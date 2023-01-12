#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "lib/debughud.h"
#include "bss.h"
#include "data.h"
#include "types.h"

#ifdef DEBUG
s32 g_DMenuSelectedOption = 0;
s32 g_DMenuNumOptions = 0;
char **g_DMenuCurLabels = NULL;
s32 (*g_DMenuCurPositions)[2] = NULL;
s32 g_DMenuNumGroups = 0;
s32 *g_DMenuCurOffsets = NULL;
u32 g_DMenuScaleIndex = 2;
u8 g_DMenuXScales[] = { 4, 4, 4 };
u8 g_DMenuYScales[] = { 7, 7, 7 };
#endif

#ifdef DEBUG
void dmenu0f118c80nb(void)
{
	// empty
}
#endif

void dmenuSetScaleIndex(s32 index)
{
#ifdef DEBUG
	g_DMenuScaleIndex = index;
#endif
}

void dmenuSetMenu(char **labels, s32 (*positions)[2], s32 *offsets)
{
#ifdef DEBUG
	s32 numgroups;

	g_DMenuCurLabels = labels;
	g_DMenuCurPositions = positions;
	g_DMenuCurOffsets = offsets;

	for (numgroups = 0; offsets[numgroups] >= 0; numgroups++);

	g_DMenuNumOptions = offsets[numgroups - 1];
	g_DMenuNumGroups = numgroups;
#endif
}

Gfx *dmenuRender(Gfx *gdl)
{
#ifdef DEBUG
	s32 xscale = g_DMenuXScales[g_DMenuScaleIndex];
	s32 yscale = g_DMenuYScales[g_DMenuScaleIndex];
	s32 i;

	gDPSetTextureLUT(gdl++, G_TT_NONE);

	// Render unselected/gray options
	for (i = 0; i < g_DMenuNumOptions; i++) {
		dmenu0f118c80nb();

		if (i != g_DMenuSelectedOption) {
			dhudSetFgColour(0xc0, 0xc0, 0xc0, 0xc0);
			dhudSetPos((g_DMenuCurPositions[i][0] * xscale - 20) / 4, (g_DMenuCurPositions[i][1] * yscale - 8) / 7);
			dhudPrintString(g_DMenuCurLabels[i]);
		}
	}

	// Render selected/red option
	for (i = 0; i < g_DMenuNumOptions; i++) {
		dmenu0f118c80nb();

		if (i == g_DMenuSelectedOption) {
			dhudSetFgColour(0xc0, 0, 0, 0xc0);
			dhudSetPos((g_DMenuCurPositions[i][0] * xscale - 20) / 4, (g_DMenuCurPositions[i][1] * yscale - 8) / 7);
			dhudPrintString(g_DMenuCurLabels[i]);
		}
	}
#endif

	return gdl;
}

#ifndef DEBUG
void debug0f11ed10(s32 arg0, s32 arg1, s32 arg2)
{
	// empty
}
#endif

s32 dmenuGetSelectedOption(void)
{
#ifdef DEBUG
	return g_DMenuSelectedOption;
#else
	return 0;
#endif
}

void dmenuSetSelectedOption(s32 option)
{
#ifdef DEBUG
	g_DMenuSelectedOption = option;
#endif
}

void dmenuNavigateUp(void)
{
#ifdef DEBUG
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
#endif
}

void dmenuNavigateDown(void)
{
#ifdef DEBUG
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
#endif
}

void dmenuNavigateRight(void)
{
#ifdef DEBUG
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
#endif
}

void dmenuNavigateLeft(void)
{
#ifdef DEBUG
	s32 i;

	// First group
	if (g_DMenuSelectedOption < g_DMenuCurOffsets[0]) {
		s32 i;

		for (i = 0; i < g_DMenuNumGroups - 1; i++);

		if (i > 0) {
			g_DMenuSelectedOption += g_DMenuCurOffsets[i - 1];

			if (g_DMenuSelectedOption >= g_DMenuCurOffsets[i]) {
				g_DMenuSelectedOption = g_DMenuCurOffsets[i] - 1;
			}
		}
		return;
	}

	// Any other group
	for (i = 0; g_DMenuSelectedOption >= g_DMenuCurOffsets[i]; i++);

	g_DMenuSelectedOption -= g_DMenuCurOffsets[i - 1];

	if (i - 2 >= 0) {
		g_DMenuSelectedOption += g_DMenuCurOffsets[i - 2];
	}

	if (g_DMenuSelectedOption >= g_DMenuCurOffsets[i - 1]) {
		g_DMenuSelectedOption = g_DMenuCurOffsets[i - 1] - 1;
	}
#endif
}
