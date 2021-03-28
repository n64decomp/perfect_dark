#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_39fc0.h"
#include "data.h"
#include "types.h"

ALGlobals *var8005f110 = NULL;
ALGlobals *alGlobals = NULL;
u32 var8005f118 = 0;
u32 var8005f11c = 0;

void n_alInit(ALGlobals *g, ALSynConfig *c)
{
	if (!var8005f110) {
		var8005f110 = g;

		if (!alGlobals) {
			alGlobals = var8005f110;
			n_alSynNew(c);
		}
	}
}

GLOBAL_ASM(
glabel alClose
/*    2fc0c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    2fc10:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    2fc14:	afa40018 */ 	sw	$a0,0x18($sp)
/*    2fc18:	3c0e8006 */ 	lui	$t6,%hi(var8005f110)
/*    2fc1c:	8dcef110 */ 	lw	$t6,%lo(var8005f110)($t6)
/*    2fc20:	11c00007 */ 	beqz	$t6,.L0002fc40
/*    2fc24:	00000000 */ 	nop
/*    2fc28:	0c00e7f0 */ 	jal	func00039fc0
/*    2fc2c:	00000000 */ 	nop
/*    2fc30:	3c018006 */ 	lui	$at,%hi(var8005f110)
/*    2fc34:	ac20f110 */ 	sw	$zero,%lo(var8005f110)($at)
/*    2fc38:	3c018006 */ 	lui	$at,%hi(alGlobals)
/*    2fc3c:	ac20f114 */ 	sw	$zero,%lo(alGlobals)($at)
.L0002fc40:
/*    2fc40:	10000001 */ 	b	.L0002fc48
/*    2fc44:	00000000 */ 	nop
.L0002fc48:
/*    2fc48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    2fc4c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    2fc50:	03e00008 */ 	jr	$ra
/*    2fc54:	00000000 */ 	nop
);
