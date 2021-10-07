#include "macros.h"
.set noat
.set noreorder

/**
 * Get the return address ($ra) that the caller would return to.
 *
 * For example, a C function could use:
 *
 *     osSyncPrintf("Called from %u\n", getReturnAddress());
 *
 * It follows the current $ra to get to the function that called
 * getReturnAddress, then steps backwards through that function's bytecode until
 * it finds either `addiu $sp` or `sw $ra, 0xnn($sp)`.
 *
 * If it finds `addiu $sp` first then it's reached the top of the function and
 * $ra wasn't saved to the stack. In this case something is massively wrong and
 * the function returns -1.
 *
 * If it finds `sw $ra, 0xnn($sp)` first then it reads the stack offset out of
 * the instruction, then reads the value out of the stack using that offset.
 */
glabel getReturnAddress
	or     $a0, $ra, $zero
	addiu  $v0, $zero, -1
.loop:
	lw     $t0, 0($a0)
	addiu  $t2, $zero, 0x27bd
	srl    $t1, $t0, 16
	beq    $t1, $t2, .foundtop
	nop
	dli    $t2, 0xafbf
	beql   $t1, $t2, .foundstore
	sll    $t2, $t0, 16
	j      .loop
	addiu  $a0, $a0, -4

	sll    $t2, $t0, 16
.foundstore:
	sra    $t2, $t2, 16
	add    $t2, $t2, $sp
	lw     $v0, 0($t2)
.foundtop:
	jr     $ra
	nop
