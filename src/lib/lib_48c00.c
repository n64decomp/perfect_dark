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
#include "lib/lib_51890.h"
#include "types.h"

GLOBAL_ASM(
glabel osSpTaskYielded
/*    48c00:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    48c04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    48c08:	0c014624 */ 	jal	func00051890
/*    48c0c:	afa40020 */ 	sw	$a0,0x20($sp)
/*    48c10:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    48c14:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    48c18:	31cf0100 */ 	andi	$t7,$t6,0x100
/*    48c1c:	11e00004 */ 	beqz	$t7,.L00048c30
/*    48c20:	00000000 */ 	nop
/*    48c24:	24180001 */ 	addiu	$t8,$zero,0x1
/*    48c28:	10000002 */ 	b	.L00048c34
/*    48c2c:	afb80018 */ 	sw	$t8,0x18($sp)
.L00048c30:
/*    48c30:	afa00018 */ 	sw	$zero,0x18($sp)
.L00048c34:
/*    48c34:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    48c38:	33280080 */ 	andi	$t0,$t9,0x80
/*    48c3c:	1100000b */ 	beqz	$t0,.L00048c6c
/*    48c40:	00000000 */ 	nop
/*    48c44:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    48c48:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    48c4c:	2401fffd */ 	addiu	$at,$zero,-3
/*    48c50:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    48c54:	014b6025 */ 	or	$t4,$t2,$t3
/*    48c58:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*    48c5c:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    48c60:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    48c64:	01c17824 */ 	and	$t7,$t6,$at
/*    48c68:	adaf0004 */ 	sw	$t7,0x4($t5)
.L00048c6c:
/*    48c6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    48c70:	8fa20018 */ 	lw	$v0,0x18($sp)
/*    48c74:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    48c78:	03e00008 */ 	jr	$ra
/*    48c7c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00048c80
/*    48c80:	3c0ea410 */ 	lui	$t6,0xa410
/*    48c84:	8dcf0010 */ 	lw	$t7,0x10($t6)
/*    48c88:	3c18a410 */ 	lui	$t8,0xa410
/*    48c8c:	3c08a410 */ 	lui	$t0,0xa410
/*    48c90:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*    48c94:	8f190014 */ 	lw	$t9,0x14($t8)
/*    48c98:	24840004 */ 	addiu	$a0,$a0,0x4
/*    48c9c:	3c0aa410 */ 	lui	$t2,0xa410
/*    48ca0:	ac990000 */ 	sw	$t9,0x0($a0)
/*    48ca4:	8d090018 */ 	lw	$t1,0x18($t0)
/*    48ca8:	24840004 */ 	addiu	$a0,$a0,0x4
/*    48cac:	24840004 */ 	addiu	$a0,$a0,0x4
/*    48cb0:	ac89fffc */ 	sw	$t1,-0x4($a0)
/*    48cb4:	8d4b001c */ 	lw	$t3,0x1c($t2)
/*    48cb8:	24840004 */ 	addiu	$a0,$a0,0x4
/*    48cbc:	03e00008 */ 	jr	$ra
/*    48cc0:	ac8bfffc */ 	sw	$t3,-0x4($a0)
/*    48cc4:	00000000 */ 	nop
/*    48cc8:	00000000 */ 	nop
/*    48ccc:	00000000 */ 	nop
);