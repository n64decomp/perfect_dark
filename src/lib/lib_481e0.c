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
#include "lib/lib_034f0.h"
#include "lib/lib_491b0.h"
#include "lib/lib_49c20.h"
#include "types.h"

GLOBAL_ASM(
glabel __osSetFpcCsr
/*    481e0:	4442f800 */ 	cfc1	$v0,$31
/*    481e4:	44c4f800 */ 	ctc1	$a0,$31
/*    481e8:	03e00008 */ 	jr	$ra
/*    481ec:	00000000 */ 	nop
);

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

GLOBAL_ASM(
glabel osCreateMesgQueue
/*    48340:	3c0e8006 */ 	lui	$t6,%hi(var80060930)
/*    48344:	3c0f8006 */ 	lui	$t7,%hi(var80060930)
/*    48348:	25ce0930 */ 	addiu	$t6,$t6,%lo(var80060930)
/*    4834c:	25ef0930 */ 	addiu	$t7,$t7,%lo(var80060930)
/*    48350:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*    48354:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*    48358:	ac800008 */ 	sw	$zero,0x8($a0)
/*    4835c:	ac80000c */ 	sw	$zero,0xc($a0)
/*    48360:	ac860010 */ 	sw	$a2,0x10($a0)
/*    48364:	03e00008 */ 	jr	$ra
/*    48368:	ac850014 */ 	sw	$a1,0x14($a0)
/*    4836c:	00000000 */ 	nop
);

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
/*    484c0:	3c0f8006 */ 	lui	$t7,%hi(var80060938)
/*    484c4:	8def0938 */ 	lw	$t7,%lo(var80060938)($t7)
/*    484c8:	8dad0940 */ 	lw	$t5,%lo(__osRunningThread)($t5)
/*    484cc:	8df90004 */ 	lw	$t9,0x4($t7)
/*    484d0:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    484d4:	01d9082a */ 	slt	$at,$t6,$t9
/*    484d8:	10200006 */ 	beqz	$at,.L000484f4
/*    484dc:	00000000 */ 	nop
/*    484e0:	24080002 */ 	addiu	$t0,$zero,0x2
/*    484e4:	3c048006 */ 	lui	$a0,%hi(var80060938)
/*    484e8:	a5a80010 */ 	sh	$t0,0x10($t5)
/*    484ec:	0c000ee8 */ 	jal	__osEnqueueAndYield
/*    484f0:	24840938 */ 	addiu	$a0,$a0,%lo(var80060938)
.L000484f4:
/*    484f4:	0c012588 */ 	jal	__osRestoreInt
/*    484f8:	02002025 */ 	or	$a0,$s0,$zero
/*    484fc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48500:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48504:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    48508:	03e00008 */ 	jr	$ra
/*    4850c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel osGetCount
/*    48510:	40024800 */ 	mfc0	$v0,$9
/*    48514:	03e00008 */ 	jr	$ra
/*    48518:	00000000 */ 	nop
/*    4851c:	00000000 */ 	nop
);