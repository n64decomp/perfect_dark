#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel __osGetCause
/*    4b160:	40026800 */ 	mfc0	$v0,$13
/*    4b164:	03e00008 */ 	jr	$ra
/*    4b168:	00000000 */ 	nop
/*    4b16c:	00000000 */ 	nop
);
