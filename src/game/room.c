#include <ultra64.h>
#include "constants.h"
#include "game/room.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

struct roommtx *g_RoomMtxes;

s32 var80082050 = 0;

void roomSetLastForOffset(s32 room)
{
	g_Vars.currentplayer->lastroomforoffset = room;
}

void room0f1668f0(s32 index, s32 roomnum)
{
	g_Rooms[roomnum].unk10 = index;
	g_RoomMtxes[index].room1 = roomnum;
}

void room0f16692c(s32 index, s32 roomnum)
{
	g_Rooms[roomnum].unk10 = -1;
	g_RoomMtxes[index].room1 = -1;
}

void room0f16696c(s32 index)
{
	if (g_RoomMtxes[index].room1 != -1) {
		room0f16692c(index, g_RoomMtxes[index].room1);
	}

	g_RoomMtxes[index].count = 2;
	g_RoomMtxes[index].room2 = -1;
	g_RoomMtxes[index].somefloat = 1;
}

s32 room0f1669fc(void)
{
	s32 i;

	for (i = 0; i < var80082050; i++) {
		if (g_RoomMtxes[i].count > 1 && g_RoomMtxes[i].room2 == -1) {
			return i;
		}
	}

	return 0;
}

void room0f166a6c(Mtxf *mtx, s32 roomnum)
{
	s32 stagenum = g_Vars.stagenum;

	mtx4LoadIdentity(mtx);

	mtx->m[0][0] = 1;
	mtx->m[1][1] = 1;
	mtx->m[2][2] = 1;

	// These are rooms that are always active, such as the moon in Defection.
	// This is probably making those rooms always drawn a certain distance away
	// relative to the camera, so the moon never gets bigger as you go closer.
	if (((stagenum == g_Stages[STAGEINDEX_INFILTRATION].id
					|| stagenum == g_Stages[STAGEINDEX_RESCUE].id
					|| stagenum == g_Stages[STAGEINDEX_ESCAPE].id
					|| stagenum == g_Stages[STAGEINDEX_MAIANSOS].id) && roomnum == 0x0f)
			|| ((stagenum == g_Stages[STAGEINDEX_SKEDARRUINS].id
					|| stagenum == g_Stages[STAGEINDEX_WAR].id) && roomnum == 0x02)
			|| ((stagenum == g_Stages[STAGEINDEX_DEFECTION].id
					|| stagenum == g_Stages[STAGEINDEX_EXTRACTION].id
					|| stagenum == g_Stages[STAGEINDEX_MBR].id) && roomnum == 0x01)
			|| (stagenum == g_Stages[STAGEINDEX_ATTACKSHIP].id && roomnum == 0x71)) {
		mtx->m[3][0] = g_BgRooms[roomnum].pos.x;
		mtx->m[3][1] = g_BgRooms[roomnum].pos.y;
		mtx->m[3][2] = g_BgRooms[roomnum].pos.z;
	} else {
		mtx->m[3][0] = g_BgRooms[roomnum].pos.x - g_Vars.currentplayer->globaldrawworldoffset.x;
		mtx->m[3][1] = g_BgRooms[roomnum].pos.y - g_Vars.currentplayer->globaldrawworldoffset.y;
		mtx->m[3][2] = g_BgRooms[roomnum].pos.z - g_Vars.currentplayer->globaldrawworldoffset.z;
	}
}

s32 room0f166c20(s32 roomnum)
{
	s32 index = g_Rooms[roomnum].unk10;
	Mtxf mtx;

	if (index == -1
			|| g_Vars.currentplayer->lastroomforoffset != g_RoomMtxes[index].room2
			|| g_RoomMtxes[index].somefloat != var8005ef10[0]) {
		if (index != -1) {
			room0f16692c(index, roomnum);
		}

		index = room0f1669fc();

		room0f1668f0(index, roomnum);
		g_RoomMtxes[index].count = 0;
	} else {
		g_RoomMtxes[index].count = 0;
		return index;
	}

	g_RoomMtxes[index].room2 = g_Vars.currentplayer->lastroomforoffset;
	g_RoomMtxes[index].somefloat = var8005ef10[0];

	room0f166a6c(&mtx, roomnum);
	mtx00016054(&mtx, &g_RoomMtxes[index].mtx);

	return index;
}

Gfx *roomPushMtx(Gfx *gdl, s32 roomnum)
{
	s32 index = room0f166c20(roomnum);

	gSPMatrix(gdl++, &g_RoomMtxes[index].mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

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
