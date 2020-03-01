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

GLOBAL_ASM(
glabel func00047d20
/*    47d20:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    47d24:	46006005 */ 	abs.s	$f0,$f12
/*    47d28:	e7a0000c */ 	swc1	$f0,0xc($sp)
/*    47d2c:	3c013400 */ 	lui	$at,0x3400
/*    47d30:	44813000 */ 	mtc1	$at,$f6
/*    47d34:	c7a4000c */ 	lwc1	$f4,0xc($sp)
/*    47d38:	4606203c */ 	c.lt.s	$f4,$f6
/*    47d3c:	00000000 */ 	sll	$zero,$zero,0x0
/*    47d40:	45000005 */ 	bc1f	.L00047d58
/*    47d44:	00000000 */ 	sll	$zero,$zero,0x0
/*    47d48:	3c013f80 */ 	lui	$at,0x3f80
/*    47d4c:	44810000 */ 	mtc1	$at,$f0
/*    47d50:	10000065 */ 	beqz	$zero,.L00047ee8
/*    47d54:	00000000 */ 	sll	$zero,$zero,0x0
.L00047d58:
/*    47d58:	3c017006 */ 	lui	$at,0x7006
/*    47d5c:	c42a9e10 */ 	lwc1	$f10,-0x61f0($at)
/*    47d60:	c7a8000c */ 	lwc1	$f8,0xc($sp)
/*    47d64:	460a4403 */ 	div.s	$f16,$f8,$f10
/*    47d68:	4600848d */ 	trunc.w.s	$f18,$f16
/*    47d6c:	440f9000 */ 	mfc1	$t7,$f18
/*    47d70:	00000000 */ 	sll	$zero,$zero,0x0
/*    47d74:	afaf0004 */ 	sw	$t7,0x4($sp)
/*    47d78:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    47d7c:	2b010401 */ 	slti	$at,$t8,0x401
/*    47d80:	1420000f */ 	bnez	$at,.L00047dc0
/*    47d84:	00000000 */ 	sll	$zero,$zero,0x0
/*    47d88:	44802000 */ 	mtc1	$zero,$f4
/*    47d8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    47d90:	460c203e */ 	c.le.s	$f4,$f12
/*    47d94:	00000000 */ 	sll	$zero,$zero,0x0
/*    47d98:	45000006 */ 	bc1f	.L00047db4
/*    47d9c:	00000000 */ 	sll	$zero,$zero,0x0
/*    47da0:	3c017006 */ 	lui	$at,0x7006
/*    47da4:	10000050 */ 	beqz	$zero,.L00047ee8
/*    47da8:	c4209e14 */ 	lwc1	$f0,-0x61ec($at)
/*    47dac:	10000004 */ 	beqz	$zero,.L00047dc0
/*    47db0:	00000000 */ 	sll	$zero,$zero,0x0
.L00047db4:
/*    47db4:	44800000 */ 	mtc1	$zero,$f0
/*    47db8:	1000004b */ 	beqz	$zero,.L00047ee8
/*    47dbc:	00000000 */ 	sll	$zero,$zero,0x0
.L00047dc0:
/*    47dc0:	8fb90004 */ 	lw	$t9,0x4($sp)
/*    47dc4:	3c017006 */ 	lui	$at,0x7006
/*    47dc8:	c42a9e18 */ 	lwc1	$f10,-0x61e8($at)
/*    47dcc:	44993000 */ 	mtc1	$t9,$f6
/*    47dd0:	c7b2000c */ 	lwc1	$f18,0xc($sp)
/*    47dd4:	46803220 */ 	cvt.s.w	$f8,$f6
/*    47dd8:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    47ddc:	46109101 */ 	sub.s	$f4,$f18,$f16
/*    47de0:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    47de4:	24080001 */ 	addiu	$t0,$zero,0x1
/*    47de8:	afa80008 */ 	sw	$t0,0x8($sp)
/*    47dec:	3c013f80 */ 	lui	$at,0x3f80
/*    47df0:	44813000 */ 	mtc1	$at,$f6
/*    47df4:	00000000 */ 	sll	$zero,$zero,0x0
/*    47df8:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*    47dfc:	3c013f80 */ 	lui	$at,0x3f80
/*    47e00:	44814000 */ 	mtc1	$at,$f8
/*    47e04:	00000000 */ 	sll	$zero,$zero,0x0
/*    47e08:	e7a80018 */ 	swc1	$f8,0x18($sp)
.L00047e0c:
/*    47e0c:	c7aa001c */ 	lwc1	$f10,0x1c($sp)
/*    47e10:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*    47e14:	8fa90008 */ 	lw	$t1,0x8($sp)
/*    47e18:	c7b20010 */ 	lwc1	$f18,0x10($sp)
/*    47e1c:	c7a80018 */ 	lwc1	$f8,0x18($sp)
/*    47e20:	44898000 */ 	mtc1	$t1,$f16
/*    47e24:	00000000 */ 	sll	$zero,$zero,0x0
/*    47e28:	46808120 */ 	cvt.s.w	$f4,$f16
/*    47e2c:	46049183 */ 	div.s	$f6,$f18,$f4
/*    47e30:	46064282 */ 	mul.s	$f10,$f8,$f6
/*    47e34:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*    47e38:	c7b0001c */ 	lwc1	$f16,0x1c($sp)
/*    47e3c:	c7b20018 */ 	lwc1	$f18,0x18($sp)
/*    47e40:	46128100 */ 	add.s	$f4,$f16,$f18
/*    47e44:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*    47e48:	8faa0008 */ 	lw	$t2,0x8($sp)
/*    47e4c:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    47e50:	afab0008 */ 	sw	$t3,0x8($sp)
/*    47e54:	c7a8001c */ 	lwc1	$f8,0x1c($sp)
/*    47e58:	c7a60014 */ 	lwc1	$f6,0x14($sp)
/*    47e5c:	46064032 */ 	c.eq.s	$f8,$f6
/*    47e60:	00000000 */ 	sll	$zero,$zero,0x0
/*    47e64:	4500ffe9 */ 	bc1f	.L00047e0c
/*    47e68:	00000000 */ 	sll	$zero,$zero,0x0
/*    47e6c:	8fac0004 */ 	lw	$t4,0x4($sp)
/*    47e70:	1180000c */ 	beqz	$t4,.L00047ea4
/*    47e74:	00000000 */ 	sll	$zero,$zero,0x0
.L00047e78:
/*    47e78:	3c014000 */ 	lui	$at,0x4000
/*    47e7c:	44818000 */ 	mtc1	$at,$f16
/*    47e80:	c7aa001c */ 	lwc1	$f10,0x1c($sp)
/*    47e84:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    47e88:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*    47e8c:	8fad0004 */ 	lw	$t5,0x4($sp)
/*    47e90:	25aeffff */ 	addiu	$t6,$t5,-1
/*    47e94:	afae0004 */ 	sw	$t6,0x4($sp)
/*    47e98:	8faf0004 */ 	lw	$t7,0x4($sp)
/*    47e9c:	15e0fff6 */ 	bnez	$t7,.L00047e78
/*    47ea0:	00000000 */ 	sll	$zero,$zero,0x0
.L00047ea4:
/*    47ea4:	44802000 */ 	mtc1	$zero,$f4
/*    47ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*    47eac:	460c203e */ 	c.le.s	$f4,$f12
/*    47eb0:	00000000 */ 	sll	$zero,$zero,0x0
/*    47eb4:	45000005 */ 	bc1f	.L00047ecc
/*    47eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*    47ebc:	1000000a */ 	beqz	$zero,.L00047ee8
/*    47ec0:	c7a0001c */ 	lwc1	$f0,0x1c($sp)
/*    47ec4:	10000006 */ 	beqz	$zero,.L00047ee0
/*    47ec8:	00000000 */ 	sll	$zero,$zero,0x0
.L00047ecc:
/*    47ecc:	3c013f80 */ 	lui	$at,0x3f80
/*    47ed0:	44814000 */ 	mtc1	$at,$f8
/*    47ed4:	c7a6001c */ 	lwc1	$f6,0x1c($sp)
/*    47ed8:	10000003 */ 	beqz	$zero,.L00047ee8
/*    47edc:	46064003 */ 	div.s	$f0,$f8,$f6
.L00047ee0:
/*    47ee0:	10000001 */ 	beqz	$zero,.L00047ee8
/*    47ee4:	00000000 */ 	sll	$zero,$zero,0x0
.L00047ee8:
/*    47ee8:	03e00008 */ 	jr	$ra
/*    47eec:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func00047ef0
/*    47ef0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    47ef4:	44802000 */ 	mtc1	$zero,$f4
/*    47ef8:	00000000 */ 	sll	$zero,$zero,0x0
/*    47efc:	4604603c */ 	c.lt.s	$f12,$f4
/*    47f00:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f04:	45000004 */ 	bc1f	.L00047f18
/*    47f08:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f0c:	44800000 */ 	mtc1	$zero,$f0
/*    47f10:	10000069 */ 	beqz	$zero,.L000480b8
/*    47f14:	00000000 */ 	sll	$zero,$zero,0x0
.L00047f18:
/*    47f18:	44803000 */ 	mtc1	$zero,$f6
/*    47f1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f20:	46066032 */ 	c.eq.s	$f12,$f6
/*    47f24:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f28:	45000004 */ 	bc1f	.L00047f3c
/*    47f2c:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f30:	44800000 */ 	mtc1	$zero,$f0
/*    47f34:	10000060 */ 	beqz	$zero,.L000480b8
/*    47f38:	00000000 */ 	sll	$zero,$zero,0x0
.L00047f3c:
/*    47f3c:	44804000 */ 	mtc1	$zero,$f8
/*    47f40:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f44:	e7a80008 */ 	swc1	$f8,0x8($sp)
/*    47f48:	3c014000 */ 	lui	$at,0x4000
/*    47f4c:	44815000 */ 	mtc1	$at,$f10
/*    47f50:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f54:	460c503e */ 	c.le.s	$f10,$f12
/*    47f58:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f5c:	45000011 */ 	bc1f	.L00047fa4
/*    47f60:	00000000 */ 	sll	$zero,$zero,0x0
.L00047f64:
/*    47f64:	3c014000 */ 	lui	$at,0x4000
/*    47f68:	44818000 */ 	mtc1	$at,$f16
/*    47f6c:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f70:	46106303 */ 	div.s	$f12,$f12,$f16
/*    47f74:	3c017006 */ 	lui	$at,0x7006
/*    47f78:	c4249e20 */ 	lwc1	$f4,-0x61e0($at)
/*    47f7c:	c7b20008 */ 	lwc1	$f18,0x8($sp)
/*    47f80:	46049180 */ 	add.s	$f6,$f18,$f4
/*    47f84:	e7a60008 */ 	swc1	$f6,0x8($sp)
/*    47f88:	3c014000 */ 	lui	$at,0x4000
/*    47f8c:	44814000 */ 	mtc1	$at,$f8
/*    47f90:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f94:	460c403e */ 	c.le.s	$f8,$f12
/*    47f98:	00000000 */ 	sll	$zero,$zero,0x0
/*    47f9c:	4501fff1 */ 	bc1t	.L00047f64
/*    47fa0:	00000000 */ 	sll	$zero,$zero,0x0
.L00047fa4:
/*    47fa4:	3c013f80 */ 	lui	$at,0x3f80
/*    47fa8:	44815000 */ 	mtc1	$at,$f10
/*    47fac:	00000000 */ 	sll	$zero,$zero,0x0
/*    47fb0:	460a603c */ 	c.lt.s	$f12,$f10
/*    47fb4:	00000000 */ 	sll	$zero,$zero,0x0
/*    47fb8:	45000012 */ 	bc1f	.L00048004
/*    47fbc:	00000000 */ 	sll	$zero,$zero,0x0
.L00047fc0:
/*    47fc0:	3c014000 */ 	lui	$at,0x4000
/*    47fc4:	44818000 */ 	mtc1	$at,$f16
/*    47fc8:	00000000 */ 	sll	$zero,$zero,0x0
/*    47fcc:	46106302 */ 	mul.s	$f12,$f12,$f16
/*    47fd0:	00000000 */ 	sll	$zero,$zero,0x0
/*    47fd4:	3c017006 */ 	lui	$at,0x7006
/*    47fd8:	c4249e24 */ 	lwc1	$f4,-0x61dc($at)
/*    47fdc:	c7b20008 */ 	lwc1	$f18,0x8($sp)
/*    47fe0:	46049181 */ 	sub.s	$f6,$f18,$f4
/*    47fe4:	e7a60008 */ 	swc1	$f6,0x8($sp)
/*    47fe8:	3c013f80 */ 	lui	$at,0x3f80
/*    47fec:	44814000 */ 	mtc1	$at,$f8
/*    47ff0:	00000000 */ 	sll	$zero,$zero,0x0
/*    47ff4:	4608603c */ 	c.lt.s	$f12,$f8
/*    47ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*    47ffc:	4501fff0 */ 	bc1t	.L00047fc0
/*    48000:	00000000 */ 	sll	$zero,$zero,0x0
.L00048004:
/*    48004:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    48008:	afae0014 */ 	sw	$t6,0x14($sp)
/*    4800c:	3c013f80 */ 	lui	$at,0x3f80
/*    48010:	44815000 */ 	mtc1	$at,$f10
/*    48014:	44819000 */ 	mtc1	$at,$f18
/*    48018:	460a6401 */ 	sub.s	$f16,$f12,$f10
/*    4801c:	46126100 */ 	add.s	$f4,$f12,$f18
/*    48020:	46048183 */ 	div.s	$f6,$f16,$f4
/*    48024:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*    48028:	3c014000 */ 	lui	$at,0x4000
/*    4802c:	44814000 */ 	mtc1	$at,$f8
/*    48030:	c7aa0010 */ 	lwc1	$f10,0x10($sp)
/*    48034:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*    48038:	e7b2000c */ 	swc1	$f18,0xc($sp)
/*    4803c:	c7b00010 */ 	lwc1	$f16,0x10($sp)
/*    48040:	46108102 */ 	mul.s	$f4,$f16,$f16
/*    48044:	e7a40010 */ 	swc1	$f4,0x10($sp)
.L00048048:
/*    48048:	c7a60008 */ 	lwc1	$f6,0x8($sp)
/*    4804c:	e7a60004 */ 	swc1	$f6,0x4($sp)
/*    48050:	8faf0014 */ 	lw	$t7,0x14($sp)
/*    48054:	c7a8000c */ 	lwc1	$f8,0xc($sp)
/*    48058:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*    4805c:	448f5000 */ 	mtc1	$t7,$f10
/*    48060:	00000000 */ 	sll	$zero,$zero,0x0
/*    48064:	468054a0 */ 	cvt.s.w	$f18,$f10
/*    48068:	46124403 */ 	div.s	$f16,$f8,$f18
/*    4806c:	46102180 */ 	add.s	$f6,$f4,$f16
/*    48070:	e7a60008 */ 	swc1	$f6,0x8($sp)
/*    48074:	c7aa000c */ 	lwc1	$f10,0xc($sp)
/*    48078:	c7a80010 */ 	lwc1	$f8,0x10($sp)
/*    4807c:	46085482 */ 	mul.s	$f18,$f10,$f8
/*    48080:	e7b2000c */ 	swc1	$f18,0xc($sp)
/*    48084:	8fb80014 */ 	lw	$t8,0x14($sp)
/*    48088:	27190002 */ 	addiu	$t9,$t8,0x2
/*    4808c:	afb90014 */ 	sw	$t9,0x14($sp)
/*    48090:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*    48094:	c7b00004 */ 	lwc1	$f16,0x4($sp)
/*    48098:	46102032 */ 	c.eq.s	$f4,$f16
/*    4809c:	00000000 */ 	sll	$zero,$zero,0x0
/*    480a0:	4500ffe9 */ 	bc1f	.L00048048
/*    480a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    480a8:	10000003 */ 	beqz	$zero,.L000480b8
/*    480ac:	c7a00008 */ 	lwc1	$f0,0x8($sp)
/*    480b0:	10000001 */ 	beqz	$zero,.L000480b8
/*    480b4:	00000000 */ 	sll	$zero,$zero,0x0
.L000480b8:
/*    480b8:	03e00008 */ 	jr	$ra
/*    480bc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    480c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    480c4:	00000000 */ 	sll	$zero,$zero,0x0
/*    480c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    480cc:	00000000 */ 	sll	$zero,$zero,0x0
/*    480d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    480d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    480d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    480dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    480e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    480e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    480e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    480ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    480f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    480f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    480f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    480fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    48100:	00000000 */ 	sll	$zero,$zero,0x0
/*    48104:	00000000 */ 	sll	$zero,$zero,0x0
/*    48108:	00000000 */ 	sll	$zero,$zero,0x0
/*    4810c:	00000000 */ 	sll	$zero,$zero,0x0
/*    48110:	00000000 */ 	sll	$zero,$zero,0x0
/*    48114:	00000000 */ 	sll	$zero,$zero,0x0
/*    48118:	00000000 */ 	sll	$zero,$zero,0x0
/*    4811c:	00000000 */ 	sll	$zero,$zero,0x0
);