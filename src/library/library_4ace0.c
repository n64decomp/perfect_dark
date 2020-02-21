#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_51c60.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004ace0
/*    4ace0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4ace4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4ace8:	afa40018 */ 	sw	$a0,0x18($sp)
/*    4acec:	0c014718 */ 	jal	func00051c60
/*    4acf0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    4acf4:	10400003 */ 	beqz	$v0,.L0004ad04
/*    4acf8:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    4acfc:	10000007 */ 	beqz	$zero,.L0004ad1c
/*    4ad00:	2402ffff */ 	addiu	$v0,$zero,-1
.L0004ad04:
/*    4ad04:	3c01a000 */ 	lui	$at,0xa000
/*    4ad08:	01c17825 */ 	or	$t7,$t6,$at
/*    4ad0c:	8df80000 */ 	lw	$t8,0x0($t7)
/*    4ad10:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    4ad14:	00001025 */ 	or	$v0,$zero,$zero
/*    4ad18:	af380000 */ 	sw	$t8,0x0($t9)
.L0004ad1c:
/*    4ad1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4ad20:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4ad24:	03e00008 */ 	jr	$ra
/*    4ad28:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ad2c:	00000000 */ 	sll	$zero,$zero,0x0
);