#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f013260
/*  f013260:	3c01800a */ 	lui	$at,0x800a
/*  f013264:	3c03800a */ 	lui	$v1,%hi(var800a3fc8)
/*  f013268:	3c02800a */ 	lui	$v0,%hi(var800a4130)
/*  f01326c:	ac203fc0 */ 	sw	$zero,0x3fc0($at)
/*  f013270:	24424130 */ 	addiu	$v0,$v0,%lo(var800a4130)
/*  f013274:	24633fc8 */ 	addiu	$v1,$v1,%lo(var800a3fc8)
.L0f013278:
/*  f013278:	24630024 */ 	addiu	$v1,$v1,0x24
/*  f01327c:	1462fffe */ 	bne	$v1,$v0,.L0f013278
/*  f013280:	ac60ffe4 */ 	sw	$zero,-0x1c($v1)
/*  f013284:	3c01800a */ 	lui	$at,0x800a
/*  f013288:	ac204130 */ 	sw	$zero,0x4130($at)
/*  f01328c:	3c018008 */ 	lui	$at,0x8008
/*  f013290:	03e00008 */ 	jr	$ra
/*  f013294:	ac20f0b8 */ 	sw	$zero,-0xf48($at)
/*  f013298:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01329c:	00000000 */ 	sll	$zero,$zero,0x0
);
