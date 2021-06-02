#include <ultra64.h>
#include "constants.h"
#include "game/game_00c240.h"
#include "game/prop.h"
#include "bss.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

void gvarsInitProps(void)
{
	s32 i;

	g_Vars.props = malloc(ALIGN64(g_Vars.maxprops * sizeof(struct prop)), MEMPOOL_STAGE);
	g_Vars.onscreenprops = malloc(ALIGN64(200 * sizeof(void *)), MEMPOOL_STAGE);

	var80069880 = 1;

	g_Vars.activeprops = g_Vars.activepropstail = NULL;
	g_Vars.pausedprops = NULL;

	g_Vars.numonscreenprops = 0;
	g_Vars.onscreenprops[0] = NULL;
	g_Vars.endonscreenprops = g_Vars.onscreenprops;

	g_Vars.freeprops = g_Vars.props;

	for (i = 0; i < g_Vars.maxprops - 1; i++) {
		g_Vars.props[i].next = &g_Vars.props[i + 1];
	}

	gvarsInitRoomProps();

	if (g_Vars.normmplayerisrunning) {
		g_Vars.numpropstates = 4;
	} else {
		g_Vars.numpropstates = 7;
	}

	g_Vars.allocstateindex = 0;
	g_Vars.runstateindex = 0;
	g_Vars.alwaystick = 0;
	g_Vars.updateframe = 0xfffe;
	g_Vars.prevupdateframe = 0xffff;

	for (i = 0; i < ARRAYCOUNT(g_Vars.propstates); i++) {
		g_Vars.propstates[i].propcount = 0;
		g_Vars.propstates[i].chrpropcount = 0;
		g_Vars.propstates[i].updatetime = 0;
		g_Vars.propstates[i].chrupdatetime = 0;
		g_Vars.propstates[i].slotupdate240 = 0;
		g_Vars.propstates[i].slotupdate60error = 2;
	}
}

void gvarsInitRoomProps(void)
{
	s32 i;
	s32 j;

	g_RoomPropListChunkIndexes = malloc(ALIGN16(g_Vars.roomcount * sizeof(s16)), MEMPOOL_STAGE);
	g_RoomPropListChunks = malloc(256 * sizeof(struct roomproplistchunk), MEMPOOL_STAGE);

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_RoomPropListChunkIndexes[i] = -1;
	}

	for (i = 0; i < 256; i++) {
		g_RoomPropListChunks[i].propnums[0] = -2;

		for (j = 1; j < ARRAYCOUNT(g_RoomPropListChunks[i].propnums); j++) {
			g_RoomPropListChunks[i].propnums[j] = -1;
		}
	}
}
