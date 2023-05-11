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
	g_RoomMtxMtxes = UNCACHED(mempAlloc(ALIGN16(var80082050 * sizeof(Mtx)), MEMPOOL_STAGE));
	g_NextRoomMtx = 0;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->lastroomforoffset = -1;
	}

	for (i = 0; i < var80082050; i++) {
		g_RoomMtxes[i].index = i;
		g_RoomMtxes[i].playernum = -1;
		g_RoomMtxes[i].lvframe = -10;
		g_RoomMtxes[i].room1 = -1;
		g_RoomMtxes[i].room2 = -1;
		g_RoomMtxes[i].somefloat = 1;
	}

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_Rooms[i].unk10[0] = -1;
		g_Rooms[i].unk10[1] = -1;
		g_Rooms[i].unk10[2] = -1;
		g_Rooms[i].unk10[3] = -1;
	}
}
