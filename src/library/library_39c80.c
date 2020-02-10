#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_3c4d0.h"
#include "library/library_43dd0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00039c80
/*    39c80:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    39c84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    39c88:	afa40028 */ 	sw	$a0,0x28($sp)
/*    39c8c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    39c90:	240e000a */ 	addiu	$t6,$zero,0xa
/*    39c94:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    39c98:	87af002e */ 	lh	$t7,0x2e($sp)
/*    39c9c:	a7af001c */ 	sh	$t7,0x1c($sp)
/*    39ca0:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    39ca4:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    39ca8:	00003025 */ 	or	$a2,$zero,$zero
/*    39cac:	00003825 */ 	or	$a3,$zero,$zero
/*    39cb0:	0c00f184 */ 	jal	func0003c610
/*    39cb4:	24840048 */ 	addiu	$a0,$a0,0x48
/*    39cb8:	10000001 */ 	beqz	$zero,.L00039cc0
/*    39cbc:	00000000 */ 	sll	$zero,$zero,0x0
.L00039cc0:
/*    39cc0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    39cc4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    39cc8:	03e00008 */ 	jr	$ra
/*    39ccc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00039cd0
/*    39cd0:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    39cd4:	340effff */ 	dli	$t6,0xffff
/*    39cd8:	a48e0030 */ 	sh	$t6,0x30($a0)
/*    39cdc:	afa00004 */ 	sw	$zero,0x4($sp)
/*    39ce0:	908f0034 */ 	lbu	$t7,0x34($a0)
/*    39ce4:	19e0001c */ 	blez	$t7,.L00039d58
/*    39ce8:	00000000 */ 	sll	$zero,$zero,0x0
.L00039cec:
/*    39cec:	8fa80004 */ 	lw	$t0,0x4($sp)
/*    39cf0:	8c990060 */ 	lw	$t9,0x60($a0)
/*    39cf4:	241800ff */ 	addiu	$t8,$zero,0xff
/*    39cf8:	00084880 */ 	sll	$t1,$t0,0x2
/*    39cfc:	01284823 */ 	subu	$t1,$t1,$t0
/*    39d00:	00094880 */ 	sll	$t1,$t1,0x2
/*    39d04:	01284821 */ 	addu	$t1,$t1,$t0
/*    39d08:	00094880 */ 	sll	$t1,$t1,0x2
/*    39d0c:	03295021 */ 	addu	$t2,$t9,$t1
/*    39d10:	a158000e */ 	sb	$t8,0xe($t2)
/*    39d14:	8fad0004 */ 	lw	$t5,0x4($sp)
/*    39d18:	8c8c0060 */ 	lw	$t4,0x60($a0)
/*    39d1c:	240b00ff */ 	addiu	$t3,$zero,0xff
/*    39d20:	000d7080 */ 	sll	$t6,$t5,0x2
/*    39d24:	01cd7023 */ 	subu	$t6,$t6,$t5
/*    39d28:	000e7080 */ 	sll	$t6,$t6,0x2
/*    39d2c:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    39d30:	000e7080 */ 	sll	$t6,$t6,0x2
/*    39d34:	018e7821 */ 	addu	$t7,$t4,$t6
/*    39d38:	a1eb000d */ 	sb	$t3,0xd($t7)
/*    39d3c:	8fa80004 */ 	lw	$t0,0x4($sp)
/*    39d40:	25190001 */ 	addiu	$t9,$t0,0x1
/*    39d44:	afb90004 */ 	sw	$t9,0x4($sp)
/*    39d48:	90890034 */ 	lbu	$t1,0x34($a0)
/*    39d4c:	0329082a */ 	slt	$at,$t9,$t1
/*    39d50:	1420ffe6 */ 	bnez	$at,.L00039cec
/*    39d54:	00000000 */ 	sll	$zero,$zero,0x0
.L00039d58:
/*    39d58:	10000001 */ 	beqz	$zero,.L00039d60
/*    39d5c:	00000000 */ 	sll	$zero,$zero,0x0
.L00039d60:
/*    39d60:	03e00008 */ 	jr	$ra
/*    39d64:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*    39d68:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39d6c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39d70:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39d74:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39d78:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39d7c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39d80:	00002825 */ 	or	$a1,$zero,$zero
/*    39d84:	240700fc */ 	addiu	$a3,$zero,0xfc
/*    39d88:	afa00010 */ 	sw	$zero,0x10($sp)
/*    39d8c:	0c011194 */ 	jal	func00044650
/*    39d90:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39d94:	10000001 */ 	beqz	$zero,.L00039d9c
/*    39d98:	00000000 */ 	sll	$zero,$zero,0x0
.L00039d9c:
/*    39d9c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39da0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39da4:	03e00008 */ 	jr	$ra
/*    39da8:	00000000 */ 	sll	$zero,$zero,0x0
/*    39dac:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39db0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39db4:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39db8:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39dbc:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    39dc0:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    39dc4:	24190001 */ 	addiu	$t9,$zero,0x1
/*    39dc8:	95cf0030 */ 	lhu	$t7,0x30($t6)
/*    39dcc:	03194004 */ 	sllv	$t0,$t9,$t8
/*    39dd0:	01e84825 */ 	or	$t1,$t7,$t0
/*    39dd4:	a5c90030 */ 	sh	$t1,0x30($t6)
/*    39dd8:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39ddc:	240a00ff */ 	addiu	$t2,$zero,0xff
/*    39de0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    39de4:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39de8:	00002825 */ 	or	$a1,$zero,$zero
/*    39dec:	240700fc */ 	addiu	$a3,$zero,0xfc
/*    39df0:	0c011194 */ 	jal	func00044650
/*    39df4:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39df8:	10000001 */ 	beqz	$zero,.L00039e00
/*    39dfc:	00000000 */ 	sll	$zero,$zero,0x0
.L00039e00:
/*    39e00:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39e04:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39e08:	03e00008 */ 	jr	$ra
/*    39e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*    39e10:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39e14:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39e18:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39e1c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39e20:	afa60028 */ 	sw	$a2,0x28($sp)
/*    39e24:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39e28:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*    39e2c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39e30:	00002825 */ 	or	$a1,$zero,$zero
/*    39e34:	240700ff */ 	addiu	$a3,$zero,0xff
/*    39e38:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39e3c:	0c011194 */ 	jal	func00044650
/*    39e40:	afae0010 */ 	sw	$t6,0x10($sp)
/*    39e44:	10000001 */ 	beqz	$zero,.L00039e4c
/*    39e48:	00000000 */ 	sll	$zero,$zero,0x0
.L00039e4c:
/*    39e4c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39e50:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39e54:	03e00008 */ 	jr	$ra
/*    39e58:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00039e5c
/*    39e5c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39e60:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39e64:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39e68:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39e6c:	afa60028 */ 	sw	$a2,0x28($sp)
/*    39e70:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    39e74:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39e78:	93ae002f */ 	lbu	$t6,0x2f($sp)
/*    39e7c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39e80:	00002825 */ 	or	$a1,$zero,$zero
/*    39e84:	240700fd */ 	addiu	$a3,$zero,0xfd
/*    39e88:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39e8c:	0c011194 */ 	jal	func00044650
/*    39e90:	afae0010 */ 	sw	$t6,0x10($sp)
/*    39e94:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39e98:	93af002b */ 	lbu	$t7,0x2b($sp)
/*    39e9c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39ea0:	00002825 */ 	or	$a1,$zero,$zero
/*    39ea4:	240700ff */ 	addiu	$a3,$zero,0xff
/*    39ea8:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39eac:	0c011194 */ 	jal	func00044650
/*    39eb0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    39eb4:	10000001 */ 	beqz	$zero,.L00039ebc
/*    39eb8:	00000000 */ 	sll	$zero,$zero,0x0
.L00039ebc:
/*    39ebc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39ec0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39ec4:	03e00008 */ 	jr	$ra
/*    39ec8:	00000000 */ 	sll	$zero,$zero,0x0
/*    39ecc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39ed0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39ed4:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39ed8:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39edc:	afa60028 */ 	sw	$a2,0x28($sp)
/*    39ee0:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39ee4:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*    39ee8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39eec:	00002825 */ 	or	$a1,$zero,$zero
/*    39ef0:	24070041 */ 	addiu	$a3,$zero,0x41
/*    39ef4:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39ef8:	0c011194 */ 	jal	func00044650
/*    39efc:	afae0010 */ 	sw	$t6,0x10($sp)
/*    39f00:	10000001 */ 	beqz	$zero,.L00039f08
/*    39f04:	00000000 */ 	sll	$zero,$zero,0x0
.L00039f08:
/*    39f08:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39f0c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39f10:	03e00008 */ 	jr	$ra
/*    39f14:	00000000 */ 	sll	$zero,$zero,0x0
/*    39f18:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39f1c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39f20:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39f24:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39f28:	afa60028 */ 	sw	$a2,0x28($sp)
/*    39f2c:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39f30:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*    39f34:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39f38:	00002825 */ 	or	$a1,$zero,$zero
/*    39f3c:	240700fc */ 	addiu	$a3,$zero,0xfc
/*    39f40:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39f44:	0c011194 */ 	jal	func00044650
/*    39f48:	afae0010 */ 	sw	$t6,0x10($sp)
/*    39f4c:	10000001 */ 	beqz	$zero,.L00039f54
/*    39f50:	00000000 */ 	sll	$zero,$zero,0x0
.L00039f54:
/*    39f54:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39f58:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39f5c:	03e00008 */ 	jr	$ra
/*    39f60:	00000000 */ 	sll	$zero,$zero,0x0
/*    39f64:	00000000 */ 	sll	$zero,$zero,0x0
/*    39f68:	00000000 */ 	sll	$zero,$zero,0x0
/*    39f6c:	00000000 */ 	sll	$zero,$zero,0x0
);