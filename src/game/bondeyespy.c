#include <ultra64.h>
#include "constants.h"
#include "game/bondeyespy.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/chr/chr.h"
#include "game/game_0601b0.h"
#include "game/game_092610.h"
#include "game/game_097ba0.h"
#include "game/game_0b63b0.h"
#include "game/game_0dcdb0.h"
#include "game/game_111600.h"
#include "game/game_127910.h"
#include "game/game_1655c0.h"
#include "game/lang.h"
#include "game/pdoptions.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_13130.h"
#include "lib/lib_13900.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1ada40[] = "bondeyespy.c";
const char var7f1ada50[] = "bondeyespy.c";

u32 var80070ec0 = 0x00000000;
u32 var80070ec4 = 0x00000000;
u32 var80070ec8 = 0x00000000;
u32 var80070ecc = 0x00000000;
f32 g_EyespyMaxHeight = 160;
u32 var80070ed4 = 0x42a00000;
u32 var80070ed8 = 0x00000064;
u32 var80070edc = 0x00000bb8;

/**
 * Determines the eyespy's ground Y value by doing a collision check for a
 * position 50 units above the current position, or less if the eyespy is near
 * the top of its height range.
 */
f32 eyespyFindGround(s16 *floorroom)
{
	struct prop *prop = g_Vars.currentplayer->eyespy->prop;
	bool thing;
	struct prop *lift;
	struct coord pos;
	f32 yoffset = 50;
	f32 ground;

	if (g_EyespyMaxHeight - g_Vars.currentplayer->eyespy->height < 50) {
		yoffset = g_EyespyMaxHeight - g_Vars.currentplayer->eyespy->height;
	}

	if (yoffset < 0) {
		yoffset = 0;
	}

	pos.x = prop->pos.x;
	pos.y = prop->pos.y + yoffset;
	pos.z = prop->pos.z;

	ground = func0002a1b0(&pos, 26, prop->rooms, NULL, NULL, NULL, floorroom, &thing, &lift);

	if (ground < -30000) {
		ground = -30000;
	}

	return ground;
}

GLOBAL_ASM(
glabel func0f0cf230
.late_rodata
glabel var7f1ada84
.word 0x3dcccccd
glabel var7f1ada88
.word 0x3f847ae1
glabel var7f1ada8c
.word 0x47ae147b
.text
/*  f0cf230:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0cf234:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0cf238:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0cf23c:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0cf240:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0cf244:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0cf248:	8c4e0480 */ 	lw	$t6,0x480($v0)
/*  f0cf24c:	8c8f0328 */ 	lw	$t7,0x328($a0)
/*  f0cf250:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0cf254:	8dd00000 */ 	lw	$s0,0x0($t6)
/*  f0cf258:	44817000 */ 	mtc1	$at,$f14
/*  f0cf25c:	24190020 */ 	addiu	$t9,$zero,0x20
/*  f0cf260:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f0cf264:	8e030004 */ 	lw	$v1,0x4($s0)
/*  f0cf268:	2418003f */ 	addiu	$t8,$zero,0x3f
/*  f0cf26c:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*  f0cf270:	c606000c */ 	lwc1	$f6,0xc($s0)
/*  f0cf274:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f0cf278:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f0cf27c:	460c3200 */ 	add.s	$f8,$f6,$f12
/*  f0cf280:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0cf284:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f0cf288:	e7a80064 */ 	swc1	$f8,0x64($sp)
/*  f0cf28c:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f0cf290:	11e00003 */ 	beqz	$t7,.L0f0cf2a0
/*  f0cf294:	e7aa0068 */ 	swc1	$f10,0x68($sp)
/*  f0cf298:	10000002 */ 	beqz	$zero,.L0f0cf2a4
/*  f0cf29c:	afb8004c */ 	sw	$t8,0x4c($sp)
.L0f0cf2a0:
/*  f0cf2a0:	afb9004c */ 	sw	$t9,0x4c($sp)
.L0f0cf2a4:
/*  f0cf2a4:	c46200b4 */ 	lwc1	$f2,0xb4($v1)
/*  f0cf2a8:	8c480480 */ 	lw	$t0,0x480($v0)
/*  f0cf2ac:	460e1400 */ 	add.s	$f16,$f2,$f14
/*  f0cf2b0:	c50c005c */ 	lwc1	$f12,0x5c($t0)
/*  f0cf2b4:	4610603e */ 	c.le.s	$f12,$f16
/*  f0cf2b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf2bc:	45020006 */ 	bc1fl	.L0f0cf2d8
/*  f0cf2c0:	c606000c */ 	lwc1	$f6,0xc($s0)
/*  f0cf2c4:	c612000c */ 	lwc1	$f18,0xc($s0)
/*  f0cf2c8:	46121101 */ 	sub.s	$f4,$f2,$f18
/*  f0cf2cc:	10000003 */ 	beqz	$zero,.L0f0cf2dc
/*  f0cf2d0:	460e2000 */ 	add.s	$f0,$f4,$f14
/*  f0cf2d4:	c606000c */ 	lwc1	$f6,0xc($s0)
.L0f0cf2d8:
/*  f0cf2d8:	46066001 */ 	sub.s	$f0,$f12,$f6
.L0f0cf2dc:
/*  f0cf2dc:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0cf2e0:	0fc1979d */ 	jal	func0f065e74
/*  f0cf2e4:	e7a00044 */ 	swc1	$f0,0x44($sp)
/*  f0cf2e8:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f0cf2ec:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f0cf2f0:	0fc087ea */ 	jal	func0f021fa8
/*  f0cf2f4:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0cf2f8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cf2fc:	0fc1905e */ 	jal	func0f064178
/*  f0cf300:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cf304:	3c017f1b */ 	lui	$at,%hi(var7f1ada84)
/*  f0cf308:	c7a00044 */ 	lwc1	$f0,0x44($sp)
/*  f0cf30c:	c428da84 */ 	lwc1	$f8,%lo(var7f1ada84)($at)
/*  f0cf310:	3c014170 */ 	lui	$at,0x4170
/*  f0cf314:	44815000 */ 	mtc1	$at,$f10
/*  f0cf318:	46080001 */ 	sub.s	$f0,$f0,$f8
/*  f0cf31c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0cf320:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0cf324:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f0cf328:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f0cf32c:	3c0541d0 */ 	lui	$a1,0x41d0
/*  f0cf330:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0cf334:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0cf338:	0c00a9a1 */ 	jal	func0002a684
/*  f0cf33c:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f0cf340:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0cf344:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cf348:	0fc1905e */ 	jal	func0f064178
/*  f0cf34c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cf350:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0cf354:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cf358:	c7b00064 */ 	lwc1	$f16,0x64($sp)
/*  f0cf35c:	15410006 */ 	bne	$t2,$at,.L0f0cf378
/*  f0cf360:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cf364:	0fc19711 */ 	jal	func0f065c44
/*  f0cf368:	e610000c */ 	swc1	$f16,0xc($s0)
/*  f0cf36c:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f0cf370:	0fc195e9 */ 	jal	roomsCopy
/*  f0cf374:	8fa5003c */ 	lw	$a1,0x3c($sp)
.L0f0cf378:
/*  f0cf378:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0cf37c:	8fa20074 */ 	lw	$v0,0x74($sp)
/*  f0cf380:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0cf384:	03e00008 */ 	jr	$ra
/*  f0cf388:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f0cf38c
/*  f0cf38c:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f0cf390:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0cf394:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0cf398:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0cf39c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0cf3a0:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0cf3a4:	afae00cc */ 	sw	$t6,0xcc($sp)
/*  f0cf3a8:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0cf3ac:	00803025 */ 	or	$a2,$a0,$zero
/*  f0cf3b0:	27a400a6 */ 	addiu	$a0,$sp,0xa6
/*  f0cf3b4:	8f100000 */ 	lw	$s0,0x0($t8)
/*  f0cf3b8:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0cf3bc:	afa600d0 */ 	sw	$a2,0xd0($sp)
/*  f0cf3c0:	0fc33c54 */ 	jal	eyespyFindGround
/*  f0cf3c4:	afb900c4 */ 	sw	$t9,0xc4($sp)
/*  f0cf3c8:	8fa600d0 */ 	lw	$a2,0xd0($sp)
/*  f0cf3cc:	44800000 */ 	mtc1	$zero,$f0
/*  f0cf3d0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cf3d4:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f0cf3d8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cf3dc:	46040032 */ 	c.eq.s	$f0,$f4
/*  f0cf3e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf3e4:	4500000b */ 	bc1f	.L0f0cf414
/*  f0cf3e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf3ec:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*  f0cf3f0:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0cf3f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf3f8:	45000006 */ 	bc1f	.L0f0cf414
/*  f0cf3fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf400:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*  f0cf404:	46080032 */ 	c.eq.s	$f0,$f8
/*  f0cf408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf40c:	450300c2 */ 	bc1tl	.L0f0cf718
/*  f0cf410:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cf414:
/*  f0cf414:	0fc1905e */ 	jal	func0f064178
/*  f0cf418:	afa600d0 */ 	sw	$a2,0xd0($sp)
/*  f0cf41c:	8fa600d0 */ 	lw	$a2,0xd0($sp)
/*  f0cf420:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f0cf424:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0cf428:	c4ca0000 */ 	lwc1	$f10,0x0($a2)
/*  f0cf42c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0cf430:	8c490328 */ 	lw	$t1,0x328($v0)
/*  f0cf434:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0cf438:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0cf43c:	24080020 */ 	addiu	$t0,$zero,0x20
/*  f0cf440:	8faa00c4 */ 	lw	$t2,0xc4($sp)
/*  f0cf444:	e7a600b8 */ 	swc1	$f6,0xb8($sp)
/*  f0cf448:	c60a000c */ 	lwc1	$f10,0xc($s0)
/*  f0cf44c:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f0cf450:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0cf454:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f0cf458:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0cf45c:	27a700a8 */ 	addiu	$a3,$sp,0xa8
/*  f0cf460:	27ad0074 */ 	addiu	$t5,$sp,0x74
/*  f0cf464:	240e0014 */ 	addiu	$t6,$zero,0x14
/*  f0cf468:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f0cf46c:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f0cf470:	c4c60008 */ 	lwc1	$f6,0x8($a2)
/*  f0cf474:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0cf478:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0cf47c:	11200003 */ 	beqz	$t1,.L0f0cf48c
/*  f0cf480:	e7aa00c0 */ 	swc1	$f10,0xc0($sp)
/*  f0cf484:	10000001 */ 	beqz	$zero,.L0f0cf48c
/*  f0cf488:	2408003f */ 	addiu	$t0,$zero,0x3f
.L0f0cf48c:
/*  f0cf48c:	8c4b0284 */ 	lw	$t3,0x284($v0)
/*  f0cf490:	44816000 */ 	mtc1	$at,$f12
/*  f0cf494:	c54000b4 */ 	lwc1	$f0,0xb4($t2)
/*  f0cf498:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f0cf49c:	460c0100 */ 	add.s	$f4,$f0,$f12
/*  f0cf4a0:	c582005c */ 	lwc1	$f2,0x5c($t4)
/*  f0cf4a4:	4604103e */ 	c.le.s	$f2,$f4
/*  f0cf4a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf4ac:	45020006 */ 	bc1fl	.L0f0cf4c8
/*  f0cf4b0:	c60a000c */ 	lwc1	$f10,0xc($s0)
/*  f0cf4b4:	c606000c */ 	lwc1	$f6,0xc($s0)
/*  f0cf4b8:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f0cf4bc:	10000003 */ 	beqz	$zero,.L0f0cf4cc
/*  f0cf4c0:	460c4480 */ 	add.s	$f18,$f8,$f12
/*  f0cf4c4:	c60a000c */ 	lwc1	$f10,0xc($s0)
.L0f0cf4c8:
/*  f0cf4c8:	460a1481 */ 	sub.s	$f18,$f2,$f10
.L0f0cf4cc:
/*  f0cf4cc:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0cf4d0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0cf4d4:	afa40044 */ 	sw	$a0,0x44($sp)
/*  f0cf4d8:	afa50040 */ 	sw	$a1,0x40($sp)
/*  f0cf4dc:	afa80070 */ 	sw	$t0,0x70($sp)
/*  f0cf4e0:	0fc1977f */ 	jal	func0f065dfc
/*  f0cf4e4:	e7b20068 */ 	swc1	$f18,0x68($sp)
/*  f0cf4e8:	87af00a8 */ 	lh	$t7,0xa8($sp)
/*  f0cf4ec:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0cf4f0:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0cf4f4:	10af000d */ 	beq	$a1,$t7,.L0f0cf52c
/*  f0cf4f8:	c7b20068 */ 	lwc1	$f18,0x68($sp)
/*  f0cf4fc:	27a200a8 */ 	addiu	$v0,$sp,0xa8
/*  f0cf500:	84430000 */ 	lh	$v1,0x0($v0)
/*  f0cf504:	87a400a6 */ 	lh	$a0,0xa6($sp)
.L0f0cf508:
/*  f0cf508:	14830004 */ 	bne	$a0,$v1,.L0f0cf51c
/*  f0cf50c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0cf510:	a7a400a8 */ 	sh	$a0,0xa8($sp)
/*  f0cf514:	10000005 */ 	beqz	$zero,.L0f0cf52c
/*  f0cf518:	a7b900aa */ 	sh	$t9,0xaa($sp)
.L0f0cf51c:
/*  f0cf51c:	84430002 */ 	lh	$v1,0x2($v0)
/*  f0cf520:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0cf524:	14a3fff8 */ 	bne	$a1,$v1,.L0f0cf508
/*  f0cf528:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cf52c:
/*  f0cf52c:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f0cf530:	e7b20068 */ 	swc1	$f18,0x68($sp)
/*  f0cf534:	afa80070 */ 	sw	$t0,0x70($sp)
/*  f0cf538:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0cf53c:	0fc087ea */ 	jal	func0f021fa8
/*  f0cf540:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f0cf544:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f0cf548:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f0cf54c:	3c0141d0 */ 	lui	$at,0x41d0
/*  f0cf550:	44818000 */ 	mtc1	$at,$f16
/*  f0cf554:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f0cf558:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cf55c:	44812000 */ 	mtc1	$at,$f4
/*  f0cf560:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0cf564:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f0cf568:	46048002 */ 	mul.s	$f0,$f16,$f4
/*  f0cf56c:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0cf570:	c7b20068 */ 	lwc1	$f18,0x68($sp)
/*  f0cf574:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0cf578:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0cf57c:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f0cf580:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cf584:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf588:	45030011 */ 	bc1tl	.L0f0cf5d0
/*  f0cf58c:	3c014170 */ 	lui	$at,0x4170
/*  f0cf590:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0cf594:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf598:	4503000d */ 	bc1tl	.L0f0cf5d0
/*  f0cf59c:	3c014170 */ 	lui	$at,0x4170
/*  f0cf5a0:	46000387 */ 	neg.s	$f14,$f0
/*  f0cf5a4:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0cf5a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf5ac:	45030008 */ 	bc1tl	.L0f0cf5d0
/*  f0cf5b0:	3c014170 */ 	lui	$at,0x4170
/*  f0cf5b4:	460e603c */ 	c.lt.s	$f12,$f14
/*  f0cf5b8:	27a70074 */ 	addiu	$a3,$sp,0x74
/*  f0cf5bc:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0cf5c0:	3c014170 */ 	lui	$at,0x4170
/*  f0cf5c4:	45020024 */ 	bc1fl	.L0f0cf658
/*  f0cf5c8:	44815000 */ 	mtc1	$at,$f10
/*  f0cf5cc:	3c014170 */ 	lui	$at,0x4170
.L0f0cf5d0:
/*  f0cf5d0:	44813000 */ 	mtc1	$at,$f6
/*  f0cf5d4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0cf5d8:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0cf5dc:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0cf5e0:	27a700a8 */ 	addiu	$a3,$sp,0xa8
/*  f0cf5e4:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f0cf5e8:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0cf5ec:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f0cf5f0:	afa80070 */ 	sw	$t0,0x70($sp)
/*  f0cf5f4:	e7b20068 */ 	swc1	$f18,0x68($sp)
/*  f0cf5f8:	0c00b657 */ 	jal	func0002d95c
/*  f0cf5fc:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0cf600:	3c0141d0 */ 	lui	$at,0x41d0
/*  f0cf604:	44818000 */ 	mtc1	$at,$f16
/*  f0cf608:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cf60c:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0cf610:	c7b20068 */ 	lwc1	$f18,0x68($sp)
/*  f0cf614:	14410019 */ 	bne	$v0,$at,.L0f0cf67c
/*  f0cf618:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0cf61c:	3c014170 */ 	lui	$at,0x4170
/*  f0cf620:	44814000 */ 	mtc1	$at,$f8
/*  f0cf624:	44068000 */ 	mfc1	$a2,$f16
/*  f0cf628:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0cf62c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0cf630:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0cf634:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0cf638:	27a700a8 */ 	addiu	$a3,$sp,0xa8
/*  f0cf63c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0cf640:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f0cf644:	0c00aa7c */ 	jal	func0002a9f0
/*  f0cf648:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0cf64c:	1000000b */ 	beqz	$zero,.L0f0cf67c
/*  f0cf650:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0cf654:	44815000 */ 	mtc1	$at,$f10
.L0f0cf658:
/*  f0cf658:	44068000 */ 	mfc1	$a2,$f16
/*  f0cf65c:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0cf660:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0cf664:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0cf668:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0cf66c:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f0cf670:	0c00aa7c */ 	jal	func0002a9f0
/*  f0cf674:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f0cf678:	afa200cc */ 	sw	$v0,0xcc($sp)
.L0f0cf67c:
/*  f0cf67c:	54400014 */ 	bnezl	$v0,.L0f0cf6d0
/*  f0cf680:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cf684:	0c0093ac */ 	jal	func00024eb0
/*  f0cf688:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf68c:	1040000f */ 	beqz	$v0,.L0f0cf6cc
/*  f0cf690:	00402025 */ 	or	$a0,$v0,$zero
/*  f0cf694:	904c0000 */ 	lbu	$t4,0x0($v0)
/*  f0cf698:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0cf69c:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x28c)
/*  f0cf6a0:	5581000b */ 	bnel	$t4,$at,.L0f0cf6d0
/*  f0cf6a4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cf6a8:	8dada24c */ 	lw	$t5,%lo(g_Vars+0x28c)($t5)
/*  f0cf6ac:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0cf6b0:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f0cf6b4:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0cf6b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0cf6bc:	3c018007 */ 	lui	$at,%hi(var80070ec0)
/*  f0cf6c0:	544e0003 */ 	bnel	$v0,$t6,.L0f0cf6d0
/*  f0cf6c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cf6c8:	a02f0ec0 */ 	sb	$t7,%lo(var80070ec0)($at)
.L0f0cf6cc:
/*  f0cf6cc:	02002025 */ 	or	$a0,$s0,$zero
.L0f0cf6d0:
/*  f0cf6d0:	0fc1905e */ 	jal	func0f064178
/*  f0cf6d4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cf6d8:	8fb800cc */ 	lw	$t8,0xcc($sp)
/*  f0cf6dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cf6e0:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f0cf6e4:	5701000c */ 	bnel	$t8,$at,.L0f0cf718
/*  f0cf6e8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0cf6ec:	e6040008 */ 	swc1	$f4,0x8($s0)
/*  f0cf6f0:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f0cf6f4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cf6f8:	e606000c */ 	swc1	$f6,0xc($s0)
/*  f0cf6fc:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0cf700:	0fc19711 */ 	jal	func0f065c44
/*  f0cf704:	e6080010 */ 	swc1	$f8,0x10($s0)
/*  f0cf708:	27a400a8 */ 	addiu	$a0,$sp,0xa8
/*  f0cf70c:	0fc195e9 */ 	jal	roomsCopy
/*  f0cf710:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0cf714:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cf718:
/*  f0cf718:	8fa200cc */ 	lw	$v0,0xcc($sp)
/*  f0cf71c:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0cf720:	03e00008 */ 	jr	$ra
/*  f0cf724:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);

GLOBAL_ASM(
glabel func0f0cf728
/*  f0cf728:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0cf72c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cf730:	0fc33ce3 */ 	jal	func0f0cf38c
/*  f0cf734:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf738:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cf73c:	1041004f */ 	beq	$v0,$at,.L0f0cf87c
/*  f0cf740:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0cf744:	3c088007 */ 	lui	$t0,%hi(var80070ec4)
/*  f0cf748:	25080ec4 */ 	addiu	$t0,$t0,%lo(var80070ec4)
/*  f0cf74c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0cf750:	0c0093ac */ 	jal	func00024eb0
/*  f0cf754:	a10e0000 */ 	sb	$t6,0x0($t0)
/*  f0cf758:	3c088007 */ 	lui	$t0,%hi(var80070ec4)
/*  f0cf75c:	25080ec4 */ 	addiu	$t0,$t0,%lo(var80070ec4)
/*  f0cf760:	10400046 */ 	beqz	$v0,.L0f0cf87c
/*  f0cf764:	00404825 */ 	or	$t1,$v0,$zero
/*  f0cf768:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x34)
/*  f0cf76c:	8def9ff4 */ 	lw	$t7,%lo(g_Vars+0x34)($t7)
/*  f0cf770:	59e00043 */ 	blezl	$t7,.L0f0cf880
/*  f0cf774:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cf778:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f0cf77c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0cf780:	5701002f */ 	bnel	$t8,$at,.L0f0cf840
/*  f0cf784:	91220000 */ 	lbu	$v0,0x0($t1)
/*  f0cf788:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f0cf78c:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f0cf790:	a1190000 */ 	sb	$t9,0x0($t0)
/*  f0cf794:	946a0070 */ 	lhu	$t2,0x70($v1)
/*  f0cf798:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*  f0cf79c:	27a50020 */ 	addiu	$a1,$sp,0x20
/*  f0cf7a0:	314b0400 */ 	andi	$t3,$t2,0x400
/*  f0cf7a4:	11600025 */ 	beqz	$t3,.L0f0cf83c
/*  f0cf7a8:	2406011e */ 	addiu	$a2,$zero,0x11e
/*  f0cf7ac:	3c077f1b */ 	lui	$a3,%hi(var7f1ada40)
/*  f0cf7b0:	24e7da40 */ 	addiu	$a3,$a3,%lo(var7f1ada40)
/*  f0cf7b4:	0c009393 */ 	jal	func00024e4c
/*  f0cf7b8:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0cf7bc:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*  f0cf7c0:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f0cf7c4:	44801000 */ 	mtc1	$zero,$f2
/*  f0cf7c8:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*  f0cf7cc:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f0cf7d0:	c7aa0020 */ 	lwc1	$f10,0x20($sp)
/*  f0cf7d4:	3c088007 */ 	lui	$t0,%hi(var80070ec4)
/*  f0cf7d8:	25080ec4 */ 	addiu	$t0,$t0,%lo(var80070ec4)
/*  f0cf7dc:	46001032 */ 	c.eq.s	$f2,$f0
/*  f0cf7e0:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f0cf7e4:	460a4401 */ 	sub.s	$f16,$f8,$f10
/*  f0cf7e8:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0cf7ec:	e7a2003c */ 	swc1	$f2,0x3c($sp)
/*  f0cf7f0:	45000004 */ 	bc1f	.L0f0cf804
/*  f0cf7f4:	e7b00040 */ 	swc1	$f16,0x40($sp)
/*  f0cf7f8:	46101032 */ 	c.eq.s	$f2,$f16
/*  f0cf7fc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cf800:	45010009 */ 	bc1t	.L0f0cf828
.L0f0cf804:
/*  f0cf804:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f0cf808:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f0cf80c:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0cf810:	0c0011e4 */ 	jal	scaleTo1
/*  f0cf814:	afa90048 */ 	sw	$t1,0x48($sp)
/*  f0cf818:	3c088007 */ 	lui	$t0,%hi(var80070ec4)
/*  f0cf81c:	25080ec4 */ 	addiu	$t0,$t0,%lo(var80070ec4)
/*  f0cf820:	10000004 */ 	beqz	$zero,.L0f0cf834
/*  f0cf824:	8fa90048 */ 	lw	$t1,0x48($sp)
.L0f0cf828:
/*  f0cf828:	44819000 */ 	mtc1	$at,$f18
/*  f0cf82c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf830:	e7b20040 */ 	swc1	$f18,0x40($sp)
.L0f0cf834:
/*  f0cf834:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f0cf838:	a10c0000 */ 	sb	$t4,0x0($t0)
.L0f0cf83c:
/*  f0cf83c:	91220000 */ 	lbu	$v0,0x0($t1)
.L0f0cf840:
/*  f0cf840:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0cf844:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0cf848:	54410004 */ 	bnel	$v0,$at,.L0f0cf85c
/*  f0cf84c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0cf850:	1000000a */ 	beqz	$zero,.L0f0cf87c
/*  f0cf854:	a10d0000 */ 	sb	$t5,0x0($t0)
/*  f0cf858:	24010006 */ 	addiu	$at,$zero,0x6
.L0f0cf85c:
/*  f0cf85c:	14410003 */ 	bne	$v0,$at,.L0f0cf86c
/*  f0cf860:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0cf864:	10000005 */ 	beqz	$zero,.L0f0cf87c
/*  f0cf868:	a10e0000 */ 	sb	$t6,0x0($t0)
.L0f0cf86c:
/*  f0cf86c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cf870:	14410002 */ 	bne	$v0,$at,.L0f0cf87c
/*  f0cf874:	240f0005 */ 	addiu	$t7,$zero,0x5
/*  f0cf878:	a10f0000 */ 	sb	$t7,0x0($t0)
.L0f0cf87c:
/*  f0cf87c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0cf880:
/*  f0cf880:	8fa2004c */ 	lw	$v0,0x4c($sp)
/*  f0cf884:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f0cf888:	03e00008 */ 	jr	$ra
/*  f0cf88c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cf890
/*  f0cf890:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0cf894:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cf898:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0cf89c:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0cf8a0:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f0cf8a4:	0c0093a9 */ 	jal	func00024ea4
/*  f0cf8a8:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f0cf8ac:	5040004e */ 	beqzl	$v0,.L0f0cf9e8
/*  f0cf8b0:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0cf8b4:	0c0093a6 */ 	jal	func00024e98
/*  f0cf8b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf8bc:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0cf8c0:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cf8c4:	44811000 */ 	mtc1	$at,$f2
/*  f0cf8c8:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f0cf8cc:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f0cf8d0:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0cf8d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf8d8:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0cf8dc:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0cf8e0:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f0cf8e4:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0cf8e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf8ec:	46028482 */ 	mul.s	$f18,$f16,$f2
/*  f0cf8f0:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*  f0cf8f4:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0cf8f8:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0cf8fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf900:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0cf904:	0fc33dca */ 	jal	func0f0cf728
/*  f0cf908:	e7a8002c */ 	swc1	$f8,0x2c($sp)
/*  f0cf90c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cf910:	14410003 */ 	bne	$v0,$at,.L0f0cf920
/*  f0cf914:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf918:	10000033 */ 	beqz	$zero,.L0f0cf9e8
/*  f0cf91c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0cf920:
/*  f0cf920:	14400030 */ 	bnez	$v0,.L0f0cf9e4
/*  f0cf924:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0cf928:	3c077f1b */ 	lui	$a3,%hi(var7f1ada50)
/*  f0cf92c:	24e7da50 */ 	addiu	$a3,$a3,%lo(var7f1ada50)
/*  f0cf930:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0cf934:	0c009393 */ 	jal	func00024e4c
/*  f0cf938:	2406015e */ 	addiu	$a2,$zero,0x15e
/*  f0cf93c:	8fa20034 */ 	lw	$v0,0x34($sp)
/*  f0cf940:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0cf944:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0cf948:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f0cf94c:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f0cf950:	46105032 */ 	c.eq.s	$f10,$f16
/*  f0cf954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf958:	45000020 */ 	bc1f	.L0f0cf9dc
/*  f0cf95c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf960:	c4720004 */ 	lwc1	$f18,0x4($v1)
/*  f0cf964:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f0cf968:	46049032 */ 	c.eq.s	$f18,$f4
/*  f0cf96c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf970:	4500001a */ 	bc1f	.L0f0cf9dc
/*  f0cf974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf978:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f0cf97c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0cf980:	8fa20038 */ 	lw	$v0,0x38($sp)
/*  f0cf984:	46083032 */ 	c.eq.s	$f6,$f8
/*  f0cf988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf98c:	45000013 */ 	bc1f	.L0f0cf9dc
/*  f0cf990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf994:	c4aa0000 */ 	lwc1	$f10,0x0($a1)
/*  f0cf998:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f0cf99c:	46105032 */ 	c.eq.s	$f10,$f16
/*  f0cf9a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf9a4:	4500000d */ 	bc1f	.L0f0cf9dc
/*  f0cf9a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf9ac:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*  f0cf9b0:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f0cf9b4:	46049032 */ 	c.eq.s	$f18,$f4
/*  f0cf9b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf9bc:	45000007 */ 	bc1f	.L0f0cf9dc
/*  f0cf9c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf9c4:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f0cf9c8:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0cf9cc:	46083032 */ 	c.eq.s	$f6,$f8
/*  f0cf9d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf9d4:	45030004 */ 	bc1tl	.L0f0cf9e8
/*  f0cf9d8:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0cf9dc:
/*  f0cf9dc:	10000002 */ 	beqz	$zero,.L0f0cf9e8
/*  f0cf9e0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0cf9e4:
/*  f0cf9e4:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0cf9e8:
/*  f0cf9e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cf9ec:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0cf9f0:	03e00008 */ 	jr	$ra
/*  f0cf9f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cf9f8
/*  f0cf9f8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0cf9fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cfa00:	c4c20000 */ 	lwc1	$f2,0x0($a2)
/*  f0cfa04:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f0cfa08:	00803825 */ 	or	$a3,$a0,$zero
/*  f0cfa0c:	46020032 */ 	c.eq.s	$f0,$f2
/*  f0cfa10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfa14:	45020009 */ 	bc1fl	.L0f0cfa3c
/*  f0cfa18:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f0cfa1c:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f0cfa20:	c4c60008 */ 	lwc1	$f6,0x8($a2)
/*  f0cfa24:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0cfa28:	46062032 */ 	c.eq.s	$f4,$f6
/*  f0cfa2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfa30:	4501002e */ 	bc1t	.L0f0cfaec
/*  f0cfa34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfa38:	46001201 */ 	sub.s	$f8,$f2,$f0
.L0f0cfa3c:
/*  f0cfa3c:	44805000 */ 	mtc1	$zero,$f10
/*  f0cfa40:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f0cfa44:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f0cfa48:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f0cfa4c:	c4d00008 */ 	lwc1	$f16,0x8($a2)
/*  f0cfa50:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*  f0cfa54:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f0cfa58:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f0cfa5c:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*  f0cfa60:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*  f0cfa64:	46063202 */ 	mul.s	$f8,$f6,$f6
/*  f0cfa68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfa6c:	460a5402 */ 	mul.s	$f16,$f10,$f10
/*  f0cfa70:	0c012974 */ 	jal	sqrtf
/*  f0cfa74:	46104300 */ 	add.s	$f12,$f8,$f16
/*  f0cfa78:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cfa7c:	44819000 */ 	mtc1	$at,$f18
/*  f0cfa80:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*  f0cfa84:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*  f0cfa88:	46009083 */ 	div.s	$f2,$f18,$f0
/*  f0cfa8c:	8fa70040 */ 	lw	$a3,0x40($sp)
/*  f0cfa90:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f0cfa94:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0cfa98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfa9c:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0cfaa0:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f0cfaa4:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*  f0cfaa8:	c4f00008 */ 	lwc1	$f16,0x8($a3)
/*  f0cfaac:	c4e40000 */ 	lwc1	$f4,0x0($a3)
/*  f0cfab0:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f0cfab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfab8:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0cfabc:	44802000 */ 	mtc1	$zero,$f4
/*  f0cfac0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfac4:	e7a40028 */ 	swc1	$f4,0x28($sp)
/*  f0cfac8:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f0cfacc:	460c3402 */ 	mul.s	$f16,$f6,$f12
/*  f0cfad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfad4:	460c4482 */ 	mul.s	$f18,$f8,$f12
/*  f0cfad8:	e7b00024 */ 	swc1	$f16,0x24($sp)
/*  f0cfadc:	0fc33dca */ 	jal	func0f0cf728
/*  f0cfae0:	e7b2002c */ 	swc1	$f18,0x2c($sp)
/*  f0cfae4:	10000002 */ 	beqz	$zero,.L0f0cfaf0
/*  f0cfae8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0cfaec:
/*  f0cfaec:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0cfaf0:
/*  f0cfaf0:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0cfaf4:	03e00008 */ 	jr	$ra
/*  f0cfaf8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cfafc
/*  f0cfafc:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0cfb00:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0cfb04:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0cfb08:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cfb0c:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0cfb10:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f0cfb14:	c4aa0000 */ 	lwc1	$f10,0x0($a1)
/*  f0cfb18:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f0cfb1c:	3c0141d0 */ 	lui	$at,0x41d0
/*  f0cfb20:	44811000 */ 	mtc1	$at,$f2
/*  f0cfb24:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0cfb28:	00803825 */ 	or	$a3,$a0,$zero
/*  f0cfb2c:	46021002 */ 	mul.s	$f0,$f2,$f2
/*  f0cfb30:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0cfb34:	46085401 */ 	sub.s	$f16,$f10,$f8
/*  f0cfb38:	e7b00034 */ 	swc1	$f16,0x34($sp)
/*  f0cfb3c:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f0cfb40:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0cfb44:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f0cfb48:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0cfb4c:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*  f0cfb50:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0cfb54:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*  f0cfb58:	c7b0003c */ 	lwc1	$f16,0x3c($sp)
/*  f0cfb5c:	46108482 */ 	mul.s	$f18,$f16,$f16
/*  f0cfb60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfb64:	46042282 */ 	mul.s	$f10,$f4,$f4
/*  f0cfb68:	460a9180 */ 	add.s	$f6,$f18,$f10
/*  f0cfb6c:	4600303e */ 	c.le.s	$f6,$f0
/*  f0cfb70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfb74:	4500003e */ 	bc1f	.L0f0cfc70
/*  f0cfb78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfb7c:	c4a80000 */ 	lwc1	$f8,0x0($a1)
/*  f0cfb80:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f0cfb84:	46104032 */ 	c.eq.s	$f8,$f16
/*  f0cfb88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfb8c:	45020008 */ 	bc1fl	.L0f0cfbb0
/*  f0cfb90:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f0cfb94:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f0cfb98:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f0cfb9c:	46122032 */ 	c.eq.s	$f4,$f18
/*  f0cfba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfba4:	45030086 */ 	bc1tl	.L0f0cfdc0
/*  f0cfba8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cfbac:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
.L0f0cfbb0:
/*  f0cfbb0:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0cfbb4:	44802000 */ 	mtc1	$zero,$f4
/*  f0cfbb8:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0cfbbc:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*  f0cfbc0:	46004407 */ 	neg.s	$f16,$f8
/*  f0cfbc4:	e7b00034 */ 	swc1	$f16,0x34($sp)
/*  f0cfbc8:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0cfbcc:	c4b20000 */ 	lwc1	$f18,0x0($a1)
/*  f0cfbd0:	46108202 */ 	mul.s	$f8,$f16,$f16
/*  f0cfbd4:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f0cfbd8:	460a9181 */ 	sub.s	$f6,$f18,$f10
/*  f0cfbdc:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*  f0cfbe0:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*  f0cfbe4:	46042482 */ 	mul.s	$f18,$f4,$f4
/*  f0cfbe8:	0c012974 */ 	jal	sqrtf
/*  f0cfbec:	46089300 */ 	add.s	$f12,$f18,$f8
/*  f0cfbf0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cfbf4:	44815000 */ 	mtc1	$at,$f10
/*  f0cfbf8:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f0cfbfc:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*  f0cfc00:	46005083 */ 	div.s	$f2,$f10,$f0
/*  f0cfc04:	8fa70040 */ 	lw	$a3,0x40($sp)
/*  f0cfc08:	27a40028 */ 	addiu	$a0,$sp,0x28
/*  f0cfc0c:	46023402 */ 	mul.s	$f16,$f6,$f2
/*  f0cfc10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfc14:	46022482 */ 	mul.s	$f18,$f4,$f2
/*  f0cfc18:	e7b00034 */ 	swc1	$f16,0x34($sp)
/*  f0cfc1c:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f0cfc20:	c4e80008 */ 	lwc1	$f8,0x8($a3)
/*  f0cfc24:	c4e60000 */ 	lwc1	$f6,0x0($a3)
/*  f0cfc28:	46089282 */ 	mul.s	$f10,$f18,$f8
/*  f0cfc2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfc30:	46103102 */ 	mul.s	$f4,$f6,$f16
/*  f0cfc34:	46045300 */ 	add.s	$f12,$f10,$f4
/*  f0cfc38:	44805000 */ 	mtc1	$zero,$f10
/*  f0cfc3c:	460c8202 */ 	mul.s	$f8,$f16,$f12
/*  f0cfc40:	e7aa002c */ 	swc1	$f10,0x2c($sp)
/*  f0cfc44:	460c9182 */ 	mul.s	$f6,$f18,$f12
/*  f0cfc48:	e7a80034 */ 	swc1	$f8,0x34($sp)
/*  f0cfc4c:	e7a80028 */ 	swc1	$f8,0x28($sp)
/*  f0cfc50:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*  f0cfc54:	0fc33dca */ 	jal	func0f0cf728
/*  f0cfc58:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f0cfc5c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cfc60:	54410057 */ 	bnel	$v0,$at,.L0f0cfdc0
/*  f0cfc64:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cfc68:	10000055 */ 	beqz	$zero,.L0f0cfdc0
/*  f0cfc6c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0cfc70:
/*  f0cfc70:	c4e40000 */ 	lwc1	$f4,0x0($a3)
/*  f0cfc74:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f0cfc78:	c4c80000 */ 	lwc1	$f8,0x0($a2)
/*  f0cfc7c:	46102480 */ 	add.s	$f18,$f4,$f16
/*  f0cfc80:	46124281 */ 	sub.s	$f10,$f8,$f18
/*  f0cfc84:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f0cfc88:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0cfc8c:	c4e60008 */ 	lwc1	$f6,0x8($a3)
/*  f0cfc90:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*  f0cfc94:	46043400 */ 	add.s	$f16,$f6,$f4
/*  f0cfc98:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*  f0cfc9c:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f0cfca0:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f0cfca4:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*  f0cfca8:	460a5182 */ 	mul.s	$f6,$f10,$f10
/*  f0cfcac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfcb0:	46042202 */ 	mul.s	$f8,$f4,$f4
/*  f0cfcb4:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f0cfcb8:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cfcbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfcc0:	4500003e */ 	bc1f	.L0f0cfdbc
/*  f0cfcc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfcc8:	c4d20000 */ 	lwc1	$f18,0x0($a2)
/*  f0cfccc:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0cfcd0:	460a9032 */ 	c.eq.s	$f18,$f10
/*  f0cfcd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfcd8:	45020008 */ 	bc1fl	.L0f0cfcfc
/*  f0cfcdc:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*  f0cfce0:	c4c40008 */ 	lwc1	$f4,0x8($a2)
/*  f0cfce4:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0cfce8:	46062032 */ 	c.eq.s	$f4,$f6
/*  f0cfcec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfcf0:	45030033 */ 	bc1tl	.L0f0cfdc0
/*  f0cfcf4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cfcf8:	c4c80008 */ 	lwc1	$f8,0x8($a2)
.L0f0cfcfc:
/*  f0cfcfc:	c4500010 */ 	lwc1	$f16,0x10($v0)
/*  f0cfd00:	44802000 */ 	mtc1	$zero,$f4
/*  f0cfd04:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f0cfd08:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*  f0cfd0c:	46009287 */ 	neg.s	$f10,$f18
/*  f0cfd10:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f0cfd14:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0cfd18:	c4c60000 */ 	lwc1	$f6,0x0($a2)
/*  f0cfd1c:	460a5482 */ 	mul.s	$f18,$f10,$f10
/*  f0cfd20:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f0cfd24:	46083401 */ 	sub.s	$f16,$f6,$f8
/*  f0cfd28:	e7b0003c */ 	swc1	$f16,0x3c($sp)
/*  f0cfd2c:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*  f0cfd30:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f0cfd34:	0c012974 */ 	jal	sqrtf
/*  f0cfd38:	46123300 */ 	add.s	$f12,$f6,$f18
/*  f0cfd3c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cfd40:	44814000 */ 	mtc1	$at,$f8
/*  f0cfd44:	c7b00034 */ 	lwc1	$f16,0x34($sp)
/*  f0cfd48:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*  f0cfd4c:	46004083 */ 	div.s	$f2,$f8,$f0
/*  f0cfd50:	8fa70040 */ 	lw	$a3,0x40($sp)
/*  f0cfd54:	27a40028 */ 	addiu	$a0,$sp,0x28
/*  f0cfd58:	46028282 */ 	mul.s	$f10,$f16,$f2
/*  f0cfd5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfd60:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0cfd64:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f0cfd68:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*  f0cfd6c:	c4f20008 */ 	lwc1	$f18,0x8($a3)
/*  f0cfd70:	c4f00000 */ 	lwc1	$f16,0x0($a3)
/*  f0cfd74:	46123202 */ 	mul.s	$f8,$f6,$f18
/*  f0cfd78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cfd7c:	460a8102 */ 	mul.s	$f4,$f16,$f10
/*  f0cfd80:	46044300 */ 	add.s	$f12,$f8,$f4
/*  f0cfd84:	44804000 */ 	mtc1	$zero,$f8
/*  f0cfd88:	460c5482 */ 	mul.s	$f18,$f10,$f12
/*  f0cfd8c:	e7a8002c */ 	swc1	$f8,0x2c($sp)
/*  f0cfd90:	460c3402 */ 	mul.s	$f16,$f6,$f12
/*  f0cfd94:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f0cfd98:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*  f0cfd9c:	e7b0003c */ 	swc1	$f16,0x3c($sp)
/*  f0cfda0:	0fc33dca */ 	jal	func0f0cf728
/*  f0cfda4:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f0cfda8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cfdac:	54410004 */ 	bnel	$v0,$at,.L0f0cfdc0
/*  f0cfdb0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cfdb4:	10000002 */ 	beqz	$zero,.L0f0cfdc0
/*  f0cfdb8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0cfdbc:
/*  f0cfdbc:	00001025 */ 	or	$v0,$zero,$zero
.L0f0cfdc0:
/*  f0cfdc0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cfdc4:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0cfdc8:	03e00008 */ 	jr	$ra
/*  f0cfdcc:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 func0f0cfdd0(struct coord *arg0, struct coord *arg1, struct coord *arg2)
{
	s32 iVar1 = func0f0cf728(arg0);

	if (iVar1 != 1) {
		func00024e4c(arg1, arg2, 0x1d9, "bondeyespy.c");
	}

	return iVar1;
}

const char var7f1ada70[] = "g";
const char var7f1ada74[] = "l";
const char var7f1ada78[] = "%s%s";

GLOBAL_ASM(
glabel func0f0cfe24
.late_rodata
glabel var7f1ada90
.word 0x3c23d70a
glabel var7f1ada94
.word 0x411ffffe
.text
/*  f0cfe24:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0cfe28:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0cfe2c:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0cfe30:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0cfe34:	8c4e0480 */ 	lw	$t6,0x480($v0)
/*  f0cfe38:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0cfe3c:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0cfe40:	8dc30000 */ 	lw	$v1,0x0($t6)
/*  f0cfe44:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f0cfe48:	8c6f0004 */ 	lw	$t7,0x4($v1)
/*  f0cfe4c:	a3a00073 */ 	sb	$zero,0x73($sp)
/*  f0cfe50:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f0cfe54:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0cfe58:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f0cfe5c:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f0cfe60:	44802000 */ 	mtc1	$zero,$f4
/*  f0cfe64:	e7a60080 */ 	swc1	$f6,0x80($sp)
/*  f0cfe68:	c4680010 */ 	lwc1	$f8,0x10($v1)
/*  f0cfe6c:	e7a80084 */ 	swc1	$f8,0x84($sp)
/*  f0cfe70:	8c580480 */ 	lw	$t8,0x480($v0)
/*  f0cfe74:	c70a0040 */ 	lwc1	$f10,0x40($t8)
/*  f0cfe78:	e7a40094 */ 	swc1	$f4,0x94($sp)
/*  f0cfe7c:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f0cfe80:	8c590480 */ 	lw	$t9,0x480($v0)
/*  f0cfe84:	c7260048 */ 	lwc1	$f6,0x48($t9)
/*  f0cfe88:	afa3009c */ 	sw	$v1,0x9c($sp)
/*  f0cfe8c:	0fc33f74 */ 	jal	func0f0cfdd0
/*  f0cfe90:	e7a60098 */ 	swc1	$f6,0x98($sp)
/*  f0cfe94:	1440002d */ 	bnez	$v0,.L0f0cff4c
/*  f0cfe98:	27a80054 */ 	addiu	$t0,$sp,0x54
/*  f0cfe9c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0cfea0:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0cfea4:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0cfea8:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f0cfeac:	0fc33e24 */ 	jal	func0f0cf890
/*  f0cfeb0:	27a70060 */ 	addiu	$a3,$sp,0x60
/*  f0cfeb4:	1040000c */ 	beqz	$v0,.L0f0cfee8
/*  f0cfeb8:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0cfebc:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0cfec0:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0cfec4:	0fc33e7e */ 	jal	func0f0cf9f8
/*  f0cfec8:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f0cfecc:	1c40001f */ 	bgtz	$v0,.L0f0cff4c
/*  f0cfed0:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0cfed4:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0cfed8:	0fc33ebf */ 	jal	func0f0cfafc
/*  f0cfedc:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f0cfee0:	1000001a */ 	beqz	$zero,.L0f0cff4c
/*  f0cfee4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cfee8:
/*  f0cfee8:	27a90038 */ 	addiu	$t1,$sp,0x38
/*  f0cfeec:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0cfef0:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f0cfef4:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0cfef8:	0fc33e24 */ 	jal	func0f0cf890
/*  f0cfefc:	27a70044 */ 	addiu	$a3,$sp,0x44
/*  f0cff00:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0cff04:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f0cff08:	0fc33e7e */ 	jal	func0f0cf9f8
/*  f0cff0c:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0cff10:	1c40000e */ 	bgtz	$v0,.L0f0cff4c
/*  f0cff14:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0cff18:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0cff1c:	0fc33e7e */ 	jal	func0f0cf9f8
/*  f0cff20:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f0cff24:	1c400009 */ 	bgtz	$v0,.L0f0cff4c
/*  f0cff28:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0cff2c:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f0cff30:	0fc33ebf */ 	jal	func0f0cfafc
/*  f0cff34:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f0cff38:	1c400004 */ 	bgtz	$v0,.L0f0cff4c
/*  f0cff3c:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0cff40:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0cff44:	0fc33ebf */ 	jal	func0f0cfafc
/*  f0cff48:	27a600a0 */ 	addiu	$a2,$sp,0xa0
.L0f0cff4c:
/*  f0cff4c:	3c047f1b */ 	lui	$a0,%hi(var7f1ada70)
/*  f0cff50:	3c058007 */ 	lui	$a1,%hi(var80070ed8)
/*  f0cff54:	24a50ed8 */ 	addiu	$a1,$a1,%lo(var80070ed8)
/*  f0cff58:	0c0036cc */ 	jal	func0000db30
/*  f0cff5c:	2484da70 */ 	addiu	$a0,$a0,%lo(var7f1ada70)
/*  f0cff60:	3c047f1b */ 	lui	$a0,%hi(var7f1ada74)
/*  f0cff64:	3c058007 */ 	lui	$a1,%hi(var80070edc)
/*  f0cff68:	24a50edc */ 	addiu	$a1,$a1,%lo(var80070edc)
/*  f0cff6c:	0c0036cc */ 	jal	func0000db30
/*  f0cff70:	2484da74 */ 	addiu	$a0,$a0,%lo(var7f1ada74)
/*  f0cff74:	3c0a8007 */ 	lui	$t2,%hi(var80070ed8)
/*  f0cff78:	8d4a0ed8 */ 	lw	$t2,%lo(var80070ed8)($t2)
/*  f0cff7c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0cff80:	448a4000 */ 	mtc1	$t2,$f8
/*  f0cff84:	05410005 */ 	bgez	$t2,.L0f0cff9c
/*  f0cff88:	468042a1 */ 	cvt.d.w	$f10,$f8
/*  f0cff8c:	44812800 */ 	mtc1	$at,$f5
/*  f0cff90:	44802000 */ 	mtc1	$zero,$f4
/*  f0cff94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cff98:	46245280 */ 	add.d	$f10,$f10,$f4
.L0f0cff9c:
/*  f0cff9c:	3c017f1b */ 	lui	$at,%hi(var7f1ada88)
/*  f0cffa0:	d426da88 */ 	ldc1	$f6,%lo(var7f1ada88)($at)
/*  f0cffa4:	3c0b8007 */ 	lui	$t3,%hi(var80070edc)
/*  f0cffa8:	8d6b0edc */ 	lw	$t3,%lo(var80070edc)($t3)
/*  f0cffac:	46265202 */ 	mul.d	$f8,$f10,$f6
/*  f0cffb0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0cffb4:	448b2000 */ 	mtc1	$t3,$f4
/*  f0cffb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cffbc:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0cffc0:	05610004 */ 	bgez	$t3,.L0f0cffd4
/*  f0cffc4:	46204420 */ 	cvt.s.d	$f16,$f8
/*  f0cffc8:	44813000 */ 	mtc1	$at,$f6
/*  f0cffcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cffd0:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f0cffd4:
/*  f0cffd4:	3c017f1b */ 	lui	$at,%hi(var7f1ada90)
/*  f0cffd8:	c428da90 */ 	lwc1	$f8,%lo(var7f1ada90)($at)
/*  f0cffdc:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f0cffe0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cffe4:	46085302 */ 	mul.s	$f12,$f10,$f8
/*  f0cffe8:	c58e00b4 */ 	lwc1	$f14,0xb4($t4)
/*  f0cffec:	e7b00078 */ 	swc1	$f16,0x78($sp)
/*  f0cfff0:	e7ae006c */ 	swc1	$f14,0x6c($sp)
/*  f0cfff4:	0fc33c54 */ 	jal	eyespyFindGround
/*  f0cfff8:	e7ac0074 */ 	swc1	$f12,0x74($sp)
/*  f0cfffc:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f0d0000:	c7ac0074 */ 	lwc1	$f12,0x74($sp)
/*  f0d0004:	c7ae006c */ 	lwc1	$f14,0x6c($sp)
/*  f0d0008:	c46200b4 */ 	lwc1	$f2,0xb4($v1)
/*  f0d000c:	c7b00078 */ 	lwc1	$f16,0x78($sp)
/*  f0d0010:	46000486 */ 	mov.s	$f18,$f0
/*  f0d0014:	46020032 */ 	c.eq.s	$f0,$f2
/*  f0d0018:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x284)
/*  f0d001c:	45030046 */ 	bc1tl	.L0f0d0138
/*  f0d0020:	46027301 */ 	sub.s	$f12,$f14,$f2
/*  f0d0024:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0d0028:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x284)
/*  f0d002c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0d0030:	45020019 */ 	bc1fl	.L0f0d0098
/*  f0d0034:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0d0038:	8dada244 */ 	lw	$t5,%lo(g_Vars+0x284)($t5)
/*  f0d003c:	8da20480 */ 	lw	$v0,0x480($t5)
/*  f0d0040:	c4420064 */ 	lwc1	$f2,0x64($v0)
/*  f0d0044:	4602603e */ 	c.le.s	$f12,$f2
/*  f0d0048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d004c:	45020004 */ 	bc1fl	.L0f0d0060
/*  f0d0050:	46101100 */ 	add.s	$f4,$f2,$f16
/*  f0d0054:	10000003 */ 	beqz	$zero,.L0f0d0064
/*  f0d0058:	e44c0064 */ 	swc1	$f12,0x64($v0)
/*  f0d005c:	46101100 */ 	add.s	$f4,$f2,$f16
.L0f0d0060:
/*  f0d0060:	e4440064 */ 	swc1	$f4,0x64($v0)
.L0f0d0064:
/*  f0d0064:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0d0068:	8dc20480 */ 	lw	$v0,0x480($t6)
/*  f0d006c:	c4460064 */ 	lwc1	$f6,0x64($v0)
/*  f0d0070:	46067381 */ 	sub.s	$f14,$f14,$f6
/*  f0d0074:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0d0078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d007c:	45000020 */ 	bc1f	.L0f0d0100
/*  f0d0080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0084:	44805000 */ 	mtc1	$zero,$f10
/*  f0d0088:	46000386 */ 	mov.s	$f14,$f0
/*  f0d008c:	1000001c */ 	beqz	$zero,.L0f0d0100
/*  f0d0090:	e44a0064 */ 	swc1	$f10,0x64($v0)
/*  f0d0094:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0d0098:
/*  f0d0098:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0d009c:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f0d00a0:	45000017 */ 	bc1f	.L0f0d0100
/*  f0d00a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d00a8:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0d00ac:	8de20480 */ 	lw	$v0,0x480($t7)
/*  f0d00b0:	c4420064 */ 	lwc1	$f2,0x64($v0)
/*  f0d00b4:	4602603e */ 	c.le.s	$f12,$f2
/*  f0d00b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d00bc:	45020004 */ 	bc1fl	.L0f0d00d0
/*  f0d00c0:	46101200 */ 	add.s	$f8,$f2,$f16
/*  f0d00c4:	10000003 */ 	beqz	$zero,.L0f0d00d4
/*  f0d00c8:	e44c0064 */ 	swc1	$f12,0x64($v0)
/*  f0d00cc:	46101200 */ 	add.s	$f8,$f2,$f16
.L0f0d00d0:
/*  f0d00d0:	e4480064 */ 	swc1	$f8,0x64($v0)
.L0f0d00d4:
/*  f0d00d4:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f0d00d8:	8f020480 */ 	lw	$v0,0x480($t8)
/*  f0d00dc:	c4440064 */ 	lwc1	$f4,0x64($v0)
/*  f0d00e0:	46047380 */ 	add.s	$f14,$f14,$f4
/*  f0d00e4:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0d00e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d00ec:	45000004 */ 	bc1f	.L0f0d0100
/*  f0d00f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d00f4:	44803000 */ 	mtc1	$zero,$f6
/*  f0d00f8:	46000386 */ 	mov.s	$f14,$f0
/*  f0d00fc:	e4460064 */ 	swc1	$f6,0x64($v0)
.L0f0d0100:
/*  f0d0100:	8f39a244 */ 	lw	$t9,%lo(g_Vars+0x284)($t9)
/*  f0d0104:	3c018007 */ 	lui	$at,0x8007
/*  f0d0108:	c42a0ed4 */ 	lwc1	$f10,0xed4($at)
/*  f0d010c:	8f280480 */ 	lw	$t0,0x480($t9)
/*  f0d0110:	c46200b4 */ 	lwc1	$f2,0xb4($v1)
/*  f0d0114:	460a0300 */ 	add.s	$f12,$f0,$f10
/*  f0d0118:	c5100060 */ 	lwc1	$f16,0x60($t0)
/*  f0d011c:	46101200 */ 	add.s	$f8,$f2,$f16
/*  f0d0120:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0d0124:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0128:	45020003 */ 	bc1fl	.L0f0d0138
/*  f0d012c:	46027301 */ 	sub.s	$f12,$f14,$f2
/*  f0d0130:	46106381 */ 	sub.s	$f14,$f12,$f16
/*  f0d0134:	46027301 */ 	sub.s	$f12,$f14,$f2
.L0f0d0138:
/*  f0d0138:	e7ae006c */ 	swc1	$f14,0x6c($sp)
/*  f0d013c:	0fc33c8c */ 	jal	func0f0cf230
/*  f0d0140:	e7b2008c */ 	swc1	$f18,0x8c($sp)
/*  f0d0144:	c7ae006c */ 	lwc1	$f14,0x6c($sp)
/*  f0d0148:	10400004 */ 	beqz	$v0,.L0f0d015c
/*  f0d014c:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f0d0150:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f0d0154:	10000007 */ 	beqz	$zero,.L0f0d0174
/*  f0d0158:	e48e00b4 */ 	swc1	$f14,0xb4($a0)
.L0f0d015c:
/*  f0d015c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x284)
/*  f0d0160:	8d29a244 */ 	lw	$t1,%lo(g_Vars+0x284)($t1)
/*  f0d0164:	44802000 */ 	mtc1	$zero,$f4
/*  f0d0168:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f0d016c:	e5440064 */ 	swc1	$f4,0x64($t2)
/*  f0d0170:	8fa40088 */ 	lw	$a0,0x88($sp)
.L0f0d0174:
/*  f0d0174:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x284)
/*  f0d0178:	8d6ba244 */ 	lw	$t3,%lo(g_Vars+0x284)($t3)
/*  f0d017c:	3c017f1b */ 	lui	$at,%hi(var7f1ada94)
/*  f0d0180:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x284)
/*  f0d0184:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f0d0188:	44804000 */ 	mtc1	$zero,$f8
/*  f0d018c:	e592005c */ 	swc1	$f18,0x5c($t4)
/*  f0d0190:	c48200b4 */ 	lwc1	$f2,0xb4($a0)
/*  f0d0194:	e48200b8 */ 	swc1	$f2,0xb8($a0)
/*  f0d0198:	c426da94 */ 	lwc1	$f6,%lo(var7f1ada94)($at)
/*  f0d019c:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0d01a0:	e48a00b0 */ 	swc1	$f10,0xb0($a0)
/*  f0d01a4:	8dada244 */ 	lw	$t5,%lo(g_Vars+0x284)($t5)
/*  f0d01a8:	8da20480 */ 	lw	$v0,0x480($t5)
/*  f0d01ac:	c44c0044 */ 	lwc1	$f12,0x44($v0)
/*  f0d01b0:	460c4032 */ 	c.eq.s	$f8,$f12
/*  f0d01b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d01b8:	4501002e */ 	bc1t	.L0f0d0274
/*  f0d01bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d01c0:	c4500060 */ 	lwc1	$f16,0x60($v0)
/*  f0d01c4:	3c018007 */ 	lui	$at,0x8007
/*  f0d01c8:	c4220ed4 */ 	lwc1	$f2,0xed4($at)
/*  f0d01cc:	46106000 */ 	add.s	$f0,$f12,$f16
/*  f0d01d0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0d01d4:	3c018007 */ 	lui	$at,0x8007
/*  f0d01d8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0d01dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d01e0:	45000004 */ 	bc1f	.L0f0d01f4
/*  f0d01e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d01e8:	46001006 */ 	mov.s	$f0,$f2
/*  f0d01ec:	10000008 */ 	beqz	$zero,.L0f0d0210
/*  f0d01f0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0d01f4:
/*  f0d01f4:	c4220ed0 */ 	lwc1	$f2,0xed0($at)
/*  f0d01f8:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0d01fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0200:	45020004 */ 	bc1fl	.L0f0d0214
/*  f0d0204:	46100301 */ 	sub.s	$f12,$f0,$f16
/*  f0d0208:	46001006 */ 	mov.s	$f0,$f2
/*  f0d020c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0d0210:
/*  f0d0210:	46100301 */ 	sub.s	$f12,$f0,$f16
.L0f0d0214:
/*  f0d0214:	afa30030 */ 	sw	$v1,0x30($sp)
/*  f0d0218:	0fc33c8c */ 	jal	func0f0cf230
/*  f0d021c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0d0220:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0d0224:	10400006 */ 	beqz	$v0,.L0f0d0240
/*  f0d0228:	c7a00034 */ 	lwc1	$f0,0x34($sp)
/*  f0d022c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0d0230:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0d0234:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d0238:	10000004 */ 	beqz	$zero,.L0f0d024c
/*  f0d023c:	e5e00060 */ 	swc1	$f0,0x60($t7)
.L0f0d0240:
/*  f0d0240:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d0244:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0d0248:	a3b80073 */ 	sb	$t8,0x73($sp)
.L0f0d024c:
/*  f0d024c:	10600009 */ 	beqz	$v1,.L0f0d0274
/*  f0d0250:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x284)
/*  f0d0254:	8f39a244 */ 	lw	$t9,%lo(g_Vars+0x284)($t9)
/*  f0d0258:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d025c:	44815000 */ 	mtc1	$at,$f10
/*  f0d0260:	8f220480 */ 	lw	$v0,0x480($t9)
/*  f0d0264:	c4440044 */ 	lwc1	$f4,0x44($v0)
/*  f0d0268:	46002187 */ 	neg.s	$f6,$f4
/*  f0d026c:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0d0270:	e4480044 */ 	swc1	$f8,0x44($v0)
.L0f0d0274:
/*  f0d0274:	3c028007 */ 	lui	$v0,%hi(var80070ec4)
/*  f0d0278:	24420ec4 */ 	addiu	$v0,$v0,%lo(var80070ec4)
/*  f0d027c:	90480000 */ 	lbu	$t0,0x0($v0)
/*  f0d0280:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f0d0284:	93a90073 */ 	lbu	$t1,0x73($sp)
/*  f0d0288:	15000002 */ 	bnez	$t0,.L0f0d0294
/*  f0d028c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0290:	a0490000 */ 	sb	$t1,0x0($v0)
.L0f0d0294:
/*  f0d0294:	0fc0882b */ 	jal	func0f0220ac
/*  f0d0298:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d029c:	8fa2009c */ 	lw	$v0,0x9c($sp)
/*  f0d02a0:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*  f0d02a4:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x284)
/*  f0d02a8:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0d02ac:	8d4aa244 */ 	lw	$t2,%lo(g_Vars+0x284)($t2)
/*  f0d02b0:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f0d02b4:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0d02b8:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f0d02bc:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0d02c0:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f0d02c4:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f0d02c8:	e7a60094 */ 	swc1	$f6,0x94($sp)
/*  f0d02cc:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f0d02d0:	c7a60090 */ 	lwc1	$f6,0x90($sp)
/*  f0d02d4:	46085101 */ 	sub.s	$f4,$f10,$f8
/*  f0d02d8:	46063282 */ 	mul.s	$f10,$f6,$f6
/*  f0d02dc:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f0d02e0:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f0d02e4:	46084102 */ 	mul.s	$f4,$f8,$f8
/*  f0d02e8:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f0d02ec:	8d4b0480 */ 	lw	$t3,0x480($t2)
/*  f0d02f0:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0d02f4:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f0d02f8:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f0d02fc:	e5640058 */ 	swc1	$f4,0x58($t3)
/*  f0d0300:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0d0304:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f0d0308:	03e00008 */ 	jr	$ra
/*  f0d030c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0d0310
.late_rodata
glabel var7f1ada98
.word 0x3c8efa35
glabel var7f1ada9c
.word 0x3c8efa35
.text
/*  f0d0310:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f0d0314:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f0d0318:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0d031c:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0d0320:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0d0324:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0d0328:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f0d032c:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d0330:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f0d0334:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0d0338:	0fc59585 */ 	jal	stageGetIndex
/*  f0d033c:	8f110004 */ 	lw	$s1,0x4($t8)
/*  f0d0340:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f0d0344:	00461826 */ 	xor	$v1,$v0,$a2
/*  f0d0348:	2c650001 */ 	sltiu	$a1,$v1,0x1
/*  f0d034c:	50a00007 */ 	beqzl	$a1,.L0f0d036c
/*  f0d0350:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0d0354:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0d0358:	8f2900bc */ 	lw	$t1,0xbc($t9)
/*  f0d035c:	85250028 */ 	lh	$a1,0x28($t1)
/*  f0d0360:	38aa0053 */ 	xori	$t2,$a1,0x53
/*  f0d0364:	2d450001 */ 	sltiu	$a1,$t2,0x1
/*  f0d0368:	8e030284 */ 	lw	$v1,0x284($s0)
.L0f0d036c:
/*  f0d036c:	44807000 */ 	mtc1	$zero,$f14
/*  f0d0370:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d0374:	8c6b00bc */ 	lw	$t3,0xbc($v1)
/*  f0d0378:	44815000 */ 	mtc1	$at,$f10
/*  f0d037c:	c5640008 */ 	lwc1	$f4,0x8($t3)
/*  f0d0380:	e7a400b4 */ 	swc1	$f4,0xb4($sp)
/*  f0d0384:	8c6c00bc */ 	lw	$t4,0xbc($v1)
/*  f0d0388:	c586000c */ 	lwc1	$f6,0xc($t4)
/*  f0d038c:	e7a600b8 */ 	swc1	$f6,0xb8($sp)
/*  f0d0390:	8c6d00bc */ 	lw	$t5,0xbc($v1)
/*  f0d0394:	c5a80010 */ 	lwc1	$f8,0x10($t5)
/*  f0d0398:	e7a800bc */ 	swc1	$f8,0xbc($sp)
/*  f0d039c:	ae260120 */ 	sw	$a2,0x120($s1)
/*  f0d03a0:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0d03a4:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d03a8:	a1e00034 */ 	sb	$zero,0x34($t7)
/*  f0d03ac:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0d03b0:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f0d03b4:	e72e0010 */ 	swc1	$f14,0x10($t9)
/*  f0d03b8:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0d03bc:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f0d03c0:	e54a0014 */ 	swc1	$f10,0x14($t2)
/*  f0d03c4:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0d03c8:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f0d03cc:	e58e0018 */ 	swc1	$f14,0x18($t4)
/*  f0d03d0:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0d03d4:	8dae0480 */ 	lw	$t6,0x480($t5)
/*  f0d03d8:	a1c00036 */ 	sb	$zero,0x36($t6)
/*  f0d03dc:	afa50068 */ 	sw	$a1,0x68($sp)
/*  f0d03e0:	0fc59585 */ 	jal	stageGetIndex
/*  f0d03e4:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f0d03e8:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0d03ec:	50410006 */ 	beql	$v0,$at,.L0f0d0408
/*  f0d03f0:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0d03f4:	0fc59585 */ 	jal	stageGetIndex
/*  f0d03f8:	8e0404b4 */ 	lw	$a0,0x4b4($s0)
/*  f0d03fc:	24010012 */ 	addiu	$at,$zero,0x12
/*  f0d0400:	14410006 */ 	bne	$v0,$at,.L0f0d041c
/*  f0d0404:	3c0141f0 */ 	lui	$at,0x41f0
.L0f0d0408:
/*  f0d0408:	44818000 */ 	mtc1	$at,$f16
/*  f0d040c:	3c048007 */ 	lui	$a0,%hi(var80070ed4)
/*  f0d0410:	24840ed4 */ 	addiu	$a0,$a0,%lo(var80070ed4)
/*  f0d0414:	10000006 */ 	beqz	$zero,.L0f0d0430
/*  f0d0418:	e4900000 */ 	swc1	$f16,0x0($a0)
.L0f0d041c:
/*  f0d041c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0d0420:	44819000 */ 	mtc1	$at,$f18
/*  f0d0424:	3c048007 */ 	lui	$a0,%hi(var80070ed4)
/*  f0d0428:	24840ed4 */ 	addiu	$a0,$a0,%lo(var80070ed4)
/*  f0d042c:	e4920000 */ 	swc1	$f18,0x0($a0)
.L0f0d0430:
/*  f0d0430:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0d0434:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d0438:	44811000 */ 	mtc1	$at,$f2
/*  f0d043c:	c4640078 */ 	lwc1	$f4,0x78($v1)
/*  f0d0440:	8c6f0480 */ 	lw	$t7,0x480($v1)
/*  f0d0444:	3c014334 */ 	lui	$at,0x4334
/*  f0d0448:	44819000 */ 	mtc1	$at,$f18
/*  f0d044c:	e5e4005c */ 	swc1	$f4,0x5c($t7)
/*  f0d0450:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0d0454:	3c017f1b */ 	lui	$at,%hi(var7f1ada98)
/*  f0d0458:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f0d045c:	c726005c */ 	lwc1	$f6,0x5c($t9)
/*  f0d0460:	e62600b8 */ 	swc1	$f6,0xb8($s1)
/*  f0d0464:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0d0468:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f0d046c:	c548005c */ 	lwc1	$f8,0x5c($t2)
/*  f0d0470:	e62800b4 */ 	swc1	$f8,0xb4($s1)
/*  f0d0474:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0d0478:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f0d047c:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f0d0480:	e58a0060 */ 	swc1	$f10,0x60($t4)
/*  f0d0484:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0d0488:	c4700144 */ 	lwc1	$f16,0x144($v1)
/*  f0d048c:	8c6d0480 */ 	lw	$t5,0x480($v1)
/*  f0d0490:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0d0494:	e5a4001c */ 	swc1	$f4,0x1c($t5)
/*  f0d0498:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0d049c:	8dc20480 */ 	lw	$v0,0x480($t6)
/*  f0d04a0:	c440001c */ 	lwc1	$f0,0x1c($v0)
/*  f0d04a4:	4600103e */ 	c.le.s	$f2,$f0
/*  f0d04a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d04ac:	45000006 */ 	bc1f	.L0f0d04c8
/*  f0d04b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d04b4:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f0d04b8:	e446001c */ 	swc1	$f6,0x1c($v0)
/*  f0d04bc:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0d04c0:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d04c4:	c700001c */ 	lwc1	$f0,0x1c($t8)
.L0f0d04c8:
/*  f0d04c8:	c428da98 */ 	lwc1	$f8,%lo(var7f1ada98)($at)
/*  f0d04cc:	46080302 */ 	mul.s	$f12,$f0,$f8
/*  f0d04d0:	0c0068f4 */ 	jal	cosf
/*  f0d04d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d04d8:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0d04dc:	3c017f1b */ 	lui	$at,%hi(var7f1ada9c)
/*  f0d04e0:	8f290480 */ 	lw	$t1,0x480($t9)
/*  f0d04e4:	e5200020 */ 	swc1	$f0,0x20($t1)
/*  f0d04e8:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0d04ec:	c430da9c */ 	lwc1	$f16,%lo(var7f1ada9c)($at)
/*  f0d04f0:	8d4b0480 */ 	lw	$t3,0x480($t2)
/*  f0d04f4:	c56a001c */ 	lwc1	$f10,0x1c($t3)
/*  f0d04f8:	46105302 */ 	mul.s	$f12,$f10,$f16
/*  f0d04fc:	0c0068f7 */ 	jal	sinf
/*  f0d0500:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0504:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0d0508:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0d050c:	44812000 */ 	mtc1	$at,$f4
/*  f0d0510:	8d8d0480 */ 	lw	$t5,0x480($t4)
/*  f0d0514:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f0d0518:	44807000 */ 	mtc1	$zero,$f14
/*  f0d051c:	e5a00024 */ 	swc1	$f0,0x24($t5)
/*  f0d0520:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0d0524:	c7a800b4 */ 	lwc1	$f8,0xb4($sp)
/*  f0d0528:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0d052c:	8dc20480 */ 	lw	$v0,0x480($t6)
/*  f0d0530:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d0534:	c4520024 */ 	lwc1	$f18,0x24($v0)
/*  f0d0538:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0d053c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0d0540:	44812000 */ 	mtc1	$at,$f4
/*  f0d0544:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d0548:	46064080 */ 	add.s	$f2,$f8,$f6
/*  f0d054c:	e5e20008 */ 	swc1	$f2,0x8($t7)
/*  f0d0550:	e62200c8 */ 	swc1	$f2,0xc8($s1)
/*  f0d0554:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0d0558:	8f020480 */ 	lw	$v0,0x480($t8)
/*  f0d055c:	c44a005c */ 	lwc1	$f10,0x5c($v0)
/*  f0d0560:	c4500060 */ 	lwc1	$f16,0x60($v0)
/*  f0d0564:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0d0568:	46105080 */ 	add.s	$f2,$f10,$f16
/*  f0d056c:	e722000c */ 	swc1	$f2,0xc($t9)
/*  f0d0570:	e62200cc */ 	swc1	$f2,0xcc($s1)
/*  f0d0574:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0d0578:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f0d057c:	8d220480 */ 	lw	$v0,0x480($t1)
/*  f0d0580:	c4520020 */ 	lwc1	$f18,0x20($v0)
/*  f0d0584:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f0d0588:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f0d058c:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f0d0590:	e5420010 */ 	swc1	$f2,0x10($t2)
/*  f0d0594:	e62200d0 */ 	swc1	$f2,0xd0($s1)
/*  f0d0598:	e62e00bc */ 	swc1	$f14,0xbc($s1)
/*  f0d059c:	e62e00c0 */ 	swc1	$f14,0xc0($s1)
/*  f0d05a0:	e62e00c4 */ 	swc1	$f14,0xc4($s1)
/*  f0d05a4:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0d05a8:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0d05ac:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f0d05b0:	e7aa00a8 */ 	swc1	$f10,0xa8($sp)
/*  f0d05b4:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f0d05b8:	c450005c */ 	lwc1	$f16,0x5c($v0)
/*  f0d05bc:	c4520060 */ 	lwc1	$f18,0x60($v0)
/*  f0d05c0:	e7a600b0 */ 	swc1	$f6,0xb0($sp)
/*  f0d05c4:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0d05c8:	44819000 */ 	mtc1	$at,$f18
/*  f0d05cc:	e7a400ac */ 	swc1	$f4,0xac($sp)
/*  f0d05d0:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f0d05d4:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f0d05d8:	e4480004 */ 	swc1	$f8,0x4($v0)
/*  f0d05dc:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0d05e0:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f0d05e4:	e58e0008 */ 	swc1	$f14,0x8($t4)
/*  f0d05e8:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0d05ec:	8da20480 */ 	lw	$v0,0x480($t5)
/*  f0d05f0:	c44a0020 */ 	lwc1	$f10,0x20($v0)
/*  f0d05f4:	46005407 */ 	neg.s	$f16,$f10
/*  f0d05f8:	e450000c */ 	swc1	$f16,0xc($v0)
/*  f0d05fc:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0d0600:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d0604:	e5ee0028 */ 	swc1	$f14,0x28($t7)
/*  f0d0608:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0d060c:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f0d0610:	e732002c */ 	swc1	$f18,0x2c($t9)
/*  f0d0614:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0d0618:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f0d061c:	e54e0030 */ 	swc1	$f14,0x30($t2)
/*  f0d0620:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0d0624:	8d6c0480 */ 	lw	$t4,0x480($t3)
/*  f0d0628:	e58e0040 */ 	swc1	$f14,0x40($t4)
/*  f0d062c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0d0630:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0d0634:	8dae0480 */ 	lw	$t6,0x480($t5)
/*  f0d0638:	e5ce0044 */ 	swc1	$f14,0x44($t6)
/*  f0d063c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0d0640:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d0644:	e70e0048 */ 	swc1	$f14,0x48($t8)
/*  f0d0648:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0d064c:	8f290480 */ 	lw	$t1,0x480($t9)
/*  f0d0650:	a526003a */ 	sh	$a2,0x3a($t1)
/*  f0d0654:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0d0658:	8d4b0480 */ 	lw	$t3,0x480($t2)
/*  f0d065c:	a160003c */ 	sb	$zero,0x3c($t3)
/*  f0d0660:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0d0664:	8dae0480 */ 	lw	$t6,0x480($t5)
/*  f0d0668:	a1cc003d */ 	sb	$t4,0x3d($t6)
/*  f0d066c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0d0670:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d0674:	e70e0058 */ 	swc1	$f14,0x58($t8)
/*  f0d0678:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0d067c:	8f290480 */ 	lw	$t1,0x480($t9)
/*  f0d0680:	e52e0064 */ 	swc1	$f14,0x64($t1)
/*  f0d0684:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0d0688:	8d4b0480 */ 	lw	$t3,0x480($t2)
/*  f0d068c:	a1660037 */ 	sb	$a2,0x37($t3)
/*  f0d0690:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0d0694:	8dac0480 */ 	lw	$t4,0x480($t5)
/*  f0d0698:	a1800039 */ 	sb	$zero,0x39($t4)
/*  f0d069c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0d06a0:	8dc20480 */ 	lw	$v0,0x480($t6)
/*  f0d06a4:	804f0039 */ 	lb	$t7,0x39($v0)
/*  f0d06a8:	a04f0038 */ 	sb	$t7,0x38($v0)
/*  f0d06ac:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0d06b0:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f0d06b4:	a3200068 */ 	sb	$zero,0x68($t9)
/*  f0d06b8:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0d06bc:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f0d06c0:	a140006a */ 	sb	$zero,0x6a($t2)
/*  f0d06c4:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0d06c8:	8d6d0480 */ 	lw	$t5,0x480($t3)
/*  f0d06cc:	e5ae006c */ 	swc1	$f14,0x6c($t5)
/*  f0d06d0:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0d06d4:	8d8e0480 */ 	lw	$t6,0x480($t4)
/*  f0d06d8:	e5ce0070 */ 	swc1	$f14,0x70($t6)
/*  f0d06dc:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0d06e0:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d06e4:	e70e0074 */ 	swc1	$f14,0x74($t8)
/*  f0d06e8:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0d06ec:	8f290480 */ 	lw	$t1,0x480($t9)
/*  f0d06f0:	e52e0078 */ 	swc1	$f14,0x78($t1)
/*  f0d06f4:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0d06f8:	8d4b0480 */ 	lw	$t3,0x480($t2)
/*  f0d06fc:	e56e007c */ 	swc1	$f14,0x7c($t3)
/*  f0d0700:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0d0704:	0fc30795 */ 	jal	func0f0c1e54
/*  f0d0708:	8da400bc */ 	lw	$a0,0xbc($t5)
/*  f0d070c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0d0710:	5580000f */ 	bnezl	$t4,.L0f0d0750
/*  f0d0714:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0d0718:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0d071c:	240f000f */ 	addiu	$t7,$zero,0xf
/*  f0d0720:	27a400a8 */ 	addiu	$a0,$sp,0xa8
/*  f0d0724:	8c6e0480 */ 	lw	$t6,0x480($v1)
/*  f0d0728:	8c6500bc */ 	lw	$a1,0xbc($v1)
/*  f0d072c:	2407003f */ 	addiu	$a3,$zero,0x3f
/*  f0d0730:	8dc60000 */ 	lw	$a2,0x0($t6)
/*  f0d0734:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d0738:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0d073c:	0c00b764 */ 	jal	func0002dd90
/*  f0d0740:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0d0744:	1440002d */ 	bnez	$v0,.L0f0d07fc
/*  f0d0748:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d074c:	8e180284 */ 	lw	$t8,0x284($s0)
.L0f0d0750:
/*  f0d0750:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d0754:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f0d0758:	a3200035 */ 	sb	$zero,0x35($t9)
/*  f0d075c:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0d0760:	c7a200b4 */ 	lwc1	$f2,0xb4($sp)
/*  f0d0764:	8d2a0480 */ 	lw	$t2,0x480($t1)
/*  f0d0768:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f0d076c:	e5620008 */ 	swc1	$f2,0x8($t3)
/*  f0d0770:	e62200c8 */ 	swc1	$f2,0xc8($s1)
/*  f0d0774:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0d0778:	8da20480 */ 	lw	$v0,0x480($t5)
/*  f0d077c:	c444005c */ 	lwc1	$f4,0x5c($v0)
/*  f0d0780:	c4460060 */ 	lwc1	$f6,0x60($v0)
/*  f0d0784:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f0d0788:	46062080 */ 	add.s	$f2,$f4,$f6
/*  f0d078c:	e582000c */ 	swc1	$f2,0xc($t4)
/*  f0d0790:	e62200cc */ 	swc1	$f2,0xcc($s1)
/*  f0d0794:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0d0798:	c7a200bc */ 	lwc1	$f2,0xbc($sp)
/*  f0d079c:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d07a0:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0d07a4:	e7020010 */ 	swc1	$f2,0x10($t8)
/*  f0d07a8:	e62200d0 */ 	swc1	$f2,0xd0($s1)
/*  f0d07ac:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0d07b0:	8f290480 */ 	lw	$t1,0x480($t9)
/*  f0d07b4:	0fc1905e */ 	jal	func0f064178
/*  f0d07b8:	8d240000 */ 	lw	$a0,0x0($t1)
/*  f0d07bc:	0fc5b9f1 */ 	jal	langGet
/*  f0d07c0:	240458da */ 	addiu	$a0,$zero,0x58da
/*  f0d07c4:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f0d07c8:	0fc28857 */ 	jal	weaponGetName
/*  f0d07cc:	2404002e */ 	addiu	$a0,$zero,0x2e
/*  f0d07d0:	3c057f1b */ 	lui	$a1,%hi(var7f1ada78)
/*  f0d07d4:	24a5da78 */ 	addiu	$a1,$a1,%lo(var7f1ada78)
/*  f0d07d8:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0d07dc:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f0d07e0:	0c004dad */ 	jal	sprintf
/*  f0d07e4:	00403825 */ 	or	$a3,$v0,$zero
/*  f0d07e8:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0d07ec:	0fc377c7 */ 	jal	hudmsgCreateViaPreset
/*  f0d07f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d07f4:	10000033 */ 	beqz	$zero,.L0f0d08c4
/*  f0d07f8:	afa000a0 */ 	sw	$zero,0xa0($sp)
.L0f0d07fc:
/*  f0d07fc:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0d0800:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0d0804:	44810000 */ 	mtc1	$at,$f0
/*  f0d0808:	8d6d0480 */ 	lw	$t5,0x480($t3)
/*  f0d080c:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f0d0810:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0d0814:	a1aa0035 */ 	sb	$t2,0x35($t5)
/*  f0d0818:	240effff */ 	addiu	$t6,$zero,-1
/*  f0d081c:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0d0820:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0d0824:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0d0828:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0d082c:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f0d0830:	240580ab */ 	addiu	$a1,$zero,-32597
/*  f0d0834:	00003025 */ 	or	$a2,$zero,$zero
/*  f0d0838:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0d083c:	0c004241 */ 	jal	func00010904
/*  f0d0840:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f0d0844:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d0848:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*  f0d084c:	8e390018 */ 	lw	$t9,0x18($s1)
/*  f0d0850:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d0854:	44810000 */ 	mtc1	$at,$f0
/*  f0d0858:	2401fbff */ 	addiu	$at,$zero,-1025
/*  f0d085c:	03214824 */ 	and	$t1,$t9,$at
/*  f0d0860:	2401ffef */ 	addiu	$at,$zero,-17
/*  f0d0864:	ae290018 */ 	sw	$t1,0x18($s1)
/*  f0d0868:	01215024 */ 	and	$t2,$t1,$at
/*  f0d086c:	ae2a0018 */ 	sw	$t2,0x18($s1)
/*  f0d0870:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0d0874:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0d0878:	240effff */ 	addiu	$t6,$zero,-1
/*  f0d087c:	8dac0480 */ 	lw	$t4,0x480($t5)
/*  f0d0880:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0d0884:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d0888:	8d850000 */ 	lw	$a1,0x0($t4)
/*  f0d088c:	afb8002c */ 	sw	$t8,0x2c($sp)
/*  f0d0890:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0d0894:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0d0898:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0d089c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0d08a0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0d08a4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0d08a8:	240601bd */ 	addiu	$a2,$zero,0x1bd
/*  f0d08ac:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0d08b0:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0d08b4:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0d08b8:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0d08bc:	0fc24e7e */ 	jal	func0f0939f8
/*  f0d08c0:	e7a00024 */ 	swc1	$f0,0x24($sp)
.L0f0d08c4:
/*  f0d08c4:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0d08c8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0d08cc:	0fc30795 */ 	jal	func0f0c1e54
/*  f0d08d0:	8f2400bc */ 	lw	$a0,0xbc($t9)
/*  f0d08d4:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0d08d8:	8d2b0480 */ 	lw	$t3,0x480($t1)
/*  f0d08dc:	0fc19711 */ 	jal	func0f065c44
/*  f0d08e0:	8d640000 */ 	lw	$a0,0x0($t3)
/*  f0d08e4:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0d08e8:	8c6a0480 */ 	lw	$t2,0x480($v1)
/*  f0d08ec:	8c6800bc */ 	lw	$t0,0xbc($v1)
/*  f0d08f0:	8d420000 */ 	lw	$v0,0x0($t2)
/*  f0d08f4:	25040008 */ 	addiu	$a0,$t0,0x8
/*  f0d08f8:	25050028 */ 	addiu	$a1,$t0,0x28
/*  f0d08fc:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f0d0900:	0fc1979d */ 	jal	func0f065e74
/*  f0d0904:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f0d0908:	0fc0882b */ 	jal	func0f0220ac
/*  f0d090c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0d0910:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0d0914:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0d0918:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f0d091c:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f0d0920:	03e00008 */ 	jr	$ra
/*  f0d0924:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);

GLOBAL_ASM(
glabel func0f0d0928
.late_rodata
glabel var7f1adaa0
.word 0x3f75c28f
glabel var7f1adaa4
.word 0x3e99999a
glabel var7f1adaa8
.word 0x3c4ccccd
glabel var7f1adaac
.word 0x3c4ccccd
glabel var7f1adab0
.word 0x3f75c28f
glabel var7f1adab4
.word 0x3c8efa35
glabel var7f1adab8
.word 0x3c8efa35
glabel var7f1adabc
.word 0x3c8efa35
glabel var7f1adac0
.word 0x3c8efa35
glabel var7f1adac4
.word 0x3d23d70a
glabel var7f1adac8
.word 0x3d23d70a
glabel var7f1adacc
.word 0x3c8efa35
glabel var7f1adad0
.word 0x3c8efa35
glabel var7f1adad4
.word 0x3e19999a
glabel var7f1adad8
.word 0x3e19999a
glabel var7f1adadc
.word 0x42b48000
glabel var7f1adae0
.word 0x3dcccccd
glabel var7f1adae4
.word 0x3ccccccd
glabel var7f1adae8
.word func0f0d0928+0x1184 # f0d1aac
glabel var7f1adaec
.word func0f0d0928+0x1280 # f0d1ba8
glabel var7f1adaf0
.word func0f0d0928+0x122c # f0d1b54
glabel var7f1adaf4
.word func0f0d0928+0x12d4 # f0d1bfc
glabel var7f1adaf8
.word func0f0d0928+0x11d8 # f0d1b00
glabel var7f1adafc
.word 0x40c907a9
glabel var7f1adb00
.word 0x461c4000
.text
/*  f0d0928:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d092c:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d0930:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d0934:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f0d0938:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0d093c:	afa400e8 */ 	sw	$a0,0xe8($sp)
/*  f0d0940:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d0944:	3c017f1b */ 	lui	$at,%hi(var7f1adaa0)
/*  f0d0948:	c424daa0 */ 	lwc1	$f4,%lo(var7f1adaa0)($at)
/*  f0d094c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0d0950:	8d2e0288 */ 	lw	$t6,0x288($t1)
/*  f0d0954:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f0d0958:	e7a400e0 */ 	swc1	$f4,0xe0($sp)
/*  f0d095c:	afb900e4 */ 	sw	$t9,0xe4($sp)
/*  f0d0960:	0fc549d2 */ 	jal	optionsGetUnk45
/*  f0d0964:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0d0968:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0d096c:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0d0970:	a3a200c3 */ 	sb	$v0,0xc3($sp)
/*  f0d0974:	0c005384 */ 	jal	func00014e10
/*  f0d0978:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0d097c:	83a400c3 */ 	lb	$a0,0xc3($sp)
/*  f0d0980:	0c0053ae */ 	jal	func00014eb8
/*  f0d0984:	a3a200c2 */ 	sb	$v0,0xc2($sp)
/*  f0d0988:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f0d098c:	00023e00 */ 	sll	$a3,$v0,0x18
/*  f0d0990:	0007ce03 */ 	sra	$t9,$a3,0x18
/*  f0d0994:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d0998:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d099c:	03203825 */ 	or	$a3,$t9,$zero
/*  f0d09a0:	11c0000c */ 	beqz	$t6,.L0f0d09d4
/*  f0d09a4:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d09a8:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d09ac:	83a400c3 */ 	lb	$a0,0xc3($sp)
/*  f0d09b0:	3405ffff */ 	dli	$a1,0xffff
/*  f0d09b4:	0c0053d8 */ 	jal	func00014f60
/*  f0d09b8:	a3b900c0 */ 	sb	$t9,0xc0($sp)
/*  f0d09bc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d09c0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d09c4:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d09c8:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d09cc:	10000002 */ 	beqz	$zero,.L0f0d09d8
/*  f0d09d0:	3048ffff */ 	andi	$t0,$v0,0xffff
.L0f0d09d4:
/*  f0d09d4:	00004025 */ 	or	$t0,$zero,$zero
.L0f0d09d8:
/*  f0d09d8:	8d380288 */ 	lw	$t8,0x288($t1)
/*  f0d09dc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d09e0:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f0d09e4:	8f040070 */ 	lw	$a0,0x70($t8)
/*  f0d09e8:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d09ec:	a7a800bc */ 	sh	$t0,0xbc($sp)
/*  f0d09f0:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0d09f4:	a3a700c0 */ 	sb	$a3,0xc0($sp)
/*  f0d09f8:	44808000 */ 	mtc1	$zero,$f16
/*  f0d09fc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d0a00:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d0a04:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d0a08:	e7b0009c */ 	swc1	$f16,0x9c($sp)
/*  f0d0a0c:	e7b00098 */ 	swc1	$f16,0x98($sp)
/*  f0d0a10:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*  f0d0a14:	8db90480 */ 	lw	$t9,0x480($t5)
/*  f0d0a18:	28410004 */ 	slti	$at,$v0,0x4
/*  f0d0a1c:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d0a20:	c7260028 */ 	lwc1	$f6,0x28($t9)
/*  f0d0a24:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f0d0a28:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d0a2c:	00405825 */ 	or	$t3,$v0,$zero
/*  f0d0a30:	14200035 */ 	bnez	$at,.L0f0d0b08
/*  f0d0a34:	e7a60088 */ 	swc1	$f6,0x88($sp)
/*  f0d0a38:	8d2e0288 */ 	lw	$t6,0x288($t1)
/*  f0d0a3c:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0d0a40:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d0a44:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0d0a48:	a7a800bc */ 	sh	$t0,0xbc($sp)
/*  f0d0a4c:	0fc549d9 */ 	jal	optionsGetUnk46
/*  f0d0a50:	a3a700c0 */ 	sb	$a3,0xc0($sp)
/*  f0d0a54:	00021e00 */ 	sll	$v1,$v0,0x18
/*  f0d0a58:	00037e03 */ 	sra	$t7,$v1,0x18
/*  f0d0a5c:	000f2600 */ 	sll	$a0,$t7,0x18
/*  f0d0a60:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0d0a64:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f0d0a68:	0c005384 */ 	jal	func00014e10
/*  f0d0a6c:	03002025 */ 	or	$a0,$t8,$zero
/*  f0d0a70:	83a40077 */ 	lb	$a0,0x77($sp)
/*  f0d0a74:	a3a200c1 */ 	sb	$v0,0xc1($sp)
/*  f0d0a78:	0c0053ae */ 	jal	func00014eb8
/*  f0d0a7c:	afa4003c */ 	sw	$a0,0x3c($sp)
/*  f0d0a80:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0d0a84:	00023600 */ 	sll	$a2,$v0,0x18
/*  f0d0a88:	00067603 */ 	sra	$t6,$a2,0x18
/*  f0d0a8c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d0a90:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d0a94:	01c03025 */ 	or	$a2,$t6,$zero
/*  f0d0a98:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0d0a9c:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d0aa0:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f0d0aa4:	83aa00c1 */ 	lb	$t2,0xc1($sp)
/*  f0d0aa8:	8fab00b0 */ 	lw	$t3,0xb0($sp)
/*  f0d0aac:	11e00013 */ 	beqz	$t7,.L0f0d0afc
/*  f0d0ab0:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d0ab4:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d0ab8:	3405ffff */ 	dli	$a1,0xffff
/*  f0d0abc:	a3ae00bf */ 	sb	$t6,0xbf($sp)
/*  f0d0ac0:	a3a700c0 */ 	sb	$a3,0xc0($sp)
/*  f0d0ac4:	a7a800bc */ 	sh	$t0,0xbc($sp)
/*  f0d0ac8:	a3aa00c1 */ 	sb	$t2,0xc1($sp)
/*  f0d0acc:	0c0053d8 */ 	jal	func00014f60
/*  f0d0ad0:	afab00b0 */ 	sw	$t3,0xb0($sp)
/*  f0d0ad4:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d0ad8:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d0adc:	83a600bf */ 	lb	$a2,0xbf($sp)
/*  f0d0ae0:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d0ae4:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f0d0ae8:	83aa00c1 */ 	lb	$t2,0xc1($sp)
/*  f0d0aec:	8fab00b0 */ 	lw	$t3,0xb0($sp)
/*  f0d0af0:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d0af4:	10000002 */ 	beqz	$zero,.L0f0d0b00
/*  f0d0af8:	3045ffff */ 	andi	$a1,$v0,0xffff
.L0f0d0afc:
/*  f0d0afc:	00002825 */ 	or	$a1,$zero,$zero
.L0f0d0b00:
/*  f0d0b00:	10000008 */ 	beqz	$zero,.L0f0d0b24
/*  f0d0b04:	8d2d0284 */ 	lw	$t5,0x284($t1)
.L0f0d0b08:
/*  f0d0b08:	001f5600 */ 	sll	$t2,$ra,0x18
/*  f0d0b0c:	00073600 */ 	sll	$a2,$a3,0x18
/*  f0d0b10:	000ac603 */ 	sra	$t8,$t2,0x18
/*  f0d0b14:	0006ce03 */ 	sra	$t9,$a2,0x18
/*  f0d0b18:	03005025 */ 	or	$t2,$t8,$zero
/*  f0d0b1c:	03203025 */ 	or	$a2,$t9,$zero
/*  f0d0b20:	3105ffff */ 	andi	$a1,$t0,0xffff
.L0f0d0b24:
/*  f0d0b24:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0d0b28:	11610002 */ 	beq	$t3,$at,.L0f0d0b34
/*  f0d0b2c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0d0b30:	15610009 */ 	bne	$t3,$at,.L0f0d0b58
.L0f0d0b34:
/*  f0d0b34:	310e8000 */ 	andi	$t6,$t0,0x8000
/*  f0d0b38:	310f0010 */ 	andi	$t7,$t0,0x10
/*  f0d0b3c:	31184000 */ 	andi	$t8,$t0,0x4000
/*  f0d0b40:	01002025 */ 	or	$a0,$t0,$zero
/*  f0d0b44:	310c2000 */ 	andi	$t4,$t0,0x2000
/*  f0d0b48:	afae00a8 */ 	sw	$t6,0xa8($sp)
/*  f0d0b4c:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f0d0b50:	1000001e */ 	beqz	$zero,.L0f0d0bcc
/*  f0d0b54:	afb800a0 */ 	sw	$t8,0xa0($sp)
.L0f0d0b58:
/*  f0d0b58:	29610004 */ 	slti	$at,$t3,0x4
/*  f0d0b5c:	10200009 */ 	beqz	$at,.L0f0d0b84
/*  f0d0b60:	01002025 */ 	or	$a0,$t0,$zero
/*  f0d0b64:	31192000 */ 	andi	$t9,$t0,0x2000
/*  f0d0b68:	310e8000 */ 	andi	$t6,$t0,0x8000
/*  f0d0b6c:	310f4000 */ 	andi	$t7,$t0,0x4000
/*  f0d0b70:	310c0030 */ 	andi	$t4,$t0,0x30
/*  f0d0b74:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0d0b78:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f0d0b7c:	10000013 */ 	beqz	$zero,.L0f0d0bcc
/*  f0d0b80:	afaf00a0 */ 	sw	$t7,0xa0($sp)
.L0f0d0b84:
/*  f0d0b84:	29610006 */ 	slti	$at,$t3,0x6
/*  f0d0b88:	14200007 */ 	bnez	$at,.L0f0d0ba8
/*  f0d0b8c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0d0b90:	30b82000 */ 	andi	$t8,$a1,0x2000
/*  f0d0b94:	01002025 */ 	or	$a0,$t0,$zero
/*  f0d0b98:	310c2000 */ 	andi	$t4,$t0,0x2000
/*  f0d0b9c:	afb800a8 */ 	sw	$t8,0xa8($sp)
/*  f0d0ba0:	10000005 */ 	beqz	$zero,.L0f0d0bb8
/*  f0d0ba4:	00a01825 */ 	or	$v1,$a1,$zero
.L0f0d0ba8:
/*  f0d0ba8:	31192000 */ 	andi	$t9,$t0,0x2000
/*  f0d0bac:	30ac2000 */ 	andi	$t4,$a1,0x2000
/*  f0d0bb0:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0d0bb4:	01002025 */ 	or	$a0,$t0,$zero
.L0f0d0bb8:
/*  f0d0bb8:	00831025 */ 	or	$v0,$a0,$v1
/*  f0d0bbc:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0d0bc0:	304f4000 */ 	andi	$t7,$v0,0x4000
/*  f0d0bc4:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f0d0bc8:	afaf00a0 */ 	sw	$t7,0xa0($sp)
.L0f0d0bcc:
/*  f0d0bcc:	2be1fff7 */ 	slti	$at,$ra,-9
/*  f0d0bd0:	14200004 */ 	bnez	$at,.L0f0d0be4
/*  f0d0bd4:	2be1000a */ 	slti	$at,$ra,0xa
/*  f0d0bd8:	50200003 */ 	beqzl	$at,.L0f0d0be8
/*  f0d0bdc:	2be1fff7 */ 	slti	$at,$ra,-9
/*  f0d0be0:	0000f825 */ 	or	$ra,$zero,$zero
.L0f0d0be4:
/*  f0d0be4:	2be1fff7 */ 	slti	$at,$ra,-9
.L0f0d0be8:
/*  f0d0be8:	50200005 */ 	beqzl	$at,.L0f0d0c00
/*  f0d0bec:	2be1000a */ 	slti	$at,$ra,0xa
/*  f0d0bf0:	27ff000a */ 	addiu	$ra,$ra,0xa
/*  f0d0bf4:	001fc600 */ 	sll	$t8,$ra,0x18
/*  f0d0bf8:	0018fe03 */ 	sra	$ra,$t8,0x18
/*  f0d0bfc:	2be1000a */ 	slti	$at,$ra,0xa
.L0f0d0c00:
/*  f0d0c00:	54200005 */ 	bnezl	$at,.L0f0d0c18
/*  f0d0c04:	2941fff7 */ 	slti	$at,$t2,-9
/*  f0d0c08:	27fffff6 */ 	addiu	$ra,$ra,-10
/*  f0d0c0c:	001f7600 */ 	sll	$t6,$ra,0x18
/*  f0d0c10:	000efe03 */ 	sra	$ra,$t6,0x18
/*  f0d0c14:	2941fff7 */ 	slti	$at,$t2,-9
.L0f0d0c18:
/*  f0d0c18:	14200004 */ 	bnez	$at,.L0f0d0c2c
/*  f0d0c1c:	2941000a */ 	slti	$at,$t2,0xa
/*  f0d0c20:	50200003 */ 	beqzl	$at,.L0f0d0c30
/*  f0d0c24:	2941fff7 */ 	slti	$at,$t2,-9
/*  f0d0c28:	00005025 */ 	or	$t2,$zero,$zero
.L0f0d0c2c:
/*  f0d0c2c:	2941fff7 */ 	slti	$at,$t2,-9
.L0f0d0c30:
/*  f0d0c30:	50200005 */ 	beqzl	$at,.L0f0d0c48
/*  f0d0c34:	2941000a */ 	slti	$at,$t2,0xa
/*  f0d0c38:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f0d0c3c:	000ac600 */ 	sll	$t8,$t2,0x18
/*  f0d0c40:	00185603 */ 	sra	$t2,$t8,0x18
/*  f0d0c44:	2941000a */ 	slti	$at,$t2,0xa
.L0f0d0c48:
/*  f0d0c48:	54200005 */ 	bnezl	$at,.L0f0d0c60
/*  f0d0c4c:	28e1ffed */ 	slti	$at,$a3,-19
/*  f0d0c50:	254afff6 */ 	addiu	$t2,$t2,-10
/*  f0d0c54:	000a7600 */ 	sll	$t6,$t2,0x18
/*  f0d0c58:	000e5603 */ 	sra	$t2,$t6,0x18
/*  f0d0c5c:	28e1ffed */ 	slti	$at,$a3,-19
.L0f0d0c60:
/*  f0d0c60:	14200004 */ 	bnez	$at,.L0f0d0c74
/*  f0d0c64:	28e10014 */ 	slti	$at,$a3,0x14
/*  f0d0c68:	50200003 */ 	beqzl	$at,.L0f0d0c78
/*  f0d0c6c:	28e1ffed */ 	slti	$at,$a3,-19
/*  f0d0c70:	00003825 */ 	or	$a3,$zero,$zero
.L0f0d0c74:
/*  f0d0c74:	28e1ffed */ 	slti	$at,$a3,-19
.L0f0d0c78:
/*  f0d0c78:	50200005 */ 	beqzl	$at,.L0f0d0c90
/*  f0d0c7c:	28e10014 */ 	slti	$at,$a3,0x14
/*  f0d0c80:	24e70014 */ 	addiu	$a3,$a3,0x14
/*  f0d0c84:	0007c600 */ 	sll	$t8,$a3,0x18
/*  f0d0c88:	00183e03 */ 	sra	$a3,$t8,0x18
/*  f0d0c8c:	28e10014 */ 	slti	$at,$a3,0x14
.L0f0d0c90:
/*  f0d0c90:	54200005 */ 	bnezl	$at,.L0f0d0ca8
/*  f0d0c94:	44874000 */ 	mtc1	$a3,$f8
/*  f0d0c98:	24e7ffec */ 	addiu	$a3,$a3,-20
/*  f0d0c9c:	00077600 */ 	sll	$t6,$a3,0x18
/*  f0d0ca0:	000e3e03 */ 	sra	$a3,$t6,0x18
/*  f0d0ca4:	44874000 */ 	mtc1	$a3,$f8
.L0f0d0ca8:
/*  f0d0ca8:	28c1ffed */ 	slti	$at,$a2,-19
/*  f0d0cac:	14200005 */ 	bnez	$at,.L0f0d0cc4
/*  f0d0cb0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d0cb4:	28c10014 */ 	slti	$at,$a2,0x14
/*  f0d0cb8:	50200003 */ 	beqzl	$at,.L0f0d0cc8
/*  f0d0cbc:	28c1ffed */ 	slti	$at,$a2,-19
/*  f0d0cc0:	00003025 */ 	or	$a2,$zero,$zero
.L0f0d0cc4:
/*  f0d0cc4:	28c1ffed */ 	slti	$at,$a2,-19
.L0f0d0cc8:
/*  f0d0cc8:	50200005 */ 	beqzl	$at,.L0f0d0ce0
/*  f0d0ccc:	28c10014 */ 	slti	$at,$a2,0x14
/*  f0d0cd0:	24c60014 */ 	addiu	$a2,$a2,0x14
/*  f0d0cd4:	0006c600 */ 	sll	$t8,$a2,0x18
/*  f0d0cd8:	00183603 */ 	sra	$a2,$t8,0x18
/*  f0d0cdc:	28c10014 */ 	slti	$at,$a2,0x14
.L0f0d0ce0:
/*  f0d0ce0:	14200004 */ 	bnez	$at,.L0f0d0cf4
/*  f0d0ce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0ce8:	24c6ffec */ 	addiu	$a2,$a2,-20
/*  f0d0cec:	00067600 */ 	sll	$t6,$a2,0x18
/*  f0d0cf0:	000e3603 */ 	sra	$a2,$t6,0x18
.L0f0d0cf4:
/*  f0d0cf4:	3c017f1b */ 	lui	$at,%hi(var7f1adaa4)
/*  f0d0cf8:	c420daa4 */ 	lwc1	$f0,%lo(var7f1adaa4)($at)
/*  f0d0cfc:	44864000 */ 	mtc1	$a2,$f8
/*  f0d0d00:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0d0d04:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d0d08:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d0d0c:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0d0d10:	44073000 */ 	mfc1	$a3,$f6
/*  f0d0d14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0d18:	0007ce00 */ 	sll	$t9,$a3,0x18
/*  f0d0d1c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d0d20:	00193e03 */ 	sra	$a3,$t9,0x18
/*  f0d0d24:	44063000 */ 	mfc1	$a2,$f6
/*  f0d0d28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0d2c:	0006c600 */ 	sll	$t8,$a2,0x18
/*  f0d0d30:	11600004 */ 	beqz	$t3,.L0f0d0d44
/*  f0d0d34:	00183603 */ 	sra	$a2,$t8,0x18
/*  f0d0d38:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0d0d3c:	5561002b */ 	bnel	$t3,$at,.L0f0d0dec
/*  f0d0d40:	29610004 */ 	slti	$at,$t3,0x4
.L0f0d0d44:
/*  f0d0d44:	11800006 */ 	beqz	$t4,.L0f0d0d60
/*  f0d0d48:	308e0808 */ 	andi	$t6,$a0,0x808
/*  f0d0d4c:	44874000 */ 	mtc1	$a3,$f8
/*  f0d0d50:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f0d0d54:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d0d58:	10000005 */ 	beqz	$zero,.L0f0d0d70
/*  f0d0d5c:	e7aa0098 */ 	swc1	$f10,0x98($sp)
.L0f0d0d60:
/*  f0d0d60:	44872000 */ 	mtc1	$a3,$f4
/*  f0d0d64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0d68:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d0d6c:	e7a6009c */ 	swc1	$f6,0x9c($sp)
.L0f0d0d70:
/*  f0d0d70:	11c00003 */ 	beqz	$t6,.L0f0d0d80
/*  f0d0d74:	308f0404 */ 	andi	$t7,$a0,0x404
/*  f0d0d78:	10000002 */ 	beqz	$zero,.L0f0d0d84
/*  f0d0d7c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0d0d80:
/*  f0d0d80:	00001825 */ 	or	$v1,$zero,$zero
.L0f0d0d84:
/*  f0d0d84:	11e00003 */ 	beqz	$t7,.L0f0d0d94
/*  f0d0d88:	308e0202 */ 	andi	$t6,$a0,0x202
/*  f0d0d8c:	10000002 */ 	beqz	$zero,.L0f0d0d98
/*  f0d0d90:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0d0d94:
/*  f0d0d94:	00001025 */ 	or	$v0,$zero,$zero
.L0f0d0d98:
/*  f0d0d98:	0062c023 */ 	subu	$t8,$v1,$v0
/*  f0d0d9c:	44984000 */ 	mtc1	$t8,$f8
/*  f0d0da0:	30990101 */ 	andi	$t9,$a0,0x101
/*  f0d0da4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d0da8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d0dac:	00001825 */ 	or	$v1,$zero,$zero
/*  f0d0db0:	13200003 */ 	beqz	$t9,.L0f0d0dc0
/*  f0d0db4:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f0d0db8:	10000001 */ 	beqz	$zero,.L0f0d0dc0
/*  f0d0dbc:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0d0dc0:
/*  f0d0dc0:	11c00003 */ 	beqz	$t6,.L0f0d0dd0
/*  f0d0dc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0dc8:	10000001 */ 	beqz	$zero,.L0f0d0dd0
/*  f0d0dcc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0d0dd0:
/*  f0d0dd0:	00627823 */ 	subu	$t7,$v1,$v0
/*  f0d0dd4:	448f2000 */ 	mtc1	$t7,$f4
/*  f0d0dd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0ddc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d0de0:	10000063 */ 	beqz	$zero,.L0f0d0f70
/*  f0d0de4:	e7a60094 */ 	swc1	$f6,0x94($sp)
/*  f0d0de8:	29610004 */ 	slti	$at,$t3,0x4
.L0f0d0dec:
/*  f0d0dec:	1020002e */ 	beqz	$at,.L0f0d0ea8
/*  f0d0df0:	308e0101 */ 	andi	$t6,$a0,0x101
/*  f0d0df4:	11800006 */ 	beqz	$t4,.L0f0d0e10
/*  f0d0df8:	308f0202 */ 	andi	$t7,$a0,0x202
/*  f0d0dfc:	44874000 */ 	mtc1	$a3,$f8
/*  f0d0e00:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f0d0e04:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d0e08:	10000019 */ 	beqz	$zero,.L0f0d0e70
/*  f0d0e0c:	e7aa0098 */ 	swc1	$f10,0x98($sp)
.L0f0d0e10:
/*  f0d0e10:	44872000 */ 	mtc1	$a3,$f4
/*  f0d0e14:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d0e18:	44814000 */ 	mtc1	$at,$f8
/*  f0d0e1c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d0e20:	30980808 */ 	andi	$t8,$a0,0x808
/*  f0d0e24:	3c0141c0 */ 	lui	$at,0x41c0
/*  f0d0e28:	30990404 */ 	andi	$t9,$a0,0x404
/*  f0d0e2c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0d0e30:	13000004 */ 	beqz	$t8,.L0f0d0e44
/*  f0d0e34:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f0d0e38:	44810000 */ 	mtc1	$at,$f0
/*  f0d0e3c:	10000003 */ 	beqz	$zero,.L0f0d0e4c
/*  f0d0e40:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0d0e44:
/*  f0d0e44:	44800000 */ 	mtc1	$zero,$f0
/*  f0d0e48:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0d0e4c:
/*  f0d0e4c:	13200004 */ 	beqz	$t9,.L0f0d0e60
/*  f0d0e50:	3c0141c0 */ 	lui	$at,0x41c0
/*  f0d0e54:	44811000 */ 	mtc1	$at,$f2
/*  f0d0e58:	10000004 */ 	beqz	$zero,.L0f0d0e6c
/*  f0d0e5c:	46020101 */ 	sub.s	$f4,$f0,$f2
.L0f0d0e60:
/*  f0d0e60:	44801000 */ 	mtc1	$zero,$f2
/*  f0d0e64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0e68:	46020101 */ 	sub.s	$f4,$f0,$f2
.L0f0d0e6c:
/*  f0d0e6c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
.L0f0d0e70:
/*  f0d0e70:	11c00003 */ 	beqz	$t6,.L0f0d0e80
/*  f0d0e74:	00001825 */ 	or	$v1,$zero,$zero
/*  f0d0e78:	10000001 */ 	beqz	$zero,.L0f0d0e80
/*  f0d0e7c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0d0e80:
/*  f0d0e80:	11e00003 */ 	beqz	$t7,.L0f0d0e90
/*  f0d0e84:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d0e88:	10000001 */ 	beqz	$zero,.L0f0d0e90
/*  f0d0e8c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0d0e90:
/*  f0d0e90:	0062c023 */ 	subu	$t8,$v1,$v0
/*  f0d0e94:	44983000 */ 	mtc1	$t8,$f6
/*  f0d0e98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0e9c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d0ea0:	10000033 */ 	beqz	$zero,.L0f0d0f70
/*  f0d0ea4:	e7a80094 */ 	swc1	$f8,0x94($sp)
.L0f0d0ea8:
/*  f0d0ea8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0d0eac:	11610003 */ 	beq	$t3,$at,.L0f0d0ebc
/*  f0d0eb0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0d0eb4:	15610018 */ 	bne	$t3,$at,.L0f0d0f18
/*  f0d0eb8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0d0ebc:
/*  f0d0ebc:	44875000 */ 	mtc1	$a3,$f10
/*  f0d0ec0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0ec4:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d0ec8:	11800006 */ 	beqz	$t4,.L0f0d0ee4
/*  f0d0ecc:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f0d0ed0:	44863000 */ 	mtc1	$a2,$f6
/*  f0d0ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0ed8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d0edc:	10000007 */ 	beqz	$zero,.L0f0d0efc
/*  f0d0ee0:	e7a80098 */ 	swc1	$f8,0x98($sp)
.L0f0d0ee4:
/*  f0d0ee4:	44865000 */ 	mtc1	$a2,$f10
/*  f0d0ee8:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d0eec:	44813000 */ 	mtc1	$at,$f6
/*  f0d0ef0:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d0ef4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d0ef8:	e7a8008c */ 	swc1	$f8,0x8c($sp)
.L0f0d0efc:
/*  f0d0efc:	448a5000 */ 	mtc1	$t2,$f10
/*  f0d0f00:	3c017f1b */ 	lui	$at,%hi(var7f1adaa8)
/*  f0d0f04:	c426daa8 */ 	lwc1	$f6,%lo(var7f1adaa8)($at)
/*  f0d0f08:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d0f0c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d0f10:	10000017 */ 	beqz	$zero,.L0f0d0f70
/*  f0d0f14:	e7a80094 */ 	swc1	$f8,0x94($sp)
.L0f0d0f18:
/*  f0d0f18:	51800007 */ 	beqzl	$t4,.L0f0d0f38
/*  f0d0f1c:	44873000 */ 	mtc1	$a3,$f6
/*  f0d0f20:	44875000 */ 	mtc1	$a3,$f10
/*  f0d0f24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0f28:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d0f2c:	10000007 */ 	beqz	$zero,.L0f0d0f4c
/*  f0d0f30:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f0d0f34:	44873000 */ 	mtc1	$a3,$f6
.L0f0d0f38:
/*  f0d0f38:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d0f3c:	44815000 */ 	mtc1	$at,$f10
/*  f0d0f40:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d0f44:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0d0f48:	e7a4008c */ 	swc1	$f4,0x8c($sp)
.L0f0d0f4c:
/*  f0d0f4c:	44863000 */ 	mtc1	$a2,$f6
/*  f0d0f50:	448a5000 */ 	mtc1	$t2,$f10
/*  f0d0f54:	3c017f1b */ 	lui	$at,%hi(var7f1adaac)
/*  f0d0f58:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d0f5c:	c426daac */ 	lwc1	$f6,%lo(var7f1adaac)($at)
/*  f0d0f60:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d0f64:	e7a8009c */ 	swc1	$f8,0x9c($sp)
/*  f0d0f68:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d0f6c:	e7a80094 */ 	swc1	$f8,0x94($sp)
.L0f0d0f70:
/*  f0d0f70:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d0f74:	44816000 */ 	mtc1	$at,$f12
/*  f0d0f78:	3c018007 */ 	lui	$at,%hi(var80070ec0)
/*  f0d0f7c:	a0200ec0 */ 	sb	$zero,%lo(var80070ec0)($at)
/*  f0d0f80:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d0f84:	46006006 */ 	mov.s	$f0,$f12
/*  f0d0f88:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0d0f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0f90:	4500000a */ 	bc1f	.L0f0d0fbc
/*  f0d0f94:	3c017f1b */ 	lui	$at,%hi(var7f1adab0)
/*  f0d0f98:	c432dab0 */ 	lwc1	$f18,%lo(var7f1adab0)($at)
/*  f0d0f9c:	c7ae00e0 */ 	lwc1	$f14,0xe0($sp)
/*  f0d0fa0:	460c0000 */ 	add.s	$f0,$f0,$f12
.L0f0d0fa4:
/*  f0d0fa4:	46127382 */ 	mul.s	$f14,$f14,$f18
/*  f0d0fa8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0d0fac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d0fb0:	4503fffc */ 	bc1tl	.L0f0d0fa4
/*  f0d0fb4:	460c0000 */ 	add.s	$f0,$f0,$f12
/*  f0d0fb8:	e7ae00e0 */ 	swc1	$f14,0xe0($sp)
.L0f0d0fbc:
/*  f0d0fbc:	8da30480 */ 	lw	$v1,0x480($t5)
/*  f0d0fc0:	c7ae00e0 */ 	lwc1	$f14,0xe0($sp)
/*  f0d0fc4:	80620036 */ 	lb	$v0,0x36($v1)
/*  f0d0fc8:	28410032 */ 	slti	$at,$v0,0x32
/*  f0d0fcc:	50200006 */ 	beqzl	$at,.L0f0d0fe8
/*  f0d0fd0:	240f0032 */ 	addiu	$t7,$zero,0x32
/*  f0d0fd4:	8d390038 */ 	lw	$t9,0x38($t1)
/*  f0d0fd8:	00597021 */ 	addu	$t6,$v0,$t9
/*  f0d0fdc:	10000003 */ 	beqz	$zero,.L0f0d0fec
/*  f0d0fe0:	a06e0036 */ 	sb	$t6,0x36($v1)
/*  f0d0fe4:	240f0032 */ 	addiu	$t7,$zero,0x32
.L0f0d0fe8:
/*  f0d0fe8:	a06f0036 */ 	sb	$t7,0x36($v1)
.L0f0d0fec:
/*  f0d0fec:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d0ff0:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f0d0ff4:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0d0ff8:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f0d0ffc:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f0d1000:	c5ca0008 */ 	lwc1	$f10,0x8($t6)
/*  f0d1004:	e44a00c8 */ 	swc1	$f10,0xc8($v0)
/*  f0d1008:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d100c:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d1010:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f0d1014:	c724000c */ 	lwc1	$f4,0xc($t9)
/*  f0d1018:	e44400cc */ 	swc1	$f4,0xcc($v0)
/*  f0d101c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1020:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d1024:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0d1028:	c7060010 */ 	lwc1	$f6,0x10($t8)
/*  f0d102c:	e44600d0 */ 	swc1	$f6,0xd0($v0)
/*  f0d1030:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1034:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f0d1038:	8dc40000 */ 	lw	$a0,0x0($t6)
/*  f0d103c:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d1040:	e7ae00e0 */ 	swc1	$f14,0xe0($sp)
/*  f0d1044:	0fc195e9 */ 	jal	roomsCopy
/*  f0d1048:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f0d104c:	0fc44727 */ 	jal	currentPlayerCanHaveWeapon
/*  f0d1050:	2404002e */ 	addiu	$a0,$zero,0x2e
/*  f0d1054:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1058:	44808000 */ 	mtc1	$zero,$f16
/*  f0d105c:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1060:	1440001e */ 	bnez	$v0,.L0f0d10dc
/*  f0d1064:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d1068:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d106c:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f0d1070:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0d1074:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d1078:	24010048 */ 	addiu	$at,$zero,0x48
/*  f0d107c:	a3000035 */ 	sb	$zero,0x35($t8)
/*  f0d1080:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1084:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d1088:	a1f90034 */ 	sb	$t9,0x34($t7)
/*  f0d108c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1090:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1094:	a1c00037 */ 	sb	$zero,0x37($t6)
/*  f0d1098:	8c590018 */ 	lw	$t9,0x18($v0)
/*  f0d109c:	372f0400 */ 	ori	$t7,$t9,0x400
/*  f0d10a0:	ac4f0018 */ 	sw	$t7,0x18($v0)
/*  f0d10a4:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d10a8:	8d2f0338 */ 	lw	$t7,0x338($t1)
/*  f0d10ac:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d10b0:	8dd90000 */ 	lw	$t9,0x0($t6)
/*  f0d10b4:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d10b8:	032f2023 */ 	subu	$a0,$t9,$t7
/*  f0d10bc:	0081001a */ 	div	$zero,$a0,$at
/*  f0d10c0:	00002012 */ 	mflo	$a0
/*  f0d10c4:	0fc083e4 */ 	jal	propClearReferences
/*  f0d10c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d10cc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d10d0:	44808000 */ 	mtc1	$zero,$f16
/*  f0d10d4:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d10d8:	83bf00c2 */ 	lb	$ra,0xc2($sp)
.L0f0d10dc:
/*  f0d10dc:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d10e0:	8da30480 */ 	lw	$v1,0x480($t5)
/*  f0d10e4:	806e0037 */ 	lb	$t6,0x37($v1)
/*  f0d10e8:	51c001c8 */ 	beqzl	$t6,.L0f0d180c
/*  f0d10ec:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d10f0:	8d39028c */ 	lw	$t9,0x28c($t1)
/*  f0d10f4:	3c188007 */ 	lui	$t8,%hi(g_PlayersWithControl)
/*  f0d10f8:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0d10fc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0d1100:	8f180750 */ 	lw	$t8,%lo(g_PlayersWithControl)($t8)
/*  f0d1104:	530001c1 */ 	beqzl	$t8,.L0f0d180c
/*  f0d1108:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d110c:	449f4000 */ 	mtc1	$ra,$f8
/*  f0d1110:	3c013d80 */ 	lui	$at,0x3d80
/*  f0d1114:	44812000 */ 	mtc1	$at,$f4
/*  f0d1118:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d111c:	240effff */ 	addiu	$t6,$zero,-1
/*  f0d1120:	adae1c40 */ 	sw	$t6,0x1c40($t5)
/*  f0d1124:	c528004c */ 	lwc1	$f8,0x4c($t1)
/*  f0d1128:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d112c:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0d1130:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1134:	c464001c */ 	lwc1	$f4,0x1c($v1)
/*  f0d1138:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0d113c:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0d1140:	e466001c */ 	swc1	$f6,0x1c($v1)
/*  f0d1144:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1148:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d114c:	c460001c */ 	lwc1	$f0,0x1c($v1)
/*  f0d1150:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0d1154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1158:	4500000c */ 	bc1f	.L0f0d118c
/*  f0d115c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d1160:	44817000 */ 	mtc1	$at,$f14
/*  f0d1164:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1168:	460e0200 */ 	add.s	$f8,$f0,$f14
.L0f0d116c:
/*  f0d116c:	e468001c */ 	swc1	$f8,0x1c($v1)
/*  f0d1170:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1174:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1178:	c460001c */ 	lwc1	$f0,0x1c($v1)
/*  f0d117c:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0d1180:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1184:	4503fff9 */ 	bc1tl	.L0f0d116c
/*  f0d1188:	460e0200 */ 	add.s	$f8,$f0,$f14
.L0f0d118c:
/*  f0d118c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d1190:	44817000 */ 	mtc1	$at,$f14
/*  f0d1194:	3c017f1b */ 	lui	$at,%hi(var7f1adab4)
/*  f0d1198:	4600703e */ 	c.le.s	$f14,$f0
/*  f0d119c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d11a0:	4500000a */ 	bc1f	.L0f0d11cc
/*  f0d11a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d11a8:	460e0101 */ 	sub.s	$f4,$f0,$f14
.L0f0d11ac:
/*  f0d11ac:	e464001c */ 	swc1	$f4,0x1c($v1)
/*  f0d11b0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d11b4:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d11b8:	c460001c */ 	lwc1	$f0,0x1c($v1)
/*  f0d11bc:	4600703e */ 	c.le.s	$f14,$f0
/*  f0d11c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d11c4:	4503fff9 */ 	bc1tl	.L0f0d11ac
/*  f0d11c8:	460e0101 */ 	sub.s	$f4,$f0,$f14
.L0f0d11cc:
/*  f0d11cc:	c42adab4 */ 	lwc1	$f10,%lo(var7f1adab4)($at)
/*  f0d11d0:	460a0302 */ 	mul.s	$f12,$f0,$f10
/*  f0d11d4:	0c0068f4 */ 	jal	cosf
/*  f0d11d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d11dc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d11e0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d11e4:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d11e8:	3c017f1b */ 	lui	$at,%hi(var7f1adab8)
/*  f0d11ec:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d11f0:	e5e00020 */ 	swc1	$f0,0x20($t7)
/*  f0d11f4:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d11f8:	c428dab8 */ 	lwc1	$f8,%lo(var7f1adab8)($at)
/*  f0d11fc:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1200:	c5c6001c */ 	lwc1	$f6,0x1c($t6)
/*  f0d1204:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f0d1208:	0c0068f7 */ 	jal	sinf
/*  f0d120c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1210:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1214:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1218:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d121c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d1220:	44817000 */ 	mtc1	$at,$f14
/*  f0d1224:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d1228:	3c013d80 */ 	lui	$at,0x3d80
/*  f0d122c:	44815000 */ 	mtc1	$at,$f10
/*  f0d1230:	e5e00024 */ 	swc1	$f0,0x24($t7)
/*  f0d1234:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f0d1238:	c528004c */ 	lwc1	$f8,0x4c($t1)
/*  f0d123c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1240:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0d1244:	44808000 */ 	mtc1	$zero,$f16
/*  f0d1248:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d124c:	3c017f1b */ 	lui	$at,%hi(var7f1adabc)
/*  f0d1250:	c46a0028 */ 	lwc1	$f10,0x28($v1)
/*  f0d1254:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0d1258:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0d125c:	e4660028 */ 	swc1	$f6,0x28($v1)
/*  f0d1260:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1264:	c7a80088 */ 	lwc1	$f8,0x88($sp)
/*  f0d1268:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d126c:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d1270:	46024032 */ 	c.eq.s	$f8,$f2
/*  f0d1274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1278:	45030037 */ 	bc1tl	.L0f0d1358
/*  f0d127c:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f0d1280:	4610103c */ 	c.lt.s	$f2,$f16
/*  f0d1284:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1288:	4502000b */ 	bc1fl	.L0f0d12b8
/*  f0d128c:	4602703e */ 	c.le.s	$f14,$f2
/*  f0d1290:	460e1280 */ 	add.s	$f10,$f2,$f14
.L0f0d1294:
/*  f0d1294:	e46a0028 */ 	swc1	$f10,0x28($v1)
/*  f0d1298:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d129c:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d12a0:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d12a4:	4610103c */ 	c.lt.s	$f2,$f16
/*  f0d12a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d12ac:	4503fff9 */ 	bc1tl	.L0f0d1294
/*  f0d12b0:	460e1280 */ 	add.s	$f10,$f2,$f14
/*  f0d12b4:	4602703e */ 	c.le.s	$f14,$f2
.L0f0d12b8:
/*  f0d12b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d12bc:	4500000a */ 	bc1f	.L0f0d12e8
/*  f0d12c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d12c4:	460e1101 */ 	sub.s	$f4,$f2,$f14
.L0f0d12c8:
/*  f0d12c8:	e4640028 */ 	swc1	$f4,0x28($v1)
/*  f0d12cc:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d12d0:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d12d4:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d12d8:	4602703e */ 	c.le.s	$f14,$f2
/*  f0d12dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d12e0:	4503fff9 */ 	bc1tl	.L0f0d12c8
/*  f0d12e4:	460e1101 */ 	sub.s	$f4,$f2,$f14
.L0f0d12e8:
/*  f0d12e8:	c426dabc */ 	lwc1	$f6,%lo(var7f1adabc)($at)
/*  f0d12ec:	46061302 */ 	mul.s	$f12,$f2,$f6
/*  f0d12f0:	0c0068f4 */ 	jal	cosf
/*  f0d12f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d12f8:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d12fc:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1300:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1304:	3c017f1b */ 	lui	$at,%hi(var7f1adac0)
/*  f0d1308:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d130c:	e5c0002c */ 	swc1	$f0,0x2c($t6)
/*  f0d1310:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1314:	c42adac0 */ 	lwc1	$f10,%lo(var7f1adac0)($at)
/*  f0d1318:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d131c:	c5e80028 */ 	lwc1	$f8,0x28($t7)
/*  f0d1320:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f0d1324:	0c0068f7 */ 	jal	sinf
/*  f0d1328:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d132c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1330:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1334:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1338:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d133c:	44817000 */ 	mtc1	$at,$f14
/*  f0d1340:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1344:	44808000 */ 	mtc1	$zero,$f16
/*  f0d1348:	e5c00030 */ 	swc1	$f0,0x30($t6)
/*  f0d134c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1350:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1354:	8faf00b4 */ 	lw	$t7,0xb4($sp)
.L0f0d1358:
/*  f0d1358:	e7b000c4 */ 	swc1	$f16,0xc4($sp)
/*  f0d135c:	46008486 */ 	mov.s	$f18,$f16
/*  f0d1360:	e7b000cc */ 	swc1	$f16,0xcc($sp)
/*  f0d1364:	e7b000d0 */ 	swc1	$f16,0xd0($sp)
/*  f0d1368:	11e00069 */ 	beqz	$t7,.L0f0d1510
/*  f0d136c:	e7b000d4 */ 	swc1	$f16,0xd4($sp)
/*  f0d1370:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d1374:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f0d1378:	4602803c */ 	c.lt.s	$f16,$f2
/*  f0d137c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1380:	45020051 */ 	bc1fl	.L0f0d14c8
/*  f0d1384:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0d1388:	44803000 */ 	mtc1	$zero,$f6
/*  f0d138c:	3c014334 */ 	lui	$at,0x4334
/*  f0d1390:	46062032 */ 	c.eq.s	$f4,$f6
/*  f0d1394:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1398:	4503004b */ 	bc1tl	.L0f0d14c8
/*  f0d139c:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0d13a0:	44814000 */ 	mtc1	$at,$f8
/*  f0d13a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d13a8:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0d13ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d13b0:	45020017 */ 	bc1fl	.L0f0d1410
/*  f0d13b4:	8d2e0038 */ 	lw	$t6,0x38($t1)
/*  f0d13b8:	8d380038 */ 	lw	$t8,0x38($t1)
/*  f0d13bc:	46001006 */ 	mov.s	$f0,$f2
/*  f0d13c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d13c4:	1b000025 */ 	blez	$t8,.L0f0d145c
/*  f0d13c8:	3c017f1b */ 	lui	$at,%hi(var7f1adac4)
/*  f0d13cc:	c422dac4 */ 	lwc1	$f2,%lo(var7f1adac4)($at)
/*  f0d13d0:	8d2e0284 */ 	lw	$t6,0x284($t1)
.L0f0d13d4:
/*  f0d13d4:	46020002 */ 	mul.s	$f0,$f0,$f2
/*  f0d13d8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d13dc:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d13e0:	c46a0028 */ 	lwc1	$f10,0x28($v1)
/*  f0d13e4:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0d13e8:	e4640028 */ 	swc1	$f4,0x28($v1)
/*  f0d13ec:	8d390038 */ 	lw	$t9,0x38($t1)
/*  f0d13f0:	0059082a */ 	slt	$at,$v0,$t9
/*  f0d13f4:	5420fff7 */ 	bnezl	$at,.L0f0d13d4
/*  f0d13f8:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d13fc:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1400:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d1404:	10000015 */ 	beqz	$zero,.L0f0d145c
/*  f0d1408:	c7020028 */ 	lwc1	$f2,0x28($t8)
/*  f0d140c:	8d2e0038 */ 	lw	$t6,0x38($t1)
.L0f0d1410:
/*  f0d1410:	46027001 */ 	sub.s	$f0,$f14,$f2
/*  f0d1414:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d1418:	19c00010 */ 	blez	$t6,.L0f0d145c
/*  f0d141c:	3c017f1b */ 	lui	$at,%hi(var7f1adac8)
/*  f0d1420:	c422dac8 */ 	lwc1	$f2,%lo(var7f1adac8)($at)
/*  f0d1424:	8d390284 */ 	lw	$t9,0x284($t1)
.L0f0d1428:
/*  f0d1428:	46020002 */ 	mul.s	$f0,$f0,$f2
/*  f0d142c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d1430:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1434:	c4660028 */ 	lwc1	$f6,0x28($v1)
/*  f0d1438:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0d143c:	e4680028 */ 	swc1	$f8,0x28($v1)
/*  f0d1440:	8d2f0038 */ 	lw	$t7,0x38($t1)
/*  f0d1444:	004f082a */ 	slt	$at,$v0,$t7
/*  f0d1448:	5420fff7 */ 	bnezl	$at,.L0f0d1428
/*  f0d144c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1450:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1454:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1458:	c5c20028 */ 	lwc1	$f2,0x28($t6)
.L0f0d145c:
/*  f0d145c:	3c017f1b */ 	lui	$at,%hi(var7f1adacc)
/*  f0d1460:	c42adacc */ 	lwc1	$f10,%lo(var7f1adacc)($at)
/*  f0d1464:	460a1302 */ 	mul.s	$f12,$f2,$f10
/*  f0d1468:	0c0068f4 */ 	jal	cosf
/*  f0d146c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1470:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1474:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1478:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d147c:	3c017f1b */ 	lui	$at,%hi(var7f1adad0)
/*  f0d1480:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d1484:	e5e0002c */ 	swc1	$f0,0x2c($t7)
/*  f0d1488:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d148c:	c426dad0 */ 	lwc1	$f6,%lo(var7f1adad0)($at)
/*  f0d1490:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1494:	c5c40028 */ 	lwc1	$f4,0x28($t6)
/*  f0d1498:	46062302 */ 	mul.s	$f12,$f4,$f6
/*  f0d149c:	0c0068f7 */ 	jal	sinf
/*  f0d14a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d14a4:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d14a8:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d14ac:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d14b0:	44808000 */ 	mtc1	$zero,$f16
/*  f0d14b4:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d14b8:	e5e00030 */ 	swc1	$f0,0x30($t7)
/*  f0d14bc:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d14c0:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d14c4:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
.L0f0d14c8:
/*  f0d14c8:	c46a0024 */ 	lwc1	$f10,0x24($v1)
/*  f0d14cc:	3c017f1b */ 	lui	$at,%hi(var7f1adad4)
/*  f0d14d0:	c42cdad4 */ 	lwc1	$f12,%lo(var7f1adad4)($at)
/*  f0d14d4:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0d14d8:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d14dc:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0d14e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d14e4:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f0d14e8:	46004187 */ 	neg.s	$f6,$f8
/*  f0d14ec:	460a8100 */ 	add.s	$f4,$f16,$f10
/*  f0d14f0:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0d14f4:	c46a0020 */ 	lwc1	$f10,0x20($v1)
/*  f0d14f8:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f0d14fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1500:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*  f0d1504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1508:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0d150c:	46068480 */ 	add.s	$f18,$f16,$f6
.L0f0d1510:
/*  f0d1510:	c7aa0094 */ 	lwc1	$f10,0x94($sp)
/*  f0d1514:	44802000 */ 	mtc1	$zero,$f4
/*  f0d1518:	3c017f1b */ 	lui	$at,%hi(var7f1adad8)
/*  f0d151c:	c42cdad8 */ 	lwc1	$f12,%lo(var7f1adad8)($at)
/*  f0d1520:	46045032 */ 	c.eq.s	$f10,$f4
/*  f0d1524:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0d1528:	45030016 */ 	bc1tl	.L0f0d1584
/*  f0d152c:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
/*  f0d1530:	44814000 */ 	mtc1	$at,$f8
/*  f0d1534:	c4660020 */ 	lwc1	$f6,0x20($v1)
/*  f0d1538:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d153c:	46085002 */ 	mul.s	$f0,$f10,$f8
/*  f0d1540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1544:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0d1548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d154c:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0d1550:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1554:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0d1558:	46088180 */ 	add.s	$f6,$f16,$f8
/*  f0d155c:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0d1560:	c4640024 */ 	lwc1	$f4,0x24($v1)
/*  f0d1564:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f0d1568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d156c:	460c5202 */ 	mul.s	$f8,$f10,$f12
/*  f0d1570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1574:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0d1578:	46068100 */ 	add.s	$f4,$f16,$f6
/*  f0d157c:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f0d1580:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
.L0f0d1584:
/*  f0d1584:	44804000 */ 	mtc1	$zero,$f8
/*  f0d1588:	3c014040 */ 	lui	$at,0x4040
/*  f0d158c:	46085032 */ 	c.eq.s	$f10,$f8
/*  f0d1590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1594:	45030019 */ 	bc1tl	.L0f0d15fc
/*  f0d1598:	c466006c */ 	lwc1	$f6,0x6c($v1)
/*  f0d159c:	44813000 */ 	mtc1	$at,$f6
/*  f0d15a0:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0d15a4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0d15a8:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f0d15ac:	c526004c */ 	lwc1	$f6,0x4c($t1)
/*  f0d15b0:	240effff */ 	addiu	$t6,$zero,-1
/*  f0d15b4:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*  f0d15b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d15bc:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0d15c0:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f0d15c4:	45000003 */ 	bc1f	.L0f0d15d4
/*  f0d15c8:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f0d15cc:	10000002 */ 	beqz	$zero,.L0f0d15d8
/*  f0d15d0:	a46e003a */ 	sh	$t6,0x3a($v1)
.L0f0d15d4:
/*  f0d15d4:	a479003a */ 	sh	$t9,0x3a($v1)
.L0f0d15d8:
/*  f0d15d8:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d15dc:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d15e0:	a300003c */ 	sb	$zero,0x3c($t8)
/*  f0d15e4:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d15e8:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f0d15ec:	a320003d */ 	sb	$zero,0x3d($t9)
/*  f0d15f0:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d15f4:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d15f8:	c466006c */ 	lwc1	$f6,0x6c($v1)
.L0f0d15fc:
/*  f0d15fc:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0d1600:	3c017f1b */ 	lui	$at,%hi(var7f1adadc)
/*  f0d1604:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0d1608:	e468006c */ 	swc1	$f8,0x6c($v1)
/*  f0d160c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1610:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1614:	c46a0070 */ 	lwc1	$f10,0x70($v1)
/*  f0d1618:	46125180 */ 	add.s	$f6,$f10,$f18
/*  f0d161c:	e4660070 */ 	swc1	$f6,0x70($v1)
/*  f0d1620:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1624:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0d1628:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d162c:	c4640074 */ 	lwc1	$f4,0x74($v1)
/*  f0d1630:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0d1634:	e46a0074 */ 	swc1	$f10,0x74($v1)
/*  f0d1638:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d163c:	c7a400d0 */ 	lwc1	$f4,0xd0($sp)
/*  f0d1640:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1644:	c4660078 */ 	lwc1	$f6,0x78($v1)
/*  f0d1648:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0d164c:	e4680078 */ 	swc1	$f8,0x78($v1)
/*  f0d1650:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1654:	c428dadc */ 	lwc1	$f8,%lo(var7f1adadc)($at)
/*  f0d1658:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d165c:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1660:	c46c0070 */ 	lwc1	$f12,0x70($v1)
/*  f0d1664:	c460006c */ 	lwc1	$f0,0x6c($v1)
/*  f0d1668:	460c6282 */ 	mul.s	$f10,$f12,$f12
/*  f0d166c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1670:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f0d1674:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f0d1678:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0d167c:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0d1680:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f0d1684:	4604303c */ 	c.lt.s	$f6,$f4
/*  f0d1688:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d168c:	45000018 */ 	bc1f	.L0f0d16f0
/*  f0d1690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1694:	0c012974 */ 	jal	sqrtf
/*  f0d1698:	46002306 */ 	mov.s	$f12,$f4
/*  f0d169c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d16a0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d16a4:	3c014118 */ 	lui	$at,0x4118
/*  f0d16a8:	44814000 */ 	mtc1	$at,$f8
/*  f0d16ac:	c52a004c */ 	lwc1	$f10,0x4c($t1)
/*  f0d16b0:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d16b4:	44808000 */ 	mtc1	$zero,$f16
/*  f0d16b8:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f0d16bc:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d16c0:	c464006c */ 	lwc1	$f4,0x6c($v1)
/*  f0d16c4:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f0d16c8:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*  f0d16cc:	e468006c */ 	swc1	$f8,0x6c($v1)
/*  f0d16d0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d16d4:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d16d8:	c46a0070 */ 	lwc1	$f10,0x70($v1)
/*  f0d16dc:	460c5182 */ 	mul.s	$f6,$f10,$f12
/*  f0d16e0:	e4660070 */ 	swc1	$f6,0x70($v1)
/*  f0d16e4:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d16e8:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d16ec:	8f230480 */ 	lw	$v1,0x480($t9)
.L0f0d16f0:
/*  f0d16f0:	c46c0078 */ 	lwc1	$f12,0x78($v1)
/*  f0d16f4:	c4600074 */ 	lwc1	$f0,0x74($v1)
/*  f0d16f8:	3c014361 */ 	lui	$at,0x4361
/*  f0d16fc:	460c6102 */ 	mul.s	$f4,$f12,$f12
/*  f0d1700:	44813000 */ 	mtc1	$at,$f6
/*  f0d1704:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f0d1708:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0d170c:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f0d1710:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0d1714:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0d1718:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0d171c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1720:	4502001a */ 	bc1fl	.L0f0d178c
/*  f0d1724:	c4640044 */ 	lwc1	$f4,0x44($v1)
/*  f0d1728:	0c012974 */ 	jal	sqrtf
/*  f0d172c:	46005306 */ 	mov.s	$f12,$f10
/*  f0d1730:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1734:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1738:	3c014170 */ 	lui	$at,0x4170
/*  f0d173c:	44813000 */ 	mtc1	$at,$f6
/*  f0d1740:	c524004c */ 	lwc1	$f4,0x4c($t1)
/*  f0d1744:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1748:	44808000 */ 	mtc1	$zero,$f16
/*  f0d174c:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0d1750:	46004283 */ 	div.s	$f10,$f8,$f0
/*  f0d1754:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0d1758:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d175c:	c4660074 */ 	lwc1	$f6,0x74($v1)
/*  f0d1760:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f0d1764:	e4640074 */ 	swc1	$f4,0x74($v1)
/*  f0d1768:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d176c:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0d1770:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1774:	c4680078 */ 	lwc1	$f8,0x78($v1)
/*  f0d1778:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0d177c:	e46a0078 */ 	swc1	$f10,0x78($v1)
/*  f0d1780:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1784:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1788:	c4640044 */ 	lwc1	$f4,0x44($v1)
.L0f0d178c:
/*  f0d178c:	c7a800c4 */ 	lwc1	$f8,0xc4($sp)
/*  f0d1790:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0d1794:	44815000 */ 	mtc1	$at,$f10
/*  f0d1798:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0d179c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0d17a0:	e4660044 */ 	swc1	$f6,0x44($v1)
/*  f0d17a4:	c524004c */ 	lwc1	$f4,0x4c($t1)
/*  f0d17a8:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d17ac:	46045082 */ 	mul.s	$f2,$f10,$f4
/*  f0d17b0:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d17b4:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f0d17b8:	46001307 */ 	neg.s	$f12,$f2
/*  f0d17bc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0d17c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d17c4:	45020009 */ 	bc1fl	.L0f0d17ec
/*  f0d17c8:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0d17cc:	e46c0044 */ 	swc1	$f12,0x44($v1)
/*  f0d17d0:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d17d4:	c526004c */ 	lwc1	$f6,0x4c($t1)
/*  f0d17d8:	44814000 */ 	mtc1	$at,$f8
/*  f0d17dc:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d17e0:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f0d17e4:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f0d17e8:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0d17ec:
/*  f0d17ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d17f0:	4502000a */ 	bc1fl	.L0f0d181c
/*  f0d17f4:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f0d17f8:	e4620044 */ 	swc1	$f2,0x44($v1)
/*  f0d17fc:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1800:	10000005 */ 	beqz	$zero,.L0f0d1818
/*  f0d1804:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1808:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f0d180c:
/*  f0d180c:	a06e003d */ 	sb	$t6,0x3d($v1)
/*  f0d1810:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1814:	8f230480 */ 	lw	$v1,0x480($t9)
.L0f0d1818:
/*  f0d1818:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
.L0f0d181c:
/*  f0d181c:	46105032 */ 	c.eq.s	$f10,$f16
/*  f0d1820:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1824:	45020037 */ 	bc1fl	.L0f0d1904
/*  f0d1828:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f0d182c:	906f003d */ 	lbu	$t7,0x3d($v1)
/*  f0d1830:	3c017f1b */ 	lui	$at,%hi(var7f1adae0)
/*  f0d1834:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1838:	55e00011 */ 	bnezl	$t7,.L0f0d1880
/*  f0d183c:	a078003d */ 	sb	$t8,0x3d($v1)
/*  f0d1840:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f0d1844:	44802000 */ 	mtc1	$zero,$f4
/*  f0d1848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d184c:	4600203c */ 	c.lt.s	$f4,$f0
/*  f0d1850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1854:	45020004 */ 	bc1fl	.L0f0d1868
/*  f0d1858:	46000087 */ 	neg.s	$f2,$f0
/*  f0d185c:	10000002 */ 	beqz	$zero,.L0f0d1868
/*  f0d1860:	46000086 */ 	mov.s	$f2,$f0
/*  f0d1864:	46000087 */ 	neg.s	$f2,$f0
.L0f0d1868:
/*  f0d1868:	c428dae0 */ 	lwc1	$f8,%lo(var7f1adae0)($at)
/*  f0d186c:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0d1870:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1874:	45020023 */ 	bc1fl	.L0f0d1904
/*  f0d1878:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f0d187c:	a078003d */ 	sb	$t8,0x3d($v1)
.L0f0d1880:
/*  f0d1880:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1884:	8d2f0038 */ 	lw	$t7,0x38($t1)
/*  f0d1888:	3c017f1b */ 	lui	$at,%hi(var7f1adae4)
/*  f0d188c:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1890:	9079003c */ 	lbu	$t9,0x3c($v1)
/*  f0d1894:	032fc021 */ 	addu	$t8,$t9,$t7
/*  f0d1898:	a078003c */ 	sb	$t8,0x3c($v1)
/*  f0d189c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d18a0:	c426dae4 */ 	lwc1	$f6,%lo(var7f1adae4)($at)
/*  f0d18a4:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d18a8:	8479003a */ 	lh	$t9,0x3a($v1)
/*  f0d18ac:	44995000 */ 	mtc1	$t9,$f10
/*  f0d18b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d18b4:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d18b8:	c46a0044 */ 	lwc1	$f10,0x44($v1)
/*  f0d18bc:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0d18c0:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0d18c4:	e4660044 */ 	swc1	$f6,0x44($v1)
/*  f0d18c8:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d18cc:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d18d0:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0d18d4:	2b010079 */ 	slti	$at,$t8,0x79
/*  f0d18d8:	5420000a */ 	bnezl	$at,.L0f0d1904
/*  f0d18dc:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f0d18e0:	a060003c */ 	sb	$zero,0x3c($v1)
/*  f0d18e4:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d18e8:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d18ec:	8479003a */ 	lh	$t9,0x3a($v1)
/*  f0d18f0:	00197823 */ 	negu	$t7,$t9
/*  f0d18f4:	a46f003a */ 	sh	$t7,0x3a($v1)
/*  f0d18f8:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d18fc:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1900:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
.L0f0d1904:
/*  f0d1904:	c4640044 */ 	lwc1	$f4,0x44($v1)
/*  f0d1908:	3c028007 */ 	lui	$v0,%hi(var80070ec4)
/*  f0d190c:	24420ec4 */ 	addiu	$v0,$v0,%lo(var80070ec4)
/*  f0d1910:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0d1914:	3c018007 */ 	lui	$at,%hi(var80070ec8)
/*  f0d1918:	e46a0044 */ 	swc1	$f10,0x44($v1)
/*  f0d191c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1920:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1924:	c4680074 */ 	lwc1	$f8,0x74($v1)
/*  f0d1928:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0d192c:	e4660074 */ 	swc1	$f6,0x74($v1)
/*  f0d1930:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1934:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1938:	c4640078 */ 	lwc1	$f4,0x78($v1)
/*  f0d193c:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0d1940:	e46a0078 */ 	swc1	$f10,0x78($v1)
/*  f0d1944:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1948:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d194c:	c468006c */ 	lwc1	$f8,0x6c($v1)
/*  f0d1950:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0d1954:	e466006c */ 	swc1	$f6,0x6c($v1)
/*  f0d1958:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d195c:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1960:	c4640070 */ 	lwc1	$f4,0x70($v1)
/*  f0d1964:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0d1968:	e46a0070 */ 	swc1	$f10,0x70($v1)
/*  f0d196c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1970:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1974:	c468006c */ 	lwc1	$f8,0x6c($v1)
/*  f0d1978:	c4660074 */ 	lwc1	$f6,0x74($v1)
/*  f0d197c:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0d1980:	e4640040 */ 	swc1	$f4,0x40($v1)
/*  f0d1984:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1988:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d198c:	c46a0070 */ 	lwc1	$f10,0x70($v1)
/*  f0d1990:	c4680078 */ 	lwc1	$f8,0x78($v1)
/*  f0d1994:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0d1998:	e4660048 */ 	swc1	$f6,0x48($v1)
/*  f0d199c:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d19a0:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d19a4:	c4640030 */ 	lwc1	$f4,0x30($v1)
/*  f0d19a8:	e4640008 */ 	swc1	$f4,0x8($v1)
/*  f0d19ac:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d19b0:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d19b4:	c46a002c */ 	lwc1	$f10,0x2c($v1)
/*  f0d19b8:	c4680024 */ 	lwc1	$f8,0x24($v1)
/*  f0d19bc:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d19c0:	e4660004 */ 	swc1	$f6,0x4($v1)
/*  f0d19c4:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d19c8:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d19cc:	c464002c */ 	lwc1	$f4,0x2c($v1)
/*  f0d19d0:	c4680020 */ 	lwc1	$f8,0x20($v1)
/*  f0d19d4:	46002287 */ 	neg.s	$f10,$f4
/*  f0d19d8:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d19dc:	e466000c */ 	swc1	$f6,0xc($v1)
/*  f0d19e0:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d19e4:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d19e8:	c464002c */ 	lwc1	$f4,0x2c($v1)
/*  f0d19ec:	e4640014 */ 	swc1	$f4,0x14($v1)
/*  f0d19f0:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d19f4:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d19f8:	c46a0030 */ 	lwc1	$f10,0x30($v1)
/*  f0d19fc:	c4660024 */ 	lwc1	$f6,0x24($v1)
/*  f0d1a00:	46005207 */ 	neg.s	$f8,$f10
/*  f0d1a04:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0d1a08:	e4640010 */ 	swc1	$f4,0x10($v1)
/*  f0d1a0c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1a10:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1a14:	c46a0030 */ 	lwc1	$f10,0x30($v1)
/*  f0d1a18:	c4680020 */ 	lwc1	$f8,0x20($v1)
/*  f0d1a1c:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d1a20:	e4660018 */ 	swc1	$f6,0x18($v1)
/*  f0d1a24:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f0d1a28:	a02e0ec8 */ 	sb	$t6,%lo(var80070ec8)($at)
/*  f0d1a2c:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f0d1a30:	3c018007 */ 	lui	$at,%hi(var80070ecc)
/*  f0d1a34:	0fc33f89 */ 	jal	func0f0cfe24
/*  f0d1a38:	a0200ecc */ 	sb	$zero,%lo(var80070ecc)($at)
/*  f0d1a3c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1a40:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1a44:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1a48:	3c188007 */ 	lui	$t8,%hi(var80070ec4)
/*  f0d1a4c:	3c0e8007 */ 	lui	$t6,%hi(var80070ec8)
/*  f0d1a50:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1a54:	806f0037 */ 	lb	$t7,0x37($v1)
/*  f0d1a58:	51e0007f */ 	beqzl	$t7,.L0f0d1c58
/*  f0d1a5c:	3c0144c8 */ 	lui	$at,0x44c8
/*  f0d1a60:	93180ec4 */ 	lbu	$t8,%lo(var80070ec4)($t8)
/*  f0d1a64:	91ce0ec8 */ 	lbu	$t6,%lo(var80070ec8)($t6)
/*  f0d1a68:	51d8007b */ 	beql	$t6,$t8,.L0f0d1c58
/*  f0d1a6c:	3c0144c8 */ 	lui	$at,0x44c8
/*  f0d1a70:	1b000078 */ 	blez	$t8,.L0f0d1c54
/*  f0d1a74:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0d1a78:	8f2f0120 */ 	lw	$t7,0x120($t9)
/*  f0d1a7c:	270effff */ 	addiu	$t6,$t8,-1
/*  f0d1a80:	29e1000b */ 	slti	$at,$t7,0xb
/*  f0d1a84:	14200073 */ 	bnez	$at,.L0f0d1c54
/*  f0d1a88:	2dc10005 */ 	sltiu	$at,$t6,0x5
/*  f0d1a8c:	1020006f */ 	beqz	$at,.L0f0d1c4c
/*  f0d1a90:	af200120 */ 	sw	$zero,0x120($t9)
/*  f0d1a94:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0d1a98:	3c017f1b */ 	lui	$at,%hi(var7f1adae8)
/*  f0d1a9c:	002e0821 */ 	addu	$at,$at,$t6
/*  f0d1aa0:	8c2edae8 */ 	lw	$t6,%lo(var7f1adae8)($at)
/*  f0d1aa4:	01c00008 */ 	jr	$t6
/*  f0d1aa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1aac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d1ab0:	44812000 */ 	mtc1	$at,$f4
/*  f0d1ab4:	340f808c */ 	dli	$t7,0x808c
/*  f0d1ab8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0d1abc:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0d1ac0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d1ac4:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f0d1ac8:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0d1acc:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0d1ad0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d1ad4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d1ad8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d1adc:	24063e80 */ 	addiu	$a2,$zero,0x3e80
/*  f0d1ae0:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0d1ae4:	0c0041c6 */ 	jal	func00010718
/*  f0d1ae8:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0d1aec:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1af0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1af4:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1af8:	10000056 */ 	beqz	$zero,.L0f0d1c54
/*  f0d1afc:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1b00:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d1b04:	44815000 */ 	mtc1	$at,$f10
/*  f0d1b08:	3419808c */ 	dli	$t9,0x808c
/*  f0d1b0c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1b10:	240effff */ 	addiu	$t6,$zero,-1
/*  f0d1b14:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d1b18:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0d1b1c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0d1b20:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0d1b24:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0d1b28:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d1b2c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d1b30:	24063e80 */ 	addiu	$a2,$zero,0x3e80
/*  f0d1b34:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0d1b38:	0c0041c6 */ 	jal	func00010718
/*  f0d1b3c:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f0d1b40:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1b44:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1b48:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1b4c:	10000041 */ 	beqz	$zero,.L0f0d1c54
/*  f0d1b50:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1b54:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d1b58:	44814000 */ 	mtc1	$at,$f8
/*  f0d1b5c:	3418808c */ 	dli	$t8,0x808c
/*  f0d1b60:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d1b64:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0d1b68:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0d1b6c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0d1b70:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0d1b74:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0d1b78:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0d1b7c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d1b80:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d1b84:	24063e80 */ 	addiu	$a2,$zero,0x3e80
/*  f0d1b88:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0d1b8c:	0c0041c6 */ 	jal	func00010718
/*  f0d1b90:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0d1b94:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1b98:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1b9c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1ba0:	1000002c */ 	beqz	$zero,.L0f0d1c54
/*  f0d1ba4:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1ba8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d1bac:	44813000 */ 	mtc1	$at,$f6
/*  f0d1bb0:	340e808c */ 	dli	$t6,0x808c
/*  f0d1bb4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d1bb8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0d1bbc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1bc0:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0d1bc4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0d1bc8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0d1bcc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0d1bd0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d1bd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d1bd8:	24063e80 */ 	addiu	$a2,$zero,0x3e80
/*  f0d1bdc:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0d1be0:	0c0041c6 */ 	jal	func00010718
/*  f0d1be4:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0d1be8:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1bec:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1bf0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1bf4:	10000017 */ 	beqz	$zero,.L0f0d1c54
/*  f0d1bf8:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1bfc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d1c00:	44812000 */ 	mtc1	$at,$f4
/*  f0d1c04:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f0d1c08:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0d1c0c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0d1c10:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0d1c14:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0d1c18:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0d1c1c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d1c20:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f0d1c24:	240500f2 */ 	addiu	$a1,$zero,0xf2
/*  f0d1c28:	00003025 */ 	or	$a2,$zero,$zero
/*  f0d1c2c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0d1c30:	0c004241 */ 	jal	func00010904
/*  f0d1c34:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0d1c38:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1c3c:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1c40:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1c44:	10000003 */ 	beqz	$zero,.L0f0d1c54
/*  f0d1c48:	8dc30480 */ 	lw	$v1,0x480($t6)
.L0f0d1c4c:
/*  f0d1c4c:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1c50:	8de30480 */ 	lw	$v1,0x480($t7)
.L0f0d1c54:
/*  f0d1c54:	3c0144c8 */ 	lui	$at,0x44c8
.L0f0d1c58:
/*  f0d1c58:	44816000 */ 	mtc1	$at,$f12
/*  f0d1c5c:	c4620058 */ 	lwc1	$f2,0x58($v1)
/*  f0d1c60:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0d1c64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1c68:	45020006 */ 	bc1fl	.L0f0d1c84
/*  f0d1c6c:	460c1003 */ 	div.s	$f0,$f2,$f12
/*  f0d1c70:	e46c0058 */ 	swc1	$f12,0x58($v1)
/*  f0d1c74:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1c78:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1c7c:	c4620058 */ 	lwc1	$f2,0x58($v1)
/*  f0d1c80:	460c1003 */ 	div.s	$f0,$f2,$f12
.L0f0d1c84:
/*  f0d1c84:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0d1c88:	44815000 */ 	mtc1	$at,$f10
/*  f0d1c8c:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f0d1c90:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0d1c94:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0d1c98:	44053000 */ 	mfc1	$a1,$f6
/*  f0d1c9c:	0fc24de4 */ 	jal	func0f093790
/*  f0d1ca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1ca4:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1ca8:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1cac:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1cb0:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d1cb4:	44817000 */ 	mtc1	$at,$f14
/*  f0d1cb8:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d1cbc:	3c014334 */ 	lui	$at,0x4334
/*  f0d1cc0:	44812000 */ 	mtc1	$at,$f4
/*  f0d1cc4:	c5ea001c */ 	lwc1	$f10,0x1c($t7)
/*  f0d1cc8:	44804000 */ 	mtc1	$zero,$f8
/*  f0d1ccc:	460a2001 */ 	sub.s	$f0,$f4,$f10
/*  f0d1cd0:	4608003c */ 	c.lt.s	$f0,$f8
/*  f0d1cd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1cd8:	45020003 */ 	bc1fl	.L0f0d1ce8
/*  f0d1cdc:	460e0183 */ 	div.s	$f6,$f0,$f14
/*  f0d1ce0:	460e0000 */ 	add.s	$f0,$f0,$f14
/*  f0d1ce4:	460e0183 */ 	div.s	$f6,$f0,$f14
.L0f0d1ce8:
/*  f0d1ce8:	3c017f1b */ 	lui	$at,%hi(var7f1adafc)
/*  f0d1cec:	c424dafc */ 	lwc1	$f4,%lo(var7f1adafc)($at)
/*  f0d1cf0:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f0d1cf4:	46043002 */ 	mul.s	$f0,$f6,$f4
/*  f0d1cf8:	44050000 */ 	mfc1	$a1,$f0
/*  f0d1cfc:	0fc0f94e */ 	jal	func0f03e538
/*  f0d1d00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1d04:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1d08:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1d0c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1d10:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1d14:	80780036 */ 	lb	$t8,0x36($v1)
/*  f0d1d18:	2b010032 */ 	slti	$at,$t8,0x32
/*  f0d1d1c:	542000aa */ 	bnezl	$at,.L0f0d1fc8
/*  f0d1d20:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0d1d24:	806e0068 */ 	lb	$t6,0x68($v1)
/*  f0d1d28:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*  f0d1d2c:	5dc00013 */ 	bgtzl	$t6,.L0f0d1d7c
/*  f0d1d30:	a0600039 */ 	sb	$zero,0x39($v1)
/*  f0d1d34:	51e00011 */ 	beqzl	$t7,.L0f0d1d7c
/*  f0d1d38:	a0600039 */ 	sb	$zero,0x39($v1)
/*  f0d1d3c:	80790037 */ 	lb	$t9,0x37($v1)
/*  f0d1d40:	5320000e */ 	beqzl	$t9,.L0f0d1d7c
/*  f0d1d44:	a0600039 */ 	sb	$zero,0x39($v1)
/*  f0d1d48:	80780039 */ 	lb	$t8,0x39($v1)
/*  f0d1d4c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d1d50:	5700000d */ 	bnezl	$t8,.L0f0d1d88
/*  f0d1d54:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f0d1d58:	a06e0039 */ 	sb	$t6,0x39($v1)
/*  f0d1d5c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1d60:	240f0018 */ 	addiu	$t7,$zero,0x18
/*  f0d1d64:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f0d1d68:	a30f0068 */ 	sb	$t7,0x68($t8)
/*  f0d1d6c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1d70:	10000004 */ 	beqz	$zero,.L0f0d1d84
/*  f0d1d74:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1d78:	a0600039 */ 	sb	$zero,0x39($v1)
.L0f0d1d7c:
/*  f0d1d7c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1d80:	8f230480 */ 	lw	$v1,0x480($t9)
.L0f0d1d84:
/*  f0d1d84:	8faf00a4 */ 	lw	$t7,0xa4($sp)
.L0f0d1d88:
/*  f0d1d88:	3c0a8007 */ 	lui	$t2,%hi(var80070ec0)
/*  f0d1d8c:	254a0ec0 */ 	addiu	$t2,$t2,%lo(var80070ec0)
/*  f0d1d90:	51e0000d */ 	beqzl	$t7,.L0f0d1dc8
/*  f0d1d94:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0d1d98:	80780037 */ 	lb	$t8,0x37($v1)
/*  f0d1d9c:	5300000a */ 	beqzl	$t8,.L0f0d1dc8
/*  f0d1da0:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0d1da4:	a0600037 */ 	sb	$zero,0x37($v1)
/*  f0d1da8:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d1dac:	2401fffb */ 	addiu	$at,$zero,-5
/*  f0d1db0:	8dae00c4 */ 	lw	$t6,0xc4($t5)
/*  f0d1db4:	01c1c824 */ 	and	$t9,$t6,$at
/*  f0d1db8:	adb900c4 */ 	sw	$t9,0xc4($t5)
/*  f0d1dbc:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1dc0:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1dc4:	8fb800a0 */ 	lw	$t8,0xa0($sp)
.L0f0d1dc8:
/*  f0d1dc8:	53000011 */ 	beqzl	$t8,.L0f0d1e10
/*  f0d1dcc:	a060006a */ 	sb	$zero,0x6a($v1)
/*  f0d1dd0:	806e0037 */ 	lb	$t6,0x37($v1)
/*  f0d1dd4:	51c0000e */ 	beqzl	$t6,.L0f0d1e10
/*  f0d1dd8:	a060006a */ 	sb	$zero,0x6a($v1)
/*  f0d1ddc:	80790038 */ 	lb	$t9,0x38($v1)
/*  f0d1de0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d1de4:	17200007 */ 	bnez	$t9,.L0f0d1e04
/*  f0d1de8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1dec:	a06f0038 */ 	sb	$t7,0x38($v1)
/*  f0d1df0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1df4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1df8:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f0d1dfc:	10000007 */ 	beqz	$zero,.L0f0d1e1c
/*  f0d1e00:	a338006a */ 	sb	$t8,0x6a($t9)
.L0f0d1e04:
/*  f0d1e04:	10000005 */ 	beqz	$zero,.L0f0d1e1c
/*  f0d1e08:	a060006a */ 	sb	$zero,0x6a($v1)
/*  f0d1e0c:	a060006a */ 	sb	$zero,0x6a($v1)
.L0f0d1e10:
/*  f0d1e10:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1e14:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f0d1e18:	a1c00038 */ 	sb	$zero,0x38($t6)
.L0f0d1e1c:
/*  f0d1e1c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1e20:	3c188007 */ 	lui	$t8,%hi(var80070ec4)
/*  f0d1e24:	93180ec4 */ 	lbu	$t8,%lo(var80070ec4)($t8)
/*  f0d1e28:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d1e2c:	a1f80069 */ 	sb	$t8,0x69($t7)
/*  f0d1e30:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d1e34:	8da30480 */ 	lw	$v1,0x480($t5)
/*  f0d1e38:	806e0037 */ 	lb	$t6,0x37($v1)
/*  f0d1e3c:	55c0002a */ 	bnezl	$t6,.L0f0d1ee8
/*  f0d1e40:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d1e44:	91590000 */ 	lbu	$t9,0x0($t2)
/*  f0d1e48:	240e0022 */ 	addiu	$t6,$zero,0x22
/*  f0d1e4c:	57200026 */ 	bnezl	$t9,.L0f0d1ee8
/*  f0d1e50:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d1e54:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f0d1e58:	8da800bc */ 	lw	$t0,0xbc($t5)
/*  f0d1e5c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1e60:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0d1e64:	c5080008 */ 	lwc1	$f8,0x8($t0)
/*  f0d1e68:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0d1e6c:	c5040010 */ 	lwc1	$f4,0x10($t0)
/*  f0d1e70:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f0d1e74:	a1580000 */ 	sb	$t8,0x0($t2)
/*  f0d1e78:	3c017f1b */ 	lui	$at,%hi(var7f1adb00)
/*  f0d1e7c:	46043081 */ 	sub.s	$f2,$f6,$f4
/*  f0d1e80:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f0d1e84:	c42adb00 */ 	lwc1	$f10,%lo(var7f1adb00)($at)
/*  f0d1e88:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f0d1e8c:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0d1e90:	4604503c */ 	c.lt.s	$f10,$f4
/*  f0d1e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1e98:	45020003 */ 	bc1fl	.L0f0d1ea8
/*  f0d1e9c:	8daf0480 */ 	lw	$t7,0x480($t5)
/*  f0d1ea0:	a1400000 */ 	sb	$zero,0x0($t2)
/*  f0d1ea4:	8daf0480 */ 	lw	$t7,0x480($t5)
.L0f0d1ea8:
/*  f0d1ea8:	8da800bc */ 	lw	$t0,0xbc($t5)
/*  f0d1eac:	2419001c */ 	addiu	$t9,$zero,0x1c
/*  f0d1eb0:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f0d1eb4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0d1eb8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0d1ebc:	25040008 */ 	addiu	$a0,$t0,0x8
/*  f0d1ec0:	25050028 */ 	addiu	$a1,$t0,0x28
/*  f0d1ec4:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f0d1ec8:	0c00b70f */ 	jal	hasLineOfSight
/*  f0d1ecc:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f0d1ed0:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1ed4:	14400003 */ 	bnez	$v0,.L0f0d1ee4
/*  f0d1ed8:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1edc:	3c018007 */ 	lui	$at,%hi(var80070ec0)
/*  f0d1ee0:	a0200ec0 */ 	sb	$zero,%lo(var80070ec0)($at)
.L0f0d1ee4:
/*  f0d1ee4:	8d2d0284 */ 	lw	$t5,0x284($t1)
.L0f0d1ee8:
/*  f0d1ee8:	3c0a8007 */ 	lui	$t2,%hi(var80070ec0)
/*  f0d1eec:	254a0ec0 */ 	addiu	$t2,$t2,%lo(var80070ec0)
/*  f0d1ef0:	8db80480 */ 	lw	$t8,0x480($t5)
/*  f0d1ef4:	830f0037 */ 	lb	$t7,0x37($t8)
/*  f0d1ef8:	51e00003 */ 	beqzl	$t7,.L0f0d1f08
/*  f0d1efc:	914e0000 */ 	lbu	$t6,0x0($t2)
/*  f0d1f00:	a1400000 */ 	sb	$zero,0x0($t2)
/*  f0d1f04:	914e0000 */ 	lbu	$t6,0x0($t2)
.L0f0d1f08:
/*  f0d1f08:	51c0002a */ 	beqzl	$t6,.L0f0d1fb4
/*  f0d1f0c:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0d1f10:	8db90480 */ 	lw	$t9,0x480($t5)
/*  f0d1f14:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1f18:	2404002e */ 	addiu	$a0,$zero,0x2e
/*  f0d1f1c:	a3200035 */ 	sb	$zero,0x35($t9)
/*  f0d1f20:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1f24:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f0d1f28:	a1d80034 */ 	sb	$t8,0x34($t6)
/*  f0d1f2c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1f30:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d1f34:	a1e00037 */ 	sb	$zero,0x37($t7)
/*  f0d1f38:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0d1f3c:	8f0e0018 */ 	lw	$t6,0x18($t8)
/*  f0d1f40:	35d90400 */ 	ori	$t9,$t6,0x400
/*  f0d1f44:	372f0010 */ 	ori	$t7,$t9,0x10
/*  f0d1f48:	af190018 */ 	sw	$t9,0x18($t8)
/*  f0d1f4c:	0fc21f44 */ 	jal	func0f087d10
/*  f0d1f50:	af0f0018 */ 	sw	$t7,0x18($t8)
/*  f0d1f54:	2404002e */ 	addiu	$a0,$zero,0x2e
/*  f0d1f58:	0fc221f2 */ 	jal	currentPlayerQueuePickupWeaponHudmsg
/*  f0d1f5c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d1f60:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1f64:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1f68:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1f6c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0d1f70:	3406ffff */ 	dli	$a2,0xffff
/*  f0d1f74:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f0d1f78:	0fc249af */ 	jal	func0f0926bc
/*  f0d1f7c:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0d1f80:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1f84:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1f88:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1f8c:	8d390338 */ 	lw	$t9,0x338($t1)
/*  f0d1f90:	24010048 */ 	addiu	$at,$zero,0x48
/*  f0d1f94:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d1f98:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f0d1f9c:	01d92023 */ 	subu	$a0,$t6,$t9
/*  f0d1fa0:	0081001a */ 	div	$zero,$a0,$at
/*  f0d1fa4:	00002012 */ 	mflo	$a0
/*  f0d1fa8:	0fc083e4 */ 	jal	propClearReferences
/*  f0d1fac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1fb0:	8fb800e4 */ 	lw	$t8,0xe4($sp)
.L0f0d1fb4:
/*  f0d1fb4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0d1fb8:	8f04001c */ 	lw	$a0,0x1c($t8)
/*  f0d1fbc:	0fc22af5 */ 	jal	func0f08abd4
/*  f0d1fc0:	24840008 */ 	addiu	$a0,$a0,8
/*  f0d1fc4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0d1fc8:
/*  f0d1fc8:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f0d1fcc:	03e00008 */ 	jr	$ra
/*  f0d1fd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1fd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1fd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0d1fdc:	00000000 */ 	sll	$zero,$zero,0x0
);
