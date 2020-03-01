#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_4b480.h"
#include "lib/lib_4b5e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004b550
/*    4b550:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4b554:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4b558:	afa40018 */ 	sw	$a0,0x18($sp)
/*    4b55c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    4b560:	afa60020 */ 	sw	$a2,0x20($sp)
/*    4b564:	0c012d78 */ 	jal	func0004b5e0
/*    4b568:	afa70024 */ 	sw	$a3,0x24($sp)
/*    4b56c:	10400003 */ 	beqz	$v0,.L0004b57c
/*    4b570:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    4b574:	10000013 */ 	beqz	$zero,.L0004b5c4
/*    4b578:	2402ffff */ 	addiu	$v0,$zero,-1
.L0004b57c:
/*    4b57c:	3c0fa404 */ 	lui	$t7,0xa404
/*    4b580:	adee0000 */ 	sw	$t6,0x0($t7)
/*    4b584:	0c012d20 */ 	jal	osVirtualToPhysical
/*    4b588:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    4b58c:	3c18a404 */ 	lui	$t8,0xa404
/*    4b590:	af020004 */ 	sw	$v0,0x4($t8)
/*    4b594:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    4b598:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    4b59c:	00001025 */ 	or	$v0,$zero,$zero
/*    4b5a0:	17200006 */ 	bnez	$t9,.L0004b5bc
/*    4b5a4:	256cffff */ 	addiu	$t4,$t3,-1
/*    4b5a8:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    4b5ac:	3c0aa404 */ 	lui	$t2,0xa404
/*    4b5b0:	2509ffff */ 	addiu	$t1,$t0,-1
/*    4b5b4:	10000003 */ 	beqz	$zero,.L0004b5c4
/*    4b5b8:	ad49000c */ 	sw	$t1,0xc($t2)
.L0004b5bc:
/*    4b5bc:	3c0da404 */ 	lui	$t5,0xa404
/*    4b5c0:	adac0008 */ 	sw	$t4,0x8($t5)
.L0004b5c4:
/*    4b5c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4b5c8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4b5cc:	03e00008 */ 	jr	$ra
/*    4b5d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b5d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b5d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b5dc:	00000000 */ 	sll	$zero,$zero,0x0
);