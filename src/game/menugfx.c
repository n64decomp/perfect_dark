#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/bondgun.h"
#include "game/tex.h"
#include "game/savebuffer.h"
#include "game/menugfx.h"
#include "game/menu.h"
#include "game/game_1531a0.h"
#include "game/gfxmemory.h"
#include "game/file.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

#if VERSION == VERSION_PAL_FINAL
GLOBAL_ASM(
glabel menugfxCreateBlur
/*  f0e0db0:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0e0db4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e0db8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0e0dbc:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0e0dc0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0e0dc4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0e0dc8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0e0dcc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0e0dd0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0e0dd4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e0dd8:	0c002a1c */ 	jal	viGetFrontBuffer
/*  f0e0ddc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e0de0:	0c002e53 */ 	jal	viGetWidth
/*  f0e0de4:	00408025 */ 	move	$s0,$v0
/*  f0e0de8:	00026840 */ 	sll	$t5,$v0,0x1
/*  f0e0dec:	0c002e53 */ 	jal	viGetWidth
/*  f0e0df0:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f0e0df4:	44822000 */ 	mtc1	$v0,$f4
/*  f0e0df8:	3c0143a0 */ 	lui	$at,0x43a0
/*  f0e0dfc:	44814000 */ 	mtc1	$at,$f8
/*  f0e0e00:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e0e04:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0e0e08:	8def1460 */ 	lw	$t7,0x1460($t7)
/*  f0e0e0c:	3c018008 */ 	lui	$at,0x8008
/*  f0e0e10:	240e0001 */ 	li	$t6,0x1
/*  f0e0e14:	ac2e0020 */ 	sw	$t6,0x20($at)
/*  f0e0e18:	24010001 */ 	li	$at,0x1
/*  f0e0e1c:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0e0e20:	15e10007 */ 	bne	$t7,$at,.PF0f0e0e40
/*  f0e0e24:	46083003 */ 	div.s	$f0,$f6,$f8
/*  f0e0e28:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f0e0e2c:	0c002a1c */ 	jal	viGetFrontBuffer
/*  f0e0e30:	e7a0006c */ 	swc1	$f0,0x6c($sp)
/*  f0e0e34:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0e0e38:	c7a0006c */ 	lwc1	$f0,0x6c($sp)
/*  f0e0e3c:	00408025 */ 	move	$s0,$v0
.PF0f0e0e40:
/*  f0e0e40:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0e0e44:	3c058007 */ 	lui	$a1,0x8007
/*  f0e0e48:	24a51460 */ 	addiu	$a1,$a1,0x1460
/*  f0e0e4c:	2484f1f0 */ 	addiu	$a0,$a0,-3600
/*  f0e0e50:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f0e0e54:	0c003624 */ 	jal	mainOverrideVariable
/*  f0e0e58:	e7a0006c */ 	swc1	$f0,0x6c($sp)
/*  f0e0e5c:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0e0e60:	3c15800a */ 	lui	$s5,0x800a
/*  f0e0e64:	c7a0006c */ 	lwc1	$f0,0x6c($sp)
/*  f0e0e68:	000dc0c0 */ 	sll	$t8,$t5,0x3
/*  f0e0e6c:	afb80044 */ 	sw	$t8,0x44($sp)
/*  f0e0e70:	26b5e55c */ 	addiu	$s5,$s5,-6820
/*  f0e0e74:	0000f025 */ 	move	$s8,$zero
/*  f0e0e78:	0000b025 */ 	move	$s6,$zero
/*  f0e0e7c:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f0e0e80:	24170028 */ 	li	$s7,0x28
/*  f0e0e84:	240cfffe */ 	li	$t4,-2
/*  f0e0e88:	240b0008 */ 	li	$t3,0x8
.PF0f0e0e8c:
/*  f0e0e8c:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0e0e90:	00009025 */ 	move	$s2,$zero
.PF0f0e0e94:
/*  f0e0e94:	44925000 */ 	mtc1	$s2,$f10
/*  f0e0e98:	3c014000 */ 	lui	$at,0x4000
/*  f0e0e9c:	44819000 */ 	mtc1	$at,$f18
/*  f0e0ea0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e0ea4:	3c014080 */ 	lui	$at,0x4080
/*  f0e0ea8:	44813000 */ 	mtc1	$at,$f6
/*  f0e0eac:	3c014000 */ 	lui	$at,0x4000
/*  f0e0eb0:	44815000 */ 	mtc1	$at,$f10
/*  f0e0eb4:	2401fffe */ 	li	$at,-2
/*  f0e0eb8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0e0ebc:	0260a025 */ 	move	$s4,$s3
/*  f0e0ec0:	00004025 */ 	move	$t0,$zero
/*  f0e0ec4:	00003825 */ 	move	$a3,$zero
/*  f0e0ec8:	00004825 */ 	move	$t1,$zero
/*  f0e0ecc:	0000f825 */ 	move	$ra,$zero
/*  f0e0ed0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e0ed4:	00000000 */ 	nop
/*  f0e0ed8:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0e0edc:	00000000 */ 	nop
/*  f0e0ee0:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e0ee4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e0ee8:	440e2000 */ 	mfc1	$t6,$f4
/*  f0e0eec:	00000000 */ 	nop
/*  f0e0ef0:	01d68821 */ 	addu	$s1,$t6,$s6
/*  f0e0ef4:	02217824 */ 	and	$t7,$s1,$at
/*  f0e0ef8:	01e08825 */ 	move	$s1,$t7
/*  f0e0efc:	449f3000 */ 	mtc1	$ra,$f6
.PF0f0e0f00:
/*  f0e0f00:	3c014000 */ 	lui	$at,0x4000
/*  f0e0f04:	44815000 */ 	mtc1	$at,$f10
/*  f0e0f08:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e0f0c:	27ff0001 */ 	addiu	$ra,$ra,0x1
/*  f0e0f10:	00002825 */ 	move	$a1,$zero
/*  f0e0f14:	00003025 */ 	move	$a2,$zero
/*  f0e0f18:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0e0f1c:	00000000 */ 	nop
/*  f0e0f20:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e0f24:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e0f28:	44192000 */ 	mfc1	$t9,$f4
/*  f0e0f2c:	00000000 */ 	nop
/*  f0e0f30:	03315021 */ 	addu	$t2,$t9,$s1
.PF0f0e0f34:
/*  f0e0f34:	01467021 */ 	addu	$t6,$t2,$a2
/*  f0e0f38:	01cc7824 */ 	and	$t7,$t6,$t4
/*  f0e0f3c:	01f01821 */ 	addu	$v1,$t7,$s0
/*  f0e0f40:	90790000 */ 	lbu	$t9,0x0($v1)
/*  f0e0f44:	90780001 */ 	lbu	$t8,0x1($v1)
/*  f0e0f48:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0e0f4c:	00197200 */ 	sll	$t6,$t9,0x8
/*  f0e0f50:	030e1025 */ 	or	$v0,$t8,$t6
/*  f0e0f54:	0002cac3 */ 	sra	$t9,$v0,0xb
/*  f0e0f58:	3338001f */ 	andi	$t8,$t9,0x1f
/*  f0e0f5c:	03094821 */ 	addu	$t1,$t8,$t1
/*  f0e0f60:	00027183 */ 	sra	$t6,$v0,0x6
/*  f0e0f64:	0002c843 */ 	sra	$t9,$v0,0x1
/*  f0e0f68:	31cf001f */ 	andi	$t7,$t6,0x1f
/*  f0e0f6c:	3338001f */ 	andi	$t8,$t9,0x1f
/*  f0e0f70:	00cd3021 */ 	addu	$a2,$a2,$t5
/*  f0e0f74:	01e73821 */ 	addu	$a3,$t7,$a3
/*  f0e0f78:	14abffee */ 	bne	$a1,$t3,.PF0f0e0f34
/*  f0e0f7c:	03084021 */ 	addu	$t0,$t8,$t0
/*  f0e0f80:	57ebffdf */ 	bnel	$ra,$t3,.PF0f0e0f00
/*  f0e0f84:	449f3000 */ 	mtc1	$ra,$f6
/*  f0e0f88:	00097182 */ 	srl	$t6,$t1,0x6
/*  f0e0f8c:	00077982 */ 	srl	$t7,$a3,0x6
/*  f0e0f90:	0008c982 */ 	srl	$t9,$t0,0x6
/*  f0e0f94:	000ec0c0 */ 	sll	$t8,$t6,0x3
/*  f0e0f98:	03204025 */ 	move	$t0,$t9
/*  f0e0f9c:	000f7082 */ 	srl	$t6,$t7,0x2
/*  f0e0fa0:	030ec825 */ 	or	$t9,$t8,$t6
/*  f0e0fa4:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f0e0fa8:	01e03825 */ 	move	$a3,$t7
/*  f0e0fac:	00077980 */ 	sll	$t7,$a3,0x6
/*  f0e0fb0:	03147021 */ 	addu	$t6,$t8,$s4
/*  f0e0fb4:	a1d90000 */ 	sb	$t9,0x0($t6)
/*  f0e0fb8:	3118001f */ 	andi	$t8,$t0,0x1f
/*  f0e0fbc:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f0e0fc0:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f0e0fc4:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f0e0fc8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0e0fcc:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f0e0fd0:	01f4c821 */ 	addu	$t9,$t7,$s4
/*  f0e0fd4:	1657ffaf */ 	bne	$s2,$s7,.PF0f0e0e94
/*  f0e0fd8:	a3380001 */ 	sb	$t8,0x1($t9)
/*  f0e0fdc:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0e0fe0:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f0e0fe4:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f0e0fe8:	2401001e */ 	li	$at,0x1e
/*  f0e0fec:	25cf0050 */ 	addiu	$t7,$t6,0x50
/*  f0e0ff0:	afaf0040 */ 	sw	$t7,0x40($sp)
/*  f0e0ff4:	17c1ffa5 */ 	bne	$s8,$at,.PF0f0e0e8c
/*  f0e0ff8:	02d8b021 */ 	addu	$s6,$s6,$t8
/*  f0e0ffc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e1000:	24190001 */ 	li	$t9,0x1
/*  f0e1004:	3c018008 */ 	lui	$at,0x8008
/*  f0e1008:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0e100c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0e1010:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0e1014:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0e1018:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0e101c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0e1020:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0e1024:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0e1028:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0e102c:	ac390020 */ 	sw	$t9,0x20($at)
/*  f0e1030:	03e00008 */ 	jr	$ra
/*  f0e1034:	27bd0080 */ 	addiu	$sp,$sp,0x80
);
#elif VERSION == VERSION_PAL_BETA
GLOBAL_ASM(
glabel menugfxCreateBlur
/*  f0e0bf0:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0e0bf4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e0bf8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0e0bfc:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0e0c00:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0e0c04:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0e0c08:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0e0c0c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0e0c10:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0e0c14:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e0c18:	0c002a16 */ 	jal	viGetFrontBuffer
/*  f0e0c1c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e0c20:	0c002e4d */ 	jal	viGetWidth
/*  f0e0c24:	00408025 */ 	move	$s0,$v0
/*  f0e0c28:	00026840 */ 	sll	$t5,$v0,0x1
/*  f0e0c2c:	0c002e4d */ 	jal	viGetWidth
/*  f0e0c30:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f0e0c34:	44822000 */ 	mtc1	$v0,$f4
/*  f0e0c38:	3c0143a0 */ 	lui	$at,0x43a0
/*  f0e0c3c:	44814000 */ 	mtc1	$at,$f8
/*  f0e0c40:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e0c44:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0e0c48:	8def2e50 */ 	lw	$t7,0x2e50($t7)
/*  f0e0c4c:	3c018008 */ 	lui	$at,0x8008
/*  f0e0c50:	240e0001 */ 	li	$t6,0x1
/*  f0e0c54:	ac2e1f90 */ 	sw	$t6,0x1f90($at)
/*  f0e0c58:	24010001 */ 	li	$at,0x1
/*  f0e0c5c:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0e0c60:	15e10007 */ 	bne	$t7,$at,.PB0f0e0c80
/*  f0e0c64:	46083003 */ 	div.s	$f0,$f6,$f8
/*  f0e0c68:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f0e0c6c:	0c002a16 */ 	jal	viGetFrontBuffer
/*  f0e0c70:	e7a0006c */ 	swc1	$f0,0x6c($sp)
/*  f0e0c74:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0e0c78:	c7a0006c */ 	lwc1	$f0,0x6c($sp)
/*  f0e0c7c:	00408025 */ 	move	$s0,$v0
.PB0f0e0c80:
/*  f0e0c80:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0e0c84:	3c058007 */ 	lui	$a1,0x8007
/*  f0e0c88:	24a52e50 */ 	addiu	$a1,$a1,0x2e50
/*  f0e0c8c:	2484fc40 */ 	addiu	$a0,$a0,-960
/*  f0e0c90:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f0e0c94:	0c003648 */ 	jal	mainOverrideVariable
/*  f0e0c98:	e7a0006c */ 	swc1	$f0,0x6c($sp)
/*  f0e0c9c:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0e0ca0:	3c15800a */ 	lui	$s5,0x800a
/*  f0e0ca4:	c7a0006c */ 	lwc1	$f0,0x6c($sp)
/*  f0e0ca8:	000dc0c0 */ 	sll	$t8,$t5,0x3
/*  f0e0cac:	afb80044 */ 	sw	$t8,0x44($sp)
/*  f0e0cb0:	26b524ec */ 	addiu	$s5,$s5,0x24ec
/*  f0e0cb4:	0000f025 */ 	move	$s8,$zero
/*  f0e0cb8:	0000b025 */ 	move	$s6,$zero
/*  f0e0cbc:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f0e0cc0:	24170028 */ 	li	$s7,0x28
/*  f0e0cc4:	240cfffe */ 	li	$t4,-2
/*  f0e0cc8:	240b0008 */ 	li	$t3,0x8
.PB0f0e0ccc:
/*  f0e0ccc:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0e0cd0:	00009025 */ 	move	$s2,$zero
.PB0f0e0cd4:
/*  f0e0cd4:	44925000 */ 	mtc1	$s2,$f10
/*  f0e0cd8:	3c014000 */ 	lui	$at,0x4000
/*  f0e0cdc:	44819000 */ 	mtc1	$at,$f18
/*  f0e0ce0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e0ce4:	3c014080 */ 	lui	$at,0x4080
/*  f0e0ce8:	44813000 */ 	mtc1	$at,$f6
/*  f0e0cec:	3c014000 */ 	lui	$at,0x4000
/*  f0e0cf0:	44815000 */ 	mtc1	$at,$f10
/*  f0e0cf4:	2401fffe */ 	li	$at,-2
/*  f0e0cf8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0e0cfc:	0260a025 */ 	move	$s4,$s3
/*  f0e0d00:	00004025 */ 	move	$t0,$zero
/*  f0e0d04:	00003825 */ 	move	$a3,$zero
/*  f0e0d08:	00004825 */ 	move	$t1,$zero
/*  f0e0d0c:	0000f825 */ 	move	$ra,$zero
/*  f0e0d10:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e0d14:	00000000 */ 	nop
/*  f0e0d18:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0e0d1c:	00000000 */ 	nop
/*  f0e0d20:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e0d24:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e0d28:	440e2000 */ 	mfc1	$t6,$f4
/*  f0e0d2c:	00000000 */ 	nop
/*  f0e0d30:	01d68821 */ 	addu	$s1,$t6,$s6
/*  f0e0d34:	02217824 */ 	and	$t7,$s1,$at
/*  f0e0d38:	01e08825 */ 	move	$s1,$t7
/*  f0e0d3c:	449f3000 */ 	mtc1	$ra,$f6
.PB0f0e0d40:
/*  f0e0d40:	3c014000 */ 	lui	$at,0x4000
/*  f0e0d44:	44815000 */ 	mtc1	$at,$f10
/*  f0e0d48:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e0d4c:	27ff0001 */ 	addiu	$ra,$ra,0x1
/*  f0e0d50:	00002825 */ 	move	$a1,$zero
/*  f0e0d54:	00003025 */ 	move	$a2,$zero
/*  f0e0d58:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0e0d5c:	00000000 */ 	nop
/*  f0e0d60:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e0d64:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e0d68:	44192000 */ 	mfc1	$t9,$f4
/*  f0e0d6c:	00000000 */ 	nop
/*  f0e0d70:	03315021 */ 	addu	$t2,$t9,$s1
.PB0f0e0d74:
/*  f0e0d74:	01467021 */ 	addu	$t6,$t2,$a2
/*  f0e0d78:	01cc7824 */ 	and	$t7,$t6,$t4
/*  f0e0d7c:	01f01821 */ 	addu	$v1,$t7,$s0
/*  f0e0d80:	90790000 */ 	lbu	$t9,0x0($v1)
/*  f0e0d84:	90780001 */ 	lbu	$t8,0x1($v1)
/*  f0e0d88:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0e0d8c:	00197200 */ 	sll	$t6,$t9,0x8
/*  f0e0d90:	030e1025 */ 	or	$v0,$t8,$t6
/*  f0e0d94:	0002cac3 */ 	sra	$t9,$v0,0xb
/*  f0e0d98:	3338001f */ 	andi	$t8,$t9,0x1f
/*  f0e0d9c:	03094821 */ 	addu	$t1,$t8,$t1
/*  f0e0da0:	00027183 */ 	sra	$t6,$v0,0x6
/*  f0e0da4:	0002c843 */ 	sra	$t9,$v0,0x1
/*  f0e0da8:	31cf001f */ 	andi	$t7,$t6,0x1f
/*  f0e0dac:	3338001f */ 	andi	$t8,$t9,0x1f
/*  f0e0db0:	00cd3021 */ 	addu	$a2,$a2,$t5
/*  f0e0db4:	01e73821 */ 	addu	$a3,$t7,$a3
/*  f0e0db8:	14abffee */ 	bne	$a1,$t3,.PB0f0e0d74
/*  f0e0dbc:	03084021 */ 	addu	$t0,$t8,$t0
/*  f0e0dc0:	57ebffdf */ 	bnel	$ra,$t3,.PB0f0e0d40
/*  f0e0dc4:	449f3000 */ 	mtc1	$ra,$f6
/*  f0e0dc8:	00097182 */ 	srl	$t6,$t1,0x6
/*  f0e0dcc:	00077982 */ 	srl	$t7,$a3,0x6
/*  f0e0dd0:	0008c982 */ 	srl	$t9,$t0,0x6
/*  f0e0dd4:	000ec0c0 */ 	sll	$t8,$t6,0x3
/*  f0e0dd8:	03204025 */ 	move	$t0,$t9
/*  f0e0ddc:	000f7082 */ 	srl	$t6,$t7,0x2
/*  f0e0de0:	030ec825 */ 	or	$t9,$t8,$t6
/*  f0e0de4:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f0e0de8:	01e03825 */ 	move	$a3,$t7
/*  f0e0dec:	00077980 */ 	sll	$t7,$a3,0x6
/*  f0e0df0:	03147021 */ 	addu	$t6,$t8,$s4
/*  f0e0df4:	a1d90000 */ 	sb	$t9,0x0($t6)
/*  f0e0df8:	3118001f */ 	andi	$t8,$t0,0x1f
/*  f0e0dfc:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f0e0e00:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f0e0e04:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f0e0e08:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0e0e0c:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f0e0e10:	01f4c821 */ 	addu	$t9,$t7,$s4
/*  f0e0e14:	1657ffaf */ 	bne	$s2,$s7,.PB0f0e0cd4
/*  f0e0e18:	a3380001 */ 	sb	$t8,0x1($t9)
/*  f0e0e1c:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0e0e20:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f0e0e24:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f0e0e28:	2401001e */ 	li	$at,0x1e
/*  f0e0e2c:	25cf0050 */ 	addiu	$t7,$t6,0x50
/*  f0e0e30:	afaf0040 */ 	sw	$t7,0x40($sp)
/*  f0e0e34:	17c1ffa5 */ 	bne	$s8,$at,.PB0f0e0ccc
/*  f0e0e38:	02d8b021 */ 	addu	$s6,$s6,$t8
/*  f0e0e3c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e0e40:	24190001 */ 	li	$t9,0x1
/*  f0e0e44:	3c018008 */ 	lui	$at,0x8008
/*  f0e0e48:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0e0e4c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0e0e50:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0e0e54:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0e0e58:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0e0e5c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0e0e60:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0e0e64:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0e0e68:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0e0e6c:	ac391f90 */ 	sw	$t9,0x1f90($at)
/*  f0e0e70:	03e00008 */ 	jr	$ra
/*  f0e0e74:	27bd0080 */ 	addiu	$sp,$sp,0x80
);
#else
GLOBAL_ASM(
glabel menugfxCreateBlur
/*  f0e0770:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0e0774:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e0778:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0e077c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0e0780:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0e0784:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0e0788:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0e078c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0e0790:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0e0794:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e0798:	0c002acb */ 	jal	viGetFrontBuffer
/*  f0e079c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e07a0:	0c002f02 */ 	jal	viGetWidth
/*  f0e07a4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e07a8:	3c0e8007 */ 	lui	$t6,%hi(g_ViRes)
/*  f0e07ac:	8dce06c8 */ 	lw	$t6,%lo(g_ViRes)($t6)
/*  f0e07b0:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0e07b4:	0002f840 */ 	sll	$ra,$v0,0x1
/*  f0e07b8:	162e0005 */ 	bne	$s1,$t6,.L0f0e07d0
/*  f0e07bc:	3c188007 */ 	lui	$t8,%hi(var80071180)
/*  f0e07c0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0e07c4:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f0e07c8:	10000003 */ 	b	.L0f0e07d8
/*  f0e07cc:	ac2ffac0 */ 	sw	$t7,%lo(g_ScaleX)($at)
.L0f0e07d0:
/*  f0e07d0:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f0e07d4:	ac31fac0 */ 	sw	$s1,%lo(g_ScaleX)($at)
.L0f0e07d8:
/*  f0e07d8:	8f181180 */ 	lw	$t8,%lo(var80071180)($t8)
/*  f0e07dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e07e0:	17010006 */ 	bne	$t8,$at,.L0f0e07fc
/*  f0e07e4:	00000000 */ 	nop
/*  f0e07e8:	afbf0070 */ 	sw	$ra,0x70($sp)
/*  f0e07ec:	0c002acb */ 	jal	viGetFrontBuffer
/*  f0e07f0:	00000000 */ 	nop
/*  f0e07f4:	8fbf0070 */ 	lw	$ra,0x70($sp)
/*  f0e07f8:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e07fc:
/*  f0e07fc:	3c047f1b */ 	lui	$a0,%hi(var7f1adf00)
/*  f0e0800:	3c058007 */ 	lui	$a1,%hi(var80071180)
/*  f0e0804:	afbf0070 */ 	sw	$ra,0x70($sp)
/*  f0e0808:	24a51180 */ 	addiu	$a1,$a1,%lo(var80071180)
/*  f0e080c:	0c0036cc */ 	jal	mainOverrideVariable
/*  f0e0810:	2484df00 */ 	addiu	$a0,$a0,%lo(var7f1adf00)
/*  f0e0814:	8fbf0070 */ 	lw	$ra,0x70($sp)
/*  f0e0818:	3c17800a */ 	lui	$s7,%hi(g_BlurBuffer)
/*  f0e081c:	26f7dfbc */ 	addiu	$s7,$s7,%lo(g_BlurBuffer)
/*  f0e0820:	001fc8c0 */ 	sll	$t9,$ra,0x3
/*  f0e0824:	afb90048 */ 	sw	$t9,0x48($sp)
/*  f0e0828:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f0e082c:	0000f025 */ 	or	$s8,$zero,$zero
/*  f0e0830:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f0e0834:	24130010 */ 	addiu	$s3,$zero,0x10
/*  f0e0838:	240c0008 */ 	addiu	$t4,$zero,0x8
.L0f0e083c:
/*  f0e083c:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f0e0840:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0e0844:
/*  f0e0844:	3c118008 */ 	lui	$s1,%hi(g_ScaleX)
/*  f0e0848:	8e31fac0 */ 	lw	$s1,%lo(g_ScaleX)($s1)
/*  f0e084c:	02a0b025 */ 	or	$s6,$s5,$zero
/*  f0e0850:	26b50002 */ 	addiu	$s5,$s5,0x2
/*  f0e0854:	02910019 */ 	multu	$s4,$s1
/*  f0e0858:	00004825 */ 	or	$t1,$zero,$zero
/*  f0e085c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0e0860:	00005025 */ 	or	$t2,$zero,$zero
/*  f0e0864:	00006825 */ 	or	$t5,$zero,$zero
/*  f0e0868:	00007012 */ 	mflo	$t6
/*  f0e086c:	01de9021 */ 	addu	$s2,$t6,$s8
/*  f0e0870:	00000000 */ 	nop
.L0f0e0874:
/*  f0e0874:	01b10019 */ 	multu	$t5,$s1
/*  f0e0878:	25ad0002 */ 	addiu	$t5,$t5,0x2
/*  f0e087c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0e0880:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e0884:	00007812 */ 	mflo	$t7
/*  f0e0888:	01f25821 */ 	addu	$t3,$t7,$s2
/*  f0e088c:	00000000 */ 	nop
.L0f0e0890:
/*  f0e0890:	01672021 */ 	addu	$a0,$t3,$a3
/*  f0e0894:	00901821 */ 	addu	$v1,$a0,$s0
/*  f0e0898:	90790000 */ 	lbu	$t9,0x0($v1)
/*  f0e089c:	90780001 */ 	lbu	$t8,0x1($v1)
/*  f0e08a0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0e08a4:	00197200 */ 	sll	$t6,$t9,0x8
/*  f0e08a8:	030e1025 */ 	or	$v0,$t8,$t6
/*  f0e08ac:	0002cac3 */ 	sra	$t9,$v0,0xb
/*  f0e08b0:	3338001f */ 	andi	$t8,$t9,0x1f
/*  f0e08b4:	030a5021 */ 	addu	$t2,$t8,$t2
/*  f0e08b8:	00027183 */ 	sra	$t6,$v0,0x6
/*  f0e08bc:	0002c843 */ 	sra	$t9,$v0,0x1
/*  f0e08c0:	31cf001f */ 	andi	$t7,$t6,0x1f
/*  f0e08c4:	3338001f */ 	andi	$t8,$t9,0x1f
/*  f0e08c8:	00ff3821 */ 	addu	$a3,$a3,$ra
/*  f0e08cc:	01e84021 */ 	addu	$t0,$t7,$t0
/*  f0e08d0:	14ccffef */ 	bne	$a2,$t4,.L0f0e0890
/*  f0e08d4:	03094821 */ 	addu	$t1,$t8,$t1
/*  f0e08d8:	15b3ffe6 */ 	bne	$t5,$s3,.L0f0e0874
/*  f0e08dc:	00000000 */ 	nop
/*  f0e08e0:	000a7182 */ 	srl	$t6,$t2,0x6
/*  f0e08e4:	00087982 */ 	srl	$t7,$t0,0x6
/*  f0e08e8:	0009c982 */ 	srl	$t9,$t1,0x6
/*  f0e08ec:	000ec0c0 */ 	sll	$t8,$t6,0x3
/*  f0e08f0:	03204825 */ 	or	$t1,$t9,$zero
/*  f0e08f4:	000f7082 */ 	srl	$t6,$t7,0x2
/*  f0e08f8:	030ec825 */ 	or	$t9,$t8,$t6
/*  f0e08fc:	8ef80000 */ 	lw	$t8,0x0($s7)
/*  f0e0900:	01e04025 */ 	or	$t0,$t7,$zero
/*  f0e0904:	00087980 */ 	sll	$t7,$t0,0x6
/*  f0e0908:	03167021 */ 	addu	$t6,$t8,$s6
/*  f0e090c:	a1d90000 */ 	sb	$t9,0x0($t6)
/*  f0e0910:	3138001f */ 	andi	$t8,$t1,0x1f
/*  f0e0914:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f0e0918:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f0e091c:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0e0920:	26940010 */ 	addiu	$s4,$s4,0x10
/*  f0e0924:	24010280 */ 	addiu	$at,$zero,0x280
/*  f0e0928:	01f6c821 */ 	addu	$t9,$t7,$s6
/*  f0e092c:	1681ffc5 */ 	bne	$s4,$at,.L0f0e0844
/*  f0e0930:	a3380001 */ 	sb	$t8,0x1($t9)
/*  f0e0934:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f0e0938:	8fa20074 */ 	lw	$v0,0x74($sp)
/*  f0e093c:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0e0940:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f0e0944:	25cf0050 */ 	addiu	$t7,$t6,0x50
/*  f0e0948:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0e094c:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0e0950:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f0e0954:	1441ffb9 */ 	bne	$v0,$at,.L0f0e083c
/*  f0e0958:	03d8f021 */ 	addu	$s8,$s8,$t8
/*  f0e095c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e0960:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0e0964:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f0e0968:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0e096c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0e0970:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0e0974:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0e0978:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0e097c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0e0980:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0e0984:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0e0988:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0e098c:	ac39fac0 */ 	sw	$t9,%lo(g_ScaleX)($at)
/*  f0e0990:	03e00008 */ 	jr	$ra
/*  f0e0994:	27bd0080 */ 	addiu	$sp,$sp,0x80
);
#endif

const u32 var7f1adf00[] = {0x63636363};
const u32 var7f1adf04[] = {0x00000000};
u32 var80071180 = 1;

#define BLURIMG_WIDTH  40
#define BLURIMG_HEIGHT 30
#define SAMPLE_WIDTH  8
#define SAMPLE_HEIGHT 8
#define PXTOBYTES(val) ((val) * 2)

/**
 * Blur the gameplay background for the pause menu.
 *
 * The blurred image is 30x40 pixels at 16 bits per pixel. At standard
 * resolution this is 1/8th the size of the framebuffer.
 *
 * This function reads the framebuffer in blocks of 8x8 pixels. Each block's
 * R/G/B components are averaged and used to set a pixel in the blurred buffer.
 *
 * If hi-res is being used, every second horizontal pixel on the framebuffer is
 * read instead. The blurred image is the same size regardless of hi-res.
 *
 * The transition effect when pausing and unpausing is implemented elsewhere.
 * It's a simple fade between the source framebuffer and the blurred image.
 * Only one blurred image is made.
 */
//void menugfxCreateBlur(void)
//{
//#if VERSION >= VERSION_PAL_FINAL
//	// Mismatch: Different codegen
//	u8 *fb = viGetFrontBuffer();
//	s32 fbwidthinbytes = viGetWidth() * 2;
//	f32 scale = viGetWidth() / 320.0f;
//	s32 dsty;
//	s32 dstx;
//	s32 srcx;
//	s32 srcy;
//
//	static u32 var80071180 = 1;
//
//	g_ScaleX = 1;
//
//	if (var80071180 == 1) {
//		fb = viGetFrontBuffer();
//	}
//
//	mainOverrideVariable("cccc", &var80071180);
//
//	for (dsty = 0; dsty < 30; dsty++) {
//		for (dstx = 0; dstx < 40; dstx++) {
//			s32 dstindex = dsty * 80 + dstx * 2;
//			u32 r = 0;
//			u32 g = 0;
//			u32 b = 0;
//
//			for (srcx = 0; srcx < 8; srcx++) {
//				for (srcy = 0; srcy < 8; srcy++) {
//					s32 e = (f32)dstx * 2 * 4 * 2 * scale;
//					s32 c = (dsty * fbwidthinbytes * 8);
//					s32 block = (e + c) & ~1;
//					s32 a = (f32)srcx * 2 * scale;
//					s32 d = (srcy * fbwidthinbytes);
//					s32 index = (a + block + d) & ~1;
//
//					u32 colour = fb[index] << 8 | fb[index + 1];
//
//					r += colour >> 11 & 0x1f;
//					g += colour >> 6 & 0x1f;
//					b += colour >> 1 & 0x1f;
//				}
//			}
//
//			r /= SAMPLE_WIDTH * SAMPLE_HEIGHT;
//			g /= SAMPLE_WIDTH * SAMPLE_HEIGHT;
//			b /= SAMPLE_WIDTH * SAMPLE_HEIGHT;
//
//			g_BlurBuffer[dstindex + 0] = (r << 3) | (g >> 2);
//			g_BlurBuffer[dstindex + 1] = (g << 6) | ((b & 0x1f) << 1);
//		}
//	}
//
//	g_ScaleX = 1;
//#else
//	// Mismatch: The below stores 0x280 (end value for dstx loop) in s8,
//	// and doesn't store samplestartindex in s2.
//	u8 *fb = viGetFrontBuffer();
//	s32 fbwidthinbytes = PXTOBYTES(viGetWidth());
//	s32 dsty;
//	s32 dstx;
//	s32 srcx;
//	s32 srcy;
//
//	static u32 var80071180 = 1;
//
//	g_ScaleX = (g_ViRes == VIRES_HI) ? 2 : 1;
//
//	if (var80071180 == 1) {
//		fb = viGetFrontBuffer();
//	}
//
//	mainOverrideVariable("cccc", &var80071180);
//
//	for (dsty = 0; dsty < BLURIMG_HEIGHT; dsty++) {
//		for (dstx = 0; dstx < BLURIMG_WIDTH; dstx++) {
//			s32 dstindex = PXTOBYTES(dsty * BLURIMG_WIDTH) + PXTOBYTES(dstx);
//			u32 r = 0;
//			u32 g = 0;
//			u32 b = 0;
//			s32 samplestartindex = PXTOBYTES(dstx * SAMPLE_WIDTH) * g_ScaleX + dsty * fbwidthinbytes * SAMPLE_HEIGHT;
//
//			for (srcx = 0; srcx < SAMPLE_WIDTH; srcx++) {
//				for (srcy = 0; srcy < SAMPLE_HEIGHT; srcy++) {
//					s32 offset = PXTOBYTES(srcx) * g_ScaleX + srcy * fbwidthinbytes;
//					s32 colour = fb[samplestartindex + offset] << 8 | fb[samplestartindex + offset + 1];
//
//					r += colour >> 11 & 0x1f;
//					g += colour >> 6 & 0x1f;
//					b += colour >> 1 & 0x1f;
//				}
//			}
//
//			r /= SAMPLE_WIDTH * SAMPLE_HEIGHT;
//			g /= SAMPLE_WIDTH * SAMPLE_HEIGHT;
//			b /= SAMPLE_WIDTH * SAMPLE_HEIGHT;
//
//			g_BlurBuffer[dstindex + 0] = (r << 3) | (g >> 2);
//			g_BlurBuffer[dstindex + 1] = (g << 6) | ((b & 0x1f) << 1);
//		}
//	}
//
//	g_ScaleX = 1;
//#endif
//}

u32 var80071184 = 0;

Gfx *menugfxRenderBgBlur(Gfx *gdl, u32 colour, s16 arg2, s16 arg3)
{
	u32 *colours;
	struct gfxvtx *vertices;
#if VERSION >= VERSION_PAL_BETA
	s32 width;
	s32 height;
#endif

	if (IS4MB()) {
		return menugfxRenderGradient(gdl, 0, 0, viGetWidth(), viGetHeight(), 0xff, 0xff, 0xff);
	}

	colours = gfxAllocateColours(1);
	vertices = gfxAllocateVertices(4);

	gDPPipeSync(gdl++);
	gSPTexture(gdl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);

	gDPLoadTextureBlock(gdl++, g_BlurBuffer, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 30, 0,
			G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
			G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);

	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

#if VERSION >= VERSION_JPN_FINAL
	width = viGetWidth() * 10;
	height = viGetHeight() * 10;

	*(u16 *)&vertices[0].x = arg2;
	*(u16 *)&vertices[0].y = arg3;
	vertices[0].z = -10;
	*(u16 *)&vertices[1].x = arg2 + 320 * 10u + 40;
	*(u16 *)&vertices[1].y = arg3;
	vertices[1].z = -10;
	*(u16 *)&vertices[2].x = arg2 + 320 * 10u + 40;
	*(u16 *)&vertices[2].y = arg3 + 240 * 10u + 50;
	vertices[2].z = -10;
	*(u16 *)&vertices[3].x = arg2;
	*(u16 *)&vertices[3].y = arg3 + 240 * 10u + 50;
	vertices[3].z = -10;
#elif PAL
	width = viGetWidth() * 10;
	height = viGetHeight() * 10;

	*(u16 *)&vertices[0].x = arg2;
	*(u16 *)&vertices[0].y = arg3;
	vertices[0].z = -10;
	*(u16 *)&vertices[1].x = (s32)width + arg2 + 40;
	*(u16 *)&vertices[1].y = arg3;
	vertices[1].z = -10;
	*(u16 *)&vertices[2].x = (s32)width + arg2 + 40;
	*(u16 *)&vertices[2].y = (s32)height + arg3 + 50;
	vertices[2].z = -10;
	*(u16 *)&vertices[3].x = arg2;
	*(u16 *)&vertices[3].y = (s32)height + arg3 + 50;
	vertices[3].z = -10;
#else
	*(u16 *)&vertices[0].x = arg2;
	*(u16 *)&vertices[0].y = arg3;
	vertices[0].z = -10;
	*(u16 *)&vertices[1].x = arg2 + 320 * 10u + 40;
	*(u16 *)&vertices[1].y = arg3;
	vertices[1].z = -10;
	*(u16 *)&vertices[2].x = arg2 + 320 * 10u + 40;
	*(u16 *)&vertices[2].y = arg3 + 240 * 10u + 50;
	vertices[2].z = -10;
	*(u16 *)&vertices[3].x = arg2;
	*(u16 *)&vertices[3].y = arg3 + 240 * 10u + 50;
	vertices[3].z = -10;
#endif

	vertices[0].s = 0;
	vertices[0].t = 0;
	vertices[1].s = 1280;
	vertices[1].t = 0;
	vertices[2].s = 1280;
	vertices[2].t = 960;
	vertices[3].s = 0;
	vertices[3].t = 960;

	vertices[0].colour = 0;
	vertices[1].colour = 0;
	vertices[2].colour = 0;
	vertices[3].colour = 0;

	colours[0] = colour;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);

	gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);

	return gdl;
}

void func0f0e0cbc(s32 arg0, s32 arg1, s16 arg2, s16 arg3, struct gfxvtx *vertex, Mtxf *arg5)
{
	struct coord sp24;

	sp24.x = (arg2 - arg0 + 100) * 0.25f;
	sp24.y = (arg3 - arg1 + 100) * 0.25f;
	sp24.z = 0;

	vertex->x = arg2 * 10;
	vertex->y = arg3 * 10;
	vertex->z = -10;

	vertex->colour = 0;

	mtx4TransformVecInPlace(arg5, &sp24);

	vertex->s = sp24.x * 32;
	vertex->t = sp24.y * 32;
}

Gfx *menugfxRenderDialogBackground(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, struct menudialog *dialog, u32 colour1, u32 colour2, f32 arg8)
{
	u32 stack[1];
	u32 leftcolour;
	u32 rightcolour;

	// Render the dialog's background fill
	gdl = textSetPrimColour(gdl, colour1);

	gDPFillRectangleScaled(gdl++, x1, y1, x2, y2);

	gdl = text0f153838(gdl);

	if (dialog->transitionfrac < 0.0f) {
		leftcolour = g_MenuColourPalettes[dialog->type].unk00;
	} else {
		leftcolour = colourBlend(g_MenuColourPalettes[dialog->type2].unk00, g_MenuColourPalettes[dialog->type].unk00, dialog->colourweight);
	}

	if (dialog->transitionfrac < 0.0f) {
		rightcolour = g_MenuColourPalettes[dialog->type].unk08;
	} else {
		rightcolour = colourBlend(g_MenuColourPalettes[dialog->type2].unk08, g_MenuColourPalettes[dialog->type].unk08, dialog->colourweight);
	}

	// Right, left, bottom border
	gdl = menugfxDrawDialogBorderLine(gdl, x2 - 1, y1, x2, y2, rightcolour, rightcolour);
	gdl = menugfxDrawDialogBorderLine(gdl, x1, y1, x1 + 1, y2, leftcolour, leftcolour);
	gdl = menugfxDrawDialogBorderLine(gdl, x1, y2 - 1, x2, y2, leftcolour, rightcolour);

	return gdl;
}

GLOBAL_ASM(
glabel menugfxRenderBgGreenHaze
.late_rodata
glabel var7f1adf08
.word 0x40c907a9
glabel var7f1adf0c
.word 0x3e4ccccd
glabel var7f1adf10
.word 0x3f666666
glabel var7f1adf14
.word 0x3dcccccd
glabel var7f1adf18
.word 0x3dcccccd
.text
/*  f0e0fc0:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f0e0fc4:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0e0fc8:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0e0fcc:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0e0fd0:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0e0fd4:	afa40118 */ 	sw	$a0,0x118($sp)
/*  f0e0fd8:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0e0fdc:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0e0fe0:	00e09825 */ 	or	$s3,$a3,$zero
/*  f0e0fe4:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0e0fe8:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0e0fec:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0e0ff0:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0e0ff4:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0e0ff8:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0e0ffc:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f0e1000:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f0e1004:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f0e1008:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f0e100c:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0e1010:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0e1014:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0e1018:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e101c:	afa20110 */ 	sw	$v0,0x110($sp)
/*  f0e1020:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0e1024:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0e1028:	8fae0118 */ 	lw	$t6,0x118($sp)
/*  f0e102c:	3c18e700 */ 	lui	$t8,0xe700
/*  f0e1030:	3c0aba00 */ 	lui	$t2,0xba00
/*  f0e1034:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e1038:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f0e103c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0e1040:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e1044:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f0e1048:	354a1402 */ 	ori	$t2,$t2,0x1402
/*  f0e104c:	3c0db900 */ 	lui	$t5,0xb900
/*  f0e1050:	27290008 */ 	addiu	$t1,$t9,0x8
/*  f0e1054:	afa90118 */ 	sw	$t1,0x118($sp)
/*  f0e1058:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0e105c:	af2a0000 */ 	sw	$t2,0x0($t9)
/*  f0e1060:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f0e1064:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0e1068:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f0e106c:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f0e1070:	afac0118 */ 	sw	$t4,0x118($sp)
/*  f0e1074:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0e1078:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0e107c:	8fae0118 */ 	lw	$t6,0x118($sp)
/*  f0e1080:	37187e24 */ 	ori	$t8,$t8,0x7e24
/*  f0e1084:	2419f9fc */ 	addiu	$t9,$zero,-1540
/*  f0e1088:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e108c:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f0e1090:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e1094:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e1098:	8fa90118 */ 	lw	$t1,0x118($sp)
/*  f0e109c:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0e10a0:	240c3000 */ 	addiu	$t4,$zero,0x3000
/*  f0e10a4:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0e10a8:	afaa0118 */ 	sw	$t2,0x118($sp)
/*  f0e10ac:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f0e10b0:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0e10b4:	8fad0118 */ 	lw	$t5,0x118($sp)
/*  f0e10b8:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0e10bc:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f0e10c0:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e10c4:	afae0118 */ 	sw	$t6,0x118($sp)
/*  f0e10c8:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f0e10cc:	3c05800b */ 	lui	$a1,%hi(g_TexGeneralConfigs)
/*  f0e10d0:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0e10d4:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e10d8:	8ca5b5a8 */ 	lw	$a1,%lo(g_TexGeneralConfigs)($a1)
/*  f0e10dc:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0e10e0:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0e10e4:	0040b825 */ 	or	$s7,$v0,$zero
/*  f0e10e8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e10ec:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e10f0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e10f4:	27a40118 */ 	addiu	$a0,$sp,0x118
/*  f0e10f8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e10fc:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e1100:	0fc2ce70 */ 	jal	texSelect
/*  f0e1104:	24a50048 */ 	addiu	$a1,$a1,0x0048
/*  f0e1108:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f0e110c:	02060019 */ 	multu	$s0,$a2
/*  f0e1110:	8faa0118 */ 	lw	$t2,0x118($sp)
/*  f0e1114:	3c0cb900 */ 	lui	$t4,0xb900
/*  f0e1118:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f0e111c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e1120:	afab0118 */ 	sw	$t3,0x118($sp)
/*  f0e1124:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0e1128:	3c0d0050 */ 	lui	$t5,0x50
/*  f0e112c:	35ad4240 */ 	ori	$t5,$t5,0x4240
/*  f0e1130:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0e1134:	00002012 */ 	mflo	$a0
/*  f0e1138:	2407fff6 */ 	addiu	$a3,$zero,-10
/*  f0e113c:	a6e70004 */ 	sh	$a3,0x4($s7)
/*  f0e1140:	02460019 */ 	multu	$s2,$a2
/*  f0e1144:	86ee0004 */ 	lh	$t6,0x4($s7)
/*  f0e1148:	a6e40000 */ 	sh	$a0,0x0($s7)
/*  f0e114c:	a6e40030 */ 	sh	$a0,0x30($s7)
/*  f0e1150:	a6e70010 */ 	sh	$a3,0x10($s7)
/*  f0e1154:	a6ee0034 */ 	sh	$t6,0x34($s7)
/*  f0e1158:	02704823 */ 	subu	$t1,$s3,$s0
/*  f0e115c:	86ef0010 */ 	lh	$t7,0x10($s7)
/*  f0e1160:	0000b025 */ 	or	$s6,$zero,$zero
/*  f0e1164:	27b40104 */ 	addiu	$s4,$sp,0x104
/*  f0e1168:	00001012 */ 	mflo	$v0
/*  f0e116c:	a6e20002 */ 	sh	$v0,0x2($s7)
/*  f0e1170:	a6e20032 */ 	sh	$v0,0x32($s7)
/*  f0e1174:	02660019 */ 	multu	$s3,$a2
/*  f0e1178:	a6e2000e */ 	sh	$v0,0xe($s7)
/*  f0e117c:	a6e2003e */ 	sh	$v0,0x3e($s7)
/*  f0e1180:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0e1184:	02e08825 */ 	or	$s1,$s7,$zero
/*  f0e1188:	241e0030 */ 	addiu	$s8,$zero,0x30
/*  f0e118c:	00002812 */ 	mflo	$a1
/*  f0e1190:	a6e5000c */ 	sh	$a1,0xc($s7)
/*  f0e1194:	a6e5003c */ 	sh	$a1,0x3c($s7)
/*  f0e1198:	8fa30128 */ 	lw	$v1,0x128($sp)
/*  f0e119c:	a6e7001c */ 	sh	$a3,0x1c($s7)
/*  f0e11a0:	a6e70028 */ 	sh	$a3,0x28($s7)
/*  f0e11a4:	00660019 */ 	multu	$v1,$a2
/*  f0e11a8:	00725823 */ 	subu	$t3,$v1,$s2
/*  f0e11ac:	86f8001c */ 	lh	$t8,0x1c($s7)
/*  f0e11b0:	86f90028 */ 	lh	$t9,0x28($s7)
/*  f0e11b4:	a6e50048 */ 	sh	$a1,0x48($s7)
/*  f0e11b8:	a6e50018 */ 	sh	$a1,0x18($s7)
/*  f0e11bc:	a6e40054 */ 	sh	$a0,0x54($s7)
/*  f0e11c0:	a6e40024 */ 	sh	$a0,0x24($s7)
/*  f0e11c4:	a6ef0040 */ 	sh	$t7,0x40($s7)
/*  f0e11c8:	a6f8004c */ 	sh	$t8,0x4c($s7)
/*  f0e11cc:	00001012 */ 	mflo	$v0
/*  f0e11d0:	a6e2001a */ 	sh	$v0,0x1a($s7)
/*  f0e11d4:	a6e2004a */ 	sh	$v0,0x4a($s7)
/*  f0e11d8:	a6e20026 */ 	sh	$v0,0x26($s7)
/*  f0e11dc:	a6e20056 */ 	sh	$v0,0x56($s7)
/*  f0e11e0:	a6f90058 */ 	sh	$t9,0x58($s7)
/*  f0e11e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e11e8:	05210003 */ 	bgez	$t1,.L0f0e11f8
/*  f0e11ec:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0e11f0:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0e11f4:	00015043 */ 	sra	$t2,$at,0x1
.L0f0e11f8:
/*  f0e11f8:	448a2000 */ 	mtc1	$t2,$f4
/*  f0e11fc:	00000000 */ 	nop
/*  f0e1200:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e1204:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f0e1208:	05610003 */ 	bgez	$t3,.L0f0e1218
/*  f0e120c:	000b6043 */ 	sra	$t4,$t3,0x1
/*  f0e1210:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0e1214:	00016043 */ 	sra	$t4,$at,0x1
.L0f0e1218:
/*  f0e1218:	448c4000 */ 	mtc1	$t4,$f8
/*  f0e121c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e1220:	4481f000 */ 	mtc1	$at,$f30
/*  f0e1224:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e1228:	e7aa0098 */ 	swc1	$f10,0x98($sp)
.L0f0e122c:
/*  f0e122c:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0e1230:	c4201630 */ 	lwc1	$f0,%lo(var80061630)($at)
/*  f0e1234:	3c017f1b */ 	lui	$at,%hi(var7f1adf08)
/*  f0e1238:	c430df08 */ 	lwc1	$f16,%lo(var7f1adf08)($at)
/*  f0e123c:	24010030 */ 	addiu	$at,$zero,0x30
/*  f0e1240:	46008682 */ 	mul.s	$f26,$f16,$f0
/*  f0e1244:	16be0002 */ 	bne	$s5,$s8,.L0f0e1250
/*  f0e1248:	00000000 */ 	nop
/*  f0e124c:	4600d687 */ 	neg.s	$f26,$f26
.L0f0e1250:
/*  f0e1250:	16a10004 */ 	bne	$s5,$at,.L0f0e1264
/*  f0e1254:	3c013f00 */ 	lui	$at,0x3f00
/*  f0e1258:	44819000 */ 	mtc1	$at,$f18
/*  f0e125c:	00000000 */ 	nop
/*  f0e1260:	46120000 */ 	add.s	$f0,$f0,$f18
.L0f0e1264:
/*  f0e1264:	4600f03c */ 	c.lt.s	$f30,$f0
/*  f0e1268:	3c017f1b */ 	lui	$at,%hi(var7f1adf0c)
/*  f0e126c:	45000002 */ 	bc1f	.L0f0e1278
/*  f0e1270:	00000000 */ 	nop
/*  f0e1274:	461e0001 */ 	sub.s	$f0,$f0,$f30
.L0f0e1278:
/*  f0e1278:	c42cdf0c */ 	lwc1	$f12,%lo(var7f1adf0c)($at)
/*  f0e127c:	3c017f1b */ 	lui	$at,%hi(var7f1adf10)
/*  f0e1280:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0e1284:	00000000 */ 	nop
/*  f0e1288:	45000029 */ 	bc1f	.L0f0e1330
/*  f0e128c:	00000000 */ 	nop
/*  f0e1290:	460c0103 */ 	div.s	$f4,$f0,$f12
/*  f0e1294:	3c0142fe */ 	lui	$at,0x42fe
/*  f0e1298:	44813000 */ 	mtc1	$at,$f6
/*  f0e129c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0e12a0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e12a4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e12a8:	444df800 */ 	cfc1	$t5,$31
/*  f0e12ac:	44cef800 */ 	ctc1	$t6,$31
/*  f0e12b0:	00000000 */ 	nop
/*  f0e12b4:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0e12b8:	444ef800 */ 	cfc1	$t6,$31
/*  f0e12bc:	00000000 */ 	nop
/*  f0e12c0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0e12c4:	51c00013 */ 	beqzl	$t6,.L0f0e1314
/*  f0e12c8:	440e5000 */ 	mfc1	$t6,$f10
/*  f0e12cc:	44815000 */ 	mtc1	$at,$f10
/*  f0e12d0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0e12d4:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0e12d8:	44cef800 */ 	ctc1	$t6,$31
/*  f0e12dc:	00000000 */ 	nop
/*  f0e12e0:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0e12e4:	444ef800 */ 	cfc1	$t6,$31
/*  f0e12e8:	00000000 */ 	nop
/*  f0e12ec:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0e12f0:	15c00005 */ 	bnez	$t6,.L0f0e1308
/*  f0e12f4:	00000000 */ 	nop
/*  f0e12f8:	440e5000 */ 	mfc1	$t6,$f10
/*  f0e12fc:	3c018000 */ 	lui	$at,0x8000
/*  f0e1300:	10000007 */ 	b	.L0f0e1320
/*  f0e1304:	01c17025 */ 	or	$t6,$t6,$at
.L0f0e1308:
/*  f0e1308:	10000005 */ 	b	.L0f0e1320
/*  f0e130c:	240effff */ 	addiu	$t6,$zero,-1
/*  f0e1310:	440e5000 */ 	mfc1	$t6,$f10
.L0f0e1314:
/*  f0e1314:	00000000 */ 	nop
/*  f0e1318:	05c0fffb */ 	bltz	$t6,.L0f0e1308
/*  f0e131c:	00000000 */ 	nop
.L0f0e1320:
/*  f0e1320:	44cdf800 */ 	ctc1	$t5,$31
/*  f0e1324:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f0e1328:	10000033 */ 	b	.L0f0e13f8
/*  f0e132c:	4600f081 */ 	sub.s	$f2,$f30,$f0
.L0f0e1330:
/*  f0e1330:	c430df10 */ 	lwc1	$f16,%lo(var7f1adf10)($at)
/*  f0e1334:	3c017f1b */ 	lui	$at,%hi(var7f1adf14)
/*  f0e1338:	2419007f */ 	addiu	$t9,$zero,0x7f
/*  f0e133c:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0e1340:	00000000 */ 	nop
/*  f0e1344:	4502002b */ 	bc1fl	.L0f0e13f4
/*  f0e1348:	ae990000 */ 	sw	$t9,0x0($s4)
/*  f0e134c:	4600f081 */ 	sub.s	$f2,$f30,$f0
/*  f0e1350:	c432df14 */ 	lwc1	$f18,%lo(var7f1adf14)($at)
/*  f0e1354:	3c0142fe */ 	lui	$at,0x42fe
/*  f0e1358:	44813000 */ 	mtc1	$at,$f6
/*  f0e135c:	46121103 */ 	div.s	$f4,$f2,$f18
/*  f0e1360:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0e1364:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e1368:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e136c:	444ff800 */ 	cfc1	$t7,$31
/*  f0e1370:	44d8f800 */ 	ctc1	$t8,$31
/*  f0e1374:	00000000 */ 	nop
/*  f0e1378:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0e137c:	4458f800 */ 	cfc1	$t8,$31
/*  f0e1380:	00000000 */ 	nop
/*  f0e1384:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0e1388:	53000013 */ 	beqzl	$t8,.L0f0e13d8
/*  f0e138c:	44185000 */ 	mfc1	$t8,$f10
/*  f0e1390:	44815000 */ 	mtc1	$at,$f10
/*  f0e1394:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0e1398:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0e139c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0e13a0:	00000000 */ 	nop
/*  f0e13a4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0e13a8:	4458f800 */ 	cfc1	$t8,$31
/*  f0e13ac:	00000000 */ 	nop
/*  f0e13b0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0e13b4:	17000005 */ 	bnez	$t8,.L0f0e13cc
/*  f0e13b8:	00000000 */ 	nop
/*  f0e13bc:	44185000 */ 	mfc1	$t8,$f10
/*  f0e13c0:	3c018000 */ 	lui	$at,0x8000
/*  f0e13c4:	10000007 */ 	b	.L0f0e13e4
/*  f0e13c8:	0301c025 */ 	or	$t8,$t8,$at
.L0f0e13cc:
/*  f0e13cc:	10000005 */ 	b	.L0f0e13e4
/*  f0e13d0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0e13d4:	44185000 */ 	mfc1	$t8,$f10
.L0f0e13d8:
/*  f0e13d8:	00000000 */ 	nop
/*  f0e13dc:	0700fffb */ 	bltz	$t8,.L0f0e13cc
/*  f0e13e0:	00000000 */ 	nop
.L0f0e13e4:
/*  f0e13e4:	44cff800 */ 	ctc1	$t7,$31
/*  f0e13e8:	10000003 */ 	b	.L0f0e13f8
/*  f0e13ec:	ae980000 */ 	sw	$t8,0x0($s4)
/*  f0e13f0:	ae990000 */ 	sw	$t9,0x0($s4)
.L0f0e13f4:
/*  f0e13f4:	4600f081 */ 	sub.s	$f2,$f30,$f0
.L0f0e13f8:
/*  f0e13f8:	3c017f1b */ 	lui	$at,%hi(var7f1adf18)
/*  f0e13fc:	c430df18 */ 	lwc1	$f16,%lo(var7f1adf18)($at)
/*  f0e1400:	3c014170 */ 	lui	$at,0x4170
/*  f0e1404:	44812000 */ 	mtc1	$at,$f4
/*  f0e1408:	46101480 */ 	add.s	$f18,$f2,$f16
/*  f0e140c:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f0e1410:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e1414:	46049502 */ 	mul.s	$f20,$f18,$f4
/*  f0e1418:	00000000 */ 	nop
/*  f0e141c:	46143602 */ 	mul.s	$f24,$f6,$f20
/*  f0e1420:	0c0068f7 */ 	jal	sinf
/*  f0e1424:	4600c706 */ 	mov.s	$f28,$f24
/*  f0e1428:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0e142c:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e1430:	46144582 */ 	mul.s	$f22,$f8,$f20
/*  f0e1434:	00000000 */ 	nop
/*  f0e1438:	46160282 */ 	mul.s	$f10,$f0,$f22
/*  f0e143c:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e1440:	44128000 */ 	mfc1	$s2,$f16
/*  f0e1444:	00000000 */ 	nop
/*  f0e1448:	00125400 */ 	sll	$t2,$s2,0x10
/*  f0e144c:	0c0068f4 */ 	jal	cosf
/*  f0e1450:	000a9403 */ 	sra	$s2,$t2,0x10
/*  f0e1454:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e1458:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e145c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e1460:	44132000 */ 	mfc1	$s3,$f4
/*  f0e1464:	00000000 */ 	nop
/*  f0e1468:	00136c00 */ 	sll	$t5,$s3,0x10
/*  f0e146c:	0c0068f4 */ 	jal	cosf
/*  f0e1470:	000d9c03 */ 	sra	$s3,$t5,0x10
/*  f0e1474:	46160182 */ 	mul.s	$f6,$f0,$f22
/*  f0e1478:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e147c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e1480:	44104000 */ 	mfc1	$s0,$f8
/*  f0e1484:	00000000 */ 	nop
/*  f0e1488:	0010c400 */ 	sll	$t8,$s0,0x10
/*  f0e148c:	0c0068f7 */ 	jal	sinf
/*  f0e1490:	00188403 */ 	sra	$s0,$t8,0x10
/*  f0e1494:	46000287 */ 	neg.s	$f10,$f0
/*  f0e1498:	02d23023 */ 	subu	$a2,$s6,$s2
/*  f0e149c:	461c5402 */ 	mul.s	$f16,$f10,$f28
/*  f0e14a0:	00d05023 */ 	subu	$t2,$a2,$s0
/*  f0e14a4:	02d33823 */ 	subu	$a3,$s6,$s3
/*  f0e14a8:	02d22021 */ 	addu	$a0,$s6,$s2
/*  f0e14ac:	02d32821 */ 	addu	$a1,$s6,$s3
/*  f0e14b0:	a62a0008 */ 	sh	$t2,0x8($s1)
/*  f0e14b4:	26b50030 */ 	addiu	$s5,$s5,0x30
/*  f0e14b8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e14bc:	24010060 */ 	addiu	$at,$zero,0x60
/*  f0e14c0:	00907823 */ 	subu	$t7,$a0,$s0
/*  f0e14c4:	0090c821 */ 	addu	$t9,$a0,$s0
/*  f0e14c8:	440d9000 */ 	mfc1	$t5,$f18
/*  f0e14cc:	00d05021 */ 	addu	$t2,$a2,$s0
/*  f0e14d0:	26d60100 */ 	addiu	$s6,$s6,0x100
/*  f0e14d4:	00ed7023 */ 	subu	$t6,$a3,$t5
/*  f0e14d8:	00adc023 */ 	subu	$t8,$a1,$t5
/*  f0e14dc:	00ad4821 */ 	addu	$t1,$a1,$t5
/*  f0e14e0:	00ed5821 */ 	addu	$t3,$a3,$t5
/*  f0e14e4:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f0e14e8:	26310030 */ 	addiu	$s1,$s1,0x30
/*  f0e14ec:	a62effda */ 	sh	$t6,-0x26($s1)
/*  f0e14f0:	a62fffe4 */ 	sh	$t7,-0x1c($s1)
/*  f0e14f4:	a638ffe6 */ 	sh	$t8,-0x1a($s1)
/*  f0e14f8:	a639fff0 */ 	sh	$t9,-0x10($s1)
/*  f0e14fc:	a629fff2 */ 	sh	$t1,-0xe($s1)
/*  f0e1500:	a62afffc */ 	sh	$t2,-0x4($s1)
/*  f0e1504:	16a1ff49 */ 	bne	$s5,$at,.L0f0e122c
/*  f0e1508:	a62bfffe */ 	sh	$t3,-0x2($s1)
/*  f0e150c:	8fa40110 */ 	lw	$a0,0x110($sp)
/*  f0e1510:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f0e1514:	2403000c */ 	addiu	$v1,$zero,0xc
/*  f0e1518:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0e151c:	a2e00007 */ 	sb	$zero,0x7($s7)
/*  f0e1520:	a2e00013 */ 	sb	$zero,0x13($s7)
/*  f0e1524:	a2e2001f */ 	sb	$v0,0x1f($s7)
/*  f0e1528:	a2e2002b */ 	sb	$v0,0x2b($s7)
/*  f0e152c:	a2e30037 */ 	sb	$v1,0x37($s7)
/*  f0e1530:	a2e30043 */ 	sb	$v1,0x43($s7)
/*  f0e1534:	a2e5004f */ 	sb	$a1,0x4f($s7)
/*  f0e1538:	a2e5005b */ 	sb	$a1,0x5b($s7)
/*  f0e153c:	8fac0104 */ 	lw	$t4,0x104($sp)
/*  f0e1540:	3c0600af */ 	lui	$a2,0xaf
/*  f0e1544:	3c07ffff */ 	lui	$a3,0xffff
/*  f0e1548:	01866825 */ 	or	$t5,$t4,$a2
/*  f0e154c:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f0e1550:	8fae0104 */ 	lw	$t6,0x104($sp)
/*  f0e1554:	3c0d070c */ 	lui	$t5,0x70c
/*  f0e1558:	35ad0010 */ 	ori	$t5,$t5,0x10
/*  f0e155c:	01c77825 */ 	or	$t7,$t6,$a3
/*  f0e1560:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0e1564:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e1568:	0306c825 */ 	or	$t9,$t8,$a2
/*  f0e156c:	ac990008 */ 	sw	$t9,0x8($a0)
/*  f0e1570:	8fa90108 */ 	lw	$t1,0x108($sp)
/*  f0e1574:	01275025 */ 	or	$t2,$t1,$a3
/*  f0e1578:	ac8a000c */ 	sw	$t2,0xc($a0)
/*  f0e157c:	8fb00118 */ 	lw	$s0,0x118($sp)
/*  f0e1580:	260c0008 */ 	addiu	$t4,$s0,0x8
/*  f0e1584:	afac0118 */ 	sw	$t4,0x118($sp)
/*  f0e1588:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e158c:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f0e1590:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0e1594:	8fb10118 */ 	lw	$s1,0x118($sp)
/*  f0e1598:	3c180470 */ 	lui	$t8,0x470
/*  f0e159c:	37180060 */ 	ori	$t8,$t8,0x60
/*  f0e15a0:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f0e15a4:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f0e15a8:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0e15ac:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e15b0:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f0e15b4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0e15b8:	44812000 */ 	mtc1	$at,$f4
/*  f0e15bc:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0e15c0:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0e15c4:	c4261630 */ 	lwc1	$f6,%lo(var80061630)($at)
/*  f0e15c8:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0e15cc:	3c0eb100 */ 	lui	$t6,0xb100
/*  f0e15d0:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e15d4:	3c0f7654 */ 	lui	$t7,0x7654
/*  f0e15d8:	35ef3210 */ 	ori	$t7,$t7,0x3210
/*  f0e15dc:	35ce4602 */ 	ori	$t6,$t6,0x4602
/*  f0e15e0:	4500000b */ 	bc1f	.L0f0e1610
/*  f0e15e4:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0e15e8:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f0e15ec:	3c0ab100 */ 	lui	$t2,0xb100
/*  f0e15f0:	3c0b3210 */ 	lui	$t3,0x3210
/*  f0e15f4:	27290008 */ 	addiu	$t1,$t9,0x8
/*  f0e15f8:	afa90118 */ 	sw	$t1,0x118($sp)
/*  f0e15fc:	356b7654 */ 	ori	$t3,$t3,0x7654
/*  f0e1600:	354a0246 */ 	ori	$t2,$t2,0x246
/*  f0e1604:	af2a0000 */ 	sw	$t2,0x0($t9)
/*  f0e1608:	10000004 */ 	b	.L0f0e161c
/*  f0e160c:	af2b0004 */ 	sw	$t3,0x4($t9)
.L0f0e1610:
/*  f0e1610:	afad0118 */ 	sw	$t5,0x118($sp)
/*  f0e1614:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f0e1618:	ad8e0000 */ 	sw	$t6,0x0($t4)
.L0f0e161c:
/*  f0e161c:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0e1620:	8fa20118 */ 	lw	$v0,0x118($sp)
/*  f0e1624:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0e1628:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0e162c:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f0e1630:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f0e1634:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f0e1638:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f0e163c:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0e1640:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0e1644:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0e1648:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0e164c:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0e1650:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0e1654:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0e1658:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0e165c:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0e1660:	03e00008 */ 	jr	$ra
/*  f0e1664:	27bd0118 */ 	addiu	$sp,$sp,0x118
);

/**
 * This unused function renders an experimental menu background.
 *
 * The background consists of two layers of a green hazy texture.
 * Both layers spin slowly in opposite directions.
 */
// Mismatch: Regalloc, and a different approach is taken for the i == 1 checks.
//Gfx *menugfxRenderBgGreenHaze(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2)
//{
//	u32 *colours;
//	struct gfxvtx *vertices;
//	u32 alphas[2]; // 104
//	s32 i;
//	s16 t5;
//	s16 s0;
//	s16 s2;
//	s16 s3;
//	f32 f20;
//	f32 f22;
//	f32 f24;
//	f32 f26;
//	f32 f0;
//	f32 f2;
//	u32 stack[2];
//	struct gfxvtx *iter;
//
//	colours = gfxAllocateColours(4);
//	vertices = gfxAllocateVertices(8);
//
//	gDPPipeSync(gdl++);
//	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//	gDPSetAlphaCompare(gdl++, G_AC_NONE);
//	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
//	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
//	gDPSetTextureFilter(gdl++, G_TF_BILERP);
//
//	texSelect(&gdl, &g_TexGeneralConfigs[6], 2, 0, 2, 1, NULL);
//
//	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
//
//	vertices[4].x = vertices[0].x = x1 * 10;
//	vertices[4].y = vertices[0].y = y1 * 10;
//	vertices[4].z = vertices[0].z = -10;
//	vertices[5].x = vertices[1].x = x2 * 10;
//	vertices[5].y = vertices[1].y = y1 * 10;
//	vertices[5].z = vertices[1].z = -10;
//	vertices[6].x = vertices[2].x = x2 * 10;
//	vertices[6].y = vertices[2].y = y2 * 10;
//	vertices[6].z = vertices[2].z = -10;
//	vertices[7].x = vertices[3].x = x1 * 10;
//	vertices[7].y = vertices[3].y = y2 * 10;
//	vertices[7].z = vertices[3].z = -10;
//
//	for (i = 0; i < 2; i++) {
//		f0 = var80061630;
//		f26 = M_BADTAU * var80061630;
//
//		if (i == 1) {
//			f26 = -f26;
//		}
//
//		if (i == 1) {
//			f0 += 0.5f;
//		}
//
//		if (f0 > 1.0f) {
//			f0 -= 1.0f;
//		}
//
//		f2 = 1.0f - f0;
//
//		if (f0 < 0.2f) {
//			alphas[i] = f0 / 0.2f * 127.0f;
//		} else if (f0 > 0.9f) {
//			alphas[i] = f2 / 0.1f * 127.0f;
//		} else {
//			alphas[i] = 0x7f;
//		}
//
//		f20 = (f2 + 0.1f) * 15.0f;
//		f22 = (x2 - x1) / 2 * f20;
//		f24 = (y2 - y1) / 2 * f20;
//
//		s2 = sinf(f26) * f22;
//		s3 = cosf(f26) * f24;
//		s0 = cosf(f26) * f22;
//		t5 = -sinf(f26) * f24;
//
//		if (1);
//
//		iter = &vertices[i * 4];
//
//		iter[0].unk08 = i * 256 - s2 - s0;
//		iter[0].unk0a = i * 256 - s3 - t5;
//		iter[1].unk08 = i * 256 + s2 - s0;
//		iter[1].unk0a = i * 256 + s3 - t5;
//		iter[2].unk08 = i * 256 + s2 + s0;
//		iter[2].unk0a = i * 256 + s3 + t5;
//		iter[3].unk08 = i * 256 - s2 + s0;
//		iter[3].unk0a = i * 256 - s3 + t5;
//	}
//
//	vertices[0].colour = 0;
//	vertices[1].colour = 0;
//	vertices[2].colour = 4;
//	vertices[3].colour = 4;
//	vertices[4].colour = 12;
//	vertices[5].colour = 12;
//	vertices[6].colour = 8;
//	vertices[7].colour = 8;
//
//	colours[0] = 0x00af0000 | alphas[0];
//	colours[1] = 0xffff0000 | alphas[0];
//	colours[2] = 0x00af0000 | alphas[1];
//	colours[3] = 0xffff0000 | alphas[1];
//
//	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 4);
//	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 8);
//
//	if (var80061630 > 0.5f) {
//		gDPTri4(gdl++, 4, 5, 6, 6, 7, 4, 0, 1, 2, 2, 3, 0);
//	} else {
//		gDPTri4(gdl++, 0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4);
//	}
//
//	return gdl;
//}

Gfx *menugfxDrawDropdownBackground(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2)
{
	u32 *colours = gfxAllocateColours(3);
	struct gfxvtx *vertices = gfxAllocateVertices(6);
	u32 colour1;
	u32 colour2;

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);

	texSelect(&gdl, NULL, 2, 0, 2, true, NULL);

	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

	vertices[0].x = x1 * 10;
	vertices[0].y = y1 * 10;
	vertices[0].z = -10;

	vertices[1].x = x2 * 10;
	vertices[1].y = y1 * 10;
	vertices[1].z = -10;

	vertices[2].x = x1 * 10;
	vertices[2].y = (y2 + y1) / 2 * 10;
	vertices[2].z = -10;

	vertices[3].x = x2 * 10;
	vertices[3].y = (y2 + y1) / 2 * 10;
	vertices[3].z = -10;

	vertices[4].x = x1 * 10;
	vertices[4].y = y2 * 10;
	vertices[4].z = -10;

	vertices[5].x = x2 * 10;
	vertices[5].y = y2 * 10;
	vertices[5].z = -10;

	vertices[0].colour = 0;
	vertices[1].colour = 0;
	vertices[2].colour = 4;
	vertices[3].colour = 4;
	vertices[4].colour = 8;
	vertices[5].colour = 8;

	colour1 = text0f1543ac((x1 + x2) / 2, (y2 + y1) / 2, 0xffffffff) & 0xff;
	colour2 = (text0f1543ac((x1 + x2) / 2, (y2 + y1) / 2, 0xffffff7f) & 0xff) | 0x00006f00;

	colours[0] = colour1 | 0x00006f00;
	colours[1] = colour2;
	colours[2] = colour1 | 0x00003f00;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 3);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 6);

	gDPTri4(gdl++, 0, 1, 3, 3, 2, 0, 2, 3, 4, 4, 3, 5);

	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
// NTSC beta is non-matching, but a close match is shown here
#if VERSION >= VERSION_NTSC_1_0
Gfx *menugfxDrawListGroupHeader(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, s32 x3, u8 alpha)
#else
Gfx *menugfxDrawListGroupHeader(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, s32 x3)
#endif
{
	u32 *colours = gfxAllocateColours(7);
	struct gfxvtx *vertices = gfxAllocateVertices(9);
	u32 alpha1;
	u32 alpha2;

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);

	texSelect(&gdl, NULL, 2, 0, 2, 1, NULL);

	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

	vertices[0].x = x1 * 10;
	vertices[0].y = y1 * 10;
	vertices[0].z = -10;
	vertices[1].x = x2 * 10;
	vertices[1].y = y1 * 10;
	vertices[1].z = -10;
	vertices[2].x = x1 * 10;
	vertices[2].y = (y2 + y1) / 2 * 10;
	vertices[2].z = -10;
	vertices[3].x = x2 * 10;
	vertices[3].y = (y2 + y1) / 2 * 10;
	vertices[3].z = -10;
	vertices[4].x = x1 * 10;
	vertices[4].y = y2 * 10;
	vertices[4].z = -10;
	vertices[5].x = x2 * 10;
	vertices[5].y = y2 * 10;
	vertices[5].z = -10;
	vertices[6].x = x3 * 10;
	vertices[6].y = y1 * 10;
	vertices[6].z = -10;
	vertices[7].x = x3 * 10;
	vertices[7].y = (y2 + y1) / 2 * 10;
	vertices[7].z = -10;
	vertices[8].x = x3 * 10;
	vertices[8].y = y2 * 10;
	vertices[8].z = -10;

	vertices[0].colour = 0;
	vertices[1].colour = 24;
	vertices[2].colour = 4;
	vertices[3].colour = 4;
	vertices[4].colour = 8;
	vertices[5].colour = 8;
	vertices[6].colour = 12;
	vertices[7].colour = 16;
	vertices[8].colour = 20;

#if VERSION >= VERSION_NTSC_1_0
	alpha1 = alpha;
	alpha2 = alpha;
#else
	alpha1 = text0f1543ac((x2 + x1) / 2, (y2 + y1) / 2, 0xffffffff) & 0xff;
	alpha2 = text0f1543ac((x2 + x1) / 2, (y2 + y1) / 2, 0xffffff7f) & 0xff;
#endif

	colours[0] = 0x00006f00 | alpha1;
	colours[1] = 0x00006f00 | alpha2;
	colours[2] = 0x00003f00 | alpha2;
	colours[3] = 0xffffff00;
	colours[4] = (0x00006f00 | alpha2) & 0xffffff00;
	colours[5] = (0x00003f00 | alpha1) & 0xffffff00;
	colours[6] = 0x6f6f6f00 | alpha1;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 7);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 9);

	gDPTri4(gdl++, 0, 1, 3, 3, 2, 0, 2, 3, 4, 4, 3, 5);
	gDPTri4(gdl++, 1, 6, 7, 7, 3, 1, 3, 7, 8, 8, 5, 3);

	gdl = menugfxDrawShimmer(gdl, x1, y1, x2, y1 + 1, (alpha1 & 0xff) >> 2, 1, 0x28, 0);
	gdl = menugfxDrawShimmer(gdl, x1, y2, x2, y2 + 1, (alpha1 & 0xff) >> 2, 0, 0x28, 1);

	return gdl;
}
#else
GLOBAL_ASM(
glabel menugfxDrawListGroupHeader
/*  f0ded8c:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0ded90:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ded94:	afa40090 */ 	sw	$a0,0x90($sp)
/*  f0ded98:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f0ded9c:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f0deda0:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0deda4:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f0deda8:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f0dedac:	afa7009c */ 	sw	$a3,0x9c($sp)
/*  f0dedb0:	0fc588c3 */ 	jal	gfxAllocateColours
/*  f0dedb4:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0dedb8:	00408825 */ 	or	$s1,$v0,$zero
/*  f0dedbc:	0fc588a9 */ 	jal	gfxAllocateVertices
/*  f0dedc0:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0dedc4:	8fae0090 */ 	lw	$t6,0x90($sp)
/*  f0dedc8:	3c18e700 */ 	lui	$t8,0xe700
/*  f0dedcc:	00408025 */ 	or	$s0,$v0,$zero
/*  f0dedd0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0dedd4:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f0dedd8:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0deddc:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0dede0:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f0dede4:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0dede8:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f0dedec:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0dedf0:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f0dedf4:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0dedf8:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f0dedfc:	8fb80090 */ 	lw	$t8,0x90($sp)
/*  f0dee00:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0dee04:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f0dee08:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0dee0c:	afb90090 */ 	sw	$t9,0x90($sp)
/*  f0dee10:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0dee14:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f0dee18:	8faf0090 */ 	lw	$t7,0x90($sp)
/*  f0dee1c:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f0dee20:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f0dee24:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0dee28:	afb80090 */ 	sw	$t8,0x90($sp)
/*  f0dee2c:	240ef9fc */ 	addiu	$t6,$zero,-1540
/*  f0dee30:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0dee34:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0dee38:	8faf0090 */ 	lw	$t7,0x90($sp)
/*  f0dee3c:	3c19b600 */ 	lui	$t9,0xb600
/*  f0dee40:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f0dee44:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0dee48:	afb80090 */ 	sw	$t8,0x90($sp)
/*  f0dee4c:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0dee50:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0dee54:	8faf0090 */ 	lw	$t7,0x90($sp)
/*  f0dee58:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0dee5c:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f0dee60:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0dee64:	afb80090 */ 	sw	$t8,0x90($sp)
/*  f0dee68:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*  f0dee6c:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0dee70:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0dee74:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0dee78:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dee7c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0dee80:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0dee84:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0dee88:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0dee8c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dee90:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0dee94:	0fc2c5c8 */ 	jal	texSelect
/*  f0dee98:	00003825 */ 	or	$a3,$zero,$zero
/*  f0dee9c:	8fab0094 */ 	lw	$t3,0x94($sp)
/*  f0deea0:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0deea4:	8fac0098 */ 	lw	$t4,0x98($sp)
/*  f0deea8:	01640019 */ 	multu	$t3,$a0
/*  f0deeac:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f0deeb0:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f0deeb4:	8faa00a0 */ 	lw	$t2,0xa0($sp)
/*  f0deeb8:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0deebc:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0deec0:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f0deec4:	3c180050 */ 	lui	$t8,0x50
/*  f0deec8:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f0deecc:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f0deed0:	00002812 */ 	mflo	$a1
/*  f0deed4:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f0deed8:	af380004 */ 	sw	$t8,0x4($t9)
/*  f0deedc:	01840019 */ 	multu	$t4,$a0
/*  f0deee0:	03201825 */ 	or	$v1,$t9,$zero
/*  f0deee4:	014c9021 */ 	addu	$s2,$t2,$t4
/*  f0deee8:	2402fff6 */ 	addiu	$v0,$zero,-10
/*  f0deeec:	a6050000 */ 	sh	$a1,0x0($s0)
/*  f0deef0:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f0deef4:	a6020010 */ 	sh	$v0,0x10($s0)
/*  f0deef8:	a6050018 */ 	sh	$a1,0x18($s0)
/*  f0deefc:	a602001c */ 	sh	$v0,0x1c($s0)
/*  f0def00:	a6020028 */ 	sh	$v0,0x28($s0)
/*  f0def04:	00003012 */ 	mflo	$a2
/*  f0def08:	a6060002 */ 	sh	$a2,0x2($s0)
/*  f0def0c:	a606000e */ 	sh	$a2,0xe($s0)
/*  f0def10:	01a40019 */ 	multu	$t5,$a0
/*  f0def14:	a6050030 */ 	sh	$a1,0x30($s0)
/*  f0def18:	a6020034 */ 	sh	$v0,0x34($s0)
/*  f0def1c:	a6020040 */ 	sh	$v0,0x40($s0)
/*  f0def20:	240f0018 */ 	addiu	$t7,$zero,0x18
/*  f0def24:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0def28:	2418000c */ 	addiu	$t8,$zero,0xc
/*  f0def2c:	00003812 */ 	mflo	$a3
/*  f0def30:	a607000c */ 	sh	$a3,0xc($s0)
/*  f0def34:	06410003 */ 	bgez	$s2,.NB0f0def44
/*  f0def38:	0012c843 */ 	sra	$t9,$s2,0x1
/*  f0def3c:	26410001 */ 	addiu	$at,$s2,0x1
/*  f0def40:	0001c843 */ 	sra	$t9,$at,0x1
.NB0f0def44:
/*  f0def44:	03240019 */ 	multu	$t9,$a0
/*  f0def48:	a6070024 */ 	sh	$a3,0x24($s0)
/*  f0def4c:	a607003c */ 	sh	$a3,0x3c($s0)
/*  f0def50:	03209025 */ 	or	$s2,$t9,$zero
/*  f0def54:	24190010 */ 	addiu	$t9,$zero,0x10
/*  f0def58:	00004012 */ 	mflo	$t0
/*  f0def5c:	a608001a */ 	sh	$t0,0x1a($s0)
/*  f0def60:	a6080026 */ 	sh	$t0,0x26($s0)
/*  f0def64:	01440019 */ 	multu	$t2,$a0
/*  f0def68:	00001812 */ 	mflo	$v1
/*  f0def6c:	a6030032 */ 	sh	$v1,0x32($s0)
/*  f0def70:	a603003e */ 	sh	$v1,0x3e($s0)
/*  f0def74:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0def78:	a20f0013 */ 	sb	$t7,0x13($s0)
/*  f0def7c:	a606004a */ 	sh	$a2,0x4a($s0)
/*  f0def80:	01c40019 */ 	multu	$t6,$a0
/*  f0def84:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0def88:	a204001f */ 	sb	$a0,0x1f($s0)
/*  f0def8c:	a204002b */ 	sb	$a0,0x2b($s0)
/*  f0def90:	016d2021 */ 	addu	$a0,$t3,$t5
/*  f0def94:	a2050037 */ 	sb	$a1,0x37($s0)
/*  f0def98:	a2050043 */ 	sb	$a1,0x43($s0)
/*  f0def9c:	240e0014 */ 	addiu	$t6,$zero,0x14
/*  f0defa0:	a602004c */ 	sh	$v0,0x4c($s0)
/*  f0defa4:	a6080056 */ 	sh	$t0,0x56($s0)
/*  f0defa8:	00004812 */ 	mflo	$t1
/*  f0defac:	a6090048 */ 	sh	$t1,0x48($s0)
/*  f0defb0:	a6090054 */ 	sh	$t1,0x54($s0)
/*  f0defb4:	a6020058 */ 	sh	$v0,0x58($s0)
/*  f0defb8:	a6090060 */ 	sh	$t1,0x60($s0)
/*  f0defbc:	a6030062 */ 	sh	$v1,0x62($s0)
/*  f0defc0:	a6020064 */ 	sh	$v0,0x64($s0)
/*  f0defc4:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0defc8:	a218004f */ 	sb	$t8,0x4f($s0)
/*  f0defcc:	a219005b */ 	sb	$t9,0x5b($s0)
/*  f0defd0:	a20e0067 */ 	sb	$t6,0x67($s0)
/*  f0defd4:	04810003 */ 	bgez	$a0,.NB0f0defe4
/*  f0defd8:	00047843 */ 	sra	$t7,$a0,0x1
/*  f0defdc:	24810001 */ 	addiu	$at,$a0,0x1
/*  f0defe0:	00017843 */ 	sra	$t7,$at,0x1
.NB0f0defe4:
/*  f0defe4:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0defe8:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f0defec:	afb20044 */ 	sw	$s2,0x44($sp)
/*  f0deff0:	02402825 */ 	or	$a1,$s2,$zero
/*  f0deff4:	0fc53a82 */ 	jal	text0f1543ac
/*  f0deff8:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0deffc:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0df000:	305200ff */ 	andi	$s2,$v0,0xff
/*  f0df004:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0df008:	0fc53a82 */ 	jal	text0f1543ac
/*  f0df00c:	2406ff7f */ 	addiu	$a2,$zero,-129
/*  f0df010:	2406ff00 */ 	addiu	$a2,$zero,-256
/*  f0df014:	36586f00 */ 	ori	$t8,$s2,0x6f00
/*  f0df018:	304300ff */ 	andi	$v1,$v0,0xff
/*  f0df01c:	3c016f6f */ 	lui	$at,0x6f6f
/*  f0df020:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f0df024:	34796f00 */ 	ori	$t9,$v1,0x6f00
/*  f0df028:	36453f00 */ 	ori	$a1,$s2,0x3f00
/*  f0df02c:	34216f00 */ 	ori	$at,$at,0x6f00
/*  f0df030:	03267024 */ 	and	$t6,$t9,$a2
/*  f0df034:	00a67824 */ 	and	$t7,$a1,$a2
/*  f0df038:	0241c025 */ 	or	$t8,$s2,$at
/*  f0df03c:	ae390004 */ 	sw	$t9,0x4($s1)
/*  f0df040:	ae250008 */ 	sw	$a1,0x8($s1)
/*  f0df044:	ae26000c */ 	sw	$a2,0xc($s1)
/*  f0df048:	ae2e0010 */ 	sw	$t6,0x10($s1)
/*  f0df04c:	ae2f0014 */ 	sw	$t7,0x14($s1)
/*  f0df050:	ae380018 */ 	sw	$t8,0x18($s1)
/*  f0df054:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f0df058:	3c0f0718 */ 	lui	$t7,0x718
/*  f0df05c:	35ef001c */ 	ori	$t7,$t7,0x1c
/*  f0df060:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0df064:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f0df068:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f0df06c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0df070:	0c013100 */ 	jal	osVirtualToPhysical
/*  f0df074:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0df078:	8fa70060 */ 	lw	$a3,0x60($sp)
/*  f0df07c:	3c0e0480 */ 	lui	$t6,0x480
/*  f0df080:	35ce006c */ 	ori	$t6,$t6,0x6c
/*  f0df084:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f0df088:	8fb10090 */ 	lw	$s1,0x90($sp)
/*  f0df08c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0df090:	26390008 */ 	addiu	$t9,$s1,0x8
/*  f0df094:	afb90090 */ 	sw	$t9,0x90($sp)
/*  f0df098:	0c013100 */ 	jal	osVirtualToPhysical
/*  f0df09c:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f0df0a0:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0df0a4:	8faf0090 */ 	lw	$t7,0x90($sp)
/*  f0df0a8:	3c19b100 */ 	lui	$t9,0xb100
/*  f0df0ac:	3c0e3432 */ 	lui	$t6,0x3432
/*  f0df0b0:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0df0b4:	afb80090 */ 	sw	$t8,0x90($sp)
/*  f0df0b8:	35ce2310 */ 	ori	$t6,$t6,0x2310
/*  f0df0bc:	37395403 */ 	ori	$t9,$t9,0x5403
/*  f0df0c0:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0df0c4:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0df0c8:	8faf0090 */ 	lw	$t7,0x90($sp)
/*  f0df0cc:	3c0e5873 */ 	lui	$t6,0x5873
/*  f0df0d0:	3c19b100 */ 	lui	$t9,0xb100
/*  f0df0d4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0df0d8:	afb80090 */ 	sw	$t8,0x90($sp)
/*  f0df0dc:	37393817 */ 	ori	$t9,$t9,0x3817
/*  f0df0e0:	35ce3761 */ 	ori	$t6,$t6,0x3761
/*  f0df0e4:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0df0e8:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0df0ec:	8fa60098 */ 	lw	$a2,0x98($sp)
/*  f0df0f0:	325000ff */ 	andi	$s0,$s2,0xff
/*  f0df0f4:	0010c882 */ 	srl	$t9,$s0,0x2
/*  f0df0f8:	240f0028 */ 	addiu	$t7,$zero,0x28
/*  f0df0fc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0df100:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0df104:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0df108:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0df10c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0df110:	03208025 */ 	or	$s0,$t9,$zero
/*  f0df114:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0df118:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0df11c:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0df120:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f0df124:	0fc37fce */ 	jal	menugfxDrawShimmer
/*  f0df128:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f0df12c:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f0df130:	24190028 */ 	addiu	$t9,$zero,0x28
/*  f0df134:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0df138:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0df13c:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f0df140:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0df144:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f0df148:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0df14c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0df150:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f0df154:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0df158:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0df15c:	0fc37fce */ 	jal	menugfxDrawShimmer
/*  f0df160:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0df164:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0df168:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0df16c:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f0df170:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f0df174:	03e00008 */ 	jr	$ra
/*  f0df178:	27bd0090 */ 	addiu	$sp,$sp,0x90
);
#endif

GLOBAL_ASM(
glabel menugfxRenderGradient
/*  f0e1ce8:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0e1cec:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e1cf0:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0e1cf4:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0e1cf8:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0e1cfc:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f0e1d00:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f0e1d04:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f0e1d08:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0e1d0c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e1d10:	00408825 */ 	or	$s1,$v0,$zero
/*  f0e1d14:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0e1d18:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0e1d1c:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0e1d20:	3c18e700 */ 	lui	$t8,0xe700
/*  f0e1d24:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e1d28:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e1d2c:	afaf0060 */ 	sw	$t7,0x60($sp)
/*  f0e1d30:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0e1d34:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e1d38:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e1d3c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0e1d40:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f0e1d44:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0e1d48:	afad0060 */ 	sw	$t5,0x60($sp)
/*  f0e1d4c:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0e1d50:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0e1d54:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f0e1d58:	3c19b900 */ 	lui	$t9,0xb900
/*  f0e1d5c:	37390002 */ 	ori	$t9,$t9,0x2
/*  f0e1d60:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e1d64:	afb80060 */ 	sw	$t8,0x60($sp)
/*  f0e1d68:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0e1d6c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e1d70:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e1d74:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f0e1d78:	35ef7e24 */ 	ori	$t7,$t7,0x7e24
/*  f0e1d7c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e1d80:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e1d84:	2418f9fc */ 	addiu	$t8,$zero,-1540
/*  f0e1d88:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0e1d8c:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e1d90:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e1d94:	240f3000 */ 	addiu	$t7,$zero,0x3000
/*  f0e1d98:	3c0eb600 */ 	lui	$t6,0xb600
/*  f0e1d9c:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0e1da0:	afad0060 */ 	sw	$t5,0x60($sp)
/*  f0e1da4:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f0e1da8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0e1dac:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0e1db0:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0e1db4:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f0e1db8:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e1dbc:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0e1dc0:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*  f0e1dc4:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f0e1dc8:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0e1dcc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0e1dd0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0e1dd4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e1dd8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e1ddc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e1de0:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f0e1de4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e1de8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e1dec:	0fc2ce70 */ 	jal	texSelect
/*  f0e1df0:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e1df4:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e1df8:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f0e1dfc:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0e1e00:	8fa9006c */ 	lw	$t1,0x6c($sp)
/*  f0e1e04:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f0e1e08:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0e1e0c:	afad0060 */ 	sw	$t5,0x60($sp)
/*  f0e1e10:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0e1e14:	3c0f0050 */ 	lui	$t7,0x50
/*  f0e1e18:	018b4021 */ 	addu	$t0,$t4,$t3
/*  f0e1e1c:	35ef4240 */ 	ori	$t7,$t7,0x4240
/*  f0e1e20:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f0e1e24:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0e1e28:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f0e1e2c:	03201025 */ 	or	$v0,$t9,$zero
/*  f0e1e30:	05010003 */ 	bgez	$t0,.L0f0e1e40
/*  f0e1e34:	0008c043 */ 	sra	$t8,$t0,0x1
/*  f0e1e38:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0e1e3c:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0e1e40:
/*  f0e1e40:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f0e1e44:	012a2023 */ 	subu	$a0,$t1,$t2
/*  f0e1e48:	0099082a */ 	slt	$at,$a0,$t9
/*  f0e1e4c:	10200001 */ 	beqz	$at,.L0f0e1e54
/*  f0e1e50:	03004025 */ 	or	$t0,$t8,$zero
.L0f0e1e54:
/*  f0e1e54:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f0e1e58:	01460019 */ 	multu	$t2,$a2
/*  f0e1e5c:	2407fff6 */ 	addiu	$a3,$zero,-10
/*  f0e1e60:	a6070004 */ 	sh	$a3,0x4($s0)
/*  f0e1e64:	a6070010 */ 	sh	$a3,0x10($s0)
/*  f0e1e68:	a607001c */ 	sh	$a3,0x1c($s0)
/*  f0e1e6c:	a6070028 */ 	sh	$a3,0x28($s0)
/*  f0e1e70:	a6070034 */ 	sh	$a3,0x34($s0)
/*  f0e1e74:	a6070040 */ 	sh	$a3,0x40($s0)
/*  f0e1e78:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0e1e7c:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f0e1e80:	00001012 */ 	mflo	$v0
/*  f0e1e84:	a6020000 */ 	sh	$v0,0x0($s0)
/*  f0e1e88:	a6020024 */ 	sh	$v0,0x24($s0)
/*  f0e1e8c:	01860019 */ 	multu	$t4,$a2
/*  f0e1e90:	00001812 */ 	mflo	$v1
/*  f0e1e94:	a6030002 */ 	sh	$v1,0x2($s0)
/*  f0e1e98:	a603000e */ 	sh	$v1,0xe($s0)
/*  f0e1e9c:	01260019 */ 	multu	$t1,$a2
/*  f0e1ea0:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f0e1ea4:	a203001f */ 	sb	$v1,0x1f($s0)
/*  f0e1ea8:	a203002b */ 	sb	$v1,0x2b($s0)
/*  f0e1eac:	00002012 */ 	mflo	$a0
/*  f0e1eb0:	a604000c */ 	sh	$a0,0xc($s0)
/*  f0e1eb4:	a6040018 */ 	sh	$a0,0x18($s0)
/*  f0e1eb8:	01660019 */ 	multu	$t3,$a2
/*  f0e1ebc:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0e1ec0:	a2040037 */ 	sb	$a0,0x37($s0)
/*  f0e1ec4:	a2040043 */ 	sb	$a0,0x43($s0)
/*  f0e1ec8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e1ecc:	00002812 */ 	mflo	$a1
/*  f0e1ed0:	a605001a */ 	sh	$a1,0x1a($s0)
/*  f0e1ed4:	a6050026 */ 	sh	$a1,0x26($s0)
/*  f0e1ed8:	01460019 */ 	multu	$t2,$a2
/*  f0e1edc:	00006812 */ 	mflo	$t5
/*  f0e1ee0:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f0e1ee4:	00000000 */ 	nop
/*  f0e1ee8:	01060019 */ 	multu	$t0,$a2
/*  f0e1eec:	00001012 */ 	mflo	$v0
/*  f0e1ef0:	a6020032 */ 	sh	$v0,0x32($s0)
/*  f0e1ef4:	a602003e */ 	sh	$v0,0x3e($s0)
/*  f0e1ef8:	01260019 */ 	multu	$t1,$a2
/*  f0e1efc:	00007012 */ 	mflo	$t6
/*  f0e1f00:	a60e003c */ 	sh	$t6,0x3c($s0)
/*  f0e1f04:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0e1f08:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f0e1f0c:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f0e1f10:	3c0f0708 */ 	lui	$t7,0x708
/*  f0e1f14:	35ef000c */ 	ori	$t7,$t7,0xc
/*  f0e1f18:	ae380008 */ 	sw	$t8,0x8($s1)
/*  f0e1f1c:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f0e1f20:	ae390004 */ 	sw	$t9,0x4($s1)
/*  f0e1f24:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e1f28:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e1f2c:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e1f30:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e1f34:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e1f38:	afad0034 */ 	sw	$t5,0x34($sp)
/*  f0e1f3c:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0e1f40:	3c0d0450 */ 	lui	$t5,0x450
/*  f0e1f44:	35ad0048 */ 	ori	$t5,$t5,0x48
/*  f0e1f48:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0e1f4c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0e1f50:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e1f54:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e1f58:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0e1f5c:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0e1f60:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e1f64:	afb80030 */ 	sw	$t8,0x30($sp)
/*  f0e1f68:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f0e1f6c:	3c18b100 */ 	lui	$t8,0xb100
/*  f0e1f70:	3c195432 */ 	lui	$t9,0x5432
/*  f0e1f74:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0e1f78:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0e1f7c:	37394510 */ 	ori	$t9,$t9,0x4510
/*  f0e1f80:	37182405 */ 	ori	$t8,$t8,0x2405
/*  f0e1f84:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e1f88:	afaf0060 */ 	sw	$t7,0x60($sp)
/*  f0e1f8c:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e1f90:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e1f94:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e1f98:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0e1f9c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0e1fa0:	8fa20060 */ 	lw	$v0,0x60($sp)
/*  f0e1fa4:	03e00008 */ 	jr	$ra
/*  f0e1fa8:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

// Mismatch: Goal has the if statement with empty contents
//Gfx *menugfxRenderGradient(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colourstart, u32 colourmid, u32 colourend)
//{
//	u32 *colours = gfxAllocateColours(3);
//	struct gfxvtx *vertices = gfxAllocateVertices(6);
//	s32 ymid;
//
//	gDPPipeSync(gdl++);
//	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//	gDPSetAlphaCompare(gdl++, G_AC_NONE);
//	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
//	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
//	gDPSetTextureFilter(gdl++, G_TF_BILERP);
//
//	texSelect(&gdl, NULL, 2, 0, 2, 1, NULL);
//
//	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
//
//	ymid = (y1 + y2) / 2;
//
//	if (x2 - x1 < ymid * 2) {
//		ymid <<= 0;
//	}
//
//	// 0 = top left
//	// 1 = top right
//	// 2 = bottom right
//	// 3 = bottom left
//	// 4 = mid left
//	// 5 = mid right
//
//	vertices[0].z = -10;
//	vertices[1].z = -10;
//	vertices[2].z = -10;
//	vertices[3].z = -10;
//	vertices[4].z = -10;
//	vertices[5].z = -10;
//
//	vertices[0].x = x1 * 10;
//	vertices[0].y = y1 * 10;
//	vertices[0].colour = 0;
//
//	vertices[1].x = x2 * 10;
//	vertices[1].y = y1 * 10;
//	vertices[1].colour = 0;
//
//	vertices[2].x = x2 * 10;
//	vertices[2].y = y2 * 10;
//	vertices[2].colour = 4;
//
//	vertices[3].x = x1 * 10;
//	vertices[3].y = y2 * 10;
//	vertices[3].colour = 4;
//
//	vertices[4].x = x1 * 10;
//	vertices[4].y = ymid * 10;
//	vertices[4].colour = 8;
//
//	vertices[5].x = x2 * 10;
//	vertices[5].y = ymid * 10;
//	vertices[5].colour = 8;
//
//	colours[0] = colourstart;
//	colours[2] = colourmid;
//	colours[1] = colourend;
//
//	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 3);
//	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 6);
//	gDPTri4(gdl++, 0, 1, 5, 5, 4, 0, 2, 3, 4, 4, 5, 2);
//
//	return gdl;
//}

Gfx *menugfxRenderSlider(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, s32 markerx, u32 colour)
{
	u32 *colours = gfxAllocateColours(3);
	struct gfxvtx *vertices = gfxAllocateVertices(6);

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);

	texSelect(&gdl, NULL, 2, 0, 2, 1, NULL);

	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

	// Marker triangle
	vertices[0].x = markerx * 10 - 40;
	vertices[0].y = y2 * 10 - 80;
	vertices[0].z = -10;
	vertices[1].x = markerx * 10 + 40;
	vertices[1].y = y2 * 10 - 80;
	vertices[1].z = -10;
	vertices[2].x = markerx * 10;
	vertices[2].y = y2 * 10 + 10;
	vertices[2].z = -10;

	vertices[0].colour = 0;
	vertices[1].colour = 0;
	vertices[2].colour = 4;

	// Background triangle
	vertices[3].x = x1 * 10;
	vertices[3].y = y2 * 10;
	vertices[3].z = -10;
	vertices[4].x = (s16)(x2 * 10) - 40;
	vertices[4].y = y1 * 10;
	vertices[4].z = -10;
	vertices[5].x = x2 * 10;
	vertices[5].y = y2 * 10;
	vertices[5].z = -10;

	vertices[3].colour = 8;
	vertices[4].colour = 8;
	vertices[5].colour = 8;

	colours[0] = (colour & 0xffffff00) | 0x4f;
	colours[1] = 0xffffffff;
	colours[2] = 0x0000ff4f;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 3);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 6);

	gDPTri1(gdl++, 3, 4, 5);

	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

	gDPTri1(gdl++, 0, 1, 2);

	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

	// Line to the left of the marker: blue -> white gradient
	gdl = menugfxDrawLine(gdl, x1, y2, markerx, y2 + 1, 0x0000ffff, 0xffffffff);

	// Line to the right of the marker: solid blue
	gdl = menugfxDrawLine(gdl, markerx, y2, x2, y2 + 1, 0x0000ffff, 0x0000ffff);

	return gdl;
}

Gfx *menugfx0f0e2348(Gfx *gdl)
{
	gSPSetGeometryMode(gdl++, G_CULL_BACK);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPPipelineMode(gdl++, G_PM_1PRIMITIVE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
	gDPSetCombineKey(gdl++, G_CK_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetRenderMode(gdl++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
	gDPSetColorDither(gdl++, G_CD_MAGICSQ);
	gSPSetGeometryMode(gdl++, G_ZBUFFER);

	return gdl;
}

Gfx *menugfx0f0e2498(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH)

	texSelect(&gdl, 0, 2, 0, 2, 1, NULL);

	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

	return gdl;
}

Gfx *menugfxDrawTri2(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2, bool arg7)
{
	struct gfxvtx *vertices;
	u32 *colours;

	colours = gfxAllocateColours(2);
	vertices = gfxAllocateVertices(4);

	vertices[0].x = x1 * 10;
	vertices[0].y = y1 * 10;
	vertices[0].z = -10;

	vertices[1].x = x2 * 10;
	vertices[1].y = y1 * 10;
	vertices[1].z = -10;

	vertices[2].x = x2 * 10;
	vertices[2].y = y2 * 10;
	vertices[2].z = -10;

	vertices[3].x = x1 * 10;
	vertices[3].y = y2 * 10;
	vertices[3].z = -10;

	if (!arg7) {
		vertices[0].colour = 0;
		vertices[1].colour = 4;
		vertices[2].colour = 4;
		vertices[3].colour = 0;
	} else {
		vertices[0].colour = 0;
		vertices[1].colour = 0;
		vertices[2].colour = 4;
		vertices[3].colour = 4;
	}

	colours[0] = colour1;
	colours[1] = colour2;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);
	gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);

	return gdl;
}

Gfx *menugfxDrawLine(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2)
{
	gdl = menugfx0f0e2498(gdl);
	gdl = menugfxDrawTri2(gdl, x1, y1, x2, y2, colour1, colour2, false);

	return gdl;
}

GLOBAL_ASM(
glabel menugfxDrawTessellatedRect
/*  f0e2744:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0e2748:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0e274c:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f0e2750:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0e2754:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f0e2758:	00e0f025 */ 	or	$s8,$a3,$zero
/*  f0e275c:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f0e2760:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0e2764:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0e2768:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0e276c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0e2770:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0e2774:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0e2778:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0e277c:	0fc54f96 */ 	jal	textHasDiagonalBlend
/*  f0e2780:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0e2784:	104000ae */ 	beqz	$v0,.L0f0e2a40
/*  f0e2788:	8fb500b0 */ 	lw	$s5,0xb0($sp)
/*  f0e278c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f0e2790:	8fb700a8 */ 	lw	$s7,0xa8($sp)
/*  f0e2794:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e2798:	03c41023 */ 	subu	$v0,$s8,$a0
/*  f0e279c:	02f61823 */ 	subu	$v1,$s7,$s6
/*  f0e27a0:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e27a4:	10200053 */ 	beqz	$at,.L0f0e28f4
/*  f0e27a8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e27ac:	0061001a */ 	div	$zero,$v1,$at
/*  f0e27b0:	00008012 */ 	mflo	$s0
/*  f0e27b4:	afb00094 */ 	sw	$s0,0x94($sp)
/*  f0e27b8:	afb60080 */ 	sw	$s6,0x80($sp)
/*  f0e27bc:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e27c0:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e27c4:	0fc54fa5 */ 	jal	text0f153e94
/*  f0e27c8:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f0e27cc:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f0e27d0:	1a000038 */ 	blez	$s0,.L0f0e28b4
/*  f0e27d4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0e27d8:	02c08825 */ 	or	$s1,$s6,$zero
/*  f0e27dc:	02f69823 */ 	subu	$s3,$s7,$s6
/*  f0e27e0:	8fb500b0 */ 	lw	$s5,0xb0($sp)
.L0f0e27e4:
/*  f0e27e4:	2a610003 */ 	slti	$at,$s3,0x3
/*  f0e27e8:	10200008 */ 	beqz	$at,.L0f0e280c
/*  f0e27ec:	02209025 */ 	or	$s2,$s1,$zero
/*  f0e27f0:	02e09025 */ 	or	$s2,$s7,$zero
/*  f0e27f4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0e27f8:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0e27fc:	0fc54fa5 */ 	jal	text0f153e94
/*  f0e2800:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e2804:	10000019 */ 	b	.L0f0e286c
/*  f0e2808:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e280c:
/*  f0e280c:	02367023 */ 	subu	$t6,$s1,$s6
/*  f0e2810:	000e7a00 */ 	sll	$t7,$t6,0x8
/*  f0e2814:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f0e2818:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0e281c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0e2820:	01f8001a */ 	div	$zero,$t7,$t8
/*  f0e2824:	00003012 */ 	mflo	$a2
/*  f0e2828:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0e282c:	17000002 */ 	bnez	$t8,.L0f0e2838
/*  f0e2830:	00000000 */ 	nop
/*  f0e2834:	0007000d */ 	break	0x7
.L0f0e2838:
/*  f0e2838:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e283c:	17010004 */ 	bne	$t8,$at,.L0f0e2850
/*  f0e2840:	3c018000 */ 	lui	$at,0x8000
/*  f0e2844:	15e10002 */ 	bne	$t7,$at,.L0f0e2850
/*  f0e2848:	00000000 */ 	nop
/*  f0e284c:	0006000d */ 	break	0x6
.L0f0e2850:
/*  f0e2850:	0fc01a40 */ 	jal	colourBlend
/*  f0e2854:	00000000 */ 	nop
/*  f0e2858:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0e285c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e2860:	0fc54fa5 */ 	jal	text0f153e94
/*  f0e2864:	00403025 */ 	or	$a2,$v0,$zero
/*  f0e2868:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e286c:
/*  f0e286c:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0e2870:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0e2874:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f0e2878:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0e287c:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0e2880:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0e2884:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e2888:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e288c:	0fc38963 */ 	jal	menugfxDrawTri2
/*  f0e2890:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e2894:	8fa80094 */ 	lw	$t0,0x94($sp)
/*  f0e2898:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0e289c:	2631000f */ 	addiu	$s1,$s1,0xf
/*  f0e28a0:	2673fff1 */ 	addiu	$s3,$s3,-15
/*  f0e28a4:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0e28a8:	afb20080 */ 	sw	$s2,0x80($sp)
/*  f0e28ac:	1688ffcd */ 	bne	$s4,$t0,.L0f0e27e4
/*  f0e28b0:	afb0008c */ 	sw	$s0,0x8c($sp)
.L0f0e28b4:
/*  f0e28b4:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e28b8:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0e28bc:	0fc54fa5 */ 	jal	text0f153e94
/*  f0e28c0:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0e28c4:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f0e28c8:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0e28cc:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f0e28d0:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0e28d4:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0e28d8:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e28dc:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e28e0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e28e4:	0fc38963 */ 	jal	menugfxDrawTri2
/*  f0e28e8:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e28ec:	10000060 */ 	b	.L0f0e2a70
/*  f0e28f0:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0e28f4:
/*  f0e28f4:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e28f8:	0041001a */ 	div	$zero,$v0,$at
/*  f0e28fc:	00008012 */ 	mflo	$s0
/*  f0e2900:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f0e2904:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0e2908:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e290c:	0fc54fa5 */ 	jal	text0f153e94
/*  f0e2910:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f0e2914:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f0e2918:	1a000039 */ 	blez	$s0,.L0f0e2a00
/*  f0e291c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0e2920:	8fb1009c */ 	lw	$s1,0x9c($sp)
/*  f0e2924:	8fb500b0 */ 	lw	$s5,0xb0($sp)
/*  f0e2928:	03d19823 */ 	subu	$s3,$s8,$s1
.L0f0e292c:
/*  f0e292c:	2a610003 */ 	slti	$at,$s3,0x3
/*  f0e2930:	10200008 */ 	beqz	$at,.L0f0e2954
/*  f0e2934:	02209025 */ 	or	$s2,$s1,$zero
/*  f0e2938:	03c09025 */ 	or	$s2,$s8,$zero
/*  f0e293c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0e2940:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0e2944:	0fc54fa5 */ 	jal	text0f153e94
/*  f0e2948:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e294c:	1000001a */ 	b	.L0f0e29b8
/*  f0e2950:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e2954:
/*  f0e2954:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f0e2958:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f0e295c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0e2960:	022a5823 */ 	subu	$t3,$s1,$t2
/*  f0e2964:	000b6200 */ 	sll	$t4,$t3,0x8
/*  f0e2968:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0e296c:	018d001a */ 	div	$zero,$t4,$t5
/*  f0e2970:	00003012 */ 	mflo	$a2
/*  f0e2974:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0e2978:	15a00002 */ 	bnez	$t5,.L0f0e2984
/*  f0e297c:	00000000 */ 	nop
/*  f0e2980:	0007000d */ 	break	0x7
.L0f0e2984:
/*  f0e2984:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e2988:	15a10004 */ 	bne	$t5,$at,.L0f0e299c
/*  f0e298c:	3c018000 */ 	lui	$at,0x8000
/*  f0e2990:	15810002 */ 	bne	$t4,$at,.L0f0e299c
/*  f0e2994:	00000000 */ 	nop
/*  f0e2998:	0006000d */ 	break	0x6
.L0f0e299c:
/*  f0e299c:	0fc01a40 */ 	jal	colourBlend
/*  f0e29a0:	00000000 */ 	nop
/*  f0e29a4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e29a8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e29ac:	0fc54fa5 */ 	jal	text0f153e94
/*  f0e29b0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0e29b4:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e29b8:
/*  f0e29b8:	8fae006c */ 	lw	$t6,0x6c($sp)
/*  f0e29bc:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0e29c0:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f0e29c4:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0e29c8:	02403825 */ 	or	$a3,$s2,$zero
/*  f0e29cc:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e29d0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e29d4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e29d8:	0fc38963 */ 	jal	menugfxDrawTri2
/*  f0e29dc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e29e0:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0e29e4:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0e29e8:	2631000f */ 	addiu	$s1,$s1,0xf
/*  f0e29ec:	2673fff1 */ 	addiu	$s3,$s3,-15
/*  f0e29f0:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0e29f4:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0e29f8:	168fffcc */ 	bne	$s4,$t7,.L0f0e292c
/*  f0e29fc:	afb0006c */ 	sw	$s0,0x6c($sp)
.L0f0e2a00:
/*  f0e2a00:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e2a04:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0e2a08:	0fc54fa5 */ 	jal	text0f153e94
/*  f0e2a0c:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0e2a10:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f0e2a14:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0e2a18:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f0e2a1c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0e2a20:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0e2a24:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e2a28:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e2a2c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e2a30:	0fc38963 */ 	jal	menugfxDrawTri2
/*  f0e2a34:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e2a38:	1000000d */ 	b	.L0f0e2a70
/*  f0e2a3c:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0e2a40:
/*  f0e2a40:	8fb700a8 */ 	lw	$s7,0xa8($sp)
/*  f0e2a44:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f0e2a48:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0e2a4c:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f0e2a50:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0e2a54:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0e2a58:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f0e2a5c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e2a60:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e2a64:	0fc38963 */ 	jal	menugfxDrawTri2
/*  f0e2a68:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e2a6c:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0e2a70:
/*  f0e2a70:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0e2a74:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0e2a78:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0e2a7c:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0e2a80:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0e2a84:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0e2a88:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0e2a8c:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0e2a90:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0e2a94:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f0e2a98:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f0e2a9c:	03e00008 */ 	jr	$ra
/*  f0e2aa0:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

// Mismatch: Uses callee-save registers differently
//Gfx *menugfxDrawTessellatedRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2)
//{
//	if (textHasDiagonalBlend()) {
//		if (y2 - y1 > x2 - x1) {
//			// Portrait
//			s32 numfullparts; // 94
//			u32 nextcolour;
//			u32 thiscolour; // 8c
//			s32 i;
//			s32 nexty;
//			s32 thisy; // 80
//			u32 stack[2];
//
//			numfullparts = (y2 - y1) / 15;
//			thiscolour = text0f153e94(x1, y1, colour1);
//			thisy = y1;
//
//			for (i = 0; i < numfullparts; i++) {
//				nexty = y1 + i * 15;
//
//				if (y2 - nexty < 3) {
//					nexty = y2;
//					nextcolour = text0f153e94(x2, y2, colour2);
//				} else {
//					nextcolour = colourBlend(colour2, colour1, (nexty - y1) * 255 / (y2 - y1));
//					// @bug? Should y1 be x1?
//					nextcolour = text0f153e94(y1, thisy, nextcolour);
//				}
//
//				gdl = menugfxDrawTri2(gdl, x1, thisy, x2, nexty, thiscolour, nextcolour, false);
//
//				thisy = nexty;
//				thiscolour = nextcolour;
//			}
//
//			nextcolour = text0f153e94(x2, y2, colour2);
//			gdl = menugfxDrawTri2(gdl, x1, thisy, x2, y2, thiscolour, nextcolour, false);
//		} else {
//			// Landscape
//			// 8f4
//			s32 numfullparts; // 74
//			u32 nextcolour;
//			u32 thiscolour; // 6c
//			s32 i;
//			s32 nextx;
//			s32 thisx; // 60
//			u32 stack[1];
//
//			numfullparts = (x2 - x1) / 15;
//			thiscolour = text0f153e94(x1, y1, colour1);
//			thisx = x1;
//
//			for (i = 0; i < numfullparts; i++) {
//				nextx = x1 + i * 15;
//
//				if (x2 - nextx < 3) {
//					nextx = x2;
//					nextcolour = text0f153e94(x2, y2, colour2);
//				} else {
//					nextcolour = colourBlend(colour2, colour1, (nextx - x1) * 255 / (x2 - x1));
//					nextcolour = text0f153e94(thisx, y1, nextcolour);
//				}
//
//				gdl = menugfxDrawTri2(gdl, thisx, y1, nextx, y2, thiscolour, nextcolour, false);
//
//				thisx = nextx;
//				thiscolour = nextcolour;
//			}
//
//			nextcolour = text0f153e94(x2, y2, colour2);
//			gdl = menugfxDrawTri2(gdl, thisx, y1, x2, y2, thiscolour, nextcolour, false);
//		}
//	} else {
//		// a40
//		gdl = menugfxDrawTri2(gdl, x1, y1, x2, y2, colour1, colour2, false);
//	}
//
//	return gdl;
//}

/**
 * Consider rendering a shimmer effect along a line, based on timing.
 *
 * Also known as the white comets that travel along the dialog borders and
 * within some elements in the dialog.
 *
 * The given coordinates are the coordinates of the full line. Colour is the
 * natural colour of the line.
 *
 * The shimmer will go right to left or bottom to top unless the reverse
 * argument is set to true.
 */
Gfx *menugfxDrawShimmer(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour, bool arg6, s32 arg7, bool reverse)
{
	s32 shimmerleft;
	s32 shimmertop;
	s32 shimmerright;
	s32 shimmerbottom;
	s32 v0;
	s32 alpha;
	s32 minalpha;
	u32 tailcolour;

	alpha = 0;
	minalpha = 0;

	if (reverse) {
		v0 = 6.0f * var80061630 * 600.0f;
	} else {
		v0 = (1.0f - var80061630) * 6.0f * 600.0f;
	}

	if (y2 - y1 < x2 - x1) {
		// Horizontal
		v0 += (u32)(y1 + x1);
		v0 %= 600;
		shimmerleft = x1 + v0 - arg7;
		shimmerright = shimmerleft + arg7;

		if (shimmerleft < x1) {
			alpha = x1 - shimmerleft;
			shimmerleft = x1;
		}

		if (shimmerright > x2) {
			minalpha = shimmerright - x2;
			shimmerright = x2;
		}

		if (alpha < minalpha) {
			alpha = minalpha;
		}

		alpha = alpha * 255 / arg7;

		if (alpha > 255) {
			alpha = 255;
		}

		if (x1 <= shimmerright && x2 >= shimmerleft) {
			if (arg6) {
				gdl = menugfx0f0e2498(gdl);
			}

			tailcolour = ((((colour & 0xff) * (0xff - alpha)) / 255) & 0xff) | 0xffffff00;

			if (reverse) {
				// Left to right
				gdl = menugfxDrawTri2(gdl, shimmerleft, y1, shimmerright, y2, 0xffffff00, tailcolour, 0);
			} else {
				// Right to left
				gdl = menugfxDrawTri2(gdl, shimmerleft, y1, shimmerright, y2, tailcolour, 0xffffff00, 0);
			}
		}
	} else {
		// Vertical
		v0 += (u32)(y1 + x1);
		v0 %= 600;
		shimmertop = y1 + v0 - arg7;
		shimmerbottom = shimmertop + arg7;

		if (shimmertop < y1) {
			alpha = y1 - shimmertop;
			shimmertop = y1;
		}

		if (shimmerbottom > y2) {
			minalpha = shimmerbottom - y2;
			shimmerbottom = y2;
		}

		if (alpha < minalpha) {
			alpha = minalpha;
		}

		alpha = alpha * 255 / arg7;

		if (alpha > 255) {
			alpha = 255;
		}

		if (y1 <= shimmerbottom && y2 >= shimmertop) {
			if (arg6) {
				gdl = menugfx0f0e2498(gdl);
			}

			tailcolour = ((((colour & 0xff) * (0xff - alpha)) / 255) & 0xff) | 0xffffff00;

			if (reverse) {
				// Top to bottom
				gdl = menugfxDrawTri2(gdl, x1, shimmertop, x2, shimmerbottom, 0xffffff00, tailcolour, 1);
			} else {
				// Bottom to top
				gdl = menugfxDrawTri2(gdl, x1, shimmertop, x2, shimmerbottom, tailcolour, 0xffffff00, 1);
			}
		}
	}

	return gdl;
}

Gfx *menugfxDrawDialogBorderLine(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2)
{
	gdl = menugfxDrawLine(gdl, x1, y1, x2, y2, colour1, colour2);
	gdl = menugfxDrawShimmer(gdl, x1, y1, x2, y2, colour1, 0, 10, false);

	return gdl;
}

Gfx *menugfxDrawFilledRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2)
{
	gdl = menugfx0f0e2498(gdl);
	gdl = menugfxDrawTessellatedRect(gdl, x1, y1, x2, y2, colour1, colour2);
	gdl = menugfxDrawShimmer(gdl, x1, y1, x2, y2, colour1, 0, 10, false);

	return gdl;
}

/**
 * Draw a chevron/arrow using a simple triangle.
 *
 * Used for the left/right arrows on the Combat Simulator head/body selectors.
 *
 * The x and y arguments refer to the apex of the chevron. Size is the distance
 * from the apex to the opposite side.
 */
Gfx *menugfxDrawCarouselChevron(Gfx *gdl, s32 x, s32 y, s32 size, s32 direction, u32 colour1, u32 colour2)
{
	struct gfxvtx *vertices;
	u32 *colours;
	s16 halfwidth;
	s16 halfheight;
	s16 relx;
	s16 rely;

	relx = 0;
	rely = 0;
	halfwidth = 0;
	halfheight = 0;

	size *= 10;

	switch (direction) {
	case 0: // Down
		rely = -size;
		halfwidth = -size / 2;
		break;
	case 1: // Left
		relx = size;
		halfheight = -size / 2;
		break;
	case 2: // Up
		rely = size;
		halfwidth = size / 2;
		break;
	case 3: // Right
		relx = size * -1;
		halfheight = size / 2;
		break;
	}

	colours = gfxAllocateColours(2);
	vertices = gfxAllocateVertices(3);

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);

	texSelect(&gdl, NULL, 2, 0, 2, 1, NULL);

	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

	vertices[0].x = x * 10;
	vertices[0].y = y * 10;
	vertices[0].z = -10;

	vertices[1].x = x * 10 + relx + halfwidth;
	vertices[1].y = y * 10 + rely + halfheight;
	vertices[1].z = -10;

	vertices[2].x = x * 10 + relx - halfwidth;
	vertices[2].y = y * 10 + rely - halfheight;
	vertices[2].z = -10;

	vertices[0].colour = 0;
	vertices[1].colour = 4;
	vertices[2].colour = 4;

	colours[0] = colour1;
	colours[1] = colour2;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 3);
	gDPTri1(gdl++, 0, 1, 2);

	return gdl;
}

/**
 * Draw a chevron/arrow for dialogs.
 *
 * These chevons are drawn with two triangles, and the middle rear vertex's
 * position can be adjusted on each frame to create an animated chevron.
 *
 * The x and y arguments refer to the apex of the chevron. Size is the distance
 * from the apex to the opposite side.
 */
Gfx *menugfxDrawDialogChevron(Gfx *gdl, s32 x, s32 y, s32 size, s32 direction, u32 colour1, u32 colour2, f32 arg7)
{
	u32 stack;
	u32 *colours;
	struct gfxvtx *vertices;
	s16 halfwidth;
	s16 halfheight;
	s16 relx;
	s16 rely;

	relx = 0;
	rely = 0;
	halfwidth = 0;
	halfheight = 0;

	size *= 10;

	switch (direction) {
	case 0: // Down
		rely = -size;
		halfwidth = -((s32)(size * arg7 * 0.5f) + size) / 2;
		break;
	case 1: // Left
		relx = size;
		halfheight = -((s32)(size * arg7 * 0.5f) + size) / 2;
		break;
	case 2: // Up
		rely = size;
		halfwidth = ((s32)(size * arg7 * 0.5f) + size) / 2;
		break;
	case 3: // Right
		relx = -size;
		halfheight = ((s32)(size * arg7 * 0.5f) + size) / 2;
		break;
	}

	colours = gfxAllocateColours(2);
	vertices = gfxAllocateVertices(4);

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);

	texSelect(&gdl, NULL, 2, 0, 2, 1, NULL);

	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

	// Apex
	vertices[0].x = x * 10;
	vertices[0].y = y * 10;
	vertices[0].z = -10;

	vertices[1].x = x * 10 + relx + halfwidth;
	vertices[1].y = y * 10 + rely + halfheight;
	vertices[1].z = -10;

	vertices[2].x = x * 10 + relx - halfwidth;
	vertices[2].y = y * 10 + rely - halfheight;
	vertices[2].z = -10;

	relx = (relx / 3.0f + (relx * 1.5f * (1.0f - arg7)) / 3.0f);
	rely = rely / 3.0f + (rely * 1.5f * (1.0f - arg7)) / 3.0f;

	// Middle vertex
	vertices[3].x = x * 10 + relx;
	vertices[3].y = y * 10 + rely;
	vertices[3].z = -10;

	vertices[0].colour = 0;
	vertices[1].colour = 4;
	vertices[2].colour = 4;
	vertices[3].colour = 4;

	colours[0] = colour1;
	colours[1] = colour2;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);
	gDPTri2(gdl++, 0, 1, 3, 3, 2, 0);

	return gdl;
}

Gfx *menugfxDrawCheckbox(Gfx *gdl, s32 x, s32 y, s32 size, bool fill, u32 bordercolour, u32 fillcolour)
{
	if (fill) {
		gdl = textSetPrimColour(gdl, fillcolour);
		gDPFillRectangleScaled(gdl++, x, y, x + size, y + size);
		gdl = text0f153838(gdl);
	}

	gdl = textSetPrimColour(gdl, bordercolour);

	gDPFillRectangleScaled(gdl++, x, y, x + size + 1, y + 1);
	gDPFillRectangleScaled(gdl++, x, y + size, x + size + 1, y + size + 1);
	gDPFillRectangleScaled(gdl++, x, y + 1, x + 1, y + size);
	gDPFillRectangleScaled(gdl++, x + size, y + 1, x + size + 1, y + size);

	gdl = text0f153838(gdl);

	return gdl;
}

Gfx *menugfxRenderBgFailure(Gfx *gdl)
{
	f32 spb4;
	s32 i;
	f32 angle;
	s32 s0;
	s32 s1;
	s32 s2;
	s32 s3;
	s32 s6;
	s32 s7;
	u32 alpha1;
	u32 alpha2;

	spb4 = M_TAU * var80061630;

	var8009de98 = var8009de9c = 0;

	gdl = func0f0d4a3c(gdl, 0);

	var8009de90 = -100000;
	var8009de94 = 100000;

	gdl = func0f0d4d0c(gdl, -10000, 0, 10000, 0, 0x7f7f, 0x7f7f, 4);
	gdl = func0f0d4d0c(gdl, -10000, 300, 10000, 300, 0x7f7f, 0x7f7f, 4);

	for (i = 0; i < 3; i++) {
		angle = (2.0f * i * M_PI) / 3.0f + spb4;
		s6 = sinf(angle) * 600.0f;
		s3 = cosf(angle) * 600.0f;

		angle += 0.52359879016876f;
		s2 = sinf(angle) * 600.0f;
		s0 = cosf(angle) * 600.0f;

		angle += 0.52359879016876f;
		s1 = sinf(angle) * 600.0f;
		s7 = cosf(angle) * 600.0f;

		s6 += 160;
		s2 += 160;
		s1 += 160;
		s3 += 120;
		s0 += 120;
		s7 += 120;

		gdl = func0f0d4d0c(gdl, s6, s3, s2, s0, 0xff000040, 0xff00007f, 2);
		gdl = func0f0d4d0c(gdl, s2, s0, s1, s7, 0xff00007f, 0xff000040, 3);

		angle = -2.0f * spb4 + (2.0f * i * M_PI) / 3.0f;
		s6 = sinf(angle) * 600.0f;
		s3 = cosf(angle) * 600.0f;

		angle += 0.17453293502331f;
		s2 = sinf(angle) * 600.0f;
		s0 = cosf(angle) * 600.0f;

		angle += 0.099733099341393f;
		s1 = sinf(angle) * 600.0f;
		s7 = cosf(angle) * 600.0f;

		s6 += 160;
		s2 += 160;
		s1 += 160;
		s3 += 120;
		s0 += 120;
		s7 += 120;

		alpha1 = func0f006b54(4) * 127.0f;
		alpha2 = func0f006b54(4) * 55.0f;

		gdl = func0f0d4d0c(gdl, s6, s3, s2, s0, 0xffff0000 | alpha2, 0xffff0000 | alpha1, 2);
		gdl = func0f0d4d0c(gdl, s2, s0, s1, s7, 0xffff0000 | alpha1, 0xffff0000 | alpha2, 3);

		angle = -2.0f * spb4 + (2.0f * i * M_PI) / 3.0f + M_PI;
		s6 = sinf(angle) * 600.0f;
		s3 = cosf(angle) * 600.0f;

		angle += 0.17453293502331f;
		s2 = sinf(angle) * 600.0f;
		s0 = cosf(angle) * 600.0f;

		angle += 0.099733099341393f;
		s1 = sinf(angle) * 600.0f;
		s7 = cosf(angle) * 600.0f;

		s6 += 160;
		s2 += 160;
		s1 += 160;
		s3 += 120;
		s0 += 120;
		s7 += 120;

		alpha1 = (1.0f - func0f006b54(4)) * 99.0f;
		alpha2 = (1.0f - func0f006b54(4)) * 33.0f;

		gdl = func0f0d4d0c(gdl, s6, s3, s2, s0, 0xffffff00 | alpha2, 0xffffff00 | alpha1, 2);
		gdl = func0f0d4d0c(gdl, s2, s0, s1, s7, 0xffffff00 | alpha1, 0xffffff00 | alpha2, 3);
	}

	gdl = func0f0d4c80(gdl);

	return gdl;
}

GLOBAL_ASM(
glabel menugfxRenderBgCone
.late_rodata
glabel var7f1adf40
.word 0x40c90fdb
glabel var7f1adf44
.word 0x3f490fdb
glabel var7f1adf48
.word 0x40490fdb
glabel var7f1adf4c
.word 0x40c90fdb
.text
/*  f0e4190:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0e4194:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0e4198:	3c168006 */ 	lui	$s6,%hi(var80061630)
/*  f0e419c:	26d61630 */ 	addiu	$s6,$s6,%lo(var80061630)
/*  f0e41a0:	3c017f1b */ 	lui	$at,%hi(var7f1adf40)
/*  f0e41a4:	c424df40 */ 	lwc1	$f4,%lo(var7f1adf40)($at)
/*  f0e41a8:	c6c60000 */ 	lwc1	$f6,0x0($s6)
/*  f0e41ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e41b0:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f0e41b4:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f0e41b8:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0e41bc:	44816000 */ 	mtc1	$at,$f12
/*  f0e41c0:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0e41c4:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0e41c8:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0e41cc:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0e41d0:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f0e41d4:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0e41d8:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0e41dc:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f0e41e0:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f0e41e4:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f0e41e8:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f0e41ec:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0e41f0:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0e41f4:	0fc01ac2 */ 	jal	func0f006b08
/*  f0e41f8:	e7a8009c */ 	swc1	$f8,0x9c($sp)
/*  f0e41fc:	3c01437f */ 	lui	$at,0x437f
/*  f0e4200:	44815000 */ 	mtc1	$at,$f10
/*  f0e4204:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e4208:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e420c:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0e4210:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0e4214:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e4218:	444ef800 */ 	cfc1	$t6,$31
/*  f0e421c:	44d0f800 */ 	ctc1	$s0,$31
/*  f0e4220:	00000000 */ 	nop
/*  f0e4224:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0e4228:	4450f800 */ 	cfc1	$s0,$31
/*  f0e422c:	00000000 */ 	nop
/*  f0e4230:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0e4234:	52000013 */ 	beqzl	$s0,.L0f0e4284
/*  f0e4238:	44109000 */ 	mfc1	$s0,$f18
/*  f0e423c:	44819000 */ 	mtc1	$at,$f18
/*  f0e4240:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e4244:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0e4248:	44d0f800 */ 	ctc1	$s0,$31
/*  f0e424c:	00000000 */ 	nop
/*  f0e4250:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0e4254:	4450f800 */ 	cfc1	$s0,$31
/*  f0e4258:	00000000 */ 	nop
/*  f0e425c:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0e4260:	16000005 */ 	bnez	$s0,.L0f0e4278
/*  f0e4264:	00000000 */ 	nop
/*  f0e4268:	44109000 */ 	mfc1	$s0,$f18
/*  f0e426c:	3c018000 */ 	lui	$at,0x8000
/*  f0e4270:	10000007 */ 	b	.L0f0e4290
/*  f0e4274:	02018025 */ 	or	$s0,$s0,$at
.L0f0e4278:
/*  f0e4278:	10000005 */ 	b	.L0f0e4290
/*  f0e427c:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f0e4280:	44109000 */ 	mfc1	$s0,$f18
.L0f0e4284:
/*  f0e4284:	00000000 */ 	nop
/*  f0e4288:	0600fffb */ 	bltz	$s0,.L0f0e4278
/*  f0e428c:	00000000 */ 	nop
.L0f0e4290:
/*  f0e4290:	44cef800 */ 	ctc1	$t6,$31
/*  f0e4294:	00107c00 */ 	sll	$t7,$s0,0x10
/*  f0e4298:	0fc3528f */ 	jal	func0f0d4a3c
/*  f0e429c:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0e42a0:	3c18fffe */ 	lui	$t8,0xfffe
/*  f0e42a4:	37187960 */ 	ori	$t8,$t8,0x7960
/*  f0e42a8:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0e42ac:	ac38de90 */ 	sw	$t8,%lo(var8009de90)($at)
/*  f0e42b0:	3c190001 */ 	lui	$t9,0x1
/*  f0e42b4:	373986a0 */ 	ori	$t9,$t9,0x86a0
/*  f0e42b8:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0e42bc:	ac39de94 */ 	sw	$t9,%lo(var8009de94)($at)
/*  f0e42c0:	3c01ff00 */ 	lui	$at,0xff00
/*  f0e42c4:	3421007f */ 	ori	$at,$at,0x7f
/*  f0e42c8:	0201a025 */ 	or	$s4,$s0,$at
/*  f0e42cc:	3c017f1b */ 	lui	$at,%hi(var7f1adf44)
/*  f0e42d0:	c43edf44 */ 	lwc1	$f30,%lo(var7f1adf44)($at)
/*  f0e42d4:	3c013e00 */ 	lui	$at,0x3e00
/*  f0e42d8:	4481e000 */ 	mtc1	$at,$f28
/*  f0e42dc:	3c017f1b */ 	lui	$at,%hi(var7f1adf48)
/*  f0e42e0:	c43adf48 */ 	lwc1	$f26,%lo(var7f1adf48)($at)
/*  f0e42e4:	3c014416 */ 	lui	$at,0x4416
/*  f0e42e8:	4481c000 */ 	mtc1	$at,$f24
/*  f0e42ec:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e42f0:	00009825 */ 	or	$s3,$zero,$zero
.L0f0e42f4:
/*  f0e42f4:	44932000 */ 	mtc1	$s3,$f4
/*  f0e42f8:	c7b0009c */ 	lwc1	$f16,0x9c($sp)
/*  f0e42fc:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0e4300:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f0e4304:	461a3202 */ 	mul.s	$f8,$f6,$f26
/*  f0e4308:	00000000 */ 	nop
/*  f0e430c:	461c4282 */ 	mul.s	$f10,$f8,$f28
/*  f0e4310:	46105500 */ 	add.s	$f20,$f10,$f16
/*  f0e4314:	0c0068f7 */ 	jal	sinf
/*  f0e4318:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e431c:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e4320:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e4324:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e4328:	44112000 */ 	mfc1	$s1,$f4
/*  f0e432c:	0c0068f4 */ 	jal	cosf
/*  f0e4330:	00000000 */ 	nop
/*  f0e4334:	46180182 */ 	mul.s	$f6,$f0,$f24
/*  f0e4338:	461ea580 */ 	add.s	$f22,$f20,$f30
/*  f0e433c:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e4340:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e4344:	44124000 */ 	mfc1	$s2,$f8
/*  f0e4348:	0c0068f7 */ 	jal	sinf
/*  f0e434c:	00000000 */ 	nop
/*  f0e4350:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f0e4354:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e4358:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e435c:	44108000 */ 	mfc1	$s0,$f16
/*  f0e4360:	0c0068f4 */ 	jal	cosf
/*  f0e4364:	00000000 */ 	nop
/*  f0e4368:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e436c:	240e0008 */ 	addiu	$t6,$zero,0x8
/*  f0e4370:	262500a0 */ 	addiu	$a1,$s1,0xa0
/*  f0e4374:	260700a0 */ 	addiu	$a3,$s0,0xa0
/*  f0e4378:	26460078 */ 	addiu	$a2,$s2,0x78
/*  f0e437c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0e4380:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0e4384:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e4388:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f0e438c:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f0e4390:	440c2000 */ 	mfc1	$t4,$f4
/*  f0e4394:	00000000 */ 	nop
/*  f0e4398:	258d0078 */ 	addiu	$t5,$t4,0x78
/*  f0e439c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e43a0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e43a4:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0e43a8:	2a610008 */ 	slti	$at,$s3,0x8
/*  f0e43ac:	1420ffd1 */ 	bnez	$at,.L0f0e42f4
/*  f0e43b0:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e43b4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e43b8:	44816000 */ 	mtc1	$at,$f12
/*  f0e43bc:	0fc01ad5 */ 	jal	func0f006b54
/*  f0e43c0:	00000000 */ 	nop
/*  f0e43c4:	3c01437f */ 	lui	$at,0x437f
/*  f0e43c8:	44816000 */ 	mtc1	$at,$f12
/*  f0e43cc:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e43d0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e43d4:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f0e43d8:	46066201 */ 	sub.s	$f8,$f12,$f6
/*  f0e43dc:	444ff800 */ 	cfc1	$t7,$31
/*  f0e43e0:	44d0f800 */ 	ctc1	$s0,$31
/*  f0e43e4:	00000000 */ 	nop
/*  f0e43e8:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0e43ec:	4450f800 */ 	cfc1	$s0,$31
/*  f0e43f0:	00000000 */ 	nop
/*  f0e43f4:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0e43f8:	52000013 */ 	beqzl	$s0,.L0f0e4448
/*  f0e43fc:	44105000 */ 	mfc1	$s0,$f10
/*  f0e4400:	44815000 */ 	mtc1	$at,$f10
/*  f0e4404:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e4408:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0e440c:	44d0f800 */ 	ctc1	$s0,$31
/*  f0e4410:	00000000 */ 	nop
/*  f0e4414:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0e4418:	4450f800 */ 	cfc1	$s0,$31
/*  f0e441c:	00000000 */ 	nop
/*  f0e4420:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0e4424:	16000005 */ 	bnez	$s0,.L0f0e443c
/*  f0e4428:	00000000 */ 	nop
/*  f0e442c:	44105000 */ 	mfc1	$s0,$f10
/*  f0e4430:	3c018000 */ 	lui	$at,0x8000
/*  f0e4434:	10000007 */ 	b	.L0f0e4454
/*  f0e4438:	02018025 */ 	or	$s0,$s0,$at
.L0f0e443c:
/*  f0e443c:	10000005 */ 	b	.L0f0e4454
/*  f0e4440:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f0e4444:	44105000 */ 	mfc1	$s0,$f10
.L0f0e4448:
/*  f0e4448:	00000000 */ 	nop
/*  f0e444c:	0600fffb */ 	bltz	$s0,.L0f0e443c
/*  f0e4450:	00000000 */ 	nop
.L0f0e4454:
/*  f0e4454:	3c017f1b */ 	lui	$at,%hi(var7f1adf4c)
/*  f0e4458:	44cff800 */ 	ctc1	$t7,$31
/*  f0e445c:	c430df4c */ 	lwc1	$f16,%lo(var7f1adf4c)($at)
/*  f0e4460:	c6d20000 */ 	lwc1	$f18,0x0($s6)
/*  f0e4464:	3c01ff00 */ 	lui	$at,0xff00
/*  f0e4468:	0010c400 */ 	sll	$t8,$s0,0x10
/*  f0e446c:	46128082 */ 	mul.s	$f2,$f16,$f18
/*  f0e4470:	3421007f */ 	ori	$at,$at,0x7f
/*  f0e4474:	0301a025 */ 	or	$s4,$t8,$at
/*  f0e4478:	24160008 */ 	addiu	$s6,$zero,0x8
/*  f0e447c:	00009825 */ 	or	$s3,$zero,$zero
/*  f0e4480:	46001107 */ 	neg.s	$f4,$f2
/*  f0e4484:	e7a40078 */ 	swc1	$f4,0x78($sp)
.L0f0e4488:
/*  f0e4488:	44933000 */ 	mtc1	$s3,$f6
/*  f0e448c:	c7a80078 */ 	lwc1	$f8,0x78($sp)
/*  f0e4490:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f0e4494:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f0e4498:	461a5402 */ 	mul.s	$f16,$f10,$f26
/*  f0e449c:	00000000 */ 	nop
/*  f0e44a0:	461c8482 */ 	mul.s	$f18,$f16,$f28
/*  f0e44a4:	46124500 */ 	add.s	$f20,$f8,$f18
/*  f0e44a8:	0c0068f7 */ 	jal	sinf
/*  f0e44ac:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e44b0:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e44b4:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e44b8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e44bc:	44113000 */ 	mfc1	$s1,$f6
/*  f0e44c0:	0c0068f4 */ 	jal	cosf
/*  f0e44c4:	00000000 */ 	nop
/*  f0e44c8:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f0e44cc:	461ea580 */ 	add.s	$f22,$f20,$f30
/*  f0e44d0:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e44d4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e44d8:	44128000 */ 	mfc1	$s2,$f16
/*  f0e44dc:	0c0068f7 */ 	jal	sinf
/*  f0e44e0:	00000000 */ 	nop
/*  f0e44e4:	46180202 */ 	mul.s	$f8,$f0,$f24
/*  f0e44e8:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e44ec:	4600448d */ 	trunc.w.s	$f18,$f8
/*  f0e44f0:	44109000 */ 	mfc1	$s0,$f18
/*  f0e44f4:	0c0068f4 */ 	jal	cosf
/*  f0e44f8:	00000000 */ 	nop
/*  f0e44fc:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e4500:	240d0009 */ 	addiu	$t5,$zero,0x9
/*  f0e4504:	262500a0 */ 	addiu	$a1,$s1,0xa0
/*  f0e4508:	260700a0 */ 	addiu	$a3,$s0,0xa0
/*  f0e450c:	26460078 */ 	addiu	$a2,$s2,0x78
/*  f0e4510:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e4514:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0e4518:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e451c:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f0e4520:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f0e4524:	440b3000 */ 	mfc1	$t3,$f6
/*  f0e4528:	00000000 */ 	nop
/*  f0e452c:	256c0078 */ 	addiu	$t4,$t3,0x78
/*  f0e4530:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4534:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e4538:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0e453c:	1676ffd2 */ 	bne	$s3,$s6,.L0f0e4488
/*  f0e4540:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e4544:	0fc35320 */ 	jal	func0f0d4c80
/*  f0e4548:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e454c:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f0e4550:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0e4554:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0e4558:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f0e455c:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f0e4560:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f0e4564:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f0e4568:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0e456c:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0e4570:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0e4574:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0e4578:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0e457c:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0e4580:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0e4584:	03e00008 */ 	jr	$ra
/*  f0e4588:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

// Mismatch: Float regalloc
//Gfx *menugfxRenderBgCone(Gfx *gdl)
//{
//	f32 sp9c;
//	u32 stack[2];
//	f32 angle;
//	s32 x1;
//	s32 y1;
//	s32 x2;
//	s32 y2;
//	u32 s0;
//	f32 sp78;
//	s32 colour;
//	s32 i;
//
//	angle = M_BADTAU * var80061630;
//	sp9c = angle * 2.0f;
//	s0 = (u32)(func0f006b08(1) * 255.0f) << 16;
//
//	gdl = func0f0d4a3c(gdl, 0);
//
//	colour = s0 | 0xff00007f;
//
//	var8009de90 = -100000;
//	var8009de94 = 100000;
//
//	for (i = 0; i < 8; i++) {
//		angle = sp9c + i * 2.0f * M_PI * 0.125f;
//
//		x1 = 600.0f * sinf(angle);
//		y1 = 600.0f * cosf(angle);
//		x2 = 600.0f * sinf(angle + 0.78539818525314f);
//		y2 = 600.0f * cosf(angle + 0.78539818525314f);
//
//		x1 += 160;
//		x2 += 160;
//		y1 += 120;
//		y2 += 120;
//
//		gdl = func0f0d4d0c(gdl, x1, y1, x2, y2, colour, colour, 8);
//	}
//
//	s0 = (u32)(255.0f - func0f006b54(1) * 255.0f) << 16;
//
//	if (M_BADTAU * var80061630);
//	angle = M_BADTAU * var80061630;
//	sp78 = -angle;
//
//	colour = s0 | 0xff00007f;
//
//	for (i = 0; i < 8; i++) {
//		angle = sp78 + 2.0f * i * M_PI * 0.125f;
//
//		x1 = 600.0f * sinf(angle);
//		y1 = 600.0f * cosf(angle);
//		x2 = 600.0f * sinf(angle + 0.78539818525314f);
//		y2 = 600.0f * cosf(angle + 0.78539818525314f);
//
//		x1 += 160;
//		x2 += 160;
//		y1 += 120;
//		y2 += 120;
//
//		gdl = func0f0d4d0c(gdl, x1, y1, x2, y2, colour, colour, 9);
//	}
//
//	gdl = func0f0d4c80(gdl);
//
//	return gdl;
//}

/**
 * Fill the framebuffer with a transparent green overlay.
 *
 * The amount of transparency varies from frame to frame. It's quite volatile.
 *
 * This function is not called.
 */
Gfx *func0f0e458c(Gfx *gdl)
{
	var8009de98 = 0;
	var8009de9c = -20 - viGetHeight() / 2;

	gdl = func0f0d4a3c(gdl, 0);

	var8009de90 = -100000;
	var8009de94 = 100000;

	gdl = func0f0d4d0c(gdl, -1000, viGetHeight() + 10, 2000, viGetHeight() + 10, 0x00ff00bf, 0x00ff00bf, 6);
	gdl = func0f0d4d0c(gdl, -1000, viGetHeight() + 10, 2000, viGetHeight() + 10, 0xffff00af, 0xffff00af, 5);
	gdl = func0f0d4c80(gdl);

	var8009de98 = var8009de9c = 0;

	return gdl;
}

GLOBAL_ASM(
glabel func0f0e46b0
/*  f0e46b0:	3c0e800a */ 	lui	$t6,%hi(var8009de9c)
/*  f0e46b4:	8dcede9c */ 	lw	$t6,%lo(var8009de9c)($t6)
/*  f0e46b8:	44803000 */ 	mtc1	$zero,$f6
/*  f0e46bc:	3c014370 */ 	lui	$at,0x4370
/*  f0e46c0:	25cf0078 */ 	addiu	$t7,$t6,0x78
/*  f0e46c4:	448f2000 */ 	mtc1	$t7,$f4
/*  f0e46c8:	44856000 */ 	mtc1	$a1,$f12
/*  f0e46cc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0e46d0:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0e46d4:	44812000 */ 	mtc1	$at,$f4
/*  f0e46d8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0e46dc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e46e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e46e4:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0e46e8:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0e46ec:	46086282 */ 	mul.s	$f10,$f12,$f8
/*  f0e46f0:	00000000 */ 	nop
/*  f0e46f4:	46066202 */ 	mul.s	$f8,$f12,$f6
/*  f0e46f8:	460a0400 */ 	add.s	$f16,$f0,$f10
/*  f0e46fc:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f0e4700:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e4704:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e4708:	44069000 */ 	mfc1	$a2,$f18
/*  f0e470c:	44108000 */ 	mfc1	$s0,$f16
/*  f0e4710:	0fc3528f */ 	jal	func0f0d4a3c
/*  f0e4714:	afa60034 */ 	sw	$a2,0x34($sp)
/*  f0e4718:	3c08fffe */ 	lui	$t0,0xfffe
/*  f0e471c:	35087960 */ 	ori	$t0,$t0,0x7960
/*  f0e4720:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0e4724:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0e4728:	3c03ffff */ 	lui	$v1,0xffff
/*  f0e472c:	ac28de90 */ 	sw	$t0,%lo(var8009de90)($at)
/*  f0e4730:	3c090001 */ 	lui	$t1,0x1
/*  f0e4734:	3463007f */ 	ori	$v1,$v1,0x7f
/*  f0e4738:	352986a0 */ 	ori	$t1,$t1,0x86a0
/*  f0e473c:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0e4740:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f0e4744:	ac29de94 */ 	sw	$t1,%lo(var8009de94)($at)
/*  f0e4748:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0e474c:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e4750:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e4754:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4758:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e475c:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e4760:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4764:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f0e4768:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0e476c:	3c0300aa */ 	lui	$v1,0xaa
/*  f0e4770:	3463007f */ 	ori	$v1,$v1,0x7f
/*  f0e4774:	240b0006 */ 	addiu	$t3,$zero,0x6
/*  f0e4778:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0e477c:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e4780:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e4784:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4788:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e478c:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e4790:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4794:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f0e4798:	3c03ffff */ 	lui	$v1,0xffff
/*  f0e479c:	3463007f */ 	ori	$v1,$v1,0x7f
/*  f0e47a0:	240c0005 */ 	addiu	$t4,$zero,0x5
/*  f0e47a4:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e47a8:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e47ac:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e47b0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e47b4:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e47b8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e47bc:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e47c0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e47c4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e47c8:	3c0300aa */ 	lui	$v1,0xaa
/*  f0e47cc:	3463007f */ 	ori	$v1,$v1,0x7f
/*  f0e47d0:	240d0006 */ 	addiu	$t5,$zero,0x6
/*  f0e47d4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e47d8:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e47dc:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e47e0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e47e4:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e47e8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e47ec:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e47f0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e47f4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e47f8:	0fc35320 */ 	jal	func0f0d4c80
/*  f0e47fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4800:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e4804:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0e4808:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0e480c:	03e00008 */ 	jr	$ra
/*  f0e4810:	00000000 */ 	nop
);

// Mismatch: Too much stack
//Gfx *func0f0e46b0(Gfx *gdl, f32 arg1)
//{
//	s32 y1;
//	s32 y2;
//	f32 value;
//
//	value = var8009de9c + 120;
//
//	y1 = (f32)value + arg1 * (0 - value);
//	y2 = (f32)value + arg1 * (240 - value);
//
//	if (y1);
//	if (y2);
//
//	gdl = func0f0d4a3c(gdl, 0);
//
//	var8009de90 = -100000;
//	var8009de94 = 100000;
//
//	gdl = func0f0d4d0c(gdl, -1000, y1, 2000, y1, 0xffff007f, 0xffff007f, 5);
//	gdl = func0f0d4d0c(gdl, -1000, y1, 2000, y1, 0x00aa007f, 0x00aa007f, 6);
//	gdl = func0f0d4d0c(gdl, -1000, y2, 2000, y2, 0xffff007f, 0xffff007f, 5);
//	gdl = func0f0d4d0c(gdl, -1000, y2, 2000, y2, 0x00aa007f, 0x00aa007f, 6);
//
//	gdl = func0f0d4c80(gdl);
//
//	return gdl;
//}

/**
 * This is an exact copy of menugfxRenderBgFailure.
 */
Gfx *menugfxRenderBgFailureCopy(Gfx *gdl)
{
	f32 spb4;
	s32 i;
	f32 angle;
	s32 s0;
	s32 s1;
	s32 s2;
	s32 s3;
	s32 s6;
	s32 s7;
	u32 alpha1;
	u32 alpha2;

	spb4 = M_TAU * var80061630;

	var8009de98 = var8009de9c = 0;

	gdl = func0f0d4a3c(gdl, 0);

	var8009de90 = -100000;
	var8009de94 = 100000;

	gdl = func0f0d4d0c(gdl, -10000, 0, 10000, 0, 0x7f7f, 0x7f7f, 4);
	gdl = func0f0d4d0c(gdl, -10000, 300, 10000, 300, 0x7f7f, 0x7f7f, 4);

	for (i = 0; i < 3; i++) {
		angle = (2.0f * i * M_PI) / 3.0f + spb4;
		s6 = sinf(angle) * 600.0f;
		s3 = cosf(angle) * 600.0f;

		angle += 0.52359879016876f;
		s2 = sinf(angle) * 600.0f;
		s0 = cosf(angle) * 600.0f;

		angle += 0.52359879016876f;
		s1 = sinf(angle) * 600.0f;
		s7 = cosf(angle) * 600.0f;

		s6 += 160;
		s2 += 160;
		s1 += 160;
		s3 += 120;
		s0 += 120;
		s7 += 120;

		gdl = func0f0d4d0c(gdl, s6, s3, s2, s0, 0xff000040, 0xff00007f, 2);
		gdl = func0f0d4d0c(gdl, s2, s0, s1, s7, 0xff00007f, 0xff000040, 3);

		angle = -2.0f * spb4 + (2.0f * i * M_PI) / 3.0f;
		s6 = sinf(angle) * 600.0f;
		s3 = cosf(angle) * 600.0f;

		angle += 0.17453293502331f;
		s2 = sinf(angle) * 600.0f;
		s0 = cosf(angle) * 600.0f;

		angle += 0.099733099341393f;
		s1 = sinf(angle) * 600.0f;
		s7 = cosf(angle) * 600.0f;

		s6 += 160;
		s2 += 160;
		s1 += 160;
		s3 += 120;
		s0 += 120;
		s7 += 120;

		alpha1 = func0f006b54(4) * 127.0f;
		alpha2 = func0f006b54(4) * 55.0f;

		gdl = func0f0d4d0c(gdl, s6, s3, s2, s0, 0xffff0000 | alpha2, 0xffff0000 | alpha1, 2);
		gdl = func0f0d4d0c(gdl, s2, s0, s1, s7, 0xffff0000 | alpha1, 0xffff0000 | alpha2, 3);

		angle = -2.0f * spb4 + (2.0f * i * M_PI) / 3.0f + M_PI;
		s6 = sinf(angle) * 600.0f;
		s3 = cosf(angle) * 600.0f;

		angle += 0.17453293502331f;
		s2 = sinf(angle) * 600.0f;
		s0 = cosf(angle) * 600.0f;

		angle += 0.099733099341393f;
		s1 = sinf(angle) * 600.0f;
		s7 = cosf(angle) * 600.0f;

		s6 += 160;
		s2 += 160;
		s1 += 160;
		s3 += 120;
		s0 += 120;
		s7 += 120;

		alpha1 = (1.0f - func0f006b54(4)) * 99.0f;
		alpha2 = (1.0f - func0f006b54(4)) * 33.0f;

		gdl = func0f0d4d0c(gdl, s6, s3, s2, s0, 0xffffff00 | alpha2, 0xffffff00 | alpha1, 2);
		gdl = func0f0d4d0c(gdl, s2, s0, s1, s7, 0xffffff00 | alpha1, 0xffffff00 | alpha2, 3);
	}

	gdl = func0f0d4c80(gdl);

	return gdl;
}

void menugfx0f0e4fd4(void)
{
	var80071184 = 0;
}

u32 menugfx0f0e4fe0(void)
{
	return align16(0xd20);
}

#if VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel menugfxRenderBgSuccess
.late_rodata
glabel var7f1adf74
.word 0x459c4000
glabel var7f1adf78
.word 0x461c4000
glabel var7f1adf7c
.word 0x461c4000
glabel var7f1adf80
.word 0x459c4000
glabel var7f1adf84
.word 0x40c907a9
glabel var7f1adf88
.word 0xc5ce4000
glabel var7f1adf8c
.word 0x40c907a9
glabel var7f1adf90
.word 0x45ce4000
.text
/*  f0e5000:	27bdfeb0 */ 	addiu	$sp,$sp,-336
/*  f0e5004:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0e5008:	3c0e8008 */ 	lui	$t6,%hi(g_StageIndex)
/*  f0e500c:	44812000 */ 	mtc1	$at,$f4
/*  f0e5010:	8dcefc00 */ 	lw	$t6,%lo(g_StageIndex)($t6)
/*  f0e5014:	24010019 */ 	addiu	$at,$zero,0x19
/*  f0e5018:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0e501c:	afb30060 */ 	sw	$s3,0x60($sp)
/*  f0e5020:	afb2005c */ 	sw	$s2,0x5c($sp)
/*  f0e5024:	afb10058 */ 	sw	$s1,0x58($sp)
/*  f0e5028:	afb00054 */ 	sw	$s0,0x54($sp)
/*  f0e502c:	f7be0048 */ 	sdc1	$f30,0x48($sp)
/*  f0e5030:	f7bc0040 */ 	sdc1	$f28,0x40($sp)
/*  f0e5034:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f0e5038:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f0e503c:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f0e5040:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0e5044:	afa40150 */ 	sw	$a0,0x150($sp)
/*  f0e5048:	afa000f0 */ 	sw	$zero,0xf0($sp)
/*  f0e504c:	15c10006 */ 	bne	$t6,$at,.L0f0e5068
/*  f0e5050:	e7a400f4 */ 	swc1	$f4,0xf4($sp)
/*  f0e5054:	3c014000 */ 	lui	$at,0x4000
/*  f0e5058:	44813000 */ 	mtc1	$at,$f6
/*  f0e505c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e5060:	afaf00f0 */ 	sw	$t7,0xf0($sp)
/*  f0e5064:	e7a600f4 */ 	swc1	$f6,0xf4($sp)
.L0f0e5068:
/*  f0e5068:	3c118007 */ 	lui	$s1,%hi(var80071184)
/*  f0e506c:	26311184 */ 	addiu	$s1,$s1,%lo(var80071184)
/*  f0e5070:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e5074:	5700005d */ 	bnezl	$t8,.L0f0e51ec
/*  f0e5078:	3c012f80 */ 	lui	$at,0x2f80
/*  f0e507c:	0fc2777b */ 	jal	bgunGetGunMem
/*  f0e5080:	00000000 */ 	nop
/*  f0e5084:	14400003 */ 	bnez	$v0,.L0f0e5094
/*  f0e5088:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f0e508c:	10000304 */ 	b	.L0f0e5ca0
/*  f0e5090:	8fa20150 */ 	lw	$v0,0x150($sp)
.L0f0e5094:
/*  f0e5094:	3c0143f0 */ 	lui	$at,0x43f0
/*  f0e5098:	4481f000 */ 	mtc1	$at,$f30
/*  f0e509c:	3c01c420 */ 	lui	$at,0xc420
/*  f0e50a0:	4481e000 */ 	mtc1	$at,$f28
/*  f0e50a4:	3c014420 */ 	lui	$at,0x4420
/*  f0e50a8:	4481d000 */ 	mtc1	$at,$f26
/*  f0e50ac:	3c017f1b */ 	lui	$at,%hi(var7f1adf74)
/*  f0e50b0:	c438df74 */ 	lwc1	$f24,%lo(var7f1adf74)($at)
/*  f0e50b4:	3c017f1b */ 	lui	$at,%hi(var7f1adf78)
/*  f0e50b8:	c436df78 */ 	lwc1	$f22,%lo(var7f1adf78)($at)
/*  f0e50bc:	3c012f80 */ 	lui	$at,0x2f80
/*  f0e50c0:	4481a000 */ 	mtc1	$at,$f20
/*  f0e50c4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e50c8:	24120d20 */ 	addiu	$s2,$zero,0xd20
.L0f0e50cc:
/*  f0e50cc:	0c004b70 */ 	jal	random
/*  f0e50d0:	00000000 */ 	nop
/*  f0e50d4:	44824000 */ 	mtc1	$v0,$f8
/*  f0e50d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e50dc:	04410004 */ 	bgez	$v0,.L0f0e50f0
/*  f0e50e0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e50e4:	44818000 */ 	mtc1	$at,$f16
/*  f0e50e8:	00000000 */ 	nop
/*  f0e50ec:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0e50f0:
/*  f0e50f0:	46145482 */ 	mul.s	$f18,$f10,$f20
/*  f0e50f4:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f0e50f8:	01305021 */ 	addu	$t2,$t1,$s0
/*  f0e50fc:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f0e5100:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e5104:	0c004b70 */ 	jal	random
/*  f0e5108:	e5460000 */ 	swc1	$f6,0x0($t2)
/*  f0e510c:	44824000 */ 	mtc1	$v0,$f8
/*  f0e5110:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e5114:	04410004 */ 	bgez	$v0,.L0f0e5128
/*  f0e5118:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f0e511c:	44815000 */ 	mtc1	$at,$f10
/*  f0e5120:	00000000 */ 	nop
/*  f0e5124:	460a8400 */ 	add.s	$f16,$f16,$f10
.L0f0e5128:
/*  f0e5128:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f0e512c:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0e5130:	3c01c3f0 */ 	lui	$at,0xc3f0
/*  f0e5134:	01706021 */ 	addu	$t4,$t3,$s0
/*  f0e5138:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f0e513c:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e5140:	e5860004 */ 	swc1	$f6,0x4($t4)
/*  f0e5144:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f0e5148:	01b01821 */ 	addu	$v1,$t5,$s0
/*  f0e514c:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f0e5150:	461a003c */ 	c.lt.s	$f0,$f26
/*  f0e5154:	00000000 */ 	nop
/*  f0e5158:	45000010 */ 	bc1f	.L0f0e519c
/*  f0e515c:	00000000 */ 	nop
/*  f0e5160:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f0e5164:	00000000 */ 	nop
/*  f0e5168:	4500000c */ 	bc1f	.L0f0e519c
/*  f0e516c:	00000000 */ 	nop
/*  f0e5170:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f0e5174:	461e003c */ 	c.lt.s	$f0,$f30
/*  f0e5178:	00000000 */ 	nop
/*  f0e517c:	45000007 */ 	bc1f	.L0f0e519c
/*  f0e5180:	00000000 */ 	nop
/*  f0e5184:	44814000 */ 	mtc1	$at,$f8
/*  f0e5188:	00000000 */ 	nop
/*  f0e518c:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0e5190:	00000000 */ 	nop
/*  f0e5194:	4501ffcd */ 	bc1t	.L0f0e50cc
/*  f0e5198:	00000000 */ 	nop
.L0f0e519c:
/*  f0e519c:	0c004b70 */ 	jal	random
/*  f0e51a0:	00000000 */ 	nop
/*  f0e51a4:	44825000 */ 	mtc1	$v0,$f10
/*  f0e51a8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e51ac:	04410004 */ 	bgez	$v0,.L0f0e51c0
/*  f0e51b0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e51b4:	44819000 */ 	mtc1	$at,$f18
/*  f0e51b8:	00000000 */ 	nop
/*  f0e51bc:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f0e51c0:
/*  f0e51c0:	46148102 */ 	mul.s	$f4,$f16,$f20
/*  f0e51c4:	3c0145fa */ 	lui	$at,0x45fa
/*  f0e51c8:	44814000 */ 	mtc1	$at,$f8
/*  f0e51cc:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0e51d0:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f0e51d4:	46002187 */ 	neg.s	$f6,$f4
/*  f0e51d8:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0e51dc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0e51e0:	1612ffba */ 	bne	$s0,$s2,.L0f0e50cc
/*  f0e51e4:	e5ea0008 */ 	swc1	$f10,0x8($t7)
/*  f0e51e8:	3c012f80 */ 	lui	$at,0x2f80
.L0f0e51ec:
/*  f0e51ec:	4481a000 */ 	mtc1	$at,$f20
/*  f0e51f0:	3c017f1b */ 	lui	$at,%hi(var7f1adf7c)
/*  f0e51f4:	c436df7c */ 	lwc1	$f22,%lo(var7f1adf7c)($at)
/*  f0e51f8:	3c017f1b */ 	lui	$at,%hi(var7f1adf80)
/*  f0e51fc:	c438df80 */ 	lwc1	$f24,%lo(var7f1adf80)($at)
/*  f0e5200:	3c014420 */ 	lui	$at,0x4420
/*  f0e5204:	4481d000 */ 	mtc1	$at,$f26
/*  f0e5208:	3c01c420 */ 	lui	$at,0xc420
/*  f0e520c:	4481e000 */ 	mtc1	$at,$f28
/*  f0e5210:	3c0143f0 */ 	lui	$at,0x43f0
/*  f0e5214:	4481f000 */ 	mtc1	$at,$f30
/*  f0e5218:	00009025 */ 	or	$s2,$zero,$zero
/*  f0e521c:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e5220:	24130005 */ 	addiu	$s3,$zero,0x5
.L0f0e5224:
/*  f0e5224:	0253001a */ 	div	$zero,$s2,$s3
/*  f0e5228:	0000c810 */ 	mfhi	$t9
/*  f0e522c:	27290001 */ 	addiu	$t1,$t9,0x1
/*  f0e5230:	44899000 */ 	mtc1	$t1,$f18
/*  f0e5234:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f0e5238:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e523c:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0e5240:	03101821 */ 	addu	$v1,$t8,$s0
/*  f0e5244:	16600002 */ 	bnez	$s3,.L0f0e5250
/*  f0e5248:	00000000 */ 	nop
/*  f0e524c:	0007000d */ 	break	0x7
.L0f0e5250:
/*  f0e5250:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e5254:	16610004 */ 	bne	$s3,$at,.L0f0e5268
/*  f0e5258:	3c018000 */ 	lui	$at,0x8000
/*  f0e525c:	16410002 */ 	bne	$s2,$at,.L0f0e5268
/*  f0e5260:	00000000 */ 	nop
/*  f0e5264:	0006000d */ 	break	0x6
.L0f0e5268:
/*  f0e5268:	3c01800a */ 	lui	$at,%hi(g_Vars+0x5c)
/*  f0e526c:	c424a008 */ 	lwc1	$f4,%lo(g_Vars+0x5c)($at)
/*  f0e5270:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f0e5274:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0e5278:	44802000 */ 	mtc1	$zero,$f4
/*  f0e527c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0e5280:	460a9400 */ 	add.s	$f16,$f18,$f10
/*  f0e5284:	e4700008 */ 	swc1	$f16,0x8($v1)
/*  f0e5288:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f0e528c:	01505821 */ 	addu	$t3,$t2,$s0
/*  f0e5290:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f0e5294:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e5298:	00000000 */ 	nop
/*  f0e529c:	45020049 */ 	bc1fl	.L0f0e53c4
/*  f0e52a0:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0e52a4:
/*  f0e52a4:	0c004b70 */ 	jal	random
/*  f0e52a8:	00000000 */ 	nop
/*  f0e52ac:	44824000 */ 	mtc1	$v0,$f8
/*  f0e52b0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e52b4:	04410004 */ 	bgez	$v0,.L0f0e52c8
/*  f0e52b8:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0e52bc:	44815000 */ 	mtc1	$at,$f10
/*  f0e52c0:	00000000 */ 	nop
/*  f0e52c4:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0f0e52c8:
/*  f0e52c8:	46149402 */ 	mul.s	$f16,$f18,$f20
/*  f0e52cc:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f0e52d0:	01906821 */ 	addu	$t5,$t4,$s0
/*  f0e52d4:	46168102 */ 	mul.s	$f4,$f16,$f22
/*  f0e52d8:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e52dc:	0c004b70 */ 	jal	random
/*  f0e52e0:	e5a60000 */ 	swc1	$f6,0x0($t5)
/*  f0e52e4:	44824000 */ 	mtc1	$v0,$f8
/*  f0e52e8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e52ec:	04410004 */ 	bgez	$v0,.L0f0e5300
/*  f0e52f0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e52f4:	44819000 */ 	mtc1	$at,$f18
/*  f0e52f8:	00000000 */ 	nop
/*  f0e52fc:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f0e5300:
/*  f0e5300:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f0e5304:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0e5308:	3c01c3f0 */ 	lui	$at,0xc3f0
/*  f0e530c:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f0e5310:	46168102 */ 	mul.s	$f4,$f16,$f22
/*  f0e5314:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e5318:	e5e60004 */ 	swc1	$f6,0x4($t7)
/*  f0e531c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e5320:	03101821 */ 	addu	$v1,$t8,$s0
/*  f0e5324:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f0e5328:	461a003c */ 	c.lt.s	$f0,$f26
/*  f0e532c:	00000000 */ 	nop
/*  f0e5330:	45000010 */ 	bc1f	.L0f0e5374
/*  f0e5334:	00000000 */ 	nop
/*  f0e5338:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f0e533c:	00000000 */ 	nop
/*  f0e5340:	4500000c */ 	bc1f	.L0f0e5374
/*  f0e5344:	00000000 */ 	nop
/*  f0e5348:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f0e534c:	461e003c */ 	c.lt.s	$f0,$f30
/*  f0e5350:	00000000 */ 	nop
/*  f0e5354:	45000007 */ 	bc1f	.L0f0e5374
/*  f0e5358:	00000000 */ 	nop
/*  f0e535c:	44814000 */ 	mtc1	$at,$f8
/*  f0e5360:	00000000 */ 	nop
/*  f0e5364:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0e5368:	00000000 */ 	nop
/*  f0e536c:	4501ffcd */ 	bc1t	.L0f0e52a4
/*  f0e5370:	00000000 */ 	nop
.L0f0e5374:
/*  f0e5374:	0c004b70 */ 	jal	random
/*  f0e5378:	00000000 */ 	nop
/*  f0e537c:	44829000 */ 	mtc1	$v0,$f18
/*  f0e5380:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e5384:	04410004 */ 	bgez	$v0,.L0f0e5398
/*  f0e5388:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0e538c:	44818000 */ 	mtc1	$at,$f16
/*  f0e5390:	00000000 */ 	nop
/*  f0e5394:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0e5398:
/*  f0e5398:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0e539c:	3c0143fa */ 	lui	$at,0x43fa
/*  f0e53a0:	44813000 */ 	mtc1	$at,$f6
/*  f0e53a4:	3c01c5fa */ 	lui	$at,0xc5fa
/*  f0e53a8:	44819000 */ 	mtc1	$at,$f18
/*  f0e53ac:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f0e53b0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e53b4:	03304821 */ 	addu	$t1,$t9,$s0
/*  f0e53b8:	46089401 */ 	sub.s	$f16,$f18,$f8
/*  f0e53bc:	e5300008 */ 	swc1	$f16,0x8($t1)
/*  f0e53c0:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0e53c4:
/*  f0e53c4:	2a410118 */ 	slti	$at,$s2,0x118
/*  f0e53c8:	1420ff96 */ 	bnez	$at,.L0f0e5224
/*  f0e53cc:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0e53d0:	3c014120 */ 	lui	$at,0x4120
/*  f0e53d4:	44816000 */ 	mtc1	$at,$f12
/*  f0e53d8:	0fc01ae8 */ 	jal	func0f006ba0
/*  f0e53dc:	00000000 */ 	nop
/*  f0e53e0:	3c01800a */ 	lui	$at,%hi(var8009de98)
/*  f0e53e4:	ac20de98 */ 	sw	$zero,%lo(var8009de98)($at)
/*  f0e53e8:	3c01800a */ 	lui	$at,%hi(var8009de9c)
/*  f0e53ec:	8fa40150 */ 	lw	$a0,0x150($sp)
/*  f0e53f0:	46000506 */ 	mov.s	$f20,$f0
/*  f0e53f4:	ac20de9c */ 	sw	$zero,%lo(var8009de9c)($at)
/*  f0e53f8:	0fc3528f */ 	jal	func0f0d4a3c
/*  f0e53fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e5400:	3c0afffe */ 	lui	$t2,0xfffe
/*  f0e5404:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f0e5408:	354a7960 */ 	ori	$t2,$t2,0x7960
/*  f0e540c:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0e5410:	ac2ade90 */ 	sw	$t2,%lo(var8009de90)($at)
/*  f0e5414:	3c0b0001 */ 	lui	$t3,0x1
/*  f0e5418:	356b86a0 */ 	ori	$t3,$t3,0x86a0
/*  f0e541c:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0e5420:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e5424:	11800022 */ 	beqz	$t4,.L0f0e54b0
/*  f0e5428:	ac2bde94 */ 	sw	$t3,%lo(var8009de94)($at)
/*  f0e542c:	3c026060 */ 	lui	$v0,0x6060
/*  f0e5430:	3442607f */ 	ori	$v0,$v0,0x607f
/*  f0e5434:	240dfff6 */ 	addiu	$t5,$zero,-10
/*  f0e5438:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e543c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0e5440:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e5444:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e5448:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e544c:	2406fff6 */ 	addiu	$a2,$zero,-10
/*  f0e5450:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e5454:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f0e5458:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e545c:	afb20150 */ 	sw	$s2,0x150($sp)
/*  f0e5460:	0c002f06 */ 	jal	viGetHeight
/*  f0e5464:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e5468:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e546c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0e5470:	0c002f06 */ 	jal	viGetHeight
/*  f0e5474:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0e5478:	3c039090 */ 	lui	$v1,0x9090
/*  f0e547c:	3463907f */ 	ori	$v1,$v1,0x907f
/*  f0e5480:	244f000a */ 	addiu	$t7,$v0,0xa
/*  f0e5484:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e5488:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e548c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e5490:	8fa40150 */ 	lw	$a0,0x150($sp)
/*  f0e5494:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e5498:	2606000a */ 	addiu	$a2,$s0,0xa
/*  f0e549c:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e54a0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e54a4:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f0e54a8:	10000023 */ 	b	.L0f0e5538
/*  f0e54ac:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e54b0:
/*  f0e54b0:	2418fff6 */ 	addiu	$t8,$zero,-10
/*  f0e54b4:	3419947f */ 	dli	$t9,0x947f
/*  f0e54b8:	3409947f */ 	dli	$t1,0x947f
/*  f0e54bc:	240a000a */ 	addiu	$t2,$zero,0xa
/*  f0e54c0:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0e54c4:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0e54c8:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e54cc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e54d0:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e54d4:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e54d8:	2406fff6 */ 	addiu	$a2,$zero,-10
/*  f0e54dc:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e54e0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e54e4:	afb20150 */ 	sw	$s2,0x150($sp)
/*  f0e54e8:	0c002f06 */ 	jal	viGetHeight
/*  f0e54ec:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e54f0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e54f4:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0e54f8:	0c002f06 */ 	jal	viGetHeight
/*  f0e54fc:	01608025 */ 	or	$s0,$t3,$zero
/*  f0e5500:	3c036200 */ 	lui	$v1,0x6200
/*  f0e5504:	3463947f */ 	ori	$v1,$v1,0x947f
/*  f0e5508:	244c000a */ 	addiu	$t4,$v0,0xa
/*  f0e550c:	240d0006 */ 	addiu	$t5,$zero,0x6
/*  f0e5510:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e5514:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e5518:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e551c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e5520:	8fa40150 */ 	lw	$a0,0x150($sp)
/*  f0e5524:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e5528:	2606000a */ 	addiu	$a2,$s0,0xa
/*  f0e552c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e5530:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e5534:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e5538:
/*  f0e5538:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e553c:	0fc35320 */ 	jal	func0f0d4c80
/*  f0e5540:	afb20150 */ 	sw	$s2,0x150($sp)
/*  f0e5544:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e5548:	0fc35272 */ 	jal	func0f0d49c8
/*  f0e554c:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e5550:	3c05800b */ 	lui	$a1,%hi(g_TexGeneralConfigs)
/*  f0e5554:	8ca5b5a8 */ 	lw	$a1,%lo(g_TexGeneralConfigs)($a1)
/*  f0e5558:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0e555c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e5560:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e5564:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e5568:	27a40150 */ 	addiu	$a0,$sp,0x150
/*  f0e556c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e5570:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0e5574:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e5578:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e557c:	0fc2ce70 */ 	jal	texSelect
/*  f0e5580:	24a5000c */ 	addiu	$a1,$a1,0x000c
/*  f0e5584:	8fb80150 */ 	lw	$t8,0x150($sp)
/*  f0e5588:	3c09ba00 */ 	lui	$t1,0xba00
/*  f0e558c:	35291402 */ 	ori	$t1,$t1,0x1402
/*  f0e5590:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e5594:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f0e5598:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0e559c:	af090000 */ 	sw	$t1,0x0($t8)
/*  f0e55a0:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0e55a4:	3c0cba00 */ 	lui	$t4,0xba00
/*  f0e55a8:	358c0602 */ 	ori	$t4,$t4,0x602
/*  f0e55ac:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e55b0:	afab0150 */ 	sw	$t3,0x150($sp)
/*  f0e55b4:	240d00c0 */ 	addiu	$t5,$zero,0xc0
/*  f0e55b8:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0e55bc:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0e55c0:	8fae0150 */ 	lw	$t6,0x150($sp)
/*  f0e55c4:	3c18b900 */ 	lui	$t8,0xb900
/*  f0e55c8:	3c190050 */ 	lui	$t9,0x50
/*  f0e55cc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e55d0:	afaf0150 */ 	sw	$t7,0x150($sp)
/*  f0e55d4:	373949d8 */ 	ori	$t9,$t9,0x49d8
/*  f0e55d8:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f0e55dc:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e55e0:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e55e4:	8fa90150 */ 	lw	$t1,0x150($sp)
/*  f0e55e8:	3c0bb900 */ 	lui	$t3,0xb900
/*  f0e55ec:	356b0002 */ 	ori	$t3,$t3,0x2
/*  f0e55f0:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0e55f4:	afaa0150 */ 	sw	$t2,0x150($sp)
/*  f0e55f8:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f0e55fc:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0e5600:	8fac0150 */ 	lw	$t4,0x150($sp)
/*  f0e5604:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0e5608:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f0e560c:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0e5610:	afad0150 */ 	sw	$t5,0x150($sp)
/*  f0e5614:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f0e5618:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0e561c:	8faf0150 */ 	lw	$t7,0x150($sp)
/*  f0e5620:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0e5624:	37390903 */ 	ori	$t9,$t9,0x903
/*  f0e5628:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e562c:	afb80150 */ 	sw	$t8,0x150($sp)
/*  f0e5630:	24090c00 */ 	addiu	$t1,$zero,0xc00
/*  f0e5634:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f0e5638:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e563c:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0e5640:	3c0cfcff */ 	lui	$t4,0xfcff
/*  f0e5644:	3c0dff32 */ 	lui	$t5,0xff32
/*  f0e5648:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e564c:	afab0150 */ 	sw	$t3,0x150($sp)
/*  f0e5650:	35ad7f3f */ 	ori	$t5,$t5,0x7f3f
/*  f0e5654:	358c99ff */ 	ori	$t4,$t4,0x99ff
/*  f0e5658:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0e565c:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0e5660:	8fae0150 */ 	lw	$t6,0x150($sp)
/*  f0e5664:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0e5668:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f0e566c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e5670:	afaf0150 */ 	sw	$t7,0x150($sp)
/*  f0e5674:	24192000 */ 	addiu	$t9,$zero,0x2000
/*  f0e5678:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e567c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e5680:	8fa90150 */ 	lw	$t1,0x150($sp)
/*  f0e5684:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0e5688:	27b00110 */ 	addiu	$s0,$sp,0x110
/*  f0e568c:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0e5690:	afaa0150 */ 	sw	$t2,0x150($sp)
/*  f0e5694:	356b1301 */ 	ori	$t3,$t3,0x1301
/*  f0e5698:	3c0c0008 */ 	lui	$t4,0x8
/*  f0e569c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e56a0:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f0e56a4:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0e56a8:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0e56ac:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0e56b0:	00000000 */ 	nop
/*  f0e56b4:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e56b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e56bc:	0c005815 */ 	jal	mtx00016054
/*  f0e56c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0e56c4:	8fb00150 */ 	lw	$s0,0x150($sp)
/*  f0e56c8:	3c0f0102 */ 	lui	$t7,0x102
/*  f0e56cc:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f0e56d0:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f0e56d4:	afae0150 */ 	sw	$t6,0x150($sp)
/*  f0e56d8:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e56dc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e56e0:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f0e56e4:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0e56e8:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0e56ec:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e56f0:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f0e56f4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e56f8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e56fc:	1300004b */ 	beqz	$t8,.L0f0e582c
/*  f0e5700:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e5704:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5708:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e570c:	2408ff00 */ 	addiu	$t0,$zero,-256
/*  f0e5710:	2407007f */ 	addiu	$a3,$zero,0x7f
/*  f0e5714:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f0e5718:	0263c823 */ 	subu	$t9,$s3,$v1
.L0f0e571c:
/*  f0e571c:	03270019 */ 	multu	$t9,$a3
/*  f0e5720:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5724:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e5728:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e572c:	00004812 */ 	mflo	$t1
/*  f0e5730:	00000000 */ 	nop
/*  f0e5734:	00000000 */ 	nop
/*  f0e5738:	0125001b */ 	divu	$zero,$t1,$a1
/*  f0e573c:	00005012 */ 	mflo	$t2
/*  f0e5740:	01485825 */ 	or	$t3,$t2,$t0
/*  f0e5744:	14a00002 */ 	bnez	$a1,.L0f0e5750
/*  f0e5748:	00000000 */ 	nop
/*  f0e574c:	0007000d */ 	break	0x7
.L0f0e5750:
/*  f0e5750:	ac8bfff0 */ 	sw	$t3,-0x10($a0)
/*  f0e5754:	5420fff1 */ 	bnezl	$at,.L0f0e571c
/*  f0e5758:	0263c823 */ 	subu	$t9,$s3,$v1
/*  f0e575c:	3c06aaaa */ 	lui	$a2,0xaaaa
/*  f0e5760:	34c6aa00 */ 	ori	$a2,$a2,0xaa00
/*  f0e5764:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5768:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e576c:
/*  f0e576c:	02636023 */ 	subu	$t4,$s3,$v1
/*  f0e5770:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e5774:	01a5001b */ 	divu	$zero,$t5,$a1
/*  f0e5778:	00007012 */ 	mflo	$t6
/*  f0e577c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5780:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e5784:	01c67825 */ 	or	$t7,$t6,$a2
/*  f0e5788:	14a00002 */ 	bnez	$a1,.L0f0e5794
/*  f0e578c:	00000000 */ 	nop
/*  f0e5790:	0007000d */ 	break	0x7
.L0f0e5794:
/*  f0e5794:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0e5798:	1420fff4 */ 	bnez	$at,.L0f0e576c
/*  f0e579c:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e57a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e57a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e57a8:	0263c023 */ 	subu	$t8,$s3,$v1
.L0f0e57ac:
/*  f0e57ac:	03070019 */ 	multu	$t8,$a3
/*  f0e57b0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e57b4:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e57b8:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e57bc:	0000c812 */ 	mflo	$t9
/*  f0e57c0:	00000000 */ 	nop
/*  f0e57c4:	00000000 */ 	nop
/*  f0e57c8:	0325001b */ 	divu	$zero,$t9,$a1
/*  f0e57cc:	00004812 */ 	mflo	$t1
/*  f0e57d0:	01285025 */ 	or	$t2,$t1,$t0
/*  f0e57d4:	14a00002 */ 	bnez	$a1,.L0f0e57e0
/*  f0e57d8:	00000000 */ 	nop
/*  f0e57dc:	0007000d */ 	break	0x7
.L0f0e57e0:
/*  f0e57e0:	ac8afff8 */ 	sw	$t2,-0x8($a0)
/*  f0e57e4:	5420fff1 */ 	bnezl	$at,.L0f0e57ac
/*  f0e57e8:	0263c023 */ 	subu	$t8,$s3,$v1
/*  f0e57ec:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e57f0:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e57f4:
/*  f0e57f4:	02635823 */ 	subu	$t3,$s3,$v1
/*  f0e57f8:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0e57fc:	0185001b */ 	divu	$zero,$t4,$a1
/*  f0e5800:	00006812 */ 	mflo	$t5
/*  f0e5804:	01a67025 */ 	or	$t6,$t5,$a2
/*  f0e5808:	14a00002 */ 	bnez	$a1,.L0f0e5814
/*  f0e580c:	00000000 */ 	nop
/*  f0e5810:	0007000d */ 	break	0x7
.L0f0e5814:
/*  f0e5814:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5818:	ac8e000c */ 	sw	$t6,0xc($a0)
/*  f0e581c:	1473fff5 */ 	bne	$v1,$s3,.L0f0e57f4
/*  f0e5820:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e5824:	1000004a */ 	b	.L0f0e5950
/*  f0e5828:	8fb30150 */ 	lw	$s3,0x150($sp)
.L0f0e582c:
/*  f0e582c:	2408ff00 */ 	addiu	$t0,$zero,-256
/*  f0e5830:	2407007f */ 	addiu	$a3,$zero,0x7f
/*  f0e5834:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f0e5838:	02637823 */ 	subu	$t7,$s3,$v1
.L0f0e583c:
/*  f0e583c:	01e70019 */ 	multu	$t7,$a3
/*  f0e5840:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5844:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e5848:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e584c:	0000c012 */ 	mflo	$t8
/*  f0e5850:	00000000 */ 	nop
/*  f0e5854:	00000000 */ 	nop
/*  f0e5858:	0305001b */ 	divu	$zero,$t8,$a1
/*  f0e585c:	0000c812 */ 	mflo	$t9
/*  f0e5860:	03284825 */ 	or	$t1,$t9,$t0
/*  f0e5864:	14a00002 */ 	bnez	$a1,.L0f0e5870
/*  f0e5868:	00000000 */ 	nop
/*  f0e586c:	0007000d */ 	break	0x7
.L0f0e5870:
/*  f0e5870:	ac89fff0 */ 	sw	$t1,-0x10($a0)
/*  f0e5874:	5420fff1 */ 	bnezl	$at,.L0f0e583c
/*  f0e5878:	02637823 */ 	subu	$t7,$s3,$v1
/*  f0e587c:	3c06aaaa */ 	lui	$a2,0xaaaa
/*  f0e5880:	34c6ff00 */ 	ori	$a2,$a2,0xff00
/*  f0e5884:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5888:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e588c:
/*  f0e588c:	02635023 */ 	subu	$t2,$s3,$v1
/*  f0e5890:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0e5894:	0165001b */ 	divu	$zero,$t3,$a1
/*  f0e5898:	00006012 */ 	mflo	$t4
/*  f0e589c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e58a0:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e58a4:	01866825 */ 	or	$t5,$t4,$a2
/*  f0e58a8:	14a00002 */ 	bnez	$a1,.L0f0e58b4
/*  f0e58ac:	00000000 */ 	nop
/*  f0e58b0:	0007000d */ 	break	0x7
.L0f0e58b4:
/*  f0e58b4:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f0e58b8:	1420fff4 */ 	bnez	$at,.L0f0e588c
/*  f0e58bc:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e58c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e58c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e58c8:	02637023 */ 	subu	$t6,$s3,$v1
.L0f0e58cc:
/*  f0e58cc:	01c70019 */ 	multu	$t6,$a3
/*  f0e58d0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e58d4:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e58d8:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e58dc:	00007812 */ 	mflo	$t7
/*  f0e58e0:	00000000 */ 	nop
/*  f0e58e4:	00000000 */ 	nop
/*  f0e58e8:	01e5001b */ 	divu	$zero,$t7,$a1
/*  f0e58ec:	0000c012 */ 	mflo	$t8
/*  f0e58f0:	0308c825 */ 	or	$t9,$t8,$t0
/*  f0e58f4:	14a00002 */ 	bnez	$a1,.L0f0e5900
/*  f0e58f8:	00000000 */ 	nop
/*  f0e58fc:	0007000d */ 	break	0x7
.L0f0e5900:
/*  f0e5900:	ac99fff8 */ 	sw	$t9,-0x8($a0)
/*  f0e5904:	5420fff1 */ 	bnezl	$at,.L0f0e58cc
/*  f0e5908:	02637023 */ 	subu	$t6,$s3,$v1
/*  f0e590c:	3c06ffaa */ 	lui	$a2,0xffaa
/*  f0e5910:	34c6ff00 */ 	ori	$a2,$a2,0xff00
/*  f0e5914:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5918:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e591c:
/*  f0e591c:	02634823 */ 	subu	$t1,$s3,$v1
/*  f0e5920:	00095100 */ 	sll	$t2,$t1,0x4
/*  f0e5924:	0145001b */ 	divu	$zero,$t2,$a1
/*  f0e5928:	00005812 */ 	mflo	$t3
/*  f0e592c:	01666025 */ 	or	$t4,$t3,$a2
/*  f0e5930:	14a00002 */ 	bnez	$a1,.L0f0e593c
/*  f0e5934:	00000000 */ 	nop
/*  f0e5938:	0007000d */ 	break	0x7
.L0f0e593c:
/*  f0e593c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5940:	ac8c000c */ 	sw	$t4,0xc($a0)
/*  f0e5944:	1473fff5 */ 	bne	$v1,$s3,.L0f0e591c
/*  f0e5948:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e594c:	8fb30150 */ 	lw	$s3,0x150($sp)
.L0f0e5950:
/*  f0e5950:	3c0f074c */ 	lui	$t7,0x74c
/*  f0e5954:	35ef0050 */ 	ori	$t7,$t7,0x50
/*  f0e5958:	266e0008 */ 	addiu	$t6,$s3,0x8
/*  f0e595c:	afae0150 */ 	sw	$t6,0x150($sp)
/*  f0e5960:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e5964:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e5968:	ae6f0000 */ 	sw	$t7,0x0($s3)
/*  f0e596c:	ae620004 */ 	sw	$v0,0x4($s3)
/*  f0e5970:	3c017f1b */ 	lui	$at,%hi(var7f1adf84)
/*  f0e5974:	c42adf84 */ 	lwc1	$f10,%lo(var7f1adf84)($at)
/*  f0e5978:	3c017f1b */ 	lui	$at,%hi(var7f1adf88)
/*  f0e597c:	c43edf88 */ 	lwc1	$f30,%lo(var7f1adf88)($at)
/*  f0e5980:	460aa002 */ 	mul.s	$f0,$f20,$f10
/*  f0e5984:	3c014170 */ 	lui	$at,0x4170
/*  f0e5988:	4481e000 */ 	mtc1	$at,$f28
/*  f0e598c:	3c017f1b */ 	lui	$at,%hi(var7f1adf8c)
/*  f0e5990:	c43adf8c */ 	lwc1	$f26,%lo(var7f1adf8c)($at)
/*  f0e5994:	3c0141c8 */ 	lui	$at,0x41c8
/*  f0e5998:	4481b000 */ 	mtc1	$at,$f22
/*  f0e599c:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f0e59a0:	24120117 */ 	addiu	$s2,$zero,0x117
/*  f0e59a4:	24100d14 */ 	addiu	$s0,$zero,0xd14
.L0f0e59a8:
/*  f0e59a8:	44922000 */ 	mtc1	$s2,$f4
/*  f0e59ac:	c7a00070 */ 	lwc1	$f0,0x70($sp)
/*  f0e59b0:	00009825 */ 	or	$s3,$zero,$zero
/*  f0e59b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e59b8:	461c3483 */ 	div.s	$f18,$f6,$f28
/*  f0e59bc:	4612d202 */ 	mul.s	$f8,$f26,$f18
/*  f0e59c0:	46080500 */ 	add.s	$f20,$f0,$f8
/*  f0e59c4:	0c0068f7 */ 	jal	sinf
/*  f0e59c8:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e59cc:	46000606 */ 	mov.s	$f24,$f0
/*  f0e59d0:	0c0068f4 */ 	jal	cosf
/*  f0e59d4:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e59d8:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e59dc:	46000506 */ 	mov.s	$f20,$f0
/*  f0e59e0:	3c017f1b */ 	lui	$at,%hi(var7f1adf90)
/*  f0e59e4:	03101821 */ 	addu	$v1,$t8,$s0
/*  f0e59e8:	c4700000 */ 	lwc1	$f16,0x0($v1)
/*  f0e59ec:	e7b000b8 */ 	swc1	$f16,0xb8($sp)
/*  f0e59f0:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f0e59f4:	e7aa00bc */ 	swc1	$f10,0xbc($sp)
/*  f0e59f8:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0e59fc:	e7a400c0 */ 	swc1	$f4,0xc0($sp)
/*  f0e5a00:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f0e5a04:	c7a000c0 */ 	lwc1	$f0,0xc0($sp)
/*  f0e5a08:	461e303c */ 	c.lt.s	$f6,$f30
/*  f0e5a0c:	00000000 */ 	nop
/*  f0e5a10:	4502000e */ 	bc1fl	.L0f0e5a4c
/*  f0e5a14:	44808000 */ 	mtc1	$zero,$f16
/*  f0e5a18:	c432df90 */ 	lwc1	$f18,%lo(var7f1adf90)($at)
/*  f0e5a1c:	3c0144af */ 	lui	$at,0x44af
/*  f0e5a20:	44815000 */ 	mtc1	$at,$f10
/*  f0e5a24:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f0e5a28:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0e5a2c:	44813000 */ 	mtc1	$at,$f6
/*  f0e5a30:	46004407 */ 	neg.s	$f16,$f8
/*  f0e5a34:	460a8103 */ 	div.s	$f4,$f16,$f10
/*  f0e5a38:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f0e5a3c:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5a40:	44134000 */ 	mfc1	$s3,$f8
/*  f0e5a44:	00000000 */ 	nop
/*  f0e5a48:	44808000 */ 	mtc1	$zero,$f16
.L0f0e5a4c:
/*  f0e5a4c:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0e5a50:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0e5a54:	00000000 */ 	nop
/*  f0e5a58:	4502008d */ 	bc1fl	.L0f0e5c90
/*  f0e5a5c:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f0e5a60:	5020008b */ 	beqzl	$at,.L0f0e5c90
/*  f0e5a64:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f0e5a68:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0e5a6c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e5a70:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0e5a74:	4600c007 */ 	neg.s	$f0,$f24
/*  f0e5a78:	4600a087 */ 	neg.s	$f2,$f20
/*  f0e5a7c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0e5a80:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e5a84:	440a2000 */ 	mfc1	$t2,$f4
/*  f0e5a88:	4614c100 */ 	add.s	$f4,$f24,$f20
/*  f0e5a8c:	a44a0000 */ 	sh	$t2,0x0($v0)
/*  f0e5a90:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f0e5a94:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5a98:	4604b182 */ 	mul.s	$f6,$f22,$f4
/*  f0e5a9c:	4600a100 */ 	add.s	$f4,$f20,$f0
/*  f0e5aa0:	440c9000 */ 	mfc1	$t4,$f18
/*  f0e5aa4:	00000000 */ 	nop
/*  f0e5aa8:	a44c0002 */ 	sh	$t4,0x2($v0)
/*  f0e5aac:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5ab0:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f0e5ab4:	440e8000 */ 	mfc1	$t6,$f16
/*  f0e5ab8:	00000000 */ 	nop
/*  f0e5abc:	a44e0004 */ 	sh	$t6,0x4($v0)
/*  f0e5ac0:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0e5ac4:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f0e5ac8:	4604b282 */ 	mul.s	$f10,$f22,$f4
/*  f0e5acc:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5ad0:	44184000 */ 	mfc1	$t8,$f8
/*  f0e5ad4:	00000000 */ 	nop
/*  f0e5ad8:	a458000c */ 	sh	$t8,0xc($v0)
/*  f0e5adc:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*  f0e5ae0:	460a8180 */ 	add.s	$f6,$f16,$f10
/*  f0e5ae4:	4614c281 */ 	sub.s	$f10,$f24,$f20
/*  f0e5ae8:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5aec:	460ab182 */ 	mul.s	$f6,$f22,$f10
/*  f0e5af0:	4600a281 */ 	sub.s	$f10,$f20,$f0
/*  f0e5af4:	44099000 */ 	mfc1	$t1,$f18
/*  f0e5af8:	00000000 */ 	nop
/*  f0e5afc:	a449000e */ 	sh	$t1,0xe($v0)
/*  f0e5b00:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5b04:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0e5b08:	440b2000 */ 	mfc1	$t3,$f4
/*  f0e5b0c:	00000000 */ 	nop
/*  f0e5b10:	a44b0010 */ 	sh	$t3,0x10($v0)
/*  f0e5b14:	c7b000b8 */ 	lwc1	$f16,0xb8($sp)
/*  f0e5b18:	46068480 */ 	add.s	$f18,$f16,$f6
/*  f0e5b1c:	460ab402 */ 	mul.s	$f16,$f22,$f10
/*  f0e5b20:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5b24:	440d4000 */ 	mfc1	$t5,$f8
/*  f0e5b28:	00000000 */ 	nop
/*  f0e5b2c:	a44d0018 */ 	sh	$t5,0x18($v0)
/*  f0e5b30:	c7a400bc */ 	lwc1	$f4,0xbc($sp)
/*  f0e5b34:	46102180 */ 	add.s	$f6,$f4,$f16
/*  f0e5b38:	46140401 */ 	sub.s	$f16,$f0,$f20
/*  f0e5b3c:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5b40:	4610b182 */ 	mul.s	$f6,$f22,$f16
/*  f0e5b44:	46001401 */ 	sub.s	$f16,$f2,$f0
/*  f0e5b48:	440f9000 */ 	mfc1	$t7,$f18
/*  f0e5b4c:	00000000 */ 	nop
/*  f0e5b50:	a44f001a */ 	sh	$t7,0x1a($v0)
/*  f0e5b54:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5b58:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e5b5c:	44195000 */ 	mfc1	$t9,$f10
/*  f0e5b60:	00000000 */ 	nop
/*  f0e5b64:	a459001c */ 	sh	$t9,0x1c($v0)
/*  f0e5b68:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f0e5b6c:	46062480 */ 	add.s	$f18,$f4,$f6
/*  f0e5b70:	4610b102 */ 	mul.s	$f4,$f22,$f16
/*  f0e5b74:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5b78:	440a4000 */ 	mfc1	$t2,$f8
/*  f0e5b7c:	00000000 */ 	nop
/*  f0e5b80:	a44a0024 */ 	sh	$t2,0x24($v0)
/*  f0e5b84:	c7aa00bc */ 	lwc1	$f10,0xbc($sp)
/*  f0e5b88:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0e5b8c:	46140100 */ 	add.s	$f4,$f0,$f20
/*  f0e5b90:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5b94:	4604b182 */ 	mul.s	$f6,$f22,$f4
/*  f0e5b98:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f0e5b9c:	440c9000 */ 	mfc1	$t4,$f18
/*  f0e5ba0:	00000000 */ 	nop
/*  f0e5ba4:	a44c0026 */ 	sh	$t4,0x26($v0)
/*  f0e5ba8:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5bac:	00136080 */ 	sll	$t4,$s3,0x2
/*  f0e5bb0:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f0e5bb4:	440e8000 */ 	mfc1	$t6,$f16
/*  f0e5bb8:	00000000 */ 	nop
/*  f0e5bbc:	a44e0028 */ 	sh	$t6,0x28($v0)
/*  f0e5bc0:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0e5bc4:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f0e5bc8:	4604b282 */ 	mul.s	$f10,$f22,$f4
/*  f0e5bcc:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5bd0:	44184000 */ 	mfc1	$t8,$f8
/*  f0e5bd4:	00000000 */ 	nop
/*  f0e5bd8:	a4580030 */ 	sh	$t8,0x30($v0)
/*  f0e5bdc:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*  f0e5be0:	460a8180 */ 	add.s	$f6,$f16,$f10
/*  f0e5be4:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5be8:	44099000 */ 	mfc1	$t1,$f18
/*  f0e5bec:	00000000 */ 	nop
/*  f0e5bf0:	a4490032 */ 	sh	$t1,0x32($v0)
/*  f0e5bf4:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5bf8:	3c090440 */ 	lui	$t1,0x440
/*  f0e5bfc:	3529003c */ 	ori	$t1,$t1,0x3c
/*  f0e5c00:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0e5c04:	440b2000 */ 	mfc1	$t3,$f4
/*  f0e5c08:	00000000 */ 	nop
/*  f0e5c0c:	a44b0034 */ 	sh	$t3,0x34($v0)
/*  f0e5c10:	06410004 */ 	bgez	$s2,.L0f0e5c24
/*  f0e5c14:	324d0001 */ 	andi	$t5,$s2,0x1
/*  f0e5c18:	11a00002 */ 	beqz	$t5,.L0f0e5c24
/*  f0e5c1c:	00000000 */ 	nop
/*  f0e5c20:	25adfffe */ 	addiu	$t5,$t5,-2
.L0f0e5c24:
/*  f0e5c24:	000d7040 */ 	sll	$t6,$t5,0x1
/*  f0e5c28:	018e1821 */ 	addu	$v1,$t4,$t6
/*  f0e5c2c:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0e5c30:	25e50004 */ 	addiu	$a1,$t7,0x4
/*  f0e5c34:	a04f0007 */ 	sb	$t7,0x7($v0)
/*  f0e5c38:	a0450013 */ 	sb	$a1,0x13($v0)
/*  f0e5c3c:	a085001f */ 	sb	$a1,0x1f($a0)
/*  f0e5c40:	a085002b */ 	sb	$a1,0x2b($a0)
/*  f0e5c44:	a0850037 */ 	sb	$a1,0x37($a0)
/*  f0e5c48:	8fb80150 */ 	lw	$t8,0x150($sp)
/*  f0e5c4c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e5c50:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f0e5c54:	af090000 */ 	sw	$t1,0x0($t8)
/*  f0e5c58:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e5c5c:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f0e5c60:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0e5c64:	3c0db100 */ 	lui	$t5,0xb100
/*  f0e5c68:	3c0c4030 */ 	lui	$t4,0x4030
/*  f0e5c6c:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f0e5c70:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0e5c74:	358c2010 */ 	ori	$t4,$t4,0x2010
/*  f0e5c78:	35ad1432 */ 	ori	$t5,$t5,0x1432
/*  f0e5c7c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e5c80:	afab0150 */ 	sw	$t3,0x150($sp)
/*  f0e5c84:	ad4c0004 */ 	sw	$t4,0x4($t2)
/*  f0e5c88:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f0e5c8c:	2652ffff */ 	addiu	$s2,$s2,-1
.L0f0e5c90:
/*  f0e5c90:	0641ff45 */ 	bgez	$s2,.L0f0e59a8
/*  f0e5c94:	2610fff4 */ 	addiu	$s0,$s0,-12
/*  f0e5c98:	0fc351e7 */ 	jal	func0f0d479c
/*  f0e5c9c:	8fa40150 */ 	lw	$a0,0x150($sp)
.L0f0e5ca0:
/*  f0e5ca0:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0e5ca4:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0e5ca8:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f0e5cac:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f0e5cb0:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f0e5cb4:	d7bc0040 */ 	ldc1	$f28,0x40($sp)
/*  f0e5cb8:	d7be0048 */ 	ldc1	$f30,0x48($sp)
/*  f0e5cbc:	8fb00054 */ 	lw	$s0,0x54($sp)
/*  f0e5cc0:	8fb10058 */ 	lw	$s1,0x58($sp)
/*  f0e5cc4:	8fb2005c */ 	lw	$s2,0x5c($sp)
/*  f0e5cc8:	8fb30060 */ 	lw	$s3,0x60($sp)
/*  f0e5ccc:	03e00008 */ 	jr	$ra
/*  f0e5cd0:	27bd0150 */ 	addiu	$sp,$sp,0x150
);
#else
GLOBAL_ASM(
glabel menugfxRenderBgSuccess
.late_rodata
glabel var7f1adf74
.word 0x459c4000
glabel var7f1adf78
.word 0x461c4000
glabel var7f1adf7c
.word 0x461c4000
glabel var7f1adf80
.word 0x459c4000
glabel var7f1adf84
.word 0x40c907a9
glabel var7f1adf88
.word 0xc5ce4000
glabel var7f1adf8c
.word 0x40c907a9
glabel var7f1adf90
.word 0x45ce4000
.text
/*  f0e5000:	27bdfeb0 */ 	addiu	$sp,$sp,-336
/*  f0e5004:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0e5008:	3c0e8008 */ 	lui	$t6,%hi(g_StageIndex)
/*  f0e500c:	44812000 */ 	mtc1	$at,$f4
/*  f0e5010:	8dcefc00 */ 	lw	$t6,%lo(g_StageIndex)($t6)
/*  f0e5014:	24010019 */ 	addiu	$at,$zero,0x19
/*  f0e5018:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0e501c:	afb30060 */ 	sw	$s3,0x60($sp)
/*  f0e5020:	afb2005c */ 	sw	$s2,0x5c($sp)
/*  f0e5024:	afb10058 */ 	sw	$s1,0x58($sp)
/*  f0e5028:	afb00054 */ 	sw	$s0,0x54($sp)
/*  f0e502c:	f7be0048 */ 	sdc1	$f30,0x48($sp)
/*  f0e5030:	f7bc0040 */ 	sdc1	$f28,0x40($sp)
/*  f0e5034:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f0e5038:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f0e503c:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f0e5040:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0e5044:	afa40150 */ 	sw	$a0,0x150($sp)
/*  f0e5048:	afa000f0 */ 	sw	$zero,0xf0($sp)
/*  f0e504c:	15c10006 */ 	bne	$t6,$at,.L0f0e5068
/*  f0e5050:	e7a400f4 */ 	swc1	$f4,0xf4($sp)
/*  f0e5054:	3c014000 */ 	lui	$at,0x4000
/*  f0e5058:	44813000 */ 	mtc1	$at,$f6
/*  f0e505c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e5060:	afaf00f0 */ 	sw	$t7,0xf0($sp)
/*  f0e5064:	e7a600f4 */ 	swc1	$f6,0xf4($sp)
.L0f0e5068:
/*  f0e5068:	3c118007 */ 	lui	$s1,%hi(var80071184)
/*  f0e506c:	26311184 */ 	addiu	$s1,$s1,%lo(var80071184)
/*  f0e5070:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e5074:	5700005d */ 	bnezl	$t8,.L0f0e51ec
/*  f0e5078:	3c012f80 */ 	lui	$at,0x2f80
/*  f0e507c:	0fc2777b */ 	jal	bgunGetGunMem
/*  f0e5080:	00000000 */ 	nop
/*  f0e5084:	14400003 */ 	bnez	$v0,.L0f0e5094
/*  f0e5088:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f0e508c:	10000304 */ 	b	.L0f0e5ca0
/*  f0e5090:	8fa20150 */ 	lw	$v0,0x150($sp)
.L0f0e5094:
/*  f0e5094:	3c0143f0 */ 	lui	$at,0x43f0
/*  f0e5098:	4481f000 */ 	mtc1	$at,$f30
/*  f0e509c:	3c01c420 */ 	lui	$at,0xc420
/*  f0e50a0:	4481e000 */ 	mtc1	$at,$f28
/*  f0e50a4:	3c014420 */ 	lui	$at,0x4420
/*  f0e50a8:	4481d000 */ 	mtc1	$at,$f26
/*  f0e50ac:	3c017f1b */ 	lui	$at,%hi(var7f1adf74)
/*  f0e50b0:	c438df74 */ 	lwc1	$f24,%lo(var7f1adf74)($at)
/*  f0e50b4:	3c017f1b */ 	lui	$at,%hi(var7f1adf78)
/*  f0e50b8:	c436df78 */ 	lwc1	$f22,%lo(var7f1adf78)($at)
/*  f0e50bc:	3c012f80 */ 	lui	$at,0x2f80
/*  f0e50c0:	4481a000 */ 	mtc1	$at,$f20
/*  f0e50c4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e50c8:	24120d20 */ 	addiu	$s2,$zero,0xd20
.L0f0e50cc:
/*  f0e50cc:	0c004b70 */ 	jal	random
/*  f0e50d0:	00000000 */ 	nop
/*  f0e50d4:	44824000 */ 	mtc1	$v0,$f8
/*  f0e50d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e50dc:	04410004 */ 	bgez	$v0,.L0f0e50f0
/*  f0e50e0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e50e4:	44818000 */ 	mtc1	$at,$f16
/*  f0e50e8:	00000000 */ 	nop
/*  f0e50ec:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0e50f0:
/*  f0e50f0:	46145482 */ 	mul.s	$f18,$f10,$f20
/*  f0e50f4:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f0e50f8:	01305021 */ 	addu	$t2,$t1,$s0
/*  f0e50fc:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f0e5100:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e5104:	0c004b70 */ 	jal	random
/*  f0e5108:	e5460000 */ 	swc1	$f6,0x0($t2)
/*  f0e510c:	44824000 */ 	mtc1	$v0,$f8
/*  f0e5110:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e5114:	04410004 */ 	bgez	$v0,.L0f0e5128
/*  f0e5118:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f0e511c:	44815000 */ 	mtc1	$at,$f10
/*  f0e5120:	00000000 */ 	nop
/*  f0e5124:	460a8400 */ 	add.s	$f16,$f16,$f10
.L0f0e5128:
/*  f0e5128:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f0e512c:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0e5130:	3c01c3f0 */ 	lui	$at,0xc3f0
/*  f0e5134:	01706021 */ 	addu	$t4,$t3,$s0
/*  f0e5138:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f0e513c:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e5140:	e5860004 */ 	swc1	$f6,0x4($t4)
/*  f0e5144:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f0e5148:	01b01821 */ 	addu	$v1,$t5,$s0
/*  f0e514c:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f0e5150:	461a003c */ 	c.lt.s	$f0,$f26
/*  f0e5154:	00000000 */ 	nop
/*  f0e5158:	45000010 */ 	bc1f	.L0f0e519c
/*  f0e515c:	00000000 */ 	nop
/*  f0e5160:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f0e5164:	00000000 */ 	nop
/*  f0e5168:	4500000c */ 	bc1f	.L0f0e519c
/*  f0e516c:	00000000 */ 	nop
/*  f0e5170:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f0e5174:	461e003c */ 	c.lt.s	$f0,$f30
/*  f0e5178:	00000000 */ 	nop
/*  f0e517c:	45000007 */ 	bc1f	.L0f0e519c
/*  f0e5180:	00000000 */ 	nop
/*  f0e5184:	44814000 */ 	mtc1	$at,$f8
/*  f0e5188:	00000000 */ 	nop
/*  f0e518c:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0e5190:	00000000 */ 	nop
/*  f0e5194:	4501ffcd */ 	bc1t	.L0f0e50cc
/*  f0e5198:	00000000 */ 	nop
.L0f0e519c:
/*  f0e519c:	0c004b70 */ 	jal	random
/*  f0e51a0:	00000000 */ 	nop
/*  f0e51a4:	44825000 */ 	mtc1	$v0,$f10
/*  f0e51a8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e51ac:	04410004 */ 	bgez	$v0,.L0f0e51c0
/*  f0e51b0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e51b4:	44819000 */ 	mtc1	$at,$f18
/*  f0e51b8:	00000000 */ 	nop
/*  f0e51bc:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f0e51c0:
/*  f0e51c0:	46148102 */ 	mul.s	$f4,$f16,$f20
/*  f0e51c4:	3c0145fa */ 	lui	$at,0x45fa
/*  f0e51c8:	44814000 */ 	mtc1	$at,$f8
/*  f0e51cc:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0e51d0:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f0e51d4:	46002187 */ 	neg.s	$f6,$f4
/*  f0e51d8:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0e51dc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0e51e0:	1612ffba */ 	bne	$s0,$s2,.L0f0e50cc
/*  f0e51e4:	e5ea0008 */ 	swc1	$f10,0x8($t7)
/*  f0e51e8:	3c012f80 */ 	lui	$at,0x2f80
.L0f0e51ec:
/*  f0e51ec:	4481a000 */ 	mtc1	$at,$f20
/*  f0e51f0:	3c017f1b */ 	lui	$at,%hi(var7f1adf7c)
/*  f0e51f4:	c436df7c */ 	lwc1	$f22,%lo(var7f1adf7c)($at)
/*  f0e51f8:	3c017f1b */ 	lui	$at,%hi(var7f1adf80)
/*  f0e51fc:	c438df80 */ 	lwc1	$f24,%lo(var7f1adf80)($at)
/*  f0e5200:	3c014420 */ 	lui	$at,0x4420
/*  f0e5204:	4481d000 */ 	mtc1	$at,$f26
/*  f0e5208:	3c01c420 */ 	lui	$at,0xc420
/*  f0e520c:	4481e000 */ 	mtc1	$at,$f28
/*  f0e5210:	3c0143f0 */ 	lui	$at,0x43f0
/*  f0e5214:	4481f000 */ 	mtc1	$at,$f30
/*  f0e5218:	00009025 */ 	or	$s2,$zero,$zero
/*  f0e521c:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e5220:	24130005 */ 	addiu	$s3,$zero,0x5
.L0f0e5224:
/*  f0e5224:	0253001a */ 	div	$zero,$s2,$s3
/*  f0e5228:	0000c810 */ 	mfhi	$t9
/*  f0e522c:	27290001 */ 	addiu	$t1,$t9,0x1
/*  f0e5230:	44899000 */ 	mtc1	$t1,$f18
/*  f0e5234:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f0e5238:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e523c:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0e5240:	03101821 */ 	addu	$v1,$t8,$s0
/*  f0e5244:	16600002 */ 	bnez	$s3,.L0f0e5250
/*  f0e5248:	00000000 */ 	nop
/*  f0e524c:	0007000d */ 	break	0x7
.L0f0e5250:
/*  f0e5250:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e5254:	16610004 */ 	bne	$s3,$at,.L0f0e5268
/*  f0e5258:	3c018000 */ 	lui	$at,0x8000
/*  f0e525c:	16410002 */ 	bne	$s2,$at,.L0f0e5268
/*  f0e5260:	00000000 */ 	nop
/*  f0e5264:	0006000d */ 	break	0x6
.L0f0e5268:
/*  f0e5268:	3c01800a */ 	lui	$at,%hi(g_Vars+0x48)
/*  f0e526c:	c424a008 */ 	lwc1	$f4,%lo(g_Vars+0x48)($at)
/*  f0e5270:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f0e5274:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0e5278:	44802000 */ 	mtc1	$zero,$f4
/*  f0e527c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0e5280:	460a9400 */ 	add.s	$f16,$f18,$f10
/*  f0e5284:	e4700008 */ 	swc1	$f16,0x8($v1)
/*  f0e5288:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f0e528c:	01505821 */ 	addu	$t3,$t2,$s0
/*  f0e5290:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f0e5294:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e5298:	00000000 */ 	nop
/*  f0e529c:	45020049 */ 	bc1fl	.L0f0e53c4
/*  f0e52a0:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0e52a4:
/*  f0e52a4:	0c004b70 */ 	jal	random
/*  f0e52a8:	00000000 */ 	nop
/*  f0e52ac:	44824000 */ 	mtc1	$v0,$f8
/*  f0e52b0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e52b4:	04410004 */ 	bgez	$v0,.L0f0e52c8
/*  f0e52b8:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0e52bc:	44815000 */ 	mtc1	$at,$f10
/*  f0e52c0:	00000000 */ 	nop
/*  f0e52c4:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0f0e52c8:
/*  f0e52c8:	46149402 */ 	mul.s	$f16,$f18,$f20
/*  f0e52cc:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f0e52d0:	01906821 */ 	addu	$t5,$t4,$s0
/*  f0e52d4:	46168102 */ 	mul.s	$f4,$f16,$f22
/*  f0e52d8:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e52dc:	0c004b70 */ 	jal	random
/*  f0e52e0:	e5a60000 */ 	swc1	$f6,0x0($t5)
/*  f0e52e4:	44824000 */ 	mtc1	$v0,$f8
/*  f0e52e8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e52ec:	04410004 */ 	bgez	$v0,.L0f0e5300
/*  f0e52f0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e52f4:	44819000 */ 	mtc1	$at,$f18
/*  f0e52f8:	00000000 */ 	nop
/*  f0e52fc:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f0e5300:
/*  f0e5300:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f0e5304:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0e5308:	3c01c3f0 */ 	lui	$at,0xc3f0
/*  f0e530c:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f0e5310:	46168102 */ 	mul.s	$f4,$f16,$f22
/*  f0e5314:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e5318:	e5e60004 */ 	swc1	$f6,0x4($t7)
/*  f0e531c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e5320:	03101821 */ 	addu	$v1,$t8,$s0
/*  f0e5324:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f0e5328:	461a003c */ 	c.lt.s	$f0,$f26
/*  f0e532c:	00000000 */ 	nop
/*  f0e5330:	45000010 */ 	bc1f	.L0f0e5374
/*  f0e5334:	00000000 */ 	nop
/*  f0e5338:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f0e533c:	00000000 */ 	nop
/*  f0e5340:	4500000c */ 	bc1f	.L0f0e5374
/*  f0e5344:	00000000 */ 	nop
/*  f0e5348:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f0e534c:	461e003c */ 	c.lt.s	$f0,$f30
/*  f0e5350:	00000000 */ 	nop
/*  f0e5354:	45000007 */ 	bc1f	.L0f0e5374
/*  f0e5358:	00000000 */ 	nop
/*  f0e535c:	44814000 */ 	mtc1	$at,$f8
/*  f0e5360:	00000000 */ 	nop
/*  f0e5364:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0e5368:	00000000 */ 	nop
/*  f0e536c:	4501ffcd */ 	bc1t	.L0f0e52a4
/*  f0e5370:	00000000 */ 	nop
.L0f0e5374:
/*  f0e5374:	0c004b70 */ 	jal	random
/*  f0e5378:	00000000 */ 	nop
/*  f0e537c:	44829000 */ 	mtc1	$v0,$f18
/*  f0e5380:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e5384:	04410004 */ 	bgez	$v0,.L0f0e5398
/*  f0e5388:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0e538c:	44818000 */ 	mtc1	$at,$f16
/*  f0e5390:	00000000 */ 	nop
/*  f0e5394:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0e5398:
/*  f0e5398:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0e539c:	3c0143fa */ 	lui	$at,0x43fa
/*  f0e53a0:	44813000 */ 	mtc1	$at,$f6
/*  f0e53a4:	3c01c5fa */ 	lui	$at,0xc5fa
/*  f0e53a8:	44819000 */ 	mtc1	$at,$f18
/*  f0e53ac:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f0e53b0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e53b4:	03304821 */ 	addu	$t1,$t9,$s0
/*  f0e53b8:	46089401 */ 	sub.s	$f16,$f18,$f8
/*  f0e53bc:	e5300008 */ 	swc1	$f16,0x8($t1)
/*  f0e53c0:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0e53c4:
/*  f0e53c4:	2a410118 */ 	slti	$at,$s2,0x118
/*  f0e53c8:	1420ff96 */ 	bnez	$at,.L0f0e5224
/*  f0e53cc:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0e53d0:	3c014120 */ 	lui	$at,0x4120
/*  f0e53d4:	44816000 */ 	mtc1	$at,$f12
/*  f0e53d8:	0fc01ae8 */ 	jal	func0f006ba0
/*  f0e53dc:	00000000 */ 	nop
/*  f0e53e0:	3c01800a */ 	lui	$at,%hi(var8009de98)
/*  f0e53e4:	ac20de98 */ 	sw	$zero,%lo(var8009de98)($at)
/*  f0e53e8:	3c01800a */ 	lui	$at,%hi(var8009de9c)
/*  f0e53ec:	8fa40150 */ 	lw	$a0,0x150($sp)
/*  f0e53f0:	46000506 */ 	mov.s	$f20,$f0
/*  f0e53f4:	ac20de9c */ 	sw	$zero,%lo(var8009de9c)($at)
/*  f0e53f8:	0fc3528f */ 	jal	func0f0d4a3c
/*  f0e53fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e5400:	3c0afffe */ 	lui	$t2,0xfffe
/*  f0e5404:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f0e5408:	354a7960 */ 	ori	$t2,$t2,0x7960
/*  f0e540c:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0e5410:	ac2ade90 */ 	sw	$t2,%lo(var8009de90)($at)
/*  f0e5414:	3c0b0001 */ 	lui	$t3,0x1
/*  f0e5418:	356b86a0 */ 	ori	$t3,$t3,0x86a0
/*  f0e541c:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0e5420:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e5424:	11800022 */ 	beqz	$t4,.L0f0e54b0
/*  f0e5428:	ac2bde94 */ 	sw	$t3,%lo(var8009de94)($at)
/*  f0e542c:	3c026060 */ 	lui	$v0,0x6060
/*  f0e5430:	3442607f */ 	ori	$v0,$v0,0x607f
/*  f0e5434:	240dfff6 */ 	addiu	$t5,$zero,-10
/*  f0e5438:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e543c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0e5440:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e5444:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e5448:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e544c:	2406fff6 */ 	addiu	$a2,$zero,-10
/*  f0e5450:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e5454:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f0e5458:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e545c:	afb20150 */ 	sw	$s2,0x150($sp)
/*  f0e5460:	0c002f06 */ 	jal	viGetHeight
/*  f0e5464:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e5468:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e546c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0e5470:	0c002f06 */ 	jal	viGetHeight
/*  f0e5474:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0e5478:	3c039090 */ 	lui	$v1,0x9090
/*  f0e547c:	3463907f */ 	ori	$v1,$v1,0x907f
/*  f0e5480:	244f000a */ 	addiu	$t7,$v0,0xa
/*  f0e5484:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e5488:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e548c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e5490:	8fa40150 */ 	lw	$a0,0x150($sp)
/*  f0e5494:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e5498:	2606000a */ 	addiu	$a2,$s0,0xa
/*  f0e549c:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e54a0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e54a4:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f0e54a8:	10000023 */ 	b	.L0f0e5538
/*  f0e54ac:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e54b0:
/*  f0e54b0:	2418fff6 */ 	addiu	$t8,$zero,-10
/*  f0e54b4:	3419947f */ 	dli	$t9,0x947f
/*  f0e54b8:	3409947f */ 	dli	$t1,0x947f
/*  f0e54bc:	240a000a */ 	addiu	$t2,$zero,0xa
/*  f0e54c0:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0e54c4:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0e54c8:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e54cc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e54d0:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e54d4:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e54d8:	2406fff6 */ 	addiu	$a2,$zero,-10
/*  f0e54dc:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e54e0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e54e4:	afb20150 */ 	sw	$s2,0x150($sp)
/*  f0e54e8:	0c002f06 */ 	jal	viGetHeight
/*  f0e54ec:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e54f0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e54f4:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0e54f8:	0c002f06 */ 	jal	viGetHeight
/*  f0e54fc:	01608025 */ 	or	$s0,$t3,$zero
/*  f0e5500:	3c036200 */ 	lui	$v1,0x6200
/*  f0e5504:	3463947f */ 	ori	$v1,$v1,0x947f
/*  f0e5508:	244c000a */ 	addiu	$t4,$v0,0xa
/*  f0e550c:	240d0006 */ 	addiu	$t5,$zero,0x6
/*  f0e5510:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e5514:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e5518:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e551c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e5520:	8fa40150 */ 	lw	$a0,0x150($sp)
/*  f0e5524:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e5528:	2606000a */ 	addiu	$a2,$s0,0xa
/*  f0e552c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e5530:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e5534:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e5538:
/*  f0e5538:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e553c:	0fc35320 */ 	jal	func0f0d4c80
/*  f0e5540:	afb20150 */ 	sw	$s2,0x150($sp)
/*  f0e5544:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e5548:	0fc35272 */ 	jal	func0f0d49c8
/*  f0e554c:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e5550:	3c05800b */ 	lui	$a1,%hi(g_TexGeneralConfigs)
/*  f0e5554:	8ca5b5a8 */ 	lw	$a1,%lo(g_TexGeneralConfigs)($a1)
/*  f0e5558:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0e555c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e5560:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e5564:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e5568:	27a40150 */ 	addiu	$a0,$sp,0x150
/*  f0e556c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e5570:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0e5574:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e5578:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e557c:	0fc2ce70 */ 	jal	texSelect
/*  f0e5580:	24a5000c */ 	addiu	$a1,$a1,0x000c
/*  f0e5584:	8fb80150 */ 	lw	$t8,0x150($sp)
/*  f0e5588:	3c09ba00 */ 	lui	$t1,0xba00
/*  f0e558c:	35291402 */ 	ori	$t1,$t1,0x1402
/*  f0e5590:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e5594:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f0e5598:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0e559c:	af090000 */ 	sw	$t1,0x0($t8)
/*  f0e55a0:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0e55a4:	3c0cba00 */ 	lui	$t4,0xba00
/*  f0e55a8:	358c0602 */ 	ori	$t4,$t4,0x602
/*  f0e55ac:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e55b0:	afab0150 */ 	sw	$t3,0x150($sp)
/*  f0e55b4:	240d00c0 */ 	addiu	$t5,$zero,0xc0
/*  f0e55b8:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0e55bc:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0e55c0:	8fae0150 */ 	lw	$t6,0x150($sp)
/*  f0e55c4:	3c18b900 */ 	lui	$t8,0xb900
/*  f0e55c8:	3c190050 */ 	lui	$t9,0x50
/*  f0e55cc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e55d0:	afaf0150 */ 	sw	$t7,0x150($sp)
/*  f0e55d4:	373949d8 */ 	ori	$t9,$t9,0x49d8
/*  f0e55d8:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f0e55dc:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e55e0:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e55e4:	8fa90150 */ 	lw	$t1,0x150($sp)
/*  f0e55e8:	3c0bb900 */ 	lui	$t3,0xb900
/*  f0e55ec:	356b0002 */ 	ori	$t3,$t3,0x2
/*  f0e55f0:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0e55f4:	afaa0150 */ 	sw	$t2,0x150($sp)
/*  f0e55f8:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f0e55fc:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0e5600:	8fac0150 */ 	lw	$t4,0x150($sp)
/*  f0e5604:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0e5608:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f0e560c:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0e5610:	afad0150 */ 	sw	$t5,0x150($sp)
/*  f0e5614:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f0e5618:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0e561c:	8faf0150 */ 	lw	$t7,0x150($sp)
/*  f0e5620:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0e5624:	37390903 */ 	ori	$t9,$t9,0x903
/*  f0e5628:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e562c:	afb80150 */ 	sw	$t8,0x150($sp)
/*  f0e5630:	24090c00 */ 	addiu	$t1,$zero,0xc00
/*  f0e5634:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f0e5638:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e563c:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0e5640:	3c0cfcff */ 	lui	$t4,0xfcff
/*  f0e5644:	3c0dff32 */ 	lui	$t5,0xff32
/*  f0e5648:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e564c:	afab0150 */ 	sw	$t3,0x150($sp)
/*  f0e5650:	35ad7f3f */ 	ori	$t5,$t5,0x7f3f
/*  f0e5654:	358c99ff */ 	ori	$t4,$t4,0x99ff
/*  f0e5658:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0e565c:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0e5660:	8fae0150 */ 	lw	$t6,0x150($sp)
/*  f0e5664:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0e5668:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f0e566c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e5670:	afaf0150 */ 	sw	$t7,0x150($sp)
/*  f0e5674:	24192000 */ 	addiu	$t9,$zero,0x2000
/*  f0e5678:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e567c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e5680:	8fa90150 */ 	lw	$t1,0x150($sp)
/*  f0e5684:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0e5688:	27b00110 */ 	addiu	$s0,$sp,0x110
/*  f0e568c:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0e5690:	afaa0150 */ 	sw	$t2,0x150($sp)
/*  f0e5694:	356b1301 */ 	ori	$t3,$t3,0x1301
/*  f0e5698:	3c0c0008 */ 	lui	$t4,0x8
/*  f0e569c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e56a0:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f0e56a4:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0e56a8:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0e56ac:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0e56b0:	00000000 */ 	nop
/*  f0e56b4:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e56b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e56bc:	0c005815 */ 	jal	mtx00016054
/*  f0e56c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0e56c4:	8fb00150 */ 	lw	$s0,0x150($sp)
/*  f0e56c8:	3c0f0102 */ 	lui	$t7,0x102
/*  f0e56cc:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f0e56d0:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f0e56d4:	afae0150 */ 	sw	$t6,0x150($sp)
/*  f0e56d8:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e56dc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e56e0:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f0e56e4:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0e56e8:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0e56ec:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e56f0:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f0e56f4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e56f8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e56fc:	1300004b */ 	beqz	$t8,.L0f0e582c
/*  f0e5700:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e5704:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5708:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e570c:	2408ff00 */ 	addiu	$t0,$zero,-256
/*  f0e5710:	2407007f */ 	addiu	$a3,$zero,0x7f
/*  f0e5714:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f0e5718:	0263c823 */ 	subu	$t9,$s3,$v1
.L0f0e571c:
/*  f0e571c:	03270019 */ 	multu	$t9,$a3
/*  f0e5720:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5724:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e5728:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e572c:	00004812 */ 	mflo	$t1
/*  f0e5730:	00000000 */ 	nop
/*  f0e5734:	00000000 */ 	nop
/*  f0e5738:	0125001b */ 	divu	$zero,$t1,$a1
/*  f0e573c:	00005012 */ 	mflo	$t2
/*  f0e5740:	01485825 */ 	or	$t3,$t2,$t0
/*  f0e5744:	14a00002 */ 	bnez	$a1,.L0f0e5750
/*  f0e5748:	00000000 */ 	nop
/*  f0e574c:	0007000d */ 	break	0x7
.L0f0e5750:
/*  f0e5750:	ac8bfff0 */ 	sw	$t3,-0x10($a0)
/*  f0e5754:	5420fff1 */ 	bnezl	$at,.L0f0e571c
/*  f0e5758:	0263c823 */ 	subu	$t9,$s3,$v1
/*  f0e575c:	3c06aaaa */ 	lui	$a2,0xaaaa
/*  f0e5760:	34c6aa00 */ 	ori	$a2,$a2,0xaa00
/*  f0e5764:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5768:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e576c:
/*  f0e576c:	02636023 */ 	subu	$t4,$s3,$v1
/*  f0e5770:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e5774:	01a5001b */ 	divu	$zero,$t5,$a1
/*  f0e5778:	00007012 */ 	mflo	$t6
/*  f0e577c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5780:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e5784:	01c67825 */ 	or	$t7,$t6,$a2
/*  f0e5788:	14a00002 */ 	bnez	$a1,.L0f0e5794
/*  f0e578c:	00000000 */ 	nop
/*  f0e5790:	0007000d */ 	break	0x7
.L0f0e5794:
/*  f0e5794:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0e5798:	1420fff4 */ 	bnez	$at,.L0f0e576c
/*  f0e579c:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e57a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e57a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e57a8:	0263c023 */ 	subu	$t8,$s3,$v1
.L0f0e57ac:
/*  f0e57ac:	03070019 */ 	multu	$t8,$a3
/*  f0e57b0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e57b4:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e57b8:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e57bc:	0000c812 */ 	mflo	$t9
/*  f0e57c0:	00000000 */ 	nop
/*  f0e57c4:	00000000 */ 	nop
/*  f0e57c8:	0325001b */ 	divu	$zero,$t9,$a1
/*  f0e57cc:	00004812 */ 	mflo	$t1
/*  f0e57d0:	01285025 */ 	or	$t2,$t1,$t0
/*  f0e57d4:	14a00002 */ 	bnez	$a1,.L0f0e57e0
/*  f0e57d8:	00000000 */ 	nop
/*  f0e57dc:	0007000d */ 	break	0x7
.L0f0e57e0:
/*  f0e57e0:	ac8afff8 */ 	sw	$t2,-0x8($a0)
/*  f0e57e4:	5420fff1 */ 	bnezl	$at,.L0f0e57ac
/*  f0e57e8:	0263c023 */ 	subu	$t8,$s3,$v1
/*  f0e57ec:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e57f0:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e57f4:
/*  f0e57f4:	02635823 */ 	subu	$t3,$s3,$v1
/*  f0e57f8:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0e57fc:	0185001b */ 	divu	$zero,$t4,$a1
/*  f0e5800:	00006812 */ 	mflo	$t5
/*  f0e5804:	01a67025 */ 	or	$t6,$t5,$a2
/*  f0e5808:	14a00002 */ 	bnez	$a1,.L0f0e5814
/*  f0e580c:	00000000 */ 	nop
/*  f0e5810:	0007000d */ 	break	0x7
.L0f0e5814:
/*  f0e5814:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5818:	ac8e000c */ 	sw	$t6,0xc($a0)
/*  f0e581c:	1473fff5 */ 	bne	$v1,$s3,.L0f0e57f4
/*  f0e5820:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e5824:	1000004a */ 	b	.L0f0e5950
/*  f0e5828:	8fb30150 */ 	lw	$s3,0x150($sp)
.L0f0e582c:
/*  f0e582c:	2408ff00 */ 	addiu	$t0,$zero,-256
/*  f0e5830:	2407007f */ 	addiu	$a3,$zero,0x7f
/*  f0e5834:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f0e5838:	02637823 */ 	subu	$t7,$s3,$v1
.L0f0e583c:
/*  f0e583c:	01e70019 */ 	multu	$t7,$a3
/*  f0e5840:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5844:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e5848:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e584c:	0000c012 */ 	mflo	$t8
/*  f0e5850:	00000000 */ 	nop
/*  f0e5854:	00000000 */ 	nop
/*  f0e5858:	0305001b */ 	divu	$zero,$t8,$a1
/*  f0e585c:	0000c812 */ 	mflo	$t9
/*  f0e5860:	03284825 */ 	or	$t1,$t9,$t0
/*  f0e5864:	14a00002 */ 	bnez	$a1,.L0f0e5870
/*  f0e5868:	00000000 */ 	nop
/*  f0e586c:	0007000d */ 	break	0x7
.L0f0e5870:
/*  f0e5870:	ac89fff0 */ 	sw	$t1,-0x10($a0)
/*  f0e5874:	5420fff1 */ 	bnezl	$at,.L0f0e583c
/*  f0e5878:	02637823 */ 	subu	$t7,$s3,$v1
/*  f0e587c:	3c06aaaa */ 	lui	$a2,0xaaaa
/*  f0e5880:	34c6ff00 */ 	ori	$a2,$a2,0xff00
/*  f0e5884:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5888:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e588c:
/*  f0e588c:	02635023 */ 	subu	$t2,$s3,$v1
/*  f0e5890:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0e5894:	0165001b */ 	divu	$zero,$t3,$a1
/*  f0e5898:	00006012 */ 	mflo	$t4
/*  f0e589c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e58a0:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e58a4:	01866825 */ 	or	$t5,$t4,$a2
/*  f0e58a8:	14a00002 */ 	bnez	$a1,.L0f0e58b4
/*  f0e58ac:	00000000 */ 	nop
/*  f0e58b0:	0007000d */ 	break	0x7
.L0f0e58b4:
/*  f0e58b4:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f0e58b8:	1420fff4 */ 	bnez	$at,.L0f0e588c
/*  f0e58bc:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e58c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e58c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e58c8:	02637023 */ 	subu	$t6,$s3,$v1
.L0f0e58cc:
/*  f0e58cc:	01c70019 */ 	multu	$t6,$a3
/*  f0e58d0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e58d4:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e58d8:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e58dc:	00007812 */ 	mflo	$t7
/*  f0e58e0:	00000000 */ 	nop
/*  f0e58e4:	00000000 */ 	nop
/*  f0e58e8:	01e5001b */ 	divu	$zero,$t7,$a1
/*  f0e58ec:	0000c012 */ 	mflo	$t8
/*  f0e58f0:	0308c825 */ 	or	$t9,$t8,$t0
/*  f0e58f4:	14a00002 */ 	bnez	$a1,.L0f0e5900
/*  f0e58f8:	00000000 */ 	nop
/*  f0e58fc:	0007000d */ 	break	0x7
.L0f0e5900:
/*  f0e5900:	ac99fff8 */ 	sw	$t9,-0x8($a0)
/*  f0e5904:	5420fff1 */ 	bnezl	$at,.L0f0e58cc
/*  f0e5908:	02637023 */ 	subu	$t6,$s3,$v1
/*  f0e590c:	3c06ffaa */ 	lui	$a2,0xffaa
/*  f0e5910:	34c6ff00 */ 	ori	$a2,$a2,0xff00
/*  f0e5914:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5918:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e591c:
/*  f0e591c:	02634823 */ 	subu	$t1,$s3,$v1
/*  f0e5920:	00095100 */ 	sll	$t2,$t1,0x4
/*  f0e5924:	0145001b */ 	divu	$zero,$t2,$a1
/*  f0e5928:	00005812 */ 	mflo	$t3
/*  f0e592c:	01666025 */ 	or	$t4,$t3,$a2
/*  f0e5930:	14a00002 */ 	bnez	$a1,.L0f0e593c
/*  f0e5934:	00000000 */ 	nop
/*  f0e5938:	0007000d */ 	break	0x7
.L0f0e593c:
/*  f0e593c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5940:	ac8c000c */ 	sw	$t4,0xc($a0)
/*  f0e5944:	1473fff5 */ 	bne	$v1,$s3,.L0f0e591c
/*  f0e5948:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e594c:	8fb30150 */ 	lw	$s3,0x150($sp)
.L0f0e5950:
/*  f0e5950:	3c0f074c */ 	lui	$t7,0x74c
/*  f0e5954:	35ef0050 */ 	ori	$t7,$t7,0x50
/*  f0e5958:	266e0008 */ 	addiu	$t6,$s3,0x8
/*  f0e595c:	afae0150 */ 	sw	$t6,0x150($sp)
/*  f0e5960:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e5964:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e5968:	ae6f0000 */ 	sw	$t7,0x0($s3)
/*  f0e596c:	ae620004 */ 	sw	$v0,0x4($s3)
/*  f0e5970:	3c017f1b */ 	lui	$at,%hi(var7f1adf84)
/*  f0e5974:	c42adf84 */ 	lwc1	$f10,%lo(var7f1adf84)($at)
/*  f0e5978:	3c017f1b */ 	lui	$at,%hi(var7f1adf88)
/*  f0e597c:	c43edf88 */ 	lwc1	$f30,%lo(var7f1adf88)($at)
/*  f0e5980:	460aa002 */ 	mul.s	$f0,$f20,$f10
/*  f0e5984:	3c014170 */ 	lui	$at,0x4170
/*  f0e5988:	4481e000 */ 	mtc1	$at,$f28
/*  f0e598c:	3c017f1b */ 	lui	$at,%hi(var7f1adf8c)
/*  f0e5990:	c43adf8c */ 	lwc1	$f26,%lo(var7f1adf8c)($at)
/*  f0e5994:	3c0141c8 */ 	lui	$at,0x41c8
/*  f0e5998:	4481b000 */ 	mtc1	$at,$f22
/*  f0e599c:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f0e59a0:	24120117 */ 	addiu	$s2,$zero,0x117
/*  f0e59a4:	24100d14 */ 	addiu	$s0,$zero,0xd14
.L0f0e59a8:
/*  f0e59a8:	44922000 */ 	mtc1	$s2,$f4
/*  f0e59ac:	c7a00070 */ 	lwc1	$f0,0x70($sp)
/*  f0e59b0:	00009825 */ 	or	$s3,$zero,$zero
/*  f0e59b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e59b8:	461c3483 */ 	div.s	$f18,$f6,$f28
/*  f0e59bc:	4612d202 */ 	mul.s	$f8,$f26,$f18
/*  f0e59c0:	46080500 */ 	add.s	$f20,$f0,$f8
/*  f0e59c4:	0c0068f7 */ 	jal	sinf
/*  f0e59c8:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e59cc:	46000606 */ 	mov.s	$f24,$f0
/*  f0e59d0:	0c0068f4 */ 	jal	cosf
/*  f0e59d4:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e59d8:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e59dc:	46000506 */ 	mov.s	$f20,$f0
/*  f0e59e0:	3c017f1b */ 	lui	$at,%hi(var7f1adf90)
/*  f0e59e4:	03101821 */ 	addu	$v1,$t8,$s0
/*  f0e59e8:	c4700000 */ 	lwc1	$f16,0x0($v1)
/*  f0e59ec:	e7b000b8 */ 	swc1	$f16,0xb8($sp)
/*  f0e59f0:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f0e59f4:	e7aa00bc */ 	swc1	$f10,0xbc($sp)
/*  f0e59f8:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0e59fc:	e7a400c0 */ 	swc1	$f4,0xc0($sp)
/*  f0e5a00:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f0e5a04:	c7a000c0 */ 	lwc1	$f0,0xc0($sp)
/*  f0e5a08:	461e303c */ 	c.lt.s	$f6,$f30
/*  f0e5a0c:	00000000 */ 	nop
/*  f0e5a10:	4502000e */ 	bc1fl	.L0f0e5a4c
/*  f0e5a14:	44808000 */ 	mtc1	$zero,$f16
/*  f0e5a18:	c432df90 */ 	lwc1	$f18,%lo(var7f1adf90)($at)
/*  f0e5a1c:	3c0144af */ 	lui	$at,0x44af
/*  f0e5a20:	44815000 */ 	mtc1	$at,$f10
/*  f0e5a24:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f0e5a28:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0e5a2c:	44813000 */ 	mtc1	$at,$f6
/*  f0e5a30:	46004407 */ 	neg.s	$f16,$f8
/*  f0e5a34:	460a8103 */ 	div.s	$f4,$f16,$f10
/*  f0e5a38:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f0e5a3c:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5a40:	44134000 */ 	mfc1	$s3,$f8
/*  f0e5a44:	00000000 */ 	nop
/*  f0e5a48:	44808000 */ 	mtc1	$zero,$f16
.L0f0e5a4c:
/*  f0e5a4c:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0e5a50:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0e5a54:	00000000 */ 	nop
/*  f0e5a58:	4502008d */ 	bc1fl	.L0f0e5c90
/*  f0e5a5c:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f0e5a60:	5020008b */ 	beqzl	$at,.L0f0e5c90
/*  f0e5a64:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f0e5a68:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0e5a6c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e5a70:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0e5a74:	4600c007 */ 	neg.s	$f0,$f24
/*  f0e5a78:	4600a087 */ 	neg.s	$f2,$f20
/*  f0e5a7c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0e5a80:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e5a84:	440a2000 */ 	mfc1	$t2,$f4
/*  f0e5a88:	4614c100 */ 	add.s	$f4,$f24,$f20
/*  f0e5a8c:	a44a0000 */ 	sh	$t2,0x0($v0)
/*  f0e5a90:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f0e5a94:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5a98:	4604b182 */ 	mul.s	$f6,$f22,$f4
/*  f0e5a9c:	4600a100 */ 	add.s	$f4,$f20,$f0
/*  f0e5aa0:	440c9000 */ 	mfc1	$t4,$f18
/*  f0e5aa4:	00000000 */ 	nop
/*  f0e5aa8:	a44c0002 */ 	sh	$t4,0x2($v0)
/*  f0e5aac:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5ab0:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f0e5ab4:	440e8000 */ 	mfc1	$t6,$f16
/*  f0e5ab8:	00000000 */ 	nop
/*  f0e5abc:	a44e0004 */ 	sh	$t6,0x4($v0)
/*  f0e5ac0:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0e5ac4:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f0e5ac8:	4604b282 */ 	mul.s	$f10,$f22,$f4
/*  f0e5acc:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5ad0:	44184000 */ 	mfc1	$t8,$f8
/*  f0e5ad4:	00000000 */ 	nop
/*  f0e5ad8:	a458000c */ 	sh	$t8,0xc($v0)
/*  f0e5adc:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*  f0e5ae0:	460a8180 */ 	add.s	$f6,$f16,$f10
/*  f0e5ae4:	4614c281 */ 	sub.s	$f10,$f24,$f20
/*  f0e5ae8:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5aec:	460ab182 */ 	mul.s	$f6,$f22,$f10
/*  f0e5af0:	4600a281 */ 	sub.s	$f10,$f20,$f0
/*  f0e5af4:	44099000 */ 	mfc1	$t1,$f18
/*  f0e5af8:	00000000 */ 	nop
/*  f0e5afc:	a449000e */ 	sh	$t1,0xe($v0)
/*  f0e5b00:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5b04:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0e5b08:	440b2000 */ 	mfc1	$t3,$f4
/*  f0e5b0c:	00000000 */ 	nop
/*  f0e5b10:	a44b0010 */ 	sh	$t3,0x10($v0)
/*  f0e5b14:	c7b000b8 */ 	lwc1	$f16,0xb8($sp)
/*  f0e5b18:	46068480 */ 	add.s	$f18,$f16,$f6
/*  f0e5b1c:	460ab402 */ 	mul.s	$f16,$f22,$f10
/*  f0e5b20:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5b24:	440d4000 */ 	mfc1	$t5,$f8
/*  f0e5b28:	00000000 */ 	nop
/*  f0e5b2c:	a44d0018 */ 	sh	$t5,0x18($v0)
/*  f0e5b30:	c7a400bc */ 	lwc1	$f4,0xbc($sp)
/*  f0e5b34:	46102180 */ 	add.s	$f6,$f4,$f16
/*  f0e5b38:	46140401 */ 	sub.s	$f16,$f0,$f20
/*  f0e5b3c:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5b40:	4610b182 */ 	mul.s	$f6,$f22,$f16
/*  f0e5b44:	46001401 */ 	sub.s	$f16,$f2,$f0
/*  f0e5b48:	440f9000 */ 	mfc1	$t7,$f18
/*  f0e5b4c:	00000000 */ 	nop
/*  f0e5b50:	a44f001a */ 	sh	$t7,0x1a($v0)
/*  f0e5b54:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5b58:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e5b5c:	44195000 */ 	mfc1	$t9,$f10
/*  f0e5b60:	00000000 */ 	nop
/*  f0e5b64:	a459001c */ 	sh	$t9,0x1c($v0)
/*  f0e5b68:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f0e5b6c:	46062480 */ 	add.s	$f18,$f4,$f6
/*  f0e5b70:	4610b102 */ 	mul.s	$f4,$f22,$f16
/*  f0e5b74:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5b78:	440a4000 */ 	mfc1	$t2,$f8
/*  f0e5b7c:	00000000 */ 	nop
/*  f0e5b80:	a44a0024 */ 	sh	$t2,0x24($v0)
/*  f0e5b84:	c7aa00bc */ 	lwc1	$f10,0xbc($sp)
/*  f0e5b88:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0e5b8c:	46140100 */ 	add.s	$f4,$f0,$f20
/*  f0e5b90:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5b94:	4604b182 */ 	mul.s	$f6,$f22,$f4
/*  f0e5b98:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f0e5b9c:	440c9000 */ 	mfc1	$t4,$f18
/*  f0e5ba0:	00000000 */ 	nop
/*  f0e5ba4:	a44c0026 */ 	sh	$t4,0x26($v0)
/*  f0e5ba8:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5bac:	00136080 */ 	sll	$t4,$s3,0x2
/*  f0e5bb0:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f0e5bb4:	440e8000 */ 	mfc1	$t6,$f16
/*  f0e5bb8:	00000000 */ 	nop
/*  f0e5bbc:	a44e0028 */ 	sh	$t6,0x28($v0)
/*  f0e5bc0:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0e5bc4:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f0e5bc8:	4604b282 */ 	mul.s	$f10,$f22,$f4
/*  f0e5bcc:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5bd0:	44184000 */ 	mfc1	$t8,$f8
/*  f0e5bd4:	00000000 */ 	nop
/*  f0e5bd8:	a4580030 */ 	sh	$t8,0x30($v0)
/*  f0e5bdc:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*  f0e5be0:	460a8180 */ 	add.s	$f6,$f16,$f10
/*  f0e5be4:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5be8:	44099000 */ 	mfc1	$t1,$f18
/*  f0e5bec:	00000000 */ 	nop
/*  f0e5bf0:	a4490032 */ 	sh	$t1,0x32($v0)
/*  f0e5bf4:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5bf8:	3c090440 */ 	lui	$t1,0x440
/*  f0e5bfc:	3529003c */ 	ori	$t1,$t1,0x3c
/*  f0e5c00:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0e5c04:	440b2000 */ 	mfc1	$t3,$f4
/*  f0e5c08:	00000000 */ 	nop
/*  f0e5c0c:	a44b0034 */ 	sh	$t3,0x34($v0)
/*  f0e5c10:	06410004 */ 	bgez	$s2,.L0f0e5c24
/*  f0e5c14:	324d0001 */ 	andi	$t5,$s2,0x1
/*  f0e5c18:	11a00002 */ 	beqz	$t5,.L0f0e5c24
/*  f0e5c1c:	00000000 */ 	nop
/*  f0e5c20:	25adfffe */ 	addiu	$t5,$t5,-2
.L0f0e5c24:
/*  f0e5c24:	000d7040 */ 	sll	$t6,$t5,0x1
/*  f0e5c28:	018e1821 */ 	addu	$v1,$t4,$t6
/*  f0e5c2c:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0e5c30:	25e50004 */ 	addiu	$a1,$t7,0x4
/*  f0e5c34:	a04f0007 */ 	sb	$t7,0x7($v0)
/*  f0e5c38:	a0450013 */ 	sb	$a1,0x13($v0)
/*  f0e5c3c:	a085001f */ 	sb	$a1,0x1f($a0)
/*  f0e5c40:	a085002b */ 	sb	$a1,0x2b($a0)
/*  f0e5c44:	a0850037 */ 	sb	$a1,0x37($a0)
/*  f0e5c48:	8fb80150 */ 	lw	$t8,0x150($sp)
/*  f0e5c4c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e5c50:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f0e5c54:	af090000 */ 	sw	$t1,0x0($t8)
/*  f0e5c58:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e5c5c:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f0e5c60:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0e5c64:	3c0db100 */ 	lui	$t5,0xb100
/*  f0e5c68:	3c0c4030 */ 	lui	$t4,0x4030
/*  f0e5c6c:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f0e5c70:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0e5c74:	358c2010 */ 	ori	$t4,$t4,0x2010
/*  f0e5c78:	35ad1432 */ 	ori	$t5,$t5,0x1432
/*  f0e5c7c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e5c80:	afab0150 */ 	sw	$t3,0x150($sp)
/*  f0e5c84:	ad4c0004 */ 	sw	$t4,0x4($t2)
/*  f0e5c88:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f0e5c8c:	2652ffff */ 	addiu	$s2,$s2,-1
.L0f0e5c90:
/*  f0e5c90:	0641ff45 */ 	bgez	$s2,.L0f0e59a8
/*  f0e5c94:	2610fff4 */ 	addiu	$s0,$s0,-12
/*  f0e5c98:	0fc351e7 */ 	jal	func0f0d479c
/*  f0e5c9c:	8fa40150 */ 	lw	$a0,0x150($sp)
.L0f0e5ca0:
/*  f0e5ca0:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0e5ca4:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0e5ca8:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f0e5cac:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f0e5cb0:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f0e5cb4:	d7bc0040 */ 	ldc1	$f28,0x40($sp)
/*  f0e5cb8:	d7be0048 */ 	ldc1	$f30,0x48($sp)
/*  f0e5cbc:	8fb00054 */ 	lw	$s0,0x54($sp)
/*  f0e5cc0:	8fb10058 */ 	lw	$s1,0x58($sp)
/*  f0e5cc4:	8fb2005c */ 	lw	$s2,0x5c($sp)
/*  f0e5cc8:	8fb30060 */ 	lw	$s3,0x60($sp)
/*  f0e5ccc:	03e00008 */ 	jr	$ra
/*  f0e5cd0:	27bd0150 */ 	addiu	$sp,$sp,0x150
);
#endif
