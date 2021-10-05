#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel bzero
	slti  $at, $a1, 0xc
	bnez  $at, .L0004b13c
	negu  $v1, $a0
	andi  $v1, $v1, 0x3
	beqz  $v1, .L0004b0e0
	subu  $a1, $a1, $v1
	swl   $zero, 0x0($a0)
	addu  $a0, $a0, $v1
.L0004b0e0:
	addiu $at, $zero, -32
	and   $a3, $a1, $at
	beqz  $a3, .L0004b11c
	subu  $a1, $a1, $a3
	addu  $a3, $a3, $a0
.L0004b0f4:
	addiu $a0, $a0, 0x20
	sw    $zero, -0x20($a0)
	sw    $zero, -0x1c($a0)
	sw    $zero, -0x18($a0)
	sw    $zero, -0x14($a0)
	sw    $zero, -0x10($a0)
	sw    $zero, -0xc($a0)
	sw    $zero, -0x8($a0)
	bne   $a0, $a3, .L0004b0f4
	sw    $zero, -0x4($a0)
.L0004b11c:
	addiu $at, $zero, -4
	and   $a3, $a1, $at
	beqz  $a3, .L0004b13c
	subu  $a1, $a1, $a3
	addu  $a3, $a3, $a0
.L0004b130:
	addiu $a0, $a0, 0x4
	bne   $a0, $a3, .L0004b130
	sw    $zero, -0x4($a0)
.L0004b13c:
	blez  $a1, .L0004b154
 	nop
	addu  $a1, $a1, $a0
.L0004b148:
	addiu $a0, $a0, 0x1
	bne   $a0, $a1, .L0004b148
	sb    $zero, -0x1($a0)
.L0004b154:
	jr    $ra
 	nop
