#include "asm_helper.h"
#include "macros.inc"

.set noreorder
.section .text

glabel __osSetCompare
	mtc0 $a0, C0_COMPARE
	jr   $ra
	nop
