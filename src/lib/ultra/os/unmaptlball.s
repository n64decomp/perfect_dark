#include "asm_helper.h"
#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel osUnmapTLBAll
	mfc0  $t0, C0_ENTRYHI
	li    $t1, 30
	lui   $t2, 0x8000
	mtc0  $t2, C0_ENTRYHI
	mtc0  $zero, C0_ENTRYLO0
	mtc0  $zero, C0_ENTRYLO1
.PF00052098:
	mtc0  $t1, C0_INX
 	nop
 	tlbwi
 	nop
 	nop
	addi  $t1, $t1, -1
	bgez  $t1, .PF00052098
 	nop
	mtc0  $t0, C0_ENTRYHI
	jr    $ra
 	nop
