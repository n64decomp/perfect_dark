#include "versions.h"
#include <ultra64.h>
#include "constants.h"
#include "game/bossfile.h"
#include "game/camdraw.h"
#include "game/filelist.h"
#include "game/menu.h"
#include "game/crc.h"
#include "game/gamefile.h"
#include "game/lv.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/args.h"
#include "lib/crash.h"
#include "lib/joy.h"
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

#define NUM_PAGES 28

#define MAX_HEADERCACHE_ENTRIES 50

#if VERSION >= VERSION_JPN_FINAL
#define LINE_825  830
#define LINE_1058 1063
#define LINE_1551 1556
#define LINE_1802 1807
#define LINE_3486 3498
#define LINE_3495 3507
#define LINE_3599 3611
#define LINE_3654 3666
#define LINE_3668 3680
#define LINE_3829 3841
#define LINE_3865 3877
#define LINE_3889 3901
#define LINE_3948 3960
#define LINE_4140 4152
#define LINE_4394 4406
#define LINE_4742 4754
#define LINE_4801 4813
#elif VERSION >= VERSION_PAL_BETA
#define LINE_825  825
#define LINE_1058 1058
#define LINE_1551 1551
#define LINE_1802 1802
#define LINE_3486 3493
#define LINE_3495 3502
#define LINE_3599 3606
#define LINE_3654 3661
#define LINE_3668 3675
#define LINE_3829 3836
#define LINE_3865 3872
#define LINE_3889 3896
#define LINE_3948 3955
#define LINE_4140 4147
#define LINE_4394 4401
#define LINE_4742 4749
#define LINE_4801 4808
#elif VERSION >= VERSION_NTSC_FINAL
#define LINE_825  825
#define LINE_1058 1058
#define LINE_1551 1551
#define LINE_1802 1802
#define LINE_3486 3486
#define LINE_3495 3495
#define LINE_3599 3599
#define LINE_3654 3654
#define LINE_3668 3668
#define LINE_3829 3829
#define LINE_3865 3865
#define LINE_3889 3889
#define LINE_3948 3948
#define LINE_4140 4140
#define LINE_4394 4394
#define LINE_4742 4742
#define LINE_4801 4801
#elif VERSION >= VERSION_NTSC_1_0
#define LINE_825  822
#define LINE_1058 1055
#define LINE_1551 1551
#define LINE_1802 1788
#define LINE_3486 3290
#define LINE_3495 3299
#define LINE_3599 3403
#define LINE_3654 3459
#define LINE_3668 3473
#define LINE_3829 3634
#define LINE_3865 3670
#define LINE_3889 3694
#define LINE_3948 3753
#define LINE_4140 3945
#define LINE_4394 4199
#define LINE_4742 4547
#define LINE_4801 4606
#else
#define LINE_825  742
#define LINE_1058 994
#define LINE_1551 1461
#define LINE_1802 1698
#define LINE_3486 3133
#define LINE_3495 3142
#define LINE_3599 3246
#define LINE_3654 3328
#define LINE_3668 3342
#define LINE_3829 3829
#define LINE_3865 3865
#define LINE_3889 3889
#define LINE_3948 3573
#define LINE_4140 3779
#define LINE_4394 4029
#define LINE_4742 4377
#define LINE_4801 4436
#endif

/**
 * In NTSC Beta the functions joy_disable_cyclic_polling and joy_enable_cyclic_polling
 * take two arguments: __LINE__ and __FILE__. In newer versions of the game
 * these functions take no arguments. This macro is here to avoid using VERSION
 * checks everywhere where these are called.
 */
#if VERSION >= VERSION_NTSC_1_0
#define JOYARGS(line)
#else
#define JOYARGS(line) line, "pak.c"
#endif

#if VERSION >= VERSION_NTSC_1_0
#define SETBANNER(banner) if (var80075d14) { menu_set_banner(banner, true); }
#else
#define SETBANNER(banner) menu_set_banner(banner, true)
#endif

#define PAKFEATURE_MEMORY  0x01
#define PAKFEATURE_RUMBLE  0x02
#define PAKFEATURE_GAMEBOY 0x04

const char g_N64FontCodeMap[] = "\0************** 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#'*+,-./:=?@";
const char var7f1b3ad4[] = "Pak %d -> Pak_UpdateAndGetPakNoteInfo - ERROR - ekPakErrorPakFatal\n";
const char var7f1b3b18[] = "Pak %d -> Pak_UpdateAndGetPakNoteInfo - ERROR - ekPakErrorNoPakPresent\n";

struct pak g_Paks[5]; // controller paks + EEPROM

#if VERSION >= VERSION_NTSC_1_0
u32 var800a317c;
#endif

OSPfs g_Pfses[MAX_PLAYERS];
u32 var800a3320;
u32 var800a3324;
u32 var800a3328;
u32 var800a332c;
u32 var800a3330;
u32 var800a3334;
u32 var800a3338;
u32 var800a333c;
u32 var800a3340;
u32 var800a3344;
u32 var800a3348;
u32 var800a334c;
u32 var800a3350;
u32 var800a3354;
u32 var800a3358;
u32 var800a335c;
u32 var800a3360;
u32 var800a3364;
u32 var800a3368;
u32 var800a336c;
u32 var800a3370;
u32 var800a3374;
u32 var800a3378;
u32 var800a337c;
u32 var800a3380;
u32 var800a3384;

#ifndef DEBUG
// This is likely g_DebugCutsceneLabelPtrs and/or g_DebugCutsceneLabelBuffers
// but with reduced lengths
u32 var800a3388;
u32 var800a338c;
u32 var800a3390;
u32 var800a3394;
u32 var800a3398;
u32 var800a339c;
#endif

#if VERSION >= VERSION_NTSC_1_0
u16 var80075cb0 = ROM_COMPANYCODE;
char var80075cb4[] = "PerfDark";
char var80075cc0[] = "PerfDark";
#else
u16 var80075cb0 = ROM_COMPANYCODE;
u16 var80078054nb = ROM_COMPANYCODE;
char var80078058nb[] = "POCKETCAMERA";
char var80078068nb[] = "GAMEBOYCAMERA";
char var80078078nb[] = "PerfDark";
char var80078084nb[] = "GAMEBOYCAMERA";
#endif

u32 var80075ccc = 0x00000400;
u32 g_PakHasEeprom = false;
u32 var80075cd4 = 0x00000000;
u32 var80075cd8 = 0x00000000;
u32 g_PakDebugForceCrc = 0;
u32 g_PakDebugForceScrub = 0;
u32 g_PakDebugPakDump = 0;
u32 g_PakDebugPakCache = 1;
u32 g_PakDebugPakInit = 0;

#if VERSION >= VERSION_NTSC_1_0
u32 g_PakDebugWipeEeprom = 0;
u32 g_PakDebugCorruptMe = 0;
#endif

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

u32 var80075d0c = 0x00000000;
u8 g_PaksPlugged = 0;

#if VERSION >= VERSION_NTSC_1_0
bool var80075d14 = true;
#endif

void pak0f116bdc(s8 device, u8 *arg1, u8 *arg2);
u16 _pak_get_serial(s8 device);
u32 _pak_get_type(s8 device);
PakErr1 pak0f116df0(s8 device, struct pakdata **pakdata);
PakErr1 _pak_delete_game_note(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name);
s32 _pak_delete_file(s8 device, s32 fileid);
s32 _pak_save_at_guid(s8 device, s32 fileid, s32 filetype, u8 *newdata, s32 *outfileid, u8 *olddataptr);
PakErr1 pak_delete_game_note3(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name);
u32 pak_get_pd_num_bytes(s8 device);
s32 _pak_create_camera_file(s8 device, s32 *outfileid);
s32 pak_resize_note(s8 device, s32 numpages);
void pak0f1185e0(s8 device, s32 arg1, s32 arg2);
u32 pak0f118674(s8 device, u32 filetype, s32 *outfileid);
void pak_calculate_checksum(u8 *start, u8 *end, u16 *checksum);
s32 _pak_read_body_at_guid(s8 device, s32 fileid, u8 *body, s32 arg3);
s32 _pak_get_file_ids_by_type(s8 device, u32 filetype, u32 *fileids);
s32 pak_check_file_can_fit_in_note(s8 device, s32 filetype, s32 *numspaces);
u32 pak0f119298(s8 device);
bool pak_repair_as_blank(s8 device, u32 *offsetptr, struct pakfileheader *header);
void pak_merge_blanks(s8 device);
void pak_set_features(s8 device, u8 features, u32 line, char *file);
void pak_set_defaults(s8 device);
PakErr1 pak_read_write_block(s8 device, OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer);
s32 pak_query_total_usage(s8 device);
void pak_save_header_to_cache(s8 device, s32 blocknum, struct pakfileheader *header);
s32 pak_retrieve_header_from_cache(s8 device, s32 blocknum, struct pakfileheader *dst);
s32 pak_create_filesystem(s8 device);
s32 pak_get_filesystem_length(s8 device, u32 *outlen);
s32 pak0f11b86c(s8 device, u32 offset, u8 *data, struct pakfileheader *header, s32 bodylen);
s32 pak_replace_file_at_offset_with_blank(s8 device, u32 offset);
s32 pak_write_file_at_offset(s8 device, u32 offset, u32 filetype, u8 *newdata, s32 bodylenarg, s32 *outfileid, u8 *olddata, u32 fileid, u32 generation);
s32 pak_handle_result(s32 err1, s8 device, s32  arg2, u32 line);
void pak_check_plugged(void);
void pak0f11d118(u8 *arg0, u8 arg1, u32 arg2);
void pak0f11d174(s8 device, u8 *arg1);
void pak0f11d214(u8 *arg0, u32 arg1);
void pak_dump_pak(void);
void pak_tick_state(s8 device);
void pak_probe_eeprom(void);
PakErr1 pak_read_eeprom(u8 address, u8 *buffer, u32 len);
PakErr1 pak_write_eeprom(u8 address, u8 *buffer, u32 len);
s32 gbpak_identify_game(s8 device);
void pak_wipe(s8 device, u32 blocknumstart, u32 blocknumend);

u32 pak_get_block_size(s8 device)
{
	return device == SAVEDEVICE_GAMEPAK ? 0x10 : 0x20;
}

u32 pak_align(s8 device, u32 size)
{
	return pak_get_block_size(device) == 0x20 ? align32(size) : align16(size);
}

void pak0f116650(void)
{
	// empty
}

s32 pak_get_aligned_file_len_by_body_len(s8 device, u32 bodylen)
{
	return pak_align(device, sizeof(struct pakfileheader) + bodylen);
}

u32 pak_get_body_len_by_file_len(u32 filelen)
{
	return filelen - sizeof(struct pakfileheader);
}

#if VERSION >= VERSION_NTSC_1_0
u32 pak_generate_serial(s8 device)
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
#endif

bool mempak_is_okay(s8 device)
{
	if (g_Paks[device].type == PAKTYPE_MEMORY) {
		switch (g_Paks[device].state) {
		case PAKSTATE_MEM_ENTER_DEVICEERROR:
		case PAKSTATE_MEM_ENTER_CORRUPT:
		case PAKSTATE_MEM_DEVICEERROR:
		case PAKSTATE_MEM_CORRUPT:
		case PAKSTATE_22:
			return false;
		}

		return true;
	}

	return false;
}

s32 pak_get_file_ids_by_type(s8 device, u32 filetype, u32 *fileids)
{
	return _pak_get_file_ids_by_type(device, filetype, fileids);
}

s32 pak0f1167d8(s8 device)
{
	return pak0f119298(device);
}

s32 pak_read_body_at_guid(s8 device, s32 fileid, u8 *body, s32 arg3)
{
	return _pak_read_body_at_guid(device, fileid, body, arg3);
}

s32 pak_save_at_guid(s8 device, s32 fileid, s32 filetype, u8 *body, s32 *outfileid, u8 *olddata)
{
	return _pak_save_at_guid(device, fileid, filetype, body, outfileid, olddata);
}

bool pak_delete_file(s8 device, s32 fileid)
{
	return _pak_delete_file(device, fileid);
}

PakErr1 pak_delete_game_note(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name)
{
	return _pak_delete_game_note(device, company_code, game_code, game_name, ext_name);
}

PakErr1 pak0f1168c4(s8 device, struct pakdata **arg1)
{
	return pak0f116df0(device, arg1);
}

s32 pak_create_camera_file(s8 device, s32 *outfileid)
{
	return _pak_create_camera_file(device, outfileid);
}

s32 pak_get_type(s8 device)
{
	return _pak_get_type(device);
}

s32 pak_get_serial(s8 device)
{
	return _pak_get_serial(device);
}

void pak0f116984(s8 arg0, u8 *arg1, u8 *arg2)
{
	pak0f116bdc(arg0, arg1, arg2);
}

void pak0f11698c(s8 device)
{
	// empty
}

#if VERSION >= VERSION_NTSC_1_0
void pak0f116994(void)
{
	if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		g_Vars.pakstocheck = 0xf8;
	}
}
#endif

#if VERSION >= VERSION_NTSC_1_0
void pak0f1169bc(u32 arg0, u32 arg1)
{
	// empty
}
#endif

void pak0f1169c8(s8 device, bool tick)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 prevvalue = g_Vars.paksneededformenu;

	g_Vars.paksneededformenu = 0x1f;

	if ((g_Vars.paksneededforgame | g_Vars.paksneededformenu) & (1 << device)) {
		g_PaksPlugged &= ~(1 << device);

		pak_check_plugged();
		pak_check_plugged();

		if (tick) {
			g_JoyPfsPollMasterEnabled = false;

			pak_tick_state(device);
			pak_tick_state(device);
			pak_tick_state(device);
			pak_tick_state(device);
			pak_tick_state(device);
			pak_tick_state(device);
			pak_tick_state(device);

			g_JoyPfsPollMasterEnabled = true;
		}
	}

	g_Vars.paksneededformenu = prevvalue;
#else
	if ((g_Vars.paksneededforgame | g_Vars.paksneededformenu) & (1 << device)) {
		g_PaksPlugged &= ~(1 << device);

		pak_check_plugged();

		if (tick) {
			pak_tick_state(device);
			pak_tick_state(device);
			pak_tick_state(device);
			pak_tick_state(device);
			pak_tick_state(device);
			pak_tick_state(device);
			pak_tick_state(device);
		}
	}
#endif
}

bool mempak_is_ready(s8 device)
{
	if (g_Paks[device].state == PAKSTATE_READY && g_Paks[device].type == PAKTYPE_MEMORY) {
		return true;
	}

	return false;
}

bool mempak_is_ready_or_full(s8 device)
{
	if ((g_Paks[device].state == PAKSTATE_READY
				|| g_Paks[device].state == PAKSTATE_MEM_ENTER_FULL
				|| g_Paks[device].state == PAKSTATE_MEM_FULL)
			&& g_Paks[device].type == PAKTYPE_MEMORY) {
		return true;
	}

	return false;
}

void pak0f116bdc(s8 device, u8 *arg1, u8 *arg2)
{
	*arg1 = g_Paks[device].unk2ba;
	*arg2 = g_Paks[device].unk2bb;
}

void pak_set_temporarily_plugged(s8 index)
{
	joy_set_pfs_temporarily_plugged(index);
}

u16 _pak_get_serial(s8 device)
{
	return g_Paks[device].serial;
}

u32 _pak_get_type(s8 device)
{
	return g_Paks[device].type;
}

ubool pak0f116cd4(s8 device)
{
	pak0f11d620(device);

	return g_Paks[device].unk2b8_05 && g_Paks[device].isgbcamera;
}

ubool pak0f116d4c(s8 device)
{
	return g_Paks[device].unk2b8_05 && !g_Paks[device].isgbcamera;
}

void pak_set_state(s8 device, s32 state)
{
	g_Paks[device].state = state;
}

PakErr1 pak0f116df0(s8 device, struct pakdata **pakdata)
{
	*pakdata = NULL;

	if (mempak_is_ready_or_full(device)) {
		if (pak_query_total_usage(device)) {
			*pakdata = &g_Paks[device].pakdata;
			return PAK_ERR1_OK;
		}

		return PAK_ERR1_NEWPAK;
	}

	return PAK_ERR1_NOPAK;
}

PakErr1 _pak_delete_game_note(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name)
{
	s32 result;

	if (mempak_is_ready_or_full(device)) {
		joy_disable_cyclic_polling(JOYARGS(738));
		result = pak_delete_game_note3(PFS(device), company_code, game_code, game_name, ext_name);
		joy_enable_cyclic_polling(JOYARGS(740));

		if (pak_handle_result(result, device, true, LINE_825)) {
			g_Paks[device].unk2b8_02 = 1;
			return PAK_ERR1_OK;
		}

		return PAK_ERR1_NEWPAK;
	}

	return PAK_ERR1_NOPAK;
}

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b3b60[] = "-> Unknown PakFileType_e - %d\n";
#else
const char var7f1b3b60[] = "-> Unknown PakFileType_e - %d";
#endif

#if VERSION < VERSION_NTSC_1_0
const char var7f1ad850nb[] = "Bad     ";
const char var7f1ad85cnb[] = "Blank   ";
const char var7f1ad868nb[] = "Swap    ";
const char var7f1ad874nb[] = "Camera  ";
const char var7f1ad880nb[] = "GmSetup ";
const char var7f1ad88cnb[] = "Boss    ";
const char var7f1ad898nb[] = "Multi Pl";
const char var7f1ad8a4nb[] = "Multi Gm";
const char var7f1ad8b0n0[] = "????????";
#endif

#if VERSION >= VERSION_NTSC_1_0
s32 _pak_delete_file(s8 device, s32 fileid)
{
	struct pakfileheader header;
	s32 result = pak_find_file(device, fileid, &header);

	if (result == -1) {
		return 1;
	}

	result = pak_write_file_at_offset(device, result, header.filetype, NULL, 0, NULL, NULL, 0, header.generation + 1);

	if (result) {
		return result;
	}

	return 0;
}
#else
s32 _pak_delete_file(s8 device, s32 fileid)
{
	struct pakfileheader header;
	u32 result;
	u32 tmp = pak_find_file(device, fileid, &header);

	if (tmp && (!tmp || tmp >= pak_get_pd_num_bytes(device) || ((pak_get_block_size(device) - 1U) & tmp))) {
		return 3;
	}

	result = pak_write_file_at_offset(device, tmp, header.filetype, NULL, 0, NULL, NULL, 0, header.generation + 1);

	if (result) {
		return result;
	}

	return 0;
}
#endif

s32 pak_get_plug_count(s8 device)
{
	return g_Paks[device].plugcount;
}

u32 pak_get_max_file_size(s8 device)
{
	if (device != SAVEDEVICE_GAMEPAK) {
		return 0x4c0;
	}

	return 0x100;
}

s32 pak_get_body_len_by_type(s8 device, u32 filetype)
{
	s32 len = 0;

	switch (filetype) {
	case PAKFILETYPE_001:
	case PAKFILETYPE_BLANK:
		break;
	case PAKFILETYPE_TERMINATOR:
		len = pak_get_max_file_size(device) - sizeof(struct pakfileheader);
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

#if VERSION < VERSION_NTSC_1_0
void pak0f1114a0nb(u32 arg0)
{
	if (arg0 >= 0x41) {
		if (arg0 != 0x80) {

		}
	} else if (arg0 >= 0x21) {
		if (arg0 != 0x40) {

		}
	} else {
		switch (arg0) {
		case 0x01:
		case 0x02:
		case 0x03:
		case 0x04:
		case 0x05:
		case 0x06:
		case 0x07:
		case 0x08:
		case 0x09:
		case 0x0a:
		case 0x0b:
		case 0x0c:
		case 0x0d:
		case 0x0e:
		case 0x0f:
		case 0x10:
		case 0x11:
		case 0x12:
		case 0x13:
		case 0x14:
		case 0x15:
		case 0x16:
		case 0x17:
		case 0x18:
		case 0x19:
		case 0x1a:
		case 0x1b:
		case 0x1c:
		case 0x1d:
		case 0x1e:
		case 0x1f:
		case 0x20:
			break;
		}
	}
}
#endif

void pak0f117150(s8 device, u8 *ptr)
{
	s32 i;

	g_Paks[device].unk2c4 = ptr;

	for (i = 0; i < 4096; i++) {
		g_Paks[device].unk2c4[i] = 0;
	}
}

void pak0f1171b4(s8 device, s32 arg1, s32 arg2)
{
	g_Paks[device].unk00c = arg1;
	g_Paks[device].unk2b8_06 = arg2;
}

s32 pak_get_unk008(s8 device)
{
	return g_Paks[device].unk008;
}

void pak_set_unk008(s8 device, s32 value)
{
	g_Paks[device].unk008 = value;
}

s32 pak_get_unk270(s8 device)
{
	return g_Paks[device].unk270;
}

s32 pak_get_rumble_state(s8 device)
{
	return g_Paks[device].rumblestate;
}

void pak_set_rumble_state(s8 device, s32 state)
{
	g_Paks[device].rumblestate = state;
}

s32 pak0f117350(s8 device)
{
	return g_Paks[device].unk2b8_01;
}

void pak0f117398(s8 device)
{
	g_Paks[device].unk2b8_01 = 1;
}

void pak0f1173e4(s8 device)
{
	g_Paks[device].unk2b8_01 = 0;
}

bool pak_retrieve_block_from_cache(s8 device, u32 offset, u8 *dst)
{
	u32 blocksize = pak_get_block_size(device);
	u32 stack;
	s32 i;

	if (g_Paks[device].headercachecount < MAX_HEADERCACHE_ENTRIES) {
		for (i = 0; i < g_Paks[device].headercachecount; i++) {
			if (offset / blocksize == g_Paks[device].headercache[i].blocknum) {
				memcpy(dst, g_Paks[device].headercache[i].payload, pak_get_block_size(device));
				return true;
			}
		}
	}

	return false;
}

PakErr2 pak_read_header_at_offset(s8 device, u32 offset, struct pakfileheader *header)
{
	struct pakfileheader localheader;
	struct pakfileheader *headerptr;
	u32 blocknum;
	s32 result;
	u16 checksum[2];
	u8 sp38[0x20];

	headerptr = header ? header : &localheader;

	blocknum = offset / pak_get_block_size(device);

	if (blocknum >= g_Paks[device].pdnumblocks) {
		return PAK_ERR2_BADOFFSET;
	}

	if (!pak_retrieve_header_from_cache(device, blocknum, headerptr)) {
		result = pak_read_write_block(device, PFS(device), g_Paks[device].pdnoteindex, 0, offset, sizeof(sp38), sp38);

		if (pak_handle_result(result, device, true, LINE_1058) == 0) {
			if (result == PAK_ERR1_NOPAK) {
				return PAK_ERR2_NOPAK;
			}

			return PAK_ERR2_BADOFFSET;
		}

		memcpy(headerptr, sp38, sizeof(struct pakfileheader));
		pak_calculate_checksum(&sp38[0x08], &sp38[0x10], checksum);

		if (headerptr->headersum[0] != checksum[0] || headerptr->headersum[1] != checksum[1]) {
			return PAK_ERR2_CHECKSUM;
		}

		if (!headerptr->writecompleted) {
			return PAK_ERR2_INCOMPLETE;
		}

		if ((arg_find_by_prefix(1, "-forceversion") ? 1 : 0) != headerptr->version) {
			return PAK_ERR2_VERSION;
		}

		if (g_PakDebugPakCache) {
			pak_save_header_to_cache(device, blocknum, (struct pakfileheader *) sp38);

			if (!pak_retrieve_header_from_cache(device, blocknum, headerptr)) {
#if VERSION >= VERSION_NTSC_1_0
				osSyncPrintf("Pak %d -> Header Cache 2 - FATAL ERROR\n");
#else
				osSyncPrintf("Pak %d -> Header Cache 2 - FATAL ERROR");
#endif
				return PAK_ERR2_CORRUPT;
			}
		}
	}

	if (headerptr->filelen == 0) {
		return PAK_ERR2_CORRUPT;
	}

	return PAK_ERR2_OK;
}

void pak_dump_buffer(u8 *buffer, u32 len, char *name)
{
	s32 i;
	char line[256];
	char tmp[256];

	osSyncPrintf(name);
	sprintf(line, "\n");

	for (i = 0; i != len; i++) {
		if ((i % 16) == 0) {
			osSyncPrintf(line);
			sprintf(line, "\nAddress = %u : ", i);
		}

		sprintf(tmp, "%2x ", buffer[i]);
		strcat(line, tmp);
	}

	strcat(line, "\n");

	osSyncPrintf(line);
}

void pak_dump_eeprom(void)
{
	u8 buffer[2048];

	joy_disable_cyclic_polling(JOYARGS(1098));
	osEepromLongRead(&g_PiMesgQueue, 0, buffer, 2048);
	joy_enable_cyclic_polling(JOYARGS(1100));

	pak_dump_buffer(buffer, 2048, "EEPROM DUMP");
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
s32 _pak_save_at_guid(s8 device, s32 fileid, s32 filetype, u8 *newdata, s32 *outfileid, u8 *olddataptr)
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
	oldoffset = pak_find_file(device, fileid, &header);

	if (oldoffset && (!oldoffset || oldoffset >= pak_get_pd_num_bytes(device) || ((pak_get_block_size(device) - 1) & oldoffset))) {
		return 3;
	}

	if (filetype != header.filetype) {
		return 12;
	}

	// Find all files on the pak of the same filetype,
	// then iterate them to find the swap file
	pak_get_file_ids_by_type(device, header.filetype, fileids);

	// NTSC Beta initialises swapoffset to -1 so it can detect if the loop below
	// has been entered. But in NTSC 1.0 they realised that pak_find_file can
	// return -1, so they initialised the variable to 0xeeeeeeee instead and
	// added the check for -1 in the loop below.
#if VERSION >= VERSION_NTSC_1_0
	swapoffset = 0xeeeeeeee;
#else
	swapoffset = -1;
#endif

	for (i = 0; fileids[i] != 0; i++) {
		swapoffset = pak_find_file(device, fileids[i], &swapheader);

#if VERSION >= VERSION_NTSC_1_0
		if (swapoffset == -1) {
			return 1;
		}
#endif

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
		result = pak_read_body_at_guid(device, swapfileid, olddata, -1);

		// NTSC 1.0 just writes the same thing a different way
#if VERSION >= VERSION_NTSC_1_0
		if (result == 0) {
			olddataptr = olddata;
		} else if (result == 10) {
			olddataptr = olddata;
		} else {
			olddataptr = NULL;
		}
#else
		if (result == 0 || result == 10) {
			olddataptr = olddata;
		} else {
			olddataptr = NULL;
		}
#endif
	}

	// Write the new file into the swap space
	result = pak_write_file_at_offset(device, swapoffset, filetype, newdata, 0, outfileid, olddataptr, fileid, header.generation + 1);

	if (result != 0) {
		return 4;
	}

	if (outfileid) {
		osSyncPrintf("PakSaveAtGuid: new guid = %x\n", outfileid);
	}

	// NTSC Beta skips marking the old file as vacant if the file wasn't found
	// and returns an OK value. NTSC Final makes it return an error instead.
	// @bug: The 0xeeeeeeee check should have been done earlier for swapoffset
	// instead. As it turns out, if swap space wasn't found then
	// pak_write_file_at_offset would have returned an error above and this function
	// would have returned before this check occurs. And oldoffset will never be
	// 0xeeeeeeee (even with 4GB of storage) because 0xeeeeeeee is not aligned
	// to a 16-byte boundary. So this bug is harmless.
#if VERSION >= VERSION_NTSC_1_0
	if (oldoffset == -1) {
		return 1;
	}

	if (oldoffset != 0xeeeeeeee) {
		pak_write_file_at_offset(device, oldoffset, filetype, NULL, 0, NULL, NULL, swapfileid, header.generation);
	}
#else
	if (oldoffset != -1) {
		pak_write_file_at_offset(device, oldoffset, filetype, NULL, 0, NULL, NULL, swapfileid, header.generation);
	}
#endif

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
PakErr1 pak_init_pak(OSMesgQueue *mq, OSPfs *pfs, s32 channel, s32 *arg3)
#else
PakErr1 pak_init_pak(OSMesgQueue *mq, OSPfs *pfs, s32 channel)
#endif
{
	if (pfs) {
#if VERSION >= VERSION_NTSC_1_0
		return osPfsInitPak(mq, pfs, channel, arg3);
#else
		return osPfsInitPak(mq, pfs, channel);
#endif
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	return PAK_ERR1_OK;
}

PakErr1 _pak_read_write_block(OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer)
{
	u32 newaddress;

#if VERSION >= VERSION_NTSC_1_0
	joy_poll_pfs(2);
#endif

	if (pfs) {
		return osPfsReadWriteFile(pfs, file_no, flag, address, len, buffer);
	}

	newaddress = address / 8;

	if (newaddress >= 256) {
#if VERSION < VERSION_NTSC_1_0
		u32 stack;
		crash_set_message("ILLEGAL EEPROM ADDRESS (>=256)");
		CRASH();
#endif
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	if (flag == OS_WRITE) {
		return pak_write_eeprom(newaddress, buffer, len);
	}

	if (flag == OS_READ) {
		return pak_read_eeprom(newaddress, buffer, len);
	}

	return PAK_ERR1_EEPROMINVALIDOP;
}

PakErr1 pak_query_num_notes(OSPfs *pfs, s32 *max_files, s32 *files_used)
{
	if (pfs) {
		s32 result;

		joy_disable_cyclic_polling(JOYARGS(1308));
		result = osPfsNumFiles(pfs, max_files, files_used);
		joy_enable_cyclic_polling(JOYARGS(1310));

		return result;
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	*max_files = 1;
	*files_used = 1;

	return PAK_ERR1_OK;
}

PakErr1 pak_query_num_free_bytes(OSPfs *pfs, s32 *bytes_not_used)
{
	if (pfs) {
		s32 result;

		joy_disable_cyclic_polling(JOYARGS(1337));
		result = osPfsFreeBlocks(pfs, bytes_not_used);
		joy_enable_cyclic_polling(JOYARGS(1339));

		return result;
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	*bytes_not_used = 0;

	return PAK_ERR1_OK;
}

PakErr1 pak_query_note_state(OSPfs *pfs, s32 file_no, OSPfsState *note)
{
	if (pfs) {
		s32 result;

		joy_disable_cyclic_polling(JOYARGS(1363));
		result = osPfsFileState(pfs, file_no, note);
		joy_enable_cyclic_polling(JOYARGS(1365));

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

const char var7f1b3c08[] = "Call to osPfsReSizeFile -> pfs=%x, cc=%u, gc=%u, gn=%s, en=%s, l=%d\n";

PakErr1 pak_allocate_note(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 size, s32 *file_no)
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

PakErr1 pak_delete_game_note3(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name)
{
	if (pfs) {
		return osPfsDeleteFile(pfs, company_code, game_code, game_name, ext_name);
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	return PAK_ERR1_OK;
}

PakErr1 pak_find_note(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 *file_no)
{
	if (pfs) {
		return osPfsFindFile(pfs, company_code, game_code, game_name, ext_name, file_no);
	}

	if (g_PakHasEeprom) {
#if VERSION >= VERSION_NTSC_FINAL
		*file_no = 0;
		return PAK_ERR1_OK;
#else
		struct pakfileheader header;
		u32 ret;
		u16 calcedsum[4];

		*file_no = 0;
		ret = pak_read_write_block(SAVEDEVICE_GAMEPAK, 0, 0, 0, 0, align16(0x10), (u8 *) &header);

		if (pak_handle_result(ret, SAVEDEVICE_GAMEPAK, true, LINE_1551)) {
			pak_calculate_checksum((u8 *) &header + 8, (u8 *) (&header + 1), calcedsum);

			if (header.headersum[0] == calcedsum[0] && header.headersum[1] == calcedsum[1]) {
				return PAK_ERR1_OK;
			}

			return PAK_ERR1_EEPROMINVALIDARG;
		}

		return PAK_ERR1_EEPROMINVALIDARG;
#endif
	}

	return PAK_ERR1_EEPROMMISSING;
}

PakErr1 _pak_resize_note(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, u32 numbytes)
{
	if (pfs) {
		s32 result;

		joy_disable_cyclic_polling(JOYARGS(1496));
		result = osPfsReSizeFile(pfs, company_code, game_code, game_name, ext_name, numbytes);
		joy_enable_cyclic_polling(JOYARGS(1498));

		return result;
	}

	if (!g_PakHasEeprom) {
		return PAK_ERR1_EEPROMMISSING;
	}

	return PAK_ERR1_OK;
}

const char var7f1b3c50[] = "Pak %d -> Pak_AddOneCameraFile\n";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b3c70[] = "Pak %d -> Pak_AddOneCameraFile - Making one default camera file\n";
#else
const char var7f1b3c70[] = "Pak %d -> Pak_AddOneCameraFile - Making one default camera file";
#endif

const char var7f1b3cb4[] = "Pak %d -> Pak_AddOneCameraFile : Got Space - No need for resize\n";
const char var7f1b3cf8[] = "Pak %d -> Pak_AddOneCameraFile : No Space - Need to resize by %d pages\n";
const char var7f1b3d40[] = "Pak %d -> Pak_AddOneCameraFile - Make of one default camera files failed\n";
const char var7f1b3d8c[] = "Pak %d -> Pak_AddOneCameraFile : Error - No Room\n";
const char var7f1b3dc0[] = "Pak %d -> Pak_GameNoteResetSize : New=%u\n";
const char var7f1b3dec[] = "bDoUpdate7\n";
const char var7f1b3df8[] = "Pak_SetThisGameSetupFile -> Pak=%d, File=%d, EEPROM=%d\n";

#if VERSION < VERSION_NTSC_1_0
const char var7f1adbd8nb[] = "RWI : Pak_OneNewFile - Using a snug in a bug offset\n";
#endif

s32 pak_get_pd_num_blocks(s8 device)
{
	return g_Paks[device].pdnumblocks;
}

s32 pak_get_pd_num_pages(s8 device)
{
	return g_Paks[device].pdnumpages;
}

u32 pak_get_pd_num_bytes(s8 device)
{
	return g_Paks[device].pdnumbytes;
}

s32 pak_query_num_free_pages(s8 device)
{
	s32 bytesfree;

	pak_query_num_free_bytes(PFS(device), &bytesfree);

	return bytesfree / 256;
}

s32 pak_get_num_pages_required(void)
{
	return NUM_PAGES;
}

/**
 * Determine if the pak could accommodate a new camera file,
 * considering the possibility of resizing the game note to make it larger.
 */
bool pak_can_fit_camera_file_in_pak(s8 device)
{
	if (device != SAVEDEVICE_GAMEPAK) {
		s32 pagesneeded;
		u32 bytesneeded = pak_get_max_file_size(device);

		if (pak_check_file_can_fit_in_note(device, PAKFILETYPE_CAMERA, NULL) == 0) {
			return true;
		}

		pagesneeded = bytesneeded / 256;

		if (bytesneeded & 0xff) {
			pagesneeded++;
		}

		if (g_Paks[device].pakdata.pagesused + pagesneeded < 128) {
			return (g_Paks[device].pakdata.pagesfree >= pagesneeded);
		}
	}

	return false;
}

/**
 * Determine how many camera files the pak could accommodate,
 * considering the possibility of resizing the game note to make it larger.
 */
s32 pak_get_num_free_camera_spaces_in_pak(s8 device)
{
	if (device != SAVEDEVICE_GAMEPAK) {
		s32 numspaces = 0;
		s32 pagesneeded;
		u32 bytesneeded;

		bytesneeded = pak_get_max_file_size(device);
		pak_check_file_can_fit_in_note(device, PAKFILETYPE_CAMERA, &numspaces);
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

s32 _pak_create_camera_file(s8 device, s32 *outfileid)
{
	if (device != SAVEDEVICE_GAMEPAK && pak_can_fit_camera_file_in_pak(device)) {
		s32 result;
		u32 bytesneeded = pak_get_max_file_size(device);

		if (pak_check_file_can_fit_in_note(device, PAKFILETYPE_CAMERA, NULL) != 0) {
			s32 pages = pak_get_pd_num_pages(device);
			s32 pagesneeded = bytesneeded / 256;

			if (bytesneeded & 0xff) {
				pagesneeded++;
			}

			pages += pagesneeded;

			if (!pak_resize_note(device, pages)) {
				return 4;
			}
		}

		result = pak0f118674(device, PAKFILETYPE_CAMERA, outfileid);

		if (result) {
			return result;
		}

		return 0;
	}

	return 14;
}

bool pak_resize_note(s8 device, s32 numpages)
{
	s32 stack1[2];
	s32 errno;
	struct pak *devicedata;
	s32 stack2[2];
	OSPfsState *note;
	u32 numbytes;

	pak_get_pd_num_pages(device);
	pak_query_num_free_pages(device);

	numbytes = numpages * 256;
	errno = _pak_resize_note(PFS(device), ROM_COMPANYCODE, ROM_GAMECODE, g_PakNoteGameName, g_PakNoteExtName, numbytes);
	pak_handle_result(errno, device, true, LINE_1802);

	if (errno == PAK_ERR1_OK) {
		devicedata = &g_Paks[device];
		note = &devicedata->pakdata.notes[devicedata->pdnoteindex];

		devicedata->pakdata.pagesfree -= numpages - devicedata->pdnumpages;
		devicedata->pakdata.pagesused += numpages - devicedata->pdnumpages;

		note->file_size = devicedata->pakdata.pagesused * 256;

		devicedata->pdnumbytes = numbytes;
		devicedata->pdnumblocks = devicedata->pdnumbytes / pak_get_block_size(device);
		devicedata->pdnumpages = devicedata->pdnumbytes / 256;

		return true;
	}

	return false;
}

void pak0f1184d8(s8 device, u32 *arg1, bool *arg2)
{
	if (device != SAVEDEVICE_GAMEPAK) {
		if (!(g_Paks[device].type == PAKTYPE_MEMORY && g_Paks[device].state == PAKSTATE_READY)) {
			pak0f1185e0(device, g_Paks[SAVEDEVICE_GAMEPAK].unk2bd & 0x0f, 1);
			device = SAVEDEVICE_GAMEPAK;
		}
	}

	if (g_Paks[device].unk2bd & 0x80) {
		*arg2 = true;
	} else {
		*arg2 = false;
	}

	*arg1 = g_Paks[device].unk2bd & 0x0f;
}

void pak0f1185e0(s8 device, s32 arg1, s32 arg2)
{
	if (arg2) {
		g_Paks[device].unk2bd = 0x80;
	} else {
		g_Paks[device].unk2bd = 0;
	}

	g_Paks[device].unk2bd += arg1;
}

/**
 * Find a spot for the given filetype and write it.
 *
 * Replace a blank spot or extend the filesystem if needed and possible.
 */
u32 pak0f118674(s8 device, u32 filetype, s32 *outfileid)
{
	struct pakfileheader header;
	s32 ret;
	s32 zero = 0;
	s32 filelen = pak_get_aligned_file_len_by_body_len(device, pak_get_body_len_by_type(device, filetype));
	s32 bestoffset = -1;
	u32 offset = 0;
	bool foundperfectblank = false;
#if VERSION >= VERSION_NTSC_FINAL
	bool foundblank = false;
#endif

	if (pak0f1167d8(device)) {
		return pak0f1167d8(device);
	}

	while (offset < g_Paks[device].pdnumbytes) {
		ret = pak_read_header_at_offset(device, offset, &header);

		if (ret == PAK_ERR2_OK) {
			if (header.filetype & PAKFILETYPE_TERMINATOR) {
#if VERSION >= VERSION_NTSC_1_0
				if (offset + filelen > g_Paks[device].pdnumbytes - 0x20) {
					return 14;
				}
#endif

				bestoffset = offset;
				break;
			}

			if (header.filetype & PAKFILETYPE_BLANK) {
				if (header.filelen == filelen) {
					foundperfectblank = true;
					bestoffset = offset;
					break;
				}

#if VERSION >= VERSION_NTSC_FINAL
				foundblank = true;
				bestoffset = offset;
				break;
#endif
			}

			offset += header.filelen;
		}
#if VERSION >= VERSION_NTSC_1_0
		else if (ret == PAK_ERR2_NOPAK) {
			return 1;
		}
#endif
		else {
			offset += pak_get_block_size(device);
		}
	}

	// This is optimised out, but it invalidates the the register that stores &g_Paks[device],
	// which makes it get recalculated. This is required for a match.
	if (zero) {
		device ^= 0;
		device ^= 0;
	}

	if (offset == 0 ||
			(offset && offset < pak_get_pd_num_bytes(device) && ((pak_get_block_size(device) - 1) & offset) == 0)) {
		if (bestoffset == -1) {
			return 14;
		}

		// Write the file
		if (pak_write_file_at_offset(device, bestoffset, filetype, NULL, 0, outfileid, NULL, 0, 1) == 0) {
#if VERSION >= VERSION_NTSC_FINAL
			if (foundblank) {
				u32 endoffset = bestoffset + filelen;
				pak_repair_as_blank(device, &endoffset, NULL);
				return 0;
			}

			if (foundperfectblank || foundblank) {
				return 0;
			}
#else
			if (foundperfectblank) {
				return 0;
			}
#endif

			// Write new terminator after file
			bestoffset += pak_get_aligned_file_len_by_body_len(device, pak_get_body_len_by_type(device, filetype));

			if (pak_write_file_at_offset(device, bestoffset, PAKFILETYPE_TERMINATOR, NULL, 0, NULL, NULL, 0, 1) == 0) {
				return 0;
			}

			return 4;
		}

		return 4;
	}

	g_Paks[device].state = PAKSTATE_MEM_ENTER_FULL;
	g_Paks[device].type = PAKTYPE_MEMORY;

	return 4;
}

void pak0f1189d0(void)
{
	// empty
}

void paks_init(void)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 prevvalue = g_Vars.paksneededformenu;
	s8 i;

	g_Vars.pakstocheck = 0;

	for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
		pak_set_defaults(i);
	}

	for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
#if VERSION >= VERSION_JPN_FINAL
		pak_set_features(i, PAKFEATURE_MEMORY | PAKFEATURE_RUMBLE | PAKFEATURE_GAMEBOY, 2054, "pak/pak.c");
#elif VERSION >= VERSION_PAL_BETA
		pak_set_features(i, PAKFEATURE_MEMORY | PAKFEATURE_RUMBLE | PAKFEATURE_GAMEBOY, 2049, "pak.c");
#elif VERSION >= VERSION_NTSC_FINAL
		pak_set_features(i, PAKFEATURE_MEMORY | PAKFEATURE_RUMBLE | PAKFEATURE_GAMEBOY, 2049, "pak/pak.c");
#else
		pak_set_features(i, PAKFEATURE_MEMORY | PAKFEATURE_RUMBLE | PAKFEATURE_GAMEBOY, 2016, "pak.c");
#endif
	}

	pak_probe_eeprom();
	joy_record_pfs_state(0x10);

	g_Vars.paksneededformenu = 0x10;

	pak0f1169c8(SAVEDEVICE_GAMEPAK, true);
	bossfile_load_full();

	gamefile_load_defaults(&g_GameFile);
	gamefile_apply_options(&g_GameFile);

	g_GameFileGuid.deviceserial = 0;
	g_Vars.pakstocheck = 0xf5;
	g_Vars.paksneededformenu = prevvalue;
#else
	s8 i;
	s32 j;

	for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
		pak_set_defaults(i);
	}

	g_Vars.paksneededforgame = 0x1f;

	for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
		pak_set_features(i, PAKFEATURE_MEMORY | PAKFEATURE_RUMBLE | PAKFEATURE_GAMEBOY, 1929, "pak.c");
	}

	pak_probe_eeprom();

	osSyncPrintf("Pak_Make -> Dumping details of file types found\n");

	for (j = 0; j < 9; j++) {
		s32 len = pak_get_body_len_by_type(0, 1 << j);
		pak0f1114a0nb(1 << j);

		// The use of i in pak_get_aligned_file_len_by_body_len is likely a bug,
		// but this is debug code anyway
		osSyncPrintf("Type %d -> ", 1 << j);
		osSyncPrintf(", dSize=%u, fSize=%u\n", len, pak_get_aligned_file_len_by_body_len(i, len));
	}

	osSyncPrintf("Pak_Make -> Checking for inserted pakz\n");
	pak_execute_debug_operations();

	osSyncPrintf("Pak_Make -> Loading Boss File\n");

	if (!bossfile_load_full()) {
		osSyncPrintf("Pak_Make -> Boss file load failed - Try to make a new one\n");
	}

	osSyncPrintf("Pak_Make -> Setting up default game file\n");
	gamefile_load_defaults(&g_GameFile);
	gamefile_apply_options(&g_GameFile);

	g_GameFileGuid.deviceserial = 0;
	g_Vars.paksneededforgame = 0;
#endif
}

const char var7f1b3e3c[] = "Pak %d -> Pak_Dir - ERROR : Pak Not Ready\n";
const char var7f1b3e68[] = "Pak %d -> Pak_Dir - Done - Pak_GetOffsetEOF\n";
const char var7f1b3e98[] = "Pak %d -> Pak_Dir - Done - ekPakErrorHeaderCrcCheckFail\n";
const char var7f1b3ed4[] = "Pak Return Code = ekPakOk";
const char var7f1b3ef0[] = "Pak Return Code = ekPakErrorNoPakPresent";
const char var7f1b3f1c[] = "Pak Return Code = ekPakErrorPakFatal";
const char var7f1b3f44[] = "Pak Return Code = ekPakErrorFileNotFound";
const char var7f1b3f70[] = "Pak Return Code = ekPakErrorFileSystem";
const char var7f1b3f98[] = "Pak Return Code = ekPakErrorOutOfMemory";
const char var7f1b3fc0[] = "Pak Return Code = ekPakErrorPakWaitingForInit";
const char var7f1b3ff0[] = "Pak Return Code = ekPakErrorHeaderCrcCheckFail";
const char var7f1b4020[] = "Pak Return Code = ekPakErrorDataCrcCheckFail";
const char var7f1b4050[] = "Pak Return Code = ekPakErrorDataNotValid";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b407c[] = "Pak Return Code = Unknown - %d\n";
#else
const char var7f1b407c[] = "Pak Return Code = Unknown - %d";
#endif

void pak_calculate_checksum(u8 *start, u8 *end, u16 *checksum)
{
	crc_calculate_u16_pair(start, end, checksum);
}

s32 pak0f118b04(s8 device, u32 fileid)
{
	s32 offset;
	s32 result = pak0f1167d8(device);

	if (result == 0) {
		offset = pak_find_file(device, fileid, 0);

#if VERSION >= VERSION_NTSC_1_0
		if (offset == -1) {
			return 1;
		}
#endif

		if (offset == 0 || (offset != 0 && offset < pak_get_pd_num_bytes(device) && ((pak_get_block_size(device) - 1) & offset) == 0)) {
			if (!pak_replace_file_at_offset_with_blank(device, offset)) {
				return 4;
			}
		} else {
			return 3;
		}
	} else {
		return 6;
	}

	return 0;
}

s32 _pak_read_body_at_guid(s8 device, s32 fileid, u8 *body, s32 arg3)
{
	s32 offset;
	struct pakfileheader header;
	s32 result;
	u16 checksum[2];

	if (!pak0f1167d8(device)) {
		offset = pak_find_file(device, fileid, NULL);

#if VERSION >= VERSION_NTSC_1_0
		if (offset == -1) {
			return 1;
		}
#endif

		if (offset == 0 || (offset && offset < pak_get_pd_num_bytes(device) && ((pak_get_block_size(device) - 1) & offset) == 0)) {
			result = pak0f11b86c(device, offset, body, &header, arg3);

			if (result) {
				return result;
			}

			if (arg3 == -1) {
				arg3 = 0;
			}

			if (header.occupied) {
				if (!arg3) {
					pak_calculate_checksum(body, body + header.bodylen, checksum);

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

s32 _pak_get_file_ids_by_type(s8 device, u32 filetype, u32 *fileids)
{
	struct pakfileheader header;
	u32 offset = 0;
	u32 fslen;
	s32 len = 0;
	s32 result = pak0f119298(device);

	if (result != 0) {
		return result;
	}

	result = pak_get_filesystem_length(device, &fslen);

	if (result != 0) {
		return result;
	}

	result = pak0f1167d8(device);

	if (result != 0) {
		return pak0f1167d8(device);
	}

	result = pak_read_header_at_offset(device, offset, &header);

	while (result == PAK_ERR2_OK) {
		if ((filetype & PAKFILETYPE_ALL) || (filetype & header.filetype)) {
			fileids[len] = header.fileid;
			len++;
		}

		offset += header.filelen;

		if (offset >= fslen) {
			break;
		}

		result = pak_read_header_at_offset(device, offset, &header);
	}

	fileids[len] = 0;

	if (result == PAK_ERR2_CHECKSUM) {
		return 7;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (result == PAK_ERR2_NOPAK) {
		return 1;
	}
#endif

	return 0;
}

/**
 * This function makes no sense. If it's trying to get a usage percentage then
 * it should be adding the number of blank blocks, not number of blank files.
 *
 * It's not called anyway - likely a broken debug function.
 */
s32 pak0f118eb0(s8 device, u32 *dst)
{
	struct pakfileheader header;
	f32 numblanks = 0; // This was probably supposed to be an s32
	u32 offset = 0;

	s32 ret = pak0f1167d8(device);

	if (ret != 0) {
		return ret;
	}

	while (pak_read_header_at_offset(device, offset, &header) == 0) {
		if (PAKFILETYPE_BLANK == header.filetype) {
			numblanks++;
		}

		offset += header.filelen;
	}

	*dst = 100.0f / g_Paks[device].pdnumblocks * numblanks;

	return 0;
}

s32 pak_defrag(s8 device)
{
	s32 result = pak0f1167d8(device);

	if (result != 0) {
		return result;
	}

	pak_merge_blanks(device);

	return 0;
}

/**
 * Calculate the number of times the given filetype can fit in the note.
 *
 * Return 0 if it can fit, otherwise 5.
 */
s32 pak_check_file_can_fit_in_note(s8 device, s32 filetype, s32 *numspaces)
{
	struct pakfileheader header;
	u32 filelen;
	bool hasspace;
	u32 fslen;
	u32 offset;
	u32 roomtogrow;

	filelen = pak_get_aligned_file_len_by_body_len(device, pak_get_body_len_by_type(device, filetype));

	hasspace = false;

	pak_get_filesystem_length(device, &fslen);

	if (numspaces != NULL) {
		*numspaces = 0;
	}

	for (offset = 0; pak_read_header_at_offset(device, offset, &header) == PAK_ERR2_OK && offset < fslen; offset += header.filelen) {
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

	if (!hasspace && roomtogrow >= pak_get_max_file_size(device)) {
		hasspace = true;
	}

	return (hasspace ? 0 : 5);
}

u32 pak0f119298(s8 device)
{
	if (g_Paks[device].type != PAKTYPE_MEMORY) {
		return 1;
	}

	switch (g_Paks[device].state) {
	case PAKSTATE_READY:
		return 0;
	case PAKSTATE_17:
		return 14;
	case PAKSTATE_18:
		return 4;
	case PAKSTATE_MEM_DISPATCH:
	case PAKSTATE_MEM_PRE_PREPARE:
	case PAKSTATE_MEM_PREPARE:
	case PAKSTATE_MEM_POST_PREPARE:
	case PAKSTATE_07:
		return 13;
	}

	return 1;
}

void pak0f119340(u32 arg0)
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

s32 pak_find_file(s8 device, u32 fileid, struct pakfileheader *headerptr)
{
	// NTSC 1.0 adds error checking
#if VERSION >= VERSION_NTSC_1_0
	struct pakfileheader header;
	s32 offset = 0;
	u32 fslen;
	s32 ret;

	pak_get_filesystem_length(device, &fslen);

	ret = pak_read_header_at_offset(device, offset, &header);

	while (ret == PAK_ERR2_OK && offset < fslen) {
		if (fileid == header.fileid) {
			if (headerptr) {
				memcpy(headerptr, &header, sizeof(struct pakfileheader));
			}

			return offset;
		}

		offset += header.filelen;

		ret = pak_read_header_at_offset(device, offset, &header);
	}

	if (ret == PAK_ERR2_NOPAK) {
		return -1;
	}

	return 0xffff;
#else
	struct pakfileheader header;
	u32 fslen;
	s32 offset = 0;

	pak_get_filesystem_length(device, &fslen);

	while (pak_read_header_at_offset(device, offset, &header) == PAK_ERR2_OK && offset < fslen) {
		if (fileid == header.fileid) {
			if (headerptr) {
				memcpy(headerptr, &header, sizeof(struct pakfileheader));
			}

			return offset;
		}

		offset += header.filelen;
	}

	return 0xffff;
#endif
}

#if VERSION >= VERSION_NTSC_FINAL
bool pak_write_blank_file(s8 device, u32 offset, struct pakfileheader *header)
{
	if (pak_write_file_at_offset(device, offset, PAKFILETYPE_BLANK, NULL, pak_get_body_len_by_file_len(header->filelen), NULL, NULL, 0, 1) == 0) {
		return true;
	}

	return false;
}
#endif

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
bool pak_repair_as_blank(s8 device, u32 *offsetptr, struct pakfileheader *header)
{
	struct pakfileheader iterheader;

	u32 maxfilesize = pak_get_max_file_size(device);
	u32 start = *offsetptr;
	u32 start2 = *offsetptr;
	u32 offset = *offsetptr;
	s32 result;
	u32 bodylen;

#if VERSION < VERSION_NTSC_FINAL
	osSyncPrintf("Pak %d -> Pak_RepairAsBlank : Repairing as Blank, Offset=%u, pH=%x\n", device, offset, header);
#endif

	// Skip past the header if given
	if (header != NULL) {
		offset += header->filelen;
	}

#if VERSION >= VERSION_NTSC_FINAL
	if (1);
#endif

	while (offset < g_Paks[device].pdnumbytes) {
		result = pak_read_header_at_offset(device, offset, &iterheader);

#if VERSION >= VERSION_NTSC_FINAL
		if (1);

		if (result == PAK_ERR2_OK) {
			// Found a valid header
			if ((iterheader.filetype & PAKFILETYPE_BLANK) == 0 && offset > start2) {
				break;
			}
		} else if (result == PAK_ERR2_NOPAK) {
			return false;
		}

		// No header at this offset
		offset += pak_get_block_size(device);

		// For controller paks, consider giving up
		if (device != SAVEDEVICE_GAMEPAK && offset - start > maxfilesize) {
			*offsetptr = offset;
			return false;
		}

		// If the end was reached, write a terminator at the starting offset
		if (offset >= g_Paks[device].pdnumbytes) {
			pak_write_file_at_offset(device, start, PAKFILETYPE_TERMINATOR, NULL, 0, NULL, NULL, 0, 1);
			return true;
		}
#elif VERSION >= VERSION_NTSC_1_0
		osSyncPrintf("Pak %d -> Pak_RepairAsBlank -> Summing @ offset=%u, ret=%d\n", device, offset, result);

		if (result == PAK_ERR2_OK) {
			// Found a valid header
			if (iterheader.filetype & PAKFILETYPE_BLANK) {
				// empty
			} else {
				break;
			}
		} else if (result == PAK_ERR2_NOPAK) {
			return false;
		}

		// No header at this offset
		offset += pak_get_block_size(device);

		if (offset - start > maxfilesize) {
			osSyncPrintf("Pak %d -> Pak_RepairAsBlank -> Fault Speads Over More Than One File - TERMINAL", device);
			*offsetptr = offset;
			return false;
		}
#else
		osSyncPrintf("Pak %d -> Pak_RepairAsBlank -> Summing @ offset=%u, ret=%d\n", device, offset, result);

		if (result == PAK_ERR2_OK) {
			// Found a valid header
			if (iterheader.filetype & PAKFILETYPE_BLANK) {
				// empty
			} else {
				break;
			}
		}

		// No header at this offset
		offset += pak_get_block_size(device);

		if (offset - start > maxfilesize) {
			osSyncPrintf("Pak %d -> Pak_RepairAsBlank -> Fault Speads Over More Than One File - TERMINAL", device);
			*offsetptr = offset;
			return false;
		}
#endif
	}

	bodylen = pak_get_body_len_by_file_len(offset - start);

	osSyncPrintf("Pak %d -> Pak_RepairAsBlank - St=%u, Ed=%u, Gap=%u, Blank Size=%u\n", device, start, offset, offset - start, bodylen);

	// Write the blank file ranging from to the start to the current offset
	result = pak_write_file_at_offset(device, start, PAKFILETYPE_BLANK, NULL, bodylen, NULL, NULL, 0, 1);

	if (result != 0) {
		osSyncPrintf("Pak %d -> Pak_RepairAsBlank - Fatal Error at tOffset %u\n", device, offset);
		*offsetptr = offset;
		return false;
	}

	*offsetptr = offset;
	return true;
}

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b411c[] = "Pak %d -> Pak_ValidateVersion - Start - Game File Size = %d\n";
const char var7f1b415c[] = "Pak %d -> Pak_ValidateVersion - Clearing cache 2\n";
const char var7f1b4190[] = "Pak %d -> Pak_ValidateVersion 1 - Loaded with ret=%d at offset %u\n";
const char var7f1b41d4[] = "Pak %d -> Pak_ValidateVersion 1 - Blank at %u\n";
const char var7f1b4204[] = "Pak %d -> Pak_ValidateVersion 2 - Loaded  at offset %u\n";
#endif

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
s32 pak_repair_filesystem(s8 device)
{
	s32 ret;
	bool fatal = false;
	bool foundotherversion = false;
	struct pakfileheader headers[50];
	struct pakfileheader header;
	s32 numheaders = 0;
	u32 headeroffsets[50];
	u32 offset;
#if VERSION >= VERSION_NTSC_FINAL
	s32 i;
	bool foundduplicate;
	struct serialcount serials[100];
	u32 stack[1];
#else
	bool foundduplicate;
#endif

#if VERSION >= VERSION_NTSC_1_0
	if (device);
	if (device);
	if (device);
	if (device);
	if (device);
	if (device);
#endif

	g_Paks[device].serial = (VERSION >= VERSION_NTSC_1_0 ? 0xbaba : 0);
	g_Paks[device].headercachecount = 0;

	if (pak0f1167d8(device) != 0) {
		return (VERSION >= VERSION_NTSC_1_0 ? 1 : 0);
	}

	// Iterate the headers on the pak and copy each one onto the stack.
	// As each header is read, check if a duplicate exists on the stack.
	// If a duplicate is found, blank the oldest one.
	// Stop when the end is reached, or a blank file or terminator is found.
	// If any headers are unreadable, replace them with a blank file.
	offset = 0;

	while (!fatal && offset < g_Paks[device].pdnumbytes) {
		ret = pak_read_header_at_offset(device, offset, &header);

		if (ret == PAK_ERR2_OK) {
			if (header.filetype & PAKFILETYPE_BLANK) {
#if VERSION >= VERSION_NTSC_FINAL
				break;
#else
				fatal = !pak_repair_as_blank(device, &offset, NULL);
				continue;
#endif
			}

			if (header.filetype & PAKFILETYPE_TERMINATOR) {
				break;
			}

#if VERSION >= VERSION_NTSC_1_0
			if (offset + header.filelen >= g_Paks[device].pdnumbytes)
#else
			if (false)
#endif
			{
				// File overflows the device length -> replace with terminator
				ret = pak_write_file_at_offset(device, offset, PAKFILETYPE_TERMINATOR, NULL, 0, NULL, NULL, 0, 1);

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
							fatal = pak_repair_as_blank(device, &offset, &header) == 0;
						} else {
							// The header that was just read is newer -> delete the older one
							fatal = pak_repair_as_blank(device, &headeroffsets[i], &headers[i]) == 0;
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
#if VERSION >= VERSION_NTSC_1_0
			if (ret == PAK_ERR2_NOPAK) {
				return 1;
			} else if (ret == PAK_ERR2_CHECKSUM) {
				fatal = pak_repair_as_blank(device, &offset, NULL) == false;
			} else if (ret == PAK_ERR2_INCOMPLETE) {
				if (!pak_repair_as_blank(device, &offset, &header)) {
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
#else
			if (ret == PAK_ERR2_CHECKSUM) {
				fatal = pak_repair_as_blank(device, &offset, NULL) == false;
			} else if (ret == PAK_ERR2_INCOMPLETE) {
				fatal = pak_repair_as_blank(device, &offset, &header) == false;
			} else if (ret == PAK_ERR2_VERSION) {
				foundotherversion = true;
				break;
			} else if (ret == PAK_ERR2_BADOFFSET || ret == PAK_ERR2_NOPAK || ret == PAK_ERR2_CORRUPT) {
				return 0;
			} else {
				return 0;
			}
#endif
		}

#if VERSION < VERSION_NTSC_1_0
		if (offset);
#endif
	}

	// Recheck all the headers.
	// Return 0 if the first file was a terminator (ie. pak is empty).
	// Return 1 if any header still has problems.
	offset = 0;

#if VERSION >= VERSION_NTSC_1_0
	while (!foundotherversion && !fatal && offset < g_Paks[device].pdnumbytes) {
		ret = pak_read_header_at_offset(device, offset, &header);

		if (ret == 0) { // success
			if (header.filetype & PAKFILETYPE_BLANK) {
				// empty
			} else if (offset) {
#if VERSION < VERSION_NTSC_FINAL
				if (header.deviceserial != g_Paks[device].serial) {
					if (pak_repair_as_blank(device, &offset, &header)) {
						// empty
					} else {
						fatal = true;
					}
				}

				g_Paks[device].serial = header.deviceserial;
#endif
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
			return (VERSION >= VERSION_NTSC_FINAL ? 1 : -1);
		}
	}
#else
	while (!foundotherversion && !fatal && offset < g_Paks[device].pdnumbytes) {
		ret = pak_read_header_at_offset(device, offset, &header);

		if (ret == PAK_ERR2_OK) {
			if (header.filetype & PAKFILETYPE_TERMINATOR) {
				break;
			} else if (header.filetype & PAKFILETYPE_BLANK) {
				// emtpy
			} else if (offset) {
				if (header.deviceserial);
				g_Paks[device].serial = header.deviceserial;
			} else {
				g_Paks[device].serial = header.deviceserial;

			}

			offset += header.filelen;
		} else if (ret == PAK_ERR2_VERSION) {
			foundotherversion = true;
			offset += header.filelen;
		} else {
			return 0;
		}
	}
#endif

#if VERSION >= VERSION_NTSC_FINAL
	// NTSC Final ensures serials are all the same
	if (!foundotherversion && !fatal) {
		// Build list of serials and how many times each was found.
		// There should only be one serial across all files.
		s32 numserials = 0;
		offset = 0;

		while (offset < g_Paks[device].pdnumbytes) {
			ret = pak_read_header_at_offset(device, offset, &header);

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

#if VERSION >= VERSION_PAL_BETA
				if (g_Paks[device].serial < 0x10) {
					g_Paks[device].serial = pak_generate_serial(device);
				}
#endif

				offset = 0;

				while (offset < g_Paks[device].pdnumbytes) {
					ret = pak_read_header_at_offset(device, offset, &header);

					if (ret != PAK_ERR2_OK) {
						break;
					}

					if ((header.filetype & PAKFILETYPE_BLANK) == 0) {
						if (header.filetype & PAKFILETYPE_TERMINATOR) {
							break;
						}

						if (header.deviceserial != g_Paks[device].serial) {
							pak_write_blank_file(device, offset, &header);
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
#endif

	if (fatal) {
		return (VERSION >= VERSION_NTSC_1_0 ? -1 : 0);
	}

	if (foundotherversion) {
		return (VERSION >= VERSION_NTSC_1_0 ? -1 : 0);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (device != SAVEDEVICE_GAMEPAK && g_Paks[device].serial == 0) {
		g_Paks[device].serial = pak_generate_serial(device);
		return -1;
	}
#else
	if (device != SAVEDEVICE_GAMEPAK && g_Paks[device].serial == 0) {
		g_Paks[device].serial = 0x10 + random() % 0x1ff0;
		return 0;
	}
#endif

	return (VERSION >= VERSION_NTSC_1_0 ? 0 : 1);
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * Find all game files on the game pak and write random data into them.
 * This should cause a checksum mismatch the next time the file is read.
 */
void pak_corrupt(void)
{
	struct pakfileheader header;
	u32 fileids[1025];
	s32 address;
	s32 i;
	s32 j;
	u8 payload[8];

	pak_get_file_ids_by_type(SAVEDEVICE_GAMEPAK, PAKFILETYPE_GAME, fileids);

	for (i = 0; fileids[i] != 0; i++) {
		for (j = 0; j < 8; j++) {
			payload[j] = random() & 0xff;
		}

		address = pak_find_file(SAVEDEVICE_GAMEPAK, fileids[i], &header);
		address += i * 8;
		address += 0x30;

		joy_disable_cyclic_polling();
		osEepromLongWrite(&g_PiMesgQueue, address, payload, sizeof(payload));
		joy_enable_cyclic_polling();
	}
}
#endif

/**
 * Create the initial files on a pak. Return true if all good.
 *
 * NTSC Beta forgets to include return values.
 */
#if VERSION >= VERSION_NTSC_1_0
bool pak_create_initial_files(s8 device)
#else
void pak_create_initial_files(s8 device)
#endif
{
	struct pakfileheader header;
	s32 i;
	u32 fileids[1024];
	s32 j;
	u32 stack[2];

	u32 filetypes[] = {
		PAKFILETYPE_BOSS,
		PAKFILETYPE_CAMERA,
		PAKFILETYPE_MPPLAYER,
		PAKFILETYPE_MPSETUP,
		PAKFILETYPE_GAME,
	};

	u32 filecounts[] = { 2, 3, 5, 5, 5 };

#if VERSION >= VERSION_NTSC_1_0
	char *filenames[] = { "BOS\n", "CAM\n", "MPP\n", "MPG\n", "GAM" };
#else
	char *filenames[] = { "BOS", "CAM", "MPP", "MPG", "GAM" };
#endif

	// Iterate all files on the pak and decrease the counts per filetype
	if (pak_get_file_ids_by_type(device, PAKFILETYPE_ALL, fileids) != 0) {
#if VERSION >= VERSION_NTSC_1_0
		return false;
#else
		return;
#endif
	}

	for (i = 0; fileids[i] != 0; i++) {
#if VERSION >= VERSION_NTSC_1_0
		if (pak_find_file(device, fileids[i], &header) == -1) {
			return false;
		}
#else
		pak_find_file(device, fileids[i], &header);
#endif

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
#if VERSION >= VERSION_NTSC_1_0
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
#else
	for (i = 0; i < ARRAYCOUNT(filetypes); i++) {
		// Skip creating camera files on the game pak (they are controller pak only)
		if (filecounts[i] != 0 && !(device == SAVEDEVICE_GAMEPAK && i == 1)) {
			for (j = 0; j < filecounts[i]; j++) {
				s32 ret = pak0f118674(device, filetypes[i], NULL);

				if (ret != 0) {
					pak0f119340(ret);
					return;
				}
			}
		}
	}
#endif
}

s32 pak_find_max_file_id(s8 device)
{
	struct pakfileheader header;
	u32 fileids[1025];
	s32 result;
	s32 max = 0;
	s32 i;

	result = pak_get_file_ids_by_type(device, PAKFILETYPE_ALL, fileids);

#if VERSION >= VERSION_NTSC_1_0
	if (result == 0) {
		for (i = 0; fileids[i] != 0; i++) {
			s32 offset = pak_find_file(device, fileids[i], &header);

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
#else
	for (i = 0; fileids[i] != 0; i++) {
		s32 offset = pak_find_file(device, fileids[i], &header);

		if (header.fileid > max) {
			max = header.fileid;
		}
	}

	osSyncPrintf("Pak %d -> Pak_GetCurrentSaveId - SaveID = %u\n", device, max);
#endif

	return max;
}

void pak_merge_blanks(s8 device)
{
	struct pakfileheader header;
	u32 offset = 0;
	u32 nextoffset;
	s32 mergestartoffset = 0xffff;

	while (pak_read_header_at_offset(device, offset, &header) == PAK_ERR2_OK) {
		nextoffset = offset + header.filelen;

		if (offset);

		if (PAKFILETYPE_BLANK == header.filetype) {
			if (mergestartoffset != 0xffff) {
				u32 filelen = offset - mergestartoffset + header.filelen - sizeof(struct pakfileheader);

				if (pak_write_file_at_offset(device, mergestartoffset, PAKFILETYPE_BLANK, NULL, filelen, NULL, NULL, 0, 1) != 0) {
					osSyncPrintf("> Pak_DefragPak_Level1 - Merge of two blanks failed");
				}

				nextoffset = 0;
				mergestartoffset = 0xffff;
			} else {
				mergestartoffset = offset;
			}
		} else {
			mergestartoffset = 0xffff;
		}

		offset = nextoffset;
	}
}

void paks_reset(void)
{
	// empty
}

s32 pak_get_features(s8 device)
{
	return g_Paks[device].features;
}

void pak_set_features(s8 device, u8 features, u32 line, char *file)
{
	if (g_Paks[device].features == 0) {
		g_Paks[device].features = features;

		if ((g_Paks[device].features & PAKFEATURE_MEMORY) && g_Paks[device].headercache == NULL) {
			g_Paks[device].headercachecount = 0;
			g_Paks[device].headercache = memp_alloc(align32(sizeof(struct pakheadercache) * MAX_HEADERCACHE_ENTRIES), MEMPOOL_PERMANENT);

			// This would have been used in an osSyncPrintf call.
			// Perhaps using the strings at var7f1b4318 through var7f1b43ac?
			align32(sizeof(struct pakheadercache) * MAX_HEADERCACHE_ENTRIES);
		}
	}
}

void pak_remove_all_features(s8 device, u32 arg1, u32 arg2)
{
	if (g_Paks[device].features) {
		g_Paks[device].features = 0;
	}

	if (g_Paks[device].features);
}

const char var7f1b4294[] = "Pak %d - Pak_StartOne called from line %d in %s -> Flags = %0x\n";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b42d4[] = "\nPak_StartOne -> Pak%d, Modes -\n";
#else
const char var7f1b42d4[] = "\nPak_StartOne -> Pak%d, Modes -";
#endif

const char var7f1b42f8[] = "Memory,";
const char var7f1b4300[] = "Rumble,";
const char var7f1b4308[] = "Game Boy";
const char var7f1b4314[] = "\n";
const char var7f1b4318[] = "Pak %d -> %u Bytes of scratch for cache 2 memory at %0x\n";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b4354[] = "\nPak%d -> Pak_EndOne - Called from line %d in %s : Modes -\n";
#else
const char var7f1b4354[] = "\nPak%d -> Pak_EndOne - Called from line %d in %s : Modes -";
#endif

const char var7f1b4390[] = "Memory,";
const char var7f1b4398[] = "Rumble,";
const char var7f1b43a0[] = "Game Boy";
const char var7f1b43ac[] = "\n";
const char var7f1b43b0[] = "Pak -> FATAL ERROR -> MEMORY INSTANCE ENDING IS NO LONGER SUPPORTED\n";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b43f8[] = "Pak -> Pak_MakeOne - Id=%d is finished\n";
#else
const char var7f1b43f8[] = "Pak -> Pak_MakeOne - Id=%d is finished";
#endif

void pak_set_defaults(s8 device)
{
	g_Paks[device].unk274 = 3;
	g_Paks[device].features = 0;
	g_Paks[device].type = PAKTYPE_NONE;
	g_Paks[device].unk008 = PAK008_01;
	g_Paks[device].rumblestate = RUMBLESTATE_1;
	g_Paks[device].unk00c = PAK00C_03;
	g_Paks[device].state = PAKSTATE_NOPAK;
	g_Paks[device].pdnoteindex = -1;
	g_Paks[device].unk2b8_01 = 0;
	g_Paks[device].unk2b8_05 = 0;
	g_Paks[device].isgbcamera = 0;
	g_Paks[device].unk2b8_02 = 0;
	g_Paks[device].unk2bd = 128;
	g_Paks[device].plugcount = 0;
	g_Paks[device].unk2b8_06 = 0;
#if VERSION >= VERSION_NTSC_1_0
	g_Paks[device].showdatalost = false;
#endif
	g_Paks[device].headercache = NULL;
	g_Paks[device].unk2c4 = NULL;
	g_Paks[device].maxfileid = 8;
	g_Paks[device].serial = 0;
	g_Paks[device].rumblettl = -1;
#if VERSION >= VERSION_NTSC_1_0
	g_Paks[device].unk2c8 = 0;
#endif
}

PakErr1 pak_read_write_block(s8 device, OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer)
{
	s32 result;
	len = pak_align(device, len);

	joy_disable_cyclic_polling(JOYARGS(3096));
	result = _pak_read_write_block(pfs, file_no, flag, address, len, buffer);
	joy_enable_cyclic_polling(JOYARGS(3098));

	return result;
}

bool pak_query_total_usage(s8 device)
{
	struct pak *pak = &g_Paks[device];
	s32 noteerrors[16];
	s32 bytesfree;
	s32 ret;
	s32 i;

#if VERSION >= VERSION_NTSC_1_0
	osSyncPrintf("Pak %d -> Pak_Memory_UpdateNoteInfo\n", device);
#else
	osSyncPrintf("Pak %d -> Pak_Memory_UpdateNoteInfo", device);
#endif

	if (!pak->unk2b8_02) {
		return true;
	}

	ret = pak_query_num_notes(PFS(device), &pak->notestotal, &pak->notesused);

	if (!pak_handle_result(ret, device, true, LINE_3486)) {
		pak->unk2b8_02 = false;
		return false;
	}

	ret = pak_query_num_free_bytes(PFS(device), &bytesfree);
	pak->pakdata.pagesfree = ((bytesfree + 255) & 0xffff) >> 8;

	if (!pak_handle_result(ret, device, true, LINE_3495)) {
		pak->unk2b8_02 = false;
		return false;
	}

	for (i = 0; i < ARRAYCOUNT(noteerrors); i++) {
		noteerrors[i] = pak_query_note_state(PFS(device), i, &pak->pakdata.notes[i]);

		if (noteerrors[i] != PAK_ERR1_OK) {
			pak->pakdata.notesinuse[i] = false;
		} else {
			pak->pakdata.notesinuse[i] = true;
		}
	}

	for (i = 0, pak->pakdata.pagesused = 0; i < ARRAYCOUNT(noteerrors); i++) {
		if (noteerrors[i] == PAK_ERR1_OK) {
			pak->pakdata.pagesused += (pak->pakdata.notes[i].file_size + 255) >> 8;
		}
	}

	pak->unk2b8_02 = false;

	return true;
}

void pak_query_pd_size(s8 device)
{
	u32 stack;
	OSPfsState note;
	s32 result;

	joy_disable_cyclic_polling(JOYARGS(3242));
	result = pak_query_note_state(PFS(device), g_Paks[device].pdnoteindex, &note);
	joy_enable_cyclic_polling(JOYARGS(3244));

	if (pak_handle_result(result, device, true, LINE_3599)) {
		g_Paks[device].pdnumbytes = note.file_size;
		g_Paks[device].pdnumblocks = g_Paks[device].pdnumbytes / pak_get_block_size(device);
		g_Paks[device].pdnumpages = g_Paks[device].pdnumbytes / 256;
		g_Paks[device].pdnumnotes = g_Paks[device].pdnumbytes / (256 * NUM_PAGES);
	}

	// These strings belong in this function, but the function needs to be
	// reworked to put them in their correct places
#if VERSION >= VERSION_NTSC_1_0
	osSyncPrintf("Pak %d -> Couldn't assertain the game note size\n");
	osSyncPrintf("Pak %d -> Pak_AnalyseCurrentGameNote - Game note size = %uk\n");
#else
	osSyncPrintf("Pak %d -> Couldn't assertain the game note size");
	osSyncPrintf("Pak %d -> Pak_AnalyseCurrentGameNote - Game note size = %uk");
#endif
}

#if VERSION < VERSION_NTSC_1_0
bool pak0f1147b8nb(s8 device)
{
	u32 stack;
	s32 ret;

	osSyncPrintf("Pak %d -> Pak_Memory_Init1");

	joy_disable_cyclic_polling(3272, "pak.c");
	ret = pak_init_pak(&g_PiMesgQueue, PFS(device), device);
	joy_enable_cyclic_polling(3274, "pak.c");

	if (!pak_handle_result(ret, device, true, 3276)) {
		return false;
	}

	g_Paks[device].state = PAKSTATE_MEM_DISPATCH;

	if (device == SAVEDEVICE_GAMEPAK) {
		pak_execute_debug_operations();
		pak_execute_debug_operations();
		pak_execute_debug_operations();
	}

	return true;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b44bc[] = "Pak %d -> Searching for the game file\n";
#else
const char var7f1b44bc[] = "Pak %d -> Searching for the game file";
#endif

/**
 * Prepare a controller pak for use by making sure a note is allocated and that
 * the filesystem is good, among other things.
 */
bool mempak_prepare(s8 device)
{
	u32 stack1;
	struct pak *pak;
	bool error1 = false;
#if VERSION >= VERSION_NTSC_1_0
	bool error2 = false;
#endif
#if VERSION == VERSION_NTSC_1_0
	u32 stack3;
#endif
	u32 fileids[1024];
#if VERSION >= VERSION_NTSC_1_0
	s32 serial;
#endif
	s32 sp48;
	s32 notesize;
#if VERSION >= VERSION_NTSC_1_0
	s32 maxfileid;
	u32 stack2;
#endif

	if (1);
	if (1);
	if (1);

	g_Paks[device].type = PAKTYPE_MEMORY;
	g_Paks[device].unk2b8_02 = true;

	pak_query_total_usage(device);

#if VERSION >= VERSION_NTSC_1_0
	if (g_Paks[device].state == PAKSTATE_UNPLUGGING) {
		return false;
	}
#endif

	// Find the PD note if it exists
	joy_disable_cyclic_polling(JOYARGS(3319));
	sp48 = pak_find_note(PFS(device), ROM_COMPANYCODE, ROM_GAMECODE, g_PakNoteGameName, g_PakNoteExtName, &g_Paks[device].pdnoteindex);
	joy_enable_cyclic_polling(JOYARGS(3321));

	// If it doesn't exist, allocate it
	if (sp48 != PAK_ERR1_OK) {
		pak = &g_Paks[device];

		pak_handle_result(sp48, device, false, LINE_3654);

		g_Paks[device].pdnumnotes = (pak->pakdata.pagesfree > 128) ? 2 : 1;

		notesize = g_Paks[device].pdnumnotes * (256 * NUM_PAGES);

		joy_disable_cyclic_polling(JOYARGS(3336));
		sp48 = pak_allocate_note(PFS(device), ROM_COMPANYCODE, ROM_GAMECODE, g_PakNoteGameName, g_PakNoteExtName, notesize, &g_Paks[device].pdnoteindex);
		joy_enable_cyclic_polling(JOYARGS(3338));

		g_Paks[device].unk2b8_02 = true;

		if (pak_handle_result(sp48, device, true, LINE_3668)) {
			error1 = true;
		} else {
			return false;
		}
	}

	pak_query_total_usage(device);
	pak_query_pd_size(device);

#if VERSION >= VERSION_NTSC_1_0
	g_Paks[device].showdatalost = false;
#endif

	g_Paks[device].headercachecount = 0;
	g_Paks[device].state = PAKSTATE_READY;

	if (device && device && device);

#if VERSION >= VERSION_NTSC_1_0
	// If it's a new note, create the filesystem
	if (error1) {
		serial = pak_create_filesystem(device);

		if (serial != -1) {
			g_Paks[device].serial = serial;
		} else {
			error2 = true;
		}
	}

	// Check the filesystem for errors and try to recreate it if broken
	if (!error2) {
		if (pak_repair_filesystem(device) == -1) {
			serial = pak_create_filesystem(device);

			if (serial != -1) {
				g_Paks[device].serial = serial;
			} else {
				error2 = true;
			}

			if (device != SAVEDEVICE_GAMEPAK) {
				g_Paks[device].showdatalost = true;
			}
		}
	}

	if (!error2) {
		maxfileid = pak_find_max_file_id(device);

		if (maxfileid != -1) {
			g_Paks[device].maxfileid = maxfileid;

			if (pak_get_file_ids_by_type(device, PAKFILETYPE_TERMINATOR, fileids) == 0 && pak_create_initial_files(device)) {
				g_Paks[device].state = (device == SAVEDEVICE_GAMEPAK) ? PAKSTATE_READY : PAKSTATE_MEM_POST_PREPARE;

				filelist_invalidate_pak(device);

				return true;
			}
		}
	}

	g_Paks[device].state = PAKSTATE_22;

	filelist_invalidate_pak(device);

	return false;
#else
	if (!error1) {
		if (!pak_repair_filesystem(device)) {
			error1 = true;
		}
	}

	if (arg_find_by_prefix(1, "-forcewipe")) {
		pak_wipe(device, 0, g_Paks[device].pdnumblocks);
	} else if (error1 || arg_find_by_prefix(1, "-forcescrub")) {
		g_Paks[device].serial = pak_create_filesystem(device);
	}

	g_Paks[device].maxfileid = pak_find_max_file_id(device);

	pak_get_file_ids_by_type(device, PAKFILETYPE_TERMINATOR, fileids);
	pak_create_initial_files(device);

	g_Paks[device].state = (device == SAVEDEVICE_GAMEPAK) ? PAKSTATE_READY : PAKSTATE_MEM_POST_PREPARE;

	return true;
#endif
}

#if VERSION < VERSION_NTSC_1_0
const char var7f1ae40cnb[] = "Pak %d -> Initialisation - No swap file";
const char var7f1ae434nb[] = "Pak %d -> Initialisation - Found a swap file";
#endif

bool pak_probe(s8 device)
{
	bool plugged = false;
	s32 ret;
	bool done = false;

#if VERSION >= VERSION_NTSC_1_0
	joy_disable_cyclic_polling();

	// Try memory pak
	ret = pak_init_pak(&g_PiMesgQueue, PFS(device), device, NULL);

	if (pak_handle_result(ret, device, true, LINE_3829)) {
		g_Paks[device].state = PAKSTATE_MEM_DISPATCH;

		if (device == SAVEDEVICE_GAMEPAK) {
			pak_execute_debug_operations();
			pak_execute_debug_operations();
			pak_execute_debug_operations();
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

			if (pak_handle_result(ret, device, false, LINE_3865)) {
				g_Paks[device].type = PAKTYPE_RUMBLE;
				g_Paks[device].state = PAKSTATE_READY;
				g_Paks[device].rumblestate = RUMBLESTATE_1;
				g_Paks[device].plugcount++;

				plugged = true;
				done = true;
			} else if (ret == PAK_ERR1_NOPAK) {
				plugged = false;
				done = true;
			}

			if (!done) {
				// Try game boy pak
				ret = osGbpakInit(&g_PiMesgQueue, PFS(device), device);

				if (pak_handle_result(ret, device, false, LINE_3889)) {
					if (IS4MB()) {
						g_Paks[device].type = PAKTYPE_NONE;
						g_Paks[device].state = PAKSTATE_22;
					} else {
						g_Paks[device].type = PAKTYPE_GAMEBOY;
						g_Paks[device].state = PAKSTATE_GB_PRE_PREPARE;
						g_Paks[device].unk2b8_01 = false;
						g_Paks[device].plugcount++;
					}

					plugged = true;
				} else if (ret == PAK_ERR1_NOPAK) {
					plugged = false;
				}
			}
		}
	}

	joy_enable_cyclic_polling();

	return plugged;
#else
	if (device == SAVEDEVICE_GAMEPAK) {
		return true;
	}

	joy_disable_cyclic_polling(JOYARGS(3434));

	// Try memory pak
	ret = pak_init_pak(&g_PiMesgQueue, PFS(device), device);

	if (pak_handle_result(ret, device, true, 3437)) {
		joy_enable_cyclic_polling(JOYARGS(3439));
		return true;
	}

	// Try rumble pak
	ret = osMotorProbe(&g_PiMesgQueue, PFS(device), device);

	if (pak_handle_result(ret, device, false, 3446)) {
		joy_enable_cyclic_polling(JOYARGS(3448));
		return true;
	}

	// Try game boy pak
	ret = osGbpakInit(&g_PiMesgQueue, PFS(device), device);

	if (pak_handle_result(ret, device, false, 3455)) {
		joy_enable_cyclic_polling(JOYARGS(3457));
		return true;
	}

	joy_enable_cyclic_polling(JOYARGS(3462));

	return false;
#endif
}

#if VERSION < VERSION_NTSC_1_0
void pak0f114dd4nb(s8 device)
{
	struct pak *pak = &g_Paks[device];
	s32 ret;

	pak->pdnoteindex = -1;
	pak->unk2b8_01 = false;
	pak->type = PAKTYPE_NONE;
	pak->unk008 = PAK008_01;
	pak->rumblestate = RUMBLESTATE_1;
	pak->unk00c = PAK00C_03;

	if (pak_probe(device)) {
		if (pak->features & PAKFEATURE_MEMORY) {
			if (pak0f1147b8nb(device)) {
				pak->plugcount++;
				return;
			}

			if (1);
		}

		if (pak->features & PAKFEATURE_RUMBLE) {
			if (device != SAVEDEVICE_GAMEPAK) {
				joy_disable_cyclic_polling(3514, "pak.c");
				ret = osMotorProbe(&g_PiMesgQueue, PFS(device), device);
				joy_enable_cyclic_polling(3516, "pak.c");

				if (pak_handle_result(ret, device, 1, 3518)) {
					pak->type = PAKTYPE_RUMBLE;
					pak->state = PAKSTATE_READY;
					pak->plugcount++;
					return;
				}
			} else {
				return;
			}
		}

		if (pak->features & PAKFEATURE_GAMEBOY) {
			pak->state = PAKSTATE_GB_PRE_PREPARE;
			pak->unk2b8_01 = false;
			pak->plugcount++;
		}
	}
}
#endif

/**
 * Replace data between the given blocks with '!'.
 */
void pak_wipe(s8 device, u32 blocknumstart, u32 blocknumend)
{
	u8 buffer[128];
	u32 i;

#if VERSION < VERSION_NTSC_1_0
	osSyncPrintf("Pak %d -> About to wipe blocks %d to %d of the game file with the wipe byte %d", device, blocknumstart, blocknumend, '!');
#endif

	for (i = 0; i < pak_get_block_size(device); i++) {
		buffer[i] = '!';
	}

	for (i = blocknumstart; i < blocknumend; i++) {
		s32 result = pak_read_write_block(device, PFS(device), g_Paks[device].pdnoteindex, PFS_WRITE, i * pak_get_block_size(device), pak_get_block_size(device), buffer);

		g_Paks[device].headercachecount = 0;

		if (!pak_handle_result(result, device, true, LINE_3948)) {
#if VERSION >= VERSION_NTSC_1_0
			osSyncPrintf("Pak %d -> Game file wipe failed\n", device);
#else
			osSyncPrintf("Pak %d -> Game file wipe failed", device);
#endif
			g_Paks[device].pdnoteindex = -1;
			break;
		}
	}
}

void pak_save_header_to_cache(s8 device, s32 blocknum, struct pakfileheader *header)
{
	struct pak *pak = &g_Paks[device];
	s32 count;
	s32 overview[1024];
	u32 stack[2];
	s32 j;
	s32 k;
	s32 i;
	s32 endblocknum = header->filelen / pak_get_block_size(device) + blocknum;

	for (i = 0; i < ARRAYCOUNT(overview); i++) {
		overview[i] = -1;
	}

	// Iterate existing cache items and write their indexes into the overview array,
	// where the index in the overview array is determined by the cache item's blocknum.
	for (i = 0; i < pak->headercachecount; i++) {
		struct pakfileheader *tmp = (struct pakfileheader *) pak->headercache[i].payload;

		for (j = 0; j < tmp->filelen / pak_get_block_size(device); j++) {
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
	memcpy(pak->headercache[pak->headercachecount].payload, header, pak_get_block_size(device));

	pak->headercachecount++;

	// Close any gaps in the cache list and recount for good measure
	count = 0;

	for (i = 0; i < pak->headercachecount; i++) {
		if (pak->headercache[i].blocknum != -1) {
			pak->headercache[count].blocknum = pak->headercache[i].blocknum;
			memcpy(&pak->headercache[count].payload, &pak->headercache[i].payload, pak_get_block_size(device));
			count++;
		}
	}

	pak->headercachecount = count;
}

bool pak_retrieve_header_from_cache(s8 device, s32 blocknum, struct pakfileheader *dst)
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
s32 pak_create_filesystem(s8 device)
{
	u8 data[32];
	s32 address;
	s32 result;
	s32 i;

	for (i = 0; i < 32; i++) {
		data[i] = random() & 0xff;
	}

	address = pak_get_aligned_file_len_by_body_len(device, pak_get_body_len_by_type(device, PAKFILETYPE_TERMINATOR));

	g_Paks[device].maxfileid = 0x10;
#if VERSION >= VERSION_NTSC_1_0
	g_Paks[device].serial = pak_generate_serial(device);
#else
	g_Paks[device].serial = 0x10 + random() % 0x1ff0;
#endif
	g_Paks[device].headercachecount = 0;

	pak_write_file_at_offset(device, 0, PAKFILETYPE_TERMINATOR, NULL, 0, NULL, NULL, 0, 1);

	result = pak_read_write_block(device, PFS(device), g_Paks[device].pdnoteindex, PFS_WRITE, address, pak_get_block_size(device), data);

#if VERSION >= VERSION_NTSC_1_0
	if (pak_handle_result(result, device, true, LINE_4140) == 0) {
		return -1;
	}
#else
	pak_handle_result(result, device, true, LINE_4140);
#endif

	return g_Paks[device].serial;
}

s32 pak0f11b6ec(s8 device)
{
	if (g_Paks[device].state == PAKSTATE_READY && g_Paks[device].type == PAKTYPE_MEMORY) {
		return 3;
	}

	return 0;
}

bool pak_get_filesystem_length(s8 device, u32 *outlen)
{
	struct pakfileheader header;
	s32 offset = 0;
	u32 stack[2];

	while (offset < g_Paks[device].pdnumbytes) {
		s32 ret = pak_read_header_at_offset(device, offset, &header);
		offset += header.filelen;

#if VERSION >= VERSION_NTSC_1_0
		if (ret == PAK_ERR2_NOPAK) {
			return true;
		}
#endif

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

const char var7f1b4508[] = "RWI : Warning : tOffset > gPakObj[PakNum].GameFileSize\n";

/**
 * Read a file from cache or from the pak and write it to *data.
 */
s32 pak0f11b86c(s8 device, u32 offset, u8 *data, struct pakfileheader *header, s32 bodylen)
{
	struct pakfileheader headerstack;
	s32 s0;
#if VERSION >= VERSION_NTSC_1_0
	s32 negativebodylen2;
#endif
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

#if VERSION >= VERSION_NTSC_1_0
	if (bodylen == -1) {
		negativebodylen = true;
		negativebodylen2 = true;
		bodylen = 0;
	} else {
		negativebodylen = false;
		negativebodylen2 = false;
	}
#else
	if (bodylen == -1) {
		negativebodylen = true;
		bodylen = 0;
	} else {
		negativebodylen = false;
	}
#endif

	blocksize = pak_get_block_size(device);
	isoneblock = bodylen && data && (bool)(bodylen + sizeof(struct pakfileheader) <= blocksize);

	if (header == NULL) {
		header = &headerstack;
	}

	ret = pak_read_header_at_offset(device, offset, header);

	if (ret != 0) {
		return ret;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (!negativebodylen2 && !header->occupied) {
		return 10;
	}
#else
	if (!header->occupied) {
		return 10;
	}
#endif

	if (isoneblock) {
		if (pak_retrieve_block_from_cache(device, offset, buffer)) {
			for (i = 0; i < bodylen; i++) {
				data[i] = buffer[sizeof(struct pakfileheader) + i];
			}

			return 0;
		}
	}

	if (bodylen == header->bodylen) {
		bodylen = 0;
	}

	alignedfilelen = pak_get_aligned_file_len_by_body_len(device, header->bodylen);

	filelen = (bodylen == 0 ? header->bodylen : bodylen) + sizeof(struct pakfileheader);

	if (negativebodylen) {
		filelen = alignedfilelen;
	}

	joy_disable_cyclic_polling(JOYARGS(4008));

	for (i = 0; i != filelen; i++) {
		offsetinblock = i % pak_get_block_size(device);
		blocknum = i / pak_get_block_size(device);

		if (offsetinblock == 0) {
			s32 absoluteoffset = pak_get_block_size(device) * blocknum + offset;
			s32 ret;

			ret = pak_read_write_block(device, PFS(device), g_Paks[device].pdnoteindex, OS_READ, absoluteoffset, pak_get_block_size(device), sp58);

			if (!pak_handle_result(ret, device, true, LINE_4394)) {
				joy_enable_cyclic_polling(JOYARGS(4032));

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

	joy_enable_cyclic_polling(JOYARGS(4054));

	return 0;
}

const char var7f1b4540[] = "Pak %d -> Pak_DeleteFile_Offset - DataSize = %u\n";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b4574[] = "Pak %d -> Delete file offset (file id %d) failed\n";
const char var7f1b45a8[] = "Pak %d -> Delete file offset failed - Bad Offset passed\n";
#else
const char var7f1b4574[] = "Pak %d -> Delete file offset (file id %d) failed";
const char var7f1b45a8[] = "Pak %d -> Delete file offset failed - Bad Offset passed";
#endif

bool pak_replace_file_at_offset_with_blank(s8 device, u32 offset)
{
	struct pakfileheader header;
	s32 result;

	result = pak_read_header_at_offset(device, offset, &header);

	if (result == PAK_ERR2_OK) {
		result = pak_write_file_at_offset(device, offset, PAKFILETYPE_BLANK, NULL, header.filelen - sizeof(struct pakfileheader), NULL, NULL, 0, 1);

		if (result == 0) {
			return true;
		}
	}

	return false;
}

s32 pak_write_file_at_offset(s8 device, u32 offset, u32 filetype, u8 *newdata, s32 bodylenarg, s32 *outfileid, u8 *olddata, u32 fileid, u32 generation)
{
	struct pakfileheader localheader;
	struct pakfileheader *headerptr = &localheader;
	u32 blocksize;
	s32 filelen;
	s32 bodylen;
	s32 paddinglen;
	u8 newfilebytes[4096];
	u8 oldfilebytes[4096];
	u32 numblocks;
	s32 i;
	s32 j;
	s32 k;
	s32 result;
	struct pakfileheader *newheader;
	struct pakfileheader *oldheader;
	u8 *oldfileu8ptr;
	u8 *newfileu8ptr;
	u8 *headeru8ptr;
	s32 stack;

	blocksize = pak_get_block_size(device);

	generation &= 0x1ff;
	bodylen = bodylenarg ? bodylenarg : pak_get_body_len_by_type(device, filetype);
	filelen = pak_get_aligned_file_len_by_body_len(device, bodylen);

#if VERSION < VERSION_NTSC_1_0
	if (headerptr->fileid);
#endif

	// Build the header bytes on the stack
	headerptr->fileid = fileid ? fileid : ++g_Paks[device].maxfileid;
	headerptr->deviceserial = g_Paks[device].serial;
	headerptr->filelen = filelen;
	headerptr->version = (s32) (arg_find_by_prefix(1, "-forceversion") ? 1 : 0);
	headerptr->bodylen = bodylen;
	headerptr->generation = generation;
	headerptr->filetype = filetype;
	headerptr->fileid &= 0x7f;

	if (outfileid != NULL) {
		*outfileid = headerptr->fileid;
	}

	headerptr->occupied = newdata ? 1 : 0;

	if (headerptr->occupied) {
		pak_calculate_checksum(newdata, newdata + headerptr->bodylen, headerptr->bodysum);
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
	headeru8ptr = (u8 *) &localheader;
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

	joy_disable_cyclic_polling(JOYARGS(4292));

	// Write the header with writecompleted = 0, followed by the data, then
	// rewrite the header with writecompleted = 1. This allows the game to
	// detect if data on the pak was only partially written.
	for (j = 0; j < 2; j++) {
		newheader->writecompleted = j ? 1 : 0;

		// Checksum the header part after the checksums themselves
		pak_calculate_checksum((u8 *) (newheader->bodysum + 2), (u8 *) (newheader + 1), newheader->headersum);

		for (i = 0; i != numblocks; i++) {
			s32 offsetinfile = pak_get_block_size(device) * i;
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
				result = pak_read_write_block(device, PFS(device), g_Paks[device].pdnoteindex, OS_WRITE, offset + i * blocksize, pak_get_block_size(device), &newfilebytes[offsetinfile]);

				if (!pak_handle_result(result, device, true, LINE_4742)) {
					joy_enable_cyclic_polling(JOYARGS(4380));

					if (result == PAK_ERR1_NOPAK) {
						return 1;
					}

					return 4;
				}
			}
		}
	}

	joy_enable_cyclic_polling(JOYARGS(4393));

	if (g_PakDebugPakCache) {
		pak_save_header_to_cache(device, offset / pak_get_block_size(device), newheader);
	}

	return 0;
}

bool pak_repair(s8 device)
{
	s32 result;

	switch (g_Paks[device].state) {
	case PAKSTATE_MEM_ENTER_DEVICEERROR:
	case PAKSTATE_MEM_DEVICEERROR:
		break;
	default:
		joy_disable_cyclic_polling(JOYARGS(4425));
		result = osPfsChecker(PFS(device));
		joy_enable_cyclic_polling(JOYARGS(4427));

		if (result == PAK_ERR1_OK) {
			g_Paks[device].state = PAKSTATE_PROBE;
			return true;
		}

		pak_handle_result(result, device, false, LINE_4801);

#if VERSION >= VERSION_NTSC_1_0
		g_Paks[device].state = PAKSTATE_22;
#endif
		break;
	}

#if VERSION < VERSION_NTSC_1_0
	g_Paks[device].state = PAKSTATE_22;
#endif

	return false;
}

const char var7f1b45f4[] = "PakMac_PaksLive()=%x\n";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b460c[] = "paksNeedToBeLive4Game=%x\n";
const char var7f1b4628[] = "paksNeedToBeLive4Menu=%x\n";
#endif

const char var7f1b4644[] = "g_LastPackPattern=%x\n";

bool pak_handle_result(s32 err1, s8 device, bool arg2, u32 line)
{
	if (err1 == PAK_ERR1_OK) {
		return true;
	}

	if (arg2) {
		switch (err1) {
#if VERSION >= VERSION_NTSC_1_0
		case PAK_ERR1_NOPAK:
			g_Paks[device].type = PAKTYPE_MEMORY;
			g_Paks[device].state = PAKSTATE_UNPLUGGING;
			break;
#endif
		case PAK_ERR1_DEVICE:
			g_Paks[device].type = PAKTYPE_MEMORY;
			g_Paks[device].state = PAKSTATE_MEM_ENTER_DEVICEERROR;
			break;
		case PAK_ERR1_INCONSISTENT:
		case PAK_ERR1_IDFATAL:
			g_Paks[device].type = PAKTYPE_MEMORY;
			g_Paks[device].state = PAKSTATE_MEM_ENTER_CORRUPT;
			break;
		case PAK_ERR1_DATAFULL:
		case PAK_ERR1_DIRFULL:
			g_Paks[device].type = PAKTYPE_MEMORY;
			g_Paks[device].state = PAKSTATE_MEM_ENTER_FULL;
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

#if VERSION >= VERSION_NTSC_1_0
void paks_tick(void)
{
	s32 i;

	if (g_Vars.pakstocheck) {
		g_MpPlayerNum = 0;

		menu_set_banner(MENUBANNER_CHECKINGPAK, true);

		var80075d14 = false;

		if (g_Vars.pakstocheck & 0x0f) {
			joy_set_pfs_poll_enabled(0);

			// Waiting for some timer
			if ((g_Vars.pakstocheck & 0x0f) >= 10) {
				if ((g_Vars.lvframenum % 7) == 0) {
					g_Vars.pakstocheck--;
				}
			} else {
				g_Vars.pakstocheck--;
			}
		} else {
			joy_poll_pfs(2);

			for (i = 0; i < 4; i++) {
				if (g_Vars.pakstocheck & (1 << (i + 4))) {
					pak0f1169c8(i, true);
					g_Vars.pakstocheck &= ~(1 << (i + 4));
				} else if (g_Vars.pakstocheck & (1 << (i + 8))) {
					pak0f1169c8(i, false);
					g_Vars.pakstocheck &= ~(1 << (i + 8));
				}
			}

			if (!joy_is_pfs_poll_enabled()) {
				joy_set_pfs_poll_enabled(true);
				joy_set_default_pfs_poll_interval();
			}

			menu_set_banner(-1, true);

			var80075d14 = true;
		}
	}
}
#endif

#if VERSION >= VERSION_NTSC_1_0
void pak0f11c6d0(void)
{
	s32 i;

	for (i = 0; i < MAX_PLAYERS; i++) {
		switch (g_Paks[i].state) {
		case PAKSTATE_PROBE:
		case PAKSTATE_MEM_DISPATCH:
		case PAKSTATE_MEM_PRE_PREPARE:
		case PAKSTATE_MEM_PREPARE:
		case PAKSTATE_MEM_POST_PREPARE:
			g_Paks[i].state = PAKSTATE_UNPLUGGING;
			g_PaksPlugged &= ~(1 << i);
			g_MpPlayerNum = i;
			menu_set_banner(-1, true);
			break;
		}
	}

	g_JoyPfsPollMasterEnabled = true;
}
#endif

void pak_execute_debug_operations(void)
{
#if VERSION >= VERSION_NTSC_1_0
	static u32 g_PakDebugDumpEeprom = 0;
	bool disablepolling = false;
	s8 i;

	main_override_variable("forcescrub", &g_PakDebugForceScrub);
	main_override_variable("pakdump", &g_PakDebugPakDump);
	main_override_variable("pakcache", &g_PakDebugPakCache);
	main_override_variable("pakinit", &g_PakDebugPakInit);
	main_override_variable("corruptme", &g_PakDebugCorruptMe);
	main_override_variable("wipeeeprom", &g_PakDebugWipeEeprom);
	main_override_variable("dumpeeprom", &g_PakDebugDumpEeprom);

	if (g_PakDebugCorruptMe) {
		g_PakDebugCorruptMe = false;
		pak_corrupt();
	}

	if (g_PakDebugPakDump) {
		pak_dump_pak();
		g_PakDebugPakDump = false;
	}

	if (g_PakDebugDumpEeprom) {
		g_PakDebugDumpEeprom = false;
		pak_dump_eeprom();
	}

	if (g_PakDebugWipeEeprom) {
		pak_wipe(SAVEDEVICE_GAMEPAK, 0, 0x80);
		g_PakDebugWipeEeprom = false;
	}

	if (g_PakDebugPakInit) {
		s32 device = g_PakDebugPakInit - 1;

		joy_disable_cyclic_polling();
		pak_init_pak(&g_PiMesgQueue, PFS(device), device, 0);
		joy_enable_cyclic_polling();

		g_PakDebugPakInit = false;
	}

	if (g_PakDebugForceScrub) {
		pak_create_filesystem(SAVEDEVICE_GAMEPAK);
		g_PakDebugForceScrub = false;
	}

	pak_check_plugged();

	for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
		if (g_Paks[i].features) {
			pak_tick_state(i);
		}
	}

	for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
		switch (g_Paks[i].state) {
		case PAKSTATE_PROBE:
		case PAKSTATE_MEM_DISPATCH:
		case PAKSTATE_MEM_PRE_PREPARE:
		case PAKSTATE_MEM_PREPARE:
		case PAKSTATE_MEM_POST_PREPARE:
			disablepolling = true;
			break;
		}
	}

	if (disablepolling) {
		g_JoyPfsPollMasterEnabled = false;
	} else {
		g_JoyPfsPollMasterEnabled = true;
	}
#else
	static u32 g_PakDebugDumpEeprom = 0;
	s8 i;

	osSyncPrintf("lvGetPause    = %s", lv_is_paused() ? "TRUE" : "FALSE");
	osSyncPrintf("MP_GetPause   = %s", mp_is_paused() ? "TRUE" : "FALSE");
	osSyncPrintf("getnumplayers = %d", PLAYERCOUNT());

	main_override_variable("forcecrc", &g_PakDebugForceCrc);
	main_override_variable("forcescrub", &g_PakDebugForceScrub);
	main_override_variable("dumph", &g_PakDebugPakDump);
	main_override_variable("pakcache", &g_PakDebugPakCache);
	main_override_variable("pakinit", &g_PakDebugPakInit);
	main_override_variable("dumpeeprom", &g_PakDebugDumpEeprom);

	if (g_PakDebugDumpEeprom) {
		g_PakDebugDumpEeprom = false;
		pak_dump_eeprom();
	}

	if (g_PakDebugPakInit) {
		s32 device = g_PakDebugPakInit - 1;

		joy_disable_cyclic_polling(4558, "pak.c");
		pak_init_pak(&g_PiMesgQueue, PFS(device), device);
		joy_enable_cyclic_polling(4560, "pak.c");

		g_PakDebugPakInit = false;
	}

	if (g_PakDebugForceCrc) {
		pak_wipe(SAVEDEVICE_GAMEPAK, 0x4d, 0x4e);
		g_PakDebugForceCrc = false;
	}

	if (g_PakDebugForceScrub) {
		pak_create_filesystem(SAVEDEVICE_GAMEPAK);
		g_PakDebugForceScrub = false;
	}

	pak_check_plugged();
	pak_dump_pak();

	for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
		if (g_Paks[i].features) {
			pak_tick_state(i);
		}
	}
#endif
}

const char var7f1b46a8[] = "\nOS_GBPAK_GBCART_ON       - ";
const char var7f1b46c8[] = "\nOS_GBPAK_GBCART_PULL     - ";
const char var7f1b46e8[] = "\nOS_GBPAK_POWER           - ";
const char var7f1b4708[] = "\nOS_GBPAK_RSTB_DETECTION  - ";
const char var7f1b4728[] = "Pak -> Dumping contents of Game Boy Pack(TM) Id file";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b4760[] = "(u16) - Fixed1             - %d\n";
const char var7f1b4784[] = "(u16) - StartAddress       - %d\n";
const char var7f1b47a8[] = "(u8*) - Nintendo chr data  - %s\n";
const char var7f1b47cc[] = "(u8*) - Game Title         - %s\n";
const char var7f1b47f0[] = "(u16) - Company Code       - %d\n";
const char var7f1b4814[] = "(u8 ) - Body Code          - %d\n";
const char var7f1b4838[] = "(u8 ) - Rom Size           - %d\n";
const char var7f1b485c[] = "(u8 ) - Ram Size           - %d\n";
const char var7f1b4880[] = "(u8 ) - country_code       - %d\n";
const char var7f1b48a4[] = "(u8 ) - Fixed 2 (0x33)     - %d\n";
const char var7f1b48c8[] = "(u8 ) - Version Number     - %d\n";
const char var7f1b48ec[] = "(u8 ) - isum               - %d\n";
const char var7f1b4910[] = "(u16) - sum                - %d\n";
#else
const char var7f1b4760[] = "(u16) - Fixed1             - %d";
const char var7f1b4784[] = "(u16) - StartAddress       - %d";
const char var7f1b47a8[] = "(u8*) - Nintendo chr data  - %s";
const char var7f1b47cc[] = "(u8*) - Game Title         - %s";
const char var7f1b47f0[] = "(u16) - Company Code       - %d";
const char var7f1b4814[] = "(u8 ) - Body Code          - %d";
const char var7f1b4838[] = "(u8 ) - Rom Size           - %d";
const char var7f1b485c[] = "(u8 ) - Ram Size           - %d";
const char var7f1b4880[] = "(u8 ) - country_code       - %d";
const char var7f1b48a4[] = "(u8 ) - Fixed 2 (0x33)     - %d";
const char var7f1b48c8[] = "(u8 ) - Version Number     - %d";
const char var7f1b48ec[] = "(u8 ) - isum               - %d";
const char var7f1b4910[] = "(u16) - sum                - %d";
#endif

const char var7f1b4934[] = "Pak -> Finished Dump";

#if VERSION < VERSION_NTSC_1_0
const char var7f1ae980nb[] = "Pak -> Game Boy Pack reset was sucessful\n";
const char var7f1ae9acnb[] = "Pak -> Connector Check Failed";
const char var7f1ae9ccnb[] = "Pak -> osGbpakReadId - Failed";
#endif

void pak_check_plugged(void)
{
#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.tickmode != TICKMODE_CUTSCENE || g_MenuData.count > 0) {
		u8 oldplugged = g_PaksPlugged;
		u8 newplugged = g_PaksPlugged;
		u8 paksconnected = 0xff;
		s32 i;

		if ((g_Vars.pakstocheck & 0xf) == 0) {
			for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
				if ((g_Vars.paksneededforgame | g_Vars.paksneededformenu) & (1 << i)) {
					if (paksconnected == 0xff) {
						paksconnected = joy_shift_pfs_states();
					}

					if (((paksconnected & (1 << i)) != (oldplugged & (1 << i)))) {
						if ((paksconnected & (1 << i))) {
							// pak connected
							g_Paks[i].state = PAKSTATE_PROBE;
							newplugged |= (1 << i);
						} else {
							// pak unplugged
							g_Paks[i].state = PAKSTATE_UNPLUGGING;
							newplugged &= ~(1 << i);
							filelist_invalidate_pak(i);
						}
					}
				}
			}

			g_PaksPlugged = newplugged;
		}
	}
#else
	if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
		u32 paksconnected = joy_shift_pfs_states();
		u8 oldplugged = g_PaksPlugged;
		u8 newplugged = g_PaksPlugged;
		s32 i;

		for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
			u32 thisbit = 1 << i;

			if ((g_Vars.paksneededforgame | g_Vars.paksneededformenu) & thisbit) {
				if ((paksconnected & thisbit) != (oldplugged & thisbit)) {
					if (paksconnected & thisbit) {
						// pak connected
						g_Paks[i].state = PAKSTATE_PROBE;
						newplugged |= thisbit;
					} else {
						// pak unplugged
						g_Paks[i].state = PAKSTATE_UNPLUGGING;
						newplugged &= ~thisbit;
					}
				}
			}
		}

		g_PaksPlugged = newplugged;
	}
#endif
}

void gbpak_handle_error(u32 err)
{
#if VERSION >= VERSION_NTSC_1_0
	switch (err) {
		case PFS_ERR_NOPACK:
		case PFS_ERR_NEW_PACK:
		case PFS_ERR_INCONSISTENT:
		case PFS_ERR_CONTRFAIL:
		case PFS_ERR_INVALID:
		case PFS_ERR_BAD_DATA:
		case PFS_DATA_FULL:
		case PFS_DIR_FULL:
		case PFS_ERR_EXIST:
		case PFS_ERR_ID_FATAL:
		case PFS_ERR_DEVICE:
		case PFS_ERR_NO_GBCART:
		case PFS_ERR_NEW_GBCART:
			break;
	}
#endif
}

#if VERSION >= VERSION_NTSC_1_0
void pak0f11cbc8(void)
{
	// empty
}

void pak0f11cbd0(void)
{
	// empty
}
#endif

#if VERSION < VERSION_NTSC_1_0
void pak0f116758nb(u32 arg0)
{
	// empty
}

void pak0f116760nb(OSGbpakId *id)
{
	// empty
}
#endif

#if VERSION < VERSION_NTSC_1_0
bool pak0f116768nb(s8 device)
{
	OSGbpakId id;
	s32 ret;
	u8 status;

	ret = osGbpakReadId(PFS(device), &id, &status);

	if (ret == PAK_ERR1_OK) {
		pak0f116758nb(status);
		pak0f116760nb(&id);

		ret = osGbpakCheckConnector(PFS(device), &status);

		if (ret == PAK_ERR1_OK) {
			return true;
		}

		gbpak_handle_error(ret);
		return false;
	}

	gbpak_handle_error(ret);
	return false;
}
#endif

bool gbpak_read(s8 device, u16 address, u8 *buffer, u16 size)
{
	s32 result = osGbpakReadWrite(PFS(device), OS_READ, address, buffer, size);

	if (result) {
		gbpak_handle_error(result);
		return false;
	}

	return true;
}

bool gbpak_write(s8 device, u16 address, u8 *buffer, u16 size)
{
	s32 result = osGbpakReadWrite(PFS(device), OS_WRITE, address, buffer, size);

	if (result) {
		gbpak_handle_error(result);
		return false;
	}

	return true;
}

/**
 * Note: ntsc-beta needs the tmp variable to get the instruction ordering
 * correct, but there is not enough room in the stack to do this. So for
 * matching purposes, the buffer is being reduced to make room for tmp.
 * buffer is actually 32 though.
 */
bool pak0f11cd00(s8 device, u16 arg1, char *arg2, s32 arg3, s32 arg4)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 buffer[32];
	bool result = false;
	s32 i;

	for (i = 0; i < 32; i++) {
		buffer[i] = '\n';
	}

	gbpak_write(device, 0, buffer, sizeof(buffer));
#else
	bool result = false;
	s32 i;
	s32 tmp;
	u8 buffer[28];
#endif

	if (arg4 >= 0) {
#if VERSION >= VERSION_NTSC_1_0
		for (i = 0; i < 32; i++) {
			buffer[i] = (s32)(arg1 + 0xffff6000) / 0x2000;
		}
#else
		tmp = (s32)(arg1 + 0xffff6000) / 0x2000;

		for (i = 0; i < 32; i++) {
			buffer[i] = tmp;
		}
#endif

		if (gbpak_write(device, 0x4000, buffer, 32)) {
			result = true;
		}
	} else {
		result = true;
	}

	if (result && gbpak_write(device, arg1, arg2, arg3)) {
		result = true;
	}

	return result;
}

bool pak0f11ce00(s8 device, u16 arg1, char *arg2, s32 arg3, bool arg4)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 buffer[32];
	bool result = false;
	s32 i;

	for (i = 0; i < 32; i++) {
		buffer[i] = 0;
	}

	gbpak_write(device, 0, buffer, sizeof(buffer));
#else
	bool result = false;
	s32 i;
	u8 buffer[32];
#endif

	if (arg4) {
		for (i = 0; i < 32; i++) {
			buffer[i] = 0;
		}

		buffer[31] = (s32)(arg1 + 0xffff6000) / 0x2000;

		if (gbpak_write(device, 0x4000, buffer, sizeof(buffer))) {
			result = true;
		}
	} else {
		result = true;
	}

	if (result && gbpak_read(device, arg1, arg2, arg3)) {
		result = true;
	}

	return result;
}

bool gbpak0f11cef8(s8 device)
{
	struct pak *pak = &g_Paks[device];
	u8 spac[32];
	u8 sp8c[32];
	u8 sp6c[32];
	u8 sp2c[64];
	s32 i;

	if (pak->type == PAKTYPE_GAMEBOY) {
		for (i = 0; i < (s32)sizeof(spac); i++) {
			spac[i] = 2;
		}

		if (!gbpak_write(device, 0x4000, spac, sizeof(spac))) {
			return false;
		}

		if (!gbpak_read(device, 0xafe0, sp8c, sizeof(sp8c))) {
			return false;
		}

		for (i = 0; i < (s32)sizeof(spac); i++) {
			spac[i] = 8;
		}

		if (!gbpak_write(device, 0x4000, spac, sizeof(spac))) {
			return false;
		}

		if (!gbpak_read(device, 0xbfe0, sp6c, sizeof(sp6c))) {
			return false;
		}

		for (i = 0; i < (s32)sizeof(spac); i++) {
			spac[i] = 16;
		}

		if (!gbpak_write(device, 0x4000, spac, sizeof(spac))) {
			return false;
		}

		for (i = 0; i < sizeof(sp2c); i++) {
			sp2c[i] = 0;
		}

		pak->unk2ba = sp8c[26];
		pak->unk2bb = sp6c[26];
		pak->unk2b9 = (pak->unk2ba == pak->unk2bb ? pak->unk2ba : pak->unk2bb);

		if (pak->unk2b9);

		pak0f11d118(sp2c, pak->unk2b9, phead_get_unk3b8());
		pak0f11d174(device, sp2c);

		sp2c[0] |= 1;

		if (!gbpak_write(device, 0xa000, sp2c, sizeof(sp2c))) {
			return false;
		}
	}

	pak->unk008 = PAK008_01;

	return true;
}

#if VERSION >= VERSION_NTSC_1_0
void pak0f11d110(void)
{
	// empty
}
#endif

#if VERSION < VERSION_NTSC_1_0
u32 pak0f116d1cnb(s8 device)
{
	u8 readbuffer[0x40];
	u8 writebuffer[0x20];
	s32 i;

	for (i = 0; i < sizeof(writebuffer); i++) {
		writebuffer[i] = 0x10;
	}

	if (gbpak_write(device, 0x4000, writebuffer, sizeof(writebuffer)) == 0) {
		return 0;
	}

	if (gbpak_read(device, 0xa000, readbuffer, sizeof(readbuffer)) == 0) {
		return 0;
	}

	return readbuffer[0] & 1;
}
#endif

void pak0f11d118(u8 *arg0, u8 arg1, u32 arg2)
{
	arg0[0] = 2;
	arg0[1] = 0xe4;
	arg0[2] = 0x10;
	arg0[3] = 0;
	arg0[4] = arg1 & 7;
	arg0[5] = (arg1 & 0x3f) + 0x80;

	pak0f11d214(&arg0[6], arg2);
}

void pak0f11d174(s8 device, u8 *arg1)
{
	u8 tmp1;
	s32 tmp2;

	pak0f11d118(arg1, g_Paks[device].unk2b9, phead_get_unk3b8());

	tmp1 = editor_get_unk060(device);
	tmp2 = editor_get_unk05c(device);

	arg1[1] = (arg1[1] & 0xe0) + tmp1;
	arg1[2] = (tmp2 >> 8) & 0xff;
	arg1[3] = tmp2;
}

void pak0f11d214(u8 *arg0, u32 arg1)
{
	const f32 spa8[][4] = {
		{ 128, 148, 220, 255 },
		{ 130, 149, 210, 255 },
		{ 132, 150, 202, 255 },
		{ 134, 150, 196, 255 },
		{ 136, 151, 190, 255 },
		{ 138, 151, 184, 255 },
		{ 139, 152, 178, 245 },
		{ 140, 152, 172, 235 },
		{ 141, 152, 170, 221 },
		{ 142, 152, 168, 208 },
		{ 143, 152, 166, 196 },
		{ 144, 152, 164, 186 },
		{ 146, 152, 161, 177 },
		{ 148, 152, 157, 168 },
		{ 150, 152, 153, 160 },
		{ 152, 152, 152, 152 },
		{ 0,   0,   0,   0   },
	};

	const f32 sp68[][4] = {
		{ 0,  8,  2,  10 },
		{ 12, 4,  14, 6  },
		{ 3,  11, 1,  9  },
		{ 15, 7,  13, 5  },
	};

	const f32 sp28[][4] = {
		{ 0,  14, 3,  13 },
		{ 11, 5,  8,  6  },
		{ 12, 2,  15, 1  },
		{ 7,  9,  4,  10 },
	};

	s32 i;
	s32 j;
	s32 k;

	for (i = 0; i < 3; i++) {
		f32 mult = (spa8[arg1][i + 1] - spa8[arg1][i]) * (1.0f / 16.0f);

		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				arg0[j * 12 + k * 3 + i] = 0.5f + spa8[arg1][i] + sp28[j][k] * mult;
			}
		}
	}
}

const char var7f1b4adc[] = "Pak_StartCapture -> Failed - Code = %d\n";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b4b04[] = "Pak_DownloadNextBlockToPackBuffer : eQuality=ekCapQualityHeader, BufferNum=%d\n";
#else
const char var7f1b4b04[] = "Pak_DownloadNextBlockToPackBuffer : eQuality=ekCapQualityHeader, BufferNum=%d";
#endif

const char var7f1b4b54[] = "Pak : Doing Frame - Top    = %d\n";
const char var7f1b4b78[] = "Pak : Doing Frame - Height = %d\n";
const char var7f1b4b9c[] = "Pak : Doing Frame - Bottom = %d\n";

#if VERSION == VERSION_NTSC_1_0
const char var7f1b4b9c_2[] = "Pak %d - PakDamage_UjiWipedMyAss\n";
#endif

#if VERSION < VERSION_NTSC_1_0
const char var7f1aec60nb[] = "Pak %d -> ekPakInitStatusInitMemoryPak1\n";
const char var7f1aec8cnb[] = "Pak %d -> ekPakInitStatusInitMemoryPak2\n";
const char var7f1aecb8nb[] = "Pak %d -> ekPakInitStatusInitMemoryPak3\n";
#endif

u32 var80075d58 = 0x00000000;
u32 var80075d5c = 0x00000000;

s32 pak0f11d3f8(s8 device)
{
	if (g_Paks[device].type == PAKTYPE_GAMEBOY
			&& (g_Paks[device].state == PAKSTATE_READY || g_Paks[device].state == PAKSTATE_12 || g_Paks[device].state == PAKSTATE_13)) {
		return true;
	}

	return false;
}

bool pak0f11d478(s8 device)
{
	if (g_Paks[device].unk008 == PAK008_11) {
		g_Paks[device].unk008 = PAK008_01;
		return true;
	}

	return false;
}

bool pak0f11d4dc(s8 device)
{
	if (g_Paks[device].unk008 == PAK008_01 || g_Paks[device].unk008 == PAK008_00) {
		g_Paks[device].unk008 = PAK008_02;
		g_Paks[device].unk270 = 0;
	}

	return false;
}

s32 pak0f11d540(s8 device, s32 arg1)
{
	if (g_Paks[device].unk008 == PAK008_01 || g_Paks[device].unk008 == PAK008_00) {
		g_Paks[device].unk008 = PAK008_04;
		g_Paks[device].unk270 = arg1;
		return true;
	}

	return false;
}

s32 pak0f11d5b0(s8 device)
{
	if (g_Paks[device].unk008 == PAK008_01 || g_Paks[device].unk008 == PAK008_00) {
		g_Paks[device].unk008 = PAK008_04;
		g_Paks[device].unk270 = 1;
		return true;
	}

	return false;
}

void pak0f11d620(s8 device)
{
	if (g_Paks[device].state == PAKSTATE_READY) {
		g_Paks[device].state = PAKSTATE_12;
	}
}

#if VERSION >= VERSION_NTSC_1_0
void pak0f11d678(void)
{
	// empty
}
#endif

#if VERSION < VERSION_NTSC_1_0
void gbpak0f1172c8nb(s8 device, s32 arg1)
{
	u8 buffer[0x20];
	s32 i;

	g_Paks[device].unk278 = 0;

	for (i = 0; i < sizeof(buffer); i++) {
		buffer[i] = arg1 / 2;
	}

	gbpak_write(device, 0x4000, buffer, sizeof(buffer));
}
#endif

bool gbpak0f11d680(s8 device, bool arg1)
{
	u32 offset = 0;
	u16 addr;
	u16 size;

	switch (g_Paks[device].unk00c) {
	case PAK00C_00:
		offset = 0x1a0;
		size = 0x40;
		arg1 = true;
		break;
	case PAK00C_01:
		offset = g_Paks[device].unk278 * 0x100 + 0x660;
		size = 0x40;
		break;
	case PAK00C_02:
		offset = g_Paks[device].unk278 * 0x100 + 0x440;
		size = 0x80;
		break;
	case PAK00C_03:
		offset = g_Paks[device].unk278 * var80075ccc;
		size = var80075ccc;
		break;
	}

	addr = 0xa000 + (arg1 & 1 ? 0x1000 : 0) + offset;

	if (gbpak_read(device, addr, &g_Paks[device].unk2c4[offset], size) == 0) {
		return false;
	}

	g_Paks[device].unk278++;
	return true;
}

bool pak0f11d7c4(s8 device)
{
	switch (g_Paks[device].unk00c) {
	case PAK00C_00:
		if (g_Paks[device].unk278 == 1) {
			return true;
		}
		break;
	case PAK00C_01:
		if (g_Paks[device].unk278 == 4) {
			return true;
		}
		break;
	case PAK00C_02:
		if (g_Paks[device].unk278 == 8) {
			return true;
		}
		break;
	case PAK00C_03:
		if (g_Paks[device].unk278 == 0x1000 / var80075ccc) {
			return true;
		}
		break;
	}

	return false;
}

/**
 * Convert camera pixel data from the Game Boy Camera's format and write it to
 * a 128x128 byte array.
 *
 * The GBC's format is 128x112 pixels at 2 bits per pixel. The bits are not
 * linear; the two bits for each pixel are in neighbouring bytes using the same
 * bit index. It also appears that the GBC format is column major.
 */
void pak_convert_from_gbc_image(u8 *src, u8 *dst)
{
	s32 i;
	s32 j;
	s32 byte;
	s32 bit;
	s32 a0;
	s32 a3;

	for (i = 0; i < 16; i++) {
		byte = (i * 16) << 4;
		a0 = byte;

		for (j = 0; j < 16; j++) {
			for (byte = 0; byte < 8; byte++) {
				s32 srcindex = a0 + byte * 2;
				s32 tmp = j * 8;

				for (bit = 0, a3 = tmp; bit < 8; bit++) {
					s32 t2 = (i * 8 + byte) << 7;

					dst[t2 + a3] = 0;

					if ((src[srcindex + 0] & (0x80 >> bit)) == 0) {
						dst[t2 + a3] += 0x40;
					}

					if ((src[srcindex + 1] & (0x80 >> bit)) == 0) {
						dst[t2 + a3] += 0x80;
					}

					a3++;
				}
			}

			a0 += 16;
		}
	}
}

/**
 * Perform operations on a 128 x 128 image.
 */
void pak0f11d9c4(s8 device, u8 *arg1, u8 *arg2, u32 arg3)
{
	u8 sp60[0x4000];
	u32 i;
	u32 j;

	switch (g_Paks[device].unk00c) {
	case PAK00C_00:
		if (arg2 != NULL) {
			u8 *src = &g_Paks[device].unk2c4[0x1b2];
			s32 i;

			for (i = 0; i < 30; i++) {
				arg2[i] = src[i];
			}
		}
		break;
	case PAK00C_01:
		if (arg1 != NULL) {
			pak_convert_from_gbc_image(g_Paks[device].unk2c4, sp60);

			for (i = 0; i < 128; i++) {
				for (j = 0; j < 128; j++) {
					arg1[j * 128 + i] = sp60[0x1830 + (j / 4) * 128 + (i / 4)];
				}
			}
		}
		break;
	case PAK00C_02:
		if (arg1 != NULL) {
			pak_convert_from_gbc_image(g_Paks[device].unk2c4, sp60);

			for (i = 0; i < 128; i++) {
				for (j = 0; j < 128; j++) {
					arg1[j * 128 + i] = sp60[0x1020 + (j / 2) * 128 + (i / 2)];
				}
			}
		}
		break;
	case PAK00C_03:
		if (arg1 != NULL) {
			pak_convert_from_gbc_image(g_Paks[device].unk2c4, arg1);
		}
		break;
	}

	if (arg1 && arg3) {
		s32 i;
		s32 j;
		s32 innertop = 120;
		s32 innerbottom = 8;
		u32 stack[4];

		// Move the image down by 8 rows
		for (i = innertop; i > innerbottom; i--) {
			for (j = 0; j < 128; j++) {
				arg1[i * 128 + j] = arg1[(i - 8) * 128 + j];
			}
		}

		// Fill the bottom 8 rows with black
		for (i = 0; i < innerbottom; i++) {
			for (j = 0; j < 128; j++) {
				arg1[i * 128 + j] = 0;
			}
		}

		// Fill the top 8 rows with black
		for (i = innertop; i < 128; i++) {
			for (j = 0; j < 128; j++) {
				arg1[i * 128 + j] = 0;
			}
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
void pak_rumble(s32 device, f32 numsecs, s32 onduration, s32 offduration)
{
	if (g_Paks[device].state == PAKSTATE_READY
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
#else
void pak_rumble(s8 device, f32 numsecs, s32 onduration, s32 offduration)
{
	u8 index = g_Vars.playertojoymap[device];

	if (g_Paks[index].state == PAKSTATE_READY
			&& g_Paks[index].type == PAKTYPE_RUMBLE
			&& g_Paks[index].rumblestate != RUMBLESTATE_DISABLED_STOPPING
			&& g_Paks[index].rumblestate != RUMBLESTATE_DISABLED_STOPPED
			&& g_Paks[index].rumblettl < 60 * numsecs) {
		g_Paks[index].rumblestate = RUMBLESTATE_ENABLED_STARTING;
		g_Paks[index].rumblettl = 60 * numsecs;
		g_Paks[index].rumblepulsestopat = onduration;
		g_Paks[index].rumblepulselen = onduration + offduration;
		g_Paks[index].rumblepulsetimer = 0;
	}
}
#endif

void paks_stop(bool disablepolling)
{
	s8 i;

	for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
		s32 type = g_Paks[i].type;

		if (type);

		if (type != PAKTYPE_MEMORY && type != PAKTYPE_GAMEBOY) {
			joy_stop_rumble(i, disablepolling);
		}
	}
}

void pak_disable_rumble_for_player(s8 playernum)
{
	s32 i;
	s32 tmp = playernum;
	s32 contpads[2];

#if VERSION >= VERSION_NTSC_1_0
	joy_get_contpad_nums_for_player(tmp, &contpads[0], &contpads[1]);

	for (i = 0; i < 2; i++) {
		if (contpads[i] >= 0 && g_Paks[contpads[i]].type == PAKTYPE_RUMBLE) {
			g_Paks[contpads[i]].rumblestate = RUMBLESTATE_DISABLED_STOPPING;
			joy_stop_rumble(contpads[i], true);
		}
	}
#else
	if (g_Paks[playernum].type == PAKTYPE_RUMBLE) {
		g_Paks[playernum].rumblestate = RUMBLESTATE_DISABLED_STOPPING;
		joy_stop_rumble(playernum, true);
	}
#endif
}

void pak_enable_rumble_for_player(s8 playernum)
{
	s32 i;
	s32 tmp = playernum;
	s32 contpads[2];

#if VERSION >= VERSION_NTSC_1_0
	joy_get_contpad_nums_for_player(tmp, &contpads[0], &contpads[1]);

	for (i = 0; i < 2; i++) {
		if (contpads[i] >= 0
				&& g_Paks[contpads[i]].type == PAKTYPE_RUMBLE
				&& g_Paks[contpads[i]].rumblestate == RUMBLESTATE_DISABLED_STOPPED) {
			g_Paks[contpads[i]].rumblestate = RUMBLESTATE_ENABLING;
		}
	}
#else
	if (g_Paks[playernum].type == PAKTYPE_RUMBLE
			&& g_Paks[playernum].rumblestate == RUMBLESTATE_DISABLED_STOPPED) {
		g_Paks[playernum].rumblestate = RUMBLESTATE_ENABLING;
	}
#endif
}

void pak_disable_rumble_for_all_players(void)
{
	s32 i;

#if VERSION >= VERSION_NTSC_1_0
	for (i = 0; i < MAX_PLAYERS; i++) {
		if (g_Paks[i].type == PAKTYPE_RUMBLE) {
			g_Paks[i].rumblestate = RUMBLESTATE_DISABLED_STOPPING;
			joy_stop_rumble(i, true);
		}
	}
#else
	for (i = 0; i < MAX_PLAYERS; i++) {
		pak_disable_rumble_for_player(i);
	}
#endif
}

void pak_enable_rumble_for_all_players(void)
{
	s32 i;

#if VERSION >= VERSION_NTSC_FINAL
	for (i = 0; i < MAX_PLAYERS; i++) {
		if (g_Paks[i].type == PAKTYPE_RUMBLE && g_Paks[i].rumblestate == RUMBLESTATE_DISABLED_STOPPED) {
			g_Paks[i].rumblestate = RUMBLESTATE_ENABLING;
		}
	}
#else
	for (i = 0; i < MAX_PLAYERS; i++) {
		pak_enable_rumble_for_player(i);
	}
#endif
}

#if VERSION >= VERSION_NTSC_1_0
s32 pak0f11df84(s32 arg0)
{
	return arg0;
}
#endif

void pak_dump_pak(void)
{
	// empty
}

void pak0f117f94nb(s8 device);

void pak_tick_state(s8 device)
{
#if VERSION == VERSION_NTSC_1_0
	if (g_Paks[device].showdatalost) {
		SETBANNER(-1);

		if (menu_is_ready_for_pak_error(device, PAKERRORDIALOG_DATALOST)) {
			menu_push_pak_error_dialog(device, PAKERRORDIALOG_DATALOST);
			g_Paks[device].showdatalost = false;
		}
	}
#endif

	switch (g_Paks[device].state) {
	case PAKSTATE_NOPAK:
		break;
	case PAKSTATE_UNPLUGGING:
		g_Paks[device].state = PAKSTATE_NOPAK;
		g_Paks[device].plugcount++;
#if VERSION >= VERSION_NTSC_FINAL
		g_Paks[device].showdatalost = false;
#endif
		g_Paks[device].type = PAKTYPE_NONE;

		SETBANNER(-1);
		func0f14aed0(device);
		break;
	case PAKSTATE_PROBE:
#if VERSION >= VERSION_NTSC_1_0
		SETBANNER(-1);
		pak_probe(device);
#else
		pak0f114dd4nb(device);
#endif
		func0f14aed0(device);
		break;
	case PAKSTATE_MEM_DISPATCH:
#if VERSION >= VERSION_NTSC_1_0
		if (g_Vars.paksneededformenu & (1 << device))
#else
		if ((g_Vars.paksneededforgame | g_Vars.paksneededformenu) & (1 << device))
#endif
		{
			if (device == SAVEDEVICE_GAMEPAK) {
				g_Paks[device].state = PAKSTATE_MEM_PREPARE;
			} else {
				g_Paks[device].state = PAKSTATE_MEM_PRE_PREPARE;
			}
		} else {
			g_Paks[device].state = PAKSTATE_07;
		}
		break;
	case PAKSTATE_07:
#if VERSION >= VERSION_NTSC_1_0
		if (g_Vars.paksneededformenu & (1 << device))
#else
		if ((g_Vars.paksneededforgame | g_Vars.paksneededformenu) & (1 << device))
#endif
		{
			g_Paks[device].state = PAKSTATE_PROBE;
		}
		break;
	default:
		break;
	case PAKSTATE_MEM_PRE_PREPARE:
		g_MpPlayerNum = device;

		SETBANNER(MENUBANNER_CHECKINGPAK);

		g_Paks[device].state = PAKSTATE_MEM_PREPARE;
		break;
	case PAKSTATE_MEM_PREPARE:
#if VERSION >= VERSION_NTSC_1_0
		joy_disable_cyclic_polling();
		mempak_prepare(device);
		joy_enable_cyclic_polling();
#else
		mempak_prepare(device);
#endif
		break;
	case PAKSTATE_MEM_POST_PREPARE:
		SETBANNER(-1);
		g_Paks[device].state = PAKSTATE_READY;
		break;
	case PAKSTATE_GB_PRE_PREPARE:
		if (editor_needs_gbpak(device)) {
			g_Paks[device].state = PAKSTATE_GB_PREPARE;
		}
		break;
	case PAKSTATE_GB_PREPARE:
#if VERSION >= VERSION_NTSC_1_0
		g_Paks[device].unk008 = PAK008_00;
		g_Paks[device].state = PAKSTATE_GB_POST_PREPARE1;
#else
		{
			s32 ret;

			joy_disable_cyclic_polling(5914, "pak.c");
			ret = osGbpakInit(&g_PiMesgQueue, PFS(device), device);
			joy_enable_cyclic_polling(5916, "pak.c");

			if (ret == 0) {
				g_Paks[device].type = PAKTYPE_GAMEBOY;
				g_Paks[device].unk008 = PAK008_00;
				g_Paks[device].state = PAKSTATE_GB_POST_PREPARE1;
			} else {
				gbpak_handle_error(ret);
				g_Paks[device].type = PAKTYPE_GAMEBOY_ERROR;
				g_Paks[device].state = PAKSTATE_NOPAK;
			}
		}
#endif
		break;
	case PAKSTATE_GB_POST_PREPARE1:
		g_Paks[device].state = PAKSTATE_GB_POST_PREPARE2;
		break;
	case PAKSTATE_GB_POST_PREPARE2:
		g_Paks[device].state = PAKSTATE_GB_POST_PREPARE3;
		break;
	case PAKSTATE_GB_POST_PREPARE3:
		g_Paks[device].state = PAKSTATE_READY;
		break;
	case PAKSTATE_12:
#if VERSION >= VERSION_NTSC_1_0
		g_Paks[device].state = PAKSTATE_READY;
#else
		if (g_Paks[device].type == PAKTYPE_GAMEBOY) {
			joy_disable_cyclic_polling(5960, "pak.c");
			pak0f117f94nb(device);
			joy_enable_cyclic_polling(5962, "pak.c");

			g_Paks[device].state = PAKSTATE_13;
		} else {
			g_Paks[device].state = PAKSTATE_READY;
		}
#endif
		break;
	case PAKSTATE_13:
		break;
	case PAKSTATE_MEM_ENTER_CORRUPT:
		SETBANNER(-1);

#if VERSION >= VERSION_NTSC_1_0
		if ((g_Vars.paksneededformenu & (1 << device)))
#endif
		{
			if (menu_is_ready_for_pak_error(device, PAKERRORDIALOG_CORRUPT)) {
				menu_push_pak_error_dialog(device, PAKERRORDIALOG_CORRUPT);
				g_Paks[device].state = PAKSTATE_MEM_CORRUPT;
			} else {
				// empty
			}
		}
		break;
#if VERSION >= VERSION_NTSC_1_0
	case PAKSTATE_GB_OPEN_UNREADABLE:
		if (menu_is_ready_for_pak_error(device, PAKERRORDIALOG_GB_UNREADABLE)) {
			menu_push_pak_error_dialog(device, PAKERRORDIALOG_GB_UNREADABLE);
			g_Paks[device].state = PAKSTATE_GB_IDLE_UNREADABLE;
		}
		break;
	case PAKSTATE_GB_IDLE_UNREADABLE:
		g_Paks[device].state = PAKSTATE_READY;
		break;
#endif
	case PAKSTATE_MEM_ENTER_DEVICEERROR:
		SETBANNER(-1);

#if VERSION >= VERSION_NTSC_1_0
		if (g_Vars.paksneededformenu & (1 << device))
#endif
		{
			if (menu_is_ready_for_pak_error(device, PAKERRORDIALOG_DEVICEERROR)) {
				menu_push_pak_error_dialog(device, PAKERRORDIALOG_DEVICEERROR);
				g_Paks[device].state = PAKSTATE_MEM_DEVICEERROR;
			} else {
				// empty
			}
		}
		break;
	case PAKSTATE_MEM_ENTER_FULL:
		SETBANNER(-1);

#if VERSION >= VERSION_NTSC_1_0
		if (g_Vars.paksneededformenu & (1 << device))
#endif
		{
			if (menu_is_ready_for_pak_error(device, PAKERRORDIALOG_FULL)) {
				menu_push_pak_error_dialog(device, PAKERRORDIALOG_FULL);
				g_Paks[device].state = PAKSTATE_MEM_FULL;
			} else {
				// empty
			}
		}
		break;
	case PAKSTATE_MEM_FULL:
		SETBANNER(-1);
		break;
	case PAKSTATE_22:
		SETBANNER(-1);
		break;
	}

#if VERSION >= VERSION_NTSC_FINAL
	if (g_Paks[device].showdatalost) {
		SETBANNER(-1);

		if (menu_is_ready_for_pak_error(device, PAKERRORDIALOG_DATALOST)) {
			menu_push_pak_error_dialog(device, PAKERRORDIALOG_DATALOST);
			g_Paks[device].showdatalost = false;
		}
	}
#endif
}

const char var7f1b4bc0[] = "Pak %d - ekPakInitStatusError_CorruptedPak\n";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b4bec[] = "Pak %d - ekPakInitStatusInitGameBoy_PDGB_Check_Error\n";
#endif

const char var7f1b4c24[] = "Pak %d - ekPakInitStatusError_DamagedPak\n";
const char var7f1b4c50[] = "Pak %d - ekPakInitStatusError_StuffedPak\n";
const char var7f1b4c7c[] = "Pak %d - ekPakInitStatusError_StuffedAndCheckedPak\n";
const char var7f1b4cb0[] = "Pak %d - ekPakInitStatusVoid\n";
const char var7f1b4cd0[] = "Pak %d -> Unhandled Init Status - %d\n";

#if VERSION >= VERSION_NTSC_FINAL
const char var7f1b4cf8[] = "Pak %d - PakDamage_UjiWipedMyAss\n";
#endif

#if VERSION < VERSION_NTSC_1_0
const char var7f1aee04nb[] = "Pak_EEPROM_Init";
#endif

#if VERSION >= VERSION_NTSC_1_0
void pak0f11e3b4(void)
{
	// empty
}
#endif

#if VERSION < VERSION_NTSC_1_0
s32 gbpak_identify_game(s8 device);

void pak0f117f94nb(s8 device)
{
	struct pak *pak = &g_Paks[device];

	pak->unk2b8_05 = gbpak_identify_game(device);

	if (pak);
	if (pak);

	if (pak->unk008 == PAK008_12) {
		pak->unk2b8_05 = gbpak_identify_game(device);

		if (pak->unk2b8_05 && pak->isgbcamera) {
			pak->unk008 = PAK008_00;
		}
	}

	if (!pak->unk2b8_05) {
		editor_stop_autocalibrate();
		pak->unk008 = PAK008_12;
		return;
	}

	if (pak->unk008 != PAK008_01) {
		if (pak->unk008 == PAK008_00) {
			gbpak0f11cef8(device);
			return;
		}

		if (pak->unk008 == PAK008_02) {
			gbpak0f11cef8(device);
			pak->unk008 = PAK008_03;
		}

		if (pak->unk008 == PAK008_03) {
			if (pak0f116d1cnb(device) == 0) {
				pak->unk008 = PAK008_04;
			}
		}

		if (pak->unk008 == PAK008_04) {
			pak->unk008 = pak->unk2b8_06 ? PAK008_05 : PAK008_08;
		}

		if (pak->unk008 == PAK008_05) {
			gbpak0f11cef8(device);
			pak->unk008 = PAK008_06;
		}

		if (pak->unk008 == PAK008_06) {
			if (pak0f116d1cnb(device) == 0) {
				pak->unk008 = PAK008_07;
			}
		}

		if (pak->unk008 == PAK008_07) {
			pak->unk008 = PAK008_08;
		}

		if (pak->unk008 == PAK008_08) {
			s32 i;

			for (i = 0; i < 0x1000; i++) {
				pak->unk2c4[i] = 0;
			}

			gbpak0f1172c8nb(device, pak->unk270);
			pak->unk008 = PAK008_09;
		}

		if (pak->unk008 == PAK008_09) {
			if (gbpak0f11d680(device, pak_get_unk270(device)) && pak0f11d7c4(device)) {
				pak_set_unk008(device, PAK008_11);
			}
		}
	}
}
#endif

void pak0f11e3bc(s8 device)
{
	g_Paks[device].unk008 = PAK008_00;
}

void pak_probe_eeprom(void)
{
	s32 type;

	joy_disable_cyclic_polling(JOYARGS(6199));
	type = osEepromProbe(&g_PiMesgQueue);
	joy_enable_cyclic_polling(JOYARGS(6201));

	if (type == EEPROM_TYPE_16K) {
		g_PakHasEeprom = true;

		if (arg_find_by_prefix(1, "-scrub")) {
			pak_create_filesystem(SAVEDEVICE_GAMEPAK);
		}
	} else {
		g_PakHasEeprom = false;
	}
}

PakErr1 pak_read_eeprom(u8 address, u8 *buffer, u32 len)
{
	s32 result;

	joy_disable_cyclic_polling(JOYARGS(6234));
	result = osEepromLongRead(&g_PiMesgQueue, address, buffer, len);
	joy_enable_cyclic_polling(JOYARGS(6236));

	return result == PAK_ERR1_OK ? PAK_ERR1_OK : PAK_ERR1_EEPROMREADFAILED;
}

PakErr1 pak_write_eeprom(u8 address, u8 *buffer, u32 len)
{
	s32 result;

	joy_disable_cyclic_polling(JOYARGS(6269));
	result = osEepromLongWrite(&g_PiMesgQueue, address, buffer, len);
	joy_enable_cyclic_polling(JOYARGS(6271));

	return result == PAK_ERR1_OK ? PAK_ERR1_OK : PAK_ERR1_EEPROMWRITEFAILED;
}

void pak_set_bitflag(s32 flagnum, u8 *bitstream, bool set)
{
	u32 byteindex = (u32)flagnum / 8;
	u8 mask = 1 << ((u32)flagnum % 8);

	if (set) {
		bitstream[byteindex] |= mask;
	} else {
		bitstream[byteindex] &= (u8)~mask;
	}
}

bool pak_has_bitflag(u32 flagnum, u8 *bitstream)
{
	u32 byteindex = flagnum / 8;
	u8 mask = 1 << (flagnum % 8);

	return bitstream[byteindex] & mask ? 1 : 0;
}

void pak_clear_all_bitflags(u8 *flags)
{
	s32 i;

	for (i = 0; i <= GAMEFILEFLAG_4E; i++) {
		pak_set_bitflag(i, flags, false);
	}
}

u32 pak0f11e610(u32 arg0)
{
	return arg0;
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
void pak_n64_font_code_to_ascii(char *src, char *dst, s32 len)
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
#if VERSION >= VERSION_JPN_FINAL
		if ((u32)c == '"') {
			*ptr = '\'';
			ptr++;
			*ptr = '\'';
		} else if (in >= 0x42 && in <= 0x94) {
			*ptr = (in >> 7) | 0x80;
			ptr++;
			*ptr = (in & 0x7f) | 0x80;
		} else {
			*ptr = c;
		}
#else
		if ((u32)c == '"') {
			*ptr = '\'';
			ptr++;
			*ptr = '\'';
		} else {
			*ptr = c;
		}
#endif

		ptr++;
	}

	*ptr = '\0';

	strcpy(dst, buffer);
}

s8 pak_find_by_serial(s32 findserial)
{
	s8 device = -1;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Paks); i++) {
		if (mempak_is_ready(i)) {
			s32 serial = pak_get_serial(i);

			if (findserial == serial) {
				device = i;
			}
		}
	}

	return device;
}

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b4d24[] = "Pak %d -> Pak_PdGameBoySetRWByte - Fatal Error\n";
#else
const char var7f1b4d24[] = "Pak %d -> Pak_PdGameBoySetRWByte - Fatal Error";
#endif

s32 pak0f11e750(s8 device)
{
	u8 buffer[32];
	buffer[0] = 0x0a;

	return gbpak_write(device, 0, buffer, sizeof(buffer));
}

bool gbpak_is_any_perfect_dark(void)
{
	s8 i;

	for (i = 0; i < MAX_PLAYERS; i++) {
		if (gbpak_identify_game(i) == GBGAME_PD) {
			return true;
		}
	}

	return false;
}

/**
 * Probable @bug: This function is probably intended to be a "strings are equal"
 * check, however it's actually checking if either string starts with the other.
 */
bool gbpak_strcmp(char *a, char *b)
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

bool pak0f11eaec(s8 device);

s32 gbpak_identify_game(s8 device)
{
#if VERSION >= VERSION_NTSC_1_0
	OSGbpakId id;
	u8 status;
	s32 ret;
	s32 game = GBGAME_OTHER;
	bool poweredon = false;
	bool ok = true;

	if (g_Paks[device].type != PAKTYPE_GAMEBOY) {
		return GBGAME_OTHER;
	}

	joy_disable_cyclic_polling();

	ret = osGbpakReadId(PFS(device), &id, &status);

#if VERSION >= VERSION_NTSC_FINAL
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
#else
	// NTSC 1.0 only sets poweredon to true if the call to osGbpakReadId
	// returned PAK_ERR1_OK.
	// The else here might have been else if (ok). This optimises itself out,
	// but may explain why the final code appears to use a condition. They could
	// have moved the else-if into its own check (and had to do it prior to the
	// ret check for it to work as intended).
	if (ret != PAK_ERR1_OK) {
		ok = false;
	} else {
		poweredon = true;
	}
#endif

	if (var80075cb0 == id.company_code) {
		// PerfDark or PerfDark
		if (gbpak_strcmp(var80075cb4, id.game_title) || gbpak_strcmp(var80075cc0, id.game_title)) {
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

	joy_enable_cyclic_polling();

	if (ok) {
		return game;
	}

	g_Paks[device].state = PAKSTATE_GB_OPEN_UNREADABLE;
	return GBGAME_OTHER;
#else
	OSGbpakId id;
	u8 status;
	u32 stack;

	joy_disable_cyclic_polling(7045, "pak.c");

	if (g_Paks[device].type != PAKTYPE_GAMEBOY) {
		joy_enable_cyclic_polling(7050, "pak.c");
		return GBGAME_OTHER;
	}

	if (osGbpakGetStatus(PFS(device), &status) != PAK_ERR1_OK) {
		joy_enable_cyclic_polling(7057, "pak.c");
		return GBGAME_OTHER;
	}

	if (status & OS_GBPAK_RSTB_DETECTION) {
		osGbpakGetStatus(PFS(device), &status);
	}

	if ((status & OS_GBPAK_GBCART_ON) == 0) {
		joy_enable_cyclic_polling(7071, "pak.c");
		return GBGAME_OTHER;
	}

	if ((status & OS_GBPAK_GBCART_ON) == 0) {
		joy_enable_cyclic_polling(7078, "pak.c");
		return GBGAME_OTHER;
	}

	if (osGbpakPower(PFS(device), OS_GBPAK_POWER_ON) != PAK_ERR1_OK) {
		joy_enable_cyclic_polling(7085, "pak.c");
		return GBGAME_OTHER;
	}

	if (osGbpakReadId(PFS(device), &id, &status) != PAK_ERR1_OK) {
		joy_enable_cyclic_polling(7096, "pak.c");
		return GBGAME_OTHER;
	}

	if (var80075cb0 == id.company_code) {
		// POCKETCAMERA or GAMEBOYCAMERA
		if (gbpak_strcmp(var80078058nb, id.game_title) || gbpak_strcmp(var80078068nb, id.game_title)) {
			g_Paks[device].isgbcamera = true;
			g_Paks[device].isgbpd = false;
			joy_enable_cyclic_polling(7111, "pak.c");
		}
	}

	if (var80078054nb == id.company_code) {
		// PerfDark or GAMEBOYCAMERA
		if (gbpak_strcmp(var80078078nb, id.game_title) || gbpak_strcmp(var80078084nb, id.game_title)) {
			g_Paks[device].isgbcamera = false;
			g_Paks[device].isgbpd = true;
			pak0f11eaec(device);
			joy_enable_cyclic_polling(7135, "pak.c");
			return GBGAME_PD;
		}
	}

	joy_enable_cyclic_polling(7140, "pak.c");

	return GBGAME_OTHER;
#endif
}

bool pak0f11ea34(s8 arg0)
{
	char numbers[] = "0123456789012345678901234567890123456789";
	u8 sp20[36];

	if (!pak0f11cd00(arg0, 0xa000, numbers, 32, true)) {
		return false;
	}

	if (!pak0f11ce00(arg0, 0xa000, sp20, 32, true)) {
		return false;
	}

	return true;
}

bool pak0f11eaec(s8 device)
{
	u8 sp78[32];
	u8 sp58[32];
	u8 sp38[32];
	s32 i;
	bool sp30 = false;
	bool result = false;
	u8 sp28[2];

	for (i = 0; i < 32; i++) {
		sp78[i] = 0;
		sp58[i] = 0;
	}

	sp78[0] = 0;

	pak0f11ea34(device);
	pak0f11ea34(device);
	pak0f11ea34(device);

	if (!pak0f11ce00(device, 0xbfe0, sp38, 32, true)) {
		sp30 = true;
	}

	for (i = 0; i < 32; i++) {
		sp28[0] = sp38[i];
		sp28[1] = 0;
	}

#if VERSION >= VERSION_NTSC_1_0
	gbpak_strcmp("PerfDark\n", sp38);
#else
	gbpak_strcmp("PerfDark", sp38);
#endif

	if (!pak0f11ce00(device, 0xa000, sp38, 32, true)) {
		sp30 = true;
	}

	if (sp38[0] & 1) {
		result = true;
	}

	if (sp30) {
		return false;
	}

	return result;
}

/**
 * This function isn't called.
 *
 * It reads data from the game boy pak, unsets a bit, writes it, reads it back,
 * sets the bit, writes it and then reads it back.
 */
void gbpak_fiddle(s8 device)
{
	u8 buffer[32];

	if (gbpak_read(device, 0xa000, buffer, sizeof(buffer))) {
		pak0f11e750(device);
		buffer[0] &= 0x7f;

		if (gbpak_write(device, 0xa000, buffer, sizeof(buffer))) {
			if (gbpak_read(device, 0xa000, buffer, sizeof(buffer))) {
				buffer[0] |= 0x80;

				if (gbpak_write(device, 0xa000, buffer, sizeof(buffer))) {
					gbpak_read(device, 0xa000, buffer, sizeof(buffer));
				}
			}
		}
	}
}
