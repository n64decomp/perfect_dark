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
glabel func00038d10
/*    38d10:	03e00008 */ 	jr	$ra
/*    38d14:	8c82002c */ 	lw	$v0,0x2c($a0)
/*    38d18:	03e00008 */ 	jr	$ra
/*    38d1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    38d20:	03e00008 */ 	jr	$ra
/*    38d24:	00000000 */ 	sll	$zero,$zero,0x0
/*    38d28:	00000000 */ 	sll	$zero,$zero,0x0
/*    38d2c:	00000000 */ 	sll	$zero,$zero,0x0
);