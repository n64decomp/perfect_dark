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
#include "lib/lib_4a360.h"
#include "types.h"

GLOBAL_ASM(
glabel sqrtf
/*    4a5d0:	03e00008 */ 	jr	$ra
/*    4a5d4:	46006004 */ 	sqrt.s	$f0,$f12
/*    4a5d8:	00000000 */ 	nop
/*    4a5dc:	00000000 */ 	nop
);
