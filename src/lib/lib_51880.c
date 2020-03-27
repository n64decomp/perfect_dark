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
glabel __osSetCompare
/*    51880:	40845800 */ 	mtc0	$a0,$11
/*    51884:	03e00008 */ 	jr	$ra
/*    51888:	00000000 */ 	sll	$zero,$zero,0x0
/*    5188c:	00000000 */ 	sll	$zero,$zero,0x0
);