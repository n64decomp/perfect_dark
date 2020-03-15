#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

const u32 var7f1a8680[] = {0xb8d1b717};
const u32 var7f1a8684[] = {0x00000000};
const u32 var7f1a8688[] = {0x00000000};
const u32 var7f1a868c[] = {0x00000000};

GLOBAL_ASM(
glabel sparksTick
/*  f01e050:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f01e054:	3c0b8008 */ 	lui	$t3,%hi(var8007f0b8)
/*  f01e058:	256bf0b8 */ 	addiu	$t3,$t3,%lo(var8007f0b8)
/*  f01e05c:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f01e060:	afb5001c */ 	sw	$s5,0x1c($sp)
/*  f01e064:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f01e068:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f01e06c:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f01e070:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f01e074:	11c0006d */ 	beqz	$t6,.L0f01e22c
/*  f01e078:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f01e07c:	ad600000 */ 	sw	$zero,0x0($t3)
/*  f01e080:	3c02800a */ 	lui	$v0,%hi(var800a3fc8)
/*  f01e084:	3c017f1b */ 	lui	$at,%hi(var7f1a8680)
/*  f01e088:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f01e08c:	3c14800a */ 	lui	$s4,%hi(var800a3fc0)
/*  f01e090:	3c12800a */ 	lui	$s2,%hi(var800a34d0)
/*  f01e094:	3c0c8008 */ 	lui	$t4,%hi(sparktable)
/*  f01e098:	44807000 */ 	mtc1	$zero,$f14
/*  f01e09c:	24423fc8 */ 	addiu	$v0,$v0,%lo(var800a3fc8)
/*  f01e0a0:	258cec80 */ 	addiu	$t4,$t4,%lo(sparktable)
/*  f01e0a4:	265234d0 */ 	addiu	$s2,$s2,%lo(var800a34d0)
/*  f01e0a8:	26943fc0 */ 	addiu	$s4,$s4,%lo(var800a3fc0)
/*  f01e0ac:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f01e0b0:	c4308680 */ 	lwc1	$f16,%lo(var7f1a8680)($at)
/*  f01e0b4:	00001825 */ 	or	$v1,$zero,$zero
/*  f01e0b8:	2413001c */ 	addiu	$s3,$zero,0x1c
/*  f01e0bc:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f01e0c0:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f01e0c4:	240d0028 */ 	addiu	$t5,$zero,0x28
.L0f01e0c8:
/*  f01e0c8:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f01e0cc:	8c450008 */ 	lw	$a1,0x8($v0)
/*  f01e0d0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f01e0d4:	01ed0019 */ 	multu	$t7,$t5
/*  f01e0d8:	0000c012 */ 	mflo	$t8
/*  f01e0dc:	01982021 */ 	addu	$a0,$t4,$t8
/*  f01e0e0:	94990010 */ 	lhu	$t9,0x10($a0)
/*  f01e0e4:	00b9082a */ 	slt	$at,$a1,$t9
/*  f01e0e8:	14200003 */ 	bnez	$at,.L0f01e0f8
/*  f01e0ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e0f0:	1000004c */ 	beqz	$zero,.L0f01e224
/*  f01e0f4:	ac400008 */ 	sw	$zero,0x8($v0)
.L0f01e0f8:
/*  f01e0f8:	10a0004a */ 	beqz	$a1,.L0f01e224
/*  f01e0fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e100:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f01e104:	00002825 */ 	or	$a1,$zero,$zero
/*  f01e108:	8ea60038 */ 	lw	$a2,0x38($s5)
/*  f01e10c:	15c00002 */ 	bnez	$t6,.L0f01e118
/*  f01e110:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e114:	ad710000 */ 	sw	$s1,0x0($t3)
.L0f01e118:
/*  f01e118:	18c00042 */ 	blez	$a2,.L0f01e224
/*  f01e11c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e120:	8c4a0004 */ 	lw	$t2,0x4($v0)
/*  f01e124:	8c46000c */ 	lw	$a2,0xc($v0)
.L0f01e128:
/*  f01e128:	8c4f0008 */ 	lw	$t7,0x8($v0)
/*  f01e12c:	00004825 */ 	or	$t1,$zero,$zero
/*  f01e130:	00d30019 */ 	multu	$a2,$s3
/*  f01e134:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f01e138:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f01e13c:	0000c812 */ 	mflo	$t9
/*  f01e140:	02594021 */ 	addu	$t0,$s2,$t9
/*  f01e144:	19400032 */ 	blez	$t2,.L0f01e210
/*  f01e148:	01003825 */ 	or	$a3,$t0,$zero
/*  f01e14c:	8cee0018 */ 	lw	$t6,0x18($a3)
.L0f01e150:
/*  f01e150:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f01e154:	2508001c */ 	addiu	$t0,$t0,0x1c
/*  f01e158:	11c00026 */ 	beqz	$t6,.L0f01e1f4
/*  f01e15c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01e160:	c4e0000c */ 	lwc1	$f0,0xc($a3)
/*  f01e164:	c4840024 */ 	lwc1	$f4,0x24($a0)
/*  f01e168:	c4e20010 */ 	lwc1	$f2,0x10($a3)
/*  f01e16c:	c4ec0014 */ 	lwc1	$f12,0x14($a3)
/*  f01e170:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f01e174:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f01e178:	e4e8000c */ 	swc1	$f8,0xc($a3)
/*  f01e17c:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01e180:	c486000c */ 	lwc1	$f6,0xc($a0)
/*  f01e184:	460a1482 */ 	mul.s	$f18,$f2,$f10
/*  f01e188:	46121101 */ 	sub.s	$f4,$f2,$f18
/*  f01e18c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f01e190:	e4e80010 */ 	swc1	$f8,0x10($a3)
/*  f01e194:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f01e198:	c4e20010 */ 	lwc1	$f2,0x10($a3)
/*  f01e19c:	460a6482 */ 	mul.s	$f18,$f12,$f10
/*  f01e1a0:	46027032 */ 	c.eq.s	$f14,$f2
/*  f01e1a4:	46126101 */ 	sub.s	$f4,$f12,$f18
/*  f01e1a8:	45000003 */ 	bc1f	.L0f01e1b8
/*  f01e1ac:	e4e40014 */ 	swc1	$f4,0x14($a3)
/*  f01e1b0:	e4f00010 */ 	swc1	$f16,0x10($a3)
/*  f01e1b4:	c4e20010 */ 	lwc1	$f2,0x10($a3)
.L0f01e1b8:
/*  f01e1b8:	c4e60000 */ 	lwc1	$f6,0x0($a3)
/*  f01e1bc:	c4e8000c */ 	lwc1	$f8,0xc($a3)
/*  f01e1c0:	c4f20004 */ 	lwc1	$f18,0x4($a3)
/*  f01e1c4:	8cef0018 */ 	lw	$t7,0x18($a3)
/*  f01e1c8:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f01e1cc:	c4e80014 */ 	lwc1	$f8,0x14($a3)
/*  f01e1d0:	c4e60008 */ 	lwc1	$f6,0x8($a3)
/*  f01e1d4:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f01e1d8:	e4ea0000 */ 	swc1	$f10,0x0($a3)
/*  f01e1dc:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f01e1e0:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f01e1e4:	e4e40004 */ 	swc1	$f4,0x4($a3)
/*  f01e1e8:	acf80018 */ 	sw	$t8,0x18($a3)
/*  f01e1ec:	e4ea0008 */ 	swc1	$f10,0x8($a3)
/*  f01e1f0:	8c4a0004 */ 	lw	$t2,0x4($v0)
.L0f01e1f4:
/*  f01e1f4:	15140003 */ 	bne	$t0,$s4,.L0f01e204
/*  f01e1f8:	012a082a */ 	slt	$at,$t1,$t2
/*  f01e1fc:	10000002 */ 	beqz	$zero,.L0f01e208
/*  f01e200:	02403825 */ 	or	$a3,$s2,$zero
.L0f01e204:
/*  f01e204:	24e7001c */ 	addiu	$a3,$a3,0x1c
.L0f01e208:
/*  f01e208:	5420ffd1 */ 	bnezl	$at,.L0f01e150
/*  f01e20c:	8cee0018 */ 	lw	$t6,0x18($a3)
.L0f01e210:
/*  f01e210:	8eb90038 */ 	lw	$t9,0x38($s5)
/*  f01e214:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f01e218:	00b9082a */ 	slt	$at,$a1,$t9
/*  f01e21c:	5420ffc2 */ 	bnezl	$at,.L0f01e128
/*  f01e220:	8c46000c */ 	lw	$a2,0xc($v0)
.L0f01e224:
/*  f01e224:	1470ffa8 */ 	bne	$v1,$s0,.L0f01e0c8
/*  f01e228:	24420024 */ 	addiu	$v0,$v0,0x24
.L0f01e22c:
/*  f01e22c:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f01e230:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f01e234:	8fb20010 */ 	lw	$s2,0x10($sp)
/*  f01e238:	8fb30014 */ 	lw	$s3,0x14($sp)
/*  f01e23c:	8fb40018 */ 	lw	$s4,0x18($sp)
/*  f01e240:	8fb5001c */ 	lw	$s5,0x1c($sp)
/*  f01e244:	03e00008 */ 	jr	$ra
/*  f01e248:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f01e24c:	00000000 */ 	sll	$zero,$zero,0x0
);
