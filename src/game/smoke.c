#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/dlights.h"
#include "game/game_0601b0.h"
#include "game/game_0b3350.h"
#include "game/smoke.h"
#include "game/game_157db0.h"
#include "game/game_1668e0.h"
#include "game/game_166e40.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4b480.h"
#include "types.h"

const u32 var7f1b55d0[] = {0x46ea6000};
const u32 var7f1b55d4[] = {0x46ea6000};
const u32 var7f1b55d8[] = {0xc6ea6000};
const u32 var7f1b55dc[] = {0x3b808081};
const u32 var7f1b55e0[] = {0x3c23d70a};
const u32 var7f1b55e4[] = {0x3ca3d70a};
const u32 var7f1b55e8[] = {0x3ea8f5c3};
const u32 var7f1b55ec[] = {0x40c907a9};
const u32 var7f1b55f0[] = {0x3e6b851f};
const u32 var7f1b55f4[] = {0x00000000};
const u32 var7f1b55f8[] = {0x00000000};
const u32 var7f1b55fc[] = {0x00000000};

GLOBAL_ASM(
glabel func0f12d3f0
/*  f12d3f0:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f12d3f4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f12d3f8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f12d3fc:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*  f12d400:	00c08825 */ 	or	$s1,$a2,$zero
/*  f12d404:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f12d408:	afa500bc */ 	sw	$a1,0xbc($sp)
/*  f12d40c:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*  f12d410:	0fc59e59 */ 	jal	func0f167964
/*  f12d414:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f12d418:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f12d41c:	0fc59e73 */ 	jal	func0f1679cc
/*  f12d420:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f12d424:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f12d428:	00408025 */ 	or	$s0,$v0,$zero
/*  f12d42c:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f12d430:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f12d434:	3c048008 */ 	lui	$a0,%hi(g_SmokeTypes+0x2)
/*  f12d438:	95cf0006 */ 	lhu	$t7,0x6($t6)
/*  f12d43c:	84e60024 */ 	lh	$a2,0x24($a3)
/*  f12d440:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f12d444:	000fc242 */ 	srl	$t8,$t7,0x9
/*  f12d448:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f12d44c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f12d450:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12d454:	00992021 */ 	addu	$a0,$a0,$t9
/*  f12d458:	8484e942 */ 	lh	$a0,%lo(g_SmokeTypes+0x2)($a0)
/*  f12d45c:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f12d460:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f12d464:	0086082a */ 	slt	$at,$a0,$a2
/*  f12d468:	00401825 */ 	or	$v1,$v0,$zero
/*  f12d46c:	1420002b */ 	bnez	$at,.L0f12d51c
/*  f12d470:	25081bb0 */ 	addiu	$t0,$t0,7088
/*  f12d474:	44843000 */ 	mtc1	$a0,$f6
/*  f12d478:	c4e40020 */ 	lwc1	$f4,0x20($a3)
/*  f12d47c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f12d480:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f12d484:	44863000 */ 	mtc1	$a2,$f6
/*  f12d488:	3c014f00 */ 	lui	$at,0x4f00
/*  f12d48c:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f12d490:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f12d494:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f12d498:	444af800 */ 	cfc1	$t2,$31
/*  f12d49c:	44cbf800 */ 	ctc1	$t3,$31
/*  f12d4a0:	00000000 */ 	nop
/*  f12d4a4:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f12d4a8:	444bf800 */ 	cfc1	$t3,$31
/*  f12d4ac:	00000000 */ 	nop
/*  f12d4b0:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f12d4b4:	51600013 */ 	beqzl	$t3,.L0f12d504
/*  f12d4b8:	440b3000 */ 	mfc1	$t3,$f6
/*  f12d4bc:	44813000 */ 	mtc1	$at,$f6
/*  f12d4c0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f12d4c4:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f12d4c8:	44cbf800 */ 	ctc1	$t3,$31
/*  f12d4cc:	00000000 */ 	nop
/*  f12d4d0:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f12d4d4:	444bf800 */ 	cfc1	$t3,$31
/*  f12d4d8:	00000000 */ 	nop
/*  f12d4dc:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f12d4e0:	15600005 */ 	bnez	$t3,.L0f12d4f8
/*  f12d4e4:	00000000 */ 	nop
/*  f12d4e8:	440b3000 */ 	mfc1	$t3,$f6
/*  f12d4ec:	3c018000 */ 	lui	$at,0x8000
/*  f12d4f0:	10000007 */ 	b	.L0f12d510
/*  f12d4f4:	01615825 */ 	or	$t3,$t3,$at
.L0f12d4f8:
/*  f12d4f8:	10000005 */ 	b	.L0f12d510
/*  f12d4fc:	240bffff */ 	addiu	$t3,$zero,-1
/*  f12d500:	440b3000 */ 	mfc1	$t3,$f6
.L0f12d504:
/*  f12d504:	00000000 */ 	nop
/*  f12d508:	0560fffb */ 	bltz	$t3,.L0f12d4f8
/*  f12d50c:	00000000 */ 	nop
.L0f12d510:
/*  f12d510:	44caf800 */ 	ctc1	$t2,$31
/*  f12d514:	10000024 */ 	b	.L0f12d5a8
/*  f12d518:	a3ab0067 */ 	sb	$t3,0x67($sp)
.L0f12d51c:
/*  f12d51c:	444cf800 */ 	cfc1	$t4,$31
/*  f12d520:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f12d524:	44cdf800 */ 	ctc1	$t5,$31
/*  f12d528:	c4ea0020 */ 	lwc1	$f10,0x20($a3)
/*  f12d52c:	3c014f00 */ 	lui	$at,0x4f00
/*  f12d530:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f12d534:	444df800 */ 	cfc1	$t5,$31
/*  f12d538:	00000000 */ 	nop
/*  f12d53c:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f12d540:	51a00013 */ 	beqzl	$t5,.L0f12d590
/*  f12d544:	440d2000 */ 	mfc1	$t5,$f4
/*  f12d548:	44812000 */ 	mtc1	$at,$f4
/*  f12d54c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f12d550:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f12d554:	44cdf800 */ 	ctc1	$t5,$31
/*  f12d558:	00000000 */ 	nop
/*  f12d55c:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f12d560:	444df800 */ 	cfc1	$t5,$31
/*  f12d564:	00000000 */ 	nop
/*  f12d568:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f12d56c:	15a00005 */ 	bnez	$t5,.L0f12d584
/*  f12d570:	00000000 */ 	nop
/*  f12d574:	440d2000 */ 	mfc1	$t5,$f4
/*  f12d578:	3c018000 */ 	lui	$at,0x8000
/*  f12d57c:	10000007 */ 	b	.L0f12d59c
/*  f12d580:	01a16825 */ 	or	$t5,$t5,$at
.L0f12d584:
/*  f12d584:	10000005 */ 	b	.L0f12d59c
/*  f12d588:	240dffff */ 	addiu	$t5,$zero,-1
/*  f12d58c:	440d2000 */ 	mfc1	$t5,$f4
.L0f12d590:
/*  f12d590:	00000000 */ 	nop
/*  f12d594:	05a0fffb */ 	bltz	$t5,.L0f12d584
/*  f12d598:	00000000 */ 	nop
.L0f12d59c:
/*  f12d59c:	44ccf800 */ 	ctc1	$t4,$31
/*  f12d5a0:	a3ad0067 */ 	sb	$t5,0x67($sp)
/*  f12d5a4:	00000000 */ 	nop
.L0f12d5a8:
/*  f12d5a8:	c4ec0010 */ 	lwc1	$f12,0x10($a3)
/*  f12d5ac:	afa80060 */ 	sw	$t0,0x60($sp)
/*  f12d5b0:	afa500b4 */ 	sw	$a1,0xb4($sp)
/*  f12d5b4:	0c0068f4 */ 	jal	cosf
/*  f12d5b8:	afa300ac */ 	sw	$v1,0xac($sp)
/*  f12d5bc:	8fa200bc */ 	lw	$v0,0xbc($sp)
/*  f12d5c0:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f12d5c4:	c44c0010 */ 	lwc1	$f12,0x10($v0)
/*  f12d5c8:	46080382 */ 	mul.s	$f14,$f0,$f8
/*  f12d5cc:	0c0068f7 */ 	jal	sinf
/*  f12d5d0:	e7ae0078 */ 	swc1	$f14,0x78($sp)
/*  f12d5d4:	8fa200bc */ 	lw	$v0,0xbc($sp)
/*  f12d5d8:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f12d5dc:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f12d5e0:	46060402 */ 	mul.s	$f16,$f0,$f6
/*  f12d5e4:	0c0068f7 */ 	jal	sinf
/*  f12d5e8:	e7b00074 */ 	swc1	$f16,0x74($sp)
/*  f12d5ec:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f12d5f0:	3c018008 */ 	lui	$at,%hi(g_SmokeTypes+0x20)
/*  f12d5f4:	8fa200bc */ 	lw	$v0,0xbc($sp)
/*  f12d5f8:	95cf0006 */ 	lhu	$t7,0x6($t6)
/*  f12d5fc:	000fc242 */ 	srl	$t8,$t7,0x9
/*  f12d600:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f12d604:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f12d608:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12d60c:	00390821 */ 	addu	$at,$at,$t9
/*  f12d610:	c42ae960 */ 	lwc1	$f10,%lo(g_SmokeTypes+0x20)($at)
/*  f12d614:	3c0140e0 */ 	lui	$at,0x40e0
/*  f12d618:	44812000 */ 	mtc1	$at,$f4
/*  f12d61c:	00000000 */ 	nop
/*  f12d620:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f12d624:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f12d628:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f12d62c:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f12d630:	e7aa0070 */ 	swc1	$f10,0x70($sp)
/*  f12d634:	c4480004 */ 	lwc1	$f8,0x4($v0)
/*  f12d638:	e7a8006c */ 	swc1	$f8,0x6c($sp)
/*  f12d63c:	0c0068f7 */ 	jal	sinf
/*  f12d640:	c44c001c */ 	lwc1	$f12,0x1c($v0)
/*  f12d644:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f12d648:	3c018008 */ 	lui	$at,%hi(g_SmokeTypes+0x20)
/*  f12d64c:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f12d650:	954b0006 */ 	lhu	$t3,0x6($t2)
/*  f12d654:	8fa80060 */ 	lw	$t0,0x60($sp)
/*  f12d658:	000b6242 */ 	srl	$t4,$t3,0x9
/*  f12d65c:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f12d660:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f12d664:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f12d668:	002d0821 */ 	addu	$at,$at,$t5
/*  f12d66c:	c426e960 */ 	lwc1	$f6,%lo(g_SmokeTypes+0x20)($at)
/*  f12d670:	3c0140e0 */ 	lui	$at,0x40e0
/*  f12d674:	44812000 */ 	mtc1	$at,$f4
/*  f12d678:	00000000 */ 	nop
/*  f12d67c:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f12d680:	c5c40008 */ 	lwc1	$f4,0x8($t6)
/*  f12d684:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f12d688:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f12d68c:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f12d690:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f12d694:	e7a60068 */ 	swc1	$f6,0x68($sp)
/*  f12d698:	c5080000 */ 	lwc1	$f8,0x0($t0)
/*  f12d69c:	46085481 */ 	sub.s	$f18,$f10,$f8
/*  f12d6a0:	c50a0004 */ 	lwc1	$f10,0x4($t0)
/*  f12d6a4:	c5080008 */ 	lwc1	$f8,0x8($t0)
/*  f12d6a8:	460a2081 */ 	sub.s	$f2,$f4,$f10
/*  f12d6ac:	46129282 */ 	mul.s	$f10,$f18,$f18
/*  f12d6b0:	e7b2005c */ 	swc1	$f18,0x5c($sp)
/*  f12d6b4:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f12d6b8:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f12d6bc:	e7a20058 */ 	swc1	$f2,0x58($sp)
/*  f12d6c0:	e7a40054 */ 	swc1	$f4,0x54($sp)
/*  f12d6c4:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f12d6c8:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f12d6cc:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*  f12d6d0:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f12d6d4:	0c012974 */ 	jal	sqrtf
/*  f12d6d8:	46064300 */ 	add.s	$f12,$f8,$f6
/*  f12d6dc:	3c017f1b */ 	lui	$at,%hi(var7f1b55d0)
/*  f12d6e0:	c42455d0 */ 	lwc1	$f4,%lo(var7f1b55d0)($at)
/*  f12d6e4:	3c068008 */ 	lui	$a2,%hi(g_SmokeTypes)
/*  f12d6e8:	24c6e940 */ 	addiu	$a2,$a2,%lo(g_SmokeTypes)
/*  f12d6ec:	4600203c */ 	c.lt.s	$f4,$f0
/*  f12d6f0:	8fa300ac */ 	lw	$v1,0xac($sp)
/*  f12d6f4:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f12d6f8:	24070024 */ 	addiu	$a3,$zero,0x24
/*  f12d6fc:	8fa80060 */ 	lw	$t0,0x60($sp)
/*  f12d700:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f12d704:	c7ae0078 */ 	lwc1	$f14,0x78($sp)
/*  f12d708:	c7b00074 */ 	lwc1	$f16,0x74($sp)
/*  f12d70c:	45000003 */ 	bc1f	.L0f12d71c
/*  f12d710:	c7b2005c */ 	lwc1	$f18,0x5c($sp)
/*  f12d714:	100002a5 */ 	b	.L0f12e1ac
/*  f12d718:	02201025 */ 	or	$v0,$s1,$zero
.L0f12d71c:
/*  f12d71c:	3c013f00 */ 	lui	$at,0x3f00
/*  f12d720:	44815000 */ 	mtc1	$at,$f10
/*  f12d724:	3c0142c8 */ 	lui	$at,0x42c8
/*  f12d728:	44814000 */ 	mtc1	$at,$f8
/*  f12d72c:	460a0302 */ 	mul.s	$f12,$f0,$f10
/*  f12d730:	44803000 */ 	mtc1	$zero,$f6
/*  f12d734:	3c0142c8 */ 	lui	$at,0x42c8
/*  f12d738:	460c403c */ 	c.lt.s	$f8,$f12
/*  f12d73c:	00000000 */ 	nop
/*  f12d740:	45020004 */ 	bc1fl	.L0f12d754
/*  f12d744:	46060032 */ 	c.eq.s	$f0,$f6
/*  f12d748:	44816000 */ 	mtc1	$at,$f12
/*  f12d74c:	00000000 */ 	nop
/*  f12d750:	46060032 */ 	c.eq.s	$f0,$f6
.L0f12d754:
/*  f12d754:	00000000 */ 	nop
/*  f12d758:	45020005 */ 	bc1fl	.L0f12d770
/*  f12d75c:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f12d760:	44801000 */ 	mtc1	$zero,$f2
/*  f12d764:	10000003 */ 	b	.L0f12d774
/*  f12d768:	00000000 */ 	nop
/*  f12d76c:	460c0101 */ 	sub.s	$f4,$f0,$f12
.L0f12d770:
/*  f12d770:	46002083 */ 	div.s	$f2,$f4,$f0
.L0f12d774:
/*  f12d774:	46027382 */ 	mul.s	$f14,$f14,$f2
/*  f12d778:	c50a0000 */ 	lwc1	$f10,0x0($t0)
/*  f12d77c:	3c017f1b */ 	lui	$at,%hi(var7f1b55d4)
/*  f12d780:	46028402 */ 	mul.s	$f16,$f16,$f2
/*  f12d784:	00000000 */ 	nop
/*  f12d788:	46029202 */ 	mul.s	$f8,$f18,$f2
/*  f12d78c:	c7b200c8 */ 	lwc1	$f18,0xc8($sp)
/*  f12d790:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f12d794:	c7aa0058 */ 	lwc1	$f10,0x58($sp)
/*  f12d798:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f12d79c:	e7a60070 */ 	swc1	$f6,0x70($sp)
/*  f12d7a0:	c5040004 */ 	lwc1	$f4,0x4($t0)
/*  f12d7a4:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f12d7a8:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f12d7ac:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f12d7b0:	e7a6006c */ 	swc1	$f6,0x6c($sp)
/*  f12d7b4:	c50a0008 */ 	lwc1	$f10,0x8($t0)
/*  f12d7b8:	c42255d4 */ 	lwc1	$f2,%lo(var7f1b55d4)($at)
/*  f12d7bc:	3c017f1b */ 	lui	$at,%hi(var7f1b55d8)
/*  f12d7c0:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f12d7c4:	e7a60068 */ 	swc1	$f6,0x68($sp)
/*  f12d7c8:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f12d7cc:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*  f12d7d0:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f12d7d4:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f12d7d8:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f12d7dc:	e7a600a4 */ 	swc1	$f6,0xa4($sp)
/*  f12d7e0:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f12d7e4:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*  f12d7e8:	e7aa00a8 */ 	swc1	$f10,0xa8($sp)
/*  f12d7ec:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f12d7f0:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f12d7f4:	e7a60094 */ 	swc1	$f6,0x94($sp)
/*  f12d7f8:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f12d7fc:	46102282 */ 	mul.s	$f10,$f4,$f16
/*  f12d800:	e7aa0098 */ 	swc1	$f10,0x98($sp)
/*  f12d804:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f12d808:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f12d80c:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f12d810:	c4640010 */ 	lwc1	$f4,0x10($v1)
/*  f12d814:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*  f12d818:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f12d81c:	c4680014 */ 	lwc1	$f8,0x14($v1)
/*  f12d820:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f12d824:	e7a6008c */ 	swc1	$f6,0x8c($sp)
/*  f12d828:	c4640018 */ 	lwc1	$f4,0x18($v1)
/*  f12d82c:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*  f12d830:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f12d834:	c4680010 */ 	lwc1	$f8,0x10($v1)
/*  f12d838:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f12d83c:	e7a6007c */ 	swc1	$f6,0x7c($sp)
/*  f12d840:	c4640014 */ 	lwc1	$f4,0x14($v1)
/*  f12d844:	46102282 */ 	mul.s	$f10,$f4,$f16
/*  f12d848:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f12d84c:	e7aa0080 */ 	swc1	$f10,0x80($sp)
/*  f12d850:	c4680018 */ 	lwc1	$f8,0x18($v1)
/*  f12d854:	c7aa00a0 */ 	lwc1	$f10,0xa0($sp)
/*  f12d858:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f12d85c:	460a2201 */ 	sub.s	$f8,$f4,$f10
/*  f12d860:	e7a60084 */ 	swc1	$f6,0x84($sp)
/*  f12d864:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*  f12d868:	46064101 */ 	sub.s	$f4,$f8,$f6
/*  f12d86c:	c5280000 */ 	lwc1	$f8,0x0($t1)
/*  f12d870:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f12d874:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f12d878:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f12d87c:	c7aa00a4 */ 	lwc1	$f10,0xa4($sp)
/*  f12d880:	460a2201 */ 	sub.s	$f8,$f4,$f10
/*  f12d884:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f12d888:	e7a60044 */ 	swc1	$f6,0x44($sp)
/*  f12d88c:	4606103c */ 	c.lt.s	$f2,$f6
/*  f12d890:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f12d894:	c5240004 */ 	lwc1	$f4,0x4($t1)
/*  f12d898:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f12d89c:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f12d8a0:	c7a400a8 */ 	lwc1	$f4,0xa8($sp)
/*  f12d8a4:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*  f12d8a8:	e7aa0040 */ 	swc1	$f10,0x40($sp)
/*  f12d8ac:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f12d8b0:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f12d8b4:	46085101 */ 	sub.s	$f4,$f10,$f8
/*  f12d8b8:	c5280008 */ 	lwc1	$f8,0x8($t1)
/*  f12d8bc:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f12d8c0:	46085101 */ 	sub.s	$f4,$f10,$f8
/*  f12d8c4:	45010017 */ 	bc1t	.L0f12d924
/*  f12d8c8:	e7a4003c */ 	swc1	$f4,0x3c($sp)
/*  f12d8cc:	c42055d8 */ 	lwc1	$f0,%lo(var7f1b55d8)($at)
/*  f12d8d0:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*  f12d8d4:	4600303c */ 	c.lt.s	$f6,$f0
/*  f12d8d8:	00000000 */ 	nop
/*  f12d8dc:	45010011 */ 	bc1t	.L0f12d924
/*  f12d8e0:	00000000 */ 	nop
/*  f12d8e4:	460a103c */ 	c.lt.s	$f2,$f10
/*  f12d8e8:	c7a80040 */ 	lwc1	$f8,0x40($sp)
/*  f12d8ec:	4501000d */ 	bc1t	.L0f12d924
/*  f12d8f0:	00000000 */ 	nop
/*  f12d8f4:	4600403c */ 	c.lt.s	$f8,$f0
/*  f12d8f8:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*  f12d8fc:	45010009 */ 	bc1t	.L0f12d924
/*  f12d900:	00000000 */ 	nop
/*  f12d904:	4604103c */ 	c.lt.s	$f2,$f4
/*  f12d908:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*  f12d90c:	45010005 */ 	bc1t	.L0f12d924
/*  f12d910:	00000000 */ 	nop
/*  f12d914:	4600303c */ 	c.lt.s	$f6,$f0
/*  f12d918:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f12d91c:	45000003 */ 	bc1f	.L0f12d92c
/*  f12d920:	00000000 */ 	nop
.L0f12d924:
/*  f12d924:	10000221 */ 	b	.L0f12e1ac
/*  f12d928:	02201025 */ 	or	$v0,$s1,$zero
.L0f12d92c:
/*  f12d92c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f12d930:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12d934:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f12d938:	944f0010 */ 	lhu	$t7,0x10($v0)
/*  f12d93c:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f12d940:	55e100b0 */ 	bnel	$t7,$at,.L0f12dc04
/*  f12d944:	94620006 */ 	lhu	$v0,0x6($v1)
/*  f12d948:	c4480020 */ 	lwc1	$f8,0x20($v0)
/*  f12d94c:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f12d950:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f12d954:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f12d958:	c448001c */ 	lwc1	$f8,0x1c($v0)
/*  f12d95c:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f12d960:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f12d964:	3c013f00 */ 	lui	$at,0x3f00
/*  f12d968:	44818000 */ 	mtc1	$at,$f16
/*  f12d96c:	46085381 */ 	sub.s	$f14,$f10,$f8
/*  f12d970:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f12d974:	afa500b4 */ 	sw	$a1,0xb4($sp)
/*  f12d978:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f12d97c:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f12d980:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f12d984:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f12d988:	0c012974 */ 	jal	sqrtf
/*  f12d98c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f12d990:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f12d994:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f12d998:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f12d99c:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f12d9a0:	c70c0024 */ 	lwc1	$f12,0x24($t8)
/*  f12d9a4:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f12d9a8:	c7b200c8 */ 	lwc1	$f18,0xc8($sp)
/*  f12d9ac:	4600603c */ 	c.lt.s	$f12,$f0
/*  f12d9b0:	3c014316 */ 	lui	$at,0x4316
/*  f12d9b4:	45020004 */ 	bc1fl	.L0f12d9c8
/*  f12d9b8:	44812000 */ 	mtc1	$at,$f4
/*  f12d9bc:	100001fb */ 	b	.L0f12e1ac
/*  f12d9c0:	02201025 */ 	or	$v0,$s1,$zero
/*  f12d9c4:	44812000 */ 	mtc1	$at,$f4
.L0f12d9c8:
/*  f12d9c8:	3c013f80 */ 	lui	$at,0x3f80
/*  f12d9cc:	46046081 */ 	sub.s	$f2,$f12,$f4
/*  f12d9d0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f12d9d4:	00000000 */ 	nop
/*  f12d9d8:	4502000c */ 	bc1fl	.L0f12da0c
/*  f12d9dc:	460c0083 */ 	div.s	$f2,$f0,$f12
/*  f12d9e0:	44817000 */ 	mtc1	$at,$f14
/*  f12d9e4:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f12d9e8:	3c014316 */ 	lui	$at,0x4316
/*  f12d9ec:	44814000 */ 	mtc1	$at,$f8
/*  f12d9f0:	3c013f00 */ 	lui	$at,0x3f00
/*  f12d9f4:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f12d9f8:	44813000 */ 	mtc1	$at,$f6
/*  f12d9fc:	460a7101 */ 	sub.s	$f4,$f14,$f10
/*  f12da00:	46062402 */ 	mul.s	$f16,$f4,$f6
/*  f12da04:	00000000 */ 	nop
/*  f12da08:	460c0083 */ 	div.s	$f2,$f0,$f12
.L0f12da0c:
/*  f12da0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f12da10:	44817000 */ 	mtc1	$at,$f14
/*  f12da14:	3c01437f */ 	lui	$at,0x437f
/*  f12da18:	44810000 */ 	mtc1	$at,$f0
/*  f12da1c:	3c014f00 */ 	lui	$at,0x4f00
/*  f12da20:	4602703c */ 	c.lt.s	$f14,$f2
/*  f12da24:	00000000 */ 	nop
/*  f12da28:	45000002 */ 	bc1f	.L0f12da34
/*  f12da2c:	00000000 */ 	nop
/*  f12da30:	46007086 */ 	mov.s	$f2,$f14
.L0f12da34:
/*  f12da34:	46001202 */ 	mul.s	$f8,$f2,$f0
/*  f12da38:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f12da3c:	4459f800 */ 	cfc1	$t9,$31
/*  f12da40:	44caf800 */ 	ctc1	$t2,$31
/*  f12da44:	00000000 */ 	nop
/*  f12da48:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f12da4c:	444af800 */ 	cfc1	$t2,$31
/*  f12da50:	00000000 */ 	nop
/*  f12da54:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f12da58:	51400013 */ 	beqzl	$t2,.L0f12daa8
/*  f12da5c:	440a5000 */ 	mfc1	$t2,$f10
/*  f12da60:	44815000 */ 	mtc1	$at,$f10
/*  f12da64:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f12da68:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f12da6c:	44caf800 */ 	ctc1	$t2,$31
/*  f12da70:	00000000 */ 	nop
/*  f12da74:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f12da78:	444af800 */ 	cfc1	$t2,$31
/*  f12da7c:	00000000 */ 	nop
/*  f12da80:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f12da84:	15400005 */ 	bnez	$t2,.L0f12da9c
/*  f12da88:	00000000 */ 	nop
/*  f12da8c:	440a5000 */ 	mfc1	$t2,$f10
/*  f12da90:	3c018000 */ 	lui	$at,0x8000
/*  f12da94:	10000007 */ 	b	.L0f12dab4
/*  f12da98:	01415025 */ 	or	$t2,$t2,$at
.L0f12da9c:
/*  f12da9c:	10000005 */ 	b	.L0f12dab4
/*  f12daa0:	240affff */ 	addiu	$t2,$zero,-1
/*  f12daa4:	440a5000 */ 	mfc1	$t2,$f10
.L0f12daa8:
/*  f12daa8:	00000000 */ 	nop
/*  f12daac:	0540fffb */ 	bltz	$t2,.L0f12da9c
/*  f12dab0:	00000000 */ 	nop
.L0f12dab4:
/*  f12dab4:	44d9f800 */ 	ctc1	$t9,$31
/*  f12dab8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f12dabc:	a20a0000 */ 	sb	$t2,0x0($s0)
/*  f12dac0:	46027101 */ 	sub.s	$f4,$f14,$f2
/*  f12dac4:	3c014f00 */ 	lui	$at,0x4f00
/*  f12dac8:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f12dacc:	444bf800 */ 	cfc1	$t3,$31
/*  f12dad0:	44ccf800 */ 	ctc1	$t4,$31
/*  f12dad4:	00000000 */ 	nop
/*  f12dad8:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f12dadc:	444cf800 */ 	cfc1	$t4,$31
/*  f12dae0:	00000000 */ 	nop
/*  f12dae4:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f12dae8:	51800013 */ 	beqzl	$t4,.L0f12db38
/*  f12daec:	440c4000 */ 	mfc1	$t4,$f8
/*  f12daf0:	44814000 */ 	mtc1	$at,$f8
/*  f12daf4:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f12daf8:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f12dafc:	44ccf800 */ 	ctc1	$t4,$31
/*  f12db00:	00000000 */ 	nop
/*  f12db04:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f12db08:	444cf800 */ 	cfc1	$t4,$31
/*  f12db0c:	00000000 */ 	nop
/*  f12db10:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f12db14:	15800005 */ 	bnez	$t4,.L0f12db2c
/*  f12db18:	00000000 */ 	nop
/*  f12db1c:	440c4000 */ 	mfc1	$t4,$f8
/*  f12db20:	3c018000 */ 	lui	$at,0x8000
/*  f12db24:	10000007 */ 	b	.L0f12db44
/*  f12db28:	01816025 */ 	or	$t4,$t4,$at
.L0f12db2c:
/*  f12db2c:	10000005 */ 	b	.L0f12db44
/*  f12db30:	240cffff */ 	addiu	$t4,$zero,-1
/*  f12db34:	440c4000 */ 	mfc1	$t4,$f8
.L0f12db38:
/*  f12db38:	00000000 */ 	nop
/*  f12db3c:	0580fffb */ 	bltz	$t4,.L0f12db2c
/*  f12db40:	00000000 */ 	nop
.L0f12db44:
/*  f12db44:	a20c0001 */ 	sb	$t4,0x1($s0)
/*  f12db48:	a2000002 */ 	sb	$zero,0x2($s0)
/*  f12db4c:	93ad0067 */ 	lbu	$t5,0x67($sp)
/*  f12db50:	44cbf800 */ 	ctc1	$t3,$31
/*  f12db54:	3c014f80 */ 	lui	$at,0x4f80
/*  f12db58:	448d5000 */ 	mtc1	$t5,$f10
/*  f12db5c:	05a10004 */ 	bgez	$t5,.L0f12db70
/*  f12db60:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f12db64:	44813000 */ 	mtc1	$at,$f6
/*  f12db68:	00000000 */ 	nop
/*  f12db6c:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f12db70:
/*  f12db70:	46102202 */ 	mul.s	$f8,$f4,$f16
/*  f12db74:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f12db78:	3c014f00 */ 	lui	$at,0x4f00
/*  f12db7c:	444ef800 */ 	cfc1	$t6,$31
/*  f12db80:	44cff800 */ 	ctc1	$t7,$31
/*  f12db84:	00000000 */ 	nop
/*  f12db88:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f12db8c:	444ff800 */ 	cfc1	$t7,$31
/*  f12db90:	00000000 */ 	nop
/*  f12db94:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f12db98:	51e00013 */ 	beqzl	$t7,.L0f12dbe8
/*  f12db9c:	440f5000 */ 	mfc1	$t7,$f10
/*  f12dba0:	44815000 */ 	mtc1	$at,$f10
/*  f12dba4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f12dba8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f12dbac:	44cff800 */ 	ctc1	$t7,$31
/*  f12dbb0:	00000000 */ 	nop
/*  f12dbb4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f12dbb8:	444ff800 */ 	cfc1	$t7,$31
/*  f12dbbc:	00000000 */ 	nop
/*  f12dbc0:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f12dbc4:	15e00005 */ 	bnez	$t7,.L0f12dbdc
/*  f12dbc8:	00000000 */ 	nop
/*  f12dbcc:	440f5000 */ 	mfc1	$t7,$f10
/*  f12dbd0:	3c018000 */ 	lui	$at,0x8000
/*  f12dbd4:	10000007 */ 	b	.L0f12dbf4
/*  f12dbd8:	01e17825 */ 	or	$t7,$t7,$at
.L0f12dbdc:
/*  f12dbdc:	10000005 */ 	b	.L0f12dbf4
/*  f12dbe0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f12dbe4:	440f5000 */ 	mfc1	$t7,$f10
.L0f12dbe8:
/*  f12dbe8:	00000000 */ 	nop
/*  f12dbec:	05e0fffb */ 	bltz	$t7,.L0f12dbdc
/*  f12dbf0:	00000000 */ 	nop
.L0f12dbf4:
/*  f12dbf4:	44cef800 */ 	ctc1	$t6,$31
/*  f12dbf8:	100000ca */ 	b	.L0f12df24
/*  f12dbfc:	a20f0003 */ 	sb	$t7,0x3($s0)
/*  f12dc00:	94620006 */ 	lhu	$v0,0x6($v1)
.L0f12dc04:
/*  f12dc04:	24010013 */ 	addiu	$at,$zero,0x13
/*  f12dc08:	0002c242 */ 	srl	$t8,$v0,0x9
/*  f12dc0c:	130100b0 */ 	beq	$t8,$at,.L0f12ded0
/*  f12dc10:	03001025 */ 	or	$v0,$t8,$zero
/*  f12dc14:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f12dc18:	87240028 */ 	lh	$a0,0x28($t9)
/*  f12dc1c:	0fc00284 */ 	jal	func0f000a10
/*  f12dc20:	afa500b4 */ 	sw	$a1,0xb4($sp)
/*  f12dc24:	44823000 */ 	mtc1	$v0,$f6
/*  f12dc28:	3c013f80 */ 	lui	$at,0x3f80
/*  f12dc2c:	44816000 */ 	mtc1	$at,$f12
/*  f12dc30:	3c068008 */ 	lui	$a2,%hi(g_SmokeTypes)
/*  f12dc34:	24c6e940 */ 	addiu	$a2,$a2,%lo(g_SmokeTypes)
/*  f12dc38:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f12dc3c:	24070024 */ 	addiu	$a3,$zero,0x24
/*  f12dc40:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f12dc44:	c7b200c8 */ 	lwc1	$f18,0xc8($sp)
/*  f12dc48:	04410005 */ 	bgez	$v0,.L0f12dc60
/*  f12dc4c:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f12dc50:	3c014f80 */ 	lui	$at,0x4f80
/*  f12dc54:	44814000 */ 	mtc1	$at,$f8
/*  f12dc58:	00000000 */ 	nop
/*  f12dc5c:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f12dc60:
/*  f12dc60:	3c017f1b */ 	lui	$at,%hi(var7f1b55dc)
/*  f12dc64:	c42a55dc */ 	lwc1	$f10,%lo(var7f1b55dc)($at)
/*  f12dc68:	3c014f80 */ 	lui	$at,0x4f80
/*  f12dc6c:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f12dc70:	460a2082 */ 	mul.s	$f2,$f4,$f10
/*  f12dc74:	4602603c */ 	c.lt.s	$f12,$f2
/*  f12dc78:	00000000 */ 	nop
/*  f12dc7c:	45020003 */ 	bc1fl	.L0f12dc8c
/*  f12dc80:	954b0006 */ 	lhu	$t3,0x6($t2)
/*  f12dc84:	46006086 */ 	mov.s	$f2,$f12
/*  f12dc88:	954b0006 */ 	lhu	$t3,0x6($t2)
.L0f12dc8c:
/*  f12dc8c:	000b6242 */ 	srl	$t4,$t3,0x9
/*  f12dc90:	01870019 */ 	multu	$t4,$a3
/*  f12dc94:	00006812 */ 	mflo	$t5
/*  f12dc98:	00cd7021 */ 	addu	$t6,$a2,$t5
/*  f12dc9c:	91cf000c */ 	lbu	$t7,0xc($t6)
/*  f12dca0:	448f3000 */ 	mtc1	$t7,$f6
/*  f12dca4:	05e10004 */ 	bgez	$t7,.L0f12dcb8
/*  f12dca8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f12dcac:	44812000 */ 	mtc1	$at,$f4
/*  f12dcb0:	00000000 */ 	nop
/*  f12dcb4:	46044200 */ 	add.s	$f8,$f8,$f4
.L0f12dcb8:
/*  f12dcb8:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f12dcbc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f12dcc0:	3c014f00 */ 	lui	$at,0x4f00
/*  f12dcc4:	4458f800 */ 	cfc1	$t8,$31
/*  f12dcc8:	44d9f800 */ 	ctc1	$t9,$31
/*  f12dccc:	00000000 */ 	nop
/*  f12dcd0:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f12dcd4:	4459f800 */ 	cfc1	$t9,$31
/*  f12dcd8:	00000000 */ 	nop
/*  f12dcdc:	33390078 */ 	andi	$t9,$t9,0x78
/*  f12dce0:	53200013 */ 	beqzl	$t9,.L0f12dd30
/*  f12dce4:	44193000 */ 	mfc1	$t9,$f6
/*  f12dce8:	44813000 */ 	mtc1	$at,$f6
/*  f12dcec:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f12dcf0:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f12dcf4:	44d9f800 */ 	ctc1	$t9,$31
/*  f12dcf8:	00000000 */ 	nop
/*  f12dcfc:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f12dd00:	4459f800 */ 	cfc1	$t9,$31
/*  f12dd04:	00000000 */ 	nop
/*  f12dd08:	33390078 */ 	andi	$t9,$t9,0x78
/*  f12dd0c:	17200005 */ 	bnez	$t9,.L0f12dd24
/*  f12dd10:	00000000 */ 	nop
/*  f12dd14:	44193000 */ 	mfc1	$t9,$f6
/*  f12dd18:	3c018000 */ 	lui	$at,0x8000
/*  f12dd1c:	10000007 */ 	b	.L0f12dd3c
/*  f12dd20:	0321c825 */ 	or	$t9,$t9,$at
.L0f12dd24:
/*  f12dd24:	10000005 */ 	b	.L0f12dd3c
/*  f12dd28:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f12dd2c:	44193000 */ 	mfc1	$t9,$f6
.L0f12dd30:
/*  f12dd30:	00000000 */ 	nop
/*  f12dd34:	0720fffb */ 	bltz	$t9,.L0f12dd24
/*  f12dd38:	00000000 */ 	nop
.L0f12dd3c:
/*  f12dd3c:	a2190000 */ 	sb	$t9,0x0($s0)
/*  f12dd40:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*  f12dd44:	44d8f800 */ 	ctc1	$t8,$31
/*  f12dd48:	3c014f80 */ 	lui	$at,0x4f80
/*  f12dd4c:	956c0006 */ 	lhu	$t4,0x6($t3)
/*  f12dd50:	000c6a42 */ 	srl	$t5,$t4,0x9
/*  f12dd54:	01a70019 */ 	multu	$t5,$a3
/*  f12dd58:	00007012 */ 	mflo	$t6
/*  f12dd5c:	00ce7821 */ 	addu	$t7,$a2,$t6
/*  f12dd60:	91f8000d */ 	lbu	$t8,0xd($t7)
/*  f12dd64:	44982000 */ 	mtc1	$t8,$f4
/*  f12dd68:	07010004 */ 	bgez	$t8,.L0f12dd7c
/*  f12dd6c:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f12dd70:	44815000 */ 	mtc1	$at,$f10
/*  f12dd74:	00000000 */ 	nop
/*  f12dd78:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f12dd7c:
/*  f12dd7c:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f12dd80:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f12dd84:	3c014f00 */ 	lui	$at,0x4f00
/*  f12dd88:	4459f800 */ 	cfc1	$t9,$31
/*  f12dd8c:	44caf800 */ 	ctc1	$t2,$31
/*  f12dd90:	00000000 */ 	nop
/*  f12dd94:	46003124 */ 	cvt.w.s	$f4,$f6
/*  f12dd98:	444af800 */ 	cfc1	$t2,$31
/*  f12dd9c:	00000000 */ 	nop
/*  f12dda0:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f12dda4:	51400013 */ 	beqzl	$t2,.L0f12ddf4
/*  f12dda8:	440a2000 */ 	mfc1	$t2,$f4
/*  f12ddac:	44812000 */ 	mtc1	$at,$f4
/*  f12ddb0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f12ddb4:	46043101 */ 	sub.s	$f4,$f6,$f4
/*  f12ddb8:	44caf800 */ 	ctc1	$t2,$31
/*  f12ddbc:	00000000 */ 	nop
/*  f12ddc0:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f12ddc4:	444af800 */ 	cfc1	$t2,$31
/*  f12ddc8:	00000000 */ 	nop
/*  f12ddcc:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f12ddd0:	15400005 */ 	bnez	$t2,.L0f12dde8
/*  f12ddd4:	00000000 */ 	nop
/*  f12ddd8:	440a2000 */ 	mfc1	$t2,$f4
/*  f12dddc:	3c018000 */ 	lui	$at,0x8000
/*  f12dde0:	10000007 */ 	b	.L0f12de00
/*  f12dde4:	01415025 */ 	or	$t2,$t2,$at
.L0f12dde8:
/*  f12dde8:	10000005 */ 	b	.L0f12de00
/*  f12ddec:	240affff */ 	addiu	$t2,$zero,-1
/*  f12ddf0:	440a2000 */ 	mfc1	$t2,$f4
.L0f12ddf4:
/*  f12ddf4:	00000000 */ 	nop
/*  f12ddf8:	0540fffb */ 	bltz	$t2,.L0f12dde8
/*  f12ddfc:	00000000 */ 	nop
.L0f12de00:
/*  f12de00:	a20a0001 */ 	sb	$t2,0x1($s0)
/*  f12de04:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f12de08:	44d9f800 */ 	ctc1	$t9,$31
/*  f12de0c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12de10:	958d0006 */ 	lhu	$t5,0x6($t4)
/*  f12de14:	000d7242 */ 	srl	$t6,$t5,0x9
/*  f12de18:	01c70019 */ 	multu	$t6,$a3
/*  f12de1c:	00007812 */ 	mflo	$t7
/*  f12de20:	00cfc021 */ 	addu	$t8,$a2,$t7
/*  f12de24:	9319000e */ 	lbu	$t9,0xe($t8)
/*  f12de28:	44995000 */ 	mtc1	$t9,$f10
/*  f12de2c:	07210004 */ 	bgez	$t9,.L0f12de40
/*  f12de30:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f12de34:	44813000 */ 	mtc1	$at,$f6
/*  f12de38:	00000000 */ 	nop
/*  f12de3c:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f12de40:
/*  f12de40:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f12de44:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f12de48:	3c014f00 */ 	lui	$at,0x4f00
/*  f12de4c:	444af800 */ 	cfc1	$t2,$31
/*  f12de50:	44cbf800 */ 	ctc1	$t3,$31
/*  f12de54:	00000000 */ 	nop
/*  f12de58:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f12de5c:	444bf800 */ 	cfc1	$t3,$31
/*  f12de60:	00000000 */ 	nop
/*  f12de64:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f12de68:	51600013 */ 	beqzl	$t3,.L0f12deb8
/*  f12de6c:	440b5000 */ 	mfc1	$t3,$f10
/*  f12de70:	44815000 */ 	mtc1	$at,$f10
/*  f12de74:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f12de78:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f12de7c:	44cbf800 */ 	ctc1	$t3,$31
/*  f12de80:	00000000 */ 	nop
/*  f12de84:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f12de88:	444bf800 */ 	cfc1	$t3,$31
/*  f12de8c:	00000000 */ 	nop
/*  f12de90:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f12de94:	15600005 */ 	bnez	$t3,.L0f12deac
/*  f12de98:	00000000 */ 	nop
/*  f12de9c:	440b5000 */ 	mfc1	$t3,$f10
/*  f12dea0:	3c018000 */ 	lui	$at,0x8000
/*  f12dea4:	10000007 */ 	b	.L0f12dec4
/*  f12dea8:	01615825 */ 	or	$t3,$t3,$at
.L0f12deac:
/*  f12deac:	10000005 */ 	b	.L0f12dec4
/*  f12deb0:	240bffff */ 	addiu	$t3,$zero,-1
/*  f12deb4:	440b5000 */ 	mfc1	$t3,$f10
.L0f12deb8:
/*  f12deb8:	00000000 */ 	nop
/*  f12debc:	0560fffb */ 	bltz	$t3,.L0f12deac
/*  f12dec0:	00000000 */ 	nop
.L0f12dec4:
/*  f12dec4:	44caf800 */ 	ctc1	$t2,$31
/*  f12dec8:	10000014 */ 	b	.L0f12df1c
/*  f12decc:	a20b0002 */ 	sb	$t3,0x2($s0)
.L0f12ded0:
/*  f12ded0:	00470019 */ 	multu	$v0,$a3
/*  f12ded4:	00006812 */ 	mflo	$t5
/*  f12ded8:	00cd7021 */ 	addu	$t6,$a2,$t5
/*  f12dedc:	91cf000c */ 	lbu	$t7,0xc($t6)
/*  f12dee0:	a20f0000 */ 	sb	$t7,0x0($s0)
/*  f12dee4:	94780006 */ 	lhu	$t8,0x6($v1)
/*  f12dee8:	0018ca42 */ 	srl	$t9,$t8,0x9
/*  f12deec:	03270019 */ 	multu	$t9,$a3
/*  f12def0:	00005012 */ 	mflo	$t2
/*  f12def4:	00ca5821 */ 	addu	$t3,$a2,$t2
/*  f12def8:	916c000d */ 	lbu	$t4,0xd($t3)
/*  f12defc:	a20c0001 */ 	sb	$t4,0x1($s0)
/*  f12df00:	946d0006 */ 	lhu	$t5,0x6($v1)
/*  f12df04:	000d7242 */ 	srl	$t6,$t5,0x9
/*  f12df08:	01c70019 */ 	multu	$t6,$a3
/*  f12df0c:	00007812 */ 	mflo	$t7
/*  f12df10:	00cfc021 */ 	addu	$t8,$a2,$t7
/*  f12df14:	9319000e */ 	lbu	$t9,0xe($t8)
/*  f12df18:	a2190002 */ 	sb	$t9,0x2($s0)
.L0f12df1c:
/*  f12df1c:	93aa0067 */ 	lbu	$t2,0x67($sp)
/*  f12df20:	a20a0003 */ 	sb	$t2,0x3($s0)
.L0f12df24:
/*  f12df24:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f12df28:	240206e0 */ 	addiu	$v0,$zero,0x6e0
/*  f12df2c:	3c0b0700 */ 	lui	$t3,0x700
/*  f12df30:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12df34:	356b0004 */ 	ori	$t3,$t3,0x4
/*  f12df38:	02201825 */ 	or	$v1,$s1,$zero
/*  f12df3c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f12df40:	440c4000 */ 	mfc1	$t4,$f8
/*  f12df44:	02002025 */ 	or	$a0,$s0,$zero
/*  f12df48:	a4ac0000 */ 	sh	$t4,0x0($a1)
/*  f12df4c:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f12df50:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f12df54:	440e5000 */ 	mfc1	$t6,$f10
/*  f12df58:	00000000 */ 	nop
/*  f12df5c:	a4ae0002 */ 	sh	$t6,0x2($a1)
/*  f12df60:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*  f12df64:	a4a20008 */ 	sh	$v0,0x8($a1)
/*  f12df68:	a4a0000a */ 	sh	$zero,0xa($a1)
/*  f12df6c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12df70:	a0a00007 */ 	sb	$zero,0x7($a1)
/*  f12df74:	44184000 */ 	mfc1	$t8,$f8
/*  f12df78:	00000000 */ 	nop
/*  f12df7c:	a4b80004 */ 	sh	$t8,0x4($a1)
/*  f12df80:	c7aa0094 */ 	lwc1	$f10,0x94($sp)
/*  f12df84:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f12df88:	c7a80088 */ 	lwc1	$f8,0x88($sp)
/*  f12df8c:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f12df90:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f12df94:	c5260000 */ 	lwc1	$f6,0x0($t1)
/*  f12df98:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f12df9c:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f12dfa0:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f12dfa4:	440a2000 */ 	mfc1	$t2,$f4
/*  f12dfa8:	00000000 */ 	nop
/*  f12dfac:	a4aa000c */ 	sh	$t2,0xc($a1)
/*  f12dfb0:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f12dfb4:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f12dfb8:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f12dfbc:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f12dfc0:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f12dfc4:	c5280004 */ 	lwc1	$f8,0x4($t1)
/*  f12dfc8:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f12dfcc:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f12dfd0:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f12dfd4:	440c5000 */ 	mfc1	$t4,$f10
/*  f12dfd8:	00000000 */ 	nop
/*  f12dfdc:	a4ac000e */ 	sh	$t4,0xe($a1)
/*  f12dfe0:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f12dfe4:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*  f12dfe8:	c7aa0090 */ 	lwc1	$f10,0x90($sp)
/*  f12dfec:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f12dff0:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f12dff4:	c5240008 */ 	lwc1	$f4,0x8($t1)
/*  f12dff8:	a4a00014 */ 	sh	$zero,0x14($a1)
/*  f12dffc:	a4a00016 */ 	sh	$zero,0x16($a1)
/*  f12e000:	46123202 */ 	mul.s	$f8,$f6,$f18
/*  f12e004:	a0a00013 */ 	sb	$zero,0x13($a1)
/*  f12e008:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f12e00c:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f12e010:	440e3000 */ 	mfc1	$t6,$f6
/*  f12e014:	00000000 */ 	nop
/*  f12e018:	a4ae0010 */ 	sh	$t6,0x10($a1)
/*  f12e01c:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*  f12e020:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f12e024:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*  f12e028:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f12e02c:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f12e030:	c52a0000 */ 	lwc1	$f10,0x0($t1)
/*  f12e034:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f12e038:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f12e03c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12e040:	44184000 */ 	mfc1	$t8,$f8
/*  f12e044:	00000000 */ 	nop
/*  f12e048:	a4b80018 */ 	sh	$t8,0x18($a1)
/*  f12e04c:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f12e050:	c7aa00a4 */ 	lwc1	$f10,0xa4($sp)
/*  f12e054:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*  f12e058:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f12e05c:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f12e060:	c5260004 */ 	lwc1	$f6,0x4($t1)
/*  f12e064:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f12e068:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f12e06c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f12e070:	440a2000 */ 	mfc1	$t2,$f4
/*  f12e074:	00000000 */ 	nop
/*  f12e078:	a4aa001a */ 	sh	$t2,0x1a($a1)
/*  f12e07c:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f12e080:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f12e084:	c7a40084 */ 	lwc1	$f4,0x84($sp)
/*  f12e088:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f12e08c:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f12e090:	c5280008 */ 	lwc1	$f8,0x8($t1)
/*  f12e094:	a4a00020 */ 	sh	$zero,0x20($a1)
/*  f12e098:	a4a20022 */ 	sh	$v0,0x22($a1)
/*  f12e09c:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f12e0a0:	a0a0001f */ 	sb	$zero,0x1f($a1)
/*  f12e0a4:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f12e0a8:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f12e0ac:	440c5000 */ 	mfc1	$t4,$f10
/*  f12e0b0:	00000000 */ 	nop
/*  f12e0b4:	a4ac001c */ 	sh	$t4,0x1c($a1)
/*  f12e0b8:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f12e0bc:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f12e0c0:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f12e0c4:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f12e0c8:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f12e0cc:	c5240000 */ 	lwc1	$f4,0x0($t1)
/*  f12e0d0:	46123202 */ 	mul.s	$f8,$f6,$f18
/*  f12e0d4:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f12e0d8:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f12e0dc:	440e3000 */ 	mfc1	$t6,$f6
/*  f12e0e0:	00000000 */ 	nop
/*  f12e0e4:	a4ae0024 */ 	sh	$t6,0x24($a1)
/*  f12e0e8:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f12e0ec:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f12e0f0:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f12e0f4:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f12e0f8:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f12e0fc:	c52a0004 */ 	lwc1	$f10,0x4($t1)
/*  f12e100:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f12e104:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f12e108:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12e10c:	44184000 */ 	mfc1	$t8,$f8
/*  f12e110:	00000000 */ 	nop
/*  f12e114:	a4b80026 */ 	sh	$t8,0x26($a1)
/*  f12e118:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f12e11c:	c7a40068 */ 	lwc1	$f4,0x68($sp)
/*  f12e120:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*  f12e124:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f12e128:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f12e12c:	c5260008 */ 	lwc1	$f6,0x8($t1)
/*  f12e130:	a4a2002c */ 	sh	$v0,0x2c($a1)
/*  f12e134:	a4a2002e */ 	sh	$v0,0x2e($a1)
/*  f12e138:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f12e13c:	a0a0002b */ 	sb	$zero,0x2b($a1)
/*  f12e140:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f12e144:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f12e148:	440a2000 */ 	mfc1	$t2,$f4
/*  f12e14c:	00000000 */ 	nop
/*  f12e150:	a4aa0028 */ 	sh	$t2,0x28($a1)
/*  f12e154:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f12e158:	afa500b4 */ 	sw	$a1,0xb4($sp)
/*  f12e15c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12e160:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f12e164:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f12e168:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*  f12e16c:	3c0c0430 */ 	lui	$t4,0x430
/*  f12e170:	358c0030 */ 	ori	$t4,$t4,0x30
/*  f12e174:	02203025 */ 	or	$a2,$s1,$zero
/*  f12e178:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f12e17c:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f12e180:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f12e184:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12e188:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f12e18c:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f12e190:	3c0db100 */ 	lui	$t5,0xb100
/*  f12e194:	35ad0032 */ 	ori	$t5,$t5,0x32
/*  f12e198:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f12e19c:	240e2010 */ 	addiu	$t6,$zero,0x2010
/*  f12e1a0:	ae2e0004 */ 	sw	$t6,0x4($s1)
/*  f12e1a4:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f12e1a8:	26220008 */ 	addiu	$v0,$s1,0x8
.L0f12e1ac:
/*  f12e1ac:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f12e1b0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f12e1b4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f12e1b8:	03e00008 */ 	jr	$ra
/*  f12e1bc:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

GLOBAL_ASM(
glabel smokeCreate
/*  f12e1c0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f12e1c4:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f12e1c8:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f12e1cc:	8c4f006c */ 	lw	$t7,0x6c($v0)
/*  f12e1d0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f12e1d4:	00068400 */ 	sll	$s0,$a2,0x10
/*  f12e1d8:	00107403 */ 	sra	$t6,$s0,0x10
/*  f12e1dc:	01c08025 */ 	or	$s0,$t6,$zero
/*  f12e1e0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f12e1e4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f12e1e8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f12e1ec:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f12e1f0:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f12e1f4:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f12e1f8:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f12e1fc:	11e00003 */ 	beqz	$t7,.L0f12e20c
/*  f12e200:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f12e204:	10000002 */ 	b	.L0f12e210
/*  f12e208:	24130001 */ 	addiu	$s3,$zero,0x1
.L0f12e20c:
/*  f12e20c:	00009825 */ 	or	$s3,$zero,$zero
.L0f12e210:
/*  f12e210:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f12e214:	00008825 */ 	or	$s1,$zero,$zero
/*  f12e218:	00009025 */ 	or	$s2,$zero,$zero
/*  f12e21c:	13000003 */ 	beqz	$t8,.L0f12e22c
/*  f12e220:	3c08800a */ 	lui	$t0,%hi(g_NumSmokes)
/*  f12e224:	10000001 */ 	b	.L0f12e22c
/*  f12e228:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f12e22c:
/*  f12e22c:	8c590064 */ 	lw	$t9,0x64($v0)
/*  f12e230:	00006825 */ 	or	$t5,$zero,$zero
/*  f12e234:	00003025 */ 	or	$a2,$zero,$zero
/*  f12e238:	13200003 */ 	beqz	$t9,.L0f12e248
/*  f12e23c:	3c1f800a */ 	lui	$ra,%hi(g_Smokes)
/*  f12e240:	10000001 */ 	b	.L0f12e248
/*  f12e244:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f12e248:
/*  f12e248:	8c4e0070 */ 	lw	$t6,0x70($v0)
/*  f12e24c:	27ff3440 */ 	addiu	$ra,$ra,%lo(g_Smokes)
/*  f12e250:	240c0024 */ 	addiu	$t4,$zero,0x24
/*  f12e254:	11c00003 */ 	beqz	$t6,.L0f12e264
/*  f12e258:	3c0b8008 */ 	lui	$t3,%hi(g_SmokeTypes)
/*  f12e25c:	10000001 */ 	b	.L0f12e264
/*  f12e260:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f12e264:
/*  f12e264:	8d083444 */ 	lw	$t0,%lo(g_NumSmokes)($t0)
/*  f12e268:	00004825 */ 	or	$t1,$zero,$zero
/*  f12e26c:	00003825 */ 	or	$a3,$zero,$zero
/*  f12e270:	1900003b */ 	blez	$t0,.L0f12e360
/*  f12e274:	256be940 */ 	addiu	$t3,$t3,%lo(g_SmokeTypes)
/*  f12e278:	240a0007 */ 	addiu	$t2,$zero,0x7
.L0f12e27c:
/*  f12e27c:	8fe50000 */ 	lw	$a1,0x0($ra)
/*  f12e280:	01b27021 */ 	addu	$t6,$t5,$s2
/*  f12e284:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12e288:	00a67821 */ 	addu	$t7,$a1,$a2
/*  f12e28c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f12e290:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f12e294:	00c51821 */ 	addu	$v1,$a2,$a1
/*  f12e298:	17000003 */ 	bnez	$t8,.L0f12e2a8
/*  f12e29c:	00c5c821 */ 	addu	$t9,$a2,$a1
/*  f12e2a0:	1000002f */ 	b	.L0f12e360
/*  f12e2a4:	afb9002c */ 	sw	$t9,0x2c($sp)
.L0f12e2a8:
/*  f12e2a8:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f12e2ac:	2b010002 */ 	slti	$at,$t8,0x2
/*  f12e2b0:	54200015 */ 	bnezl	$at,.L0f12e308
/*  f12e2b4:	2a01000f */ 	slti	$at,$s0,0xf
/*  f12e2b8:	94640006 */ 	lhu	$a0,0x6($v1)
/*  f12e2bc:	24010008 */ 	addiu	$at,$zero,0x8
/*  f12e2c0:	0004ca42 */ 	srl	$t9,$a0,0x9
/*  f12e2c4:	51590024 */ 	beql	$t2,$t9,.L0f12e358
/*  f12e2c8:	00e8082a */ 	slt	$at,$a3,$t0
/*  f12e2cc:	13210021 */ 	beq	$t9,$at,.L0f12e354
/*  f12e2d0:	2401000b */ 	addiu	$at,$zero,0xb
/*  f12e2d4:	1321001f */ 	beq	$t9,$at,.L0f12e354
/*  f12e2d8:	24010009 */ 	addiu	$at,$zero,0x9
/*  f12e2dc:	5321001e */ 	beql	$t9,$at,.L0f12e358
/*  f12e2e0:	00e8082a */ 	slt	$at,$a3,$t0
/*  f12e2e4:	032c0019 */ 	multu	$t9,$t4
/*  f12e2e8:	3c08800a */ 	lui	$t0,%hi(g_NumSmokes)
/*  f12e2ec:	00007012 */ 	mflo	$t6
/*  f12e2f0:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f12e2f4:	85f80000 */ 	lh	$t8,0x0($t7)
/*  f12e2f8:	a4780004 */ 	sh	$t8,0x4($v1)
/*  f12e2fc:	10000015 */ 	b	.L0f12e354
/*  f12e300:	8d083444 */ 	lw	$t0,%lo(g_NumSmokes)($t0)
/*  f12e304:	2a01000f */ 	slti	$at,$s0,0xf
.L0f12e308:
/*  f12e308:	14200012 */ 	bnez	$at,.L0f12e354
/*  f12e30c:	2a010013 */ 	slti	$at,$s0,0x13
/*  f12e310:	10200010 */ 	beqz	$at,.L0f12e354
/*  f12e314:	00c51021 */ 	addu	$v0,$a2,$a1
/*  f12e318:	94430006 */ 	lhu	$v1,0x6($v0)
/*  f12e31c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f12e320:	0003ca42 */ 	srl	$t9,$v1,0x9
/*  f12e324:	5559000c */ 	bnel	$t2,$t9,.L0f12e358
/*  f12e328:	00e8082a */ 	slt	$at,$a3,$t0
/*  f12e32c:	55210009 */ 	bnel	$t1,$at,.L0f12e354
/*  f12e330:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f12e334:	032c0019 */ 	multu	$t9,$t4
/*  f12e338:	3c08800a */ 	lui	$t0,%hi(g_NumSmokes)
/*  f12e33c:	00007012 */ 	mflo	$t6
/*  f12e340:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f12e344:	85f80000 */ 	lh	$t8,0x0($t7)
/*  f12e348:	a4580004 */ 	sh	$t8,0x4($v0)
/*  f12e34c:	8d083444 */ 	lw	$t0,%lo(g_NumSmokes)($t0)
/*  f12e350:	25290001 */ 	addiu	$t1,$t1,0x1
.L0f12e354:
/*  f12e354:	00e8082a */ 	slt	$at,$a3,$t0
.L0f12e358:
/*  f12e358:	1420ffc8 */ 	bnez	$at,.L0f12e27c
/*  f12e35c:	24c6019c */ 	addiu	$a2,$a2,0x19c
.L0f12e360:
/*  f12e360:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*  f12e364:	53200034 */ 	beqzl	$t9,.L0f12e438
/*  f12e368:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f12e36c:	0fc180d6 */ 	jal	propAllocate
/*  f12e370:	00000000 */ 	nop
/*  f12e374:	240a0007 */ 	addiu	$t2,$zero,0x7
/*  f12e378:	1040002e */ 	beqz	$v0,.L0f12e434
/*  f12e37c:	00408825 */ 	or	$s1,$v0,$zero
/*  f12e380:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f12e384:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f12e388:	240e0008 */ 	addiu	$t6,$zero,0x8
/*  f12e38c:	a04e0000 */ 	sb	$t6,0x0($v0)
/*  f12e390:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f12e394:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f12e398:	00004040 */ 	sll	$t0,$zero,0x1
/*  f12e39c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f12e3a0:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f12e3a4:	00482821 */ 	addu	$a1,$v0,$t0
/*  f12e3a8:	00003825 */ 	or	$a3,$zero,$zero
/*  f12e3ac:	e4440008 */ 	swc1	$f4,0x8($v0)
/*  f12e3b0:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f12e3b4:	e446000c */ 	swc1	$f6,0xc($v0)
/*  f12e3b8:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f12e3bc:	01281821 */ 	addu	$v1,$t1,$t0
/*  f12e3c0:	e4480010 */ 	swc1	$f8,0x10($v0)
/*  f12e3c4:	85380000 */ 	lh	$t8,0x0($t1)
/*  f12e3c8:	50d8000b */ 	beql	$a2,$t8,.L0f12e3f8
/*  f12e3cc:	0007c840 */ 	sll	$t9,$a3,0x1
/*  f12e3d0:	84640000 */ 	lh	$a0,0x0($v1)
/*  f12e3d4:	a4a40028 */ 	sh	$a0,0x28($a1)
.L0f12e3d8:
/*  f12e3d8:	84640002 */ 	lh	$a0,0x2($v1)
/*  f12e3dc:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12e3e0:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f12e3e4:	10c40003 */ 	beq	$a2,$a0,.L0f12e3f4
/*  f12e3e8:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f12e3ec:	54eafffa */ 	bnel	$a3,$t2,.L0f12e3d8
/*  f12e3f0:	a4a40028 */ 	sh	$a0,0x28($a1)
.L0f12e3f4:
/*  f12e3f4:	0007c840 */ 	sll	$t9,$a3,0x1
.L0f12e3f8:
/*  f12e3f8:	02397021 */ 	addu	$t6,$s1,$t9
/*  f12e3fc:	a5c60028 */ 	sh	$a2,0x28($t6)
/*  f12e400:	0fc1814e */ 	jal	func0f060538
/*  f12e404:	02202025 */ 	or	$a0,$s1,$zero
/*  f12e408:	0fc180bc */ 	jal	propShow
/*  f12e40c:	02202025 */ 	or	$a0,$s1,$zero
/*  f12e410:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f12e414:	00107040 */ 	sll	$t6,$s0,0x1
/*  f12e418:	91f80006 */ 	lbu	$t8,0x6($t7)
/*  f12e41c:	adf10000 */ 	sw	$s1,0x0($t7)
/*  f12e420:	a5e00004 */ 	sh	$zero,0x4($t7)
/*  f12e424:	3319ff01 */ 	andi	$t9,$t8,0xff01
/*  f12e428:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f12e42c:	a1f80006 */ 	sb	$t8,0x6($t7)
/*  f12e430:	ade00198 */ 	sw	$zero,0x198($t7)
.L0f12e434:
/*  f12e434:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f12e438:
/*  f12e438:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*  f12e43c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f12e440:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f12e444:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f12e448:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f12e44c:	03e00008 */ 	jr	$ra
/*  f12e450:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

// Mismatch because goal calculates g_Smokes[i].type an extra time while mine
// resuses an existing one.
//struct smoke *smokeCreate(struct coord *pos, s16 *rooms, s16 type)
//{
//	struct smoke *smoke = NULL;
//	s32 playercount = PLAYERCOUNT();
//	s32 count = 0;
//	s32 i;
//
//	// 270
//	for (i = 0; i < g_NumSmokes; i++) {
//		if (g_Smokes[i].prop == NULL) {
//			smoke = &g_Smokes[i];
//			break;
//		}
//
//		// 2b0
//		if (playercount >= 2) {
//			// Multiplayer - clear existing smoke if it's not any of the following
//			if (g_Smokes[i].type != SMOKETYPE_BULLETIMPACT
//					&& g_Smokes[i].type != SMOKETYPE_ROCKETTAIL
//					&& g_Smokes[i].type != SMOKETYPE_HOMINGTAIL
//					&& g_Smokes[i].type != SMOKETYPE_GRENADETAIL) {
//				g_Smokes[i].age = g_SmokeTypes[g_Smokes[i].type].duration;
//			}
//		} else {
//			// 308
//			// 1 player - if creating muzzle smoke, remove the third bullet impact smoke
//			if (type >= SMOKETYPE_MUZZLE_PISTOL && type <= SMOKETYPE_MUZZLE_REAPER) {
//				if (g_Smokes[i].type == SMOKETYPE_BULLETIMPACT) {
//					// 32c
//					if (count == 3) {
//						g_Smokes[i].age = g_SmokeTypes[g_Smokes[i].type].duration;
//					}
//
//					count++;
//				}
//			}
//		}
//	}
//
//	// 360
//	if (smoke) {
//		struct prop *prop = propAllocate();
//
//		if (prop) {
//			prop->type = PROPTYPE_EFFECT;
//			prop->smoke = smoke;
//			prop->pos.x = pos->x;
//			prop->pos.y = pos->y;
//			prop->pos.z = pos->z;
//
//			for (i = 0; rooms[i] != -1 && i < 7; i++) {
//				prop->rooms[i] = rooms[i];
//			}
//
//			prop->rooms[i] = -1;
//			func0f060538(prop);
//			propShow(prop);
//
//			smoke->prop = prop;
//			smoke->age = 0;
//			smoke->type = type;
//			smoke->srcprop = NULL;
//		}
//	}
//
//	return smoke;
//}

bool func0f12e454(struct coord *pos, s16 *rooms, s16 type, u32 arg4)
{
	struct smoke *smoke;
	s32 i;
	s32 j;

	for (i = 0; i < g_NumSmokes; i++) {
		if (g_Smokes[i].prop
				&& g_Smokes[i].unk06_07 == arg4
				&& g_Smokes[i].type >= SMOKETYPE_MUZZLE_PISTOL
				&& g_Smokes[i].type <= SMOKETYPE_MUZZLE_REAPER) {
			bool fail = false;

			if (g_Smokes[i].age < g_SmokeTypes[g_Smokes[i].type].duration) {
				for (j = 0; j < 10; j++) {
					if (g_Smokes[i].smokebits[j].size == 0) {
						fail = true;
					}
				}

				if (fail) {
					return false;
				}
			}
		}
	}

	smoke = smokeCreate(pos, rooms, type);

	if (smoke) {
		smoke->unk06_07 = arg4;
		return true;
	}

	return false;
}

/**
 * Creates smoke, unless there is already smoke for this prop and any of the
 * smokebits have a size of zero. Perhaps the caller is supposed to check if
 * this function returns false and reuse the zero-sized smokebits if so?
 */
bool smokeCreateAtPropIfNecessary(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, u32 arg4)
{
	struct smoke *smoke;
	s32 i;
	s32 j;
	bool checksmokes = true;

	if (type == SMOKETYPE_UFO) {
		checksmokes = false;
	}

	if (checksmokes) {
		for (i = 0; i < g_NumSmokes; i++) {
			if (g_Smokes[i].prop && g_Smokes[i].srcprop == prop) {
				bool fail = false;

				if (g_Smokes[i].age < g_SmokeTypes[g_Smokes[i].type].duration) {
					for (j = 0; j < 10; j++) {
						if (g_Smokes[i].smokebits[j].size == 0) {
							fail = true;
						}
					}

					if (fail) {
						return false;
					}
				}
			}
		}
	}

	smoke = smokeCreate(pos, rooms, type);

	if (smoke) {
		smoke->srcprop = prop;
		smoke->unk06_07 = arg4;
		return true;
	}

	return false;
}

void smokeCreateAtProp(struct prop *prop, s16 type)
{
	smokeCreateAtPropIfNecessary(prop, &prop->pos, prop->rooms, type, false);
}

void func0f12e74c(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, u32 arg4)
{
	smokeCreateAtPropIfNecessary(prop, pos, rooms, type, true);
}

void smokeClearForProp(struct prop *prop)
{
	s32 i;

	for (i = 0; i < g_NumSmokes; i++) {
		if (g_Smokes[i].prop && g_Smokes[i].srcprop == prop && g_Smokes[i].unk06_07 == false) {
			g_Smokes[i].age = g_SmokeTypes[g_Smokes[i].type].duration;
			g_Smokes[i].srcprop = NULL;
		}
	}
}

struct smoke *smokeCreateSimple(struct coord *pos, s16 *rooms, s16 type)
{
	return smokeCreate(pos, rooms, type);
}

GLOBAL_ASM(
glabel func0f12e848
/*  f12e848:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f12e84c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x34)
/*  f12e850:	8dce9ff4 */ 	lw	$t6,%lo(g_Vars+0x34)($t6)
/*  f12e854:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f12e858:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f12e85c:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f12e860:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f12e864:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f12e868:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f12e86c:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f12e870:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f12e874:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f12e878:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f12e87c:	f7be0048 */ 	sdc1	$f30,0x48($sp)
/*  f12e880:	f7bc0040 */ 	sdc1	$f28,0x40($sp)
/*  f12e884:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f12e888:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f12e88c:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f12e890:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f12e894:	0080b025 */ 	or	$s6,$a0,$zero
/*  f12e898:	15c00003 */ 	bnez	$t6,.L0f12e8a8
/*  f12e89c:	8c920004 */ 	lw	$s2,0x4($a0)
/*  f12e8a0:	10000226 */ 	b	.L0f12f13c
/*  f12e8a4:	00001025 */ 	or	$v0,$zero,$zero
.L0f12e8a8:
/*  f12e8a8:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x38)
/*  f12e8ac:	8c429ff8 */ 	lw	$v0,%lo(g_Vars+0x38)($v0)
/*  f12e8b0:	264b0008 */ 	addiu	$t3,$s2,0x8
/*  f12e8b4:	24150190 */ 	addiu	$s5,$zero,0x190
/*  f12e8b8:	2841000f */ 	slti	$at,$v0,0xf
/*  f12e8bc:	10200008 */ 	beqz	$at,.L0f12e8e0
/*  f12e8c0:	24140024 */ 	addiu	$s4,$zero,0x24
/*  f12e8c4:	44822000 */ 	mtc1	$v0,$f4
/*  f12e8c8:	00000000 */ 	nop
/*  f12e8cc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f12e8d0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12e8d4:	44184000 */ 	mfc1	$t8,$f8
/*  f12e8d8:	10000008 */ 	b	.L0f12e8fc
/*  f12e8dc:	afb800c0 */ 	sw	$t8,0xc0($sp)
.L0f12e8e0:
/*  f12e8e0:	3c014170 */ 	lui	$at,0x4170
/*  f12e8e4:	44815000 */ 	mtc1	$at,$f10
/*  f12e8e8:	00000000 */ 	nop
/*  f12e8ec:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f12e8f0:	44098000 */ 	mfc1	$t1,$f16
/*  f12e8f4:	00000000 */ 	nop
/*  f12e8f8:	afa900c0 */ 	sw	$t1,0xc0($sp)
.L0f12e8fc:
/*  f12e8fc:	8faa00c0 */ 	lw	$t2,0xc0($sp)
/*  f12e900:	0000b825 */ 	or	$s7,$zero,$zero
/*  f12e904:	3c013f00 */ 	lui	$at,0x3f00
/*  f12e908:	194001a4 */ 	blez	$t2,.L0f12ef9c
/*  f12e90c:	3c138008 */ 	lui	$s3,%hi(g_SmokeTypes)
/*  f12e910:	4481f000 */ 	mtc1	$at,$f30
/*  f12e914:	3c014080 */ 	lui	$at,0x4080
/*  f12e918:	4481e000 */ 	mtc1	$at,$f28
/*  f12e91c:	3c017f1b */ 	lui	$at,%hi(var7f1b55e0)
/*  f12e920:	c43a55e0 */ 	lwc1	$f26,%lo(var7f1b55e0)($at)
/*  f12e924:	3c017f1b */ 	lui	$at,%hi(var7f1b55e4)
/*  f12e928:	c43855e4 */ 	lwc1	$f24,%lo(var7f1b55e4)($at)
/*  f12e92c:	3c012f80 */ 	lui	$at,0x2f80
/*  f12e930:	4481b000 */ 	mtc1	$at,$f22
/*  f12e934:	4480a000 */ 	mtc1	$zero,$f20
/*  f12e938:	afab0090 */ 	sw	$t3,0x90($sp)
/*  f12e93c:	241e07a4 */ 	addiu	$s8,$zero,0x7a4
/*  f12e940:	2673e940 */ 	addiu	$s3,$s3,%lo(g_SmokeTypes)
/*  f12e944:	864c0004 */ 	lh	$t4,0x4($s2)
.L0f12e948:
/*  f12e948:	00008825 */ 	or	$s1,$zero,$zero
/*  f12e94c:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f12e950:	a64d0004 */ 	sh	$t5,0x4($s2)
/*  f12e954:	8fb00090 */ 	lw	$s0,0x90($sp)
.L0f12e958:
/*  f12e958:	c600000c */ 	lwc1	$f0,0xc($s0)
/*  f12e95c:	4600a032 */ 	c.eq.s	$f20,$f0
/*  f12e960:	00000000 */ 	nop
/*  f12e964:	4503004a */ 	bc1tl	.L0f12ea90
/*  f12e968:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f12e96c:	964e0006 */ 	lhu	$t6,0x6($s2)
/*  f12e970:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f12e974:	000e7a42 */ 	srl	$t7,$t6,0x9
/*  f12e978:	01f40019 */ 	multu	$t7,$s4
/*  f12e97c:	0000c012 */ 	mflo	$t8
/*  f12e980:	0278c821 */ 	addu	$t9,$s3,$t8
/*  f12e984:	c724001c */ 	lwc1	$f4,0x1c($t9)
/*  f12e988:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f12e98c:	e6060004 */ 	swc1	$f6,0x4($s0)
/*  f12e990:	96490006 */ 	lhu	$t1,0x6($s2)
/*  f12e994:	00095242 */ 	srl	$t2,$t1,0x9
/*  f12e998:	01540019 */ 	multu	$t2,$s4
/*  f12e99c:	00005812 */ 	mflo	$t3
/*  f12e9a0:	026b6021 */ 	addu	$t4,$s3,$t3
/*  f12e9a4:	c5880018 */ 	lwc1	$f8,0x18($t4)
/*  f12e9a8:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f12e9ac:	e60a000c */ 	swc1	$f10,0xc($s0)
/*  f12e9b0:	c610000c */ 	lwc1	$f16,0xc($s0)
/*  f12e9b4:	4614803c */ 	c.lt.s	$f16,$f20
/*  f12e9b8:	00000000 */ 	nop
/*  f12e9bc:	45020003 */ 	bc1fl	.L0f12e9cc
/*  f12e9c0:	964d0006 */ 	lhu	$t5,0x6($s2)
/*  f12e9c4:	e614000c */ 	swc1	$f20,0xc($s0)
/*  f12e9c8:	964d0006 */ 	lhu	$t5,0x6($s2)
.L0f12e9cc:
/*  f12e9cc:	c6120020 */ 	lwc1	$f18,0x20($s0)
/*  f12e9d0:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f12e9d4:	000d7242 */ 	srl	$t6,$t5,0x9
/*  f12e9d8:	01d40019 */ 	multu	$t6,$s4
/*  f12e9dc:	c60a0014 */ 	lwc1	$f10,0x14($s0)
/*  f12e9e0:	86190024 */ 	lh	$t9,0x24($s0)
/*  f12e9e4:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f12e9e8:	27290001 */ 	addiu	$t1,$t9,0x1
/*  f12e9ec:	00007812 */ 	mflo	$t7
/*  f12e9f0:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f12e9f4:	c7040010 */ 	lwc1	$f4,0x10($t8)
/*  f12e9f8:	a6090024 */ 	sh	$t1,0x24($s0)
/*  f12e9fc:	e6100010 */ 	swc1	$f16,0x10($s0)
/*  f12ea00:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f12ea04:	0c004b70 */ 	jal	random
/*  f12ea08:	e6060020 */ 	swc1	$f6,0x20($s0)
/*  f12ea0c:	44822000 */ 	mtc1	$v0,$f4
/*  f12ea10:	c6120018 */ 	lwc1	$f18,0x18($s0)
/*  f12ea14:	04410005 */ 	bgez	$v0,.L0f12ea2c
/*  f12ea18:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f12ea1c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ea20:	44814000 */ 	mtc1	$at,$f8
/*  f12ea24:	00000000 */ 	nop
/*  f12ea28:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f12ea2c:
/*  f12ea2c:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f12ea30:	00000000 */ 	nop
/*  f12ea34:	461a5402 */ 	mul.s	$f16,$f10,$f26
/*  f12ea38:	4610c100 */ 	add.s	$f4,$f24,$f16
/*  f12ea3c:	46049200 */ 	add.s	$f8,$f18,$f4
/*  f12ea40:	0c004b70 */ 	jal	random
/*  f12ea44:	e6080018 */ 	swc1	$f8,0x18($s0)
/*  f12ea48:	44825000 */ 	mtc1	$v0,$f10
/*  f12ea4c:	c606001c */ 	lwc1	$f6,0x1c($s0)
/*  f12ea50:	04410005 */ 	bgez	$v0,.L0f12ea68
/*  f12ea54:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f12ea58:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ea5c:	44819000 */ 	mtc1	$at,$f18
/*  f12ea60:	00000000 */ 	nop
/*  f12ea64:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f12ea68:
/*  f12ea68:	46168102 */ 	mul.s	$f4,$f16,$f22
/*  f12ea6c:	c6100020 */ 	lwc1	$f16,0x20($s0)
/*  f12ea70:	461c803c */ 	c.lt.s	$f16,$f28
/*  f12ea74:	461a2202 */ 	mul.s	$f8,$f4,$f26
/*  f12ea78:	4608c280 */ 	add.s	$f10,$f24,$f8
/*  f12ea7c:	460a3480 */ 	add.s	$f18,$f6,$f10
/*  f12ea80:	45000002 */ 	bc1f	.L0f12ea8c
/*  f12ea84:	e612001c */ 	swc1	$f18,0x1c($s0)
/*  f12ea88:	e614000c */ 	swc1	$f20,0xc($s0)
.L0f12ea8c:
/*  f12ea8c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f12ea90:
/*  f12ea90:	2a21000a */ 	slti	$at,$s1,0xa
/*  f12ea94:	1420ffb0 */ 	bnez	$at,.L0f12e958
/*  f12ea98:	26100028 */ 	addiu	$s0,$s0,0x28
/*  f12ea9c:	964a0006 */ 	lhu	$t2,0x6($s2)
/*  f12eaa0:	86430004 */ 	lh	$v1,0x4($s2)
/*  f12eaa4:	000a5a42 */ 	srl	$t3,$t2,0x9
/*  f12eaa8:	01740019 */ 	multu	$t3,$s4
/*  f12eaac:	00006012 */ 	mflo	$t4
/*  f12eab0:	026c2021 */ 	addu	$a0,$s3,$t4
/*  f12eab4:	848d0000 */ 	lh	$t5,0x0($a0)
/*  f12eab8:	006d082a */ 	slt	$at,$v1,$t5
/*  f12eabc:	50200134 */ 	beqzl	$at,.L0f12ef90
/*  f12eac0:	8fa900c0 */ 	lw	$t1,0xc0($sp)
/*  f12eac4:	848e0004 */ 	lh	$t6,0x4($a0)
/*  f12eac8:	8fb00090 */ 	lw	$s0,0x90($sp)
/*  f12eacc:	006e001a */ 	div	$zero,$v1,$t6
/*  f12ead0:	15c00002 */ 	bnez	$t6,.L0f12eadc
/*  f12ead4:	00000000 */ 	nop
/*  f12ead8:	0007000d */ 	break	0x7
.L0f12eadc:
/*  f12eadc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12eae0:	15c10004 */ 	bne	$t6,$at,.L0f12eaf4
/*  f12eae4:	3c018000 */ 	lui	$at,0x8000
/*  f12eae8:	14610002 */ 	bne	$v1,$at,.L0f12eaf4
/*  f12eaec:	00000000 */ 	nop
/*  f12eaf0:	0006000d */ 	break	0x6
.L0f12eaf4:
/*  f12eaf4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12eaf8:	00007810 */ 	mfhi	$t7
/*  f12eafc:	55e10124 */ 	bnel	$t7,$at,.L0f12ef90
/*  f12eb00:	8fa900c0 */ 	lw	$t1,0xc0($sp)
/*  f12eb04:	00003025 */ 	or	$a2,$zero,$zero
/*  f12eb08:	02402825 */ 	or	$a1,$s2,$zero
.L0f12eb0c:
/*  f12eb0c:	c4a40014 */ 	lwc1	$f4,0x14($a1)
/*  f12eb10:	24c60028 */ 	addiu	$a2,$a2,0x28
/*  f12eb14:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f12eb18:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f12eb1c:	00000000 */ 	nop
/*  f12eb20:	45000118 */ 	bc1f	.L0f12ef84
/*  f12eb24:	00000000 */ 	nop
/*  f12eb28:	84980006 */ 	lh	$t8,0x6($a0)
/*  f12eb2c:	17000014 */ 	bnez	$t8,.L0f12eb80
/*  f12eb30:	00000000 */ 	nop
/*  f12eb34:	0c004b70 */ 	jal	random
/*  f12eb38:	00000000 */ 	nop
/*  f12eb3c:	44824000 */ 	mtc1	$v0,$f8
/*  f12eb40:	3c014f80 */ 	lui	$at,0x4f80
/*  f12eb44:	04410004 */ 	bgez	$v0,.L0f12eb58
/*  f12eb48:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f12eb4c:	44815000 */ 	mtc1	$at,$f10
/*  f12eb50:	00000000 */ 	nop
/*  f12eb54:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f12eb58:
/*  f12eb58:	46163482 */ 	mul.s	$f18,$f6,$f22
/*  f12eb5c:	3c013f80 */ 	lui	$at,0x3f80
/*  f12eb60:	44812000 */ 	mtc1	$at,$f4
/*  f12eb64:	3c017f1b */ 	lui	$at,%hi(var7f1b55e8)
/*  f12eb68:	c42a55e8 */ 	lwc1	$f10,%lo(var7f1b55e8)($at)
/*  f12eb6c:	461e9402 */ 	mul.s	$f16,$f18,$f30
/*  f12eb70:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f12eb74:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f12eb78:	1000001a */ 	b	.L0f12ebe4
/*  f12eb7c:	e606000c */ 	swc1	$f6,0xc($s0)
.L0f12eb80:
/*  f12eb80:	0c004b70 */ 	jal	random
/*  f12eb84:	00000000 */ 	nop
/*  f12eb88:	44829000 */ 	mtc1	$v0,$f18
/*  f12eb8c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12eb90:	04410004 */ 	bgez	$v0,.L0f12eba4
/*  f12eb94:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f12eb98:	44812000 */ 	mtc1	$at,$f4
/*  f12eb9c:	00000000 */ 	nop
/*  f12eba0:	46048400 */ 	add.s	$f16,$f16,$f4
.L0f12eba4:
/*  f12eba4:	96590006 */ 	lhu	$t9,0x6($s2)
/*  f12eba8:	46168202 */ 	mul.s	$f8,$f16,$f22
/*  f12ebac:	3c013f80 */ 	lui	$at,0x3f80
/*  f12ebb0:	00194a42 */ 	srl	$t1,$t9,0x9
/*  f12ebb4:	01340019 */ 	multu	$t1,$s4
/*  f12ebb8:	44813000 */ 	mtc1	$at,$f6
/*  f12ebbc:	461e4282 */ 	mul.s	$f10,$f8,$f30
/*  f12ebc0:	00005012 */ 	mflo	$t2
/*  f12ebc4:	026a5821 */ 	addu	$t3,$s3,$t2
/*  f12ebc8:	856c0006 */ 	lh	$t4,0x6($t3)
/*  f12ebcc:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f12ebd0:	448c2000 */ 	mtc1	$t4,$f4
/*  f12ebd4:	00000000 */ 	nop
/*  f12ebd8:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f12ebdc:	46109202 */ 	mul.s	$f8,$f18,$f16
/*  f12ebe0:	e608000c */ 	swc1	$f8,0xc($s0)
.L0f12ebe4:
/*  f12ebe4:	0c004b70 */ 	jal	random
/*  f12ebe8:	00000000 */ 	nop
/*  f12ebec:	24010046 */ 	addiu	$at,$zero,0x46
/*  f12ebf0:	0041001b */ 	divu	$zero,$v0,$at
/*  f12ebf4:	00006810 */ 	mfhi	$t5
/*  f12ebf8:	448d5000 */ 	mtc1	$t5,$f10
/*  f12ebfc:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ec00:	05a10004 */ 	bgez	$t5,.L0f12ec14
/*  f12ec04:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f12ec08:	44812000 */ 	mtc1	$at,$f4
/*  f12ec0c:	00000000 */ 	nop
/*  f12ec10:	46043180 */ 	add.s	$f6,$f6,$f4
.L0f12ec14:
/*  f12ec14:	3c0142dc */ 	lui	$at,0x42dc
/*  f12ec18:	44819000 */ 	mtc1	$at,$f18
/*  f12ec1c:	a6000024 */ 	sh	$zero,0x24($s0)
/*  f12ec20:	46123400 */ 	add.s	$f16,$f6,$f18
/*  f12ec24:	0c004b70 */ 	jal	random
/*  f12ec28:	e6100020 */ 	swc1	$f16,0x20($s0)
/*  f12ec2c:	44824000 */ 	mtc1	$v0,$f8
/*  f12ec30:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ec34:	04410004 */ 	bgez	$v0,.L0f12ec48
/*  f12ec38:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f12ec3c:	44812000 */ 	mtc1	$at,$f4
/*  f12ec40:	00000000 */ 	nop
/*  f12ec44:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f12ec48:
/*  f12ec48:	46165182 */ 	mul.s	$f6,$f10,$f22
/*  f12ec4c:	3c017f1b */ 	lui	$at,%hi(var7f1b55ec)
/*  f12ec50:	c43255ec */ 	lwc1	$f18,%lo(var7f1b55ec)($at)
/*  f12ec54:	46123402 */ 	mul.s	$f16,$f6,$f18
/*  f12ec58:	0c004b70 */ 	jal	random
/*  f12ec5c:	e6100010 */ 	swc1	$f16,0x10($s0)
/*  f12ec60:	964e0006 */ 	lhu	$t6,0x6($s2)
/*  f12ec64:	44822000 */ 	mtc1	$v0,$f4
/*  f12ec68:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ec6c:	000e7a42 */ 	srl	$t7,$t6,0x9
/*  f12ec70:	01f40019 */ 	multu	$t7,$s4
/*  f12ec74:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f12ec78:	0000c012 */ 	mflo	$t8
/*  f12ec7c:	0278c821 */ 	addu	$t9,$s3,$t8
/*  f12ec80:	04410004 */ 	bgez	$v0,.L0f12ec94
/*  f12ec84:	c7280008 */ 	lwc1	$f8,0x8($t9)
/*  f12ec88:	44813000 */ 	mtc1	$at,$f6
/*  f12ec8c:	00000000 */ 	nop
/*  f12ec90:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f12ec94:
/*  f12ec94:	46165482 */ 	mul.s	$f18,$f10,$f22
/*  f12ec98:	4612f401 */ 	sub.s	$f16,$f30,$f18
/*  f12ec9c:	46104102 */ 	mul.s	$f4,$f8,$f16
/*  f12eca0:	e6040014 */ 	swc1	$f4,0x14($s0)
/*  f12eca4:	96430006 */ 	lhu	$v1,0x6($s2)
/*  f12eca8:	00034a42 */ 	srl	$t1,$v1,0x9
/*  f12ecac:	2921000f */ 	slti	$at,$t1,0xf
/*  f12ecb0:	1420001f */ 	bnez	$at,.L0f12ed30
/*  f12ecb4:	29210013 */ 	slti	$at,$t1,0x13
/*  f12ecb8:	5020001e */ 	beqzl	$at,.L0f12ed34
/*  f12ecbc:	8e420198 */ 	lw	$v0,0x198($s2)
/*  f12ecc0:	924b0006 */ 	lbu	$t3,0x6($s2)
/*  f12ecc4:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x284)
/*  f12ecc8:	8d4aa244 */ 	lw	$t2,%lo(g_Vars+0x284)($t2)
/*  f12eccc:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f12ecd0:	019e0019 */ 	multu	$t4,$s8
/*  f12ecd4:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f12ecd8:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x284)
/*  f12ecdc:	00006812 */ 	mflo	$t5
/*  f12ece0:	014d7021 */ 	addu	$t6,$t2,$t5
/*  f12ece4:	c5c609ac */ 	lwc1	$f6,0x9ac($t6)
/*  f12ece8:	e6060000 */ 	swc1	$f6,0x0($s0)
/*  f12ecec:	92580006 */ 	lbu	$t8,0x6($s2)
/*  f12ecf0:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f12ecf4:	33190001 */ 	andi	$t9,$t8,0x1
/*  f12ecf8:	033e0019 */ 	multu	$t9,$s8
/*  f12ecfc:	00004812 */ 	mflo	$t1
/*  f12ed00:	01e95821 */ 	addu	$t3,$t7,$t1
/*  f12ed04:	c56a09b0 */ 	lwc1	$f10,0x9b0($t3)
/*  f12ed08:	e60a0004 */ 	swc1	$f10,0x4($s0)
/*  f12ed0c:	924a0006 */ 	lbu	$t2,0x6($s2)
/*  f12ed10:	8d8ca244 */ 	lw	$t4,%lo(g_Vars+0x284)($t4)
/*  f12ed14:	314d0001 */ 	andi	$t5,$t2,0x1
/*  f12ed18:	01be0019 */ 	multu	$t5,$s8
/*  f12ed1c:	00007012 */ 	mflo	$t6
/*  f12ed20:	018ec021 */ 	addu	$t8,$t4,$t6
/*  f12ed24:	c71209b4 */ 	lwc1	$f18,0x9b4($t8)
/*  f12ed28:	10000017 */ 	b	.L0f12ed88
/*  f12ed2c:	e6120008 */ 	swc1	$f18,0x8($s0)
.L0f12ed30:
/*  f12ed30:	8e420198 */ 	lw	$v0,0x198($s2)
.L0f12ed34:
/*  f12ed34:	5040000f */ 	beqzl	$v0,.L0f12ed74
/*  f12ed38:	c6c60008 */ 	lwc1	$f6,0x8($s6)
/*  f12ed3c:	92590006 */ 	lbu	$t9,0x6($s2)
/*  f12ed40:	332f0001 */ 	andi	$t7,$t9,0x1
/*  f12ed44:	55e0000b */ 	bnezl	$t7,.L0f12ed74
/*  f12ed48:	c6c60008 */ 	lwc1	$f6,0x8($s6)
/*  f12ed4c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f12ed50:	e6080000 */ 	swc1	$f8,0x0($s0)
/*  f12ed54:	8e490198 */ 	lw	$t1,0x198($s2)
/*  f12ed58:	c530000c */ 	lwc1	$f16,0xc($t1)
/*  f12ed5c:	e6100004 */ 	swc1	$f16,0x4($s0)
/*  f12ed60:	8e4b0198 */ 	lw	$t3,0x198($s2)
/*  f12ed64:	c5640010 */ 	lwc1	$f4,0x10($t3)
/*  f12ed68:	10000007 */ 	b	.L0f12ed88
/*  f12ed6c:	e6040008 */ 	swc1	$f4,0x8($s0)
/*  f12ed70:	c6c60008 */ 	lwc1	$f6,0x8($s6)
.L0f12ed74:
/*  f12ed74:	e6060000 */ 	swc1	$f6,0x0($s0)
/*  f12ed78:	c6ca000c */ 	lwc1	$f10,0xc($s6)
/*  f12ed7c:	e60a0004 */ 	swc1	$f10,0x4($s0)
/*  f12ed80:	c6d20010 */ 	lwc1	$f18,0x10($s6)
/*  f12ed84:	e6120008 */ 	swc1	$f18,0x8($s0)
.L0f12ed88:
/*  f12ed88:	964a0006 */ 	lhu	$t2,0x6($s2)
/*  f12ed8c:	24010014 */ 	addiu	$at,$zero,0x14
/*  f12ed90:	000a6a42 */ 	srl	$t5,$t2,0x9
/*  f12ed94:	15a1004c */ 	bne	$t5,$at,.L0f12eec8
/*  f12ed98:	00000000 */ 	nop
/*  f12ed9c:	0c004b70 */ 	jal	random
/*  f12eda0:	00000000 */ 	nop
/*  f12eda4:	44824000 */ 	mtc1	$v0,$f8
/*  f12eda8:	3c014f80 */ 	lui	$at,0x4f80
/*  f12edac:	04410004 */ 	bgez	$v0,.L0f12edc0
/*  f12edb0:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f12edb4:	44812000 */ 	mtc1	$at,$f4
/*  f12edb8:	00000000 */ 	nop
/*  f12edbc:	46048400 */ 	add.s	$f16,$f16,$f4
.L0f12edc0:
/*  f12edc0:	46168182 */ 	mul.s	$f6,$f16,$f22
/*  f12edc4:	3c01428c */ 	lui	$at,0x428c
/*  f12edc8:	44815000 */ 	mtc1	$at,$f10
/*  f12edcc:	3c01420c */ 	lui	$at,0x420c
/*  f12edd0:	44814000 */ 	mtc1	$at,$f8
/*  f12edd4:	c6100000 */ 	lwc1	$f16,0x0($s0)
/*  f12edd8:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f12eddc:	46089101 */ 	sub.s	$f4,$f18,$f8
/*  f12ede0:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f12ede4:	0c004b70 */ 	jal	random
/*  f12ede8:	e6060000 */ 	swc1	$f6,0x0($s0)
/*  f12edec:	44825000 */ 	mtc1	$v0,$f10
/*  f12edf0:	3c014f80 */ 	lui	$at,0x4f80
/*  f12edf4:	04410004 */ 	bgez	$v0,.L0f12ee08
/*  f12edf8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f12edfc:	44814000 */ 	mtc1	$at,$f8
/*  f12ee00:	00000000 */ 	nop
/*  f12ee04:	46089480 */ 	add.s	$f18,$f18,$f8
.L0f12ee08:
/*  f12ee08:	46169402 */ 	mul.s	$f16,$f18,$f22
/*  f12ee0c:	3c014220 */ 	lui	$at,0x4220
/*  f12ee10:	44812000 */ 	mtc1	$at,$f4
/*  f12ee14:	3c0141c8 */ 	lui	$at,0x41c8
/*  f12ee18:	44815000 */ 	mtc1	$at,$f10
/*  f12ee1c:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f12ee20:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f12ee24:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f12ee28:	46089400 */ 	add.s	$f16,$f18,$f8
/*  f12ee2c:	0c004b70 */ 	jal	random
/*  f12ee30:	e6100004 */ 	swc1	$f16,0x4($s0)
/*  f12ee34:	44822000 */ 	mtc1	$v0,$f4
/*  f12ee38:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ee3c:	04410004 */ 	bgez	$v0,.L0f12ee50
/*  f12ee40:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f12ee44:	44815000 */ 	mtc1	$at,$f10
/*  f12ee48:	00000000 */ 	nop
/*  f12ee4c:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f12ee50:
/*  f12ee50:	46163482 */ 	mul.s	$f18,$f6,$f22
/*  f12ee54:	3c014220 */ 	lui	$at,0x4220
/*  f12ee58:	44814000 */ 	mtc1	$at,$f8
/*  f12ee5c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f12ee60:	44812000 */ 	mtc1	$at,$f4
/*  f12ee64:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f12ee68:	3c017f1b */ 	lui	$at,%hi(var7f1b55f0)
/*  f12ee6c:	46089402 */ 	mul.s	$f16,$f18,$f8
/*  f12ee70:	c6080020 */ 	lwc1	$f8,0x20($s0)
/*  f12ee74:	46048281 */ 	sub.s	$f10,$f16,$f4
/*  f12ee78:	460a3480 */ 	add.s	$f18,$f6,$f10
/*  f12ee7c:	e6120008 */ 	swc1	$f18,0x8($s0)
/*  f12ee80:	c43055f0 */ 	lwc1	$f16,%lo(var7f1b55f0)($at)
/*  f12ee84:	46104102 */ 	mul.s	$f4,$f8,$f16
/*  f12ee88:	0c004b70 */ 	jal	random
/*  f12ee8c:	e6040020 */ 	swc1	$f4,0x20($s0)
/*  f12ee90:	44823000 */ 	mtc1	$v0,$f6
/*  f12ee94:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ee98:	04410004 */ 	bgez	$v0,.L0f12eeac
/*  f12ee9c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f12eea0:	44819000 */ 	mtc1	$at,$f18
/*  f12eea4:	00000000 */ 	nop
/*  f12eea8:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f12eeac:
/*  f12eeac:	46165202 */ 	mul.s	$f8,$f10,$f22
/*  f12eeb0:	3c013f80 */ 	lui	$at,0x3f80
/*  f12eeb4:	44818000 */ 	mtc1	$at,$f16
/*  f12eeb8:	c606000c */ 	lwc1	$f6,0xc($s0)
/*  f12eebc:	46104100 */ 	add.s	$f4,$f8,$f16
/*  f12eec0:	46043482 */ 	mul.s	$f18,$f6,$f4
/*  f12eec4:	e612000c */ 	swc1	$f18,0xc($s0)
.L0f12eec8:
/*  f12eec8:	0c004b70 */ 	jal	random
/*  f12eecc:	00000000 */ 	nop
/*  f12eed0:	44825000 */ 	mtc1	$v0,$f10
/*  f12eed4:	3c014f80 */ 	lui	$at,0x4f80
/*  f12eed8:	04410004 */ 	bgez	$v0,.L0f12eeec
/*  f12eedc:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f12eee0:	44818000 */ 	mtc1	$at,$f16
/*  f12eee4:	00000000 */ 	nop
/*  f12eee8:	46104200 */ 	add.s	$f8,$f8,$f16
.L0f12eeec:
/*  f12eeec:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f12eef0:	00000000 */ 	nop
/*  f12eef4:	461e3102 */ 	mul.s	$f4,$f6,$f30
/*  f12eef8:	0c004b70 */ 	jal	random
/*  f12eefc:	e6040018 */ 	swc1	$f4,0x18($s0)
/*  f12ef00:	44829000 */ 	mtc1	$v0,$f18
/*  f12ef04:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ef08:	04410004 */ 	bgez	$v0,.L0f12ef1c
/*  f12ef0c:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f12ef10:	44818000 */ 	mtc1	$at,$f16
/*  f12ef14:	00000000 */ 	nop
/*  f12ef18:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f12ef1c:
/*  f12ef1c:	46165202 */ 	mul.s	$f8,$f10,$f22
/*  f12ef20:	00000000 */ 	nop
/*  f12ef24:	461e4182 */ 	mul.s	$f6,$f8,$f30
/*  f12ef28:	e606001c */ 	swc1	$f6,0x1c($s0)
/*  f12ef2c:	964c0006 */ 	lhu	$t4,0x6($s2)
/*  f12ef30:	86430004 */ 	lh	$v1,0x4($s2)
/*  f12ef34:	000c7242 */ 	srl	$t6,$t4,0x9
/*  f12ef38:	01d40019 */ 	multu	$t6,$s4
/*  f12ef3c:	0000c012 */ 	mflo	$t8
/*  f12ef40:	02782021 */ 	addu	$a0,$s3,$t8
/*  f12ef44:	84850000 */ 	lh	$a1,0x0($a0)
/*  f12ef48:	84860014 */ 	lh	$a2,0x14($a0)
/*  f12ef4c:	00a6c823 */ 	subu	$t9,$a1,$a2
/*  f12ef50:	0323082a */ 	slt	$at,$t9,$v1
/*  f12ef54:	1020000d */ 	beqz	$at,.L0f12ef8c
/*  f12ef58:	00000000 */ 	nop
/*  f12ef5c:	00a37823 */ 	subu	$t7,$a1,$v1
/*  f12ef60:	448f2000 */ 	mtc1	$t7,$f4
/*  f12ef64:	44868000 */ 	mtc1	$a2,$f16
/*  f12ef68:	c6060020 */ 	lwc1	$f6,0x20($s0)
/*  f12ef6c:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f12ef70:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f12ef74:	460a9203 */ 	div.s	$f8,$f18,$f10
/*  f12ef78:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f12ef7c:	10000003 */ 	b	.L0f12ef8c
/*  f12ef80:	e6040020 */ 	swc1	$f4,0x20($s0)
.L0f12ef84:
/*  f12ef84:	14d5fee1 */ 	bne	$a2,$s5,.L0f12eb0c
/*  f12ef88:	26100028 */ 	addiu	$s0,$s0,0x28
.L0f12ef8c:
/*  f12ef8c:	8fa900c0 */ 	lw	$t1,0xc0($sp)
.L0f12ef90:
/*  f12ef90:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f12ef94:	56e9fe6c */ 	bnel	$s7,$t1,.L0f12e948
/*  f12ef98:	864c0004 */ 	lh	$t4,0x4($s2)
.L0f12ef9c:
/*  f12ef9c:	3c013f80 */ 	lui	$at,0x3f80
/*  f12efa0:	44819000 */ 	mtc1	$at,$f18
/*  f12efa4:	c6d00008 */ 	lwc1	$f16,0x8($s6)
/*  f12efa8:	44814000 */ 	mtc1	$at,$f8
/*  f12efac:	3c138008 */ 	lui	$s3,%hi(g_SmokeTypes)
/*  f12efb0:	46128281 */ 	sub.s	$f10,$f16,$f18
/*  f12efb4:	44819000 */ 	mtc1	$at,$f18
/*  f12efb8:	4480a000 */ 	mtc1	$zero,$f20
/*  f12efbc:	2673e940 */ 	addiu	$s3,$s3,%lo(g_SmokeTypes)
/*  f12efc0:	e7aa00ac */ 	swc1	$f10,0xac($sp)
/*  f12efc4:	c6c6000c */ 	lwc1	$f6,0xc($s6)
/*  f12efc8:	24140024 */ 	addiu	$s4,$zero,0x24
/*  f12efcc:	00003025 */ 	or	$a2,$zero,$zero
/*  f12efd0:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f12efd4:	44814000 */ 	mtc1	$at,$f8
/*  f12efd8:	02402825 */ 	or	$a1,$s2,$zero
/*  f12efdc:	27a700ac */ 	addiu	$a3,$sp,0xac
/*  f12efe0:	e7a400b0 */ 	swc1	$f4,0xb0($sp)
/*  f12efe4:	c6d00010 */ 	lwc1	$f16,0x10($s6)
/*  f12efe8:	46128281 */ 	sub.s	$f10,$f16,$f18
/*  f12efec:	44819000 */ 	mtc1	$at,$f18
/*  f12eff0:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f12eff4:	c6c60008 */ 	lwc1	$f6,0x8($s6)
/*  f12eff8:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f12effc:	44814000 */ 	mtc1	$at,$f8
/*  f12f000:	e7a400a0 */ 	swc1	$f4,0xa0($sp)
/*  f12f004:	c6d0000c */ 	lwc1	$f16,0xc($s6)
/*  f12f008:	46128280 */ 	add.s	$f10,$f16,$f18
/*  f12f00c:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f12f010:	c6c60010 */ 	lwc1	$f6,0x10($s6)
/*  f12f014:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f12f018:	e7a400a8 */ 	swc1	$f4,0xa8($sp)
.L0f12f01c:
/*  f12f01c:	c4b00014 */ 	lwc1	$f16,0x14($a1)
/*  f12f020:	24c60028 */ 	addiu	$a2,$a2,0x28
/*  f12f024:	28c10190 */ 	slti	$at,$a2,0x190
/*  f12f028:	4610a032 */ 	c.eq.s	$f20,$f16
/*  f12f02c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f12f030:	27a400ac */ 	addiu	$a0,$sp,0xac
/*  f12f034:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f12f038:	45010017 */ 	bc1t	.L0f12f098
/*  f12f03c:	00000000 */ 	nop
.L0f12f040:
/*  f12f040:	c4620008 */ 	lwc1	$f2,0x8($v1)
/*  f12f044:	c4a00014 */ 	lwc1	$f0,0x14($a1)
/*  f12f048:	c4920000 */ 	lwc1	$f18,0x0($a0)
/*  f12f04c:	46001301 */ 	sub.s	$f12,$f2,$f0
/*  f12f050:	4612603c */ 	c.lt.s	$f12,$f18
/*  f12f054:	00000000 */ 	nop
/*  f12f058:	45020005 */ 	bc1fl	.L0f12f070
/*  f12f05c:	46001300 */ 	add.s	$f12,$f2,$f0
/*  f12f060:	e48c0000 */ 	swc1	$f12,0x0($a0)
/*  f12f064:	c4620008 */ 	lwc1	$f2,0x8($v1)
/*  f12f068:	c4a00014 */ 	lwc1	$f0,0x14($a1)
/*  f12f06c:	46001300 */ 	add.s	$f12,$f2,$f0
.L0f12f070:
/*  f12f070:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f12f074:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12f078:	460c503c */ 	c.lt.s	$f10,$f12
/*  f12f07c:	00000000 */ 	nop
/*  f12f080:	45020003 */ 	bc1fl	.L0f12f090
/*  f12f084:	24420004 */ 	addiu	$v0,$v0,4
/*  f12f088:	e44c0000 */ 	swc1	$f12,0x0($v0)
/*  f12f08c:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f12f090:
/*  f12f090:	1447ffeb */ 	bne	$v0,$a3,.L0f12f040
/*  f12f094:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f12f098:
/*  f12f098:	1420ffe0 */ 	bnez	$at,.L0f12f01c
/*  f12f09c:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f12f0a0:	27a400ac */ 	addiu	$a0,$sp,0xac
/*  f12f0a4:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f12f0a8:	26c60028 */ 	addiu	$a2,$s6,0x28
/*  f12f0ac:	24070007 */ 	addiu	$a3,$zero,0x7
/*  f12f0b0:	0fc59434 */ 	jal	func0f1650d0
/*  f12f0b4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f12f0b8:	964b0006 */ 	lhu	$t3,0x6($s2)
/*  f12f0bc:	86580004 */ 	lh	$t8,0x4($s2)
/*  f12f0c0:	00003025 */ 	or	$a2,$zero,$zero
/*  f12f0c4:	000b5242 */ 	srl	$t2,$t3,0x9
/*  f12f0c8:	01540019 */ 	multu	$t2,$s4
/*  f12f0cc:	02402825 */ 	or	$a1,$s2,$zero
/*  f12f0d0:	24030190 */ 	addiu	$v1,$zero,0x190
/*  f12f0d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f12f0d8:	00006812 */ 	mflo	$t5
/*  f12f0dc:	026d6021 */ 	addu	$t4,$s3,$t5
/*  f12f0e0:	858e0004 */ 	lh	$t6,0x4($t4)
/*  f12f0e4:	01d8082a */ 	slt	$at,$t6,$t8
/*  f12f0e8:	1020000e */ 	beqz	$at,.L0f12f124
/*  f12f0ec:	00000000 */ 	nop
/*  f12f0f0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f12f0f4:
/*  f12f0f4:	c4a60014 */ 	lwc1	$f6,0x14($a1)
/*  f12f0f8:	24c60028 */ 	addiu	$a2,$a2,0x28
/*  f12f0fc:	4606a03c */ 	c.lt.s	$f20,$f6
/*  f12f100:	00000000 */ 	nop
/*  f12f104:	45000003 */ 	bc1f	.L0f12f114
/*  f12f108:	00000000 */ 	nop
/*  f12f10c:	10000005 */ 	b	.L0f12f124
/*  f12f110:	00001025 */ 	or	$v0,$zero,$zero
.L0f12f114:
/*  f12f114:	14c3fff7 */ 	bne	$a2,$v1,.L0f12f0f4
/*  f12f118:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f12f11c:	10000001 */ 	b	.L0f12f124
/*  f12f120:	00000000 */ 	nop
.L0f12f124:
/*  f12f124:	50400005 */ 	beqzl	$v0,.L0f12f13c
/*  f12f128:	00001025 */ 	or	$v0,$zero,$zero
/*  f12f12c:	ae400000 */ 	sw	$zero,0x0($s2)
/*  f12f130:	10000002 */ 	b	.L0f12f13c
/*  f12f134:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f12f138:	00001025 */ 	or	$v0,$zero,$zero
.L0f12f13c:
/*  f12f13c:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f12f140:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f12f144:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f12f148:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f12f14c:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f12f150:	d7bc0040 */ 	ldc1	$f28,0x40($sp)
/*  f12f154:	d7be0048 */ 	ldc1	$f30,0x48($sp)
/*  f12f158:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f12f15c:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f12f160:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f12f164:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f12f168:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f12f16c:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f12f170:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f12f174:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f12f178:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f12f17c:	03e00008 */ 	jr	$ra
/*  f12f180:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);

u32 smokeUpdateZ(struct prop *prop)
{
	f32 *matrix = currentPlayerGetMatrix();

	prop->z = -(matrix[2] * prop->pos.x + matrix[6] * prop->pos.y + matrix[10] * prop->pos.z + matrix[14]);

	if (prop->z < 100) {
		prop->z *= 0.5f;
	} else {
		prop->z -= 100;
	}

	prop->flags |= PROPFLAG_40 | PROPFLAG_02;

	return 0;
}

GLOBAL_ASM(
glabel func0f12f230
/*  f12f230:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f12f234:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f12f238:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f12f23c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f12f240:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f12f244:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f12f248:	8c920004 */ 	lw	$s2,0x4($a0)
/*  f12f24c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f12f250:	00a08825 */ 	or	$s1,$a1,$zero
/*  f12f254:	00803825 */ 	or	$a3,$a0,$zero
/*  f12f258:	14c00003 */ 	bnez	$a2,.L0f12f268
/*  f12f25c:	afae0070 */ 	sw	$t6,0x70($sp)
/*  f12f260:	100000de */ 	b	.L0f12f5dc
/*  f12f264:	00a01025 */ 	or	$v0,$a1,$zero
.L0f12f268:
/*  f12f268:	84f00028 */ 	lh	$s0,0x28($a3)
/*  f12f26c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f12f270:	00001825 */ 	or	$v1,$zero,$zero
/*  f12f274:	12060016 */ 	beq	$s0,$a2,.L0f12f2d0
/*  f12f278:	3c04800a */ 	lui	$a0,%hi(g_Rooms)
/*  f12f27c:	8c844928 */ 	lw	$a0,%lo(g_Rooms)($a0)
/*  f12f280:	2405008c */ 	addiu	$a1,$zero,0x8c
.L0f12f284:
/*  f12f284:	02050019 */ 	multu	$s0,$a1
/*  f12f288:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f12f28c:	00035040 */ 	sll	$t2,$v1,0x1
/*  f12f290:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f12f294:	00007812 */ 	mflo	$t7
/*  f12f298:	008f1021 */ 	addu	$v0,$a0,$t7
/*  f12f29c:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f12f2a0:	53000009 */ 	beqzl	$t8,.L0f12f2c8
/*  f12f2a4:	85700028 */ 	lh	$s0,0x28($t3)
/*  f12f2a8:	84590002 */ 	lh	$t9,0x2($v0)
/*  f12f2ac:	53200006 */ 	beqzl	$t9,.L0f12f2c8
/*  f12f2b0:	85700028 */ 	lh	$s0,0x28($t3)
/*  f12f2b4:	94480000 */ 	lhu	$t0,0x0($v0)
/*  f12f2b8:	31090004 */ 	andi	$t1,$t0,0x4
/*  f12f2bc:	15200004 */ 	bnez	$t1,.L0f12f2d0
/*  f12f2c0:	00000000 */ 	nop
/*  f12f2c4:	85700028 */ 	lh	$s0,0x28($t3)
.L0f12f2c8:
/*  f12f2c8:	1606ffee */ 	bne	$s0,$a2,.L0f12f284
/*  f12f2cc:	00000000 */ 	nop
.L0f12f2d0:
/*  f12f2d0:	120600c1 */ 	beq	$s0,$a2,.L0f12f5d8
/*  f12f2d4:	02002025 */ 	or	$a0,$s0,$zero
/*  f12f2d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f12f2dc:	0fc59b74 */ 	jal	func0f166dd0
/*  f12f2e0:	afa700a8 */ 	sw	$a3,0xa8($sp)
/*  f12f2e4:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f12f2e8:	02002025 */ 	or	$a0,$s0,$zero
/*  f12f2ec:	0fc59b7c */ 	jal	func0f166df0
/*  f12f2f0:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f12f2f4:	4480a000 */ 	mtc1	$zero,$f20
/*  f12f2f8:	c6440014 */ 	lwc1	$f4,0x14($s2)
/*  f12f2fc:	8fa700a8 */ 	lw	$a3,0xa8($sp)
/*  f12f300:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f12f304:	24e40028 */ 	addiu	$a0,$a3,0x28
/*  f12f308:	45000026 */ 	bc1f	.L0f12f3a4
/*  f12f30c:	00000000 */ 	nop
/*  f12f310:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f12f314:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f12f318:	3c01c4fa */ 	lui	$at,0xc4fa
/*  f12f31c:	44817000 */ 	mtc1	$at,$f14
/*  f12f320:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f12f324:	c64a000c */ 	lwc1	$f10,0xc($s2)
/*  f12f328:	c7b20078 */ 	lwc1	$f18,0x78($sp)
/*  f12f32c:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*  f12f330:	460e003c */ 	c.lt.s	$f0,$f14
/*  f12f334:	c6440010 */ 	lwc1	$f4,0x10($s2)
/*  f12f338:	46125081 */ 	sub.s	$f2,$f10,$f18
/*  f12f33c:	45010018 */ 	bc1t	.L0f12f3a0
/*  f12f340:	46062301 */ 	sub.s	$f12,$f4,$f6
/*  f12f344:	3c0144fa */ 	lui	$at,0x44fa
/*  f12f348:	44818000 */ 	mtc1	$at,$f16
/*  f12f34c:	00000000 */ 	nop
/*  f12f350:	4600803c */ 	c.lt.s	$f16,$f0
/*  f12f354:	00000000 */ 	nop
/*  f12f358:	45030012 */ 	bc1tl	.L0f12f3a4
/*  f12f35c:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f12f360:	460e103c */ 	c.lt.s	$f2,$f14
/*  f12f364:	00000000 */ 	nop
/*  f12f368:	4503000e */ 	bc1tl	.L0f12f3a4
/*  f12f36c:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f12f370:	4602803c */ 	c.lt.s	$f16,$f2
/*  f12f374:	00000000 */ 	nop
/*  f12f378:	4503000a */ 	bc1tl	.L0f12f3a4
/*  f12f37c:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f12f380:	460e603c */ 	c.lt.s	$f12,$f14
/*  f12f384:	00000000 */ 	nop
/*  f12f388:	45030006 */ 	bc1tl	.L0f12f3a4
/*  f12f38c:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f12f390:	460c803c */ 	c.lt.s	$f16,$f12
/*  f12f394:	00000000 */ 	nop
/*  f12f398:	45000002 */ 	bc1f	.L0f12f3a4
/*  f12f39c:	00000000 */ 	nop
.L0f12f3a0:
/*  f12f3a0:	afa00070 */ 	sw	$zero,0x70($sp)
.L0f12f3a4:
/*  f12f3a4:	0fc2396a */ 	jal	func0f08e5a8
/*  f12f3a8:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f12f3ac:	1840000a */ 	blez	$v0,.L0f12f3d8
/*  f12f3b0:	00000000 */ 	nop
/*  f12f3b4:	87ac009e */ 	lh	$t4,0x9e($sp)
/*  f12f3b8:	02202025 */ 	or	$a0,$s1,$zero
/*  f12f3bc:	87a50098 */ 	lh	$a1,0x98($sp)
/*  f12f3c0:	87a6009a */ 	lh	$a2,0x9a($sp)
/*  f12f3c4:	87a7009c */ 	lh	$a3,0x9c($sp)
/*  f12f3c8:	0fc57306 */ 	jal	func0f15cc18
/*  f12f3cc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f12f3d0:	10000004 */ 	b	.L0f12f3e4
/*  f12f3d4:	00408825 */ 	or	$s1,$v0,$zero
.L0f12f3d8:
/*  f12f3d8:	0fc572dd */ 	jal	func0f15cb74
/*  f12f3dc:	02202025 */ 	or	$a0,$s1,$zero
/*  f12f3e0:	00408825 */ 	or	$s1,$v0,$zero
.L0f12f3e4:
/*  f12f3e4:	02201025 */ 	or	$v0,$s1,$zero
/*  f12f3e8:	3c0e0001 */ 	lui	$t6,0x1
/*  f12f3ec:	35ce3000 */ 	ori	$t6,$t6,0x3000
/*  f12f3f0:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f12f3f4:	3c0db600 */ 	lui	$t5,0xb600
/*  f12f3f8:	3c0f0103 */ 	lui	$t7,0x103
/*  f12f3fc:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f12f400:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f12f404:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f12f408:	02201825 */ 	or	$v1,$s1,$zero
/*  f12f40c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f12f410:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f12f414:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f12f418:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f12f41c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12f420:	00402025 */ 	or	$a0,$v0,$zero
/*  f12f424:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*  f12f428:	02202025 */ 	or	$a0,$s1,$zero
/*  f12f42c:	02002825 */ 	or	$a1,$s0,$zero
/*  f12f430:	0fc59b5f */ 	jal	func0f166d7c
/*  f12f434:	af020004 */ 	sw	$v0,0x4($t8)
/*  f12f438:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f12f43c:	00408825 */ 	or	$s1,$v0,$zero
/*  f12f440:	02208025 */ 	or	$s0,$s1,$zero
/*  f12f444:	1320000b */ 	beqz	$t9,.L0f12f474
/*  f12f448:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f12f44c:	3c080100 */ 	lui	$t0,0x100
/*  f12f450:	35080040 */ 	ori	$t0,$t0,0x40
/*  f12f454:	3c04800a */ 	lui	$a0,%hi(var800a3448)
/*  f12f458:	24843448 */ 	addiu	$a0,$a0,%lo(var800a3448)
/*  f12f45c:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f12f460:	00408025 */ 	or	$s0,$v0,$zero
/*  f12f464:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12f468:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f12f46c:	10000008 */ 	b	.L0f12f490
/*  f12f470:	ae020004 */ 	sw	$v0,0x4($s0)
.L0f12f474:
/*  f12f474:	3c090100 */ 	lui	$t1,0x100
/*  f12f478:	35290040 */ 	ori	$t1,$t1,0x40
/*  f12f47c:	3c04800a */ 	lui	$a0,%hi(var800a3488)
/*  f12f480:	24843488 */ 	addiu	$a0,$a0,%lo(var800a3488)
/*  f12f484:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12f488:	ae090000 */ 	sw	$t1,0x0($s0)
/*  f12f48c:	ae020004 */ 	sw	$v0,0x4($s0)
.L0f12f490:
/*  f12f490:	02201025 */ 	or	$v0,$s1,$zero
/*  f12f494:	3c0a0600 */ 	lui	$t2,0x600
/*  f12f498:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f12f49c:	3c0b800b */ 	lui	$t3,%hi(var800ab564)
/*  f12f4a0:	8d6bb564 */ 	lw	$t3,%lo(var800ab564)($t3)
/*  f12f4a4:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f12f4a8:	02201825 */ 	or	$v1,$s1,$zero
/*  f12f4ac:	3c0cba00 */ 	lui	$t4,0xba00
/*  f12f4b0:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f12f4b4:	358c0602 */ 	ori	$t4,$t4,0x602
/*  f12f4b8:	240d0080 */ 	addiu	$t5,$zero,0x80
/*  f12f4bc:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f12f4c0:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f12f4c4:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f12f4c8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f12f4cc:	00001825 */ 	or	$v1,$zero,$zero
/*  f12f4d0:	11c00010 */ 	beqz	$t6,.L0f12f514
/*  f12f4d4:	02408025 */ 	or	$s0,$s2,$zero
/*  f12f4d8:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f12f4dc:	3c014120 */ 	lui	$at,0x4120
/*  f12f4e0:	44810000 */ 	mtc1	$at,$f0
/*  f12f4e4:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f12f4e8:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f12f4ec:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f12f4f0:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f12f4f4:	44815000 */ 	mtc1	$at,$f10
/*  f12f4f8:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f12f4fc:	e7a40090 */ 	swc1	$f4,0x90($sp)
/*  f12f500:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f12f504:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f12f508:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f12f50c:	1000000e */ 	b	.L0f12f548
/*  f12f510:	e7a80094 */ 	swc1	$f8,0x94($sp)
.L0f12f514:
/*  f12f514:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f12f518:	3c0140a0 */ 	lui	$at,0x40a0
/*  f12f51c:	44810000 */ 	mtc1	$at,$f0
/*  f12f520:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f12f524:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f12f528:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f12f52c:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f12f530:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f12f534:	e7a80090 */ 	swc1	$f8,0x90($sp)
/*  f12f538:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f12f53c:	e7a00088 */ 	swc1	$f0,0x88($sp)
/*  f12f540:	46005482 */ 	mul.s	$f18,$f10,$f0
/*  f12f544:	e7b20094 */ 	swc1	$f18,0x94($sp)
.L0f12f548:
/*  f12f548:	c6040014 */ 	lwc1	$f4,0x14($s0)
/*  f12f54c:	02402025 */ 	or	$a0,$s2,$zero
/*  f12f550:	26050008 */ 	addiu	$a1,$s0,0x8
/*  f12f554:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f12f558:	02203025 */ 	or	$a2,$s1,$zero
/*  f12f55c:	27a7008c */ 	addiu	$a3,$sp,0x8c
/*  f12f560:	c7a60088 */ 	lwc1	$f6,0x88($sp)
/*  f12f564:	45020008 */ 	bc1fl	.L0f12f588
/*  f12f568:	e6140014 */ 	swc1	$f20,0x14($s0)
/*  f12f56c:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f12f570:	0fc4b4fc */ 	jal	func0f12d3f0
/*  f12f574:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f12f578:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f12f57c:	10000002 */ 	b	.L0f12f588
/*  f12f580:	00408825 */ 	or	$s1,$v0,$zero
/*  f12f584:	e6140014 */ 	swc1	$f20,0x14($s0)
.L0f12f588:
/*  f12f588:	24630028 */ 	addiu	$v1,$v1,0x28
/*  f12f58c:	24010190 */ 	addiu	$at,$zero,0x190
/*  f12f590:	1461ffed */ 	bne	$v1,$at,.L0f12f548
/*  f12f594:	26100028 */ 	addiu	$s0,$s0,0x28
/*  f12f598:	02201025 */ 	or	$v0,$s1,$zero
/*  f12f59c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f12f5a0:	35ef0602 */ 	ori	$t7,$t7,0x602
/*  f12f5a4:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f12f5a8:	24180040 */ 	addiu	$t8,$zero,0x40
/*  f12f5ac:	3c190103 */ 	lui	$t9,0x103
/*  f12f5b0:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f12f5b4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f12f5b8:	37390040 */ 	ori	$t9,$t9,0x40
/*  f12f5bc:	02208025 */ 	or	$s0,$s1,$zero
/*  f12f5c0:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f12f5c4:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f12f5c8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f12f5cc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12f5d0:	00402025 */ 	or	$a0,$v0,$zero
/*  f12f5d4:	ae020004 */ 	sw	$v0,0x4($s0)
.L0f12f5d8:
/*  f12f5d8:	02201025 */ 	or	$v0,$s1,$zero
.L0f12f5dc:
/*  f12f5dc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f12f5e0:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f12f5e4:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f12f5e8:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f12f5ec:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f12f5f0:	03e00008 */ 	jr	$ra
/*  f12f5f4:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

GLOBAL_ASM(
glabel func0f12f5f8
/*  f12f5f8:	3c03800a */ 	lui	$v1,%hi(g_NumSmokes)
/*  f12f5fc:	8c633444 */ 	lw	$v1,%lo(g_NumSmokes)($v1)
/*  f12f600:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*  f12f604:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f12f608:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f12f60c:	18600026 */ 	blez	$v1,.L0f12f6a8
/*  f12f610:	00001025 */ 	or	$v0,$zero,$zero
/*  f12f614:	3c108008 */ 	lui	$s0,%hi(g_SmokeTypes)
/*  f12f618:	3c09800a */ 	lui	$t1,%hi(g_Smokes)
/*  f12f61c:	25293440 */ 	addiu	$t1,$t1,%lo(g_Smokes)
/*  f12f620:	2610e940 */ 	addiu	$s0,$s0,%lo(g_SmokeTypes)
/*  f12f624:	00002825 */ 	or	$a1,$zero,$zero
/*  f12f628:	24110024 */ 	addiu	$s1,$zero,0x24
/*  f12f62c:	240d0009 */ 	addiu	$t5,$zero,0x9
/*  f12f630:	240c000b */ 	addiu	$t4,$zero,0xb
/*  f12f634:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f12f638:	240a0007 */ 	addiu	$t2,$zero,0x7
.L0f12f63c:
/*  f12f63c:	8d240000 */ 	lw	$a0,0x0($t1)
/*  f12f640:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f12f644:	00857021 */ 	addu	$t6,$a0,$a1
/*  f12f648:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f12f64c:	00a43021 */ 	addu	$a2,$a1,$a0
/*  f12f650:	51e00013 */ 	beqzl	$t7,.L0f12f6a0
/*  f12f654:	0043082a */ 	slt	$at,$v0,$v1
/*  f12f658:	94c70006 */ 	lhu	$a3,0x6($a2)
/*  f12f65c:	0007c242 */ 	srl	$t8,$a3,0x9
/*  f12f660:	5158000f */ 	beql	$t2,$t8,.L0f12f6a0
/*  f12f664:	0043082a */ 	slt	$at,$v0,$v1
/*  f12f668:	5178000d */ 	beql	$t3,$t8,.L0f12f6a0
/*  f12f66c:	0043082a */ 	slt	$at,$v0,$v1
/*  f12f670:	5198000b */ 	beql	$t4,$t8,.L0f12f6a0
/*  f12f674:	0043082a */ 	slt	$at,$v0,$v1
/*  f12f678:	51b80009 */ 	beql	$t5,$t8,.L0f12f6a0
/*  f12f67c:	0043082a */ 	slt	$at,$v0,$v1
/*  f12f680:	03110019 */ 	multu	$t8,$s1
/*  f12f684:	3c03800a */ 	lui	$v1,%hi(g_NumSmokes)
/*  f12f688:	0000c812 */ 	mflo	$t9
/*  f12f68c:	02197021 */ 	addu	$t6,$s0,$t9
/*  f12f690:	85cf0000 */ 	lh	$t7,0x0($t6)
/*  f12f694:	a4cf0004 */ 	sh	$t7,0x4($a2)
/*  f12f698:	8c633444 */ 	lw	$v1,%lo(g_NumSmokes)($v1)
/*  f12f69c:	0043082a */ 	slt	$at,$v0,$v1
.L0f12f6a0:
/*  f12f6a0:	1420ffe6 */ 	bnez	$at,.L0f12f63c
/*  f12f6a4:	24a5019c */ 	addiu	$a1,$a1,0x19c
.L0f12f6a8:
/*  f12f6a8:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f12f6ac:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f12f6b0:	03e00008 */ 	jr	$ra
/*  f12f6b4:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*  f12f6b8:	00000000 */ 	nop
/*  f12f6bc:	00000000 */ 	nop
);
