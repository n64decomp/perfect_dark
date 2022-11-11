#include <ultra64.h>
#include "constants.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

extern u8 *g_LangBuffer;
extern s32 g_LangBufferSize;

void langReset(s32 stagenum)
{
	s32 i;
	s32 size;

	for (i = 0; i < ARRAYCOUNT(g_LangBanks); i++) {
		g_LangBanks[i] = NULL;
	}

	g_LangBanks[LANGBANK_GUN] = fileLoadToNew(langGetFileId(LANGBANK_GUN), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_MPMENU] = fileLoadToNew(langGetFileId(LANGBANK_MPMENU), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_PROPOBJ] = fileLoadToNew(langGetFileId(LANGBANK_PROPOBJ), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_MPWEAPONS] = fileLoadToNew(langGetFileId(LANGBANK_MPWEAPONS), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_OPTIONS] = fileLoadToNew(langGetFileId(LANGBANK_OPTIONS), FILELOADMETHOD_DEFAULT);
	g_LangBanks[LANGBANK_MISC] = fileLoadToNew(langGetFileId(LANGBANK_MISC), FILELOADMETHOD_DEFAULT);

	if (stagenum == STAGE_CREDITS) {
		g_LangBanks[LANGBANK_TITLE] = fileLoadToNew(langGetFileId(LANGBANK_TITLE), FILELOADMETHOD_DEFAULT);
	}
}
