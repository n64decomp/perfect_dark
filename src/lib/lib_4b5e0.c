#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_4b170.h"
#include "lib/lib_51d50.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004b5e0
/*    4b5e0:	3c0ea404 */ 	lui	$t6,0xa404
/*    4b5e4:	8dc40010 */ 	lw	$a0,0x10($t6)
/*    4b5e8:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    4b5ec:	308f001c */ 	andi	$t7,$a0,0x1c
/*    4b5f0:	11e00003 */ 	beqz	$t7,.L0004b600
/*    4b5f4:	00000000 */ 	nop
/*    4b5f8:	10000002 */ 	b	.L0004b604
/*    4b5fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0004b600:
/*    4b600:	00001025 */ 	or	$v0,$zero,$zero
.L0004b604:
/*    4b604:	03e00008 */ 	jr	$ra
/*    4b608:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*    4b60c:	00000000 */ 	nop
);
