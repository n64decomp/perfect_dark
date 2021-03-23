#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "bss.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel debug0f119270nb
/*  f119270:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f119274:	3c028008 */ 	lui	$v0,0x8008
/*  f119278:	8c4286dc */ 	lw	$v0,-0x7924($v0)
/*  f11927c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f119280:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f119284:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f119288:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f11928c:	1440000b */ 	bnez	$v0,.NB0f1192bc
/*  f119290:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f119294:	3c048008 */ 	lui	$a0,0x8008
/*  f119298:	3c058008 */ 	lui	$a1,0x8008
/*  f11929c:	3c068008 */ 	lui	$a2,0x8008
/*  f1192a0:	24c68150 */ 	addiu	$a2,$a2,-32432
/*  f1192a4:	24a58174 */ 	addiu	$a1,$a1,-32396
/*  f1192a8:	0fc46325 */ 	jal	0xf118c94
/*  f1192ac:	248484d4 */ 	addiu	$a0,$a0,-31532
/*  f1192b0:	3c028008 */ 	lui	$v0,0x8008
/*  f1192b4:	10000032 */ 	beqz	$zero,.NB0f119380
/*  f1192b8:	8c4286dc */ 	lw	$v0,-0x7924($v0)
.NB0f1192bc:
/*  f1192bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1192c0:	1441002f */ 	bne	$v0,$at,.NB0f119380
/*  f1192c4:	3c03800a */ 	lui	$v1,0x800a
/*  f1192c8:	3c02800a */ 	lui	$v0,0x800a
/*  f1192cc:	3c04800a */ 	lui	$a0,0x800a
/*  f1192d0:	24847950 */ 	addiu	$a0,$a0,0x7950
/*  f1192d4:	24427888 */ 	addiu	$v0,$v0,0x7888
/*  f1192d8:	24637860 */ 	addiu	$v1,$v1,0x7860
.NB0f1192dc:
/*  f1192dc:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f1192e0:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f1192e4:	0044082b */ 	sltu	$at,$v0,$a0
/*  f1192e8:	1420fffc */ 	bnez	$at,.NB0f1192dc
/*  f1192ec:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1192f0:	3c118008 */ 	lui	$s1,0x8008
/*  f1192f4:	3c13800a */ 	lui	$s3,0x800a
/*  f1192f8:	26737860 */ 	addiu	$s3,$s3,0x7860
/*  f1192fc:	26318684 */ 	addiu	$s1,$s1,-31100
/*  f119300:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f119304:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f119308:	24a5f378 */ 	addiu	$a1,$a1,-3208
/*  f11930c:	0c004e60 */ 	jal	0x13980
/*  f119310:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f119314:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f119318:	3c127f1b */ 	lui	$s2,0x7f1b
/*  f11931c:	2652f380 */ 	addiu	$s2,$s2,-3200
/*  f119320:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f119324:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f119328:	00008025 */ 	or	$s0,$zero,$zero
.NB0f11932c:
/*  f11932c:	0c006568 */ 	jal	0x195a0
/*  f119330:	26040c00 */ 	addiu	$a0,$s0,0xc00
/*  f119334:	1040000b */ 	beqz	$v0,.NB0f119364
/*  f119338:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f11933c:	0278c821 */ 	addu	$t9,$s3,$t8
/*  f119340:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f119344:	02402825 */ 	or	$a1,$s2,$zero
/*  f119348:	0c004fc1 */ 	jal	0x13f04
/*  f11934c:	02003025 */ 	or	$a2,$s0,$zero
/*  f119350:	8e280000 */ 	lw	$t0,0x0($s1)
/*  f119354:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f119358:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f11935c:	1000fff3 */ 	beqz	$zero,.NB0f11932c
/*  f119360:	ae290000 */ 	sw	$t1,0x0($s1)
.NB0f119364:
/*  f119364:	3c058008 */ 	lui	$a1,0x8008
/*  f119368:	24a5868c */ 	addiu	$a1,$a1,-31092
/*  f11936c:	02602025 */ 	or	$a0,$s3,$zero
/*  f119370:	0fc46325 */ 	jal	0xf118c94
/*  f119374:	02203025 */ 	or	$a2,$s1,$zero
/*  f119378:	3c028008 */ 	lui	$v0,0x8008
/*  f11937c:	8c4286dc */ 	lw	$v0,-0x7924($v0)
.NB0f119380:
/*  f119380:	00025080 */ 	sll	$t2,$v0,0x2
/*  f119384:	3c048008 */ 	lui	$a0,0x8008
/*  f119388:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f11938c:	0fc463df */ 	jal	0xf118f7c
/*  f119390:	8c8486e0 */ 	lw	$a0,-0x7920($a0)
/*  f119394:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f119398:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f11939c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1193a0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1193a4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1193a8:	03e00008 */ 	jr	$ra
/*  f1193ac:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel debug0f1193b0nb
/*  f1193b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1193b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1193b8:	0fc463dc */ 	jal	0xf118f70
/*  f1193bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1193c0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1193c4:	8dce86dc */ 	lw	$t6,-0x7924($t6)
/*  f1193c8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1193cc:	3c018008 */ 	lui	$at,0x8008
/*  f1193d0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1193d4:	002f0821 */ 	addu	$at,$at,$t7
/*  f1193d8:	ac2286e0 */ 	sw	$v0,-0x7920($at)
/*  f1193dc:	03e00008 */ 	jr	$ra
/*  f1193e0:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

void debug0f1193e4nb(void)
{
	// empty
}

void debug0f1193ecnb(void)
{
	// empty
}

GLOBAL_ASM(
glabel debug0f1193f4nb
/*  f1193f4:	3c028008 */ 	lui	$v0,0x8008
/*  f1193f8:	3c038008 */ 	lui	$v1,0x8008
/*  f1193fc:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f119400:	246386ec */ 	addiu	$v1,$v1,-30996
/*  f119404:	244286f4 */ 	addiu	$v0,$v0,-30988
/*  f119408:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f11940c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f119410:	3c018008 */ 	lui	$at,0x8008
/*  f119414:	03e00008 */ 	jr	$ra
/*  f119418:	ac2e86e8 */ 	sw	$t6,-0x7918($at)
);

GLOBAL_ASM(
glabel debug0f11941cnb
/*  f11941c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f119420:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f119424:	3c048008 */ 	lui	$a0,0x8008
/*  f119428:	248487f4 */ 	addiu	$a0,$a0,-30732
/*  f11942c:	0c00c460 */ 	jal	0x31180
/*  f119430:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f119434:	0c00c462 */ 	jal	0x31188
/*  f119438:	240400fa */ 	addiu	$a0,$zero,0xfa
/*  f11943c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f119440:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f119444:	03e00008 */ 	jr	$ra
/*  f119448:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel debug0f11944cnb
/*  f11944c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f119450:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f119454:	0c00c464 */ 	jal	0x31190
/*  f119458:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11945c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f119460:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f119464:	03e00008 */ 	jr	$ra
/*  f119468:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel debug0f11946cnb
/*  f11946c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f119470:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f119474:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f119478:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f11947c:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f119480:	0fc4649c */ 	jal	0xf119270
/*  f119484:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f119488:	3c048008 */ 	lui	$a0,0x8008
/*  f11948c:	24848814 */ 	addiu	$a0,$a0,-30700
/*  f119490:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f119494:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f119498:	1040000b */ 	beqz	$v0,.NB0f1194c8
/*  f11949c:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f1194a0:	14c20009 */ 	bne	$a2,$v0,.NB0f1194c8
/*  f1194a4:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1194a8:	0c00305e */ 	jal	0xc178
/*  f1194ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1194b0:	3c048008 */ 	lui	$a0,0x8008
/*  f1194b4:	24848814 */ 	addiu	$a0,$a0,-30700
/*  f1194b8:	0c002b20 */ 	jal	0xac80
/*  f1194bc:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f1194c0:	0c01282c */ 	jal	0x4a0b0
/*  f1194c4:	00002025 */ 	or	$a0,$zero,$zero
.NB0f1194c8:
/*  f1194c8:	3c048008 */ 	lui	$a0,0x8008
/*  f1194cc:	24848818 */ 	addiu	$a0,$a0,-30696
/*  f1194d0:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f1194d4:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f1194d8:	1040000b */ 	beqz	$v0,.NB0f119508
/*  f1194dc:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f1194e0:	14c20009 */ 	bne	$a2,$v0,.NB0f119508
/*  f1194e4:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1194e8:	0c00305a */ 	jal	0xc168
/*  f1194ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1194f0:	3c048008 */ 	lui	$a0,0x8008
/*  f1194f4:	24848818 */ 	addiu	$a0,$a0,-30696
/*  f1194f8:	0c002b20 */ 	jal	0xac80
/*  f1194fc:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f119500:	0c01282c */ 	jal	0x4a0b0
/*  f119504:	00002025 */ 	or	$a0,$zero,$zero
.NB0f119508:
/*  f119508:	3c188008 */ 	lui	$t8,0x8008
/*  f11950c:	8f18881c */ 	lw	$t8,-0x77e4($t8)
/*  f119510:	3c048008 */ 	lui	$a0,0x8008
/*  f119514:	3c018008 */ 	lui	$at,0x8008
/*  f119518:	1700000c */ 	bnez	$t8,.NB0f11954c
/*  f11951c:	248486f0 */ 	addiu	$a0,$a0,-30992
/*  f119520:	97a4003a */ 	lhu	$a0,0x3a($sp)
/*  f119524:	30820008 */ 	andi	$v0,$a0,0x8
/*  f119528:	0002182b */ 	sltu	$v1,$zero,$v0
/*  f11952c:	10600004 */ 	beqz	$v1,.NB0f119540
/*  f119530:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119534:	30830004 */ 	andi	$v1,$a0,0x4
/*  f119538:	0003402b */ 	sltu	$t0,$zero,$v1
/*  f11953c:	01001825 */ 	or	$v1,$t0,$zero
.NB0f119540:
/*  f119540:	ac23881c */ 	sw	$v1,-0x77e4($at)
/*  f119544:	100000e4 */ 	beqz	$zero,.NB0f1198d8
/*  f119548:	00601025 */ 	or	$v0,$v1,$zero
.NB0f11954c:
/*  f11954c:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f119550:	2403fffe */ 	addiu	$v1,$zero,-2
/*  f119554:	3c018008 */ 	lui	$at,0x8008
/*  f119558:	50620004 */ 	beql	$v1,$v0,.NB0f11956c
/*  f11955c:	97a9003e */ 	lhu	$t1,0x3e($sp)
/*  f119560:	ac2286f4 */ 	sw	$v0,-0x790c($at)
/*  f119564:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f119568:	97a9003e */ 	lhu	$t1,0x3e($sp)
.NB0f11956c:
/*  f11956c:	312a0200 */ 	andi	$t2,$t1,0x200
/*  f119570:	11400007 */ 	beqz	$t2,.NB0f119590
/*  f119574:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f119578:	0fc4645d */ 	jal	0xf119174
/*  f11957c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119580:	3c048008 */ 	lui	$a0,0x8008
/*  f119584:	248486f0 */ 	addiu	$a0,$a0,-30992
/*  f119588:	2403fffe */ 	addiu	$v1,$zero,-2
/*  f11958c:	ac830000 */ 	sw	$v1,0x0($a0)
.NB0f119590:
/*  f119590:	8fab001c */ 	lw	$t3,0x1c($sp)
/*  f119594:	316c0100 */ 	andi	$t4,$t3,0x100
/*  f119598:	51800008 */ 	beqzl	$t4,.NB0f1195bc
/*  f11959c:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f1195a0:	0fc46420 */ 	jal	0xf119080
/*  f1195a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1195a8:	3c048008 */ 	lui	$a0,0x8008
/*  f1195ac:	248486f0 */ 	addiu	$a0,$a0,-30992
/*  f1195b0:	2403fffe */ 	addiu	$v1,$zero,-2
/*  f1195b4:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f1195b8:	8fad001c */ 	lw	$t5,0x1c($sp)
.NB0f1195bc:
/*  f1195bc:	31ae0800 */ 	andi	$t6,$t5,0x800
/*  f1195c0:	51c00008 */ 	beqzl	$t6,.NB0f1195e4
/*  f1195c4:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f1195c8:	0fc463e2 */ 	jal	0xf118f88
/*  f1195cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1195d0:	3c048008 */ 	lui	$a0,0x8008
/*  f1195d4:	248486f0 */ 	addiu	$a0,$a0,-30992
/*  f1195d8:	2403fffe */ 	addiu	$v1,$zero,-2
/*  f1195dc:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f1195e0:	8faf001c */ 	lw	$t7,0x1c($sp)
.NB0f1195e4:
/*  f1195e4:	31f80400 */ 	andi	$t8,$t7,0x400
/*  f1195e8:	53000008 */ 	beqzl	$t8,.NB0f11960c
/*  f1195ec:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f1195f0:	0fc46402 */ 	jal	0xf119008
/*  f1195f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1195f8:	3c048008 */ 	lui	$a0,0x8008
/*  f1195fc:	248486f0 */ 	addiu	$a0,$a0,-30992
/*  f119600:	2403fffe */ 	addiu	$v1,$zero,-2
/*  f119604:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f119608:	8fb9001c */ 	lw	$t9,0x1c($sp)
.NB0f11960c:
/*  f11960c:	3c028008 */ 	lui	$v0,0x8008
/*  f119610:	33289000 */ 	andi	$t0,$t9,0x9000
/*  f119614:	510000a0 */ 	beqzl	$t0,.NB0f119898
/*  f119618:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f11961c:	8c4286dc */ 	lw	$v0,-0x7924($v0)
/*  f119620:	24010001 */ 	addiu	$at,$zero,0x1
/*  f119624:	14410011 */ 	bne	$v0,$at,.NB0f11966c
/*  f119628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11962c:	0fc463dc */ 	jal	0xf118f70
/*  f119630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119634:	14400007 */ 	bnez	$v0,.NB0f119654
/*  f119638:	3c018008 */ 	lui	$at,0x8008
/*  f11963c:	0c0050b5 */ 	jal	0x142d4
/*  f119640:	ac2086dc */ 	sw	$zero,-0x7924($at)
/*  f119644:	0fc4649c */ 	jal	0xf119270
/*  f119648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11964c:	10000092 */ 	beqz	$zero,.NB0f119898
/*  f119650:	8faf001c */ 	lw	$t7,0x1c($sp)
.NB0f119654:
/*  f119654:	0fc463dc */ 	jal	0xf118f70
/*  f119658:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11965c:	0fc11e7c */ 	jal	0xf0479f0
/*  f119660:	24440bff */ 	addiu	$a0,$v0,0xbff
/*  f119664:	1000008c */ 	beqz	$zero,.NB0f119898
/*  f119668:	8faf001c */ 	lw	$t7,0x1c($sp)
.NB0f11966c:
/*  f11966c:	5440008a */ 	bnezl	$v0,.NB0f119898
/*  f119670:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f119674:	0fc463dc */ 	jal	0xf118f70
/*  f119678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11967c:	2449fff3 */ 	addiu	$t1,$v0,-13
/*  f119680:	2d210059 */ 	sltiu	$at,$t1,0x59
/*  f119684:	10200083 */ 	beqz	$at,.NB0f119894
/*  f119688:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f11968c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f119690:	3c017f1b */ 	lui	$at,0x7f1b
/*  f119694:	00290821 */ 	addu	$at,$at,$t1
/*  f119698:	8c29f38c */ 	lw	$t1,-0xc74($at)
/*  f11969c:	01200008 */ 	jr	$t1
/*  f1196a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1196a4:	3c028008 */ 	lui	$v0,0x8008
/*  f1196a8:	24428730 */ 	addiu	$v0,$v0,-30928
/*  f1196ac:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f1196b0:	394b0001 */ 	xori	$t3,$t2,0x1
/*  f1196b4:	10000077 */ 	beqz	$zero,.NB0f119894
/*  f1196b8:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f1196bc:	3c028008 */ 	lui	$v0,0x8008
/*  f1196c0:	24428770 */ 	addiu	$v0,$v0,-30864
/*  f1196c4:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f1196c8:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f1196cc:	05a10004 */ 	bgez	$t5,.NB0f1196e0
/*  f1196d0:	31ae0003 */ 	andi	$t6,$t5,0x3
/*  f1196d4:	11c00002 */ 	beqz	$t6,.NB0f1196e0
/*  f1196d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1196dc:	25cefffc */ 	addiu	$t6,$t6,-4
.NB0f1196e0:
/*  f1196e0:	1000006c */ 	beqz	$zero,.NB0f119894
/*  f1196e4:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f1196e8:	3c028008 */ 	lui	$v0,0x8008
/*  f1196ec:	2442876c */ 	addiu	$v0,$v0,-30868
/*  f1196f0:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f1196f4:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f1196f8:	07010004 */ 	bgez	$t8,.NB0f11970c
/*  f1196fc:	33190003 */ 	andi	$t9,$t8,0x3
/*  f119700:	13200002 */ 	beqz	$t9,.NB0f11970c
/*  f119704:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119708:	2739fffc */ 	addiu	$t9,$t9,-4
.NB0f11970c:
/*  f11970c:	10000061 */ 	beqz	$zero,.NB0f119894
/*  f119710:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f119714:	3c05800a */ 	lui	$a1,0x800a
/*  f119718:	3c07800a */ 	lui	$a3,0x800a
/*  f11971c:	24e7676e */ 	addiu	$a3,$a3,0x676e
/*  f119720:	24a566f0 */ 	addiu	$a1,$a1,0x66f0
/*  f119724:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f119728:	00001025 */ 	or	$v0,$zero,$zero
.NB0f11972c:
/*  f11972c:	00a01825 */ 	or	$v1,$a1,$zero
.NB0f119730:
/*  f119730:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f119734:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f119738:	1446fffd */ 	bne	$v0,$a2,.NB0f119730
/*  f11973c:	a464001e */ 	sh	$a0,0x1e($v1)
/*  f119740:	24a50006 */ 	addiu	$a1,$a1,0x6
/*  f119744:	54a7fff9 */ 	bnel	$a1,$a3,.NB0f11972c
/*  f119748:	00001025 */ 	or	$v0,$zero,$zero
/*  f11974c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f119750:	3c01800a */ 	lui	$at,0x800a
/*  f119754:	1000004f */ 	beqz	$zero,.NB0f119894
/*  f119758:	a028681b */ 	sb	$t0,0x681b($at)
/*  f11975c:	3c028008 */ 	lui	$v0,0x8008
/*  f119760:	24428798 */ 	addiu	$v0,$v0,-30824
/*  f119764:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f119768:	392a0001 */ 	xori	$t2,$t1,0x1
/*  f11976c:	0fc65417 */ 	jal	0xf19505c
/*  f119770:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f119774:	10000048 */ 	beqz	$zero,.NB0f119898
/*  f119778:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f11977c:	3c028008 */ 	lui	$v0,0x8008
/*  f119780:	2442879c */ 	addiu	$v0,$v0,-30820
/*  f119784:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f119788:	396c0001 */ 	xori	$t4,$t3,0x1
/*  f11978c:	10000041 */ 	beqz	$zero,.NB0f119894
/*  f119790:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f119794:	3c048008 */ 	lui	$a0,0x8008
/*  f119798:	248487a0 */ 	addiu	$a0,$a0,-30816
/*  f11979c:	8c8d0000 */ 	lw	$t5,0x0($a0)
/*  f1197a0:	3c02800a */ 	lui	$v0,0x800a
/*  f1197a4:	244266f0 */ 	addiu	$v0,$v0,0x66f0
/*  f1197a8:	39ae0001 */ 	xori	$t6,$t5,0x1
/*  f1197ac:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1197b0:	3c04800a */ 	lui	$a0,0x800a
/*  f1197b4:	248466f9 */ 	addiu	$a0,$a0,0x66f9
/*  f1197b8:	240300ff */ 	addiu	$v1,$zero,0xff
.NB0f1197bc:
/*  f1197bc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1197c0:	1444fffe */ 	bne	$v0,$a0,.NB0f1197bc
/*  f1197c4:	a04300ab */ 	sb	$v1,0xab($v0)
/*  f1197c8:	0fc425a7 */ 	jal	0xf10969c
/*  f1197cc:	24040030 */ 	addiu	$a0,$zero,0x30
/*  f1197d0:	0fc425a7 */ 	jal	0xf10969c
/*  f1197d4:	24040031 */ 	addiu	$a0,$zero,0x31
/*  f1197d8:	0fc425a7 */ 	jal	0xf10969c
/*  f1197dc:	24040032 */ 	addiu	$a0,$zero,0x32
/*  f1197e0:	0fc425a7 */ 	jal	0xf10969c
/*  f1197e4:	24040033 */ 	addiu	$a0,$zero,0x33
/*  f1197e8:	0fc425a7 */ 	jal	0xf10969c
/*  f1197ec:	24040034 */ 	addiu	$a0,$zero,0x34
/*  f1197f0:	0fc425a7 */ 	jal	0xf10969c
/*  f1197f4:	24040035 */ 	addiu	$a0,$zero,0x35
/*  f1197f8:	0fc425a7 */ 	jal	0xf10969c
/*  f1197fc:	24040036 */ 	addiu	$a0,$zero,0x36
/*  f119800:	0fc425a7 */ 	jal	0xf10969c
/*  f119804:	24040037 */ 	addiu	$a0,$zero,0x37
/*  f119808:	0fc425a7 */ 	jal	0xf10969c
/*  f11980c:	24040038 */ 	addiu	$a0,$zero,0x38
/*  f119810:	0fc425a7 */ 	jal	0xf10969c
/*  f119814:	24040039 */ 	addiu	$a0,$zero,0x39
/*  f119818:	1000001f */ 	beqz	$zero,.NB0f119898
/*  f11981c:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f119820:	3c028008 */ 	lui	$v0,0x8008
/*  f119824:	244287a4 */ 	addiu	$v0,$v0,-30812
/*  f119828:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f11982c:	39f80001 */ 	xori	$t8,$t7,0x1
/*  f119830:	10000018 */ 	beqz	$zero,.NB0f119894
/*  f119834:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f119838:	3c028008 */ 	lui	$v0,0x8008
/*  f11983c:	244287e4 */ 	addiu	$v0,$v0,-30748
/*  f119840:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f119844:	3b280001 */ 	xori	$t0,$t9,0x1
/*  f119848:	10000012 */ 	beqz	$zero,.NB0f119894
/*  f11984c:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f119850:	3c028008 */ 	lui	$v0,0x8008
/*  f119854:	24428700 */ 	addiu	$v0,$v0,-30976
/*  f119858:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f11985c:	392a0001 */ 	xori	$t2,$t1,0x1
/*  f119860:	1000000c */ 	beqz	$zero,.NB0f119894
/*  f119864:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f119868:	3c028006 */ 	lui	$v0,0x8006
/*  f11986c:	2442e710 */ 	addiu	$v0,$v0,-6384
/*  f119870:	904b0000 */ 	lbu	$t3,0x0($v0)
/*  f119874:	396c0001 */ 	xori	$t4,$t3,0x1
/*  f119878:	10000006 */ 	beqz	$zero,.NB0f119894
/*  f11987c:	a04c0000 */ 	sb	$t4,0x0($v0)
/*  f119880:	3c028008 */ 	lui	$v0,0x8008
/*  f119884:	244287ac */ 	addiu	$v0,$v0,-30804
/*  f119888:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f11988c:	39ae0001 */ 	xori	$t6,$t5,0x1
/*  f119890:	ac4e0000 */ 	sw	$t6,0x0($v0)
.NB0f119894:
/*  f119894:	8faf001c */ 	lw	$t7,0x1c($sp)
.NB0f119898:
/*  f119898:	3c198008 */ 	lui	$t9,0x8008
/*  f11989c:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f1198a0:	13000009 */ 	beqz	$t8,.NB0f1198c8
/*  f1198a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1198a8:	8f39881c */ 	lw	$t9,-0x77e4($t9)
/*  f1198ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1198b0:	17210003 */ 	bne	$t9,$at,.NB0f1198c0
/*  f1198b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1198b8:	0c0050b5 */ 	jal	0x142d4
/*  f1198bc:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1198c0:
/*  f1198c0:	3c018008 */ 	lui	$at,0x8008
/*  f1198c4:	ac20881c */ 	sw	$zero,-0x77e4($at)
.NB0f1198c8:
/*  f1198c8:	0fc464ec */ 	jal	0xf1193b0
/*  f1198cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1198d0:	3c028008 */ 	lui	$v0,0x8008
/*  f1198d4:	8c42881c */ 	lw	$v0,-0x77e4($v0)
.NB0f1198d8:
/*  f1198d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1198dc:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1198e0:	03e00008 */ 	jr	$ra
/*  f1198e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel debug0f1198e8nb
/*  f1198e8:	3c028008 */ 	lui	$v0,0x8008
/*  f1198ec:	03e00008 */ 	jr	$ra
/*  f1198f0:	8c4286f8 */ 	lw	$v0,-0x7908($v0)
);

GLOBAL_ASM(
glabel debug0f1198f4nb
/*  f1198f4:	3c028008 */ 	lui	$v0,0x8008
/*  f1198f8:	03e00008 */ 	jr	$ra
/*  f1198fc:	8c4286fc */ 	lw	$v0,-0x7904($v0)
);

GLOBAL_ASM(
glabel debugEnablePropRendering
/*  f119900:	3c028008 */ 	lui	$v0,0x8008
/*  f119904:	03e00008 */ 	jr	$ra
/*  f119908:	8c428700 */ 	lw	$v0,-0x7900($v0)
);

GLOBAL_ASM(
glabel debug0f11990cnb
/*  f11990c:	3c028008 */ 	lui	$v0,0x8008
/*  f119910:	03e00008 */ 	jr	$ra
/*  f119914:	8c428708 */ 	lw	$v0,-0x78f8($v0)
);

GLOBAL_ASM(
glabel debug0f119918nb
/*  f119918:	3c028008 */ 	lui	$v0,0x8008
/*  f11991c:	03e00008 */ 	jr	$ra
/*  f119920:	8c428730 */ 	lw	$v0,-0x78d0($v0)
);

GLOBAL_ASM(
glabel debug0f119924nb
/*  f119924:	3c018008 */ 	lui	$at,0x8008
/*  f119928:	03e00008 */ 	jr	$ra
/*  f11992c:	ac248730 */ 	sw	$a0,-0x78d0($at)
);

GLOBAL_ASM(
glabel debug0f119930nb
/*  f119930:	3c028008 */ 	lui	$v0,0x8008
/*  f119934:	03e00008 */ 	jr	$ra
/*  f119938:	8c428710 */ 	lw	$v0,-0x78f0($v0)
);

GLOBAL_ASM(
glabel debug0f11993cnb
/*  f11993c:	3c028008 */ 	lui	$v0,0x8008
/*  f119940:	03e00008 */ 	jr	$ra
/*  f119944:	8c428714 */ 	lw	$v0,-0x78ec($v0)
);

GLOBAL_ASM(
glabel debug0f119948nb
/*  f119948:	3c028008 */ 	lui	$v0,0x8008
/*  f11994c:	03e00008 */ 	jr	$ra
/*  f119950:	8c428718 */ 	lw	$v0,-0x78e8($v0)
);

GLOBAL_ASM(
glabel debug0f119954nb
/*  f119954:	3c028008 */ 	lui	$v0,0x8008
/*  f119958:	03e00008 */ 	jr	$ra
/*  f11995c:	8c42871c */ 	lw	$v0,-0x78e4($v0)
);

GLOBAL_ASM(
glabel debugIsRoomStateDebugEnabled
/*  f119960:	3c028008 */ 	lui	$v0,0x8008
/*  f119964:	03e00008 */ 	jr	$ra
/*  f119968:	8c42870c */ 	lw	$v0,-0x78f4($v0)
);

GLOBAL_ASM(
glabel debug0f11996cnb
/*  f11996c:	3c028008 */ 	lui	$v0,0x8008
/*  f119970:	03e00008 */ 	jr	$ra
/*  f119974:	8c428720 */ 	lw	$v0,-0x78e0($v0)
);

GLOBAL_ASM(
glabel debug0f119978nb
/*  f119978:	3c018008 */ 	lui	$at,0x8008
/*  f11997c:	03e00008 */ 	jr	$ra
/*  f119980:	ac248720 */ 	sw	$a0,-0x78e0($at)
);

GLOBAL_ASM(
glabel debug0f119984nb
/*  f119984:	3c028008 */ 	lui	$v0,0x8008
/*  f119988:	03e00008 */ 	jr	$ra
/*  f11998c:	8c428734 */ 	lw	$v0,-0x78cc($v0)
);

GLOBAL_ASM(
glabel debug0f119990nb
/*  f119990:	3c018008 */ 	lui	$at,0x8008
/*  f119994:	03e00008 */ 	jr	$ra
/*  f119998:	ac248734 */ 	sw	$a0,-0x78cc($at)
);

GLOBAL_ASM(
glabel debugForceAllObjectivesComplete
/*  f11999c:	3c028008 */ 	lui	$v0,0x8008
/*  f1199a0:	03e00008 */ 	jr	$ra
/*  f1199a4:	8c428738 */ 	lw	$v0,-0x78c8($v0)
);

GLOBAL_ASM(
glabel debug0f11ee28
/*  f1199a8:	3c028008 */ 	lui	$v0,0x8008
/*  f1199ac:	03e00008 */ 	jr	$ra
/*  f1199b0:	8c42873c */ 	lw	$v0,-0x78c4($v0)
);

GLOBAL_ASM(
glabel debug0f11ee30
/*  f1199b4:	3c028008 */ 	lui	$v0,0x8008
/*  f1199b8:	03e00008 */ 	jr	$ra
/*  f1199bc:	8c428744 */ 	lw	$v0,-0x78bc($v0)
);

GLOBAL_ASM(
glabel debug0f11ee38
/*  f1199c0:	3c028008 */ 	lui	$v0,0x8008
/*  f1199c4:	03e00008 */ 	jr	$ra
/*  f1199c8:	8c428750 */ 	lw	$v0,-0x78b0($v0)
);

GLOBAL_ASM(
glabel debug0f11ee40
/*  f1199cc:	3c028008 */ 	lui	$v0,0x8008
/*  f1199d0:	03e00008 */ 	jr	$ra
/*  f1199d4:	8c428754 */ 	lw	$v0,-0x78ac($v0)
);

GLOBAL_ASM(
glabel debug0f1199d8nb
/*  f1199d8:	3c028008 */ 	lui	$v0,0x8008
/*  f1199dc:	03e00008 */ 	jr	$ra
/*  f1199e0:	8c428758 */ 	lw	$v0,-0x78a8($v0)
);

GLOBAL_ASM(
glabel debug0f1199e4nb
/*  f1199e4:	3c028008 */ 	lui	$v0,0x8008
/*  f1199e8:	03e00008 */ 	jr	$ra
/*  f1199ec:	8c428740 */ 	lw	$v0,-0x78c0($v0)
);

GLOBAL_ASM(
glabel debug0f1199f0nb
/*  f1199f0:	3c028008 */ 	lui	$v0,0x8008
/*  f1199f4:	03e00008 */ 	jr	$ra
/*  f1199f8:	8c428724 */ 	lw	$v0,-0x78dc($v0)
);

GLOBAL_ASM(
glabel debug0f1199fcnb
/*  f1199fc:	3c028008 */ 	lui	$v0,0x8008
/*  f119a00:	03e00008 */ 	jr	$ra
/*  f119a04:	8c428728 */ 	lw	$v0,-0x78d8($v0)
);

GLOBAL_ASM(
glabel debug0f119a08nb
/*  f119a08:	3c028008 */ 	lui	$v0,0x8008
/*  f119a0c:	03e00008 */ 	jr	$ra
/*  f119a10:	8c42872c */ 	lw	$v0,-0x78d4($v0)
);

GLOBAL_ASM(
glabel debug0f119a14nb
/*  f119a14:	3c028008 */ 	lui	$v0,0x8008
/*  f119a18:	03e00008 */ 	jr	$ra
/*  f119a1c:	8c428748 */ 	lw	$v0,-0x78b8($v0)
);

GLOBAL_ASM(
glabel debug0f119a20nb
/*  f119a20:	3c028008 */ 	lui	$v0,0x8008
/*  f119a24:	03e00008 */ 	jr	$ra
/*  f119a28:	8c42874c */ 	lw	$v0,-0x78b4($v0)
);

GLOBAL_ASM(
glabel debug0f119a2cnb
/*  f119a2c:	3c028008 */ 	lui	$v0,0x8008
/*  f119a30:	03e00008 */ 	jr	$ra
/*  f119a34:	8c42875c */ 	lw	$v0,-0x78a4($v0)
);

GLOBAL_ASM(
glabel debugGetSlowMotion
/*  f119a38:	3c028008 */ 	lui	$v0,0x8008
/*  f119a3c:	03e00008 */ 	jr	$ra
/*  f119a40:	8c428764 */ 	lw	$v0,-0x789c($v0)
);

GLOBAL_ASM(
glabel debug0f119a44nb
/*  f119a44:	3c028008 */ 	lui	$v0,0x8008
/*  f119a48:	03e00008 */ 	jr	$ra
/*  f119a4c:	8c428768 */ 	lw	$v0,-0x7898($v0)
);

GLOBAL_ASM(
glabel debug0f119a50nb
/*  f119a50:	3c028008 */ 	lui	$v0,0x8008
/*  f119a54:	03e00008 */ 	jr	$ra
/*  f119a58:	8c428760 */ 	lw	$v0,-0x78a0($v0)
);

GLOBAL_ASM(
glabel debug0f11ee88
/*  f119a5c:	3c028008 */ 	lui	$v0,0x8008
/*  f119a60:	03e00008 */ 	jr	$ra
/*  f119a64:	8c42876c */ 	lw	$v0,-0x7894($v0)
);

GLOBAL_ASM(
glabel debug0f11ee90
/*  f119a68:	3c028008 */ 	lui	$v0,0x8008
/*  f119a6c:	03e00008 */ 	jr	$ra
/*  f119a70:	8c428770 */ 	lw	$v0,-0x7890($v0)
);

GLOBAL_ASM(
glabel debug0f119a74nb
/*  f119a74:	3c028008 */ 	lui	$v0,0x8008
/*  f119a78:	03e00008 */ 	jr	$ra
/*  f119a7c:	8c428774 */ 	lw	$v0,-0x788c($v0)
);

GLOBAL_ASM(
glabel debug0f119a80nb
/*  f119a80:	3c018008 */ 	lui	$at,0x8008
/*  f119a84:	03e00008 */ 	jr	$ra
/*  f119a88:	ac208774 */ 	sw	$zero,-0x788c($at)
);

GLOBAL_ASM(
glabel debug0f119a8cnb
/*  f119a8c:	3c028008 */ 	lui	$v0,0x8008
/*  f119a90:	03e00008 */ 	jr	$ra
/*  f119a94:	8c428778 */ 	lw	$v0,-0x7888($v0)
);

GLOBAL_ASM(
glabel debug0f11eea8
/*  f119a98:	3c028008 */ 	lui	$v0,0x8008
/*  f119a9c:	03e00008 */ 	jr	$ra
/*  f119aa0:	8c428780 */ 	lw	$v0,-0x7880($v0)
);

bool debug0f119aa4nb(void)
{
	return false;
}

GLOBAL_ASM(
glabel debugDangerousProps
/*  f119aac:	3c028008 */ 	lui	$v0,0x8008
/*  f119ab0:	03e00008 */ 	jr	$ra
/*  f119ab4:	8c4287ec */ 	lw	$v0,-0x7814($v0)
);

GLOBAL_ASM(
glabel debug0f119ab8nb
/*  f119ab8:	3c028008 */ 	lui	$v0,0x8008
/*  f119abc:	03e00008 */ 	jr	$ra
/*  f119ac0:	8c4287d8 */ 	lw	$v0,-0x7828($v0)
);

GLOBAL_ASM(
glabel debug0f119ac4nb
/*  f119ac4:	3c028008 */ 	lui	$v0,0x8008
/*  f119ac8:	03e00008 */ 	jr	$ra
/*  f119acc:	8c4287dc */ 	lw	$v0,-0x7824($v0)
);

GLOBAL_ASM(
glabel debug0f119ad0nb
/*  f119ad0:	3c028008 */ 	lui	$v0,0x8008
/*  f119ad4:	03e00008 */ 	jr	$ra
/*  f119ad8:	8c42877c */ 	lw	$v0,-0x7884($v0)
);

GLOBAL_ASM(
glabel debugGetMotionBlur
/*  f119adc:	3c028008 */ 	lui	$v0,0x8008
/*  f119ae0:	03e00008 */ 	jr	$ra
/*  f119ae4:	8c428784 */ 	lw	$v0,-0x787c($v0)
);

GLOBAL_ASM(
glabel debug0f119ae8nb
/*  f119ae8:	3c028008 */ 	lui	$v0,0x8008
/*  f119aec:	03e00008 */ 	jr	$ra
/*  f119af0:	8c428790 */ 	lw	$v0,-0x7870($v0)
);

GLOBAL_ASM(
glabel dprint
/*  f119af4:	3c028008 */ 	lui	$v0,0x8008
/*  f119af8:	03e00008 */ 	jr	$ra
/*  f119afc:	8c4287b8 */ 	lw	$v0,-0x7848($v0)
);

GLOBAL_ASM(
glabel debug0f119b00nb
/*  f119b00:	3c028008 */ 	lui	$v0,0x8008
/*  f119b04:	03e00008 */ 	jr	$ra
/*  f119b08:	8c4287c0 */ 	lw	$v0,-0x7840($v0)
);

GLOBAL_ASM(
glabel debugAllowEndLevel
/*  f119b0c:	3c028008 */ 	lui	$v0,0x8008
/*  f119b10:	03e00008 */ 	jr	$ra
/*  f119b14:	8c4287c4 */ 	lw	$v0,-0x783c($v0)
);

GLOBAL_ASM(
glabel debug0f119b18nb
/*  f119b18:	3c028008 */ 	lui	$v0,0x8008
/*  f119b1c:	03e00008 */ 	jr	$ra
/*  f119b20:	8c4287c8 */ 	lw	$v0,-0x7838($v0)
);

GLOBAL_ASM(
glabel debug0f119b24nb
/*  f119b24:	3c028008 */ 	lui	$v0,0x8008
/*  f119b28:	03e00008 */ 	jr	$ra
/*  f119b2c:	8c4287cc */ 	lw	$v0,-0x7834($v0)
);

GLOBAL_ASM(
glabel debug0f119b30nb
/*  f119b30:	3c028008 */ 	lui	$v0,0x8008
/*  f119b34:	03e00008 */ 	jr	$ra
/*  f119b38:	8c4287d0 */ 	lw	$v0,-0x7830($v0)
);

GLOBAL_ASM(
glabel debug0f119b3cnb
/*  f119b3c:	3c028008 */ 	lui	$v0,0x8008
/*  f119b40:	03e00008 */ 	jr	$ra
/*  f119b44:	8c4287d4 */ 	lw	$v0,-0x782c($v0)
);

GLOBAL_ASM(
glabel debugEnableFootsteps
/*  f119b48:	3c028008 */ 	lui	$v0,0x8008
/*  f119b4c:	03e00008 */ 	jr	$ra
/*  f119b50:	8c428794 */ 	lw	$v0,-0x786c($v0)
);

GLOBAL_ASM(
glabel debug0f119b54nb
/*  f119b54:	3c028008 */ 	lui	$v0,0x8008
/*  f119b58:	03e00008 */ 	jr	$ra
/*  f119b5c:	8c428798 */ 	lw	$v0,-0x7868($v0)
);

GLOBAL_ASM(
glabel debug0f119b60nb
/*  f119b60:	3c028008 */ 	lui	$v0,0x8008
/*  f119b64:	03e00008 */ 	jr	$ra
/*  f119b68:	8c42879c */ 	lw	$v0,-0x7864($v0)
);

GLOBAL_ASM(
glabel debugAllFrWeapons
/*  f119b6c:	3c028008 */ 	lui	$v0,0x8008
/*  f119b70:	03e00008 */ 	jr	$ra
/*  f119b74:	8c4287a0 */ 	lw	$v0,-0x7860($v0)
);

GLOBAL_ASM(
glabel debug0f119b78nb
/*  f119b78:	3c028008 */ 	lui	$v0,0x8008
/*  f119b7c:	03e00008 */ 	jr	$ra
/*  f119b80:	8c4287a4 */ 	lw	$v0,-0x785c($v0)
);

GLOBAL_ASM(
glabel debug0f119b84nb
/*  f119b84:	3c028008 */ 	lui	$v0,0x8008
/*  f119b88:	03e00008 */ 	jr	$ra
/*  f119b8c:	8c4287a8 */ 	lw	$v0,-0x7858($v0)
);

GLOBAL_ASM(
glabel debug0f119b90nb
/*  f119b90:	3c028008 */ 	lui	$v0,0x8008
/*  f119b94:	03e00008 */ 	jr	$ra
/*  f119b98:	8c4287ac */ 	lw	$v0,-0x7854($v0)
);

GLOBAL_ASM(
glabel debug0f119b9cnb
/*  f119b9c:	3c028008 */ 	lui	$v0,0x8008
/*  f119ba0:	03e00008 */ 	jr	$ra
/*  f119ba4:	8c4287b0 */ 	lw	$v0,-0x7850($v0)
);

GLOBAL_ASM(
glabel debug0f119ba8nb
/*  f119ba8:	3c028008 */ 	lui	$v0,0x8008
/*  f119bac:	03e00008 */ 	jr	$ra
/*  f119bb0:	8c4287bc */ 	lw	$v0,-0x7844($v0)
);

GLOBAL_ASM(
glabel debug0f11ef78
/*  f119bb4:	3c028008 */ 	lui	$v0,0x8008
/*  f119bb8:	03e00008 */ 	jr	$ra
/*  f119bbc:	8c4287e4 */ 	lw	$v0,-0x781c($v0)
);

GLOBAL_ASM(
glabel debug0f11ef80
/*  f119bc0:	3c028008 */ 	lui	$v0,0x8008
/*  f119bc4:	03e00008 */ 	jr	$ra
/*  f119bc8:	8c4287e8 */ 	lw	$v0,-0x7818($v0)
);

GLOBAL_ASM(
glabel debug0f119bccnb
/*  f119bcc:	3c028008 */ 	lui	$v0,0x8008
/*  f119bd0:	03e00008 */ 	jr	$ra
/*  f119bd4:	8c4287e0 */ 	lw	$v0,-0x7820($v0)
);

GLOBAL_ASM(
glabel debug0f119bd8nb
/*  f119bd8:	3c028008 */ 	lui	$v0,0x8008
/*  f119bdc:	03e00008 */ 	jr	$ra
/*  f119be0:	8c4287f0 */ 	lw	$v0,-0x7810($v0)
);
