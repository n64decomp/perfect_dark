#include "asm_helper.h"

.text
LEAF(osGetCount)
	STAY2(mfc0 v0, C0_COUNT)
	jr ra
END(osGetCount)
