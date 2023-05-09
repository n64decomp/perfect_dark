#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

u16 *g_WallhitCountsPerRoom;
s32 g_WallhitsMax;
u32 var8009cc48;
u32 g_WallhitsNumFree;
u32 g_WallhitsNumUsed;
u32 var8009cc54;
u32 var8009cc58;
s32 g_MinPropWallhits;
u32 g_MaxPropWallhits;
s32 g_MinBgWallhitsPerRoom;
s32 g_MaxBgWallhitsPerRoom;
s32 var8009cc70;
s32 var8009cc74;
f32 g_WallhitTargetBloodRatio;

/**
 * Initialises an array of room numbers and a linked list of structs.
 *
 * Related to blood splats, bullet holes and scorch marks.
 * With this function nopped they do not appear.
 */
void wallhitReset(void)
{
	s32 stack;
	s32 type = 2;
	s32 i;

	if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) && PLAYERCOUNT() == 2) {
		type = 1;
	} else if (PLAYERCOUNT() >= 2) {
		type = 0;
	}

	switch (type) {
	case 0:
		// 4MB or MP with 2+ players
		g_WallhitsMax = 80;
		g_MinPropWallhits = 10;
		g_MaxPropWallhits = 40;
		g_MinBgWallhitsPerRoom = 1;
		g_MaxBgWallhitsPerRoom = 25;
		var8009cc70 = 5;
		var8009cc74 = 15;
		g_WallhitTargetBloodRatio = 0.3f;
		break;
	case 1:
		// 2 player coop/anti
		g_WallhitsMax = 200;
		g_MinPropWallhits = 25;
		g_MaxPropWallhits = 100;
		g_MinBgWallhitsPerRoom = 4;
		g_MaxBgWallhitsPerRoom = 40;
		var8009cc70 = 20;
		var8009cc74 = 30;
		g_WallhitTargetBloodRatio = 0.4f;
		break;
	case 2:
	default:
		// 1 player 8MB
		g_WallhitsMax = 360;
		g_MinPropWallhits = 50;
		g_MaxPropWallhits = 120;
		g_MinBgWallhitsPerRoom = 10;
		g_MaxBgWallhitsPerRoom = 60;
		var8009cc70 = 25;
		var8009cc74 = 40;
		g_WallhitTargetBloodRatio = 0.5f;
		break;
	}

	g_WallhitCountsPerRoom = NULL;
	var8009cc48 = 0;
	g_WallhitsNumFree = 0;
	g_WallhitsNumUsed = 0;
	var8009cc54 = 0;
	var8009cc58 = 0;

	if (g_Vars.stagenum >= STAGE_TITLE) {
		g_WallhitsMax = 0;
	}

	if (g_WallhitsMax == 0) {
		g_Wallhits = NULL;
	} else {
		// Allocate an array of s16 room numbers followed by a bunch of structs
		u32 numberssize;
		u32 structssize;
		void *ptr;

		structssize = g_WallhitsMax * sizeof(struct wallhit);
		structssize += 0xf;
		structssize &= ~0xf;

		numberssize = g_Vars.roomcount * 2;
		numberssize += 0xf;
		numberssize &= ~0xf;

		ptr = mempAlloc(structssize + numberssize, MEMPOOL_STAGE);

		g_WallhitCountsPerRoom = ptr;
		g_Wallhits = (struct wallhit *)((u32)ptr + numberssize);
		g_FreeWallhits = NULL;
		g_ActiveWallhits = 0;
		g_BusyWallhits = NULL;

		// Initialise structs
		for (i = 0; i < g_WallhitsMax; i++) {
			g_Wallhits[i].timermax = 0;
			g_Wallhits[i].timercur = 0;
			g_Wallhits[i].createdframe = 0;
			g_Wallhits[i].inuse = false;
			g_Wallhits[i].roomnum = -1;
			g_Wallhits[i].chrprop = NULL;
			g_Wallhits[i].objprop = NULL;

			g_WallhitsNumFree++;

			g_Wallhits[i].globalnext = g_FreeWallhits;
			g_FreeWallhits = &g_Wallhits[i];
		}

		// Initialise room numbers
		for (i = 0; i < g_Vars.roomcount; i++) {
			g_WallhitCountsPerRoom[i] = 0;
		}
	}
}
