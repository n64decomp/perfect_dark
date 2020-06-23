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
#include "lib/lib_51c60.h"
#include "types.h"

GLOBAL_ASM(
glabel osVirtualToPhysical
/*    4b480:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4b484:	afa40018 */ 	sw	$a0,0x18($sp)
/*    4b488:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    4b48c:	3c018000 */ 	lui	$at,0x8000
/*    4b490:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4b494:	01c1082b */ 	sltu	$at,$t6,$at
/*    4b498:	14200007 */ 	bnez	$at,.L0004b4b8
/*    4b49c:	3c01a000 */ 	lui	$at,0xa000
/*    4b4a0:	01c1082b */ 	sltu	$at,$t6,$at
/*    4b4a4:	10200004 */ 	beqz	$at,.L0004b4b8
/*    4b4a8:	3c011fff */ 	lui	$at,0x1fff
/*    4b4ac:	3421ffff */ 	ori	$at,$at,0xffff
/*    4b4b0:	1000000e */ 	b	.L0004b4ec
/*    4b4b4:	01c11024 */ 	and	$v0,$t6,$at
.L0004b4b8:
/*    4b4b8:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    4b4bc:	3c01a000 */ 	lui	$at,0xa000
/*    4b4c0:	01e1082b */ 	sltu	$at,$t7,$at
/*    4b4c4:	14200007 */ 	bnez	$at,.L0004b4e4
/*    4b4c8:	3c01c000 */ 	lui	$at,0xc000
/*    4b4cc:	01e1082b */ 	sltu	$at,$t7,$at
/*    4b4d0:	10200004 */ 	beqz	$at,.L0004b4e4
/*    4b4d4:	3c011fff */ 	lui	$at,0x1fff
/*    4b4d8:	3421ffff */ 	ori	$at,$at,0xffff
/*    4b4dc:	10000003 */ 	b	.L0004b4ec
/*    4b4e0:	01e11024 */ 	and	$v0,$t7,$at
.L0004b4e4:
/*    4b4e4:	0c014724 */ 	jal	__osProbeTLB
/*    4b4e8:	8fa40018 */ 	lw	$a0,0x18($sp)
.L0004b4ec:
/*    4b4ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4b4f0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4b4f4:	03e00008 */ 	jr	$ra
/*    4b4f8:	00000000 */ 	nop
/*    4b4fc:	00000000 */ 	nop
);