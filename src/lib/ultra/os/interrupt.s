#include "asm_helper.h"
#include "macros.inc"
.set noat
.set noreorder

.text

glabel __osDisableInt
	lui    $t2, %hi(__osGlobalIntMask)
	addiu  $t2, $t2, %lo(__osGlobalIntMask)
	lw     $t3, 0x0($t2)
	andi   $t3, $t3, 0xff00
	mfc0   $t0, $12
	addiu  $at, $zero, -2
	and    $t1, $t0, $at
	mtc0   $t1, $12
	andi   $v0, $t0, 0x1
	lw     $t0, 0x0($t2)
	andi   $t0, $t0, 0xff00
	beq    $t0, $t3, .L00049618
	lui    $t2, %hi(__osRunningThread)
	addiu  $t2, $t2, %lo(__osRunningThread)
	lw     $t1, 0x118($t2)
	andi   $t2, $t1, 0xff00
	and    $t2, $t2, $t0
	lui    $at, 0xffff
	ori    $at, $at, 0xff
	and    $t1, $t1, $at
	or     $t1, $t1, $t2
	addiu  $at, $zero, -2
	and    $t1, $t1, $at
	mtc0   $t1, $12
 	nop
 	nop
.L00049618:
	jr     $ra
 	nop

glabel __osRestoreInt
	mfc0   $t0, $12
	or     $t0, $t0, $a0
	mtc0   $t0, $12
 	nop
 	nop
	jr     $ra
 	nop
