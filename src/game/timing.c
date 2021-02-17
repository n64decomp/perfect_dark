#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/timing.h"
#include "gvars/gvars.h"
#include "types.h"

void frametimeInit(void)
{
	g_Vars.thisframetime = osGetCount();
	g_Vars.lastframetime = g_Vars.thisframetime;
}

void frametimeApply(s32 diffframe60, s32 diffframe240, s32 frametime)
{
	g_Vars.lastframetime = g_Vars.thisframetime;
	g_Vars.thisframetime = frametime;

	g_Vars.diffframe60 = diffframe60;
	g_Vars.diffframe60freal = g_Vars.diffframe60f = diffframe60;

	g_Vars.lastframe240 = g_Vars.thisframe240;
	g_Vars.thisframe240 += diffframe240;
	g_Vars.diffframe240 = diffframe240;
	g_Vars.diffframe240freal = g_Vars.diffframe240f = diffframe240;
}

void frametimeCalculate(void)
{
	u32 count;
	u32 thisframeticks;
	u32 diffframe60;
	u32 diffframe240;

    do {
		count = osGetCount();
		thisframeticks = count - g_Vars.thisframetime;
		g_Vars.thisframeticks = thisframeticks;

		diffframe60 = (g_Vars.lostframetime + thisframeticks + 390625) / 781250;
		diffframe240 = (g_Vars.lostframetime240 + thisframeticks + 97656) / 195312;
	} while (diffframe60 < g_Vars.mininc60);

    g_Vars.lostframetime = (g_Vars.lostframetime + thisframeticks) - (diffframe60 * 781250);
    g_Vars.lostframetime240 = (g_Vars.lostframetime240 + thisframeticks) - (diffframe240 * 195312);
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
