#include <ultra64.h>
#include "constants.h"
#include "game/challenge.h"
#include "game/mplayer/mplayer.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void challengesInit(void)
{
	struct mpconfigfull *mpconfig;
	u8 buffer[0x1ca];
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpChallenges); i++) {
		g_MpChallenges[i].availability = 0;
		g_MpChallenges[i].completions[0] = 0;
		g_MpChallenges[i].completions[1] = 0;
		g_MpChallenges[i].completions[2] = 0;
		g_MpChallenges[i].completions[3] = 0;

		mpconfig = challengeLoad(i, buffer, 0x1ca);
		challengeForceUnlockConfigFeatures(&mpconfig->config, g_MpChallenges[i].unlockfeatures, 16, i);
	}

	for (i = 0; i < mpGetNumPresets(); i++) {
		mpconfig = challengeLoadConfig(g_MpPresets[i].confignum, buffer, 0x1ca);
		challengeForceUnlockConfigFeatures(&mpconfig->config, g_MpPresets[i].requirefeatures, 16, -1);
	}

	challengeDetermineUnlockedFeatures();
}
