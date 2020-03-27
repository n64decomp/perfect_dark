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
#include "types.h"

GLOBAL_ASM(
glabel func0004b500
/*    4b500:	3c0ea404 */ 	lui	$t6,0xa404
/*    4b504:	03e00008 */ 	jr	$ra
/*    4b508:	adc40010 */ 	sw	$a0,0x10($t6)
/*    4b50c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004b510
/*    4b510:	3c0ea404 */ 	lui	$t6,0xa404
/*    4b514:	8dc50010 */ 	lw	$a1,0x10($t6)
/*    4b518:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    4b51c:	30af0001 */ 	andi	$t7,$a1,0x1
/*    4b520:	15e00003 */ 	bnez	$t7,.L0004b530
/*    4b524:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b528:	10000004 */ 	beqz	$zero,.L0004b53c
/*    4b52c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0004b530:
/*    4b530:	3c18a408 */ 	lui	$t8,0xa408
/*    4b534:	af040000 */ 	sw	$a0,0x0($t8)
/*    4b538:	00001025 */ 	or	$v0,$zero,$zero
.L0004b53c:
/*    4b53c:	03e00008 */ 	jr	$ra
/*    4b540:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*    4b544:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b548:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b54c:	00000000 */ 	sll	$zero,$zero,0x0
);