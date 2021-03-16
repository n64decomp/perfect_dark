#include "asm_helper.h"

.set noreorder
.text
LEAF(__osSetCompare)
	mtc0 a0, C0_COMPARE
	jr ra
	nop
END(__osSetCompare)
