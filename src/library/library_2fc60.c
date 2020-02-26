#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_16110.h"
#include "library/library_2fc60.h"
#include "library/library_39fe0.h"
#include "types.h"

const u32 var700546b0[] = {0x3f83f794};
const u32 var700546b4[] = {0x40c90fdb};
const u32 var700546b8[] = {0x40c90fdb};
const u32 var700546bc[] = {0x4622f985};
const u32 var700546c0[] = {0x49742400};
const u32 var700546c4[] = {0x700304d0};
const u32 var700546c8[] = {0x700304d0};
const u32 var700546cc[] = {0x700304d0};
const u32 var700546d0[] = {0x700304d0};
const u32 var700546d4[] = {0x70030548};
const u32 var700546d8[] = {0x70030568};
const u32 var700546dc[] = {0x70030548};
const u32 var700546e0[] = {0x70030568};
const u32 var700546e4[] = {0x700305a0};
const u32 var700546e8[] = {0x70030548};
const u32 var700546ec[] = {0x70030548};
const u32 var700546f0[] = {0x70030568};
const u32 var700546f4[] = {0x48f42400};
const u32 var700546f8[] = {0x7003081c};
const u32 var700546fc[] = {0x7003081c};
const u32 var70054700[] = {0x7003081c};
const u32 var70054704[] = {0x7003081c};
const u32 var70054708[] = {0x7003085c};
const u32 var7005470c[] = {0x7003085c};
const u32 var70054710[] = {0x70030960};
const u32 var70054714[] = {0x70030960};
const u32 var70054718[] = {0x70030998};
const u32 var7005471c[] = {0x70030998};
const u32 var70054720[] = {0x700309c4};
const u32 var70054724[] = {0x700309c4};
const u32 var70054728[] = {0x00000000};
const u32 var7005472c[] = {0x00000000};

GLOBAL_ASM(
glabel func0002fc60
/*    2fc60:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    2fc64:	308400ff */ 	andi	$a0,$a0,0xff
/*    2fc68:	3c017005 */ 	lui	$at,%hi(var700546b0)
/*    2fc6c:	c42446b0 */ 	lwc1	$f4,%lo(var700546b0)($at)
/*    2fc70:	e7a40004 */ 	swc1	$f4,0x4($sp)
/*    2fc74:	3c013f80 */ 	lui	$at,0x3f80
/*    2fc78:	44813000 */ 	mtc1	$at,$f6
/*    2fc7c:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fc80:	e7a60000 */ 	swc1	$f6,0x0($sp)
/*    2fc84:	1080000f */ 	beqz	$a0,.L0002fcc4
/*    2fc88:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fc8c:
/*    2fc8c:	308e0001 */ 	andi	$t6,$a0,0x1
/*    2fc90:	11c00005 */ 	beqz	$t6,.L0002fca8
/*    2fc94:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fc98:	c7a80000 */ 	lwc1	$f8,0x0($sp)
/*    2fc9c:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*    2fca0:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    2fca4:	e7b00000 */ 	swc1	$f16,0x0($sp)
.L0002fca8:
/*    2fca8:	c7b20004 */ 	lwc1	$f18,0x4($sp)
/*    2fcac:	46129102 */ 	mul.s	$f4,$f18,$f18
/*    2fcb0:	e7a40004 */ 	swc1	$f4,0x4($sp)
/*    2fcb4:	00042042 */ 	srl	$a0,$a0,0x1
/*    2fcb8:	308400ff */ 	andi	$a0,$a0,0xff
/*    2fcbc:	1480fff3 */ 	bnez	$a0,.L0002fc8c
/*    2fcc0:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fcc4:
/*    2fcc4:	10000003 */ 	beqz	$zero,.L0002fcd4
/*    2fcc8:	c7a00000 */ 	lwc1	$f0,0x0($sp)
/*    2fccc:	10000001 */ 	beqz	$zero,.L0002fcd4
/*    2fcd0:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fcd4:
/*    2fcd4:	03e00008 */ 	jr	$ra
/*    2fcd8:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*    2fcdc:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    2fce0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    2fce4:	afa40040 */ 	sw	$a0,0x40($sp)
/*    2fce8:	afa50044 */ 	sw	$a1,0x44($sp)
/*    2fcec:	afa60048 */ 	sw	$a2,0x48($sp)
/*    2fcf0:	afa7004c */ 	sw	$a3,0x4c($sp)
/*    2fcf4:	afb00028 */ 	sw	$s0,0x28($sp)
/*    2fcf8:	afa00038 */ 	sw	$zero,0x38($sp)
/*    2fcfc:	93ae0057 */ 	lbu	$t6,0x57($sp)
/*    2fd00:	15c00003 */ 	bnez	$t6,.L0002fd10
/*    2fd04:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fd08:	10000067 */ 	beqz	$zero,.L0002fea8
/*    2fd0c:	00001025 */ 	or	$v0,$zero,$zero
.L0002fd10:
/*    2fd10:	93af004b */ 	lbu	$t7,0x4b($sp)
/*    2fd14:	24010001 */ 	addiu	$at,$zero,0x1
/*    2fd18:	11e10011 */ 	beq	$t7,$at,.L0002fd60
/*    2fd1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fd20:	24010080 */ 	addiu	$at,$zero,0x80
/*    2fd24:	11e1000e */ 	beq	$t7,$at,.L0002fd60
/*    2fd28:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fd2c:	93b80053 */ 	lbu	$t8,0x53($sp)
/*    2fd30:	93b90057 */ 	lbu	$t9,0x57($sp)
/*    2fd34:	93a8005b */ 	lbu	$t0,0x5b($sp)
/*    2fd38:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    2fd3c:	8fa50044 */ 	lw	$a1,0x44($sp)
/*    2fd40:	93a6004b */ 	lbu	$a2,0x4b($sp)
/*    2fd44:	93a7004f */ 	lbu	$a3,0x4f($sp)
/*    2fd48:	afb80010 */ 	sw	$t8,0x10($sp)
/*    2fd4c:	afb90014 */ 	sw	$t9,0x14($sp)
/*    2fd50:	0c00c079 */ 	jal	func000301e4
/*    2fd54:	afa80018 */ 	sw	$t0,0x18($sp)
/*    2fd58:	10000053 */ 	beqz	$zero,.L0002fea8
/*    2fd5c:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fd60:
/*    2fd60:	3c09800a */ 	lui	$t1,0x800a
/*    2fd64:	8d29b870 */ 	lw	$t1,-0x4790($t1)
/*    2fd68:	1120004b */ 	beqz	$t1,.L0002fe98
/*    2fd6c:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fd70:	3c0a800a */ 	lui	$t2,0x800a
/*    2fd74:	8d4ab870 */ 	lw	$t2,-0x4790($t2)
/*    2fd78:	afaa003c */ 	sw	$t2,0x3c($sp)
/*    2fd7c:	3c0b800a */ 	lui	$t3,0x800a
/*    2fd80:	8d6bb870 */ 	lw	$t3,-0x4790($t3)
/*    2fd84:	3c01800a */ 	lui	$at,0x800a
/*    2fd88:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    2fd8c:	ac2cb870 */ 	sw	$t4,-0x4790($at)
/*    2fd90:	93ad004b */ 	lbu	$t5,0x4b($sp)
/*    2fd94:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    2fd98:	a1cd0004 */ 	sb	$t5,0x4($t6)
/*    2fd9c:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    2fda0:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    2fda4:	af0f0000 */ 	sw	$t7,0x0($t8)
/*    2fda8:	93b90057 */ 	lbu	$t9,0x57($sp)
/*    2fdac:	00194380 */ 	sll	$t0,$t9,0xe
/*    2fdb0:	afa80038 */ 	sw	$t0,0x38($sp)
/*    2fdb4:	93b0004b */ 	lbu	$s0,0x4b($sp)
/*    2fdb8:	24010001 */ 	addiu	$at,$zero,0x1
/*    2fdbc:	12010006 */ 	beq	$s0,$at,.L0002fdd8
/*    2fdc0:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fdc4:	24010080 */ 	addiu	$at,$zero,0x80
/*    2fdc8:	12010020 */ 	beq	$s0,$at,.L0002fe4c
/*    2fdcc:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fdd0:	1000002f */ 	beqz	$zero,.L0002fe90
/*    2fdd4:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fdd8:
/*    2fdd8:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    2fddc:	a5200024 */ 	sh	$zero,0x24($t1)
/*    2fde0:	93aa004f */ 	lbu	$t2,0x4f($sp)
/*    2fde4:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    2fde8:	240b0103 */ 	addiu	$t3,$zero,0x103
/*    2fdec:	016a6023 */ 	subu	$t4,$t3,$t2
/*    2fdf0:	a5ac0022 */ 	sh	$t4,0x22($t5)
/*    2fdf4:	93ae0053 */ 	lbu	$t6,0x53($sp)
/*    2fdf8:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    2fdfc:	000e7843 */ 	sra	$t7,$t6,0x1
/*    2fe00:	a30f0028 */ 	sb	$t7,0x28($t8)
/*    2fe04:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    2fe08:	2409007f */ 	addiu	$t1,$zero,0x7f
/*    2fe0c:	93280028 */ 	lbu	$t0,0x28($t9)
/*    2fe10:	01285823 */ 	subu	$t3,$t1,$t0
/*    2fe14:	a32b0029 */ 	sb	$t3,0x29($t9)
/*    2fe18:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    2fe1c:	914c0029 */ 	lbu	$t4,0x29($t2)
/*    2fe20:	448c2000 */ 	mtc1	$t4,$f4
/*    2fe24:	05810005 */ 	bgez	$t4,.L0002fe3c
/*    2fe28:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    2fe2c:	3c014f80 */ 	lui	$at,0x4f80
/*    2fe30:	44814000 */ 	mtc1	$at,$f8
/*    2fe34:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fe38:	46083180 */ 	add.s	$f6,$f6,$f8
.L0002fe3c:
/*    2fe3c:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    2fe40:	e5a60000 */ 	swc1	$f6,0x0($t5)
/*    2fe44:	10000014 */ 	beqz	$zero,.L0002fe98
/*    2fe48:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fe4c:
/*    2fe4c:	0c00bf18 */ 	jal	func0002fc60
/*    2fe50:	93a40053 */ 	lbu	$a0,0x53($sp)
/*    2fe54:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    2fe58:	e5c00028 */ 	swc1	$f0,0x28($t6)
/*    2fe5c:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    2fe60:	a5e00024 */ 	sh	$zero,0x24($t7)
/*    2fe64:	93b8004f */ 	lbu	$t8,0x4f($sp)
/*    2fe68:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    2fe6c:	24090103 */ 	addiu	$t1,$zero,0x103
/*    2fe70:	01384023 */ 	subu	$t0,$t1,$t8
/*    2fe74:	a5680022 */ 	sh	$t0,0x22($t3)
/*    2fe78:	3c013f80 */ 	lui	$at,0x3f80
/*    2fe7c:	44815000 */ 	mtc1	$at,$f10
/*    2fe80:	8fb90044 */ 	lw	$t9,0x44($sp)
/*    2fe84:	e72a0000 */ 	swc1	$f10,0x0($t9)
/*    2fe88:	10000003 */ 	beqz	$zero,.L0002fe98
/*    2fe8c:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fe90:
/*    2fe90:	10000001 */ 	beqz	$zero,.L0002fe98
/*    2fe94:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fe98:
/*    2fe98:	10000003 */ 	beqz	$zero,.L0002fea8
/*    2fe9c:	8fa20038 */ 	lw	$v0,0x38($sp)
/*    2fea0:	10000001 */ 	beqz	$zero,.L0002fea8
/*    2fea4:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fea8:
/*    2fea8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    2feac:	8fb00028 */ 	lw	$s0,0x28($sp)
/*    2feb0:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    2feb4:	03e00008 */ 	jr	$ra
/*    2feb8:	00000000 */ 	sll	$zero,$zero,0x0
/*    2febc:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    2fec0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    2fec4:	afa40030 */ 	sw	$a0,0x30($sp)
/*    2fec8:	afa50034 */ 	sw	$a1,0x34($sp)
/*    2fecc:	afb00018 */ 	sw	$s0,0x18($sp)
/*    2fed0:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    2fed4:	afae0028 */ 	sw	$t6,0x28($sp)
/*    2fed8:	240f3e80 */ 	addiu	$t7,$zero,0x3e80
/*    2fedc:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    2fee0:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    2fee4:	24010001 */ 	addiu	$at,$zero,0x1
/*    2fee8:	93190004 */ 	lbu	$t9,0x4($t8)
/*    2feec:	13210009 */ 	beq	$t9,$at,.L0002ff14
/*    2fef0:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fef4:	24010080 */ 	addiu	$at,$zero,0x80
/*    2fef8:	13210006 */ 	beq	$t9,$at,.L0002ff14
/*    2fefc:	00000000 */ 	sll	$zero,$zero,0x0
/*    2ff00:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    2ff04:	0c00c1a4 */ 	jal	func00030690
/*    2ff08:	8fa50034 */ 	lw	$a1,0x34($sp)
/*    2ff0c:	10000084 */ 	beqz	$zero,.L00030120
/*    2ff10:	00000000 */ 	sll	$zero,$zero,0x0
.L0002ff14:
/*    2ff14:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    2ff18:	24010001 */ 	addiu	$at,$zero,0x1
/*    2ff1c:	91100004 */ 	lbu	$s0,0x4($t0)
/*    2ff20:	12010006 */ 	beq	$s0,$at,.L0002ff3c
/*    2ff24:	00000000 */ 	sll	$zero,$zero,0x0
/*    2ff28:	24010080 */ 	addiu	$at,$zero,0x80
/*    2ff2c:	12010044 */ 	beq	$s0,$at,.L00030040
/*    2ff30:	00000000 */ 	sll	$zero,$zero,0x0
/*    2ff34:	10000074 */ 	beqz	$zero,.L00030108
/*    2ff38:	00000000 */ 	sll	$zero,$zero,0x0
.L0002ff3c:
/*    2ff3c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    2ff40:	952a0024 */ 	lhu	$t2,0x24($t1)
/*    2ff44:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    2ff48:	a52b0024 */ 	sh	$t3,0x24($t1)
/*    2ff4c:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    2ff50:	958d0024 */ 	lhu	$t5,0x24($t4)
/*    2ff54:	958e0022 */ 	lhu	$t6,0x22($t4)
/*    2ff58:	01ae082a */ 	slt	$at,$t5,$t6
/*    2ff5c:	14200003 */ 	bnez	$at,.L0002ff6c
/*    2ff60:	00000000 */ 	sll	$zero,$zero,0x0
/*    2ff64:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    2ff68:	a5e00024 */ 	sh	$zero,0x24($t7)
.L0002ff6c:
/*    2ff6c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    2ff70:	97190024 */ 	lhu	$t9,0x24($t8)
/*    2ff74:	44992000 */ 	mtc1	$t9,$f4
/*    2ff78:	07210005 */ 	bgez	$t9,.L0002ff90
/*    2ff7c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    2ff80:	3c014f80 */ 	lui	$at,0x4f80
/*    2ff84:	44814000 */ 	mtc1	$at,$f8
/*    2ff88:	00000000 */ 	sll	$zero,$zero,0x0
/*    2ff8c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0002ff90:
/*    2ff90:	97080022 */ 	lhu	$t0,0x22($t8)
/*    2ff94:	44885000 */ 	mtc1	$t0,$f10
/*    2ff98:	05010005 */ 	bgez	$t0,.L0002ffb0
/*    2ff9c:	46805420 */ 	cvt.s.w	$f16,$f10
/*    2ffa0:	3c014f80 */ 	lui	$at,0x4f80
/*    2ffa4:	44819000 */ 	mtc1	$at,$f18
/*    2ffa8:	00000000 */ 	sll	$zero,$zero,0x0
/*    2ffac:	46128400 */ 	add.s	$f16,$f16,$f18
.L0002ffb0:
/*    2ffb0:	46103103 */ 	div.s	$f4,$f6,$f16
/*    2ffb4:	e7a4002c */ 	swc1	$f4,0x2c($sp)
/*    2ffb8:	3c017005 */ 	lui	$at,%hi(var700546b4)
/*    2ffbc:	c42a46b4 */ 	lwc1	$f10,%lo(var700546b4)($at)
/*    2ffc0:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*    2ffc4:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*    2ffc8:	0c0068f7 */ 	jal	func0001a3dc
/*    2ffcc:	00000000 */ 	sll	$zero,$zero,0x0
/*    2ffd0:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*    2ffd4:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    2ffd8:	914b0028 */ 	lbu	$t3,0x28($t2)
/*    2ffdc:	448b9000 */ 	mtc1	$t3,$f18
/*    2ffe0:	05610005 */ 	bgez	$t3,.L0002fff8
/*    2ffe4:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    2ffe8:	3c014f80 */ 	lui	$at,0x4f80
/*    2ffec:	44818000 */ 	mtc1	$at,$f16
/*    2fff0:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fff4:	46103180 */ 	add.s	$f6,$f6,$f16
.L0002fff8:
/*    2fff8:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*    2fffc:	46043202 */ 	mul.s	$f8,$f6,$f4
/*    30000:	e7a8002c */ 	swc1	$f8,0x2c($sp)
/*    30004:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    30008:	912c0029 */ 	lbu	$t4,0x29($t1)
/*    3000c:	448c5000 */ 	mtc1	$t4,$f10
/*    30010:	05810005 */ 	bgez	$t4,.L00030028
/*    30014:	468054a0 */ 	cvt.s.w	$f18,$f10
/*    30018:	3c014f80 */ 	lui	$at,0x4f80
/*    3001c:	44818000 */ 	mtc1	$at,$f16
/*    30020:	00000000 */ 	sll	$zero,$zero,0x0
/*    30024:	46109480 */ 	add.s	$f18,$f18,$f16
.L00030028:
/*    30028:	c7a6002c */ 	lwc1	$f6,0x2c($sp)
/*    3002c:	8fad0034 */ 	lw	$t5,0x34($sp)
/*    30030:	46069100 */ 	add.s	$f4,$f18,$f6
/*    30034:	e5a40000 */ 	swc1	$f4,0x0($t5)
/*    30038:	10000035 */ 	beqz	$zero,.L00030110
/*    3003c:	00000000 */ 	sll	$zero,$zero,0x0
.L00030040:
/*    30040:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    30044:	95cf0024 */ 	lhu	$t7,0x24($t6)
/*    30048:	25f90001 */ 	addiu	$t9,$t7,0x1
/*    3004c:	a5d90024 */ 	sh	$t9,0x24($t6)
/*    30050:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    30054:	97080024 */ 	lhu	$t0,0x24($t8)
/*    30058:	970a0022 */ 	lhu	$t2,0x22($t8)
/*    3005c:	010a082a */ 	slt	$at,$t0,$t2
/*    30060:	14200003 */ 	bnez	$at,.L00030070
/*    30064:	00000000 */ 	sll	$zero,$zero,0x0
/*    30068:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    3006c:	a5600024 */ 	sh	$zero,0x24($t3)
.L00030070:
/*    30070:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    30074:	952c0024 */ 	lhu	$t4,0x24($t1)
/*    30078:	448c4000 */ 	mtc1	$t4,$f8
/*    3007c:	05810005 */ 	bgez	$t4,.L00030094
/*    30080:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    30084:	3c014f80 */ 	lui	$at,0x4f80
/*    30088:	44818000 */ 	mtc1	$at,$f16
/*    3008c:	00000000 */ 	sll	$zero,$zero,0x0
/*    30090:	46105280 */ 	add.s	$f10,$f10,$f16
.L00030094:
/*    30094:	952d0022 */ 	lhu	$t5,0x22($t1)
/*    30098:	448d9000 */ 	mtc1	$t5,$f18
/*    3009c:	05a10005 */ 	bgez	$t5,.L000300b4
/*    300a0:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    300a4:	3c014f80 */ 	lui	$at,0x4f80
/*    300a8:	44812000 */ 	mtc1	$at,$f4
/*    300ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    300b0:	46043180 */ 	add.s	$f6,$f6,$f4
.L000300b4:
/*    300b4:	46065203 */ 	div.s	$f8,$f10,$f6
/*    300b8:	e7a8002c */ 	swc1	$f8,0x2c($sp)
/*    300bc:	3c017005 */ 	lui	$at,%hi(var700546b8)
/*    300c0:	c43246b8 */ 	lwc1	$f18,%lo(var700546b8)($at)
/*    300c4:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*    300c8:	46128302 */ 	mul.s	$f12,$f16,$f18
/*    300cc:	0c0068f7 */ 	jal	func0001a3dc
/*    300d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    300d4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    300d8:	c5e40028 */ 	lwc1	$f4,0x28($t7)
/*    300dc:	46040282 */ 	mul.s	$f10,$f0,$f4
/*    300e0:	e7aa002c */ 	swc1	$f10,0x2c($sp)
/*    300e4:	c7a6002c */ 	lwc1	$f6,0x2c($sp)
/*    300e8:	4600320d */ 	trunc.w.s	$f8,$f6
/*    300ec:	44044000 */ 	mfc1	$a0,$f8
/*    300f0:	0c00e7f8 */ 	jal	func00039fe0
/*    300f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    300f8:	8fae0034 */ 	lw	$t6,0x34($sp)
/*    300fc:	e5c00000 */ 	swc1	$f0,0x0($t6)
/*    30100:	10000003 */ 	beqz	$zero,.L00030110
/*    30104:	00000000 */ 	sll	$zero,$zero,0x0
.L00030108:
/*    30108:	10000001 */ 	beqz	$zero,.L00030110
/*    3010c:	00000000 */ 	sll	$zero,$zero,0x0
.L00030110:
/*    30110:	10000003 */ 	beqz	$zero,.L00030120
/*    30114:	8fa20024 */ 	lw	$v0,0x24($sp)
/*    30118:	10000001 */ 	beqz	$zero,.L00030120
/*    3011c:	00000000 */ 	sll	$zero,$zero,0x0
.L00030120:
/*    30120:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    30124:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    30128:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    3012c:	03e00008 */ 	jr	$ra
/*    30130:	00000000 */ 	sll	$zero,$zero,0x0
/*    30134:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    30138:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3013c:	afa40020 */ 	sw	$a0,0x20($sp)
/*    30140:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    30144:	afae001c */ 	sw	$t6,0x1c($sp)
/*    30148:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3014c:	24010001 */ 	addiu	$at,$zero,0x1
/*    30150:	91f80004 */ 	lbu	$t8,0x4($t7)
/*    30154:	13010006 */ 	beq	$t8,$at,.L00030170
/*    30158:	00000000 */ 	sll	$zero,$zero,0x0
/*    3015c:	24010080 */ 	addiu	$at,$zero,0x80
/*    30160:	13010003 */ 	beq	$t8,$at,.L00030170
/*    30164:	00000000 */ 	sll	$zero,$zero,0x0
/*    30168:	0c00c2f6 */ 	jal	func00030bd8
/*    3016c:	8fa40020 */ 	lw	$a0,0x20($sp)
.L00030170:
/*    30170:	3c19800a */ 	lui	$t9,0x800a
/*    30174:	8f39b870 */ 	lw	$t9,-0x4790($t9)
/*    30178:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3017c:	ad190000 */ 	sw	$t9,0x0($t0)
/*    30180:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    30184:	3c01800a */ 	lui	$at,0x800a
/*    30188:	ac29b870 */ 	sw	$t1,-0x4790($at)
/*    3018c:	10000001 */ 	beqz	$zero,.L00030194
/*    30190:	00000000 */ 	sll	$zero,$zero,0x0
.L00030194:
/*    30194:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    30198:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3019c:	03e00008 */ 	jr	$ra
/*    301a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000301a4
/*    301a4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    301a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    301ac:	e7ac0018 */ 	swc1	$f12,0x18($sp)
/*    301b0:	3c017005 */ 	lui	$at,%hi(var700546bc)
/*    301b4:	c42646bc */ 	lwc1	$f6,%lo(var700546bc)($at)
/*    301b8:	c7a40018 */ 	lwc1	$f4,0x18($sp)
/*    301bc:	0c0068f7 */ 	jal	func0001a3dc
/*    301c0:	46062303 */ 	div.s	$f12,$f4,$f6
/*    301c4:	10000003 */ 	beqz	$zero,.L000301d4
/*    301c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    301cc:	10000001 */ 	beqz	$zero,.L000301d4
/*    301d0:	00000000 */ 	sll	$zero,$zero,0x0
.L000301d4:
/*    301d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    301d8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    301dc:	03e00008 */ 	jr	$ra
/*    301e0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000301e4
/*    301e4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    301e8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    301ec:	afa40020 */ 	sw	$a0,0x20($sp)
/*    301f0:	afa50024 */ 	sw	$a1,0x24($sp)
/*    301f4:	afa60028 */ 	sw	$a2,0x28($sp)
/*    301f8:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    301fc:	93ae002f */ 	lbu	$t6,0x2f($sp)
/*    30200:	29c10064 */ 	slti	$at,$t6,0x64
/*    30204:	14200003 */ 	bnez	$at,.L00030214
/*    30208:	00000000 */ 	sll	$zero,$zero,0x0
/*    3020c:	240f0063 */ 	addiu	$t7,$zero,0x63
/*    30210:	a3af002f */ 	sb	$t7,0x2f($sp)
.L00030214:
/*    30214:	93b80037 */ 	lbu	$t8,0x37($sp)
/*    30218:	2b010080 */ 	slti	$at,$t8,0x80
/*    3021c:	14200003 */ 	bnez	$at,.L0003022c
/*    30220:	00000000 */ 	sll	$zero,$zero,0x0
/*    30224:	2419007f */ 	addiu	$t9,$zero,0x7f
/*    30228:	a3b90037 */ 	sb	$t9,0x37($sp)
.L0003022c:
/*    3022c:	93a8003b */ 	lbu	$t0,0x3b($sp)
/*    30230:	29010080 */ 	slti	$at,$t0,0x80
/*    30234:	14200003 */ 	bnez	$at,.L00030244
/*    30238:	00000000 */ 	sll	$zero,$zero,0x0
/*    3023c:	2409007f */ 	addiu	$t1,$zero,0x7f
/*    30240:	a3a9003b */ 	sb	$t1,0x3b($sp)
.L00030244:
/*    30244:	3c0a800a */ 	lui	$t2,0x800a
/*    30248:	8d4ab870 */ 	lw	$t2,-0x4790($t2)
/*    3024c:	15400003 */ 	bnez	$t2,.L0003025c
/*    30250:	00000000 */ 	sll	$zero,$zero,0x0
/*    30254:	1000010a */ 	beqz	$zero,.L00030680
/*    30258:	00001025 */ 	or	$v0,$zero,$zero
.L0003025c:
/*    3025c:	3c0b800a */ 	lui	$t3,0x800a
/*    30260:	8d6bb870 */ 	lw	$t3,-0x4790($t3)
/*    30264:	afab001c */ 	sw	$t3,0x1c($sp)
/*    30268:	93ac003b */ 	lbu	$t4,0x3b($sp)
/*    3026c:	15800009 */ 	bnez	$t4,.L00030294
/*    30270:	00000000 */ 	sll	$zero,$zero,0x0
/*    30274:	3c013f80 */ 	lui	$at,0x3f80
/*    30278:	44812000 */ 	mtc1	$at,$f4
/*    3027c:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    30280:	e5a40018 */ 	swc1	$f4,0x18($t5)
/*    30284:	44803000 */ 	mtc1	$zero,$f6
/*    30288:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    3028c:	10000013 */ 	beqz	$zero,.L000302dc
/*    30290:	e5c6001c */ 	swc1	$f6,0x1c($t6)
.L00030294:
/*    30294:	44804000 */ 	mtc1	$zero,$f8
/*    30298:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3029c:	e5e80018 */ 	swc1	$f8,0x18($t7)
/*    302a0:	93b8003b */ 	lbu	$t8,0x3b($sp)
/*    302a4:	3c088006 */ 	lui	$t0,0x8006
/*    302a8:	3c01467a */ 	lui	$at,0x467a
/*    302ac:	0018c880 */ 	sll	$t9,$t8,0x2
/*    302b0:	01194021 */ 	addu	$t0,$t0,$t9
/*    302b4:	8d08f150 */ 	lw	$t0,-0xeb0($t0)
/*    302b8:	44819000 */ 	mtc1	$at,$f18
/*    302bc:	3c013f80 */ 	lui	$at,0x3f80
/*    302c0:	44885000 */ 	mtc1	$t0,$f10
/*    302c4:	44813000 */ 	mtc1	$at,$f6
/*    302c8:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    302cc:	46805420 */ 	cvt.s.w	$f16,$f10
/*    302d0:	46128103 */ 	div.s	$f4,$f16,$f18
/*    302d4:	46043203 */ 	div.s	$f8,$f6,$f4
/*    302d8:	e528001c */ 	swc1	$f8,0x1c($t1)
.L000302dc:
/*    302dc:	93aa002b */ 	lbu	$t2,0x2b($sp)
/*    302e0:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    302e4:	a16a0004 */ 	sb	$t2,0x4($t3)
/*    302e8:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    302ec:	a5800014 */ 	sh	$zero,0x14($t4)
/*    302f0:	93ad002f */ 	lbu	$t5,0x2f($sp)
/*    302f4:	3c017005 */ 	lui	$at,%hi(var700546c0)
/*    302f8:	c42a46c0 */ 	lwc1	$f10,%lo(var700546c0)($at)
/*    302fc:	3c018006 */ 	lui	$at,0x8006
/*    30300:	000d7080 */ 	sll	$t6,$t5,0x2
/*    30304:	002e0821 */ 	addu	$at,$at,$t6
/*    30308:	c430f34c */ 	lwc1	$f16,-0xcb4($at)
/*    3030c:	3c01467a */ 	lui	$at,0x467a
/*    30310:	44813000 */ 	mtc1	$at,$f6
/*    30314:	46105483 */ 	div.s	$f18,$f10,$f16
/*    30318:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3031c:	46069103 */ 	div.s	$f4,$f18,$f6
/*    30320:	444ff800 */ 	cfc1	$t7,$31
/*    30324:	44d8f800 */ 	ctc1	$t8,$31
/*    30328:	00000000 */ 	sll	$zero,$zero,0x0
/*    3032c:	46002224 */ 	cvt.w.s	$f8,$f4
/*    30330:	4458f800 */ 	cfc1	$t8,$31
/*    30334:	00000000 */ 	sll	$zero,$zero,0x0
/*    30338:	33010004 */ 	andi	$at,$t8,0x4
/*    3033c:	33180078 */ 	andi	$t8,$t8,0x78
/*    30340:	13000014 */ 	beqz	$t8,.L00030394
/*    30344:	00000000 */ 	sll	$zero,$zero,0x0
/*    30348:	3c014f00 */ 	lui	$at,0x4f00
/*    3034c:	44814000 */ 	mtc1	$at,$f8
/*    30350:	24180001 */ 	addiu	$t8,$zero,0x1
/*    30354:	46082201 */ 	sub.s	$f8,$f4,$f8
/*    30358:	44d8f800 */ 	ctc1	$t8,$31
/*    3035c:	00000000 */ 	sll	$zero,$zero,0x0
/*    30360:	46004224 */ 	cvt.w.s	$f8,$f8
/*    30364:	4458f800 */ 	cfc1	$t8,$31
/*    30368:	00000000 */ 	sll	$zero,$zero,0x0
/*    3036c:	33010004 */ 	andi	$at,$t8,0x4
/*    30370:	33180078 */ 	andi	$t8,$t8,0x78
/*    30374:	17000005 */ 	bnez	$t8,.L0003038c
/*    30378:	00000000 */ 	sll	$zero,$zero,0x0
/*    3037c:	44184000 */ 	mfc1	$t8,$f8
/*    30380:	3c018000 */ 	lui	$at,0x8000
/*    30384:	10000007 */ 	beqz	$zero,.L000303a4
/*    30388:	0301c025 */ 	or	$t8,$t8,$at
.L0003038c:
/*    3038c:	10000005 */ 	beqz	$zero,.L000303a4
/*    30390:	2418ffff */ 	addiu	$t8,$zero,-1
.L00030394:
/*    30394:	44184000 */ 	mfc1	$t8,$f8
/*    30398:	00000000 */ 	sll	$zero,$zero,0x0
/*    3039c:	0700fffb */ 	bltz	$t8,.L0003038c
/*    303a0:	00000000 */ 	sll	$zero,$zero,0x0
.L000303a4:
/*    303a4:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    303a8:	44cff800 */ 	ctc1	$t7,$31
/*    303ac:	a7380016 */ 	sh	$t8,0x16($t9)
/*    303b0:	00000000 */ 	sll	$zero,$zero,0x0
/*    303b4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    303b8:	24083e80 */ 	addiu	$t0,$zero,0x3e80
/*    303bc:	ad280008 */ 	sw	$t0,0x8($t1)
/*    303c0:	93aa0033 */ 	lbu	$t2,0x33($sp)
/*    303c4:	448a5000 */ 	mtc1	$t2,$f10
/*    303c8:	05410005 */ 	bgez	$t2,.L000303e0
/*    303cc:	46805420 */ 	cvt.s.w	$f16,$f10
/*    303d0:	3c014f80 */ 	lui	$at,0x4f80
/*    303d4:	44819000 */ 	mtc1	$at,$f18
/*    303d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    303dc:	46128400 */ 	add.s	$f16,$f16,$f18
.L000303e0:
/*    303e0:	e7b00018 */ 	swc1	$f16,0x18($sp)
/*    303e4:	93ab002b */ 	lbu	$t3,0x2b($sp)
/*    303e8:	316c0080 */ 	andi	$t4,$t3,0x80
/*    303ec:	11800027 */ 	beqz	$t4,.L0003048c
/*    303f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    303f4:	444df800 */ 	cfc1	$t5,$31
/*    303f8:	24040001 */ 	addiu	$a0,$zero,0x1
/*    303fc:	44c4f800 */ 	ctc1	$a0,$31
/*    30400:	c7a60018 */ 	lwc1	$f6,0x18($sp)
/*    30404:	46003124 */ 	cvt.w.s	$f4,$f6
/*    30408:	4444f800 */ 	cfc1	$a0,$31
/*    3040c:	00000000 */ 	sll	$zero,$zero,0x0
/*    30410:	30810004 */ 	andi	$at,$a0,0x4
/*    30414:	30840078 */ 	andi	$a0,$a0,0x78
/*    30418:	10800014 */ 	beqz	$a0,.L0003046c
/*    3041c:	00000000 */ 	sll	$zero,$zero,0x0
/*    30420:	3c014f00 */ 	lui	$at,0x4f00
/*    30424:	44812000 */ 	mtc1	$at,$f4
/*    30428:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3042c:	46043101 */ 	sub.s	$f4,$f6,$f4
/*    30430:	44c4f800 */ 	ctc1	$a0,$31
/*    30434:	00000000 */ 	sll	$zero,$zero,0x0
/*    30438:	46002124 */ 	cvt.w.s	$f4,$f4
/*    3043c:	4444f800 */ 	cfc1	$a0,$31
/*    30440:	00000000 */ 	sll	$zero,$zero,0x0
/*    30444:	30810004 */ 	andi	$at,$a0,0x4
/*    30448:	30840078 */ 	andi	$a0,$a0,0x78
/*    3044c:	14800005 */ 	bnez	$a0,.L00030464
/*    30450:	00000000 */ 	sll	$zero,$zero,0x0
/*    30454:	44042000 */ 	mfc1	$a0,$f4
/*    30458:	3c018000 */ 	lui	$at,0x8000
/*    3045c:	10000007 */ 	beqz	$zero,.L0003047c
/*    30460:	00812025 */ 	or	$a0,$a0,$at
.L00030464:
/*    30464:	10000005 */ 	beqz	$zero,.L0003047c
/*    30468:	2404ffff */ 	addiu	$a0,$zero,-1
.L0003046c:
/*    3046c:	44042000 */ 	mfc1	$a0,$f4
/*    30470:	00000000 */ 	sll	$zero,$zero,0x0
/*    30474:	0480fffb */ 	bltz	$a0,.L00030464
/*    30478:	00000000 */ 	sll	$zero,$zero,0x0
.L0003047c:
/*    3047c:	44cdf800 */ 	ctc1	$t5,$31
/*    30480:	0c00bf18 */ 	jal	func0002fc60
/*    30484:	00000000 */ 	sll	$zero,$zero,0x0
/*    30488:	e7a00018 */ 	swc1	$f0,0x18($sp)
.L0003048c:
/*    3048c:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*    30490:	2401ff7f */ 	addiu	$at,$zero,-129
/*    30494:	01c17824 */ 	and	$t7,$t6,$at
/*    30498:	a3af002b */ 	sb	$t7,0x2b($sp)
/*    3049c:	93b8002b */ 	lbu	$t8,0x2b($sp)
/*    304a0:	2401ff7f */ 	addiu	$at,$zero,-129
/*    304a4:	0301c824 */ 	and	$t9,$t8,$at
/*    304a8:	2728fffe */ 	addiu	$t0,$t9,-2
/*    304ac:	2d01000c */ 	sltiu	$at,$t0,0xc
/*    304b0:	10200047 */ 	beqz	$at,.L000305d0
/*    304b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    304b8:	00084080 */ 	sll	$t0,$t0,0x2
/*    304bc:	3c017005 */ 	lui	$at,%hi(var700546c4)
/*    304c0:	00280821 */ 	addu	$at,$at,$t0
/*    304c4:	8c2846c4 */ 	lw	$t0,%lo(var700546c4)($at)
/*    304c8:	01000008 */ 	jr	$t0
/*    304cc:	00000000 */ 	sll	$zero,$zero,0x0
/*    304d0:	c7a80018 */ 	lwc1	$f8,0x18($sp)
/*    304d4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    304d8:	e528000c */ 	swc1	$f8,0xc($t1)
/*    304dc:	93aa002b */ 	lbu	$t2,0x2b($sp)
/*    304e0:	24010002 */ 	addiu	$at,$zero,0x2
/*    304e4:	15410006 */ 	bne	$t2,$at,.L00030500
/*    304e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    304ec:	c7aa0018 */ 	lwc1	$f10,0x18($sp)
/*    304f0:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    304f4:	46005487 */ 	neg.s	$f18,$f10
/*    304f8:	10000004 */ 	beqz	$zero,.L0003050c
/*    304fc:	e5720010 */ 	swc1	$f18,0x10($t3)
.L00030500:
/*    30500:	44808000 */ 	mtc1	$zero,$f16
/*    30504:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    30508:	e5900010 */ 	swc1	$f16,0x10($t4)
.L0003050c:
/*    3050c:	93ad002f */ 	lbu	$t5,0x2f($sp)
/*    30510:	3c017005 */ 	lui	$at,%hi(var700546f4)
/*    30514:	c42646f4 */ 	lwc1	$f6,%lo(var700546f4)($at)
/*    30518:	3c018006 */ 	lui	$at,0x8006
/*    3051c:	000d7080 */ 	sll	$t6,$t5,0x2
/*    30520:	002e0821 */ 	addu	$at,$at,$t6
/*    30524:	c424f34c */ 	lwc1	$f4,-0xcb4($at)
/*    30528:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3052c:	46043203 */ 	div.s	$f8,$f6,$f4
/*    30530:	4600428d */ 	trunc.w.s	$f10,$f8
/*    30534:	44185000 */ 	mfc1	$t8,$f10
/*    30538:	00000000 */ 	sll	$zero,$zero,0x0
/*    3053c:	af380008 */ 	sw	$t8,0x8($t9)
/*    30540:	10000025 */ 	beqz	$zero,.L000305d8
/*    30544:	00000000 */ 	sll	$zero,$zero,0x0
/*    30548:	44809000 */ 	mtc1	$zero,$f18
/*    3054c:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    30550:	e5120010 */ 	swc1	$f18,0x10($t0)
/*    30554:	c7b00018 */ 	lwc1	$f16,0x18($sp)
/*    30558:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3055c:	e530000c */ 	swc1	$f16,0xc($t1)
/*    30560:	1000001d */ 	beqz	$zero,.L000305d8
/*    30564:	00000000 */ 	sll	$zero,$zero,0x0
/*    30568:	3c014000 */ 	lui	$at,0x4000
/*    3056c:	44812000 */ 	mtc1	$at,$f4
/*    30570:	c7a60018 */ 	lwc1	$f6,0x18($sp)
/*    30574:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    30578:	46043203 */ 	div.s	$f8,$f6,$f4
/*    3057c:	e5480010 */ 	swc1	$f8,0x10($t2)
/*    30580:	3c014000 */ 	lui	$at,0x4000
/*    30584:	44819000 */ 	mtc1	$at,$f18
/*    30588:	c7aa0018 */ 	lwc1	$f10,0x18($sp)
/*    3058c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    30590:	46125403 */ 	div.s	$f16,$f10,$f18
/*    30594:	e570000c */ 	swc1	$f16,0xc($t3)
/*    30598:	1000000f */ 	beqz	$zero,.L000305d8
/*    3059c:	00000000 */ 	sll	$zero,$zero,0x0
/*    305a0:	c7a60018 */ 	lwc1	$f6,0x18($sp)
/*    305a4:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    305a8:	46003107 */ 	neg.s	$f4,$f6
/*    305ac:	e5840010 */ 	swc1	$f4,0x10($t4)
/*    305b0:	3c014000 */ 	lui	$at,0x4000
/*    305b4:	44815000 */ 	mtc1	$at,$f10
/*    305b8:	c7a80018 */ 	lwc1	$f8,0x18($sp)
/*    305bc:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    305c0:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*    305c4:	e5b2000c */ 	swc1	$f18,0xc($t5)
/*    305c8:	10000003 */ 	beqz	$zero,.L000305d8
/*    305cc:	00000000 */ 	sll	$zero,$zero,0x0
.L000305d0:
/*    305d0:	1000002b */ 	beqz	$zero,.L00030680
/*    305d4:	00001025 */ 	or	$v0,$zero,$zero
.L000305d8:
/*    305d8:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    305dc:	91cf0004 */ 	lbu	$t7,0x4($t6)
/*    305e0:	31f80080 */ 	andi	$t8,$t7,0x80
/*    305e4:	1300000a */ 	beqz	$t8,.L00030610
/*    305e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    305ec:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    305f0:	c7300010 */ 	lwc1	$f16,0x10($t9)
/*    305f4:	4600818d */ 	trunc.w.s	$f6,$f16
/*    305f8:	44043000 */ 	mfc1	$a0,$f6
/*    305fc:	0c00e7f8 */ 	jal	func00039fe0
/*    30600:	00000000 */ 	sll	$zero,$zero,0x0
/*    30604:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    30608:	10000008 */ 	beqz	$zero,.L0003062c
/*    3060c:	e5200000 */ 	swc1	$f0,0x0($t1)
.L00030610:
/*    30610:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    30614:	3c0142fe */ 	lui	$at,0x42fe
/*    30618:	44814000 */ 	mtc1	$at,$f8
/*    3061c:	c5440010 */ 	lwc1	$f4,0x10($t2)
/*    30620:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    30624:	46082280 */ 	add.s	$f10,$f4,$f8
/*    30628:	e56a0000 */ 	swc1	$f10,0x0($t3)
.L0003062c:
/*    3062c:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    30630:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    30634:	adac0000 */ 	sw	$t4,0x0($t5)
/*    30638:	3c0e800a */ 	lui	$t6,0x800a
/*    3063c:	8dceb870 */ 	lw	$t6,-0x4790($t6)
/*    30640:	3c01800a */ 	lui	$at,0x800a
/*    30644:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    30648:	ac2fb870 */ 	sw	$t7,-0x4790($at)
/*    3064c:	93b80037 */ 	lbu	$t8,0x37($sp)
/*    30650:	13000007 */ 	beqz	$t8,.L00030670
/*    30654:	00000000 */ 	sll	$zero,$zero,0x0
/*    30658:	93b90037 */ 	lbu	$t9,0x37($sp)
/*    3065c:	3c028006 */ 	lui	$v0,0x8006
/*    30660:	00194080 */ 	sll	$t0,$t9,0x2
/*    30664:	00481021 */ 	addu	$v0,$v0,$t0
/*    30668:	10000005 */ 	beqz	$zero,.L00030680
/*    3066c:	8c42f150 */ 	lw	$v0,-0xeb0($v0)
.L00030670:
/*    30670:	10000003 */ 	beqz	$zero,.L00030680
/*    30674:	24023e80 */ 	addiu	$v0,$zero,0x3e80
/*    30678:	10000001 */ 	beqz	$zero,.L00030680
/*    3067c:	00000000 */ 	sll	$zero,$zero,0x0
.L00030680:
/*    30680:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    30684:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    30688:	03e00008 */ 	jr	$ra
/*    3068c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00030690
/*    30690:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    30694:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    30698:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3069c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    306a0:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    306a4:	2401ff7f */ 	addiu	$at,$zero,-129
/*    306a8:	91cf0004 */ 	lbu	$t7,0x4($t6)
/*    306ac:	01e1c024 */ 	and	$t8,$t7,$at
/*    306b0:	2b010006 */ 	slti	$at,$t8,0x6
/*    306b4:	14200020 */ 	bnez	$at,.L00030738
/*    306b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    306bc:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    306c0:	97280014 */ 	lhu	$t0,0x14($t9)
/*    306c4:	25090001 */ 	addiu	$t1,$t0,0x1
/*    306c8:	a7290014 */ 	sh	$t1,0x14($t9)
/*    306cc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    306d0:	954b0014 */ 	lhu	$t3,0x14($t2)
/*    306d4:	954c0016 */ 	lhu	$t4,0x16($t2)
/*    306d8:	016c082a */ 	slt	$at,$t3,$t4
/*    306dc:	14200003 */ 	bnez	$at,.L000306ec
/*    306e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    306e4:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    306e8:	a5a00014 */ 	sh	$zero,0x14($t5)
.L000306ec:
/*    306ec:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    306f0:	95cf0014 */ 	lhu	$t7,0x14($t6)
/*    306f4:	448f2000 */ 	mtc1	$t7,$f4
/*    306f8:	05e10005 */ 	bgez	$t7,.L00030710
/*    306fc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    30700:	3c014f80 */ 	lui	$at,0x4f80
/*    30704:	44814000 */ 	mtc1	$at,$f8
/*    30708:	00000000 */ 	sll	$zero,$zero,0x0
/*    3070c:	46083180 */ 	add.s	$f6,$f6,$f8
.L00030710:
/*    30710:	95d80016 */ 	lhu	$t8,0x16($t6)
/*    30714:	44985000 */ 	mtc1	$t8,$f10
/*    30718:	07010005 */ 	bgez	$t8,.L00030730
/*    3071c:	46805420 */ 	cvt.s.w	$f16,$f10
/*    30720:	3c014f80 */ 	lui	$at,0x4f80
/*    30724:	44819000 */ 	mtc1	$at,$f18
/*    30728:	00000000 */ 	sll	$zero,$zero,0x0
/*    3072c:	46128400 */ 	add.s	$f16,$f16,$f18
.L00030730:
/*    30730:	46103103 */ 	div.s	$f4,$f6,$f16
/*    30734:	e7a40020 */ 	swc1	$f4,0x20($sp)
.L00030738:
/*    30738:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    3073c:	44805000 */ 	mtc1	$zero,$f10
/*    30740:	c508001c */ 	lwc1	$f8,0x1c($t0)
/*    30744:	460a4032 */ 	c.eq.s	$f8,$f10
/*    30748:	00000000 */ 	sll	$zero,$zero,0x0
/*    3074c:	45010015 */ 	bc1t	.L000307a4
/*    30750:	00000000 */ 	sll	$zero,$zero,0x0
/*    30754:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    30758:	c5320018 */ 	lwc1	$f18,0x18($t1)
/*    3075c:	c526001c */ 	lwc1	$f6,0x1c($t1)
/*    30760:	46069400 */ 	add.s	$f16,$f18,$f6
/*    30764:	e5300018 */ 	swc1	$f16,0x18($t1)
/*    30768:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3076c:	3c013f80 */ 	lui	$at,0x3f80
/*    30770:	44814000 */ 	mtc1	$at,$f8
/*    30774:	c7240018 */ 	lwc1	$f4,0x18($t9)
/*    30778:	4604403e */ 	c.le.s	$f8,$f4
/*    3077c:	00000000 */ 	sll	$zero,$zero,0x0
/*    30780:	45000008 */ 	bc1f	.L000307a4
/*    30784:	00000000 */ 	sll	$zero,$zero,0x0
/*    30788:	3c013f80 */ 	lui	$at,0x3f80
/*    3078c:	44815000 */ 	mtc1	$at,$f10
/*    30790:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    30794:	e54a0018 */ 	swc1	$f10,0x18($t2)
/*    30798:	44809000 */ 	mtc1	$zero,$f18
/*    3079c:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    307a0:	e572001c */ 	swc1	$f18,0x1c($t3)
.L000307a4:
/*    307a4:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    307a8:	c586000c */ 	lwc1	$f6,0xc($t4)
/*    307ac:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*    307b0:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    307b4:	3c013f80 */ 	lui	$at,0x3f80
/*    307b8:	44812000 */ 	mtc1	$at,$f4
/*    307bc:	c5b00018 */ 	lwc1	$f16,0x18($t5)
/*    307c0:	46048032 */ 	c.eq.s	$f16,$f4
/*    307c4:	00000000 */ 	sll	$zero,$zero,0x0
/*    307c8:	45010006 */ 	bc1t	.L000307e4
/*    307cc:	00000000 */ 	sll	$zero,$zero,0x0
/*    307d0:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    307d4:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*    307d8:	c5ea0018 */ 	lwc1	$f10,0x18($t7)
/*    307dc:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*    307e0:	e7b20024 */ 	swc1	$f18,0x24($sp)
.L000307e4:
/*    307e4:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    307e8:	2401ff7f */ 	addiu	$at,$zero,-129
/*    307ec:	91d80004 */ 	lbu	$t8,0x4($t6)
/*    307f0:	03014024 */ 	and	$t0,$t8,$at
/*    307f4:	2509fffe */ 	addiu	$t1,$t0,-2
/*    307f8:	2d21000c */ 	sltiu	$at,$t1,0xc
/*    307fc:	102000da */ 	beqz	$at,.L00030b68
/*    30800:	00000000 */ 	sll	$zero,$zero,0x0
/*    30804:	00094880 */ 	sll	$t1,$t1,0x2
/*    30808:	3c017005 */ 	lui	$at,%hi(var700546f8)
/*    3080c:	00290821 */ 	addu	$at,$at,$t1
/*    30810:	8c2946f8 */ 	lw	$t1,%lo(var700546f8)($at)
/*    30814:	01200008 */ 	jr	$t1
/*    30818:	00000000 */ 	sll	$zero,$zero,0x0
/*    3081c:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    30820:	972a0014 */ 	lhu	$t2,0x14($t9)
/*    30824:	11400004 */ 	beqz	$t2,.L00030838
/*    30828:	00000000 */ 	sll	$zero,$zero,0x0
/*    3082c:	c7a60024 */ 	lwc1	$f6,0x24($sp)
/*    30830:	10000004 */ 	beqz	$zero,.L00030844
/*    30834:	e7a60020 */ 	swc1	$f6,0x20($sp)
.L00030838:
/*    30838:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    3083c:	c5700010 */ 	lwc1	$f16,0x10($t3)
/*    30840:	e7b00020 */ 	swc1	$f16,0x20($sp)
.L00030844:
/*    30844:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    30848:	958d0014 */ 	lhu	$t5,0x14($t4)
/*    3084c:	39af0001 */ 	xori	$t7,$t5,0x1
/*    30850:	a58f0014 */ 	sh	$t7,0x14($t4)
/*    30854:	100000c4 */ 	beqz	$zero,.L00030b68
/*    30858:	00000000 */ 	sll	$zero,$zero,0x0
/*    3085c:	3c013e80 */ 	lui	$at,0x3e80
/*    30860:	44814000 */ 	mtc1	$at,$f8
/*    30864:	c7a40020 */ 	lwc1	$f4,0x20($sp)
/*    30868:	4608203c */ 	c.lt.s	$f4,$f8
/*    3086c:	00000000 */ 	sll	$zero,$zero,0x0
/*    30870:	4500000a */ 	bc1f	.L0003089c
/*    30874:	00000000 */ 	sll	$zero,$zero,0x0
/*    30878:	3c014080 */ 	lui	$at,0x4080
/*    3087c:	44815000 */ 	mtc1	$at,$f10
/*    30880:	c7b20024 */ 	lwc1	$f18,0x24($sp)
/*    30884:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*    30888:	46125182 */ 	mul.s	$f6,$f10,$f18
/*    3088c:	00000000 */ 	sll	$zero,$zero,0x0
/*    30890:	46068102 */ 	mul.s	$f4,$f16,$f6
/*    30894:	1000002b */ 	beqz	$zero,.L00030944
/*    30898:	e7a40020 */ 	swc1	$f4,0x20($sp)
.L0003089c:
/*    3089c:	3c013f40 */ 	lui	$at,0x3f40
/*    308a0:	44815000 */ 	mtc1	$at,$f10
/*    308a4:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*    308a8:	4608503e */ 	c.le.s	$f10,$f8
/*    308ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    308b0:	45000013 */ 	bc1f	.L00030900
/*    308b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    308b8:	3c013f40 */ 	lui	$at,0x3f40
/*    308bc:	44818000 */ 	mtc1	$at,$f16
/*    308c0:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*    308c4:	46109181 */ 	sub.s	$f6,$f18,$f16
/*    308c8:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*    308cc:	3c014080 */ 	lui	$at,0x4080
/*    308d0:	44812000 */ 	mtc1	$at,$f4
/*    308d4:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*    308d8:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*    308dc:	46082282 */ 	mul.s	$f10,$f4,$f8
/*    308e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    308e4:	460a9402 */ 	mul.s	$f16,$f18,$f10
/*    308e8:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*    308ec:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    308f0:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*    308f4:	46043201 */ 	sub.s	$f8,$f6,$f4
/*    308f8:	10000012 */ 	beqz	$zero,.L00030944
/*    308fc:	e7a80020 */ 	swc1	$f8,0x20($sp)
.L00030900:
/*    30900:	3c013e80 */ 	lui	$at,0x3e80
/*    30904:	44815000 */ 	mtc1	$at,$f10
/*    30908:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*    3090c:	460a9401 */ 	sub.s	$f16,$f18,$f10
/*    30910:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*    30914:	3c014080 */ 	lui	$at,0x4080
/*    30918:	44813000 */ 	mtc1	$at,$f6
/*    3091c:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*    30920:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*    30924:	46043202 */ 	mul.s	$f8,$f6,$f4
/*    30928:	00000000 */ 	sll	$zero,$zero,0x0
/*    3092c:	46089282 */ 	mul.s	$f10,$f18,$f8
/*    30930:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    30934:	c7b00024 */ 	lwc1	$f16,0x24($sp)
/*    30938:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    3093c:	46068101 */ 	sub.s	$f4,$f16,$f6
/*    30940:	e7a40020 */ 	swc1	$f4,0x20($sp)
.L00030944:
/*    30944:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    30948:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*    3094c:	c5c80010 */ 	lwc1	$f8,0x10($t6)
/*    30950:	46089280 */ 	add.s	$f10,$f18,$f8
/*    30954:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    30958:	10000083 */ 	beqz	$zero,.L00030b68
/*    3095c:	00000000 */ 	sll	$zero,$zero,0x0
/*    30960:	3c014780 */ 	lui	$at,0x4780
/*    30964:	44813000 */ 	mtc1	$at,$f6
/*    30968:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*    3096c:	46068302 */ 	mul.s	$f12,$f16,$f6
/*    30970:	0c00c069 */ 	jal	func000301a4
/*    30974:	00000000 */ 	sll	$zero,$zero,0x0
/*    30978:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*    3097c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    30980:	46040482 */ 	mul.s	$f18,$f0,$f4
/*    30984:	c7080010 */ 	lwc1	$f8,0x10($t8)
/*    30988:	46089280 */ 	add.s	$f10,$f18,$f8
/*    3098c:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    30990:	10000075 */ 	beqz	$zero,.L00030b68
/*    30994:	00000000 */ 	sll	$zero,$zero,0x0
/*    30998:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*    3099c:	c7a60024 */ 	lwc1	$f6,0x24($sp)
/*    309a0:	46068102 */ 	mul.s	$f4,$f16,$f6
/*    309a4:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*    309a8:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    309ac:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*    309b0:	c5080010 */ 	lwc1	$f8,0x10($t0)
/*    309b4:	46089280 */ 	add.s	$f10,$f18,$f8
/*    309b8:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    309bc:	1000006a */ 	beqz	$zero,.L00030b68
/*    309c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    309c4:	3c013e80 */ 	lui	$at,0x3e80
/*    309c8:	44813000 */ 	mtc1	$at,$f6
/*    309cc:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*    309d0:	4606803c */ 	c.lt.s	$f16,$f6
/*    309d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    309d8:	4500000a */ 	bc1f	.L00030a04
/*    309dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    309e0:	3c014080 */ 	lui	$at,0x4080
/*    309e4:	44812000 */ 	mtc1	$at,$f4
/*    309e8:	c7b20024 */ 	lwc1	$f18,0x24($sp)
/*    309ec:	c7aa0020 */ 	lwc1	$f10,0x20($sp)
/*    309f0:	46122202 */ 	mul.s	$f8,$f4,$f18
/*    309f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    309f8:	46085402 */ 	mul.s	$f16,$f10,$f8
/*    309fc:	1000002b */ 	beqz	$zero,.L00030aac
/*    30a00:	e7b00020 */ 	swc1	$f16,0x20($sp)
.L00030a04:
/*    30a04:	3c013f40 */ 	lui	$at,0x3f40
/*    30a08:	44812000 */ 	mtc1	$at,$f4
/*    30a0c:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    30a10:	4606203e */ 	c.le.s	$f4,$f6
/*    30a14:	00000000 */ 	sll	$zero,$zero,0x0
/*    30a18:	45000013 */ 	bc1f	.L00030a68
/*    30a1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    30a20:	3c013f40 */ 	lui	$at,0x3f40
/*    30a24:	44815000 */ 	mtc1	$at,$f10
/*    30a28:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*    30a2c:	460a9201 */ 	sub.s	$f8,$f18,$f10
/*    30a30:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*    30a34:	3c014080 */ 	lui	$at,0x4080
/*    30a38:	44818000 */ 	mtc1	$at,$f16
/*    30a3c:	c7a60024 */ 	lwc1	$f6,0x24($sp)
/*    30a40:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*    30a44:	46068102 */ 	mul.s	$f4,$f16,$f6
/*    30a48:	00000000 */ 	sll	$zero,$zero,0x0
/*    30a4c:	46049282 */ 	mul.s	$f10,$f18,$f4
/*    30a50:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    30a54:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*    30a58:	c7b00024 */ 	lwc1	$f16,0x24($sp)
/*    30a5c:	46104181 */ 	sub.s	$f6,$f8,$f16
/*    30a60:	10000012 */ 	beqz	$zero,.L00030aac
/*    30a64:	e7a60020 */ 	swc1	$f6,0x20($sp)
.L00030a68:
/*    30a68:	3c013e80 */ 	lui	$at,0x3e80
/*    30a6c:	44812000 */ 	mtc1	$at,$f4
/*    30a70:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*    30a74:	46049281 */ 	sub.s	$f10,$f18,$f4
/*    30a78:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    30a7c:	3c014080 */ 	lui	$at,0x4080
/*    30a80:	44814000 */ 	mtc1	$at,$f8
/*    30a84:	c7b00024 */ 	lwc1	$f16,0x24($sp)
/*    30a88:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*    30a8c:	46104182 */ 	mul.s	$f6,$f8,$f16
/*    30a90:	00000000 */ 	sll	$zero,$zero,0x0
/*    30a94:	46069102 */ 	mul.s	$f4,$f18,$f6
/*    30a98:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*    30a9c:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*    30aa0:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*    30aa4:	46085401 */ 	sub.s	$f16,$f10,$f8
/*    30aa8:	e7b00020 */ 	swc1	$f16,0x20($sp)
.L00030aac:
/*    30aac:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    30ab0:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    30ab4:	c5320010 */ 	lwc1	$f18,0x10($t1)
/*    30ab8:	46069100 */ 	add.s	$f4,$f18,$f6
/*    30abc:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*    30ac0:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    30ac4:	972a0014 */ 	lhu	$t2,0x14($t9)
/*    30ac8:	448a5000 */ 	mtc1	$t2,$f10
/*    30acc:	05410005 */ 	bgez	$t2,.L00030ae4
/*    30ad0:	46805220 */ 	cvt.s.w	$f8,$f10
/*    30ad4:	3c014f80 */ 	lui	$at,0x4f80
/*    30ad8:	44818000 */ 	mtc1	$at,$f16
/*    30adc:	00000000 */ 	sll	$zero,$zero,0x0
/*    30ae0:	46104200 */ 	add.s	$f8,$f8,$f16
.L00030ae4:
/*    30ae4:	972b0016 */ 	lhu	$t3,0x16($t9)
/*    30ae8:	448b9000 */ 	mtc1	$t3,$f18
/*    30aec:	05610005 */ 	bgez	$t3,.L00030b04
/*    30af0:	468091a0 */ 	cvt.s.w	$f6,$f18
/*    30af4:	3c014f80 */ 	lui	$at,0x4f80
/*    30af8:	44812000 */ 	mtc1	$at,$f4
/*    30afc:	00000000 */ 	sll	$zero,$zero,0x0
/*    30b00:	46043180 */ 	add.s	$f6,$f6,$f4
.L00030b04:
/*    30b04:	46064283 */ 	div.s	$f10,$f8,$f6
/*    30b08:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    30b0c:	3c014780 */ 	lui	$at,0x4780
/*    30b10:	44819000 */ 	mtc1	$at,$f18
/*    30b14:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*    30b18:	46128302 */ 	mul.s	$f12,$f16,$f18
/*    30b1c:	0c00c069 */ 	jal	func000301a4
/*    30b20:	00000000 */ 	sll	$zero,$zero,0x0
/*    30b24:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*    30b28:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    30b2c:	46040202 */ 	mul.s	$f8,$f0,$f4
/*    30b30:	c5a60010 */ 	lwc1	$f6,0x10($t5)
/*    30b34:	46064280 */ 	add.s	$f10,$f8,$f6
/*    30b38:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    30b3c:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*    30b40:	c7b2001c */ 	lwc1	$f18,0x1c($sp)
/*    30b44:	46128100 */ 	add.s	$f4,$f16,$f18
/*    30b48:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*    30b4c:	3c014000 */ 	lui	$at,0x4000
/*    30b50:	44813000 */ 	mtc1	$at,$f6
/*    30b54:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*    30b58:	46064283 */ 	div.s	$f10,$f8,$f6
/*    30b5c:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    30b60:	10000001 */ 	beqz	$zero,.L00030b68
/*    30b64:	00000000 */ 	sll	$zero,$zero,0x0
.L00030b68:
/*    30b68:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    30b6c:	91ec0004 */ 	lbu	$t4,0x4($t7)
/*    30b70:	318e0080 */ 	andi	$t6,$t4,0x80
/*    30b74:	11c00009 */ 	beqz	$t6,.L00030b9c
/*    30b78:	00000000 */ 	sll	$zero,$zero,0x0
/*    30b7c:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*    30b80:	4600848d */ 	trunc.w.s	$f18,$f16
/*    30b84:	44049000 */ 	mfc1	$a0,$f18
/*    30b88:	0c00e7f8 */ 	jal	func00039fe0
/*    30b8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    30b90:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    30b94:	10000007 */ 	beqz	$zero,.L00030bb4
/*    30b98:	e5000000 */ 	swc1	$f0,0x0($t0)
.L00030b9c:
/*    30b9c:	3c0142fe */ 	lui	$at,0x42fe
/*    30ba0:	44814000 */ 	mtc1	$at,$f8
/*    30ba4:	c7a40020 */ 	lwc1	$f4,0x20($sp)
/*    30ba8:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    30bac:	46082180 */ 	add.s	$f6,$f4,$f8
/*    30bb0:	e5260000 */ 	swc1	$f6,0x0($t1)
.L00030bb4:
/*    30bb4:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    30bb8:	10000003 */ 	beqz	$zero,.L00030bc8
/*    30bbc:	8d420008 */ 	lw	$v0,0x8($t2)
/*    30bc0:	10000001 */ 	beqz	$zero,.L00030bc8
/*    30bc4:	00000000 */ 	sll	$zero,$zero,0x0
.L00030bc8:
/*    30bc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    30bcc:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    30bd0:	03e00008 */ 	jr	$ra
/*    30bd4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00030bd8
/*    30bd8:	3c0e800a */ 	lui	$t6,0x800a
/*    30bdc:	8dceb870 */ 	lw	$t6,-0x4790($t6)
/*    30be0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*    30be4:	3c01800a */ 	lui	$at,0x800a
/*    30be8:	ac24b870 */ 	sw	$a0,-0x4790($at)
/*    30bec:	03e00008 */ 	jr	$ra
/*    30bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*    30bf4:	03e00008 */ 	jr	$ra
/*    30bf8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00030bfc
/*    30bfc:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    30c00:	afa40008 */ 	sw	$a0,0x8($sp)
/*    30c04:	3c0e800a */ 	lui	$t6,%hi(var8009b878)
/*    30c08:	25ceb878 */ 	addiu	$t6,$t6,%lo(var8009b878)
/*    30c0c:	3c01800a */ 	lui	$at,0x800a
/*    30c10:	ac2eb870 */ 	sw	$t6,-0x4790($at)
/*    30c14:	3c0f800a */ 	lui	$t7,%hi(var8009b878)
/*    30c18:	25efb878 */ 	addiu	$t7,$t7,%lo(var8009b878)
/*    30c1c:	afaf0004 */ 	sw	$t7,0x4($sp)
/*    30c20:	24b8ffff */ 	addiu	$t8,$a1,-1
/*    30c24:	1b000016 */ 	blez	$t8,.L00030c80
/*    30c28:	afa00000 */ 	sw	$zero,0x0($sp)
.L00030c2c:
/*    30c2c:	8fb90000 */ 	lw	$t9,0x0($sp)
/*    30c30:	8fac0004 */ 	lw	$t4,0x4($sp)
/*    30c34:	3c0a800a */ 	lui	$t2,%hi(var8009b878)
/*    30c38:	00194080 */ 	sll	$t0,$t9,0x2
/*    30c3c:	01194023 */ 	subu	$t0,$t0,$t9
/*    30c40:	00084080 */ 	sll	$t0,$t0,0x2
/*    30c44:	01194023 */ 	subu	$t0,$t0,$t9
/*    30c48:	00084080 */ 	sll	$t0,$t0,0x2
/*    30c4c:	2509002c */ 	addiu	$t1,$t0,0x2c
/*    30c50:	254ab878 */ 	addiu	$t2,$t2,%lo(var8009b878)
/*    30c54:	012a5821 */ 	addu	$t3,$t1,$t2
/*    30c58:	ad8b0000 */ 	sw	$t3,0x0($t4)
/*    30c5c:	8fad0004 */ 	lw	$t5,0x4($sp)
/*    30c60:	8dae0000 */ 	lw	$t6,0x0($t5)
/*    30c64:	afae0004 */ 	sw	$t6,0x4($sp)
/*    30c68:	8faf0000 */ 	lw	$t7,0x0($sp)
/*    30c6c:	24b9ffff */ 	addiu	$t9,$a1,-1
/*    30c70:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    30c74:	0319082a */ 	slt	$at,$t8,$t9
/*    30c78:	1420ffec */ 	bnez	$at,.L00030c2c
/*    30c7c:	afb80000 */ 	sw	$t8,0x0($sp)
.L00030c80:
/*    30c80:	8fa80004 */ 	lw	$t0,0x4($sp)
/*    30c84:	ad000000 */ 	sw	$zero,0x0($t0)
/*    30c88:	10000001 */ 	beqz	$zero,.L00030c90
/*    30c8c:	00000000 */ 	sll	$zero,$zero,0x0
.L00030c90:
/*    30c90:	03e00008 */ 	jr	$ra
/*    30c94:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func00030c98
/*    30c98:	3c0e7003 */ 	lui	$t6,0x7003
/*    30c9c:	25cefcdc */ 	addiu	$t6,$t6,-804
/*    30ca0:	ac8e0010 */ 	sw	$t6,0x10($a0)
/*    30ca4:	3c0f7003 */ 	lui	$t7,0x7003
/*    30ca8:	25effebc */ 	addiu	$t7,$t7,-324
/*    30cac:	ac8f0014 */ 	sw	$t7,0x14($a0)
/*    30cb0:	3c187003 */ 	lui	$t8,0x7003
/*    30cb4:	27180134 */ 	addiu	$t8,$t8,0x134
/*    30cb8:	ac980018 */ 	sw	$t8,0x18($a0)
/*    30cbc:	03e00008 */ 	jr	$ra
/*    30cc0:	00000000 */ 	sll	$zero,$zero,0x0
/*    30cc4:	03e00008 */ 	jr	$ra
/*    30cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*    30ccc:	03e00008 */ 	jr	$ra
/*    30cd0:	00000000 */ 	sll	$zero,$zero,0x0
/*    30cd4:	00000000 */ 	sll	$zero,$zero,0x0
/*    30cd8:	00000000 */ 	sll	$zero,$zero,0x0
/*    30cdc:	00000000 */ 	sll	$zero,$zero,0x0
);