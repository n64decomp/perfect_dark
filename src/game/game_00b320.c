#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_166e40.h"
#include "game/lang.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "types.h"

void stageLoadCommonLang(s32 stagenum)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_LangBanks); i++) {
		g_LangBanks[i] = NULL;
	}

	g_LangBanks[LANGBANK_GUN] = func0f1670fc(langGetFileId(LANGBANK_GUN), 0x22);
	g_LangBanks[LANGBANK_MPMENU] = func0f1670fc(langGetFileId(LANGBANK_MPMENU), 0x22);
	g_LangBanks[LANGBANK_PROPOBJ] = func0f1670fc(langGetFileId(LANGBANK_PROPOBJ), 0x22);
	g_LangBanks[LANGBANK_MPWEAPONS] = func0f1670fc(langGetFileId(LANGBANK_MPWEAPONS), 0x22);
	g_LangBanks[LANGBANK_OPTIONS] = func0f1670fc(langGetFileId(LANGBANK_OPTIONS), 0x22);
	g_LangBanks[LANGBANK_MISC] = func0f1670fc(langGetFileId(LANGBANK_MISC), 0x22);

	if (stagenum == STAGE_CREDITS) {
		g_LangBanks[LANGBANK_TITLE] = func0f1670fc(langGetFileId(LANGBANK_TITLE), 0x22);
	}
}

void func0f00b420(void)
{
	var80062410 = 0;
	var8009cc80 = malloc(0x80, MEMPOOL_STAGE);
	var8009cc84 = malloc(0x80, MEMPOOL_STAGE);
	var8009cc88 = malloc(0x80, MEMPOOL_STAGE);
}
