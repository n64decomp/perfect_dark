#include <libultra_internal.h>

GLOBAL_ASM(
glabel osSetThreadPri
/*    48430:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    48434:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48438:	afa40028 */ 	sw	$a0,0x28($sp)
/*    4843c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    48440:	0c01256c */ 	jal	__osDisableInt
/*    48444:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48448:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    4844c:	00408025 */ 	or	$s0,$v0,$zero
/*    48450:	15c00004 */ 	bnez	$t6,.L00048464
/*    48454:	00000000 */ 	nop
/*    48458:	3c0f8006 */ 	lui	$t7,%hi(__osRunningThread)
/*    4845c:	8def0940 */ 	lw	$t7,%lo(__osRunningThread)($t7)
/*    48460:	afaf0028 */ 	sw	$t7,0x28($sp)
.L00048464:
/*    48464:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    48468:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    4846c:	8f190004 */ 	lw	$t9,0x4($t8)
/*    48470:	13280020 */ 	beq	$t9,$t0,.L000484f4
/*    48474:	00000000 */ 	nop
/*    48478:	af080004 */ 	sw	$t0,0x4($t8)
/*    4847c:	3c0a8006 */ 	lui	$t2,%hi(__osRunningThread)
/*    48480:	8d4a0940 */ 	lw	$t2,%lo(__osRunningThread)($t2)
/*    48484:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    48488:	112a000c */ 	beq	$t1,$t2,.L000484bc
/*    4848c:	00000000 */ 	nop
/*    48490:	952b0010 */ 	lhu	$t3,0x10($t1)
/*    48494:	24010001 */ 	addiu	$at,$zero,0x1
/*    48498:	11610008 */ 	beq	$t3,$at,.L000484bc
/*    4849c:	00000000 */ 	nop
/*    484a0:	8d240008 */ 	lw	$a0,0x8($t1)
/*    484a4:	0c012884 */ 	jal	__osDequeueThread
/*    484a8:	01202825 */ 	or	$a1,$t1,$zero
/*    484ac:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    484b0:	8d840008 */ 	lw	$a0,0x8($t4)
/*    484b4:	0c000f2e */ 	jal	__osEnqueueThread
/*    484b8:	01802825 */ 	or	$a1,$t4,$zero
.L000484bc:
/*    484bc:	3c0d8006 */ 	lui	$t5,%hi(__osRunningThread)
/*    484c0:	3c0f8006 */ 	lui	$t7,%hi(__osRunQueue)
/*    484c4:	8def0938 */ 	lw	$t7,%lo(__osRunQueue)($t7)
/*    484c8:	8dad0940 */ 	lw	$t5,%lo(__osRunningThread)($t5)
/*    484cc:	8df90004 */ 	lw	$t9,0x4($t7)
/*    484d0:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    484d4:	01d9082a */ 	slt	$at,$t6,$t9
/*    484d8:	10200006 */ 	beqz	$at,.L000484f4
/*    484dc:	00000000 */ 	nop
/*    484e0:	24080002 */ 	addiu	$t0,$zero,0x2
/*    484e4:	3c048006 */ 	lui	$a0,%hi(__osRunQueue)
/*    484e8:	a5a80010 */ 	sh	$t0,0x10($t5)
/*    484ec:	0c000ee8 */ 	jal	__osEnqueueAndYield
/*    484f0:	24840938 */ 	addiu	$a0,$a0,%lo(__osRunQueue)
.L000484f4:
/*    484f4:	0c012588 */ 	jal	__osRestoreInt
/*    484f8:	02002025 */ 	or	$a0,$s0,$zero
/*    484fc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48500:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48504:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    48508:	03e00008 */ 	jr	$ra
/*    4850c:	00000000 */ 	nop
);
