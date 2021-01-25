#include <ultra64.h>
#include "boot/boot.h"
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_04a80.h"
#include "lib/lib_16110.h"
#include "lib/lib_48150.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4a5e0.h"
#include "lib/libc/ldiv.h"
#include "lib/libc/ll.h"
#include "types.h"

/* float properties */
#define _D0 0
#define _DBIAS 0x3ff
#define _DLONG 1
#define _DOFF 4
#define _FBIAS 0x7e
#define _FOFF 7
#define _FRND 1
#define _LBIAS 0x3ffe
#define _LOFF 15

/* integer properties */
#define _C2 1
#define _CSIGN 1
#define _ILONG 0
#define _MBMAX 8
#define NAN 2
#define INF 1
#define FINITE -1
#define _DFRAC ((1 << _DOFF) - 1)
#define _DMASK (0x7fff & ~_DFRAC)
#define _DMAX ((1 << (15 - _DOFF)) - 1)
#define _DNAN (0x8000 | _DMAX << _DOFF | 1 << (_DOFF - 1))
#define _DSIGN 0x8000
#define _D1 1 /* big-endian order */
#define _D2 2
#define _D3 3

const u32 var700524c0[] = {0x3c8efa35};
const u32 var700524c4[] = {0x00000000};
const u32 var700524c8[] = {0x00000000};
const u32 var700524cc[] = {0x00000000};
const u32 var700524d0[] = {0x40240000};
const u32 var700524d4[] = {0x00000000};
const u32 var700524d8[] = {0x40590000};
const u32 var700524dc[] = {0x00000000};
const u32 var700524e0[] = {0x40c38800};
const u32 var700524e4[] = {0x00000000};
const u32 var700524e8[] = {0x4197d784};
const u32 var700524ec[] = {0x00000000};
const u32 var700524f0[] = {0x4341c379};
const u32 var700524f4[] = {0x37e08000};
const u32 var700524f8[] = {0x4693b8b5};
const u32 var700524fc[] = {0xb5056e17};
const u32 var70052500[] = {0x4d384f03};
const u32 var70052504[] = {0xe93ff9f5};
const u32 var70052508[] = {0x5a827748};
const u32 var7005250c[] = {0xf9301d32};
const u32 var70052510[] = {0x75154fdd};
const u32 var70052514[] = {0x7f73bf3c};
const u32 var70052518[] = {0x4e614e00};
const u32 var7005251c[] = {0x496e6600};

GLOBAL_ASM(
glabel func00004a80
/*     4a80:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*     4a84:	afb00018 */ 	sw	$s0,0x18($sp)
/*     4a88:	00808025 */ 	or	$s0,$a0,$zero
/*     4a8c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     4a90:	afa5003c */ 	sw	$a1,0x3c($sp)
/*     4a94:	afa60040 */ 	sw	$a2,0x40($sp)
/*     4a98:	afa70044 */ 	sw	$a3,0x44($sp)
/*     4a9c:	27a60048 */ 	addiu	$a2,$sp,0x48
/*     4aa0:	27a50044 */ 	addiu	$a1,$sp,0x44
/*     4aa4:	0c0011e4 */ 	jal	scaleTo1
/*     4aa8:	27a40040 */ 	addiu	$a0,$sp,0x40
/*     4aac:	3c017005 */ 	lui	$at,%hi(var700524c0)
/*     4ab0:	c7ac003c */ 	lwc1	$f12,0x3c($sp)
/*     4ab4:	c42424c0 */ 	lwc1	$f4,%lo(var700524c0)($at)
/*     4ab8:	46046302 */ 	mul.s	$f12,$f12,$f4
/*     4abc:	0c0068f7 */ 	jal	sinf
/*     4ac0:	e7ac003c */ 	swc1	$f12,0x3c($sp)
/*     4ac4:	c7ac003c */ 	lwc1	$f12,0x3c($sp)
/*     4ac8:	0c0068f4 */ 	jal	cosf
/*     4acc:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*     4ad0:	c7a80040 */ 	lwc1	$f8,0x40($sp)
/*     4ad4:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*     4ad8:	3c013f80 */ 	lui	$at,0x3f80
/*     4adc:	44813000 */ 	mtc1	$at,$f6
/*     4ae0:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*     4ae4:	02002025 */ 	or	$a0,$s0,$zero
/*     4ae8:	46003081 */ 	sub.s	$f2,$f6,$f0
/*     4aec:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*     4af0:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*     4af4:	46022402 */ 	mul.s	$f16,$f4,$f2
/*     4af8:	00000000 */ 	nop
/*     4afc:	46065102 */ 	mul.s	$f4,$f10,$f6
/*     4b00:	e7b0002c */ 	swc1	$f16,0x2c($sp)
/*     4b04:	46022482 */ 	mul.s	$f18,$f4,$f2
/*     4b08:	00000000 */ 	nop
/*     4b0c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*     4b10:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*     4b14:	46025102 */ 	mul.s	$f4,$f10,$f2
/*     4b18:	0c012918 */ 	jal	func0004a460
/*     4b1c:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*     4b20:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*     4b24:	3c013f80 */ 	lui	$at,0x3f80
/*     4b28:	44814000 */ 	mtc1	$at,$f8
/*     4b2c:	46063002 */ 	mul.s	$f0,$f6,$f6
/*     4b30:	c7ac0030 */ 	lwc1	$f12,0x30($sp)
/*     4b34:	c7ae0034 */ 	lwc1	$f14,0x34($sp)
/*     4b38:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*     4b3c:	c7b20028 */ 	lwc1	$f18,0x28($sp)
/*     4b40:	46004281 */ 	sub.s	$f10,$f8,$f0
/*     4b44:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*     4b48:	46002180 */ 	add.s	$f6,$f4,$f0
/*     4b4c:	e6060000 */ 	swc1	$f6,0x0($s0)
/*     4b50:	c7a80040 */ 	lwc1	$f8,0x40($sp)
/*     4b54:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*     4b58:	460a9101 */ 	sub.s	$f4,$f18,$f10
/*     4b5c:	e6040024 */ 	swc1	$f4,0x24($s0)
/*     4b60:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*     4b64:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*     4b68:	44813000 */ 	mtc1	$at,$f6
/*     4b6c:	46124280 */ 	add.s	$f10,$f8,$f18
/*     4b70:	e60a0018 */ 	swc1	$f10,0x18($s0)
/*     4b74:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*     4b78:	46042082 */ 	mul.s	$f2,$f4,$f4
/*     4b7c:	46023201 */ 	sub.s	$f8,$f6,$f2
/*     4b80:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*     4b84:	46025100 */ 	add.s	$f4,$f10,$f2
/*     4b88:	e6040014 */ 	swc1	$f4,0x14($s0)
/*     4b8c:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*     4b90:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*     4b94:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*     4b98:	460a4100 */ 	add.s	$f4,$f8,$f10
/*     4b9c:	e6040020 */ 	swc1	$f4,0x20($s0)
/*     4ba0:	c7a80044 */ 	lwc1	$f8,0x44($sp)
/*     4ba4:	c7a60024 */ 	lwc1	$f6,0x24($sp)
/*     4ba8:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*     4bac:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*     4bb0:	44813000 */ 	mtc1	$at,$f6
/*     4bb4:	e6040008 */ 	swc1	$f4,0x8($s0)
/*     4bb8:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*     4bbc:	46084002 */ 	mul.s	$f0,$f8,$f8
/*     4bc0:	46003281 */ 	sub.s	$f10,$f6,$f0
/*     4bc4:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*     4bc8:	46002200 */ 	add.s	$f8,$f4,$f0
/*     4bcc:	e6080028 */ 	swc1	$f8,0x28($s0)
/*     4bd0:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*     4bd4:	460e3282 */ 	mul.s	$f10,$f6,$f14
/*     4bd8:	460a8101 */ 	sub.s	$f4,$f16,$f10
/*     4bdc:	e6040010 */ 	swc1	$f4,0x10($s0)
/*     4be0:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*     4be4:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*     4be8:	46103280 */ 	add.s	$f10,$f6,$f16
/*     4bec:	e60a0004 */ 	swc1	$f10,0x4($s0)
/*     4bf0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     4bf4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     4bf8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*     4bfc:	03e00008 */ 	jr	$ra
/*     4c00:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00004c04
/*     4c04:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*     4c08:	44856000 */ 	mtc1	$a1,$f12
/*     4c0c:	44867000 */ 	mtc1	$a2,$f14
/*     4c10:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*     4c14:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     4c18:	afa40060 */ 	sw	$a0,0x60($sp)
/*     4c1c:	44056000 */ 	mfc1	$a1,$f12
/*     4c20:	44067000 */ 	mfc1	$a2,$f14
/*     4c24:	afa7006c */ 	sw	$a3,0x6c($sp)
/*     4c28:	27a40020 */ 	addiu	$a0,$sp,0x20
/*     4c2c:	0c0012a0 */ 	jal	func00004a80
/*     4c30:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*     4c34:	27a40020 */ 	addiu	$a0,$sp,0x20
/*     4c38:	0c0128d8 */ 	jal	func0004a360
/*     4c3c:	8fa50060 */ 	lw	$a1,0x60($sp)
/*     4c40:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     4c44:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*     4c48:	03e00008 */ 	jr	$ra
/*     4c4c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel _Ldtob
/*     4c50:	27bdff20 */ 	addiu	$sp,$sp,-224
/*     4c54:	44802000 */ 	mtc1	$zero,$f4
/*     4c58:	afbf0044 */ 	sw	$ra,0x44($sp)
/*     4c5c:	afb50040 */ 	sw	$s5,0x40($sp)
/*     4c60:	afb4003c */ 	sw	$s4,0x3c($sp)
/*     4c64:	afb30038 */ 	sw	$s3,0x38($sp)
/*     4c68:	afb20034 */ 	sw	$s2,0x34($sp)
/*     4c6c:	afb10030 */ 	sw	$s1,0x30($sp)
/*     4c70:	afb0002c */ 	sw	$s0,0x2c($sp)
/*     4c74:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*     4c78:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*     4c7c:	afa500e4 */ 	sw	$a1,0xe4($sp)
/*     4c80:	8c820024 */ 	lw	$v0,0x24($a0)
/*     4c84:	460020a1 */ 	cvt.d.s	$f2,$f4
/*     4c88:	00803025 */ 	or	$a2,$a0,$zero
/*     4c8c:	27b200c0 */ 	addiu	$s2,$sp,0xc0
/*     4c90:	d4940000 */ 	ldc1	$f20,0x0($a0)
/*     4c94:	04410004 */ 	bgez	$v0,.L00004ca8
/*     4c98:	46201586 */ 	mov.d	$f22,$f2
/*     4c9c:	240e0006 */ 	addiu	$t6,$zero,0x6
/*     4ca0:	1000000a */ 	b	.L00004ccc
/*     4ca4:	ac8e0024 */ 	sw	$t6,0x24($a0)
.L00004ca8:
/*     4ca8:	14400008 */ 	bnez	$v0,.L00004ccc
/*     4cac:	93af00e7 */ 	lbu	$t7,0xe7($sp)
/*     4cb0:	24010067 */ 	addiu	$at,$zero,0x67
/*     4cb4:	11e10003 */ 	beq	$t7,$at,.L00004cc4
/*     4cb8:	afaf004c */ 	sw	$t7,0x4c($sp)
/*     4cbc:	24010047 */ 	addiu	$at,$zero,0x47
/*     4cc0:	15e10002 */ 	bne	$t7,$at,.L00004ccc
.L00004cc4:
/*     4cc4:	24180001 */ 	addiu	$t8,$zero,0x1
/*     4cc8:	acd80024 */ 	sw	$t8,0x24($a2)
.L00004ccc:
/*     4ccc:	27a40096 */ 	addiu	$a0,$sp,0x96
/*     4cd0:	00c02825 */ 	or	$a1,$a2,$zero
/*     4cd4:	afa600e0 */ 	sw	$a2,0xe0($sp)
/*     4cd8:	0c00143b */ 	jal	_Ldunscale
/*     4cdc:	f7a20050 */ 	sdc1	$f2,0x50($sp)
/*     4ce0:	18400010 */ 	blez	$v0,.L00004d24
/*     4ce4:	d7a20050 */ 	ldc1	$f2,0x50($sp)
/*     4ce8:	24010002 */ 	addiu	$at,$zero,0x2
/*     4cec:	14410004 */ 	bne	$v0,$at,.L00004d00
/*     4cf0:	3c057005 */ 	lui	$a1,%hi(var7005251c)
/*     4cf4:	3c057005 */ 	lui	$a1,%hi(var70052518)
/*     4cf8:	10000002 */ 	b	.L00004d04
/*     4cfc:	24a52518 */ 	addiu	$a1,$a1,%lo(var70052518)
.L00004d00:
/*     4d00:	24a5251c */ 	addiu	$a1,$a1,%lo(var7005251c)
.L00004d04:
/*     4d04:	8fa200e0 */ 	lw	$v0,0xe0($sp)
/*     4d08:	24190003 */ 	addiu	$t9,$zero,0x3
/*     4d0c:	24060003 */ 	addiu	$a2,$zero,0x3
/*     4d10:	ac590014 */ 	sw	$t9,0x14($v0)
/*     4d14:	0c012978 */ 	jal	memcpy
/*     4d18:	8c440008 */ 	lw	$a0,0x8($v0)
/*     4d1c:	100000e9 */ 	b	.L000050c4
/*     4d20:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00004d24:
/*     4d24:	14400003 */ 	bnez	$v0,.L00004d34
/*     4d28:	00003825 */ 	or	$a3,$zero,$zero
/*     4d2c:	100000de */ 	b	.L000050a8
/*     4d30:	a7a00096 */ 	sh	$zero,0x96($sp)
.L00004d34:
/*     4d34:	4622a03c */ 	c.lt.d	$f20,$f2
/*     4d38:	93a800e7 */ 	lbu	$t0,0xe7($sp)
/*     4d3c:	87a90096 */ 	lh	$t1,0x96($sp)
/*     4d40:	24017597 */ 	addiu	$at,$zero,0x7597
/*     4d44:	45000002 */ 	bc1f	.L00004d50
/*     4d48:	afa8004c */ 	sw	$t0,0x4c($sp)
/*     4d4c:	4620a507 */ 	neg.d	$f20,$f20
.L00004d50:
/*     4d50:	01210019 */ 	multu	$t1,$at
/*     4d54:	3c010001 */ 	lui	$at,0x1
/*     4d58:	342186a0 */ 	ori	$at,$at,0x86a0
/*     4d5c:	240f0003 */ 	addiu	$t7,$zero,0x3
/*     4d60:	00001825 */ 	or	$v1,$zero,$zero
/*     4d64:	24050006 */ 	addiu	$a1,$zero,0x6
/*     4d68:	27b200c1 */ 	addiu	$s2,$sp,0xc1
/*     4d6c:	00005012 */ 	mflo	$t2
/*     4d70:	00000000 */ 	nop
/*     4d74:	00000000 */ 	nop
/*     4d78:	0141001a */ 	div	$zero,$t2,$at
/*     4d7c:	00005812 */ 	mflo	$t3
/*     4d80:	256cfffc */ 	addiu	$t4,$t3,-4
/*     4d84:	000c6c00 */ 	sll	$t5,$t4,0x10
/*     4d88:	000d7403 */ 	sra	$t6,$t5,0x10
/*     4d8c:	05c10018 */ 	bgez	$t6,.L00004df0
/*     4d90:	a7ac0096 */ 	sh	$t4,0x96($sp)
/*     4d94:	000cc400 */ 	sll	$t8,$t4,0x10
/*     4d98:	0018cc03 */ 	sra	$t9,$t8,0x10
/*     4d9c:	01f92023 */ 	subu	$a0,$t7,$t9
/*     4da0:	2401fffc */ 	addiu	$at,$zero,-4
/*     4da4:	00811024 */ 	and	$v0,$a0,$at
/*     4da8:	00024823 */ 	negu	$t1,$v0
/*     4dac:	1840002c */ 	blez	$v0,.L00004e60
/*     4db0:	a7a90096 */ 	sh	$t1,0x96($sp)
/*     4db4:	3c047005 */ 	lui	$a0,%hi(var700524d0)
/*     4db8:	248424d0 */ 	addiu	$a0,$a0,%lo(var700524d0)
.L00004dbc:
/*     4dbc:	304a0001 */ 	andi	$t2,$v0,0x1
/*     4dc0:	11400006 */ 	beqz	$t2,.L00004ddc
/*     4dc4:	00027043 */ 	sra	$t6,$v0,0x1
/*     4dc8:	000358c0 */ 	sll	$t3,$v1,0x3
/*     4dcc:	008b6821 */ 	addu	$t5,$a0,$t3
/*     4dd0:	d5a60000 */ 	ldc1	$f6,0x0($t5)
/*     4dd4:	4626a502 */ 	mul.d	$f20,$f20,$f6
/*     4dd8:	00000000 */ 	nop
.L00004ddc:
/*     4ddc:	01c01025 */ 	or	$v0,$t6,$zero
/*     4de0:	1dc0fff6 */ 	bgtz	$t6,.L00004dbc
/*     4de4:	24630001 */ 	addiu	$v1,$v1,0x1
/*     4de8:	1000001e */ 	b	.L00004e64
/*     4dec:	8fae004c */ 	lw	$t6,0x4c($sp)
.L00004df0:
/*     4df0:	87ac0096 */ 	lh	$t4,0x96($sp)
/*     4df4:	3c013f80 */ 	lui	$at,0x3f80
/*     4df8:	00001825 */ 	or	$v1,$zero,$zero
/*     4dfc:	19800018 */ 	blez	$t4,.L00004e60
/*     4e00:	3198fffc */ 	andi	$t8,$t4,0xfffc
/*     4e04:	44814000 */ 	mtc1	$at,$f8
/*     4e08:	00181400 */ 	sll	$v0,$t8,0x10
/*     4e0c:	0018cc00 */ 	sll	$t9,$t8,0x10
/*     4e10:	00194403 */ 	sra	$t0,$t9,0x10
/*     4e14:	00027c03 */ 	sra	$t7,$v0,0x10
/*     4e18:	a7b80096 */ 	sh	$t8,0x96($sp)
/*     4e1c:	01e01025 */ 	or	$v0,$t7,$zero
/*     4e20:	1900000e */ 	blez	$t0,.L00004e5c
/*     4e24:	46004021 */ 	cvt.d.s	$f0,$f8
/*     4e28:	3c047005 */ 	lui	$a0,%hi(var700524d0)
/*     4e2c:	248424d0 */ 	addiu	$a0,$a0,%lo(var700524d0)
.L00004e30:
/*     4e30:	30490001 */ 	andi	$t1,$v0,0x1
/*     4e34:	11200006 */ 	beqz	$t1,.L00004e50
/*     4e38:	00026843 */ 	sra	$t5,$v0,0x1
/*     4e3c:	000350c0 */ 	sll	$t2,$v1,0x3
/*     4e40:	008a5821 */ 	addu	$t3,$a0,$t2
/*     4e44:	d56a0000 */ 	ldc1	$f10,0x0($t3)
/*     4e48:	462a0002 */ 	mul.d	$f0,$f0,$f10
/*     4e4c:	00000000 */ 	nop
.L00004e50:
/*     4e50:	01a01025 */ 	or	$v0,$t5,$zero
/*     4e54:	1da0fff6 */ 	bgtz	$t5,.L00004e30
/*     4e58:	24630001 */ 	addiu	$v1,$v1,0x1
.L00004e5c:
/*     4e5c:	4620a503 */ 	div.d	$f20,$f20,$f0
.L00004e60:
/*     4e60:	8fae004c */ 	lw	$t6,0x4c($sp)
.L00004e64:
/*     4e64:	24010066 */ 	addiu	$at,$zero,0x66
/*     4e68:	8fac00e0 */ 	lw	$t4,0xe0($sp)
/*     4e6c:	15c10004 */ 	bne	$t6,$at,.L00004e80
/*     4e70:	24180030 */ 	addiu	$t8,$zero,0x30
/*     4e74:	87a50096 */ 	lh	$a1,0x96($sp)
/*     4e78:	10000001 */ 	b	.L00004e80
/*     4e7c:	24a5000a */ 	addiu	$a1,$a1,0xa
.L00004e80:
/*     4e80:	8d8f0024 */ 	lw	$t7,0x24($t4)
/*     4e84:	00afa821 */ 	addu	$s5,$a1,$t7
/*     4e88:	2aa10014 */ 	slti	$at,$s5,0x14
/*     4e8c:	14200002 */ 	bnez	$at,.L00004e98
/*     4e90:	00000000 */ 	nop
/*     4e94:	24150013 */ 	addiu	$s5,$zero,0x13
.L00004e98:
/*     4e98:	1aa00031 */ 	blez	$s5,.L00004f60
/*     4e9c:	a3b800c0 */ 	sb	$t8,0xc0($sp)
/*     4ea0:	4634103c */ 	c.lt.d	$f2,$f20
/*     4ea4:	24140030 */ 	addiu	$s4,$zero,0x30
/*     4ea8:	27b3006c */ 	addiu	$s3,$sp,0x6c
/*     4eac:	4502002d */ 	bc1fl	.L00004f64
/*     4eb0:	87ad0096 */ 	lh	$t5,0x96($sp)
/*     4eb4:	4620a40d */ 	trunc.w.d	$f16,$f20
.L00004eb8:
/*     4eb8:	26b5fff8 */ 	addiu	$s5,$s5,-8
/*     4ebc:	26520008 */ 	addiu	$s2,$s2,0x8
/*     4ec0:	44118000 */ 	mfc1	$s1,$f16
/*     4ec4:	1aa00008 */ 	blez	$s5,.L00004ee8
/*     4ec8:	00000000 */ 	nop
/*     4ecc:	44919000 */ 	mtc1	$s1,$f18
/*     4ed0:	3c017005 */ 	lui	$at,%hi(var70052528)
/*     4ed4:	d4282528 */ 	ldc1	$f8,%lo(var70052528)($at)
/*     4ed8:	46809121 */ 	cvt.d.w	$f4,$f18
/*     4edc:	4624a181 */ 	sub.d	$f6,$f20,$f4
/*     4ee0:	46283502 */ 	mul.d	$f20,$f6,$f8
/*     4ee4:	00000000 */ 	nop
.L00004ee8:
/*     4ee8:	1a200011 */ 	blez	$s1,.L00004f30
/*     4eec:	24100008 */ 	addiu	$s0,$zero,0x8
/*     4ef0:	24100007 */ 	addiu	$s0,$zero,0x7
/*     4ef4:	0600000e */ 	bltz	$s0,.L00004f30
/*     4ef8:	02602025 */ 	or	$a0,$s3,$zero
.L00004efc:
/*     4efc:	02202825 */ 	or	$a1,$s1,$zero
/*     4f00:	0c0129e0 */ 	jal	ldiv
/*     4f04:	2406000a */ 	addiu	$a2,$zero,0xa
/*     4f08:	8fa80070 */ 	lw	$t0,0x70($sp)
/*     4f0c:	2652ffff */ 	addiu	$s2,$s2,-1
/*     4f10:	25090030 */ 	addiu	$t1,$t0,0x30
/*     4f14:	a2490000 */ 	sb	$t1,0x0($s2)
/*     4f18:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*     4f1c:	5a200005 */ 	blezl	$s1,.L00004f34
/*     4f20:	2610ffff */ 	addiu	$s0,$s0,-1
/*     4f24:	2610ffff */ 	addiu	$s0,$s0,-1
/*     4f28:	0603fff4 */ 	bgezl	$s0,.L00004efc
/*     4f2c:	02602025 */ 	or	$a0,$s3,$zero
.L00004f30:
/*     4f30:	2610ffff */ 	addiu	$s0,$s0,-1
.L00004f34:
/*     4f34:	06000004 */ 	bltz	$s0,.L00004f48
.L00004f38:
/*     4f38:	2610ffff */ 	addiu	$s0,$s0,-1
/*     4f3c:	2652ffff */ 	addiu	$s2,$s2,-1
/*     4f40:	0601fffd */ 	bgez	$s0,.L00004f38
/*     4f44:	a2540000 */ 	sb	$s4,0x0($s2)
.L00004f48:
/*     4f48:	1aa00005 */ 	blez	$s5,.L00004f60
/*     4f4c:	26520008 */ 	addiu	$s2,$s2,0x8
/*     4f50:	4634b03c */ 	c.lt.d	$f22,$f20
/*     4f54:	00000000 */ 	nop
/*     4f58:	4503ffd7 */ 	bc1tl	.L00004eb8
/*     4f5c:	4620a40d */ 	trunc.w.d	$f16,$f20
.L00004f60:
/*     4f60:	87ad0096 */ 	lh	$t5,0x96($sp)
.L00004f64:
/*     4f64:	93ac00c1 */ 	lbu	$t4,0xc1($sp)
/*     4f68:	27ab00c0 */ 	addiu	$t3,$sp,0xc0
/*     4f6c:	24020030 */ 	addiu	$v0,$zero,0x30
/*     4f70:	024ba823 */ 	subu	$s5,$s2,$t3
/*     4f74:	25ae0007 */ 	addiu	$t6,$t5,0x7
/*     4f78:	26b5ffff */ 	addiu	$s5,$s5,-1
/*     4f7c:	a7ae0096 */ 	sh	$t6,0x96($sp)
/*     4f80:	144c0009 */ 	bne	$v0,$t4,.L00004fa8
/*     4f84:	27b200c1 */ 	addiu	$s2,$sp,0xc1
/*     4f88:	87af0096 */ 	lh	$t7,0x96($sp)
.L00004f8c:
/*     4f8c:	26520001 */ 	addiu	$s2,$s2,0x1
/*     4f90:	26b5ffff */ 	addiu	$s5,$s5,-1
/*     4f94:	25f8ffff */ 	addiu	$t8,$t7,-1
/*     4f98:	a7b80096 */ 	sh	$t8,0x96($sp)
/*     4f9c:	92590000 */ 	lbu	$t9,0x0($s2)
/*     4fa0:	5059fffa */ 	beql	$v0,$t9,.L00004f8c
/*     4fa4:	87af0096 */ 	lh	$t7,0x96($sp)
.L00004fa8:
/*     4fa8:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*     4fac:	24010066 */ 	addiu	$at,$zero,0x66
/*     4fb0:	8faa00e0 */ 	lw	$t2,0xe0($sp)
/*     4fb4:	15010004 */ 	bne	$t0,$at,.L00004fc8
/*     4fb8:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*     4fbc:	87a50096 */ 	lh	$a1,0x96($sp)
/*     4fc0:	10000009 */ 	b	.L00004fe8
/*     4fc4:	24a50001 */ 	addiu	$a1,$a1,0x1
.L00004fc8:
/*     4fc8:	24010065 */ 	addiu	$at,$zero,0x65
/*     4fcc:	11210003 */ 	beq	$t1,$at,.L00004fdc
/*     4fd0:	24010045 */ 	addiu	$at,$zero,0x45
/*     4fd4:	15210003 */ 	bne	$t1,$at,.L00004fe4
/*     4fd8:	00001025 */ 	or	$v0,$zero,$zero
.L00004fdc:
/*     4fdc:	10000001 */ 	b	.L00004fe4
/*     4fe0:	24020001 */ 	addiu	$v0,$zero,0x1
.L00004fe4:
/*     4fe4:	00402825 */ 	or	$a1,$v0,$zero
.L00004fe8:
/*     4fe8:	8d4b0024 */ 	lw	$t3,0x24($t2)
/*     4fec:	00ab3821 */ 	addu	$a3,$a1,$t3
/*     4ff0:	00076c00 */ 	sll	$t5,$a3,0x10
/*     4ff4:	000d3c03 */ 	sra	$a3,$t5,0x10
/*     4ff8:	02a7082a */ 	slt	$at,$s5,$a3
/*     4ffc:	10200004 */ 	beqz	$at,.L00005010
/*     5000:	00000000 */ 	nop
/*     5004:	00153c00 */ 	sll	$a3,$s5,0x10
/*     5008:	00076403 */ 	sra	$t4,$a3,0x10
/*     500c:	01803825 */ 	or	$a3,$t4,$zero
.L00005010:
/*     5010:	18e00025 */ 	blez	$a3,.L000050a8
/*     5014:	00f5082a */ 	slt	$at,$a3,$s5
/*     5018:	10200007 */ 	beqz	$at,.L00005038
/*     501c:	00f21021 */ 	addu	$v0,$a3,$s2
/*     5020:	904f0000 */ 	lbu	$t7,0x0($v0)
/*     5024:	29e10035 */ 	slti	$at,$t7,0x35
/*     5028:	54200004 */ 	bnezl	$at,.L0000503c
/*     502c:	24050030 */ 	addiu	$a1,$zero,0x30
/*     5030:	10000003 */ 	b	.L00005040
/*     5034:	24050039 */ 	addiu	$a1,$zero,0x39
.L00005038:
/*     5038:	24050030 */ 	addiu	$a1,$zero,0x30
.L0000503c:
/*     503c:	00f21021 */ 	addu	$v0,$a3,$s2
.L00005040:
/*     5040:	9058ffff */ 	lbu	$t8,-0x1($v0)
/*     5044:	24e3ffff */ 	addiu	$v1,$a3,-1
/*     5048:	00a02025 */ 	or	$a0,$a1,$zero
/*     504c:	14b80009 */ 	bne	$a1,$t8,.L00005074
/*     5050:	24010039 */ 	addiu	$at,$zero,0x39
/*     5054:	00721021 */ 	addu	$v0,$v1,$s2
.L00005058:
/*     5058:	9049ffff */ 	lbu	$t1,-0x1($v0)
/*     505c:	24e7ffff */ 	addiu	$a3,$a3,-1
/*     5060:	0007cc00 */ 	sll	$t9,$a3,0x10
/*     5064:	2463ffff */ 	addiu	$v1,$v1,-1
/*     5068:	2442ffff */ 	addiu	$v0,$v0,-1
/*     506c:	1089fffa */ 	beq	$a0,$t1,.L00005058
/*     5070:	00193c03 */ 	sra	$a3,$t9,0x10
.L00005074:
/*     5074:	14810004 */ 	bne	$a0,$at,.L00005088
/*     5078:	02431021 */ 	addu	$v0,$s2,$v1
/*     507c:	904a0000 */ 	lbu	$t2,0x0($v0)
/*     5080:	254b0001 */ 	addiu	$t3,$t2,0x1
/*     5084:	a04b0000 */ 	sb	$t3,0x0($v0)
.L00005088:
/*     5088:	04610007 */ 	bgez	$v1,.L000050a8
/*     508c:	87ac0096 */ 	lh	$t4,0x96($sp)
/*     5090:	24e70001 */ 	addiu	$a3,$a3,0x1
/*     5094:	00076c00 */ 	sll	$t5,$a3,0x10
/*     5098:	258f0001 */ 	addiu	$t7,$t4,0x1
/*     509c:	a7af0096 */ 	sh	$t7,0x96($sp)
/*     50a0:	000d3c03 */ 	sra	$a3,$t5,0x10
/*     50a4:	2652ffff */ 	addiu	$s2,$s2,-1
.L000050a8:
/*     50a8:	87b80096 */ 	lh	$t8,0x96($sp)
/*     50ac:	8fa400e0 */ 	lw	$a0,0xe0($sp)
/*     50b0:	93a500e7 */ 	lbu	$a1,0xe7($sp)
/*     50b4:	02403025 */ 	or	$a2,$s2,$zero
/*     50b8:	0c001469 */ 	jal	_Genld
/*     50bc:	afb80010 */ 	sw	$t8,0x10($sp)
/*     50c0:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L000050c4:
/*     50c4:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*     50c8:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*     50cc:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*     50d0:	8fb10030 */ 	lw	$s1,0x30($sp)
/*     50d4:	8fb20034 */ 	lw	$s2,0x34($sp)
/*     50d8:	8fb30038 */ 	lw	$s3,0x38($sp)
/*     50dc:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*     50e0:	8fb50040 */ 	lw	$s5,0x40($sp)
/*     50e4:	03e00008 */ 	jr	$ra
/*     50e8:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);

short _Ldunscale(short *pex, printf_struct *px)
{
	unsigned short *ps = (unsigned short *)px;
	short xchar = (ps[_D0] & _DMASK) >> _DOFF;

	if (xchar == _DMAX) {
		/* NaN or INF */
		*pex = 0;

		return ps[_D0] & _DFRAC || ps[_D1] || ps[_D2] || ps[_D3] ? NAN : INF;
	}

	if (xchar > 0) {
		ps[_D0] = (ps[_D0] & ~_DMASK) | (_DBIAS << _DOFF);
		*pex = xchar - (_DBIAS - 1);

		return FINITE;
	}

	if (xchar < 0) {
		return NAN;
	}

	*pex = 0;

	return 0;
}

void _Genld(printf_struct *px, char code, char *p, short nsig, short xexp)
{
	const char point = 0x2e;

	if (nsig <= 0) {
		nsig = 1, p = (char *)"0";
	}

	if (code == 0x66 || ((code == 0x67 || code == 0x47) && (-4 <= xexp) && (xexp < px->precision))) {
		/* 0x66 format */
		++xexp; /* change to leading digit count */

		if (code != 0x66) {
			/* fixup for 0x67 */
			if (!(px->flags & FLAGS_HASH) && nsig < px->precision) {
				px->precision = nsig;
			}

			if ((px->precision -= xexp) < 0) {
				px->precision = 0;
			}
		}

		if (xexp <= 0) {
			/* digits only to right of point */
			px->buff[px->part2_len++] = 0x30;

			if (0 < px->precision || px->flags & FLAGS_HASH) {
				px->buff[px->part2_len++] = point;
			}

			if (px->precision < -xexp) {
				xexp = -px->precision;
			}

			px->num_mid_zeros = -xexp;
			px->precision += xexp;

			if (px->precision < nsig) {
				nsig = px->precision;
			}

			memcpy(&px->buff[px->part2_len], p, px->part3_len = nsig);

			px->num_trailing_zeros = px->precision - nsig;
		} else if (nsig < xexp) {
			/* zeros before point */
			memcpy(&px->buff[px->part2_len], p, nsig);

			px->part2_len += nsig;
			px->num_mid_zeros = xexp - nsig;

			if (0 < px->precision || px->flags & FLAGS_HASH) {
				px->buff[px->part2_len] = point, ++px->part3_len;
			}

			px->num_trailing_zeros = px->precision;
		} else {
			/* enough digits before point */
			memcpy(&px->buff[px->part2_len], p, xexp);

			px->part2_len += xexp;
			nsig -= xexp;

			if (0 < px->precision || px->flags & FLAGS_HASH) {
				px->buff[px->part2_len++] = point;
			}

			if (px->precision < nsig) {
				nsig = px->precision;
			}

			memcpy(&px->buff[px->part2_len], p + xexp, nsig);

			px->part2_len += nsig;
			px->num_mid_zeros = px->precision - nsig;
		}
	} else {
		/* 0x65 format */
		if (code == 0x67 || code == 0x47) {
			/* fixup for 0x67 */
			if (nsig < px->precision) {
				px->precision = nsig;
			}

			if (--px->precision < 0) {
				px->precision = 0;
			}

			code = code == 0x67 ? 0x65 : 0x45;
		}

		px->buff[px->part2_len++] = *p++;

		if (0 < px->precision || px->flags & FLAGS_HASH) {
			px->buff[px->part2_len++] = point;
		}

		if (0 < px->precision) {
			/* put fraction digits */
			if (px->precision < --nsig) {
				nsig = px->precision;
			}

			memcpy(&px->buff[px->part2_len], p, nsig);

			px->part2_len += nsig;
			px->num_mid_zeros = px->precision - nsig;
		}

		p = (char *)&px->buff[px->part2_len]; /* put exponent */
		*p++ = code;

		if (0 <= xexp) {
			*p++ = 0x2b;
		} else {
			/* negative exponent */
			*p++ = 0x2d;
			xexp = -xexp;
		}

		if (100 <= xexp) {
			/* put oversize exponent */
			if (1000 <= xexp) {
				*p++ = xexp / 1000 + 0x30, xexp %= 1000;
			}

			*p++ = xexp / 100 + 0x30, xexp %= 100;
		}

		*p++ = xexp / 10 + 0x30, xexp %= 10;
		*p++ = xexp + 0x30;

		px->part3_len = p - (char *)&px->buff[px->part2_len];
	}

	if ((px->flags & (FLAGS_ZERO | FLAGS_MINUS)) == FLAGS_ZERO) {
		/* pad with leading zeros */
		int n = px->n0 + px->part2_len + px->num_mid_zeros + px->part3_len + px->num_trailing_zeros;

		if (n < px->width) {
			px->num_leading_zeros = px->width - n;
		}
	}
}

const u32 var70052524[] = {0x00000000};
const u32 var70052528[] = {0x4197d784};
const u32 var7005252c[] = {0x00000000};
