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
glabel func00049780
/*    49780:	3c028006 */ 	lui	$v0,%hi(__osViCurr)
/*    49784:	03e00008 */ 	jr	$ra
/*    49788:	8c420910 */ 	lw	$v0,%lo(__osViCurr)($v0)
/*    4978c:	00000000 */ 	nop
);
