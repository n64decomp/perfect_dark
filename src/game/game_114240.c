#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_0601b0.h"
#include "game/game_114240.h"
#include "game/game_115ab0.h"
#include "game/game_157db0.h"
#include "library/library.h"

const char var7f1b3a80[] = "padhalllv.c";

const u32 var7f1b3a8c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f114240
/*  f114240:	3c028007 */ 	lui	$v0,%hi(var80075ca0)
/*  f114244:	24425ca0 */ 	addiu	$v0,$v0,%lo(var80075ca0)
/*  f114248:	ac440000 */ 	sw	$a0,0x0($v0)
/*  f11424c:	03e00008 */ 	jr	$ra
/*  f114250:	ac450004 */ 	sw	$a1,0x4($v0)
);

GLOBAL_ASM(
glabel func0f114254
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
/*  f1142ec:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f114328:	3c1e800a */ 	lui	$s8,%hi(var8009d030)
/*  f11432c:	27ded030 */ 	addiu	$s8,$s8,%lo(var8009d030)
/*  f114330:	8fcb0000 */ 	lw	$t3,0x0($s8)
/*  f114334:	87ac0360 */ 	lh	$t4,0x360($sp)
/*  f114338:	51600128 */ 	beqzl	$t3,.L0f1147dc
/*  f11433c:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f114340:	10ec0068 */ 	beq	$a3,$t4,.L0f1144e4
/*  f114344:	0000a025 */ 	or	$s4,$zero,$zero
/*  f114348:	27b50360 */ 	addiu	$s5,$sp,0x360
/*  f11434c:	3c03800a */ 	lui	$v1,%hi(var8009fffc)
/*  f114350:	8c634928 */ 	lw	$v1,0x4928($v1)
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
/*  f114384:	3c0e800a */ 	lui	$t6,0x800a
/*  f114388:	8dcea020 */ 	lw	$t6,-0x5fe0($t6)
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
/*  f11440c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f114478:	2463fffc */ 	addiu	$v1,$v1,%lo(var8009fffc)
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
/*  f1144a0:	3c03800a */ 	lui	$v1,0x800a
/*  f1144a4:	8c634928 */ 	lw	$v1,0x4928($v1)
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
/*  f1144dc:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f114544:	0c00b70f */ 	jal	func0002dc3c
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
/*  f114588:	10000015 */ 	beqz	$zero,.L0f1145e0
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
/*  f1145c8:	10000006 */ 	beqz	$zero,.L0f1145e4
/*  f1145cc:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f1145d0:
/*  f1145d0:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f1145d4:	10000006 */ 	beqz	$zero,.L0f1145f0
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
/*  f114664:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f1146f4:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f114744:	1000001e */ 	beqz	$zero,.L0f1147c0
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
/*  f1147a8:	10000005 */ 	beqz	$zero,.L0f1147c0
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

GLOBAL_ASM(
glabel func0f114810
/*  f114810:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f114814:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f114818:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f11481c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f114820:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f114824:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f114828:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f11482c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f114830:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f114834:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f114838:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11483c:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f114840:	3c15800a */ 	lui	$s5,0x800a
/*  f114844:	00808825 */ 	or	$s1,$a0,$zero
/*  f114848:	00c0b825 */ 	or	$s7,$a2,$zero
/*  f11484c:	00a0f025 */ 	or	$s8,$a1,$zero
/*  f114850:	8eb5d034 */ 	lw	$s5,-0x2fcc($s5)
/*  f114854:	04400033 */ 	bltz	$v0,.L0f114924
/*  f114858:	0000b025 */ 	or	$s6,$zero,$zero
/*  f11485c:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f114860:	3c108007 */ 	lui	$s0,%hi(var80075ca0)
/*  f114864:	26105ca0 */ 	addiu	$s0,$s0,%lo(var80075ca0)
/*  f114868:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f11486c:	27b40050 */ 	addiu	$s4,$sp,0x50
/*  f114870:	2412000c */ 	addiu	$s2,$zero,0xc
/*  f114874:	00577024 */ 	and	$t6,$v0,$s7
.L0f114878:
/*  f114878:	15c00026 */ 	bnez	$t6,.L0f114914
/*  f11487c:	304f3fff */ 	andi	$t7,$v0,0x3fff
/*  f114880:	01f20019 */ 	multu	$t7,$s2
/*  f114884:	0000c012 */ 	mflo	$t8
/*  f114888:	03151821 */ 	addu	$v1,$t8,$s5
/*  f11488c:	8c790008 */ 	lw	$t9,0x8($v1)
/*  f114890:	57d90021 */ 	bnel	$s8,$t9,.L0f114918
/*  f114894:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f114898:	8e680330 */ 	lw	$t0,0x330($s3)
/*  f11489c:	0060b025 */ 	or	$s6,$v1,$zero
/*  f1148a0:	24040000 */ 	addiu	$a0,$zero,0x0
/*  f1148a4:	1100001f */ 	beqz	$t0,.L0f114924
/*  f1148a8:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f1148ac:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f1148b0:	1440000b */ 	bnez	$v0,.L0f1148e0
/*  f1148b4:	00402825 */ 	or	$a1,$v0,$zero
/*  f1148b8:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f1148bc:	15200008 */ 	bnez	$t1,.L0f1148e0
/*  f1148c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1148c4:	0c004b70 */ 	jal	random
/*  f1148c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1148cc:	304a0001 */ 	andi	$t2,$v0,0x1
/*  f1148d0:	55400011 */ 	bnezl	$t2,.L0f114918
/*  f1148d4:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f1148d8:	10000013 */ 	beqz	$zero,.L0f114928
/*  f1148dc:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1148e0:
/*  f1148e0:	0c012ba9 */ 	jal	func0004aea4
/*  f1148e4:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f1148e8:	8e0b0004 */ 	lw	$t3,0x4($s0)
/*  f1148ec:	240c0000 */ 	addiu	$t4,$zero,0x0
/*  f1148f0:	01827025 */ 	or	$t6,$t4,$v0
/*  f1148f4:	01637825 */ 	or	$t7,$t3,$v1
/*  f1148f8:	afaf0054 */ 	sw	$t7,0x54($sp)
/*  f1148fc:	afae0050 */ 	sw	$t6,0x50($sp)
/*  f114900:	0c004b87 */ 	jal	func00012e1c
/*  f114904:	02802025 */ 	or	$a0,$s4,$zero
/*  f114908:	30580001 */ 	andi	$t8,$v0,0x1
/*  f11490c:	53000006 */ 	beqzl	$t8,.L0f114928
/*  f114910:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f114914:
/*  f114914:	8e220004 */ 	lw	$v0,0x4($s1)
.L0f114918:
/*  f114918:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f11491c:	0443ffd6 */ 	bgezl	$v0,.L0f114878
/*  f114920:	00577024 */ 	and	$t6,$v0,$s7
.L0f114924:
/*  f114924:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f114928:
/*  f114928:	02c01025 */ 	or	$v0,$s6,$zero
/*  f11492c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f114930:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f114934:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f114938:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11493c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f114940:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f114944:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f114948:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f11494c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f114950:	03e00008 */ 	jr	$ra
/*  f114954:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f114958
/*  f114958:	8c830000 */ 	lw	$v1,0x0($a0)
/*  f11495c:	3c02800a */ 	lui	$v0,0x800a
/*  f114960:	00a03825 */ 	or	$a3,$a1,$zero
/*  f114964:	04600010 */ 	bltz	$v1,.L0f1149a8
/*  f114968:	8c42d034 */ 	lw	$v0,-0x2fcc($v0)
/*  f11496c:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f114970:	00667024 */ 	and	$t6,$v1,$a2
.L0f114974:
/*  f114974:	15c00008 */ 	bnez	$t6,.L0f114998
/*  f114978:	306f3fff */ 	andi	$t7,$v1,0x3fff
/*  f11497c:	01e80019 */ 	multu	$t7,$t0
/*  f114980:	0000c012 */ 	mflo	$t8
/*  f114984:	03022821 */ 	addu	$a1,$t8,$v0
/*  f114988:	8cb90008 */ 	lw	$t9,0x8($a1)
/*  f11498c:	07230003 */ 	bgezl	$t9,.L0f11499c
/*  f114990:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f114994:	aca70008 */ 	sw	$a3,0x8($a1)
.L0f114998:
/*  f114998:	8c830004 */ 	lw	$v1,0x4($a0)
.L0f11499c:
/*  f11499c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f1149a0:	0463fff4 */ 	bgezl	$v1,.L0f114974
/*  f1149a4:	00667024 */ 	and	$t6,$v1,$a2
.L0f1149a8:
/*  f1149a8:	03e00008 */ 	jr	$ra
/*  f1149ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1149b0
/*  f1149b0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1149b4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1149b8:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1149bc:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1149c0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1149c4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1149c8:	8c870000 */ 	lw	$a3,0x0($a0)
/*  f1149cc:	00808025 */ 	or	$s0,$a0,$zero
/*  f1149d0:	00a08825 */ 	or	$s1,$a1,$zero
/*  f1149d4:	00c09825 */ 	or	$s3,$a2,$zero
/*  f1149d8:	10e0000c */ 	beqz	$a3,.L0f114a0c
/*  f1149dc:	00009025 */ 	or	$s2,$zero,$zero
/*  f1149e0:	8e0e0008 */ 	lw	$t6,0x8($s0)
.L0f1149e4:
/*  f1149e4:	00e02025 */ 	or	$a0,$a3,$zero
/*  f1149e8:	26250001 */ 	addiu	$a1,$s1,0x1
/*  f1149ec:	162e0003 */ 	bne	$s1,$t6,.L0f1149fc
/*  f1149f0:	02603025 */ 	or	$a2,$s3,$zero
/*  f1149f4:	0fc45256 */ 	jal	func0f114958
/*  f1149f8:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f1149fc:
/*  f1149fc:	8e07000c */ 	lw	$a3,0xc($s0)
/*  f114a00:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f114a04:	54e0fff7 */ 	bnezl	$a3,.L0f1149e4
/*  f114a08:	8e0e0008 */ 	lw	$t6,0x8($s0)
.L0f114a0c:
/*  f114a0c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f114a10:	02401025 */ 	or	$v0,$s2,$zero
/*  f114a14:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f114a18:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f114a1c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f114a20:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f114a24:	03e00008 */ 	jr	$ra
/*  f114a28:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f114a2c
/*  f114a2c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f114a30:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f114a34:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f114a38:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f114a3c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f114a40:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f114a44:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f114a48:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f114a4c:	00c09025 */ 	or	$s2,$a2,$zero
/*  f114a50:	00e09825 */ 	or	$s3,$a3,$zero
/*  f114a54:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f114a58:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f114a5c:	11c00007 */ 	beqz	$t6,.L0f114a7c
/*  f114a60:	00c01025 */ 	or	$v0,$a2,$zero
/*  f114a64:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f114a68:	8c4f000c */ 	lw	$t7,0xc($v0)
.L0f114a6c:
/*  f114a6c:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f114a70:	ac43fffc */ 	sw	$v1,-0x4($v0)
/*  f114a74:	55e0fffd */ 	bnezl	$t7,.L0f114a6c
/*  f114a78:	8c4f000c */ 	lw	$t7,0xc($v0)
.L0f114a7c:
/*  f114a7c:	ac800008 */ 	sw	$zero,0x8($a0)
/*  f114a80:	16600004 */ 	bnez	$s3,.L0f114a94
/*  f114a84:	00008025 */ 	or	$s0,$zero,$zero
/*  f114a88:	8e980008 */ 	lw	$t8,0x8($s4)
/*  f114a8c:	0703000f */ 	bgezl	$t8,.L0f114acc
/*  f114a90:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f114a94:
/*  f114a94:	8fb10040 */ 	lw	$s1,0x40($sp)
/*  f114a98:	02402025 */ 	or	$a0,$s2,$zero
.L0f114a9c:
/*  f114a9c:	02002825 */ 	or	$a1,$s0,$zero
/*  f114aa0:	0fc4526c */ 	jal	func0f1149b0
/*  f114aa4:	02203025 */ 	or	$a2,$s1,$zero
/*  f114aa8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f114aac:	16600004 */ 	bnez	$s3,.L0f114ac0
/*  f114ab0:	00404025 */ 	or	$t0,$v0,$zero
/*  f114ab4:	8e990008 */ 	lw	$t9,0x8($s4)
/*  f114ab8:	07230004 */ 	bgezl	$t9,.L0f114acc
/*  f114abc:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f114ac0:
/*  f114ac0:	5500fff6 */ 	bnezl	$t0,.L0f114a9c
/*  f114ac4:	02402025 */ 	or	$a0,$s2,$zero
/*  f114ac8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f114acc:
/*  f114acc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f114ad0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f114ad4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f114ad8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f114adc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f114ae0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f114ae4:	03e00008 */ 	jr	$ra
/*  f114ae8:	01001025 */ 	or	$v0,$t0,$zero
);

GLOBAL_ASM(
glabel func0f114aec
/*  f114aec:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f114af0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f114af4:	340e8000 */ 	dli	$t6,0x8000
/*  f114af8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f114afc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f114b00:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f114b04:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f114b08:	0fc4528b */ 	jal	func0f114a2c
/*  f114b0c:	00003825 */ 	or	$a3,$zero,$zero
/*  f114b10:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f114b14:	10400013 */ 	beqz	$v0,.L0f114b64
/*  f114b18:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f114b1c:	8cb00008 */ 	lw	$s0,0x8($a1)
/*  f114b20:	00a08825 */ 	or	$s1,$a1,$zero
/*  f114b24:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f114b28:	0602000c */ 	bltzl	$s0,.L0f114b5c
/*  f114b2c:	8e390008 */ 	lw	$t9,0x8($s1)
.L0f114b30:
/*  f114b30:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f114b34:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f114b38:	02002825 */ 	or	$a1,$s0,$zero
/*  f114b3c:	25f82710 */ 	addiu	$t8,$t7,0x2710
/*  f114b40:	ae380008 */ 	sw	$t8,0x8($s1)
/*  f114b44:	0fc45204 */ 	jal	func0f114810
/*  f114b48:	24064000 */ 	addiu	$a2,$zero,0x4000
/*  f114b4c:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f114b50:	0601fff7 */ 	bgez	$s0,.L0f114b30
/*  f114b54:	00408825 */ 	or	$s1,$v0,$zero
/*  f114b58:	8e390008 */ 	lw	$t9,0x8($s1)
.L0f114b5c:
/*  f114b5c:	27282710 */ 	addiu	$t0,$t9,0x2710
/*  f114b60:	ae280008 */ 	sw	$t0,0x8($s1)
.L0f114b64:
/*  f114b64:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f114b68:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*  f114b6c:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f114b70:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f114b74:	03e00008 */ 	jr	$ra
/*  f114b78:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f114b7c
/*  f114b7c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f114b80:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f114b84:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f114b88:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f114b8c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f114b90:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f114b94:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f114b98:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f114b9c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f114ba0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f114ba4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f114ba8:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f114bac:	3c14800a */ 	lui	$s4,0x800a
/*  f114bb0:	00808825 */ 	or	$s1,$a0,$zero
/*  f114bb4:	00e0b025 */ 	or	$s6,$a3,$zero
/*  f114bb8:	00c0b825 */ 	or	$s7,$a2,$zero
/*  f114bbc:	00a0f025 */ 	or	$s8,$a1,$zero
/*  f114bc0:	8e94d030 */ 	lw	$s4,-0x2fd0($s4)
/*  f114bc4:	04400034 */ 	bltz	$v0,.L0f114c98
/*  f114bc8:	0000a825 */ 	or	$s5,$zero,$zero
/*  f114bcc:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f114bd0:	3c108007 */ 	lui	$s0,%hi(var80075ca0)
/*  f114bd4:	26105ca0 */ 	addiu	$s0,$s0,%lo(var80075ca0)
/*  f114bd8:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f114bdc:	27b30050 */ 	addiu	$s3,$sp,0x50
/*  f114be0:	00567024 */ 	and	$t6,$v0,$s6
.L0f114be4:
/*  f114be4:	15c00028 */ 	bnez	$t6,.L0f114c88
/*  f114be8:	304f3fff */ 	andi	$t7,$v0,0x3fff
/*  f114bec:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f114bf0:	03141821 */ 	addu	$v1,$t8,$s4
/*  f114bf4:	8c790008 */ 	lw	$t9,0x8($v1)
/*  f114bf8:	56f90024 */ 	bnel	$s7,$t9,.L0f114c8c
/*  f114bfc:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f114c00:	8c68000c */ 	lw	$t0,0xc($v1)
/*  f114c04:	57c80021 */ 	bnel	$s8,$t0,.L0f114c8c
/*  f114c08:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f114c0c:	8e490330 */ 	lw	$t1,0x330($s2)
/*  f114c10:	0060a825 */ 	or	$s5,$v1,$zero
/*  f114c14:	24040000 */ 	addiu	$a0,$zero,0x0
/*  f114c18:	1120001f */ 	beqz	$t1,.L0f114c98
/*  f114c1c:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f114c20:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f114c24:	1440000b */ 	bnez	$v0,.L0f114c54
/*  f114c28:	00402825 */ 	or	$a1,$v0,$zero
/*  f114c2c:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f114c30:	15400008 */ 	bnez	$t2,.L0f114c54
/*  f114c34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f114c38:	0c004b70 */ 	jal	random
/*  f114c3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f114c40:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f114c44:	55600011 */ 	bnezl	$t3,.L0f114c8c
/*  f114c48:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f114c4c:	10000013 */ 	beqz	$zero,.L0f114c9c
/*  f114c50:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f114c54:
/*  f114c54:	0c012ba9 */ 	jal	func0004aea4
/*  f114c58:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f114c5c:	8e0c0004 */ 	lw	$t4,0x4($s0)
/*  f114c60:	240e0000 */ 	addiu	$t6,$zero,0x0
/*  f114c64:	01c2c025 */ 	or	$t8,$t6,$v0
/*  f114c68:	0183c825 */ 	or	$t9,$t4,$v1
/*  f114c6c:	afb90054 */ 	sw	$t9,0x54($sp)
/*  f114c70:	afb80050 */ 	sw	$t8,0x50($sp)
/*  f114c74:	0c004b87 */ 	jal	func00012e1c
/*  f114c78:	02602025 */ 	or	$a0,$s3,$zero
/*  f114c7c:	304d0001 */ 	andi	$t5,$v0,0x1
/*  f114c80:	51a00006 */ 	beqzl	$t5,.L0f114c9c
/*  f114c84:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f114c88:
/*  f114c88:	8e220004 */ 	lw	$v0,0x4($s1)
.L0f114c8c:
/*  f114c8c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f114c90:	0443ffd4 */ 	bgezl	$v0,.L0f114be4
/*  f114c94:	00567024 */ 	and	$t6,$v0,$s6
.L0f114c98:
/*  f114c98:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f114c9c:
/*  f114c9c:	02a01025 */ 	or	$v0,$s5,$zero
/*  f114ca0:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f114ca4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f114ca8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f114cac:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f114cb0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f114cb4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f114cb8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f114cbc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f114cc0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f114cc4:	03e00008 */ 	jr	$ra
/*  f114cc8:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f114ccc
/*  f114ccc:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f114cd0:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f114cd4:	8c830000 */ 	lw	$v1,0x0($a0)
/*  f114cd8:	3c02800a */ 	lui	$v0,0x800a
/*  f114cdc:	00a08025 */ 	or	$s0,$a1,$zero
/*  f114ce0:	04600011 */ 	bltz	$v1,.L0f114d28
/*  f114ce4:	8c42d030 */ 	lw	$v0,-0x2fd0($v0)
/*  f114ce8:	00677024 */ 	and	$t6,$v1,$a3
.L0f114cec:
/*  f114cec:	15c0000a */ 	bnez	$t6,.L0f114d18
/*  f114cf0:	306f3fff */ 	andi	$t7,$v1,0x3fff
/*  f114cf4:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f114cf8:	03022821 */ 	addu	$a1,$t8,$v0
/*  f114cfc:	8cb90008 */ 	lw	$t9,0x8($a1)
/*  f114d00:	54d90006 */ 	bnel	$a2,$t9,.L0f114d1c
/*  f114d04:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f114d08:	8ca8000c */ 	lw	$t0,0xc($a1)
/*  f114d0c:	05030003 */ 	bgezl	$t0,.L0f114d1c
/*  f114d10:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f114d14:	acb0000c */ 	sw	$s0,0xc($a1)
.L0f114d18:
/*  f114d18:	8c830004 */ 	lw	$v1,0x4($a0)
.L0f114d1c:
/*  f114d1c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f114d20:	0463fff2 */ 	bgezl	$v1,.L0f114cec
/*  f114d24:	00677024 */ 	and	$t6,$v1,$a3
.L0f114d28:
/*  f114d28:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f114d2c:	03e00008 */ 	jr	$ra
/*  f114d30:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0f114d34
/*  f114d34:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f114d38:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f114d3c:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f114d40:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f114d44:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f114d48:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f114d4c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f114d50:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f114d54:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f114d58:	3c13800a */ 	lui	$s3,0x800a
/*  f114d5c:	00808025 */ 	or	$s0,$a0,$zero
/*  f114d60:	00a08825 */ 	or	$s1,$a1,$zero
/*  f114d64:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f114d68:	00e0a825 */ 	or	$s5,$a3,$zero
/*  f114d6c:	00009025 */ 	or	$s2,$zero,$zero
/*  f114d70:	04400011 */ 	bltz	$v0,.L0f114db8
/*  f114d74:	8e73d030 */ 	lw	$s3,-0x2fd0($s3)
/*  f114d78:	00027100 */ 	sll	$t6,$v0,0x4
.L0f114d7c:
/*  f114d7c:	01d31821 */ 	addu	$v1,$t6,$s3
/*  f114d80:	8c6f000c */ 	lw	$t7,0xc($v1)
/*  f114d84:	562f0009 */ 	bnel	$s1,$t7,.L0f114dac
/*  f114d88:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f114d8c:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f114d90:	26250001 */ 	addiu	$a1,$s1,0x1
/*  f114d94:	02803025 */ 	or	$a2,$s4,$zero
/*  f114d98:	10800003 */ 	beqz	$a0,.L0f114da8
/*  f114d9c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f114da0:	0fc45333 */ 	jal	func0f114ccc
/*  f114da4:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f114da8:
/*  f114da8:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f114dac:
/*  f114dac:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f114db0:	0443fff2 */ 	bgezl	$v0,.L0f114d7c
/*  f114db4:	00027100 */ 	sll	$t6,$v0,0x4
.L0f114db8:
/*  f114db8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f114dbc:	02401025 */ 	or	$v0,$s2,$zero
/*  f114dc0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f114dc4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f114dc8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f114dcc:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f114dd0:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f114dd4:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f114dd8:	03e00008 */ 	jr	$ra
/*  f114ddc:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f114de0
/*  f114de0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f114de4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f114de8:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f114dec:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f114df0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f114df4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f114df8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f114dfc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f114e00:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f114e04:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*  f114e08:	2416000c */ 	addiu	$s6,$zero,0xc
/*  f114e0c:	3c02800a */ 	lui	$v0,%hi(var8009d030)
/*  f114e10:	01d60019 */ 	multu	$t6,$s6
/*  f114e14:	2442d030 */ 	addiu	$v0,$v0,%lo(var8009d030)
/*  f114e18:	8c510004 */ 	lw	$s1,0x4($v0)
/*  f114e1c:	00809025 */ 	or	$s2,$a0,$zero
/*  f114e20:	00c09825 */ 	or	$s3,$a2,$zero
/*  f114e24:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f114e28:	00e0a825 */ 	or	$s5,$a3,$zero
/*  f114e2c:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f114e30:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f114e34:	00008025 */ 	or	$s0,$zero,$zero
/*  f114e38:	00007812 */ 	mflo	$t7
/*  f114e3c:	022fc021 */ 	addu	$t8,$s1,$t7
/*  f114e40:	8f030004 */ 	lw	$v1,0x4($t8)
/*  f114e44:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f114e48:	05000007 */ 	bltz	$t0,.L0f114e68
/*  f114e4c:	0008c900 */ 	sll	$t9,$t0,0x4
.L0f114e50:
/*  f114e50:	03291021 */ 	addu	$v0,$t9,$t1
/*  f114e54:	ac44000c */ 	sw	$a0,0xc($v0)
/*  f114e58:	8c680004 */ 	lw	$t0,0x4($v1)
/*  f114e5c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f114e60:	0503fffb */ 	bgezl	$t0,.L0f114e50
/*  f114e64:	0008c900 */ 	sll	$t9,$t0,0x4
.L0f114e68:
/*  f114e68:	16600004 */ 	bnez	$s3,.L0f114e7c
/*  f114e6c:	ae40000c */ 	sw	$zero,0xc($s2)
/*  f114e70:	8e8a000c */ 	lw	$t2,0xc($s4)
/*  f114e74:	05430012 */ 	bgezl	$t2,.L0f114ec0
/*  f114e78:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f114e7c:
/*  f114e7c:	8e460008 */ 	lw	$a2,0x8($s2)
.L0f114e80:
/*  f114e80:	02002825 */ 	or	$a1,$s0,$zero
/*  f114e84:	02a03825 */ 	or	$a3,$s5,$zero
/*  f114e88:	00d60019 */ 	multu	$a2,$s6
/*  f114e8c:	00005812 */ 	mflo	$t3
/*  f114e90:	022b6021 */ 	addu	$t4,$s1,$t3
/*  f114e94:	0fc4534d */ 	jal	func0f114d34
/*  f114e98:	8d840004 */ 	lw	$a0,0x4($t4)
/*  f114e9c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f114ea0:	16600004 */ 	bnez	$s3,.L0f114eb4
/*  f114ea4:	00401825 */ 	or	$v1,$v0,$zero
/*  f114ea8:	8e8d000c */ 	lw	$t5,0xc($s4)
/*  f114eac:	05a30004 */ 	bgezl	$t5,.L0f114ec0
/*  f114eb0:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f114eb4:
/*  f114eb4:	5460fff2 */ 	bnezl	$v1,.L0f114e80
/*  f114eb8:	8e460008 */ 	lw	$a2,0x8($s2)
/*  f114ebc:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f114ec0:
/*  f114ec0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f114ec4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f114ec8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f114ecc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f114ed0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f114ed4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f114ed8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f114edc:	03e00008 */ 	jr	$ra
/*  f114ee0:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f114ee4
/*  f114ee4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f114ee8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f114eec:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f114ef0:	00809025 */ 	or	$s2,$a0,$zero
/*  f114ef4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f114ef8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f114efc:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f114f00:	00003025 */ 	or	$a2,$zero,$zero
/*  f114f04:	0fc45378 */ 	jal	func0f114de0
/*  f114f08:	34078000 */ 	dli	$a3,0x8000
/*  f114f0c:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f114f10:	8e30000c */ 	lw	$s0,0xc($s1)
/*  f114f14:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f114f18:	0602000d */ 	bltzl	$s0,.L0f114f50
/*  f114f1c:	8e38000c */ 	lw	$t8,0xc($s1)
.L0f114f20:
/*  f114f20:	8e2e000c */ 	lw	$t6,0xc($s1)
/*  f114f24:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f114f28:	02002825 */ 	or	$a1,$s0,$zero
/*  f114f2c:	25cf2710 */ 	addiu	$t7,$t6,0x2710
/*  f114f30:	ae2f000c */ 	sw	$t7,0xc($s1)
/*  f114f34:	8e460008 */ 	lw	$a2,0x8($s2)
/*  f114f38:	0fc452df */ 	jal	func0f114b7c
/*  f114f3c:	24074000 */ 	addiu	$a3,$zero,0x4000
/*  f114f40:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f114f44:	0601fff6 */ 	bgez	$s0,.L0f114f20
/*  f114f48:	00408825 */ 	or	$s1,$v0,$zero
/*  f114f4c:	8e38000c */ 	lw	$t8,0xc($s1)
.L0f114f50:
/*  f114f50:	27192710 */ 	addiu	$t9,$t8,0x2710
/*  f114f54:	ae39000c */ 	sw	$t9,0xc($s1)
/*  f114f58:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f114f5c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f114f60:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f114f64:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f114f68:	03e00008 */ 	jr	$ra
/*  f114f6c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f114f70
/*  f114f70:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f114f74:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f114f78:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f114f7c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f114f80:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f114f84:	28e10002 */ 	slti	$at,$a3,0x2
/*  f114f88:	00e09825 */ 	or	$s3,$a3,$zero
/*  f114f8c:	0080a025 */ 	or	$s4,$a0,$zero
/*  f114f90:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f114f94:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f114f98:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f114f9c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f114fa0:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f114fa4:	1420001e */ 	bnez	$at,.L0f115020
/*  f114fa8:	00c08825 */ 	or	$s1,$a2,$zero
/*  f114fac:	0fc453b9 */ 	jal	func0f114ee4
/*  f114fb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f114fb4:	8fa20038 */ 	lw	$v0,0x38($sp)
/*  f114fb8:	02809025 */ 	or	$s2,$s4,$zero
/*  f114fbc:	2673270f */ 	addiu	$s3,$s3,0x270f
/*  f114fc0:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f114fc4:	8eae000c */ 	lw	$t6,0xc($s5)
/*  f114fc8:	24102711 */ 	addiu	$s0,$zero,0x2711
/*  f114fcc:	24510004 */ 	addiu	$s1,$v0,0x4
/*  f114fd0:	29c12711 */ 	slti	$at,$t6,0x2711
/*  f114fd4:	14200012 */ 	bnez	$at,.L0f115020
/*  f114fd8:	2a612712 */ 	slti	$at,$s3,0x2712
/*  f114fdc:	54200011 */ 	bnezl	$at,.L0f115024
/*  f114fe0:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f114fe4:	8e440004 */ 	lw	$a0,0x4($s2)
.L0f114fe8:
/*  f114fe8:	02002825 */ 	or	$a1,$s0,$zero
/*  f114fec:	8e860008 */ 	lw	$a2,0x8($s4)
/*  f114ff0:	0fc452df */ 	jal	func0f114b7c
/*  f114ff4:	34078000 */ 	dli	$a3,0x8000
/*  f114ff8:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f114ffc:	8eaf000c */ 	lw	$t7,0xc($s5)
/*  f115000:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f115004:	00409025 */ 	or	$s2,$v0,$zero
/*  f115008:	01f0082a */ 	slt	$at,$t7,$s0
/*  f11500c:	14200004 */ 	bnez	$at,.L0f115020
/*  f115010:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f115014:	0213082a */ 	slt	$at,$s0,$s3
/*  f115018:	5420fff3 */ 	bnezl	$at,.L0f114fe8
/*  f11501c:	8e440004 */ 	lw	$a0,0x4($s2)
.L0f115020:
/*  f115020:	ae200000 */ 	sw	$zero,0x0($s1)
.L0f115024:
/*  f115024:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f115028:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f11502c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f115030:	02381023 */ 	subu	$v0,$s1,$t8
/*  f115034:	0002c883 */ 	sra	$t9,$v0,0x2
/*  f115038:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f11503c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f115040:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f115044:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f115048:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f11504c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f115050:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f115054:	03e00008 */ 	jr	$ra
/*  f115058:	03201025 */ 	or	$v0,$t9,$zero
);

GLOBAL_ASM(
glabel func0f11505c
/*  f11505c:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f115060:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f115064:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f115068:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f11506c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f115070:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f115074:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f115078:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f11507c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f115080:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f115084:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f115088:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f11508c:	3c02800a */ 	lui	$v0,%hi(var8009d030)
/*  f115090:	2442d030 */ 	addiu	$v0,$v0,%lo(var8009d030)
/*  f115094:	8c530000 */ 	lw	$s3,0x0($v0)
/*  f115098:	8c540004 */ 	lw	$s4,0x4($v0)
/*  f11509c:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f1150a0:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f1150a4:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f1150a8:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f1150ac:	00e0a825 */ 	or	$s5,$a3,$zero
/*  f1150b0:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f1150b4:	8de30000 */ 	lw	$v1,0x0($t7)
/*  f1150b8:	00a0b825 */ 	or	$s7,$a1,$zero
/*  f1150bc:	3c118007 */ 	lui	$s1,%hi(var80075ca0)
/*  f1150c0:	0460003e */ 	bltz	$v1,.L0f1151bc
/*  f1150c4:	241e000c */ 	addiu	$s8,$zero,0xc
/*  f1150c8:	26315ca0 */ 	addiu	$s1,$s1,%lo(var80075ca0)
/*  f1150cc:	0003c100 */ 	sll	$t8,$v1,0x4
.L0f1150d0:
/*  f1150d0:	03139021 */ 	addu	$s2,$t8,$s3
/*  f1150d4:	8e500004 */ 	lw	$s0,0x4($s2)
/*  f1150d8:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f1150dc:	04400031 */ 	bltz	$v0,.L0f1151a4
/*  f1150e0:	30598000 */ 	andi	$t9,$v0,0x8000
.L0f1150e4:
/*  f1150e4:	1720002b */ 	bnez	$t9,.L0f115194
/*  f1150e8:	30483fff */ 	andi	$t0,$v0,0x3fff
/*  f1150ec:	00084900 */ 	sll	$t1,$t0,0x4
/*  f1150f0:	01331821 */ 	addu	$v1,$t1,$s3
/*  f1150f4:	8c6a0008 */ 	lw	$t2,0x8($v1)
/*  f1150f8:	3c0d800a */ 	lui	$t5,0x800a
/*  f1150fc:	015e0019 */ 	multu	$t2,$s8
/*  f115100:	00005812 */ 	mflo	$t3
/*  f115104:	01746021 */ 	addu	$t4,$t3,$s4
/*  f115108:	56ec0023 */ 	bnel	$s7,$t4,.L0f115198
/*  f11510c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f115110:	aed20000 */ 	sw	$s2,0x0($s6)
/*  f115114:	aea30000 */ 	sw	$v1,0x0($s5)
/*  f115118:	8dada2f0 */ 	lw	$t5,-0x5d10($t5)
/*  f11511c:	24040000 */ 	addiu	$a0,$zero,0x0
/*  f115120:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f115124:	11a0001f */ 	beqz	$t5,.L0f1151a4
/*  f115128:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11512c:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f115130:	1440000b */ 	bnez	$v0,.L0f115160
/*  f115134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115138:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f11513c:	15c00008 */ 	bnez	$t6,.L0f115160
/*  f115140:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115144:	0c004b70 */ 	jal	random
/*  f115148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11514c:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f115150:	55e00011 */ 	bnezl	$t7,.L0f115198
/*  f115154:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f115158:	10000013 */ 	beqz	$zero,.L0f1151a8
/*  f11515c:	8fac006c */ 	lw	$t4,0x6c($sp)
.L0f115160:
/*  f115160:	0c012ba9 */ 	jal	func0004aea4
/*  f115164:	00402825 */ 	or	$a1,$v0,$zero
/*  f115168:	8e380004 */ 	lw	$t8,0x4($s1)
/*  f11516c:	24080000 */ 	addiu	$t0,$zero,0x0
/*  f115170:	01025025 */ 	or	$t2,$t0,$v0
/*  f115174:	03035825 */ 	or	$t3,$t8,$v1
/*  f115178:	afab0054 */ 	sw	$t3,0x54($sp)
/*  f11517c:	afaa0050 */ 	sw	$t2,0x50($sp)
/*  f115180:	0c004b87 */ 	jal	func00012e1c
/*  f115184:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f115188:	30590001 */ 	andi	$t9,$v0,0x1
/*  f11518c:	53200006 */ 	beqzl	$t9,.L0f1151a8
/*  f115190:	8fac006c */ 	lw	$t4,0x6c($sp)
.L0f115194:
/*  f115194:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f115198:
/*  f115198:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f11519c:	0443ffd1 */ 	bgezl	$v0,.L0f1150e4
/*  f1151a0:	30598000 */ 	andi	$t9,$v0,0x8000
.L0f1151a4:
/*  f1151a4:	8fac006c */ 	lw	$t4,0x6c($sp)
.L0f1151a8:
/*  f1151a8:	258d0004 */ 	addiu	$t5,$t4,0x4
/*  f1151ac:	afad006c */ 	sw	$t5,0x6c($sp)
/*  f1151b0:	8da30000 */ 	lw	$v1,0x0($t5)
/*  f1151b4:	0463ffc6 */ 	bgezl	$v1,.L0f1150d0
/*  f1151b8:	0003c100 */ 	sll	$t8,$v1,0x4
.L0f1151bc:
/*  f1151bc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1151c0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1151c4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1151c8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1151cc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1151d0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1151d4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f1151d8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f1151dc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f1151e0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f1151e4:	03e00008 */ 	jr	$ra
/*  f1151e8:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f1151ec
/*  f1151ec:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f1151f0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1151f4:	3c10800a */ 	lui	$s0,0x800a
/*  f1151f8:	8e10d034 */ 	lw	$s0,-0x2fcc($s0)
/*  f1151fc:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f115200:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f115204:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f115208:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11520c:	00a08825 */ 	or	$s1,$a1,$zero
/*  f115210:	00e09825 */ 	or	$s3,$a3,$zero
/*  f115214:	0080b025 */ 	or	$s6,$a0,$zero
/*  f115218:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f11521c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f115220:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f115224:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f115228:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f11522c:	afa60078 */ 	sw	$a2,0x78($sp)
/*  f115230:	12000045 */ 	beqz	$s0,.L0f115348
/*  f115234:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f115238:	50800044 */ 	beqzl	$a0,.L0f11534c
/*  f11523c:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f115240:	50a00042 */ 	beqzl	$a1,.L0f11534c
/*  f115244:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f115248:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*  f11524c:	2402000c */ 	addiu	$v0,$zero,0xc
/*  f115250:	8cb80008 */ 	lw	$t8,0x8($a1)
/*  f115254:	01c20019 */ 	multu	$t6,$v0
/*  f115258:	afb10074 */ 	sw	$s1,0x74($sp)
/*  f11525c:	02003025 */ 	or	$a2,$s0,$zero
/*  f115260:	00007812 */ 	mflo	$t7
/*  f115264:	01f09021 */ 	addu	$s2,$t7,$s0
/*  f115268:	02402025 */ 	or	$a0,$s2,$zero
/*  f11526c:	03020019 */ 	multu	$t8,$v0
/*  f115270:	0000c812 */ 	mflo	$t9
/*  f115274:	0330f021 */ 	addu	$s8,$t9,$s0
/*  f115278:	0fc452bb */ 	jal	func0f114aec
/*  f11527c:	03c02825 */ 	or	$a1,$s8,$zero
/*  f115280:	50400032 */ 	beqzl	$v0,.L0f11534c
/*  f115284:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f115288:	8e500008 */ 	lw	$s0,0x8($s2)
/*  f11528c:	8fc80008 */ 	lw	$t0,0x8($s8)
/*  f115290:	02c0a825 */ 	or	$s5,$s6,$zero
/*  f115294:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f115298:	0110082a */ 	slt	$at,$t0,$s0
/*  f11529c:	14200022 */ 	bnez	$at,.L0f115328
/*  f1152a0:	02408825 */ 	or	$s1,$s2,$zero
/*  f1152a4:	2a610002 */ 	slti	$at,$s3,0x2
/*  f1152a8:	1420001f */ 	bnez	$at,.L0f115328
/*  f1152ac:	27b70044 */ 	addiu	$s7,$sp,0x44
/*  f1152b0:	27b60048 */ 	addiu	$s6,$sp,0x48
/*  f1152b4:	8e240000 */ 	lw	$a0,0x0($s1)
.L0f1152b8:
/*  f1152b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1152bc:	0fc45204 */ 	jal	func0f114810
/*  f1152c0:	34068000 */ 	dli	$a2,0x8000
/*  f1152c4:	00409025 */ 	or	$s2,$v0,$zero
/*  f1152c8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1152cc:	00402825 */ 	or	$a1,$v0,$zero
/*  f1152d0:	02c03025 */ 	or	$a2,$s6,$zero
/*  f1152d4:	0fc45417 */ 	jal	func0f11505c
/*  f1152d8:	02e03825 */ 	or	$a3,$s7,$zero
/*  f1152dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1152e0:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1152e4:	02803025 */ 	or	$a2,$s4,$zero
/*  f1152e8:	0fc453dc */ 	jal	func0f114f70
/*  f1152ec:	02603825 */ 	or	$a3,$s3,$zero
/*  f1152f0:	8fcb0008 */ 	lw	$t3,0x8($s8)
/*  f1152f4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1152f8:	2449ffff */ 	addiu	$t1,$v0,-1
/*  f1152fc:	02629823 */ 	subu	$s3,$s3,$v0
/*  f115300:	00095080 */ 	sll	$t2,$t1,0x2
/*  f115304:	0170082a */ 	slt	$at,$t3,$s0
/*  f115308:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f11530c:	028aa021 */ 	addu	$s4,$s4,$t2
/*  f115310:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f115314:	14200004 */ 	bnez	$at,.L0f115328
/*  f115318:	02408825 */ 	or	$s1,$s2,$zero
/*  f11531c:	2a610002 */ 	slti	$at,$s3,0x2
/*  f115320:	5020ffe5 */ 	beqzl	$at,.L0f1152b8
/*  f115324:	8e240000 */ 	lw	$a0,0x0($s1)
.L0f115328:
/*  f115328:	02a02025 */ 	or	$a0,$s5,$zero
/*  f11532c:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f115330:	02803025 */ 	or	$a2,$s4,$zero
/*  f115334:	0fc453dc */ 	jal	func0f114f70
/*  f115338:	02603825 */ 	or	$a3,$s3,$zero
/*  f11533c:	244cffff */ 	addiu	$t4,$v0,-1
/*  f115340:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f115344:	028da021 */ 	addu	$s4,$s4,$t5
.L0f115348:
/*  f115348:	ae800000 */ 	sw	$zero,0x0($s4)
.L0f11534c:
/*  f11534c:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f115350:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f115354:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f115358:	028e1023 */ 	subu	$v0,$s4,$t6
/*  f11535c:	00027883 */ 	sra	$t7,$v0,0x2
/*  f115360:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f115364:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f115368:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f11536c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f115370:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f115374:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f115378:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11537c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f115380:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f115384:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f115388:	03e00008 */ 	jr	$ra
/*  f11538c:	01e01025 */ 	or	$v0,$t7,$zero
);

GLOBAL_ASM(
glabel func0f115390
/*  f115390:	3c02800a */ 	lui	$v0,%hi(var800a0010)
/*  f115394:	8c42d030 */ 	lw	$v0,-0x2fd0($v0)
/*  f115398:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f11539c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f1153a0:	05c00006 */ 	bltz	$t6,.L0f1153bc
/*  f1153a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1153a8:	8c4f0010 */ 	lw	$t7,0x10($v0)
.L0f1153ac:
/*  f1153ac:	ac43000c */ 	sw	$v1,0xc($v0)
/*  f1153b0:	24420010 */ 	addiu	$v0,$v0,%lo(var800a0010)
/*  f1153b4:	05e3fffd */ 	bgezl	$t7,.L0f1153ac
/*  f1153b8:	8c4f0010 */ 	lw	$t7,0x10($v0)
.L0f1153bc:
/*  f1153bc:	03e00008 */ 	jr	$ra
/*  f1153c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1153c4
/*  f1153c4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1153c8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1153cc:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f1153d0:	00a03825 */ 	or	$a3,$a1,$zero
/*  f1153d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1153d8:	05c00006 */ 	bltz	$t6,.L0f1153f4
/*  f1153dc:	00801025 */ 	or	$v0,$a0,$zero
/*  f1153e0:	8c4f0004 */ 	lw	$t7,0x4($v0)
.L0f1153e4:
/*  f1153e4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1153e8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1153ec:	05e3fffd */ 	bgezl	$t7,.L0f1153e4
/*  f1153f0:	8c4f0004 */ 	lw	$t7,0x4($v0)
.L0f1153f4:
/*  f1153f4:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1153f8:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f1153fc:	0c004b70 */ 	jal	random
/*  f115400:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f115404:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f115408:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f11540c:	8faa0020 */ 	lw	$t2,0x20($sp)
/*  f115410:	0046001b */ 	divu	$zero,$v0,$a2
/*  f115414:	00004810 */ 	mfhi	$t1
/*  f115418:	0126082a */ 	slt	$at,$t1,$a2
/*  f11541c:	14c00002 */ 	bnez	$a2,.L0f115428
/*  f115420:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115424:	0007000d */ 	break	0x7
.L0f115428:
/*  f115428:	01204025 */ 	or	$t0,$t1,$zero
/*  f11542c:	10200011 */ 	beqz	$at,.L0f115474
/*  f115430:	01201825 */ 	or	$v1,$t1,$zero
/*  f115434:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f115438:	3c05800a */ 	lui	$a1,0x800a
/*  f11543c:	8ca5d030 */ 	lw	$a1,-0x2fd0($a1)
/*  f115440:	01581021 */ 	addu	$v0,$t2,$t8
.L0f115444:
/*  f115444:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f115448:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11544c:	332b3fff */ 	andi	$t3,$t9,0x3fff
/*  f115450:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f115454:	01852021 */ 	addu	$a0,$t4,$a1
/*  f115458:	8c8d000c */ 	lw	$t5,0xc($a0)
/*  f11545c:	14ed0003 */ 	bne	$a3,$t5,.L0f11546c
/*  f115460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115464:	10000015 */ 	beqz	$zero,.L0f1154bc
/*  f115468:	00801025 */ 	or	$v0,$a0,$zero
.L0f11546c:
/*  f11546c:	1466fff5 */ 	bne	$v1,$a2,.L0f115444
/*  f115470:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f115474:
/*  f115474:	19200010 */ 	blez	$t1,.L0f1154b8
/*  f115478:	00001825 */ 	or	$v1,$zero,$zero
/*  f11547c:	3c05800a */ 	lui	$a1,0x800a
/*  f115480:	8ca5d030 */ 	lw	$a1,-0x2fd0($a1)
/*  f115484:	01401025 */ 	or	$v0,$t2,$zero
.L0f115488:
/*  f115488:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f11548c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f115490:	31cf3fff */ 	andi	$t7,$t6,0x3fff
/*  f115494:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f115498:	03052021 */ 	addu	$a0,$t8,$a1
/*  f11549c:	8c99000c */ 	lw	$t9,0xc($a0)
/*  f1154a0:	14f90003 */ 	bne	$a3,$t9,.L0f1154b0
/*  f1154a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1154a8:	10000004 */ 	beqz	$zero,.L0f1154bc
/*  f1154ac:	00801025 */ 	or	$v0,$a0,$zero
.L0f1154b0:
/*  f1154b0:	1468fff5 */ 	bne	$v1,$t0,.L0f115488
/*  f1154b4:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f1154b8:
/*  f1154b8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1154bc:
/*  f1154bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1154c0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1154c4:	03e00008 */ 	jr	$ra
/*  f1154c8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1154cc
/*  f1154cc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1154d0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1154d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1154d8:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f1154dc:	00a08025 */ 	or	$s0,$a1,$zero
/*  f1154e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f1154e4:	05c00006 */ 	bltz	$t6,.L0f115500
/*  f1154e8:	00801025 */ 	or	$v0,$a0,$zero
/*  f1154ec:	8c4f0004 */ 	lw	$t7,0x4($v0)
.L0f1154f0:
/*  f1154f0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1154f4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1154f8:	05e3fffd */ 	bgezl	$t7,.L0f1154f0
/*  f1154fc:	8c4f0004 */ 	lw	$t7,0x4($v0)
.L0f115500:
/*  f115500:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f115504:	0c004b70 */ 	jal	random
/*  f115508:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f11550c:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f115510:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f115514:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f115518:	0046001b */ 	divu	$zero,$v0,$a2
/*  f11551c:	00004810 */ 	mfhi	$t1
/*  f115520:	0126082a */ 	slt	$at,$t1,$a2
/*  f115524:	14c00002 */ 	bnez	$a2,.L0f115530
/*  f115528:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11552c:	0007000d */ 	break	0x7
.L0f115530:
/*  f115530:	01204025 */ 	or	$t0,$t1,$zero
/*  f115534:	10200013 */ 	beqz	$at,.L0f115584
/*  f115538:	01201825 */ 	or	$v1,$t1,$zero
/*  f11553c:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f115540:	3c05800a */ 	lui	$a1,0x800a
/*  f115544:	8ca5d034 */ 	lw	$a1,-0x2fcc($a1)
/*  f115548:	01581021 */ 	addu	$v0,$t2,$t8
/*  f11554c:	2407000c */ 	addiu	$a3,$zero,0xc
.L0f115550:
/*  f115550:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f115554:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f115558:	332b3fff */ 	andi	$t3,$t9,0x3fff
/*  f11555c:	01670019 */ 	multu	$t3,$a3
/*  f115560:	00006012 */ 	mflo	$t4
/*  f115564:	01852021 */ 	addu	$a0,$t4,$a1
/*  f115568:	8c8d0008 */ 	lw	$t5,0x8($a0)
/*  f11556c:	160d0003 */ 	bne	$s0,$t5,.L0f11557c
/*  f115570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115574:	10000017 */ 	beqz	$zero,.L0f1155d4
/*  f115578:	00801025 */ 	or	$v0,$a0,$zero
.L0f11557c:
/*  f11557c:	1466fff4 */ 	bne	$v1,$a2,.L0f115550
/*  f115580:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f115584:
/*  f115584:	2407000c */ 	addiu	$a3,$zero,0xc
/*  f115588:	19200011 */ 	blez	$t1,.L0f1155d0
/*  f11558c:	00001825 */ 	or	$v1,$zero,$zero
/*  f115590:	3c05800a */ 	lui	$a1,0x800a
/*  f115594:	8ca5d034 */ 	lw	$a1,-0x2fcc($a1)
/*  f115598:	01401025 */ 	or	$v0,$t2,$zero
.L0f11559c:
/*  f11559c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f1155a0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1155a4:	31cf3fff */ 	andi	$t7,$t6,0x3fff
/*  f1155a8:	01e70019 */ 	multu	$t7,$a3
/*  f1155ac:	0000c012 */ 	mflo	$t8
/*  f1155b0:	03052021 */ 	addu	$a0,$t8,$a1
/*  f1155b4:	8c990008 */ 	lw	$t9,0x8($a0)
/*  f1155b8:	16190003 */ 	bne	$s0,$t9,.L0f1155c8
/*  f1155bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1155c0:	10000004 */ 	beqz	$zero,.L0f1155d4
/*  f1155c4:	00801025 */ 	or	$v0,$a0,$zero
.L0f1155c8:
/*  f1155c8:	1468fff4 */ 	bne	$v1,$t0,.L0f11559c
/*  f1155cc:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f1155d0:
/*  f1155d0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1155d4:
/*  f1155d4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1155d8:	03e00008 */ 	jr	$ra
/*  f1155dc:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1155e0
/*  f1155e0:	3c06800a */ 	lui	$a2,0x800a
/*  f1155e4:	8cc6d034 */ 	lw	$a2,-0x2fcc($a2)
/*  f1155e8:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f1155ec:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f1155f0:	00808825 */ 	or	$s1,$a0,$zero
/*  f1155f4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1155f8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1155fc:	10c0005b */ 	beqz	$a2,.L0f11576c
/*  f115600:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f115604:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*  f115608:	2402000c */ 	addiu	$v0,$zero,0xc
/*  f11560c:	8cb90008 */ 	lw	$t9,0x8($a1)
/*  f115610:	01c20019 */ 	multu	$t6,$v0
/*  f115614:	00003825 */ 	or	$a3,$zero,$zero
/*  f115618:	34098000 */ 	dli	$t1,0x8000
/*  f11561c:	00007812 */ 	mflo	$t7
/*  f115620:	01e68021 */ 	addu	$s0,$t7,$a2
/*  f115624:	02002825 */ 	or	$a1,$s0,$zero
/*  f115628:	03220019 */ 	multu	$t9,$v0
/*  f11562c:	00004012 */ 	mflo	$t0
/*  f115630:	01062021 */ 	addu	$a0,$t0,$a2
/*  f115634:	16040017 */ 	bne	$s0,$a0,.L0f115694
/*  f115638:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11563c:	0fc454e4 */ 	jal	func0f115390
/*  f115640:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115644:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f115648:	02202825 */ 	or	$a1,$s1,$zero
/*  f11564c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f115650:	0fc45378 */ 	jal	func0f114de0
/*  f115654:	00003825 */ 	or	$a3,$zero,$zero
/*  f115658:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f11565c:	0fc454f1 */ 	jal	func0f1153c4
/*  f115660:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f115664:	50400004 */ 	beqzl	$v0,.L0f115678
/*  f115668:	8e25000c */ 	lw	$a1,0xc($s1)
/*  f11566c:	10000041 */ 	beqz	$zero,.L0f115774
/*  f115670:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f115674:	8e25000c */ 	lw	$a1,0xc($s1)
.L0f115678:
/*  f115678:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f11567c:	0fc454f1 */ 	jal	func0f1153c4
/*  f115680:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f115684:	5040003a */ 	beqzl	$v0,.L0f115770
/*  f115688:	00001025 */ 	or	$v0,$zero,$zero
/*  f11568c:	10000039 */ 	beqz	$zero,.L0f115774
/*  f115690:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f115694:
/*  f115694:	0fc4528b */ 	jal	func0f114a2c
/*  f115698:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f11569c:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f1156a0:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1156a4:	05420032 */ 	bltzl	$t2,.L0f115770
/*  f1156a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1156ac:	0fc45533 */ 	jal	func0f1154cc
/*  f1156b0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f1156b4:	10400013 */ 	beqz	$v0,.L0f115704
/*  f1156b8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1156bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1156c0:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f1156c4:	0fc45417 */ 	jal	func0f11505c
/*  f1156c8:	27a70044 */ 	addiu	$a3,$sp,0x44
/*  f1156cc:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1156d0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1156d4:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f1156d8:	14b10003 */ 	bne	$a1,$s1,.L0f1156e8
/*  f1156dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1156e0:	10000023 */ 	beqz	$zero,.L0f115770
/*  f1156e4:	8fa20044 */ 	lw	$v0,0x44($sp)
.L0f1156e8:
/*  f1156e8:	0fc453dc */ 	jal	func0f114f70
/*  f1156ec:	24070003 */ 	addiu	$a3,$zero,0x3
/*  f1156f0:	28410003 */ 	slti	$at,$v0,0x3
/*  f1156f4:	5420001e */ 	bnezl	$at,.L0f115770
/*  f1156f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1156fc:	1000001c */ 	beqz	$zero,.L0f115770
/*  f115700:	8fa2003c */ 	lw	$v0,0x3c($sp)
.L0f115704:
/*  f115704:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f115708:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f11570c:	34068000 */ 	dli	$a2,0x8000
/*  f115710:	0fc45204 */ 	jal	func0f114810
/*  f115714:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f115718:	10400014 */ 	beqz	$v0,.L0f11576c
/*  f11571c:	00402825 */ 	or	$a1,$v0,$zero
/*  f115720:	02002025 */ 	or	$a0,$s0,$zero
/*  f115724:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f115728:	0fc45417 */ 	jal	func0f11505c
/*  f11572c:	27a7002c */ 	addiu	$a3,$sp,0x2c
/*  f115730:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f115734:	02202825 */ 	or	$a1,$s1,$zero
/*  f115738:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f11573c:	0fc45378 */ 	jal	func0f114de0
/*  f115740:	00003825 */ 	or	$a3,$zero,$zero
/*  f115744:	8e25000c */ 	lw	$a1,0xc($s1)
/*  f115748:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f11574c:	8e260008 */ 	lw	$a2,0x8($s1)
/*  f115750:	34078000 */ 	dli	$a3,0x8000
/*  f115754:	0fc452df */ 	jal	func0f114b7c
/*  f115758:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f11575c:	50400004 */ 	beqzl	$v0,.L0f115770
/*  f115760:	00001025 */ 	or	$v0,$zero,$zero
/*  f115764:	10000003 */ 	beqz	$zero,.L0f115774
/*  f115768:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f11576c:
/*  f11576c:	00001025 */ 	or	$v0,$zero,$zero
.L0f115770:
/*  f115770:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f115774:
/*  f115774:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f115778:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f11577c:	03e00008 */ 	jr	$ra
/*  f115780:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f115784
/*  f115784:	3c0b800a */ 	lui	$t3,%hi(var8009d030)
/*  f115788:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*  f11578c:	8c8a0004 */ 	lw	$t2,0x4($a0)
/*  f115790:	256bd030 */ 	addiu	$t3,$t3,%lo(var8009d030)
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
/*  f11583c:	3c04800a */ 	lui	$a0,0x800a
/*  f115840:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f115844:	00af5821 */ 	addu	$t3,$a1,$t7
/*  f115848:	0520001e */ 	bltz	$t1,.L0f1158c4
/*  f11584c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115850:	8c84d030 */ 	lw	$a0,-0x2fd0($a0)
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
/*  f1158b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1158bc:	50e0ffe6 */ 	beqzl	$a3,.L0f115858
/*  f1158c0:	0009c100 */ 	sll	$t8,$t1,0x4
.L0f1158c4:
/*  f1158c4:	14e0001f */ 	bnez	$a3,.L0f115944
/*  f1158c8:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f115920:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f115948:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11594c
/*  f11594c:	3c0a800a */ 	lui	$t2,%hi(var8009d030)
/*  f115950:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*  f115954:	8c890004 */ 	lw	$t1,0x4($a0)
/*  f115958:	254ad030 */ 	addiu	$t2,$t2,%lo(var8009d030)
/*  f11595c:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f115960:	8d280000 */ 	lw	$t0,0x0($t1)
/*  f115964:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f115968:	8d580004 */ 	lw	$t8,0x4($t2)
/*  f11596c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f115970:	00b91823 */ 	subu	$v1,$a1,$t9
/*  f115974:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f115978:	00035903 */ 	sra	$t3,$v1,0x4
/*  f11597c:	01601825 */ 	or	$v1,$t3,$zero
/*  f115980:	8ca60008 */ 	lw	$a2,0x8($a1)
/*  f115984:	00003825 */ 	or	$a3,$zero,$zero
/*  f115988:	0500000c */ 	bltz	$t0,.L0f1159bc
/*  f11598c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f115990:	310c3fff */ 	andi	$t4,$t0,0x3fff
/*  f115994:	116c0009 */ 	beq	$t3,$t4,.L0f1159bc
/*  f115998:	00006880 */ 	sll	$t5,$zero,0x2
/*  f11599c:	012d2821 */ 	addu	$a1,$t1,$t5
/*  f1159a0:	8ca80004 */ 	lw	$t0,0x4($a1)
.L0f1159a4:
/*  f1159a4:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f1159a8:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f1159ac:	05000003 */ 	bltz	$t0,.L0f1159bc
/*  f1159b0:	310e3fff */ 	andi	$t6,$t0,0x3fff
/*  f1159b4:	546efffb */ 	bnel	$v1,$t6,.L0f1159a4
/*  f1159b8:	8ca80004 */ 	lw	$t0,0x4($a1)
.L0f1159bc:
/*  f1159bc:	310f3fff */ 	andi	$t7,$t0,0x3fff
/*  f1159c0:	106f0007 */ 	beq	$v1,$t7,.L0f1159e0
/*  f1159c4:	00072880 */ 	sll	$a1,$a3,0x2
/*  f1159c8:	0125c021 */ 	addu	$t8,$t1,$a1
/*  f1159cc:	af030000 */ 	sw	$v1,0x0($t8)
/*  f1159d0:	8c8b0004 */ 	lw	$t3,0x4($a0)
/*  f1159d4:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f1159d8:	01656021 */ 	addu	$t4,$t3,$a1
/*  f1159dc:	ad990004 */ 	sw	$t9,0x4($t4)
.L0f1159e0:
/*  f1159e0:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f1159e4:	00003825 */ 	or	$a3,$zero,$zero
/*  f1159e8:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f1159ec:	0500000b */ 	bltz	$t0,.L0f115a1c
/*  f1159f0:	310d3fff */ 	andi	$t5,$t0,0x3fff
/*  f1159f4:	10cd0009 */ 	beq	$a2,$t5,.L0f115a1c
/*  f1159f8:	00007080 */ 	sll	$t6,$zero,0x2
/*  f1159fc:	006e2021 */ 	addu	$a0,$v1,$t6
/*  f115a00:	8c880004 */ 	lw	$t0,0x4($a0)
.L0f115a04:
/*  f115a04:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f115a08:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f115a0c:	05000003 */ 	bltz	$t0,.L0f115a1c
/*  f115a10:	310f3fff */ 	andi	$t7,$t0,0x3fff
/*  f115a14:	54cffffb */ 	bnel	$a2,$t7,.L0f115a04
/*  f115a18:	8c880004 */ 	lw	$t0,0x4($a0)
.L0f115a1c:
/*  f115a1c:	31183fff */ 	andi	$t8,$t0,0x3fff
/*  f115a20:	10d80007 */ 	beq	$a2,$t8,.L0f115a40
/*  f115a24:	00072880 */ 	sll	$a1,$a3,0x2
/*  f115a28:	00655821 */ 	addu	$t3,$v1,$a1
/*  f115a2c:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f115a30:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f115a34:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f115a38:	01856821 */ 	addu	$t5,$t4,$a1
/*  f115a3c:	adb90004 */ 	sw	$t9,0x4($t5)
.L0f115a40:
/*  f115a40:	03e00008 */ 	jr	$ra
/*  f115a44:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f115a48
/*  f115a48:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f115a4c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f115a50:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f115a54:	0fc455e1 */ 	jal	func0f115784
/*  f115a58:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f115a5c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f115a60:	0fc455e1 */ 	jal	func0f115784
/*  f115a64:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f115a68:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f115a6c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f115a70:	03e00008 */ 	jr	$ra
/*  f115a74:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f115a78
/*  f115a78:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f115a7c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f115a80:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f115a84:	0fc45653 */ 	jal	func0f11594c
/*  f115a88:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f115a8c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f115a90:	0fc45653 */ 	jal	func0f11594c
/*  f115a94:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f115a98:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f115a9c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f115aa0:	03e00008 */ 	jr	$ra
/*  f115aa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115aa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115aac:	00000000 */ 	sll	$zero,$zero,0x0
);