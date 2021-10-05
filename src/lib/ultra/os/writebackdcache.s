#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel osWritebackDCache
	blez  $a1, .L0004adc8
 	nop
	addiu $t3, $zero, 0x2000
	sltu  $at, $a1, $t3
	beqz  $at, .L0004add0
 	nop
	move  $t0, $a0
	addu  $t1, $a0, $a1
	sltu  $at, $t0, $t1
	beqz  $at, .L0004adc8
 	nop
	andi  $t2, $t0, 0xf
	addiu $t1, $t1, -16
	subu  $t0, $t0, $t2
.L0004adb8:
	cache 0x19, 0x0($t0)
	sltu  $at, $t0, $t1
	bnez  $at, .L0004adb8
	addiu $t0, $t0, 0x10
.L0004adc8:
	jr    $ra
 	nop
.L0004add0:
	lui   $t0, 0x8000
	addu  $t1, $t0, $t3
	addiu $t1, $t1, -16
.L0004addc:
	cache 0x1, 0x0($t0)
	sltu  $at, $t0, $t1
	bnez  $at, .L0004addc
	addiu $t0, $t0, 0x10
	jr    $ra
 	nop
