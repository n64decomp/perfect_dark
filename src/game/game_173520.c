#include <ultra64.h>
#include "constants.h"
#include "game/game_0b3350.h"
#include "game/texdecompress.h"
#include "bss.h"
#include "lib/rzip.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f173520
/*  f173520:	3c01800b */ 	lui	$at,%hi(var800ab540)
/*  f173524:	ac24b540 */ 	sw	$a0,%lo(var800ab540)($at)
/*  f173528:	3c01800b */ 	lui	$at,%hi(var800ab544)
/*  f17352c:	ac20b544 */ 	sw	$zero,%lo(var800ab544)($at)
/*  f173530:	3c01800b */ 	lui	$at,%hi(var800ab548)
/*  f173534:	03e00008 */ 	jr	$ra
/*  f173538:	ac20b548 */ 	sw	$zero,%lo(var800ab548)($at)
);

s32 func0f17353c(s32 arg0)
{
	while (var800ab548 < arg0) {
		var800ab544 = *var800ab540 | var800ab544 << 8;
		var800ab540++;
		var800ab548 += 8;
	}

	var800ab548 -= arg0;

	return var800ab544 >> var800ab548 & (1 << arg0) - 1;
}

GLOBAL_ASM(
glabel texturesLoadConfigs
/*  f1735c0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1735c4:	3c0e0200 */ 	lui	$t6,0x200
/*  f1735c8:	3c0f0200 */ 	lui	$t7,0x200
/*  f1735cc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1735d0:	25ef0000 */ 	addiu	$t7,$t7,0x0
/*  f1735d4:	25ce0b50 */ 	addiu	$t6,$t6,0xb50
/*  f1735d8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1735dc:	01cf8823 */ 	subu	$s1,$t6,$t7
/*  f1735e0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1735e4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1735e8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1735ec:	0c0048f2 */ 	jal	malloc
/*  f1735f0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1735f4:	3c03800b */ 	lui	$v1,%hi(g_TextureConfigSegment)
/*  f1735f8:	2463b554 */ 	addiu	$v1,$v1,%lo(g_TextureConfigSegment)
/*  f1735fc:	3c05007f */ 	lui	$a1,%hi(_textureconfigSegmentRomStart)
/*  f173600:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f173604:	24a5b270 */ 	addiu	$a1,$a1,%lo(_textureconfigSegmentRomStart)
/*  f173608:	00402025 */ 	or	$a0,$v0,$zero
/*  f17360c:	0c003504 */ 	jal	dmaExec
/*  f173610:	02203025 */ 	or	$a2,$s1,$zero
/*  f173614:	3c18800b */ 	lui	$t8,%hi(g_TextureConfigSegment)
/*  f173618:	8f18b554 */ 	lw	$t8,%lo(g_TextureConfigSegment)($t8)
/*  f17361c:	3c070200 */ 	lui	$a3,0x200
/*  f173620:	3c06800b */ 	lui	$a2,%hi(var800ab550)
/*  f173624:	3c080200 */ 	lui	$t0,0x200
/*  f173628:	03071023 */ 	subu	$v0,$t8,$a3
/*  f17362c:	24c6b550 */ 	addiu	$a2,$a2,%lo(var800ab550)
/*  f173630:	25080000 */ 	addiu	$t0,$t0,0x0
/*  f173634:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f173638:	00484821 */ 	addu	$t1,$v0,$t0
/*  f17363c:	3c01800b */ 	lui	$at,%hi(var800ab564)
/*  f173640:	3c0a0200 */ 	lui	$t2,0x200
/*  f173644:	ac29b564 */ 	sw	$t1,%lo(var800ab564)($at)
/*  f173648:	254a0070 */ 	addiu	$t2,$t2,0x70
/*  f17364c:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f173650:	3c01800b */ 	lui	$at,%hi(var800ab568)
/*  f173654:	3c0c0200 */ 	lui	$t4,0x200
/*  f173658:	ac2bb568 */ 	sw	$t3,%lo(var800ab568)($at)
/*  f17365c:	258c00d8 */ 	addiu	$t4,$t4,0xd8
/*  f173660:	004c6821 */ 	addu	$t5,$v0,$t4
/*  f173664:	3c01800b */ 	lui	$at,%hi(var800ab56c)
/*  f173668:	3c0e0200 */ 	lui	$t6,0x200
/*  f17366c:	3c12800b */ 	lui	$s2,%hi(var800ab570)
/*  f173670:	ac2db56c */ 	sw	$t5,%lo(var800ab56c)($at)
/*  f173674:	25ce0148 */ 	addiu	$t6,$t6,0x148
/*  f173678:	3c030200 */ 	lui	$v1,0x200
/*  f17367c:	2652b570 */ 	addiu	$s2,$s2,%lo(var800ab570)
/*  f173680:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f173684:	246301c0 */ 	addiu	$v1,$v1,0x1c0
/*  f173688:	ae4f0000 */ 	sw	$t7,0x0($s2)
/*  f17368c:	0062c021 */ 	addu	$t8,$v1,$v0
/*  f173690:	3c01800b */ 	lui	$at,%hi(var800ab560)
/*  f173694:	3c190200 */ 	lui	$t9,0x200
/*  f173698:	ac38b560 */ 	sw	$t8,%lo(var800ab560)($at)
/*  f17369c:	27390298 */ 	addiu	$t9,$t9,0x298
/*  f1736a0:	00594021 */ 	addu	$t0,$v0,$t9
/*  f1736a4:	3c01800b */ 	lui	$at,%hi(var800ab574)
/*  f1736a8:	3c090200 */ 	lui	$t1,0x200
/*  f1736ac:	ac28b574 */ 	sw	$t0,%lo(var800ab574)($at)
/*  f1736b0:	252902d4 */ 	addiu	$t1,$t1,0x2d4
/*  f1736b4:	00495021 */ 	addu	$t2,$v0,$t1
/*  f1736b8:	3c01800b */ 	lui	$at,%hi(var800ab578)
/*  f1736bc:	3c0b0200 */ 	lui	$t3,0x200
/*  f1736c0:	ac2ab578 */ 	sw	$t2,%lo(var800ab578)($at)
/*  f1736c4:	256b02e0 */ 	addiu	$t3,$t3,0x2e0
/*  f1736c8:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f1736cc:	3c01800b */ 	lui	$at,%hi(var800ab57c)
/*  f1736d0:	3c0d0200 */ 	lui	$t5,0x200
/*  f1736d4:	ac2cb57c */ 	sw	$t4,%lo(var800ab57c)($at)
/*  f1736d8:	25ad02ec */ 	addiu	$t5,$t5,0x2ec
/*  f1736dc:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f1736e0:	3c01800b */ 	lui	$at,%hi(var800ab580)
/*  f1736e4:	3c0f0200 */ 	lui	$t7,0x200
/*  f1736e8:	ac2eb580 */ 	sw	$t6,%lo(var800ab580)($at)
/*  f1736ec:	25ef02f8 */ 	addiu	$t7,$t7,0x2f8
/*  f1736f0:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f1736f4:	3c01800b */ 	lui	$at,%hi(var800ab584)
/*  f1736f8:	3c190200 */ 	lui	$t9,0x200
/*  f1736fc:	ac38b584 */ 	sw	$t8,%lo(var800ab584)($at)
/*  f173700:	27390304 */ 	addiu	$t9,$t9,0x304
/*  f173704:	00594021 */ 	addu	$t0,$v0,$t9
/*  f173708:	3c01800b */ 	lui	$at,%hi(var800ab588)
/*  f17370c:	3c090200 */ 	lui	$t1,0x200
/*  f173710:	ac28b588 */ 	sw	$t0,%lo(var800ab588)($at)
/*  f173714:	25290310 */ 	addiu	$t1,$t1,0x310
/*  f173718:	00495021 */ 	addu	$t2,$v0,$t1
/*  f17371c:	3c01800b */ 	lui	$at,%hi(var800ab58c)
/*  f173720:	3c0b0200 */ 	lui	$t3,0x200
/*  f173724:	ac2ab58c */ 	sw	$t2,%lo(var800ab58c)($at)
/*  f173728:	256b031c */ 	addiu	$t3,$t3,0x31c
/*  f17372c:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f173730:	3c01800b */ 	lui	$at,%hi(var800ab590)
/*  f173734:	3c0d0200 */ 	lui	$t5,0x200
/*  f173738:	ac2cb590 */ 	sw	$t4,%lo(var800ab590)($at)
/*  f17373c:	25ad0334 */ 	addiu	$t5,$t5,0x334
/*  f173740:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f173744:	3c01800b */ 	lui	$at,%hi(var800ab594)
/*  f173748:	3c0f0200 */ 	lui	$t7,0x200
/*  f17374c:	ac2eb594 */ 	sw	$t6,%lo(var800ab594)($at)
/*  f173750:	25ef07b4 */ 	addiu	$t7,$t7,0x7b4
/*  f173754:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f173758:	3c01800b */ 	lui	$at,%hi(var800ab598)
/*  f17375c:	3c190200 */ 	lui	$t9,0x200
/*  f173760:	ac38b598 */ 	sw	$t8,%lo(var800ab598)($at)
/*  f173764:	273907d8 */ 	addiu	$t9,$t9,0x7d8
/*  f173768:	00594021 */ 	addu	$t0,$v0,$t9
/*  f17376c:	3c01800b */ 	lui	$at,%hi(var800ab59c)
/*  f173770:	3c090200 */ 	lui	$t1,0x200
/*  f173774:	ac28b59c */ 	sw	$t0,%lo(var800ab59c)($at)
/*  f173778:	25290820 */ 	addiu	$t1,$t1,0x820
/*  f17377c:	00495021 */ 	addu	$t2,$v0,$t1
/*  f173780:	3c01800b */ 	lui	$at,%hi(var800ab5a0)
/*  f173784:	3c0b0200 */ 	lui	$t3,0x200
/*  f173788:	ac2ab5a0 */ 	sw	$t2,%lo(var800ab5a0)($at)
/*  f17378c:	256b0898 */ 	addiu	$t3,$t3,0x898
/*  f173790:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f173794:	3c01800b */ 	lui	$at,%hi(var800ab5a4)
/*  f173798:	3c0d0200 */ 	lui	$t5,0x200
/*  f17379c:	ac2cb5a4 */ 	sw	$t4,%lo(var800ab5a4)($at)
/*  f1737a0:	25ad08a4 */ 	addiu	$t5,$t5,0x8a4
/*  f1737a4:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f1737a8:	3c01800b */ 	lui	$at,%hi(var800ab5a8)
/*  f1737ac:	3c0f0200 */ 	lui	$t7,0x200
/*  f1737b0:	ac2eb5a8 */ 	sw	$t6,%lo(var800ab5a8)($at)
/*  f1737b4:	25ef0b44 */ 	addiu	$t7,$t7,0xb44
/*  f1737b8:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f1737bc:	3c01800b */ 	lui	$at,%hi(var800ab5ac)
/*  f1737c0:	ac38b5ac */ 	sw	$t8,%lo(var800ab5ac)($at)
/*  f1737c4:	0223c823 */ 	subu	$t9,$s1,$v1
/*  f1737c8:	03274021 */ 	addu	$t0,$t9,$a3
/*  f1737cc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1737d0:	0101001b */ 	divu	$zero,$t0,$at
/*  f1737d4:	3c10800b */ 	lui	$s0,%hi(var800ab558)
/*  f1737d8:	00004812 */ 	mflo	$t1
/*  f1737dc:	3c01800b */ 	lui	$at,%hi(var800ab558)
/*  f1737e0:	2610b558 */ 	addiu	$s0,$s0,%lo(var800ab558)
/*  f1737e4:	ac29b558 */ 	sw	$t1,%lo(var800ab558)($at)
/*  f1737e8:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f1737ec:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1737f0:	00045080 */ 	sll	$t2,$a0,0x2
/*  f1737f4:	2544000f */ 	addiu	$a0,$t2,0xf
/*  f1737f8:	348b000f */ 	ori	$t3,$a0,0xf
/*  f1737fc:	0c0048f2 */ 	jal	malloc
/*  f173800:	3964000f */ 	xori	$a0,$t3,0xf
/*  f173804:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f173808:	3c03800b */ 	lui	$v1,%hi(var800ab55c)
/*  f17380c:	2463b55c */ 	addiu	$v1,$v1,%lo(var800ab55c)
/*  f173810:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f173814:	19a0000c */ 	blez	$t5,.L0f173848
/*  f173818:	00008825 */ 	or	$s1,$zero,$zero
/*  f17381c:	00001025 */ 	or	$v0,$zero,$zero
/*  f173820:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f173824:
/*  f173824:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f173828:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f17382c:	ade00000 */ 	sw	$zero,0x0($t7)
/*  f173830:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f173834:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f173838:	0238082a */ 	slt	$at,$s1,$t8
/*  f17383c:	5420fff9 */ 	bnezl	$at,.L0f173824
/*  f173840:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f173844:	00008825 */ 	or	$s1,$zero,$zero
.L0f173848:
/*  f173848:	8e590000 */ 	lw	$t9,0x0($s2)
.L0f17384c:
/*  f17384c:	001180c0 */ 	sll	$s0,$s1,0x3
/*  f173850:	00002825 */ 	or	$a1,$zero,$zero
/*  f173854:	00003025 */ 	or	$a2,$zero,$zero
/*  f173858:	0fc5cc04 */ 	jal	func0f173010
/*  f17385c:	02192021 */ 	addu	$a0,$s0,$t9
/*  f173860:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f173864:	00002825 */ 	or	$a1,$zero,$zero
/*  f173868:	00003025 */ 	or	$a2,$zero,$zero
/*  f17386c:	02082021 */ 	addu	$a0,$s0,$t0
/*  f173870:	0fc5cc04 */ 	jal	func0f173010
/*  f173874:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f173878:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f17387c:	2a21000f */ 	slti	$at,$s1,0xf
/*  f173880:	5420fff2 */ 	bnezl	$at,.L0f17384c
/*  f173884:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f173888:	3c04800b */ 	lui	$a0,%hi(var800ab564)
/*  f17388c:	8c84b564 */ 	lw	$a0,%lo(var800ab564)($a0)
/*  f173890:	00002825 */ 	or	$a1,$zero,$zero
/*  f173894:	0fc5cbd7 */ 	jal	func0f172f5c
/*  f173898:	00003025 */ 	or	$a2,$zero,$zero
/*  f17389c:	3c04800b */ 	lui	$a0,%hi(var800ab56c)
/*  f1738a0:	8c84b56c */ 	lw	$a0,%lo(var800ab56c)($a0)
/*  f1738a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1738a8:	0fc5cbd7 */ 	jal	func0f172f5c
/*  f1738ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f1738b0:	0c003a61 */ 	jal	mainGetStageNum
/*  f1738b4:	00000000 */ 	nop
/*  f1738b8:	3c098009 */ 	lui	$t1,%hi(g_Is4Mb)
/*  f1738bc:	91290af0 */ 	lbu	$t1,%lo(g_Is4Mb)($t1)
/*  f1738c0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1738c4:	15210045 */ 	bne	$t1,$at,.L0f1739dc
/*  f1738c8:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f1738cc:	10410043 */ 	beq	$v0,$at,.L0f1739dc
/*  f1738d0:	24010026 */ 	addiu	$at,$zero,0x26
/*  f1738d4:	10410041 */ 	beq	$v0,$at,.L0f1739dc
/*  f1738d8:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f1738dc:	1041003f */ 	beq	$v0,$at,.L0f1739dc
/*  f1738e0:	00008025 */ 	or	$s0,$zero,$zero
.L0f1738e4:
/*  f1738e4:	3c0a800b */ 	lui	$t2,%hi(var800ab560)
/*  f1738e8:	8d4ab560 */ 	lw	$t2,%lo(var800ab560)($t2)
/*  f1738ec:	0fc2ce62 */ 	jal	func0f0b3988
/*  f1738f0:	020a2021 */ 	addu	$a0,$s0,$t2
/*  f1738f4:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f1738f8:	2a0100d8 */ 	slti	$at,$s0,0xd8
/*  f1738fc:	1420fff9 */ 	bnez	$at,.L0f1738e4
/*  f173900:	00000000 */ 	nop
/*  f173904:	00008025 */ 	or	$s0,$zero,$zero
.L0f173908:
/*  f173908:	3c0b800b */ 	lui	$t3,%hi(var800ab574)
/*  f17390c:	8d6bb574 */ 	lw	$t3,%lo(var800ab574)($t3)
/*  f173910:	0fc2ce62 */ 	jal	func0f0b3988
/*  f173914:	020b2021 */ 	addu	$a0,$s0,$t3
/*  f173918:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f17391c:	2a01003c */ 	slti	$at,$s0,0x3c
/*  f173920:	1420fff9 */ 	bnez	$at,.L0f173908
/*  f173924:	00000000 */ 	nop
/*  f173928:	00008025 */ 	or	$s0,$zero,$zero
.L0f17392c:
/*  f17392c:	3c0c800b */ 	lui	$t4,%hi(var800ab598)
/*  f173930:	8d8cb598 */ 	lw	$t4,%lo(var800ab598)($t4)
/*  f173934:	0fc2ce62 */ 	jal	func0f0b3988
/*  f173938:	020c2021 */ 	addu	$a0,$s0,$t4
/*  f17393c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f173940:	2a010024 */ 	slti	$at,$s0,0x24
/*  f173944:	1420fff9 */ 	bnez	$at,.L0f17392c
/*  f173948:	00000000 */ 	nop
/*  f17394c:	00008025 */ 	or	$s0,$zero,$zero
.L0f173950:
/*  f173950:	3c0d800b */ 	lui	$t5,%hi(var800ab588)
/*  f173954:	8dadb588 */ 	lw	$t5,%lo(var800ab588)($t5)
/*  f173958:	0fc2ce62 */ 	jal	func0f0b3988
/*  f17395c:	020d2021 */ 	addu	$a0,$s0,$t5
/*  f173960:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f173964:	2a01000c */ 	slti	$at,$s0,0xc
/*  f173968:	1420fff9 */ 	bnez	$at,.L0f173950
/*  f17396c:	00000000 */ 	nop
/*  f173970:	00008025 */ 	or	$s0,$zero,$zero
.L0f173974:
/*  f173974:	3c0e800b */ 	lui	$t6,%hi(var800ab58c)
/*  f173978:	8dceb58c */ 	lw	$t6,%lo(var800ab58c)($t6)
/*  f17397c:	0fc2ce62 */ 	jal	func0f0b3988
/*  f173980:	020e2021 */ 	addu	$a0,$s0,$t6
/*  f173984:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f173988:	2a01000c */ 	slti	$at,$s0,0xc
/*  f17398c:	1420fff9 */ 	bnez	$at,.L0f173974
/*  f173990:	00000000 */ 	nop
/*  f173994:	00008025 */ 	or	$s0,$zero,$zero
.L0f173998:
/*  f173998:	3c0f800b */ 	lui	$t7,%hi(var800ab5ac)
/*  f17399c:	8defb5ac */ 	lw	$t7,%lo(var800ab5ac)($t7)
/*  f1739a0:	0fc2ce62 */ 	jal	func0f0b3988
/*  f1739a4:	020f2021 */ 	addu	$a0,$s0,$t7
/*  f1739a8:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f1739ac:	2a01000c */ 	slti	$at,$s0,0xc
/*  f1739b0:	1420fff9 */ 	bnez	$at,.L0f173998
/*  f1739b4:	00000000 */ 	nop
/*  f1739b8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1739bc:	2411000c */ 	addiu	$s1,$zero,0xc
.L0f1739c0:
/*  f1739c0:	3c18800b */ 	lui	$t8,%hi(var800ab5a4)
/*  f1739c4:	8f18b5a4 */ 	lw	$t8,%lo(var800ab5a4)($t8)
/*  f1739c8:	0fc2ce62 */ 	jal	func0f0b3988
/*  f1739cc:	02182021 */ 	addu	$a0,$s0,$t8
/*  f1739d0:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f1739d4:	1611fffa */ 	bne	$s0,$s1,.L0f1739c0
/*  f1739d8:	00000000 */ 	nop
.L0f1739dc:
/*  f1739dc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1739e0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1739e4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1739e8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1739ec:	03e00008 */ 	jr	$ra
/*  f1739f0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

//extern u8 *_textureconfigSegmentRomStart;
//extern u8 *_textureconfigSegmentStart;
//extern u8 *_textureconfigSegmentEnd;

// Unfinished
//void texturesLoadConfigs(void)
//{
//	s32 stage;
//	u32 len = &_textureconfigSegmentEnd - &_textureconfigSegmentStart;
//	s32 i;
//
//	g_TextureConfigSegment = malloc(len, MEMPOOL_STAGE);
//	dmaExec(g_TextureConfigSegment, &_textureconfigSegmentRomStart, len);
//
//	var800ab550 = (u32)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart);
//	var800ab564 = (Gfx *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x000); // gdl000
//	var800ab568 = (Gfx *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x070); // gdl070
//	var800ab56c = (Gfx *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x0d8); // gdl0d8
//	var800ab570 = (u32 *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x148); // g_ExplosionTextureNums
//	var800ab560 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x1c0);
//	var800ab574 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x298);
//	var800ab578 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x2d4);
//	var800ab57c = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x2e0);
//	var800ab580 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x2ec);
//	var800ab584 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x2f8);
//	var800ab588 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x304);
//	var800ab58c = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x310);
//	var800ab590 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x31c);
//	var800ab594 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x334);
//	var800ab598 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x7b4);
//	var800ab59c = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x7d8);
//	var800ab5a0 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x820);
//	var800ab5a4 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x898);
//	var800ab5a8 = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0x8a4);
//	var800ab5ac = (struct textureconfig *)((u32)g_TextureConfigSegment - (u32)&_textureconfigSegmentStart + 0xb44);
//
//	var800ab558 = (len - ((u32)&_textureconfigSegmentStart + 0x1c0)) + (u32)&_textureconfigSegmentStart;
//	var800ab55c = malloc(align16(var800ab558), MEMPOOL_STAGE);
//
//	for (i = 0; i < var800ab558; i++) {
//		var800ab55c[i].texturenum = 0;
//	}
//
//	for (i = 0; i < 15; i++) {
//		func0f173010(&var800ab570[i * 2 + 0], 0, 0);
//		func0f173010(&var800ab570[i * 2 + 1], 0, 0);
//	}
//
//	func0f172f5c(var800ab564, 0, 0);
//	func0f172f5c(var800ab56c, 0, 0);
//	stage = mainGetStageNum();
//
//	if (IS4MB() && stage != STAGE_TITLE && stage != STAGE_CITRAINING && stage != STAGE_4MBMENU) {
//		for (i = 0; i < 12; i++) {
//			func0f0b3988(&var800ab560[i]);
//		}
//
//		for (i = 0; i < 5; i++) {
//			func0f0b3988(&var800ab574[i]);
//		}
//
//		for (i = 0; i < 3; i++) {
//			func0f0b3988(&var800ab598[i]);
//		}
//
//		for (i = 0; i < 1; i++) {
//			func0f0b3988(&var800ab588[i]);
//		}
//
//		for (i = 0; i < 1; i++) {
//			func0f0b3988(&var800ab58c[i]);
//		}
//
//		for (i = 0; i < 1; i++) {
//			func0f0b3988(&var800ab5ac[i]);
//		}
//
//		for (i = 0; i < 1; i++) {
//			func0f0b3988(&var800ab5a4[i]);
//		}
//	}
//}
