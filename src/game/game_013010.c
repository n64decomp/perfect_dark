#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f013010
/*  f013010:	3c018008 */ 	lui	$at,0x8008
/*  f013014:	ac20e4a0 */ 	sw	$zero,-0x1b60($at)
/*  f013018:	3c018008 */ 	lui	$at,0x8008
/*  f01301c:	ac20e4a4 */ 	sw	$zero,-0x1b5c($at)
/*  f013020:	3c013f80 */ 	lui	$at,0x3f80
/*  f013024:	44812000 */ 	mtc1	$at,$f4
/*  f013028:	3c08800a */ 	lui	$t0,%hi(var800a3434)
/*  f01302c:	3c018008 */ 	lui	$at,0x8008
/*  f013030:	25083434 */ 	addiu	$t0,$t0,%lo(var800a3434)
/*  f013034:	240e0006 */ 	addiu	$t6,$zero,0x6
/*  f013038:	e424e4a8 */ 	swc1	$f4,-0x1b58($at)
/*  f01303c:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f013040:	3c0f800a */ 	lui	$t7,0x800a
/*  f013044:	8defa474 */ 	lw	$t7,-0x5b8c($t7)
/*  f013048:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01304c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013050:	29e1005a */ 	slti	$at,$t7,0x5a
/*  f013054:	14200002 */ 	bnez	$at,.L0f013060
/*  f013058:	3c05800a */ 	lui	$a1,%hi(var800a3430)
/*  f01305c:	ad000000 */ 	sw	$zero,0x0($t0)
.L0f013060:
/*  f013060:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f013064:	24a53430 */ 	addiu	$a1,$a1,%lo(var800a3430)
/*  f013068:	54400004 */ 	bnezl	$v0,.L0f01307c
/*  f01306c:	000220c0 */ 	sll	$a0,$v0,0x3
/*  f013070:	1000002b */ 	beqz	$zero,.L0f013120
/*  f013074:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f013078:	000220c0 */ 	sll	$a0,$v0,0x3
.L0f01307c:
/*  f01307c:	00822021 */ 	addu	$a0,$a0,$v0
/*  f013080:	00042100 */ 	sll	$a0,$a0,0x4
/*  f013084:	00822023 */ 	subu	$a0,$a0,$v0
/*  f013088:	000420c0 */ 	sll	$a0,$a0,0x3
/*  f01308c:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f013090:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f013094:	0081c024 */ 	and	$t8,$a0,$at
/*  f013098:	03002025 */ 	or	$a0,$t8,$zero
/*  f01309c:	0c0048f2 */ 	jal	malloc
/*  f0130a0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0130a4:	3c08800a */ 	lui	$t0,%hi(var800a3434)
/*  f0130a8:	25083434 */ 	addiu	$t0,$t0,%lo(var800a3434)
/*  f0130ac:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0130b0:	3c05800a */ 	lui	$a1,%hi(var800a3430)
/*  f0130b4:	24a53430 */ 	addiu	$a1,$a1,%lo(var800a3430)
/*  f0130b8:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f0130bc:	1b200018 */ 	blez	$t9,.L0f013120
/*  f0130c0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0130c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0130c8:	240303c0 */ 	addiu	$v1,$zero,0x3c0
/*  f0130cc:	8ca90000 */ 	lw	$t1,0x0($a1)
.L0f0130d0:
/*  f0130d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0130d4:	01265021 */ 	addu	$t2,$t1,$a2
/*  f0130d8:	ad400000 */ 	sw	$zero,0x0($t2)
.L0f0130dc:
/*  f0130dc:	000460c0 */ 	sll	$t4,$a0,0x3
/*  f0130e0:	01846021 */ 	addu	$t4,$t4,$a0
/*  f0130e4:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f0130e8:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0130ec:	01846023 */ 	subu	$t4,$t4,$a0
/*  f0130f0:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0130f4:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f0130f8:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f0130fc:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f013100:	1443fff6 */ 	bne	$v0,$v1,.L0f0130dc
/*  f013104:	a5c0001c */ 	sh	$zero,0x1c($t6)
/*  f013108:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f01310c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f013110:	24c60478 */ 	addiu	$a2,$a2,0x478
/*  f013114:	008f082a */ 	slt	$at,$a0,$t7
/*  f013118:	5420ffed */ 	bnezl	$at,.L0f0130d0
/*  f01311c:	8ca90000 */ 	lw	$t1,0x0($a1)
.L0f013120:
/*  f013120:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f013124:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f013128:	03e00008 */ 	jr	$ra
/*  f01312c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f013130
/*  f013130:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*  f013134:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*  f013138:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01313c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f013140:	15c10006 */ 	bne	$t6,$at,.L0f01315c
/*  f013144:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013148:	3c08800a */ 	lui	$t0,%hi(var800a3444)
/*  f01314c:	25083444 */ 	addiu	$t0,$t0,%lo(var800a3444)
/*  f013150:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f013154:	10000005 */ 	beqz	$zero,.L0f01316c
/*  f013158:	ad0f0000 */ 	sw	$t7,0x0($t0)
.L0f01315c:
/*  f01315c:	3c08800a */ 	lui	$t0,%hi(var800a3444)
/*  f013160:	25083444 */ 	addiu	$t0,$t0,%lo(var800a3444)
/*  f013164:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f013168:	ad180000 */ 	sw	$t8,0x0($t0)
.L0f01316c:
/*  f01316c:	3c19800a */ 	lui	$t9,0x800a
/*  f013170:	8f39a474 */ 	lw	$t9,-0x5b8c($t9)
/*  f013174:	3c05800a */ 	lui	$a1,%hi(var800a3440)
/*  f013178:	24a53440 */ 	addiu	$a1,$a1,%lo(var800a3440)
/*  f01317c:	2b21005a */ 	slti	$at,$t9,0x5a
/*  f013180:	54200003 */ 	bnezl	$at,.L0f013190
/*  f013184:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f013188:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f01318c:	8d020000 */ 	lw	$v0,0x0($t0)
.L0f013190:
/*  f013190:	54400004 */ 	bnezl	$v0,.L0f0131a4
/*  f013194:	00022080 */ 	sll	$a0,$v0,0x2
/*  f013198:	1000002c */ 	beqz	$zero,.L0f01324c
/*  f01319c:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f0131a0:	00022080 */ 	sll	$a0,$v0,0x2
.L0f0131a4:
/*  f0131a4:	00822023 */ 	subu	$a0,$a0,$v0
/*  f0131a8:	00042080 */ 	sll	$a0,$a0,0x2
/*  f0131ac:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0131b0:	000420c0 */ 	sll	$a0,$a0,0x3
/*  f0131b4:	00822023 */ 	subu	$a0,$a0,$v0
/*  f0131b8:	00042080 */ 	sll	$a0,$a0,0x2
/*  f0131bc:	0c0048f2 */ 	jal	malloc
/*  f0131c0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0131c4:	3c08800a */ 	lui	$t0,%hi(var800a3444)
/*  f0131c8:	25083444 */ 	addiu	$t0,$t0,%lo(var800a3444)
/*  f0131cc:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f0131d0:	3c05800a */ 	lui	$a1,%hi(var800a3440)
/*  f0131d4:	24a53440 */ 	addiu	$a1,$a1,%lo(var800a3440)
/*  f0131d8:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f0131dc:	1920001b */ 	blez	$t1,.L0f01324c
/*  f0131e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0131e4:	44800000 */ 	mtc1	$zero,$f0
/*  f0131e8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0131ec:	24030190 */ 	addiu	$v1,$zero,0x190
/*  f0131f0:	8caa0000 */ 	lw	$t2,0x0($a1)
.L0f0131f4:
/*  f0131f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0131f8:	01465821 */ 	addu	$t3,$t2,$a2
/*  f0131fc:	ad600000 */ 	sw	$zero,0x0($t3)
.L0f013200:
/*  f013200:	00046880 */ 	sll	$t5,$a0,0x2
/*  f013204:	01a46823 */ 	subu	$t5,$t5,$a0
/*  f013208:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f01320c:	01a46821 */ 	addu	$t5,$t5,$a0
/*  f013210:	8cac0000 */ 	lw	$t4,0x0($a1)
/*  f013214:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f013218:	01a46823 */ 	subu	$t5,$t5,$a0
/*  f01321c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f013220:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f013224:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f013228:	24420028 */ 	addiu	$v0,$v0,0x28
/*  f01322c:	1443fff4 */ 	bne	$v0,$v1,.L0f013200
/*  f013230:	e5e00014 */ 	swc1	$f0,0x14($t7)
/*  f013234:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f013238:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f01323c:	24c6019c */ 	addiu	$a2,$a2,0x19c
/*  f013240:	0098082a */ 	slt	$at,$a0,$t8
/*  f013244:	5420ffeb */ 	bnezl	$at,.L0f0131f4
/*  f013248:	8caa0000 */ 	lw	$t2,0x0($a1)
.L0f01324c:
/*  f01324c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f013250:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f013254:	03e00008 */ 	jr	$ra
/*  f013258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01325c:	00000000 */ 	sll	$zero,$zero,0x0
);
