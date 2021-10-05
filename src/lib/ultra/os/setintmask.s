#include "macros.inc"
.set noat
.set noreorder

.section .text

glabel osSetIntMask
	mfc0  $t4, $12
	andi  $v0, $t4, 0xff01
	lui   $t0, %hi(__osGlobalIntMask)
	addiu $t0, $t0, %lo(__osGlobalIntMask)
	lw    $t3, 0x0($t0)
	addiu $at, $zero, -1
	xor   $t0, $t3, $at
	andi  $t0, $t0, 0xff00
	or    $v0, $v0, $t0
	lui   $t2, 0xa430
	lw    $t2, 0xc($t2)
	beqz  $t2, .L00048694
	srl   $t1, $t3, 0x10
	addiu $at, $zero, -1
	xor   $t1, $t1, $at
	andi  $t1, $t1, 0x3f
	or    $t2, $t2, $t1
.L00048694:
	sll   $t2, $t2, 0x10
	or    $v0, $v0, $t2
	lui   $at, 0x3f
	and   $t0, $a0, $at
	and   $t0, $t0, $t3
	srl   $t0, $t0, 0xf
	lui   $t2, %hi(var70059e30)
	addu  $t2, $t2, $t0
	lhu   $t2, %lo(var70059e30)($t2)
	lui   $at, 0xa430
	sw    $t2, 0xc($at)
	andi  $t0, $a0, 0xff01
	andi  $t1, $t3, 0xff00
	and   $t0, $t0, $t1
	lui   $at, 0xffff
	ori   $at, $at, 0xff
	and   $t4, $t4, $at
	or    $t4, $t4, $t0
	mtc0  $t4, $12
 	nop
 	nop
	jr    $ra
 	nop

.section .rodata

glabel var70059e30
.half 0x0555
.half 0x0556
.half 0x0559
.half 0x055a
.half 0x0565
.half 0x0566
.half 0x0569
.half 0x056a
.half 0x0595
.half 0x0596
.half 0x0599
.half 0x059a
.half 0x05a5
.half 0x05a6
.half 0x05a9
.half 0x05aa
.half 0x0655
.half 0x0656
.half 0x0659
.half 0x065a
.half 0x0665
.half 0x0666
.half 0x0669
.half 0x066a
.half 0x0695
.half 0x0696
.half 0x0699
.half 0x069a
.half 0x06a5
.half 0x06a6
.half 0x06a9
.half 0x06aa
.half 0x0955
.half 0x0956
.half 0x0959
.half 0x095a
.half 0x0965
.half 0x0966
.half 0x0969
.half 0x096a
.half 0x0995
.half 0x0996
.half 0x0999
.half 0x099a
.half 0x09a5
.half 0x09a6
.half 0x09a9
.half 0x09aa
.half 0x0a55
.half 0x0a56
.half 0x0a59
.half 0x0a5a
.half 0x0a65
.half 0x0a66
.half 0x0a69
.half 0x0a6a
.half 0x0a95
.half 0x0a96
.half 0x0a99
.half 0x0a9a
.half 0x0aa5
.half 0x0aa6
.half 0x0aa9
.half 0x0aaa

