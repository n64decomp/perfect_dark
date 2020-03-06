#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_39fc0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0002fba0
/*    2fba0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    2fba4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    2fba8:	afa40018 */ 	sw	$a0,0x18($sp)
/*    2fbac:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    2fbb0:	3c0e8006 */ 	lui	$t6,%hi(var8005f110)
/*    2fbb4:	8dcef110 */ 	lw	$t6,%lo(var8005f110)($t6)
/*    2fbb8:	15c0000e */ 	bnez	$t6,.L0002fbf4
/*    2fbbc:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fbc0:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    2fbc4:	3c018006 */ 	lui	$at,0x8006
/*    2fbc8:	ac2ff110 */ 	sw	$t7,-0xef0($at)
/*    2fbcc:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    2fbd0:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    2fbd4:	17000007 */ 	bnez	$t8,.L0002fbf4
/*    2fbd8:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fbdc:	3c198006 */ 	lui	$t9,%hi(var8005f110)
/*    2fbe0:	8f39f110 */ 	lw	$t9,%lo(var8005f110)($t9)
/*    2fbe4:	3c018006 */ 	lui	$at,0x8006
/*    2fbe8:	ac39f114 */ 	sw	$t9,-0xeec($at)
/*    2fbec:	0c00c338 */ 	jal	func00030ce0
/*    2fbf0:	8fa4001c */ 	lw	$a0,0x1c($sp)
.L0002fbf4:
/*    2fbf4:	10000001 */ 	beqz	$zero,.L0002fbfc
/*    2fbf8:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fbfc:
/*    2fbfc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    2fc00:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    2fc04:	03e00008 */ 	jr	$ra
/*    2fc08:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0002fc0c
/*    2fc0c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    2fc10:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    2fc14:	afa40018 */ 	sw	$a0,0x18($sp)
/*    2fc18:	3c0e8006 */ 	lui	$t6,%hi(var8005f110)
/*    2fc1c:	8dcef110 */ 	lw	$t6,%lo(var8005f110)($t6)
/*    2fc20:	11c00007 */ 	beqz	$t6,.L0002fc40
/*    2fc24:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fc28:	0c00e7f0 */ 	jal	func00039fc0
/*    2fc2c:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fc30:	3c018006 */ 	lui	$at,0x8006
/*    2fc34:	ac20f110 */ 	sw	$zero,-0xef0($at)
/*    2fc38:	3c018006 */ 	lui	$at,0x8006
/*    2fc3c:	ac20f114 */ 	sw	$zero,-0xeec($at)
.L0002fc40:
/*    2fc40:	10000001 */ 	beqz	$zero,.L0002fc48
/*    2fc44:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fc48:
/*    2fc48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    2fc4c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    2fc50:	03e00008 */ 	jr	$ra
/*    2fc54:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fc58:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fc5c:	00000000 */ 	sll	$zero,$zero,0x0
);