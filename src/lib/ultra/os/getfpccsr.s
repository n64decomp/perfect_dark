#include "asm_helper.h"
#include "macros.inc"

.section .text

glabel __osGetFpcCsr
	STAY2(cfc1 $v0, $31)
	jr $ra
