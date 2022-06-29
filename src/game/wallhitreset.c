#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

u16 *var8009cc40;
s32 g_WallhitsMax;
u32 var8009cc48;
u32 g_WallhitsNumFree;
u32 g_WallhitsNumUsed;
u32 var8009cc54;
u32 var8009cc58;
u32 var8009cc5c;
u32 var8009cc60;
s32 var8009cc64;
u32 var8009cc68;
u32 var8009cc6c;
u32 var8009cc70;
u32 var8009cc74;
f32 var8009cc78;

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

	if (IS4MB()) {
		type = 0;
	} else if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) && PLAYERCOUNT() == 2) {
		type = 1;
	} else if (PLAYERCOUNT() >= 2) {
		type = 0;
	}

	switch (type) {
	case 0:
		// 4MB or MP with 2+ players
		g_WallhitsMax = 80;
		var8009cc5c = 10;
		var8009cc60 = 40;
		var8009cc64 = 1;
		var8009cc68 = 25;
		var8009cc6c = 20;
		var8009cc70 = 5;
		var8009cc74 = 15;
		var8009cc78 = 0.3f;
		break;
	case 1:
		// 2 player coop/anti
		g_WallhitsMax = 200;
		var8009cc5c = 25;
		var8009cc60 = 100;
		var8009cc64 = 4;
		var8009cc68 = 40;
		var8009cc6c = 80;
		var8009cc70 = 20;
		var8009cc74 = 30;
		var8009cc78 = 0.4f;
		break;
	case 2:
	default:
		// 1 player 8MB
		g_WallhitsMax = 360;
		var8009cc5c = 50;
		var8009cc60 = 120;
		var8009cc64 = 10;
		var8009cc68 = 60; // max bullet holes
		var8009cc6c = 180;
		var8009cc70 = 25;
		var8009cc74 = 40;
		var8009cc78 = 0.5f;
		break;
	}

	var8009cc40 = 0;
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

		var8009cc40 = ptr;
		g_Wallhits = (struct wallhit *)((u32)ptr + numberssize);
		var800a41b4 = NULL;
		var800a41b8 = 0;

		// Initialise structs
		for (i = 0; i < g_WallhitsMax; i++) {
			g_Wallhits[i].unk6d = 0;
			g_Wallhits[i].unk6e = 0;
			g_Wallhits[i].unk70_00 = 0;
			g_Wallhits[i].inuse = false;
			g_Wallhits[i].roomnum = -1;
			g_Wallhits[i].prop = NULL;
			g_Wallhits[i].prop60 = NULL;

			g_WallhitsNumFree++;

			g_Wallhits[i].globalnext = var800a41b4;
			var800a41b4 = &g_Wallhits[i];
		}

		// Initialise room numbers
		for (i = 0; i < g_Vars.roomcount; i++) {
			var8009cc40[i] = 0;
		}
	}
}
