#include <ultra64.h>
#include "constants.h"
#include "game/room.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

struct roommtx *g_RoomMtxes;
Mtx *g_RoomMtxMtxes;

s32 var80082050 = 0;
s32 g_NextRoomMtx = 0;

/**
 * Find a free mtx and return it.
 */
static struct roommtx *roomAllocateMtx(void)
{
	s32 i;

	for (i = 0; i < var80082050; i++) {
		struct roommtx *roommtx = &g_RoomMtxes[g_NextRoomMtx];

		g_NextRoomMtx++;

		if (g_NextRoomMtx == var80082050) {
			g_NextRoomMtx = 0;
		}

		if (roommtx->lvframe < g_Vars.lvframenum - 2) {
			return roommtx;
		}
	}

	return &g_RoomMtxes[0];
}

void roomPopulateMtx(Mtxf *mtx, s32 roomnum)
{
	mtx4LoadIdentity(mtx);

	if (roomnum == g_BgAlwaysRoom) {
		mtx->m[3][0] = g_BgRooms[roomnum].pos.x;
		mtx->m[3][1] = g_BgRooms[roomnum].pos.y;
		mtx->m[3][2] = g_BgRooms[roomnum].pos.z;
	} else {
		mtx->m[3][0] = g_BgRooms[roomnum].pos.x - g_Vars.currentplayer->globaldrawworldoffset.x;
		mtx->m[3][1] = g_BgRooms[roomnum].pos.y - g_Vars.currentplayer->globaldrawworldoffset.y;
		mtx->m[3][2] = g_BgRooms[roomnum].pos.z - g_Vars.currentplayer->globaldrawworldoffset.z;
	}
}

static struct roommtx *roomTouchMtx(s32 roomnum)
{
	s32 index = g_Rooms[roomnum].unk10[g_Vars.currentplayernum];
	struct roommtx *roommtx;
	Mtxf mtx;

	if (index != -1
			&& g_Vars.currentplayer->lastroomforoffset == g_RoomMtxes[index].room2
			&& g_RoomMtxes[index].somefloat == var8005ef10[0]) {
		roommtx = &g_RoomMtxes[index];
		roommtx->lvframe = g_Vars.lvframenum;
		return roommtx;
	}

	roommtx = roomAllocateMtx();

	if (roommtx->room1 != -1) {
		g_Rooms[roommtx->room1].unk10[roommtx->playernum] = -1;
		roommtx->room1 = -1;
	}

	g_Rooms[roomnum].unk10[g_Vars.currentplayernum] = roommtx->index;

	roommtx->room1 = roomnum;
	roommtx->lvframe = g_Vars.lvframenum;
	roommtx->playernum = g_Vars.currentplayernum;
	roommtx->room2 = g_Vars.currentplayer->lastroomforoffset;
	roommtx->somefloat = var8005ef10[0];

	roomPopulateMtx(&mtx, roomnum);
	mtx00016054(&mtx, (void *) &g_RoomMtxMtxes[roommtx->index]);

	return roommtx;
}

Gfx *roomApplyMtx(Gfx *gdl, s32 roomnum)
{
	struct roommtx *roommtx = roomTouchMtx(roomnum);

	gSPMatrix(gdl++, &g_RoomMtxMtxes[roommtx->index], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	return gdl;
}
