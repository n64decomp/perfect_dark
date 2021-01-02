#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_19aa80.h"
#include "game/mplayer/mplayer.h"
#include "gvars/gvars.h"
#include "types.h"

void mpInitPresetFeatures(void)
{
	struct mpconfigfull *mpconfig;
	u8 buffer[0x1ca];
	s32 i;

	for (i = 0; i < 30; i++) {
		g_MpChallenges[i].availability = 0;
		g_MpChallenges[i].completions[0] = 0;
		g_MpChallenges[i].completions[1] = 0;
		g_MpChallenges[i].completions[2] = 0;
		g_MpChallenges[i].completions[3] = 0;

		mpconfig = mpLoadChallenge(i, buffer, 0x1ca);
		mpForceUnlockConfigFeatures(&mpconfig->config, g_MpChallenges[i].unlockfeatures, 16, i);
	}

	for (i = 0; i < mpGetNumPresets(); i++) {
		mpconfig = mpLoadConfig(g_MpPresets[i].confignum, buffer, 0x1ca);
		mpForceUnlockConfigFeatures(&mpconfig->config, g_MpPresets[i].requirefeatures, 16, -1);
	}

	mpDetermineUnlockedFeatures();
}
