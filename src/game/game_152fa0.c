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
#include "types.h"

const u32 var7f1b73a0[] = {0x46ffffcd};
const u32 var7f1b73a4[] = {0xc6ffffcd};
const u32 var7f1b73a8[] = {0x00000000};
const u32 var7f1b73ac[] = {0x00000000};

GLOBAL_ASM(
glabel func0f152fa0
/*  f152fa0:	3c017f1b */ 	lui	$at,%hi(var7f1b73a0)
/*  f152fa4:	c42073a0 */ 	lwc1	$f0,%lo(var7f1b73a0)($at)
/*  f152fa8:	44802000 */ 	mtc1	$zero,$f4
/*  f152fac:	3c017f1b */ 	lui	$at,%hi(var7f1b73a4)
/*  f152fb0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f152fb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f152fb8:	45000002 */ 	bc1f	.L0f152fc4
/*  f152fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f152fc0:	46000306 */ 	mov.s	$f12,$f0
.L0f152fc4:
/*  f152fc4:	c42073a4 */ 	lwc1	$f0,%lo(var7f1b73a4)($at)
/*  f152fc8:	3c014780 */ 	lui	$at,0x4780
/*  f152fcc:	4600603c */ 	c.lt.s	$f12,$f0
/*  f152fd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f152fd4:	45020003 */ 	bc1fl	.L0f152fe4
/*  f152fd8:	4604603c */ 	c.lt.s	$f12,$f4
/*  f152fdc:	46000306 */ 	mov.s	$f12,$f0
/*  f152fe0:	4604603c */ 	c.lt.s	$f12,$f4
.L0f152fe4:
/*  f152fe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f152fe8:	4502002c */ 	bc1fl	.L0f15309c
/*  f152fec:	44818000 */ 	mtc1	$at,$f16
/*  f152ff0:	3c01c780 */ 	lui	$at,0xc780
/*  f152ff4:	44813000 */ 	mtc1	$at,$f6
/*  f152ff8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f152ffc:	3c014f00 */ 	lui	$at,0x4f00
/*  f153000:	46066202 */ 	mul.s	$f8,$f12,$f6
/*  f153004:	444ef800 */ 	cfc1	$t6,$31
/*  f153008:	44c3f800 */ 	ctc1	$v1,$31
/*  f15300c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f153010:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f153014:	4443f800 */ 	cfc1	$v1,$31
/*  f153018:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15301c:	30630078 */ 	andi	$v1,$v1,0x78
/*  f153020:	50600017 */ 	beqzl	$v1,.L0f153080
/*  f153024:	44035000 */ 	mfc1	$v1,$f10
/*  f153028:	44815000 */ 	mtc1	$at,$f10
/*  f15302c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f153030:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f153034:	44c3f800 */ 	ctc1	$v1,$31
/*  f153038:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15303c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f153040:	4443f800 */ 	cfc1	$v1,$31
/*  f153044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f153048:	30630078 */ 	andi	$v1,$v1,0x78
/*  f15304c:	54600008 */ 	bnezl	$v1,.L0f153070
/*  f153050:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f153054:	44035000 */ 	mfc1	$v1,$f10
/*  f153058:	3c018000 */ 	lui	$at,0x8000
/*  f15305c:	44cef800 */ 	ctc1	$t6,$31
/*  f153060:	00611825 */ 	or	$v1,$v1,$at
/*  f153064:	03e00008 */ 	jr	$ra
/*  f153068:	00031023 */ 	negu	$v0,$v1
/*  f15306c:	2403ffff */ 	addiu	$v1,$zero,-1
.L0f153070:
/*  f153070:	44cef800 */ 	ctc1	$t6,$31
/*  f153074:	03e00008 */ 	jr	$ra
/*  f153078:	00031023 */ 	negu	$v0,$v1
/*  f15307c:	44035000 */ 	mfc1	$v1,$f10
.L0f153080:
/*  f153080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f153084:	0462fffa */ 	bltzl	$v1,.L0f153070
/*  f153088:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f15308c:	44cef800 */ 	ctc1	$t6,$31
/*  f153090:	03e00008 */ 	jr	$ra
/*  f153094:	00031023 */ 	negu	$v0,$v1
/*  f153098:	44818000 */ 	mtc1	$at,$f16
.L0f15309c:
/*  f15309c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f1530a0:	3c014f00 */ 	lui	$at,0x4f00
/*  f1530a4:	460c8482 */ 	mul.s	$f18,$f16,$f12
/*  f1530a8:	444ff800 */ 	cfc1	$t7,$31
/*  f1530ac:	44c3f800 */ 	ctc1	$v1,$31
/*  f1530b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1530b4:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f1530b8:	4443f800 */ 	cfc1	$v1,$31
/*  f1530bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1530c0:	30630078 */ 	andi	$v1,$v1,0x78
/*  f1530c4:	50600013 */ 	beqzl	$v1,.L0f153114
/*  f1530c8:	44032000 */ 	mfc1	$v1,$f4
/*  f1530cc:	44812000 */ 	mtc1	$at,$f4
/*  f1530d0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f1530d4:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f1530d8:	44c3f800 */ 	ctc1	$v1,$31
/*  f1530dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1530e0:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f1530e4:	4443f800 */ 	cfc1	$v1,$31
/*  f1530e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1530ec:	30630078 */ 	andi	$v1,$v1,0x78
/*  f1530f0:	14600005 */ 	bnez	$v1,.L0f153108
/*  f1530f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1530f8:	44032000 */ 	mfc1	$v1,$f4
/*  f1530fc:	3c018000 */ 	lui	$at,0x8000
/*  f153100:	10000007 */ 	beqz	$zero,.L0f153120
/*  f153104:	00611825 */ 	or	$v1,$v1,$at
.L0f153108:
/*  f153108:	10000005 */ 	beqz	$zero,.L0f153120
/*  f15310c:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f153110:	44032000 */ 	mfc1	$v1,$f4
.L0f153114:
/*  f153114:	00000000 */ 	sll	$zero,$zero,0x0
/*  f153118:	0460fffb */ 	bltz	$v1,.L0f153108
/*  f15311c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f153120:
/*  f153120:	44cff800 */ 	ctc1	$t7,$31
/*  f153124:	00000000 */ 	sll	$zero,$zero,0x0
/*  f153128:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15312c:	03e00008 */ 	jr	$ra
/*  f153130:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f153134
/*  f153134:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f153138:	3c0ee700 */ 	lui	$t6,0xe700
/*  f15313c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f153140:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f153144:	3c0fba00 */ 	lui	$t7,0xba00
/*  f153148:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f15314c:	24a60008 */ 	addiu	$a2,$a1,0x8
/*  f153150:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f153154:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f153158:	3c18fcff */ 	lui	$t8,0xfcff
/*  f15315c:	3c19fffd */ 	lui	$t9,0xfffd
/*  f153160:	3739f6fb */ 	ori	$t9,$t9,0xf6fb
/*  f153164:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f153168:	24c70008 */ 	addiu	$a3,$a2,0x8
/*  f15316c:	3c08b900 */ 	lui	$t0,0xb900
/*  f153170:	3c090050 */ 	lui	$t1,0x50
/*  f153174:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f153178:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f15317c:	35294240 */ 	ori	$t1,$t1,0x4240
/*  f153180:	3508031d */ 	ori	$t0,$t0,0x31d
/*  f153184:	ace80000 */ 	sw	$t0,0x0($a3)
/*  f153188:	ace90004 */ 	sw	$t1,0x4($a3)
/*  f15318c:	03e00008 */ 	jr	$ra
/*  f153190:	24e20008 */ 	addiu	$v0,$a3,0x8
/*  f153194:	00000000 */ 	sll	$zero,$zero,0x0
/*  f153198:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15319c:	00000000 */ 	sll	$zero,$zero,0x0
);
