#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osDestroyThread
/*    4a250:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    4a254:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    4a258:	afa40038 */ 	sw	$a0,0x38($sp)
/*    4a25c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    4a260:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    4a264:	0c01256c */ 	jal	__osDisableInt
/*    4a268:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4a26c:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    4a270:	00408025 */ 	or	$s0,$v0,$zero
/*    4a274:	15c00005 */ 	bnez	$t6,.L0004a28c
/*    4a278:	00000000 */ 	nop
/*    4a27c:	3c0f8006 */ 	lui	$t7,%hi(__osRunningThread)
/*    4a280:	8def0940 */ 	lw	$t7,%lo(__osRunningThread)($t7)
/*    4a284:	10000009 */ 	b	.L0004a2ac
/*    4a288:	afaf0038 */ 	sw	$t7,0x38($sp)
.L0004a28c:
/*    4a28c:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    4a290:	24010001 */ 	addiu	$at,$zero,0x1
/*    4a294:	97190010 */ 	lhu	$t9,0x10($t8)
/*    4a298:	13210004 */ 	beq	$t9,$at,.L0004a2ac
/*    4a29c:	00000000 */ 	nop
/*    4a2a0:	8f040008 */ 	lw	$a0,0x8($t8)
/*    4a2a4:	0c012884 */ 	jal	__osDequeueThread
/*    4a2a8:	03002825 */ 	or	$a1,$t8,$zero
.L0004a2ac:
/*    4a2ac:	3c088006 */ 	lui	$t0,%hi(__osActiveQueue)
/*    4a2b0:	8d08093c */ 	lw	$t0,%lo(__osActiveQueue)($t0)
/*    4a2b4:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    4a2b8:	15090005 */ 	bne	$t0,$t1,.L0004a2d0
/*    4a2bc:	00000000 */ 	nop
/*    4a2c0:	8d0a000c */ 	lw	$t2,0xc($t0)
/*    4a2c4:	3c018006 */ 	lui	$at,%hi(__osActiveQueue)
/*    4a2c8:	10000013 */ 	b	.L0004a318
/*    4a2cc:	ac2a093c */ 	sw	$t2,%lo(__osActiveQueue)($at)
.L0004a2d0:
/*    4a2d0:	3c118006 */ 	lui	$s1,%hi(__osActiveQueue)
/*    4a2d4:	8e31093c */ 	lw	$s1,%lo(__osActiveQueue)($s1)
/*    4a2d8:	2401ffff */ 	addiu	$at,$zero,-1
/*    4a2dc:	8e2b0004 */ 	lw	$t3,0x4($s1)
/*    4a2e0:	1161000d */ 	beq	$t3,$at,.L0004a318
/*    4a2e4:	00000000 */ 	nop
.L0004a2e8:
/*    4a2e8:	8e32000c */ 	lw	$s2,0xc($s1)
/*    4a2ec:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    4a2f0:	164c0004 */ 	bne	$s2,$t4,.L0004a304
/*    4a2f4:	00000000 */ 	nop
/*    4a2f8:	8d8d000c */ 	lw	$t5,0xc($t4)
/*    4a2fc:	10000006 */ 	b	.L0004a318
/*    4a300:	ae2d000c */ 	sw	$t5,0xc($s1)
.L0004a304:
/*    4a304:	02408825 */ 	or	$s1,$s2,$zero
/*    4a308:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*    4a30c:	2401ffff */ 	addiu	$at,$zero,-1
/*    4a310:	15c1fff5 */ 	bne	$t6,$at,.L0004a2e8
/*    4a314:	00000000 */ 	nop
.L0004a318:
/*    4a318:	3c198006 */ 	lui	$t9,%hi(__osRunningThread)
/*    4a31c:	8f390940 */ 	lw	$t9,%lo(__osRunningThread)($t9)
/*    4a320:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    4a324:	15f90003 */ 	bne	$t7,$t9,.L0004a334
/*    4a328:	00000000 */ 	nop
/*    4a32c:	0c000f44 */ 	jal	__osDispatchThread
/*    4a330:	00000000 */ 	nop
.L0004a334:
/*    4a334:	0c012588 */ 	jal	__osRestoreInt
/*    4a338:	02002025 */ 	or	$a0,$s0,$zero
/*    4a33c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    4a340:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4a344:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    4a348:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    4a34c:	03e00008 */ 	jr	$ra
/*    4a350:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    4a354:	00000000 */ 	nop
/*    4a358:	00000000 */ 	nop
/*    4a35c:	00000000 */ 	nop
);
