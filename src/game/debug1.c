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
s32 g_DMenuNumGroups = 0;
s32 *g_DMenuCurOffsets = NULL;
u32 g_DMenuScaleIndex = 2;
u8 g_DMenuXScales[] = { 4, 4, 4 };
u8 g_DMenuYScales[] = { 7, 7, 7 };

void dmenu0f118c80nb(void)
{
	// empty
}

void dmenuSetScaleIndex(s32 index)
{
	g_DMenuScaleIndex = index;
}

void dmenuSetMenu(char **labels, s32 (*positions)[2], s32 *offsets)
{
	s32 numgroups;

	g_DMenuCurLabels = labels;
	g_DMenuCurPositions = positions;
	g_DMenuCurOffsets = offsets;

	for (numgroups = 0; offsets[numgroups] >= 0; numgroups++);

	g_DMenuNumOptions = offsets[numgroups - 1];
	g_DMenuNumGroups = numgroups;
}

Gfx *dmenuRender(Gfx *gdl)
{
	s32 xscale = g_DMenuXScales[g_DMenuScaleIndex];
	s32 yscale = g_DMenuYScales[g_DMenuScaleIndex];
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

s32 dmenuGetSelectedOption(void)
{
	return g_DMenuSelectedOption;
}

void dmenuSetSelectedOption(s32 option)
{
	g_DMenuSelectedOption = option;
}

void dmenuNavigateUp(void)
{
	s32 i;

	g_DMenuSelectedOption--;

	// If at the top of the first group, wrap to the bottom of the group.
	// This must be treated differently to the other groups because the first
	// group's offset is omitted from the offsets array.
	if (g_DMenuSelectedOption < 0) {
		g_DMenuSelectedOption = g_DMenuCurOffsets[0] - 1;
		return;
	}

	// If at the top of any other group, wrap to the bottom of that group.
	for (i = 0; i < g_DMenuNumGroups; i++) {
		if (g_DMenuSelectedOption == g_DMenuCurOffsets[i] - 1) {
			g_DMenuSelectedOption = g_DMenuCurOffsets[i + 1] - 1;
			return;
		}
	}
}

void dmenuNavigateDown(void)
{
	s32 i;

	g_DMenuSelectedOption++;

	// If at the bottom of the first group, wrap to the top of the group.
	// This must be treated differently to the other groups because the first
	// group's offset is omitted from the offsets array.
	if (g_DMenuSelectedOption == g_DMenuCurOffsets[0]) {
		g_DMenuSelectedOption = 0;
		return;
	}

	// If at the bottom of any other group, wrap to the top of that group.
	for (i = 0; i < g_DMenuNumGroups; i++) {
		if (g_DMenuSelectedOption == g_DMenuCurOffsets[i]) {
			g_DMenuSelectedOption = g_DMenuCurOffsets[i - 1];
			return;
		}
	}
}

void dmenuNavigateRight(void)
{
	s32 i;

	if (g_DMenuSelectedOption < g_DMenuCurOffsets[0]) {
		if (g_DMenuNumGroups >= 2) {
			g_DMenuSelectedOption += g_DMenuCurOffsets[0];

			if (g_DMenuSelectedOption >= g_DMenuCurOffsets[1]) {
				g_DMenuSelectedOption = g_DMenuCurOffsets[1] - 1;
			}
		}
		return;
	}

	for (i = 0; i < g_DMenuNumGroups; i++) {
		if (g_DMenuSelectedOption < g_DMenuCurOffsets[i]) {
			g_DMenuSelectedOption = g_DMenuSelectedOption + g_DMenuCurOffsets[i] - g_DMenuCurOffsets[i - 1];

			if (g_DMenuCurOffsets[i + 1] < 0) {
				g_DMenuSelectedOption -= g_DMenuCurOffsets[i];

				if (g_DMenuSelectedOption >= g_DMenuCurOffsets[0]) {
					g_DMenuSelectedOption = g_DMenuCurOffsets[0] - 1;
				}
			} else {
				if (g_DMenuSelectedOption >= g_DMenuCurOffsets[i + 1]) {
					g_DMenuSelectedOption = g_DMenuCurOffsets[i + 1] - 1;
				}
			}
			return;
		}
	}
}

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
