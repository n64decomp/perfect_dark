#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

GLOBAL_ASM(
glabel smokeInit
/*  f013130:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*  f013134:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*  f013138:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01313c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f013140:	15c10006 */ 	bne	$t6,$at,.L0f01315c
/*  f013144:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013148:	3c08800a */ 	lui	$t0,%hi(g_NumSmokes)
/*  f01314c:	25083444 */ 	addiu	$t0,$t0,%lo(g_NumSmokes)
/*  f013150:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f013154:	10000005 */ 	b	.L0f01316c
/*  f013158:	ad0f0000 */ 	sw	$t7,0x0($t0)
.L0f01315c:
/*  f01315c:	3c08800a */ 	lui	$t0,%hi(g_NumSmokes)
/*  f013160:	25083444 */ 	addiu	$t0,$t0,%lo(g_NumSmokes)
/*  f013164:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f013168:	ad180000 */ 	sw	$t8,0x0($t0)
.L0f01316c:
/*  f01316c:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x4b4)
/*  f013170:	8f39a474 */ 	lw	$t9,%lo(g_Vars+0x4b4)($t9)
/*  f013174:	3c05800a */ 	lui	$a1,%hi(g_Smokes)
/*  f013178:	24a53440 */ 	addiu	$a1,$a1,%lo(g_Smokes)
/*  f01317c:	2b21005a */ 	slti	$at,$t9,0x5a
/*  f013180:	54200003 */ 	bnezl	$at,.L0f013190
/*  f013184:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f013188:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f01318c:	8d020000 */ 	lw	$v0,0x0($t0)
.L0f013190:
/*  f013190:	54400004 */ 	bnezl	$v0,.L0f0131a4
/*  f013194:	00022080 */ 	sll	$a0,$v0,0x2
/*  f013198:	1000002c */ 	b	.L0f01324c
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
/*  f0131c4:	3c08800a */ 	lui	$t0,%hi(g_NumSmokes)
/*  f0131c8:	25083444 */ 	addiu	$t0,$t0,%lo(g_NumSmokes)
/*  f0131cc:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f0131d0:	3c05800a */ 	lui	$a1,%hi(g_Smokes)
/*  f0131d4:	24a53440 */ 	addiu	$a1,$a1,%lo(g_Smokes)
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
/*  f013258:	00000000 */ 	nop
/*  f01325c:	00000000 */ 	nop
);
