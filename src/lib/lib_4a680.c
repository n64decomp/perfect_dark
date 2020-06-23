#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_4ae00.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004a680
/*    4a680:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    4a684:	afa40030 */ 	sw	$a0,0x30($sp)
/*    4a688:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a68c:	afa60038 */ 	sw	$a2,0x38($sp)
/*    4a690:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    4a694:	00c02025 */ 	or	$a0,$a2,$zero
/*    4a698:	00e02825 */ 	or	$a1,$a3,$zero
/*    4a69c:	8fa70044 */ 	lw	$a3,0x44($sp)
/*    4a6a0:	0c012bc3 */ 	jal	func0004af0c
/*    4a6a4:	8fa60040 */ 	lw	$a2,0x40($sp)
/*    4a6a8:	afa20020 */ 	sw	$v0,0x20($sp)
/*    4a6ac:	afa30024 */ 	sw	$v1,0x24($sp)
/*    4a6b0:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    4a6b4:	8fa50044 */ 	lw	$a1,0x44($sp)
/*    4a6b8:	00403025 */ 	or	$a2,$v0,$zero
/*    4a6bc:	0c012bda */ 	jal	func0004af68
/*    4a6c0:	00603825 */ 	or	$a3,$v1,$zero
/*    4a6c4:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    4a6c8:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    4a6cc:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    4a6d0:	01c2c023 */ 	subu	$t8,$t6,$v0
/*    4a6d4:	01e3082b */ 	sltu	$at,$t7,$v1
/*    4a6d8:	0301c023 */ 	subu	$t8,$t8,$at
/*    4a6dc:	01e3c823 */ 	subu	$t9,$t7,$v1
/*    4a6e0:	afb9002c */ 	sw	$t9,0x2c($sp)
/*    4a6e4:	afb80028 */ 	sw	$t8,0x28($sp)
/*    4a6e8:	1d000017 */ 	bgtz	$t0,.L0004a748
/*    4a6ec:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    4a6f0:	05000003 */ 	bltz	$t0,.L0004a700
/*    4a6f4:	00000000 */ 	nop
/*    4a6f8:	10000014 */ 	b	.L0004a74c
/*    4a6fc:	27a80020 */ 	addiu	$t0,$sp,0x20
.L0004a700:
/*    4a700:	07020012 */ 	bltzl	$t8,.L0004a74c
/*    4a704:	27a80020 */ 	addiu	$t0,$sp,0x20
/*    4a708:	1f000003 */ 	bgtz	$t8,.L0004a718
/*    4a70c:	252b0001 */ 	addiu	$t3,$t1,0x1
/*    4a710:	5320000e */ 	beqzl	$t9,.L0004a74c
/*    4a714:	27a80020 */ 	addiu	$t0,$sp,0x20
.L0004a718:
/*    4a718:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    4a71c:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    4a720:	2d610001 */ 	sltiu	$at,$t3,0x1
/*    4a724:	01015021 */ 	addu	$t2,$t0,$at
/*    4a728:	030c7023 */ 	subu	$t6,$t8,$t4
/*    4a72c:	032d082b */ 	sltu	$at,$t9,$t5
/*    4a730:	01c17023 */ 	subu	$t6,$t6,$at
/*    4a734:	032d7823 */ 	subu	$t7,$t9,$t5
/*    4a738:	afaa0020 */ 	sw	$t2,0x20($sp)
/*    4a73c:	afab0024 */ 	sw	$t3,0x24($sp)
/*    4a740:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    4a744:	afae0028 */ 	sw	$t6,0x28($sp)
.L0004a748:
/*    4a748:	27a80020 */ 	addiu	$t0,$sp,0x20
.L0004a74c:
/*    4a74c:	8fa20030 */ 	lw	$v0,0x30($sp)
/*    4a750:	8d010000 */ 	lw	$at,0x0($t0)
/*    4a754:	ac410000 */ 	sw	$at,0x0($v0)
/*    4a758:	8d0b0004 */ 	lw	$t3,0x4($t0)
/*    4a75c:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*    4a760:	8d010008 */ 	lw	$at,0x8($t0)
/*    4a764:	ac410008 */ 	sw	$at,0x8($v0)
/*    4a768:	8d0b000c */ 	lw	$t3,0xc($t0)
/*    4a76c:	ac4b000c */ 	sw	$t3,0xc($v0)
/*    4a770:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a774:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    4a778:	03e00008 */ 	jr	$ra
/*    4a77c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0004a780
/*    4a780:	00a6001a */ 	div	$zero,$a1,$a2
/*    4a784:	00001012 */ 	mflo	$v0
/*    4a788:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    4a78c:	14c00002 */ 	bnez	$a2,.L0004a798
/*    4a790:	00000000 */ 	nop
/*    4a794:	0007000d */ 	break	0x7
.L0004a798:
/*    4a798:	2401ffff */ 	addiu	$at,$zero,-1
/*    4a79c:	14c10004 */ 	bne	$a2,$at,.L0004a7b0
/*    4a7a0:	3c018000 */ 	lui	$at,0x8000
/*    4a7a4:	14a10002 */ 	bne	$a1,$at,.L0004a7b0
/*    4a7a8:	00000000 */ 	nop
/*    4a7ac:	0006000d */ 	break	0x6
.L0004a7b0:
/*    4a7b0:	00c20019 */ 	multu	$a2,$v0
/*    4a7b4:	afa20000 */ 	sw	$v0,0x0($sp)
/*    4a7b8:	27af0000 */ 	addiu	$t7,$sp,0x0
/*    4a7bc:	00007012 */ 	mflo	$t6
/*    4a7c0:	00ae1823 */ 	subu	$v1,$a1,$t6
/*    4a7c4:	04410008 */ 	bgez	$v0,.L0004a7e8
/*    4a7c8:	afa30004 */ 	sw	$v1,0x4($sp)
/*    4a7cc:	afa20000 */ 	sw	$v0,0x0($sp)
/*    4a7d0:	18600005 */ 	blez	$v1,.L0004a7e8
/*    4a7d4:	afa30004 */ 	sw	$v1,0x4($sp)
/*    4a7d8:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4a7dc:	00661823 */ 	subu	$v1,$v1,$a2
/*    4a7e0:	afa30004 */ 	sw	$v1,0x4($sp)
/*    4a7e4:	afa20000 */ 	sw	$v0,0x0($sp)
.L0004a7e8:
/*    4a7e8:	8de10000 */ 	lw	$at,0x0($t7)
/*    4a7ec:	00801025 */ 	or	$v0,$a0,$zero
/*    4a7f0:	ac810000 */ 	sw	$at,0x0($a0)
/*    4a7f4:	8de80004 */ 	lw	$t0,0x4($t7)
/*    4a7f8:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*    4a7fc:	03e00008 */ 	jr	$ra
/*    4a800:	ac880004 */ 	sw	$t0,0x4($a0)
/*    4a804:	00000000 */ 	nop
/*    4a808:	00000000 */ 	nop
/*    4a80c:	00000000 */ 	nop
);