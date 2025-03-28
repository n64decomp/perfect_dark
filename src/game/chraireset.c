#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chrai.h"
#include "game/chraireset.h"
#include "game/playerreset.h"
#include "game/body.h"
#include "game/setuputils.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

struct prop *g_DangerousProps[12];

void chrai_reset(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_DangerousProps); i++) {
		g_DangerousProps[i] = NULL;
	}

	g_StageFlags = 0;

	g_EnemyAccuracyScale = 1;
	g_PlayerDamageRxScale = 1;
	g_PlayerDamageTxScale = 1;
	g_AttackWalkDurationScale = 1;

	g_NumChrsSeenPlayerRecently2 = 0;
}

void chrai_load_bgchrs(void)
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
		g_BgChrs = memp_alloc(ALIGN16(g_NumBgChrs * sizeof(struct chrdata)), MEMPOOL_STAGE);
		g_BgChrnums = memp_alloc(ALIGN16(g_NumBgChrs * sizeof(s16)), MEMPOOL_STAGE);

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
				g_BgChrs[count].aioffset = 0;
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
		g_BgChrs[count].aioffset = 0;
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

	g_TeamList = memp_alloc((MAX_CHRSPERTEAM + 1) * MAX_TEAMS * sizeof(s16), MEMPOOL_STAGE);
	g_SquadronList = memp_alloc((MAX_CHRSPERSQUADRON + 1) * MAX_SQUADRONS * sizeof(s16), MEMPOOL_STAGE);
}

void chrai_load_ailist_models(void)
{
	u8 *cmd = g_StageSetup.ailists[0].list;
	s32 i = 0;
	u16 id;

	if (!cmd) {
		return;
	}

	do {
		while (true) {
			if (cmd[0] == AICMD_END) {
				break;
			}

			switch (cmd[0]) {
			case AICMD_DROPITEM:
				id = cmd[3] | (cmd[2] << 8);
				if (setup_load_modeldef(id));
				break;
			case AICMD_SPAWNCHRATPAD:
				body_load_modeldef(cmd[2]);
				if ((s8)cmd[3] >= 0 && body_load_modeldef((s8)cmd[3]));
				break;
			case AICMD_SPAWNCHRATCHR:
				body_load_modeldef(cmd[2]);
				if ((s8)cmd[3] >= 0 && body_load_modeldef((s8)cmd[3]));
				break;
			case AICMD_EQUIPWEAPON:
				setup_load_modeldef(cmd[3] | (cmd[2] << 8));
				if (modelmgr_load_projectile_modeldefs(cmd[4]));
				break;
			case AICMD_EQUIPHAT:
				setup_load_modeldef(cmd[3] | (cmd[2] << 8));
				break;
			}

			cmd += chrai_get_command_length(cmd, 0);
		}

		i++;
		cmd = g_StageSetup.ailists[i].list;
	} while (cmd);
}

void chrai_load_projectile_models(void)
{
	// empty
}
