#include "asm_helper.h"
#include "macros.inc"
.set noat
.set noreorder

.rdata

glabel var70059c90
.float 1.8793852329254
glabel var70059c94
.float 1.5320888757706
glabel var70059c98
.float 0.34729635715485
glabel var70059c9c
.float -0.34729635715485
glabel var70059ca0
.float -1.8793852329254
glabel var70059ca4
.float 1.5320888757706
glabel var70059ca8
.float -1.5320888757706
glabel var70059cac
.float 0.34729635715485
glabel var70059cb0
.float -1.8793852329254
glabel var70059cb4
.float 1.7320507764816
glabel var70059cb8
.float 1.9696154594421
glabel var70059cbc
.float 1.2855752706528
glabel var70059cc0
.float 0.68404030799866
glabel var70059cc4
.float 1.2855752706528
glabel var70059cc8
.float -0.68404030799866
glabel var70059ccc
.float 1.9696154594421
glabel var70059cd0
.float 0.68404030799866
glabel var70059cd4
.float 1.9696154594421
glabel var70059cd8
.float -1.2855752706528
glabel var70059cdc
.float 1.7320507764816
glabel var70059ce0
.float 1.8793852329254
glabel var70059ce4
.float 1.5320888757706
glabel var70059ce8
.float 0.34729635715485
glabel var70059cec
.float -0.34729635715485
glabel var70059cf0
.float -1.8793852329254
glabel var70059cf4
.float 1.5320888757706
glabel var70059cf8
.float -1.5320888757706
glabel var70059cfc
.float 0.34729635715485
glabel var70059d00
.float -1.8793852329254
glabel var70059d04
.float 1.7320507764816
glabel var70059d08
.float 1.9696154594421
glabel var70059d0c
.float 1.2855752706528
glabel var70059d10
.float 0.68404030799866
glabel var70059d14
.float 1.2855752706528
glabel var70059d18
.float -0.68404030799866
glabel var70059d1c
.float 1.9696154594421
glabel var70059d20
.float 0.68404030799866
glabel var70059d24
.float 1.9696154594421
glabel var70059d28
.float -1.2855752706528
glabel var70059d2c
.float 1.7320507764816
glabel var70059d30
.float 0.50190991163254
glabel var70059d34
.float -0.25023818016052
glabel var70059d38
.float -5.7313961982727
glabel var70059d3c
.float 0.51763808727264
glabel var70059d40
.float -0.25215724110603
glabel var70059d44
.float -1.9153244495392
glabel var70059d48
.float 0.55168896913528
glabel var70059d4c
.float -0.25606986880302
glabel var70059d50
.float -1.1550565958023
glabel var70059d54
.float 0.61038726568222
glabel var70059d58
.float -0.26213228702545
glabel var70059d5c
.float -0.83137738704681
glabel var70059d60
.float 0.87172341346741
glabel var70059d64
.float -0.28184548020363
glabel var70059d68
.float -0.54142016172409
glabel var70059d6c
.float 1.1831008195877
glabel var70059d70
.float -0.29642227292061
glabel var70059d74
.float -0.46528974175453
glabel var70059d78
.float 1.9318516254425
glabel var70059d7c
.float -0.31511810421944
glabel var70059d80
.float -0.41066989302635
glabel var70059d84
.float 5.7368564605713
glabel var70059d88
.float -0.33908542990685
glabel var70059d8c
.float -0.37004679441452
glabel var70059d90
.float 0.70710676908493
glabel var70059d94
.float -0.54119610786438
glabel var70059d98
.float -1.3065630197525

# These values are used in the following file
glabel var70059d9c
.float 0.86602538824081
glabel var70059da0
.float 0.86602538824081
glabel var70059da4
.float 1.9318516254425
glabel var70059da8
.float 0.70710676908493
glabel var70059dac
.float 0.51763808727264
glabel var70059db0
.float 0.50431448221207
glabel var70059db4
.float 0.54119610786438
glabel var70059db8
.float 0.63023620843887
glabel var70059dbc
.float 0.8213397860527
glabel var70059dc0
.float 1.3065630197525
glabel var70059dc4
.float 3.8306488990784
glabel var70059dc8
.float -0.79335331916809
glabel var70059dcc
.float -0.60876142978668
glabel var70059dd0
.float -0.9238795042038
glabel var70059dd4
.float -0.38268342614174
glabel var70059dd8
.float -0.99144488573074
glabel var70059ddc
.float -0.13052618503571
glabel var70059de0
.float 0.38268342614174
glabel var70059de4
.float 0.60876142978668
glabel var70059de8
.float -0.79335331916809
glabel var70059dec
.float -0.9238795042038
glabel var70059df0
.float -0.99144488573074
glabel var70059df4
.float 0.13052618503571

.text

/**
 * Determined to be ASM because of the following:
 * - copy of $sp to temp register
 * - heavy reuse of float registers
 * - every mul is followed by a nop
 */
glabel func00046650
	addiu  $sp, $sp, -0x90
	or     $t0, $sp, $zero
	addiu  $t1, $t0, 0x48
	lwc1   $f4, 0x3c($a0)
	lwc1   $f6, 0x40($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x44($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x40($a0)
	swc1   $f6, 0x44($a0)
	lwc1   $f4, 0x34($a0)
	lwc1   $f6, 0x38($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x3c($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x38($a0)
	swc1   $f6, 0x3c($a0)
	lwc1   $f4, 0x2c($a0)
	lwc1   $f6, 0x30($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x34($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x30($a0)
	swc1   $f6, 0x34($a0)
	lwc1   $f4, 0x24($a0)
	lwc1   $f6, 0x28($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x2c($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x28($a0)
	swc1   $f6, 0x2c($a0)
	lwc1   $f4, 0x1c($a0)
	lwc1   $f6, 0x20($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x24($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x20($a0)
	swc1   $f6, 0x24($a0)
	lwc1   $f4, 0x14($a0)
	lwc1   $f6, 0x18($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x1c($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x18($a0)
	swc1   $f6, 0x1c($a0)
	lwc1   $f4, 0xc($a0)
	lwc1   $f6, 0x10($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x14($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x10($a0)
	swc1   $f6, 0x14($a0)
	lwc1   $f4, 0x4($a0)
	lwc1   $f6, 0x8($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0xc($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x8($a0)
	swc1   $f6, 0xc($a0)
	lwc1   $f4, 0x0($a0)
	lwc1   $f6, 0x4($a0)
	add.s  $f4, $f4, $f6
	swc1   $f4, 0x4($a0)
	lwc1   $f4, 0x34($a0)
	lwc1   $f6, 0x3c($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x44($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x3c($a0)
	swc1   $f6, 0x44($a0)
	lwc1   $f4, 0x24($a0)
	lwc1   $f6, 0x2c($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x34($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x2c($a0)
	swc1   $f6, 0x34($a0)
	lwc1   $f4, 0x14($a0)
	lwc1   $f6, 0x1c($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x24($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0x1c($a0)
	swc1   $f6, 0x24($a0)
	lwc1   $f4, 0x4($a0)
	lwc1   $f6, 0xc($a0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x14($a0)
	add.s  $f6, $f6, $f8
	swc1   $f4, 0xc($a0)
	swc1   $f6, 0x14($a0)
	lwc1   $f4, 0x0($a0)
	lwc1   $f6, 0x30($a0)
	add.s  $f2, $f4, $f4
	add.s  $f0, $f2, $f6
	lwc1   $f4, 0x10($a0)
	lui    $at, %hi(var70059c90)
	lwc1   $f6, %lo(var70059c90)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x20($a0)
	lui    $at, %hi(var70059c94)
	lwc1   $f10, %lo(var70059c94)($at)
	lwc1   $f16, 0x40($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059c98)
	lwc1   $f6, %lo(var70059c98)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x0($t0)
	lwc1   $f4, 0x10($a0)
	lui    $at, %hi(var70059c9c)
	lwc1   $f6, %lo(var70059c9c)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x20($a0)
	lui    $at, %hi(var70059ca0)
	lwc1   $f10, %lo(var70059ca0)($at)
	lwc1   $f16, 0x40($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059ca4)
	lwc1   $f6, %lo(var70059ca4)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x8($t0)
	lwc1   $f4, 0x10($a0)
	lui    $at, %hi(var70059ca8)
	lwc1   $f6, %lo(var70059ca8)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x20($a0)
	lui    $at, %hi(var70059cac)
	lwc1   $f10, %lo(var70059cac)($at)
	lwc1   $f16, 0x40($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059cb0)
	lwc1   $f6, %lo(var70059cb0)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0xc($t0)
	lwc1   $f4, 0x10($a0)
	add.s  $f2, $f2, $f4
	lwc1   $f6, 0x20($a0)
	lwc1   $f8, 0x30($a0)
	lwc1   $f10, 0x40($a0)
	sub.s  $f2, $f2, $f6
	lwc1   $f16, 0x0($a0)
	sub.s  $f2, $f2, $f8
	sub.s  $f2, $f2, $f8
	sub.s  $f2, $f2, $f10
	swc1   $f2, 0x4($t0)
	sub.s  $f2, $f16, $f4
	add.s  $f2, $f2, $f6
	sub.s  $f2, $f2, $f8
	add.s  $f2, $f2, $f10
	swc1   $f2, 0x10($t0)
	lwc1   $f0, 0x18($a0)
	lui    $at, %hi(var70059cb4)
	lwc1   $f4, %lo(var70059cb4)($at)
	mul.s  $f0, $f0, $f4
 	nop
	lwc1   $f4, 0x8($a0)
	lui    $at, %hi(var70059cb8)
	lwc1   $f6, %lo(var70059cb8)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x28($a0)
	lui    $at, %hi(var70059cbc)
	lwc1   $f10, %lo(var70059cbc)($at)
	lwc1   $f16, 0x38($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059cc0)
	lwc1   $f6, %lo(var70059cc0)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x14($t0)
	neg.s  $f0, $f0
	lwc1   $f4, 0x8($a0)
	lui    $at, %hi(var70059cc4)
	lwc1   $f6, %lo(var70059cc4)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x28($a0)
	lui    $at, %hi(var70059cc8)
	lwc1   $f10, %lo(var70059cc8)($at)
	lwc1   $f16, 0x38($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059ccc)
	lwc1   $f6, %lo(var70059ccc)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x18($t0)
	lwc1   $f4, 0x8($a0)
	lui    $at, %hi(var70059cd0)
	lwc1   $f6, %lo(var70059cd0)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x28($a0)
	lui    $at, %hi(var70059cd4)
	lwc1   $f10, %lo(var70059cd4)($at)
	lwc1   $f16, 0x38($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059cd8)
	lwc1   $f6, %lo(var70059cd8)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x1c($t0)
	lwc1   $f4, 0x8($a0)
	lwc1   $f6, 0x28($a0)
	sub.s  $f4, $f4, $f6
	lwc1   $f8, 0x38($a0)
	lui    $at, %hi(var70059cdc)
	lwc1   $f10, %lo(var70059cdc)($at)
	sub.s  $f4, $f4, $f8
	mul.s  $f4, $f4, $f10
 	nop
	swc1   $f4, 0x20($t0)
	lwc1   $f4, 0x4($a0)
	lwc1   $f6, 0x34($a0)
	add.s  $f2, $f4, $f4
	add.s  $f0, $f2, $f6
	lwc1   $f4, 0x14($a0)
	lui    $at, %hi(var70059ce0)
	lwc1   $f6, %lo(var70059ce0)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x24($a0)
	lui    $at, %hi(var70059ce4)
	lwc1   $f10, %lo(var70059ce4)($at)
	lwc1   $f16, 0x44($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059ce8)
	lwc1   $f6, %lo(var70059ce8)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x24($t0)
	lwc1   $f4, 0x14($a0)
	lui    $at, %hi(var70059cec)
	lwc1   $f6, %lo(var70059cec)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x24($a0)
	lui    $at, %hi(var70059cf0)
	lwc1   $f10, %lo(var70059cf0)($at)
	lwc1   $f16, 0x44($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059cf4)
	lwc1   $f6, %lo(var70059cf4)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x2c($t0)
	lwc1   $f4, 0x14($a0)
	lui    $at, %hi(var70059cf8)
	lwc1   $f6, %lo(var70059cf8)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x24($a0)
	lui    $at, %hi(var70059cfc)
	lwc1   $f10, %lo(var70059cfc)($at)
	lwc1   $f16, 0x44($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059d00)
	lwc1   $f6, %lo(var70059d00)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x30($t0)
	lwc1   $f4, 0x14($a0)
	add.s  $f2, $f2, $f4
	lwc1   $f6, 0x24($a0)
	lwc1   $f8, 0x34($a0)
	lwc1   $f10, 0x44($a0)
	sub.s  $f2, $f2, $f6
	lwc1   $f16, 0x4($a0)
	sub.s  $f2, $f2, $f8
	sub.s  $f2, $f2, $f8
	sub.s  $f2, $f2, $f10
	swc1   $f2, 0x28($t0)
	sub.s  $f2, $f16, $f4
	add.s  $f2, $f2, $f6
	sub.s  $f2, $f2, $f8
	add.s  $f2, $f2, $f10
	swc1   $f2, 0x34($t0)
	lwc1   $f0, 0x1c($a0)
	lui    $at, %hi(var70059d04)
	lwc1   $f4, %lo(var70059d04)($at)
	mul.s  $f0, $f0, $f4
 	nop
	lwc1   $f4, 0xc($a0)
	lui    $at, %hi(var70059d08)
	lwc1   $f6, %lo(var70059d08)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x2c($a0)
	lui    $at, %hi(var70059d0c)
	lwc1   $f10, %lo(var70059d0c)($at)
	lwc1   $f16, 0x3c($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059d10)
	lwc1   $f6, %lo(var70059d10)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x38($t0)
	neg.s  $f0, $f0
	lwc1   $f4, 0xc($a0)
	lui    $at, %hi(var70059d14)
	lwc1   $f6, %lo(var70059d14)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x2c($a0)
	lui    $at, %hi(var70059d18)
	lwc1   $f10, %lo(var70059d18)($at)
	lwc1   $f16, 0x3c($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059d1c)
	lwc1   $f6, %lo(var70059d1c)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x3c($t0)
	lwc1   $f4, 0xc($a0)
	lui    $at, %hi(var70059d20)
	lwc1   $f6, %lo(var70059d20)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x2c($a0)
	lui    $at, %hi(var70059d24)
	lwc1   $f10, %lo(var70059d24)($at)
	lwc1   $f16, 0x3c($a0)
	mul.s  $f8, $f8, $f10
 	nop
	lui    $at, %hi(var70059d28)
	lwc1   $f6, %lo(var70059d28)($at)
	mul.s  $f16, $f16, $f6
 	nop
	add.s  $f4, $f4, $f8
	add.s  $f4, $f4, $f16
	add.s  $f4, $f4, $f0
	swc1   $f4, 0x40($t0)
	lwc1   $f4, 0xc($a0)
	lwc1   $f6, 0x2c($a0)
	sub.s  $f4, $f4, $f6
	lwc1   $f8, 0x3c($a0)
	lui    $at, %hi(var70059d2c)
	lwc1   $f10, %lo(var70059d2c)($at)
	sub.s  $f4, $f4, $f8
	mul.s  $f4, $f4, $f10
 	nop
	swc1   $f4, 0x44($t0)
	lwc1   $f4, 0x0($t0)
	lwc1   $f6, 0x14($t0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x24($t0)
	lwc1   $f10, 0x38($t0)
	lui    $at, %hi(var70059d30)
	lwc1   $f16, %lo(var70059d30)($at)
	add.s  $f8, $f8, $f10
	mul.s  $f8, $f8, $f16
 	nop
	lui    $at, %hi(var70059d34)
	lwc1   $f6, %lo(var70059d34)($at)
	add.s  $f10, $f4, $f8
	mul.s  $f10, $f10, $f6
 	nop
	lui    $at, %hi(var70059d38)
	lwc1   $f16, %lo(var70059d38)($at)
	sub.s  $f4, $f4, $f8
	mul.s  $f4, $f4, $f16
 	nop
	swc1   $f10, 0x0($t1)
	swc1   $f4, 0x44($t1)
	lwc1   $f4, 0x4($t0)
	lwc1   $f6, 0x20($t0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x28($t0)
	lwc1   $f10, 0x44($t0)
	lui    $at, %hi(var70059d3c)
	lwc1   $f16, %lo(var70059d3c)($at)
	add.s  $f8, $f8, $f10
	mul.s  $f8, $f8, $f16
 	nop
	lui    $at, %hi(var70059d40)
	lwc1   $f6, %lo(var70059d40)($at)
	add.s  $f10, $f4, $f8
	mul.s  $f10, $f10, $f6
 	nop
	lui    $at, %hi(var70059d44)
	lwc1   $f16, %lo(var70059d44)($at)
	sub.s  $f4, $f4, $f8
	mul.s  $f4, $f4, $f16
 	nop
	swc1   $f10, 0x4($t1)
	swc1   $f4, 0x40($t1)
	lwc1   $f4, 0x8($t0)
	lwc1   $f6, 0x18($t0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x2c($t0)
	lwc1   $f10, 0x3c($t0)
	lui    $at, %hi(var70059d48)
	lwc1   $f16, %lo(var70059d48)($at)
	add.s  $f8, $f8, $f10
	mul.s  $f8, $f8, $f16
 	nop
	lui    $at, %hi(var70059d4c)
	lwc1   $f6, %lo(var70059d4c)($at)
	add.s  $f10, $f4, $f8
	mul.s  $f10, $f10, $f6
 	nop
	lui    $at, %hi(var70059d50)
	lwc1   $f16, %lo(var70059d50)($at)
	sub.s  $f4, $f4, $f8
	mul.s  $f4, $f4, $f16
 	nop
	swc1   $f10, 0x8($t1)
	swc1   $f4, 0x3c($t1)
	lwc1   $f4, 0xc($t0)
	lwc1   $f6, 0x1c($t0)
	add.s  $f4, $f4, $f6
	lwc1   $f8, 0x30($t0)
	lwc1   $f10, 0x40($t0)
	lui    $at, %hi(var70059d54)
	lwc1   $f16, %lo(var70059d54)($at)
	add.s  $f8, $f8, $f10
	mul.s  $f8, $f8, $f16
 	nop
	lui    $at, %hi(var70059d58)
	lwc1   $f6, %lo(var70059d58)($at)
	add.s  $f10, $f4, $f8
	mul.s  $f10, $f10, $f6
 	nop
	lui    $at, %hi(var70059d5c)
	lwc1   $f16, %lo(var70059d5c)($at)
	sub.s  $f4, $f4, $f8
	mul.s  $f4, $f4, $f16
 	nop
	swc1   $f10, 0xc($t1)
	swc1   $f4, 0x38($t1)
	lwc1   $f4, 0xc($t0)
	lwc1   $f6, 0x1c($t0)
	sub.s  $f4, $f4, $f6
	lwc1   $f8, 0x30($t0)
	lwc1   $f10, 0x40($t0)
	lui    $at, %hi(var70059d60)
	lwc1   $f16, %lo(var70059d60)($at)
	sub.s  $f8, $f8, $f10
	mul.s  $f8, $f8, $f16
 	nop
	lui    $at, %hi(var70059d64)
	lwc1   $f6, %lo(var70059d64)($at)
	add.s  $f10, $f4, $f8
	mul.s  $f10, $f10, $f6
 	nop
	lui    $at, %hi(var70059d68)
	lwc1   $f16, %lo(var70059d68)($at)
	sub.s  $f4, $f4, $f8
	mul.s  $f4, $f4, $f16
 	nop
	swc1   $f10, 0x14($t1)
	swc1   $f4, 0x30($t1)
	lwc1   $f4, 0x8($t0)
	lwc1   $f6, 0x18($t0)
	sub.s  $f4, $f4, $f6
	lwc1   $f8, 0x2c($t0)
	lwc1   $f10, 0x3c($t0)
	lui    $at, %hi(var70059d6c)
	lwc1   $f16, %lo(var70059d6c)($at)
	sub.s  $f8, $f8, $f10
	mul.s  $f8, $f8, $f16
 	nop
	lui    $at, %hi(var70059d70)
	lwc1   $f6, %lo(var70059d70)($at)
	add.s  $f10, $f4, $f8
	mul.s  $f10, $f10, $f6
 	nop
	lui    $at, %hi(var70059d74)
	lwc1   $f16, %lo(var70059d74)($at)
	sub.s  $f4, $f4, $f8
	mul.s  $f4, $f4, $f16
 	nop
	swc1   $f10, 0x18($t1)
	swc1   $f4, 0x2c($t1)
	lwc1   $f4, 0x4($t0)
	lwc1   $f6, 0x20($t0)
	sub.s  $f4, $f4, $f6
	lwc1   $f8, 0x28($t0)
	lwc1   $f10, 0x44($t0)
	lui    $at, %hi(var70059d78)
	lwc1   $f16, %lo(var70059d78)($at)
	sub.s  $f8, $f8, $f10
	mul.s  $f8, $f8, $f16
 	nop
	lui    $at, %hi(var70059d7c)
	lwc1   $f6, %lo(var70059d7c)($at)
	add.s  $f10, $f4, $f8
	mul.s  $f10, $f10, $f6
 	nop
	lui    $at, %hi(var70059d80)
	lwc1   $f16, %lo(var70059d80)($at)
	sub.s  $f4, $f4, $f8
	mul.s  $f4, $f4, $f16
 	nop
	swc1   $f10, 0x1c($t1)
	swc1   $f4, 0x28($t1)
	lwc1   $f4, 0x0($t0)
	lwc1   $f6, 0x14($t0)
	sub.s  $f4, $f4, $f6
	lwc1   $f8, 0x24($t0)
	lwc1   $f10, 0x38($t0)
	lui    $at, %hi(var70059d84)
	lwc1   $f16, %lo(var70059d84)($at)
	sub.s  $f8, $f8, $f10
	mul.s  $f8, $f8, $f16
 	nop
	lui    $at, %hi(var70059d88)
	lwc1   $f6, %lo(var70059d88)($at)
	add.s  $f10, $f4, $f8
	mul.s  $f10, $f10, $f6
 	nop
	lui    $at, %hi(var70059d8c)
	lwc1   $f16, %lo(var70059d8c)($at)
	sub.s  $f4, $f4, $f8
	mul.s  $f4, $f4, $f16
 	nop
	swc1   $f10, 0x20($t1)
	swc1   $f4, 0x24($t1)
	lwc1   $f4, 0x34($t0)
	lui    $at, %hi(var70059d90)
	lwc1   $f6, %lo(var70059d90)($at)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x10($t0)
	lui    $at, %hi(var70059d94)
	lwc1   $f10, %lo(var70059d94)($at)
	lui    $at, %hi(var70059d98)
	lwc1   $f16, %lo(var70059d98)($at)
	add.s  $f6, $f8, $f4
	mul.s  $f6, $f6, $f10
 	nop
	sub.s  $f4, $f8, $f4
	mul.s  $f4, $f4, $f16
 	nop
	swc1   $f6, 0x10($t1)
	swc1   $f4, 0x34($t1)
	or     $t0, $t1, $zero
	lw     $t1, 0xa0($sp)
	or     $t2, $a2, $zero
	or     $t3, $a3, $zero
	andi   $a1, $a1, 0x1
	beqz   $a1, .L000471b8
 	nop
	lwc1   $f4, 0x24($t0)
	neg.s  $f4, $f4
	lwc1   $f6, 0x0($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x0($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x0($t2)
	lwc1   $f6, 0x28($t0)
	lwc1   $f8, 0x4($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x4($t3)
	sub.s  $f10, $f8, $f10
	swc1   $f10, 0x4($t2)
	lwc1   $f4, 0x2c($t0)
	neg.s  $f4, $f4
	lwc1   $f6, 0x8($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x8($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x8($t2)
	lwc1   $f6, 0x30($t0)
	lwc1   $f8, 0xc($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0xc($t3)
	sub.s  $f10, $f8, $f10
	swc1   $f10, 0xc($t2)
	lwc1   $f4, 0x34($t0)
	neg.s  $f4, $f4
	lwc1   $f6, 0x10($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x10($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x10($t2)
	lwc1   $f6, 0x38($t0)
	lwc1   $f8, 0x14($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x14($t3)
	sub.s  $f10, $f8, $f10
	swc1   $f10, 0x14($t2)
	lwc1   $f4, 0x3c($t0)
	neg.s  $f4, $f4
	lwc1   $f6, 0x18($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x18($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x18($t2)
	lwc1   $f6, 0x40($t0)
	lwc1   $f8, 0x1c($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x1c($t3)
	sub.s  $f10, $f8, $f10
	swc1   $f10, 0x1c($t2)
	lwc1   $f4, 0x44($t0)
	neg.s  $f4, $f4
	lwc1   $f6, 0x20($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x20($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x20($t2)
	lwc1   $f6, 0x44($t0)
	neg.s  $f6, $f6
	lwc1   $f8, 0x24($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x24($t3)
	sub.s  $f10, $f8, $f10
	swc1   $f10, 0x24($t2)
	lwc1   $f4, 0x40($t0)
	lwc1   $f6, 0x28($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x28($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x28($t2)
	lwc1   $f6, 0x3c($t0)
	neg.s  $f6, $f6
	lwc1   $f8, 0x2c($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x2c($t3)
	sub.s  $f10, $f8, $f10
	swc1   $f10, 0x2c($t2)
	lwc1   $f4, 0x38($t0)
	lwc1   $f6, 0x30($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x30($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x30($t2)
	lwc1   $f6, 0x34($t0)
	neg.s  $f6, $f6
	lwc1   $f8, 0x34($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x34($t3)
	sub.s  $f10, $f8, $f10
	swc1   $f10, 0x34($t2)
	lwc1   $f4, 0x30($t0)
	lwc1   $f6, 0x38($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x38($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x38($t2)
	lwc1   $f6, 0x2c($t0)
	neg.s  $f6, $f6
	lwc1   $f8, 0x3c($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x3c($t3)
	sub.s  $f10, $f8, $f10
	swc1   $f10, 0x3c($t2)
	lwc1   $f4, 0x28($t0)
	lwc1   $f6, 0x40($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x40($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x40($t2)
	lwc1   $f6, 0x24($t0)
	neg.s  $f6, $f6
	lwc1   $f8, 0x44($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x44($t3)
	sub.s  $f10, $f8, $f10
	swc1   $f10, 0x44($t2)
	b      .L000473d4
 	nop
.L000471b8:
	lwc1   $f4, 0x24($t0)
	neg.s  $f4, $f4
	lwc1   $f6, 0x0($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x0($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x0($t2)
	lwc1   $f6, 0x28($t0)
	neg.s  $f6, $f6
	lwc1   $f8, 0x4($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x4($t3)
	add.s  $f10, $f8, $f10
	swc1   $f10, 0x4($t2)
	lwc1   $f4, 0x2c($t0)
	neg.s  $f4, $f4
	lwc1   $f6, 0x8($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x8($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x8($t2)
	lwc1   $f6, 0x30($t0)
	neg.s  $f6, $f6
	lwc1   $f8, 0xc($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0xc($t3)
	add.s  $f10, $f8, $f10
	swc1   $f10, 0xc($t2)
	lwc1   $f4, 0x34($t0)
	neg.s  $f4, $f4
	lwc1   $f6, 0x10($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x10($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x10($t2)
	lwc1   $f6, 0x38($t0)
	neg.s  $f6, $f6
	lwc1   $f8, 0x14($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x14($t3)
	add.s  $f10, $f8, $f10
	swc1   $f10, 0x14($t2)
	lwc1   $f4, 0x3c($t0)
	neg.s  $f4, $f4
	lwc1   $f6, 0x18($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x18($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x18($t2)
	lwc1   $f6, 0x40($t0)
	neg.s  $f6, $f6
	lwc1   $f8, 0x1c($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x1c($t3)
	add.s  $f10, $f8, $f10
	swc1   $f10, 0x1c($t2)
	lwc1   $f4, 0x44($t0)
	neg.s  $f4, $f4
	lwc1   $f6, 0x20($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x20($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x20($t2)
	lwc1   $f6, 0x44($t0)
	lwc1   $f8, 0x24($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x24($t3)
	add.s  $f10, $f8, $f10
	swc1   $f10, 0x24($t2)
	lwc1   $f4, 0x40($t0)
	lwc1   $f6, 0x28($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x28($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x28($t2)
	lwc1   $f6, 0x3c($t0)
	lwc1   $f8, 0x2c($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x2c($t3)
	add.s  $f10, $f8, $f10
	swc1   $f10, 0x2c($t2)
	lwc1   $f4, 0x38($t0)
	lwc1   $f6, 0x30($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x30($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x30($t2)
	lwc1   $f6, 0x34($t0)
	lwc1   $f8, 0x34($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x34($t3)
	add.s  $f10, $f8, $f10
	swc1   $f10, 0x34($t2)
	lwc1   $f4, 0x30($t0)
	lwc1   $f6, 0x38($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x38($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x38($t2)
	lwc1   $f6, 0x2c($t0)
	lwc1   $f8, 0x3c($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x3c($t3)
	add.s  $f10, $f8, $f10
	swc1   $f10, 0x3c($t2)
	lwc1   $f4, 0x28($t0)
	lwc1   $f6, 0x40($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x40($t3)
	add.s  $f4, $f4, $f8
	swc1   $f4, 0x40($t2)
	lwc1   $f6, 0x24($t0)
	lwc1   $f8, 0x44($t1)
	mul.s  $f8, $f6, $f8
 	nop
	lwc1   $f10, 0x44($t3)
	add.s  $f10, $f8, $f10
	swc1   $f10, 0x44($t2)
.L000473d4:
	lwc1   $f4, 0x20($t0)
	lwc1   $f6, 0x48($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x1c($t0)
	lwc1   $f10, 0x4c($t1)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x0($t3)
	swc1   $f8, 0x4($t3)
	lwc1   $f4, 0x18($t0)
	lwc1   $f6, 0x50($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x14($t0)
	lwc1   $f10, 0x54($t1)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x8($t3)
	swc1   $f8, 0xc($t3)
	lwc1   $f4, 0x10($t0)
	lwc1   $f6, 0x58($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0xc($t0)
	lwc1   $f10, 0x5c($t1)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x10($t3)
	swc1   $f8, 0x14($t3)
	lwc1   $f4, 0x8($t0)
	lwc1   $f6, 0x60($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x4($t0)
	lwc1   $f10, 0x64($t1)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x18($t3)
	swc1   $f8, 0x1c($t3)
	lwc1   $f4, 0x0($t0)
	lwc1   $f6, 0x68($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x0($t0)
	lwc1   $f10, 0x6c($t1)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x20($t3)
	swc1   $f8, 0x24($t3)
	lwc1   $f4, 0x4($t0)
	lwc1   $f6, 0x70($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x8($t0)
	lwc1   $f10, 0x74($t1)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x28($t3)
	swc1   $f8, 0x2c($t3)
	lwc1   $f4, 0xc($t0)
	lwc1   $f6, 0x78($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x10($t0)
	lwc1   $f10, 0x7c($t1)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x30($t3)
	swc1   $f8, 0x34($t3)
	lwc1   $f4, 0x14($t0)
	lwc1   $f6, 0x80($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x18($t0)
	lwc1   $f10, 0x84($t1)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x38($t3)
	swc1   $f8, 0x3c($t3)
	lwc1   $f4, 0x1c($t0)
	lwc1   $f6, 0x88($t1)
	mul.s  $f4, $f4, $f6
 	nop
	lwc1   $f8, 0x20($t0)
	lwc1   $f10, 0x8c($t1)
	mul.s  $f8, $f8, $f10
 	nop
	swc1   $f4, 0x40($t3)
	swc1   $f8, 0x44($t3)
	addiu  $sp, $sp, 0x90
	jr     $ra
 	nop
