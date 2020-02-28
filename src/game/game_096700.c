#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f096700
/*  f096700:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f096704:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f096708:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f09670c:	0c0068f7 */ 	jal	func0001a3dc
/*  f096710:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*  f096714:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f096718:	0c0068f4 */ 	jal	func0001a3d0
/*  f09671c:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*  f096720:	c7a40018 */ 	lwc1	$f4,0x18($sp)
/*  f096724:	3c013f80 */ 	lui	$at,0x3f80
/*  f096728:	44814000 */ 	mtc1	$at,$f8
/*  f09672c:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f096730:	0c012974 */ 	jal	sqrtf
/*  f096734:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f096738:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09673c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f096740:	03e00008 */ 	jr	$ra
/*  f096744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096748:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09674c:	00000000 */ 	sll	$zero,$zero,0x0
);
