#include <ultra64.h>
#include "types.h"

GLOBAL_ASM(
glabel func00039fc0
/*    39fc0:	3c0e8006 */ 	lui	$t6,0x8006
/*    39fc4:	8dcef114 */ 	lw	$t6,-0xeec($t6)
/*    39fc8:	adc00000 */ 	sw	$zero,0x0($t6)
/*    39fcc:	03e00008 */ 	jr	$ra
/*    39fd0:	00000000 */ 	sll	$zero,$zero,0x0
/*    39fd4:	03e00008 */ 	jr	$ra
/*    39fd8:	00000000 */ 	sll	$zero,$zero,0x0
/*    39fdc:	00000000 */ 	sll	$zero,$zero,0x0
);