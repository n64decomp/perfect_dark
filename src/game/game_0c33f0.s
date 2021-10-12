#include "asm_helper.h"
#include "macros.inc"
.set noat
.set noreorder

.text

glabel func0f0c33f0
	lui    $t0, %hi(var8005ef10)
	addiu  $t0, $t0, %lo(var8005ef10)
	lui    $t1, 0xffff
	lwc1   $f16, 0x0($t0)
.L0f0c3400:
	lwc1   $f0, 0x0($a0)
	lwc1   $f1, 0x4($a0)
	lwc1   $f2, 0x8($a0)
	lwc1   $f3, 0xc($a0)
	lwc1   $f4, 0x10($a0)
	lwc1   $f5, 0x14($a0)
	lwc1   $f6, 0x18($a0)
	lwc1   $f7, 0x1c($a0)
	lwc1   $f8, 0x20($a0)
	lwc1   $f9, 0x24($a0)
	lwc1   $f10, 0x28($a0)
	lwc1   $f11, 0x2c($a0)
	lwc1   $f12, 0x30($a0)
	lwc1   $f13, 0x34($a0)
	lwc1   $f14, 0x38($a0)
	lwc1   $f15, 0x3c($a0)
	mul.s  $f18, $f0, $f16
	lwc1   $f17, 0x4($t0)
	trunc.w.s $f18, $f18
	mul.s  $f19, $f1, $f16
	trunc.w.s $f19, $f19
	mfc1   $t2, $f18
	mfc1   $t3, $f19
	mul.s  $f18, $f2, $f16
	and    $t4, $t2, $t1
	trunc.w.s $f18, $f18
	mul.s  $f19, $f3, $f17
	srl    $t5, $t3, 0x10
	trunc.w.s $f19, $f19
	or     $t4, $t4, $t5
	mfc1   $t5, $f18
	sll    $t2, $t2, 0x10
	andi   $t3, $t3, 0xffff
	mfc1   $t6, $f19
	or     $t2, $t2, $t3
	and    $t7, $t5, $t1
	sll    $t5, $t5, 0x10
	srl    $t8, $t6, 0x10
	andi   $t6, $t6, 0xffff
	or     $t7, $t7, $t8
	or     $t5, $t5, $t6
	mul.s  $f18, $f4, $f16
	sw     $t4, 0x0($a0)
	trunc.w.s $f18, $f18
	mul.s  $f19, $f5, $f16
	sw     $t7, 0x4($a0)
	sw     $t2, 0x20($a0)
	sw     $t5, 0x24($a0)
	trunc.w.s $f19, $f19
	mfc1   $t2, $f18
	mfc1   $t3, $f19
	mul.s  $f18, $f6, $f16
	and    $t4, $t2, $t1
	trunc.w.s $f18, $f18
	mul.s  $f19, $f7, $f17
	srl    $t5, $t3, 0x10
	trunc.w.s $f19, $f19
	or     $t4, $t4, $t5
	mfc1   $t5, $f18
	sll    $t2, $t2, 0x10
	andi   $t3, $t3, 0xffff
	mfc1   $t6, $f19
	or     $t2, $t2, $t3
	and    $t7, $t5, $t1
	sll    $t5, $t5, 0x10
	srl    $t8, $t6, 0x10
	andi   $t6, $t6, 0xffff
	or     $t7, $t7, $t8
	or     $t5, $t5, $t6
	mul.s  $f18, $f8, $f16
	sw     $t4, 0x8($a0)
	trunc.w.s $f18, $f18
	mul.s  $f19, $f9, $f16
	sw     $t7, 0xc($a0)
	sw     $t2, 0x28($a0)
	sw     $t5, 0x2c($a0)
	trunc.w.s $f19, $f19
	mfc1   $t2, $f18
	mfc1   $t3, $f19
	mul.s  $f18, $f10, $f16
	and    $t4, $t2, $t1
	trunc.w.s $f18, $f18
	mul.s  $f19, $f11, $f17
	srl    $t5, $t3, 0x10
	trunc.w.s $f19, $f19
	or     $t4, $t4, $t5
	mfc1   $t5, $f18
	sll    $t2, $t2, 0x10
	andi   $t3, $t3, 0xffff
	mfc1   $t6, $f19
	or     $t2, $t2, $t3
	and    $t7, $t5, $t1
	sll    $t5, $t5, 0x10
	srl    $t8, $t6, 0x10
	andi   $t6, $t6, 0xffff
	or     $t7, $t7, $t8
	or     $t5, $t5, $t6
	mul.s  $f18, $f12, $f16
	sw     $t4, 0x10($a0)
	trunc.w.s $f18, $f18
	mul.s  $f19, $f13, $f16
	sw     $t7, 0x14($a0)
	sw     $t2, 0x30($a0)
	sw     $t5, 0x34($a0)
	trunc.w.s $f19, $f19
	mfc1   $t2, $f18
	mfc1   $t3, $f19
	mul.s  $f18, $f14, $f16
	and    $t4, $t2, $t1
	trunc.w.s $f18, $f18
	mul.s  $f19, $f15, $f17
	srl    $t5, $t3, 0x10
	trunc.w.s $f19, $f19
	or     $t4, $t4, $t5
	mfc1   $t5, $f18
	sll    $t2, $t2, 0x10
	andi   $t3, $t3, 0xffff
	mfc1   $t6, $f19
	or     $t2, $t2, $t3
	and    $t7, $t5, $t1
	sll    $t5, $t5, 0x10
	srl    $t8, $t6, 0x10
	andi   $t6, $t6, 0xffff
	or     $t7, $t7, $t8
	or     $t5, $t5, $t6
	addiu  $a1, $a1, -1
	sw     $t4, 0x18($a0)
	sw     $t7, 0x1c($a0)
	sw     $t2, 0x38($a0)
	sw     $t5, 0x3c($a0)
	bnez   $a1, .L0f0c3400
	addiu  $a0, $a0, 0x40
	jr     $ra
 	nop
