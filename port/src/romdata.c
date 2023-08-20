#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <PR/ultratypes.h>
#include <PR/ultratypes.h>
#include "lib/rzip.h"
#include "romdata.h"
#include "fs.h"
#include "system.h"
#include "preprocess.h"
#include "platform.h"

/**
 * asset files and ROM segments can be replaced by optional external files,
 * but asset filenames still have to be either pulled from the ROM or from an
 * external file, so stuff can't be completely custom
 * 
 * all data is assumed to be big endian, so it has to be byteswapped
 * at load time, which is fucking terrible
 */

#define ROMDATA_ROM_NAME "pd.ntsc-final.z64"
#define ROMDATA_ROM_SIZE 33554432
#define ROMDATA_ROM_HASH // TODO

#define ROMDATA_FILEDIR "files"
#define ROMDATA_SEGDIR "segs"

// for ntsc-final
#define ROMDATA_FILES_OFS 0x28080
#define ROMDATA_DATA_OFS 0x39850

#define ROMDATA_MAX_FILES 2048

u8 *g_RomFile;
u32 g_RomFileSize;

static u8 *romDataSeg;
static u32 romDataSegSize;

struct romfile {
	u8 **segstart;
	u8 **segend;
	const char *name;
	u8 *data;
	u32 size;
	preprocessfunc preprocess;
	s32 external;
	s32 preprocessed;
};

static struct romfile fileSlots[ROMDATA_MAX_FILES];

#define ROMSEG_START(n) _ ## n ## SegmentRomStart
#define ROMSEG_END(n) _ ## n ## SegmentRomEnd

/* segment table for ntsc-final                                                     */
/* size will get calculated automatically if it is 0                                */
/* if there are replacement files in the data dir, they will be loaded instead      */
#define ROMSEG_LIST() \
	ROMSEG_DECL_SEG(fontjpnsingle,      0x194b20,  0x0,      preprocessJpnFont       ) \
	ROMSEG_DECL_SEG(fontjpnmulti,       0x19fb40,  0x0,      preprocessJpnFont       ) \
	ROMSEG_DECL_SEG(animations,         0x1a15c0,  0x0,      preprocessAnimations    ) \
	ROMSEG_DECL_SEG(mpconfigs,          0x7d0a40,  0x11E0,   preprocessMpConfigs     ) \
	ROMSEG_DECL_SEG(mpstringsE,         0x7d1c20,  0x3700,   NULL                    ) \
	ROMSEG_DECL_SEG(mpstringsJ,         0x7d5320,  0x3700,   NULL                    ) \
	ROMSEG_DECL_SEG(mpstringsP,         0x7d8a20,  0x3700,   NULL                    ) \
	ROMSEG_DECL_SEG(mpstringsG,         0x7dc120,  0x3700,   NULL                    ) \
	ROMSEG_DECL_SEG(mpstringsF,         0x7df820,  0x3700,   NULL                    ) \
	ROMSEG_DECL_SEG(mpstringsS,         0x7e2f20,  0x3700,   NULL                    ) \
	ROMSEG_DECL_SEG(mpstringsI,         0x7e6620,  0x3700,   NULL                    ) \
	ROMSEG_DECL_SEG(firingrange,        0x7e9d20,  0x1550,   NULL                    ) \
	ROMSEG_DECL_SEG(fonttahoma,         0x7f7860,  0x0,      preprocessFont          ) \
	ROMSEG_DECL_SEG(fontnumeric,        0x7f8b20,  0x0,      preprocessFont          ) \
	ROMSEG_DECL_SEG(fonthandelgothicsm, 0x7f9d30,  0x0,      preprocessFont          ) \
	ROMSEG_DECL_SEG(fonthandelgothicxs, 0x7fbfb0,  0x0,      preprocessFont          ) \
	ROMSEG_DECL_SEG(fonthandelgothicmd, 0x7fdd80,  0x0,      preprocessFont          ) \
	ROMSEG_DECL_SEG(fonthandelgothiclg, 0x8008e0,  0x0,      preprocessFont          ) \
	ROMSEG_DECL_SEG(sfxctl,             0x80a250,  0x2fb80,  preprocessALBankFile    ) \
	ROMSEG_DECL_SEG(sfxtbl,             0x839dd0,  0x4c2160, NULL                    ) \
	ROMSEG_DECL_SEG(seqctl,             0xcfbf30,  0xa060,   preprocessALBankFile    ) \
	ROMSEG_DECL_SEG(seqtbl,             0xd05f90,  0x17c070, NULL                    ) \
	ROMSEG_DECL_SEG(sequences,          0xe82000,  0x563a0,  preprocessSequences     ) \
	ROMSEG_DECL_SEG(texturesdata,       0x1d65f40, 0x291d60, NULL                    ) \
	ROMSEG_DECL_SEG(textureslist,       0x1ff7ca0, 0x6d80,   preprocessTexturesList  )

// declare the vars first

#undef ROMSEG_DECL_SEG
#define ROMSEG_DECL_SEG(name, ofs, size, preproc) u8 *ROMSEG_START(name), *ROMSEG_END(name);
ROMSEG_LIST()

// this is part of the animations seg and as such does not follow the naming convention
// these are set in preprocessAnimations
u8 *_animationsTableRomStart;
u8 *_animationsTableRomEnd;

// then build the table

#undef ROMSEG_DECL_SEG
#define ROMSEG_DECL_SEG(name, ofs, size, preproc) { &ROMSEG_START(name), &ROMSEG_END(name), #name, (u8 *)ofs, size, preproc },
static struct romfile romSegs[] = {
	ROMSEG_LIST()
	{ NULL, NULL, NULL, NULL, 0, NULL },
};

/* the game sets g_LoadType to the type of file it expects,                     */
/* so we can hijack that in fileLoad and automatically byteswap the file */
static preprocessfunc filePreprocFuncs[] = {
	/* LOADTYPE_NONE  */ NULL,
	/* LOADTYPE_BG    */ NULL, // loaded in parts
	/* LOADTYPE_TILES */ preprocessTilesFile,
	/* LOADTYPE_LANG  */ preprocessLangFile,
	/* LOADTYPE_SETUP */ preprocessSetupFile,
	/* LOADTYPE_PADS  */ preprocessPadsFile,
	/* LOADTYPE_MODEL */ preprocessModelFile,
	/* LOADTYPE_GUN   */ preprocessGunFile,
};

static inline void romdataLoadRom(void)
{
	g_RomFile = fsFileLoad(ROMDATA_ROM_NAME, &g_RomFileSize);

	if (!g_RomFile) {
		sysFatalError("Could not open ROM file " ROMDATA_ROM_NAME ".\nEnsure that it is in the data directory.");
	}

	if (g_RomFileSize != ROMDATA_ROM_SIZE) {
		sysFatalError("Wrong ROM file size.\nExpected: %u\nGot: %u", ROMDATA_ROM_SIZE, g_RomFileSize);
	}

	if (memcmp(g_RomFile + 0x3b, "NPDE", 4) || memcmp(g_RomFile + 0x20, "Perfect Dark", 12)) {
		sysFatalError("Wrong ROM file.\nEnsure that it is the correct NTSC v1.1 ROM in z64 format.");
	}

	// inflate the compressed data segment since that's where some useful stuff is

	u8 *zipped = g_RomFile + ROMDATA_DATA_OFS;
	if (!zipped) {
		sysFatalError("Data segment not found.");
	}
	if (!rzipIs1173(zipped)) {
		sysFatalError("Data segment is not 1173-compressed.");
	}

	const u32 dataSegLen = ((u32)zipped[2] << 16) | ((u32)zipped[3] << 8) | (u32)zipped[4];
	if (dataSegLen < ROMDATA_FILES_OFS) {
		sysFatalError("Data segment too small (%u), need at least %u.", dataSegLen, ROMDATA_FILES_OFS);
	}

	u8 *dataSeg = sysMemAlloc(dataSegLen);
	if (!dataSeg) {
		sysFatalError("Could not allocate %u bytes for data segment.", dataSegLen);
	}

	u8 scratch[5 * 1024];
	if (rzipInflate(zipped, dataSeg, scratch) < 0) {
		free(dataSeg);
		sysFatalError("Could not inflate data segment.");
	}

	romDataSeg = dataSeg;
	romDataSegSize = dataSegLen;
}

static inline void romdataInitSegment(struct romfile *seg)
{
	if (!seg->size) {
		// size unknown
		if (seg[1].name) {
			// use next segment's base to calculate
			seg->size = seg[1].data - seg->data;
		} else {
			// this is the last segment, calculate based on rom size
			seg->size = (u8 *)g_RomFileSize - seg->data;
		}
	}

	// check if we have an external replacement and load it if so
	u8 *newData = NULL;
	const s32 extFileSize = fsFileSize(seg->name);
	if (extFileSize > 0) {
		char tmp[FS_MAXPATH];
		snprintf(tmp, sizeof(tmp), ROMDATA_SEGDIR "/%s", seg->name);
		newData = fsFileLoad(tmp, &seg->size);
	}

	if (!newData) {
		// no external data, just make it point to the rom
		if (g_RomFile) {
			newData = g_RomFile + (uintptr_t)seg->data;
			printf("loading segment %s from ROM (offset %08x pointer %p)\n", seg->name, (u32)seg->data, newData);
			fflush(stdout);
		} else {
			sysFatalError("No ROM or external file for segment:\n%s", seg->name);
		}
	} else {
		// loaded external data
		seg->external = 1;
		printf("loading segment %s from file (pointer %p)\n", seg->name, newData);
		fflush(stdout);
	}

	seg->data = newData;

	if (seg->segstart) {
		*seg->segstart = seg->data;
	}

	if (seg->segend) {
		*seg->segend = seg->data + seg->size;
	}

	// call the post load function if any
	if (seg->preprocess && !seg->preprocessed) {
		seg->preprocess(seg->data, seg->size);
		seg->preprocessed = 1;
	}
}

static inline s32 romdataLoadExternalFileList(void)
{
	romDataSeg = fsFileLoad("filenames.lst", &romDataSegSize); // this null terminates the file by itself
	if (!romDataSeg || !romDataSegSize) {
		return 0;
	}

	s32 n = 1;
	char *p = (char *)romDataSeg;
	while (*p && n < ROMDATA_MAX_FILES) {
		// skip whitespace
		while (*p && isspace(*p)) ++p;
		if (*p) {
			const char *start = p;
			// skip to next whitespace or end of file
			while (*p && !isspace(*p)) ++p;
			// null terminate the name if needed
			if (*p) {
				*p++ = '\0';
			}
			fileSlots[n++].name = start;
		}
	}

	return n - 1;
}

static inline void romdataInitFiles(void)
{
	if (!g_RomFile) {
		// no ROM; try to load the file name list from disk
		if (!romdataLoadExternalFileList()) {
			sysFatalError("No ROM or external file for filename table.");
		}
		return;
	}

	// the file offset table is in the data seg
	const u32 *offsets = (u32 *)(romDataSeg + ROMDATA_FILES_OFS);
	u32 i;
	for (i = 1; offsets[i]; ++i) {
		if (offsets + i + 1 < (u32 *)(romDataSeg + romDataSegSize)) {
			const u32 nextofs = PD_BE32(offsets[i + 1]);
			const u32 ofs = PD_BE32(offsets[i]);
			fileSlots[i].data = g_RomFile + ofs;
			fileSlots[i].size = nextofs - ofs;
			fileSlots[i].external = 0;
			fileSlots[i].preprocessed = 0;
		}
	}

	// last offset is to the name table
	const u32 *nameOffsets = (u32 *)(g_RomFile + PD_BE32(offsets[i - 1]));
	for (i = 1; nameOffsets[i]; ++i) {
		const u32 ofs = PD_BE32(nameOffsets[i]);
		fileSlots[i].name = (const char *)nameOffsets + ofs; // ofs is relative to the start of the name table
		printf("file %d name `%s` ofs %d size %u\n", i, fileSlots[i].name, fileSlots[i].data - g_RomFile, fileSlots[i].size);
	}
}

static inline struct romfile *romdataGetSeg(const char *name)
{
	struct romfile *seg = romSegs;
	while (seg->name && strcmp(name, seg->name)) {
		++seg;
	}
	return seg;
}

s32 romdataInit(void)
{
	romdataLoadRom();

	// set segments to point to the rom or load them externally
	for (struct romfile *seg = romSegs; seg->name; ++seg) {
		romdataInitSegment(seg);
	}

	// load file table from the files segment
	romdataInitFiles();

	printf("romdataInit: loaded rom, size = %u\n", g_RomFileSize);
	fflush(stdout);

	return 0;
}

s32 romdataFileGetSize(s32 fileNum)
{
	if (fileNum < 1 || fileNum >= ROMDATA_MAX_FILES) {
		fprintf(stderr, "romdataFileGetSize: invalid file num %d", fileNum);
		return -1;
	}
	if (!fileSlots[fileNum].data) {
		fprintf(stderr, "romdataFileGetSize: file %d is not loaded", fileNum);
		return -1;
	}
	return fileSlots[fileNum].size;
}

u8 *romdataFileGetData(s32 fileNum)
{
	if (fileNum < 1 || fileNum >= ROMDATA_MAX_FILES) {
		fprintf(stderr, "romdataFileGetData: invalid file num %d", fileNum);
		return NULL;
	}
	if (!fileSlots[fileNum].data) {
		fprintf(stderr, "romdataFileGetData: file %d is not loaded, loading", fileNum);
		return romdataFileLoad(fileNum, NULL);
	}
	return fileSlots[fileNum].data;
}

u8 *romdataFileLoad(s32 fileNum, u32 *outSize)
{
	if (fileNum < 1 || fileNum >= ROMDATA_MAX_FILES) {
		fprintf(stderr, "romdataFileLoad: invalid file num %d", fileNum);
		return NULL;
	}

	u8 *out = NULL;

	// try to load external file
	if (!fileSlots[fileNum].external) {
		char tmp[FS_MAXPATH] = { 0 };
		snprintf(tmp, sizeof(tmp), ROMDATA_FILEDIR "/%s", fileSlots[fileNum].name);
		if (fsFileSize(tmp) > 0) {
			u32 size = 0;
			out = fsFileLoad(tmp, &size);
			if (out && size) {
				printf("file %d (%s) loaded externally\n", fileNum, fileSlots[fileNum].name);
				fileSlots[fileNum].data = out;
				fileSlots[fileNum].size = size;
				fileSlots[fileNum].external = 1;
			}
		}
	}

	if (!out) {
		out = fileSlots[fileNum].data;
	}

	if (out && outSize) {
		*outSize = fileSlots[fileNum].size;
	}

	return out;
}

void romdataFilePreprocess(s32 fileNum, s32 loadType, u8 *data, u32 size)
{
	if (fileNum < 1 || fileNum >= ROMDATA_MAX_FILES) {
		fprintf(stderr, "romdataFilePreprocess: invalid file num %d", fileNum);
		return;
	}

	if (data && size /* && !fileSlots[fileNum].preprocessed*/) {
		if (loadType && loadType < (u32)ARRAYCOUNT(filePreprocFuncs) && filePreprocFuncs[loadType]) {
			filePreprocFuncs[loadType](data, size);
			// fileSlots[fileNum].preprocessed = 1;
		}
	}
}

void romdataFileFree(s32 fileNum)
{
	if (fileNum < 1 || fileNum >= ROMDATA_MAX_FILES) {
		fprintf(stderr, "fsFileFree: invalid file num %d", fileNum);
		return;
	}

	if (!fileSlots[fileNum].external) {
		fprintf(stderr, "fsFileFree: file %d not external", fileNum);
		return;
	}

	free(fileSlots[fileNum].data);
	fileSlots[fileNum].data = NULL;
	fileSlots[fileNum].external = 0;
}

u8 *romdataSegGetData(const char *segName)
{
	return romdataGetSeg(segName)->data;
}

u8 *romdataSegGetDataEnd(const char *segName)
{
	struct romfile *seg = romdataGetSeg(segName);
	return seg->data + seg->size;
}

u32 romdataSegGetSize(const char *segName)
{
	return romdataGetSeg(segName)->size;
}
