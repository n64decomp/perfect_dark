#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_013ee0.h"
#include "game/game_157db0.h"
#include "game/pad.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_121e0.h"
#include "lib/lib_233c0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f013ee0
/*  f013ee0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f013ee4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f013ee8:	8d0e006c */ 	lw	$t6,0x6c($t0)
/*  f013eec:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f013ef0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013ef4:	51c00004 */ 	beqzl	$t6,.L0f013f08
/*  f013ef8:	00004825 */ 	or	$t1,$zero,$zero
/*  f013efc:	10000002 */ 	b	.L0f013f08
/*  f013f00:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f013f04:	00004825 */ 	or	$t1,$zero,$zero
.L0f013f08:
/*  f013f08:	8d0f0068 */ 	lw	$t7,0x68($t0)
/*  f013f0c:	51e00004 */ 	beqzl	$t7,.L0f013f20
/*  f013f10:	00003825 */ 	or	$a3,$zero,$zero
/*  f013f14:	10000002 */ 	b	.L0f013f20
/*  f013f18:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f013f1c:	00003825 */ 	or	$a3,$zero,$zero
.L0f013f20:
/*  f013f20:	8d180064 */ 	lw	$t8,0x64($t0)
/*  f013f24:	53000004 */ 	beqzl	$t8,.L0f013f38
/*  f013f28:	00002825 */ 	or	$a1,$zero,$zero
/*  f013f2c:	10000002 */ 	b	.L0f013f38
/*  f013f30:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f013f34:	00002825 */ 	or	$a1,$zero,$zero
.L0f013f38:
/*  f013f38:	8d190070 */ 	lw	$t9,0x70($t0)
/*  f013f3c:	53200004 */ 	beqzl	$t9,.L0f013f50
/*  f013f40:	00001025 */ 	or	$v0,$zero,$zero
/*  f013f44:	10000002 */ 	b	.L0f013f50
/*  f013f48:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f013f4c:	00001025 */ 	or	$v0,$zero,$zero
.L0f013f50:
/*  f013f50:	00457021 */ 	addu	$t6,$v0,$a1
/*  f013f54:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f013f58:	01e9c021 */ 	addu	$t8,$t7,$t1
/*  f013f5c:	2b010002 */ 	slti	$at,$t8,0x2
/*  f013f60:	14200005 */ 	bnez	$at,.L0f013f78
/*  f013f64:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f013f68:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f013f6c:	241900c8 */ 	addiu	$t9,$zero,0xc8
/*  f013f70:	10000005 */ 	b	.L0f013f88
/*  f013f74:	ad590000 */ 	sw	$t9,0x0($t2)
.L0f013f78:
/*  f013f78:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f013f7c:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f013f80:	240e0078 */ 	addiu	$t6,$zero,0x78
/*  f013f84:	ad4e0000 */ 	sw	$t6,0x0($t2)
.L0f013f88:
/*  f013f88:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f013f8c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f013f90:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f013f94:	348f000f */ 	ori	$t7,$a0,0xf
/*  f013f98:	0c0048f2 */ 	jal	malloc
/*  f013f9c:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f013fa0:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f013fa4:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f013fa8:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f013fac:	3c0d800a */ 	lui	$t5,%hi(var800a6660)
/*  f013fb0:	25ad6660 */ 	addiu	$t5,$t5,%lo(var800a6660)
/*  f013fb4:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f013fb8:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f013fbc:	348e000f */ 	ori	$t6,$a0,0xf
/*  f013fc0:	ada20000 */ 	sw	$v0,0x0($t5)
/*  f013fc4:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f013fc8:	0c0048f2 */ 	jal	malloc
/*  f013fcc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f013fd0:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f013fd4:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f013fd8:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f013fdc:	3c1f800a */ 	lui	$ra,%hi(var800a6664)
/*  f013fe0:	27ff6664 */ 	addiu	$ra,$ra,%lo(var800a6664)
/*  f013fe4:	0004c040 */ 	sll	$t8,$a0,0x1
/*  f013fe8:	2704000f */ 	addiu	$a0,$t8,0xf
/*  f013fec:	afe20000 */ 	sw	$v0,0x0($ra)
/*  f013ff0:	3499000f */ 	ori	$t9,$a0,0xf
/*  f013ff4:	3b24000f */ 	xori	$a0,$t9,0xf
/*  f013ff8:	0c0048f2 */ 	jal	malloc
/*  f013ffc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014000:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f014004:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f014008:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f01400c:	3c0b800a */ 	lui	$t3,%hi(var800a6668)
/*  f014010:	256b6668 */ 	addiu	$t3,$t3,%lo(var800a6668)
/*  f014014:	00047880 */ 	sll	$t7,$a0,0x2
/*  f014018:	25e4000f */ 	addiu	$a0,$t7,0xf
/*  f01401c:	3498000f */ 	ori	$t8,$a0,0xf
/*  f014020:	ad620000 */ 	sw	$v0,0x0($t3)
/*  f014024:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f014028:	0c0048f2 */ 	jal	malloc
/*  f01402c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014030:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f014034:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f014038:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f01403c:	3c0c800a */ 	lui	$t4,%hi(var800a666c)
/*  f014040:	258c666c */ 	addiu	$t4,$t4,%lo(var800a666c)
/*  f014044:	00047180 */ 	sll	$t6,$a0,0x6
/*  f014048:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f01404c:	348f000f */ 	ori	$t7,$a0,0xf
/*  f014050:	ad820000 */ 	sw	$v0,0x0($t4)
/*  f014054:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f014058:	0c0048f2 */ 	jal	malloc
/*  f01405c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014060:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f014064:	3c01800a */ 	lui	$at,%hi(var800a6670)
/*  f014068:	ac226670 */ 	sw	$v0,%lo(var800a6670)($at)
/*  f01406c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f014070:	8d19006c */ 	lw	$t9,0x6c($t0)
/*  f014074:	3c0a8008 */ 	lui	$t2,%hi(var80082050)
/*  f014078:	3c0b800a */ 	lui	$t3,%hi(var800a6668)
/*  f01407c:	3c0c800a */ 	lui	$t4,%hi(var800a666c)
/*  f014080:	3c0d800a */ 	lui	$t5,%hi(var800a6660)
/*  f014084:	3c1f800a */ 	lui	$ra,%hi(var800a6664)
/*  f014088:	27ff6664 */ 	addiu	$ra,$ra,%lo(var800a6664)
/*  f01408c:	25ad6660 */ 	addiu	$t5,$t5,%lo(var800a6660)
/*  f014090:	258c666c */ 	addiu	$t4,$t4,%lo(var800a666c)
/*  f014094:	256b6668 */ 	addiu	$t3,$t3,%lo(var800a6668)
/*  f014098:	254a2050 */ 	addiu	$t2,$t2,%lo(var80082050)
/*  f01409c:	13200003 */ 	beqz	$t9,.L0f0140ac
/*  f0140a0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0140a4:	10000002 */ 	b	.L0f0140b0
/*  f0140a8:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0140ac:
/*  f0140ac:	00004825 */ 	or	$t1,$zero,$zero
.L0f0140b0:
/*  f0140b0:	8d0e0068 */ 	lw	$t6,0x68($t0)
/*  f0140b4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0140b8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0140bc:	11c00003 */ 	beqz	$t6,.L0f0140cc
/*  f0140c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0140c4:	10000001 */ 	b	.L0f0140cc
/*  f0140c8:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0140cc:
/*  f0140cc:	8d0f0064 */ 	lw	$t7,0x64($t0)
/*  f0140d0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0140d4:	11e00003 */ 	beqz	$t7,.L0f0140e4
/*  f0140d8:	00000000 */ 	nop
/*  f0140dc:	10000001 */ 	b	.L0f0140e4
/*  f0140e0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0140e4:
/*  f0140e4:	8d180070 */ 	lw	$t8,0x70($t0)
/*  f0140e8:	13000003 */ 	beqz	$t8,.L0f0140f8
/*  f0140ec:	00000000 */ 	nop
/*  f0140f0:	10000001 */ 	b	.L0f0140f8
/*  f0140f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0140f8:
/*  f0140f8:	0045c821 */ 	addu	$t9,$v0,$a1
/*  f0140fc:	03277021 */ 	addu	$t6,$t9,$a3
/*  f014100:	01c97821 */ 	addu	$t7,$t6,$t1
/*  f014104:	19e00024 */ 	blez	$t7,.L0f014198
/*  f014108:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f01410c:	01181821 */ 	addu	$v1,$t0,$t8
/*  f014110:	8c790064 */ 	lw	$t9,0x64($v1)
.L0f014114:
/*  f014114:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f014118:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f01411c:	af261700 */ 	sw	$a2,0x1700($t9)
/*  f014120:	8d0e006c */ 	lw	$t6,0x6c($t0)
/*  f014124:	00004825 */ 	or	$t1,$zero,$zero
/*  f014128:	00003825 */ 	or	$a3,$zero,$zero
/*  f01412c:	11c00003 */ 	beqz	$t6,.L0f01413c
/*  f014130:	00002825 */ 	or	$a1,$zero,$zero
/*  f014134:	10000001 */ 	b	.L0f01413c
/*  f014138:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f01413c:
/*  f01413c:	8d0f0068 */ 	lw	$t7,0x68($t0)
/*  f014140:	00001025 */ 	or	$v0,$zero,$zero
/*  f014144:	11e00003 */ 	beqz	$t7,.L0f014154
/*  f014148:	00000000 */ 	nop
/*  f01414c:	10000001 */ 	b	.L0f014154
/*  f014150:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f014154:
/*  f014154:	8d180064 */ 	lw	$t8,0x64($t0)
/*  f014158:	13000003 */ 	beqz	$t8,.L0f014168
/*  f01415c:	00000000 */ 	nop
/*  f014160:	10000001 */ 	b	.L0f014168
/*  f014164:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f014168:
/*  f014168:	8d190070 */ 	lw	$t9,0x70($t0)
/*  f01416c:	13200003 */ 	beqz	$t9,.L0f01417c
/*  f014170:	00000000 */ 	nop
/*  f014174:	10000001 */ 	b	.L0f01417c
/*  f014178:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f01417c:
/*  f01417c:	00457021 */ 	addu	$t6,$v0,$a1
/*  f014180:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f014184:	01e9c021 */ 	addu	$t8,$t7,$t1
/*  f014188:	0098082a */ 	slt	$at,$a0,$t8
/*  f01418c:	5420ffe1 */ 	bnezl	$at,.L0f014114
/*  f014190:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f014194:	00002025 */ 	or	$a0,$zero,$zero
.L0f014198:
/*  f014198:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f01419c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0141a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0141a4:	1b200018 */ 	blez	$t9,.L0f014208
/*  f0141a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0141ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0141b0:	44810000 */ 	mtc1	$at,$f0
/*  f0141b4:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0141b8:	8fee0000 */ 	lw	$t6,0x0($ra)
.L0f0141bc:
/*  f0141bc:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f0141c0:	a5e60000 */ 	sh	$a2,0x0($t7)
/*  f0141c4:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f0141c8:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0141cc:	a3250000 */ 	sb	$a1,0x0($t9)
/*  f0141d0:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f0141d4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0141d8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f0141dc:	a5e60000 */ 	sh	$a2,0x0($t7)
/*  f0141e0:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0141e4:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0141e8:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f0141ec:	e7200000 */ 	swc1	$f0,0x0($t9)
/*  f0141f0:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f0141f4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0141f8:	008e082a */ 	slt	$at,$a0,$t6
/*  f0141fc:	5420ffef */ 	bnezl	$at,.L0f0141bc
/*  f014200:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f014204:	00002025 */ 	or	$a0,$zero,$zero
.L0f014208:
/*  f014208:	8d0f02bc */ 	lw	$t7,0x2bc($t0)
/*  f01420c:	3c03800a */ 	lui	$v1,%hi(g_Rooms)
/*  f014210:	24634928 */ 	addiu	$v1,$v1,%lo(g_Rooms)
/*  f014214:	19e0000a */ 	blez	$t7,.L0f014240
/*  f014218:	00001025 */ 	or	$v0,$zero,$zero
/*  f01421c:	8c780000 */ 	lw	$t8,0x0($v1)
.L0f014220:
/*  f014220:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f014224:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f014228:	a7260010 */ 	sh	$a2,0x10($t9)
/*  f01422c:	8d0e02bc */ 	lw	$t6,0x2bc($t0)
/*  f014230:	2442008c */ 	addiu	$v0,$v0,0x8c
/*  f014234:	008e082a */ 	slt	$at,$a0,$t6
/*  f014238:	5420fff9 */ 	bnezl	$at,.L0f014220
/*  f01423c:	8c780000 */ 	lw	$t8,0x0($v1)
.L0f014240:
/*  f014240:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f014244:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f014248:	03e00008 */ 	jr	$ra
/*  f01424c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f014250
/*  f014250:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f014254:	3c06800a */ 	lui	$a2,%hi(var800a236c)
/*  f014258:	24c6236c */ 	addiu	$a2,$a2,%lo(var800a236c)
/*  f01425c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f014260:	94c40000 */ 	lhu	$a0,0x0($a2)
/*  f014264:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f014268:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f01426c:	00047040 */ 	sll	$t6,$a0,0x1
/*  f014270:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f014274:	348f000f */ 	ori	$t7,$a0,0xf
/*  f014278:	0c0048f2 */ 	jal	malloc
/*  f01427c:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f014280:	3c05800a */ 	lui	$a1,%hi(g_CoverNums)
/*  f014284:	24a52370 */ 	addiu	$a1,$a1,%lo(g_CoverNums)
/*  f014288:	3c06800a */ 	lui	$a2,%hi(var800a236c)
/*  f01428c:	24c6236c */ 	addiu	$a2,$a2,%lo(var800a236c)
/*  f014290:	10400011 */ 	beqz	$v0,.L0f0142d8
/*  f014294:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f014298:	94c80000 */ 	lhu	$t0,0x0($a2)
/*  f01429c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0142a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0142a4:	1900000c */ 	blez	$t0,.L0f0142d8
/*  f0142a8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0142ac:	8caa0000 */ 	lw	$t2,0x0($a1)
.L0f0142b0:
/*  f0142b0:	94890000 */ 	lhu	$t1,0x0($a0)
/*  f0142b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0142b8:	01435821 */ 	addu	$t3,$t2,$v1
/*  f0142bc:	a5690000 */ 	sh	$t1,0x0($t3)
/*  f0142c0:	94cc0000 */ 	lhu	$t4,0x0($a2)
/*  f0142c4:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0142c8:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f0142cc:	004c082a */ 	slt	$at,$v0,$t4
/*  f0142d0:	5420fff7 */ 	bnezl	$at,.L0f0142b0
/*  f0142d4:	8caa0000 */ 	lw	$t2,0x0($a1)
.L0f0142d8:
/*  f0142d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0142dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0142e0:	03e00008 */ 	jr	$ra
/*  f0142e4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0142e8
/*  f0142e8:	27bdf6f8 */ 	addiu	$sp,$sp,-2312
/*  f0142ec:	3c0e800a */ 	lui	$t6,%hi(g_PadsFile)
/*  f0142f0:	8dce2350 */ 	lw	$t6,%lo(g_PadsFile)($t6)
/*  f0142f4:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0142f8:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f0142fc:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f014300:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f014304:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f014308:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f01430c:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f014310:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f014314:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f014318:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f01431c:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f014320:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f014324:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f014328:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f01432c:	8dc20004 */ 	lw	$v0,0x4($t6)
/*  f014330:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014334:	00022040 */ 	sll	$a0,$v0,0x1
/*  f014338:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f01433c:	348f000f */ 	ori	$t7,$a0,0xf
/*  f014340:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f014344:	0c0048f2 */ 	jal	malloc
/*  f014348:	afa20900 */ 	sw	$v0,0x900($sp)
/*  f01434c:	8fa40900 */ 	lw	$a0,0x900($sp)
/*  f014350:	3c13800a */ 	lui	$s3,%hi(g_CoverFlags)
/*  f014354:	26732360 */ 	addiu	$s3,$s3,%lo(g_CoverFlags)
/*  f014358:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f01435c:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f014360:	3488000f */ 	ori	$t0,$a0,0xf
/*  f014364:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f014368:	3904000f */ 	xori	$a0,$t0,0xf
/*  f01436c:	0c0048f2 */ 	jal	malloc
/*  f014370:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014374:	8fa40900 */ 	lw	$a0,0x900($sp)
/*  f014378:	3c15800a */ 	lui	$s5,%hi(g_CoverRooms)
/*  f01437c:	26b52364 */ 	addiu	$s5,$s5,%lo(g_CoverRooms)
/*  f014380:	00045100 */ 	sll	$t2,$a0,0x4
/*  f014384:	2544000f */ 	addiu	$a0,$t2,0xf
/*  f014388:	348b000f */ 	ori	$t3,$a0,0xf
/*  f01438c:	aea20000 */ 	sw	$v0,0x0($s5)
/*  f014390:	3964000f */ 	xori	$a0,$t3,0xf
/*  f014394:	0c0048f2 */ 	jal	malloc
/*  f014398:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f01439c:	3c03800a */ 	lui	$v1,%hi(var800a2368)
/*  f0143a0:	24632368 */ 	addiu	$v1,$v1,%lo(var800a2368)
/*  f0143a4:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f0143a8:	3c01800a */ 	lui	$at,%hi(var800a236c)
/*  f0143ac:	a420236c */ 	sh	$zero,%lo(var800a236c)($at)
/*  f0143b0:	3c01800a */ 	lui	$at,%hi(g_CoverNums)
/*  f0143b4:	ac202370 */ 	sw	$zero,%lo(g_CoverNums)($at)
/*  f0143b8:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0143bc:	51a000e6 */ 	beqzl	$t5,.L0f014758
/*  f0143c0:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0143c4:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f0143c8:	51c000e3 */ 	beqzl	$t6,.L0f014758
/*  f0143cc:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0143d0:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0143d4:	8fb80900 */ 	lw	$t8,0x900($sp)
/*  f0143d8:	51e000df */ 	beqzl	$t7,.L0f014758
/*  f0143dc:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0143e0:	1b0000da */ 	blez	$t8,.L0f01474c
/*  f0143e4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0143e8:	3c014416 */ 	lui	$at,0x4416
/*  f0143ec:	4481d000 */ 	mtc1	$at,$f26
/*  f0143f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0143f4:	4481c000 */ 	mtc1	$at,$f24
/*  f0143f8:	4481b000 */ 	mtc1	$at,$f22
/*  f0143fc:	4480a000 */ 	mtc1	$zero,$f20
/*  f014400:	00009025 */ 	or	$s2,$zero,$zero
/*  f014404:	27be0084 */ 	addiu	$s8,$sp,0x84
/*  f014408:	27b700b0 */ 	addiu	$s7,$sp,0xb0
/*  f01440c:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f014410:	8e790000 */ 	lw	$t9,0x0($s3)
.L0f014414:
/*  f014414:	00008025 */ 	or	$s0,$zero,$zero
/*  f014418:	02802025 */ 	or	$a0,$s4,$zero
/*  f01441c:	03324021 */ 	addu	$t0,$t9,$s2
/*  f014420:	a5000000 */ 	sh	$zero,0x0($t0)
/*  f014424:	0fc458b8 */ 	jal	coverLoad
/*  f014428:	27a508dc */ 	addiu	$a1,$sp,0x8dc
/*  f01442c:	104000c2 */ 	beqz	$v0,.L0f014738
/*  f014430:	8fa908e0 */ 	lw	$t1,0x8e0($sp)
/*  f014434:	c5240000 */ 	lwc1	$f4,0x0($t1)
/*  f014438:	27a408dc */ 	addiu	$a0,$sp,0x8dc
/*  f01443c:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f014440:	00000000 */ 	nop
/*  f014444:	4500000b */ 	bc1f	.L0f014474
/*  f014448:	00000000 */ 	nop
/*  f01444c:	c5260004 */ 	lwc1	$f6,0x4($t1)
/*  f014450:	4606a032 */ 	c.eq.s	$f20,$f6
/*  f014454:	00000000 */ 	nop
/*  f014458:	45000006 */ 	bc1f	.L0f014474
/*  f01445c:	00000000 */ 	nop
/*  f014460:	c5280008 */ 	lwc1	$f8,0x8($t1)
/*  f014464:	4608a032 */ 	c.eq.s	$f20,$f8
/*  f014468:	00000000 */ 	nop
/*  f01446c:	450300b3 */ 	bc1tl	.L0f01473c
/*  f014470:	8fae0900 */ 	lw	$t6,0x900($sp)
.L0f014474:
/*  f014474:	0fc4596c */ 	jal	coverHasSomeFlags
/*  f014478:	00148880 */ 	sll	$s1,$s4,0x2
/*  f01447c:	10400008 */ 	beqz	$v0,.L0f0144a0
/*  f014480:	3c02800a */ 	lui	$v0,%hi(var800a236c)
/*  f014484:	9442236c */ 	lhu	$v0,%lo(var800a236c)($v0)
/*  f014488:	3c01800a */ 	lui	$at,%hi(var800a236c)
/*  f01448c:	00025040 */ 	sll	$t2,$v0,0x1
/*  f014490:	03aa5821 */ 	addu	$t3,$sp,$t2
/*  f014494:	a57400dc */ 	sh	$s4,0xdc($t3)
/*  f014498:	244c0001 */ 	addiu	$t4,$v0,0x1
/*  f01449c:	a42c236c */ 	sh	$t4,%lo(var800a236c)($at)
.L0f0144a0:
/*  f0144a0:	8fad08dc */ 	lw	$t5,0x8dc($sp)
/*  f0144a4:	c5aa0000 */ 	lwc1	$f10,0x0($t5)
/*  f0144a8:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f0144ac:	e5b00000 */ 	swc1	$f16,0x0($t5)
/*  f0144b0:	8fae08dc */ 	lw	$t6,0x8dc($sp)
/*  f0144b4:	c5d20004 */ 	lwc1	$f18,0x4($t6)
/*  f0144b8:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f0144bc:	e5c40004 */ 	swc1	$f4,0x4($t6)
/*  f0144c0:	8faf08dc */ 	lw	$t7,0x8dc($sp)
/*  f0144c4:	c5e60008 */ 	lwc1	$f6,0x8($t7)
/*  f0144c8:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f0144cc:	e5e80008 */ 	swc1	$f8,0x8($t7)
/*  f0144d0:	8fb808e0 */ 	lw	$t8,0x8e0($sp)
/*  f0144d4:	c70a0000 */ 	lwc1	$f10,0x0($t8)
/*  f0144d8:	460ac032 */ 	c.eq.s	$f24,$f10
/*  f0144dc:	00000000 */ 	nop
/*  f0144e0:	45000011 */ 	bc1f	.L0f014528
/*  f0144e4:	00000000 */ 	nop
/*  f0144e8:	c7100004 */ 	lwc1	$f16,0x4($t8)
/*  f0144ec:	4610c032 */ 	c.eq.s	$f24,$f16
/*  f0144f0:	00000000 */ 	nop
/*  f0144f4:	4500000c */ 	bc1f	.L0f014528
/*  f0144f8:	00000000 */ 	nop
/*  f0144fc:	c7120008 */ 	lwc1	$f18,0x8($t8)
/*  f014500:	4612c032 */ 	c.eq.s	$f24,$f18
/*  f014504:	00000000 */ 	nop
/*  f014508:	45000007 */ 	bc1f	.L0f014528
/*  f01450c:	00000000 */ 	nop
/*  f014510:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f014514:	03321021 */ 	addu	$v0,$t9,$s2
/*  f014518:	94480000 */ 	lhu	$t0,0x0($v0)
/*  f01451c:	35090010 */ 	ori	$t1,$t0,0x10
/*  f014520:	1000000a */ 	b	.L0f01454c
/*  f014524:	a4490000 */ 	sh	$t1,0x0($v0)
.L0f014528:
/*  f014528:	0fc4596c */ 	jal	coverHasSomeFlags
/*  f01452c:	27a408dc */ 	addiu	$a0,$sp,0x8dc
/*  f014530:	14400006 */ 	bnez	$v0,.L0f01454c
/*  f014534:	8fa408e0 */ 	lw	$a0,0x8e0($sp)
/*  f014538:	44802000 */ 	mtc1	$zero,$f4
/*  f01453c:	24850004 */ 	addiu	$a1,$a0,0x4
/*  f014540:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f014544:	0c0011e4 */ 	jal	scaleTo1
/*  f014548:	e4840004 */ 	swc1	$f4,0x4($a0)
.L0f01454c:
/*  f01454c:	8fa408dc */ 	lw	$a0,0x8dc($sp)
/*  f014550:	02e02825 */ 	or	$a1,$s7,$zero
/*  f014554:	03c03025 */ 	or	$a2,$s8,$zero
/*  f014558:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f01455c:	0fc58865 */ 	jal	func0f162194
/*  f014560:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f014564:	87ab00b0 */ 	lh	$t3,0xb0($sp)
/*  f014568:	87ac0084 */ 	lh	$t4,0x84($sp)
/*  f01456c:	12cb0003 */ 	beq	$s6,$t3,.L0f01457c
/*  f014570:	00000000 */ 	nop
/*  f014574:	10000004 */ 	b	.L0f014588
/*  f014578:	02e08025 */ 	or	$s0,$s7,$zero
.L0f01457c:
/*  f01457c:	52cc0003 */ 	beql	$s6,$t4,.L0f01458c
/*  f014580:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f014584:	03c08025 */ 	or	$s0,$s8,$zero
.L0f014588:
/*  f014588:	8ead0000 */ 	lw	$t5,0x0($s5)
.L0f01458c:
/*  f01458c:	02002825 */ 	or	$a1,$s0,$zero
/*  f014590:	01b17021 */ 	addu	$t6,$t5,$s1
/*  f014594:	1200000f */ 	beqz	$s0,.L0f0145d4
/*  f014598:	add60000 */ 	sw	$s6,0x0($t6)
/*  f01459c:	0c00a900 */ 	jal	func0002a400
/*  f0145a0:	8fa408dc */ 	lw	$a0,0x8dc($sp)
/*  f0145a4:	58400008 */ 	blezl	$v0,.L0f0145c8
/*  f0145a8:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f0145ac:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f0145b0:	00027c00 */ 	sll	$t7,$v0,0x10
/*  f0145b4:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f0145b8:	03314021 */ 	addu	$t0,$t9,$s1
/*  f0145bc:	10000005 */ 	b	.L0f0145d4
/*  f0145c0:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f0145c4:	8eaa0000 */ 	lw	$t2,0x0($s5)
.L0f0145c8:
/*  f0145c8:	86090000 */ 	lh	$t1,0x0($s0)
/*  f0145cc:	01515821 */ 	addu	$t3,$t2,$s1
/*  f0145d0:	ad690000 */ 	sw	$t1,0x0($t3)
.L0f0145d4:
/*  f0145d4:	8eac0000 */ 	lw	$t4,0x0($s5)
/*  f0145d8:	01916821 */ 	addu	$t5,$t4,$s1
/*  f0145dc:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f0145e0:	05c30008 */ 	bgezl	$t6,.L0f014604
/*  f0145e4:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f0145e8:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f0145ec:	01f21021 */ 	addu	$v0,$t7,$s2
/*  f0145f0:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f0145f4:	37380004 */ 	ori	$t8,$t9,0x4
/*  f0145f8:	1000004f */ 	b	.L0f014738
/*  f0145fc:	a4580000 */ 	sh	$t8,0x0($v0)
/*  f014600:	8e680000 */ 	lw	$t0,0x0($s3)
.L0f014604:
/*  f014604:	8fac08e0 */ 	lw	$t4,0x8e0($sp)
/*  f014608:	01125021 */ 	addu	$t2,$t0,$s2
/*  f01460c:	95490000 */ 	lhu	$t1,0x0($t2)
/*  f014610:	312b0010 */ 	andi	$t3,$t1,0x10
/*  f014614:	55600049 */ 	bnezl	$t3,.L0f01473c
/*  f014618:	8fae0900 */ 	lw	$t6,0x900($sp)
/*  f01461c:	c5860000 */ 	lwc1	$f6,0x0($t4)
/*  f014620:	8fad08dc */ 	lw	$t5,0x8dc($sp)
/*  f014624:	27a408ec */ 	addiu	$a0,$sp,0x8ec
/*  f014628:	461a3202 */ 	mul.s	$f8,$f6,$f26
/*  f01462c:	c5aa0000 */ 	lwc1	$f10,0x0($t5)
/*  f014630:	02e02825 */ 	or	$a1,$s7,$zero
/*  f014634:	03c03025 */ 	or	$a2,$s8,$zero
/*  f014638:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f01463c:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f014640:	e7b008ec */ 	swc1	$f16,0x8ec($sp)
/*  f014644:	c5b20004 */ 	lwc1	$f18,0x4($t5)
/*  f014648:	e7b208f0 */ 	swc1	$f18,0x8f0($sp)
/*  f01464c:	c5840008 */ 	lwc1	$f4,0x8($t4)
/*  f014650:	c5a80008 */ 	lwc1	$f8,0x8($t5)
/*  f014654:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f014658:	461a2182 */ 	mul.s	$f6,$f4,$f26
/*  f01465c:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f014660:	0fc58865 */ 	jal	func0f162194
/*  f014664:	e7aa08f4 */ 	swc1	$f10,0x8f4($sp)
/*  f014668:	87ae00b0 */ 	lh	$t6,0xb0($sp)
/*  f01466c:	87af0084 */ 	lh	$t7,0x84($sp)
/*  f014670:	27a408ec */ 	addiu	$a0,$sp,0x8ec
/*  f014674:	12ce0003 */ 	beq	$s6,$t6,.L0f014684
/*  f014678:	00000000 */ 	nop
/*  f01467c:	10000004 */ 	b	.L0f014690
/*  f014680:	02e08025 */ 	or	$s0,$s7,$zero
.L0f014684:
/*  f014684:	12cf0002 */ 	beq	$s6,$t7,.L0f014690
/*  f014688:	00000000 */ 	nop
/*  f01468c:	03c08025 */ 	or	$s0,$s8,$zero
.L0f014690:
/*  f014690:	52000025 */ 	beqzl	$s0,.L0f014728
/*  f014694:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f014698:	0c00a900 */ 	jal	func0002a400
/*  f01469c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0146a0:	58400012 */ 	blezl	$v0,.L0f0146ec
/*  f0146a4:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f0146a8:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f0146ac:	0002cc00 */ 	sll	$t9,$v0,0x10
/*  f0146b0:	0019c403 */ 	sra	$t8,$t9,0x10
/*  f0146b4:	01115021 */ 	addu	$t2,$t0,$s1
/*  f0146b8:	8d490000 */ 	lw	$t1,0x0($t2)
/*  f0146bc:	24030008 */ 	addiu	$v1,$zero,0x8
/*  f0146c0:	17090003 */ 	bne	$t8,$t1,.L0f0146d0
/*  f0146c4:	00000000 */ 	nop
/*  f0146c8:	10000001 */ 	b	.L0f0146d0
/*  f0146cc:	24030004 */ 	addiu	$v1,$zero,0x4
.L0f0146d0:
/*  f0146d0:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f0146d4:	01721021 */ 	addu	$v0,$t3,$s2
/*  f0146d8:	944c0000 */ 	lhu	$t4,0x0($v0)
/*  f0146dc:	01836825 */ 	or	$t5,$t4,$v1
/*  f0146e0:	10000015 */ 	b	.L0f014738
/*  f0146e4:	a44d0000 */ 	sh	$t5,0x0($v0)
/*  f0146e8:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f0146ec:
/*  f0146ec:	86080000 */ 	lh	$t0,0x0($s0)
/*  f0146f0:	24030008 */ 	addiu	$v1,$zero,0x8
/*  f0146f4:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f0146f8:	8df90000 */ 	lw	$t9,0x0($t7)
/*  f0146fc:	17280003 */ 	bne	$t9,$t0,.L0f01470c
/*  f014700:	00000000 */ 	nop
/*  f014704:	10000001 */ 	b	.L0f01470c
/*  f014708:	24030004 */ 	addiu	$v1,$zero,0x4
.L0f01470c:
/*  f01470c:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f014710:	01521021 */ 	addu	$v0,$t2,$s2
/*  f014714:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f014718:	03034825 */ 	or	$t1,$t8,$v1
/*  f01471c:	10000006 */ 	b	.L0f014738
/*  f014720:	a4490000 */ 	sh	$t1,0x0($v0)
/*  f014724:	8e6b0000 */ 	lw	$t3,0x0($s3)
.L0f014728:
/*  f014728:	01721021 */ 	addu	$v0,$t3,$s2
/*  f01472c:	944c0000 */ 	lhu	$t4,0x0($v0)
/*  f014730:	358d0008 */ 	ori	$t5,$t4,0x8
/*  f014734:	a44d0000 */ 	sh	$t5,0x0($v0)
.L0f014738:
/*  f014738:	8fae0900 */ 	lw	$t6,0x900($sp)
.L0f01473c:
/*  f01473c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f014740:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f014744:	568eff33 */ 	bnel	$s4,$t6,.L0f014414
/*  f014748:	8e790000 */ 	lw	$t9,0x0($s3)
.L0f01474c:
/*  f01474c:	0fc05094 */ 	jal	func0f014250
/*  f014750:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f014754:	8fbf0064 */ 	lw	$ra,0x64($sp)
.L0f014758:
/*  f014758:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f01475c:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f014760:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f014764:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f014768:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f01476c:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f014770:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f014774:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f014778:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f01477c:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f014780:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f014784:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f014788:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f01478c:	03e00008 */ 	jr	$ra
/*  f014790:	27bd0908 */ 	addiu	$sp,$sp,0x908
/*  f014794:	00000000 */ 	nop
/*  f014798:	00000000 */ 	nop
/*  f01479c:	00000000 */ 	nop
);
