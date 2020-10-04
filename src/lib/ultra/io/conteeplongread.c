#include <libultra_internal.h>

GLOBAL_ASM(
glabel osEepromLongRead
/*    503f0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    503f4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    503f8:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    503fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    50400:	afa40020 */ 	sw	$a0,0x20($sp)
/*    50404:	afa50024 */ 	sw	$a1,0x24($sp)
/*    50408:	afa60028 */ 	sw	$a2,0x28($sp)
/*    5040c:	19c00016 */ 	blez	$t6,.L00050468
/*    50410:	afa0001c */ 	sw	$zero,0x1c($sp)
.L00050414:
/*    50414:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    50418:	93a50027 */ 	lbu	$a1,0x27($sp)
/*    5041c:	0c014068 */ 	jal	osEepromRead
/*    50420:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    50424:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    50428:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    5042c:	11e00003 */ 	beqz	$t7,.L0005043c
/*    50430:	00000000 */ 	nop
/*    50434:	1000000d */ 	b	.L0005046c
/*    50438:	01e01025 */ 	or	$v0,$t7,$zero
.L0005043c:
/*    5043c:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    50440:	93a80027 */ 	lbu	$t0,0x27($sp)
/*    50444:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    50448:	2719fff8 */ 	addiu	$t9,$t8,-8
/*    5044c:	afb9002c */ 	sw	$t9,0x2c($sp)
/*    50450:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    50454:	25090001 */ 	addiu	$t1,$t0,0x1
/*    50458:	254b0008 */ 	addiu	$t3,$t2,0x8
/*    5045c:	a3a90027 */ 	sb	$t1,0x27($sp)
/*    50460:	1d80ffec */ 	bgtz	$t4,.L00050414
/*    50464:	afab0028 */ 	sw	$t3,0x28($sp)
.L00050468:
/*    50468:	8fa2001c */ 	lw	$v0,0x1c($sp)
.L0005046c:
/*    5046c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    50470:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    50474:	03e00008 */ 	jr	$ra
/*    50478:	00000000 */ 	nop
/*    5047c:	00000000 */ 	nop
);
