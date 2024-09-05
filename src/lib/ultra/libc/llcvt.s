#include "asm_helper.h"
#include "macros.inc"
#include "versions.h"

/**
 * Rare almost certainly compiled a C version of this file
 * then patched the compiled assembly.
 *
 * __f_to_ull:
 *
 *    The C version loads 0x8000000000000000 from rodata while Rare's does
 *    lui 0x8000 and shifts left by 32. This is an optimisation that Rare made.
 *
 * __ull_to_d:
 *
 *    Rare had to ASM patch some instructions due to Rare's use of the FPU's
 *    native register mode (FR=1), which the assembler assumes is off.
 *    However, Rare patched these wrong, and as a result calling __ull_to_d with
 *    very large numbers can cause a crash. This function is never called though
 *    and only exists in the beta version.
 *
 * __d_to_ull:
 *
 *    This function contains both of the above. Like __ull_to_d, it is also
 *    patched incorrectly and can cause a crash. It was also not used and only
 *    exists in the beta version.
 */

.set noat
.set noreorder
.set gp=64

.text

#if VERSION < VERSION_NTSC_1_0
glabel __d_to_ll
	trunc.l.d  $f4, $f12
	dmfc1      $v0, $f4
	nop
	dsll32     $v1, $v0, 0
	dsra32     $v1, $v1, 0
	jr         $ra
	dsra32     $v0, $v0, 0
#endif

glabel __f_to_ll
glabel __fixsfdi
	trunc.l.s  $f4, $f12
	dmfc1      $v0, $f4
	nop
	dsll32     $v1, $v0, 0
	dsra32     $v1, $v1, 0
	jr         $ra
	dsra32     $v0, $v0, 0

#if VERSION < VERSION_NTSC_1_0
glabel __d_to_ull
	cfc1       $t6, $31
	li         $v0, 1
	ctc1       $v0, $31
	nop
	cvt.l.d    $f4, $f12
	cfc1       $v0, $31
	nop
	andi       $at, $v0, 4
	andi       $v0, $v0, 0x78
	beqz       $v0, .NB00005b50

	# Same @bug as in __ull_to_d
	lui        $at, 0x43e0
	mtc1       $at, $f4

	li         $v0, 1
	sub.d      $f4, $f12, $f4
	ctc1       $v0, $31
	nop
	cvt.l.d    $f4, $f4
	cfc1       $v0, $31
	nop
	andi       $at, $v0, 4
	andi       $v0, $v0, 0x78
	bnez       $v0, .NB00005b48
	nop
	lui        $t7, 0x8000
	dsll32     $t7, $t7, 0
	dmfc1      $v0, $f4
	beqz       $zero, .NB00005b60
	or         $v0, $v0, $t7
.NB00005b48:
	beqz       $zero, .NB00005b60
	li         $v0, -1
.NB00005b50:
	dmfc1      $v0, $f4
	nop
	bltz       $v0, .NB00005b48
	nop
.NB00005b60:
	ctc1       $t6, $31
	dsll32     $v1, $v0, 0
	dsra32     $v1, $v1, 0
	jr         $ra
	dsra32     $v0, $v0, 0
#endif

glabel __f_to_ull
glabel __fixunssfdi
	cfc1       $t6, $31
	li         $v0, 1
	ctc1       $v0, $31
	nop
	cvt.l.s    $f4, $f12
	cfc1       $v0, $31
	nop
	andi       $at, $v0, 4
	andi       $v0, $v0, 0x78
	beqz       $v0, .L00005af4
	lui        $at, 0x5f00
	mtc1       $at, $f4
	li         $v0, 1
	sub.s      $f4, $f12, $f4
	ctc1       $v0, $31
	nop
	cvt.l.s    $f4, $f4
	cfc1       $v0, $31
	nop
	andi       $at, $v0, 4
	andi       $v0, $v0, 0x78
	bnez       $v0, .L00005aec
	nop
	lui        $t7, 0x8000
	dsll32     $t7, $t7, 0
	dmfc1      $v0, $f4
	b          .L00005b04
	or         $v0, $v0, $t7
	.L00005aec:
	b          .L00005b04
	li         $v0, -1
	.L00005af4:
	dmfc1      $v0, $f4
	nop
	bltz       $v0, .L00005aec
	nop
	.L00005b04:
	ctc1       $t6, $31
	dsll32     $v1, $v0, 0
	dsra32     $v1, $v1, 0
	jr         $ra
	dsra32     $v0, $v0, 0

glabel __ll_to_d
glabel __floatdidf
	sw         $a0, 0($sp)
	sw         $a1, 4($sp)
	ld         $t6, 0($sp)
	dmtc1      $t6, $f4
	jr         $ra
	cvt.d.l    $f0, $f4

#if VERSION < VERSION_NTSC_1_0
glabel __ll_to_f
	sw         $a0, 0($sp)
	sw         $a1, 4($sp)
	ld         $t6, 0($sp)
	dmtc1      $t6, $f4
	jr         $ra
	cvt.s.l    $f0, $f4
#endif

#if VERSION < VERSION_NTSC_1_0
glabel __ull_to_d
	sw         $a0, 0($sp)
	sw         $a1, 4($sp)
	ld         $t6, 0($sp)
	dmtc1      $t6, $f4
	bgez       $t6, .NB00005c68
	cvt.d.l    $f0, $f4

	# IDO emits:
	#
	#    lui $at, 0x41f0
	#    mtc1 $at, $f7
	#    mtc1 $zero, $f6
	#
	# ...which is correct when FR=0. $f7 is the upper half of the 64-bit register.
	#
	# @bug: Rare patched this to account for FR=1, but did it incorrectly and
	# loaded the immediate into the lower half of the register.
	# They should have used dmtc1 to set the value for the entire $f6 register.

	lui        $at, 0x41f0
	mtc1       $at, $f6

	nop
	add.d      $f0, $f0, $f6
.NB00005c68:
	jr         $ra
	nop
#endif

glabel __ull_to_f
glabel __floatundisf
	sw         $a0, 0($sp)
	sw         $a1, 4($sp)
	ld         $t6, 0($sp)
	dmtc1      $t6, $f4
	bgez       $t6, .end
	cvt.s.l    $f0, $f4
	lui        $at, 0x4f80
	mtc1       $at, $f6
	nop
	add.s      $f0, $f0, $f6
.end:
	jr         $ra
	nop
