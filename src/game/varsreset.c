#include <ultra64.h>
#include "constants.h"
#include "game/prop.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/vars.h"
#include "data.h"
#include "types.h"

void vars_reset_room_props(void);

void vars_reset(void)
{
	s32 i;

	g_Vars.props = memp_alloc(ALIGN64(g_Vars.maxprops * sizeof(struct prop)), MEMPOOL_STAGE);
	g_Vars.onscreenprops = memp_alloc(ALIGN64(200 * sizeof(void *)), MEMPOOL_STAGE);

	g_AutoAimScale = 1;

	g_Vars.activeprops = g_Vars.activepropstail = NULL;
	g_Vars.pausedprops = NULL;

	g_Vars.numonscreenprops = 0;
	g_Vars.onscreenprops[0] = NULL;
	g_Vars.endonscreenprops = g_Vars.onscreenprops;

	g_Vars.freeprops = g_Vars.props;

	// @bug: The tail of the freeprops list will have an uninitialised next pointer.
	// This will likely crash the game if too many props get allocated,
	// but there is no known way to exhaust the free props list.
	for (i = 0; i < g_Vars.maxprops - 1; i++) {
		g_Vars.props[i].next = &g_Vars.props[i + 1];
	}

	vars_reset_room_props();

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

void vars_reset_room_props(void)
{
	s32 i;
	s32 j;

	g_RoomPropListChunkIndexes = memp_alloc(ALIGN16(g_Vars.roomcount * sizeof(s16)), MEMPOOL_STAGE);
	g_RoomPropListChunks = memp_alloc(MAX_ROOMPROPLISTCHUNKS * sizeof(struct roomproplistchunk), MEMPOOL_STAGE);

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_RoomPropListChunkIndexes[i] = -1;
	}

	for (i = 0; i < MAX_ROOMPROPLISTCHUNKS; i++) {
		g_RoomPropListChunks[i].propnums[0] = -2;

		for (j = 1; j < ARRAYCOUNT(g_RoomPropListChunks[i].propnums); j++) {
			g_RoomPropListChunks[i].propnums[j] = -1;
		}
	}
}
