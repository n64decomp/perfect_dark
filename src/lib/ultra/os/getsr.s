#include "asm_helper.h"
#include "macros.inc"

.section .text

glabel __osGetSR
	STAY2(mfc0 $v0, C0_SR)
	jr $ra
