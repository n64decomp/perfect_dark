#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel __osGetSR
/*    4acd0:	40026000 */ 	mfc0	$v0,$12
/*    4acd4:	03e00008 */ 	jr	$ra
/*    4acd8:	00000000 */ 	nop
/*    4acdc:	00000000 */ 	nop
);
