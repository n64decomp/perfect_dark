#include "asm_helper.h"

.text
LEAF(__osGetFpcCsr)
	STAY2(cfc1 v0, $31)
	jr ra
END(__osGetFpcCsr)
