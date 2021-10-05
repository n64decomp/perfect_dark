#include "macros.inc"

.section .text

glabel sqrtf
	sqrt.s $f0, $f12
	jr $ra
