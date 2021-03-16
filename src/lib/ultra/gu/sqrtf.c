#include <ultra64.h>

GLOBAL_ASM(
glabel sqrtf
/*    4a5d0:	03e00008 */ 	jr	$ra
/*    4a5d4:	46006004 */ 	sqrt.s	$f0,$f12
);
