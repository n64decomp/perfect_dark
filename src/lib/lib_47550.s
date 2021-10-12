#include "asm_helper.h"
#include "macros.inc"
.set noat
.set noreorder

.text

glabel func00047550
	addiu  $sp, $sp, -0xd0
	or     $t0, $sp, $zero
	addiu  $t1, $t0, 0xd0
.L0004755c:
	sw     $zero, 0x0($t0)
	sw     $zero, 0x4($t0)
	sw     $zero, 0x8($t0)
	sw     $zero, 0xc($t0)
	addiu  $t0, $t0, 0x10
	bne    $t0, $t1, .L0004755c
 	nop
	or     $t2, $a0, $zero
	or     $t3, $sp, $zero
	addiu  $t4, $t3, 0x40
	or     $t6, $t4, $zero
	addiu  $t5, $zero, 0x3
.L0004758c:
	lwc1   $f4, 0x14($t2)
	lwc1   $f6, 0x10($t2)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x10($t2)
	lwc1   $f10, 0xc($t2)
	add.s  $f8, $f8, $f10
	swc1   $f4, 0x14($t2)
	swc1   $f8, 0x10($t2)
	lwc1   $f4, 0xc($t2)
	lwc1   $f6, 0x8($t2)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x8($t2)
	lwc1   $f10, 0x4($t2)
	add.s  $f8, $f8, $f10
	swc1   $f4, 0xc($t2)
	swc1   $f8, 0x8($t2)
	lwc1   $f4, 0x4($t2)
	lwc1   $f6, 0x0($t2)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x14($t2)
	lwc1   $f10, 0xc($t2)
	add.s  $f8, $f8, $f10
	swc1   $f4, 0x4($t2)
	swc1   $f8, 0x14($t2)
	lwc1   $f4, 0xc($t2)
	lwc1   $f6, 0x4($t2)
	add.s  $f4, $f4, $f6
	swc1   $f4, 0xc($t2)
	lwc1   $f4, 0x8($t2)
	lui    $at, %hi(var70059d9c)
	lwc1   $f6, %lo(var70059d9c)($at)
	mul.s  $f6, $f4, $f6
 	nop
	lwc1   $f8, 0x10($t2)
	lui    $at, 0x3f00
	mtc1   $at, $f10
 	nop
	lwc1   $f16, 0x0($t2)
	mul.s  $f10, $f8, $f10
 	nop
	add.s  $f18, $f16, $f10
	sub.s  $f0, $f16, $f8
	swc1   $f0, 0x4($t3)
	add.s  $f0, $f18, $f6
	swc1   $f0, 0x0($t3)
	sub.s  $f0, $f18, $f6
	swc1   $f0, 0x8($t3)
	lwc1   $f4, 0xc($t2)
	lui    $at, %hi(var70059da0)
	lwc1   $f6, %lo(var70059da0)($at)
	mul.s  $f6, $f4, $f6
 	nop
	lwc1   $f8, 0x14($t2)
	lui    $at, 0x3f00
	mtc1   $at, $f10
 	nop
	lwc1   $f16, 0x4($t2)
	mul.s  $f10, $f8, $f10
 	nop
	add.s  $f18, $f16, $f10
	sub.s  $f0, $f16, $f8
	swc1   $f0, 0x10($t3)
	add.s  $f0, $f18, $f6
	swc1   $f0, 0x14($t3)
	sub.s  $f0, $f18, $f6
	swc1   $f0, 0xc($t3)
	lwc1   $f4, 0xc($t3)
	lui    $at, %hi(var70059da4)
	lwc1   $f6, %lo(var70059da4)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x10($t3)
	lui    $at, %hi(var70059da8)
	lwc1   $f10, %lo(var70059da8)($at)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0xc($t3)
	swc1   $f8, 0x10($t3)
	lwc1   $f4, 0x14($t3)
	lui    $at, %hi(var70059dac)
	lwc1   $f6, %lo(var70059dac)($at)
	mul.s  $f4, $f4, $f6
 	nop
	swc1   $f4, 0x14($t3)
	lwc1   $f4, 0x0($t3)
	lwc1   $f6, 0x14($t3)
	add.s  $f8, $f4, $f6
	swc1   $f8, 0x0($t3)
	sub.s  $f10, $f4, $f6
	swc1   $f10, 0x14($t3)
	lwc1   $f4, 0x4($t3)
	lwc1   $f6, 0x10($t3)
	add.s  $f8, $f4, $f6
	swc1   $f8, 0x4($t3)
	sub.s  $f8, $f4, $f6
	swc1   $f8, 0x10($t3)
	lwc1   $f4, 0x8($t3)
	lwc1   $f6, 0xc($t3)
	add.s  $f8, $f4, $f6
	swc1   $f8, 0x8($t3)
	sub.s  $f8, $f4, $f6
	swc1   $f8, 0xc($t3)
	lwc1   $f4, 0x0($t3)
	lui    $at, %hi(var70059db0)
	lwc1   $f6, %lo(var70059db0)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x4($t3)
	lui    $at, %hi(var70059db4)
	lwc1   $f10, %lo(var70059db4)($at)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x0($t3)
	swc1   $f8, 0x4($t3)
	lwc1   $f4, 0x8($t3)
	lui    $at, %hi(var70059db8)
	lwc1   $f6, %lo(var70059db8)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0xc($t3)
	lui    $at, %hi(var70059dbc)
	lwc1   $f10, %lo(var70059dbc)($at)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x8($t3)
	swc1   $f8, 0xc($t3)
	lwc1   $f4, 0x10($t3)
	lui    $at, %hi(var70059dc0)
	lwc1   $f6, %lo(var70059dc0)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x14($t3)
	lui    $at, %hi(var70059dc4)
	lwc1   $f10, %lo(var70059dc4)($at)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x10($t3)
	swc1   $f8, 0x14($t3)
	lwc1   $f4, 0x0($t3)
	lui    $at, %hi(var70059dc8)
	lwc1   $f6, %lo(var70059dc8)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x0($t3)
	lui    $at, %hi(var70059dcc)
	lwc1   $f10, %lo(var70059dcc)($at)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x20($t3)
	swc1   $f8, 0x24($t3)
	lwc1   $f4, 0x4($t3)
	lui    $at, %hi(var70059dd0)
	lwc1   $f6, %lo(var70059dd0)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x4($t3)
	lui    $at, %hi(var70059dd4)
	lwc1   $f10, %lo(var70059dd4)($at)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x1c($t3)
	swc1   $f8, 0x28($t3)
	lwc1   $f4, 0x8($t3)
	lui    $at, %hi(var70059dd8)
	lwc1   $f6, %lo(var70059dd8)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x8($t3)
	lui    $at, %hi(var70059ddc)
	lwc1   $f10, %lo(var70059ddc)($at)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x18($t3)
	swc1   $f8, 0x2c($t3)
	lwc1   $f4, 0xc($t3)
	lui    $at, 0x3f80
	mtc1   $at, $f6
 	nop
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x10($t3)
	lui    $at, %hi(var70059de0)
	lwc1   $f10, %lo(var70059de0)($at)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x0($t3)
	swc1   $f8, 0x4($t3)
	lwc1   $f4, 0x14($t3)
	lui    $at, %hi(var70059de4)
	lwc1   $f6, %lo(var70059de4)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x14($t3)
	lui    $at, %hi(var70059de8)
	lwc1   $f10, %lo(var70059de8)($at)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x8($t3)
	swc1   $f8, 0xc($t3)
	lwc1   $f4, 0x10($t3)
	lui    $at, %hi(var70059dec)
	lwc1   $f6, %lo(var70059dec)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x0($t3)
	lui    $at, %hi(var70059df0)
	lwc1   $f10, %lo(var70059df0)($at)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x10($t3)
	swc1   $f8, 0x14($t3)
	lwc1   $f4, 0x0($t3)
	lui    $at, %hi(var70059df4)
	lwc1   $f6, %lo(var70059df4)($at)
	mul.s  $f4, $f4, $f6
 	nop
	swc1   $f4, 0x0($t3)
	lwc1   $f4, 0x18($t4)
	lwc1   $f6, 0x0($t3)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x1c($t4)
	lwc1   $f10, 0x4($t3)
	add.s  $f8, $f8, $f10
	swc1   $f4, 0x18($t4)
	swc1   $f8, 0x1c($t4)
	lwc1   $f4, 0x20($t4)
	lwc1   $f6, 0x8($t3)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x24($t4)
	lwc1   $f10, 0xc($t3)
	add.s  $f8, $f8, $f10
	swc1   $f4, 0x20($t4)
	swc1   $f8, 0x24($t4)
	lwc1   $f4, 0x28($t4)
	lwc1   $f6, 0x10($t3)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x2c($t4)
	lwc1   $f10, 0x14($t3)
	add.s  $f8, $f8, $f10
	swc1   $f4, 0x28($t4)
	swc1   $f8, 0x2c($t4)
	lwc1   $f4, 0x30($t4)
	lwc1   $f6, 0x18($t3)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x34($t4)
	lwc1   $f10, 0x1c($t3)
	add.s  $f8, $f8, $f10
	swc1   $f4, 0x30($t4)
	swc1   $f8, 0x34($t4)
	lwc1   $f4, 0x38($t4)
	lwc1   $f6, 0x20($t3)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x3c($t4)
	lwc1   $f10, 0x24($t3)
	add.s  $f8, $f8, $f10
	swc1   $f4, 0x38($t4)
	swc1   $f8, 0x3c($t4)
	lwc1   $f4, 0x40($t4)
	lwc1   $f6, 0x28($t3)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x44($t4)
	lwc1   $f10, 0x2c($t3)
	add.s  $f8, $f8, $f10
	swc1   $f4, 0x40($t4)
	swc1   $f8, 0x44($t4)
	addi   $t2, $t2, 0x18
	addi   $t4, $t4, 0x18
	addi   $t5, $t5, -1
	bnez   $t5, .L0004758c
 	nop
	or     $t0, $a2, $zero
	or     $t1, $a3, $zero
	or     $t4, $t6, $zero
	andi   $a1, $a1, 0x1
	beqz   $a1, .L00047a24
 	nop
	addiu  $t5, $zero, 0x9
.L000479e0:
	lwc1   $f4, 0x0($t4)
	lwc1   $f6, 0x0($t1)
	add.s  $f6, $f4, $f6
	lwc1   $f8, 0x4($t4)
	neg.s  $f8, $f8
	lwc1   $f10, 0x4($t1)
	sub.s  $f10, $f8, $f10
	swc1   $f6, 0x0($t0)
	swc1   $f10, 0x4($t0)
	addi   $t0, $t0, 0x8
	addi   $t1, $t1, 0x8
	addi   $t4, $t4, 0x8
	addi   $t5, $t5, -1
	bnez   $t5, .L000479e0
 	nop
	b      .L00047a50
 	nop
.L00047a24:
	addiu  $t5, $zero, 0x12
.L00047a28:
	lwc1   $f4, 0x0($t4)
	lwc1   $f6, 0x0($t1)
	add.s  $f4, $f4, $f6
	swc1   $f4, 0x0($t0)
	addi   $t0, $t0, 0x4
	addi   $t1, $t1, 0x4
	addi   $t4, $t4, 0x4
	addi   $t5, $t5, -1
	bnez   $t5, .L00047a28
 	nop
.L00047a50:
	or     $t1, $a3, $zero
	addi   $t4, $t6, 0x48
	addiu  $t5, $zero, 0x12
.L00047a5c:
	lwc1   $f4, 0x0($t4)
	swc1   $f4, 0x0($t1)
	addi   $t1, $t1, 0x4
	addi   $t4, $t4, 0x4
	addi   $t5, $t5, -1
	bnez   $t5, .L00047a5c
 	nop
	addiu  $sp, $sp, 0xd0
	jr     $ra
 	nop
