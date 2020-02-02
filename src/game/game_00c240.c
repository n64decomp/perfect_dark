#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "game/data/data_000000.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "types.h"
#include "game/game_00c240.h"

GLOBAL_ASM(
glabel func0f00c240
/*  f00c240:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f00c244:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00c248:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f00c24c:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f00c250:	8e040334 */ 	lw	$a0,0x334($s0)
/*  f00c254:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00c258:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c25c:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f00c260:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f00c264:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f00c268:	25c4003f */ 	addiu	$a0,$t6,0x3f
/*  f00c26c:	348f003f */ 	ori	$t7,$a0,0x3f
/*  f00c270:	0c0048f2 */ 	jal	malloc
/*  f00c274:	39e4003f */ 	xori	$a0,$t7,0x3f
/*  f00c278:	ae020338 */ 	sw	$v0,0x338($s0)
/*  f00c27c:	24040340 */ 	addiu	$a0,$zero,0x340
/*  f00c280:	0c0048f2 */ 	jal	malloc
/*  f00c284:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c288:	3c013f80 */ 	lui	$at,0x3f80
/*  f00c28c:	44812000 */ 	mtc1	$at,$f4
/*  f00c290:	ae020348 */ 	sw	$v0,0x348($s0)
/*  f00c294:	3c018007 */ 	lui	$at,0x8007
/*  f00c298:	e4249880 */ 	swc1	$f4,-0x6780($at)
/*  f00c29c:	8e080348 */ 	lw	$t0,0x348($s0)
/*  f00c2a0:	ae00033c */ 	sw	$zero,0x33c($s0)
/*  f00c2a4:	ae000340 */ 	sw	$zero,0x340($s0)
/*  f00c2a8:	ae000354 */ 	sw	$zero,0x354($s0)
/*  f00c2ac:	ae000350 */ 	sw	$zero,0x350($s0)
/*  f00c2b0:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f00c2b4:	8e0b0334 */ 	lw	$t3,0x334($s0)
/*  f00c2b8:	8e090348 */ 	lw	$t1,0x348($s0)
/*  f00c2bc:	8e0a0338 */ 	lw	$t2,0x338($s0)
/*  f00c2c0:	256cffff */ 	addiu	$t4,$t3,-1
/*  f00c2c4:	00002025 */ 	or	$a0,$zero,$zero
/*  f00c2c8:	ae09034c */ 	sw	$t1,0x34c($s0)
/*  f00c2cc:	1980000e */ 	blez	$t4,.L0f00c308
/*  f00c2d0:	ae0a0344 */ 	sw	$t2,0x344($s0)
/*  f00c2d4:	00001825 */ 	or	$v1,$zero,$zero
/*  f00c2d8:	8e020338 */ 	lw	$v0,0x338($s0)
.L0f00c2dc:
/*  f00c2dc:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f00c2e0:	00626821 */ 	addu	$t5,$v1,$v0
/*  f00c2e4:	25ae0048 */ 	addiu	$t6,$t5,0x48
/*  f00c2e8:	00437821 */ 	addu	$t7,$v0,$v1
/*  f00c2ec:	adee0020 */ 	sw	$t6,0x20($t7)
/*  f00c2f0:	8e180334 */ 	lw	$t8,0x334($s0)
/*  f00c2f4:	24630048 */ 	addiu	$v1,$v1,0x48
/*  f00c2f8:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f00c2fc:	0099082a */ 	slt	$at,$a0,$t9
/*  f00c300:	5420fff6 */ 	bnezl	$at,.L0f00c2dc
/*  f00c304:	8e020338 */ 	lw	$v0,0x338($s0)
.L0f00c308:
/*  f00c308:	0fc030e4 */ 	jal	func0f00c390
/*  f00c30c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c310:	8e080318 */ 	lw	$t0,0x318($s0)
/*  f00c314:	340bfffe */ 	dli	$t3,0xfffe
/*  f00c318:	340cffff */ 	dli	$t4,0xffff
/*  f00c31c:	11000004 */ 	beqz	$t0,.L0f00c330
/*  f00c320:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f00c324:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f00c328:	10000003 */ 	beqz	$zero,.L0f00c338
/*  f00c32c:	a2090358 */ 	sb	$t1,0x358($s0)
.L0f00c330:
/*  f00c330:	240a0007 */ 	addiu	$t2,$zero,0x7
/*  f00c334:	a20a0358 */ 	sb	$t2,0x358($s0)
.L0f00c338:
/*  f00c338:	3c04800a */ 	lui	$a0,0x800a
/*  f00c33c:	a2000359 */ 	sb	$zero,0x359($s0)
/*  f00c340:	a200035a */ 	sb	$zero,0x35a($s0)
/*  f00c344:	a200035b */ 	sb	$zero,0x35b($s0)
/*  f00c348:	a60b035c */ 	sh	$t3,0x35c($s0)
/*  f00c34c:	a60c035e */ 	sh	$t4,0x35e($s0)
/*  f00c350:	2484a084 */ 	addiu	$a0,$a0,-24444
/*  f00c354:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f00c358:	24030002 */ 	addiu	$v1,$zero,0x2
.L0f00c35c:
/*  f00c35c:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f00c360:	a4400344 */ 	sh	$zero,0x344($v0)
/*  f00c364:	a4400346 */ 	sh	$zero,0x346($v0)
/*  f00c368:	ac40034c */ 	sw	$zero,0x34c($v0)
/*  f00c36c:	ac400350 */ 	sw	$zero,0x350($v0)
/*  f00c370:	ac400354 */ 	sw	$zero,0x354($v0)
/*  f00c374:	1444fff9 */ 	bne	$v0,$a0,.L0f00c35c
/*  f00c378:	ac430358 */ 	sw	$v1,0x358($v0)
/*  f00c37c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00c380:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00c384:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f00c388:	03e00008 */ 	jr	$ra
/*  f00c38c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f00c390
/*  f00c390:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f00c394:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f00c398:	8ce402bc */ 	lw	$a0,0x2bc($a3)
/*  f00c39c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00c3a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00c3a4:	00047040 */ 	sll	$t6,$a0,0x1
/*  f00c3a8:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f00c3ac:	348f000f */ 	ori	$t7,$a0,0xf
/*  f00c3b0:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f00c3b4:	0c0048f2 */ 	jal	malloc
/*  f00c3b8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c3bc:	3c08800a */ 	lui	$t0,%hi(var8009cda0)
/*  f00c3c0:	2508cda0 */ 	addiu	$t0,$t0,%lo(var8009cda0)
/*  f00c3c4:	ad020000 */ 	sw	$v0,0x0($t0)
/*  f00c3c8:	24041000 */ 	addiu	$a0,$zero,0x1000
/*  f00c3cc:	0c0048f2 */ 	jal	malloc
/*  f00c3d0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c3d4:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f00c3d8:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f00c3dc:	8cf902bc */ 	lw	$t9,0x2bc($a3)
/*  f00c3e0:	3c05800a */ 	lui	$a1,%hi(var8009cda4)
/*  f00c3e4:	24a5cda4 */ 	addiu	$a1,$a1,%lo(var8009cda4)
/*  f00c3e8:	3c08800a */ 	lui	$t0,%hi(var8009cda0)
/*  f00c3ec:	2508cda0 */ 	addiu	$t0,$t0,%lo(var8009cda0)
/*  f00c3f0:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f00c3f4:	1b20000d */ 	blez	$t9,.L0f00c42c
/*  f00c3f8:	00001825 */ 	or	$v1,$zero,$zero
/*  f00c3fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f00c400:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f00c404:	8d0b0000 */ 	lw	$t3,0x0($t0)
.L0f00c408:
/*  f00c408:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00c40c:	01626021 */ 	addu	$t4,$t3,$v0
/*  f00c410:	a5860000 */ 	sh	$a2,0x0($t4)
/*  f00c414:	8ced02bc */ 	lw	$t5,0x2bc($a3)
/*  f00c418:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f00c41c:	006d082a */ 	slt	$at,$v1,$t5
/*  f00c420:	5420fff9 */ 	bnezl	$at,.L0f00c408
/*  f00c424:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f00c428:	00001825 */ 	or	$v1,$zero,$zero
.L0f00c42c:
/*  f00c42c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f00c430:	00003825 */ 	or	$a3,$zero,$zero
/*  f00c434:	240a0100 */ 	addiu	$t2,$zero,0x100
/*  f00c438:	2409fffe */ 	addiu	$t1,$zero,-2
/*  f00c43c:	24040010 */ 	addiu	$a0,$zero,0x10
.L0f00c440:
/*  f00c440:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f00c444:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f00c448:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f00c44c:	a5e90000 */ 	sh	$t1,0x0($t7)
.L0f00c450:
/*  f00c450:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f00c454:	0003c900 */ 	sll	$t9,$v1,0x4
/*  f00c458:	03195821 */ 	addu	$t3,$t8,$t9
/*  f00c45c:	01626021 */ 	addu	$t4,$t3,$v0
/*  f00c460:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f00c464:	1444fffa */ 	bne	$v0,$a0,.L0f00c450
/*  f00c468:	a5860000 */ 	sh	$a2,0x0($t4)
/*  f00c46c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00c470:	146afff3 */ 	bne	$v1,$t2,.L0f00c440
/*  f00c474:	24e70010 */ 	addiu	$a3,$a3,0x10
/*  f00c478:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00c47c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00c480:	03e00008 */ 	jr	$ra
/*  f00c484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00c48c:	00000000 */ 	sll	$zero,$zero,0x0
);
