#include <ultra64.h>
#include "constants.h"
#include "game/room.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

struct roommtx *g_RoomMtxes;

s32 var80082050 = 0;
s32 g_NextRoomMtx = 0;

void roomSetLastForOffset(s32 room)
{
	g_Vars.currentplayer->lastroomforoffset = room;
}

void room0f1668f0(struct roommtx *roommtx, s32 roomnum)
{
	g_Rooms[roomnum].unk10[g_Vars.currentplayernum] = roommtx->index;
	roommtx->room1 = roomnum;
}

void room0f16692c(struct roommtx *roommtx, s32 roomnum)
{
	g_Rooms[roomnum].unk10[roommtx->playernum] = -1;
	roommtx->room1 = -1;
}

void room0f16696c(struct roommtx *roommtx)
{
	if (roommtx->room1 != -1) {
		room0f16692c(roommtx, roommtx->room1);
	}

	roommtx->lvframe = 0;
	roommtx->playernum = -1;
	roommtx->room2 = -1;
	roommtx->somefloat = 1;
}

/**
 * Find a free mtx and return it.
 */
struct roommtx *room0f1669fc(void)
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

void room0f166a6c(Mtxf *mtx, s32 roomnum)
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

struct roommtx *room0f166c20(s32 roomnum)
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

	if (index != -1) {
		room0f16692c(&g_RoomMtxes[index], roomnum);
	}

	roommtx = room0f1669fc();

	room0f1668f0(roommtx, roomnum);
	roommtx->lvframe = g_Vars.lvframenum;
	roommtx->playernum = g_Vars.currentplayernum;
	roommtx->room2 = g_Vars.currentplayer->lastroomforoffset;
	roommtx->somefloat = var8005ef10[0];

	room0f166a6c(&mtx, roomnum);
	mtx00016054(&mtx, &roommtx->mtx);

	return roommtx;
}

Gfx *roomPushMtx(Gfx *gdl, s32 roomnum)
{
	struct roommtx *roommtx = room0f166c20(roomnum);

	gSPMatrix(gdl++, &roommtx->mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	return gdl;
}

struct coord *roomGetPos(s32 room)
{
	return &g_BgRooms[room].pos;
}

void room0f166df0(s32 room, struct coord *globaldrawworldoffset)
{
	*globaldrawworldoffset = g_BgRooms[room].pos;
}
