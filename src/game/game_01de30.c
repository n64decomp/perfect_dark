#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

const u32 var7f1a8670[] = {0x46ea6000};
const u32 var7f1a8674[] = {0xc6ea6000};
const u32 var7f1a8678[] = {0x3dcccccd};
const u32 var7f1a867c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f01de30
/*  f01de30:	3c088008 */ 	lui	$t0,%hi(var8007fa84)
/*  f01de34:	2508fa84 */ 	addiu	$t0,$t0,%lo(var8007fa84)
/*  f01de38:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f01de3c:	3c09800a */ 	lui	$t1,%hi(var800a45c0)
/*  f01de40:	252945c0 */ 	addiu	$t1,$t1,%lo(var800a45c0)
/*  f01de44:	11c0007d */ 	beqz	$t6,.L0f01e03c
/*  f01de48:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x38)
/*  f01de4c:	8c429ff8 */ 	lw	$v0,%lo(g_Vars+0x38)($v0)
/*  f01de50:	00001825 */ 	or	$v1,$zero,$zero
/*  f01de54:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f01de58:	2841000f */ 	slti	$at,$v0,0xf
/*  f01de5c:	10200004 */ 	beqz	$at,.L0f01de70
/*  f01de60:	3c0a800a */ 	lui	$t2,%hi(var800a45c4)
/*  f01de64:	44822000 */ 	mtc1	$v0,$f4
/*  f01de68:	10000004 */ 	beqz	$zero,.L0f01de7c
/*  f01de6c:	46802020 */ 	cvt.s.w	$f0,$f4
.L0f01de70:
/*  f01de70:	3c014170 */ 	lui	$at,0x4170
/*  f01de74:	44810000 */ 	mtc1	$at,$f0
/*  f01de78:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01de7c:
/*  f01de7c:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f01de80:	00001025 */ 	or	$v0,$zero,$zero
/*  f01de84:	3c017f1b */ 	lui	$at,%hi(var7f1a8670)
/*  f01de88:	19e0006c */ 	blez	$t7,.L0f01e03c
/*  f01de8c:	254a45c4 */ 	addiu	$t2,$t2,%lo(var800a45c4)
/*  f01de90:	c4308670 */ 	lwc1	$f16,%lo(var7f1a8670)($at)
/*  f01de94:	3c017f1b */ 	lui	$at,%hi(var7f1a8674)
/*  f01de98:	c42e8674 */ 	lwc1	$f14,%lo(var7f1a8674)($at)
/*  f01de9c:	3c017f1b */ 	lui	$at,%hi(var7f1a8678)
/*  f01dea0:	c42c8678 */ 	lwc1	$f12,%lo(var7f1a8678)($at)
/*  f01dea4:	8d580000 */ 	lw	$t8,0x0($t2)
.L0f01dea8:
/*  f01dea8:	03032021 */ 	addu	$a0,$t8,$v1
/*  f01deac:	8c850004 */ 	lw	$a1,0x4($a0)
/*  f01deb0:	58a0005d */ 	blezl	$a1,.L0f01e028
/*  f01deb4:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f01deb8:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f01debc:	00003825 */ 	or	$a3,$zero,$zero
/*  f01dec0:	44063000 */ 	mfc1	$a2,$f6
/*  f01dec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dec8:	00a66021 */ 	addu	$t4,$a1,$a2
/*  f01decc:	ac8c0004 */ 	sw	$t4,0x4($a0)
/*  f01ded0:	8d4d0000 */ 	lw	$t5,0x0($t2)
/*  f01ded4:	01a32021 */ 	addu	$a0,$t5,$v1
/*  f01ded8:	c48a002c */ 	lwc1	$f10,0x2c($a0)
/*  f01dedc:	c4880014 */ 	lwc1	$f8,0x14($a0)
/*  f01dee0:	46005482 */ 	mul.s	$f18,$f10,$f0
/*  f01dee4:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f01dee8:	e4840014 */ 	swc1	$f4,0x14($a0)
/*  f01deec:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f01def0:	01c32021 */ 	addu	$a0,$t6,$v1
/*  f01def4:	c48a0030 */ 	lwc1	$f10,0x30($a0)
/*  f01def8:	c4860018 */ 	lwc1	$f6,0x18($a0)
/*  f01defc:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f01df00:	46083480 */ 	add.s	$f18,$f6,$f8
/*  f01df04:	e4920018 */ 	swc1	$f18,0x18($a0)
/*  f01df08:	8d4f0000 */ 	lw	$t7,0x0($t2)
/*  f01df0c:	01e32021 */ 	addu	$a0,$t7,$v1
/*  f01df10:	c48a0034 */ 	lwc1	$f10,0x34($a0)
/*  f01df14:	c484001c */ 	lwc1	$f4,0x1c($a0)
/*  f01df18:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f01df1c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f01df20:	e488001c */ 	swc1	$f8,0x1c($a0)
/*  f01df24:	8d580000 */ 	lw	$t8,0x0($t2)
/*  f01df28:	03032021 */ 	addu	$a0,$t8,$v1
/*  f01df2c:	c48a0020 */ 	lwc1	$f10,0x20($a0)
/*  f01df30:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f01df34:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f01df38:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f01df3c:	e4860008 */ 	swc1	$f6,0x8($a0)
/*  f01df40:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f01df44:	03232021 */ 	addu	$a0,$t9,$v1
/*  f01df48:	c48a0028 */ 	lwc1	$f10,0x28($a0)
/*  f01df4c:	c4880010 */ 	lwc1	$f8,0x10($a0)
/*  f01df50:	46005482 */ 	mul.s	$f18,$f10,$f0
/*  f01df54:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f01df58:	18c0001b */ 	blez	$a2,.L0f01dfc8
/*  f01df5c:	e4840010 */ 	swc1	$f4,0x10($a0)
/*  f01df60:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f01df64:	10e6000e */ 	beq	$a3,$a2,.L0f01dfa0
/*  f01df68:	8d4c0000 */ 	lw	$t4,0x0($t2)
.L0f01df6c:
/*  f01df6c:	01832021 */ 	addu	$a0,$t4,$v1
/*  f01df70:	c492000c */ 	lwc1	$f18,0xc($a0)
/*  f01df74:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01df78:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f01df7c:	460a9280 */ 	add.s	$f10,$f18,$f10
/*  f01df80:	e48a000c */ 	swc1	$f10,0xc($a0)
/*  f01df84:	8d4d0000 */ 	lw	$t5,0x0($t2)
/*  f01df88:	01a32021 */ 	addu	$a0,$t5,$v1
/*  f01df8c:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01df90:	460c5281 */ 	sub.s	$f10,$f10,$f12
/*  f01df94:	e48a0024 */ 	swc1	$f10,0x24($a0)
/*  f01df98:	14e6fff4 */ 	bne	$a3,$a2,.L0f01df6c
/*  f01df9c:	8d4c0000 */ 	lw	$t4,0x0($t2)
.L0f01dfa0:
/*  f01dfa0:	01832021 */ 	addu	$a0,$t4,$v1
/*  f01dfa4:	c492000c */ 	lwc1	$f18,0xc($a0)
/*  f01dfa8:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01dfac:	460a9280 */ 	add.s	$f10,$f18,$f10
/*  f01dfb0:	e48a000c */ 	swc1	$f10,0xc($a0)
/*  f01dfb4:	8d4d0000 */ 	lw	$t5,0x0($t2)
/*  f01dfb8:	01a32021 */ 	addu	$a0,$t5,$v1
/*  f01dfbc:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01dfc0:	460c5281 */ 	sub.s	$f10,$f10,$f12
/*  f01dfc4:	e48a0024 */ 	swc1	$f10,0x24($a0)
.L0f01dfc8:
/*  f01dfc8:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f01dfcc:	01c32021 */ 	addu	$a0,$t6,$v1
/*  f01dfd0:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f01dfd4:	29e10096 */ 	slti	$at,$t7,0x96
/*  f01dfd8:	54200005 */ 	bnezl	$at,.L0f01dff0
/*  f01dfdc:	c482000c */ 	lwc1	$f2,0xc($a0)
/*  f01dfe0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f01dfe4:	8d580000 */ 	lw	$t8,0x0($t2)
/*  f01dfe8:	03032021 */ 	addu	$a0,$t8,$v1
/*  f01dfec:	c482000c */ 	lwc1	$f2,0xc($a0)
.L0f01dff0:
/*  f01dff0:	460e103c */ 	c.lt.s	$f2,$f14
/*  f01dff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01dff8:	45030006 */ 	bc1tl	.L0f01e014
/*  f01dffc:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f01e000:	4602803c */ 	c.lt.s	$f16,$f2
/*  f01e004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e008:	45020003 */ 	bc1fl	.L0f01e018
/*  f01e00c:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f01e010:	ac800004 */ 	sw	$zero,0x4($a0)
.L0f01e014:
/*  f01e014:	8d190000 */ 	lw	$t9,0x0($t0)
.L0f01e018:
/*  f01e018:	57200003 */ 	bnezl	$t9,.L0f01e028
/*  f01e01c:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f01e020:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*  f01e024:	8d2c0000 */ 	lw	$t4,0x0($t1)
.L0f01e028:
/*  f01e028:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f01e02c:	2463006c */ 	addiu	$v1,$v1,0x6c
/*  f01e030:	004c082a */ 	slt	$at,$v0,$t4
/*  f01e034:	5420ff9c */ 	bnezl	$at,.L0f01dea8
/*  f01e038:	8d580000 */ 	lw	$t8,0x0($t2)
.L0f01e03c:
/*  f01e03c:	03e00008 */ 	jr	$ra
/*  f01e040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e04c:	00000000 */ 	sll	$zero,$zero,0x0
);
