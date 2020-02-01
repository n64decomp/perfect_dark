#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chr/chr.h"
#include "game/game_012450.h"
#include "game/game_111600.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"

void currentPlayerInitGunsHeld(void)
{
	s32 i;

	if (PLAYERCOUNT() == 1 && g_Vars.mplayerisrunning == false) {
		g_Vars.currentplayer->equipallguns = cheatIsActive(CHEAT_ALLGUNS);
	} else {
		g_Vars.currentplayer->equipallguns = false;
	}

	for (i = 0; i != 10; i++) {
		g_Vars.currentplayer->gunheldarr[i].unk08 = -1;
	}
}

void func0f012530(s32 arg0)
{
	g_Vars.currentplayer->equipmaxitems = arg0 + 30;
	g_Vars.currentplayer->unk1868 = func000123c8((g_Vars.currentplayer->equipmaxitems * 20 + 15 | 0xf) ^ 0xf, 4);
	func0f111600();
}
