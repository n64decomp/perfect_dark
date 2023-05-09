#include <ultra64.h>
#include "constants.h"
#include "game/body.h"
#include "game/cheats.h"
#include "game/chrai.h"
#include "game/game_00b820.h"
#include "game/playerreset.h"
#include "game/setuputils.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

struct stageheadlimit g_StageHeadLimits[3] = {
	{ STAGE_INFILTRATION, 5 },
	{ STAGE_RESCUE,       4 },
	{ STAGE_ESCAPE,       5 },
};


void bodiesReset(s32 stagenum)
{
	s32 *headsavailablelist;
	s32 headsavailablelen;
	bool done;
	s32 i;
	s32 j;

	for (i = 0; g_HeadsAndBodies[i].filenum; i++) {
		g_HeadsAndBodies[i].filedata = NULL;
	}

	var80062c80 = random() % g_NumBondBodies;

	if (PLAYERCOUNT() >= 2) {
		g_NumActiveHeadsPerGender = 4;
	} else {
		// 950
		g_NumActiveHeadsPerGender = 8;

		for (i = 0; i < ARRAYCOUNT(g_StageHeadLimits); i++) {
			if (g_StageHeadLimits[i].stagenum == stagenum) {
				g_NumActiveHeadsPerGender = g_StageHeadLimits[i].maxheads;
			}
		}
	}

	// Male heads
	if (cheatIsActive(CHEAT_TEAMHEADSONLY)) {
		headsavailablelist = g_MaleGuardTeamHeads;
		headsavailablelen = g_NumMaleGuardTeamHeads;
	} else {
		headsavailablelist = g_MaleGuardHeads;
		headsavailablelen = g_NumMaleGuardHeads;
	}

	for (i = 0; i < g_NumActiveHeadsPerGender; i++) {
		do {
			done = true;
			g_ActiveMaleHeads[i] = headsavailablelist[random() % headsavailablelen];

			if (headsavailablelen > g_NumActiveHeadsPerGender) {
				for (j = 0; j < i; j++) {
					if (g_ActiveMaleHeads[i] == g_ActiveMaleHeads[j]) {
						done = false;
					}
				}
			}
		} while (!done);
	}

	// Female heads
	if (cheatIsActive(CHEAT_TEAMHEADSONLY)) {
		headsavailablelist = g_FemaleGuardTeamHeads;
		headsavailablelen = g_NumFemaleGuardTeamHeads;
	} else {
		headsavailablelist = g_FemaleGuardHeads;
		headsavailablelen = g_NumFemaleGuardHeads;
	}

	for (i = 0; i < g_NumActiveHeadsPerGender; i++) {
		do {
			done = true;
			g_ActiveFemaleHeads[i] = headsavailablelist[random() % headsavailablelen];

			if (headsavailablelen > g_NumActiveHeadsPerGender) {
				for (j = 0; j < i; j++) {
					if (g_ActiveFemaleHeads[i] == g_ActiveFemaleHeads[j]) {
						done = false;
					}
				}
			}
		} while (!done);
	}

	g_ActiveMaleHeadsIndex = 0;
	g_ActiveFemaleHeadsIndex = 0;
}
