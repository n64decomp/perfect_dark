#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/chr/chrai.h"
#include "game/data/ailists.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_12dc0.h"
#include "library/library_16110.h"
#include "library/library_1a500.h"
#include "types.h"

s32 chraiGetListIdByList(u8 *ailist, bool *is_global)
{
	s32 i;

	if (g_StageSetup.ailists) {
		for (i = 0; g_StageSetup.ailists[i].list != NULL; i++) {
			if (g_StageSetup.ailists[i].list == ailist) {
				*is_global = false;
				return g_StageSetup.ailists[i].id;
			}
		}
	}

	for (i = 0; g_GlobalAilists[i].list != NULL; i++) {
		if (g_GlobalAilists[i].list == ailist) {
			*is_global = true;
			return g_GlobalAilists[i].id;
		}
	}

	return -1;
}

u32 chraiGoToLabel(u8 *ailist, u32 aioffset, u8 label)
{
	do {
		u8 *cmd = aioffset + ailist;
		u32 type = (cmd[0] << 8) + cmd[1];

		if (type == CMD_LABEL) {
			if (label == cmd[2]) {
				return aioffset;
			}
		} else if (type == CMD_END) {
			return 0;
		}

		aioffset += chraiGetCommandLength(ailist, aioffset);
	} while (true);
}

void chraiExecute(void *entity, s32 proptype)
{
	g_Vars.chrdata = NULL;
	g_Vars.truck = NULL;
	g_Vars.heli = NULL;
	g_Vars.hovercar = NULL;
	g_Vars.ailist = NULL;
	g_Vars.aioffset = 0;

	if (proptype == PROPTYPE_CHR) {
		g_Vars.chrdata = entity;
	} else if (proptype == PROPTYPE_OBJ) {
		struct defaultobj *obj = entity;

		if (obj->type == OBJTYPE_TRUCK) {
			g_Vars.truck = entity;
		} else if (obj->type == OBJTYPE_HELI) {
			g_Vars.heli = entity;
		} else if (obj->type == OBJTYPE_HOVERCAR || obj->type == OBJTYPE_CHOPPER) {
			g_Vars.hovercar = entity;
		}
	}

	if (g_Vars.chrdata) {
		g_Vars.ailist = g_Vars.chrdata->ailist;
		g_Vars.aioffset = g_Vars.chrdata->aioffset;
	} else if (g_Vars.truck) {
		g_Vars.ailist = g_Vars.truck->ailist;
		g_Vars.aioffset = g_Vars.truck->aioffset;
	} else if (g_Vars.heli) {
		g_Vars.ailist = g_Vars.heli->ailist;
		g_Vars.aioffset = g_Vars.heli->aioffset;
	} else if (g_Vars.hovercar) {
		g_Vars.ailist = g_Vars.hovercar->ailist;
		g_Vars.aioffset = g_Vars.hovercar->aioffset;
	}

	if (g_Vars.ailist) {
		if (g_Vars.chrdata) {
			chrAddTargetToBdlist(g_Vars.chrdata);
		}

		// Check if the ailist should be switched to a different one
		if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & CHRCFLAG_00200000)) {
			u32 animnum = animGetId(g_Vars.chrdata->animdata);
			if (g_Vars.chrdata->aishotlist >= 0
					&& g_Vars.chrdata->cshield <= 0
					&& (0 <= g_Vars.chrdata->damage || g_Vars.chrdata->gunprop != NULL)
					&& animnum != ANIM_SNIPING_0269
					&& animnum != ANIM_SNIPING_026B
					&& animnum != ANIM_SNIPING_026A) {
				// Set shot list
				g_Vars.chrdata->chrflags &= ~CHRCFLAG_00200000;
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aishotlist);
				g_Vars.aioffset = 0;
			}
		} else if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & CHRCFLAG_CONSIDER_DODGE)) {
			g_Vars.chrdata->chrflags &= ~CHRCFLAG_CONSIDER_DODGE;

			if (g_Vars.chrdata->aishootingatmelist >= 0
					&& ailistFindById(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
					&& g_Vars.chrdata->dodgerating > (u32)random() % 100
					&& chrHasFlag(g_Vars.chrdata, CHRFLAG1_00000400, BANK_1) == 0
					&& chrHasFlag(g_Vars.chrdata, CHRFLAG0_AIVSAI, BANK_0) == 0
					&& ailistFindById(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
					&& g_Vars.chrdata->actiontype != ACT_ATTACK
					&& g_Vars.chrdata->actiontype != ACT_ATTACKWALK
					&& g_Vars.chrdata->actiontype != ACT_DIE
					&& g_Vars.chrdata->actiontype != ACT_DEAD
					&& g_Vars.chrdata->actiontype != ACT_ARGH
					&& g_Vars.chrdata->actiontype != ACT_PREARGH
					&& g_Vars.chrdata->actiontype != ACT_ATTACKROLL) {
				// Set shooting at me list
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aishootingatmelist);
				g_Vars.aioffset = 0;
				g_Vars.chrdata->dodgerating = 0;
			} else {
				// Increase dodge rating
				g_Vars.chrdata->dodgerating *= 2;

				if (g_Vars.chrdata->dodgerating > g_Vars.chrdata->maxdodgerating) {
					g_Vars.chrdata->dodgerating = g_Vars.chrdata->maxdodgerating;
				}
			}
		} else if (g_Vars.chrdata
				&& g_Vars.chrdata->darkroomthing
				&& chrHasFlag(g_Vars.chrdata, CHRFLAG1_00000400, BANK_1) == 0
				&& ailistFindById(g_Vars.chrdata->aidarkroomlist) != g_Vars.chrdata->ailist
				&& g_Vars.stagenum != STAGE_CRASHSITE) {
			g_Vars.chrdata->darkroomthing = 0;

			if (g_Vars.chrdata->aidarkroomlist >= 0
					&& g_Vars.chrdata->actiontype != ACT_DIE
					&& g_Vars.chrdata->actiontype != ACT_DEAD
					&& g_Vars.chrdata->actiontype != ACT_ARGH) {
				// Set darkroom list
				chrSetFlags(g_Vars.chrdata, CHRFLAG1_00000400, BANK_1);
				chrSetFlags(g_Vars.chrdata, CHRFLAG1_10000000, BANK_1);
				g_Vars.chrdata->alertness = 0;
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aidarkroomlist);
				g_Vars.aioffset = 0;
			}
		} else {
			// empty
		}

		// Iterate and execute the ailist
		while (g_Vars.ailist) {
			u8 *cmd = g_Vars.aioffset + g_Vars.ailist;
			s32 type = (cmd[0] << 8) + cmd[1];

			if (type >= 0 && type <= 0x1e0) {
				if (g_CommandPointers[type]()) {
					break;
				}
			} else {
				// This is attempting to handle situations where the command
				// type is invalid by passing over them and continuing
				// execution. This would very likely result in a crash though.
				g_Vars.aioffset += chraiGetCommandLength(g_Vars.ailist, g_Vars.aioffset);
			}
		}
	}
}

u32 chraiGetCommandLength(u8 *ailist, u32 aioffset)
{
	u8 *cmd = aioffset + ailist;
	s32 type = (cmd[0] << 8) + cmd[1];

	if (type == CMD_PRINT) {
		u32 prop = aioffset + 2;

		while (ailist[prop] != 0) {
			++prop;
		}

		return (prop - aioffset) + 1;
	}

	if (type >= 0 && type < NUM_AICOMMANDS) {
		return g_CommandLengths[type];
	}

	return 1;
}
