#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/lib_44f60.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func00047a90
/*    47a90:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    47a94:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    47a98:	afa40038 */ 	sw	$a0,0x38($sp)
/*    47a9c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    47aa0:	afa60040 */ 	sw	$a2,0x40($sp)
/*    47aa4:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    47aa8:	afae0034 */ 	sw	$t6,0x34($sp)
/*    47aac:	240f0170 */ 	addiu	$t7,$zero,0x170
/*    47ab0:	a7af0032 */ 	sh	$t7,0x32($sp)
/*    47ab4:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    47ab8:	8f190048 */ 	lw	$t9,0x48($t8)
/*    47abc:	1320001c */ 	beqz	$t9,.L00047b30
/*    47ac0:	00000000 */ 	nop
/*    47ac4:	8fa40038 */ 	lw	$a0,0x38($sp)
/*    47ac8:	27a50032 */ 	addiu	$a1,$sp,0x32
/*    47acc:	240600b8 */ 	addiu	$a2,$zero,0xb8
/*    47ad0:	0c0113d8 */ 	jal	func00044f60
/*    47ad4:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    47ad8:	afa20034 */ 	sw	$v0,0x34($sp)
/*    47adc:	8fa80034 */ 	lw	$t0,0x34($sp)
/*    47ae0:	25090008 */ 	addiu	$t1,$t0,0x8
/*    47ae4:	afa90034 */ 	sw	$t1,0x34($sp)
/*    47ae8:	afa80020 */ 	sw	$t0,0x20($sp)
/*    47aec:	87aa0032 */ 	lh	$t2,0x32($sp)
/*    47af0:	3c0100ff */ 	lui	$at,0xff
/*    47af4:	3421ffff */ 	ori	$at,$at,0xffff
/*    47af8:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    47afc:	01415824 */ 	and	$t3,$t2,$at
/*    47b00:	3c010a00 */ 	lui	$at,0xa00
/*    47b04:	01616025 */ 	or	$t4,$t3,$at
/*    47b08:	adac0000 */ 	sw	$t4,0x0($t5)
/*    47b0c:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    47b10:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    47b14:	85cf0000 */ 	lh	$t7,0x0($t6)
/*    47b18:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*    47b1c:	0018cc00 */ 	sll	$t9,$t8,0x10
/*    47b20:	37280170 */ 	ori	$t0,$t9,0x170
/*    47b24:	ad280004 */ 	sw	$t0,0x4($t1)
/*    47b28:	10000062 */ 	b	.L00047cb4
/*    47b2c:	00000000 */ 	nop
.L00047b30:
/*    47b30:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    47b34:	3c017006 */ 	lui	$at,0x7006
/*    47b38:	d4289e00 */ 	ldc1	$f8,-0x6200($at)
/*    47b3c:	c5440044 */ 	lwc1	$f4,0x44($t2)
/*    47b40:	460021a1 */ 	cvt.d.s	$f6,$f4
/*    47b44:	4626403c */ 	c.lt.d	$f8,$f6
/*    47b48:	00000000 */ 	nop
/*    47b4c:	45000005 */ 	bc1f	.L00047b64
/*    47b50:	00000000 */ 	nop
/*    47b54:	3c017006 */ 	lui	$at,0x7006
/*    47b58:	c42a9e08 */ 	lwc1	$f10,-0x61f8($at)
/*    47b5c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    47b60:	e56a0044 */ 	swc1	$f10,0x44($t3)
.L00047b64:
/*    47b64:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    47b68:	3c014700 */ 	lui	$at,0x4700
/*    47b6c:	44819000 */ 	mtc1	$at,$f18
/*    47b70:	c5900044 */ 	lwc1	$f16,0x44($t4)
/*    47b74:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    47b78:	4600218d */ 	trunc.w.s	$f6,$f4
/*    47b7c:	440e3000 */ 	mfc1	$t6,$f6
/*    47b80:	00000000 */ 	nop
/*    47b84:	448e4000 */ 	mtc1	$t6,$f8
/*    47b88:	00000000 */ 	nop
/*    47b8c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    47b90:	e58a0044 */ 	swc1	$f10,0x44($t4)
/*    47b94:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    47b98:	3c014700 */ 	lui	$at,0x4700
/*    47b9c:	44819000 */ 	mtc1	$at,$f18
/*    47ba0:	c5f00044 */ 	lwc1	$f16,0x44($t7)
/*    47ba4:	46128103 */ 	div.s	$f4,$f16,$f18
/*    47ba8:	e5e40044 */ 	swc1	$f4,0x44($t7)
/*    47bac:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    47bb0:	3c014338 */ 	lui	$at,0x4338
/*    47bb4:	44814000 */ 	mtc1	$at,$f8
/*    47bb8:	c7060044 */ 	lwc1	$f6,0x44($t8)
/*    47bbc:	c710004c */ 	lwc1	$f16,0x4c($t8)
/*    47bc0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    47bc4:	460a8480 */ 	add.s	$f18,$f16,$f10
/*    47bc8:	e7b20024 */ 	swc1	$f18,0x24($sp)
/*    47bcc:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*    47bd0:	4600218d */ 	trunc.w.s	$f6,$f4
/*    47bd4:	44083000 */ 	mfc1	$t0,$f6
/*    47bd8:	00000000 */ 	nop
/*    47bdc:	afa8002c */ 	sw	$t0,0x2c($sp)
/*    47be0:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    47be4:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*    47be8:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    47bec:	44898000 */ 	mtc1	$t1,$f16
/*    47bf0:	00000000 */ 	nop
/*    47bf4:	468082a0 */ 	cvt.s.w	$f10,$f16
/*    47bf8:	460a4481 */ 	sub.s	$f18,$f8,$f10
/*    47bfc:	e552004c */ 	swc1	$f18,0x4c($t2)
/*    47c00:	8fa40038 */ 	lw	$a0,0x38($sp)
/*    47c04:	27a50032 */ 	addiu	$a1,$sp,0x32
/*    47c08:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    47c0c:	0c0113d8 */ 	jal	func00044f60
/*    47c10:	8fa70040 */ 	lw	$a3,0x40($sp)
/*    47c14:	afa20034 */ 	sw	$v0,0x34($sp)
/*    47c18:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    47c1c:	3c014700 */ 	lui	$at,0x4700
/*    47c20:	44813000 */ 	mtc1	$at,$f6
/*    47c24:	c5640044 */ 	lwc1	$f4,0x44($t3)
/*    47c28:	46062402 */ 	mul.s	$f16,$f4,$f6
/*    47c2c:	4600820d */ 	trunc.w.s	$f8,$f16
/*    47c30:	440e4000 */ 	mfc1	$t6,$f8
/*    47c34:	00000000 */ 	nop
/*    47c38:	afae0028 */ 	sw	$t6,0x28($sp)
/*    47c3c:	8fac0034 */ 	lw	$t4,0x34($sp)
/*    47c40:	258f0008 */ 	addiu	$t7,$t4,0x8
/*    47c44:	afaf0034 */ 	sw	$t7,0x34($sp)
/*    47c48:	afac001c */ 	sw	$t4,0x1c($sp)
/*    47c4c:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    47c50:	0c012d20 */ 	jal	osVirtualToPhysical
/*    47c54:	8f040040 */ 	lw	$a0,0x40($t8)
/*    47c58:	3c0100ff */ 	lui	$at,0xff
/*    47c5c:	3421ffff */ 	ori	$at,$at,0xffff
/*    47c60:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    47c64:	0041c824 */ 	and	$t9,$v0,$at
/*    47c68:	3c010500 */ 	lui	$at,0x500
/*    47c6c:	03214025 */ 	or	$t0,$t9,$at
/*    47c70:	ad280000 */ 	sw	$t0,0x0($t1)
/*    47c74:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    47c78:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    47c7c:	87a80032 */ 	lh	$t0,0x32($sp)
/*    47c80:	8d4b0050 */ 	lw	$t3,0x50($t2)
/*    47c84:	318fffff */ 	andi	$t7,$t4,0xffff
/*    47c88:	000fc380 */ 	sll	$t8,$t7,0xe
/*    47c8c:	316d0003 */ 	andi	$t5,$t3,0x3
/*    47c90:	000d7780 */ 	sll	$t6,$t5,0x1e
/*    47c94:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    47c98:	31090fff */ 	andi	$t1,$t0,0xfff
/*    47c9c:	00095080 */ 	sll	$t2,$t1,0x2
/*    47ca0:	01d8c825 */ 	or	$t9,$t6,$t8
/*    47ca4:	032a5825 */ 	or	$t3,$t9,$t2
/*    47ca8:	adab0004 */ 	sw	$t3,0x4($t5)
/*    47cac:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    47cb0:	ad800050 */ 	sw	$zero,0x50($t4)
.L00047cb4:
/*    47cb4:	10000003 */ 	b	.L00047cc4
/*    47cb8:	8fa20034 */ 	lw	$v0,0x34($sp)
/*    47cbc:	10000001 */ 	b	.L00047cc4
/*    47cc0:	00000000 */ 	nop
.L00047cc4:
/*    47cc4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    47cc8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    47ccc:	03e00008 */ 	jr	$ra
/*    47cd0:	00000000 */ 	nop
/*    47cd4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    47cd8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    47cdc:	afa40018 */ 	sw	$a0,0x18($sp)
/*    47ce0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    47ce4:	afa60020 */ 	sw	$a2,0x20($sp)
/*    47ce8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    47cec:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    47cf0:	0c011582 */ 	jal	func00045608
/*    47cf4:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    47cf8:	10000003 */ 	b	.L00047d08
/*    47cfc:	00001025 */ 	or	$v0,$zero,$zero
/*    47d00:	10000001 */ 	b	.L00047d08
/*    47d04:	00000000 */ 	nop
.L00047d08:
/*    47d08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    47d0c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    47d10:	03e00008 */ 	jr	$ra
/*    47d14:	00000000 */ 	nop
/*    47d18:	00000000 */ 	nop
/*    47d1c:	00000000 */ 	nop
);