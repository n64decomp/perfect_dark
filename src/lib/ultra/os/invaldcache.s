#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel osInvalDCache
	blez  $a1, .L0004e500
 	nop
	addiu $t3, $zero, 0x2000
	sltu  $at, $a1, $t3
	beqz  $at, .L0004e508
 	nop
	move  $t0, $a0
	addu  $t1, $a0, $a1
	sltu  $at, $t0, $t1
	beqz  $at, .L0004e500
 	nop
	andi  $t2, $t0, 0xf
	beqz  $t2, .L0004e4d0
	addiu $t1, $t1, -16
	subu  $t0, $t0, $t2
	cache 0x15, 0x0($t0)
	sltu  $at, $t0, $t1
	beqz  $at, .L0004e500
 	nop
	addiu $t0, $t0, 0x10
.L0004e4d0:
	andi  $t2, $t1, 0xf
	beqz  $t2, .L0004e4f0
 	nop
	subu  $t1, $t1, $t2
	cache 0x15, 0x10($t1)
	sltu  $at, $t1, $t0
	bnez  $at, .L0004e500
 	nop
.L0004e4f0:
	cache 0x11, 0x0($t0)
	sltu  $at, $t0, $t1
	bnez  $at, .L0004e4f0
	addiu $t0, $t0, 0x10
.L0004e500:
	jr    $ra
 	nop
.L0004e508:
	lui   $t0, 0x8000
	addu  $t1, $t0, $t3
	addiu $t1, $t1, -16
.L0004e514:
	cache 0x1, 0x0($t0)
	sltu  $at, $t0, $t1
	bnez  $at, .L0004e514
	addiu $t0, $t0, 0x10
	jr    $ra
 	nop
