#include "asm_helper.h"
#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel __osProbeTLB
	mfc0  $t0, C0_ENTRYHI
	andi  $t1, $t0, 0xff
	addiu $at, $zero, -8192
	and   $t2, $a0, $at
	or    $t1, $t1, $t2
	mtc0  $t1, C0_ENTRYHI
 	nop
 	nop
 	nop
 	tlbp
 	nop
 	nop
	mfc0  $t3, C0_INX
	lui   $at, 0x8000
	and   $t3, $t3, $at
	bnez  $t3, .L00051d38
 	nop
 	tlbr
 	nop
 	nop
 	nop
	mfc0  $t3, C0_PAGEMASK
	addi  $t3, $t3, 0x2000
	srl   $t3, $t3, 0x1
	and   $t4, $t3, $a0
	bnez  $t4, .L00051d08
	addi  $t3, $t3, -1
	mfc0  $v0, C0_ENTRYLO0
	b     .L00051d0c
 	nop
.L00051d08:
	mfc0  $v0, C0_ENTRYLO1
.L00051d0c:
	andi  $t5, $v0, 0x2
	beqz  $t5, .L00051d38
 	nop
	lui   $at, 0x3fff
	ori   $at, $at, 0xffc0
	and   $v0, $v0, $at
	sll   $v0, $v0, 0x6
	and   $t5, $a0, $t3
	add   $v0, $v0, $t5
	b     .L00051d3c
 	nop
.L00051d38:
	addiu $v0, $zero, -1
.L00051d3c:
	mtc0  $t0, C0_ENTRYHI
	jr    $ra
 	nop
