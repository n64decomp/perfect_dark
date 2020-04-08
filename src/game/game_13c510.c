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
#include "game/game_0b2150.h"
#include "game/game_0b3350.h"
#include "game/game_11f000.h"
#include "game/game_13c510.h"
#include "game/game_157db0.h"
#include "game/game_1655c0.h"
#include "game/game_165670.h"
#include "game/game_1668e0.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "types.h"

const u32 var7f1b5990[] = {0x4effffff};
const u32 var7f1b5994[] = {0x4effffff};
const u32 var7f1b5998[] = {0xceffffff};
const u32 var7f1b599c[] = {0x38d1b717};
const u32 var7f1b59a0[] = {0x38d1b717};
const u32 var7f1b59a4[] = {0x3ecccccd};
const u32 var7f1b59a8[] = {0x38d1b717};
const u32 var7f1b59ac[] = {0x43ff8000};
const u32 var7f1b59b0[] = {0x46fe8000};
const u32 var7f1b59b4[] = {0x46fc5800};
const u32 var7f1b59b8[] = {0x44a28000};
const u32 var7f1b59bc[] = {0x44a28000};
const u32 var7f1b59c0[] = {0x3a49a634};
const u32 var7f1b59c4[] = {0x3f19999a};
const u32 var7f1b59c8[] = {0x461c3c00};
const u32 var7f1b59cc[] = {0x461c3c00};
const u32 var7f1b59d0[] = {0xc61c3c00};
const u32 var7f1b59d4[] = {0xc61c3c00};
const u32 var7f1b59d8[] = {0x43ff8000};
const u32 var7f1b59dc[] = {0x46fe8000};
const u32 var7f1b59e0[] = {0x3c8efa35};
const u32 var7f1b59e4[] = {0x4169999a};
const u32 var7f1b59e8[] = {0x3ecccccd};
const u32 var7f1b59ec[] = {0x3b808081};
const u32 var7f1b59f0[] = {0x46d6d800};
const u32 var7f1b59f4[] = {0x3b808081};
const u32 var7f1b59f8[] = {0x443b8000};
const u32 var7f1b59fc[] = {0x3c23d70a};
const u32 var7f1b5a00[] = {0x3c23d70a};
const u32 var7f1b5a04[] = {0x3b888889};
const u32 var7f1b5a08[] = {0x3b888889};
const u32 var7f1b5a0c[] = {0x3ecccccd};

GLOBAL_ASM(
glabel func0f13c510
/*  f13c510:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f13c514:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f13c518:	0c000913 */ 	jal	func0000244c
/*  f13c51c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c520:	00001825 */ 	or	$v1,$zero,$zero
/*  f13c524:	00402025 */ 	or	$a0,$v0,$zero
/*  f13c528:	24050078 */ 	addiu	$a1,$zero,0x78
.L0f13c52c:
/*  f13c52c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13c530:	24840014 */ 	addiu	$a0,$a0,0x14
/*  f13c534:	1465fffd */ 	bne	$v1,$a1,.L0f13c52c
/*  f13c538:	a480ffec */ 	sh	$zero,-0x14($a0)
/*  f13c53c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f13c540:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f13c544:	03e00008 */ 	jr	$ra
/*  f13c548:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13c54c
/*  f13c54c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f13c550:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f13c554:	0c00093a */ 	jal	func000024e8
/*  f13c558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c55c:	0c000944 */ 	jal	func00002510
/*  f13c560:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c564:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f13c568:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f13c56c:	03e00008 */ 	jr	$ra
/*  f13c570:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13c574
/*  f13c574:	3c014100 */ 	lui	$at,0x4100
/*  f13c578:	44812000 */ 	mtc1	$at,$f4
/*  f13c57c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f13c580:	3c014f00 */ 	lui	$at,0x4f00
/*  f13c584:	46046182 */ 	mul.s	$f6,$f12,$f4
/*  f13c588:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f13c58c:	444ef800 */ 	cfc1	$t6,$31
/*  f13c590:	44c2f800 */ 	ctc1	$v0,$31
/*  f13c594:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c598:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f13c59c:	4442f800 */ 	cfc1	$v0,$31
/*  f13c5a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c5a4:	30420078 */ 	andi	$v0,$v0,0x78
/*  f13c5a8:	50400013 */ 	beqzl	$v0,.L0f13c5f8
/*  f13c5ac:	44024000 */ 	mfc1	$v0,$f8
/*  f13c5b0:	44814000 */ 	mtc1	$at,$f8
/*  f13c5b4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f13c5b8:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f13c5bc:	44c2f800 */ 	ctc1	$v0,$31
/*  f13c5c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c5c4:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f13c5c8:	4442f800 */ 	cfc1	$v0,$31
/*  f13c5cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c5d0:	30420078 */ 	andi	$v0,$v0,0x78
/*  f13c5d4:	14400005 */ 	bnez	$v0,.L0f13c5ec
/*  f13c5d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c5dc:	44024000 */ 	mfc1	$v0,$f8
/*  f13c5e0:	3c018000 */ 	lui	$at,0x8000
/*  f13c5e4:	10000007 */ 	beqz	$zero,.L0f13c604
/*  f13c5e8:	00411025 */ 	or	$v0,$v0,$at
.L0f13c5ec:
/*  f13c5ec:	10000005 */ 	beqz	$zero,.L0f13c604
/*  f13c5f0:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f13c5f4:	44024000 */ 	mfc1	$v0,$f8
.L0f13c5f8:
/*  f13c5f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c5fc:	0440fffb */ 	bltz	$v0,.L0f13c5ec
/*  f13c600:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13c604:
/*  f13c604:	3c010003 */ 	lui	$at,0x3
/*  f13c608:	3421f801 */ 	ori	$at,$at,0xf801
/*  f13c60c:	0041082b */ 	sltu	$at,$v0,$at
/*  f13c610:	44cef800 */ 	ctc1	$t6,$31
/*  f13c614:	14200004 */ 	bnez	$at,.L0f13c628
/*  f13c618:	00401825 */ 	or	$v1,$v0,$zero
/*  f13c61c:	306f07ff */ 	andi	$t7,$v1,0x7ff
/*  f13c620:	10000035 */ 	beqz	$zero,.L0f13c6f8
/*  f13c624:	01e01825 */ 	or	$v1,$t7,$zero
.L0f13c628:
/*  f13c628:	3c010003 */ 	lui	$at,0x3
/*  f13c62c:	3421f001 */ 	ori	$at,$at,0xf001
/*  f13c630:	0041082b */ 	sltu	$at,$v0,$at
/*  f13c634:	14200005 */ 	bnez	$at,.L0f13c64c
/*  f13c638:	00401825 */ 	or	$v1,$v0,$zero
/*  f13c63c:	307807ff */ 	andi	$t8,$v1,0x7ff
/*  f13c640:	03001825 */ 	or	$v1,$t8,$zero
/*  f13c644:	1000002c */ 	beqz	$zero,.L0f13c6f8
/*  f13c648:	24040006 */ 	addiu	$a0,$zero,0x6
.L0f13c64c:
/*  f13c64c:	3c010003 */ 	lui	$at,0x3
/*  f13c650:	3421e001 */ 	ori	$at,$at,0xe001
/*  f13c654:	0041082b */ 	sltu	$at,$v0,$at
/*  f13c658:	14200004 */ 	bnez	$at,.L0f13c66c
/*  f13c65c:	0002c842 */ 	srl	$t9,$v0,0x1
/*  f13c660:	332307ff */ 	andi	$v1,$t9,0x7ff
/*  f13c664:	10000024 */ 	beqz	$zero,.L0f13c6f8
/*  f13c668:	24040005 */ 	addiu	$a0,$zero,0x5
.L0f13c66c:
/*  f13c66c:	3c010003 */ 	lui	$at,0x3
/*  f13c670:	3421c001 */ 	ori	$at,$at,0xc001
/*  f13c674:	0041082b */ 	sltu	$at,$v0,$at
/*  f13c678:	14200004 */ 	bnez	$at,.L0f13c68c
/*  f13c67c:	00024882 */ 	srl	$t1,$v0,0x2
/*  f13c680:	312307ff */ 	andi	$v1,$t1,0x7ff
/*  f13c684:	1000001c */ 	beqz	$zero,.L0f13c6f8
/*  f13c688:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f13c68c:
/*  f13c68c:	3c010003 */ 	lui	$at,0x3
/*  f13c690:	34218001 */ 	ori	$at,$at,0x8001
/*  f13c694:	0041082b */ 	sltu	$at,$v0,$at
/*  f13c698:	14200004 */ 	bnez	$at,.L0f13c6ac
/*  f13c69c:	000258c2 */ 	srl	$t3,$v0,0x3
/*  f13c6a0:	316307ff */ 	andi	$v1,$t3,0x7ff
/*  f13c6a4:	10000014 */ 	beqz	$zero,.L0f13c6f8
/*  f13c6a8:	24040003 */ 	addiu	$a0,$zero,0x3
.L0f13c6ac:
/*  f13c6ac:	3c010003 */ 	lui	$at,0x3
/*  f13c6b0:	34210001 */ 	ori	$at,$at,0x1
/*  f13c6b4:	0041082b */ 	sltu	$at,$v0,$at
/*  f13c6b8:	14200004 */ 	bnez	$at,.L0f13c6cc
/*  f13c6bc:	00026902 */ 	srl	$t5,$v0,0x4
/*  f13c6c0:	31a307ff */ 	andi	$v1,$t5,0x7ff
/*  f13c6c4:	1000000c */ 	beqz	$zero,.L0f13c6f8
/*  f13c6c8:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f13c6cc:
/*  f13c6cc:	3c010002 */ 	lui	$at,0x2
/*  f13c6d0:	34210001 */ 	ori	$at,$at,0x1
/*  f13c6d4:	0041082b */ 	sltu	$at,$v0,$at
/*  f13c6d8:	14200005 */ 	bnez	$at,.L0f13c6f0
/*  f13c6dc:	0002c982 */ 	srl	$t9,$v0,0x6
/*  f13c6e0:	00027942 */ 	srl	$t7,$v0,0x5
/*  f13c6e4:	31e307ff */ 	andi	$v1,$t7,0x7ff
/*  f13c6e8:	10000003 */ 	beqz	$zero,.L0f13c6f8
/*  f13c6ec:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f13c6f0:
/*  f13c6f0:	332307ff */ 	andi	$v1,$t9,0x7ff
/*  f13c6f4:	00002025 */ 	or	$a0,$zero,$zero
.L0f13c6f8:
/*  f13c6f8:	00044b40 */ 	sll	$t1,$a0,0xd
/*  f13c6fc:	00035080 */ 	sll	$t2,$v1,0x2
/*  f13c700:	012a1025 */ 	or	$v0,$t1,$t2
/*  f13c704:	304bffff */ 	andi	$t3,$v0,0xffff
/*  f13c708:	03e00008 */ 	jr	$ra
/*  f13c70c:	01601025 */ 	or	$v0,$t3,$zero
);

GLOBAL_ASM(
glabel func0f13c710
/*  f13c710:	44802000 */ 	mtc1	$zero,$f4
/*  f13c714:	3c017f1b */ 	lui	$at,%hi(var7f1b5998)
/*  f13c718:	460c203c */ 	c.lt.s	$f4,$f12
/*  f13c71c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c720:	4500000d */ 	bc1f	.L0f13c758
/*  f13c724:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c728:	3c017f1b */ 	lui	$at,%hi(var7f1b5990)
/*  f13c72c:	c4265990 */ 	lwc1	$f6,%lo(var7f1b5990)($at)
/*  f13c730:	3c017f1b */ 	lui	$at,%hi(var7f1b5994)
/*  f13c734:	460c303c */ 	c.lt.s	$f6,$f12
/*  f13c738:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c73c:	4502000d */ 	bc1fl	.L0f13c774
/*  f13c740:	4600620d */ 	trunc.w.s	$f8,$f12
/*  f13c744:	c42c5994 */ 	lwc1	$f12,%lo(var7f1b5994)($at)
/*  f13c748:	4600620d */ 	trunc.w.s	$f8,$f12
/*  f13c74c:	44024000 */ 	mfc1	$v0,$f8
/*  f13c750:	03e00008 */ 	jr	$ra
/*  f13c754:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13c758:
/*  f13c758:	c4205998 */ 	lwc1	$f0,%lo(var7f1b5998)($at)
/*  f13c75c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f13c760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c764:	45020003 */ 	bc1fl	.L0f13c774
/*  f13c768:	4600620d */ 	trunc.w.s	$f8,$f12
/*  f13c76c:	46000306 */ 	mov.s	$f12,$f0
/*  f13c770:	4600620d */ 	trunc.w.s	$f8,$f12
.L0f13c774:
/*  f13c774:	44024000 */ 	mfc1	$v0,$f8
/*  f13c778:	03e00008 */ 	jr	$ra
/*  f13c77c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13c780
/*  f13c780:	27bdfe28 */ 	addiu	$sp,$sp,-472
/*  f13c784:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f13c788:	afbe0068 */ 	sw	$s8,0x68($sp)
/*  f13c78c:	afb70064 */ 	sw	$s7,0x64($sp)
/*  f13c790:	afb60060 */ 	sw	$s6,0x60($sp)
/*  f13c794:	afb5005c */ 	sw	$s5,0x5c($sp)
/*  f13c798:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f13c79c:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f13c7a0:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f13c7a4:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f13c7a8:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f13c7ac:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f13c7b0:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f13c7b4:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f13c7b8:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f13c7bc:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f13c7c0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f13c7c4:	0c000913 */ 	jal	func0000244c
/*  f13c7c8:	afa401d8 */ 	sw	$a0,0x1d8($sp)
/*  f13c7cc:	8fa501d8 */ 	lw	$a1,0x1d8($sp)
/*  f13c7d0:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f13c7d4:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f13c7d8:	0005c8c0 */ 	sll	$t9,$a1,0x3
/*  f13c7dc:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*  f13c7e0:	0325c821 */ 	addu	$t9,$t9,$a1
/*  f13c7e4:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*  f13c7e8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f13c7ec:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f13c7f0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f13c7f4:	25cf1bb0 */ 	addiu	$t7,$t6,0x1bb0
/*  f13c7f8:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f13c7fc:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f13c800:	03192021 */ 	addu	$a0,$t8,$t9
/*  f13c804:	8c830014 */ 	lw	$v1,0x14($a0)
/*  f13c808:	506002dd */ 	beqzl	$v1,.L0f13d380
/*  f13c80c:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f13c810:	84880002 */ 	lh	$t0,0x2($a0)
/*  f13c814:	510002da */ 	beqzl	$t0,.L0f13d380
/*  f13c818:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f13c81c:	84660012 */ 	lh	$a2,0x12($v1)
/*  f13c820:	27b00138 */ 	addiu	$s0,$sp,0x138
/*  f13c824:	3c0a800a */ 	lui	$t2,%hi(var800a4cd8)
/*  f13c828:	10c002d4 */ 	beqz	$a2,.L0f13d37c
/*  f13c82c:	3c0d800a */ 	lui	$t5,%hi(var800a41a0)
/*  f13c830:	84620010 */ 	lh	$v0,0x10($v1)
/*  f13c834:	8d4a4cd8 */ 	lw	$t2,%lo(var800a4cd8)($t2)
/*  f13c838:	8dad41a0 */ 	lw	$t5,%lo(var800a41a0)($t5)
/*  f13c83c:	00024900 */ 	sll	$t1,$v0,0x4
/*  f13c840:	01224821 */ 	addu	$t1,$t1,$v0
/*  f13c844:	00094840 */ 	sll	$t1,$t1,0x1
/*  f13c848:	00026080 */ 	sll	$t4,$v0,0x2
/*  f13c84c:	01826023 */ 	subu	$t4,$t4,$v0
/*  f13c850:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f13c854:	afab00c0 */ 	sw	$t3,0xc0($sp)
/*  f13c858:	afa601c0 */ 	sw	$a2,0x1c0($sp)
/*  f13c85c:	02002025 */ 	or	$a0,$s0,$zero
/*  f13c860:	0fc59a9b */ 	jal	func0f166a6c
/*  f13c864:	018d8821 */ 	addu	$s1,$t4,$t5
/*  f13c868:	0fc5722e */ 	jal	currentPlayerGetScaleBg2Gfx
/*  f13c86c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c870:	46000306 */ 	mov.s	$f12,$f0
/*  f13c874:	0c0057e2 */ 	jal	func00015f88
/*  f13c878:	02002825 */ 	or	$a1,$s0,$zero
/*  f13c87c:	0fc2d3f2 */ 	jal	currentPlayerGetUnk006c
/*  f13c880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c884:	00402025 */ 	or	$a0,$v0,$zero
/*  f13c888:	02002825 */ 	or	$a1,$s0,$zero
/*  f13c88c:	0c005680 */ 	jal	func00015a00
/*  f13c890:	27a600f8 */ 	addiu	$a2,$sp,0xf8
/*  f13c894:	0c002f22 */ 	jal	func0000bc88
/*  f13c898:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c89c:	44822000 */ 	mtc1	$v0,$f4
/*  f13c8a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c8a4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13c8a8:	0c002f26 */ 	jal	func0000bc98
/*  f13c8ac:	e7a601bc */ 	swc1	$f6,0x1bc($sp)
/*  f13c8b0:	44824000 */ 	mtc1	$v0,$f8
/*  f13c8b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c8b8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f13c8bc:	0c002f40 */ 	jal	func0000bd00
/*  f13c8c0:	e7aa01b8 */ 	swc1	$f10,0x1b8($sp)
/*  f13c8c4:	44822000 */ 	mtc1	$v0,$f4
/*  f13c8c8:	0c002f44 */ 	jal	func0000bd10
/*  f13c8cc:	468027a0 */ 	cvt.s.w	$f30,$f4
/*  f13c8d0:	8fae01c0 */ 	lw	$t6,0x1c0($sp)
/*  f13c8d4:	44823000 */ 	mtc1	$v0,$f6
/*  f13c8d8:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f13c8dc:	19c002a7 */ 	blez	$t6,.L0f13d37c
/*  f13c8e0:	46803720 */ 	cvt.s.w	$f28,$f6
/*  f13c8e4:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f13c8e8:	3c013f80 */ 	lui	$at,0x3f80
/*  f13c8ec:	3c1e8008 */ 	lui	$s8,%hi(var800844f0)
/*  f13c8f0:	4481d000 */ 	mtc1	$at,$f26
/*  f13c8f4:	4480c000 */ 	mtc1	$zero,$f24
/*  f13c8f8:	27de44f0 */ 	addiu	$s8,$s8,%lo(var800844f0)
/*  f13c8fc:	afb10090 */ 	sw	$s1,0x90($sp)
/*  f13c900:	afa0008c */ 	sw	$zero,0x8c($sp)
/*  f13c904:	27b600f8 */ 	addiu	$s6,$sp,0xf8
/*  f13c908:	27b50104 */ 	addiu	$s5,$sp,0x104
/*  f13c90c:	afaf00a0 */ 	sw	$t7,0xa0($sp)
/*  f13c910:	afaf0088 */ 	sw	$t7,0x88($sp)
.L0f13c914:
/*  f13c914:	e7b800d0 */ 	swc1	$f24,0xd0($sp)
/*  f13c918:	e7b800d4 */ 	swc1	$f24,0xd4($sp)
/*  f13c91c:	e7b800d8 */ 	swc1	$f24,0xd8($sp)
/*  f13c920:	00001825 */ 	or	$v1,$zero,$zero
/*  f13c924:	8fb100a0 */ 	lw	$s1,0xa0($sp)
.L0f13c928:
/*  f13c928:	8638000a */ 	lh	$t8,0xa($s1)
/*  f13c92c:	c7a800d0 */ 	lwc1	$f8,0xd0($sp)
/*  f13c930:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13c934:	44985000 */ 	mtc1	$t8,$f10
/*  f13c938:	28610004 */ 	slti	$at,$v1,0x4
/*  f13c93c:	26310006 */ 	addiu	$s1,$s1,0x6
/*  f13c940:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f13c944:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f13c948:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f13c94c:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f13c950:	86390006 */ 	lh	$t9,0x6($s1)
/*  f13c954:	44994000 */ 	mtc1	$t9,$f8
/*  f13c958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c95c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f13c960:	c7a800d8 */ 	lwc1	$f8,0xd8($sp)
/*  f13c964:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f13c968:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f13c96c:	86280008 */ 	lh	$t0,0x8($s1)
/*  f13c970:	44885000 */ 	mtc1	$t0,$f10
/*  f13c974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13c978:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f13c97c:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f13c980:	1420ffe9 */ 	bnez	$at,.L0f13c928
/*  f13c984:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
/*  f13c988:	3c013e80 */ 	lui	$at,0x3e80
/*  f13c98c:	44817000 */ 	mtc1	$at,$f14
/*  f13c990:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f13c994:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f13c998:	8faa01d8 */ 	lw	$t2,0x1d8($sp)
/*  f13c99c:	460e5202 */ 	mul.s	$f8,$f10,$f14
/*  f13c9a0:	c7aa00d8 */ 	lwc1	$f10,0xd8($sp)
/*  f13c9a4:	3c09800a */ 	lui	$t1,%hi(var800a4cc4)
/*  f13c9a8:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f13c9ac:	8d294cc4 */ 	lw	$t1,%lo(var800a4cc4)($t1)
/*  f13c9b0:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f13c9b4:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f13c9b8:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f13c9bc:	460e5202 */ 	mul.s	$f8,$f10,$f14
/*  f13c9c0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f13c9c4:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f13c9c8:	27a400c4 */ 	addiu	$a0,$sp,0xc4
/*  f13c9cc:	27a200d0 */ 	addiu	$v0,$sp,0xd0
/*  f13c9d0:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f13c9d4:	27a700dc */ 	addiu	$a3,$sp,0xdc
/*  f13c9d8:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*  f13c9dc:	012b3021 */ 	addu	$a2,$t1,$t3
.L0f13c9e0:
/*  f13c9e0:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f13c9e4:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*  f13c9e8:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f13c9ec:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f13c9f0:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f13c9f4:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f13c9f8:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f13c9fc:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f13ca00:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f13ca04:	1447fff6 */ 	bne	$v0,$a3,.L0f13c9e0
/*  f13ca08:	e484fffc */ 	swc1	$f4,-0x4($a0)
/*  f13ca0c:	8fac0090 */ 	lw	$t4,0x90($sp)
/*  f13ca10:	3c017f1b */ 	lui	$at,%hi(var7f1b599c)
/*  f13ca14:	a1800001 */ 	sb	$zero,0x1($t4)
/*  f13ca18:	a1800002 */ 	sb	$zero,0x2($t4)
/*  f13ca1c:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f13ca20:	c7a800c4 */ 	lwc1	$f8,0xc4($sp)
/*  f13ca24:	c7a400c8 */ 	lwc1	$f4,0xc8($sp)
/*  f13ca28:	81a20009 */ 	lb	$v0,0x9($t5)
/*  f13ca2c:	81a30007 */ 	lb	$v1,0x7($t5)
/*  f13ca30:	81a40008 */ 	lb	$a0,0x8($t5)
/*  f13ca34:	00420019 */ 	multu	$v0,$v0
/*  f13ca38:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f13ca3c:	00007012 */ 	mflo	$t6
/*  f13ca40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ca44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ca48:	00630019 */ 	multu	$v1,$v1
/*  f13ca4c:	00007812 */ 	mflo	$t7
/*  f13ca50:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f13ca54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ca58:	00840019 */ 	multu	$a0,$a0
/*  f13ca5c:	0000c812 */ 	mflo	$t9
/*  f13ca60:	03194021 */ 	addu	$t0,$t8,$t9
/*  f13ca64:	44883000 */ 	mtc1	$t0,$f6
/*  f13ca68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ca6c:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f13ca70:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f13ca74:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f13ca78:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f13ca7c:	c426599c */ 	lwc1	$f6,%lo(var7f1b599c)($at)
/*  f13ca80:	46042282 */ 	mul.s	$f10,$f4,$f4
/*  f13ca84:	3c017f1b */ 	lui	$at,%hi(var7f1b59a0)
/*  f13ca88:	460e303c */ 	c.lt.s	$f6,$f14
/*  f13ca8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ca90:	45000029 */ 	bc1f	.L0f13cb38
/*  f13ca94:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f13ca98:	c42459a0 */ 	lwc1	$f4,%lo(var7f1b59a0)($at)
/*  f13ca9c:	4610203c */ 	c.lt.s	$f4,$f16
/*  f13caa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13caa4:	45020025 */ 	bc1fl	.L0f13cb3c
/*  f13caa8:	e7b80190 */ 	swc1	$f24,0x190($sp)
/*  f13caac:	46107302 */ 	mul.s	$f12,$f14,$f16
/*  f13cab0:	0c012974 */ 	jal	sqrtf
/*  f13cab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cab8:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f13cabc:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f13cac0:	3c017f1b */ 	lui	$at,%hi(var7f1b59a4)
/*  f13cac4:	81490007 */ 	lb	$t1,0x7($t2)
/*  f13cac8:	814b0008 */ 	lb	$t3,0x8($t2)
/*  f13cacc:	814c0009 */ 	lb	$t4,0x9($t2)
/*  f13cad0:	44895000 */ 	mtc1	$t1,$f10
/*  f13cad4:	c42259a4 */ 	lwc1	$f2,%lo(var7f1b59a4)($at)
/*  f13cad8:	3c014020 */ 	lui	$at,0x4020
/*  f13cadc:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f13cae0:	448b5000 */ 	mtc1	$t3,$f10
/*  f13cae4:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f13cae8:	c7a600c8 */ 	lwc1	$f6,0xc8($sp)
/*  f13caec:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f13caf0:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f13caf4:	448c3000 */ 	mtc1	$t4,$f6
/*  f13caf8:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f13cafc:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f13cb00:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f13cb04:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f13cb08:	44815000 */ 	mtc1	$at,$f10
/*  f13cb0c:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f13cb10:	46002383 */ 	div.s	$f14,$f4,$f0
/*  f13cb14:	46007387 */ 	neg.s	$f14,$f14
/*  f13cb18:	460e103c */ 	c.lt.s	$f2,$f14
/*  f13cb1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cb20:	45000002 */ 	bc1f	.L0f13cb2c
/*  f13cb24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cb28:	46001386 */ 	mov.s	$f14,$f2
.L0f13cb2c:
/*  f13cb2c:	460a7382 */ 	mul.s	$f14,$f14,$f10
/*  f13cb30:	10000004 */ 	beqz	$zero,.L0f13cb44
/*  f13cb34:	460ec03c */ 	c.lt.s	$f24,$f14
.L0f13cb38:
/*  f13cb38:	e7b80190 */ 	swc1	$f24,0x190($sp)
.L0f13cb3c:
/*  f13cb3c:	c7ae0190 */ 	lwc1	$f14,0x190($sp)
/*  f13cb40:	460ec03c */ 	c.lt.s	$f24,$f14
.L0f13cb44:
/*  f13cb44:	27a300e8 */ 	addiu	$v1,$sp,0xe8
/*  f13cb48:	27a20104 */ 	addiu	$v0,$sp,0x104
/*  f13cb4c:	4502013f */ 	bc1fl	.L0f13d04c
/*  f13cb50:	8fab0090 */ 	lw	$t3,0x90($sp)
.L0f13cb54:
/*  f13cb54:	c7a800d0 */ 	lwc1	$f8,0xd0($sp)
/*  f13cb58:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f13cb5c:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f13cb60:	27ad0104 */ 	addiu	$t5,$sp,0x104
/*  f13cb64:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f13cb68:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f13cb6c:	27ae00f8 */ 	addiu	$t6,$sp,0xf8
/*  f13cb70:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f13cb74:	c7a800d8 */ 	lwc1	$f8,0xd8($sp)
/*  f13cb78:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f13cb7c:	c4440020 */ 	lwc1	$f4,0x20($v0)
/*  f13cb80:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f13cb84:	c4440030 */ 	lwc1	$f4,0x30($v0)
/*  f13cb88:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f13cb8c:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f13cb90:	144d0005 */ 	bne	$v0,$t5,.L0f13cba8
/*  f13cb94:	e46a0000 */ 	swc1	$f10,0x0($v1)
/*  f13cb98:	c4660000 */ 	lwc1	$f6,0x0($v1)
/*  f13cb9c:	4618303e */ 	c.le.s	$f6,$f24
/*  f13cba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cba4:	45010004 */ 	bc1t	.L0f13cbb8
.L0f13cba8:
/*  f13cba8:	2442fffc */ 	addiu	$v0,$v0,-4
/*  f13cbac:	004e082b */ 	sltu	$at,$v0,$t6
/*  f13cbb0:	1020ffe8 */ 	beqz	$at,.L0f13cb54
/*  f13cbb4:	2463fffc */ 	addiu	$v1,$v1,-4
.L0f13cbb8:
/*  f13cbb8:	3c017f1b */ 	lui	$at,%hi(var7f1b59a8)
/*  f13cbbc:	c42459a8 */ 	lwc1	$f4,%lo(var7f1b59a8)($at)
/*  f13cbc0:	c7a800e8 */ 	lwc1	$f8,0xe8($sp)
/*  f13cbc4:	e7ae0190 */ 	swc1	$f14,0x190($sp)
/*  f13cbc8:	4608203c */ 	c.lt.s	$f4,$f8
/*  f13cbcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cbd0:	4502011e */ 	bc1fl	.L0f13d04c
/*  f13cbd4:	8fab0090 */ 	lw	$t3,0x90($sp)
/*  f13cbd8:	4608d503 */ 	div.s	$f20,$f26,$f8
/*  f13cbdc:	3c013f00 */ 	lui	$at,0x3f00
/*  f13cbe0:	44813000 */ 	mtc1	$at,$f6
/*  f13cbe4:	c7aa01bc */ 	lwc1	$f10,0x1bc($sp)
/*  f13cbe8:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f13cbec:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f13cbf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cbf4:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f13cbf8:	461a5180 */ 	add.s	$f6,$f10,$f26
/*  f13cbfc:	c7aa01b8 */ 	lwc1	$f10,0x1b8($sp)
/*  f13cc00:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f13cc04:	44813000 */ 	mtc1	$at,$f6
/*  f13cc08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cc0c:	46065582 */ 	mul.s	$f22,$f10,$f6
/*  f13cc10:	0fc4f1c4 */ 	jal	func0f13c710
/*  f13cc14:	461e4300 */ 	add.s	$f12,$f8,$f30
/*  f13cc18:	c7a800e0 */ 	lwc1	$f8,0xe0($sp)
/*  f13cc1c:	44822000 */ 	mtc1	$v0,$f4
/*  f13cc20:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f13cc24:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f13cc28:	460ad181 */ 	sub.s	$f6,$f26,$f10
/*  f13cc2c:	e7b001a8 */ 	swc1	$f16,0x1a8($sp)
/*  f13cc30:	46163102 */ 	mul.s	$f4,$f6,$f22
/*  f13cc34:	0fc4f1c4 */ 	jal	func0f13c710
/*  f13cc38:	461c2300 */ 	add.s	$f12,$f4,$f28
/*  f13cc3c:	c7a800e4 */ 	lwc1	$f8,0xe4($sp)
/*  f13cc40:	3c017f1b */ 	lui	$at,%hi(var7f1b59ac)
/*  f13cc44:	c42259ac */ 	lwc1	$f2,%lo(var7f1b59ac)($at)
/*  f13cc48:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f13cc4c:	3c014200 */ 	lui	$at,0x4200
/*  f13cc50:	44814000 */ 	mtc1	$at,$f8
/*  f13cc54:	3c017f1b */ 	lui	$at,%hi(var7f1b59b0)
/*  f13cc58:	c7b001a8 */ 	lwc1	$f16,0x1a8($sp)
/*  f13cc5c:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f13cc60:	c42a59b0 */ 	lwc1	$f10,%lo(var7f1b59b0)($at)
/*  f13cc64:	3c014120 */ 	lui	$at,0x4120
/*  f13cc68:	46023100 */ 	add.s	$f4,$f6,$f2
/*  f13cc6c:	46082002 */ 	mul.s	$f0,$f4,$f8
/*  f13cc70:	460a003c */ 	c.lt.s	$f0,$f10
/*  f13cc74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cc78:	450200f4 */ 	bc1fl	.L0f13d04c
/*  f13cc7c:	8fab0090 */ 	lw	$t3,0x90($sp)
/*  f13cc80:	44813000 */ 	mtc1	$at,$f6
/*  f13cc84:	3c013f80 */ 	lui	$at,0x3f80
/*  f13cc88:	44812000 */ 	mtc1	$at,$f4
/*  f13cc8c:	461e3580 */ 	add.s	$f22,$f6,$f30
/*  f13cc90:	4600d306 */ 	mov.s	$f12,$f26
/*  f13cc94:	4604d081 */ 	sub.s	$f2,$f26,$f4
/*  f13cc98:	4616803e */ 	c.le.s	$f16,$f22
/*  f13cc9c:	46021380 */ 	add.s	$f14,$f2,$f2
/*  f13cca0:	460ed201 */ 	sub.s	$f8,$f26,$f14
/*  f13cca4:	e7ae0070 */ 	swc1	$f14,0x70($sp)
/*  f13cca8:	45000003 */ 	bc1f	.L0f13ccb8
/*  f13ccac:	e7a80178 */ 	swc1	$f8,0x178($sp)
/*  f13ccb0:	10000021 */ 	beqz	$zero,.L0f13cd38
/*  f13ccb4:	4600c306 */ 	mov.s	$f12,$f24
.L0f13ccb8:
/*  f13ccb8:	44825000 */ 	mtc1	$v0,$f10
/*  f13ccbc:	3c0141f0 */ 	lui	$at,0x41f0
/*  f13ccc0:	44813000 */ 	mtc1	$at,$f6
/*  f13ccc4:	468050a0 */ 	cvt.s.w	$f2,$f10
/*  f13ccc8:	3c01c120 */ 	lui	$at,0xc120
/*  f13cccc:	461c3100 */ 	add.s	$f4,$f6,$f28
/*  f13ccd0:	4604103e */ 	c.le.s	$f2,$f4
/*  f13ccd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ccd8:	45020004 */ 	bc1fl	.L0f13ccec
/*  f13ccdc:	44814000 */ 	mtc1	$at,$f8
/*  f13cce0:	10000015 */ 	beqz	$zero,.L0f13cd38
/*  f13cce4:	4600c306 */ 	mov.s	$f12,$f24
/*  f13cce8:	44814000 */ 	mtc1	$at,$f8
.L0f13ccec:
/*  f13ccec:	c7a601bc */ 	lwc1	$f6,0x1bc($sp)
/*  f13ccf0:	3c01c1f0 */ 	lui	$at,0xc1f0
/*  f13ccf4:	461e4280 */ 	add.s	$f10,$f8,$f30
/*  f13ccf8:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f13ccfc:	4610203e */ 	c.le.s	$f4,$f16
/*  f13cd00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cd04:	45020004 */ 	bc1fl	.L0f13cd18
/*  f13cd08:	44814000 */ 	mtc1	$at,$f8
/*  f13cd0c:	1000000a */ 	beqz	$zero,.L0f13cd38
/*  f13cd10:	4600c306 */ 	mov.s	$f12,$f24
/*  f13cd14:	44814000 */ 	mtc1	$at,$f8
.L0f13cd18:
/*  f13cd18:	c7a601b8 */ 	lwc1	$f6,0x1b8($sp)
/*  f13cd1c:	461c4280 */ 	add.s	$f10,$f8,$f28
/*  f13cd20:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f13cd24:	4602203e */ 	c.le.s	$f4,$f2
/*  f13cd28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cd2c:	45020003 */ 	bc1fl	.L0f13cd3c
/*  f13cd30:	46186032 */ 	c.eq.s	$f12,$f24
/*  f13cd34:	4600c306 */ 	mov.s	$f12,$f24
.L0f13cd38:
/*  f13cd38:	46186032 */ 	c.eq.s	$f12,$f24
.L0f13cd3c:
/*  f13cd3c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f13cd40:	c7a601bc */ 	lwc1	$f6,0x1bc($sp)
/*  f13cd44:	45010054 */ 	bc1t	.L0f13ce98
/*  f13cd48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cd4c:	44815000 */ 	mtc1	$at,$f10
/*  f13cd50:	4606f500 */ 	add.s	$f20,$f30,$f6
/*  f13cd54:	44824000 */ 	mtc1	$v0,$f8
/*  f13cd58:	3c0142b4 */ 	lui	$at,0x42b4
/*  f13cd5c:	44812000 */ 	mtc1	$at,$f4
/*  f13cd60:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f13cd64:	3c0142c8 */ 	lui	$at,0x42c8
/*  f13cd68:	44813000 */ 	mtc1	$at,$f6
/*  f13cd6c:	3c0142b4 */ 	lui	$at,0x42b4
/*  f13cd70:	4600d306 */ 	mov.s	$f12,$f26
/*  f13cd74:	4604a201 */ 	sub.s	$f8,$f20,$f4
/*  f13cd78:	460ae480 */ 	add.s	$f18,$f28,$f10
/*  f13cd7c:	c7aa01b8 */ 	lwc1	$f10,0x1b8($sp)
/*  f13cd80:	e7a8007c */ 	swc1	$f8,0x7c($sp)
/*  f13cd84:	44814000 */ 	mtc1	$at,$f8
/*  f13cd88:	460ae380 */ 	add.s	$f14,$f28,$f10
/*  f13cd8c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f13cd90:	4608f280 */ 	add.s	$f10,$f30,$f8
/*  f13cd94:	e7ae0078 */ 	swc1	$f14,0x78($sp)
/*  f13cd98:	46067101 */ 	sub.s	$f4,$f14,$f6
/*  f13cd9c:	460a803c */ 	c.lt.s	$f16,$f10
/*  f13cda0:	e7a40074 */ 	swc1	$f4,0x74($sp)
/*  f13cda4:	4502000b */ 	bc1fl	.L0f13cdd4
/*  f13cda8:	4612103c */ 	c.lt.s	$f2,$f18
/*  f13cdac:	46168181 */ 	sub.s	$f6,$f16,$f22
/*  f13cdb0:	44812000 */ 	mtc1	$at,$f4
/*  f13cdb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cdb8:	46043383 */ 	div.s	$f14,$f6,$f4
/*  f13cdbc:	461a703c */ 	c.lt.s	$f14,$f26
/*  f13cdc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cdc4:	45020003 */ 	bc1fl	.L0f13cdd4
/*  f13cdc8:	4612103c */ 	c.lt.s	$f2,$f18
/*  f13cdcc:	46007306 */ 	mov.s	$f12,$f14
/*  f13cdd0:	4612103c */ 	c.lt.s	$f2,$f18
.L0f13cdd4:
/*  f13cdd4:	3c0141f0 */ 	lui	$at,0x41f0
/*  f13cdd8:	4502000d */ 	bc1fl	.L0f13ce10
/*  f13cddc:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f13cde0:	44814000 */ 	mtc1	$at,$f8
/*  f13cde4:	3c01428c */ 	lui	$at,0x428c
/*  f13cde8:	44812000 */ 	mtc1	$at,$f4
/*  f13cdec:	4608e280 */ 	add.s	$f10,$f28,$f8
/*  f13cdf0:	460a1181 */ 	sub.s	$f6,$f2,$f10
/*  f13cdf4:	46043383 */ 	div.s	$f14,$f6,$f4
/*  f13cdf8:	460c703c */ 	c.lt.s	$f14,$f12
/*  f13cdfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ce00:	45020003 */ 	bc1fl	.L0f13ce10
/*  f13ce04:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f13ce08:	46007306 */ 	mov.s	$f12,$f14
/*  f13ce0c:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
.L0f13ce10:
/*  f13ce10:	3c014120 */ 	lui	$at,0x4120
/*  f13ce14:	4610403c */ 	c.lt.s	$f8,$f16
/*  f13ce18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ce1c:	4502000d */ 	bc1fl	.L0f13ce54
/*  f13ce20:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f13ce24:	44815000 */ 	mtc1	$at,$f10
/*  f13ce28:	3c0142a0 */ 	lui	$at,0x42a0
/*  f13ce2c:	44814000 */ 	mtc1	$at,$f8
/*  f13ce30:	460aa181 */ 	sub.s	$f6,$f20,$f10
/*  f13ce34:	46103101 */ 	sub.s	$f4,$f6,$f16
/*  f13ce38:	46082383 */ 	div.s	$f14,$f4,$f8
/*  f13ce3c:	460c703c */ 	c.lt.s	$f14,$f12
/*  f13ce40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ce44:	45020003 */ 	bc1fl	.L0f13ce54
/*  f13ce48:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f13ce4c:	46007306 */ 	mov.s	$f12,$f14
/*  f13ce50:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
.L0f13ce54:
/*  f13ce54:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*  f13ce58:	3c0141f0 */ 	lui	$at,0x41f0
/*  f13ce5c:	4602503c */ 	c.lt.s	$f10,$f2
/*  f13ce60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ce64:	4500000c */ 	bc1f	.L0f13ce98
/*  f13ce68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ce6c:	44812000 */ 	mtc1	$at,$f4
/*  f13ce70:	3c01428c */ 	lui	$at,0x428c
/*  f13ce74:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f13ce78:	44813000 */ 	mtc1	$at,$f6
/*  f13ce7c:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f13ce80:	46065383 */ 	div.s	$f14,$f10,$f6
/*  f13ce84:	460c703c */ 	c.lt.s	$f14,$f12
/*  f13ce88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ce8c:	45000002 */ 	bc1f	.L0f13ce98
/*  f13ce90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ce94:	46007306 */ 	mov.s	$f12,$f14
.L0f13ce98:
/*  f13ce98:	3c017f1b */ 	lui	$at,%hi(var7f1b59b4)
/*  f13ce9c:	c42e59b4 */ 	lwc1	$f14,%lo(var7f1b59b4)($at)
/*  f13cea0:	3c017f1b */ 	lui	$at,%hi(var7f1b59b8)
/*  f13cea4:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f13cea8:	4600703c */ 	c.lt.s	$f14,$f0
/*  f13ceac:	46007081 */ 	sub.s	$f2,$f14,$f0
/*  f13ceb0:	45000002 */ 	bc1f	.L0f13cebc
/*  f13ceb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ceb8:	4600c086 */ 	mov.s	$f2,$f24
.L0f13cebc:
/*  f13cebc:	c42459b8 */ 	lwc1	$f4,%lo(var7f1b59b8)($at)
/*  f13cec0:	3c017f1b */ 	lui	$at,%hi(var7f1b59bc)
/*  f13cec4:	4602203c */ 	c.lt.s	$f4,$f2
/*  f13cec8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cecc:	45000002 */ 	bc1f	.L0f13ced8
/*  f13ced0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ced4:	c42259bc */ 	lwc1	$f2,%lo(var7f1b59bc)($at)
.L0f13ced8:
/*  f13ced8:	3c017f1b */ 	lui	$at,%hi(var7f1b59c0)
/*  f13cedc:	460ad03c */ 	c.lt.s	$f26,$f10
/*  f13cee0:	c42859c0 */ 	lwc1	$f8,%lo(var7f1b59c0)($at)
/*  f13cee4:	3c01437f */ 	lui	$at,0x437f
/*  f13cee8:	44813000 */ 	mtc1	$at,$f6
/*  f13ceec:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f13cef0:	45000002 */ 	bc1f	.L0f13cefc
/*  f13cef4:	3c014f00 */ 	lui	$at,0x4f00
/*  f13cef8:	e7b80178 */ 	swc1	$f24,0x178($sp)
.L0f13cefc:
/*  f13cefc:	c7a00190 */ 	lwc1	$f0,0x190($sp)
/*  f13cf00:	c7a80178 */ 	lwc1	$f8,0x178($sp)
/*  f13cf04:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f13cf08:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f13cf0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cf10:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f13cf14:	444ff800 */ 	cfc1	$t7,$31
/*  f13cf18:	44d8f800 */ 	ctc1	$t8,$31
/*  f13cf1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cf20:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f13cf24:	4458f800 */ 	cfc1	$t8,$31
/*  f13cf28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cf2c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f13cf30:	13000012 */ 	beqz	$t8,.L0f13cf7c
/*  f13cf34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cf38:	44813000 */ 	mtc1	$at,$f6
/*  f13cf3c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f13cf40:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f13cf44:	44d8f800 */ 	ctc1	$t8,$31
/*  f13cf48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cf4c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f13cf50:	4458f800 */ 	cfc1	$t8,$31
/*  f13cf54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cf58:	33180078 */ 	andi	$t8,$t8,0x78
/*  f13cf5c:	17000005 */ 	bnez	$t8,.L0f13cf74
/*  f13cf60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cf64:	44183000 */ 	mfc1	$t8,$f6
/*  f13cf68:	3c018000 */ 	lui	$at,0x8000
/*  f13cf6c:	10000007 */ 	beqz	$zero,.L0f13cf8c
/*  f13cf70:	0301c025 */ 	or	$t8,$t8,$at
.L0f13cf74:
/*  f13cf74:	10000005 */ 	beqz	$zero,.L0f13cf8c
/*  f13cf78:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f13cf7c:
/*  f13cf7c:	44183000 */ 	mfc1	$t8,$f6
/*  f13cf80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cf84:	0700fffb */ 	bltz	$t8,.L0f13cf74
/*  f13cf88:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13cf8c:
/*  f13cf8c:	44cff800 */ 	ctc1	$t7,$31
/*  f13cf90:	3c014280 */ 	lui	$at,0x4280
/*  f13cf94:	44815000 */ 	mtc1	$at,$f10
/*  f13cf98:	46026102 */ 	mul.s	$f4,$f12,$f2
/*  f13cf9c:	3c013f80 */ 	lui	$at,0x3f80
/*  f13cfa0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f13cfa4:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f13cfa8:	a3380001 */ 	sb	$t8,0x1($t9)
/*  f13cfac:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f13cfb0:	44812000 */ 	mtc1	$at,$f4
/*  f13cfb4:	3c014f00 */ 	lui	$at,0x4f00
/*  f13cfb8:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f13cfbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cfc0:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f13cfc4:	4448f800 */ 	cfc1	$t0,$31
/*  f13cfc8:	44c9f800 */ 	ctc1	$t1,$31
/*  f13cfcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cfd0:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f13cfd4:	4449f800 */ 	cfc1	$t1,$31
/*  f13cfd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cfdc:	31290078 */ 	andi	$t1,$t1,0x78
/*  f13cfe0:	11200012 */ 	beqz	$t1,.L0f13d02c
/*  f13cfe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cfe8:	44815000 */ 	mtc1	$at,$f10
/*  f13cfec:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f13cff0:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f13cff4:	44c9f800 */ 	ctc1	$t1,$31
/*  f13cff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13cffc:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f13d000:	4449f800 */ 	cfc1	$t1,$31
/*  f13d004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d008:	31290078 */ 	andi	$t1,$t1,0x78
/*  f13d00c:	15200005 */ 	bnez	$t1,.L0f13d024
/*  f13d010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d014:	44095000 */ 	mfc1	$t1,$f10
/*  f13d018:	3c018000 */ 	lui	$at,0x8000
/*  f13d01c:	10000007 */ 	beqz	$zero,.L0f13d03c
/*  f13d020:	01214825 */ 	or	$t1,$t1,$at
.L0f13d024:
/*  f13d024:	10000005 */ 	beqz	$zero,.L0f13d03c
/*  f13d028:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f13d02c:
/*  f13d02c:	44095000 */ 	mfc1	$t1,$f10
/*  f13d030:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d034:	0520fffb */ 	bltz	$t1,.L0f13d024
/*  f13d038:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13d03c:
/*  f13d03c:	44c8f800 */ 	ctc1	$t0,$31
/*  f13d040:	a3290002 */ 	sb	$t1,0x2($t9)
/*  f13d044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d048:	8fab0090 */ 	lw	$t3,0x90($sp)
.L0f13d04c:
/*  f13d04c:	0000b825 */ 	or	$s7,$zero,$zero
/*  f13d050:	8fb100a0 */ 	lw	$s1,0xa0($sp)
/*  f13d054:	916a0001 */ 	lbu	$t2,0x1($t3)
/*  f13d058:	594000b8 */ 	blezl	$t2,.L0f13d33c
/*  f13d05c:	8fa801d4 */ 	lw	$t0,0x1d4($sp)
.L0f13d060:
/*  f13d060:	862c000a */ 	lh	$t4,0xa($s1)
/*  f13d064:	c7a800d0 */ 	lwc1	$f8,0xd0($sp)
/*  f13d068:	3c017f1b */ 	lui	$at,%hi(var7f1b59c4)
/*  f13d06c:	448c3000 */ 	mtc1	$t4,$f6
/*  f13d070:	c42059c4 */ 	lwc1	$f0,%lo(var7f1b59c4)($at)
/*  f13d074:	27a300e8 */ 	addiu	$v1,$sp,0xe8
/*  f13d078:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f13d07c:	27a20104 */ 	addiu	$v0,$sp,0x104
/*  f13d080:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f13d084:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f13d088:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f13d08c:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f13d090:	e7a400ec */ 	swc1	$f4,0xec($sp)
/*  f13d094:	862d000c */ 	lh	$t5,0xc($s1)
/*  f13d098:	448d5000 */ 	mtc1	$t5,$f10
/*  f13d09c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d0a0:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f13d0a4:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f13d0a8:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f13d0ac:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f13d0b0:	e7a200f0 */ 	swc1	$f2,0xf0($sp)
/*  f13d0b4:	862e000e */ 	lh	$t6,0xe($s1)
/*  f13d0b8:	448e3000 */ 	mtc1	$t6,$f6
/*  f13d0bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d0c0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f13d0c4:	c7a600d8 */ 	lwc1	$f6,0xd8($sp)
/*  f13d0c8:	46064201 */ 	sub.s	$f8,$f8,$f6
/*  f13d0cc:	46004202 */ 	mul.s	$f8,$f8,$f0
/*  f13d0d0:	46002006 */ 	mov.s	$f0,$f4
/*  f13d0d4:	46064300 */ 	add.s	$f12,$f8,$f6
/*  f13d0d8:	e7ac00f4 */ 	swc1	$f12,0xf4($sp)
.L0f13d0dc:
/*  f13d0dc:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f13d0e0:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f13d0e4:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f13d0e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d0ec:	460a1102 */ 	mul.s	$f4,$f2,$f10
/*  f13d0f0:	c44a0020 */ 	lwc1	$f10,0x20($v0)
/*  f13d0f4:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f13d0f8:	460a6202 */ 	mul.s	$f8,$f12,$f10
/*  f13d0fc:	c44a0030 */ 	lwc1	$f10,0x30($v0)
/*  f13d100:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f13d104:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f13d108:	14550005 */ 	bne	$v0,$s5,.L0f13d120
/*  f13d10c:	e4660000 */ 	swc1	$f6,0x0($v1)
/*  f13d110:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f13d114:	4618403e */ 	c.le.s	$f8,$f24
/*  f13d118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d11c:	45010004 */ 	bc1t	.L0f13d130
.L0f13d120:
/*  f13d120:	2442fffc */ 	addiu	$v0,$v0,-4
/*  f13d124:	0056082b */ 	sltu	$at,$v0,$s6
/*  f13d128:	1020ffec */ 	beqz	$at,.L0f13d0dc
/*  f13d12c:	2463fffc */ 	addiu	$v1,$v1,-4
.L0f13d130:
/*  f13d130:	c7aa00e8 */ 	lwc1	$f10,0xe8($sp)
/*  f13d134:	460ac03c */ 	c.lt.s	$f24,$f10
/*  f13d138:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d13c:	4502007b */ 	bc1fl	.L0f13d32c
/*  f13d140:	26f70006 */ 	addiu	$s7,$s7,0x6
/*  f13d144:	460ad503 */ 	div.s	$f20,$f26,$f10
/*  f13d148:	3c013f00 */ 	lui	$at,0x3f00
/*  f13d14c:	44813000 */ 	mtc1	$at,$f6
/*  f13d150:	c7a401bc */ 	lwc1	$f4,0x1bc($sp)
/*  f13d154:	44815000 */ 	mtc1	$at,$f10
/*  f13d158:	3c017f1b */ 	lui	$at,%hi(var7f1b59c8)
/*  f13d15c:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f13d160:	c42459c8 */ 	lwc1	$f4,%lo(var7f1b59c8)($at)
/*  f13d164:	c7a801b8 */ 	lwc1	$f8,0x1b8($sp)
/*  f13d168:	3c017f1b */ 	lui	$at,%hi(var7f1b59cc)
/*  f13d16c:	460a4582 */ 	mul.s	$f22,$f8,$f10
/*  f13d170:	4614203c */ 	c.lt.s	$f4,$f20
/*  f13d174:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f13d178:	45000002 */ 	bc1f	.L0f13d184
/*  f13d17c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d180:	c43459cc */ 	lwc1	$f20,%lo(var7f1b59cc)($at)
.L0f13d184:
/*  f13d184:	3c017f1b */ 	lui	$at,%hi(var7f1b59d0)
/*  f13d188:	c42659d0 */ 	lwc1	$f6,%lo(var7f1b59d0)($at)
/*  f13d18c:	3c017f1b */ 	lui	$at,%hi(var7f1b59d4)
/*  f13d190:	4606a03c */ 	c.lt.s	$f20,$f6
/*  f13d194:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d198:	45000002 */ 	bc1f	.L0f13d1a4
/*  f13d19c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d1a0:	c43459d4 */ 	lwc1	$f20,%lo(var7f1b59d4)($at)
.L0f13d1a4:
/*  f13d1a4:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f13d1a8:	461a5100 */ 	add.s	$f4,$f10,$f26
/*  f13d1ac:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f13d1b0:	0fc4f1c4 */ 	jal	func0f13c710
/*  f13d1b4:	461e3300 */ 	add.s	$f12,$f6,$f30
/*  f13d1b8:	c7a800e0 */ 	lwc1	$f8,0xe0($sp)
/*  f13d1bc:	00409025 */ 	or	$s2,$v0,$zero
/*  f13d1c0:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f13d1c4:	460ad101 */ 	sub.s	$f4,$f26,$f10
/*  f13d1c8:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f13d1cc:	0fc4f1c4 */ 	jal	func0f13c710
/*  f13d1d0:	461c3300 */ 	add.s	$f12,$f6,$f28
/*  f13d1d4:	c7a800e4 */ 	lwc1	$f8,0xe4($sp)
/*  f13d1d8:	3c017f1b */ 	lui	$at,%hi(var7f1b59d8)
/*  f13d1dc:	c42259d8 */ 	lwc1	$f2,%lo(var7f1b59d8)($at)
/*  f13d1e0:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f13d1e4:	3c014200 */ 	lui	$at,0x4200
/*  f13d1e8:	44814000 */ 	mtc1	$at,$f8
/*  f13d1ec:	8fcf0000 */ 	lw	$t7,0x0($s8)
/*  f13d1f0:	0040a025 */ 	or	$s4,$v0,$zero
/*  f13d1f4:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f13d1f8:	46022180 */ 	add.s	$f6,$f4,$f2
/*  f13d1fc:	46083002 */ 	mul.s	$f0,$f6,$f8
/*  f13d200:	11e00049 */ 	beqz	$t7,.L0f13d328
/*  f13d204:	46000586 */ 	mov.s	$f22,$f0
/*  f13d208:	4600f28d */ 	trunc.w.s	$f10,$f30
/*  f13d20c:	c7a401bc */ 	lwc1	$f4,0x1bc($sp)
/*  f13d210:	44085000 */ 	mfc1	$t0,$f10
/*  f13d214:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d218:	0248082a */ 	slt	$at,$s2,$t0
/*  f13d21c:	54200043 */ 	bnezl	$at,.L0f13d32c
/*  f13d220:	26f70006 */ 	addiu	$s7,$s7,0x6
/*  f13d224:	4604f180 */ 	add.s	$f6,$f30,$f4
/*  f13d228:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f13d22c:	44194000 */ 	mfc1	$t9,$f8
/*  f13d230:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d234:	0259082a */ 	slt	$at,$s2,$t9
/*  f13d238:	5020003c */ 	beqzl	$at,.L0f13d32c
/*  f13d23c:	26f70006 */ 	addiu	$s7,$s7,0x6
/*  f13d240:	4600e28d */ 	trunc.w.s	$f10,$f28
/*  f13d244:	c7a401b8 */ 	lwc1	$f4,0x1b8($sp)
/*  f13d248:	440a5000 */ 	mfc1	$t2,$f10
/*  f13d24c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d250:	004a082a */ 	slt	$at,$v0,$t2
/*  f13d254:	54200035 */ 	bnezl	$at,.L0f13d32c
/*  f13d258:	26f70006 */ 	addiu	$s7,$s7,0x6
/*  f13d25c:	4604e180 */ 	add.s	$f6,$f28,$f4
/*  f13d260:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f13d264:	440d4000 */ 	mfc1	$t5,$f8
/*  f13d268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d26c:	004d082a */ 	slt	$at,$v0,$t5
/*  f13d270:	1020002d */ 	beqz	$at,.L0f13d328
/*  f13d274:	3c017f1b */ 	lui	$at,%hi(var7f1b59dc)
/*  f13d278:	c42a59dc */ 	lwc1	$f10,%lo(var7f1b59dc)($at)
/*  f13d27c:	460a003c */ 	c.lt.s	$f0,$f10
/*  f13d280:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d284:	45020029 */ 	bc1fl	.L0f13d32c
/*  f13d288:	26f70006 */ 	addiu	$s7,$s7,0x6
/*  f13d28c:	0fc595f3 */ 	jal	func0f1657cc
/*  f13d290:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d294:	9044000b */ 	lbu	$a0,0xb($v0)
/*  f13d298:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f13d29c:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f13d2a0:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f13d2a4:	000e1880 */ 	sll	$v1,$t6,0x2
/*  f13d2a8:	006e1821 */ 	addu	$v1,$v1,$t6
/*  f13d2ac:	00031880 */ 	sll	$v1,$v1,0x2
/*  f13d2b0:	01e38021 */ 	addu	$s0,$t7,$v1
/*  f13d2b4:	96180000 */ 	lhu	$t8,0x0($s0)
/*  f13d2b8:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f13d2bc:	13000006 */ 	beqz	$t8,.L0f13d2d8
/*  f13d2c0:	01399821 */ 	addu	$s3,$t1,$t9
/*  f13d2c4:	96080014 */ 	lhu	$t0,0x14($s0)
.L0f13d2c8:
/*  f13d2c8:	24630014 */ 	addiu	$v1,$v1,0x14
/*  f13d2cc:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f13d2d0:	5500fffd */ 	bnezl	$t0,.L0f13d2c8
/*  f13d2d4:	96080014 */ 	lhu	$t0,0x14($s0)
.L0f13d2d8:
/*  f13d2d8:	28610960 */ 	slti	$at,$v1,0x960
/*  f13d2dc:	50200013 */ 	beqzl	$at,.L0f13d32c
/*  f13d2e0:	26f70006 */ 	addiu	$s7,$s7,0x6
/*  f13d2e4:	0fc4f15d */ 	jal	func0f13c574
/*  f13d2e8:	4600b306 */ 	mov.s	$f12,$f22
/*  f13d2ec:	00025883 */ 	sra	$t3,$v0,0x2
/*  f13d2f0:	0c002f02 */ 	jal	func0000bc08
/*  f13d2f4:	a60b0004 */ 	sh	$t3,0x4($s0)
/*  f13d2f8:	00540019 */ 	multu	$v0,$s4
/*  f13d2fc:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f13d300:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f13d304:	ae130010 */ 	sw	$s3,0x10($s0)
/*  f13d308:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f13d30c:	a612000e */ 	sh	$s2,0xe($s0)
/*  f13d310:	a614000c */ 	sh	$s4,0xc($s0)
/*  f13d314:	00005012 */ 	mflo	$t2
/*  f13d318:	01526021 */ 	addu	$t4,$t2,$s2
/*  f13d31c:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f13d320:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f13d324:	ae0f0008 */ 	sw	$t7,0x8($s0)
.L0f13d328:
/*  f13d328:	26f70006 */ 	addiu	$s7,$s7,0x6
.L0f13d32c:
/*  f13d32c:	24010018 */ 	addiu	$at,$zero,0x18
/*  f13d330:	16e1ff4b */ 	bne	$s7,$at,.L0f13d060
/*  f13d334:	26310006 */ 	addiu	$s1,$s1,0x6
/*  f13d338:	8fa801d4 */ 	lw	$t0,0x1d4($sp)
.L0f13d33c:
/*  f13d33c:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f13d340:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f13d344:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f13d348:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f13d34c:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f13d350:	8fa801c0 */ 	lw	$t0,0x1c0($sp)
/*  f13d354:	272b0022 */ 	addiu	$t3,$t9,0x22
/*  f13d358:	254c0003 */ 	addiu	$t4,$t2,0x3
/*  f13d35c:	25ae0022 */ 	addiu	$t6,$t5,0x22
/*  f13d360:	25f80022 */ 	addiu	$t8,$t7,0x22
/*  f13d364:	afb80088 */ 	sw	$t8,0x88($sp)
/*  f13d368:	afae008c */ 	sw	$t6,0x8c($sp)
/*  f13d36c:	afac0090 */ 	sw	$t4,0x90($sp)
/*  f13d370:	afab00a0 */ 	sw	$t3,0xa0($sp)
/*  f13d374:	1528fd67 */ 	bne	$t1,$t0,.L0f13c914
/*  f13d378:	afa901d4 */ 	sw	$t1,0x1d4($sp)
.L0f13d37c:
/*  f13d37c:	8fbf006c */ 	lw	$ra,0x6c($sp)
.L0f13d380:
/*  f13d380:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f13d384:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f13d388:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f13d38c:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f13d390:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f13d394:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f13d398:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f13d39c:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f13d3a0:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f13d3a4:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f13d3a8:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f13d3ac:	8fb5005c */ 	lw	$s5,0x5c($sp)
/*  f13d3b0:	8fb60060 */ 	lw	$s6,0x60($sp)
/*  f13d3b4:	8fb70064 */ 	lw	$s7,0x64($sp)
/*  f13d3b8:	8fbe0068 */ 	lw	$s8,0x68($sp)
/*  f13d3bc:	03e00008 */ 	jr	$ra
/*  f13d3c0:	27bd01d8 */ 	addiu	$sp,$sp,0x1d8
);

GLOBAL_ASM(
glabel func0f13d3c4
/*  f13d3c4:	308300ff */ 	andi	$v1,$a0,0xff
/*  f13d3c8:	30a200ff */ 	andi	$v0,$a1,0xff
/*  f13d3cc:	24660007 */ 	addiu	$a2,$v1,0x7
/*  f13d3d0:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f13d3d4:	0046082a */ 	slt	$at,$v0,$a2
/*  f13d3d8:	00402825 */ 	or	$a1,$v0,$zero
/*  f13d3dc:	14200003 */ 	bnez	$at,.L0f13d3ec
/*  f13d3e0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f13d3e4:	03e00008 */ 	jr	$ra
/*  f13d3e8:	30c200ff */ 	andi	$v0,$a2,0xff
.L0f13d3ec:
/*  f13d3ec:	2464fff9 */ 	addiu	$a0,$v1,-7
/*  f13d3f0:	0082082a */ 	slt	$at,$a0,$v0
/*  f13d3f4:	14200003 */ 	bnez	$at,.L0f13d404
/*  f13d3f8:	00a01025 */ 	or	$v0,$a1,$zero
/*  f13d3fc:	03e00008 */ 	jr	$ra
/*  f13d400:	308200ff */ 	andi	$v0,$a0,0xff
.L0f13d404:
/*  f13d404:	03e00008 */ 	jr	$ra
/*  f13d408:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13d40c
/*  f13d40c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f13d410:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f13d414:	0fc59570 */ 	jal	stageGetCurrent
/*  f13d418:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f13d41c:	904e0002 */ 	lbu	$t6,0x2($v0)
/*  f13d420:	3c18800b */ 	lui	$t8,%hi(var800ab5a0)
/*  f13d424:	8f18b5a0 */ 	lw	$t8,%lo(var800ab5a0)($t8)
/*  f13d428:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f13d42c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f13d430:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f13d434:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f13d438:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f13d43c:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f13d440:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f13d444:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f13d448:	27a40028 */ 	addiu	$a0,$sp,0x28
/*  f13d44c:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f13d450:	00003825 */ 	or	$a3,$zero,$zero
/*  f13d454:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f13d458:	01f82821 */ 	addu	$a1,$t7,$t8
/*  f13d45c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f13d460:	3c0bba00 */ 	lui	$t3,0xba00
/*  f13d464:	356b1402 */ 	ori	$t3,$t3,0x1402
/*  f13d468:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f13d46c:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f13d470:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f13d474:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f13d478:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f13d47c:	3c0eb900 */ 	lui	$t6,0xb900
/*  f13d480:	3c0f0050 */ 	lui	$t7,0x50
/*  f13d484:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f13d488:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f13d48c:	35ef4340 */ 	ori	$t7,$t7,0x4340
/*  f13d490:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f13d494:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f13d498:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f13d49c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*  f13d4a0:	3c08ba00 */ 	lui	$t0,0xba00
/*  f13d4a4:	35080c02 */ 	ori	$t0,$t0,0xc02
/*  f13d4a8:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f13d4ac:	afb90028 */ 	sw	$t9,0x28($sp)
/*  f13d4b0:	24092000 */ 	addiu	$t1,$zero,0x2000
/*  f13d4b4:	af090004 */ 	sw	$t1,0x4($t8)
/*  f13d4b8:	af080000 */ 	sw	$t0,0x0($t8)
/*  f13d4bc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f13d4c0:	3c0cfcff */ 	lui	$t4,0xfcff
/*  f13d4c4:	3c0dff36 */ 	lui	$t5,0xff36
/*  f13d4c8:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f13d4cc:	afab0028 */ 	sw	$t3,0x28($sp)
/*  f13d4d0:	35adff7f */ 	ori	$t5,$t5,0xff7f
/*  f13d4d4:	358c9bff */ 	ori	$t4,$t4,0x9bff
/*  f13d4d8:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f13d4dc:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f13d4e0:	8fae0028 */ 	lw	$t6,0x28($sp)
/*  f13d4e4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f13d4e8:	37180602 */ 	ori	$t8,$t8,0x602
/*  f13d4ec:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f13d4f0:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f13d4f4:	24190040 */ 	addiu	$t9,$zero,0x40
/*  f13d4f8:	add90004 */ 	sw	$t9,0x4($t6)
/*  f13d4fc:	add80000 */ 	sw	$t8,0x0($t6)
/*  f13d500:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f13d504:	3c0aba00 */ 	lui	$t2,0xba00
/*  f13d508:	354a0402 */ 	ori	$t2,$t2,0x402
/*  f13d50c:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f13d510:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f13d514:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f13d518:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f13d51c:	8fab0028 */ 	lw	$t3,0x28($sp)
/*  f13d520:	3c0dba00 */ 	lui	$t5,0xba00
/*  f13d524:	35ad1301 */ 	ori	$t5,$t5,0x1301
/*  f13d528:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f13d52c:	afac0028 */ 	sw	$t4,0x28($sp)
/*  f13d530:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f13d534:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f13d538:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f13d53c:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f13d540:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f13d544:	03e00008 */ 	jr	$ra
/*  f13d548:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13d54c
/*  f13d54c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f13d550:	35ce1301 */ 	ori	$t6,$t6,0x1301
/*  f13d554:	3c0f0008 */ 	lui	$t7,0x8
/*  f13d558:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f13d55c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f13d560:	03e00008 */ 	jr	$ra
/*  f13d564:	24820008 */ 	addiu	$v0,$a0,0x8
);

GLOBAL_ASM(
glabel func0f13d568
/*  f13d568:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f13d56c:	afbf0084 */ 	sw	$ra,0x84($sp)
/*  f13d570:	afbe0080 */ 	sw	$s8,0x80($sp)
/*  f13d574:	afb7007c */ 	sw	$s7,0x7c($sp)
/*  f13d578:	afb60078 */ 	sw	$s6,0x78($sp)
/*  f13d57c:	afb50074 */ 	sw	$s5,0x74($sp)
/*  f13d580:	afb40070 */ 	sw	$s4,0x70($sp)
/*  f13d584:	afb3006c */ 	sw	$s3,0x6c($sp)
/*  f13d588:	afb20068 */ 	sw	$s2,0x68($sp)
/*  f13d58c:	afb10064 */ 	sw	$s1,0x64($sp)
/*  f13d590:	afb00060 */ 	sw	$s0,0x60($sp)
/*  f13d594:	f7be0058 */ 	sdc1	$f30,0x58($sp)
/*  f13d598:	f7bc0050 */ 	sdc1	$f28,0x50($sp)
/*  f13d59c:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*  f13d5a0:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f13d5a4:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f13d5a8:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f13d5ac:	afa40160 */ 	sw	$a0,0x160($sp)
/*  f13d5b0:	0c000920 */ 	jal	func00002480
/*  f13d5b4:	afa50164 */ 	sw	$a1,0x164($sp)
/*  f13d5b8:	0040a025 */ 	or	$s4,$v0,$zero
/*  f13d5bc:	0fc00331 */ 	jal	func0f000cc4
/*  f13d5c0:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f13d5c4:	8fa30164 */ 	lw	$v1,0x164($sp)
/*  f13d5c8:	3c0f800a */ 	lui	$t7,%hi(g_Rooms)
/*  f13d5cc:	8def4928 */ 	lw	$t7,%lo(g_Rooms)($t7)
/*  f13d5d0:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f13d5d4:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f13d5d8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f13d5dc:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f13d5e0:	000e1880 */ 	sll	$v1,$t6,0x2
/*  f13d5e4:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f13d5e8:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f13d5ec:	46000786 */ 	mov.s	$f30,$f0
/*  f13d5f0:	13000004 */ 	beqz	$t8,.L0f13d604
/*  f13d5f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d5f8:	84590002 */ 	lh	$t9,0x2($v0)
/*  f13d5fc:	17200003 */ 	bnez	$t9,.L0f13d60c
/*  f13d600:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13d604:
/*  f13d604:	100002a2 */ 	beqz	$zero,.L0f13e090
/*  f13d608:	8fa20160 */ 	lw	$v0,0x160($sp)
.L0f13d60c:
/*  f13d60c:	0fc595f3 */ 	jal	func0f1657cc
/*  f13d610:	afa300a4 */ 	sw	$v1,0xa4($sp)
/*  f13d614:	9052000b */ 	lbu	$s2,0xb($v0)
/*  f13d618:	241e0002 */ 	addiu	$s8,$zero,0x2
/*  f13d61c:	001260c0 */ 	sll	$t4,$s2,0x3
/*  f13d620:	29810078 */ 	slti	$at,$t4,0x78
/*  f13d624:	10200299 */ 	beqz	$at,.L0f13e08c
/*  f13d628:	01809025 */ 	or	$s2,$t4,$zero
/*  f13d62c:	3c01437f */ 	lui	$at,0x437f
/*  f13d630:	4481e000 */ 	mtc1	$at,$f28
/*  f13d634:	24170014 */ 	addiu	$s7,$zero,0x14
.L0f13d638:
/*  f13d638:	02570019 */ 	multu	$s2,$s7
/*  f13d63c:	2a410078 */ 	slti	$at,$s2,0x78
/*  f13d640:	00008025 */ 	or	$s0,$zero,$zero
/*  f13d644:	02401825 */ 	or	$v1,$s2,$zero
/*  f13d648:	00006812 */ 	mflo	$t5
/*  f13d64c:	028d1021 */ 	addu	$v0,$s4,$t5
/*  f13d650:	8c450010 */ 	lw	$a1,0x10($v0)
/*  f13d654:	10200012 */ 	beqz	$at,.L0f13d6a0
/*  f13d658:	00a02025 */ 	or	$a0,$a1,$zero
/*  f13d65c:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f13d660:	17ce000f */ 	bne	$s8,$t6,.L0f13d6a0
/*  f13d664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d668:	1485000d */ 	bne	$a0,$a1,.L0f13d6a0
/*  f13d66c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f13d670:
/*  f13d670:	28610078 */ 	slti	$at,$v1,0x78
/*  f13d674:	1020000a */ 	beqz	$at,.L0f13d6a0
/*  f13d678:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f13d67c:	00770019 */ 	multu	$v1,$s7
/*  f13d680:	00007812 */ 	mflo	$t7
/*  f13d684:	028f1021 */ 	addu	$v0,$s4,$t7
/*  f13d688:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f13d68c:	17d80004 */ 	bne	$s8,$t8,.L0f13d6a0
/*  f13d690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d694:	8c590010 */ 	lw	$t9,0x10($v0)
/*  f13d698:	5099fff5 */ 	beql	$a0,$t9,.L0f13d670
/*  f13d69c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f13d6a0:
/*  f13d6a0:	5a000277 */ 	blezl	$s0,.L0f13e080
/*  f13d6a4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f13d6a8:	afa50140 */ 	sw	$a1,0x140($sp)
/*  f13d6ac:	94ad0000 */ 	lhu	$t5,0x0($a1)
/*  f13d6b0:	8fac0164 */ 	lw	$t4,0x164($sp)
/*  f13d6b4:	3c0f800a */ 	lui	$t7,%hi(var800a4cd8)
/*  f13d6b8:	24010022 */ 	addiu	$at,$zero,0x22
/*  f13d6bc:	158d026d */ 	bne	$t4,$t5,.L0f13e074
/*  f13d6c0:	00005025 */ 	or	$t2,$zero,$zero
/*  f13d6c4:	8def4cd8 */ 	lw	$t7,%lo(var800a4cd8)($t7)
/*  f13d6c8:	3c0c800a */ 	lui	$t4,%hi(var800a41a0)
/*  f13d6cc:	8d8c41a0 */ 	lw	$t4,%lo(var800a41a0)($t4)
/*  f13d6d0:	00af8823 */ 	subu	$s1,$a1,$t7
/*  f13d6d4:	0221001b */ 	divu	$zero,$s1,$at
/*  f13d6d8:	00008812 */ 	mflo	$s1
/*  f13d6dc:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f13d6e0:	02504821 */ 	addu	$t1,$s2,$s0
/*  f13d6e4:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f13d6e8:	0249082a */ 	slt	$at,$s2,$t1
/*  f13d6ec:	3406ffff */ 	dli	$a2,0xffff
/*  f13d6f0:	00004025 */ 	or	$t0,$zero,$zero
/*  f13d6f4:	02403825 */ 	or	$a3,$s2,$zero
/*  f13d6f8:	10200013 */ 	beqz	$at,.L0f13d748
/*  f13d6fc:	032c9821 */ 	addu	$s3,$t9,$t4
/*  f13d700:	00076880 */ 	sll	$t5,$a3,0x2
/*  f13d704:	01a76821 */ 	addu	$t5,$t5,$a3
/*  f13d708:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f13d70c:	028d1021 */ 	addu	$v0,$s4,$t5
.L0f13d710:
/*  f13d710:	94430004 */ 	lhu	$v1,0x4($v0)
/*  f13d714:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f13d718:	00c02825 */ 	or	$a1,$a2,$zero
/*  f13d71c:	0103082a */ 	slt	$at,$t0,$v1
/*  f13d720:	10200002 */ 	beqz	$at,.L0f13d72c
/*  f13d724:	00602025 */ 	or	$a0,$v1,$zero
/*  f13d728:	3068ffff */ 	andi	$t0,$v1,0xffff
.L0f13d72c:
/*  f13d72c:	0085082a */ 	slt	$at,$a0,$a1
/*  f13d730:	10200002 */ 	beqz	$at,.L0f13d73c
/*  f13d734:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d738:	3066ffff */ 	andi	$a2,$v1,0xffff
.L0f13d73c:
/*  f13d73c:	14e9fff4 */ 	bne	$a3,$t1,.L0f13d710
/*  f13d740:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f13d744:	02403825 */ 	or	$a3,$s2,$zero
.L0f13d748:
/*  f13d748:	01061023 */ 	subu	$v0,$t0,$a2
/*  f13d74c:	00025843 */ 	sra	$t3,$v0,0x1
/*  f13d750:	29610019 */ 	slti	$at,$t3,0x19
/*  f13d754:	10200002 */ 	beqz	$at,.L0f13d760
/*  f13d758:	00077880 */ 	sll	$t7,$a3,0x2
/*  f13d75c:	240b0019 */ 	addiu	$t3,$zero,0x19
.L0f13d760:
/*  f13d760:	0249082a */ 	slt	$at,$s2,$t1
/*  f13d764:	10200017 */ 	beqz	$at,.L0f13d7c4
/*  f13d768:	01e77821 */ 	addu	$t7,$t7,$a3
/*  f13d76c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f13d770:	028f1021 */ 	addu	$v0,$s4,$t7
.L0f13d774:
/*  f13d774:	94430002 */ 	lhu	$v1,0x2($v0)
/*  f13d778:	94440004 */ 	lhu	$a0,0x4($v0)
/*  f13d77c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f13d780:	3078fffc */ 	andi	$t8,$v1,0xfffc
/*  f13d784:	0018c883 */ 	sra	$t9,$t8,0x2
/*  f13d788:	332cffff */ 	andi	$t4,$t9,0xffff
/*  f13d78c:	008c082a */ 	slt	$at,$a0,$t4
/*  f13d790:	01803025 */ 	or	$a2,$t4,$zero
/*  f13d794:	10200003 */ 	beqz	$at,.L0f13d7a4
/*  f13d798:	00802825 */ 	or	$a1,$a0,$zero
/*  f13d79c:	10000002 */ 	beqz	$zero,.L0f13d7a8
/*  f13d7a0:	01841823 */ 	subu	$v1,$t4,$a0
.L0f13d7a4:
/*  f13d7a4:	00a61823 */ 	subu	$v1,$a1,$a2
.L0f13d7a8:
/*  f13d7a8:	0163082a */ 	slt	$at,$t3,$v1
/*  f13d7ac:	54200003 */ 	bnezl	$at,.L0f13d7bc
/*  f13d7b0:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f13d7b4:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f13d7b8:	24420014 */ 	addiu	$v0,$v0,0x14
.L0f13d7bc:
/*  f13d7bc:	14e9ffed */ 	bne	$a3,$t1,.L0f13d774
/*  f13d7c0:	a440ffec */ 	sh	$zero,-0x14($v0)
.L0f13d7c4:
/*  f13d7c4:	92640000 */ 	lbu	$a0,0x0($s3)
/*  f13d7c8:	000a1840 */ 	sll	$v1,$t2,0x1
/*  f13d7cc:	306500ff */ 	andi	$a1,$v1,0xff
/*  f13d7d0:	0fc4f4f1 */ 	jal	func0f13d3c4
/*  f13d7d4:	afa300a0 */ 	sw	$v1,0xa0($sp)
/*  f13d7d8:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f13d7dc:	a2620000 */ 	sb	$v0,0x0($s3)
/*  f13d7e0:	28610002 */ 	slti	$at,$v1,0x2
/*  f13d7e4:	54200222 */ 	bnezl	$at,.L0f13e070
/*  f13d7e8:	a2600001 */ 	sb	$zero,0x1($s3)
/*  f13d7ec:	0c002f9d */ 	jal	func0000be74
/*  f13d7f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d7f4:	3c017f1b */ 	lui	$at,%hi(var7f1b59e0)
/*  f13d7f8:	c42459e0 */ 	lwc1	$f4,%lo(var7f1b59e0)($at)
/*  f13d7fc:	46040302 */ 	mul.s	$f12,$f0,$f4
/*  f13d800:	0c0068f4 */ 	jal	cosf
/*  f13d804:	46006586 */ 	mov.s	$f22,$f12
/*  f13d808:	46000506 */ 	mov.s	$f20,$f0
/*  f13d80c:	0c0068f7 */ 	jal	sinf
/*  f13d810:	4600b306 */ 	mov.s	$f12,$f22
/*  f13d814:	4600a183 */ 	div.s	$f6,$f20,$f0
/*  f13d818:	3c0d800a */ 	lui	$t5,%hi(g_Rooms)
/*  f13d81c:	8dad4928 */ 	lw	$t5,%lo(g_Rooms)($t5)
/*  f13d820:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f13d824:	3c017f1b */ 	lui	$at,%hi(var7f1b59e4)
/*  f13d828:	c42859e4 */ 	lwc1	$f8,%lo(var7f1b59e4)($at)
/*  f13d82c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f13d830:	8df80014 */ 	lw	$t8,0x14($t7)
/*  f13d834:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f13d838:	87190010 */ 	lh	$t9,0x10($t8)
/*  f13d83c:	02392823 */ 	subu	$a1,$s1,$t9
/*  f13d840:	46083602 */ 	mul.s	$f24,$f6,$f8
/*  f13d844:	0fc003d4 */ 	jal	func0f000f50
/*  f13d848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d84c:	1040000f */ 	beqz	$v0,.L0f13d88c
/*  f13d850:	3c19800a */ 	lui	$t9,%hi(g_Rooms)
/*  f13d854:	3c0c800a */ 	lui	$t4,%hi(g_Rooms)
/*  f13d858:	8d8c4928 */ 	lw	$t4,%lo(g_Rooms)($t4)
/*  f13d85c:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f13d860:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f13d864:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f13d868:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*  f13d86c:	85f80010 */ 	lh	$t8,0x10($t7)
/*  f13d870:	0fc003ef */ 	jal	func0f000fbc
/*  f13d874:	02382823 */ 	subu	$a1,$s1,$t8
/*  f13d878:	10400200 */ 	beqz	$v0,.L0f13e07c
/*  f13d87c:	3c013f80 */ 	lui	$at,0x3f80
/*  f13d880:	4481b000 */ 	mtc1	$at,$f22
/*  f13d884:	1000000d */ 	beqz	$zero,.L0f13d8bc
/*  f13d888:	8fb80140 */ 	lw	$t8,0x140($sp)
.L0f13d88c:
/*  f13d88c:	8f394928 */ 	lw	$t9,%lo(g_Rooms)($t9)
/*  f13d890:	8fac00a4 */ 	lw	$t4,0xa4($sp)
/*  f13d894:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f13d898:	032c6821 */ 	addu	$t5,$t9,$t4
/*  f13d89c:	8dae0014 */ 	lw	$t6,0x14($t5)
/*  f13d8a0:	85cf0010 */ 	lh	$t7,0x10($t6)
/*  f13d8a4:	0fc00bbe */ 	jal	func0f002ef8
/*  f13d8a8:	022f2823 */ 	subu	$a1,$s1,$t7
/*  f13d8ac:	104001f3 */ 	beqz	$v0,.L0f13e07c
/*  f13d8b0:	3c017f1b */ 	lui	$at,%hi(var7f1b59e8)
/*  f13d8b4:	c43659e8 */ 	lwc1	$f22,%lo(var7f1b59e8)($at)
/*  f13d8b8:	8fb80140 */ 	lw	$t8,0x140($sp)
.L0f13d8bc:
/*  f13d8bc:	24030011 */ 	addiu	$v1,$zero,0x11
/*  f13d8c0:	240100ff */ 	addiu	$at,$zero,0xff
/*  f13d8c4:	97020002 */ 	lhu	$v0,0x2($t8)
/*  f13d8c8:	0002cb03 */ 	sra	$t9,$v0,0xc
/*  f13d8cc:	332c000f */ 	andi	$t4,$t9,0xf
/*  f13d8d0:	01830019 */ 	multu	$t4,$v1
/*  f13d8d4:	00026a03 */ 	sra	$t5,$v0,0x8
/*  f13d8d8:	31ae000f */ 	andi	$t6,$t5,0xf
/*  f13d8dc:	00027903 */ 	sra	$t7,$v0,0x4
/*  f13d8e0:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f13d8e4:	00008812 */ 	mflo	$s1
/*  f13d8e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d8ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d8f0:	01c30019 */ 	multu	$t6,$v1
/*  f13d8f4:	3c0e8007 */ 	lui	$t6,%hi(var80070764)
/*  f13d8f8:	0000a812 */ 	mflo	$s5
/*  f13d8fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d904:	03030019 */ 	multu	$t8,$v1
/*  f13d908:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f13d90c:	0000b012 */ 	mflo	$s6
/*  f13d910:	16210004 */ 	bne	$s1,$at,.L0f13d924
/*  f13d914:	240100ff */ 	addiu	$at,$zero,0xff
/*  f13d918:	16a10002 */ 	bne	$s5,$at,.L0f13d924
/*  f13d91c:	240100ff */ 	addiu	$at,$zero,0xff
/*  f13d920:	12c10006 */ 	beq	$s6,$at,.L0f13d93c
.L0f13d924:
/*  f13d924:	240100ff */ 	addiu	$at,$zero,0xff
/*  f13d928:	16210006 */ 	bne	$s1,$at,.L0f13d944
/*  f13d92c:	02b6c821 */ 	addu	$t9,$s5,$s6
/*  f13d930:	2b210023 */ 	slti	$at,$t9,0x23
/*  f13d934:	50200004 */ 	beqzl	$at,.L0f13d948
/*  f13d938:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f13d93c:
/*  f13d93c:	10000003 */ 	beqz	$zero,.L0f13d94c
/*  f13d940:	afa000cc */ 	sw	$zero,0xcc($sp)
.L0f13d944:
/*  f13d944:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f13d948:
/*  f13d948:	afac00cc */ 	sw	$t4,0xcc($sp)
.L0f13d94c:
/*  f13d94c:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f13d950:	8c6d00d8 */ 	lw	$t5,0xd8($v1)
/*  f13d954:	55a0001f */ 	bnezl	$t5,.L0f13d9d4
/*  f13d958:	926d0002 */ 	lbu	$t5,0x2($s3)
/*  f13d95c:	8dce0764 */ 	lw	$t6,%lo(var80070764)($t6)
/*  f13d960:	55c0001c */ 	bnezl	$t6,.L0f13d9d4
/*  f13d964:	926d0002 */ 	lbu	$t5,0x2($s3)
/*  f13d968:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f13d96c:	50400007 */ 	beqzl	$v0,.L0f13d98c
/*  f13d970:	8c791c54 */ 	lw	$t9,0x1c54($v1)
/*  f13d974:	50400017 */ 	beqzl	$v0,.L0f13d9d4
/*  f13d978:	926d0002 */ 	lbu	$t5,0x2($s3)
/*  f13d97c:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f13d980:	55e00014 */ 	bnezl	$t7,.L0f13d9d4
/*  f13d984:	926d0002 */ 	lbu	$t5,0x2($s3)
/*  f13d988:	8c791c54 */ 	lw	$t9,0x1c54($v1)
.L0f13d98c:
/*  f13d98c:	8c7800c4 */ 	lw	$t8,0xc4($v1)
/*  f13d990:	3c0140e0 */ 	lui	$at,0x40e0
/*  f13d994:	03206027 */ 	nor	$t4,$t9,$zero
/*  f13d998:	030c6824 */ 	and	$t5,$t8,$t4
/*  f13d99c:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f13d9a0:	51c0000c */ 	beqzl	$t6,.L0f13d9d4
/*  f13d9a4:	926d0002 */ 	lbu	$t5,0x2($s3)
/*  f13d9a8:	44815000 */ 	mtc1	$at,$f10
/*  f13d9ac:	926f0002 */ 	lbu	$t7,0x2($s3)
/*  f13d9b0:	460af402 */ 	mul.s	$f16,$f30,$f10
/*  f13d9b4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f13d9b8:	44189000 */ 	mfc1	$t8,$f18
/*  f13d9bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d9c0:	01f80019 */ 	multu	$t7,$t8
/*  f13d9c4:	00006012 */ 	mflo	$t4
/*  f13d9c8:	a26c0002 */ 	sb	$t4,0x2($s3)
/*  f13d9cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d9d0:	926d0002 */ 	lbu	$t5,0x2($s3)
.L0f13d9d4:
/*  f13d9d4:	44918000 */ 	mtc1	$s1,$f16
/*  f13d9d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f13d9dc:	448d2000 */ 	mtc1	$t5,$f4
/*  f13d9e0:	05a10004 */ 	bgez	$t5,.L0f13d9f4
/*  f13d9e4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13d9e8:	44814000 */ 	mtc1	$at,$f8
/*  f13d9ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13d9f0:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f13d9f4:
/*  f13d9f4:	3c017f1b */ 	lui	$at,%hi(var7f1b59ec)
/*  f13d9f8:	c42a59ec */ 	lwc1	$f10,%lo(var7f1b59ec)($at)
/*  f13d9fc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f13da00:	460a3002 */ 	mul.s	$f0,$f6,$f10
/*  f13da04:	44953000 */ 	mtc1	$s5,$f6
/*  f13da08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13da0c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13da10:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f13da14:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f13da18:	44962000 */ 	mtc1	$s6,$f4
/*  f13da1c:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f13da20:	44044000 */ 	mfc1	$a0,$f8
/*  f13da24:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f13da28:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f13da2c:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f13da30:	44059000 */ 	mfc1	$a1,$f18
/*  f13da34:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f13da38:	44065000 */ 	mfc1	$a2,$f10
/*  f13da3c:	0fc49ccd */ 	jal	func0f127334
/*  f13da40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13da44:	8fac0164 */ 	lw	$t4,0x164($sp)
/*  f13da48:	3c18800a */ 	lui	$t8,%hi(var800a4cc4)
/*  f13da4c:	8f184cc4 */ 	lw	$t8,%lo(var800a4cc4)($t8)
/*  f13da50:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f13da54:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f13da58:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f13da5c:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x284)
/*  f13da60:	8ce7a244 */ 	lw	$a3,%lo(g_Vars+0x284)($a3)
/*  f13da64:	27a300fc */ 	addiu	$v1,$sp,0xfc
/*  f13da68:	8fa20140 */ 	lw	$v0,0x140($sp)
/*  f13da6c:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f13da70:	27a500e4 */ 	addiu	$a1,$sp,0xe4
/*  f13da74:	27a800f0 */ 	addiu	$t0,$sp,0xf0
/*  f13da78:	030d3021 */ 	addu	$a2,$t8,$t5
.L0f13da7c:
/*  f13da7c:	844e001c */ 	lh	$t6,0x1c($v0)
/*  f13da80:	8459000a */ 	lh	$t9,0xa($v0)
/*  f13da84:	844c0010 */ 	lh	$t4,0x10($v0)
/*  f13da88:	844d0016 */ 	lh	$t5,0x16($v0)
/*  f13da8c:	01d97821 */ 	addu	$t7,$t6,$t9
/*  f13da90:	01ecc021 */ 	addu	$t8,$t7,$t4
/*  f13da94:	030d7021 */ 	addu	$t6,$t8,$t5
/*  f13da98:	05c10003 */ 	bgez	$t6,.L0f13daa8
/*  f13da9c:	000ec883 */ 	sra	$t9,$t6,0x2
/*  f13daa0:	25c10003 */ 	addiu	$at,$t6,0x3
/*  f13daa4:	0001c883 */ 	sra	$t9,$at,0x2
.L0f13daa8:
/*  f13daa8:	a4790000 */ 	sh	$t9,0x0($v1)
/*  f13daac:	846f0000 */ 	lh	$t7,0x0($v1)
/*  f13dab0:	c4d00004 */ 	lwc1	$f16,0x4($a2)
/*  f13dab4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f13dab8:	448f9000 */ 	mtc1	$t7,$f18
/*  f13dabc:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f13dac0:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f13dac4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f13dac8:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f13dacc:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f13dad0:	24e70004 */ 	addiu	$a3,$a3,4
/*  f13dad4:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f13dad8:	e488fffc */ 	swc1	$f8,-0x4($a0)
/*  f13dadc:	c4ea1bac */ 	lwc1	$f10,0x1bac($a3)
/*  f13dae0:	c486fffc */ 	lwc1	$f6,-0x4($a0)
/*  f13dae4:	460a3481 */ 	sub.s	$f18,$f6,$f10
/*  f13dae8:	14a8ffe4 */ 	bne	$a1,$t0,.L0f13da7c
/*  f13daec:	e4b2fffc */ 	swc1	$f18,-0x4($a1)
/*  f13daf0:	0fc2d5be */ 	jal	currentPlayerGetUnk1740
/*  f13daf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13daf8:	00402025 */ 	or	$a0,$v0,$zero
/*  f13dafc:	0c0056c4 */ 	jal	func00015b10
/*  f13db00:	27a500e4 */ 	addiu	$a1,$sp,0xe4
/*  f13db04:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f13db08:	0fc2d341 */ 	jal	func0f0b4d04
/*  f13db0c:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f13db10:	c7a000ec */ 	lwc1	$f0,0xec($sp)
/*  f13db14:	3c013f80 */ 	lui	$at,0x3f80
/*  f13db18:	44818000 */ 	mtc1	$at,$f16
/*  f13db1c:	46000007 */ 	neg.s	$f0,$f0
/*  f13db20:	3c013f80 */ 	lui	$at,0x3f80
/*  f13db24:	4610003c */ 	c.lt.s	$f0,$f16
/*  f13db28:	3c0e8007 */ 	lui	$t6,%hi(var80070764)
/*  f13db2c:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f13db30:	45020005 */ 	bc1fl	.L0f13db48
/*  f13db34:	46000506 */ 	mov.s	$f20,$f0
/*  f13db38:	4481a000 */ 	mtc1	$at,$f20
/*  f13db3c:	10000002 */ 	beqz	$zero,.L0f13db48
/*  f13db40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13db44:	46000506 */ 	mov.s	$f20,$f0
.L0f13db48:
/*  f13db48:	3c017f1b */ 	lui	$at,%hi(var7f1b59f0)
/*  f13db4c:	c42459f0 */ 	lwc1	$f4,%lo(var7f1b59f0)($at)
/*  f13db50:	8fac0140 */ 	lw	$t4,0x140($sp)
/*  f13db54:	46142203 */ 	div.s	$f8,$f4,$f20
/*  f13db58:	91820006 */ 	lbu	$v0,0x6($t4)
/*  f13db5c:	4608b582 */ 	mul.s	$f22,$f22,$f8
/*  f13db60:	50400010 */ 	beqzl	$v0,.L0f13dba4
/*  f13db64:	92780001 */ 	lbu	$t8,0x1($s3)
/*  f13db68:	44823000 */ 	mtc1	$v0,$f6
/*  f13db6c:	3c014f80 */ 	lui	$at,0x4f80
/*  f13db70:	04410004 */ 	bgez	$v0,.L0f13db84
/*  f13db74:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13db78:	44819000 */ 	mtc1	$at,$f18
/*  f13db7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13db80:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f13db84:
/*  f13db84:	3c013d00 */ 	lui	$at,0x3d00
/*  f13db88:	44818000 */ 	mtc1	$at,$f16
/*  f13db8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13db90:	46105102 */ 	mul.s	$f4,$f10,$f16
/*  f13db94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13db98:	4604b582 */ 	mul.s	$f22,$f22,$f4
/*  f13db9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dba0:	92780001 */ 	lbu	$t8,0x1($s3)
.L0f13dba4:
/*  f13dba4:	3c014f80 */ 	lui	$at,0x4f80
/*  f13dba8:	44984000 */ 	mtc1	$t8,$f8
/*  f13dbac:	07010004 */ 	bgez	$t8,.L0f13dbc0
/*  f13dbb0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f13dbb4:	44819000 */ 	mtc1	$at,$f18
/*  f13dbb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dbbc:	46123180 */ 	add.s	$f6,$f6,$f18
.L0f13dbc0:
/*  f13dbc0:	3c017f1b */ 	lui	$at,%hi(var7f1b59f4)
/*  f13dbc4:	c42a59f4 */ 	lwc1	$f10,%lo(var7f1b59f4)($at)
/*  f13dbc8:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f13dbcc:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f13dbd0:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f13dbd4:	8c6d00d8 */ 	lw	$t5,0xd8($v1)
/*  f13dbd8:	4610b582 */ 	mul.s	$f22,$f22,$f16
/*  f13dbdc:	15a0001a */ 	bnez	$t5,.L0f13dc48
/*  f13dbe0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dbe4:	8dce0764 */ 	lw	$t6,%lo(var80070764)($t6)
/*  f13dbe8:	15c00017 */ 	bnez	$t6,.L0f13dc48
/*  f13dbec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dbf0:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f13dbf4:	50400007 */ 	beqzl	$v0,.L0f13dc14
/*  f13dbf8:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
/*  f13dbfc:	10400012 */ 	beqz	$v0,.L0f13dc48
/*  f13dc00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dc04:	80590037 */ 	lb	$t9,0x37($v0)
/*  f13dc08:	1720000f */ 	bnez	$t9,.L0f13dc48
/*  f13dc0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dc10:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
.L0f13dc14:
/*  f13dc14:	8c6f00c4 */ 	lw	$t7,0xc4($v1)
/*  f13dc18:	3c014160 */ 	lui	$at,0x4160
/*  f13dc1c:	0180c027 */ 	nor	$t8,$t4,$zero
/*  f13dc20:	01f86824 */ 	and	$t5,$t7,$t8
/*  f13dc24:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f13dc28:	11c00007 */ 	beqz	$t6,.L0f13dc48
/*  f13dc2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dc30:	44812000 */ 	mtc1	$at,$f4
/*  f13dc34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dc38:	461e2202 */ 	mul.s	$f8,$f4,$f30
/*  f13dc3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dc40:	4608b582 */ 	mul.s	$f22,$f22,$f8
/*  f13dc44:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13dc48:
/*  f13dc48:	0fc0036f */ 	jal	func0f000dbc
/*  f13dc4c:	4618b580 */ 	add.s	$f22,$f22,$f24
/*  f13dc50:	46000480 */ 	add.s	$f18,$f0,$f0
/*  f13dc54:	3c017f1b */ 	lui	$at,%hi(var7f1b59f8)
/*  f13dc58:	c42259f8 */ 	lwc1	$f2,%lo(var7f1b59f8)($at)
/*  f13dc5c:	4612b582 */ 	mul.s	$f22,$f22,$f18
/*  f13dc60:	4616103c */ 	c.lt.s	$f2,$f22
/*  f13dc64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dc68:	45000002 */ 	bc1f	.L0f13dc74
/*  f13dc6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dc70:	46001586 */ 	mov.s	$f22,$f2
.L0f13dc74:
/*  f13dc74:	0fc59570 */ 	jal	stageGetCurrent
/*  f13dc78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dc7c:	90590004 */ 	lbu	$t9,0x4($v0)
/*  f13dc80:	3c014f80 */ 	lui	$at,0x4f80
/*  f13dc84:	44993000 */ 	mtc1	$t9,$f6
/*  f13dc88:	07210004 */ 	bgez	$t9,.L0f13dc9c
/*  f13dc8c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13dc90:	44818000 */ 	mtc1	$at,$f16
/*  f13dc94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dc98:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f13dc9c:
/*  f13dc9c:	46165102 */ 	mul.s	$f4,$f10,$f22
/*  f13dca0:	3c017f1b */ 	lui	$at,%hi(var7f1b59fc)
/*  f13dca4:	c42859fc */ 	lwc1	$f8,%lo(var7f1b59fc)($at)
/*  f13dca8:	46082602 */ 	mul.s	$f24,$f4,$f8
/*  f13dcac:	0fc59570 */ 	jal	stageGetCurrent
/*  f13dcb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dcb4:	904c0005 */ 	lbu	$t4,0x5($v0)
/*  f13dcb8:	3c014f80 */ 	lui	$at,0x4f80
/*  f13dcbc:	448c9000 */ 	mtc1	$t4,$f18
/*  f13dcc0:	05810004 */ 	bgez	$t4,.L0f13dcd4
/*  f13dcc4:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f13dcc8:	44818000 */ 	mtc1	$at,$f16
/*  f13dccc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dcd0:	46103180 */ 	add.s	$f6,$f6,$f16
.L0f13dcd4:
/*  f13dcd4:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f13dcd8:	3c017f1b */ 	lui	$at,%hi(var7f1b5a00)
/*  f13dcdc:	c4245a00 */ 	lwc1	$f4,%lo(var7f1b5a00)($at)
/*  f13dce0:	46045682 */ 	mul.s	$f26,$f10,$f4
/*  f13dce4:	0fc2d60a */ 	jal	currentPlayerGetPerspAspect
/*  f13dce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dcec:	0c002f22 */ 	jal	func0000bc88
/*  f13dcf0:	46000506 */ 	mov.s	$f20,$f0
/*  f13dcf4:	44824000 */ 	mtc1	$v0,$f8
/*  f13dcf8:	3c017f1b */ 	lui	$at,%hi(var7f1b5a04)
/*  f13dcfc:	c4305a04 */ 	lwc1	$f16,%lo(var7f1b5a04)($at)
/*  f13dd00:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f13dd04:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f13dd08:	46143283 */ 	div.s	$f10,$f6,$f20
/*  f13dd0c:	460ac602 */ 	mul.s	$f24,$f24,$f10
/*  f13dd10:	0c002f26 */ 	jal	func0000bc98
/*  f13dd14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dd18:	44822000 */ 	mtc1	$v0,$f4
/*  f13dd1c:	3c017f1b */ 	lui	$at,%hi(var7f1b5a08)
/*  f13dd20:	c4325a08 */ 	lwc1	$f18,%lo(var7f1b5a08)($at)
/*  f13dd24:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f13dd28:	3c014040 */ 	lui	$at,0x4040
/*  f13dd2c:	44813000 */ 	mtc1	$at,$f6
/*  f13dd30:	8faf0140 */ 	lw	$t7,0x140($sp)
/*  f13dd34:	4616303c */ 	c.lt.s	$f6,$f22
/*  f13dd38:	46124402 */ 	mul.s	$f16,$f8,$f18
/*  f13dd3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dd40:	4610d682 */ 	mul.s	$f26,$f26,$f16
/*  f13dd44:	450000c9 */ 	bc1f	.L0f13e06c
/*  f13dd48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dd4c:	95f80002 */ 	lhu	$t8,0x2($t7)
/*  f13dd50:	a3b10104 */ 	sb	$s1,0x104($sp)
/*  f13dd54:	a3b50105 */ 	sb	$s5,0x105($sp)
/*  f13dd58:	330d000f */ 	andi	$t5,$t8,0xf
/*  f13dd5c:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f13dd60:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f13dd64:	448e5000 */ 	mtc1	$t6,$f10
/*  f13dd68:	a3b60106 */ 	sb	$s6,0x106($sp)
/*  f13dd6c:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f13dd70:	0fc59570 */ 	jal	stageGetCurrent
/*  f13dd74:	e7a000bc */ 	swc1	$f0,0xbc($sp)
/*  f13dd78:	90590003 */ 	lbu	$t9,0x3($v0)
/*  f13dd7c:	c7a000bc */ 	lwc1	$f0,0xbc($sp)
/*  f13dd80:	27a40160 */ 	addiu	$a0,$sp,0x160
/*  f13dd84:	44992000 */ 	mtc1	$t9,$f4
/*  f13dd88:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f13dd8c:	07210005 */ 	bgez	$t9,.L0f13dda4
/*  f13dd90:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f13dd94:	3c014f80 */ 	lui	$at,0x4f80
/*  f13dd98:	44819000 */ 	mtc1	$at,$f18
/*  f13dd9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dda0:	46124200 */ 	add.s	$f8,$f8,$f18
.L0f13dda4:
/*  f13dda4:	461c4403 */ 	div.s	$f16,$f8,$f28
/*  f13dda8:	926c0001 */ 	lbu	$t4,0x1($s3)
/*  f13ddac:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ddb0:	3c0d8007 */ 	lui	$t5,%hi(var80070764)
/*  f13ddb4:	448c3000 */ 	mtc1	$t4,$f6
/*  f13ddb8:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f13ddbc:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f13ddc0:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13ddc4:	46100002 */ 	mul.s	$f0,$f0,$f16
/*  f13ddc8:	05830005 */ 	bgezl	$t4,.L0f13dde0
/*  f13ddcc:	461c5483 */ 	div.s	$f18,$f10,$f28
/*  f13ddd0:	44812000 */ 	mtc1	$at,$f4
/*  f13ddd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ddd8:	46045280 */ 	add.s	$f10,$f10,$f4
/*  f13dddc:	461c5483 */ 	div.s	$f18,$f10,$f28
.L0f13dde0:
/*  f13dde0:	926f0000 */ 	lbu	$t7,0x0($s3)
/*  f13dde4:	3c014f80 */ 	lui	$at,0x4f80
/*  f13dde8:	448f4000 */ 	mtc1	$t7,$f8
/*  f13ddec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ddf0:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f13ddf4:	46120002 */ 	mul.s	$f0,$f0,$f18
/*  f13ddf8:	05e30005 */ 	bgezl	$t7,.L0f13de10
/*  f13ddfc:	3c013e00 */ 	lui	$at,0x3e00
/*  f13de00:	44813000 */ 	mtc1	$at,$f6
/*  f13de04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13de08:	46068400 */ 	add.s	$f16,$f16,$f6
/*  f13de0c:	3c013e00 */ 	lui	$at,0x3e00
.L0f13de10:
/*  f13de10:	44812000 */ 	mtc1	$at,$f4
/*  f13de14:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f13de18:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f13de1c:	46048282 */ 	mul.s	$f10,$f16,$f4
/*  f13de20:	8c7800d8 */ 	lw	$t8,0xd8($v1)
/*  f13de24:	460a0002 */ 	mul.s	$f0,$f0,$f10
/*  f13de28:	5700001b */ 	bnezl	$t8,.L0f13de98
/*  f13de2c:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f13de30:	8dad0764 */ 	lw	$t5,%lo(var80070764)($t5)
/*  f13de34:	55a00018 */ 	bnezl	$t5,.L0f13de98
/*  f13de38:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f13de3c:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f13de40:	50400007 */ 	beqzl	$v0,.L0f13de60
/*  f13de44:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
/*  f13de48:	50400013 */ 	beqzl	$v0,.L0f13de98
/*  f13de4c:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f13de50:	804e0037 */ 	lb	$t6,0x37($v0)
/*  f13de54:	55c00010 */ 	bnezl	$t6,.L0f13de98
/*  f13de58:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f13de5c:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
.L0f13de60:
/*  f13de60:	8c7900c4 */ 	lw	$t9,0xc4($v1)
/*  f13de64:	3c0140e0 */ 	lui	$at,0x40e0
/*  f13de68:	01807827 */ 	nor	$t7,$t4,$zero
/*  f13de6c:	032fc024 */ 	and	$t8,$t9,$t7
/*  f13de70:	330d0001 */ 	andi	$t5,$t8,0x1
/*  f13de74:	51a00008 */ 	beqzl	$t5,.L0f13de98
/*  f13de78:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f13de7c:	44819000 */ 	mtc1	$at,$f18
/*  f13de80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13de84:	4612f202 */ 	mul.s	$f8,$f30,$f18
/*  f13de88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13de8c:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f13de90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13de94:	4600e03c */ 	c.lt.s	$f28,$f0
.L0f13de98:
/*  f13de98:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f13de9c:	3c014f00 */ 	lui	$at,0x4f00
/*  f13dea0:	3c18fb00 */ 	lui	$t8,0xfb00
/*  f13dea4:	45020003 */ 	bc1fl	.L0f13deb4
/*  f13dea8:	444ef800 */ 	cfc1	$t6,$31
/*  f13deac:	4600e006 */ 	mov.s	$f0,$f28
/*  f13deb0:	444ef800 */ 	cfc1	$t6,$31
.L0f13deb4:
/*  f13deb4:	44ccf800 */ 	ctc1	$t4,$31
/*  f13deb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13debc:	460001a4 */ 	cvt.w.s	$f6,$f0
/*  f13dec0:	444cf800 */ 	cfc1	$t4,$31
/*  f13dec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dec8:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f13decc:	51800013 */ 	beqzl	$t4,.L0f13df1c
/*  f13ded0:	440c3000 */ 	mfc1	$t4,$f6
/*  f13ded4:	44813000 */ 	mtc1	$at,$f6
/*  f13ded8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f13dedc:	46060181 */ 	sub.s	$f6,$f0,$f6
/*  f13dee0:	44ccf800 */ 	ctc1	$t4,$31
/*  f13dee4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13dee8:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f13deec:	444cf800 */ 	cfc1	$t4,$31
/*  f13def0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13def4:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f13def8:	15800005 */ 	bnez	$t4,.L0f13df10
/*  f13defc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13df00:	440c3000 */ 	mfc1	$t4,$f6
/*  f13df04:	3c018000 */ 	lui	$at,0x8000
/*  f13df08:	10000007 */ 	beqz	$zero,.L0f13df28
/*  f13df0c:	01816025 */ 	or	$t4,$t4,$at
.L0f13df10:
/*  f13df10:	10000005 */ 	beqz	$zero,.L0f13df28
/*  f13df14:	240cffff */ 	addiu	$t4,$zero,-1
/*  f13df18:	440c3000 */ 	mfc1	$t4,$f6
.L0f13df1c:
/*  f13df1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13df20:	0580fffb */ 	bltz	$t4,.L0f13df10
/*  f13df24:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13df28:
/*  f13df28:	8fa20160 */ 	lw	$v0,0x160($sp)
/*  f13df2c:	a3ac0107 */ 	sb	$t4,0x107($sp)
/*  f13df30:	44cef800 */ 	ctc1	$t6,$31
/*  f13df34:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f13df38:	afaf0160 */ 	sw	$t7,0x160($sp)
/*  f13df3c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f13df40:	93b90104 */ 	lbu	$t9,0x104($sp)
/*  f13df44:	93ac0105 */ 	lbu	$t4,0x105($sp)
/*  f13df48:	93ae0107 */ 	lbu	$t6,0x107($sp)
/*  f13df4c:	93ad0106 */ 	lbu	$t5,0x106($sp)
/*  f13df50:	00197e00 */ 	sll	$t7,$t9,0x18
/*  f13df54:	000ccc00 */ 	sll	$t9,$t4,0x10
/*  f13df58:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f13df5c:	03197025 */ 	or	$t6,$t8,$t9
/*  f13df60:	000d6200 */ 	sll	$t4,$t5,0x8
/*  f13df64:	01ccc025 */ 	or	$t8,$t6,$t4
/*  f13df68:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f13df6c:	24190040 */ 	addiu	$t9,$zero,0x40
/*  f13df70:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f13df74:	e7b800d4 */ 	swc1	$f24,0xd4($sp)
/*  f13df78:	e7ba00d8 */ 	swc1	$f26,0xd8($sp)
/*  f13df7c:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f13df80:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f13df84:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f13df88:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f13df8c:	0fc2c9d0 */ 	jal	func0f0b2740
/*  f13df90:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13df94:	8fad00cc */ 	lw	$t5,0xcc($sp)
/*  f13df98:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f13df9c:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f13dfa0:	11a00032 */ 	beqz	$t5,.L0f13e06c
/*  f13dfa4:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f13dfa8:	a3ae0104 */ 	sb	$t6,0x104($sp)
/*  f13dfac:	a3ac0105 */ 	sb	$t4,0x105($sp)
/*  f13dfb0:	0fc59570 */ 	jal	stageGetCurrent
/*  f13dfb4:	a3b80106 */ 	sb	$t8,0x106($sp)
/*  f13dfb8:	90590003 */ 	lbu	$t9,0x3($v0)
/*  f13dfbc:	3c017f1b */ 	lui	$at,%hi(var7f1b5a0c)
/*  f13dfc0:	c4205a0c */ 	lwc1	$f0,%lo(var7f1b5a0c)($at)
/*  f13dfc4:	a3b90107 */ 	sb	$t9,0x107($sp)
/*  f13dfc8:	926d0000 */ 	lbu	$t5,0x0($s3)
/*  f13dfcc:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f13dfd0:	8fa30160 */ 	lw	$v1,0x160($sp)
/*  f13dfd4:	01ed0019 */ 	multu	$t7,$t5
/*  f13dfd8:	3c0ffb00 */ 	lui	$t7,0xfb00
/*  f13dfdc:	24790008 */ 	addiu	$t9,$v1,0x8
/*  f13dfe0:	afb90160 */ 	sw	$t9,0x160($sp)
/*  f13dfe4:	4600c402 */ 	mul.s	$f16,$f24,$f0
/*  f13dfe8:	27a40160 */ 	addiu	$a0,$sp,0x160
/*  f13dfec:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f13dff0:	4600d102 */ 	mul.s	$f4,$f26,$f0
/*  f13dff4:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f13dff8:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f13dffc:	00007012 */ 	mflo	$t6
/*  f13e000:	05c10003 */ 	bgez	$t6,.L0f13e010
/*  f13e004:	000e60c3 */ 	sra	$t4,$t6,0x3
/*  f13e008:	25c10007 */ 	addiu	$at,$t6,0x7
/*  f13e00c:	000160c3 */ 	sra	$t4,$at,0x3
.L0f13e010:
/*  f13e010:	a3ac0107 */ 	sb	$t4,0x107($sp)
/*  f13e014:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f13e018:	93b80104 */ 	lbu	$t8,0x104($sp)
/*  f13e01c:	93ac0105 */ 	lbu	$t4,0x105($sp)
/*  f13e020:	93ae0107 */ 	lbu	$t6,0x107($sp)
/*  f13e024:	93ad0106 */ 	lbu	$t5,0x106($sp)
/*  f13e028:	0018ce00 */ 	sll	$t9,$t8,0x18
/*  f13e02c:	000cc400 */ 	sll	$t8,$t4,0x10
/*  f13e030:	01d97825 */ 	or	$t7,$t6,$t9
/*  f13e034:	01f87025 */ 	or	$t6,$t7,$t8
/*  f13e038:	000d6200 */ 	sll	$t4,$t5,0x8
/*  f13e03c:	01cc7825 */ 	or	$t7,$t6,$t4
/*  f13e040:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f13e044:	24180040 */ 	addiu	$t8,$zero,0x40
/*  f13e048:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f13e04c:	e7b000d4 */ 	swc1	$f16,0xd4($sp)
/*  f13e050:	e7a400d8 */ 	swc1	$f4,0xd8($sp)
/*  f13e054:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f13e058:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13e05c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f13e060:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f13e064:	0fc2c9d0 */ 	jal	func0f0b2740
/*  f13e068:	afa00014 */ 	sw	$zero,0x14($sp)
.L0f13e06c:
/*  f13e06c:	a2600001 */ 	sb	$zero,0x1($s3)
.L0f13e070:
/*  f13e070:	a2600002 */ 	sb	$zero,0x2($s3)
.L0f13e074:
/*  f13e074:	02509021 */ 	addu	$s2,$s2,$s0
/*  f13e078:	2652ffff */ 	addiu	$s2,$s2,-1
.L0f13e07c:
/*  f13e07c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f13e080:
/*  f13e080:	2a410078 */ 	slti	$at,$s2,0x78
/*  f13e084:	1420fd6c */ 	bnez	$at,.L0f13d638
/*  f13e088:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13e08c:
/*  f13e08c:	8fa20160 */ 	lw	$v0,0x160($sp)
.L0f13e090:
/*  f13e090:	8fbf0084 */ 	lw	$ra,0x84($sp)
/*  f13e094:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f13e098:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f13e09c:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f13e0a0:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*  f13e0a4:	d7bc0050 */ 	ldc1	$f28,0x50($sp)
/*  f13e0a8:	d7be0058 */ 	ldc1	$f30,0x58($sp)
/*  f13e0ac:	8fb00060 */ 	lw	$s0,0x60($sp)
/*  f13e0b0:	8fb10064 */ 	lw	$s1,0x64($sp)
/*  f13e0b4:	8fb20068 */ 	lw	$s2,0x68($sp)
/*  f13e0b8:	8fb3006c */ 	lw	$s3,0x6c($sp)
/*  f13e0bc:	8fb40070 */ 	lw	$s4,0x70($sp)
/*  f13e0c0:	8fb50074 */ 	lw	$s5,0x74($sp)
/*  f13e0c4:	8fb60078 */ 	lw	$s6,0x78($sp)
/*  f13e0c8:	8fb7007c */ 	lw	$s7,0x7c($sp)
/*  f13e0cc:	8fbe0080 */ 	lw	$s8,0x80($sp)
/*  f13e0d0:	03e00008 */ 	jr	$ra
/*  f13e0d4:	27bd0160 */ 	addiu	$sp,$sp,0x160
/*  f13e0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e0dc:	00000000 */ 	sll	$zero,$zero,0x0
);
