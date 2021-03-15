#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_3c4d0.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func00039f70
/*    39f70:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    39f74:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    39f78:	afa40028 */ 	sw	$a0,0x28($sp)
/*    39f7c:	240e0011 */ 	addiu	$t6,$zero,0x11
/*    39f80:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    39f84:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    39f88:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    39f8c:	00003025 */ 	or	$a2,$zero,$zero
/*    39f90:	00003825 */ 	or	$a3,$zero,$zero
/*    39f94:	0c00f184 */ 	jal	alEvtqPostEvent
/*    39f98:	24840048 */ 	addiu	$a0,$a0,0x48
/*    39f9c:	10000001 */ 	b	.L00039fa4
/*    39fa0:	00000000 */ 	nop
.L00039fa4:
/*    39fa4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    39fa8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    39fac:	03e00008 */ 	jr	$ra
/*    39fb0:	00000000 */ 	nop
/*    39fb4:	00000000 */ 	nop
/*    39fb8:	00000000 */ 	nop
/*    39fbc:	00000000 */ 	nop
);