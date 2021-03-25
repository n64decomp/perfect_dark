#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

u32 var8009ca70;

const u32 var70059fd0[] = {0x3c8efa35};

GLOBAL_ASM(
glabel func0004f9b0
/*    4f9b0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    4f9b4:	3c017006 */ 	lui	$at,%hi(var70059fd0)
/*    4f9b8:	c4249fd0 */ 	lwc1	$f4,%lo(var70059fd0)($at)
/*    4f9bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4f9c0:	00808025 */ 	or	$s0,$a0,$zero
/*    4f9c4:	3c01800a */ 	lui	$at,%hi(var8009ca70)
/*    4f9c8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4f9cc:	afa50034 */ 	sw	$a1,0x34($sp)
/*    4f9d0:	afa60038 */ 	sw	$a2,0x38($sp)
/*    4f9d4:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    4f9d8:	27a60040 */ 	addiu	$a2,$sp,0x40
/*    4f9dc:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*    4f9e0:	27a40038 */ 	addiu	$a0,$sp,0x38
/*    4f9e4:	0c0011e4 */ 	jal	guNormalize
/*    4f9e8:	e424ca70 */ 	swc1	$f4,%lo(var8009ca70)($at)
/*    4f9ec:	3c01800a */ 	lui	$at,%hi(var8009ca70)
/*    4f9f0:	c7ac0034 */ 	lwc1	$f12,0x34($sp)
/*    4f9f4:	c426ca70 */ 	lwc1	$f6,%lo(var8009ca70)($at)
/*    4f9f8:	46066302 */ 	mul.s	$f12,$f12,$f6
/*    4f9fc:	0c0068f7 */ 	jal	sinf
/*    4fa00:	e7ac0034 */ 	swc1	$f12,0x34($sp)
/*    4fa04:	c7ac0034 */ 	lwc1	$f12,0x34($sp)
/*    4fa08:	0c0068f4 */ 	jal	cosf
/*    4fa0c:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*    4fa10:	c7ae0038 */ 	lwc1	$f14,0x38($sp)
/*    4fa14:	c7b20040 */ 	lwc1	$f18,0x40($sp)
/*    4fa18:	e7a00028 */ 	swc1	$f0,0x28($sp)
/*    4fa1c:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*    4fa20:	00000000 */ 	nop
/*    4fa24:	46129282 */ 	mul.s	$f10,$f18,$f18
/*    4fa28:	0c012974 */ 	jal	sqrtf
/*    4fa2c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*    4fa30:	02002025 */ 	or	$a0,$s0,$zero
/*    4fa34:	0c012918 */ 	jal	guMtxIdentF
/*    4fa38:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*    4fa3c:	44806000 */ 	mtc1	$zero,$f12
/*    4fa40:	c7ae0024 */ 	lwc1	$f14,0x24($sp)
/*    4fa44:	c7a20028 */ 	lwc1	$f2,0x28($sp)
/*    4fa48:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*    4fa4c:	460c7032 */ 	c.eq.s	$f14,$f12
/*    4fa50:	3c013f80 */ 	lui	$at,0x3f80
/*    4fa54:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    4fa58:	45030041 */ 	bc1tl	.L0004fb60
/*    4fa5c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4fa60:	44812000 */ 	mtc1	$at,$f4
/*    4fa64:	46068202 */ 	mul.s	$f8,$f16,$f6
/*    4fa68:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*    4fa6c:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*    4fa70:	460e2003 */ 	div.s	$f0,$f4,$f14
/*    4fa74:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*    4fa78:	46003207 */ 	neg.s	$f8,$f6
/*    4fa7c:	46024282 */ 	mul.s	$f10,$f8,$f2
/*    4fa80:	46045181 */ 	sub.s	$f6,$f10,$f4
/*    4fa84:	46003202 */ 	mul.s	$f8,$f6,$f0
/*    4fa88:	e6080000 */ 	swc1	$f8,0x0($s0)
/*    4fa8c:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*    4fa90:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*    4fa94:	460a1102 */ 	mul.s	$f4,$f2,$f10
/*    4fa98:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*    4fa9c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    4faa0:	00000000 */ 	nop
/*    4faa4:	46105102 */ 	mul.s	$f4,$f10,$f16
/*    4faa8:	46082181 */ 	sub.s	$f6,$f4,$f8
/*    4faac:	46003282 */ 	mul.s	$f10,$f6,$f0
/*    4fab0:	e60a0010 */ 	swc1	$f10,0x10($s0)
/*    4fab4:	460e8182 */ 	mul.s	$f6,$f16,$f14
/*    4fab8:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*    4fabc:	e60c0030 */ 	swc1	$f12,0x30($s0)
/*    4fac0:	460e1282 */ 	mul.s	$f10,$f2,$f14
/*    4fac4:	46002207 */ 	neg.s	$f8,$f4
/*    4fac8:	e6080020 */ 	swc1	$f8,0x20($s0)
/*    4facc:	e6060004 */ 	swc1	$f6,0x4($s0)
/*    4fad0:	e60a0014 */ 	swc1	$f10,0x14($s0)
/*    4fad4:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*    4fad8:	e60c0034 */ 	swc1	$f12,0x34($s0)
/*    4fadc:	46002207 */ 	neg.s	$f8,$f4
/*    4fae0:	e6080024 */ 	swc1	$f8,0x24($s0)
/*    4fae4:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    4fae8:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*    4faec:	46068282 */ 	mul.s	$f10,$f16,$f6
/*    4faf0:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*    4faf4:	46045202 */ 	mul.s	$f8,$f10,$f4
/*    4faf8:	00000000 */ 	nop
/*    4fafc:	46061282 */ 	mul.s	$f10,$f2,$f6
/*    4fb00:	46085101 */ 	sub.s	$f4,$f10,$f8
/*    4fb04:	46008287 */ 	neg.s	$f10,$f16
/*    4fb08:	46002182 */ 	mul.s	$f6,$f4,$f0
/*    4fb0c:	e6060008 */ 	swc1	$f6,0x8($s0)
/*    4fb10:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*    4fb14:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    4fb18:	46085102 */ 	mul.s	$f4,$f10,$f8
/*    4fb1c:	c7a80040 */ 	lwc1	$f8,0x40($sp)
/*    4fb20:	46061282 */ 	mul.s	$f10,$f2,$f6
/*    4fb24:	00000000 */ 	nop
/*    4fb28:	46085182 */ 	mul.s	$f6,$f10,$f8
/*    4fb2c:	46062281 */ 	sub.s	$f10,$f4,$f6
/*    4fb30:	46005202 */ 	mul.s	$f8,$f10,$f0
/*    4fb34:	44815000 */ 	mtc1	$at,$f10
/*    4fb38:	e6080018 */ 	swc1	$f8,0x18($s0)
/*    4fb3c:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*    4fb40:	e60c0038 */ 	swc1	$f12,0x38($s0)
/*    4fb44:	e60c000c */ 	swc1	$f12,0xc($s0)
/*    4fb48:	46002187 */ 	neg.s	$f6,$f4
/*    4fb4c:	e60c001c */ 	swc1	$f12,0x1c($s0)
/*    4fb50:	e6060028 */ 	swc1	$f6,0x28($s0)
/*    4fb54:	e60c002c */ 	swc1	$f12,0x2c($s0)
/*    4fb58:	e60a003c */ 	swc1	$f10,0x3c($s0)
/*    4fb5c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004fb60:
/*    4fb60:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4fb64:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    4fb68:	03e00008 */ 	jr	$ra
/*    4fb6c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0004fb70
/*    4fb70:	44856000 */ 	mtc1	$a1,$f12
/*    4fb74:	44867000 */ 	mtc1	$a2,$f14
/*    4fb78:	44878000 */ 	mtc1	$a3,$f16
/*    4fb7c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*    4fb80:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*    4fb84:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4fb88:	afa40060 */ 	sw	$a0,0x60($sp)
/*    4fb8c:	44056000 */ 	mfc1	$a1,$f12
/*    4fb90:	44067000 */ 	mfc1	$a2,$f14
/*    4fb94:	44078000 */ 	mfc1	$a3,$f16
/*    4fb98:	27a40020 */ 	addiu	$a0,$sp,0x20
/*    4fb9c:	0c013e6c */ 	jal	func0004f9b0
/*    4fba0:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    4fba4:	27a40020 */ 	addiu	$a0,$sp,0x20
/*    4fba8:	0c0128d8 */ 	jal	guMtxF2L
/*    4fbac:	8fa50060 */ 	lw	$a1,0x60($sp)
/*    4fbb0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4fbb4:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*    4fbb8:	03e00008 */ 	jr	$ra
/*    4fbbc:	00000000 */ 	nop
);
