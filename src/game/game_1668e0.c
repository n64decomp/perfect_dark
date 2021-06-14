#include <ultra64.h>
#include "constants.h"
#include "game/game_1668e0.h"
#include "bss.h"
#include "lib/lib_159b0.h"
#include "data.h"
#include "types.h"

u8 *var800a6660;
s16 *var800a6664; // room numbers
s16 *var800a6668;
f32 *var800a666c;
Mtxf *var800a6670;

s32 var80082050 = 0;

void currentPlayerSetLastRoomForOffset(s32 room)
{
	g_Vars.currentplayer->lastroomforoffset = room;
}

void func0f1668f0(s32 index, s32 roomnum)
{
	g_Rooms[roomnum].unk10 = index;
	var800a6664[index] = roomnum;
}

void func0f16692c(s32 index, s32 roomnum)
{
	g_Rooms[roomnum].unk10 = -1;
	var800a6664[index] = -1;
}

void func0f16696c(s32 index)
{
	if (var800a6664[index] != -1) {
		func0f16692c(index, var800a6664[index]);
	}

	var800a6660[index] = 2;
	var800a6668[index] = -1;
	var800a666c[index] = 1;
}

s32 func0f1669fc(void)
{
	s32 i;

	for (i = 0; i < var80082050; i++) {
		if (var800a6660[i] > 1 && var800a6668[i] == -1) {
			return i;
		}
	}

	return 0;
}

void func0f166a6c(Mtxf *mtx, s32 roomnum)
{
	s32 stagenum = g_Vars.stagenum;

	func000159b0(mtx);

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

s32 func0f166c20(s32 roomnum)
{
	s32 index = g_Rooms[roomnum].unk10;
	Mtxf mtx;

	if (index == -1
			|| g_Vars.currentplayer->lastroomforoffset != var800a6668[index]
			|| var800a666c[index] != var8005ef10[0]) {
		if (index != -1) {
			func0f16692c(index, roomnum);
		}

		index = func0f1669fc();

		func0f1668f0(index, roomnum);
		var800a6660[index] = 0;
	} else {
		var800a6660[index] = 0;
		return index;
	}

	var800a6668[index] = g_Vars.currentplayer->lastroomforoffset;
	var800a666c[index] = var8005ef10[0];

	func0f166a6c(&mtx, roomnum);
	func00016054(&mtx, &var800a6670[index]);

	return index;
}

Gfx *func0f166d7c(Gfx *gdl, s32 roomnum)
{
	s32 index = func0f166c20(roomnum);

	gSPMatrix(gdl++, &var800a6670[index], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	return gdl;
}

struct coord *func0f166dd0(s32 room)
{
	return &g_BgRooms[room].pos;
}

void func0f166df0(s32 room, struct coord *globaldrawworldoffset)
{
	globaldrawworldoffset->x = g_BgRooms[room].pos.x;
	globaldrawworldoffset->y = g_BgRooms[room].pos.y;
	globaldrawworldoffset->z = g_BgRooms[room].pos.z;
}
