#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

u32 var8005ef10 = 0x47800000;
u32 var8005ef14 = 0x47800000;

GLOBAL_ASM(
glabel func000159b0
/*    159b0:	3c013f80 */ 	lui	$at,0x3f80
/*    159b4:	44810000 */ 	mtc1	$at,$f0
/*    159b8:	ac800004 */ 	sw	$zero,0x4($a0)
/*    159bc:	ac800008 */ 	sw	$zero,0x8($a0)
/*    159c0:	ac80000c */ 	sw	$zero,0xc($a0)
/*    159c4:	ac800010 */ 	sw	$zero,0x10($a0)
/*    159c8:	ac800018 */ 	sw	$zero,0x18($a0)
/*    159cc:	ac80001c */ 	sw	$zero,0x1c($a0)
/*    159d0:	ac800020 */ 	sw	$zero,0x20($a0)
/*    159d4:	ac800024 */ 	sw	$zero,0x24($a0)
/*    159d8:	ac80002c */ 	sw	$zero,0x2c($a0)
/*    159dc:	ac800030 */ 	sw	$zero,0x30($a0)
/*    159e0:	ac800034 */ 	sw	$zero,0x34($a0)
/*    159e4:	ac800038 */ 	sw	$zero,0x38($a0)
/*    159e8:	e4800000 */ 	swc1	$f0,0x0($a0)
/*    159ec:	e4800014 */ 	swc1	$f0,0x14($a0)
/*    159f0:	e4800028 */ 	swc1	$f0,0x28($a0)
/*    159f4:	03e00008 */ 	jr	$ra
/*    159f8:	e480003c */ 	swc1	$f0,0x3c($a0)
);

GLOBAL_ASM(
glabel func000159fc
/*    159fc:	00a03020 */ 	add	$a2,$a1,$zero
glabel func00015a00
/*    15a00:	4409a000 */ 	mfc1	$t1,$f20
/*    15a04:	440aa800 */ 	mfc1	$t2,$f21
/*    15a08:	440bb000 */ 	mfc1	$t3,$f22
/*    15a0c:	440cb800 */ 	mfc1	$t4,$f23
/*    15a10:	440dc000 */ 	mfc1	$t5,$f24
/*    15a14:	24080004 */ 	addiu	$t0,$zero,0x4
/*    15a18:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*    15a1c:	c4a10004 */ 	lwc1	$f1,0x4($a1)
/*    15a20:	c4a20008 */ 	lwc1	$f2,0x8($a1)
/*    15a24:	c4a3000c */ 	lwc1	$f3,0xc($a1)
/*    15a28:	c4a40010 */ 	lwc1	$f4,0x10($a1)
/*    15a2c:	c4a50014 */ 	lwc1	$f5,0x14($a1)
/*    15a30:	c4a60018 */ 	lwc1	$f6,0x18($a1)
/*    15a34:	c4a7001c */ 	lwc1	$f7,0x1c($a1)
/*    15a38:	c4a80020 */ 	lwc1	$f8,0x20($a1)
/*    15a3c:	c4a90024 */ 	lwc1	$f9,0x24($a1)
/*    15a40:	c4aa0028 */ 	lwc1	$f10,0x28($a1)
/*    15a44:	c4ab002c */ 	lwc1	$f11,0x2c($a1)
/*    15a48:	c4ac0030 */ 	lwc1	$f12,0x30($a1)
/*    15a4c:	c4ad0034 */ 	lwc1	$f13,0x34($a1)
/*    15a50:	c4ae0038 */ 	lwc1	$f14,0x38($a1)
/*    15a54:	c4af003c */ 	lwc1	$f15,0x3c($a1)
.L00015a58:
/*    15a58:	c4900000 */ 	lwc1	$f16,0x0($a0)
/*    15a5c:	46008502 */ 	mul.s	$f20,$f16,$f0
/*    15a60:	c4910010 */ 	lwc1	$f17,0x10($a0)
/*    15a64:	c4920020 */ 	lwc1	$f18,0x20($a0)
/*    15a68:	46018d42 */ 	mul.s	$f21,$f17,$f1
/*    15a6c:	c4930030 */ 	lwc1	$f19,0x30($a0)
/*    15a70:	46029582 */ 	mul.s	$f22,$f18,$f2
/*    15a74:	4615a500 */ 	add.s	$f20,$f20,$f21
/*    15a78:	46039d42 */ 	mul.s	$f21,$f19,$f3
/*    15a7c:	4616a500 */ 	add.s	$f20,$f20,$f22
/*    15a80:	46048582 */ 	mul.s	$f22,$f16,$f4
/*    15a84:	4615a500 */ 	add.s	$f20,$f20,$f21
/*    15a88:	46058d42 */ 	mul.s	$f21,$f17,$f5
/*    15a8c:	e4d40000 */ 	swc1	$f20,0x0($a2)
/*    15a90:	46069502 */ 	mul.s	$f20,$f18,$f6
/*    15a94:	4615b580 */ 	add.s	$f22,$f22,$f21
/*    15a98:	46079d42 */ 	mul.s	$f21,$f19,$f7
/*    15a9c:	24c60004 */ 	addiu	$a2,$a2,0x4
/*    15aa0:	460885c2 */ 	mul.s	$f23,$f16,$f8
/*    15aa4:	4614b580 */ 	add.s	$f22,$f22,$f20
/*    15aa8:	46098d02 */ 	mul.s	$f20,$f17,$f9
/*    15aac:	4615b580 */ 	add.s	$f22,$f22,$f21
/*    15ab0:	460a9542 */ 	mul.s	$f21,$f18,$f10
/*    15ab4:	e4d6000c */ 	swc1	$f22,0xc($a2)
/*    15ab8:	460b9e02 */ 	mul.s	$f24,$f19,$f11
/*    15abc:	4614bdc0 */ 	add.s	$f23,$f23,$f20
/*    15ac0:	460c8582 */ 	mul.s	$f22,$f16,$f12
/*    15ac4:	4615bdc0 */ 	add.s	$f23,$f23,$f21
/*    15ac8:	460d8d42 */ 	mul.s	$f21,$f17,$f13
/*    15acc:	4618bdc0 */ 	add.s	$f23,$f23,$f24
/*    15ad0:	460e9602 */ 	mul.s	$f24,$f18,$f14
/*    15ad4:	e4d7001c */ 	swc1	$f23,0x1c($a2)
/*    15ad8:	460f9dc2 */ 	mul.s	$f23,$f19,$f15
/*    15adc:	4615b580 */ 	add.s	$f22,$f22,$f21
/*    15ae0:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15ae4:	4618b580 */ 	add.s	$f22,$f22,$f24
/*    15ae8:	24840004 */ 	addiu	$a0,$a0,0x4
/*    15aec:	4617b580 */ 	add.s	$f22,$f22,$f23
/*    15af0:	1500ffd9 */ 	bnez	$t0,.L00015a58
/*    15af4:	e4d6002c */ 	swc1	$f22,0x2c($a2)
/*    15af8:	4489a000 */ 	mtc1	$t1,$f20
/*    15afc:	448aa800 */ 	mtc1	$t2,$f21
/*    15b00:	448bb000 */ 	mtc1	$t3,$f22
/*    15b04:	448cb800 */ 	mtc1	$t4,$f23
/*    15b08:	03e00008 */ 	jr	$ra
/*    15b0c:	448dc000 */ 	mtc1	$t5,$f24
);

GLOBAL_ASM(
glabel func00015b10
/*    15b10:	00a03020 */ 	add	$a2,$a1,$zero
glabel func00015b14
/*    15b14:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*    15b18:	c4a10004 */ 	lwc1	$f1,0x4($a1)
/*    15b1c:	c4a20008 */ 	lwc1	$f2,0x8($a1)
/*    15b20:	24080003 */ 	addiu	$t0,$zero,0x3
/*    15b24:	c4830000 */ 	lwc1	$f3,0x0($a0)
.L00015b28:
/*    15b28:	c4840010 */ 	lwc1	$f4,0x10($a0)
/*    15b2c:	46001982 */ 	mul.s	$f6,$f3,$f0
/*    15b30:	c4850020 */ 	lwc1	$f5,0x20($a0)
/*    15b34:	460121c2 */ 	mul.s	$f7,$f4,$f1
/*    15b38:	24840004 */ 	addiu	$a0,$a0,0x4
/*    15b3c:	46073240 */ 	add.s	$f9,$f6,$f7
/*    15b40:	46022a02 */ 	mul.s	$f8,$f5,$f2
/*    15b44:	24c60004 */ 	addiu	$a2,$a2,0x4
/*    15b48:	46084c00 */ 	add.s	$f16,$f9,$f8
/*    15b4c:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15b50:	e4d0fffc */ 	swc1	$f16,-0x4($a2)
/*    15b54:	1500fff4 */ 	bnez	$t0,.L00015b28
/*    15b58:	c4830000 */ 	lwc1	$f3,0x0($a0)
/*    15b5c:	03e00008 */ 	jr	$ra
/*    15b60:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00015b64
/*    15b64:	00a03020 */ 	add	$a2,$a1,$zero
glabel func00015b68
/*    15b68:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*    15b6c:	c4a10004 */ 	lwc1	$f1,0x4($a1)
/*    15b70:	c4a20008 */ 	lwc1	$f2,0x8($a1)
/*    15b74:	24080003 */ 	addiu	$t0,$zero,0x3
/*    15b78:	c4830000 */ 	lwc1	$f3,0x0($a0)
.L00015b7c:
/*    15b7c:	c4840010 */ 	lwc1	$f4,0x10($a0)
/*    15b80:	46001982 */ 	mul.s	$f6,$f3,$f0
/*    15b84:	c4850020 */ 	lwc1	$f5,0x20($a0)
/*    15b88:	460121c2 */ 	mul.s	$f7,$f4,$f1
/*    15b8c:	24840004 */ 	addiu	$a0,$a0,0x4
/*    15b90:	46073240 */ 	add.s	$f9,$f6,$f7
/*    15b94:	46022a02 */ 	mul.s	$f8,$f5,$f2
/*    15b98:	24c60004 */ 	addiu	$a2,$a2,0x4
/*    15b9c:	46084c00 */ 	add.s	$f16,$f9,$f8
/*    15ba0:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15ba4:	e4d0fffc */ 	swc1	$f16,-0x4($a2)
/*    15ba8:	1500fff4 */ 	bnez	$t0,.L00015b7c
/*    15bac:	c4830000 */ 	lwc1	$f3,0x0($a0)
/*    15bb0:	c4c0fff4 */ 	lwc1	$f0,-0xc($a2)
/*    15bb4:	c4c1fff8 */ 	lwc1	$f1,-0x8($a2)
/*    15bb8:	c4830024 */ 	lwc1	$f3,0x24($a0)
/*    15bbc:	c4840028 */ 	lwc1	$f4,0x28($a0)
/*    15bc0:	c485002c */ 	lwc1	$f5,0x2c($a0)
/*    15bc4:	46030000 */ 	add.s	$f0,$f0,$f3
/*    15bc8:	46040840 */ 	add.s	$f1,$f1,$f4
/*    15bcc:	46058080 */ 	add.s	$f2,$f16,$f5
/*    15bd0:	e4c0fff4 */ 	swc1	$f0,-0xc($a2)
/*    15bd4:	e4c1fff8 */ 	swc1	$f1,-0x8($a2)
/*    15bd8:	03e00008 */ 	jr	$ra
/*    15bdc:	e4c2fffc */ 	swc1	$f2,-0x4($a2)
);

GLOBAL_ASM(
glabel func00015be0
/*    15be0:	00a03020 */ 	add	$a2,$a1,$zero
glabel func00015be4
/*    15be4:	4409a000 */ 	mfc1	$t1,$f20
/*    15be8:	440aa800 */ 	mfc1	$t2,$f21
/*    15bec:	440bb000 */ 	mfc1	$t3,$f22
/*    15bf0:	440cb800 */ 	mfc1	$t4,$f23
/*    15bf4:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*    15bf8:	c4a10004 */ 	lwc1	$f1,0x4($a1)
/*    15bfc:	c4a20008 */ 	lwc1	$f2,0x8($a1)
/*    15c00:	c4a30010 */ 	lwc1	$f3,0x10($a1)
/*    15c04:	c4a40014 */ 	lwc1	$f4,0x14($a1)
/*    15c08:	c4a50018 */ 	lwc1	$f5,0x18($a1)
/*    15c0c:	c4a60020 */ 	lwc1	$f6,0x20($a1)
/*    15c10:	c4a70024 */ 	lwc1	$f7,0x24($a1)
/*    15c14:	c4a80028 */ 	lwc1	$f8,0x28($a1)
/*    15c18:	c4a90030 */ 	lwc1	$f9,0x30($a1)
/*    15c1c:	c4aa0034 */ 	lwc1	$f10,0x34($a1)
/*    15c20:	c4ab0038 */ 	lwc1	$f11,0x38($a1)
/*    15c24:	24080003 */ 	addiu	$t0,$zero,0x3
.L00015c28:
/*    15c28:	c48c0000 */ 	lwc1	$f12,0x0($a0)
/*    15c2c:	24840004 */ 	addiu	$a0,$a0,0x4
/*    15c30:	46006402 */ 	mul.s	$f16,$f12,$f0
/*    15c34:	c48d000c */ 	lwc1	$f13,0xc($a0)
/*    15c38:	c48e001c */ 	lwc1	$f14,0x1c($a0)
/*    15c3c:	46016c42 */ 	mul.s	$f17,$f13,$f1
/*    15c40:	c48f002c */ 	lwc1	$f15,0x2c($a0)
/*    15c44:	46027482 */ 	mul.s	$f18,$f14,$f2
/*    15c48:	461184c0 */ 	add.s	$f19,$f16,$f17
/*    15c4c:	46036502 */ 	mul.s	$f20,$f12,$f3
/*    15c50:	46129cc0 */ 	add.s	$f19,$f19,$f18
/*    15c54:	46046d42 */ 	mul.s	$f21,$f13,$f4
/*    15c58:	e4d30000 */ 	swc1	$f19,0x0($a2)
/*    15c5c:	46057582 */ 	mul.s	$f22,$f14,$f5
/*    15c60:	4615a5c0 */ 	add.s	$f23,$f20,$f21
/*    15c64:	46066402 */ 	mul.s	$f16,$f12,$f6
/*    15c68:	4616bdc0 */ 	add.s	$f23,$f23,$f22
/*    15c6c:	46076c42 */ 	mul.s	$f17,$f13,$f7
/*    15c70:	e4d70010 */ 	swc1	$f23,0x10($a2)
/*    15c74:	46087482 */ 	mul.s	$f18,$f14,$f8
/*    15c78:	461184c0 */ 	add.s	$f19,$f16,$f17
/*    15c7c:	46096502 */ 	mul.s	$f20,$f12,$f9
/*    15c80:	46129cc0 */ 	add.s	$f19,$f19,$f18
/*    15c84:	460a6d42 */ 	mul.s	$f21,$f13,$f10
/*    15c88:	e4d30020 */ 	swc1	$f19,0x20($a2)
/*    15c8c:	460b7582 */ 	mul.s	$f22,$f14,$f11
/*    15c90:	4615a500 */ 	add.s	$f20,$f20,$f21
/*    15c94:	460fb580 */ 	add.s	$f22,$f22,$f15
/*    15c98:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15c9c:	4616a580 */ 	add.s	$f22,$f20,$f22
/*    15ca0:	24c60004 */ 	addiu	$a2,$a2,0x4
/*    15ca4:	1500ffe0 */ 	bnez	$t0,.L00015c28
/*    15ca8:	e4d6002c */ 	swc1	$f22,0x2c($a2)
/*    15cac:	3c013f80 */ 	lui	$at,0x3f80
/*    15cb0:	44810000 */ 	mtc1	$at,$f0
/*    15cb4:	acc00000 */ 	sw	$zero,0x0($a2)
/*    15cb8:	acc00010 */ 	sw	$zero,0x10($a2)
/*    15cbc:	acc00020 */ 	sw	$zero,0x20($a2)
/*    15cc0:	e4c00030 */ 	swc1	$f0,0x30($a2)
/*    15cc4:	4489a000 */ 	mtc1	$t1,$f20
/*    15cc8:	448aa800 */ 	mtc1	$t2,$f21
/*    15ccc:	448bb000 */ 	mtc1	$t3,$f22
/*    15cd0:	03e00008 */ 	jr	$ra
/*    15cd4:	448cb800 */ 	mtc1	$t4,$f23
);

GLOBAL_ASM(
glabel func00015cd8
/*    15cd8:	24080002 */ 	addiu	$t0,$zero,0x2
.L00015cdc:
/*    15cdc:	8c890000 */ 	lw	$t1,0x0($a0)
/*    15ce0:	8c8a0004 */ 	lw	$t2,0x4($a0)
/*    15ce4:	8c8b0008 */ 	lw	$t3,0x8($a0)
/*    15ce8:	8c8c000c */ 	lw	$t4,0xc($a0)
/*    15cec:	aca90000 */ 	sw	$t1,0x0($a1)
/*    15cf0:	acaa0004 */ 	sw	$t2,0x4($a1)
/*    15cf4:	acab0008 */ 	sw	$t3,0x8($a1)
/*    15cf8:	acac000c */ 	sw	$t4,0xc($a1)
/*    15cfc:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15d00:	24840010 */ 	addiu	$a0,$a0,0x10
/*    15d04:	1500fff5 */ 	bnez	$t0,.L00015cdc
/*    15d08:	24a50010 */ 	addiu	$a1,$a1,0x10
/*    15d0c:	8c880000 */ 	lw	$t0,0x0($a0)
/*    15d10:	03e00008 */ 	jr	$ra
/*    15d14:	aca80000 */ 	sw	$t0,0x0($a1)
);

GLOBAL_ASM(
glabel func00015d18
/*    15d18:	24080004 */ 	addiu	$t0,$zero,0x4
.L00015d1c:
/*    15d1c:	8c890000 */ 	lw	$t1,0x0($a0)
/*    15d20:	8c8a0004 */ 	lw	$t2,0x4($a0)
/*    15d24:	8c8b0008 */ 	lw	$t3,0x8($a0)
/*    15d28:	8c8c000c */ 	lw	$t4,0xc($a0)
/*    15d2c:	aca90000 */ 	sw	$t1,0x0($a1)
/*    15d30:	acaa0004 */ 	sw	$t2,0x4($a1)
/*    15d34:	acab0008 */ 	sw	$t3,0x8($a1)
/*    15d38:	acac000c */ 	sw	$t4,0xc($a1)
/*    15d3c:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15d40:	24840010 */ 	addiu	$a0,$a0,0x10
/*    15d44:	1500fff5 */ 	bnez	$t0,.L00015d1c
/*    15d48:	24a50010 */ 	addiu	$a1,$a1,0x10
/*    15d4c:	03e00008 */ 	jr	$ra
/*    15d50:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00015d54
/*    15d54:	24080003 */ 	addiu	$t0,$zero,0x3
/*    15d58:	3c013f80 */ 	lui	$at,0x3f80
/*    15d5c:	44812000 */ 	mtc1	$at,$f4
.L00015d60:
/*    15d60:	8c890000 */ 	lw	$t1,0x0($a0)
/*    15d64:	8c8a0004 */ 	lw	$t2,0x4($a0)
/*    15d68:	8c8b0008 */ 	lw	$t3,0x8($a0)
/*    15d6c:	aca90000 */ 	sw	$t1,0x0($a1)
/*    15d70:	acaa0004 */ 	sw	$t2,0x4($a1)
/*    15d74:	acab0008 */ 	sw	$t3,0x8($a1)
/*    15d78:	aca0000c */ 	sw	$zero,0xc($a1)
/*    15d7c:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15d80:	24a50010 */ 	addiu	$a1,$a1,0x10
/*    15d84:	1500fff6 */ 	bnez	$t0,.L00015d60
/*    15d88:	2484000c */ 	addiu	$a0,$a0,0xc
/*    15d8c:	aca00000 */ 	sw	$zero,0x0($a1)
/*    15d90:	aca00004 */ 	sw	$zero,0x4($a1)
/*    15d94:	aca00008 */ 	sw	$zero,0x8($a1)
/*    15d98:	03e00008 */ 	jr	$ra
/*    15d9c:	e4a4000c */ 	swc1	$f4,0xc($a1)
);

GLOBAL_ASM(
glabel func00015da0
/*    15da0:	24080003 */ 	addiu	$t0,$zero,0x3
.L00015da4:
/*    15da4:	8c890000 */ 	lw	$t1,0x0($a0)
/*    15da8:	8c8a0004 */ 	lw	$t2,0x4($a0)
/*    15dac:	8c8b0008 */ 	lw	$t3,0x8($a0)
/*    15db0:	aca90000 */ 	sw	$t1,0x0($a1)
/*    15db4:	acaa0004 */ 	sw	$t2,0x4($a1)
/*    15db8:	acab0008 */ 	sw	$t3,0x8($a1)
/*    15dbc:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15dc0:	24840010 */ 	addiu	$a0,$a0,0x10
/*    15dc4:	1500fff7 */ 	bnez	$t0,.L00015da4
/*    15dc8:	24a5000c */ 	addiu	$a1,$a1,0xc
/*    15dcc:	03e00008 */ 	jr	$ra
/*    15dd0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00015dd4
/*    15dd4:	8c880000 */ 	lw	$t0,0x0($a0)
/*    15dd8:	8c890004 */ 	lw	$t1,0x4($a0)
/*    15ddc:	8c8a0008 */ 	lw	$t2,0x8($a0)
/*    15de0:	aca80030 */ 	sw	$t0,0x30($a1)
/*    15de4:	aca90034 */ 	sw	$t1,0x34($a1)
/*    15de8:	03e00008 */ 	jr	$ra
/*    15dec:	acaa0038 */ 	sw	$t2,0x38($a1)
);

GLOBAL_ASM(
glabel func00015df0
/*    15df0:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*    15df4:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*    15df8:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*    15dfc:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*    15e00:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*    15e04:	c4a6000c */ 	lwc1	$f6,0xc($a1)
/*    15e08:	460c5282 */ 	mul.s	$f10,$f10,$f12
/*    15e0c:	e4a80000 */ 	swc1	$f8,0x0($a1)
/*    15e10:	460c3182 */ 	mul.s	$f6,$f6,$f12
/*    15e14:	e4a40004 */ 	swc1	$f4,0x4($a1)
/*    15e18:	e4aa0008 */ 	swc1	$f10,0x8($a1)
/*    15e1c:	03e00008 */ 	jr	$ra
/*    15e20:	e4a6000c */ 	swc1	$f6,0xc($a1)
);

GLOBAL_ASM(
glabel func00015e24
/*    15e24:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*    15e28:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*    15e2c:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*    15e30:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*    15e34:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*    15e38:	e4a80000 */ 	swc1	$f8,0x0($a1)
/*    15e3c:	460c5282 */ 	mul.s	$f10,$f10,$f12
/*    15e40:	e4a40004 */ 	swc1	$f4,0x4($a1)
/*    15e44:	03e00008 */ 	jr	$ra
/*    15e48:	e4aa0008 */ 	swc1	$f10,0x8($a1)
);

GLOBAL_ASM(
glabel func00015e4c
/*    15e4c:	c4a40010 */ 	lwc1	$f4,0x10($a1)
/*    15e50:	c4a60014 */ 	lwc1	$f6,0x14($a1)
/*    15e54:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*    15e58:	c4aa0018 */ 	lwc1	$f10,0x18($a1)
/*    15e5c:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*    15e60:	c4a6001c */ 	lwc1	$f6,0x1c($a1)
/*    15e64:	460c5282 */ 	mul.s	$f10,$f10,$f12
/*    15e68:	e4a80010 */ 	swc1	$f8,0x10($a1)
/*    15e6c:	460c3182 */ 	mul.s	$f6,$f6,$f12
/*    15e70:	e4a40014 */ 	swc1	$f4,0x14($a1)
/*    15e74:	e4aa0018 */ 	swc1	$f10,0x18($a1)
/*    15e78:	03e00008 */ 	jr	$ra
/*    15e7c:	e4a6001c */ 	swc1	$f6,0x1c($a1)
);

GLOBAL_ASM(
glabel func00015e80
/*    15e80:	c4a40010 */ 	lwc1	$f4,0x10($a1)
/*    15e84:	c4a60014 */ 	lwc1	$f6,0x14($a1)
/*    15e88:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*    15e8c:	c4aa0018 */ 	lwc1	$f10,0x18($a1)
/*    15e90:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*    15e94:	e4a80010 */ 	swc1	$f8,0x10($a1)
/*    15e98:	460c5282 */ 	mul.s	$f10,$f10,$f12
/*    15e9c:	e4a40014 */ 	swc1	$f4,0x14($a1)
/*    15ea0:	03e00008 */ 	jr	$ra
/*    15ea4:	e4aa0018 */ 	swc1	$f10,0x18($a1)
);

GLOBAL_ASM(
glabel func00015ea8
/*    15ea8:	c4a40020 */ 	lwc1	$f4,0x20($a1)
/*    15eac:	c4a60024 */ 	lwc1	$f6,0x24($a1)
/*    15eb0:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*    15eb4:	c4aa0028 */ 	lwc1	$f10,0x28($a1)
/*    15eb8:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*    15ebc:	c4a6002c */ 	lwc1	$f6,0x2c($a1)
/*    15ec0:	460c5282 */ 	mul.s	$f10,$f10,$f12
/*    15ec4:	e4a80020 */ 	swc1	$f8,0x20($a1)
/*    15ec8:	460c3182 */ 	mul.s	$f6,$f6,$f12
/*    15ecc:	e4a40024 */ 	swc1	$f4,0x24($a1)
/*    15ed0:	e4aa0028 */ 	swc1	$f10,0x28($a1)
/*    15ed4:	03e00008 */ 	jr	$ra
/*    15ed8:	e4a6002c */ 	swc1	$f6,0x2c($a1)
);

GLOBAL_ASM(
glabel func00015edc
/*    15edc:	c4a40020 */ 	lwc1	$f4,0x20($a1)
/*    15ee0:	c4a60024 */ 	lwc1	$f6,0x24($a1)
/*    15ee4:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*    15ee8:	c4aa0028 */ 	lwc1	$f10,0x28($a1)
/*    15eec:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*    15ef0:	e4a80020 */ 	swc1	$f8,0x20($a1)
/*    15ef4:	460c5282 */ 	mul.s	$f10,$f10,$f12
/*    15ef8:	e4a40024 */ 	swc1	$f4,0x24($a1)
/*    15efc:	03e00008 */ 	jr	$ra
/*    15f00:	e4aa0028 */ 	swc1	$f10,0x28($a1)
);

GLOBAL_ASM(
glabel func00015f04
/*    15f04:	24080003 */ 	addiu	$t0,$zero,0x3
.L00015f08:
/*    15f08:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*    15f0c:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*    15f10:	460c2102 */ 	mul.s	$f4,$f4,$f12
/*    15f14:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*    15f18:	460c3182 */ 	mul.s	$f6,$f6,$f12
/*    15f1c:	c4aa000c */ 	lwc1	$f10,0xc($a1)
/*    15f20:	460c4202 */ 	mul.s	$f8,$f8,$f12
/*    15f24:	24a50010 */ 	addiu	$a1,$a1,0x10
/*    15f28:	460c5282 */ 	mul.s	$f10,$f10,$f12
/*    15f2c:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15f30:	e4a4fff0 */ 	swc1	$f4,-0x10($a1)
/*    15f34:	e4a6fff4 */ 	swc1	$f6,-0xc($a1)
/*    15f38:	e4a8fff8 */ 	swc1	$f8,-0x8($a1)
/*    15f3c:	1500fff2 */ 	bnez	$t0,.L00015f08
/*    15f40:	e4aafffc */ 	swc1	$f10,-0x4($a1)
/*    15f44:	03e00008 */ 	jr	$ra
/*    15f48:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00015f4c
/*    15f4c:	24080003 */ 	addiu	$t0,$zero,0x3
.L00015f50:
/*    15f50:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*    15f54:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*    15f58:	460c2102 */ 	mul.s	$f4,$f4,$f12
/*    15f5c:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*    15f60:	460c3182 */ 	mul.s	$f6,$f6,$f12
/*    15f64:	24a50010 */ 	addiu	$a1,$a1,0x10
/*    15f68:	460c4202 */ 	mul.s	$f8,$f8,$f12
/*    15f6c:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15f70:	e4a4fff0 */ 	swc1	$f4,-0x10($a1)
/*    15f74:	e4a6fff4 */ 	swc1	$f6,-0xc($a1)
/*    15f78:	1500fff5 */ 	bnez	$t0,.L00015f50
/*    15f7c:	e4a8fff8 */ 	swc1	$f8,-0x8($a1)
/*    15f80:	03e00008 */ 	jr	$ra
/*    15f84:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00015f88
/*    15f88:	24080003 */ 	addiu	$t0,$zero,0x3
.L00015f8c:
/*    15f8c:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*    15f90:	c4a60010 */ 	lwc1	$f6,0x10($a1)
/*    15f94:	460c2102 */ 	mul.s	$f4,$f4,$f12
/*    15f98:	c4a80020 */ 	lwc1	$f8,0x20($a1)
/*    15f9c:	460c3182 */ 	mul.s	$f6,$f6,$f12
/*    15fa0:	c4aa0030 */ 	lwc1	$f10,0x30($a1)
/*    15fa4:	460c4202 */ 	mul.s	$f8,$f8,$f12
/*    15fa8:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    15fac:	460c5282 */ 	mul.s	$f10,$f10,$f12
/*    15fb0:	2508ffff */ 	addiu	$t0,$t0,-1
/*    15fb4:	e4a4fffc */ 	swc1	$f4,-0x4($a1)
/*    15fb8:	e4a6000c */ 	swc1	$f6,0xc($a1)
/*    15fbc:	e4a8001c */ 	swc1	$f8,0x1c($a1)
/*    15fc0:	1500fff2 */ 	bnez	$t0,.L00015f8c
/*    15fc4:	e4aa002c */ 	swc1	$f10,0x2c($a1)
/*    15fc8:	03e00008 */ 	jr	$ra
/*    15fcc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00015fd0
/*    15fd0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    15fd4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    15fd8:	3c04800a */ 	lui	$a0,%hi(__osPiAccessQueue)
/*    15fdc:	2484c7a8 */ 	addiu	$a0,$a0,%lo(__osPiAccessQueue)
/*    15fe0:	24050000 */ 	addiu	$a1,$zero,0x0
/*    15fe4:	0c0121bc */ 	jal	osRecvMesg
/*    15fe8:	3c060001 */ 	lui	$a2,0x1
/*    15fec:	3c04a45f */ 	lui	$a0,0xa45f
/*    15ff0:	3484ffff */ 	ori	$a0,$a0,0xffff
/*    15ff4:	24840011 */ 	addiu	$a0,$a0,0x11
.L00015ff8:
/*    15ff8:	8c880000 */ 	lw	$t0,0x0($a0)
/*    15ffc:	31080003 */ 	andi	$t0,$t0,0x3
/*    16000:	1500fffd */ 	bnez	$t0,.L00015ff8
/*    16004:	00000000 */ 	nop
/*    16008:	3c058000 */ 	lui	$a1,0x8000
/*    1600c:	8ca50308 */ 	lw	$a1,0x308($a1)
/*    16010:	3c04b764 */ 	lui	$a0,0xb764
/*    16014:	3484b4fd */ 	ori	$a0,$a0,0xb4fd
/*    16018:	00852025 */ 	or	$a0,$a0,$a1
/*    1601c:	3c050764 */ 	lui	$a1,0x764
/*    16020:	34a5bea1 */ 	ori	$a1,$a1,0xbea1
/*    16024:	00852026 */ 	xor	$a0,$a0,$a1
/*    16028:	8c820000 */ 	lw	$v0,0x0($a0)
/*    1602c:	afa20018 */ 	sw	$v0,0x18($sp)
/*    16030:	3c04800a */ 	lui	$a0,%hi(__osPiAccessQueue)
/*    16034:	2484c7a8 */ 	addiu	$a0,$a0,%lo(__osPiAccessQueue)
/*    16038:	24050000 */ 	addiu	$a1,$zero,0x0
/*    1603c:	0c012238 */ 	jal	osSendMesg
/*    16040:	3c060000 */ 	lui	$a2,0x0
/*    16044:	8fa20018 */ 	lw	$v0,0x18($sp)
/*    16048:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1604c:	03e00008 */ 	jr	$ra
/*    16050:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func00016054
/*    16054:	3c0a8006 */ 	lui	$t2,%hi(var8005ef10)
/*    16058:	254aef10 */ 	addiu	$t2,$t2,%lo(var8005ef10)
/*    1605c:	24080004 */ 	addiu	$t0,$zero,0x4
/*    16060:	3c09ffff */ 	lui	$t1,0xffff
/*    16064:	c5400000 */ 	lwc1	$f0,0x0($t2)
/*    16068:	c5420004 */ 	lwc1	$f2,0x4($t2)
.L0001606c:
/*    1606c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*    16070:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*    16074:	46002102 */ 	mul.s	$f4,$f4,$f0
/*    16078:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*    1607c:	46003182 */ 	mul.s	$f6,$f6,$f0
/*    16080:	c48a000c */ 	lwc1	$f10,0xc($a0)
/*    16084:	4600210d */ 	trunc.w.s	$f4,$f4
/*    16088:	46004202 */ 	mul.s	$f8,$f8,$f0
/*    1608c:	440a2000 */ 	mfc1	$t2,$f4
/*    16090:	4600318d */ 	trunc.w.s	$f6,$f6
/*    16094:	46025282 */ 	mul.s	$f10,$f10,$f2
/*    16098:	440b3000 */ 	mfc1	$t3,$f6
/*    1609c:	4600420d */ 	trunc.w.s	$f8,$f8
/*    160a0:	01496024 */ 	and	$t4,$t2,$t1
/*    160a4:	000b6c02 */ 	srl	$t5,$t3,0x10
/*    160a8:	4600528d */ 	trunc.w.s	$f10,$f10
/*    160ac:	018d6025 */ 	or	$t4,$t4,$t5
/*    160b0:	440d4000 */ 	mfc1	$t5,$f8
/*    160b4:	000a5400 */ 	sll	$t2,$t2,0x10
/*    160b8:	316bffff */ 	andi	$t3,$t3,0xffff
/*    160bc:	440e5000 */ 	mfc1	$t6,$f10
/*    160c0:	014b5025 */ 	or	$t2,$t2,$t3
/*    160c4:	01a97824 */ 	and	$t7,$t5,$t1
/*    160c8:	000d6c00 */ 	sll	$t5,$t5,0x10
/*    160cc:	000ec402 */ 	srl	$t8,$t6,0x10
/*    160d0:	31ceffff */ 	andi	$t6,$t6,0xffff
/*    160d4:	01f87825 */ 	or	$t7,$t7,$t8
/*    160d8:	01ae6825 */ 	or	$t5,$t5,$t6
/*    160dc:	24840010 */ 	addiu	$a0,$a0,0x10
/*    160e0:	acac0000 */ 	sw	$t4,0x0($a1)
/*    160e4:	acaf0004 */ 	sw	$t7,0x4($a1)
/*    160e8:	acaa0020 */ 	sw	$t2,0x20($a1)
/*    160ec:	acad0024 */ 	sw	$t5,0x24($a1)
/*    160f0:	2508ffff */ 	addiu	$t0,$t0,-1
/*    160f4:	1500ffdd */ 	bnez	$t0,.L0001606c
/*    160f8:	24a50008 */ 	addiu	$a1,$a1,0x8
/*    160fc:	03e00008 */ 	jr	$ra
/*    16100:	00000000 */ 	nop
);
