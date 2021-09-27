#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel osGbpakPower
/*     6330:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*     6334:	afb10028 */ 	sw	$s1,0x28($sp)
/*     6338:	afb00024 */ 	sw	$s0,0x24($sp)
/*     633c:	00a08025 */ 	or	$s0,$a1,$zero
/*     6340:	00808825 */ 	or	$s1,$a0,$zero
/*     6344:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     6348:	27a20038 */ 	addiu	$v0,$sp,0x38
/*     634c:	27a30058 */ 	addiu	$v1,$sp,0x58
.L00006350:
/*     6350:	24420001 */ 	addiu	$v0,$v0,0x1
/*     6354:	1443fffe */ 	bne	$v0,$v1,.L00006350
/*     6358:	a050ffff */ 	sb	$s0,-0x1($v0)
/*     635c:	8e240004 */ 	lw	$a0,0x4($s1)
/*     6360:	8e250008 */ 	lw	$a1,0x8($s1)
/*     6364:	afa00010 */ 	sw	$zero,0x10($sp)
/*     6368:	24060580 */ 	addiu	$a2,$zero,0x580
/*     636c:	0c012d84 */ 	jal	__osContRamWrite
/*     6370:	27a70038 */ 	addiu	$a3,$sp,0x38
/*     6374:	24010002 */ 	addiu	$at,$zero,0x2
/*     6378:	14410011 */ 	bne	$v0,$at,.L000063c0
/*     637c:	00401825 */ 	or	$v1,$v0,$zero
/*     6380:	8e240004 */ 	lw	$a0,0x4($s1)
/*     6384:	02202825 */ 	or	$a1,$s1,$zero
/*     6388:	0c001840 */ 	jal	osGbpakInit
/*     638c:	8e260008 */ 	lw	$a2,0x8($s1)
/*     6390:	1440000b */ 	bnez	$v0,.L000063c0
/*     6394:	00401825 */ 	or	$v1,$v0,$zero
/*     6398:	8e240004 */ 	lw	$a0,0x4($s1)
/*     639c:	8e250008 */ 	lw	$a1,0x8($s1)
/*     63a0:	afa00010 */ 	sw	$zero,0x10($sp)
/*     63a4:	24060580 */ 	addiu	$a2,$zero,0x580
/*     63a8:	0c012d84 */ 	jal	__osContRamWrite
/*     63ac:	27a70038 */ 	addiu	$a3,$sp,0x38
/*     63b0:	24010002 */ 	addiu	$at,$zero,0x2
/*     63b4:	14410002 */ 	bne	$v0,$at,.L000063c0
/*     63b8:	00401825 */ 	or	$v1,$v0,$zero
/*     63bc:	24030004 */ 	addiu	$v1,$zero,0x4
.L000063c0:
/*     63c0:	12000016 */ 	beqz	$s0,.L0000641c
/*     63c4:	3c048009 */ 	lui	$a0,%hi(var80090ab0)
/*     63c8:	3c108009 */ 	lui	$s0,%hi(var80090ad0)
/*     63cc:	3c188009 */ 	lui	$t8,%hi(var80090ae8)
/*     63d0:	26100ad0 */ 	addiu	$s0,$s0,%lo(var80090ad0)
/*     63d4:	27180ae8 */ 	addiu	$t8,$t8,%lo(var80090ae8)
/*     63d8:	3c07000e */ 	lui	$a3,0xe
/*     63dc:	240e0000 */ 	addiu	$t6,$zero,0x0
/*     63e0:	240f0000 */ 	addiu	$t7,$zero,0x0
/*     63e4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     63e8:	afae0010 */ 	sw	$t6,0x10($sp)
/*     63ec:	34e74e1c */ 	ori	$a3,$a3,0x4e1c
/*     63f0:	afb8001c */ 	sw	$t8,0x1c($sp)
/*     63f4:	afb00018 */ 	sw	$s0,0x18($sp)
/*     63f8:	24840ab0 */ 	addiu	$a0,$a0,%lo(var80090ab0)
/*     63fc:	24060000 */ 	addiu	$a2,$zero,0x0
/*     6400:	0c0122c8 */ 	jal	osSetTimer
/*     6404:	afa30058 */ 	sw	$v1,0x58($sp)
/*     6408:	02002025 */ 	or	$a0,$s0,$zero
/*     640c:	00002825 */ 	or	$a1,$zero,$zero
/*     6410:	0c0121bc */ 	jal	osRecvMesg
/*     6414:	24060001 */ 	addiu	$a2,$zero,0x1
/*     6418:	8fa30058 */ 	lw	$v1,0x58($sp)
.L0000641c:
/*     641c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     6420:	8fb00024 */ 	lw	$s0,0x24($sp)
/*     6424:	8fb10028 */ 	lw	$s1,0x28($sp)
/*     6428:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*     642c:	03e00008 */ 	jr	$ra
/*     6430:	00601025 */ 	or	$v0,$v1,$zero
);
