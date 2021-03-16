#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/libc/ll.h"
#include "lib/lib_4c090.h"
#include "lib/lib_4cc10.h"
#include "lib/lib_4d480.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004d480
/*    4d480:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*    4d484:	afb20024 */ 	sw	$s2,0x24($sp)
/*    4d488:	afa50174 */ 	sw	$a1,0x174($sp)
/*    4d48c:	30aeffff */ 	andi	$t6,$a1,0xffff
/*    4d490:	01c02825 */ 	or	$a1,$t6,$zero
/*    4d494:	00809025 */ 	or	$s2,$a0,$zero
/*    4d498:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    4d49c:	afb50030 */ 	sw	$s5,0x30($sp)
/*    4d4a0:	afb4002c */ 	sw	$s4,0x2c($sp)
/*    4d4a4:	afb30028 */ 	sw	$s3,0x28($sp)
/*    4d4a8:	afb10020 */ 	sw	$s1,0x20($sp)
/*    4d4ac:	11c00003 */ 	beqz	$t6,.L0004d4bc
/*    4d4b0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*    4d4b4:	14c00003 */ 	bnez	$a2,.L0004d4c4
/*    4d4b8:	02402025 */ 	or	$a0,$s2,$zero
.L0004d4bc:
/*    4d4bc:	1000005d */ 	b	.L0004d634
/*    4d4c0:	24020005 */ 	addiu	$v0,$zero,0x5
.L0004d4c4:
/*    4d4c4:	8faf0180 */ 	lw	$t7,0x180($sp)
/*    4d4c8:	27b8016c */ 	addiu	$t8,$sp,0x16c
/*    4d4cc:	afb80014 */ 	sw	$t8,0x14($sp)
/*    4d4d0:	0c013304 */ 	jal	func0004cc10
/*    4d4d4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    4d4d8:	50400004 */ 	beqzl	$v0,.L0004d4ec
/*    4d4dc:	92590065 */ 	lbu	$t9,0x65($s2)
/*    4d4e0:	10000055 */ 	b	.L0004d638
/*    4d4e4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    4d4e8:	92590065 */ 	lbu	$t9,0x65($s2)
.L0004d4ec:
/*    4d4ec:	02402025 */ 	or	$a0,$s2,$zero
/*    4d4f0:	53200008 */ 	beqzl	$t9,.L0004d514
/*    4d4f4:	8e48005c */ 	lw	$t0,0x5c($s2)
/*    4d4f8:	0c013378 */ 	jal	__osPfsSelectBank
/*    4d4fc:	00002825 */ 	or	$a1,$zero,$zero
/*    4d500:	50400004 */ 	beqzl	$v0,.L0004d514
/*    4d504:	8e48005c */ 	lw	$t0,0x5c($s2)
/*    4d508:	1000004b */ 	b	.L0004d638
/*    4d50c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    4d510:	8e48005c */ 	lw	$t0,0x5c($s2)
.L0004d514:
/*    4d514:	8fa9016c */ 	lw	$t1,0x16c($sp)
/*    4d518:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4d51c:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4d520:	01093021 */ 	addu	$a2,$t0,$t1
/*    4d524:	30caffff */ 	andi	$t2,$a2,0xffff
/*    4d528:	01403025 */ 	or	$a2,$t2,$zero
/*    4d52c:	0c012e18 */ 	jal	__osContRamRead
/*    4d530:	27a70048 */ 	addiu	$a3,$sp,0x48
/*    4d534:	10400003 */ 	beqz	$v0,.L0004d544
/*    4d538:	93b0004e */ 	lbu	$s0,0x4e($sp)
/*    4d53c:	1000003e */ 	b	.L0004d638
/*    4d540:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0004d544:
/*    4d544:	92420064 */ 	lbu	$v0,0x64($s2)
/*    4d548:	93b3004f */ 	lbu	$s3,0x4f($sp)
/*    4d54c:	24150001 */ 	addiu	$s5,$zero,0x1
/*    4d550:	0202082a */ 	slt	$at,$s0,$v0
/*    4d554:	10200026 */ 	beqz	$at,.L0004d5f0
/*    4d558:	27b40044 */ 	addiu	$s4,$sp,0x44
/*    4d55c:	27b10068 */ 	addiu	$s1,$sp,0x68
/*    4d560:	02402025 */ 	or	$a0,$s2,$zero
.L0004d564:
/*    4d564:	02202825 */ 	or	$a1,$s1,$zero
/*    4d568:	00003025 */ 	or	$a2,$zero,$zero
/*    4d56c:	0c01324d */ 	jal	func0004c934
/*    4d570:	320700ff */ 	andi	$a3,$s0,0xff
/*    4d574:	10400003 */ 	beqz	$v0,.L0004d584
/*    4d578:	02402025 */ 	or	$a0,$s2,$zero
/*    4d57c:	1000002e */ 	b	.L0004d638
/*    4d580:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0004d584:
/*    4d584:	02202825 */ 	or	$a1,$s1,$zero
/*    4d588:	326600ff */ 	andi	$a2,$s3,0xff
/*    4d58c:	320700ff */ 	andi	$a3,$s0,0xff
/*    4d590:	0c013596 */ 	jal	func0004d658
/*    4d594:	afb40010 */ 	sw	$s4,0x10($sp)
/*    4d598:	10400003 */ 	beqz	$v0,.L0004d5a8
/*    4d59c:	02402025 */ 	or	$a0,$s2,$zero
/*    4d5a0:	10000025 */ 	b	.L0004d638
/*    4d5a4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0004d5a8:
/*    4d5a8:	02202825 */ 	or	$a1,$s1,$zero
/*    4d5ac:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4d5b0:	0c01324d */ 	jal	func0004c934
/*    4d5b4:	320700ff */ 	andi	$a3,$s0,0xff
/*    4d5b8:	10400003 */ 	beqz	$v0,.L0004d5c8
/*    4d5bc:	97ac0044 */ 	lhu	$t4,0x44($sp)
/*    4d5c0:	1000001d */ 	b	.L0004d638
/*    4d5c4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0004d5c8:
/*    4d5c8:	56ac0004 */ 	bnel	$s5,$t4,.L0004d5dc
/*    4d5cc:	92420064 */ 	lbu	$v0,0x64($s2)
/*    4d5d0:	10000007 */ 	b	.L0004d5f0
/*    4d5d4:	92420064 */ 	lbu	$v0,0x64($s2)
/*    4d5d8:	92420064 */ 	lbu	$v0,0x64($s2)
.L0004d5dc:
/*    4d5dc:	93b00044 */ 	lbu	$s0,0x44($sp)
/*    4d5e0:	93b30045 */ 	lbu	$s3,0x45($sp)
/*    4d5e4:	0202082a */ 	slt	$at,$s0,$v0
/*    4d5e8:	5420ffde */ 	bnezl	$at,.L0004d564
/*    4d5ec:	02402025 */ 	or	$a0,$s2,$zero
.L0004d5f0:
/*    4d5f0:	0202082a */ 	slt	$at,$s0,$v0
/*    4d5f4:	14200003 */ 	bnez	$at,.L0004d604
/*    4d5f8:	27a40048 */ 	addiu	$a0,$sp,0x48
/*    4d5fc:	1000000d */ 	b	.L0004d634
/*    4d600:	24020003 */ 	addiu	$v0,$zero,0x3
.L0004d604:
/*    4d604:	0c012c30 */ 	jal	bzero
/*    4d608:	24050020 */ 	addiu	$a1,$zero,0x20
/*    4d60c:	8e4d005c */ 	lw	$t5,0x5c($s2)
/*    4d610:	8fae016c */ 	lw	$t6,0x16c($sp)
/*    4d614:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4d618:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4d61c:	01ae3021 */ 	addu	$a2,$t5,$t6
/*    4d620:	30cfffff */ 	andi	$t7,$a2,0xffff
/*    4d624:	01e03025 */ 	or	$a2,$t7,$zero
/*    4d628:	afa00010 */ 	sw	$zero,0x10($sp)
/*    4d62c:	0c012d84 */ 	jal	__osContRamWrite
/*    4d630:	27a70048 */ 	addiu	$a3,$sp,0x48
.L0004d634:
/*    4d634:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0004d638:
/*    4d638:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*    4d63c:	8fb10020 */ 	lw	$s1,0x20($sp)
/*    4d640:	8fb20024 */ 	lw	$s2,0x24($sp)
/*    4d644:	8fb30028 */ 	lw	$s3,0x28($sp)
/*    4d648:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*    4d64c:	8fb50030 */ 	lw	$s5,0x30($sp)
/*    4d650:	03e00008 */ 	jr	$ra
/*    4d654:	27bd0170 */ 	addiu	$sp,$sp,0x170
);

GLOBAL_ASM(
glabel func0004d658
/*    4d658:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    4d65c:	30e200ff */ 	andi	$v0,$a3,0xff
/*    4d660:	30ce00ff */ 	andi	$t6,$a2,0xff
/*    4d664:	0002c200 */ 	sll	$t8,$v0,0x8
/*    4d668:	afa60018 */ 	sw	$a2,0x18($sp)
/*    4d66c:	afa7001c */ 	sw	$a3,0x1c($sp)
/*    4d670:	030ec821 */ 	addu	$t9,$t8,$t6
/*    4d674:	a7b9000c */ 	sh	$t9,0xc($sp)
/*    4d678:	24070003 */ 	addiu	$a3,$zero,0x3
/*    4d67c:	27a6000c */ 	addiu	$a2,$sp,0xc
/*    4d680:	27a30008 */ 	addiu	$v1,$sp,0x8
/*    4d684:	94c10000 */ 	lhu	$at,0x0($a2)
.L0004d688:
/*    4d688:	a4610000 */ 	sh	$at,0x0($v1)
/*    4d68c:	93ab000d */ 	lbu	$t3,0xd($sp)
/*    4d690:	000b6040 */ 	sll	$t4,$t3,0x1
/*    4d694:	00ac6821 */ 	addu	$t5,$a1,$t4
/*    4d698:	95a10000 */ 	lhu	$at,0x0($t5)
/*    4d69c:	a4c10000 */ 	sh	$at,0x0($a2)
/*    4d6a0:	93b90009 */ 	lbu	$t9,0x9($sp)
/*    4d6a4:	00194840 */ 	sll	$t1,$t9,0x1
/*    4d6a8:	00a94021 */ 	addu	$t0,$a1,$t1
/*    4d6ac:	a5070000 */ 	sh	$a3,0x0($t0)
/*    4d6b0:	8c8b0060 */ 	lw	$t3,0x60($a0)
/*    4d6b4:	97aa000c */ 	lhu	$t2,0xc($sp)
/*    4d6b8:	93ac000c */ 	lbu	$t4,0xc($sp)
/*    4d6bc:	014b082a */ 	slt	$at,$t2,$t3
/*    4d6c0:	54200004 */ 	bnezl	$at,.L0004d6d4
/*    4d6c4:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    4d6c8:	504cffef */ 	beql	$v0,$t4,.L0004d688
/*    4d6cc:	94c10000 */ 	lhu	$at,0x0($a2)
/*    4d6d0:	8faf0020 */ 	lw	$t7,0x20($sp)
.L0004d6d4:
/*    4d6d4:	94c10000 */ 	lhu	$at,0x0($a2)
/*    4d6d8:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*    4d6dc:	00001025 */ 	or	$v0,$zero,$zero
/*    4d6e0:	03e00008 */ 	jr	$ra
/*    4d6e4:	a5e10000 */ 	sh	$at,0x0($t7)
);
