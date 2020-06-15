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
#include "lib/lib_09660.h"
#include "lib/lib_4b480.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f01afc0
/*  f01afc0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f01afc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f01afc8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f01afcc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f01afd0:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f01afd4:	3c0f0030 */ 	lui	$t7,0x30
/*  f01afd8:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f01afdc:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f01afe0:	24900008 */ 	addiu	$s0,$a0,0x8
/*  f01afe4:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f01afe8:	0c002f02 */ 	jal	func0000bc08
/*  f01afec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f01aff0:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f01aff4:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f01aff8:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f01affc:	3c01ff10 */ 	lui	$at,0xff10
/*  f01b000:	03214025 */ 	or	$t0,$t9,$at
/*  f01b004:	0c002ac7 */ 	jal	viGetUnk28
/*  f01b008:	ad280000 */ 	sw	$t0,0x0($t1)
/*  f01b00c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f01b010:	00402025 */ 	or	$a0,$v0,$zero
/*  f01b014:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f01b018:	02001825 */ 	or	$v1,$s0,$zero
/*  f01b01c:	3c0c0001 */ 	lui	$t4,0x1
/*  f01b020:	ad420004 */ 	sw	$v0,0x4($t2)
/*  f01b024:	358c0001 */ 	ori	$t4,$t4,0x1
/*  f01b028:	3c0bf700 */ 	lui	$t3,0xf700
/*  f01b02c:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f01b030:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f01b034:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f01b038:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f01b03c:	0c002f02 */ 	jal	func0000bc08
/*  f01b040:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f01b044:	0c002f06 */ 	jal	func0000bc18
/*  f01b048:	a7a20022 */ 	sh	$v0,0x22($sp)
/*  f01b04c:	87b90022 */ 	lh	$t9,0x22($sp)
/*  f01b050:	244dffff */ 	addiu	$t5,$v0,-1
/*  f01b054:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f01b058:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f01b05c:	2728ffff */ 	addiu	$t0,$t9,-1
/*  f01b060:	310903ff */ 	andi	$t1,$t0,0x3ff
/*  f01b064:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f01b068:	3c01f600 */ 	lui	$at,0xf600
/*  f01b06c:	01e1c025 */ 	or	$t8,$t7,$at
/*  f01b070:	00095380 */ 	sll	$t2,$t1,0xe
/*  f01b074:	030a5825 */ 	or	$t3,$t8,$t2
/*  f01b078:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f01b07c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f01b080:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f01b084:	02001025 */ 	or	$v0,$s0,$zero
/*  f01b088:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f01b08c:	03e00008 */ 	jr	$ra
/*  f01b090:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f01b094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b09c:	00000000 */ 	sll	$zero,$zero,0x0
);
