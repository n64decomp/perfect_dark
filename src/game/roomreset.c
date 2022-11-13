#include <ultra64.h>
#include "constants.h"
#include "game/bg.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

void roomsReset(void)
{
	s32 i;

	var80082050 = PLAYERCOUNT() >= 2 ? 200 : 120;

	g_RoomMtxes = mempAlloc(ALIGN16(var80082050 * sizeof(struct roommtx)), MEMPOOL_STAGE);
	g_RoomMtxesUsed = NULL;
	g_RoomMtxesFree = g_RoomMtxes;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->lastroomforoffset = -1;
	}

	for (i = 0; i < var80082050; i++) {
		g_RoomMtxesFree[i].index = i;
		g_RoomMtxesFree[i].count = 2;
		g_RoomMtxesFree[i].room1 = -1;
		g_RoomMtxesFree[i].room2 = -1;
		g_RoomMtxesFree[i].somefloat = 1;
		g_RoomMtxesFree[i].next = &g_RoomMtxes[i + 1];
	}

	g_RoomMtxesFree[var80082050 - 1].next = NULL;

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_Rooms[i].unk10 = -1;
	}
}
