#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

// This bss belongs in lib_37b00 but is here due to reordering issues
u32 var8009c3d0;
u32 var8009c3d4;
u32 var8009c3d8;
u32 var8009c3dc;
u32 var8009c3e0;
u32 var8009c3e4;
u32 var8009c3e8;
u32 var8009c3ec;
u32 var8009c3f0;
u32 var8009c3f4;

GLOBAL_ASM(
glabel func00038d10
/*    38d10:	03e00008 */ 	jr	$ra
/*    38d14:	8c82002c */ 	lw	$v0,0x2c($a0)
/*    38d18:	03e00008 */ 	jr	$ra
/*    38d1c:	00000000 */ 	nop
/*    38d20:	03e00008 */ 	jr	$ra
/*    38d24:	00000000 */ 	nop
);
