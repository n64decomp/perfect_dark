#include "asm_helper.h"

.set noreorder
.text

LEAF(__osSetFpcCsr)
	cfc1 v0, $31
	ctc1 a0, $31
	jr ra
	nop
END(__osSetFpcCsr)
