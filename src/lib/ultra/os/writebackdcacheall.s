#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel osWritebackDCacheAll
	lui   $t0, 0x8000
	addiu $t2, $zero, 0x2000
	addu  $t1, $t0, $t2
	addiu $t1, $t1, -16
.L00048130:
	cache 0x1, 0x0($t0)
	sltu  $at, $t0, $t1
	bnez  $at, .L00048130
	addiu $t0, $t0, 0x10
	jr    $ra
 	nop
