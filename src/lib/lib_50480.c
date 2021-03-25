#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_50480.h"
#include "data.h"
#include "types.h"

#define CHECK_IPAGE(p, pfs)                                                                                   \
	(((p).ipage >= (pfs).inode_start_page) && ((p).inode_t.bank < (pfs).banks) && ((p).inode_t.page >= 0x01) && \
	 ((p).inode_t.page < 0x80))

s32 __osPfsGetNextPage(OSPfs *pfs, u8 *bank, __OSInode *inode, __OSInodeUnit *page)
{
	s32 ret;

	if (page->inode_t.bank != *bank) {
		*bank = page->inode_t.bank;

		if ((ret = __osPfsRWInode(pfs, inode, PFS_READ, *bank)) != 0) {
			return ret;
		}
	}

	*page = inode->inode_page[page->inode_t.page];

	if (!CHECK_IPAGE(*page, *pfs)) {
		if (page->ipage == 1) {
			return PFS_ERR_INVALID;
		}

		return PFS_ERR_INCONSISTENT;
	}

	return 0;
}

GLOBAL_ASM(
glabel func00050554
/*    50554:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*    50558:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    5055c:	afb30028 */ 	sw	$s3,0x28($sp)
/*    50560:	afb20024 */ 	sw	$s2,0x24($sp)
/*    50564:	afb10020 */ 	sw	$s1,0x20($sp)
/*    50568:	afb0001c */ 	sw	$s0,0x1c($sp)
/*    5056c:	afa60178 */ 	sw	$a2,0x178($sp)
/*    50570:	8c8e0050 */ 	lw	$t6,0x50($a0)
/*    50574:	30d000ff */ 	andi	$s0,$a2,0xff
/*    50578:	00e08825 */ 	or	$s1,$a3,$zero
/*    5057c:	00ae082a */ 	slt	$at,$a1,$t6
/*    50580:	10200003 */ 	beqz	$at,.L00050590
/*    50584:	00809025 */ 	or	$s2,$a0,$zero
/*    50588:	04a10003 */ 	bgez	$a1,.L00050598
/*    5058c:	8fa20180 */ 	lw	$v0,0x180($sp)
.L00050590:
/*    50590:	100000c7 */ 	b	.L000508b0
/*    50594:	24020005 */ 	addiu	$v0,$zero,0x5
.L00050598:
/*    50598:	18400003 */ 	blez	$v0,.L000505a8
/*    5059c:	304f001f */ 	andi	$t7,$v0,0x1f
/*    505a0:	11e00003 */ 	beqz	$t7,.L000505b0
/*    505a4:	00000000 */ 	nop
.L000505a8:
/*    505a8:	100000c1 */ 	b	.L000508b0
/*    505ac:	24020005 */ 	addiu	$v0,$zero,0x5
.L000505b0:
/*    505b0:	06200003 */ 	bltz	$s1,.L000505c0
/*    505b4:	3238001f */ 	andi	$t8,$s1,0x1f
/*    505b8:	53000004 */ 	beqzl	$t8,.L000505cc
/*    505bc:	8e590000 */ 	lw	$t9,0x0($s2)
.L000505c0:
/*    505c0:	100000bb */ 	b	.L000508b0
/*    505c4:	24020005 */ 	addiu	$v0,$zero,0x5
/*    505c8:	8e590000 */ 	lw	$t9,0x0($s2)
.L000505cc:
/*    505cc:	02402025 */ 	or	$a0,$s2,$zero
/*    505d0:	33280001 */ 	andi	$t0,$t9,0x1
/*    505d4:	15000003 */ 	bnez	$t0,.L000505e4
/*    505d8:	00000000 */ 	nop
/*    505dc:	100000b4 */ 	b	.L000508b0
/*    505e0:	24020005 */ 	addiu	$v0,$zero,0x5
.L000505e4:
/*    505e4:	0c013218 */ 	jal	__osCheckId
/*    505e8:	afa50174 */ 	sw	$a1,0x174($sp)
/*    505ec:	24010002 */ 	addiu	$at,$zero,0x2
/*    505f0:	54410004 */ 	bnel	$v0,$at,.L00050604
/*    505f4:	92490065 */ 	lbu	$t1,0x65($s2)
/*    505f8:	100000ad */ 	b	.L000508b0
/*    505fc:	24020002 */ 	addiu	$v0,$zero,0x2
/*    50600:	92490065 */ 	lbu	$t1,0x65($s2)
.L00050604:
/*    50604:	02402025 */ 	or	$a0,$s2,$zero
/*    50608:	51200008 */ 	beqzl	$t1,.L0005062c
/*    5060c:	8e4a005c */ 	lw	$t2,0x5c($s2)
/*    50610:	0c013378 */ 	jal	__osPfsSelectBank
/*    50614:	00002825 */ 	or	$a1,$zero,$zero
/*    50618:	50400004 */ 	beqzl	$v0,.L0005062c
/*    5061c:	8e4a005c */ 	lw	$t2,0x5c($s2)
/*    50620:	100000a4 */ 	b	.L000508b4
/*    50624:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    50628:	8e4a005c */ 	lw	$t2,0x5c($s2)
.L0005062c:
/*    5062c:	8fab0174 */ 	lw	$t3,0x174($sp)
/*    50630:	8e440004 */ 	lw	$a0,0x4($s2)
/*    50634:	8e450008 */ 	lw	$a1,0x8($s2)
/*    50638:	014b3021 */ 	addu	$a2,$t2,$t3
/*    5063c:	30ccffff */ 	andi	$t4,$a2,0xffff
/*    50640:	01803025 */ 	or	$a2,$t4,$zero
/*    50644:	0c012e18 */ 	jal	__osContRamRead
/*    50648:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*    5064c:	10400003 */ 	beqz	$v0,.L0005065c
/*    50650:	97ad0150 */ 	lhu	$t5,0x150($sp)
/*    50654:	10000097 */ 	b	.L000508b4
/*    50658:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0005065c:
/*    5065c:	11a00003 */ 	beqz	$t5,.L0005066c
/*    50660:	8fae014c */ 	lw	$t6,0x14c($sp)
/*    50664:	15c00003 */ 	bnez	$t6,.L00050674
/*    50668:	97af0152 */ 	lhu	$t7,0x152($sp)
.L0005066c:
/*    5066c:	10000090 */ 	b	.L000508b0
/*    50670:	24020005 */ 	addiu	$v0,$zero,0x5
.L00050674:
/*    50674:	8e580060 */ 	lw	$t8,0x60($s2)
/*    50678:	93b90152 */ 	lbu	$t9,0x152($sp)
/*    5067c:	97aa0152 */ 	lhu	$t2,0x152($sp)
/*    50680:	01f8082a */ 	slt	$at,$t7,$t8
/*    50684:	5420000a */ 	bnezl	$at,.L000506b0
/*    50688:	24010001 */ 	addiu	$at,$zero,0x1
/*    5068c:	92480064 */ 	lbu	$t0,0x64($s2)
/*    50690:	93a90153 */ 	lbu	$t1,0x153($sp)
/*    50694:	0328082a */ 	slt	$at,$t9,$t0
/*    50698:	50200005 */ 	beqzl	$at,.L000506b0
/*    5069c:	24010001 */ 	addiu	$at,$zero,0x1
/*    506a0:	19200002 */ 	blez	$t1,.L000506ac
/*    506a4:	29210080 */ 	slti	$at,$t1,0x80
/*    506a8:	14200007 */ 	bnez	$at,.L000506c8
.L000506ac:
/*    506ac:	24010001 */ 	addiu	$at,$zero,0x1
.L000506b0:
/*    506b0:	15410003 */ 	bne	$t2,$at,.L000506c0
/*    506b4:	00000000 */ 	nop
/*    506b8:	1000007d */ 	b	.L000508b0
/*    506bc:	24020005 */ 	addiu	$v0,$zero,0x5
.L000506c0:
/*    506c0:	1000007b */ 	b	.L000508b0
/*    506c4:	24020003 */ 	addiu	$v0,$zero,0x3
.L000506c8:
/*    506c8:	16000007 */ 	bnez	$s0,.L000506e8
/*    506cc:	afb00034 */ 	sw	$s0,0x34($sp)
/*    506d0:	93ac0154 */ 	lbu	$t4,0x154($sp)
/*    506d4:	318d0002 */ 	andi	$t5,$t4,0x2
/*    506d8:	55a00004 */ 	bnezl	$t5,.L000506ec
/*    506dc:	97af0152 */ 	lhu	$t7,0x152($sp)
/*    506e0:	10000073 */ 	b	.L000508b0
/*    506e4:	24020006 */ 	addiu	$v0,$zero,0x6
.L000506e8:
/*    506e8:	97af0152 */ 	lhu	$t7,0x152($sp)
.L000506ec:
/*    506ec:	240e00ff */ 	addiu	$t6,$zero,0xff
/*    506f0:	a3ae003b */ 	sb	$t6,0x3b($sp)
/*    506f4:	06210003 */ 	bgez	$s1,.L00050704
/*    506f8:	00111143 */ 	sra	$v0,$s1,0x5
/*    506fc:	2621001f */ 	addiu	$at,$s1,0x1f
/*    50700:	00011143 */ 	sra	$v0,$at,0x5
.L00050704:
/*    50704:	28410008 */ 	slti	$at,$v0,0x8
/*    50708:	00408025 */ 	or	$s0,$v0,$zero
/*    5070c:	1420000d */ 	bnez	$at,.L00050744
/*    50710:	a7af0048 */ 	sh	$t7,0x48($sp)
/*    50714:	02402025 */ 	or	$a0,$s2,$zero
.L00050718:
/*    50718:	27a5003b */ 	addiu	$a1,$sp,0x3b
/*    5071c:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*    50720:	0c014120 */ 	jal	__osPfsGetNextPage
/*    50724:	27a70048 */ 	addiu	$a3,$sp,0x48
/*    50728:	10400003 */ 	beqz	$v0,.L00050738
/*    5072c:	2610fff8 */ 	addiu	$s0,$s0,-8
/*    50730:	10000060 */ 	b	.L000508b4
/*    50734:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00050738:
/*    50738:	2a010008 */ 	slti	$at,$s0,0x8
/*    5073c:	5020fff6 */ 	beqzl	$at,.L00050718
/*    50740:	02402025 */ 	or	$a0,$s2,$zero
.L00050744:
/*    50744:	8fa20180 */ 	lw	$v0,0x180($sp)
/*    50748:	8fb10184 */ 	lw	$s1,0x184($sp)
/*    5074c:	04410003 */ 	bgez	$v0,.L0005075c
/*    50750:	0002c143 */ 	sra	$t8,$v0,0x5
/*    50754:	2441001f */ 	addiu	$at,$v0,0x1f
/*    50758:	0001c143 */ 	sra	$t8,$at,0x5
.L0005075c:
/*    5075c:	1b000031 */ 	blez	$t8,.L00050824
/*    50760:	03009825 */ 	or	$s3,$t8,$zero
.L00050764:
/*    50764:	24010008 */ 	addiu	$at,$zero,0x8
/*    50768:	16010009 */ 	bne	$s0,$at,.L00050790
/*    5076c:	02402025 */ 	or	$a0,$s2,$zero
/*    50770:	27a5003b */ 	addiu	$a1,$sp,0x3b
/*    50774:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*    50778:	0c014120 */ 	jal	__osPfsGetNextPage
/*    5077c:	27a70048 */ 	addiu	$a3,$sp,0x48
/*    50780:	10400003 */ 	beqz	$v0,.L00050790
/*    50784:	00008025 */ 	or	$s0,$zero,$zero
/*    50788:	1000004a */ 	b	.L000508b4
/*    5078c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00050790:
/*    50790:	93b90048 */ 	lbu	$t9,0x48($sp)
/*    50794:	92480065 */ 	lbu	$t0,0x65($s2)
/*    50798:	02402025 */ 	or	$a0,$s2,$zero
/*    5079c:	53280008 */ 	beql	$t9,$t0,.L000507c0
/*    507a0:	93a90049 */ 	lbu	$t1,0x49($sp)
/*    507a4:	0c013378 */ 	jal	__osPfsSelectBank
/*    507a8:	03202825 */ 	or	$a1,$t9,$zero
/*    507ac:	50400004 */ 	beqzl	$v0,.L000507c0
/*    507b0:	93a90049 */ 	lbu	$t1,0x49($sp)
/*    507b4:	1000003f */ 	b	.L000508b4
/*    507b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    507bc:	93a90049 */ 	lbu	$t1,0x49($sp)
.L000507c0:
/*    507c0:	8fac0034 */ 	lw	$t4,0x34($sp)
/*    507c4:	02203825 */ 	or	$a3,$s1,$zero
/*    507c8:	000950c0 */ 	sll	$t2,$t1,0x3
/*    507cc:	01503021 */ 	addu	$a2,$t2,$s0
/*    507d0:	30cbffff */ 	andi	$t3,$a2,0xffff
/*    507d4:	15800007 */ 	bnez	$t4,.L000507f4
/*    507d8:	01603025 */ 	or	$a2,$t3,$zero
/*    507dc:	8e440004 */ 	lw	$a0,0x4($s2)
/*    507e0:	8e450008 */ 	lw	$a1,0x8($s2)
/*    507e4:	0c012e18 */ 	jal	__osContRamRead
/*    507e8:	02203825 */ 	or	$a3,$s1,$zero
/*    507ec:	10000006 */ 	b	.L00050808
/*    507f0:	00401825 */ 	or	$v1,$v0,$zero
.L000507f4:
/*    507f4:	8e440004 */ 	lw	$a0,0x4($s2)
/*    507f8:	8e450008 */ 	lw	$a1,0x8($s2)
/*    507fc:	0c012d84 */ 	jal	__osContRamWrite
/*    50800:	afa00010 */ 	sw	$zero,0x10($sp)
/*    50804:	00401825 */ 	or	$v1,$v0,$zero
.L00050808:
/*    50808:	10400003 */ 	beqz	$v0,.L00050818
/*    5080c:	26310020 */ 	addiu	$s1,$s1,0x20
/*    50810:	10000027 */ 	b	.L000508b0
/*    50814:	00601025 */ 	or	$v0,$v1,$zero
.L00050818:
/*    50818:	2673ffff */ 	addiu	$s3,$s3,-1
/*    5081c:	1660ffd1 */ 	bnez	$s3,.L00050764
/*    50820:	26100001 */ 	addiu	$s0,$s0,0x1
.L00050824:
/*    50824:	8fad0034 */ 	lw	$t5,0x34($sp)
/*    50828:	93a20154 */ 	lbu	$v0,0x154($sp)
/*    5082c:	24010001 */ 	addiu	$at,$zero,0x1
/*    50830:	15a1001c */ 	bne	$t5,$at,.L000508a4
/*    50834:	304e0002 */ 	andi	$t6,$v0,0x2
/*    50838:	15c0001a */ 	bnez	$t6,.L000508a4
/*    5083c:	344f0002 */ 	ori	$t7,$v0,0x2
/*    50840:	a3af0154 */ 	sb	$t7,0x154($sp)
/*    50844:	92580065 */ 	lbu	$t8,0x65($s2)
/*    50848:	02402025 */ 	or	$a0,$s2,$zero
/*    5084c:	53000008 */ 	beqzl	$t8,.L00050870
/*    50850:	8e48005c */ 	lw	$t0,0x5c($s2)
/*    50854:	0c013378 */ 	jal	__osPfsSelectBank
/*    50858:	00002825 */ 	or	$a1,$zero,$zero
/*    5085c:	50400004 */ 	beqzl	$v0,.L00050870
/*    50860:	8e48005c */ 	lw	$t0,0x5c($s2)
/*    50864:	10000013 */ 	b	.L000508b4
/*    50868:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    5086c:	8e48005c */ 	lw	$t0,0x5c($s2)
.L00050870:
/*    50870:	8fb90174 */ 	lw	$t9,0x174($sp)
/*    50874:	8e440004 */ 	lw	$a0,0x4($s2)
/*    50878:	8e450008 */ 	lw	$a1,0x8($s2)
/*    5087c:	01193021 */ 	addu	$a2,$t0,$t9
/*    50880:	30c9ffff */ 	andi	$t1,$a2,0xffff
/*    50884:	01203025 */ 	or	$a2,$t1,$zero
/*    50888:	afa00010 */ 	sw	$zero,0x10($sp)
/*    5088c:	0c012d84 */ 	jal	__osContRamWrite
/*    50890:	27a7014c */ 	addiu	$a3,$sp,0x14c
/*    50894:	50400004 */ 	beqzl	$v0,.L000508a8
/*    50898:	8e440004 */ 	lw	$a0,0x4($s2)
/*    5089c:	10000005 */ 	b	.L000508b4
/*    508a0:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L000508a4:
/*    508a4:	8e440004 */ 	lw	$a0,0x4($s2)
.L000508a8:
/*    508a8:	0c012ea4 */ 	jal	__osPfsGetStatus
/*    508ac:	8e450008 */ 	lw	$a1,0x8($s2)
.L000508b0:
/*    508b0:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L000508b4:
/*    508b4:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*    508b8:	8fb10020 */ 	lw	$s1,0x20($sp)
/*    508bc:	8fb20024 */ 	lw	$s2,0x24($sp)
/*    508c0:	8fb30028 */ 	lw	$s3,0x28($sp)
/*    508c4:	03e00008 */ 	jr	$ra
/*    508c8:	27bd0170 */ 	addiu	$sp,$sp,0x170
);
