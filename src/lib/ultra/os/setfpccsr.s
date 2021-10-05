#include "macros.inc"

.set noreorder
.text

glabel __osSetFpcCsr
	cfc1 $v0, $31
	ctc1 $a0, $31
	jr   $ra
	nop
