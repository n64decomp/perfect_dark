#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_000130.h"
#include "library/library.h"

GLOBAL_ASM(
glabel func0f000090
/*  f000090:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f000094:	3c018006 */ 	lui	$at,0x8006
/*  f000098:	ac2224b4 */ 	sw	$v0,0x24b4($at)
/*  f00009c:	3c018006 */ 	lui	$at,0x8006
/*  f0000a0:	ac2024b8 */ 	sw	$zero,0x24b8($at)
/*  f0000a4:	3c018006 */ 	lui	$at,0x8006
/*  f0000a8:	ac2024c4 */ 	sw	$zero,0x24c4($at)
/*  f0000ac:	3c018006 */ 	lui	$at,0x8006
/*  f0000b0:	ac2224e4 */ 	sw	$v0,0x24e4($at)
/*  f0000b4:	3c018006 */ 	lui	$at,0x8006
/*  f0000b8:	ac2024e0 */ 	sw	$zero,0x24e0($at)
/*  f0000bc:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0000c0:	3c018006 */ 	lui	$at,0x8006
/*  f0000c4:	ac2324e8 */ 	sw	$v1,0x24e8($at)
/*  f0000c8:	3c018006 */ 	lui	$at,0x8006
/*  f0000cc:	ac2024ec */ 	sw	$zero,0x24ec($at)
/*  f0000d0:	3c018006 */ 	lui	$at,0x8006
/*  f0000d4:	ac2024f0 */ 	sw	$zero,0x24f0($at)
/*  f0000d8:	3c04800a */ 	lui	$a0,%hi(var8009dfe8)
/*  f0000dc:	3c018006 */ 	lui	$at,0x8006
/*  f0000e0:	2484dfe8 */ 	addiu	$a0,$a0,%lo(var8009dfe8)
/*  f0000e4:	ac2324f4 */ 	sw	$v1,0x24f4($at)
/*  f0000e8:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f0000ec:	a0800004 */ 	sb	$zero,0x4($a0)
/*  f0000f0:	a0850005 */ 	sb	$a1,0x5($a0)
/*  f0000f4:	a0850006 */ 	sb	$a1,0x6($a0)
/*  f0000f8:	03e00008 */ 	jr	$ra
/*  f0000fc:	a0850007 */ 	sb	$a1,0x7($a0)
);

GLOBAL_ASM(
glabel func0f000100
/*  f000100:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f000104:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f000108:	3c047f02 */ 	lui	$a0,0x7f02
/*  f00010c:	0c006946 */ 	jal	func0001a518
/*  f000110:	2484e760 */ 	addiu	$a0,$a0,-6304
/*  f000114:	0fc00192 */ 	jal	func0f000648
/*  f000118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00011c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f000120:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f000124:	03e00008 */ 	jr	$ra
/*  f000128:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00012c:	00000000 */ 	sll	$zero,$zero,0x0
);