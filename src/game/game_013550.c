#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

u16 *var8009cc40;
s32 var8009cc44;
u32 var8009cc48;
u32 var8009cc4c;
u32 var8009cc50;
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
void func0f013550(void)
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
		var8009cc44 = 80;
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
		var8009cc44 = 200;
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
		var8009cc44 = 360;
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
	var8009cc4c = 0;
	var8009cc50 = 0;
	var8009cc54 = 0;
	var8009cc58 = 0;

	if (g_Vars.stagenum >= STAGE_TITLE) {
		var8009cc44 = 0;
	}

	if (var8009cc44 == 0) {
		var800a41b0 = NULL;
	} else {
		// Allocate an array of s16 room numbers followed by a bunch of structs
		u32 numberssize;
		u32 structssize;
		void *ptr;

		structssize = var8009cc44 * sizeof(struct var800a41b0);
		structssize += 0xf;
		structssize &= ~0xf;

		numberssize = g_Vars.roomcount * 2;
		numberssize += 0xf;
		numberssize &= ~0xf;

		ptr = malloc(structssize + numberssize, MEMPOOL_STAGE);

		var8009cc40 = ptr;
		var800a41b0 = (struct var800a41b0 *)((u32)ptr + numberssize);
		var800a41b4 = NULL;
		var800a41b8 = 0;

		// Initialise structs
		for (i = 0; i < var8009cc44; i++) {
			var800a41b0[i].unk6d = 0;
			var800a41b0[i].unk6e = 0;
			var800a41b0[i].unk70_00 = 0;
			var800a41b0[i].unk6f_00 = 0;
			var800a41b0[i].unk68 = -1;
			var800a41b0[i].prop = NULL;
			var800a41b0[i].unk60 = 0;

			var8009cc4c++;
			var800a41b0[i].prev = var800a41b4;
			var800a41b4 = &var800a41b0[i];
		}

		// Initialise room numbers
		for (i = 0; i < g_Vars.roomcount; i++) {
			var8009cc40[i] = 0;
		}
	}
}
