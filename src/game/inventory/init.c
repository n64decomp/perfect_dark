#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/cheats.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/inventory/init.h"
#include "game/inventory/inventory.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "types.h"

void invInitGunsHeld(void)
{
	s32 i;

	if (PLAYERCOUNT() == 1 && g_Vars.normmplayerisrunning == false) {
		g_Vars.currentplayer->equipallguns = cheatIsActive(CHEAT_ALLGUNS);
	} else {
		g_Vars.currentplayer->equipallguns = false;
	}

	for (i = 0; i != 10; i++) {
		g_Vars.currentplayer->gunheldarr[i].totaltime240_60 = -1;
	}
}

void invInit(s32 numdoubles)
{
	g_Vars.currentplayer->equipmaxitems = numdoubles + 30;
	g_Vars.currentplayer->equipment = malloc(ALIGN16(g_Vars.currentplayer->equipmaxitems * sizeof(struct invitem)), MEMPOOL_STAGE);
	invClear();
}
