#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_121e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f00b190
/*  f00b190:	3c0e0200 */ 	lui	$t6,0x200
/*  f00b194:	3c0f01ff */ 	lui	$t7,0x1ff
/*  f00b198:	25ef7ca0 */ 	addiu	$t7,$t7,0x7ca0
/*  f00b19c:	25ceea20 */ 	addiu	$t6,$t6,-5600
/*  f00b1a0:	01cf3023 */ 	subu	$a2,$t6,$t7
/*  f00b1a4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f00b1a8:	24c6000f */ 	addiu	$a2,$a2,0xf
/*  f00b1ac:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f00b1b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00b1b4:	00c12024 */ 	and	$a0,$a2,$at
/*  f00b1b8:	00803025 */ 	or	$a2,$a0,$zero
/*  f00b1bc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f00b1c0:	0c0048f2 */ 	jal	malloc
/*  f00b1c4:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f00b1c8:	3c03800b */ 	lui	$v1,%hi(var800aabc0)
/*  f00b1cc:	2463abc0 */ 	addiu	$v1,$v1,%lo(var800aabc0)
/*  f00b1d0:	3c0501ff */ 	lui	$a1,0x1ff
/*  f00b1d4:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f00b1d8:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f00b1dc:	24a57ca0 */ 	addiu	$a1,$a1,0x7ca0
/*  f00b1e0:	0c003504 */ 	jal	func0000d410
/*  f00b1e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b1e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00b1ec:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f00b1f0:	03e00008 */ 	jr	$ra
/*  f00b1f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b1f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b1fc:	00000000 */ 	sll	$zero,$zero,0x0
);
