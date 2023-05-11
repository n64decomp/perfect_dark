#include "macros.inc"
.set noat
.set noreorder
.set gp=64

.text

/**
 * AI execution is entered via aiTick and exited through either aiYield
 * or aiTerminate.
 *
 * aiTick's $a0 is a pointer to the code where the execution should be resumed.
 * aiTick saves $ra to the stack before jumping to AI code so that execution can
 * be returned to the caller once aiYield or aiTerminate is used.
 *
 * aiYield returns a pointer to the code where execution should be resumed on
 * the next AI tick for this chr, while aiTerminate returns NULL.
 *
 * Stack usage:
 * 0x28 = saved $s0
 * 0x24 = saved $ra
 * 0x00 through 0x20 = function arguments used in AI code
 */

glabel aiTick
	addiu   $sp, $sp, -0x30
	sw      $s0, 0x28($sp)
	move    $s0, $a1
	jr      $a0
	sw      $ra, 0x24($sp)

glabel aiYield
	move    $v0, $ra
	lw      $s0, 0x28($sp)
	lw      $ra, 0x24($sp)
	jr      $ra
	addiu   $sp, $sp, 0x30

glabel aiTerminate
	jal     aiTerminateCleanup
	move    $a0, $s0
	move    $v0, $zero
	lw      $s0, 0x28($sp)
	lw      $ra, 0x24($sp)
	jr      $ra
	addiu   $sp, $sp, 0x30
