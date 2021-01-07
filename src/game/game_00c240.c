#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_00c240.h"
#include "game/game_0601b0.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "types.h"

void gvarsInitProps(void)
{
	s32 i;

	g_Vars.props = malloc(ALIGN64(g_Vars.maxprops * sizeof(struct prop)), MEMPOOL_STAGE);
	g_Vars.tangibleprops = malloc(ALIGN64(200 * sizeof(void *)), MEMPOOL_STAGE);

	var80069880 = 1;

	g_Vars.unk00033c = NULL;
	g_Vars.unk000340 = NULL;
	g_Vars.unk000354 = g_Vars.unk000350 = NULL;

	g_Vars.tangibleprops[0] = NULL;

	g_Vars.unk00034c = g_Vars.tangibleprops;
	g_Vars.freeprops = g_Vars.props;

	for (i = 0; i < g_Vars.maxprops - 1; i++) {
		g_Vars.props[i].next = &g_Vars.props[i + 1];
	}

	func0f00c390();

	if (g_Vars.normmplayerisrunning) {
		g_Vars.numpropstateindexes = 4;
	} else {
		g_Vars.numpropstateindexes = 7;
	}

	g_Vars.nextpropstateindex = 0;
	g_Vars.unk00035a = 0;
	g_Vars.unk00035b = 0;
	g_Vars.unk00035c = 0xfffe;
	g_Vars.unk00035e = 0xffff;

	for (i = 0; i < ARRAYCOUNT(g_Vars.propstates); i++) {
		g_Vars.propstates[i].propcount = 0;
		g_Vars.propstates[i].chrpropcount = 0;
		g_Vars.propstates[i].updatetime = 0;
		g_Vars.propstates[i].chrupdatetime = 0;
		g_Vars.propstates[i].slotupdate240 = 0;
		g_Vars.propstates[i].slotupdate60error = 2;
	}
}

void func0f00c390(void)
{
	s32 i;
	s32 j;

	var8009cda0 = malloc(ALIGN16(g_Vars.roomcount * 2), MEMPOOL_STAGE);
	var8009cda4 = malloc(256 * sizeof(struct var8009cda4), MEMPOOL_STAGE);

	for (i = 0; i < g_Vars.roomcount; i++) {
		var8009cda0[i] = -1;
	}

	for (i = 0; i < 256; i++) {
		var8009cda4[i].unk00[0] = -2;

		for (j = 1; j < ARRAYCOUNT(var8009cda4[i].unk00); j++) {
			var8009cda4[i].unk00[j] = -1;
		}
	}
}
