#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_16110.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3e730.h"
#include "lib/lib_43dd0.h"
#include "lib/lib_44f60.h"
#include "lib/lib_45ed0.h"
#include "lib/lib_461c0.h"
#include "lib/lib_46650.h"
#include "lib/lib_47550.h"
#include "lib/libc/ll.h"
#include "lib/lib_4b170.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003e730
/*    3e730:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3e734:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3e738:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3e73c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3e740:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3e744:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3e748:	11e0001f */ 	beqz	$t7,.L0003e7c8
/*    3e74c:	00000000 */ 	nop
/*    3e750:	0c00c541 */ 	jal	func00031504
/*    3e754:	00000000 */ 	nop
/*    3e758:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3e75c:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3e760:	17000003 */ 	bnez	$t8,.L0003e770
/*    3e764:	00000000 */ 	nop
/*    3e768:	10000019 */ 	b	.L0003e7d0
/*    3e76c:	00000000 */ 	nop
.L0003e770:
/*    3e770:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3e774:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3e778:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3e77c:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3e780:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3e784:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3e788:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3e78c:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3e790:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3e794:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3e798:	240e0011 */ 	addiu	$t6,$zero,0x11
/*    3e79c:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3e7a0:	93b80027 */ 	lbu	$t8,0x27($sp)
/*    3e7a4:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3e7a8:	af38000c */ 	sw	$t8,0xc($t9)
/*    3e7ac:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3e7b0:	ad200000 */ 	sw	$zero,0x0($t1)
/*    3e7b4:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3e7b8:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3e7bc:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3e7c0:	0c00fc79 */ 	jal	func0003f1e4
/*    3e7c4:	8d440008 */ 	lw	$a0,0x8($t2)
.L0003e7c8:
/*    3e7c8:	10000001 */ 	b	.L0003e7d0
/*    3e7cc:	00000000 */ 	nop
.L0003e7d0:
/*    3e7d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3e7d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3e7d8:	03e00008 */ 	jr	$ra
/*    3e7dc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003e7e0
/*    3e7e0:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    3e7e4:	240effff */ 	addiu	$t6,$zero,-1
/*    3e7e8:	afae0008 */ 	sw	$t6,0x8($sp)
/*    3e7ec:	8c8f0010 */ 	lw	$t7,0x10($a0)
/*    3e7f0:	afaf0004 */ 	sw	$t7,0x4($sp)
/*    3e7f4:	8c980004 */ 	lw	$t8,0x4($a0)
/*    3e7f8:	17000003 */ 	bnez	$t8,.L0003e808
/*    3e7fc:	00000000 */ 	nop
/*    3e800:	1000002c */ 	b	.L0003e8b4
/*    3e804:	00001025 */ 	or	$v0,$zero,$zero
.L0003e808:
/*    3e808:	afa0000c */ 	sw	$zero,0xc($sp)
.L0003e80c:
/*    3e80c:	8c990004 */ 	lw	$t9,0x4($a0)
/*    3e810:	8fa8000c */ 	lw	$t0,0xc($sp)
/*    3e814:	01194806 */ 	srlv	$t1,$t9,$t0
/*    3e818:	312a0001 */ 	andi	$t2,$t1,0x1
/*    3e81c:	11400019 */ 	beqz	$t2,.L0003e884
/*    3e820:	00000000 */ 	nop
/*    3e824:	8c8b0014 */ 	lw	$t3,0x14($a0)
/*    3e828:	11600009 */ 	beqz	$t3,.L0003e850
/*    3e82c:	00000000 */ 	nop
/*    3e830:	8fac000c */ 	lw	$t4,0xc($sp)
/*    3e834:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3e838:	000c6880 */ 	sll	$t5,$t4,0x2
/*    3e83c:	008d7021 */ 	addu	$t6,$a0,$t5
/*    3e840:	8dcf00b8 */ 	lw	$t7,0xb8($t6)
/*    3e844:	008d4021 */ 	addu	$t0,$a0,$t5
/*    3e848:	01f8c823 */ 	subu	$t9,$t7,$t8
/*    3e84c:	ad1900b8 */ 	sw	$t9,0xb8($t0)
.L0003e850:
/*    3e850:	8fa9000c */ 	lw	$t1,0xc($sp)
/*    3e854:	8fae0008 */ 	lw	$t6,0x8($sp)
/*    3e858:	00095080 */ 	sll	$t2,$t1,0x2
/*    3e85c:	008a5821 */ 	addu	$t3,$a0,$t2
/*    3e860:	8d6c00b8 */ 	lw	$t4,0xb8($t3)
/*    3e864:	018e082b */ 	sltu	$at,$t4,$t6
/*    3e868:	10200006 */ 	beqz	$at,.L0003e884
/*    3e86c:	00000000 */ 	nop
/*    3e870:	8faf000c */ 	lw	$t7,0xc($sp)
/*    3e874:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3e878:	00986821 */ 	addu	$t5,$a0,$t8
/*    3e87c:	8db900b8 */ 	lw	$t9,0xb8($t5)
/*    3e880:	afb90008 */ 	sw	$t9,0x8($sp)
.L0003e884:
/*    3e884:	8fa8000c */ 	lw	$t0,0xc($sp)
/*    3e888:	25090001 */ 	addiu	$t1,$t0,0x1
/*    3e88c:	2d210010 */ 	sltiu	$at,$t1,0x10
/*    3e890:	1420ffde */ 	bnez	$at,.L0003e80c
/*    3e894:	afa9000c */ 	sw	$t1,0xc($sp)
/*    3e898:	ac800014 */ 	sw	$zero,0x14($a0)
/*    3e89c:	8faa0008 */ 	lw	$t2,0x8($sp)
/*    3e8a0:	acaa0000 */ 	sw	$t2,0x0($a1)
/*    3e8a4:	10000003 */ 	b	.L0003e8b4
/*    3e8a8:	24020001 */ 	addiu	$v0,$zero,0x1
/*    3e8ac:	10000001 */ 	b	.L0003e8b4
/*    3e8b0:	00000000 */ 	nop
.L0003e8b4:
/*    3e8b4:	03e00008 */ 	jr	$ra
/*    3e8b8:	27bd0010 */ 	addiu	$sp,$sp,0x10
);
