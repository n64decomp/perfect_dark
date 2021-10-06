/**
 * This file is a customised implementation of zlib's inflate functions.
 *
 * There are two inflate implementations in this codebase:
 *
 * 1. src/inflate/inflate.c:
 * - Is pretty much regular zlib but with some malloc functions changed to use
 *   stack or data.
 * - Being C, is more readable than this file.
 * - Is stored uncompressed in the ROM and is used to decompress the lib and
 *   data segments, which includes this file's code.
 *
 * 2. This file:
 * - Is used for inflating everything else, including the game segment and
 *   assets.
 * - Is stored in the lib segment which is compressed on the ROM.
 */

#include "macros.inc"
.set noat
.set noreorder
.set gp=64

.bss

glabel var80090b10
.space 2504

glabel var800914d8
.space 128

glabel var80091558
.space 4

.rdata

glabel mask_bits
.half 0x0000
.half 0x0001
.half 0x0003
.half 0x0007
.half 0x000f
.half 0x001f
.half 0x003f
.half 0x007f
.half 0x00ff
.half 0x01ff
.half 0x03ff
.half 0x07ff
.half 0x0fff
.half 0x1fff
.half 0x3fff
.half 0x7fff
.half 0xffff

glabel cplens
.half 3
.half 4
.half 5
.half 6
.half 7
.half 8
.half 9
.half 10
.half 11
.half 13
.half 15
.half 17
.half 19
.half 23
.half 27
.half 31
.half 35
.half 43
.half 51
.half 59
.half 67
.half 83
.half 99
.half 115
.half 131
.half 163
.half 195
.half 227
.half 258
.half 0
.half 0

glabel cpdist
.half 1
.half 2
.half 3
.half 4
.half 5
.half 7
.half 9
.half 13
.half 17
.half 25
.half 33
.half 49
.half 65
.half 97
.half 129
.half 193
.half 257
.half 385
.half 513
.half 769
.half 1025
.half 1537
.half 2049
.half 3073
.half 4097
.half 6145
.half 8193
.half 12289
.half 16385
.half 24577

glabel border
.byte 16
.byte 17
.byte 18
.byte 0
.byte 8
.byte 7
.byte 9
.byte 6
.byte 10
.byte 5
.byte 11
.byte 4
.byte 12
.byte 3
.byte 13
.byte 2
.byte 14
.byte 1
.byte 15

glabel cplext
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 1
.byte 1
.byte 1
.byte 1
.byte 2
.byte 2
.byte 2
.byte 2
.byte 3
.byte 3
.byte 3
.byte 3
.byte 4
.byte 4
.byte 4
.byte 4
.byte 5
.byte 5
.byte 5
.byte 5
.byte 0
.byte 99
.byte 99

glabel cpdext
.byte 0
.byte 0
.byte 0
.byte 0
.byte 1
.byte 1
.byte 2
.byte 2
.byte 3
.byte 3
.byte 4
.byte 4
.byte 5
.byte 5
.byte 6
.byte 6
.byte 7
.byte 7
.byte 8
.byte 8
.byte 9
.byte 9
.byte 10
.byte 10
.byte 11
.byte 11
.byte 12
.byte 12
.byte 13
.byte 13

glabel errstr_inflatefailed
.asciiz "RareZipAsmDecompress: inflate failed (%d)\n"

glabel errstr_huftsoverflow
.asciiz "RareZipAsmDecompress: hufts overflow=%d\n"

glabel errstr_badlen
.asciiz "RareZipAsmDecompress: bad len\n"

glabel errstr_unrecognised
.asciiz "RareZipAsmDecompress: input not in any known rare zip format\n"

.text

/**
 * u32 rzipInflate(void *src, void *dst, void *scratch);
 *
 * Inflate a 1172 (GE) or 1173 (PD) compressed stream.
 *
 * GE's format is 0x11, 0x72, then the raw DEFLATE stream.
 * PD's format is 0x11, 0x73, then 3 bytes for the uncompressed length,
 * then the raw DEFLATE stream.
 *
 * The scratch argument must be a pointer to a 5KB allocation (5120 bytes).
 */
glabel rzipInflate
 	addiu  $sp, $sp, -0xa88
 	sw     $s0, 0xa48($sp)
 	sw     $s1, 0xa4c($sp)
 	sw     $s2, 0xa50($sp)
 	sw     $s3, 0xa54($sp)
 	sw     $s4, 0xa58($sp)
 	sw     $s5, 0xa5c($sp)
 	sw     $s6, 0xa60($sp)
 	sw     $s7, 0xa64($sp)
 	sw     $s8, 0xa78($sp)
 	sw     $gp, 0xa7c($sp)
 	sw     $ra, 0xa80($sp)
 	li     $t0, 0x11
 	lbu    $t1, 0x0($a0)
 	beq    $t1, $t0, .firstbyteok
 	li     $t0, 0x72
 	addiu  $sp, $sp, -0x80
 	sw     $a0, 0x10($sp)
 	lui    $a0, %hi(errstr_unrecognised)
 	sw     $ra, 0x0($sp)
 	sw     $at, 0x4($sp)
 	sw     $v0, 0x8($sp)
 	sw     $v1, 0xc($sp)
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
 	addiu  $sp, $sp, -0x18
 	jal    crashPrint
 	addiu  $a0, $a0, %lo(errstr_unrecognised)
 	addiu  $sp, $sp, 0x18
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
 	j      .failed
 	nop
.firstbyteok:
 	lbu    $t1, 0x1($a0)
 	beq    $t1, $t0, .geheader
 	li     $t0, 0x73
 	beq    $t1, $t0, .pdheader
 	nop
 	addiu  $sp, $sp, -0x80
 	sw     $a0, 0x10($sp)
 	lui    $a0, %hi(errstr_unrecognised)
 	sw     $ra, 0x0($sp)
 	sw     $at, 0x4($sp)
 	sw     $v0, 0x8($sp)
 	sw     $v1, 0xc($sp)
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
 	addiu  $sp, $sp, -0x18
 	jal    crashPrint
 	addiu  $a0, $a0, %lo(errstr_unrecognised)
 	addiu  $sp, $sp, 0x18
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
 	j      .failed
 	nop
.geheader:
 	j      .L0000776c
 	addiu  $a0, $a0, 0x2
.pdheader:
 	j      .L0000776c
 	addiu  $a0, $a0, 0x5
.L0000776c:
 	addiu  $s7, $a0, 0x0
 	mtc1   $a1, $f16
 	move   $s6, $a2
 	mtc1   $zero, $f17
 	lui    $t2, 0x7000
 	subu   $t0, $a0, $a1
 	bgtzl  $t0, .L00007790
 	nop
 	move   $t2, $t0
.L00007790:
 	subu   $t0, $a2, $a1
 	bltz   $t0, .L000077ac
 	nop
 	slt    $at, $t0, $t2
 	beqz   $at, .L000077ac
 	nop
 	move   $t2, $t0
.L000077ac:
 	mtc1   $t2, $f18
 	jal    rzipInflateBody
 	nop
 	bnez   $v0, .failed
 	mfc1   $v0, $f17
.exit:
 	lw     $s0, 0xa48($sp)
 	lw     $s1, 0xa4c($sp)
 	lw     $s2, 0xa50($sp)
 	lw     $s3, 0xa54($sp)
 	lw     $s4, 0xa58($sp)
 	lw     $s5, 0xa5c($sp)
 	lw     $s6, 0xa60($sp)
 	lw     $s7, 0xa64($sp)
 	lw     $s8, 0xa78($sp)
 	lw     $gp, 0xa7c($sp)
 	lw     $ra, 0xa80($sp)
 	jr     $ra
 	addiu  $sp, $sp, 0xa88
.failed:
 	addiu  $sp, $sp, -0x80
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
 	addiu  $sp, $sp, -0x18
 	sw     $v0, 0x4($sp)
 	lui    $a0, %hi(errstr_inflatefailed)
 	addiu  $a0, $a0, %lo(errstr_inflatefailed)
 	jal    crashPrint
 	lw     $a1, 0x4($sp)
 	addiu  $sp, $sp, 0x18
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
 	j      .exit
 	li     $v0, 0

/**
 * Return 0 on success.
 */
glabel rzipInflateBody
 	sw     $ra, 0xa6c($sp)
 	mtc1   $zero, $f17
 	li     $gp, 0
 	li     $s8, 0
.L00007918:
 	mtc1   $zero, $f19
 	jal    rzipInflateBlock
 	addiu  $a0, $sp, 0xa70
 	bnez   $v0, .L00007960
 	lw     $t3, 0xa70($sp)
 	beqz   $t3, .L00007918
 	nop
 	slti   $at, $s8, 0x8
 	bnez   $at, .L00007950
 	nop
.L00007940:
 	addiu   $s8, $s8, -8
 	slti    $at, $s8, 0x8
 	beqz    $at, .L00007940
 	addiu   $s7, $s7, -1
.L00007950:
 	li      $v0, 0
 	lui     $t3, %hi(var80091558)
 	addiu   $t3, $t3, %lo(var80091558)
 	sw      $s7, 0x0($t3)
.L00007960:
 	lw      $ra, 0xa6c($sp)
 	jr      $ra
 	nop

glabel rzipInflateBlock
 	sw      $ra, 0xa68($sp)
 	slti    $at, $s8, 0x3
 	beqz    $at, .L0000799c
 	nop
 	lbu     $at, 0x0($s7)
.L00007980:
 	addiu   $s7, $s7, 0x1
 	sllv    $at, $at, $s8
 	or      $gp, $gp, $at
 	addiu   $s8, $s8, 0x8
 	slti    $at, $s8, 0x3
 	bnezl   $at, .L00007980
 	lbu     $at, 0x0($s7)
.L0000799c:
 	andi    $at, $gp, 0x1
 	sw      $at, 0x0($a0)
 	srl     $t3, $gp, 0x1
 	andi    $t3, $t3, 0x3
 	srl     $gp, $gp, 0x3
 	addiu   $s8, $s8, -3
 	li      $at, 2
 	bne     $t3, $at, .L000079d0
 	nop
 	jal     rzipInflateDynamic
 	nop
 	j       .L00007a04
 	nop
.L000079d0:
 	bnez    $t3, .L000079e8
 	li      $at, 1
 	jal     rzipInflateStored
 	nop
 	j       .L00007a04
 	nop
.L000079e8:
 	bne     $t3, $at, .L00007a00
 	nop
 	jal     rzipInflateFixed2
 	nop
 	j       .L00007a04
 	nop
.L00007a00:
 	li      $v0, 2
.L00007a04:
 	lw      $ra, 0xa68($sp)
 	jr      $ra
 	nop

glabel rzipInflateDynamic
 	sw      $ra, 0xa44($sp)
 	lui     $t5, %hi(border)
 	addiu   $t5, $t5, %lo(border)
 	slti    $at, $s8, 0xe
 	beqz    $at, .L00007a48
 	nop
 	lbu     $at, 0x0($s7)
.L00007a2c:
 	addiu   $s7, $s7, 0x1
 	sllv    $at, $at, $s8
 	or      $gp, $gp, $at
 	addiu   $s8, $s8, 0x8
 	slti    $at, $s8, 0xe
 	bnezl   $at, .L00007a2c
 	lbu     $at, 0x0($s7)
.L00007a48:
 	andi    $t2, $gp, 0x1f
 	addiu   $t2, $t2, 0x101
 	andi    $t3, $gp, 0x3e0
 	srl     $t3, $t3, 0x5
 	addiu   $t3, $t3, 0x1
 	andi    $t1, $gp, 0x3c00
 	srl     $t1, $t1, 0xa
 	addiu   $t1, $t1, 0x4
 	srl     $gp, $gp, 0xe
 	addiu   $s8, $s8, -14
 	slti    $at, $t2, 0x11f
 	beqz    $at, .L00007e0c
 	nop
 	slti    $at, $t3, 0x1f
 	beqz    $at, .L00007e0c
 	li      $s1, 0
.L00007a88:
 	slti    $at, $s8, 0x3
 	beqz    $at, .L00007ab4
 	nop
 	lbu     $at, 0x0($s7)
.L00007a98:
 	addiu   $s7, $s7, 0x1
 	sllv    $at, $at, $s8
 	or      $gp, $gp, $at
 	addiu   $s8, $s8, 0x8
 	slti    $at, $s8, 0x3
 	bnezl   $at, .L00007a98
 	lbu     $at, 0x0($s7)
.L00007ab4:
 	addu    $t8, $t5, $s1
 	lbu     $t8, 0x0($t8)
 	sll     $t8, $t8, 0x2
 	addu    $t8, $t8, $sp
 	andi    $at, $gp, 0x7
 	sw      $at, 0x548($t8)
 	srl     $gp, $gp, 0x3
 	addiu   $s8, $s8, -3
 	addiu   $s1, $s1, 0x1
 	slt     $at, $s1, $t1
 	bnez    $at, .L00007a88
 	nop
 	slti    $at, $s1, 0x13
 	beqz    $at, .L00007b0c
.L00007aec:
 	addu    $t8, $t5, $s1
 	lbu     $t8, 0x0($t8)
 	addiu   $s1, $s1, 0x1
 	sll     $t8, $t8, 0x2
 	addu    $t8, $t8, $sp
 	sw      $zero, 0x548($t8)
 	slti    $at, $s1, 0x13
 	bnez    $at, .L00007aec
.L00007b0c:
 	li      $t8, 7
 	sw      $t8, 0xa3c($sp)
 	mtc1    $t2, $f0
 	mtc1    $t3, $f1
 	addiu   $a0, $sp, 0x548
 	li      $a1, 19
 	li      $a2, 19
 	li      $a3, 0
 	li      $t7, 0
 	addiu   $t8, $sp, 0xa38
 	jal     rzipBuildHufts
 	addiu   $t9, $sp, 0xa3c
 	mfc1    $t2, $f0
 	mfc1    $t3, $f1
 	lui     $t6, %hi(mask_bits)
 	addiu   $t6, $t6, %lo(mask_bits)
 	lhu     $s5, 0xa38($sp)
 	lw      $t0, 0xa3c($sp)
 	addu    $s4, $t2, $t3
 	sll     $s3, $t0, 0x1
 	addu    $s3, $s3, $t6
 	li      $t9, 0
 	li      $s2, 0
 	slt     $at, $t9, $s4
 	beqz    $at, .L00007d50
 	lhu     $s3, 0x0($s3)
.L00007b74:
 	slt     $at, $s8, $t0
 	beqz    $at, .L00007ba0
 	nop
 	lbu     $at, 0x0($s7)
.L00007b84:
 	addiu   $s7, $s7, 0x1
 	sllv    $at, $at, $s8
 	or      $gp, $gp, $at
 	addiu   $s8, $s8, 0x8
 	slt     $at, $s8, $t0
 	bnezl   $at, .L00007b84
 	lbu     $at, 0x0($s7)
.L00007ba0:
 	and     $s0, $gp, $s3
 	addu    $s0, $s0, $s5
 	sll     $s1, $s0, 0x2
 	addu    $s1, $s1, $s6
 	lbu     $s1, 0x1($s1)
 	srlv    $gp, $gp, $s1
 	subu    $s8, $s8, $s1
 	sll     $s1, $s0, 0x2
 	addu    $s1, $s1, $s6
 	lhu     $s1, 0x2($s1)
 	slti    $at, $s1, 0x10
 	beqz    $at, .L00007bec
 	nop
 	sll     $s2, $t9, 0x2
 	addu    $s2, $s2, $sp
 	sw      $s1, 0x548($s2)
 	addiu   $t9, $t9, 0x1
 	j       .L00007d44
 	move    $s2, $s1
.L00007bec:
 	li      $at, 16
 	bne     $s1, $at, .L00007c64
 	nop
 	slti    $at, $s8, 0x2
 	beqz    $at, .L00007c24
 	nop
 	lbu     $at, 0x0($s7)
.L00007c08:
 	addiu   $s7, $s7, 0x1
 	sllv    $at, $at, $s8
 	or      $gp, $gp, $at
 	addiu   $s8, $s8, 0x8
 	slti    $at, $s8, 0x2
 	bnezl   $at, .L00007c08
 	lbu     $at, 0x0($s7)
.L00007c24:
 	andi    $s1, $gp, 0x3
 	addiu   $s1, $s1, 0x3
 	srl     $gp, $gp, 0x2
 	addiu   $s8, $s8, -2
 	addu    $t8, $t9, $s1
 	slt     $at, $s4, $t8
 	bnez    $at, .L00007f10
 	sll     $t8, $t9, 0x2
 	addu    $t8, $t8, $sp
.L00007c48:
 	sw      $s2, 0x548($t8)
 	addiu   $t9, $t9, 0x1
 	addiu   $s1, $s1, -1
 	bnez    $s1, .L00007c48
 	addiu   $t8, $t8, 0x4
 	j       .L00007d44
 	nop
.L00007c64:
 	li      $at, 17
 	bne     $s1, $at, .L00007cdc
 	nop
 	slti    $at, $s8, 0x3
 	beqz    $at, .L00007c9c
 	nop
 	lbu     $at, 0x0($s7)
.L00007c80:
 	addiu   $s7, $s7, 0x1
 	sllv    $at, $at, $s8
 	or      $gp, $gp, $at
 	addiu   $s8, $s8, 0x8
 	slti    $at, $s8, 0x3
 	bnezl   $at, .L00007c80
 	lbu     $at, 0x0($s7)
.L00007c9c:
 	andi    $s1, $gp, 0x7
 	addiu   $s1, $s1, 0x3
 	srl     $gp, $gp, 0x3
 	addiu   $s8, $s8, -3
 	addu    $t8, $t9, $s1
 	slt     $at, $s4, $t8
 	bnez    $at, .L00007f10
 	sll     $t8, $t9, 0x2
 	addu    $t8, $t8, $sp
.L00007cc0:
 	sw      $zero, 0x548($t8)
 	addiu   $t9, $t9, 0x1
 	addiu   $s1, $s1, -1
 	bnez    $s1, .L00007cc0
 	addiu   $t8, $t8, 0x4
 	j       .L00007d44
 	li      $s2, 0
.L00007cdc:
 	slti    $at, $s8, 0x7
 	beqz    $at, .L00007d08
 	nop
 	lbu     $at, 0x0($s7)
.L00007cec:
 	addiu   $s7, $s7, 0x1
 	sllv    $at, $at, $s8
 	or      $gp, $gp, $at
 	addiu   $s8, $s8, 0x8
 	slti    $at, $s8, 0x7
 	bnezl   $at, .L00007cec
 	lbu     $at, 0x0($s7)
.L00007d08:
 	andi    $s1, $gp, 0x7f
 	addiu   $s1, $s1, 0xb
 	srl     $gp, $gp, 0x7
 	addiu   $s8, $s8, -7
 	addu    $t8, $t9, $s1
 	slt     $at, $s4, $t8
 	bnez    $at, .L00007f10
 	sll     $t8, $t9, 0x2
 	addu    $t8, $t8, $sp
.L00007d2c:
 	sw      $zero, 0x548($t8)
 	addiu   $t9, $t9, 0x1
 	addiu   $s1, $s1, -1
 	bnez    $s1, .L00007d2c
 	addiu   $t8, $t8, 0x4
 	li      $s2, 0
.L00007d44:
 	slt     $at, $t9, $s4
 	bnez    $at, .L00007b74
 	nop
.L00007d50:
 	sh      $s5, 0xa38($sp)
 	sh      $s0, 0xa3a($sp)
 	li      $t8, 9
 	sw      $t8, 0xa3c($sp)
 	mtc1    $t2, $f0
 	mtc1    $t3, $f1
 	addiu   $a0, $sp, 0x548
 	move    $a1, $t2
 	li      $a2, 257
 	lui     $a3, %hi(cplens)
 	addiu   $a3, $a3, %lo(cplens)
 	lui     $t7, %hi(cplext)
 	addiu   $t7, $t7, %lo(cplext)
 	addiu   $t8, $sp, 0xa38
 	jal     rzipBuildHufts
 	addiu   $t9, $sp, 0xa3c
 	mfc1    $t2, $f0
 	mfc1    $t3, $f1
 	bnez    $v0, .L00007f10
 	li      $t8, 6
 	sw      $t8, 0xa40($sp)
 	sll     $a0, $t2, 0x2
 	addu    $a0, $a0, $sp
 	addiu   $a0, $a0, 0x548
 	move    $a1, $t3
 	li      $a2, 0
 	lui     $a3, %hi(cpdist)
 	addiu   $a3, $a3, %lo(cpdist)
 	lui     $t7, %hi(cpdext)
 	addiu   $t7, $t7, %lo(cpdext)
 	addiu   $t8, $sp, 0xa3a
 	jal     rzipBuildHufts
 	addiu   $t9, $sp, 0xa40
 	bnez    $v0, .L00007f10
 	lhu     $a0, 0xa38($sp)
 	sll     $a0, $a0, 0x2
 	addu    $a0, $a0, $s6
 	lhu     $a1, 0xa3a($sp)
 	sll     $a1, $a1, 0x2
 	addu    $a1, $a1, $s6
 	lw      $a2, 0xa3c($sp)
 	jal     rzipInflateCodes
 	lw      $a3, 0xa40($sp)
 	bnez    $v0, .L00007f10
 	nop
 	j       .L00007f14
 	li      $v0, 0
.L00007e0c:
 	addiu   $sp, $sp, -128
 	sw      $a0, 0x10($sp)
 	lui     $a0, %hi(errstr_badlen)
 	sw      $ra, 0x0($sp)
 	sw      $at, 0x4($sp)
 	sw      $v0, 0x8($sp)
 	sw      $v1, 0xc($sp)
 	sw      $a1, 0x14($sp)
 	sw      $a2, 0x18($sp)
 	sw      $a3, 0x1c($sp)
 	sw      $t0, 0x20($sp)
 	sw      $t1, 0x24($sp)
 	sw      $t2, 0x28($sp)
 	sw      $t3, 0x2c($sp)
 	sw      $t4, 0x30($sp)
 	sw      $t5, 0x34($sp)
 	sw      $t6, 0x38($sp)
 	sw      $t7, 0x3c($sp)
 	sw      $s0, 0x40($sp)
 	sw      $s1, 0x44($sp)
 	sw      $s2, 0x48($sp)
 	sw      $s3, 0x4c($sp)
 	sw      $s4, 0x50($sp)
 	sw      $s5, 0x54($sp)
 	sw      $s6, 0x58($sp)
 	sw      $s7, 0x5c($sp)
 	sw      $t8, 0x60($sp)
 	sw      $t9, 0x64($sp)
 	sw      $gp, 0x70($sp)
 	sw      $sp, 0x74($sp)
 	sw      $s8, 0x78($sp)
 	addiu   $sp, $sp, -24
 	jal     crashPrint
 	addiu   $a0, $a0, %lo(errstr_badlen)
 	addiu   $sp, $sp, 0x18
 	lw      $ra, 0x0($sp)
 	lw      $at, 0x4($sp)
 	lw      $v0, 0x8($sp)
 	lw      $v1, 0xc($sp)
 	lw      $a0, 0x10($sp)
 	lw      $a1, 0x14($sp)
 	lw      $a2, 0x18($sp)
 	lw      $a3, 0x1c($sp)
 	lw      $t0, 0x20($sp)
 	lw      $t1, 0x24($sp)
 	lw      $t2, 0x28($sp)
 	lw      $t3, 0x2c($sp)
 	lw      $t4, 0x30($sp)
 	lw      $t5, 0x34($sp)
 	lw      $t6, 0x38($sp)
 	lw      $t7, 0x3c($sp)
 	lw      $s0, 0x40($sp)
 	lw      $s1, 0x44($sp)
 	lw      $s2, 0x48($sp)
 	lw      $s3, 0x4c($sp)
 	lw      $s4, 0x50($sp)
 	lw      $s5, 0x54($sp)
 	lw      $s6, 0x58($sp)
 	lw      $s7, 0x5c($sp)
 	lw      $t8, 0x60($sp)
 	lw      $t9, 0x64($sp)
 	lw      $gp, 0x70($sp)
 	lw      $sp, 0x74($sp)
 	lw      $s8, 0x78($sp)
 	addiu   $sp, $sp, 0x80
.L00007f10:
 	li      $v0, 1
.L00007f14:
 	lw      $ra, 0xa44($sp)
 	jr      $ra
 	nop

glabel rzipInflateStored
 	mfc1    $t2, $f17
 	mfc1    $t6, $f18
 	mfc1    $t7, $f16
 	andi    $t3, $s8, 0x7
 	srlv    $gp, $gp, $t3
 	subu    $s8, $s8, $t3
 	slti    $at, $s8, 0x10
 	beqz    $at, .L00007f64
 	nop
 	lbu     $at, 0x0($s7)
.L00007f48:
 	addiu   $s7, $s7, 0x1
 	sllv    $at, $at, $s8
 	or      $gp, $gp, $at
 	addiu   $s8, $s8, 0x8
 	slti    $at, $s8, 0x10
 	bnezl   $at, .L00007f48
 	lbu     $at, 0x0($s7)
.L00007f64:
 	andi    $t3, $gp, 0xffff
 	srl     $gp, $gp, 0x10
 	addiu   $s8, $s8, -16
 	slti    $at, $s8, 0x10
 	beqz    $at, .L00007f9c
 	nop
 	lbu     $at, 0x0($s7)
.L00007f80:
 	addiu   $s7, $s7, 0x1
 	sllv    $at, $at, $s8
 	or      $gp, $gp, $at
 	addiu   $s8, $s8, 0x8
 	slti    $at, $s8, 0x10
 	bnezl   $at, .L00007f80
 	lbu     $at, 0x0($s7)
.L00007f9c:
 	nor     $t5, $gp, $zero
 	andi    $t5, $t5, 0xffff
 	bne     $t3, $t5, .L0000801c
 	srl     $gp, $gp, 0x10
 	addiu   $s8, $s8, -16
 	addu    $t5, $t2, $t3
 	slt     $at, $t5, $t6
 	beqz    $at, .L0000801c
 	addu    $t5, $t7, $t2
 	addu    $t2, $t2, $t3
 	beqz    $t3, .L00008010
 	addiu   $t3, $t3, -1
.L00007fcc:
 	slti    $at, $s8, 0x8
 	beqz    $at, .L00007ff8
 	nop
 	lbu     $at, 0x0($s7)
.L00007fdc:
 	addiu   $s7, $s7, 0x1
 	sllv    $at, $at, $s8
 	or      $gp, $gp, $at
 	addiu   $s8, $s8, 0x8
 	slti    $at, $s8, 0x8
 	bnezl   $at, .L00007fdc
 	lbu     $at, 0x0($s7)
.L00007ff8:
 	sb      $gp, 0x0($t5)
 	addiu   $t5, $t5, 0x1
 	srl     $gp, $gp, 0x8
 	addiu   $s8, $s8, -8
 	bnez    $t3, .L00007fcc
 	addiu   $t3, $t3, -1
.L00008010:
 	mtc1    $t2, $f17
 	jr      $ra
 	li      $v0, 0
.L0000801c:
 	jr      $ra
 	li      $v0, 1

glabel rzipInflateFixed2
 	sw     $ra, 0xa44($sp)
 	sw     $s6, 0xa74($sp)
 	lui    $s6, %hi(var80090b10)
 	addiu  $s6, $s6, %lo(var80090b10)
 	lui    $a0, %hi(var80090b10+0x4)
 	addiu  $a0, $a0, %lo(var80090b10+0x4)
 	lui    $a1, %hi(var800914d8)
 	addiu  $a1, $a1, %lo(var800914d8)
 	li     $a2, 7
 	li     $a3, 5
 	jal    rzipInflateCodes
 	nop
 	lw     $s6, 0xa74($sp)
 	lw     $ra, 0xa44($sp)
 	jr     $ra
 	li     $v0, 0

glabel rzipBuildHufts
 	beqz   $a1, .L000084e8
 	mtc1   $s0, $f2
 	mtc1   $s1, $f3
 	mtc1   $s2, $f4
 	mtc1   $s3, $f5
 	mtc1   $s4, $f6
 	mtc1   $s5, $f7
 	mtc1   $s6, $f8
 	mtc1   $s7, $f9
 	mtc1   $s8, $f10
 	mtc1   $gp, $f11
 	mfc1   $s3, $f19
 	sd     $zero, 0x0($sp)
 	sd     $zero, 0x8($sp)
 	sd     $zero, 0x10($sp)
 	sd     $zero, 0x18($sp)
 	sd     $zero, 0x20($sp)
 	sd     $zero, 0x28($sp)
 	sd     $zero, 0x30($sp)
 	sd     $zero, 0x38($sp)
 	sw     $zero, 0x40($sp)
 	move   $t0, $a0
 	move   $t1, $a1
.L000080c0:
 	lw     $s7, 0x0($t0)
 	addiu  $t0, $t0, 0x4
 	sll    $s7, $s7, 0x2
 	addu   $s7, $s7, $sp
 	lw     $at, 0x0($s7)
 	addiu  $t1, $t1, -1
 	addiu  $at, $at, 0x1
 	bnez   $t1, .L000080c0
 	sw     $at, 0x0($s7)
 	lw     $s7, 0x0($sp)
 	beq    $s7, $a1, .L000084f0
 	lw     $t2, 0x0($t9)
 	li     $t3, 4
 	sll    $t2, $t2, 0x2
 	li     $at, 64
.L000080fc:
 	addu   $s7, $t3, $sp
 	lw     $s7, 0x0($s7)
 	bnez   $s7, .L00008114
 	nop
 	bne    $t3, $at, .L000080fc
 	addiu  $t3, $t3, 0x4
.L00008114:
 	slt    $at, $t2, $t3
 	beqz   $at, .L00008124
 	move   $t4, $t3
 	move   $t2, $t3
.L00008124:
 	li     $t1, 64
.L00008128:
 	addu   $s7, $t1, $sp
 	lw     $s7, 0x0($s7)
 	bnez   $s7, .L00008144
 	nop
 	addiu  $t1, $t1, -4
 	bnez   $t1, .L00008128
 	nop
.L00008144:
 	slt    $at, $t1, $t2
 	beqz   $at, .L00008154
 	move   $t5, $t1
 	move   $t2, $t1
.L00008154:
 	srl    $t2, $t2, 0x2
 	sw     $t2, 0x0($t9)
 	li     $t9, 1
 	srl    $s7, $t3, 0x2
 	slt    $at, $t3, $t1
 	beqz   $at, .L0000818c
 	sllv   $t9, $t9, $s7
.L00008170:
 	addu   $s7, $t3, $sp
 	lw     $s7, 0x0($s7)
 	addiu  $t3, $t3, 0x4
 	subu   $t9, $t9, $s7
 	slt    $at, $t3, $t1
 	bnez   $at, .L00008170
 	sll    $t9, $t9, 0x1
.L0000818c:
 	addu   $s7, $t1, $sp
 	lw     $at, 0x0($s7)
 	sw     $t9, 0x0($s7)
 	subu   $t9, $t9, $at
 	sw     $zero, 0x508($sp)
 	li     $t3, 0
 	addiu  $t0, $sp, 0x4
 	addiu  $t1, $t1, -4
 	beqz   $t1, .L000081d0
 	addiu  $t6, $sp, 0x50c
.L000081b4:
 	lw     $s7, 0x0($t0)
 	addiu  $t0, $t0, 0x4
 	addu   $t3, $t3, $s7
 	sw     $t3, 0x0($t6)
 	addiu  $t1, $t1, -4
 	bnez   $t1, .L000081b4
 	addiu  $t6, $t6, 0x4
.L000081d0:
 	srl    $t5, $t5, 0x2
 	srl    $t4, $t4, 0x2
 	move   $t0, $a0
 	li     $t1, 0
 	lw     $t3, 0x0($t0)
.L000081e4:
 	addiu  $t0, $t0, 0x4
 	beqz   $t3, .L0000820c
 	sll    $t3, $t3, 0x2
 	addu   $t3, $t3, $sp
 	lw     $s7, 0x504($t3)
 	sll    $s8, $s7, 0x2
 	addiu  $at, $s7, 0x1
 	sw     $at, 0x504($t3)
 	addu   $s8, $s8, $sp
 	sw     $t1, 0x84($s8)
.L0000820c:
 	addiu  $t1, $t1, 0x1
 	slt    $at, $t1, $a1
 	bnezl  $at, .L000081e4
 	lw     $t3, 0x0($t0)
 	sw     $zero, 0x504($sp)
 	li     $t1, 0
 	addiu  $t0, $sp, 0x84
 	li     $v0, -1
 	negu   $s1, $t2
 	sw     $zero, 0x44($sp)
 	j      .L00008474
 	li     $s0, 0
 	addu   $s1, $s1, $t2
.L00008240:
 	subu   $s0, $t5, $s1
 	slt    $at, $t2, $s0
 	beqz   $at, .L00008254
 	addiu  $v0, $v0, 0x1
 	move   $s0, $t2
.L00008254:
 	subu   $t3, $t4, $s1
 	li     $s2, 1
 	sllv   $s2, $s2, $t3
 	addiu  $s7, $a0, 0x1
 	slt    $at, $s7, $s2
 	beqz   $at, .L000082b4
 	nop
 	subu   $s2, $s2, $s7
 	sll    $t6, $t4, 0x2
 	addu   $t6, $t6, $sp
 	addiu  $t6, $t6, 0x0
 	addiu  $t3, $t3, 0x1
 	slt    $at, $t3, $s0
 	beqz   $at, .L000082b4
 	nop
.L00008290:
 	lw     $s7, 0x4($t6)
 	sll    $s2, $s2, 0x1
 	slt    $at, $s7, $s2
 	beqz   $at, .L000082b4
 	addiu  $t6, $t6, 0x4
 	addiu  $t3, $t3, 0x1
 	slt    $at, $t3, $s0
 	bnez   $at, .L00008290
 	subu   $s2, $s2, $s7
.L000082b4:
 	li     $s0, 1
 	sllv   $s0, $s0, $t3
 	sll    $t6, $s3, 0x2
 	addu   $t6, $t6, $s6
 	addiu  $s7, $s3, 0x1
 	sh     $s7, 0x0($t8)
 	addiu  $t8, $t6, 0x2
 	sh     $zero, 0x0($t8)
 	addiu  $t6, $t6, 0x4
 	sll    $s7, $v0, 0x2
 	addu   $s7, $s7, $sp
 	beqz   $v0, .L0000832c
 	sw     $t6, 0x44($s7)
 	sll    $s7, $v0, 0x2
 	addu   $s7, $s7, $sp
 	sw     $t1, 0x504($s7)
 	move   $s5, $t2
 	addiu  $s4, $t3, 0x10
 	addiu  $gp, $s3, 0x1
 	subu   $t3, $s1, $t2
 	srlv   $t3, $t1, $t3
 	addiu  $s7, $v0, -1
 	sll    $s7, $s7, 0x2
 	addu   $s7, $s7, $sp
 	lw     $s7, 0x44($s7)
 	sll    $at, $t3, 0x2
 	addu   $s7, $s7, $at
 	sb     $s4, 0x0($s7)
 	sb     $s5, 0x1($s7)
 	sh     $gp, 0x2($s7)
.L0000832c:
 	addu   $s3, $s3, $s0
 	addiu  $s3, $s3, 0x1
 	slti   $at, $s3, 0x501
 	beqz   $at, .L00008500
.L0000833c:
 	addu   $s7, $s1, $t2
.L00008340:
 	slt    $at, $s7, $t4
 	bnezl  $at, .L00008240
 	addu   $s1, $s1, $t2
 	subu   $s5, $t4, $s1
 	sll    $s7, $a1, 0x2
 	addu   $s7, $s7, $sp
 	addiu  $s7, $s7, 0x84
 	slt    $at, $t0, $s7
 	bnez   $at, .L00008370
 	li     $s4, 99
 	j      .L000083bc
 	li     $s2, 1
.L00008370:
 	lw     $s7, 0x0($t0)
 	slt    $at, $s7, $a2
 	beqz   $at, .L0000839c
 	nop
 	move   $gp, $s7
 	slti   $at, $s7, 0x100
 	bnezl  $at, .L00008394
 	li     $s4, 16
 	li     $s4, 15
.L00008394:
 	j      .L000083b8
 	addiu  $t0, $t0, 0x4
.L0000839c:
 	subu   $s7, $s7, $a2
 	addu   $s4, $s7, $t7
 	lbu    $s4, 0x0($s4)
 	sll    $s7, $s7, 0x1
 	addu   $s7, $s7, $a3
 	lhu    $gp, 0x0($s7)
 	addiu  $t0, $t0, 0x4
.L000083b8:
 	li     $s2, 1
.L000083bc:
 	subu   $s7, $t4, $s1
 	sllv   $s2, $s2, $s7
 	srlv   $t3, $t1, $s1
 	slt    $at, $t3, $s0
 	beqz   $at, .L00008410
 	sll    $s7, $s4, 0x18
 	andi   $s5, $s5, 0xff
 	sll    $s5, $s5, 0x10
 	or     $s7, $s7, $s5
 	andi   $s5, $gp, 0xffff
 	or     $s5, $s5, $s7
 	sll    $s2, $s2, 0x2
 	sll    $t3, $t3, 0x2
 	addu   $t3, $t3, $t6
 	sll    $s7, $s0, 0x2
 	addu   $s7, $s7, $t6
 	sw     $s5, 0x0($t3)
.L00008400:
 	addu   $t3, $t3, $s2
 	slt    $at, $t3, $s7
 	bnezl  $at, .L00008400
 	sw     $s5, 0x0($t3)
.L00008410:
 	addiu  $s7, $t4, -1
 	li     $t3, 1
 	sllv   $t3, $t3, $s7
 	and    $s7, $t1, $t3
 	beqz   $s7, .L00008438
 	xor    $t1, $t1, $t3
.L00008428:
 	srl    $t3, $t3, 0x1
 	and    $s7, $t1, $t3
 	bnez   $s7, .L00008428
 	xor    $t1, $t1, $t3
.L00008438:
 	j      .L00008448
 	li     $s8, 1
 	addiu  $v0, $v0, -1
.L00008444:
 	subu   $s1, $s1, $t2
.L00008448:
 	sllv   $s7, $s8, $s1
 	addiu  $s7, $s7, -1
 	sll    $at, $v0, 0x2
 	addu   $at, $at, $sp
 	lw     $at, 0x504($at)
 	and    $s7, $s7, $t1
 	bnel   $s7, $at, .L00008444
 	addiu  $v0, $v0, -1
 	bnez   $a0, .L0000833c
 	addiu  $a0, $a0, -1
.L00008470:
 	addiu  $t4, $t4, 0x1
.L00008474:
 	slt    $at, $t5, $t4
 	bnez   $at, .L00008498
 	sll    $a0, $t4, 0x2
 	addu   $a0, $a0, $sp
 	lw     $a0, 0x0($a0)
 	beqz   $a0, .L00008470
 	addiu  $a0, $a0, -1
 	j      .L00008340
 	addu   $s7, $s1, $t2
.L00008498:
 	bnezl  $t9, .L000084a4
 	li     $s7, 1
 	li     $s7, 0
.L000084a4:
 	li     $at, 1
 	bnel   $t5, $at, .L000084b4
 	li     $at, 1
 	li     $at, 0
.L000084b4:
 	and    $v0, $s7, $at
 	mtc1   $s3, $f19
.L000084bc:
 	mfc1   $s0, $f2
 	mfc1   $s1, $f3
 	mfc1   $s2, $f4
 	mfc1   $s3, $f5
 	mfc1   $s4, $f6
 	mfc1   $s5, $f7
 	mfc1   $s6, $f8
 	mfc1   $s7, $f9
 	mfc1   $s8, $f10
 	jr     $ra
 	mfc1   $gp, $f11
.L000084e8:
 	jr     $ra
 	li     $v0, 1
.L000084f0:
 	sh     $zero, 0x0($t8)
 	sw     $zero, 0x0($t9)
 	j      .L000084bc
 	li     $v0, 0
.L00008500:
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
 	addiu  $sp, $sp, -24
 	sw     $s3, 0x4($sp)
 	lui    $a0, %hi(errstr_huftsoverflow)
 	addiu  $a0, $a0, %lo(errstr_huftsoverflow)
 	jal    crashPrint
 	lw     $a1, 0x4($sp)
 	addiu  $sp, $sp, 0x18
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
 	j      .L0000833c
 	addiu  $sp, $sp, 0x80

glabel rzipInflateCodes
 	mfc1   $t3, $f16
 	mfc1   $t5, $f18
 	mfc1   $s4, $f17
 	lui    $s0, %hi(mask_bits)
 	addiu  $s0, $s0, %lo(mask_bits)
 	sll    $t7, $a2, 0x1
 	addu   $t7, $t7, $s0
 	lhu    $t2, 0x0($t7)
 	sll    $t7, $a3, 0x1
 	addu   $t7, $t7, $s0
 	lhu    $t0, 0x0($t7)
.L0000863c:
 	slt    $at, $s8, $a2
.L00008640:
 	beqz   $at, .L00008668
 	and    $s5, $gp, $t2
.L00008648:
 	lbu    $s5, 0x0($s7)
 	addiu  $s7, $s7, 0x1
 	sllv   $s5, $s5, $s8
 	addiu  $s8, $s8, 0x8
 	slt    $at, $s8, $a2
 	bnez   $at, .L00008648
 	or     $gp, $gp, $s5
 	and    $s5, $gp, $t2
.L00008668:
 	sll    $s5, $s5, 0x2
 	addu   $s5, $s5, $a0
 	lbu    $s1, 0x0($s5)
 	slti   $at, $s1, 0x11
 	bnez   $at, .L000086e8
 	li     $t9, 99
 	lbu    $t7, 0x1($s5)
.L00008684:
 	beq    $s1, $t9, .L000088a0
 	addiu  $s1, $s1, -16
 	subu   $s8, $s8, $t7
 	slt    $at, $s8, $s1
 	beqz   $at, .L000086b8
 	srlv   $gp, $gp, $t7
.L0000869c:
 	lbu    $at, 0x0($s7)
 	addiu  $s7, $s7, 0x1
 	sllv   $at, $at, $s8
 	addiu  $s8, $s8, 0x8
 	slt    $t7, $s8, $s1
 	bnez   $t7, .L0000869c
 	or     $gp, $gp, $at
.L000086b8:
 	sll    $t7, $s1, 0x1
 	addu   $t7, $t7, $s0
 	lhu    $t7, 0x0($t7)
 	lhu    $t8, 0x2($s5)
 	and    $t7, $t7, $gp
 	addu   $t7, $t7, $t8
 	sll    $t7, $t7, 0x2
 	addu   $s5, $s6, $t7
 	lbu    $s1, 0x0($s5)
 	slti   $at, $s1, 0x11
 	beqzl  $at, .L00008684
 	lbu    $t7, 0x1($s5)
.L000086e8:
 	lbu    $t7, 0x1($s5)
 	li     $at, 16
 	srlv   $gp, $gp, $t7
 	bne    $s1, $at, .L00008710
 	subu   $s8, $s8, $t7
 	lhu    $t7, 0x2($s5)
 	addu   $t8, $t3, $s4
 	sb     $t7, 0x0($t8)
 	j      .L0000863c
 	addiu  $s4, $s4, 0x1
.L00008710:
 	li     $at, 15
 	beq    $s1, $at, .L00008894
 	nop
 	slt    $at, $s8, $s1
 	beqz   $at, .L00008744
 	sll    $t7, $s1, 0x1
.L00008728:
 	lbu    $t9, 0x0($s7)
 	addiu  $s7, $s7, 0x1
 	sllv   $t9, $t9, $s8
 	addiu  $s8, $s8, 0x8
 	slt    $at, $s8, $s1
 	bnez   $at, .L00008728
 	or     $gp, $gp, $t9
.L00008744:
 	addu   $t7, $t7, $s0
 	lhu    $t7, 0x0($t7)
 	lhu    $t8, 0x2($s5)
 	and    $t7, $t7, $gp
 	addu   $s2, $t7, $t8
 	subu   $s8, $s8, $s1
 	slt    $at, $s8, $a3
 	beqz   $at, .L00008784
 	srlv   $gp, $gp, $s1
.L00008768:
 	lbu    $t7, 0x0($s7)
 	addiu  $s7, $s7, 0x1
 	sllv   $t7, $t7, $s8
 	addiu  $s8, $s8, 0x8
 	slt    $at, $s8, $a3
 	bnez   $at, .L00008768
 	or     $gp, $gp, $t7
.L00008784:
 	and    $t7, $gp, $t0
 	sll    $t7, $t7, 0x2
 	addu   $s5, $a1, $t7
 	lbu    $s1, 0x0($s5)
 	slti   $at, $s1, 0x11
 	bnez   $at, .L00008810
 	li     $t7, 99
.L000087a0:
 	beq    $s1, $t7, .L000088a8
 	lbu    $t7, 0x1($s5)
 	addiu  $s1, $s1, -16
 	srlv   $gp, $gp, $t7
 	subu   $s8, $s8, $t7
 	slt    $at, $s8, $s1
 	beqz   $at, .L000087e0
 	nop
 	lbu    $at, 0x0($s7)
.L000087c4:
 	addiu  $s7, $s7, 0x1
 	sllv   $at, $at, $s8
 	or     $gp, $gp, $at
 	addiu  $s8, $s8, 0x8
 	slt    $at, $s8, $s1
 	bnezl  $at, .L000087c4
 	lbu    $at, 0x0($s7)
.L000087e0:
 	sll    $t7, $s1, 0x1
 	addu   $t7, $t7, $s0
 	lhu    $t7, 0x0($t7)
 	lhu    $t8, 0x2($s5)
 	and    $t7, $t7, $gp
 	addu   $t7, $t7, $t8
 	sll    $t7, $t7, 0x2
 	addu   $s5, $s6, $t7
 	lbu    $s1, 0x0($s5)
 	slti   $at, $s1, 0x11
 	beqz   $at, .L000087a0
 	li     $t7, 99
.L00008810:
 	lbu    $t7, 0x1($s5)
 	sll    $t8, $s1, 0x1
 	subu   $s8, $s8, $t7
 	slt    $at, $s8, $s1
 	beqz   $at, .L00008844
 	srlv   $gp, $gp, $t7
.L00008828:
 	lbu    $t7, 0x0($s7)
 	addiu  $s7, $s7, 0x1
 	sllv   $t7, $t7, $s8
 	addiu  $s8, $s8, 0x8
 	slt    $at, $s8, $s1
 	bnez   $at, .L00008828
 	or     $gp, $gp, $t7
.L00008844:
 	addu    $t7, $t8, $s0
 	lhu    $t7, 0x0($t7)
 	lhu    $t8, 0x2($s5)
 	and    $t7, $t7, $gp
 	subu   $s3, $s4, $t7
 	subu   $s3, $s3, $t8
 	srlv   $gp, $gp, $s1
 	subu   $s8, $s8, $s1
 	addu   $t7, $s4, $s2
 	addu   $t8, $t3, $s3
 	addu   $t9, $t3, $s4
 	addu   $s4, $s4, $s2
 	addu   $v0, $t3, $s4
.L00008878:
 	lbu    $t7, 0x0($t8)
 	addiu  $t9, $t9, 0x1
 	sb     $t7, -0x1($t9)
 	bne    $t9, $v0, .L00008878
 	addiu  $t8, $t8, 0x1
 	j      .L00008640
 	slt    $at, $s8, $a2
.L00008894:
 	mtc1   $s4, $f17
 	jr     $ra
 	li     $v0, 0
.L000088a0:
 	jr     $ra
 	li     $v0, 2
.L000088a8:
 	jr     $ra
 	li     $v0, 4

glabel rzipInflateFixed
 	addiu  $sp, $sp, -2696
 	sw     $s0, 0xa48($sp)
 	sw     $s1, 0xa4c($sp)
 	sw     $s2, 0xa50($sp)
 	sw     $s3, 0xa54($sp)
 	sw     $s4, 0xa58($sp)
 	sw     $s5, 0xa5c($sp)
 	sw     $s6, 0xa60($sp)
 	sw     $s7, 0xa64($sp)
 	sw     $ra, 0xa80($sp)
 	mtc1   $zero, $f19
 	lui    $s6, %hi(var80090b10)
 	addiu  $s6, $s6, %lo(var80090b10)
 	li     $t0, 8
 	addiu  $t2, $sp, 0x548
 	addiu  $t1, $t2, 0x240
.L000088f0:
 	addiu  $t2, $t2, 0x4
 	bne    $t2, $t1, .L000088f0
 	sw     $t0, -0x4($t2)
 	li     $t0, 9
 	addiu  $t1, $t2, 0x1c0
.L00008904:
 	addiu  $t2, $t2, 0x4
 	bne    $t2, $t1, .L00008904
 	sw     $t0, -0x4($t2)
 	li     $t0, 7
 	addiu  $t1, $t2, 0x60
.L00008918:
 	addiu  $t2, $t2, 0x4
 	bne    $t2, $t1, .L00008918
 	sw     $t0, -0x4($t2)
 	li     $t0, 8
 	addiu  $t1, $t2, 0x20
.L0000892c:
 	addiu  $t2, $t2, 0x4
 	bne    $t2, $t1, .L0000892c
 	sw     $t0, -0x4($t2)
 	li     $t0, 7
 	sw     $t0, 0x9cc($sp)
 	addiu  $a0, $sp, 0x548
 	li     $a1, 288
 	li     $a2, 257
 	lui    $a3, %hi(cplens)
 	addiu  $a3, $a3, %lo(cplens)
 	lui    $t7, %hi(cplext)
 	addiu  $t7, $t7, %lo(cplext)
 	addiu  $t8, $sp, 0x9c8
 	jal    rzipBuildHufts
 	addiu  $t9, $sp, 0x9cc
 	addiu  $t0, $sp, 0x548
 	li     $t1, 5
 	addiu  $t2, $t0, 0x78
.L00008974:
 	addiu  $t0, $t0, 0x4
 	bne    $t0, $t2, .L00008974
 	sw     $t1, -0x4($t0)
 	li     $t0, 5
 	sw     $t0, 0x9d4($sp)
 	addiu  $a0, $sp, 0x548
 	li     $a1, 30
 	li     $a2, 0
 	lui    $a3, %hi(cpdist)
 	addiu  $a3, $a3, %lo(cpdist)
 	lui    $t7, %hi(cpdext)
 	addiu  $t7, $t7, %lo(cpdext)
 	addiu  $t8, $sp, 0x9d0
 	jal    rzipBuildHufts
 	addiu  $t9, $sp, 0x9d4
 	lw     $s0, 0xa48($sp)
 	lw     $s1, 0xa4c($sp)
 	lw     $s2, 0xa50($sp)
 	lw     $s3, 0xa54($sp)
 	lw     $s4, 0xa58($sp)
 	lw     $s5, 0xa5c($sp)
 	lw     $s6, 0xa60($sp)
 	lw     $s7, 0xa64($sp)
 	lw     $ra, 0xa80($sp)
 	jr     $ra
 	addiu  $sp, $sp, 0xa88

glabel rzipIs1173
 	li     $t1, 0x11
 	lbu    $t0, 0x0($a0)
 	bne    $t0, $t1, .L00008a00
 	li     $t1, 0x73
 	lbu    $t0, 0x1($a0)
 	bne    $t0, $t1, .L00008a00
 	nop
 	jr     $ra
 	li     $v0, 1
.L00008a00:
 	jr     $ra
 	li     $v0, 0

glabel rzipGetSomething
 	lui    $v0, %hi(var80091558)
 	addiu  $v0, $v0, %lo(var80091558)
 	jr     $ra
 	lw     $v0, 0x0($v0)
