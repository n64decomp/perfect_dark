#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_096890.h"
#include "gvars/gvars.h"
#include "types.h"

s32 func0f096890(s32 arg0)
{
	u16 *array;
	s32 shiftamount;
	s32 mask;
	s32 index;
	s32 value;
	s32 nextvalue;

	if (arg0 >= 32736) {
		mask = 0x07;
		shiftamount = 3;
		array = var8006af8c;
		arg0 -= 32736;
	} else if (arg0 >= 30720) {
		mask = 0x1f;
		shiftamount = 5;
		array = var8006af0c;
		arg0 -= 30720;
	} else {
		mask = 0x1ff;
		shiftamount = 9;
		array = var8006ae90;
	}

	index = arg0 >> shiftamount;
	value = array[index];
	nextvalue = array[index + 1];

	return value - (((value - nextvalue) * (arg0 & mask)) >> shiftamount);
}

GLOBAL_ASM(
glabel func0f096910
/*  f096910:	00042c00 */ 	sll	$a1,$a0,0x10
/*  f096914:	00057403 */ 	sra	$t6,$a1,0x10
/*  f096918:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f09691c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f096920:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f096924:	05c00003 */ 	bltz	$t6,.L0f096934
/*  f096928:	01c02825 */ 	or	$a1,$t6,$zero
/*  f09692c:	10000002 */ 	b	.L0f096938
/*  f096930:	01c02025 */ 	or	$a0,$t6,$zero
.L0f096934:
/*  f096934:	00052023 */ 	negu	$a0,$a1
.L0f096938:
/*  f096938:	0fc25a24 */ 	jal	func0f096890
/*  f09693c:	a7a5001a */ 	sh	$a1,0x1a($sp)
/*  f096940:	87a5001a */ 	lh	$a1,0x1a($sp)
/*  f096944:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f096948:	00402025 */ 	or	$a0,$v0,$zero
/*  f09694c:	04a10003 */ 	bgez	$a1,.L0f09695c
/*  f096950:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f096954:	340fffff */ 	dli	$t7,0xffff
/*  f096958:	01e22023 */ 	subu	$a0,$t7,$v0
.L0f09695c:
/*  f09695c:	03e00008 */ 	jr	$ra
/*  f096960:	3082ffff */ 	andi	$v0,$a0,0xffff
);

GLOBAL_ASM(
glabel func0f096964
/*  f096964:	00042c00 */ 	sll	$a1,$a0,0x10
/*  f096968:	00057403 */ 	sra	$t6,$a1,0x10
/*  f09696c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f096970:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f096974:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f096978:	05c00003 */ 	bltz	$t6,.L0f096988
/*  f09697c:	01c02825 */ 	or	$a1,$t6,$zero
/*  f096980:	10000002 */ 	b	.L0f09698c
/*  f096984:	01c02025 */ 	or	$a0,$t6,$zero
.L0f096988:
/*  f096988:	00052023 */ 	negu	$a0,$a1
.L0f09698c:
/*  f09698c:	0fc25a24 */ 	jal	func0f096890
/*  f096990:	a7a5001a */ 	sh	$a1,0x1a($sp)
/*  f096994:	87a5001a */ 	lh	$a1,0x1a($sp)
/*  f096998:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09699c:	24018000 */ 	addiu	$at,$zero,-32768
/*  f0969a0:	04a00004 */ 	bltz	$a1,.L0f0969b4
/*  f0969a4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0969a8:	240f7fff */ 	addiu	$t7,$zero,0x7fff
/*  f0969ac:	10000002 */ 	b	.L0f0969b8
/*  f0969b0:	01e22023 */ 	subu	$a0,$t7,$v0
.L0f0969b4:
/*  f0969b4:	00412021 */ 	addu	$a0,$v0,$at
.L0f0969b8:
/*  f0969b8:	00041400 */ 	sll	$v0,$a0,0x10
/*  f0969bc:	0002c403 */ 	sra	$t8,$v0,0x10
/*  f0969c0:	03e00008 */ 	jr	$ra
/*  f0969c4:	03001025 */ 	or	$v0,$t8,$zero
/*  f0969c8:	00000000 */ 	nop
/*  f0969cc:	00000000 */ 	nop
);
