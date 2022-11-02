#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "game/atan2f.h"
#include "game/bg.h"
#include "game/bondgun.h"
#include "game/bondmove.h"
#include "game/bot.h"
#include "game/cheats.h"
#include "game/chr.h"
#include "game/chraction.h"
#include "game/chrai.h"
#include "game/chraicommands.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/env.h"
#include "game/explosions.h"
#include "game/game_0b0fd0.h"
#include "game/gamefile.h"
#include "game/hudmsg.h"
#include "game/inv.h"
#include "game/lang.h"
#include "game/lv.h"
#include "game/modelmgr.h"
#include "game/mpstats.h"
#include "game/music.h"
#include "game/objectives.h"
#include "game/options.h"
#include "game/pad.h"
#include "game/player.h"
#include "game/playermgr.h"
#include "game/playerreset.h"
#include "game/prop.h"
#include "game/propobj.h"
#include "game/propsnd.h"
#include "game/setuputils.h"
#include "game/smoke.h"
#include "game/stagetable.h"
#include "game/title.h"
#include "game/training.h"
#include "game/weather.h"
#include "lib/ailist.h"
#include "lib/anim.h"
#include "lib/lib_317f0.h"
#include "lib/libc/ll.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/mtx.h"
#include "lib/music.h"
#include "lib/rng.h"
#include "lib/snd.h"
#include "types.h"

u8 *aiTick(u8 *ptr);

void chraiExecute(void *entity, s32 proptype)
{
	g_Vars.chrdata = NULL;
	g_Vars.hovercar = NULL;
	g_Vars.ailist = NULL;
	g_Vars.aioffset = NULL;

	if (proptype == PROPTYPE_CHR) {
		g_Vars.chrdata = entity;
	} else if (proptype == PROPTYPE_OBJ) {
		struct defaultobj *obj = entity;

		if (obj->type == OBJTYPE_HOVERCAR || obj->type == OBJTYPE_CHOPPER) {
			g_Vars.hovercar = entity;
		}
	}

	if (g_Vars.chrdata) {
		g_Vars.ailist = g_Vars.chrdata->ailist;
		g_Vars.aioffset = g_Vars.chrdata->aioffset;
	} else if (g_Vars.hovercar) {
		g_Vars.ailist = g_Vars.hovercar->ailist;
		g_Vars.aioffset = g_Vars.hovercar->aioffset;
	}

	if (g_Vars.ailist) {
		if (g_Vars.chrdata) {
			chrAddTargetToBdlist(g_Vars.chrdata);
		}

		// Check if the ailist should be switched to a different one
		if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & CHRCFLAG_TRIGGERSHOTLIST)) {
			u32 animnum = modelGetAnimNum(g_Vars.chrdata->model);
			if (g_Vars.chrdata->aishotlist >= 0
					&& g_Vars.chrdata->cshield <= 0
					&& (0 <= g_Vars.chrdata->damage || g_Vars.chrdata->gunprop != NULL)
					&& animnum != ANIM_SNIPING_GETDOWN
					&& animnum != ANIM_SNIPING_GETUP
					&& animnum != ANIM_SNIPING_ONGROUND) {
				// Set shot list
				g_Vars.chrdata->chrflags &= ~CHRCFLAG_TRIGGERSHOTLIST;
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aishotlist);
				g_Vars.aioffset = g_Vars.ailist;
			}
		} else if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & CHRCFLAG_CONSIDER_DODGE)) {
			g_Vars.chrdata->chrflags &= ~CHRCFLAG_CONSIDER_DODGE;

			if (g_Vars.chrdata->aishootingatmelist >= 0
					&& ailistFindById(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
					&& g_Vars.chrdata->dodgerating > (u32)random() % 100
					&& chrHasFlag(g_Vars.chrdata, CHRFLAG1_INDARKROOM, BANK_1) == 0
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
				g_Vars.aioffset = g_Vars.ailist;
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
				&& chrHasFlag(g_Vars.chrdata, CHRFLAG1_INDARKROOM, BANK_1) == 0
				&& ailistFindById(g_Vars.chrdata->aidarkroomlist) != g_Vars.chrdata->ailist
				&& g_Vars.stagenum != STAGE_CRASHSITE) {
			g_Vars.chrdata->darkroomthing = 0;

			if (g_Vars.chrdata->aidarkroomlist >= 0
					&& g_Vars.chrdata->actiontype != ACT_DIE
					&& g_Vars.chrdata->actiontype != ACT_DEAD
					&& g_Vars.chrdata->actiontype != ACT_ARGH) {
				// Set darkroom list
				chrSetFlags(g_Vars.chrdata, CHRFLAG1_INDARKROOM, BANK_1);
				chrSetFlags(g_Vars.chrdata, CHRFLAG1_SEARCHSAMEROOM, BANK_1);
				g_Vars.chrdata->alertness = 0;
				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aidarkroomlist);
				g_Vars.aioffset = g_Vars.ailist;
			}
		} else {
			// empty
		}

		// Iterate and execute the ailist
		{
			u8 *cmd = g_Vars.aioffset;

			if (cmd) {
				cmd = aiTick(cmd);

				if (g_Vars.chrdata) {
					g_Vars.chrdata->ailist = g_Vars.ailist;
					g_Vars.chrdata->aioffset = cmd;
				} else if (g_Vars.hovercar) {
					g_Vars.hovercar->ailist = g_Vars.ailist;
					g_Vars.hovercar->aioffset = cmd;
				}
			}
		}
	}
}
