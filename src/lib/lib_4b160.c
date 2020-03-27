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
glabel __osGetCause
/*    4b160:	40026800 */ 	mfc0	$v0,$13
/*    4b164:	03e00008 */ 	jr	$ra
/*    4b168:	00000000 */ 	sll	$zero,$zero,0x0
/*    4b16c:	00000000 */ 	sll	$zero,$zero,0x0
);