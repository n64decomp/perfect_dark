#include <ultra64.h>
#include "boot/boot.h"
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_04a80.h"
#include "lib/lib_16110.h"
#include "lib/lib_48150.h"
#include "lib/lib_481e0.h"
#include "lib/lib_48650.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4a5e0.h"
#include "lib/lib_4a680.h"
#include "lib/lib_4a810.h"
#include "lib/lib_4acc0.h"
#include "lib/lib_4ace0.h"
#include "lib/lib_4ad30.h"
#include "lib/lib_4ad80.h"
#include "lib/lib_4ae00.h"
#include "lib/lib_4b160.h"
#include "types.h"

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
const u32 var70052520[] = {0x30000000};
const u32 var70052524[] = {0x00000000};
const u32 var70052528[] = {0x4197d784};
const u32 var7005252c[] = {0x00000000};

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
/*     4abc:	0c0068f7 */ 	jal	fsin
/*     4ac0:	e7ac003c */ 	swc1	$f12,0x3c($sp)
/*     4ac4:	c7ac003c */ 	lwc1	$f12,0x3c($sp)
/*     4ac8:	0c0068f4 */ 	jal	fcos
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
/*     4af8:	00000000 */ 	sll	$zero,$zero,0x0
/*     4afc:	46065102 */ 	mul.s	$f4,$f10,$f6
/*     4b00:	e7b0002c */ 	swc1	$f16,0x2c($sp)
/*     4b04:	46022482 */ 	mul.s	$f18,$f4,$f2
/*     4b08:	00000000 */ 	sll	$zero,$zero,0x0
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
/*     4c00:	00000000 */ 	sll	$zero,$zero,0x0
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
/*     4c4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00004c50
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
/*     4ca0:	1000000a */ 	beqz	$zero,.L00004ccc
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
/*     4cd8:	0c00143b */ 	jal	func000050ec
/*     4cdc:	f7a20050 */ 	sdc1	$f2,0x50($sp)
/*     4ce0:	18400010 */ 	blez	$v0,.L00004d24
/*     4ce4:	d7a20050 */ 	ldc1	$f2,0x50($sp)
/*     4ce8:	24010002 */ 	addiu	$at,$zero,0x2
/*     4cec:	14410004 */ 	bne	$v0,$at,.L00004d00
/*     4cf0:	3c057005 */ 	lui	$a1,%hi(var7005251c)
/*     4cf4:	3c057005 */ 	lui	$a1,%hi(var70052518)
/*     4cf8:	10000002 */ 	beqz	$zero,.L00004d04
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
/*     4d1c:	100000e9 */ 	beqz	$zero,.L000050c4
/*     4d20:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00004d24:
/*     4d24:	14400003 */ 	bnez	$v0,.L00004d34
/*     4d28:	00003825 */ 	or	$a3,$zero,$zero
/*     4d2c:	100000de */ 	beqz	$zero,.L000050a8
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
/*     4d70:	00000000 */ 	sll	$zero,$zero,0x0
/*     4d74:	00000000 */ 	sll	$zero,$zero,0x0
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
/*     4dd8:	00000000 */ 	sll	$zero,$zero,0x0
.L00004ddc:
/*     4ddc:	01c01025 */ 	or	$v0,$t6,$zero
/*     4de0:	1dc0fff6 */ 	bgtz	$t6,.L00004dbc
/*     4de4:	24630001 */ 	addiu	$v1,$v1,0x1
/*     4de8:	1000001e */ 	beqz	$zero,.L00004e64
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
/*     4e4c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*     4e78:	10000001 */ 	beqz	$zero,.L00004e80
/*     4e7c:	24a5000a */ 	addiu	$a1,$a1,0xa
.L00004e80:
/*     4e80:	8d8f0024 */ 	lw	$t7,0x24($t4)
/*     4e84:	00afa821 */ 	addu	$s5,$a1,$t7
/*     4e88:	2aa10014 */ 	slti	$at,$s5,0x14
/*     4e8c:	14200002 */ 	bnez	$at,.L00004e98
/*     4e90:	00000000 */ 	sll	$zero,$zero,0x0
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
/*     4ec8:	00000000 */ 	sll	$zero,$zero,0x0
/*     4ecc:	44919000 */ 	mtc1	$s1,$f18
/*     4ed0:	3c017005 */ 	lui	$at,0x7005
/*     4ed4:	d4282528 */ 	ldc1	$f8,0x2528($at)
/*     4ed8:	46809121 */ 	cvt.d.w	$f4,$f18
/*     4edc:	4624a181 */ 	sub.d	$f6,$f20,$f4
/*     4ee0:	46283502 */ 	mul.d	$f20,$f6,$f8
/*     4ee4:	00000000 */ 	sll	$zero,$zero,0x0
.L00004ee8:
/*     4ee8:	1a200011 */ 	blez	$s1,.L00004f30
/*     4eec:	24100008 */ 	addiu	$s0,$zero,0x8
/*     4ef0:	24100007 */ 	addiu	$s0,$zero,0x7
/*     4ef4:	0600000e */ 	bltz	$s0,.L00004f30
/*     4ef8:	02602025 */ 	or	$a0,$s3,$zero
.L00004efc:
/*     4efc:	02202825 */ 	or	$a1,$s1,$zero
/*     4f00:	0c0129e0 */ 	jal	func0004a780
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
/*     4f54:	00000000 */ 	sll	$zero,$zero,0x0
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
/*     4fc0:	10000009 */ 	beqz	$zero,.L00004fe8
/*     4fc4:	24a50001 */ 	addiu	$a1,$a1,0x1
.L00004fc8:
/*     4fc8:	24010065 */ 	addiu	$at,$zero,0x65
/*     4fcc:	11210003 */ 	beq	$t1,$at,.L00004fdc
/*     4fd0:	24010045 */ 	addiu	$at,$zero,0x45
/*     4fd4:	15210003 */ 	bne	$t1,$at,.L00004fe4
/*     4fd8:	00001025 */ 	or	$v0,$zero,$zero
.L00004fdc:
/*     4fdc:	10000001 */ 	beqz	$zero,.L00004fe4
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
/*     5000:	00000000 */ 	sll	$zero,$zero,0x0
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
/*     5030:	10000003 */ 	beqz	$zero,.L00005040
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
/*     50b8:	0c001469 */ 	jal	func000051a4
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

GLOBAL_ASM(
glabel func000050ec
/*     50ec:	94a60000 */ 	lhu	$a2,0x0($a1)
/*     50f0:	240107ff */ 	addiu	$at,$zero,0x7ff
/*     50f4:	30c37ff0 */ 	andi	$v1,$a2,0x7ff0
/*     50f8:	00037103 */ 	sra	$t6,$v1,0x4
/*     50fc:	000e7c00 */ 	sll	$t7,$t6,0x10
/*     5100:	000f1c03 */ 	sra	$v1,$t7,0x10
/*     5104:	14610018 */ 	bne	$v1,$at,.L00005168
/*     5108:	00000000 */ 	sll	$zero,$zero,0x0
/*     510c:	a4800000 */ 	sh	$zero,0x0($a0)
/*     5110:	94b90000 */ 	lhu	$t9,0x0($a1)
/*     5114:	24030002 */ 	addiu	$v1,$zero,0x2
/*     5118:	00031400 */ 	sll	$v0,$v1,0x10
/*     511c:	3328000f */ 	andi	$t0,$t9,0xf
/*     5120:	1500000a */ 	bnez	$t0,.L0000514c
/*     5124:	00026403 */ 	sra	$t4,$v0,0x10
/*     5128:	94a90002 */ 	lhu	$t1,0x2($a1)
/*     512c:	15200007 */ 	bnez	$t1,.L0000514c
/*     5130:	00000000 */ 	sll	$zero,$zero,0x0
/*     5134:	94aa0004 */ 	lhu	$t2,0x4($a1)
/*     5138:	15400004 */ 	bnez	$t2,.L0000514c
/*     513c:	00000000 */ 	sll	$zero,$zero,0x0
/*     5140:	94ab0006 */ 	lhu	$t3,0x6($a1)
/*     5144:	51600004 */ 	beqzl	$t3,.L00005158
/*     5148:	24030001 */ 	addiu	$v1,$zero,0x1
.L0000514c:
/*     514c:	03e00008 */ 	jr	$ra
/*     5150:	01801025 */ 	or	$v0,$t4,$zero
/*     5154:	24030001 */ 	addiu	$v1,$zero,0x1
.L00005158:
/*     5158:	00031400 */ 	sll	$v0,$v1,0x10
/*     515c:	00026403 */ 	sra	$t4,$v0,0x10
/*     5160:	03e00008 */ 	jr	$ra
/*     5164:	01801025 */ 	or	$v0,$t4,$zero
.L00005168:
/*     5168:	18600007 */ 	blez	$v1,.L00005188
/*     516c:	30cd800f */ 	andi	$t5,$a2,0x800f
/*     5170:	35ae3ff0 */ 	ori	$t6,$t5,0x3ff0
/*     5174:	a4ae0000 */ 	sh	$t6,0x0($a1)
/*     5178:	246ffc02 */ 	addiu	$t7,$v1,-1022
/*     517c:	a48f0000 */ 	sh	$t7,0x0($a0)
/*     5180:	03e00008 */ 	jr	$ra
/*     5184:	2402ffff */ 	addiu	$v0,$zero,-1
.L00005188:
/*     5188:	04610003 */ 	bgez	$v1,.L00005198
/*     518c:	00001025 */ 	or	$v0,$zero,$zero
/*     5190:	03e00008 */ 	jr	$ra
/*     5194:	24020002 */ 	addiu	$v0,$zero,0x2
.L00005198:
/*     5198:	a4800000 */ 	sh	$zero,0x0($a0)
/*     519c:	03e00008 */ 	jr	$ra
/*     51a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000051a4
/*     51a4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*     51a8:	afa7002c */ 	sw	$a3,0x2c($sp)
/*     51ac:	00077400 */ 	sll	$t6,$a3,0x10
/*     51b0:	000e3c03 */ 	sra	$a3,$t6,0x10
/*     51b4:	afb10018 */ 	sw	$s1,0x18($sp)
/*     51b8:	afb00014 */ 	sw	$s0,0x14($sp)
/*     51bc:	00808025 */ 	or	$s0,$a0,$zero
/*     51c0:	00c08825 */ 	or	$s1,$a2,$zero
/*     51c4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     51c8:	1ce00004 */ 	bgtz	$a3,.L000051dc
/*     51cc:	afa50024 */ 	sw	$a1,0x24($sp)
/*     51d0:	3c117005 */ 	lui	$s1,%hi(var70052520)
/*     51d4:	26312520 */ 	addiu	$s1,$s1,%lo(var70052520)
/*     51d8:	24070001 */ 	addiu	$a3,$zero,0x1
.L000051dc:
/*     51dc:	93a30027 */ 	lbu	$v1,0x27($sp)
/*     51e0:	24020066 */ 	addiu	$v0,$zero,0x66
/*     51e4:	24040067 */ 	addiu	$a0,$zero,0x67
/*     51e8:	5043000e */ 	beql	$v0,$v1,.L00005224
/*     51ec:	87a80032 */ 	lh	$t0,0x32($sp)
/*     51f0:	10830003 */ 	beq	$a0,$v1,.L00005200
/*     51f4:	24010047 */ 	addiu	$at,$zero,0x47
/*     51f8:	146100a5 */ 	bne	$v1,$at,.L00005490
/*     51fc:	00000000 */ 	sll	$zero,$zero,0x0
.L00005200:
/*     5200:	87a80032 */ 	lh	$t0,0x32($sp)
/*     5204:	2901fffc */ 	slti	$at,$t0,-4
/*     5208:	142000a1 */ 	bnez	$at,.L00005490
/*     520c:	00000000 */ 	sll	$zero,$zero,0x0
/*     5210:	8e180024 */ 	lw	$t8,0x24($s0)
/*     5214:	0118082a */ 	slt	$at,$t0,$t8
/*     5218:	1020009d */ 	beqz	$at,.L00005490
/*     521c:	00000000 */ 	sll	$zero,$zero,0x0
/*     5220:	87a80032 */ 	lh	$t0,0x32($sp)
.L00005224:
/*     5224:	02202825 */ 	or	$a1,$s1,$zero
/*     5228:	25080001 */ 	addiu	$t0,$t0,0x1
/*     522c:	0008cc00 */ 	sll	$t9,$t0,0x10
/*     5230:	1043000e */ 	beq	$v0,$v1,.L0000526c
/*     5234:	00194403 */ 	sra	$t0,$t9,0x10
/*     5238:	8e0a0030 */ 	lw	$t2,0x30($s0)
/*     523c:	8e020024 */ 	lw	$v0,0x24($s0)
/*     5240:	314b0008 */ 	andi	$t3,$t2,0x8
/*     5244:	15600005 */ 	bnez	$t3,.L0000525c
/*     5248:	00e2082a */ 	slt	$at,$a3,$v0
/*     524c:	50200004 */ 	beqzl	$at,.L00005260
/*     5250:	00486023 */ 	subu	$t4,$v0,$t0
/*     5254:	ae070024 */ 	sw	$a3,0x24($s0)
/*     5258:	00e01025 */ 	or	$v0,$a3,$zero
.L0000525c:
/*     525c:	00486023 */ 	subu	$t4,$v0,$t0
.L00005260:
/*     5260:	05810002 */ 	bgez	$t4,.L0000526c
/*     5264:	ae0c0024 */ 	sw	$t4,0x24($s0)
/*     5268:	ae000024 */ 	sw	$zero,0x24($s0)
.L0000526c:
/*     526c:	1d000034 */ 	bgtz	$t0,.L00005340
/*     5270:	00e8082a */ 	slt	$at,$a3,$t0
/*     5274:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*     5278:	8e180014 */ 	lw	$t8,0x14($s0)
/*     527c:	240e0030 */ 	addiu	$t6,$zero,0x30
/*     5280:	00081823 */ 	negu	$v1,$t0
/*     5284:	01f8c821 */ 	addu	$t9,$t7,$t8
/*     5288:	a32e0000 */ 	sb	$t6,0x0($t9)
/*     528c:	8e090014 */ 	lw	$t1,0x14($s0)
/*     5290:	8e020024 */ 	lw	$v0,0x24($s0)
/*     5294:	252a0001 */ 	addiu	$t2,$t1,0x1
/*     5298:	1c400005 */ 	bgtz	$v0,.L000052b0
/*     529c:	ae0a0014 */ 	sw	$t2,0x14($s0)
/*     52a0:	8e0b0030 */ 	lw	$t3,0x30($s0)
/*     52a4:	316c0008 */ 	andi	$t4,$t3,0x8
/*     52a8:	5180000b */ 	beqzl	$t4,.L000052d8
/*     52ac:	0043082a */ 	slt	$at,$v0,$v1
.L000052b0:
/*     52b0:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*     52b4:	8e180014 */ 	lw	$t8,0x14($s0)
/*     52b8:	240d002e */ 	addiu	$t5,$zero,0x2e
/*     52bc:	01f87021 */ 	addu	$t6,$t7,$t8
/*     52c0:	a1cd0000 */ 	sb	$t5,0x0($t6)
/*     52c4:	8e190014 */ 	lw	$t9,0x14($s0)
/*     52c8:	8e020024 */ 	lw	$v0,0x24($s0)
/*     52cc:	27290001 */ 	addiu	$t1,$t9,0x1
/*     52d0:	ae090014 */ 	sw	$t1,0x14($s0)
/*     52d4:	0043082a */ 	slt	$at,$v0,$v1
.L000052d8:
/*     52d8:	50200006 */ 	beqzl	$at,.L000052f4
/*     52dc:	00486021 */ 	addu	$t4,$v0,$t0
/*     52e0:	00024023 */ 	negu	$t0,$v0
/*     52e4:	00085400 */ 	sll	$t2,$t0,0x10
/*     52e8:	000a4403 */ 	sra	$t0,$t2,0x10
/*     52ec:	00081823 */ 	negu	$v1,$t0
/*     52f0:	00486021 */ 	addu	$t4,$v0,$t0
.L000052f4:
/*     52f4:	0187082a */ 	slt	$at,$t4,$a3
/*     52f8:	ae030018 */ 	sw	$v1,0x18($s0)
/*     52fc:	10200004 */ 	beqz	$at,.L00005310
/*     5300:	ae0c0024 */ 	sw	$t4,0x24($s0)
/*     5304:	000c3c00 */ 	sll	$a3,$t4,0x10
/*     5308:	00077c03 */ 	sra	$t7,$a3,0x10
/*     530c:	01e03825 */ 	or	$a3,$t7,$zero
.L00005310:
/*     5310:	8e180008 */ 	lw	$t8,0x8($s0)
/*     5314:	8e0d0014 */ 	lw	$t5,0x14($s0)
/*     5318:	ae07001c */ 	sw	$a3,0x1c($s0)
/*     531c:	a7a7002e */ 	sh	$a3,0x2e($sp)
/*     5320:	00e03025 */ 	or	$a2,$a3,$zero
/*     5324:	0c012978 */ 	jal	memcpy
/*     5328:	030d2021 */ 	addu	$a0,$t8,$t5
/*     532c:	87a7002e */ 	lh	$a3,0x2e($sp)
/*     5330:	8e0e0024 */ 	lw	$t6,0x24($s0)
/*     5334:	01c7c823 */ 	subu	$t9,$t6,$a3
/*     5338:	100000f4 */ 	beqz	$zero,.L0000570c
/*     533c:	ae190020 */ 	sw	$t9,0x20($s0)
.L00005340:
/*     5340:	10200021 */ 	beqz	$at,.L000053c8
/*     5344:	02202825 */ 	or	$a1,$s1,$zero
/*     5348:	8e090008 */ 	lw	$t1,0x8($s0)
/*     534c:	8e0a0014 */ 	lw	$t2,0x14($s0)
/*     5350:	a7a80032 */ 	sh	$t0,0x32($sp)
/*     5354:	a7a7002e */ 	sh	$a3,0x2e($sp)
/*     5358:	02202825 */ 	or	$a1,$s1,$zero
/*     535c:	00e03025 */ 	or	$a2,$a3,$zero
/*     5360:	0c012978 */ 	jal	memcpy
/*     5364:	012a2021 */ 	addu	$a0,$t1,$t2
/*     5368:	87a7002e */ 	lh	$a3,0x2e($sp)
/*     536c:	87a80032 */ 	lh	$t0,0x32($sp)
/*     5370:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*     5374:	8e020024 */ 	lw	$v0,0x24($s0)
/*     5378:	01077823 */ 	subu	$t7,$t0,$a3
/*     537c:	01676021 */ 	addu	$t4,$t3,$a3
/*     5380:	ae0c0014 */ 	sw	$t4,0x14($s0)
/*     5384:	1c400005 */ 	bgtz	$v0,.L0000539c
/*     5388:	ae0f0018 */ 	sw	$t7,0x18($s0)
/*     538c:	8e180030 */ 	lw	$t8,0x30($s0)
/*     5390:	330d0008 */ 	andi	$t5,$t8,0x8
/*     5394:	11a0000a */ 	beqz	$t5,.L000053c0
/*     5398:	00000000 */ 	sll	$zero,$zero,0x0
.L0000539c:
/*     539c:	8e190008 */ 	lw	$t9,0x8($s0)
/*     53a0:	8e090014 */ 	lw	$t1,0x14($s0)
/*     53a4:	240e002e */ 	addiu	$t6,$zero,0x2e
/*     53a8:	03295021 */ 	addu	$t2,$t9,$t1
/*     53ac:	a14e0000 */ 	sb	$t6,0x0($t2)
/*     53b0:	8e0b001c */ 	lw	$t3,0x1c($s0)
/*     53b4:	8e020024 */ 	lw	$v0,0x24($s0)
/*     53b8:	256c0001 */ 	addiu	$t4,$t3,0x1
/*     53bc:	ae0c001c */ 	sw	$t4,0x1c($s0)
.L000053c0:
/*     53c0:	100000d2 */ 	beqz	$zero,.L0000570c
/*     53c4:	ae020020 */ 	sw	$v0,0x20($s0)
.L000053c8:
/*     53c8:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*     53cc:	8e180014 */ 	lw	$t8,0x14($s0)
/*     53d0:	a7a80032 */ 	sh	$t0,0x32($sp)
/*     53d4:	a7a7002e */ 	sh	$a3,0x2e($sp)
/*     53d8:	01003025 */ 	or	$a2,$t0,$zero
/*     53dc:	0c012978 */ 	jal	memcpy
/*     53e0:	01f82021 */ 	addu	$a0,$t7,$t8
/*     53e4:	87a7002e */ 	lh	$a3,0x2e($sp)
/*     53e8:	87a80032 */ 	lh	$t0,0x32($sp)
/*     53ec:	8e0d0014 */ 	lw	$t5,0x14($s0)
/*     53f0:	8e020024 */ 	lw	$v0,0x24($s0)
/*     53f4:	00e83823 */ 	subu	$a3,$a3,$t0
/*     53f8:	00074c00 */ 	sll	$t1,$a3,0x10
/*     53fc:	01a8c821 */ 	addu	$t9,$t5,$t0
/*     5400:	ae190014 */ 	sw	$t9,0x14($s0)
/*     5404:	1c400005 */ 	bgtz	$v0,.L0000541c
/*     5408:	00093c03 */ 	sra	$a3,$t1,0x10
/*     540c:	8e0a0030 */ 	lw	$t2,0x30($s0)
/*     5410:	314b0008 */ 	andi	$t3,$t2,0x8
/*     5414:	5160000b */ 	beqzl	$t3,.L00005444
/*     5418:	0047082a */ 	slt	$at,$v0,$a3
.L0000541c:
/*     541c:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*     5420:	8e180014 */ 	lw	$t8,0x14($s0)
/*     5424:	240c002e */ 	addiu	$t4,$zero,0x2e
/*     5428:	01f86821 */ 	addu	$t5,$t7,$t8
/*     542c:	a1ac0000 */ 	sb	$t4,0x0($t5)
/*     5430:	8e190014 */ 	lw	$t9,0x14($s0)
/*     5434:	8e020024 */ 	lw	$v0,0x24($s0)
/*     5438:	27290001 */ 	addiu	$t1,$t9,0x1
/*     543c:	ae090014 */ 	sw	$t1,0x14($s0)
/*     5440:	0047082a */ 	slt	$at,$v0,$a3
.L00005444:
/*     5444:	10200004 */ 	beqz	$at,.L00005458
/*     5448:	01112821 */ 	addu	$a1,$t0,$s1
/*     544c:	00023c00 */ 	sll	$a3,$v0,0x10
/*     5450:	00077403 */ 	sra	$t6,$a3,0x10
/*     5454:	01c03825 */ 	or	$a3,$t6,$zero
.L00005458:
/*     5458:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*     545c:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*     5460:	a7a7002e */ 	sh	$a3,0x2e($sp)
/*     5464:	00e03025 */ 	or	$a2,$a3,$zero
/*     5468:	0c012978 */ 	jal	memcpy
/*     546c:	014b2021 */ 	addu	$a0,$t2,$t3
/*     5470:	87a7002e */ 	lh	$a3,0x2e($sp)
/*     5474:	8e0f0014 */ 	lw	$t7,0x14($s0)
/*     5478:	8e0c0024 */ 	lw	$t4,0x24($s0)
/*     547c:	01e7c021 */ 	addu	$t8,$t7,$a3
/*     5480:	01876823 */ 	subu	$t5,$t4,$a3
/*     5484:	ae180014 */ 	sw	$t8,0x14($s0)
/*     5488:	100000a0 */ 	beqz	$zero,.L0000570c
/*     548c:	ae0d0018 */ 	sw	$t5,0x18($s0)
.L00005490:
/*     5490:	10830004 */ 	beq	$a0,$v1,.L000054a4
/*     5494:	87a80032 */ 	lh	$t0,0x32($sp)
/*     5498:	24010047 */ 	addiu	$at,$zero,0x47
/*     549c:	54610013 */ 	bnel	$v1,$at,.L000054ec
/*     54a0:	8e0f0008 */ 	lw	$t7,0x8($s0)
.L000054a4:
/*     54a4:	8e020024 */ 	lw	$v0,0x24($s0)
/*     54a8:	240e0065 */ 	addiu	$t6,$zero,0x65
/*     54ac:	00e2082a */ 	slt	$at,$a3,$v0
/*     54b0:	50200004 */ 	beqzl	$at,.L000054c4
/*     54b4:	2459ffff */ 	addiu	$t9,$v0,-1
/*     54b8:	ae070024 */ 	sw	$a3,0x24($s0)
/*     54bc:	00e01025 */ 	or	$v0,$a3,$zero
/*     54c0:	2459ffff */ 	addiu	$t9,$v0,-1
.L000054c4:
/*     54c4:	07210002 */ 	bgez	$t9,.L000054d0
/*     54c8:	ae190024 */ 	sw	$t9,0x24($s0)
/*     54cc:	ae000024 */ 	sw	$zero,0x24($s0)
.L000054d0:
/*     54d0:	54830004 */ 	bnel	$a0,$v1,.L000054e4
/*     54d4:	240a0045 */ 	addiu	$t2,$zero,0x45
/*     54d8:	10000003 */ 	beqz	$zero,.L000054e8
/*     54dc:	a3ae0027 */ 	sb	$t6,0x27($sp)
/*     54e0:	240a0045 */ 	addiu	$t2,$zero,0x45
.L000054e4:
/*     54e4:	a3aa0027 */ 	sb	$t2,0x27($sp)
.L000054e8:
/*     54e8:	8e0f0008 */ 	lw	$t7,0x8($s0)
.L000054ec:
/*     54ec:	8e180014 */ 	lw	$t8,0x14($s0)
/*     54f0:	922b0000 */ 	lbu	$t3,0x0($s1)
/*     54f4:	26310001 */ 	addiu	$s1,$s1,0x1
/*     54f8:	01f86021 */ 	addu	$t4,$t7,$t8
/*     54fc:	a18b0000 */ 	sb	$t3,0x0($t4)
/*     5500:	8e0d0014 */ 	lw	$t5,0x14($s0)
/*     5504:	8e020024 */ 	lw	$v0,0x24($s0)
/*     5508:	25b90001 */ 	addiu	$t9,$t5,0x1
/*     550c:	1c400005 */ 	bgtz	$v0,.L00005524
/*     5510:	ae190014 */ 	sw	$t9,0x14($s0)
/*     5514:	8e090030 */ 	lw	$t1,0x30($s0)
/*     5518:	312e0008 */ 	andi	$t6,$t1,0x8
/*     551c:	11c0000a */ 	beqz	$t6,.L00005548
/*     5520:	00000000 */ 	sll	$zero,$zero,0x0
.L00005524:
/*     5524:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*     5528:	8e180014 */ 	lw	$t8,0x14($s0)
/*     552c:	240a002e */ 	addiu	$t2,$zero,0x2e
/*     5530:	01f85821 */ 	addu	$t3,$t7,$t8
/*     5534:	a16a0000 */ 	sb	$t2,0x0($t3)
/*     5538:	8e0c0014 */ 	lw	$t4,0x14($s0)
/*     553c:	8e020024 */ 	lw	$v0,0x24($s0)
/*     5540:	258d0001 */ 	addiu	$t5,$t4,0x1
/*     5544:	ae0d0014 */ 	sw	$t5,0x14($s0)
.L00005548:
/*     5548:	5840001a */ 	blezl	$v0,.L000055b4
/*     554c:	8e190008 */ 	lw	$t9,0x8($s0)
/*     5550:	24e7ffff */ 	addiu	$a3,$a3,-1
/*     5554:	0007cc00 */ 	sll	$t9,$a3,0x10
/*     5558:	00193c03 */ 	sra	$a3,$t9,0x10
/*     555c:	0047082a */ 	slt	$at,$v0,$a3
/*     5560:	10200004 */ 	beqz	$at,.L00005574
/*     5564:	02202825 */ 	or	$a1,$s1,$zero
/*     5568:	00023c00 */ 	sll	$a3,$v0,0x10
/*     556c:	00077403 */ 	sra	$t6,$a3,0x10
/*     5570:	01c03825 */ 	or	$a3,$t6,$zero
.L00005574:
/*     5574:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*     5578:	8e180014 */ 	lw	$t8,0x14($s0)
/*     557c:	a7a80032 */ 	sh	$t0,0x32($sp)
/*     5580:	a7a7002e */ 	sh	$a3,0x2e($sp)
/*     5584:	00e03025 */ 	or	$a2,$a3,$zero
/*     5588:	0c012978 */ 	jal	memcpy
/*     558c:	01f82021 */ 	addu	$a0,$t7,$t8
/*     5590:	87a7002e */ 	lh	$a3,0x2e($sp)
/*     5594:	8e0a0014 */ 	lw	$t2,0x14($s0)
/*     5598:	8e0c0024 */ 	lw	$t4,0x24($s0)
/*     559c:	87a80032 */ 	lh	$t0,0x32($sp)
/*     55a0:	01475821 */ 	addu	$t3,$t2,$a3
/*     55a4:	01876823 */ 	subu	$t5,$t4,$a3
/*     55a8:	ae0b0014 */ 	sw	$t3,0x14($s0)
/*     55ac:	ae0d0018 */ 	sw	$t5,0x18($s0)
/*     55b0:	8e190008 */ 	lw	$t9,0x8($s0)
.L000055b4:
/*     55b4:	8e090014 */ 	lw	$t1,0x14($s0)
/*     55b8:	93ae0027 */ 	lbu	$t6,0x27($sp)
/*     55bc:	03298821 */ 	addu	$s1,$t9,$t1
/*     55c0:	26310001 */ 	addiu	$s1,$s1,0x1
/*     55c4:	05000005 */ 	bltz	$t0,.L000055dc
/*     55c8:	a22effff */ 	sb	$t6,-0x1($s1)
/*     55cc:	240f002b */ 	addiu	$t7,$zero,0x2b
/*     55d0:	a22f0000 */ 	sb	$t7,0x0($s1)
/*     55d4:	10000008 */ 	beqz	$zero,.L000055f8
/*     55d8:	26310001 */ 	addiu	$s1,$s1,0x1
.L000055dc:
/*     55dc:	00084023 */ 	negu	$t0,$t0
/*     55e0:	00085400 */ 	sll	$t2,$t0,0x10
/*     55e4:	2418002d */ 	addiu	$t8,$zero,0x2d
/*     55e8:	000a5c03 */ 	sra	$t3,$t2,0x10
/*     55ec:	a2380000 */ 	sb	$t8,0x0($s1)
/*     55f0:	26310001 */ 	addiu	$s1,$s1,0x1
/*     55f4:	01604025 */ 	or	$t0,$t3,$zero
.L000055f8:
/*     55f8:	29010064 */ 	slti	$at,$t0,0x64
/*     55fc:	5420002a */ 	bnezl	$at,.L000056a8
/*     5600:	2402000a */ 	addiu	$v0,$zero,0xa
/*     5604:	290103e8 */ 	slti	$at,$t0,0x3e8
/*     5608:	14200013 */ 	bnez	$at,.L00005658
/*     560c:	240203e8 */ 	addiu	$v0,$zero,0x3e8
/*     5610:	0102001a */ 	div	$zero,$t0,$v0
/*     5614:	14400002 */ 	bnez	$v0,.L00005620
/*     5618:	00000000 */ 	sll	$zero,$zero,0x0
/*     561c:	0007000d */ 	break	0x7
.L00005620:
/*     5620:	2401ffff */ 	addiu	$at,$zero,-1
/*     5624:	14410004 */ 	bne	$v0,$at,.L00005638
/*     5628:	3c018000 */ 	lui	$at,0x8000
/*     562c:	15010002 */ 	bne	$t0,$at,.L00005638
/*     5630:	00000000 */ 	sll	$zero,$zero,0x0
/*     5634:	0006000d */ 	break	0x6
.L00005638:
/*     5638:	00004010 */ 	mfhi	$t0
/*     563c:	0008cc00 */ 	sll	$t9,$t0,0x10
/*     5640:	00006012 */ 	mflo	$t4
/*     5644:	258d0030 */ 	addiu	$t5,$t4,0x30
/*     5648:	00194c03 */ 	sra	$t1,$t9,0x10
/*     564c:	01204025 */ 	or	$t0,$t1,$zero
/*     5650:	a22d0000 */ 	sb	$t5,0x0($s1)
/*     5654:	26310001 */ 	addiu	$s1,$s1,0x1
.L00005658:
/*     5658:	24020064 */ 	addiu	$v0,$zero,0x64
/*     565c:	0102001a */ 	div	$zero,$t0,$v0
/*     5660:	14400002 */ 	bnez	$v0,.L0000566c
/*     5664:	00000000 */ 	sll	$zero,$zero,0x0
/*     5668:	0007000d */ 	break	0x7
.L0000566c:
/*     566c:	2401ffff */ 	addiu	$at,$zero,-1
/*     5670:	14410004 */ 	bne	$v0,$at,.L00005684
/*     5674:	3c018000 */ 	lui	$at,0x8000
/*     5678:	15010002 */ 	bne	$t0,$at,.L00005684
/*     567c:	00000000 */ 	sll	$zero,$zero,0x0
/*     5680:	0006000d */ 	break	0x6
.L00005684:
/*     5684:	00004010 */ 	mfhi	$t0
/*     5688:	0008c400 */ 	sll	$t8,$t0,0x10
/*     568c:	00007012 */ 	mflo	$t6
/*     5690:	25cf0030 */ 	addiu	$t7,$t6,0x30
/*     5694:	00185403 */ 	sra	$t2,$t8,0x10
/*     5698:	01404025 */ 	or	$t0,$t2,$zero
/*     569c:	a22f0000 */ 	sb	$t7,0x0($s1)
/*     56a0:	26310001 */ 	addiu	$s1,$s1,0x1
/*     56a4:	2402000a */ 	addiu	$v0,$zero,0xa
.L000056a8:
/*     56a8:	0102001a */ 	div	$zero,$t0,$v0
/*     56ac:	14400002 */ 	bnez	$v0,.L000056b8
/*     56b0:	00000000 */ 	sll	$zero,$zero,0x0
/*     56b4:	0007000d */ 	break	0x7
.L000056b8:
/*     56b8:	2401ffff */ 	addiu	$at,$zero,-1
/*     56bc:	14410004 */ 	bne	$v0,$at,.L000056d0
/*     56c0:	3c018000 */ 	lui	$at,0x8000
/*     56c4:	15010002 */ 	bne	$t0,$at,.L000056d0
/*     56c8:	00000000 */ 	sll	$zero,$zero,0x0
/*     56cc:	0006000d */ 	break	0x6
.L000056d0:
/*     56d0:	00004010 */ 	mfhi	$t0
/*     56d4:	00086c00 */ 	sll	$t5,$t0,0x10
/*     56d8:	000dcc03 */ 	sra	$t9,$t5,0x10
/*     56dc:	00005812 */ 	mflo	$t3
/*     56e0:	256c0030 */ 	addiu	$t4,$t3,0x30
/*     56e4:	27290030 */ 	addiu	$t1,$t9,0x30
/*     56e8:	a22c0000 */ 	sb	$t4,0x0($s1)
/*     56ec:	a2290001 */ 	sb	$t1,0x1($s1)
/*     56f0:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*     56f4:	8e180014 */ 	lw	$t8,0x14($s0)
/*     56f8:	26310002 */ 	addiu	$s1,$s1,0x2
/*     56fc:	022e7823 */ 	subu	$t7,$s1,$t6
/*     5700:	01f85023 */ 	subu	$t2,$t7,$t8
/*     5704:	03204025 */ 	or	$t0,$t9,$zero
/*     5708:	ae0a001c */ 	sw	$t2,0x1c($s0)
.L0000570c:
/*     570c:	8e0b0030 */ 	lw	$t3,0x30($s0)
/*     5710:	24010010 */ 	addiu	$at,$zero,0x10
/*     5714:	316c0014 */ 	andi	$t4,$t3,0x14
/*     5718:	55810010 */ 	bnel	$t4,$at,.L0000575c
/*     571c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     5720:	8e0d000c */ 	lw	$t5,0xc($s0)
/*     5724:	8e190014 */ 	lw	$t9,0x14($s0)
/*     5728:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*     572c:	8e18001c */ 	lw	$t8,0x1c($s0)
/*     5730:	8e0b0020 */ 	lw	$t3,0x20($s0)
/*     5734:	01b94821 */ 	addu	$t1,$t5,$t9
/*     5738:	8e030028 */ 	lw	$v1,0x28($s0)
/*     573c:	012e7821 */ 	addu	$t7,$t1,$t6
/*     5740:	01f85021 */ 	addu	$t2,$t7,$t8
/*     5744:	014b1021 */ 	addu	$v0,$t2,$t3
/*     5748:	0043082a */ 	slt	$at,$v0,$v1
/*     574c:	10200002 */ 	beqz	$at,.L00005758
/*     5750:	00626023 */ 	subu	$t4,$v1,$v0
/*     5754:	ae0c0010 */ 	sw	$t4,0x10($s0)
.L00005758:
/*     5758:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0000575c:
/*     575c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     5760:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     5764:	03e00008 */ 	jr	$ra
/*     5768:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*     576c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00005770
/*     5770:	27bdff90 */ 	addiu	$sp,$sp,-112
/*     5774:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     5778:	afb5002c */ 	sw	$s5,0x2c($sp)
/*     577c:	afb20020 */ 	sw	$s2,0x20($sp)
/*     5780:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     5784:	00809025 */ 	or	$s2,$a0,$zero
/*     5788:	afbe0038 */ 	sw	$s8,0x38($sp)
/*     578c:	afb70034 */ 	sw	$s7,0x34($sp)
/*     5790:	afb60030 */ 	sw	$s6,0x30($sp)
/*     5794:	afb40028 */ 	sw	$s4,0x28($sp)
/*     5798:	afb30024 */ 	sw	$s3,0x24($sp)
/*     579c:	afb00018 */ 	sw	$s0,0x18($sp)
/*     57a0:	afa50074 */ 	sw	$a1,0x74($sp)
/*     57a4:	0000a825 */ 	or	$s5,$zero,$zero
/*     57a8:	0c012a18 */ 	jal	__osSiGetAccess
/*     57ac:	24110001 */ 	addiu	$s1,$zero,0x1
/*     57b0:	3c1e800a */ 	lui	$s8,0x800a
/*     57b4:	3c138009 */ 	lui	$s3,%hi(var80090a20)
/*     57b8:	26730a20 */ 	addiu	$s3,$s3,%lo(var80090a20)
/*     57bc:	27dec821 */ 	addiu	$s8,$s8,-14303
/*     57c0:	00008025 */ 	or	$s0,$zero,$zero
/*     57c4:	27b70054 */ 	addiu	$s7,$sp,0x54
/*     57c8:	27b60067 */ 	addiu	$s6,$sp,0x67
/*     57cc:	27b40068 */ 	addiu	$s4,$sp,0x68
.L000057d0:
/*     57d0:	0c00163f */ 	jal	func000058fc
/*     57d4:	00002025 */ 	or	$a0,$zero,$zero
/*     57d8:	24040001 */ 	addiu	$a0,$zero,0x1
/*     57dc:	0c012a34 */ 	jal	__osSiRawStartDma
/*     57e0:	02602825 */ 	or	$a1,$s3,$zero
/*     57e4:	02402025 */ 	or	$a0,$s2,$zero
/*     57e8:	02802825 */ 	or	$a1,$s4,$zero
/*     57ec:	0c0121bc */ 	jal	osRecvMesg
/*     57f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*     57f4:	00002025 */ 	or	$a0,$zero,$zero
/*     57f8:	0c012a34 */ 	jal	__osSiRawStartDma
/*     57fc:	02602825 */ 	or	$a1,$s3,$zero
/*     5800:	afa2006c */ 	sw	$v0,0x6c($sp)
/*     5804:	02402025 */ 	or	$a0,$s2,$zero
/*     5808:	02802825 */ 	or	$a1,$s4,$zero
/*     580c:	0c0121bc */ 	jal	osRecvMesg
/*     5810:	24060001 */ 	addiu	$a2,$zero,0x1
/*     5814:	02c02025 */ 	or	$a0,$s6,$zero
/*     5818:	0c00166c */ 	jal	func000059b0
/*     581c:	02e02825 */ 	or	$a1,$s7,$zero
/*     5820:	93c30000 */ 	lbu	$v1,0x0($s8)
/*     5824:	27a20054 */ 	addiu	$v0,$sp,0x54
/*     5828:	5860000c */ 	blezl	$v1,.L0000585c
/*     582c:	02031026 */ 	xor	$v0,$s0,$v1
.L00005830:
/*     5830:	904e0002 */ 	lbu	$t6,0x2($v0)
/*     5834:	31cf0004 */ 	andi	$t7,$t6,0x4
/*     5838:	55e00004 */ 	bnezl	$t7,.L0000584c
/*     583c:	26100001 */ 	addiu	$s0,$s0,0x1
/*     5840:	10000005 */ 	beqz	$zero,.L00005858
/*     5844:	2631ffff */ 	addiu	$s1,$s1,-1
/*     5848:	26100001 */ 	addiu	$s0,$s0,0x1
.L0000584c:
/*     584c:	0203082a */ 	slt	$at,$s0,$v1
/*     5850:	1420fff7 */ 	bnez	$at,.L00005830
/*     5854:	24420004 */ 	addiu	$v0,$v0,0x4
.L00005858:
/*     5858:	02031026 */ 	xor	$v0,$s0,$v1
.L0000585c:
/*     585c:	14400002 */ 	bnez	$v0,.L00005868
/*     5860:	00008025 */ 	or	$s0,$zero,$zero
/*     5864:	00008825 */ 	or	$s1,$zero,$zero
.L00005868:
/*     5868:	1e20ffd9 */ 	bgtz	$s1,.L000057d0
/*     586c:	00000000 */ 	sll	$zero,$zero,0x0
/*     5870:	18600011 */ 	blez	$v1,.L000058b8
/*     5874:	27a20054 */ 	addiu	$v0,$sp,0x54
.L00005878:
/*     5878:	90580003 */ 	lbu	$t8,0x3($v0)
/*     587c:	5700000b */ 	bnezl	$t8,.L000058ac
/*     5880:	26100001 */ 	addiu	$s0,$s0,0x1
/*     5884:	90590002 */ 	lbu	$t9,0x2($v0)
/*     5888:	24090001 */ 	addiu	$t1,$zero,0x1
/*     588c:	02095004 */ 	sllv	$t2,$t1,$s0
/*     5890:	33280001 */ 	andi	$t0,$t9,0x1
/*     5894:	51000005 */ 	beqzl	$t0,.L000058ac
/*     5898:	26100001 */ 	addiu	$s0,$s0,0x1
/*     589c:	02aaa825 */ 	or	$s5,$s5,$t2
/*     58a0:	32ab00ff */ 	andi	$t3,$s5,0xff
/*     58a4:	0160a825 */ 	or	$s5,$t3,$zero
/*     58a8:	26100001 */ 	addiu	$s0,$s0,0x1
.L000058ac:
/*     58ac:	0203082a */ 	slt	$at,$s0,$v1
/*     58b0:	1420fff1 */ 	bnez	$at,.L00005878
/*     58b4:	24420004 */ 	addiu	$v0,$v0,0x4
.L000058b8:
/*     58b8:	0c012a29 */ 	jal	__osSiRelAccess
/*     58bc:	00000000 */ 	sll	$zero,$zero,0x0
/*     58c0:	8fac0074 */ 	lw	$t4,0x74($sp)
/*     58c4:	a1950000 */ 	sb	$s5,0x0($t4)
/*     58c8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     58cc:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*     58d0:	8fb70034 */ 	lw	$s7,0x34($sp)
/*     58d4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*     58d8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*     58dc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     58e0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     58e4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     58e8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     58ec:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     58f0:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*     58f4:	03e00008 */ 	jr	$ra
/*     58f8:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func000058fc
/*     58fc:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*     5900:	3c058009 */ 	lui	$a1,%hi(var80090a20)
/*     5904:	3c01800a */ 	lui	$at,0x800a
/*     5908:	24a20a20 */ 	addiu	$v0,$a1,%lo(var80090a20)
/*     590c:	afa40010 */ 	sw	$a0,0x10($sp)
/*     5910:	a024c820 */ 	sb	$a0,-0x37e0($at)
/*     5914:	240f0001 */ 	addiu	$t7,$zero,0x1
/*     5918:	ac4f003c */ 	sw	$t7,0x3c($v0)
/*     591c:	3c06800a */ 	lui	$a2,0x800a
/*     5920:	24c6c821 */ 	addiu	$a2,$a2,-14303
/*     5924:	90cd0000 */ 	lbu	$t5,0x0($a2)
/*     5928:	241800ff */ 	addiu	$t8,$zero,0xff
/*     592c:	24190001 */ 	addiu	$t9,$zero,0x1
/*     5930:	24080003 */ 	addiu	$t0,$zero,0x3
/*     5934:	240900ff */ 	addiu	$t1,$zero,0xff
/*     5938:	240a00ff */ 	addiu	$t2,$zero,0xff
/*     593c:	240b00ff */ 	addiu	$t3,$zero,0xff
/*     5940:	240c00ff */ 	addiu	$t4,$zero,0xff
/*     5944:	a3b80004 */ 	sb	$t8,0x4($sp)
/*     5948:	a3b90005 */ 	sb	$t9,0x5($sp)
/*     594c:	a3a80006 */ 	sb	$t0,0x6($sp)
/*     5950:	a3a40007 */ 	sb	$a0,0x7($sp)
/*     5954:	a3a90008 */ 	sb	$t1,0x8($sp)
/*     5958:	a3aa0009 */ 	sb	$t2,0x9($sp)
/*     595c:	a3ab000a */ 	sb	$t3,0xa($sp)
/*     5960:	a3ac000b */ 	sb	$t4,0xb($sp)
/*     5964:	19a0000e */ 	blez	$t5,.L000059a0
/*     5968:	00001825 */ 	or	$v1,$zero,$zero
/*     596c:	27a40004 */ 	addiu	$a0,$sp,0x4
/*     5970:	8c810000 */ 	lw	$at,0x0($a0)
.L00005974:
/*     5974:	24630001 */ 	addiu	$v1,$v1,0x1
/*     5978:	24420008 */ 	addiu	$v0,$v0,0x8
/*     597c:	a841fff8 */ 	swl	$at,-0x8($v0)
/*     5980:	b841fffb */ 	swr	$at,-0x5($v0)
/*     5984:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*     5988:	a84ffffc */ 	swl	$t7,-0x4($v0)
/*     598c:	b84fffff */ 	swr	$t7,-0x1($v0)
/*     5990:	90d80000 */ 	lbu	$t8,0x0($a2)
/*     5994:	0078082a */ 	slt	$at,$v1,$t8
/*     5998:	5420fff6 */ 	bnezl	$at,.L00005974
/*     599c:	8c810000 */ 	lw	$at,0x0($a0)
.L000059a0:
/*     59a0:	241900fe */ 	addiu	$t9,$zero,0xfe
/*     59a4:	a0590000 */ 	sb	$t9,0x0($v0)
/*     59a8:	03e00008 */ 	jr	$ra
/*     59ac:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

GLOBAL_ASM(
glabel func000059b0
/*     59b0:	3c07800a */ 	lui	$a3,0x800a
/*     59b4:	24e7c821 */ 	addiu	$a3,$a3,-14303
/*     59b8:	90ee0000 */ 	lbu	$t6,0x0($a3)
/*     59bc:	3c038009 */ 	lui	$v1,%hi(var80090a20)
/*     59c0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     59c4:	00001025 */ 	or	$v0,$zero,$zero
/*     59c8:	24630a20 */ 	addiu	$v1,$v1,%lo(var80090a20)
/*     59cc:	19c00020 */ 	blez	$t6,.L00005a50
/*     59d0:	00003025 */ 	or	$a2,$zero,$zero
/*     59d4:	27a8000c */ 	addiu	$t0,$sp,0xc
.L000059d8:
/*     59d8:	88610000 */ 	lwl	$at,0x0($v1)
/*     59dc:	98610003 */ 	lwr	$at,0x3($v1)
/*     59e0:	ad010000 */ 	sw	$at,0x0($t0)
/*     59e4:	88780004 */ 	lwl	$t8,0x4($v1)
/*     59e8:	98780007 */ 	lwr	$t8,0x7($v1)
/*     59ec:	ad180004 */ 	sw	$t8,0x4($t0)
/*     59f0:	93b9000e */ 	lbu	$t9,0xe($sp)
/*     59f4:	332900c0 */ 	andi	$t1,$t9,0xc0
/*     59f8:	00095103 */ 	sra	$t2,$t1,0x4
/*     59fc:	314b00ff */ 	andi	$t3,$t2,0xff
/*     5a00:	1560000d */ 	bnez	$t3,.L00005a38
/*     5a04:	a0aa0003 */ 	sb	$t2,0x3($a1)
/*     5a08:	93ac0011 */ 	lbu	$t4,0x11($sp)
/*     5a0c:	93ae0010 */ 	lbu	$t6,0x10($sp)
/*     5a10:	24190001 */ 	addiu	$t9,$zero,0x1
/*     5a14:	000c6a00 */ 	sll	$t5,$t4,0x8
/*     5a18:	01ae7825 */ 	or	$t7,$t5,$t6
/*     5a1c:	a4af0000 */ 	sh	$t7,0x0($a1)
/*     5a20:	93b80012 */ 	lbu	$t8,0x12($sp)
/*     5a24:	00d94804 */ 	sllv	$t1,$t9,$a2
/*     5a28:	00491025 */ 	or	$v0,$v0,$t1
/*     5a2c:	304a00ff */ 	andi	$t2,$v0,0xff
/*     5a30:	01401025 */ 	or	$v0,$t2,$zero
/*     5a34:	a0b80002 */ 	sb	$t8,0x2($a1)
.L00005a38:
/*     5a38:	90eb0000 */ 	lbu	$t3,0x0($a3)
/*     5a3c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*     5a40:	24630008 */ 	addiu	$v1,$v1,0x8
/*     5a44:	00cb082a */ 	slt	$at,$a2,$t3
/*     5a48:	1420ffe3 */ 	bnez	$at,.L000059d8
/*     5a4c:	24a50004 */ 	addiu	$a1,$a1,0x4
.L00005a50:
/*     5a50:	a0820000 */ 	sb	$v0,0x0($a0)
/*     5a54:	03e00008 */ 	jr	$ra
/*     5a58:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     5a5c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00005a60
/*     5a60:	46006109 */ 	trunc.l.s	$f4,$f12
/*     5a64:	44222000 */ 	dmfc1	$v0,$f4
/*     5a68:	00000000 */ 	sll	$zero,$zero,0x0
/*     5a6c:	0002183c */ 	dsll32	$v1,$v0,0x0
/*     5a70:	0003183f */ 	dsra32	$v1,$v1,0x0
/*     5a74:	03e00008 */ 	jr	$ra
/*     5a78:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func00005a7c
/*     5a7c:	444ef800 */ 	cfc1	$t6,$31
/*     5a80:	24020001 */ 	addiu	$v0,$zero,0x1
/*     5a84:	44c2f800 */ 	ctc1	$v0,$31
/*     5a88:	00000000 */ 	sll	$zero,$zero,0x0
/*     5a8c:	46006125 */ 	cvt.l.s	$f4,$f12
/*     5a90:	4442f800 */ 	cfc1	$v0,$31
/*     5a94:	00000000 */ 	sll	$zero,$zero,0x0
/*     5a98:	30410004 */ 	andi	$at,$v0,0x4
/*     5a9c:	30420078 */ 	andi	$v0,$v0,0x78
/*     5aa0:	10400014 */ 	beqz	$v0,.L00005af4
/*     5aa4:	3c015f00 */ 	lui	$at,0x5f00
/*     5aa8:	44812000 */ 	mtc1	$at,$f4
/*     5aac:	24020001 */ 	addiu	$v0,$zero,0x1
/*     5ab0:	46046101 */ 	sub.s	$f4,$f12,$f4
/*     5ab4:	44c2f800 */ 	ctc1	$v0,$31
/*     5ab8:	00000000 */ 	sll	$zero,$zero,0x0
/*     5abc:	46002125 */ 	cvt.l.s	$f4,$f4
/*     5ac0:	4442f800 */ 	cfc1	$v0,$31
/*     5ac4:	00000000 */ 	sll	$zero,$zero,0x0
/*     5ac8:	30410004 */ 	andi	$at,$v0,0x4
/*     5acc:	30420078 */ 	andi	$v0,$v0,0x78
/*     5ad0:	14400006 */ 	bnez	$v0,.L00005aec
/*     5ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*     5ad8:	3c0f8000 */ 	lui	$t7,0x8000
/*     5adc:	000f783c */ 	dsll32	$t7,$t7,0x0
/*     5ae0:	44222000 */ 	dmfc1	$v0,$f4
/*     5ae4:	10000007 */ 	beqz	$zero,.L00005b04
/*     5ae8:	004f1025 */ 	or	$v0,$v0,$t7
.L00005aec:
/*     5aec:	10000005 */ 	beqz	$zero,.L00005b04
/*     5af0:	2402ffff */ 	addiu	$v0,$zero,-1
.L00005af4:
/*     5af4:	44222000 */ 	dmfc1	$v0,$f4
/*     5af8:	00000000 */ 	sll	$zero,$zero,0x0
/*     5afc:	0440fffb */ 	bltz	$v0,.L00005aec
/*     5b00:	00000000 */ 	sll	$zero,$zero,0x0
.L00005b04:
/*     5b04:	44cef800 */ 	ctc1	$t6,$31
/*     5b08:	0002183c */ 	dsll32	$v1,$v0,0x0
/*     5b0c:	0003183f */ 	dsra32	$v1,$v1,0x0
/*     5b10:	03e00008 */ 	jr	$ra
/*     5b14:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func00005b18
/*     5b18:	afa40000 */ 	sw	$a0,0x0($sp)
/*     5b1c:	afa50004 */ 	sw	$a1,0x4($sp)
/*     5b20:	dfae0000 */ 	ld	$t6,0x0($sp)
/*     5b24:	44ae2000 */ 	dmtc1	$t6,$f4
/*     5b28:	03e00008 */ 	jr	$ra
/*     5b2c:	46a02021 */ 	cvt.d.l	$f0,$f4
);

GLOBAL_ASM(
glabel func00005b30
/*     5b30:	afa40000 */ 	sw	$a0,0x0($sp)
/*     5b34:	afa50004 */ 	sw	$a1,0x4($sp)
/*     5b38:	dfae0000 */ 	ld	$t6,0x0($sp)
/*     5b3c:	44ae2000 */ 	dmtc1	$t6,$f4
/*     5b40:	05c10005 */ 	bgez	$t6,.L00005b58
/*     5b44:	46a02020 */ 	cvt.s.l	$f0,$f4
/*     5b48:	3c014f80 */ 	lui	$at,0x4f80
/*     5b4c:	44813000 */ 	mtc1	$at,$f6
/*     5b50:	00000000 */ 	sll	$zero,$zero,0x0
/*     5b54:	46060000 */ 	add.s	$f0,$f0,$f6
.L00005b58:
/*     5b58:	03e00008 */ 	jr	$ra
/*     5b5c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00005b60
/*     5b60:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*     5b64:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     5b68:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     5b6c:	3c018009 */ 	lui	$at,0x8009
/*     5b70:	afb10018 */ 	sw	$s1,0x18($sp)
/*     5b74:	afb00014 */ 	sw	$s0,0x14($sp)
/*     5b78:	0c012b34 */ 	jal	func0004acd0
/*     5b7c:	ac2e0a60 */ 	sw	$t6,0xa60($at)
/*     5b80:	3c012000 */ 	lui	$at,0x2000
/*     5b84:	0c012b30 */ 	jal	func0004acc0
/*     5b88:	00412025 */ 	or	$a0,$v0,$at
/*     5b8c:	3c040100 */ 	lui	$a0,0x100
/*     5b90:	0c012078 */ 	jal	func000481e0
/*     5b94:	34840800 */ 	ori	$a0,$a0,0x800
/*     5b98:	3c101fc0 */ 	lui	$s0,0x1fc0
/*     5b9c:	361007fc */ 	ori	$s0,$s0,0x7fc
/*     5ba0:	27b10034 */ 	addiu	$s1,$sp,0x34
/*     5ba4:	02202825 */ 	or	$a1,$s1,$zero
/*     5ba8:	0c012b38 */ 	jal	func0004ace0
/*     5bac:	02002025 */ 	or	$a0,$s0,$zero
/*     5bb0:	10400005 */ 	beqz	$v0,.L00005bc8
/*     5bb4:	02002025 */ 	or	$a0,$s0,$zero
.L00005bb8:
/*     5bb8:	0c012b38 */ 	jal	func0004ace0
/*     5bbc:	02202825 */ 	or	$a1,$s1,$zero
/*     5bc0:	5440fffd */ 	bnezl	$v0,.L00005bb8
/*     5bc4:	02002025 */ 	or	$a0,$s0,$zero
.L00005bc8:
/*     5bc8:	8fa50034 */ 	lw	$a1,0x34($sp)
/*     5bcc:	02002025 */ 	or	$a0,$s0,$zero
/*     5bd0:	34af0008 */ 	ori	$t7,$a1,0x8
/*     5bd4:	0c012b4c */ 	jal	func0004ad30
/*     5bd8:	01e02825 */ 	or	$a1,$t7,$zero
/*     5bdc:	10400008 */ 	beqz	$v0,.L00005c00
/*     5be0:	00000000 */ 	sll	$zero,$zero,0x0
/*     5be4:	8fa50034 */ 	lw	$a1,0x34($sp)
.L00005be8:
/*     5be8:	02002025 */ 	or	$a0,$s0,$zero
/*     5bec:	34b80008 */ 	ori	$t8,$a1,0x8
/*     5bf0:	0c012b4c */ 	jal	func0004ad30
/*     5bf4:	03002825 */ 	or	$a1,$t8,$zero
/*     5bf8:	5440fffb */ 	bnezl	$v0,.L00005be8
/*     5bfc:	8fa50034 */ 	lw	$a1,0x34($sp)
.L00005c00:
/*     5c00:	3c027000 */ 	lui	$v0,%hi(__osExceptionPreamble)
/*     5c04:	244234f0 */ 	addiu	$v0,$v0,%lo(__osExceptionPreamble)
/*     5c08:	8c410000 */ 	lw	$at,0x0($v0)
/*     5c0c:	3c108000 */ 	lui	$s0,0x8000
/*     5c10:	3c098000 */ 	lui	$t1,0x8000
/*     5c14:	ae010000 */ 	sw	$at,0x0($s0)
/*     5c18:	8c480004 */ 	lw	$t0,0x4($v0)
/*     5c1c:	35290080 */ 	ori	$t1,$t1,0x80
/*     5c20:	3c0c8000 */ 	lui	$t4,0x8000
/*     5c24:	ae080004 */ 	sw	$t0,0x4($s0)
/*     5c28:	8c410008 */ 	lw	$at,0x8($v0)
/*     5c2c:	358c0100 */ 	ori	$t4,$t4,0x100
/*     5c30:	3c0f8000 */ 	lui	$t7,0x8000
/*     5c34:	ae010008 */ 	sw	$at,0x8($s0)
/*     5c38:	8c48000c */ 	lw	$t0,0xc($v0)
/*     5c3c:	35ef0180 */ 	ori	$t7,$t7,0x180
/*     5c40:	02002025 */ 	or	$a0,$s0,$zero
/*     5c44:	ae08000c */ 	sw	$t0,0xc($s0)
/*     5c48:	8c410000 */ 	lw	$at,0x0($v0)
/*     5c4c:	24050190 */ 	addiu	$a1,$zero,0x190
/*     5c50:	ad210000 */ 	sw	$at,0x0($t1)
/*     5c54:	8c4b0004 */ 	lw	$t3,0x4($v0)
/*     5c58:	ad2b0004 */ 	sw	$t3,0x4($t1)
/*     5c5c:	8c410008 */ 	lw	$at,0x8($v0)
/*     5c60:	ad210008 */ 	sw	$at,0x8($t1)
/*     5c64:	8c4b000c */ 	lw	$t3,0xc($v0)
/*     5c68:	ad2b000c */ 	sw	$t3,0xc($t1)
/*     5c6c:	8c410000 */ 	lw	$at,0x0($v0)
/*     5c70:	ad810000 */ 	sw	$at,0x0($t4)
/*     5c74:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*     5c78:	ad8e0004 */ 	sw	$t6,0x4($t4)
/*     5c7c:	8c410008 */ 	lw	$at,0x8($v0)
/*     5c80:	ad810008 */ 	sw	$at,0x8($t4)
/*     5c84:	8c4e000c */ 	lw	$t6,0xc($v0)
/*     5c88:	ad8e000c */ 	sw	$t6,0xc($t4)
/*     5c8c:	8c410000 */ 	lw	$at,0x0($v0)
/*     5c90:	ade10000 */ 	sw	$at,0x0($t7)
/*     5c94:	8c590004 */ 	lw	$t9,0x4($v0)
/*     5c98:	adf90004 */ 	sw	$t9,0x4($t7)
/*     5c9c:	8c410008 */ 	lw	$at,0x8($v0)
/*     5ca0:	ade10008 */ 	sw	$at,0x8($t7)
/*     5ca4:	8c59000c */ 	lw	$t9,0xc($v0)
/*     5ca8:	0c012b60 */ 	jal	osWritebackDCache
/*     5cac:	adf9000c */ 	sw	$t9,0xc($t7)
/*     5cb0:	02002025 */ 	or	$a0,$s0,$zero
/*     5cb4:	0c012054 */ 	jal	func00048150
/*     5cb8:	24050190 */ 	addiu	$a1,$zero,0x190
/*     5cbc:	0c001770 */ 	jal	func00005dc0
/*     5cc0:	00000000 */ 	sll	$zero,$zero,0x0
/*     5cc4:	0c000bfc */ 	jal	func00002ff0
/*     5cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*     5ccc:	3c108006 */ 	lui	$s0,%hi(var8005cf60)
/*     5cd0:	2610cf60 */ 	addiu	$s0,$s0,%lo(var8005cf60)
/*     5cd4:	8e040000 */ 	lw	$a0,0x0($s0)
/*     5cd8:	8e050004 */ 	lw	$a1,0x4($s0)
/*     5cdc:	24060000 */ 	addiu	$a2,$zero,0x0
/*     5ce0:	0c012bda */ 	jal	func0004af68
/*     5ce4:	24070003 */ 	addiu	$a3,$zero,0x3
/*     5ce8:	00402025 */ 	or	$a0,$v0,$zero
/*     5cec:	00602825 */ 	or	$a1,$v1,$zero
/*     5cf0:	24060000 */ 	addiu	$a2,$zero,0x0
/*     5cf4:	0c012b9a */ 	jal	func0004ae68
/*     5cf8:	24070004 */ 	addiu	$a3,$zero,0x4
/*     5cfc:	ae020000 */ 	sw	$v0,0x0($s0)
/*     5d00:	ae030004 */ 	sw	$v1,0x4($s0)
/*     5d04:	3c088000 */ 	lui	$t0,0x8000
/*     5d08:	8d08030c */ 	lw	$t0,0x30c($t0)
/*     5d0c:	3c048000 */ 	lui	$a0,0x8000
/*     5d10:	2484031c */ 	addiu	$a0,$a0,0x31c
/*     5d14:	15000003 */ 	bnez	$t0,.L00005d24
/*     5d18:	00000000 */ 	sll	$zero,$zero,0x0
/*     5d1c:	0c012c30 */ 	jal	bzero
/*     5d20:	24050040 */ 	addiu	$a1,$zero,0x40
.L00005d24:
/*     5d24:	3c028000 */ 	lui	$v0,0x8000
/*     5d28:	8c420300 */ 	lw	$v0,0x300($v0)
/*     5d2c:	3c0a02f5 */ 	lui	$t2,0x2f5
/*     5d30:	354ab2d2 */ 	ori	$t2,$t2,0xb2d2
/*     5d34:	14400004 */ 	bnez	$v0,.L00005d48
/*     5d38:	24010002 */ 	addiu	$at,$zero,0x2
/*     5d3c:	3c018006 */ 	lui	$at,0x8006
/*     5d40:	1000000b */ 	beqz	$zero,.L00005d70
/*     5d44:	ac2acf68 */ 	sw	$t2,-0x3098($at)
.L00005d48:
/*     5d48:	14410006 */ 	bne	$v0,$at,.L00005d64
/*     5d4c:	3c0b02e6 */ 	lui	$t3,0x2e6
/*     5d50:	3c0902e6 */ 	lui	$t1,0x2e6
/*     5d54:	3529d354 */ 	ori	$t1,$t1,0xd354
/*     5d58:	3c018006 */ 	lui	$at,0x8006
/*     5d5c:	10000004 */ 	beqz	$zero,.L00005d70
/*     5d60:	ac29cf68 */ 	sw	$t1,-0x3098($at)
.L00005d64:
/*     5d64:	356bd354 */ 	ori	$t3,$t3,0xd354
/*     5d68:	3c018006 */ 	lui	$at,0x8006
/*     5d6c:	ac2bcf68 */ 	sw	$t3,-0x3098($at)
.L00005d70:
/*     5d70:	0c012c58 */ 	jal	func0004b160
/*     5d74:	00000000 */ 	sll	$zero,$zero,0x0
/*     5d78:	304d1000 */ 	andi	$t5,$v0,0x1000
/*     5d7c:	11a00003 */ 	beqz	$t5,.L00005d8c
/*     5d80:	240c0001 */ 	addiu	$t4,$zero,0x1
.L00005d84:
/*     5d84:	1000ffff */ 	beqz	$zero,.L00005d84
/*     5d88:	00000000 */ 	sll	$zero,$zero,0x0
.L00005d8c:
/*     5d8c:	3c0ea450 */ 	lui	$t6,0xa450
/*     5d90:	adcc0008 */ 	sw	$t4,0x8($t6)
/*     5d94:	24183fff */ 	addiu	$t8,$zero,0x3fff
/*     5d98:	3c0fa450 */ 	lui	$t7,0xa450
/*     5d9c:	adf80010 */ 	sw	$t8,0x10($t7)
/*     5da0:	2419000f */ 	addiu	$t9,$zero,0xf
/*     5da4:	3c08a450 */ 	lui	$t0,0xa450
/*     5da8:	ad190014 */ 	sw	$t9,0x14($t0)
/*     5dac:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     5db0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     5db4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     5db8:	03e00008 */ 	jr	$ra
/*     5dbc:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func00005dc0
/*     5dc0:	3c028009 */ 	lui	$v0,%hi(var800902a0)
/*     5dc4:	244202a0 */ 	addiu	$v0,$v0,%lo(var800902a0)
/*     5dc8:	24030007 */ 	addiu	$v1,$zero,0x7
/*     5dcc:	a0430004 */ 	sb	$v1,0x4($v0)
/*     5dd0:	3c0ea460 */ 	lui	$t6,0xa460
/*     5dd4:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*     5dd8:	3c18a460 */ 	lui	$t8,0xa460
/*     5ddc:	3c08a460 */ 	lui	$t0,0xa460
/*     5de0:	a04f0005 */ 	sb	$t7,0x5($v0)
/*     5de4:	8f190018 */ 	lw	$t9,0x18($t8)
/*     5de8:	3c0aa460 */ 	lui	$t2,0xa460
/*     5dec:	3c048009 */ 	lui	$a0,%hi(var80090318)
/*     5df0:	a0590008 */ 	sb	$t9,0x8($v0)
/*     5df4:	8d09001c */ 	lw	$t1,0x1c($t0)
/*     5df8:	24840318 */ 	addiu	$a0,$a0,%lo(var80090318)
/*     5dfc:	3c0ca460 */ 	lui	$t4,0xa460
/*     5e00:	a0490006 */ 	sb	$t1,0x6($v0)
/*     5e04:	8d4b0020 */ 	lw	$t3,0x20($t2)
/*     5e08:	a0830004 */ 	sb	$v1,0x4($a0)
/*     5e0c:	a04b0007 */ 	sb	$t3,0x7($v0)
/*     5e10:	8d8d0024 */ 	lw	$t5,0x24($t4)
/*     5e14:	a08d0005 */ 	sb	$t5,0x5($a0)
/*     5e18:	8dcf0028 */ 	lw	$t7,0x28($t6)
/*     5e1c:	a08f0008 */ 	sb	$t7,0x8($a0)
/*     5e20:	8f19002c */ 	lw	$t9,0x2c($t8)
/*     5e24:	a0990006 */ 	sb	$t9,0x6($a0)
/*     5e28:	8d090030 */ 	lw	$t1,0x30($t0)
/*     5e2c:	03e00008 */ 	jr	$ra
/*     5e30:	a0890007 */ 	sb	$t1,0x7($a0)
/*     5e34:	00000000 */ 	sll	$zero,$zero,0x0
/*     5e38:	00000000 */ 	sll	$zero,$zero,0x0
/*     5e3c:	00000000 */ 	sll	$zero,$zero,0x0
);
