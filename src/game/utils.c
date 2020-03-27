#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/utils.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1b7cb0[] = "UM_Make : In\n";
const char var7f1b7cc0[] = "UM_Make : Out\n";
const char var7f1b7cd0[] = "Utils -> ERROR at Line %d of %s\n";
const char var7f1b7cf4[] = "Utils -> UM_fVec3_NormaliseTo - Vec = %s%s (%f,%f,%f)\n";
const char var7f1b7d2c[] = "";
const char var7f1b7d30[] = "";
const char var7f1b7d34[] = "Utils -> Attempt to normalise zeo length vector\n";
const char var7f1b7d68[] = "utils.c";
const char var7f1b7d70[] = "UTILS -> DEBUG ERROR - UM_fVec3_MakeNormalTo - Cant normalise\n";
const char var7f1b7db0[] = "utils.c";
const char var7f1b7db8[] = "UTILS -> DEBUG ERROR - UM_fVec3_MakeNormalTo - Cant normalise\n";
const char var7f1b7df8[] = "utils.c";
const char var7f1b7e00[] = "WARNING - UTILS -> DEBUG - Triangle passed to Planar Poly Test\n";
const char var7f1b7e40[] = "utils.c";
const char var7f1b7e48[] = "utils.c";
const char var7f1b7e50[] = "UM_ZeroRunVerify_U8 - FAILED on item %d\n";

const u32 var7f1b7e7c[] = {0x3a83126f};

void func0f176d70(s32 arg0)
{
	var800845d8 = arg0;
}

s32 func0f176d7c(void)
{
	return var800845d8;
}

u32 func0f176d88(u32 arg0)
{
	if (arg0 & 3) {
		arg0 = (arg0 & 0xfffffffc) + 4;
	}

	return arg0;
}

u32 func0f176da4(u32 arg0)
{
	if (arg0 & 0xf) {
		arg0 = (arg0 & 0xfffffff0) + 0x10;
	}

	return arg0;
}

u32 func0f176dc0(u32 arg0)
{
	if (arg0 & 0x1f) {
		arg0 = (arg0 & 0xffffffe0) + 0x20;
	}

	return arg0;
}

GLOBAL_ASM(
glabel func0f176ddc
/*  f176ddc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f176de0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f176de4:	24042710 */ 	addiu	$a0,$zero,0x2710
/*  f176de8:	0c0048f2 */ 	jal	malloc
/*  f176dec:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f176df0:	3c01800b */ 	lui	$at,%hi(var800ac0d0)
/*  f176df4:	ac22c0d0 */ 	sw	$v0,%lo(var800ac0d0)($at)
/*  f176df8:	0fc5db69 */ 	jal	func0f176da4
/*  f176dfc:	24043900 */ 	addiu	$a0,$zero,0x3900
/*  f176e00:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f176e04:	00402025 */ 	or	$a0,$v0,$zero
/*  f176e08:	0c0048f2 */ 	jal	malloc
/*  f176e0c:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f176e10:	3c05800b */ 	lui	$a1,%hi(var800ac0e8)
/*  f176e14:	24a5c0e8 */ 	addiu	$a1,$a1,%lo(var800ac0e8)
/*  f176e18:	1040000e */ 	beqz	$v0,.L0f176e54
/*  f176e1c:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f176e20:	3c02800b */ 	lui	$v0,%hi(var800ac0e8)
/*  f176e24:	2442c0e8 */ 	addiu	$v0,$v0,%lo(var800ac0e8)
/*  f176e28:	00001825 */ 	or	$v1,$zero,$zero
/*  f176e2c:	24040190 */ 	addiu	$a0,$zero,0x190
.L0f176e30:
/*  f176e30:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f176e34:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f176e38:	24630064 */ 	addiu	$v1,$v1,0x64
/*  f176e3c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f176e40:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f176e44:	1464fffa */ 	bne	$v1,$a0,.L0f176e30
/*  f176e48:	ac59fffc */ 	sw	$t9,-0x4($v0)
/*  f176e4c:	10000009 */ 	beqz	$zero,.L0f176e74
/*  f176e50:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f176e54:
/*  f176e54:	3c02800b */ 	lui	$v0,%hi(var800ac0e8)
/*  f176e58:	3c03800b */ 	lui	$v1,%hi(var800ac0f8)
/*  f176e5c:	2463c0f8 */ 	addiu	$v1,$v1,%lo(var800ac0f8)
/*  f176e60:	2442c0e8 */ 	addiu	$v0,$v0,%lo(var800ac0e8)
.L0f176e64:
/*  f176e64:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f176e68:	1443fffe */ 	bne	$v0,$v1,.L0f176e64
/*  f176e6c:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f176e70:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f176e74:
/*  f176e74:	8fa90018 */ 	lw	$t1,0x18($sp)
/*  f176e78:	3c018008 */ 	lui	$at,%hi(var80084610)
/*  f176e7c:	24481900 */ 	addiu	$t0,$v0,0x1900
/*  f176e80:	ac284610 */ 	sw	$t0,%lo(var80084610)($at)
/*  f176e84:	00495021 */ 	addu	$t2,$v0,$t1
/*  f176e88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f176e8c:	254bffff */ 	addiu	$t3,$t2,-1
/*  f176e90:	3c018008 */ 	lui	$at,%hi(var80084618)
/*  f176e94:	3c0c8008 */ 	lui	$t4,%hi(var80084610)
/*  f176e98:	8d8c4610 */ 	lw	$t4,%lo(var80084610)($t4)
/*  f176e9c:	ac2b4618 */ 	sw	$t3,%lo(var80084618)($at)
/*  f176ea0:	3c018008 */ 	lui	$at,%hi(var80084614)
/*  f176ea4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f176ea8:	03e00008 */ 	jr	$ra
/*  f176eac:	ac2c4614 */ 	sw	$t4,%lo(var80084614)($at)
/*  f176eb0:	0085001a */ 	div	$zero,$a0,$a1
/*  f176eb4:	00007010 */ 	mfhi	$t6
/*  f176eb8:	14a00002 */ 	bnez	$a1,.L0f176ec4
/*  f176ebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176ec0:	0007000d */ 	break	0x7
.L0f176ec4:
/*  f176ec4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f176ec8:	14a10004 */ 	bne	$a1,$at,.L0f176edc
/*  f176ecc:	3c018000 */ 	lui	$at,0x8000
/*  f176ed0:	14810002 */ 	bne	$a0,$at,.L0f176edc
/*  f176ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176ed8:	0006000d */ 	break	0x6
.L0f176edc:
/*  f176edc:	15c00003 */ 	bnez	$t6,.L0f176eec
/*  f176ee0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176ee4:	03e00008 */ 	jr	$ra
/*  f176ee8:	00801025 */ 	or	$v0,$a0,$zero
.L0f176eec:
/*  f176eec:	0085001a */ 	div	$zero,$a0,$a1
/*  f176ef0:	00007812 */ 	mflo	$t7
/*  f176ef4:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f176ef8:	14a00002 */ 	bnez	$a1,.L0f176f04
/*  f176efc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176f00:	0007000d */ 	break	0x7
.L0f176f04:
/*  f176f04:	2401ffff */ 	addiu	$at,$zero,-1
/*  f176f08:	14a10004 */ 	bne	$a1,$at,.L0f176f1c
/*  f176f0c:	3c018000 */ 	lui	$at,0x8000
/*  f176f10:	14810002 */ 	bne	$a0,$at,.L0f176f1c
/*  f176f14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176f18:	0006000d */ 	break	0x6
.L0f176f1c:
/*  f176f1c:	03050019 */ 	multu	$t8,$a1
/*  f176f20:	00001012 */ 	mflo	$v0
/*  f176f24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176f28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176f2c:	03e00008 */ 	jr	$ra
/*  f176f30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f176f34:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f176f38:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f176f3c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f176f40:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f176f44:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f176f48:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f176f4c:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f176f50:	e4d20004 */ 	swc1	$f18,0x4($a2)
/*  f176f54:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f176f58:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f176f5c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f176f60:	03e00008 */ 	jr	$ra
/*  f176f64:	e4c80008 */ 	swc1	$f8,0x8($a2)
/*  f176f68:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f176f6c:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f176f70:	c4ca0000 */ 	lwc1	$f10,0x0($a2)
/*  f176f74:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f176f78:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f176f7c:	e4f00000 */ 	swc1	$f16,0x0($a3)
/*  f176f80:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*  f176f84:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f176f88:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f176f8c:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f176f90:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f176f94:	e4ea0004 */ 	swc1	$f10,0x4($a3)
/*  f176f98:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f176f9c:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f176fa0:	c4c60008 */ 	lwc1	$f6,0x8($a2)
/*  f176fa4:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f176fa8:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f176fac:	03e00008 */ 	jr	$ra
/*  f176fb0:	e4e80008 */ 	swc1	$f8,0x8($a3)
/*  f176fb4:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f176fb8:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f176fbc:	c4ca0000 */ 	lwc1	$f10,0x0($a2)
/*  f176fc0:	c4f20000 */ 	lwc1	$f18,0x0($a3)
/*  f176fc4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f176fc8:	8fae0010 */ 	lw	$t6,0x10($sp)
/*  f176fcc:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f176fd0:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f176fd4:	e5c40000 */ 	swc1	$f4,0x0($t6)
/*  f176fd8:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*  f176fdc:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f176fe0:	c4d00004 */ 	lwc1	$f16,0x4($a2)
/*  f176fe4:	c4e40004 */ 	lwc1	$f4,0x4($a3)
/*  f176fe8:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f176fec:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f176ff0:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f176ff4:	e5c60004 */ 	swc1	$f6,0x4($t6)
/*  f176ff8:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f176ffc:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f177000:	c4d20008 */ 	lwc1	$f18,0x8($a2)
/*  f177004:	c4e60008 */ 	lwc1	$f6,0x8($a3)
/*  f177008:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f17700c:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f177010:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f177014:	03e00008 */ 	jr	$ra
/*  f177018:	e5c80008 */ 	swc1	$f8,0x8($t6)
/*  f17701c:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f177020:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f177024:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f177028:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f17702c:	c4900004 */ 	lwc1	$f16,0x4($a0)
/*  f177030:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f177034:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f177038:	e4d20004 */ 	swc1	$f18,0x4($a2)
/*  f17703c:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f177040:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f177044:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f177048:	03e00008 */ 	jr	$ra
/*  f17704c:	e4c80008 */ 	swc1	$f8,0x8($a2)
/*  f177050:	44856000 */ 	mtc1	$a1,$f12
/*  f177054:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177058:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f17705c:	e4c60000 */ 	swc1	$f6,0x0($a2)
/*  f177060:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f177064:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f177068:	e4ca0004 */ 	swc1	$f10,0x4($a2)
/*  f17706c:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f177070:	460c8482 */ 	mul.s	$f18,$f16,$f12
/*  f177074:	03e00008 */ 	jr	$ra
/*  f177078:	e4d20008 */ 	swc1	$f18,0x8($a2)
/*  f17707c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177080:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f177084:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f177088:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f17708c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f177090:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f177094:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f177098:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f17709c:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f1770a0:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f1770a4:	03e00008 */ 	jr	$ra
/*  f1770a8:	46102000 */ 	add.s	$f0,$f4,$f16
);

GLOBAL_ASM(
glabel func0f1770ac
/*  f1770ac:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f1770b0:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f1770b4:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f1770b8:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f1770bc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f1770c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1770c4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f1770c8:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f1770cc:	e4c40000 */ 	swc1	$f4,0x0($a2)
/*  f1770d0:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f1770d4:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f1770d8:	c4b20000 */ 	lwc1	$f18,0x0($a1)
/*  f1770dc:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f1770e0:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f1770e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1770e8:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f1770ec:	46048181 */ 	sub.s	$f6,$f16,$f4
/*  f1770f0:	46003287 */ 	neg.s	$f10,$f6
/*  f1770f4:	e4ca0004 */ 	swc1	$f10,0x4($a2)
/*  f1770f8:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*  f1770fc:	c4880000 */ 	lwc1	$f8,0x0($a0)
/*  f177100:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f177104:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f177108:	46124402 */ 	mul.s	$f16,$f8,$f18
/*  f17710c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177110:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f177114:	460a8201 */ 	sub.s	$f8,$f16,$f10
/*  f177118:	03e00008 */ 	jr	$ra
/*  f17711c:	e4c80008 */ 	swc1	$f8,0x8($a2)
/*  f177120:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177124:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*  f177128:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f17712c:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*  f177130:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f177134:	03e00008 */ 	jr	$ra
/*  f177138:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*  f17713c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177140:	46002187 */ 	neg.s	$f6,$f4
/*  f177144:	e4a60000 */ 	swc1	$f6,0x0($a1)
/*  f177148:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f17714c:	46004287 */ 	neg.s	$f10,$f8
/*  f177150:	e4aa0004 */ 	swc1	$f10,0x4($a1)
/*  f177154:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f177158:	46008487 */ 	neg.s	$f18,$f16
/*  f17715c:	03e00008 */ 	jr	$ra
/*  f177160:	e4b20008 */ 	swc1	$f18,0x8($a1)
);

GLOBAL_ASM(
glabel func0f177164
/*  f177164:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f177168:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17716c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f177170:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f177174:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f177178:	c4820004 */ 	lwc1	$f2,0x4($a0)
/*  f17717c:	c48c0008 */ 	lwc1	$f12,0x8($a0)
/*  f177180:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f177184:	3c018008 */ 	lui	$at,0x8008
/*  f177188:	c43045d4 */ 	lwc1	$f16,0x45d4($at)
/*  f17718c:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f177190:	3c038008 */ 	lui	$v1,%hi(var800845f4)
/*  f177194:	246345f4 */ 	addiu	$v1,$v1,%lo(var800845f4)
/*  f177198:	460c6282 */ 	mul.s	$f10,$f12,$f12
/*  f17719c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f1771a0:	460a4380 */ 	add.s	$f14,$f8,$f10
/*  f1771a4:	4610703c */ 	c.lt.s	$f14,$f16
/*  f1771a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1771ac:	4502000a */ 	bc1fl	.L0f1771d8
/*  f1771b0:	46007306 */ 	mov.s	$f12,$f14
/*  f1771b4:	c4720000 */ 	lwc1	$f18,0x0($v1)
/*  f1771b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1771bc:	e4920000 */ 	swc1	$f18,0x0($a0)
/*  f1771c0:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f1771c4:	e4840004 */ 	swc1	$f4,0x4($a0)
/*  f1771c8:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f1771cc:	10000014 */ 	beqz	$zero,.L0f177220
/*  f1771d0:	e4860008 */ 	swc1	$f6,0x8($a0)
/*  f1771d4:	46007306 */ 	mov.s	$f12,$f14
.L0f1771d8:
/*  f1771d8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1771dc:	0c012974 */ 	jal	sqrtf
/*  f1771e0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1771e4:	3c013f80 */ 	lui	$at,0x3f80
/*  f1771e8:	44814000 */ 	mtc1	$at,$f8
/*  f1771ec:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f1771f0:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f1771f4:	46004083 */ 	div.s	$f2,$f8,$f0
/*  f1771f8:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f1771fc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f177200:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f177204:	e4b00000 */ 	swc1	$f16,0x0($a1)
/*  f177208:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f17720c:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f177210:	e4a40004 */ 	swc1	$f4,0x4($a1)
/*  f177214:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f177218:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f17721c:	e4a80008 */ 	swc1	$f8,0x8($a1)
.L0f177220:
/*  f177220:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f177224:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f177228:	03e00008 */ 	jr	$ra
/*  f17722c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177230:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177234:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f177238:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f17723c:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f177240:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f177244:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f177248:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f17724c:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f177250:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f177254:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f177258:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f17725c:	46128301 */ 	sub.s	$f12,$f16,$f18
/*  f177260:	c4d20008 */ 	lwc1	$f18,0x8($a2)
/*  f177264:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f177268:	00001025 */ 	or	$v0,$zero,$zero
/*  f17726c:	46126102 */ 	mul.s	$f4,$f12,$f18
/*  f177270:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f177274:	44803000 */ 	mtc1	$zero,$f6
/*  f177278:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f17727c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f177280:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177284:	45000002 */ 	bc1f	.L0f177290
/*  f177288:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17728c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f177290:
/*  f177290:	03e00008 */ 	jr	$ra
/*  f177294:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177298:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f17729c:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f1772a0:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f1772a4:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f1772a8:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f1772ac:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f1772b0:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f1772b4:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f1772b8:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f1772bc:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f1772c0:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f1772c4:	46128301 */ 	sub.s	$f12,$f16,$f18
/*  f1772c8:	c4d20008 */ 	lwc1	$f18,0x8($a2)
/*  f1772cc:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f1772d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1772d4:	46126102 */ 	mul.s	$f4,$f12,$f18
/*  f1772d8:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f1772dc:	44803000 */ 	mtc1	$zero,$f6
/*  f1772e0:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f1772e4:	4606403c */ 	c.lt.s	$f8,$f6
/*  f1772e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1772ec:	45000002 */ 	bc1f	.L0f1772f8
/*  f1772f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1772f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1772f8:
/*  f1772f8:	03e00008 */ 	jr	$ra
/*  f1772fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177300:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f177304:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f177308:	44807000 */ 	mtc1	$zero,$f14
/*  f17730c:	3c018008 */ 	lui	$at,0x8008
/*  f177310:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f177314:	00001025 */ 	or	$v0,$zero,$zero
/*  f177318:	4600703c */ 	c.lt.s	$f14,$f0
/*  f17731c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177320:	45020004 */ 	bc1fl	.L0f177334
/*  f177324:	46000087 */ 	neg.s	$f2,$f0
/*  f177328:	10000002 */ 	beqz	$zero,.L0f177334
/*  f17732c:	46000086 */ 	mov.s	$f2,$f0
/*  f177330:	46000087 */ 	neg.s	$f2,$f0
.L0f177334:
/*  f177334:	c42c45d4 */ 	lwc1	$f12,0x45d4($at)
/*  f177338:	460c103c */ 	c.lt.s	$f2,$f12
/*  f17733c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177340:	4500001f */ 	bc1f	.L0f1773c0
/*  f177344:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177348:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f17734c:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f177350:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f177354:	4600703c */ 	c.lt.s	$f14,$f0
/*  f177358:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17735c:	45020004 */ 	bc1fl	.L0f177370
/*  f177360:	46000087 */ 	neg.s	$f2,$f0
/*  f177364:	10000002 */ 	beqz	$zero,.L0f177370
/*  f177368:	46000086 */ 	mov.s	$f2,$f0
/*  f17736c:	46000087 */ 	neg.s	$f2,$f0
.L0f177370:
/*  f177370:	460c103c */ 	c.lt.s	$f2,$f12
/*  f177374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177378:	45000011 */ 	bc1f	.L0f1773c0
/*  f17737c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177380:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f177384:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f177388:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f17738c:	4600703c */ 	c.lt.s	$f14,$f0
/*  f177390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177394:	45020004 */ 	bc1fl	.L0f1773a8
/*  f177398:	46000087 */ 	neg.s	$f2,$f0
/*  f17739c:	10000002 */ 	beqz	$zero,.L0f1773a8
/*  f1773a0:	46000086 */ 	mov.s	$f2,$f0
/*  f1773a4:	46000087 */ 	neg.s	$f2,$f0
.L0f1773a8:
/*  f1773a8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1773ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773b0:	45000003 */ 	bc1f	.L0f1773c0
/*  f1773b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773b8:	03e00008 */ 	jr	$ra
/*  f1773bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1773c0:
/*  f1773c0:	03e00008 */ 	jr	$ra
/*  f1773c4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1773c8
/*  f1773c8:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f1773cc:	c4a20000 */ 	lwc1	$f2,0x0($a1)
/*  f1773d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1773d4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f1773d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773dc:	4500001e */ 	bc1f	.L0f177458
/*  f1773e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773e4:	46001107 */ 	neg.s	$f4,$f2
/*  f1773e8:	4600203c */ 	c.lt.s	$f4,$f0
/*  f1773ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773f0:	45000019 */ 	bc1f	.L0f177458
/*  f1773f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1773f8:	c4800004 */ 	lwc1	$f0,0x4($a0)
/*  f1773fc:	c4a20004 */ 	lwc1	$f2,0x4($a1)
/*  f177400:	4602003c */ 	c.lt.s	$f0,$f2
/*  f177404:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177408:	45000013 */ 	bc1f	.L0f177458
/*  f17740c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177410:	46001187 */ 	neg.s	$f6,$f2
/*  f177414:	4600303c */ 	c.lt.s	$f6,$f0
/*  f177418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17741c:	4500000e */ 	bc1f	.L0f177458
/*  f177420:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177424:	c4800008 */ 	lwc1	$f0,0x8($a0)
/*  f177428:	c4a20008 */ 	lwc1	$f2,0x8($a1)
/*  f17742c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f177430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177434:	45000008 */ 	bc1f	.L0f177458
/*  f177438:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17743c:	46001207 */ 	neg.s	$f8,$f2
/*  f177440:	4600403c */ 	c.lt.s	$f8,$f0
/*  f177444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177448:	45000003 */ 	bc1f	.L0f177458
/*  f17744c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177450:	03e00008 */ 	jr	$ra
/*  f177454:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f177458:
/*  f177458:	03e00008 */ 	jr	$ra
/*  f17745c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f177460
/*  f177460:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f177464:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f177468:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f17746c:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f177470:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f177474:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*  f177478:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f17747c:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f177480:	c4b00008 */ 	lwc1	$f16,0x8($a1)
/*  f177484:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f177488:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f17748c:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f177490:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f177494:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f177498:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f17749c:	0c012974 */ 	jal	sqrtf
/*  f1774a0:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f1774a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1774a8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1774ac:	03e00008 */ 	jr	$ra
/*  f1774b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1774b4:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f1774b8:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f1774bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1774c0:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f1774c4:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f1774c8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f1774cc:	3c077f1b */ 	lui	$a3,%hi(var7f1b7d68)
/*  f1774d0:	24e77d68 */ 	addiu	$a3,$a3,%lo(var7f1b7d68)
/*  f1774d4:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f1774d8:	0fc5dc59 */ 	jal	func0f177164
/*  f1774dc:	240602be */ 	addiu	$a2,$zero,0x2be
/*  f1774e0:	14400003 */ 	bnez	$v0,.L0f1774f0
/*  f1774e4:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f1774e8:	10000024 */ 	beqz	$zero,.L0f17757c
/*  f1774ec:	00001025 */ 	or	$v0,$zero,$zero
.L0f1774f0:
/*  f1774f0:	3c077f1b */ 	lui	$a3,%hi(var7f1b7db0)
/*  f1774f4:	24e77db0 */ 	addiu	$a3,$a3,%lo(var7f1b7db0)
/*  f1774f8:	27a50028 */ 	addiu	$a1,$sp,0x28
/*  f1774fc:	0fc5dc59 */ 	jal	func0f177164
/*  f177500:	240602c6 */ 	addiu	$a2,$zero,0x2c6
/*  f177504:	14400003 */ 	bnez	$v0,.L0f177514
/*  f177508:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f17750c:	1000001b */ 	beqz	$zero,.L0f17757c
/*  f177510:	00001025 */ 	or	$v0,$zero,$zero
.L0f177514:
/*  f177514:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*  f177518:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f17751c:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*  f177520:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f177524:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f177528:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f17752c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f177530:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f177534:	c7b20030 */ 	lwc1	$f18,0x30($sp)
/*  f177538:	c7a8003c */ 	lwc1	$f8,0x3c($sp)
/*  f17753c:	46124482 */ 	mul.s	$f18,$f8,$f18
/*  f177540:	46128000 */ 	add.s	$f0,$f16,$f18
/*  f177544:	46000007 */ 	neg.s	$f0,$f0
/*  f177548:	460a0082 */ 	mul.s	$f2,$f0,$f10
/*  f17754c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177550:	46080302 */ 	mul.s	$f12,$f0,$f8
/*  f177554:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177558:	46040402 */ 	mul.s	$f16,$f0,$f4
/*  f17755c:	46103480 */ 	add.s	$f18,$f6,$f16
/*  f177560:	e4720000 */ 	swc1	$f18,0x0($v1)
/*  f177564:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f177568:	46025200 */ 	add.s	$f8,$f10,$f2
/*  f17756c:	e4680004 */ 	swc1	$f8,0x4($v1)
/*  f177570:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*  f177574:	460c2180 */ 	add.s	$f6,$f4,$f12
/*  f177578:	e4660008 */ 	swc1	$f6,0x8($v1)
.L0f17757c:
/*  f17757c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f177580:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f177584:	03e00008 */ 	jr	$ra
/*  f177588:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17758c:	c4820000 */ 	lwc1	$f2,0x0($a0)
/*  f177590:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f177594:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f177598:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*  f17759c:	46041001 */ 	sub.s	$f0,$f2,$f4
/*  f1775a0:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f1775a4:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f1775a8:	46083301 */ 	sub.s	$f12,$f6,$f8
/*  f1775ac:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*  f1775b0:	c4d20000 */ 	lwc1	$f18,0x0($a2)
/*  f1775b4:	46045381 */ 	sub.s	$f14,$f10,$f4
/*  f1775b8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1775bc:	e7a6000c */ 	swc1	$f6,0xc($sp)
/*  f1775c0:	46009282 */ 	mul.s	$f10,$f18,$f0
/*  f1775c4:	c7a4000c */ 	lwc1	$f4,0xc($sp)
/*  f1775c8:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*  f1775cc:	46046182 */ 	mul.s	$f6,$f12,$f4
/*  f1775d0:	e7a80008 */ 	swc1	$f8,0x8($sp)
/*  f1775d4:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f1775d8:	c7aa0008 */ 	lwc1	$f10,0x8($sp)
/*  f1775dc:	460a7182 */ 	mul.s	$f6,$f14,$f10
/*  f1775e0:	46064400 */ 	add.s	$f16,$f8,$f6
/*  f1775e4:	46008207 */ 	neg.s	$f8,$f16
/*  f1775e8:	e7a80004 */ 	swc1	$f8,0x4($sp)
/*  f1775ec:	c7a60004 */ 	lwc1	$f6,0x4($sp)
/*  f1775f0:	46123002 */ 	mul.s	$f0,$f6,$f18
/*  f1775f4:	46001200 */ 	add.s	$f8,$f2,$f0
/*  f1775f8:	46043302 */ 	mul.s	$f12,$f6,$f4
/*  f1775fc:	e4e80000 */ 	swc1	$f8,0x0($a3)
/*  f177600:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f177604:	460a3382 */ 	mul.s	$f14,$f6,$f10
/*  f177608:	460c2180 */ 	add.s	$f6,$f4,$f12
/*  f17760c:	e4e60004 */ 	swc1	$f6,0x4($a3)
/*  f177610:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f177614:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f177618:	460e5200 */ 	add.s	$f8,$f10,$f14
/*  f17761c:	03e00008 */ 	jr	$ra
/*  f177620:	e4e80008 */ 	swc1	$f8,0x8($a3)
/*  f177624:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f177628:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f17762c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f177630:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f177634:	3c077f1b */ 	lui	$a3,%hi(var7f1b7df8)
/*  f177638:	24e77df8 */ 	addiu	$a3,$a3,%lo(var7f1b7df8)
/*  f17763c:	24060303 */ 	addiu	$a2,$zero,0x303
/*  f177640:	0fc5dc59 */ 	jal	func0f177164
/*  f177644:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f177648:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f17764c:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f177650:	c4a20008 */ 	lwc1	$f2,0x8($a1)
/*  f177654:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f177658:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17765c:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f177660:	0c012974 */ 	jal	sqrtf
/*  f177664:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f177668:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f17766c:	8fa20020 */ 	lw	$v0,0x20($sp)
/*  f177670:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f177674:	c4a80000 */ 	lwc1	$f8,0x0($a1)
/*  f177678:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f17767c:	44808000 */ 	mtc1	$zero,$f16
/*  f177680:	46004303 */ 	div.s	$f12,$f8,$f0
/*  f177684:	e4500004 */ 	swc1	$f16,0x4($v0)
/*  f177688:	46000207 */ 	neg.s	$f8,$f0
/*  f17768c:	46005083 */ 	div.s	$f2,$f10,$f0
/*  f177690:	46006487 */ 	neg.s	$f18,$f12
/*  f177694:	e4520008 */ 	swc1	$f18,0x8($v0)
/*  f177698:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f17769c:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*  f1776a0:	e4680004 */ 	swc1	$f8,0x4($v1)
/*  f1776a4:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f1776a8:	e4660000 */ 	swc1	$f6,0x0($v1)
/*  f1776ac:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f1776b0:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f1776b4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f1776b8:	e4720008 */ 	swc1	$f18,0x8($v1)
/*  f1776bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1776c0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1776c4:	03e00008 */ 	jr	$ra
/*  f1776c8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1776cc
/*  f1776cc:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f1776d0:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f1776d4:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f1776d8:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f1776dc:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f1776e0:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f1776e4:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f1776e8:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f1776ec:	c4d20008 */ 	lwc1	$f18,0x8($a2)
/*  f1776f0:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f1776f4:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f1776f8:	46049381 */ 	sub.s	$f14,$f18,$f4
/*  f1776fc:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f177700:	460a6482 */ 	mul.s	$f18,$f12,$f10
/*  f177704:	3c018008 */ 	lui	$at,0x8008
/*  f177708:	c42045d4 */ 	lwc1	$f0,0x45d4($at)
/*  f17770c:	46067282 */ 	mul.s	$f10,$f14,$f6
/*  f177710:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f177714:	460a2400 */ 	add.s	$f16,$f4,$f10
/*  f177718:	4600803c */ 	c.lt.s	$f16,$f0
/*  f17771c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177720:	45000009 */ 	bc1f	.L0f177748
/*  f177724:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177728:	46000207 */ 	neg.s	$f8,$f0
/*  f17772c:	3c018008 */ 	lui	$at,0x8008
/*  f177730:	4610403c */ 	c.lt.s	$f8,$f16
/*  f177734:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177738:	45000003 */ 	bc1f	.L0f177748
/*  f17773c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177740:	03e00008 */ 	jr	$ra
/*  f177744:	c42045d0 */ 	lwc1	$f0,0x45d0($at)
.L0f177748:
/*  f177748:	46021482 */ 	mul.s	$f18,$f2,$f2
/*  f17774c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177750:	460c6182 */ 	mul.s	$f6,$f12,$f12
/*  f177754:	46069100 */ 	add.s	$f4,$f18,$f6
/*  f177758:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f17775c:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f177760:	46104003 */ 	div.s	$f0,$f8,$f16
/*  f177764:	03e00008 */ 	jr	$ra
/*  f177768:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f17776c
/*  f17776c:	44866000 */ 	mtc1	$a2,$f12
/*  f177770:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f177774:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f177778:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f17777c:	460c2002 */ 	mul.s	$f0,$f4,$f12
/*  f177780:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*  f177784:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f177788:	460c3082 */ 	mul.s	$f2,$f6,$f12
/*  f17778c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177790:	460c4382 */ 	mul.s	$f14,$f8,$f12
/*  f177794:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f177798:	e4f00000 */ 	swc1	$f16,0x0($a3)
/*  f17779c:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f1777a0:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f1777a4:	e4e40004 */ 	swc1	$f4,0x4($a3)
/*  f1777a8:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f1777ac:	460e3200 */ 	add.s	$f8,$f6,$f14
/*  f1777b0:	03e00008 */ 	jr	$ra
/*  f1777b4:	e4e80008 */ 	swc1	$f8,0x8($a3)
/*  f1777b8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1777bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1777c0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1777c4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1777c8:	0fc5ddb3 */ 	jal	func0f1776cc
/*  f1777cc:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f1777d0:	44060000 */ 	mfc1	$a2,$f0
/*  f1777d4:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f1777d8:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f1777dc:	0fc5dddb */ 	jal	func0f17776c
/*  f1777e0:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f1777e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1777e8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1777ec:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1777f0:	03e00008 */ 	jr	$ra
/*  f1777f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1777f8
/*  f1777f8:	3c03800b */ 	lui	$v1,%hi(var800ac0f8)
/*  f1777fc:	3c02800b */ 	lui	$v0,%hi(var800ac108)
/*  f177800:	2442c108 */ 	addiu	$v0,$v0,%lo(var800ac108)
/*  f177804:	2463c0f8 */ 	addiu	$v1,$v1,%lo(var800ac0f8)
.L0f177808:
/*  f177808:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f17780c:	1462fffe */ 	bne	$v1,$v0,.L0f177808
/*  f177810:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f177814:	03e00008 */ 	jr	$ra
/*  f177818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17781c:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f177820:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f177824:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f177828:	24010003 */ 	addiu	$at,$zero,0x3
/*  f17782c:	00808825 */ 	or	$s1,$a0,$zero
/*  f177830:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f177834:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f177838:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f17783c:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f177840:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f177844:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f177848:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f17784c:	14a10003 */ 	bne	$a1,$at,.L0f17785c
/*  f177850:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f177854:	1000005b */ 	beqz	$zero,.L0f1779c4
/*  f177858:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f17785c:
/*  f17785c:	c624000c */ 	lwc1	$f4,0xc($s1)
/*  f177860:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f177864:	27b00060 */ 	addiu	$s0,$sp,0x60
/*  f177868:	02003025 */ 	or	$a2,$s0,$zero
/*  f17786c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f177870:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f177874:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f177878:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f17787c:	c6300004 */ 	lwc1	$f16,0x4($s1)
/*  f177880:	c62a0010 */ 	lwc1	$f10,0x10($s1)
/*  f177884:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f177888:	e7b2007c */ 	swc1	$f18,0x7c($sp)
/*  f17788c:	c6260008 */ 	lwc1	$f6,0x8($s1)
/*  f177890:	c6240014 */ 	lwc1	$f4,0x14($s1)
/*  f177894:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f177898:	e7a80080 */ 	swc1	$f8,0x80($sp)
/*  f17789c:	c6300000 */ 	lwc1	$f16,0x0($s1)
/*  f1778a0:	c62a0018 */ 	lwc1	$f10,0x18($s1)
/*  f1778a4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f1778a8:	e7b2006c */ 	swc1	$f18,0x6c($sp)
/*  f1778ac:	c6260004 */ 	lwc1	$f6,0x4($s1)
/*  f1778b0:	c624001c */ 	lwc1	$f4,0x1c($s1)
/*  f1778b4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1778b8:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f1778bc:	c6300008 */ 	lwc1	$f16,0x8($s1)
/*  f1778c0:	c62a0020 */ 	lwc1	$f10,0x20($s1)
/*  f1778c4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f1778c8:	0fc5dc2b */ 	jal	func0f1770ac
/*  f1778cc:	e7b20074 */ 	swc1	$f18,0x74($sp)
/*  f1778d0:	3c077f1b */ 	lui	$a3,%hi(var7f1b7e40)
/*  f1778d4:	24e77e40 */ 	addiu	$a3,$a3,%lo(var7f1b7e40)
/*  f1778d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1778dc:	02002825 */ 	or	$a1,$s0,$zero
/*  f1778e0:	0fc5dc59 */ 	jal	func0f177164
/*  f1778e4:	2406044d */ 	addiu	$a2,$zero,0x44d
/*  f1778e8:	2aa10004 */ 	slti	$at,$s5,0x4
/*  f1778ec:	14200034 */ 	bnez	$at,.L0f1779c0
/*  f1778f0:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f1778f4:	3c017f1b */ 	lui	$at,%hi(var7f1b7e7c)
/*  f1778f8:	3c147f1b */ 	lui	$s4,%hi(var7f1b7e48)
/*  f1778fc:	4480a000 */ 	mtc1	$zero,$f20
/*  f177900:	26947e48 */ 	addiu	$s4,$s4,%lo(var7f1b7e48)
/*  f177904:	c4367e7c */ 	lwc1	$f22,%lo(var7f1b7e7c)($at)
/*  f177908:	26300024 */ 	addiu	$s0,$s1,0x24
/*  f17790c:	27b30050 */ 	addiu	$s3,$sp,0x50
.L0f177910:
/*  f177910:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f177914:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f177918:	02602025 */ 	or	$a0,$s3,$zero
/*  f17791c:	02602825 */ 	or	$a1,$s3,$zero
/*  f177920:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f177924:	24060455 */ 	addiu	$a2,$zero,0x455
/*  f177928:	02803825 */ 	or	$a3,$s4,$zero
/*  f17792c:	e7a80050 */ 	swc1	$f8,0x50($sp)
/*  f177930:	c6300004 */ 	lwc1	$f16,0x4($s1)
/*  f177934:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*  f177938:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f17793c:	e7b20054 */ 	swc1	$f18,0x54($sp)
/*  f177940:	c6260008 */ 	lwc1	$f6,0x8($s1)
/*  f177944:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f177948:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f17794c:	0fc5dc59 */ 	jal	func0f177164
/*  f177950:	e7a80058 */ 	swc1	$f8,0x58($sp)
/*  f177954:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*  f177958:	c7b00060 */ 	lwc1	$f16,0x60($sp)
/*  f17795c:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f177960:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f177964:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f177968:	c7b00058 */ 	lwc1	$f16,0x58($sp)
/*  f17796c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f177970:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f177974:	c7a40068 */ 	lwc1	$f4,0x68($sp)
/*  f177978:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f17797c:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f177980:	46065000 */ 	add.s	$f0,$f10,$f6
/*  f177984:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f177988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17798c:	45020004 */ 	bc1fl	.L0f1779a0
/*  f177990:	46000087 */ 	neg.s	$f2,$f0
/*  f177994:	10000002 */ 	beqz	$zero,.L0f1779a0
/*  f177998:	46000086 */ 	mov.s	$f2,$f0
/*  f17799c:	46000087 */ 	neg.s	$f2,$f0
.L0f1779a0:
/*  f1779a0:	4602b03c */ 	c.lt.s	$f22,$f2
/*  f1779a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1779a8:	45000003 */ 	bc1f	.L0f1779b8
/*  f1779ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1779b0:	10000004 */ 	beqz	$zero,.L0f1779c4
/*  f1779b4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1779b8:
/*  f1779b8:	1655ffd5 */ 	bne	$s2,$s5,.L0f177910
/*  f1779bc:	2610000c */ 	addiu	$s0,$s0,0xc
.L0f1779c0:
/*  f1779c0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1779c4:
/*  f1779c4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1779c8:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f1779cc:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f1779d0:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f1779d4:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f1779d8:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f1779dc:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f1779e0:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f1779e4:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f1779e8:	03e00008 */ 	jr	$ra
/*  f1779ec:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*  f1779f0:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f1779f4:	afa40008 */ 	sw	$a0,0x8($sp)
/*  f1779f8:	afa5000c */ 	sw	$a1,0xc($sp)
/*  f1779fc:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f177a00:	afa70014 */ 	sw	$a3,0x14($sp)
/*  f177a04:	03e00008 */ 	jr	$ra
/*  f177a08:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*  f177a0c:	03e00008 */ 	jr	$ra
/*  f177a10:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f177a14:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f177a18:	afa40008 */ 	sw	$a0,0x8($sp)
/*  f177a1c:	afa5000c */ 	sw	$a1,0xc($sp)
/*  f177a20:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f177a24:	afa70014 */ 	sw	$a3,0x14($sp)
/*  f177a28:	03e00008 */ 	jr	$ra
/*  f177a2c:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*  f177a30:	03e00008 */ 	jr	$ra
/*  f177a34:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f177a38:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f177a3c:	afa40008 */ 	sw	$a0,0x8($sp)
/*  f177a40:	afa5000c */ 	sw	$a1,0xc($sp)
/*  f177a44:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f177a48:	afa70014 */ 	sw	$a3,0x14($sp)
/*  f177a4c:	03e00008 */ 	jr	$ra
/*  f177a50:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0f177a54
/*  f177a54:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f177a58:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f177a5c:	00c08025 */ 	or	$s0,$a2,$zero
/*  f177a60:	00001025 */ 	or	$v0,$zero,$zero
/*  f177a64:	00001825 */ 	or	$v1,$zero,$zero
/*  f177a68:	18a0002d */ 	blez	$a1,.L0f177b20
/*  f177a6c:	00004025 */ 	or	$t0,$zero,$zero
/*  f177a70:	00803025 */ 	or	$a2,$a0,$zero
/*  f177a74:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f177a78:	240b00c8 */ 	addiu	$t3,$zero,0xc8
/*  f177a7c:	240a00ff */ 	addiu	$t2,$zero,0xff
.L0f177a80:
/*  f177a80:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f177a84:	50800023 */ 	beqzl	$a0,.L0f177b14
/*  f177a88:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f177a8c:	1040001d */ 	beqz	$v0,.L0f177b04
/*  f177a90:	02034821 */ 	addu	$t1,$s0,$v1
/*  f177a94:	00c77023 */ 	subu	$t6,$a2,$a3
/*  f177a98:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*  f177a9c:	55e0001a */ 	bnezl	$t7,.L0f177b08
/*  f177aa0:	a1240000 */ 	sb	$a0,0x0($t1)
/*  f177aa4:	a1200000 */ 	sb	$zero,0x0($t1)
/*  f177aa8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177aac:	150a0007 */ 	bne	$t0,$t2,.L0f177acc
/*  f177ab0:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f177ab4:	a12b0000 */ 	sb	$t3,0x0($t1)
/*  f177ab8:	a1200001 */ 	sb	$zero,0x1($t1)
/*  f177abc:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f177ac0:	25290002 */ 	addiu	$t1,$t1,0x2
/*  f177ac4:	1000000a */ 	beqz	$zero,.L0f177af0
/*  f177ac8:	2508ff38 */ 	addiu	$t0,$t0,-200
.L0f177acc:
/*  f177acc:	29010100 */ 	slti	$at,$t0,0x100
/*  f177ad0:	54200008 */ 	bnezl	$at,.L0f177af4
/*  f177ad4:	a1280000 */ 	sb	$t0,0x0($t1)
.L0f177ad8:
/*  f177ad8:	2508ff01 */ 	addiu	$t0,$t0,-255
/*  f177adc:	29010100 */ 	slti	$at,$t0,0x100
/*  f177ae0:	a12c0000 */ 	sb	$t4,0x0($t1)
/*  f177ae4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177ae8:	1020fffb */ 	beqz	$at,.L0f177ad8
/*  f177aec:	25290001 */ 	addiu	$t1,$t1,0x1
.L0f177af0:
/*  f177af0:	a1280000 */ 	sb	$t0,0x0($t1)
.L0f177af4:
/*  f177af4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177af8:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f177afc:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f177b00:	00004025 */ 	or	$t0,$zero,$zero
.L0f177b04:
/*  f177b04:	a1240000 */ 	sb	$a0,0x0($t1)
.L0f177b08:
/*  f177b08:	10000002 */ 	beqz	$zero,.L0f177b14
/*  f177b0c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177b10:	25080001 */ 	addiu	$t0,$t0,0x1
.L0f177b14:
/*  f177b14:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177b18:	1445ffd9 */ 	bne	$v0,$a1,.L0f177a80
/*  f177b1c:	00c73021 */ 	addu	$a2,$a2,$a3
.L0f177b20:
/*  f177b20:	0203c021 */ 	addu	$t8,$s0,$v1
/*  f177b24:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177b28:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f177b2c:	0203c821 */ 	addu	$t9,$s0,$v1
/*  f177b30:	a3200000 */ 	sb	$zero,0x0($t9)
/*  f177b34:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f177b38:	24620001 */ 	addiu	$v0,$v1,0x1
/*  f177b3c:	03e00008 */ 	jr	$ra
/*  f177b40:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*  f177b44:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f177b48:	00803025 */ 	or	$a2,$a0,$zero
/*  f177b4c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f177b50:	14610003 */ 	bne	$v1,$at,.L0f177b60
/*  f177b54:	3c04800b */ 	lui	$a0,%hi(var800ac108)
/*  f177b58:	3c01800b */ 	lui	$at,%hi(var800ac108)
/*  f177b5c:	ac20c108 */ 	sw	$zero,%lo(var800ac108)($at)
.L0f177b60:
/*  f177b60:	8c84c108 */ 	lw	$a0,%lo(var800ac108)($a0)
/*  f177b64:	3c01800b */ 	lui	$at,%hi(var800ac108)
/*  f177b68:	00c43821 */ 	addu	$a3,$a2,$a0
/*  f177b6c:	90ee0000 */ 	lbu	$t6,0x0($a3)
/*  f177b70:	55c0000b */ 	bnezl	$t6,.L0f177ba0
/*  f177b74:	24780001 */ 	addiu	$t8,$v1,0x1
/*  f177b78:	90e20001 */ 	lbu	$v0,0x1($a3)
/*  f177b7c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f177b80:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f177b84:	10400005 */ 	beqz	$v0,.L0f177b9c
/*  f177b88:	00627821 */ 	addu	$t7,$v1,$v0
/*  f177b8c:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f177b90:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f177b94:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f177b98:	01e01825 */ 	or	$v1,$t7,$zero
.L0f177b9c:
/*  f177b9c:	24780001 */ 	addiu	$t8,$v1,0x1
.L0f177ba0:
/*  f177ba0:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f177ba4:	90e20000 */ 	lbu	$v0,0x0($a3)
/*  f177ba8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f177bac:	03e00008 */ 	jr	$ra
/*  f177bb0:	ac24c108 */ 	sw	$a0,%lo(var800ac108)($at)
);

GLOBAL_ASM(
glabel func0f177bb4
/*  f177bb4:	14800003 */ 	bnez	$a0,.L0f177bc4
/*  f177bb8:	00001825 */ 	or	$v1,$zero,$zero
/*  f177bbc:	03e00008 */ 	jr	$ra
/*  f177bc0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f177bc4:
/*  f177bc4:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f177bc8:	3c078008 */ 	lui	$a3,%hi(var80084624)
/*  f177bcc:	240fffff */ 	addiu	$t7,$zero,-1
/*  f177bd0:	15c00002 */ 	bnez	$t6,.L0f177bdc
/*  f177bd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177bd8:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f177bdc:
/*  f177bdc:	8ce74624 */ 	lw	$a3,%lo(var80084624)($a3)
/*  f177be0:	3c018008 */ 	lui	$at,%hi(var80084624)
/*  f177be4:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f177be8:	1ce00022 */ 	bgtz	$a3,.L0f177c74
/*  f177bec:	ac274624 */ 	sw	$a3,%lo(var80084624)($at)
/*  f177bf0:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f177bf4:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f177bf8:	93080000 */ 	lbu	$t0,0x0($t8)
/*  f177bfc:	24590001 */ 	addiu	$t9,$v0,0x1
/*  f177c00:	03245821 */ 	addu	$t3,$t9,$a0
/*  f177c04:	51000004 */ 	beqzl	$t0,.L0f177c18
/*  f177c08:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f177c0c:	10000017 */ 	beqz	$zero,.L0f177c6c
/*  f177c10:	01001825 */ 	or	$v1,$t0,$zero
/*  f177c14:	acb90000 */ 	sw	$t9,0x0($a1)
.L0f177c18:
/*  f177c18:	91680000 */ 	lbu	$t0,0x0($t3)
/*  f177c1c:	03201025 */ 	or	$v0,$t9,$zero
/*  f177c20:	240a00ff */ 	addiu	$t2,$zero,0xff
/*  f177c24:	1100000f */ 	beqz	$t0,.L0f177c64
/*  f177c28:	00003825 */ 	or	$a3,$zero,$zero
/*  f177c2c:	15480009 */ 	bne	$t2,$t0,.L0f177c54
/*  f177c30:	01004825 */ 	or	$t1,$t0,$zero
/*  f177c34:	244c0001 */ 	addiu	$t4,$v0,0x1
.L0f177c38:
/*  f177c38:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f177c3c:	01846821 */ 	addu	$t5,$t4,$a0
/*  f177c40:	91a90000 */ 	lbu	$t1,0x0($t5)
/*  f177c44:	24e700ff */ 	addiu	$a3,$a3,0xff
/*  f177c48:	01801025 */ 	or	$v0,$t4,$zero
/*  f177c4c:	5149fffa */ 	beql	$t2,$t1,.L0f177c38
/*  f177c50:	244c0001 */ 	addiu	$t4,$v0,0x1
.L0f177c54:
/*  f177c54:	00e93821 */ 	addu	$a3,$a3,$t1
/*  f177c58:	3c018008 */ 	lui	$at,%hi(var80084624)
/*  f177c5c:	10000003 */ 	beqz	$zero,.L0f177c6c
/*  f177c60:	ac274624 */ 	sw	$a3,%lo(var80084624)($at)
.L0f177c64:
/*  f177c64:	03e00008 */ 	jr	$ra
/*  f177c68:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f177c6c:
/*  f177c6c:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f177c70:	acae0000 */ 	sw	$t6,0x0($a1)
.L0f177c74:
/*  f177c74:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f177c78:	00601025 */ 	or	$v0,$v1,$zero
/*  f177c7c:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f177c80:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f177c84:	03e00008 */ 	jr	$ra
/*  f177c88:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f177c8c
/*  f177c8c:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f177c90:	240effff */ 	addiu	$t6,$zero,-1
/*  f177c94:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f177c98:	54600004 */ 	bnezl	$v1,.L0f177cac
/*  f177c9c:	00647821 */ 	addu	$t7,$v1,$a0
/*  f177ca0:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f177ca4:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f177ca8:	00647821 */ 	addu	$t7,$v1,$a0
.L0f177cac:
/*  f177cac:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f177cb0:	17000020 */ 	bnez	$t8,.L0f177d34
/*  f177cb4:	24790001 */ 	addiu	$t9,$v1,0x1
.L0f177cb8:
/*  f177cb8:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f177cbc:	03244821 */ 	addu	$t1,$t9,$a0
/*  f177cc0:	91220000 */ 	lbu	$v0,0x0($t1)
/*  f177cc4:	10400014 */ 	beqz	$v0,.L0f177d18
/*  f177cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177ccc:	14e2000b */ 	bne	$a3,$v0,.L0f177cfc
/*  f177cd0:	00401825 */ 	or	$v1,$v0,$zero
/*  f177cd4:	8cca0000 */ 	lw	$t2,0x0($a2)
.L0f177cd8:
/*  f177cd8:	254b00ff */ 	addiu	$t3,$t2,0xff
/*  f177cdc:	accb0000 */ 	sw	$t3,0x0($a2)
/*  f177ce0:	8cac0000 */ 	lw	$t4,0x0($a1)
/*  f177ce4:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f177ce8:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f177cec:	01a47821 */ 	addu	$t7,$t5,$a0
/*  f177cf0:	91e30000 */ 	lbu	$v1,0x0($t7)
/*  f177cf4:	50e3fff8 */ 	beql	$a3,$v1,.L0f177cd8
/*  f177cf8:	8cca0000 */ 	lw	$t2,0x0($a2)
.L0f177cfc:
/*  f177cfc:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f177d00:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f177d04:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f177d08:	8ca80000 */ 	lw	$t0,0x0($a1)
/*  f177d0c:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f177d10:	10000003 */ 	beqz	$zero,.L0f177d20
/*  f177d14:	aca90000 */ 	sw	$t1,0x0($a1)
.L0f177d18:
/*  f177d18:	03e00008 */ 	jr	$ra
/*  f177d1c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f177d20:
/*  f177d20:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f177d24:	00645021 */ 	addu	$t2,$v1,$a0
/*  f177d28:	914b0000 */ 	lbu	$t3,0x0($t2)
/*  f177d2c:	5160ffe2 */ 	beqzl	$t3,.L0f177cb8
/*  f177d30:	24790001 */ 	addiu	$t9,$v1,0x1
.L0f177d34:
/*  f177d34:	8ccc0000 */ 	lw	$t4,0x0($a2)
/*  f177d38:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f177d3c:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f177d40:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f177d44:	00647021 */ 	addu	$t6,$v1,$a0
/*  f177d48:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f177d4c:	246f0001 */ 	addiu	$t7,$v1,0x1
/*  f177d50:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f177d54:	03e00008 */ 	jr	$ra
/*  f177d58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177d5c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f177d60:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f177d64:	00808825 */ 	or	$s1,$a0,$zero
/*  f177d68:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f177d6c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f177d70:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f177d74:	00a08025 */ 	or	$s0,$a1,$zero
/*  f177d78:	27b20034 */ 	addiu	$s2,$sp,0x34
/*  f177d7c:	27b30030 */ 	addiu	$s3,$sp,0x30
/*  f177d80:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f177d84:	00a02025 */ 	or	$a0,$a1,$zero
/*  f177d88:	02402825 */ 	or	$a1,$s2,$zero
/*  f177d8c:	02603025 */ 	or	$a2,$s3,$zero
/*  f177d90:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f177d94:	0fc5deed */ 	jal	func0f177bb4
/*  f177d98:	afa00030 */ 	sw	$zero,0x30($sp)
/*  f177d9c:	0442000f */ 	bltzl	$v0,.L0f177ddc
/*  f177da0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f177da4:	8fae0030 */ 	lw	$t6,0x30($sp)
.L0f177da8:
/*  f177da8:	02002025 */ 	or	$a0,$s0,$zero
/*  f177dac:	02402825 */ 	or	$a1,$s2,$zero
/*  f177db0:	022e7821 */ 	addu	$t7,$s1,$t6
/*  f177db4:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f177db8:	10580003 */ 	beq	$v0,$t8,.L0f177dc8
/*  f177dbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177dc0:	10000006 */ 	beqz	$zero,.L0f177ddc
/*  f177dc4:	00001025 */ 	or	$v0,$zero,$zero
.L0f177dc8:
/*  f177dc8:	0fc5deed */ 	jal	func0f177bb4
/*  f177dcc:	02603025 */ 	or	$a2,$s3,$zero
/*  f177dd0:	0443fff5 */ 	bgezl	$v0,.L0f177da8
/*  f177dd4:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f177dd8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f177ddc:
/*  f177ddc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f177de0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f177de4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f177de8:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f177dec:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f177df0:	03e00008 */ 	jr	$ra
/*  f177df4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f177df8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f177dfc:	00000000 */ 	sll	$zero,$zero,0x0
);
