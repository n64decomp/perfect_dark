#include "macros.inc"
.set noat
.set noreorder

.text

/**
 * This function is generated automatically by makerom. It clears the BSS
 * segment, sets the stack pointer to 0x80000f10 and then calls boot.
 */
glabel preamble
 	lui	   $t0, %hi(_bssSegmentStart)
 	lui	   $t1, %hi(_bssSegmentLen)
 	addiu  $t0, $t0, %lo(_bssSegmentStart)
 	ori	   $t1, $t1, %lo(_bssSegmentLen)
.L00001010:
 	addi   $t1, $t1, -8
 	sw     $zero, 0($t0)
 	sw     $zero, 4($t0)
 	bnez   $t1, .L00001010
 	addi   $t0, $t0, 8
 	lui    $t2, %hi(tlbInitFromPreamble)
 	lui    $sp, 0x8000
 	addiu  $t2, $t2, %lo(tlbInitFromPreamble)
 	jr     $t2
 	addiu  $sp, $sp, 0xf10
