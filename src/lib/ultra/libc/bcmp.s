#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel bcmp
	slti  $at, $a2, 0x10
	bnez  $at, .L0004e174
	xor   $v0, $a0, $a1
	andi  $v0, $v0, 0x3
	bnez  $v0, .L0004e108
	negu  $t8, $a0
	andi  $t8, $t8, 0x3
	beqz  $t8, .L0004e0cc
	subu  $a2, $a2, $t8
	or    $v0, $v1, $zero
	lwl   $v0, 0x0($a0)
	lwl   $v1, 0x0($a1)
	addu  $a0, $a0, $t8
	addu  $a1, $a1, $t8
	bne   $v0, $v1, .L0004e1a4
.L0004e0cc:
	addiu $at, $zero, -4
	and   $a3, $a2, $at
	beqz  $a3, .L0004e174
	subu  $a2, $a2, $a3
	addu  $a3, $a3, $a0
	lw    $v0, 0x0($a0)
.L0004e0e4:
	lw    $v1, 0x0($a1)
	addiu $a0, $a0, 0x4
	addiu $a1, $a1, 0x4
	bne   $v0, $v1, .L0004e1a4
 	nop
	bnel  $a0, $a3, .L0004e0e4
	lw    $v0, 0x0($a0)
	b     .L0004e174
 	nop
.L0004e108:
	negu  $a3, $a1
	andi  $a3, $a3, 0x3
	beqz  $a3, .L0004e13c
	subu  $a2, $a2, $a3
	addu  $a3, $a3, $a0
	lbu   $v0, 0x0($a0)
.L0004e120:
	lbu   $v1, 0x0($a1)
	addiu $a0, $a0, 0x1
	addiu $a1, $a1, 0x1
	bne   $v0, $v1, .L0004e1a4
 	nop
	bnel  $a0, $a3, .L0004e120
	lbu   $v0, 0x0($a0)
.L0004e13c:
	addiu $at, $zero, -4
	and   $a3, $a2, $at
	beqz  $a3, .L0004e174
	subu  $a2, $a2, $a3
	addu  $a3, $a3, $a0
	lwl   $v0, 0x0($a0)
.L0004e154:
	lw    $v1, 0x0($a1)
	lwr   $v0, 0x3($a0)
	addiu $a0, $a0, 0x4
	addiu $a1, $a1, 0x4
	bne   $v0, $v1, .L0004e1a4
 	nop
	bnel  $a0, $a3, .L0004e154
	lwl   $v0, 0x0($a0)
.L0004e174:
	blez  $a2, .L0004e19c
	addu  $a3, $a2, $a0
	lbu   $v0, 0x0($a0)
.L0004e180:
	lbu   $v1, 0x0($a1)
	addiu $a0, $a0, 0x1
	addiu $a1, $a1, 0x1
	bne   $v0, $v1, .L0004e1a4
 	nop
	bnel  $a0, $a3, .L0004e180
	lbu   $v0, 0x0($a0)
.L0004e19c:
	jr    $ra
	or    $v0, $zero, $zero
.L0004e1a4:
	jr    $ra
	addiu $v0, $zero, 0x1
