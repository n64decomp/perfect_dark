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
#include "game/room.h"
#include "game/pad.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
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
glabel coverAllocateSpecial
/*  f014250:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f014254:	3c06800a */ 	lui	$a2,%hi(g_NumSpecialCovers)
/*  f014258:	24c6236c */ 	addiu	$a2,$a2,%lo(g_NumSpecialCovers)
/*  f01425c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f014260:	94c40000 */ 	lhu	$a0,0x0($a2)
/*  f014264:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f014268:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f01426c:	00047040 */ 	sll	$t6,$a0,0x1
/*  f014270:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f014274:	348f000f */ 	ori	$t7,$a0,0xf
/*  f014278:	0c0048f2 */ 	jal	malloc
/*  f01427c:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f014280:	3c05800a */ 	lui	$a1,%hi(g_SpecialCoverNums)
/*  f014284:	24a52370 */ 	addiu	$a1,$a1,%lo(g_SpecialCoverNums)
/*  f014288:	3c06800a */ 	lui	$a2,%hi(g_NumSpecialCovers)
/*  f01428c:	24c6236c */ 	addiu	$a2,$a2,%lo(g_NumSpecialCovers)
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

void coverLoad(void)
{
	s32 i;
	s32 numcovers = g_PadsFile[1];
	s16 *roomsptr;
	f32 scale = 1;
	struct coord aimpos;
	struct cover cover;
	s16 specialcovernums[1024];
	s16 rooms1[21];
	s16 rooms2[21];

	g_CoverFlags = malloc(ALIGN16(numcovers * sizeof(u16)), MEMPOOL_STAGE);
	g_CoverRooms = malloc(ALIGN16(numcovers * sizeof(s32)), MEMPOOL_STAGE);
	var800a2368 = malloc(ALIGN16(numcovers * 0x10), MEMPOOL_STAGE);

	g_NumSpecialCovers = 0;
	g_SpecialCoverNums = NULL;

	if (g_CoverFlags && g_CoverRooms && var800a2368) {
		for (i = 0; i < numcovers; i++) {
			roomsptr = NULL;
			g_CoverFlags[i] = 0;

			if (coverUnpack(i, &cover)
					&& (cover.look->x != 0.0f || cover.look->y != 0.0f || cover.look->z != 0.0f)) {
				if (coverIsSpecial(&cover)) {
					specialcovernums[g_NumSpecialCovers] = i;
					g_NumSpecialCovers++;
				}

				cover.pos->x *= scale;
				cover.pos->y *= scale;
				cover.pos->z *= scale;

				if (cover.look->x == 1.0f && cover.look->y == 1.0f && cover.look->z == 1.0f) {
					g_CoverFlags[i] |= COVERFLAG_OMNIDIRECTIONAL;
				} else if (!coverIsSpecial(&cover)) {
					struct coord *look = cover.look;
					look->y = 0;
					guNormalize(&look->x, &look->y, &look->z);
				}

				// Find room
				func0f162194(cover.pos, rooms1, rooms2, 20, NULL);

				if (rooms1[0] != -1) {
					roomsptr = rooms1;
				} else if (rooms2[0] != -1) {
					roomsptr = rooms2;
				}

				g_CoverRooms[i] = -1;

				if (roomsptr != NULL) {
					s32 room = func0002a400(cover.pos, roomsptr);

					if (room > 0) {
						g_CoverRooms[i] = (s16)room;
					} else {
						g_CoverRooms[i] = roomsptr[0];
					}
				}

				// Determine if aim is in the same room or not
				if (g_CoverRooms[i] < 0) {
					g_CoverFlags[i] |= COVERFLAG_AIMSAMEROOM;
				} else if ((g_CoverFlags[i] & COVERFLAG_OMNIDIRECTIONAL) == 0) {
					aimpos.x = cover.pos->x + cover.look->f[0] * 600;
					aimpos.y = cover.pos->y;
					aimpos.z = cover.pos->z + cover.look->f[2] * 600;

					func0f162194(&aimpos, rooms1, rooms2, 20, NULL);

					if (rooms1[0] != -1) {
						roomsptr = rooms1;
					} else if (rooms2[0] != -1) {
						roomsptr = rooms2;
					}

					if (roomsptr) {
						s32 aimroom = func0002a400(&aimpos, roomsptr);

						if (aimroom > 0) {
							g_CoverFlags[i] |= (g_CoverRooms[i] == (s16)aimroom) ? COVERFLAG_AIMSAMEROOM : COVERFLAG_AIMDIFFROOM;
						} else {
							g_CoverFlags[i] |= (g_CoverRooms[i] == roomsptr[0]) ? COVERFLAG_AIMSAMEROOM : COVERFLAG_AIMDIFFROOM;
						}
					} else {
						g_CoverFlags[i] |= COVERFLAG_AIMDIFFROOM;
					}
				}
			}
		}

		coverAllocateSpecial(specialcovernums);
	}
}
