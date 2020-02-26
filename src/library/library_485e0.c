#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_491b0.h"
#include "types.h"

GLOBAL_ASM(
glabel func000485e0
/*    485e0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    485e4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    485e8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    485ec:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    485f0:	afa60030 */ 	sw	$a2,0x30($sp)
/*    485f4:	0c01256c */ 	jal	func000495b0
/*    485f8:	afb00018 */ 	sw	$s0,0x18($sp)
/*    485fc:	3c0f8006 */ 	lui	$t7,0x8006
/*    48600:	8def0914 */ 	lw	$t7,0x914($t7)
/*    48604:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    48608:	3c198006 */ 	lui	$t9,0x8006
/*    4860c:	3c098006 */ 	lui	$t1,0x8006
/*    48610:	adee0010 */ 	sw	$t6,0x10($t7)
/*    48614:	8f390914 */ 	lw	$t9,0x914($t9)
/*    48618:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    4861c:	00408025 */ 	or	$s0,$v0,$zero
/*    48620:	02002025 */ 	or	$a0,$s0,$zero
/*    48624:	af380014 */ 	sw	$t8,0x14($t9)
/*    48628:	8d290914 */ 	lw	$t1,0x914($t1)
/*    4862c:	8fa80030 */ 	lw	$t0,0x30($sp)
/*    48630:	0c012588 */ 	jal	func00049620
/*    48634:	a5280002 */ 	sh	$t0,0x2($t1)
/*    48638:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4863c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48640:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    48644:	03e00008 */ 	jr	$ra
/*    48648:	00000000 */ 	sll	$zero,$zero,0x0
/*    4864c:	00000000 */ 	sll	$zero,$zero,0x0
);