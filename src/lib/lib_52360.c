#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/lib_06100.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func00052360
/*    52360:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    52364:	afb0001c */ 	sw	$s0,0x1c($sp)
/*    52368:	30b000ff */ 	andi	$s0,$a1,0xff
/*    5236c:	afb10020 */ 	sw	$s1,0x20($sp)
/*    52370:	2a010003 */ 	slti	$at,$s0,0x3
/*    52374:	00808825 */ 	or	$s1,$a0,$zero
/*    52378:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    5237c:	14200003 */ 	bnez	$at,.L0005238c
/*    52380:	afa5005c */ 	sw	$a1,0x5c($sp)
/*    52384:	10000025 */ 	b	.L0005241c
/*    52388:	24020005 */ 	addiu	$v0,$zero,0x5
.L0005238c:
/*    5238c:	27a20030 */ 	addiu	$v0,$sp,0x30
/*    52390:	27a30050 */ 	addiu	$v1,$sp,0x50
.L00052394:
/*    52394:	24420004 */ 	addiu	$v0,$v0,0x4
/*    52398:	a050fffc */ 	sb	$s0,-0x4($v0)
/*    5239c:	a050fffd */ 	sb	$s0,-0x3($v0)
/*    523a0:	a050fffe */ 	sb	$s0,-0x2($v0)
/*    523a4:	1443fffb */ 	bne	$v0,$v1,.L00052394
/*    523a8:	a050ffff */ 	sb	$s0,-0x1($v0)
/*    523ac:	8e240004 */ 	lw	$a0,0x4($s1)
/*    523b0:	8e250008 */ 	lw	$a1,0x8($s1)
/*    523b4:	afa00010 */ 	sw	$zero,0x10($sp)
/*    523b8:	24060500 */ 	addiu	$a2,$zero,0x500
/*    523bc:	0c012d84 */ 	jal	__osContRamWrite
/*    523c0:	27a70030 */ 	addiu	$a3,$sp,0x30
/*    523c4:	24010002 */ 	addiu	$at,$zero,0x2
/*    523c8:	14410011 */ 	bne	$v0,$at,.L00052410
/*    523cc:	00401825 */ 	or	$v1,$v0,$zero
/*    523d0:	8e240004 */ 	lw	$a0,0x4($s1)
/*    523d4:	02202825 */ 	or	$a1,$s1,$zero
/*    523d8:	0c001840 */ 	jal	func00006100
/*    523dc:	8e260008 */ 	lw	$a2,0x8($s1)
/*    523e0:	1440000b */ 	bnez	$v0,.L00052410
/*    523e4:	00401825 */ 	or	$v1,$v0,$zero
/*    523e8:	8e240004 */ 	lw	$a0,0x4($s1)
/*    523ec:	8e250008 */ 	lw	$a1,0x8($s1)
/*    523f0:	afa00010 */ 	sw	$zero,0x10($sp)
/*    523f4:	24060500 */ 	addiu	$a2,$zero,0x500
/*    523f8:	0c012d84 */ 	jal	__osContRamWrite
/*    523fc:	27a70030 */ 	addiu	$a3,$sp,0x30
/*    52400:	24010002 */ 	addiu	$at,$zero,0x2
/*    52404:	14410002 */ 	bne	$v0,$at,.L00052410
/*    52408:	00401825 */ 	or	$v1,$v0,$zero
/*    5240c:	24030004 */ 	addiu	$v1,$zero,0x4
.L00052410:
/*    52410:	14600002 */ 	bnez	$v1,.L0005241c
/*    52414:	00601025 */ 	or	$v0,$v1,$zero
/*    52418:	a2300064 */ 	sb	$s0,0x64($s1)
.L0005241c:
/*    5241c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    52420:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*    52424:	8fb10020 */ 	lw	$s1,0x20($sp)
/*    52428:	03e00008 */ 	jr	$ra
/*    5242c:	27bd0058 */ 	addiu	$sp,$sp,0x58
);