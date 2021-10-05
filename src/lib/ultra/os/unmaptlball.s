#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel osUnmapTLBAll
	mfc0  $t0, $10
	li    $t1, 0x1e
	lui   $t2, 0x8000
	mtc0  $t2, $10
	mtc0  $zero, $2
	mtc0  $zero, $3
.PF00052098:
	mtc0  $t1, $0
 	nop
 	tlbwi
 	nop
 	nop
	addi  $t1, $t1, -1
	bgez  $t1, .PF00052098
 	nop
	mtc0  $t0, $10
	jr    $ra
 	nop
