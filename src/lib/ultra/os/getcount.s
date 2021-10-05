#include "asm_helper.h"
#include "macros.inc"

.section .text

glabel osGetCount
	STAY2(mfc0 $v0, C0_COUNT)
	jr $ra
