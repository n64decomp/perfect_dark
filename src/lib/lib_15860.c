#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_15860.h"
#include "types.h"

void initGlobalVariables(void)
{
	g_Vars.diffframe60f = 1;
	g_Vars.lvframe60 = 0;
	g_Vars.lvframenum = 0;
	g_Vars.unk00031c = 0;
	g_Vars.unk000320 = 0;
	g_Vars.diffframe60 = 1;
	g_Vars.lastframe240 = -1;
	g_Vars.thisframe240 = 0;
	g_Vars.diffframe240 = 4;
	g_Vars.diffframe60freal = 1;
	g_Vars.lastframetime = 0;
	g_Vars.thisframetime = 0;
	g_Vars.thisframeticks = 0;
	g_Vars.lostframetime = 0;
	g_Vars.lostframetime240 = 0;
	g_Vars.lvupdate240_60error = 2;
	g_Vars.mininc60 = 1;
	g_Vars.roomportalrecursionlimit = 254;
	g_Vars.diffframe240f = 4;
	g_Vars.diffframe240freal = 4;
	g_Vars.bondplayernum = 0;
	g_Vars.coopplayernum = -1;
	g_Vars.antiplayernum = -1;
	g_Vars.bond = NULL;
	g_Vars.coop = NULL;
	g_Vars.anti = NULL;
	g_Vars.coopradaron = 1;
	g_Vars.coopfriendlyfire = 1;
	g_Vars.antiradaron = 1;
	g_Vars.pendingantiplayernum = 1;
	g_Vars.unk000458 = 0;
	g_Vars.numaibuddies = 0;
	g_Vars.unk000324 = 1;
	g_Vars.unk000328 = 1;
	g_Vars.tickmode = TICKMODE_0;
	g_Vars.roomcount = 350;
	g_Vars.mplayerisrunning = 0;
	g_Vars.normmplayerisrunning = 0;
	g_Vars.perfectbuddynum = 0;
	g_Vars.unk00032c = 0;
	g_Vars.restartlevel = 0;
	g_Vars.unk00048c = 0;
	g_Vars.unk000490 = 0;
	g_Vars.unk000494 = 0;
	g_Vars.unk000495 = 0;
	g_Vars.unk000496 = 0;
	g_Vars.unk000497 = 0;
	g_Vars.unk000498 = 0;
	g_Vars.unk00049c = 0;
	g_Vars.unk0004a0 = 1;
	g_Vars.unk0004a4 = 1;
	g_Vars.unk0004a8 = 2;
	g_Vars.unk0004ac = 0;
	g_Vars.unk0004ad = 1;
	g_Vars.unk0004ae = 2;
	g_Vars.unk0004af = 3;
	g_Vars.mpquickteam = MPQUICKTEAM_5;
	g_Vars.unk0004c8 = 0;
	g_Vars.in_cutscene = false;
	g_Vars.unk0004d2 = -1;
	g_Vars.unk0004d3 = 0;
	g_Vars.unk0004d4 = -1;
	g_Vars.unk0004d5 = 0;
	g_Vars.unk0004d7 = 0;
	g_Vars.unk0004e0 = 0;
	g_Vars.unk0004e2 = 0;
}
