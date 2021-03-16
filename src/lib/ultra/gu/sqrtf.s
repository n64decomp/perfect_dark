#include "asm_helper.h"

.text
LEAF(sqrtf)
	sqrt.s $f0, $f12
	jr ra
END(sqrtf)
