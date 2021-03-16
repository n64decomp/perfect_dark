#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel __osSetCompare
/*    51880:	40845800 */ 	mtc0	$a0,$11
/*    51884:	03e00008 */ 	jr	$ra
/*    51888:	00000000 */ 	nop
);
