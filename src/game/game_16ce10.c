#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_16ce10.h"
#include "gvars/gvars.h"
#include "library/library_481e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f16ce10
/*  f16ce10:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16ce14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16ce18:	0c012144 */ 	jal	func00048510
/*  f16ce1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16ce20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16ce24:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f16ce28:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f16ce2c:	ac620018 */ 	sw	$v0,0x18($v1)
/*  f16ce30:	ac620014 */ 	sw	$v0,0x14($v1)
/*  f16ce34:	03e00008 */ 	jr	$ra
/*  f16ce38:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f16ce3c
/*  f16ce3c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f16ce40:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f16ce44:	44842000 */ 	mtc1	$a0,$f4
/*  f16ce48:	44855000 */ 	mtc1	$a1,$f10
/*  f16ce4c:	8c620058 */ 	lw	$v0,0x58($v1)
/*  f16ce50:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16ce54:	8c6e0018 */ 	lw	$t6,0x18($v1)
/*  f16ce58:	00457821 */ 	addu	$t7,$v0,$a1
/*  f16ce5c:	ac660018 */ 	sw	$a2,0x18($v1)
/*  f16ce60:	ac640000 */ 	sw	$a0,0x0($v1)
/*  f16ce64:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f16ce68:	e4660004 */ 	swc1	$f6,0x4($v1)
/*  f16ce6c:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f16ce70:	ac6f0058 */ 	sw	$t7,0x58($v1)
/*  f16ce74:	ac650040 */ 	sw	$a1,0x40($v1)
/*  f16ce78:	ac620054 */ 	sw	$v0,0x54($v1)
/*  f16ce7c:	e4700048 */ 	swc1	$f16,0x48($v1)
/*  f16ce80:	c4720048 */ 	lwc1	$f18,0x48($v1)
/*  f16ce84:	ac6e0014 */ 	sw	$t6,0x14($v1)
/*  f16ce88:	e4680010 */ 	swc1	$f8,0x10($v1)
/*  f16ce8c:	03e00008 */ 	jr	$ra
/*  f16ce90:	e472005c */ 	swc1	$f18,0x5c($v1)
);

GLOBAL_ASM(
glabel func0f16ce94
/*  f16ce94:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f16ce98:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f16ce9c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f16cea0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f16cea4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f16cea8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f16ceac:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f16ceb0:	3c11000b */ 	lui	$s1,0xb
/*  f16ceb4:	3c120002 */ 	lui	$s2,0x2
/*  f16ceb8:	3c130005 */ 	lui	$s3,0x5
/*  f16cebc:	3c140001 */ 	lui	$s4,0x1
/*  f16cec0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f16cec4:	36947d78 */ 	ori	$s4,$s4,0x7d78
/*  f16cec8:	3673f5e1 */ 	ori	$s3,$s3,0xf5e1
/*  f16cecc:	3652faf0 */ 	ori	$s2,$s2,0xfaf0
/*  f16ced0:	3631ebc2 */ 	ori	$s1,$s1,0xebc2
/*  f16ced4:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
.L0f16ced8:
/*  f16ced8:	0c012144 */ 	jal	func00048510
/*  f16cedc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16cee0:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f16cee4:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f16cee8:	8e190024 */ 	lw	$t9,0x24($s0)
/*  f16ceec:	004e1823 */ 	subu	$v1,$v0,$t6
/*  f16cef0:	01e33821 */ 	addu	$a3,$t7,$v1
/*  f16cef4:	00f3c021 */ 	addu	$t8,$a3,$s3
/*  f16cef8:	0311001b */ 	divu	$zero,$t8,$s1
/*  f16cefc:	00002012 */ 	mflo	$a0
/*  f16cf00:	03234021 */ 	addu	$t0,$t9,$v1
/*  f16cf04:	01144821 */ 	addu	$t1,$t0,$s4
/*  f16cf08:	0132001b */ 	divu	$zero,$t1,$s2
/*  f16cf0c:	8e0a0028 */ 	lw	$t2,0x28($s0)
/*  f16cf10:	00002812 */ 	mflo	$a1
/*  f16cf14:	00403025 */ 	or	$a2,$v0,$zero
/*  f16cf18:	008a082b */ 	sltu	$at,$a0,$t2
/*  f16cf1c:	ae03001c */ 	sw	$v1,0x1c($s0)
/*  f16cf20:	16200002 */ 	bnez	$s1,.L0f16cf2c
/*  f16cf24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16cf28:	0007000d */ 	break	0x7
.L0f16cf2c:
/*  f16cf2c:	16400002 */ 	bnez	$s2,.L0f16cf38
/*  f16cf30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16cf34:	0007000d */ 	break	0x7
.L0f16cf38:
/*  f16cf38:	1420ffe7 */ 	bnez	$at,.L0f16ced8
/*  f16cf3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16cf40:	00910019 */ 	multu	$a0,$s1
/*  f16cf44:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f16cf48:	ae0f0028 */ 	sw	$t7,0x28($s0)
/*  f16cf4c:	00005812 */ 	mflo	$t3
/*  f16cf50:	00eb6023 */ 	subu	$t4,$a3,$t3
/*  f16cf54:	ae0c0020 */ 	sw	$t4,0x20($s0)
/*  f16cf58:	00b20019 */ 	multu	$a1,$s2
/*  f16cf5c:	00006812 */ 	mflo	$t5
/*  f16cf60:	010d7023 */ 	subu	$t6,$t0,$t5
/*  f16cf64:	0fc5b38f */ 	jal	func0f16ce3c
/*  f16cf68:	ae0e0024 */ 	sw	$t6,0x24($s0)
/*  f16cf6c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f16cf70:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f16cf74:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f16cf78:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f16cf7c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f16cf80:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f16cf84:	03e00008 */ 	jr	$ra
/*  f16cf88:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f16cf8c:	03e00008 */ 	jr	$ra
/*  f16cf90:	afa40000 */ 	sw	$a0,0x0($sp)
);

GLOBAL_ASM(
glabel func0f16cf94
/*  f16cf94:	03e00008 */ 	jr	$ra
/*  f16cf98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16cf9c:	00000000 */ 	sll	$zero,$zero,0x0
);
