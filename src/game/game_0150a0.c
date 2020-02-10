#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_0e9d0.h"
#include "library/library_317f0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f0150a0
/*  f0150a0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0150a4:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f0150a8:	3c178009 */ 	lui	$s7,%hi(g_Is4Mb)
/*  f0150ac:	26f70af0 */ 	addiu	$s7,$s7,%lo(g_Is4Mb)
/*  f0150b0:	92ee0000 */ 	lbu	$t6,0x0($s7)
/*  f0150b4:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f0150b8:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f0150bc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0150c0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0150c4:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0150c8:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0150cc:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0150d0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0150d4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0150d8:	16ce0003 */ 	bne	$s6,$t6,.L0f0150e8
/*  f0150dc:	00009825 */ 	or	$s3,$zero,$zero
/*  f0150e0:	10000002 */ 	beqz	$zero,.L0f0150ec
/*  f0150e4:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f0150e8:
/*  f0150e8:	24020028 */ 	addiu	$v0,$zero,0x28
.L0f0150ec:
/*  f0150ec:	18400034 */ 	blez	$v0,.L0f0151c0
/*  f0150f0:	00138900 */ 	sll	$s1,$s3,0x4
/*  f0150f4:	02338823 */ 	subu	$s1,$s1,$s3
/*  f0150f8:	3c128007 */ 	lui	$s2,%hi(var8006ae10)
/*  f0150fc:	2652ae10 */ 	addiu	$s2,$s2,%lo(var8006ae10)
/*  f015100:	001188c0 */ 	sll	$s1,$s1,0x3
/*  f015104:	2415ffef */ 	addiu	$s5,$zero,-17
/*  f015108:	2414fffd */ 	addiu	$s4,$zero,-3
/*  f01510c:	8e4f0000 */ 	lw	$t7,0x0($s2)
.L0f015110:
/*  f015110:	01f18021 */ 	addu	$s0,$t7,$s1
/*  f015114:	96180030 */ 	lhu	$t8,0x30($s0)
/*  f015118:	33190010 */ 	andi	$t9,$t8,0x10
/*  f01511c:	5320000f */ 	beqzl	$t9,.L0f01515c
/*  f015120:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f015124:	0c003ef1 */ 	jal	func0000fbc4
/*  f015128:	86040026 */ 	lh	$a0,0x26($s0)
/*  f01512c:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f015130:	01118021 */ 	addu	$s0,$t0,$s1
/*  f015134:	96090030 */ 	lhu	$t1,0x30($s0)
/*  f015138:	01355024 */ 	and	$t2,$t1,$s5
/*  f01513c:	a60a0030 */ 	sh	$t2,0x30($s0)
/*  f015140:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f015144:	01718021 */ 	addu	$s0,$t3,$s1
/*  f015148:	960c0030 */ 	lhu	$t4,0x30($s0)
/*  f01514c:	01946824 */ 	and	$t5,$t4,$s4
/*  f015150:	10000011 */ 	beqz	$zero,.L0f015198
/*  f015154:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f015158:	8e040000 */ 	lw	$a0,0x0($s0)
.L0f01515c:
/*  f01515c:	5080000f */ 	beqzl	$a0,.L0f01519c
/*  f015160:	92e90000 */ 	lbu	$t1,0x0($s7)
/*  f015164:	0c00cdfc */ 	jal	func000337f0
/*  f015168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01516c:	5040000b */ 	beqzl	$v0,.L0f01519c
/*  f015170:	92e90000 */ 	lbu	$t1,0x0($s7)
/*  f015174:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f015178:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f01517c:	0c00cec9 */ 	jal	func00033b24
/*  f015180:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f015184:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f015188:	03118021 */ 	addu	$s0,$t8,$s1
/*  f01518c:	96190030 */ 	lhu	$t9,0x30($s0)
/*  f015190:	03344024 */ 	and	$t0,$t9,$s4
/*  f015194:	a6080030 */ 	sh	$t0,0x30($s0)
.L0f015198:
/*  f015198:	92e90000 */ 	lbu	$t1,0x0($s7)
.L0f01519c:
/*  f01519c:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0151a0:	26310078 */ 	addiu	$s1,$s1,0x78
/*  f0151a4:	16c90003 */ 	bne	$s6,$t1,.L0f0151b4
/*  f0151a8:	24020028 */ 	addiu	$v0,$zero,0x28
/*  f0151ac:	10000001 */ 	beqz	$zero,.L0f0151b4
/*  f0151b0:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f0151b4:
/*  f0151b4:	0262082a */ 	slt	$at,$s3,$v0
/*  f0151b8:	5420ffd5 */ 	bnezl	$at,.L0f015110
/*  f0151bc:	8e4f0000 */ 	lw	$t7,0x0($s2)
.L0f0151c0:
/*  f0151c0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0151c4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0151c8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0151cc:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0151d0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0151d4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0151d8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0151dc:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f0151e0:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f0151e4:	03e00008 */ 	jr	$ra
/*  f0151e8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0151ec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0151f0
/*  f0151f0:	3c04800a */ 	lui	$a0,%hi(g_Objectives)
/*  f0151f4:	3c08800a */ 	lui	$t0,%hi(var8009d088)
/*  f0151f8:	3c06800a */ 	lui	$a2,%hi(var8009d088)
/*  f0151fc:	24c6d088 */ 	addiu	$a2,$a2,%lo(var8009d088)
/*  f015200:	2508d088 */ 	addiu	$t0,$t0,%lo(var8009d088)
/*  f015204:	2484d060 */ 	addiu	$a0,$a0,%lo(g_Objectives)
/*  f015208:	00001825 */ 	or	$v1,$zero,$zero
/*  f01520c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f015210:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f015214:
/*  f015214:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f015218:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f01521c:	1040000a */ 	beqz	$v0,.L0f015248
/*  f015220:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015224:	904e000e */ 	lbu	$t6,0xe($v0)
/*  f015228:	00c31021 */ 	addu	$v0,$a2,$v1
/*  f01522c:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f015230:	11e00005 */ 	beqz	$t7,.L0f015248
/*  f015234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015238:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f01523c:	10b80002 */ 	beq	$a1,$t8,.L0f015248
/*  f015240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015244:	ac470000 */ 	sw	$a3,0x0($v0)
.L0f015248:
/*  f015248:	1488fff2 */ 	bne	$a0,$t0,.L0f015214
/*  f01524c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f015250:	03e00008 */ 	jr	$ra
/*  f015254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01525c:	00000000 */ 	sll	$zero,$zero,0x0
);
