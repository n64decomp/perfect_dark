#include "asm_helper.h"
#include "macros.inc"
.set noat
.set noreorder

.text

glabel func0002f490
	lw      $t0, 0x10($sp)
	lw      $t1, 0x14($sp)
	lw      $t2, 0x18($sp)
	lw      $t3, 0x1c($sp)
	lw      $t4, 0x20($sp)
	lh      $t5, 0x0($a0)
	lh      $t6, 0x2($a0)
	lh      $t7, 0x4($a0)
	mtc1    $t5, $f0
	mtc1    $t6, $f1
	mtc1    $t7, $f2
	cvt.s.w $f0, $f0
	cvt.s.w $f1, $f1
	cvt.s.w $f2, $f2
	lh      $t5, 0x0($a1)
	lh      $t6, 0x2($a1)
	lh      $t7, 0x4($a1)
	mtc1    $t5, $f12
	mtc1    $t6, $f13
	mtc1    $t7, $f14
	cvt.s.w $f12, $f12
	cvt.s.w $f13, $f13
	cvt.s.w $f14, $f14
	lh      $t5, 0x0($a2)
	lh      $t6, 0x2($a2)
	lh      $t7, 0x4($a2)
	mtc1    $t5, $f15
	mtc1    $t6, $f16
	mtc1    $t7, $f17
	cvt.s.w $f15, $f15
	cvt.s.w $f16, $f16
	cvt.s.w $f17, $f17
	sub.s   $f3, $f12, $f0
	sub.s   $f4, $f13, $f1
	sub.s   $f5, $f14, $f2
	sub.s   $f6, $f15, $f12
	sub.s   $f7, $f16, $f13
	sub.s   $f8, $f17, $f14
	sub.s   $f9, $f15, $f0
	sub.s   $f10, $f16, $f1
	beqz    $a3, .L0002f550
	sub.s   $f11, $f17, $f2
	lwc1    $f12, 0x0($a3)
	lwc1    $f13, 0x4($a3)
	lwc1    $f14, 0x8($a3)
	add.s   $f0, $f0, $f12
	add.s   $f1, $f1, $f13
	add.s   $f2, $f2, $f14
.L0002f550:
	lui     $t5, %hi(.L0002f5d8)
	addiu   $t5, $t5, %lo(.L0002f5d8)
	jr      $t5
 	nop

glabel func0002f560
	lw      $t0, 0x10($sp)
	lw      $t1, 0x14($sp)
	lw      $t2, 0x18($sp)
	lw      $t3, 0x1c($sp)
	lw      $t4, 0x20($sp)
	lwc1    $f0, 0x0($a0)
	lwc1    $f1, 0x4($a0)
	lwc1    $f2, 0x8($a0)
	lwc1    $f12, 0x0($a1)
	lwc1    $f13, 0x4($a1)
	lwc1    $f14, 0x8($a1)
	lwc1    $f15, 0x0($a2)
	lwc1    $f16, 0x4($a2)
	lwc1    $f17, 0x8($a2)
	sub.s   $f3, $f12, $f0
	sub.s   $f4, $f13, $f1
	sub.s   $f5, $f14, $f2
	sub.s   $f6, $f15, $f12
	sub.s   $f7, $f16, $f13
	sub.s   $f8, $f17, $f14
	sub.s   $f9, $f15, $f0
	sub.s   $f10, $f16, $f1
	beqz    $a3, .L0002f5d8
	sub.s   $f11, $f17, $f2
	lwc1    $f12, 0x0($a3)
	lwc1    $f13, 0x4($a3)
	lwc1    $f14, 0x8($a3)
	add.s   $f0, $f0, $f12
	add.s   $f1, $f1, $f13
	add.s   $f2, $f2, $f14
.L0002f5d8:
	addiu   $sp, $sp, -0x20
	swc1    $f20, 0x0($sp)
	swc1    $f21, 0x4($sp)
	swc1    $f22, 0x8($sp)
	swc1    $f23, 0xc($sp)
	swc1    $f24, 0x10($sp)
	swc1    $f25, 0x14($sp)
	mul.s   $f12, $f4, $f8
	swc1    $f25, 0x14($sp)
	mul.s   $f13, $f7, $f5
	swc1    $f26, 0x18($sp)
	mul.s   $f14, $f5, $f6
	sub.s   $f12, $f12, $f13
	mul.s   $f15, $f8, $f3
	swc1    $f27, 0x1c($sp)
	mul.s   $f16, $f3, $f7
	sub.s   $f13, $f14, $f15
	mul.s   $f14, $f6, $f4
	mfc1    $t6, $f28
	sub.s   $f14, $f16, $f14
	mul.s   $f15, $f12, $f0
	mfc1    $t7, $f29
	mul.s   $f16, $f13, $f1
	mfc1    $t8, $f30
	mul.s   $f17, $f14, $f2
	add.s   $f15, $f15, $f16
	mfc1    $t9, $f31
	add.s   $f15, $f15, $f17
	lwc1    $f16, 0x0($t2)
	lwc1    $f17, 0x4($t2)
	mul.s   $f19, $f12, $f16
	lwc1    $f18, 0x8($t2)
	mul.s   $f20, $f13, $f17
	add.s   $f19, $f19, $f20
	mul.s   $f20, $f14, $f18
	mtc1    $zero, $f31
	add.s   $f19, $f19, $f20
	c.eq.s  $f19, $f31
	bc1t    .L0002f864
	addi    $v0, $zero, 0x0
	lwc1    $f20, 0x0($t1)
	lwc1    $f21, 0x4($t1)
	mul.s   $f23, $f12, $f20
	lwc1    $f22, 0x8($t1)
	mul.s   $f24, $f13, $f21
	sub.s   $f23, $f15, $f23
	mul.s   $f25, $f14, $f22
	sub.s   $f23, $f23, $f24
	sub.s   $f23, $f23, $f25
	div.s   $f19, $f23, $f19
	mul.s   $f23, $f19, $f16
 	nop
	mul.s   $f24, $f19, $f17
	add.s   $f23, $f20, $f23
	mul.s   $f25, $f19, $f18
	add.s   $f24, $f21, $f24
	add.s   $f25, $f22, $f25
	sub.s   $f26, $f23, $f20
	mul.s   $f26, $f16, $f26
	sub.s   $f27, $f24, $f21
	mul.s   $f27, $f17, $f27
	sub.s   $f28, $f25, $f22
	add.s   $f26, $f26, $f27
	mul.s   $f27, $f18, $f28
	add.s   $f26, $f26, $f27
	c.lt.s  $f31, $f26
	bc1f    .L0002f6f0
 	nop
	b       .L0002f864
	addi    $v0, $zero, 0x0
.L0002f6f0:
	lwc1    $f20, 0x0($t0)
	sub.s   $f26, $f23, $f20
	lwc1    $f21, 0x4($t0)
	mul.s   $f26, $f16, $f26
	sub.s   $f27, $f24, $f21
	lwc1    $f22, 0x8($t0)
	mul.s   $f27, $f17, $f27
	sub.s   $f28, $f25, $f22
	add.s   $f26, $f26, $f27
	mul.s   $f27, $f18, $f28
	add.s   $f26, $f26, $f27
	c.lt.s  $f26, $f31
	bc1f    .L0002f730
 	nop
	b       .L0002f864
	addi    $v0, $zero, 0x0
.L0002f730:
	sub.s   $f0, $f23, $f0
	sub.s   $f1, $f24, $f1
	sub.s   $f2, $f25, $f2
	mul.s   $f26, $f6, $f4
 	nop
	mul.s   $f27, $f3, $f7
	sub.s   $f26, $f26, $f27
	c.eq.s  $f26, $f31
	bc1t    .L0002f770
 	nop
	mul.s   $f27, $f0, $f4
 	nop
	mul.s   $f28, $f1, $f3
	sub.s   $f27, $f27, $f28
	b       .L0002f7c8
	div.s   $f27, $f27, $f26
.L0002f770:
	mul.s   $f26, $f7, $f5
 	nop
	mul.s   $f27, $f4, $f8
	sub.s   $f26, $f26, $f27
	c.eq.s  $f26, $f31
	bc1t    .L0002f7a4
 	nop
	mul.s   $f27, $f1, $f5
 	nop
	mul.s   $f28, $f2, $f4
	sub.s   $f27, $f27, $f28
	b       .L0002f7c8
	div.s   $f27, $f27, $f26
.L0002f7a4:
	mul.s   $f26, $f8, $f3
 	nop
	mul.s   $f27, $f5, $f6
	sub.s   $f26, $f26, $f27
	mul.s   $f27, $f2, $f3
 	nop
	mul.s   $f28, $f0, $f5
	sub.s   $f27, $f27, $f28
	div.s   $f27, $f27, $f26
.L0002f7c8:
	c.lt.s  $f27, $f31
	bc1t    .L0002f864
	addi    $v0, $zero, 0x0
	c.eq.s  $f3, $f31
	bc1t    .L0002f7f0
 	nop
	mul.s   $f28, $f27, $f9
	sub.s   $f28, $f0, $f28
	b       .L0002f818
	div.s   $f28, $f28, $f3
.L0002f7f0:
	c.eq.s  $f4, $f31
	bc1t    .L0002f80c
 	nop
	mul.s   $f28, $f27, $f10
	sub.s   $f28, $f1, $f28
	b       .L0002f818
	div.s   $f28, $f28, $f4
.L0002f80c:
	mul.s   $f28, $f27, $f11
	sub.s   $f28, $f2, $f28
	div.s   $f28, $f28, $f5
.L0002f818:
	c.lt.s  $f28, $f31
	bc1t    .L0002f864
	addi    $v0, $zero, 0x0
	lui     $at, 0x3f80
	mtc1    $at, $f29
	add.s   $f27, $f28, $f27
	c.le.s  $f27, $f29
	bc1f    .L0002f864
	addi    $v0, $zero, 0x0
	beqz    $t3, .L0002f850
	addi    $v0, $zero, 0x1
	swc1    $f23, 0x0($t3)
	swc1    $f24, 0x4($t3)
	swc1    $f25, 0x8($t3)
.L0002f850:
	beqz    $t4, .L0002f864
 	nop
	swc1    $f12, 0x0($t4)
	swc1    $f13, 0x4($t4)
	swc1    $f14, 0x8($t4)
.L0002f864:
	lwc1    $f20, 0x0($sp)
	lwc1    $f21, 0x4($sp)
	lwc1    $f22, 0x8($sp)
	lwc1    $f23, 0xc($sp)
	lwc1    $f24, 0x10($sp)
	lwc1    $f25, 0x14($sp)
	lwc1    $f26, 0x18($sp)
	lwc1    $f27, 0x1c($sp)
	mtc1    $t6, $f28
	mtc1    $t7, $f29
	mtc1    $t8, $f30
	mtc1    $t9, $f31
	jr      $ra
	addiu   $sp, $sp, 0x20
