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

	g_RoomMtxNumSlots = PLAYERCOUNT() >= 2 ? 200 : 120;

	g_RoomMtxAges = mempAlloc(ALIGN16(g_RoomMtxNumSlots), MEMPOOL_STAGE);
	g_RoomMtxLinkedRooms = mempAlloc(ALIGN16(g_RoomMtxNumSlots * sizeof(*g_RoomMtxLinkedRooms)), MEMPOOL_STAGE);
	g_RoomMtxBaseRooms = mempAlloc(ALIGN16(g_RoomMtxNumSlots * sizeof(*g_RoomMtxBaseRooms)), MEMPOOL_STAGE);
	g_RoomMtxScales = mempAlloc(ALIGN16(g_RoomMtxNumSlots * sizeof(*g_RoomMtxScales)), MEMPOOL_STAGE);
	g_RoomMtxMatrices = mempAlloc(ALIGN16(g_RoomMtxNumSlots * sizeof(*g_RoomMtxMatrices)), MEMPOOL_STAGE);

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->lastroomforoffset = -1;
	}

	for (i = 0; i < g_RoomMtxNumSlots; i++) {
		g_RoomMtxLinkedRooms[i] = -1;
		g_RoomMtxAges[i] = 2;
		g_RoomMtxBaseRooms[i] = -1;
		g_RoomMtxScales[i] = 1;
	}

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_Rooms[i].roommtxindex = -1;
	}
}
