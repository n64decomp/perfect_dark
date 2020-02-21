#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_37b00.h"
#include "library/library_3a100.h"
#include "library/library_4b480.h"
#include "types.h"

GLOBAL_ASM(
glabel func00044bc0
/*    44bc0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    44bc4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    44bc8:	afa40048 */ 	sw	$a0,0x48($sp)
/*    44bcc:	afa5004c */ 	sw	$a1,0x4c($sp)
/*    44bd0:	8fae004c */ 	lw	$t6,0x4c($sp)
/*    44bd4:	afae0044 */ 	sw	$t6,0x44($sp)
/*    44bd8:	240400b8 */ 	addiu	$a0,$zero,0xb8
/*    44bdc:	0c00dff0 */ 	jal	func00037fc0
/*    44be0:	27a50044 */ 	addiu	$a1,$sp,0x44
/*    44be4:	1440000c */ 	bnez	$v0,.L00044c18
/*    44be8:	00000000 */ 	sll	$zero,$zero,0x0
/*    44bec:	8faf0044 */ 	lw	$t7,0x44($sp)
/*    44bf0:	25f80008 */ 	addiu	$t8,$t7,0x8
/*    44bf4:	afb80044 */ 	sw	$t8,0x44($sp)
/*    44bf8:	afaf003c */ 	sw	$t7,0x3c($sp)
/*    44bfc:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    44c00:	3c190200 */ 	lui	$t9,0x200
/*    44c04:	373904e0 */ 	ori	$t9,$t9,0x4e0
/*    44c08:	ad190000 */ 	sw	$t9,0x0($t0)
/*    44c0c:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    44c10:	240902e0 */ 	addiu	$t1,$zero,0x2e0
/*    44c14:	ad490004 */ 	sw	$t1,0x4($t2)
.L00044c18:
/*    44c18:	3c0b8006 */ 	lui	$t3,0x8006
/*    44c1c:	8d6bf114 */ 	lw	$t3,-0xeec($t3)
/*    44c20:	afa00040 */ 	sw	$zero,0x40($sp)
/*    44c24:	8d6c003c */ 	lw	$t4,0x3c($t3)
/*    44c28:	198000bd */ 	blez	$t4,.L00044f20
/*    44c2c:	00000000 */ 	sll	$zero,$zero,0x0
.L00044c30:
/*    44c30:	3c0d8006 */ 	lui	$t5,0x8006
/*    44c34:	8dadf114 */ 	lw	$t5,-0xeec($t5)
/*    44c38:	8fa40048 */ 	lw	$a0,0x48($sp)
/*    44c3c:	8fa50044 */ 	lw	$a1,0x44($sp)
/*    44c40:	8dae0030 */ 	lw	$t6,0x30($t5)
/*    44c44:	8fa60040 */ 	lw	$a2,0x40($sp)
/*    44c48:	8dd90004 */ 	lw	$t9,0x4($t6)
/*    44c4c:	0320f809 */ 	jalr	$t9
/*    44c50:	00000000 */ 	sll	$zero,$zero,0x0
/*    44c54:	afa20044 */ 	sw	$v0,0x44($sp)
/*    44c58:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    44c5c:	3c18800a */ 	lui	$t8,0x800a
/*    44c60:	030fc021 */ 	addu	$t8,$t8,$t7
/*    44c64:	9318c344 */ 	lbu	$t8,-0x3cbc($t8)
/*    44c68:	13000023 */ 	beqz	$t8,.L00044cf8
/*    44c6c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44c70:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    44c74:	3c09800a */ 	lui	$t1,0x800a
/*    44c78:	01284821 */ 	addu	$t1,$t1,$t0
/*    44c7c:	9129c346 */ 	lbu	$t1,-0x3cba($t1)
/*    44c80:	1120000f */ 	beqz	$t1,.L00044cc0
/*    44c84:	00000000 */ 	sll	$zero,$zero,0x0
/*    44c88:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    44c8c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*    44c90:	afab0044 */ 	sw	$t3,0x44($sp)
/*    44c94:	afaa0038 */ 	sw	$t2,0x38($sp)
/*    44c98:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    44c9c:	3c0c0c00 */ 	lui	$t4,0xc00
/*    44ca0:	358c8000 */ 	ori	$t4,$t4,0x8000
/*    44ca4:	adac0000 */ 	sw	$t4,0x0($t5)
/*    44ca8:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    44cac:	3c0e07c0 */ 	lui	$t6,0x7c0
/*    44cb0:	35ce04e0 */ 	ori	$t6,$t6,0x4e0
/*    44cb4:	af2e0004 */ 	sw	$t6,0x4($t9)
/*    44cb8:	1000000d */ 	beqz	$zero,.L00044cf0
/*    44cbc:	00000000 */ 	sll	$zero,$zero,0x0
.L00044cc0:
/*    44cc0:	8faf0044 */ 	lw	$t7,0x44($sp)
/*    44cc4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*    44cc8:	afb80044 */ 	sw	$t8,0x44($sp)
/*    44ccc:	afaf0034 */ 	sw	$t7,0x34($sp)
/*    44cd0:	8fa90034 */ 	lw	$t1,0x34($sp)
/*    44cd4:	3c080c00 */ 	lui	$t0,0xc00
/*    44cd8:	35087fff */ 	ori	$t0,$t0,0x7fff
/*    44cdc:	ad280000 */ 	sw	$t0,0x0($t1)
/*    44ce0:	8fab0034 */ 	lw	$t3,0x34($sp)
/*    44ce4:	3c0a07c0 */ 	lui	$t2,0x7c0
/*    44ce8:	354a0650 */ 	ori	$t2,$t2,0x650
/*    44cec:	ad6a0004 */ 	sw	$t2,0x4($t3)
.L00044cf0:
/*    44cf0:	1000002d */ 	beqz	$zero,.L00044da8
/*    44cf4:	00000000 */ 	sll	$zero,$zero,0x0
.L00044cf8:
/*    44cf8:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    44cfc:	3c0d800a */ 	lui	$t5,0x800a
/*    44d00:	01ac6821 */ 	addu	$t5,$t5,$t4
/*    44d04:	91adc346 */ 	lbu	$t5,-0x3cba($t5)
/*    44d08:	11a0000f */ 	beqz	$t5,.L00044d48
/*    44d0c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44d10:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    44d14:	25d90008 */ 	addiu	$t9,$t6,0x8
/*    44d18:	afb90044 */ 	sw	$t9,0x44($sp)
/*    44d1c:	afae0030 */ 	sw	$t6,0x30($sp)
/*    44d20:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    44d24:	3c0f0c00 */ 	lui	$t7,0xc00
/*    44d28:	35ef8000 */ 	ori	$t7,$t7,0x8000
/*    44d2c:	af0f0000 */ 	sw	$t7,0x0($t8)
/*    44d30:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    44d34:	3c0807c0 */ 	lui	$t0,0x7c0
/*    44d38:	35080650 */ 	ori	$t0,$t0,0x650
/*    44d3c:	ad280004 */ 	sw	$t0,0x4($t1)
/*    44d40:	1000000d */ 	beqz	$zero,.L00044d78
/*    44d44:	00000000 */ 	sll	$zero,$zero,0x0
.L00044d48:
/*    44d48:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    44d4c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*    44d50:	afab0044 */ 	sw	$t3,0x44($sp)
/*    44d54:	afaa002c */ 	sw	$t2,0x2c($sp)
/*    44d58:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    44d5c:	3c0c0c00 */ 	lui	$t4,0xc00
/*    44d60:	358c7fff */ 	ori	$t4,$t4,0x7fff
/*    44d64:	adac0000 */ 	sw	$t4,0x0($t5)
/*    44d68:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    44d6c:	3c0e07c0 */ 	lui	$t6,0x7c0
/*    44d70:	35ce0650 */ 	ori	$t6,$t6,0x650
/*    44d74:	af2e0004 */ 	sw	$t6,0x4($t9)
.L00044d78:
/*    44d78:	8faf0044 */ 	lw	$t7,0x44($sp)
/*    44d7c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*    44d80:	afb80044 */ 	sw	$t8,0x44($sp)
/*    44d84:	afaf0028 */ 	sw	$t7,0x28($sp)
/*    44d88:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    44d8c:	3c080c00 */ 	lui	$t0,0xc00
/*    44d90:	35087fff */ 	ori	$t0,$t0,0x7fff
/*    44d94:	ad280000 */ 	sw	$t0,0x0($t1)
/*    44d98:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    44d9c:	3c0a07c0 */ 	lui	$t2,0x7c0
/*    44da0:	354a04e0 */ 	ori	$t2,$t2,0x4e0
/*    44da4:	ad6a0004 */ 	sw	$t2,0x4($t3)
.L00044da8:
/*    44da8:	3c0c8006 */ 	lui	$t4,0x8006
/*    44dac:	8d8cf114 */ 	lw	$t4,-0xeec($t4)
/*    44db0:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    44db4:	8d8d0034 */ 	lw	$t5,0x34($t4)
/*    44db8:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*    44dbc:	032ec821 */ 	addu	$t9,$t9,$t6
/*    44dc0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    44dc4:	01b97821 */ 	addu	$t7,$t5,$t9
/*    44dc8:	8df80044 */ 	lw	$t8,0x44($t7)
/*    44dcc:	87080002 */ 	lh	$t0,0x2($t8)
/*    44dd0:	1900004a */ 	blez	$t0,.L00044efc
/*    44dd4:	00000000 */ 	sll	$zero,$zero,0x0
/*    44dd8:	3c098006 */ 	lui	$t1,0x8006
/*    44ddc:	8d29f114 */ 	lw	$t1,-0xeec($t1)
/*    44de0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*    44de4:	8d2a0034 */ 	lw	$t2,0x34($t1)
/*    44de8:	000b60c0 */ 	sll	$t4,$t3,0x3
/*    44dec:	018b6021 */ 	addu	$t4,$t4,$t3
/*    44df0:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    44df4:	014c7021 */ 	addu	$t6,$t2,$t4
/*    44df8:	8dcd0044 */ 	lw	$t5,0x44($t6)
/*    44dfc:	afad0024 */ 	sw	$t5,0x24($sp)
/*    44e00:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    44e04:	8f2f0028 */ 	lw	$t7,0x28($t9)
/*    44e08:	11e0000b */ 	beqz	$t7,.L00044e38
/*    44e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44e10:	3c188006 */ 	lui	$t8,0x8006
/*    44e14:	8f18f114 */ 	lw	$t8,-0xeec($t8)
/*    44e18:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    44e1c:	8f080040 */ 	lw	$t0,0x40($t8)
/*    44e20:	44882000 */ 	mtc1	$t0,$f4
/*    44e24:	00000000 */ 	sll	$zero,$zero,0x0
/*    44e28:	46802120 */ 	cvt.s.w	$f4,$f4
/*    44e2c:	44052000 */ 	mfc1	$a1,$f4
/*    44e30:	0c00ee99 */ 	jal	func0003ba64
/*    44e34:	00000000 */ 	sll	$zero,$zero,0x0
.L00044e38:
/*    44e38:	8fa90044 */ 	lw	$t1,0x44($sp)
/*    44e3c:	252b0008 */ 	addiu	$t3,$t1,0x8
/*    44e40:	afab0044 */ 	sw	$t3,0x44($sp)
/*    44e44:	afa90020 */ 	sw	$t1,0x20($sp)
/*    44e48:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    44e4c:	3c0a0b00 */ 	lui	$t2,0xb00
/*    44e50:	354a0020 */ 	ori	$t2,$t2,0x20
/*    44e54:	ad8a0000 */ 	sw	$t2,0x0($t4)
/*    44e58:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    44e5c:	0c012d20 */ 	jal	func0004b480
/*    44e60:	24840008 */ 	addiu	$a0,$a0,0x8
/*    44e64:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    44e68:	adc20004 */ 	sw	$v0,0x4($t6)
/*    44e6c:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    44e70:	25b90008 */ 	addiu	$t9,$t5,0x8
/*    44e74:	afb90044 */ 	sw	$t9,0x44($sp)
/*    44e78:	afad001c */ 	sw	$t5,0x1c($sp)
/*    44e7c:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    44e80:	3c0f0e00 */ 	lui	$t7,0xe00
/*    44e84:	35ef04e0 */ 	ori	$t7,$t7,0x4e0
/*    44e88:	af0f0000 */ 	sw	$t7,0x0($t8)
/*    44e8c:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    44e90:	0c012d20 */ 	jal	func0004b480
/*    44e94:	8d04002c */ 	lw	$a0,0x2c($t0)
/*    44e98:	3c0100ff */ 	lui	$at,0xff
/*    44e9c:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    44ea0:	3421ffff */ 	ori	$at,$at,0xffff
/*    44ea4:	00414824 */ 	and	$t1,$v0,$at
/*    44ea8:	01215824 */ 	and	$t3,$t1,$at
/*    44eac:	ad4b0004 */ 	sw	$t3,0x4($t2)
/*    44eb0:	8fac0044 */ 	lw	$t4,0x44($sp)
/*    44eb4:	258e0008 */ 	addiu	$t6,$t4,0x8
/*    44eb8:	afae0044 */ 	sw	$t6,0x44($sp)
/*    44ebc:	afac0018 */ 	sw	$t4,0x18($sp)
/*    44ec0:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    44ec4:	3c0d0e00 */ 	lui	$t5,0xe00
/*    44ec8:	35ad0650 */ 	ori	$t5,$t5,0x650
/*    44ecc:	af2d0000 */ 	sw	$t5,0x0($t9)
/*    44ed0:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    44ed4:	0c012d20 */ 	jal	func0004b480
/*    44ed8:	8de40030 */ 	lw	$a0,0x30($t7)
/*    44edc:	3c0100ff */ 	lui	$at,0xff
/*    44ee0:	8fa90018 */ 	lw	$t1,0x18($sp)
/*    44ee4:	3421ffff */ 	ori	$at,$at,0xffff
/*    44ee8:	0041c024 */ 	and	$t8,$v0,$at
/*    44eec:	03014024 */ 	and	$t0,$t8,$at
/*    44ef0:	ad280004 */ 	sw	$t0,0x4($t1)
/*    44ef4:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    44ef8:	ad600028 */ 	sw	$zero,0x28($t3)
.L00044efc:
/*    44efc:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    44f00:	3c0e8006 */ 	lui	$t6,0x8006
/*    44f04:	8dcef114 */ 	lw	$t6,-0xeec($t6)
/*    44f08:	254c0001 */ 	addiu	$t4,$t2,0x1
/*    44f0c:	afac0040 */ 	sw	$t4,0x40($sp)
/*    44f10:	8dcd003c */ 	lw	$t5,0x3c($t6)
/*    44f14:	018d082a */ 	slt	$at,$t4,$t5
/*    44f18:	1420ff45 */ 	bnez	$at,.L00044c30
/*    44f1c:	00000000 */ 	sll	$zero,$zero,0x0
.L00044f20:
/*    44f20:	10000003 */ 	beqz	$zero,.L00044f30
/*    44f24:	8fa20044 */ 	lw	$v0,0x44($sp)
/*    44f28:	10000001 */ 	beqz	$zero,.L00044f30
/*    44f2c:	00000000 */ 	sll	$zero,$zero,0x0
.L00044f30:
/*    44f30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    44f34:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*    44f38:	03e00008 */ 	jr	$ra
/*    44f3c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00044f40
/*    44f40:	00052c00 */ 	sll	$a1,$a1,0x10
/*    44f44:	00052c03 */ 	sra	$a1,$a1,0x10
/*    44f48:	a4850016 */ 	sh	$a1,0x16($a0)
/*    44f4c:	03e00008 */ 	jr	$ra
/*    44f50:	00000000 */ 	sll	$zero,$zero,0x0
/*    44f54:	03e00008 */ 	jr	$ra
/*    44f58:	00000000 */ 	sll	$zero,$zero,0x0
/*    44f5c:	00000000 */ 	sll	$zero,$zero,0x0
);