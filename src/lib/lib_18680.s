#include "versions.h"
#include "macros.inc"
.set noat
.set noreorder

.data

glabel var8005ef40
.word 0x00040800
.word 0x00000000
.word 0x0c100000
.word 0x00000000
.word 0x00001400
.word 0x0018001c
.word 0x00000000

glabel var8005ef5c
.word func00018680+0xef4
.word func00018680+0xa3c
.word func00018680+0x3a8
.word func00018680+0x990
.word func00018680+0xecc
.word func00018680+0xed4
.word func00018680+0xe60
.word func00018680+0xe24

glabel var8005ef7c
.word 0x00000000

glabel var8005ef80
.word func00019be0+0x84
.word func00019be0+0x90
.word func00019be0+0xa8
.word func00019be0+0xcc

glabel var8005ef90
.word 0xff08ffff
.word 0xffffffff
.word 0x0c22ff44
.word 0x20ffffff
.word 0xffff04ff
.word 0xffffff00
.word 0x14000000

.rdata

glabel var70054210
.word 0xbf7ffcb9

glabel var70054214
.word 0x3f7ffcb9

glabel var70054218
.word 0x40490fdb

glabel var7005421c
.word 0x40c90fdb

glabel var70054220
.word 0x3fc90fda

glabel var70054224
.word 0xbf7ffcb9

glabel var70054228
.word 0x3f7ffcb9

glabel var7005422c
.word 0x38c90fdb

glabel var70054230
.word 0x3fc90fda

glabel var70054234
.word 0x38490fdb

glabel var70054238
.word 0x3fc90fdb

glabel var7005423c
.word 0x46fffe00

glabel var70054240
.word 0x384910a4

glabel var70054244
.word 0x3fc90fda

glabel var70054248
.word 0x362edef8

glabel var7005424c
.word 0xb94fb7ff

glabel var70054250
.word 0x3c08876a

glabel var70054254
.word 0xbe2aaaa6

glabel var70054258
.word 0x3ea2f983

glabel var7005425c
.word 0x40490fdb

glabel var70054260
.word 0x330885a3

glabel var70054264
.word 0x362edef8

glabel var70054268
.word 0xb94fb7ff

glabel var7005426c
.word 0x3c08876a

glabel var70054270
.word 0xbe2aaaa6

.text

glabel func00018680
	addiu  $sp, $sp, -2048
	sw     $s0, 0x780($sp)
	sw     $s1, 0x784($sp)
	sw     $s2, 0x788($sp)
	sw     $s3, 0x78c($sp)
	sw     $s4, 0x790($sp)
	sw     $s5, 0x794($sp)
	sw     $s6, 0x798($sp)
	sw     $s7, 0x79c($sp)
	sw     $s8, 0x7a0($sp)
	sw     $gp, 0x7a4($sp)
	sw     $ra, 0x7a8($sp)
	swc1   $f20, 0x7b0($sp)
	swc1   $f21, 0x7b4($sp)
	swc1   $f22, 0x7b8($sp)
	swc1   $f23, 0x7bc($sp)
	swc1   $f24, 0x7c0($sp)
	swc1   $f25, 0x7c4($sp)
	swc1   $f26, 0x7c8($sp)
	swc1   $f27, 0x7cc($sp)
	swc1   $f28, 0x7d0($sp)
	swc1   $f29, 0x7d4($sp)
	swc1   $f30, 0x7d8($sp)
	swc1   $f31, 0x7dc($sp)
	sw     $zero, 0x7f8($sp)
	lui    $at, 0x3f80
	mtc1   $at, $f31
	or     $t0, $sp, $zero
	lw     $t1, 0x8($a1)
	lhu    $t1, 0xe($t1)
.L000186f8:
	sh     $zero, 0x0($t0)
	addiu  $t1, $t1, -1
	bnezl  $t1, .L000186f8
	addiu  $t0, $t0, 0x8
	add    $t0, $zero, $a1
	lw     $a2, 0x20($a1)
	beqz   $a2, .L000189cc
 	nop
	or     $t0, $sp, $zero
	addi   $t1, $zero, 0x0
	lui    $t4, %hi(var8005f010)
	addiu  $t4, $t4, %lo(var8005f010)
	lw     $t4, 0x0($t4)
	lh     $t5, 0x0($a2)
	add    $t4, $t4, $t5
	lbu    $t3, 0x0($t4)
	lui    $t4, %hi(var8009a888)
	addiu  $t4, $t4, %lo(var8009a888)
	lw     $t4, 0x0($t4)
	sll    $t3, $t3, 0x2
	add    $t4, $t4, $t3
	lw     $t2, 0x0($t4)
	lui    $t4, %hi(g_Anims)
	addiu  $t4, $t4, %lo(g_Anims)
	lw     $t4, 0x0($t4)
	sll    $t5, $t5, 0x2
	add    $t6, $t5, $t5
	add    $t5, $t5, $t6
	add    $t4, $t4, $t5
	lh     $t5, 0x8($t4)
	lbu    $t4, 0xa($t4)
	add    $t3, $t2, $t5
	lui    $t5, %hi(var8009a874)
	addiu  $t5, $t5, %lo(var8009a874)
	lw     $t5, 0x0($t5)
	beq    $t2, $t3, .L00018874
	addi   $v0, $zero, 0x0
	lbu    $t6, 0x4($a2)
	sll    $t6, $t6, 0x2
	add    $t6, $t5, $t6
	lw     $t6, 0x0($t6)
	jal    func00019634
	addi   $gp, $zero, 0x0
	mtc1   $zero, $f1
	lwc1   $f0, 0x10($a2)
	c.eq.s $f1, $f0
	bc1t   .L00018874
 	nop
	or     $t0, $sp, $zero
	addiu  $t0, $t0, 0x3c0
	lw     $t1, 0x8($a1)
	lhu    $t1, 0xe($t1)
.L000187c8:
	sh     $zero, 0x0($t0)
	addiu  $t1, $t1, -1
	bnezl  $t1, .L000187c8
	addiu  $t0, $t0, 0x8
	lui    $at, 0x4580
	mtc1   $at, $f2
	or     $t0, $sp, $zero
	mul.s  $f0, $f0, $f2
	addi   $t1, $zero, 0x0
	trunc.w.s $f0, $f0
	lui    $t4, %hi(var8005f010)
	addiu  $t4, $t4, %lo(var8005f010)
	lw     $t4, 0x0($t4)
	lh     $t5, 0x0($a2)
	add    $t4, $t4, $t5
	lbu    $t3, 0x0($t4)
	lui    $t4, %hi(var8009a888)
	addiu  $t4, $t4, %lo(var8009a888)
	lw     $t4, 0x0($t4)
	sll    $t3, $t3, 0x2
	add    $t4, $t4, $t3
	lw     $t2, 0x0($t4)
	lui    $t4, %hi(g_Anims)
	addiu  $t4, $t4, %lo(g_Anims)
	lw     $t4, 0x0($t4)
	sll    $t5, $t5, 0x2
	add    $t6, $t5, $t5
	add    $t5, $t5, $t6
	add    $t4, $t4, $t5
	lh     $t5, 0x8($t4)
	lbu    $t4, 0xa($t4)
	add    $t3, $t2, $t5
	lui    $t5, %hi(var8009a874)
	addiu  $t5, $t5, %lo(var8009a874)
	lw     $t5, 0x0($t5)
	beq    $t2, $t3, .L00018874
	addi   $v0, $zero, 0x0
	lbu    $t6, 0x5($a2)
	sll    $t6, $t6, 0x2
	add    $t6, $t5, $t6
	lw     $t6, 0x0($t6)
	jal    func000198dc
	addi   $gp, $zero, 0x0
.L00018874:
	mtc1   $zero, $f1
	lwc1   $f0, 0x54($a2)
	c.eq.s $f0, $f1
	bc1t   .L000189cc
	swc1   $f0, 0x7e0($sp)
	or     $t0, $sp, $zero
	addiu  $t0, $t0, 0x3c0
	addi   $t1, $zero, 0x0
	lui    $t4, %hi(var8005f010)
	addiu  $t4, $t4, %lo(var8005f010)
	lw     $t4, 0x0($t4)
	lh     $t5, 0x2($a2)
	add    $t4, $t4, $t5
	lbu    $t3, 0x0($t4)
	lui    $t4, %hi(var8009a888)
	addiu  $t4, $t4, %lo(var8009a888)
	lw     $t4, 0x0($t4)
	sll    $t3, $t3, 0x2
	add    $t4, $t4, $t3
	lw     $t2, 0x0($t4)
	lui    $t4, %hi(g_Anims)
	addiu  $t4, $t4, %lo(g_Anims)
	lw     $t4, 0x0($t4)
	sll    $t5, $t5, 0x2
	add    $t6, $t5, $t5
	add    $t5, $t5, $t6
	add    $t4, $t4, $t5
	lh     $t5, 0x8($t4)
	lbu    $t4, 0xa($t4)
	add    $t3, $t2, $t5
	lui    $t5, %hi(var8009a874)
	addiu  $t5, $t5, %lo(var8009a874)
	lw     $t5, 0x0($t5)
	beq    $t2, $t3, .L000189cc
	addi   $v0, $zero, 0x0
	lbu    $t6, 0x6($a2)
	sll    $t6, $t6, 0x2
	add    $t6, $t5, $t6
	lw     $t6, 0x0($t6)
	jal    func00019634
	addi   $gp, $zero, 0x0
	mtc1   $zero, $f1
	lwc1   $f0, 0x34($a2)
	c.eq.s $f1, $f0
	bc1t   .L000189cc
 	nop
	lui    $at, 0x4580
	mtc1   $at, $f2
	or     $t0, $sp, $zero
	addiu  $t0, $t0, 0x3c0
	mul.s  $f0, $f0, $f2
	addi   $t1, $zero, 0x0
	trunc.w.s $f0, $f0
	lui    $t4, %hi(var8005f010)
	addiu  $t4, $t4, %lo(var8005f010)
	lw     $t4, 0x0($t4)
	lh     $t5, 0x2($a2)
	add    $t4, $t4, $t5
	lbu    $t3, 0x0($t4)
	lui    $t4, %hi(var8009a888)
	addiu  $t4, $t4, %lo(var8009a888)
	lw     $t4, 0x0($t4)
	sll    $t3, $t3, 0x2
	add    $t4, $t4, $t3
	lw     $t2, 0x0($t4)
	lui    $t4, %hi(g_Anims)
	addiu  $t4, $t4, %lo(g_Anims)
	lw     $t4, 0x0($t4)
	sll    $t5, $t5, 0x2
	add    $t6, $t5, $t5
	add    $t5, $t5, $t6
	add    $t4, $t4, $t5
	lh     $t5, 0x8($t4)
	lbu    $t4, 0xa($t4)
	add    $t3, $t2, $t5
	lui    $t5, %hi(var8009a874)
	addiu  $t5, $t5, %lo(var8009a874)
	lw     $t5, 0x0($t5)
	beq    $t2, $t3, .L000189cc
	addi   $v0, $zero, 0x0
	lbu    $t6, 0x7($a2)
	sll    $t6, $t6, 0x2
	add    $t6, $t5, $t6
	lw     $t6, 0x0($t6)
	jal    func000198dc
	addi   $gp, $zero, 0x0
.L000189cc:
	lw     $a3, 0x8($a1)
	lw     $gp, 0x0($a3)
	lw     $s6, 0x4($a3)
	or     $s7, $sp, $zero
	beqz   $gp, .L000195c8
	addiu  $v0, $v0, 0x1
.L000189e4:
	lui    $t1, %hi(var8005ef40)
	addiu  $t1, $t1, %lo(var8005ef40)
	lhu    $t0, 0x0($gp)
	andi   $t0, $t0, 0xff
	add    $t0, $t0, $t1
	lui    $t1, %hi(var8005ef5c)
	addiu  $t1, $t1, %lo(var8005ef5c)
	lbu    $t0, 0x0($t0)
	add    $t0, $t1, $t0
	lw     $t1, 0x0($t0)
	lhu    $t0, 0x0($gp)
	jr     $t1
	andi   $t0, $t0, 0xff
	beqz   $gp, .L000195c8
	addiu  $v0, $v0, 0x1
	lh     $t0, 0x0($gp)
	andi   $t0, $t0, 0xff
	sw     $zero, 0x7e4($sp)
	beqz   $a1, .L0001900c
	lw     $t0, 0x4($gp)
	beqz   $a2, .L00018fd8
	lhu    $t1, 0xc($t0)
	lhu    $t2, 0x0($a2)
	mtc1   $zero, $f29
	lwc1   $f30, 0x7e0($sp)
	c.eq.s $f29, $f30
	bc1t   .L00018ba8
 	nop
	lbu    $t2, 0x8($a2)
	beqz   $t2, .L00018ab0
 	nop
	lw     $t2, 0x4($s6)
	sll    $t1, $t1, 0x1
	add    $t2, $t2, $t1
	lbu    $t1, 0x1($t2)
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lhu    $s8, 0x0($t0)
	lui    $t2, 0x1
	lhu    $t4, 0x6($t0)
	bnez   $t4, .L00018a90
	sub    $t4, $t2, $t4
	addi   $t4, $zero, 0x0
.L00018a90:
	lhu    $t3, 0x4($t0)
	bnez   $t3, .L00018aa0
	sub    $t3, $t2, $t3
	addi   $t3, $zero, 0x0
.L00018aa0:
	andi   $t3, $t3, 0xffff
	andi   $t4, $t4, 0xffff
	j      .L00018ac8
	lhu    $t2, 0x2($t0)
.L00018ab0:
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lhu    $s8, 0x0($t0)
	lhu    $t2, 0x2($t0)
	lhu    $t3, 0x4($t0)
	lhu    $t4, 0x6($t0)
.L00018ac8:
	lw     $s0, 0x4($gp)
	lbu    $s1, 0x9($a2)
	beqz   $s1, .L00018b28
	lhu    $t1, 0xc($s0)
	lw     $s0, 0x4($s6)
	sll    $t1, $t1, 0x1
	add    $s0, $s0, $t1
	lbu    $t1, 0x1($s0)
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lui    $s0, 0x1
	lhu    $s4, 0x3c6($t0)
	bnez   $s4, .L00018b04
	sub    $s4, $s0, $s4
	addi   $s4, $zero, 0x0
.L00018b04:
	lhu    $s3, 0x3c4($t0)
	bnez   $s3, .L00018b14
	sub    $s3, $s0, $s3
	addi   $s3, $zero, 0x0
.L00018b14:
	andi   $s3, $s3, 0xffff
	andi   $s4, $s4, 0xffff
	lhu    $s0, 0x2($t0)
	b      .L00018b3c
	lhu    $s2, 0x3c2($t0)
.L00018b28:
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lhu    $s2, 0x3c2($t0)
	lhu    $s3, 0x3c4($t0)
	lhu    $s4, 0x3c6($t0)
.L00018b3c:
	jal    func0001a024
	sw     $t0, 0x7e8($sp)
	jal    func00019f2c
 	nop
	mov.s  $f16, $f0
	mov.s  $f17, $f1
	mov.s  $f18, $f2
	mov.s  $f19, $f3
	or     $t2, $s2, $zero
	or     $t3, $s3, $zero
	jal    func0001a024
	or     $t4, $s4, $zero
	jal    func00019f2c
 	nop
	jal    func00019ddc
	lwc1   $f30, 0x7e0($sp)
	addiu  $t0, $zero, 0x1
	sw     $t0, 0x7e4($sp)
	lw     $t0, 0x7e8($sp)
	swc1   $f0, 0x7e8($sp)
	swc1   $f1, 0x7ec($sp)
	swc1   $f2, 0x7f0($sp)
	swc1   $f3, 0x7f4($sp)
	jal    func0001a110
 	nop
	j      .L00018c6c
 	nop
.L00018ba8:
	lbu    $t2, 0x8($a2)
	beqz   $t2, .L00018c04
 	nop
	lw     $t2, 0x4($s6)
	sll    $t1, $t1, 0x1
	add    $t2, $t2, $t1
	lbu    $t1, 0x1($t2)
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lhu    $s8, 0x0($t0)
	lui    $t2, 0x1
	lhu    $t4, 0x6($t0)
	bnez   $t4, .L00018be4
	sub    $t4, $t2, $t4
	addi   $t4, $zero, 0x0
.L00018be4:
	lhu    $t3, 0x4($t0)
	bnez   $t3, .L00018bf4
	sub    $t3, $t2, $t3
	addi   $t3, $zero, 0x0
.L00018bf4:
	andi   $t3, $t3, 0xffff
	andi   $t4, $t4, 0xffff
	b      .L00018c1c
	lhu    $t2, 0x2($t0)
.L00018c04:
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lhu    $s8, 0x0($t0)
	lhu    $t4, 0x6($t0)
	lhu    $t3, 0x4($t0)
	lhu    $t2, 0x2($t0)
.L00018c1c:
	andi   $t5, $s8, 0x1
	bnez   $t5, .L00018c50
	add    $s0, $zero, $t2
	mtc1   $zero, $f13
	mov.s  $f12, $f31
	mov.s  $f16, $f31
	mov.s  $f20, $f31
	mov.s  $f14, $f13
	mov.s  $f15, $f13
	mov.s  $f17, $f13
	mov.s  $f18, $f13
	j      .L00018c6c
	mov.s  $f19, $f13
.L00018c50:
	add    $s0, $zero, $t2
	add    $s1, $zero, $t3
	add    $s2, $zero, $t4
	jal    func00019f98
	add    $s3, $zero, $t0
	jal    func0001a0ac
	add    $t0, $zero, $s3
.L00018c6c:
	andi   $t2, $s8, 0x2
	beqz   $t2, .L00018d04
 	nop
	lh     $t2, 0x1e0($t0)
	lh     $t3, 0x1e2($t0)
	lh     $t4, 0x1e4($t0)
	lw     $t5, 0x0($a3)
	bne    $t5, $gp, .L00018cc0
	lw     $t0, 0x4($gp)
	lwc1   $f0, 0x88($a2)
	mtc1   $t2, $f21
	mtc1   $t3, $f22
	cvt.s.w $f21, $f21
	mul.s  $f21, $f21, $f0
	mtc1   $t4, $f23
	cvt.s.w $f22, $f22
	mul.s  $f22, $f22, $f0
	cvt.s.w $f23, $f23
	mul.s  $f23, $f23, $f0
	b      .L00018d2c
 	nop
.L00018cc0:
	lwc1   $f3, 0x88($a2)
	mtc1   $t2, $f0
	mtc1   $t3, $f1
	cvt.s.w $f0, $f0
	mul.s  $f0, $f0, $f3
	mtc1   $t4, $f2
	cvt.s.w $f1, $f1
	mul.s  $f1, $f1, $f3
	cvt.s.w $f2, $f2
	mul.s  $f2, $f2, $f3
	lwc1   $f21, 0x0($t0)
	lwc1   $f22, 0x4($t0)
	lwc1   $f23, 0x8($t0)
	add.s  $f21, $f21, $f0
	add.s  $f22, $f22, $f1
	b      .L00018d2c
	add.s  $f23, $f23, $f2
.L00018d04:
	lw     $t2, 0x0($a3)
	beq    $gp, $t2, .L00018d20
	lw     $t0, 0x4($gp)
	lwc1   $f21, 0x0($t0)
	lwc1   $f22, 0x4($t0)
	j      .L00018d2c
	lwc1   $f23, 0x8($t0)
.L00018d20:
	mtc1   $zero, $f21
	mtc1   $zero, $f22
	mtc1   $zero, $f23
.L00018d2c:
	lw     $t0, 0x8($gp)
	beqz   $t0, .L00018d48
 	nop
	jal    func0001a25c
 	nop
	b      .L00018d4c
 	nop
.L00018d48:
	lw     $t0, 0x0($a0)
.L00018d4c:
	lw     $t1, 0x4($gp)
	lhu    $t2, 0xe($t1)
	sll    $t2, $t2, 0x6
	lw     $t1, 0xc($a1)
	jal    func0001a1c0
	add    $t1, $t1, $t2
	lui    $t3, %hi(var8005efcc)
	addiu  $t3, $t3, %lo(var8005efcc)
	lw     $t3, 0x0($t3)
	beqz   $t3, .L00018e80
 	nop
	addiu  $sp, $sp, -128
	sw     $ra, 0x0($sp)
	sw     $at, 0x4($sp)
	sw     $v0, 0x8($sp)
	sw     $v1, 0xc($sp)
	sw     $a0, 0x10($sp)
	sw     $a1, 0x14($sp)
	sw     $a2, 0x18($sp)
	sw     $a3, 0x1c($sp)
	sw     $t0, 0x20($sp)
	sw     $t1, 0x24($sp)
	sw     $t2, 0x28($sp)
	sw     $t3, 0x2c($sp)
	sw     $t4, 0x30($sp)
	sw     $t5, 0x34($sp)
	sw     $t6, 0x38($sp)
	sw     $t7, 0x3c($sp)
	sw     $s0, 0x40($sp)
	sw     $s1, 0x44($sp)
	sw     $s2, 0x48($sp)
	sw     $s3, 0x4c($sp)
	sw     $s4, 0x50($sp)
	sw     $s5, 0x54($sp)
	sw     $s6, 0x58($sp)
	sw     $s7, 0x5c($sp)
	sw     $t8, 0x60($sp)
	sw     $t9, 0x64($sp)
	sw     $gp, 0x70($sp)
	sw     $sp, 0x74($sp)
	sw     $s8, 0x78($sp)
	lw     $t1, 0x4($gp)
	lhu    $a0, 0xe($t1)
	sll    $t2, $a0, 0x6
	lw     $t1, 0xc($a1)
	jalr   $t3
	add    $a1, $t1, $t2
	lw     $ra, 0x0($sp)
	lw     $at, 0x4($sp)
	lw     $v0, 0x8($sp)
	lw     $v1, 0xc($sp)
	lw     $a0, 0x10($sp)
	lw     $a1, 0x14($sp)
	lw     $a2, 0x18($sp)
	lw     $a3, 0x1c($sp)
	lw     $t0, 0x20($sp)
	lw     $t1, 0x24($sp)
	lw     $t2, 0x28($sp)
	lw     $t3, 0x2c($sp)
	lw     $t4, 0x30($sp)
	lw     $t5, 0x34($sp)
	lw     $t6, 0x38($sp)
	lw     $t7, 0x3c($sp)
	lw     $s0, 0x40($sp)
	lw     $s1, 0x44($sp)
	lw     $s2, 0x48($sp)
	lw     $s3, 0x4c($sp)
	lw     $s4, 0x50($sp)
	lw     $s5, 0x54($sp)
	lw     $s6, 0x58($sp)
	lw     $s7, 0x5c($sp)
	lw     $t8, 0x60($sp)
	lw     $t9, 0x64($sp)
	lw     $gp, 0x70($sp)
	lw     $sp, 0x74($sp)
	lw     $s8, 0x78($sp)
	addiu  $sp, $sp, 0x80
.L00018e80:
	lh     $t2, 0x0($gp)
	andi   $t2, $t2, 0x100
	beqz   $t2, .L00019574
 	nop
	lw     $v0, 0x7e4($sp)
	beqz   $v0, .L00018eb0
	addiu  $t0, $t0, -12
	lwc1   $f0, 0x7e8($sp)
	lwc1   $f1, 0x7ec($sp)
	lwc1   $f2, 0x7f0($sp)
	j      .L00018ecc
	lwc1   $f3, 0x7f4($sp)
.L00018eb0:
	add    $t2, $zero, $s0
	add    $t3, $zero, $s1
	add    $t4, $zero, $s2
	jal    func0001a024
	add    $s0, $zero, $t0
	jal    func00019f2c
	add    $t0, $zero, $s0
.L00018ecc:
	lui    $at, 0x3f00
	mtc1   $at, $f8
	mtc1   $zero, $f4
	mov.s  $f6, $f0
	lui    $at, %hi(var70054210)
	lwc1   $f7, %lo(var70054210)($at)
	c.lt.s $f6, $f4
	bc1f   .L00018ef8
	mov.s  $f5, $f31
	neg.s  $f6, $f6
	neg.s  $f5, $f5
.L00018ef8:
	c.lt.s $f6, $f7
	lui    $at, %hi(var70054214)
	lwc1   $f7, %lo(var70054214)($at)
	bc1f   .L00018f38
 	nop
	mul.s  $f0, $f0, $f8
 	nop
	mul.s  $f4, $f5, $f8
 	nop
	mul.s  $f1, $f1, $f8
 	nop
	mul.s  $f2, $f2, $f8
 	nop
	mul.s  $f3, $f3, $f8
	b      .L00018fb4
	sub.s  $f0, $f0, $f4
.L00018f38:
	c.le.s $f6, $f7
	bc1f   .L00018f8c
 	nop
	jal    func0001a2dc
 	nop
	mov.s  $f17, $f0
	mul.s  $f12, $f6, $f8
	add    $s0, $zero, $t0
	jal    sinf
	add    $s1, $zero, $t1
	mul.s  $f3, $f3, $f0
	add    $t0, $zero, $s0
	mul.s  $f2, $f2, $f0
	add    $t1, $zero, $s1
	mul.s  $f1, $f1, $f0
 	nop
	mul.s  $f5, $f5, $f0
 	nop
	mul.s  $f0, $f0, $f17
	b      .L00018fb4
	add.s  $f0, $f0, $f5
.L00018f8c:
	mul.s  $f0, $f0, $f8
 	nop
	mul.s  $f4, $f5, $f8
 	nop
	mul.s  $f1, $f1, $f8
 	nop
	mul.s  $f2, $f2, $f8
 	nop
	mul.s  $f3, $f3, $f8
	add.s  $f0, $f0, $f4
.L00018fb4:
	jal    func0001a110
	lw     $t1, 0x4($gp)
	lhu    $t2, 0x10($t1)
	sll    $t2, $t2, 0x6
	lw     $t1, 0xc($a1)
	jal    func0001a1c0
	add    $t1, $t1, $t2
	j      .L00019574
 	nop
.L00018fd8:
	mtc1   $zero, $f13
	mov.s  $f12, $f31
	mov.s  $f16, $f31
	mov.s  $f20, $f31
	mov.s  $f14, $f13
	mov.s  $f15, $f13
	mov.s  $f17, $f13
	mov.s  $f18, $f13
	mov.s  $f19, $f13
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	j      .L00018c6c
	lhu    $s8, 0x0($t0)
.L0001900c:
 	syscall
	jal    func0001a25c
	add    $t0, $zero, $gp
	lui    $t2, %hi(g_ModelDistanceDisabled)
	addiu  $t2, $t2, %lo(g_ModelDistanceDisabled)
	jal    func00019d1c
	lw     $t1, 0x4($gp)
	lw     $t2, 0x0($t2)
	bnez   $t2, .L00019068
	mtc1   $zero, $f0
	beqz   $t0, .L00019068
	mtc1   $zero, $f0
	lui    $t2, %hi(g_Vars)
	addiu  $t2, $t2, %lo(g_Vars)
	lwc1   $f0, 0x38($t0)
	lw     $t2, 0x284($t2)
	neg.s  $f0, $f0
	lwc1   $f1, 0x1774($t2)
	mul.s  $f0, $f0, $f1
	lui    $t0, %hi(g_ModelDistanceScale)
	addiu  $t0, $t0, %lo(g_ModelDistanceScale)
	lwc1   $f1, 0x0($t0)
	mul.s  $f0, $f0, $f1
.L00019068:
	lwc1   $f1, 0x0($t1)
	lwc1   $f2, 0x14($a1)
	mtc1   $zero, $f4
	mul.s  $f3, $f1, $f2
	c.eq.s $f1, $f4
	bc1t   .L00019090
	lwc1   $f4, 0x4($t1)
	c.lt.s $f3, $f0
	bc1f   .L000190b0
 	nop
.L00019090:
	mul.s  $f3, $f4, $f2
	c.le.s $f0, $f3
	bc1f   .L000190b0
	lw     $t1, 0x8($t1)
	addiu  $t0, $zero, 0x1
	sw     $t0, 0x0($v0)
	j      .L00019574
	sw     $t1, 0x14($gp)
.L000190b0:
	sw     $zero, 0x0($v0)
	j      .L00019574
	sw     $zero, 0x14($gp)
	beqz   $a1, .L000194a0
	lw     $t0, 0x4($gp)
	lhu    $t2, 0x0($a2)
	beqz   $a2, .L0001946c
	lhu    $t1, 0x0($t0)
	mtc1   $zero, $f29
	lwc1   $f30, 0x7e0($sp)
	c.eq.s $f29, $f30
	bc1t   .L00019220
 	nop
	lbu    $t2, 0x8($a2)
	beqz   $t2, .L00019140
 	nop
	lw     $t2, 0x4($s6)
	sll    $t1, $t1, 0x1
	add    $t2, $t2, $t1
	lbu    $t1, 0x1($t2)
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lhu    $s8, 0x0($t0)
	lui    $t2, 0x1
	lhu    $t4, 0x6($t0)
	bnez   $t4, .L00019120
	sub    $t4, $t2, $t4
	addi   $t4, $zero, 0x0
.L00019120:
	lhu    $t3, 0x4($t0)
	bnez   $t3, .L00019130
	sub    $t3, $t2, $t3
	addi   $t3, $zero, 0x0
.L00019130:
	andi   $t3, $t3, 0xffff
	andi   $t4, $t4, 0xffff
	j      .L00019158
	lhu    $t2, 0x2($t0)
.L00019140:
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lhu    $s8, 0x0($t0)
	lhu    $t2, 0x2($t0)
	lhu    $t3, 0x4($t0)
	lhu    $t4, 0x6($t0)
.L00019158:
	lw     $s0, 0x4($gp)
	lbu    $s1, 0x9($a2)
	beqz   $s1, .L000191b8
	lhu    $t1, 0x0($s0)
	lw     $s0, 0x4($s6)
	sll    $t1, $t1, 0x1
	add    $s0, $s0, $t1
	lbu    $t1, 0x1($s0)
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lui    $s0, 0x1
	lhu    $s4, 0x3c6($t0)
	bnez   $s4, .L00019194
	sub    $s4, $s0, $s4
	addi   $s4, $zero, 0x0
.L00019194:
	lhu    $s3, 0x3c4($t0)
	bnez   $s3, .L000191a4
	sub    $s3, $s0, $s3
	addi   $s3, $zero, 0x0
.L000191a4:
	andi   $s3, $s3, 0xffff
	andi   $s4, $s4, 0xffff
	lhu    $s0, 0x2($t0)
	b      .L000191cc
	lhu    $s2, 0x3c2($t0)
.L000191b8:
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lhu    $s2, 0x3c2($t0)
	lhu    $s3, 0x3c4($t0)
	lhu    $s4, 0x3c6($t0)
.L000191cc:
	jal    func0001a024
	sw     $t0, 0x7e8($sp)
	jal    func00019f2c
 	nop
	mov.s  $f16, $f0
	mov.s  $f17, $f1
	mov.s  $f18, $f2
	mov.s  $f19, $f3
	or     $t2, $s2, $zero
	or     $t3, $s3, $zero
	jal    func0001a024
	or     $t4, $s4, $zero
	jal    func00019f2c
 	nop
	jal    func00019ddc
	lwc1   $f30, 0x7e0($sp)
	lw     $t0, 0x7e8($sp)
	jal    func0001a110
 	nop
	j      .L000192a8
 	nop
.L00019220:
	lbu    $t2, 0x8($a2)
	beqz   $t2, .L00019284
	lhu    $t1, 0x0($t0)
	lw     $t2, 0x4($s6)
	sll    $t1, $t1, 0x1
	add    $t2, $t2, $t1
	lbu    $t1, 0x1($t2)
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lhu    $s8, 0x0($t0)
	lui    $t2, 0x1
	lhu    $t4, 0x6($t0)
	bnez   $t4, .L0001925c
	sub    $t4, $t2, $t4
	addi   $t4, $zero, 0x0
.L0001925c:
	lhu    $t3, 0x4($t0)
	bnez   $t3, .L0001926c
	sub    $t3, $t2, $t3
	addi   $t3, $zero, 0x0
.L0001926c:
	andi   $t3, $t3, 0xffff
	andi   $t4, $t4, 0xffff
	jal    func00019f98
	lhu    $t2, 0x2($t0)
	b      .L000192a0
 	nop
.L00019284:
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	lhu    $s8, 0x0($t0)
	lhu    $t4, 0x6($t0)
	lhu    $t3, 0x4($t0)
	jal    func00019f98
	lhu    $t2, 0x2($t0)
.L000192a0:
	jal    func0001a0ac
 	nop
.L000192a8:
	jal    func00019d1c
	mtc1   $zero, $f0
	mov.s  $f27, $f12
	mov.s  $f28, $f13
	mov.s  $f29, $f14
	mov.s  $f30, $f15
	lwc1   $f1, 0x18($v0)
	c.eq.s $f0, $f1
	bc1t   .L0001933c
	lwc1   $f12, 0x14($v0)
	lwc1   $f3, 0x1c($v0)
	lui    $at, %hi(var70054218)
	lwc1   $f4, %lo(var70054218)($at)
	sub.s  $f5, $f3, $f12
	lui    $at, %hi(var7005421c)
	lwc1   $f6, %lo(var7005421c)($at)
	c.lt.s $f5, $f0
	bc1f   .L000192f8
 	nop
	add.s  $f5, $f5, $f6
.L000192f8:
	c.lt.s $f5, $f4
	bc1t   .L00019320
 	nop
	mul.s  $f5, $f5, $f1
	add.s  $f12, $f12, $f5
	c.le.s $f12, $f6
	bc1t   .L0001933c
 	nop
	j      .L0001933c
	sub.s  $f12, $f12, $f6
.L00019320:
	sub.s  $f5, $f6, $f5
	mul.s  $f5, $f5, $f1
	sub.s  $f12, $f12, $f5
	c.lt.s $f12, $f0
	bc1f   .L0001933c
 	nop
	add.s  $f12, $f12, $f6
.L0001933c:
	lui    $at, %hi(var70054220)
	lwc1   $f1, %lo(var70054220)($at)
	jal    sinf
	add.s  $f1, $f12, $f1
	mov.s  $f12, $f1
	jal    sinf
	mov.s  $f1, $f0
	neg.s  $f2, $f1
	mov.s  $f12, $f27
	mov.s  $f13, $f28
	mov.s  $f14, $f29
	mov.s  $f15, $f30
	lwc1   $f21, 0x8($v0)
	lwc1   $f22, 0xc($v0)
	lwc1   $f23, 0x10($v0)
	mul.s  $f3, $f0, $f12
 	nop
	mul.s  $f4, $f1, $f14
 	nop
	mul.s  $f5, $f0, $f15
	add.s  $f3, $f3, $f4
	mul.s  $f6, $f1, $f17
 	nop
	mul.s  $f7, $f0, $f18
	add.s  $f5, $f5, $f6
	mul.s  $f8, $f1, $f20
 	nop
	mul.s  $f9, $f2, $f12
	add.s  $f7, $f7, $f8
	mul.s  $f10, $f0, $f14
 	nop
	mul.s  $f4, $f2, $f15
	add.s  $f14, $f9, $f10
	mul.s  $f6, $f0, $f17
 	nop
	mul.s  $f8, $f2, $f18
	add.s  $f17, $f4, $f6
	mul.s  $f10, $f0, $f20
	mov.s  $f12, $f3
	add.s  $f20, $f8, $f10
	mov.s  $f15, $f5
	mov.s  $f18, $f7
	lwc1   $f0, 0x14($a1)
	c.eq.s $f31, $f0
	bc1t   .L00019438
 	nop
	mul.s  $f12, $f12, $f0
 	nop
	mul.s  $f13, $f13, $f0
 	nop
	mul.s  $f14, $f14, $f0
 	nop
	mul.s  $f15, $f15, $f0
 	nop
	mul.s  $f16, $f16, $f0
 	nop
	mul.s  $f17, $f17, $f0
 	nop
	mul.s  $f18, $f18, $f0
 	nop
	mul.s  $f19, $f19, $f0
 	nop
	mul.s  $f20, $f20, $f0
.L00019438:
	lw     $t0, 0x8($gp)
	beqz   $t0, .L00019448
 	nop
 	syscall
.L00019448:
	lw     $t1, 0x4($gp)
	lw     $t0, 0x0($a0)
	lhu    $t2, 0x2($t1)
	sll    $t2, $t2, 0x6
	lw     $t1, 0xc($a1)
	jal    func0001a1c0
	add    $t1, $t1, $t2
	j      .L00019574
 	nop
.L0001946c:
	mtc1   $zero, $f13
	mov.s  $f12, $f31
	mov.s  $f16, $f31
	mov.s  $f20, $f31
	mov.s  $f14, $f13
	mov.s  $f15, $f13
	mov.s  $f17, $f13
	mov.s  $f18, $f13
	mov.s  $f19, $f13
	sll    $t1, $t1, 0x3
	add    $t0, $s7, $t1
	j      .L000192a8
	lhu    $s8, 0x0($t0)
.L000194a0:
 	syscall
	jal    func00019d1c
 	nop
	lw     $t1, 0x0($v0)
	beqz   $t1, .L00019574
 	nop
	sw     $sp, 0x7f8($sp)
	lw     $t2, 0x0($t1)
	beqz   $t2, .L00019574
	sw     $t2, 0x14($gp)
.L000194c8:
	sw     $gp, 0x8($t2)
	lw     $t2, 0xc($t2)
	bnez   $t2, .L000194c8
 	nop
	j      .L00019574
 	nop
	lw     $t0, 0x8($gp)
	bnez   $t0, .L000194f4
 	nop
	j      .L000194fc
	lw     $t0, 0x0($a0)
.L000194f4:
	jal    func0001a25c
 	nop
.L000194fc:
	lw     $t1, 0x4($gp)
	mtc1   $zero, $f13
	mov.s  $f12, $f31
	mov.s  $f16, $f31
	mov.s  $f20, $f31
	mov.s  $f14, $f13
	mov.s  $f15, $f13
	mov.s  $f17, $f13
	mov.s  $f18, $f13
	mov.s  $f19, $f13
	lwc1   $f21, 0x0($t1)
	lwc1   $f22, 0x4($t1)
	lwc1   $f23, 0x8($t1)
	lhu    $t2, 0xc($t1)
	sll    $t2, $t2, 0x6
	lw     $t1, 0xc($a1)
	jal    func0001a1c0
	add    $t1, $t1, $t2
	j      .L00019574
 	nop
	j      .L00019574
 	nop
	jal    func00019d1c
	lw     $t0, 0x4($gp)
	lw     $t1, 0x0($v0)
	beqz   $t1, .L00019570
	lw     $t1, 0x0($t0)
	j      .L00019574
	sw     $t1, 0x14($gp)
.L00019570:
	sw     $zero, 0x14($gp)
.L00019574:
	lw     $t0, 0x14($gp)
	beqz   $t0, .L00019588
 	nop
	j      .L000189e4
	add    $gp, $zero, $t0
.L00019588:
	lw     $t0, 0xc($gp)
	beqz   $t0, .L0001959c
 	nop
	j      .L000189e4
	add    $gp, $zero, $t0
.L0001959c:
	lw     $gp, 0x8($gp)
	beqz   $gp, .L000195c8
 	nop
	lhu    $t0, 0x0($gp)
	andi   $t0, $t0, 0xff
	addiu  $at, $zero, 0x17
	bne    $t0, $at, .L00019588
 	nop
	sw     $t0, 0x7f8($sp)
	bnez   $gp, .L00019588
 	nop
.L000195c8:
	addiu  $v0, $zero, 0x1
.L000195cc:
	lw     $s0, 0x780($sp)
	lw     $s1, 0x784($sp)
	lw     $s2, 0x788($sp)
	lw     $s3, 0x78c($sp)
	lw     $s4, 0x790($sp)
	lw     $s5, 0x794($sp)
	lw     $s6, 0x798($sp)
	lw     $s7, 0x79c($sp)
	lw     $s8, 0x7a0($sp)
	lw     $gp, 0x7a4($sp)
	lw     $ra, 0x7a8($sp)
	lwc1   $f20, 0x7b0($sp)
	lwc1   $f21, 0x7b4($sp)
	lwc1   $f22, 0x7b8($sp)
	lwc1   $f23, 0x7bc($sp)
	lwc1   $f24, 0x7c0($sp)
	lwc1   $f25, 0x7c4($sp)
	lwc1   $f26, 0x7c8($sp)
	lwc1   $f27, 0x7cc($sp)
	lwc1   $f28, 0x7d0($sp)
	lwc1   $f29, 0x7d4($sp)
	lwc1   $f30, 0x7d8($sp)
	lwc1   $f31, 0x7dc($sp)
	jr     $ra
	addiu  $sp, $sp, 0x800
 	syscall

glabel func00019634
	sw     $ra, 0x7ac($sp)
.L00019638:
	lbu    $t7, 0x0($t2)
	addiu  $t2, $t2, 0x1
	sh     $t7, 0x0($t0)
	ori    $t8, $zero, 0x0f
	slt    $at, $t8, $t7
	bnez   $at, .L000195cc
	addi   $v0, $zero, 0x0
	andi   $t8, $t7, 0x2
	bnez   $t8, .L000196cc
	addi   $s0, $zero, 0x0
	andi   $t8, $t7, 0x8
	addi   $s1, $zero, 0x0
	beqz   $t8, .L00019808
	addi   $s2, $zero, 0x0
	lbu    $v0, 0x2($t2)
	lbu    $v1, 0x5($t2)
	add    $v0, $v0, $v1
	lbu    $v1, 0x8($t2)
	add    $v0, $v0, $v1
	lbu    $v1, 0xb($t2)
	add    $v0, $v0, $v1
	slt    $at, $v0, $gp
	bnez   $at, .L000196c4
	sub    $v0, $v0, $gp
	addi   $s8, $zero, 0x0
	srl    $t8, $v0, 0x3
	add    $t6, $t6, $t8
	sll    $t8, $t8, 0x3
	sub    $v0, $v0, $t8
	lbu    $s8, 0x0($t6)
	addiu  $gp, $zero, 0x8
	addiu  $t6, $t6, 0x1
	sub    $gp, $gp, $v0
	j      .L00019808
	addi   $t2, $t2, 0xc
.L000196c4:
	j      .L00019808
	addi   $t2, $t2, 0xc
.L000196cc:
	jal    func00019be0
	lbu    $v1, 0x2($t2)
	add    $s0, $zero, $v0
	lbu    $v1, 0x2($t2)
	addiu  $s3, $zero, 0x10
	slt    $at, $v1, $s3
	beqz   $at, .L00019718
	addiu  $s3, $zero, 0x1
	addiu  $v0, $v1, -1
	sllv   $s3, $s3, $v0
	and    $s4, $s0, $s3
	beqz   $s4, .L00019718
	addiu  $s4, $zero, 0x10
	sub    $s4, $s4, $v1
	addiu  $v0, $zero, 0x1
	sllv   $v0, $v0, $s4
	addiu  $v0, $v0, -1
	sllv   $v0, $v0, $v1
	or     $s0, $s0, $v0
.L00019718:
	lbu    $s3, 0x0($t2)
	sll    $s3, $s3, 0x8
	lbu    $s4, 0x1($t2)
	addu   $s3, $s3, $s4
	addu   $s0, $s0, $s3
	andi   $s0, $s0, 0xffff
	jal    func00019be0
	lbu    $v1, 0x5($t2)
	add    $s1, $zero, $v0
	lbu    $v1, 0x5($t2)
	addiu  $s3, $zero, 0x10
	slt    $at, $v1, $s3
	beqz   $at, .L0001977c
	addiu  $s3, $zero, 0x1
	addiu  $v0, $v1, -1
	sllv   $s3, $s3, $v0
	and    $s4, $s1, $s3
	beqz   $s4, .L0001977c
	addiu  $s4, $zero, 0x10
	sub    $s4, $s4, $v1
	addiu  $v0, $zero, 0x1
	sllv   $v0, $v0, $s4
	addiu  $v0, $v0, -1
	sllv   $v0, $v0, $v1
	or     $s1, $s1, $v0
.L0001977c:
	lbu    $s3, 0x3($t2)
	sll    $s3, $s3, 0x8
	lbu    $s4, 0x4($t2)
	addu   $s3, $s3, $s4
	addu   $s1, $s1, $s3
	andi   $s1, $s1, 0xffff
	jal    func00019be0
	lbu    $v1, 0x8($t2)
	add    $s2, $zero, $v0
	lbu    $v1, 0x8($t2)
	addiu  $s3, $zero, 0x10
	slt    $at, $v1, $s3
	beqz   $at, .L000197e0
	addiu  $s3, $zero, 0x1
	addiu  $v0, $v1, -1
	sllv   $s3, $s3, $v0
	and    $s4, $s2, $s3
	beqz   $s4, .L000197e0
	addiu  $s4, $zero, 0x10
	sub    $s4, $s4, $v1
	addiu  $v0, $zero, 0x1
	sllv   $v0, $v0, $s4
	addiu  $v0, $v0, -1
	sllv   $v0, $v0, $v1
	or     $s2, $s2, $v0
.L000197e0:
	lbu    $s3, 0x6($t2)
	sll    $s3, $s3, 0x8
	lbu    $s4, 0x7($t2)
	addu   $s3, $s3, $s4
	addu   $s2, $s2, $s3
	andi   $s2, $s2, 0xffff
	addi   $t2, $t2, 0x9
	sh     $s0, 0x1e0($t0)
	sh     $s1, 0x1e2($t0)
	sh     $s2, 0x1e4($t0)
.L00019808:
	andi   $t8, $t7, 0x1
	bnez   $t8, .L00019820
	addi   $s0, $zero, 0x0
	addi   $s1, $zero, 0x0
	j      .L000198b4
	addi   $s2, $zero, 0x0
.L00019820:
	jal    func00019be0
	lbu    $v1, 0x2($t2)
	add    $s0, $zero, $v0
	lbu    $v1, 0x0($t2)
	sll    $v1, $v1, 0x8
	lbu    $v0, 0x1($t2)
	addu   $v1, $v1, $v0
	addiu  $v0, $zero, 0x10
	addu   $s0, $s0, $v1
	sub    $v0, $v0, $t4
	sllv   $s0, $s0, $v0
	andi   $s0, $s0, 0xffff
	jal    func00019be0
	lbu    $v1, 0x5($t2)
	add    $s1, $zero, $v0
	lbu    $v1, 0x3($t2)
	sll    $v1, $v1, 0x8
	lbu    $v0, 0x4($t2)
	addu   $v1, $v1, $v0
	addiu  $v0, $zero, 0x10
	addu   $s1, $s1, $v1
	sub    $v0, $v0, $t4
	sllv   $s1, $s1, $v0
	andi   $s1, $s1, 0xffff
	jal    func00019be0
	lbu    $v1, 0x8($t2)
	add    $s2, $zero, $v0
	lbu    $v1, 0x6($t2)
	sll    $v1, $v1, 0x8
	lbu    $v0, 0x7($t2)
	addu   $v1, $v1, $v0
	addiu  $v0, $zero, 0x10
	addu   $s2, $s2, $v1
	sub    $v0, $v0, $t4
	sllv   $s2, $s2, $v0
	andi   $s2, $s2, 0xffff
	addi   $t2, $t2, 0x9
.L000198b4:
	sh     $s0, 0x2($t0)
	sh     $s1, 0x4($t0)
	sh     $s2, 0x6($t0)
	addi   $t0, $t0, 0x8
	slt    $at, $t2, $t3
	bnez   $at, .L00019638
 	nop
	lw     $ra, 0x7ac($sp)
	jr     $ra
 	nop

glabel func000198dc
	sw     $ra, 0x7ac($sp)
.L000198e0:
	lbu    $t7, 0x0($t2)
	addi   $t2, $t2, 0x1
	ori    $t8, $zero, 0x0f
	slt    $at, $t8, $t7
	bnez   $at, .L000195cc
	addi   $v0, $zero, 0x0
	andi   $t8, $t7, 0x2
	bnez   $t8, .L00019970
	addi   $s0, $zero, 0x0
	andi   $t8, $t7, 0x8
	addi   $s1, $zero, 0x0
	beqz   $t8, .L000199b8
	addi   $s2, $zero, 0x0
	lbu    $v0, 0x2($t2)
	lbu    $v1, 0x5($t2)
	add    $v0, $v0, $v1
	lbu    $v1, 0x8($t2)
	add    $v0, $v0, $v1
	lbu    $v1, 0xb($t2)
	add    $v0, $v0, $v1
	slt    $at, $v0, $gp
	bnez   $at, .L00019968
	sub    $v0, $v0, $gp
	addi   $s8, $zero, 0x0
	srl    $t8, $v0, 0x3
	add    $t6, $t6, $t8
	sll    $t8, $t8, 0x3
	sub    $v0, $v0, $t8
	lbu    $s8, 0x0($t6)
	addiu  $gp, $zero, 0x8
	addiu  $t6, $t6, 0x1
	sub    $gp, $gp, $v0
	j      .L000199b8
	addi   $t2, $t2, 0xc
.L00019968:
	j      .L000199b8
	addi   $t2, $t2, 0xc
.L00019970:
	lbu    $v0, 0x2($t2)
	lbu    $v1, 0x5($t2)
	add    $v0, $v0, $v1
	lbu    $v1, 0x8($t2)
	add    $v0, $v0, $v1
	slt    $at, $v0, $gp
	bnez   $at, .L000199b4
	sub    $v0, $v0, $gp
	addi   $s8, $zero, 0x0
	srl    $t8, $v0, 0x3
	add    $t6, $t6, $t8
	sll    $t8, $t8, 0x3
	sub    $v0, $v0, $t8
	lbu    $s8, 0x0($t6)
	addiu  $gp, $zero, 0x8
	addiu  $t6, $t6, 0x1
	sub    $gp, $gp, $v0
.L000199b4:
	addi   $t2, $t2, 0x9
.L000199b8:
	andi   $t8, $t7, 0x1
	bnez   $t8, .L000199d0
	addi   $s0, $zero, 0x0
	addi   $s1, $zero, 0x0
	j      .L00019a64
	addi   $s2, $zero, 0x0
.L000199d0:
	jal    func00019be0
	lbu    $v1, 0x2($t2)
	add    $s0, $zero, $v0
	lbu    $v1, 0x0($t2)
	sll    $v1, $v1, 0x8
	lbu    $v0, 0x1($t2)
	addu   $v1, $v1, $v0
	addiu  $v0, $zero, 0x10
	addu   $s0, $s0, $v1
	sub    $v0, $v0, $t4
	sllv   $s0, $s0, $v0
	andi   $s0, $s0, 0xffff
	jal    func00019be0
	lbu    $v1, 0x5($t2)
	add    $s1, $zero, $v0
	lbu    $v1, 0x3($t2)
	sll    $v1, $v1, 0x8
	lbu    $v0, 0x4($t2)
	addu   $v1, $v1, $v0
	addiu  $v0, $zero, 0x10
	addu   $s1, $s1, $v1
	sub    $v0, $v0, $t4
	sllv   $s1, $s1, $v0
	andi   $s1, $s1, 0xffff
	jal    func00019be0
	lbu    $v1, 0x8($t2)
	add    $s2, $zero, $v0
	lbu    $v1, 0x6($t2)
	sll    $v1, $v1, 0x8
	lbu    $v0, 0x7($t2)
	addu   $v1, $v1, $v0
	addiu  $v0, $zero, 0x10
	addu   $s2, $s2, $v1
	sub    $v0, $v0, $t4
	sllv   $s2, $s2, $v0
	andi   $s2, $s2, 0xffff
	addi   $t2, $t2, 0x9
.L00019a64:
	mfc1   $s3, $f0
	lui    $v1, 0x1
	lhu    $s4, 0x2($t0)
	sub    $s5, $s0, $s4
	bgez   $s5, .L00019a80
 	nop
	add    $s5, $s5, $v1
.L00019a80:
	dli    $at, 0x8000
	slt    $at, $s5, $at
	beqz   $at, .L00019abc
 	nop
	multu  $s5, $s3
	mflo   $s5
	sra    $s5, $s5, 0xc
	add    $s0, $s4, $s5
	lui    $at, 0x1
	slt    $at, $s0, $at
	bnez   $at, .L00019adc
 	nop
	lui    $s4, 0x1
	j      .L00019adc
	sub    $s0, $s0, $s4
.L00019abc:
	sub    $s5, $v1, $s5
	multu  $s5, $s3
	mflo   $s5
	sra    $s5, $s5, 0xc
	sub    $s0, $s4, $s5
	bgez   $s0, .L00019adc
 	nop
	add    $s0, $s0, $v1
.L00019adc:
	lhu    $s4, 0x4($t0)
	sub    $s5, $s1, $s4
	bgez   $s5, .L00019af0
 	nop
	add    $s5, $s5, $v1
.L00019af0:
	dli    $at, 0x8000
	slt    $at, $s5, $at
	beqz   $at, .L00019b28
 	nop
	multu  $s5, $s3
	mflo   $s5
	sra    $s5, $s5, 0xc
	add    $s1, $s4, $s5
	lui    $at, 0x1
	slt    $at, $s1, $at
	bnez   $at, .L00019b48
 	nop
	j      .L00019b48
	sub    $s1, $s1, $v1
.L00019b28:
	sub    $s5, $v1, $s5
	multu  $s5, $s3
	mflo   $s5
	sra    $s5, $s5, 0xc
	sub    $s1, $s4, $s5
	bgez   $s1, .L00019b48
 	nop
	add    $s1, $s1, $v1
.L00019b48:
	lhu    $s4, 0x6($t0)
	sub    $s5, $s2, $s4
	bgez   $s5, .L00019b5c
 	nop
	add    $s5, $s5, $v1
.L00019b5c:
	dli    $at, 0x8000
	slt    $at, $s5, $at
	beqz   $at, .L00019b94
 	nop
	multu  $s5, $s3
	mflo   $s5
	sra    $s5, $s5, 0xc
	add    $s2, $s4, $s5
	lui    $at, 0x1
	slt    $at, $s2, $at
	bnez   $at, .L00019bb8
 	nop
	j      .L00019bb8
	sub    $s2, $s2, $v1
.L00019b94:
	sub    $s5, $v1, $s5
	multu  $s5, $s3
	mflo   $s5
	sra    $s5, $s5, 0xc
	sub    $s2, $s4, $s5
	bgez   $s2, .L00019bb8
 	nop
	lui    $s4, 0x1
	add    $s2, $s2, $s4
.L00019bb8:
	sh     $s0, 0x2($t0)
	sh     $s1, 0x4($t0)
	sh     $s2, 0x6($t0)
	addi   $t0, $t0, 0x8
	slt    $at, $t2, $t3
	bnez   $at, .L000198e0
 	nop
	lw     $ra, 0x7ac($sp)
	jr     $ra
 	nop

glabel func00019be0
	beqz   $v1, .L00019d14
	addi   $v0, $zero, 0x0
.L00019be8:
	slt    $at, $gp, $v1
	beqz   $at, .L00019cf4
 	nop
	sub    $v1, $v1, $gp
	addi   $s6, $zero, 0x1
	sllv   $s6, $s6, $gp
	addi   $s6, $s6, -1
	and    $s6, $s8, $s6
	sllv   $s6, $s6, $v1
	or     $v0, $v0, $s6
	sub    $s6, $t3, $t6
	slti   $at, $s6, 0x4
	bnez   $at, .L00019c24
 	nop
	addiu  $s6, $zero, 0x4
.L00019c24:
	andi   $s8, $t6, 0x3
	addiu  $s8, $s8, -4
	neg    $s8, $s8
	beqz   $s8, .L00019c48
 	nop
	slt    $at, $s8, $s6
	beqz   $at, .L00019c48
 	nop
	or     $s6, $s8, $zero
.L00019c48:
	lui    $s8, %hi(var8005ef7c)
	addiu  $s8, $s8, %lo(var8005ef7c)
	sll    $s6, $s6, 0x2
	add    $s6, $s8, $s6
	lw     $s6, 0x0($s6)
	jr     $s6
	lbu    $s8, 0x0($t6)
	addiu  $t6, $t6, 0x1
	j      .L00019be8
	addiu  $gp, $zero, 0x8
	sll    $s8, $s8, 0x8
	lbu    $s6, 0x1($t6)
	or     $s8, $s8, $s6
	addiu  $t6, $t6, 0x2
	j      .L00019be8
	addiu  $gp, $zero, 0x10
	sll    $s8, $s8, 0x8
	lbu    $s6, 0x1($t6)
	or     $s8, $s8, $s6
	sll    $s8, $s8, 0x8
	lbu    $s6, 0x2($t6)
	or     $s8, $s8, $s6
	addiu  $t6, $t6, 0x3
	j      .L00019be8
	addiu  $gp, $zero, 0x18
	andi   $s6, $t6, 0x3
	beqz   $s6, .L00019ce4
	sll    $s8, $s8, 0x8
	lbu    $s6, 0x1($t6)
	or     $s8, $s8, $s6
	sll    $s8, $s8, 0x8
	lbu    $s6, 0x2($t6)
	or     $s8, $s8, $s6
	sll    $s8, $s8, 0x8
	lbu    $s6, 0x3($t6)
	or     $s8, $s8, $s6
	addiu  $t6, $t6, 0x4
	j      .L00019be8
	addiu  $gp, $zero, 0x20
.L00019ce4:
	lw     $s8, 0x0($t6)
	addiu  $t6, $t6, 0x4
	j      .L00019be8
	addiu  $gp, $zero, 0x20
.L00019cf4:
	beqz   $v1, .L00019d14
	sub    $gp, $gp, $v1
	srav   $s6, $s8, $gp
	addi   $s7, $zero, 0x1
	sllv   $s7, $s7, $v1
	addi   $s7, $s7, -1
	and    $s6, $s6, $s7
	or     $v0, $v0, $s6
.L00019d14:
	jr     $ra
 	nop

glabel func00019d1c
	addiu  $sp, $sp, -32
	sw     $gp, 0x0($sp)
	sw     $t0, 0x4($sp)
	sw     $t1, 0x8($sp)
	sw     $t2, 0xc($sp)
	sw     $t3, 0x10($sp)
	sw     $t4, 0x14($sp)
	sw     $ra, 0x18($sp)
	lw     $t4, 0x4($gp)
	lui    $t2, %hi(var8005ef90)
	addiu  $t2, $t2, %lo(var8005ef90)
	lhu    $t1, 0x0($gp)
	andi   $t1, $t1, 0xff
	or     $t0, $zero, $zero
	slti   $at, $t1, 0x1a
	beqz   $at, .L00019d78
	lw     $t3, 0x10($a1)
	add    $t2, $t2, $t1
	lbu    $t2, 0x0($t2)
	addiu  $at, $zero, 0xff
	beq    $t2, $at, .L00019d78
	add    $t2, $t4, $t2
	lhu    $t0, 0x0($t2)
.L00019d78:
	lw     $t1, 0x818($sp)
	beqz   $t1, .L00019db0
 	nop
.L00019d84:
	lw     $t1, 0x8($gp)
	beqz   $t1, .L00019db0
	or     $gp, $t1, $zero
	lhu    $t1, 0x0($gp)
	andi   $t1, $t1, 0xff
	addiu  $at, $zero, 0x17
	bne    $t1, $at, .L00019d84
 	nop
	jal    func00019d1c
 	nop
	lw     $t3, 0x4($v0)
.L00019db0:
	sll    $t0, $t0, 0x2
	add    $v0, $t3, $t0
	lw     $gp, 0x0($sp)
	lw     $t0, 0x4($sp)
	lw     $t1, 0x8($sp)
	lw     $t2, 0xc($sp)
	lw     $t3, 0x10($sp)
	lw     $t4, 0x14($sp)
	lw     $ra, 0x18($sp)
	jr     $ra
	addiu  $sp, $sp, 0x20

#if VERSION < VERSION_NTSC_1_0
/**
 * NTSC beta uses a simple version of this function, implemented here in ASM.
 * NTSC 1.0 and newer reimplements the function in C and adds more to it.
 */
glabel modelGetNodeRwData
	addiu  $sp, $sp, -16
	sw     $t0, 0x0($sp)
	sw     $t1, 0x4($sp)
	sw     $t3, 0x8($sp)
	sw     $ra, 0xc($sp)
	lw     $t4, 0x4($a1)
	lui    $t2, 0x8006
	addiu  $t2, $t2, 0x1360
	lhu    $t1, 0x0($a1)
	andi   $t1, $t1, 0xff
	or     $t0, $zero, $zero
	slti   $at, $t1, 0x1a
	beqz   $at, .NB0001aefc
	lw     $t3, 0x10($a0)
	add    $t2, $t2, $t1
	lbu    $t2, 0x0($t2)
	addiu  $at, $zero, 0xff
	beq    $t2, $at, .NB0001aefc
	add    $t2, $t4, $t2
	lhu    $t0, 0x0($t2)
.NB0001aefc:
	lbu    $t1, 0x0($a0)
	beqz   $t1, .NB0001af34
	sll    $zero, $zero, 0x0
.NB0001af08:
	lw     $t1, 0x8($a1)
	beqz   $t1, .NB0001af34
	or     $a1, $t1, $zero
	lhu    $t1, 0x0($a1)
	andi   $t1, $t1, 0xff
	addiu  $at, $zero, 0x17
	bne    $t1, $at, .NB0001af08
	sll    $zero, $zero, 0x0
	jal    modelGetNodeRwData
	sll    $zero, $zero, 0x0
	lw     $t3, 0x4($v0)
.NB0001af34:
	sll    $t0, $t0, 0x2
	add    $v0, $t3, $t0
	lw     $t0, 0x0($sp)
	lw     $t1, 0x4($sp)
	lw     $t3, 0x8($sp)
	lw     $ra, 0xc($sp)
	jr     $ra
	addiu  $sp, $sp, 0x10
#endif

glabel func00019ddc
	sw     $ra, 0x7ac($sp)
.L00019de0:
	mul.s  $f5, $f16, $f0
	mtc1   $zero, $f4
	mul.s  $f6, $f17, $f1
 	nop
	mul.s  $f7, $f18, $f2
	add.s  $f6, $f5, $f6
	mul.s  $f5, $f19, $f3
	add.s  $f6, $f6, $f7
	add.s  $f6, $f6, $f5
	c.lt.s $f6, $f4
	bc1fl  .L00019e24
 	nop
	neg.s  $f0, $f0
	neg.s  $f1, $f1
	neg.s  $f2, $f2
	j      .L00019de0
	neg.s  $f3, $f3
.L00019e24:
	lui    $at, %hi(var70054224)
	lwc1   $f7, %lo(var70054224)($at)
	c.lt.s $f6, $f7
	bc1fl  .L00019e80
 	nop
	mul.s  $f6, $f30, $f16
	sub.s  $f5, $f5, $f30
	mul.s  $f7, $f5, $f0
	sub.s  $f0, $f7, $f6
	mul.s  $f6, $f30, $f17
 	nop
	mul.s  $f7, $f5, $f1
 	nop
	mul.s  $f8, $f30, $f18
	sub.s  $f1, $f7, $f6
	mul.s  $f9, $f5, $f2
 	nop
	mul.s  $f6, $f30, $f19
	sub.s  $f2, $f9, $f8
	mul.s  $f7, $f5, $f3
	lw     $ra, 0x7ac($sp)
	jr     $ra
	sub.s  $f2, $f7, $f6
.L00019e80:
	lui    $at, %hi(var70054228)
	lwc1   $f7, %lo(var70054228)($at)
	c.le.s $f6, $f7
	bc1f   .L00019f20
 	nop
	jal    func0001a2dc
 	nop
	mov.s  $f20, $f0
	jal    sinf
	mov.s  $f12, $f7
	mov.s  $f12, $f31
	sub.s  $f12, $f12, $f30
	mul.s  $f12, $f12, $f7
	jal    sinf
	mov.s  $f21, $f0
	mul.s  $f12, $f7, $f30
	jal    sinf
	mov.s  $f22, $f0
	div.s  $f5, $f22, $f21
 	nop
	div.s  $f30, $f0, $f21
	mov.s  $f0, $f20
.L00019ed8:
	mul.s  $f6, $f5, $f16
 	nop
	mul.s  $f7, $f30, $f0
 	nop
	mul.s  $f8, $f5, $f17
	add.s  $f0, $f6, $f7
	mul.s  $f9, $f30, $f1
 	nop
	mul.s  $f6, $f5, $f18
	add.s  $f1, $f8, $f9
	mul.s  $f7, $f30, $f2
 	nop
	mul.s  $f8, $f5, $f19
	add.s  $f2, $f6, $f7
	mul.s  $f9, $f30, $f3
	lw     $ra, 0x7ac($sp)
	jr     $ra
	add.s  $f3, $f8, $f9
.L00019f20:
	mov.s  $f5, $f31
	j      .L00019ed8
	sub.s  $f5, $f5, $f30

glabel func00019f2c
	mul.s  $f6, $f0, $f2
 	nop
	mul.s  $f7, $f0, $f3
 	nop
	mul.s  $f8, $f1, $f2
 	nop
	mul.s  $f9, $f1, $f3
 	nop
	mul.s  $f0, $f6, $f4
 	nop
	mul.s  $f1, $f9, $f5
 	nop
	mul.s  $f2, $f8, $f4
	add.s  $f0, $f0, $f1
	mul.s  $f1, $f7, $f5
 	nop
	mul.s  $f3, $f7, $f5
 	nop
	mul.s  $f10, $f7, $f4
	sub.s  $f1, $f2, $f1
	mul.s  $f11, $f8, $f5
 	nop
	mul.s  $f26, $f6, $f5
	add.s  $f2, $f10, $f11
	mul.s  $f10, $f9, $f4
	jr     $ra
	sub.s  $f3, $f26, $f10

glabel func00019f98
	add    $t5, $zero, $ra
	lui    $at, %hi(var7005422c)
	lwc1   $f29, %lo(var7005422c)($at)
	mtc1   $t4, $f8
	mtc1   $t3, $f7
	mtc1   $t2, $f6
	cvt.s.w $f8, $f8
	cvt.s.w $f7, $f7
	cvt.s.w $f6, $f6
	mul.s  $f8, $f8, $f29
	lui    $at, %hi(var70054230)
	lwc1   $f30, %lo(var70054230)($at)
	mul.s  $f7, $f7, $f29
	mov.s  $f12, $f8
	jal    sinf
 	nop
	mul.s  $f6, $f6, $f29
	add.s  $f12, $f8, $f30
	jal    sinf
	mov.s  $f5, $f0
	mov.s  $f12, $f7
	jal    sinf
	mov.s  $f4, $f0
	add.s  $f12, $f7, $f30
	jal    sinf
	mov.s  $f3, $f0
	mov.s  $f12, $f6
	jal    sinf
	mov.s  $f2, $f0
	add.s  $f12, $f6, $f30
	jal    sinf
	mov.s  $f1, $f0
	add    $ra, $zero, $t5
	jr     $ra
 	nop

glabel func0001a024
	add    $t5, $zero, $ra
	lui    $at, %hi(var70054234)
	lwc1   $f29, %lo(var70054234)($at)
	mtc1   $t4, $f8
	mtc1   $t3, $f7
	mtc1   $t2, $f6
	cvt.s.w $f8, $f8
	cvt.s.w $f7, $f7
	cvt.s.w $f6, $f6
	mul.s  $f8, $f8, $f29
	lui    $at, %hi(var70054238)
	lwc1   $f30, %lo(var70054238)($at)
	mul.s  $f7, $f7, $f29
	jal    sinf
	mov.s  $f12, $f8
	mul.s  $f6, $f6, $f29
	add.s  $f12, $f8, $f30
	jal    sinf
	mov.s  $f5, $f0
	mov.s  $f12, $f7
	jal    sinf
	mov.s  $f4, $f0
	add.s  $f12, $f7, $f30
	jal    sinf
	mov.s  $f3, $f0
	mov.s  $f12, $f6
	jal    sinf
	mov.s  $f2, $f0
	add.s  $f12, $f6, $f30
	jal    sinf
	mov.s  $f1, $f0
	add    $ra, $zero, $t5
	jr     $ra
 	nop

glabel func0001a0ac
	mul.s  $f6, $f1, $f5
 	nop
	mul.s  $f7, $f0, $f5
 	nop
	mul.s  $f8, $f1, $f4
 	nop
	mul.s  $f9, $f0, $f4
 	nop
	mul.s  $f12, $f2, $f4
	neg.s  $f14, $f3
	mul.s  $f13, $f2, $f5
 	nop
	mul.s  $f15, $f8, $f3
 	nop
	mul.s  $f16, $f6, $f3
	sub.s  $f15, $f15, $f7
	mul.s  $f17, $f1, $f2
	add.s  $f16, $f16, $f9
	mul.s  $f18, $f9, $f3
 	nop
	mul.s  $f19, $f7, $f3
	add.s  $f18, $f18, $f6
	mul.s  $f20, $f0, $f2
	jr     $ra
	sub.s  $f19, $f19, $f8

glabel func0001a110
	mul.s  $f4, $f0, $f0
 	nop
	mul.s  $f5, $f1, $f1
 	nop
	mul.s  $f6, $f2, $f2
	add.s  $f4, $f4, $f5
	mul.s  $f5, $f3, $f3
	add.s  $f4, $f4, $f6
	lui    $at, 0x4000
	mtc1   $at, $f6
	add.s  $f4, $f4, $f5
	div.s  $f4, $f6, $f4
	mul.s  $f5, $f1, $f4
 	nop
	mul.s  $f6, $f2, $f4
 	nop
	mul.s  $f7, $f3, $f4
 	nop
	mul.s  $f8, $f0, $f5
 	nop
	mul.s  $f9, $f0, $f6
 	nop
	mul.s  $f10, $f0, $f7
 	nop
	mul.s  $f11, $f1, $f5
 	nop
	mul.s  $f24, $f1, $f6
	sub.s  $f16, $f31, $f11
	mul.s  $f25, $f1, $f7
	sub.s  $f20, $f31, $f11
	mul.s  $f26, $f2, $f6
	add.s  $f13, $f24, $f10
	mul.s  $f27, $f2, $f7
	sub.s  $f12, $f31, $f26
	mul.s  $f28, $f3, $f7
	sub.s  $f14, $f25, $f9
	sub.s  $f12, $f12, $f28
	sub.s  $f15, $f24, $f10
	sub.s  $f16, $f16, $f28
	add.s  $f17, $f27, $f8
	add.s  $f18, $f25, $f9
	sub.s  $f19, $f27, $f8
	jr     $ra
	sub.s  $f20, $f20, $f26

glabel func0001a1c0
	addiu  $t2, $zero, 0x3
.L0001a1c4:
	lwc1   $f0, 0x0($t0)
	addiu  $t0, $t0, 0x4
	mul.s  $f4, $f0, $f12
	lwc1   $f1, 0xc($t0)
	lwc1   $f2, 0x1c($t0)
	mul.s  $f5, $f1, $f13
	lwc1   $f3, 0x2c($t0)
	mul.s  $f6, $f2, $f14
	add.s  $f7, $f4, $f5
	mul.s  $f8, $f0, $f15
	add.s  $f7, $f7, $f6
	mul.s  $f9, $f1, $f16
	swc1   $f7, 0x0($t1)
	mul.s  $f10, $f2, $f17
	add.s  $f11, $f8, $f9
	mul.s  $f4, $f0, $f18
	add.s  $f11, $f11, $f10
	mul.s  $f5, $f1, $f19
	swc1   $f11, 0x10($t1)
	mul.s  $f6, $f2, $f20
	add.s  $f7, $f4, $f5
	mul.s  $f8, $f0, $f21
	add.s  $f7, $f7, $f6
	mul.s  $f9, $f1, $f22
	swc1   $f7, 0x20($t1)
	mul.s  $f10, $f2, $f23
	add.s  $f8, $f8, $f9
	add.s  $f10, $f10, $f3
	addiu  $t2, $t2, -1
	add.s  $f10, $f8, $f10
	addiu  $t1, $t1, 0x4
	bnez   $t2, .L0001a1c4
	swc1   $f10, 0x2c($t1)
	sw     $zero, 0x0($t1)
	sw     $zero, 0x10($t1)
	sw     $zero, 0x20($t1)
	jr     $ra
	swc1   $f31, 0x30($t1)

glabel func0001a25c
.L0001a25c:
	lh     $t1, 0x0($t0)
	andi   $t1, $t1, 0xff
	addiu  $t2, $zero, 0x1
	bne    $t1, $t2, .L0001a288
	addiu  $t2, $zero, 0x2
	lw     $t2, 0x4($t0)
	lhu    $t2, 0x2($t2)
	sll    $t2, $t2, 0x6
	lw     $t1, 0xc($a1)
	jr     $ra
	add    $t0, $t1, $t2
.L0001a288:
	bne    $t1, $t2, .L0001a2a8
	addiu  $t2, $zero, 0x15
	lw     $t2, 0x4($t0)
	lhu    $t2, 0xe($t2)
	sll    $t2, $t2, 0x6
	lw     $t1, 0xc($a1)
	jr     $ra
	add    $t0, $t1, $t2
.L0001a2a8:
	bne    $t1, $t2, .L0001a2c8
 	nop
	lw     $t2, 0x4($t0)
	lhu    $t2, 0xc($t2)
	sll    $t2, $t2, 0x6
	lw     $t1, 0xc($a1)
	jr     $ra
	add    $t0, $t1, $t2
.L0001a2c8:
	lw     $t0, 0x8($t0)
	bnez   $t0, .L0001a25c
 	nop
	jr     $ra
	add    $t0, $zero, $zero

glabel func0001a2dc
	lui    $at, %hi(var7005423c)
	lwc1   $f7, %lo(var7005423c)($at)
	mul.s  $f7, $f6, $f7
	trunc.w.s $f7, $f7
	mfc1   $t2, $f7
 	nop
	slti   $at, $t2, 0x7fff
	bnez   $at, .L0001a308
 	nop
	b      .L0001a318
	addiu  $t2, $zero, 0x7fff
.L0001a308:
	slti   $at, $t2, -32767
	beqz   $at, .L0001a318
 	nop
	addiu  $t2, $zero, -32767
.L0001a318:
	bgez   $t2, .L0001a324
	add    $t3, $zero, $t2
	neg    $t3, $t3
.L0001a324:
	slti   $at, $t3, 0x7fe0
	bnez   $at, .L0001a348
 	nop
	lui    $t4, %hi(var8006af8c)
	addiu  $t4, $t4, %lo(var8006af8c)
	addi   $t3, $t3, -32736
	addiu  $t5, $zero, 0x3
	b      .L0001a37c
	addiu  $t6, $zero, 0x7
.L0001a348:
	slti   $at, $t3, 0x7800
	bnez   $at, .L0001a36c
 	nop
	lui    $t4, %hi(var8006af0c)
	addiu  $t4, $t4, %lo(var8006af0c)
	addi   $t3, $t3, -30720
	addiu  $t5, $zero, 0x5
	b      .L0001a37c
	addiu  $t6, $zero, 0x1f
.L0001a36c:
	lui    $t4, %hi(var8006ae90)
	addiu  $t4, $t4, %lo(var8006ae90)
	addiu  $t5, $zero, 0x9
	addiu  $t6, $zero, 0x1ff
.L0001a37c:
	srav   $s0, $t3, $t5
	sll    $s0, $s0, 0x1
	add    $t4, $t4, $s0
	lhu    $s1, 0x0($t4)
	lhu    $s2, 0x2($t4)
	sub    $s3, $s1, $s2
	and    $s4, $t3, $t6
	multu  $s3, $s4
	mflo   $s3
	srav   $s3, $s3, $t5
	sub    $t3, $s1, $s3
	bgez   $t2, .L0001a3b4
	dli    $t2, 0xffff
	sub    $t3, $t2, $t3
.L0001a3b4:
	mtc1   $t3, $f8
	lui    $at, %hi(var70054240)
	lwc1   $f7, %lo(var70054240)($at)
	cvt.s.w $f8, $f8
	mul.s  $f7, $f8, $f7
	jr     $ra
 	nop

glabel cosf
	lui       $at, %hi(var70054244)
	lwc1      $f13, %lo(var70054244)($at)
	add.s     $f12, $f12, $f13

glabel sinf
	mfc1      $t0, $f12
    nop
	sra       $t0, $t0, 22
	andi      $t0, $t0, 0x1ff
	slti      $at, $t0, 255
	beqz      $at, .L0001a454
    nop
	slti      $at, $t0, 230
	bnez      $at, .L0001a4f0
	mov.s     $f0, $f12
	mul.s     $f14, $f12, $f12
	lui       $at, %hi(var70054248)
	lwc1      $f15, %lo(var70054248)($at)
	lui       $at, %hi(var7005424c)
	lwc1      $f13, %lo(var7005424c)($at)
	mul.s     $f15, $f15, $f14
	add.s     $f15, $f13, $f15
	lui       $at, %hi(var70054250)
	lwc1      $f13, %lo(var70054250)($at)
	mul.s     $f15, $f15, $f14
	add.s     $f15, $f13, $f15
	lui       $at, %hi(var70054254)
	lwc1      $f13, %lo(var70054254)($at)
	mul.s     $f15, $f15, $f14
	add.s     $f15, $f13, $f15
	mul.s     $f15, $f15, $f14
    nop
	mul.s     $f15, $f15, $f12
	jr        $ra
	add.s     $f0, $f15, $f12
.L0001a454:
	slti      $at, $t0, 310
	beqzl     $at, .L0001a4f0
	mtc1      $zero, $f0
	lui       $at, %hi(var70054258)
	lwc1      $f14, %lo(var70054258)($at)
	mul.s     $f14, $f14, $f12
	round.w.s $f14, $f14
	mfc1      $t1, $f14
	cvt.s.w   $f14, $f14
	lui       $at, %hi(var7005425c)
	lwc1      $f15, %lo(var7005425c)($at)
	mul.s     $f15, $f15, $f14
	sub.s     $f12, $f12, $f15
	lui       $at, %hi(var70054260)
	lwc1      $f15, %lo(var70054260)($at)
	mul.s     $f15, $f15, $f14
	sub.s     $f12, $f12, $f15
	lui       $at, %hi(var70054264)
	lwc1      $f15, %lo(var70054264)($at)
	mul.s     $f14, $f12, $f12
	lui       $at, %hi(var70054268)
	lwc1      $f13, %lo(var70054268)($at)
	mul.s     $f15, $f15, $f14
	add.s     $f15, $f13, $f15
	lui       $at, %hi(var7005426c)
	lwc1      $f13, %lo(var7005426c)($at)
	mul.s     $f15, $f15, $f14
	add.s     $f15, $f13, $f15
	lui       $at, %hi(var70054270)
	lwc1      $f13, %lo(var70054270)($at)
	mul.s     $f15, $f15, $f14
	add.s     $f15, $f13, $f15
	mul.s     $f15, $f15, $f14
    nop
	mul.s     $f15, $f15, $f12
	andi      $t1, $t1, 1
	add.s     $f0, $f15, $f12
	bnezl     $t1, .L0001a4f0
	neg.s     $f0, $f0
.L0001a4f0:
	jr        $ra
    nop
