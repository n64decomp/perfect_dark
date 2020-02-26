#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f01d990
/*  f01d990:	3c014580 */ 	lui	$at,0x4580
/*  f01d994:	44811000 */ 	mtc1	$at,$f2
/*  f01d998:	3c01800a */ 	lui	$at,0x800a
/*  f01d99c:	c424a00c */ 	lwc1	$f4,-0x5ff4($at)
/*  f01d9a0:	3c018008 */ 	lui	$at,0x8008
/*  f01d9a4:	c426db84 */ 	lwc1	$f6,-0x247c($at)
/*  f01d9a8:	3c028008 */ 	lui	$v0,%hi(var8007db80)
/*  f01d9ac:	2442db80 */ 	addiu	$v0,$v0,%lo(var8007db80)
/*  f01d9b0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f01d9b4:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f01d9b8:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f01d9bc:	e4500000 */ 	swc1	$f16,0x0($v0)
/*  f01d9c0:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f01d9c4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f01d9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d9cc:	45000003 */ 	bc1f	.L0f01d9dc
/*  f01d9d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d9d4:	46020481 */ 	sub.s	$f18,$f0,$f2
/*  f01d9d8:	e4520000 */ 	swc1	$f18,0x0($v0)
.L0f01d9dc:
/*  f01d9dc:	03e00008 */ 	jr	$ra
/*  f01d9e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d9e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d9e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d9ec:	00000000 */ 	sll	$zero,$zero,0x0
);
