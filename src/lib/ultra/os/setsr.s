#include "asm_helper.h"

.set noreorder
.text
LEAF(__osSetSR)
	mtc0 a0, C0_SR
	nop
	jr ra
	nop
END(__osSetSR)
