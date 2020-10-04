#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_0b63b0.h"
#include "game/game_0d5a90.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "gvars/gvars.h"
#include "lib/lib_0d520.h"
#include "types.h"

const char var7f1adbf0[] = "radmax";
const char var7f1adbf8[] = "radmed";
const char var7f1adc00[] = "radmin";
const char var7f1adc08[] = "len1";
const char var7f1adc10[] = "len2";
const char var7f1adc18[] = "len3";
const char var7f1adc20[] = "offx";
const char var7f1adc28[] = "offy";
const char var7f1adc30[] = "shieldcol";
const char var7f1adc3c[] = "armourcol";
const char var7f1adc48[] = "traumacol";
const char var7f1adc54[] = "bgcol";
const char var7f1adc5c[] = "shieldfade";
const char var7f1adc68[] = "armourfade";
const char var7f1adc74[] = "traumafade";
const char var7f1adc80[] = "shielddir";
const char var7f1adc8c[] = "underleft";
const char var7f1adc98[] = "undertop";
const char var7f1adca4[] = "underright";
const char var7f1adcb0[] = "underbottom";
const char var7f1adcbc[] = "undercol";

const u32 var7f1adcc8[] = {0x3f8a3d71};
const u32 var7f1adccc[] = {0x3f6c8b44};
const u32 var7f1adcd0[] = {0x3f851eb8};
const u32 var7f1adcd4[] = {0x3ec41893};
const u32 var7f1adcd8[] = {0x3f6c8b44};
const u32 var7f1adcdc[] = {0x3ec41893};
const u32 var7f1adce0[] = {0x3d4ccccd};
const u32 var7f1adce4[] = {0x3f34fdf4};
const u32 var7f1adce8[] = {0x3f828f5c};
const u32 var7f1adcec[] = {0x3f34fdf4};
const u32 var7f1adcf0[] = {0x3f34fdf4};
const u32 var7f1adcf4[] = {0x3f34fdf4};
const u32 var7f1adcf8[] = {0x3dcccccd};
const u32 var7f1adcfc[] = {0x3ec41893};
const u32 var7f1add00[] = {0x3f6c8b44};
const u32 var7f1add04[] = {0x3ec41893};
const u32 var7f1add08[] = {0x3f6c8b44};
const u32 var7f1add0c[] = {0x3e19999a};
const u32 var7f1add10[] = {0x3e4ccccd};
const u32 var7f1add14[] = {0x3f4ccccd};
const u32 var7f1add18[] = {0x3f59999a};
const u32 var7f1add1c[] = {0x3f666666};
const u32 var7f1add20[] = {0x3f733333};
const u32 var7f1add24[] = {0x3f666666};
const u32 var7f1add28[] = {0x3eaf1aa0};
const u32 var7f1add2c[] = {0x3f70a3d7};
const u32 var7f1add30[] = {0x3f70a3d7};
const u32 var7f1add34[] = {0x3f70a3d7};
const u32 var7f1add38[] = {0x3f249ba6};
const u32 var7f1add3c[] = {0x3f441893};
const u32 var7f1add40[] = {0x3f441893};
const u32 var7f1add44[] = {0x3f7851ec};
const u32 var7f1add48[] = {0x3f5db22d};
const u32 var7f1add4c[] = {0x3f7d70a4};
const u32 var7f1add50[] = {0x3f7c28f6};
const u32 var7f1add54[] = {0x3e322d0e};
const u32 var7f1add58[] = {0x3e322d0e};
const u32 var7f1add5c[] = {0x3f4ccccd};
const u32 var7f1add60[] = {0x3ec41893};
const u32 var7f1add64[] = {0x3f6c8b44};
const u32 var7f1add68[] = {0x3f6c8b44};
const u32 var7f1add6c[] = {0x3f59999a};
const u32 var7f1add70[] = {0x3f34fdf4};
const u32 var7f1add74[] = {0x3f34fdf4};
const u32 var7f1add78[] = {0x3f34fdf4};
const u32 var7f1add7c[] = {0x3f666666};
const u32 var7f1add80[] = {0x3f6c8b44};
const u32 var7f1add84[] = {0x3ec41893};
const u32 var7f1add88[] = {0x3ec41893};
const u32 var7f1add8c[] = {0x3f733333};
const u32 var7f1add90[] = {0x3a83126f};
const u32 var7f1add94[] = {0x3a83126f};
const u32 var7f1add98[] = {0x3a83126f};
const u32 var7f1add9c[] = {0x00000000};

u32 var80070f20 = 0x0000001e;
u32 var80070f24 = 0x00000012;
u32 var80070f28 = 0x0000000c;
u32 var80070f2c = 0x000000aa;
u32 var80070f30 = 0x0000002f;
u32 var80070f34 = 0x00000028;
u32 var80070f38 = 0x10500090;
u32 var80070f3c = 0x00c00060;
u32 var80070f40 = 0xff000060;
u32 var80070f44 = 0x00000080;
u32 var80070f48 = 0xffffffab;
u32 var80070f4c = 0xffffff47;
u32 var80070f50 = 0x00000064;
u32 var80070f54 = 0x00000064;
u32 var80070f58 = 0x000000c8;
u32 var80070f5c = 0x00000001;
u32 var80070f60 = 0x0000005f;
u32 var80070f64 = 0x00000012;
u32 var80070f68 = 0x000000e1;
u32 var80070f6c = 0x0000002e;
u32 var80070f70 = 0x00000000;
u32 var80070f74 = 0x00000000;
u32 var80070f78 = 0x00000000;
u32 var80070f7c = 0x00000000;

GLOBAL_ASM(
glabel func0f0d5a90
/*  f0d5a90:	44876000 */ 	mtc1	$a3,$f12
/*  f0d5a94:	44800000 */ 	mtc1	$zero,$f0
/*  f0d5a98:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0d5a9c:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f0d5aa0:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0d5aa4:	00808025 */ 	or	$s0,$a0,$zero
/*  f0d5aa8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0d5aac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d5ab0:	45000002 */ 	bc1f	.L0f0d5abc
/*  f0d5ab4:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0d5ab8:	46000306 */ 	mov.s	$f12,$f0
.L0f0d5abc:
/*  f0d5abc:	44810000 */ 	mtc1	$at,$f0
/*  f0d5ac0:	24090014 */ 	addiu	$t1,$zero,0x14
/*  f0d5ac4:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0d5ac8:	00000000 */ 	nop
/*  f0d5acc:	45000002 */ 	bc1f	.L0f0d5ad8
/*  f0d5ad0:	00000000 */ 	nop
/*  f0d5ad4:	46000306 */ 	mov.s	$f12,$f0
.L0f0d5ad8:
/*  f0d5ad8:	18c0000a */ 	blez	$a2,.L0f0d5b04
/*  f0d5adc:	00001025 */ 	or	$v0,$zero,$zero
.L0f0d5ae0:
/*  f0d5ae0:	8c870000 */ 	lw	$a3,0x0($a0)
/*  f0d5ae4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d5ae8:	0067082a */ 	slt	$at,$v1,$a3
/*  f0d5aec:	10200002 */ 	beqz	$at,.L0f0d5af8
/*  f0d5af0:	00000000 */ 	nop
/*  f0d5af4:	00e01825 */ 	or	$v1,$a3,$zero
.L0f0d5af8:
/*  f0d5af8:	1446fff9 */ 	bne	$v0,$a2,.L0f0d5ae0
/*  f0d5afc:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f0d5b00:	00001025 */ 	or	$v0,$zero,$zero
.L0f0d5b04:
/*  f0d5b04:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0d5b08:	18600051 */ 	blez	$v1,.L0f0d5c50
/*  f0d5b0c:	00a02025 */ 	or	$a0,$a1,$zero
.L0f0d5b10:
/*  f0d5b10:	8c860000 */ 	lw	$a2,0x0($a0)
/*  f0d5b14:	8c870004 */ 	lw	$a3,0x4($a0)
/*  f0d5b18:	00c90019 */ 	multu	$a2,$t1
/*  f0d5b1c:	00007012 */ 	mflo	$t6
/*  f0d5b20:	020e4021 */ 	addu	$t0,$s0,$t6
/*  f0d5b24:	c5000010 */ 	lwc1	$f0,0x10($t0)
/*  f0d5b28:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0d5b2c:	00000000 */ 	nop
/*  f0d5b30:	45020045 */ 	bc1fl	.L0f0d5c48
/*  f0d5b34:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d5b38:	00e90019 */ 	multu	$a3,$t1
/*  f0d5b3c:	00007812 */ 	mflo	$t7
/*  f0d5b40:	020f3021 */ 	addu	$a2,$s0,$t7
/*  f0d5b44:	c4c20010 */ 	lwc1	$f2,0x10($a2)
/*  f0d5b48:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0d5b4c:	00000000 */ 	nop
/*  f0d5b50:	4502003d */ 	bc1fl	.L0f0d5c48
/*  f0d5b54:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d5b58:	c5100000 */ 	lwc1	$f16,0x0($t0)
/*  f0d5b5c:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f0d5b60:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*  f0d5b64:	c5080004 */ 	lwc1	$f8,0x4($t0)
/*  f0d5b68:	46102381 */ 	sub.s	$f14,$f4,$f16
/*  f0d5b6c:	c5040008 */ 	lwc1	$f4,0x8($t0)
/*  f0d5b70:	c4ca0008 */ 	lwc1	$f10,0x8($a2)
/*  f0d5b74:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0d5b78:	00690019 */ 	multu	$v1,$t1
/*  f0d5b7c:	2469ffff */ 	addiu	$t1,$v1,-1
/*  f0d5b80:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0d5b84:	0049082a */ 	slt	$at,$v0,$t1
/*  f0d5b88:	01203825 */ 	or	$a3,$t1,$zero
/*  f0d5b8c:	0009c880 */ 	sll	$t9,$t1,0x2
/*  f0d5b90:	e7a6002c */ 	swc1	$f6,0x2c($sp)
/*  f0d5b94:	46001181 */ 	sub.s	$f6,$f2,$f0
/*  f0d5b98:	c4c8000c */ 	lwc1	$f8,0xc($a2)
/*  f0d5b9c:	c50a000c */ 	lwc1	$f10,0xc($t0)
/*  f0d5ba0:	46006081 */ 	sub.s	$f2,$f12,$f0
/*  f0d5ba4:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0d5ba8:	0000c012 */ 	mflo	$t8
/*  f0d5bac:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0d5bb0:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*  f0d5bb4:	02183021 */ 	addu	$a2,$s0,$t8
/*  f0d5bb8:	46081283 */ 	div.s	$f10,$f2,$f8
/*  f0d5bbc:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f0d5bc0:	e7aa0008 */ 	swc1	$f10,0x8($sp)
/*  f0d5bc4:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*  f0d5bc8:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0d5bcc:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f0d5bd0:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f0d5bd4:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*  f0d5bd8:	c50a0004 */ 	lwc1	$f10,0x4($t0)
/*  f0d5bdc:	46122182 */ 	mul.s	$f6,$f4,$f18
/*  f0d5be0:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0d5be4:	e4c80004 */ 	swc1	$f8,0x4($a2)
/*  f0d5be8:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*  f0d5bec:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f0d5bf0:	c5080008 */ 	lwc1	$f8,0x8($t0)
/*  f0d5bf4:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0d5bf8:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0d5bfc:	e4c40008 */ 	swc1	$f4,0x8($a2)
/*  f0d5c00:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*  f0d5c04:	c7aa0008 */ 	lwc1	$f10,0x8($sp)
/*  f0d5c08:	c504000c */ 	lwc1	$f4,0xc($t0)
/*  f0d5c0c:	e4cc0010 */ 	swc1	$f12,0x10($a2)
/*  f0d5c10:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d5c14:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0d5c18:	10200007 */ 	beqz	$at,.L0f0d5c38
/*  f0d5c1c:	e4ca000c */ 	swc1	$f10,0xc($a2)
/*  f0d5c20:	00b93021 */ 	addu	$a2,$a1,$t9
.L0f0d5c24:
/*  f0d5c24:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f0d5c28:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0d5c2c:	24c6fffc */ 	addiu	$a2,$a2,-4
/*  f0d5c30:	1447fffc */ 	bne	$v0,$a3,.L0f0d5c24
/*  f0d5c34:	acca0008 */ 	sw	$t2,0x8($a2)
.L0f0d5c38:
/*  f0d5c38:	ac830004 */ 	sw	$v1,0x4($a0)
/*  f0d5c3c:	10000005 */ 	b	.L0f0d5c54
/*  f0d5c40:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0d5c44:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f0d5c48:
/*  f0d5c48:	1443ffb1 */ 	bne	$v0,$v1,.L0f0d5b10
/*  f0d5c4c:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f0d5c50:
/*  f0d5c50:	00001025 */ 	or	$v0,$zero,$zero
.L0f0d5c54:
/*  f0d5c54:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f0d5c58:	03e00008 */ 	jr	$ra
/*  f0d5c5c:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f0d5c60
/*  f0d5c60:	44877000 */ 	mtc1	$a3,$f14
/*  f0d5c64:	c7ac0010 */ 	lwc1	$f12,0x10($sp)
/*  f0d5c68:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f0d5c6c:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*  f0d5c70:	460c703e */ 	c.le.s	$f14,$f12
/*  f0d5c74:	00000000 */ 	nop
/*  f0d5c78:	45020004 */ 	bc1fl	.L0f0d5c8c
/*  f0d5c7c:	4604603e */ 	c.le.s	$f12,$f4
/*  f0d5c80:	03e00008 */ 	jr	$ra
/*  f0d5c84:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d5c88:	4604603e */ 	c.le.s	$f12,$f4
.L0f0d5c8c:
/*  f0d5c8c:	00000000 */ 	nop
/*  f0d5c90:	45020004 */ 	bc1fl	.L0f0d5ca4
/*  f0d5c94:	c7a60008 */ 	lwc1	$f6,0x8($sp)
/*  f0d5c98:	03e00008 */ 	jr	$ra
/*  f0d5c9c:	00801025 */ 	or	$v0,$a0,$zero
/*  f0d5ca0:	c7a60008 */ 	lwc1	$f6,0x8($sp)
.L0f0d5ca4:
/*  f0d5ca4:	00041e02 */ 	srl	$v1,$a0,0x18
/*  f0d5ca8:	0005ce02 */ 	srl	$t9,$a1,0x18
/*  f0d5cac:	46066201 */ 	sub.s	$f8,$f12,$f6
/*  f0d5cb0:	332900ff */ 	andi	$t1,$t9,0xff
/*  f0d5cb4:	306e00ff */ 	andi	$t6,$v1,0xff
/*  f0d5cb8:	46067281 */ 	sub.s	$f10,$f14,$f6
/*  f0d5cbc:	00043402 */ 	srl	$a2,$a0,0x10
/*  f0d5cc0:	30cf00ff */ 	andi	$t7,$a2,0xff
/*  f0d5cc4:	012e5023 */ 	subu	$t2,$t1,$t6
/*  f0d5cc8:	460a4003 */ 	div.s	$f0,$f8,$f10
/*  f0d5ccc:	00043a02 */ 	srl	$a3,$a0,0x8
/*  f0d5cd0:	448a8000 */ 	mtc1	$t2,$f16
/*  f0d5cd4:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f0d5cd8:	01e03025 */ 	or	$a2,$t7,$zero
/*  f0d5cdc:	00057c02 */ 	srl	$t7,$a1,0x10
/*  f0d5ce0:	03003825 */ 	or	$a3,$t8,$zero
/*  f0d5ce4:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0d5ce8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0d5cec:	0306c823 */ 	subu	$t9,$t8,$a2
/*  f0d5cf0:	44994000 */ 	mtc1	$t9,$f8
/*  f0d5cf4:	00057a02 */ 	srl	$t7,$a1,0x8
/*  f0d5cf8:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0d5cfc:	0307c823 */ 	subu	$t9,$t8,$a3
/*  f0d5d00:	30af00ff */ 	andi	$t7,$a1,0xff
/*  f0d5d04:	308800ff */ 	andi	$t0,$a0,0xff
/*  f0d5d08:	01e8c023 */ 	subu	$t8,$t7,$t0
/*  f0d5d0c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d5d10:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0d5d14:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d5d18:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0d5d1c:	44992000 */ 	mtc1	$t9,$f4
/*  f0d5d20:	440c3000 */ 	mfc1	$t4,$f6
/*  f0d5d24:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d5d28:	01cc6821 */ 	addu	$t5,$t6,$t4
/*  f0d5d2c:	000d7600 */ 	sll	$t6,$t5,0x18
/*  f0d5d30:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0d5d34:	44988000 */ 	mtc1	$t8,$f16
/*  f0d5d38:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0d5d3c:	440a9000 */ 	mfc1	$t2,$f18
/*  f0d5d40:	00000000 */ 	nop
/*  f0d5d44:	00ca5821 */ 	addu	$t3,$a2,$t2
/*  f0d5d48:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0d5d4c:	000b6400 */ 	sll	$t4,$t3,0x10
/*  f0d5d50:	01cc6825 */ 	or	$t5,$t6,$t4
/*  f0d5d54:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d5d58:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0d5d5c:	440a5000 */ 	mfc1	$t2,$f10
/*  f0d5d60:	00000000 */ 	nop
/*  f0d5d64:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f0d5d68:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d5d6c:	000b7200 */ 	sll	$t6,$t3,0x8
/*  f0d5d70:	01ae6025 */ 	or	$t4,$t5,$t6
/*  f0d5d74:	44093000 */ 	mfc1	$t1,$f6
/*  f0d5d78:	00000000 */ 	nop
/*  f0d5d7c:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0d5d80:	018a1025 */ 	or	$v0,$t4,$t2
/*  f0d5d84:	03e00008 */ 	jr	$ra
/*  f0d5d88:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0d5d8c
/*  f0d5d8c:	27bdfbd8 */ 	addiu	$sp,$sp,-1064
/*  f0d5d90:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0d5d94:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0d5d98:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0d5d9c:	afa40428 */ 	sw	$a0,0x428($sp)
/*  f0d5da0:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0d5da4:	00c08825 */ 	or	$s1,$a2,$zero
/*  f0d5da8:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f0d5dac:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f0d5db0:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f0d5db4:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f0d5db8:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f0d5dbc:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f0d5dc0:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0d5dc4:	afa70434 */ 	sw	$a3,0x434($sp)
/*  f0d5dc8:	0fc59e59 */ 	jal	func0f167964
/*  f0d5dcc:	24040038 */ 	addiu	$a0,$zero,0x38
/*  f0d5dd0:	afa20184 */ 	sw	$v0,0x184($sp)
/*  f0d5dd4:	0fc59e73 */ 	jal	func0f1679cc
/*  f0d5dd8:	24040038 */ 	addiu	$a0,$zero,0x38
/*  f0d5ddc:	8fb20184 */ 	lw	$s2,0x184($sp)
/*  f0d5de0:	3c047f1b */ 	lui	$a0,%hi(var7f1adbf0)
/*  f0d5de4:	3c058007 */ 	lui	$a1,%hi(var80070f20)
/*  f0d5de8:	26530120 */ 	addiu	$s3,$s2,0x120
/*  f0d5dec:	265501e0 */ 	addiu	$s5,$s2,0x1e0
/*  f0d5df0:	afa20180 */ 	sw	$v0,0x180($sp)
/*  f0d5df4:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0d5df8:	24570060 */ 	addiu	$s7,$v0,0x60
/*  f0d5dfc:	245e00a0 */ 	addiu	$s8,$v0,0xa0
/*  f0d5e00:	afb5009c */ 	sw	$s5,0x9c($sp)
/*  f0d5e04:	afb300a0 */ 	sw	$s3,0xa0($sp)
/*  f0d5e08:	24a50f20 */ 	addiu	$a1,$a1,%lo(var80070f20)
/*  f0d5e0c:	0c0036cc */ 	jal	func0000db30
/*  f0d5e10:	2484dbf0 */ 	addiu	$a0,$a0,%lo(var7f1adbf0)
/*  f0d5e14:	3c047f1b */ 	lui	$a0,%hi(var7f1adbf8)
/*  f0d5e18:	3c058007 */ 	lui	$a1,%hi(var80070f24)
/*  f0d5e1c:	24a50f24 */ 	addiu	$a1,$a1,%lo(var80070f24)
/*  f0d5e20:	0c0036cc */ 	jal	func0000db30
/*  f0d5e24:	2484dbf8 */ 	addiu	$a0,$a0,%lo(var7f1adbf8)
/*  f0d5e28:	3c047f1b */ 	lui	$a0,%hi(var7f1adc00)
/*  f0d5e2c:	3c058007 */ 	lui	$a1,%hi(var80070f28)
/*  f0d5e30:	24a50f28 */ 	addiu	$a1,$a1,%lo(var80070f28)
/*  f0d5e34:	0c0036cc */ 	jal	func0000db30
/*  f0d5e38:	2484dc00 */ 	addiu	$a0,$a0,%lo(var7f1adc00)
/*  f0d5e3c:	3c047f1b */ 	lui	$a0,%hi(var7f1adc08)
/*  f0d5e40:	3c058007 */ 	lui	$a1,%hi(var80070f2c)
/*  f0d5e44:	24a50f2c */ 	addiu	$a1,$a1,%lo(var80070f2c)
/*  f0d5e48:	0c0036cc */ 	jal	func0000db30
/*  f0d5e4c:	2484dc08 */ 	addiu	$a0,$a0,%lo(var7f1adc08)
/*  f0d5e50:	3c047f1b */ 	lui	$a0,%hi(var7f1adc10)
/*  f0d5e54:	3c058007 */ 	lui	$a1,%hi(var80070f30)
/*  f0d5e58:	24a50f30 */ 	addiu	$a1,$a1,%lo(var80070f30)
/*  f0d5e5c:	0c0036cc */ 	jal	func0000db30
/*  f0d5e60:	2484dc10 */ 	addiu	$a0,$a0,%lo(var7f1adc10)
/*  f0d5e64:	3c047f1b */ 	lui	$a0,%hi(var7f1adc18)
/*  f0d5e68:	3c058007 */ 	lui	$a1,%hi(var80070f34)
/*  f0d5e6c:	24a50f34 */ 	addiu	$a1,$a1,%lo(var80070f34)
/*  f0d5e70:	0c0036cc */ 	jal	func0000db30
/*  f0d5e74:	2484dc18 */ 	addiu	$a0,$a0,%lo(var7f1adc18)
/*  f0d5e78:	3c047f1b */ 	lui	$a0,%hi(var7f1adc20)
/*  f0d5e7c:	3c058007 */ 	lui	$a1,%hi(var80070f48)
/*  f0d5e80:	24a50f48 */ 	addiu	$a1,$a1,%lo(var80070f48)
/*  f0d5e84:	0c0036cc */ 	jal	func0000db30
/*  f0d5e88:	2484dc20 */ 	addiu	$a0,$a0,%lo(var7f1adc20)
/*  f0d5e8c:	3c047f1b */ 	lui	$a0,%hi(var7f1adc28)
/*  f0d5e90:	3c058007 */ 	lui	$a1,%hi(var80070f4c)
/*  f0d5e94:	24a50f4c */ 	addiu	$a1,$a1,%lo(var80070f4c)
/*  f0d5e98:	0c0036cc */ 	jal	func0000db30
/*  f0d5e9c:	2484dc28 */ 	addiu	$a0,$a0,%lo(var7f1adc28)
/*  f0d5ea0:	3c047f1b */ 	lui	$a0,%hi(var7f1adc30)
/*  f0d5ea4:	3c058007 */ 	lui	$a1,%hi(var80070f38)
/*  f0d5ea8:	24a50f38 */ 	addiu	$a1,$a1,%lo(var80070f38)
/*  f0d5eac:	0c0036cc */ 	jal	func0000db30
/*  f0d5eb0:	2484dc30 */ 	addiu	$a0,$a0,%lo(var7f1adc30)
/*  f0d5eb4:	3c047f1b */ 	lui	$a0,%hi(var7f1adc3c)
/*  f0d5eb8:	3c058007 */ 	lui	$a1,%hi(var80070f3c)
/*  f0d5ebc:	24a50f3c */ 	addiu	$a1,$a1,%lo(var80070f3c)
/*  f0d5ec0:	0c0036cc */ 	jal	func0000db30
/*  f0d5ec4:	2484dc3c */ 	addiu	$a0,$a0,%lo(var7f1adc3c)
/*  f0d5ec8:	3c047f1b */ 	lui	$a0,%hi(var7f1adc48)
/*  f0d5ecc:	3c058007 */ 	lui	$a1,%hi(var80070f40)
/*  f0d5ed0:	24a50f40 */ 	addiu	$a1,$a1,%lo(var80070f40)
/*  f0d5ed4:	0c0036cc */ 	jal	func0000db30
/*  f0d5ed8:	2484dc48 */ 	addiu	$a0,$a0,%lo(var7f1adc48)
/*  f0d5edc:	3c047f1b */ 	lui	$a0,%hi(var7f1adc54)
/*  f0d5ee0:	3c058007 */ 	lui	$a1,%hi(var80070f44)
/*  f0d5ee4:	24a50f44 */ 	addiu	$a1,$a1,%lo(var80070f44)
/*  f0d5ee8:	0c0036cc */ 	jal	func0000db30
/*  f0d5eec:	2484dc54 */ 	addiu	$a0,$a0,%lo(var7f1adc54)
/*  f0d5ef0:	3c047f1b */ 	lui	$a0,%hi(var7f1adc5c)
/*  f0d5ef4:	3c058007 */ 	lui	$a1,%hi(var80070f50)
/*  f0d5ef8:	24a50f50 */ 	addiu	$a1,$a1,%lo(var80070f50)
/*  f0d5efc:	0c0036cc */ 	jal	func0000db30
/*  f0d5f00:	2484dc5c */ 	addiu	$a0,$a0,%lo(var7f1adc5c)
/*  f0d5f04:	3c047f1b */ 	lui	$a0,%hi(var7f1adc68)
/*  f0d5f08:	3c058007 */ 	lui	$a1,%hi(var80070f54)
/*  f0d5f0c:	24a50f54 */ 	addiu	$a1,$a1,%lo(var80070f54)
/*  f0d5f10:	0c0036cc */ 	jal	func0000db30
/*  f0d5f14:	2484dc68 */ 	addiu	$a0,$a0,%lo(var7f1adc68)
/*  f0d5f18:	3c047f1b */ 	lui	$a0,%hi(var7f1adc74)
/*  f0d5f1c:	3c058007 */ 	lui	$a1,%hi(var80070f58)
/*  f0d5f20:	24a50f58 */ 	addiu	$a1,$a1,%lo(var80070f58)
/*  f0d5f24:	0c0036cc */ 	jal	func0000db30
/*  f0d5f28:	2484dc74 */ 	addiu	$a0,$a0,%lo(var7f1adc74)
/*  f0d5f2c:	3c047f1b */ 	lui	$a0,%hi(var7f1adc80)
/*  f0d5f30:	3c058007 */ 	lui	$a1,%hi(var80070f5c)
/*  f0d5f34:	24a50f5c */ 	addiu	$a1,$a1,%lo(var80070f5c)
/*  f0d5f38:	0c0036cc */ 	jal	func0000db30
/*  f0d5f3c:	2484dc80 */ 	addiu	$a0,$a0,%lo(var7f1adc80)
/*  f0d5f40:	3c047f1b */ 	lui	$a0,%hi(var7f1adc8c)
/*  f0d5f44:	3c058007 */ 	lui	$a1,%hi(var80070f60)
/*  f0d5f48:	24a50f60 */ 	addiu	$a1,$a1,%lo(var80070f60)
/*  f0d5f4c:	0c0036cc */ 	jal	func0000db30
/*  f0d5f50:	2484dc8c */ 	addiu	$a0,$a0,%lo(var7f1adc8c)
/*  f0d5f54:	3c047f1b */ 	lui	$a0,%hi(var7f1adc98)
/*  f0d5f58:	3c058007 */ 	lui	$a1,%hi(var80070f64)
/*  f0d5f5c:	24a50f64 */ 	addiu	$a1,$a1,%lo(var80070f64)
/*  f0d5f60:	0c0036cc */ 	jal	func0000db30
/*  f0d5f64:	2484dc98 */ 	addiu	$a0,$a0,%lo(var7f1adc98)
/*  f0d5f68:	3c047f1b */ 	lui	$a0,%hi(var7f1adca4)
/*  f0d5f6c:	3c058007 */ 	lui	$a1,%hi(var80070f68)
/*  f0d5f70:	24a50f68 */ 	addiu	$a1,$a1,%lo(var80070f68)
/*  f0d5f74:	0c0036cc */ 	jal	func0000db30
/*  f0d5f78:	2484dca4 */ 	addiu	$a0,$a0,%lo(var7f1adca4)
/*  f0d5f7c:	3c047f1b */ 	lui	$a0,%hi(var7f1adcb0)
/*  f0d5f80:	3c058007 */ 	lui	$a1,%hi(var80070f6c)
/*  f0d5f84:	24a50f6c */ 	addiu	$a1,$a1,%lo(var80070f6c)
/*  f0d5f88:	0c0036cc */ 	jal	func0000db30
/*  f0d5f8c:	2484dcb0 */ 	addiu	$a0,$a0,%lo(var7f1adcb0)
/*  f0d5f90:	3c047f1b */ 	lui	$a0,%hi(var7f1adcbc)
/*  f0d5f94:	3c058007 */ 	lui	$a1,%hi(var80070f70)
/*  f0d5f98:	24a50f70 */ 	addiu	$a1,$a1,%lo(var80070f70)
/*  f0d5f9c:	0c0036cc */ 	jal	func0000db30
/*  f0d5fa0:	2484dcbc */ 	addiu	$a0,$a0,%lo(var7f1adcbc)
/*  f0d5fa4:	12000008 */ 	beqz	$s0,.L0f0d5fc8
/*  f0d5fa8:	00000000 */ 	nop
/*  f0d5fac:	1a200006 */ 	blez	$s1,.L0f0d5fc8
/*  f0d5fb0:	c7ae0434 */ 	lwc1	$f14,0x434($sp)
/*  f0d5fb4:	44805000 */ 	mtc1	$zero,$f10
/*  f0d5fb8:	00000000 */ 	nop
/*  f0d5fbc:	460a703e */ 	c.le.s	$f14,$f10
/*  f0d5fc0:	00000000 */ 	nop
/*  f0d5fc4:	45000015 */ 	bc1f	.L0f0d601c
.L0f0d5fc8:
/*  f0d5fc8:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0d5fcc:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0d5fd0:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d5fd4:	44816000 */ 	mtc1	$at,$f12
/*  f0d5fd8:	c44800f0 */ 	lwc1	$f8,0xf0($v0)
/*  f0d5fdc:	3c013f40 */ 	lui	$at,0x3f40
/*  f0d5fe0:	44812000 */ 	mtc1	$at,$f4
/*  f0d5fe4:	e7a8013c */ 	swc1	$f8,0x13c($sp)
/*  f0d5fe8:	c44000ec */ 	lwc1	$f0,0xec($v0)
/*  f0d5fec:	3c014080 */ 	lui	$at,0x4080
/*  f0d5ff0:	460c0181 */ 	sub.s	$f6,$f0,$f12
/*  f0d5ff4:	46006201 */ 	sub.s	$f8,$f12,$f0
/*  f0d5ff8:	46043283 */ 	div.s	$f10,$f6,$f4
/*  f0d5ffc:	44813000 */ 	mtc1	$at,$f6
/*  f0d6000:	00000000 */ 	nop
/*  f0d6004:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0d6008:	e7a40134 */ 	swc1	$f4,0x134($sp)
/*  f0d600c:	0fc305bd */ 	jal	currentPlayerGetHealthBarHeightFrac
/*  f0d6010:	e7aa0138 */ 	swc1	$f10,0x138($sp)
/*  f0d6014:	1000001c */ 	b	.L0f0d6088
/*  f0d6018:	e7a0012c */ 	swc1	$f0,0x12c($sp)
.L0f0d601c:
/*  f0d601c:	c6020104 */ 	lwc1	$f2,0x104($s0)
/*  f0d6020:	c60a0100 */ 	lwc1	$f10,0x100($s0)
/*  f0d6024:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d6028:	44816000 */ 	mtc1	$at,$f12
/*  f0d602c:	460a1201 */ 	sub.s	$f8,$f2,$f10
/*  f0d6030:	3c013e00 */ 	lui	$at,0x3e00
/*  f0d6034:	44812000 */ 	mtc1	$at,$f4
/*  f0d6038:	c6060180 */ 	lwc1	$f6,0x180($s0)
/*  f0d603c:	46024003 */ 	div.s	$f0,$f8,$f2
/*  f0d6040:	3c013f40 */ 	lui	$at,0x3f40
/*  f0d6044:	3c0c8007 */ 	lui	$t4,%hi(var80070f4c)
/*  f0d6048:	8d8c0f4c */ 	lw	$t4,%lo(var80070f4c)($t4)
/*  f0d604c:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0d6050:	44813000 */ 	mtc1	$at,$f6
/*  f0d6054:	3c014080 */ 	lui	$at,0x4080
/*  f0d6058:	01916821 */ 	addu	$t5,$t4,$s1
/*  f0d605c:	e7ae012c */ 	swc1	$f14,0x12c($sp)
/*  f0d6060:	e7aa013c */ 	swc1	$f10,0x13c($sp)
/*  f0d6064:	460c0201 */ 	sub.s	$f8,$f0,$f12
/*  f0d6068:	46006281 */ 	sub.s	$f10,$f12,$f0
/*  f0d606c:	46064103 */ 	div.s	$f4,$f8,$f6
/*  f0d6070:	44814000 */ 	mtc1	$at,$f8
/*  f0d6074:	3c018007 */ 	lui	$at,%hi(var80070f4c)
/*  f0d6078:	ac2d0f4c */ 	sw	$t5,%lo(var80070f4c)($at)
/*  f0d607c:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d6080:	e7a60134 */ 	swc1	$f6,0x134($sp)
/*  f0d6084:	e7a40138 */ 	swc1	$f4,0x138($sp)
.L0f0d6088:
/*  f0d6088:	44800000 */ 	mtc1	$zero,$f0
/*  f0d608c:	c7a40138 */ 	lwc1	$f4,0x138($sp)
/*  f0d6090:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d6094:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d6098:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0d609c:	27aa01c8 */ 	addiu	$t2,$sp,0x1c8
/*  f0d60a0:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0d60a4:	3c188007 */ 	lui	$t8,%hi(var80070f20)
/*  f0d60a8:	45030003 */ 	bc1tl	.L0f0d60b8
/*  f0d60ac:	c7aa0134 */ 	lwc1	$f10,0x134($sp)
/*  f0d60b0:	e7a00138 */ 	swc1	$f0,0x138($sp)
/*  f0d60b4:	c7aa0134 */ 	lwc1	$f10,0x134($sp)
.L0f0d60b8:
/*  f0d60b8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0d60bc:	00000000 */ 	nop
/*  f0d60c0:	45010002 */ 	bc1t	.L0f0d60cc
/*  f0d60c4:	00000000 */ 	nop
/*  f0d60c8:	e7a00134 */ 	swc1	$f0,0x134($sp)
.L0f0d60cc:
/*  f0d60cc:	2a21000a */ 	slti	$at,$s1,0xa
/*  f0d60d0:	10200003 */ 	beqz	$at,.L0f0d60e0
/*  f0d60d4:	27ae01a8 */ 	addiu	$t6,$sp,0x1a8
/*  f0d60d8:	10000002 */ 	b	.L0f0d60e4
/*  f0d60dc:	ad510000 */ 	sw	$s1,0x0($t2)
.L0f0d60e0:
/*  f0d60e0:	ad430000 */ 	sw	$v1,0x0($t2)
.L0f0d60e4:
/*  f0d60e4:	2a210008 */ 	slti	$at,$s1,0x8
/*  f0d60e8:	1020000f */ 	beqz	$at,.L0f0d6128
/*  f0d60ec:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f0d60f0:	27af0188 */ 	addiu	$t7,$sp,0x188
/*  f0d60f4:	2a210006 */ 	slti	$at,$s1,0x6
/*  f0d60f8:	004f4821 */ 	addu	$t1,$v0,$t7
/*  f0d60fc:	10200003 */ 	beqz	$at,.L0f0d610c
/*  f0d6100:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f0d6104:	10000002 */ 	b	.L0f0d6110
/*  f0d6108:	ad110000 */ 	sw	$s1,0x0($t0)
.L0f0d610c:
/*  f0d610c:	ad030000 */ 	sw	$v1,0x0($t0)
.L0f0d6110:
/*  f0d6110:	2a210006 */ 	slti	$at,$s1,0x6
/*  f0d6114:	50200004 */ 	beqzl	$at,.L0f0d6128
/*  f0d6118:	ad230000 */ 	sw	$v1,0x0($t1)
/*  f0d611c:	10000002 */ 	b	.L0f0d6128
/*  f0d6120:	ad310000 */ 	sw	$s1,0x0($t1)
/*  f0d6124:	ad230000 */ 	sw	$v1,0x0($t1)
.L0f0d6128:
/*  f0d6128:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0d612c:	2a21000c */ 	slti	$at,$s1,0xc
/*  f0d6130:	1420ffe6 */ 	bnez	$at,.L0f0d60cc
/*  f0d6134:	24420004 */ 	addiu	$v0,$v0,4
/*  f0d6138:	8f180f20 */ 	lw	$t8,%lo(var80070f20)($t8)
/*  f0d613c:	3c017f1b */ 	lui	$at,%hi(var7f1adcc8)
/*  f0d6140:	c424dcc8 */ 	lwc1	$f4,%lo(var7f1adcc8)($at)
/*  f0d6144:	44983000 */ 	mtc1	$t8,$f6
/*  f0d6148:	3c0b8007 */ 	lui	$t3,%hi(var80070f2c)
/*  f0d614c:	8d6b0f2c */ 	lw	$t3,%lo(var80070f2c)($t3)
/*  f0d6150:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f0d6154:	3c198007 */ 	lui	$t9,%hi(var80070f24)
/*  f0d6158:	448b4000 */ 	mtc1	$t3,$f8
/*  f0d615c:	8f390f24 */ 	lw	$t9,%lo(var80070f24)($t9)
/*  f0d6160:	3c017f1b */ 	lui	$at,%hi(var7f1adccc)
/*  f0d6164:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0d6168:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f0d616c:	44802000 */ 	mtc1	$zero,$f4
/*  f0d6170:	3c0d8007 */ 	lui	$t5,%hi(var80070f28)
/*  f0d6174:	8dad0f28 */ 	lw	$t5,%lo(var80070f28)($t5)
/*  f0d6178:	e7a4033c */ 	swc1	$f4,0x33c($sp)
/*  f0d617c:	44802000 */ 	mtc1	$zero,$f4
/*  f0d6180:	3c0c8007 */ 	lui	$t4,%hi(var80070f30)
/*  f0d6184:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f0d6188:	44995000 */ 	mtc1	$t9,$f10
/*  f0d618c:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*  f0d6190:	e7a40344 */ 	swc1	$f4,0x344($sp)
/*  f0d6194:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0d6198:	44805000 */ 	mtc1	$zero,$f10
/*  f0d619c:	e7a80048 */ 	swc1	$f8,0x48($sp)
/*  f0d61a0:	8d8c0f30 */ 	lw	$t4,%lo(var80070f30)($t4)
/*  f0d61a4:	e7aa0348 */ 	swc1	$f10,0x348($sp)
/*  f0d61a8:	46086180 */ 	add.s	$f6,$f12,$f8
/*  f0d61ac:	e7ac0388 */ 	swc1	$f12,0x388($sp)
/*  f0d61b0:	e7ac0390 */ 	swc1	$f12,0x390($sp)
/*  f0d61b4:	e7ac02ac */ 	swc1	$f12,0x2ac($sp)
/*  f0d61b8:	e7a60338 */ 	swc1	$f6,0x338($sp)
/*  f0d61bc:	46106180 */ 	add.s	$f6,$f12,$f16
/*  f0d61c0:	e7ac02b4 */ 	swc1	$f12,0x2b4($sp)
/*  f0d61c4:	3c0e8007 */ 	lui	$t6,%hi(var80070f34)
/*  f0d61c8:	3c0f8007 */ 	lui	$t7,%hi(var80070f5c)
/*  f0d61cc:	e7a60340 */ 	swc1	$f6,0x340($sp)
/*  f0d61d0:	c426dccc */ 	lwc1	$f6,%lo(var7f1adccc)($at)
/*  f0d61d4:	3c017f1b */ 	lui	$at,%hi(var7f1adcd0)
/*  f0d61d8:	c42adcd0 */ 	lwc1	$f10,%lo(var7f1adcd0)($at)
/*  f0d61dc:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0d61e0:	3c017f1b */ 	lui	$at,%hi(var7f1adcd4)
/*  f0d61e4:	3c0b8007 */ 	lui	$t3,%hi(var80070f50)
/*  f0d61e8:	460a2482 */ 	mul.s	$f18,$f4,$f10
/*  f0d61ec:	c7a4012c */ 	lwc1	$f4,0x12c($sp)
/*  f0d61f0:	c42adcd4 */ 	lwc1	$f10,%lo(var7f1adcd4)($at)
/*  f0d61f4:	3c017f1b */ 	lui	$at,%hi(var7f1adcd8)
/*  f0d61f8:	46040082 */ 	mul.s	$f2,$f0,$f4
/*  f0d61fc:	46126180 */ 	add.s	$f6,$f12,$f18
/*  f0d6200:	e7a2038c */ 	swc1	$f2,0x38c($sp)
/*  f0d6204:	e7a203a0 */ 	swc1	$f2,0x3a0($sp)
/*  f0d6208:	e7a6034c */ 	swc1	$f6,0x34c($sp)
/*  f0d620c:	460a1182 */ 	mul.s	$f6,$f2,$f10
/*  f0d6210:	e7a60080 */ 	swc1	$f6,0x80($sp)
/*  f0d6214:	c426dcd8 */ 	lwc1	$f6,%lo(var7f1adcd8)($at)
/*  f0d6218:	3c017f1b */ 	lui	$at,%hi(var7f1adcdc)
/*  f0d621c:	c7aa0080 */ 	lwc1	$f10,0x80($sp)
/*  f0d6220:	46068182 */ 	mul.s	$f6,$f16,$f6
/*  f0d6224:	e7aa0350 */ 	swc1	$f10,0x350($sp)
/*  f0d6228:	46048382 */ 	mul.s	$f14,$f16,$f4
/*  f0d622c:	e7aa03dc */ 	swc1	$f10,0x3dc($sp)
/*  f0d6230:	e7a6007c */ 	swc1	$f6,0x7c($sp)
/*  f0d6234:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*  f0d6238:	e7ae0394 */ 	swc1	$f14,0x394($sp)
/*  f0d623c:	46066180 */ 	add.s	$f6,$f12,$f6
/*  f0d6240:	e7ae03a8 */ 	swc1	$f14,0x3a8($sp)
/*  f0d6244:	e7a60354 */ 	swc1	$f6,0x354($sp)
/*  f0d6248:	c426dcdc */ 	lwc1	$f6,%lo(var7f1adcdc)($at)
/*  f0d624c:	3c017f1b */ 	lui	$at,%hi(var7f1adce0)
/*  f0d6250:	46067182 */ 	mul.s	$f6,$f14,$f6
/*  f0d6254:	e7a60074 */ 	swc1	$f6,0x74($sp)
/*  f0d6258:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f0d625c:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f0d6260:	e7a60358 */ 	swc1	$f6,0x358($sp)
/*  f0d6264:	c426dce0 */ 	lwc1	$f6,%lo(var7f1adce0)($at)
/*  f0d6268:	3c017f1b */ 	lui	$at,%hi(var7f1adce4)
/*  f0d626c:	e7aa03e4 */ 	swc1	$f10,0x3e4($sp)
/*  f0d6270:	e7a6035c */ 	swc1	$f6,0x35c($sp)
/*  f0d6274:	c426dce4 */ 	lwc1	$f6,%lo(var7f1adce4)($at)
/*  f0d6278:	3c017f1b */ 	lui	$at,%hi(var7f1adce8)
/*  f0d627c:	c428dce8 */ 	lwc1	$f8,%lo(var7f1adce8)($at)
/*  f0d6280:	46060182 */ 	mul.s	$f6,$f0,$f6
/*  f0d6284:	3c017f1b */ 	lui	$at,%hi(var7f1adcec)
/*  f0d6288:	c7aa0048 */ 	lwc1	$f10,0x48($sp)
/*  f0d628c:	46083182 */ 	mul.s	$f6,$f6,$f8
/*  f0d6290:	e7a60070 */ 	swc1	$f6,0x70($sp)
/*  f0d6294:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*  f0d6298:	46086180 */ 	add.s	$f6,$f12,$f8
/*  f0d629c:	c428dcec */ 	lwc1	$f8,%lo(var7f1adcec)($at)
/*  f0d62a0:	3c017f1b */ 	lui	$at,%hi(var7f1adcf0)
/*  f0d62a4:	e7a60360 */ 	swc1	$f6,0x360($sp)
/*  f0d62a8:	46081182 */ 	mul.s	$f6,$f2,$f8
/*  f0d62ac:	e7a6006c */ 	swc1	$f6,0x6c($sp)
/*  f0d62b0:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f0d62b4:	c426dcf0 */ 	lwc1	$f6,%lo(var7f1adcf0)($at)
/*  f0d62b8:	3c017f1b */ 	lui	$at,%hi(var7f1adcf4)
/*  f0d62bc:	e7a80364 */ 	swc1	$f8,0x364($sp)
/*  f0d62c0:	46068202 */ 	mul.s	$f8,$f16,$f6
/*  f0d62c4:	e7a80068 */ 	swc1	$f8,0x68($sp)
/*  f0d62c8:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*  f0d62cc:	46066200 */ 	add.s	$f8,$f12,$f6
/*  f0d62d0:	c426dcf4 */ 	lwc1	$f6,%lo(var7f1adcf4)($at)
/*  f0d62d4:	3c017f1b */ 	lui	$at,%hi(var7f1adcf8)
/*  f0d62d8:	e7a80368 */ 	swc1	$f8,0x368($sp)
/*  f0d62dc:	46067202 */ 	mul.s	$f8,$f14,$f6
/*  f0d62e0:	e7a80064 */ 	swc1	$f8,0x64($sp)
/*  f0d62e4:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f0d62e8:	c428dcf8 */ 	lwc1	$f8,%lo(var7f1adcf8)($at)
/*  f0d62ec:	3c017f1b */ 	lui	$at,%hi(var7f1adcfc)
/*  f0d62f0:	e7a6036c */ 	swc1	$f6,0x36c($sp)
/*  f0d62f4:	c426dcfc */ 	lwc1	$f6,%lo(var7f1adcfc)($at)
/*  f0d62f8:	e7a80370 */ 	swc1	$f8,0x370($sp)
/*  f0d62fc:	3c017f1b */ 	lui	$at,%hi(var7f1add00)
/*  f0d6300:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0d6304:	44800000 */ 	mtc1	$zero,$f0
/*  f0d6308:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f0d630c:	c7a60060 */ 	lwc1	$f6,0x60($sp)
/*  f0d6310:	46066200 */ 	add.s	$f8,$f12,$f6
/*  f0d6314:	c426dd00 */ 	lwc1	$f6,%lo(var7f1add00)($at)
/*  f0d6318:	3c017f1b */ 	lui	$at,%hi(var7f1add04)
/*  f0d631c:	e7a80374 */ 	swc1	$f8,0x374($sp)
/*  f0d6320:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0d6324:	e7a8005c */ 	swc1	$f8,0x5c($sp)
/*  f0d6328:	c7a6005c */ 	lwc1	$f6,0x5c($sp)
/*  f0d632c:	c428dd04 */ 	lwc1	$f8,%lo(var7f1add04)($at)
/*  f0d6330:	3c017f1b */ 	lui	$at,%hi(var7f1add08)
/*  f0d6334:	e7a60378 */ 	swc1	$f6,0x378($sp)
/*  f0d6338:	46088182 */ 	mul.s	$f6,$f16,$f8
/*  f0d633c:	e7a60058 */ 	swc1	$f6,0x58($sp)
/*  f0d6340:	c7a80058 */ 	lwc1	$f8,0x58($sp)
/*  f0d6344:	46086180 */ 	add.s	$f6,$f12,$f8
/*  f0d6348:	c428dd08 */ 	lwc1	$f8,%lo(var7f1add08)($at)
/*  f0d634c:	3c017f1b */ 	lui	$at,%hi(var7f1add0c)
/*  f0d6350:	e7a6037c */ 	swc1	$f6,0x37c($sp)
/*  f0d6354:	46087182 */ 	mul.s	$f6,$f14,$f8
/*  f0d6358:	e7a60054 */ 	swc1	$f6,0x54($sp)
/*  f0d635c:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f0d6360:	c426dd0c */ 	lwc1	$f6,%lo(var7f1add0c)($at)
/*  f0d6364:	3c017f1b */ 	lui	$at,%hi(var7f1add10)
/*  f0d6368:	e7a80380 */ 	swc1	$f8,0x380($sp)
/*  f0d636c:	c428dd10 */ 	lwc1	$f8,%lo(var7f1add10)($at)
/*  f0d6370:	e7a60384 */ 	swc1	$f6,0x384($sp)
/*  f0d6374:	44803000 */ 	mtc1	$zero,$f6
/*  f0d6378:	e7a80398 */ 	swc1	$f8,0x398($sp)
/*  f0d637c:	44804000 */ 	mtc1	$zero,$f8
/*  f0d6380:	3c017f1b */ 	lui	$at,%hi(var7f1add14)
/*  f0d6384:	e7a6039c */ 	swc1	$f6,0x39c($sp)
/*  f0d6388:	c426dd14 */ 	lwc1	$f6,%lo(var7f1add14)($at)
/*  f0d638c:	e7a803a4 */ 	swc1	$f8,0x3a4($sp)
/*  f0d6390:	c7a80060 */ 	lwc1	$f8,0x60($sp)
/*  f0d6394:	e7a603ac */ 	swc1	$f6,0x3ac($sp)
/*  f0d6398:	3c017f1b */ 	lui	$at,%hi(var7f1add18)
/*  f0d639c:	46080181 */ 	sub.s	$f6,$f0,$f8
/*  f0d63a0:	c7a8005c */ 	lwc1	$f8,0x5c($sp)
/*  f0d63a4:	e7a603b0 */ 	swc1	$f6,0x3b0($sp)
/*  f0d63a8:	c7a60058 */ 	lwc1	$f6,0x58($sp)
/*  f0d63ac:	e7a803b4 */ 	swc1	$f8,0x3b4($sp)
/*  f0d63b0:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f0d63b4:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f0d63b8:	e7a803b8 */ 	swc1	$f8,0x3b8($sp)
/*  f0d63bc:	c428dd18 */ 	lwc1	$f8,%lo(var7f1add18)($at)
/*  f0d63c0:	e7a603bc */ 	swc1	$f6,0x3bc($sp)
/*  f0d63c4:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f0d63c8:	e7a803c0 */ 	swc1	$f8,0x3c0($sp)
/*  f0d63cc:	3c017f1b */ 	lui	$at,%hi(var7f1add1c)
/*  f0d63d0:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f0d63d4:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f0d63d8:	e7a803c4 */ 	swc1	$f8,0x3c4($sp)
/*  f0d63dc:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*  f0d63e0:	e7a603c8 */ 	swc1	$f6,0x3c8($sp)
/*  f0d63e4:	46080181 */ 	sub.s	$f6,$f0,$f8
/*  f0d63e8:	c7a80064 */ 	lwc1	$f8,0x64($sp)
/*  f0d63ec:	e7a603cc */ 	swc1	$f6,0x3cc($sp)
/*  f0d63f0:	c426dd1c */ 	lwc1	$f6,%lo(var7f1add1c)($at)
/*  f0d63f4:	e7a803d0 */ 	swc1	$f8,0x3d0($sp)
/*  f0d63f8:	46120201 */ 	sub.s	$f8,$f0,$f18
/*  f0d63fc:	e7a603d4 */ 	swc1	$f6,0x3d4($sp)
/*  f0d6400:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*  f0d6404:	3c017f1b */ 	lui	$at,%hi(var7f1add20)
/*  f0d6408:	e7a803d8 */ 	swc1	$f8,0x3d8($sp)
/*  f0d640c:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f0d6410:	c426dd20 */ 	lwc1	$f6,%lo(var7f1add20)($at)
/*  f0d6414:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d6418:	e7a803e0 */ 	swc1	$f8,0x3e0($sp)
/*  f0d641c:	44804000 */ 	mtc1	$zero,$f8
/*  f0d6420:	e7a603e8 */ 	swc1	$f6,0x3e8($sp)
/*  f0d6424:	460a4181 */ 	sub.s	$f6,$f8,$f10
/*  f0d6428:	44804000 */ 	mtc1	$zero,$f8
/*  f0d642c:	44805000 */ 	mtc1	$zero,$f10
/*  f0d6430:	e7a803f0 */ 	swc1	$f8,0x3f0($sp)
/*  f0d6434:	44804000 */ 	mtc1	$zero,$f8
/*  f0d6438:	e7a603ec */ 	swc1	$f6,0x3ec($sp)
/*  f0d643c:	46105181 */ 	sub.s	$f6,$f10,$f16
/*  f0d6440:	e7a803f8 */ 	swc1	$f8,0x3f8($sp)
/*  f0d6444:	448d4000 */ 	mtc1	$t5,$f8
/*  f0d6448:	44815000 */ 	mtc1	$at,$f10
/*  f0d644c:	e7a603f4 */ 	swc1	$f6,0x3f4($sp)
/*  f0d6450:	468043a0 */ 	cvt.s.w	$f14,$f8
/*  f0d6454:	448c3000 */ 	mtc1	$t4,$f6
/*  f0d6458:	3c017f1b */ 	lui	$at,%hi(var7f1add24)
/*  f0d645c:	e7aa03fc */ 	swc1	$f10,0x3fc($sp)
/*  f0d6460:	c428dd24 */ 	lwc1	$f8,%lo(var7f1add24)($at)
/*  f0d6464:	46002287 */ 	neg.s	$f10,$f4
/*  f0d6468:	46047002 */ 	mul.s	$f0,$f14,$f4
/*  f0d646c:	3c017f1b */ 	lui	$at,%hi(var7f1add28)
/*  f0d6470:	c424dd28 */ 	lwc1	$f4,%lo(var7f1add28)($at)
/*  f0d6474:	460e5082 */ 	mul.s	$f2,$f10,$f14
/*  f0d6478:	3c017f1b */ 	lui	$at,%hi(var7f1add2c)
/*  f0d647c:	e7a802bc */ 	swc1	$f8,0x2bc($sp)
/*  f0d6480:	46047282 */ 	mul.s	$f10,$f14,$f4
/*  f0d6484:	e7a0029c */ 	swc1	$f0,0x29c($sp)
/*  f0d6488:	e7a002b0 */ 	swc1	$f0,0x2b0($sp)
/*  f0d648c:	e7a202a4 */ 	swc1	$f2,0x2a4($sp)
/*  f0d6490:	e7a202b8 */ 	swc1	$f2,0x2b8($sp)
/*  f0d6494:	468034a0 */ 	cvt.s.w	$f18,$f6
/*  f0d6498:	44803000 */ 	mtc1	$zero,$f6
/*  f0d649c:	00000000 */ 	nop
/*  f0d64a0:	e7a602a8 */ 	swc1	$f6,0x2a8($sp)
/*  f0d64a4:	c426dd2c */ 	lwc1	$f6,%lo(var7f1add2c)($at)
/*  f0d64a8:	3c017f1b */ 	lui	$at,%hi(var7f1add30)
/*  f0d64ac:	c424dd30 */ 	lwc1	$f4,%lo(var7f1add30)($at)
/*  f0d64b0:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0d64b4:	460a6400 */ 	add.s	$f16,$f12,$f10
/*  f0d64b8:	3c017f1b */ 	lui	$at,%hi(var7f1add34)
/*  f0d64bc:	46041282 */ 	mul.s	$f10,$f2,$f4
/*  f0d64c0:	c426dd34 */ 	lwc1	$f6,%lo(var7f1add34)($at)
/*  f0d64c4:	3c017f1b */ 	lui	$at,%hi(var7f1add38)
/*  f0d64c8:	e7b20298 */ 	swc1	$f18,0x298($sp)
/*  f0d64cc:	e7a802c4 */ 	swc1	$f8,0x2c4($sp)
/*  f0d64d0:	c428dd38 */ 	lwc1	$f8,%lo(var7f1add38)($at)
/*  f0d64d4:	3c017f1b */ 	lui	$at,%hi(var7f1add3c)
/*  f0d64d8:	e7aa02cc */ 	swc1	$f10,0x2cc($sp)
/*  f0d64dc:	46087102 */ 	mul.s	$f4,$f14,$f8
/*  f0d64e0:	c42add3c */ 	lwc1	$f10,%lo(var7f1add3c)($at)
/*  f0d64e4:	e7a602d0 */ 	swc1	$f6,0x2d0($sp)
/*  f0d64e8:	3c017f1b */ 	lui	$at,%hi(var7f1add40)
/*  f0d64ec:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0d64f0:	c428dd40 */ 	lwc1	$f8,%lo(var7f1add40)($at)
/*  f0d64f4:	3c017f1b */ 	lui	$at,%hi(var7f1add44)
/*  f0d64f8:	c42add44 */ 	lwc1	$f10,%lo(var7f1add44)($at)
/*  f0d64fc:	e7b202a0 */ 	swc1	$f18,0x2a0($sp)
/*  f0d6500:	46046480 */ 	add.s	$f18,$f12,$f4
/*  f0d6504:	3c017f1b */ 	lui	$at,%hi(var7f1add48)
/*  f0d6508:	e7a602d8 */ 	swc1	$f6,0x2d8($sp)
/*  f0d650c:	46081102 */ 	mul.s	$f4,$f2,$f8
/*  f0d6510:	c426dd48 */ 	lwc1	$f6,%lo(var7f1add48)($at)
/*  f0d6514:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d6518:	e7aa02e4 */ 	swc1	$f10,0x2e4($sp)
/*  f0d651c:	46067202 */ 	mul.s	$f8,$f14,$f6
/*  f0d6520:	44813000 */ 	mtc1	$at,$f6
/*  f0d6524:	e7b002c0 */ 	swc1	$f16,0x2c0($sp)
/*  f0d6528:	e7a402e0 */ 	swc1	$f4,0x2e0($sp)
/*  f0d652c:	e7b002c8 */ 	swc1	$f16,0x2c8($sp)
/*  f0d6530:	e7b202d4 */ 	swc1	$f18,0x2d4($sp)
/*  f0d6534:	e7b202dc */ 	swc1	$f18,0x2dc($sp)
/*  f0d6538:	46086100 */ 	add.s	$f4,$f12,$f8
/*  f0d653c:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0d6540:	e7a40090 */ 	swc1	$f4,0x90($sp)
/*  f0d6544:	c7aa0090 */ 	lwc1	$f10,0x90($sp)
/*  f0d6548:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f0d654c:	e7aa02e8 */ 	swc1	$f10,0x2e8($sp)
/*  f0d6550:	44815000 */ 	mtc1	$at,$f10
/*  f0d6554:	e7a802ec */ 	swc1	$f8,0x2ec($sp)
/*  f0d6558:	3c017f1b */ 	lui	$at,%hi(var7f1add4c)
/*  f0d655c:	460a1182 */ 	mul.s	$f6,$f2,$f10
/*  f0d6560:	c428dd4c */ 	lwc1	$f8,%lo(var7f1add4c)($at)
/*  f0d6564:	3c017f1b */ 	lui	$at,%hi(var7f1add50)
/*  f0d6568:	e7a402f0 */ 	swc1	$f4,0x2f0($sp)
/*  f0d656c:	c424dd50 */ 	lwc1	$f4,%lo(var7f1add50)($at)
/*  f0d6570:	3c017f1b */ 	lui	$at,%hi(var7f1add54)
/*  f0d6574:	e7a802f8 */ 	swc1	$f8,0x2f8($sp)
/*  f0d6578:	46047282 */ 	mul.s	$f10,$f14,$f4
/*  f0d657c:	e7a602f4 */ 	swc1	$f6,0x2f4($sp)
/*  f0d6580:	c426dd54 */ 	lwc1	$f6,%lo(var7f1add54)($at)
/*  f0d6584:	3c017f1b */ 	lui	$at,%hi(var7f1add58)
/*  f0d6588:	c424dd58 */ 	lwc1	$f4,%lo(var7f1add58)($at)
/*  f0d658c:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0d6590:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d6594:	460a6400 */ 	add.s	$f16,$f12,$f10
/*  f0d6598:	46041282 */ 	mul.s	$f10,$f2,$f4
/*  f0d659c:	44813000 */ 	mtc1	$at,$f6
/*  f0d65a0:	44802000 */ 	mtc1	$zero,$f4
/*  f0d65a4:	e7b002fc */ 	swc1	$f16,0x2fc($sp)
/*  f0d65a8:	e7a80300 */ 	swc1	$f8,0x300($sp)
/*  f0d65ac:	e7b00304 */ 	swc1	$f16,0x304($sp)
/*  f0d65b0:	3c017f1b */ 	lui	$at,%hi(var7f1add5c)
/*  f0d65b4:	e7aa0308 */ 	swc1	$f10,0x308($sp)
/*  f0d65b8:	8dce0f34 */ 	lw	$t6,%lo(var80070f34)($t6)
/*  f0d65bc:	44805000 */ 	mtc1	$zero,$f10
/*  f0d65c0:	e7a6030c */ 	swc1	$f6,0x30c($sp)
/*  f0d65c4:	448e4000 */ 	mtc1	$t6,$f8
/*  f0d65c8:	44803000 */ 	mtc1	$zero,$f6
/*  f0d65cc:	e7aa020c */ 	swc1	$f10,0x20c($sp)
/*  f0d65d0:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0d65d4:	c428dd5c */ 	lwc1	$f8,%lo(var7f1add5c)($at)
/*  f0d65d8:	3c017f1b */ 	lui	$at,%hi(var7f1add60)
/*  f0d65dc:	c42add60 */ 	lwc1	$f10,%lo(var7f1add60)($at)
/*  f0d65e0:	e7a60214 */ 	swc1	$f6,0x214($sp)
/*  f0d65e4:	e7a40208 */ 	swc1	$f4,0x208($sp)
/*  f0d65e8:	460a7182 */ 	mul.s	$f6,$f14,$f10
/*  f0d65ec:	44802000 */ 	mtc1	$zero,$f4
/*  f0d65f0:	3c017f1b */ 	lui	$at,%hi(var7f1add64)
/*  f0d65f4:	e7a8021c */ 	swc1	$f8,0x21c($sp)
/*  f0d65f8:	c428dd64 */ 	lwc1	$f8,%lo(var7f1add64)($at)
/*  f0d65fc:	3c017f1b */ 	lui	$at,%hi(var7f1add68)
/*  f0d6600:	e7b201f8 */ 	swc1	$f18,0x1f8($sp)
/*  f0d6604:	46062301 */ 	sub.s	$f12,$f4,$f6
/*  f0d6608:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0d660c:	c424dd68 */ 	lwc1	$f4,%lo(var7f1add68)($at)
/*  f0d6610:	3c017f1b */ 	lui	$at,%hi(var7f1add6c)
/*  f0d6614:	c428dd6c */ 	lwc1	$f8,%lo(var7f1add6c)($at)
/*  f0d6618:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f0d661c:	3c017f1b */ 	lui	$at,%hi(var7f1add70)
/*  f0d6620:	c424dd70 */ 	lwc1	$f4,%lo(var7f1add70)($at)
/*  f0d6624:	e7aa0224 */ 	swc1	$f10,0x224($sp)
/*  f0d6628:	44805000 */ 	mtc1	$zero,$f10
/*  f0d662c:	3c017f1b */ 	lui	$at,%hi(var7f1add74)
/*  f0d6630:	e7a80230 */ 	swc1	$f8,0x230($sp)
/*  f0d6634:	e7a6022c */ 	swc1	$f6,0x22c($sp)
/*  f0d6638:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f0d663c:	c428dd74 */ 	lwc1	$f8,%lo(var7f1add74)($at)
/*  f0d6640:	3c017f1b */ 	lui	$at,%hi(var7f1add78)
/*  f0d6644:	e7b20200 */ 	swc1	$f18,0x200($sp)
/*  f0d6648:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f0d664c:	e7a001fc */ 	swc1	$f0,0x1fc($sp)
/*  f0d6650:	e7a00210 */ 	swc1	$f0,0x210($sp)
/*  f0d6654:	8def0f5c */ 	lw	$t7,%lo(var80070f5c)($t7)
/*  f0d6658:	e7a20204 */ 	swc1	$f2,0x204($sp)
/*  f0d665c:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0d6660:	c42add78 */ 	lwc1	$f10,%lo(var7f1add78)($at)
/*  f0d6664:	3c017f1b */ 	lui	$at,%hi(var7f1add7c)
/*  f0d6668:	c428dd7c */ 	lwc1	$f8,%lo(var7f1add7c)($at)
/*  f0d666c:	460a1182 */ 	mul.s	$f6,$f2,$f10
/*  f0d6670:	3c017f1b */ 	lui	$at,%hi(var7f1add80)
/*  f0d6674:	c42add80 */ 	lwc1	$f10,%lo(var7f1add80)($at)
/*  f0d6678:	3c017f1b */ 	lui	$at,%hi(var7f1add84)
/*  f0d667c:	e7a80244 */ 	swc1	$f8,0x244($sp)
/*  f0d6680:	c428dd84 */ 	lwc1	$f8,%lo(var7f1add84)($at)
/*  f0d6684:	e7a40238 */ 	swc1	$f4,0x238($sp)
/*  f0d6688:	e7a60240 */ 	swc1	$f6,0x240($sp)
/*  f0d668c:	460a7182 */ 	mul.s	$f6,$f14,$f10
/*  f0d6690:	44802000 */ 	mtc1	$zero,$f4
/*  f0d6694:	3c017f1b */ 	lui	$at,%hi(var7f1add88)
/*  f0d6698:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0d669c:	e7a20218 */ 	swc1	$f2,0x218($sp)
/*  f0d66a0:	e7ac0220 */ 	swc1	$f12,0x220($sp)
/*  f0d66a4:	e7ac0228 */ 	swc1	$f12,0x228($sp)
/*  f0d66a8:	e7b00234 */ 	swc1	$f16,0x234($sp)
/*  f0d66ac:	46062481 */ 	sub.s	$f18,$f4,$f6
/*  f0d66b0:	c424dd88 */ 	lwc1	$f4,%lo(var7f1add88)($at)
/*  f0d66b4:	e7aa024c */ 	swc1	$f10,0x24c($sp)
/*  f0d66b8:	44805000 */ 	mtc1	$zero,$f10
/*  f0d66bc:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f0d66c0:	3c017f1b */ 	lui	$at,%hi(var7f1add8c)
/*  f0d66c4:	c428dd8c */ 	lwc1	$f8,%lo(var7f1add8c)($at)
/*  f0d66c8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d66cc:	44802000 */ 	mtc1	$zero,$f4
/*  f0d66d0:	460e5001 */ 	sub.s	$f0,$f10,$f14
/*  f0d66d4:	e7a80258 */ 	swc1	$f8,0x258($sp)
/*  f0d66d8:	e7a60254 */ 	swc1	$f6,0x254($sp)
/*  f0d66dc:	44803000 */ 	mtc1	$zero,$f6
/*  f0d66e0:	44814000 */ 	mtc1	$at,$f8
/*  f0d66e4:	e7b0023c */ 	swc1	$f16,0x23c($sp)
/*  f0d66e8:	e7b20248 */ 	swc1	$f18,0x248($sp)
/*  f0d66ec:	e7b20250 */ 	swc1	$f18,0x250($sp)
/*  f0d66f0:	e7a0025c */ 	swc1	$f0,0x25c($sp)
/*  f0d66f4:	e7a00264 */ 	swc1	$f0,0x264($sp)
/*  f0d66f8:	e7a40260 */ 	swc1	$f4,0x260($sp)
/*  f0d66fc:	e7a60268 */ 	swc1	$f6,0x268($sp)
/*  f0d6700:	11e00006 */ 	beqz	$t7,.L0f0d671c
/*  f0d6704:	e7a8026c */ 	swc1	$f8,0x26c($sp)
/*  f0d6708:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d670c:	44815000 */ 	mtc1	$at,$f10
/*  f0d6710:	c7a4013c */ 	lwc1	$f4,0x13c($sp)
/*  f0d6714:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0d6718:	e7a6013c */ 	swc1	$f6,0x13c($sp)
.L0f0d671c:
/*  f0d671c:	8d6b0f50 */ 	lw	$t3,%lo(var80070f50)($t3)
/*  f0d6720:	3c017f1b */ 	lui	$at,%hi(var7f1add90)
/*  f0d6724:	c424dd90 */ 	lwc1	$f4,%lo(var7f1add90)($at)
/*  f0d6728:	448b4000 */ 	mtc1	$t3,$f8
/*  f0d672c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d6730:	44813000 */ 	mtc1	$at,$f6
/*  f0d6734:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d6738:	27b001c8 */ 	addiu	$s0,$sp,0x1c8
/*  f0d673c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0d6740:	27a40338 */ 	addiu	$a0,$sp,0x338
/*  f0d6744:	2406000c */ 	addiu	$a2,$zero,0xc
/*  f0d6748:	46045002 */ 	mul.s	$f0,$f10,$f4
/*  f0d674c:	c7aa013c */ 	lwc1	$f10,0x13c($sp)
/*  f0d6750:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0d6754:	460a4082 */ 	mul.s	$f2,$f8,$f10
/*  f0d6758:	46001301 */ 	sub.s	$f12,$f2,$f0
/*  f0d675c:	e7a20164 */ 	swc1	$f2,0x164($sp)
/*  f0d6760:	44076000 */ 	mfc1	$a3,$f12
/*  f0d6764:	0fc356a4 */ 	jal	func0f0d5a90
/*  f0d6768:	e7ac0160 */ 	swc1	$f12,0x160($sp)
/*  f0d676c:	2458000a */ 	addiu	$t8,$v0,0xa
/*  f0d6770:	afb80148 */ 	sw	$t8,0x148($sp)
/*  f0d6774:	27a40338 */ 	addiu	$a0,$sp,0x338
/*  f0d6778:	02002825 */ 	or	$a1,$s0,$zero
/*  f0d677c:	2406000c */ 	addiu	$a2,$zero,0xc
/*  f0d6780:	0fc356a4 */ 	jal	func0f0d5a90
/*  f0d6784:	8fa70164 */ 	lw	$a3,0x164($sp)
/*  f0d6788:	8fb90148 */ 	lw	$t9,0x148($sp)
/*  f0d678c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d6790:	03226021 */ 	addu	$t4,$t9,$v0
/*  f0d6794:	19800057 */ 	blez	$t4,.L0f0d68f4
/*  f0d6798:	afac0148 */ 	sw	$t4,0x148($sp)
/*  f0d679c:	27aa01c8 */ 	addiu	$t2,$sp,0x1c8
/*  f0d67a0:	24140014 */ 	addiu	$s4,$zero,0x14
.L0f0d67a4:
/*  f0d67a4:	3c0d8007 */ 	lui	$t5,%hi(var80070f5c)
/*  f0d67a8:	8dad0f5c */ 	lw	$t5,%lo(var80070f5c)($t5)
/*  f0d67ac:	8d420000 */ 	lw	$v0,0x0($t2)
/*  f0d67b0:	11a00011 */ 	beqz	$t5,.L0f0d67f8
/*  f0d67b4:	00000000 */ 	nop
/*  f0d67b8:	00540019 */ 	multu	$v0,$s4
/*  f0d67bc:	27af0338 */ 	addiu	$t7,$sp,0x338
/*  f0d67c0:	3c048007 */ 	lui	$a0,%hi(var80070f44)
/*  f0d67c4:	3c058007 */ 	lui	$a1,%hi(var80070f38)
/*  f0d67c8:	8ca50f38 */ 	lw	$a1,%lo(var80070f38)($a1)
/*  f0d67cc:	8c840f44 */ 	lw	$a0,%lo(var80070f44)($a0)
/*  f0d67d0:	8fa60160 */ 	lw	$a2,0x160($sp)
/*  f0d67d4:	8fa70164 */ 	lw	$a3,0x164($sp)
/*  f0d67d8:	00007012 */ 	mflo	$t6
/*  f0d67dc:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f0d67e0:	c6040010 */ 	lwc1	$f4,0x10($s0)
/*  f0d67e4:	afaa0094 */ 	sw	$t2,0x94($sp)
/*  f0d67e8:	0fc35718 */ 	jal	func0f0d5c60
/*  f0d67ec:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0d67f0:	10000010 */ 	b	.L0f0d6834
/*  f0d67f4:	8faa0094 */ 	lw	$t2,0x94($sp)
.L0f0d67f8:
/*  f0d67f8:	00540019 */ 	multu	$v0,$s4
/*  f0d67fc:	27b80338 */ 	addiu	$t8,$sp,0x338
/*  f0d6800:	3c048007 */ 	lui	$a0,%hi(var80070f38)
/*  f0d6804:	3c058007 */ 	lui	$a1,%hi(var80070f44)
/*  f0d6808:	8ca50f44 */ 	lw	$a1,%lo(var80070f44)($a1)
/*  f0d680c:	8c840f38 */ 	lw	$a0,%lo(var80070f38)($a0)
/*  f0d6810:	8fa60160 */ 	lw	$a2,0x160($sp)
/*  f0d6814:	8fa70164 */ 	lw	$a3,0x164($sp)
/*  f0d6818:	00005812 */ 	mflo	$t3
/*  f0d681c:	01788021 */ 	addu	$s0,$t3,$t8
/*  f0d6820:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*  f0d6824:	afaa0094 */ 	sw	$t2,0x94($sp)
/*  f0d6828:	0fc35718 */ 	jal	func0f0d5c60
/*  f0d682c:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f0d6830:	8faa0094 */ 	lw	$t2,0x94($sp)
.L0f0d6834:
/*  f0d6834:	c6080000 */ 	lwc1	$f8,0x0($s0)
/*  f0d6838:	3c0d8007 */ 	lui	$t5,%hi(var80070f48)
/*  f0d683c:	8dad0f48 */ 	lw	$t5,%lo(var80070f48)($t5)
/*  f0d6840:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d6844:	a6400002 */ 	sh	$zero,0x2($s2)
/*  f0d6848:	3c188007 */ 	lui	$t8,%hi(var80070f4c)
/*  f0d684c:	02311821 */ 	addu	$v1,$s1,$s1
/*  f0d6850:	440c5000 */ 	mfc1	$t4,$f10
/*  f0d6854:	3c0f8007 */ 	lui	$t7,%hi(var80070f48)
/*  f0d6858:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0d685c:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0d6860:	a64e0000 */ 	sh	$t6,0x0($s2)
/*  f0d6864:	c6040004 */ 	lwc1	$f4,0x4($s0)
/*  f0d6868:	8f180f4c */ 	lw	$t8,%lo(var80070f4c)($t8)
/*  f0d686c:	00036080 */ 	sll	$t4,$v1,0x2
/*  f0d6870:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d6874:	a24c0007 */ 	sb	$t4,0x7($s2)
/*  f0d6878:	3c0c8007 */ 	lui	$t4,%hi(var80070f4c)
/*  f0d687c:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f0d6880:	440b3000 */ 	mfc1	$t3,$f6
/*  f0d6884:	26520018 */ 	addiu	$s2,$s2,0x18
/*  f0d6888:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f0d688c:	0178c821 */ 	addu	$t9,$t3,$t8
/*  f0d6890:	a659ffec */ 	sh	$t9,-0x14($s2)
/*  f0d6894:	aec2fff8 */ 	sw	$v0,-0x8($s6)
/*  f0d6898:	c6080008 */ 	lwc1	$f8,0x8($s0)
/*  f0d689c:	8def0f48 */ 	lw	$t7,%lo(var80070f48)($t7)
/*  f0d68a0:	a640fff6 */ 	sh	$zero,-0xa($s2)
/*  f0d68a4:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d68a8:	440e5000 */ 	mfc1	$t6,$f10
/*  f0d68ac:	00000000 */ 	nop
/*  f0d68b0:	01cf5821 */ 	addu	$t3,$t6,$t7
/*  f0d68b4:	a64bfff4 */ 	sh	$t3,-0xc($s2)
/*  f0d68b8:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f0d68bc:	8d8c0f4c */ 	lw	$t4,%lo(var80070f4c)($t4)
/*  f0d68c0:	246e0001 */ 	addiu	$t6,$v1,0x1
/*  f0d68c4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d68c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0d68cc:	a24ffffb */ 	sb	$t7,-0x5($s2)
/*  f0d68d0:	44193000 */ 	mfc1	$t9,$f6
/*  f0d68d4:	00000000 */ 	nop
/*  f0d68d8:	032c6821 */ 	addu	$t5,$t9,$t4
/*  f0d68dc:	a64dfff8 */ 	sh	$t5,-0x8($s2)
/*  f0d68e0:	aec2fffc */ 	sw	$v0,-0x4($s6)
/*  f0d68e4:	8fab0148 */ 	lw	$t3,0x148($sp)
/*  f0d68e8:	162bffae */ 	bne	$s1,$t3,.L0f0d67a4
/*  f0d68ec:	00000000 */ 	nop
/*  f0d68f0:	00008825 */ 	or	$s1,$zero,$zero
.L0f0d68f4:
/*  f0d68f4:	3c188007 */ 	lui	$t8,%hi(var80070f54)
/*  f0d68f8:	8f180f54 */ 	lw	$t8,%lo(var80070f54)($t8)
/*  f0d68fc:	3c017f1b */ 	lui	$at,%hi(var7f1add94)
/*  f0d6900:	c424dd94 */ 	lwc1	$f4,%lo(var7f1add94)($at)
/*  f0d6904:	44984000 */ 	mtc1	$t8,$f8
/*  f0d6908:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d690c:	44813000 */ 	mtc1	$at,$f6
/*  f0d6910:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d6914:	27b001a8 */ 	addiu	$s0,$sp,0x1a8
/*  f0d6918:	27b20298 */ 	addiu	$s2,$sp,0x298
/*  f0d691c:	24140014 */ 	addiu	$s4,$zero,0x14
/*  f0d6920:	02402025 */ 	or	$a0,$s2,$zero
/*  f0d6924:	02002825 */ 	or	$a1,$s0,$zero
/*  f0d6928:	46045002 */ 	mul.s	$f0,$f10,$f4
/*  f0d692c:	c7aa0138 */ 	lwc1	$f10,0x138($sp)
/*  f0d6930:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f0d6934:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0d6938:	460a4082 */ 	mul.s	$f2,$f8,$f10
/*  f0d693c:	46001301 */ 	sub.s	$f12,$f2,$f0
/*  f0d6940:	e7a2015c */ 	swc1	$f2,0x15c($sp)
/*  f0d6944:	44076000 */ 	mfc1	$a3,$f12
/*  f0d6948:	0fc356a4 */ 	jal	func0f0d5a90
/*  f0d694c:	e7ac0158 */ 	swc1	$f12,0x158($sp)
/*  f0d6950:	24560006 */ 	addiu	$s6,$v0,0x6
/*  f0d6954:	02402025 */ 	or	$a0,$s2,$zero
/*  f0d6958:	02002825 */ 	or	$a1,$s0,$zero
/*  f0d695c:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f0d6960:	0fc356a4 */ 	jal	func0f0d5a90
/*  f0d6964:	8fa7015c */ 	lw	$a3,0x15c($sp)
/*  f0d6968:	02c2b021 */ 	addu	$s6,$s6,$v0
/*  f0d696c:	1ac0003e */ 	blez	$s6,.L0f0d6a68
/*  f0d6970:	27a801a8 */ 	addiu	$t0,$sp,0x1a8
.L0f0d6974:
/*  f0d6974:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f0d6978:	3c048007 */ 	lui	$a0,%hi(var80070f3c)
/*  f0d697c:	3c058007 */ 	lui	$a1,%hi(var80070f44)
/*  f0d6980:	00540019 */ 	multu	$v0,$s4
/*  f0d6984:	8ca50f44 */ 	lw	$a1,%lo(var80070f44)($a1)
/*  f0d6988:	8c840f3c */ 	lw	$a0,%lo(var80070f3c)($a0)
/*  f0d698c:	8fa60158 */ 	lw	$a2,0x158($sp)
/*  f0d6990:	8fa7015c */ 	lw	$a3,0x15c($sp)
/*  f0d6994:	0000c812 */ 	mflo	$t9
/*  f0d6998:	02598021 */ 	addu	$s0,$s2,$t9
/*  f0d699c:	c6040010 */ 	lwc1	$f4,0x10($s0)
/*  f0d69a0:	afa80090 */ 	sw	$t0,0x90($sp)
/*  f0d69a4:	0fc35718 */ 	jal	func0f0d5c60
/*  f0d69a8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0d69ac:	c6060000 */ 	lwc1	$f6,0x0($s0)
/*  f0d69b0:	3c0e8007 */ 	lui	$t6,%hi(var80070f48)
/*  f0d69b4:	8dce0f48 */ 	lw	$t6,%lo(var80070f48)($t6)
/*  f0d69b8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0d69bc:	8fa80090 */ 	lw	$t0,0x90($sp)
/*  f0d69c0:	a6600002 */ 	sh	$zero,0x2($s3)
/*  f0d69c4:	3c198007 */ 	lui	$t9,%hi(var80070f4c)
/*  f0d69c8:	440d4000 */ 	mfc1	$t5,$f8
/*  f0d69cc:	02311821 */ 	addu	$v1,$s1,$s1
/*  f0d69d0:	3c0b8007 */ 	lui	$t3,%hi(var80070f48)
/*  f0d69d4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0d69d8:	a66f0000 */ 	sh	$t7,0x0($s3)
/*  f0d69dc:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*  f0d69e0:	8f390f4c */ 	lw	$t9,%lo(var80070f4c)($t9)
/*  f0d69e4:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0d69e8:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0d69ec:	a26d0007 */ 	sb	$t5,0x7($s3)
/*  f0d69f0:	3c0d8007 */ 	lui	$t5,%hi(var80070f4c)
/*  f0d69f4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0d69f8:	44182000 */ 	mfc1	$t8,$f4
/*  f0d69fc:	26730018 */ 	addiu	$s3,$s3,0x18
/*  f0d6a00:	26f70008 */ 	addiu	$s7,$s7,0x8
/*  f0d6a04:	03196021 */ 	addu	$t4,$t8,$t9
/*  f0d6a08:	a66cffec */ 	sh	$t4,-0x14($s3)
/*  f0d6a0c:	aee2fff8 */ 	sw	$v0,-0x8($s7)
/*  f0d6a10:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f0d6a14:	8d6b0f48 */ 	lw	$t3,%lo(var80070f48)($t3)
/*  f0d6a18:	a660fff6 */ 	sh	$zero,-0xa($s3)
/*  f0d6a1c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0d6a20:	25080004 */ 	addiu	$t0,$t0,0x4
/*  f0d6a24:	440f4000 */ 	mfc1	$t7,$f8
/*  f0d6a28:	00000000 */ 	nop
/*  f0d6a2c:	01ebc021 */ 	addu	$t8,$t7,$t3
/*  f0d6a30:	a678fff4 */ 	sh	$t8,-0xc($s3)
/*  f0d6a34:	c60a000c */ 	lwc1	$f10,0xc($s0)
/*  f0d6a38:	8dad0f4c */ 	lw	$t5,%lo(var80070f4c)($t5)
/*  f0d6a3c:	246f0001 */ 	addiu	$t7,$v1,0x1
/*  f0d6a40:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0d6a44:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f0d6a48:	a26bfffb */ 	sb	$t3,-0x5($s3)
/*  f0d6a4c:	440c2000 */ 	mfc1	$t4,$f4
/*  f0d6a50:	00000000 */ 	nop
/*  f0d6a54:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0d6a58:	a66efff8 */ 	sh	$t6,-0x8($s3)
/*  f0d6a5c:	1636ffc5 */ 	bne	$s1,$s6,.L0f0d6974
/*  f0d6a60:	aee2fffc */ 	sw	$v0,-0x4($s7)
/*  f0d6a64:	00008825 */ 	or	$s1,$zero,$zero
.L0f0d6a68:
/*  f0d6a68:	3c188007 */ 	lui	$t8,%hi(var80070f58)
/*  f0d6a6c:	8f180f58 */ 	lw	$t8,%lo(var80070f58)($t8)
/*  f0d6a70:	3c017f1b */ 	lui	$at,%hi(var7f1add98)
/*  f0d6a74:	c42add98 */ 	lwc1	$f10,%lo(var7f1add98)($at)
/*  f0d6a78:	44983000 */ 	mtc1	$t8,$f6
/*  f0d6a7c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d6a80:	44812000 */ 	mtc1	$at,$f4
/*  f0d6a84:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d6a88:	27b00188 */ 	addiu	$s0,$sp,0x188
/*  f0d6a8c:	27b201f8 */ 	addiu	$s2,$sp,0x1f8
/*  f0d6a90:	02402025 */ 	or	$a0,$s2,$zero
/*  f0d6a94:	02002825 */ 	or	$a1,$s0,$zero
/*  f0d6a98:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f0d6a9c:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f0d6aa0:	c7a80134 */ 	lwc1	$f8,0x134($sp)
/*  f0d6aa4:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f0d6aa8:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f0d6aac:	46001301 */ 	sub.s	$f12,$f2,$f0
/*  f0d6ab0:	e7a20154 */ 	swc1	$f2,0x154($sp)
/*  f0d6ab4:	44076000 */ 	mfc1	$a3,$f12
/*  f0d6ab8:	0fc356a4 */ 	jal	func0f0d5a90
/*  f0d6abc:	e7ac0150 */ 	swc1	$f12,0x150($sp)
/*  f0d6ac0:	24530006 */ 	addiu	$s3,$v0,0x6
/*  f0d6ac4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0d6ac8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0d6acc:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f0d6ad0:	0fc356a4 */ 	jal	func0f0d5a90
/*  f0d6ad4:	8fa70154 */ 	lw	$a3,0x154($sp)
/*  f0d6ad8:	02629821 */ 	addu	$s3,$s3,$v0
/*  f0d6adc:	1a60003d */ 	blez	$s3,.L0f0d6bd4
/*  f0d6ae0:	27a90188 */ 	addiu	$t1,$sp,0x188
.L0f0d6ae4:
/*  f0d6ae4:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f0d6ae8:	3c048007 */ 	lui	$a0,%hi(var80070f40)
/*  f0d6aec:	3c058007 */ 	lui	$a1,%hi(var80070f44)
/*  f0d6af0:	00540019 */ 	multu	$v0,$s4
/*  f0d6af4:	8ca50f44 */ 	lw	$a1,%lo(var80070f44)($a1)
/*  f0d6af8:	8c840f40 */ 	lw	$a0,%lo(var80070f40)($a0)
/*  f0d6afc:	8fa60150 */ 	lw	$a2,0x150($sp)
/*  f0d6b00:	8fa70154 */ 	lw	$a3,0x154($sp)
/*  f0d6b04:	0000c812 */ 	mflo	$t9
/*  f0d6b08:	02598021 */ 	addu	$s0,$s2,$t9
/*  f0d6b0c:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f0d6b10:	afa9008c */ 	sw	$t1,0x8c($sp)
/*  f0d6b14:	0fc35718 */ 	jal	func0f0d5c60
/*  f0d6b18:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0d6b1c:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f0d6b20:	3c0e8007 */ 	lui	$t6,%hi(var80070f48)
/*  f0d6b24:	8dce0f48 */ 	lw	$t6,%lo(var80070f48)($t6)
/*  f0d6b28:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d6b2c:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f0d6b30:	a6a00002 */ 	sh	$zero,0x2($s5)
/*  f0d6b34:	3c198007 */ 	lui	$t9,%hi(var80070f4c)
/*  f0d6b38:	440d3000 */ 	mfc1	$t5,$f6
/*  f0d6b3c:	02311821 */ 	addu	$v1,$s1,$s1
/*  f0d6b40:	3c0b8007 */ 	lui	$t3,%hi(var80070f48)
/*  f0d6b44:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0d6b48:	a6af0000 */ 	sh	$t7,0x0($s5)
/*  f0d6b4c:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f0d6b50:	8f390f4c */ 	lw	$t9,%lo(var80070f4c)($t9)
/*  f0d6b54:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0d6b58:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d6b5c:	a2ad0007 */ 	sb	$t5,0x7($s5)
/*  f0d6b60:	3c0d8007 */ 	lui	$t5,%hi(var80070f4c)
/*  f0d6b64:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0d6b68:	44185000 */ 	mfc1	$t8,$f10
/*  f0d6b6c:	26b50018 */ 	addiu	$s5,$s5,0x18
/*  f0d6b70:	27de0008 */ 	addiu	$s8,$s8,0x8
/*  f0d6b74:	03196021 */ 	addu	$t4,$t8,$t9
/*  f0d6b78:	a6acffec */ 	sh	$t4,-0x14($s5)
/*  f0d6b7c:	afc2fff8 */ 	sw	$v0,-0x8($s8)
/*  f0d6b80:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f0d6b84:	8d6b0f48 */ 	lw	$t3,%lo(var80070f48)($t3)
/*  f0d6b88:	a6a0fff6 */ 	sh	$zero,-0xa($s5)
/*  f0d6b8c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d6b90:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f0d6b94:	440f3000 */ 	mfc1	$t7,$f6
/*  f0d6b98:	00000000 */ 	nop
/*  f0d6b9c:	01ebc021 */ 	addu	$t8,$t7,$t3
/*  f0d6ba0:	a6b8fff4 */ 	sh	$t8,-0xc($s5)
/*  f0d6ba4:	c608000c */ 	lwc1	$f8,0xc($s0)
/*  f0d6ba8:	8dad0f4c */ 	lw	$t5,%lo(var80070f4c)($t5)
/*  f0d6bac:	246f0001 */ 	addiu	$t7,$v1,0x1
/*  f0d6bb0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d6bb4:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f0d6bb8:	a2abfffb */ 	sb	$t3,-0x5($s5)
/*  f0d6bbc:	440c5000 */ 	mfc1	$t4,$f10
/*  f0d6bc0:	00000000 */ 	nop
/*  f0d6bc4:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0d6bc8:	a6aefff8 */ 	sh	$t6,-0x8($s5)
/*  f0d6bcc:	1633ffc5 */ 	bne	$s1,$s3,.L0f0d6ae4
/*  f0d6bd0:	afc2fffc */ 	sw	$v0,-0x4($s8)
.L0f0d6bd4:
/*  f0d6bd4:	0fc54d8a */ 	jal	func0f153628
/*  f0d6bd8:	8fa40428 */ 	lw	$a0,0x428($sp)
/*  f0d6bdc:	3c188007 */ 	lui	$t8,%hi(var80070f6c)
/*  f0d6be0:	3c198007 */ 	lui	$t9,%hi(var80070f70)
/*  f0d6be4:	8f390f70 */ 	lw	$t9,%lo(var80070f70)($t9)
/*  f0d6be8:	8f180f6c */ 	lw	$t8,%lo(var80070f6c)($t8)
/*  f0d6bec:	3c058007 */ 	lui	$a1,%hi(var80070f60)
/*  f0d6bf0:	3c068007 */ 	lui	$a2,%hi(var80070f64)
/*  f0d6bf4:	3c078007 */ 	lui	$a3,%hi(var80070f68)
/*  f0d6bf8:	8ce70f68 */ 	lw	$a3,%lo(var80070f68)($a3)
/*  f0d6bfc:	8cc60f64 */ 	lw	$a2,%lo(var80070f64)($a2)
/*  f0d6c00:	8ca50f60 */ 	lw	$a1,%lo(var80070f60)($a1)
/*  f0d6c04:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d6c08:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0d6c0c:	0fc54e8d */ 	jal	func0f153a34
/*  f0d6c10:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0d6c14:	0fc54de0 */ 	jal	func0f153780
/*  f0d6c18:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d6c1c:	3c0cb900 */ 	lui	$t4,0xb900
/*  f0d6c20:	3c0d0050 */ 	lui	$t5,0x50
/*  f0d6c24:	3c0efcff */ 	lui	$t6,0xfcff
/*  f0d6c28:	3c0ffffe */ 	lui	$t7,0xfffe
/*  f0d6c2c:	35ad41c8 */ 	ori	$t5,$t5,0x41c8
/*  f0d6c30:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f0d6c34:	35ef793c */ 	ori	$t7,$t7,0x793c
/*  f0d6c38:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f0d6c3c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0d6c40:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f0d6c44:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f0d6c48:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f0d6c4c:	8fb00148 */ 	lw	$s0,0x148($sp)
/*  f0d6c50:	244b0018 */ 	addiu	$t3,$v0,0x18
/*  f0d6c54:	afab0428 */ 	sw	$t3,0x428($sp)
/*  f0d6c58:	0010c040 */ 	sll	$t8,$s0,0x1
/*  f0d6c5c:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f0d6c60:	00196080 */ 	sll	$t4,$t9,0x2
/*  f0d6c64:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0d6c68:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f0d6c6c:	03008025 */ 	or	$s0,$t8,$zero
/*  f0d6c70:	00185880 */ 	sll	$t3,$t8,0x2
/*  f0d6c74:	3c010700 */ 	lui	$at,0x700
/*  f0d6c78:	01c17825 */ 	or	$t7,$t6,$at
/*  f0d6c7c:	3178ffff */ 	andi	$t8,$t3,0xffff
/*  f0d6c80:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f0d6c84:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f0d6c88:	8fa40180 */ 	lw	$a0,0x180($sp)
/*  f0d6c8c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d6c90:	24510010 */ 	addiu	$s1,$v0,0x10
/*  f0d6c94:	8fb20428 */ 	lw	$s2,0x428($sp)
/*  f0d6c98:	3c0c04d0 */ 	lui	$t4,0x4d0
/*  f0d6c9c:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0d6ca0:	358c00a8 */ 	ori	$t4,$t4,0xa8
/*  f0d6ca4:	ae4c0000 */ 	sw	$t4,0x0($s2)
/*  f0d6ca8:	26430008 */ 	addiu	$v1,$s2,0x8
/*  f0d6cac:	afa30428 */ 	sw	$v1,0x428($sp)
/*  f0d6cb0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d6cb4:	8fa40184 */ 	lw	$a0,0x184($sp)
/*  f0d6cb8:	8fa30428 */ 	lw	$v1,0x428($sp)
/*  f0d6cbc:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f0d6cc0:	3c17b100 */ 	lui	$s7,0xb100
/*  f0d6cc4:	3c1e4332 */ 	lui	$s8,0x4332
/*  f0d6cc8:	37de2110 */ 	ori	$s8,$s8,0x2110
/*  f0d6ccc:	36f75432 */ 	ori	$s7,$s7,0x5432
/*  f0d6cd0:	24650008 */ 	addiu	$a1,$v1,0x8
/*  f0d6cd4:	3c0db100 */ 	lui	$t5,0xb100
/*  f0d6cd8:	3c0e8776 */ 	lui	$t6,0x8776
/*  f0d6cdc:	ac770000 */ 	sw	$s7,0x0($v1)
/*  f0d6ce0:	ac7e0004 */ 	sw	$s8,0x4($v1)
/*  f0d6ce4:	35ce6554 */ 	ori	$t6,$t6,0x6554
/*  f0d6ce8:	35ad9876 */ 	ori	$t5,$t5,0x9876
/*  f0d6cec:	3c0bb100 */ 	lui	$t3,0xb100
/*  f0d6cf0:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f0d6cf4:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f0d6cf8:	24a60008 */ 	addiu	$a2,$a1,0x8
/*  f0d6cfc:	356bdcba */ 	ori	$t3,$t3,0xdcba
/*  f0d6d00:	accb0000 */ 	sw	$t3,0x0($a2)
/*  f0d6d04:	2611fff4 */ 	addiu	$s1,$s0,-12
/*  f0d6d08:	2618fff3 */ 	addiu	$t8,$s0,-13
/*  f0d6d0c:	3c0fcbba */ 	lui	$t7,0xcbba
/*  f0d6d10:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0d6d14:	00115880 */ 	sll	$t3,$s1,0x2
/*  f0d6d18:	35efa998 */ 	ori	$t7,$t7,0xa998
/*  f0d6d1c:	01715823 */ 	subu	$t3,$t3,$s1
/*  f0d6d20:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f0d6d24:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f0d6d28:	000c6c00 */ 	sll	$t5,$t4,0x10
/*  f0d6d2c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0d6d30:	3c010400 */ 	lui	$at,0x400
/*  f0d6d34:	01a17025 */ 	or	$t6,$t5,$at
/*  f0d6d38:	316fffff */ 	andi	$t7,$t3,0xffff
/*  f0d6d3c:	24d40008 */ 	addiu	$s4,$a2,0x8
/*  f0d6d40:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f0d6d44:	ae980000 */ 	sw	$t8,0x0($s4)
/*  f0d6d48:	8fa40184 */ 	lw	$a0,0x184($sp)
/*  f0d6d4c:	26870008 */ 	addiu	$a3,$s4,0x8
/*  f0d6d50:	afa70428 */ 	sw	$a3,0x428($sp)
/*  f0d6d54:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d6d58:	24840090 */ 	addiu	$a0,$a0,144
/*  f0d6d5c:	8fa50428 */ 	lw	$a1,0x428($sp)
/*  f0d6d60:	ae820004 */ 	sw	$v0,0x4($s4)
/*  f0d6d64:	2a21000a */ 	slti	$at,$s1,0xa
/*  f0d6d68:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0d6d6c:	ac770000 */ 	sw	$s7,0x0($v1)
/*  f0d6d70:	ac7e0004 */ 	sw	$s8,0x4($v1)
/*  f0d6d74:	10200009 */ 	beqz	$at,.L0f0d6d9c
/*  f0d6d78:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0d6d7c:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d6d80:	3c19b100 */ 	lui	$t9,0xb100
/*  f0d6d84:	37390076 */ 	ori	$t9,$t9,0x76
/*  f0d6d88:	240c6554 */ 	addiu	$t4,$zero,0x6554
/*  f0d6d8c:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0d6d90:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0d6d94:	10000012 */ 	b	.L0f0d6de0
/*  f0d6d98:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f0d6d9c:
/*  f0d6d9c:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d6da0:	3c0db100 */ 	lui	$t5,0xb100
/*  f0d6da4:	3c0b8776 */ 	lui	$t3,0x8776
/*  f0d6da8:	356b6554 */ 	ori	$t3,$t3,0x6554
/*  f0d6dac:	35ad9876 */ 	ori	$t5,$t5,0x9876
/*  f0d6db0:	2a21000c */ 	slti	$at,$s1,0xc
/*  f0d6db4:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0d6db8:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0d6dbc:	14200008 */ 	bnez	$at,.L0f0d6de0
/*  f0d6dc0:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0d6dc4:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d6dc8:	3c0eb100 */ 	lui	$t6,0xb100
/*  f0d6dcc:	35ce00ba */ 	ori	$t6,$t6,0xba
/*  f0d6dd0:	340fa998 */ 	dli	$t7,0xa998
/*  f0d6dd4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0d6dd8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0d6ddc:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f0d6de0:
/*  f0d6de0:	00168040 */ 	sll	$s0,$s6,0x1
/*  f0d6de4:	2614ffff */ 	addiu	$s4,$s0,-1
/*  f0d6de8:	0014c080 */ 	sll	$t8,$s4,0x2
/*  f0d6dec:	331900ff */ 	andi	$t9,$t8,0xff
/*  f0d6df0:	00196400 */ 	sll	$t4,$t9,0x10
/*  f0d6df4:	00108880 */ 	sll	$s1,$s0,0x2
/*  f0d6df8:	3c010700 */ 	lui	$at,0x700
/*  f0d6dfc:	01816825 */ 	or	$t5,$t4,$at
/*  f0d6e00:	322bffff */ 	andi	$t3,$s1,0xffff
/*  f0d6e04:	01ab7025 */ 	or	$t6,$t5,$t3
/*  f0d6e08:	00a09025 */ 	or	$s2,$a1,$zero
/*  f0d6e0c:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*  f0d6e10:	8fa40180 */ 	lw	$a0,0x180($sp)
/*  f0d6e14:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0d6e18:	afa50428 */ 	sw	$a1,0x428($sp)
/*  f0d6e1c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d6e20:	24840060 */ 	addiu	$a0,$a0,0x60
/*  f0d6e24:	00147900 */ 	sll	$t7,$s4,0x4
/*  f0d6e28:	00106880 */ 	sll	$t5,$s0,0x2
/*  f0d6e2c:	8fb50428 */ 	lw	$s5,0x428($sp)
/*  f0d6e30:	01b06823 */ 	subu	$t5,$t5,$s0
/*  f0d6e34:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0d6e38:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f0d6e3c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0d6e40:	3c010400 */ 	lui	$at,0x400
/*  f0d6e44:	03216025 */ 	or	$t4,$t9,$at
/*  f0d6e48:	31abffff */ 	andi	$t3,$t5,0xffff
/*  f0d6e4c:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f0d6e50:	018b7025 */ 	or	$t6,$t4,$t3
/*  f0d6e54:	aeae0000 */ 	sw	$t6,0x0($s5)
/*  f0d6e58:	26a30008 */ 	addiu	$v1,$s5,0x8
/*  f0d6e5c:	afa30428 */ 	sw	$v1,0x428($sp)
/*  f0d6e60:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d6e64:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0d6e68:	8fa50428 */ 	lw	$a1,0x428($sp)
/*  f0d6e6c:	aea20004 */ 	sw	$v0,0x4($s5)
/*  f0d6e70:	3c0fb100 */ 	lui	$t7,0xb100
/*  f0d6e74:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0d6e78:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0d6e7c:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0d6e80:	3c188776 */ 	lui	$t8,0x8776
/*  f0d6e84:	ac770000 */ 	sw	$s7,0x0($v1)
/*  f0d6e88:	ac7e0004 */ 	sw	$s8,0x4($v1)
/*  f0d6e8c:	37186554 */ 	ori	$t8,$t8,0x6554
/*  f0d6e90:	35ef9876 */ 	ori	$t7,$t7,0x9876
/*  f0d6e94:	2a210038 */ 	slti	$at,$s1,0x38
/*  f0d6e98:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f0d6e9c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f0d6ea0:	10200009 */ 	beqz	$at,.L0f0d6ec8
/*  f0d6ea4:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0d6ea8:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d6eac:	3c19b100 */ 	lui	$t9,0xb100
/*  f0d6eb0:	373900ba */ 	ori	$t9,$t9,0xba
/*  f0d6eb4:	340da998 */ 	dli	$t5,0xa998
/*  f0d6eb8:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f0d6ebc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0d6ec0:	10000012 */ 	b	.L0f0d6f0c
/*  f0d6ec4:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f0d6ec8:
/*  f0d6ec8:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d6ecc:	3c0cb100 */ 	lui	$t4,0xb100
/*  f0d6ed0:	3c0bcbba */ 	lui	$t3,0xcbba
/*  f0d6ed4:	356ba998 */ 	ori	$t3,$t3,0xa998
/*  f0d6ed8:	358cdcba */ 	ori	$t4,$t4,0xdcba
/*  f0d6edc:	2a210040 */ 	slti	$at,$s1,0x40
/*  f0d6ee0:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0d6ee4:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0d6ee8:	14200008 */ 	bnez	$at,.L0f0d6f0c
/*  f0d6eec:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0d6ef0:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d6ef4:	3c0eb100 */ 	lui	$t6,0xb100
/*  f0d6ef8:	35ce00fe */ 	ori	$t6,$t6,0xfe
/*  f0d6efc:	340feddc */ 	dli	$t7,0xeddc
/*  f0d6f00:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0d6f04:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0d6f08:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f0d6f0c:
/*  f0d6f0c:	00138040 */ 	sll	$s0,$s3,0x1
/*  f0d6f10:	2614ffff */ 	addiu	$s4,$s0,-1
/*  f0d6f14:	0014c080 */ 	sll	$t8,$s4,0x2
/*  f0d6f18:	331900ff */ 	andi	$t9,$t8,0xff
/*  f0d6f1c:	00196c00 */ 	sll	$t5,$t9,0x10
/*  f0d6f20:	00108880 */ 	sll	$s1,$s0,0x2
/*  f0d6f24:	3c010700 */ 	lui	$at,0x700
/*  f0d6f28:	01a16025 */ 	or	$t4,$t5,$at
/*  f0d6f2c:	322bffff */ 	andi	$t3,$s1,0xffff
/*  f0d6f30:	018b7025 */ 	or	$t6,$t4,$t3
/*  f0d6f34:	00a09025 */ 	or	$s2,$a1,$zero
/*  f0d6f38:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*  f0d6f3c:	8fa40180 */ 	lw	$a0,0x180($sp)
/*  f0d6f40:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0d6f44:	afa50428 */ 	sw	$a1,0x428($sp)
/*  f0d6f48:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d6f4c:	248400a0 */ 	addiu	$a0,$a0,160
/*  f0d6f50:	00147900 */ 	sll	$t7,$s4,0x4
/*  f0d6f54:	00106080 */ 	sll	$t4,$s0,0x2
/*  f0d6f58:	8fb30428 */ 	lw	$s3,0x428($sp)
/*  f0d6f5c:	01906023 */ 	subu	$t4,$t4,$s0
/*  f0d6f60:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0d6f64:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f0d6f68:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0d6f6c:	3c010400 */ 	lui	$at,0x400
/*  f0d6f70:	03216825 */ 	or	$t5,$t9,$at
/*  f0d6f74:	318bffff */ 	andi	$t3,$t4,0xffff
/*  f0d6f78:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f0d6f7c:	01ab7025 */ 	or	$t6,$t5,$t3
/*  f0d6f80:	ae6e0000 */ 	sw	$t6,0x0($s3)
/*  f0d6f84:	26630008 */ 	addiu	$v1,$s3,0x8
/*  f0d6f88:	afa30428 */ 	sw	$v1,0x428($sp)
/*  f0d6f8c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d6f90:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f0d6f94:	8fa50428 */ 	lw	$a1,0x428($sp)
/*  f0d6f98:	ae620004 */ 	sw	$v0,0x4($s3)
/*  f0d6f9c:	3c0fb100 */ 	lui	$t7,0xb100
/*  f0d6fa0:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0d6fa4:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0d6fa8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0d6fac:	3c188776 */ 	lui	$t8,0x8776
/*  f0d6fb0:	ac770000 */ 	sw	$s7,0x0($v1)
/*  f0d6fb4:	ac7e0004 */ 	sw	$s8,0x4($v1)
/*  f0d6fb8:	37186554 */ 	ori	$t8,$t8,0x6554
/*  f0d6fbc:	35ef9876 */ 	ori	$t7,$t7,0x9876
/*  f0d6fc0:	2a210038 */ 	slti	$at,$s1,0x38
/*  f0d6fc4:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f0d6fc8:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f0d6fcc:	10200009 */ 	beqz	$at,.L0f0d6ff4
/*  f0d6fd0:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0d6fd4:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d6fd8:	3c19b100 */ 	lui	$t9,0xb100
/*  f0d6fdc:	373900ba */ 	ori	$t9,$t9,0xba
/*  f0d6fe0:	340ca998 */ 	dli	$t4,0xa998
/*  f0d6fe4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0d6fe8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0d6fec:	10000012 */ 	b	.L0f0d7038
/*  f0d6ff0:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f0d6ff4:
/*  f0d6ff4:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d6ff8:	3c0db100 */ 	lui	$t5,0xb100
/*  f0d6ffc:	3c0bcbba */ 	lui	$t3,0xcbba
/*  f0d7000:	356ba998 */ 	ori	$t3,$t3,0xa998
/*  f0d7004:	35addcba */ 	ori	$t5,$t5,0xdcba
/*  f0d7008:	2a210040 */ 	slti	$at,$s1,0x40
/*  f0d700c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0d7010:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0d7014:	14200008 */ 	bnez	$at,.L0f0d7038
/*  f0d7018:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0d701c:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d7020:	3c0eb100 */ 	lui	$t6,0xb100
/*  f0d7024:	35ce00fe */ 	ori	$t6,$t6,0xfe
/*  f0d7028:	340feddc */ 	dli	$t7,0xeddc
/*  f0d702c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0d7030:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0d7034:	24a50008 */ 	addiu	$a1,$a1,0x8
.L0f0d7038:
/*  f0d7038:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0d703c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0d7040:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0d7044:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0d7048:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f0d704c:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f0d7050:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f0d7054:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f0d7058:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f0d705c:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f0d7060:	27bd0428 */ 	addiu	$sp,$sp,0x428
/*  f0d7064:	03e00008 */ 	jr	$ra
/*  f0d7068:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d706c:	00000000 */ 	nop
);
