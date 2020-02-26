#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_491b0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00048cd0
/*    48cd0:	3c0ea410 */ 	lui	$t6,0xa410
/*    48cd4:	03e00008 */ 	jr	$ra
/*    48cd8:	8dc2000c */ 	lw	$v0,0xc($t6)
/*    48cdc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00048ce0
/*    48ce0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    48ce4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48ce8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    48cec:	0c01256c */ 	jal	func000495b0
/*    48cf0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48cf4:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*    48cf8:	00408025 */ 	or	$s0,$v0,$zero
/*    48cfc:	11c00007 */ 	beqz	$t6,.L00048d1c
/*    48d00:	00000000 */ 	sll	$zero,$zero,0x0
/*    48d04:	3c0f8006 */ 	lui	$t7,0x8006
/*    48d08:	8def0914 */ 	lw	$t7,0x914($t7)
/*    48d0c:	95f80000 */ 	lhu	$t8,0x0($t7)
/*    48d10:	37190020 */ 	ori	$t9,$t8,0x20
/*    48d14:	10000007 */ 	beqz	$zero,.L00048d34
/*    48d18:	a5f90000 */ 	sh	$t9,0x0($t7)
.L00048d1c:
/*    48d1c:	3c088006 */ 	lui	$t0,0x8006
/*    48d20:	8d080914 */ 	lw	$t0,0x914($t0)
/*    48d24:	2401ffdf */ 	addiu	$at,$zero,-33
/*    48d28:	95090000 */ 	lhu	$t1,0x0($t0)
/*    48d2c:	01215024 */ 	and	$t2,$t1,$at
/*    48d30:	a50a0000 */ 	sh	$t2,0x0($t0)
.L00048d34:
/*    48d34:	0c012588 */ 	jal	func00049620
/*    48d38:	02002025 */ 	or	$a0,$s0,$zero
/*    48d3c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48d40:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48d44:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    48d48:	03e00008 */ 	jr	$ra
/*    48d4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00048d50
/*    48d50:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    48d54:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48d58:	afa40028 */ 	sw	$a0,0x28($sp)
/*    48d5c:	0c01256c */ 	jal	func000495b0
/*    48d60:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48d64:	3c0f8006 */ 	lui	$t7,0x8006
/*    48d68:	8def0914 */ 	lw	$t7,0x914($t7)
/*    48d6c:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    48d70:	3c198006 */ 	lui	$t9,0x8006
/*    48d74:	24180001 */ 	addiu	$t8,$zero,0x1
/*    48d78:	adee0008 */ 	sw	$t6,0x8($t7)
/*    48d7c:	8f390914 */ 	lw	$t9,0x914($t9)
/*    48d80:	3c088006 */ 	lui	$t0,0x8006
/*    48d84:	00408025 */ 	or	$s0,$v0,$zero
/*    48d88:	a7380000 */ 	sh	$t8,0x0($t9)
/*    48d8c:	8d080914 */ 	lw	$t0,0x914($t0)
/*    48d90:	02002025 */ 	or	$a0,$s0,$zero
/*    48d94:	8d090008 */ 	lw	$t1,0x8($t0)
/*    48d98:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    48d9c:	0c012588 */ 	jal	func00049620
/*    48da0:	ad0a000c */ 	sw	$t2,0xc($t0)
/*    48da4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48da8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48dac:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    48db0:	03e00008 */ 	jr	$ra
/*    48db4:	00000000 */ 	sll	$zero,$zero,0x0
/*    48db8:	00000000 */ 	sll	$zero,$zero,0x0
/*    48dbc:	00000000 */ 	sll	$zero,$zero,0x0
);