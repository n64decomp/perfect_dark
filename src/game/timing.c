#include <ultra64.h>
#include "constants.h"
#include "game/timing.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void frametimeInit(void)
{
	g_Vars.thisframestartt = osGetCount();
	g_Vars.prevframestartt = g_Vars.thisframestartt;
}

void frametimeApply(s32 diffframe60, s32 diffframe240, s32 frametime)
{
	g_Vars.prevframestartt = g_Vars.thisframestartt;
	g_Vars.thisframestartt = frametime;

	g_Vars.diffframe60 = diffframe60;
	g_Vars.diffframe60f = diffframe60;
	g_Vars.diffframe60freal = PALUPF(g_Vars.diffframe60f);

	g_Vars.prevframestart240 = g_Vars.thisframestart240;
	g_Vars.thisframestart240 += diffframe240;
	g_Vars.diffframe240 = diffframe240;
	g_Vars.diffframe240f = diffframe240;
	g_Vars.diffframe240freal = PALUPF(g_Vars.diffframe240f);
}

void frametimeCalculate(void)
{
	u32 count;
	u32 diffframet;
	u32 diffframe60;
	u32 diffframe240;

	do {
		count = osGetCount();
		diffframet = count - g_Vars.thisframestartt;
		g_Vars.diffframet = diffframet;

		diffframe60 = (g_Vars.lostframetime60t + diffframet + CYCLES_PER_FRAME / 2) / CYCLES_PER_FRAME;
		diffframe240 = (g_Vars.lostframetime240t + diffframet + CYCLES_PER_FRAME / 2 / 4) / (CYCLES_PER_FRAME / 4);
	} while (diffframe60 < g_Vars.mininc60);

	g_Vars.lostframetime60t = g_Vars.lostframetime60t + diffframet - diffframe60 * CYCLES_PER_FRAME;
	g_Vars.lostframetime240t = g_Vars.lostframetime240t + diffframet - diffframe240 * (CYCLES_PER_FRAME / 4);

	g_Vars.mininc60 = 1;

	frametimeApply(diffframe60, diffframe240, count);
}

void func0f16cf8c(s32 arg0)
{
	// empty
}

void func0f16cf94(void)
{
	// empty
}
