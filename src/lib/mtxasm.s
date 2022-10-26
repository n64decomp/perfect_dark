#include "asm_helper.h"
#include "macros.inc"
.set noat
.set noreorder

.data

glabel var8005ef10
.float 65536
.float 65536

.text

glabel mtx4LoadIdentity
	lui    $at, 0x3f80
	sw     $zero, 0x4($a0)
	sw     $zero, 0x8($a0)
	sw     $zero, 0xc($a0)
	sw     $zero, 0x10($a0)
	sw     $zero, 0x18($a0)
	sw     $zero, 0x1c($a0)
	sw     $zero, 0x20($a0)
	sw     $zero, 0x24($a0)
	sw     $zero, 0x2c($a0)
	sw     $zero, 0x30($a0)
	sw     $zero, 0x34($a0)
	sw     $zero, 0x38($a0)
	sw     $at, 0x0($a0)
	sw     $at, 0x14($a0)
	sw     $at, 0x28($a0)
	jr     $ra
	sw     $at, 0x3c($a0)

glabel mtx4MultMtx4InPlace
	add    $a2, $a1, $zero

glabel mtx4MultMtx4
	mfc1   $t1, $f20
	mfc1   $t2, $f21
	mfc1   $t3, $f22
	mfc1   $t4, $f23
	mfc1   $t5, $f24
	addiu  $t0, $zero, 0x4
	lwc1   $f0, 0x0($a1)
	lwc1   $f1, 0x4($a1)
	lwc1   $f2, 0x8($a1)
	lwc1   $f3, 0xc($a1)
	lwc1   $f4, 0x10($a1)
	lwc1   $f5, 0x14($a1)
	lwc1   $f6, 0x18($a1)
	lwc1   $f7, 0x1c($a1)
	lwc1   $f8, 0x20($a1)
	lwc1   $f9, 0x24($a1)
	lwc1   $f10, 0x28($a1)
	lwc1   $f11, 0x2c($a1)
	lwc1   $f12, 0x30($a1)
	lwc1   $f13, 0x34($a1)
	lwc1   $f14, 0x38($a1)
	lwc1   $f15, 0x3c($a1)
.L00015a58:
	lwc1   $f16, 0x0($a0)
	mul.s  $f20, $f16, $f0
	lwc1   $f17, 0x10($a0)
	lwc1   $f18, 0x20($a0)
	mul.s  $f21, $f17, $f1
	lwc1   $f19, 0x30($a0)
	mul.s  $f22, $f18, $f2
	add.s  $f20, $f20, $f21
	mul.s  $f21, $f19, $f3
	add.s  $f20, $f20, $f22
	mul.s  $f22, $f16, $f4
	add.s  $f20, $f20, $f21
	mul.s  $f21, $f17, $f5
	swc1   $f20, 0x0($a2)
	mul.s  $f20, $f18, $f6
	add.s  $f22, $f22, $f21
	mul.s  $f21, $f19, $f7
	addiu  $a2, $a2, 0x4
	mul.s  $f23, $f16, $f8
	add.s  $f22, $f22, $f20
	mul.s  $f20, $f17, $f9
	add.s  $f22, $f22, $f21
	mul.s  $f21, $f18, $f10
	swc1   $f22, 0xc($a2)
	mul.s  $f24, $f19, $f11
	add.s  $f23, $f23, $f20
	mul.s  $f22, $f16, $f12
	add.s  $f23, $f23, $f21
	mul.s  $f21, $f17, $f13
	add.s  $f23, $f23, $f24
	mul.s  $f24, $f18, $f14
	swc1   $f23, 0x1c($a2)
	mul.s  $f23, $f19, $f15
	add.s  $f22, $f22, $f21
	addiu  $t0, $t0, -1
	add.s  $f22, $f22, $f24
	addiu  $a0, $a0, 0x4
	add.s  $f22, $f22, $f23
	bnez   $t0, .L00015a58
	swc1   $f22, 0x2c($a2)
	mtc1   $t1, $f20
	mtc1   $t2, $f21
	mtc1   $t3, $f22
	mtc1   $t4, $f23
	jr     $ra
	mtc1   $t5, $f24

glabel mtx4RotateVecInPlace
	add    $a2, $a1, $zero

glabel mtx4RotateVec
	lwc1   $f0, 0x0($a1)
	lwc1   $f1, 0x4($a1)
	lwc1   $f2, 0x8($a1)
	addiu  $t0, $zero, 0x3
	lwc1   $f3, 0x0($a0)
.L00015b28:
	lwc1   $f4, 0x10($a0)
	mul.s  $f6, $f3, $f0
	lwc1   $f5, 0x20($a0)
	mul.s  $f7, $f4, $f1
	addiu  $a0, $a0, 0x4
	add.s  $f9, $f6, $f7
	mul.s  $f8, $f5, $f2
	addiu  $a2, $a2, 0x4
	add.s  $f16, $f9, $f8
	addiu  $t0, $t0, -1
	swc1   $f16, -0x4($a2)
	bnez   $t0, .L00015b28
	lwc1   $f3, 0x0($a0)
	jr     $ra
 	nop

glabel mtx4TransformVecInPlace
	add    $a2, $a1, $zero

glabel mtx4TransformVec
	lwc1   $f0, 0x0($a1)
	lwc1   $f1, 0x4($a1)
	lwc1   $f2, 0x8($a1)
	addiu  $t0, $zero, 0x3
	lwc1   $f3, 0x0($a0)
.L00015b7c:
	lwc1   $f4, 0x10($a0)
	mul.s  $f6, $f3, $f0
	lwc1   $f5, 0x20($a0)
	mul.s  $f7, $f4, $f1
	addiu  $a0, $a0, 0x4
	add.s  $f9, $f6, $f7
	mul.s  $f8, $f5, $f2
	addiu  $a2, $a2, 0x4
	add.s  $f16, $f9, $f8
	addiu  $t0, $t0, -1
	swc1   $f16, -0x4($a2)
	bnez   $t0, .L00015b7c
	lwc1   $f3, 0x0($a0)
	lwc1   $f0, -0xc($a2)
	lwc1   $f1, -0x8($a2)
	lwc1   $f3, 0x24($a0)
	lwc1   $f4, 0x28($a0)
	lwc1   $f5, 0x2c($a0)
	add.s  $f0, $f0, $f3
	add.s  $f1, $f1, $f4
	add.s  $f2, $f16, $f5
	swc1   $f0, -0xc($a2)
	swc1   $f1, -0x8($a2)
	jr     $ra
	swc1   $f2, -0x4($a2)

glabel mtx00015be0
	add    $a2, $a1, $zero

glabel mtx00015be4
	mfc1   $t1, $f20
	mfc1   $t2, $f21
	mfc1   $t3, $f22
	mfc1   $t4, $f23
	lwc1   $f0, 0x0($a1)
	lwc1   $f1, 0x4($a1)
	lwc1   $f2, 0x8($a1)
	lwc1   $f3, 0x10($a1)
	lwc1   $f4, 0x14($a1)
	lwc1   $f5, 0x18($a1)
	lwc1   $f6, 0x20($a1)
	lwc1   $f7, 0x24($a1)
	lwc1   $f8, 0x28($a1)
	lwc1   $f9, 0x30($a1)
	lwc1   $f10, 0x34($a1)
	lwc1   $f11, 0x38($a1)
	addiu  $t0, $zero, 0x3
.L00015c28:
	lwc1   $f12, 0x0($a0)
	addiu  $a0, $a0, 0x4
	mul.s  $f16, $f12, $f0
	lwc1   $f13, 0xc($a0)
	lwc1   $f14, 0x1c($a0)
	mul.s  $f17, $f13, $f1
	lwc1   $f15, 0x2c($a0)
	mul.s  $f18, $f14, $f2
	add.s  $f19, $f16, $f17
	mul.s  $f20, $f12, $f3
	add.s  $f19, $f19, $f18
	mul.s  $f21, $f13, $f4
	swc1   $f19, 0x0($a2)
	mul.s  $f22, $f14, $f5
	add.s  $f23, $f20, $f21
	mul.s  $f16, $f12, $f6
	add.s  $f23, $f23, $f22
	mul.s  $f17, $f13, $f7
	swc1   $f23, 0x10($a2)
	mul.s  $f18, $f14, $f8
	add.s  $f19, $f16, $f17
	mul.s  $f20, $f12, $f9
	add.s  $f19, $f19, $f18
	mul.s  $f21, $f13, $f10
	swc1   $f19, 0x20($a2)
	mul.s  $f22, $f14, $f11
	add.s  $f20, $f20, $f21
	add.s  $f22, $f22, $f15
	addiu  $t0, $t0, -1
	add.s  $f22, $f20, $f22
	addiu  $a2, $a2, 0x4
	bnez   $t0, .L00015c28
	swc1   $f22, 0x2c($a2)
	lui    $at, 0x3f80
	mtc1   $at, $f0
	sw     $zero, 0x0($a2)
	sw     $zero, 0x10($a2)
	sw     $zero, 0x20($a2)
	swc1   $f0, 0x30($a2)
	mtc1   $t1, $f20
	mtc1   $t2, $f21
	mtc1   $t3, $f22
	jr     $ra
	mtc1   $t4, $f23

glabel mtx3Copy
	addiu  $t0, $zero, 0x2
.L00015cdc:
	lw     $t1, 0x0($a0)
	lw     $t2, 0x4($a0)
	lw     $t3, 0x8($a0)
	lw     $t4, 0xc($a0)
	sw     $t1, 0x0($a1)
	sw     $t2, 0x4($a1)
	sw     $t3, 0x8($a1)
	sw     $t4, 0xc($a1)
	addiu  $t0, $t0, -1
	addiu  $a0, $a0, 0x10
	bnez   $t0, .L00015cdc
	addiu  $a1, $a1, 0x10
	lw     $t0, 0x0($a0)
	jr     $ra
	sw     $t0, 0x0($a1)

glabel mtx4Copy
	addiu  $t0, $zero, 0x4
.L00015d1c:
	lw     $t1, 0x0($a0)
	lw     $t2, 0x4($a0)
	lw     $t3, 0x8($a0)
	lw     $t4, 0xc($a0)
	sw     $t1, 0x0($a1)
	sw     $t2, 0x4($a1)
	sw     $t3, 0x8($a1)
	sw     $t4, 0xc($a1)
	addiu  $t0, $t0, -1
	addiu  $a0, $a0, 0x10
	bnez   $t0, .L00015d1c
	addiu  $a1, $a1, 0x10
	jr     $ra
 	nop

glabel mtx3ToMtx4
	addiu  $t0, $zero, 0x3
	lui    $at, 0x3f80
.L00015d60:
	lw     $t1, 0x0($a0)
	lw     $t2, 0x4($a0)
	lw     $t3, 0x8($a0)
	sw     $t1, 0x0($a1)
	sw     $t2, 0x4($a1)
	sw     $t3, 0x8($a1)
	sw     $zero, 0xc($a1)
	addiu  $t0, $t0, -1
	addiu  $a1, $a1, 0x10
	bnez   $t0, .L00015d60
	addiu  $a0, $a0, 0xc
	sw     $zero, 0x0($a1)
	sw     $zero, 0x4($a1)
	sw     $zero, 0x8($a1)
	jr     $ra
	sw     $at, 0xc($a1)

glabel mtx4ToMtx3
	addiu  $t0, $zero, 0x3
.L00015da4:
	lw     $t1, 0x0($a0)
	lw     $t2, 0x4($a0)
	lw     $t3, 0x8($a0)
	sw     $t1, 0x0($a1)
	sw     $t2, 0x4($a1)
	sw     $t3, 0x8($a1)
	addiu  $t0, $t0, -1
	addiu  $a0, $a0, 0x10
	bnez   $t0, .L00015da4
	addiu  $a1, $a1, 0xc
	jr     $ra
 	nop

glabel mtx4SetTranslation
	lw     $t0, 0x0($a0)
	lw     $t1, 0x4($a0)
	lw     $t2, 0x8($a0)
	sw     $t0, 0x30($a1)
	sw     $t1, 0x34($a1)
	jr     $ra
	sw     $t2, 0x38($a1)

glabel mtx00015df0
	lwc1   $f4, 0x0($a1)
	lwc1   $f6, 0x4($a1)
	mul.s  $f8, $f4, $f12
	lwc1   $f10, 0x8($a1)
	mul.s  $f4, $f6, $f12
	lwc1   $f6, 0xc($a1)
	mul.s  $f10, $f10, $f12
	swc1   $f8, 0x0($a1)
	mul.s  $f6, $f6, $f12
	swc1   $f4, 0x4($a1)
	swc1   $f10, 0x8($a1)
	jr     $ra
	swc1   $f6, 0xc($a1)

glabel mtx00015e24
	lwc1   $f4, 0x0($a1)
	lwc1   $f6, 0x4($a1)
	mul.s  $f8, $f4, $f12
	lwc1   $f10, 0x8($a1)
	mul.s  $f4, $f6, $f12
	swc1   $f8, 0x0($a1)
	mul.s  $f10, $f10, $f12
	swc1   $f4, 0x4($a1)
	jr     $ra
	swc1   $f10, 0x8($a1)

glabel mtx00015e4c
	lwc1   $f4, 0x10($a1)
	lwc1   $f6, 0x14($a1)
	mul.s  $f8, $f4, $f12
	lwc1   $f10, 0x18($a1)
	mul.s  $f4, $f6, $f12
	lwc1   $f6, 0x1c($a1)
	mul.s  $f10, $f10, $f12
	swc1   $f8, 0x10($a1)
	mul.s  $f6, $f6, $f12
	swc1   $f4, 0x14($a1)
	swc1   $f10, 0x18($a1)
	jr     $ra
	swc1   $f6, 0x1c($a1)

glabel mtx00015e80
	lwc1   $f4, 0x10($a1)
	lwc1   $f6, 0x14($a1)
	mul.s  $f8, $f4, $f12
	lwc1   $f10, 0x18($a1)
	mul.s  $f4, $f6, $f12
	swc1   $f8, 0x10($a1)
	mul.s  $f10, $f10, $f12
	swc1   $f4, 0x14($a1)
	jr     $ra
	swc1   $f10, 0x18($a1)

glabel mtx00015ea8
	lwc1   $f4, 0x20($a1)
	lwc1   $f6, 0x24($a1)
	mul.s  $f8, $f4, $f12
	lwc1   $f10, 0x28($a1)
	mul.s  $f4, $f6, $f12
	lwc1   $f6, 0x2c($a1)
	mul.s  $f10, $f10, $f12
	swc1   $f8, 0x20($a1)
	mul.s  $f6, $f6, $f12
	swc1   $f4, 0x24($a1)
	swc1   $f10, 0x28($a1)
	jr     $ra
	swc1   $f6, 0x2c($a1)

glabel mtx00015edc
	lwc1   $f4, 0x20($a1)
	lwc1   $f6, 0x24($a1)
	mul.s  $f8, $f4, $f12
	lwc1   $f10, 0x28($a1)
	mul.s  $f4, $f6, $f12
	swc1   $f8, 0x20($a1)
	mul.s  $f10, $f10, $f12
	swc1   $f4, 0x24($a1)
	jr     $ra
	swc1   $f10, 0x28($a1)

glabel mtx00015f04
	addiu  $t0, $zero, 0x3
.L00015f08:
	lwc1   $f4, 0x0($a1)
	lwc1   $f6, 0x4($a1)
	mul.s  $f4, $f4, $f12
	lwc1   $f8, 0x8($a1)
	mul.s  $f6, $f6, $f12
	lwc1   $f10, 0xc($a1)
	mul.s  $f8, $f8, $f12
	addiu  $a1, $a1, 0x10
	mul.s  $f10, $f10, $f12
	addiu  $t0, $t0, -1
	swc1   $f4, -0x10($a1)
	swc1   $f6, -0xc($a1)
	swc1   $f8, -0x8($a1)
	bnez   $t0, .L00015f08
	swc1   $f10, -0x4($a1)
	jr     $ra
 	nop

glabel mtx00015f4c
	addiu  $t0, $zero, 0x3
.L00015f50:
	lwc1   $f4, 0x0($a1)
	lwc1   $f6, 0x4($a1)
	mul.s  $f4, $f4, $f12
	lwc1   $f8, 0x8($a1)
	mul.s  $f6, $f6, $f12
	addiu  $a1, $a1, 0x10
	mul.s  $f8, $f8, $f12
	addiu  $t0, $t0, -1
	swc1   $f4, -0x10($a1)
	swc1   $f6, -0xc($a1)
	bnez   $t0, .L00015f50
	swc1   $f8, -0x8($a1)
	jr     $ra
 	nop

glabel mtx00015f88
	addiu  $t0, $zero, 0x3
.L00015f8c:
	lwc1   $f4, 0x0($a1)
	lwc1   $f6, 0x10($a1)
	mul.s  $f4, $f4, $f12
	lwc1   $f8, 0x20($a1)
	mul.s  $f6, $f6, $f12
	lwc1   $f10, 0x30($a1)
	mul.s  $f8, $f8, $f12
	addiu  $a1, $a1, 0x4
	mul.s  $f10, $f10, $f12
	addiu  $t0, $t0, -1
	swc1   $f4, -0x4($a1)
	swc1   $f6, 0xc($a1)
	swc1   $f8, 0x1c($a1)
	bnez   $t0, .L00015f8c
	swc1   $f10, 0x2c($a1)
	jr     $ra
 	nop

/**
 * Wait for the PI to be idle, then read the osRomBase variable, obfuscate its
 * value and return it.
 *
 * The returned value is (osRomBase | 0xb764b4fd) ^ 0x0764bea1.
 *
 * The source of this is definitely ASM:
 * - Minimal use of temporary registers
 * - The load of a1 for osRecvMesg and osSendMesg should be li, not addiu
 * - The load of a2 for osRecvMesg and osSendMesg use lui instead of li
 */
glabel mtxGetObfuscatedRomBase
	addiu  $sp, $sp, -0x20
	sw     $ra, 0x14($sp)
	lui    $a0, %hi(__osPiAccessQueue)
	addiu  $a0, $a0, %lo(__osPiAccessQueue)
	addiu  $a1, $zero, 0
	jal    osRecvMesg
	lui    $a2, 1
	lui    $a0, 0xa45f
	ori    $a0, $a0, 0xffff
	addiu  $a0, $a0, 0x11
.L00015ff8:
	lw     $t0, 0x0($a0)
	andi   $t0, $t0, 3
	bnez   $t0, .L00015ff8
 	nop
	lui    $a1, %hi(osRomBase)
	lw     $a1, %lo(osRomBase)($a1)
	lui    $a0, 0xb764
	ori    $a0, $a0, 0xb4fd
	or     $a0, $a0, $a1
	lui    $a1, 0x764
	ori    $a1, $a1, 0xbea1
	xor    $a0, $a0, $a1
	lw     $v0, 0x0($a0)
	sw     $v0, 0x18($sp)
	lui    $a0, %hi(__osPiAccessQueue)
	addiu  $a0, $a0, %lo(__osPiAccessQueue)
	addiu  $a1, $zero, 0
	jal    osSendMesg
	lui    $a2, 0
	lw     $v0, 0x18($sp)
	lw     $ra, 0x14($sp)
	jr     $ra
	addiu  $sp, $sp, 0x20

glabel mtx00016054
	lui    $t2, %hi(var8005ef10)
	addiu  $t2, $t2, %lo(var8005ef10)
	addiu  $t0, $zero, 0x4
	lui    $t1, 0xffff
	lwc1   $f0, 0x0($t2)
	lwc1   $f2, 0x4($t2)
.L0001606c:
	lwc1   $f4, 0x0($a0)
	lwc1   $f6, 0x4($a0)
	mul.s  $f4, $f4, $f0
	lwc1   $f8, 0x8($a0)
	mul.s  $f6, $f6, $f0
	lwc1   $f10, 0xc($a0)
	trunc.w.s $f4, $f4
	mul.s  $f8, $f8, $f0
	mfc1   $t2, $f4
	trunc.w.s $f6, $f6
	mul.s  $f10, $f10, $f2
	mfc1   $t3, $f6
	trunc.w.s $f8, $f8
	and    $t4, $t2, $t1
	srl    $t5, $t3, 0x10
	trunc.w.s $f10, $f10
	or     $t4, $t4, $t5
	mfc1   $t5, $f8
	sll    $t2, $t2, 0x10
	andi   $t3, $t3, 0xffff
	mfc1   $t6, $f10
	or     $t2, $t2, $t3
	and    $t7, $t5, $t1
	sll    $t5, $t5, 0x10
	srl    $t8, $t6, 0x10
	andi   $t6, $t6, 0xffff
	or     $t7, $t7, $t8
	or     $t5, $t5, $t6
	addiu  $a0, $a0, 0x10
	sw     $t4, 0x0($a1)
	sw     $t7, 0x4($a1)
	sw     $t2, 0x20($a1)
	sw     $t5, 0x24($a1)
	addiu  $t0, $t0, -1
	bnez   $t0, .L0001606c
	addiu  $a1, $a1, 0x8
	jr     $ra
 	nop
