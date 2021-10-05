#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel osInvalICache
	blez  $a1, .L00048198
 	nop
	addiu $t3, $zero, 0x4000
	sltu  $at, $a1, $t3
	beqz  $at, .L000481a0
 	nop
	move  $t0, $a0
	addu  $t1, $a0, $a1
	sltu  $at, $t0, $t1
	beqz  $at, .L00048198
 	nop
	andi  $t2, $t0, 0x1f
	addiu $t1, $t1, -32
	subu  $t0, $t0, $t2
.L00048188:
	cache 0x10, 0x0($t0)
	sltu  $at, $t0, $t1
	bnez  $at, .L00048188
	addiu $t0, $t0, 0x20
.L00048198:
	jr    $ra
 	nop
.L000481a0:
	lui   $t0, 0x8000
	addu  $t1, $t0, $t3
	addiu $t1, $t1, -32
.L000481ac:
	cache 0x0, 0x0($t0)
	sltu  $at, $t0, $t1
	bnez  $at, .L000481ac
	addiu $t0, $t0, 0x20
	jr    $ra
 	nop
