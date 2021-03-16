#include "asm_helper.h"

.text
LEAF(__osGetCause)
	STAY2(mfc0 v0, C0_CAUSE)
	jr ra
END(__osGetCause)
