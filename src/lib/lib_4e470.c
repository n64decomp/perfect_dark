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
glabel osAiGetLength
/*    4e470:	3c0ea450 */ 	lui	$t6,0xa450
/*    4e474:	03e00008 */ 	jr	$ra
/*    4e478:	8dc20004 */ 	lw	$v0,0x4($t6)
/*    4e47c:	00000000 */ 	nop
);
