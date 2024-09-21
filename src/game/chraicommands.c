#include <ultra64.h>
#include "../lib/naudio/n_sndp.h"
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/chrai.h"
#include "game/chraicommands.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/playerreset.h"
#include "game/title.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/setuputils.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/atan2f.h"
#include "game/bondgun.h"
#include "game/gset.h"
#include "game/modelmgr.h"
#include "game/player.h"
#include "game/hudmsg.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/explosions.h"
#include "game/smoke.h"
#include "game/weather.h"
#include "game/bg.h"
#include "game/stagetable.h"
#include "game/env.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/training.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/pad.h"
#include "game/options.h"
#include "game/propobj.h"
#include "game/mpstats.h"
#include "bss.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/music.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/ailist.h"
#include "lib/anim.h"
#include "lib/lib_317f0.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

/**
 * @cmd 0000
 */
bool ai_go_to_next(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	osSyncPrintf(" (%d)\n", cmd[2]);

	return false;
}

/**
 * @cmd 0001
 */
bool ai_go_to_first(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, 0, cmd[2]);
	osSyncPrintf(" (%d)\n", cmd[2]);

	return false;
}

/**
 * @cmd 0002
 */
bool ai_label(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 0003
 */
bool ai_yield(void)
{
	g_Vars.aioffset += 2;

	if (g_Vars.chrdata) {
		g_Vars.chrdata->ailist = g_Vars.ailist;
		g_Vars.chrdata->aioffset = g_Vars.aioffset;
	} else if (g_Vars.truck) {
		g_Vars.truck->ailist = g_Vars.ailist;
		g_Vars.truck->aioffset = g_Vars.aioffset;
	} else if (g_Vars.heli) {
		g_Vars.heli->ailist = g_Vars.ailist;
		g_Vars.heli->aioffset = g_Vars.aioffset;
	} else if (g_Vars.hovercar) {
		g_Vars.hovercar->ailist = g_Vars.ailist;
		g_Vars.hovercar->aioffset = g_Vars.aioffset;
	}

	return true;
}

/**
 * @cmd 0005
 */
bool ai_set_list(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 ailistid = cmd[4] | (cmd[3] << 8);
	u8 *ailist = ailist_find_by_id(ailistid & 0xffff);

	struct chrdata *chr = g_Vars.chrdata;

	if ((cmd[2] & 0xff) == CHR_SELF) {
		g_Vars.ailist = ailist;
		g_Vars.aioffset = 0;
	} else {
		chr = chr_find_by_id(chr, cmd[2]);

		if (chr) {
			chr->ailist = ailist;
			chr->aioffset = 0;
			chr->sleep = 0;
		}

		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0006
 */
bool ai_set_return_list(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 ailistid = cmd[4] | (cmd[3] << 8);
	struct chrdata *chr;

	if (g_Vars.chrdata) {
		if (cmd[2] == CHR_SELF) {
			g_Vars.chrdata->aireturnlist = ailistid;
		} else {
			chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

			if (chr) {
				chr->aireturnlist = ailistid;
			}
		}
	} else if (g_Vars.truck) {
		g_Vars.truck->aireturnlist = ailistid;
	} else if (g_Vars.heli) {
		g_Vars.heli->aireturnlist = ailistid;
	} else if (g_Vars.hovercar) {
		g_Vars.hovercar->aireturnlist = ailistid;
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 0007
 */
bool ai_set_shot_list(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 ailistid = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata) {
		g_Vars.chrdata->aishotlist = ailistid;
	} else if (g_Vars.truck) {
		osSyncPrintf("set shot list(void) doesn't work for g_Vars.CommandInfo.truck!\n");
	} else if (g_Vars.heli) {
		osSyncPrintf("set shot list(void) doesn't work for g_Vars.CommandInfo.heli!\n");
	} else if (g_Vars.hovercar) {
		osSyncPrintf("set shot list(void) doesn't work for g_Vars.CommandInfo.hovercar!\n");
	}

	g_Vars.aioffset += 4;

	return false;
}

const char var7f1a9524[] = "BOND IN ROOM \n";
const char var7f1a9534[] = "bond not in room \n";
const char var7f1a9548[] = "aTimer%s%s: %f\n";
const char var7f1a9558[] = "";
const char var7f1a955c[] = "";
const char var7f1a9560[] = "bTimer:%s%s %f\n";
const char var7f1a9570[] = "";
const char var7f1a9574[] = "";
const char var7f1a9578[] = "ai_ifbondintank: tank code has been removed.\n";
const char var7f1a95a8[] = "AI_BONDENABLECONTROL\n";
const char var7f1a95c0[] = "ai(void) enery tune on (%d, %d, %d)\n";
const char var7f1a95e8[] = "ai(void) enery tune off (%d)\n";
const char var7f1a9608[] = "%s%sAI_PRINT(void) height = %f ptop =  %f \n\n";
const char var7f1a9638[] = "";
const char var7f1a963c[] = "";
const char var7f1a9640[] = "Preset character = %d, my target = %d \n";
const char var7f1a9668[] = "characters target is %d \n";
const char var7f1a9684[] = "(DGD)chrai.c(void) aiIfChrsTargetIsChr does not support CHR_BOND as chr1!\n";
const char var7f1a96d0[] = "(DGD)chrai.c(void) aiIfChrsTargetIsChr does not support CHR_BOND as chr1!\n";
const char var7f1a971c[] = "DGD(void) (chrai.c) WARNING! attempt to use invalid CHR_PRESET1 - defaulting to JO\n";
const char var7f1a9770[] = "RISK CHECK = %d \n";
const char var7f1a9784[] = "aiIfOpportunityFireJumpF() called with no botdata!\n";
const char var7f1a97b8[] = "TARGET %d PASSED THE DISTANCE 2 TESTS \n";
const char var7f1a97e0[] = "%d I NOTICE THE TARGET %d\n";
const char var7f1a97fc[] = "%d I NOTICE THE TARGET %d\n";
const char var7f1a9818[] = "%d OPPORTUNITY FIRE A CHARACTER = %d \n";
const char var7f1a9840[] = "%d  CANNOT OPPORTUNITY FIRE A TARGET \n";
const char var7f1a9868[] = " RISK CHECK = %d \n";
const char var7f1a987c[] = "dist = %d \n";
const char var7f1a9888[] = "USING VOICE NUMBER %d \n";
const char var7f1a98a0[] = "SETORDERS COMMAND  \n";
const char var7f1a98b8[] = "SQUADRON MEMBER CHR NUMBER = %d \n";
const char var7f1a98dc[] = "DOING DIST CHECK \n";
const char var7f1a98f0[] = "%d SYNCHED WITH A CHARACTER %d \n";
const char var7f1a9914[] = "synched = %d \n";
const char var7f1a9924[] = "LEADER'S GOING TO COVER \n";
const char var7f1a9940[] = "LEADER IS BREAKING COVER \n";
const char var7f1a995c[] = " I AM SAFE TO BREAK COVER \n";
const char var7f1a9978[] = "not safe to break cover \n";
const char var7f1a9994[] = "LEADER IS COVER SEEN \n";
const char var7f1a99ac[] = "LEADER IS FLANKING LEFT \n";
const char var7f1a99c8[] = "LEADER IS FLANKING RIGHT \n";
const char var7f1a99e4[] = "LEADER IS DODGING \n";
const char var7f1a99f8[] = "LEADER IS THROWING GRENADE \n";
const char var7f1a9a18[] = "LEADER HAS SEEN FROM WAIT \n";
const char var7f1a9a34[] = "UNKNOWN LEADER ACTION \n";
const char var7f1a9a4c[] = "ORDERS CARRIED OUT  ";
const char var7f1a9a64[] = "WITHDRAWING!!!!!!!!!!!\n";
const char var7f1a9a7c[] = "CHECKING MY ORDERS  ";
const char var7f1a9a94[] = "ACTING ON MY ORDERS  ";
const char var7f1a9aac[] = "DOING DIST CHECK VS CHAR %d\n";
const char var7f1a9acc[] = "I'm just carrying out my ORDERS \n";
const char var7f1a9af0[] = "SQUAD IS DOING THAT ACTION\n";
const char var7f1a9b0c[] = "SQUAD NOT DOING ACTION\n";
const char var7f1a9b24[] = "g_Vars.CommandInfo.chrdata ->soundtimer = %d, g_Vars.CommandInfo.chrdata->talkgap = %d , soundgap = %d\n";
const char var7f1a9b8c[] = "RESETTING THE LISTENING \n";
const char var7f1a9ba8[] = "couldn't go to cover from danger !\n";
const char var7f1a9bcc[] = "couldn't find cover from danger !\n";
const char var7f1a9bf0[] = "Randnum = %d,    Alarmrandnum = %d \n";
const char var7f1a9c18[] = "IVE FOUND MY PAD %d \n";

/**
 * @cmd 01c1
 */
bool ai_set_punch_dodge_list(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 ailistid = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata) {
		g_Vars.chrdata->aipunchdodgelist = ailistid;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01c2
 */
bool ai_set_shooting_at_me_list(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 ailistid = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata) {
		g_Vars.chrdata->aishootingatmelist = ailistid;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01c3
 */
bool ai_set_dark_room_list(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 ailistid = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata) {
		g_Vars.chrdata->aidarkroomlist = ailistid;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01c4
 */
bool ai_set_player_dead_list(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 ailistid = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata) {
		g_Vars.chrdata->aiplayerdeadlist = ailistid;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0008
 */
bool ai_return(void)
{
	u8 *ailist = NULL;

	if (g_Vars.chrdata) {
		ailist = ailist_find_by_id(g_Vars.chrdata->aireturnlist);
	} else if (g_Vars.truck) {
		ailist = ailist_find_by_id(g_Vars.truck->aireturnlist);
	} else if (g_Vars.heli) {
		ailist = ailist_find_by_id(g_Vars.heli->aireturnlist);
	} else if (g_Vars.hovercar) {
		ailist = ailist_find_by_id(g_Vars.hovercar->aireturnlist);
	}

	g_Vars.ailist = ailist;
	g_Vars.aioffset = 0;

	return false;
}

/**
 * @cmd 0004
 */
bool ai_end_list(void)
{
	s32 ailistid;
	bool is_global;
	ailistid = chrai_get_list_id_by_list(g_Vars.ailist, &is_global);

	return true;
}

/**
 * @cmd 0009
 */
bool ai_stop(void)
{
	if (g_Vars.chrdata) {
		chr_try_stop(g_Vars.chrdata);
	} else if (g_Vars.hovercar) {
		chopper_stop(g_Vars.hovercar);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 000a
 */
bool ai_kneel(void)
{
	chr_try_kneel(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 000b
 */
bool ai_chr_do_animation(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 anim_id = cmd[3] | (cmd[2] << 8);
	s32 startframe = cmd[5] | (cmd[4] << 8);
	s32 endframe = cmd[7] | (cmd[6] << 8);
	struct chrdata *chr = NULL;
	f32 fstartframe;
	f32 fendframe;

	if (g_Vars.chrdata) {
		chr = chr_find_by_id(g_Vars.chrdata, cmd[10]);
	}

	if (startframe == 0xffff) {
		fstartframe = 0;
	} else if (startframe == 0xfffe) {
		fstartframe = anim_get_num_frames(anim_id) - 1;
	} else {
		fstartframe = startframe;
	}

	if (endframe == 0xffff) {
		fendframe = -1.0f;
	} else {
		fendframe = endframe;
	}

	if (chr && chr->model) {
		f32 speed = 1.0f / (s32)cmd[11];

		if (g_Vars.in_cutscene) {
			if (startframe != 0xfffe) {
#if PAL
				fstartframe += var8009e388pf * speed;
#else
				fstartframe += g_CutsceneFrameOverrun240 * speed * 0.25f;
#endif
			}

			chr->prop->propupdate240 = 0;
		}

		chr_try_start_anim(chr, anim_id, fstartframe, fendframe, cmd[8], cmd[9], speed);

		if (startframe == 0xfffe) {
			chr_update_anim(chr, 1, true);

			if (chr->prop->type == PROPTYPE_PLAYER) {
				u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
				struct player *player = g_Vars.players[playernum];
				player->vv_ground = chr->ground;
				player->vv_manground = chr->ground;
			}
		}
	}

	g_Vars.aioffset += 12;

	return false;
}

/**
 * @cmd 000c
 */
bool ai_if_idle(void)
{
	if (g_Vars.chrdata->actiontype == ACT_ANIM) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

bool func0f04e418(void)
{
	return false;
}

/**
 * @cmd 000d
 */
bool ai_be_surprised_one_hand(void)
{
	chr_try_surprised_one_hand(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 000e
 */
bool ai_be_surprised_look_around(void)
{
	chr_try_surprised_look_around(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0032
 */
bool ai_if_stopped(void)
{
	if (chr_is_stopped(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0033
 */
bool ai_if_chr_dead(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if ((!chr || !chr->prop || chr->prop->type != PROPTYPE_PLAYER) && (!chr || !chr->model || chr_is_dead(chr))) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0034
 */
bool ai_if_chr_death_animation_finished(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	bool pass;

	if (!chr || !chr->prop) {
		pass = true;
	} else {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
			pass = g_Vars.players[playernum]->isdead;
		} else {
			pass = (chr->actiontype == ACT_DEAD);
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 017b
 */
bool ai_if_chr_knocked_out(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if ((!chr || !chr->prop || chr->prop->type != PROPTYPE_PLAYER) &&
			(!chr || !chr->model || chr->actiontype == ACT_DRUGGEDKO || chr->actiontype == ACT_DRUGGEDDROP || chr->actiontype == ACT_DRUGGEDCOMINGUP)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0035
 */
bool ai_if_can_see_target(void)
{
	if (chr_check_can_see_target(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 000f
 */
bool ai_try_sidestep(void)
{
	if (chr_try_sidestep(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0010
 */
bool ai_try_jump_out(void)
{
	if (chr_try_jump_out(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0011
 */
bool ai_try_run_sideways(void)
{
	if (chr_try_run_sideways(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0012
 */
bool ai_try_attack_walk(void)
{
	if (chr_try_attack_walk(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0013
 */
bool ai_try_attack_run(void)
{
	if (chr_try_attack_run(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0014
 */
bool ai_try_attack_roll(void)
{
	if (chr_try_attack_roll(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0015
 */
bool ai_try_attack_stand(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chr_try_attack_stand(g_Vars.chrdata, thingtype, thingid)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 0016
 */
bool ai_try_attack_kneel(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chr_try_attack_kneel(g_Vars.chrdata, thingtype, thingid)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 01ba
 */
bool ai_try_attack_lie(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chr_try_attack_lie(g_Vars.chrdata, thingtype, thingid)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 00f0
 */
bool ai00f0(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->actiontype == ACT_ATTACK &&
			!g_Vars.chrdata->act_attack.reaim &&
			g_Vars.chrdata->act_attack.flags & ATTACKFLAG_DONTTURN) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 00f1
 */
bool ai_if_attacking(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->actiontype == ACT_ATTACK) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0017
 */
bool ai_try_modify_attack(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if ((g_Vars.chrdata && chr_try_modify_attack(g_Vars.chrdata, thingtype, thingid)) ||
			(g_Vars.hovercar && chopper_attack(g_Vars.hovercar))) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 0018
 */
bool ai_face_entity(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chr_face_entity(g_Vars.chrdata, thingtype, thingid)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 0019
 */
bool ai0019(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	struct coord pos = {0, 0, 0};

	if (chr && chr->prop) {
		f32 damage = gset_get_damage((struct gset *)&cmd[4]);
		chr_damage_by_general(chr, damage, &pos, (struct gset *)&cmd[4], NULL, (s8)cmd[3]);
	}

	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 001a
 */
bool ai_chr_damage_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr1 = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	struct chrdata *chr2 = chr_find_by_id(g_Vars.chrdata, cmd[3]);

	if (chr1 && chr2 && chr1->prop && chr2->prop) {
		struct prop *prop = chr_get_held_usable_prop(chr1, HAND_RIGHT);
		f32 damage;
		struct coord vector = {0, 0, 0};
		struct weaponobj *weapon;

		if (!prop) {
			prop = chr_get_held_usable_prop(chr1, HAND_LEFT);
		}

		if (prop) {
			vector.x = chr2->prop->pos.x - chr1->prop->pos.x;
			vector.y = chr2->prop->pos.y - chr1->prop->pos.y;
			vector.z = chr2->prop->pos.z - chr1->prop->pos.z;
			guNormalize(&vector.x, &vector.y, &vector.z);
			weapon = prop->weapon;
			damage = gset_get_damage(&weapon->gset);
			chr_damage_by_general(chr2, damage, &vector, &weapon->gset, chr1->prop, (s8)cmd[4]);
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 001b
 */
bool ai_consider_grenade_throw(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 value2 = cmd[5] | (cmd[4] << 8);
	u32 value1 = cmd[3] | (cmd[2] << 8);

	if (chr_consider_grenade_throw(g_Vars.chrdata, value1, value2)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 001c
 */
bool ai_drop_item(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 modelnum = cmd[3] | (cmd[2] << 8);

	if (chr_drop_item(g_Vars.chrdata, modelnum & 0xffff, cmd[4] & 0xff)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 0024
 */
bool ai_surrender(void)
{
	chr_try_surrender(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0025
 */
bool ai_fade_out(void)
{
	chr_fade_out(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0026
 */
bool ai_remove_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		chr->hidden |= 0x20;
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0027
 */
bool ai_try_start_alarm(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[3] | (cmd[2] << 8);

	if (chr_try_start_alarm(g_Vars.chrdata, pad_id)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0028
 */
bool ai_activate_alarm(void)
{
	alarm_activate();
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0029
 */
bool ai_deactivate_alarm(void)
{
	alarm_deactivate();
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 002a
 */
bool ai_try_run_from_target(void)
{
	if (chr_try_run_from_target(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 002b
 */
bool ai_try_jog_to_target_prop(void)
{
	if (chr_go_to_target(g_Vars.chrdata, GOPOSFLAG_JOG)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 002c
 */
bool ai_try_walk_to_target_prop(void)
{
	if (chr_go_to_target(g_Vars.chrdata, GOPOSFLAG_WALK)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 002d
 */
bool ai_try_run_to_target_prop(void)
{
	if (chr_go_to_target(g_Vars.chrdata, GOPOSFLAG_RUN)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 002e
 */
bool ai_try_go_to_cover_prop(void)
{
	if (chr_go_to_cover_prop(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist,g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 002f
 */
bool ai_try_jog_to_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_go_to_chr(g_Vars.chrdata, cmd[2], GOPOSFLAG_JOG)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0030
 */
bool ai_try_walk_to_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_go_to_chr(g_Vars.chrdata, cmd[2], GOPOSFLAG_WALK)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0031
 */
bool ai_try_run_to_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_go_to_chr(g_Vars.chrdata, cmd[2], GOPOSFLAG_RUN)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0036
 */
bool ai_random(void)
{
	g_Vars.chrdata->random = random() & 0xff;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0037
 */
bool ai_if_random_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((g_Vars.chrdata && g_Vars.chrdata->random < cmd[2]) ||
			(g_Vars.hovercar && ((u8)random()) < cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0038
 */
bool ai_if_random_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((g_Vars.chrdata && g_Vars.chrdata->random > cmd[2]) ||
			(g_Vars.hovercar && ((u8)random()) > cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 001d
 */
bool ai_jog_to_pad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad = cmd[3] | (cmd[2] << 8);

	chr_go_to_pad(g_Vars.chrdata, pad, GOPOSFLAG_JOG);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 001e
 */
bool ai_go_to_pad_preset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	switch (cmd[2]) {
	case 0:
		chr_go_to_pad(g_Vars.chrdata, g_Vars.chrdata->padpreset1, GOPOSFLAG_WALK);
		break;
	case 1:
		chr_go_to_pad(g_Vars.chrdata, g_Vars.chrdata->padpreset1, GOPOSFLAG_JOG);
		break;
	default:
		chr_go_to_pad(g_Vars.chrdata, g_Vars.chrdata->padpreset1, GOPOSFLAG_RUN);
		break;
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 001f
 */
bool ai_walk_to_pad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad = cmd[3] | (cmd[2] << 8);

	chr_go_to_pad(g_Vars.chrdata, pad, GOPOSFLAG_WALK);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0020
 */
bool ai_run_to_pad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad = cmd[3] | (cmd[2] << 8);

	chr_go_to_pad(g_Vars.chrdata, pad, GOPOSFLAG_RUN);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0021
 */
bool ai_set_path(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	chr_set_path(g_Vars.chrdata, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0022
 */
bool ai_start_patrol(void)
{
	chr_try_start_patrol(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0039
 */
bool ai_if_can_hear_alarm(void)
{
	if (chr_can_hear_alarm(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0023
 */
bool ai_if_patrolling(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->actiontype == ACT_PATROL
			|| (g_Vars.chrdata->actiontype == ACT_GOPOS && g_Vars.chrdata->act_gopos.flags & GOPOSFLAG_FORPATHSTART)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 003a
 */
bool ai_if_alarm_active(void)
{
	if (alarm_is_active()) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 003b
 */
bool ai_if_gas_active(void)
{
	if (gas_is_active()) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 003c
 */
bool ai_if_hears_target(void)
{
	if (chr_is_hearing_target(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 003d
 */
bool ai_if_saw_injury(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_saw_injury(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 003e
 */
bool ai_if_saw_death(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_saw_death(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 003f
 */
bool ai_if_los_to_target(void)
{
	if ((g_Vars.chrdata && chr_has_los_to_target(g_Vars.chrdata)) ||
			(g_Vars.hovercar && chopper_check_target_in_fov(g_Vars.hovercar, 64) && chopper_check_target_in_sight(g_Vars.hovercar))) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 017a
 */
bool ai_if_los_to_attack_target(void)
{
	if ((g_Vars.chrdata && g_Vars.chrdata->prop && chr_has_los_to_attack_target(g_Vars.chrdata, &g_Vars.chrdata->prop->pos, g_Vars.chrdata->prop->rooms, true))
			|| (g_Vars.hovercar && chopper_check_target_in_fov(g_Vars.hovercar, 64) && chopper_check_target_in_sight(g_Vars.hovercar))) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0040
 */
bool ai_if_target_nearly_in_sight(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 distance = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if (chr_is_target_nearly_in_sight(g_Vars.chrdata, distance)) {
		cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 0041
 */
bool ai_if_nearly_in_targets_sight(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 distance = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if (chr_is_nearly_in_targets_sight(g_Vars.chrdata, distance)) {
		cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 0042
 */
bool ai_set_pad_preset_to_pad_on_route_to_target(void)
{
	if (chr_set_pad_preset_to_pad_on_route_to_target(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0043
 */
bool ai_if_saw_target_recently(void)
{
	if (chr_saw_target_recently(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0044
 */
bool ai_if_heard_target_recently(void)
{
	if (chr_heard_target_recently(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0045
 */
bool ai_if_los_to_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr_has_los_to_pos(g_Vars.chrdata, &chr->prop->pos, chr->prop->rooms)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0046
 */
bool ai_if_never_been_on_screen(void)
{
	if ((g_Vars.chrdata->chrflags & CHRCFLAG_EVERONSCREEN) == 0) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0047
 */
bool ai_if_on_screen(void)
{
	if (g_Vars.chrdata->prop->flags & (PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0048
 */
bool ai_if_chr_in_on_screen_room(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	u8 pass = false;
	s32 i;

	if (chr && chr->prop) {
		for (i = 0; chr->prop->rooms[i] != -1; i++) {
			if (bg_room_is_onscreen(chr->prop->rooms[i])) {
				pass = true;
			}
		}
	}

	if (pass) {
		cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0049
 */
bool ai_if_room_is_on_screen(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[3] | (cmd[2] << 8);
	s32 room_id = chr_get_pad_room(g_Vars.chrdata, pad_id);

	if (room_id >= 0 && bg_room_is_onscreen(room_id)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 004a
 */
bool ai_if_target_aiming_at_me(void)
{
	if (chr_is_target_aiming_at_me(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 004b
 */
bool ai_if_near_miss(void)
{
	if (chr_reset_near_miss(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 004c
 */
bool ai_if_sees_suspicious_item(void)
{
	s16 *ptr;
	ubool pass = false;
	struct prop *prop;
	struct defaultobj *obj;
	s16 propnums[256];
	struct prop *chrprop = g_Vars.chrdata->prop;

	room_get_props(chrprop->rooms, &propnums[0], 256);

	ptr = &propnums[0];

	while (*ptr >= 0) {
		prop = &g_Vars.props[*ptr];
		obj = prop->obj;

		if (prop->type == PROPTYPE_WEAPON) {
			if ((obj->hidden & OBJHFLAG_SUSPICIOUS) && chr_has_los_to_prop(g_Vars.chrdata, prop)) {
				pass = true;
			}
		} else if (prop->type == PROPTYPE_OBJ) {
			if (((obj->hidden & OBJHFLAG_SUSPICIOUS) || !obj_is_healthy(obj))
					&& chr_has_los_to_prop(g_Vars.chrdata, prop)) {
				pass = true;
			}
		} else if (prop->type == PROPTYPE_EXPLOSION) {
			if (chr_has_los_to_prop(g_Vars.chrdata, prop)) {
				pass = true;
			}
		}

		ptr++;
	}

	if (pass) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 004e
 */
bool ai_if_check_fov_with_target(void)
{
	bool pass;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[4] == 0) {
		if (cmd[3]) {
			pass = chr_is_in_targets_fov_x(g_Vars.chrdata, cmd[2]);
		} else {
			pass = chr_is_vertical_angle_to_target_within(g_Vars.chrdata, cmd[2]);
		}
	} else {
		pass = g_Vars.chrdata->yvisang && chr_is_vertical_angle_to_target_within(g_Vars.chrdata, g_Vars.chrdata->yvisang) == 0;
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 004d
 */
bool ai_if_target_in_fov_left(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_get_angle_to_target(g_Vars.chrdata) < cmd[2] * BADDTOR(360) * (1.0f / 256.0f)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 004f
 */
bool ai_if_target_out_of_fov_left(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_get_angle_to_target(g_Vars.chrdata) > cmd[2] * BADDTOR(360) * (1.0f / 256.0f)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0050
 */
bool ai_if_target_in_fov(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_is_target_in_fov(g_Vars.chrdata, cmd[2], 0)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0051
 */
bool ai_if_target_out_of_fov(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (!chr_is_target_in_fov(g_Vars.chrdata, cmd[2], 0)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0052
 */
bool ai_if_distance_to_target_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) * (f32)10;

	if (chr_get_distance_to_target(g_Vars.chrdata) < distance) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0053
 */
bool ai_if_distance_to_target_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) * (f32)10;

	if (chr_get_distance_to_target(g_Vars.chrdata) > distance) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0054
 */
bool ai_if_chr_distance_to_pad_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

#if VERSION >= VERSION_NTSC_1_0
	s32 padnum = (cmd[6] | (cmd[5] << 8)) & 0xffff;
	f32 value = (cmd[4] | (cmd[3] << 8)) * 10.0f;
	s32 realpadnum = padnum;

	if (padnum == 9000) {
		realpadnum = (u16) g_Vars.chrdata->padpreset1;
	}

	if (chr && realpadnum < 9000 && chr_get_distance_to_pad(chr, realpadnum) < value) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}
#else
	u16 padnum = cmd[6] | (cmd[5] << 8);
	f32 value = (cmd[4] | (cmd[3] << 8)) * 10.0f;

	if (padnum == 9000) {
		padnum = g_Vars.chrdata->padpreset1;
	}

	if (chr && chr_get_distance_to_pad(chr, padnum) < value) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}
#endif

	return false;
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * @cmd 01df
 */
bool ai_if_chr_same_floor_distance_to_pad_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	u16 padnum = cmd[6] | (cmd[5] << 8);
	f32 distance = (cmd[4] | (cmd[3] << 8)) * 10.0f;
	s32 padnum2;

	if (padnum == 9000) {
		padnum = g_Vars.chrdata->padpreset1;
	}

	padnum2 = padnum;

	if (chr && chr_get_same_floor_distance_to_pad(chr, padnum2 & 0xffffffff) < distance) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}
#endif

/**
 * @cmd 0055
 */
bool ai_if_chr_distance_to_pad_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	u16 padnum = cmd[6] | (cmd[5] << 8);
	f32 distance = (cmd[4] | (cmd[3] << 8)) * 10.0f;

	if (padnum == 9000) {
		padnum = g_Vars.chrdata->padpreset1;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (chr && padnum < 9000 && chr_get_distance_to_pad(chr, padnum) > distance)
#else
	if (chr && chr_get_distance_to_pad(chr, padnum) > distance)
#endif
	{
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 0056
 */
bool ai_if_distance_to_chr_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 cutoff = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chr_get_distance_to_chr(g_Vars.chrdata, cmd[4]) < cutoff) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 0057
 */
bool ai_if_distance_to_chr_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 cutoff = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chr_get_distance_to_chr(g_Vars.chrdata, cmd[4]) > cutoff) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 0058
 */
bool ai0058(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chr_set_chr_preset_to_any_chr_near_self(g_Vars.chrdata, distance)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0059
 */
bool ai_if_distance_from_target_to_pad_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad = cmd[5] | (cmd[4] << 8);
	f32 value = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chr_get_distance_from_target_to_pad(g_Vars.chrdata, pad) < value) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 005a
 */
bool ai_if_distance_from_target_to_pad_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad = cmd[5] | (cmd[4] << 8);
	f32 value = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chr_get_distance_from_target_to_pad(g_Vars.chrdata, pad) > value) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 005b
 */
bool ai_if_chr_in_room(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	u16 pad_id = cmd[5] | (cmd[4] << 8);
	s32 room = chr_get_pad_room(g_Vars.chrdata, pad_id);

	if ((cmd[3] == 0 && room >= 0 && chr && chr->prop && chr->prop->rooms[0] == room)
			|| (cmd[3] == 1 && chr && chr->prop && chr->prop->rooms[0] == g_Vars.chrdata->roomtosearch)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
		return false;
	}

	if (cmd[3] == 2 && stage_get_index(g_Vars.stagenum) == STAGEINDEX_G5BUILDING) {
		s32 i;
		bool pass = false;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.players[i]->eyespy && g_Vars.players[i]->eyespy->prop
#if VERSION >= VERSION_NTSC_1_0
					&& chr_get_distance_to_pad(g_Vars.players[i]->eyespy->prop->chr, pad_id) < 150.0f
#else
					&& chr_get_distance_to_pad(g_Vars.players[i]->eyespy->prop->chr, 0x4d) < 150.0f
#endif
					) {
				pass = true;
			}
		}

		if (pass == true) {
			g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
		} else {
			g_Vars.aioffset += 7;
		}

		return false;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 005c
 */
bool ai_if_target_in_room(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct prop *prop = chr_get_target_prop(g_Vars.chrdata);
	u16 pad_id = cmd[3] | (cmd[2] << 8);
	s32 room_id = chr_get_pad_room(g_Vars.chrdata, pad_id);

	if (room_id >= 0 && prop && room_id == prop->rooms[0]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 005d
 */
bool ai_if_chr_has_object(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[3]);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	s32 hasprop = false;

	if (obj && obj->prop && chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		s32 prevplayernum = g_Vars.currentplayernum;
		set_current_player_num(playermgr_get_player_num_by_prop(chr->prop));
		hasprop = inv_has_prop(obj->prop);
		set_current_player_num(prevplayernum);
	}

	if (hasprop) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 005e
 */
bool ai_if_weapon_thrown(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (weapon_find_landed(cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 005f
 */
bool ai_if_weapon_thrown_on_object(void)
{
	struct bytelist *cmd = (struct bytelist *)(g_Vars.ailist + g_Vars.aioffset);
	struct defaultobj *obj = obj_find_by_tag_id(cmd->b3);
	bool pass = false;

	if (obj && obj->prop) {
		struct prop *prop = obj->prop->child;

		while (prop) {
			if (prop->type == PROPTYPE_WEAPON) {
				struct weaponobj *weapon = prop->weapon;

				if (weapon->weaponnum == cmd->b2) {
					pass = true;
				}
			}

			prop = prop->next;
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd->b4);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0060
 */
bool ai_if_chr_has_weapon_equipped(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	bool passes = false;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);

		if (bgun_get_weapon_num(HAND_RIGHT) == cmd[3]) {
			passes = true;
		}

		set_current_player_num(prevplayernum);
	}

	if (passes) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0061
 */
bool ai_if_gun_unclaimed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[3] == 0) {
		struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

		if (obj && obj->prop) {
			g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
		} else {
			g_Vars.aioffset += 5;
		}
	} else {
		struct weaponobj *weapon = g_Vars.chrdata->gunprop->weapon;

		if (weapon && weapon->base.prop) {
			weapon->base.flags |= OBJFLAG_FORCENOBOUNCE;
			g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
		} else {
			g_Vars.aioffset += 5;
		}
	}

	return false;
}

/**
 * @cmd 0062
 */
bool ai_if_object_healthy(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj_is_healthy(obj)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0063
 */
bool ai_if_chr_activated_object(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[3]);
	u32 stack[1];
	bool pass = false;

	if (obj && obj->prop) {
		if (cmd[2] == CHR_ANY) {
			if (obj->hidden & (OBJHFLAG_ACTIVATED_BY_BOND | OBJHFLAG_ACTIVATED_BY_COOP)) {
				pass = true;
				obj->hidden &= ~(OBJHFLAG_ACTIVATED_BY_BOND | OBJHFLAG_ACTIVATED_BY_COOP);
			}
		} else {
			struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

			if (chr && chr->prop) {
				if (chr->prop == g_Vars.bond->prop && (obj->hidden & OBJHFLAG_ACTIVATED_BY_BOND)) {
					pass = true;
					obj->hidden &= ~OBJHFLAG_ACTIVATED_BY_BOND;
				} else if (g_Vars.coopplayernum >= 0 && chr->prop == g_Vars.coop->prop && (obj->hidden & OBJHFLAG_ACTIVATED_BY_COOP)) {
					pass = true;
					obj->hidden &= ~OBJHFLAG_ACTIVATED_BY_COOP;
				}
			}
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0065
 */
bool ai_obj_interact(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		if (obj->prop->type == PROPTYPE_DOOR) {
			doors_activate(obj->prop, false);
		} else if (obj->prop->type == PROPTYPE_OBJ || obj->prop->type == PROPTYPE_WEAPON) {
			propobj_interact(obj->prop);
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0066
 */
bool ai_destroy_object(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj_get_destroyed_level(obj) == 0) {
		struct defaultobj *entity = obj->prop->obj;

		if (entity->modelnum == MODEL_ELVIS_SAUCER) {
			obj->flags = (obj->flags & ~OBJFLAG_FORCEMORTAL) | OBJFLAG_INVINCIBLE;
			explosion_create_simple(entity->prop, &entity->prop->pos, entity->prop->rooms, EXPLOSIONTYPE_LAPTOP, 0);
			smoke_create_at_prop(entity->prop, SMOKETYPE_UFO);
		} else {
			f32 damage = ((obj->maxdamage - obj->damage) + 1) / 250.0f;
			obj_damage(obj, damage, &obj->prop->pos, WEAPON_REMOTEMINE, -1);
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0067
 */
bool ai0067(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj->prop->parent && obj->prop->parent->type == PROPTYPE_CHR) {
		struct chrdata *chr = obj->prop->parent->chr;
		obj_set_dropped(obj->prop, DROPTYPE_SURRENDER);
		chr->hidden |= CHRHFLAG_DROPPINGITEM;
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0068
 */
bool ai_chr_drop_items(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		chr_drop_concealed_items(chr);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0069
 */
bool ai_chr_drop_weapon(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		u32 weaponnum;
		set_current_player_num(playernum);
		weaponnum = bgun_get_weapon_num(HAND_RIGHT);
		inv_remove_item_by_num(weaponnum);
		bgun_cycle_back();
		set_current_player_num(prevplayernum);
	} else if (chr && chr->prop) {
		if (chr->weapons_held[0]) {
			obj_set_dropped(chr->weapons_held[0], DROPTYPE_DEFAULT);
			chr->hidden |= CHRHFLAG_DROPPINGITEM;
		}

		if (chr->weapons_held[1]) {
			obj_set_dropped(chr->weapons_held[1], DROPTYPE_DEFAULT);
			chr->hidden |= CHRHFLAG_DROPPINGITEM;
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 006a
 */
bool ai_give_object_to_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[3]);

	if (obj && obj->prop && chr && chr->prop) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 something;
			u32 prevplayernum = g_Vars.currentplayernum;
			struct defaultobj *obj2 = obj->prop->obj;
			u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
			set_current_player_num(playernum);

#if VERSION >= VERSION_NTSC_1_0
			if (obj->prop->parent) {
				obj_detach(obj->prop);
				obj_free_embedment_or_projectile(obj->prop);
				prop_activate(obj->prop);
			}
#endif

			something = prop_pickup_by_player(obj->prop, 0);
			prop_execute_tick_operation(obj->prop, something);
			playernum = playermgr_get_player_num_by_prop(chr->prop);
			obj2->hidden = (playernum << 28) | (obj2->hidden & 0x0fffffff);
			set_current_player_num(prevplayernum);
		} else {
			if (obj->prop->parent) {
				obj_detach(obj->prop);
			} else {
				prop_deregister_rooms(obj->prop);
				prop_delist(obj->prop);
				prop_disable(obj->prop);
			}

			if (obj->type != OBJTYPE_WEAPON || chr_equip_weapon((struct weaponobj *) obj, chr) == 0) {
				prop_reparent(obj->prop, chr->prop);
			}
		}
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 006b
 */
bool ai_object_move_to_pad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);
	u16 padnum = cmd[4] | (cmd[3] << 8);
	Mtxf matrix;
	struct pad pad;
	RoomNum rooms[2];

	if (obj && obj->prop) {
		pad_unpack(padnum, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_ROOM, &pad);
		mtx00016d58(&matrix,
				0, 0, 0,
				-pad.look.x, -pad.look.y, -pad.look.z,
				pad.up.x, pad.up.y, pad.up.z);

		if (obj->model) {
			mtx00015f04(obj->model->scale, &matrix);
		}

		rooms[0] = pad.room;
		rooms[1] = -1;
		func0f06a730(obj, &pad.pos, &matrix, rooms, &pad.pos);
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 006c
 */
bool ai_open_door(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		if (!door_call_lift(obj->prop, false)) {
			struct doorobj *door = (struct doorobj *) obj;
			doors_request_mode(door, DOORMODE_OPENING);
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 006d
 */
bool ai_close_door(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		doors_request_mode(door, DOORMODE_CLOSING);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 006e
 */
bool ai_if_door_state(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);
	bool pass = false;

	if (obj && obj->prop && obj->type == OBJTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;

		if (door->mode == DOORMODE_IDLE) {
			if (door->frac <= 0) {
				pass = (cmd[3] & DOORSTATE_CLOSED) != 0;
			} else {
				pass = (cmd[3] & DOORSTATE_OPEN) != 0;
			}
		} else if (door->mode == DOORMODE_OPENING || door->mode == DOORMODE_WAITING) {
			pass = (cmd[3] & DOORSTATE_OPENING) != 0;
		} else if (door->mode == DOORMODE_CLOSING) {
			pass = (cmd[3] & DOORSTATE_CLOSING) != 0;
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 006f
 */
bool ai_if_object_is_door(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj->type == OBJTYPE_DOOR && (obj->hidden & 0x200)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0070
 */
bool ai_lock_door(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		u8 bits = cmd[3];
		door->keyflags = door->keyflags | bits;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0071
 */
bool ai_unlock_door(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		u8 bits = cmd[3];
		door->keyflags = door->keyflags & ~bits;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0072
 */
bool ai_if_door_locked(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);
	bool pass = false;

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		u32 bits = cmd[3];
		u32 keyflags = door->keyflags;

		if ((keyflags & bits) == bits) {
			pass = true;
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0073
 */
bool ai_if_objective_complete(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] < objective_get_count() &&
			objective_check(cmd[2]) == OBJECTIVE_COMPLETE &&
			objective_get_difficulty_bits(cmd[2]) & (1 << lv_get_difficulty())) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0074
 */
bool ai_if_objective_failed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] < objective_get_count() &&
			objective_check(cmd[2]) == OBJECTIVE_FAILED &&
			objective_get_difficulty_bits(cmd[2]) & (1 << lv_get_difficulty())) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0075
 */
bool ai0075(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (func0f04a4ec(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0076
 */
bool ai_set_pad_preset_to_target_quadrant(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_set_pad_preset_to_waypoint_within_target_quadrant(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 007d
 */
bool ai_if_num_arghs_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_get_num_arghs(g_Vars.chrdata) < cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 007e
 */
bool ai_if_num_arghs_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_get_num_arghs(g_Vars.chrdata) > cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 007f
 */
bool ai_if_num_close_arghs_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_get_num_close_arghs(g_Vars.chrdata) < cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0080
 */
bool ai_if_num_close_arghs_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_get_num_close_arghs(g_Vars.chrdata) > cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0081
 */
bool ai_if_chr_health_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = cmd[3] * 0.1f;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	u32 pass = false;

	if (chr && chr->prop) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 playernum = playermgr_get_player_num_by_prop(chr->prop);

			pass = (value > g_Vars.players[playernum]->bondhealth * 8.0f);
		} else {
			pass = (value > chr->maxdamage - chr->damage);
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0082
 */
bool ai_if_chr_health_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = cmd[3] * 0.1f;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	u32 pass = false;

	if (chr && chr->prop) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 playernum = playermgr_get_player_num_by_prop(chr->prop);

			pass = (value < g_Vars.players[playernum]->bondhealth * 8.0f);
		} else {
			pass = (value < chr->maxdamage - chr->damage);
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 010f
 */
bool ai_if_chr_shield_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = (cmd[4] | (cmd[3] << 8)) * 0.1f;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata,cmd[2]);

	if (chr && chr_get_shield(chr) < value) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 6;
	}

	return false;
}

/**
 * @cmd 0110
 */
bool ai_if_chr_shield_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = (cmd[4] | (cmd[3] << 8)) * 0.1f;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata,cmd[2]);

	if (chr && chr_get_shield(chr) > value) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 6;
	}

	return false;
}

/**
 * @cmd 0083
 */
bool ai_if_injured(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_JUST_INJURED)) {
		chr->chrflags &= ~CHRCFLAG_JUST_INJURED;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 4;
	}

	return false;
}

/**
 * @cmd 0168
 */
bool ai_if_shield_damaged(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_SHIELDDAMAGED)) {
		chr->chrflags &= ~CHRCFLAG_SHIELDDAMAGED;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 4;
	}

	return false;
}

/**
 * @cmd 0077
 */
bool ai_if_difficulty_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (lv_get_difficulty() < cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0078
 */
bool ai_if_difficulty_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (lv_get_difficulty() > cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0079
 */
bool ai_if_stage_timer_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 target = (f32)(cmd[3] | (cmd[2] << 8));
	f32 time = lv_get_stage_time_in_seconds();

	if (time < target) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 007a
 */
bool ai_if_stage_timer_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 target = (f32)(cmd[3] | (cmd[2] << 8));
	f32 time = lv_get_stage_time_in_seconds();

	if (time > target) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 007b
 */
bool ai_if_stage_id_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] > main_get_stage_num()) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 007c
 */
bool ai_if_stage_id_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (main_get_stage_num() > cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0084
 */
bool ai_set_morale(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.chrdata->morale = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0085
 */
bool ai_add_morale(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	increment_byte(&g_Vars.chrdata->morale, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0086
 */
bool ai_chr_add_morale(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[3]);
	increment_byte(&chr->morale, cmd[2]);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0087
 */
bool ai_subtract_morale(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	decrement_byte(&g_Vars.chrdata->morale, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0088
 */
bool ai_if_morale_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->morale < cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0089
 */
bool ai_if_morale_less_than_random(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->morale < g_Vars.chrdata->random) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 008a
 */
bool ai_set_alertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.chrdata->alertness = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 008b
 */
bool ai_add_alertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	increment_byte(&g_Vars.chrdata->alertness, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 008c
 */
bool ai_chr_add_alertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[3]);

	if (chr && chr->prop) {
		increment_byte(&chr->alertness, cmd[2]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 008d
 */
bool ai_subtract_alertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	decrement_byte(&g_Vars.chrdata->alertness, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 008e
 */
bool ai_if_alertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((g_Vars.chrdata->alertness < cmd[2] && cmd[3] == 0) ||
			(cmd[2] < g_Vars.chrdata->alertness && cmd[3] == 1)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 008f
 */
bool ai_if_chr_alertness_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[3]);

	if (chr && chr->alertness < cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0090
 */
bool ai_if_alertness_less_than_random(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->alertness < g_Vars.chrdata->random) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0092
 */
bool ai_set_hear_distance(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) / 1000.0f;
	g_Vars.chrdata->hearingscale = distance;

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0093
 */
bool ai_set_view_distance(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (!cheat_is_active(CHEAT_PERFECTDARKNESS)) {
		g_Vars.chrdata->visionrange = cmd[2];
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0094
 */
bool ai_set_grenade_probability(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.chrdata->grenadeprob = cmd[2];
	g_Vars.aioffset += + 3;

	return false;
}

/**
 * @cmd 0095
 */
bool ai_set_chr_num(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	chr_set_chrnum(g_Vars.chrdata, cmd[2]);
	g_Vars.chrdata->chrnum = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0096
 */
bool ai_set_max_damage(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 maxdamage = (cmd[4] | (cmd[3] << 8)) * 0.1f;

	if (g_Vars.hovercar) {
		chopper_set_max_damage(g_Vars.hovercar, maxdamage);
	} else {
		struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

		if (chr && chr->prop && !chr_is_dead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP) {
			chr_set_max_damage(chr, maxdamage);
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 0097
 */
bool ai_add_health()
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 amount = (cmd[3] | (cmd[2] << 8)) * 0.1f;

	chr_add_health(g_Vars.chrdata, amount);

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 010e
 */
bool ai_set_shield(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 amount = (cmd[3] | (cmd[2] << 8)) * 0.1f;

	if (cheat_is_active(CHEAT_ENEMYSHIELDS)) {
		amount = amount < 8 ? 8 : amount;
	}

	chr_set_shield(g_Vars.chrdata, amount);

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0098
 */
bool ai_set_reaction_speed(void)
{
	s8 *cmd = (s8 *)g_Vars.ailist + g_Vars.aioffset;

	g_Vars.chrdata->speedrating = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0099
 */
bool ai_set_recovery_speed(void)
{
	s8 *cmd = (s8 *)g_Vars.ailist + g_Vars.aioffset;

	g_Vars.chrdata->arghrating = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 009a
 */
bool ai_set_accuracy(void)
{
	s8 *cmd = (s8 *)g_Vars.ailist + g_Vars.aioffset;

	g_Vars.chrdata->accuracyrating = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01c6
 */
bool ai_set_dodge_rating(void)
{
	s8 *cmd = (s8 *)g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] == 0) {
		g_Vars.chrdata->dodgerating = cmd[3];
	} else if (cmd[2] == 1) {
		g_Vars.chrdata->maxdodgerating = cmd[3];
	} else {
		g_Vars.chrdata->dodgerating = cmd[3];
		g_Vars.chrdata->maxdodgerating = cmd[3];
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01c7
 */
bool ai_set_unarmed_dodge_rating(void)
{
	s8 *cmd = (s8 *)g_Vars.ailist + g_Vars.aioffset;

	g_Vars.chrdata->unarmeddodgerating = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 009b
 */
bool ai_set_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chr_set_flags(g_Vars.chrdata, flags, cmd[6]);

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 009c
 */
bool ai_unset_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chr_unset_flags(g_Vars.chrdata, flags, cmd[6]);

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 009d
 */
bool ai_if_has_flag(void)
{
	bool result;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	result = chr_has_flag(g_Vars.chrdata, flags, cmd[7]);

	if (cmd[6] == 0) {
		result = !result;
	}

	if (result) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[8]);
	} else {
		g_Vars.aioffset += 9;
	}

	return false;
}

/**
 * @cmd 009e
 */
bool ai_chr_set_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	chr_set_flags_by_id(g_Vars.chrdata, cmd[2], flags, cmd[7]);
	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 009f
 */
bool ai_chr_unset_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	chr_unset_flags_by_id(g_Vars.chrdata, cmd[2], flags, cmd[7]);
	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 00a0
 */
bool ai_if_chr_has_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);

	if (chr_has_flag_by_id(g_Vars.chrdata, cmd[2], flags, cmd[7])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[8]);
	} else {
		g_Vars.aioffset += 9;
	}

	return false;
}

/**
 * @cmd 00a1
 */
bool ai_set_stage_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chr_set_stage_flag(g_Vars.chrdata, flags);
	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00a2
 */
bool ai_unset_stage_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chr_unset_stage_flag(g_Vars.chrdata, flags);
	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00a3
 */
bool ai_if_stage_flag_eq(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if ((chr_has_stage_flag(g_Vars.chrdata, flags) && cmd[6] == 1) ||
			(!chr_has_stage_flag(g_Vars.chrdata, flags) && cmd[6] == 0)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 00a4
 */
bool ai_set_chrflag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	g_Vars.chrdata->chrflags |= flags;
	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00a5
 */
bool ai_unset_chrflag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	g_Vars.chrdata->chrflags &= ~flags;
	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00a6
 */
bool ai_if_has_chrflag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if ((g_Vars.chrdata->chrflags & flags) == flags) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 00a7
 */
bool ai_chr_set_chrflag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->chrflags |= flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00a8
 */
bool ai_chr_unset_chrflag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->chrflags &= ~flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00a9
 */
bool ai_if_chr_has_chrflag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & flags) == flags) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 011b
 */
bool ai_chr_set_hidden_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->hidden |= flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 011c
 */
bool ai_chr_unset_hidden_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->hidden &= ~flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 011d
 */
bool ai_if_chr_has_hidden_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->hidden & flags) == flags) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 00aa
 */
bool ai_set_obj_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		obj->flags |= flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00ab
 */
bool ai_unset_obj_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		obj->flags &= ~flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00ac
 */
bool ai_if_obj_has_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && (obj->flags & flags) == flags) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 00ad
 */
bool ai_set_obj_flag2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		obj->flags2 |= flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00ae
 */
bool ai_unset_obj_flag2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		obj->flags2 &= ~flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00af
 */
bool ai_if_obj_has_flag2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && (obj->flags2 & flags) == flags) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 0118
 */
bool ai_set_obj_flag3(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		obj->flags3 |= flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 0119
 */
bool ai_unset_obj_flag3(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		obj->flags3 &= ~flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 011a
 */
bool ai_if_obj_has_flag3(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && (obj->flags3 & flags) == flags) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 00b0
 */
bool ai_set_chr_preset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	chr_set_chr_preset(g_Vars.chrdata, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00b1
 */
bool ai_set_chr_target(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	chr_set_chr_preset_by_chrnum(g_Vars.chrdata, cmd[2], cmd[3]);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00b2
 */
bool ai_set_pad_preset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata) {
		chr_set_pad_preset(g_Vars.chrdata, pad_id);
	} else if (g_Vars.heli) {
		g_Vars.heli->base.pad = pad_id;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00b3
 */
bool ai_chr_set_pad_preset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[4] | (cmd[3] << 8);

	chr_set_pad_preset_by_chrnum(g_Vars.chrdata, cmd[2], pad_id);

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 00b4
 */
bool ai_chr_copy_pad_preset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chrsrc = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	struct chrdata *chrdst = chr_find_by_id(g_Vars.chrdata, cmd[3]);

	chrdst->padpreset1 = chrsrc->padpreset1;
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00b5
 *
 * The weirdness to do with result is required for a match.
 * The original source likely had something similar and probably used ifdefs.
 */
bool ai_print(void)
{
	u32 len;
	u32 result = dprint();

	if (result) {
		result = 2;
	}

	if (result == 2) {
		// empty
	}

	len = chrai_get_command_length(g_Vars.ailist, g_Vars.aioffset);

	g_Vars.aioffset += len;

	return false;
}

/**
 * @cmd 0091
 */
bool ai_noop_0091(void)
{
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 00b6
 */
bool ai_restart_timer(void)
{
	if (g_Vars.chrdata) {
		chr_restart_timer(g_Vars.chrdata);
	} else if (g_Vars.hovercar) {
		chopper_restart_timer(g_Vars.hovercar);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00b7
 */
bool ai_reset_timer(void)
{
	g_Vars.chrdata->timer60 = 0;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00b8
 */
bool ai_pause_timer(void)
{
	g_Vars.chrdata->hidden &= ~CHRHFLAG_TIMER_RUNNING;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00b9
 */
bool ai_resume_timer(void)
{
	g_Vars.chrdata->hidden |= CHRHFLAG_TIMER_RUNNING;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00ba
 */
bool ai_if_timer_stopped(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((g_Vars.chrdata->hidden & CHRHFLAG_TIMER_RUNNING) == 0) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 00bb
 */
bool ai_if_timer_greater_than_random(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 timer = chr_get_timer(g_Vars.chrdata);

	if (g_Vars.chrdata->random < timer) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 00bc
 */
bool ai_if_timer_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = (u32)((cmd[3] << 8) | cmd[4] | (cmd[2] << 16)) / 60.0f;

	if ((g_Vars.chrdata && chr_get_timer(g_Vars.chrdata) < value) ||
			(g_Vars.hovercar && chopper_get_timer(g_Vars.hovercar) < value)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 00bd
 */
bool ai_if_timer_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = (u32)((cmd[3] << 8) | cmd[4] | (cmd[2] << 16)) / 60.0f;

	// These two function calls were likely used in a debug print statement
	if (g_Vars.chrdata) {
		chr_get_timer(g_Vars.chrdata);
	}

	if (g_Vars.hovercar) {
		chopper_get_timer(g_Vars.hovercar);
	}

	if ((g_Vars.chrdata && chr_get_timer(g_Vars.chrdata) > value) ||
			(g_Vars.hovercar && chopper_get_timer(g_Vars.hovercar) > value)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 00be
 */
bool ai_show_countdown_timer(void)
{
	countdown_timer_set_visible(COUNTDOWNTIMERREASON_AI, true);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00bf
 */
bool ai_hide_countdown_timer(void)
{
	countdown_timer_set_visible(COUNTDOWNTIMERREASON_AI, false);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00c0
 */
bool ai_set_countdown_timer_value(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 seconds = cmd[3] | (cmd[2] << 8);

	countdown_timer_set_value60(seconds * 60);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00c1
 */
bool ai_stop_countdown_timer(void)
{
	countdown_timer_set_running(false);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00c2
 */
bool ai_start_countdown_timer(void)
{
	countdown_timer_set_running(true);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00c3
 */
bool ai_if_countdown_timer_stopped(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (!countdown_timer_is_running()) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 00c4
 */
bool ai_if_countdown_timer_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = cmd[3] | (cmd[2] << 8);

	if (countdown_timer_get_value60() < value * 60) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 00c5
 */
bool ai_if_countdown_timer_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = cmd[3] | (cmd[2] << 8);

	if (countdown_timer_get_value60() > value * 60) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 00c6
 */
bool ai_spawn_chr_at_pad(void)
{
	struct bytelist *cmd = (struct bytelist *)(g_Vars.ailist + g_Vars.aioffset);
	u16 pad = cmd->b4 << 8 | cmd->b5;
	u32 spawnflags = cmd->b8 << 24 | cmd->b9 << 16 | cmd->b10 << 8 | cmd->b11;
	u16 ailistid = cmd->b6 << 8 | cmd->b7;
	u8 *ailist = ailist_find_by_id(ailistid);

	if (spawnflags);

	if (chr_spawn_at_pad(g_Vars.chrdata, cmd->b2, (s8)cmd->b3, pad, ailist, spawnflags)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd->b12);
	} else {
		g_Vars.aioffset += 13;
	}

	return false;
}

/**
 * @cmd 00c7
 */
bool ai_spawn_chr_at_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 spawnflags = (cmd[8] << 16) | (cmd[9] << 8) | cmd[10] | (cmd[7] << 24);
	u16 ailistid = cmd[6] | (cmd[5] << 8);
	u8 *ailist = ailist_find_by_id(ailistid);

	if (chr_spawn_at_chr(g_Vars.chrdata, cmd[2], (s8)cmd[3], cmd[4], ailist, spawnflags)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[11]);
	} else {
		g_Vars.aioffset += 12;
	}

	return false;
}

/**
 * @cmd 00c8
 */
bool ai_try_equip_weapon(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[6] << 16) | (cmd[7] << 8) | cmd[8] | (cmd[5] << 24);
	u32 model = cmd[3] | (cmd[2] << 8);
	struct prop *prop = NULL;

	if (g_Vars.chrdata && g_Vars.chrdata->prop && g_Vars.chrdata->model) {
		// If the Marqis cheat is active, don't give guns to chrs,
		// except where required for objectives.
#if VERSION < VERSION_NTSC_1_0
		// On NTSC beta, Marquis is disabled entirely on MBR, and the K7 guard
		// on Investigation PA is excluded here (ie. is given his weapon).
		if (cheat_is_active(CHEAT_MARQUIS) && g_Vars.stagenum != STAGE_MBR) {
			if (g_Vars.stagenum == STAGE_INVESTIGATION
					&& lv_get_difficulty() == DIFF_PA
					&& cmd[4] == WEAPON_K7AVENGER) {
				prop = chr_give_weapon(g_Vars.chrdata, model, cmd[4], flags);
			}
		}
#elif VERSION < VERSION_PAL_BETA
		// NTSC final enables Marquis for MBR, but fails to realise why it was
		// disabled in the first place (Cass needs to equip her Falcon).
		// Additionally, NTSC Final changes the logic so the chrs are given
		// their weapon but they cannot equip them. This means the K7 guard
		// no longer needs to be handled.
		if (cheat_is_active(CHEAT_MARQUIS)) {
			flags &= ~OBJFLAG_WEAPON_LEFTHANDED;
			flags |= OBJFLAG_WEAPON_AICANNOTUSE;

			prop = chr_give_weapon(g_Vars.chrdata, model, cmd[4], flags);
		}
#else
		// PAL fixes Cass on MBR by allowing her to equip her weapon
		if (cheat_is_active(CHEAT_MARQUIS)) {
			if (g_Vars.chrdata->bodynum != BODY_CASSANDRA || main_get_stage_num() != STAGE_MBR) {
				flags &= ~OBJFLAG_WEAPON_LEFTHANDED;
				flags |= OBJFLAG_WEAPON_AICANNOTUSE;
			}

			prop = chr_give_weapon(g_Vars.chrdata, model, cmd[4], flags);
		}
#endif
		else if (cheat_is_active(CHEAT_ENEMYROCKETS)) {
			switch (cmd[4]) {
			case WEAPON_FALCON2:
			case WEAPON_FALCON2_SILENCER:
			case WEAPON_FALCON2_SCOPE:
			case WEAPON_MAGSEC4:
			case WEAPON_MAULER:
			case WEAPON_PHOENIX:
			case WEAPON_DY357MAGNUM:
			case WEAPON_DY357LX:
			case WEAPON_CMP150:
			case WEAPON_CYCLONE:
			case WEAPON_CALLISTO:
			case WEAPON_RCP120:
			case WEAPON_LAPTOPGUN:
			case WEAPON_DRAGON:
			case WEAPON_AR34:
			case WEAPON_SUPERDRAGON:
			case WEAPON_SHOTGUN:
			case WEAPON_REAPER:
			case WEAPON_SNIPERRIFLE:
			case WEAPON_FARSIGHT:
			case WEAPON_DEVASTATOR:
			case WEAPON_ROCKETLAUNCHER:
			case WEAPON_SLAYER:
			case WEAPON_COMBATKNIFE:
			case WEAPON_CROSSBOW:
			case WEAPON_TRANQUILIZER:
			case WEAPON_GRENADE:
			case WEAPON_NBOMB:
			case WEAPON_TIMEDMINE:
			case WEAPON_PROXIMITYMINE:
			case WEAPON_REMOTEMINE:
				prop = chr_give_weapon(g_Vars.chrdata, MODEL_CHRDYROCKET, WEAPON_ROCKETLAUNCHER, flags);
				break;
			case WEAPON_K7AVENGER:
				if (g_Vars.stagenum == STAGE_INVESTIGATION && lv_get_difficulty() == DIFF_PA) {
					prop = chr_give_weapon(g_Vars.chrdata, model, cmd[4], flags);
				} else {
					prop = chr_give_weapon(g_Vars.chrdata, MODEL_CHRDYROCKET, WEAPON_ROCKETLAUNCHER, flags);
				}
				break;
			default:
				prop = chr_give_weapon(g_Vars.chrdata, model, cmd[4], flags);
				break;
			}
		} else {
			prop = chr_give_weapon(g_Vars.chrdata, model, cmd[4], flags);
		}
	}

	if (prop) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[9]);
	} else {
		g_Vars.aioffset += 10;
	}

	return false;
}

/**
 * @cmd 00c9
 */
bool ai_try_equip_hat(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[5] << 16) | (cmd[6] << 8) | cmd[7] | (cmd[4] << 24);
	u32 modelnum = cmd[3] | (cmd[2] << 8);
	struct prop *prop = NULL;

	if (g_Vars.chrdata && g_Vars.chrdata->prop && g_Vars.chrdata->model) {
		prop = hat_create_for_chr(g_Vars.chrdata, modelnum, flags);
	}

	if (prop) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[8]);
	} else {
		g_Vars.aioffset += 9;
	}

	return false;
}

/**
 * @cmd 00ca
 */
bool ai_duplicate_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 spawnflags = (cmd[6] << 16) | (cmd[7] << 8) | cmd[8] | (cmd[5] << 24);
	u16 ailistid = cmd[4] | (cmd[3] << 8);
	u8 *ailist = ailist_find_by_id(ailistid);
	bool pass = false;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	struct chrdata *clone = NULL;
	struct weaponobj *srcweapon1 = NULL;
	struct prop *cloneprop = NULL;
	struct weaponobj *srcweapon0 = NULL;
	struct prop *srcweapon0prop = NULL;
	struct prop *cloneweapon0prop = NULL;
	struct prop *srcweapon1prop = NULL;
	struct weaponobj *cloneweapon1 = NULL;
	struct weaponobj *cloneweapon0 = NULL;
	struct prop *cloneweapon1prop = NULL;

	if (chr && (chr->chrflags & CHRCFLAG_CLONEABLE)) {
		cloneprop = chr_spawn_at_chr(g_Vars.chrdata, chr->bodynum, -1, chr->chrnum, ailist, spawnflags);

		if (cloneprop) {
			clone = cloneprop->chr;
			chr_set_chrnum(clone, chrs_get_next_unused_chrnum());
			chr->chrdup = clone->chrnum;

			srcweapon0prop = chr_get_held_prop(chr, 0);

			if (srcweapon0prop) {
				srcweapon0 = srcweapon0prop->weapon;
				cloneweapon0prop = chr_give_weapon(clone, srcweapon0->base.modelnum, srcweapon0->weaponnum, 0);

				if (cloneweapon0prop) {
					cloneweapon0 = cloneweapon0prop->weapon;
				}
			}

			srcweapon1prop = chr_get_held_prop(chr, 1);

			if (srcweapon1prop) {
				srcweapon1 = srcweapon1prop->weapon;
				cloneweapon1prop = chr_give_weapon(clone, srcweapon1->base.modelnum, srcweapon1->weaponnum, OBJFLAG_WEAPON_LEFTHANDED);

				if (cloneweapon1prop) {
					cloneweapon1 = cloneweapon1prop->weapon;
				}
			}

			if (srcweapon1 && srcweapon0
					&& cloneweapon1 && cloneweapon0
					&& srcweapon0 == srcweapon1->dualweapon && srcweapon1 == srcweapon0->dualweapon) {
				weapon_set_dual(cloneweapon1, cloneweapon0);
			}

			if (chr->weapons_held[2]) {
				struct defaultobj *obj = chr->weapons_held[2]->obj;
				hat_create_for_chr(clone, obj->modelnum, 0);
			}

			clone->flags = chr->flags;
			clone->flags2 = chr->flags2;
			clone->padpreset1 = chr->padpreset1;

			if (g_Vars.normmplayerisrunning == false
					&& g_MissionConfig.iscoop
					&& g_Vars.numaibuddies > 0) {
				clone->flags |= CHRFLAG0_AIVSAI;
			}

			if (spawnflags & SPAWNFLAG_HIDDEN) {
				clone->chrflags &= CHRCFLAG_HIDDEN;
			}

			clone->team = chr->team;
			clone->squadron = chr->squadron;
			clone->voicebox = chr->voicebox;

			rebuild_teams();
			rebuild_squadrons();

			pass = true;
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[9]);
	} else {
		g_Vars.aioffset += 10;
	}

	return false;
}

/**
 * @cmd 00cb
 */
bool ai_show_hudmsg(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	char *text = lang_get(cmd[4] | (cmd[3] << 8));
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	u32 prevplayernum = g_Vars.currentplayernum;
	u32 playernum = g_Vars.currentplayernum;

	if (chr && chr->prop && (chr->prop->type & 0xff) == PROPTYPE_PLAYER) {
		playernum = playermgr_get_player_num_by_prop(chr->prop);
	}

	set_current_player_num(playernum);
	hudmsg_create(text, HUDMSGTYPE_DEFAULT);
	set_current_player_num(prevplayernum);

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01a4
 */
bool ai_show_hudmsg_middle(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] == 0) {
		u32 text_id = cmd[5] | (cmd[4] << 8);
		char *text = lang_get(text_id);
		hudmsg_create_with_colour(text, HUDMSGTYPE_7, cmd[3]);
	} else if (cmd[2] == 1) {
		u32 text_id = cmd[5] | (cmd[4] << 8);
		char *text = lang_get(text_id);
		hudmsg_create_with_colour(text, HUDMSGTYPE_8, cmd[3]);
	} else {
		hudmsg_remove_all();
	}

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00cc
 */
bool ai_show_hudmsg_top_middle(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	char *text = lang_get(cmd[4] | (cmd[3] << 8));
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	u32 prevplayernum = g_Vars.currentplayernum;
	u32 playernum = g_Vars.currentplayernum;

	if (chr && chr->prop && (chr->prop->type & 0xff) == PROPTYPE_PLAYER) {
		playernum = playermgr_get_player_num_by_prop(chr->prop);
	}

	set_current_player_num(playernum);
	hudmsg_create_with_colour(text, HUDMSGTYPE_INGAMESUBTITLE, cmd[5]);
	set_current_player_num(prevplayernum);

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00cd
 */
bool ai_speak(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	s16 audio_id = cmd[6] | (cmd[5] << 8);
	s16 text_id = cmd[4] | (cmd[3] << 8);
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 playernum = prevplayernum;
	u32 channelnum;
	char *text = text_id >= 0 ? lang_get(cmd[4] | (cmd[3] << 8)) : NULL;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		playernum = playermgr_get_player_num_by_prop(chr->prop);
	}

	set_current_player_num(playernum);

	if (text && cmd[2] != CHR_P1P2) {
		ps_stop_sound(g_Vars.chrdata->prop, PSTYPE_CHRTALK, 0xffff);
	}

	if (cmd[2] == CHR_P1P2) {
		channelnum = ps_play_from_prop((s8)cmd[7], audio_id, 0, g_Vars.chrdata->prop, PSTYPE_NONE, PSFLAG_FORHUDMSG);
	} else {
		channelnum = ps_play_from_prop((s8)cmd[7], audio_id, 0, g_Vars.chrdata->prop, PSTYPE_CHRTALK, PSFLAG_FORHUDMSG);
	}

	if (text && !snd_is_filtered(audio_id)) {
		hudmsg_create_as_subtitle(text, HUDMSGTYPE_INGAMESUBTITLE, cmd[8], channelnum);
	}

	set_current_player_num(prevplayernum);

	g_Vars.aioffset += 9;

	return false;
}

/**
 * @cmd 00ce
 */
bool ai_play_sound(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 audio_id = cmd[3] | (cmd[2] << 8);

	ps_play_from_prop((s8)cmd[4], audio_id, 0, NULL, PSTYPE_NONE, 0);

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 017c
 */
bool ai_assign_sound(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 audio_id = cmd[3] | (cmd[2] << 8);

	ps_play_from_prop((s8)cmd[4], audio_id, -1, NULL, PSTYPE_MARKER, 0);

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 00d3
 */
bool ai_audio_mute_channel(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s8 channel = (s8)cmd[2];

	ps_mute_channel(channel);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0138
 */
bool ai_if_channel_free(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s8 channel = (s8) cmd[2];

	if (ps_is_channel_free(channel)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 00d1
 */
bool ai_set_object_sound_volume(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 volume = cmd[4] | (cmd[3] << 8);
	u16 volchangetimer60 = cmd[6] | (cmd[5] << 8);

	ps_modify((s8)cmd[2], volume, -1, NULL, volchangetimer60, 2500, 3000, 0);

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00d2
 */
bool ai_set_object_sound_volume_by_distance(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 playerdist = cmd[4] | (cmd[3] << 8);
	u16 volchangetimer60 = cmd[6] | (cmd[5] << 8);
	s32 volume = ps_calculate_volume_from_distance(playerdist, 400, 2500, 3000, AL_VOL_FULL);

	ps_modify((s8)cmd[2], volume, -1, NULL, volchangetimer60, 2500, 3000, 0);

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00cf
 */
bool ai_set_object_sound_playing(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[3]);
	u16 volchangetimer60 = cmd[5] | (cmd[4] << 8);

	if (obj && obj->prop) {
		ps_modify((s8)cmd[2], -1, -1, obj->prop, volchangetimer60, 2500, 3000, 0);
	}

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 016b
 */
bool ai_play_repeating_sound_from_object(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[3]);
	u16 thing1 = cmd[5] | (cmd[4] << 8);
	u16 dist2 = cmd[7] | (cmd[6] << 8);
	u16 dist3 = cmd[9] | (cmd[8] << 8);

	if (obj && obj->prop) {
		s32 volchangetimer60;

		if (thing1 == 0) {
			volchangetimer60 = -1;
		} else {
			volchangetimer60 = thing1;
		}

		ps_modify((s8)cmd[2], -1, -1, obj->prop, volchangetimer60, dist2, dist3, PSFLAG_REPEATING);
	}

	g_Vars.aioffset += 10;

	return false;
}

/**
 * @cmd 0179
 */
bool ai_play_sound_from_entity(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 volchangetimer60 = cmd[5] | (cmd[4] << 8);
	u16 dist2 = cmd[7] | (cmd[6] << 8);
	u16 dist3 = cmd[9] | (cmd[8] << 8);

	if (cmd[10] == 0) {
		struct defaultobj *obj = obj_find_by_tag_id(cmd[3]);

		if (obj && obj->prop) {
			ps_modify((s8)cmd[2], -1, -1, obj->prop, volchangetimer60, dist2, dist3, 0);
		}
	} else {
		struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[3]);

		if (chr && chr->prop) {
			ps_modify((s8)cmd[2], -1, -1, chr->prop, volchangetimer60, dist2, dist3, 0);
		}
	}

	g_Vars.aioffset += 11;

	return false;
}

/**
 * @cmd 00d0
 */
bool ai_play_repeating_sound_from_pad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 padnum = cmd[4] | (cmd[3] << 8);
	s16 sound = cmd[6] | (cmd[5] << 8);

	ps_create(0, NULL, sound, padnum, -1, PSFLAG_REPEATING, 0, PSTYPE_NONE, 0, -1, 0, -1, -1, -1, -1);

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00d4
 */
bool ai_if_object_sound_volume_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 value = cmd[4] | (cmd[3] << 8);

	if (ps_get_volume((s8)cmd[2]) < value) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 00d5
 */
bool ai_hovercar_begin_path(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct path *path = path_find_by_id(cmd[2]);

	if (g_Vars.truck) {
		g_Vars.truck->path = path;
		g_Vars.truck->nextstep = 0;
	}

	if (g_Vars.hovercar) {
		struct chopperobj *chopper = chopper_from_hovercar(g_Vars.hovercar);
		g_Vars.hovercar->path = path;
		g_Vars.hovercar->nextstep = 0;
		g_Vars.hovercar->path->flags |= PATHFLAG_INUSE;

		if (chopper) {
			chopper->targetvisible = false;
			chopper->attackmode = CHOPPERMODE_PATROL;
			chopper->turnrot60 = 0;
			chopper->roty = 0;
			chopper->rotx = 0;
			chopper->gunroty = 0;
			chopper->gunrotx = 0;
			chopper->barrelrot = 0;
			chopper->barrelrotspeed = 0;
			chopper->vz = 0;
			chopper->vy = 0;
			chopper->vx = 0;
			chopper->otz = 0;
			chopper->oty = 0;
			chopper->otx = 0;
			chopper->power = 0;
			chopper->bob = 0;
			chopper->bobstrength = 0.05;
			chopper->timer60 = 0;
			chopper->patroltimer60 = 0;
			chopper->cw = 0;
			chopper->weaponsarmed = true;
			chopper->base.flags |= OBJFLAG_CHOPPER_INIT;
		} else {
			g_Vars.hovercar->weaponsarmed = false;
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00d6
 */
bool ai_set_vehicle_speed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 speedtime = cmd[5] | (cmd[4] << 8);
	f32 speedaim = (cmd[3] | (cmd[2] << 8)) * 100.0f / 15360.0f;

	if (g_Vars.truck) {
		g_Vars.truck->speedaim = speedaim;
		g_Vars.truck->speedtime60 = speedtime;
	}

	if (g_Vars.hovercar) {
		g_Vars.hovercar->speedaim = speedaim;
		g_Vars.hovercar->speedtime60 = speedtime;
	}

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00d7
 */
bool ai_set_rotor_speed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 speedtime = cmd[5] | (cmd[4] << 8);
	f32 speedaim = (cmd[3] | (cmd[2] << 8)) * BADDTOR(360) / 3600;

	if (g_Vars.heli) {
		g_Vars.heli->rotoryspeedaim = speedaim;
		g_Vars.heli->rotoryspeedtime = speedtime;
	}

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00d8
 */
bool ai_noop_00d8(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 00d9
 */
bool ai_noop_00d9(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 00da
 */
bool ai_set_obj_image(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		if (obj->type == OBJTYPE_SINGLEMONITOR) {
			struct singlemonitorobj *sm = (struct singlemonitorobj *) obj;
			tvscreen_set_program(&sm->screen, cmd[4]);
		} else if (obj->type == OBJTYPE_MULTIMONITOR) {
			struct multimonitorobj *mm = (struct multimonitorobj *) obj;
			u8 slot = cmd[3];

			if (slot < ARRAYCOUNT(mm->screens)) {
				tvscreen_set_program(&mm->screens[slot], cmd[4]);
			}
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 00db
 */
bool ai_noop_00db(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 00dc
 */
bool ai_end_level(void)
{
	if (debug_allow_end_level()) {
		if (g_IsTitleDemo) {
			main_change_to_stage(STAGE_TITLE);
		} else if (g_Vars.autocutplaying) {
			g_Vars.autocutfinished = true;
		} else {
			func0000e990();
		}
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00dd
 */
bool ai00dd(void)
{
	player_end_cutscene();
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 00de
 */
bool ai_move_camera_to_pad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[3] | (cmd[2] << 8);

	player_prepare_move_camera_to_pad(pad_id);

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 010d
 */
bool ai_noop_010d(void)
{
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 0111
 */
bool ai_set_camera_animation(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 anim_id = cmd[3] | (cmd[2] << 8);

	player_start_cutscene(anim_id);

	if (g_Vars.currentplayer->haschrbody == false) {
		return true;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0113
 */
bool ai_if_in_cutscene(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.in_cutscene) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0174
 */
bool ai_if_cutscene_button_pressed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((g_Vars.in_cutscene && g_CutsceneSkipRequested) ||
			(g_Vars.stagenum == STAGE_CITRAINING && var80087260 > 0)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0175
 */
bool ai0175(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	player_reorient_for_cutscene_stop(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0112
 */
bool ai_object_do_animation(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 anim_id = cmd[3] | (cmd[2] << 8);
	struct defaultobj *obj = NULL;
	f32 thing;
	s32 startframe = cmd[7] | (cmd[6] << 8);
	f32 fstartframe;

	if (startframe == 0xffff) {
		fstartframe = 0;
	} else if (startframe == 0xfffe) {
		fstartframe = anim_get_num_frames(anim_id) - 2;

		if (fstartframe < 0) {
			fstartframe = 0;
		}
	} else {
		fstartframe = startframe;
	}

	if (cmd[4] == 255) {
		if (g_Vars.chrdata && g_Vars.chrdata->myspecial >= 0) {
			obj = obj_find_by_tag_id(g_Vars.chrdata->myspecial);
		}
	} else {
		obj = obj_find_by_tag_id(cmd[4]);
	}

	if (obj && obj->prop) {
		struct anim *anim = obj->model->anim;

		if (obj->model->anim == NULL) {
			obj->model->anim = modelmgr_instantiate_anim();
		}

		if (obj->model->anim) {
			thing = 1.0f / (s32)cmd[5];

			if (g_Vars.in_cutscene && startframe != 0xfffe) {
#if PAL
				fstartframe += var8009e388pf * thing;
#else
				fstartframe += g_CutsceneFrameOverrun240 * thing * 0.25f;
#endif
			}

			anim_init(obj->model->anim);
#if VERSION >= VERSION_JPN_FINAL
			model_set_anim_play_speed(obj->model, 1, 0);
#elif VERSION >= VERSION_PAL_BETA
			model_set_anim_play_speed(obj->model, 1.2, 0);
#endif
			model_set_animation(obj->model, anim_id, 0, fstartframe, thing, 0);
			model_set_anim_scale(obj->model, bg_get_stage_translation_thing() * obj->model->scale * 100.0f);
		}
	}

	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 0114
 */
bool ai_enable_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->model) {
		prop_activate(chr->prop);
		prop_enable(chr->prop);
		chr_detect_rooms(chr);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0115
 */
bool ai_disable_chr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->model) {
		prop_deregister_rooms(chr->prop);
		prop_delist(chr->prop);
		prop_disable(chr->prop);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0116
 */
bool ai_enable_obj(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj->model) {
		prop_activate(obj->prop);
		prop_enable(obj->prop);

		if (g_Vars.currentplayer->eyespy == NULL && obj->type == OBJTYPE_WEAPON) {
			struct weaponobj *weapon = (struct weaponobj *) obj;

			if (weapon->weaponnum == WEAPON_EYESPY) {
				player_init_eyespy();
			}
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0117
 */
bool ai_disable_obj(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj->model) {
#if VERSION >= VERSION_PAL_FINAL
		if (g_Vars.autocutplaying
				&& main_get_stage_num() == STAGE_AIRFORCEONE
				&& (obj->modelnum == MODEL_AIRFORCE1 || obj->modelnum == MODEL_SK_SHUTTLE)) {
			// ignore
		} else {
			if (obj->prop->parent) {
				obj_detach(obj->prop);
			} else {
				prop_deregister_rooms(obj->prop);
				prop_delist(obj->prop);
				prop_disable(obj->prop);
			}
		}
#else
		if (obj->prop->parent) {
			obj_detach(obj->prop);
		} else {
			prop_deregister_rooms(obj->prop);
			prop_delist(obj->prop);
			prop_disable(obj->prop);
		}
#endif
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00df
 */
bool ai_move_camera_to_preset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct tag *tag = tag_find_by_id(cmd[2]);

	if (tag) {
		s32 cmdindex = setup_get_cmd_index_by_tag(tag);

		if (cmdindex >= 0) {
			struct camerapresetobj *preset = (struct camerapresetobj *) setup_get_cmd_by_index(cmdindex + tag->cmdoffset);
			player_prepare_move_camera_to_preset(preset, cmd[4] | (cmd[3] << 8), cmd[6] | (cmd[5] << 8));
		}
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00e0
 */
bool ai_revoke_control(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);
		bgun_set_sight_visible(GUNSIGHTREASON_NOCONTROL, false);
		bgun_set_gun_ammo_visible(GUNAMMOREASON_NOCONTROL, false);

		if ((cmd[3] & 2) == 0) {
			hudmsgs_set_off(HUDMSGREASON_NOCONTROL);
		}

		if ((cmd[3] & 4) == 0) {
			countdown_timer_set_visible(COUNTDOWNTIMERREASON_NOCONTROL, false);
		}

		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		set_current_player_num(prevplayernum);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00e1
 */
bool ai_grant_control(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		set_current_player_num(playermgr_get_player_num_by_prop(chr->prop));
		bgun_set_sight_visible(GUNSIGHTREASON_NOCONTROL, true);
		bgun_set_gun_ammo_visible(GUNAMMOREASON_NOCONTROL, true);
		hudmsgs_set_on(HUDMSGREASON_NOCONTROL);
		countdown_timer_set_visible(COUNTDOWNTIMERREASON_NOCONTROL, true);
		g_PlayersWithControl[g_Vars.currentplayernum] = true;
		set_current_player_num(prevplayernum);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00e2
 */
bool ai_chr_move_to_pad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
#if VERSION < VERSION_NTSC_1_0
	s32 padnum = cmd[4] | (cmd[3] << 8);
#endif
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	bool pass = false;
	f32 theta;
	struct pad pad;
	RoomNum rooms[2];
	struct chrdata *chr2;

	if (chr && chr->prop) {
#if VERSION >= VERSION_NTSC_1_0
		if (cmd[5] == 88) {
			chr2 = chr_find_by_id(g_Vars.chrdata, cmd[4]);

			if (chr2 && chr2->prop) {
				theta = chr_get_theta(chr2);
				pass = chr_move_to_pos(chr, &chr2->prop->pos, chr2->prop->rooms, theta, false);
			}
		} else {
			s32 padnum = cmd[4] | (cmd[3] << 8);
			padnum = chr_resolve_pad_id(chr, padnum);

			if (padnum >= 0) {
				pad_unpack(padnum, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_ROOM, &pad);
				theta = atan2f(pad.look.x, pad.look.z);

				rooms[0] = pad.room;
				rooms[1] = -1;
				pass = chr_move_to_pos(chr, &pad.pos, rooms, theta, cmd[5]);
			}
		}
#else
		padnum = chr_resolve_pad_id(chr, padnum);

		pad_unpack(padnum, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_ROOM, &pad);
		theta = atan2f(pad.look.x, pad.look.z);

		rooms[0] = pad.room;
		rooms[1] = -1;
		pass = chr_move_to_pos(chr, &pad.pos, rooms, theta, cmd[5]);
#endif
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 00e3
 */
bool ai00e3(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);

		if (var8007074c != 2) {
			player_set_fade_colour(0, 0, 0, 0);
			player_set_fade_frac(60, 1);
		}

		set_current_player_num(prevplayernum);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00e4
 */
bool ai00e4(void)
{
	s32 playernum;
	u32 prevplayernum = g_Vars.currentplayernum;

	for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
		set_current_player_num(playernum);

		if (var8007074c != 2) {
			player_set_fade_colour(0, 0, 0, 1);
			player_set_fade_frac(60, 0);
		}
	}

	set_current_player_num(prevplayernum);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00e5
 */
bool ai_if_colour_fade_complete(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bool pass = false;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);

		if (g_Vars.players[playernum]->colourfadetimemax60 < 0) {
			pass = true;
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 00e8
 */
bool ai_set_door_open(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		struct doorobj *door = (struct doorobj *) obj;
		door->frac = door->maxfrac;
		door->fracspeed = 0;
		door->lastopen60 = g_Vars.lvframe60;
		door->mode = 0;
		door_update_tiles(door);
		door_activate_portal(door);
		ps_stop_sound(door->base.prop, PSTYPE_GENERAL, 0xffff);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00e9
 */
bool ai00e9(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		weapon_delete_from_chr(chr, cmd[3]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00ea
 */
bool ai_if_num_players_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((s8)cmd[2] > PLAYERCOUNT()) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 00eb
 */
bool ai_if_chr_ammo_quantity_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	bool passes = false;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);

		if (bgun_get_ammo_count((s8)cmd[3]) < (s8)cmd[4]) {
			passes = true;
		}

		set_current_player_num(prevplayernum);
	}

	if (passes) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 00ec
 */
bool ai_chr_draw_weapon(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);
		bgun_equip_weapon2(0, (s8)cmd[3]);
		bgun_equip_weapon2(1, 0);
		set_current_player_num(prevplayernum);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00ed
 */
bool ai_chr_draw_weapon_in_cutscene(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);
		bgun_equip_weapon((s8)cmd[3]);
		set_current_player_num(prevplayernum);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00ee
 */
bool ai00ee(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);

		g_Vars.currentplayer->bondforcespeed.x = (s8)cmd[3];
		g_Vars.currentplayer->bondforcespeed.y = 0;
		g_Vars.currentplayer->bondforcespeed.z = (s8)cmd[4];

		set_current_player_num(prevplayernum);
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 00ef
 */
bool ai_if_obj_in_room(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);
	u16 room_id = cmd[4] | (cmd[3] << 8);
	s32 room_something = chr_get_pad_room(g_Vars.chrdata, room_id);

	if (room_something >= 0 && obj && obj->prop && room_something == obj->prop->rooms[0]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 00f2
 */
bool ai_switch_to_alt_sky(void)
{
	env_apply_transition_frac(1);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00f3
 */
bool ai_chr_set_invincible(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);
		g_PlayerInvincible = true;
		set_current_player_num(prevplayernum);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00f4
 */
bool ai_move_camera_to_pos(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	s32 range = cmd[3] | (cmd[2] << 8);
	s16 height1 = cmd[5] | (cmd[4] << 8);
	s16 rotangle = cmd[7] | (cmd[6] << 8);
	s32 padnum = cmd[9] | (cmd[8] << 8);
	s16 height2 = cmd[11] | (cmd[10] << 8);
	s32 posangle = cmd[13] | (cmd[12] << 8);

	player_prepare_move_camera_to_pos(posangle * BADDTOR(360) / 65536, rotangle * BADDTOR(360) / 65536, range, height1, height2, padnum);

	g_Vars.aioffset += 14;

	return false;
}

/**
 * @cmd 00f5
 */
bool ai00f5(void)
{
	var8007073c = 1;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00f6
 */
bool ai00f6(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (var8007073c == 2) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 00f7
 */
bool ai_if_all_objectives_complete(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (objective_is_all_complete()) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 3;
	}

	return false;
}

/**
 * @cmd 00f8
 */
bool ai_if_player_is_invincible(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bool pass = false;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);
		pass = g_PlayerInvincible;
		set_current_player_num(prevplayernum);
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 00f9
 */
bool ai_play_x_track(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset += 5;
	music_set_x_reason((s8)cmd[2], cmd[3], cmd[4]);

	return false;
}

/**
 * @cmd 00fa
 */
bool ai_stop_x_track(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset += 3;
	music_unset_x_reason((s8)cmd[2]);

	return false;
}

/**
 * @cmd 015b
 */
bool ai_play_track_isolated(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] == MUSIC_CI_TRAINING) {
		u16 volume = options_get_music_volume();
		music_play_track_isolated(cmd[2]);
		options_set_music_volume(volume);
	} else {
		music_play_track_isolated(cmd[2]);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 015c
 */
bool ai_play_default_tracks(void)
{
	g_Vars.aioffset += 2;
	music_play_default_tracks();

	return false;
}

/**
 * @cmd 017d
 */
bool ai_play_cutscene_track(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	music_start_cutscene(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 017e
 */
bool ai_stop_cutscene_track(void)
{
	g_Vars.aioffset += 2;
	music_end_cutscene();

	return false;
}

/**
 * @cmd 017f
 */
bool ai_play_temporary_track(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	music_start_temporary_ambient(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0180
 */
bool ai_stop_ambient_track(void)
{
	g_Vars.aioffset += 2;
	music_end_temporary_ambient();

	return false;
}

/**
 * @cmd 00fb
 */
bool ai_chr_explosions(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);
		player_surround_with_explosions(0);
		set_current_player_num(prevplayernum);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00fc
 */
bool ai_if_kill_count_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.killcount > cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 01ab
 */
bool ai_if_num_knocked_out_chrs(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] < mpstats_get_total_knockout_count() && cmd[3] == 0) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else if (mpstats_get_total_knockout_count() < cmd[2] && cmd[3] == 1) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 00fd
 */
bool ai00fd(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_TRIGGERSHOTLIST)) {
		chr->chrflags &= ~CHRCFLAG_TRIGGERSHOTLIST;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 00fe
 */
bool ai_kill_bond(void)
{
	g_Vars.bond->isdead = true;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00ff
 */
bool ai_be_surprised_surrender(void)
{
	chr_try_surprised_surrender(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0100
 */
bool ai_noop_0100(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 0101
 */
bool ai_noop_0101(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 0102
 */
bool ai_set_lights(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 padnum = cmd[3] | (cmd[2] << 8);
	s32 roomnum = chr_get_pad_room(g_Vars.chrdata, padnum);

	if (roomnum >= 0) {
		switch (cmd[4]) {
		case LIGHTOP_TURNOFF:
			room_set_lights_on(roomnum, false);
			break;
		case LIGHTOP_TURNON:
			room_set_lights_on(roomnum, true);
			break;
		default:
			room_set_light_op(roomnum, cmd[4], cmd[5], cmd[6], TICKS(cmd[7]));
			break;
		}
	}

	g_Vars.aioffset += 11;

	return false;
}

/**
 * @cmd 0103
 */
bool ai_if_prop_preset_is_blocking_sight_to_target(void)
{
	if (chr_is_prop_preset_blocking_sight_to_target(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0104
 */
bool ai_remove_object_at_prop_preset(void)
{
	if (g_Vars.chrdata->proppreset1 >= 0) {
		struct defaultobj *obj = (g_Vars.props + g_Vars.chrdata->proppreset1)->obj;
		obj->hidden &= ~OBJHFLAG_OCCUPIEDCHAIR;
	}

	g_Vars.chrdata->proppreset1 = -1;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0105
 */
bool ai_if_prop_preset_height_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct prop *prop = &g_Vars.props[g_Vars.chrdata->proppreset1];
	f32 value = cmd[3] | (cmd[2] << 8);
	f32 ymax;
	f32 ymin;
	f32 radius;

	prop_get_bbox(prop, &radius, &ymax, &ymin);

	if (ymax - ymin < value) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0106
 */
bool ai_set_target(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata) {
		s16 newtarget;

		if (!cmd[3] && !cmd[4]) {
			newtarget = prop_get_index_by_chr_id(g_Vars.chrdata, cmd[2]);
		} else if (!cmd[4]) {
			struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
			newtarget = chr->target;
		}

		if (newtarget != g_Vars.chrdata->target) {
			g_Vars.chrdata->lastvisibletarget60 = 0;
			g_Vars.chrdata->lastseetarget60 = 0;
			g_Vars.chrdata->lastheartarget60 = 0;

			// @bug: Unsetting these flags here causes guards to become deaf in
			// co-op mode. This is because their AI scripting toggles their
			// target between the two players on each frame, so this flag is
			// cleared before it is read. A suitable fix would be to only unset
			// these flags if either the old or new target is not a player.
			g_Vars.chrdata->hidden &= ~CHRHFLAG_IS_HEARING_TARGET;
			g_Vars.chrdata->chrflags &= ~CHRCFLAG_NEAR_MISS;

			g_Vars.chrdata->target = newtarget;
		}
	} else if (g_Vars.hovercar) {
		chopper_set_target(g_Vars.hovercar, cmd[2]);
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 0107
 */
bool ai_if_presets_target_is_not_my_target(void)
{
	s32 mypresetchrstarget;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->chrpreset1 != -1) {
		mypresetchrstarget = prop_get_index_by_chr_id(g_Vars.chrdata, g_Vars.chrdata->chrpreset1);
	}

	if (g_Vars.chrdata->target != -1 && mypresetchrstarget != g_Vars.chrdata->target) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0108
 */
bool ai_if_chr_target(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	bool pass = false;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		// empty
	} else if (cmd[2] != CHR_BOND) {
		if (cmd[4] == 0) {
			struct chrdata *chr2 = chr_find_by_id(g_Vars.chrdata, cmd[3]);

			if (chr2 && chr2->prop && chr_get_target_prop(chr) == chr2->prop) {
				pass = true;
			}
		} else {
			if (chr->target != -1 && chr && chr->prop) {
				pass = true;
			}
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 0109
 */
bool ai_set_chr_preset_to_chr_near_self(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[4] | (cmd[3] << 8)) * 10.0f;

	if (chr_set_chr_preset_to_chr_near_self(cmd[2], g_Vars.chrdata, distance)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 010a
 */
bool ai_set_chr_preset_to_chr_near_pad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[4] | (cmd[3] << 8)) * 10.0f;
	u16 padnum = cmd[6] | (cmd[5] << 8);

	if (chr_set_chr_preset_to_chr_near_pad(cmd[2], g_Vars.chrdata, distance, padnum)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 010b
 */
bool ai_chr_set_team(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->team = cmd[3];
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 010c
 */
bool ai_if_compare_chr_presets_team(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, CHR_PRESET);

	if (!chr || (!chr->model && chr->prop->type != PROPTYPE_PLAYER)) {
		chr_set_chr_preset(g_Vars.chrdata, CHR_BOND);
		chr = chr_find_by_id(g_Vars.chrdata, CHR_PRESET);
	}

	if (chr_compare_teams(chr, g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 011e
 */
bool ai_if_human(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && CHRRACE(chr) == RACE_HUMAN) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 011f
 */
bool ai_if_skedar(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && CHRRACE(chr) == RACE_SKEDAR) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0120
 */
bool ai_if_safety2_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u8 score;
	u8 numnearby;
	s16 *chrnums = team_get_chr_ids(g_Vars.chrdata->team);

	score = 6;
	numnearby = 0;

	if (chr_get_num_arghs(g_Vars.chrdata) > 0) {
		score -= 2;
	}

	switch (bgun_get_weapon_num(HAND_RIGHT)) {
	case WEAPON_FALCON2:
	case WEAPON_FALCON2_SILENCER:
	case WEAPON_FALCON2_SCOPE:
	case WEAPON_MAGSEC4:
	case WEAPON_MAULER:
	case WEAPON_PHOENIX:
	case WEAPON_DY357MAGNUM:
	case WEAPON_DY357LX:
	case WEAPON_CROSSBOW:
		break;
	case WEAPON_CMP150:
	case WEAPON_CYCLONE:
	case WEAPON_CALLISTO:
	case WEAPON_RCP120:
	case WEAPON_LAPTOPGUN:
	case WEAPON_DRAGON:
	case WEAPON_K7AVENGER:
	case WEAPON_AR34:
	case WEAPON_SUPERDRAGON:
	case WEAPON_SHOTGUN:
	case WEAPON_SNIPERRIFLE:
		score--;
		break;
	case WEAPON_REAPER:
	case WEAPON_FARSIGHT:
	case WEAPON_DEVASTATOR:
	case WEAPON_ROCKETLAUNCHER:
	case WEAPON_SLAYER:
		score -= 2;
		break;
	default:
		score++;
		break;
	}

	while (*chrnums != -2) {
		struct chrdata *chr = chr_find_by_literal_id(*chrnums);

		if (chr && chr->model
				&& !chr_is_dead(chr)
				&& chr->actiontype != ACT_DEAD
				&& chr->alertness > 100
				&& g_Vars.chrdata->squadron == chr->squadron
				&& g_Vars.chrdata->chrnum != chr->chrnum
				&& chr_get_distance_to_chr(g_Vars.chrdata, chr->chrnum) < 3500) {
			numnearby++;
		}

		chrnums++;
	}

	if (numnearby == 0) {
		score -= 2;
	} else if (numnearby == 1) {
		score--;
	}

	if (score < 3 && numnearby != 0) {
		score = 3;
	}

	if (score < cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0121
 */
bool ai_find_cover(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 criteria = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata && g_Vars.chrdata->prop && chr_assign_cover_by_criteria(g_Vars.chrdata, criteria, 0) != -1) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0122
 */
bool ai_find_cover_within_dist(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 criteria = cmd[3] | (cmd[2] << 8);
	u32 flags = (cmd[5] << 16) | (cmd[6] << 8) | cmd[7] | (cmd[4] << 24);

	if (g_Vars.chrdata && g_Vars.chrdata->prop && chr_assign_cover_by_criteria(g_Vars.chrdata, criteria, flags) != -1) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[8]);
	} else {
		g_Vars.aioffset += 9;
	}

	return false;
}

/**
 * @cmd 0123
 */
bool ai_find_cover_outside_dist(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 criteria = cmd[3] | (cmd[2] << 8);
	u32 flags = (cmd[5] << 16) | (cmd[6] << 8) | cmd[7] | (cmd[4] << 24);

	if (g_Vars.chrdata && g_Vars.chrdata->prop && chr_assign_cover_by_criteria(g_Vars.chrdata, criteria, -flags) != -1) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[8]);
	} else {
		g_Vars.aioffset += 9;
	}

	return false;
}

/**
 * @cmd 0124
 */
bool ai_go_to_cover(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	chr_go_to_cover(g_Vars.chrdata, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0125
 */
bool ai_check_cover_out_of_sight(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_check_cover_out_of_sight(g_Vars.chrdata, g_Vars.chrdata->cover, false)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0126
 */
bool ai_if_player_using_cmp_or_ar34(void)
{
	u32 hand = HAND_RIGHT;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	switch (bgun_get_weapon_num(hand)) {
		case WEAPON_CMP150:
		case WEAPON_AR34:
			g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
			break;
		default:
			g_Vars.aioffset += 3;
			break;
	}

	return false;
}

/**
 * @cmd 0127
 */
bool ai_detect_enemy_on_same_floor(void)
{ \
	s32 team = 0;
	f32 closestdist = 9999.9;
	f32 distance;
	u32 stack[2];
	f32 y;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 scandist;
	s16 *chrnums = team_get_chr_ids(1);
	struct chrdata *chr;
	s16 newtarget = -1;

	if (g_Vars.chrdata->teamscandist == 0) {
		scandist = 1500;
	} else if (g_Vars.chrdata->teamscandist == 255) {
		scandist = 9999;
	} else {
		scandist = g_Vars.chrdata->teamscandist * 40.0f;
	}

	y = g_Vars.chrdata->prop->pos.y;

	while (team < 8) {
		chr = chr_find_by_literal_id(*chrnums);

		if (*chrnums != -2) {
			if (chr && chr->prop
					&& chr->team != TEAM_NONCOMBAT
					&& !chr_is_dead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP
					&& chr_compare_teams(g_Vars.chrdata, chr, COMPARE_ENEMIES)
					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
					&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0
					&& (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0
					&& y - chr->prop->pos.y > -200
					&& y - chr->prop->pos.y < 200
					&& ((g_Vars.chrdata->hidden & CHRHFLAG_PSYCHOSISED) == 0
						|| (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0
						|| (chr->hidden & CHRHFLAG_DONTSHOOTME))
					&& g_Vars.chrdata->chrnum != chr->chrnum) {
				distance = chr_get_distance_to_chr(g_Vars.chrdata, chr->chrnum);

				if (distance < closestdist) {
					if (distance < scandist || stage_get_index(g_Vars.stagenum) == STAGEINDEX_MAIANSOS) {
						if (distance < closestdist) {
							closestdist = distance;
							newtarget = chr->chrnum;
						}
					}
				}
			}

			chrnums++;
		} else {
			chrnums++;
			team++;
		}
	}

	if (newtarget != -1) {
		g_Vars.chrdata->target = prop_get_index_by_chr_id(g_Vars.chrdata, newtarget);
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 3;
	}

	return false;
}

/**
 * @cmd 0128
 */
bool ai_detect_enemy(void)
{
	s16 *chrnums;
	s32 team = 0;
	u32 stack[4];
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 closestdist = 10000000;
	f32 maxdist = (s32)cmd[2] * 10.0f;
	s16 closesttarg = -1;

	chrnums = team_get_chr_ids(1);

	if (!g_Vars.chrdata) {
		g_Vars.aioffset = g_Vars.aioffset + 4;
		return false;
	}

	/**
	 * Iterate all the chrs in team order. Generally the outer loop iterates the
	 * teams and the inner loop iterates the chrs within that team, but for the
	 * chr's current team the inner loop won't iterate so the outer loop handles
	 * it.
	 *
	 * The chrnums list returned by team_get_chr_ids is an array of chrnums in
	 * team 1 terminated by a -2, then an array of chrnums in team 2 terminated
	 * by -2, and so on.
	 */
	do {
		u8 teamvalue = (1 << team);

		while (*chrnums != -2 && g_Vars.chrdata->team != teamvalue) {
			struct chrdata *chr = chr_find_by_literal_id(*chrnums);

			if (chr && chr->prop
					&& !chr_is_dead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP
					&& chr_compare_teams(g_Vars.chrdata, chr, COMPARE_ENEMIES)
					&& chr != g_Vars.chrdata
					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
					&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0
					&& (chr->hidden & CHRHFLAG_DISGUISED) == 0
					&& chr->team != TEAM_NONCOMBAT
					&& (
						(g_Vars.chrdata->hidden & CHRHFLAG_PSYCHOSISED) == 0
						|| (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0
						|| (chr->hidden & CHRHFLAG_DONTSHOOTME))) {
				f32 distance = chr_get_distance_to_chr(g_Vars.chrdata, chr->chrnum);

				if (distance < maxdist && distance != 0 && distance < closestdist
						&& chr_has_los_to_prop(g_Vars.chrdata, chr->prop)
						&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0) {
					if (g_Vars.chrdata->yvisang == 0) {
						closestdist = distance;
						closesttarg = chr->chrnum;
					} else {
						s16 prevtarget = g_Vars.chrdata->target;
						g_Vars.chrdata->target = prop_get_index_by_chr_id(g_Vars.chrdata, chr->chrnum);

						if (chr_is_vertical_angle_to_target_within(g_Vars.chrdata, g_Vars.chrdata->yvisang)) {
							closestdist = distance;
							closesttarg = chr->chrnum;
						}

						g_Vars.chrdata->target = prevtarget;
					}
				}
			}

			chrnums++;
		}

		// If the inner loop was at the end of the current team,
		// move to the next team
		if (*chrnums == -2) {
			team++;
		}

		// And progress chrnums past the -2 terminator
		chrnums++;
	} while (team < 8);

	if (closesttarg != -1) {
		g_Vars.chrdata->target = prop_get_index_by_chr_id(g_Vars.chrdata, closesttarg);
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 4;
	}

	return false;
}

/**
 * @cmd 0129
 */
bool ai_if_safety_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 *chrnums = team_get_chr_ids(g_Vars.chrdata->team);
	u8 safety = 6;
	u8 numnearby = 0;

	if (chr_get_num_arghs(g_Vars.chrdata) > 0) {
		safety--;
	}

	while (*chrnums != -2) {
		struct chrdata *chr = chr_find_by_literal_id(*chrnums);

		if (chr && chr->model
				&& !chr_is_dead(chr)
				&& chr->actiontype != ACT_DEAD
				&& g_Vars.chrdata->chrnum != chr->chrnum
				&& chr_get_distance_to_chr(g_Vars.chrdata, chr->chrnum) < 3500) {
			numnearby++;
		}

		chrnums++;
	}

	if (numnearby == 0) {
		safety -= 2;
	} else if (numnearby < 3) {
		safety--;
	}

	if (safety < cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 012a
 */
bool ai_if_target_moving_slowly(void)
{
	s32 delta;
	s32 absdelta;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] == 0) {
		delta = chr_get_distance_lost_to_target_in_last_second(g_Vars.chrdata);
	} else {
		struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
		delta = chr_get_distance_lost_to_target_in_last_second(chr);
	}

	absdelta = delta > 0 ? delta : -delta;

	if (absdelta < 50) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 012b
 */
bool ai_if_target_moving_closer(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_get_distance_lost_to_target_in_last_second(g_Vars.chrdata) < -50) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 012c
 */
bool ai_if_target_moving_away(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_get_distance_lost_to_target_in_last_second(g_Vars.chrdata) > 50) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 012f
 */
bool ai012f(void)
{
	if (g_Vars.chrdata->cover >= 0) {
		cover_set_in_use(g_Vars.chrdata->cover, 0);
	}

	g_Vars.aioffset += 2;

	return false;
}

s16 g_GuardQuipBank[][4] = {
	// Voicebox 0
	{ QUIP_ATTACK1,            SFX_M0_CLEAR_SHOT,                SFX_M0_CLEAR_SHOT,                SFX_M0_SHES_MINE                  },
	{ QUIP_ATTACK2,            SFX_M0_OPEN_FIRE,                 SFX_M0_WIPE_HER_OUT,              SFX_M0_WASTE_HER                  },
	{ QUIP_GOTOCOVER1,         SFX_M0_COVER_ME,                  SFX_M0_WATCH_MY_BACK,             SFX_M0_TAKE_COVER                 },
	{ QUIP_GRENADE1,           SFX_M0_M1_LOOK_OUT_LOOK_OUT,      SFX_M0_M1_ITS_A_GRENADE,          SFX_M0_M1_CLEAR_THE_AREA          },
	{ QUIP_RETREAT1,           SFX_M0_GO_TO_PLAN_B,              SFX_M0_GET_THE_HELL_OUT_OF_HERE,  SFX_M0_RETREAT                    },
	{ QUIP_GRENADE2,           SFX_M0_CATCH,                     SFX_M0_EVERYBODY_DOWN,            SFX_M0_GRENADE                    },
	{ QUIP_RETREAT2,           SFX_M0_FALL_BACK,                 SFX_M0_EVERYONE_BACK_OFF,         SFX_M0_WITHDRAW                   },
	{ QUIP_FLANK,              SFX_M0_FLANK_THE_TARGET,          SFX_M0_LETS_SPLIT_UP,             SFX_M0_SURROUND_HER               },
	{ QUIP_SURRENDER,          SFX_M0_DONT_SHOOT_ME,             SFX_M0_I_GIVE_UP,                 SFX_M0_YOU_WIN_I_SURRENDER        },
	{ QUIP_HEARNOISE,          SFX_M0_HEAR_THAT,                 SFX_M0_WHATS_THAT_NOISE,          SFX_M0_HEARD_A_NOISE              },
	{ QUIP_10,                 SFX_0037,                         SFX_0037,                         SFX_0037                          },
	{ QUIP_SEEPLAYER,          SFX_M0_HEY_YOU,                   SFX_M0_INTRUDER_ALERT,            SFX_M0_GOT_A_CONTACT              },
#if VERSION >= VERSION_NTSC_1_0
	{ QUIP_SHOTUNALERT,        SFX_M0_HOLY_SHH,                  SFX_M0_HOLY_SHH,                  SFX_M0_WHAT_THE_HELL              },
#else
	{ QUIP_SHOTUNALERT,        SFX_80F6,                         SFX_80F6,                         SFX_M0_WHAT_THE_HELL              },
#endif
	{ QUIP_INJURED1,           SFX_M0_MEDIC,                     SFX_M0_OW,                        SFX_M0_YOU_SHOT_ME                },
	{ QUIP_INJURED2,           SFX_M0_IM_HIT,                    SFX_M0_IM_TAKING_FIRE,            SFX_M0_TAKING_DAMAGE              },
	{ QUIP_KILLEDPLAYER1,      SFX_M0_GRAB_A_BODY_BAG,           SFX_M0_ONE_FOR_THE_MORGUE,        SFX_M0_REST_IN_PEACE              },
	{ QUIP_WARNFRIENDS,        SFX_M0_INTRUDER_ALERT2,           SFX_M0_WEVE_GOT_TROUBLE,          SFX_M0_WEVE_GOT_PROBLEMS          },
	{ QUIP_GOFORALARM,         SFX_0037,                         SFX_0037,                         SFX_0037                          },
	{ QUIP_SURPRISED,          SFX_M0_WHAT_THE,                  SFX_M0_WHO_THE,                   SFX_M0_WHO_THE                    },
	{ QUIP_INSPECTBODY,        SFX_M0_ARE_YOU_OKAY,              SFX_M0_GOT_A_MAN_DOWN,            SFX_M0_HES_BOUGHT_IT              },
	{ QUIP_20,                 SFX_0037,                         SFX_0037,                         SFX_0037                          },
	{ QUIP_HITPLAYER,          SFX_M0_GIVE_IT_UP,                SFX_M0_SURRENDER_NOW,             SFX_M0_TAKE_THAT                  },
	{ QUIP_MISSEDPLAYER1,      SFX_M0_DAMN_IT_MISSED,            SFX_M0_DAMN_IT_MISSED,            SFX_M0_HOW_DID_I_MISS             },
	{ QUIP_MISSEDPLAYER2,      SFX_M0_GODS_SAKE_SOMEONE_HIT_HER, SFX_M0_GODS_SAKE_SOMEONE_HIT_HER, SFX_M0_SHES_A_TRICKY_ONE          },
	{ QUIP_GOTOCOVER2,         SFX_M0_TAKE_COVER_028D,           SFX_M0_ILL_COVER_YOU,             SFX_M0_GET_DOWN                   },
	{ QUIP_DIE,                SFX_M0_YOU_BITCH,                 SFX_M0_OH_MY_GOD,                 SFX_M0_SHE_GOT_ME                 },
	{ QUIP_26,                 SFX_0037,                         SFX_0037,                         SFX_0037                          },
	{ QUIP_SEARCHSUCCESS,      SFX_M0_I_SEE_HER,                 SFX_M0_THERE_SHE_IS,              SFX_M0_THERE_MOVEMENT             },
	{ QUIP_SEEEYESPY,          SFX_M0_WHAT_THE_HELL_8167,        SFX_M0_HELLO_THERE,               SFX_M0_WHATS_THIS                 },
	{ QUIP_GREETING,           SFX_M0_HOWS_THINGS,               SFX_M0_HEY_THERE,                 SFX_M0_HI_HOW_ARE_YOU             },
	{ QUIP_ASKWEAPON1,         MP3_M0_WHERE_DID_YOU_GET_THAT,    MP3_M0_SHOULD_YOU_HAVE_THAT,      MP3_M0_WHAT_ARE_YOU_DOING         },
	{ QUIP_ASKWEAPON2,         SFX_0037,                         MP3_M0_DONT_POINT_THAT_AT_ME,     MP3_M0_WATCH_WHERE_YOURE_POINTING },
	{ QUIP_UNCOVERDISGUISE1,   MP3_M0_IMPOSTER,                  MP3_M0_IMPOSTER,                  MP3_M0_ITS_A_SPY                  },
	{ QUIP_LOSTGUN,            SFX_M0_MY_GUN,                    SFX_M0_MY_GUN,                    SFX_M0_MY_GUN                     },
	{ QUIP_GOFORALARM,         SFX_M0_TRIGGER_THE_ALARM,         SFX_M0_TRIGGER_THE_ALARM,         SFX_M0_TRIGGER_THE_ALARM          },
	{ QUIP_SEARCHFAIL,         SFX_M0_IM_SURE_I_HEARD_A_NOISE,   SFX_M0_IM_SURE_I_HEARD_A_NOISE,   SFX_M0_HEARING_THINGS             },
	{ QUIP_ATTACK3,            SFX_M0_CLEAR_SHOT,                SFX_M0_CLEAR_SHOT,                SFX_M0_OPEN_FIRE                  },
	{ QUIP_ATTACK4,            SFX_M0_CLEAR_SHOT,                SFX_M0_OPEN_FIRE,                 SFX_M0_OPEN_FIRE                  },
	{ QUIP_KILLEDPLAYER2,      SFX_M0_GRAB_A_BODY_BAG,           SFX_M0_ONE_FOR_THE_MORGUE,        SFX_M0_REST_IN_PEACE              },
	{ QUIP_GUNJAMMED,          SFX_M0_MY_GUN,                    SFX_M0_MY_GUN,                    SFX_M0_MY_GUN                     },
	{ QUIP_UNCOVEREDDISGUISE2, MP3_M0_ITS_A_SPY,                 MP3_M0_ITS_A_SPY,                 MP3_M0_ITS_A_SPY                  },
	// Voicebox 1
	{ QUIP_ATTACK1,            SFX_M1_LAST_MISTAKE,            SFX_M1_WHAT_ARE_YOU_WAITING_FOR, SFX_M1_BRING_IT_ON                },
	{ QUIP_ATTACK2,            SFX_M1_TAKE_HER_DOWN,           SFX_M1_EVERYBODY_GET_HER,        SFX_M1_ATTACK                     },
	{ QUIP_GOTOCOVER1,         SFX_M1_COVER_MY_ASS,            SFX_M1_COVER_ME_NOW,             SFX_M1_IM_GOING_FOR_COVER         },
	{ QUIP_GRENADE1,           SFX_M0_M1_LOOK_OUT_LOOK_OUT,    SFX_M0_M1_ITS_A_GRENADE,         SFX_M0_M1_CLEAR_THE_AREA          },
	{ QUIP_RETREAT1,           SFX_M1_SHES_TOO_GOOD_RUN,       SFX_M1_GET_SOME_BACKUP,          SFX_M1_EVACUATE_THE_AREA          },
	{ QUIP_GRENADE2,           SFX_M1_CATCH_THIS,              SFX_M1_HERE_KEEP_IT,             SFX_M1_GRENADE                    },
	{ QUIP_RETREAT2,           SFX_M1_WITHDRAW,                SFX_M1_FALL_BACK,                SFX_M1_EVERYONE_GET_BACK          },
	{ QUIP_FLANK,              SFX_M1_SURROUND_HER,            SFX_M1_SPREAD_OUT,               SFX_M1_SPLIT_UP                   },
	{ QUIP_SURRENDER,          SFX_M1_PLEASE_DONT,             SFX_M1_DONT_SHOOT,               SFX_M1_IM_ONLY_DOING_MY_JOB       },
	{ QUIP_HEARNOISE,          SFX_M1_THAT_SOUNDED_LIKE,       SFX_M1_GUNFIRE,                  SFX_M1_SOMEONES_SHOOTING          },
	{ QUIP_10,                 SFX_0037,                       SFX_0037,                        SFX_0037                          },
	{ QUIP_SEEPLAYER,          SFX_M1_COME_HERE,               SFX_M1_THERES_SOMEONE_HERE,      SFX_M1_GET_HER                    },
	{ QUIP_SHOTUNALERT,        SFX_M1_WHOA,                    SFX_M1_MY_GOD,                   SFX_M1_IS_THAT_A_BULLET           },
	{ QUIP_INJURED1,           SFX_M1_OH_MY_GOD,               SFX_M1_IM_HIT_IM_HIT,            SFX_M1_IM_BLEEDING                },
	{ QUIP_INJURED2,           SFX_M1_OH_GOD_IM_HIT,           SFX_M1_HELP_ME_OUT,              SFX_M1_IM_IN_TROUBLE              },
	{ QUIP_KILLEDPLAYER1,      SFX_0037,                       SFX_0037,                        SFX_0037                          },
	{ QUIP_WARNFRIENDS,        SFX_M1_M2_LOOK_OUT_SHES_COMING, SFX_M1_M2_TAKE_COVER,            SFX_M1_M2_LOOK_OUT_LOOK_OUT       },
	{ QUIP_GOFORALARM,         SFX_0037,                       SFX_0037,                        SFX_0037                          },
	{ QUIP_SURPRISED,          SFX_M1_HOLY,                    SFX_M1_WHAT_THE_HELL,            SFX_M1_WHA                        },
#if VERSION >= VERSION_NTSC_1_0
	{ QUIP_INSPECTBODY,        SFX_M1_NOOO,                    SFX_M1_OH_GOD_HES_DEAD,          SFX_M1_HES_GONE                   },
#else
	{ QUIP_INSPECTBODY,        SFX_0313,                       SFX_M1_NOOO,                     SFX_M1_HES_GONE                   },
#endif
	{ QUIP_20,                 SFX_M1_M2_LOOK_OUT_SHES_COMING, SFX_M1_M2_TAKE_COVER,            SFX_M1_M2_LOOK_OUT_LOOK_OUT       },
	{ QUIP_HITPLAYER,          SFX_M1_IM_JUST_TOO_GOOD,        SFX_M1_YEAH_BABY,                SFX_M1_YEAH_BABY                  },
	{ QUIP_MISSEDPLAYER1,      SFX_M1_BLOODY_STUPID_GUN,       SFX_M1_MY_GUN_ITS_USELESS,       SFX_M1_DAMN_IT                    },
	{ QUIP_MISSEDPLAYER2,      SFX_M1_STOP_DODGING,            SFX_M1_SOMEONE_HIT_HER,          SFX_M1_DAMN_SHES_GOOD             },
	{ QUIP_GOTOCOVER2,         SFX_M1_GO_FOR_IT,               SFX_M1_GO_GO_GO,                 SFX_M1_RUN                        },
#if VERSION >= VERSION_NTSC_1_0
	{ QUIP_DIE,                SFX_M1_SCREAM,                  SFX_M1_WHY_ME,                   SFX_M1_CHOKING                    },
#else
	{ QUIP_DIE,                SFX_034C,                       SFX_M1_WHY_ME,                   SFX_M1_CHOKING                    },
#endif
	{ QUIP_26,                 SFX_M1_OUTSTANDING,             SFX_M1_IM_JUST_TOO_GOOD,         SFX_M1_YEEHAH_GOT_ONE             },
	{ QUIP_SEARCHSUCCESS,      SFX_M1_OVER_THERE,              SFX_M1_HALT,                     SFX_M1_FREEZE                     },
	{ QUIP_SEEEYESPY,          SFX_M1_WHAT_IS_IT,              SFX_M1_HOW_DID_THAT_GET_HERE,    SFX_M1_DONT_TOUCH_IT              },
	{ QUIP_GREETING,           SFX_M1_HI_THERE,                SFX_M1_HI_THERE,                 SFX_M1_HOWS_THINGS                },
	{ QUIP_ASKWEAPON1,         MP3_M1_WHERE_ARE_YOU_TAKING,    MP3_M1_WHERE_ARE_YOU_TAKING,     MP3_M1_GET_THAT_FIREARM_APPROVED  },
	{ QUIP_ASKWEAPON2,         MP3_M1_WATCH_WHAT_YOURE_DOING,  MP3_M1_WATCH_WHAT_YOURE_DOING,   MP3_M1_BE_CAREFUL                 },
	{ QUIP_UNCOVERDISGUISE1,   MP3_M1_STOP_RIGHT_THERE,        MP3_M1_STOP_RIGHT_THERE,         MP3_M1_DROP_THE_GUN               },
	{ QUIP_LOSTGUN,            SFX_M1_M2_GEEZ,                 SFX_M1_M2_GEEZ,                  SFX_M1_M2_GEEZ                    },
	{ QUIP_GOFORALARM,         SFX_M1_WARN_THE_OTHERS,         SFX_M1_WARN_THE_OTHERS,          SFX_M1_WARN_THE_OTHERS            },
	{ QUIP_SEARCHFAIL,         SFX_M1_I_CANT_SEE_ANYBODY,      SFX_M1_THERES_NO_ONE_HERE,       SFX_M1_THERES_NO_ONE_HERE         },
	{ QUIP_ATTACK3,            SFX_M1_LAST_MISTAKE,            SFX_M1_WHAT_ARE_YOU_WAITING_FOR, SFX_M1_BRING_IT_ON                },
	{ QUIP_ATTACK4,            SFX_M1_BRING_IT_ON,             SFX_M1_ATTACK,                   SFX_M1_ATTACK                     },
	{ QUIP_KILLEDPLAYER2,      SFX_M1_IM_JUST_TOO_GOOD,        SFX_M1_YEEHAH_GOT_ONE,           SFX_M1_ANOTHER_ONE_BITES_THE_DUST },
	{ QUIP_GUNJAMMED,          SFX_M1_BLOODY_STUPID_GUN,       SFX_M1_MY_GUN_ITS_USELESS,       SFX_M1_DAMN_IT                    },
	{ QUIP_UNCOVEREDDISGUISE2, MP3_M1_STOP_RIGHT_THERE,        MP3_M1_STOP_RIGHT_THERE,         MP3_M1_STOP_RIGHT_THERE           },
	// Voicebox 2
	{ QUIP_ATTACK1,            SFX_M2_COME_ON_MAN2,                    SFX_M2_DIE,                             SFX_M2_TAKE_THIS                        },
	{ QUIP_ATTACK2,            SFX_M2_MOVE_IN,                         SFX_M2_YOURE_OUT_OF_YOUR_LEAGUE,        SFX_M2_LET_HER_HAVE_IT                  },
	{ QUIP_GOTOCOVER1,         SFX_M2_HELP_ME_OUT_HERE,                SFX_M2_HEY_DISTRACT_HER,                SFX_M2_KEEP_HER_OCCUPIED                },
	{ QUIP_GRENADE1,           SFX_M2_GET_BACK_QUICK,                  SFX_M2_WERE_GONNA_DIE,                  SFX_M2_GOD_RUN                          },
	{ QUIP_RETREAT1,           SFX_M2_RETREAT,                         SFX_M2_LETS_GET_THE_HELL_OUT_OF_HERE,   SFX_M2_GET_BACK_GET_BACK                },
	{ QUIP_GRENADE2,           SFX_M2_FIRE_IN_THE_HOLE,                SFX_M2_HERES_A_LITTLE_PRESENT_FOR_YA,   SFX_M2_TRY_THIS_FOR_SIZE                },
	{ QUIP_RETREAT2,           SFX_M2_GET_OUT_OF_THE_WAY,              SFX_M2_FALL_BACK,                       SFX_M2_MOVE_OUT                         },
	{ QUIP_FLANK,              SFX_M2_TEAM_UP_GUYS,                    SFX_M2_COME_ON_AROUND_THE_SIDE,         SFX_M2_SCATTER                          },
	{ QUIP_SURRENDER,          SFX_M2_I_DONT_LIKE_THIS_ANY_MORE,       SFX_M2_DONT_HURT_ME,                    SFX_M2_YOU_WIN_I_GIVE_UP                },
	{ QUIP_HEARNOISE,          SFX_M2_LISTEN_GUNSHOTS,                 SFX_M2_LISTEN_GUNSHOTS,                 SFX_M2_SOMEONES_NEARBY                  },
	{ QUIP_10,                 SFX_0037,                               SFX_0037,                               SFX_0037                                },
	{ QUIP_SEEPLAYER,          SFX_M2_TARGET_SIGHTED,                  SFX_M2_COME_ON_MAN,                     SFX_M2_GOD_DAMN_IT                      },
	{ QUIP_SHOTUNALERT,        SFX_M2_THAT_WAS_CLOSE,                  SFX_M2_HOLY_MOLY,                       SFX_M2_AY_CARAMBA                       },
	{ QUIP_INJURED1,           SFX_M2_GEEZ_THAT_HURT,                  SFX_M2_WHY_YOU,                         SFX_M2_WHY_YOU                          },
	{ QUIP_INJURED2,           SFX_M2_IM_INJURED,                      SFX_M2_IM_HIT_IM_HIT,                   SFX_M2_DAMN_IT_IM_TAKING_FIRE           },
	{ QUIP_KILLEDPLAYER1,      SFX_0037,                               SFX_0037,                               SFX_0037                                },
	{ QUIP_WARNFRIENDS,        SFX_M2_WATCH_OUT,                       SFX_M2_HELP_ME_OUT,                     SFX_M2_WEVE_GOT_AN_INTRUDER             },
	{ QUIP_GOFORALARM,         SFX_0037,                               SFX_0037,                               SFX_0037                                },
	{ QUIP_SURPRISED,          SFX_M2_HOW_THE,                         SFX_M2_HEY,                             SFX_M2_STOP                             },
	{ QUIP_INSPECTBODY,        SFX_M2_BODY_COUNTS_TOO_HIGH,            SFX_M2_I_NEVER_LIKED_HIM_ANYWAY,        SFX_M2_THAT_WAS_MY_BEST_FRIEND          },
	{ QUIP_20,                 SFX_M1_M2_LOOK_OUT_SHES_COMING,         SFX_M1_M2_TAKE_COVER,                   SFX_M1_M2_LOOK_OUT_LOOK_OUT             },
	{ QUIP_HITPLAYER,          SFX_M2_SURRENDER_OR_DIE,                SFX_M2_I_HAVE_YOU_NOW,                  SFX_M2_YOU_WANT_BEAT_ME                 },
	{ QUIP_MISSEDPLAYER1,      SFX_M2_DAMN_MISSED_AGAIN,               SFX_M2_I_DONT_BELIEVE_IT,               SFX_M2_DAMN_YOU                         },
	{ QUIP_MISSEDPLAYER2,      SFX_M2_HELL_SHES_GOOD,                  SFX_M2_STOP_MOVING,                     SFX_M2_NO_ESCAPE_FOR_YOU                },
	{ QUIP_GOTOCOVER2,         SFX_M2_MOVE_IT_MOVE_IT,                 SFX_M2_GET_TO_COVER_NOW,                SFX_M2_RUN_FOR_IT                       },
#if VERSION >= VERSION_NTSC_1_0
	{ QUIP_DIE,                SFX_M2_NOOO,                            SFX_M2_OH_GOD_IM_DYING,                 SFX_M2_I_DONT_WANT_TO_DIE               },
#else
	{ QUIP_DIE,                SFX_0411,                               SFX_M2_OH_GOD_IM_DYING,                 SFX_M2_I_DONT_WANT_TO_DIE               },
#endif
	{ QUIP_26,                 SFX_M2_IM_THE_MAN,                      SFX_M2_BOY_THAT_WAS_CLOSE,              SFX_M2_DID_YOU_SEE_THAT                 },
	{ QUIP_SEARCHSUCCESS,      SFX_M2_GET_HER,                         SFX_M2_THERE_ATTACK,                    SFX_M2_HEY_YOU_STOP                     },
	{ QUIP_SEEEYESPY,          SFX_M2_IS_IT_DANGEROUS,                 SFX_M2_DONT_MOVE,                       SFX_M2_STAY_BACK                        },
	{ QUIP_GREETING,           SFX_M2_HELLO,                           SFX_M2_HELLO,                           SFX_M2_HEY_WHATS_UP                     },
	{ QUIP_ASKWEAPON1,         MP3_M2_DO_YOU_HAVE_PERMISSION_FOR_THAT, MP3_M2_DO_YOU_HAVE_PERMISSION_FOR_THAT, MP3_M2_WHAT_ARE_YOU_DOING               },
	{ QUIP_ASKWEAPON2,         MP3_M2_HEY_THATS_DANGEROUS,             MP3_M2_HEY_THATS_DANGEROUS,             MP3_M2_WATCH_IT_THAT_THING_COULD_GO_OFF },
	{ QUIP_UNCOVERDISGUISE1,   MP3_M2_PUT_YOUR_HANDS_UP,               MP3_M2_PUT_YOUR_HANDS_UP,               MP3_M2_ITS_A_TERRORIST                  },
	{ QUIP_LOSTGUN,            SFX_M1_M2_GEEZ,                         SFX_M1_M2_GEEZ,                         SFX_M1_M2_GEEZ                          },
	{ QUIP_GOFORALARM,         SFX_M2_ACTIVATE_THE_ALARM,              SFX_M2_ACTIVATE_THE_ALARM,              SFX_M2_ACTIVATE_THE_ALARM               },
	{ QUIP_SEARCHFAIL,         SFX_M2_I_BET_THIS_IS_ANOTHER_DRILL,     SFX_M2_I_BET_THIS_IS_ANOTHER_DRILL,     SFX_M2_ANOTHER_FALSE_ALARM              },
	{ QUIP_ATTACK3,            SFX_M2_COME_ON_MAN2,                    SFX_M2_DIE,                             SFX_M2_TAKE_THIS                        },
	{ QUIP_ATTACK4,            SFX_M2_DIE,                             SFX_M2_YOURE_OUT_OF_YOUR_LEAGUE,        SFX_M2_YOURE_OUT_OF_YOUR_LEAGUE         },
	{ QUIP_KILLEDPLAYER2,      SFX_M2_IM_THE_MAN,                      SFX_M2_ITS_ALL_OVER_FOR_THIS_ONE,       SFX_M2_DID_YOU_SEE_THAT                 },
	{ QUIP_GUNJAMMED,          SFX_M2_GOD_DAMN_IT,                     SFX_M2_I_DONT_BELIEVE_IT,               SFX_M2_GOD_DAMN_IT                      },
	{ QUIP_UNCOVEREDDISGUISE2, MP3_M2_ITS_A_TERRORIST,                 MP3_M2_ITS_A_TERRORIST,                 MP3_M2_ITS_A_TERRORIST                  },
	// Voicebox 3 (female)
	{ QUIP_ATTACK1,            SFX_F_COME_ON,            SFX_F_COME_ON,            SFX_F_COME_ON           },
	{ QUIP_ATTACK2,            SFX_0037,                 SFX_F_EVERYONE_GET_HER,   SFX_F_ATTACK            },
	{ QUIP_GOTOCOVER1,         SFX_F_COVER_ME,           SFX_0037,                 SFX_F_TAKE_COVER        },
	{ QUIP_GRENADE1,           SFX_F_LOOK_OUT,           SFX_F_ITS_A_GRENADE,      SFX_F_ITS_A_GRENADE     },
	{ QUIP_RETREAT1,           SFX_F_GET_REINFORCEMENTS, SFX_F_EVACUATE_THE_AREA,  SFX_F_RETREAT           },
	{ QUIP_GRENADE2,           SFX_F_CATCH_THIS,         SFX_F_TIME_TO_DIE,        SFX_0037                },
	{ QUIP_RETREAT2,           SFX_F_WITHDRAW,           SFX_F_WITHDRAW,           SFX_F_FALL_BACK         },
	{ QUIP_FLANK,              SFX_0037,                 SFX_F_SPREAD_OUT,         SFX_F_SPLIT_UP          },
	{ QUIP_SURRENDER,          SFX_F_PLEASE_DONT,        SFX_F_PLEASE_DONT,        SFX_F_DONT_SHOOT        },
	{ QUIP_HEARNOISE,          SFX_0037,                 SFX_F_0389,               SFX_F_SOMEONES_SHOOTING },
	{ QUIP_10,                 0,                        0,                        0                       },
	{ QUIP_SEEPLAYER,          SFX_F_GET_HER,            SFX_F_HEY_YOU_COME_HERE,  SFX_0037                },
	{ QUIP_SHOTUNALERT,        SFX_F_UNDER_FIRE,         SFX_0037,                 SFX_F_WERE_UNDER_FIRE   },
	{ QUIP_INJURED1,           SFX_0037,                 SFX_F_IM_WOUNDED,         SFX_F_HELP_ME_OUT       },
	{ QUIP_INJURED2,           SFX_F_IM_WOUNDED,         SFX_F_HELP_ME_OUT,        SFX_F_IM_IN_TROUBLE     },
	{ QUIP_KILLEDPLAYER1,      0,                        0,                        0                       },
	{ QUIP_WARNFRIENDS,        SFX_F_TARGET_ATTACKING,   SFX_F_UNDER_FIRE,         SFX_0037                },
	{ QUIP_GOFORALARM,         SFX_F_GET_REINFORCEMENTS, SFX_F_EVACUATE_THE_AREA,  SFX_F_RETREAT           },
	{ QUIP_SURPRISED,          SFX_0037,                 SFX_F_HEY,                SFX_F_HUH               },
	{ QUIP_INSPECTBODY,        SFX_F_UNIT_DOWN,          SFX_F_UNIT_DOWN,          SFX_F_UNIT_DOWN         },
	{ QUIP_20,                 SFX_F_TARGET_ATTACKING,   SFX_F_UNDER_FIRE,         SFX_F_WERE_UNDER_FIRE   },
	{ QUIP_HITPLAYER,          SFX_F_DID_THAT_HURT,      SFX_F_YOU_WANT_SOME_MORE, SFX_0037                },
	{ QUIP_MISSEDPLAYER1,      SFX_F_THIS_GUNS_USELESS,  SFX_0037,                 SFX_F_STAND_STILL       },
#if VERSION >= VERSION_NTSC_1_0
	{ QUIP_MISSEDPLAYER2,      SFX_F_STAND_STILL,        SFX_F_SOMEONE_HIT_HER,    SFX_F_DAMN_SHES_GOOD    },
#else
	{ QUIP_MISSEDPLAYER2,      SFX_F_STAND_STILL,        SFX_F_SOMEONE_HIT_HER,    SFX_M1_SCREAM           },
#endif
	{ QUIP_GOTOCOVER2,         SFX_F_GO_FOR_IT,          SFX_0037,                 SFX_F_RUN               },
	{ QUIP_DIE,                SFX_F_WHY_ME,             SFX_F_NOO,                SFX_F_MY_GOD            },
	{ QUIP_26,                 SFX_F_IM_JUST_TOO_GOOD,   SFX_0037,                 SFX_F_SUCH_A_WASTE      },
	{ QUIP_SEARCHSUCCESS,      SFX_F_GET_HER,            SFX_F_HEY_YOU_COME_HERE,  SFX_0037                },
	{ QUIP_SEEEYESPY,          0,                        0,                        0                       },
	{ QUIP_GREETING,           SFX_0037,                 SFX_F_COME_ON,            SFX_0037                },
	{ QUIP_ASKWEAPON1,         SFX_0037,                 SFX_F_COME_ON,            SFX_0037                },
	{ QUIP_ASKWEAPON2,         SFX_0037,                 SFX_F_COME_ON,            SFX_0037                },
	{ QUIP_UNCOVERDISGUISE1,   SFX_0037,                 SFX_F_COME_ON,            SFX_0037                },
	{ QUIP_LOSTGUN,            SFX_F_HEY,                SFX_F_HUH,                SFX_F_HEY               },
	{ QUIP_GOFORALARM,         SFX_F_GET_REINFORCEMENTS, SFX_F_FALL_BACK,          SFX_F_EVACUATE_THE_AREA },
	{ QUIP_SEARCHFAIL,         0,                        0,                        0                       },
	{ QUIP_ATTACK3,            SFX_F_COME_ON,            SFX_F_COME_ON,            SFX_F_ATTACK            },
	{ QUIP_ATTACK4,            SFX_F_ATTACK,             SFX_F_ATTACK,             SFX_F_COME_ON           },
	{ QUIP_KILLEDPLAYER2,      SFX_F_GET_A_CLEANER,      SFX_F_IM_JUST_TOO_GOOD,   SFX_F_SUCH_A_WASTE      },
	{ QUIP_GUNJAMMED,          SFX_F_THIS_GUNS_USELESS,  SFX_F_THIS_GUNS_USELESS,  SFX_F_THIS_GUNS_USELESS },
	{ QUIP_UNCOVEREDDISGUISE2, 0,                        0,                        0                       },
};

s16 g_SpecialQuipBank[][4] = {
	{ 0,  MP3_CASS_HOW_DARE_YOU_DISTURB_ME,     MP3_CASS_YOU_WILL_REGRET,               MP3_CASS_LEAVE_NOW                 },
	{ 1,  MP3_SEC_PLEASE_DONT_KILL_ME,          MP3_SEC_DONT_SHOOT,                     MP3_SEC_PLEASE_DONT_KILL_ME        },
	{ 2,  SFX_DRCAROLL_COME_ON,                 SFX_DRCAROLL_TAKING_YOUR_TIME,          SFX_DRCAROLL_GET_OUT_OF_HERE       },
	{ 3,  SFX_DRCAROLL_KNOW_WHAT_YOURE_DOING,   SFX_DRCAROLL_0249,                      SFX_DRCAROLL_GOING_TO_THE_HELIPAD  },
	{ 4,  SFX_DRCAROLL_STOP_THAT,               SFX_DRCAROLL_WHAT,                      SFX_ARGH_DRCAROLL_0240             },
	{ 5,  SFX_ARGH_DRCAROLL_024C,               SFX_DRCAROLL_QUITE_ENOUGH,              SFX_ARGH_DRCAROLL_0251             },
	{ 6,  SFX_DRCAROLL_I_CANT_MAKE_IT,          SFX_DRCAROLL_YOU_WERE_SUPPOSED,         SFX_DRCAROLL_SYSTEMS_FAILURE       },
	{ 7,  SFX_DRCAROLL_OH_CRIKEY,               SFX_DRCAROLL_GOODNESS_GRACIOUS,         SFX_DRCAROLL_DONT_THEY_KNOW        },
	{ 8,  MP3_K7_IM_NOT_SURE,                   MP3_K7_ONE_MORE_TIME,                   MP3_K7_I_DUNNO                     },
	{ 9,  MP3_SCI_AND_AGAIN,                    MP3_SCI_TRY_IT_NOW,                     MP3_SCI_AND_AGAIN                  },
	{ 10, MP3_SCI_WHAT_ARE_YOU_DOING,           MP3_SCI_HAVENT_SEEN_YOU,                SFX_SCI_WHO_THE_HELL_ARE_YOU       },
	{ 11, MP3_JO_SHUT_DOWN_EXPERIMENTS,         MP3_JO_PULL_THE_PLUG,                   MP3_JO_SWITCH_THIS_THING_OFF       },
	{ 12, MP3_SCI_ILL_SHUT_IT_DOWN,             MP3_SCI_PLEASE_DONT_HURT_ME,            MP3_SCI_ALLOW_ME_TO_ASSIST_YOU     },
	{ 13, MP3_SCI_MY_EXPERIMENTS,               MP3_SCI_EXPERIMENT_IS_DOWN,             MP3_SCI_LEAVE_THIS_AREA            },
	{ 14, MP3_SCI_SECURITY,                     MP3_SCI_IM_CALLING_SECURITY,            MP3_SCI_ACCIDENTS_WILL_HAPPEN      },
	{ 15, MP3_SCI_HOW_DID_THAT_HAPPEN,          MP3_SCI_OFF_ALREADY,                    MP3_SCI_HAVE_YOU_BEEN_TAMPERING    },
	{ 16, MP3_SCI_SOMEONES_BROKEN_MY_EQUIPMENT, MP3_SCI_WHATS_HAPPENED_TO_THE_TERMINAL, MP3_SCI_YOU_VANDAL                 },
	{ 17, SFX_ARGH_FEMALE_000D,                 SFX_ARGH_FEMALE_000D,                   SFX_ARGH_FEMALE_000D               },
	{ 18, SFX_M0_HOWS_THINGS,                   SFX_M0_HEY_THERE,                       SFX_M0_HI_HOW_ARE_YOU              },
	{ 19, MP3_M0_WHERE_DID_YOU_GET_THAT,        MP3_M0_SHOULD_YOU_HAVE_THAT,            MP3_M0_WHAT_ARE_YOU_DOING          },
	{ 20, SFX_0037,                             MP3_M0_DONT_POINT_THAT_AT_ME,           MP3_M0_WATCH_WHERE_YOURE_POINTING  },
	{ 21, MP3_M0_IMPOSTER,                      MP3_M0_IMPOSTER,                        MP3_M0_ITS_A_SPY                   },
	{ 22, SFX_CIV_GREETINGS_CITIZEN,            SFX_CIV_HEY_SUGAR_WANNA_PARTY,          SFX_CIV_HEY_BABY                   },
	{ 23, SFX_CIV_HOWS_IT_GOING,                SFX_CIV_TAKE_IT_EASY,                   SFX_CIV_WHISTLE                    },
	{ 24, SFX_CIV_OH_MY_GOD,                    SFX_CIV_I_DONT_WANT_ANY_TROUBLE,        SFX_CIV_TAKE_THE_WALLET            },
	{ 25, SFX_CIV_THERES_A_MANIAC,              SFX_CIV_QUICK_DOWN_THERE,               SFX_CIV_GET_ME_OUT_OF_HERE         },
	{ 26, SFX_CIV_GUNS_DONT_SCARE_ME,           SFX_CIV_KEEP_AWAY_FROM_THIS_CAR,        SFX_CIV_KEEP_AWAY_FROM_THIS_CAR    },
	{ 27, SFX_FBI_WE_HAVE_AN_INTRUDER,          SFX_FBI_CODE_2_SITUATION,               SFX_FBI_REQUEST_BACKUP_IMMEDIATELY },
	{ 28, SFX_SHOULD_HAVE_COME_HERE_GIRL,       SFX_SECURE_THE_PERIMETER,               SFX_WERE_TAKING_OVER               },
	{ 29, SFX_FBI_WE_HAVE_AN_INTRUDER,          SFX_FBI_CODE_2_SITUATION,               SFX_FBI_REQUEST_BACKUP_IMMEDIATELY },
	{ 30, SFX_FBI_WE_HAVE_AN_INTRUDER,          SFX_FBI_CODE_2_SITUATION,               SFX_FBI_REQUEST_BACKUP_IMMEDIATELY },
	{ 31, MP3_ROBOT_STOP_WHERE_YOU_ARE,         MP3_ROBOT_STOP_WHERE_YOU_ARE,           MP3_ROBOT_STOP_WHERE_YOU_ARE       },
	{ 32, MP3_COME_BACK_LATER_IM_BUSY,          MP3_GO_AWAY,                            MP3_LOOK_I_CANT_HELP_YOU           },
	{ 33, MP3_PRES_STOP_SHOOTING,               MP3_PRES_YOU_SURE_THIS_IS_THE_WAY,      MP3_PRES_WHY_ARE_THEY_SHOOTING     },
	{ 34, SFX_CIV_GREETINGS_CITIZEN,            SFX_CIV_HEY_SUGAR_WANNA_PARTY,          0                                  },
	{ 35, SFX_CIV_HOWS_IT_GOING,                SFX_CIV_TAKE_IT_EASY,                   0                                  },
	{ 36, SFX_CIV_OH_MY_GOD,                    SFX_CIV_I_DONT_WANT_ANY_TROUBLE,        MP3_SEC_PLEASE_DONT_KILL_ME        },
	{ 37, SFX_CIV_THERES_A_MANIAC,              SFX_CIV_QUICK_DOWN_THERE,               0                                  },
	{ 38, SFX_ELVIS_INTERGALACTIC_PEACE,        SFX_ELVIS_EAT_HOT_LEAD_WEIRDOS,         SFX_ELVIS_KISS_MY_ALIEN_BUTT       },
	{ 39, SFX_ELVIS_ILL_KICK_YOUR_ASS,          SFX_ELVIS_FOR_YOUR_OWN_GOOD,            SFX_ELVIS_YOU_DARE_SHOOT_AT_ME     },
	{ 40, SFX_ELVIS_DONT_MESS_WITH_THE_MAIAN,   SFX_ELVIS_IM_BAD,                       SFX_ELVIS_HEHE                     },
	{ 41, SFX_ELVIS_ALL_GOING_WRONG,            SFX_ELVIS_ALL_GOING_WRONG,              SFX_ELVIS_WATCH_THE_SUIT           },
	{ 42, MP3_M2_ITS_A_TERRORIST,               MP3_M0_ITS_A_SPY,                       MP3_M1_STOP_RIGHT_THERE            },
	{ 43, MP3_CASS_HOW_DARE_YOU_DISTURB_ME,     MP3_CASS_LEAVE_NOW,                     MP3_CASS_LEAVE_NOW                 },
	{ 44, SFX_ELVIS_HEHE,                       SFX_ELVIS_HEHE,                         SFX_ELVIS_HEHE                     },
	{ 45, MP3_ROBOT_ALERT_UNDER_ATTACK,         MP3_ROBOT_ALERT_UNDER_ATTACK,           MP3_ROBOT_ALERT_UNDER_ATTACK       },
};

s16 g_QuipTexts[][4] = {
	{  1, L_AME_083, L_AME_084, L_AME_085 }, // "How dare you disturb me!", "You will regret this intrusion, girl!", "If I were you, I'd leave...NOW!"
	{  2, L_AME_086, L_AME_087, L_AME_086 }, // "Please don't kill me!", "Don't shoot!"
	{  3, L_EAR_064, L_EAR_065, L_EAR_066 }, // "What are you doing in my lab?", "I haven't seen you before...", "Who the hell are you?"
	{  4, L_EAR_067, L_EAR_068, L_EAR_069 }, // "Shut down the experiment.", "Pull the plug on that, NOW.", "Switch this thing off."
	{  5, L_EAR_070, L_EAR_071, L_EAR_072 }, // "I'll shut it down.", "Please don't hurt me.", "Allow me to assist you."
	{  6, L_EAR_073, L_EAR_074, L_EAR_075 }, // "My experiments!", "There the experiment is down.", "Leave this area NOW!"
	{  7, L_EAR_076, L_EAR_077, L_EAR_078 }, // "Security!", "I'm calling security.", "Accidents will happen."
	{  8, L_EAR_079, L_EAR_080, L_EAR_081 }, // "How did that happen?", "Looks like it's off already.", "Have you been tampering with this?"
	{  9, L_EAR_082, L_EAR_083, L_EAR_084 }, // "Someone's broken my equipment.", "What's happened to the terminal?", "You vandal - you've broken it."
	{ 10, L_WAX_010, L_WAX_012, L_WAX_012 }, // "How dare you disturb me!", "If I were you, I'd leave... NOW!"
};

s16 g_SkedarQuipBank[][4] = {
	{ 1, SFX_SKEDAR_ROAR_0529, SFX_SKEDAR_ROAR_052A, SFX_SKEDAR_ROAR_052B },
	{ 2, SFX_SKEDAR_ROAR_052D, SFX_SKEDAR_ROAR_052E, SFX_SKEDAR_ROAR_052F },
	{ 3, SFX_SKEDAR_ROAR_0530, SFX_SKEDAR_ROAR_0530, SFX_SKEDAR_ROAR_0531 },
	{ 1, SFX_SKEDAR_ROAR_0532, SFX_SKEDAR_ROAR_0533, SFX_SKEDAR_ROAR_0534 },
	{ 2, SFX_SKEDAR_ROAR_0536, SFX_SKEDAR_ROAR_0537, SFX_SKEDAR_ROAR_0538 },
	{ 3, SFX_SKEDAR_ROAR_0539, SFX_SKEDAR_ROAR_0539, SFX_SKEDAR_ROAR_053A },
	{ 0 },
};

s16 g_MaianQuipBank[][4] = {
	{ 1, SFX_MAIAN_05E2,      SFX_MAIAN_05E3,      SFX_MAIAN_05E4      },
	{ 2, SFX_MAIAN_05E5,      SFX_MAIAN_05E6,      SFX_MAIAN_05E7      },
	{ 3, SFX_ARGH_MAIAN_05DF, SFX_ARGH_MAIAN_05E0, SFX_ARGH_MAIAN_05E1 },
	{ 0 },
};

#define AUDIO_NEEDS_MOVEMENT(soundnum) \
		((soundnum) == SFX_M2_STOP_MOVING \
		|| (soundnum) == SFX_M1_STOP_DODGING \
		|| (soundnum) == SFX_F_STAND_STILL)

/**
 * @cmd 0130
 */
bool ai_say_quip(void)
{
	u8 column;
	s16 audioid;
	u8 i;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s32 numnearbychrs;
	bool issomeonetalking;
	s32 probability;
	s16 *rowptr;
	s16 *chrnums;
	s16 *bank;
	char *text;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 distance;
	s32 row = cmd[3];
	u32 playernum;
#ifdef __sgi
	// @bug: CHRH2FLAG_HEADSHOTTED doesn't fit in a u8
	u8 headshotted = (g_Vars.chrdata->hidden2 & CHRH2FLAG_HEADSHOTTED);
#else
	u8 headshotted = 0;
#endif
	struct chrdata *loopchr;

	// Choose bank
	if (CHRRACE(g_Vars.chrdata) == RACE_SKEDAR) {
		bank = (s16 *) g_SkedarQuipBank;

		if (row > 5) {
			row = 0;
		}
	} else if (g_Vars.chrdata->headnum == HEAD_MAIAN_S) {
		bank = (s16 *) g_MaianQuipBank;

		if (row > 2) {
			row = random() % 2;
		}
	} else if (cmd[7] == 0) {
		if (g_Vars.chrdata->voicebox > 3) {
			g_Vars.chrdata->voicebox = 3;
		}

		bank = (s16 *) g_GuardQuipBank[g_Vars.chrdata->voicebox * 41];
	} else {
		bank = (s16 *) g_SpecialQuipBank;
	}

	if (!row && !cmd[4] && !cmd[6]) {
		g_Vars.chrdata->soundtimer = 0;
		g_Vars.aioffset += 10;
		return false;
	}

	chrnums = team_get_chr_ids(g_Vars.chrdata->team);
	numnearbychrs = 0;
	issomeonetalking = false;
	probability = cmd[4];

	// Make it impossible for Elvis and Jon to use anything but special phrases
	if ((g_Vars.chrdata->headnum == HEAD_ELVIS
				|| g_Vars.chrdata->headnum == HEAD_THEKING
				|| g_Vars.chrdata->headnum == HEAD_ELVIS_GOGS
				|| g_Vars.chrdata->headnum == HEAD_JONATHAN) &&
			bank != (s16 *) g_SpecialQuipBank) {
		probability = 0;
	}

	// If the person talking is a player, and they've just died,
	// try using the other coop player.
	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		playernum = playermgr_get_player_num_by_prop(chr->prop);

		if (g_Vars.coopplayernum >= 0 && g_Vars.players[playernum]->isdead) {
			if (playernum == g_Vars.bondplayernum) {
				playernum = g_Vars.coopplayernum;
			} else {
				playernum = g_Vars.bondplayernum;
			}
		}

		set_current_player_num(playernum);
	}

	// If soundgap permits talking at this time and probability passes
	if (g_Vars.chrdata->soundgap == 0 || g_Vars.chrdata->soundgap * TICKS(60) < g_Vars.chrdata->soundtimer) {
		if (probability > (s32) (random() % 256)) {
			// Try and find a chr in the same squadron who is currently talking
			while (*chrnums != -2) {
				loopchr = chr_find_by_literal_id(*chrnums);

				if (loopchr && loopchr->model
						&& !chr_is_dead(loopchr)
						&& loopchr->actiontype != ACT_DEAD
						&& g_Vars.chrdata->squadron == loopchr->squadron
						&& loopchr->alertness >= 100
						&& g_Vars.chrdata->chrnum != loopchr->chrnum
						&& chr_get_distance_to_chr(g_Vars.chrdata, loopchr->chrnum) < 7000) {
					numnearbychrs++;

					if (loopchr->soundtimer < TICKS(60) && cmd[6] != 0 && cmd[6] != 255) {
						issomeonetalking = true;
					}
				}

				chrnums++;
			}

			if (!issomeonetalking
					&& ((numnearbychrs == 0 && (!cmd[6] || cmd[6] == 255)) || (numnearbychrs > 0 && cmd[6] > 0))) {
				rowptr = (s16 *) bank + row * 4;
				column = random() % 3;

				if ((cmd[7] & 0x80) == 0) {
					audioid = rowptr[1 + column];
				} else {
					audioid = rowptr[1 + g_Vars.chrdata->tude];
				}

				if (audio_was_not_played_recently(audioid) || CHRRACE(g_Vars.chrdata) == RACE_SKEDAR) {
					audio_mark_as_recently_played(audioid);

					if (audioid == SFX_M1_CHOKING && !headshotted) {
						audioid = SFX_M1_WHY_ME;
					}

					g_Vars.chrdata->soundtimer = 0;
					g_Vars.chrdata->soundgap = cmd[5];
					g_Vars.chrdata->propsoundcount++;

					if (!AUDIO_NEEDS_MOVEMENT(audioid)) {
						ps_stop_sound(g_Vars.chrdata->prop, PSTYPE_CHRTALK, 0xffff);
						ps_create(0, g_Vars.chrdata->prop, audioid, -1,
								-1, PSFLAG_FORPROP, 0, PSTYPE_CHRTALK, 0, -1, 0, -1, -1, -1, -1);
					} else {
						distance = chr_get_distance_lost_to_target_in_last_second(g_Vars.chrdata);

						if (ABS(distance) > 50) {
							ps_stop_sound(g_Vars.chrdata->prop, PSTYPE_CHRTALK, 0xffff);
							ps_create(0, g_Vars.chrdata->prop, audioid, -1,
									-1, PSFLAG_FORPROP, 0, PSTYPE_CHRTALK, 0, -1, 0, -1, -1, -1, -1);
						}
					}

					// Consider putting text on screen
					// Note: if cmd[8] is 0 then it means no text, so the value
					// needs to be be decremented by one so it's 0-indexed.
					if (cmd[8] && (cmd[7] & 0x80) == 0) {
						if (column > 2) {
							column = 2;
						}

						text = lang_get(g_QuipTexts[cmd[8] - 1][1 + column]);

#if VERSION >= VERSION_NTSC_1_0
						if (!snd_is_filtered(audioid))
#endif
						{
							hudmsg_create_with_colour(text, HUDMSGTYPE_INGAMESUBTITLE, cmd[9]);
						}
					} else if (cmd[8]) {
						text = lang_get(g_QuipTexts[cmd[8] - 1][1 + g_Vars.chrdata->tude]);

#if VERSION >= VERSION_NTSC_1_0
						if (!snd_is_filtered(audioid))
#endif
						{
							hudmsg_create_with_colour(text, HUDMSGTYPE_INGAMESUBTITLE, cmd[9]);
						}
					}
				} else {
					// Audio was played recently - try and find a different one
					audioid = 0;

					for (i = 1; i < ARRAYCOUNT(g_GuardQuipBank[row]); i++) {
						if (audio_was_not_played_recently(g_GuardQuipBank[row][i])
								&& audio_was_not_played_recently(rowptr[i])) {
							audioid = rowptr[i];
							break;
						}
					}

					if (audioid) {
						audio_mark_as_recently_played(audioid);

						if (audioid == SFX_M1_CHOKING && !headshotted) {
							audioid = SFX_M1_WHY_ME;
						}

						g_Vars.chrdata->soundtimer = 0;
						g_Vars.chrdata->soundgap = cmd[5];
						g_Vars.chrdata->propsoundcount++;

						if (!AUDIO_NEEDS_MOVEMENT(audioid)) {
							ps_stop_sound(g_Vars.chrdata->prop, PSTYPE_CHRTALK, 0xffff);
							ps_create(0, g_Vars.chrdata->prop, audioid, -1,
									-1, PSFLAG_FORPROP, 0, PSTYPE_CHRTALK, 0, -1, 0, -1, -1, -1, -1);
						} else {
							distance = chr_get_distance_lost_to_target_in_last_second(g_Vars.chrdata);

							if (ABS(distance) > 50) {
								ps_stop_sound(g_Vars.chrdata->prop, PSTYPE_CHRTALK, 0xffff);
								ps_create(0, g_Vars.chrdata->prop, audioid, -1,
										-1, PSFLAG_FORPROP, 0, PSTYPE_CHRTALK, 0, -1, 0, -1, -1, -1, -1);
							}
						}

						if (cmd[8]) {
							text = lang_get(g_QuipTexts[cmd[8] - 1][i]);

#if VERSION >= VERSION_NTSC_1_0
							if (!snd_is_filtered(audioid))
#endif
							{
								hudmsg_create_with_colour(text, HUDMSGTYPE_INGAMESUBTITLE, cmd[9]);
							}
						}
					} else {
						g_Vars.chrdata->soundtimer = 0;
						g_Vars.chrdata->soundgap = cmd[5];
						chr_unset_flags(g_Vars.chrdata, CHRFLAG1_TALKINGTODISGUISE, BANK_1);
					}
				}
			}
		}
	}

	set_current_player_num(prevplayernum);

	g_Vars.aioffset += 10;

	return false;
}

void prop_decrement_sound_count(struct prop *prop)
{
	if (prop && prop->chr && prop->chr->model && prop->chr->propsoundcount > 0) {
		prop->chr->propsoundcount--;
	}
}

/**
 * @cmd 01a7
 */
bool ai_if_chr_not_talking(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_literal_id(cmd[2]);

	if (chr && chr->propsoundcount == 0) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 4;
	}

	return false;
}

/**
 * @cmd 0131
 */
bool ai_increase_squadron_alertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 *chrnums = team_get_chr_ids(g_Vars.chrdata->team);

	for (; *chrnums != -2; chrnums++) {
		struct chrdata *chr = chr_find_by_literal_id(*chrnums);

		if (chr &&
				chr->model &&
				!chr_is_dead(chr) &&
				chr->actiontype != ACT_DEAD &&
				(g_Vars.chrdata->squadron == chr->squadron || g_Vars.chrdata->squadron == 255) &&
				g_Vars.chrdata->chrnum != chr->chrnum &&
				(chr_get_distance_to_chr(g_Vars.chrdata, chr->chrnum) < 1000 || chr_has_flag(g_Vars.chrdata, CHRFLAG0_SQUADALERTANYDIST, BANK_0))) {
			increment_byte(&chr->alertness, cmd[2]);
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0132
 */
bool ai_set_action(void)
{
	struct bytelist *cmd = (struct bytelist *)(g_Vars.ailist + g_Vars.aioffset);
	g_Vars.chrdata->myaction = cmd->b2;

	if (cmd->b3 == 0) {
		g_Vars.chrdata->orders = 0;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0133
 */
bool ai_set_team_orders(void)
{
	struct chrnumaction *chraction;
	s32 chrcount = 1;
	s16 *chrnums;
	struct chrnumaction chractions[50];
	s32 num;
	u32 stack;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	// Get list of chrs in the current chr's squadron
	chrnums = squadron_get_chr_ids(g_Vars.chrdata->squadron);

	// Iterate chrs in squadron and build list of their actions.
	// Put the current chr's action first.
	chraction = chractions;
	chraction->chrnum = g_Vars.chrdata->chrnum;
	chraction->myaction = g_Vars.chrdata->myaction;
	chraction++;

	if (chrnums) {
		while (*chrnums != -2) {
			struct chrdata *chr = chr_find_by_literal_id(*chrnums);

			if (chr && chr->model
					&& !chr_is_dead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chr_compare_teams(g_Vars.chrdata, chr, COMPARE_FRIENDS)
					&& g_Vars.chrdata->chrnum != chr->chrnum) {
				if (chr->myaction == MA_COVERWAIT
						|| chr->myaction == MA_NORMAL
						|| chr->myaction == MA_WAITING
						|| chr->myaction == MA_SHOOTING) {
					if (chr_get_distance_to_chr(g_Vars.chrdata, chr->chrnum) < 3500) {
						chrcount++;
						chraction->chrnum = chr->chrnum;
						chraction->myaction = chr->myaction;
						chraction++;
					}
				}
			}

			chrnums++;
		}
	}

	chraction->myaction = MA_END;

	// Iterate the list of chrs and decide how to reassign orders to them
	// based on the current chr's action
	if (chrcount != 1) {
		chraction = &chractions[1];
		num = 1;

		while (chraction->myaction != MA_END) {
			struct chrdata *chr = chr_find_by_literal_id(chraction->chrnum);

			switch (chractions[0].myaction) {
			case MA_COVERGOTO:
				if (!chr_is_in_targets_fov_x(chr, 45)) {
					chr->orders = MA_SHOOTING;
				}
				break;
			case MA_COVERBREAK:
				if (!chr_is_in_targets_fov_x(chr, 30)) {
					chr->orders = MA_SHOOTING;
				}
				num++;
				break;
			case MA_COVERSEEN:
				if (!chr_is_in_targets_fov_x(chr, 30)) {
					chr->orders = MA_SHOOTING;
					g_Vars.chrdata->orders = MA_COVERGOTO;
				}
				num++;
				break;
			case MA_FLANKLEFT:
				if (chr_is_in_targets_fov_x(chr, 50)) {
					chr->orders = MA_FLANKRIGHT;
				} else {
					chr->orders = MA_SHOOTING;
				}
				num++;
				g_Vars.chrdata->orders = MA_FLANKLEFT;
				break;
			case MA_FLANKRIGHT:
				if (chr_is_in_targets_fov_x(chr, 50)) {
					chr->orders = MA_FLANKLEFT;
				} else {
					chr->orders = MA_SHOOTING;
				}
				num++;
				g_Vars.chrdata->orders = MA_FLANKRIGHT;
				break;
			case MA_DODGE:
				if (!chr_is_in_targets_fov_x(chr, 30) &&
						chr_has_flag_by_id(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders = MA_WITHDRAW;
				} else {
					chr->orders = MA_SHOOTING;
				}
				num++;
				break;
			case MA_GRENADE:
				if (num < 2) {
					chr->orders = MA_WAITING;
				} else if (chr_has_flag_by_id(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders = MA_WITHDRAW;
				}
				num++;
				break;
			case MA_WAITSEEN:
				if (chr_is_in_targets_fov_x(chr, 30) &&
						chr_has_flag_by_id(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders = MA_WITHDRAW;
				} else {
					chr->orders = MA_SHOOTING;
				}
				num++;
				break;
			case MA_WITHDRAW:
				if (chr_has_flag_by_id(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders = MA_WITHDRAW;
				}
				break;
			}

			chraction++;
		}

		if (num != 1) {
			g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
		} else {
			g_Vars.aioffset += 4;
		}
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0134
 */
bool ai_if_orders(void)
{
	struct bytelist *cmd = (struct bytelist *)(g_Vars.ailist + g_Vars.aioffset);

	if (g_Vars.chrdata->orders == cmd->b3) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd->b4);

		if (g_Vars.chrdata->orders == MA_WITHDRAW) {
			// empty
		}
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0135
 */
bool ai_if_has_orders(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->orders) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0136
 */
bool ai_retreat(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[3] == 0) {
		chr_run_from_pos(g_Vars.chrdata, cmd[2], (cmd[2] & 0x10) ? 400.0f : 10000.0f, &g_Vars.chrdata->runfrompos);
	} else if (cmd[3] == 1) {
		struct prop *target = chr_get_target_prop(g_Vars.chrdata);
		chr_run_from_pos(g_Vars.chrdata, cmd[2], 10000, &target->pos);
	} else {
		chr_assign_cover_by_criteria(g_Vars.chrdata,
				COVERCRITERIA_FURTHEREST
				| COVERCRITERIA_DISTTOTARGET
				| COVERCRITERIA_ONLYNEIGHBOURINGROOMS
				| COVERCRITERIA_ROOMSFROMME, 0);
		chr_go_to_cover(g_Vars.chrdata, cmd[2]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0137
 */
bool ai_if_chr_in_squadron_doing_action(void)
{
	s32 ret;
	s16 *chrnums = squadron_get_chr_ids(g_Vars.chrdata->squadron);
	struct bytelist *cmd = (struct bytelist *)(g_Vars.ailist + g_Vars.aioffset);
	ret = 1;

	if (chrnums) {
		for (; *chrnums != -2; chrnums++) {
			struct chrdata *chr = chr_find_by_literal_id(*chrnums);

			if (chr && chr->model && chr_is_dead(chr) == false &&
					chr->actiontype != ACT_DEAD &&
					chr_compare_teams(g_Vars.chrdata, chr, COMPARE_FRIENDS) &&
					g_Vars.chrdata->chrnum != chr->chrnum &&
					chr_get_distance_to_chr(g_Vars.chrdata, chr->chrnum) < 3500 &&
					chr->myaction == cmd->b2) {
				ret = 2;
				break;
			}
		}
	}

	if (ret != 1) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd->b3);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0139
 */
bool ai_flank(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 angle = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	struct coord pos;

	chr_flank(g_Vars.chrdata, angle, &pos, cmd[7], cmd[6]);

	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 013a
 */
bool ai_set_chr_preset_to_unalerted_teammate(void)
{
	f32 closest_distance = 30999.9;
	s16 candidate_chrnum = -1;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 *chrnums = team_get_chr_ids(g_Vars.chrdata->team);

	if (g_Vars.chrdata->talktimer > TICKS(480) && g_Vars.chrdata->listening) {
		g_Vars.chrdata->listening = 0;
	}

	for (; *chrnums != -2; chrnums++) {
		struct chrdata *chr = chr_find_by_literal_id(*chrnums);

		if (cmd[3] == 0 && chr && chr->model &&
				chr_is_dead(chr) == false &&
				chr->actiontype != ACT_DEAD &&
				chr->actiontype != ACT_DIE &&
				chr->actiontype != ACT_DRUGGEDKO &&
				chr->actiontype != ACT_DRUGGEDDROP &&
				chr->actiontype != ACT_DRUGGEDCOMINGUP &&
				chr->alertness < 100 &&
				(g_Vars.chrdata->squadron == chr->squadron || g_Vars.chrdata->squadron == 0xff) &&
				g_Vars.chrdata->chrnum != chr->chrnum) {

			f32 distance = chr_get_distance_to_chr(g_Vars.chrdata, chr->chrnum);

			if (distance < closest_distance &&
					(distance < 100.0f * (s32)cmd[2] || cmd[2] == 0) &&
					distance < closest_distance) {
				closest_distance = distance;

				if (cmd[3] != 1) {
					candidate_chrnum = chr->chrnum;
				} else if (distance > 200) {
					candidate_chrnum = chr->chrnum;
				}
			}
		}
	}

	if (candidate_chrnum != -1) {
		chr_set_chr_preset(g_Vars.chrdata, candidate_chrnum);
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 013b
 */
bool ai_set_squadron(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.chrdata->squadron = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 013c
 */
bool ai_face_cover(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_face_cover(g_Vars.chrdata)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 013d
 */
bool ai_if_dangerous_object_nearby(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_detect_dangerous_object(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 013e
 */
bool ai013e(void)
{
	if (func0f03aca0(g_Vars.chrdata, 400, true) == 0 && chr_assign_cover_away_from_danger(g_Vars.chrdata, 1000, 12000) != -1) {
		chr_go_to_cover(g_Vars.chrdata, GOPOSFLAG_RUN);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 013f
 */
bool ai_if_heli_weapons_armed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.hovercar) {
		if (g_Vars.hovercar->weaponsarmed) {
			g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
		} else {
			g_Vars.aioffset += 3;
		}
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0140
 */
bool ai_if_hoverbot_next_step(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.hovercar) {
		if ((g_Vars.hovercar->nextstep > cmd[3] && cmd[2] == 1) ||
				(g_Vars.hovercar->nextstep < cmd[3] && cmd[2] == 0)) {
			g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
		} else {
			g_Vars.aioffset += 5;
		}
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0141
 */
bool ai_shuffle_investigation_terminals(void)
{
	// 2 = goodtag
	// 3 = badtag
	// 4 = pc1
	// 5 = pc2
	// 6 = pc3
	// 7 = pc4
	// 8 = always 00

	u8 rand1;
	u8 rand2;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct tag *goodtag = tag_find_by_id(cmd[2]);
	struct tag *badtag = tag_find_by_id(cmd[3]);
	struct tag *pc;

	/**
	 * @bug: These should be using modulus 4. Because it's 1 short, the final
	 * else conditions are unreachable so only 3 of the 4 terminals can be
	 * selected as the destination.
	 */
	rand1 = random() % 3;
	rand2 = random() % 3;

	if (cmd[8] == 0) {
		// Place the good terminal
		if (rand1 == 0) {
			pc = tag_find_by_id(cmd[4]);
			goodtag->cmdoffset = pc->cmdoffset;
			goodtag->obj = pc->obj;
		} else if (rand1 == 1) {
			pc = tag_find_by_id(cmd[5]);
			goodtag->cmdoffset = pc->cmdoffset;
			goodtag->obj = pc->obj;
		} else if (rand1 == 2) {
			pc = tag_find_by_id(cmd[6]);
			goodtag->cmdoffset = pc->cmdoffset;
			goodtag->obj = pc->obj;
		} else {
			pc = tag_find_by_id(cmd[7]);
			goodtag->cmdoffset = pc->cmdoffset;
			goodtag->obj = pc->obj;
		}

		// Handle both good and alarm terminals having the same destination
		if (rand2 == rand1 && rand2 > 0) {
			rand2--;
		} else if (rand2 == rand1 && rand2 < 3) {
			rand2++;
		}

		// Place the alarm terminal
		if (rand2 == 0) {
			pc = tag_find_by_id(cmd[4]);
			badtag->cmdoffset = pc->cmdoffset;
			badtag->obj = pc->obj;
		} else if (rand2 == 1) {
			pc = tag_find_by_id(cmd[5]);
			badtag->cmdoffset = pc->cmdoffset;
			badtag->obj = pc->obj;
		} else if (rand2 == 2) {
			pc = tag_find_by_id(cmd[6]);
			badtag->cmdoffset = pc->cmdoffset;
			badtag->obj = pc->obj;
		} else {
			pc = tag_find_by_id(cmd[7]);
			badtag->cmdoffset = pc->cmdoffset;
			badtag->obj = pc->obj;
		}
	}

	g_Vars.aioffset += 9;

	return false;
}

/**
 * Used by the below command, which makes Investigation scientists run to the
 * computer terminals. The number of the left is the pad that the terminal sits
 * on, and the number on the right is the pad that the scientist will run to
 * when running to the terminal.
 */
u16 g_InvestigationPadMap[] = {
	0x0246, 0x007b,
	0x0247, 0x007d,
	0x0248, 0x007e,
	0x0249, 0x007c,
	0x024a, 0x0093,
	0x024b, 0x0091,
	0x024c, 0x0092,
	0x024d, 0x0093,
	0x024e, 0x00ae,
	0x024f, 0x00ac,
	0x0250, 0x00ab,
	0x0251, 0x00ad,
	0x0252, 0x00a1,
	0x0253, 0x009f,
	0x0254, 0x00a0,
	0x0255, 0x009e,
	0x0256, 0x00bb,
	0x0257, 0x00b8,
	0x0258, 0x00b9,
	0x0259, 0x00ba,
};

/**
 * @cmd 0142
 */
bool ai_set_pad_preset_to_investigation_terminal(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj) {
		s16 objpad = obj->pad;
		s32 i;

		for (i = 0; i < sizeof(g_InvestigationPadMap) / sizeof(g_InvestigationPadMap[0]); i += 2) {
			if (objpad == g_InvestigationPadMap[i]) {
				chr_set_pad_preset(g_Vars.chrdata, g_InvestigationPadMap[i + 1]);
			}
		}
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0143
 */
bool ai_heli_arm_weapons(void)
{
	if (g_Vars.hovercar) {
		chopper_set_armed(g_Vars.hovercar, true);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0144
 */
bool ai_heli_unarm_weapons(void)
{
	if (g_Vars.hovercar) {
		chopper_set_armed(g_Vars.hovercar, false);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0145
 */
bool ai_rebuild_teams(void)
{
	rebuild_teams();
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0146
 */
bool ai_rebuild_squadrons(void)
{
	rebuild_squadrons();
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0147
 */
bool ai_if_squadron_is_dead(void)
{
	/**
	 * @bug: anyalive is initialised to true here, and reset to false in each
	 * loop iteration. This causes it to use the last chr's status only.
	 */
	u32 stack[2];
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bool anyalive = true;
	s16 *chrnums = squadron_get_chr_ids(cmd[2]);

	if (chrnums) {
		while (*chrnums != -2) {
			struct chrdata *chr = chr_find_by_literal_id(*chrnums);

			if (chr && chr->model) {
				anyalive = false;

				if (!chr_is_dead(chr) && chr->actiontype != ACT_DEAD) {
					anyalive = true;
				}
			}

			chrnums++;
		}
	}

	if (!anyalive) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0148
 */
bool ai_chr_set_listening(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->listening == 0) {
		chr->listening = cmd[3];
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0149
 */
bool ai_if_chr_listening(void)
{
	struct bytelist *cmd = (struct bytelist *)(g_Vars.ailist + g_Vars.aioffset);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd->b2);

	if (cmd->b4 == 0) {
		if (chr->listening == cmd->b3) {
			g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd->b5);
		} else {
			g_Vars.aioffset += 6;
		}
	} else {
		if (g_Vars.chrdata->convtalk == 0) {
			g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd->b5);
		} else {
			g_Vars.aioffset += 6;
		}
	}

	return false;
}

/**
 * @cmd 014a
 */
bool ai_if_true(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);

	return false;
}

/**
 * @cmd 014b
 */
bool ai_if_not_listening(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->listening == 0) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0157
 */
bool ai_set_tinted_glass_enabled(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_TintedGlassEnabled = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0152
 */
bool ai_if_num_chrs_in_squadron_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s32 count = 0;
	s16 *chrnums = squadron_get_chr_ids(cmd[3]);

	if (chrnums) {
		while (*chrnums != -2) {
			struct chrdata *chr = chr_find_by_literal_id(*chrnums);

			if (chr && chr->prop && chr_is_dead(chr) == false
					&& chr->actiontype != ACT_DEAD
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP) {
				count++;
			}

			chrnums++;
		}
	}

	if (count > cmd[2]) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0165
 */
bool ai_if_chr_injured(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_INJUREDTARGET)) {
		chr->chrflags &= ~CHRCFLAG_INJUREDTARGET;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0166
 */
bool ai_if_action(void)
{
	struct bytelist *cmd = (struct bytelist *)(g_Vars.ailist + g_Vars.aioffset);

	if (g_Vars.chrdata->myaction == cmd->b2) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd->b3);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0167
 */
bool ai_hovercopter_fire_rocket(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	chopper_fire_rocket(g_Vars.hovercar, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0169
 */
bool ai_if_natural_anim(void)
{
	struct bytelist *cmd = (struct bytelist *)(g_Vars.ailist + g_Vars.aioffset);

	if (g_Vars.chrdata->naturalanim == cmd->b2) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd->b3);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 016a
 */
bool ai_if_y(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = NULL;
	f32 cutoff_y = ((cmd[4] | (cmd[3] << 8)) << 16) >> 16;

	if (cmd[2] == CHR_TARGET && g_Vars.hovercar) {
		struct chopperobj *chopper = chopper_from_hovercar(g_Vars.hovercar);

		if (chopper) {
			struct prop *target = chopper_get_target_prop(chopper);

			if (target && (target->type == PROPTYPE_CHR || target->type == PROPTYPE_PLAYER)) {
				chr = target->chr;
			}
		}
	} else {
		chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	}

	if (chr && chr->prop && (
				(chr->prop->pos.y < cutoff_y && cmd[5] == 0) ||
				(chr->prop->pos.y > cutoff_y && cmd[5] == 1))) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 016c
 */
bool ai_noop_016c(void)
{
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 016d
 */
bool ai_chr_adjust_motion_blur(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		if (cmd[4] == 0) {
			chr->blurdrugamount -= TICKS(cmd[3]);
		} else {
			chr->blurdrugamount += TICKS(cmd[3]);
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 016e
 */
bool ai_damage_chr_by_amount(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct coord coord = {0, 0, 0};
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		if (cmd[4] == 2) {
			struct gset gset = {WEAPON_COMBATKNIFE, 0, 0, FUNC_POISON};
			chr_damage_by_dizziness(chr, (s32)cmd[3] * 0.03125f, &coord, &gset, NULL);
		} else if (cmd[4] == 0) {
			chr_damage_by_dizziness(chr, (s32)cmd[3] * 0.03125f, &coord, NULL, NULL);
		} else {
			chr_damage_by_dizziness(chr, (s32)cmd[3] * -0.03125f, &coord, NULL, NULL);
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 016f
 */
bool ai_if_chr_has_gun(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->model && chr->gunprop == NULL) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0170
 */
bool ai_do_gun_command(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct weaponobj *weapon = g_Vars.chrdata->gunprop->weapon;

	if (cmd[2] == 0 || ((weapon->base.hidden & OBJHFLAG_PROJECTILE) == 0 && cmd[2] == 1)) {
		if (cmd[2] == 0) {
			chr_go_to_prop(g_Vars.chrdata, g_Vars.chrdata->gunprop, GOPOSFLAG_JOG);
		}

		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0171
 */
bool ai_if_distance_to_gun_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) * 10.0f;
	f32 xdiff = 0;
	f32 ydiff = 0;
	f32 zdiff = 0;

	if (g_Vars.chrdata->gunprop) {
		xdiff = g_Vars.chrdata->prop->pos.x - g_Vars.chrdata->gunprop->pos.x;
		ydiff = g_Vars.chrdata->prop->pos.y - g_Vars.chrdata->gunprop->pos.y;
		zdiff = g_Vars.chrdata->prop->pos.z - g_Vars.chrdata->gunprop->pos.z;
	}

	if (ydiff < 200 && ydiff > -200 &&
			xdiff < distance && xdiff > -distance &&
			zdiff < distance && zdiff > -distance) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0172
 */
bool ai_recover_gun(void)
{ \
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct prop *prop = g_Vars.chrdata->gunprop;
	g_Vars.chrdata->gunprop = NULL;

	if (prop && prop->obj && prop->parent == NULL && prop->type == PROPTYPE_WEAPON) {
		prop_deregister_rooms(prop);
		prop_delist(prop);
		prop_disable(prop);
		chr_equip_weapon(prop->weapon, g_Vars.chrdata);
	}

	g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);

	if (1);

	return false;
}

/**
 * @cmd 0173
 */
bool ai_chr_copy_properties(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->model) {
		g_Vars.chrdata->hearingscale = chr->hearingscale;
		g_Vars.chrdata->visionrange = chr->visionrange;
		g_Vars.chrdata->padpreset1 = chr->padpreset1;
		g_Vars.chrdata->chrpreset1 = chr->chrpreset1;
		g_Vars.chrdata->flags = chr->flags;
		g_Vars.chrdata->flags2 = chr->flags2;
		g_Vars.chrdata->team = chr->team;
		g_Vars.chrdata->squadron = chr->squadron;

		// @bug? Copying from self to self
		g_Vars.chrdata->accuracyrating = g_Vars.chrdata->accuracyrating;
		g_Vars.chrdata->speedrating = g_Vars.chrdata->speedrating;

		g_Vars.chrdata->naturalanim = chr->naturalanim;
		g_Vars.chrdata->myspecial = chr->myspecial;
		g_Vars.chrdata->yvisang = chr->yvisang;
		g_Vars.chrdata->teamscandist = chr->teamscandist;

		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0177
 */
bool ai_player_auto_walk(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 pad_id = cmd[4] | (cmd[3] << 8);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);
		player_auto_walk(pad_id, cmd[5], cmd[6], cmd[7], cmd[8]);
		set_current_player_num(prevplayernum);
	}

	g_Vars.aioffset += 9;

	return false;
}

/**
 * @cmd 0178
 */
bool ai_if_player_auto_walk_finished(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bool walking = false;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);

		if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
			walking = true;
		}

		set_current_player_num(prevplayernum);
	}

	if (walking) {
		g_Vars.aioffset += 4;
	} else {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	}

	return false;
}

/**
 * @cmd 0181
 */
bool ai_if_player_looking_at_object(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[3]);
	bool pass = false;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);

		if (g_Vars.currentplayer->lookingatprop.prop == obj->prop) {
			pass = true;
		}

		set_current_player_num(prevplayernum);
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0182
 */
bool ai_punch_or_kick(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata && chr_try_punch(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0183
 */
bool ai_if_target_is_player(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct prop *target = chr_get_target_prop(g_Vars.chrdata);

	if (target->type == PROPTYPE_EYESPY || target->type == PROPTYPE_PLAYER) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0184
 */
bool ai0184(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	chr_try_attack_amount(g_Vars.chrdata, 512, 0, cmd[2], cmd[3]);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0186
 */
bool ai_if_sound_timer(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s32 value = TICKS(cmd[3] | (cmd[2] << 8));

	if ((g_Vars.chrdata->soundtimer > value && cmd[4] == 0) ||
			(g_Vars.chrdata->soundtimer < value && cmd[4] == 1)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 0187
 */
bool ai_set_target_to_eyespy_if_in_sight(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 prevtarget = g_Vars.chrdata->target;
	struct eyespy *eyespy = g_Vars.players[g_Vars.chrdata->p1p2]->eyespy;

	if (eyespy) {
		struct chrdata *chr = eyespy->prop->chr;
		g_Vars.chrdata->target = prop_get_index_by_chr_id(g_Vars.chrdata, chr->chrnum);

		if (chr_check_can_see_target(g_Vars.chrdata)) {
			g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
		} else {
			g_Vars.aioffset += 3;
			g_Vars.chrdata->target = prevtarget;
		}
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0188
 */
bool ai_if_lift_stationary(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);
	bool pass = false;

	if (obj && obj->prop && obj->type == OBJTYPE_LIFT) {
		struct liftobj *lift = (struct liftobj *)obj;

		if ((obj->flags & OBJFLAG_DEACTIVATED) || lift->dist == 0) {
			pass = true;
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0189
 */
bool ai_lift_go_to_stop(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj->type == OBJTYPE_LIFT) {
		struct liftobj *lift = (struct liftobj *)obj;
		lift_go_to_stop(lift, cmd[3]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 018a
 */
bool ai_if_lift_at_stop(void)
{
	struct bytelist *cmd = (struct bytelist *)(g_Vars.ailist + g_Vars.aioffset);
	struct defaultobj *obj = obj_find_by_tag_id(cmd->b2);
	bool pass = false;

	if (obj && obj->prop && obj->type == OBJTYPE_LIFT) {
		struct liftobj *lift = (struct liftobj *)obj;

		if (lift->levelcur == cmd->b3 && lift->dist == 0) {
			pass = true;
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd->b4);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 018b
 */
bool ai_configure_rain(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	weather_configure_rain(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01b6
 */
bool ai_configure_snow(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	weather_configure_snow(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 018c
 */
bool ai_chr_toggle_model_part(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr_toggle_model_part(chr, cmd[3]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 018d
 */
bool ai_activate_lift(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[3]);

	if (obj && obj->prop) {
		lift_activate(obj->prop, cmd[2]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 018e
 */
bool ai_mini_skedar_try_pounce(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 thing = cmd[4] | (cmd[3] << 8);

	if (chr_try_sk_jump(g_Vars.chrdata, g_Vars.chrdata->pouncebits, cmd[2], thing, cmd[5])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;

	}

	return false;
}

/**
 * @cmd 018f
 */
bool ai_if_object_distance_to_pad_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (f32)(cmd[4] | (cmd[3] << 8)) * 10;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
#if VERSION >= VERSION_NTSC_1_0
	s32 pad_id = (cmd[6] | (cmd[5] << 8)) & 0xffff;
#else
	u16 pad_id = cmd[6] | (cmd[5] << 8);
#endif
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);
	struct pad pad;
	bool pass = false;

	if (obj && obj->prop) {
		pad_id = chr_resolve_pad_id(g_Vars.chrdata, pad_id);

#if VERSION >= VERSION_NTSC_1_0
		if (pad_id >= 0)
#endif
		{
			pad_unpack(pad_id, PADFIELD_POS, &pad);
			xdiff = obj->prop->pos.x - pad.pos.x;
			ydiff = obj->prop->pos.y - pad.pos.y;
			zdiff = obj->prop->pos.z - pad.pos.z;

			if (ydiff < 200 && ydiff > -200 &&
					xdiff < distance && xdiff > -distance &&
					zdiff < distance && zdiff > -distance) {
				pass = true;
			}
		}
	}

	if (pass) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 0190
 */
bool ai_set_savefile_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	gamefile_set_flag(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0191
 */
bool ai_unset_savefile_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	gamefile_unset_flag(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0192
 */
bool ai_if_savefile_flag_is_set(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (gamefile_has_flag(cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0193
 */
bool ai_if_savefile_flag_is_unset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (!gamefile_has_flag(cmd[2])) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 019e
 */
bool ai_if_obj_health_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s32 damage = cmd[4] | (cmd[3] << 8);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	bool condition_passes = false;

	if (obj && obj->prop && obj->damage < damage) {
		condition_passes = true;
	}

	if (condition_passes) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 019f
 */
bool ai_set_obj_health(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s32 damage = cmd[4] | (cmd[3] << 8);
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		obj->damage = damage;
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01a0
 */
bool ai_set_chr_special_death_animation(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->specialdie = cmd[3];
	}

	g_Vars.aioffset += 4;

	return 0;
}

/**
 * @cmd 01a1
 */
bool ai_set_room_to_search(void)
{
	struct chrdata *target = chr_find_by_id(g_Vars.chrdata, CHR_TARGET);

	if (target && target->prop) {
		g_Vars.chrdata->roomtosearch = target->prop->rooms[0];
	}

	g_Vars.aioffset += 2;

	return false;
}

s16 g_CiMainQuips[][3] = {
	{ MP3_CARR_WHAT_IS_IT,           MP3_CARR_A_LITTLE_BUSY,          MP3_CARR_PROUD_OF_YOU            },
	{ MP3_CIFEM_FOSTER,              MP3_CIFEM_COME_TO_SEE_ME,        MP3_CIFEM_PRACTICE_MAKES_PERFECT },
	{ MP3_GRIMSHAW_KNOW_YOUR_ENEMY,  MP3_GRIMSHAW_ALL_EARS,           MP3_GRIMSHAW_GAP_IN_RECORDS      },
	{ MP3_HOLO_LAST_MINUTE_TRAINING, MP3_HOLO_PRACTICE_MAKES_PERFECT, MP3_HOLO_HAVE_A_LIFE             },
	{ MP3_HANGERGUY_DONT_SCREW_UP,   MP3_HANGERGUY_DONT_MAKE_A_MESS,  MP3_HANGERGUY_HALF_HOUR_AGO      },
	{ MP3_FOSTER_WHAT_TO_SHOOT_AT,   MP3_FOSTER_ZEROED_THE_SIGHTS,    MP3_FOSTER_GOOD_SHOW             },
};

s16 g_CiGreetingQuips[][3] = {
	{ SFX_CARR_HELLO_JOANNA,       SFX_CARR_HELLO_JOANNA,       SFX_CARR_HELLO_JOANNA       },
	{ SFX_CIFEM_HI_THERE,          SFX_CIFEM_HI_THERE,          SFX_CIFEM_HI_THERE          },
	{ SFX_GRIMSHAW_WELCOME,        SFX_GRIMSHAW_HI_THERE,       SFX_GRIMSHAW_UMM_ERR_HI     },
	{ SFX_HOLO_HI,                 SFX_HOLO_HI,                 SFX_HOLO_HI                 },
	{ SFX_HANGAR_WHAT_DO_YOU_WANT, SFX_HANGAR_WHAT_DO_YOU_WANT, SFX_HANGAR_WHAT_DO_YOU_WANT },
	{ SFX_FOSTER_STAR_AGENT,       SFX_FOSTER_STAR_AGENT,       SFX_FOSTER_STAR_AGENT       },
	{ SFX_CIM_HEY_THERE,           SFX_CIM_HEY_THERE,           SFX_CIM_HI                  },
	{ SFX_CIM_HI,                  SFX_CIM_HOWS_IT_GOING,       SFX_CIM_HOWS_IT_GOING       },
	{ SFX_CIFEM_HELLO,             SFX_CIFEM_HELLO,             SFX_CIFEM_HI_JO             },
	{ SFX_CIFEM_HI_JO,             SFX_CIFEM_HOWS_IT_GOING,     SFX_CIFEM_HOWS_IT_GOING     },
};

s16 g_CiAnnoyedQuips[][3] = {
	{ MP3_CARR_WORRIES_ME,           MP3_CARR_WORRIES_ME,           MP3_CARR_WORRIES_ME           },
	{ MP3_CIFEM_PATIENCE,            MP3_CIFEM_PATIENCE,            MP3_CIFEM_PATIENCE            },
	{ MP3_GRIMSHAW_BUG_OFF,          MP3_GRIMSHAW_CRIMINAL_RECORD,  MP3_GRIMSHAW_LOSER            },
	{ MP3_HOLO_IRRITATING,           MP3_HOLO_IRRITATING,           MP3_HOLO_IRRITATING           },
	{ MP3_HANGAR_LIVED_THIS_LONG,    MP3_HANGAR_LIVED_THIS_LONG,    MP3_HANGAR_LIVED_THIS_LONG    },
	{ MP3_FOSTER_LEAVE_ME_ALONE,     MP3_FOSTER_LEAVE_ME_ALONE,     MP3_FOSTER_LEAVE_ME_ALONE     },
	{ MP3_CIM_BE_SOMEWHERE,          MP3_CIM_BE_SOMEWHERE,          MP3_CIM_BE_SOMEWHERE          },
	{ MP3_CIM_BE_SOMEWHERE,          MP3_CIM_BE_SOMEWHERE,          MP3_CIM_BE_SOMEWHERE          },
	{ MP3_CIFEM_BE_SOMEWHERE,        MP3_CIFEM_BE_SOMEWHERE,        MP3_CIFEM_BE_SOMEWHERE        },
	{ MP3_CIFEM_BOTHER_SOMEONE_ELSE, MP3_CIFEM_BOTHER_SOMEONE_ELSE, MP3_CIFEM_BOTHER_SOMEONE_ELSE },
};

s16 g_CiThanksQuips[] = {
	0,
	MP3_CIFEM_THANKS1,
	MP3_GRIMSHAW_TOO_CLOSE,
	MP3_CIFEM_THANKS2,
	0,
	MP3_FOSTER_RELY_ON_YOU,
	MP3_CIM_THANKS_JO,
	MP3_CIM_THANKS_JO,
	MP3_CIFEM_THANKS3,
	MP3_CIFEM_THANKS3,
};

/**
 * @cmd 01a2
 */
bool ai_say_ci_staff_quip(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 quip;

	if (cmd[2] == CIQUIP_GREETING) {
		quip = g_CiGreetingQuips[g_Vars.chrdata->morale][random() % 3];
		ps_play_from_prop((s8)cmd[3], quip, 0, g_Vars.chrdata->prop, PSTYPE_CHRTALK, 0);
	}

	if (cmd[2] == CIQUIP_MAIN) {
		quip = g_CiMainQuips[g_Vars.chrdata->morale][random() % 3];
		ps_play_from_prop((s8)cmd[3], quip, 0, g_Vars.chrdata->prop, PSTYPE_CHRTALK, 0);
	}

	if (cmd[2] == CIQUIP_ANNOYED) {
		quip = g_CiAnnoyedQuips[g_Vars.chrdata->morale][random() % 3];
		ps_play_from_prop((s8)cmd[3], quip, 0, g_Vars.chrdata->prop, PSTYPE_CHRTALK, 0);
	}

	if (cmd[2] == CIQUIP_THANKS) {
		quip = g_CiThanksQuips[g_Vars.chrdata->morale];
		ps_play_from_prop((s8)cmd[3], quip, 0, g_Vars.chrdata->prop, PSTYPE_CHRTALK, 0);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01a3
 */
bool ai_do_preset_animation(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	// These all appear to be talking animations
	u16 anims[] = {
		/* 0*/ ANIM_0296,
		/* 1*/ ANIM_0297,
		/* 2*/ ANIM_0298,
		/* 3*/ ANIM_028A, // when value is 3 (1/2 chance)
		/* 4*/ ANIM_028C, // when value is 3 (1/2 chance)
		/* 5*/ ANIM_0290,
		/* 6*/ ANIM_0291,
		/* 7*/ ANIM_TALKING_00A3, // when value is 255 (1/8 chance)
		/* 8*/ ANIM_028E, // when value is 255 (1/8 chance)
		/* 9*/ ANIM_028F, // when value is 255 (1/8 chance)
		/*10*/ ANIM_TALKING_0231, // when value is 255 (1/8 chance)
		/*11*/ ANIM_TALKING_0232, // when value is 255 (1/8 chance)
		/*12*/ ANIM_TALKING_0233, // when value is 255 (1/8 chance)
		/*13*/ ANIM_TALKING_0234, // when value is 255 (1/8 chance)
		/*14*/ ANIM_028D, // when value is 255 (1/8 chance)
	};

	if (cmd[2] == 255) {
		chr_try_start_anim(g_Vars.chrdata, anims[7 + (random() % 8)], 0, -1, 0, 15, 0.5);
	} else if (cmd[2] == 254) {
		struct prop *prop0 = chr_get_held_prop(g_Vars.chrdata, 1);
		struct prop *prop1 = chr_get_held_prop(g_Vars.chrdata, 0);

		if (weapon_is_one_handed(prop0) || weapon_is_one_handed(prop1)) {
			chr_try_start_anim(g_Vars.chrdata, ANIM_FIX_GUN_JAM_EASY, 0, -1, 0, 5, 0.5);
		} else {
			chr_try_start_anim(g_Vars.chrdata, ANIM_FIX_GUN_JAM_HARD, 0, -1, 0, 5, 0.5);
		}
	} else if (cmd[2] == 3) {
		chr_try_start_anim(g_Vars.chrdata, anims[3 + (random() & 1)], 0, -1, 0, 15, 0.5);
	} else {
		chr_try_start_anim(g_Vars.chrdata, anims[cmd[2]], 0, -1, 0, 15, 0.5);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01a5
 */
bool ai_if_using_lift(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chr_is_using_lift(g_Vars.chrdata)) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 01a6
 */
bool ai_if_target_y_difference_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct prop *prop = chr_get_target_prop(g_Vars.chrdata);
	f32 diff = prop->pos.y - g_Vars.chrdata->prop->pos.y;

	if (diff < 0) {
		diff = 0 - diff;
	}

	if (diff < (s32)cmd[2] * 10.0f) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 01aa
 */
bool ai_if_dist_to_player_through_portals_lt_30m(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 dist = 3000;

	lights_find_distance_through_rooms_with_limit(
			g_Vars.currentplayer->prop->rooms[0],
			&g_Vars.currentplayer->prop->pos,
			g_Vars.chrdata->prop->rooms[0],
			&g_Vars.chrdata->prop->pos,
			0, &dist, 0);

	if (dist < 3000) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 01ae
 */
bool ai_clear_inventory(void)
{
	u32 stackpadding[2];
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 playernum;

	for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
		set_current_player_num(playernum);

		if (g_Vars.currentplayer == g_Vars.bond || g_Vars.currentplayer == g_Vars.coop) {
			inv_clear();
#if VERSION >= VERSION_NTSC_1_0
			g_Vars.currentplayer->devicesactive = 0;
#endif
			inv_give_single_weapon(WEAPON_UNARMED);
			bgun_equip_weapon(WEAPON_UNARMED);
		}
	}

	set_current_player_num(prevplayernum);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01ad
 */
bool ai_release_object(void)
{
	bmove_set_mode_for_all_players(MOVEMODE_WALK);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01af
 */
bool ai_chr_grab_object(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[3]);
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER && obj && obj->prop) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);

		if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK
				&& bmove_get_crouch_pos() == CROUCHPOS_STAND
				&& g_Vars.currentplayer->crouchoffset == 0) {
			bmove_grab_prop(obj->prop);
		}

		set_current_player_num(prevplayernum);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01b1
 */
bool ai_shuffle_ruins_pillars(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct tag *ptr1 = tag_find_by_id(cmd[2]);
	struct tag *ptr2 = tag_find_by_id(cmd[3]);
	struct tag *ptr3 = tag_find_by_id(cmd[4]);
	struct tag *src;
	u8 marked1index = random() % 5;
	u8 marked2index = random() % 5;
	u8 marked3index = random() % 5;
	u8 pillars[5];
	u8 mines[5];
	pillars[0] = cmd[5];
	pillars[1] = cmd[6];
	pillars[2] = cmd[7];
	pillars[3] = cmd[8];
	pillars[4] = cmd[9];
	mines[0] = cmd[13];
	mines[1] = cmd[14];
	mines[2] = cmd[15];
	mines[3] = cmd[16];
	mines[4] = cmd[17];

	while (marked2index == marked1index) {
		marked2index = random() % 5;
	}

	while (marked3index == marked2index || marked3index == marked1index) {
		marked3index = random() % 5;
	}

	// Pillar/mine 1
	src = tag_find_by_id(pillars[marked1index]);
	ptr1->cmdoffset = src->cmdoffset;
	ptr1->obj = src->obj;

	ptr1 = tag_find_by_id(cmd[10]);
	src = tag_find_by_id(mines[marked1index]);
	ptr1->cmdoffset = src->cmdoffset;
	ptr1->obj = src->obj;

	// Pillar/mine 2
	src = tag_find_by_id(pillars[marked2index]);
	ptr2->cmdoffset = src->cmdoffset;
	ptr2->obj = src->obj;

	ptr2 = tag_find_by_id(cmd[11]);
	src = tag_find_by_id(mines[marked2index]);
	ptr2->cmdoffset = src->cmdoffset;
	ptr2->obj = src->obj;

	// Pillar/mine 3
	src = tag_find_by_id(pillars[marked3index]);
	ptr3->cmdoffset = src->cmdoffset;
	ptr3->obj = src->obj;

	ptr3 = tag_find_by_id(cmd[12]);
	src = tag_find_by_id(mines[marked3index]);
	ptr3->cmdoffset = src->cmdoffset;
	ptr3->obj = src->obj;

	g_Vars.aioffset += 18;

	return false;
}

/**
 * @cmd 01b2
 */
bool ai_set_wind_speed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	g_SkyWindSpeed = 0.1f * (s32)cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01b3
 */
bool ai_toggle_p1p2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.coopplayernum >= 0) {
		struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

		if (chr) {
			if (chr->p1p2 == g_Vars.bondplayernum && !g_Vars.coop->isdead) {
				chr->p1p2 = g_Vars.coopplayernum;
			} else if (!g_Vars.bond->isdead) {
				chr->p1p2 = g_Vars.bondplayernum;
			}
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01b5
 */
bool ai_chr_set_p1p2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.coopplayernum >= 0) {
		struct chrdata *chr1 = chr_find_by_id(g_Vars.chrdata, cmd[2]);
		struct chrdata *chr2 = chr_find_by_id(g_Vars.chrdata, cmd[3]);

		if (chr1 && chr2 && chr2->prop && chr2->prop->type == PROPTYPE_PLAYER) {
			u32 playernum = playermgr_get_player_num_by_prop(chr2->prop);

			if (!g_Vars.players[playernum]->isdead) {
				if (chr2->prop == g_Vars.coop->prop) {
					chr1->p1p2 = g_Vars.coopplayernum;
				} else {
					chr1->p1p2 = g_Vars.bondplayernum;
				}
			}
		}
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01b7
 */
bool ai_chr_set_cloaked(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		if (!chr_is_dead(chr)) {
			if (cmd[3]) {
				chr_cloak(chr, cmd[4]);
			} else {
				chr_uncloak(chr, cmd[4]);
			}
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01b8
 */
bool ai_set_autogun_target_team(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop && obj->type == OBJTYPE_AUTOGUN) {
		struct autogunobj *autogun = (struct autogunobj *)obj;
		autogun->targetteam = cmd[3];
		autogun->target = NULL;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01b9
 */
bool ai_shuffle_pelagic_switches(void)
{
	u8 buttonsdone[] = {0, 0, 0, 0, 0, 0, 0, 0};
	u8 i;
	u8 j;
	struct tag *tag;
	struct tag *button;
	u8 index;

	for (i = 8; i < 16; i++) {
		tag = tag_find_by_id(i);
		index = random() & 7;

		if (buttonsdone[index] == 0) {
			// Switch has not yet been mapped
			button = tag_find_by_id(index);
			tag->cmdoffset = button->cmdoffset;
			tag->obj = button->obj;
			buttonsdone[index] = 1;
		} else {
			// Switch is already mapped - find first unmapped switch
			for (j = 0; buttonsdone[j]; j++);

			button = tag_find_by_id(j);
			tag->cmdoffset = button->cmdoffset;
			tag->obj = button->obj;
			buttonsdone[j] = 1;
		}
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 01bb
 */
bool ai_noop_01bb(void)
{
	g_Vars.aioffset += 4;
	return false;
}

/**
 * @cmd 01bc
 */
bool ai_if_pouncebits_eq(void)
{
	struct bytelist *cmd = (struct bytelist *)(g_Vars.ailist + g_Vars.aioffset);

	if (g_Vars.chrdata->pouncebits == cmd->b2) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd->b3);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 01bd
 */
bool ai_if_training_pc_holographed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct trainingdata *data = dt_get_data();

	if (data->holographedpc) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 01be
 */
bool ai_if_player_using_device(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	struct prop *prop = chr ? chr->prop : NULL;
	u8 active = false;

	if (prop && prop->type == PROPTYPE_PLAYER) {
		u32 playernum = playermgr_get_player_num_by_prop(prop);
		u32 prevplayernum = g_Vars.currentplayernum;
		set_current_player_num(playernum);

		if (gset_get_device_state(cmd[3]) == DEVICESTATE_ACTIVE) {
			active = true;
		}

		set_current_player_num(prevplayernum);
	}

	if (active) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 01bf
 */
bool ai_chr_begin_or_end_teleport(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[3] | (cmd[2] << 8);
	f32 fvalue;
	struct chrdata *chr;
#if VERSION >= VERSION_NTSC_1_0
	s32 mainpri;
#endif
	u32 playernum;
	u32 prevplayernum;
#if VERSION >= VERSION_NTSC_1_0
	s32 audiopri;
#endif
	struct sndstate *handle;
	fvalue = 0.4;
	chr = chr_find_by_id(g_Vars.chrdata, cmd[4]);
	prevplayernum = g_Vars.currentplayernum;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);
	}

	if (pad_id == 0) {
		g_Vars.currentplayer->teleportstate = TELEPORTSTATE_EXITING;
		g_Vars.currentplayer->teleporttime = 0;
	} else {
		g_Vars.currentplayer->teleporttime = 0;
		g_Vars.currentplayer->teleportstate = TELEPORTSTATE_PREENTER;
		g_Vars.currentplayer->teleportpad = pad_id;
		g_Vars.currentplayer->teleportcamerapad = 0;

#if VERSION >= VERSION_NTSC_1_0
		mainpri = osGetThreadPri(0);
		audiopri = osGetThreadPri(&g_AudioManager.thread);
		osSetThreadPri(0, audiopri + 1);
#endif

		handle = snd_start(var80095200, SFX_RELOAD_FARSIGHT, NULL, -1, -1, -1, -1, -1);

		if (handle) {
			audioPostEvent(handle, AL_SNDP_PITCH_EVT, *(u32 *)&fvalue);
		}

#if VERSION >= VERSION_NTSC_1_0
		osSetThreadPri(0, mainpri);
#endif
	}

	g_Vars.aioffset += 5;

	set_current_player_num(prevplayernum);

	return false;
}

/**
 * @cmd 01c0
 */
bool ai_if_chr_teleport_full_white(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[3]);
	u32 prevplayernum = g_Vars.currentplayernum;
#if VERSION >= VERSION_NTSC_1_0
	s32 mainpri;
#endif
	f32 fvalue;
#if VERSION >= VERSION_NTSC_1_0
	s32 audiopri;
#endif
	struct sndstate *handle;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 playernum = playermgr_get_player_num_by_prop(chr->prop);
		set_current_player_num(playernum);
	}

	if (g_Vars.currentplayer->teleportstate < TELEPORTSTATE_WHITE) {
		g_Vars.aioffset += 4;
	} else {
		fvalue = 0.4;

#if VERSION >= VERSION_NTSC_1_0
		mainpri = osGetThreadPri(0);
		audiopri = osGetThreadPri(&g_AudioManager.thread);
		osSetThreadPri(0, audiopri + 1);
#endif

		handle = snd_start(var80095200, SFX_FIRE_SHOTGUN, NULL, -1, -1, -1, -1, -1);

		if (handle) {
			audioPostEvent(handle, AL_SNDP_PITCH_EVT, *(u32 *)&fvalue);
		}

#if VERSION >= VERSION_NTSC_1_0
		osSetThreadPri(0, mainpri);
#endif

		g_Vars.currentplayer->teleportstate = TELEPORTSTATE_WHITE;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	}

	set_current_player_num(prevplayernum);

	return false;
}

/**
 * @cmd 01c5
 */
bool ai_avoid(void)
{
	chr_avoid(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 01c8
 */
bool ai_title_init_mode(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset += 3;
	title_init_from_ai_cmd(cmd[2]);

	return false;
}

/**
 * @cmd 01c9
 */
bool ai_try_exit_title(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (title_is_changing_mode()) {
		title_exit();
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 3;
	}

	return false;
}

/**
 * @cmd 01ca
 */
bool ai_chr_set_cutscene_weapon(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	s32 model_id = playermgr_get_model_of_weapon(cmd[3]);
	s32 fallback_model_id = playermgr_get_model_of_weapon(cmd[4]);

	if (chr) {
		if (cmd[3] == 0xff) {
			if (cmd[4] == 0xff) {
				if (chr->weapons_held[0]) {
					struct weaponobj *weapon = chr->weapons_held[0]->weapon;
					bool valid = true;

					switch (weapon->weaponnum) {
					case WEAPON_FALCON2:
					case WEAPON_FALCON2_SILENCER:
					case WEAPON_FALCON2_SCOPE:
					case WEAPON_MAGSEC4:
					case WEAPON_MAULER:
					case WEAPON_PHOENIX:
					case WEAPON_DY357MAGNUM:
					case WEAPON_DY357LX:
					case WEAPON_CMP150:
						valid = false;
					}

					if (valid) {
						weapon_delete_from_chr(chr, HAND_LEFT);
						weapon_delete_from_chr(chr, HAND_RIGHT);
					}
				}
			} else {
				if (chr->weapons_held[0] == NULL && chr->weapons_held[1] == NULL && fallback_model_id >= 0) {
					weapon_create_for_chr(chr, fallback_model_id, cmd[4], 0, NULL, NULL);
				}
			}
		} else {
			weapon_delete_from_chr(chr, HAND_LEFT);
			weapon_delete_from_chr(chr, HAND_RIGHT);

			if (model_id >= 0) {
				weapon_create_for_chr(chr, model_id, cmd[3], 0, NULL, NULL);
			}

			if (fallback_model_id >= 0) {
				weapon_create_for_chr(chr, fallback_model_id, cmd[4], OBJFLAG_WEAPON_LEFTHANDED, NULL, NULL);
			}
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01cb
 */
bool ai_fade_screen(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 color = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	s16 num_frames = (cmd[7] | (cmd[6] << 8));
	lv_configure_fade(color, num_frames);
	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 01cc
 */
bool ai_if_fade_complete(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (lv_is_fade_active() == false) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 01cd
 */
bool ai_set_chr_hudpiece_visible(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->model) {
		chr_set_hudpiece_visible(chr, cmd[3]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01ce
 */
bool ai_set_passive_mode(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bgun_set_passive_mode(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01cf
 */
bool ai_chr_set_firing_in_cutscene(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);
	struct coord from = {0, 0, 0};
	struct coord to = {0, 0, 0};

	if (chr && chr->weapons_held[HAND_RIGHT]) {
		if (cmd[3]) {
			chr_set_firing(chr, HAND_RIGHT, true);
			chr_update_fireslot(chr, HAND_RIGHT, true, false, &from, &to);
		} else {
			chr_set_firing(chr, HAND_RIGHT, false);
		}
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01d0
 */
bool ai_set_portal_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 portalnum = cmd[3] | (cmd[2] << 8);

	g_BgPortals[portalnum].flags |= cmd[4];
	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01d1
 */
bool ai_obj_set_model_part_visible(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = obj_find_by_tag_id(cmd[2]);

	if (obj && obj->prop) {
		obj_set_model_part_visible(obj, cmd[3], cmd[4]);
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01d2
 */
bool ai_chr_emit_sparks(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr_dr_caroll_emit_sparks(chr);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01d3
 */
bool ai_set_dr_caroll_images(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *drcaroll = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (drcaroll) {
		if (cmd[4] == 7) {
			if ((g_Vars.lvframenum % 4) == 2) {
				drcaroll->drcarollimage_left = random() % 6;
			}
		} else if (cmd[4] == 8) {
			drcaroll->drcarollimage_left = random() % 6;
		} else {
			drcaroll->drcarollimage_left = cmd[4];
		}

		if (cmd[3] == 7) {
			if ((g_Vars.lvframenum % 4) == 2) {
				drcaroll->drcarollimage_right = random() % 6;
			}
		} else if (cmd[3] == 8) {
			drcaroll->drcarollimage_right = random() % 6;
		} else {
			drcaroll->drcarollimage_right = cmd[3];
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01d4
 */
bool ai_set_room_flag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	RoomNum roomnum = cmd[3] | cmd[2] << 8;
	s16 flag = cmd[5] | cmd[4] << 8;

	g_Rooms[roomnum].flags |= flag;

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 01d5
 */
bool ai_show_cutscene_chrs(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bool show = cmd[2];
	s32 i;

	if (show) {
		for (i = chrs_get_num_slots() - 1; i >= 0; i--) {
			if (g_ChrSlots[i].chrnum >= 0 && g_ChrSlots[i].prop && (g_ChrSlots[i].hidden2 & CHRH2FLAG_HIDDENFORCUTSCENE)) {
				g_ChrSlots[i].hidden2 &= ~CHRH2FLAG_HIDDENFORCUTSCENE;
				g_ChrSlots[i].chrflags &= ~CHRCFLAG_HIDDEN;
			}
		}
	} else {
		for (i = chrs_get_num_slots() - 1; i >= 0; i--) {
			if (g_ChrSlots[i].chrnum >= 0 && g_ChrSlots[i].prop &&
					(g_ChrSlots[i].chrflags & (CHRCFLAG_UNPLAYABLE | CHRCFLAG_HIDDEN)) == 0) {
				g_ChrSlots[i].hidden2 |= CHRH2FLAG_HIDDENFORCUTSCENE;
				g_ChrSlots[i].chrflags |= CHRCFLAG_HIDDEN;
			}
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01d6
 */
bool ai_configure_environment(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	RoomNum room_id = (cmd[3] | (cmd[2] << 8));
	s32 value = cmd[5];
	s32 i;

	switch (cmd[4]) {
	case AIENVCMD_00:
		var8006ae18 = value;
		break;
	case AIENVCMD_01:
		var8006ae1c = value;
		break;
	case AIENVCMD_02:
		var8006ae20 = value;
		break;
	case AIENVCMD_03:
		var8006ae24 = value;
		break;
	case AIENVCMD_04:
		var8006ae28 = value;
		break;
	case AIENVCMD_ROOM_SETAMBIENT:
		g_Rooms[room_id].flags &= ~ROOMFLAG_PLAYAMBIENTTRACK;
		if (value) {
			g_Rooms[room_id].flags |= ROOMFLAG_PLAYAMBIENTTRACK;
		}
		break;
	case AIENVCMD_ROOM_SETOUTDOORS:
		g_Rooms[room_id].flags &= ~ROOMFLAG_OUTDOORS;
		if (value) {
			g_Rooms[room_id].flags |= ROOMFLAG_OUTDOORS;
		}
		break;
	case AIENVCMD_07:
		g_Rooms[room_id].unk4e_04 = value;
		break;
	case AIENVCMD_08:
		g_Rooms[room_id].unk4d = value;
		break;
	case AIENVCMD_SETAMBIENT:
		for (i = 1; i < g_Vars.roomcount; i++) {
			if (value) {
				g_Rooms[i].flags |= ROOMFLAG_PLAYAMBIENTTRACK;
			} else {
				g_Rooms[i].flags &= ~ROOMFLAG_PLAYAMBIENTTRACK;
			}
		}
		break;
	case AIENVCMD_PLAYNOSEDIVE:
		snd_play_nosedive(value);
		break;
	case AIENVCMD_TICKMUSICQUEUE:
		music_tick_events();
		break;
	case AIENVCMD_ROOM_SETFAULTYLIGHTS:
		room_set_lights_faulty(room_id, value);
		break;
	case AIENVCMD_STOPNOSEDIVE:
		snd_stop_nosedive();
		break;
	case AIENVCMD_PLAYUFOHUM:
		snd_play_ufo(value);
		break;
	case AIENVCMD_STOPUFOHUM:
		snd_stop_ufo();
		break;
	}

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 01d7
 */
bool ai_if_distance_to_target2_less_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chr_get_distance_to_target2(g_Vars.chrdata) < distance) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 01d8
 */
bool ai_if_distance_to_target2_greater_than(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chr_get_distance_to_target2(g_Vars.chrdata) > distance) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 01d9
 */
bool ai_play_sound_from_prop(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 audio_id = cmd[5] | (cmd[4] << 8);
	s32 volume = cmd[7] | (cmd[6] << 8);
	u16 flags = cmd[10] | (cmd[10] << 8); // @bug: Using 10 twice
	s32 channel = (s8)cmd[2];
	s16 type = cmd[8];
	struct defaultobj *obj = obj_find_by_tag_id(cmd[3]);

	ps_play_from_prop(channel, audio_id, volume, obj->prop, type, flags);

	g_Vars.aioffset += 11;

	return false;
}

/**
 * @cmd 01da
 */
bool ai_play_temporary_primary_track(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	music_start_temporary_primary(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01db
 */
bool ai_chr_kill(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chr_find_by_id(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->actiontype = ACT_DEAD;
		chr->act_dead.fadetimer60 = -1;
		chr->act_dead.fadenow = false;
		chr->act_dead.fadewheninvis = false;
		chr->act_dead.invistimer60 = 0;
		chr->act_dead.notifychrindex = 0;
		chr->sleep = 0;
		chr->chrflags |= CHRCFLAG_KEEPCORPSEKO | CHRCFLAG_PERIMDISABLEDTMP;
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01dc
 */
bool ai_remove_weapon_from_inventory(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	inv_remove_item_by_num(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01dd
 */
bool ai_if_music_event_queue_is_empty(void)
{
	f32 value = (u64)osGetCount() * 64 / 3000;

	if (g_MusicEventQueueLength) {
		g_Vars.aioffset += 4;
	} else {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	}

	return false;
}

/**
 * @cmd 01de
 */
bool ai_if_coop_mode(void)
{
	if (g_Vars.normmplayerisrunning == false && g_MissionConfig.iscoop) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * @cmd 01e0
 */
bool ai_remove_references_to_chr(void)
{
	if (g_Vars.chrdata && g_Vars.chrdata->prop) {
		u32 index = g_Vars.chrdata->prop - g_Vars.props;
		chr_clear_references(index);
	}

	g_Vars.aioffset += 2;

	return false;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
/**
 * @cmd 01b4
 */
bool ai_if_nothing_in_my_space(void)
{
	// Attempt to make the chr ascend by 0 units,
	// which is effectively the same as a volume collision test.
	if (g_Vars.chrdata
			&& g_Vars.chrdata->prop
			&& chr_ascend(g_Vars.chrdata, &g_Vars.chrdata->prop->pos, g_Vars.chrdata->prop->rooms, 0, false)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}
#endif
