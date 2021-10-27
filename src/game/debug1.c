#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "lib/lib_13790.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 g_DMenuSelectedOption = 0;
s32 g_DMenuNumOptions = 0;
char **g_DMenuCurLabels = NULL;
s32 (*g_DMenuCurPositions)[2] = NULL;
s32 g_DmenuNumGroups = 0;
s32 *g_DMenuCurOffsets = NULL;
u32 var80078138nb = 2;
u8 var8007813cnb[] = { 4, 4, 4 };
u8 var80078140nb[] = { 7, 7, 7 };

void dmenu0f118c80nb(void)
{
	// empty
}

GLOBAL_ASM(
glabel dmenuSetScaleIndex
/*  f118c88:	3c018008 */ 	lui	$at,0x8008
/*  f118c8c:	03e00008 */ 	jr	$ra
/*  f118c90:	ac248138 */ 	sw	$a0,-0x7ec8($at)
);

void dmenuSetMenu(char **labels, s32 (*positions)[2], s32 *offsets)
{
	s32 numgroups;

	g_DMenuCurLabels = labels;
	g_DMenuCurPositions = positions;
	g_DMenuCurOffsets = offsets;

	for (numgroups = 0; offsets[numgroups] >= 0; numgroups++);

	g_DMenuNumOptions = offsets[numgroups - 1];
	g_DmenuNumGroups = numgroups;
}

Gfx *dmenuRender(Gfx *gdl)
{
	s32 xscale = var8007813cnb[var80078138nb];
	s32 yscale = var80078140nb[var80078138nb];
	s32 i;

	gDPSetTextureLUT(gdl++, G_TT_NONE);

	// Render unselected/gray options
	for (i = 0; i < g_DMenuNumOptions; i++) {
		dmenu0f118c80nb();

		if (i != g_DMenuSelectedOption) {
			func000137bc(0xc0, 0xc0, 0xc0, 0xc0);
			func000137b0((g_DMenuCurPositions[i][0] * xscale - 20) / 4, (g_DMenuCurPositions[i][1] * yscale - 8) / 7);
			func000137fc(g_DMenuCurLabels[i]);
		}
	}

	// Render selected/red option
	for (i = 0; i < g_DMenuNumOptions; i++) {
		dmenu0f118c80nb();

		if (i == g_DMenuSelectedOption) {
			func000137bc(0xc0, 0, 0, 0xc0);
			func000137b0((g_DMenuCurPositions[i][0] * xscale - 20) / 4, (g_DMenuCurPositions[i][1] * yscale - 8) / 7);
			func000137fc(g_DMenuCurLabels[i]);
		}
	}

	return gdl;
}

GLOBAL_ASM(
glabel dmenuGetSelectedOption
/*  f118f70:	3c028008 */ 	lui	$v0,0x8008
/*  f118f74:	03e00008 */ 	jr	$ra
/*  f118f78:	8c428120 */ 	lw	$v0,-0x7ee0($v0)
);

GLOBAL_ASM(
glabel dmenuSetSelectedOption
/*  f118f7c:	3c018008 */ 	lui	$at,0x8008
/*  f118f80:	03e00008 */ 	jr	$ra
/*  f118f84:	ac248120 */ 	sw	$a0,-0x7ee0($at)
);

GLOBAL_ASM(
glabel dmenuNavigateUp
/*  f118f88:	3c068008 */ 	lui	$a2,0x8008
/*  f118f8c:	24c68120 */ 	addiu	$a2,$a2,-32480
/*  f118f90:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f118f94:	3c188008 */ 	lui	$t8,0x8008
/*  f118f98:	3c048008 */ 	lui	$a0,0x8008
/*  f118f9c:	25c2ffff */ 	addiu	$v0,$t6,-1
/*  f118fa0:	04410006 */ 	bgez	$v0,.NB0f118fbc
/*  f118fa4:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f118fa8:	8f188134 */ 	lw	$t8,-0x7ecc($t8)
/*  f118fac:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f118fb0:	2728ffff */ 	addiu	$t0,$t9,-1
/*  f118fb4:	03e00008 */ 	jr	$ra
/*  f118fb8:	acc80000 */ 	sw	$t0,0x0($a2)
.NB0f118fbc:
/*  f118fbc:	8c848130 */ 	lw	$a0,-0x7ed0($a0)
/*  f118fc0:	00001825 */ 	or	$v1,$zero,$zero
/*  f118fc4:	3c058008 */ 	lui	$a1,0x8008
/*  f118fc8:	1880000d */ 	blez	$a0,.NB0f119000
/*  f118fcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118fd0:	8ca58134 */ 	lw	$a1,-0x7ecc($a1)
.NB0f118fd4:
/*  f118fd4:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f118fd8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f118fdc:	24490001 */ 	addiu	$t1,$v0,0x1
/*  f118fe0:	152a0005 */ 	bne	$t1,$t2,.NB0f118ff8
/*  f118fe4:	0064082a */ 	slt	$at,$v1,$a0
/*  f118fe8:	8cab0004 */ 	lw	$t3,0x4($a1)
/*  f118fec:	256cffff */ 	addiu	$t4,$t3,-1
/*  f118ff0:	03e00008 */ 	jr	$ra
/*  f118ff4:	accc0000 */ 	sw	$t4,0x0($a2)
.NB0f118ff8:
/*  f118ff8:	1420fff6 */ 	bnez	$at,.NB0f118fd4
/*  f118ffc:	24a50004 */ 	addiu	$a1,$a1,0x4
.NB0f119000:
/*  f119000:	03e00008 */ 	jr	$ra
/*  f119004:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel dmenuNavigateDown
/*  f119008:	3c078008 */ 	lui	$a3,0x8008
/*  f11900c:	24e78120 */ 	addiu	$a3,$a3,-32480
/*  f119010:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f119014:	3c038008 */ 	lui	$v1,0x8008
/*  f119018:	3c058008 */ 	lui	$a1,0x8008
/*  f11901c:	25c20001 */ 	addiu	$v0,$t6,0x1
/*  f119020:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f119024:	8c638134 */ 	lw	$v1,-0x7ecc($v1)
/*  f119028:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f11902c:	14580003 */ 	bne	$v0,$t8,.NB0f11903c
/*  f119030:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119034:	03e00008 */ 	jr	$ra
/*  f119038:	ace00000 */ 	sw	$zero,0x0($a3)
.NB0f11903c:
/*  f11903c:	8ca58130 */ 	lw	$a1,-0x7ed0($a1)
/*  f119040:	00002025 */ 	or	$a0,$zero,$zero
/*  f119044:	00603025 */ 	or	$a2,$v1,$zero
/*  f119048:	18a0000b */ 	blez	$a1,.NB0f119078
/*  f11904c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f119050:
/*  f119050:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f119054:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f119058:	0085082a */ 	slt	$at,$a0,$a1
/*  f11905c:	14590004 */ 	bne	$v0,$t9,.NB0f119070
/*  f119060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119064:	8cc8fffc */ 	lw	$t0,-0x4($a2)
/*  f119068:	03e00008 */ 	jr	$ra
/*  f11906c:	ace80000 */ 	sw	$t0,0x0($a3)
.NB0f119070:
/*  f119070:	1420fff7 */ 	bnez	$at,.NB0f119050
/*  f119074:	24c60004 */ 	addiu	$a2,$a2,0x4
.NB0f119078:
/*  f119078:	03e00008 */ 	jr	$ra
/*  f11907c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel dmenuNavigateRight
/*  f119080:	3c038008 */ 	lui	$v1,0x8008
/*  f119084:	8c638134 */ 	lw	$v1,-0x7ecc($v1)
/*  f119088:	3c088008 */ 	lui	$t0,0x8008
/*  f11908c:	25088120 */ 	addiu	$t0,$t0,-32480
/*  f119090:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f119094:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f119098:	3c0e8008 */ 	lui	$t6,0x8008
/*  f11909c:	0044082a */ 	slt	$at,$v0,$a0
/*  f1190a0:	1020000d */ 	beqz	$at,.NB0f1190d8
/*  f1190a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1190a8:	8dce8130 */ 	lw	$t6,-0x7ed0($t6)
/*  f1190ac:	00447821 */ 	addu	$t7,$v0,$a0
/*  f1190b0:	29c10002 */ 	slti	$at,$t6,0x2
/*  f1190b4:	1420002d */ 	bnez	$at,.NB0f11916c
/*  f1190b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1190bc:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f1190c0:	8c650004 */ 	lw	$a1,0x4($v1)
/*  f1190c4:	01e5082a */ 	slt	$at,$t7,$a1
/*  f1190c8:	14200028 */ 	bnez	$at,.NB0f11916c
/*  f1190cc:	24b9ffff */ 	addiu	$t9,$a1,-1
/*  f1190d0:	03e00008 */ 	jr	$ra
/*  f1190d4:	ad190000 */ 	sw	$t9,0x0($t0)
.NB0f1190d8:
/*  f1190d8:	3c048008 */ 	lui	$a0,0x8008
/*  f1190dc:	8c848130 */ 	lw	$a0,-0x7ed0($a0)
/*  f1190e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1190e4:	00603025 */ 	or	$a2,$v1,$zero
/*  f1190e8:	18800020 */ 	blez	$a0,.NB0f11916c
/*  f1190ec:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1190f0:
/*  f1190f0:	8cc70000 */ 	lw	$a3,0x0($a2)
/*  f1190f4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1190f8:	0047082a */ 	slt	$at,$v0,$a3
/*  f1190fc:	50200019 */ 	beqzl	$at,.NB0f119164
/*  f119100:	00a4082a */ 	slt	$at,$a1,$a0
/*  f119104:	8ccafffc */ 	lw	$t2,-0x4($a2)
/*  f119108:	00474821 */ 	addu	$t1,$v0,$a3
/*  f11910c:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f119110:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*  f119114:	8cc40004 */ 	lw	$a0,0x4($a2)
/*  f119118:	0483000b */ 	bgezl	$a0,.NB0f119148
/*  f11911c:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f119120:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f119124:	016d7023 */ 	subu	$t6,$t3,$t5
/*  f119128:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f11912c:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f119130:	01c4082a */ 	slt	$at,$t6,$a0
/*  f119134:	1420000d */ 	bnez	$at,.NB0f11916c
/*  f119138:	2498ffff */ 	addiu	$t8,$a0,-1
/*  f11913c:	03e00008 */ 	jr	$ra
/*  f119140:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f119144:	8d190000 */ 	lw	$t9,0x0($t0)
.NB0f119148:
/*  f119148:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f11914c:	0324082a */ 	slt	$at,$t9,$a0
/*  f119150:	14200006 */ 	bnez	$at,.NB0f11916c
/*  f119154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119158:	03e00008 */ 	jr	$ra
/*  f11915c:	ad090000 */ 	sw	$t1,0x0($t0)
/*  f119160:	00a4082a */ 	slt	$at,$a1,$a0
.NB0f119164:
/*  f119164:	1420ffe2 */ 	bnez	$at,.NB0f1190f0
/*  f119168:	24c60004 */ 	addiu	$a2,$a2,0x4
.NB0f11916c:
/*  f11916c:	03e00008 */ 	jr	$ra
/*  f119170:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel dmenuNavigateLeft
/*  f119174:	3c038008 */ 	lui	$v1,0x8008
/*  f119178:	8c638134 */ 	lw	$v1,-0x7ecc($v1)
/*  f11917c:	3c078008 */ 	lui	$a3,0x8008
/*  f119180:	24e78120 */ 	addiu	$a3,$a3,-32480
/*  f119184:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f119188:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f11918c:	3c058008 */ 	lui	$a1,0x8008
/*  f119190:	0044082a */ 	slt	$at,$v0,$a0
/*  f119194:	50200017 */ 	beqzl	$at,.NB0f1191f4
/*  f119198:	0044082a */ 	slt	$at,$v0,$a0
/*  f11919c:	8ca58130 */ 	lw	$a1,-0x7ed0($a1)
/*  f1191a0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1191a4:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f1191a8:	18a00005 */ 	blez	$a1,.NB0f1191c0
/*  f1191ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1191b0:	24840001 */ 	addiu	$a0,$a0,0x1
.NB0f1191b4:
/*  f1191b4:	0085082a */ 	slt	$at,$a0,$a1
/*  f1191b8:	5420fffe */ 	bnezl	$at,.NB0f1191b4
/*  f1191bc:	24840001 */ 	addiu	$a0,$a0,0x1
.NB0f1191c0:
/*  f1191c0:	18800026 */ 	blez	$a0,.NB0f11925c
/*  f1191c4:	00047080 */ 	sll	$t6,$a0,0x2
/*  f1191c8:	006e2821 */ 	addu	$a1,$v1,$t6
/*  f1191cc:	8caffffc */ 	lw	$t7,-0x4($a1)
/*  f1191d0:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f1191d4:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f1191d8:	8ca60000 */ 	lw	$a2,0x0($a1)
/*  f1191dc:	0306082a */ 	slt	$at,$t8,$a2
/*  f1191e0:	1420001e */ 	bnez	$at,.NB0f11925c
/*  f1191e4:	24c8ffff */ 	addiu	$t0,$a2,-1
/*  f1191e8:	03e00008 */ 	jr	$ra
/*  f1191ec:	ace80000 */ 	sw	$t0,0x0($a3)
/*  f1191f0:	0044082a */ 	slt	$at,$v0,$a0
.NB0f1191f4:
/*  f1191f4:	14200008 */ 	bnez	$at,.NB0f119218
/*  f1191f8:	00002825 */ 	or	$a1,$zero,$zero
/*  f1191fc:	00602025 */ 	or	$a0,$v1,$zero
/*  f119200:	8c890004 */ 	lw	$t1,0x4($a0)
.NB0f119204:
/*  f119204:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f119208:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f11920c:	0049082a */ 	slt	$at,$v0,$t1
/*  f119210:	5020fffc */ 	beqzl	$at,.NB0f119204
/*  f119214:	8c890004 */ 	lw	$t1,0x4($a0)
.NB0f119218:
/*  f119218:	00055080 */ 	sll	$t2,$a1,0x2
/*  f11921c:	006a2021 */ 	addu	$a0,$v1,$t2
/*  f119220:	8c8bfffc */ 	lw	$t3,-0x4($a0)
/*  f119224:	24adfffe */ 	addiu	$t5,$a1,-2
/*  f119228:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f11922c:	05a00004 */ 	bltz	$t5,.NB0f119240
/*  f119230:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f119234:	8c8ffff8 */ 	lw	$t7,-0x8($a0)
/*  f119238:	018fc021 */ 	addu	$t8,$t4,$t7
/*  f11923c:	acf80000 */ 	sw	$t8,0x0($a3)
.NB0f119240:
/*  f119240:	8c82fffc */ 	lw	$v0,-0x4($a0)
/*  f119244:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f119248:	2448ffff */ 	addiu	$t0,$v0,-1
/*  f11924c:	0322082a */ 	slt	$at,$t9,$v0
/*  f119250:	14200002 */ 	bnez	$at,.NB0f11925c
/*  f119254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119258:	ace80000 */ 	sw	$t0,0x0($a3)
.NB0f11925c:
/*  f11925c:	03e00008 */ 	jr	$ra
/*  f119260:	00000000 */ 	sll	$zero,$zero,0x0
);
