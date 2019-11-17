#include <ultra64.h>
#include "types.h"
#include "library/library_4a360.h"
#include "library/library_50090.h"

GLOBAL_ASM(
glabel func00050090
/*    50090:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    50094:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    50098:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    5009c:	afa60020 */ 	sw	$a2,0x20($sp)
/*    500a0:	afa70024 */ 	sw	$a3,0x24($sp)
/*    500a4:	0c012918 */ 	jal	func0004a460
/*    500a8:	afa40018 */ 	sw	$a0,0x18($sp)
/*    500ac:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    500b0:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*    500b4:	3c013f80 */ 	lui	$at,0x3f80
/*    500b8:	44815000 */ 	mtc1	$at,$f10
/*    500bc:	e4840000 */ 	swc1	$f4,0x0($a0)
/*    500c0:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    500c4:	e4860014 */ 	swc1	$f6,0x14($a0)
/*    500c8:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*    500cc:	e48a003c */ 	swc1	$f10,0x3c($a0)
/*    500d0:	e4880028 */ 	swc1	$f8,0x28($a0)
/*    500d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    500d8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    500dc:	03e00008 */ 	jr	$ra
/*    500e0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000500e4
/*    500e4:	44856000 */ 	mtc1	$a1,$f12
/*    500e8:	44867000 */ 	mtc1	$a2,$f14
/*    500ec:	44878000 */ 	mtc1	$a3,$f16
/*    500f0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    500f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    500f8:	afa40058 */ 	sw	$a0,0x58($sp)
/*    500fc:	44056000 */ 	mfc1	$a1,$f12
/*    50100:	44067000 */ 	mfc1	$a2,$f14
/*    50104:	44078000 */ 	mfc1	$a3,$f16
/*    50108:	0c014024 */ 	jal	func00050090
/*    5010c:	27a40018 */ 	addiu	$a0,$sp,0x18
/*    50110:	27a40018 */ 	addiu	$a0,$sp,0x18
/*    50114:	0c0128d8 */ 	jal	func0004a360
/*    50118:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    5011c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    50120:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*    50124:	03e00008 */ 	jr	$ra
/*    50128:	00000000 */ 	sll	$zero,$zero,0x0
/*    5012c:	00000000 */ 	sll	$zero,$zero,0x0
);