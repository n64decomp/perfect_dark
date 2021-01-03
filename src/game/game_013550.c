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

GLOBAL_ASM(
glabel func0f0139f0
/*  f0139f0:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0139f4:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0139f8:	8cae006c */ 	lw	$t6,0x6c($a1)
/*  f0139fc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f013a00:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013a04:	11c00003 */ 	beqz	$t6,.L0f013a14
/*  f013a08:	3c06800a */ 	lui	$a2,%hi(var800a45c0)
/*  f013a0c:	10000002 */ 	b	.L0f013a18
/*  f013a10:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f013a14:
/*  f013a14:	00003825 */ 	or	$a3,$zero,$zero
.L0f013a18:
/*  f013a18:	8caf0068 */ 	lw	$t7,0x68($a1)
/*  f013a1c:	24c645c0 */ 	addiu	$a2,$a2,%lo(var800a45c0)
/*  f013a20:	240b00c8 */ 	addiu	$t3,$zero,0xc8
/*  f013a24:	11e00003 */ 	beqz	$t7,.L0f013a34
/*  f013a28:	3c0d8009 */ 	lui	$t5,%hi(g_Is4Mb)
/*  f013a2c:	10000002 */ 	b	.L0f013a38
/*  f013a30:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f013a34:
/*  f013a34:	00001825 */ 	or	$v1,$zero,$zero
.L0f013a38:
/*  f013a38:	8cb80064 */ 	lw	$t8,0x64($a1)
/*  f013a3c:	00002025 */ 	or	$a0,$zero,$zero
/*  f013a40:	00001025 */ 	or	$v0,$zero,$zero
/*  f013a44:	13000003 */ 	beqz	$t8,.L0f013a54
/*  f013a48:	00000000 */ 	nop
/*  f013a4c:	10000001 */ 	b	.L0f013a54
/*  f013a50:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f013a54:
/*  f013a54:	8cb90070 */ 	lw	$t9,0x70($a1)
/*  f013a58:	13200003 */ 	beqz	$t9,.L0f013a68
/*  f013a5c:	00000000 */ 	nop
/*  f013a60:	10000001 */ 	b	.L0f013a68
/*  f013a64:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f013a68:
/*  f013a68:	00444021 */ 	addu	$t0,$v0,$a0
/*  f013a6c:	01034821 */ 	addu	$t1,$t0,$v1
/*  f013a70:	01275021 */ 	addu	$t2,$t1,$a3
/*  f013a74:	016a001a */ 	div	$zero,$t3,$t2
/*  f013a78:	15400002 */ 	bnez	$t2,.L0f013a84
/*  f013a7c:	00000000 */ 	nop
/*  f013a80:	0007000d */ 	break	0x7
.L0f013a84:
/*  f013a84:	2401ffff */ 	addiu	$at,$zero,-1
/*  f013a88:	15410004 */ 	bne	$t2,$at,.L0f013a9c
/*  f013a8c:	3c018000 */ 	lui	$at,0x8000
/*  f013a90:	15610002 */ 	bne	$t3,$at,.L0f013a9c
/*  f013a94:	00000000 */ 	nop
/*  f013a98:	0006000d */ 	break	0x6
.L0f013a9c:
/*  f013a9c:	00006012 */ 	mflo	$t4
/*  f013aa0:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f013aa4:	91ad0af0 */ 	lbu	$t5,%lo(g_Is4Mb)($t5)
/*  f013aa8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f013aac:	01807025 */ 	or	$t6,$t4,$zero
/*  f013ab0:	15a10006 */ 	bne	$t5,$at,.L0f013acc
/*  f013ab4:	3c04800a */ 	lui	$a0,%hi(var800a45c4)
/*  f013ab8:	05c10003 */ 	bgez	$t6,.L0f013ac8
/*  f013abc:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f013ac0:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f013ac4:	00017843 */ 	sra	$t7,$at,0x1
.L0f013ac8:
/*  f013ac8:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f013acc:
/*  f013acc:	8cb804b4 */ 	lw	$t8,0x4b4($a1)
/*  f013ad0:	248445c4 */ 	addiu	$a0,$a0,%lo(var800a45c4)
/*  f013ad4:	2b01005a */ 	slti	$at,$t8,0x5a
/*  f013ad8:	54200003 */ 	bnezl	$at,.L0f013ae8
/*  f013adc:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f013ae0:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f013ae4:	8cc20000 */ 	lw	$v0,0x0($a2)
.L0f013ae8:
/*  f013ae8:	54400004 */ 	bnezl	$v0,.L0f013afc
/*  f013aec:	000220c0 */ 	sll	$a0,$v0,0x3
/*  f013af0:	1000001e */ 	b	.L0f013b6c
/*  f013af4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f013af8:	000220c0 */ 	sll	$a0,$v0,0x3
.L0f013afc:
/*  f013afc:	00822023 */ 	subu	$a0,$a0,$v0
/*  f013b00:	00042080 */ 	sll	$a0,$a0,0x2
/*  f013b04:	00822023 */ 	subu	$a0,$a0,$v0
/*  f013b08:	00042080 */ 	sll	$a0,$a0,0x2
/*  f013b0c:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f013b10:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f013b14:	0081c824 */ 	and	$t9,$a0,$at
/*  f013b18:	03202025 */ 	or	$a0,$t9,$zero
/*  f013b1c:	0c0048f2 */ 	jal	malloc
/*  f013b20:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f013b24:	3c06800a */ 	lui	$a2,%hi(var800a45c0)
/*  f013b28:	24c645c0 */ 	addiu	$a2,$a2,%lo(var800a45c0)
/*  f013b2c:	8cc80000 */ 	lw	$t0,0x0($a2)
/*  f013b30:	3c04800a */ 	lui	$a0,%hi(var800a45c4)
/*  f013b34:	248445c4 */ 	addiu	$a0,$a0,%lo(var800a45c4)
/*  f013b38:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f013b3c:	1900000b */ 	blez	$t0,.L0f013b6c
/*  f013b40:	00001825 */ 	or	$v1,$zero,$zero
/*  f013b44:	00001025 */ 	or	$v0,$zero,$zero
/*  f013b48:	8c890000 */ 	lw	$t1,0x0($a0)
.L0f013b4c:
/*  f013b4c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f013b50:	01225821 */ 	addu	$t3,$t1,$v0
/*  f013b54:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f013b58:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f013b5c:	2442006c */ 	addiu	$v0,$v0,0x6c
/*  f013b60:	006a082a */ 	slt	$at,$v1,$t2
/*  f013b64:	5420fff9 */ 	bnezl	$at,.L0f013b4c
/*  f013b68:	8c890000 */ 	lw	$t1,0x0($a0)
.L0f013b6c:
/*  f013b6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f013b70:	3c018008 */ 	lui	$at,%hi(var8007fa80)
/*  f013b74:	ac20fa80 */ 	sw	$zero,%lo(var8007fa80)($at)
/*  f013b78:	03e00008 */ 	jr	$ra
/*  f013b7c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

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
