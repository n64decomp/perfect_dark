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
glabel __osSetSR
/*    4acc0:	40846000 */ 	mtc0	$a0,$12
/*    4acc4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4acc8:	03e00008 */ 	jr	$ra
/*    4accc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel __osGetSR
/*    4acd0:	40026000 */ 	mfc0	$v0,$12
/*    4acd4:	03e00008 */ 	jr	$ra
/*    4acd8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4acdc:	00000000 */ 	sll	$zero,$zero,0x0
);