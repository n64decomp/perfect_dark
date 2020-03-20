#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_491b0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00051890
/*    51890:	3c0ea404 */ 	lui	$t6,0xa404
/*    51894:	03e00008 */ 	jr	$ra
/*    51898:	8dc20010 */ 	lw	$v0,0x10($t6)
/*    5189c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000518a0
/*    518a0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    518a4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    518a8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    518ac:	0c01256c */ 	jal	__osDisableInt
/*    518b0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    518b4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    518b8:	3c0e8006 */ 	lui	$t6,%hi(var8005cf70)
/*    518bc:	8dcecf70 */ 	lw	$t6,%lo(var8005cf70)($t6)
/*    518c0:	2401fbfe */ 	addiu	$at,$zero,-1026
/*    518c4:	01e1c024 */ 	and	$t8,$t7,$at
/*    518c8:	0300c827 */ 	nor	$t9,$t8,$zero
/*    518cc:	00408025 */ 	or	$s0,$v0,$zero
/*    518d0:	3c018006 */ 	lui	$at,%hi(var8005cf70)
/*    518d4:	01d94024 */ 	and	$t0,$t6,$t9
/*    518d8:	ac28cf70 */ 	sw	$t0,%lo(var8005cf70)($at)
/*    518dc:	0c012588 */ 	jal	__osRestoreInt
/*    518e0:	02002025 */ 	or	$a0,$s0,$zero
/*    518e4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    518e8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    518ec:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    518f0:	03e00008 */ 	jr	$ra
/*    518f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    518f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    518fc:	00000000 */ 	sll	$zero,$zero,0x0
);