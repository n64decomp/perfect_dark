#include "asm_helper.h"

.text
LEAF(__osGetSR)
	STAY2(mfc0 v0, C0_SR)
	jr ra
END(__osGetSR)
