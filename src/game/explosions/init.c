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
glabel explosionsInit
/*  f013010:	3c018008 */ 	lui	$at,%hi(var8007e4a0)
/*  f013014:	ac20e4a0 */ 	sw	$zero,%lo(var8007e4a0)($at)
/*  f013018:	3c018008 */ 	lui	$at,%hi(var8007e4a4)
/*  f01301c:	ac20e4a4 */ 	sw	$zero,%lo(var8007e4a4)($at)
/*  f013020:	3c013f80 */ 	lui	$at,0x3f80
/*  f013024:	44812000 */ 	mtc1	$at,$f4
/*  f013028:	3c08800a */ 	lui	$t0,%hi(g_NumExplosions)
/*  f01302c:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f013030:	25083434 */ 	addiu	$t0,$t0,%lo(g_NumExplosions)
/*  f013034:	240e0006 */ 	addiu	$t6,$zero,0x6
/*  f013038:	e424e4a8 */ 	swc1	$f4,%lo(var8007e4a8)($at)
/*  f01303c:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f013040:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x4b4)
/*  f013044:	8defa474 */ 	lw	$t7,%lo(g_Vars+0x4b4)($t7)
/*  f013048:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01304c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013050:	29e1005a */ 	slti	$at,$t7,0x5a
/*  f013054:	14200002 */ 	bnez	$at,.L0f013060
/*  f013058:	3c05800a */ 	lui	$a1,%hi(g_Explosions)
/*  f01305c:	ad000000 */ 	sw	$zero,0x0($t0)
.L0f013060:
/*  f013060:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f013064:	24a53430 */ 	addiu	$a1,$a1,%lo(g_Explosions)
/*  f013068:	54400004 */ 	bnezl	$v0,.L0f01307c
/*  f01306c:	000220c0 */ 	sll	$a0,$v0,0x3
/*  f013070:	1000002b */ 	b	.L0f013120
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
/*  f0130a4:	3c08800a */ 	lui	$t0,%hi(g_NumExplosions)
/*  f0130a8:	25083434 */ 	addiu	$t0,$t0,%lo(g_NumExplosions)
/*  f0130ac:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0130b0:	3c05800a */ 	lui	$a1,%hi(g_Explosions)
/*  f0130b4:	24a53430 */ 	addiu	$a1,$a1,%lo(g_Explosions)
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
/*  f01312c:	00000000 */ 	nop
);
