#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

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

		ptr = malloc(structssize + numberssize, 4);

		var8009cc40 = ptr;
		var800a41b0 = (struct var800a41b0 *)((u32)ptr + numberssize);
		var800a41b4 = NULL;
		var800a41b8 = 0;

		// Initialise structs
		for (i = 0; i < var8009cc44; i++) {
			var800a41b0[i].unk6d = 0;
			var800a41b0[i].unk6e = 0;
			var800a41b0[i].unk70 = var800a41b0[i].unk70 ^ ((var800a41b0[i].unk70 >> 4) << 4);
			var800a41b0[i].unk6f &= 0xff7f;
			var800a41b0[i].unk68 = -1;
			var800a41b0[i].unk5c = 0;
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

void func0f0139f0(void)
{
	s32 i;

	var800a45c0 = 200 / PLAYERCOUNT();

	if (IS4MB()) {
		var800a45c0 = var800a45c0 / 2;
	}

	if (g_Vars.stagenum >= STAGE_TITLE) {
		var800a45c0 = 0;
	}

	if (var800a45c0 == 0) {
		var800a45c4 = 0;
	} else {
		var800a45c4 = malloc(var800a45c0 * sizeof(struct var800a45c4) + 0xf & ~0xf, 4);

		for (i = 0; i < var800a45c0; i++) {
			var800a45c4[i].unk04 = 0;
		}
	}

	var8007fa80 = 0;
}

void func0f013b80(void)
{
	var800ab538 = 0;
	var800aabc8[0] = 0;
	var800aabc8[1] = 0;
	var800aabc8[3] = 0;
}

void func0f013ba0(void)
{
	s32 i;
	s32 j;
	s32 num;
	s32 val;

	for (i = 0; i < 4; i++) {
		if (PLAYERCOUNT() >= 2) {
			val = var8007e3d0[i].valifmp;
			num = var8007e3d0[i].numifmp;
		} else if (g_Vars.stagenum >= STAGE_TITLE) {
			val = var8007e3d0[i].valifspecial;
			num = var8007e3d0[i].numifspecial;
		} else {
			val = var8007e3d0[i].valifsp;
			num = var8007e3d0[i].numifsp;
		}

		if (num > 0) {
			var8007e3d0[i].unk24 = malloc(num * sizeof(struct var8007e3d0_data), 4);
		}

		for (j = 0; j < num; j++) {
			var8007e3d0[i].unk24[j].unk0e = 0;
		}

		var8007e3d0[i].numallocated = num;
		var8007e3d0[i].val1 = val;
		var8007e3d0[i].val2 = val;
	}
}
