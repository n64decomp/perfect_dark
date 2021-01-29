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
glabel func00048cd0
/*    48cd0:	3c0ea410 */ 	lui	$t6,0xa410
/*    48cd4:	03e00008 */ 	jr	$ra
/*    48cd8:	8dc2000c */ 	lw	$v0,0xc($t6)
/*    48cdc:	00000000 */ 	nop
);
