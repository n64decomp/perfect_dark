#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/lib_44bc0.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003c430
/*    3c430:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3c434:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c438:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3c43c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    3c440:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3c444:	afae0024 */ 	sw	$t6,0x24($sp)
/*    3c448:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    3c44c:	0c0112f0 */ 	jal	func00044bc0
/*    3c450:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    3c454:	afa20024 */ 	sw	$v0,0x24($sp)
/*    3c458:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3c45c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*    3c460:	afb80024 */ 	sw	$t8,0x24($sp)
/*    3c464:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    3c468:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3c46c:	3c190d00 */ 	lui	$t9,0xd00
/*    3c470:	ad190000 */ 	sw	$t9,0x0($t0)
/*    3c474:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3c478:	252a0008 */ 	addiu	$t2,$t1,0x8
/*    3c47c:	afaa0024 */ 	sw	$t2,0x24($sp)
/*    3c480:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    3c484:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    3c488:	3c0b062e */ 	lui	$t3,0x62e
/*    3c48c:	ad8b0000 */ 	sw	$t3,0x0($t4)
/*    3c490:	3c0d8006 */ 	lui	$t5,%hi(var8005f114)
/*    3c494:	8dadf114 */ 	lw	$t5,%lo(var8005f114)($t5)
/*    3c498:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3c49c:	8dae0048 */ 	lw	$t6,0x48($t5)
/*    3c4a0:	adee0004 */ 	sw	$t6,0x4($t7)
/*    3c4a4:	10000003 */ 	b	.L0003c4b4
/*    3c4a8:	8fa20024 */ 	lw	$v0,0x24($sp)
/*    3c4ac:	10000001 */ 	b	.L0003c4b4
/*    3c4b0:	00000000 */ 	nop
.L0003c4b4:
/*    3c4b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c4b8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3c4bc:	03e00008 */ 	jr	$ra
/*    3c4c0:	00000000 */ 	nop
/*    3c4c4:	00000000 */ 	nop
/*    3c4c8:	00000000 */ 	nop
/*    3c4cc:	00000000 */ 	nop
);