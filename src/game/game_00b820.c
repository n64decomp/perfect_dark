#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chrai.h"
#include "game/game_00b820.h"
#include "game/playerreset.h"
#include "game/body.h"
#include "game/setuputils.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

struct prop *g_DangerousProps[MAX_DANGEROUSPROPS];

void resetSomeStageThings(void)
{
	s32 i;

	for (i = 0; i != MAX_DANGEROUSPROPS; i++) {
		g_DangerousProps[i] = NULL;
	}

	g_StageFlags = 0;

	g_EnemyAccuracyScale = 1;
	g_PlayerDamageRxScale = 1;
	g_PlayerDamageTxScale = 1;
	g_AttackWalkDurationScale = 1;

	g_NumChrsSeenPlayerRecently2 = 0;
}

void stageAllocateBgChrs(void)
{
	bool modified;
	struct chrdata tmp;
	s32 i;

	g_BgChrs = NULL;
	g_BgChrnums = 0;
	g_NumBgChrs = 0;

	if (!g_StageSetup.ailists) {
		return;
	}

	// Count the number of background AI lists
	i = 0;

	while (g_StageSetup.ailists[i].list) {
		if (g_StageSetup.ailists[i].id >= 0x1000) {
			g_NumBgChrs++;
		}

		i++;
	}

	// Add one for cutscene
	g_NumBgChrs++;

	if (g_NumBgChrs > 0) {
		s32 count = 0;
		struct chrdata blankchr = {0};

		// Allocate BG chrs
		g_BgChrs = mempAlloc(ALIGN16(g_NumBgChrs * sizeof(struct chrdata)), MEMPOOL_STAGE);
		g_BgChrnums = mempAlloc(ALIGN16(g_NumBgChrs * sizeof(s16)), MEMPOOL_STAGE);

		// Initialise BG chrs
		i = 0;

		while (g_StageSetup.ailists[i].list) {
			if (g_StageSetup.ailists[i].id >= 0x1000) {
				g_BgChrs[count] = blankchr;

				if (g_StageSetup.ailists[i].id >= 0x1400) {
					g_BgChrs[count].chrnum = g_StageSetup.ailists[i].id - 0x460; // 4000+
					g_BgChrs[count].hidden2 |= CHRH2FLAG_TICKDURINGAUTOCUT;
				} else {
					g_BgChrs[count].chrnum = g_StageSetup.ailists[i].id - 0x60; // 4000+
				}

				g_BgChrs[count].ailist = g_StageSetup.ailists[i].list;
				g_BgChrs[count].aioffset = g_BgChrs[count].ailist;
				g_BgChrs[count].aireturnlist = -1;
				g_BgChrs[count].actiontype = ACT_NULL;
				count++;
			}

			i++;
		}

		// The final BG chr is for cutscene use
		g_BgChrs[count] = blankchr;
		g_BgChrs[count].chrnum = 4900;
		g_BgChrs[count].ailist = NULL;
		g_BgChrs[count].aioffset = NULL;
		g_BgChrs[count].aireturnlist = -1;
		g_BgChrs[count].actiontype = ACT_NULL;
		g_BgChrs[count].hidden2 |= CHRH2FLAG_TICKDURINGAUTOCUT;
		count++;

		// Sort them
		do {
			modified = false;

			for (i = 0; i < count - 1; i++) {
				if (g_BgChrs[i + 1].chrnum < g_BgChrs[i].chrnum) {
					tmp = g_BgChrs[i];
					g_BgChrs[i] = g_BgChrs[i + 1];
					g_BgChrs[i + 1] = tmp;

					modified = true;
				}
			}
		} while (modified);

		// Populate chr numbers
		for (i = 0; i < count; i++) {
			g_BgChrnums[i] = g_BgChrs[i].chrnum;
		}
	}

	g_TeamList = mempAlloc(0x210, MEMPOOL_STAGE);
	g_SquadronList = mempAlloc(0x220, MEMPOOL_STAGE);
}

void func0f00c230(void)
{
	// empty
}
