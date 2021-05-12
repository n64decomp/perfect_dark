#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

struct g_vars g_Vars;

void gvarsInit(void)
{
	g_Vars.diffframe60f = 1;
	g_Vars.lvframe60 = 0;
	g_Vars.lvframenum = 0;
	g_Vars.lvmpbotlevel = 0;
	g_Vars.lockscreen = 0;
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
	g_Vars.modifiedfiles = 0;
	g_Vars.numaibuddies = 0;
	g_Vars.bondvisible = true;
	g_Vars.bondcollisions = true;
	g_Vars.tickmode = TICKMODE_0;
	g_Vars.roomcount = 350;
	g_Vars.mplayerisrunning = 0;
	g_Vars.normmplayerisrunning = 0;
	g_Vars.perfectbuddynum = 0;
	g_Vars.enableslopes = false;
	g_Vars.restartlevel = 0;
	g_Vars.unk00048c = 0;
	g_Vars.unk000490 = 0;
	g_Vars.unk000494[0] = 0;
	g_Vars.unk000494[1] = 0;
	g_Vars.unk000494[2] = 0;
	g_Vars.unk000494[3] = 0;
	g_Vars.unk000498 = 0;
	g_Vars.unk00049c = 0;
	g_Vars.unk0004a0 = 1;
	g_Vars.mpquickteamnumsims = 1;
	g_Vars.mpsimdifficulty = SIMDIFF_NORMAL;
	g_Vars.mpplayerteams[0] = 0;
	g_Vars.mpplayerteams[1] = 1;
	g_Vars.mpplayerteams[2] = 2;
	g_Vars.mpplayerteams[3] = 3;
	g_Vars.mpquickteam = MPQUICKTEAM_NONE;
	g_Vars.dontplaynrg = false;
	g_Vars.in_cutscene = false;
	g_Vars.autocutnum = -1;
	g_Vars.autocutplaying = false;
	g_Vars.autocutgroupcur = -1;
	g_Vars.autocutgroupleft = 0;
	g_Vars.autocutgroupskip = false;
	g_Vars.fourmeg2player = false;
	g_Vars.cutsceneskip60ths = 0;
}
