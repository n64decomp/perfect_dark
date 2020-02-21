#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

/**
 * Iterates an array of structs and sets their unk04 value to 0.
 * The array is stored at 800a45c4 and each struct is 0x6c long.
 */
GLOBAL_ASM(
glabel func0f015420
/*  f015420:	3c04800a */ 	lui	$a0,%hi(var800a45c0)
/*  f015424:	248445c0 */ 	addiu	$a0,$a0,%lo(var800a45c0)
/*  f015428:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f01542c:	00001025 */ 	or	$v0,$zero,$zero
/*  f015430:	00001825 */ 	or	$v1,$zero,$zero
/*  f015434:	19c0000b */ 	blez	$t6,.L0f015464
/*  f015438:	3c05800a */ 	lui	$a1,%hi(var800a45c4)
/*  f01543c:	24a545c4 */ 	addiu	$a1,$a1,%lo(var800a45c4)
/*  f015440:	8caf0000 */ 	lw	$t7,0x0($a1)
.L0f015444:
/*  f015444:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f015448:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f01544c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f015450:	8c990000 */ 	lw	$t9,0x0($a0)
/*  f015454:	2463006c */ 	addiu	$v1,$v1,0x6c
/*  f015458:	0059082a */ 	slt	$at,$v0,$t9
/*  f01545c:	5420fff9 */ 	bnezl	$at,.L0f015444
/*  f015460:	8caf0000 */ 	lw	$t7,0x0($a1)
.L0f015464:
/*  f015464:	03e00008 */ 	jr	$ra
/*  f015468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01546c:	00000000 */ 	sll	$zero,$zero,0x0
);
