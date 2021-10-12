#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func00038d10
/*    38d10:	03e00008 */ 	jr	$ra
/*    38d14:	8c82002c */ 	lw	$v0,0x2c($a0)
/*    38d18:	03e00008 */ 	jr	$ra
/*    38d1c:	00000000 */ 	nop
);

void func00038d20(void)
{
	// empty
}
