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
glabel osViSwapBuffer
/*    490b0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    490b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    490b8:	0c01256c */ 	jal	__osDisableInt
/*    490bc:	afa40020 */ 	sw	$a0,0x20($sp)
/*    490c0:	3c0f8006 */ 	lui	$t7,%hi(__osViNext)
/*    490c4:	8def0914 */ 	lw	$t7,%lo(__osViNext)($t7)
/*    490c8:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    490cc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    490d0:	3c188006 */ 	lui	$t8,%hi(__osViNext)
/*    490d4:	adee0004 */ 	sw	$t6,0x4($t7)
/*    490d8:	8f180914 */ 	lw	$t8,%lo(__osViNext)($t8)
/*    490dc:	97190000 */ 	lhu	$t9,0x0($t8)
/*    490e0:	37280010 */ 	ori	$t0,$t9,0x10
/*    490e4:	a7080000 */ 	sh	$t0,0x0($t8)
/*    490e8:	0c012588 */ 	jal	__osRestoreInt
/*    490ec:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    490f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    490f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    490f8:	03e00008 */ 	jr	$ra
/*    490fc:	00000000 */ 	nop
);
