#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_317f0.h"
#include "types.h"

void bcutsceneInit(void)
{
	s32 i;
	s32 j;

	g_Vars.currentplayer->bondmovemode = MOVEMODE_CUTSCENE;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->joybutinhibit = 0xffffffff;

		// @bug? Should this be < 2?
		for (j = 0; j < 1; j++) {
			struct hand *hand = &g_Vars.players[i]->hands[j];

			if (hand->audiohandle && audioIsPlaying(hand->audiohandle)) {
				audioStop(hand->audiohandle);
				hand->audiohandle = NULL;
			}

			hand->unk063c = 0;
		}
	}
}

void bcutsceneTick(void)
{
	// empty
}
