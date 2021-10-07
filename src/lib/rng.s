#include "macros.inc"
.set noat
.set noreorder
.set gp=64

.data

glabel g_RngSeed
.dword 0xab8d9f7781280783

.text

/**
 * u32 random(void)
 *
 * Generate a random number between 0 and 4294967295.
 */
glabel random
	lui     $a0, %hi(g_RngSeed)
	ld      $a0, %lo(g_RngSeed)($a0)
	lui     $at, %hi(g_RngSeed)
	dsll32  $a2, $a0, 31
	dsll    $a1, $a0, 31
	dsrl    $a2, $a2, 31
	dsrl32  $a1, $a1, 0
	dsll32  $a0, $a0, 12
	or      $a2, $a2, $a1
	dsrl32  $a0, $a0, 0
	xor     $a2, $a2, $a0
	dsrl    $a0, $a2, 20
	andi    $a0, $a0, 0xfff
	xor     $a0, $a0, $a2
	dsll32  $v0, $a0, 0
	sd      $a0, %lo(g_RngSeed)($at)
	jr      $ra
	dsra32  $v0, $v0, 0

/**
 * void rngSetSeed(u32 seed)
 *
 * Set the given seed as the RNG seed. Add 1 to make sure it isn't 0.
 */
glabel rngSetSeed
	daddiu  $a0, $a0, 1
	lui     $at, %hi(g_RngSeed)
	sd      $a0, %lo(g_RngSeed)($at)
	jr      $ra
	li      $a0, 0

/**
 * u32 rngRotateSeed(u64 *value);
 *
 * Rotate the given seed using the same algorithm as random().
 *
 * Store the new 64-bit seed at the pointed address and return the same seed
 * cast as a u32.
 */
glabel rngRotateSeed
	ld      $a3, 0($a0)
	dsll32  $a2, $a3, 31
	dsll    $a1, $a3, 31
	dsrl    $a2, $a2, 31
	dsrl32  $a1, $a1, 0
	dsll32  $a3, $a3, 12
	or      $a2, $a2, $a1
	dsrl32  $a3, $a3, 0
	xor     $a2, $a2, $a3
	dsrl    $a3, $a2, 20
	andi    $a3, $a3, 0xfff
	xor     $a3, $a3, $a2
	dsll32  $v0, $a3, 0
	sd      $a3, 0($a0)
	jr      $ra
	dsra32  $v0, $v0, 0
