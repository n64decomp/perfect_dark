#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"
GLOBAL_ASM(
glabel func0f0147a0
/*  f0147a0:	3c01800a */ 	lui	$at,0x800a
/*  f0147a4:	ac2433a0 */ 	sw	$a0,0x33a0($at)
/*  f0147a8:	3c01800a */ 	lui	$at,0x800a
/*  f0147ac:	ac2033a4 */ 	sw	$zero,0x33a4($at)
/*  f0147b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0147b4:	44812000 */ 	mtc1	$at,$f4
/*  f0147b8:	3c018008 */ 	lui	$at,0x8008
/*  f0147bc:	03e00008 */ 	jr	$ra
/*  f0147c0:	e424db84 */ 	swc1	$f4,-0x247c($at)
/*  f0147c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0147c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0147cc:	00000000 */ 	sll	$zero,$zero,0x0
);