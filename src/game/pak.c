#include "versions.h"
#include <ultra64.h>
#include "constants.h"
#include "game/bossfile.h"
#include "game/camdraw.h"
#include "game/filelist.h"
#include "game/menu.h"
#include "game/gamefile.h"
#include "game/pak.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/joy.h"
#include "lib/lib_06440.h"
#include "lib/main.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"
#include "string.h"

/**
 * Perfect Dark supports saving to an in-cartridge EEPROM chip, as well as to
 * controller paks which can be inserted in any of the four controllers.
 *
 * This file provides an abstraction layer between a generic "pak" and the
 * backend device it uses, and also manages the structure of data within the
 * pak.
 *
 * -- EEPROM --
 *
 * The EEPROM chip is 2KB (0x800 bytes) and is rather simple: The game reads and
 * writes to it using address and length arguments to osEeprom functions.
 *
 * -- Controller Paks --
 *
 * The controller paks are accessed via osPfs functions which are provided by
 * Nintendo. Controller paks use a filesystem and can hold data from other games
 * which is why these functions must be used.
 *
 * Controller paks have a capacity of 256Kbits (32KB). Each controller pak
 * consists of 128 "pages", where each page is a block of 256 bytes. The first
 * 5 pages are reserved for the file allocation table, leaving 123 pages
 * available for game data.
 *
 * Games use osPfsAllocateFile to create a file, also known as a game note.
 * Controller paks can hold up to 16 game notes. Perfect Dark's game note uses
 * 28 pages (7168 bytes). This single game note holds all saved information
 * (game files, MP players and MP games).
 *
 * -- Data Structure --
 *
 * Regardless of whether the data is being written to EEPROM or to a controller
 * pak, the format of it is the same. The data is a list of files, with
 * different lengths based on their file type.
 *
 * Each file has a 16-byte header, followed by its variable length body.
 * The header contains a checksum of the body data, as well as its filetype,
 * size and identifiers.
 *
 * The only way to iterate the files in the filesystem is to read the first
 * file's header (at offset 0), then read its file length out of that header and
 * add it to the offset. Repeat until a PAKFILETYPE_TERMINATOR is found which
 * marks the end of the filesystem. The filesystem may be smaller than the size
 * of the EEPROM or controller pak note.
 *
 * The effective file types are:
 *
 * BOS (length 0x70) - The "boss" file stores things global to all game files,
 *     such as the alternative title setting and chosen language if PAL.
 * GAM (length 0xb0) - Single player game files
 * MPP (length 0x60) - Multiplayer player files
 * MPG (length 0x50) - Multiplayer game setup files
 *
 * Each device can store 4 GAM, MPG and MPP files, and one BOS file. There is
 * additionally a single swap space per game type, making the total usage
 * 1984 bytes (0x7c0), which is 0x30 short of the EEPROM capacity.
 *
 * Controller paks, however, use 28 pages which is 20 pages more than necessary.
 * This is likely because they were going to hold PerfectHead photos, but when
 * the feature was removed the controller pak allocation was not adjusted.
 *
 * -- GUIDs --
 *
 * GUID is an abbreviation for globally unique identifier. GUIDs are used to
 * minimise the chance of the game overwriting a wrong file in the event that
 * a player loads a file from a controller pak, then swaps the controller pak
 * for another during gameplay. By using GUIDs, the game is very likely to
 * detect when this has happened and will prompt the player to reinsert the
 * original pak.
 *
 * When creating a game note on a controller pak, the game generates a serial
 * number for the controller pak. This serial number persists throughout the
 * life of the note. The serial number is saved into the header of every file
 * in that note.
 *
 * Additionally, when creating a file on a pak, the file is given an
 * incrementing ID number which is unique to that pak. That ID is also saved
 * into the header of that file.
 *
 * The combination of the device serial and file ID is the GUID.
 */

static u32 pak0f119298(s8 device);
static s32 pakCreateFilesystem(s8 device);
static void pakCalculateChecksum(u8 *start, u8 *end, u16 *checksum);
static void pak0f11a32c(s8 device, u8 arg1);
static bool pakQueryTotalUsage(s8 device);
static PakErr1 pakDeleteGameNote3(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name);
static u32 pakGetPdNumBytes(s8 device);
static s32 pak0f116df0(s8 device, struct pakdata **pakdata);
static u16 _pakGetSerial(s8 device);
static u32 _pakGetType(s8 device);
static s32 _pakDeleteGameNote(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name);
static PakErr1 pakReadEeprom(u8 address, u8 *buffer, u32 len);
static bool pakGetFilesystemLength(s8 device, u32 *outlen);
static void pakProbeEeprom(void);
static bool pakHandleResult(s32 err1, s8 device, bool arg2);
static s32 gbpakIdentifyGame(s8 device);
static PakErr1 pakWriteEeprom(u8 address, u8 *buffer, u32 len);
static void pak0f11df94(s8 device);
static void pak0f11ca30(void);
static s32 pakWriteFileAtOffset(s8 device, u32 offset, u32 filetype, u8 *newdata, s32 bodylenarg, s32 *outfileid, u8 *olddata, u32 fileid, u32 generation);
static s32 pak0f11b86c(s8 device, u32 offset, u8 *data, struct pakfileheader *header, s32 bodylen);
static bool pakRetrieveHeaderFromCache(s8 device, s32 blocknum, struct pakfileheader *dst);
static s32 pakCheckFileCanFitInNote(s8 device, s32 filetype, s32 *numspaces);
static s32 _pakGetFileIdsByType(s8 device, u32 filetype, u32 *fileids);
static PakErr1 pakReadWriteBlock(s8 device, OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer);
static s32 _pakSaveAtGuid(s8 device, s32 fileid, s32 filetype, u8 *newdata, s32 *outfileid, u8 *olddataptr);
static s32 _pakReadBodyAtGuid(s8 device, s32 fileid, u8 *body, s32 arg3);
static s32 _pakDeleteFile(s8 device, s32 fileid);
static void pakSaveHeaderToCache(s8 device, s32 blocknum, struct pakfileheader *header);
static bool pakRepairAsBlank(s8 device, u32 *offsetptr, struct pakfileheader *header);

#define NUM_PAGES 28

#define MAX_HEADERCACHE_ENTRIES 50

const char g_N64FontCodeMap[] = "\0************** 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#'*+,-./:=?@";

struct pak g_Paks[5];

OSPfs g_Pfses[4];

char var80075cb4[] = "PerfDark";
char var80075cc0[] = "PerfDark";

u32 g_PakHasEeprom = false;

char g_PakNoteGameName[] = {
	N64CHAR('P'),
	N64CHAR('E'),
	N64CHAR('R'),
	N64CHAR('F'),
	N64CHAR('E'),
	N64CHAR('C'),
	N64CHAR('T'),
	N64CHAR(' '),
	N64CHAR('D'),
	N64CHAR('A'),
	N64CHAR('R'),
	N64CHAR('K'),
	0, // fill to 16 bytes
	0,
	0,
	0,
};

char g_PakNoteExtName[] = {0, 0, 0, 0};

u8 var80075d10 = 0;

bool var80075d14 = true;

static u32 pakGetBlockSize(s8 device)
{
	return device == SAVEDEVICE_GAMEPAK ? 0x10 : 0x20;
}

static u32 pakAlign(s8 device, u32 size)
{
	return pakGetBlockSize(device) == 0x20 ? ALIGN32(size) : ALIGN16(size);
}

static s32 pakGetAlignedFileLenByBodyLen(s8 device, u32 bodylen)
{
	return pakAlign(device, sizeof(struct pakfileheader) + bodylen);
}

static u32 pakGetBodyLenByFileLen(u32 filelen)
{
	return filelen - sizeof(struct pakfileheader);
}

static u32 pakGenerateSerial(s8 device)
{
	s32 value;
	s32 rand;
	s32 count;

	if (device == SAVEDEVICE_GAMEPAK) {
		return 0xbaa;
	}

	value = g_Paks[device].unk2c8;
	rand = (random() % 496) + 16; // range 16-511
	count = osGetCount();

	return value ^ rand ^ count;
}

bool pakIsMemoryPak(s8 device)
{
	if (g_Paks[device].type == PAKTYPE_MEMORY) {
		switch (g_Paks[device].unk010) {
		case PAK010_14:
		case PAK010_15:
		case PAK010_19:
		case PAK010_20:
		case PAK010_22:
			return false;
		}

		return true;
	}

	return false;
}

s32 pakGetFileIdsByType(s8 device, u32 filetype, u32 *fileids)
{
	return _pakGetFileIdsByType(device, filetype, fileids);
}

s32 pak0f1167d8(s8 device)
{
	return pak0f119298(device);
}

s32 pakReadBodyAtGuid(s8 device, s32 fileid, u8 *body, s32 arg3)
{
	return _pakReadBodyAtGuid(device, fileid, body, arg3);
}

s32 pakSaveAtGuid(s8 device, s32 fileid, s32 filetype, u8 *body, s32 *outfileid, u8 *olddata)
{
	return _pakSaveAtGuid(device, fileid, filetype, body, outfileid, olddata);
}

bool pakDeleteFile(s8 device, s32 fileid)
{
	return _pakDeleteFile(device, fileid);
}

s32 pakDeleteGameNote(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name)
{
	return _pakDeleteGameNote(device, company_code, game_code, game_name, ext_name);
}

s32 pak0f1168c4(s8 device, struct pakdata **arg1)
{
	return pak0f116df0(device, arg1);
}

u32 pakGetType(s8 device)
{
	return _pakGetType(device);
}

s32 pakGetSerial(s8 device)
{
	return _pakGetSerial(device);
}

void pak0f116994(void)
{
	if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		g_Vars.unk0004e4 = 0xf8;
	}
}

void pak0f1169c8(s8 device, s32 arg1)
{
	u8 prevvalue = g_Vars.paksconnected;

	g_Vars.paksconnected = 0x1f;

	if ((g_Vars.paksconnected2 | g_Vars.paksconnected) & (1 << device)) {
		var80075d10 &= ~(1 << device);

		pak0f11ca30();
		pak0f11ca30();

		if (arg1) {
			var8005eedc = false;

			pak0f11df94(device);
			pak0f11df94(device);
			pak0f11df94(device);
			pak0f11df94(device);
			pak0f11df94(device);
			pak0f11df94(device);
			pak0f11df94(device);

			var8005eedc = true;
		}
	}

	g_Vars.paksconnected = prevvalue;
}

static bool pak0f116aec(s8 device)
{
	if (g_Paks[device].unk010 == PAK010_11 && g_Paks[device].type == PAKTYPE_MEMORY) {
		return true;
	}

	return false;
}

static bool pak0f116b5c(s8 device)
{
	if ((g_Paks[device].unk010 == PAK010_11
				|| g_Paks[device].unk010 == PAK010_16
				|| g_Paks[device].unk010 == PAK010_21)
			&& g_Paks[device].type == PAKTYPE_MEMORY) {
		return true;
	}

	return false;
}

static u16 _pakGetSerial(s8 device)
{
	return g_Paks[device].serial;
}

static u32 _pakGetType(s8 device)
{
	return g_Paks[device].type;
}

void pakSetUnk010(s8 device, s32 value)
{
	g_Paks[device].unk010 = value;
}

static s32 pak0f116df0(s8 device, struct pakdata **pakdata)
{
	*pakdata = NULL;

	if (pak0f116b5c(device)) {
		if (pakQueryTotalUsage(device)) {
			*pakdata = &g_Paks[device].pakdata;
			return 0;
		}

		return 2;
	}

	return 1;
}

static s32 _pakDeleteGameNote(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name)
{
	s32 result;

	if (pak0f116b5c(device)) {
		joyDisableCyclicPolling();
		result = pakDeleteGameNote3(PFS(device), company_code, game_code, game_name, ext_name);
		joyEnableCyclicPolling();

		if (pakHandleResult(result, device, true)) {
			g_Paks[device].unk2b8_02 = 1;
			return 0;
		}

		return 2;
	}

	return 1;
}

static s32 _pakDeleteFile(s8 device, s32 fileid)
{
	struct pakfileheader header;
	s32 result = pakFindFile(device, fileid, &header);

	if (result == -1) {
		return 1;
	}

	result = pakWriteFileAtOffset(device, result, header.filetype, NULL, 0, NULL, NULL, 0, header.generation + 1);

	if (result) {
		return result;
	}

	return 0;
}

s32 pakGetUnk264(s8 device)
{
	return g_Paks[device].unk264;
}

static u32 pakGetMaxFileSize(s8 device)
{
	if (device != SAVEDEVICE_GAMEPAK) {
		return 0x4c0;
	}

	return 0x100;
}

static s32 pakGetBodyLenByType(s8 device, u32 filetype)
{
	s32 len = 0;

	switch (filetype) {
	case PAKFILETYPE_001:
	case PAKFILETYPE_BLANK:
		break;
	case PAKFILETYPE_TERMINATOR:
		len = pakGetMaxFileSize(device) - sizeof(struct pakfileheader);
		break;
	case PAKFILETYPE_BOSS:
		len = 0x5b;
		break;
	case PAKFILETYPE_MPPLAYER:
		len = 0x4e;
		break;
	case PAKFILETYPE_MPSETUP:
		len = 0x31;
		break;
	case PAKFILETYPE_CAMERA:
		len = 0x4a0;
		break;
	case PAKFILETYPE_GAME:
		len = 0xa0;
		break;
	}

	return len;
}

static bool pakRetrieveBlockFromCache(s8 device, u32 offset, u8 *dst)
{
	u32 blocksize = pakGetBlockSize(device);
	u32 stack;
	s32 i;

	if (g_Paks[device].headercachecount < MAX_HEADERCACHE_ENTRIES) {
		for (i = 0; i < g_Paks[device].headercachecount; i++) {
			if (offset / blocksize == g_Paks[device].headercache[i].blocknum) {
				memcpy(dst, g_Paks[device].headercache[i].payload, pakGetBlockSize(device));
				return true;
			}
		}
	}

	return false;
}

static PakErr2 pakReadHeaderAtOffset(s8 device, u32 offset, struct pakfileheader *header)
{
	struct pakfileheader localheader;
	struct pakfileheader *headerptr;
	u32 blocknum;
	s32 result;
	u16 checksum[2];
	u8 sp38[0x20];

	headerptr = header ? header : &localheader;

	blocknum = offset / pakGetBlockSize(device);

	if (blocknum >= g_Paks[device].pdnumblocks) {
		return PAK_ERR2_BADOFFSET;
	}

	if (!pakRetrieveHeaderFromCache(device, blocknum, headerptr)) {
		result = pakReadWriteBlock(device, PFS(device), g_Paks[device].pdnoteindex, 0, offset, sizeof(sp38), sp38);

		if (pakHandleResult(result, device, true) == 0) {
			if (result == PAK_ERR1_NOPAK) {
				return PAK_ERR2_NOPAK;
			}

			return PAK_ERR2_BADOFFSET;
		}

		memcpy(headerptr, sp38, sizeof(struct pakfileheader));
		pakCalculateChecksum(&sp38[0x08], &sp38[0x10], checksum);

		if (headerptr->headersum[0] != checksum[0] || headerptr->headersum[1] != checksum[1]) {
			return PAK_ERR2_CHECKSUM;
		}

		if (!headerptr->writecompleted) {
			return PAK_ERR2_INCOMPLETE;
		}

		if (headerptr->version != 0) {
			return PAK_ERR2_VERSION;
		}

		pakSaveHeaderToCache(device, blocknum, (struct pakfileheader *) sp38);

		if (!pakRetrieveHeaderFromCache(device, blocknum, headerptr)) {
			return PAK_ERR2_CORRUPT;
		}
	}

	if (headerptr->filelen == 0) {
		return PAK_ERR2_CORRUPT;
	}

	return PAK_ERR2_OK;
}

/**
 * Overwrite the save file which has the specified fileid. This is typically an
 * earlier version of the same logical save file. A new fileid will be generated
 * and returned to *outfileid.
 *
 * The function doesn't literally overwrite the old file. On the pak, there is
 * a swap file reserved for atomic writes. The new file is written into the
 * swap file, then the old file is marked as swap.
 */
static s32 _pakSaveAtGuid(s8 device, s32 fileid, s32 filetype, u8 *newdata, s32 *outfileid, u8 *olddataptr)
{
	struct pakfileheader header;
	struct pakfileheader swapheader;
	s32 result;
	s32 oldoffset;
	s32 i;
	s32 swapoffset;
	u32 fileids[1024];
	s32 swapfileid = 0;
	u8 olddata[0x800];

	// Find the file to be "replaced"
	oldoffset = pakFindFile(device, fileid, &header);

	if (oldoffset && (!oldoffset || oldoffset >= pakGetPdNumBytes(device) || ((pakGetBlockSize(device) - 1) & oldoffset))) {
		return 3;
	}

	if (filetype != header.filetype) {
		return 12;
	}

	// Find all files on the pak of the same filetype,
	// then iterate them to find the swap file
	pakGetFileIdsByType(device, header.filetype, fileids);

	// NTSC Beta initialises swapoffset to -1 so it can detect if the loop below
	// has been entered. But in NTSC 1.0 they realised that pakFindFile can
	// return -1, so they initialised the variable to 0xeeeeeeee instead and
	// added the check for -1 in the loop below.
	swapoffset = 0xeeeeeeee;

	for (i = 0; fileids[i] != 0; i++) {
		swapoffset = pakFindFile(device, fileids[i], &swapheader);

		if (swapoffset == -1) {
			return 1;
		}

		if (!swapheader.occupied && swapheader.fileid != fileid) {
			// Found the swap file
			swapfileid = swapheader.fileid;
			break;
		}
	}

	// For the game pak, don't trust the olddataptr argument and instead
	// populate it by loading the data at the swap file (olddataptr is used to
	// skip writes if any old and new blocks are matching).
	// @bug? Shouldn't this also apply to controller paks? How would the caller
	// know which swap space was going to be used? Maybe controller paks don't
	// use the olddataptr optimisation?
	if (device == SAVEDEVICE_GAMEPAK) {
		result = pakReadBodyAtGuid(device, swapfileid, olddata, -1);

		// NTSC 1.0 just writes the same thing a different way
		if (result == 0) {
			olddataptr = olddata;
		} else if (result == 10) {
			olddataptr = olddata;
		} else {
			olddataptr = NULL;
		}
	}

	// Write the new file into the swap space
	result = pakWriteFileAtOffset(device, swapoffset, filetype, newdata, 0, outfileid, olddataptr, fileid, header.generation + 1);

	if (result != 0) {
		return 4;
	}

	if (outfileid) {
	}

	// NTSC Beta skips marking the old file as vacant if the file wasn't found
	// and returns an OK value. NTSC Final makes it return an error instead.
	// @bug: The 0xeeeeeeee check should have been done earlier for swapoffset
	// instead. As it turns out, if swap space wasn't found then
	// pakWriteFileAtOffset would have returned an error above and this function
	// would have returned before this check occurs. And oldoffset will never be
	// 0xeeeeeeee (even with 4GB of storage) because 0xeeeeeeee is not aligned
	// to a 16-byte boundary. So this bug is harmless.
	if (oldoffset == -1) {
		return 1;
	}

	if (oldoffset != 0xeeeeeeee) {
		pakWriteFileAtOffset(device, oldoffset, filetype, NULL, 0, NULL, NULL, swapfileid, header.generation);
	}

	return 0;
}

static PakErr1 pakInitPak(OSMesgQueue *mq, OSPfs *pfs, s32 channel, s32 *arg3)
{
	if (pfs) {
		return osPfsInitPak(mq, pfs, channel, arg3);
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	return PAK_ERR1_OK;
}

static PakErr1 _pakReadWriteBlock(OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer)
{
	u32 newaddress;

	joyCheckPfs(2);

	if (pfs) {
		return osPfsReadWriteFile(pfs, file_no, flag, address, len, buffer);
	}

	newaddress = address / 8;

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	if (flag == OS_WRITE) {
		return pakWriteEeprom(newaddress, buffer, len);
	}

	if (flag == OS_READ) {
		return pakReadEeprom(newaddress, buffer, len);
	}

	return PAK_ERR1_EEPROMINVALIDOP;
}

static PakErr1 pakQueryNumNotes(OSPfs *pfs, s32 *max_files, s32 *files_used)
{
	if (pfs) {
		s32 result;

		joyDisableCyclicPolling();
		result = osPfsNumFiles(pfs, max_files, files_used);
		joyEnableCyclicPolling();

		return result;
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	*max_files = 1;
	*files_used = 1;

	return PAK_ERR1_OK;
}

static PakErr1 pakQueryNumFreeBytes(OSPfs *pfs, s32 *bytes_not_used)
{
	if (pfs) {
		s32 result;

		joyDisableCyclicPolling();
		result = osPfsFreeBlocks(pfs, bytes_not_used);
		joyEnableCyclicPolling();

		return result;
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	*bytes_not_used = 0;

	return PAK_ERR1_OK;
}

static PakErr1 pakQueryNoteState(OSPfs *pfs, s32 file_no, OSPfsState *note)
{
	if (pfs) {
		s32 result;

		joyDisableCyclicPolling();
		result = osPfsFileState(pfs, file_no, note);
		joyEnableCyclicPolling();

		return result;
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	if (file_no) {
		return PAK_ERR1_EEPROMINVALIDARG;
	}

	note->file_size = 0x800;
	note->company_code = ROM_COMPANYCODE;
	strcpy(note->game_name, g_PakNoteGameName);
	strcpy(note->ext_name, g_PakNoteExtName);

	return PAK_ERR1_OK;
}


static PakErr1 pakAllocateNote(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 size, s32 *file_no)
{
	if (pfs) {
		return osPfsAllocateFile(pfs, company_code, game_code, game_name, ext_name, size, file_no);
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	*file_no = 0;

	return PAK_ERR1_OK;
}

static PakErr1 pakDeleteGameNote3(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name)
{
	if (pfs) {
		return osPfsDeleteFile(pfs, company_code, game_code, game_name, ext_name);
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	return PAK_ERR1_OK;
}

static PakErr1 pakFindNote(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 *file_no)
{
	if (pfs) {
		return osPfsFindFile(pfs, company_code, game_code, game_name, ext_name, file_no);
	}

	if (g_PakHasEeprom) {
		*file_no = 0;
		return PAK_ERR1_OK;
	}

	return PAK_ERR1_EEPROMMISSING;
}

static u32 pakGetPdNumBytes(s8 device)
{
	return g_Paks[device].pdnumbytes;
}

/**
 * Determine how many camera files the pak could accommodate,
 * considering the possibility of resizing the game note to make it larger.
 */
s32 pakGetNumFreeCameraSpacesInPak(s8 device)
{
	if (device != SAVEDEVICE_GAMEPAK) {
		s32 numspaces = 0;
		s32 pagesneeded;
		u32 bytesneeded;

		bytesneeded = pakGetMaxFileSize(device);
		pakCheckFileCanFitInNote(device, PAKFILETYPE_CAMERA, &numspaces);
		pagesneeded = bytesneeded / 256;

		if (bytesneeded & 0xff) {
			pagesneeded++;
		}

		// 128 is the total number of pages on a controller pak
		numspaces += (128 - g_Paks[device].pakdata.pagesused) / pagesneeded;

		return numspaces;
	}

	return 0;
}

/**
 * Find a spot for the given filetype and write it.
 *
 * Replace a blank spot or extend the filesystem if needed and possible.
 */
static u32 pak0f118674(s8 device, u32 filetype, s32 *outfileid)
{
	struct pakfileheader header;
	s32 ret;
	s32 zero = 0;
	s32 filelen = pakGetAlignedFileLenByBodyLen(device, pakGetBodyLenByType(device, filetype));
	s32 bestoffset = -1;
	u32 offset = 0;
	bool foundperfectblank = false;
	bool foundblank = false;

	if (pak0f1167d8(device)) {
		return pak0f1167d8(device);
	}

	while (offset < g_Paks[device].pdnumbytes) {
		ret = pakReadHeaderAtOffset(device, offset, &header);

		if (ret == PAK_ERR2_OK) {
			if (header.filetype & PAKFILETYPE_TERMINATOR) {
				if (offset + filelen > g_Paks[device].pdnumbytes - 0x20) {
					return 14;
				}

				bestoffset = offset;
				break;
			}

			if (header.filetype & PAKFILETYPE_BLANK) {
				if (header.filelen == filelen) {
					foundperfectblank = true;
					bestoffset = offset;
					break;
				}

				foundblank = true;
				bestoffset = offset;
				break;
			}

			offset += header.filelen;
		} else if (ret == PAK_ERR2_NOPAK) {
			return 1;
		} else {
			offset += pakGetBlockSize(device);
		}
	}

	// This is optimised out, but it invalidates the the register that stores &g_Paks[device],
	// which makes it get recalculated. This is required for a match.
	if (zero) {
		device ^= 0;
		device ^= 0;
	}

	if (offset == 0 ||
			(offset && offset < pakGetPdNumBytes(device) && ((pakGetBlockSize(device) - 1) & offset) == 0)) {
		if (bestoffset == -1) {
			return 14;
		}

		// Write the file
		if (pakWriteFileAtOffset(device, bestoffset, filetype, NULL, 0, outfileid, NULL, 0, 1) == 0) {
			if (foundblank) {
				u32 endoffset = bestoffset + filelen;
				pakRepairAsBlank(device, &endoffset, NULL);
				return 0;
			}

			if (foundperfectblank || foundblank) {
				return 0;
			}

			// Write new terminator after file
			bestoffset += pakGetAlignedFileLenByBodyLen(device, pakGetBodyLenByType(device, filetype));

			if (pakWriteFileAtOffset(device, bestoffset, PAKFILETYPE_TERMINATOR, NULL, 0, NULL, NULL, 0, 1) == 0) {
				return 0;
			}

			return 4;
		}

		return 4;
	}

	g_Paks[device].unk010 = PAK010_16;
	g_Paks[device].type = PAKTYPE_MEMORY;

	return 4;
}

void paksInit(void)
{
	u8 prevvalue = g_Vars.paksconnected;
	s8 i;

	g_Vars.unk0004e4 = 0;

	for (i = 0; i < 5; i++) {
		g_Paks[i].unk274 = 3;
		g_Paks[i].unk014 = 0;
		g_Paks[i].type = PAKTYPE_NONE;
		g_Paks[i].unk008 = 1;
		g_Paks[i].rumblestate = RUMBLESTATE_1;
		g_Paks[i].unk00c = 3;
		g_Paks[i].unk010 = PAK010_00;
		g_Paks[i].pdnoteindex = -1;
		g_Paks[i].unk2b8_01 = 0;
		g_Paks[i].unk2b8_05 = 0;
		g_Paks[i].isgbcamera = 0;
		g_Paks[i].unk2b8_02 = 0;
		g_Paks[i].unk2bd = 128;
		g_Paks[i].unk264 = 0;
		g_Paks[i].unk2b8_06 = 0;
		g_Paks[i].unk2b8_07 = 0;
		g_Paks[i].headercache = NULL;
		g_Paks[i].unk2c4 = NULL;
		g_Paks[i].maxfileid = 8;
		g_Paks[i].serial = 0;
		g_Paks[i].rumblettl = -1;
		g_Paks[i].unk2c8 = 0;
	}

	for (i = 0; i < 5; i++) {
		pak0f11a32c(i, 7);
	}

	pakProbeEeprom();
	joyRecordPfsState(0x10);

	g_Vars.paksconnected = 0x10;

	pak0f1169c8(SAVEDEVICE_GAMEPAK, 1);
	bossfileLoadFull();

	gamefileLoadDefaults(&g_GameFile);
	gamefileApplyOptions(&g_GameFile);

	g_GameFileGuid.deviceserial = 0;
	g_Vars.unk0004e4 = 0xf5;
	g_Vars.paksconnected = prevvalue;
}

static void pakCalculateChecksum(u8 *start, u8 *end, u16 *checksum)
{
	u8 *ptr;
	u32 salt = 0;
	u64 seed = 0x8f809f473108b3c1;
	u32 sum1 = 0;
	u32 sum2 = 0;

	for (ptr = start; ptr < end; ptr++, salt += 7) {
		seed += *ptr << (salt & 0x0f);
		sum1 ^= rngRotateSeed(&seed);
	}

	for (ptr = end - 1; ptr >= start; ptr--, salt += 3) {
		seed += *ptr << (salt & 0x0f);
		sum2 ^= rngRotateSeed(&seed);
	}

	checksum[0] = sum1 & 0xffff;
	checksum[1] = sum2 & 0xffff;
}

static s32 _pakReadBodyAtGuid(s8 device, s32 fileid, u8 *body, s32 arg3)
{
	s32 offset;
	struct pakfileheader header;
	s32 result;
	u16 checksum[2];

	if (!pak0f1167d8(device)) {
		offset = pakFindFile(device, fileid, NULL);

		if (offset == -1) {
			return 1;
		}

		if (offset == 0 || (offset && offset < pakGetPdNumBytes(device) && ((pakGetBlockSize(device) - 1) & offset) == 0)) {
			result = pak0f11b86c(device, offset, body, &header, arg3);

			if (result) {
				return result;
			}

			if (arg3 == -1) {
				arg3 = 0;
			}

			if (header.occupied) {
				if (!arg3) {
					pakCalculateChecksum(body, body + header.bodylen, checksum);

					if (header.bodysum[0] != checksum[0] || header.bodysum[1] != checksum[1]) {
						return 8;
					}
				}
			} else {
				return 10;
			}
		} else {
			return 3;
		}
	} else {
		return 6;
	}

	return 0;
}

static s32 _pakGetFileIdsByType(s8 device, u32 filetype, u32 *fileids)
{
	struct pakfileheader header;
	u32 offset = 0;
	u32 fslen;
	s32 len = 0;
	s32 result = pak0f119298(device);

	if (result != 0) {
		return result;
	}

	result = pakGetFilesystemLength(device, &fslen);

	if (result != 0) {
		return result;
	}

	result = pak0f1167d8(device);

	if (result != 0) {
		return pak0f1167d8(device);
	}

	result = pakReadHeaderAtOffset(device, offset, &header);

	while (result == PAK_ERR2_OK) {
		if ((filetype & PAKFILETYPE_ALL) || (filetype & header.filetype)) {
			fileids[len] = header.fileid;
			len++;
		}

		offset += header.filelen;

		if (offset >= fslen) {
			break;
		}

		result = pakReadHeaderAtOffset(device, offset, &header);
	}

	fileids[len] = 0;

	if (result == PAK_ERR2_CHECKSUM) {
		return 7;
	}

	if (result == PAK_ERR2_NOPAK) {
		return 1;
	}

	return 0;
}

/**
 * Calculate the number of times the given filetype can fit in the note.
 *
 * Return 0 if it can fit, otherwise 5.
 */
static s32 pakCheckFileCanFitInNote(s8 device, s32 filetype, s32 *numspaces)
{
	struct pakfileheader header;
	u32 filelen;
	bool hasspace;
	u32 fslen;
	u32 offset;
	u32 roomtogrow;

	filelen = pakGetAlignedFileLenByBodyLen(device, pakGetBodyLenByType(device, filetype));

	hasspace = false;

	pakGetFilesystemLength(device, &fslen);

	if (numspaces != NULL) {
		*numspaces = 0;
	}

	for (offset = 0; pakReadHeaderAtOffset(device, offset, &header) == PAK_ERR2_OK && offset < fslen; offset += header.filelen) {
		if (PAKFILETYPE_BLANK == header.filetype && header.filelen >= filelen) {
			hasspace = true;

			if (numspaces != NULL) {
				*numspaces = *numspaces + 1;
			}
		}
	}

	roomtogrow = g_Paks[device].pdnumbytes - fslen;

	if (numspaces != NULL) {
		*numspaces += roomtogrow / filelen;
	}

	if (!hasspace && roomtogrow >= pakGetMaxFileSize(device)) {
		hasspace = true;
	}

	return (hasspace ? 0 : 5);
}

static u32 pak0f119298(s8 device)
{
	if (g_Paks[device].type != PAKTYPE_MEMORY) {
		return 1;
	}

	switch (g_Paks[device].unk010) {
	case PAK010_11:
		return 0;
	case PAK010_17:
		return 14;
	case PAK010_18:
		return 4;
	case PAK010_03:
	case PAK010_04:
	case PAK010_05:
	case PAK010_06:
	case PAK010_07:
		return 13;
	}

	return 1;
}

static void pak0f119340(u32 arg0)
{
	switch (arg0) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		break;
	}
}

s32 pakFindFile(s8 device, u32 fileid, struct pakfileheader *headerptr)
{
	// NTSC 1.0 adds error checking
	struct pakfileheader header;
	s32 offset = 0;
	u32 fslen;
	s32 ret;

	pakGetFilesystemLength(device, &fslen);

	ret = pakReadHeaderAtOffset(device, offset, &header);

	while (ret == PAK_ERR2_OK && offset < fslen) {
		if (fileid == header.fileid) {
			if (headerptr) {
				memcpy(headerptr, &header, sizeof(struct pakfileheader));
			}

			return offset;
		}

		offset += header.filelen;

		ret = pakReadHeaderAtOffset(device, offset, &header);
	}

	if (ret == PAK_ERR2_NOPAK) {
		return -1;
	}

	return 0xffff;
}

static bool pakWriteBlankFile(s8 device, u32 offset, struct pakfileheader *header)
{
	if (pakWriteFileAtOffset(device, offset, PAKFILETYPE_BLANK, NULL, pakGetBodyLenByFileLen(header->filelen), NULL, NULL, 0, 1) == 0) {
		return true;
	}

	return false;
}

/**
 * Repair the pak by writing a blank file from the given offset up until the
 * start of the next file.
 *
 * If done successfully, update the value at the offset pointer with the end
 * offset of the blank file and return true.
 *
 * For controller paks, enforce a max file size. If the blank file would exceed
 * the max file size, store the current search offset in the pointer and return
 * false.
 *
 * If the end of the note/device is reached without finding the subequent file,
 * write a terminator file at the start address and return true. A blank file
 * is not written in this case.
 *
 * If an error code is returned by called functions, the value at the offset
 * pointer is not changed and the function returns false.
 *
 * If the header argument is not NULL, it's assumed it's the header
 * corresponding to the starting offset and the function takes a shortcut by
 * starting the scan at the end of the header.
 */
static bool pakRepairAsBlank(s8 device, u32 *offsetptr, struct pakfileheader *header)
{
	struct pakfileheader iterheader;

	u32 maxfilesize = pakGetMaxFileSize(device);
	u32 start = *offsetptr;
	u32 start2 = *offsetptr;
	u32 offset = *offsetptr;
	s32 result;
	u32 bodylen;

	// Skip past the header if given
	if (header != NULL) {
		offset += header->filelen;
	}

	while (offset < g_Paks[device].pdnumbytes) {
		result = pakReadHeaderAtOffset(device, offset, &iterheader);

		if (result == PAK_ERR2_OK) {
			// Found a valid header
			if ((iterheader.filetype & PAKFILETYPE_BLANK) == 0 && offset > start2) {
				break;
			}
		} else if (result == PAK_ERR2_NOPAK) {
			return false;
		}

		// No header at this offset
		offset += pakGetBlockSize(device);

		// For controller paks, consider giving up
		if (device != SAVEDEVICE_GAMEPAK && offset - start > maxfilesize) {
			*offsetptr = offset;
			return false;
		}

		// If the end was reached, write a terminator at the starting offset
		if (offset >= g_Paks[device].pdnumbytes) {
			pakWriteFileAtOffset(device, start, PAKFILETYPE_TERMINATOR, NULL, 0, NULL, NULL, 0, 1);
			return true;
		}
	}

	bodylen = pakGetBodyLenByFileLen(offset - start);


	// Write the blank file ranging from to the start to the current offset
	result = pakWriteFileAtOffset(device, start, PAKFILETYPE_BLANK, NULL, bodylen, NULL, NULL, 0, 1);

	if (result != 0) {
		*offsetptr = offset;
		return false;
	}

	*offsetptr = offset;
	return true;
}

struct serialcount {
	u32 serial;
	s32 count;
};

/**
 * Attempt to repair the filesystem on the pak.
 *
 * ntsc-final:
 * - Ensures the same device serial is used across all files
 *
 * ntsc-1.0:
 * - Fixes the terminator if missing
 * - Changes return code to -1, 0 or 1, where:
 *     -1 means a fatal error occurred and the filesystem is hosed
 *     0 means the filesystem was fine or is now repaired
 *     1 means the pak is not inserted or the repair failed
 *
 * ntsc-beta:
 * - Removes duplicate files
 * - Removes files if header checksum mismatches
 * - Removes files if partially written
 * - Returns 1 if filesystem is good, or 0 if unrepairable
 */
static s32 pakRepairFilesystem(s8 device)
{
	s32 ret;
	bool fatal = false;
	bool foundotherversion = false;
	struct pakfileheader headers[50];
	struct pakfileheader header;
	s32 numheaders = 0;
	u32 headeroffsets[50];
	u32 offset;
	s32 i;
	bool foundduplicate;
	struct serialcount serials[100];
	u32 stack[1];

	g_Paks[device].serial = 0xbaba;
	g_Paks[device].headercachecount = 0;

	if (pak0f1167d8(device) != 0) {
		return 1;
	}

	// Iterate the headers on the pak and copy each one onto the stack.
	// As each header is read, check if a duplicate exists on the stack.
	// If a duplicate is found, blank the oldest one.
	// Stop when the end is reached, or a blank file or terminator is found.
	// If any headers are unreadable, replace them with a blank file.
	offset = 0;

	while (!fatal && offset < g_Paks[device].pdnumbytes) {
		ret = pakReadHeaderAtOffset(device, offset, &header);

		if (ret == PAK_ERR2_OK) {
			if (header.filetype & PAKFILETYPE_BLANK) {
				break;
			}

			if (header.filetype & PAKFILETYPE_TERMINATOR) {
				break;
			}

			if (offset + header.filelen >= g_Paks[device].pdnumbytes) {
				// File overflows the device length -> replace with terminator
				ret = pakWriteFileAtOffset(device, offset, PAKFILETYPE_TERMINATOR, NULL, 0, NULL, NULL, 0, 1);

				if (ret != 0) {
					fatal = true;
				} else {
					break;
				}
			} else {
				// Check for duplicates
				s32 i;
				foundduplicate = false;

				for (i = 0; i != numheaders; i++) {
					if (headeroffsets[i] != -1 && header.fileid == headers[i].fileid) {
						foundduplicate = true;

						if (header.generation < headers[i].generation) {
							// The header that was just read is older -> delete it
							fatal = pakRepairAsBlank(device, &offset, &header) == 0;
						} else {
							// The header that was just read is newer -> delete the older one
							fatal = pakRepairAsBlank(device, &headeroffsets[i], &headers[i]) == 0;
							headeroffsets[i] = -1;

							// Add this header to the list
							memcpy(&headers[numheaders], &header, sizeof(header));
							headeroffsets[numheaders] = offset;
							numheaders++;

							offset += header.filelen;
						}

						break;
					}
				}

				if (!foundduplicate && !fatal) {
					memcpy(&headers[numheaders], &header, sizeof(header));
					headeroffsets[numheaders] = offset;
					numheaders++;

					offset += header.filelen;
				}
			}
		} else {
			if (ret == PAK_ERR2_NOPAK) {
				return 1;
			} else if (ret == PAK_ERR2_CHECKSUM) {
				fatal = pakRepairAsBlank(device, &offset, NULL) == false;
			} else if (ret == PAK_ERR2_INCOMPLETE) {
				if (!pakRepairAsBlank(device, &offset, &header)) {
					fatal = true;
					break;
				}
			} else if (ret == PAK_ERR2_VERSION) {
				foundotherversion = true;
				break;
			} else if (ret == PAK_ERR2_BADOFFSET) {
				fatal = true;
				break;
			} else if (ret == PAK_ERR2_CORRUPT) {
				fatal = true;
				break;
			} else {
				fatal = true;
				break;
			}
		}
	}

	// Recheck all the headers.
	// Return 0 if the first file was a terminator (ie. pak is empty).
	// Return 1 if any header still has problems.
	offset = 0;

	while (!foundotherversion && !fatal && offset < g_Paks[device].pdnumbytes) {
		ret = pakReadHeaderAtOffset(device, offset, &header);

		if (ret == 0) { // success
			if (header.filetype & PAKFILETYPE_BLANK) {
				// empty
			} else if (offset) {
			} else {
				g_Paks[device].serial = header.deviceserial;

				if (header.filetype & PAKFILETYPE_TERMINATOR) {
					return 0;
				}
			}

			if ((header.filetype & PAKFILETYPE_TERMINATOR) == 0) {
				offset += header.filelen;
			} else {
				break;
			}
		} else if (ret == PAK_ERR2_VERSION) {
			foundotherversion = true;
			offset += header.filelen;
		} else if (ret == PAK_ERR2_NOPAK) {
			return 1;
		} else {
			return 1;
		}
	}

	// NTSC Final ensures serials are all the same
	if (!foundotherversion && !fatal) {
		// Build list of serials and how many times each was found.
		// There should only be one serial across all files.
		s32 numserials = 0;
		offset = 0;

		while (offset < g_Paks[device].pdnumbytes) {
			ret = pakReadHeaderAtOffset(device, offset, &header);

			if (ret == PAK_ERR2_NOPAK);

			if (ret != PAK_ERR2_OK) {
				break;
			}

			if ((header.filetype & PAKFILETYPE_BLANK) == 0) {
				bool found = false;

				if (header.filetype & PAKFILETYPE_TERMINATOR) {
					break;
				}

				for (i = 0; i < numserials; i++) {
					if (serials[i].serial == header.deviceserial) {
						found = true;
						serials[i].count++;
					}
				}

				if (!found) {
					serials[numserials].serial = header.deviceserial;
					serials[numserials].count = 1;
					numserials++;
				}
			}

			offset += header.filelen;

			if (offset);
		}

		if (numserials >= 2) {
			// Decide which serial to use based on majority
			s32 bestindex = -1;
			s32 bestcount = -1;

			for (i = 0; i < numserials; i++) {
				if (serials[i].count > bestcount) {
					bestindex = i;
					bestcount = serials[i].count;
				}
			}

			if (bestindex != -1) {
				// Apply the chosen serial
				g_Paks[device].serial = serials[bestindex].serial;

				offset = 0;

				while (offset < g_Paks[device].pdnumbytes) {
					ret = pakReadHeaderAtOffset(device, offset, &header);

					if (ret != PAK_ERR2_OK) {
						break;
					}

					if ((header.filetype & PAKFILETYPE_BLANK) == 0) {
						if (header.filetype & PAKFILETYPE_TERMINATOR) {
							break;
						}

						if (header.deviceserial != g_Paks[device].serial) {
							pakWriteBlankFile(device, offset, &header);
						}
					}

					offset += header.filelen;

					if (offset);
				}
			}
		} else {
			g_Paks[device].serial = serials[0].serial;
		}
	}

	if (fatal) {
		return -1;
	}

	if (foundotherversion) {
		return -1;
	}

	if (device != SAVEDEVICE_GAMEPAK && g_Paks[device].serial == 0) {
		g_Paks[device].serial = pakGenerateSerial(device);
		return -1;
	}

	return 0;
}

/**
 * Create the initial files on a pak. Return true if all good.
 *
 * NTSC Beta forgets to include return values.
 */
static bool pakCreateInitialFiles(s8 device)
{
	struct pakfileheader header;
	s32 i;
	u32 fileids[1024];
	s32 j;
	u32 stack[2];

	static u32 filetypes[] = {
		PAKFILETYPE_BOSS,
		PAKFILETYPE_CAMERA,
		PAKFILETYPE_MPPLAYER,
		PAKFILETYPE_MPSETUP,
		PAKFILETYPE_GAME,
	};

	u32 filecounts[] = { 2, 3, 5, 5, 5 };

	// Iterate all files on the pak and decrease the counts per filetype
	if (pakGetFileIdsByType(device, PAKFILETYPE_ALL, fileids) != 0) {
		return false;
	}

	for (i = 0; fileids[i] != 0; i++) {
		if (pakFindFile(device, fileids[i], &header) == -1) {
			return false;
		}

		for (j = 0; j < ARRAYCOUNT(filetypes); j++) {
			if (header.filetype == filetypes[j]) {
				if (filecounts[j]) {
					filecounts[j]--;
				}
				break;
			}
		}
	}

	// Create files
	for (i = 0; i < ARRAYCOUNT(filetypes); i++) {
		// Skip creating camera files on the game pak (they are controller pak only)
		if (filecounts[i] != 0 && !(device == SAVEDEVICE_GAMEPAK && i == 1)) {
			for (j = 0; j < filecounts[i]; j++) {
				s32 ret = pak0f118674(device, filetypes[i], NULL);

				if (ret != 0) {
					if (ret == 14) {
						return true;
					}

					pak0f119340(ret);
					return false;
				}
			}
		}
	}

	return true;
}

static s32 pakFindMaxFileId(s8 device)
{
	struct pakfileheader header;
	u32 fileids[1025];
	s32 result;
	s32 max = 0;
	s32 i;

	result = pakGetFileIdsByType(device, PAKFILETYPE_ALL, fileids);

	if (result == 0) {
		for (i = 0; fileids[i] != 0; i++) {
			s32 offset = pakFindFile(device, fileids[i], &header);

			if (offset == -1) {
				return -1;
			}

			if (header.fileid > max) {
				max = header.fileid;
			}
		}
	} else {
		return -1;
	}

	return max;
}

static void pak0f11a32c(s8 device, u8 arg1)
{
	if (g_Paks[device].unk014 == 0) {
		g_Paks[device].unk014 = arg1;

		if ((g_Paks[device].unk014 & 1) && g_Paks[device].headercache == NULL) {
			g_Paks[device].headercachecount = 0;
			g_Paks[device].headercache = mempAlloc(ALIGN32(sizeof(struct pakheadercache) * MAX_HEADERCACHE_ENTRIES), MEMPOOL_PERMANENT);
		}
	}
}

static PakErr1 pakReadWriteBlock(s8 device, OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer)
{
	s32 result;
	len = pakAlign(device, len);

	joyDisableCyclicPolling();
	result = _pakReadWriteBlock(pfs, file_no, flag, address, len, buffer);
	joyEnableCyclicPolling();

	return result;
}

static bool pakQueryTotalUsage(s8 device)
{
	struct pak *pak = &g_Paks[device];
	s32 noteerrors[16];
	s32 bytesfree;
	s32 ret;
	s32 i;

	if (!pak->unk2b8_02) {
		return true;
	}

	ret = pakQueryNumNotes(PFS(device), &pak->notestotal, &pak->notesused);

	if (!pakHandleResult(ret, device, true)) {
		pak->unk2b8_02 = false;
		return false;
	}

	ret = pakQueryNumFreeBytes(PFS(device), &bytesfree);
	pak->pakdata.pagesfree = ((bytesfree + 255) & 0xffff) >> 8;

	if (!pakHandleResult(ret, device, true)) {
		pak->unk2b8_02 = false;
		return false;
	}

	for (i = 0; i < 16; i++) {
		noteerrors[i] = pakQueryNoteState(PFS(device), i, &pak->pakdata.notes[i]);

		if (noteerrors[i] != PAK_ERR1_OK) {
			pak->pakdata.notesinuse[i] = false;
		} else {
			pak->pakdata.notesinuse[i] = true;
		}
	}

	for (i = 0, pak->pakdata.pagesused = 0; i < 16; i++) {
		if (noteerrors[i] == PAK_ERR1_OK) {
			pak->pakdata.pagesused += (pak->pakdata.notes[i].file_size + 255) >> 8;
		}
	}

	pak->unk2b8_02 = false;

	return true;
}

static void pakQueryPdSize(s8 device)
{
	u32 stack;
	OSPfsState note;
	s32 result;

	joyDisableCyclicPolling();
	result = pakQueryNoteState(PFS(device), g_Paks[device].pdnoteindex, &note);
	joyEnableCyclicPolling();

	if (pakHandleResult(result, device, true)) {
		g_Paks[device].pdnumbytes = note.file_size;
		g_Paks[device].pdnumblocks = g_Paks[device].pdnumbytes / pakGetBlockSize(device);
		g_Paks[device].pdnumpages = g_Paks[device].pdnumbytes / 256;
		g_Paks[device].pdnumnotes = g_Paks[device].pdnumbytes / (256 * NUM_PAGES);
	}
}

/**
 * Prepare a controller pak for use by making sure a note is allocated and that
 * the filesystem is good, among other things.
 */
static bool mempakPrepare(s8 device)
{
	u32 stack[2];
	bool isnewnote = false;
	bool error = false;
	u32 fileids[1024];
	s32 serial;
	s32 sp48;
	s32 notesize;
	s32 maxfileid;

	g_Paks[device].type = PAKTYPE_MEMORY;
	g_Paks[device].unk2b8_02 = true;

	pakQueryTotalUsage(device);

	if (g_Paks[device].unk010 == PAK010_01) {
		return false;
	}

	// Find the PD note if it exists
	joyDisableCyclicPolling();
	sp48 = pakFindNote(PFS(device), ROM_COMPANYCODE, ROM_GAMECODE, g_PakNoteGameName, g_PakNoteExtName, &g_Paks[device].pdnoteindex);
	joyEnableCyclicPolling();

	// If it doesn't exist, allocate it
	if (sp48 != PAK_ERR1_OK) {
		struct pak *pak = &g_Paks[device];

		pakHandleResult(sp48, device, false);

		g_Paks[device].pdnumnotes = (pak->pakdata.pagesfree > 128) ? 2 : 1;

		notesize = g_Paks[device].pdnumnotes * (256 * NUM_PAGES);

		joyDisableCyclicPolling();
		sp48 = pakAllocateNote(PFS(device), ROM_COMPANYCODE, ROM_GAMECODE, g_PakNoteGameName, g_PakNoteExtName, notesize, &g_Paks[device].pdnoteindex);
		joyEnableCyclicPolling();

		g_Paks[device].unk2b8_02 = true;

		if (pakHandleResult(sp48, device, true)) {
			isnewnote = true;
		} else {
			return false;
		}
	}

	pakQueryTotalUsage(device);
	pakQueryPdSize(device);

	g_Paks[device].unk2b8_07 = false;

	g_Paks[device].headercachecount = 0;
	g_Paks[device].unk010 = PAK010_11;

	// If it's a new note, create the filesystem
	if (isnewnote) {
		serial = pakCreateFilesystem(device);

		if (serial != -1) {
			g_Paks[device].serial = serial;
		} else {
			error = true;
		}
	}

	// Check the filesystem for errors and try to recreate it if broken
	if (!error) {
		if (pakRepairFilesystem(device) == -1) {
			serial = pakCreateFilesystem(device);

			if (serial != -1) {
				g_Paks[device].serial = serial;
			} else {
				error = true;
			}

			if (device != SAVEDEVICE_GAMEPAK) {
				g_Paks[device].unk2b8_07 = true;
			}
		}
	}

	if (!error) {
		maxfileid = pakFindMaxFileId(device);

		if (maxfileid != -1) {
			g_Paks[device].maxfileid = maxfileid;

			if (pakGetFileIdsByType(device, PAKFILETYPE_TERMINATOR, fileids) == 0 && pakCreateInitialFiles(device)) {
				g_Paks[device].unk010 = (device == SAVEDEVICE_GAMEPAK) ? PAK010_11 : PAK010_06;

				func0f110d90(device);

				return true;
			}
		}
	}

	g_Paks[device].unk010 = PAK010_22;

	func0f110d90(device);

	return false;
}

static bool pakProbe(s8 device)
{
	bool plugged = false;
	s32 ret;
	bool done = false;

	joyDisableCyclicPolling();

	// Try memory pak
	ret = pakInitPak(&g_PiMesgQueue, PFS(device), device, NULL);

	if (pakHandleResult(ret, device, true)) {
		g_Paks[device].unk010 = PAK010_03;

		if (device == SAVEDEVICE_GAMEPAK) {
			pakExecuteDebugOperations();
			pakExecuteDebugOperations();
			pakExecuteDebugOperations();
		}

		plugged = true;
		done = true;
	} else if (ret == PAK_ERR1_NOPAK) {
		done = true;
	}

	if (!done) {
		if (device == SAVEDEVICE_GAMEPAK) {
			plugged = false;
			done = true;
		}

		if (!done) {
			// Try rumble pak
			ret = osMotorProbe(&g_PiMesgQueue, PFS(device), device);

			if (pakHandleResult(ret, device, false)) {
				g_Paks[device].type = PAKTYPE_RUMBLE;
				g_Paks[device].unk010 = PAK010_11;
				g_Paks[device].rumblestate = RUMBLESTATE_1;
				g_Paks[device].unk264++;

				plugged = true;
				done = true;
			} else if (ret == PAK_ERR1_NOPAK) {
				plugged = false;
				done = true;
			}

			if (!done) {
				// Try game boy pak
				ret = osGbpakInit(&g_PiMesgQueue, PFS(device), device);

				if (pakHandleResult(ret, device, false)) {
					g_Paks[device].type = PAKTYPE_GAMEBOY;
					g_Paks[device].unk010 = PAK010_08;
					g_Paks[device].unk2b8_01 = false;
					g_Paks[device].unk264++;

					plugged = true;
				} else if (ret == PAK_ERR1_NOPAK) {
					plugged = false;
				}
			}
		}
	}

	joyEnableCyclicPolling();

	return plugged;
}

static void pakSaveHeaderToCache(s8 device, s32 blocknum, struct pakfileheader *header)
{
	struct pak *pak = &g_Paks[device];
	s32 count;
	s32 overview[1024];
	u32 stack[2];
	s32 j;
	s32 k;
	s32 i;
	s32 endblocknum = header->filelen / pakGetBlockSize(device) + blocknum;

	for (i = 0; i < ARRAYCOUNT(overview); i++) {
		overview[i] = -1;
	}

	// Iterate existing cache items and write their indexes into the overview array,
	// where the index in the overview array is determined by the cache item's blocknum.
	for (i = 0; i < pak->headercachecount; i++) {
		struct pakfileheader *tmp = (struct pakfileheader *) pak->headercache[i].payload;

		for (j = 0; j < tmp->filelen / pakGetBlockSize(device); j++) {
			overview[pak->headercache[i].blocknum + j] = i;
		}
	}

	// Examine the overview range where the new cache entry is going to go.
	// If any cache entries are there then they're likely an older version of
	// the cache header that's being inserted, so invalidate them.
	for (k = blocknum; k < endblocknum; k++) {
		if (overview[k] != -1) {
			pak->headercache[overview[k]].blocknum = -1;
		}
	}

	// Save the header into the cache
	pak->headercache[pak->headercachecount].blocknum = blocknum;
	memcpy(pak->headercache[pak->headercachecount].payload, header, pakGetBlockSize(device));

	pak->headercachecount++;

	// Close any gaps in the cache list and recount for good measure
	count = 0;

	for (i = 0; i < pak->headercachecount; i++) {
		if (pak->headercache[i].blocknum != -1) {
			pak->headercache[count].blocknum = pak->headercache[i].blocknum;
			memcpy(&pak->headercache[count].payload, &pak->headercache[i].payload, pakGetBlockSize(device));
			count++;
		}
	}

	pak->headercachecount = count;
}

static bool pakRetrieveHeaderFromCache(s8 device, s32 blocknum, struct pakfileheader *dst)
{
	struct pak *pak = &g_Paks[device];
	s32 i;

	if (pak->headercachecount < MAX_HEADERCACHE_ENTRIES) {
		for (i = 0; i < pak->headercachecount; i++) {
			if (blocknum == pak->headercache[i].blocknum) {
				memcpy(dst, &pak->headercache[i].payload, sizeof(struct pakfileheader));
				return true;
			}
		}
	}

	return false;
}

/**
 * Initialise a game pak or controller pak note's filesystem from scratch.
 *
 * - A serial is generated for the pak.
 * - A terminator file (containing the serial) is then written at the start of the pak.
 * - Random bytes are then written into a block after the terminator.
 *
 * Return the pak's serial on success, or -1 on failure.
 */
static s32 pakCreateFilesystem(s8 device)
{
	u8 data[32];
	s32 address;
	s32 result;
	s32 i;

	for (i = 0; i < 32; i++) {
		data[i] = random() & 0xff;
	}

	address = pakGetAlignedFileLenByBodyLen(device, pakGetBodyLenByType(device, PAKFILETYPE_TERMINATOR));

	g_Paks[device].maxfileid = 0x10;
	g_Paks[device].serial = pakGenerateSerial(device);
	g_Paks[device].headercachecount = 0;

	pakWriteFileAtOffset(device, 0, PAKFILETYPE_TERMINATOR, NULL, 0, NULL, NULL, 0, 1);

	result = pakReadWriteBlock(device, PFS(device), g_Paks[device].pdnoteindex, PFS_WRITE, address, pakGetBlockSize(device), data);

	if (pakHandleResult(result, device, true) == 0) {
		return -1;
	}

	return g_Paks[device].serial;
}

static bool pakGetFilesystemLength(s8 device, u32 *outlen)
{
	struct pakfileheader header;
	s32 offset = 0;
	u32 stack[2];

	while (offset < g_Paks[device].pdnumbytes) {
		s32 ret = pakReadHeaderAtOffset(device, offset, &header);
		offset += header.filelen;

		if (ret == PAK_ERR2_NOPAK) {
			return true;
		}

		if (PAKFILETYPE_TERMINATOR == header.filetype) {
			*outlen = offset;
			return false;
		}

		if (ret != PAK_ERR2_OK) {
			return false;
		}
	}

	return false;
}


/**
 * Read a file from cache or from the pak and write it to *data.
 */
static s32 pak0f11b86c(s8 device, u32 offset, u8 *data, struct pakfileheader *header, s32 bodylen)
{
	struct pakfileheader headerstack;
	s32 s0;
	s32 negativebodylen2;
	bool negativebodylen;
	s32 ret;
	bool isoneblock;
	u32 i;
	u32 filelen;
	u32 blocksize;
	u32 alignedfilelen;
	u32 stack[3];
	u8 buffer[16];
	s32 offsetinblock;
	s32 blocknum;
	u8 sp58[128];

	if (bodylen == -1) {
		negativebodylen = true;
		negativebodylen2 = true;
		bodylen = 0;
	} else {
		negativebodylen = false;
		negativebodylen2 = false;
	}

	blocksize = pakGetBlockSize(device);
	isoneblock = bodylen && data && (bool)(bodylen + sizeof(struct pakfileheader) <= blocksize);

	if (header == NULL) {
		header = &headerstack;
	}

	ret = pakReadHeaderAtOffset(device, offset, header);

	if (ret != 0) {
		return ret;
	}

	if (!negativebodylen2 && !header->occupied) {
		return 10;
	}

	if (isoneblock) {
		if (pakRetrieveBlockFromCache(device, offset, buffer)) {
			for (i = 0; i < bodylen; i++) {
				data[i] = buffer[sizeof(struct pakfileheader) + i];
			}

			return 0;
		}
	}

	if (bodylen == header->bodylen) {
		bodylen = 0;
	}

	alignedfilelen = pakGetAlignedFileLenByBodyLen(device, header->bodylen);

	filelen = (bodylen == 0 ? header->bodylen : bodylen) + sizeof(struct pakfileheader);

	if (negativebodylen) {
		filelen = alignedfilelen;
	}

	joyDisableCyclicPolling();

	for (i = 0; i != filelen; i++) {
		offsetinblock = i % pakGetBlockSize(device);
		blocknum = i / pakGetBlockSize(device);

		if (offsetinblock == 0) {
			s32 absoluteoffset = pakGetBlockSize(device) * blocknum + offset;
			s32 ret;

			ret = pakReadWriteBlock(device, PFS(device), g_Paks[device].pdnoteindex, OS_READ, absoluteoffset, pakGetBlockSize(device), sp58);

			if (!pakHandleResult(ret, device, true)) {
				joyEnableCyclicPolling();

				if (ret == 1) {
					return 1;
				}

				return 4;
			}
		}

		if (i >= 0x10 && data != NULL) {
			*data = sp58[offsetinblock];
			data++;
		}
	}

	joyEnableCyclicPolling();

	return 0;
}

static s32 pakWriteFileAtOffset(s8 device, u32 offset, u32 filetype, u8 *newdata, s32 bodylenarg, s32 *outfileid, u8 *olddata, u32 fileid, u32 generation)
{
	u8 headerbytes[sizeof(struct pakfileheader)];
	struct pakfileheader *headerptr;
	u32 blocksize;
	s32 filelen;
	s32 bodylen;
	s32 paddinglen;
	u8 newfilebytes[4096];
	u8 oldfilebytes[4096];
	u32 numblocks;
	s32 i = 0;
	s32 j;
	s32 k;
	s32 result;
	u8 version;
	struct pakfileheader *newheader;
	struct pakfileheader *oldheader;
	u8 *oldfileu8ptr;
	u8 *newfileu8ptr;
	u8 *headeru8ptr;

	blocksize = pakGetBlockSize(device);

	generation &= 0x1ff;
	bodylen = bodylenarg ? bodylenarg : pakGetBodyLenByType(device, filetype);
	filelen = pakGetAlignedFileLenByBodyLen(device, bodylen);

	// Build the header bytes on the stack
	headerptr = (struct pakfileheader *) headerbytes;

	headerptr->fileid = fileid ? fileid : ++g_Paks[device].maxfileid;
	headerptr->deviceserial = g_Paks[device].serial;
	headerptr->filelen = filelen;
	headerptr->version = 0;
	headerptr->bodylen = bodylen;
	headerptr->generation = generation;
	headerptr->filetype = filetype;
	headerptr->fileid &= 0x7f;

	if (outfileid != NULL) {
		*outfileid = headerptr->fileid;
	}

	headerptr->occupied = newdata ? 1 : 0;

	if (headerptr->occupied) {
		pakCalculateChecksum(newdata, newdata + headerptr->bodylen, headerptr->bodysum);
	} else {
		headerptr->bodysum[0] = 0xffff;
		headerptr->bodysum[1] = 0xffff;
	}

	// Build "old" and "new" versions of the complete file on the stack.
	// "old" is what is believed to be on the pak already, and "new" is what is
	// needed to be written if any. Either the olddata or newdata pointers can
	// be null when creating or deleting files, so substitute their bytes with
	// a plus sign if so.
	// These will then be compared block by block to decide which blocks need
	// to be written to the pak.
	newheader = (struct pakfileheader *) newfilebytes;
	paddinglen = filelen - bodylen - sizeof(struct pakfileheader);
	headeru8ptr = headerbytes;
	newfileu8ptr = newfilebytes;
	oldfileu8ptr = oldfilebytes;

	// Header
	for (i = 0; i < sizeof(struct pakfileheader); i++) {
		*newfileu8ptr = headeru8ptr[i];
		*oldfileu8ptr = '+';
		newfileu8ptr++;
		oldfileu8ptr++;
	}

	// Data
	for (i = 0; i != bodylen; i++) {
		*newfileu8ptr = newdata ? newdata[i] : '+';
		*oldfileu8ptr = olddata ? olddata[i] : '+';
		newfileu8ptr++;
		oldfileu8ptr++;
	}

	// Data padding to reach alignment
	for (i = 0; i != paddinglen; i++) {
		*newfileu8ptr = newdata ? newdata[i] : '+';
		*oldfileu8ptr = olddata ? olddata[i] : '+';
		newfileu8ptr++;
		oldfileu8ptr++;
	}

	numblocks = filelen / blocksize;

	if ((filelen % blocksize) != 0) {
		numblocks++;
	}

	joyDisableCyclicPolling();

	// Write the header with writecompleted = 0, followed by the data, then
	// rewrite the header with writecompleted = 1. This allows the game to
	// detect if data on the pak was only partially written.
	for (j = 0; j < 2; j++) {
		newheader->writecompleted = j ? 1 : 0;

		// Checksum the header part after the checksums themselves
		pakCalculateChecksum((u8 *) (newheader->bodysum + 2), (u8 *) (newheader + 1), newheader->headersum);

		for (i = 0; i != numblocks; i++) {
			s32 offsetinfile = pakGetBlockSize(device) * i;
			bool writethisblock = false;

			if (offsetinfile < sizeof(struct pakfileheader)) {
				// Header - always write it
				writethisblock = true;
			} else {
				// Don't write data on the second iteration
				if (j == 1) {
					break;
				}

				// Don't write data for blank files or if the file is being deleted
				if (newheader->filetype == PAKFILETYPE_BLANK || newdata == NULL) {
					break;
				}

				if (olddata) {
					// Check if any bytes in the old and new blocks are different
					for (k = 0; k < blocksize; k++) {
						s32 index = i * blocksize + k;

						if (newfilebytes[index] != oldfilebytes[index]) {
							writethisblock = true;
							break;
						}
					}
				} else {
					writethisblock = true;
				}
			}

			if (writethisblock) {
				result = pakReadWriteBlock(device, PFS(device), g_Paks[device].pdnoteindex, OS_WRITE, offset + i * blocksize, pakGetBlockSize(device), &newfilebytes[offsetinfile]);

				if (!pakHandleResult(result, device, true)) {
					joyEnableCyclicPolling();

					if (result == PAK_ERR1_NOPAK) {
						return 1;
					}

					return 4;
				}
			}
		}
	}

	joyEnableCyclicPolling();

	pakSaveHeaderToCache(device, offset / pakGetBlockSize(device), newheader);

	return 0;
}

bool pakRepair(s8 device)
{
	s32 result;

	switch (g_Paks[device].unk010) {
	case PAK010_14:
	case PAK010_19:
		break;
	default:
		joyDisableCyclicPolling();
		result = osPfsChecker(PFS(device));
		joyEnableCyclicPolling();

		if (result == PAK_ERR1_OK) {
			g_Paks[device].unk010 = PAK010_02;
			return true;
		}

		pakHandleResult(result, device, false);

		g_Paks[device].unk010 = PAK010_22;
		break;
	}

	return false;
}

static bool pakHandleResult(s32 err1, s8 device, bool arg2)
{
	if (err1 == PAK_ERR1_OK) {
		return true;
	}

	if (arg2) {
		switch (err1) {
		case PAK_ERR1_NOPAK:
			g_Paks[device].type = PAKTYPE_MEMORY;
			g_Paks[device].unk010 = PAK010_01;
			break;
		case PAK_ERR1_DEVICE:
			g_Paks[device].type = PAKTYPE_MEMORY;
			g_Paks[device].unk010 = PAK010_14;
			break;
		case PAK_ERR1_INCONSISTENT:
		case PAK_ERR1_IDFATAL:
			g_Paks[device].type = PAKTYPE_MEMORY;
			g_Paks[device].unk010 = PAK010_15;
			break;
		case PAK_ERR1_DATAFULL:
		case PAK_ERR1_DIRFULL:
			g_Paks[device].type = PAKTYPE_MEMORY;
			g_Paks[device].unk010 = PAK010_16;
			break;
		}
	}

	switch (err1) {
	case PAK_ERR1_NOPAK:
	case PAK_ERR1_NEWPAK:
	case PAK_ERR1_INCONSISTENT:
	case PAK_ERR1_CONTRFAIL:
	case PAK_ERR1_INVALID:
	case PAK_ERR1_BADDATA:
	case PAK_ERR1_DATAFULL:
	case PAK_ERR1_DIRFULL:
	case PAK_ERR1_EXIST:
	case PAK_ERR1_IDFATAL:
	case PAK_ERR1_DEVICE:
	case PAK_ERR1_NOGBCART:
	case PAK_ERR1_NEWGBCART:
	case PAK_ERR1_EEPROMMISSING:
	case PAK_ERR1_EEPROMREADFAILED:
	case PAK_ERR1_EEPROMWRITEFAILED:
	case PAK_ERR1_EEPROMINVALIDOP:
	case PAK_ERR1_EEPROMINVALIDARG:
		break;
	}

	return false;
}

void paksTick(void)
{
	s32 i;

	if (g_Vars.unk0004e4) {
		g_MpPlayerNum = 0;

		menuSetBanner(MENUBANNER_CHECKINGPAK, true);

		var80075d14 = false;

		if (g_Vars.unk0004e4 & 0x0f) {
			joy00013974(0);

			// Waiting for some timer
			if ((g_Vars.unk0004e4 & 0x0f) > 9) {
				if ((g_Vars.lvframenum % 7) == 0) {
					g_Vars.unk0004e4--;
				}
			} else {
				g_Vars.unk0004e4--;
			}
		} else {
			joyCheckPfs(2);

			for (i = 0; i < 4; i++) {
				if (g_Vars.unk0004e4 & (1 << (i + 4))) {
					pak0f1169c8(i, true);
					g_Vars.unk0004e4 &= ~(1 << (i + 4));
				} else if (g_Vars.unk0004e4 & (1 << (i + 8))) {
					pak0f1169c8(i, false);
					g_Vars.unk0004e4 &= ~(1 << (i + 8));
				}
			}

			if (!joy00013980()) {
				joy00013974(1);
				joy000139c8();
			}

			menuSetBanner(-1, true);

			var80075d14 = true;
		}
	}
}

void pak0f11c6d0(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		switch (g_Paks[i].unk010) {
		case PAK010_02:
		case PAK010_03:
		case PAK010_04:
		case PAK010_05:
		case PAK010_06:
			g_Paks[i].unk010 = PAK010_01;
			var80075d10 &= ~(1 << i);
			g_MpPlayerNum = i;
			menuSetBanner(-1, true);
			break;
		}
	}

	var8005eedc = true;
}

void pakExecuteDebugOperations(void)
{
	s32 pass = false;
	s8 i;

	pak0f11ca30();

	for (i = 0; i < 5; i++) {
		if (g_Paks[i].unk014) {
			pak0f11df94(i);
		}
	}

	for (i = 0; i < 5; i++) {
		switch (g_Paks[i].unk010) {
		case PAK010_02:
		case PAK010_03:
		case PAK010_04:
		case PAK010_05:
		case PAK010_06:
			pass = true;
			break;
		}
	}

	if (pass) {
		var8005eedc = false;
	} else {
		var8005eedc = true;
	}
}

static void pak0f11ca30(void)
{
	if (g_Vars.tickmode != TICKMODE_CUTSCENE || g_MenuData.count > 0) {
		u8 oldvalue = var80075d10;
		u8 newvalue = var80075d10;
		u8 thing = 0xff;
		s32 i;

		if ((g_Vars.unk0004e4 & 0xf) == 0) {
			for (i = 0; i < 5; i++) {
				if ((g_Vars.paksconnected2 | g_Vars.paksconnected) & (1 << i)) {
					if (thing == 0xff) {
						thing = joyShiftPfsStates();
					}

					if (((thing & (1 << i)) != (oldvalue & (1 << i)))) {
						if ((thing & (1 << i))) {
							g_Paks[i].unk010 = PAK010_02;
							newvalue |= (1 << i);
						} else {
							g_Paks[i].unk010 = PAK010_01;
							newvalue &= ~(1 << i);
							func0f110d90(i);
						}
					}
				}
			}

			var80075d10 = newvalue;
		}
	}
}

void pakRumble(s32 device, f32 numsecs, s32 onduration, s32 offduration)
{
	if (g_Paks[device].unk010 == PAK010_11
			&& g_Paks[device].type == PAKTYPE_RUMBLE
			&& g_Paks[device].rumblestate != RUMBLESTATE_DISABLED_STOPPING
			&& g_Paks[device].rumblestate != RUMBLESTATE_DISABLED_STOPPED
			&& g_Paks[device].rumblettl < 60 * numsecs) {
		g_Paks[device].rumblestate = RUMBLESTATE_ENABLED_STARTING;
		g_Paks[device].rumblettl = 60 * numsecs;
		g_Paks[device].rumblepulsestopat = onduration;
		g_Paks[device].rumblepulselen = onduration + offduration;
		g_Paks[device].rumblepulsetimer = 0;
	}
}

void paksStop(bool disablepolling)
{
	s8 i;

	for (i = 0; i < 5; i++) {
		s32 type = g_Paks[i].type;

		if (type);

		if (type != PAKTYPE_MEMORY && type != PAKTYPE_GAMEBOY) {
			joyStopRumble(i, disablepolling);
		}
	}
}

void pakDisableRumbleForPlayer(s8 playernum)
{
	s32 i;
	s32 tmp = playernum;
	s32 contpads[2];

	joyGetContpadNumsForPlayer(tmp, &contpads[0], &contpads[1]);

	for (i = 0; i < 2; i++) {
		if (contpads[i] >= 0 && g_Paks[contpads[i]].type == PAKTYPE_RUMBLE) {
			g_Paks[contpads[i]].rumblestate = RUMBLESTATE_DISABLED_STOPPING;
			joyStopRumble(contpads[i], true);
		}
	}
}

void pakEnableRumbleForPlayer(s8 playernum)
{
	s32 i;
	s32 tmp = playernum;
	s32 contpads[2];

	joyGetContpadNumsForPlayer(tmp, &contpads[0], &contpads[1]);

	for (i = 0; i < 2; i++) {
		if (contpads[i] >= 0
				&& g_Paks[contpads[i]].type == PAKTYPE_RUMBLE
				&& g_Paks[contpads[i]].rumblestate == RUMBLESTATE_DISABLED_STOPPED) {
			g_Paks[contpads[i]].rumblestate = RUMBLESTATE_ENABLING;
		}
	}
}

void pakDisableRumbleForAllPlayers(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Paks[i].type == PAKTYPE_RUMBLE) {
			g_Paks[i].rumblestate = RUMBLESTATE_DISABLED_STOPPING;
			joyStopRumble(i, true);
		}
	}
}

void pakEnableRumbleForAllPlayers(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Paks[i].type == PAKTYPE_RUMBLE && g_Paks[i].rumblestate == RUMBLESTATE_DISABLED_STOPPED) {
			g_Paks[i].rumblestate = RUMBLESTATE_ENABLING;
		}
	}
}

void pak0f117f94nb(s8 device);

static void pak0f11df94(s8 device)
{
	if (g_Paks[device].unk2b8_07) {
		if (var80075d14) {
			menuSetBanner(-1, true);
		}

		if (func0f0fd1f4(device, 4)) {
			func0f0fd320(device, 4);
			g_Paks[device].unk2b8_07 = false;
		}
	}

	switch (g_Paks[device].unk010) {
	case PAK010_00:
		break;
	case PAK010_01:
		g_Paks[device].unk010 = PAK010_00;
		g_Paks[device].unk264++;
		g_Paks[device].unk2b8_07 = false;
		g_Paks[device].type = PAKTYPE_NONE;

		if (var80075d14) {
			menuSetBanner(-1, true);
		}

		break;
	case PAK010_02:
		if (var80075d14) {
			menuSetBanner(-1, true);
		}

		pakProbe(device);
		break;
	case PAK010_03:
		if (g_Vars.paksconnected & (1 << device)) {
			if (device == SAVEDEVICE_GAMEPAK) {
				g_Paks[device].unk010 = PAK010_05;
			} else {
				g_Paks[device].unk010 = PAK010_04;
			}
		} else {
			g_Paks[device].unk010 = PAK010_07;
		}
		break;
	case PAK010_07:
		if (g_Vars.paksconnected & (1 << device)) {
			g_Paks[device].unk010 = PAK010_02;
		}
		break;
	default:
		break;
	case PAK010_04:
		g_MpPlayerNum = device;

		if (var80075d14) {
			menuSetBanner(MENUBANNER_CHECKINGPAK, true);
		}

		g_Paks[device].unk010 = PAK010_05;
		break;
	case PAK010_05:
		joyDisableCyclicPolling();
		mempakPrepare(device);
		joyEnableCyclicPolling();
		break;
	case PAK010_06:
		if (var80075d14) {
			menuSetBanner(-1, true);
		}

		g_Paks[device].unk010 = PAK010_11;
		break;
	case PAK010_08:
		break;
	case PAK010_09:
		g_Paks[device].unk008 = 0;
		g_Paks[device].unk010 = PAK010_10;
		break;
	case PAK010_10:
		g_Paks[device].unk010 = PAK010_24;
		break;
	case PAK010_24:
		g_Paks[device].unk010 = PAK010_25;
		break;
	case PAK010_25:
		g_Paks[device].unk010 = PAK010_11;
		break;
	case PAK010_12:
		g_Paks[device].unk010 = PAK010_11;
		break;
	case PAK010_13:
		break;
	case PAK010_15:
		if (var80075d14) {
			menuSetBanner(-1, true);
		}

		if ((g_Vars.paksconnected & (1 << device)) && func0f0fd1f4(device, 1)) {
			func0f0fd320(device, 1);
			g_Paks[device].unk010 = PAK010_20;
		} else {
			// empty
		}
		break;
	case PAK010_26:
		if (func0f0fd1f4(device, 3)) {
			func0f0fd320(device, 3);
			g_Paks[device].unk010 = PAK010_27;
		}
		break;
	case PAK010_27:
		g_Paks[device].unk010 = PAK010_11;
		break;
	case PAK010_14:
		if (var80075d14) {
			menuSetBanner(-1, true);
		}

		if (((g_Vars.paksconnected & (1 << device))) && func0f0fd1f4(device, 2)) {
			func0f0fd320(device, 2);
			g_Paks[device].unk010 = PAK010_19;
		} else {
			// empty
		}
		break;
	case PAK010_16:
		if (var80075d14) {
			menuSetBanner(-1, true);
		}

		if ((g_Vars.paksconnected & (1 << device)) && func0f0fd1f4(device, 0)) {
			func0f0fd320(device, 0);
			g_Paks[device].unk010 = PAK010_21;
		} else {
			// empty
		}
		break;
	case PAK010_21:
		if (var80075d14) {
			menuSetBanner(-1, true);
		}
		break;
	case PAK010_22:
		if (var80075d14) {
			menuSetBanner(-1, true);
		}
		break;
	}

	if (g_Paks[device].unk2b8_07) {
		if (var80075d14) {
			menuSetBanner(-1, true);
		}

		if (func0f0fd1f4(device, 4)) {
			func0f0fd320(device, 4);
			g_Paks[device].unk2b8_07 = false;
		}
	}
}

static void pakProbeEeprom(void)
{
	s32 type;

	joyDisableCyclicPolling();
	type = osEepromProbe(&g_PiMesgQueue);
	joyEnableCyclicPolling();

	if (type == EEPROM_TYPE_16K) {
		g_PakHasEeprom = true;
	} else {
		g_PakHasEeprom = false;
	}
}

static PakErr1 pakReadEeprom(u8 address, u8 *buffer, u32 len)
{
	s32 result;

	joyDisableCyclicPolling();
	result = osEepromLongRead(&g_PiMesgQueue, address, buffer, len);
	joyEnableCyclicPolling();

	return result == PAK_ERR1_OK ? PAK_ERR1_OK : PAK_ERR1_EEPROMREADFAILED;
}

static PakErr1 pakWriteEeprom(u8 address, u8 *buffer, u32 len)
{
	s32 result;

	joyDisableCyclicPolling();
	result = osEepromLongWrite(&g_PiMesgQueue, address, buffer, len);
	joyEnableCyclicPolling();

	return result == PAK_ERR1_OK ? PAK_ERR1_OK : PAK_ERR1_EEPROMWRITEFAILED;
}

void pakSetBitflag(s32 flagnum, u8 *bitstream, bool set)
{
	u32 byteindex = (u32)flagnum / 8;
	u8 mask = 1 << ((u32)flagnum % 8);

	if (set) {
		bitstream[byteindex] |= mask;
	} else {
		bitstream[byteindex] &= (u8)~mask;
	}
}

bool pakHasBitflag(u32 flagnum, u8 *bitstream)
{
	u32 byteindex = flagnum / 8;
	u8 mask = 1 << (flagnum % 8);

	return bitstream[byteindex] & mask ? 1 : 0;
}

void pakClearAllBitflags(u8 *flags)
{
	s32 i;

	for (i = 0; i <= GAMEFILEFLAG_4E; i++) {
		pakSetBitflag(i, flags, false);
	}
}

/**
 * The note name and note extension are stored on the pak using N64 font code.
 * This is different to ASCII.
 *
 * This function expects src to be a pointer to an N64 font code string.
 * It converts it to ASCII and writes it to dst. Characters are replaced with
 * an asterisk if they are invalid font codes or if the character doesn't exist
 * in PD's font.
 */
void pakN64FontCodeToAscii(char *src, char *dst, s32 len)
{
	char buffer[256];
	s32 i;
	s32 in;
	char c;
	char *ptr = buffer;

	for (i = 0; i < len;) {
		in = *src;
		src++;
		i++;
		c = '*';

		// @bug: The length check of the map is off by 1. The last char in the
		// list is '@', so if an @ sign appears in a note name then PD will
		// incorrectly replace it with '*' when displaying the name.
		// The original source likely used a literal here instead of sizeof().
		if (in < (s32)(sizeof(g_N64FontCodeMap) - 1)) {
			c = g_N64FontCodeMap[in];
		}

		// PD has a double quote in its fonts, but I guess it doesn't render
		// very well. So it gets replaced with two single quotes.
		if ((u32)c == '"') {
			*ptr = '\'';
			ptr++;
			*ptr = '\'';
		} else {
			*ptr = c;
		}

		ptr++;
	}

	*ptr = '\0';

	strcpy(dst, buffer);
}

s8 pakFindBySerial(s32 findserial)
{
	s8 device = -1;
	s32 i;

	for (i = 0; i < 5; i++) {
		if (pak0f116aec(i)) {
			s32 serial = pakGetSerial(i);

			if (findserial == serial) {
				device = i;
			}
		}
	}

	return device;
}

bool gbpakIsAnyPerfectDark(void)
{
	s8 i;

	for (i = 0; i < 4; i++) {
		if (gbpakIdentifyGame(i) == GBGAME_PD) {
			return true;
		}
	}

	return false;
}

/**
 * Probable @bug: This function is probably intended to be a "strings are equal"
 * check, however it's actually checking if either string starts with the other.
 */
static bool gbpakStrcmp(char *a, char *b)
{
	while (*a != '\0' && *b != '\0') {
		if (*a != *b) {
			return false;
		}

		a++;
		b++;
	}

	return true;
}

static s32 gbpakIdentifyGame(s8 device)
{
	OSGbpakId id;
	u8 status;
	s32 ret;
	s32 game = GBGAME_OTHER;
	bool poweredon = false;
	bool ok = true;

	if (g_Paks[device].type != PAKTYPE_GAMEBOY) {
		return GBGAME_OTHER;
	}

	joyDisableCyclicPolling();

	ret = osGbpakReadId(PFS(device), &id, &status);

	// NTSC Final sets poweredon to true unconditionally.
	// If we just set it to true without the if-statement then it creates a
	// mismatch because the compiler optimises out the poweredon = false line
	// earlier. Using this if-statement with a condition that's always true
	// makes the compiler optimise out the if-statement but leave both
	// assignments to poweredon intact.
	if (ok) {
		poweredon = true;
	}

	if (ret != PAK_ERR1_OK) {
		ok = false;
	}

	if (id.company_code == ROM_COMPANYCODE) {
		// PerfDark or PerfDark
		if (gbpakStrcmp(var80075cb4, id.game_title) || gbpakStrcmp(var80075cc0, id.game_title)) {
			g_Paks[device].isgbcamera = false;
			g_Paks[device].isgbpd = true;
			game = GBGAME_PD;
		}
	}

	if (game != GBGAME_PD) {
		ok = false;
	}

	if (poweredon) {
		if (osGbpakPower(PFS(device), OS_GBPAK_POWER_OFF) != PAK_ERR1_OK) {
			ok = false;
		}
	}

	joyEnableCyclicPolling();

	if (ok) {
		return game;
	}

	g_Paks[device].unk010 = PAK010_26;
	return GBGAME_OTHER;
}
