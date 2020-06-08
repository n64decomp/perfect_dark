#include <ultra64.h>
#include "constants.h"
#include "game/data/ailists.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_096750.h"
#include "game/padhalllv.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4f5e0.h"
#include "types.h"

const u32 var70054200[] = {0x42652ee0};
const u32 var70054204[] = {0x00000000};
const u32 var70054208[] = {0x00000000};
const u32 var7005420c[] = {0x00000000};
const u32 var70054210[] = {0xbf7ffcb9};
const u32 var70054214[] = {0x3f7ffcb9};
const u32 var70054218[] = {0x40490fdb};
const u32 var7005421c[] = {0x40c90fdb};
const u32 var70054220[] = {0x3fc90fda};
const u32 var70054224[] = {0xbf7ffcb9};
const u32 var70054228[] = {0x3f7ffcb9};
const u32 var7005422c[] = {0x38c90fdb};
const u32 var70054230[] = {0x3fc90fda};
const u32 var70054234[] = {0x38490fdb};
const u32 var70054238[] = {0x3fc90fdb};
const u32 var7005423c[] = {0x46fffe00};
const u32 var70054240[] = {0x384910a4};
const u32 var70054244[] = {0x3fc90fda};
const u32 var70054248[] = {0x362edef8};
const u32 var7005424c[] = {0xb94fb7ff};
const u32 var70054250[] = {0x3c08876a};
const u32 var70054254[] = {0xbe2aaaa6};
const u32 var70054258[] = {0x3ea2f983};
const u32 var7005425c[] = {0x40490fdb};
const u32 var70054260[] = {0x330885a3};
const u32 var70054264[] = {0x362edef8};
const u32 var70054268[] = {0xb94fb7ff};
const u32 var7005426c[] = {0x3c08876a};
const u32 var70054270[] = {0xbe2aaaa6};
const u32 var70054274[] = {0x00000000};
const u32 var70054278[] = {0x00000000};
const u32 var7005427c[] = {0x00000000};

GLOBAL_ASM(
glabel func00016110
/*    16110:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    16114:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    16118:	afa50044 */ 	sw	$a1,0x44($sp)
/*    1611c:	0c005850 */ 	jal	func00016140
/*    16120:	27a6001c */ 	addiu	$a2,$sp,0x1c
/*    16124:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*    16128:	0c005736 */ 	jal	func00015cd8
/*    1612c:	8fa50044 */ 	lw	$a1,0x44($sp)
/*    16130:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    16134:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    16138:	03e00008 */ 	jr	$ra
/*    1613c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00016140
/*    16140:	00001825 */ 	or	$v1,$zero,$zero
/*    16144:	00804025 */ 	or	$t0,$a0,$zero
/*    16148:	240a000c */ 	addiu	$t2,$zero,0xc
/*    1614c:	24090003 */ 	addiu	$t1,$zero,0x3
.L00016150:
/*    16150:	00001025 */ 	or	$v0,$zero,$zero
/*    16154:	00c32021 */ 	addu	$a0,$a2,$v1
/*    16158:	00a03825 */ 	or	$a3,$a1,$zero
.L0001615c:
/*    1615c:	c5120000 */ 	lwc1	$f18,0x0($t0)
/*    16160:	c4f00000 */ 	lwc1	$f16,0x0($a3)
/*    16164:	c50e000c */ 	lwc1	$f14,0xc($t0)
/*    16168:	c4ec0004 */ 	lwc1	$f12,0x4($a3)
/*    1616c:	46109402 */ 	mul.s	$f16,$f18,$f16
/*    16170:	c4f20008 */ 	lwc1	$f18,0x8($a3)
/*    16174:	c50a0018 */ 	lwc1	$f10,0x18($t0)
/*    16178:	460c7302 */ 	mul.s	$f12,$f14,$f12
/*    1617c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    16180:	2484000c */ 	addiu	$a0,$a0,0xc
/*    16184:	460a9282 */ 	mul.s	$f10,$f18,$f10
/*    16188:	24e7000c */ 	addiu	$a3,$a3,0xc
/*    1618c:	460c8300 */ 	add.s	$f12,$f16,$f12
/*    16190:	460c5300 */ 	add.s	$f12,$f10,$f12
/*    16194:	1449fff1 */ 	bne	$v0,$t1,.L0001615c
/*    16198:	e48cfff4 */ 	swc1	$f12,-0xc($a0)
/*    1619c:	24630004 */ 	addiu	$v1,$v1,0x4
/*    161a0:	146affeb */ 	bne	$v1,$t2,.L00016150
/*    161a4:	25080004 */ 	addiu	$t0,$t0,0x4
/*    161a8:	03e00008 */ 	jr	$ra
/*    161ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000161b0
/*    161b0:	00803825 */ 	or	$a3,$a0,$zero
/*    161b4:	24040003 */ 	addiu	$a0,$zero,0x3
/*    161b8:	00001025 */ 	or	$v0,$zero,$zero
/*    161bc:	00c01825 */ 	or	$v1,$a2,$zero
.L000161c0:
/*    161c0:	c4f20000 */ 	lwc1	$f18,0x0($a3)
/*    161c4:	c4b00000 */ 	lwc1	$f16,0x0($a1)
/*    161c8:	c4ee000c */ 	lwc1	$f14,0xc($a3)
/*    161cc:	c4ac0004 */ 	lwc1	$f12,0x4($a1)
/*    161d0:	46109402 */ 	mul.s	$f16,$f18,$f16
/*    161d4:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*    161d8:	c4ea0018 */ 	lwc1	$f10,0x18($a3)
/*    161dc:	460c7302 */ 	mul.s	$f12,$f14,$f12
/*    161e0:	24420001 */ 	addiu	$v0,$v0,0x1
/*    161e4:	24630004 */ 	addiu	$v1,$v1,0x4
/*    161e8:	460a9282 */ 	mul.s	$f10,$f18,$f10
/*    161ec:	24e70004 */ 	addiu	$a3,$a3,0x4
/*    161f0:	460c8300 */ 	add.s	$f12,$f16,$f12
/*    161f4:	460c5300 */ 	add.s	$f12,$f10,$f12
/*    161f8:	1444fff1 */ 	bne	$v0,$a0,.L000161c0
/*    161fc:	e46cfffc */ 	swc1	$f12,-0x4($v1)
/*    16200:	03e00008 */ 	jr	$ra
/*    16204:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00016208
/*    16208:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    1620c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    16210:	27a6001c */ 	addiu	$a2,$sp,0x1c
/*    16214:	0c00586c */ 	jal	func000161b0
/*    16218:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    1621c:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*    16220:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*    16224:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*    16228:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    1622c:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*    16230:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*    16234:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*    16238:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1623c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    16240:	03e00008 */ 	jr	$ra
/*    16244:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00016248
/*    16248:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1624c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    16250:	afa50024 */ 	sw	$a1,0x24($sp)
/*    16254:	afa40020 */ 	sw	$a0,0x20($sp)
/*    16258:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*    1625c:	0c0068f4 */ 	jal	cosf
/*    16260:	afa60028 */ 	sw	$a2,0x28($sp)
/*    16264:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*    16268:	0c0068f7 */ 	jal	sinf
/*    1626c:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*    16270:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    16274:	8fa20020 */ 	lw	$v0,0x20($sp)
/*    16278:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*    1627c:	44801000 */ 	mtc1	$zero,$f2
/*    16280:	3c013f80 */ 	lui	$at,0x3f80
/*    16284:	44816000 */ 	mtc1	$at,$f12
/*    16288:	46000107 */ 	neg.s	$f4,$f0
/*    1628c:	e4c00020 */ 	swc1	$f0,0x20($a2)
/*    16290:	e4c40008 */ 	swc1	$f4,0x8($a2)
/*    16294:	e4ce0000 */ 	swc1	$f14,0x0($a2)
/*    16298:	e4ce0028 */ 	swc1	$f14,0x28($a2)
/*    1629c:	e4c20004 */ 	swc1	$f2,0x4($a2)
/*    162a0:	e4c2000c */ 	swc1	$f2,0xc($a2)
/*    162a4:	e4c20010 */ 	swc1	$f2,0x10($a2)
/*    162a8:	e4c20018 */ 	swc1	$f2,0x18($a2)
/*    162ac:	e4c2001c */ 	swc1	$f2,0x1c($a2)
/*    162b0:	e4c20024 */ 	swc1	$f2,0x24($a2)
/*    162b4:	e4c2002c */ 	swc1	$f2,0x2c($a2)
/*    162b8:	e4cc0014 */ 	swc1	$f12,0x14($a2)
/*    162bc:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*    162c0:	e4c60030 */ 	swc1	$f6,0x30($a2)
/*    162c4:	c4480004 */ 	lwc1	$f8,0x4($v0)
/*    162c8:	e4c80034 */ 	swc1	$f8,0x34($a2)
/*    162cc:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*    162d0:	e4cc003c */ 	swc1	$f12,0x3c($a2)
/*    162d4:	e4ca0038 */ 	swc1	$f10,0x38($a2)
/*    162d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    162dc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    162e0:	03e00008 */ 	jr	$ra
/*    162e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000162e8
/*    162e8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    162ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    162f0:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*    162f4:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*    162f8:	0c0068f4 */ 	jal	cosf
/*    162fc:	afa50024 */ 	sw	$a1,0x24($sp)
/*    16300:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*    16304:	0c0068f7 */ 	jal	sinf
/*    16308:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*    1630c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    16310:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*    16314:	44801000 */ 	mtc1	$zero,$f2
/*    16318:	3c013f80 */ 	lui	$at,0x3f80
/*    1631c:	44816000 */ 	mtc1	$at,$f12
/*    16320:	46000107 */ 	neg.s	$f4,$f0
/*    16324:	e4a00018 */ 	swc1	$f0,0x18($a1)
/*    16328:	e4a40024 */ 	swc1	$f4,0x24($a1)
/*    1632c:	e4ae0014 */ 	swc1	$f14,0x14($a1)
/*    16330:	e4ae0028 */ 	swc1	$f14,0x28($a1)
/*    16334:	e4a20004 */ 	swc1	$f2,0x4($a1)
/*    16338:	e4a20008 */ 	swc1	$f2,0x8($a1)
/*    1633c:	e4a2000c */ 	swc1	$f2,0xc($a1)
/*    16340:	e4a20010 */ 	swc1	$f2,0x10($a1)
/*    16344:	e4a2001c */ 	swc1	$f2,0x1c($a1)
/*    16348:	e4a20020 */ 	swc1	$f2,0x20($a1)
/*    1634c:	e4a2002c */ 	swc1	$f2,0x2c($a1)
/*    16350:	e4a20030 */ 	swc1	$f2,0x30($a1)
/*    16354:	e4a20034 */ 	swc1	$f2,0x34($a1)
/*    16358:	e4a20038 */ 	swc1	$f2,0x38($a1)
/*    1635c:	e4ac0000 */ 	swc1	$f12,0x0($a1)
/*    16360:	e4ac003c */ 	swc1	$f12,0x3c($a1)
/*    16364:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    16368:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    1636c:	03e00008 */ 	jr	$ra
/*    16370:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00016374
/*    16374:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    16378:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1637c:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*    16380:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*    16384:	0c0068f4 */ 	jal	cosf
/*    16388:	afa50024 */ 	sw	$a1,0x24($sp)
/*    1638c:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*    16390:	0c0068f7 */ 	jal	sinf
/*    16394:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*    16398:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    1639c:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*    163a0:	44801000 */ 	mtc1	$zero,$f2
/*    163a4:	3c013f80 */ 	lui	$at,0x3f80
/*    163a8:	44816000 */ 	mtc1	$at,$f12
/*    163ac:	46000107 */ 	neg.s	$f4,$f0
/*    163b0:	e4a00020 */ 	swc1	$f0,0x20($a1)
/*    163b4:	e4a40008 */ 	swc1	$f4,0x8($a1)
/*    163b8:	e4ae0000 */ 	swc1	$f14,0x0($a1)
/*    163bc:	e4ae0028 */ 	swc1	$f14,0x28($a1)
/*    163c0:	e4a20004 */ 	swc1	$f2,0x4($a1)
/*    163c4:	e4a2000c */ 	swc1	$f2,0xc($a1)
/*    163c8:	e4a20010 */ 	swc1	$f2,0x10($a1)
/*    163cc:	e4a20018 */ 	swc1	$f2,0x18($a1)
/*    163d0:	e4a2001c */ 	swc1	$f2,0x1c($a1)
/*    163d4:	e4a20024 */ 	swc1	$f2,0x24($a1)
/*    163d8:	e4a2002c */ 	swc1	$f2,0x2c($a1)
/*    163dc:	e4a20030 */ 	swc1	$f2,0x30($a1)
/*    163e0:	e4a20034 */ 	swc1	$f2,0x34($a1)
/*    163e4:	e4a20038 */ 	swc1	$f2,0x38($a1)
/*    163e8:	e4ac0014 */ 	swc1	$f12,0x14($a1)
/*    163ec:	e4ac003c */ 	swc1	$f12,0x3c($a1)
/*    163f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    163f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    163f8:	03e00008 */ 	jr	$ra
/*    163fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00016400
/*    16400:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    16404:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    16408:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*    1640c:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*    16410:	0c0068f4 */ 	jal	cosf
/*    16414:	afa50024 */ 	sw	$a1,0x24($sp)
/*    16418:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*    1641c:	0c0068f7 */ 	jal	sinf
/*    16420:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*    16424:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    16428:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*    1642c:	44801000 */ 	mtc1	$zero,$f2
/*    16430:	3c013f80 */ 	lui	$at,0x3f80
/*    16434:	44816000 */ 	mtc1	$at,$f12
/*    16438:	46000107 */ 	neg.s	$f4,$f0
/*    1643c:	e4a00004 */ 	swc1	$f0,0x4($a1)
/*    16440:	e4a40010 */ 	swc1	$f4,0x10($a1)
/*    16444:	e4ae0000 */ 	swc1	$f14,0x0($a1)
/*    16448:	e4ae0014 */ 	swc1	$f14,0x14($a1)
/*    1644c:	e4a20008 */ 	swc1	$f2,0x8($a1)
/*    16450:	e4a2000c */ 	swc1	$f2,0xc($a1)
/*    16454:	e4a20018 */ 	swc1	$f2,0x18($a1)
/*    16458:	e4a2001c */ 	swc1	$f2,0x1c($a1)
/*    1645c:	e4a20020 */ 	swc1	$f2,0x20($a1)
/*    16460:	e4a20024 */ 	swc1	$f2,0x24($a1)
/*    16464:	e4a2002c */ 	swc1	$f2,0x2c($a1)
/*    16468:	e4a20030 */ 	swc1	$f2,0x30($a1)
/*    1646c:	e4a20034 */ 	swc1	$f2,0x34($a1)
/*    16470:	e4a20038 */ 	swc1	$f2,0x38($a1)
/*    16474:	e4ac0028 */ 	swc1	$f12,0x28($a1)
/*    16478:	e4ac003c */ 	swc1	$f12,0x3c($a1)
/*    1647c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    16480:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    16484:	03e00008 */ 	jr	$ra
/*    16488:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0001648c
/*    1648c:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    16490:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    16494:	afb10018 */ 	sw	$s1,0x18($sp)
/*    16498:	afb00014 */ 	sw	$s0,0x14($sp)
/*    1649c:	00a08025 */ 	or	$s0,$a1,$zero
/*    164a0:	00808825 */ 	or	$s1,$a0,$zero
/*    164a4:	0c0068f4 */ 	jal	cosf
/*    164a8:	c48c0000 */ 	lwc1	$f12,0x0($a0)
/*    164ac:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*    164b0:	0c0068f7 */ 	jal	sinf
/*    164b4:	c62c0000 */ 	lwc1	$f12,0x0($s1)
/*    164b8:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*    164bc:	0c0068f4 */ 	jal	cosf
/*    164c0:	c62c0004 */ 	lwc1	$f12,0x4($s1)
/*    164c4:	c62c0004 */ 	lwc1	$f12,0x4($s1)
/*    164c8:	0c0068f7 */ 	jal	sinf
/*    164cc:	e7a0004c */ 	swc1	$f0,0x4c($sp)
/*    164d0:	c62c0008 */ 	lwc1	$f12,0x8($s1)
/*    164d4:	0c0068f4 */ 	jal	cosf
/*    164d8:	e7a00048 */ 	swc1	$f0,0x48($sp)
/*    164dc:	c62c0008 */ 	lwc1	$f12,0x8($s1)
/*    164e0:	0c0068f7 */ 	jal	sinf
/*    164e4:	e7a00044 */ 	swc1	$f0,0x44($sp)
/*    164e8:	c7ae004c */ 	lwc1	$f14,0x4c($sp)
/*    164ec:	c7b00044 */ 	lwc1	$f16,0x44($sp)
/*    164f0:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*    164f4:	44806000 */ 	mtc1	$zero,$f12
/*    164f8:	46107102 */ 	mul.s	$f4,$f14,$f16
/*    164fc:	46001207 */ 	neg.s	$f8,$f2
/*    16500:	e60c000c */ 	swc1	$f12,0xc($s0)
/*    16504:	46007182 */ 	mul.s	$f6,$f14,$f0
/*    16508:	e6080008 */ 	swc1	$f8,0x8($s0)
/*    1650c:	3c013f80 */ 	lui	$at,0x3f80
/*    16510:	e6040000 */ 	swc1	$f4,0x0($s0)
/*    16514:	e6060004 */ 	swc1	$f6,0x4($s0)
/*    16518:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*    1651c:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*    16520:	46105102 */ 	mul.s	$f4,$f10,$f16
/*    16524:	00000000 */ 	sll	$zero,$zero,0x0
/*    16528:	46003202 */ 	mul.s	$f8,$f6,$f0
/*    1652c:	00000000 */ 	sll	$zero,$zero,0x0
/*    16530:	46022282 */ 	mul.s	$f10,$f4,$f2
/*    16534:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*    16538:	e7a80028 */ 	swc1	$f8,0x28($sp)
/*    1653c:	46085181 */ 	sub.s	$f6,$f10,$f8
/*    16540:	e6060010 */ 	swc1	$f6,0x10($s0)
/*    16544:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*    16548:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*    1654c:	46002482 */ 	mul.s	$f18,$f4,$f0
/*    16550:	00000000 */ 	sll	$zero,$zero,0x0
/*    16554:	46105202 */ 	mul.s	$f8,$f10,$f16
/*    16558:	00000000 */ 	sll	$zero,$zero,0x0
/*    1655c:	46029182 */ 	mul.s	$f6,$f18,$f2
/*    16560:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*    16564:	46083100 */ 	add.s	$f4,$f6,$f8
/*    16568:	e6040014 */ 	swc1	$f4,0x14($s0)
/*    1656c:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*    16570:	e60c001c */ 	swc1	$f12,0x1c($s0)
/*    16574:	460e5182 */ 	mul.s	$f6,$f10,$f14
/*    16578:	e6060018 */ 	swc1	$f6,0x18($s0)
/*    1657c:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*    16580:	46024102 */ 	mul.s	$f4,$f8,$f2
/*    16584:	46122280 */ 	add.s	$f10,$f4,$f18
/*    16588:	e60a0020 */ 	swc1	$f10,0x20($s0)
/*    1658c:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*    16590:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*    16594:	46023202 */ 	mul.s	$f8,$f6,$f2
/*    16598:	46044281 */ 	sub.s	$f10,$f8,$f4
/*    1659c:	44812000 */ 	mtc1	$at,$f4
/*    165a0:	e60a0024 */ 	swc1	$f10,0x24($s0)
/*    165a4:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*    165a8:	e60c002c */ 	swc1	$f12,0x2c($s0)
/*    165ac:	e60c0030 */ 	swc1	$f12,0x30($s0)
/*    165b0:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*    165b4:	e60c0034 */ 	swc1	$f12,0x34($s0)
/*    165b8:	e60c0038 */ 	swc1	$f12,0x38($s0)
/*    165bc:	e604003c */ 	swc1	$f4,0x3c($s0)
/*    165c0:	e6080028 */ 	swc1	$f8,0x28($s0)
/*    165c4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    165c8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    165cc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    165d0:	03e00008 */ 	jr	$ra
/*    165d4:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func000165d8
/*    165d8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    165dc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    165e0:	afb10018 */ 	sw	$s1,0x18($sp)
/*    165e4:	afb00014 */ 	sw	$s0,0x14($sp)
/*    165e8:	c4800018 */ 	lwc1	$f0,0x18($a0)
/*    165ec:	c4820028 */ 	lwc1	$f2,0x28($a0)
/*    165f0:	00808025 */ 	or	$s0,$a0,$zero
/*    165f4:	46000102 */ 	mul.s	$f4,$f0,$f0
/*    165f8:	00a08825 */ 	or	$s1,$a1,$zero
/*    165fc:	46021182 */ 	mul.s	$f6,$f2,$f2
/*    16600:	0c012974 */ 	jal	sqrtf
/*    16604:	46062300 */ 	add.s	$f12,$f4,$f6
/*    16608:	3c013600 */ 	lui	$at,0x3600
/*    1660c:	44814000 */ 	mtc1	$at,$f8
/*    16610:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*    16614:	4600403c */ 	c.lt.s	$f8,$f0
/*    16618:	00000000 */ 	sll	$zero,$zero,0x0
/*    1661c:	45020010 */ 	bc1fl	.L00016660
/*    16620:	44805000 */ 	mtc1	$zero,$f10
/*    16624:	c60c0018 */ 	lwc1	$f12,0x18($s0)
/*    16628:	0fc259d4 */ 	jal	func0f096750
/*    1662c:	c60e0028 */ 	lwc1	$f14,0x28($s0)
/*    16630:	e6200000 */ 	swc1	$f0,0x0($s1)
/*    16634:	c60c0008 */ 	lwc1	$f12,0x8($s0)
/*    16638:	c7ae0024 */ 	lwc1	$f14,0x24($sp)
/*    1663c:	0fc259d4 */ 	jal	func0f096750
/*    16640:	46006307 */ 	neg.s	$f12,$f12
/*    16644:	e6200004 */ 	swc1	$f0,0x4($s1)
/*    16648:	c60e0000 */ 	lwc1	$f14,0x0($s0)
/*    1664c:	0fc259d4 */ 	jal	func0f096750
/*    16650:	c60c0004 */ 	lwc1	$f12,0x4($s0)
/*    16654:	1000000e */ 	beqz	$zero,.L00016690
/*    16658:	e6200008 */ 	swc1	$f0,0x8($s1)
/*    1665c:	44805000 */ 	mtc1	$zero,$f10
.L00016660:
/*    16660:	00000000 */ 	sll	$zero,$zero,0x0
/*    16664:	e62a0000 */ 	swc1	$f10,0x0($s1)
/*    16668:	c60c0008 */ 	lwc1	$f12,0x8($s0)
/*    1666c:	c7ae0024 */ 	lwc1	$f14,0x24($sp)
/*    16670:	0fc259d4 */ 	jal	func0f096750
/*    16674:	46006307 */ 	neg.s	$f12,$f12
/*    16678:	e6200004 */ 	swc1	$f0,0x4($s1)
/*    1667c:	c60c0010 */ 	lwc1	$f12,0x10($s0)
/*    16680:	c60e0014 */ 	lwc1	$f14,0x14($s0)
/*    16684:	0fc259d4 */ 	jal	func0f096750
/*    16688:	46006307 */ 	neg.s	$f12,$f12
/*    1668c:	e6200008 */ 	swc1	$f0,0x8($s1)
.L00016690:
/*    16690:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    16694:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    16698:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    1669c:	03e00008 */ 	jr	$ra
/*    166a0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func000166a4
/*    166a4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    166a8:	afa40018 */ 	sw	$a0,0x18($sp)
/*    166ac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    166b0:	00a02025 */ 	or	$a0,$a1,$zero
/*    166b4:	afa60020 */ 	sw	$a2,0x20($sp)
/*    166b8:	0c005923 */ 	jal	func0001648c
/*    166bc:	00c02825 */ 	or	$a1,$a2,$zero
/*    166c0:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    166c4:	0c005775 */ 	jal	func00015dd4
/*    166c8:	8fa50020 */ 	lw	$a1,0x20($sp)
/*    166cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    166d0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    166d4:	03e00008 */ 	jr	$ra
/*    166d8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000166dc
/*    166dc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    166e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    166e4:	afa40018 */ 	sw	$a0,0x18($sp)
/*    166e8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    166ec:	0c00566c */ 	jal	func000159b0
/*    166f0:	00a02025 */ 	or	$a0,$a1,$zero
/*    166f4:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    166f8:	0c005775 */ 	jal	func00015dd4
/*    166fc:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    16700:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    16704:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    16708:	03e00008 */ 	jr	$ra
/*    1670c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00016710
/*    16710:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*    16714:	c4a80018 */ 	lwc1	$f8,0x18($a1)
/*    16718:	c4b00028 */ 	lwc1	$f16,0x28($a1)
/*    1671c:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*    16720:	c4a40038 */ 	lwc1	$f4,0x38($a1)
/*    16724:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*    16728:	00000000 */ 	sll	$zero,$zero,0x0
/*    1672c:	460c8482 */ 	mul.s	$f18,$f16,$f12
/*    16730:	e4a60008 */ 	swc1	$f6,0x8($a1)
/*    16734:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*    16738:	e4aa0018 */ 	swc1	$f10,0x18($a1)
/*    1673c:	e4b20028 */ 	swc1	$f18,0x28($a1)
/*    16740:	03e00008 */ 	jr	$ra
/*    16744:	e4a60038 */ 	swc1	$f6,0x38($a1)
);

GLOBAL_ASM(
glabel func00016748
/*    16748:	3c014780 */ 	lui	$at,0x4780
/*    1674c:	44812000 */ 	mtc1	$at,$f4
/*    16750:	3c018006 */ 	lui	$at,0x8006
/*    16754:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*    16758:	03e00008 */ 	jr	$ra
/*    1675c:	e426ef10 */ 	swc1	$f6,-0x10f0($at)
);

GLOBAL_ASM(
glabel func00016760
/*    16760:	3c028006 */ 	lui	$v0,%hi(var8005ef10)
/*    16764:	2442ef10 */ 	addiu	$v0,$v0,%lo(var8005ef10)
/*    16768:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*    1676c:	3c01800a */ 	lui	$at,0x800a
/*    16770:	e424a4d0 */ 	swc1	$f4,-0x5b30($at)
/*    16774:	3c014780 */ 	lui	$at,0x4780
/*    16778:	44813000 */ 	mtc1	$at,$f6
/*    1677c:	03e00008 */ 	jr	$ra
/*    16780:	e4460000 */ 	swc1	$f6,0x0($v0)
);

GLOBAL_ASM(
glabel func00016784
/*    16784:	3c01800a */ 	lui	$at,0x800a
/*    16788:	c424a4d0 */ 	lwc1	$f4,-0x5b30($at)
/*    1678c:	3c018006 */ 	lui	$at,0x8006
/*    16790:	03e00008 */ 	jr	$ra
/*    16794:	e424ef10 */ 	swc1	$f4,-0x10f0($at)
);

GLOBAL_ASM(
glabel func00016798
/*    16798:	3c0a8006 */ 	lui	$t2,%hi(var8005ef10)
/*    1679c:	254aef10 */ 	addiu	$t2,$t2,%lo(var8005ef10)
/*    167a0:	00001025 */ 	or	$v0,$zero,$zero
/*    167a4:	00803825 */ 	or	$a3,$a0,$zero
/*    167a8:	240b0008 */ 	addiu	$t3,$zero,0x8
/*    167ac:	3c09ffff */ 	lui	$t1,0xffff
.L000167b0:
/*    167b0:	8ce30000 */ 	lw	$v1,0x0($a3)
/*    167b4:	8ce60020 */ 	lw	$a2,0x20($a3)
/*    167b8:	c5480000 */ 	lwc1	$f8,0x0($t2)
/*    167bc:	0069c024 */ 	and	$t8,$v1,$t1
/*    167c0:	0006cc02 */ 	srl	$t9,$a2,0x10
/*    167c4:	03196025 */ 	or	$t4,$t8,$t9
/*    167c8:	448c2000 */ 	mtc1	$t4,$f4
/*    167cc:	000278c0 */ 	sll	$t7,$v0,0x3
/*    167d0:	00af4021 */ 	addu	$t0,$a1,$t7
/*    167d4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    167d8:	00036c00 */ 	sll	$t5,$v1,0x10
/*    167dc:	30ceffff */ 	andi	$t6,$a2,0xffff
/*    167e0:	01ae7825 */ 	or	$t7,$t5,$t6
/*    167e4:	448f8000 */ 	mtc1	$t7,$f16
/*    167e8:	30580001 */ 	andi	$t8,$v0,0x1
/*    167ec:	46083283 */ 	div.s	$f10,$f6,$f8
/*    167f0:	0018c880 */ 	sll	$t9,$t8,0x2
/*    167f4:	01596021 */ 	addu	$t4,$t2,$t9
/*    167f8:	24420001 */ 	addiu	$v0,$v0,0x1
/*    167fc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*    16800:	24e70004 */ 	addiu	$a3,$a3,0x4
/*    16804:	e50a0000 */ 	swc1	$f10,0x0($t0)
/*    16808:	c5840000 */ 	lwc1	$f4,0x0($t4)
/*    1680c:	46049183 */ 	div.s	$f6,$f18,$f4
/*    16810:	144bffe7 */ 	bne	$v0,$t3,.L000167b0
/*    16814:	e5060004 */ 	swc1	$f6,0x4($t0)
/*    16818:	03e00008 */ 	jr	$ra
/*    1681c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00016820
/*    16820:	00001025 */ 	or	$v0,$zero,$zero
/*    16824:	00803825 */ 	or	$a3,$a0,$zero
/*    16828:	240a0008 */ 	addiu	$t2,$zero,0x8
/*    1682c:	3c09ffff */ 	lui	$t1,0xffff
.L00016830:
/*    16830:	8ce30000 */ 	lw	$v1,0x0($a3)
/*    16834:	8ce60020 */ 	lw	$a2,0x20($a3)
/*    16838:	000278c0 */ 	sll	$t7,$v0,0x3
/*    1683c:	0069c024 */ 	and	$t8,$v1,$t1
/*    16840:	00036400 */ 	sll	$t4,$v1,0x10
/*    16844:	0006cc02 */ 	srl	$t9,$a2,0x10
/*    16848:	30cdffff */ 	andi	$t5,$a2,0xffff
/*    1684c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    16850:	03195825 */ 	or	$t3,$t8,$t9
/*    16854:	00af4021 */ 	addu	$t0,$a1,$t7
/*    16858:	018d7025 */ 	or	$t6,$t4,$t5
/*    1685c:	24e70004 */ 	addiu	$a3,$a3,0x4
/*    16860:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*    16864:	144afff2 */ 	bne	$v0,$t2,.L00016830
/*    16868:	ad0e0004 */ 	sw	$t6,0x4($t0)
/*    1686c:	03e00008 */ 	jr	$ra
/*    16870:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00016874
/*    16874:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    16878:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*    1687c:	c7b40058 */ 	lwc1	$f20,0x58($sp)
/*    16880:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*    16884:	c7b6005c */ 	lwc1	$f22,0x5c($sp)
/*    16888:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*    1688c:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*    16890:	c7b80060 */ 	lwc1	$f24,0x60($sp)
/*    16894:	4616b182 */ 	mul.s	$f6,$f22,$f22
/*    16898:	afbf0044 */ 	sw	$ra,0x44($sp)
/*    1689c:	f7be0038 */ 	sdc1	$f30,0x38($sp)
/*    168a0:	4618c282 */ 	mul.s	$f10,$f24,$f24
/*    168a4:	f7bc0030 */ 	sdc1	$f28,0x30($sp)
/*    168a8:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*    168ac:	afa5004c */ 	sw	$a1,0x4c($sp)
/*    168b0:	afa60050 */ 	sw	$a2,0x50($sp)
/*    168b4:	46062200 */ 	add.s	$f8,$f4,$f6
/*    168b8:	afa70054 */ 	sw	$a3,0x54($sp)
/*    168bc:	afa40048 */ 	sw	$a0,0x48($sp)
/*    168c0:	0c012974 */ 	jal	sqrtf
/*    168c4:	460a4300 */ 	add.s	$f12,$f8,$f10
/*    168c8:	3c01bf80 */ 	lui	$at,0xbf80
/*    168cc:	44812000 */ 	mtc1	$at,$f4
/*    168d0:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*    168d4:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*    168d8:	46002083 */ 	div.s	$f2,$f4,$f0
/*    168dc:	4602a502 */ 	mul.s	$f20,$f20,$f2
/*    168e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    168e4:	4602b582 */ 	mul.s	$f22,$f22,$f2
/*    168e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    168ec:	4602c602 */ 	mul.s	$f24,$f24,$f2
/*    168f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    168f4:	46183202 */ 	mul.s	$f8,$f6,$f24
/*    168f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    168fc:	46165102 */ 	mul.s	$f4,$f10,$f22
/*    16900:	46044681 */ 	sub.s	$f26,$f8,$f4
/*    16904:	46145202 */ 	mul.s	$f8,$f10,$f20
/*    16908:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*    1690c:	46182282 */ 	mul.s	$f10,$f4,$f24
/*    16910:	460a4701 */ 	sub.s	$f28,$f8,$f10
/*    16914:	46162202 */ 	mul.s	$f8,$f4,$f22
/*    16918:	00000000 */ 	sll	$zero,$zero,0x0
/*    1691c:	46143282 */ 	mul.s	$f10,$f6,$f20
/*    16920:	460a4781 */ 	sub.s	$f30,$f8,$f10
/*    16924:	461ad102 */ 	mul.s	$f4,$f26,$f26
/*    16928:	00000000 */ 	sll	$zero,$zero,0x0
/*    1692c:	461ce182 */ 	mul.s	$f6,$f28,$f28
/*    16930:	46062200 */ 	add.s	$f8,$f4,$f6
/*    16934:	461ef282 */ 	mul.s	$f10,$f30,$f30
/*    16938:	0c012974 */ 	jal	sqrtf
/*    1693c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*    16940:	3c013f80 */ 	lui	$at,0x3f80
/*    16944:	44812000 */ 	mtc1	$at,$f4
/*    16948:	00000000 */ 	sll	$zero,$zero,0x0
/*    1694c:	46002083 */ 	div.s	$f2,$f4,$f0
/*    16950:	4602d682 */ 	mul.s	$f26,$f26,$f2
/*    16954:	00000000 */ 	sll	$zero,$zero,0x0
/*    16958:	4602e702 */ 	mul.s	$f28,$f28,$f2
/*    1695c:	00000000 */ 	sll	$zero,$zero,0x0
/*    16960:	4602f782 */ 	mul.s	$f30,$f30,$f2
/*    16964:	00000000 */ 	sll	$zero,$zero,0x0
/*    16968:	461eb182 */ 	mul.s	$f6,$f22,$f30
/*    1696c:	00000000 */ 	sll	$zero,$zero,0x0
/*    16970:	461cc202 */ 	mul.s	$f8,$f24,$f28
/*    16974:	00000000 */ 	sll	$zero,$zero,0x0
/*    16978:	461ac282 */ 	mul.s	$f10,$f24,$f26
/*    1697c:	00000000 */ 	sll	$zero,$zero,0x0
/*    16980:	461ea102 */ 	mul.s	$f4,$f20,$f30
/*    16984:	46083381 */ 	sub.s	$f14,$f6,$f8
/*    16988:	461ca182 */ 	mul.s	$f6,$f20,$f28
/*    1698c:	00000000 */ 	sll	$zero,$zero,0x0
/*    16990:	461ab202 */ 	mul.s	$f8,$f22,$f26
/*    16994:	e7ae0064 */ 	swc1	$f14,0x64($sp)
/*    16998:	46045401 */ 	sub.s	$f16,$f10,$f4
/*    1699c:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*    169a0:	00000000 */ 	sll	$zero,$zero,0x0
/*    169a4:	46108102 */ 	mul.s	$f4,$f16,$f16
/*    169a8:	e7b00068 */ 	swc1	$f16,0x68($sp)
/*    169ac:	46083481 */ 	sub.s	$f18,$f6,$f8
/*    169b0:	46129202 */ 	mul.s	$f8,$f18,$f18
/*    169b4:	46045180 */ 	add.s	$f6,$f10,$f4
/*    169b8:	e7b2006c */ 	swc1	$f18,0x6c($sp)
/*    169bc:	0c012974 */ 	jal	sqrtf
/*    169c0:	46083300 */ 	add.s	$f12,$f6,$f8
/*    169c4:	3c013f80 */ 	lui	$at,0x3f80
/*    169c8:	44815000 */ 	mtc1	$at,$f10
/*    169cc:	c7ae0064 */ 	lwc1	$f14,0x64($sp)
/*    169d0:	c7ac0068 */ 	lwc1	$f12,0x68($sp)
/*    169d4:	46005083 */ 	div.s	$f2,$f10,$f0
/*    169d8:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*    169dc:	8fa40048 */ 	lw	$a0,0x48($sp)
/*    169e0:	46027382 */ 	mul.s	$f14,$f14,$f2
/*    169e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    169e8:	46026302 */ 	mul.s	$f12,$f12,$f2
/*    169ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    169f0:	46022182 */ 	mul.s	$f6,$f4,$f2
/*    169f4:	e7a6006c */ 	swc1	$f6,0x6c($sp)
/*    169f8:	e49a0000 */ 	swc1	$f26,0x0($a0)
/*    169fc:	e49c0010 */ 	swc1	$f28,0x10($a0)
/*    16a00:	e49e0020 */ 	swc1	$f30,0x20($a0)
/*    16a04:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*    16a08:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*    16a0c:	461a4282 */ 	mul.s	$f10,$f8,$f26
/*    16a10:	00000000 */ 	sll	$zero,$zero,0x0
/*    16a14:	461c2182 */ 	mul.s	$f6,$f4,$f28
/*    16a18:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*    16a1c:	e48e0004 */ 	swc1	$f14,0x4($a0)
/*    16a20:	e48c0014 */ 	swc1	$f12,0x14($a0)
/*    16a24:	46065200 */ 	add.s	$f8,$f10,$f6
/*    16a28:	461e2282 */ 	mul.s	$f10,$f4,$f30
/*    16a2c:	460a4180 */ 	add.s	$f6,$f8,$f10
/*    16a30:	46003107 */ 	neg.s	$f4,$f6
/*    16a34:	e4840030 */ 	swc1	$f4,0x30($a0)
/*    16a38:	e7ae0064 */ 	swc1	$f14,0x64($sp)
/*    16a3c:	c7ae006c */ 	lwc1	$f14,0x6c($sp)
/*    16a40:	e7ac0068 */ 	swc1	$f12,0x68($sp)
/*    16a44:	c7ac004c */ 	lwc1	$f12,0x4c($sp)
/*    16a48:	c7a20050 */ 	lwc1	$f2,0x50($sp)
/*    16a4c:	c7a00054 */ 	lwc1	$f0,0x54($sp)
/*    16a50:	e48e0024 */ 	swc1	$f14,0x24($a0)
/*    16a54:	c7a80064 */ 	lwc1	$f8,0x64($sp)
/*    16a58:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*    16a5c:	e4940008 */ 	swc1	$f20,0x8($a0)
/*    16a60:	46086282 */ 	mul.s	$f10,$f12,$f8
/*    16a64:	e4960018 */ 	swc1	$f22,0x18($a0)
/*    16a68:	e4980028 */ 	swc1	$f24,0x28($a0)
/*    16a6c:	46061102 */ 	mul.s	$f4,$f2,$f6
/*    16a70:	46045200 */ 	add.s	$f8,$f10,$f4
/*    16a74:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*    16a78:	46064280 */ 	add.s	$f10,$f8,$f6
/*    16a7c:	46146202 */ 	mul.s	$f8,$f12,$f20
/*    16a80:	00000000 */ 	sll	$zero,$zero,0x0
/*    16a84:	46161182 */ 	mul.s	$f6,$f2,$f22
/*    16a88:	46005107 */ 	neg.s	$f4,$f10
/*    16a8c:	e4840034 */ 	swc1	$f4,0x34($a0)
/*    16a90:	46180102 */ 	mul.s	$f4,$f0,$f24
/*    16a94:	44800000 */ 	mtc1	$zero,$f0
/*    16a98:	00000000 */ 	sll	$zero,$zero,0x0
/*    16a9c:	e480000c */ 	swc1	$f0,0xc($a0)
/*    16aa0:	46064280 */ 	add.s	$f10,$f8,$f6
/*    16aa4:	e480001c */ 	swc1	$f0,0x1c($a0)
/*    16aa8:	e480002c */ 	swc1	$f0,0x2c($a0)
/*    16aac:	46045200 */ 	add.s	$f8,$f10,$f4
/*    16ab0:	44815000 */ 	mtc1	$at,$f10
/*    16ab4:	46004187 */ 	neg.s	$f6,$f8
/*    16ab8:	e48a003c */ 	swc1	$f10,0x3c($a0)
/*    16abc:	e4860038 */ 	swc1	$f6,0x38($a0)
/*    16ac0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*    16ac4:	d7be0038 */ 	ldc1	$f30,0x38($sp)
/*    16ac8:	d7bc0030 */ 	ldc1	$f28,0x30($sp)
/*    16acc:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*    16ad0:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*    16ad4:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*    16ad8:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*    16adc:	03e00008 */ 	jr	$ra
/*    16ae0:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func00016ae4
/*    16ae4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    16ae8:	44856000 */ 	mtc1	$a1,$f12
/*    16aec:	44867000 */ 	mtc1	$a2,$f14
/*    16af0:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*    16af4:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*    16af8:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    16afc:	460c3201 */ 	sub.s	$f8,$f6,$f12
/*    16b00:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*    16b04:	c7b20048 */ 	lwc1	$f18,0x48($sp)
/*    16b08:	460e5401 */ 	sub.s	$f16,$f10,$f14
/*    16b0c:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*    16b10:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*    16b14:	46049181 */ 	sub.s	$f6,$f18,$f4
/*    16b18:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*    16b1c:	c7b00054 */ 	lwc1	$f16,0x54($sp)
/*    16b20:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*    16b24:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    16b28:	44056000 */ 	mfc1	$a1,$f12
/*    16b2c:	44067000 */ 	mfc1	$a2,$f14
/*    16b30:	44072000 */ 	mfc1	$a3,$f4
/*    16b34:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*    16b38:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*    16b3c:	e7b00024 */ 	swc1	$f16,0x24($sp)
/*    16b40:	0c005a1d */ 	jal	func00016874
/*    16b44:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    16b48:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    16b4c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    16b50:	03e00008 */ 	jr	$ra
/*    16b54:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00016b58
/*    16b58:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    16b5c:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*    16b60:	c7b40058 */ 	lwc1	$f20,0x58($sp)
/*    16b64:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*    16b68:	c7b6005c */ 	lwc1	$f22,0x5c($sp)
/*    16b6c:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*    16b70:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*    16b74:	c7b80060 */ 	lwc1	$f24,0x60($sp)
/*    16b78:	4616b182 */ 	mul.s	$f6,$f22,$f22
/*    16b7c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*    16b80:	f7be0038 */ 	sdc1	$f30,0x38($sp)
/*    16b84:	4618c282 */ 	mul.s	$f10,$f24,$f24
/*    16b88:	f7bc0030 */ 	sdc1	$f28,0x30($sp)
/*    16b8c:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*    16b90:	afa5004c */ 	sw	$a1,0x4c($sp)
/*    16b94:	afa60050 */ 	sw	$a2,0x50($sp)
/*    16b98:	46062200 */ 	add.s	$f8,$f4,$f6
/*    16b9c:	afa70054 */ 	sw	$a3,0x54($sp)
/*    16ba0:	afa40048 */ 	sw	$a0,0x48($sp)
/*    16ba4:	0c012974 */ 	jal	sqrtf
/*    16ba8:	460a4300 */ 	add.s	$f12,$f8,$f10
/*    16bac:	3c01bf80 */ 	lui	$at,0xbf80
/*    16bb0:	44812000 */ 	mtc1	$at,$f4
/*    16bb4:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*    16bb8:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*    16bbc:	46002083 */ 	div.s	$f2,$f4,$f0
/*    16bc0:	4602a502 */ 	mul.s	$f20,$f20,$f2
/*    16bc4:	00000000 */ 	sll	$zero,$zero,0x0
/*    16bc8:	4602b582 */ 	mul.s	$f22,$f22,$f2
/*    16bcc:	00000000 */ 	sll	$zero,$zero,0x0
/*    16bd0:	4602c602 */ 	mul.s	$f24,$f24,$f2
/*    16bd4:	00000000 */ 	sll	$zero,$zero,0x0
/*    16bd8:	46183202 */ 	mul.s	$f8,$f6,$f24
/*    16bdc:	00000000 */ 	sll	$zero,$zero,0x0
/*    16be0:	46165102 */ 	mul.s	$f4,$f10,$f22
/*    16be4:	46044681 */ 	sub.s	$f26,$f8,$f4
/*    16be8:	46145202 */ 	mul.s	$f8,$f10,$f20
/*    16bec:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*    16bf0:	46182282 */ 	mul.s	$f10,$f4,$f24
/*    16bf4:	460a4701 */ 	sub.s	$f28,$f8,$f10
/*    16bf8:	46162202 */ 	mul.s	$f8,$f4,$f22
/*    16bfc:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c00:	46143282 */ 	mul.s	$f10,$f6,$f20
/*    16c04:	460a4781 */ 	sub.s	$f30,$f8,$f10
/*    16c08:	461ad102 */ 	mul.s	$f4,$f26,$f26
/*    16c0c:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c10:	461ce182 */ 	mul.s	$f6,$f28,$f28
/*    16c14:	46062200 */ 	add.s	$f8,$f4,$f6
/*    16c18:	461ef282 */ 	mul.s	$f10,$f30,$f30
/*    16c1c:	0c012974 */ 	jal	sqrtf
/*    16c20:	460a4300 */ 	add.s	$f12,$f8,$f10
/*    16c24:	3c013f80 */ 	lui	$at,0x3f80
/*    16c28:	44812000 */ 	mtc1	$at,$f4
/*    16c2c:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c30:	46002083 */ 	div.s	$f2,$f4,$f0
/*    16c34:	4602d682 */ 	mul.s	$f26,$f26,$f2
/*    16c38:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c3c:	4602e702 */ 	mul.s	$f28,$f28,$f2
/*    16c40:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c44:	4602f782 */ 	mul.s	$f30,$f30,$f2
/*    16c48:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c4c:	461eb182 */ 	mul.s	$f6,$f22,$f30
/*    16c50:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c54:	461cc202 */ 	mul.s	$f8,$f24,$f28
/*    16c58:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c5c:	461ac282 */ 	mul.s	$f10,$f24,$f26
/*    16c60:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c64:	461ea102 */ 	mul.s	$f4,$f20,$f30
/*    16c68:	46083381 */ 	sub.s	$f14,$f6,$f8
/*    16c6c:	461ca182 */ 	mul.s	$f6,$f20,$f28
/*    16c70:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c74:	461ab202 */ 	mul.s	$f8,$f22,$f26
/*    16c78:	e7ae0064 */ 	swc1	$f14,0x64($sp)
/*    16c7c:	46045401 */ 	sub.s	$f16,$f10,$f4
/*    16c80:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*    16c84:	00000000 */ 	sll	$zero,$zero,0x0
/*    16c88:	46108102 */ 	mul.s	$f4,$f16,$f16
/*    16c8c:	e7b00068 */ 	swc1	$f16,0x68($sp)
/*    16c90:	46083481 */ 	sub.s	$f18,$f6,$f8
/*    16c94:	46129202 */ 	mul.s	$f8,$f18,$f18
/*    16c98:	46045180 */ 	add.s	$f6,$f10,$f4
/*    16c9c:	e7b2006c */ 	swc1	$f18,0x6c($sp)
/*    16ca0:	0c012974 */ 	jal	sqrtf
/*    16ca4:	46083300 */ 	add.s	$f12,$f6,$f8
/*    16ca8:	3c013f80 */ 	lui	$at,0x3f80
/*    16cac:	44815000 */ 	mtc1	$at,$f10
/*    16cb0:	c7ae0064 */ 	lwc1	$f14,0x64($sp)
/*    16cb4:	c7ac0068 */ 	lwc1	$f12,0x68($sp)
/*    16cb8:	46005083 */ 	div.s	$f2,$f10,$f0
/*    16cbc:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*    16cc0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*    16cc4:	44800000 */ 	mtc1	$zero,$f0
/*    16cc8:	46027382 */ 	mul.s	$f14,$f14,$f2
/*    16ccc:	00000000 */ 	sll	$zero,$zero,0x0
/*    16cd0:	46026302 */ 	mul.s	$f12,$f12,$f2
/*    16cd4:	00000000 */ 	sll	$zero,$zero,0x0
/*    16cd8:	46022182 */ 	mul.s	$f6,$f4,$f2
/*    16cdc:	e7a6006c */ 	swc1	$f6,0x6c($sp)
/*    16ce0:	e49a0000 */ 	swc1	$f26,0x0($a0)
/*    16ce4:	e48e0010 */ 	swc1	$f14,0x10($a0)
/*    16ce8:	e4940020 */ 	swc1	$f20,0x20($a0)
/*    16cec:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*    16cf0:	e49c0004 */ 	swc1	$f28,0x4($a0)
/*    16cf4:	e48c0014 */ 	swc1	$f12,0x14($a0)
/*    16cf8:	e4960024 */ 	swc1	$f22,0x24($a0)
/*    16cfc:	e4880030 */ 	swc1	$f8,0x30($a0)
/*    16d00:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*    16d04:	e49e0008 */ 	swc1	$f30,0x8($a0)
/*    16d08:	44814000 */ 	mtc1	$at,$f8
/*    16d0c:	e48a0034 */ 	swc1	$f10,0x34($a0)
/*    16d10:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*    16d14:	e4980028 */ 	swc1	$f24,0x28($a0)
/*    16d18:	e4840018 */ 	swc1	$f4,0x18($a0)
/*    16d1c:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*    16d20:	e480000c */ 	swc1	$f0,0xc($a0)
/*    16d24:	e480001c */ 	swc1	$f0,0x1c($a0)
/*    16d28:	e480002c */ 	swc1	$f0,0x2c($a0)
/*    16d2c:	e488003c */ 	swc1	$f8,0x3c($a0)
/*    16d30:	e4860038 */ 	swc1	$f6,0x38($a0)
/*    16d34:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*    16d38:	d7be0038 */ 	ldc1	$f30,0x38($sp)
/*    16d3c:	d7bc0030 */ 	ldc1	$f28,0x30($sp)
/*    16d40:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*    16d44:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*    16d48:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*    16d4c:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*    16d50:	03e00008 */ 	jr	$ra
/*    16d54:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func00016d58
/*    16d58:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    16d5c:	44856000 */ 	mtc1	$a1,$f12
/*    16d60:	44867000 */ 	mtc1	$a2,$f14
/*    16d64:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*    16d68:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*    16d6c:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    16d70:	460c3201 */ 	sub.s	$f8,$f6,$f12
/*    16d74:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*    16d78:	c7b20048 */ 	lwc1	$f18,0x48($sp)
/*    16d7c:	460e5401 */ 	sub.s	$f16,$f10,$f14
/*    16d80:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*    16d84:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*    16d88:	46049181 */ 	sub.s	$f6,$f18,$f4
/*    16d8c:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*    16d90:	c7b00054 */ 	lwc1	$f16,0x54($sp)
/*    16d94:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*    16d98:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    16d9c:	44056000 */ 	mfc1	$a1,$f12
/*    16da0:	44067000 */ 	mfc1	$a2,$f14
/*    16da4:	44072000 */ 	mfc1	$a3,$f4
/*    16da8:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*    16dac:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*    16db0:	e7b00024 */ 	swc1	$f16,0x24($sp)
/*    16db4:	0c005ad6 */ 	jal	func00016b58
/*    16db8:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    16dbc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    16dc0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    16dc4:	03e00008 */ 	jr	$ra
/*    16dc8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00016dcc
/*    16dcc:	460e6000 */ 	add.s	$f0,$f12,$f14
/*    16dd0:	3c014000 */ 	lui	$at,0x4000
/*    16dd4:	44812000 */ 	mtc1	$at,$f4
/*    16dd8:	3c014800 */ 	lui	$at,0x4800
/*    16ddc:	4604003e */ 	c.le.s	$f0,$f4
/*    16de0:	00000000 */ 	sll	$zero,$zero,0x0
/*    16de4:	45020004 */ 	bc1fl	.L00016df8
/*    16de8:	44813000 */ 	mtc1	$at,$f6
/*    16dec:	03e00008 */ 	jr	$ra
/*    16df0:	3402ffff */ 	dli	$v0,0xffff
/*    16df4:	44813000 */ 	mtc1	$at,$f6
.L00016df8:
/*    16df8:	24020001 */ 	addiu	$v0,$zero,0x1
/*    16dfc:	3c014f00 */ 	lui	$at,0x4f00
/*    16e00:	46003203 */ 	div.s	$f8,$f6,$f0
/*    16e04:	444ef800 */ 	cfc1	$t6,$31
/*    16e08:	44c2f800 */ 	ctc1	$v0,$31
/*    16e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*    16e10:	460042a4 */ 	cvt.w.s	$f10,$f8
/*    16e14:	4442f800 */ 	cfc1	$v0,$31
/*    16e18:	00000000 */ 	sll	$zero,$zero,0x0
/*    16e1c:	30420078 */ 	andi	$v0,$v0,0x78
/*    16e20:	50400013 */ 	beqzl	$v0,.L00016e70
/*    16e24:	44025000 */ 	mfc1	$v0,$f10
/*    16e28:	44815000 */ 	mtc1	$at,$f10
/*    16e2c:	24020001 */ 	addiu	$v0,$zero,0x1
/*    16e30:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*    16e34:	44c2f800 */ 	ctc1	$v0,$31
/*    16e38:	00000000 */ 	sll	$zero,$zero,0x0
/*    16e3c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*    16e40:	4442f800 */ 	cfc1	$v0,$31
/*    16e44:	00000000 */ 	sll	$zero,$zero,0x0
/*    16e48:	30420078 */ 	andi	$v0,$v0,0x78
/*    16e4c:	14400005 */ 	bnez	$v0,.L00016e64
/*    16e50:	00000000 */ 	sll	$zero,$zero,0x0
/*    16e54:	44025000 */ 	mfc1	$v0,$f10
/*    16e58:	3c018000 */ 	lui	$at,0x8000
/*    16e5c:	10000007 */ 	beqz	$zero,.L00016e7c
/*    16e60:	00411025 */ 	or	$v0,$v0,$at
.L00016e64:
/*    16e64:	10000005 */ 	beqz	$zero,.L00016e7c
/*    16e68:	2402ffff */ 	addiu	$v0,$zero,-1
/*    16e6c:	44025000 */ 	mfc1	$v0,$f10
.L00016e70:
/*    16e70:	00000000 */ 	sll	$zero,$zero,0x0
/*    16e74:	0440fffb */ 	bltz	$v0,.L00016e64
/*    16e78:	00000000 */ 	sll	$zero,$zero,0x0
.L00016e7c:
/*    16e7c:	44cef800 */ 	ctc1	$t6,$31
/*    16e80:	304fffff */ 	andi	$t7,$v0,0xffff
/*    16e84:	1de00002 */ 	bgtz	$t7,.L00016e90
/*    16e88:	3043ffff */ 	andi	$v1,$v0,0xffff
/*    16e8c:	24030001 */ 	addiu	$v1,$zero,0x1
.L00016e90:
/*    16e90:	03e00008 */ 	jr	$ra
/*    16e94:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func00016e98
/*    16e98:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    16e9c:	afb00020 */ 	sw	$s0,0x20($sp)
/*    16ea0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*    16ea4:	4485a000 */ 	mtc1	$a1,$f20
/*    16ea8:	00808025 */ 	or	$s0,$a0,$zero
/*    16eac:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    16eb0:	afa60050 */ 	sw	$a2,0x50($sp)
/*    16eb4:	afa70054 */ 	sw	$a3,0x54($sp)
/*    16eb8:	27a60058 */ 	addiu	$a2,$sp,0x58
/*    16ebc:	27a40050 */ 	addiu	$a0,$sp,0x50
/*    16ec0:	0c0011e4 */ 	jal	scaleTo1
/*    16ec4:	27a50054 */ 	addiu	$a1,$sp,0x54
/*    16ec8:	0c0068f7 */ 	jal	sinf
/*    16ecc:	4600a306 */ 	mov.s	$f12,$f20
/*    16ed0:	e7a00044 */ 	swc1	$f0,0x44($sp)
/*    16ed4:	0c0068f4 */ 	jal	cosf
/*    16ed8:	4600a306 */ 	mov.s	$f12,$f20
/*    16edc:	c7a20050 */ 	lwc1	$f2,0x50($sp)
/*    16ee0:	c7ae0058 */ 	lwc1	$f14,0x58($sp)
/*    16ee4:	e7a00040 */ 	swc1	$f0,0x40($sp)
/*    16ee8:	46021102 */ 	mul.s	$f4,$f2,$f2
/*    16eec:	00000000 */ 	sll	$zero,$zero,0x0
/*    16ef0:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*    16ef4:	0c012974 */ 	jal	sqrtf
/*    16ef8:	46062300 */ 	add.s	$f12,$f4,$f6
/*    16efc:	4480a000 */ 	mtc1	$zero,$f20
/*    16f00:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*    16f04:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*    16f08:	46140032 */ 	c.eq.s	$f0,$f20
/*    16f0c:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*    16f10:	4501003e */ 	bc1t	.L0001700c
/*    16f14:	00000000 */ 	sll	$zero,$zero,0x0
/*    16f18:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*    16f1c:	3c013f80 */ 	lui	$at,0x3f80
/*    16f20:	c7a60058 */ 	lwc1	$f6,0x58($sp)
/*    16f24:	46044382 */ 	mul.s	$f14,$f8,$f4
/*    16f28:	44814000 */ 	mtc1	$at,$f8
/*    16f2c:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*    16f30:	00000000 */ 	sll	$zero,$zero,0x0
/*    16f34:	46043482 */ 	mul.s	$f18,$f6,$f4
/*    16f38:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*    16f3c:	e7ae0030 */ 	swc1	$f14,0x30($sp)
/*    16f40:	460e3102 */ 	mul.s	$f4,$f6,$f14
/*    16f44:	e7b0002c */ 	swc1	$f16,0x2c($sp)
/*    16f48:	46008287 */ 	neg.s	$f10,$f16
/*    16f4c:	46004083 */ 	div.s	$f2,$f8,$f0
/*    16f50:	46045201 */ 	sub.s	$f8,$f10,$f4
/*    16f54:	46024182 */ 	mul.s	$f6,$f8,$f2
/*    16f58:	e7a20038 */ 	swc1	$f2,0x38($sp)
/*    16f5c:	e6060000 */ 	swc1	$f6,0x0($s0)
/*    16f60:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*    16f64:	46005102 */ 	mul.s	$f4,$f10,$f0
/*    16f68:	e6040010 */ 	swc1	$f4,0x10($s0)
/*    16f6c:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*    16f70:	e6140030 */ 	swc1	$f20,0x30($s0)
/*    16f74:	46124182 */ 	mul.s	$f6,$f8,$f18
/*    16f78:	46066281 */ 	sub.s	$f10,$f12,$f6
/*    16f7c:	46025102 */ 	mul.s	$f4,$f10,$f2
/*    16f80:	e6040020 */ 	swc1	$f4,0x20($s0)
/*    16f84:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*    16f88:	460c4182 */ 	mul.s	$f6,$f8,$f12
/*    16f8c:	46069281 */ 	sub.s	$f10,$f18,$f6
/*    16f90:	46025102 */ 	mul.s	$f4,$f10,$f2
/*    16f94:	e6040004 */ 	swc1	$f4,0x4($s0)
/*    16f98:	c7a80040 */ 	lwc1	$f8,0x40($sp)
/*    16f9c:	46004182 */ 	mul.s	$f6,$f8,$f0
/*    16fa0:	e6060014 */ 	swc1	$f6,0x14($s0)
/*    16fa4:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*    16fa8:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*    16fac:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*    16fb0:	46045202 */ 	mul.s	$f8,$f10,$f4
/*    16fb4:	46003287 */ 	neg.s	$f10,$f6
/*    16fb8:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*    16fbc:	e6140034 */ 	swc1	$f20,0x34($s0)
/*    16fc0:	46085101 */ 	sub.s	$f4,$f10,$f8
/*    16fc4:	46062282 */ 	mul.s	$f10,$f4,$f6
/*    16fc8:	e60a0024 */ 	swc1	$f10,0x24($s0)
/*    16fcc:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*    16fd0:	46004107 */ 	neg.s	$f4,$f8
/*    16fd4:	e6040008 */ 	swc1	$f4,0x8($s0)
/*    16fd8:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*    16fdc:	46003287 */ 	neg.s	$f10,$f6
/*    16fe0:	44813000 */ 	mtc1	$at,$f6
/*    16fe4:	e60a0018 */ 	swc1	$f10,0x18($s0)
/*    16fe8:	c7a80058 */ 	lwc1	$f8,0x58($sp)
/*    16fec:	e6140038 */ 	swc1	$f20,0x38($s0)
/*    16ff0:	e614000c */ 	swc1	$f20,0xc($s0)
/*    16ff4:	46004107 */ 	neg.s	$f4,$f8
/*    16ff8:	e614001c */ 	swc1	$f20,0x1c($s0)
/*    16ffc:	e6040028 */ 	swc1	$f4,0x28($s0)
/*    17000:	e614002c */ 	swc1	$f20,0x2c($s0)
/*    17004:	10000003 */ 	beqz	$zero,.L00017014
/*    17008:	e606003c */ 	swc1	$f6,0x3c($s0)
.L0001700c:
/*    1700c:	0c00566c */ 	jal	func000159b0
/*    17010:	02002025 */ 	or	$a0,$s0,$zero
.L00017014:
/*    17014:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    17018:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*    1701c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    17020:	03e00008 */ 	jr	$ra
/*    17024:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func00017028
/*    17028:	3c017005 */ 	lui	$at,%hi(var70054200)
/*    1702c:	44856000 */ 	mtc1	$a1,$f12
/*    17030:	c4244200 */ 	lwc1	$f4,%lo(var70054200)($at)
/*    17034:	44867000 */ 	mtc1	$a2,$f14
/*    17038:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1703c:	46046302 */ 	mul.s	$f12,$f12,$f4
/*    17040:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*    17044:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    17048:	44067000 */ 	mfc1	$a2,$f14
/*    1704c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    17050:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*    17054:	44056000 */ 	mfc1	$a1,$f12
/*    17058:	0c013e6c */ 	jal	func0004f9b0
/*    1705c:	00000000 */ 	sll	$zero,$zero,0x0
/*    17060:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    17064:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    17068:	03e00008 */ 	jr	$ra
/*    1706c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00017070
/*    17070:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*    17074:	44800000 */ 	mtc1	$zero,$f0
/*    17078:	3c013f80 */ 	lui	$at,0x3f80
/*    1707c:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*    17080:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*    17084:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*    17088:	c4880020 */ 	lwc1	$f8,0x20($a0)
/*    1708c:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*    17090:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*    17094:	e4aa0010 */ 	swc1	$f10,0x10($a1)
/*    17098:	c4900014 */ 	lwc1	$f16,0x14($a0)
/*    1709c:	44815000 */ 	mtc1	$at,$f10
/*    170a0:	e4b00014 */ 	swc1	$f16,0x14($a1)
/*    170a4:	c4920024 */ 	lwc1	$f18,0x24($a0)
/*    170a8:	e4b20018 */ 	swc1	$f18,0x18($a1)
/*    170ac:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*    170b0:	e4a40020 */ 	swc1	$f4,0x20($a1)
/*    170b4:	c4860018 */ 	lwc1	$f6,0x18($a0)
/*    170b8:	e4a60024 */ 	swc1	$f6,0x24($a1)
/*    170bc:	c4880028 */ 	lwc1	$f8,0x28($a0)
/*    170c0:	e4a00030 */ 	swc1	$f0,0x30($a1)
/*    170c4:	e4a00034 */ 	swc1	$f0,0x34($a1)
/*    170c8:	e4a00038 */ 	swc1	$f0,0x38($a1)
/*    170cc:	e4a0000c */ 	swc1	$f0,0xc($a1)
/*    170d0:	e4a0001c */ 	swc1	$f0,0x1c($a1)
/*    170d4:	e4a0002c */ 	swc1	$f0,0x2c($a1)
/*    170d8:	e4aa003c */ 	swc1	$f10,0x3c($a1)
/*    170dc:	03e00008 */ 	jr	$ra
/*    170e0:	e4a80028 */ 	swc1	$f8,0x28($a1)
);

GLOBAL_ASM(
glabel func000170e4
/*    170e4:	c48c0000 */ 	lwc1	$f12,0x0($a0)
/*    170e8:	c48e0010 */ 	lwc1	$f14,0x10($a0)
/*    170ec:	c4820020 */ 	lwc1	$f2,0x20($a0)
/*    170f0:	460c6102 */ 	mul.s	$f4,$f12,$f12
/*    170f4:	3c013f80 */ 	lui	$at,0x3f80
/*    170f8:	44818000 */ 	mtc1	$at,$f16
/*    170fc:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*    17100:	46062200 */ 	add.s	$f8,$f4,$f6
/*    17104:	46021282 */ 	mul.s	$f10,$f2,$f2
/*    17108:	44801000 */ 	mtc1	$zero,$f2
/*    1710c:	46085000 */ 	add.s	$f0,$f10,$f8
/*    17110:	46008003 */ 	div.s	$f0,$f16,$f0
/*    17114:	46006482 */ 	mul.s	$f18,$f12,$f0
/*    17118:	e4b20000 */ 	swc1	$f18,0x0($a1)
/*    1711c:	c4840010 */ 	lwc1	$f4,0x10($a0)
/*    17120:	46002182 */ 	mul.s	$f6,$f4,$f0
/*    17124:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*    17128:	c48a0020 */ 	lwc1	$f10,0x20($a0)
/*    1712c:	46005202 */ 	mul.s	$f8,$f10,$f0
/*    17130:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*    17134:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*    17138:	46009102 */ 	mul.s	$f4,$f18,$f0
/*    1713c:	e4a40010 */ 	swc1	$f4,0x10($a1)
/*    17140:	c4860014 */ 	lwc1	$f6,0x14($a0)
/*    17144:	46003282 */ 	mul.s	$f10,$f6,$f0
/*    17148:	e4aa0014 */ 	swc1	$f10,0x14($a1)
/*    1714c:	c4880024 */ 	lwc1	$f8,0x24($a0)
/*    17150:	46004482 */ 	mul.s	$f18,$f8,$f0
/*    17154:	e4b20018 */ 	swc1	$f18,0x18($a1)
/*    17158:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*    1715c:	46002182 */ 	mul.s	$f6,$f4,$f0
/*    17160:	e4a60020 */ 	swc1	$f6,0x20($a1)
/*    17164:	c48a0018 */ 	lwc1	$f10,0x18($a0)
/*    17168:	46005202 */ 	mul.s	$f8,$f10,$f0
/*    1716c:	e4a80024 */ 	swc1	$f8,0x24($a1)
/*    17170:	c4920028 */ 	lwc1	$f18,0x28($a0)
/*    17174:	e4b0003c */ 	swc1	$f16,0x3c($a1)
/*    17178:	e4a20030 */ 	swc1	$f2,0x30($a1)
/*    1717c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*    17180:	e4a20034 */ 	swc1	$f2,0x34($a1)
/*    17184:	e4a20038 */ 	swc1	$f2,0x38($a1)
/*    17188:	e4a2000c */ 	swc1	$f2,0xc($a1)
/*    1718c:	e4a2001c */ 	swc1	$f2,0x1c($a1)
/*    17190:	e4a2002c */ 	swc1	$f2,0x2c($a1)
/*    17194:	03e00008 */ 	jr	$ra
/*    17198:	e4a40028 */ 	swc1	$f4,0x28($a1)
);

GLOBAL_ASM(
glabel func0001719c
/*    1719c:	c48c0000 */ 	lwc1	$f12,0x0($a0)
/*    171a0:	c48e0010 */ 	lwc1	$f14,0x10($a0)
/*    171a4:	c4820020 */ 	lwc1	$f2,0x20($a0)
/*    171a8:	460c6102 */ 	mul.s	$f4,$f12,$f12
/*    171ac:	3c013f80 */ 	lui	$at,0x3f80
/*    171b0:	44818000 */ 	mtc1	$at,$f16
/*    171b4:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*    171b8:	46062200 */ 	add.s	$f8,$f4,$f6
/*    171bc:	46021282 */ 	mul.s	$f10,$f2,$f2
/*    171c0:	46085000 */ 	add.s	$f0,$f10,$f8
/*    171c4:	46008003 */ 	div.s	$f0,$f16,$f0
/*    171c8:	46006482 */ 	mul.s	$f18,$f12,$f0
/*    171cc:	e4b20000 */ 	swc1	$f18,0x0($a1)
/*    171d0:	c4840010 */ 	lwc1	$f4,0x10($a0)
/*    171d4:	46002182 */ 	mul.s	$f6,$f4,$f0
/*    171d8:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*    171dc:	c48a0020 */ 	lwc1	$f10,0x20($a0)
/*    171e0:	46005202 */ 	mul.s	$f8,$f10,$f0
/*    171e4:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*    171e8:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*    171ec:	46009102 */ 	mul.s	$f4,$f18,$f0
/*    171f0:	e4a40010 */ 	swc1	$f4,0x10($a1)
/*    171f4:	c4860014 */ 	lwc1	$f6,0x14($a0)
/*    171f8:	46003282 */ 	mul.s	$f10,$f6,$f0
/*    171fc:	e4aa0014 */ 	swc1	$f10,0x14($a1)
/*    17200:	c4880024 */ 	lwc1	$f8,0x24($a0)
/*    17204:	46004482 */ 	mul.s	$f18,$f8,$f0
/*    17208:	e4b20018 */ 	swc1	$f18,0x18($a1)
/*    1720c:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*    17210:	46002182 */ 	mul.s	$f6,$f4,$f0
/*    17214:	e4a60020 */ 	swc1	$f6,0x20($a1)
/*    17218:	c48a0018 */ 	lwc1	$f10,0x18($a0)
/*    1721c:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*    17220:	46005202 */ 	mul.s	$f8,$f10,$f0
/*    17224:	e4a80024 */ 	swc1	$f8,0x24($a1)
/*    17228:	c4920028 */ 	lwc1	$f18,0x28($a0)
/*    1722c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*    17230:	c4b20010 */ 	lwc1	$f18,0x10($a1)
/*    17234:	44800000 */ 	mtc1	$zero,$f0
/*    17238:	e4a40028 */ 	swc1	$f4,0x28($a1)
/*    1723c:	c48a0030 */ 	lwc1	$f10,0x30($a0)
/*    17240:	c4840034 */ 	lwc1	$f4,0x34($a0)
/*    17244:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*    17248:	00000000 */ 	sll	$zero,$zero,0x0
/*    1724c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    17250:	c4a40020 */ 	lwc1	$f4,0x20($a1)
/*    17254:	c4920038 */ 	lwc1	$f18,0x38($a0)
/*    17258:	46064280 */ 	add.s	$f10,$f8,$f6
/*    1725c:	46049202 */ 	mul.s	$f8,$f18,$f4
/*    17260:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*    17264:	460a4180 */ 	add.s	$f6,$f8,$f10
/*    17268:	46003487 */ 	neg.s	$f18,$f6
/*    1726c:	c4a60014 */ 	lwc1	$f6,0x14($a1)
/*    17270:	e4b20030 */ 	swc1	$f18,0x30($a1)
/*    17274:	c4880030 */ 	lwc1	$f8,0x30($a0)
/*    17278:	c4920034 */ 	lwc1	$f18,0x34($a0)
/*    1727c:	46082282 */ 	mul.s	$f10,$f4,$f8
/*    17280:	00000000 */ 	sll	$zero,$zero,0x0
/*    17284:	46123102 */ 	mul.s	$f4,$f6,$f18
/*    17288:	c4b20024 */ 	lwc1	$f18,0x24($a1)
/*    1728c:	c4860038 */ 	lwc1	$f6,0x38($a0)
/*    17290:	46045200 */ 	add.s	$f8,$f10,$f4
/*    17294:	46123282 */ 	mul.s	$f10,$f6,$f18
/*    17298:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*    1729c:	46085100 */ 	add.s	$f4,$f10,$f8
/*    172a0:	46002187 */ 	neg.s	$f6,$f4
/*    172a4:	c4a40018 */ 	lwc1	$f4,0x18($a1)
/*    172a8:	e4a60034 */ 	swc1	$f6,0x34($a1)
/*    172ac:	c48a0030 */ 	lwc1	$f10,0x30($a0)
/*    172b0:	c4860034 */ 	lwc1	$f6,0x34($a0)
/*    172b4:	460a9202 */ 	mul.s	$f8,$f18,$f10
/*    172b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    172bc:	46062482 */ 	mul.s	$f18,$f4,$f6
/*    172c0:	c4a60028 */ 	lwc1	$f6,0x28($a1)
/*    172c4:	c4840038 */ 	lwc1	$f4,0x38($a0)
/*    172c8:	e4b0003c */ 	swc1	$f16,0x3c($a1)
/*    172cc:	e4a0000c */ 	swc1	$f0,0xc($a1)
/*    172d0:	e4a0001c */ 	swc1	$f0,0x1c($a1)
/*    172d4:	e4a0002c */ 	swc1	$f0,0x2c($a1)
/*    172d8:	46124280 */ 	add.s	$f10,$f8,$f18
/*    172dc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    172e0:	460a4480 */ 	add.s	$f18,$f8,$f10
/*    172e4:	46009107 */ 	neg.s	$f4,$f18
/*    172e8:	03e00008 */ 	jr	$ra
/*    172ec:	e4a40038 */ 	swc1	$f4,0x38($a1)
);

GLOBAL_ASM(
glabel func000172f0
/*    172f0:	c4820000 */ 	lwc1	$f2,0x0($a0)
/*    172f4:	c48c0014 */ 	lwc1	$f12,0x14($a0)
/*    172f8:	c48e0028 */ 	lwc1	$f14,0x28($a0)
/*    172fc:	c4900004 */ 	lwc1	$f16,0x4($a0)
/*    17300:	460c1102 */ 	mul.s	$f4,$f2,$f12
/*    17304:	c4920018 */ 	lwc1	$f18,0x18($a0)
/*    17308:	c48a0020 */ 	lwc1	$f10,0x20($a0)
/*    1730c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    17310:	3c013f80 */ 	lui	$at,0x3f80
/*    17314:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*    17318:	c7a80010 */ 	lwc1	$f8,0x10($sp)
/*    1731c:	460e2002 */ 	mul.s	$f0,$f4,$f14
/*    17320:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*    17324:	46128182 */ 	mul.s	$f6,$f16,$f18
/*    17328:	e7aa000c */ 	swc1	$f10,0xc($sp)
/*    1732c:	c7aa000c */ 	lwc1	$f10,0xc($sp)
/*    17330:	46083102 */ 	mul.s	$f4,$f6,$f8
/*    17334:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*    17338:	e7a60008 */ 	swc1	$f6,0x8($sp)
/*    1733c:	c7a60008 */ 	lwc1	$f6,0x8($sp)
/*    17340:	46040000 */ 	add.s	$f0,$f0,$f4
/*    17344:	c4840024 */ 	lwc1	$f4,0x24($a0)
/*    17348:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*    1734c:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*    17350:	46065102 */ 	mul.s	$f4,$f10,$f6
/*    17354:	c7a8001c */ 	lwc1	$f8,0x1c($sp)
/*    17358:	46082102 */ 	mul.s	$f4,$f4,$f8
/*    1735c:	46040000 */ 	add.s	$f0,$f0,$f4
/*    17360:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*    17364:	c7aa0000 */ 	lwc1	$f10,0x0($sp)
/*    17368:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*    1736c:	00000000 */ 	sll	$zero,$zero,0x0
/*    17370:	46068282 */ 	mul.s	$f10,$f16,$f6
/*    17374:	46040001 */ 	sub.s	$f0,$f0,$f4
/*    17378:	460e5102 */ 	mul.s	$f4,$f10,$f14
/*    1737c:	00000000 */ 	sll	$zero,$zero,0x0
/*    17380:	46121182 */ 	mul.s	$f6,$f2,$f18
/*    17384:	44811000 */ 	mtc1	$at,$f2
/*    17388:	46040001 */ 	sub.s	$f0,$f0,$f4
/*    1738c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    17390:	460a0001 */ 	sub.s	$f0,$f0,$f10
/*    17394:	460e6102 */ 	mul.s	$f4,$f12,$f14
/*    17398:	00000000 */ 	sll	$zero,$zero,0x0
/*    1739c:	46124182 */ 	mul.s	$f6,$f8,$f18
/*    173a0:	46001003 */ 	div.s	$f0,$f2,$f0
/*    173a4:	46062281 */ 	sub.s	$f10,$f4,$f6
/*    173a8:	46005202 */ 	mul.s	$f8,$f10,$f0
/*    173ac:	e4a80000 */ 	swc1	$f8,0x0($a1)
/*    173b0:	c4840018 */ 	lwc1	$f4,0x18($a0)
/*    173b4:	c4860020 */ 	lwc1	$f6,0x20($a0)
/*    173b8:	c4880028 */ 	lwc1	$f8,0x28($a0)
/*    173bc:	46062282 */ 	mul.s	$f10,$f4,$f6
/*    173c0:	c4840010 */ 	lwc1	$f4,0x10($a0)
/*    173c4:	46044182 */ 	mul.s	$f6,$f8,$f4
/*    173c8:	46065201 */ 	sub.s	$f8,$f10,$f6
/*    173cc:	46004102 */ 	mul.s	$f4,$f8,$f0
/*    173d0:	e4a40010 */ 	swc1	$f4,0x10($a1)
/*    173d4:	c48a0010 */ 	lwc1	$f10,0x10($a0)
/*    173d8:	c4860024 */ 	lwc1	$f6,0x24($a0)
/*    173dc:	c4840020 */ 	lwc1	$f4,0x20($a0)
/*    173e0:	46065202 */ 	mul.s	$f8,$f10,$f6
/*    173e4:	c48a0014 */ 	lwc1	$f10,0x14($a0)
/*    173e8:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*    173ec:	46064101 */ 	sub.s	$f4,$f8,$f6
/*    173f0:	46002282 */ 	mul.s	$f10,$f4,$f0
/*    173f4:	e4aa0020 */ 	swc1	$f10,0x20($a1)
/*    173f8:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*    173fc:	c4860024 */ 	lwc1	$f6,0x24($a0)
/*    17400:	c48a0028 */ 	lwc1	$f10,0x28($a0)
/*    17404:	46064102 */ 	mul.s	$f4,$f8,$f6
/*    17408:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*    1740c:	46085182 */ 	mul.s	$f6,$f10,$f8
/*    17410:	46062281 */ 	sub.s	$f10,$f4,$f6
/*    17414:	46005202 */ 	mul.s	$f8,$f10,$f0
/*    17418:	e4a80004 */ 	swc1	$f8,0x4($a1)
/*    1741c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*    17420:	c4860028 */ 	lwc1	$f6,0x28($a0)
/*    17424:	c4880020 */ 	lwc1	$f8,0x20($a0)
/*    17428:	46062282 */ 	mul.s	$f10,$f4,$f6
/*    1742c:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*    17430:	46044182 */ 	mul.s	$f6,$f8,$f4
/*    17434:	46065201 */ 	sub.s	$f8,$f10,$f6
/*    17438:	46004102 */ 	mul.s	$f4,$f8,$f0
/*    1743c:	e4a40014 */ 	swc1	$f4,0x14($a1)
/*    17440:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*    17444:	c4860020 */ 	lwc1	$f6,0x20($a0)
/*    17448:	c4840024 */ 	lwc1	$f4,0x24($a0)
/*    1744c:	46065202 */ 	mul.s	$f8,$f10,$f6
/*    17450:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*    17454:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*    17458:	46064101 */ 	sub.s	$f4,$f8,$f6
/*    1745c:	46002282 */ 	mul.s	$f10,$f4,$f0
/*    17460:	e4aa0024 */ 	swc1	$f10,0x24($a1)
/*    17464:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*    17468:	c4860018 */ 	lwc1	$f6,0x18($a0)
/*    1746c:	c48a0014 */ 	lwc1	$f10,0x14($a0)
/*    17470:	46064102 */ 	mul.s	$f4,$f8,$f6
/*    17474:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*    17478:	46085182 */ 	mul.s	$f6,$f10,$f8
/*    1747c:	46062281 */ 	sub.s	$f10,$f4,$f6
/*    17480:	46005202 */ 	mul.s	$f8,$f10,$f0
/*    17484:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*    17488:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*    1748c:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*    17490:	c4880018 */ 	lwc1	$f8,0x18($a0)
/*    17494:	46062282 */ 	mul.s	$f10,$f4,$f6
/*    17498:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*    1749c:	46044182 */ 	mul.s	$f6,$f8,$f4
/*    174a0:	46065201 */ 	sub.s	$f8,$f10,$f6
/*    174a4:	46004102 */ 	mul.s	$f4,$f8,$f0
/*    174a8:	e4a40018 */ 	swc1	$f4,0x18($a1)
/*    174ac:	c4860014 */ 	lwc1	$f6,0x14($a0)
/*    174b0:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*    174b4:	c4840010 */ 	lwc1	$f4,0x10($a0)
/*    174b8:	46065202 */ 	mul.s	$f8,$f10,$f6
/*    174bc:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*    174c0:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*    174c4:	46064101 */ 	sub.s	$f4,$f8,$f6
/*    174c8:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*    174cc:	46002282 */ 	mul.s	$f10,$f4,$f0
/*    174d0:	44800000 */ 	mtc1	$zero,$f0
/*    174d4:	e4aa0028 */ 	swc1	$f10,0x28($a1)
/*    174d8:	c4880030 */ 	lwc1	$f8,0x30($a0)
/*    174dc:	c48a0034 */ 	lwc1	$f10,0x34($a0)
/*    174e0:	46064102 */ 	mul.s	$f4,$f8,$f6
/*    174e4:	c4a80010 */ 	lwc1	$f8,0x10($a1)
/*    174e8:	46085182 */ 	mul.s	$f6,$f10,$f8
/*    174ec:	c4a80020 */ 	lwc1	$f8,0x20($a1)
/*    174f0:	46062280 */ 	add.s	$f10,$f4,$f6
/*    174f4:	c4840038 */ 	lwc1	$f4,0x38($a0)
/*    174f8:	46044182 */ 	mul.s	$f6,$f8,$f4
/*    174fc:	460a3200 */ 	add.s	$f8,$f6,$f10
/*    17500:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*    17504:	46004107 */ 	neg.s	$f4,$f8
/*    17508:	e4a40030 */ 	swc1	$f4,0x30($a1)
/*    1750c:	c4860030 */ 	lwc1	$f6,0x30($a0)
/*    17510:	c4840034 */ 	lwc1	$f4,0x34($a0)
/*    17514:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*    17518:	c4a60014 */ 	lwc1	$f6,0x14($a1)
/*    1751c:	46062282 */ 	mul.s	$f10,$f4,$f6
/*    17520:	c4a60024 */ 	lwc1	$f6,0x24($a1)
/*    17524:	460a4100 */ 	add.s	$f4,$f8,$f10
/*    17528:	c4880038 */ 	lwc1	$f8,0x38($a0)
/*    1752c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    17530:	46045180 */ 	add.s	$f6,$f10,$f4
/*    17534:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*    17538:	46003207 */ 	neg.s	$f8,$f6
/*    1753c:	e4a80034 */ 	swc1	$f8,0x34($a1)
/*    17540:	c48a0030 */ 	lwc1	$f10,0x30($a0)
/*    17544:	c4880034 */ 	lwc1	$f8,0x34($a0)
/*    17548:	46045182 */ 	mul.s	$f6,$f10,$f4
/*    1754c:	c4aa0018 */ 	lwc1	$f10,0x18($a1)
/*    17550:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*    17554:	c4aa0028 */ 	lwc1	$f10,0x28($a1)
/*    17558:	46043200 */ 	add.s	$f8,$f6,$f4
/*    1755c:	c4860038 */ 	lwc1	$f6,0x38($a0)
/*    17560:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    17564:	e4a2003c */ 	swc1	$f2,0x3c($a1)
/*    17568:	46065102 */ 	mul.s	$f4,$f10,$f6
/*    1756c:	e4a0000c */ 	swc1	$f0,0xc($a1)
/*    17570:	e4a0001c */ 	swc1	$f0,0x1c($a1)
/*    17574:	e4a0002c */ 	swc1	$f0,0x2c($a1)
/*    17578:	46082280 */ 	add.s	$f10,$f4,$f8
/*    1757c:	46005187 */ 	neg.s	$f6,$f10
/*    17580:	03e00008 */ 	jr	$ra
/*    17584:	e4a60038 */ 	swc1	$f6,0x38($a1)
);

GLOBAL_ASM(
glabel func00017588
/*    17588:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1758c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    17590:	afa40018 */ 	sw	$a0,0x18($sp)
/*    17594:	0c005d85 */ 	jal	func00017614
/*    17598:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    1759c:	0c005e9e */ 	jal	func00017a78
/*    175a0:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    175a4:	3c013f80 */ 	lui	$at,0x3f80
/*    175a8:	44812000 */ 	mtc1	$at,$f4
/*    175ac:	00002825 */ 	or	$a1,$zero,$zero
/*    175b0:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    175b4:	24040004 */ 	addiu	$a0,$zero,0x4
/*    175b8:	46002083 */ 	div.s	$f2,$f4,$f0
.L000175bc:
/*    175bc:	00001825 */ 	or	$v1,$zero,$zero
/*    175c0:	00c01025 */ 	or	$v0,$a2,$zero
/*    175c4:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*    175c8:	24630001 */ 	addiu	$v1,$v1,0x1
/*    175cc:	46028482 */ 	mul.s	$f18,$f16,$f2
/*    175d0:	50640008 */ 	beql	$v1,$a0,.L000175f4
/*    175d4:	24420004 */ 	addiu	$v0,$v0,0x4
.L000175d8:
/*    175d8:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*    175dc:	24630001 */ 	addiu	$v1,$v1,0x1
/*    175e0:	e4520000 */ 	swc1	$f18,0x0($v0)
/*    175e4:	46028482 */ 	mul.s	$f18,$f16,$f2
/*    175e8:	1464fffb */ 	bne	$v1,$a0,.L000175d8
/*    175ec:	24420004 */ 	addiu	$v0,$v0,0x4
/*    175f0:	24420004 */ 	addiu	$v0,$v0,0x4
.L000175f4:
/*    175f4:	e452fffc */ 	swc1	$f18,-0x4($v0)
/*    175f8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    175fc:	14a4ffef */ 	bne	$a1,$a0,.L000175bc
/*    17600:	24c60010 */ 	addiu	$a2,$a2,0x10
/*    17604:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    17608:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1760c:	03e00008 */ 	jr	$ra
/*    17610:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00017614
/*    17614:	27bdff58 */ 	addiu	$sp,$sp,-168
/*    17618:	afbf0064 */ 	sw	$ra,0x64($sp)
/*    1761c:	afb00060 */ 	sw	$s0,0x60($sp)
/*    17620:	f7be0058 */ 	sdc1	$f30,0x58($sp)
/*    17624:	f7bc0050 */ 	sdc1	$f28,0x50($sp)
/*    17628:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*    1762c:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*    17630:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*    17634:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*    17638:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*    1763c:	c49e0004 */ 	lwc1	$f30,0x4($a0)
/*    17640:	c49c0000 */ 	lwc1	$f28,0x0($a0)
/*    17644:	e7a40084 */ 	swc1	$f4,0x84($sp)
/*    17648:	c486000c */ 	lwc1	$f6,0xc($a0)
/*    1764c:	00a08025 */ 	or	$s0,$a1,$zero
/*    17650:	e7a60074 */ 	swc1	$f6,0x74($sp)
/*    17654:	c4880010 */ 	lwc1	$f8,0x10($a0)
/*    17658:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*    1765c:	c48a0020 */ 	lwc1	$f10,0x20($a0)
/*    17660:	c48c0014 */ 	lwc1	$f12,0x14($a0)
/*    17664:	c482001c */ 	lwc1	$f2,0x1c($a0)
/*    17668:	c4800018 */ 	lwc1	$f0,0x18($a0)
/*    1766c:	e7aa009c */ 	swc1	$f10,0x9c($sp)
/*    17670:	c4960034 */ 	lwc1	$f22,0x34($a0)
/*    17674:	c48e0024 */ 	lwc1	$f14,0x24($a0)
/*    17678:	c492002c */ 	lwc1	$f18,0x2c($a0)
/*    1767c:	c4900028 */ 	lwc1	$f16,0x28($a0)
/*    17680:	c49a003c */ 	lwc1	$f26,0x3c($a0)
/*    17684:	c4980038 */ 	lwc1	$f24,0x38($a0)
/*    17688:	c4940030 */ 	lwc1	$f20,0x30($a0)
/*    1768c:	44070000 */ 	mfc1	$a3,$f0
/*    17690:	4406b000 */ 	mfc1	$a2,$f22
/*    17694:	e7ac0090 */ 	swc1	$f12,0x90($sp)
/*    17698:	e7a20070 */ 	swc1	$f2,0x70($sp)
/*    1769c:	e7a20018 */ 	swc1	$f2,0x18($sp)
/*    176a0:	e7a00080 */ 	swc1	$f0,0x80($sp)
/*    176a4:	e7ae008c */ 	swc1	$f14,0x8c($sp)
/*    176a8:	e7b2006c */ 	swc1	$f18,0x6c($sp)
/*    176ac:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*    176b0:	e7b0007c */ 	swc1	$f16,0x7c($sp)
/*    176b4:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*    176b8:	e7ba0020 */ 	swc1	$f26,0x20($sp)
/*    176bc:	0c005f0b */ 	jal	func00017c2c
/*    176c0:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*    176c4:	e6000000 */ 	swc1	$f0,0x0($s0)
/*    176c8:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*    176cc:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*    176d0:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*    176d4:	4406a000 */ 	mfc1	$a2,$f20
/*    176d8:	e7ba0020 */ 	swc1	$f26,0x20($sp)
/*    176dc:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*    176e0:	8fa70080 */ 	lw	$a3,0x80($sp)
/*    176e4:	c7ae009c */ 	lwc1	$f14,0x9c($sp)
/*    176e8:	c7ac00a0 */ 	lwc1	$f12,0xa0($sp)
/*    176ec:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*    176f0:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*    176f4:	0c005f0b */ 	jal	func00017c2c
/*    176f8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    176fc:	46000287 */ 	neg.s	$f10,$f0
/*    17700:	4406a000 */ 	mfc1	$a2,$f20
/*    17704:	e60a0010 */ 	swc1	$f10,0x10($s0)
/*    17708:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*    1770c:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*    17710:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*    17714:	e7ba0020 */ 	swc1	$f26,0x20($sp)
/*    17718:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*    1771c:	8fa70090 */ 	lw	$a3,0x90($sp)
/*    17720:	c7ae009c */ 	lwc1	$f14,0x9c($sp)
/*    17724:	c7ac00a0 */ 	lwc1	$f12,0xa0($sp)
/*    17728:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*    1772c:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*    17730:	0c005f0b */ 	jal	func00017c2c
/*    17734:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    17738:	e6000020 */ 	swc1	$f0,0x20($s0)
/*    1773c:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*    17740:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*    17744:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
/*    17748:	4406a000 */ 	mfc1	$a2,$f20
/*    1774c:	e7b80020 */ 	swc1	$f24,0x20($sp)
/*    17750:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*    17754:	8fa70090 */ 	lw	$a3,0x90($sp)
/*    17758:	c7ae009c */ 	lwc1	$f14,0x9c($sp)
/*    1775c:	c7ac00a0 */ 	lwc1	$f12,0xa0($sp)
/*    17760:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*    17764:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*    17768:	0c005f0b */ 	jal	func00017c2c
/*    1776c:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*    17770:	46000207 */ 	neg.s	$f8,$f0
/*    17774:	4406b000 */ 	mfc1	$a2,$f22
/*    17778:	e6080030 */ 	swc1	$f8,0x30($s0)
/*    1777c:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*    17780:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*    17784:	c7aa007c */ 	lwc1	$f10,0x7c($sp)
/*    17788:	e7ba0020 */ 	swc1	$f26,0x20($sp)
/*    1778c:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*    17790:	8fa70084 */ 	lw	$a3,0x84($sp)
/*    17794:	c7ae008c */ 	lwc1	$f14,0x8c($sp)
/*    17798:	4600f306 */ 	mov.s	$f12,$f30
/*    1779c:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*    177a0:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*    177a4:	0c005f0b */ 	jal	func00017c2c
/*    177a8:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*    177ac:	46000207 */ 	neg.s	$f8,$f0
/*    177b0:	4406a000 */ 	mfc1	$a2,$f20
/*    177b4:	e6080004 */ 	swc1	$f8,0x4($s0)
/*    177b8:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*    177bc:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*    177c0:	c7aa007c */ 	lwc1	$f10,0x7c($sp)
/*    177c4:	e7ba0020 */ 	swc1	$f26,0x20($sp)
/*    177c8:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*    177cc:	8fa70084 */ 	lw	$a3,0x84($sp)
/*    177d0:	c7ae009c */ 	lwc1	$f14,0x9c($sp)
/*    177d4:	4600e306 */ 	mov.s	$f12,$f28
/*    177d8:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*    177dc:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*    177e0:	0c005f0b */ 	jal	func00017c2c
/*    177e4:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*    177e8:	e6000014 */ 	swc1	$f0,0x14($s0)
/*    177ec:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*    177f0:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*    177f4:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*    177f8:	4406a000 */ 	mfc1	$a2,$f20
/*    177fc:	4407f000 */ 	mfc1	$a3,$f30
/*    17800:	e7ba0020 */ 	swc1	$f26,0x20($sp)
/*    17804:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*    17808:	c7ae009c */ 	lwc1	$f14,0x9c($sp)
/*    1780c:	4600e306 */ 	mov.s	$f12,$f28
/*    17810:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*    17814:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*    17818:	0c005f0b */ 	jal	func00017c2c
/*    1781c:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*    17820:	46000187 */ 	neg.s	$f6,$f0
/*    17824:	4406a000 */ 	mfc1	$a2,$f20
/*    17828:	e6060024 */ 	swc1	$f6,0x24($s0)
/*    1782c:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*    17830:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*    17834:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*    17838:	4407f000 */ 	mfc1	$a3,$f30
/*    1783c:	e7b80020 */ 	swc1	$f24,0x20($sp)
/*    17840:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*    17844:	c7ae009c */ 	lwc1	$f14,0x9c($sp)
/*    17848:	4600e306 */ 	mov.s	$f12,$f28
/*    1784c:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*    17850:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*    17854:	0c005f0b */ 	jal	func00017c2c
/*    17858:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*    1785c:	e6000034 */ 	swc1	$f0,0x34($s0)
/*    17860:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*    17864:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*    17868:	c7a60080 */ 	lwc1	$f6,0x80($sp)
/*    1786c:	4406b000 */ 	mfc1	$a2,$f22
/*    17870:	e7ba0020 */ 	swc1	$f26,0x20($sp)
/*    17874:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*    17878:	8fa70084 */ 	lw	$a3,0x84($sp)
/*    1787c:	c7ae0090 */ 	lwc1	$f14,0x90($sp)
/*    17880:	4600f306 */ 	mov.s	$f12,$f30
/*    17884:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*    17888:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*    1788c:	0c005f0b */ 	jal	func00017c2c
/*    17890:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*    17894:	e6000008 */ 	swc1	$f0,0x8($s0)
/*    17898:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*    1789c:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*    178a0:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*    178a4:	4406a000 */ 	mfc1	$a2,$f20
/*    178a8:	e7ba0020 */ 	swc1	$f26,0x20($sp)
/*    178ac:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*    178b0:	8fa70084 */ 	lw	$a3,0x84($sp)
/*    178b4:	c7ae00a0 */ 	lwc1	$f14,0xa0($sp)
/*    178b8:	4600e306 */ 	mov.s	$f12,$f28
/*    178bc:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*    178c0:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*    178c4:	0c005f0b */ 	jal	func00017c2c
/*    178c8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    178cc:	46000287 */ 	neg.s	$f10,$f0
/*    178d0:	4406a000 */ 	mfc1	$a2,$f20
/*    178d4:	e60a0018 */ 	swc1	$f10,0x18($s0)
/*    178d8:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*    178dc:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*    178e0:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*    178e4:	4407f000 */ 	mfc1	$a3,$f30
/*    178e8:	e7ba0020 */ 	swc1	$f26,0x20($sp)
/*    178ec:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*    178f0:	c7ae00a0 */ 	lwc1	$f14,0xa0($sp)
/*    178f4:	4600e306 */ 	mov.s	$f12,$f28
/*    178f8:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*    178fc:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*    17900:	0c005f0b */ 	jal	func00017c2c
/*    17904:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    17908:	e6000028 */ 	swc1	$f0,0x28($s0)
/*    1790c:	c7a60080 */ 	lwc1	$f6,0x80($sp)
/*    17910:	c7a40084 */ 	lwc1	$f4,0x84($sp)
/*    17914:	c7aa0090 */ 	lwc1	$f10,0x90($sp)
/*    17918:	4406a000 */ 	mfc1	$a2,$f20
/*    1791c:	4407f000 */ 	mfc1	$a3,$f30
/*    17920:	e7b80020 */ 	swc1	$f24,0x20($sp)
/*    17924:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*    17928:	c7ae00a0 */ 	lwc1	$f14,0xa0($sp)
/*    1792c:	4600e306 */ 	mov.s	$f12,$f28
/*    17930:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*    17934:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*    17938:	0c005f0b */ 	jal	func00017c2c
/*    1793c:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*    17940:	46000207 */ 	neg.s	$f8,$f0
/*    17944:	4600f306 */ 	mov.s	$f12,$f30
/*    17948:	e6080038 */ 	swc1	$f8,0x38($s0)
/*    1794c:	c7aa0080 */ 	lwc1	$f10,0x80($sp)
/*    17950:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*    17954:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*    17958:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*    1795c:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*    17960:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*    17964:	8fa70084 */ 	lw	$a3,0x84($sp)
/*    17968:	8fa6008c */ 	lw	$a2,0x8c($sp)
/*    1796c:	c7ae0090 */ 	lwc1	$f14,0x90($sp)
/*    17970:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*    17974:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*    17978:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    1797c:	0c005f0b */ 	jal	func00017c2c
/*    17980:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*    17984:	46000107 */ 	neg.s	$f4,$f0
/*    17988:	4600e306 */ 	mov.s	$f12,$f28
/*    1798c:	e604000c */ 	swc1	$f4,0xc($s0)
/*    17990:	c7a60080 */ 	lwc1	$f6,0x80($sp)
/*    17994:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*    17998:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*    1799c:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*    179a0:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*    179a4:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*    179a8:	8fa70084 */ 	lw	$a3,0x84($sp)
/*    179ac:	8fa6009c */ 	lw	$a2,0x9c($sp)
/*    179b0:	c7ae00a0 */ 	lwc1	$f14,0xa0($sp)
/*    179b4:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*    179b8:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*    179bc:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*    179c0:	0c005f0b */ 	jal	func00017c2c
/*    179c4:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*    179c8:	e600001c */ 	swc1	$f0,0x1c($s0)
/*    179cc:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*    179d0:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*    179d4:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*    179d8:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*    179dc:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*    179e0:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
/*    179e4:	4407f000 */ 	mfc1	$a3,$f30
/*    179e8:	8fa6009c */ 	lw	$a2,0x9c($sp)
/*    179ec:	c7ae00a0 */ 	lwc1	$f14,0xa0($sp)
/*    179f0:	4600e306 */ 	mov.s	$f12,$f28
/*    179f4:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*    179f8:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*    179fc:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*    17a00:	0c005f0b */ 	jal	func00017c2c
/*    17a04:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*    17a08:	46000287 */ 	neg.s	$f10,$f0
/*    17a0c:	4407f000 */ 	mfc1	$a3,$f30
/*    17a10:	e60a002c */ 	swc1	$f10,0x2c($s0)
/*    17a14:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*    17a18:	c7aa0080 */ 	lwc1	$f10,0x80($sp)
/*    17a1c:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*    17a20:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    17a24:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*    17a28:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*    17a2c:	8fa6009c */ 	lw	$a2,0x9c($sp)
/*    17a30:	c7ae00a0 */ 	lwc1	$f14,0xa0($sp)
/*    17a34:	4600e306 */ 	mov.s	$f12,$f28
/*    17a38:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*    17a3c:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*    17a40:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*    17a44:	0c005f0b */ 	jal	func00017c2c
/*    17a48:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*    17a4c:	e600003c */ 	swc1	$f0,0x3c($s0)
/*    17a50:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*    17a54:	8fb00060 */ 	lw	$s0,0x60($sp)
/*    17a58:	d7be0058 */ 	ldc1	$f30,0x58($sp)
/*    17a5c:	d7bc0050 */ 	ldc1	$f28,0x50($sp)
/*    17a60:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*    17a64:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*    17a68:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*    17a6c:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*    17a70:	03e00008 */ 	jr	$ra
/*    17a74:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

GLOBAL_ASM(
glabel func00017a78
/*    17a78:	27bdff80 */ 	addiu	$sp,$sp,-128
/*    17a7c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    17a80:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*    17a84:	e7a40078 */ 	swc1	$f4,0x78($sp)
/*    17a88:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*    17a8c:	e7a60068 */ 	swc1	$f6,0x68($sp)
/*    17a90:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*    17a94:	e7a80058 */ 	swc1	$f8,0x58($sp)
/*    17a98:	c48a000c */ 	lwc1	$f10,0xc($a0)
/*    17a9c:	e7aa0048 */ 	swc1	$f10,0x48($sp)
/*    17aa0:	c4840018 */ 	lwc1	$f4,0x18($a0)
/*    17aa4:	c4800014 */ 	lwc1	$f0,0x14($a0)
/*    17aa8:	c48c0010 */ 	lwc1	$f12,0x10($a0)
/*    17aac:	e7a40054 */ 	swc1	$f4,0x54($sp)
/*    17ab0:	c4860028 */ 	lwc1	$f6,0x28($a0)
/*    17ab4:	c482001c */ 	lwc1	$f2,0x1c($a0)
/*    17ab8:	c4900024 */ 	lwc1	$f16,0x24($a0)
/*    17abc:	c48e0020 */ 	lwc1	$f14,0x20($a0)
/*    17ac0:	e7a60050 */ 	swc1	$f6,0x50($sp)
/*    17ac4:	c4880030 */ 	lwc1	$f8,0x30($a0)
/*    17ac8:	c492002c */ 	lwc1	$f18,0x2c($a0)
/*    17acc:	44070000 */ 	mfc1	$a3,$f0
/*    17ad0:	e7a8006c */ 	swc1	$f8,0x6c($sp)
/*    17ad4:	c48a0034 */ 	lwc1	$f10,0x34($a0)
/*    17ad8:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*    17adc:	e7aa005c */ 	swc1	$f10,0x5c($sp)
/*    17ae0:	c4840038 */ 	lwc1	$f4,0x38($a0)
/*    17ae4:	c7a8005c */ 	lwc1	$f8,0x5c($sp)
/*    17ae8:	e7a4004c */ 	swc1	$f4,0x4c($sp)
/*    17aec:	c486003c */ 	lwc1	$f6,0x3c($a0)
/*    17af0:	e7a00064 */ 	swc1	$f0,0x64($sp)
/*    17af4:	e7ac0074 */ 	swc1	$f12,0x74($sp)
/*    17af8:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*    17afc:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*    17b00:	e7a20044 */ 	swc1	$f2,0x44($sp)
/*    17b04:	e7a20018 */ 	swc1	$f2,0x18($sp)
/*    17b08:	e7b00060 */ 	swc1	$f16,0x60($sp)
/*    17b0c:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*    17b10:	e7ae0070 */ 	swc1	$f14,0x70($sp)
/*    17b14:	e7b20040 */ 	swc1	$f18,0x40($sp)
/*    17b18:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*    17b1c:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*    17b20:	0c005f0b */ 	jal	func00017c2c
/*    17b24:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*    17b28:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*    17b2c:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*    17b30:	c7a80044 */ 	lwc1	$f8,0x44($sp)
/*    17b34:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    17b38:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*    17b3c:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*    17b40:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*    17b44:	c7ac0074 */ 	lwc1	$f12,0x74($sp)
/*    17b48:	c7ae0070 */ 	lwc1	$f14,0x70($sp)
/*    17b4c:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*    17b50:	8fa70054 */ 	lw	$a3,0x54($sp)
/*    17b54:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*    17b58:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*    17b5c:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*    17b60:	0c005f0b */ 	jal	func00017c2c
/*    17b64:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*    17b68:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*    17b6c:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*    17b70:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*    17b74:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*    17b78:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    17b7c:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*    17b80:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*    17b84:	c7ac0064 */ 	lwc1	$f12,0x64($sp)
/*    17b88:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*    17b8c:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*    17b90:	8fa70054 */ 	lw	$a3,0x54($sp)
/*    17b94:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*    17b98:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*    17b9c:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*    17ba0:	0c005f0b */ 	jal	func00017c2c
/*    17ba4:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*    17ba8:	c7a80060 */ 	lwc1	$f8,0x60($sp)
/*    17bac:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*    17bb0:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*    17bb4:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*    17bb8:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*    17bbc:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*    17bc0:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*    17bc4:	c7ac0074 */ 	lwc1	$f12,0x74($sp)
/*    17bc8:	c7ae0070 */ 	lwc1	$f14,0x70($sp)
/*    17bcc:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*    17bd0:	8fa70064 */ 	lw	$a3,0x64($sp)
/*    17bd4:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*    17bd8:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*    17bdc:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*    17be0:	0c005f0b */ 	jal	func00017c2c
/*    17be4:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*    17be8:	c7aa0078 */ 	lwc1	$f10,0x78($sp)
/*    17bec:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*    17bf0:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*    17bf4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    17bf8:	46045182 */ 	mul.s	$f6,$f10,$f4
/*    17bfc:	c7aa0034 */ 	lwc1	$f10,0x34($sp)
/*    17c00:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*    17c04:	c7aa0058 */ 	lwc1	$f10,0x58($sp)
/*    17c08:	46043201 */ 	sub.s	$f8,$f6,$f4
/*    17c0c:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*    17c10:	46065102 */ 	mul.s	$f4,$f10,$f6
/*    17c14:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*    17c18:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*    17c1c:	46044280 */ 	add.s	$f10,$f8,$f4
/*    17c20:	46060202 */ 	mul.s	$f8,$f0,$f6
/*    17c24:	03e00008 */ 	jr	$ra
/*    17c28:	46085001 */ 	sub.s	$f0,$f10,$f8
);

GLOBAL_ASM(
glabel func00017c2c
/*    17c2c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    17c30:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    17c34:	e7ac0028 */ 	swc1	$f12,0x28($sp)
/*    17c38:	e7ae002c */ 	swc1	$f14,0x2c($sp)
/*    17c3c:	afa60030 */ 	sw	$a2,0x30($sp)
/*    17c40:	afa70034 */ 	sw	$a3,0x34($sp)
/*    17c44:	8fa70048 */ 	lw	$a3,0x48($sp)
/*    17c48:	c7ae0030 */ 	lwc1	$f14,0x30($sp)
/*    17c4c:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    17c50:	0c005f2f */ 	jal	func00017cbc
/*    17c54:	c7ac002c */ 	lwc1	$f12,0x2c($sp)
/*    17c58:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*    17c5c:	c7ac0038 */ 	lwc1	$f12,0x38($sp)
/*    17c60:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*    17c64:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    17c68:	0c005f2f */ 	jal	func00017cbc
/*    17c6c:	8fa70048 */ 	lw	$a3,0x48($sp)
/*    17c70:	e7a00020 */ 	swc1	$f0,0x20($sp)
/*    17c74:	c7ac002c */ 	lwc1	$f12,0x2c($sp)
/*    17c78:	c7ae0030 */ 	lwc1	$f14,0x30($sp)
/*    17c7c:	8fa60038 */ 	lw	$a2,0x38($sp)
/*    17c80:	0c005f2f */ 	jal	func00017cbc
/*    17c84:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*    17c88:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*    17c8c:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*    17c90:	c7aa0034 */ 	lwc1	$f10,0x34($sp)
/*    17c94:	c7b0001c */ 	lwc1	$f16,0x1c($sp)
/*    17c98:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    17c9c:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*    17ca0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    17ca4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    17ca8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    17cac:	46060282 */ 	mul.s	$f10,$f0,$f6
/*    17cb0:	46124101 */ 	sub.s	$f4,$f8,$f18
/*    17cb4:	03e00008 */ 	jr	$ra
/*    17cb8:	46045000 */ 	add.s	$f0,$f10,$f4
);

GLOBAL_ASM(
glabel func00017cbc
/*    17cbc:	afa7000c */ 	sw	$a3,0xc($sp)
/*    17cc0:	c7a4000c */ 	lwc1	$f4,0xc($sp)
/*    17cc4:	afa60008 */ 	sw	$a2,0x8($sp)
/*    17cc8:	c7a80008 */ 	lwc1	$f8,0x8($sp)
/*    17ccc:	46046182 */ 	mul.s	$f6,$f12,$f4
/*    17cd0:	00000000 */ 	sll	$zero,$zero,0x0
/*    17cd4:	46087282 */ 	mul.s	$f10,$f14,$f8
/*    17cd8:	03e00008 */ 	jr	$ra
/*    17cdc:	460a3001 */ 	sub.s	$f0,$f6,$f10
);

GLOBAL_ASM(
glabel func00017ce0
/*    17ce0:	3c03800a */ 	lui	$v1,%hi(g_Portals)
/*    17ce4:	8c634cc8 */ 	lw	$v1,%lo(g_Portals)($v1)
/*    17ce8:	000470c0 */ 	sll	$t6,$a0,0x3
/*    17cec:	3c013f80 */ 	lui	$at,0x3f80
/*    17cf0:	006e7821 */ 	addu	$t7,$v1,$t6
/*    17cf4:	95f80000 */ 	lhu	$t8,0x0($t7)
/*    17cf8:	44815000 */ 	mtc1	$at,$f10
/*    17cfc:	3c014f80 */ 	lui	$at,0x4f80
/*    17d00:	03031021 */ 	addu	$v0,$t8,$v1
/*    17d04:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*    17d08:	2443000c */ 	addiu	$v1,$v0,0xc
/*    17d0c:	24070001 */ 	addiu	$a3,$zero,0x1
/*    17d10:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*    17d14:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*    17d18:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*    17d1c:	c448000c */ 	lwc1	$f8,0xc($v0)
/*    17d20:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*    17d24:	90460000 */ 	lbu	$a2,0x0($v0)
/*    17d28:	44868000 */ 	mtc1	$a2,$f16
/*    17d2c:	04c10004 */ 	bgez	$a2,.L00017d40
/*    17d30:	468084a0 */ 	cvt.s.w	$f18,$f16
/*    17d34:	44812000 */ 	mtc1	$at,$f4
/*    17d38:	00000000 */ 	sll	$zero,$zero,0x0
/*    17d3c:	46049480 */ 	add.s	$f18,$f18,$f4
.L00017d40:
/*    17d40:	28c10002 */ 	slti	$at,$a2,0x2
/*    17d44:	14200013 */ 	bnez	$at,.L00017d94
/*    17d48:	46125003 */ 	div.s	$f0,$f10,$f18
/*    17d4c:	c4a60000 */ 	lwc1	$f6,0x0($a1)
.L00017d50:
/*    17d50:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*    17d54:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*    17d58:	24e70001 */ 	addiu	$a3,$a3,0x1
/*    17d5c:	46083400 */ 	add.s	$f16,$f6,$f8
/*    17d60:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*    17d64:	2463000c */ 	addiu	$v1,$v1,12
/*    17d68:	e4b00000 */ 	swc1	$f16,0x0($a1)
/*    17d6c:	c46afffc */ 	lwc1	$f10,-0x4($v1)
/*    17d70:	460a2480 */ 	add.s	$f18,$f4,$f10
/*    17d74:	e4b20004 */ 	swc1	$f18,0x4($a1)
/*    17d78:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*    17d7c:	46083400 */ 	add.s	$f16,$f6,$f8
/*    17d80:	e4b00008 */ 	swc1	$f16,0x8($a1)
/*    17d84:	90590000 */ 	lbu	$t9,0x0($v0)
/*    17d88:	00f9082a */ 	slt	$at,$a3,$t9
/*    17d8c:	5420fff0 */ 	bnezl	$at,.L00017d50
/*    17d90:	c4a60000 */ 	lwc1	$f6,0x0($a1)
.L00017d94:
/*    17d94:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*    17d98:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*    17d9c:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*    17da0:	46002282 */ 	mul.s	$f10,$f4,$f0
/*    17da4:	00000000 */ 	sll	$zero,$zero,0x0
/*    17da8:	46009182 */ 	mul.s	$f6,$f18,$f0
/*    17dac:	00000000 */ 	sll	$zero,$zero,0x0
/*    17db0:	46004402 */ 	mul.s	$f16,$f8,$f0
/*    17db4:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*    17db8:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*    17dbc:	03e00008 */ 	jr	$ra
/*    17dc0:	e4b00008 */ 	swc1	$f16,0x8($a1)
);

GLOBAL_ASM(
glabel func00017dc4
/*    17dc4:	afa50004 */ 	sw	$a1,0x4($sp)
/*    17dc8:	848f0000 */ 	lh	$t7,0x0($a0)
/*    17dcc:	00053400 */ 	sll	$a2,$a1,0x10
/*    17dd0:	00067403 */ 	sra	$t6,$a2,0x10
/*    17dd4:	2407ffff */ 	addiu	$a3,$zero,-1
/*    17dd8:	01c03025 */ 	or	$a2,$t6,$zero
/*    17ddc:	10ef000c */ 	beq	$a3,$t7,.L00017e10
/*    17de0:	00001025 */ 	or	$v0,$zero,$zero
/*    17de4:	0000c040 */ 	sll	$t8,$zero,0x1
/*    17de8:	00981821 */ 	addu	$v1,$a0,$t8
/*    17dec:	84650000 */ 	lh	$a1,0x0($v1)
.L00017df0:
/*    17df0:	10c5000d */ 	beq	$a2,$a1,.L00017e28
/*    17df4:	24420001 */ 	addiu	$v0,$v0,0x1
/*    17df8:	28410010 */ 	slti	$at,$v0,0x10
/*    17dfc:	10200004 */ 	beqz	$at,.L00017e10
/*    17e00:	24630002 */ 	addiu	$v1,$v1,0x2
/*    17e04:	84650000 */ 	lh	$a1,0x0($v1)
/*    17e08:	14e5fff9 */ 	bne	$a3,$a1,.L00017df0
/*    17e0c:	00000000 */ 	sll	$zero,$zero,0x0
.L00017e10:
/*    17e10:	2841000f */ 	slti	$at,$v0,0xf
/*    17e14:	10200004 */ 	beqz	$at,.L00017e28
/*    17e18:	0002c840 */ 	sll	$t9,$v0,0x1
/*    17e1c:	00991821 */ 	addu	$v1,$a0,$t9
/*    17e20:	a4660000 */ 	sh	$a2,0x0($v1)
/*    17e24:	a4670002 */ 	sh	$a3,0x2($v1)
.L00017e28:
/*    17e28:	03e00008 */ 	jr	$ra
/*    17e2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00017e30
/*    17e30:	3c0e800a */ 	lui	$t6,%hi(var800a4ccc)
/*    17e34:	8dce4ccc */ 	lw	$t6,%lo(var800a4ccc)($t6)
/*    17e38:	00046880 */ 	sll	$t5,$a0,0x2
/*    17e3c:	01a46821 */ 	addu	$t5,$t5,$a0
/*    17e40:	000d6880 */ 	sll	$t5,$t5,0x2
/*    17e44:	01ae4021 */ 	addu	$t0,$t5,$t6
/*    17e48:	c50e0000 */ 	lwc1	$f14,0x0($t0)
/*    17e4c:	c4ac0000 */ 	lwc1	$f12,0x0($a1)
/*    17e50:	c5100004 */ 	lwc1	$f16,0x4($t0)
/*    17e54:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*    17e58:	460e6282 */ 	mul.s	$f10,$f12,$f14
/*    17e5c:	c5020008 */ 	lwc1	$f2,0x8($t0)
/*    17e60:	3c07800a */ 	lui	$a3,%hi(g_Portals)
/*    17e64:	46102182 */ 	mul.s	$f6,$f4,$f16
/*    17e68:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*    17e6c:	8ce74cc8 */ 	lw	$a3,%lo(g_Portals)($a3)
/*    17e70:	000478c0 */ 	sll	$t7,$a0,0x3
/*    17e74:	27bdff90 */ 	addiu	$sp,$sp,-112
/*    17e78:	00efc021 */ 	addu	$t8,$a3,$t7
/*    17e7c:	97190000 */ 	lhu	$t9,0x0($t8)
/*    17e80:	46065200 */ 	add.s	$f8,$f10,$f6
/*    17e84:	46041282 */ 	mul.s	$f10,$f2,$f4
/*    17e88:	c4c60000 */ 	lwc1	$f6,0x0($a2)
/*    17e8c:	00001025 */ 	or	$v0,$zero,$zero
/*    17e90:	03271821 */ 	addu	$v1,$t9,$a3
/*    17e94:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*    17e98:	c7a40014 */ 	lwc1	$f4,0x14($sp)
/*    17e9c:	46085000 */ 	add.s	$f0,$f10,$f8
/*    17ea0:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*    17ea4:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*    17ea8:	46104182 */ 	mul.s	$f6,$f8,$f16
/*    17eac:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*    17eb0:	46065100 */ 	add.s	$f4,$f10,$f6
/*    17eb4:	c506000c */ 	lwc1	$f6,0xc($t0)
/*    17eb8:	46081282 */ 	mul.s	$f10,$f2,$f8
/*    17ebc:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*    17ec0:	c7a80010 */ 	lwc1	$f8,0x10($sp)
/*    17ec4:	4608003c */ 	c.lt.s	$f0,$f8
/*    17ec8:	46045480 */ 	add.s	$f18,$f10,$f4
/*    17ecc:	45020008 */ 	bc1fl	.L00017ef0
/*    17ed0:	c5020010 */ 	lwc1	$f2,0x10($t0)
/*    17ed4:	4608903c */ 	c.lt.s	$f18,$f8
/*    17ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*    17edc:	4502000f */ 	bc1fl	.L00017f1c
/*    17ee0:	c7aa0014 */ 	lwc1	$f10,0x14($sp)
/*    17ee4:	10000096 */ 	beqz	$zero,.L00018140
/*    17ee8:	00001025 */ 	or	$v0,$zero,$zero
/*    17eec:	c5020010 */ 	lwc1	$f2,0x10($t0)
.L00017ef0:
/*    17ef0:	4600103c */ 	c.lt.s	$f2,$f0
/*    17ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*    17ef8:	45020008 */ 	bc1fl	.L00017f1c
/*    17efc:	c7aa0014 */ 	lwc1	$f10,0x14($sp)
/*    17f00:	4612103c */ 	c.lt.s	$f2,$f18
/*    17f04:	00000000 */ 	sll	$zero,$zero,0x0
/*    17f08:	45020004 */ 	bc1fl	.L00017f1c
/*    17f0c:	c7aa0014 */ 	lwc1	$f10,0x14($sp)
/*    17f10:	1000008b */ 	beqz	$zero,.L00018140
/*    17f14:	00001025 */ 	or	$v0,$zero,$zero
/*    17f18:	c7aa0014 */ 	lwc1	$f10,0x14($sp)
.L00017f1c:
/*    17f1c:	3c013f00 */ 	lui	$at,0x3f00
/*    17f20:	24670004 */ 	addiu	$a3,$v1,0x4
/*    17f24:	460c5101 */ 	sub.s	$f4,$f10,$f12
/*    17f28:	00e02025 */ 	or	$a0,$a3,$zero
/*    17f2c:	24690010 */ 	addiu	$t1,$v1,0x10
/*    17f30:	00005025 */ 	or	$t2,$zero,$zero
/*    17f34:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*    17f38:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*    17f3c:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*    17f40:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    17f44:	46083281 */ 	sub.s	$f10,$f6,$f8
/*    17f48:	e7aa0064 */ 	swc1	$f10,0x64($sp)
/*    17f4c:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*    17f50:	c4c40008 */ 	lwc1	$f4,0x8($a2)
/*    17f54:	46120280 */ 	add.s	$f10,$f0,$f18
/*    17f58:	46062201 */ 	sub.s	$f8,$f4,$f6
/*    17f5c:	44812000 */ 	mtc1	$at,$f4
/*    17f60:	3c018008 */ 	lui	$at,0x8008
/*    17f64:	46045182 */ 	mul.s	$f6,$f10,$f4
/*    17f68:	e7a80068 */ 	swc1	$f8,0x68($sp)
/*    17f6c:	c508000c */ 	lwc1	$f8,0xc($t0)
/*    17f70:	46083281 */ 	sub.s	$f10,$f6,$f8
/*    17f74:	e42afcb4 */ 	swc1	$f10,-0x34c($at)
/*    17f78:	906b0000 */ 	lbu	$t3,0x0($v1)
/*    17f7c:	59600068 */ 	blezl	$t3,.L00018120
/*    17f80:	c506000c */ 	lwc1	$f6,0xc($t0)
/*    17f84:	44806000 */ 	mtc1	$zero,$f12
/*    17f88:	24060002 */ 	addiu	$a2,$zero,0x2
.L00017f8c:
/*    17f8c:	254f0001 */ 	addiu	$t7,$t2,0x1
/*    17f90:	55eb0003 */ 	bnel	$t7,$t3,.L00017fa0
/*    17f94:	c5240000 */ 	lwc1	$f4,0x0($t1)
/*    17f98:	00e04825 */ 	or	$t1,$a3,$zero
/*    17f9c:	c5240000 */ 	lwc1	$f4,0x0($t1)
.L00017fa0:
/*    17fa0:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*    17fa4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*    17fa8:	e7a80048 */ 	swc1	$f8,0x48($sp)
/*    17fac:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*    17fb0:	c52a0004 */ 	lwc1	$f10,0x4($t1)
/*    17fb4:	46045181 */ 	sub.s	$f6,$f10,$f4
/*    17fb8:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*    17fbc:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*    17fc0:	c5280008 */ 	lwc1	$f8,0x8($t1)
/*    17fc4:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*    17fc8:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*    17fcc:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*    17fd0:	e7a60000 */ 	swc1	$f6,0x0($sp)
/*    17fd4:	e7a40050 */ 	swc1	$f4,0x50($sp)
/*    17fd8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    17fdc:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*    17fe0:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*    17fe4:	e7a80004 */ 	swc1	$f8,0x4($sp)
/*    17fe8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    17fec:	e7a40008 */ 	swc1	$f4,0x8($sp)
/*    17ff0:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    17ff4:	46085281 */ 	sub.s	$f10,$f10,$f8
/*    17ff8:	c7a80060 */ 	lwc1	$f8,0x60($sp)
/*    17ffc:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*    18000:	e7aa0004 */ 	swc1	$f10,0x4($sp)
/*    18004:	46083182 */ 	mul.s	$f6,$f6,$f8
/*    18008:	c7aa0048 */ 	lwc1	$f10,0x48($sp)
/*    1800c:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*    18010:	46043181 */ 	sub.s	$f6,$f6,$f4
/*    18014:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*    18018:	46045282 */ 	mul.s	$f10,$f10,$f4
/*    1801c:	c7a40000 */ 	lwc1	$f4,0x0($sp)
/*    18020:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*    18024:	46044202 */ 	mul.s	$f8,$f8,$f4
/*    18028:	46085101 */ 	sub.s	$f4,$f10,$f8
/*    1802c:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*    18030:	460a5202 */ 	mul.s	$f8,$f10,$f10
/*    18034:	e7a4003c */ 	swc1	$f4,0x3c($sp)
/*    18038:	46063282 */ 	mul.s	$f10,$f6,$f6
/*    1803c:	460a4180 */ 	add.s	$f6,$f8,$f10
/*    18040:	46042202 */ 	mul.s	$f8,$f4,$f4
/*    18044:	c7aa0034 */ 	lwc1	$f10,0x34($sp)
/*    18048:	46064080 */ 	add.s	$f2,$f8,$f6
/*    1804c:	460c1032 */ 	c.eq.s	$f2,$f12
/*    18050:	00000000 */ 	sll	$zero,$zero,0x0
/*    18054:	45020004 */ 	bc1fl	.L00018068
/*    18058:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*    1805c:	10000038 */ 	beqz	$zero,.L00018140
/*    18060:	00001025 */ 	or	$v0,$zero,$zero
/*    18064:	c4840000 */ 	lwc1	$f4,0x0($a0)
.L00018068:
/*    18068:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*    1806c:	46045202 */ 	mul.s	$f8,$f10,$f4
/*    18070:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*    18074:	46043102 */ 	mul.s	$f4,$f6,$f4
/*    18078:	46044200 */ 	add.s	$f8,$f8,$f4
/*    1807c:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*    18080:	e7aa0008 */ 	swc1	$f10,0x8($sp)
/*    18084:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*    18088:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*    1808c:	46082100 */ 	add.s	$f4,$f4,$f8
/*    18090:	c7a80008 */ 	lwc1	$f8,0x8($sp)
/*    18094:	e7a60008 */ 	swc1	$f6,0x8($sp)
/*    18098:	e7a40040 */ 	swc1	$f4,0x40($sp)
/*    1809c:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*    180a0:	46064202 */ 	mul.s	$f8,$f8,$f6
/*    180a4:	c7a60008 */ 	lwc1	$f6,0x8($sp)
/*    180a8:	e7aa0008 */ 	swc1	$f10,0x8($sp)
/*    180ac:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*    180b0:	460a3182 */ 	mul.s	$f6,$f6,$f10
/*    180b4:	46064280 */ 	add.s	$f10,$f8,$f6
/*    180b8:	c7a60008 */ 	lwc1	$f6,0x8($sp)
/*    180bc:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*    180c0:	46064202 */ 	mul.s	$f8,$f8,$f6
/*    180c4:	460a4080 */ 	add.s	$f2,$f8,$f10
/*    180c8:	4604103c */ 	c.lt.s	$f2,$f4
/*    180cc:	00000000 */ 	sll	$zero,$zero,0x0
/*    180d0:	45000007 */ 	bc1f	.L000180f0
/*    180d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    180d8:	14c20003 */ 	bne	$a2,$v0,.L000180e8
/*    180dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    180e0:	10000017 */ 	beqz	$zero,.L00018140
/*    180e4:	00001025 */ 	or	$v0,$zero,$zero
.L000180e8:
/*    180e8:	10000006 */ 	beqz	$zero,.L00018104
/*    180ec:	24020001 */ 	addiu	$v0,$zero,0x1
.L000180f0:
/*    180f0:	55820004 */ 	bnel	$t4,$v0,.L00018104
/*    180f4:	24020002 */ 	addiu	$v0,$zero,0x2
/*    180f8:	10000011 */ 	beqz	$zero,.L00018140
/*    180fc:	00001025 */ 	or	$v0,$zero,$zero
/*    18100:	24020002 */ 	addiu	$v0,$zero,0x2
.L00018104:
/*    18104:	906b0000 */ 	lbu	$t3,0x0($v1)
/*    18108:	254a0001 */ 	addiu	$t2,$t2,0x1
/*    1810c:	2484000c */ 	addiu	$a0,$a0,0xc
/*    18110:	014b082a */ 	slt	$at,$t2,$t3
/*    18114:	1420ff9d */ 	bnez	$at,.L00017f8c
/*    18118:	2529000c */ 	addiu	$t1,$t1,0xc
/*    1811c:	c506000c */ 	lwc1	$f6,0xc($t0)
.L00018120:
/*    18120:	24030002 */ 	addiu	$v1,$zero,0x2
/*    18124:	4606003c */ 	c.lt.s	$f0,$f6
/*    18128:	00000000 */ 	sll	$zero,$zero,0x0
/*    1812c:	45000003 */ 	bc1f	.L0001813c
/*    18130:	00000000 */ 	sll	$zero,$zero,0x0
/*    18134:	10000001 */ 	beqz	$zero,.L0001813c
/*    18138:	24030001 */ 	addiu	$v1,$zero,0x1
.L0001813c:
/*    1813c:	00601025 */ 	or	$v0,$v1,$zero
.L00018140:
/*    18140:	03e00008 */ 	jr	$ra
/*    18144:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func00018148
/*    18148:	27bdff30 */ 	addiu	$sp,$sp,-208
/*    1814c:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*    18150:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*    18154:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    18158:	afbe0038 */ 	sw	$s8,0x38($sp)
/*    1815c:	afb70034 */ 	sw	$s7,0x34($sp)
/*    18160:	afb60030 */ 	sw	$s6,0x30($sp)
/*    18164:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    18168:	afb40028 */ 	sw	$s4,0x28($sp)
/*    1816c:	afb30024 */ 	sw	$s3,0x24($sp)
/*    18170:	afb20020 */ 	sw	$s2,0x20($sp)
/*    18174:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    18178:	afb00018 */ 	sw	$s0,0x18($sp)
/*    1817c:	afa700dc */ 	sw	$a3,0xdc($sp)
/*    18180:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    18184:	2404ffff */ 	addiu	$a0,$zero,-1
/*    18188:	27a8009c */ 	addiu	$t0,$sp,0x9c
/*    1818c:	27a2005c */ 	addiu	$v0,$sp,0x5c
/*    18190:	00c01825 */ 	or	$v1,$a2,$zero
.L00018194:
/*    18194:	846e0000 */ 	lh	$t6,0x0($v1)
/*    18198:	24420002 */ 	addiu	$v0,$v0,0x2
/*    1819c:	0045082b */ 	sltu	$at,$v0,$a1
/*    181a0:	a50e0000 */ 	sh	$t6,0x0($t0)
/*    181a4:	846f0000 */ 	lh	$t7,0x0($v1)
/*    181a8:	25080002 */ 	addiu	$t0,$t0,0x2
/*    181ac:	a44ffffe */ 	sh	$t7,-0x2($v0)
/*    181b0:	84780000 */ 	lh	$t8,0x0($v1)
/*    181b4:	14980003 */ 	bne	$a0,$t8,.L000181c4
/*    181b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    181bc:	10000004 */ 	beqz	$zero,.L000181d0
/*    181c0:	0000b825 */ 	or	$s7,$zero,$zero
.L000181c4:
/*    181c4:	1420fff3 */ 	bnez	$at,.L00018194
/*    181c8:	24630002 */ 	addiu	$v1,$v1,0x2
/*    181cc:	0000b825 */ 	or	$s7,$zero,$zero
.L000181d0:
/*    181d0:	3c198006 */ 	lui	$t9,%hi(var8005ef20)
/*    181d4:	9339ef20 */ 	lbu	$t9,%lo(var8005ef20)($t9)
/*    181d8:	3c018006 */ 	lui	$at,%hi(var8005ef20)
/*    181dc:	27be007c */ 	addiu	$s8,$sp,0x7c
/*    181e0:	27290001 */ 	addiu	$t1,$t9,0x1
/*    181e4:	a029ef20 */ 	sb	$t1,%lo(var8005ef20)($at)
/*    181e8:	240100ff */ 	addiu	$at,$zero,0xff
/*    181ec:	312a00ff */ 	andi	$t2,$t1,0xff
/*    181f0:	15410010 */ 	bne	$t2,$at,.L00018234
/*    181f4:	3c14800a */ 	lui	$s4,%hi(g_Portals)
/*    181f8:	3c038008 */ 	lui	$v1,%hi(g_NumPortalThings)
/*    181fc:	8c63fc40 */ 	lw	$v1,%lo(g_NumPortalThings)($v1)
/*    18200:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x520)
/*    18204:	2562a4e0 */ 	addiu	$v0,$t3,%lo(g_Vars+0x520)
/*    18208:	18600008 */ 	blez	$v1,.L0001822c
/*    1820c:	00036040 */ 	sll	$t4,$v1,0x1
/*    18210:	01822821 */ 	addu	$a1,$t4,$v0
/*    18214:	240300ff */ 	addiu	$v1,$zero,0xff
.L00018218:
/*    18218:	24420002 */ 	addiu	$v0,$v0,0x2
/*    1821c:	0045082b */ 	sltu	$at,$v0,$a1
/*    18220:	1420fffd */ 	bnez	$at,.L00018218
/*    18224:	a043fffe */ 	sb	$v1,-0x2($v0)
/*    18228:	0000b825 */ 	or	$s7,$zero,$zero
.L0001822c:
/*    1822c:	3c018006 */ 	lui	$at,%hi(var8005ef20)
/*    18230:	a020ef20 */ 	sb	$zero,%lo(var8005ef20)($at)
.L00018234:
/*    18234:	26944cc8 */ 	addiu	$s4,$s4,%lo(g_Portals)
/*    18238:	87b5009c */ 	lh	$s5,0x9c($sp)
.L0001823c:
/*    1823c:	a7a4007c */ 	sh	$a0,0x7c($sp)
/*    18240:	00006840 */ 	sll	$t5,$zero,0x1
/*    18244:	12a40058 */ 	beq	$s5,$a0,.L000183a8
/*    18248:	27ae009c */ 	addiu	$t6,$sp,0x9c
/*    1824c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    18250:	afaf0044 */ 	sw	$t7,0x44($sp)
/*    18254:	0015c8c0 */ 	sll	$t9,$s5,0x3
.L00018258:
/*    18258:	0335c821 */ 	addu	$t9,$t9,$s5
/*    1825c:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*    18260:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*    18264:	0019c880 */ 	sll	$t9,$t9,0x2
/*    18268:	0335c823 */ 	subu	$t9,$t9,$s5
/*    1826c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    18270:	03191021 */ 	addu	$v0,$t8,$t9
/*    18274:	8449000e */ 	lh	$t1,0xe($v0)
/*    18278:	80560005 */ 	lb	$s6,0x5($v0)
/*    1827c:	3c0c800a */ 	lui	$t4,%hi(var800a4ce0)
/*    18280:	8d8c4ce0 */ 	lw	$t4,%lo(var800a4ce0)($t4)
/*    18284:	00095040 */ 	sll	$t2,$t1,0x1
/*    18288:	1ac0003e */ 	blez	$s6,.L00018384
/*    1828c:	014c9821 */ 	addu	$s3,$t2,$t4
.L00018290:
/*    18290:	86720000 */ 	lh	$s2,0x0($s3)
/*    18294:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x520)
/*    18298:	25ada4e0 */ 	addiu	$t5,$t5,%lo(g_Vars+0x520)
/*    1829c:	00125840 */ 	sll	$t3,$s2,0x1
/*    182a0:	016d8821 */ 	addu	$s1,$t3,$t5
/*    182a4:	3c028006 */ 	lui	$v0,%hi(var8005ef20)
/*    182a8:	9042ef20 */ 	lbu	$v0,%lo(var8005ef20)($v0)
/*    182ac:	922e0000 */ 	lbu	$t6,0x0($s1)
/*    182b0:	02402025 */ 	or	$a0,$s2,$zero
/*    182b4:	504e0007 */ 	beql	$v0,$t6,.L000182d4
/*    182b8:	92230001 */ 	lbu	$v1,0x1($s1)
/*    182bc:	a2220000 */ 	sb	$v0,0x0($s1)
/*    182c0:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    182c4:	0c005f8c */ 	jal	func00017e30
/*    182c8:	8fa600d4 */ 	lw	$a2,0xd4($sp)
/*    182cc:	a2220001 */ 	sb	$v0,0x1($s1)
/*    182d0:	92230001 */ 	lbu	$v1,0x1($s1)
.L000182d4:
/*    182d4:	24010001 */ 	addiu	$at,$zero,0x1
/*    182d8:	50600026 */ 	beqzl	$v1,.L00018374
/*    182dc:	26f70001 */ 	addiu	$s7,$s7,0x1
/*    182e0:	54610012 */ 	bnel	$v1,$at,.L0001832c
/*    182e4:	24010002 */ 	addiu	$at,$zero,0x2
/*    182e8:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*    182ec:	001280c0 */ 	sll	$s0,$s2,0x3
/*    182f0:	03c02025 */ 	or	$a0,$s8,$zero
/*    182f4:	01f01021 */ 	addu	$v0,$t7,$s0
/*    182f8:	84580002 */ 	lh	$t8,0x2($v0)
/*    182fc:	56b8000b */ 	bnel	$s5,$t8,.L0001832c
/*    18300:	24010002 */ 	addiu	$at,$zero,0x2
/*    18304:	0c005f71 */ 	jal	func00017dc4
/*    18308:	84450004 */ 	lh	$a1,0x4($v0)
/*    1830c:	8e990000 */ 	lw	$t9,0x0($s4)
/*    18310:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*    18314:	03304821 */ 	addu	$t1,$t9,$s0
/*    18318:	0c005f71 */ 	jal	func00017dc4
/*    1831c:	85250004 */ 	lh	$a1,0x4($t1)
/*    18320:	a2200001 */ 	sb	$zero,0x1($s1)
/*    18324:	300300ff */ 	andi	$v1,$zero,0xff
/*    18328:	24010002 */ 	addiu	$at,$zero,0x2
.L0001832c:
/*    1832c:	54610011 */ 	bnel	$v1,$at,.L00018374
/*    18330:	26f70001 */ 	addiu	$s7,$s7,0x1
/*    18334:	8e8a0000 */ 	lw	$t2,0x0($s4)
/*    18338:	001280c0 */ 	sll	$s0,$s2,0x3
/*    1833c:	03c02025 */ 	or	$a0,$s8,$zero
/*    18340:	01501021 */ 	addu	$v0,$t2,$s0
/*    18344:	844c0004 */ 	lh	$t4,0x4($v0)
/*    18348:	56ac000a */ 	bnel	$s5,$t4,.L00018374
/*    1834c:	26f70001 */ 	addiu	$s7,$s7,0x1
/*    18350:	0c005f71 */ 	jal	func00017dc4
/*    18354:	84450002 */ 	lh	$a1,0x2($v0)
/*    18358:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*    1835c:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*    18360:	01706821 */ 	addu	$t5,$t3,$s0
/*    18364:	0c005f71 */ 	jal	func00017dc4
/*    18368:	85a50002 */ 	lh	$a1,0x2($t5)
/*    1836c:	a2200001 */ 	sb	$zero,0x1($s1)
/*    18370:	26f70001 */ 	addiu	$s7,$s7,0x1
.L00018374:
/*    18374:	16f6ffc6 */ 	bne	$s7,$s6,.L00018290
/*    18378:	26730002 */ 	addiu	$s3,$s3,0x2
/*    1837c:	0000b825 */ 	or	$s7,$zero,$zero
/*    18380:	2404ffff */ 	addiu	$a0,$zero,-1
.L00018384:
/*    18384:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    18388:	27b800bc */ 	addiu	$t8,$sp,0xbc
/*    1838c:	25cf0002 */ 	addiu	$t7,$t6,0x2
/*    18390:	afaf0044 */ 	sw	$t7,0x44($sp)
/*    18394:	85f50000 */ 	lh	$s5,0x0($t7)
/*    18398:	52a40004 */ 	beql	$s5,$a0,.L000183ac
/*    1839c:	87b9007c */ 	lh	$t9,0x7c($sp)
/*    183a0:	55f8ffad */ 	bnel	$t7,$t8,.L00018258
/*    183a4:	0015c8c0 */ 	sll	$t9,$s5,0x3
.L000183a8:
/*    183a8:	87b9007c */ 	lh	$t9,0x7c($sp)
.L000183ac:
/*    183ac:	27a8009c */ 	addiu	$t0,$sp,0x9c
/*    183b0:	27a3007c */ 	addiu	$v1,$sp,0x7c
/*    183b4:	5099000f */ 	beql	$a0,$t9,.L000183f4
/*    183b8:	87ac009c */ 	lh	$t4,0x9c($sp)
.L000183bc:
/*    183bc:	84620000 */ 	lh	$v0,0x0($v1)
/*    183c0:	24630002 */ 	addiu	$v1,$v1,0x2
/*    183c4:	27a9009c */ 	addiu	$t1,$sp,0x9c
/*    183c8:	14820003 */ 	bne	$a0,$v0,.L000183d8
/*    183cc:	a5020000 */ 	sh	$v0,0x0($t0)
/*    183d0:	10000004 */ 	beqz	$zero,.L000183e4
/*    183d4:	0000b825 */ 	or	$s7,$zero,$zero
.L000183d8:
/*    183d8:	1469fff8 */ 	bne	$v1,$t1,.L000183bc
/*    183dc:	25080002 */ 	addiu	$t0,$t0,0x2
/*    183e0:	0000b825 */ 	or	$s7,$zero,$zero
.L000183e4:
/*    183e4:	87aa007c */ 	lh	$t2,0x7c($sp)
/*    183e8:	548aff94 */ 	bnel	$a0,$t2,.L0001823c
/*    183ec:	87b5009c */ 	lh	$s5,0x9c($sp)
/*    183f0:	87ac009c */ 	lh	$t4,0x9c($sp)
.L000183f4:
/*    183f4:	27ab009c */ 	addiu	$t3,$sp,0x9c
/*    183f8:	8fad00dc */ 	lw	$t5,0xdc($sp)
/*    183fc:	508c0010 */ 	beql	$a0,$t4,.L00018440
/*    18400:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*    18404:	00172040 */ 	sll	$a0,$s7,0x1
/*    18408:	008b4021 */ 	addu	$t0,$a0,$t3
/*    1840c:	01a41821 */ 	addu	$v1,$t5,$a0
/*    18410:	2404ffff */ 	addiu	$a0,$zero,-1
/*    18414:	85020000 */ 	lh	$v0,0x0($t0)
/*    18418:	26f70001 */ 	addiu	$s7,$s7,0x1
.L0001841c:
/*    1841c:	2ae10007 */ 	slti	$at,$s7,0x7
/*    18420:	25080002 */ 	addiu	$t0,$t0,0x2
/*    18424:	24630002 */ 	addiu	$v1,$v1,0x2
/*    18428:	10200004 */ 	beqz	$at,.L0001843c
/*    1842c:	a462fffe */ 	sh	$v0,-0x2($v1)
/*    18430:	85020000 */ 	lh	$v0,0x0($t0)
/*    18434:	5482fff9 */ 	bnel	$a0,$v0,.L0001841c
/*    18438:	26f70001 */ 	addiu	$s7,$s7,0x1
.L0001843c:
/*    1843c:	8fae00dc */ 	lw	$t6,0xdc($sp)
.L00018440:
/*    18440:	8fa600e0 */ 	lw	$a2,0xe0($sp)
/*    18444:	00177840 */ 	sll	$t7,$s7,0x1
/*    18448:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    1844c:	10c00013 */ 	beqz	$a2,.L0001849c
/*    18450:	a7040000 */ 	sh	$a0,0x0($t8)
/*    18454:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*    18458:	0000b825 */ 	or	$s7,$zero,$zero
/*    1845c:	27a2005c */ 	addiu	$v0,$sp,0x5c
/*    18460:	18a0000b */ 	blez	$a1,.L00018490
/*    18464:	00c01825 */ 	or	$v1,$a2,$zero
/*    18468:	2404ffff */ 	addiu	$a0,$zero,-1
.L0001846c:
/*    1846c:	84590000 */ 	lh	$t9,0x0($v0)
/*    18470:	24420002 */ 	addiu	$v0,$v0,0x2
/*    18474:	a4790000 */ 	sh	$t9,0x0($v1)
/*    18478:	8449fffe */ 	lh	$t1,-0x2($v0)
/*    1847c:	50890005 */ 	beql	$a0,$t1,.L00018494
/*    18480:	00175040 */ 	sll	$t2,$s7,0x1
/*    18484:	26f70001 */ 	addiu	$s7,$s7,0x1
/*    18488:	16e5fff8 */ 	bne	$s7,$a1,.L0001846c
/*    1848c:	24630002 */ 	addiu	$v1,$v1,0x2
.L00018490:
/*    18490:	00175040 */ 	sll	$t2,$s7,0x1
.L00018494:
/*    18494:	00ca6021 */ 	addu	$t4,$a2,$t2
/*    18498:	a5840000 */ 	sh	$a0,0x0($t4)
.L0001849c:
/*    1849c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    184a0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    184a4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    184a8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    184ac:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    184b0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    184b4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    184b8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    184bc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*    184c0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*    184c4:	03e00008 */ 	jr	$ra
/*    184c8:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
/*    184cc:	00000000 */ 	sll	$zero,$zero,0x0
);

u8 *ailistFindById(s32 ailistid)
{
	s32 lower;
	s32 upper;
	s32 index;

	if (ailistid >= 0x401) {
		if (g_StageSetup.ailists) {
			lower = 0;
			upper = g_NumLvAilists;
			index;

			while (upper >= lower) {
				index = (lower + upper) / 2;

				if (g_StageSetup.ailists[index].id == ailistid) {
					return g_StageSetup.ailists[index].list;
				}

				if (ailistid < g_StageSetup.ailists[index].id) {
					upper = index - 1;
				} else {
					lower = index + 1;
				}
			}
		}
	} else {
		lower = 0;
		upper = g_NumGlobalAilists;
		index;

		while (upper >= lower) {
			index = (lower + upper) / 2;

			if (g_GlobalAilists[index].id == ailistid) {
				return g_GlobalAilists[index].list;
			}

			if (ailistid < g_GlobalAilists[index].id) {
				upper = index - 1;
			} else {
				lower = index + 1;
			}
		}
	}

	return NULL;
}

GLOBAL_ASM(
glabel func000185d0
/*    185d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    185d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    185d8:	8c8e0040 */ 	lw	$t6,0x40($a0)
/*    185dc:	3c028007 */ 	lui	$v0,%hi(var8006992c)
/*    185e0:	000e7980 */ 	sll	$t7,$t6,0x6
/*    185e4:	05e30023 */ 	bgezl	$t7,.L00018674
/*    185e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    185ec:	8c42992c */ 	lw	$v0,%lo(var8006992c)($v0)
/*    185f0:	3c03800a */ 	lui	$v1,%hi(g_StageSetup)
/*    185f4:	5040001f */ 	beqzl	$v0,.L00018674
/*    185f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    185fc:	8c580004 */ 	lw	$t8,0x4($v0)
.L00018600:
/*    18600:	54980019 */ 	bnel	$a0,$t8,.L00018668
/*    18604:	8c42000c */ 	lw	$v0,0xc($v0)
/*    18608:	50a0000d */ 	beqzl	$a1,.L00018640
/*    1860c:	844b0008 */ 	lh	$t3,0x8($v0)
/*    18610:	84590008 */ 	lh	$t9,0x8($v0)
/*    18614:	8449000a */ 	lh	$t1,0xa($v0)
/*    18618:	3c03800a */ 	lui	$v1,%hi(g_StageSetup)
/*    1861c:	8c63d030 */ 	lw	$v1,%lo(g_StageSetup)($v1)
/*    18620:	00194100 */ 	sll	$t0,$t9,0x4
/*    18624:	00095100 */ 	sll	$t2,$t1,0x4
/*    18628:	01432821 */ 	addu	$a1,$t2,$v1
/*    1862c:	0fc4569e */ 	jal	func0f115a78
/*    18630:	01032021 */ 	addu	$a0,$t0,$v1
/*    18634:	1000000f */ 	beqz	$zero,.L00018674
/*    18638:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1863c:	844b0008 */ 	lh	$t3,0x8($v0)
.L00018640:
/*    18640:	844d000a */ 	lh	$t5,0xa($v0)
/*    18644:	8c63d030 */ 	lw	$v1,%lo(g_StageSetup)($v1)
/*    18648:	000b6100 */ 	sll	$t4,$t3,0x4
/*    1864c:	000d7100 */ 	sll	$t6,$t5,0x4
/*    18650:	01c32821 */ 	addu	$a1,$t6,$v1
/*    18654:	0fc45692 */ 	jal	func0f115a48
/*    18658:	01832021 */ 	addu	$a0,$t4,$v1
/*    1865c:	10000005 */ 	beqz	$zero,.L00018674
/*    18660:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    18664:	8c42000c */ 	lw	$v0,0xc($v0)
.L00018668:
/*    18668:	5440ffe5 */ 	bnezl	$v0,.L00018600
/*    1866c:	8c580004 */ 	lw	$t8,0x4($v0)
/*    18670:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00018674:
/*    18674:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    18678:	03e00008 */ 	jr	$ra
/*    1867c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00018680
/*    18680:	27bdf800 */ 	addiu	$sp,$sp,-2048
/*    18684:	afb00780 */ 	sw	$s0,0x780($sp)
/*    18688:	afb10784 */ 	sw	$s1,0x784($sp)
/*    1868c:	afb20788 */ 	sw	$s2,0x788($sp)
/*    18690:	afb3078c */ 	sw	$s3,0x78c($sp)
/*    18694:	afb40790 */ 	sw	$s4,0x790($sp)
/*    18698:	afb50794 */ 	sw	$s5,0x794($sp)
/*    1869c:	afb60798 */ 	sw	$s6,0x798($sp)
/*    186a0:	afb7079c */ 	sw	$s7,0x79c($sp)
/*    186a4:	afbe07a0 */ 	sw	$s8,0x7a0($sp)
/*    186a8:	afbc07a4 */ 	sw	$gp,0x7a4($sp)
/*    186ac:	afbf07a8 */ 	sw	$ra,0x7a8($sp)
/*    186b0:	e7b407b0 */ 	swc1	$f20,0x7b0($sp)
/*    186b4:	e7b507b4 */ 	swc1	$f21,0x7b4($sp)
/*    186b8:	e7b607b8 */ 	swc1	$f22,0x7b8($sp)
/*    186bc:	e7b707bc */ 	swc1	$f23,0x7bc($sp)
/*    186c0:	e7b807c0 */ 	swc1	$f24,0x7c0($sp)
/*    186c4:	e7b907c4 */ 	swc1	$f25,0x7c4($sp)
/*    186c8:	e7ba07c8 */ 	swc1	$f26,0x7c8($sp)
/*    186cc:	e7bb07cc */ 	swc1	$f27,0x7cc($sp)
/*    186d0:	e7bc07d0 */ 	swc1	$f28,0x7d0($sp)
/*    186d4:	e7bd07d4 */ 	swc1	$f29,0x7d4($sp)
/*    186d8:	e7be07d8 */ 	swc1	$f30,0x7d8($sp)
/*    186dc:	e7bf07dc */ 	swc1	$f31,0x7dc($sp)
/*    186e0:	afa007f8 */ 	sw	$zero,0x7f8($sp)
/*    186e4:	3c013f80 */ 	lui	$at,0x3f80
/*    186e8:	4481f800 */ 	mtc1	$at,$f31
/*    186ec:	03a04025 */ 	or	$t0,$sp,$zero
/*    186f0:	8ca90008 */ 	lw	$t1,0x8($a1)
/*    186f4:	9529000e */ 	lhu	$t1,0xe($t1)
.L000186f8:
/*    186f8:	a5000000 */ 	sh	$zero,0x0($t0)
/*    186fc:	2529ffff */ 	addiu	$t1,$t1,-1
/*    18700:	5520fffd */ 	bnezl	$t1,.L000186f8
/*    18704:	25080008 */ 	addiu	$t0,$t0,0x8
/*    18708:	00054020 */ 	add	$t0,$zero,$a1
/*    1870c:	8ca60020 */ 	lw	$a2,0x20($a1)
/*    18710:	10c000ae */ 	beqz	$a2,.L000189cc
/*    18714:	00000000 */ 	sll	$zero,$zero,0x0
/*    18718:	03a04025 */ 	or	$t0,$sp,$zero
/*    1871c:	20090000 */ 	addi	$t1,$zero,0x0
/*    18720:	3c0c8006 */ 	lui	$t4,%hi(var8005f010)
/*    18724:	258cf010 */ 	addiu	$t4,$t4,%lo(var8005f010)
/*    18728:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    1872c:	84cd0000 */ 	lh	$t5,0x0($a2)
/*    18730:	018d6020 */ 	add	$t4,$t4,$t5
/*    18734:	918b0000 */ 	lbu	$t3,0x0($t4)
/*    18738:	3c0c800a */ 	lui	$t4,%hi(var8009a888)
/*    1873c:	258ca888 */ 	addiu	$t4,$t4,%lo(var8009a888)
/*    18740:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    18744:	000b5880 */ 	sll	$t3,$t3,0x2
/*    18748:	018b6020 */ 	add	$t4,$t4,$t3
/*    1874c:	8d8a0000 */ 	lw	$t2,0x0($t4)
/*    18750:	3c0c8006 */ 	lui	$t4,%hi(g_Anims)
/*    18754:	258cf00c */ 	addiu	$t4,$t4,%lo(g_Anims)
/*    18758:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    1875c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    18760:	01ad7020 */ 	add	$t6,$t5,$t5
/*    18764:	01ae6820 */ 	add	$t5,$t5,$t6
/*    18768:	018d6020 */ 	add	$t4,$t4,$t5
/*    1876c:	858d0008 */ 	lh	$t5,0x8($t4)
/*    18770:	918c000a */ 	lbu	$t4,0xa($t4)
/*    18774:	014d5820 */ 	add	$t3,$t2,$t5
/*    18778:	3c0d800a */ 	lui	$t5,%hi(var8009a874)
/*    1877c:	25ada874 */ 	addiu	$t5,$t5,%lo(var8009a874)
/*    18780:	8dad0000 */ 	lw	$t5,0x0($t5)
/*    18784:	114b003b */ 	beq	$t2,$t3,.L00018874
/*    18788:	20020000 */ 	addi	$v0,$zero,0x0
/*    1878c:	90ce0004 */ 	lbu	$t6,0x4($a2)
/*    18790:	000e7080 */ 	sll	$t6,$t6,0x2
/*    18794:	01ae7020 */ 	add	$t6,$t5,$t6
/*    18798:	8dce0000 */ 	lw	$t6,0x0($t6)
/*    1879c:	0c00658d */ 	jal	func00019634
/*    187a0:	201c0000 */ 	addi	$gp,$zero,0x0
/*    187a4:	44800800 */ 	mtc1	$zero,$f1
/*    187a8:	c4c00010 */ 	lwc1	$f0,0x10($a2)
/*    187ac:	46000832 */ 	c.eq.s	$f1,$f0
/*    187b0:	45010030 */ 	bc1t	.L00018874
/*    187b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    187b8:	03a04025 */ 	or	$t0,$sp,$zero
/*    187bc:	250803c0 */ 	addiu	$t0,$t0,0x3c0
/*    187c0:	8ca90008 */ 	lw	$t1,0x8($a1)
/*    187c4:	9529000e */ 	lhu	$t1,0xe($t1)
.L000187c8:
/*    187c8:	a5000000 */ 	sh	$zero,0x0($t0)
/*    187cc:	2529ffff */ 	addiu	$t1,$t1,-1
/*    187d0:	5520fffd */ 	bnezl	$t1,.L000187c8
/*    187d4:	25080008 */ 	addiu	$t0,$t0,0x8
/*    187d8:	3c014580 */ 	lui	$at,0x4580
/*    187dc:	44811000 */ 	mtc1	$at,$f2
/*    187e0:	03a04025 */ 	or	$t0,$sp,$zero
/*    187e4:	46020002 */ 	mul.s	$f0,$f0,$f2
/*    187e8:	20090000 */ 	addi	$t1,$zero,0x0
/*    187ec:	4600000d */ 	trunc.w.s	$f0,$f0
/*    187f0:	3c0c8006 */ 	lui	$t4,%hi(var8005f010)
/*    187f4:	258cf010 */ 	addiu	$t4,$t4,%lo(var8005f010)
/*    187f8:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    187fc:	84cd0000 */ 	lh	$t5,0x0($a2)
/*    18800:	018d6020 */ 	add	$t4,$t4,$t5
/*    18804:	918b0000 */ 	lbu	$t3,0x0($t4)
/*    18808:	3c0c800a */ 	lui	$t4,%hi(var8009a888)
/*    1880c:	258ca888 */ 	addiu	$t4,$t4,%lo(var8009a888)
/*    18810:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    18814:	000b5880 */ 	sll	$t3,$t3,0x2
/*    18818:	018b6020 */ 	add	$t4,$t4,$t3
/*    1881c:	8d8a0000 */ 	lw	$t2,0x0($t4)
/*    18820:	3c0c8006 */ 	lui	$t4,%hi(g_Anims)
/*    18824:	258cf00c */ 	addiu	$t4,$t4,%lo(g_Anims)
/*    18828:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    1882c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    18830:	01ad7020 */ 	add	$t6,$t5,$t5
/*    18834:	01ae6820 */ 	add	$t5,$t5,$t6
/*    18838:	018d6020 */ 	add	$t4,$t4,$t5
/*    1883c:	858d0008 */ 	lh	$t5,0x8($t4)
/*    18840:	918c000a */ 	lbu	$t4,0xa($t4)
/*    18844:	014d5820 */ 	add	$t3,$t2,$t5
/*    18848:	3c0d800a */ 	lui	$t5,%hi(var8009a874)
/*    1884c:	25ada874 */ 	addiu	$t5,$t5,%lo(var8009a874)
/*    18850:	8dad0000 */ 	lw	$t5,0x0($t5)
/*    18854:	114b0007 */ 	beq	$t2,$t3,.L00018874
/*    18858:	20020000 */ 	addi	$v0,$zero,0x0
/*    1885c:	90ce0005 */ 	lbu	$t6,0x5($a2)
/*    18860:	000e7080 */ 	sll	$t6,$t6,0x2
/*    18864:	01ae7020 */ 	add	$t6,$t5,$t6
/*    18868:	8dce0000 */ 	lw	$t6,0x0($t6)
/*    1886c:	0c006637 */ 	jal	func000198dc
/*    18870:	201c0000 */ 	addi	$gp,$zero,0x0
.L00018874:
/*    18874:	44800800 */ 	mtc1	$zero,$f1
/*    18878:	c4c00054 */ 	lwc1	$f0,0x54($a2)
/*    1887c:	46010032 */ 	c.eq.s	$f0,$f1
/*    18880:	45010052 */ 	bc1t	.L000189cc
/*    18884:	e7a007e0 */ 	swc1	$f0,0x7e0($sp)
/*    18888:	03a04025 */ 	or	$t0,$sp,$zero
/*    1888c:	250803c0 */ 	addiu	$t0,$t0,0x3c0
/*    18890:	20090000 */ 	addi	$t1,$zero,0x0
/*    18894:	3c0c8006 */ 	lui	$t4,%hi(var8005f010)
/*    18898:	258cf010 */ 	addiu	$t4,$t4,%lo(var8005f010)
/*    1889c:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    188a0:	84cd0002 */ 	lh	$t5,0x2($a2)
/*    188a4:	018d6020 */ 	add	$t4,$t4,$t5
/*    188a8:	918b0000 */ 	lbu	$t3,0x0($t4)
/*    188ac:	3c0c800a */ 	lui	$t4,%hi(var8009a888)
/*    188b0:	258ca888 */ 	addiu	$t4,$t4,%lo(var8009a888)
/*    188b4:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    188b8:	000b5880 */ 	sll	$t3,$t3,0x2
/*    188bc:	018b6020 */ 	add	$t4,$t4,$t3
/*    188c0:	8d8a0000 */ 	lw	$t2,0x0($t4)
/*    188c4:	3c0c8006 */ 	lui	$t4,%hi(g_Anims)
/*    188c8:	258cf00c */ 	addiu	$t4,$t4,%lo(g_Anims)
/*    188cc:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    188d0:	000d6880 */ 	sll	$t5,$t5,0x2
/*    188d4:	01ad7020 */ 	add	$t6,$t5,$t5
/*    188d8:	01ae6820 */ 	add	$t5,$t5,$t6
/*    188dc:	018d6020 */ 	add	$t4,$t4,$t5
/*    188e0:	858d0008 */ 	lh	$t5,0x8($t4)
/*    188e4:	918c000a */ 	lbu	$t4,0xa($t4)
/*    188e8:	014d5820 */ 	add	$t3,$t2,$t5
/*    188ec:	3c0d800a */ 	lui	$t5,%hi(var8009a874)
/*    188f0:	25ada874 */ 	addiu	$t5,$t5,%lo(var8009a874)
/*    188f4:	8dad0000 */ 	lw	$t5,0x0($t5)
/*    188f8:	114b0034 */ 	beq	$t2,$t3,.L000189cc
/*    188fc:	20020000 */ 	addi	$v0,$zero,0x0
/*    18900:	90ce0006 */ 	lbu	$t6,0x6($a2)
/*    18904:	000e7080 */ 	sll	$t6,$t6,0x2
/*    18908:	01ae7020 */ 	add	$t6,$t5,$t6
/*    1890c:	8dce0000 */ 	lw	$t6,0x0($t6)
/*    18910:	0c00658d */ 	jal	func00019634
/*    18914:	201c0000 */ 	addi	$gp,$zero,0x0
/*    18918:	44800800 */ 	mtc1	$zero,$f1
/*    1891c:	c4c00034 */ 	lwc1	$f0,0x34($a2)
/*    18920:	46000832 */ 	c.eq.s	$f1,$f0
/*    18924:	45010029 */ 	bc1t	.L000189cc
/*    18928:	00000000 */ 	sll	$zero,$zero,0x0
/*    1892c:	3c014580 */ 	lui	$at,0x4580
/*    18930:	44811000 */ 	mtc1	$at,$f2
/*    18934:	03a04025 */ 	or	$t0,$sp,$zero
/*    18938:	250803c0 */ 	addiu	$t0,$t0,0x3c0
/*    1893c:	46020002 */ 	mul.s	$f0,$f0,$f2
/*    18940:	20090000 */ 	addi	$t1,$zero,0x0
/*    18944:	4600000d */ 	trunc.w.s	$f0,$f0
/*    18948:	3c0c8006 */ 	lui	$t4,%hi(var8005f010)
/*    1894c:	258cf010 */ 	addiu	$t4,$t4,%lo(var8005f010)
/*    18950:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    18954:	84cd0002 */ 	lh	$t5,0x2($a2)
/*    18958:	018d6020 */ 	add	$t4,$t4,$t5
/*    1895c:	918b0000 */ 	lbu	$t3,0x0($t4)
/*    18960:	3c0c800a */ 	lui	$t4,%hi(var8009a888)
/*    18964:	258ca888 */ 	addiu	$t4,$t4,%lo(var8009a888)
/*    18968:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    1896c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    18970:	018b6020 */ 	add	$t4,$t4,$t3
/*    18974:	8d8a0000 */ 	lw	$t2,0x0($t4)
/*    18978:	3c0c8006 */ 	lui	$t4,%hi(g_Anims)
/*    1897c:	258cf00c */ 	addiu	$t4,$t4,%lo(g_Anims)
/*    18980:	8d8c0000 */ 	lw	$t4,0x0($t4)
/*    18984:	000d6880 */ 	sll	$t5,$t5,0x2
/*    18988:	01ad7020 */ 	add	$t6,$t5,$t5
/*    1898c:	01ae6820 */ 	add	$t5,$t5,$t6
/*    18990:	018d6020 */ 	add	$t4,$t4,$t5
/*    18994:	858d0008 */ 	lh	$t5,0x8($t4)
/*    18998:	918c000a */ 	lbu	$t4,0xa($t4)
/*    1899c:	014d5820 */ 	add	$t3,$t2,$t5
/*    189a0:	3c0d800a */ 	lui	$t5,%hi(var8009a874)
/*    189a4:	25ada874 */ 	addiu	$t5,$t5,%lo(var8009a874)
/*    189a8:	8dad0000 */ 	lw	$t5,0x0($t5)
/*    189ac:	114b0007 */ 	beq	$t2,$t3,.L000189cc
/*    189b0:	20020000 */ 	addi	$v0,$zero,0x0
/*    189b4:	90ce0007 */ 	lbu	$t6,0x7($a2)
/*    189b8:	000e7080 */ 	sll	$t6,$t6,0x2
/*    189bc:	01ae7020 */ 	add	$t6,$t5,$t6
/*    189c0:	8dce0000 */ 	lw	$t6,0x0($t6)
/*    189c4:	0c006637 */ 	jal	func000198dc
/*    189c8:	201c0000 */ 	addi	$gp,$zero,0x0
.L000189cc:
/*    189cc:	8ca70008 */ 	lw	$a3,0x8($a1)
/*    189d0:	8cfc0000 */ 	lw	$gp,0x0($a3)
/*    189d4:	8cf60004 */ 	lw	$s6,0x4($a3)
/*    189d8:	03a0b825 */ 	or	$s7,$sp,$zero
/*    189dc:	138002fa */ 	beqz	$gp,.L000195c8
/*    189e0:	24420001 */ 	addiu	$v0,$v0,0x1
/*    189e4:	3c098006 */ 	lui	$t1,%hi(var8005ef40)
/*    189e8:	2529ef40 */ 	addiu	$t1,$t1,%lo(var8005ef40)
/*    189ec:	97880000 */ 	lhu	$t0,0x0($gp)
/*    189f0:	310800ff */ 	andi	$t0,$t0,0xff
/*    189f4:	01094020 */ 	add	$t0,$t0,$t1
/*    189f8:	3c098006 */ 	lui	$t1,%hi(var8005ef5c)
/*    189fc:	2529ef5c */ 	addiu	$t1,$t1,%lo(var8005ef5c)
/*    18a00:	91080000 */ 	lbu	$t0,0x0($t0)
/*    18a04:	01284020 */ 	add	$t0,$t1,$t0
/*    18a08:	8d090000 */ 	lw	$t1,0x0($t0)
/*    18a0c:	97880000 */ 	lhu	$t0,0x0($gp)
/*    18a10:	01200008 */ 	jr	$t1
/*    18a14:	310800ff */ 	andi	$t0,$t0,0xff
/*    18a18:	138002eb */ 	beqz	$gp,.L000195c8
/*    18a1c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    18a20:	87880000 */ 	lh	$t0,0x0($gp)
/*    18a24:	310800ff */ 	andi	$t0,$t0,0xff
/*    18a28:	afa007e4 */ 	sw	$zero,0x7e4($sp)
/*    18a2c:	10a00177 */ 	beqz	$a1,.L0001900c
/*    18a30:	8f880004 */ 	lw	$t0,0x4($gp)
/*    18a34:	10c00168 */ 	beqz	$a2,.L00018fd8
/*    18a38:	9509000c */ 	lhu	$t1,0xc($t0)
/*    18a3c:	94ca0000 */ 	lhu	$t2,0x0($a2)
/*    18a40:	4480e800 */ 	mtc1	$zero,$f29
/*    18a44:	c7be07e0 */ 	lwc1	$f30,0x7e0($sp)
/*    18a48:	461ee832 */ 	c.eq.s	$f29,$f30
/*    18a4c:	45010056 */ 	bc1t	.L00018ba8
/*    18a50:	00000000 */ 	sll	$zero,$zero,0x0
/*    18a54:	90ca0008 */ 	lbu	$t2,0x8($a2)
/*    18a58:	11400015 */ 	beqz	$t2,.L00018ab0
/*    18a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*    18a60:	8eca0004 */ 	lw	$t2,0x4($s6)
/*    18a64:	00094840 */ 	sll	$t1,$t1,0x1
/*    18a68:	01495020 */ 	add	$t2,$t2,$t1
/*    18a6c:	91490001 */ 	lbu	$t1,0x1($t2)
/*    18a70:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18a74:	02e94020 */ 	add	$t0,$s7,$t1
/*    18a78:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    18a7c:	3c0a0001 */ 	lui	$t2,0x1
/*    18a80:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    18a84:	15800002 */ 	bnez	$t4,.L00018a90
/*    18a88:	014c6022 */ 	sub	$t4,$t2,$t4
/*    18a8c:	200c0000 */ 	addi	$t4,$zero,0x0
.L00018a90:
/*    18a90:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    18a94:	15600002 */ 	bnez	$t3,.L00018aa0
/*    18a98:	014b5822 */ 	sub	$t3,$t2,$t3
/*    18a9c:	200b0000 */ 	addi	$t3,$zero,0x0
.L00018aa0:
/*    18aa0:	316bffff */ 	andi	$t3,$t3,0xffff
/*    18aa4:	318cffff */ 	andi	$t4,$t4,0xffff
/*    18aa8:	080062b2 */ 	j	0x18ac8
/*    18aac:	950a0002 */ 	lhu	$t2,0x2($t0)
.L00018ab0:
/*    18ab0:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18ab4:	02e94020 */ 	add	$t0,$s7,$t1
/*    18ab8:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    18abc:	950a0002 */ 	lhu	$t2,0x2($t0)
/*    18ac0:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    18ac4:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    18ac8:	8f900004 */ 	lw	$s0,0x4($gp)
/*    18acc:	90d10009 */ 	lbu	$s1,0x9($a2)
/*    18ad0:	12200015 */ 	beqz	$s1,.L00018b28
/*    18ad4:	9609000c */ 	lhu	$t1,0xc($s0)
/*    18ad8:	8ed00004 */ 	lw	$s0,0x4($s6)
/*    18adc:	00094840 */ 	sll	$t1,$t1,0x1
/*    18ae0:	02098020 */ 	add	$s0,$s0,$t1
/*    18ae4:	92090001 */ 	lbu	$t1,0x1($s0)
/*    18ae8:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18aec:	02e94020 */ 	add	$t0,$s7,$t1
/*    18af0:	3c100001 */ 	lui	$s0,0x1
/*    18af4:	951403c6 */ 	lhu	$s4,0x3c6($t0)
/*    18af8:	16800002 */ 	bnez	$s4,.L00018b04
/*    18afc:	0214a022 */ 	sub	$s4,$s0,$s4
/*    18b00:	20140000 */ 	addi	$s4,$zero,0x0
.L00018b04:
/*    18b04:	951303c4 */ 	lhu	$s3,0x3c4($t0)
/*    18b08:	16600002 */ 	bnez	$s3,.L00018b14
/*    18b0c:	02139822 */ 	sub	$s3,$s0,$s3
/*    18b10:	20130000 */ 	addi	$s3,$zero,0x0
.L00018b14:
/*    18b14:	3273ffff */ 	andi	$s3,$s3,0xffff
/*    18b18:	3294ffff */ 	andi	$s4,$s4,0xffff
/*    18b1c:	95100002 */ 	lhu	$s0,0x2($t0)
/*    18b20:	10000006 */ 	beqz	$zero,.L00018b3c
/*    18b24:	951203c2 */ 	lhu	$s2,0x3c2($t0)
.L00018b28:
/*    18b28:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18b2c:	02e94020 */ 	add	$t0,$s7,$t1
/*    18b30:	951203c2 */ 	lhu	$s2,0x3c2($t0)
/*    18b34:	951303c4 */ 	lhu	$s3,0x3c4($t0)
/*    18b38:	951403c6 */ 	lhu	$s4,0x3c6($t0)
.L00018b3c:
/*    18b3c:	0c006809 */ 	jal	func0001a024
/*    18b40:	afa807e8 */ 	sw	$t0,0x7e8($sp)
/*    18b44:	0c0067cb */ 	jal	func00019f2c
/*    18b48:	00000000 */ 	sll	$zero,$zero,0x0
/*    18b4c:	46000406 */ 	mov.s	$f16,$f0
/*    18b50:	46000c46 */ 	mov.s	$f17,$f1
/*    18b54:	46001486 */ 	mov.s	$f18,$f2
/*    18b58:	46001cc6 */ 	mov.s	$f19,$f3
/*    18b5c:	02405025 */ 	or	$t2,$s2,$zero
/*    18b60:	02605825 */ 	or	$t3,$s3,$zero
/*    18b64:	0c006809 */ 	jal	func0001a024
/*    18b68:	02806025 */ 	or	$t4,$s4,$zero
/*    18b6c:	0c0067cb */ 	jal	func00019f2c
/*    18b70:	00000000 */ 	sll	$zero,$zero,0x0
/*    18b74:	0c006777 */ 	jal	func00019ddc
/*    18b78:	c7be07e0 */ 	lwc1	$f30,0x7e0($sp)
/*    18b7c:	24080001 */ 	addiu	$t0,$zero,0x1
/*    18b80:	afa807e4 */ 	sw	$t0,0x7e4($sp)
/*    18b84:	8fa807e8 */ 	lw	$t0,0x7e8($sp)
/*    18b88:	e7a007e8 */ 	swc1	$f0,0x7e8($sp)
/*    18b8c:	e7a107ec */ 	swc1	$f1,0x7ec($sp)
/*    18b90:	e7a207f0 */ 	swc1	$f2,0x7f0($sp)
/*    18b94:	e7a307f4 */ 	swc1	$f3,0x7f4($sp)
/*    18b98:	0c006844 */ 	jal	func0001a110
/*    18b9c:	00000000 */ 	sll	$zero,$zero,0x0
/*    18ba0:	0800631b */ 	j	0x18c6c
/*    18ba4:	00000000 */ 	sll	$zero,$zero,0x0
.L00018ba8:
/*    18ba8:	90ca0008 */ 	lbu	$t2,0x8($a2)
/*    18bac:	11400015 */ 	beqz	$t2,.L00018c04
/*    18bb0:	00000000 */ 	sll	$zero,$zero,0x0
/*    18bb4:	8eca0004 */ 	lw	$t2,0x4($s6)
/*    18bb8:	00094840 */ 	sll	$t1,$t1,0x1
/*    18bbc:	01495020 */ 	add	$t2,$t2,$t1
/*    18bc0:	91490001 */ 	lbu	$t1,0x1($t2)
/*    18bc4:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18bc8:	02e94020 */ 	add	$t0,$s7,$t1
/*    18bcc:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    18bd0:	3c0a0001 */ 	lui	$t2,0x1
/*    18bd4:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    18bd8:	15800002 */ 	bnez	$t4,.L00018be4
/*    18bdc:	014c6022 */ 	sub	$t4,$t2,$t4
/*    18be0:	200c0000 */ 	addi	$t4,$zero,0x0
.L00018be4:
/*    18be4:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    18be8:	15600002 */ 	bnez	$t3,.L00018bf4
/*    18bec:	014b5822 */ 	sub	$t3,$t2,$t3
/*    18bf0:	200b0000 */ 	addi	$t3,$zero,0x0
.L00018bf4:
/*    18bf4:	316bffff */ 	andi	$t3,$t3,0xffff
/*    18bf8:	318cffff */ 	andi	$t4,$t4,0xffff
/*    18bfc:	10000007 */ 	beqz	$zero,.L00018c1c
/*    18c00:	950a0002 */ 	lhu	$t2,0x2($t0)
.L00018c04:
/*    18c04:	000948c0 */ 	sll	$t1,$t1,0x3
/*    18c08:	02e94020 */ 	add	$t0,$s7,$t1
/*    18c0c:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    18c10:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    18c14:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    18c18:	950a0002 */ 	lhu	$t2,0x2($t0)
.L00018c1c:
/*    18c1c:	33cd0001 */ 	andi	$t5,$s8,0x1
/*    18c20:	15a0000b */ 	bnez	$t5,.L00018c50
/*    18c24:	000a8020 */ 	add	$s0,$zero,$t2
/*    18c28:	44806800 */ 	mtc1	$zero,$f13
/*    18c2c:	4600fb06 */ 	mov.s	$f12,$f31
/*    18c30:	4600fc06 */ 	mov.s	$f16,$f31
/*    18c34:	4600fd06 */ 	mov.s	$f20,$f31
/*    18c38:	46006b86 */ 	mov.s	$f14,$f13
/*    18c3c:	46006bc6 */ 	mov.s	$f15,$f13
/*    18c40:	46006c46 */ 	mov.s	$f17,$f13
/*    18c44:	46006c86 */ 	mov.s	$f18,$f13
/*    18c48:	0800631b */ 	j	0x18c6c
/*    18c4c:	46006cc6 */ 	mov.s	$f19,$f13
.L00018c50:
/*    18c50:	000a8020 */ 	add	$s0,$zero,$t2
/*    18c54:	000b8820 */ 	add	$s1,$zero,$t3
/*    18c58:	000c9020 */ 	add	$s2,$zero,$t4
/*    18c5c:	0c0067e6 */ 	jal	func00019f98
/*    18c60:	00089820 */ 	add	$s3,$zero,$t0
/*    18c64:	0c00682b */ 	jal	func0001a0ac
/*    18c68:	00134020 */ 	add	$t0,$zero,$s3
/*    18c6c:	33ca0002 */ 	andi	$t2,$s8,0x2
/*    18c70:	11400024 */ 	beqz	$t2,.L00018d04
/*    18c74:	00000000 */ 	sll	$zero,$zero,0x0
/*    18c78:	850a01e0 */ 	lh	$t2,0x1e0($t0)
/*    18c7c:	850b01e2 */ 	lh	$t3,0x1e2($t0)
/*    18c80:	850c01e4 */ 	lh	$t4,0x1e4($t0)
/*    18c84:	8ced0000 */ 	lw	$t5,0x0($a3)
/*    18c88:	15bc000d */ 	bne	$t5,$gp,.L00018cc0
/*    18c8c:	8f880004 */ 	lw	$t0,0x4($gp)
/*    18c90:	c4c00088 */ 	lwc1	$f0,0x88($a2)
/*    18c94:	448aa800 */ 	mtc1	$t2,$f21
/*    18c98:	448bb000 */ 	mtc1	$t3,$f22
/*    18c9c:	4680ad60 */ 	cvt.s.w	$f21,$f21
/*    18ca0:	4600ad42 */ 	mul.s	$f21,$f21,$f0
/*    18ca4:	448cb800 */ 	mtc1	$t4,$f23
/*    18ca8:	4680b5a0 */ 	cvt.s.w	$f22,$f22
/*    18cac:	4600b582 */ 	mul.s	$f22,$f22,$f0
/*    18cb0:	4680bde0 */ 	cvt.s.w	$f23,$f23
/*    18cb4:	4600bdc2 */ 	mul.s	$f23,$f23,$f0
/*    18cb8:	1000001c */ 	beqz	$zero,.L00018d2c
/*    18cbc:	00000000 */ 	sll	$zero,$zero,0x0
.L00018cc0:
/*    18cc0:	c4c30088 */ 	lwc1	$f3,0x88($a2)
/*    18cc4:	448a0000 */ 	mtc1	$t2,$f0
/*    18cc8:	448b0800 */ 	mtc1	$t3,$f1
/*    18ccc:	46800020 */ 	cvt.s.w	$f0,$f0
/*    18cd0:	46030002 */ 	mul.s	$f0,$f0,$f3
/*    18cd4:	448c1000 */ 	mtc1	$t4,$f2
/*    18cd8:	46800860 */ 	cvt.s.w	$f1,$f1
/*    18cdc:	46030842 */ 	mul.s	$f1,$f1,$f3
/*    18ce0:	468010a0 */ 	cvt.s.w	$f2,$f2
/*    18ce4:	46031082 */ 	mul.s	$f2,$f2,$f3
/*    18ce8:	c5150000 */ 	lwc1	$f21,0x0($t0)
/*    18cec:	c5160004 */ 	lwc1	$f22,0x4($t0)
/*    18cf0:	c5170008 */ 	lwc1	$f23,0x8($t0)
/*    18cf4:	4600ad40 */ 	add.s	$f21,$f21,$f0
/*    18cf8:	4601b580 */ 	add.s	$f22,$f22,$f1
/*    18cfc:	1000000b */ 	beqz	$zero,.L00018d2c
/*    18d00:	4602bdc0 */ 	add.s	$f23,$f23,$f2
.L00018d04:
/*    18d04:	8cea0000 */ 	lw	$t2,0x0($a3)
/*    18d08:	138a0005 */ 	beq	$gp,$t2,.L00018d20
/*    18d0c:	8f880004 */ 	lw	$t0,0x4($gp)
/*    18d10:	c5150000 */ 	lwc1	$f21,0x0($t0)
/*    18d14:	c5160004 */ 	lwc1	$f22,0x4($t0)
/*    18d18:	0800634b */ 	j	0x18d2c
/*    18d1c:	c5170008 */ 	lwc1	$f23,0x8($t0)
.L00018d20:
/*    18d20:	4480a800 */ 	mtc1	$zero,$f21
/*    18d24:	4480b000 */ 	mtc1	$zero,$f22
/*    18d28:	4480b800 */ 	mtc1	$zero,$f23
.L00018d2c:
/*    18d2c:	8f880008 */ 	lw	$t0,0x8($gp)
/*    18d30:	11000005 */ 	beqz	$t0,.L00018d48
/*    18d34:	00000000 */ 	sll	$zero,$zero,0x0
/*    18d38:	0c006897 */ 	jal	func0001a25c
/*    18d3c:	00000000 */ 	sll	$zero,$zero,0x0
/*    18d40:	10000002 */ 	beqz	$zero,.L00018d4c
/*    18d44:	00000000 */ 	sll	$zero,$zero,0x0
.L00018d48:
/*    18d48:	8c880000 */ 	lw	$t0,0x0($a0)
.L00018d4c:
/*    18d4c:	8f890004 */ 	lw	$t1,0x4($gp)
/*    18d50:	952a000e */ 	lhu	$t2,0xe($t1)
/*    18d54:	000a5180 */ 	sll	$t2,$t2,0x6
/*    18d58:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    18d5c:	0c006870 */ 	jal	func0001a1c0
/*    18d60:	012a4820 */ 	add	$t1,$t1,$t2
/*    18d64:	3c0b8006 */ 	lui	$t3,%hi(var8005efcc)
/*    18d68:	256befcc */ 	addiu	$t3,$t3,%lo(var8005efcc)
/*    18d6c:	8d6b0000 */ 	lw	$t3,0x0($t3)
/*    18d70:	11600043 */ 	beqz	$t3,.L00018e80
/*    18d74:	00000000 */ 	sll	$zero,$zero,0x0
/*    18d78:	27bdff80 */ 	addiu	$sp,$sp,-128
/*    18d7c:	afbf0000 */ 	sw	$ra,0x0($sp)
/*    18d80:	afa10004 */ 	sw	$at,0x4($sp)
/*    18d84:	afa20008 */ 	sw	$v0,0x8($sp)
/*    18d88:	afa3000c */ 	sw	$v1,0xc($sp)
/*    18d8c:	afa40010 */ 	sw	$a0,0x10($sp)
/*    18d90:	afa50014 */ 	sw	$a1,0x14($sp)
/*    18d94:	afa60018 */ 	sw	$a2,0x18($sp)
/*    18d98:	afa7001c */ 	sw	$a3,0x1c($sp)
/*    18d9c:	afa80020 */ 	sw	$t0,0x20($sp)
/*    18da0:	afa90024 */ 	sw	$t1,0x24($sp)
/*    18da4:	afaa0028 */ 	sw	$t2,0x28($sp)
/*    18da8:	afab002c */ 	sw	$t3,0x2c($sp)
/*    18dac:	afac0030 */ 	sw	$t4,0x30($sp)
/*    18db0:	afad0034 */ 	sw	$t5,0x34($sp)
/*    18db4:	afae0038 */ 	sw	$t6,0x38($sp)
/*    18db8:	afaf003c */ 	sw	$t7,0x3c($sp)
/*    18dbc:	afb00040 */ 	sw	$s0,0x40($sp)
/*    18dc0:	afb10044 */ 	sw	$s1,0x44($sp)
/*    18dc4:	afb20048 */ 	sw	$s2,0x48($sp)
/*    18dc8:	afb3004c */ 	sw	$s3,0x4c($sp)
/*    18dcc:	afb40050 */ 	sw	$s4,0x50($sp)
/*    18dd0:	afb50054 */ 	sw	$s5,0x54($sp)
/*    18dd4:	afb60058 */ 	sw	$s6,0x58($sp)
/*    18dd8:	afb7005c */ 	sw	$s7,0x5c($sp)
/*    18ddc:	afb80060 */ 	sw	$t8,0x60($sp)
/*    18de0:	afb90064 */ 	sw	$t9,0x64($sp)
/*    18de4:	afbc0070 */ 	sw	$gp,0x70($sp)
/*    18de8:	afbd0074 */ 	sw	$sp,0x74($sp)
/*    18dec:	afbe0078 */ 	sw	$s8,0x78($sp)
/*    18df0:	8f890004 */ 	lw	$t1,0x4($gp)
/*    18df4:	9524000e */ 	lhu	$a0,0xe($t1)
/*    18df8:	00045180 */ 	sll	$t2,$a0,0x6
/*    18dfc:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    18e00:	0160f809 */ 	jalr	$t3
/*    18e04:	012a2820 */ 	add	$a1,$t1,$t2
/*    18e08:	8fbf0000 */ 	lw	$ra,0x0($sp)
/*    18e0c:	8fa10004 */ 	lw	$at,0x4($sp)
/*    18e10:	8fa20008 */ 	lw	$v0,0x8($sp)
/*    18e14:	8fa3000c */ 	lw	$v1,0xc($sp)
/*    18e18:	8fa40010 */ 	lw	$a0,0x10($sp)
/*    18e1c:	8fa50014 */ 	lw	$a1,0x14($sp)
/*    18e20:	8fa60018 */ 	lw	$a2,0x18($sp)
/*    18e24:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*    18e28:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    18e2c:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    18e30:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    18e34:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    18e38:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    18e3c:	8fad0034 */ 	lw	$t5,0x34($sp)
/*    18e40:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    18e44:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    18e48:	8fb00040 */ 	lw	$s0,0x40($sp)
/*    18e4c:	8fb10044 */ 	lw	$s1,0x44($sp)
/*    18e50:	8fb20048 */ 	lw	$s2,0x48($sp)
/*    18e54:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*    18e58:	8fb40050 */ 	lw	$s4,0x50($sp)
/*    18e5c:	8fb50054 */ 	lw	$s5,0x54($sp)
/*    18e60:	8fb60058 */ 	lw	$s6,0x58($sp)
/*    18e64:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*    18e68:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    18e6c:	8fb90064 */ 	lw	$t9,0x64($sp)
/*    18e70:	8fbc0070 */ 	lw	$gp,0x70($sp)
/*    18e74:	8fbd0074 */ 	lw	$sp,0x74($sp)
/*    18e78:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*    18e7c:	27bd0080 */ 	addiu	$sp,$sp,0x80
.L00018e80:
/*    18e80:	878a0000 */ 	lh	$t2,0x0($gp)
/*    18e84:	314a0100 */ 	andi	$t2,$t2,0x100
/*    18e88:	114001ba */ 	beqz	$t2,.L00019574
/*    18e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    18e90:	8fa207e4 */ 	lw	$v0,0x7e4($sp)
/*    18e94:	10400006 */ 	beqz	$v0,.L00018eb0
/*    18e98:	2508fff4 */ 	addiu	$t0,$t0,-12
/*    18e9c:	c7a007e8 */ 	lwc1	$f0,0x7e8($sp)
/*    18ea0:	c7a107ec */ 	lwc1	$f1,0x7ec($sp)
/*    18ea4:	c7a207f0 */ 	lwc1	$f2,0x7f0($sp)
/*    18ea8:	080063b3 */ 	j	0x18ecc
/*    18eac:	c7a307f4 */ 	lwc1	$f3,0x7f4($sp)
.L00018eb0:
/*    18eb0:	00105020 */ 	add	$t2,$zero,$s0
/*    18eb4:	00115820 */ 	add	$t3,$zero,$s1
/*    18eb8:	00126020 */ 	add	$t4,$zero,$s2
/*    18ebc:	0c006809 */ 	jal	func0001a024
/*    18ec0:	00088020 */ 	add	$s0,$zero,$t0
/*    18ec4:	0c0067cb */ 	jal	func00019f2c
/*    18ec8:	00104020 */ 	add	$t0,$zero,$s0
/*    18ecc:	3c013f00 */ 	lui	$at,0x3f00
/*    18ed0:	44814000 */ 	mtc1	$at,$f8
/*    18ed4:	44802000 */ 	mtc1	$zero,$f4
/*    18ed8:	46000186 */ 	mov.s	$f6,$f0
/*    18edc:	3c017005 */ 	lui	$at,%hi(var70054210)
/*    18ee0:	c4274210 */ 	lwc1	$f7,%lo(var70054210)($at)
/*    18ee4:	4604303c */ 	c.lt.s	$f6,$f4
/*    18ee8:	45000003 */ 	bc1f	.L00018ef8
/*    18eec:	4600f946 */ 	mov.s	$f5,$f31
/*    18ef0:	46003187 */ 	neg.s	$f6,$f6
/*    18ef4:	46002947 */ 	neg.s	$f5,$f5
.L00018ef8:
/*    18ef8:	4607303c */ 	c.lt.s	$f6,$f7
/*    18efc:	3c017005 */ 	lui	$at,%hi(var70054214)
/*    18f00:	c4274214 */ 	lwc1	$f7,%lo(var70054214)($at)
/*    18f04:	4500000c */ 	bc1f	.L00018f38
/*    18f08:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f0c:	46080002 */ 	mul.s	$f0,$f0,$f8
/*    18f10:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f14:	46082902 */ 	mul.s	$f4,$f5,$f8
/*    18f18:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f1c:	46080842 */ 	mul.s	$f1,$f1,$f8
/*    18f20:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f24:	46081082 */ 	mul.s	$f2,$f2,$f8
/*    18f28:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f2c:	460818c2 */ 	mul.s	$f3,$f3,$f8
/*    18f30:	10000020 */ 	beqz	$zero,.L00018fb4
/*    18f34:	46040001 */ 	sub.s	$f0,$f0,$f4
.L00018f38:
/*    18f38:	4607303e */ 	c.le.s	$f6,$f7
/*    18f3c:	45000013 */ 	bc1f	.L00018f8c
/*    18f40:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f44:	0c0068b7 */ 	jal	func0001a2dc
/*    18f48:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f4c:	46000446 */ 	mov.s	$f17,$f0
/*    18f50:	46083302 */ 	mul.s	$f12,$f6,$f8
/*    18f54:	00088020 */ 	add	$s0,$zero,$t0
/*    18f58:	0c0068f7 */ 	jal	sinf
/*    18f5c:	00098820 */ 	add	$s1,$zero,$t1
/*    18f60:	460018c2 */ 	mul.s	$f3,$f3,$f0
/*    18f64:	00104020 */ 	add	$t0,$zero,$s0
/*    18f68:	46001082 */ 	mul.s	$f2,$f2,$f0
/*    18f6c:	00114820 */ 	add	$t1,$zero,$s1
/*    18f70:	46000842 */ 	mul.s	$f1,$f1,$f0
/*    18f74:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f78:	46002942 */ 	mul.s	$f5,$f5,$f0
/*    18f7c:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f80:	46110002 */ 	mul.s	$f0,$f0,$f17
/*    18f84:	1000000b */ 	beqz	$zero,.L00018fb4
/*    18f88:	46050000 */ 	add.s	$f0,$f0,$f5
.L00018f8c:
/*    18f8c:	46080002 */ 	mul.s	$f0,$f0,$f8
/*    18f90:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f94:	46082902 */ 	mul.s	$f4,$f5,$f8
/*    18f98:	00000000 */ 	sll	$zero,$zero,0x0
/*    18f9c:	46080842 */ 	mul.s	$f1,$f1,$f8
/*    18fa0:	00000000 */ 	sll	$zero,$zero,0x0
/*    18fa4:	46081082 */ 	mul.s	$f2,$f2,$f8
/*    18fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*    18fac:	460818c2 */ 	mul.s	$f3,$f3,$f8
/*    18fb0:	46040000 */ 	add.s	$f0,$f0,$f4
.L00018fb4:
/*    18fb4:	0c006844 */ 	jal	func0001a110
/*    18fb8:	8f890004 */ 	lw	$t1,0x4($gp)
/*    18fbc:	952a0010 */ 	lhu	$t2,0x10($t1)
/*    18fc0:	000a5180 */ 	sll	$t2,$t2,0x6
/*    18fc4:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    18fc8:	0c006870 */ 	jal	func0001a1c0
/*    18fcc:	012a4820 */ 	add	$t1,$t1,$t2
/*    18fd0:	0800655d */ 	j	0x19574
/*    18fd4:	00000000 */ 	sll	$zero,$zero,0x0
.L00018fd8:
/*    18fd8:	44806800 */ 	mtc1	$zero,$f13
/*    18fdc:	4600fb06 */ 	mov.s	$f12,$f31
/*    18fe0:	4600fc06 */ 	mov.s	$f16,$f31
/*    18fe4:	4600fd06 */ 	mov.s	$f20,$f31
/*    18fe8:	46006b86 */ 	mov.s	$f14,$f13
/*    18fec:	46006bc6 */ 	mov.s	$f15,$f13
/*    18ff0:	46006c46 */ 	mov.s	$f17,$f13
/*    18ff4:	46006c86 */ 	mov.s	$f18,$f13
/*    18ff8:	46006cc6 */ 	mov.s	$f19,$f13
/*    18ffc:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19000:	02e94020 */ 	add	$t0,$s7,$t1
/*    19004:	0800631b */ 	j	0x18c6c
/*    19008:	951e0000 */ 	lhu	$s8,0x0($t0)
.L0001900c:
/*    1900c:	0000000c */ 	syscall
/*    19010:	0c006897 */ 	jal	func0001a25c
/*    19014:	001c4020 */ 	add	$t0,$zero,$gp
/*    19018:	3c0a8006 */ 	lui	$t2,%hi(var8005efb4)
/*    1901c:	254aefb4 */ 	addiu	$t2,$t2,%lo(var8005efb4)
/*    19020:	0c006747 */ 	jal	func00019d1c
/*    19024:	8f890004 */ 	lw	$t1,0x4($gp)
/*    19028:	8d4a0000 */ 	lw	$t2,0x0($t2)
/*    1902c:	1540000e */ 	bnez	$t2,.L00019068
/*    19030:	44800000 */ 	mtc1	$zero,$f0
/*    19034:	1100000c */ 	beqz	$t0,.L00019068
/*    19038:	44800000 */ 	mtc1	$zero,$f0
/*    1903c:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    19040:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*    19044:	c5000038 */ 	lwc1	$f0,0x38($t0)
/*    19048:	8d4a0284 */ 	lw	$t2,0x284($t2)
/*    1904c:	46000007 */ 	neg.s	$f0,$f0
/*    19050:	c5411774 */ 	lwc1	$f1,0x1774($t2)
/*    19054:	46010002 */ 	mul.s	$f0,$f0,$f1
/*    19058:	3c088006 */ 	lui	$t0,%hi(var8005efb8)
/*    1905c:	2508efb8 */ 	addiu	$t0,$t0,%lo(var8005efb8)
/*    19060:	c5010000 */ 	lwc1	$f1,0x0($t0)
/*    19064:	46010002 */ 	mul.s	$f0,$f0,$f1
.L00019068:
/*    19068:	c5210000 */ 	lwc1	$f1,0x0($t1)
/*    1906c:	c4a20014 */ 	lwc1	$f2,0x14($a1)
/*    19070:	44802000 */ 	mtc1	$zero,$f4
/*    19074:	460208c2 */ 	mul.s	$f3,$f1,$f2
/*    19078:	46040832 */ 	c.eq.s	$f1,$f4
/*    1907c:	45010004 */ 	bc1t	.L00019090
/*    19080:	c5240004 */ 	lwc1	$f4,0x4($t1)
/*    19084:	4600183c */ 	c.lt.s	$f3,$f0
/*    19088:	45000009 */ 	bc1f	.L000190b0
/*    1908c:	00000000 */ 	sll	$zero,$zero,0x0
.L00019090:
/*    19090:	460220c2 */ 	mul.s	$f3,$f4,$f2
/*    19094:	4603003e */ 	c.le.s	$f0,$f3
/*    19098:	45000005 */ 	bc1f	.L000190b0
/*    1909c:	8d290008 */ 	lw	$t1,0x8($t1)
/*    190a0:	24080001 */ 	addiu	$t0,$zero,0x1
/*    190a4:	ac480000 */ 	sw	$t0,0x0($v0)
/*    190a8:	0800655d */ 	j	0x19574
/*    190ac:	af890014 */ 	sw	$t1,0x14($gp)
.L000190b0:
/*    190b0:	ac400000 */ 	sw	$zero,0x0($v0)
/*    190b4:	0800655d */ 	j	0x19574
/*    190b8:	af800014 */ 	sw	$zero,0x14($gp)
/*    190bc:	10a000f8 */ 	beqz	$a1,.L000194a0
/*    190c0:	8f880004 */ 	lw	$t0,0x4($gp)
/*    190c4:	94ca0000 */ 	lhu	$t2,0x0($a2)
/*    190c8:	10c000e8 */ 	beqz	$a2,.L0001946c
/*    190cc:	95090000 */ 	lhu	$t1,0x0($t0)
/*    190d0:	4480e800 */ 	mtc1	$zero,$f29
/*    190d4:	c7be07e0 */ 	lwc1	$f30,0x7e0($sp)
/*    190d8:	461ee832 */ 	c.eq.s	$f29,$f30
/*    190dc:	45010050 */ 	bc1t	.L00019220
/*    190e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    190e4:	90ca0008 */ 	lbu	$t2,0x8($a2)
/*    190e8:	11400015 */ 	beqz	$t2,.L00019140
/*    190ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    190f0:	8eca0004 */ 	lw	$t2,0x4($s6)
/*    190f4:	00094840 */ 	sll	$t1,$t1,0x1
/*    190f8:	01495020 */ 	add	$t2,$t2,$t1
/*    190fc:	91490001 */ 	lbu	$t1,0x1($t2)
/*    19100:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19104:	02e94020 */ 	add	$t0,$s7,$t1
/*    19108:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    1910c:	3c0a0001 */ 	lui	$t2,0x1
/*    19110:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    19114:	15800002 */ 	bnez	$t4,.L00019120
/*    19118:	014c6022 */ 	sub	$t4,$t2,$t4
/*    1911c:	200c0000 */ 	addi	$t4,$zero,0x0
.L00019120:
/*    19120:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    19124:	15600002 */ 	bnez	$t3,.L00019130
/*    19128:	014b5822 */ 	sub	$t3,$t2,$t3
/*    1912c:	200b0000 */ 	addi	$t3,$zero,0x0
.L00019130:
/*    19130:	316bffff */ 	andi	$t3,$t3,0xffff
/*    19134:	318cffff */ 	andi	$t4,$t4,0xffff
/*    19138:	08006456 */ 	j	0x19158
/*    1913c:	950a0002 */ 	lhu	$t2,0x2($t0)
.L00019140:
/*    19140:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19144:	02e94020 */ 	add	$t0,$s7,$t1
/*    19148:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    1914c:	950a0002 */ 	lhu	$t2,0x2($t0)
/*    19150:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    19154:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    19158:	8f900004 */ 	lw	$s0,0x4($gp)
/*    1915c:	90d10009 */ 	lbu	$s1,0x9($a2)
/*    19160:	12200015 */ 	beqz	$s1,.L000191b8
/*    19164:	96090000 */ 	lhu	$t1,0x0($s0)
/*    19168:	8ed00004 */ 	lw	$s0,0x4($s6)
/*    1916c:	00094840 */ 	sll	$t1,$t1,0x1
/*    19170:	02098020 */ 	add	$s0,$s0,$t1
/*    19174:	92090001 */ 	lbu	$t1,0x1($s0)
/*    19178:	000948c0 */ 	sll	$t1,$t1,0x3
/*    1917c:	02e94020 */ 	add	$t0,$s7,$t1
/*    19180:	3c100001 */ 	lui	$s0,0x1
/*    19184:	951403c6 */ 	lhu	$s4,0x3c6($t0)
/*    19188:	16800002 */ 	bnez	$s4,.L00019194
/*    1918c:	0214a022 */ 	sub	$s4,$s0,$s4
/*    19190:	20140000 */ 	addi	$s4,$zero,0x0
.L00019194:
/*    19194:	951303c4 */ 	lhu	$s3,0x3c4($t0)
/*    19198:	16600002 */ 	bnez	$s3,.L000191a4
/*    1919c:	02139822 */ 	sub	$s3,$s0,$s3
/*    191a0:	20130000 */ 	addi	$s3,$zero,0x0
.L000191a4:
/*    191a4:	3273ffff */ 	andi	$s3,$s3,0xffff
/*    191a8:	3294ffff */ 	andi	$s4,$s4,0xffff
/*    191ac:	95100002 */ 	lhu	$s0,0x2($t0)
/*    191b0:	10000006 */ 	beqz	$zero,.L000191cc
/*    191b4:	951203c2 */ 	lhu	$s2,0x3c2($t0)
.L000191b8:
/*    191b8:	000948c0 */ 	sll	$t1,$t1,0x3
/*    191bc:	02e94020 */ 	add	$t0,$s7,$t1
/*    191c0:	951203c2 */ 	lhu	$s2,0x3c2($t0)
/*    191c4:	951303c4 */ 	lhu	$s3,0x3c4($t0)
/*    191c8:	951403c6 */ 	lhu	$s4,0x3c6($t0)
.L000191cc:
/*    191cc:	0c006809 */ 	jal	func0001a024
/*    191d0:	afa807e8 */ 	sw	$t0,0x7e8($sp)
/*    191d4:	0c0067cb */ 	jal	func00019f2c
/*    191d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    191dc:	46000406 */ 	mov.s	$f16,$f0
/*    191e0:	46000c46 */ 	mov.s	$f17,$f1
/*    191e4:	46001486 */ 	mov.s	$f18,$f2
/*    191e8:	46001cc6 */ 	mov.s	$f19,$f3
/*    191ec:	02405025 */ 	or	$t2,$s2,$zero
/*    191f0:	02605825 */ 	or	$t3,$s3,$zero
/*    191f4:	0c006809 */ 	jal	func0001a024
/*    191f8:	02806025 */ 	or	$t4,$s4,$zero
/*    191fc:	0c0067cb */ 	jal	func00019f2c
/*    19200:	00000000 */ 	sll	$zero,$zero,0x0
/*    19204:	0c006777 */ 	jal	func00019ddc
/*    19208:	c7be07e0 */ 	lwc1	$f30,0x7e0($sp)
/*    1920c:	8fa807e8 */ 	lw	$t0,0x7e8($sp)
/*    19210:	0c006844 */ 	jal	func0001a110
/*    19214:	00000000 */ 	sll	$zero,$zero,0x0
/*    19218:	080064aa */ 	j	0x192a8
/*    1921c:	00000000 */ 	sll	$zero,$zero,0x0
.L00019220:
/*    19220:	90ca0008 */ 	lbu	$t2,0x8($a2)
/*    19224:	11400017 */ 	beqz	$t2,.L00019284
/*    19228:	95090000 */ 	lhu	$t1,0x0($t0)
/*    1922c:	8eca0004 */ 	lw	$t2,0x4($s6)
/*    19230:	00094840 */ 	sll	$t1,$t1,0x1
/*    19234:	01495020 */ 	add	$t2,$t2,$t1
/*    19238:	91490001 */ 	lbu	$t1,0x1($t2)
/*    1923c:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19240:	02e94020 */ 	add	$t0,$s7,$t1
/*    19244:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    19248:	3c0a0001 */ 	lui	$t2,0x1
/*    1924c:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    19250:	15800002 */ 	bnez	$t4,.L0001925c
/*    19254:	014c6022 */ 	sub	$t4,$t2,$t4
/*    19258:	200c0000 */ 	addi	$t4,$zero,0x0
.L0001925c:
/*    1925c:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    19260:	15600002 */ 	bnez	$t3,.L0001926c
/*    19264:	014b5822 */ 	sub	$t3,$t2,$t3
/*    19268:	200b0000 */ 	addi	$t3,$zero,0x0
.L0001926c:
/*    1926c:	316bffff */ 	andi	$t3,$t3,0xffff
/*    19270:	318cffff */ 	andi	$t4,$t4,0xffff
/*    19274:	0c0067e6 */ 	jal	func00019f98
/*    19278:	950a0002 */ 	lhu	$t2,0x2($t0)
/*    1927c:	10000008 */ 	beqz	$zero,.L000192a0
/*    19280:	00000000 */ 	sll	$zero,$zero,0x0
.L00019284:
/*    19284:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19288:	02e94020 */ 	add	$t0,$s7,$t1
/*    1928c:	951e0000 */ 	lhu	$s8,0x0($t0)
/*    19290:	950c0006 */ 	lhu	$t4,0x6($t0)
/*    19294:	950b0004 */ 	lhu	$t3,0x4($t0)
/*    19298:	0c0067e6 */ 	jal	func00019f98
/*    1929c:	950a0002 */ 	lhu	$t2,0x2($t0)
.L000192a0:
/*    192a0:	0c00682b */ 	jal	func0001a0ac
/*    192a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    192a8:	0c006747 */ 	jal	func00019d1c
/*    192ac:	44800000 */ 	mtc1	$zero,$f0
/*    192b0:	460066c6 */ 	mov.s	$f27,$f12
/*    192b4:	46006f06 */ 	mov.s	$f28,$f13
/*    192b8:	46007746 */ 	mov.s	$f29,$f14
/*    192bc:	46007f86 */ 	mov.s	$f30,$f15
/*    192c0:	c4410018 */ 	lwc1	$f1,0x18($v0)
/*    192c4:	46010032 */ 	c.eq.s	$f0,$f1
/*    192c8:	4501001c */ 	bc1t	.L0001933c
/*    192cc:	c44c0014 */ 	lwc1	$f12,0x14($v0)
/*    192d0:	c443001c */ 	lwc1	$f3,0x1c($v0)
/*    192d4:	3c017005 */ 	lui	$at,%hi(var70054218)
/*    192d8:	c4244218 */ 	lwc1	$f4,%lo(var70054218)($at)
/*    192dc:	460c1941 */ 	sub.s	$f5,$f3,$f12
/*    192e0:	3c017005 */ 	lui	$at,%hi(var7005421c)
/*    192e4:	c426421c */ 	lwc1	$f6,%lo(var7005421c)($at)
/*    192e8:	4600283c */ 	c.lt.s	$f5,$f0
/*    192ec:	45000002 */ 	bc1f	.L000192f8
/*    192f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    192f4:	46062940 */ 	add.s	$f5,$f5,$f6
.L000192f8:
/*    192f8:	4604283c */ 	c.lt.s	$f5,$f4
/*    192fc:	45010008 */ 	bc1t	.L00019320
/*    19300:	00000000 */ 	sll	$zero,$zero,0x0
/*    19304:	46012942 */ 	mul.s	$f5,$f5,$f1
/*    19308:	46056300 */ 	add.s	$f12,$f12,$f5
/*    1930c:	4606603e */ 	c.le.s	$f12,$f6
/*    19310:	4501000a */ 	bc1t	.L0001933c
/*    19314:	00000000 */ 	sll	$zero,$zero,0x0
/*    19318:	080064cf */ 	j	0x1933c
/*    1931c:	46066301 */ 	sub.s	$f12,$f12,$f6
.L00019320:
/*    19320:	46053141 */ 	sub.s	$f5,$f6,$f5
/*    19324:	46012942 */ 	mul.s	$f5,$f5,$f1
/*    19328:	46056301 */ 	sub.s	$f12,$f12,$f5
/*    1932c:	4600603c */ 	c.lt.s	$f12,$f0
/*    19330:	45000002 */ 	bc1f	.L0001933c
/*    19334:	00000000 */ 	sll	$zero,$zero,0x0
/*    19338:	46066300 */ 	add.s	$f12,$f12,$f6
.L0001933c:
/*    1933c:	3c017005 */ 	lui	$at,%hi(var70054220)
/*    19340:	c4214220 */ 	lwc1	$f1,%lo(var70054220)($at)
/*    19344:	0c0068f7 */ 	jal	sinf
/*    19348:	46016040 */ 	add.s	$f1,$f12,$f1
/*    1934c:	46000b06 */ 	mov.s	$f12,$f1
/*    19350:	0c0068f7 */ 	jal	sinf
/*    19354:	46000046 */ 	mov.s	$f1,$f0
/*    19358:	46000887 */ 	neg.s	$f2,$f1
/*    1935c:	4600db06 */ 	mov.s	$f12,$f27
/*    19360:	4600e346 */ 	mov.s	$f13,$f28
/*    19364:	4600eb86 */ 	mov.s	$f14,$f29
/*    19368:	4600f3c6 */ 	mov.s	$f15,$f30
/*    1936c:	c4550008 */ 	lwc1	$f21,0x8($v0)
/*    19370:	c456000c */ 	lwc1	$f22,0xc($v0)
/*    19374:	c4570010 */ 	lwc1	$f23,0x10($v0)
/*    19378:	460c00c2 */ 	mul.s	$f3,$f0,$f12
/*    1937c:	00000000 */ 	sll	$zero,$zero,0x0
/*    19380:	460e0902 */ 	mul.s	$f4,$f1,$f14
/*    19384:	00000000 */ 	sll	$zero,$zero,0x0
/*    19388:	460f0142 */ 	mul.s	$f5,$f0,$f15
/*    1938c:	460418c0 */ 	add.s	$f3,$f3,$f4
/*    19390:	46110982 */ 	mul.s	$f6,$f1,$f17
/*    19394:	00000000 */ 	sll	$zero,$zero,0x0
/*    19398:	461201c2 */ 	mul.s	$f7,$f0,$f18
/*    1939c:	46062940 */ 	add.s	$f5,$f5,$f6
/*    193a0:	46140a02 */ 	mul.s	$f8,$f1,$f20
/*    193a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    193a8:	460c1242 */ 	mul.s	$f9,$f2,$f12
/*    193ac:	460839c0 */ 	add.s	$f7,$f7,$f8
/*    193b0:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*    193b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    193b8:	460f1102 */ 	mul.s	$f4,$f2,$f15
/*    193bc:	460a4b80 */ 	add.s	$f14,$f9,$f10
/*    193c0:	46110182 */ 	mul.s	$f6,$f0,$f17
/*    193c4:	00000000 */ 	sll	$zero,$zero,0x0
/*    193c8:	46121202 */ 	mul.s	$f8,$f2,$f18
/*    193cc:	46062440 */ 	add.s	$f17,$f4,$f6
/*    193d0:	46140282 */ 	mul.s	$f10,$f0,$f20
/*    193d4:	46001b06 */ 	mov.s	$f12,$f3
/*    193d8:	460a4500 */ 	add.s	$f20,$f8,$f10
/*    193dc:	46002bc6 */ 	mov.s	$f15,$f5
/*    193e0:	46003c86 */ 	mov.s	$f18,$f7
/*    193e4:	c4a00014 */ 	lwc1	$f0,0x14($a1)
/*    193e8:	4600f832 */ 	c.eq.s	$f31,$f0
/*    193ec:	45010012 */ 	bc1t	.L00019438
/*    193f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    193f4:	46006302 */ 	mul.s	$f12,$f12,$f0
/*    193f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    193fc:	46006b42 */ 	mul.s	$f13,$f13,$f0
/*    19400:	00000000 */ 	sll	$zero,$zero,0x0
/*    19404:	46007382 */ 	mul.s	$f14,$f14,$f0
/*    19408:	00000000 */ 	sll	$zero,$zero,0x0
/*    1940c:	46007bc2 */ 	mul.s	$f15,$f15,$f0
/*    19410:	00000000 */ 	sll	$zero,$zero,0x0
/*    19414:	46008402 */ 	mul.s	$f16,$f16,$f0
/*    19418:	00000000 */ 	sll	$zero,$zero,0x0
/*    1941c:	46008c42 */ 	mul.s	$f17,$f17,$f0
/*    19420:	00000000 */ 	sll	$zero,$zero,0x0
/*    19424:	46009482 */ 	mul.s	$f18,$f18,$f0
/*    19428:	00000000 */ 	sll	$zero,$zero,0x0
/*    1942c:	46009cc2 */ 	mul.s	$f19,$f19,$f0
/*    19430:	00000000 */ 	sll	$zero,$zero,0x0
/*    19434:	4600a502 */ 	mul.s	$f20,$f20,$f0
.L00019438:
/*    19438:	8f880008 */ 	lw	$t0,0x8($gp)
/*    1943c:	11000002 */ 	beqz	$t0,.L00019448
/*    19440:	00000000 */ 	sll	$zero,$zero,0x0
/*    19444:	0000000c */ 	syscall
.L00019448:
/*    19448:	8f890004 */ 	lw	$t1,0x4($gp)
/*    1944c:	8c880000 */ 	lw	$t0,0x0($a0)
/*    19450:	952a0002 */ 	lhu	$t2,0x2($t1)
/*    19454:	000a5180 */ 	sll	$t2,$t2,0x6
/*    19458:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1945c:	0c006870 */ 	jal	func0001a1c0
/*    19460:	012a4820 */ 	add	$t1,$t1,$t2
/*    19464:	0800655d */ 	j	0x19574
/*    19468:	00000000 */ 	sll	$zero,$zero,0x0
.L0001946c:
/*    1946c:	44806800 */ 	mtc1	$zero,$f13
/*    19470:	4600fb06 */ 	mov.s	$f12,$f31
/*    19474:	4600fc06 */ 	mov.s	$f16,$f31
/*    19478:	4600fd06 */ 	mov.s	$f20,$f31
/*    1947c:	46006b86 */ 	mov.s	$f14,$f13
/*    19480:	46006bc6 */ 	mov.s	$f15,$f13
/*    19484:	46006c46 */ 	mov.s	$f17,$f13
/*    19488:	46006c86 */ 	mov.s	$f18,$f13
/*    1948c:	46006cc6 */ 	mov.s	$f19,$f13
/*    19490:	000948c0 */ 	sll	$t1,$t1,0x3
/*    19494:	02e94020 */ 	add	$t0,$s7,$t1
/*    19498:	080064aa */ 	j	0x192a8
/*    1949c:	951e0000 */ 	lhu	$s8,0x0($t0)
.L000194a0:
/*    194a0:	0000000c */ 	syscall
/*    194a4:	0c006747 */ 	jal	func00019d1c
/*    194a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    194ac:	8c490000 */ 	lw	$t1,0x0($v0)
/*    194b0:	11200030 */ 	beqz	$t1,.L00019574
/*    194b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    194b8:	afbd07f8 */ 	sw	$sp,0x7f8($sp)
/*    194bc:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*    194c0:	1140002c */ 	beqz	$t2,.L00019574
/*    194c4:	af8a0014 */ 	sw	$t2,0x14($gp)
.L000194c8:
/*    194c8:	ad5c0008 */ 	sw	$gp,0x8($t2)
/*    194cc:	8d4a000c */ 	lw	$t2,0xc($t2)
/*    194d0:	1540fffd */ 	bnez	$t2,.L000194c8
/*    194d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    194d8:	0800655d */ 	j	0x19574
/*    194dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    194e0:	8f880008 */ 	lw	$t0,0x8($gp)
/*    194e4:	15000003 */ 	bnez	$t0,.L000194f4
/*    194e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    194ec:	0800653f */ 	j	0x194fc
/*    194f0:	8c880000 */ 	lw	$t0,0x0($a0)
.L000194f4:
/*    194f4:	0c006897 */ 	jal	func0001a25c
/*    194f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    194fc:	8f890004 */ 	lw	$t1,0x4($gp)
/*    19500:	44806800 */ 	mtc1	$zero,$f13
/*    19504:	4600fb06 */ 	mov.s	$f12,$f31
/*    19508:	4600fc06 */ 	mov.s	$f16,$f31
/*    1950c:	4600fd06 */ 	mov.s	$f20,$f31
/*    19510:	46006b86 */ 	mov.s	$f14,$f13
/*    19514:	46006bc6 */ 	mov.s	$f15,$f13
/*    19518:	46006c46 */ 	mov.s	$f17,$f13
/*    1951c:	46006c86 */ 	mov.s	$f18,$f13
/*    19520:	46006cc6 */ 	mov.s	$f19,$f13
/*    19524:	c5350000 */ 	lwc1	$f21,0x0($t1)
/*    19528:	c5360004 */ 	lwc1	$f22,0x4($t1)
/*    1952c:	c5370008 */ 	lwc1	$f23,0x8($t1)
/*    19530:	952a000c */ 	lhu	$t2,0xc($t1)
/*    19534:	000a5180 */ 	sll	$t2,$t2,0x6
/*    19538:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1953c:	0c006870 */ 	jal	func0001a1c0
/*    19540:	012a4820 */ 	add	$t1,$t1,$t2
/*    19544:	0800655d */ 	j	0x19574
/*    19548:	00000000 */ 	sll	$zero,$zero,0x0
/*    1954c:	0800655d */ 	j	0x19574
/*    19550:	00000000 */ 	sll	$zero,$zero,0x0
/*    19554:	0c006747 */ 	jal	func00019d1c
/*    19558:	8f880004 */ 	lw	$t0,0x4($gp)
/*    1955c:	8c490000 */ 	lw	$t1,0x0($v0)
/*    19560:	11200003 */ 	beqz	$t1,.L00019570
/*    19564:	8d090000 */ 	lw	$t1,0x0($t0)
/*    19568:	0800655d */ 	j	0x19574
/*    1956c:	af890014 */ 	sw	$t1,0x14($gp)
.L00019570:
/*    19570:	af800014 */ 	sw	$zero,0x14($gp)
.L00019574:
/*    19574:	8f880014 */ 	lw	$t0,0x14($gp)
/*    19578:	11000003 */ 	beqz	$t0,.L00019588
/*    1957c:	00000000 */ 	sll	$zero,$zero,0x0
/*    19580:	08006279 */ 	j	0x189e4
/*    19584:	0008e020 */ 	add	$gp,$zero,$t0
.L00019588:
/*    19588:	8f88000c */ 	lw	$t0,0xc($gp)
/*    1958c:	11000003 */ 	beqz	$t0,.L0001959c
/*    19590:	00000000 */ 	sll	$zero,$zero,0x0
/*    19594:	08006279 */ 	j	0x189e4
/*    19598:	0008e020 */ 	add	$gp,$zero,$t0
.L0001959c:
/*    1959c:	8f9c0008 */ 	lw	$gp,0x8($gp)
/*    195a0:	13800009 */ 	beqz	$gp,.L000195c8
/*    195a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    195a8:	97880000 */ 	lhu	$t0,0x0($gp)
/*    195ac:	310800ff */ 	andi	$t0,$t0,0xff
/*    195b0:	24010017 */ 	addiu	$at,$zero,0x17
/*    195b4:	1501fff4 */ 	bne	$t0,$at,.L00019588
/*    195b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    195bc:	afa807f8 */ 	sw	$t0,0x7f8($sp)
/*    195c0:	1780fff1 */ 	bnez	$gp,.L00019588
/*    195c4:	00000000 */ 	sll	$zero,$zero,0x0
.L000195c8:
/*    195c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L000195cc:
/*    195cc:	8fb00780 */ 	lw	$s0,0x780($sp)
/*    195d0:	8fb10784 */ 	lw	$s1,0x784($sp)
/*    195d4:	8fb20788 */ 	lw	$s2,0x788($sp)
/*    195d8:	8fb3078c */ 	lw	$s3,0x78c($sp)
/*    195dc:	8fb40790 */ 	lw	$s4,0x790($sp)
/*    195e0:	8fb50794 */ 	lw	$s5,0x794($sp)
/*    195e4:	8fb60798 */ 	lw	$s6,0x798($sp)
/*    195e8:	8fb7079c */ 	lw	$s7,0x79c($sp)
/*    195ec:	8fbe07a0 */ 	lw	$s8,0x7a0($sp)
/*    195f0:	8fbc07a4 */ 	lw	$gp,0x7a4($sp)
/*    195f4:	8fbf07a8 */ 	lw	$ra,0x7a8($sp)
/*    195f8:	c7b407b0 */ 	lwc1	$f20,0x7b0($sp)
/*    195fc:	c7b507b4 */ 	lwc1	$f21,0x7b4($sp)
/*    19600:	c7b607b8 */ 	lwc1	$f22,0x7b8($sp)
/*    19604:	c7b707bc */ 	lwc1	$f23,0x7bc($sp)
/*    19608:	c7b807c0 */ 	lwc1	$f24,0x7c0($sp)
/*    1960c:	c7b907c4 */ 	lwc1	$f25,0x7c4($sp)
/*    19610:	c7ba07c8 */ 	lwc1	$f26,0x7c8($sp)
/*    19614:	c7bb07cc */ 	lwc1	$f27,0x7cc($sp)
/*    19618:	c7bc07d0 */ 	lwc1	$f28,0x7d0($sp)
/*    1961c:	c7bd07d4 */ 	lwc1	$f29,0x7d4($sp)
/*    19620:	c7be07d8 */ 	lwc1	$f30,0x7d8($sp)
/*    19624:	c7bf07dc */ 	lwc1	$f31,0x7dc($sp)
/*    19628:	03e00008 */ 	jr	$ra
/*    1962c:	27bd0800 */ 	addiu	$sp,$sp,0x800
/*    19630:	0000000c */ 	syscall
);

GLOBAL_ASM(
glabel func00019634
/*    19634:	afbf07ac */ 	sw	$ra,0x7ac($sp)
.L00019638:
/*    19638:	914f0000 */ 	lbu	$t7,0x0($t2)
/*    1963c:	254a0001 */ 	addiu	$t2,$t2,0x1
/*    19640:	a50f0000 */ 	sh	$t7,0x0($t0)
/*    19644:	3418000f */ 	ori	$t8,$zero,0x0f
/*    19648:	030f082a */ 	slt	$at,$t8,$t7
/*    1964c:	1420ffdf */ 	bnez	$at,.L000195cc
/*    19650:	20020000 */ 	addi	$v0,$zero,0x0
/*    19654:	31f80002 */ 	andi	$t8,$t7,0x2
/*    19658:	1700001c */ 	bnez	$t8,.L000196cc
/*    1965c:	20100000 */ 	addi	$s0,$zero,0x0
/*    19660:	31f80008 */ 	andi	$t8,$t7,0x8
/*    19664:	20110000 */ 	addi	$s1,$zero,0x0
/*    19668:	13000067 */ 	beqz	$t8,.L00019808
/*    1966c:	20120000 */ 	addi	$s2,$zero,0x0
/*    19670:	91420002 */ 	lbu	$v0,0x2($t2)
/*    19674:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19678:	00431020 */ 	add	$v0,$v0,$v1
/*    1967c:	91430008 */ 	lbu	$v1,0x8($t2)
/*    19680:	00431020 */ 	add	$v0,$v0,$v1
/*    19684:	9143000b */ 	lbu	$v1,0xb($t2)
/*    19688:	00431020 */ 	add	$v0,$v0,$v1
/*    1968c:	005c082a */ 	slt	$at,$v0,$gp
/*    19690:	1420000c */ 	bnez	$at,.L000196c4
/*    19694:	005c1022 */ 	sub	$v0,$v0,$gp
/*    19698:	201e0000 */ 	addi	$s8,$zero,0x0
/*    1969c:	0002c0c2 */ 	srl	$t8,$v0,0x3
/*    196a0:	01d87020 */ 	add	$t6,$t6,$t8
/*    196a4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    196a8:	00581022 */ 	sub	$v0,$v0,$t8
/*    196ac:	91de0000 */ 	lbu	$s8,0x0($t6)
/*    196b0:	241c0008 */ 	addiu	$gp,$zero,0x8
/*    196b4:	25ce0001 */ 	addiu	$t6,$t6,0x1
/*    196b8:	0382e022 */ 	sub	$gp,$gp,$v0
/*    196bc:	08006602 */ 	j	0x19808
/*    196c0:	214a000c */ 	addi	$t2,$t2,0xc
.L000196c4:
/*    196c4:	08006602 */ 	j	0x19808
/*    196c8:	214a000c */ 	addi	$t2,$t2,0xc
.L000196cc:
/*    196cc:	0c0066f8 */ 	jal	func00019be0
/*    196d0:	91430002 */ 	lbu	$v1,0x2($t2)
/*    196d4:	00028020 */ 	add	$s0,$zero,$v0
/*    196d8:	91430002 */ 	lbu	$v1,0x2($t2)
/*    196dc:	24130010 */ 	addiu	$s3,$zero,0x10
/*    196e0:	0073082a */ 	slt	$at,$v1,$s3
/*    196e4:	1020000c */ 	beqz	$at,.L00019718
/*    196e8:	24130001 */ 	addiu	$s3,$zero,0x1
/*    196ec:	2462ffff */ 	addiu	$v0,$v1,-1
/*    196f0:	00539804 */ 	sllv	$s3,$s3,$v0
/*    196f4:	0213a024 */ 	and	$s4,$s0,$s3
/*    196f8:	12800007 */ 	beqz	$s4,.L00019718
/*    196fc:	24140010 */ 	addiu	$s4,$zero,0x10
/*    19700:	0283a022 */ 	sub	$s4,$s4,$v1
/*    19704:	24020001 */ 	addiu	$v0,$zero,0x1
/*    19708:	02821004 */ 	sllv	$v0,$v0,$s4
/*    1970c:	2442ffff */ 	addiu	$v0,$v0,-1
/*    19710:	00621004 */ 	sllv	$v0,$v0,$v1
/*    19714:	02028025 */ 	or	$s0,$s0,$v0
.L00019718:
/*    19718:	91530000 */ 	lbu	$s3,0x0($t2)
/*    1971c:	00139a00 */ 	sll	$s3,$s3,0x8
/*    19720:	91540001 */ 	lbu	$s4,0x1($t2)
/*    19724:	02749821 */ 	addu	$s3,$s3,$s4
/*    19728:	02138021 */ 	addu	$s0,$s0,$s3
/*    1972c:	3210ffff */ 	andi	$s0,$s0,0xffff
/*    19730:	0c0066f8 */ 	jal	func00019be0
/*    19734:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19738:	00028820 */ 	add	$s1,$zero,$v0
/*    1973c:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19740:	24130010 */ 	addiu	$s3,$zero,0x10
/*    19744:	0073082a */ 	slt	$at,$v1,$s3
/*    19748:	1020000c */ 	beqz	$at,.L0001977c
/*    1974c:	24130001 */ 	addiu	$s3,$zero,0x1
/*    19750:	2462ffff */ 	addiu	$v0,$v1,-1
/*    19754:	00539804 */ 	sllv	$s3,$s3,$v0
/*    19758:	0233a024 */ 	and	$s4,$s1,$s3
/*    1975c:	12800007 */ 	beqz	$s4,.L0001977c
/*    19760:	24140010 */ 	addiu	$s4,$zero,0x10
/*    19764:	0283a022 */ 	sub	$s4,$s4,$v1
/*    19768:	24020001 */ 	addiu	$v0,$zero,0x1
/*    1976c:	02821004 */ 	sllv	$v0,$v0,$s4
/*    19770:	2442ffff */ 	addiu	$v0,$v0,-1
/*    19774:	00621004 */ 	sllv	$v0,$v0,$v1
/*    19778:	02228825 */ 	or	$s1,$s1,$v0
.L0001977c:
/*    1977c:	91530003 */ 	lbu	$s3,0x3($t2)
/*    19780:	00139a00 */ 	sll	$s3,$s3,0x8
/*    19784:	91540004 */ 	lbu	$s4,0x4($t2)
/*    19788:	02749821 */ 	addu	$s3,$s3,$s4
/*    1978c:	02338821 */ 	addu	$s1,$s1,$s3
/*    19790:	3231ffff */ 	andi	$s1,$s1,0xffff
/*    19794:	0c0066f8 */ 	jal	func00019be0
/*    19798:	91430008 */ 	lbu	$v1,0x8($t2)
/*    1979c:	00029020 */ 	add	$s2,$zero,$v0
/*    197a0:	91430008 */ 	lbu	$v1,0x8($t2)
/*    197a4:	24130010 */ 	addiu	$s3,$zero,0x10
/*    197a8:	0073082a */ 	slt	$at,$v1,$s3
/*    197ac:	1020000c */ 	beqz	$at,.L000197e0
/*    197b0:	24130001 */ 	addiu	$s3,$zero,0x1
/*    197b4:	2462ffff */ 	addiu	$v0,$v1,-1
/*    197b8:	00539804 */ 	sllv	$s3,$s3,$v0
/*    197bc:	0253a024 */ 	and	$s4,$s2,$s3
/*    197c0:	12800007 */ 	beqz	$s4,.L000197e0
/*    197c4:	24140010 */ 	addiu	$s4,$zero,0x10
/*    197c8:	0283a022 */ 	sub	$s4,$s4,$v1
/*    197cc:	24020001 */ 	addiu	$v0,$zero,0x1
/*    197d0:	02821004 */ 	sllv	$v0,$v0,$s4
/*    197d4:	2442ffff */ 	addiu	$v0,$v0,-1
/*    197d8:	00621004 */ 	sllv	$v0,$v0,$v1
/*    197dc:	02429025 */ 	or	$s2,$s2,$v0
.L000197e0:
/*    197e0:	91530006 */ 	lbu	$s3,0x6($t2)
/*    197e4:	00139a00 */ 	sll	$s3,$s3,0x8
/*    197e8:	91540007 */ 	lbu	$s4,0x7($t2)
/*    197ec:	02749821 */ 	addu	$s3,$s3,$s4
/*    197f0:	02539021 */ 	addu	$s2,$s2,$s3
/*    197f4:	3252ffff */ 	andi	$s2,$s2,0xffff
/*    197f8:	214a0009 */ 	addi	$t2,$t2,0x9
/*    197fc:	a51001e0 */ 	sh	$s0,0x1e0($t0)
/*    19800:	a51101e2 */ 	sh	$s1,0x1e2($t0)
/*    19804:	a51201e4 */ 	sh	$s2,0x1e4($t0)
.L00019808:
/*    19808:	31f80001 */ 	andi	$t8,$t7,0x1
/*    1980c:	17000004 */ 	bnez	$t8,.L00019820
/*    19810:	20100000 */ 	addi	$s0,$zero,0x0
/*    19814:	20110000 */ 	addi	$s1,$zero,0x0
/*    19818:	0800662d */ 	j	0x198b4
/*    1981c:	20120000 */ 	addi	$s2,$zero,0x0
.L00019820:
/*    19820:	0c0066f8 */ 	jal	func00019be0
/*    19824:	91430002 */ 	lbu	$v1,0x2($t2)
/*    19828:	00028020 */ 	add	$s0,$zero,$v0
/*    1982c:	91430000 */ 	lbu	$v1,0x0($t2)
/*    19830:	00031a00 */ 	sll	$v1,$v1,0x8
/*    19834:	91420001 */ 	lbu	$v0,0x1($t2)
/*    19838:	00621821 */ 	addu	$v1,$v1,$v0
/*    1983c:	24020010 */ 	addiu	$v0,$zero,0x10
/*    19840:	02038021 */ 	addu	$s0,$s0,$v1
/*    19844:	004c1022 */ 	sub	$v0,$v0,$t4
/*    19848:	00508004 */ 	sllv	$s0,$s0,$v0
/*    1984c:	3210ffff */ 	andi	$s0,$s0,0xffff
/*    19850:	0c0066f8 */ 	jal	func00019be0
/*    19854:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19858:	00028820 */ 	add	$s1,$zero,$v0
/*    1985c:	91430003 */ 	lbu	$v1,0x3($t2)
/*    19860:	00031a00 */ 	sll	$v1,$v1,0x8
/*    19864:	91420004 */ 	lbu	$v0,0x4($t2)
/*    19868:	00621821 */ 	addu	$v1,$v1,$v0
/*    1986c:	24020010 */ 	addiu	$v0,$zero,0x10
/*    19870:	02238821 */ 	addu	$s1,$s1,$v1
/*    19874:	004c1022 */ 	sub	$v0,$v0,$t4
/*    19878:	00518804 */ 	sllv	$s1,$s1,$v0
/*    1987c:	3231ffff */ 	andi	$s1,$s1,0xffff
/*    19880:	0c0066f8 */ 	jal	func00019be0
/*    19884:	91430008 */ 	lbu	$v1,0x8($t2)
/*    19888:	00029020 */ 	add	$s2,$zero,$v0
/*    1988c:	91430006 */ 	lbu	$v1,0x6($t2)
/*    19890:	00031a00 */ 	sll	$v1,$v1,0x8
/*    19894:	91420007 */ 	lbu	$v0,0x7($t2)
/*    19898:	00621821 */ 	addu	$v1,$v1,$v0
/*    1989c:	24020010 */ 	addiu	$v0,$zero,0x10
/*    198a0:	02439021 */ 	addu	$s2,$s2,$v1
/*    198a4:	004c1022 */ 	sub	$v0,$v0,$t4
/*    198a8:	00529004 */ 	sllv	$s2,$s2,$v0
/*    198ac:	3252ffff */ 	andi	$s2,$s2,0xffff
/*    198b0:	214a0009 */ 	addi	$t2,$t2,0x9
/*    198b4:	a5100002 */ 	sh	$s0,0x2($t0)
/*    198b8:	a5110004 */ 	sh	$s1,0x4($t0)
/*    198bc:	a5120006 */ 	sh	$s2,0x6($t0)
/*    198c0:	21080008 */ 	addi	$t0,$t0,0x8
/*    198c4:	014b082a */ 	slt	$at,$t2,$t3
/*    198c8:	1420ff5b */ 	bnez	$at,.L00019638
/*    198cc:	00000000 */ 	sll	$zero,$zero,0x0
/*    198d0:	8fbf07ac */ 	lw	$ra,0x7ac($sp)
/*    198d4:	03e00008 */ 	jr	$ra
/*    198d8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000198dc
/*    198dc:	afbf07ac */ 	sw	$ra,0x7ac($sp)
.L000198e0:
/*    198e0:	914f0000 */ 	lbu	$t7,0x0($t2)
/*    198e4:	214a0001 */ 	addi	$t2,$t2,0x1
/*    198e8:	3418000f */ 	ori	$t8,$zero,0x0f
/*    198ec:	030f082a */ 	slt	$at,$t8,$t7
/*    198f0:	1420ff36 */ 	bnez	$at,.L000195cc
/*    198f4:	20020000 */ 	addi	$v0,$zero,0x0
/*    198f8:	31f80002 */ 	andi	$t8,$t7,0x2
/*    198fc:	1700001c */ 	bnez	$t8,.L00019970
/*    19900:	20100000 */ 	addi	$s0,$zero,0x0
/*    19904:	31f80008 */ 	andi	$t8,$t7,0x8
/*    19908:	20110000 */ 	addi	$s1,$zero,0x0
/*    1990c:	1300002a */ 	beqz	$t8,.L000199b8
/*    19910:	20120000 */ 	addi	$s2,$zero,0x0
/*    19914:	91420002 */ 	lbu	$v0,0x2($t2)
/*    19918:	91430005 */ 	lbu	$v1,0x5($t2)
/*    1991c:	00431020 */ 	add	$v0,$v0,$v1
/*    19920:	91430008 */ 	lbu	$v1,0x8($t2)
/*    19924:	00431020 */ 	add	$v0,$v0,$v1
/*    19928:	9143000b */ 	lbu	$v1,0xb($t2)
/*    1992c:	00431020 */ 	add	$v0,$v0,$v1
/*    19930:	005c082a */ 	slt	$at,$v0,$gp
/*    19934:	1420000c */ 	bnez	$at,.L00019968
/*    19938:	005c1022 */ 	sub	$v0,$v0,$gp
/*    1993c:	201e0000 */ 	addi	$s8,$zero,0x0
/*    19940:	0002c0c2 */ 	srl	$t8,$v0,0x3
/*    19944:	01d87020 */ 	add	$t6,$t6,$t8
/*    19948:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    1994c:	00581022 */ 	sub	$v0,$v0,$t8
/*    19950:	91de0000 */ 	lbu	$s8,0x0($t6)
/*    19954:	241c0008 */ 	addiu	$gp,$zero,0x8
/*    19958:	25ce0001 */ 	addiu	$t6,$t6,0x1
/*    1995c:	0382e022 */ 	sub	$gp,$gp,$v0
/*    19960:	0800666e */ 	j	0x199b8
/*    19964:	214a000c */ 	addi	$t2,$t2,0xc
.L00019968:
/*    19968:	0800666e */ 	j	0x199b8
/*    1996c:	214a000c */ 	addi	$t2,$t2,0xc
.L00019970:
/*    19970:	91420002 */ 	lbu	$v0,0x2($t2)
/*    19974:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19978:	00431020 */ 	add	$v0,$v0,$v1
/*    1997c:	91430008 */ 	lbu	$v1,0x8($t2)
/*    19980:	00431020 */ 	add	$v0,$v0,$v1
/*    19984:	005c082a */ 	slt	$at,$v0,$gp
/*    19988:	1420000a */ 	bnez	$at,.L000199b4
/*    1998c:	005c1022 */ 	sub	$v0,$v0,$gp
/*    19990:	201e0000 */ 	addi	$s8,$zero,0x0
/*    19994:	0002c0c2 */ 	srl	$t8,$v0,0x3
/*    19998:	01d87020 */ 	add	$t6,$t6,$t8
/*    1999c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    199a0:	00581022 */ 	sub	$v0,$v0,$t8
/*    199a4:	91de0000 */ 	lbu	$s8,0x0($t6)
/*    199a8:	241c0008 */ 	addiu	$gp,$zero,0x8
/*    199ac:	25ce0001 */ 	addiu	$t6,$t6,0x1
/*    199b0:	0382e022 */ 	sub	$gp,$gp,$v0
.L000199b4:
/*    199b4:	214a0009 */ 	addi	$t2,$t2,0x9
.L000199b8:
/*    199b8:	31f80001 */ 	andi	$t8,$t7,0x1
/*    199bc:	17000004 */ 	bnez	$t8,.L000199d0
/*    199c0:	20100000 */ 	addi	$s0,$zero,0x0
/*    199c4:	20110000 */ 	addi	$s1,$zero,0x0
/*    199c8:	08006699 */ 	j	0x19a64
/*    199cc:	20120000 */ 	addi	$s2,$zero,0x0
.L000199d0:
/*    199d0:	0c0066f8 */ 	jal	func00019be0
/*    199d4:	91430002 */ 	lbu	$v1,0x2($t2)
/*    199d8:	00028020 */ 	add	$s0,$zero,$v0
/*    199dc:	91430000 */ 	lbu	$v1,0x0($t2)
/*    199e0:	00031a00 */ 	sll	$v1,$v1,0x8
/*    199e4:	91420001 */ 	lbu	$v0,0x1($t2)
/*    199e8:	00621821 */ 	addu	$v1,$v1,$v0
/*    199ec:	24020010 */ 	addiu	$v0,$zero,0x10
/*    199f0:	02038021 */ 	addu	$s0,$s0,$v1
/*    199f4:	004c1022 */ 	sub	$v0,$v0,$t4
/*    199f8:	00508004 */ 	sllv	$s0,$s0,$v0
/*    199fc:	3210ffff */ 	andi	$s0,$s0,0xffff
/*    19a00:	0c0066f8 */ 	jal	func00019be0
/*    19a04:	91430005 */ 	lbu	$v1,0x5($t2)
/*    19a08:	00028820 */ 	add	$s1,$zero,$v0
/*    19a0c:	91430003 */ 	lbu	$v1,0x3($t2)
/*    19a10:	00031a00 */ 	sll	$v1,$v1,0x8
/*    19a14:	91420004 */ 	lbu	$v0,0x4($t2)
/*    19a18:	00621821 */ 	addu	$v1,$v1,$v0
/*    19a1c:	24020010 */ 	addiu	$v0,$zero,0x10
/*    19a20:	02238821 */ 	addu	$s1,$s1,$v1
/*    19a24:	004c1022 */ 	sub	$v0,$v0,$t4
/*    19a28:	00518804 */ 	sllv	$s1,$s1,$v0
/*    19a2c:	3231ffff */ 	andi	$s1,$s1,0xffff
/*    19a30:	0c0066f8 */ 	jal	func00019be0
/*    19a34:	91430008 */ 	lbu	$v1,0x8($t2)
/*    19a38:	00029020 */ 	add	$s2,$zero,$v0
/*    19a3c:	91430006 */ 	lbu	$v1,0x6($t2)
/*    19a40:	00031a00 */ 	sll	$v1,$v1,0x8
/*    19a44:	91420007 */ 	lbu	$v0,0x7($t2)
/*    19a48:	00621821 */ 	addu	$v1,$v1,$v0
/*    19a4c:	24020010 */ 	addiu	$v0,$zero,0x10
/*    19a50:	02439021 */ 	addu	$s2,$s2,$v1
/*    19a54:	004c1022 */ 	sub	$v0,$v0,$t4
/*    19a58:	00529004 */ 	sllv	$s2,$s2,$v0
/*    19a5c:	3252ffff */ 	andi	$s2,$s2,0xffff
/*    19a60:	214a0009 */ 	addi	$t2,$t2,0x9
/*    19a64:	44130000 */ 	mfc1	$s3,$f0
/*    19a68:	3c030001 */ 	lui	$v1,0x1
/*    19a6c:	95140002 */ 	lhu	$s4,0x2($t0)
/*    19a70:	0214a822 */ 	sub	$s5,$s0,$s4
/*    19a74:	06a10002 */ 	bgez	$s5,.L00019a80
/*    19a78:	00000000 */ 	sll	$zero,$zero,0x0
/*    19a7c:	02a3a820 */ 	add	$s5,$s5,$v1
.L00019a80:
/*    19a80:	34018000 */ 	dli	$at,0x8000
/*    19a84:	02a1082a */ 	slt	$at,$s5,$at
/*    19a88:	1020000c */ 	beqz	$at,.L00019abc
/*    19a8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    19a90:	02b30019 */ 	multu	$s5,$s3
/*    19a94:	0000a812 */ 	mflo	$s5
/*    19a98:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19a9c:	02958020 */ 	add	$s0,$s4,$s5
/*    19aa0:	3c010001 */ 	lui	$at,0x1
/*    19aa4:	0201082a */ 	slt	$at,$s0,$at
/*    19aa8:	1420000c */ 	bnez	$at,.L00019adc
/*    19aac:	00000000 */ 	sll	$zero,$zero,0x0
/*    19ab0:	3c140001 */ 	lui	$s4,0x1
/*    19ab4:	080066b7 */ 	j	0x19adc
/*    19ab8:	02148022 */ 	sub	$s0,$s0,$s4
.L00019abc:
/*    19abc:	0075a822 */ 	sub	$s5,$v1,$s5
/*    19ac0:	02b30019 */ 	multu	$s5,$s3
/*    19ac4:	0000a812 */ 	mflo	$s5
/*    19ac8:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19acc:	02958022 */ 	sub	$s0,$s4,$s5
/*    19ad0:	06010002 */ 	bgez	$s0,.L00019adc
/*    19ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*    19ad8:	02038020 */ 	add	$s0,$s0,$v1
.L00019adc:
/*    19adc:	95140004 */ 	lhu	$s4,0x4($t0)
/*    19ae0:	0234a822 */ 	sub	$s5,$s1,$s4
/*    19ae4:	06a10002 */ 	bgez	$s5,.L00019af0
/*    19ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*    19aec:	02a3a820 */ 	add	$s5,$s5,$v1
.L00019af0:
/*    19af0:	34018000 */ 	dli	$at,0x8000
/*    19af4:	02a1082a */ 	slt	$at,$s5,$at
/*    19af8:	1020000b */ 	beqz	$at,.L00019b28
/*    19afc:	00000000 */ 	sll	$zero,$zero,0x0
/*    19b00:	02b30019 */ 	multu	$s5,$s3
/*    19b04:	0000a812 */ 	mflo	$s5
/*    19b08:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19b0c:	02958820 */ 	add	$s1,$s4,$s5
/*    19b10:	3c010001 */ 	lui	$at,0x1
/*    19b14:	0221082a */ 	slt	$at,$s1,$at
/*    19b18:	1420000b */ 	bnez	$at,.L00019b48
/*    19b1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    19b20:	080066d2 */ 	j	0x19b48
/*    19b24:	02238822 */ 	sub	$s1,$s1,$v1
.L00019b28:
/*    19b28:	0075a822 */ 	sub	$s5,$v1,$s5
/*    19b2c:	02b30019 */ 	multu	$s5,$s3
/*    19b30:	0000a812 */ 	mflo	$s5
/*    19b34:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19b38:	02958822 */ 	sub	$s1,$s4,$s5
/*    19b3c:	06210002 */ 	bgez	$s1,.L00019b48
/*    19b40:	00000000 */ 	sll	$zero,$zero,0x0
/*    19b44:	02238820 */ 	add	$s1,$s1,$v1
.L00019b48:
/*    19b48:	95140006 */ 	lhu	$s4,0x6($t0)
/*    19b4c:	0254a822 */ 	sub	$s5,$s2,$s4
/*    19b50:	06a10002 */ 	bgez	$s5,.L00019b5c
/*    19b54:	00000000 */ 	sll	$zero,$zero,0x0
/*    19b58:	02a3a820 */ 	add	$s5,$s5,$v1
.L00019b5c:
/*    19b5c:	34018000 */ 	dli	$at,0x8000
/*    19b60:	02a1082a */ 	slt	$at,$s5,$at
/*    19b64:	1020000b */ 	beqz	$at,.L00019b94
/*    19b68:	00000000 */ 	sll	$zero,$zero,0x0
/*    19b6c:	02b30019 */ 	multu	$s5,$s3
/*    19b70:	0000a812 */ 	mflo	$s5
/*    19b74:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19b78:	02959020 */ 	add	$s2,$s4,$s5
/*    19b7c:	3c010001 */ 	lui	$at,0x1
/*    19b80:	0241082a */ 	slt	$at,$s2,$at
/*    19b84:	1420000c */ 	bnez	$at,.L00019bb8
/*    19b88:	00000000 */ 	sll	$zero,$zero,0x0
/*    19b8c:	080066ee */ 	j	0x19bb8
/*    19b90:	02439022 */ 	sub	$s2,$s2,$v1
.L00019b94:
/*    19b94:	0075a822 */ 	sub	$s5,$v1,$s5
/*    19b98:	02b30019 */ 	multu	$s5,$s3
/*    19b9c:	0000a812 */ 	mflo	$s5
/*    19ba0:	0015ab03 */ 	sra	$s5,$s5,0xc
/*    19ba4:	02959022 */ 	sub	$s2,$s4,$s5
/*    19ba8:	06410003 */ 	bgez	$s2,.L00019bb8
/*    19bac:	00000000 */ 	sll	$zero,$zero,0x0
/*    19bb0:	3c140001 */ 	lui	$s4,0x1
/*    19bb4:	02549020 */ 	add	$s2,$s2,$s4
.L00019bb8:
/*    19bb8:	a5100002 */ 	sh	$s0,0x2($t0)
/*    19bbc:	a5110004 */ 	sh	$s1,0x4($t0)
/*    19bc0:	a5120006 */ 	sh	$s2,0x6($t0)
/*    19bc4:	21080008 */ 	addi	$t0,$t0,0x8
/*    19bc8:	014b082a */ 	slt	$at,$t2,$t3
/*    19bcc:	1420ff44 */ 	bnez	$at,.L000198e0
/*    19bd0:	00000000 */ 	sll	$zero,$zero,0x0
/*    19bd4:	8fbf07ac */ 	lw	$ra,0x7ac($sp)
/*    19bd8:	03e00008 */ 	jr	$ra
/*    19bdc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00019be0
/*    19be0:	1060004c */ 	beqz	$v1,.L00019d14
/*    19be4:	20020000 */ 	addi	$v0,$zero,0x0
/*    19be8:	0383082a */ 	slt	$at,$gp,$v1
/*    19bec:	10200041 */ 	beqz	$at,.L00019cf4
/*    19bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*    19bf4:	007c1822 */ 	sub	$v1,$v1,$gp
/*    19bf8:	20160001 */ 	addi	$s6,$zero,0x1
/*    19bfc:	0396b004 */ 	sllv	$s6,$s6,$gp
/*    19c00:	22d6ffff */ 	addi	$s6,$s6,-1
/*    19c04:	03d6b024 */ 	and	$s6,$s8,$s6
/*    19c08:	0076b004 */ 	sllv	$s6,$s6,$v1
/*    19c0c:	00561025 */ 	or	$v0,$v0,$s6
/*    19c10:	016eb022 */ 	sub	$s6,$t3,$t6
/*    19c14:	2ac10004 */ 	slti	$at,$s6,0x4
/*    19c18:	14200002 */ 	bnez	$at,.L00019c24
/*    19c1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    19c20:	24160004 */ 	addiu	$s6,$zero,0x4
.L00019c24:
/*    19c24:	31de0003 */ 	andi	$s8,$t6,0x3
/*    19c28:	27defffc */ 	addiu	$s8,$s8,-4
/*    19c2c:	001ef022 */ 	neg	$s8,$s8
/*    19c30:	13c00005 */ 	beqz	$s8,.L00019c48
/*    19c34:	00000000 */ 	sll	$zero,$zero,0x0
/*    19c38:	03d6082a */ 	slt	$at,$s8,$s6
/*    19c3c:	10200002 */ 	beqz	$at,.L00019c48
/*    19c40:	00000000 */ 	sll	$zero,$zero,0x0
/*    19c44:	03c0b025 */ 	or	$s6,$s8,$zero
.L00019c48:
/*    19c48:	3c1e8006 */ 	lui	$s8,%hi(var8005ef7c)
/*    19c4c:	27deef7c */ 	addiu	$s8,$s8,%lo(var8005ef7c)
/*    19c50:	0016b080 */ 	sll	$s6,$s6,0x2
/*    19c54:	03d6b020 */ 	add	$s6,$s8,$s6
/*    19c58:	8ed60000 */ 	lw	$s6,0x0($s6)
/*    19c5c:	02c00008 */ 	jr	$s6
/*    19c60:	91de0000 */ 	lbu	$s8,0x0($t6)
/*    19c64:	25ce0001 */ 	addiu	$t6,$t6,0x1
/*    19c68:	080066fa */ 	j	0x19be8
/*    19c6c:	241c0008 */ 	addiu	$gp,$zero,0x8
/*    19c70:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19c74:	91d60001 */ 	lbu	$s6,0x1($t6)
/*    19c78:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19c7c:	25ce0002 */ 	addiu	$t6,$t6,0x2
/*    19c80:	080066fa */ 	j	0x19be8
/*    19c84:	241c0010 */ 	addiu	$gp,$zero,0x10
/*    19c88:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19c8c:	91d60001 */ 	lbu	$s6,0x1($t6)
/*    19c90:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19c94:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19c98:	91d60002 */ 	lbu	$s6,0x2($t6)
/*    19c9c:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19ca0:	25ce0003 */ 	addiu	$t6,$t6,0x3
/*    19ca4:	080066fa */ 	j	0x19be8
/*    19ca8:	241c0018 */ 	addiu	$gp,$zero,0x18
/*    19cac:	31d60003 */ 	andi	$s6,$t6,0x3
/*    19cb0:	12c0000c */ 	beqz	$s6,.L00019ce4
/*    19cb4:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19cb8:	91d60001 */ 	lbu	$s6,0x1($t6)
/*    19cbc:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19cc0:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19cc4:	91d60002 */ 	lbu	$s6,0x2($t6)
/*    19cc8:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19ccc:	001ef200 */ 	sll	$s8,$s8,0x8
/*    19cd0:	91d60003 */ 	lbu	$s6,0x3($t6)
/*    19cd4:	03d6f025 */ 	or	$s8,$s8,$s6
/*    19cd8:	25ce0004 */ 	addiu	$t6,$t6,0x4
/*    19cdc:	080066fa */ 	j	0x19be8
/*    19ce0:	241c0020 */ 	addiu	$gp,$zero,0x20
.L00019ce4:
/*    19ce4:	8dde0000 */ 	lw	$s8,0x0($t6)
/*    19ce8:	25ce0004 */ 	addiu	$t6,$t6,0x4
/*    19cec:	080066fa */ 	j	0x19be8
/*    19cf0:	241c0020 */ 	addiu	$gp,$zero,0x20
.L00019cf4:
/*    19cf4:	10600007 */ 	beqz	$v1,.L00019d14
/*    19cf8:	0383e022 */ 	sub	$gp,$gp,$v1
/*    19cfc:	039eb007 */ 	srav	$s6,$s8,$gp
/*    19d00:	20170001 */ 	addi	$s7,$zero,0x1
/*    19d04:	0077b804 */ 	sllv	$s7,$s7,$v1
/*    19d08:	22f7ffff */ 	addi	$s7,$s7,-1
/*    19d0c:	02d7b024 */ 	and	$s6,$s6,$s7
/*    19d10:	00561025 */ 	or	$v0,$v0,$s6
.L00019d14:
/*    19d14:	03e00008 */ 	jr	$ra
/*    19d18:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00019d1c
/*    19d1c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    19d20:	afbc0000 */ 	sw	$gp,0x0($sp)
/*    19d24:	afa80004 */ 	sw	$t0,0x4($sp)
/*    19d28:	afa90008 */ 	sw	$t1,0x8($sp)
/*    19d2c:	afaa000c */ 	sw	$t2,0xc($sp)
/*    19d30:	afab0010 */ 	sw	$t3,0x10($sp)
/*    19d34:	afac0014 */ 	sw	$t4,0x14($sp)
/*    19d38:	afbf0018 */ 	sw	$ra,0x18($sp)
/*    19d3c:	8f8c0004 */ 	lw	$t4,0x4($gp)
/*    19d40:	3c0a8006 */ 	lui	$t2,%hi(var8005ef90)
/*    19d44:	254aef90 */ 	addiu	$t2,$t2,%lo(var8005ef90)
/*    19d48:	97890000 */ 	lhu	$t1,0x0($gp)
/*    19d4c:	312900ff */ 	andi	$t1,$t1,0xff
/*    19d50:	00004025 */ 	or	$t0,$zero,$zero
/*    19d54:	2921001a */ 	slti	$at,$t1,0x1a
/*    19d58:	10200007 */ 	beqz	$at,.L00019d78
/*    19d5c:	8cab0010 */ 	lw	$t3,0x10($a1)
/*    19d60:	01495020 */ 	add	$t2,$t2,$t1
/*    19d64:	914a0000 */ 	lbu	$t2,0x0($t2)
/*    19d68:	240100ff */ 	addiu	$at,$zero,0xff
/*    19d6c:	11410002 */ 	beq	$t2,$at,.L00019d78
/*    19d70:	018a5020 */ 	add	$t2,$t4,$t2
/*    19d74:	95480000 */ 	lhu	$t0,0x0($t2)
.L00019d78:
/*    19d78:	8fa90818 */ 	lw	$t1,0x818($sp)
/*    19d7c:	1120000c */ 	beqz	$t1,.L00019db0
/*    19d80:	00000000 */ 	sll	$zero,$zero,0x0
.L00019d84:
/*    19d84:	8f890008 */ 	lw	$t1,0x8($gp)
/*    19d88:	11200009 */ 	beqz	$t1,.L00019db0
/*    19d8c:	0120e025 */ 	or	$gp,$t1,$zero
/*    19d90:	97890000 */ 	lhu	$t1,0x0($gp)
/*    19d94:	312900ff */ 	andi	$t1,$t1,0xff
/*    19d98:	24010017 */ 	addiu	$at,$zero,0x17
/*    19d9c:	1521fff9 */ 	bne	$t1,$at,.L00019d84
/*    19da0:	00000000 */ 	sll	$zero,$zero,0x0
/*    19da4:	0c006747 */ 	jal	func00019d1c
/*    19da8:	00000000 */ 	sll	$zero,$zero,0x0
/*    19dac:	8c4b0004 */ 	lw	$t3,0x4($v0)
.L00019db0:
/*    19db0:	00084080 */ 	sll	$t0,$t0,0x2
/*    19db4:	01681020 */ 	add	$v0,$t3,$t0
/*    19db8:	8fbc0000 */ 	lw	$gp,0x0($sp)
/*    19dbc:	8fa80004 */ 	lw	$t0,0x4($sp)
/*    19dc0:	8fa90008 */ 	lw	$t1,0x8($sp)
/*    19dc4:	8faa000c */ 	lw	$t2,0xc($sp)
/*    19dc8:	8fab0010 */ 	lw	$t3,0x10($sp)
/*    19dcc:	8fac0014 */ 	lw	$t4,0x14($sp)
/*    19dd0:	8fbf0018 */ 	lw	$ra,0x18($sp)
/*    19dd4:	03e00008 */ 	jr	$ra
/*    19dd8:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func00019ddc
/*    19ddc:	afbf07ac */ 	sw	$ra,0x7ac($sp)
/*    19de0:	46008142 */ 	mul.s	$f5,$f16,$f0
/*    19de4:	44802000 */ 	mtc1	$zero,$f4
/*    19de8:	46018982 */ 	mul.s	$f6,$f17,$f1
/*    19dec:	00000000 */ 	sll	$zero,$zero,0x0
/*    19df0:	460291c2 */ 	mul.s	$f7,$f18,$f2
/*    19df4:	46062980 */ 	add.s	$f6,$f5,$f6
/*    19df8:	46039942 */ 	mul.s	$f5,$f19,$f3
/*    19dfc:	46073180 */ 	add.s	$f6,$f6,$f7
/*    19e00:	46053180 */ 	add.s	$f6,$f6,$f5
/*    19e04:	4604303c */ 	c.lt.s	$f6,$f4
/*    19e08:	45020006 */ 	bc1fl	.L00019e24
/*    19e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*    19e10:	46000007 */ 	neg.s	$f0,$f0
/*    19e14:	46000847 */ 	neg.s	$f1,$f1
/*    19e18:	46001087 */ 	neg.s	$f2,$f2
/*    19e1c:	08006778 */ 	j	0x19de0
/*    19e20:	460018c7 */ 	neg.s	$f3,$f3
.L00019e24:
/*    19e24:	3c017005 */ 	lui	$at,%hi(var70054224)
/*    19e28:	c4274224 */ 	lwc1	$f7,%lo(var70054224)($at)
/*    19e2c:	4607303c */ 	c.lt.s	$f6,$f7
/*    19e30:	45020013 */ 	bc1fl	.L00019e80
/*    19e34:	00000000 */ 	sll	$zero,$zero,0x0
/*    19e38:	4610f182 */ 	mul.s	$f6,$f30,$f16
/*    19e3c:	461e2941 */ 	sub.s	$f5,$f5,$f30
/*    19e40:	460029c2 */ 	mul.s	$f7,$f5,$f0
/*    19e44:	46063801 */ 	sub.s	$f0,$f7,$f6
/*    19e48:	4611f182 */ 	mul.s	$f6,$f30,$f17
/*    19e4c:	00000000 */ 	sll	$zero,$zero,0x0
/*    19e50:	460129c2 */ 	mul.s	$f7,$f5,$f1
/*    19e54:	00000000 */ 	sll	$zero,$zero,0x0
/*    19e58:	4612f202 */ 	mul.s	$f8,$f30,$f18
/*    19e5c:	46063841 */ 	sub.s	$f1,$f7,$f6
/*    19e60:	46022a42 */ 	mul.s	$f9,$f5,$f2
/*    19e64:	00000000 */ 	sll	$zero,$zero,0x0
/*    19e68:	4613f182 */ 	mul.s	$f6,$f30,$f19
/*    19e6c:	46084881 */ 	sub.s	$f2,$f9,$f8
/*    19e70:	460329c2 */ 	mul.s	$f7,$f5,$f3
/*    19e74:	8fbf07ac */ 	lw	$ra,0x7ac($sp)
/*    19e78:	03e00008 */ 	jr	$ra
/*    19e7c:	46063881 */ 	sub.s	$f2,$f7,$f6
.L00019e80:
/*    19e80:	3c017005 */ 	lui	$at,%hi(var70054228)
/*    19e84:	c4274228 */ 	lwc1	$f7,%lo(var70054228)($at)
/*    19e88:	4607303e */ 	c.le.s	$f6,$f7
/*    19e8c:	45000024 */ 	bc1f	.L00019f20
/*    19e90:	00000000 */ 	sll	$zero,$zero,0x0
/*    19e94:	0c0068b7 */ 	jal	func0001a2dc
/*    19e98:	00000000 */ 	sll	$zero,$zero,0x0
/*    19e9c:	46000506 */ 	mov.s	$f20,$f0
/*    19ea0:	0c0068f7 */ 	jal	sinf
/*    19ea4:	46003b06 */ 	mov.s	$f12,$f7
/*    19ea8:	4600fb06 */ 	mov.s	$f12,$f31
/*    19eac:	461e6301 */ 	sub.s	$f12,$f12,$f30
/*    19eb0:	46076302 */ 	mul.s	$f12,$f12,$f7
/*    19eb4:	0c0068f7 */ 	jal	sinf
/*    19eb8:	46000546 */ 	mov.s	$f21,$f0
/*    19ebc:	461e3b02 */ 	mul.s	$f12,$f7,$f30
/*    19ec0:	0c0068f7 */ 	jal	sinf
/*    19ec4:	46000586 */ 	mov.s	$f22,$f0
/*    19ec8:	4615b143 */ 	div.s	$f5,$f22,$f21
/*    19ecc:	00000000 */ 	sll	$zero,$zero,0x0
/*    19ed0:	46150783 */ 	div.s	$f30,$f0,$f21
/*    19ed4:	4600a006 */ 	mov.s	$f0,$f20
/*    19ed8:	46102982 */ 	mul.s	$f6,$f5,$f16
/*    19edc:	00000000 */ 	sll	$zero,$zero,0x0
/*    19ee0:	4600f1c2 */ 	mul.s	$f7,$f30,$f0
/*    19ee4:	00000000 */ 	sll	$zero,$zero,0x0
/*    19ee8:	46112a02 */ 	mul.s	$f8,$f5,$f17
/*    19eec:	46073000 */ 	add.s	$f0,$f6,$f7
/*    19ef0:	4601f242 */ 	mul.s	$f9,$f30,$f1
/*    19ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*    19ef8:	46122982 */ 	mul.s	$f6,$f5,$f18
/*    19efc:	46094040 */ 	add.s	$f1,$f8,$f9
/*    19f00:	4602f1c2 */ 	mul.s	$f7,$f30,$f2
/*    19f04:	00000000 */ 	sll	$zero,$zero,0x0
/*    19f08:	46132a02 */ 	mul.s	$f8,$f5,$f19
/*    19f0c:	46073080 */ 	add.s	$f2,$f6,$f7
/*    19f10:	4603f242 */ 	mul.s	$f9,$f30,$f3
/*    19f14:	8fbf07ac */ 	lw	$ra,0x7ac($sp)
/*    19f18:	03e00008 */ 	jr	$ra
/*    19f1c:	460940c0 */ 	add.s	$f3,$f8,$f9
.L00019f20:
/*    19f20:	4600f946 */ 	mov.s	$f5,$f31
/*    19f24:	080067b6 */ 	j	0x19ed8
/*    19f28:	461e2941 */ 	sub.s	$f5,$f5,$f30
);

GLOBAL_ASM(
glabel func00019f2c
/*    19f2c:	46020182 */ 	mul.s	$f6,$f0,$f2
/*    19f30:	00000000 */ 	sll	$zero,$zero,0x0
/*    19f34:	460301c2 */ 	mul.s	$f7,$f0,$f3
/*    19f38:	00000000 */ 	sll	$zero,$zero,0x0
/*    19f3c:	46020a02 */ 	mul.s	$f8,$f1,$f2
/*    19f40:	00000000 */ 	sll	$zero,$zero,0x0
/*    19f44:	46030a42 */ 	mul.s	$f9,$f1,$f3
/*    19f48:	00000000 */ 	sll	$zero,$zero,0x0
/*    19f4c:	46043002 */ 	mul.s	$f0,$f6,$f4
/*    19f50:	00000000 */ 	sll	$zero,$zero,0x0
/*    19f54:	46054842 */ 	mul.s	$f1,$f9,$f5
/*    19f58:	00000000 */ 	sll	$zero,$zero,0x0
/*    19f5c:	46044082 */ 	mul.s	$f2,$f8,$f4
/*    19f60:	46010000 */ 	add.s	$f0,$f0,$f1
/*    19f64:	46053842 */ 	mul.s	$f1,$f7,$f5
/*    19f68:	00000000 */ 	sll	$zero,$zero,0x0
/*    19f6c:	460538c2 */ 	mul.s	$f3,$f7,$f5
/*    19f70:	00000000 */ 	sll	$zero,$zero,0x0
/*    19f74:	46043a82 */ 	mul.s	$f10,$f7,$f4
/*    19f78:	46011041 */ 	sub.s	$f1,$f2,$f1
/*    19f7c:	460542c2 */ 	mul.s	$f11,$f8,$f5
/*    19f80:	00000000 */ 	sll	$zero,$zero,0x0
/*    19f84:	46053682 */ 	mul.s	$f26,$f6,$f5
/*    19f88:	460b5080 */ 	add.s	$f2,$f10,$f11
/*    19f8c:	46044a82 */ 	mul.s	$f10,$f9,$f4
/*    19f90:	03e00008 */ 	jr	$ra
/*    19f94:	460ad0c1 */ 	sub.s	$f3,$f26,$f10
);

GLOBAL_ASM(
glabel func00019f98
/*    19f98:	001f6820 */ 	add	$t5,$zero,$ra
/*    19f9c:	3c017005 */ 	lui	$at,%hi(var7005422c)
/*    19fa0:	c43d422c */ 	lwc1	$f29,%lo(var7005422c)($at)
/*    19fa4:	448c4000 */ 	mtc1	$t4,$f8
/*    19fa8:	448b3800 */ 	mtc1	$t3,$f7
/*    19fac:	448a3000 */ 	mtc1	$t2,$f6
/*    19fb0:	46804220 */ 	cvt.s.w	$f8,$f8
/*    19fb4:	468039e0 */ 	cvt.s.w	$f7,$f7
/*    19fb8:	468031a0 */ 	cvt.s.w	$f6,$f6
/*    19fbc:	461d4202 */ 	mul.s	$f8,$f8,$f29
/*    19fc0:	3c017005 */ 	lui	$at,%hi(var70054230)
/*    19fc4:	c43e4230 */ 	lwc1	$f30,%lo(var70054230)($at)
/*    19fc8:	461d39c2 */ 	mul.s	$f7,$f7,$f29
/*    19fcc:	46004306 */ 	mov.s	$f12,$f8
/*    19fd0:	0c0068f7 */ 	jal	sinf
/*    19fd4:	00000000 */ 	sll	$zero,$zero,0x0
/*    19fd8:	461d3182 */ 	mul.s	$f6,$f6,$f29
/*    19fdc:	461e4300 */ 	add.s	$f12,$f8,$f30
/*    19fe0:	0c0068f7 */ 	jal	sinf
/*    19fe4:	46000146 */ 	mov.s	$f5,$f0
/*    19fe8:	46003b06 */ 	mov.s	$f12,$f7
/*    19fec:	0c0068f7 */ 	jal	sinf
/*    19ff0:	46000106 */ 	mov.s	$f4,$f0
/*    19ff4:	461e3b00 */ 	add.s	$f12,$f7,$f30
/*    19ff8:	0c0068f7 */ 	jal	sinf
/*    19ffc:	460000c6 */ 	mov.s	$f3,$f0
/*    1a000:	46003306 */ 	mov.s	$f12,$f6
/*    1a004:	0c0068f7 */ 	jal	sinf
/*    1a008:	46000086 */ 	mov.s	$f2,$f0
/*    1a00c:	461e3300 */ 	add.s	$f12,$f6,$f30
/*    1a010:	0c0068f7 */ 	jal	sinf
/*    1a014:	46000046 */ 	mov.s	$f1,$f0
/*    1a018:	000df820 */ 	add	$ra,$zero,$t5
/*    1a01c:	03e00008 */ 	jr	$ra
/*    1a020:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0001a024
/*    1a024:	001f6820 */ 	add	$t5,$zero,$ra
/*    1a028:	3c017005 */ 	lui	$at,%hi(var70054234)
/*    1a02c:	c43d4234 */ 	lwc1	$f29,%lo(var70054234)($at)
/*    1a030:	448c4000 */ 	mtc1	$t4,$f8
/*    1a034:	448b3800 */ 	mtc1	$t3,$f7
/*    1a038:	448a3000 */ 	mtc1	$t2,$f6
/*    1a03c:	46804220 */ 	cvt.s.w	$f8,$f8
/*    1a040:	468039e0 */ 	cvt.s.w	$f7,$f7
/*    1a044:	468031a0 */ 	cvt.s.w	$f6,$f6
/*    1a048:	461d4202 */ 	mul.s	$f8,$f8,$f29
/*    1a04c:	3c017005 */ 	lui	$at,%hi(var70054238)
/*    1a050:	c43e4238 */ 	lwc1	$f30,%lo(var70054238)($at)
/*    1a054:	461d39c2 */ 	mul.s	$f7,$f7,$f29
/*    1a058:	0c0068f7 */ 	jal	sinf
/*    1a05c:	46004306 */ 	mov.s	$f12,$f8
/*    1a060:	461d3182 */ 	mul.s	$f6,$f6,$f29
/*    1a064:	461e4300 */ 	add.s	$f12,$f8,$f30
/*    1a068:	0c0068f7 */ 	jal	sinf
/*    1a06c:	46000146 */ 	mov.s	$f5,$f0
/*    1a070:	46003b06 */ 	mov.s	$f12,$f7
/*    1a074:	0c0068f7 */ 	jal	sinf
/*    1a078:	46000106 */ 	mov.s	$f4,$f0
/*    1a07c:	461e3b00 */ 	add.s	$f12,$f7,$f30
/*    1a080:	0c0068f7 */ 	jal	sinf
/*    1a084:	460000c6 */ 	mov.s	$f3,$f0
/*    1a088:	46003306 */ 	mov.s	$f12,$f6
/*    1a08c:	0c0068f7 */ 	jal	sinf
/*    1a090:	46000086 */ 	mov.s	$f2,$f0
/*    1a094:	461e3300 */ 	add.s	$f12,$f6,$f30
/*    1a098:	0c0068f7 */ 	jal	sinf
/*    1a09c:	46000046 */ 	mov.s	$f1,$f0
/*    1a0a0:	000df820 */ 	add	$ra,$zero,$t5
/*    1a0a4:	03e00008 */ 	jr	$ra
/*    1a0a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0001a0ac
/*    1a0ac:	46050982 */ 	mul.s	$f6,$f1,$f5
/*    1a0b0:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a0b4:	460501c2 */ 	mul.s	$f7,$f0,$f5
/*    1a0b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a0bc:	46040a02 */ 	mul.s	$f8,$f1,$f4
/*    1a0c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a0c4:	46040242 */ 	mul.s	$f9,$f0,$f4
/*    1a0c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a0cc:	46041302 */ 	mul.s	$f12,$f2,$f4
/*    1a0d0:	46001b87 */ 	neg.s	$f14,$f3
/*    1a0d4:	46051342 */ 	mul.s	$f13,$f2,$f5
/*    1a0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a0dc:	460343c2 */ 	mul.s	$f15,$f8,$f3
/*    1a0e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a0e4:	46033402 */ 	mul.s	$f16,$f6,$f3
/*    1a0e8:	46077bc1 */ 	sub.s	$f15,$f15,$f7
/*    1a0ec:	46020c42 */ 	mul.s	$f17,$f1,$f2
/*    1a0f0:	46098400 */ 	add.s	$f16,$f16,$f9
/*    1a0f4:	46034c82 */ 	mul.s	$f18,$f9,$f3
/*    1a0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a0fc:	46033cc2 */ 	mul.s	$f19,$f7,$f3
/*    1a100:	46069480 */ 	add.s	$f18,$f18,$f6
/*    1a104:	46020502 */ 	mul.s	$f20,$f0,$f2
/*    1a108:	03e00008 */ 	jr	$ra
/*    1a10c:	46089cc1 */ 	sub.s	$f19,$f19,$f8
);

GLOBAL_ASM(
glabel func0001a110
/*    1a110:	46000102 */ 	mul.s	$f4,$f0,$f0
/*    1a114:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a118:	46010942 */ 	mul.s	$f5,$f1,$f1
/*    1a11c:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a120:	46021182 */ 	mul.s	$f6,$f2,$f2
/*    1a124:	46052100 */ 	add.s	$f4,$f4,$f5
/*    1a128:	46031942 */ 	mul.s	$f5,$f3,$f3
/*    1a12c:	46062100 */ 	add.s	$f4,$f4,$f6
/*    1a130:	3c014000 */ 	lui	$at,0x4000
/*    1a134:	44813000 */ 	mtc1	$at,$f6
/*    1a138:	46052100 */ 	add.s	$f4,$f4,$f5
/*    1a13c:	46043103 */ 	div.s	$f4,$f6,$f4
/*    1a140:	46040942 */ 	mul.s	$f5,$f1,$f4
/*    1a144:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a148:	46041182 */ 	mul.s	$f6,$f2,$f4
/*    1a14c:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a150:	460419c2 */ 	mul.s	$f7,$f3,$f4
/*    1a154:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a158:	46050202 */ 	mul.s	$f8,$f0,$f5
/*    1a15c:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a160:	46060242 */ 	mul.s	$f9,$f0,$f6
/*    1a164:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a168:	46070282 */ 	mul.s	$f10,$f0,$f7
/*    1a16c:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a170:	46050ac2 */ 	mul.s	$f11,$f1,$f5
/*    1a174:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a178:	46060e02 */ 	mul.s	$f24,$f1,$f6
/*    1a17c:	460bfc01 */ 	sub.s	$f16,$f31,$f11
/*    1a180:	46070e42 */ 	mul.s	$f25,$f1,$f7
/*    1a184:	460bfd01 */ 	sub.s	$f20,$f31,$f11
/*    1a188:	46061682 */ 	mul.s	$f26,$f2,$f6
/*    1a18c:	460ac340 */ 	add.s	$f13,$f24,$f10
/*    1a190:	460716c2 */ 	mul.s	$f27,$f2,$f7
/*    1a194:	461afb01 */ 	sub.s	$f12,$f31,$f26
/*    1a198:	46071f02 */ 	mul.s	$f28,$f3,$f7
/*    1a19c:	4609cb81 */ 	sub.s	$f14,$f25,$f9
/*    1a1a0:	461c6301 */ 	sub.s	$f12,$f12,$f28
/*    1a1a4:	460ac3c1 */ 	sub.s	$f15,$f24,$f10
/*    1a1a8:	461c8401 */ 	sub.s	$f16,$f16,$f28
/*    1a1ac:	4608dc40 */ 	add.s	$f17,$f27,$f8
/*    1a1b0:	4609cc80 */ 	add.s	$f18,$f25,$f9
/*    1a1b4:	4608dcc1 */ 	sub.s	$f19,$f27,$f8
/*    1a1b8:	03e00008 */ 	jr	$ra
/*    1a1bc:	461aa501 */ 	sub.s	$f20,$f20,$f26
);

GLOBAL_ASM(
glabel func0001a1c0
/*    1a1c0:	240a0003 */ 	addiu	$t2,$zero,0x3
.L0001a1c4:
/*    1a1c4:	c5000000 */ 	lwc1	$f0,0x0($t0)
/*    1a1c8:	25080004 */ 	addiu	$t0,$t0,0x4
/*    1a1cc:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*    1a1d0:	c501000c */ 	lwc1	$f1,0xc($t0)
/*    1a1d4:	c502001c */ 	lwc1	$f2,0x1c($t0)
/*    1a1d8:	460d0942 */ 	mul.s	$f5,$f1,$f13
/*    1a1dc:	c503002c */ 	lwc1	$f3,0x2c($t0)
/*    1a1e0:	460e1182 */ 	mul.s	$f6,$f2,$f14
/*    1a1e4:	460521c0 */ 	add.s	$f7,$f4,$f5
/*    1a1e8:	460f0202 */ 	mul.s	$f8,$f0,$f15
/*    1a1ec:	460639c0 */ 	add.s	$f7,$f7,$f6
/*    1a1f0:	46100a42 */ 	mul.s	$f9,$f1,$f16
/*    1a1f4:	e5270000 */ 	swc1	$f7,0x0($t1)
/*    1a1f8:	46111282 */ 	mul.s	$f10,$f2,$f17
/*    1a1fc:	460942c0 */ 	add.s	$f11,$f8,$f9
/*    1a200:	46120102 */ 	mul.s	$f4,$f0,$f18
/*    1a204:	460a5ac0 */ 	add.s	$f11,$f11,$f10
/*    1a208:	46130942 */ 	mul.s	$f5,$f1,$f19
/*    1a20c:	e52b0010 */ 	swc1	$f11,0x10($t1)
/*    1a210:	46141182 */ 	mul.s	$f6,$f2,$f20
/*    1a214:	460521c0 */ 	add.s	$f7,$f4,$f5
/*    1a218:	46150202 */ 	mul.s	$f8,$f0,$f21
/*    1a21c:	460639c0 */ 	add.s	$f7,$f7,$f6
/*    1a220:	46160a42 */ 	mul.s	$f9,$f1,$f22
/*    1a224:	e5270020 */ 	swc1	$f7,0x20($t1)
/*    1a228:	46171282 */ 	mul.s	$f10,$f2,$f23
/*    1a22c:	46094200 */ 	add.s	$f8,$f8,$f9
/*    1a230:	46035280 */ 	add.s	$f10,$f10,$f3
/*    1a234:	254affff */ 	addiu	$t2,$t2,-1
/*    1a238:	460a4280 */ 	add.s	$f10,$f8,$f10
/*    1a23c:	25290004 */ 	addiu	$t1,$t1,0x4
/*    1a240:	1540ffe0 */ 	bnez	$t2,.L0001a1c4
/*    1a244:	e52a002c */ 	swc1	$f10,0x2c($t1)
/*    1a248:	ad200000 */ 	sw	$zero,0x0($t1)
/*    1a24c:	ad200010 */ 	sw	$zero,0x10($t1)
/*    1a250:	ad200020 */ 	sw	$zero,0x20($t1)
/*    1a254:	03e00008 */ 	jr	$ra
/*    1a258:	e53f0030 */ 	swc1	$f31,0x30($t1)
);

GLOBAL_ASM(
glabel func0001a25c
.L0001a25c:
/*    1a25c:	85090000 */ 	lh	$t1,0x0($t0)
/*    1a260:	312900ff */ 	andi	$t1,$t1,0xff
/*    1a264:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    1a268:	152a0007 */ 	bne	$t1,$t2,.L0001a288
/*    1a26c:	240a0002 */ 	addiu	$t2,$zero,0x2
/*    1a270:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*    1a274:	954a0002 */ 	lhu	$t2,0x2($t2)
/*    1a278:	000a5180 */ 	sll	$t2,$t2,0x6
/*    1a27c:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1a280:	03e00008 */ 	jr	$ra
/*    1a284:	012a4020 */ 	add	$t0,$t1,$t2
.L0001a288:
/*    1a288:	152a0007 */ 	bne	$t1,$t2,.L0001a2a8
/*    1a28c:	240a0015 */ 	addiu	$t2,$zero,0x15
/*    1a290:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*    1a294:	954a000e */ 	lhu	$t2,0xe($t2)
/*    1a298:	000a5180 */ 	sll	$t2,$t2,0x6
/*    1a29c:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1a2a0:	03e00008 */ 	jr	$ra
/*    1a2a4:	012a4020 */ 	add	$t0,$t1,$t2
.L0001a2a8:
/*    1a2a8:	152a0007 */ 	bne	$t1,$t2,.L0001a2c8
/*    1a2ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a2b0:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*    1a2b4:	954a000c */ 	lhu	$t2,0xc($t2)
/*    1a2b8:	000a5180 */ 	sll	$t2,$t2,0x6
/*    1a2bc:	8ca9000c */ 	lw	$t1,0xc($a1)
/*    1a2c0:	03e00008 */ 	jr	$ra
/*    1a2c4:	012a4020 */ 	add	$t0,$t1,$t2
.L0001a2c8:
/*    1a2c8:	8d080008 */ 	lw	$t0,0x8($t0)
/*    1a2cc:	1500ffe3 */ 	bnez	$t0,.L0001a25c
/*    1a2d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a2d4:	03e00008 */ 	jr	$ra
/*    1a2d8:	00004020 */ 	add	$t0,$zero,$zero
);

GLOBAL_ASM(
glabel func0001a2dc
/*    1a2dc:	3c017005 */ 	lui	$at,%hi(var7005423c)
/*    1a2e0:	c427423c */ 	lwc1	$f7,%lo(var7005423c)($at)
/*    1a2e4:	460731c2 */ 	mul.s	$f7,$f6,$f7
/*    1a2e8:	460039cd */ 	trunc.w.s	$f7,$f7
/*    1a2ec:	440a3800 */ 	mfc1	$t2,$f7
/*    1a2f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a2f4:	29417fff */ 	slti	$at,$t2,0x7fff
/*    1a2f8:	14200003 */ 	bnez	$at,.L0001a308
/*    1a2fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a300:	10000005 */ 	beqz	$zero,.L0001a318
/*    1a304:	240a7fff */ 	addiu	$t2,$zero,0x7fff
.L0001a308:
/*    1a308:	29418001 */ 	slti	$at,$t2,-32767
/*    1a30c:	10200002 */ 	beqz	$at,.L0001a318
/*    1a310:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a314:	240a8001 */ 	addiu	$t2,$zero,-32767
.L0001a318:
/*    1a318:	05410002 */ 	bgez	$t2,.L0001a324
/*    1a31c:	000a5820 */ 	add	$t3,$zero,$t2
/*    1a320:	000b5822 */ 	neg	$t3,$t3
.L0001a324:
/*    1a324:	29617fe0 */ 	slti	$at,$t3,0x7fe0
/*    1a328:	14200007 */ 	bnez	$at,.L0001a348
/*    1a32c:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a330:	3c0c8007 */ 	lui	$t4,%hi(var8006af8c)
/*    1a334:	258caf8c */ 	addiu	$t4,$t4,%lo(var8006af8c)
/*    1a338:	216b8020 */ 	addi	$t3,$t3,-32736
/*    1a33c:	240d0003 */ 	addiu	$t5,$zero,0x3
/*    1a340:	1000000e */ 	beqz	$zero,.L0001a37c
/*    1a344:	240e0007 */ 	addiu	$t6,$zero,0x7
.L0001a348:
/*    1a348:	29617800 */ 	slti	$at,$t3,0x7800
/*    1a34c:	14200007 */ 	bnez	$at,.L0001a36c
/*    1a350:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a354:	3c0c8007 */ 	lui	$t4,%hi(var8006af0c)
/*    1a358:	258caf0c */ 	addiu	$t4,$t4,%lo(var8006af0c)
/*    1a35c:	216b8800 */ 	addi	$t3,$t3,-30720
/*    1a360:	240d0005 */ 	addiu	$t5,$zero,0x5
/*    1a364:	10000005 */ 	beqz	$zero,.L0001a37c
/*    1a368:	240e001f */ 	addiu	$t6,$zero,0x1f
.L0001a36c:
/*    1a36c:	3c0c8007 */ 	lui	$t4,%hi(var8006ae90)
/*    1a370:	258cae90 */ 	addiu	$t4,$t4,%lo(var8006ae90)
/*    1a374:	240d0009 */ 	addiu	$t5,$zero,0x9
/*    1a378:	240e01ff */ 	addiu	$t6,$zero,0x1ff
.L0001a37c:
/*    1a37c:	01ab8007 */ 	srav	$s0,$t3,$t5
/*    1a380:	00108040 */ 	sll	$s0,$s0,0x1
/*    1a384:	01906020 */ 	add	$t4,$t4,$s0
/*    1a388:	95910000 */ 	lhu	$s1,0x0($t4)
/*    1a38c:	95920002 */ 	lhu	$s2,0x2($t4)
/*    1a390:	02329822 */ 	sub	$s3,$s1,$s2
/*    1a394:	016ea024 */ 	and	$s4,$t3,$t6
/*    1a398:	02740019 */ 	multu	$s3,$s4
/*    1a39c:	00009812 */ 	mflo	$s3
/*    1a3a0:	01b39807 */ 	srav	$s3,$s3,$t5
/*    1a3a4:	02335822 */ 	sub	$t3,$s1,$s3
/*    1a3a8:	05410002 */ 	bgez	$t2,.L0001a3b4
/*    1a3ac:	340affff */ 	dli	$t2,0xffff
/*    1a3b0:	014b5822 */ 	sub	$t3,$t2,$t3
.L0001a3b4:
/*    1a3b4:	448b4000 */ 	mtc1	$t3,$f8
/*    1a3b8:	3c017005 */ 	lui	$at,%hi(var70054240)
/*    1a3bc:	c4274240 */ 	lwc1	$f7,%lo(var70054240)($at)
/*    1a3c0:	46804220 */ 	cvt.s.w	$f8,$f8
/*    1a3c4:	460741c2 */ 	mul.s	$f7,$f8,$f7
/*    1a3c8:	03e00008 */ 	jr	$ra
/*    1a3cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel cosf
/*    1a3d0:	3c017005 */ 	lui	$at,%hi(var70054244)
/*    1a3d4:	c42d4244 */ 	lwc1	$f13,%lo(var70054244)($at)
/*    1a3d8:	460d6300 */ 	add.s	$f12,$f12,$f13
);

GLOBAL_ASM(
glabel sinf
/*    1a3dc:	44086000 */ 	mfc1	$t0,$f12
/*    1a3e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a3e4:	00084583 */ 	sra	$t0,$t0,0x16
/*    1a3e8:	310801ff */ 	andi	$t0,$t0,0x1ff
/*    1a3ec:	290100ff */ 	slti	$at,$t0,0xff
/*    1a3f0:	10200018 */ 	beqz	$at,.L0001a454
/*    1a3f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a3f8:	290100e6 */ 	slti	$at,$t0,0xe6
/*    1a3fc:	1420003c */ 	bnez	$at,.L0001a4f0
/*    1a400:	46006006 */ 	mov.s	$f0,$f12
/*    1a404:	460c6382 */ 	mul.s	$f14,$f12,$f12
/*    1a408:	3c017005 */ 	lui	$at,%hi(var70054248)
/*    1a40c:	c42f4248 */ 	lwc1	$f15,%lo(var70054248)($at)
/*    1a410:	3c017005 */ 	lui	$at,%hi(var7005424c)
/*    1a414:	c42d424c */ 	lwc1	$f13,%lo(var7005424c)($at)
/*    1a418:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a41c:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a420:	3c017005 */ 	lui	$at,%hi(var70054250)
/*    1a424:	c42d4250 */ 	lwc1	$f13,%lo(var70054250)($at)
/*    1a428:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a42c:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a430:	3c017005 */ 	lui	$at,%hi(var70054254)
/*    1a434:	c42d4254 */ 	lwc1	$f13,%lo(var70054254)($at)
/*    1a438:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a43c:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a440:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a444:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a448:	460c7bc2 */ 	mul.s	$f15,$f15,$f12
/*    1a44c:	03e00008 */ 	jr	$ra
/*    1a450:	460c7800 */ 	add.s	$f0,$f15,$f12
.L0001a454:
/*    1a454:	29010136 */ 	slti	$at,$t0,0x136
/*    1a458:	50200025 */ 	beqzl	$at,.L0001a4f0
/*    1a45c:	44800000 */ 	mtc1	$zero,$f0
/*    1a460:	3c017005 */ 	lui	$at,%hi(var70054258)
/*    1a464:	c42e4258 */ 	lwc1	$f14,%lo(var70054258)($at)
/*    1a468:	460c7382 */ 	mul.s	$f14,$f14,$f12
/*    1a46c:	4600738c */ 	round.w.s	$f14,$f14
/*    1a470:	44097000 */ 	mfc1	$t1,$f14
/*    1a474:	468073a0 */ 	cvt.s.w	$f14,$f14
/*    1a478:	3c017005 */ 	lui	$at,%hi(var7005425c)
/*    1a47c:	c42f425c */ 	lwc1	$f15,%lo(var7005425c)($at)
/*    1a480:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a484:	460f6301 */ 	sub.s	$f12,$f12,$f15
/*    1a488:	3c017005 */ 	lui	$at,%hi(var70054260)
/*    1a48c:	c42f4260 */ 	lwc1	$f15,%lo(var70054260)($at)
/*    1a490:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a494:	460f6301 */ 	sub.s	$f12,$f12,$f15
/*    1a498:	3c017005 */ 	lui	$at,%hi(var70054264)
/*    1a49c:	c42f4264 */ 	lwc1	$f15,%lo(var70054264)($at)
/*    1a4a0:	460c6382 */ 	mul.s	$f14,$f12,$f12
/*    1a4a4:	3c017005 */ 	lui	$at,%hi(var70054268)
/*    1a4a8:	c42d4268 */ 	lwc1	$f13,%lo(var70054268)($at)
/*    1a4ac:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a4b0:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a4b4:	3c017005 */ 	lui	$at,%hi(var7005426c)
/*    1a4b8:	c42d426c */ 	lwc1	$f13,%lo(var7005426c)($at)
/*    1a4bc:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a4c0:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a4c4:	3c017005 */ 	lui	$at,%hi(var70054270)
/*    1a4c8:	c42d4270 */ 	lwc1	$f13,%lo(var70054270)($at)
/*    1a4cc:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a4d0:	460f6bc0 */ 	add.s	$f15,$f13,$f15
/*    1a4d4:	460e7bc2 */ 	mul.s	$f15,$f15,$f14
/*    1a4d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a4dc:	460c7bc2 */ 	mul.s	$f15,$f15,$f12
/*    1a4e0:	31290001 */ 	andi	$t1,$t1,0x1
/*    1a4e4:	460c7800 */ 	add.s	$f0,$f15,$f12
/*    1a4e8:	55200001 */ 	bnezl	$t1,.L0001a4f0
/*    1a4ec:	46000007 */ 	neg.s	$f0,$f0
.L0001a4f0:
/*    1a4f0:	03e00008 */ 	jr	$ra
/*    1a4f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a4f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    1a4fc:	00000000 */ 	sll	$zero,$zero,0x0
);
