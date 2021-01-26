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
glabel osViGetCurrentFramebuffer
/*    48830:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    48834:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48838:	0c01256c */ 	jal	__osDisableInt
/*    4883c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48840:	3c0e8006 */ 	lui	$t6,%hi(var80060910)
/*    48844:	8dce0910 */ 	lw	$t6,%lo(var80060910)($t6)
/*    48848:	00408025 */ 	or	$s0,$v0,$zero
/*    4884c:	02002025 */ 	or	$a0,$s0,$zero
/*    48850:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*    48854:	0c012588 */ 	jal	__osRestoreInt
/*    48858:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    4885c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48860:	8fa20020 */ 	lw	$v0,0x20($sp)
/*    48864:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48868:	03e00008 */ 	jr	$ra
/*    4886c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
