#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osSetSR
/*    4acc0:	40846000 */ 	mtc0	$a0,$12
/*    4acc4:	00000000 */ 	nop
/*    4acc8:	03e00008 */ 	jr	$ra
/*    4accc:	00000000 */ 	nop
);
