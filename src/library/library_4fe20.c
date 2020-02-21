#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_4a360.h"
#include "library/library_4fe20.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004fe20
/*    4fe20:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4fe24:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4fe28:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    4fe2c:	afa60020 */ 	sw	$a2,0x20($sp)
/*    4fe30:	afa70024 */ 	sw	$a3,0x24($sp)
/*    4fe34:	0c012918 */ 	jal	func0004a460
/*    4fe38:	afa40018 */ 	sw	$a0,0x18($sp)
/*    4fe3c:	3c014000 */ 	lui	$at,0x4000
/*    4fe40:	c7ae002c */ 	lwc1	$f14,0x2c($sp)
/*    4fe44:	44812000 */ 	mtc1	$at,$f4
/*    4fe48:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    4fe4c:	c7a8001c */ 	lwc1	$f8,0x1c($sp)
/*    4fe50:	460e2002 */ 	mul.s	$f0,$f4,$f14
/*    4fe54:	8fa20018 */ 	lw	$v0,0x18($sp)
/*    4fe58:	46083081 */ 	sub.s	$f2,$f6,$f8
/*    4fe5c:	c7b20028 */ 	lwc1	$f18,0x28($sp)
/*    4fe60:	3c01bf80 */ 	lui	$at,0xbf80
/*    4fe64:	00001825 */ 	or	$v1,$zero,$zero
/*    4fe68:	24040004 */ 	addiu	$a0,$zero,0x4
/*    4fe6c:	46020283 */ 	div.s	$f10,$f0,$f2
/*    4fe70:	e44a0000 */ 	swc1	$f10,0x0($v0)
/*    4fe74:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*    4fe78:	46049301 */ 	sub.s	$f12,$f18,$f4
/*    4fe7c:	460c0183 */ 	div.s	$f6,$f0,$f12
/*    4fe80:	e4460014 */ 	swc1	$f6,0x14($v0)
/*    4fe84:	c7aa001c */ 	lwc1	$f10,0x1c($sp)
/*    4fe88:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*    4fe8c:	460a4100 */ 	add.s	$f4,$f8,$f10
/*    4fe90:	46022183 */ 	div.s	$f6,$f4,$f2
/*    4fe94:	e4460020 */ 	swc1	$f6,0x20($v0)
/*    4fe98:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*    4fe9c:	46089280 */ 	add.s	$f10,$f18,$f8
/*    4fea0:	460c5103 */ 	div.s	$f4,$f10,$f12
/*    4fea4:	e4440024 */ 	swc1	$f4,0x24($v0)
/*    4fea8:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*    4feac:	460e3200 */ 	add.s	$f8,$f6,$f14
/*    4feb0:	460e3401 */ 	sub.s	$f16,$f6,$f14
/*    4feb4:	44813000 */ 	mtc1	$at,$f6
/*    4feb8:	3c01c000 */ 	lui	$at,0xc000
/*    4febc:	46004287 */ 	neg.s	$f10,$f8
/*    4fec0:	e446002c */ 	swc1	$f6,0x2c($v0)
/*    4fec4:	46105103 */ 	div.s	$f4,$f10,$f16
/*    4fec8:	44814000 */ 	mtc1	$at,$f8
/*    4fecc:	e4440028 */ 	swc1	$f4,0x28($v0)
/*    4fed0:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*    4fed4:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*    4fed8:	44805000 */ 	mtc1	$zero,$f10
/*    4fedc:	00000000 */ 	sll	$zero,$zero,0x0
/*    4fee0:	e44a003c */ 	swc1	$f10,0x3c($v0)
/*    4fee4:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*    4fee8:	46103203 */ 	div.s	$f8,$f6,$f16
/*    4feec:	e4480038 */ 	swc1	$f8,0x38($v0)
/*    4fef0:	c7a00034 */ 	lwc1	$f0,0x34($sp)
/*    4fef4:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*    4fef8:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4fefc:	c44e0004 */ 	lwc1	$f14,0x4($v0)
/*    4ff00:	46004402 */ 	mul.s	$f16,$f8,$f0
/*    4ff04:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*    4ff08:	10640010 */ 	beq	$v1,$a0,.L0004ff4c
/*    4ff0c:	c44c000c */ 	lwc1	$f12,0xc($v0)
.L0004ff10:
/*    4ff10:	46007282 */ 	mul.s	$f10,$f14,$f0
/*    4ff14:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*    4ff18:	c44e0014 */ 	lwc1	$f14,0x14($v0)
/*    4ff1c:	46009182 */ 	mul.s	$f6,$f18,$f0
/*    4ff20:	c4520018 */ 	lwc1	$f18,0x18($v0)
/*    4ff24:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4ff28:	46006102 */ 	mul.s	$f4,$f12,$f0
/*    4ff2c:	c44c001c */ 	lwc1	$f12,0x1c($v0)
/*    4ff30:	e4500000 */ 	swc1	$f16,0x0($v0)
/*    4ff34:	46004402 */ 	mul.s	$f16,$f8,$f0
/*    4ff38:	e44a0004 */ 	swc1	$f10,0x4($v0)
/*    4ff3c:	e4460008 */ 	swc1	$f6,0x8($v0)
/*    4ff40:	24420010 */ 	addiu	$v0,$v0,0x10
/*    4ff44:	1464fff2 */ 	bne	$v1,$a0,.L0004ff10
/*    4ff48:	e444fffc */ 	swc1	$f4,-0x4($v0)
.L0004ff4c:
/*    4ff4c:	46007282 */ 	mul.s	$f10,$f14,$f0
/*    4ff50:	24420010 */ 	addiu	$v0,$v0,0x10
/*    4ff54:	e450fff0 */ 	swc1	$f16,-0x10($v0)
/*    4ff58:	46009182 */ 	mul.s	$f6,$f18,$f0
/*    4ff5c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ff60:	46006102 */ 	mul.s	$f4,$f12,$f0
/*    4ff64:	e44afff4 */ 	swc1	$f10,-0xc($v0)
/*    4ff68:	e446fff8 */ 	swc1	$f6,-0x8($v0)
/*    4ff6c:	e444fffc */ 	swc1	$f4,-0x4($v0)
/*    4ff70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4ff74:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4ff78:	03e00008 */ 	jr	$ra
/*    4ff7c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ff80:	27bdff98 */ 	addiu	$sp,$sp,-104
/*    4ff84:	44856000 */ 	mtc1	$a1,$f12
/*    4ff88:	44867000 */ 	mtc1	$a2,$f14
/*    4ff8c:	44878000 */ 	mtc1	$a3,$f16
/*    4ff90:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*    4ff94:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*    4ff98:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*    4ff9c:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*    4ffa0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    4ffa4:	afa40068 */ 	sw	$a0,0x68($sp)
/*    4ffa8:	44056000 */ 	mfc1	$a1,$f12
/*    4ffac:	44067000 */ 	mfc1	$a2,$f14
/*    4ffb0:	44078000 */ 	mfc1	$a3,$f16
/*    4ffb4:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4ffb8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    4ffbc:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*    4ffc0:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*    4ffc4:	0c013f88 */ 	jal	func0004fe20
/*    4ffc8:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*    4ffcc:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4ffd0:	0c0128d8 */ 	jal	func0004a360
/*    4ffd4:	8fa50068 */ 	lw	$a1,0x68($sp)
/*    4ffd8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    4ffdc:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*    4ffe0:	03e00008 */ 	jr	$ra
/*    4ffe4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ffe8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ffec:	00000000 */ 	sll	$zero,$zero,0x0
);