#include <ultra64.h>
#include "lib/lib_16110.h"

GLOBAL_ASM(
glabel func00004f60nb
/*     4f60:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*     4f64:	afa40008 */ 	sw	$a0,0x8($sp)
/*     4f68:	afa5000c */ 	sw	$a1,0xc($sp)
/*     4f6c:	afa60010 */ 	sw	$a2,0x10($sp)
/*     4f70:	afa70014 */ 	sw	$a3,0x14($sp)
/*     4f74:	03e00008 */ 	jr	$ra
/*     4f78:	27bd0008 */ 	addiu	$sp,$sp,0x8
);
