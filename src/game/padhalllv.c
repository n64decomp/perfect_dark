#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_0601b0.h"
#include "game/game_157db0.h"
#include "game/pad.h"
#include "game/padhalllv.h"
#include "gvars/gvars.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4ae00.h"
#include "types.h"

const char var7f1b3a80[] = "padhalllv.c";

u32 g_WaypointHashes[2] = {0};

void waypointSetHashThing(s32 hash1, s32 hash2)
{
	g_WaypointHashes[0] = hash1;
	g_WaypointHashes[1] = hash2;
}

GLOBAL_ASM(
glabel waypointFindClosestToPos
/*  f114254:	27bdfc60 */ 	addiu	$sp,$sp,-928
/*  f114258:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f11425c:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f114260:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f114264:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f114268:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f11426c:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f114270:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f114274:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f114278:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f11427c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f114280:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f114284:	afa503a4 */ 	sw	$a1,0x3a4($sp)
/*  f114288:	afa0039c */ 	sw	$zero,0x39c($sp)
/*  f11428c:	84af0000 */ 	lh	$t7,0x0($a1)
/*  f114290:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f114294:	0080b025 */ 	or	$s6,$a0,$zero
/*  f114298:	00008825 */ 	or	$s1,$zero,$zero
/*  f11429c:	10ef000a */ 	beq	$a3,$t7,.L0f1142c8
/*  f1142a0:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1142a4:	27b50360 */ 	addiu	$s5,$sp,0x360
/*  f1142a8:	00a08025 */ 	or	$s0,$a1,$zero
/*  f1142ac:	84a40000 */ 	lh	$a0,0x0($a1)
.L0f1142b0:
/*  f1142b0:	a6a40000 */ 	sh	$a0,0x0($s5)
/*  f1142b4:	86040002 */ 	lh	$a0,0x2($s0)
/*  f1142b8:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f1142bc:	26b50002 */ 	addiu	$s5,$s5,0x2
/*  f1142c0:	14e4fffb */ 	bne	$a3,$a0,.L0f1142b0
/*  f1142c4:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f1142c8:
/*  f1142c8:	27b30360 */ 	addiu	$s3,$sp,0x360
/*  f1142cc:	0014c040 */ 	sll	$t8,$s4,0x1
/*  f1142d0:	0278c821 */ 	addu	$t9,$s3,$t8
/*  f1142d4:	a7270000 */ 	sh	$a3,0x0($t9)
/*  f1142d8:	8fa903a4 */ 	lw	$t1,0x3a4($sp)
/*  f1142dc:	27b20348 */ 	addiu	$s2,$sp,0x348
/*  f1142e0:	852a0000 */ 	lh	$t2,0x0($t1)
/*  f1142e4:	01208025 */ 	or	$s0,$t1,$zero
/*  f1142e8:	10ea000f */ 	beq	$a3,$t2,.L0f114328
/*  f1142ec:	00000000 */ 	nop
/*  f1142f0:	85240000 */ 	lh	$a0,0x0($t1)
/*  f1142f4:	02402825 */ 	or	$a1,$s2,$zero
.L0f1142f8:
/*  f1142f8:	0fc5916a */ 	jal	func0f1645a8
/*  f1142fc:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f114300:	02402025 */ 	or	$a0,$s2,$zero
/*  f114304:	02602825 */ 	or	$a1,$s3,$zero
/*  f114308:	0fc195f6 */ 	jal	func0f0657d8
/*  f11430c:	2406001e */ 	addiu	$a2,$zero,0x1e
/*  f114310:	86040002 */ 	lh	$a0,0x2($s0)
/*  f114314:	2401ffff */ 	addiu	$at,$zero,-1
/*  f114318:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f11431c:	5481fff6 */ 	bnel	$a0,$at,.L0f1142f8
/*  f114320:	02402825 */ 	or	$a1,$s2,$zero
/*  f114324:	2407ffff */ 	addiu	$a3,$zero,-1
.L0f114328:
/*  f114328:	3c1e800a */ 	lui	$s8,%hi(g_StageSetup)
/*  f11432c:	27ded030 */ 	addiu	$s8,$s8,%lo(g_StageSetup)
/*  f114330:	8fcb0000 */ 	lw	$t3,0x0($s8)
/*  f114334:	87ac0360 */ 	lh	$t4,0x360($sp)
/*  f114338:	51600128 */ 	beqzl	$t3,.L0f1147dc
/*  f11433c:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f114340:	10ec0068 */ 	beq	$a3,$t4,.L0f1144e4
/*  f114344:	0000a025 */ 	or	$s4,$zero,$zero
/*  f114348:	27b50360 */ 	addiu	$s5,$sp,0x360
/*  f11434c:	3c03800a */ 	lui	$v1,%hi(g_Rooms)
/*  f114350:	8c634928 */ 	lw	$v1,%lo(g_Rooms)($v1)
/*  f114354:	86a40000 */ 	lh	$a0,0x0($s5)
/*  f114358:	2417008c */ 	addiu	$s7,$zero,0x8c
.L0f11435c:
/*  f11435c:	00970019 */ 	multu	$a0,$s7
/*  f114360:	00007812 */ 	mflo	$t7
/*  f114364:	006f1021 */ 	addu	$v0,$v1,$t7
/*  f114368:	90450009 */ 	lbu	$a1,0x9($v0)
/*  f11436c:	50a00058 */ 	beqzl	$a1,.L0f1144d0
/*  f114370:	86a40002 */ 	lh	$a0,0x2($s5)
/*  f114374:	18a00055 */ 	blez	$a1,.L0f1144cc
/*  f114378:	00009825 */ 	or	$s3,$zero,$zero
/*  f11437c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f114380:	9458000c */ 	lhu	$t8,0xc($v0)
.L0f114384:
/*  f114384:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x60)
/*  f114388:	8dcea020 */ 	lw	$t6,%lo(g_Vars+0x60)($t6)
/*  f11438c:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f114390:	8fcc0000 */ 	lw	$t4,0x0($s8)
/*  f114394:	01d95021 */ 	addu	$t2,$t6,$t9
/*  f114398:	01544821 */ 	addu	$t1,$t2,$s4
/*  f11439c:	85300000 */ 	lh	$s0,0x0($t1)
/*  f1143a0:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f1143a4:	27a60170 */ 	addiu	$a2,$sp,0x170
/*  f1143a8:	00105900 */ 	sll	$t3,$s0,0x4
/*  f1143ac:	016c9021 */ 	addu	$s2,$t3,$t4
/*  f1143b0:	0fc456ac */ 	jal	padUnpack
/*  f1143b4:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f1143b8:	c6c80000 */ 	lwc1	$f8,0x0($s6)
/*  f1143bc:	c7aa0170 */ 	lwc1	$f10,0x170($sp)
/*  f1143c0:	c6c40008 */ 	lwc1	$f4,0x8($s6)
/*  f1143c4:	c7a60178 */ 	lwc1	$f6,0x178($sp)
/*  f1143c8:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f1143cc:	c6d00004 */ 	lwc1	$f16,0x4($s6)
/*  f1143d0:	c7b20174 */ 	lwc1	$f18,0x174($sp)
/*  f1143d4:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f1143d8:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f1143dc:	00008025 */ 	or	$s0,$zero,$zero
/*  f1143e0:	46128301 */ 	sub.s	$f12,$f16,$f18
/*  f1143e4:	27a402f0 */ 	addiu	$a0,$sp,0x2f0
/*  f1143e8:	2626ffff */ 	addiu	$a2,$s1,-1
/*  f1143ec:	27ad02f0 */ 	addiu	$t5,$sp,0x2f0
/*  f1143f0:	460c6182 */ 	mul.s	$f6,$f12,$f12
/*  f1143f4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f1143f8:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f1143fc:	1a200009 */ 	blez	$s1,.L0f114424
/*  f114400:	46085380 */ 	add.s	$f14,$f10,$f8
.L0f114404:
/*  f114404:	c4900000 */ 	lwc1	$f16,0x0($a0)
/*  f114408:	4610703c */ 	c.lt.s	$f14,$f16
/*  f11440c:	00000000 */ 	nop
/*  f114410:	45030005 */ 	bc1tl	.L0f114428
/*  f114414:	2a01000a */ 	slti	$at,$s0,0xa
/*  f114418:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11441c:	1611fff9 */ 	bne	$s0,$s1,.L0f114404
/*  f114420:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f114424:
/*  f114424:	2a01000a */ 	slti	$at,$s0,0xa
.L0f114428:
/*  f114428:	1020001c */ 	beqz	$at,.L0f11449c
/*  f11442c:	00104080 */ 	sll	$t0,$s0,0x2
/*  f114430:	28c10009 */ 	slti	$at,$a2,0x9
/*  f114434:	14200002 */ 	bnez	$at,.L0f114440
/*  f114438:	010d2021 */ 	addu	$a0,$t0,$t5
/*  f11443c:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f114440:
/*  f114440:	00d0082a */ 	slt	$at,$a2,$s0
/*  f114444:	14200010 */ 	bnez	$at,.L0f114488
/*  f114448:	03a85021 */ 	addu	$t2,$sp,$t0
/*  f11444c:	00063880 */ 	sll	$a3,$a2,0x2
/*  f114450:	27b802f0 */ 	addiu	$t8,$sp,0x2f0
/*  f114454:	27af0318 */ 	addiu	$t7,$sp,0x318
/*  f114458:	00107080 */ 	sll	$t6,$s0,0x2
/*  f11445c:	01d82821 */ 	addu	$a1,$t6,$t8
/*  f114460:	00ef1821 */ 	addu	$v1,$a3,$t7
/*  f114464:	00f81021 */ 	addu	$v0,$a3,$t8
.L0f114468:
/*  f114468:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f11446c:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f114470:	2442fffc */ 	addiu	$v0,$v0,-4
/*  f114474:	0045082b */ 	sltu	$at,$v0,$a1
/*  f114478:	2463fffc */ 	addiu	$v1,$v1,-4
/*  f11447c:	ac790008 */ 	sw	$t9,0x8($v1)
/*  f114480:	1020fff9 */ 	beqz	$at,.L0f114468
/*  f114484:	e4520008 */ 	swc1	$f18,0x8($v0)
.L0f114488:
/*  f114488:	ad520318 */ 	sw	$s2,0x318($t2)
/*  f11448c:	2a21000a */ 	slti	$at,$s1,0xa
/*  f114490:	10200002 */ 	beqz	$at,.L0f11449c
/*  f114494:	e48e0000 */ 	swc1	$f14,0x0($a0)
/*  f114498:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f11449c:
/*  f11449c:	86a90000 */ 	lh	$t1,0x0($s5)
/*  f1144a0:	3c03800a */ 	lui	$v1,%hi(g_Rooms)
/*  f1144a4:	8c634928 */ 	lw	$v1,%lo(g_Rooms)($v1)
/*  f1144a8:	01370019 */ 	multu	$t1,$s7
/*  f1144ac:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f1144b0:	26940002 */ 	addiu	$s4,$s4,0x2
/*  f1144b4:	00005812 */ 	mflo	$t3
/*  f1144b8:	006b1021 */ 	addu	$v0,$v1,$t3
/*  f1144bc:	904c0009 */ 	lbu	$t4,0x9($v0)
/*  f1144c0:	026c082a */ 	slt	$at,$s3,$t4
/*  f1144c4:	5420ffaf */ 	bnezl	$at,.L0f114384
/*  f1144c8:	9458000c */ 	lhu	$t8,0xc($v0)
.L0f1144cc:
/*  f1144cc:	86a40002 */ 	lh	$a0,0x2($s5)
.L0f1144d0:
/*  f1144d0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1144d4:	26b50002 */ 	addiu	$s5,$s5,0x2
/*  f1144d8:	14e4ffa0 */ 	bne	$a3,$a0,.L0f11435c
/*  f1144dc:	00000000 */ 	nop
/*  f1144e0:	0000a025 */ 	or	$s4,$zero,$zero
.L0f1144e4:
/*  f1144e4:	1a200042 */ 	blez	$s1,.L0f1145f0
/*  f1144e8:	00009825 */ 	or	$s3,$zero,$zero
/*  f1144ec:	4480a000 */ 	mtc1	$zero,$f20
/*  f1144f0:	27b70318 */ 	addiu	$s7,$sp,0x318
/*  f1144f4:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f1144f8:	27b5010c */ 	addiu	$s5,$sp,0x10c
/*  f1144fc:	27b202c8 */ 	addiu	$s2,$sp,0x2c8
/*  f114500:	27b0011c */ 	addiu	$s0,$sp,0x11c
.L0f114504:
/*  f114504:	8eed0000 */ 	lw	$t5,0x0($s7)
/*  f114508:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f11450c:	02003025 */ 	or	$a2,$s0,$zero
/*  f114510:	0fc456ac */ 	jal	padUnpack
/*  f114514:	8da40000 */ 	lw	$a0,0x0($t5)
/*  f114518:	8faf0164 */ 	lw	$t7,0x164($sp)
/*  f11451c:	240effff */ 	addiu	$t6,$zero,-1
/*  f114520:	24180020 */ 	addiu	$t8,$zero,0x20
/*  f114524:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f114528:	a7ae010e */ 	sh	$t6,0x10e($sp)
/*  f11452c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f114530:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f114534:	02c02025 */ 	or	$a0,$s6,$zero
/*  f114538:	8fa503a4 */ 	lw	$a1,0x3a4($sp)
/*  f11453c:	02003025 */ 	or	$a2,$s0,$zero
/*  f114540:	02a03825 */ 	or	$a3,$s5,$zero
/*  f114544:	0c00b70f */ 	jal	hasLineOfSight
/*  f114548:	a7af010c */ 	sh	$t7,0x10c($sp)
/*  f11454c:	10400023 */ 	beqz	$v0,.L0f1145dc
/*  f114550:	02537021 */ 	addu	$t6,$s2,$s3
/*  f114554:	240a0030 */ 	addiu	$t2,$zero,0x30
/*  f114558:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f11455c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f114560:	8fa503a4 */ 	lw	$a1,0x3a4($sp)
/*  f114564:	02003025 */ 	or	$a2,$s0,$zero
/*  f114568:	02a03825 */ 	or	$a3,$s5,$zero
/*  f11456c:	afbe0014 */ 	sw	$s8,0x14($sp)
/*  f114570:	e7b40018 */ 	swc1	$f20,0x18($sp)
/*  f114574:	0c00b62e */ 	jal	func0002d8b8
/*  f114578:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f11457c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f114580:	14410003 */ 	bne	$v0,$at,.L0f114590
/*  f114584:	02534821 */ 	addu	$t1,$s2,$s3
/*  f114588:	10000015 */ 	b	.L0f1145e0
/*  f11458c:	ad200000 */ 	sw	$zero,0x0($t1)
.L0f114590:
/*  f114590:	1440000f */ 	bnez	$v0,.L0f1145d0
/*  f114594:	02535821 */ 	addu	$t3,$s2,$s3
/*  f114598:	00141080 */ 	sll	$v0,$s4,0x2
/*  f11459c:	00541023 */ 	subu	$v0,$v0,$s4
/*  f1145a0:	00021080 */ 	sll	$v0,$v0,0x2
/*  f1145a4:	27ac0250 */ 	addiu	$t4,$sp,0x250
/*  f1145a8:	27ad01d8 */ 	addiu	$t5,$sp,0x1d8
/*  f1145ac:	3c077f1b */ 	lui	$a3,%hi(var7f1b3a80)
/*  f1145b0:	ad7e0000 */ 	sw	$s8,0x0($t3)
/*  f1145b4:	24e73a80 */ 	addiu	$a3,$a3,%lo(var7f1b3a80)
/*  f1145b8:	004d2821 */ 	addu	$a1,$v0,$t5
/*  f1145bc:	004c2021 */ 	addu	$a0,$v0,$t4
/*  f1145c0:	0c009393 */ 	jal	func00024e4c
/*  f1145c4:	240601b9 */ 	addiu	$a2,$zero,0x1b9
/*  f1145c8:	10000006 */ 	b	.L0f1145e4
/*  f1145cc:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f1145d0:
/*  f1145d0:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f1145d4:	10000006 */ 	b	.L0f1145f0
/*  f1145d8:	afaf039c */ 	sw	$t7,0x39c($sp)
.L0f1145dc:
/*  f1145dc:	adc00000 */ 	sw	$zero,0x0($t6)
.L0f1145e0:
/*  f1145e0:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f1145e4:
/*  f1145e4:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f1145e8:	1691ffc6 */ 	bne	$s4,$s1,.L0f114504
/*  f1145ec:	26f70004 */ 	addiu	$s7,$s7,0x4
.L0f1145f0:
/*  f1145f0:	8fb8039c */ 	lw	$t8,0x39c($sp)
/*  f1145f4:	4480a000 */ 	mtc1	$zero,$f20
/*  f1145f8:	57000078 */ 	bnezl	$t8,.L0f1147dc
/*  f1145fc:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f114600:	1a20006f */ 	blez	$s1,.L0f1147c0
/*  f114604:	0000a025 */ 	or	$s4,$zero,$zero
/*  f114608:	00009825 */ 	or	$s3,$zero,$zero
/*  f11460c:	27b502c8 */ 	addiu	$s5,$sp,0x2c8
/*  f114610:	27be008c */ 	addiu	$s8,$sp,0x8c
.L0f114614:
/*  f114614:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f114618:	00141080 */ 	sll	$v0,$s4,0x2
/*  f11461c:	00541023 */ 	subu	$v0,$v0,$s4
/*  f114620:	13200063 */ 	beqz	$t9,.L0f1147b0
/*  f114624:	00021080 */ 	sll	$v0,$v0,0x2
/*  f114628:	27aa0250 */ 	addiu	$t2,$sp,0x250
/*  f11462c:	27a901d8 */ 	addiu	$t1,$sp,0x1d8
/*  f114630:	00499021 */ 	addu	$s2,$v0,$t1
/*  f114634:	004a8021 */ 	addu	$s0,$v0,$t2
/*  f114638:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f11463c:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f114640:	27ab0318 */ 	addiu	$t3,$sp,0x318
/*  f114644:	026bb821 */ 	addu	$s7,$s3,$t3
/*  f114648:	46062032 */ 	c.eq.s	$f4,$f6
/*  f11464c:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f114650:	45020008 */ 	bc1fl	.L0f114674
/*  f114654:	8eec0000 */ 	lw	$t4,0x0($s7)
/*  f114658:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f11465c:	c6480008 */ 	lwc1	$f8,0x8($s2)
/*  f114660:	46085032 */ 	c.eq.s	$f10,$f8
/*  f114664:	00000000 */ 	nop
/*  f114668:	45030052 */ 	bc1tl	.L0f1147b4
/*  f11466c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f114670:	8eec0000 */ 	lw	$t4,0x0($s7)
.L0f114674:
/*  f114674:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f114678:	0fc456ac */ 	jal	padUnpack
/*  f11467c:	8d840000 */ 	lw	$a0,0x0($t4)
/*  f114680:	8fad00fc */ 	lw	$t5,0xfc($sp)
/*  f114684:	240fffff */ 	addiu	$t7,$zero,-1
/*  f114688:	a7af00a6 */ 	sh	$t7,0xa6($sp)
/*  f11468c:	a7ad00a4 */ 	sh	$t5,0xa4($sp)
/*  f114690:	c6520000 */ 	lwc1	$f18,0x0($s2)
/*  f114694:	c6100000 */ 	lwc1	$f16,0x0($s0)
/*  f114698:	e7b4009c */ 	swc1	$f20,0x9c($sp)
/*  f11469c:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f1146a0:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f1146a4:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f1146a8:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f1146ac:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f1146b0:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f1146b4:	e7a200a0 */ 	swc1	$f2,0xa0($sp)
/*  f1146b8:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f1146bc:	0c012974 */ 	jal	sqrtf
/*  f1146c0:	46085300 */ 	add.s	$f12,$f10,$f8
/*  f1146c4:	3c014120 */ 	lui	$at,0x4120
/*  f1146c8:	44818000 */ 	mtc1	$at,$f16
/*  f1146cc:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f1146d0:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*  f1146d4:	46008083 */ 	div.s	$f2,$f16,$f0
/*  f1146d8:	240e0030 */ 	addiu	$t6,$zero,0x30
/*  f1146dc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1146e0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1146e4:	8fa503a4 */ 	lw	$a1,0x3a4($sp)
/*  f1146e8:	03c03025 */ 	or	$a2,$s8,$zero
/*  f1146ec:	27a7007c */ 	addiu	$a3,$sp,0x7c
/*  f1146f0:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f1146f4:	00000000 */ 	nop
/*  f1146f8:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f1146fc:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f114700:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f114704:	c6080000 */ 	lwc1	$f8,0x0($s0)
/*  f114708:	46082400 */ 	add.s	$f16,$f4,$f8
/*  f11470c:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*  f114710:	c6d20004 */ 	lwc1	$f18,0x4($s6)
/*  f114714:	e7b20090 */ 	swc1	$f18,0x90($sp)
/*  f114718:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f11471c:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f114720:	e7b40018 */ 	swc1	$f20,0x18($sp)
/*  f114724:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f114728:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f11472c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f114730:	0c00b610 */ 	jal	func0002d840
/*  f114734:	e7a40094 */ 	swc1	$f4,0x94($sp)
/*  f114738:	10400004 */ 	beqz	$v0,.L0f11474c
/*  f11473c:	c7b00098 */ 	lwc1	$f16,0x98($sp)
/*  f114740:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f114744:	1000001e */ 	b	.L0f1147c0
/*  f114748:	afb9039c */ 	sw	$t9,0x39c($sp)
.L0f11474c:
/*  f11474c:	c6480000 */ 	lwc1	$f8,0x0($s2)
/*  f114750:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f114754:	240a0030 */ 	addiu	$t2,$zero,0x30
/*  f114758:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f11475c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f114760:	02c02025 */ 	or	$a0,$s6,$zero
/*  f114764:	8fa503a4 */ 	lw	$a1,0x3a4($sp)
/*  f114768:	e7b2008c */ 	swc1	$f18,0x8c($sp)
/*  f11476c:	c6ca0004 */ 	lwc1	$f10,0x4($s6)
/*  f114770:	03c03025 */ 	or	$a2,$s8,$zero
/*  f114774:	27a7007c */ 	addiu	$a3,$sp,0x7c
/*  f114778:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f11477c:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f114780:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f114784:	e7b40018 */ 	swc1	$f20,0x18($sp)
/*  f114788:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f11478c:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f114790:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f114794:	0c00b610 */ 	jal	func0002d840
/*  f114798:	e7a80094 */ 	swc1	$f8,0x94($sp)
/*  f11479c:	50400005 */ 	beqzl	$v0,.L0f1147b4
/*  f1147a0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f1147a4:	8eeb0000 */ 	lw	$t3,0x0($s7)
/*  f1147a8:	10000005 */ 	b	.L0f1147c0
/*  f1147ac:	afab039c */ 	sw	$t3,0x39c($sp)
.L0f1147b0:
/*  f1147b0:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f1147b4:
/*  f1147b4:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f1147b8:	1691ff96 */ 	bne	$s4,$s1,.L0f114614
/*  f1147bc:	26b50004 */ 	addiu	$s5,$s5,0x4
.L0f1147c0:
/*  f1147c0:	8fac039c */ 	lw	$t4,0x39c($sp)
/*  f1147c4:	55800005 */ 	bnezl	$t4,.L0f1147dc
/*  f1147c8:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f1147cc:	1a200002 */ 	blez	$s1,.L0f1147d8
/*  f1147d0:	8fad0318 */ 	lw	$t5,0x318($sp)
/*  f1147d4:	afad039c */ 	sw	$t5,0x39c($sp)
.L0f1147d8:
/*  f1147d8:	8fbf0054 */ 	lw	$ra,0x54($sp)
.L0f1147dc:
/*  f1147dc:	8fa2039c */ 	lw	$v0,0x39c($sp)
/*  f1147e0:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f1147e4:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f1147e8:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f1147ec:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f1147f0:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f1147f4:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f1147f8:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f1147fc:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f114800:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f114804:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f114808:	03e00008 */ 	jr	$ra
/*  f11480c:	27bd03a0 */ 	addiu	$sp,$sp,0x3a0
);

struct waygroup *func0f114810(s32 *groupnums, s32 value, u32 mask)
{
	struct waygroup *groups = g_StageSetup.waygroups;
	struct waygroup *best = NULL;

	while (*groupnums >= 0) {
		if ((*groupnums & mask) == 0) {
			struct waygroup *group = &groups[*groupnums & 0x3fff];

			if (group->unk08 == value) {
				best = group;

				if (g_Vars.unk000330 == 0) {
					break;
				}

				if (!g_WaypointHashes[0] && !g_WaypointHashes[1]) {
					if (random() % 2 == 0) {
						break;
					}
				} else {
					u64 sp50 = func0004aea4(g_WaypointHashes[0], 0x20) | g_WaypointHashes[1];

					if (func00012e1c(&sp50) % 2 == 0) {
						break;
					}
				}
			}
		}

		*groupnums++;
	}

	return best;
}

/**
 * For each group number in the given list which matches the mask,
 * assign value to their unk08 if their unk08 has no value (ie. is negative).
 */
void func0f114958(s32 *groupnums, s32 value, u32 mask)
{
	struct waygroup *groups = g_StageSetup.waygroups;

	while (*groupnums >= 0) {
		if ((*groupnums & mask) == 0) {
			struct waygroup *group = &groups[*groupnums & 0x3fff];

			if (group->unk08 < 0) {
				group->unk08 = value;
			}
		}

		groupnums++;
	}
}

/**
 * Iterate the given groups and find any with an unk08 matching arg1.
 * For all groups that match, iterate their neighbouring groups and set their
 * unk08s to arg1 + 1, but only if their groupnum matches the given mask and
 * they have no existing unk08 value.
 *
 * Return true if any matched.
 */
bool func0f1149b0(struct waygroup *group, s32 arg1, u32 mask)
{
	bool result = false;

	while (group->neighbours) {
		if (group->unk08 == arg1) {
			result = true;
			func0f114958(group->neighbours, arg1 + 1, mask);
		}

		group++;
	}

	return result;
}

bool func0f114a2c(struct waygroup *from, struct waygroup *to, struct waygroup *groups, s32 arg3, u32 mask)
{
	bool result = true;
	struct waygroup *group;
	s32 i;

	for (group = groups; group->neighbours; group++) {
		group->unk08 = -1;
	}

	from->unk08 = 0;

	for (i = 0; (arg3 || to->unk08 < 0) && result; i++) {
		result = func0f1149b0(groups, i, mask);
	}

	return result;
}

bool func0f114aec(struct waygroup *from, struct waygroup *to, struct waygroup *groups)
{
	u32 stack[2];
	bool result = func0f114a2c(from, to, groups, 0, 0x8000);

	if (result) {
		struct waygroup *curto = to;
		s32 i = curto->unk08 - 1;

		while (i >= 0) {
			curto->unk08 += 10000;
			curto = func0f114810(curto->neighbours, i, 0x4000);
			i--;
		}

		curto->unk08 += 10000;
	}

	return result;
}

struct waypoint *func0f114b7c(s32 *pointnums, s32 arg1, s32 groupnum, u32 mask)
{
	struct waypoint *points = g_StageSetup.waypoints;
	struct waypoint *best = NULL;

	while (*pointnums >= 0) {
		if ((*pointnums & mask) == 0) {
			struct waypoint *point = &points[*pointnums & 0x3fff];

			if (point->groupnum == groupnum && point->unk0c == arg1) {
				best = point;

				if (g_Vars.unk000330 == 0) {
					break;
				}

				if (!g_WaypointHashes[0] && !g_WaypointHashes[1]) {
					if (random() % 2 == 0) {
						break;
					}
				} else {
					u64 sp50 = func0004aea4(g_WaypointHashes[0], 0x20) | g_WaypointHashes[1];

					if (func00012e1c(&sp50) % 2 == 0) {
						break;
					}
				}
			}
		}

		*pointnums++;
	}

	return best;
}

/**
 * For each pointnum, if it matches the mask, belongs to the given group and has
 * no unk0c, set its unk0c to the given value.
 */
void func0f114ccc(s32 *pointnums, s32 value, s32 groupnum, u32 mask)
{
	struct waypoint *waypoints = g_StageSetup.waypoints;

	while (*pointnums >= 0) {
		if ((*pointnums & mask) == 0) {
			struct waypoint *waypoint = &waypoints[*pointnums & 0x3fff];

			if (waypoint->groupnum == groupnum && waypoint->unk0c < 0) {
				waypoint->unk0c = value;
			}
		}

		*pointnums++;
	}
}

bool func0f114d34(s32 *pointnums, s32 arg1, s32 groupnum, u32 mask)
{
	bool result = false;
	struct waypoint *points = g_StageSetup.waypoints;

	while (*pointnums >= 0) {
		struct waypoint *point = &points[*pointnums];

		if (arg1 == point->unk0c && point->neighbours) {
			result = true;
			func0f114ccc(point->neighbours, arg1 + 1, groupnum, mask);
		}

		pointnums++;
	}

	return result;
}

void func0f114de0(struct waypoint *from, struct waypoint *to, s32 arg2, u32 mask)
{
	struct waygroup *groups = g_StageSetup.waygroups;
	struct waypoint *points = g_StageSetup.waypoints;
	struct waypoint *point;
	s32 *pointnums = groups[from->groupnum].waypoints;
	s32 i;
	bool more;

	while (*pointnums >= 0) {
		point = &points[*pointnums];
		point->unk0c = -1;
		pointnums++;
	}

	from->unk0c = 0;

	more = true;

	for (i = 0; (arg2 || to->unk0c < 0) && more; i++) {
		more = func0f114d34(groups[from->groupnum].waypoints, i, from->groupnum, mask);
	}
}

void func0f114ee4(struct waypoint *from, struct waypoint *to)
{
	struct waypoint *curto;
	s32 value;

	func0f114de0(from, to, 0, 0x8000);

	value = to->unk0c - 1;
	curto = to;

	while (value >= 0) {
		curto->unk0c += 10000;
		curto = func0f114b7c(curto->neighbours, value, from->groupnum, 0x4000);

		value--;
	}

	curto->unk0c += 10000;
}

s32 func0f114f70(struct waypoint *from, struct waypoint *to, struct waypoint **arr, s32 arrlen)
{
	struct waypoint **arrptr = arr;
	struct waypoint *curfrom;
	s32 i;

	if (arrlen >= 2) {
		func0f114ee4(from, to);

		*arr = from;
		arrptr++;

		curfrom = from;
		arrlen += 9999;
		i = 10001;

		while (i <= to->unk0c && i < arrlen) {
			curfrom = func0f114b7c(curfrom->neighbours, i, from->groupnum, 0x8000);
			*arrptr = curfrom;
			arrptr++;
			i++;
		}
	}

	*arrptr = NULL;
	arrptr++;

	return arrptr - arr;
}

void func0f11505c(struct waygroup *groupa, struct waygroup *groupb, struct waypoint **pointa, struct waypoint **pointb)
{
	struct waypoint *points = g_StageSetup.waypoints;
	struct waygroup *groups = g_StageSetup.waygroups;
	s32 *groupapointnums = groupa->waypoints;
	s32 stack;

	*pointb = NULL;
	*pointa = NULL;

	while (*groupapointnums >= 0) {
		struct waypoint *groupapoint = &points[*groupapointnums];
		s32 *neighbournums = groupapoint->neighbours;

		while (*neighbournums >= 0) {
			if ((*neighbournums & 0x8000) == 0) {
				struct waypoint *neighbour = &points[*neighbournums & 0x3fff];

				if (groupb == &groups[neighbour->groupnum]) {
					*pointa = groupapoint;
					*pointb = neighbour;

					if (g_Vars.unk000330 == 0) {
						break;
					}

					if (!g_WaypointHashes[0] && !g_WaypointHashes[1]) {
						if (random() % 2 == 0) {
							break;
						}
					} else {
						u64 sp50 = func0004aea4(g_WaypointHashes[0], 0x20) | g_WaypointHashes[1];

						if ((func00012e1c(&sp50) % 2) == 0) {
							break;
						}
					}
				}
			}

			neighbournums++;
		}

		groupapointnums++;
	}
}

/**
 * Find a route from frompoint to topoint. The arr argument will be populated
 * with pointers to the route's waypoints. If arr is not big enough then only
 * the first part of the route will be populated into the array.
 *
 * The return value is the number of elements populated into the array.
 */
s32 waypointFindRoute(struct waypoint *frompoint, struct waypoint *topoint, struct waypoint **arr, s32 arrlen)
{
	struct waypoint **arrptr = arr;
	struct waygroup *groups = g_StageSetup.waygroups;

	if (groups && frompoint && topoint) {
		struct waygroup *fromgroup = &groups[frompoint->groupnum];
		struct waygroup *togroup = &groups[topoint->groupnum];

		if (func0f114aec(fromgroup, togroup, groups)) {
			struct waypoint *curfrompoint = frompoint;
			struct waygroup *curfromgroup = fromgroup;
			s32 i;

			for (i = fromgroup->unk08 + 1; i <= togroup->unk08 && arrlen >= 2; i++) {
				s32 numwritten;
				struct waygroup *nextfromgroup = func0f114810(curfromgroup->neighbours, i, 0x8000);
				struct waypoint *tmppoint;
				struct waypoint *nextfrompoint;

				func0f11505c(curfromgroup, nextfromgroup, &tmppoint, &nextfrompoint);
				numwritten = func0f114f70(curfrompoint, tmppoint, arrptr, arrlen) - 1;

				arrlen -= numwritten;
				arrptr += numwritten;

				curfrompoint = nextfrompoint;
				curfromgroup = nextfromgroup;
			}

			arrptr += func0f114f70(curfrompoint, topoint, arrptr, arrlen) - 1;
		}
	}

	*arrptr = NULL;
	arrptr++;

	return arrptr - arr;
}

void func0f115390(void)
{
	struct waypoint *waypoint = g_StageSetup.waypoints;

	while (waypoint->padnum >= 0) {
		waypoint->unk0c = -1;
		waypoint++;
	}
}

struct waypoint *func0f1153c4(s32 *pointnums, s32 arg1)
{
	s32 len = 0;
	s32 randomindex;
	s32 i;

	while (pointnums[len] >= 0) {
		len++;
	}

	// This is effectively randomly dividing the pointnums list into two,
	// then checking the upper portion before the lower portion. Both loops
	// have the same logic so this seems unusual, but there is reason to do
	// this if they want the returned waypoint to be any random waypoint that
	// meets the arg1 criteria, with equal weighting.

	randomindex = random() % len;

	for (i = randomindex; i < len; i++) {
		struct waypoint *point = &g_StageSetup.waypoints[pointnums[i] & 0x3fff];

		if (point->unk0c == arg1) {
			return point;
		}
	}

	for (i = 0; i < randomindex; i++) {
		struct waypoint *point = &g_StageSetup.waypoints[pointnums[i] & 0x3fff];

		if (point->unk0c == arg1) {
			return point;
		}
	}

	return NULL;
}

struct waygroup *func0f1154cc(s32 *groupnums, s32 arg1)
{
	s32 len = 0;
	s32 randomindex;
	s32 i;

	while (groupnums[len] >= 0) {
		len++;
	}

	// Similar to the above function, return a random waygroup
	// which matches the arg1 criteria.
	randomindex = random() % len;

	for (i = randomindex; i < len; i++) {
		struct waygroup *group = &g_StageSetup.waygroups[groupnums[i] & 0x3fff];

		if (group->unk08 == arg1) {
			return group;
		}
	}

	for (i = 0; i < randomindex; i++) {
		struct waygroup *group = &g_StageSetup.waygroups[groupnums[i] & 0x3fff];

		if (group->unk08 == arg1) {
			return group;
		}
	}

	return NULL;
}

struct waypoint *func0f1155e0(struct waypoint *pointa, struct waypoint *pointb)
{
	if (g_StageSetup.waygroups) {
		struct waygroup *groupa = &g_StageSetup.waygroups[pointa->groupnum];
		struct waygroup *groupb = &g_StageSetup.waygroups[pointb->groupnum];
		struct waypoint *result;
		s32 stack;

		if (groupa == groupb) {
			func0f115390();
			func0f114de0(pointb, pointa, 1, 0);

			result = func0f1153c4(pointa->neighbours, -1);

			if (result) {
				return result;
			}

			result = func0f1153c4(pointa->neighbours, pointa->unk0c + 1);

			if (result) {
				return result;
			}
		} else {
			func0f114a2c(groupb, groupa, g_StageSetup.waygroups, 0, 0x8000);

			if (groupa->unk08 >= 0) {
				struct waygroup *tmpgroup = func0f1154cc(groupa->neighbours, -1);

				if (tmpgroup) {
					struct waypoint *sp48;
					struct waypoint *sp44;
					struct waypoint *arr[3];

					func0f11505c(groupa, tmpgroup, &sp48, &sp44);

					if (sp48 == pointa) {
						return sp44;
					}

					if (func0f114f70(pointa, sp48, arr, 3) >= 3) {
						return arr[1];
					}
				} else {
					struct waygroup *tmpgroup = func0f114810(groupa->neighbours, groupa->unk08 - 1, 0x8000);

					if (tmpgroup) {
						struct waypoint *sp30;
						struct waypoint *sp2c;

						func0f11505c(groupa, tmpgroup, &sp30, &sp2c);
						func0f114de0(sp30, pointa, 1, 0);
						result = func0f114b7c(pointa->neighbours, pointa->unk0c + 1, pointa->groupnum, 0x8000);

						if (result) {
							return result;
						}
					}
				}
			}
		}
	}

	return NULL;
}

GLOBAL_ASM(
glabel waypointDisableSegmentInDirection
/*  f115784:	3c0b800a */ 	lui	$t3,%hi(g_StageSetup)
/*  f115788:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*  f11578c:	8c8a0004 */ 	lw	$t2,0x4($a0)
/*  f115790:	256bd030 */ 	addiu	$t3,$t3,%lo(g_StageSetup)
/*  f115794:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f115798:	8d490000 */ 	lw	$t1,0x0($t2)
/*  f11579c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1157a0:	8d780004 */ 	lw	$t8,0x4($t3)
/*  f1157a4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1157a8:	00b93023 */ 	subu	$a2,$a1,$t9
/*  f1157ac:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1157b0:	00066103 */ 	sra	$t4,$a2,0x4
/*  f1157b4:	01803025 */ 	or	$a2,$t4,$zero
/*  f1157b8:	8ca20008 */ 	lw	$v0,0x8($a1)
/*  f1157bc:	00003825 */ 	or	$a3,$zero,$zero
/*  f1157c0:	00004025 */ 	or	$t0,$zero,$zero
/*  f1157c4:	0520000c */ 	bltz	$t1,.L0f1157f8
/*  f1157c8:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f1157cc:	312d3fff */ 	andi	$t5,$t1,0x3fff
/*  f1157d0:	118d0009 */ 	beq	$t4,$t5,.L0f1157f8
/*  f1157d4:	00007080 */ 	sll	$t6,$zero,0x2
/*  f1157d8:	014e5821 */ 	addu	$t3,$t2,$t6
/*  f1157dc:	8d690004 */ 	lw	$t1,0x4($t3)
.L0f1157e0:
/*  f1157e0:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f1157e4:	256b0004 */ 	addiu	$t3,$t3,0x4
/*  f1157e8:	05200003 */ 	bltz	$t1,.L0f1157f8
/*  f1157ec:	312f3fff */ 	andi	$t7,$t1,0x3fff
/*  f1157f0:	54cffffb */ 	bnel	$a2,$t7,.L0f1157e0
/*  f1157f4:	8d690004 */ 	lw	$t1,0x4($t3)
.L0f1157f8:
/*  f1157f8:	31383fff */ 	andi	$t8,$t1,0x3fff
/*  f1157fc:	14d8000d */ 	bne	$a2,$t8,.L0f115834
/*  f115800:	00082880 */ 	sll	$a1,$t0,0x2
/*  f115804:	01455821 */ 	addu	$t3,$t2,$a1
/*  f115808:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f11580c:	0722000a */ 	bltzl	$t9,.L0f115838
/*  f115810:	8c650004 */ 	lw	$a1,0x4($v1)
/*  f115814:	8d6c0004 */ 	lw	$t4,0x4($t3)
.L0f115818:
/*  f115818:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f11581c:	ad6c0000 */ 	sw	$t4,0x0($t3)
/*  f115820:	8c8d0004 */ 	lw	$t5,0x4($a0)
/*  f115824:	01a55821 */ 	addu	$t3,$t5,$a1
/*  f115828:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f11582c:	05c3fffa */ 	bgezl	$t6,.L0f115818
/*  f115830:	8d6c0004 */ 	lw	$t4,0x4($t3)
.L0f115834:
/*  f115834:	8c650004 */ 	lw	$a1,0x4($v1)
.L0f115838:
/*  f115838:	00007880 */ 	sll	$t7,$zero,0x2
/*  f11583c:	3c04800a */ 	lui	$a0,%hi(g_StageSetup)
/*  f115840:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f115844:	00af5821 */ 	addu	$t3,$a1,$t7
/*  f115848:	0520001e */ 	bltz	$t1,.L0f1158c4
/*  f11584c:	00000000 */ 	nop
/*  f115850:	8c84d030 */ 	lw	$a0,%lo(g_StageSetup)($a0)
/*  f115854:	0009c100 */ 	sll	$t8,$t1,0x4
.L0f115858:
/*  f115858:	03042821 */ 	addu	$a1,$t8,$a0
/*  f11585c:	8ca80004 */ 	lw	$t0,0x4($a1)
/*  f115860:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f115864:	05220012 */ 	bltzl	$t1,.L0f1158b0
/*  f115868:	8d690004 */ 	lw	$t1,0x4($t3)
/*  f11586c:	14e0000f */ 	bnez	$a3,.L0f1158ac
/*  f115870:	0000c880 */ 	sll	$t9,$zero,0x2
/*  f115874:	01195021 */ 	addu	$t2,$t0,$t9
/*  f115878:	312c3fff */ 	andi	$t4,$t1,0x3fff
.L0f11587c:
/*  f11587c:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f115880:	01a42821 */ 	addu	$a1,$t5,$a0
/*  f115884:	8cae0008 */ 	lw	$t6,0x8($a1)
/*  f115888:	544e0003 */ 	bnel	$v0,$t6,.L0f115898
/*  f11588c:	8d490004 */ 	lw	$t1,0x4($t2)
/*  f115890:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f115894:	8d490004 */ 	lw	$t1,0x4($t2)
.L0f115898:
/*  f115898:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f11589c:	05220004 */ 	bltzl	$t1,.L0f1158b0
/*  f1158a0:	8d690004 */ 	lw	$t1,0x4($t3)
/*  f1158a4:	50e0fff5 */ 	beqzl	$a3,.L0f11587c
/*  f1158a8:	312c3fff */ 	andi	$t4,$t1,0x3fff
.L0f1158ac:
/*  f1158ac:	8d690004 */ 	lw	$t1,0x4($t3)
.L0f1158b0:
/*  f1158b0:	256b0004 */ 	addiu	$t3,$t3,0x4
/*  f1158b4:	05200003 */ 	bltz	$t1,.L0f1158c4
/*  f1158b8:	00000000 */ 	nop
/*  f1158bc:	50e0ffe6 */ 	beqzl	$a3,.L0f115858
/*  f1158c0:	0009c100 */ 	sll	$t8,$t1,0x4
.L0f1158c4:
/*  f1158c4:	14e0001f */ 	bnez	$a3,.L0f115944
/*  f1158c8:	00000000 */ 	nop
/*  f1158cc:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f1158d0:	00004025 */ 	or	$t0,$zero,$zero
/*  f1158d4:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f1158d8:	0520000b */ 	bltz	$t1,.L0f115908
/*  f1158dc:	312f3fff */ 	andi	$t7,$t1,0x3fff
/*  f1158e0:	104f0009 */ 	beq	$v0,$t7,.L0f115908
/*  f1158e4:	0000c080 */ 	sll	$t8,$zero,0x2
/*  f1158e8:	00983021 */ 	addu	$a2,$a0,$t8
/*  f1158ec:	8cc90004 */ 	lw	$t1,0x4($a2)
.L0f1158f0:
/*  f1158f0:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f1158f4:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f1158f8:	05200003 */ 	bltz	$t1,.L0f115908
/*  f1158fc:	31393fff */ 	andi	$t9,$t1,0x3fff
/*  f115900:	5459fffb */ 	bnel	$v0,$t9,.L0f1158f0
/*  f115904:	8cc90004 */ 	lw	$t1,0x4($a2)
.L0f115908:
/*  f115908:	312c3fff */ 	andi	$t4,$t1,0x3fff
/*  f11590c:	144c000d */ 	bne	$v0,$t4,.L0f115944
/*  f115910:	00082880 */ 	sll	$a1,$t0,0x2
/*  f115914:	00853021 */ 	addu	$a2,$a0,$a1
/*  f115918:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f11591c:	05a00009 */ 	bltz	$t5,.L0f115944
/*  f115920:	00000000 */ 	nop
/*  f115924:	8cce0004 */ 	lw	$t6,0x4($a2)
.L0f115928:
/*  f115928:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f11592c:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f115930:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f115934:	01e53021 */ 	addu	$a2,$t7,$a1
/*  f115938:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f11593c:	0703fffa */ 	bgezl	$t8,.L0f115928
/*  f115940:	8cce0004 */ 	lw	$t6,0x4($a2)
.L0f115944:
/*  f115944:	03e00008 */ 	jr	$ra
/*  f115948:	00000000 */ 	nop
);

/**
 * Enable the segment from A to B.
 *
 * This works by adding B to A's neighbour list. If B is already a neighbour of
 * A (ie. segment is already enabled) then no operation is performed.
 *
 * This code assumes that A's neighbours array is big enough to add the new
 * neighbour, which it will be if B was disabled previously.
 */
void waypointEnableSegmentInDirection(struct waypoint *a, struct waypoint *b)
{
	struct waygroup *agroup = &g_StageSetup.waygroups[a->groupnum];
	s32 bpointnum = b - g_StageSetup.waypoints;
	s32 bgroupnum = b->groupnum;
	s32 neighbournum;
	s32 i;

	// Find index in A's neighbour list where B can be added.
	// This will either be at the -1 terminator, or if B already exists in the
	// list then the index of B.
	for (i = 0; (neighbournum = a->neighbours[i]) >= 0 && (neighbournum & 0x3fff) != bpointnum; i++);

	// Add B to A's neighbour list if it doesn't exist
	if ((neighbournum & 0x3fff) != bpointnum) {
		a->neighbours[i] = bpointnum;
		a->neighbours[i + 1] = -1;
	}

	// Now the same for groups. Make sure B's group is a neighbour of A's group.
	for (i = 0; (neighbournum = agroup->neighbours[i]) >= 0 && (neighbournum & 0x3fff) != bgroupnum; i++);

	if (bgroupnum != (neighbournum & 0x3fff)) {
		agroup->neighbours[i] = bgroupnum;
		agroup->neighbours[i + 1] = -1;
	}
}

void waypointDisableSegment(struct waypoint *a, struct waypoint *b)
{
	waypointDisableSegmentInDirection(a, b);
	waypointDisableSegmentInDirection(b, a);
}

void waypointEnableSegment(struct waypoint *a, struct waypoint *b)
{
	waypointEnableSegmentInDirection(a, b);
	waypointEnableSegmentInDirection(b, a);
}
