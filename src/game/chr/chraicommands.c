#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/chr/chrai.h"
#include "game/chr/chraicommands.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/game_011110.h"
#include "game/game_016100.h"
#include "game/chr/chr.h"
#include "game/game_0601b0.h"
#include "game/game_091e10.h"
#include "game/game_092610.h"
#include "game/game_095320.h"
#include "game/game_096750.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b28d0.h"
#include "game/game_0b63b0.h"
#include "game/game_0dcdb0.h"
#include "game/game_111600.h"
#include "game/game_127910.h"
#include "game/game_129900.h"
#include "game/game_12d3f0.h"
#include "game/weather.h"
#include "game/game_157db0.h"
#include "game/game_1655c0.h"
#include "game/game_165670.h"
#include "game/game_167ae0.h"
#include "game/game_16cfa0.h"
#include "game/game_19c990.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/pad.h"
#include "game/pdoptions.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_04a80.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_11420.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "lib/lib_317f0.h"
#include "lib/lib_481e0.h"
#include "lib/lib_48830.h"
#include "lib/lib_4ae00.h"
#include "types.h"

/**
 * @cmd 0000
 */
bool aiGoToNext(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	osSyncPrintf(" (%d)\n", cmd[2]);

	return false;
}

/**
 * @cmd 0001
 */
bool aiGoToFirst(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, 0, cmd[2]);
	osSyncPrintf(" (%d)\n", cmd[2]);

	return false;
}

/**
 * @cmd 0002
 */
bool aiLabel(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 0003
 */
bool aiYield(void)
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
bool aiSetList(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 ailistid = cmd[4] | (cmd[3] << 8);
	u8 *ailist = ailistFindById(ailistid & 0xffff);

	struct chrdata *chr = g_Vars.chrdata;

	if ((cmd[2] & 0xff) == CHR_SELF) {
		g_Vars.ailist = ailist;
		g_Vars.aioffset = 0;
	} else {
		chr = chrFindById(chr, cmd[2]);

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
bool aiSetReturnList(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 ailistid = cmd[4] | (cmd[3] << 8);
	struct chrdata *chr;

	if (g_Vars.chrdata) {
		if (cmd[2] == CHR_SELF) {
			g_Vars.chrdata->aireturnlist = ailistid;
		} else {
			chr = chrFindById(g_Vars.chrdata, cmd[2]);

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
bool aiSetShotList(void)
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
bool aiSetPunchDodgeList(void)
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
bool aiSetShootingAtMeList(void)
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
bool aiSetDarkRoomList(void)
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
bool aiSetPlayerDeadList(void)
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
bool aiReturn(void)
{
	u8 *ailist = NULL;

	if (g_Vars.chrdata) {
		ailist = ailistFindById(g_Vars.chrdata->aireturnlist);
	} else if (g_Vars.truck) {
		ailist = ailistFindById(g_Vars.truck->aireturnlist);
	} else if (g_Vars.heli) {
		ailist = ailistFindById(g_Vars.heli->aireturnlist);
	} else if (g_Vars.hovercar) {
		ailist = ailistFindById(g_Vars.hovercar->aireturnlist);
	}

	g_Vars.ailist = ailist;
	g_Vars.aioffset = 0;

	return false;
}

/**
 * @cmd 0004
 */
bool aiEndList(void)
{
	s32 ailistid;
	bool is_global;
	ailistid = chraiGetListIdByList(g_Vars.ailist, &is_global);

	return true;
}

/**
 * @cmd 0009
 */
bool aiStop(void)
{
	if (g_Vars.chrdata) {
		chrTryStop(g_Vars.chrdata);
	} else if (g_Vars.hovercar) {
		chopperStop(g_Vars.hovercar);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 000a
 */
bool aiKneel(void)
{
	chrTryKneel(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 000b
 */
bool aiChrDoAnimation(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 anim_id = cmd[3] | (cmd[2] << 8);
	s32 startframe = cmd[5] | (cmd[4] << 8);
	s32 endframe = cmd[7] | (cmd[6] << 8);
	struct chrdata *chr = NULL;
	f32 fstartframe;
	f32 fendframe;

	if (g_Vars.chrdata) {
		chr = chrFindById(g_Vars.chrdata, cmd[10]);
	}

	if (startframe == 0xffff) {
		fstartframe = 0;
	} else if (startframe == 0xfffe) {
		fstartframe = animGetNumFrames(anim_id) - 1;
	} else {
		fstartframe = startframe;
	}

	if (endframe == 0xffff) {
		fendframe = -1.0f;
	} else {
		fendframe = endframe;
	}

	if (chr && chr->animdata) {
		f32 result = 1.0f / (s32)cmd[11];

		if (g_Vars.in_cutscene) {
			if (startframe != 0xfffe) {
				fstartframe += var8009de20 * result * 0.25f;
			}

			chr->prop->unk3a = 0;
		}

		func0f03af44(chr, anim_id, fstartframe, fendframe, cmd[8], cmd[9], result);

		if (startframe == 0xfffe) {
			func0f0220ec(chr, 1, 1);

			if (chr->prop->type == PROPTYPE_PLAYER) {
				u32 playernum = propGetPlayerNum(chr->prop);
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
bool aiIfIdle(void)
{
	if (g_Vars.chrdata->actiontype == ACT_ANIM) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
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
bool aiBeSurprisedOneHand(void)
{
	chrTrySurprisedOneHand(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 000e
 */
bool aiBeSurprisedLookAround(void)
{
	chrTrySurprisedLookAround(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0032
 */
bool aiIfStopped(void)
{
	if (chrIsStopped(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0033
 */
bool aiIfChrDead(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if ((!chr || !chr->prop || chr->prop->type != PROPTYPE_PLAYER) && (!chr || !chr->animdata || chrIsDead(chr))) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0034
 */
bool aiIfChrDeathAnimationFinished(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	bool pass;

	if (!chr || !chr->prop) {
		pass = true;
	} else {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 playernum = propGetPlayerNum(chr->prop);
			pass = g_Vars.players[playernum]->isdead;
		} else {
			pass = (chr->actiontype == ACT_DEAD);
		}
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 017b
 */
bool aiIfChrKnockedOut(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if ((!chr || !chr->prop || chr->prop->type != PROPTYPE_PLAYER) &&
			(!chr || !chr->animdata || chr->actiontype == ACT_DRUGGEDKO || chr->actiontype == ACT_DRUGGEDDROP || chr->actiontype == ACT_DRUGGEDCOMINGUP)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0035
 */
bool aiIfTargetInSight(void)
{
	if (chrCheckTargetInSight(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 000f
 */
bool aiTrySidestep(void)
{
	if (chrTrySidestep(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0010
 */
bool aiTryJumpOut(void)
{
	if (chrTryJumpOut(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0011
 */
bool aiTryRunSideways(void)
{
	if (chrTryRunSideways(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0012
 */
bool aiTryAttackWalk(void)
{
	if (chrTryAttackWalk(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0013
 */
bool aiTryAttackRun(void)
{
	if (chrTryAttackRun(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0014
 */
bool aiTryAttackRoll(void)
{
	if (chrTryAttackRoll(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0015
 */
bool aiTryAttackStand(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chrTryAttackStand(g_Vars.chrdata, thingtype, thingid)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 0016
 */
bool aiTryAttackKneel(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chrTryAttackKneel(g_Vars.chrdata, thingtype, thingid)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 01ba
 */
bool aiTryAttackLie(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chrTryAttackLie(g_Vars.chrdata, thingtype, thingid)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
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
			!g_Vars.chrdata->act_attack.unk058 &&
			g_Vars.chrdata->act_attack.entitytype & ENTITYTYPE_DONTTURN) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 00f1
 */
bool aiIfAttacking(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->actiontype == ACT_ATTACK) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0017
 */
bool aiTryModifyAttack(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if ((g_Vars.chrdata && chrTryModifyAttack(g_Vars.chrdata, thingtype, thingid)) ||
			(g_Vars.hovercar && chopperAttack(g_Vars.hovercar))) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 0018
 */
bool aiFaceEntity(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chrFaceEntity(g_Vars.chrdata, thingtype, thingid)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
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
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	struct coord pos = {0, 0, 0};

	if (chr && chr->prop) {
		f32 value = func0f0b1d28(&cmd[4]);
		func0f034330(chr, value, &pos, &cmd[4], NULL, (s8)cmd[3]);
	}

	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 001a
 */
bool ai001a(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr1 = chrFindById(g_Vars.chrdata, cmd[2]);
	struct chrdata *chr2 = chrFindById(g_Vars.chrdata, cmd[3]);

	if (chr1 && chr2 && chr1->prop && chr2->prop) {
		struct prop *prop = chrGetEquippedWeaponPropWithCheck(chr1, 0);
		f32 thing;
		struct coord vector = {0, 0, 0};
		struct weaponobj *weapon;

		if (!prop) {
			prop = chrGetEquippedWeaponPropWithCheck(chr1, 1);
		}

		if (prop) {
			vector.x = chr2->prop->pos.x - chr1->prop->pos.x;
			vector.y = chr2->prop->pos.y - chr1->prop->pos.y;
			vector.z = chr2->prop->pos.z - chr1->prop->pos.z;
			scaleTo1(&vector.x, &vector.y, &vector.z);
			weapon = prop->weapon;
			thing = func0f0b1d28(&weapon->weapon_id);
			func0f034330(chr2, thing, &vector, &weapon->weapon_id, chr1->prop, (s8)cmd[4]);
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 001b
 */
bool aiConsiderGrenadeThrow(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 value2 = cmd[5] | (cmd[4] << 8);
	u32 value1 = cmd[3] | (cmd[2] << 8);

	if (chrConsiderGrenadeThrow(g_Vars.chrdata, value1, value2)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 001c
 */
bool aiDropItem(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 modelnum = cmd[3] | (cmd[2] << 8);

	if (chrDropItem(g_Vars.chrdata, modelnum & 0xffff, cmd[4] & 0xff)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 0024
 */
bool aiSurrender(void)
{
	chrTrySurrender(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0025
 */
bool aiFadeOut(void)
{
	chrFadeOut(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0026
 */
bool aiRemoveChr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		chr->hidden |= 0x20;
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0027
 */
bool aiTryStartAlarm(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[3] | (cmd[2] << 8);

	if (chrTryStartAlarm(g_Vars.chrdata, pad_id)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0028
 */
bool aiActivateAlarm(void)
{
	alarmActivate();
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0029
 */
bool aiDeactivateAlarm(void)
{
	alarmDeactivate();
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 002a
 */
bool aiTryRunFromTarget(void)
{
	if (chrTryRunFromTarget(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 002b
 */
bool aiTryJogToTargetProp(void)
{
	if (chrGoToTarget(g_Vars.chrdata, SPEED_JOG)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 002c
 */
bool aiTryWalkToTargetProp(void)
{
	if (chrGoToTarget(g_Vars.chrdata, SPEED_WALK)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 002d
 */
bool aiTryRunToTargetProp(void)
{
	if (chrGoToTarget(g_Vars.chrdata, SPEED_RUN)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 002e
 */
bool ai002e(void)
{
	if (func0f03b1e0(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist,g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 002f
 */
bool aiTryJogToChr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGoToChr(g_Vars.chrdata, cmd[2], SPEED_JOG)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0030
 */
bool aiTryWalkToChr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGoToChr(g_Vars.chrdata, cmd[2], SPEED_WALK)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0031
 */
bool aiTryRunToChr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGoToChr(g_Vars.chrdata, cmd[2], SPEED_RUN)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0036
 */
bool aiRandom(void)
{
	g_Vars.chrdata->random = random() & 0xff;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0037
 */
bool aiIfRandomLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((g_Vars.chrdata && g_Vars.chrdata->random < cmd[2]) ||
			(g_Vars.hovercar && ((u8)random()) < cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0038
 */
bool aiIfRandomGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((g_Vars.chrdata && g_Vars.chrdata->random > cmd[2]) ||
			(g_Vars.hovercar && ((u8)random()) > cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 001d
 */
bool aiJogToPad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad = cmd[3] | (cmd[2] << 8);

	func0f03a894(g_Vars.chrdata, pad, SPEED_JOG);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 001e
 */
bool aiGoToPadPreset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	switch (cmd[2]) {
	case 0:
		func0f03a894(g_Vars.chrdata, g_Vars.chrdata->padpreset1, SPEED_WALK);
		break;
	case 1:
		func0f03a894(g_Vars.chrdata, g_Vars.chrdata->padpreset1, SPEED_JOG);
		break;
	default:
		func0f03a894(g_Vars.chrdata, g_Vars.chrdata->padpreset1, SPEED_RUN);
		break;
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 001f
 */
bool aiWalkToPad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad = cmd[3] | (cmd[2] << 8);

	func0f03a894(g_Vars.chrdata, pad, SPEED_WALK);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0020
 */
bool aiRunToPad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad = cmd[3] | (cmd[2] << 8);

	func0f03a894(g_Vars.chrdata, pad, SPEED_RUN);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0021
 */
bool aiSetPath(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	chrSetPath(g_Vars.chrdata, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0022
 */
bool aiStartPath(void)
{
	chrStartPath(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0039
 */
bool aiIfChrAlarmActivate(void)
{
	if (func0f04a2b4(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0023
 */
bool aiIfPathStarted(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->actiontype == ACT_PATROL || (g_Vars.chrdata->actiontype == ACT_GOPOS && g_Vars.chrdata->act_gopos.unk065 & 8)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 003a
 */
bool aiIfAlarmActive(void)
{
	if (alarmIsActive()) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 003b
 */
bool aiIfAlarmInactive(void)
{
	if (func0f090520()) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * Either a check if chr is alerted or a check if they can hear gunfire.
 * Probably the latter.
 *
 * @cmd 003c
 */
bool ai003c(void)
{
	if (chrHasHiddenFlag00000002(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 003d
 */
bool aiIfSawInjury(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrSawInjury(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 003e
 */
bool aiIfSawDeath(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrSawDeath(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 003f
 */
bool aiIfSeesPlayer(void)
{
	if ((g_Vars.chrdata && func0f039368(g_Vars.chrdata)) ||
			(g_Vars.hovercar && func0f07ae18(g_Vars.hovercar, 0x40) && chopperCheckTargetVisible(g_Vars.hovercar))) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 017a
 */
bool ai017a(void)
{
	if ((g_Vars.chrdata && g_Vars.chrdata->prop && func0f0391ec(g_Vars.chrdata, &g_Vars.chrdata->prop->pos, &g_Vars.chrdata->prop->rooms[0], 1))
			|| (g_Vars.hovercar && func0f07ae18(g_Vars.hovercar, 0x40) && chopperCheckTargetVisible(g_Vars.hovercar))) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0040
 */
bool ai0040(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if (func0f04c6b4(g_Vars.chrdata, flags)) {
		cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 0041
 */
bool ai0041(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 value = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if (func0f04c71c(g_Vars.chrdata, value)) {
		cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 0042
 */
bool aiIfInLoadedRoom(void)
{
	if (chrIsInLoadedRoom(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0043
 */
bool aiIfSawTargetRecently(void)
{
	if (chrSawTargetRecently(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0044
 */
bool aiIfHeardTargetRecently(void)
{
	if (chrHeardTargetRecently(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0045
 */
bool ai0045(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && func0f0393b4(g_Vars.chrdata, &chr->prop->pos, &chr->prop->rooms[0])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0046
 */
bool aiIfNeverBeenOnScreen(void)
{
	if ((g_Vars.chrdata->chrflags & CHRCFLAG_NEVER_BEEN_ON_SCREEN) == 0) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0047
 */
bool ai0047(void)
{
	if (g_Vars.chrdata->prop->flags & 0xc2) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0048
 */
bool aiIfChrInActiveRoom(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	u8 pass = false;
	s32 i;

	if (chr && chr->prop) {
		for (i = 0; chr->prop->rooms[i] != -1; i++) {
			if (roomIsVisibleByAnyPlayer(chr->prop->rooms[i])) {
				pass = true;
			}
		}
	}

	if (pass) {
		cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0049
 */
bool aiIfRoomActive(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[3] | (cmd[2] << 8);
	s32 room_id = chrGetPadRoom(g_Vars.chrdata, pad_id);

	if (room_id >= 0 && roomIsVisibleByAnyPlayer(room_id)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 004a
 */
bool ai004a(void)
{
	if (func0f049fcc(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 004b
 */
bool aiIfNearMiss(void)
{
	if (chrResetNearMiss(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 004c
 */
bool aiIfSeesSuspiciousItem(void)
{
	s16 *ptr;
	bool pass = false;
	struct prop *prop;
	struct defaultobj *obj;
	s16 propnums[256];
	struct prop *chrprop = g_Vars.chrdata->prop;

	roomGetProps(&chrprop->rooms[0], &propnums[0], 256);

	ptr = &propnums[0];

	while (*ptr >= 0) {
		prop = &g_Vars.props[*ptr];
		obj = prop->obj;

		if (prop->type == PROPTYPE_WEAPON) {
			if ((obj->hidden & OBJHFLAG_00100000) && func0f039558(g_Vars.chrdata, prop)) {
				pass = true;
			}
		} else if (prop->type == PROPTYPE_OBJ) {
			if (((obj->hidden & OBJHFLAG_00100000) || !objIsHealthy(obj))
					&& func0f039558(g_Vars.chrdata, prop)) {
				pass = true;
			}
		} else if (prop->type == PROPTYPE_EXPLOSION) {
			if (func0f039558(g_Vars.chrdata, prop)) {
				pass = true;
			}
		}

		ptr++;
	}

	if (pass) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 004e
 */
bool ai004e(void)
{
	bool pass;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[4] == 0) {
		if (cmd[3]) {
			pass = func0f048e74(g_Vars.chrdata, cmd[2]);
		} else {
			pass = func0f048f20(g_Vars.chrdata, cmd[2]);
		}
	} else {
		pass = g_Vars.chrdata->yvisang && func0f048f20(g_Vars.chrdata, g_Vars.chrdata->yvisang) == 0;
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 004d
 */
bool ai004d(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGetAngleToTarget(g_Vars.chrdata) < cmd[2] * M_BADTAU * 0.00390625f) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 004f
 */
bool ai004f(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGetAngleToTarget(g_Vars.chrdata) > cmd[2] * M_BADTAU * 0.00390625f) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0050
 */
bool ai0050(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (func0f049068(g_Vars.chrdata, cmd[2], 0)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0051
 */
bool ai0051(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (!func0f049068(g_Vars.chrdata, cmd[2], 0)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0052
 */
bool aiIfDistanceToTargetLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) * (f32)10;

	if (chrGetDistanceToTarget(g_Vars.chrdata) < distance) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0053
 */
bool aiIfDistanceToTargetGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) * (f32)10;

	if (chrGetDistanceToTarget(g_Vars.chrdata) > distance) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0054
 */
bool aiIfChrDistanceToPadLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	s32 padnum = (cmd[6] | (cmd[5] << 8)) & 0xffff;
	f32 value = (cmd[4] | (cmd[3] << 8)) * 10.0f;
	s32 realpadnum = padnum;

	if (padnum == 9000) {
		realpadnum = (u16)g_Vars.chrdata->padpreset1;
	}

	if (chr && realpadnum < 9000 && chrGetDistanceToPad(chr, realpadnum) < value) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 8;
	}

	return false;
}

/**
 * @cmd 01df
 */
GLOBAL_ASM(
glabel aiIfChrSameFloorDistanceToPadLessThan
/*  f050c54:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f050c58:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f050c5c:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f050c60:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f050c64:	8e0e0434 */ 	lw	$t6,0x434($s0)
/*  f050c68:	8e0f0438 */ 	lw	$t7,0x438($s0)
/*  f050c6c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f050c70:	8e040424 */ 	lw	$a0,0x424($s0)
/*  f050c74:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f050c78:	90650002 */ 	lbu	$a1,0x2($v1)
/*  f050c7c:	0fc126d1 */ 	jal	chrFindById
/*  f050c80:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f050c84:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f050c88:	3c014120 */ 	lui	$at,0x4120
/*  f050c8c:	44814000 */ 	mtc1	$at,$f8
/*  f050c90:	906a0003 */ 	lbu	$t2,0x3($v1)
/*  f050c94:	906c0004 */ 	lbu	$t4,0x4($v1)
/*  f050c98:	90780005 */ 	lbu	$t8,0x5($v1)
/*  f050c9c:	000a5a00 */ 	sll	$t3,$t2,0x8
/*  f050ca0:	016c6825 */ 	or	$t5,$t3,$t4
/*  f050ca4:	448d2000 */ 	mtc1	$t5,$f4
/*  f050ca8:	90680006 */ 	lbu	$t0,0x6($v1)
/*  f050cac:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f050cb0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f050cb4:	03282025 */ 	or	$a0,$t9,$t0
/*  f050cb8:	00403025 */ 	or	$a2,$v0,$zero
/*  f050cbc:	3085ffff */ 	andi	$a1,$a0,0xffff
/*  f050cc0:	24012328 */ 	addiu	$at,$zero,0x2328
/*  f050cc4:	00c02025 */ 	or	$a0,$a2,$zero
/*  f050cc8:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f050ccc:	14a10003 */ 	bne	$a1,$at,.L0f050cdc
/*  f050cd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f050cd4:	8e0e0424 */ 	lw	$t6,0x424($s0)
/*  f050cd8:	95c50128 */ 	lhu	$a1,0x128($t6)
.L0f050cdc:
/*  f050cdc:	50400011 */ 	beqzl	$v0,.L0f050d24
/*  f050ce0:	8e0f0438 */ 	lw	$t7,0x438($s0)
/*  f050ce4:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f050ce8:	0fc124e0 */ 	jal	chrGetSameFloorDistanceToPad
/*  f050cec:	e7a20020 */ 	swc1	$f2,0x20($sp)
/*  f050cf0:	c7a20020 */ 	lwc1	$f2,0x20($sp)
/*  f050cf4:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f050cf8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f050cfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f050d00:	45020008 */ 	bc1fl	.L0f050d24
/*  f050d04:	8e0f0438 */ 	lw	$t7,0x438($s0)
/*  f050d08:	8e040434 */ 	lw	$a0,0x434($s0)
/*  f050d0c:	8e050438 */ 	lw	$a1,0x438($s0)
/*  f050d10:	0fc13583 */ 	jal	chraiGoToLabel
/*  f050d14:	90660007 */ 	lbu	$a2,0x7($v1)
/*  f050d18:	10000004 */ 	beqz	$zero,.L0f050d2c
/*  f050d1c:	ae020438 */ 	sw	$v0,0x438($s0)
/*  f050d20:	8e0f0438 */ 	lw	$t7,0x438($s0)
.L0f050d24:
/*  f050d24:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f050d28:	ae180438 */ 	sw	$t8,0x438($s0)
.L0f050d2c:
/*  f050d2c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f050d30:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f050d34:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f050d38:	03e00008 */ 	jr	$ra
/*  f050d3c:	00001025 */ 	or	$v0,$zero,$zero
);

/**
 * @cmd 0055
 */
GLOBAL_ASM(
glabel aiIfChrDistanceToPadGreaterThan
/*  f050d40:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f050d44:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f050d48:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f050d4c:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f050d50:	8e0e0434 */ 	lw	$t6,0x434($s0)
/*  f050d54:	8e0f0438 */ 	lw	$t7,0x438($s0)
/*  f050d58:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f050d5c:	8e040424 */ 	lw	$a0,0x424($s0)
/*  f050d60:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f050d64:	90650002 */ 	lbu	$a1,0x2($v1)
/*  f050d68:	0fc126d1 */ 	jal	chrFindById
/*  f050d6c:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f050d70:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f050d74:	3c014120 */ 	lui	$at,0x4120
/*  f050d78:	44814000 */ 	mtc1	$at,$f8
/*  f050d7c:	906a0003 */ 	lbu	$t2,0x3($v1)
/*  f050d80:	906c0004 */ 	lbu	$t4,0x4($v1)
/*  f050d84:	90780005 */ 	lbu	$t8,0x5($v1)
/*  f050d88:	000a5a00 */ 	sll	$t3,$t2,0x8
/*  f050d8c:	016c6825 */ 	or	$t5,$t3,$t4
/*  f050d90:	448d2000 */ 	mtc1	$t5,$f4
/*  f050d94:	90680006 */ 	lbu	$t0,0x6($v1)
/*  f050d98:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f050d9c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f050da0:	03282025 */ 	or	$a0,$t9,$t0
/*  f050da4:	3089ffff */ 	andi	$t1,$a0,0xffff
/*  f050da8:	24012328 */ 	addiu	$at,$zero,0x2328
/*  f050dac:	00403025 */ 	or	$a2,$v0,$zero
/*  f050db0:	01202025 */ 	or	$a0,$t1,$zero
/*  f050db4:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f050db8:	15210003 */ 	bne	$t1,$at,.L0f050dc8
/*  f050dbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f050dc0:	8e0e0424 */ 	lw	$t6,0x424($s0)
/*  f050dc4:	95c40128 */ 	lhu	$a0,0x128($t6)
.L0f050dc8:
/*  f050dc8:	10400013 */ 	beqz	$v0,.L0f050e18
/*  f050dcc:	28812328 */ 	slti	$at,$a0,0x2328
/*  f050dd0:	10200011 */ 	beqz	$at,.L0f050e18
/*  f050dd4:	00802825 */ 	or	$a1,$a0,$zero
/*  f050dd8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f050ddc:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f050de0:	0fc124bb */ 	jal	chrGetDistanceToPad
/*  f050de4:	e7a20020 */ 	swc1	$f2,0x20($sp)
/*  f050de8:	c7a20020 */ 	lwc1	$f2,0x20($sp)
/*  f050dec:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f050df0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f050df4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f050df8:	45020008 */ 	bc1fl	.L0f050e1c
/*  f050dfc:	8e0f0438 */ 	lw	$t7,0x438($s0)
/*  f050e00:	8e040434 */ 	lw	$a0,0x434($s0)
/*  f050e04:	8e050438 */ 	lw	$a1,0x438($s0)
/*  f050e08:	0fc13583 */ 	jal	chraiGoToLabel
/*  f050e0c:	90660007 */ 	lbu	$a2,0x7($v1)
/*  f050e10:	10000004 */ 	beqz	$zero,.L0f050e24
/*  f050e14:	ae020438 */ 	sw	$v0,0x438($s0)
.L0f050e18:
/*  f050e18:	8e0f0438 */ 	lw	$t7,0x438($s0)
.L0f050e1c:
/*  f050e1c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f050e20:	ae180438 */ 	sw	$t8,0x438($s0)
.L0f050e24:
/*  f050e24:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f050e28:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f050e2c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f050e30:	03e00008 */ 	jr	$ra
/*  f050e34:	00001025 */ 	or	$v0,$zero,$zero
);

/**
 * @cmd 0056
 */
bool aiIfDistanceToChrLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 cutoff = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chrGetDistanceToChr(g_Vars.chrdata, cmd[4]) < cutoff) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 0057
 */
bool aiIfDistanceToChrGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 cutoff = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chrGetDistanceToChr(g_Vars.chrdata, cmd[4]) > cutoff) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
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

	if (func0f04a76c(g_Vars.chrdata, distance)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0059
 */
bool aiIfDistanceFromTargetToPadLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad = cmd[5] | (cmd[4] << 8);
	f32 value = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chrGetDistanceFromTargetToPad(g_Vars.chrdata, pad) < value) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 005a
 */
bool aiIfDistanceFromTargetToPadGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad = cmd[5] | (cmd[4] << 8);
	f32 value = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chrGetDistanceFromTargetToPad(g_Vars.chrdata, pad) > value) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 005b
 */
bool aiIfChrInRoom(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	u16 pad_id = cmd[5] | (cmd[4] << 8);
	s32 room = chrGetPadRoom(g_Vars.chrdata, pad_id);

	if ((cmd[3] == 0 && room >= 0 && chr && chr->prop && chr->prop->rooms[0] == room) ||
			(cmd[3] == 1 && chr && chr->prop && chr->prop->rooms[0] == g_Vars.chrdata->roomtosearch)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
		return false;
	}

	if (cmd[3] == 2 && stageGetIndex(g_Vars.stagenum) == STAGEINDEX_G5BUILDING) {
		s32 i;
		bool pass = false;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.players[i]->eyespy && g_Vars.players[i]->eyespy->prop &&
					chrGetDistanceToPad(g_Vars.players[i]->eyespy->prop->chr, pad_id) < 150.0f) {
				pass = true;
			}
		}

		if (pass == true) {
			g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
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
bool aiIfTargetInRoom(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct prop *prop = chrGetTargetProp(g_Vars.chrdata);
	u16 pad_id = cmd[3] | (cmd[2] << 8);
	s32 room_id = chrGetPadRoom(g_Vars.chrdata, pad_id);

	if (room_id >= 0 && prop && room_id == prop->rooms[0]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 005d
 */
bool aiIfChrHasObject(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[3]);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	s32 playernum = 0;

	if (obj && obj->prop && chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		s32 prevplayernum = g_Vars.currentplayernum;
		playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);
		playernum = currentPlayerHasProp(obj->prop);
		setCurrentPlayerNum(prevplayernum);
	}

	if (playernum != 0) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 005e
 */
bool aiIfWeaponThrown(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (weaponFindThrown(cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 005f
 */
GLOBAL_ASM(
glabel aiIfWeaponThrownOnObject
/*  f05167c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f051680:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f051684:	8d0e0434 */ 	lw	$t6,0x434($t0)
/*  f051688:	8d0f0438 */ 	lw	$t7,0x438($t0)
/*  f05168c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f051690:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f051694:	01cf3821 */ 	addu	$a3,$t6,$t7
/*  f051698:	90e40003 */ 	lbu	$a0,0x3($a3)
/*  f05169c:	0fc2556c */ 	jal	objFindByTagId
/*  f0516a0:	afa7001c */ 	sw	$a3,0x1c($sp)
/*  f0516a4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0516a8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0516ac:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*  f0516b0:	10400014 */ 	beqz	$v0,.L0f051704
/*  f0516b4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0516b8:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f0516bc:	10800011 */ 	beqz	$a0,.L0f051704
/*  f0516c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0516c4:	8c83001c */ 	lw	$v1,0x1c($a0)
/*  f0516c8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0516cc:	1060000d */ 	beqz	$v1,.L0f051704
/*  f0516d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0516d4:	90780000 */ 	lbu	$t8,0x0($v1)
.L0f0516d8:
/*  f0516d8:	54980008 */ 	bnel	$a0,$t8,.L0f0516fc
/*  f0516dc:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f0516e0:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f0516e4:	90f90002 */ 	lbu	$t9,0x2($a3)
/*  f0516e8:	9049005c */ 	lbu	$t1,0x5c($v0)
/*  f0516ec:	57290003 */ 	bnel	$t9,$t1,.L0f0516fc
/*  f0516f0:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f0516f4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0516f8:	8c630020 */ 	lw	$v1,0x20($v1)
.L0f0516fc:
/*  f0516fc:	5460fff6 */ 	bnezl	$v1,.L0f0516d8
/*  f051700:	90780000 */ 	lbu	$t8,0x0($v1)
.L0f051704:
/*  f051704:	50a0000a */ 	beqzl	$a1,.L0f051730
/*  f051708:	8d0a0438 */ 	lw	$t2,0x438($t0)
/*  f05170c:	8d040434 */ 	lw	$a0,0x434($t0)
/*  f051710:	8d050438 */ 	lw	$a1,0x438($t0)
/*  f051714:	0fc13583 */ 	jal	chraiGoToLabel
/*  f051718:	90e60004 */ 	lbu	$a2,0x4($a3)
/*  f05171c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f051720:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f051724:	10000004 */ 	beqz	$zero,.L0f051738
/*  f051728:	ad020438 */ 	sw	$v0,0x438($t0)
/*  f05172c:	8d0a0438 */ 	lw	$t2,0x438($t0)
.L0f051730:
/*  f051730:	254b0005 */ 	addiu	$t3,$t2,0x5
/*  f051734:	ad0b0438 */ 	sw	$t3,0x438($t0)
.L0f051738:
/*  f051738:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f05173c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f051740:	00001025 */ 	or	$v0,$zero,$zero
/*  f051744:	03e00008 */ 	jr	$ra
/*  f051748:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch due to different registers
//bool aiIfWeaponThrownOnObject(void)
//{
//	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
//	struct defaultobj *obj = objFindByTagId(cmd[3]);
//	bool pass = false;
//
//	if (obj && obj->prop) {
//		struct prop *prop = obj->prop->child;
//
//		while (prop) {
//			if (prop->type == PROPTYPE_WEAPON) {
//				struct weaponobj *weapon = prop->weapon;
//
//				if (weapon->weapon_id == cmd[2]) {
//					pass = true;
//				}
//			}
//
//			prop = prop->next;
//		}
//	}
//
//	if (pass) {
//		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
//	} else {
//		g_Vars.aioffset += 5;
//	}
//
//	return false;
//}

/**
 * @cmd 0060
 */
bool aiIfChrHasWeaponEquipped(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	bool passes = false;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);

		if (getCurrentPlayerWeaponId(0) == cmd[3]) {
			passes = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	if (passes) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0061
 */
bool aiIfGunUnclaimed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[3] == 0) {
		struct defaultobj *obj = objFindByTagId(cmd[2]);

		if (obj && obj->prop) {
			g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
		} else {
			g_Vars.aioffset += 5;
		}
	} else {
		struct weaponobj *weapon = g_Vars.chrdata->gunprop->weapon;

		if (weapon && weapon->base.prop) {
			weapon->base.flags |= OBJFLAG_00400000;
			g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
		} else {
			g_Vars.aioffset += 5;
		}
	}

	return false;
}

/**
 * @cmd 0062
 */
bool aiIfObjectHealthy(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && objIsHealthy(obj)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0063
 */
bool aiIfChrActivatedObject(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[3]);
	u32 stack[1];
	bool pass = false;

	if (obj && obj->prop) {
		if (cmd[2] == CHR_ANY) {
			if (obj->hidden & (OBJHFLAG_ACTIVATED_BY_BOND | OBJHFLAG_ACTIVATED_BY_COOP)) {
				pass = true;
				obj->hidden &= ~(OBJHFLAG_ACTIVATED_BY_BOND | OBJHFLAG_ACTIVATED_BY_COOP);
			}
		} else {
			struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

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
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0065
 */
bool ai0065(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		if (obj->prop->type == PROPTYPE_DOOR) {
			doorActivateWrapper(obj->prop, 0);
		} else if (obj->prop->type == PROPTYPE_OBJ || obj->prop->type == PROPTYPE_WEAPON) {
			propobjInteract(obj->prop);
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0066
 */
bool aiDestroyObject(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && func0f0687b8(obj) == 0) {
		struct defaultobj *entity = obj->prop->obj;

		if (entity->obj == MODEL_ELVIS_SAUCER) {
			obj->flags = (obj->flags & ~OBJFLAG_00010000) | OBJFLAG_INVINCIBLE;
			func0f129900(entity->prop, &entity->prop->pos, &entity->prop->rooms[0], 3, 0);
			func0f12e714(entity->prop, 0x16);
		} else {
			f32 damage = ((obj->maxdamage - obj->damage) + 1) / 250.0f;
			func0f0852ac(obj, damage, &obj->prop->pos, 0x22, -1);
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
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->prop->parent && obj->prop->parent->type == PROPTYPE_CHR) {
		struct chrdata *chr = obj->prop->parent->chr;
		propobjSetDropped(obj->prop, 2);
		chr->hidden |= CHRHFLAG_00000001;
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0068
 */
bool aiChrDropItems(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		chrDropItems(chr);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0069
 */
bool aiChrDropWeapon(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		u32 weapon_id;
		setCurrentPlayerNum(playernum);
		weapon_id = getCurrentPlayerWeaponId(0);
		currentPlayerRemoveWeapon(weapon_id);
		func0f0a1c2c();
		setCurrentPlayerNum(prevplayernum);
	} else if (chr && chr->prop) {
		if (chr->weapons_held[0]) {
			propobjSetDropped(chr->weapons_held[0], 1);
			chr->hidden |= CHRHFLAG_00000001;
		}

		if (chr->weapons_held[1]) {
			propobjSetDropped(chr->weapons_held[1], 1);
			chr->hidden |= CHRHFLAG_00000001;
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 006a
 */
bool aiGiveObjectToChr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[3]);

	if (obj && obj->prop && chr && chr->prop) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 something;
			u32 prevplayernum = g_Vars.currentplayernum;
			struct defaultobj *obj2 = obj->prop->obj;
			u32 playernum = propGetPlayerNum(chr->prop);
			setCurrentPlayerNum(playernum);

			if (obj->prop->parent) {
				func0f082f88(obj->prop);
				func0f06ac90(obj->prop);
				func0f0604bc(obj->prop);
			}

			something = func0f088840(obj->prop, 0);
			func0f062b64(obj->prop, something);
			playernum = propGetPlayerNum(chr->prop);
			obj2->hidden = (playernum << 28) | (obj2->hidden & 0x0fffffff);
			setCurrentPlayerNum(prevplayernum);
		} else {
			if (obj->prop->parent) {
				func0f082f88(obj->prop);
			} else {
				func0f065c44(obj->prop);
				func0f0605c4(obj->prop);
				func0f060300(obj->prop);
			}

			if (obj->type != OBJTYPE_WEAPON || func0f08ae54(obj, chr) == 0) {
				propReparent(obj->prop, chr->prop);
			}
		}
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 006b
 */
bool aiObjectMoveToPad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	u16 padnum = cmd[4] | (cmd[3] << 8);
	f32 matrix[16];
	struct pad pad;
	s16 rooms[2];

	if (obj && obj->prop) {
		padUnpack(padnum, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_ROOM, &pad);
		func00016d58(matrix,
				0, 0, 0,
				-pad.look.x, -pad.look.y, -pad.look.z,
				pad.up.x, pad.up.y, pad.up.z);

		if (obj->animdata) {
			func00015f04(obj->animdata->unk14, matrix);
		}

		rooms[0] = pad.room;
		rooms[1] = -1;
		func0f06a730(obj, &pad, matrix, rooms, &pad);
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 006c
 */
bool aiOpenDoor(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		if (!func0f066310(obj->prop, 0)) {
			struct doorobj *door = (struct doorobj *) obj;
			doorActivate(door, DOORMODE_OPENING);
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 006d
 */
bool aiCloseDoor(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		doorActivate(door, DOORMODE_CLOSING);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 006e
 */
bool aiIfDoorState(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	bool pass = false;

	if (obj && obj->prop && obj->type == OBJTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;

		if (door->mode == DOORMODE_IDLE) {
			if (door->frac <= 0) {
				pass = (cmd[3] & DOORSTATE_CLOSED) != 0;
			} else {
				pass = (cmd[3] & DOORSTATE_OPEN) != 0;
			}
		} else if (door->mode == DOORMODE_OPENING || door->mode == DOORMODE_3) {
			pass = (cmd[3] & DOORSTATE_OPENING) != 0;
		} else if (door->mode == DOORMODE_CLOSING) {
			pass = (cmd[3] & DOORSTATE_CLOSING) != 0;
		}
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 006f
 */
bool aiIfObjectIsDoor(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->type == OBJTYPE_DOOR && (obj->hidden & 0x200)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0070
 */
bool aiLockDoor(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

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
bool aiUnlockDoor(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

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
bool aiIfDoorLocked(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);
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
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0073
 */
bool aiIfObjectiveComplete(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] < objectiveGetCount() &&
			objectiveGetStatus(cmd[2]) == OBJECTIVE_COMPLETE &&
			objectiveGetDifficultyBits(cmd[2]) & (1 << getDifficulty())) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0074
 */
bool aiIfObjectiveFailed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] < objectiveGetCount() &&
			objectiveGetStatus(cmd[2]) == OBJECTIVE_FAILED &&
			objectiveGetDifficultyBits(cmd[2]) & (1 << getDifficulty())) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
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
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0076
 */
bool ai0076(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (func0f04a674(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 007d
 */
bool aiIfNumArghsLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGetNumArghs(g_Vars.chrdata) < cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 007e
 */
bool aiIfNumArghsGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGetNumArghs(g_Vars.chrdata) > cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 007f
 */
bool aiIfNumCloseArghsLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGetNumCloseArghs(g_Vars.chrdata) < cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0080
 */
bool aiIfNumCloseArghsGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGetNumCloseArghs(g_Vars.chrdata) > cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0081
 */
bool aiIfChrHealthGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = cmd[3] * 0.1f;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	u32 pass = false;

	if (chr && chr->prop) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 playernum = propGetPlayerNum(chr->prop);

			pass = (value > g_Vars.players[playernum]->bondhealth * 8.0f);
		} else {
			pass = (value > chr->maxdamage - chr->damage);
		}
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0082
 */
bool aiIfChrHealthLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = cmd[3] * 0.1f;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	u32 pass = false;

	if (chr && chr->prop) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 playernum = propGetPlayerNum(chr->prop);

			pass = (value < g_Vars.players[playernum]->bondhealth * 8.0f);
		} else {
			pass = (value < chr->maxdamage - chr->damage);
		}
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 010f
 */
bool aiIfChrShieldLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = (cmd[4] | (cmd[3] << 8)) * 0.1f;
	struct chrdata *chr = chrFindById(g_Vars.chrdata,cmd[2]);

	if (chr && chrGetShield(chr) < value) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 6;
	}

	return false;
}

/**
 * @cmd 0110
 */
bool aiIfChrShieldGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = (cmd[4] | (cmd[3] << 8)) * 0.1f;
	struct chrdata *chr = chrFindById(g_Vars.chrdata,cmd[2]);

	if (chr && chrGetShield(chr) > value) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 6;
	}

	return false;
}

/**
 * @cmd 0083
 */
bool aiIfInjured(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_JUST_INJURED)) {
		chr->chrflags &= ~CHRCFLAG_JUST_INJURED;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 4;
	}

	return false;
}

/**
 * @cmd 0168
 */
bool ai0168(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_02000000)) {
		chr->chrflags &= ~CHRCFLAG_02000000;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 4;
	}

	return false;
}

/**
 * @cmd 0077
 */
bool aiIfDifficultyLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (getDifficulty() < cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0078
 */
bool aiIfDifficultyGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (getDifficulty() > cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

f32 getUptime(void);

/**
 * @cmd 0079
 */
bool aiIfUptimeLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 target = (f32)(cmd[3] | (cmd[2] << 8));
	f32 uptime = getUptime();

	if (uptime < target) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 007a
 */
bool aiIfUptimeGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 target = (f32)(cmd[3] | (cmd[2] << 8));
	f32 uptime = getUptime();

	if (uptime > target) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 007b
 */
bool aiIfStageIdLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] > getCurrentStageId()) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 007c
 */
bool aiIfStageIdGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (getCurrentStageId() > cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0084
 */
bool aiSetMorale(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.chrdata->morale = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0085
 */
bool aiAddMorale(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	incrementByte(&g_Vars.chrdata->morale, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0086
 */
bool aiChrAddMorale(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[3]);
	incrementByte(&chr->morale, cmd[2]);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0087
 */
bool aiSubtractMorale(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	decrementByte(&g_Vars.chrdata->morale, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0088
 */
bool aiIfMoraleLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->morale < cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0089
 */
bool aiIfMoraleLessThanRandom(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->morale < g_Vars.chrdata->random) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 008a
 */
bool aiSetAlertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.chrdata->alertness = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 008b
 */
bool aiAddAlertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	incrementByte(&g_Vars.chrdata->alertness, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 008c
 */
bool aiChrAddAlertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[3]);

	if (chr && chr->prop) {
		incrementByte(&chr->alertness, cmd[2]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 008d
 */
bool aiSubtractAlertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	decrementByte(&g_Vars.chrdata->alertness, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 008e
 */
bool aiIfAlertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((g_Vars.chrdata->alertness < cmd[2] && cmd[3] == 0) ||
			(cmd[2] < g_Vars.chrdata->alertness && cmd[3] == 1)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 008f
 */
bool aiIfChrAlertnessLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[3]);

	if (chr && chr->alertness < cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0090
 */
bool aiIfAlertnessLessThanRandom(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->alertness < g_Vars.chrdata->random) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0092
 */
bool aiSetHearDistance(void)
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
bool aiSetViewDistance(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (!cheatIsActive(CHEAT_PERFECTDARKNESS)) {
		g_Vars.chrdata->visionrange = cmd[2];
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0094
 */
bool aiSetGrenadeProbability(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.chrdata->grenadeprob = cmd[2];
	g_Vars.aioffset += + 3;

	return false;
}

/**
 * @cmd 0095
 */
bool aiSetChrNum(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	chrSetChrnum(g_Vars.chrdata, cmd[2]);
	g_Vars.chrdata->chrnum = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0096
 */
GLOBAL_ASM(
glabel aiSetMaxDamage
.late_rodata
glabel var7f1a9c48
.word 0x3dcccccd
.text
/*  f053938:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f05393c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f053940:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f053944:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f053948:	8e0e0434 */ 	lw	$t6,0x434($s0)
/*  f05394c:	8e0f0438 */ 	lw	$t7,0x438($s0)
/*  f053950:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f053954:	3c017f1b */ 	lui	$at,%hi(var7f1a9c48)
/*  f053958:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f05395c:	90580003 */ 	lbu	$t8,0x3($v0)
/*  f053960:	90480004 */ 	lbu	$t0,0x4($v0)
/*  f053964:	c4289c48 */ 	lwc1	$f8,%lo(var7f1a9c48)($at)
/*  f053968:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f05396c:	03284825 */ 	or	$t1,$t9,$t0
/*  f053970:	44892000 */ 	mtc1	$t1,$f4
/*  f053974:	8e040430 */ 	lw	$a0,0x430($s0)
/*  f053978:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f05397c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f053980:	46083002 */ 	mul.s	$f0,$f6,$f8
/*  f053984:	50800026 */ 	beqzl	$a0,.L0f053a20
/*  f053988:	90450002 */ 	lbu	$a1,0x2($v0)
/*  f05398c:	444af800 */ 	cfc1	$t2,$31
/*  f053990:	44c5f800 */ 	ctc1	$a1,$31
/*  f053994:	3c014f00 */ 	lui	$at,0x4f00
/*  f053998:	460002a4 */ 	cvt.w.s	$f10,$f0
/*  f05399c:	4445f800 */ 	cfc1	$a1,$31
/*  f0539a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0539a4:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0539a8:	50a00013 */ 	beqzl	$a1,.L0f0539f8
/*  f0539ac:	44055000 */ 	mfc1	$a1,$f10
/*  f0539b0:	44815000 */ 	mtc1	$at,$f10
/*  f0539b4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0539b8:	460a0281 */ 	sub.s	$f10,$f0,$f10
/*  f0539bc:	44c5f800 */ 	ctc1	$a1,$31
/*  f0539c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0539c4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0539c8:	4445f800 */ 	cfc1	$a1,$31
/*  f0539cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0539d0:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0539d4:	14a00005 */ 	bnez	$a1,.L0f0539ec
/*  f0539d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0539dc:	44055000 */ 	mfc1	$a1,$f10
/*  f0539e0:	3c018000 */ 	lui	$at,0x8000
/*  f0539e4:	10000007 */ 	beqz	$zero,.L0f053a04
/*  f0539e8:	00a12825 */ 	or	$a1,$a1,$at
.L0f0539ec:
/*  f0539ec:	10000005 */ 	beqz	$zero,.L0f053a04
/*  f0539f0:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0539f4:	44055000 */ 	mfc1	$a1,$f10
.L0f0539f8:
/*  f0539f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0539fc:	04a0fffb */ 	bltz	$a1,.L0f0539ec
/*  f053a00:	00000000 */ 	sll	$zero,$zero,0x0
.L0f053a04:
/*  f053a04:	44caf800 */ 	ctc1	$t2,$31
/*  f053a08:	30abffff */ 	andi	$t3,$a1,0xffff
/*  f053a0c:	0fc1ec56 */ 	jal	chopperSetMaxDamage
/*  f053a10:	01602825 */ 	or	$a1,$t3,$zero
/*  f053a14:	10000021 */ 	beqz	$zero,.L0f053a9c
/*  f053a18:	8e0d0438 */ 	lw	$t5,0x438($s0)
/*  f053a1c:	90450002 */ 	lbu	$a1,0x2($v0)
.L0f053a20:
/*  f053a20:	e7a00028 */ 	swc1	$f0,0x28($sp)
/*  f053a24:	0fc126d1 */ 	jal	chrFindById
/*  f053a28:	8e040424 */ 	lw	$a0,0x424($s0)
/*  f053a2c:	c7a00028 */ 	lwc1	$f0,0x28($sp)
/*  f053a30:	10400019 */ 	beqz	$v0,.L0f053a98
/*  f053a34:	00402025 */ 	or	$a0,$v0,$zero
/*  f053a38:	8c4c001c */ 	lw	$t4,0x1c($v0)
/*  f053a3c:	51800017 */ 	beqzl	$t4,.L0f053a9c
/*  f053a40:	8e0d0438 */ 	lw	$t5,0x438($s0)
/*  f053a44:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f053a48:	0fc0e6a5 */ 	jal	chrIsDead
/*  f053a4c:	e7a00028 */ 	swc1	$f0,0x28($sp)
/*  f053a50:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f053a54:	14400010 */ 	bnez	$v0,.L0f053a98
/*  f053a58:	c7a00028 */ 	lwc1	$f0,0x28($sp)
/*  f053a5c:	80820007 */ 	lb	$v0,0x7($a0)
/*  f053a60:	24010005 */ 	addiu	$at,$zero,0x5
/*  f053a64:	1041000c */ 	beq	$v0,$at,.L0f053a98
/*  f053a68:	24010004 */ 	addiu	$at,$zero,0x4
/*  f053a6c:	1041000a */ 	beq	$v0,$at,.L0f053a98
/*  f053a70:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f053a74:	10410008 */ 	beq	$v0,$at,.L0f053a98
/*  f053a78:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f053a7c:	10410006 */ 	beq	$v0,$at,.L0f053a98
/*  f053a80:	24010020 */ 	addiu	$at,$zero,0x20
/*  f053a84:	50410005 */ 	beql	$v0,$at,.L0f053a9c
/*  f053a88:	8e0d0438 */ 	lw	$t5,0x438($s0)
/*  f053a8c:	44050000 */ 	mfc1	$a1,$f0
/*  f053a90:	0fc08166 */ 	jal	chrSetMaxDamage
/*  f053a94:	00000000 */ 	sll	$zero,$zero,0x0
.L0f053a98:
/*  f053a98:	8e0d0438 */ 	lw	$t5,0x438($s0)
.L0f053a9c:
/*  f053a9c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f053aa0:	00001025 */ 	or	$v0,$zero,$zero
/*  f053aa4:	25ae0005 */ 	addiu	$t6,$t5,0x5
/*  f053aa8:	ae0e0438 */ 	sw	$t6,0x438($s0)
/*  f053aac:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f053ab0:	03e00008 */ 	jr	$ra
/*  f053ab4:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

/**
 * @cmd 0097
 */
bool aiAddHealth()
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 amount = (cmd[3] | (cmd[2] << 8)) * 0.1f;

	chrAddHealth(g_Vars.chrdata, amount);

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 010e
 */
bool aiSetShield(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 amount = (cmd[3] | (cmd[2] << 8)) * 0.1f;

	if (cheatIsActive(CHEAT_ENEMYSHIELDS)) {
		amount = amount < 8 ? 8 : amount;
	}

	chrSetShield(g_Vars.chrdata, amount);

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0098
 */
bool aiSetReactionSpeed(void)
{
	s8 *cmd = (s8 *)g_Vars.ailist + g_Vars.aioffset;

	g_Vars.chrdata->speedrating = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0099
 */
bool aiSetRecoverySpeed(void)
{
	s8 *cmd = (s8 *)g_Vars.ailist + g_Vars.aioffset;

	g_Vars.chrdata->arghrating = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 009a
 */
bool aiSetAccuracy(void)
{
	s8 *cmd = (s8 *)g_Vars.ailist + g_Vars.aioffset;

	g_Vars.chrdata->accuracyrating = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01c6
 */
bool aiSetDodgeRating(void)
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
bool aiSetUnarmedDodgeRating(void)
{
	s8 *cmd = (s8 *)g_Vars.ailist + g_Vars.aioffset;

	g_Vars.chrdata->unarmeddodgerating = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 009b
 */
bool aiSetFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chrSetFlags(g_Vars.chrdata, flags, cmd[6]);

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 009c
 */
bool aiUnsetFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chrUnsetFlags(g_Vars.chrdata, flags, cmd[6]);

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 009d
 */
bool aiIfHasFlag(void)
{
	bool result;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	result = chrHasFlag(g_Vars.chrdata, flags, cmd[7]);

	if (cmd[6] == 0) {
		result = !result;
	}

	if (result) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[8]);
	} else {
		g_Vars.aioffset += 9;
	}

	return false;
}

/**
 * @cmd 009e
 */
bool aiChrSetFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	chrSetFlagsById(g_Vars.chrdata, cmd[2], flags, cmd[7]);
	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 009f
 */
bool aiChrUnsetFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	chrUnsetFlagsById(g_Vars.chrdata, cmd[2], flags, cmd[7]);
	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 00a0
 */
bool aiIfChrHasFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);

	if (chrHasFlagById(g_Vars.chrdata, cmd[2], flags, cmd[7])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[8]);
	} else {
		g_Vars.aioffset += 9;
	}

	return false;
}

/**
 * @cmd 00a1
 */
bool aiSetStageFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chrSetStageFlag(g_Vars.chrdata, flags);
	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00a2
 */
bool aiUnsetStageFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chrUnsetStageFlag(g_Vars.chrdata, flags);
	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00a3
 */
bool aiIfStageFlagEq(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if ((chrHasStageFlag(g_Vars.chrdata, flags) && cmd[6] == 1) ||
			(!chrHasStageFlag(g_Vars.chrdata, flags) && cmd[6] == 0)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 00a4
 */
bool aiSetChrflag(void)
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
bool aiUnsetChrflag(void)
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
bool aiIfHasChrflag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if ((g_Vars.chrdata->chrflags & flags) == flags) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 00a7
 */
bool aiChrSetChrflag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->chrflags |= flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00a8
 */
bool aiChrUnsetChrflag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->chrflags &= ~flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00a9
 */
bool aiIfChrHasChrflag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & flags) == flags) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 011b
 */
bool aiChrSetHiddenFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->hidden |= flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 011c
 */
bool aiChrUnsetHiddenFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->hidden &= ~flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 011d
 */
bool aiIfChrHasHiddenFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->hidden & flags) == flags) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 00aa
 */
bool aiSetObjFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags |= flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00ab
 */
bool aiUnsetObjFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags &= ~flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00ac
 */
bool aiIfObjHasFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && (obj->flags & flags) == flags) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 00ad
 */
bool aiSetObjFlag2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags2 |= flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00ae
 */
bool aiUnsetObjFlag2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags2 &= ~flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00af
 */
bool aiIfObjHasFlag2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && (obj->flags2 & flags) == flags) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 0118
 */
bool aiSetObjFlag3(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags3 |= flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 0119
 */
bool aiUnsetObjFlag3(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags3 &= ~flags;
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 011a
 */
bool aiIfObjHasFlag3(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && (obj->flags3 & flags) == flags) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 00b0
 */
bool aiSetChrPreset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	chrSetChrPreset(g_Vars.chrdata, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00b1
 */
bool aiSetChrTarget(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	chrSetChrPresetByChrnum(g_Vars.chrdata, cmd[2], cmd[3]);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00b2
 */
bool aiSetPadPreset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata) {
		chrSetPadPreset(g_Vars.chrdata, pad_id);
	} else if (g_Vars.heli) {
		g_Vars.heli->base.pad = pad_id;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00b3
 */
bool aiChrSetPadPreset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[4] | (cmd[3] << 8);

	chrSetPadPresetByChrnum(g_Vars.chrdata, cmd[2], pad_id);

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 00b4
 */
bool aiChrCopyPadPreset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chrsrc = chrFindById(g_Vars.chrdata, cmd[2]);
	struct chrdata *chrdst = chrFindById(g_Vars.chrdata, cmd[3]);

	chrdst->padpreset1 = chrsrc->padpreset1;
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00b5
 */
GLOBAL_ASM(
glabel aiPrint
/*  f054ec4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f054ec8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f054ecc:	0fc47bba */ 	jal	dprint
/*  f054ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f054ed4:	10400001 */ 	beqz	$v0,.L0f054edc
/*  f054ed8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
.L0f054edc:
/*  f054edc:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f054ee0:	8c640434 */ 	lw	$a0,0x434($v1)
/*  f054ee4:	0fc136d0 */ 	jal	chraiGetCommandLength
/*  f054ee8:	8c650438 */ 	lw	$a1,0x438($v1)
/*  f054eec:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f054ef0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f054ef4:	8c6e0438 */ 	lw	$t6,0x438($v1)
/*  f054ef8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f054efc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f054f00:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f054f04:	ac6f0438 */ 	sw	$t7,0x438($v1)
/*  f054f08:	03e00008 */ 	jr	$ra
/*  f054f0c:	00001025 */ 	or	$v0,$zero,$zero
);

// Mismatch because the if statement gets optimised out
//bool aiPrint(void)
//{
//	u32 len;
//
//	if (dprint()) {
//		// empty
//	}
//
//	len = chraiGetCommandLength(g_Vars.ailist, g_Vars.aioffset);
//
//	g_Vars.aioffset += len;
//
//	return false;
//}

/**
 * @cmd 0091
 */
bool aiNoOp0091(void)
{
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 00b6
 */
bool aiRestartTimer(void)
{
	if (g_Vars.chrdata) {
		chrRestartTimer(g_Vars.chrdata);
	} else if (g_Vars.hovercar) {
		chopperRestartTimer(g_Vars.hovercar);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00b7
 */
bool aiResetTimer(void)
{
	g_Vars.chrdata->timer60 = 0;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00b8
 */
bool aiPauseTimer(void)
{
	g_Vars.chrdata->hidden &= ~CHRHFLAG_TIMER_RUNNING;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00b9
 */
bool aiResumeTimer(void)
{
	g_Vars.chrdata->hidden |= CHRHFLAG_TIMER_RUNNING;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00ba
 */
bool aiIfTimerStopped(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((g_Vars.chrdata->hidden & CHRHFLAG_TIMER_RUNNING) == 0) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 00bb
 */
bool aiIfTimerGreaterThanRandom(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 timer = chrGetTimer(g_Vars.chrdata);

	if (g_Vars.chrdata->random < timer) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 00bc
 */
bool aiIfTimerLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = (u32)((cmd[3] << 8) | cmd[4] | (cmd[2] << 16)) / 60.0f;

	if ((g_Vars.chrdata && chrGetTimer(g_Vars.chrdata) < value) ||
			(g_Vars.hovercar && chopperGetTimer(g_Vars.hovercar) < value)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 00bd
 */
bool aiIfTimerGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = (u32)((cmd[3] << 8) | cmd[4] | (cmd[2] << 16)) / 60.0f;

	// These two function calls were likely used in a debug print statement
	if (g_Vars.chrdata) {
		chrGetTimer(g_Vars.chrdata);
	}

	if (g_Vars.hovercar) {
		chopperGetTimer(g_Vars.hovercar);
	}

	if ((g_Vars.chrdata && chrGetTimer(g_Vars.chrdata) > value) ||
			(g_Vars.hovercar && chopperGetTimer(g_Vars.hovercar) > value)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 00be
 */
bool aiShowCountdownTimer(void)
{
	countdownTimerSetVisible(1, true);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00bf
 */
bool aiHideCountdownTimer(void)
{
	countdownTimerSetVisible(1, false);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00c0
 */
bool aiSetCountdownTimerValue(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 seconds = cmd[3] | (cmd[2] << 8);

	countdownTimerSetValue(seconds * 60);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00c1
 */
bool aiStopCountdownTimer(void)
{
	countdownTimerSetRunning(false);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00c2
 */
bool aiStartCountdownTimer(void)
{
	countdownTimerSetRunning(true);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00c3
 */
bool aiIfCountdownTimerStopped(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (!countdownTimerIsRunning()) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 00c4
 */
bool aiIfCountdownTimerLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = cmd[3] | (cmd[2] << 8);

	if (countdownTimerGetValue() < value * 60) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 00c5
 */
bool aiIfCountdownTimerGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 value = cmd[3] | (cmd[2] << 8);

	if (countdownTimerGetValue() > value * 60) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 00c6
 */
GLOBAL_ASM(
glabel aiSpawnChrAtPad
/*  f05565c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f055660:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f055664:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f055668:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f05566c:	8e0e0434 */ 	lw	$t6,0x434($s0)
/*  f055670:	8e0f0438 */ 	lw	$t7,0x438($s0)
/*  f055674:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f055678:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f05567c:	90780004 */ 	lbu	$t8,0x4($v1)
/*  f055680:	906a0005 */ 	lbu	$t2,0x5($v1)
/*  f055684:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f055688:	032a5825 */ 	or	$t3,$t9,$t2
/*  f05568c:	a7ab0032 */ 	sh	$t3,0x32($sp)
/*  f055690:	906e0009 */ 	lbu	$t6,0x9($v1)
/*  f055694:	906c0008 */ 	lbu	$t4,0x8($v1)
/*  f055698:	9079000a */ 	lbu	$t9,0xa($v1)
/*  f05569c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f0556a0:	000c6e00 */ 	sll	$t5,$t4,0x18
/*  f0556a4:	906e0006 */ 	lbu	$t6,0x6($v1)
/*  f0556a8:	01afc025 */ 	or	$t8,$t5,$t7
/*  f0556ac:	906c000b */ 	lbu	$t4,0xb($v1)
/*  f0556b0:	906f0007 */ 	lbu	$t7,0x7($v1)
/*  f0556b4:	00195200 */ 	sll	$t2,$t9,0x8
/*  f0556b8:	030a5825 */ 	or	$t3,$t8,$t2
/*  f0556bc:	000e6a00 */ 	sll	$t5,$t6,0x8
/*  f0556c0:	016c4025 */ 	or	$t0,$t3,$t4
/*  f0556c4:	01af1025 */ 	or	$v0,$t5,$t7
/*  f0556c8:	3044ffff */ 	andi	$a0,$v0,0xffff
/*  f0556cc:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0556d0:	0c006134 */ 	jal	ailistFindById
/*  f0556d4:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0556d8:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0556dc:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0556e0:	8e040424 */ 	lw	$a0,0x424($s0)
/*  f0556e4:	90650002 */ 	lbu	$a1,0x2($v1)
/*  f0556e8:	80660003 */ 	lb	$a2,0x3($v1)
/*  f0556ec:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0556f0:	97a70032 */ 	lhu	$a3,0x32($sp)
/*  f0556f4:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0556f8:	0fc12d5e */ 	jal	chrSpawnAtPad
/*  f0556fc:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f055700:	10400007 */ 	beqz	$v0,.L0f055720
/*  f055704:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f055708:	8e040434 */ 	lw	$a0,0x434($s0)
/*  f05570c:	8e050438 */ 	lw	$a1,0x438($s0)
/*  f055710:	0fc13583 */ 	jal	chraiGoToLabel
/*  f055714:	9066000c */ 	lbu	$a2,0xc($v1)
/*  f055718:	10000004 */ 	beqz	$zero,.L0f05572c
/*  f05571c:	ae020438 */ 	sw	$v0,0x438($s0)
.L0f055720:
/*  f055720:	8e180438 */ 	lw	$t8,0x438($s0)
/*  f055724:	270a000d */ 	addiu	$t2,$t8,0xd
/*  f055728:	ae0a0438 */ 	sw	$t2,0x438($s0)
.L0f05572c:
/*  f05572c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f055730:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f055734:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f055738:	03e00008 */ 	jr	$ra
/*  f05573c:	00001025 */ 	or	$v0,$zero,$zero
);

//bool aiSpawnChrAtPad(void)
//{
//	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
//	u16 pad = cmd[5] | (cmd[4] << 8);
//	u32 flags = (cmd[9] << 16) | (cmd[10] << 8) | cmd[11] | (cmd[8] << 24);
//	s32 ailistid = cmd[7] | (cmd[6] << 8);
//	u8 *ailist = ailistFindById(ailistid & 0xffff);
//
//	if (chrSpawnAtPad(g_Vars.chrdata, cmd[2], (s8)cmd[3], pad, ailist, flags)) {
//		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[12]);
//	} else {
//		g_Vars.aioffset += 13;
//	}
//
//	return false;
//}

/**
 * @cmd 00c7
 */
bool aiSpawnChrAtChr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[8] << 16) | (cmd[9] << 8) | cmd[10] | (cmd[7] << 24);
	u16 ailistid = cmd[6] | (cmd[5] << 8);
	u8 *ailist = ailistFindById(ailistid);

	if (chrSpawnAtChr(g_Vars.chrdata, cmd[2], (s8)cmd[3], cmd[4], ailist, flags)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[11]);
	} else {
		g_Vars.aioffset += 12;
	}

	return false;
}

/**
 * @cmd 00c8
 */
bool aiTryEquipWeapon(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[6] << 16) | (cmd[7] << 8) | cmd[8] | (cmd[5] << 24);
	u32 model = cmd[3] | (cmd[2] << 8);
	struct prop *prop = NULL;

	if (g_Vars.chrdata && g_Vars.chrdata->prop && g_Vars.chrdata->animdata) {
		if (cheatIsActive(CHEAT_MARQUIS)) {
			flags &= ~0x10000000;
			flags |= 0x20000000;

			prop = chrGiveWeapon(g_Vars.chrdata, model, cmd[4], flags);
		} else if (cheatIsActive(CHEAT_ENEMYROCKETS)) {
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
			case WEAPON_CALLISTONTG:
			case WEAPON_RCP120:
			case WEAPON_LAPTOPGUN:
			case WEAPON_DRAGON:
			case WEAPON_AR34:
			case WEAPON_SUPERDRAGON:
			case WEAPON_SHOTGUN:
			case WEAPON_REAPER:
			case WEAPON_SNIPERRIFLE:
			case WEAPON_FARSIGHTXR20:
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
				prop = chrGiveWeapon(g_Vars.chrdata, MODEL_CHRDYROCKET, WEAPON_ROCKETLAUNCHER, flags);
				break;
			case WEAPON_K7AVENGER:
				if (g_Vars.stagenum == STAGE_INVESTIGATION && getDifficulty() == DIFF_PA) {
					prop = chrGiveWeapon(g_Vars.chrdata, model, cmd[4], flags);
				} else {
					prop = chrGiveWeapon(g_Vars.chrdata, MODEL_CHRDYROCKET, WEAPON_ROCKETLAUNCHER, flags);
				}
				break;
			default:
				prop = chrGiveWeapon(g_Vars.chrdata, model, cmd[4], flags);
				break;
			}
		} else {
			prop = chrGiveWeapon(g_Vars.chrdata, model, cmd[4], flags);
		}
	}

	if (prop) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[9]);
	} else {
		g_Vars.aioffset += 10;
	}

	return false;
}

/**
 * @cmd 00c9
 */
bool aiTryEquipHat(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[5] << 16) | (cmd[6] << 8) | cmd[7] | (cmd[4] << 24);
	u32 thing = cmd[3] | (cmd[2] << 8);
	bool ok = false;

	if (g_Vars.chrdata && g_Vars.chrdata->prop && g_Vars.chrdata->animdata) {
		ok = chrTryEquipHat(g_Vars.chrdata, thing, flags);
	}

	if (ok) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[8]);
	} else {
		g_Vars.aioffset += 9;
	}

	return false;
}

/**
 * @cmd 00ca
 */
bool aiDuplicateChr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[6] << 16) | (cmd[7] << 8) | cmd[8] | (cmd[5] << 24);
	u16 ailistid = cmd[4] | (cmd[3] << 8);
	u8 *ailist = ailistFindById(ailistid);
	bool pass = false;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
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
		cloneprop = chrSpawnAtChr(g_Vars.chrdata, chr->bodynum, -1, chr->chrnum, ailist, flags);

		if (cloneprop) {
			clone = cloneprop->chr;
			chrSetChrnum(clone, getLowestUnusedChrId());
			chr->chrdup = clone->chrnum;

			srcweapon0prop = chrGetEquippedWeaponProp(chr, 0);

			if (srcweapon0prop) {
				srcweapon0 = srcweapon0prop->weapon;
				cloneweapon0prop = chrGiveWeapon(clone, srcweapon0->base.obj, srcweapon0->weapon_id, 0);

				if (cloneweapon0prop) {
					cloneweapon0 = cloneweapon0prop->weapon;
				}
			}

			srcweapon1prop = chrGetEquippedWeaponProp(chr, 1);

			if (srcweapon1prop) {
				srcweapon1 = srcweapon1prop->weapon;
				cloneweapon1prop = chrGiveWeapon(clone, srcweapon1->base.obj, srcweapon1->weapon_id, 0x10000000);

				if (cloneweapon1prop) {
					cloneweapon1 = cloneweapon1prop->weapon;
				}
			}

			if (srcweapon1 && srcweapon0
					&& cloneweapon1 && cloneweapon0
					&& srcweapon0 == srcweapon1->dualweapon && srcweapon1 == srcweapon0->dualweapon) {
				propweaponSetDual(cloneweapon1, cloneweapon0);
			}

			if (chr->weapons_held[2]) {
				struct defaultobj *obj = chr->weapons_held[2]->obj;
				chrTryEquipHat(clone, obj->obj, 0);
			}

			clone->flags = chr->flags;
			clone->flags2 = chr->flags2;
			clone->padpreset1 = chr->padpreset1;

			if (g_Vars.normmplayerisrunning == false
					&& g_MissionConfig.iscoop
					&& g_Vars.numaibuddies > 0) {
				clone->flags |= CHRFLAG0_AIVSAI;
			}

			if (flags & 0x00001000) {
				clone->chrflags &= CHRCFLAG_HIDDEN;
			}

			clone->team = chr->team;
			clone->squadron = chr->squadron;
			clone->voicebox = chr->voicebox;

			rebuildTeams();
			rebuildSquadrons();

			pass = true;
		}
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[9]);
	} else {
		g_Vars.aioffset += 10;
	}

	return false;
}

/**
 * @cmd 00cb
 */
bool aiShowHudmsg(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	char *text = langGet(cmd[4] | (cmd[3] << 8));
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	u32 prevplayernum = g_Vars.currentplayernum;
	u32 playernum = g_Vars.currentplayernum;

	if (chr && chr->prop && (chr->prop->type & 0xff) == PROPTYPE_PLAYER) {
		playernum = propGetPlayerNum(chr->prop);
	}

	setCurrentPlayerNum(playernum);
	hudmsgCreateViaPreset(text, 0);
	setCurrentPlayerNum(prevplayernum);

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01a4
 */
bool aiShowHudmsgMiddle(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] == 0) {
		u32 text_id = cmd[5] | (cmd[4] << 8);
		char *text = langGet(text_id);
		hudmsgCreateViaPresetWithColour(text, 7, cmd[3]);
	} else if (cmd[2] == 1) {
		u32 text_id = cmd[5] | (cmd[4] << 8);
		char *text = langGet(text_id);
		hudmsgCreateViaPresetWithColour(text, 8, cmd[3]);
	} else {
		hudmsgRemoveAll();
	}

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00cc
 */
bool aiShowHudmsgTopMiddle(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	char *text = langGet(cmd[4] | (cmd[3] << 8));
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	u32 prevplayernum = g_Vars.currentplayernum;
	u32 playernum = g_Vars.currentplayernum;

	if (chr && chr->prop && (chr->prop->type & 0xff) == PROPTYPE_PLAYER) {
		playernum = propGetPlayerNum(chr->prop);
	}

	setCurrentPlayerNum(playernum);
	hudmsgCreateViaPresetWithColour(text, 6, cmd[5]);
	setCurrentPlayerNum(prevplayernum);

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00cd
 */
GLOBAL_ASM(
glabel aiSpeak
/*  f056040:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f056044:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f056048:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f05604c:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f056050:	8e2e0434 */ 	lw	$t6,0x434($s1)
/*  f056054:	8e2f0438 */ 	lw	$t7,0x438($s1)
/*  f056058:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f05605c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f056060:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f056064:	92050002 */ 	lbu	$a1,0x2($s0)
/*  f056068:	0fc126d1 */ 	jal	chrFindById
/*  f05606c:	8e240424 */ 	lw	$a0,0x424($s1)
/*  f056070:	92180005 */ 	lbu	$t8,0x5($s0)
/*  f056074:	92080006 */ 	lbu	$t0,0x6($s0)
/*  f056078:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f05607c:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f056080:	03284825 */ 	or	$t1,$t9,$t0
/*  f056084:	a7a9003e */ 	sh	$t1,0x3e($sp)
/*  f056088:	920a0003 */ 	lbu	$t2,0x3($s0)
/*  f05608c:	920c0004 */ 	lbu	$t4,0x4($s0)
/*  f056090:	00402825 */ 	or	$a1,$v0,$zero
/*  f056094:	000a5a00 */ 	sll	$t3,$t2,0x8
/*  f056098:	016c2025 */ 	or	$a0,$t3,$t4
/*  f05609c:	00041c00 */ 	sll	$v1,$a0,0x10
/*  f0560a0:	00036c03 */ 	sra	$t5,$v1,0x10
/*  f0560a4:	afae0038 */ 	sw	$t6,0x38($sp)
/*  f0560a8:	05a00008 */ 	bltz	$t5,.L0f0560cc
/*  f0560ac:	01c03025 */ 	or	$a2,$t6,$zero
/*  f0560b0:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0560b4:	0fc5b9f1 */ 	jal	langGet
/*  f0560b8:	afae0034 */ 	sw	$t6,0x34($sp)
/*  f0560bc:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0560c0:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0560c4:	10000002 */ 	beqz	$zero,.L0f0560d0
/*  f0560c8:	afa2002c */ 	sw	$v0,0x2c($sp)
.L0f0560cc:
/*  f0560cc:	afa0002c */ 	sw	$zero,0x2c($sp)
.L0f0560d0:
/*  f0560d0:	10a0000b */ 	beqz	$a1,.L0f056100
/*  f0560d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0560d8:	8ca4001c */ 	lw	$a0,0x1c($a1)
/*  f0560dc:	10800008 */ 	beqz	$a0,.L0f056100
/*  f0560e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0560e4:	908f0000 */ 	lbu	$t7,0x0($a0)
/*  f0560e8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0560ec:	15e10004 */ 	bne	$t7,$at,.L0f056100
/*  f0560f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0560f4:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0560f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0560fc:	00403025 */ 	or	$a2,$v0,$zero
.L0f056100:
/*  f056100:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f056104:	00c02025 */ 	or	$a0,$a2,$zero
/*  f056108:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*  f05610c:	5300000b */ 	beqzl	$t8,.L0f05613c
/*  f056110:	92090002 */ 	lbu	$t1,0x2($s0)
/*  f056114:	92190002 */ 	lbu	$t9,0x2($s0)
/*  f056118:	240100f2 */ 	addiu	$at,$zero,0xf2
/*  f05611c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f056120:	53210006 */ 	beql	$t9,$at,.L0f05613c
/*  f056124:	92090002 */ 	lbu	$t1,0x2($s0)
/*  f056128:	8e280424 */ 	lw	$t0,0x424($s1)
/*  f05612c:	3406ffff */ 	dli	$a2,0xffff
/*  f056130:	0fc249af */ 	jal	func0f0926bc
/*  f056134:	8d04001c */ 	lw	$a0,0x1c($t0)
/*  f056138:	92090002 */ 	lbu	$t1,0x2($s0)
.L0f05613c:
/*  f05613c:	240100f2 */ 	addiu	$at,$zero,0xf2
/*  f056140:	87a5003e */ 	lh	$a1,0x3e($sp)
/*  f056144:	1521000c */ 	bne	$t1,$at,.L0f056178
/*  f056148:	00003025 */ 	or	$a2,$zero,$zero
/*  f05614c:	8e2a0424 */ 	lw	$t2,0x424($s1)
/*  f056150:	82040007 */ 	lb	$a0,0x7($s0)
/*  f056154:	240b0200 */ 	addiu	$t3,$zero,0x200
/*  f056158:	8d47001c */ 	lw	$a3,0x1c($t2)
/*  f05615c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f056160:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f056164:	87a5003e */ 	lh	$a1,0x3e($sp)
/*  f056168:	0fc25010 */ 	jal	audioPlayFromProp
/*  f05616c:	00003025 */ 	or	$a2,$zero,$zero
/*  f056170:	1000000a */ 	beqz	$zero,.L0f05619c
/*  f056174:	00403825 */ 	or	$a3,$v0,$zero
.L0f056178:
/*  f056178:	8e2c0424 */ 	lw	$t4,0x424($s1)
/*  f05617c:	82040007 */ 	lb	$a0,0x7($s0)
/*  f056180:	240d0009 */ 	addiu	$t5,$zero,0x9
/*  f056184:	240e0200 */ 	addiu	$t6,$zero,0x200
/*  f056188:	8d87001c */ 	lw	$a3,0x1c($t4)
/*  f05618c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f056190:	0fc25010 */ 	jal	audioPlayFromProp
/*  f056194:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f056198:	00403825 */ 	or	$a3,$v0,$zero
.L0f05619c:
/*  f05619c:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f0561a0:	87a4003e */ 	lh	$a0,0x3e($sp)
/*  f0561a4:	11e00009 */ 	beqz	$t7,.L0f0561cc
/*  f0561a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0561ac:	0c004103 */ 	jal	audioIsFiltered
/*  f0561b0:	afa70030 */ 	sw	$a3,0x30($sp)
/*  f0561b4:	14400005 */ 	bnez	$v0,.L0f0561cc
/*  f0561b8:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f0561bc:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f0561c0:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f0561c4:	0fc37858 */ 	jal	func0f0de160
/*  f0561c8:	92060008 */ 	lbu	$a2,0x8($s0)
.L0f0561cc:
/*  f0561cc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0561d0:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0561d4:	8e380438 */ 	lw	$t8,0x438($s1)
/*  f0561d8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0561dc:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0561e0:	27190009 */ 	addiu	$t9,$t8,0x9
/*  f0561e4:	ae390438 */ 	sw	$t9,0x438($s1)
/*  f0561e8:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0561ec:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0561f0:	03e00008 */ 	jr	$ra
/*  f0561f4:	00001025 */ 	or	$v0,$zero,$zero
);

// Mismatch due to different registers
//bool aiSpeak(void)
//{
//	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
//	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
//	s16 audio_id = cmd[6] | (cmd[5] << 8);
//	s16 text_id = cmd[4] | (cmd[3] << 8);
//	s32 prevplayernum = g_Vars.currentplayernum;
//	s32 playernum = g_Vars.currentplayernum;
//	u32 audioref;
//	char *text = text_id >= 0 ? langGet(text_id) : NULL;
//
//	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
//		playernum = propGetPlayerNum(chr->prop);
//	}
//
//	setCurrentPlayerNum(playernum);
//
//	if (text && cmd[2] != CHR_P1P2) {
//		func0f0926bc(g_Vars.chrdata->prop, 9, 0xffff);
//	}
//
//	if (cmd[2] == CHR_P1P2) {
//		audioref = audioPlayFromProp(cmd[7], audio_id, 0, g_Vars.chrdata->prop, 0, 512);
//	} else {
//		audioref = audioPlayFromProp(cmd[7], audio_id, 0, g_Vars.chrdata->prop, 9, 512);
//	}
//
//	if (text && !audioIsFiltered(audio_id)) {
//		func0f0de160(text, 6, cmd[8], audioref);
//	}
//
//	setCurrentPlayerNum(prevplayernum);
//
//	g_Vars.aioffset += 9;
//
//	return false;
//}

/**
 * @cmd 00ce
 */
bool aiPlaySound(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 audio_id = cmd[3] | (cmd[2] << 8);

	audioPlayFromProp((s8)cmd[4], audio_id, 0, NULL, 0, 0);

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 017c
 */
bool aiAssignSound(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 audio_id = cmd[3] | (cmd[2] << 8);

	audioPlayFromProp((s8)cmd[4], audio_id, -1, NULL, 11, 0);

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 00d3
 */
bool aiAudioMuteChannel(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s8 channel = (s8)cmd[2];

	audioMuteChannel(channel);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0138
 */
bool aiIfChannelIdle(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s8 channel = (s8) cmd[2];

	if (audioIfChannelIdle(channel)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 00d1
 */
bool ai00d1(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 audio_id = cmd[4] | (cmd[3] << 8);
	u16 thing = cmd[6] | (cmd[5] << 8);

	audioPlayFromProp2(cmd[2], audio_id, -1, NULL, thing, 2500, 3000, 0);

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00d2
 */
bool ai00d2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 thing1 = cmd[4] | (cmd[3] << 8);
	u16 thing2 = cmd[6] | (cmd[5] << 8);
	s32 audio_id = func0f0927d4(thing1, 400, 2500, 3000, 32767);

	audioPlayFromProp2(cmd[2], audio_id, -1, NULL, thing2, 2500, 3000, 0);

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00cf
 */
bool ai00cf(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[3]);
	u16 thing = cmd[5] | (cmd[4] << 8);

	if (obj && obj->prop) {
		audioPlayFromProp2(cmd[2], -1, -1, obj->prop, thing, 2500, 3000, 0);
	}

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 016b
 */
bool ai016b(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[3]);
	u16 thing1 = cmd[5] | (cmd[4] << 8);
	u16 thing2 = cmd[7] | (cmd[6] << 8);
	u16 thing3 = cmd[9] | (cmd[8] << 8);

	if (obj && obj->prop) {
		s32 thing1again;

		if (thing1 == 0) {
			thing1again = -1;
		} else {
			thing1again = thing1;
		}

		audioPlayFromProp2(cmd[2], -1, -1, obj->prop, thing1again, thing2, thing3, 2);
	}

	g_Vars.aioffset += 10;

	return false;
}

/**
 * @cmd 0179
 */
bool ai0179(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 thing1 = cmd[5] | (cmd[4] << 8);
	u16 thing2 = cmd[7] | (cmd[6] << 8);
	u16 thing3 = cmd[9] | (cmd[8] << 8);

	if (cmd[10] == 0) {
		struct defaultobj *obj = objFindByTagId(cmd[3]);

		if (obj && obj->prop) {
			audioPlayFromProp2(cmd[2], -1, -1, obj->prop, thing1, thing2, thing3, 0);
		}
	} else {
		struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[3]);

		if (chr && chr->prop) {
			audioPlayFromProp2(cmd[2], -1, -1, chr->prop, thing1, thing2, thing3, 0);
		}
	}

	g_Vars.aioffset += 11;

	return false;
}

/**
 * @cmd 00d0
 */
bool ai00d0(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 thing1 = cmd[4] | (cmd[3] << 8);
	s16 thing2 = cmd[6] | (cmd[5] << 8);

	func0f0939f8(0, NULL, thing2, thing1, -1, 2, 0, 0, 0, -1, 0, -1, -1, -1, -1);

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00d4
 */
bool ai00d4(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 thing = cmd[4] | (cmd[3] << 8);

	if (func0f092914((s8)cmd[2]) < thing) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 00d5
 */
bool aiHovercarBeginPath(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	struct path *path = pathFindById(cmd[2]);

	if (g_Vars.truck) {
		g_Vars.truck->path = path;
		g_Vars.truck->nextstep = 0;
	}

	if (g_Vars.hovercar) {
		struct chopperobj *chopper = chopperFromHovercar(g_Vars.hovercar);
		g_Vars.hovercar->path = path;
		g_Vars.hovercar->nextstep = 0;
		g_Vars.hovercar->path->type |= PATHTYPE_4;

		if (chopper) {
			chopper->targetvisible = false;
			chopper->attackmode = 0;
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
			chopper->base.flags |= OBJFLAG_20000000;
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
bool aiSetVehicleSpeed(void)
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
bool aiSetRotarySpeed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 speedtime = cmd[5] | (cmd[4] << 8);
	f32 speedaim = (cmd[3] | (cmd[2] << 8)) * M_BADTAU / 3600;

	if (g_Vars.heli) {
		g_Vars.heli->rotaryspeedaim = speedaim;
		g_Vars.heli->rotaryspeedtime = speedtime;
	}

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 00d8
 */
bool aiNoOp00d8(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 00d9
 */
bool aiNoOp00d9(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 00da
 */
bool aiSetObjImage(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		if (obj->type == OBJTYPE_SINGLEMONITOR) {
			struct singlemonitorobj *sm = (struct singlemonitorobj *) obj;
			imageSlotSetImage(&sm->image, cmd[4], obj);
		} else if (obj->type == OBJTYPE_MULTIMONITOR) {
			u8 slot = cmd[3];
			if (slot < 4) {
				struct multimonitorobj *mm = (struct multimonitorobj *) obj;
				imageSlotSetImage(&mm->subobjs[slot].image, cmd[4], obj);
			}
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 00db
 */
bool aiNoOp00db(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 00dc
 */
bool aiEndLevel(void)
{
	if (debugAllowEndLevel()) {
		if (var800624a4) {
			func0000e95c(90);
		} else if (g_Vars.unk0004d3) {
			g_Vars.unk0004d6 = 1;
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
	func0f0b9afc();
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 00de
 */
bool aiWarpJoToPad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[3] | (cmd[2] << 8);
	warpBondToPad(pad_id);

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 010d
 */
bool aiNoOp010d(void)
{
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 0111
 */
bool aiSetCameraAnimation(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 anim_id = cmd[3] | (cmd[2] << 8);

	cameraDoAnimation(anim_id);

	if (g_Vars.currentplayer->haschrbody == false) {
		return true;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0113
 */
bool aiIfInCutscene(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.in_cutscene) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0174
 */
bool aiIfCutsceneButtonPressed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if ((g_Vars.in_cutscene && var8009de24) ||
			(g_Vars.stagenum == STAGE_CITRAINING && var80087260 > 0)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
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
	func0f0ba190(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0112
 */
bool aiObjectDoAnimation(void)
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
		fstartframe = animGetNumFrames(anim_id) - 2;

		if (fstartframe < 0) {
			fstartframe = 0;
		}
	} else {
		fstartframe = startframe;
	}

	if (cmd[4] == 255) {
		if (g_Vars.chrdata && g_Vars.chrdata->myspecial >= 0) {
			obj = objFindByTagId(g_Vars.chrdata->myspecial);
		}
	} else {
		obj = objFindByTagId(cmd[4]);
	}

	if (obj && obj->prop) {
		struct anim *anim = obj->animdata->anim;

		if (obj->animdata->anim == NULL) {
			obj->animdata->anim = func0f0b32e4();
		}

		if (obj->animdata->anim) {
			thing = 1.0f / (s32)cmd[5];

			if (g_Vars.in_cutscene && startframe != 0xfffe) {
				fstartframe += var8009de20 * thing * 0.25f;
			}

			func000230a0(obj->animdata->anim);
			func0001dccc(obj->animdata, anim_id, 0, fstartframe, thing, 0);
			func0001af64(obj->animdata, func0f15c888() * obj->animdata->unk14 * 100.0f);
		}
	}

	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 0114
 */
bool aiShowChr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->animdata) {
		func0f0604bc(chr->prop);
		propHide(chr->prop);
		func0f0220ac(chr);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0115
 */
bool aiHideChr(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->animdata) {
		func0f065c44(chr->prop);
		func0f0605c4(chr->prop);
		func0f060300(chr->prop);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0116
 */
bool aiShowObj(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->animdata) {
		func0f0604bc(obj->prop);
		propHide(obj->prop);

		if (g_Vars.currentplayer->eyespy == NULL && obj->type == OBJTYPE_WEAPON) {
			struct weaponobj *weapon = (struct weaponobj *) obj;

			if (weapon->weapon_id == WEAPON_CAMSPY) {
				currentPlayerInitEyespy();
			}
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0117
 */
bool aiHideObj(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->animdata) {
		if (obj->prop->parent) {
			func0f082f88(obj->prop);
		} else {
			func0f065c44(obj->prop);
			func0f0605c4(obj->prop);
			func0f060300(obj->prop);
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00df
 */
bool ai00df(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct tag *tag = tagFindById(cmd[2]);

	if (tag) {
		s32 a = func0f092098(tag);

		if (a >= 0) {
			u32 *ptr = setupGetPtrToCommandByIndex(tag->unk06 + a);
			func0f0b9bac(ptr, cmd[4] | (cmd[3] << 8), cmd[6] | (cmd[5] << 8));
		}
	}

	g_Vars.aioffset += 7;

	return false;
}

/**
 * @cmd 00e0
 */
bool aiRevokeControl(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);
		func0f0abc74(4, false);
		func0f0a95ec(2, false);

		if ((cmd[3] & 2) == 0) {
			currentPlayerSetFlag(PLAYERFLAG_NOCONTROL);
		}

		if ((cmd[3] & 4) == 0) {
			countdownTimerSetVisible(16, false);
		}

		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		setCurrentPlayerNum(prevplayernum);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00e1
 */
bool aiGrantControl(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		setCurrentPlayerNum(propGetPlayerNum(chr->prop));
		func0f0abc74(4, true);
		func0f0a95ec(2, true);
		currentPlayerUnsetFlag(PLAYERFLAG_NOCONTROL);
		countdownTimerSetVisible(16, true);
		g_PlayersWithControl[g_Vars.currentplayernum] = true;
		setCurrentPlayerNum(prevplayernum);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00e2
 */
bool aiChrMoveToPad(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata,cmd[2]);
	bool pass = false;
	f32 somefloat;
	struct pad pad;
	s16 rooms[2];
	struct chrdata *chr2;

	if (chr && chr->prop) {
		if (cmd[5] == 88) {
			chr2 = chrFindById(g_Vars.chrdata, cmd[4]);

			if (chr2 && chr2->prop) {
				somefloat = func0f03e45c(chr2);
				pass = chrMoveToPos(chr, &chr2->prop->pos, &chr2->prop->rooms[0], somefloat, 0);
			}
		} else {
			s32 padnum = cmd[4] | (cmd[3] << 8);
			padnum = chrResolvePadId(chr, padnum);

			if (padnum >= 0) {
				padUnpack(padnum, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_ROOM, &pad);
				somefloat = func0f096750(pad.look.x, pad.look.z);

				rooms[0] = pad.room;
				rooms[1] = -1;
				pass = chrMoveToPos(chr, &pad.pos, &rooms[0], somefloat, cmd[5]);
			}
		}
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
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
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);

		if (var8007074c != 2) {
			currentPlayerSetFadeColour(0, 0, 0, 0);
			currentPlayerSetFadeFrac(60, 1);
		}

		setCurrentPlayerNum(prevplayernum);
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
		setCurrentPlayerNum(playernum);

		if (var8007074c != 2) {
			currentPlayerSetFadeColour(0, 0, 0, 1);
			currentPlayerSetFadeFrac(60, 0);
		}
	}

	setCurrentPlayerNum(prevplayernum);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00e5
 */
bool aiIfColourFadeComplete(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bool pass = false;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 playernum = propGetPlayerNum(chr->prop);

		if (g_Vars.players[playernum]->colourfadetimemax60 < 0) {
			pass = true;
		}
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 00e8
 */
bool aiSetDoorOpen(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		struct doorobj *door = (struct doorobj *) obj;
		door->frac = door->maxfrac;
		door->fracspeed = 0;
		door->lastopen60 = g_Vars.lvframe60;
		door->mode = 0;
		func0f08c54c(door);
		doorActivatePortal(door);
		func0f0926bc(door->base.prop, 1, 0xffff);
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
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chrSetWeaponFlag4(chr, cmd[3]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00ea
 */
bool aiIfNumPlayersLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (PLAYERCOUNT3012() < (s8)cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 00eb
 */
bool aiIfChrAmmoQuantityLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	bool passes = false;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);

		if (currentPlayerGetAmmoCount((s8)cmd[3]) < (s8)cmd[4]) {
			passes = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	if (passes) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 00ec
 */
bool aiChrDrawWeapon(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);
		currentPlayerEquipWeaponWrapper(0, (s8)cmd[3]);
		currentPlayerEquipWeaponWrapper(1, 0);
		setCurrentPlayerNum(prevplayernum);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 00ed
 */
bool aiChrDrawWeaponInCutscene(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);
		currentPlayerEquipWeapon((s8)cmd[3]);
		setCurrentPlayerNum(prevplayernum);
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
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);

		g_Vars.currentplayer->bondforcespeed.x = (s8)cmd[3];
		g_Vars.currentplayer->bondforcespeed.y = 0;
		g_Vars.currentplayer->bondforcespeed.z = (s8)cmd[4];

		setCurrentPlayerNum(prevplayernum);
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 00ef
 */
bool aiIfObjInRoom(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	u16 room_id = cmd[4] | (cmd[3] << 8);
	s32 room_something = chrGetPadRoom(g_Vars.chrdata, room_id);

	if (room_something >= 0 && obj && obj->prop && room_something == obj->prop->rooms[0]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 00f2
 */
bool ai00f2(void)
{
	func0f1660a4(1);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00f3
 */
bool aiChrSetInvincible(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);
		g_PlayerInvincible = true;
		setCurrentPlayerNum(prevplayernum);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00f4
 */
bool ai00f4(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	s32 a = cmd[3] | (cmd[2] << 8);
	s16 b = cmd[5] | (cmd[4] << 8);
	s16 c = cmd[7] | (cmd[6] << 8);
	s32 d = cmd[9] | (cmd[8] << 8);
	s16 e = cmd[11] | (cmd[10] << 8);
	s32 f = cmd[13] | (cmd[12] << 8);

	func0f0b9c1c(f * M_BADTAU / 65536, c * M_BADTAU / 65536, a, b, e, d);

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
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 00f7
 */
bool aiIfAllObjectivesComplete(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (objectiveIsAllComplete()) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 3;
	}

	return false;
}

/**
 * @cmd 00f8
 */
bool aiIfPlayerIsInvincible(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bool pass = false;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);
		pass = g_PlayerInvincible;
		setCurrentPlayerNum(prevplayernum);
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 00f9
 */
bool aiAudioPlayXMusic(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset += 5;
	audioPlayXTrack((s8)cmd[2], cmd[3], cmd[4]);

	return false;
}

/**
 * @cmd 00fa
 */
bool aiAudioStopChannel(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset += 3;
	audioStopTrack((s8)cmd[2]);

	return false;
}

/**
 * @cmd 015b
 */
bool aiAudioPlayMusic(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] == MUSIC_CI_TRAINING) {
		u16 volume = optionsGetMusicVolume();
		audioPlayTrack(cmd[2]);
		optionsSetMusicVolume(volume);
	} else {
		audioPlayTrack(cmd[2]);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 015c
 */
bool aiAudioRestartMusic(void)
{
	g_Vars.aioffset += 2;
	audioRestartTrack();

	return false;
}

/**
 * @cmd 017d
 */
bool aiAudioSetMusicTrack(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	audioSetTrack(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 017e
 */
bool aiAudioRestartDefaultMusic(void)
{
	g_Vars.aioffset += 2;
	audioRestartDefaultTrack();

	return false;
}

/**
 * @cmd 017f
 */
bool aiAudioSetSfxTrack(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	audioSetAuxTrack(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0180
 */
bool aiAudioRestartSfx(void)
{
	g_Vars.aioffset += 2;
	audioRestartAuxTrack();

	return false;
}

/**
 * @cmd 00fb
 */
bool aiChrExplosions(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);
		currentPlayerSurroundWithExplosions(0);
		setCurrentPlayerNum(prevplayernum);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 00fc
 */
bool aiIfKillCountGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.killcount > cmd[2]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 01ab
 */
bool aiIfNumKnockedOutChrs(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] < getKnockoutCount() && cmd[3] == 0) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else if (getKnockoutCount() < cmd[2] && cmd[3] == 1) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
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
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_00200000)) {
		chr->chrflags &= ~CHRCFLAG_00200000;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 00fe
 */
bool aiKillBond(void)
{
	g_Vars.bond->isdead = true;
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 00ff
 */
bool aiBeSurprisedSurrender(void)
{
	chrTrySurprisedSurrender(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0100
 */
bool aiNoOp0100(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 0101
 */
bool aiNoOp0101(void)
{
	g_Vars.aioffset += 3;
	return false;
}

/**
 * @cmd 0102
 */
bool aiSetLights(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 room_id = cmd[3] | (cmd[2] << 8);
	s32 thing = chrGetPadRoom(g_Vars.chrdata, room_id);

	if (thing >= 0) {
		switch (cmd[4]) {
		case 7:
			func0f002b58(thing, false);
			break;
		case 6:
			func0f002b58(thing, true);
			break;
		default:
			func0f002c28(thing, cmd[4], cmd[5], cmd[6], cmd[7]);
		}
	}

	g_Vars.aioffset += 11;

	return false;
}

/**
 * @cmd 0103
 */
bool ai0103(void)
{
	if (func0f04b658(g_Vars.chrdata)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0104
 */
GLOBAL_ASM(
glabel aiRemoveObjectAtPropPreset
/*  f058b08:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f058b0c:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f058b10:	8ca30424 */ 	lw	$v1,0x424($a1)
/*  f058b14:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f058b18:	8462012c */ 	lh	$v0,0x12c($v1)
/*  f058b1c:	0440000c */ 	bltz	$v0,.L0f058b50
/*  f058b20:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f058b24:	8caf0338 */ 	lw	$t7,0x338($a1)
/*  f058b28:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f058b2c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f058b30:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f058b34:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f058b38:	3c01ffdf */ 	lui	$at,0xffdf
/*  f058b3c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f058b40:	8c990040 */ 	lw	$t9,0x40($a0)
/*  f058b44:	03214024 */ 	and	$t0,$t9,$at
/*  f058b48:	ac880040 */ 	sw	$t0,0x40($a0)
/*  f058b4c:	8ca30424 */ 	lw	$v1,0x424($a1)
.L0f058b50:
/*  f058b50:	a469012c */ 	sh	$t1,0x12c($v1)
/*  f058b54:	8caa0438 */ 	lw	$t2,0x438($a1)
/*  f058b58:	00001025 */ 	or	$v0,$zero,$zero
/*  f058b5c:	254b0002 */ 	addiu	$t3,$t2,0x2
/*  f058b60:	03e00008 */ 	jr	$ra
/*  f058b64:	acab0438 */ 	sw	$t3,0x438($a1)
);

// Mismatch due to temporary registers
//bool aiRemoveObjectAtPropPreset(void)
//{
//	if (g_Vars.chrdata->proppreset1 >= 0) {
//		struct defaultobj *obj = g_Vars.props[g_Vars.chrdata->proppreset1].obj;
//		obj->hidden &= ~OBJHFLAG_00200000;
//	}
//
//	g_Vars.chrdata->proppreset1 = -1;
//	g_Vars.aioffset += 2;
//
//	return false;
//}

/**
 * @cmd 0105
 */
bool aiIfPropPresetHeightLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct prop *prop = &g_Vars.props[g_Vars.chrdata->proppreset1];
	f32 value = cmd[3] | (cmd[2] << 8);
	f32 ymax;
	f32 ymin;
	f32 width;
	propGetBbox(prop, &width, &ymax, &ymin);

	if (ymax - ymin < value) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0106
 */
bool aiSetTarget(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata) {
		s16 prop_id;

		if (!cmd[3] && !cmd[4]) {
			prop_id = propGetIndexByChrId(g_Vars.chrdata, cmd[2]);
		} else if (!cmd[4]) {
			struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
			prop_id = chr->target;
		}

		if (prop_id != g_Vars.chrdata->target) {
			g_Vars.chrdata->lastvisibletarget60 = 0;
			g_Vars.chrdata->lastseetarget60 = 0;
			g_Vars.chrdata->lastheartarget60 = 0;
			g_Vars.chrdata->hidden &= ~CHRHFLAG_00000002;
			g_Vars.chrdata->chrflags &= ~CHRCFLAG_NEAR_MISS;
			g_Vars.chrdata->target = prop_id;
		}
	} else if (g_Vars.hovercar) {
		chopperSetTarget(g_Vars.hovercar, cmd[2]);
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 0107
 */
bool aiIfPresetsTargetIsNotMyTarget(void)
{
	s32 mypresetchrstarget;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->chrpreset1 != -1) {
		mypresetchrstarget = propGetIndexByChrId(g_Vars.chrdata, g_Vars.chrdata->chrpreset1);
	}

	if (g_Vars.chrdata->target != -1 && mypresetchrstarget != g_Vars.chrdata->target) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0108
 */
bool aiIfChrTarget(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	bool pass = false;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		// empty
	} else if (cmd[2] != CHR_BOND) {
		if (cmd[4] == 0) {
			struct chrdata *chr2 = chrFindById(g_Vars.chrdata, cmd[3]);

			if (chr2 && chr2->prop && chrGetTargetProp(chr) == chr2->prop) {
				pass = true;
			}
		} else {
			if (chr->target != -1 && chr && chr->prop) {
				pass = true;
			}
		}
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 0109
 */
bool ai0109(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[4] | (cmd[3] << 8)) * 10.0f;

	if (func0f04a79c(cmd[2], g_Vars.chrdata, distance)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 010a
 */
bool ai010a(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[4] | (cmd[3] << 8)) * 10.0f;
	u16 thing = cmd[6] | (cmd[5] << 8);

	if (func0f04a7dc(cmd[2], g_Vars.chrdata, distance, thing)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 010b
 */
bool aiChrSetTeam(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->team = cmd[3];
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 010c
 */
bool aiIfCompareChrPresetsTeam(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, CHR_PRESET);

	if (!chr || (!chr->animdata && chr->prop->type != PROPTYPE_PLAYER)) {
		chrSetChrPreset(g_Vars.chrdata, CHR_BOND);
		chr = chrFindById(g_Vars.chrdata, CHR_PRESET);
	}

	if (chrCompareTeams(chr, g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 011e
 */
bool aiIfHuman(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && CHRRACE(chr) == RACE_HUMAN) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 011f
 */
bool aiIfSkedar(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && CHRRACE(chr) == RACE_SKEDAR) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0120
 */
GLOBAL_ASM(
glabel ai0120
.late_rodata
glabel var7f1a9ce4
.word ai0120+0xb8 # f0593bc
glabel var7f1a9ce8
.word ai0120+0xb8 # f0593bc
glabel var7f1a9cec
.word ai0120+0xb8 # f0593bc
glabel var7f1a9cf0
.word ai0120+0xb8 # f0593bc
glabel var7f1a9cf4
.word ai0120+0xb8 # f0593bc
glabel var7f1a9cf8
.word ai0120+0xb8 # f0593bc
glabel var7f1a9cfc
.word ai0120+0xb8 # f0593bc
glabel var7f1a9d00
.word ai0120+0xb8 # f0593bc
glabel var7f1a9d04
.word ai0120+0x8c # f059390
glabel var7f1a9d08
.word ai0120+0x8c # f059390
glabel var7f1a9d0c
.word ai0120+0x8c # f059390
glabel var7f1a9d10
.word ai0120+0x8c # f059390
glabel var7f1a9d14
.word ai0120+0x8c # f059390
glabel var7f1a9d18
.word ai0120+0x8c # f059390
glabel var7f1a9d1c
.word ai0120+0x8c # f059390
glabel var7f1a9d20
.word ai0120+0x8c # f059390
glabel var7f1a9d24
.word ai0120+0x8c # f059390
glabel var7f1a9d28
.word ai0120+0x8c # f059390
glabel var7f1a9d2c
.word ai0120+0x9c # f0593a0
glabel var7f1a9d30
.word ai0120+0x8c # f059390
glabel var7f1a9d34
.word ai0120+0x9c # f0593a0
glabel var7f1a9d38
.word ai0120+0x9c # f0593a0
glabel var7f1a9d3c
.word ai0120+0x9c # f0593a0
glabel var7f1a9d40
.word ai0120+0x9c # f0593a0
glabel var7f1a9d44
.word ai0120+0xac # f0593b0
glabel var7f1a9d48
.word ai0120+0xb8 # f0593bc
glabel var7f1a9d4c
.word 0x455ac000
.text
/*  f059304:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f059308:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f05930c:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f059310:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f059314:	8e6e0434 */ 	lw	$t6,0x434($s3)
/*  f059318:	8e6f0438 */ 	lw	$t7,0x438($s3)
/*  f05931c:	8e790424 */ 	lw	$t9,0x424($s3)
/*  f059320:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f059324:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f059328:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f05932c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f059330:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f059334:	afb8002c */ 	sw	$t8,0x2c($sp)
/*  f059338:	0fc13380 */ 	jal	teamGetChrIds
/*  f05933c:	93240125 */ 	lbu	$a0,0x125($t9)
/*  f059340:	24080006 */ 	addiu	$t0,$zero,0x6
/*  f059344:	00408825 */ 	or	$s1,$v0,$zero
/*  f059348:	a3a8002b */ 	sb	$t0,0x2b($sp)
/*  f05934c:	00009025 */ 	or	$s2,$zero,$zero
/*  f059350:	0fc12840 */ 	jal	chrGetNumArghs
/*  f059354:	8e640424 */ 	lw	$a0,0x424($s3)
/*  f059358:	18400002 */ 	blez	$v0,.L0f059364
/*  f05935c:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f059360:	a3a9002b */ 	sb	$t1,0x2b($sp)
.L0f059364:
/*  f059364:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f059368:	00002025 */ 	or	$a0,$zero,$zero
/*  f05936c:	244afffe */ 	addiu	$t2,$v0,-2
/*  f059370:	2d41001a */ 	sltiu	$at,$t2,0x1a
/*  f059374:	1020000e */ 	beqz	$at,.L0f0593b0
/*  f059378:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f05937c:	3c017f1b */ 	lui	$at,%hi(var7f1a9ce4)
/*  f059380:	002a0821 */ 	addu	$at,$at,$t2
/*  f059384:	8c2a9ce4 */ 	lw	$t2,%lo(var7f1a9ce4)($at)
/*  f059388:	01400008 */ 	jr	$t2
/*  f05938c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059390:	93ab002b */ 	lbu	$t3,0x2b($sp)
/*  f059394:	256cffff */ 	addiu	$t4,$t3,-1
/*  f059398:	10000008 */ 	beqz	$zero,.L0f0593bc
/*  f05939c:	a3ac002b */ 	sb	$t4,0x2b($sp)
/*  f0593a0:	93ad002b */ 	lbu	$t5,0x2b($sp)
/*  f0593a4:	25aefffe */ 	addiu	$t6,$t5,-2
/*  f0593a8:	10000004 */ 	beqz	$zero,.L0f0593bc
/*  f0593ac:	a3ae002b */ 	sb	$t6,0x2b($sp)
.L0f0593b0:
/*  f0593b0:	93af002b */ 	lbu	$t7,0x2b($sp)
/*  f0593b4:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0593b8:	a3b8002b */ 	sb	$t8,0x2b($sp)
.L0f0593bc:
/*  f0593bc:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0593c0:	2401fffe */ 	addiu	$at,$zero,-2
/*  f0593c4:	1081002d */ 	beq	$a0,$at,.L0f05947c
/*  f0593c8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0593cc:
/*  f0593cc:	0fc0a1dd */ 	jal	chrFindByLiteralId
/*  f0593d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0593d4:	10400024 */ 	beqz	$v0,.L0f059468
/*  f0593d8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0593dc:	8c590020 */ 	lw	$t9,0x20($v0)
/*  f0593e0:	53200022 */ 	beqzl	$t9,.L0f05946c
/*  f0593e4:	86240002 */ 	lh	$a0,0x2($s1)
/*  f0593e8:	0fc0e6a5 */ 	jal	chrIsDead
/*  f0593ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0593f0:	5440001e */ 	bnezl	$v0,.L0f05946c
/*  f0593f4:	86240002 */ 	lh	$a0,0x2($s1)
/*  f0593f8:	82080007 */ 	lb	$t0,0x7($s0)
/*  f0593fc:	24010005 */ 	addiu	$at,$zero,0x5
/*  f059400:	5101001a */ 	beql	$t0,$at,.L0f05946c
/*  f059404:	86240002 */ 	lh	$a0,0x2($s1)
/*  f059408:	92090113 */ 	lbu	$t1,0x113($s0)
/*  f05940c:	29210065 */ 	slti	$at,$t1,0x65
/*  f059410:	54200016 */ 	bnezl	$at,.L0f05946c
/*  f059414:	86240002 */ 	lh	$a0,0x2($s1)
/*  f059418:	8e640424 */ 	lw	$a0,0x424($s3)
/*  f05941c:	920a02a2 */ 	lbu	$t2,0x2a2($s0)
/*  f059420:	908b02a2 */ 	lbu	$t3,0x2a2($a0)
/*  f059424:	554b0011 */ 	bnel	$t2,$t3,.L0f05946c
/*  f059428:	86240002 */ 	lh	$a0,0x2($s1)
/*  f05942c:	86050000 */ 	lh	$a1,0x0($s0)
/*  f059430:	848c0000 */ 	lh	$t4,0x0($a0)
/*  f059434:	50ac000d */ 	beql	$a1,$t4,.L0f05946c
/*  f059438:	86240002 */ 	lh	$a0,0x2($s1)
/*  f05943c:	0fc1272c */ 	jal	chrGetDistanceToChr
/*  f059440:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059444:	3c017f1b */ 	lui	$at,%hi(var7f1a9d4c)
/*  f059448:	c4249d4c */ 	lwc1	$f4,%lo(var7f1a9d4c)($at)
/*  f05944c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f059450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059454:	45020005 */ 	bc1fl	.L0f05946c
/*  f059458:	86240002 */ 	lh	$a0,0x2($s1)
/*  f05945c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f059460:	324d00ff */ 	andi	$t5,$s2,0xff
/*  f059464:	01a09025 */ 	or	$s2,$t5,$zero
.L0f059468:
/*  f059468:	86240002 */ 	lh	$a0,0x2($s1)
.L0f05946c:
/*  f05946c:	2401fffe */ 	addiu	$at,$zero,-2
/*  f059470:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f059474:	1481ffd5 */ 	bne	$a0,$at,.L0f0593cc
/*  f059478:	00000000 */ 	sll	$zero,$zero,0x0
.L0f05947c:
/*  f05947c:	16400005 */ 	bnez	$s2,.L0f059494
/*  f059480:	02401825 */ 	or	$v1,$s2,$zero
/*  f059484:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*  f059488:	25cffffe */ 	addiu	$t7,$t6,-2
/*  f05948c:	10000006 */ 	beqz	$zero,.L0f0594a8
/*  f059490:	a3af002b */ 	sb	$t7,0x2b($sp)
.L0f059494:
/*  f059494:	24010001 */ 	addiu	$at,$zero,0x1
/*  f059498:	14610003 */ 	bne	$v1,$at,.L0f0594a8
/*  f05949c:	93b8002b */ 	lbu	$t8,0x2b($sp)
/*  f0594a0:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f0594a4:	a3b9002b */ 	sb	$t9,0x2b($sp)
.L0f0594a8:
/*  f0594a8:	93a2002b */ 	lbu	$v0,0x2b($sp)
/*  f0594ac:	28410003 */ 	slti	$at,$v0,0x3
/*  f0594b0:	50200005 */ 	beqzl	$at,.L0f0594c8
/*  f0594b4:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f0594b8:	50600003 */ 	beqzl	$v1,.L0f0594c8
/*  f0594bc:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f0594c0:	24020003 */ 	addiu	$v0,$zero,0x3
/*  f0594c4:	8fa3002c */ 	lw	$v1,0x2c($sp)
.L0f0594c8:
/*  f0594c8:	90680002 */ 	lbu	$t0,0x2($v1)
/*  f0594cc:	0048082a */ 	slt	$at,$v0,$t0
/*  f0594d0:	50200008 */ 	beqzl	$at,.L0f0594f4
/*  f0594d4:	8e690438 */ 	lw	$t1,0x438($s3)
/*  f0594d8:	8e640434 */ 	lw	$a0,0x434($s3)
/*  f0594dc:	8e650438 */ 	lw	$a1,0x438($s3)
/*  f0594e0:	0fc13583 */ 	jal	chraiGoToLabel
/*  f0594e4:	90660003 */ 	lbu	$a2,0x3($v1)
/*  f0594e8:	10000004 */ 	beqz	$zero,.L0f0594fc
/*  f0594ec:	ae620438 */ 	sw	$v0,0x438($s3)
/*  f0594f0:	8e690438 */ 	lw	$t1,0x438($s3)
.L0f0594f4:
/*  f0594f4:	252a0004 */ 	addiu	$t2,$t1,0x4
/*  f0594f8:	ae6a0438 */ 	sw	$t2,0x438($s3)
.L0f0594fc:
/*  f0594fc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f059500:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f059504:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f059508:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f05950c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f059510:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f059514:	03e00008 */ 	jr	$ra
/*  f059518:	00001025 */ 	or	$v0,$zero,$zero
);

// Mismatch because score is masked with 0xff near 47c. Seems like it needs to
// use use int promotion but I haven't found a way to trigger it.
//bool ai0120(void)
//{
//	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
//	u8 score = 6;
//	u8 numnearby = 0;
//	s16 *chrnums = teamGetChrIds(g_Vars.chrdata->team);
//
//	// 350
//	if (chrGetNumArghs(g_Vars.chrdata) > 0) {
//		score -= 2;
//	}
//
//	switch (getCurrentPlayerWeaponId(0)) {
//	case WEAPON_CMP150:
//	case WEAPON_CYCLONE:
//	case WEAPON_CALLISTONTG:
//	case WEAPON_RCP120:
//	case WEAPON_LAPTOPGUN:
//	case WEAPON_DRAGON:
//	case WEAPON_K7AVENGER:
//	case WEAPON_AR34:
//	case WEAPON_SUPERDRAGON:
//	case WEAPON_SHOTGUN:
//	case WEAPON_SNIPERRIFLE:
//		score--;
//		break;
//	case WEAPON_REAPER:
//	case WEAPON_FARSIGHTXR20:
//	case WEAPON_DEVASTATOR:
//	case WEAPON_ROCKETLAUNCHER:
//	case WEAPON_SLAYER:
//		score -= 2;
//		break;
//	default:
//		score++;
//		break;
//	case WEAPON_FALCON2:
//	case WEAPON_FALCON2_SILENCER:
//	case WEAPON_FALCON2_SCOPE:
//	case WEAPON_MAGSEC4:
//	case WEAPON_MAULER:
//	case WEAPON_PHOENIX:
//	case WEAPON_DY357MAGNUM:
//	case WEAPON_DY357LX:
//	case WEAPON_CROSSBOW:
//		break;
//	}
//
//	// 3bc
//	while (*chrnums != -2) {
//		struct chrdata *chr = chrFindByLiteralId(*chrnums);
//
//		if (chr && chr->animdata
//				&& !chrIsDead(chr)
//				&& chr->actiontype != ACT_DEAD
//				&& chr->alertness > 100 // @bug? I don't think this goes higher than 100
//				&& g_Vars.chrdata->squadron == chr->squadron
//				&& g_Vars.chrdata->chrnum != chr->chrnum
//				&& chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum) < 3500) {
//			numnearby++;
//		}
//
//		chrnums++;
//	}
//
//	// 47c
//	if (numnearby == 0) {
//		score -= 2;
//	} else if (numnearby == 1) {
//		score--;
//	}
//
//	if (score < 3 && numnearby != 0) {
//		score = 3;
//	}
//
//	if (score < cmd[2]) {
//		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
//	} else {
//		g_Vars.aioffset += 4;
//	}
//
//	return false;
//}

/**
 * @cmd 0121
 */
bool ai0121(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 someshort = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata && g_Vars.chrdata->prop && func0f04ba34(g_Vars.chrdata, someshort, 0) != -1) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0122
 */
bool ai0122(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 thing = cmd[3] | (cmd[2] << 8);
	u32 flags = (cmd[5] << 16) | (cmd[6] << 8) | cmd[7] | (cmd[4] << 24);

	if (g_Vars.chrdata && g_Vars.chrdata->prop && func0f04ba34(g_Vars.chrdata, thing, flags) != -1) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[8]);
	} else {
		g_Vars.aioffset += 9;
	}

	return false;
}

/**
 * @cmd 0123
 */
bool ai0123(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 thing = cmd[3] | (cmd[2] << 8);
	u32 flags = (cmd[5] << 16) | (cmd[6] << 8) | cmd[7] | (cmd[4] << 24);

	if (g_Vars.chrdata && g_Vars.chrdata->prop && func0f04ba34(g_Vars.chrdata, thing, -flags) != -1) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[8]);
	} else {
		g_Vars.aioffset += 9;
	}

	return false;
}

/**
 * @cmd 0124
 */
bool aiGoToCover(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	chrGoToCover(g_Vars.chrdata, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0125
 */
bool ai0125(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (func0f04b950(g_Vars.chrdata, g_Vars.chrdata->cover, 0)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0126
 */
bool aiIfPlayerUsingCmpOrAr34(void)
{
	u32 arg = 0;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	switch (getCurrentPlayerWeaponId(arg)) {
		case WEAPON_CMP150:
		case WEAPON_AR34:
			g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
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
GLOBAL_ASM(
.late_rodata
glabel var7f1a9d50
.word 0x461c3f9a
glabel var7f1a9d54
.word 0x44bb8000
glabel var7f1a9d58
.word 0x461c3c00
.text
glabel aiDetectEnemyOnSameFloor
/*  f0598b4:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0598b8:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0598bc:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0598c0:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0598c4:	8e4e0434 */ 	lw	$t6,0x434($s2)
/*  f0598c8:	8e4f0438 */ 	lw	$t7,0x438($s2)
/*  f0598cc:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0598d0:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0598d4:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0598d8:	3c017f1b */ 	lui	$at,%hi(var7f1a9d50)
/*  f0598dc:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0598e0:	00009825 */ 	or	$s3,$zero,$zero
/*  f0598e4:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0598e8:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0598ec:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0598f0:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f0598f4:	c4349d50 */ 	lwc1	$f20,%lo(var7f1a9d50)($at)
/*  f0598f8:	afb80044 */ 	sw	$t8,0x44($sp)
/*  f0598fc:	0fc13380 */ 	jal	teamGetChrIds
/*  f059900:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f059904:	8e440424 */ 	lw	$a0,0x424($s2)
/*  f059908:	00408825 */ 	or	$s1,$v0,$zero
/*  f05990c:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f059910:	908302e2 */ 	lbu	$v1,0x2e2($a0)
/*  f059914:	240100ff */ 	addiu	$at,$zero,0xff
/*  f059918:	14600004 */ 	bnez	$v1,.L0f05992c
/*  f05991c:	00602825 */ 	or	$a1,$v1,$zero
/*  f059920:	3c017f1b */ 	lui	$at,%hi(var7f1a9d54)
/*  f059924:	10000011 */ 	beqz	$zero,.L0f05996c
/*  f059928:	c4369d54 */ 	lwc1	$f22,%lo(var7f1a9d54)($at)
.L0f05992c:
/*  f05992c:	14a10003 */ 	bne	$a1,$at,.L0f05993c
/*  f059930:	3c017f1b */ 	lui	$at,%hi(var7f1a9d58)
/*  f059934:	1000000d */ 	beqz	$zero,.L0f05996c
/*  f059938:	c4369d58 */ 	lwc1	$f22,%lo(var7f1a9d58)($at)
.L0f05993c:
/*  f05993c:	44832000 */ 	mtc1	$v1,$f4
/*  f059940:	3c014f80 */ 	lui	$at,0x4f80
/*  f059944:	04610004 */ 	bgez	$v1,.L0f059958
/*  f059948:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f05994c:	44814000 */ 	mtc1	$at,$f8
/*  f059950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059954:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f059958:
/*  f059958:	3c014220 */ 	lui	$at,0x4220
/*  f05995c:	44815000 */ 	mtc1	$at,$f10
/*  f059960:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059964:	460a3582 */ 	mul.s	$f22,$f6,$f10
/*  f059968:	00000000 */ 	sll	$zero,$zero,0x0
.L0f05996c:
/*  f05996c:	8c99001c */ 	lw	$t9,0x1c($a0)
/*  f059970:	c730000c */ 	lwc1	$f16,0xc($t9)
/*  f059974:	e7b00048 */ 	swc1	$f16,0x48($sp)
.L0f059978:
/*  f059978:	0fc0a1dd */ 	jal	chrFindByLiteralId
/*  f05997c:	86240000 */ 	lh	$a0,0x0($s1)
/*  f059980:	86280000 */ 	lh	$t0,0x0($s1)
/*  f059984:	2401fffe */ 	addiu	$at,$zero,-2
/*  f059988:	00408025 */ 	or	$s0,$v0,$zero
/*  f05998c:	5101005f */ 	beql	$t0,$at,.L0f059b0c
/*  f059990:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f059994:	1040005a */ 	beqz	$v0,.L0f059b00
/*  f059998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05999c:	8c49001c */ 	lw	$t1,0x1c($v0)
/*  f0599a0:	11200057 */ 	beqz	$t1,.L0f059b00
/*  f0599a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0599a8:	904a0125 */ 	lbu	$t2,0x125($v0)
/*  f0599ac:	24010080 */ 	addiu	$at,$zero,0x80
/*  f0599b0:	11410053 */ 	beq	$t2,$at,.L0f059b00
/*  f0599b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0599b8:	0fc0e6a5 */ 	jal	chrIsDead
/*  f0599bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0599c0:	1440004f */ 	bnez	$v0,.L0f059b00
/*  f0599c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0599c8:	82020007 */ 	lb	$v0,0x7($s0)
/*  f0599cc:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0599d0:	1041004b */ 	beq	$v0,$at,.L0f059b00
/*  f0599d4:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f0599d8:	10410049 */ 	beq	$v0,$at,.L0f059b00
/*  f0599dc:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f0599e0:	10410047 */ 	beq	$v0,$at,.L0f059b00
/*  f0599e4:	24010020 */ 	addiu	$at,$zero,0x20
/*  f0599e8:	10410045 */ 	beq	$v0,$at,.L0f059b00
/*  f0599ec:	02002825 */ 	or	$a1,$s0,$zero
/*  f0599f0:	8e440424 */ 	lw	$a0,0x424($s2)
/*  f0599f4:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f0599f8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0599fc:	10400040 */ 	beqz	$v0,.L0f059b00
/*  f059a00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059a04:	8e030014 */ 	lw	$v1,0x14($s0)
/*  f059a08:	00035880 */ 	sll	$t3,$v1,0x2
/*  f059a0c:	0560003c */ 	bltz	$t3,.L0f059b00
/*  f059a10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059a14:	8e0c0018 */ 	lw	$t4,0x18($s0)
/*  f059a18:	3c014000 */ 	lui	$at,0x4000
/*  f059a1c:	00611024 */ 	and	$v0,$v1,$at
/*  f059a20:	318d0400 */ 	andi	$t5,$t4,0x400
/*  f059a24:	15a00036 */ 	bnez	$t5,.L0f059b00
/*  f059a28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059a2c:	14400034 */ 	bnez	$v0,.L0f059b00
/*  f059a30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059a34:	8e0e001c */ 	lw	$t6,0x1c($s0)
/*  f059a38:	c7b20048 */ 	lwc1	$f18,0x48($sp)
/*  f059a3c:	3c01c348 */ 	lui	$at,0xc348
/*  f059a40:	c5c4000c */ 	lwc1	$f4,0xc($t6)
/*  f059a44:	44814000 */ 	mtc1	$at,$f8
/*  f059a48:	3c014348 */ 	lui	$at,0x4348
/*  f059a4c:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f059a50:	4600403c */ 	c.lt.s	$f8,$f0
/*  f059a54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059a58:	45000029 */ 	bc1f	.L0f059b00
/*  f059a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059a60:	44813000 */ 	mtc1	$at,$f6
/*  f059a64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059a68:	4606003c */ 	c.lt.s	$f0,$f6
/*  f059a6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059a70:	45000023 */ 	bc1f	.L0f059b00
/*  f059a74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059a78:	8e440424 */ 	lw	$a0,0x424($s2)
/*  f059a7c:	8c8f0014 */ 	lw	$t7,0x14($a0)
/*  f059a80:	000fc000 */ 	sll	$t8,$t7,0x0
/*  f059a84:	07030006 */ 	bgezl	$t8,.L0f059aa0
/*  f059a88:	86050000 */ 	lh	$a1,0x0($s0)
/*  f059a8c:	10400003 */ 	beqz	$v0,.L0f059a9c
/*  f059a90:	0003c900 */ 	sll	$t9,$v1,0x4
/*  f059a94:	0721001a */ 	bgez	$t9,.L0f059b00
/*  f059a98:	00000000 */ 	sll	$zero,$zero,0x0
.L0f059a9c:
/*  f059a9c:	86050000 */ 	lh	$a1,0x0($s0)
.L0f059aa0:
/*  f059aa0:	84880000 */ 	lh	$t0,0x0($a0)
/*  f059aa4:	10a80016 */ 	beq	$a1,$t0,.L0f059b00
/*  f059aa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059aac:	0fc1272c */ 	jal	chrGetDistanceToChr
/*  f059ab0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059ab4:	4614003c */ 	c.lt.s	$f0,$f20
/*  f059ab8:	46000086 */ 	mov.s	$f2,$f0
/*  f059abc:	45000010 */ 	bc1f	.L0f059b00
/*  f059ac0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059ac4:	4616003c */ 	c.lt.s	$f0,$f22
/*  f059ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059acc:	45030007 */ 	bc1tl	.L0f059aec
/*  f059ad0:	4614103c */ 	c.lt.s	$f2,$f20
/*  f059ad4:	8e4404b4 */ 	lw	$a0,0x4b4($s2)
/*  f059ad8:	0fc59585 */ 	jal	stageGetIndex
/*  f059adc:	e7a20054 */ 	swc1	$f2,0x54($sp)
/*  f059ae0:	14400007 */ 	bnez	$v0,.L0f059b00
/*  f059ae4:	c7a20054 */ 	lwc1	$f2,0x54($sp)
/*  f059ae8:	4614103c */ 	c.lt.s	$f2,$f20
.L0f059aec:
/*  f059aec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059af0:	45000003 */ 	bc1f	.L0f059b00
/*  f059af4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059af8:	46001506 */ 	mov.s	$f20,$f2
/*  f059afc:	86140000 */ 	lh	$s4,0x0($s0)
.L0f059b00:
/*  f059b00:	10000003 */ 	beqz	$zero,.L0f059b10
/*  f059b04:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f059b08:	26310002 */ 	addiu	$s1,$s1,0x2
.L0f059b0c:
/*  f059b0c:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f059b10:
/*  f059b10:	2a610008 */ 	slti	$at,$s3,0x8
/*  f059b14:	1420ff98 */ 	bnez	$at,.L0f059978
/*  f059b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f059b1c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f059b20:	1281000c */ 	beq	$s4,$at,.L0f059b54
/*  f059b24:	02802825 */ 	or	$a1,$s4,$zero
/*  f059b28:	0fc12705 */ 	jal	propGetIndexByChrId
/*  f059b2c:	8e440424 */ 	lw	$a0,0x424($s2)
/*  f059b30:	8e490424 */ 	lw	$t1,0x424($s2)
/*  f059b34:	a522017e */ 	sh	$v0,0x17e($t1)
/*  f059b38:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f059b3c:	8e450438 */ 	lw	$a1,0x438($s2)
/*  f059b40:	8e440434 */ 	lw	$a0,0x434($s2)
/*  f059b44:	0fc13583 */ 	jal	chraiGoToLabel
/*  f059b48:	91460002 */ 	lbu	$a2,0x2($t2)
/*  f059b4c:	10000004 */ 	beqz	$zero,.L0f059b60
/*  f059b50:	ae420438 */ 	sw	$v0,0x438($s2)
.L0f059b54:
/*  f059b54:	8e4b0438 */ 	lw	$t3,0x438($s2)
/*  f059b58:	256c0003 */ 	addiu	$t4,$t3,0x3
/*  f059b5c:	ae4c0438 */ 	sw	$t4,0x438($s2)
.L0f059b60:
/*  f059b60:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f059b64:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f059b68:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f059b6c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f059b70:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f059b74:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f059b78:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f059b7c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f059b80:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f059b84:	03e00008 */ 	jr	$ra
/*  f059b88:	00001025 */ 	or	$v0,$zero,$zero
);

// Mismatch due to the order of variable initialisation.
// The game initialises team = 0 first then saves the callee-save registers,
// while the code below causes it to save the callee-registers first.
//bool aiDetectEnemyOnSameFloor(void)
//{
//	// Note: Must be distance, then any two words, then y then cmd.
//	// Everything else is flexible.
//	s32 team = 0;
//	f32 closestdist = 10000;
//	f32 distance;
//	u32 stack[2];
//	f32 y;
//	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
//	f32 scandist;
//	s16 *chrnums = teamGetChrIds(1);
//	struct chrdata *chr;
//	s16 newtarget = -1;
//
//	if (g_Vars.chrdata->teamscandist == 0) {
//		scandist = 1500;
//	} else if (g_Vars.chrdata->teamscandist == 255) {
//		scandist = 9999;
//	} else {
//		scandist = g_Vars.chrdata->teamscandist * 40.0f;
//	}
//
//	y = g_Vars.chrdata->prop->pos.y;
//
//	while (team < 8) {
//		chr = chrFindByLiteralId(*chrnums);
//
//		if (*chrnums != -2) {
//			if (chr && chr->prop
//					&& chr->team != TEAM_NONCOMBAT
//					&& !chrIsDead(chr)
//					&& chr->actiontype != ACT_DEAD
//					&& chr->actiontype != ACT_DRUGGEDKO
//					&& chr->actiontype != ACT_DRUGGEDDROP
//					&& chr->actiontype != ACT_DRUGGEDCOMINGUP
//					&& chrCompareTeams(g_Vars.chrdata, chr, 2)
//					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
//					&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0
//					&& (chr->hidden & CHRHFLAG_40000000) == 0
//					&& y - chr->prop->pos.y > -200
//					&& y - chr->prop->pos.y < 200
//					&& ((g_Vars.chrdata->hidden & CHRHFLAG_PSYCHOSISED) == 0
//						|| (chr->hidden & CHRHFLAG_40000000) == 0
//						|| chr->hidden & CHRHFLAG_08000000)
//					&& g_Vars.chrdata->chrnum != chr->chrnum) {
//				distance = chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum);
//
//				if (distance < closestdist) {
//					if (distance < scandist || stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MAIANSOS) {
//						if (distance < closestdist) {
//							closestdist = distance;
//							newtarget = chr->chrnum;
//						}
//					}
//				}
//			}
//
//			chrnums++;
//		} else {
//			chrnums++;
//			team++;
//		}
//	}
//
//	if (newtarget != -1) {
//		g_Vars.chrdata->target = propGetIndexByChrId(g_Vars.chrdata, newtarget);
//		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
//	} else {
//		g_Vars.aioffset = g_Vars.aioffset + 3;
//	}
//
//	return false;
//}

/**
 * @cmd 0128
 */
bool aiDetectEnemy(void)
{
	s16 *chrnums;
	s32 team = 0;
	u32 stack[4];
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 closestdist = 10000000;
	f32 maxdist = (s32)cmd[2] * 10.0f;
	s16 closesttarg = -1;

	chrnums = teamGetChrIds(1);

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
	 * The chrnums list returned by teamGetChrIds is an array of chrnums in
	 * team 1 terminated by a -2, then an array of chrnums in team 2 terminated
	 * by -2, and so on.
	 */
	do {
		u8 teamvalue = (1 << team);

		while (*chrnums != -2 && g_Vars.chrdata->team != teamvalue) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->prop
					&& !chrIsDead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP
					&& chrCompareTeams(g_Vars.chrdata, chr, 2)
					&& chr != g_Vars.chrdata
					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
					&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0
					&& (chr->hidden & CHRHFLAG_DISGUISED) == 0
					&& chr->team != TEAM_NONCOMBAT
					&& (
						(g_Vars.chrdata->hidden & CHRHFLAG_PSYCHOSISED) == 0
						|| (chr->hidden & CHRHFLAG_40000000) == 0
						|| chr->hidden & CHRHFLAG_08000000)) {
				f32 distance = chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum);

				if (distance < maxdist && distance != 0 && distance < closestdist
						&& func0f039558(g_Vars.chrdata, chr->prop)
						&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0) {
					if (g_Vars.chrdata->yvisang == 0) {
						closestdist = distance;
						closesttarg = chr->chrnum;
					} else {
						s16 prevtarget = g_Vars.chrdata->target;
						g_Vars.chrdata->target = propGetIndexByChrId(g_Vars.chrdata, chr->chrnum);

						if (func0f048f20(g_Vars.chrdata, g_Vars.chrdata->yvisang)) {
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
		g_Vars.chrdata->target = propGetIndexByChrId(g_Vars.chrdata, closesttarg);
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 4;
	}

	return false;
}

/**
 * @cmd 0129
 */
bool aiIfSafetyLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 *chrnums = teamGetChrIds(g_Vars.chrdata->team);
	u8 safety = 6;
	u8 numnearby = 0;

	if (chrGetNumArghs(g_Vars.chrdata) > 0) {
		safety--;
	}

	while (*chrnums != -2) {
		struct chrdata *chr = chrFindByLiteralId(*chrnums);

		if (chr && chr->animdata
				&& !chrIsDead(chr)
				&& chr->actiontype != ACT_DEAD
				&& g_Vars.chrdata->chrnum != chr->chrnum
				&& chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum) < 3500) {
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
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 012a
 */
bool aiIfTargetMovingSlowly(void)
{
	s32 delta;
	s32 absdelta;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] == 0) {
		delta = chrGetDistanceLostToTargetInLastSecond(g_Vars.chrdata);
	} else {
		struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
		delta = chrGetDistanceLostToTargetInLastSecond(chr);
	}

	absdelta = delta > 0 ? delta : -delta;

	if (absdelta < 50) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 012b
 */
bool aiIfTargetMovingCloser(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGetDistanceLostToTargetInLastSecond(g_Vars.chrdata) < -50) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 012c
 */
bool aiIfTargetMovingAway(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrGetDistanceLostToTargetInLastSecond(g_Vars.chrdata) > 50) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
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
		coverSetFlag0002(g_Vars.chrdata->cover, 0);
	}

	g_Vars.aioffset += 2;

	return false;
}

s16 g_GuardQuipBank[][4] = {
	// Voicebox 0
	{ QUIP_ATTACK1,            0x027b, 0x027b, 0x027c }, // "I've got a clear shot", "She's mine"
	{ QUIP_ATTACK2,            0x027d, 0x027e, 0x027f }, // "Open fire", "Wipe her out", "Waste her"
	{ QUIP_GOTOCOVER1,         0x028a, 0x028b, 0x028c }, // "Cover me", "Watch my back", "Take cover"
	{ QUIP_GRENADE1,           0x035b, 0x035c, 0x035d }, // "Look out, look out", "It's a grenade", "Clear the area"
	{ QUIP_RETREAT1,           0x0290, 0x80fb, 0x0292 }, // "Go to plan B", "Get the hell out of here", "Retreat"
	{ QUIP_GRENADE2,           0x0293, 0x0294, 0x029d }, // "Catch", "Everybody down", "Grenade"
	{ QUIP_RETREAT2,           0x0297, 0x0298, 0x0299 }, // "Fall back", "Everyone back off", "Withdraw"
	{ QUIP_FLANK,              0x029a, 0x029b, 0x029c }, // "Flank the target", "Let's split up", "Surround her"
	{ QUIP_SURRENDER,          0x02a7, 0x02a8, 0x02a9 }, // "Please, don't shoot me", "I give up", "You win, I surrender"
	{ QUIP_HEARNOISE,          0x026b, 0x026c, 0x026d }, // "Did you hear that?", "What's that noise?", "I heard a noise"
	{ QUIP_10,                 0x0037, 0x0037, 0x0037 },
	{ QUIP_SEEPLAYER,          0x0264, 0x0265, 0x0266 }, // "Hey, you", "Intruder alert", "We've got a contact"
	{ QUIP_SHOTUNALERT,        0x80f7, 0x80f7, 0x80f8 }, // "Holy shh", "What the hell?"
	{ QUIP_INJURED1,           0x025e, 0x025f, 0x0260 }, // "Medic!", "Ow!", "You shot me!"
	{ QUIP_INJURED2,           0x0261, 0x0262, 0x0263 }, // "I'm hit, I'm hit!", "I'm taking fire!", "Taking damage!"
	{ QUIP_KILLEDPLAYER1,      0x02a3, 0x02a4, 0x02a5 }, // "Grab a body bag", "One for the morgue", "Rest in peace"
	{ QUIP_WARNFRIENDS,        0x0272, 0x0273, 0x0274 }, // "Intruder alert", "We've got trouble", "We've got problems"
	{ QUIP_GOFORALARM,         0x0037, 0x0037, 0x0037 },
	{ QUIP_SURPRISED,          0x025b, 0x025c, 0x025c }, // "What the?", "Who the?"
	{ QUIP_INSPECTBODY,        0x026e, 0x026f, 0x0270 }, // "Are you okay?", "Got a man down!", "He's bought it"
	{ QUIP_20,                 0x0037, 0x0037, 0x0037 },
	{ QUIP_HITPLAYER,          0x0280, 0x0281, 0x0282 }, // "Give it up!", "Surrender, now!", "Take that!"
	{ QUIP_MISSEDPLAYER1,      0x80f9, 0x80f9, 0x0287 }, // "Damn it, missed", "How did I miss?"
	{ QUIP_MISSEDPLAYER2,      0x80fa, 0x80fa, 0x0289 }, // "God sake, someone hit her", "She's a tricky one"
	{ QUIP_GOTOCOVER2,         0x028d, 0x028e, 0x028f }, // "Take cover", "I'll cover you", "Get down!"
	{ QUIP_DIE,                0x80fc, 0x80fd, 0x02a2 }, // "You bitch", "Oh my god", "She got me"
	{ QUIP_26,                 0x0037, 0x0037, 0x0037 },
	{ QUIP_SEARCHSUCCESS,      0x0275, 0x0277, 0x0278 }, // "I see her", "There she is", "There, movement"
	{ QUIP_SEEEYESPY,          0x8167, 0x04c9, 0x04ca }, // "What the hell?", "Hello there", "What's this?"
	{ QUIP_GREETING,           0x815d, 0x815e, 0x815f }, // "How's things?", "Hey there", "Hi, how are you?"
	{ QUIP_ASKWEAPON1,         0x1aa0, 0x1aa1, 0x1aa2 }, // "Where did you get that?", "Should you have that?", "What are you doing with that weapon?"
	{ QUIP_ASKWEAPON2,         0x0037, 0x1aa3, 0x1aa4 }, // "Don't point that at me", "Watch where you're pointing that"
	{ QUIP_UNCOVERDISGUISE1,   0x1aa5, 0x1aa5, 0x1aa6 }, // "Imposter!", "It's a spy!"
	{ QUIP_LOSTGUN,            0x04c6, 0x04c6, 0x04c6 }, // "My gun!"
	{ QUIP_GOFORALARM,         0x04c7, 0x04c7, 0x04c7 }, // "Trigger the alarm"
	{ QUIP_SEARCHFAIL,         0x04cb, 0x04cb, 0x04cc }, // "I'm sure I heard a noise", "I must be hearing things"
	{ QUIP_ATTACK3,            0x027b, 0x027b, 0x027d }, // "I've got a clear shot", "Open fire!"
	{ QUIP_ATTACK4,            0x027b, 0x027d, 0x027d }, // "I've got a clear shot", "Open fire!"
	{ QUIP_KILLEDPLAYER2,      0x02a3, 0x02a4, 0x02a5 }, // "Grab a body bag", "One for the morgue", "Rest in peace"
	{ QUIP_GUNJAMMED,          0x04c6, 0x04c6, 0x04c6 }, // "My gun!"
	{ QUIP_UNCOVEREDDISGUISE2, 0x1aa6, 0x1aa6, 0x1aa6 }, // "It's a spy!"
	// Voicebox 1
	{ QUIP_ATTACK1,            0x0322, 0x0323, 0x0324 }, // "You made your last mistake", "What are you waiting for?", "Bring it on"
	{ QUIP_ATTACK2,            0x0325, 0x0326, 0x0327 }, // "Take her down, men!", "Everybody, get her!", "Attack!"
	{ QUIP_GOTOCOVER1,         0x812e, 0x0335, 0x0336 }, // "Cover my ass", "Cover me, now!", "I'm going for cover"
	{ QUIP_GRENADE1,           0x035b, 0x035c, 0x035d }, // "Look out, look out!", "It's a grenade", "Clear the area"
	{ QUIP_RETREAT1,           0x033a, 0x033b, 0x033c }, // "She's too good, run!", "Get some backup!", "Evacuate the area!"
	{ QUIP_GRENADE2,           0x033d, 0x033f, 0x0342 }, // "Catch this", "Here, keep it", "Grenade!"
	{ QUIP_RETREAT2,           0x0343, 0x0344, 0x0345 }, // "Withdraw, withdraw!", "Fall back!", "Everyone, get back!"
	{ QUIP_FLANK,              0x0346, 0x0347, 0x0348 }, // "Surround her!", "Spread out!", "Split up!"
	{ QUIP_SURRENDER,          0x0349, 0x034a, 0x034b }, // "Please don't", "Don't shoot", "I'm only doing my job"
	{ QUIP_HEARNOISE,          0x030e, 0x030f, 0x0310 }, // "That sounded like...", "Gunfire!", "Someone's shooting!"
	{ QUIP_10,                 0x0037, 0x0037, 0x0037 },
	{ QUIP_SEEPLAYER,          0x0306, 0x0307, 0x0308 }, // "Come here", "There's someone here", "Get her"
	{ QUIP_SHOTUNALERT,        0x0309, 0x8128, 0x030b }, // "Whoa!", "My god", "Is that a bullet?"
	{ QUIP_INJURED1,           0x8126, 0x0301, 0x0302 }, // "Oh my god", "I'm hit, I'm hit!", "I'm bleeding"
	{ QUIP_INJURED2,           0x8127, 0x0304, 0x0305 }, // "Oh god I'm hit", "Help me out", "I'm in trouble"
	{ QUIP_KILLEDPLAYER1,      0x0037, 0x0037, 0x0037 },
	{ QUIP_WARNFRIENDS,        0x031c, 0x031d, 0x031e }, // "Look out, she's coming!", "Take cover!", "Look out, look out"
	{ QUIP_GOFORALARM,         0x0037, 0x0037, 0x0037 },
	{ QUIP_SURPRISED,          0x8124, 0x8125, 0x02ff }, // "Holy...", "What the hell?", "Wha?"
	{ QUIP_INSPECTBODY,        0x8129, 0x812a, 0x0316 }, // "Noooo!", "Oh god he's dead!", "He's gone!"
	{ QUIP_20,                 0x031c, 0x031d, 0x031e }, // "Look out, she's coming!", "Take cover!", "Look out, look out"
	{ QUIP_HITPLAYER,          0x0356, 0x0329, 0x0329 }, // "I'm just too good", "Yeah baby"
	{ QUIP_MISSEDPLAYER1,      0x812b, 0x032f, 0x812c }, // "Bloody stupid gun", "My gun, it's useless", "Damn it"
	{ QUIP_MISSEDPLAYER2,      0x0331, 0x0332, 0x812d }, // "Stop dodging", "Someone hit her", "Damn, she's good"
	{ QUIP_GOTOCOVER2,         0x0337, 0x0338, 0x0339 }, // "Go for it", "Go go, go!", "Run!"
	{ QUIP_DIE,                0x812f, 0x034d, 0x034e }, // Death scream, "Why me", choking
	{ QUIP_26,                 0x0355, 0x0356, 0x0357 }, // "Outstanding", "I'm just too good"
	{ QUIP_SEARCHSUCCESS,      0x031f, 0x0320, 0x0321 }, // "Over there", "Halt", "Freeze"
	{ QUIP_SEEEYESPY,          0x04cf, 0x04d0, 0x04d1 }, // "What is it?", "How did that get here?", "Don't touch it!"
	{ QUIP_GREETING,           0x8163, 0x8163, 0x8164 }, // "Hi there", "How's things?"
	{ QUIP_ASKWEAPON1,         0x1ace, 0x1ace, 0x1acf }, // "Where are you taking that weapon?", "Get that firearm approved, now!"
	{ QUIP_ASKWEAPON2,         0x1ad0, 0x1ad0, 0x1ad1 }, // "Hey watch what you're doing with that", "Be careful!"
	{ QUIP_UNCOVERDISGUISE1,   0x1ad2, 0x1ad2, 0x1ad3 }, // "Stop right there", "Drop the gun"
	{ QUIP_LOSTGUN,            0x8168, 0x8168, 0x8168 }, // "Geez"
	{ QUIP_GOFORALARM,         0x04ce, 0x04ce, 0x04ce }, // "Warn the others"
	{ QUIP_SEARCHFAIL,         0x04d2, 0x04d3, 0x04d3 }, // "I can't see anybody", "There's no one here"
	{ QUIP_ATTACK3,            0x0322, 0x0323, 0x0324 }, // "You made your last mistake", "What are you waiting for?", "Bring it on"
	{ QUIP_ATTACK4,            0x0324, 0x0327, 0x0327 }, // "Bring it on", "Attack!"
	{ QUIP_KILLEDPLAYER2,      0x0356, 0x0357, 0x035a }, // "I'm just too good", "Yee-ha, got one", "Another one bites the dust"
	{ QUIP_GUNJAMMED,          0x812b, 0x032f, 0x812c }, // "Bloody stupid gun", "My gun, it's useless", "Damn it"
	{ QUIP_UNCOVEREDDISGUISE2, 0x1ad2, 0x1ad2, 0x1ad2 }, // "Stop right there!"
	// Voicebox 2
	{ QUIP_ATTACK1,            0x03e7, 0x03e8, 0x03e9 }, // "Come on, man", "Die", "Take this"
	{ QUIP_ATTACK2,            0x03ea, 0x03eb, 0x03ec }, // "Move in", "You're out of your league", "Let her have it"
	{ QUIP_GOTOCOVER1,         0x03f9, 0x03fa, 0x03fb }, // "Help me out here", "Hey, distract her", "Keep her occupied"
	{ QUIP_GRENADE1,           0x0420, 0x0421, 0x813d }, // "Get back, quick!", "We're gonna die!", "God, run!"
	{ QUIP_RETREAT1,           0x03ff, 0x8139, 0x0401 }, // "Retreat!", "Let's get the hell out of here", "Get back, get back!"
	{ QUIP_GRENADE2,           0x0403, 0x0405, 0x0407 }, // "Fire in the hole", "Here's a little present for ya", "Try this for size"
	{ QUIP_RETREAT2,           0x0408, 0x0409, 0x040a }, // "Get out of the way!", "Fall back!", "Move out"
	{ QUIP_FLANK,              0x040b, 0x040c, 0x040d }, // "Team up, guys", "Come on, around the side", "Scatter!"
	{ QUIP_SURRENDER,          0x040e, 0x040f, 0x0410 }, // "I don't like this any more", "Don't hurt me", "You win, I give up"
	{ QUIP_HEARNOISE,          0x03d6, 0x03d6, 0x03d7 }, // "Listen, gunshots", "Someone's nearby"
	{ QUIP_10,                 0x0037, 0x0037, 0x0037 },
	{ QUIP_SEEPLAYER,          0x03d0, 0x03d1, 0x8134 }, // "Target sighted", "Come on, man", "God damn it"
	{ QUIP_SHOTUNALERT,        0x03d3, 0x8135, 0x03d5 }, // "That was close", "Holy moly", "Ay caramba"
	{ QUIP_INJURED1,           0x8132, 0x03c8, 0x03c8 }, // "Geez, that hurt", "Why you..."
	{ QUIP_INJURED2,           0x03cd, 0x03ce, 0x8133 }, // "I'm injured", "I'm hit, I'm hit", "Damn it, I'm taking fire!"
	{ QUIP_KILLEDPLAYER1,      0x0037, 0x0037, 0x0037 },
	{ QUIP_WARNFRIENDS,        0x03e1, 0x03e2, 0x03e3 }, // "Watch out!", "Help me out", "We've got an intruder"
	{ QUIP_GOFORALARM,         0x0037, 0x0037, 0x0037 },
	{ QUIP_SURPRISED,          0x03c4, 0x03c5, 0x03c6 }, // "How the?", "Hey", "Stop"
	{ QUIP_INSPECTBODY,        0x03d9, 0x03da, 0x03db }, // "Body count's too high!", "I never liked him anyway", "That was my best friend"
	{ QUIP_20,                 0x031c, 0x031d, 0x031e }, // "Look out, she's coming!", "Take cover!", "Look out, look out"
	{ QUIP_HITPLAYER,          0x03ed, 0x03ee, 0x03ef }, // "Surrender or die", "I have you now", "You won't beat me"
	{ QUIP_MISSEDPLAYER1,      0x8136, 0x03f4, 0x8137 }, // "Damn, missed again", "I don't believe it", "Damn you"
	{ QUIP_MISSEDPLAYER2,      0x8138, 0x03f7, 0x03f8 }, // "Hell, she's good", "Stop moving", "No escape for you"
	{ QUIP_GOTOCOVER2,         0x03fc, 0x03fd, 0x03fe }, // "Move it, move it", "Get to cover now", "Run for it"
	{ QUIP_DIE,                0x813a, 0x813c, 0x0415 }, // "Noooo!", "Oh god, I'm dying", "I don't want to die"
	{ QUIP_26,                 0x041b, 0x041c, 0x041d }, // "I'm the man", "Boy that was close", "Did you see that?"
	{ QUIP_SEARCHSUCCESS,      0x03e4, 0x03e5, 0x03e6 }, // "Get her!", "There, attack!", "Hey, you, stop!"
	{ QUIP_SEEEYESPY,          0x04d5, 0x04d6, 0x04d7 }, // "Is it dangerous?", "Don't move", "Stay back"
	{ QUIP_GREETING,           0x8165, 0x8165, 0x8166 }, // "Hello", "Hey, what's up?"
	{ QUIP_ASKWEAPON1,         0x1ad6, 0x1ad6, 0x1ad7 }, // "Do you have permission for that?", "What are you doing with that gun?"
	{ QUIP_ASKWEAPON2,         0x1ad8, 0x1ad8, 0x1ad9 }, // "Hey, that's dangerous", "Watch it, that thing could go off"
	{ QUIP_UNCOVERDISGUISE1,   0x1ada, 0x1ada, 0x1adb }, // "Put your hands up", "It's a terrorist!"
	{ QUIP_LOSTGUN,            0x8168, 0x8168, 0x8168 }, // "Geez"
	{ QUIP_GOFORALARM,         0x04d4, 0x04d4, 0x04d4 }, // "Activate the alarm!"
	{ QUIP_SEARCHFAIL,         0x04d8, 0x04d8, 0x04d9 }, // "I bet this is another drill", "Another false alarm"
	{ QUIP_ATTACK3,            0x03e7, 0x03e8, 0x03e9 }, // "Come on, man", "Die", "Take this"
	{ QUIP_ATTACK4,            0x03e8, 0x03eb, 0x03eb }, // "Die", "You're out of your league"
	{ QUIP_KILLEDPLAYER2,      0x041b, 0x0417, 0x041d }, // "I'm the man", "It's all over for this one", "Did you see that?"
	{ QUIP_GUNJAMMED,          0x8134, 0x03f4, 0x8134 }, // "God damn it", "I don't believe it"
	{ QUIP_UNCOVEREDDISGUISE2, 0x1adb, 0x1adb, 0x1adb }, // "It's a terrorist!"
	// Voicebox 3 (female)
	{ QUIP_ATTACK1,            0x0396, 0x0396, 0x0396 }, // "Come on"
	{ QUIP_ATTACK2,            0x0037, 0x0398, 0x0399 }, // "Everyone, get her", "Attack!"
	{ QUIP_GOTOCOVER1,         0x03a4, 0x0037, 0x03a6 }, // "Cover me!", "Take cover!"
	{ QUIP_GRENADE1,           0x03c1, 0x03c2, 0x03c2 }, // "Look out, look out!"
	{ QUIP_RETREAT1,           0x03aa, 0x03ab, 0x03ac }, // "Get reinforcements!", "Evacuate the area", "Retreat!"
	{ QUIP_GRENADE2,           0x03ad, 0x03ae, 0x0037 }, // "Catch this", "Time to die"
	{ QUIP_RETREAT2,           0x03b0, 0x03b0, 0x03b1 }, // "Withdraw, withdraw!", "Fall back!"
	{ QUIP_FLANK,              0x0037, 0x03b3, 0x03b4 }, // "Spread out", "Split up"
	{ QUIP_SURRENDER,          0x03b5, 0x03b5, 0x03b6 }, // "Please dont", "Don't shoot"
	{ QUIP_HEARNOISE,          0x0037, 0x0389, 0x038a }, // ???, "Someone's shooting"
	{ QUIP_10,                 0x0000, 0x0000, 0x0000 },
	{ QUIP_SEEPLAYER,          0x0381, 0x0382, 0x0037 }, // "Get her!", "Hey, you, come here!"
	{ QUIP_SHOTUNALERT,        0x0385, 0x0037, 0x0387 }, // "Under fire!", "We're under fire!"
	{ QUIP_INJURED1,           0x0037, 0x037e, 0x037f }, // "I'm wounded", "Help me out"
	{ QUIP_INJURED2,           0x037e, 0x037f, 0x0380 }, // "I'm wounded", "I'm in trouble!"
	{ QUIP_KILLEDPLAYER1,      0x0000, 0x0000, 0x0000 },
	{ QUIP_WARNFRIENDS,        0x0384, 0x0385, 0x0037 }, // "Target attacking", "Under fire!"
	{ QUIP_GOFORALARM,         0x03aa, 0x03ab, 0x03ac }, // "Get reinforcements", "Evacuate the area", "Retreat!"
	{ QUIP_SURPRISED,          0x0037, 0x037b, 0x037c }, // "Hey", "Huh?"
	{ QUIP_INSPECTBODY,        0x038d, 0x038d, 0x038d }, // "Unit down"
	{ QUIP_20,                 0x0384, 0x0385, 0x0387 }, // "Target attacking", "Under fire!", "We're under fire!"
	{ QUIP_HITPLAYER,          0x039a, 0x039b, 0x0037 }, // "Did that hurt?", "You want some more?"
	{ QUIP_MISSEDPLAYER1,      0x039f, 0x0037, 0x03a1 }, // "This gun's useless", "Stand still"
	{ QUIP_MISSEDPLAYER2,      0x03a1, 0x03a2, 0x8130 }, // "Stand still", "Someone hit her", "Damn, she's good"
	{ QUIP_GOTOCOVER2,         0x03a7, 0x0037, 0x03a9 }, // "Go for it!", "Run!"
	{ QUIP_DIE,                0x03b7, 0x03b8, 0x8131 }, // "Why me?", "Nooo!", "My god"
	{ QUIP_26,                 0x03be, 0x0037, 0x03c0 }, // "I'm just too good", "Such a waste"
	{ QUIP_SEARCHSUCCESS,      0x0381, 0x0382, 0x0037 }, // "Get her!", "Hey, you, come here"
	{ QUIP_SEEEYESPY,          0x0000, 0x0000, 0x0000 },
	{ QUIP_GREETING,           0x0037, 0x0396, 0x0037 }, // "Come on"
	{ QUIP_ASKWEAPON1,         0x0037, 0x0396, 0x0037 }, // "Come on"
	{ QUIP_ASKWEAPON2,         0x0037, 0x0396, 0x0037 }, // "Come on"
	{ QUIP_UNCOVERDISGUISE1,   0x0037, 0x0396, 0x0037 }, // "Come on"
	{ QUIP_LOSTGUN,            0x037b, 0x037c, 0x037b }, // "Hey", "Huh?"
	{ QUIP_GOFORALARM,         0x03aa, 0x03b1, 0x03ab }, // "Get reinforcements!", "Fall back!", "Evacuate the area"
	{ QUIP_SEARCHFAIL,         0x0000, 0x0000, 0x0000 },
	{ QUIP_ATTACK3,            0x0396, 0x0396, 0x0399 }, // "Come on", "Attack!"
	{ QUIP_ATTACK4,            0x0399, 0x0399, 0x0396 }, // "Attack!", "Come on"
	{ QUIP_KILLEDPLAYER2,      0x03bc, 0x03be, 0x03c0 }, // "Get a cleaner", "I'm just too good", "Such a waste"
	{ QUIP_GUNJAMMED,          0x039f, 0x039f, 0x039f }, // "This gun's useless"
	{ QUIP_UNCOVEREDDISGUISE2, 0x0000, 0x0000, 0x0000 },
};

s16 g_SpecialQuipBank[][4] = {
	{  0, 0x0af2, 0x0af3, 0x0af8 },
	{  1, 0x1aee, 0x1aef, 0x1aee }, // Secretary: "Please don't kill me", "Don't shoot"
	{  2, 0x023d, 0x023e, 0x0247 }, // Dr Caroll: "Come on, come on", "My dear you're taking your time", "Come on my dear, we're going to get out of here now"
	{  3, 0x0248, 0x0249, 0x024b }, // Dr Caroll: "Do you actually know what you're doing", "Ooh, ...?", "We're going to the helipad I presume"
	{  4, 0x0246, 0x023f, 0x0240 }, // Dr Caroll: "I say over there, stop that", "What", "Ooh"
	{  5, 0x024c, 0x0252, 0x0251 }, // Dr Caroll: "Ooh-uh", "That's quite enough of that", "Wow"
	{  6, 0x024f, 0x0258, 0x024d }, // Dr Caroll: "I can't make it", "You were supposed to protect me", "Systems failure"
	{  7, 0x0243, 0x0244, 0x0245 }, // Dr Caroll: "Oh crikey", "Goodness gracious me", "Don't they know who I am"
	{  8, 0x1294, 0x1295, 0x1296 }, // Invest shock: "I'm not sure", "One more time", "I dunno"
	{  9, 0x1297, 0x1298, 0x1297 }, // Scientist: "And again", "Try it now"
	{ 10, 0x1290, 0x127e, 0x8103 }, // Scientist: "What are you doing in my lab?", "I haven't seen you before", "Who the hell are you?"
	{ 11, 0x7324, 0x7325, 0x7326 }, // Jo: "Shut down the experiments", "Pull the plug on that, now!", "Switch this thing off"
	{ 12, 0x128e, 0x1280, 0x1287 }, // Scientist: "I'll shut it down", "Please, don't hurt me", "Allow me to assist you"
	{ 13, 0x128d, 0x1283, 0x1286 }, // Scientist: "My experiments!", "There, the experiment is down", "Leave this area now!"
	{ 14, 0x1291, 0x1284, 0x128a }, // Scientist: "Security!", "I'm calling security", "Accidents will happen"
	{ 15, 0x1292, 0x1281, 0x1288 }, // Scientist: "How did that happen", "It looks like it's off already", "Have you been tampering with this?"
	{ 16, 0x128b, 0x1282, 0x1289 }, // Scientist: "Someone's broken my equipment", "What's happened to the terminal?", "You vandal, you've broken it"
	{ 17, 0x000d, 0x000d, 0x000d },
	{ 18, 0x815d, 0x815e, 0x815f }, // "How's things?", "Hey there", "Hi, how are you?"
	{ 19, 0x1aa0, 0x1aa1, 0x1aa2 }, // "Where did you get that?", "Should you have that?", "What are you doing with that weapon?"
	{ 20, 0x0037, 0x1aa3, 0x1aa4 }, // "Don't point that at me", "Watch where you're pointing that"
	{ 21, 0x1aa5, 0x1aa5, 0x1aa6 }, // "Imposter!", "It's a spy!"
	{ 22, 0x0446, 0x0461, 0x0465 }, // "Greetings, citizen", "Hey sugar, wanna party?", "Hey baby"
	{ 23, 0x0447, 0x045d, 0x0466 }, // "How's it going?", "Whoa, take it easy there lady", wolf whistle
	{ 24, 0x814a, 0x045e, 0x0463 }, // "Oh my god", "I don't want any trouble", "Here, take the wallet"
	{ 25, 0x0444, 0x045f, 0x0468 }, // "There's a maniac on the loose", "Quick, down there, she's got a gun", "Help, get me out of here!"
	{ 26, 0x0448, 0x0449, 0x0449 }, // "Guns don't scare me", "Keep away from this car"
	{ 27, 0x044b, 0x0459, 0x045a }, // "Base, we have an intruder", "We have a code 2 situation", "Request backup immediately"
	{ 28, 0x05be, 0x0515, 0x05bf }, // "You shouldn't have come here, girl", "Secure the perimeter", "We're taking over!"
	{ 29, 0x044b, 0x0459, 0x045a }, // "Base, we have an intruder", "We have a code 2 situation", "Request backup immediately"
	{ 30, 0x044b, 0x0459, 0x045a }, // "Base, we have an intruder", "We have a code 2 situation", "Request backup immediately"
	{ 31, 0x1aeb, 0x1aeb, 0x1aeb }, // Robot: "Stop where you are"
	{ 32, 0x1b35, 0x1b36, 0x1b37 }, // "Come back later, I'm busy", "Go away", "Look, I can't help you"
	{ 33, 0x1ac0, 0x1ac1, 0x1ac3 }, // President: "Stop shooting!", "You sure this is the way to the escape pod?", "Why are they shooting at me?"
	{ 34, 0x0446, 0x0461, 0x0000 }, // "Greetings, citizen", "Hey sugar, wanna party?"
	{ 35, 0x0447, 0x045d, 0x0000 }, // "How's it going?", "Whoa, take it easy there lady"
	{ 36, 0x814a, 0x045e, 0x1aee }, // "Oh my god", "I don't want any trouble", "Please don't kill me"
	{ 37, 0x0444, 0x045f, 0x0000 }, // "There's a maniac on the loose", "Quick, down there, she's got a gun"
	{ 38, 0x051b, 0x051c, 0x051d }, // Elvis: "In the name of intergalactic peace", "Eat hot lead, weirdos", "Kiss my alien butt"
	{ 39, 0x051e, 0x051f, 0x0520 }, // Elvis: "I'll kick your ass", "I'm doing this for your own good", "You dare shoot at me?"
	{ 40, 0x0521, 0x0522, 0x0525 }, // Elvis: "Don't mess with the Maian", "I'm bad", "He he"
	{ 41, 0x0523, 0x0523, 0x0524 }, // Elvis: "Oh It's all going wrong", "Hey, watch the suit"
	{ 42, 0x1adb, 0x1aa6, 0x1ad2 }, // "It's a terrorist!", "It's a spy!", "Stop right there!"
	{ 43, 0x0af2, 0x0af8, 0x0af8 },
	{ 44, 0x0525, 0x0525, 0x0525 }, // Elvis: "He he"
	{ 45, 0x1aec, 0x1aec, 0x1aec }, // Robot: "Alert! Under attack"
};

s16 g_QuipTexts[][4] = {
	{  1, L_AME(83), L_AME(84), L_AME(85) }, // "How dare you disturb me!", "You will regret this intrusion, girl!", "If I were you, I'd leave...NOW!"
	{  2, L_AME(86), L_AME(87), L_AME(86) }, // "Please don't kill me!", "Don't shoot!"
	{  3, L_EAR(64), L_EAR(65), L_EAR(66) }, // "What are you doing in my lab?", "I haven't seen you before...", "Who the hell are you?"
	{  4, L_EAR(67), L_EAR(68), L_EAR(69) }, // "Shut down the experiment.", "Pull the plug on that, NOW.", "Switch this thing off."
	{  5, L_EAR(70), L_EAR(71), L_EAR(72) }, // "I'll shut it down.", "Please don't hurt me.", "Allow me to assist you."
	{  6, L_EAR(73), L_EAR(74), L_EAR(75) }, // "My experiments!", "There the experiment is down.", "Leave this area NOW!"
	{  7, L_EAR(76), L_EAR(77), L_EAR(78) }, // "Security!", "I'm calling security.", "Accidents will happen."
	{  8, L_EAR(79), L_EAR(80), L_EAR(81) }, // "How did that happen?", "Looks like it's off already.", "Have you been tampering with this?"
	{  9, L_EAR(82), L_EAR(83), L_EAR(84) }, // "Someone's broken my equipment.", "What's happened to the terminal?", "You vandal - you've broken it."
	{ 10, L_WAX(10), L_WAX(12), L_WAX(12) }, // "How dare you disturb me!", "If I were you, I'd leave... NOW!"
};

s16 g_SkedarQuipBank[][4] = {
	{ 1, 0x0529, 0x052a, 0x052b },
	{ 2, 0x052d, 0x052e, 0x052f },
	{ 3, 0x0530, 0x0530, 0x0531 },
	{ 1, 0x0532, 0x0533, 0x0534 },
	{ 2, 0x0536, 0x0537, 0x0538 },
	{ 3, 0x0539, 0x0539, 0x053a },
	{ 0, 0x0000, 0x0000, 0x0000 },
};

s16 g_MaianQuipBank[][4] = {
	{ 1, 0x05e2, 0x05e3, 0x05e4 }, // laughter, mumble, mumble
	{ 2, 0x05e5, 0x05e6, 0x05e7 }, // mumble, mumble, laughter
	{ 3, 0x05df, 0x05e0, 0x05e1 }, // injuries
	{ 0, 0x0000, 0x0000, 0x0000 },
};

/**
 * @cmd 0130
 */
GLOBAL_ASM(
.late_rodata
glabel var7f1a9d64
.word 0x45dac000
.text
glabel aiSayQuip
/*  f05a258:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f05a25c:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f05a260:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f05a264:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f05a268:	8e0e0434 */ 	lw	$t6,0x434($s0)
/*  f05a26c:	8e0f0438 */ 	lw	$t7,0x438($s0)
/*  f05a270:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f05a274:	8e040424 */ 	lw	$a0,0x424($s0)
/*  f05a278:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f05a27c:	90450002 */ 	lbu	$a1,0x2($v0)
/*  f05a280:	0fc126d1 */ 	jal	chrFindById
/*  f05a284:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f05a288:	8e18028c */ 	lw	$t8,0x28c($s0)
/*  f05a28c:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f05a290:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*  f05a294:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f05a298:	94f90192 */ 	lhu	$t9,0x192($a3)
/*  f05a29c:	91060003 */ 	lbu	$a2,0x3($t0)
/*  f05a2a0:	00402825 */ 	or	$a1,$v0,$zero
/*  f05a2a4:	33291000 */ 	andi	$t1,$t9,0x1000
/*  f05a2a8:	10e00003 */ 	beqz	$a3,.L0f05a2b8
/*  f05a2ac:	a3a9006b */ 	sb	$t1,0x6b($sp)
/*  f05a2b0:	10000002 */ 	beqz	$zero,.L0f05a2bc
/*  f05a2b4:	90e302fe */ 	lbu	$v1,0x2fe($a3)
.L0f05a2b8:
/*  f05a2b8:	00001825 */ 	or	$v1,$zero,$zero
.L0f05a2bc:
/*  f05a2bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f05a2c0:	14610007 */ 	bne	$v1,$at,.L0f05a2e0
/*  f05a2c4:	3c0a8007 */ 	lui	$t2,%hi(g_SkedarQuipBank)
/*  f05a2c8:	254a96d8 */ 	addiu	$t2,$t2,%lo(g_SkedarQuipBank)
/*  f05a2cc:	28c10006 */ 	slti	$at,$a2,0x6
/*  f05a2d0:	1420002a */ 	bnez	$at,.L0f05a37c
/*  f05a2d4:	afaa0084 */ 	sw	$t2,0x84($sp)
/*  f05a2d8:	10000028 */ 	beqz	$zero,.L0f05a37c
/*  f05a2dc:	00003025 */ 	or	$a2,$zero,$zero
.L0f05a2e0:
/*  f05a2e0:	80eb0006 */ 	lb	$t3,0x6($a3)
/*  f05a2e4:	24030029 */ 	addiu	$v1,$zero,0x29
/*  f05a2e8:	3c0c8007 */ 	lui	$t4,%hi(g_MaianQuipBank)
/*  f05a2ec:	146b000d */ 	bne	$v1,$t3,.L0f05a324
/*  f05a2f0:	258c9710 */ 	addiu	$t4,$t4,%lo(g_MaianQuipBank)
/*  f05a2f4:	28c10003 */ 	slti	$at,$a2,0x3
/*  f05a2f8:	14200020 */ 	bnez	$at,.L0f05a37c
/*  f05a2fc:	afac0084 */ 	sw	$t4,0x84($sp)
/*  f05a300:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f05a304:	0c004b70 */ 	jal	random
/*  f05a308:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f05a30c:	30460001 */ 	andi	$a2,$v0,0x1
/*  f05a310:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f05a314:	8fa5007c */ 	lw	$a1,0x7c($sp)
/*  f05a318:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f05a31c:	10000017 */ 	beqz	$zero,.L0f05a37c
/*  f05a320:	8fa8009c */ 	lw	$t0,0x9c($sp)
.L0f05a324:
/*  f05a324:	910e0007 */ 	lbu	$t6,0x7($t0)
/*  f05a328:	3c0b8007 */ 	lui	$t3,%hi(g_SpecialQuipBank)
/*  f05a32c:	256b9518 */ 	addiu	$t3,$t3,%lo(g_SpecialQuipBank)
/*  f05a330:	55c00012 */ 	bnezl	$t6,.L0f05a37c
/*  f05a334:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f05a338:	90e202b1 */ 	lbu	$v0,0x2b1($a3)
/*  f05a33c:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f05a340:	28410004 */ 	slti	$at,$v0,0x4
/*  f05a344:	14200004 */ 	bnez	$at,.L0f05a358
/*  f05a348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a34c:	a0ef02b1 */ 	sb	$t7,0x2b1($a3)
/*  f05a350:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f05a354:	90e202b1 */ 	lbu	$v0,0x2b1($a3)
.L0f05a358:
/*  f05a358:	00430019 */ 	multu	$v0,$v1
/*  f05a35c:	3c098007 */ 	lui	$t1,%hi(g_GuardQuipBank)
/*  f05a360:	25298ff8 */ 	addiu	$t1,$t1,%lo(g_GuardQuipBank)
/*  f05a364:	0000c012 */ 	mflo	$t8
/*  f05a368:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f05a36c:	03295021 */ 	addu	$t2,$t9,$t1
/*  f05a370:	10000002 */ 	beqz	$zero,.L0f05a37c
/*  f05a374:	afaa0084 */ 	sw	$t2,0x84($sp)
/*  f05a378:	afab0084 */ 	sw	$t3,0x84($sp)
.L0f05a37c:
/*  f05a37c:	54c0000e */ 	bnezl	$a2,.L0f05a3b8
/*  f05a380:	90e40125 */ 	lbu	$a0,0x125($a3)
/*  f05a384:	910c0004 */ 	lbu	$t4,0x4($t0)
/*  f05a388:	5580000b */ 	bnezl	$t4,.L0f05a3b8
/*  f05a38c:	90e40125 */ 	lbu	$a0,0x125($a3)
/*  f05a390:	910d0006 */ 	lbu	$t5,0x6($t0)
/*  f05a394:	55a00008 */ 	bnezl	$t5,.L0f05a3b8
/*  f05a398:	90e40125 */ 	lbu	$a0,0x125($a3)
/*  f05a39c:	ace00120 */ 	sw	$zero,0x120($a3)
/*  f05a3a0:	8e0e0438 */ 	lw	$t6,0x438($s0)
/*  f05a3a4:	00001025 */ 	or	$v0,$zero,$zero
/*  f05a3a8:	25cf000a */ 	addiu	$t7,$t6,0xa
/*  f05a3ac:	10000206 */ 	beqz	$zero,.L0f05abc8
/*  f05a3b0:	ae0f0438 */ 	sw	$t7,0x438($s0)
/*  f05a3b4:	90e40125 */ 	lbu	$a0,0x125($a3)
.L0f05a3b8:
/*  f05a3b8:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f05a3bc:	0fc13380 */ 	jal	teamGetChrIds
/*  f05a3c0:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f05a3c4:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f05a3c8:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f05a3cc:	afa00098 */ 	sw	$zero,0x98($sp)
/*  f05a3d0:	afa00094 */ 	sw	$zero,0x94($sp)
/*  f05a3d4:	93190004 */ 	lbu	$t9,0x4($t8)
/*  f05a3d8:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f05a3dc:	24010005 */ 	addiu	$at,$zero,0x5
/*  f05a3e0:	afb90090 */ 	sw	$t9,0x90($sp)
/*  f05a3e4:	80e30006 */ 	lb	$v1,0x6($a3)
/*  f05a3e8:	8fa5007c */ 	lw	$a1,0x7c($sp)
/*  f05a3ec:	8fa90084 */ 	lw	$t1,0x84($sp)
/*  f05a3f0:	10610007 */ 	beq	$v1,$at,.L0f05a410
/*  f05a3f4:	3c0a8007 */ 	lui	$t2,%hi(g_SpecialQuipBank)
/*  f05a3f8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f05a3fc:	10610004 */ 	beq	$v1,$at,.L0f05a410
/*  f05a400:	2401003a */ 	addiu	$at,$zero,0x3a
/*  f05a404:	10610002 */ 	beq	$v1,$at,.L0f05a410
/*  f05a408:	24010028 */ 	addiu	$at,$zero,0x28
/*  f05a40c:	14610004 */ 	bne	$v1,$at,.L0f05a420
.L0f05a410:
/*  f05a410:	254a9518 */ 	addiu	$t2,$t2,%lo(g_SpecialQuipBank)
/*  f05a414:	112a0002 */ 	beq	$t1,$t2,.L0f05a420
/*  f05a418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a41c:	afa00090 */ 	sw	$zero,0x90($sp)
.L0f05a420:
/*  f05a420:	50a0001c */ 	beqzl	$a1,.L0f05a494
/*  f05a424:	90e20126 */ 	lbu	$v0,0x126($a3)
/*  f05a428:	8ca4001c */ 	lw	$a0,0x1c($a1)
/*  f05a42c:	50800019 */ 	beqzl	$a0,.L0f05a494
/*  f05a430:	90e20126 */ 	lbu	$v0,0x126($a3)
/*  f05a434:	908b0000 */ 	lbu	$t3,0x0($a0)
/*  f05a438:	24010006 */ 	addiu	$at,$zero,0x6
/*  f05a43c:	55610015 */ 	bnel	$t3,$at,.L0f05a494
/*  f05a440:	90e20126 */ 	lbu	$v0,0x126($a3)
/*  f05a444:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f05a448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a44c:	8e030298 */ 	lw	$v1,0x298($s0)
/*  f05a450:	00026080 */ 	sll	$t4,$v0,0x2
/*  f05a454:	00402025 */ 	or	$a0,$v0,$zero
/*  f05a458:	0460000a */ 	bltz	$v1,.L0f05a484
/*  f05a45c:	020c6821 */ 	addu	$t5,$s0,$t4
/*  f05a460:	8dae0064 */ 	lw	$t6,0x64($t5)
/*  f05a464:	8dcf00d8 */ 	lw	$t7,0xd8($t6)
/*  f05a468:	11e00006 */ 	beqz	$t7,.L0f05a484
/*  f05a46c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a470:	8e050294 */ 	lw	$a1,0x294($s0)
/*  f05a474:	14450003 */ 	bne	$v0,$a1,.L0f05a484
/*  f05a478:	00a02025 */ 	or	$a0,$a1,$zero
/*  f05a47c:	10000001 */ 	beqz	$zero,.L0f05a484
/*  f05a480:	00602025 */ 	or	$a0,$v1,$zero
.L0f05a484:
/*  f05a484:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f05a488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a48c:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f05a490:	90e20126 */ 	lbu	$v0,0x126($a3)
.L0f05a494:
/*  f05a494:	10400007 */ 	beqz	$v0,.L0f05a4b4
/*  f05a498:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f05a49c:	8cf90120 */ 	lw	$t9,0x120($a3)
/*  f05a4a0:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f05a4a4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f05a4a8:	0319082a */ 	slt	$at,$t8,$t9
/*  f05a4ac:	102001c0 */ 	beqz	$at,.L0f05abb0
/*  f05a4b0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f05a4b4:
/*  f05a4b4:	0c004b70 */ 	jal	random
/*  f05a4b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a4bc:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f05a4c0:	304900ff */ 	andi	$t1,$v0,0xff
/*  f05a4c4:	8fab0088 */ 	lw	$t3,0x88($sp)
/*  f05a4c8:	012a082a */ 	slt	$at,$t1,$t2
/*  f05a4cc:	102001b8 */ 	beqz	$at,.L0f05abb0
/*  f05a4d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a4d4:	85640000 */ 	lh	$a0,0x0($t3)
/*  f05a4d8:	2401fffe */ 	addiu	$at,$zero,-2
/*  f05a4dc:	5081003e */ 	beql	$a0,$at,.L0f05a5d8
/*  f05a4e0:	8fae0094 */ 	lw	$t6,0x94($sp)
.L0f05a4e4:
/*  f05a4e4:	0fc0a1dd */ 	jal	chrFindByLiteralId
/*  f05a4e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a4ec:	50400033 */ 	beqzl	$v0,.L0f05a5bc
/*  f05a4f0:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f05a4f4:	8c4c0020 */ 	lw	$t4,0x20($v0)
/*  f05a4f8:	00402025 */ 	or	$a0,$v0,$zero
/*  f05a4fc:	5180002f */ 	beqzl	$t4,.L0f05a5bc
/*  f05a500:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f05a504:	0fc0e6a5 */ 	jal	chrIsDead
/*  f05a508:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f05a50c:	1440002a */ 	bnez	$v0,.L0f05a5b8
/*  f05a510:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f05a514:	80cd0007 */ 	lb	$t5,0x7($a2)
/*  f05a518:	24010005 */ 	addiu	$at,$zero,0x5
/*  f05a51c:	51a10027 */ 	beql	$t5,$at,.L0f05a5bc
/*  f05a520:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f05a524:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f05a528:	90ce02a2 */ 	lbu	$t6,0x2a2($a2)
/*  f05a52c:	90ef02a2 */ 	lbu	$t7,0x2a2($a3)
/*  f05a530:	55cf0022 */ 	bnel	$t6,$t7,.L0f05a5bc
/*  f05a534:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f05a538:	90d80113 */ 	lbu	$t8,0x113($a2)
/*  f05a53c:	2b010064 */ 	slti	$at,$t8,0x64
/*  f05a540:	5420001e */ 	bnezl	$at,.L0f05a5bc
/*  f05a544:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f05a548:	84c50000 */ 	lh	$a1,0x0($a2)
/*  f05a54c:	84f90000 */ 	lh	$t9,0x0($a3)
/*  f05a550:	00e02025 */ 	or	$a0,$a3,$zero
/*  f05a554:	50b90019 */ 	beql	$a1,$t9,.L0f05a5bc
/*  f05a558:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f05a55c:	0fc1272c */ 	jal	chrGetDistanceToChr
/*  f05a560:	afa60064 */ 	sw	$a2,0x64($sp)
/*  f05a564:	3c017f1b */ 	lui	$at,%hi(var7f1a9d64)
/*  f05a568:	c4249d64 */ 	lwc1	$f4,%lo(var7f1a9d64)($at)
/*  f05a56c:	8fa90098 */ 	lw	$t1,0x98($sp)
/*  f05a570:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f05a574:	4604003c */ 	c.lt.s	$f0,$f4
/*  f05a578:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f05a57c:	4502000f */ 	bc1fl	.L0f05a5bc
/*  f05a580:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f05a584:	afaa0098 */ 	sw	$t2,0x98($sp)
/*  f05a588:	8ccb0120 */ 	lw	$t3,0x120($a2)
/*  f05a58c:	8fac009c */ 	lw	$t4,0x9c($sp)
/*  f05a590:	2961003c */ 	slti	$at,$t3,0x3c
/*  f05a594:	50200009 */ 	beqzl	$at,.L0f05a5bc
/*  f05a598:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f05a59c:	91820006 */ 	lbu	$v0,0x6($t4)
/*  f05a5a0:	240100ff */ 	addiu	$at,$zero,0xff
/*  f05a5a4:	50400005 */ 	beqzl	$v0,.L0f05a5bc
/*  f05a5a8:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f05a5ac:	10410002 */ 	beq	$v0,$at,.L0f05a5b8
/*  f05a5b0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f05a5b4:	afad0094 */ 	sw	$t5,0x94($sp)
.L0f05a5b8:
/*  f05a5b8:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f05a5bc:
/*  f05a5bc:	2401fffe */ 	addiu	$at,$zero,-2
/*  f05a5c0:	84440002 */ 	lh	$a0,0x2($v0)
/*  f05a5c4:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f05a5c8:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f05a5cc:	1481ffc5 */ 	bne	$a0,$at,.L0f05a4e4
/*  f05a5d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a5d4:	8fae0094 */ 	lw	$t6,0x94($sp)
.L0f05a5d8:
/*  f05a5d8:	8faf0098 */ 	lw	$t7,0x98($sp)
/*  f05a5dc:	15c00174 */ 	bnez	$t6,.L0f05abb0
/*  f05a5e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a5e4:	15e00007 */ 	bnez	$t7,.L0f05a604
/*  f05a5e8:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f05a5ec:	93020006 */ 	lbu	$v0,0x6($t8)
/*  f05a5f0:	240100ff */ 	addiu	$at,$zero,0xff
/*  f05a5f4:	1040000a */ 	beqz	$v0,.L0f05a620
/*  f05a5f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a5fc:	10410008 */ 	beq	$v0,$at,.L0f05a620
/*  f05a600:	00000000 */ 	sll	$zero,$zero,0x0
.L0f05a604:
/*  f05a604:	8fb90098 */ 	lw	$t9,0x98($sp)
/*  f05a608:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*  f05a60c:	1b200168 */ 	blez	$t9,.L0f05abb0
/*  f05a610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a614:	912a0006 */ 	lbu	$t2,0x6($t1)
/*  f05a618:	19400165 */ 	blez	$t2,.L0f05abb0
/*  f05a61c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f05a620:
/*  f05a620:	0c004b70 */ 	jal	random
/*  f05a624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a628:	24010003 */ 	addiu	$at,$zero,0x3
/*  f05a62c:	0041001b */ 	divu	$zero,$v0,$at
/*  f05a630:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f05a634:	00001810 */ 	mfhi	$v1
/*  f05a638:	a3a300a7 */ 	sb	$v1,0xa7($sp)
/*  f05a63c:	916c0007 */ 	lbu	$t4,0x7($t3)
/*  f05a640:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f05a644:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f05a648:	318d0080 */ 	andi	$t5,$t4,0x80
/*  f05a64c:	15a00009 */ 	bnez	$t5,.L0f05a674
/*  f05a650:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f05a654:	01d94821 */ 	addu	$t1,$t6,$t9
/*  f05a658:	306a00ff */ 	andi	$t2,$v1,0xff
/*  f05a65c:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f05a660:	012b6021 */ 	addu	$t4,$t1,$t3
/*  f05a664:	afa90058 */ 	sw	$t1,0x58($sp)
/*  f05a668:	858d0002 */ 	lh	$t5,0x2($t4)
/*  f05a66c:	1000000c */ 	beqz	$zero,.L0f05a6a0
/*  f05a670:	a7ad00a4 */ 	sh	$t5,0xa4($sp)
.L0f05a674:
/*  f05a674:	8e0a0424 */ 	lw	$t2,0x424($s0)
/*  f05a678:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f05a67c:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f05a680:	914902b0 */ 	lbu	$t1,0x2b0($t2)
/*  f05a684:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*  f05a688:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f05a68c:	00095840 */ 	sll	$t3,$t1,0x1
/*  f05a690:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f05a694:	858d0002 */ 	lh	$t5,0x2($t4)
/*  f05a698:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f05a69c:	a7ad00a4 */ 	sh	$t5,0xa4($sp)
.L0f05a6a0:
/*  f05a6a0:	0fc133cd */ 	jal	audioWasNotPlayedRecently
/*  f05a6a4:	87a400a4 */ 	lh	$a0,0xa4($sp)
/*  f05a6a8:	1440000a */ 	bnez	$v0,.L0f05a6d4
/*  f05a6ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f05a6b0:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f05a6b4:	00001825 */ 	or	$v1,$zero,$zero
/*  f05a6b8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f05a6bc:	10e00003 */ 	beqz	$a3,.L0f05a6cc
/*  f05a6c0:	3c0e8007 */ 	lui	$t6,%hi(g_GuardQuipBank)
/*  f05a6c4:	10000001 */ 	beqz	$zero,.L0f05a6cc
/*  f05a6c8:	90e302fe */ 	lbu	$v1,0x2fe($a3)
.L0f05a6cc:
/*  f05a6cc:	54610092 */ 	bnel	$v1,$at,.L0f05a918
/*  f05a6d0:	8fad0070 */ 	lw	$t5,0x70($sp)
.L0f05a6d4:
/*  f05a6d4:	0fc133bb */ 	jal	audioMarkAsRecentlyPlayed
/*  f05a6d8:	87a400a4 */ 	lh	$a0,0xa4($sp)
/*  f05a6dc:	87b800a4 */ 	lh	$t8,0xa4($sp)
/*  f05a6e0:	2401034e */ 	addiu	$at,$zero,0x34e
/*  f05a6e4:	93ae006b */ 	lbu	$t6,0x6b($sp)
/*  f05a6e8:	57010005 */ 	bnel	$t8,$at,.L0f05a700
/*  f05a6ec:	8e190424 */ 	lw	$t9,0x424($s0)
/*  f05a6f0:	15c00002 */ 	bnez	$t6,.L0f05a6fc
/*  f05a6f4:	240f034d */ 	addiu	$t7,$zero,0x34d
/*  f05a6f8:	a7af00a4 */ 	sh	$t7,0xa4($sp)
.L0f05a6fc:
/*  f05a6fc:	8e190424 */ 	lw	$t9,0x424($s0)
.L0f05a700:
/*  f05a700:	240103f7 */ 	addiu	$at,$zero,0x3f7
/*  f05a704:	af200120 */ 	sw	$zero,0x120($t9)
/*  f05a708:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f05a70c:	8e0b0424 */ 	lw	$t3,0x424($s0)
/*  f05a710:	91490005 */ 	lbu	$t1,0x5($t2)
/*  f05a714:	a1690126 */ 	sb	$t1,0x126($t3)
/*  f05a718:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f05a71c:	90ec0332 */ 	lbu	$t4,0x332($a3)
/*  f05a720:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f05a724:	a0ed0332 */ 	sb	$t5,0x332($a3)
/*  f05a728:	87b800a4 */ 	lh	$t8,0xa4($sp)
/*  f05a72c:	13010022 */ 	beq	$t8,$at,.L0f05a7b8
/*  f05a730:	24010331 */ 	addiu	$at,$zero,0x331
/*  f05a734:	13010020 */ 	beq	$t8,$at,.L0f05a7b8
/*  f05a738:	240103a1 */ 	addiu	$at,$zero,0x3a1
/*  f05a73c:	1301001e */ 	beq	$t8,$at,.L0f05a7b8
/*  f05a740:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f05a744:	8e0e0424 */ 	lw	$t6,0x424($s0)
/*  f05a748:	3406ffff */ 	dli	$a2,0xffff
/*  f05a74c:	0fc249af */ 	jal	func0f0926bc
/*  f05a750:	8dc4001c */ 	lw	$a0,0x1c($t6)
/*  f05a754:	8e0f0424 */ 	lw	$t7,0x424($s0)
/*  f05a758:	3c01bf80 */ 	lui	$at,0xbf80
/*  f05a75c:	44810000 */ 	mtc1	$at,$f0
/*  f05a760:	8de5001c */ 	lw	$a1,0x1c($t7)
/*  f05a764:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f05a768:	240a0008 */ 	addiu	$t2,$zero,0x8
/*  f05a76c:	24090009 */ 	addiu	$t1,$zero,0x9
/*  f05a770:	240bffff */ 	addiu	$t3,$zero,-1
/*  f05a774:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f05a778:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f05a77c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f05a780:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f05a784:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f05a788:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f05a78c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f05a790:	00002025 */ 	or	$a0,$zero,$zero
/*  f05a794:	87a600a4 */ 	lh	$a2,0xa4($sp)
/*  f05a798:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f05a79c:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f05a7a0:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f05a7a4:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f05a7a8:	0fc24e7e */ 	jal	func0f0939f8
/*  f05a7ac:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f05a7b0:	10000026 */ 	beqz	$zero,.L0f05a84c
/*  f05a7b4:	8faa009c */ 	lw	$t2,0x9c($sp)
.L0f05a7b8:
/*  f05a7b8:	0fc13160 */ 	jal	chrGetDistanceLostToTargetInLastSecond
/*  f05a7bc:	8e040424 */ 	lw	$a0,0x424($s0)
/*  f05a7c0:	18400003 */ 	blez	$v0,.L0f05a7d0
/*  f05a7c4:	00021823 */ 	negu	$v1,$v0
/*  f05a7c8:	10000001 */ 	beqz	$zero,.L0f05a7d0
/*  f05a7cc:	00401825 */ 	or	$v1,$v0,$zero
.L0f05a7d0:
/*  f05a7d0:	28610033 */ 	slti	$at,$v1,0x33
/*  f05a7d4:	1420001c */ 	bnez	$at,.L0f05a848
/*  f05a7d8:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f05a7dc:	8e0c0424 */ 	lw	$t4,0x424($s0)
/*  f05a7e0:	3406ffff */ 	dli	$a2,0xffff
/*  f05a7e4:	0fc249af */ 	jal	func0f0926bc
/*  f05a7e8:	8d84001c */ 	lw	$a0,0x1c($t4)
/*  f05a7ec:	8e0d0424 */ 	lw	$t5,0x424($s0)
/*  f05a7f0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f05a7f4:	44810000 */ 	mtc1	$at,$f0
/*  f05a7f8:	8da5001c */ 	lw	$a1,0x1c($t5)
/*  f05a7fc:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f05a800:	240e0008 */ 	addiu	$t6,$zero,0x8
/*  f05a804:	240f0009 */ 	addiu	$t7,$zero,0x9
/*  f05a808:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f05a80c:	afb9002c */ 	sw	$t9,0x2c($sp)
/*  f05a810:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f05a814:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f05a818:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f05a81c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f05a820:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f05a824:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f05a828:	00002025 */ 	or	$a0,$zero,$zero
/*  f05a82c:	87a600a4 */ 	lh	$a2,0xa4($sp)
/*  f05a830:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f05a834:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f05a838:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f05a83c:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f05a840:	0fc24e7e */ 	jal	func0f0939f8
/*  f05a844:	e7a00024 */ 	swc1	$f0,0x24($sp)
.L0f05a848:
/*  f05a848:	8faa009c */ 	lw	$t2,0x9c($sp)
.L0f05a84c:
/*  f05a84c:	91420008 */ 	lbu	$v0,0x8($t2)
/*  f05a850:	1040001a */ 	beqz	$v0,.L0f05a8bc
/*  f05a854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a858:	91490007 */ 	lbu	$t1,0x7($t2)
/*  f05a85c:	93a300a7 */ 	lbu	$v1,0xa7($sp)
/*  f05a860:	000260c0 */ 	sll	$t4,$v0,0x3
/*  f05a864:	312b0080 */ 	andi	$t3,$t1,0x80
/*  f05a868:	15600014 */ 	bnez	$t3,.L0f05a8bc
/*  f05a86c:	28610003 */ 	slti	$at,$v1,0x3
/*  f05a870:	14200002 */ 	bnez	$at,.L0f05a87c
/*  f05a874:	3c048007 */ 	lui	$a0,%hi(g_SpecialQuipBank+0x16a)
/*  f05a878:	24030002 */ 	addiu	$v1,$zero,0x2
.L0f05a87c:
/*  f05a87c:	00036840 */ 	sll	$t5,$v1,0x1
/*  f05a880:	018dc021 */ 	addu	$t8,$t4,$t5
/*  f05a884:	00982021 */ 	addu	$a0,$a0,$t8
/*  f05a888:	0fc5b9f1 */ 	jal	langGet
/*  f05a88c:	84849682 */ 	lh	$a0,%lo(g_SpecialQuipBank+0x16a)($a0)
/*  f05a890:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f05a894:	0c004103 */ 	jal	audioIsFiltered
/*  f05a898:	87a400a4 */ 	lh	$a0,0xa4($sp)
/*  f05a89c:	144000c4 */ 	bnez	$v0,.L0f05abb0
/*  f05a8a0:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f05a8a4:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f05a8a8:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f05a8ac:	0fc3780d */ 	jal	hudmsgCreateViaPresetWithColour
/*  f05a8b0:	91c60009 */ 	lbu	$a2,0x9($t6)
/*  f05a8b4:	100000be */ 	beqz	$zero,.L0f05abb0
/*  f05a8b8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f05a8bc:
/*  f05a8bc:	104000bc */ 	beqz	$v0,.L0f05abb0
/*  f05a8c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a8c4:	8e190424 */ 	lw	$t9,0x424($s0)
/*  f05a8c8:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f05a8cc:	3c048007 */ 	lui	$a0,%hi(g_SpecialQuipBank+0x16a)
/*  f05a8d0:	932a02b0 */ 	lbu	$t2,0x2b0($t9)
/*  f05a8d4:	000a4840 */ 	sll	$t1,$t2,0x1
/*  f05a8d8:	01e95821 */ 	addu	$t3,$t7,$t1
/*  f05a8dc:	008b2021 */ 	addu	$a0,$a0,$t3
/*  f05a8e0:	0fc5b9f1 */ 	jal	langGet
/*  f05a8e4:	84849682 */ 	lh	$a0,%lo(g_SpecialQuipBank+0x16a)($a0)
/*  f05a8e8:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f05a8ec:	0c004103 */ 	jal	audioIsFiltered
/*  f05a8f0:	87a400a4 */ 	lh	$a0,0xa4($sp)
/*  f05a8f4:	144000ae */ 	bnez	$v0,.L0f05abb0
/*  f05a8f8:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f05a8fc:	8fac009c */ 	lw	$t4,0x9c($sp)
/*  f05a900:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f05a904:	0fc3780d */ 	jal	hudmsgCreateViaPresetWithColour
/*  f05a908:	91860009 */ 	lbu	$a2,0x9($t4)
/*  f05a90c:	100000a8 */ 	beqz	$zero,.L0f05abb0
/*  f05a910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05a914:	8fad0070 */ 	lw	$t5,0x70($sp)
.L0f05a918:
/*  f05a918:	25ce8ff8 */ 	addiu	$t6,$t6,%lo(g_GuardQuipBank)
/*  f05a91c:	a7a000a4 */ 	sh	$zero,0xa4($sp)
/*  f05a920:	000dc0c0 */ 	sll	$t8,$t5,0x3
/*  f05a924:	030e1021 */ 	addu	$v0,$t8,$t6
/*  f05a928:	afa2005c */ 	sw	$v0,0x5c($sp)
.L0f05a92c:
/*  f05a92c:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f05a930:	00081840 */ 	sll	$v1,$t0,0x1
/*  f05a934:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f05a938:	87240000 */ 	lh	$a0,0x0($t9)
/*  f05a93c:	a3a800a3 */ 	sb	$t0,0xa3($sp)
/*  f05a940:	0fc133cd */ 	jal	audioWasNotPlayedRecently
/*  f05a944:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f05a948:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f05a94c:	1040000d */ 	beqz	$v0,.L0f05a984
/*  f05a950:	93a800a3 */ 	lbu	$t0,0xa3($sp)
/*  f05a954:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f05a958:	01432821 */ 	addu	$a1,$t2,$v1
/*  f05a95c:	84a40000 */ 	lh	$a0,0x0($a1)
/*  f05a960:	a3a800a3 */ 	sb	$t0,0xa3($sp)
/*  f05a964:	0fc133cd */ 	jal	audioWasNotPlayedRecently
/*  f05a968:	afa50050 */ 	sw	$a1,0x50($sp)
/*  f05a96c:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f05a970:	10400004 */ 	beqz	$v0,.L0f05a984
/*  f05a974:	93a800a3 */ 	lbu	$t0,0xa3($sp)
/*  f05a978:	84af0000 */ 	lh	$t7,0x0($a1)
/*  f05a97c:	10000006 */ 	beqz	$zero,.L0f05a998
/*  f05a980:	a7af00a4 */ 	sh	$t7,0xa4($sp)
.L0f05a984:
/*  f05a984:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f05a988:	310900ff */ 	andi	$t1,$t0,0xff
/*  f05a98c:	29210004 */ 	slti	$at,$t1,0x4
/*  f05a990:	1420ffe6 */ 	bnez	$at,.L0f05a92c
/*  f05a994:	01204025 */ 	or	$t0,$t1,$zero
.L0f05a998:
/*  f05a998:	87ab00a4 */ 	lh	$t3,0xa4($sp)
/*  f05a99c:	1160007a */ 	beqz	$t3,.L0f05ab88
/*  f05a9a0:	01602025 */ 	or	$a0,$t3,$zero
/*  f05a9a4:	0fc133bb */ 	jal	audioMarkAsRecentlyPlayed
/*  f05a9a8:	a3a800a3 */ 	sb	$t0,0xa3($sp)
/*  f05a9ac:	87ac00a4 */ 	lh	$t4,0xa4($sp)
/*  f05a9b0:	2401034e */ 	addiu	$at,$zero,0x34e
/*  f05a9b4:	93a800a3 */ 	lbu	$t0,0xa3($sp)
/*  f05a9b8:	15810004 */ 	bne	$t4,$at,.L0f05a9cc
/*  f05a9bc:	93ad006b */ 	lbu	$t5,0x6b($sp)
/*  f05a9c0:	15a00002 */ 	bnez	$t5,.L0f05a9cc
/*  f05a9c4:	2418034d */ 	addiu	$t8,$zero,0x34d
/*  f05a9c8:	a7b800a4 */ 	sh	$t8,0xa4($sp)
.L0f05a9cc:
/*  f05a9cc:	8e0e0424 */ 	lw	$t6,0x424($s0)
/*  f05a9d0:	240103f7 */ 	addiu	$at,$zero,0x3f7
/*  f05a9d4:	adc00120 */ 	sw	$zero,0x120($t6)
/*  f05a9d8:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f05a9dc:	8e0f0424 */ 	lw	$t7,0x424($s0)
/*  f05a9e0:	932a0005 */ 	lbu	$t2,0x5($t9)
/*  f05a9e4:	a1ea0126 */ 	sb	$t2,0x126($t7)
/*  f05a9e8:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f05a9ec:	90e90332 */ 	lbu	$t1,0x332($a3)
/*  f05a9f0:	252b0001 */ 	addiu	$t3,$t1,0x1
/*  f05a9f4:	a0eb0332 */ 	sb	$t3,0x332($a3)
/*  f05a9f8:	87ac00a4 */ 	lh	$t4,0xa4($sp)
/*  f05a9fc:	11810024 */ 	beq	$t4,$at,.L0f05aa90
/*  f05aa00:	24010331 */ 	addiu	$at,$zero,0x331
/*  f05aa04:	11810022 */ 	beq	$t4,$at,.L0f05aa90
/*  f05aa08:	240103a1 */ 	addiu	$at,$zero,0x3a1
/*  f05aa0c:	51810021 */ 	beql	$t4,$at,.L0f05aa94
/*  f05aa10:	8e040424 */ 	lw	$a0,0x424($s0)
/*  f05aa14:	8e0d0424 */ 	lw	$t5,0x424($s0)
/*  f05aa18:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f05aa1c:	3406ffff */ 	dli	$a2,0xffff
/*  f05aa20:	8da4001c */ 	lw	$a0,0x1c($t5)
/*  f05aa24:	0fc249af */ 	jal	func0f0926bc
/*  f05aa28:	a3a800a3 */ 	sb	$t0,0xa3($sp)
/*  f05aa2c:	8e180424 */ 	lw	$t8,0x424($s0)
/*  f05aa30:	3c01bf80 */ 	lui	$at,0xbf80
/*  f05aa34:	44810000 */ 	mtc1	$at,$f0
/*  f05aa38:	8f05001c */ 	lw	$a1,0x1c($t8)
/*  f05aa3c:	240effff */ 	addiu	$t6,$zero,-1
/*  f05aa40:	24190008 */ 	addiu	$t9,$zero,0x8
/*  f05aa44:	240a0009 */ 	addiu	$t2,$zero,0x9
/*  f05aa48:	240fffff */ 	addiu	$t7,$zero,-1
/*  f05aa4c:	afaf002c */ 	sw	$t7,0x2c($sp)
/*  f05aa50:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f05aa54:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f05aa58:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f05aa5c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f05aa60:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f05aa64:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f05aa68:	00002025 */ 	or	$a0,$zero,$zero
/*  f05aa6c:	87a600a4 */ 	lh	$a2,0xa4($sp)
/*  f05aa70:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f05aa74:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f05aa78:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f05aa7c:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f05aa80:	0fc24e7e */ 	jal	func0f0939f8
/*  f05aa84:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f05aa88:	1000002a */ 	beqz	$zero,.L0f05ab34
/*  f05aa8c:	93a800a3 */ 	lbu	$t0,0xa3($sp)
.L0f05aa90:
/*  f05aa90:	8e040424 */ 	lw	$a0,0x424($s0)
.L0f05aa94:
/*  f05aa94:	0fc13160 */ 	jal	chrGetDistanceLostToTargetInLastSecond
/*  f05aa98:	a3a800a3 */ 	sb	$t0,0xa3($sp)
/*  f05aa9c:	18400003 */ 	blez	$v0,.L0f05aaac
/*  f05aaa0:	93a800a3 */ 	lbu	$t0,0xa3($sp)
/*  f05aaa4:	10000002 */ 	beqz	$zero,.L0f05aab0
/*  f05aaa8:	00401825 */ 	or	$v1,$v0,$zero
.L0f05aaac:
/*  f05aaac:	00021823 */ 	negu	$v1,$v0
.L0f05aab0:
/*  f05aab0:	28610033 */ 	slti	$at,$v1,0x33
/*  f05aab4:	54200020 */ 	bnezl	$at,.L0f05ab38
/*  f05aab8:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f05aabc:	8e090424 */ 	lw	$t1,0x424($s0)
/*  f05aac0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f05aac4:	3406ffff */ 	dli	$a2,0xffff
/*  f05aac8:	8d24001c */ 	lw	$a0,0x1c($t1)
/*  f05aacc:	0fc249af */ 	jal	func0f0926bc
/*  f05aad0:	a3a800a3 */ 	sb	$t0,0xa3($sp)
/*  f05aad4:	8e0b0424 */ 	lw	$t3,0x424($s0)
/*  f05aad8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f05aadc:	44810000 */ 	mtc1	$at,$f0
/*  f05aae0:	8d65001c */ 	lw	$a1,0x1c($t3)
/*  f05aae4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f05aae8:	240d0008 */ 	addiu	$t5,$zero,0x8
/*  f05aaec:	24180009 */ 	addiu	$t8,$zero,0x9
/*  f05aaf0:	240effff */ 	addiu	$t6,$zero,-1
/*  f05aaf4:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f05aaf8:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f05aafc:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f05ab00:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f05ab04:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f05ab08:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f05ab0c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f05ab10:	00002025 */ 	or	$a0,$zero,$zero
/*  f05ab14:	87a600a4 */ 	lh	$a2,0xa4($sp)
/*  f05ab18:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f05ab1c:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f05ab20:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f05ab24:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f05ab28:	0fc24e7e */ 	jal	func0f0939f8
/*  f05ab2c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f05ab30:	93a800a3 */ 	lbu	$t0,0xa3($sp)
.L0f05ab34:
/*  f05ab34:	8fb9009c */ 	lw	$t9,0x9c($sp)
.L0f05ab38:
/*  f05ab38:	00087840 */ 	sll	$t7,$t0,0x1
/*  f05ab3c:	3c048007 */ 	lui	$a0,%hi(g_SpecialQuipBank+0x168)
/*  f05ab40:	93220008 */ 	lbu	$v0,0x8($t9)
/*  f05ab44:	1040001a */ 	beqz	$v0,.L0f05abb0
/*  f05ab48:	000250c0 */ 	sll	$t2,$v0,0x3
/*  f05ab4c:	014f4821 */ 	addu	$t1,$t2,$t7
/*  f05ab50:	00892021 */ 	addu	$a0,$a0,$t1
/*  f05ab54:	0fc5b9f1 */ 	jal	langGet
/*  f05ab58:	84849680 */ 	lh	$a0,%lo(g_SpecialQuipBank+0x168)($a0)
/*  f05ab5c:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f05ab60:	0c004103 */ 	jal	audioIsFiltered
/*  f05ab64:	87a400a4 */ 	lh	$a0,0xa4($sp)
/*  f05ab68:	14400011 */ 	bnez	$v0,.L0f05abb0
/*  f05ab6c:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f05ab70:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f05ab74:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f05ab78:	0fc3780d */ 	jal	hudmsgCreateViaPresetWithColour
/*  f05ab7c:	91660009 */ 	lbu	$a2,0x9($t3)
/*  f05ab80:	1000000b */ 	beqz	$zero,.L0f05abb0
/*  f05ab84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f05ab88:
/*  f05ab88:	8e0c0424 */ 	lw	$t4,0x424($s0)
/*  f05ab8c:	3c050800 */ 	lui	$a1,0x800
/*  f05ab90:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f05ab94:	ad800120 */ 	sw	$zero,0x120($t4)
/*  f05ab98:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f05ab9c:	8e0e0424 */ 	lw	$t6,0x424($s0)
/*  f05aba0:	91b80005 */ 	lbu	$t8,0x5($t5)
/*  f05aba4:	a1d80126 */ 	sb	$t8,0x126($t6)
/*  f05aba8:	0fc12782 */ 	jal	chrUnsetFlags
/*  f05abac:	8e040424 */ 	lw	$a0,0x424($s0)
.L0f05abb0:
/*  f05abb0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f05abb4:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f05abb8:	8e190438 */ 	lw	$t9,0x438($s0)
/*  f05abbc:	00001025 */ 	or	$v0,$zero,$zero
/*  f05abc0:	272a000a */ 	addiu	$t2,$t9,0xa
/*  f05abc4:	ae0a0438 */ 	sw	$t2,0x438($s0)
.L0f05abc8:
/*  f05abc8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f05abcc:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f05abd0:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f05abd4:	03e00008 */ 	jr	$ra
/*  f05abd8:	00000000 */ 	sll	$zero,$zero,0x0
);

// regalloc difference near 64c
//bool aiSayQuip(void)
//{
//	u8 column; // 167
//	s16 audioid; // 164
//	u8 i; // 163
//	u8 *cmd = g_Vars.ailist + g_Vars.aioffset; // 156
//	s32 numnearbychrs; // 152
//	bool issomeonetalking; // 148
//	s32 probability; // 144
//	u32 stack; // 140 - not referenced
//	s16 *chrnums; // 136
//	s16 (*bank)[4]; // 132
//	char *text; // 128
//	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]); // 124
//	u32 prevplayernum = g_Vars.currentplayernum; // 120
//	s32 distance; // 116 - not referenced
//	s32 row = cmd[3]; // 112
//	u32 playernum; // 108 - not referenced
//	u8 headshotted = g_Vars.chrdata->hidden2 & CHRH2FLAG_HEADSHOTTED; // 107
//	struct chrdata *loopchr; // 100
//
//	// Choose bank
//	// 2c0
//	if (CHRRACE(g_Vars.chrdata) == RACE_SKEDAR) {
//		bank = g_SkedarQuipBank;
//
//		if (row > 5) {
//			row = 0;
//		}
//		// 2e0
//	} else if (g_Vars.chrdata->headnum == HEAD_MAIAN_S) {
//		bank = g_MaianQuipBank;
//
//		if (row > 2) {
//			row = random() & 1;
//		}
//		// 324
//	} else if (cmd[7] == 0) {
//		if (g_Vars.chrdata->voicebox > 3) {
//			g_Vars.chrdata->voicebox = 3;
//		}
//
//		bank = &g_GuardQuipBank[g_Vars.chrdata->voicebox * 41];
//	} else {
//		// 37c
//		bank = g_SpecialQuipBank;
//	}
//
//	// 37c
//	if (!row && !cmd[4] && !cmd[6]) {
//		g_Vars.chrdata->soundtimer = 0;
//		g_Vars.aioffset += 10;
//		return false;
//	}
//
//	// 3bc
//	chrnums = teamGetChrIds(g_Vars.chrdata->team);
//	numnearbychrs = 0;
//	issomeonetalking = false;
//	probability = cmd[4];
//
//	// Make it impossible for Elvis and Jon to use anything but special phrases
//	// 3f0
//	if ((g_Vars.chrdata->headnum == HEAD_ELVIS
//				|| g_Vars.chrdata->headnum == HEAD_THEKING
//				|| g_Vars.chrdata->headnum == HEAD_ELVIS_GOGS
//				|| g_Vars.chrdata->headnum == HEAD_JONATHAN) &&
//			bank != g_SpecialQuipBank) {
//		probability = 0;
//	}
//
//	// If the person talking is a player, and they've just died,
//	// try using the other coop player.
//	// 420
//	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
//		// 444
//		playernum = propGetPlayerNum(chr->prop);
//
//		if (g_Vars.coopplayernum >= 0 && g_Vars.players[playernum]->isdead) {
//			// 470
//			if (playernum == g_Vars.bondplayernum) {
//				playernum = g_Vars.coopplayernum;
//			} else {
//				playernum = g_Vars.bondplayernum;
//			}
//		}
//
//		setCurrentPlayerNum(playernum);
//	}
//
//	// If soundgap permits talking at this time and probability passes
//	// 494
//	if ((g_Vars.chrdata->soundgap == 0 || g_Vars.chrdata->soundgap * 60 < g_Vars.chrdata->soundtimer)
//			&& probability > (u8)random()) {
//		// Try and find a chr in the same squadron who is currently talking
//		// 4dc
//		while (*chrnums != -2) {
//			loopchr = chrFindByLiteralId(*chrnums);
//
//			if (loopchr && loopchr->animdata
//					&& !chrIsDead(loopchr)
//					&& loopchr->actiontype != ACT_DEAD
//					&& g_Vars.chrdata->squadron == loopchr->squadron
//					&& loopchr->alertness >= 100
//					&& g_Vars.chrdata->chrnum != loopchr->chrnum
//					&& chrGetDistanceToChr(g_Vars.chrdata, loopchr->chrnum) < 7000) {
//				// 584
//				numnearbychrs++;
//
//				// 594
//				if (loopchr->soundtimer < 60 && cmd[6] != 0 && cmd[6] != 255) {
//					issomeonetalking = true;
//				}
//			}
//
//			chrnums++;
//		}
//
//		// 5dc
//		if (!issomeonetalking &&
//				((numnearbychrs == 0 && (cmd[6] == 0 || cmd[6] == 255)) ||
//				 (numnearbychrs > 0 && cmd[6] > 0))) {
//			column = random() % 3;
//
//			// 64c
//			if ((cmd[7] & 0x80) == 0) {
//				audioid = bank[row][1 + column];
//			} else {
//				audioid = bank[row][1 + g_Vars.chrdata->tude];
//			}
//
//			// 6a0
//			if (audioWasNotPlayedRecently(audioid) || CHRRACE(g_Vars.chrdata) == RACE_SKEDAR) {
//				// 6d4
//				audioMarkAsRecentlyPlayed(audioid);
//
//				// 6e8
//				// Replace gurgle with "why me"
//				if (audioid == 0x34e && !headshotted) {
//					audioid = 0x34d;
//				}
//
//				// 700
//				g_Vars.chrdata->soundtimer = 0;
//				g_Vars.chrdata->soundgap = cmd[5];
//				g_Vars.chrdata->propsoundcount++;
//
//				// 72c
//				if (audioid != 0x3f7 && audioid != 0x331 && audioid != 0x3a1) {
//					func0f0926bc(g_Vars.chrdata->prop, 9, -1);
//					// 7a8
//					func0f0939f8(0, g_Vars.chrdata->prop, audioid, -1,
//							-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
//				} else {
//					// Audio is "Stop moving", "Stop dodging" or "Stand still"
//					distance = chrGetDistanceLostToTargetInLastSecond(g_Vars.chrdata);
//
//					if (ABS(distance) > 50) {
//						func0f0926bc(g_Vars.chrdata->prop, 9, -1);
//						// 840
//						func0f0939f8(0, g_Vars.chrdata->prop, audioid, -1,
//								-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
//					}
//				}
//
//				// Consider putting text on screen
//				// Note: if cmd[8] is 0 then it means no text, so the value
//				// needs to be be decremented by one so it's 0-indexed.
//				// 850
//				if (cmd[8] && (cmd[7] & 0x80) == 0) {
//					if (column > 2) {
//						column = 2;
//					}
//
//					text = langGet(g_QuipTexts[cmd[8] - 1][1 + column]);
//
//					if (!audioIsFiltered(audioid)) {
//						// 8ac
//						hudmsgCreateViaPresetWithColour(text, 6, cmd[9]);
//					}
//				} else if (cmd[8]) {
//					text = langGet(g_QuipTexts[cmd[8] - 1][1 + g_Vars.chrdata->tude]);
//
//					if (!audioIsFiltered(audioid)) {
//						// 904
//						hudmsgCreateViaPresetWithColour(text, 6, cmd[9]);
//					}
//				}
//			} else {
//				// Audio was played recently - try and find a different one
//				audioid = 0;
//
//				// 92c
//				for (i = 1; i < 4; i++) {
//					if (audioWasNotPlayedRecently(g_GuardQuipBank[row][i])
//							&& audioWasNotPlayedRecently(bank[row][i])) {
//						audioid = bank[row][i];
//						break;
//					}
//				}
//
//				// 99c
//				if (audioid) {
//					audioMarkAsRecentlyPlayed(audioid);
//
//					// Replace gurgle with "why me"
//					if (audioid == 0x34e && !headshotted) {
//						audioid = 0x34d;
//					}
//
//					g_Vars.chrdata->soundtimer = 0;
//					g_Vars.chrdata->soundgap = cmd[5];
//					g_Vars.chrdata->propsoundcount++;
//
//					// 9fc
//					if (audioid != 0x3f7 && audioid != 0x331 && audioid != 0x3a1) {
//						func0f0926bc(g_Vars.chrdata->prop, 9, -1);
//						// a80
//						func0f0939f8(0, g_Vars.chrdata->prop, audioid, -1,
//								-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
//					} else {
//						// Audio is "Stop moving", "Stop dodging" or "Stand still"
//						// a90
//						distance = chrGetDistanceLostToTargetInLastSecond(g_Vars.chrdata);
//
//						if (ABS(distance) > 50) {
//							func0f0926bc(g_Vars.chrdata->prop, 9, -1);
//							// b28
//							func0f0939f8(0, g_Vars.chrdata->prop, audioid, -1,
//									-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
//						}
//					}
//
//					// b44
//					if (cmd[8]) {
//						text = langGet(g_QuipTexts[cmd[8] - 1][i]);
//
//						if (!audioIsFiltered(audioid)) {
//							// b78
//							hudmsgCreateViaPresetWithColour(text, 6, cmd[9]);
//						}
//					}
//				} else {
//					g_Vars.chrdata->soundtimer = 0;
//					g_Vars.chrdata->soundgap = cmd[5];
//					chrUnsetFlags(g_Vars.chrdata, CHRFLAG1_DISSPEE, BANK_1);
//				}
//			}
//		}
//	}
//
//	setCurrentPlayerNum(prevplayernum);
//
//	g_Vars.aioffset += 10;
//
//	return false;
//}

void func0f05abdc(struct prop *prop)
{
	if (prop && prop->chr && prop->chr->animdata && prop->chr->propsoundcount > 0) {
		prop->chr->propsoundcount--;
	}
}

/**
 * @cmd 01a7
 */
bool aiIfChrPropsoundcountZero(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindByLiteralId(cmd[2]);

	if (chr && chr->propsoundcount == 0) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 4;
	}

	return false;
}

/**
 * @cmd 0131
 */
bool aiIncreaseSquadronAlertness(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 *chrnums = teamGetChrIds(g_Vars.chrdata->team);

	for (; *chrnums != -2; chrnums++) {
		struct chrdata *chr = chrFindByLiteralId(*chrnums);

		if (chr &&
				chr->animdata &&
				!chrIsDead(chr) &&
				chr->actiontype != ACT_DEAD &&
				(g_Vars.chrdata->squadron == chr->squadron || g_Vars.chrdata->squadron == 255) &&
				g_Vars.chrdata->chrnum != chr->chrnum &&
				(chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum) < 1000 || chrHasFlag(g_Vars.chrdata, CHRFLAG0_SQUADALERTANYDIST, BANK_0))) {
			incrementByte(&chr->alertness, cmd[2]);
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0132
 */
bool aiSetAction(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.chrdata->myaction[0] = cmd[2];

	if (cmd[3] == 0) {
		g_Vars.chrdata->orders[0] = 0;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0133
 */
bool aiSetTeamOrders(void)
{
	struct chrnumaction *chraction;
	s32 chrcount = 1;
	s16 *chrnums;
	struct chrnumaction chractions[50];
	s32 num;
	u32 stack;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	chrnums = squadronGetChrIds(g_Vars.chrdata->squadron);

	chraction = chractions;
	chraction->chrnum = g_Vars.chrdata->chrnum;
	chraction->myaction = g_Vars.chrdata->myaction[0];
	chraction++;

	if (chrnums) {
		while (*chrnums != -2) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->animdata
					&& !chrIsDead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chrCompareTeams(g_Vars.chrdata, chr, true)
					&& g_Vars.chrdata->chrnum != chr->chrnum) {
				if (chr->myaction[0] == MA_COVERWAIT
						|| chr->myaction[0] == MA_NORMAL
						|| chr->myaction[0] == MA_WAITING
						|| chr->myaction[0] == MA_SHOOTING) {
					if (chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum) < 3500) {
						chrcount++;
						chraction->chrnum = chr->chrnum;
						chraction->myaction = chr->myaction[0];
						chraction++;
					}
				}
			}

			chrnums++;
		}
	}

	chraction->myaction = MA_END;

	if (chrcount != 1) {
		chraction = &chractions[1];
		num = 1;

		while (chraction->myaction != MA_END) {
			struct chrdata *chr = chrFindByLiteralId(chraction->chrnum);

			switch (chractions[0].myaction) {
			case MA_COVERGOTO:
				if (func0f048e74(chr, 45) == 0) {
					chr->orders[0] = MA_SHOOTING;
				}
				break;
			case MA_COVERBREAK:
				if (func0f048e74(chr, 30) == 0) {
					chr->orders[0] = MA_SHOOTING;
				}
				num++;
				break;
			case MA_COVERSEEN:
				if (func0f048e74(chr, 30) == 0) {
					chr->orders[0] = MA_SHOOTING;
					g_Vars.chrdata->orders[0] = MA_COVERGOTO;
				}
				num++;
				break;
			case MA_FLANKLEFT:
				if (func0f048e74(chr, 50)) {
					chr->orders[0] = MA_FLANKRIGHT;
				} else {
					chr->orders[0] = MA_SHOOTING;
				}
				num++;
				g_Vars.chrdata->orders[0] = MA_FLANKLEFT;
				break;
			case MA_FLANKRIGHT:
				if (func0f048e74(chr, 50)) {
					chr->orders[0] = MA_FLANKLEFT;
				} else {
					chr->orders[0] = MA_SHOOTING;
				}
				num++;
				g_Vars.chrdata->orders[0] = MA_FLANKRIGHT;
				break;
			case MA_DODGE:
				if (func0f048e74(chr, 30) == 0 &&
						chrHasFlagById(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders[0] = MA_WITHDRAW;
				} else {
					chr->orders[0] = MA_SHOOTING;
				}
				num++;
				break;
			case MA_GRENADE:
				if (num < 2) {
					chr->orders[0] = MA_WAITING;
				} else if (chrHasFlagById(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders[0] = MA_WITHDRAW;
				}
				num++;
				break;
			case MA_WAITSEEN:
				if (func0f048e74(chr, 30) &&
						chrHasFlagById(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders[0] = MA_WITHDRAW;
				} else {
					chr->orders[0] = MA_SHOOTING;
				}
				num++;
				break;
			case MA_WITHDRAW:
				if (chrHasFlagById(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders[0] = MA_WITHDRAW;
				}
				break;
			}

			chraction++;
		}

		if (num != 1) {
			g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
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
bool aiIfOrders(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[3] == g_Vars.chrdata->orders[0]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);

		if (g_Vars.chrdata->orders[0] == MA_WITHDRAW) {
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
bool aiIfHasOrders(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->orders[0]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0136
 */
bool aiRetreat(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[3] == 0) {
		chrRunFromPos(g_Vars.chrdata, cmd[2], (cmd[2] & 0x10) ? 400.0f : 10000.0f, &g_Vars.chrdata->runfrompos);
	} else if (cmd[3] == 1) {
		struct prop *target = chrGetTargetProp(g_Vars.chrdata);
		chrRunFromPos(g_Vars.chrdata, cmd[2], 10000, &target->pos);
	} else {
		func0f04ba34(g_Vars.chrdata, 2314, 0);
		chrGoToCover(g_Vars.chrdata, cmd[2]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0137
 */
bool aiIfChrInSquadronDoingAction(void)
{
	s32 ret;
	s16 *chrnums = squadronGetChrIds(g_Vars.chrdata->squadron);
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	ret = 1;

	if (chrnums) {
		for (; *chrnums != -2; chrnums++) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->animdata && chrIsDead(chr) == false &&
					chr->actiontype != ACT_DEAD &&
					chrCompareTeams(g_Vars.chrdata, chr, 1) &&
					g_Vars.chrdata->chrnum != chr->chrnum &&
					chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum) < 3500 &&
					cmd[2] == chr->myaction[0]) {
				ret = 2;
				break;
			}
		}
	}

	if (ret != 1) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0139
 */
bool ai0139(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	struct coord pos;

	func0f04c874(g_Vars.chrdata, flags, &pos, cmd[7], cmd[6]);

	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 013a
 */
bool aiSetChrPresetToUnalertedTeammate(void)
{
	f32 closest_distance = 30999.9;
	s16 candidate_chrnum = -1;
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 *chrnums = teamGetChrIds(g_Vars.chrdata->team);

	if (g_Vars.chrdata->talktimer >= 0x1e1 && g_Vars.chrdata->listening[0]) {
		g_Vars.chrdata->listening[0] = 0;
	}

	for (; *chrnums != -2; chrnums++) {
		struct chrdata *chr = chrFindByLiteralId(*chrnums);

		if (cmd[3] == 0 && chr && chr->animdata &&
				chrIsDead(chr) == false &&
				chr->actiontype != ACT_DEAD &&
				chr->actiontype != ACT_DIE &&
				chr->actiontype != ACT_DRUGGEDKO &&
				chr->actiontype != ACT_DRUGGEDDROP &&
				chr->actiontype != ACT_DRUGGEDCOMINGUP &&
				chr->alertness < 100 &&
				(g_Vars.chrdata->squadron == chr->squadron || g_Vars.chrdata->squadron == 0xff) &&
				g_Vars.chrdata->chrnum != chr->chrnum) {

			f32 distance = chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum);

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
		chrSetChrPreset(g_Vars.chrdata, candidate_chrnum);
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 013b
 */
bool aiSetSquadron(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.chrdata->squadron = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 013c
 */
bool ai013c(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (func0f02ec94(g_Vars.chrdata)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 013d
 */
bool aiIfDangerousObjectNearby(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (chrDetectDangerousObject(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
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
	if (func0f03aca0(g_Vars.chrdata, 0x43c80000, 1) == 0 && func0f04bffc(g_Vars.chrdata, 1000, 12000) != -1) {
		chrGoToCover(g_Vars.chrdata, SPEED_RUN);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 013f
 */
bool aiIfHeliWeaponsArmed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.hovercar) {
		if (g_Vars.hovercar->weaponsarmed) {
			g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
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
bool aiIfHoverbotNextStep(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.hovercar) {
		if ((g_Vars.hovercar->nextstep > cmd[3] && cmd[2] == 1) ||
				(g_Vars.hovercar->nextstep < cmd[3] && cmd[2] == 0)) {
			g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
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
bool aiShuffleInvestigationTerminals(void)
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
	struct tag *goodtag = tagFindById(cmd[2]);
	struct tag *badtag = tagFindById(cmd[3]);
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
			pc = tagFindById(cmd[4]);
			goodtag->unk06 = pc->unk06;
			goodtag->obj = pc->obj;
		} else if (rand1 == 1) {
			pc = tagFindById(cmd[5]);
			goodtag->unk06 = pc->unk06;
			goodtag->obj = pc->obj;
		} else if (rand1 == 2) {
			pc = tagFindById(cmd[6]);
			goodtag->unk06 = pc->unk06;
			goodtag->obj = pc->obj;
		} else {
			pc = tagFindById(cmd[7]);
			goodtag->unk06 = pc->unk06;
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
			pc = tagFindById(cmd[4]);
			badtag->unk06 = pc->unk06;
			badtag->obj = pc->obj;
		} else if (rand2 == 1) {
			pc = tagFindById(cmd[5]);
			badtag->unk06 = pc->unk06;
			badtag->obj = pc->obj;
		} else if (rand2 == 2) {
			pc = tagFindById(cmd[6]);
			badtag->unk06 = pc->unk06;
			badtag->obj = pc->obj;
		} else {
			pc = tagFindById(cmd[7]);
			badtag->unk06 = pc->unk06;
			badtag->obj = pc->obj;
		}
	}

	g_Vars.aioffset += 9;

	return false;
}

/**
 * Used by the blow command, which makes Investigation scientists run to the
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
bool aiSetPadPresetToInvestigationTerminal(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj) {
		s16 objpad = obj->pad;
		s32 i;

		for (i = 0; i < sizeof(g_InvestigationPadMap) / sizeof(g_InvestigationPadMap[0]); i += 2) {
			if (objpad == g_InvestigationPadMap[i]) {
				chrSetPadPreset(g_Vars.chrdata, g_InvestigationPadMap[i + 1]);
			}
		}
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0143
 */
bool aiHeliArmWeapons(void)
{
	if (g_Vars.hovercar) {
		chopperSetArmed(g_Vars.hovercar, true);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0144
 */
bool aiHeliUnarmWeapons(void)
{
	if (g_Vars.hovercar) {
		chopperSetArmed(g_Vars.hovercar, false);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0145
 */
bool aiRebuildTeams(void)
{
	rebuildTeams();
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0146
 */
bool aiRebuildSquadrons(void)
{
	rebuildSquadrons();
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 0147
 */
bool aiIfSquadronIsDead(void)
{
	/**
	 * @bug: anyalive is initialised to true here, and reset to false in each
	 * loop iteration. This causes it to use the last chr's status only.
	 */
	u32 stack[2];
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bool anyalive = true;
	s16 *chrnums = squadronGetChrIds(cmd[2]);

	if (chrnums) {
		while (*chrnums != -2) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->animdata) {
				anyalive = false;

				if (!chrIsDead(chr) && chr->actiontype != ACT_DEAD) {
					anyalive = true;
				}
			}

			chrnums++;
		}
	}

	if (!anyalive) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0148
 */
bool aiChrSetListening(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->listening[0] == 0) {
		chr->listening[0] = cmd[3];
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0149
 */
bool aiIfChrListening(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (cmd[4] == 0) {
		if (cmd[3] == chr->listening[0]) {
			g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
		} else {
			g_Vars.aioffset += 6;
		}
	} else {
		if (g_Vars.chrdata->convtalk == 0) {
			g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
		} else {
			g_Vars.aioffset += 6;
		}
	}

	return false;
}

/**
 * @cmd 014a
 */
bool aiIfTrue(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);

	return false;
}

/**
 * @cmd 014b
 */
bool aiIfNotListening(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata->listening[0] == 0) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 0157
 */
bool aiSetTintedGlassEnabled(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_TintedGlassEnabled = cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0152
 */
bool aiIfNumChrsInSquadronGreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s32 count = 0;
	s16 *chrnums = squadronGetChrIds(cmd[3]);

	if (chrnums) {
		while (*chrnums != -2) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->prop && chrIsDead(chr) == false
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
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0165
 */
bool aiIfChrInjured(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_INJURED)) {
		chr->chrflags &= ~CHRCFLAG_INJURED;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0166
 */
bool aiIfAction(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] == g_Vars.chrdata->myaction[0]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0167
 */
bool aiHovercopterFireRocket(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	chopperFireRocket(g_Vars.hovercar, cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0169
 */
bool aiIfNaturalAnim(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (cmd[2] == g_Vars.chrdata->naturalanim[0]) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 016a
 */
bool aiIfY(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = NULL;
	f32 cutoff_y = ((cmd[4] | (cmd[3] << 8)) << 16) >> 16;

	if (cmd[2] == CHR_TARGET && g_Vars.hovercar) {
		struct chopperobj *chopper = chopperFromHovercar(g_Vars.hovercar);

		if (chopper) {
			struct prop *target = chopperGetTargetProp(chopper);

			if (target && (target->type == PROPTYPE_CHR || target->type == PROPTYPE_PLAYER)) {
				chr = target->chr;
			}
		}
	} else {
		chr = chrFindById(g_Vars.chrdata, cmd[2]);
	}

	if (chr && chr->prop && (
				(chr->prop->pos.y < cutoff_y && cmd[5] == 0) ||
				(chr->prop->pos.y > cutoff_y && cmd[5] == 1))) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;
	}

	return false;
}

/**
 * @cmd 016c
 */
bool aiNoOp016c(void)
{
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 016d
 */
bool aiChrAdjustMotionBlur(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		if (cmd[4] == 0) {
			chr->blurdrugamount -= cmd[3];
		} else {
			chr->blurdrugamount += cmd[3];
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 016e
 */
bool aiDamagePlayer(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct coord coord = {0, 0, 0};
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		if (cmd[4] == 2) {
			u8 sp40[] = {0x1a, 0, 0, 3};
			func0f034124(chr, (s32)cmd[3] * 0.03125f, &coord, sp40, 0);
		} else if (cmd[4] == 0) {
			func0f034124(chr, (s32)cmd[3] * 0.03125f, &coord, NULL, 0);
		} else {
			func0f034124(chr, (s32)cmd[3] * -0.03125f, &coord, NULL, 0);
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 016f
 */
bool aiIfChrHasGun(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->animdata && chr->gunprop == NULL) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0170
 */
bool aiDoGunCommand(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct weaponobj *weapon = g_Vars.chrdata->gunprop->weapon;

	if (cmd[2] == 0 || ((weapon->base.hidden & OBJHFLAG_00000080) == 0 && cmd[2] == 1)) {
		if (cmd[2] == 0) {
			chrGoToProp(g_Vars.chrdata, g_Vars.chrdata->gunprop, SPEED_JOG);
		}

		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0171
 */
bool aiIfDistanceToGunLessThan(void)
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
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0172
 */
GLOBAL_ASM(
glabel ai0172
/*  f05ca78:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f05ca7c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f05ca80:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f05ca84:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f05ca88:	8e2e0434 */ 	lw	$t6,0x434($s1)
/*  f05ca8c:	8e2f0438 */ 	lw	$t7,0x438($s1)
/*  f05ca90:	8e220424 */ 	lw	$v0,0x424($s1)
/*  f05ca94:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f05ca98:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f05ca9c:	afb80024 */ 	sw	$t8,0x24($sp)
/*  f05caa0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f05caa4:	8c500300 */ 	lw	$s0,0x300($v0)
/*  f05caa8:	ac400300 */ 	sw	$zero,0x300($v0)
/*  f05caac:	52000015 */ 	beqzl	$s0,.L0f05cb04
/*  f05cab0:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f05cab4:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f05cab8:	53200012 */ 	beqzl	$t9,.L0f05cb04
/*  f05cabc:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f05cac0:	8e080018 */ 	lw	$t0,0x18($s0)
/*  f05cac4:	5500000f */ 	bnezl	$t0,.L0f05cb04
/*  f05cac8:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f05cacc:	92090000 */ 	lbu	$t1,0x0($s0)
/*  f05cad0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f05cad4:	5521000b */ 	bnel	$t1,$at,.L0f05cb04
/*  f05cad8:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f05cadc:	0fc19711 */ 	jal	func0f065c44
/*  f05cae0:	02002025 */ 	or	$a0,$s0,$zero
/*  f05cae4:	0fc18171 */ 	jal	func0f0605c4
/*  f05cae8:	02002025 */ 	or	$a0,$s0,$zero
/*  f05caec:	0fc180c0 */ 	jal	func0f060300
/*  f05caf0:	02002025 */ 	or	$a0,$s0,$zero
/*  f05caf4:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f05caf8:	0fc22b95 */ 	jal	func0f08ae54
/*  f05cafc:	8e250424 */ 	lw	$a1,0x424($s1)
/*  f05cb00:	8faa0024 */ 	lw	$t2,0x24($sp)
.L0f05cb04:
/*  f05cb04:	8e240434 */ 	lw	$a0,0x434($s1)
/*  f05cb08:	8e250438 */ 	lw	$a1,0x438($s1)
/*  f05cb0c:	0fc13583 */ 	jal	chraiGoToLabel
/*  f05cb10:	91460003 */ 	lbu	$a2,0x3($t2)
/*  f05cb14:	ae220438 */ 	sw	$v0,0x438($s1)
/*  f05cb18:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f05cb1c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f05cb20:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f05cb24:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f05cb28:	03e00008 */ 	jr	$ra
/*  f05cb2c:	00001025 */ 	or	$v0,$zero,$zero
);

// Mismatch because some stores/loads to SP is in the opposite order
//bool ai0172(void)
//{
//	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
//	struct prop *prop = g_Vars.chrdata->gunprop;
//	g_Vars.chrdata->gunprop = NULL;
//
//	if (prop && prop->weapon && prop->parent == NULL && prop->type == PROPTYPE_WEAPON) {
//		func0f065c44(prop);
//		func0f0605c4(prop);
//		func0f060300(prop);
//		func0f08ae54(prop->weapon, g_Vars.chrdata);
//	}
//
//	g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
//
//	return false;
//}

/**
 * @cmd 0173
 */
bool aiChrCopyProperties(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->animdata) {
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

		g_Vars.chrdata->naturalanim[0] = chr->naturalanim[0];
		g_Vars.chrdata->myspecial = chr->myspecial;
		g_Vars.chrdata->yvisang = chr->yvisang;
		g_Vars.chrdata->teamscandist = chr->teamscandist;

		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0177
 */
bool aiPlayerAutoWalk(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 pad_id = cmd[4] | (cmd[3] << 8);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);
		currentPlayerAutoWalk(pad_id, cmd[5], cmd[6], cmd[7], cmd[8]);
		setCurrentPlayerNum(prevplayernum);
	}

	g_Vars.aioffset += 9;

	return false;
}

/**
 * @cmd 0178
 */
bool aiIfPlayerAutoWalkFinished(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bool walking = false;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);

		if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
			walking = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	if (walking) {
		g_Vars.aioffset += 4;
	} else {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	}

	return false;
}

/**
 * @cmd 0181
 */
bool aiIfPlayerLookingAtObject(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[3]);
	bool pass = false;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);

		if (g_Vars.currentplayer->lookingatprop == obj->prop) {
			pass = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 0182
 */
bool aiPunchOrKick(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.chrdata && chrTryPunchOrKick(g_Vars.chrdata, cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0183
 */
bool aiIfTargetIsPlayer(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct prop *target = chrGetTargetProp(g_Vars.chrdata);

	if (target->type == PROPTYPE_EYESPY || target->type == PROPTYPE_PLAYER) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
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
	func0f03a3ec(g_Vars.chrdata, 512, 0, cmd[2], cmd[3]);
	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 0186
 */
bool aiIfSoundTimer(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s32 value = cmd[3] | (cmd[2] << 8);

	if ((g_Vars.chrdata->soundtimer > value && cmd[4] == 0) ||
			(g_Vars.chrdata->soundtimer < value && cmd[4] == 1)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 0187
 */
bool aiSetTargetToEyespyIfInSight(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 prevtarget = g_Vars.chrdata->target;
	struct eyespy *eyespy = g_Vars.players[g_Vars.chrdata->p1p2]->eyespy;

	if (eyespy) {
		struct chrdata *chr = eyespy->prop->chr;
		g_Vars.chrdata->target = propGetIndexByChrId(g_Vars.chrdata, chr->chrnum);

		if (chrCheckTargetInSight(g_Vars.chrdata)) {
			g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
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
bool aiIfLiftStationary(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	bool pass = false;

	if (obj && obj->prop && obj->type == OBJTYPE_LIFT) {
		struct liftobj *lift = (struct liftobj *)obj;

		if ((obj->flags & OBJFLAG_DEACTIVATED) || lift->dist == 0) {
			pass = true;
		}
	}

	if (pass) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0189
 */
bool aiLiftGoToStop(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->type == OBJTYPE_LIFT) {
		struct liftobj *lift = (struct liftobj *)obj;
		liftGoToStop(lift, cmd[3]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 018a
 */
GLOBAL_ASM(
glabel aiIfLiftAtStop
/*  f05d30c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f05d310:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f05d314:	8c6e0434 */ 	lw	$t6,0x434($v1)
/*  f05d318:	8c6f0438 */ 	lw	$t7,0x438($v1)
/*  f05d31c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f05d320:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f05d324:	01cf3821 */ 	addu	$a3,$t6,$t7
/*  f05d328:	90e40002 */ 	lbu	$a0,0x2($a3)
/*  f05d32c:	0fc2556c */ 	jal	objFindByTagId
/*  f05d330:	afa7001c */ 	sw	$a3,0x1c($sp)
/*  f05d334:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f05d338:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f05d33c:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*  f05d340:	10400013 */ 	beqz	$v0,.L0f05d390
/*  f05d344:	00002025 */ 	or	$a0,$zero,$zero
/*  f05d348:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f05d34c:	13000010 */ 	beqz	$t8,.L0f05d390
/*  f05d350:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05d354:	90590003 */ 	lbu	$t9,0x3($v0)
/*  f05d358:	24010030 */ 	addiu	$at,$zero,0x30
/*  f05d35c:	1721000c */ 	bne	$t9,$at,.L0f05d390
/*  f05d360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05d364:	90e80003 */ 	lbu	$t0,0x3($a3)
/*  f05d368:	80490085 */ 	lb	$t1,0x85($v0)
/*  f05d36c:	15090008 */ 	bne	$t0,$t1,.L0f05d390
/*  f05d370:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05d374:	44802000 */ 	mtc1	$zero,$f4
/*  f05d378:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f05d37c:	46062032 */ 	c.eq.s	$f4,$f6
/*  f05d380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05d384:	45000002 */ 	bc1f	.L0f05d390
/*  f05d388:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05d38c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f05d390:
/*  f05d390:	5080000a */ 	beqzl	$a0,.L0f05d3bc
/*  f05d394:	8c6a0438 */ 	lw	$t2,0x438($v1)
/*  f05d398:	8c640434 */ 	lw	$a0,0x434($v1)
/*  f05d39c:	8c650438 */ 	lw	$a1,0x438($v1)
/*  f05d3a0:	0fc13583 */ 	jal	chraiGoToLabel
/*  f05d3a4:	90e60004 */ 	lbu	$a2,0x4($a3)
/*  f05d3a8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f05d3ac:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f05d3b0:	10000004 */ 	beqz	$zero,.L0f05d3c4
/*  f05d3b4:	ac620438 */ 	sw	$v0,0x438($v1)
/*  f05d3b8:	8c6a0438 */ 	lw	$t2,0x438($v1)
.L0f05d3bc:
/*  f05d3bc:	254b0005 */ 	addiu	$t3,$t2,0x5
/*  f05d3c0:	ac6b0438 */ 	sw	$t3,0x438($v1)
.L0f05d3c4:
/*  f05d3c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f05d3c8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f05d3cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f05d3d0:	03e00008 */ 	jr	$ra
/*  f05d3d4:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch because the load order of lift->levelcur and cmd[3] are swapped
//bool aiIfLiftAtStop(void)
//{
//	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
//	struct defaultobj *obj = objFindByTagId(cmd[2]);
//	bool pass = false;
//
//	if (obj && obj->prop && obj->type == OBJTYPE_LIFT) {
//		struct liftobj *lift = (struct liftobj *)obj;
//
//		if (lift->levelcur == cmd[3] && lift->dist == 0) {
//			pass = true;
//		}
//	}
//
//	if (pass) {
//		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
//	} else {
//		g_Vars.aioffset += 5;
//	}
//
//	return false;
//}

/**
 * @cmd 018b
 */
bool aiConfigureRain(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	weatherConfigureRain(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01b6
 */
bool aiConfigureSnow(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	weatherConfigureSnow(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 018c
 */
bool aiChrToggleProp(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		func0f04cf90(chr, cmd[3]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 018d
 */
bool aiActivateLift(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[3]);

	if (obj && obj->prop) {
		liftActivate(obj->prop, cmd[2]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 018e
 */
bool aiMiniSkedarTryPounce(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 thing = cmd[4] | (cmd[3] << 8);

	if (chrTrySkJump(g_Vars.chrdata, g_Vars.chrdata->pouncebits, cmd[2], thing, cmd[5])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[6]);
	} else {
		g_Vars.aioffset += 7;

	}

	return false;
}

/**
 * @cmd 018f
 */
bool aiIfObjectDistanceToPadLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (f32)(cmd[4] | (cmd[3] << 8)) * 10;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	s32 pad_id = (cmd[6] | (cmd[5] << 8)) & 0xffff;
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	struct pad pad;
	bool pass = false;

	if (obj && obj->prop) {
		pad_id = chrResolvePadId(g_Vars.chrdata, pad_id);

		if (pad_id >= 0) {
			padUnpack(pad_id, PADFIELD_POS, &pad);
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
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[7]);
	} else {
		g_Vars.aioffset += 8;
	}

	return false;
}

/**
 * @cmd 0190
 */
bool aiSetSavefileFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	savefileSetFlag(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0191
 */
bool aiUnsetSavefileFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	savefileUnsetFlag(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 0192
 */
bool aiIfSavefileFlagIsSet(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (savefileHasFlag(cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 0193
 */
bool aiIfSavefileFlagIsUnset(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (!savefileHasFlag(cmd[2])) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 019e
 */
bool aiIfObjHealthLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s32 damage = cmd[4] | (cmd[3] << 8);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	bool condition_passes = false;

	if (obj && obj->prop && obj->damage < damage) {
		condition_passes = true;
	}

	if (condition_passes) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[5]);
	} else {
		g_Vars.aioffset += 6;
	}

	return false;
}

/**
 * @cmd 019f
 */
bool aiSetObjHealth(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s32 damage = cmd[4] | (cmd[3] << 8);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->damage = damage;
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01a0
 */
bool aiSetChrSpecialDeathAnimation(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->specialdie = cmd[3];
	}

	g_Vars.aioffset += 4;

	return 0;
}

/**
 * @cmd 01a1
 */
bool aiSetRoomToSearch(void)
{
	struct chrdata *target = chrFindById(g_Vars.chrdata, CHR_TARGET);

	if (target && target->prop) {
		g_Vars.chrdata->roomtosearch = target->prop->rooms[0];
	}

	g_Vars.aioffset += 2;

	return false;
}

s16 g_CiMainQuips[][3] = {
	{ 0x17a1, 0x17a2, 0x17a3 }, // Carrington
	{ 0x17a4, 0x17a5, 0x17a6 }, // Device training girl
	{ 0x17a7, 0x17a8, 0x17a9 }, // Grimshaw
	{ 0x17aa, 0x17ab, 0x17ac }, // Holo training girl
	{ 0x17ad, 0x17ae, 0x17af }, // Hangar guy
	{ 0x179e, 0x179f, 0x17a0 }, // Foster
};

s16 g_CiGreetingQuips[][3] = {
	{ 0x8028, 0x8028, 0x8028 },
	{ 0x802b, 0x802b, 0x802b },
	{ 0x802c, 0x802d, 0x802e },
	{ 0x802f, 0x802f, 0x802f },
	{ 0x8030, 0x8030, 0x8030 },
	{ 0x8031, 0x8031, 0x8031 },
	{ 0x8032, 0x8032, 0x8033 },
	{ 0x8033, 0x8034, 0x8034 },
	{ 0x8035, 0x8035, 0x8036 },
	{ 0x8036, 0x8037, 0x8037 },
};

s16 g_CiAnnoyedQuips[][3] = {
	{ 0x177b, 0x177b, 0x177b }, // Carrington
	{ 0x177d, 0x177d, 0x177d }, // Device training girl
	{ 0x1789, 0x178a, 0x178b }, // Grimshaw
	{ 0x178d, 0x178d, 0x178d }, // Holo training girl
	{ 0x1795, 0x1795, 0x1795 }, // Hangar guy
	{ 0x1785, 0x1785, 0x1785 }, // Foster
	{ 0x1791, 0x1791, 0x1791 }, // Male "Don't you have to be somewhere?"
	{ 0x1791, 0x1791, 0x1791 },
	{ 0x1782, 0x1782, 0x1782 }, // Female "Don't you have to be somewhere?"
	{ 0x1783, 0x1783, 0x1783 }, // "Bother someone else, would you?"
};

s16 g_CiThanksQuips[] = {
	0x0000,
	0x1b1c, // Device training girl "Thanks for coming back for me, Joanna"
	0x1b1f, // Grimshaw "That was too close"
	0x1b20, // Holo training girl "Quick, let's get to the hangar"
	0x0000,
	0x1b1e, // Foster "I knew I could rely on you, Joanna"
	0x1b21, // Device training guy "Thanks, Jo"
	0x1b21,
	0x1b1d, // Female "Thanks"
	0x1b1d,
};

/**
 * @cmd 01a2
 */
bool aiSayCiStaffQuip(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 quip;

	if (cmd[2] == CIQUIP_GREETING) {
		quip = g_CiGreetingQuips[g_Vars.chrdata->morale][random() % 3];
		audioPlayFromProp((s8)cmd[3], quip, 0, g_Vars.chrdata->prop, 9, 0);
	}

	if (cmd[2] == CIQUIP_MAIN) {
		quip = g_CiMainQuips[g_Vars.chrdata->morale][random() % 3];
		audioPlayFromProp((s8)cmd[3], quip, 0, g_Vars.chrdata->prop, 9, 0);
	}

	if (cmd[2] == CIQUIP_ANNOYED) {
		quip = g_CiAnnoyedQuips[g_Vars.chrdata->morale][random() % 3];
		audioPlayFromProp((s8)cmd[3], quip, 0, g_Vars.chrdata->prop, 9, 0);
	}

	if (cmd[2] == CIQUIP_THANKS) {
		quip = g_CiThanksQuips[g_Vars.chrdata->morale];
		audioPlayFromProp((s8)cmd[3], quip, 0, g_Vars.chrdata->prop, 9, 0);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01a3
 */
bool aiDoPresetAnimation(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	// These all appear to be talking animations
	u16 anims[15] = {
		/* 0*/ 0x0296,
		/* 1*/ 0x0297,
		/* 2*/ 0x0298,
		/* 3*/ 0x028a, // when value is 3 (1/2 chance)
		/* 4*/ 0x028c, // when value is 3 (1/2 chance)
		/* 5*/ 0x0290,
		/* 6*/ 0x0291,
		/* 7*/ 0x00a3, // when value is 255 (1/8 chance)
		/* 8*/ 0x028e, // when value is 255 (1/8 chance)
		/* 9*/ 0x028f, // when value is 255 (1/8 chance)
		/*10*/ 0x0231, // when value is 255 (1/8 chance)
		/*11*/ 0x0232, // when value is 255 (1/8 chance)
		/*12*/ 0x0233, // when value is 255 (1/8 chance)
		/*13*/ 0x0234, // when value is 255 (1/8 chance)
		/*14*/ 0x028d, // when value is 255 (1/8 chance)
	};

	if (cmd[2] == 255) {
		func0f03af44(g_Vars.chrdata, anims[7 + (random() & 7)], 0, -1, 0, 15, 0.5);
	} else if (cmd[2] == 254) {
		struct prop *prop0 = chrGetEquippedWeaponProp(g_Vars.chrdata, 1);
		struct prop *prop1 = chrGetEquippedWeaponProp(g_Vars.chrdata, 0);

		if (func0f02e124(prop0) || func0f02e124(prop1)) {
			func0f03af44(g_Vars.chrdata, ANIM_FIX_GUN_JAM_EASY, 0, -1, 0, 5, 0.5);
		} else {
			func0f03af44(g_Vars.chrdata, ANIM_FIX_GUN_JAM_HARD, 0, -1, 0, 5, 0.5);
		}
	} else if (cmd[2] == 3) {
		func0f03af44(g_Vars.chrdata, anims[3 + (random() & 1)], 0, -1, 0, 15, 0.5);
	} else {
		func0f03af44(g_Vars.chrdata, anims[cmd[2]], 0, -1, 0, 15, 0.5);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01a5
 */
bool ai01a5(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (func0f046a30(g_Vars.chrdata)) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 01a6
 */
bool aiIfTargetYDifferenceLessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct prop *prop = chrGetTargetProp(g_Vars.chrdata);
	f32 diff = prop->pos.y - g_Vars.chrdata->prop->pos.y;

	if (diff < 0) {
		diff = 0 - diff;
	}

	if (diff < (s32)cmd[2] * 10.0f) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	} else {
		g_Vars.aioffset += 4;
	}

	return false;
}

/**
 * @cmd 01aa
 */
bool ai01aa(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 a = 3000;

	func0f0056f4(
			g_Vars.currentplayer->prop->rooms[0],
			&g_Vars.currentplayer->prop->pos,
			g_Vars.chrdata->prop->rooms[0],
			&g_Vars.chrdata->prop->pos,
			0, &a, 0);

	if (a < 3000) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 01ae
 */
bool aiClearInventory(void)
{
	u32 stackpadding[2];
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 playernum;

	for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
		setCurrentPlayerNum(playernum);

		if (g_Vars.currentplayer == g_Vars.bond || g_Vars.currentplayer == g_Vars.coop) {
			currentPlayerClearInventory();
			g_Vars.currentplayer->itemswitch = 0;
			currentPlayerGiveWeapon(WEAPON_UNARMED);
			currentPlayerEquipWeapon(WEAPON_UNARMED);
		}
	}

	setCurrentPlayerNum(prevplayernum);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01ad
 */
bool aiReleaseObject(void)
{
	setMoveModeForAllPlayers(MOVEMODE_WALK);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01af
 */
bool aiChrGrabObject(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[3]);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER && obj && obj->prop) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);

		if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK
				&& currentPlayerGetCrouchPos() == CROUCH_STAND
				&& g_Vars.currentplayer->crouchoffset == 0) {
			currentPlayerGrabProp(obj->prop);
		}

		setCurrentPlayerNum(prevplayernum);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01b1
 */
bool aiShuffleRuinsPillars(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct tag *ptr1 = tagFindById(cmd[2]);
	struct tag *ptr2 = tagFindById(cmd[3]);
	struct tag *ptr3 = tagFindById(cmd[4]);
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
	src = tagFindById(pillars[marked1index]);
	ptr1->unk06 = src->unk06;
	ptr1->obj = src->obj;

	ptr1 = tagFindById(cmd[10]);
	src = tagFindById(mines[marked1index]);
	ptr1->unk06 = src->unk06;
	ptr1->obj = src->obj;

	// Pillar/mine 2
	src = tagFindById(pillars[marked2index]);
	ptr2->unk06 = src->unk06;
	ptr2->obj = src->obj;

	ptr2 = tagFindById(cmd[11]);
	src = tagFindById(mines[marked2index]);
	ptr2->unk06 = src->unk06;
	ptr2->obj = src->obj;

	// Pillar/mine 3
	src = tagFindById(pillars[marked3index]);
	ptr3->unk06 = src->unk06;
	ptr3->obj = src->obj;

	ptr3 = tagFindById(cmd[12]);
	src = tagFindById(mines[marked3index]);
	ptr3->unk06 = src->unk06;
	ptr3->obj = src->obj;

	g_Vars.aioffset += 18;

	return false;
}

/**
 * @cmd 01b2
 */
bool ai01b2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	var8007db84 = 0.1f * (s32)cmd[2];
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01b3
 */
bool aiToggleP1P2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.coopplayernum >= 0) {
		struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

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
bool aiChrSetP1P2(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (g_Vars.coopplayernum >= 0) {
		struct chrdata *chr1 = chrFindById(g_Vars.chrdata, cmd[2]);
		struct chrdata *chr2 = chrFindById(g_Vars.chrdata, cmd[3]);

		if (chr1 && chr2 && chr2->prop && chr2->prop->type == PROPTYPE_PLAYER) {
			u32 playernum = propGetPlayerNum(chr2->prop);

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
bool aiChrSetCloaked(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		if (!chrIsDead(chr)) {
			if (cmd[3]) {
				chrCloak(chr, cmd[4]);
			} else {
				chrUncloak(chr, cmd[4]);
			}
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01b8
 */
bool aiSetAutogunType(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->type == OBJTYPE_AUTOGUN) {
		struct autogunobj *autogun = (struct autogunobj *)obj;
		autogun->autogun_type = cmd[3];
		autogun->unka4 = 0;
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01b9
 */
bool aiShufflePelagicSwitches(void)
{
	u8 buttonsdone[] = {0, 0, 0, 0, 0, 0, 0, 0};
	u8 i;
	u8 j;
	struct tag *tag;
	struct tag *button;
	u8 index;

	for (i = 8; i < 16; i++) {
		tag = tagFindById(i);
		index = random() & 7;

		if (buttonsdone[index] == 0) {
			// Switch has not yet been mapped
			button = tagFindById(index);
			tag->unk06 = button->unk06;
			tag->obj = button->obj;
			buttonsdone[index] = 1;
		} else {
			// Switch is already mapped - find first unmapped switch
			for (j = 0; buttonsdone[j]; j++);

			button = tagFindById(j);
			tag->unk06 = button->unk06;
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
bool aiNoOp01bb(void)
{
	g_Vars.aioffset += 4;
	return false;
}

/**
 * @cmd 01bc
 */
GLOBAL_ASM(
glabel ai01bc
/*  f05ead4:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f05ead8:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f05eadc:	8c6f0424 */ 	lw	$t7,0x424($v1)
/*  f05eae0:	8c640434 */ 	lw	$a0,0x434($v1)
/*  f05eae4:	8c650438 */ 	lw	$a1,0x438($v1)
/*  f05eae8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f05eaec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f05eaf0:	8df8032c */ 	lw	$t8,0x32c($t7)
/*  f05eaf4:	00851021 */ 	addu	$v0,$a0,$a1
/*  f05eaf8:	904e0002 */ 	lbu	$t6,0x2($v0)
/*  f05eafc:	0018ca40 */ 	sll	$t9,$t8,0x9
/*  f05eb00:	00194742 */ 	srl	$t0,$t9,0x1d
/*  f05eb04:	15c80007 */ 	bne	$t6,$t0,.L0f05eb24
/*  f05eb08:	24a90004 */ 	addiu	$t1,$a1,0x4
/*  f05eb0c:	0fc13583 */ 	jal	chraiGoToLabel
/*  f05eb10:	90460003 */ 	lbu	$a2,0x3($v0)
/*  f05eb14:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f05eb18:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f05eb1c:	10000002 */ 	beqz	$zero,.L0f05eb28
/*  f05eb20:	ac620438 */ 	sw	$v0,0x438($v1)
.L0f05eb24:
/*  f05eb24:	ac690438 */ 	sw	$t1,0x438($v1)
.L0f05eb28:
/*  f05eb28:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f05eb2c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f05eb30:	00001025 */ 	or	$v0,$zero,$zero
/*  f05eb34:	03e00008 */ 	jr	$ra
/*  f05eb38:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch due to different temporary registers
//bool ai01bc(void)
//{
//	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
//
//	if (cmd[2] == g_Vars.chrdata->pouncebits) {
//		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
//	} else {
//		g_Vars.aioffset += 4;
//	}
//
//	return false;
//}

/**
 * @cmd 01bd
 */
bool aiIfTrainingPcHolographed(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct trainingdata *data = getDeviceTrainingData();

	if (data->holographedpc) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 01be
 */
bool aiIfChrWeaponEquipped(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	struct prop *prop = chr ? chr->prop : NULL;
	u8 is_using_weapon = false;

	if (prop && prop->type == PROPTYPE_PLAYER) {
		u32 playernum = propGetPlayerNum(prop);
		u32 prevplayernum = g_Vars.currentplayernum;
		setCurrentPlayerNum(playernum);

		if (currentPlayerHasWeaponEquipped(cmd[3]) == 1) {
			is_using_weapon = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	if (is_using_weapon) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 01bf
 */
bool aiChrBeginOrEndTeleport(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u16 pad_id = cmd[3] | (cmd[2] << 8);
	f32 fvalue[1];
	struct chrdata *chr;
	s32 a;
	u32 playernum;
	u32 prevplayernum;
	s32 b;
	s32 c;
	fvalue[0] = 0.4;
	chr = chrFindById(g_Vars.chrdata, cmd[4]);
	prevplayernum = g_Vars.currentplayernum;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);
	}

	if (pad_id == 0) {
		g_Vars.currentplayer->teleportstate = TELEPORTSTATE_4;
		g_Vars.currentplayer->teleporttime = 0;
	} else {
		g_Vars.currentplayer->teleporttime = 0;
		g_Vars.currentplayer->teleportstate = TELEPORTSTATE_STARTING;
		g_Vars.currentplayer->teleportpad = pad_id;
		g_Vars.currentplayer->teleportcamerapad = 0;

		a = osGetThreadPri(0);
		b = osGetThreadPri(&var800915e0);
		osSetThreadPri(0, b + 1);
		c = audioStart(var80095200, 0x0433, NULL, -1, -1, -1, -1, -1);

		if (c) {
			func00033e50(c, 16, fvalue[0]);
		}

		osSetThreadPri(0, a);
	}

	g_Vars.aioffset += 5;

	setCurrentPlayerNum(prevplayernum);

	return false;
}

/**
 * @cmd 01c0
 */
bool aiIfChrTeleportFullWhite(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[3]);
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 a;
	f32 fvalue[1];
	s32 b;
	s32 c;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 playernum = propGetPlayerNum(chr->prop);
		setCurrentPlayerNum(playernum);
	}

	if (g_Vars.currentplayer->teleportstate < TELEPORTSTATE_3) {
		g_Vars.aioffset += 4;
	} else {
		fvalue[0] = 0.4;
		a = osGetThreadPri(0);
		b = osGetThreadPri(&var800915e0);
		osSetThreadPri(0, b + 1);
		c = audioStart(var80095200, 0x8055, NULL, -1, -1, -1, -1, -1);

		if (c) {
			func00033e50(c, 16, fvalue[0]);
		}

		osSetThreadPri(0, a);
		g_Vars.currentplayer->teleportstate = TELEPORTSTATE_3;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	}

	setCurrentPlayerNum(prevplayernum);

	return false;
}

/**
 * @cmd 01c5
 */
bool ai01c5(void)
{
	func0f04d000(g_Vars.chrdata);
	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 01c8
 */
bool ai01c8(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	g_Vars.aioffset += 3;
	func0f01aca8(cmd[2]);

	return false;
}

/**
 * @cmd 01c9
 */
bool ai01c9(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (func0f01ab94()) {
		func0f01abf0();
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset = g_Vars.aioffset + 3;
	}

	return false;
}

/**
 * @cmd 01ca
 */
bool aiChrSetCutsceneWeapon(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	s32 model_id = weaponGetModel(cmd[3]);
	s32 fallback_model_id = weaponGetModel(cmd[4]);

	if (chr) {
		if (cmd[3] == 0xff) {
			if (cmd[4] == 0xff) {
				if (chr->weapons_held[0]) {
					struct weaponobj *weapon = chr->weapons_held[0]->weapon;
					bool valid = true;

					switch (weapon->weapon_id) {
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
						chrSetWeaponFlag4(chr, 1);
						chrSetWeaponFlag4(chr, 0);
					}
				}
			} else {
				if (chr->weapons_held[0] == NULL && chr->weapons_held[1] == NULL && fallback_model_id >= 0) {
					func0f08b8e8(chr, fallback_model_id, cmd[4], 0, 0, 0);
				}
			}
		} else {
			chrSetWeaponFlag4(chr, 1);
			chrSetWeaponFlag4(chr, 0);

			if (model_id >= 0) {
				func0f08b8e8(chr, model_id, cmd[3], 0, 0, 0);
			}

			if (fallback_model_id >= 0) {
				func0f08b8e8(chr, fallback_model_id, cmd[4], 0x10000000, 0, 0);
			}
		}
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01cb
 */
bool aiFadeScreen(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	u32 color = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	s16 num_frames = (cmd[7] | (cmd[6] << 8));
	fadeConfigure(color, num_frames);
	g_Vars.aioffset += 8;

	return false;
}

/**
 * @cmd 01cc
 */
bool aiIfFadeComplete(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

	if (fadeIsActive() == false) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 01cd
 */
bool aiSetChrHudpieceVisible(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->animdata) {
		chrSetHudpieceVisible(chr, cmd[3]);
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01ce
 */
bool aiSetPassiveMode(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	playersSetPassiveMode(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01cf
 */
bool aiChrSetFiringInCutscene(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	struct coord sp2c = {0, 0, 0};
	struct coord sp20 = {0, 0, 0};

	if (chr && chr->weapons_held[0]) {
		if (cmd[3]) {
			chrSetFiring(chr, 0, true);
			func0f03e29c(chr, 0, 1, 0, &sp2c, &sp20);
		} else {
			chrSetFiring(chr, 0, false);
		}
	}

	g_Vars.aioffset += 4;

	return false;
}

/**
 * @cmd 01d0
 */
bool aiSetPortalFlag(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 portalnum = cmd[3] | (cmd[2] << 8);

	g_Portals[portalnum].flags |= cmd[4];
	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01d1
 */
bool aiSetObjPartVisible(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		objSetPartVisible(obj, cmd[3], cmd[4]);
	}

	g_Vars.aioffset += 5;

	return false;
}

/**
 * @cmd 01d2
 */
bool aiChrEmitSparks(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chrEmitSparks(chr);
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01d3
 */
bool aiSetDrCarollImages(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *drcaroll = chrFindById(g_Vars.chrdata, cmd[2]);

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
GLOBAL_ASM(
glabel ai01d4
/*  f05f7b8:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f05f7bc:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f05f7c0:	8cee0434 */ 	lw	$t6,0x434($a3)
/*  f05f7c4:	8cef0438 */ 	lw	$t7,0x438($a3)
/*  f05f7c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f05f7cc:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f05f7d0:	90780002 */ 	lbu	$t8,0x2($v1)
/*  f05f7d4:	90680003 */ 	lbu	$t0,0x3($v1)
/*  f05f7d8:	906b0004 */ 	lbu	$t3,0x4($v1)
/*  f05f7dc:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f05f7e0:	03282025 */ 	or	$a0,$t9,$t0
/*  f05f7e4:	00044c00 */ 	sll	$t1,$a0,0x10
/*  f05f7e8:	00095403 */ 	sra	$t2,$t1,0x10
/*  f05f7ec:	000ac8c0 */ 	sll	$t9,$t2,0x3
/*  f05f7f0:	032ac821 */ 	addu	$t9,$t9,$t2
/*  f05f7f4:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*  f05f7f8:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*  f05f7fc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f05f800:	032ac823 */ 	subu	$t9,$t9,$t2
/*  f05f804:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f05f808:	906d0005 */ 	lbu	$t5,0x5($v1)
/*  f05f80c:	03193021 */ 	addu	$a2,$t8,$t9
/*  f05f810:	94c80000 */ 	lhu	$t0,0x0($a2)
/*  f05f814:	000b6200 */ 	sll	$t4,$t3,0x8
/*  f05f818:	018d7825 */ 	or	$t7,$t4,$t5
/*  f05f81c:	010f4825 */ 	or	$t1,$t0,$t7
/*  f05f820:	a4c90000 */ 	sh	$t1,0x0($a2)
/*  f05f824:	8cea0438 */ 	lw	$t2,0x438($a3)
/*  f05f828:	254b0006 */ 	addiu	$t3,$t2,0x6
/*  f05f82c:	03e00008 */ 	jr	$ra
/*  f05f830:	aceb0438 */ 	sw	$t3,0x438($a3)
);

//bool ai01d4(void)
//{
//	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
//	s16 room_id = cmd[3] | (cmd[2] << 8);
//	u32 value = cmd[5] | (cmd[4] << 8);
//
//	struct room *room = &g_Rooms[room_id];
//	room->unk00 |= value;
//
//	g_Vars.aioffset += 6;
//
//	return false;
//}

/**
 * @cmd 01d5
 */
bool aiShowCutsceneChrs(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	bool show = cmd[2];
	s32 i;

	if (show) {
		for (i = getNumChrs() - 1; i >= 0; i--) {
			if (g_ChrsA[i].chrnum >= 0 && g_ChrsA[i].prop && (g_ChrsA[i].hidden2 & CHRH2FLAG_0001)) {
				g_ChrsA[i].hidden2 &= ~CHRH2FLAG_0001;
				g_ChrsA[i].chrflags &= ~CHRCFLAG_HIDDEN;
			}
		}
	} else {
		for (i = getNumChrs() - 1; i >= 0; i--) {
			if (g_ChrsA[i].chrnum >= 0 && g_ChrsA[i].prop &&
					(g_ChrsA[i].chrflags & (CHRCFLAG_UNPLAYABLE | CHRCFLAG_HIDDEN)) == 0) {
				g_ChrsA[i].hidden2 |= CHRH2FLAG_0001;
				g_ChrsA[i].chrflags |= CHRCFLAG_HIDDEN;
			}
		}
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01d6
 */
bool aiMiscellaneous(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 room_id = (cmd[3] | (cmd[2] << 8));
	s32 value = cmd[5];
	s32 i;

	switch (cmd[4]) {
	case 0:
		var8006ae18 = value;
		break;
	case 1:
		var8006ae1c = value;
		break;
	case 2:
		var8006ae20 = value;
		break;
	case 3:
		var8006ae24 = value;
		break;
	case 4:
		var8006ae28 = value;
		break;
	case 5:
		g_Rooms[room_id].flags &= ~ROOMFLAG_4000;
		if (value) {
			g_Rooms[room_id].flags |= ROOMFLAG_4000;
		}
		break;
	case 6:
		g_Rooms[room_id].flags &= ~ROOMFLAG_8000;
		if (value) {
			g_Rooms[room_id].flags |= ROOMFLAG_8000;
		}
		break;
	case 7:
		g_Rooms[room_id].bitfield.b = value;
		break;
	case 8:
		g_Rooms[room_id].unk4d = value;
		break;
	case 9:
		for (i = 1; i < g_Vars.roomcount; i++) {
			if (value) {
				g_Rooms[i].flags |= ROOMFLAG_4000;
			} else {
				g_Rooms[i].flags &= ~ROOMFLAG_4000;
			}
		}
		break;
	case 10:
		func00010db0(value);
		break;
	case 11:
		func0001190c(room_id);
		break;
	case 12:
		func0f001a64(room_id, value);
		break;
	case 13:
		func00010de0(room_id);
		break;
	case 14:
		func000110bc(value);
		break;
	case 15:
		func000110ec(room_id);
		break;
	}

	g_Vars.aioffset += 6;

	return false;
}

/**
 * @cmd 01d7
 */
bool aiIfDistanceToTarget2LessThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chrGetDistanceToTarget2(g_Vars.chrdata) < distance) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 01d8
 */
bool aiIfDistanceToTarget2GreaterThan(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	f32 distance = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chrGetDistanceToTarget2(g_Vars.chrdata) > distance) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[4]);
	} else {
		g_Vars.aioffset += 5;
	}

	return false;
}

/**
 * @cmd 01d9
 */
bool aiPlaySoundFromProp(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	s16 audio_id = cmd[5] | (cmd[4] << 8);
	s32 volumemaybe = cmd[7] | (cmd[6] << 8);
	u16 unk1 = cmd[10] | (cmd[10] << 8); // @bug: Using 10 twice
	s32 channel = (s8)cmd[2];
	s16 unk2 = cmd[8];
	struct defaultobj *obj = objFindByTagId(cmd[3]);

	audioPlayFromProp(channel, audio_id, volumemaybe, obj->prop, unk2, unk1);

	g_Vars.aioffset += 11;

	return false;
}

/**
 * @cmd 01da
 */
bool aiPlayMusicContinuously(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	func0f16deb8(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01db
 */
bool aiChrKill(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->actiontype = ACT_DEAD;
		chr->act_dead.unk038 = -1;
		chr->act_dead.unk02c = 0;
		chr->act_dead.unk030 = 0;
		chr->act_dead.unk034 = 0;
		chr->act_dead.unk03c = 0;
		chr->sleep = 0;
		chr->chrflags |= CHRCFLAG_04000000 | CHRCFLAG_00010000;
	}

	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01dc
 */
bool aiRemoveWeaponFromInventory(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	currentPlayerRemoveWeapon(cmd[2]);
	g_Vars.aioffset += 3;

	return false;
}

/**
 * @cmd 01dd
 */
bool ai01dd(void)
{
	u64 value = func0004af68(osGetCount(), 64);
	value = func0004ae68(value, 3000);
	func00005b30(value);

	if (var800840c4) {
		g_Vars.aioffset += 4;
	} else {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[3]);
	}

	return false;
}

/**
 * @cmd 01de
 */
bool aiIfCoopMode(void)
{
	if (g_Vars.normmplayerisrunning == false && g_MissionConfig.iscoop) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

/**
 * @cmd 01e0
 */
bool aiRemoveReferencesToChr(void)
{
	if (g_Vars.chrdata && g_Vars.chrdata->prop) {
		u32 index = g_Vars.chrdata->prop - g_Vars.props;
		propClearReferences(index);
	}

	g_Vars.aioffset += 2;

	return false;
}

/**
 * @cmd 01b4
 */
bool ai01b4(void)
{
	if (g_Vars.chrdata && g_Vars.chrdata->prop &&
			func0f01f264(g_Vars.chrdata, &g_Vars.chrdata->prop->pos, &g_Vars.chrdata->prop->rooms[0], 0, false)) {
		u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}
