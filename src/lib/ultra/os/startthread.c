#include <libultra_internal.h>

GLOBAL_ASM(
glabel osStartThread
/*    481f0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    481f4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    481f8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    481fc:	afb10018 */ 	sw	$s1,0x18($sp)
/*    48200:	0c01256c */ 	jal	__osDisableInt
/*    48204:	afb00014 */ 	sw	$s0,0x14($sp)
/*    48208:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    4820c:	24010001 */ 	addiu	$at,$zero,0x1
/*    48210:	00408025 */ 	or	$s0,$v0,$zero
/*    48214:	95d10010 */ 	lhu	$s1,0x10($t6)
/*    48218:	1221000c */ 	beq	$s1,$at,.L0004824c
/*    4821c:	24010008 */ 	addiu	$at,$zero,0x8
/*    48220:	1621002a */ 	bne	$s1,$at,.L000482cc
/*    48224:	00000000 */ 	nop
/*    48228:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    4822c:	240f0002 */ 	addiu	$t7,$zero,0x2
/*    48230:	3c048006 */ 	lui	$a0,%hi(var80060938)
/*    48234:	a70f0010 */ 	sh	$t7,0x10($t8)
/*    48238:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    4823c:	0c000f2e */ 	jal	__osEnqueueThread
/*    48240:	24840938 */ 	addiu	$a0,$a0,%lo(var80060938)
/*    48244:	10000021 */ 	b	.L000482cc
/*    48248:	00000000 */ 	nop
.L0004824c:
/*    4824c:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    48250:	8f280008 */ 	lw	$t0,0x8($t9)
/*    48254:	11000005 */ 	beqz	$t0,.L0004826c
/*    48258:	00000000 */ 	nop
/*    4825c:	3c098006 */ 	lui	$t1,%hi(var80060938)
/*    48260:	25290938 */ 	addiu	$t1,$t1,%lo(var80060938)
/*    48264:	1509000a */ 	bne	$t0,$t1,.L00048290
/*    48268:	00000000 */ 	nop
.L0004826c:
/*    4826c:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    48270:	240a0002 */ 	addiu	$t2,$zero,0x2
/*    48274:	3c048006 */ 	lui	$a0,%hi(var80060938)
/*    48278:	a56a0010 */ 	sh	$t2,0x10($t3)
/*    4827c:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    48280:	0c000f2e */ 	jal	__osEnqueueThread
/*    48284:	24840938 */ 	addiu	$a0,$a0,%lo(var80060938)
/*    48288:	10000010 */ 	b	.L000482cc
/*    4828c:	00000000 */ 	nop
.L00048290:
/*    48290:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    48294:	240c0008 */ 	addiu	$t4,$zero,0x8
/*    48298:	a5ac0010 */ 	sh	$t4,0x10($t5)
/*    4829c:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    482a0:	8dc40008 */ 	lw	$a0,0x8($t6)
/*    482a4:	0c000f2e */ 	jal	__osEnqueueThread
/*    482a8:	01c02825 */ 	or	$a1,$t6,$zero
/*    482ac:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    482b0:	0c000f40 */ 	jal	__osPopThread
/*    482b4:	8de40008 */ 	lw	$a0,0x8($t7)
/*    482b8:	00408825 */ 	or	$s1,$v0,$zero
/*    482bc:	3c048006 */ 	lui	$a0,%hi(var80060938)
/*    482c0:	24840938 */ 	addiu	$a0,$a0,%lo(var80060938)
/*    482c4:	0c000f2e */ 	jal	__osEnqueueThread
/*    482c8:	02202825 */ 	or	$a1,$s1,$zero
.L000482cc:
/*    482cc:	3c188006 */ 	lui	$t8,%hi(__osRunningThread)
/*    482d0:	8f180940 */ 	lw	$t8,%lo(__osRunningThread)($t8)
/*    482d4:	17000005 */ 	bnez	$t8,.L000482ec
/*    482d8:	00000000 */ 	nop
/*    482dc:	0c000f44 */ 	jal	__osDispatchThread
/*    482e0:	00000000 */ 	nop
/*    482e4:	1000000f */ 	b	.L00048324
/*    482e8:	00000000 */ 	nop
.L000482ec:
/*    482ec:	3c198006 */ 	lui	$t9,%hi(__osRunningThread)
/*    482f0:	3c098006 */ 	lui	$t1,%hi(var80060938)
/*    482f4:	8d290938 */ 	lw	$t1,%lo(var80060938)($t1)
/*    482f8:	8f390940 */ 	lw	$t9,%lo(__osRunningThread)($t9)
/*    482fc:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    48300:	8f280004 */ 	lw	$t0,0x4($t9)
/*    48304:	010a082a */ 	slt	$at,$t0,$t2
/*    48308:	10200006 */ 	beqz	$at,.L00048324
/*    4830c:	00000000 */ 	nop
/*    48310:	240b0002 */ 	addiu	$t3,$zero,0x2
/*    48314:	3c048006 */ 	lui	$a0,%hi(var80060938)
/*    48318:	a72b0010 */ 	sh	$t3,0x10($t9)
/*    4831c:	0c000ee8 */ 	jal	__osEnqueueAndYield
/*    48320:	24840938 */ 	addiu	$a0,$a0,%lo(var80060938)
.L00048324:
/*    48324:	0c012588 */ 	jal	__osRestoreInt
/*    48328:	02002025 */ 	or	$a0,$s0,$zero
/*    4832c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48330:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    48334:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    48338:	03e00008 */ 	jr	$ra
/*    4833c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
