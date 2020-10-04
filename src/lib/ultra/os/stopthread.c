#include <libultra_internal.h>

GLOBAL_ASM(
glabel osStopThread
/*    48370:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    48374:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    48378:	afa40038 */ 	sw	$a0,0x38($sp)
/*    4837c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    48380:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    48384:	0c01256c */ 	jal	__osDisableInt
/*    48388:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4838c:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    48390:	00408025 */ 	or	$s0,$v0,$zero
/*    48394:	15c00003 */ 	bnez	$t6,.L000483a4
/*    48398:	00000000 */ 	nop
/*    4839c:	10000003 */ 	b	.L000483ac
/*    483a0:	24110004 */ 	addiu	$s1,$zero,0x4
.L000483a4:
/*    483a4:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    483a8:	95f10010 */ 	lhu	$s1,0x10($t7)
.L000483ac:
/*    483ac:	02209025 */ 	or	$s2,$s1,$zero
/*    483b0:	24010002 */ 	addiu	$at,$zero,0x2
/*    483b4:	1241000f */ 	beq	$s2,$at,.L000483f4
/*    483b8:	24010004 */ 	addiu	$at,$zero,0x4
/*    483bc:	12410005 */ 	beq	$s2,$at,.L000483d4
/*    483c0:	24010008 */ 	addiu	$at,$zero,0x8
/*    483c4:	1241000b */ 	beq	$s2,$at,.L000483f4
/*    483c8:	00000000 */ 	nop
/*    483cc:	10000010 */ 	b	.L00048410
/*    483d0:	00000000 */ 	nop
.L000483d4:
/*    483d4:	3c198006 */ 	lui	$t9,%hi(__osRunningThread)
/*    483d8:	8f390940 */ 	lw	$t9,%lo(__osRunningThread)($t9)
/*    483dc:	24180001 */ 	addiu	$t8,$zero,0x1
/*    483e0:	00002025 */ 	or	$a0,$zero,$zero
/*    483e4:	0c000ee8 */ 	jal	__osEnqueueAndYield
/*    483e8:	a7380010 */ 	sh	$t8,0x10($t9)
/*    483ec:	10000008 */ 	b	.L00048410
/*    483f0:	00000000 */ 	nop
.L000483f4:
/*    483f4:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    483f8:	24080001 */ 	addiu	$t0,$zero,0x1
/*    483fc:	a5280010 */ 	sh	$t0,0x10($t1)
/*    48400:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    48404:	8d440008 */ 	lw	$a0,0x8($t2)
/*    48408:	0c012884 */ 	jal	__osDequeueThread
/*    4840c:	01402825 */ 	or	$a1,$t2,$zero
.L00048410:
/*    48410:	0c012588 */ 	jal	__osRestoreInt
/*    48414:	02002025 */ 	or	$a0,$s0,$zero
/*    48418:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    4841c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48420:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    48424:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    48428:	03e00008 */ 	jr	$ra
/*    4842c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
