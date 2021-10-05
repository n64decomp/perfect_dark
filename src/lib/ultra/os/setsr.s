#include "asm_helper.h"
#include "macros.inc"

.set noreorder
.section .text

glabel __osSetSR
	mtc0 $a0, C0_SR
	nop
	jr   $ra
	nop
