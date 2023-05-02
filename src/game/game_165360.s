#include "asm_helper.h"
#include "macros.inc"
.set noat
.set noreorder

.rdata

glabel var7f1b76d0
.float -0.9

.text

glabel func0f165360
	mfc1   $t7, $f20
	lui    $a3, %hi(g_Vars)
	addiu  $a3, $a3, %lo(g_Vars)
	lw     $a3, 0x284($a3)
	lw     $a3, 0x1750($a3)
	lui    $t0, %hi(var800a4cf0)
	addiu  $t0, $t0, %lo(var800a4cf0)
	lui    $at, %hi(var7f1b76d0)
	lwc1   $f13, %lo(var7f1b76d0)($at)
	lwc1   $f12, 0xc($t0)
	lui    $t0, %hi(g_BgPortals)
	addiu  $t0, $t0, %lo(g_BgPortals)
	lw     $t0, 0x0($t0)
	sll    $t1, $a0, 0x3
	add    $t1, $t1, $t0
	lhu    $t1, 0x0($t1)
	add    $a0, $t0, $t1
	lbu    $t1, 0x0($a0)
	add    $t5, $zero, $t1
	addiu  $t6, $a2, 0x270
	mul.s  $f12, $f12, $f13
	lwc1   $f0, 0x0($a3)
	lwc1   $f3, 0x4($a3)
	lwc1   $f6, 0x8($a3)
	lwc1   $f1, 0x10($a3)
	lwc1   $f4, 0x14($a3)
	lwc1   $f7, 0x18($a3)
	lwc1   $f2, 0x20($a3)
	lwc1   $f5, 0x24($a3)
	lwc1   $f8, 0x28($a3)
	lwc1   $f9, 0x30($a3)
	lwc1   $f10, 0x34($a3)
	lwc1   $f11, 0x38($a3)
	addi   $a0, $a0, 0x4
	mtc1   $zero, $f20
	addi   $t2, $zero, 0x1
	addi   $t3, $zero, 0x0
	add    $v0, $zero, $t1
	lwc1   $f13, 0x0($a0)
.L0f1653fc:
	mul.s  $f16, $f0, $f13
	lwc1   $f14, 0x4($a0)
	mul.s  $f17, $f1, $f14
	lwc1   $f15, 0x8($a0)
	mul.s  $f18, $f2, $f15
	add.s  $f16, $f16, $f17
	mul.s  $f17, $f3, $f13
	add.s  $f16, $f16, $f18
	mul.s  $f18, $f4, $f14
	add.s  $f16, $f16, $f9
	mul.s  $f19, $f5, $f15
	add.s  $f17, $f17, $f18
	mul.s  $f18, $f6, $f13
	swc1   $f16, 0x0($t6)
	mul.s  $f16, $f7, $f14
	add.s  $f17, $f17, $f19
	mul.s  $f19, $f8, $f15
	add.s  $f17, $f17, $f10
	add.s  $f16, $f18, $f16
	swc1   $f17, 0x4($t6)
	add.s  $f16, $f16, $f19
	addiu  $a0, $a0, 0xc
	add.s  $f16, $f16, $f11
	addi   $t1, $t1, -1
	c.lt.s $f16, $f20
	swc1   $f16, 0x8($t6)
	bc1t   .L0f165474
	addiu  $t4, $zero, 0x0
	addiu  $t3, $zero, 0x1
	addiu  $t4, $zero, 0x1
.L0f165474:
	sw     $t4, 0xc($t6)
	addiu  $t6, $t6, -16
	bnez   $t1, .L0f1653fc
	lwc1   $f13, 0x0($a0)
	beqz   $t3, .L0f1655a8
 	nop
	addiu  $t0, $a2, 0x270
	addiu  $v0, $zero, 0x0
	lw     $t1, 0x0($t0)
	lw     $t2, 0x4($t0)
	lw     $t3, 0x8($t0)
	lw     $t4, 0xc($t0)
	sw     $t1, 0x0($t6)
	sw     $t2, 0x4($t6)
	sw     $t3, 0x8($t6)
	sw     $t4, 0xc($t6)
.L0f1654b4:
	lw     $t1, 0xc($t6)
	beqz   $t1, .L0f165550
	lw     $t1, 0x1c($t6)
	bnez   $t1, .L0f165590
 	nop
	lw     $t1, 0x10($t6)
	lw     $t2, 0x14($t6)
	lw     $t3, 0x18($t6)
	sw     $t1, 0x0($a2)
	sw     $t2, 0x4($a2)
	sw     $t3, 0x8($a2)
	addiu  $a2, $a2, 0x10
	addiu  $v0, $v0, 0x1
.L0f1654e8:
	lwc1   $f0, 0x8($t6)
	lwc1   $f1, 0x18($t6)
	addiu  $a2, $a2, 0x10
	sub.s  $f1, $f1, $f0
	neg.s  $f2, $f0
	lwc1   $f3, 0x0($t6)
	div.s  $f0, $f2, $f1
	lwc1   $f2, 0x10($t6)
	sub.s  $f1, $f2, $f3
	mul.s  $f1, $f1, $f0
	lwc1   $f2, 0x4($t6)
	add.s  $f1, $f3, $f1
	lwc1   $f3, 0x14($t6)
	swc1   $f1, -0x10($a2)
	sub.s  $f3, $f3, $f2
	addiu  $v0, $v0, 0x1
	mul.s  $f1, $f3, $f0
	sw     $zero, -0x8($a2)
	add.s  $f1, $f2, $f1
	addi   $t5, $t5, -1
	swc1   $f1, -0xc($a2)
	bnez   $t5, .L0f1654b4
	addiu  $t6, $t6, 0x10
	sw     $zero, 0x0($a1)
	jr     $ra
	mtc1   $t7, $f20
.L0f165550:
	bnez   $t1, .L0f1654e8
 	nop
	lw     $t1, 0x10($t6)
	lw     $t2, 0x14($t6)
	lw     $t3, 0x18($t6)
	sw     $t1, 0x0($a2)
	sw     $t2, 0x4($a2)
	sw     $t3, 0x8($a2)
	addi   $t5, $t5, -1
	addiu  $v0, $v0, 0x1
	addiu  $a2, $a2, 0x10
	bnez   $t5, .L0f1654b4
	addiu  $t6, $t6, 0x10
	sw     $zero, 0x0($a1)
	jr     $ra
	mtc1   $t7, $f20
.L0f165590:
	addi   $t5, $t5, -1
	bnez   $t5, .L0f1654b4
	addiu  $t6, $t6, 0x10
	sw     $zero, 0x0($a1)
	jr     $ra
	mtc1   $t7, $f20
.L0f1655a8:
	addiu  $t0, $zero, 0x28
	sub    $t0, $t0, $v0
	sw     $t0, 0x0($a1)
	jr     $ra
	mtc1   $t7, $f20
