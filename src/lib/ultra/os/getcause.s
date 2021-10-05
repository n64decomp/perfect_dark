#include "asm_helper.h"
#include "macros.inc"

.section .text

glabel __osGetCause
	STAY2(mfc0 $v0, C0_CAUSE)
	jr $ra
