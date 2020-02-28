#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_00b320.h"
#include "game/game_00b820.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f00b480
/*  f00b480:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f00b484:	3c018006 */ 	lui	$at,0x8006
/*  f00b488:	ac2224b4 */ 	sw	$v0,0x24b4($at)
/*  f00b48c:	3c018006 */ 	lui	$at,0x8006
/*  f00b490:	ac2024d4 */ 	sw	$zero,0x24d4($at)
/*  f00b494:	3c018006 */ 	lui	$at,0x8006
/*  f00b498:	ac2024d8 */ 	sw	$zero,0x24d8($at)
/*  f00b49c:	3c018006 */ 	lui	$at,0x8006
/*  f00b4a0:	ac2024dc */ 	sw	$zero,0x24dc($at)
/*  f00b4a4:	3c018006 */ 	lui	$at,0x8006
/*  f00b4a8:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f00b4ac:	ac2e24bc */ 	sw	$t6,0x24bc($at)
/*  f00b4b0:	3c188006 */ 	lui	$t8,0x8006
/*  f00b4b4:	8f1824f0 */ 	lw	$t8,0x24f0($t8)
/*  f00b4b8:	3c018006 */ 	lui	$at,0x8006
/*  f00b4bc:	ac2224c0 */ 	sw	$v0,0x24c0($at)
/*  f00b4c0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00b4c4:	3c018006 */ 	lui	$at,0x8006
/*  f00b4c8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f00b4cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00b4d0:	13000004 */ 	beqz	$t8,.L0f00b4e4
/*  f00b4d4:	ac2f24f4 */ 	sw	$t7,0x24f4($at)
/*  f00b4d8:	24190005 */ 	addiu	$t9,$zero,0x5
/*  f00b4dc:	3c018006 */ 	lui	$at,0x8006
/*  f00b4e0:	ac3924b8 */ 	sw	$t9,0x24b8($at)
.L0f00b4e4:
/*  f00b4e4:	3c040004 */ 	lui	$a0,0x4
/*  f00b4e8:	34847800 */ 	ori	$a0,$a0,0x7800
/*  f00b4ec:	0c0048f2 */ 	jal	malloc
/*  f00b4f0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b4f4:	3c01800a */ 	lui	$at,0x800a
/*  f00b4f8:	0fc02d08 */ 	jal	func0f00b420
/*  f00b4fc:	ac22cca0 */ 	sw	$v0,-0x3360($at)
/*  f00b500:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00b504:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00b508:	03e00008 */ 	jr	$ra
/*  f00b50c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f00b510
/*  f00b510:	3c013f80 */ 	lui	$at,0x3f80
/*  f00b514:	44812000 */ 	mtc1	$at,$f4
/*  f00b518:	3c018006 */ 	lui	$at,0x8006
/*  f00b51c:	240e1388 */ 	addiu	$t6,$zero,0x1388
/*  f00b520:	e4242968 */ 	swc1	$f4,0x2968($at)
/*  f00b524:	3c018006 */ 	lui	$at,0x8006
/*  f00b528:	ac20296c */ 	sw	$zero,0x296c($at)
/*  f00b52c:	3c018006 */ 	lui	$at,0x8006
/*  f00b530:	ac202970 */ 	sw	$zero,0x2970($at)
/*  f00b534:	3c018006 */ 	lui	$at,0x8006
/*  f00b538:	ac202974 */ 	sw	$zero,0x2974($at)
/*  f00b53c:	3c018006 */ 	lui	$at,0x8006
/*  f00b540:	ac202978 */ 	sw	$zero,0x2978($at)
/*  f00b544:	3c018006 */ 	lui	$at,0x8006
/*  f00b548:	ac20297c */ 	sw	$zero,0x297c($at)
/*  f00b54c:	3c018006 */ 	lui	$at,0x8006
/*  f00b550:	ac2e2984 */ 	sw	$t6,0x2984($at)
/*  f00b554:	3c018006 */ 	lui	$at,0x8006
/*  f00b558:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f00b55c:	ac202988 */ 	sw	$zero,0x2988($at)
/*  f00b560:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00b564:	3c018006 */ 	lui	$at,0x8006
/*  f00b568:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f00b56c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f00b570:	ac20298c */ 	sw	$zero,0x298c($at)
/*  f00b574:	24040730 */ 	addiu	$a0,$zero,0x730
/*  f00b578:	0c0048f2 */ 	jal	malloc
/*  f00b57c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b580:	3c048006 */ 	lui	$a0,%hi(var80062a8c)
/*  f00b584:	24842a8c */ 	addiu	$a0,$a0,%lo(var80062a8c)
/*  f00b588:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00b58c:	00001825 */ 	or	$v1,$zero,$zero
.L0f00b590:
/*  f00b590:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f00b594:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f00b598:	2463005c */ 	addiu	$v1,$v1,0x5c
/*  f00b59c:	28610730 */ 	slti	$at,$v1,0x730
/*  f00b5a0:	1420fffb */ 	bnez	$at,.L0f00b590
/*  f00b5a4:	af000000 */ 	sw	$zero,0x0($t8)
/*  f00b5a8:	3c018006 */ 	lui	$at,0x8006
/*  f00b5ac:	ac202a90 */ 	sw	$zero,0x2a90($at)
/*  f00b5b0:	3c01800a */ 	lui	$at,0x800a
/*  f00b5b4:	ac20cd10 */ 	sw	$zero,-0x32f0($at)
/*  f00b5b8:	3c01800a */ 	lui	$at,0x800a
/*  f00b5bc:	ac20cd14 */ 	sw	$zero,-0x32ec($at)
/*  f00b5c0:	3c01800a */ 	lui	$at,0x800a
/*  f00b5c4:	ac20cd18 */ 	sw	$zero,-0x32e8($at)
/*  f00b5c8:	24041470 */ 	addiu	$a0,$zero,0x1470
/*  f00b5cc:	0c0048f2 */ 	jal	malloc
/*  f00b5d0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b5d4:	3c018006 */ 	lui	$at,0x8006
/*  f00b5d8:	3c10800a */ 	lui	$s0,%hi(var8009ccc0)
/*  f00b5dc:	3c11800a */ 	lui	$s1,%hi(g_NumChrsC)
/*  f00b5e0:	ac222960 */ 	sw	$v0,0x2960($at)
/*  f00b5e4:	2631cd10 */ 	addiu	$s1,$s1,%lo(g_NumChrsC)
/*  f00b5e8:	2610ccc0 */ 	addiu	$s0,$s0,%lo(var8009ccc0)
.L0f00b5ec:
/*  f00b5ec:	24040240 */ 	addiu	$a0,$zero,0x240
/*  f00b5f0:	0c0048f2 */ 	jal	malloc
/*  f00b5f4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b5f8:	2459003f */ 	addiu	$t9,$v0,0x3f
/*  f00b5fc:	3728003f */ 	ori	$t0,$t9,0x3f
/*  f00b600:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f00b604:	3909003f */ 	xori	$t1,$t0,0x3f
/*  f00b608:	1611fff8 */ 	bne	$s0,$s1,.L0f00b5ec
/*  f00b60c:	ae09fffc */ 	sw	$t1,-0x4($s0)
/*  f00b610:	0fc02edc */ 	jal	resetSomeStageThings
/*  f00b614:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b618:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00b61c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f00b620:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f00b624:	03e00008 */ 	jr	$ra
/*  f00b628:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f00b62c
/*  f00b62c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f00b630:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f00b634:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f00b638:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f00b63c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00b640:	11c00003 */ 	beqz	$t6,.L0f00b650
/*  f00b644:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f00b648:	10000002 */ 	beqz	$zero,.L0f00b654
/*  f00b64c:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f00b650:
/*  f00b650:	00003825 */ 	or	$a3,$zero,$zero
.L0f00b654:
/*  f00b654:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f00b658:	3c088006 */ 	lui	$t0,%hi(g_NumChrsA)
/*  f00b65c:	2508298c */ 	addiu	$t0,$t0,%lo(g_NumChrsA)
/*  f00b660:	11e00003 */ 	beqz	$t7,.L0f00b670
/*  f00b664:	8fac0020 */ 	lw	$t4,0x20($sp)
/*  f00b668:	10000002 */ 	beqz	$zero,.L0f00b674
/*  f00b66c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f00b670:
/*  f00b670:	00001825 */ 	or	$v1,$zero,$zero
.L0f00b674:
/*  f00b674:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f00b678:	00003025 */ 	or	$a2,$zero,$zero
/*  f00b67c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b680:	13000003 */ 	beqz	$t8,.L0f00b690
/*  f00b684:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b688:	10000001 */ 	beqz	$zero,.L0f00b690
/*  f00b68c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f00b690:
/*  f00b690:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f00b694:	00001025 */ 	or	$v0,$zero,$zero
/*  f00b698:	13200003 */ 	beqz	$t9,.L0f00b6a8
/*  f00b69c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b6a0:	10000001 */ 	beqz	$zero,.L0f00b6a8
/*  f00b6a4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f00b6a8:
/*  f00b6a8:	00464821 */ 	addu	$t1,$v0,$a2
/*  f00b6ac:	01235021 */ 	addu	$t2,$t1,$v1
/*  f00b6b0:	01475821 */ 	addu	$t3,$t2,$a3
/*  f00b6b4:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f00b6b8:	25ae000a */ 	addiu	$t6,$t5,0xa
/*  f00b6bc:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f00b6c0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f00b6c4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f00b6c8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f00b6cc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f00b6d0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f00b6d4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f00b6d8:	25e4000f */ 	addiu	$a0,$t7,0xf
/*  f00b6dc:	3498000f */ 	ori	$t8,$a0,0xf
/*  f00b6e0:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f00b6e4:	0c0048f2 */ 	jal	malloc
/*  f00b6e8:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f00b6ec:	3c088006 */ 	lui	$t0,%hi(g_NumChrsA)
/*  f00b6f0:	2508298c */ 	addiu	$t0,$t0,%lo(g_NumChrsA)
/*  f00b6f4:	8d060000 */ 	lw	$a2,0x0($t0)
/*  f00b6f8:	3c048006 */ 	lui	$a0,%hi(g_ChrsA)
/*  f00b6fc:	24842988 */ 	addiu	$a0,$a0,%lo(g_ChrsA)
/*  f00b700:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00b704:	18c00013 */ 	blez	$a2,.L0f00b754
/*  f00b708:	00001825 */ 	or	$v1,$zero,$zero
/*  f00b70c:	00001025 */ 	or	$v0,$zero,$zero
/*  f00b710:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f00b714:	8c890000 */ 	lw	$t1,0x0($a0)
.L0f00b718:
/*  f00b718:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00b71c:	01225021 */ 	addu	$t2,$t1,$v0
/*  f00b720:	a5470000 */ 	sh	$a3,0x0($t2)
/*  f00b724:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f00b728:	01626021 */ 	addu	$t4,$t3,$v0
/*  f00b72c:	ad800020 */ 	sw	$zero,0x20($t4)
/*  f00b730:	8c8d0000 */ 	lw	$t5,0x0($a0)
/*  f00b734:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f00b738:	adc0001c */ 	sw	$zero,0x1c($t6)
/*  f00b73c:	8d060000 */ 	lw	$a2,0x0($t0)
/*  f00b740:	24420368 */ 	addiu	$v0,$v0,0x368
/*  f00b744:	0066082a */ 	slt	$at,$v1,$a2
/*  f00b748:	5420fff3 */ 	bnezl	$at,.L0f00b718
/*  f00b74c:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f00b750:	00001825 */ 	or	$v1,$zero,$zero
.L0f00b754:
/*  f00b754:	00062040 */ 	sll	$a0,$a2,0x1
/*  f00b758:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f00b75c:	3c01800a */ 	lui	$at,0x800a
/*  f00b760:	348f000f */ 	ori	$t7,$a0,0xf
/*  f00b764:	ac20cd10 */ 	sw	$zero,-0x32f0($at)
/*  f00b768:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f00b76c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b770:	0c0048f2 */ 	jal	malloc
/*  f00b774:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f00b778:	3c088006 */ 	lui	$t0,%hi(g_NumChrsA)
/*  f00b77c:	2508298c */ 	addiu	$t0,$t0,%lo(g_NumChrsA)
/*  f00b780:	8d040000 */ 	lw	$a0,0x0($t0)
/*  f00b784:	3c06800a */ 	lui	$a2,%hi(g_ChrnumsC)
/*  f00b788:	24c6cd14 */ 	addiu	$a2,$a2,%lo(g_ChrnumsC)
/*  f00b78c:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f00b790:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f00b794:	3489000f */ 	ori	$t1,$a0,0xf
/*  f00b798:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f00b79c:	3924000f */ 	xori	$a0,$t1,0xf
/*  f00b7a0:	0c0048f2 */ 	jal	malloc
/*  f00b7a4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b7a8:	3c088006 */ 	lui	$t0,%hi(g_NumChrsA)
/*  f00b7ac:	2508298c */ 	addiu	$t0,$t0,%lo(g_NumChrsA)
/*  f00b7b0:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f00b7b4:	3c04800a */ 	lui	$a0,%hi(g_ChrIndexesC)
/*  f00b7b8:	2484cd18 */ 	addiu	$a0,$a0,%lo(g_ChrIndexesC)
/*  f00b7bc:	3c06800a */ 	lui	$a2,%hi(g_ChrnumsC)
/*  f00b7c0:	24c6cd14 */ 	addiu	$a2,$a2,%lo(g_ChrnumsC)
/*  f00b7c4:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00b7c8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f00b7cc:	1960000e */ 	blez	$t3,.L0f00b808
/*  f00b7d0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f00b7d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f00b7d8:	8ccc0000 */ 	lw	$t4,0x0($a2)
.L0f00b7dc:
/*  f00b7dc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00b7e0:	01826821 */ 	addu	$t5,$t4,$v0
/*  f00b7e4:	a5a70000 */ 	sh	$a3,0x0($t5)
/*  f00b7e8:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f00b7ec:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f00b7f0:	a5e70000 */ 	sh	$a3,0x0($t7)
/*  f00b7f4:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f00b7f8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f00b7fc:	0078082a */ 	slt	$at,$v1,$t8
/*  f00b800:	5420fff6 */ 	bnezl	$at,.L0f00b7dc
/*  f00b804:	8ccc0000 */ 	lw	$t4,0x0($a2)
.L0f00b808:
/*  f00b808:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00b80c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f00b810:	03e00008 */ 	jr	$ra
/*  f00b814:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b81c:	00000000 */ 	sll	$zero,$zero,0x0
);
