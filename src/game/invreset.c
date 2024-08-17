#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/cheats.h"
#include "game/inv.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void inv_reset(void)
{
	s32 i;

	if (PLAYERCOUNT() == 1 && g_Vars.normmplayerisrunning == false) {
		g_Vars.currentplayer->equipallguns = cheat_is_active(CHEAT_ALLGUNS);
	} else {
		g_Vars.currentplayer->equipallguns = false;
	}

	for (i = 0; i != ARRAYCOUNT(g_Vars.currentplayer->gunheldarr); i++) {
		g_Vars.currentplayer->gunheldarr[i].totaltime240_60 = -1;
	}
}

void inv_init(s32 numdoubles)
{
	g_Vars.currentplayer->equipmaxitems = numdoubles + 30;
	g_Vars.currentplayer->equipment = memp_alloc(ALIGN16(g_Vars.currentplayer->equipmaxitems * sizeof(struct invitem)), MEMPOOL_STAGE);
	inv_clear();
}
