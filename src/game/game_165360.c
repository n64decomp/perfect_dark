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

const u32 var7f1b76d0[] = {0xbf666666};
const u32 var7f1b76d4[] = {0x00000000};
const u32 var7f1b76d8[] = {0x00000000};
const u32 var7f1b76dc[] = {0x00000000};

GLOBAL_ASM(
glabel func0f165360
/*  f165360:	440fa000 */ 	mfc1	$t7,$f20
/*  f165364:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f165368:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f16536c:	8ce70284 */ 	lw	$a3,0x284($a3)
/*  f165370:	8ce71740 */ 	lw	$a3,0x1740($a3)
/*  f165374:	3c08800a */ 	lui	$t0,%hi(var800a4cf0)
/*  f165378:	25084cf0 */ 	addiu	$t0,$t0,%lo(var800a4cf0)
/*  f16537c:	3c017f1b */ 	lui	$at,%hi(var7f1b76d0)
/*  f165380:	c42d76d0 */ 	lwc1	$f13,%lo(var7f1b76d0)($at)
/*  f165384:	c50c000c */ 	lwc1	$f12,0xc($t0)
/*  f165388:	3c08800a */ 	lui	$t0,%hi(g_PortalSomethings)
/*  f16538c:	25084cc8 */ 	addiu	$t0,$t0,%lo(g_PortalSomethings)
/*  f165390:	8d080000 */ 	lw	$t0,0x0($t0)
/*  f165394:	000448c0 */ 	sll	$t1,$a0,0x3
/*  f165398:	01284820 */ 	add	$t1,$t1,$t0
/*  f16539c:	95290000 */ 	lhu	$t1,0x0($t1)
/*  f1653a0:	01092020 */ 	add	$a0,$t0,$t1
/*  f1653a4:	90890000 */ 	lbu	$t1,0x0($a0)
/*  f1653a8:	00096820 */ 	add	$t5,$zero,$t1
/*  f1653ac:	24ce0270 */ 	addiu	$t6,$a2,0x270
/*  f1653b0:	460d6302 */ 	mul.s	$f12,$f12,$f13
/*  f1653b4:	c4e00000 */ 	lwc1	$f0,0x0($a3)
/*  f1653b8:	c4e30004 */ 	lwc1	$f3,0x4($a3)
/*  f1653bc:	c4e60008 */ 	lwc1	$f6,0x8($a3)
/*  f1653c0:	c4e10010 */ 	lwc1	$f1,0x10($a3)
/*  f1653c4:	c4e40014 */ 	lwc1	$f4,0x14($a3)
/*  f1653c8:	c4e70018 */ 	lwc1	$f7,0x18($a3)
/*  f1653cc:	c4e20020 */ 	lwc1	$f2,0x20($a3)
/*  f1653d0:	c4e50024 */ 	lwc1	$f5,0x24($a3)
/*  f1653d4:	c4e80028 */ 	lwc1	$f8,0x28($a3)
/*  f1653d8:	c4e90030 */ 	lwc1	$f9,0x30($a3)
/*  f1653dc:	c4ea0034 */ 	lwc1	$f10,0x34($a3)
/*  f1653e0:	c4eb0038 */ 	lwc1	$f11,0x38($a3)
/*  f1653e4:	20840004 */ 	addi	$a0,$a0,0x4
/*  f1653e8:	4480a000 */ 	mtc1	$zero,$f20
/*  f1653ec:	200a0001 */ 	addi	$t2,$zero,0x1
/*  f1653f0:	200b0000 */ 	addi	$t3,$zero,0x0
/*  f1653f4:	00091020 */ 	add	$v0,$zero,$t1
/*  f1653f8:	c48d0000 */ 	lwc1	$f13,0x0($a0)
.L0f1653fc:
/*  f1653fc:	460d0402 */ 	mul.s	$f16,$f0,$f13
/*  f165400:	c48e0004 */ 	lwc1	$f14,0x4($a0)
/*  f165404:	460e0c42 */ 	mul.s	$f17,$f1,$f14
/*  f165408:	c48f0008 */ 	lwc1	$f15,0x8($a0)
/*  f16540c:	460f1482 */ 	mul.s	$f18,$f2,$f15
/*  f165410:	46118400 */ 	add.s	$f16,$f16,$f17
/*  f165414:	460d1c42 */ 	mul.s	$f17,$f3,$f13
/*  f165418:	46128400 */ 	add.s	$f16,$f16,$f18
/*  f16541c:	460e2482 */ 	mul.s	$f18,$f4,$f14
/*  f165420:	46098400 */ 	add.s	$f16,$f16,$f9
/*  f165424:	460f2cc2 */ 	mul.s	$f19,$f5,$f15
/*  f165428:	46128c40 */ 	add.s	$f17,$f17,$f18
/*  f16542c:	460d3482 */ 	mul.s	$f18,$f6,$f13
/*  f165430:	e5d00000 */ 	swc1	$f16,0x0($t6)
/*  f165434:	460e3c02 */ 	mul.s	$f16,$f7,$f14
/*  f165438:	46138c40 */ 	add.s	$f17,$f17,$f19
/*  f16543c:	460f44c2 */ 	mul.s	$f19,$f8,$f15
/*  f165440:	460a8c40 */ 	add.s	$f17,$f17,$f10
/*  f165444:	46109400 */ 	add.s	$f16,$f18,$f16
/*  f165448:	e5d10004 */ 	swc1	$f17,0x4($t6)
/*  f16544c:	46138400 */ 	add.s	$f16,$f16,$f19
/*  f165450:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f165454:	460b8400 */ 	add.s	$f16,$f16,$f11
/*  f165458:	2129ffff */ 	addi	$t1,$t1,-1
/*  f16545c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f165460:	e5d00008 */ 	swc1	$f16,0x8($t6)
/*  f165464:	45010003 */ 	bc1t	.L0f165474
/*  f165468:	240c0000 */ 	addiu	$t4,$zero,0x0
/*  f16546c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f165470:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f165474:
/*  f165474:	adcc000c */ 	sw	$t4,0xc($t6)
/*  f165478:	25cefff0 */ 	addiu	$t6,$t6,-16
/*  f16547c:	1520ffdf */ 	bnez	$t1,.L0f1653fc
/*  f165480:	c48d0000 */ 	lwc1	$f13,0x0($a0)
/*  f165484:	11600048 */ 	beqz	$t3,.L0f1655a8
/*  f165488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16548c:	24c80270 */ 	addiu	$t0,$a2,0x270
/*  f165490:	24020000 */ 	addiu	$v0,$zero,0x0
/*  f165494:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f165498:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*  f16549c:	8d0b0008 */ 	lw	$t3,0x8($t0)
/*  f1654a0:	8d0c000c */ 	lw	$t4,0xc($t0)
/*  f1654a4:	adc90000 */ 	sw	$t1,0x0($t6)
/*  f1654a8:	adca0004 */ 	sw	$t2,0x4($t6)
/*  f1654ac:	adcb0008 */ 	sw	$t3,0x8($t6)
/*  f1654b0:	adcc000c */ 	sw	$t4,0xc($t6)
.L0f1654b4:
/*  f1654b4:	8dc9000c */ 	lw	$t1,0xc($t6)
/*  f1654b8:	11200025 */ 	beqz	$t1,.L0f165550
/*  f1654bc:	8dc9001c */ 	lw	$t1,0x1c($t6)
/*  f1654c0:	15200033 */ 	bnez	$t1,.L0f165590
/*  f1654c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1654c8:	8dc90010 */ 	lw	$t1,0x10($t6)
/*  f1654cc:	8dca0014 */ 	lw	$t2,0x14($t6)
/*  f1654d0:	8dcb0018 */ 	lw	$t3,0x18($t6)
/*  f1654d4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1654d8:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f1654dc:	accb0008 */ 	sw	$t3,0x8($a2)
/*  f1654e0:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f1654e4:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f1654e8:
/*  f1654e8:	c5c00008 */ 	lwc1	$f0,0x8($t6)
/*  f1654ec:	c5c10018 */ 	lwc1	$f1,0x18($t6)
/*  f1654f0:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f1654f4:	46000841 */ 	sub.s	$f1,$f1,$f0
/*  f1654f8:	46000087 */ 	neg.s	$f2,$f0
/*  f1654fc:	c5c30000 */ 	lwc1	$f3,0x0($t6)
/*  f165500:	46011003 */ 	div.s	$f0,$f2,$f1
/*  f165504:	c5c20010 */ 	lwc1	$f2,0x10($t6)
/*  f165508:	46031041 */ 	sub.s	$f1,$f2,$f3
/*  f16550c:	46000842 */ 	mul.s	$f1,$f1,$f0
/*  f165510:	c5c20004 */ 	lwc1	$f2,0x4($t6)
/*  f165514:	46011840 */ 	add.s	$f1,$f3,$f1
/*  f165518:	c5c30014 */ 	lwc1	$f3,0x14($t6)
/*  f16551c:	e4c1fff0 */ 	swc1	$f1,-0x10($a2)
/*  f165520:	460218c1 */ 	sub.s	$f3,$f3,$f2
/*  f165524:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f165528:	46001842 */ 	mul.s	$f1,$f3,$f0
/*  f16552c:	acc0fff8 */ 	sw	$zero,-0x8($a2)
/*  f165530:	46011040 */ 	add.s	$f1,$f2,$f1
/*  f165534:	21adffff */ 	addi	$t5,$t5,-1
/*  f165538:	e4c1fff4 */ 	swc1	$f1,-0xc($a2)
/*  f16553c:	15a0ffdd */ 	bnez	$t5,.L0f1654b4
/*  f165540:	25ce0010 */ 	addiu	$t6,$t6,0x10
/*  f165544:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f165548:	03e00008 */ 	jr	$ra
/*  f16554c:	448fa000 */ 	mtc1	$t7,$f20
.L0f165550:
/*  f165550:	1520ffe5 */ 	bnez	$t1,.L0f1654e8
/*  f165554:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165558:	8dc90010 */ 	lw	$t1,0x10($t6)
/*  f16555c:	8dca0014 */ 	lw	$t2,0x14($t6)
/*  f165560:	8dcb0018 */ 	lw	$t3,0x18($t6)
/*  f165564:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f165568:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f16556c:	accb0008 */ 	sw	$t3,0x8($a2)
/*  f165570:	21adffff */ 	addi	$t5,$t5,-1
/*  f165574:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f165578:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f16557c:	15a0ffcd */ 	bnez	$t5,.L0f1654b4
/*  f165580:	25ce0010 */ 	addiu	$t6,$t6,0x10
/*  f165584:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f165588:	03e00008 */ 	jr	$ra
/*  f16558c:	448fa000 */ 	mtc1	$t7,$f20
.L0f165590:
/*  f165590:	21adffff */ 	addi	$t5,$t5,-1
/*  f165594:	15a0ffc7 */ 	bnez	$t5,.L0f1654b4
/*  f165598:	25ce0010 */ 	addiu	$t6,$t6,0x10
/*  f16559c:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f1655a0:	03e00008 */ 	jr	$ra
/*  f1655a4:	448fa000 */ 	mtc1	$t7,$f20
.L0f1655a8:
/*  f1655a8:	24080028 */ 	addiu	$t0,$zero,0x28
/*  f1655ac:	01024022 */ 	sub	$t0,$t0,$v0
/*  f1655b0:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f1655b4:	03e00008 */ 	jr	$ra
/*  f1655b8:	448fa000 */ 	mtc1	$t7,$f20
/*  f1655bc:	00000000 */ 	sll	$zero,$zero,0x0
);
