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

/**
 * @cmd 0000
 */
static u8 *aiGoToNext(u8 *cmd)
{
	cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);

	return cmd;
}

/**
 * @cmd 0001
 */
static u8 *aiGoToFirst(u8 *cmd)
{
	cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);

	return cmd;
}

/**
 * @cmd 0002
 */
static u8 *aiLabel(u8 *cmd)
{
	cmd += 3;
	return cmd;
}

/**
 * @cmd 0003
 */
static u8 *aiYield(u8 *cmd)
{
	cmd += 2;

	if (g_Vars.chrdata) {
		g_Vars.chrdata->ailist = g_Vars.ailist;
		g_Vars.chrdata->aioffset = cmd;
	} else if (g_Vars.truck) {
		g_Vars.truck->ailist = g_Vars.ailist;
		g_Vars.truck->aioffset = cmd;
	} else if (g_Vars.heli) {
		g_Vars.heli->ailist = g_Vars.ailist;
		g_Vars.heli->aioffset = cmd;
	} else if (g_Vars.hovercar) {
		g_Vars.hovercar->ailist = g_Vars.ailist;
		g_Vars.hovercar->aioffset = cmd;
	}

	return NULL;
}

/**
 * @cmd 0005
 */
static u8 *aiSetList(u8 *cmd)
{
	u32 ailistid = cmd[4] | (cmd[3] << 8);
	u8 *ailist = ailistFindById(ailistid & 0xffff);

	struct chrdata *chr = g_Vars.chrdata;

	if ((cmd[2] & 0xff) == CHR_SELF) {
		g_Vars.ailist = ailist;
		return ailist;
	}

	chr = chrFindById(chr, cmd[2]);

	if (chr) {
		chr->ailist = ailist;
		chr->aioffset = ailist;
		chr->sleep = 0;
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 0006
 */
static u8 *aiSetReturnList(u8 *cmd)
{
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

	cmd += 5;

	return cmd;
}

/**
 * @cmd 0007
 */
static u8 *aiSetShotList(u8 *cmd)
{
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

	cmd += 4;

	return cmd;
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
 * @cmd 01c2
 */
static u8 *aiSetShootingAtMeList(u8 *cmd)
{
	u16 ailistid = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata) {
		g_Vars.chrdata->aishootingatmelist = ailistid;
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 01c3
 */
static u8 *aiSetDarkRoomList(u8 *cmd)
{
	u16 ailistid = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata) {
		g_Vars.chrdata->aidarkroomlist = ailistid;
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 0008
 */
static u8 *aiReturn(u8 *cmd)
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

	return ailist;
}

/**
 * @cmd 0004
 */
static u8 *aiEndList(u8 *cmd)
{
	return NULL;
}

/**
 * @cmd 0009
 */
static u8 *aiStop(u8 *cmd)
{
	if (g_Vars.chrdata) {
		chrTryStop(g_Vars.chrdata);
	} else if (g_Vars.hovercar) {
		chopperStop(g_Vars.hovercar);
	}

	cmd += 2;

	return cmd;
}

/**
 * @cmd 000a
 */
static u8 *aiKneel(u8 *cmd)
{
	chrTryKneel(g_Vars.chrdata);
	cmd += 2;

	return cmd;
}

/**
 * @cmd 000b
 */
static u8 *aiChrDoAnimation(u8 *cmd)
{
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

		chrTryStartAnim(chr, anim_id, fstartframe, fendframe, cmd[8], cmd[9], speed);

		if (startframe == 0xfffe) {
			chr0f0220ec(chr, 1, 1);

			if (chr->prop->type == PROPTYPE_PLAYER) {
				u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
				struct player *player = g_Vars.players[playernum];
				player->vv_ground = chr->ground;
				player->vv_manground = chr->ground;
			}
		}
	}

	cmd += 12;

	return cmd;
}

/**
 * @cmd 000c
 */
static u8 *aiIfIdle(u8 *cmd)
{
	if (g_Vars.chrdata->actiontype == ACT_ANIM) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

bool func0f04e418(void)
{
	return false;
}

/**
 * @cmd 0032
 */
static u8 *aiIfStopped(u8 *cmd)
{
	if (chrIsStopped(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0033
 */
static u8 *aiIfChrDead(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if ((!chr || !chr->prop || chr->prop->type != PROPTYPE_PLAYER) && (!chr || !chr->model || chrIsDead(chr))) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0034
 */
static u8 *aiIfChrDeathAnimationFinished(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	bool pass;

	if (!chr || !chr->prop) {
		pass = true;
	} else {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
			pass = g_Vars.players[playernum]->isdead;
		} else {
			pass = (chr->actiontype == ACT_DEAD);
		}
	}

	if (pass) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 017b
 */
static u8 *aiIfChrKnockedOut(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if ((!chr || !chr->prop || chr->prop->type != PROPTYPE_PLAYER) &&
			(!chr || !chr->model || chr->actiontype == ACT_DRUGGEDKO || chr->actiontype == ACT_DRUGGEDDROP || chr->actiontype == ACT_DRUGGEDCOMINGUP)) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0035
 */
static u8 *aiIfTargetInSight(u8 *cmd)
{
	if (chrCheckTargetInSight(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 000f
 */
static u8 *aiTrySidestep(u8 *cmd)
{
	if (chrTrySidestep(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0010
 */
static u8 *aiTryJumpOut(u8 *cmd)
{
	if (chrTryJumpOut(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0011
 */
static u8 *aiTryRunSideways(u8 *cmd)
{
	if (chrTryRunSideways(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0012
 */
static u8 *aiTryAttackWalk(u8 *cmd)
{
	if (chrTryAttackWalk(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0014
 */
static u8 *aiTryAttackRoll(u8 *cmd)
{
	if (chrTryAttackRoll(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0015
 */
static u8 *aiTryAttackStand(u8 *cmd)
{
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chrTryAttackStand(g_Vars.chrdata, thingtype, thingid)) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 0016
 */
static u8 *aiTryAttackKneel(u8 *cmd)
{
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chrTryAttackKneel(g_Vars.chrdata, thingtype, thingid)) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 01ba
 */
static u8 *aiTryAttackLie(u8 *cmd)
{
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chrTryAttackLie(g_Vars.chrdata, thingtype, thingid)) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 0017
 */
static u8 *aiTryModifyAttack(u8 *cmd)
{
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if ((g_Vars.chrdata && chrTryModifyAttack(g_Vars.chrdata, thingtype, thingid)) ||
			(g_Vars.hovercar && chopperAttack(g_Vars.hovercar))) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 0018
 */
static u8 *aiFaceEntity(u8 *cmd)
{
	u32 thingid = cmd[5] | (cmd[4] << 8);
	u32 thingtype = cmd[3] | (cmd[2] << 8);

	if (chrFaceEntity(g_Vars.chrdata, thingtype, thingid)) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 0019
 */
static u8 *ai0019(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	struct coord pos = {0, 0, 0};

	if (chr && chr->prop) {
		f32 damage = gsetGetDamage((struct gset *)&cmd[4]);
		chrDamageByImpact(chr, damage, &pos, (struct gset *)&cmd[4], NULL, (s8)cmd[3]);
	}

	cmd += 8;

	return cmd;
}

/**
 * @cmd 001a
 */
static u8 *aiChrDamageChr(u8 *cmd)
{
	struct chrdata *chr1 = chrFindById(g_Vars.chrdata, cmd[2]);
	struct chrdata *chr2 = chrFindById(g_Vars.chrdata, cmd[3]);

	if (chr1 && chr2 && chr1->prop && chr2->prop) {
		struct prop *prop = chrGetHeldUsableProp(chr1, HAND_RIGHT);
		f32 damage;
		struct coord vector = {0, 0, 0};
		struct weaponobj *weapon;

		if (!prop) {
			prop = chrGetHeldUsableProp(chr1, HAND_LEFT);
		}

		if (prop) {
			vector.x = chr2->prop->pos.x - chr1->prop->pos.x;
			vector.y = chr2->prop->pos.y - chr1->prop->pos.y;
			vector.z = chr2->prop->pos.z - chr1->prop->pos.z;
			guNormalize(&vector.x, &vector.y, &vector.z);
			weapon = prop->weapon;
			damage = gsetGetDamage(&weapon->gset);
			chrDamageByImpact(chr2, damage, &vector, &weapon->gset, chr1->prop, (s8)cmd[4]);
		}
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 001b
 */
static u8 *aiConsiderGrenadeThrow(u8 *cmd)
{
	u32 value2 = cmd[5] | (cmd[4] << 8);
	u32 value1 = cmd[3] | (cmd[2] << 8);

	if (chrConsiderGrenadeThrow(g_Vars.chrdata, value1, value2)) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 0024
 */
static u8 *aiSurrender(u8 *cmd)
{
	chrTrySurrender(g_Vars.chrdata);
	cmd += 2;

	return cmd;
}

/**
 * @cmd 0025
 */
static u8 *aiFadeOut(u8 *cmd)
{
	chrFadeOut(g_Vars.chrdata);
	cmd += 2;

	return cmd;
}

/**
 * @cmd 0026
 */
static u8 *aiRemoveChr(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		chr->hidden |= 0x20;
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 0028
 */
static u8 *aiActivateAlarm(u8 *cmd)
{
	alarmActivate();
	cmd += 2;

	return cmd;
}

/**
 * @cmd 0029
 */
static u8 *aiDeactivateAlarm(u8 *cmd)
{
	alarmDeactivate();
	cmd += 2;

	return cmd;
}

/**
 * @cmd 002b
 */
static u8 *aiTryJogToTargetProp(u8 *cmd)
{
	if (chrGoToTarget(g_Vars.chrdata, GOPOSFLAG_JOG)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 002c
 */
static u8 *aiTryWalkToTargetProp(u8 *cmd)
{
	if (chrGoToTarget(g_Vars.chrdata, GOPOSFLAG_WALK)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 002d
 */
static u8 *aiTryRunToTargetProp(u8 *cmd)
{
	if (chrGoToTarget(g_Vars.chrdata, GOPOSFLAG_RUN)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 002f
 */
static u8 *aiTryJogToChr(u8 *cmd)
{
	if (chrGoToChr(g_Vars.chrdata, cmd[2], GOPOSFLAG_JOG)) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0031
 */
static u8 *aiTryRunToChr(u8 *cmd)
{
	if (chrGoToChr(g_Vars.chrdata, cmd[2], GOPOSFLAG_RUN)) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0036
 */
static u8 *aiRandom(u8 *cmd)
{
	g_Vars.chrdata->random = random() & 0xff;
	cmd += 2;

	return cmd;
}

/**
 * @cmd 0037
 */
static u8 *aiIfRandomLessThan(u8 *cmd)
{
	if ((g_Vars.chrdata && g_Vars.chrdata->random < cmd[2]) ||
			(g_Vars.hovercar && ((u8)random()) < cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0038
 */
static u8 *aiIfRandomGreaterThan(u8 *cmd)
{
	if ((g_Vars.chrdata && g_Vars.chrdata->random > cmd[2]) ||
			(g_Vars.hovercar && ((u8)random()) > cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 001d
 */
static u8 *aiJogToPad(u8 *cmd)
{
	u16 pad = cmd[3] | (cmd[2] << 8);

	chrGoToPad(g_Vars.chrdata, pad, GOPOSFLAG_JOG);
	cmd += 4;

	return cmd;
}

/**
 * @cmd 001e
 */
static u8 *aiGoToPadPreset(u8 *cmd)
{
	switch (cmd[2]) {
	case 0:
		chrGoToPad(g_Vars.chrdata, g_Vars.chrdata->padpreset1, GOPOSFLAG_WALK);
		break;
	case 1:
		chrGoToPad(g_Vars.chrdata, g_Vars.chrdata->padpreset1, GOPOSFLAG_JOG);
		break;
	default:
		chrGoToPad(g_Vars.chrdata, g_Vars.chrdata->padpreset1, GOPOSFLAG_RUN);
		break;
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 001f
 */
static u8 *aiWalkToPad(u8 *cmd)
{
	u16 pad = cmd[3] | (cmd[2] << 8);

	chrGoToPad(g_Vars.chrdata, pad, GOPOSFLAG_WALK);
	cmd += 4;

	return cmd;
}

/**
 * @cmd 0020
 */
static u8 *aiRunToPad(u8 *cmd)
{
	u16 pad = cmd[3] | (cmd[2] << 8);

	chrGoToPad(g_Vars.chrdata, pad, GOPOSFLAG_RUN);
	cmd += 4;

	return cmd;
}

/**
 * @cmd 0021
 */
static u8 *aiSetPath(u8 *cmd)
{
	chrSetPath(g_Vars.chrdata, cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0022
 */
static u8 *aiStartPatrol(u8 *cmd)
{
	chrTryStartPatrol(g_Vars.chrdata);
	cmd += 2;

	return cmd;
}

/**
 * @cmd 0039
 */
static u8 *aiIfCanHearAlarm(u8 *cmd)
{
	if (chrCanHearAlarm(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0023
 */
static u8 *aiIfPatrolling(u8 *cmd)
{
	if (g_Vars.chrdata->actiontype == ACT_PATROL
			|| (g_Vars.chrdata->actiontype == ACT_GOPOS && g_Vars.chrdata->act_gopos.flags & GOPOSFLAG_FORPATHSTART)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 003a
 */
static u8 *aiIfAlarmActive(u8 *cmd)
{
	if (alarmIsActive()) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 003c
 */
static u8 *aiIfHearsTarget(u8 *cmd)
{
	if (chrIsHearingTarget(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 003d
 */
static u8 *aiIfSawInjury(u8 *cmd)
{
	if (chrSawInjury(g_Vars.chrdata, cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 003e
 */
static u8 *aiIfSawDeath(u8 *cmd)
{
	if (chrSawDeath(g_Vars.chrdata, cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 003f
 */
static u8 *aiIfCanSeeTarget(u8 *cmd)
{
	if ((g_Vars.chrdata && chrCanSeeTarget(g_Vars.chrdata)) ||
			(g_Vars.hovercar && chopperCheckTargetInFov(g_Vars.hovercar, 64) && chopperCheckTargetInSight(g_Vars.hovercar))) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 017a
 */
static u8 *aiIfCanSeeAttackTarget(u8 *cmd)
{
	if ((g_Vars.chrdata && g_Vars.chrdata->prop && chrCanSeeAttackTarget(g_Vars.chrdata, &g_Vars.chrdata->prop->pos, g_Vars.chrdata->prop->rooms, true))
			|| (g_Vars.hovercar && chopperCheckTargetInFov(g_Vars.hovercar, 64) && chopperCheckTargetInSight(g_Vars.hovercar))) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0041
 */
static u8 *aiIfNearlyInTargetsSight(u8 *cmd)
{
	u32 distance = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if (chrIsNearlyInTargetsSight(g_Vars.chrdata, distance)) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 0044
 */
static u8 *aiIfHeardTargetRecently(u8 *cmd)
{
	if (chrHeardTargetRecently(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0045
 */
static u8 *ai0045(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chrHasLineOfSightToPos(g_Vars.chrdata, &chr->prop->pos, chr->prop->rooms)) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0046
 */
static u8 *aiIfNeverBeenOnScreen(u8 *cmd)
{
	if ((g_Vars.chrdata->chrflags & CHRCFLAG_EVERONSCREEN) == 0) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0047
 */
static u8 *aiIfOnScreen(u8 *cmd)
{
	if (g_Vars.chrdata->prop->flags & (PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0049
 */
static u8 *aiIfRoomIsOnScreen(u8 *cmd)
{
	u16 pad_id = cmd[3] | (cmd[2] << 8);
	s32 room_id = chrGetPadRoom(g_Vars.chrdata, pad_id);

	if (room_id >= 0 && roomIsOnscreen(room_id)) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 004a
 */
static u8 *ai004a(u8 *cmd)
{
	if (chrCanSeeTargetWithExtraCheck(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 004b
 */
static u8 *aiIfNearMiss(u8 *cmd)
{
	if (chrResetNearMiss(g_Vars.chrdata)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 004c
 */
static u8 *aiIfSeesSuspiciousItem(u8 *cmd)
{
	s16 *ptr;
	ubool pass = false;
	struct prop *prop;
	struct defaultobj *obj;
	s16 propnums[256];
	struct prop *chrprop = g_Vars.chrdata->prop;

	roomGetProps(chrprop->rooms, &propnums[0], 256);

	ptr = &propnums[0];

	while (*ptr >= 0) {
		prop = &g_Vars.props[*ptr];
		obj = prop->obj;

		if (prop->type == PROPTYPE_WEAPON) {
			if ((obj->hidden & OBJHFLAG_SUSPICIOUS) && chrCanSeeProp(g_Vars.chrdata, prop)) {
				pass = true;
			}
		} else if (prop->type == PROPTYPE_OBJ) {
			if (((obj->hidden & OBJHFLAG_SUSPICIOUS) || !objIsHealthy(obj))
					&& chrCanSeeProp(g_Vars.chrdata, prop)) {
				pass = true;
			}
		} else if (prop->type == PROPTYPE_EXPLOSION) {
			if (chrCanSeeProp(g_Vars.chrdata, prop)) {
				pass = true;
			}
		}

		ptr++;
	}

	if (pass) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 004e
 */
static u8 *aiIfCheckFovWithTarget(u8 *cmd)
{
	bool pass;

	if (cmd[4] == 0) {
		if (cmd[3]) {
			pass = chrIsInTargetsFovX(g_Vars.chrdata, cmd[2]);
		} else {
			pass = chrIsVerticalAngleToTargetWithin(g_Vars.chrdata, cmd[2]);
		}
	} else {
		pass = g_Vars.chrdata->yvisang && chrIsVerticalAngleToTargetWithin(g_Vars.chrdata, g_Vars.chrdata->yvisang) == 0;
	}

	if (pass) {
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd += 7;
	}

	return cmd;
}

/**
 * @cmd 004d
 */
static u8 *aiIfTargetInFovLeft(u8 *cmd)
{
	if (chrGetAngleToTarget(g_Vars.chrdata) < cmd[2] * M_BADTAU * 0.00390625f) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 004f
 */
static u8 *aiIfTargetOutOfFovLeft(u8 *cmd)
{
	if (chrGetAngleToTarget(g_Vars.chrdata) > cmd[2] * M_BADTAU * 0.00390625f) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0050
 */
static u8 *aiIfTargetInFov(u8 *cmd)
{
	if (chrIsTargetInFov(g_Vars.chrdata, cmd[2], 0)) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0052
 */
static u8 *aiIfDistanceToTargetLessThan(u8 *cmd)
{
	f32 distance = (cmd[3] | (cmd[2] << 8)) * (f32)10;

	if (chrGetDistanceToTarget(g_Vars.chrdata) < distance) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0053
 */
static u8 *aiIfDistanceToTargetGreaterThan(u8 *cmd)
{
	f32 distance = (cmd[3] | (cmd[2] << 8)) * (f32)10;

	if (chrGetDistanceToTarget(g_Vars.chrdata) > distance) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0054
 */
static u8 *aiIfChrDistanceToPadLessThan(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

#if VERSION >= VERSION_NTSC_1_0
	s32 padnum = (cmd[6] | (cmd[5] << 8)) & 0xffff;
	f32 value = (cmd[4] | (cmd[3] << 8)) * 10.0f;
	s32 realpadnum = padnum;

	if (padnum == 9000) {
		realpadnum = (u16) g_Vars.chrdata->padpreset1;
	}

	if (chr && realpadnum < 9000 && chrGetDistanceToPad(chr, realpadnum) < value) {
		cmd = AILABEL(g_Vars.ailist, cmd[7], cmd[8]);
	} else {
		cmd += 9;
	}
#else
	u16 padnum = cmd[6] | (cmd[5] << 8);
	f32 value = (cmd[4] | (cmd[3] << 8)) * 10.0f;

	if (padnum == 9000) {
		padnum = g_Vars.chrdata->padpreset1;
	}

	if (chr && chrGetDistanceToPad(chr, padnum) < value) {
		cmd = AILABEL(g_Vars.ailist, cmd[7], cmd[8]);
	} else {
		cmd += 9;
	}
#endif

	return cmd;
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * @cmd 01df
 */
static u8 *aiIfChrSameFloorDistanceToPadLessThan(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	u16 padnum = cmd[6] | (cmd[5] << 8);
	f32 distance = (cmd[4] | (cmd[3] << 8)) * 10.0f;
	s32 padnum2;

	if (padnum == 9000) {
		padnum = g_Vars.chrdata->padpreset1;
	}

	padnum2 = padnum;

	if (chr && chrGetSameFloorDistanceToPad(chr, padnum2 & 0xffffffff) < distance) {
		cmd = AILABEL(g_Vars.ailist, cmd[7], cmd[8]);
	} else {
		cmd += 9;
	}

	return cmd;
}
#endif

/**
 * @cmd 0055
 */
static u8 *aiIfChrDistanceToPadGreaterThan(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	u16 padnum = cmd[6] | (cmd[5] << 8);
	f32 distance = (cmd[4] | (cmd[3] << 8)) * 10.0f;

	if (padnum == 9000) {
		padnum = g_Vars.chrdata->padpreset1;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (chr && padnum < 9000 && chrGetDistanceToPad(chr, padnum) > distance)
#else
	if (chr && chrGetDistanceToPad(chr, padnum) > distance)
#endif
	{
		cmd = AILABEL(g_Vars.ailist, cmd[7], cmd[8]);
	} else {
		cmd += 9;
	}

	return cmd;
}

/**
 * @cmd 0056
 */
static u8 *aiIfDistanceToChrLessThan(u8 *cmd)
{
	f32 cutoff = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chrGetDistanceToChr(g_Vars.chrdata, cmd[4]) < cutoff) {
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd += 7;
	}

	return cmd;
}

/**
 * @cmd 0057
 */
static u8 *aiIfDistanceToChrGreaterThan(u8 *cmd)
{
	f32 cutoff = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chrGetDistanceToChr(g_Vars.chrdata, cmd[4]) > cutoff) {
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd += 7;
	}

	return cmd;
}

/**
 * @cmd 0059
 */
static u8 *aiIfDistanceFromTargetToPadLessThan(u8 *cmd)
{
	u16 pad = cmd[5] | (cmd[4] << 8);
	f32 value = (cmd[3] | (cmd[2] << 8)) * 10.0f;

	if (chrGetDistanceFromTargetToPad(g_Vars.chrdata, pad) < value) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 005b
 */
static u8 *aiIfChrInRoom(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	u16 pad_id = cmd[5] | (cmd[4] << 8);
	s32 room = chrGetPadRoom(g_Vars.chrdata, pad_id);

	if ((cmd[3] == 0 && room >= 0 && chr && chr->prop && chr->prop->rooms[0] == room)
			|| (cmd[3] == 1 && chr && chr->prop && chr->prop->rooms[0] == g_Vars.chrdata->roomtosearch)) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
		return cmd;
	}

	if (cmd[3] == 2 && stageGetIndex(g_Vars.stagenum) == STAGEINDEX_G5BUILDING) {
		s32 i;
		bool pass = false;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.players[i]->eyespy && g_Vars.players[i]->eyespy->prop
#if VERSION >= VERSION_NTSC_1_0
					&& chrGetDistanceToPad(g_Vars.players[i]->eyespy->prop->chr, pad_id) < 150.0f
#else
					&& chrGetDistanceToPad(g_Vars.players[i]->eyespy->prop->chr, 0x4d) < 150.0f
#endif
					) {
				pass = true;
			}
		}

		if (pass == true) {
			cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
		} else {
			cmd += 8;
		}

		return cmd;
	}

	cmd += 8;

	return cmd;
}

/**
 * @cmd 005d
 */
static u8 *aiIfChrHasObject(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[3]);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	s32 hasprop = false;

	if (obj && obj->prop && chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		s32 prevplayernum = g_Vars.currentplayernum;
		setCurrentPlayerNum(playermgrGetPlayerNumByProp(chr->prop));
		hasprop = invHasProp(obj->prop);
		setCurrentPlayerNum(prevplayernum);
	}

	if (hasprop) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 005e
 */
static u8 *aiIfWeaponThrown(u8 *cmd)
{
	if (weaponFindLanded(cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 005f
 */
static u8 *aiIfWeaponThrownOnObject(u8 *cmd)
{
	struct bytelist *cmd2 = (struct bytelist *)(cmd);
	struct defaultobj *obj = objFindByTagId(cmd2->b3);
	bool pass = false;

	if (obj && obj->prop) {
		struct prop *prop = obj->prop->child;

		while (prop) {
			if (prop->type == PROPTYPE_WEAPON) {
				struct weaponobj *weapon = prop->weapon;

				if (weapon->weaponnum == cmd2->b2) {
					pass = true;
				}
			}

			prop = prop->next;
		}
	}

	if (pass) {
		cmd = AILABEL(g_Vars.ailist, cmd2->b4, cmd2->b5);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0060
 */
static u8 *aiIfChrHasWeaponEquipped(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	bool passes = false;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);

		if (bgunGetWeaponNum(HAND_RIGHT) == cmd[3]) {
			passes = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	if (passes) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0061
 */
static u8 *aiIfGunUnclaimed(u8 *cmd)
{
	if (cmd[3] == 0) {
		struct defaultobj *obj = objFindByTagId(cmd[2]);

		if (obj && obj->prop) {
			cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
		} else {
			cmd += 6;
		}
	} else {
		struct weaponobj *weapon = g_Vars.chrdata->gunprop->weapon;

		if (weapon && weapon->base.prop) {
			weapon->base.flags |= OBJFLAG_00400000;
			cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
		} else {
			cmd += 6;
		}
	}

	return cmd;
}

/**
 * @cmd 0062
 */
static u8 *aiIfObjectHealthy(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && objIsHealthy(obj)) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0063
 */
static u8 *aiIfChrActivatedObject(u8 *cmd)
{
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
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0066
 */
static u8 *aiDestroyObject(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && objGetDestroyedLevel(obj) == 0) {
		struct defaultobj *entity = obj->prop->obj;

		if (entity->modelnum == MODEL_ELVIS_SAUCER) {
			obj->flags = (obj->flags & ~OBJFLAG_00010000) | OBJFLAG_INVINCIBLE;
			explosionCreateSimple(entity->prop, &entity->prop->pos, entity->prop->rooms, EXPLOSIONTYPE_LAPTOP, 0);
			smokeCreateAtProp(entity->prop, SMOKETYPE_UFO);
		} else {
			f32 damage = ((obj->maxdamage - obj->damage) + 1) / 250.0f;
			objDamage(obj, damage, &obj->prop->pos, WEAPON_REMOTEMINE, -1);
		}
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 0068
 */
static u8 *aiChrDropItems(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		chrDropConcealedItems(chr);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 0069
 */
static u8 *aiChrDropWeapon(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		u32 weaponnum;
		setCurrentPlayerNum(playernum);
		weaponnum = bgunGetWeaponNum(HAND_RIGHT);
		invRemoveItemByNum(weaponnum);
		bgunCycleBack();
		setCurrentPlayerNum(prevplayernum);
	} else if (chr && chr->prop) {
		if (chr->weapons_held[0]) {
			objSetDropped(chr->weapons_held[0], DROPTYPE_DEFAULT);
			chr->hidden |= CHRHFLAG_00000001;
		}

		if (chr->weapons_held[1]) {
			objSetDropped(chr->weapons_held[1], DROPTYPE_DEFAULT);
			chr->hidden |= CHRHFLAG_00000001;
		}
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 006a
 */
static u8 *aiGiveObjectToChr(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[3]);

	if (obj && obj->prop && chr && chr->prop) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 something;
			u32 prevplayernum = g_Vars.currentplayernum;
			struct defaultobj *obj2 = obj->prop->obj;
			u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
			setCurrentPlayerNum(playernum);

#if VERSION >= VERSION_NTSC_1_0
			if (obj->prop->parent) {
				objDetach(obj->prop);
				objFreeEmbedmentOrProjectile(obj->prop);
				propActivate(obj->prop);
			}
#endif

			something = propPickupByPlayer(obj->prop, 0);
			propExecuteTickOperation(obj->prop, something);
			playernum = playermgrGetPlayerNumByProp(chr->prop);
			obj2->hidden = (playernum << 28) | (obj2->hidden & 0x0fffffff);
			setCurrentPlayerNum(prevplayernum);
		} else {
			if (obj->prop->parent) {
				objDetach(obj->prop);
			} else {
				propDeregisterRooms(obj->prop);
				propDelist(obj->prop);
				propDisable(obj->prop);
			}

			if (obj->type != OBJTYPE_WEAPON || chrEquipWeapon((struct weaponobj *) obj, chr) == 0) {
				propReparent(obj->prop, chr->prop);
			}
		}
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 006b
 */
static u8 *aiObjectMoveToPad(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	u16 padnum = cmd[4] | (cmd[3] << 8);
	Mtxf matrix;
	struct pad *pad;
	s16 rooms[2];

	if (obj && obj->prop) {
		pad = &g_Pads[padnum];
		mtx00016d58(&matrix,
				0, 0, 0,
				-pad->look.x, -pad->look.y, -pad->look.z,
				pad->up.x, pad->up.y, pad->up.z);

		if (obj->model) {
			mtx00015f04(obj->model->scale, &matrix);
		}

		rooms[0] = pad->room;
		rooms[1] = -1;
		func0f06a730(obj, &pad->pos, &matrix, rooms, &pad->pos);
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 006c
 */
static u8 *aiOpenDoor(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		if (!doorCallLift(obj->prop, false)) {
			struct doorobj *door = (struct doorobj *) obj;
			doorsRequestMode(door, DOORMODE_OPENING);
		}
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 006d
 */
static u8 *aiCloseDoor(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		doorsRequestMode(door, DOORMODE_CLOSING);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 006e
 */
static u8 *aiIfDoorState(u8 *cmd)
{
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
		} else if (door->mode == DOORMODE_OPENING || door->mode == DOORMODE_WAITING) {
			pass = (cmd[3] & DOORSTATE_OPENING) != 0;
		} else if (door->mode == DOORMODE_CLOSING) {
			pass = (cmd[3] & DOORSTATE_CLOSING) != 0;
		}
	}

	if (pass) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0070
 */
static u8 *aiLockDoor(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		u8 bits = cmd[3];
		door->keyflags = door->keyflags | bits;
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 0071
 */
static u8 *aiUnlockDoor(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		u8 bits = cmd[3];
		door->keyflags = door->keyflags & ~bits;
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 0072
 */
static u8 *aiIfDoorLocked(u8 *cmd)
{
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
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0073
 */
static u8 *aiIfObjectiveComplete(u8 *cmd)
{
	if (cmd[2] < objectiveGetCount() &&
			objectiveCheck(cmd[2]) == OBJECTIVE_COMPLETE &&
			objectiveGetDifficultyBits(cmd[2]) & (1 << lvGetDifficulty())) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0074
 */
static u8 *aiIfObjectiveFailed(u8 *cmd)
{
	if (cmd[2] < objectiveGetCount() &&
			objectiveCheck(cmd[2]) == OBJECTIVE_FAILED &&
			objectiveGetDifficultyBits(cmd[2]) & (1 << lvGetDifficulty())) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0075
 */
static u8 *ai0075(u8 *cmd)
{
	if (func0f04a4ec(g_Vars.chrdata, cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0076
 */
static u8 *aiSetPadPresetToTargetQuadrant(u8 *cmd)
{
	if (chrSetPadPresetToWaypointWithinTargetQuadrant(g_Vars.chrdata, cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 007d
 */
static u8 *aiIfNumArghsLessThan(u8 *cmd)
{
	if (chrGetNumArghs(g_Vars.chrdata) < cmd[2]) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 007e
 */
static u8 *aiIfNumArghsGreaterThan(u8 *cmd)
{
	if (chrGetNumArghs(g_Vars.chrdata) > cmd[2]) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 010f
 */
static u8 *aiIfChrShieldLessThan(u8 *cmd)
{
	f32 value = (cmd[4] | (cmd[3] << 8)) * 0.1f;
	struct chrdata *chr = chrFindById(g_Vars.chrdata,cmd[2]);

	if (chr && chrGetShield(chr) < value) {
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd = cmd + 7;
	}

	return cmd;
}

/**
 * @cmd 0083
 */
static u8 *aiIfInjured(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_JUST_INJURED)) {
		chr->chrflags &= ~CHRCFLAG_JUST_INJURED;
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd = cmd + 5;
	}

	return cmd;
}

/**
 * @cmd 0168
 */
static u8 *aiIfShieldDamaged(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_SHIELDDAMAGED)) {
		chr->chrflags &= ~CHRCFLAG_SHIELDDAMAGED;
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd = cmd + 5;
	}

	return cmd;
}

/**
 * @cmd 0077
 */
static u8 *aiIfDifficultyLessThan(u8 *cmd)
{
	if (lvGetDifficulty() < cmd[2]) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0078
 */
static u8 *aiIfDifficultyGreaterThan(u8 *cmd)
{
	if (lvGetDifficulty() > cmd[2]) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 007b
 */
static u8 *aiIfStageIsNot(u8 *cmd)
{
	if (mainGetStageNum() != cmd[2]) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0084
 */
static u8 *aiSetMorale(u8 *cmd)
{
	g_Vars.chrdata->morale = cmd[2];
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0085
 */
static u8 *aiAddMorale(u8 *cmd)
{
	incrementByte(&g_Vars.chrdata->morale, cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0087
 */
static u8 *aiSubtractMorale(u8 *cmd)
{
	decrementByte(&g_Vars.chrdata->morale, cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0088
 */
static u8 *aiIfMoraleLessThan(u8 *cmd)
{
	if (g_Vars.chrdata->morale < cmd[2]) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 008a
 */
static u8 *aiSetAlertness(u8 *cmd)
{
	g_Vars.chrdata->alertness = cmd[2];
	cmd += 3;

	return cmd;
}

/**
 * @cmd 008b
 */
static u8 *aiAddAlertness(u8 *cmd)
{
	incrementByte(&g_Vars.chrdata->alertness, cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 008c
 */
static u8 *aiChrAddAlertness(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[3]);

	if (chr && chr->prop) {
		incrementByte(&chr->alertness, cmd[2]);
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 008e
 */
static u8 *aiIfAlertness(u8 *cmd)
{
	if ((g_Vars.chrdata->alertness < cmd[2] && cmd[3] == 0) ||
			(cmd[2] < g_Vars.chrdata->alertness && cmd[3] == 1)) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 008f
 */
static u8 *aiIfChrAlertnessLessThan(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[3]);

	if (chr && chr->alertness < cmd[2]) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0092
 */
static u8 *aiSetHearDistance(u8 *cmd)
{
	f32 distance = (cmd[3] | (cmd[2] << 8)) / 1000.0f;
	g_Vars.chrdata->hearingscale = distance;

	cmd += 4;

	return cmd;
}

/**
 * @cmd 0093
 */
static u8 *aiSetViewDistance(u8 *cmd)
{
	if (!cheatIsActive(CHEAT_PERFECTDARKNESS)) {
		g_Vars.chrdata->visionrange = cmd[2];
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 0094
 */
static u8 *aiSetGrenadeProbability(u8 *cmd)
{
	g_Vars.chrdata->grenadeprob = cmd[2];
	cmd += + 3;

	return cmd;
}

/**
 * @cmd 0095
 */
static u8 *aiSetChrNum(u8 *cmd)
{
	chrSetChrnum(g_Vars.chrdata, cmd[2]);
	g_Vars.chrdata->chrnum = cmd[2];
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0096
 */
static u8 *aiSetMaxDamage(u8 *cmd)
{
	f32 maxdamage = (cmd[4] | (cmd[3] << 8)) * 0.1f;

	if (g_Vars.hovercar) {
		chopperSetMaxDamage(g_Vars.hovercar, maxdamage);
	} else {
		struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

		if (chr && chr->prop && !chrIsDead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP) {
			chrSetMaxDamage(chr, maxdamage);
		}
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 0097
 */
static u8 *aiAddHealth(u8 *cmd)
{
	f32 amount = (cmd[3] | (cmd[2] << 8)) * 0.1f;

	chrAddHealth(g_Vars.chrdata, amount);

	cmd += 4;

	return cmd;
}

/**
 * @cmd 010e
 */
static u8 *aiSetShield(u8 *cmd)
{
	f32 amount = (cmd[3] | (cmd[2] << 8)) * 0.1f;

	if (cheatIsActive(CHEAT_ENEMYSHIELDS)) {
		amount = amount < 8 ? 8 : amount;
	}

	chrSetShield(g_Vars.chrdata, amount);

	cmd += 4;

	return cmd;
}

/**
 * @cmd 0098
 */
static u8 *aiSetReactionSpeed(u8 *cmd)
{
	s8 *cmd2 = (s8 *)cmd;

	g_Vars.chrdata->speedrating = cmd2[2];
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0099
 */
static u8 *aiSetRecoverySpeed(u8 *cmd)
{
	s8 *cmd2 = (s8 *)cmd;

	g_Vars.chrdata->arghrating = cmd2[2];
	cmd += 3;

	return cmd;
}

/**
 * @cmd 009a
 */
static u8 *aiSetAccuracy(u8 *cmd)
{
	s8 *cmd2 = (s8 *)cmd;

	g_Vars.chrdata->accuracyrating = cmd2[2];
	cmd += 3;

	return cmd;
}

/**
 * @cmd 01c6
 */
static u8 *aiSetDodgeRating(u8 *cmd)
{
	s8 *cmd2 = (s8 *)cmd;

	if (cmd[2] == 0) {
		g_Vars.chrdata->dodgerating = cmd2[3];
	} else if (cmd[2] == 1) {
		g_Vars.chrdata->maxdodgerating = cmd2[3];
	} else {
		g_Vars.chrdata->dodgerating = cmd2[3];
		g_Vars.chrdata->maxdodgerating = cmd2[3];
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 01c7
 */
static u8 *aiSetUnarmedDodgeRating(u8 *cmd)
{
	s8 *cmd2 = (s8 *)cmd;

	g_Vars.chrdata->unarmeddodgerating = cmd2[2];
	cmd += 3;

	return cmd;
}

/**
 * @cmd 009b
 */
static u8 *aiSetFlag(u8 *cmd)
{
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chrSetFlags(g_Vars.chrdata, flags, cmd[6]);

	cmd += 7;

	return cmd;
}

/**
 * @cmd 009c
 */
static u8 *aiUnsetFlag(u8 *cmd)
{
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chrUnsetFlags(g_Vars.chrdata, flags, cmd[6]);

	cmd += 7;

	return cmd;
}

/**
 * @cmd 009d
 */
static u8 *aiIfHasFlag(u8 *cmd)
{
	bool result;
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	result = chrHasFlag(g_Vars.chrdata, flags, cmd[7]);

	if (cmd[6] == 0) {
		result = !result;
	}

	if (result) {
		cmd = AILABEL(g_Vars.ailist, cmd[8], cmd[9]);
	} else {
		cmd += 10;
	}

	return cmd;
}

/**
 * @cmd 009e
 */
static u8 *aiChrSetFlag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	chrSetFlagsById(g_Vars.chrdata, cmd[2], flags, cmd[7]);
	cmd += 8;

	return cmd;
}

/**
 * @cmd 009f
 */
static u8 *aiChrUnsetFlag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	chrUnsetFlagsById(g_Vars.chrdata, cmd[2], flags, cmd[7]);
	cmd += 8;

	return cmd;
}

/**
 * @cmd 00a0
 */
static u8 *aiIfChrHasFlag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);

	if (chrHasFlagById(g_Vars.chrdata, cmd[2], flags, cmd[7])) {
		cmd = AILABEL(g_Vars.ailist, cmd[8], cmd[9]);
	} else {
		cmd += 10;
	}

	return cmd;
}

/**
 * @cmd 00a1
 */
static u8 *aiSetStageFlag(u8 *cmd)
{
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chrSetStageFlag(g_Vars.chrdata, flags);
	cmd += 6;

	return cmd;
}

/**
 * @cmd 00a2
 */
static u8 *aiUnsetStageFlag(u8 *cmd)
{
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	chrUnsetStageFlag(g_Vars.chrdata, flags);
	cmd += 6;

	return cmd;
}

/**
 * @cmd 00a3
 */
static u8 *aiIfStageFlagEq(u8 *cmd)
{
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if ((chrHasStageFlag(g_Vars.chrdata, flags) && cmd[6] == 1) ||
			(!chrHasStageFlag(g_Vars.chrdata, flags) && cmd[6] == 0)) {
		cmd = AILABEL(g_Vars.ailist, cmd[7], cmd[8]);
	} else {
		cmd += 9;
	}

	return cmd;
}

/**
 * @cmd 00a4
 */
static u8 *aiSetChrflag(u8 *cmd)
{
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	g_Vars.chrdata->chrflags |= flags;
	cmd += 6;

	return cmd;
}

/**
 * @cmd 00a5
 */
static u8 *aiUnsetChrflag(u8 *cmd)
{
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	g_Vars.chrdata->chrflags &= ~flags;
	cmd += 6;

	return cmd;
}

/**
 * @cmd 00a6
 */
static u8 *aiIfHasChrflag(u8 *cmd)
{
	u32 flags = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);

	if ((g_Vars.chrdata->chrflags & flags) == flags) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 00a7
 */
static u8 *aiChrSetChrflag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->chrflags |= flags;
	}

	cmd += 7;

	return cmd;
}

/**
 * @cmd 00a8
 */
static u8 *aiChrUnsetChrflag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->chrflags &= ~flags;
	}

	cmd += 7;

	return cmd;
}

/**
 * @cmd 00a9
 */
static u8 *aiIfChrHasChrflag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & flags) == flags) {
		cmd = AILABEL(g_Vars.ailist, cmd[7], cmd[8]);
	} else {
		cmd += 9;
	}

	return cmd;
}

/**
 * @cmd 011b
 */
static u8 *aiChrSetHiddenFlag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->hidden |= flags;
	}

	cmd += 7;

	return cmd;
}

/**
 * @cmd 011c
 */
static u8 *aiChrUnsetHiddenFlag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->hidden &= ~flags;
	}

	cmd += 7;

	return cmd;
}

/**
 * @cmd 011d
 */
static u8 *aiIfChrHasHiddenFlag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->hidden & flags) == flags) {
		cmd = AILABEL(g_Vars.ailist, cmd[7], cmd[8]);
	} else {
		cmd += 9;
	}

	return cmd;
}

/**
 * @cmd 00aa
 */
static u8 *aiSetObjFlag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags |= flags;
	}

	cmd += 7;

	return cmd;
}

/**
 * @cmd 00ab
 */
static u8 *aiUnsetObjFlag(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags &= ~flags;
	}

	cmd += 7;

	return cmd;
}

/**
 * @cmd 00ad
 */
static u8 *aiSetObjFlag2(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags2 |= flags;
	}

	cmd += 7;

	return cmd;
}

/**
 * @cmd 00ae
 */
static u8 *aiUnsetObjFlag2(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags2 &= ~flags;
	}

	cmd += 7;

	return cmd;
}

/**
 * @cmd 00af
 */
static u8 *aiIfObjHasFlag2(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && (obj->flags2 & flags) == flags) {
		cmd = AILABEL(g_Vars.ailist, cmd[7], cmd[8]);
	} else {
		cmd += 9;
	}

	return cmd;
}

/**
 * @cmd 0118
 */
static u8 *aiSetObjFlag3(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags3 |= flags;
	}

	cmd += 7;

	return cmd;
}

/**
 * @cmd 0119
 */
static u8 *aiUnsetObjFlag3(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->flags3 &= ~flags;
	}

	cmd += 7;

	return cmd;
}

/**
 * @cmd 011a
 */
static u8 *aiIfObjHasFlag3(u8 *cmd)
{
	u32 flags = (cmd[4] << 16) | (cmd[5] << 8) | cmd[6] | (cmd[3] << 24);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && (obj->flags3 & flags) == flags) {
		cmd = AILABEL(g_Vars.ailist, cmd[7], cmd[8]);
	} else {
		cmd += 9;
	}

	return cmd;
}

/**
 * @cmd 00b0
 */
static u8 *aiSetChrPreset(u8 *cmd)
{
	chrSetChrPreset(g_Vars.chrdata, cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 00b1
 */
static u8 *aiSetChrTarget(u8 *cmd)
{
	chrSetChrPresetByChrnum(g_Vars.chrdata, cmd[2], cmd[3]);
	cmd += 4;

	return cmd;
}

/**
 * @cmd 00b2
 */
static u8 *aiSetPadPreset(u8 *cmd)
{
	u16 pad_id = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata) {
		chrSetPadPreset(g_Vars.chrdata, pad_id);
	} else if (g_Vars.heli) {
		g_Vars.heli->base.pad = pad_id;
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 00b6
 */
static u8 *aiRestartTimer(u8 *cmd)
{
	if (g_Vars.chrdata) {
		chrRestartTimer(g_Vars.chrdata);
	} else if (g_Vars.hovercar) {
		chopperRestartTimer(g_Vars.hovercar);
	}

	cmd += 2;

	return cmd;
}

/**
 * @cmd 00b7
 */
static u8 *aiResetTimer(u8 *cmd)
{
	g_Vars.chrdata->timer60 = 0;
	cmd += 2;

	return cmd;
}

/**
 * @cmd 00b8
 */
static u8 *aiPauseTimer(u8 *cmd)
{
	g_Vars.chrdata->hidden &= ~CHRHFLAG_TIMER_RUNNING;
	cmd += 2;

	return cmd;
}

/**
 * @cmd 00b9
 */
static u8 *aiResumeTimer(u8 *cmd)
{
	g_Vars.chrdata->hidden |= CHRHFLAG_TIMER_RUNNING;
	cmd += 2;

	return cmd;
}

/**
 * @cmd 00bc
 */
static u8 *aiIfTimerLessThan(u8 *cmd)
{
	s32 value = (cmd[3] << 8) | cmd[4] | (cmd[2] << 16);

	if ((g_Vars.chrdata && g_Vars.chrdata->timer60 < value)
			|| (g_Vars.hovercar && chopperGetTimer(g_Vars.hovercar) < value)) {
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd += 7;
	}

	return cmd;
}

/**
 * @cmd 00bd
 */
static u8 *aiIfTimerGreaterThan(u8 *cmd)
{
	s32 value = (cmd[3] << 8) | cmd[4] | (cmd[2] << 16);

	if ((g_Vars.chrdata && g_Vars.chrdata->timer60 > value)
			|| (g_Vars.hovercar && chopperGetTimer(g_Vars.hovercar) > value)) {
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd += 7;
	}

	return cmd;
}

/**
 * @cmd 00be
 */
static u8 *aiShowCountdownTimer(u8 *cmd)
{
	countdownTimerSetVisible(COUNTDOWNTIMERREASON_AI, true);
	cmd += 2;

	return cmd;
}

/**
 * @cmd 00bf
 */
static u8 *aiHideCountdownTimer(u8 *cmd)
{
	countdownTimerSetVisible(COUNTDOWNTIMERREASON_AI, false);
	cmd += 2;

	return cmd;
}

/**
 * @cmd 00c0
 */
static u8 *aiSetCountdownTimerValue(u8 *cmd)
{
	f32 seconds = cmd[3] | (cmd[2] << 8);

	countdownTimerSetValue60(seconds * 60);
	cmd += 4;

	return cmd;
}

/**
 * @cmd 00c1
 */
static u8 *aiStopCountdownTimer(u8 *cmd)
{
	countdownTimerSetRunning(false);
	cmd += 2;

	return cmd;
}

/**
 * @cmd 00c2
 */
static u8 *aiStartCountdownTimer(u8 *cmd)
{
	countdownTimerSetRunning(true);
	cmd += 2;

	return cmd;
}

/**
 * @cmd 00c4
 */
static u8 *aiIfCountdownTimerLessThan(u8 *cmd)
{
	f32 value = cmd[3] | (cmd[2] << 8);

	if (countdownTimerGetValue60() < value * 60) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 00c5
 */
static u8 *aiIfCountdownTimerGreaterThan(u8 *cmd)
{
	f32 value = cmd[3] | (cmd[2] << 8);

	if (countdownTimerGetValue60() > value * 60) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 00c6
 */
static u8 *aiSpawnChrAtPad(u8 *cmd)
{
	struct bytelist *cmd2 = (struct bytelist *)(cmd);
	u16 pad = cmd2->b4 << 8 | cmd2->b5;
	u32 spawnflags = cmd2->b8 << 24 | cmd2->b9 << 16 | cmd2->b10 << 8 | cmd2->b11;
	u16 ailistid = cmd2->b6 << 8 | cmd2->b7;
	u8 *ailist = ailistFindById(ailistid);

	if (spawnflags);

	if (chrSpawnAtPad(g_Vars.chrdata, cmd2->b2, (s8)cmd2->b3, pad, ailist, spawnflags)) {
		cmd = AILABEL(g_Vars.ailist, cmd2->b12, cmd2->b13);
	} else {
		cmd += 14;
	}

	return cmd;
}

/**
 * @cmd 00c7
 */
static u8 *aiSpawnChrAtChr(u8 *cmd)
{
	u32 spawnflags = (cmd[8] << 16) | (cmd[9] << 8) | cmd[10] | (cmd[7] << 24);
	u16 ailistid = cmd[6] | (cmd[5] << 8);
	u8 *ailist = ailistFindById(ailistid);

	if (chrSpawnAtChr(g_Vars.chrdata, cmd[2], (s8)cmd[3], cmd[4], ailist, spawnflags)) {
		cmd = AILABEL(g_Vars.ailist, cmd[11], cmd[12]);
	} else {
		cmd += 13;
	}

	return cmd;
}

/**
 * @cmd 00c8
 */
static u8 *aiTryEquipWeapon(u8 *cmd)
{
	u32 flags = (cmd[6] << 16) | (cmd[7] << 8) | cmd[8] | (cmd[5] << 24);
	u32 model = cmd[3] | (cmd[2] << 8);
	struct prop *prop = NULL;

	if (g_Vars.chrdata && g_Vars.chrdata->prop && g_Vars.chrdata->model) {
		// If the Marqis cheat is active, don't give guns to chrs,
		// except where required for objectives.
#if VERSION < VERSION_NTSC_1_0
		// On NTSC beta, Marquis is disabled entirely on MBR, and the K7 guard
		// on Investigation PA is excluded here (ie. is given his weapon).
		if (cheatIsActive(CHEAT_MARQUIS) && g_Vars.stagenum != STAGE_MBR) {
			if (g_Vars.stagenum == STAGE_INVESTIGATION
					&& lvGetDifficulty() == DIFF_PA
					&& cmd[4] == WEAPON_K7AVENGER) {
				prop = chrGiveWeapon(g_Vars.chrdata, model, cmd[4], flags);
			}
		}
#elif VERSION < VERSION_PAL_BETA
		// NTSC final enables Marquis for MBR, but fails to realise why it was
		// disabled in the first place (Cass needs to equip her Falcon).
		// Additionally, NTSC Final changes the logic so the chrs are given
		// their weapon but they cannot equip them. This means the K7 guard
		// no longer needs to be handled.
		if (cheatIsActive(CHEAT_MARQUIS)) {
			flags &= ~OBJFLAG_WEAPON_LEFTHANDED;
			flags |= OBJFLAG_WEAPON_AICANNOTUSE;

			prop = chrGiveWeapon(g_Vars.chrdata, model, cmd[4], flags);
		}
#else
		// PAL fixes Cass on MBR by allowing her to equip her weapon
		if (cheatIsActive(CHEAT_MARQUIS)) {
			if (g_Vars.chrdata->bodynum != BODY_CASSANDRA || mainGetStageNum() != STAGE_MBR) {
				flags &= ~OBJFLAG_WEAPON_LEFTHANDED;
				flags |= OBJFLAG_WEAPON_AICANNOTUSE;
			}

			prop = chrGiveWeapon(g_Vars.chrdata, model, cmd[4], flags);
		}
#endif
		else if (cheatIsActive(CHEAT_ENEMYROCKETS)) {
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
				prop = chrGiveWeapon(g_Vars.chrdata, MODEL_CHRDYROCKET, WEAPON_ROCKETLAUNCHER, flags);
				break;
			case WEAPON_K7AVENGER:
				if (g_Vars.stagenum == STAGE_INVESTIGATION && lvGetDifficulty() == DIFF_PA) {
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
		cmd = AILABEL(g_Vars.ailist, cmd[9], cmd[10]);
	} else {
		cmd += 11;
	}

	return cmd;
}

/**
 * @cmd 00ca
 */
static u8 *aiDuplicateChr(u8 *cmd)
{
	u32 spawnflags = (cmd[6] << 16) | (cmd[7] << 8) | cmd[8] | (cmd[5] << 24);
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
		cloneprop = chrSpawnAtChr(g_Vars.chrdata, chr->bodynum, -1, chr->chrnum, ailist, spawnflags);

		if (cloneprop) {
			clone = cloneprop->chr;
			chrSetChrnum(clone, chrsGetNextUnusedChrnum());
			chr->chrdup = clone->chrnum;

			srcweapon0prop = chrGetHeldProp(chr, 0);

			if (srcweapon0prop) {
				srcweapon0 = srcweapon0prop->weapon;
				cloneweapon0prop = chrGiveWeapon(clone, srcweapon0->base.modelnum, srcweapon0->weaponnum, 0);

				if (cloneweapon0prop) {
					cloneweapon0 = cloneweapon0prop->weapon;
				}
			}

			srcweapon1prop = chrGetHeldProp(chr, 1);

			if (srcweapon1prop) {
				srcweapon1 = srcweapon1prop->weapon;
				cloneweapon1prop = chrGiveWeapon(clone, srcweapon1->base.modelnum, srcweapon1->weaponnum, OBJFLAG_WEAPON_LEFTHANDED);

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
				hatCreateForChr(clone, obj->modelnum, 0);
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

			rebuildTeams();
			rebuildSquadrons();

			pass = true;
		}
	}

	if (pass) {
		cmd = AILABEL(g_Vars.ailist, cmd[9], cmd[10]);
	} else {
		cmd += 11;
	}

	return cmd;
}

/**
 * @cmd 00cb
 */
static u8 *aiShowHudmsg(u8 *cmd)
{
	char *text = langGet(cmd[4] | (cmd[3] << 8));
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	u32 prevplayernum = g_Vars.currentplayernum;
	u32 playernum = g_Vars.currentplayernum;

	if (chr && chr->prop && (chr->prop->type & 0xff) == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(chr->prop);
	}

	setCurrentPlayerNum(playernum);
	hudmsgCreate(text, HUDMSGTYPE_DEFAULT);
	setCurrentPlayerNum(prevplayernum);

	cmd += 5;

	return cmd;
}

/**
 * @cmd 01a4
 */
static u8 *aiShowHudmsgMiddle(u8 *cmd)
{
	if (cmd[2] == 0) {
		u32 text_id = cmd[5] | (cmd[4] << 8);
		char *text = langGet(text_id);
		hudmsgCreateWithColour(text, HUDMSGTYPE_7, cmd[3]);
	} else if (cmd[2] == 1) {
		u32 text_id = cmd[5] | (cmd[4] << 8);
		char *text = langGet(text_id);
		hudmsgCreateWithColour(text, HUDMSGTYPE_8, cmd[3]);
	} else {
		hudmsgRemoveAll();
	}

	cmd += 6;

	return cmd;
}

/**
 * @cmd 00cc
 */
static u8 *aiShowHudmsgTopMiddle(u8 *cmd)
{
	char *text = langGet(cmd[4] | (cmd[3] << 8));
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	u32 prevplayernum = g_Vars.currentplayernum;
	u32 playernum = g_Vars.currentplayernum;

	if (chr && chr->prop && (chr->prop->type & 0xff) == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(chr->prop);
	}

	setCurrentPlayerNum(playernum);
	hudmsgCreateWithColour(text, HUDMSGTYPE_INGAMESUBTITLE, cmd[5]);
	setCurrentPlayerNum(prevplayernum);

	cmd += 6;

	return cmd;
}

/**
 * @cmd 00cd
 */
static u8 *aiSpeak(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	s16 audio_id = cmd[6] | (cmd[5] << 8);
	s16 text_id = cmd[4] | (cmd[3] << 8);
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 playernum = prevplayernum;
	u32 channelnum;
	char *text = text_id >= 0 ? langGet(cmd[4] | (cmd[3] << 8)) : NULL;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(chr->prop);
	}

	setCurrentPlayerNum(playernum);

	if (text && cmd[2] != CHR_P1P2) {
		func0f0926bc(g_Vars.chrdata->prop, 9, 0xffff);
	}

	if (cmd[2] == CHR_P1P2) {
		channelnum = audioPlayFromProp((s8)cmd[7], audio_id, 0, g_Vars.chrdata->prop, 0, 512);
	} else {
		channelnum = audioPlayFromProp((s8)cmd[7], audio_id, 0, g_Vars.chrdata->prop, 9, 512);
	}

	if (text && !sndIsFiltered(audio_id)) {
		hudmsgCreateAsSubtitle(text, HUDMSGTYPE_INGAMESUBTITLE, cmd[8], channelnum);
	}

	setCurrentPlayerNum(prevplayernum);

	cmd += 9;

	return cmd;
}

/**
 * @cmd 00ce
 */
static u8 *aiPlaySound(u8 *cmd)
{
	s16 audio_id = cmd[3] | (cmd[2] << 8);

	audioPlayFromProp((s8)cmd[4], audio_id, 0, NULL, 0, 0);

	cmd += 5;

	return cmd;
}

/**
 * @cmd 017c
 */
static u8 *aiAssignSound(u8 *cmd)
{
	s16 audio_id = cmd[3] | (cmd[2] << 8);

	audioPlayFromProp((s8)cmd[4], audio_id, -1, NULL, 11, 0);

	cmd += 5;

	return cmd;
}

/**
 * @cmd 00d3
 */
static u8 *aiAudioMuteChannel(u8 *cmd)
{
	s8 channel = (s8)cmd[2];

	audioMuteChannel(channel);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0138
 */
static u8 *aiIfChannelIdle(u8 *cmd)
{
	s8 channel = (s8) cmd[2];

	if (audioIsChannelIdle(channel)) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 00cf
 */
static u8 *ai00cf(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[3]);
	u16 thing = cmd[5] | (cmd[4] << 8);

	if (obj && obj->prop) {
		audioPlayFromProp2((s8)cmd[2], -1, -1, obj->prop, thing, 2500, 3000, 0);
	}

	cmd += 6;

	return cmd;
}

/**
 * @cmd 016b
 */
static u8 *ai016b(u8 *cmd)
{
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

		audioPlayFromProp2((s8)cmd[2], -1, -1, obj->prop, thing1again, thing2, thing3, 2);
	}

	cmd += 10;

	return cmd;
}

/**
 * @cmd 0179
 */
static u8 *ai0179(u8 *cmd)
{
	u16 thing1 = cmd[5] | (cmd[4] << 8);
	u16 thing2 = cmd[7] | (cmd[6] << 8);
	u16 thing3 = cmd[9] | (cmd[8] << 8);

	if (cmd[10] == 0) {
		struct defaultobj *obj = objFindByTagId(cmd[3]);

		if (obj && obj->prop) {
			audioPlayFromProp2((s8)cmd[2], -1, -1, obj->prop, thing1, thing2, thing3, 0);
		}
	} else {
		struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[3]);

		if (chr && chr->prop) {
			audioPlayFromProp2((s8)cmd[2], -1, -1, chr->prop, thing1, thing2, thing3, 0);
		}
	}

	cmd += 11;

	return cmd;
}

/**
 * @cmd 00d0
 */
static u8 *ai00d0(u8 *cmd)
{
	s16 padnum = cmd[4] | (cmd[3] << 8);
	s16 sound = cmd[6] | (cmd[5] << 8);

	propsnd0f0939f8(0, NULL, sound, padnum, -1, 2, 0, 0, 0, -1, 0, -1, -1, -1, -1);

	cmd += 7;

	return cmd;
}

/**
 * @cmd 00d5
 */
static u8 *aiHovercarBeginPath(u8 *cmd)
{
	struct path *path = pathFindById(cmd[2]);

	if (g_Vars.truck) {
		g_Vars.truck->path = path;
		g_Vars.truck->nextstep = 0;
	}

	if (g_Vars.hovercar) {
		struct chopperobj *chopper = chopperFromHovercar(g_Vars.hovercar);
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
			chopper->base.flags |= OBJFLAG_20000000;
		} else {
			g_Vars.hovercar->weaponsarmed = false;
		}
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 00d6
 */
static u8 *aiSetVehicleSpeed(u8 *cmd)
{
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

	cmd += 6;

	return cmd;
}

/**
 * @cmd 00d7
 */
static u8 *aiSetRotorSpeed(u8 *cmd)
{
	f32 speedtime = cmd[5] | (cmd[4] << 8);
	f32 speedaim = (cmd[3] | (cmd[2] << 8)) * M_BADTAU / 3600;

	if (g_Vars.heli) {
		g_Vars.heli->rotoryspeedaim = speedaim;
		g_Vars.heli->rotoryspeedtime = speedtime;
	}

	cmd += 6;

	return cmd;
}

/**
 * @cmd 00da
 */
static u8 *aiSetObjImage(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		if (obj->type == OBJTYPE_SINGLEMONITOR) {
			struct singlemonitorobj *sm = (struct singlemonitorobj *) obj;
			tvscreenSetImageByNum(&sm->screen, cmd[4]);
		} else if (obj->type == OBJTYPE_MULTIMONITOR) {
			u8 slot = cmd[3];
			if (slot < 4) {
				struct multimonitorobj *mm = (struct multimonitorobj *) obj;
				tvscreenSetImageByNum(&mm->screens[slot], cmd[4]);
			}
		}
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 00dc
 */
static u8 *aiEndLevel(u8 *cmd)
{
	if (debugAllowEndLevel()) {
		if (g_IsTitleDemo) {
			mainChangeToStage(STAGE_TITLE);
		} else if (g_Vars.autocutplaying) {
			g_Vars.autocutfinished = true;
		} else {
			func0000e990();
		}
	}

	cmd += 2;

	return cmd;
}

/**
 * @cmd 00dd
 */
static u8 *ai00dd(u8 *cmd)
{
	playerEndCutscene();
	cmd += 2;
	return cmd;
}

/**
 * @cmd 00de
 */
static u8 *aiWarpJoToPad(u8 *cmd)
{
	u16 pad_id = cmd[3] | (cmd[2] << 8);
	playerPrepareWarpType1(pad_id);

	cmd += 4;

	return cmd;
}

/**
 * @cmd 0111
 */
static u8 *aiSetCameraAnimation(u8 *cmd)
{
	s16 anim_id = cmd[3] | (cmd[2] << 8);

	playerStartCutscene(anim_id);

	if (g_Vars.currentplayer->haschrbody == false) {
		return NULL;
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 0113
 */
static u8 *aiIfInCutscene(u8 *cmd)
{
	if (g_Vars.in_cutscene) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0174
 */
static u8 *aiIfCutsceneButtonPressed(u8 *cmd)
{
	if ((g_Vars.in_cutscene && g_CutsceneSkipRequested) ||
			(g_Vars.stagenum == STAGE_CITRAINING && var80087260 > 0)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0175
 */
static u8 *ai0175(u8 *cmd)
{
	playerReorientForCutsceneStop(cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0112
 */
static u8 *aiObjectDoAnimation(u8 *cmd)
{
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
		struct anim *anim = obj->model->anim;

		if (obj->model->anim == NULL) {
			obj->model->anim = modelmgrInstantiateAnim();
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

			animInit(obj->model->anim);
#if VERSION >= VERSION_JPN_FINAL
			modelSetAnimPlaySpeed(obj->model, 1, 0);
#elif VERSION >= VERSION_PAL_BETA
			modelSetAnimPlaySpeed(obj->model, 1.2, 0);
#endif
			modelSetAnimation(obj->model, anim_id, 0, fstartframe, thing, 0);
			modelSetAnimScale(obj->model, func0f15c888() * obj->model->scale * 100.0f);
		}
	}

	cmd += 8;

	return cmd;
}

/**
 * @cmd 0114
 */
static u8 *aiEnableChr(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->model) {
		propActivate(chr->prop);
		propEnable(chr->prop);
		chr0f0220ac(chr);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 0115
 */
static u8 *aiDisableChr(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->model) {
		propDeregisterRooms(chr->prop);
		propDelist(chr->prop);
		propDisable(chr->prop);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 0116
 */
static u8 *aiEnableObj(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->model) {
		propActivate(obj->prop);
		propEnable(obj->prop);

		if (g_Vars.currentplayer->eyespy == NULL && obj->type == OBJTYPE_WEAPON) {
			struct weaponobj *weapon = (struct weaponobj *) obj;

			if (weapon->weaponnum == WEAPON_EYESPY) {
				playerInitEyespy();
			}
		}
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 0117
 */
static u8 *aiDisableObj(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->model) {
#if VERSION >= VERSION_PAL_FINAL
		if (g_Vars.autocutplaying
				&& mainGetStageNum() == STAGE_AIRFORCEONE
				&& (obj->modelnum == MODEL_AIRFORCE1 || obj->modelnum == MODEL_SK_SHUTTLE)) {
			// ignore
		} else {
			if (obj->prop->parent) {
				objDetach(obj->prop);
			} else {
				propDeregisterRooms(obj->prop);
				propDelist(obj->prop);
				propDisable(obj->prop);
			}
		}
#else
		if (obj->prop->parent) {
			objDetach(obj->prop);
		} else {
			propDeregisterRooms(obj->prop);
			propDelist(obj->prop);
			propDisable(obj->prop);
		}
#endif
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 00e0
 */
static u8 *aiRevokeControl(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		bgunSetSightVisible(GUNSIGHTREASON_NOCONTROL, false);
		bgunSetGunAmmoVisible(GUNAMMOREASON_NOCONTROL, false);

		if ((cmd[3] & 2) == 0) {
			hudmsgsSetOff(HUDMSGREASON_NOCONTROL);
		}

		if ((cmd[3] & 4) == 0) {
			countdownTimerSetVisible(COUNTDOWNTIMERREASON_NOCONTROL, false);
		}

		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		setCurrentPlayerNum(prevplayernum);
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 00e1
 */
static u8 *aiGrantControl(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		setCurrentPlayerNum(playermgrGetPlayerNumByProp(chr->prop));
		bgunSetSightVisible(GUNSIGHTREASON_NOCONTROL, true);
		bgunSetGunAmmoVisible(GUNAMMOREASON_NOCONTROL, true);
		hudmsgsSetOn(HUDMSGREASON_NOCONTROL);
		countdownTimerSetVisible(COUNTDOWNTIMERREASON_NOCONTROL, true);
		g_PlayersWithControl[g_Vars.currentplayernum] = true;
		setCurrentPlayerNum(prevplayernum);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 00e2
 */
static u8 *aiChrMoveToPad(u8 *cmd)
{
#if VERSION < VERSION_NTSC_1_0
	s32 padnum = cmd[4] | (cmd[3] << 8);
#endif
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	bool pass = false;
	f32 theta;
	struct pad *pad;
	s16 rooms[2];
	struct chrdata *chr2;

	if (chr && chr->prop) {
		if (cmd[5] == 88) {
			chr2 = chrFindById(g_Vars.chrdata, cmd[4]);

			if (chr2 && chr2->prop) {
				theta = chrGetInverseTheta(chr2);
				pass = chrMoveToPos(chr, &chr2->prop->pos, chr2->prop->rooms, theta, 0);
			}
		} else {
			s32 padnum = cmd[4] | (cmd[3] << 8);
			padnum = chrResolvePadId(chr, padnum);

			if (padnum >= 0) {
				pad = &g_Pads[padnum];
				theta = atan2f(pad->look.x, pad->look.z);

				rooms[0] = pad->room;
				rooms[1] = -1;
				pass = chrMoveToPos(chr, &pad->pos, rooms, theta, cmd[5]);
			}
		}
	}

	if (pass) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 00e8
 */
static u8 *aiSetDoorOpen(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		struct doorobj *door = (struct doorobj *) obj;
		door->frac = door->maxfrac;
		door->fracspeed = 0;
		door->lastopen60 = g_Vars.lvframe60;
		door->mode = 0;
		doorUpdateTiles(door);
		doorActivatePortal(door);
		func0f0926bc(door->base.prop, 1, 0xffff);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 00ea
 */
static u8 *aiIfNumPlayersLessThan(u8 *cmd)
{
	if ((s8)cmd[2] > PLAYERCOUNT()) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 00eb
 */
static u8 *aiIfChrAmmoQuantityLessThan(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	bool passes = false;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);

		if (bgunGetAmmoCount((s8)cmd[3]) < (s8)cmd[4]) {
			passes = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	if (passes) {
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd += 7;
	}

	return cmd;
}

/**
 * @cmd 00ec
 */
static u8 *aiChrDrawWeapon(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		bgunEquipWeapon2(0, (s8)cmd[3]);
		bgunEquipWeapon2(1, 0);
		setCurrentPlayerNum(prevplayernum);
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 00ed
 */
static u8 *aiChrDrawWeaponInCutscene(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		bgunEquipWeapon((s8)cmd[3]);
		setCurrentPlayerNum(prevplayernum);
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 00ef
 */
static u8 *aiIfObjInRoom(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	u16 room_id = cmd[4] | (cmd[3] << 8);
	s32 room_something = chrGetPadRoom(g_Vars.chrdata, room_id);

	if (room_something >= 0 && obj && obj->prop && room_something == obj->prop->rooms[0]) {
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd += 7;
	}

	return cmd;
}

/**
 * @cmd 00f3
 */
static u8 *aiChrSetInvincible(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		g_PlayerInvincible = true;
		setCurrentPlayerNum(prevplayernum);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 00f7
 */
static u8 *aiIfAllObjectivesComplete(u8 *cmd)
{
	if (objectiveIsAllComplete()) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd = cmd + 4;
	}

	return cmd;
}

/**
 * @cmd 00f9
 */
static u8 *aiPlayXTrack(u8 *cmd)
{
	musicSetXReason((s8)cmd[2], cmd[3], cmd[4]);
	cmd += 5;

	return cmd;
}

/**
 * @cmd 00fa
 */
static u8 *aiStopXTrack(u8 *cmd)
{
	musicUnsetXReason((s8)cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 015b
 */
static u8 *aiPlayTrackIsolated(u8 *cmd)
{
	if (cmd[2] == MUSIC_CI_TRAINING) {
		u16 volume = optionsGetMusicVolume();
		musicPlayTrackIsolated(cmd[2]);
		optionsSetMusicVolume(volume);
	} else {
		musicPlayTrackIsolated(cmd[2]);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 015c
 */
static u8 *aiPlayDefaultTracks(u8 *cmd)
{
	cmd += 2;
	musicPlayDefaultTracks();

	return cmd;
}

/**
 * @cmd 017d
 */
static u8 *aiPlayCutsceneTrack(u8 *cmd)
{
	musicStartCutscene(cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 017e
 */
static u8 *aiStopCutsceneTrack(u8 *cmd)
{
	musicEndCutscene();
	cmd += 2;

	return cmd;
}

/**
 * @cmd 017f
 */
static u8 *aiPlayTemporaryTrack(u8 *cmd)
{
	musicStartTemporaryAmbient(cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0180
 */
static u8 *aiStopAmbientTrack(u8 *cmd)
{
	musicEndTemporaryAmbient();
	cmd += 2;

	return cmd;
}

/**
 * @cmd 00fb
 */
static u8 *aiChrExplosions(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		playerSurroundWithExplosions(0);
		setCurrentPlayerNum(prevplayernum);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 00fc
 */
static u8 *aiIfKillCountGreaterThan(u8 *cmd)
{
	if (g_Vars.killcount > cmd[2]) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 01ab
 */
static u8 *aiIfNumKnockedOutChrs(u8 *cmd)
{
	if (cmd[2] < mpstatsGetTotalKnockoutCount() && cmd[3] == 0) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else if (mpstatsGetTotalKnockoutCount() < cmd[2] && cmd[3] == 1) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0102
 */
static u8 *aiSetLights(u8 *cmd)
{
	u16 padnum = cmd[3] | (cmd[2] << 8);
	s32 roomnum = chrGetPadRoom(g_Vars.chrdata, padnum);

	if (roomnum >= 0) {
		switch (cmd[4]) {
		case LIGHTOP_TURNOFF:
			roomSetLightsOn(roomnum, false);
			break;
		case LIGHTOP_TURNON:
			roomSetLightsOn(roomnum, true);
			break;
		default:
			roomSetLighting(roomnum, cmd[4], cmd[5], cmd[6], TICKS(cmd[7]));
		}
	}

	cmd += 11;

	return cmd;
}

/**
 * @cmd 0106
 */
static u8 *aiSetTarget(u8 *cmd)
{
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
			g_Vars.chrdata->hidden &= ~CHRHFLAG_IS_HEARING_TARGET;
			g_Vars.chrdata->chrflags &= ~CHRCFLAG_NEAR_MISS;
			g_Vars.chrdata->target = prop_id;
		}
	} else if (g_Vars.hovercar) {
		chopperSetTarget(g_Vars.hovercar, cmd[2]);
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 0107
 */
static u8 *aiIfPresetsTargetIsNotMyTarget(u8 *cmd)
{
	s32 mypresetchrstarget;

	if (g_Vars.chrdata->chrpreset1 != -1) {
		mypresetchrstarget = propGetIndexByChrId(g_Vars.chrdata, g_Vars.chrdata->chrpreset1);
	}

	if (g_Vars.chrdata->target != -1 && mypresetchrstarget != g_Vars.chrdata->target) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0108
 */
static u8 *aiIfChrTarget(u8 *cmd)
{
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
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd += 7;
	}

	return cmd;
}

/**
 * @cmd 010b
 */
static u8 *aiChrSetTeam(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->team = cmd[3];
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 011f
 */
static u8 *aiIfSkedar(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && CHRRACE(chr) == RACE_SKEDAR) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0120
 */
static u8 *aiIfSafety2LessThan(u8 *cmd)
{
	u8 score;
	u8 numnearby;
	s16 *chrnums = teamGetChrIds(g_Vars.chrdata->team);

	score = 6;
	numnearby = 0;

	if (chrGetNumArghs(g_Vars.chrdata) > 0) {
		score -= 2;
	}

	switch (bgunGetWeaponNum(HAND_RIGHT)) {
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
		struct chrdata *chr = chrFindByLiteralId(*chrnums);

		if (chr && chr->model
				&& !chrIsDead(chr)
				&& chr->actiontype != ACT_DEAD
				&& chr->alertness > 100
				&& g_Vars.chrdata->squadron == chr->squadron
				&& g_Vars.chrdata->chrnum != chr->chrnum
				&& chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum) < 3500) {
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
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0121
 */
static u8 *aiFindCover(u8 *cmd)
{
	u16 criteria = cmd[3] | (cmd[2] << 8);

	if (g_Vars.chrdata && g_Vars.chrdata->prop && chrAssignCoverByCriteria(g_Vars.chrdata, criteria, 0) != -1) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0124
 */
static u8 *aiGoToCover(u8 *cmd)
{
	chrGoToCover(g_Vars.chrdata, cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0125
 */
static u8 *aiCheckCoverOutOfSight(u8 *cmd)
{
	if (chrCheckCoverOutOfSight(g_Vars.chrdata, g_Vars.chrdata->cover, false)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0126
 */
static u8 *aiIfPlayerUsingCmpOrAr34(u8 *cmd)
{
	u32 hand = HAND_RIGHT;

	switch (bgunGetWeaponNum(hand)) {
		case WEAPON_CMP150:
		case WEAPON_AR34:
			cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
			break;
		default:
			cmd += 4;
			break;
	}

	return cmd;
}

/**
 * @cmd 0127
 */
static u8 *aiDetectEnemyOnSameFloor(u8 *cmd)
{ \
	s32 team = 0;
	f32 closestdist = 9999.9;
	f32 distance;
	u32 stack[2];
	f32 y;
	f32 scandist;
	s16 *chrnums = teamGetChrIds(1);
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
		chr = chrFindByLiteralId(*chrnums);

		if (*chrnums != -2) {
			if (chr && chr->prop
					&& chr->team != TEAM_NONCOMBAT
					&& !chrIsDead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP
					&& chrCompareTeams(g_Vars.chrdata, chr, COMPARE_ENEMIES)
					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
					&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0
					&& (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0
					&& y - chr->prop->pos.y > -200
					&& y - chr->prop->pos.y < 200
					&& ((g_Vars.chrdata->hidden & CHRHFLAG_PSYCHOSISED) == 0
						|| (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0
						|| (chr->hidden & CHRHFLAG_DONTSHOOTME))
					&& g_Vars.chrdata->chrnum != chr->chrnum) {
				distance = chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum);

				if (distance < closestdist) {
					if (distance < scandist || stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MAIANSOS) {
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
		g_Vars.chrdata->target = propGetIndexByChrId(g_Vars.chrdata, newtarget);
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd = cmd + 4;
	}

	return cmd;
}

/**
 * @cmd 0128
 */
static u8 *aiDetectEnemy(u8 *cmd)
{
	s16 *chrnums;
	s32 team = 0;
	u32 stack[4];
	f32 closestdist = 10000000;
	f32 maxdist = (s32)cmd[2] * 10.0f;
	s16 closesttarg = -1;

	chrnums = teamGetChrIds(1);

	if (!g_Vars.chrdata) {
		cmd = cmd + 5;
		return cmd;
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
					&& chrCompareTeams(g_Vars.chrdata, chr, COMPARE_ENEMIES)
					&& chr != g_Vars.chrdata
					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
					&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0
					&& (chr->hidden & CHRHFLAG_DISGUISED) == 0
					&& chr->team != TEAM_NONCOMBAT
					&& (
						(g_Vars.chrdata->hidden & CHRHFLAG_PSYCHOSISED) == 0
						|| (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0
						|| (chr->hidden & CHRHFLAG_DONTSHOOTME))) {
				f32 distance = chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum);

				if (distance < maxdist && distance != 0 && distance < closestdist
						&& chrCanSeeProp(g_Vars.chrdata, chr->prop)
						&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0) {
					if (g_Vars.chrdata->yvisang == 0) {
						closestdist = distance;
						closesttarg = chr->chrnum;
					} else {
						s16 prevtarget = g_Vars.chrdata->target;
						g_Vars.chrdata->target = propGetIndexByChrId(g_Vars.chrdata, chr->chrnum);

						if (chrIsVerticalAngleToTargetWithin(g_Vars.chrdata, g_Vars.chrdata->yvisang)) {
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
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd = cmd + 5;
	}

	return cmd;
}

/**
 * @cmd 012a
 */
static u8 *aiIfTargetMovingSlowly(u8 *cmd)
{
	s32 delta;
	s32 absdelta;

	if (cmd[2] == 0) {
		delta = chrGetDistanceLostToTargetInLastSecond(g_Vars.chrdata);
	} else {
		struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
		delta = chrGetDistanceLostToTargetInLastSecond(chr);
	}

	absdelta = delta > 0 ? delta : -delta;

	if (absdelta < 50) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 012b
 */
static u8 *aiIfTargetMovingCloser(u8 *cmd)
{
	if (chrGetDistanceLostToTargetInLastSecond(g_Vars.chrdata) < -50) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 012c
 */
static u8 *aiIfTargetMovingAway(u8 *cmd)
{
	if (chrGetDistanceLostToTargetInLastSecond(g_Vars.chrdata) > 50) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 012f
 */
static u8 *ai012f(u8 *cmd)
{
	if (g_Vars.chrdata->cover >= 0) {
		coverSetInUse(g_Vars.chrdata->cover, 0);
	}

	cmd += 2;

	return cmd;
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
#if VERSION >= VERSION_NTSC_1_0
	{ 0,  MP3_CASS_HOW_DARE_YOU_DISTURB_ME,     MP3_CASS_YOU_WILL_REGRET,               MP3_CASS_LEAVE_NOW                 },
#else
	{ 0,  0x12f2,                               0x12f3,                                 0x12f8                             },
#endif
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
#if VERSION >= VERSION_NTSC_1_0
	{ 43, MP3_CASS_HOW_DARE_YOU_DISTURB_ME,     MP3_CASS_LEAVE_NOW,                     MP3_CASS_LEAVE_NOW                 },
#else
	{ 43, 0x12f2,                               0x12f8,                                 0x12f8,                            },
#endif
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

/**
 * @cmd 0130
 */
static u8 *aiSayQuip(u8 *cmd)
{
	u8 column; // 167
	s16 audioid; // 164
	u8 i; // 163
	s32 numnearbychrs; // 152
	bool issomeonetalking; // 148
	s32 probability; // 144
	u32 stack; // 140 - not referenced
	s16 *chrnums; // 136
	s16 (*bank)[4]; // 132
	char *text; // 128
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]); // 124
	u32 prevplayernum = g_Vars.currentplayernum; // 120
	s32 distance; // 116 - not referenced
	s32 row = cmd[3]; // 112
	u32 playernum; // 108 - not referenced
	u8 headshotted = (g_Vars.chrdata->hidden2 & CHRH2FLAG_HEADSHOTTED) & 0xff; // 107
	struct chrdata *loopchr; // 100

	// Choose bank
	// 2c0
	if (CHRRACE(g_Vars.chrdata) == RACE_SKEDAR) {
		bank = g_SkedarQuipBank;

		if (row > 5) {
			row = 0;
		}
		// 2e0
	} else if (g_Vars.chrdata->headnum == HEAD_MAIAN_S) {
		bank = g_MaianQuipBank;

		if (row > 2) {
			row = random() & 1;
		}
		// 324
	} else if (cmd[7] == 0) {
		if (g_Vars.chrdata->voicebox > 3) {
			g_Vars.chrdata->voicebox = 3;
		}

		bank = &g_GuardQuipBank[g_Vars.chrdata->voicebox * 41];
	} else {
		// 37c
		bank = g_SpecialQuipBank;
	}

	// 37c
	if (!row && !cmd[4] && !cmd[6]) {
		g_Vars.chrdata->soundtimer = 0;
		cmd += 10;
		return cmd;
	}

	// 3bc
	chrnums = teamGetChrIds(g_Vars.chrdata->team);
	numnearbychrs = 0;
	issomeonetalking = false;
	probability = cmd[4];

	// Make it impossible for Elvis and Jon to use anything but special phrases
	// 3f0
	if ((g_Vars.chrdata->headnum == HEAD_ELVIS
				|| g_Vars.chrdata->headnum == HEAD_THEKING
				|| g_Vars.chrdata->headnum == HEAD_ELVIS_GOGS
				|| g_Vars.chrdata->headnum == HEAD_JONATHAN) &&
			bank != g_SpecialQuipBank) {
		probability = 0;
	}

	// If the person talking is a player, and they've just died,
	// try using the other coop player.
	// 420
	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		// 444
		playernum = playermgrGetPlayerNumByProp(chr->prop);

		if (g_Vars.coopplayernum >= 0 && g_Vars.players[playernum]->isdead) {
			// 470
			if (playernum == g_Vars.bondplayernum) {
				playernum = g_Vars.coopplayernum;
			} else {
				playernum = g_Vars.bondplayernum;
			}
		}

		setCurrentPlayerNum(playernum);
	}

	// If soundgap permits talking at this time and probability passes
	// 494
	if ((g_Vars.chrdata->soundgap == 0 || g_Vars.chrdata->soundgap * 60 < g_Vars.chrdata->soundtimer)
			&& probability > (u8)random()) {
		// Try and find a chr in the same squadron who is currently talking
		// 4dc
		while (*chrnums != -2) {
			loopchr = chrFindByLiteralId(*chrnums);

			if (loopchr && loopchr->model
					&& !chrIsDead(loopchr)
					&& loopchr->actiontype != ACT_DEAD
					&& g_Vars.chrdata->squadron == loopchr->squadron
					&& loopchr->alertness >= 100
					&& g_Vars.chrdata->chrnum != loopchr->chrnum
					&& chrGetDistanceToChr(g_Vars.chrdata, loopchr->chrnum) < 7000) {
				// 584
				numnearbychrs++;

				// 594
				if (loopchr->soundtimer < 60 && cmd[6] != 0 && cmd[6] != 255) {
					issomeonetalking = true;
				}
			}

			chrnums++;
		}

		// 5dc
		if (!issomeonetalking &&
				((numnearbychrs == 0 && (cmd[6] == 0 || cmd[6] == 255)) ||
				 (numnearbychrs > 0 && cmd[6] > 0))) {
			column = random() % 3;

			// 64c
			if ((cmd[7] & 0x80) == 0) {
				audioid = bank[row][1 + column];
			} else {
				audioid = bank[row][1 + g_Vars.chrdata->tude];
			}

			// 6a0
			if (audioWasNotPlayedRecently(audioid) || CHRRACE(g_Vars.chrdata) == RACE_SKEDAR) {
				// 6d4
				audioMarkAsRecentlyPlayed(audioid);

				// 6e8
				// Replace gurgle with "why me"
				if (audioid == 0x34e && !headshotted) {
					audioid = 0x34d;
				}

				// 700
				g_Vars.chrdata->soundtimer = 0;
				g_Vars.chrdata->soundgap = cmd[5];
				g_Vars.chrdata->propsoundcount++;

				// 72c
				if (audioid != 0x3f7 && audioid != 0x331 && audioid != 0x3a1) {
					func0f0926bc(g_Vars.chrdata->prop, 9, 0xffff);
					// 7a8
					propsnd0f0939f8(0, g_Vars.chrdata->prop, audioid, -1,
							-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
				} else {
					// Audio is "Stop moving", "Stop dodging" or "Stand still"
					distance = chrGetDistanceLostToTargetInLastSecond(g_Vars.chrdata);

					if (ABS(distance) > 50) {
						func0f0926bc(g_Vars.chrdata->prop, 9, 0xffff);
						// 840
						propsnd0f0939f8(0, g_Vars.chrdata->prop, audioid, -1,
								-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
					}
				}

				// Consider putting text on screen
				// Note: if cmd[8] is 0 then it means no text, so the value
				// needs to be be decremented by one so it's 0-indexed.
				// 850
				if (cmd[8] && (cmd[7] & 0x80) == 0) {
					if (column > 2) {
						column = 2;
					}

					text = langGet(g_QuipTexts[cmd[8] - 1][1 + column]);

					if (!sndIsFiltered(audioid)) {
						// 8ac
						hudmsgCreateWithColour(text, HUDMSGTYPE_INGAMESUBTITLE, cmd[9]);
					}
				} else if (cmd[8]) {
					text = langGet(g_QuipTexts[cmd[8] - 1][1 + g_Vars.chrdata->tude]);

					if (!sndIsFiltered(audioid)) {
						// 904
						hudmsgCreateWithColour(text, HUDMSGTYPE_INGAMESUBTITLE, cmd[9]);
					}
				}
			} else {
				// Audio was played recently - try and find a different one
				audioid = 0;

				// 92c
				for (i = 1; i < 4; i++) {
					if (audioWasNotPlayedRecently(g_GuardQuipBank[row][i])
							&& audioWasNotPlayedRecently(bank[row][i])) {
						audioid = bank[row][i];
						break;
					}
				}

				// 99c
				if (audioid) {
					audioMarkAsRecentlyPlayed(audioid);

					// Replace gurgle with "why me"
					if (audioid == 0x34e && !headshotted) {
						audioid = 0x34d;
					}

					g_Vars.chrdata->soundtimer = 0;
					g_Vars.chrdata->soundgap = cmd[5];
					g_Vars.chrdata->propsoundcount++;

					// 9fc
					if (audioid != 0x3f7 && audioid != 0x331 && audioid != 0x3a1) {
						func0f0926bc(g_Vars.chrdata->prop, 9, 0xffff);
						// a80
						propsnd0f0939f8(0, g_Vars.chrdata->prop, audioid, -1,
								-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
					} else {
						// Audio is "Stop moving", "Stop dodging" or "Stand still"
						// a90
						distance = chrGetDistanceLostToTargetInLastSecond(g_Vars.chrdata);

						if (ABS(distance) > 50) {
							func0f0926bc(g_Vars.chrdata->prop, 9, 0xffff);
							// b28
							propsnd0f0939f8(0, g_Vars.chrdata->prop, audioid, -1,
									-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
						}
					}

					// b44
					if (cmd[8]) {
						text = langGet(g_QuipTexts[cmd[8] - 1][i]);

						if (!sndIsFiltered(audioid)) {
							// b78
							hudmsgCreateWithColour(text, HUDMSGTYPE_INGAMESUBTITLE, cmd[9]);
						}
					}
				} else {
					g_Vars.chrdata->soundtimer = 0;
					g_Vars.chrdata->soundgap = cmd[5];
					chrUnsetFlags(g_Vars.chrdata, CHRFLAG1_TALKINGTODISGUISE, BANK_1);
				}
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);

	cmd += 10;

	return cmd;
}

void propDecrementSoundCount(struct prop *prop)
{
	if (prop && prop->chr && prop->chr->model && prop->chr->propsoundcount > 0) {
		prop->chr->propsoundcount--;
	}
}

/**
 * @cmd 01a7
 */
static u8 *aiIfChrNotTalking(u8 *cmd)
{
	struct chrdata *chr = chrFindByLiteralId(cmd[2]);

	if (chr && chr->propsoundcount == 0) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd = cmd + 5;
	}

	return cmd;
}

/**
 * @cmd 0131
 */
static u8 *aiIncreaseSquadronAlertness(u8 *cmd)
{
	s16 *chrnums = teamGetChrIds(g_Vars.chrdata->team);

	for (; *chrnums != -2; chrnums++) {
		struct chrdata *chr = chrFindByLiteralId(*chrnums);

		if (chr &&
				chr->model &&
				!chrIsDead(chr) &&
				chr->actiontype != ACT_DEAD &&
				(g_Vars.chrdata->squadron == chr->squadron || g_Vars.chrdata->squadron == 255) &&
				g_Vars.chrdata->chrnum != chr->chrnum &&
				(chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum) < 1000 || chrHasFlag(g_Vars.chrdata, CHRFLAG0_SQUADALERTANYDIST, BANK_0))) {
			incrementByte(&chr->alertness, cmd[2]);
		}
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 0132
 */
static u8 *aiSetAction(u8 *cmd)
{
	struct bytelist *cmd2 = (struct bytelist *)(cmd);
	g_Vars.chrdata->myaction = cmd2->b2;

	if (cmd2->b3 == 0) {
		g_Vars.chrdata->orders = 0;
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 0133
 */
static u8 *aiSetTeamOrders(u8 *cmd)
{
	struct chrnumaction *chraction;
	s32 chrcount = 1;
	s16 *chrnums;
	struct chrnumaction chractions[50];
	s32 num;
	u32 stack;

	// Get list of chrs in the current chr's squadron
	chrnums = squadronGetChrIds(g_Vars.chrdata->squadron);

	// Iterate chrs in squadron and build list of their actions.
	// Put the current chr's action first.
	chraction = chractions;
	chraction->chrnum = g_Vars.chrdata->chrnum;
	chraction->myaction = g_Vars.chrdata->myaction;
	chraction++;

	if (chrnums) {
		while (*chrnums != -2) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->model
					&& !chrIsDead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chrCompareTeams(g_Vars.chrdata, chr, COMPARE_FRIENDS)
					&& g_Vars.chrdata->chrnum != chr->chrnum) {
				if (chr->myaction == MA_COVERWAIT
						|| chr->myaction == MA_NORMAL
						|| chr->myaction == MA_WAITING
						|| chr->myaction == MA_SHOOTING) {
					if (chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum) < 3500) {
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
			struct chrdata *chr = chrFindByLiteralId(chraction->chrnum);

			switch (chractions[0].myaction) {
			case MA_COVERGOTO:
				if (!chrIsInTargetsFovX(chr, 45)) {
					chr->orders = MA_SHOOTING;
				}
				break;
			case MA_COVERBREAK:
				if (!chrIsInTargetsFovX(chr, 30)) {
					chr->orders = MA_SHOOTING;
				}
				num++;
				break;
			case MA_COVERSEEN:
				if (!chrIsInTargetsFovX(chr, 30)) {
					chr->orders = MA_SHOOTING;
					g_Vars.chrdata->orders = MA_COVERGOTO;
				}
				num++;
				break;
			case MA_FLANKLEFT:
				if (chrIsInTargetsFovX(chr, 50)) {
					chr->orders = MA_FLANKRIGHT;
				} else {
					chr->orders = MA_SHOOTING;
				}
				num++;
				g_Vars.chrdata->orders = MA_FLANKLEFT;
				break;
			case MA_FLANKRIGHT:
				if (chrIsInTargetsFovX(chr, 50)) {
					chr->orders = MA_FLANKLEFT;
				} else {
					chr->orders = MA_SHOOTING;
				}
				num++;
				g_Vars.chrdata->orders = MA_FLANKRIGHT;
				break;
			case MA_DODGE:
				if (!chrIsInTargetsFovX(chr, 30) &&
						chrHasFlagById(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders = MA_WITHDRAW;
				} else {
					chr->orders = MA_SHOOTING;
				}
				num++;
				break;
			case MA_GRENADE:
				if (num < 2) {
					chr->orders = MA_WAITING;
				} else if (chrHasFlagById(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders = MA_WITHDRAW;
				}
				num++;
				break;
			case MA_WAITSEEN:
				if (chrIsInTargetsFovX(chr, 30) &&
						chrHasFlagById(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders = MA_WITHDRAW;
				} else {
					chr->orders = MA_SHOOTING;
				}
				num++;
				break;
			case MA_WITHDRAW:
				if (chrHasFlagById(chr, CHR_SELF, CHRFLAG0_CAN_BACKOFF, BANK_0)) {
					chr->orders = MA_WITHDRAW;
				}
				break;
			}

			chraction++;
		}

		if (num != 1) {
			cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
		} else {
			cmd += 5;
		}
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0134
 */
static u8 *aiIfOrders(u8 *cmd)
{
	struct bytelist *cmd2 = (struct bytelist *)(cmd);

	if (g_Vars.chrdata->orders == cmd2->b3) {
		cmd = AILABEL(g_Vars.ailist, cmd2->b4, cmd2->b5);

		if (g_Vars.chrdata->orders == MA_WITHDRAW) {
			// empty
		}
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0135
 */
static u8 *aiIfHasOrders(u8 *cmd)
{
	if (g_Vars.chrdata->orders) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0136
 */
static u8 *aiRetreat(u8 *cmd)
{
	if (cmd[3] == 0) {
		chrRunFromPos(g_Vars.chrdata, cmd[2], (cmd[2] & 0x10) ? 400.0f : 10000.0f, &g_Vars.chrdata->runfrompos);
	} else if (cmd[3] == 1) {
		struct prop *target = chrGetTargetProp(g_Vars.chrdata);
		chrRunFromPos(g_Vars.chrdata, cmd[2], 10000, &target->pos);
	} else {
		chrAssignCoverByCriteria(g_Vars.chrdata,
				COVERCRITERIA_FURTHEREST
				| COVERCRITERIA_DISTTOTARGET
				| COVERCRITERIA_ONLYNEIGHBOURINGROOMS
				| COVERCRITERIA_ROOMSFROMME, 0);
		chrGoToCover(g_Vars.chrdata, cmd[2]);
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 0137
 */
static u8 *aiIfChrInSquadronDoingAction(u8 *cmd)
{
	s32 ret;
	s16 *chrnums = squadronGetChrIds(g_Vars.chrdata->squadron);
	struct bytelist *cmd2 = (struct bytelist *)(cmd);
	ret = 1;

	if (chrnums) {
		for (; *chrnums != -2; chrnums++) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->model && chrIsDead(chr) == false &&
					chr->actiontype != ACT_DEAD &&
					chrCompareTeams(g_Vars.chrdata, chr, COMPARE_FRIENDS) &&
					g_Vars.chrdata->chrnum != chr->chrnum &&
					chrGetDistanceToChr(g_Vars.chrdata, chr->chrnum) < 3500 &&
					chr->myaction == cmd2->b2) {
				ret = 2;
				break;
			}
		}
	}

	if (ret != 1) {
		cmd = AILABEL(g_Vars.ailist, cmd2->b3, cmd2->b4);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0139
 */
static u8 *ai0139(u8 *cmd)
{
	u32 angle = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	struct coord pos;

	chr0f04c874(g_Vars.chrdata, angle, &pos, cmd[7], cmd[6]);

	cmd += 8;

	return cmd;
}

/**
 * @cmd 013a
 */
static u8 *aiSetChrPresetToUnalertedTeammate(u8 *cmd)
{
	f32 closest_distance = 30999.9;
	s16 candidate_chrnum = -1;
	s16 *chrnums = teamGetChrIds(g_Vars.chrdata->team);

	if (g_Vars.chrdata->talktimer > TICKS(480) && g_Vars.chrdata->listening) {
		g_Vars.chrdata->listening = 0;
	}

	for (; *chrnums != -2; chrnums++) {
		struct chrdata *chr = chrFindByLiteralId(*chrnums);

		if (cmd[3] == 0 && chr && chr->model &&
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
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 013b
 */
static u8 *aiSetSquadron(u8 *cmd)
{
	g_Vars.chrdata->squadron = cmd[2];
	cmd += 3;

	return cmd;
}

/**
 * @cmd 013d
 */
static u8 *aiIfDangerousObjectNearby(u8 *cmd)
{
	if (chrDetectDangerousObject(g_Vars.chrdata, cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 013e
 */
static u8 *ai013e(u8 *cmd)
{
	if (func0f03aca0(g_Vars.chrdata, 400, true) == 0 && chrAssignCoverAwayFromDanger(g_Vars.chrdata, 1000, 12000) != -1) {
		chrGoToCover(g_Vars.chrdata, GOPOSFLAG_RUN);
	}

	cmd += 2;

	return cmd;
}

/**
 * @cmd 0140
 */
static u8 *aiIfHoverbotNextStep(u8 *cmd)
{
	if (g_Vars.hovercar) {
		if ((g_Vars.hovercar->nextstep > cmd[3] && cmd[2] == 1) ||
				(g_Vars.hovercar->nextstep < cmd[3] && cmd[2] == 0)) {
			cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
		} else {
			cmd += 6;
		}
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0141
 */
static u8 *aiShuffleInvestigationTerminals(u8 *cmd)
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
			goodtag->cmdoffset = pc->cmdoffset;
			goodtag->obj = pc->obj;
		} else if (rand1 == 1) {
			pc = tagFindById(cmd[5]);
			goodtag->cmdoffset = pc->cmdoffset;
			goodtag->obj = pc->obj;
		} else if (rand1 == 2) {
			pc = tagFindById(cmd[6]);
			goodtag->cmdoffset = pc->cmdoffset;
			goodtag->obj = pc->obj;
		} else {
			pc = tagFindById(cmd[7]);
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
			pc = tagFindById(cmd[4]);
			badtag->cmdoffset = pc->cmdoffset;
			badtag->obj = pc->obj;
		} else if (rand2 == 1) {
			pc = tagFindById(cmd[5]);
			badtag->cmdoffset = pc->cmdoffset;
			badtag->obj = pc->obj;
		} else if (rand2 == 2) {
			pc = tagFindById(cmd[6]);
			badtag->cmdoffset = pc->cmdoffset;
			badtag->obj = pc->obj;
		} else {
			pc = tagFindById(cmd[7]);
			badtag->cmdoffset = pc->cmdoffset;
			badtag->obj = pc->obj;
		}
	}

	cmd += 9;

	return cmd;
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
static u8 *aiSetPadPresetToInvestigationTerminal(u8 *cmd)
{
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

	cmd += 4;

	return cmd;
}

/**
 * @cmd 0143
 */
static u8 *aiHeliArmWeapons(u8 *cmd)
{
	if (g_Vars.hovercar) {
		chopperSetArmed(g_Vars.hovercar, true);
	}

	cmd += 2;

	return cmd;
}

/**
 * @cmd 0145
 */
static u8 *aiRebuildTeams(u8 *cmd)
{
	rebuildTeams();
	rebuildSquadrons();
	cmd += 2;

	return cmd;
}

/**
 * @cmd 0147
 */
static u8 *aiIfSquadronIsDead(u8 *cmd)
{
	/**
	 * @bug: anyalive is initialised to true here, and reset to false in each
	 * loop iteration. This causes it to use the last chr's status only.
	 */
	u32 stack[2];
	bool anyalive = true;
	s16 *chrnums = squadronGetChrIds(cmd[2]);

	if (chrnums) {
		while (*chrnums != -2) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->model) {
				anyalive = false;

				if (!chrIsDead(chr) && chr->actiontype != ACT_DEAD) {
					anyalive = true;
				}
			}

			chrnums++;
		}
	}

	if (!anyalive) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0157
 */
static u8 *aiSetTintedGlassEnabled(u8 *cmd)
{
	g_TintedGlassEnabled = cmd[2];
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0152
 */
static u8 *aiIfNumChrsInSquadronGreaterThan(u8 *cmd)
{
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
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0165
 */
static u8 *aiIfChrInjured(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && (chr->chrflags & CHRCFLAG_INJUREDTARGET)) {
		chr->chrflags &= ~CHRCFLAG_INJUREDTARGET;
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0167
 */
static u8 *aiHovercopterFireRocket(u8 *cmd)
{
	chopperFireRocket(g_Vars.hovercar, cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0169
 */
static u8 *aiIfNaturalAnim(u8 *cmd)
{
	struct bytelist *cmd2 = (struct bytelist *)(cmd);

	if (g_Vars.chrdata->naturalanim == cmd2->b2) {
		cmd = AILABEL(g_Vars.ailist, cmd2->b3, cmd2->b4);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 016a
 */
static u8 *aiIfY(u8 *cmd)
{
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
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;
	}

	return cmd;
}

/**
 * @cmd 016d
 */
static u8 *aiChrAdjustMotionBlur(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		if (cmd[4] == 0) {
			chr->blurdrugamount -= TICKS(cmd[3]);
		} else {
			chr->blurdrugamount += TICKS(cmd[3]);
		}
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 016e
 */
static u8 *aiDamageChrByAmount(u8 *cmd)
{
	struct coord coord = {0, 0, 0};
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop) {
		if (cmd[4] == 2) {
			struct gset gset = {WEAPON_COMBATKNIFE, 0, 0, FUNC_POISON};
			chrDamageByMisc(chr, (s32)cmd[3] * 0.03125f, &coord, &gset, NULL);
		} else if (cmd[4] == 0) {
			chrDamageByMisc(chr, (s32)cmd[3] * 0.03125f, &coord, NULL, NULL);
		} else {
			chrDamageByMisc(chr, (s32)cmd[3] * -0.03125f, &coord, NULL, NULL);
		}
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 016f
 */
static u8 *aiIfChrHasGun(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->model && chr->gunprop == NULL) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0170
 */
static u8 *aiDoGunCommand(u8 *cmd)
{
	struct weaponobj *weapon = g_Vars.chrdata->gunprop->weapon;

	if (cmd[2] == 0 || ((weapon->base.hidden & OBJHFLAG_PROJECTILE) == 0 && cmd[2] == 1)) {
		if (cmd[2] == 0) {
			chrGoToProp(g_Vars.chrdata, g_Vars.chrdata->gunprop, GOPOSFLAG_JOG);
		}

		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0171
 */
static u8 *aiIfDistanceToGunLessThan(u8 *cmd)
{
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
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0172
 */
static u8 *aiRecoverGun(u8 *cmd)
{ \
	struct prop *prop = g_Vars.chrdata->gunprop;
	g_Vars.chrdata->gunprop = NULL;

	if (prop && prop->obj && prop->parent == NULL && prop->type == PROPTYPE_WEAPON) {
		propDeregisterRooms(prop);
		propDelist(prop);
		propDisable(prop);
		chrEquipWeapon(prop->weapon, g_Vars.chrdata);
	}

	cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);

	if (1);

	return cmd;
}

/**
 * @cmd 0173
 */
static u8 *aiChrCopyProperties(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

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

		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0177
 */
static u8 *aiPlayerAutoWalk(u8 *cmd)
{
	s16 pad_id = cmd[4] | (cmd[3] << 8);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		playerAutoWalk(pad_id, cmd[5], cmd[6], cmd[7], cmd[8]);
		setCurrentPlayerNum(prevplayernum);
	}

	cmd += 9;

	return cmd;
}

/**
 * @cmd 0178
 */
static u8 *aiIfPlayerAutoWalkFinished(u8 *cmd)
{
	bool walking = false;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);

		if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
			walking = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	if (walking) {
		cmd += 5;
	} else {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	}

	return cmd;
}

/**
 * @cmd 0181
 */
static u8 *aiIfPlayerLookingAtObject(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[3]);
	bool pass = false;
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);

		if (g_Vars.currentplayer->lookingatprop.prop == obj->prop) {
			pass = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	if (pass) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 0182
 */
static u8 *aiPunchOrKick(u8 *cmd)
{
	if (g_Vars.chrdata && chrTryPunch(g_Vars.chrdata, cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0183
 */
static u8 *aiIfTargetIsPlayer(u8 *cmd)
{
	struct prop *target = chrGetTargetProp(g_Vars.chrdata);

	if (target->type == PROPTYPE_EYESPY || target->type == PROPTYPE_PLAYER) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0184
 */
static u8 *ai0184(u8 *cmd)
{
	chrTryAttackAmount(g_Vars.chrdata, 512, 0, cmd[2], cmd[3]);
	cmd += 4;

	return cmd;
}

/**
 * @cmd 0186
 */
static u8 *aiIfSoundTimer(u8 *cmd)
{
	s32 value = TICKS(cmd[3] | (cmd[2] << 8));

	if ((g_Vars.chrdata->soundtimer > value && cmd[4] == 0) ||
			(g_Vars.chrdata->soundtimer < value && cmd[4] == 1)) {
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd += 7;
	}

	return cmd;
}

/**
 * @cmd 0187
 */
static u8 *aiSetTargetToEyespyIfInSight(u8 *cmd)
{
	s16 prevtarget = g_Vars.chrdata->target;
	struct eyespy *eyespy = g_Vars.players[g_Vars.chrdata->p1p2]->eyespy;

	if (eyespy) {
		struct chrdata *chr = eyespy->prop->chr;
		g_Vars.chrdata->target = propGetIndexByChrId(g_Vars.chrdata, chr->chrnum);

		if (chrCheckTargetInSight(g_Vars.chrdata)) {
			cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
		} else {
			cmd += 4;
			g_Vars.chrdata->target = prevtarget;
		}
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0188
 */
static u8 *aiIfLiftStationary(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	bool pass = false;

	if (obj && obj->prop && obj->type == OBJTYPE_LIFT) {
		struct liftobj *lift = (struct liftobj *)obj;

		if ((obj->flags & OBJFLAG_DEACTIVATED) || lift->dist == 0) {
			pass = true;
		}
	}

	if (pass) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 018b
 */
static u8 *aiConfigureRain(u8 *cmd)
{
	weatherConfigureRain(cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 01b6
 */
static u8 *aiConfigureSnow(u8 *cmd)
{
	weatherConfigureSnow(cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 018c
 */
static u8 *aiChrToggleModelPart(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chrToggleModelPart(chr, cmd[3]);
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 018d
 */
static u8 *aiActivateLift(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[3]);

	if (obj && obj->prop) {
		liftActivate(obj->prop, cmd[2]);
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 018e
 */
static u8 *aiMiniSkedarTryPounce(u8 *cmd)
{
	u16 thing = cmd[4] | (cmd[3] << 8);

	if (chrTrySkJump(g_Vars.chrdata, g_Vars.chrdata->pouncebits, cmd[2], thing, cmd[5])) {
		cmd = AILABEL(g_Vars.ailist, cmd[6], cmd[7]);
	} else {
		cmd += 8;

	}

	return cmd;
}

/**
 * @cmd 018f
 */
static u8 *aiIfObjectDistanceToPadLessThan(u8 *cmd)
{
	f32 distance = (f32)(cmd[4] | (cmd[3] << 8)) * 10;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
#if VERSION >= VERSION_NTSC_1_0
	s32 pad_id = (cmd[6] | (cmd[5] << 8)) & 0xffff;
#else
	u16 pad_id = cmd[6] | (cmd[5] << 8);
#endif
	struct defaultobj *obj = objFindByTagId(cmd[2]);
	struct pad pad;
	bool pass = false;

	if (obj && obj->prop) {
		pad_id = chrResolvePadId(g_Vars.chrdata, pad_id);

		if (pad_id >= 0) {
			xdiff = obj->prop->pos.x - g_Pads[pad_id].pos.x;
			ydiff = obj->prop->pos.y - g_Pads[pad_id].pos.y;
			zdiff = obj->prop->pos.z - g_Pads[pad_id].pos.z;

			if (ydiff < 200 && ydiff > -200 &&
					xdiff < distance && xdiff > -distance &&
					zdiff < distance && zdiff > -distance) {
				pass = true;
			}
		}
	}

	if (pass) {
		cmd = AILABEL(g_Vars.ailist, cmd[7], cmd[8]);
	} else {
		cmd += 9;
	}

	return cmd;
}

/**
 * @cmd 0190
 */
static u8 *aiSetSavefileFlag(u8 *cmd)
{
	gamefileSetFlag(cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0191
 */
static u8 *aiUnsetSavefileFlag(u8 *cmd)
{
	gamefileUnsetFlag(cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 0192
 */
static u8 *aiIfSavefileFlagIsSet(u8 *cmd)
{
	if (gamefileHasFlag(cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 0193
 */
static u8 *aiIfSavefileFlagIsUnset(u8 *cmd)
{
	if (!gamefileHasFlag(cmd[2])) {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	} else {
		cmd += 5;
	}

	return cmd;
}

/**
 * @cmd 019e
 */
static u8 *aiIfObjHealthLessThan(u8 *cmd)
{
	s32 damage = cmd[4] | (cmd[3] << 8);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	bool condition_passes = false;

	if (obj && obj->prop && obj->damage < damage) {
		condition_passes = true;
	}

	if (condition_passes) {
		cmd = AILABEL(g_Vars.ailist, cmd[5], cmd[6]);
	} else {
		cmd += 7;
	}

	return cmd;
}

/**
 * @cmd 019f
 */
static u8 *aiSetObjHealth(u8 *cmd)
{
	s32 damage = cmd[4] | (cmd[3] << 8);
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		obj->damage = damage;
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 01a0
 */
static u8 *aiSetChrSpecialDeathAnimation(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chr->specialdie = cmd[3];
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 01a1
 */
static u8 *aiSetRoomToSearch(u8 *cmd)
{
	struct chrdata *target = chrFindById(g_Vars.chrdata, CHR_TARGET);

	if (target && target->prop) {
		g_Vars.chrdata->roomtosearch = target->prop->rooms[0];
	}

	cmd += 2;

	return cmd;
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
static u8 *aiSayCiStaffQuip(u8 *cmd)
{
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

	cmd += 4;

	return cmd;
}

/**
 * @cmd 01a3
 */
static u8 *aiDoPresetAnimation(u8 *cmd)
{
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
		chrTryStartAnim(g_Vars.chrdata, anims[7 + (random() % 8)], 0, -1, 0, 15, 0.5);
	} else if (cmd[2] == 254) {
		struct prop *prop0 = chrGetHeldProp(g_Vars.chrdata, 1);
		struct prop *prop1 = chrGetHeldProp(g_Vars.chrdata, 0);

		if (weaponIsOneHanded(prop0) || weaponIsOneHanded(prop1)) {
			chrTryStartAnim(g_Vars.chrdata, ANIM_FIX_GUN_JAM_EASY, 0, -1, 0, 5, 0.5);
		} else {
			chrTryStartAnim(g_Vars.chrdata, ANIM_FIX_GUN_JAM_HARD, 0, -1, 0, 5, 0.5);
		}
	} else if (cmd[2] == 3) {
		chrTryStartAnim(g_Vars.chrdata, anims[3 + (random() & 1)], 0, -1, 0, 15, 0.5);
	} else {
		chrTryStartAnim(g_Vars.chrdata, anims[cmd[2]], 0, -1, 0, 15, 0.5);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 01ae
 */
static u8 *aiClearInventory(u8 *cmd)
{
	u32 stackpadding[2];
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 playernum;

	for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
		setCurrentPlayerNum(playernum);

		if (g_Vars.currentplayer == g_Vars.bond || g_Vars.currentplayer == g_Vars.coop) {
			invClear();
#if VERSION >= VERSION_NTSC_1_0
			g_Vars.currentplayer->devicesactive = 0;
#endif
			invGiveSingleWeapon(WEAPON_UNARMED);
			bgunEquipWeapon(WEAPON_UNARMED);
		}
	}

	setCurrentPlayerNum(prevplayernum);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 01ad
 */
static u8 *aiReleaseObject(u8 *cmd)
{
	bmoveSetModeForAllPlayers(MOVEMODE_WALK);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 01af
 */
static u8 *aiChrGrabObject(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[3]);
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER && obj && obj->prop) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);

		if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK
				&& bmoveGetCrouchPos() == CROUCHPOS_STAND
				&& g_Vars.currentplayer->crouchoffset == 0) {
			bmoveGrabProp(obj->prop);
		}

		setCurrentPlayerNum(prevplayernum);
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 01b1
 */
static u8 *aiShuffleRuinsPillars(u8 *cmd)
{
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
	ptr1->cmdoffset = src->cmdoffset;
	ptr1->obj = src->obj;

	ptr1 = tagFindById(cmd[10]);
	src = tagFindById(mines[marked1index]);
	ptr1->cmdoffset = src->cmdoffset;
	ptr1->obj = src->obj;

	// Pillar/mine 2
	src = tagFindById(pillars[marked2index]);
	ptr2->cmdoffset = src->cmdoffset;
	ptr2->obj = src->obj;

	ptr2 = tagFindById(cmd[11]);
	src = tagFindById(mines[marked2index]);
	ptr2->cmdoffset = src->cmdoffset;
	ptr2->obj = src->obj;

	// Pillar/mine 3
	src = tagFindById(pillars[marked3index]);
	ptr3->cmdoffset = src->cmdoffset;
	ptr3->obj = src->obj;

	ptr3 = tagFindById(cmd[12]);
	src = tagFindById(mines[marked3index]);
	ptr3->cmdoffset = src->cmdoffset;
	ptr3->obj = src->obj;

	cmd += 18;

	return cmd;
}

/**
 * @cmd 01b2
 */
static u8 *aiSetWindSpeed(u8 *cmd)
{
	g_SkyWindSpeed = 0.1f * (s32)cmd[2];
	cmd += 3;

	return cmd;
}

/**
 * @cmd 01b3
 */
static u8 *aiToggleP1P2(u8 *cmd)
{
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

	cmd += 3;

	return cmd;
}

/**
 * @cmd 01b7
 */
static u8 *aiChrSetCloaked(u8 *cmd)
{
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

	cmd += 5;

	return cmd;
}

/**
 * @cmd 01b8
 */
static u8 *aiSetAutogunTargetTeam(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop && obj->type == OBJTYPE_AUTOGUN) {
		struct autogunobj *autogun = (struct autogunobj *)obj;
		autogun->targetteam = cmd[3];
		autogun->target = NULL;
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 01b9
 */
static u8 *aiShufflePelagicSwitches(u8 *cmd)
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
			tag->cmdoffset = button->cmdoffset;
			tag->obj = button->obj;
			buttonsdone[index] = 1;
		} else {
			// Switch is already mapped - find first unmapped switch
			for (j = 0; buttonsdone[j]; j++);

			button = tagFindById(j);
			tag->cmdoffset = button->cmdoffset;
			tag->obj = button->obj;
			buttonsdone[j] = 1;
		}
	}

	cmd += 2;

	return cmd;
}

/**
 * @cmd 01bd
 */
static u8 *aiIfTrainingPcHolographed(u8 *cmd)
{
	struct trainingdata *data = dtGetData();

	if (data->holographedpc) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 01be
 */
static u8 *aiIfPlayerUsingDevice(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	struct prop *prop = chr ? chr->prop : NULL;
	u8 active = false;

	if (prop && prop->type == PROPTYPE_PLAYER) {
		u32 playernum = playermgrGetPlayerNumByProp(prop);
		u32 prevplayernum = g_Vars.currentplayernum;
		setCurrentPlayerNum(playernum);

		if (currentPlayerGetDeviceState(cmd[3]) == DEVICESTATE_ACTIVE) {
			active = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	if (active) {
		cmd = AILABEL(g_Vars.ailist, cmd[4], cmd[5]);
	} else {
		cmd += 6;
	}

	return cmd;
}

/**
 * @cmd 01bf
 */
static u8 *aiChrBeginOrEndTeleport(u8 *cmd)
{
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
	chr = chrFindById(g_Vars.chrdata, cmd[4]);
	prevplayernum = g_Vars.currentplayernum;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
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

		handle = sndStart(var80095200, SFX_RELOAD_FARSIGHT, NULL, -1, -1, -1, -1, -1);

		if (handle) {
			audioPostEvent(handle, 16, *(u32 *)&fvalue);
		}

#if VERSION >= VERSION_NTSC_1_0
		osSetThreadPri(0, mainpri);
#endif
	}

	cmd += 5;

	setCurrentPlayerNum(prevplayernum);

	return cmd;
}

/**
 * @cmd 01c0
 */
static u8 *aiIfChrTeleportFullWhite(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[4]);
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
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
	}

	if (g_Vars.currentplayer->teleportstate < TELEPORTSTATE_WHITE) {
		cmd += 5;
	} else {
		fvalue = 0.4;

#if VERSION >= VERSION_NTSC_1_0
		mainpri = osGetThreadPri(0);
		audiopri = osGetThreadPri(&g_AudioManager.thread);
		osSetThreadPri(0, audiopri + 1);
#endif

		handle = sndStart(var80095200, SFX_FIRE_SHOTGUN, NULL, -1, -1, -1, -1, -1);

		if (handle) {
			audioPostEvent(handle, 16, *(u32 *)&fvalue);
		}

#if VERSION >= VERSION_NTSC_1_0
		osSetThreadPri(0, mainpri);
#endif

		g_Vars.currentplayer->teleportstate = TELEPORTSTATE_WHITE;
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	}

	setCurrentPlayerNum(prevplayernum);

	return cmd;
}

/**
 * @cmd 01ca
 */
static u8 *aiChrSetCutsceneWeapon(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	s32 model_id = playermgrGetModelOfWeapon(cmd[3]);
	s32 fallback_model_id = playermgrGetModelOfWeapon(cmd[4]);

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
						weaponDeleteFromChr(chr, HAND_LEFT);
						weaponDeleteFromChr(chr, HAND_RIGHT);
					}
				}
			} else {
				if (chr->weapons_held[0] == NULL && chr->weapons_held[1] == NULL && fallback_model_id >= 0) {
					weaponCreateForChr(chr, fallback_model_id, cmd[4], 0, NULL, NULL);
				}
			}
		} else {
			weaponDeleteFromChr(chr, HAND_LEFT);
			weaponDeleteFromChr(chr, HAND_RIGHT);

			if (model_id >= 0) {
				weaponCreateForChr(chr, model_id, cmd[3], 0, NULL, NULL);
			}

			if (fallback_model_id >= 0) {
				weaponCreateForChr(chr, fallback_model_id, cmd[4], OBJFLAG_WEAPON_LEFTHANDED, NULL, NULL);
			}
		}
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 01cb
 */
static u8 *aiFadeScreen(u8 *cmd)
{
	u32 color = (cmd[3] << 16) | (cmd[4] << 8) | cmd[5] | (cmd[2] << 24);
	s16 num_frames = (cmd[7] | (cmd[6] << 8));
	lvConfigureFade(color, num_frames);
	cmd += 8;

	return cmd;
}

/**
 * @cmd 01cd
 */
static u8 *aiSetChrHudpieceVisible(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr && chr->prop && chr->model) {
		chrSetHudpieceVisible(chr, cmd[3]);
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 01ce
 */
static u8 *aiSetPassiveMode(u8 *cmd)
{
	bgunSetPassiveMode(cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 01cf
 */
static u8 *aiChrSetFiringInCutscene(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);
	struct coord from = {0, 0, 0};
	struct coord to = {0, 0, 0};

	if (chr && chr->weapons_held[HAND_RIGHT]) {
		if (cmd[3]) {
			chrSetFiring(chr, HAND_RIGHT, true);
			chrCreateFireslot(chr, HAND_RIGHT, true, false, &from, &to);
		} else {
			chrSetFiring(chr, HAND_RIGHT, false);
		}
	}

	cmd += 4;

	return cmd;
}

/**
 * @cmd 01d0
 */
static u8 *aiSetPortalFlag(u8 *cmd)
{
	s16 portalnum = cmd[3] | (cmd[2] << 8);

	g_BgPortals[portalnum].flags |= cmd[4];
	cmd += 5;

	return cmd;
}

/**
 * @cmd 01d1
 */
static u8 *aiObjSetModelPartVisible(u8 *cmd)
{
	struct defaultobj *obj = objFindByTagId(cmd[2]);

	if (obj && obj->prop) {
		objSetModelPartVisible(obj, cmd[3], cmd[4]);
	}

	cmd += 5;

	return cmd;
}

/**
 * @cmd 01d2
 */
static u8 *aiChrEmitSparks(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

	if (chr) {
		chrDrCarollEmitSparks(chr);
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 01d3
 */
static u8 *aiSetDrCarollImages(u8 *cmd)
{
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

	cmd += 5;

	return cmd;
}

/**
 * @cmd 01d4
 */
static u8 *aiSetRoomFlag(u8 *cmd)
{
	s16 roomnum = cmd[3] | cmd[2] << 8;
	s16 flag = cmd[5] | cmd[4] << 8;

	g_Rooms[roomnum].flags |= flag;

	cmd += 6;

	return cmd;
}

/**
 * @cmd 01d5
 */
static u8 *aiShowCutsceneChrs(u8 *cmd)
{
	bool show = cmd[2];
	s32 i;

	if (show) {
		for (i = chrsGetNumSlots() - 1; i >= 0; i--) {
			if (g_ChrSlots[i].chrnum >= 0 && g_ChrSlots[i].prop && (g_ChrSlots[i].hidden2 & CHRH2FLAG_HIDDENFORCUTSCENE)) {
				g_ChrSlots[i].hidden2 &= ~CHRH2FLAG_HIDDENFORCUTSCENE;
				g_ChrSlots[i].chrflags &= ~CHRCFLAG_HIDDEN;
			}
		}
	} else {
		for (i = chrsGetNumSlots() - 1; i >= 0; i--) {
			if (g_ChrSlots[i].chrnum >= 0 && g_ChrSlots[i].prop &&
					(g_ChrSlots[i].chrflags & (CHRCFLAG_UNPLAYABLE | CHRCFLAG_HIDDEN)) == 0) {
				g_ChrSlots[i].hidden2 |= CHRH2FLAG_HIDDENFORCUTSCENE;
				g_ChrSlots[i].chrflags |= CHRCFLAG_HIDDEN;
			}
		}
	}

	cmd += 3;

	return cmd;
}

/**
 * @cmd 01d6
 */
static u8 *aiConfigureEnvironment(u8 *cmd)
{
	s16 room_id = (cmd[3] | (cmd[2] << 8));
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
		sndPlayNosedive(value);
		break;
	case AIENVCMD_TICKMUSICQUEUE:
		musicTickEvents();
		break;
	case AIENVCMD_ROOM_SETFAULTYLIGHTS:
		roomSetLightsFaulty(room_id, value);
		break;
	case AIENVCMD_STOPNOSEDIVE:
		sndStopNosedive();
		break;
	case AIENVCMD_PLAYUFOHUM:
		sndPlayUfo(value);
		break;
	case AIENVCMD_STOPUFOHUM:
		sndStopUfo();
		break;
	}

	cmd += 6;

	return cmd;
}

/**
 * @cmd 01d9
 */
static u8 *aiPlaySoundFromProp(u8 *cmd)
{
	s16 audio_id = cmd[5] | (cmd[4] << 8);
	s32 volumemaybe = cmd[7] | (cmd[6] << 8);
	u16 unk1 = cmd[10] | (cmd[10] << 8); // @bug: Using 10 twice
	s32 channel = (s8)cmd[2];
	s16 unk2 = cmd[8];
	struct defaultobj *obj = objFindByTagId(cmd[3]);

	audioPlayFromProp(channel, audio_id, volumemaybe, obj->prop, unk2, unk1);

	cmd += 11;

	return cmd;
}

/**
 * @cmd 01da
 */
static u8 *aiPlayTemporaryPrimaryTrack(u8 *cmd)
{
	musicStartTemporaryPrimary(cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 01db
 */
static u8 *aiChrKill(u8 *cmd)
{
	struct chrdata *chr = chrFindById(g_Vars.chrdata, cmd[2]);

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

	cmd += 3;

	return cmd;
}

/**
 * @cmd 01dc
 */
static u8 *aiRemoveWeaponFromInventory(u8 *cmd)
{
	invRemoveItemByNum(cmd[2]);
	cmd += 3;

	return cmd;
}

/**
 * @cmd 01dd
 */
static u8 *aiIfMusicEventQueueIsEmpty(u8 *cmd)
{
	f32 value = (u64)osGetCount() * 64 / 3000;

	if (g_MusicEventQueueLength) {
		cmd += 5;
	} else {
		cmd = AILABEL(g_Vars.ailist, cmd[3], cmd[4]);
	}

	return cmd;
}

/**
 * @cmd 01de
 */
static u8 *aiIfCoopMode(u8 *cmd)
{
	if (g_Vars.normmplayerisrunning == false && g_MissionConfig.iscoop) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 01e0
 */
static u8 *aiRemoveReferencesToChr(u8 *cmd)
{
	if (g_Vars.chrdata && g_Vars.chrdata->prop) {
		u32 index = g_Vars.chrdata->prop - g_Vars.props;
		chrClearReferences(index);
	}

	cmd += 2;

	return cmd;
}

/**
 * @cmd 01b4
 */
static u8 *ai01b4(u8 *cmd)
{
	if (g_Vars.chrdata && g_Vars.chrdata->prop &&
			chr0f01f264(g_Vars.chrdata, &g_Vars.chrdata->prop->pos, g_Vars.chrdata->prop->rooms, 0, false)) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
	} else {
		cmd += 4;
	}

	return cmd;
}

/**
 * @cmd 0185
 */
static u8 *aiMpInitSimulants(u8 *cmd)
{
	botSpawnAll();
	cmd += 2;
	return cmd;
}

/**
 * @cmd 0176
 */
static u8 *ai0176(u8 *cmd)
{
	struct aibot *aibot;

	/**
	 * @bug: Missing return means a crash will occur if either of these are
	 * null.
	 */
	if (!g_Vars.chrdata || !g_Vars.chrdata->aibot) {
		cmd += 4;
		return cmd;
	}

	aibot = g_Vars.chrdata->aibot;

	if (aibot->unk059 == 1) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
		aibot->unk059 = 0;
	} else {
		cmd += 4;
	}

	return cmd;
}

static u8 *aiSubCommand(u8 *cmd)
{
	switch (cmd[1]) {
	case 0x00: return aiIfCutsceneButtonPressed(cmd);
	case 0x01: return aiIfPlayerAutoWalkFinished(cmd);
	case 0x02: return aiIfSavefileFlagIsSet(cmd);
	case 0x03: return aiIfSavefileFlagIsUnset(cmd);
	case 0x04: return aiIfTrainingPcHolographed(cmd);
	case 0x05: return aiIfChrTeleportFullWhite(cmd);
	case 0x06: return aiIfMusicEventQueueIsEmpty(cmd);
	case 0x07: return aiSetPath(cmd);
	case 0x08: return aiStartPatrol(cmd);
	case 0x09: return aiSurrender(cmd);
	case 0x0a: return aiLockDoor(cmd);
	case 0x0b: return aiSetGrenadeProbability(cmd);
	case 0x0c: return aiSetChrNum(cmd);
	case 0x0d: return aiSetMaxDamage(cmd);
	case 0x0e: return aiAddHealth(cmd);
	case 0x0f: return aiSetReactionSpeed(cmd);
	case 0x10: return aiSetRecoverySpeed(cmd);
	case 0x11: return aiSetAccuracy(cmd);
	case 0x12: return aiShowCountdownTimer(cmd);
	case 0x13: return aiHideCountdownTimer(cmd);
	case 0x14: return aiSetCountdownTimerValue(cmd);
	case 0x15: return aiStopCountdownTimer(cmd);
	case 0x16: return aiStartCountdownTimer(cmd);
	case 0x17: return ai00d0(cmd);
	case 0x18: return aiHovercarBeginPath(cmd);
	case 0x19: return aiSetVehicleSpeed(cmd);
	case 0x1a: return aiSetRotorSpeed(cmd);
	case 0x1b: return aiEndLevel(cmd);
	case 0x1c: return ai00dd(cmd);
	case 0x1d: return aiWarpJoToPad(cmd);
	case 0x1e: return aiRevokeControl(cmd);
	case 0x1f: return aiGrantControl(cmd);
	case 0x20: return aiChrDrawWeaponInCutscene(cmd);
	case 0x21: return aiChrSetInvincible(cmd);
	case 0x22: return aiPlayXTrack(cmd);
	case 0x23: return aiStopXTrack(cmd);
	case 0x24: return aiChrExplosions(cmd);
	case 0x25: return aiSetLights(cmd);
	case 0x26: return aiChrSetTeam(cmd);
	case 0x27: return aiSetShield(cmd);
	case 0x28: return aiSetCameraAnimation(cmd);
	case 0x29: return aiSetSquadron(cmd);
	case 0x2a: return aiShuffleInvestigationTerminals(cmd);
	case 0x2b: return aiSetPadPresetToInvestigationTerminal(cmd);
	case 0x2c: return aiHeliArmWeapons(cmd);
	case 0x2d: return aiSetTintedGlassEnabled(cmd);
	case 0x2e: return aiPlayTrackIsolated(cmd);
	case 0x2f: return aiPlayDefaultTracks(cmd);
	case 0x30: return ai016b(cmd);
	case 0x31: return aiChrAdjustMotionBlur(cmd);
	case 0x32: return aiPlayerAutoWalk(cmd);
	case 0x33: return aiPlayCutsceneTrack(cmd);
	case 0x34: return aiStopCutsceneTrack(cmd);
	case 0x35: return aiPlayTemporaryTrack(cmd);
	case 0x36: return aiStopAmbientTrack(cmd);
	case 0x37: return aiMpInitSimulants(cmd);
	case 0x38: return aiConfigureRain(cmd);
	case 0x39: return aiChrToggleModelPart(cmd);
	case 0x3a: return aiActivateLift(cmd);
	case 0x3b: return aiSetSavefileFlag(cmd);
	case 0x3c: return aiUnsetSavefileFlag(cmd);
	case 0x3d: return aiSayCiStaffQuip(cmd);
	case 0x3e: return aiReleaseObject(cmd);
	case 0x3f: return aiClearInventory(cmd);
	case 0x40: return aiChrGrabObject(cmd);
	case 0x41: return aiShuffleRuinsPillars(cmd);
	case 0x42: return aiSetWindSpeed(cmd);
	case 0x43: return aiConfigureSnow(cmd);
	case 0x44: return aiShufflePelagicSwitches(cmd);
	case 0x45: return aiChrBeginOrEndTeleport(cmd);
	case 0x46: return aiSetDodgeRating(cmd);
	case 0x47: return aiSetUnarmedDodgeRating(cmd);
	case 0x48: return aiChrSetCutsceneWeapon(cmd);
	case 0x49: return aiSetChrHudpieceVisible(cmd);
	case 0x4a: return aiSetPassiveMode(cmd);
	case 0x4b: return aiChrSetFiringInCutscene(cmd);
	case 0x4c: return aiSetPortalFlag(cmd);
	case 0x4d: return aiObjSetModelPartVisible(cmd);
	case 0x4e: return aiSetDrCarollImages(cmd);
	case 0x4f: return aiSetRoomFlag(cmd);
	case 0x50: return aiShowCutsceneChrs(cmd);
	case 0x51: return aiConfigureEnvironment(cmd);
	case 0x52: return aiPlaySoundFromProp(cmd);
	case 0x53: return aiPlayTemporaryPrimaryTrack(cmd);
	case 0x54: return aiRemoveWeaponFromInventory(cmd);
	case 0x55: return aiRemoveReferencesToChr(cmd);
	}

	while (1);
}

void chraiExecute(void *entity, s32 proptype)
{
	u8 *cmd = NULL;

	g_Vars.chrdata = NULL;
	g_Vars.truck = NULL;
	g_Vars.heli = NULL;
	g_Vars.hovercar = NULL;
	g_Vars.ailist = NULL;

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
		cmd = g_Vars.chrdata->aioffset;
	} else if (g_Vars.truck) {
		g_Vars.ailist = g_Vars.truck->ailist;
		cmd = g_Vars.truck->aioffset;
	} else if (g_Vars.heli) {
		g_Vars.ailist = g_Vars.heli->ailist;
		cmd = g_Vars.heli->aioffset;
	} else if (g_Vars.hovercar) {
		g_Vars.ailist = g_Vars.hovercar->ailist;
		cmd = g_Vars.hovercar->aioffset;
	}

	if (g_Vars.ailist) {
		if (!cmd) {
			cmd = g_Vars.ailist;
		}

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
				cmd = g_Vars.ailist;
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
				cmd = g_Vars.ailist;
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
				cmd = g_Vars.ailist;
			}
		} else {
			// empty
		}

		// Iterate and execute the ailist
		do {
			switch (cmd[0]) {
			case 0x00: cmd = aiGoToNext(cmd); break;
			case 0x01: cmd = aiGoToFirst(cmd); break;
			case 0x02: cmd = aiIfIdle(cmd); break;
			case 0x03: cmd = aiTrySidestep(cmd); break;
			case 0x04: cmd = aiTryJumpOut(cmd); break;
			case 0x05: cmd = aiTryRunSideways(cmd); break;
			case 0x06: cmd = aiTryAttackWalk(cmd); break;
			case 0x07: cmd = aiTryAttackRoll(cmd); break;
			case 0x08: cmd = aiTryAttackStand(cmd); break;
			case 0x09: cmd = aiTryAttackKneel(cmd); break;
			case 0x0a: cmd = aiTryModifyAttack(cmd); break;
			case 0x0b: cmd = aiFaceEntity(cmd); break;
			case 0x0c: cmd = aiConsiderGrenadeThrow(cmd); break;
			case 0x0d: cmd = aiIfPatrolling(cmd); break;
			case 0x0e: cmd = aiTryJogToTargetProp(cmd); break;
			case 0x0f: cmd = aiTryWalkToTargetProp(cmd); break;
			case 0x10: cmd = aiTryRunToTargetProp(cmd); break;
			case 0x11: cmd = aiTryJogToChr(cmd); break;
			case 0x12: cmd = aiTryRunToChr(cmd); break;
			case 0x13: cmd = aiIfStopped(cmd); break;
			case 0x14: cmd = aiIfChrDead(cmd); break;
			case 0x15: cmd = aiIfChrDeathAnimationFinished(cmd); break;
			case 0x16: cmd = aiIfTargetInSight(cmd); break;
			case 0x17: cmd = aiIfRandomLessThan(cmd); break;
			case 0x18: cmd = aiIfRandomGreaterThan(cmd); break;
			case 0x19: cmd = aiIfCanHearAlarm(cmd); break;
			case 0x1a: cmd = aiIfAlarmActive(cmd); break;
			case 0x1b: cmd = aiIfHearsTarget(cmd); break;
			case 0x1c: cmd = aiIfSawInjury(cmd); break;
			case 0x1d: cmd = aiIfSawDeath(cmd); break;
			case 0x1e: cmd = aiIfCanSeeTarget(cmd); break;
			case 0x1f: cmd = aiIfNearlyInTargetsSight(cmd); break;
			case 0x20: cmd = aiIfHeardTargetRecently(cmd); break;
			case 0x21: cmd = ai0045(cmd); break;
			case 0x22: cmd = aiIfNeverBeenOnScreen(cmd); break;
			case 0x23: cmd = aiIfOnScreen(cmd); break;
			case 0x24: cmd = aiIfRoomIsOnScreen(cmd); break;
			case 0x25: cmd = ai004a(cmd); break;
			case 0x26: cmd = aiIfNearMiss(cmd); break;
			case 0x27: cmd = aiIfSeesSuspiciousItem(cmd); break;
			case 0x28: cmd = aiIfTargetInFovLeft(cmd); break;
			case 0x29: cmd = aiIfCheckFovWithTarget(cmd); break;
			case 0x2a: cmd = aiIfTargetOutOfFovLeft(cmd); break;
			case 0x2b: cmd = aiIfTargetInFov(cmd); break;
			case 0x2c: cmd = aiIfDistanceToTargetLessThan(cmd); break;
			case 0x2d: cmd = aiIfDistanceToTargetGreaterThan(cmd); break;
			case 0x2e: cmd = aiIfChrDistanceToPadLessThan(cmd); break;
			case 0x2f: cmd = aiIfChrDistanceToPadGreaterThan(cmd); break;
			case 0x30: cmd = aiIfDistanceToChrLessThan(cmd); break;
			case 0x31: cmd = aiIfDistanceToChrGreaterThan(cmd); break;
			case 0x32: cmd = aiIfDistanceFromTargetToPadLessThan(cmd); break;
			case 0x33: cmd = aiIfChrInRoom(cmd); break;
			case 0x34: cmd = aiIfChrHasObject(cmd); break;
			case 0x35: cmd = aiIfWeaponThrown(cmd); break;
			case 0x36: cmd = aiIfWeaponThrownOnObject(cmd); break;
			case 0x37: cmd = aiIfChrHasWeaponEquipped(cmd); break;
			case 0x38: cmd = aiIfGunUnclaimed(cmd); break;
			case 0x39: cmd = aiIfObjectHealthy(cmd); break;
			case 0x3a: cmd = aiIfChrActivatedObject(cmd); break;
			case 0x3b: cmd = aiIfDoorState(cmd); break;
			case 0x3c: cmd = aiIfDoorLocked(cmd); break;
			case 0x3d: cmd = aiIfObjectiveComplete(cmd); break;
			case 0x3e: cmd = aiIfObjectiveFailed(cmd); break;
			case 0x3f: cmd = ai0075(cmd); break;
			case 0x40: cmd = aiSetPadPresetToTargetQuadrant(cmd); break;
			case 0x41: cmd = aiIfDifficultyLessThan(cmd); break;
			case 0x42: cmd = aiIfDifficultyGreaterThan(cmd); break;
			case 0x43: cmd = aiIfStageIsNot(cmd); break;
			case 0x44: cmd = aiIfNumArghsLessThan(cmd); break;
			case 0x45: cmd = aiIfNumArghsGreaterThan(cmd); break;
			case 0x46: cmd = aiIfInjured(cmd); break;
			case 0x47: cmd = aiIfMoraleLessThan(cmd); break;
			case 0x48: cmd = aiIfAlertness(cmd); break;
			case 0x49: cmd = aiIfChrAlertnessLessThan(cmd); break;
			case 0x4a: cmd = aiIfHasFlag(cmd); break;
			case 0x4b: cmd = aiIfChrHasFlag(cmd); break;
			case 0x4c: cmd = aiIfStageFlagEq(cmd); break;
			case 0x4d: cmd = aiIfHasChrflag(cmd); break;
			case 0x4e: cmd = aiIfChrHasChrflag(cmd); break;
			case 0x4f: cmd = aiIfObjHasFlag2(cmd); break;
			case 0x50: cmd = aiIfTimerLessThan(cmd); break;
			case 0x51: cmd = aiIfTimerGreaterThan(cmd); break;
			case 0x52: cmd = aiIfCountdownTimerLessThan(cmd); break;
			case 0x53: cmd = aiIfCountdownTimerGreaterThan(cmd); break;
			case 0x54: cmd = aiSpawnChrAtPad(cmd); break;
			case 0x55: cmd = aiSpawnChrAtChr(cmd); break;
			case 0x56: cmd = aiTryEquipWeapon(cmd); break;
			case 0x57: cmd = aiDuplicateChr(cmd); break;
			case 0x58: cmd = aiChrMoveToPad(cmd); break;
			case 0x59: cmd = aiIfNumPlayersLessThan(cmd); break;
			case 0x5a: cmd = aiIfChrAmmoQuantityLessThan(cmd); break;
			case 0x5b: cmd = aiIfObjInRoom(cmd); break;
			case 0x5c: cmd = aiIfAllObjectivesComplete(cmd); break;
			case 0x5d: cmd = aiIfKillCountGreaterThan(cmd); break;
			case 0x5e: cmd = aiIfPresetsTargetIsNotMyTarget(cmd); break;
			case 0x5f: cmd = aiIfChrTarget(cmd); break;
			case 0x60: cmd = aiIfChrShieldLessThan(cmd); break;
			case 0x61: cmd = aiIfInCutscene(cmd); break;
			case 0x62: cmd = aiIfObjHasFlag3(cmd); break;
			case 0x63: cmd = aiIfChrHasHiddenFlag(cmd); break;
			case 0x64: cmd = aiIfSkedar(cmd); break;
			case 0x65: cmd = aiIfSafety2LessThan(cmd); break;
			case 0x66: cmd = aiFindCover(cmd); break;
			case 0x67: cmd = aiCheckCoverOutOfSight(cmd); break;
			case 0x68: cmd = aiIfPlayerUsingCmpOrAr34(cmd); break;
			case 0x69: cmd = aiDetectEnemyOnSameFloor(cmd); break;
			case 0x6a: cmd = aiDetectEnemy(cmd); break;
			case 0x6b: cmd = aiIfTargetMovingSlowly(cmd); break;
			case 0x6c: cmd = aiIfTargetMovingCloser(cmd); break;
			case 0x6d: cmd = aiIfTargetMovingAway(cmd); break;
			case 0x6e: cmd = aiSetTeamOrders(cmd); break;
			case 0x6f: cmd = aiIfOrders(cmd); break;
			case 0x70: cmd = aiIfHasOrders(cmd); break;
			case 0x71: cmd = aiIfChrInSquadronDoingAction(cmd); break;
			case 0x72: cmd = aiIfChannelIdle(cmd); break;
			case 0x73: cmd = aiSetChrPresetToUnalertedTeammate(cmd); break;
			case 0x74: cmd = aiIfDangerousObjectNearby(cmd); break;
			case 0x75: cmd = aiIfHoverbotNextStep(cmd); break;
			case 0x76: cmd = aiIfSquadronIsDead(cmd); break;
			case 0x77: cmd = aiIfNumChrsInSquadronGreaterThan(cmd); break;
			case 0x78: cmd = aiIfChrInjured(cmd); break;
			case 0x79: cmd = aiIfShieldDamaged(cmd); break;
			case 0x7a: cmd = aiIfNaturalAnim(cmd); break;
			case 0x7b: cmd = aiIfY(cmd); break;
			case 0x7c: cmd = aiIfChrHasGun(cmd); break;
			case 0x7d: cmd = aiDoGunCommand(cmd); break;
			case 0x7e: cmd = aiIfDistanceToGunLessThan(cmd); break;
			case 0x7f: cmd = aiRecoverGun(cmd); break;
			case 0x80: cmd = aiChrCopyProperties(cmd); break;
			case 0x81: cmd = ai0176(cmd); break;
			case 0x82: cmd = aiIfCanSeeAttackTarget(cmd); break;
			case 0x83: cmd = aiIfChrKnockedOut(cmd); break;
			case 0x84: cmd = aiIfPlayerLookingAtObject(cmd); break;
			case 0x85: cmd = aiPunchOrKick(cmd); break;
			case 0x86: cmd = aiIfTargetIsPlayer(cmd); break;
			case 0x87: cmd = aiIfSoundTimer(cmd); break;
			case 0x88: cmd = aiSetTargetToEyespyIfInSight(cmd); break;
			case 0x89: cmd = aiIfLiftStationary(cmd); break;
			case 0x8a: cmd = aiMiniSkedarTryPounce(cmd); break;
			case 0x8b: cmd = aiIfObjectDistanceToPadLessThan(cmd); break;
			case 0x8c: cmd = aiIfObjHealthLessThan(cmd); break;
			case 0x8d: cmd = aiIfChrNotTalking(cmd); break;
			case 0x8e: cmd = aiIfNumKnockedOutChrs(cmd); break;
			case 0x8f: cmd = ai01b4(cmd); break;
			case 0x90: cmd = aiTryAttackLie(cmd); break;
			case 0x91: cmd = aiIfPlayerUsingDevice(cmd); break;
			case 0x92: cmd = aiIfCoopMode(cmd); break;
			case 0x93: cmd = aiIfChrSameFloorDistanceToPadLessThan(cmd); break;
			case 0x94: cmd = aiLabel(cmd); break;
			case 0x95: cmd = aiYield(cmd); break;
			case 0x96: cmd = aiEndList(cmd); break;
			case 0x97: cmd = aiSetList(cmd); break;
			case 0x98: cmd = aiSetReturnList(cmd); break;
			case 0x99: cmd = aiSetShotList(cmd); break;
			case 0x9a: cmd = aiReturn(cmd); break;
			case 0x9b: cmd = aiStop(cmd); break;
			case 0x9c: cmd = aiKneel(cmd); break;
			case 0x9d: cmd = aiChrDoAnimation(cmd); break;
			case 0x9e: cmd = ai0019(cmd); break;
			case 0x9f: cmd = aiChrDamageChr(cmd); break;
			case 0xa0: cmd = aiJogToPad(cmd); break;
			case 0xa1: cmd = aiGoToPadPreset(cmd); break;
			case 0xa2: cmd = aiWalkToPad(cmd); break;
			case 0xa3: cmd = aiRunToPad(cmd); break;
			case 0xa4: cmd = aiFadeOut(cmd); break;
			case 0xa5: cmd = aiRemoveChr(cmd); break;
			case 0xa6: cmd = aiActivateAlarm(cmd); break;
			case 0xa7: cmd = aiDeactivateAlarm(cmd); break;
			case 0xa8: cmd = aiRandom(cmd); break;
			case 0xa9: cmd = aiDestroyObject(cmd); break;
			case 0xaa: cmd = aiChrDropItems(cmd); break;
			case 0xab: cmd = aiChrDropWeapon(cmd); break;
			case 0xac: cmd = aiGiveObjectToChr(cmd); break;
			case 0xad: cmd = aiObjectMoveToPad(cmd); break;
			case 0xae: cmd = aiOpenDoor(cmd); break;
			case 0xaf: cmd = aiCloseDoor(cmd); break;
			case 0xb0: cmd = aiUnlockDoor(cmd); break;
			case 0xb1: cmd = aiSetMorale(cmd); break;
			case 0xb2: cmd = aiAddMorale(cmd); break;
			case 0xb3: cmd = aiSubtractMorale(cmd); break;
			case 0xb4: cmd = aiSetAlertness(cmd); break;
			case 0xb5: cmd = aiAddAlertness(cmd); break;
			case 0xb6: cmd = aiChrAddAlertness(cmd); break;
			case 0xb7: cmd = aiSetHearDistance(cmd); break;
			case 0xb8: cmd = aiSetViewDistance(cmd); break;
			case 0xb9: cmd = aiSetFlag(cmd); break;
			case 0xba: cmd = aiUnsetFlag(cmd); break;
			case 0xbb: cmd = aiChrSetFlag(cmd); break;
			case 0xbc: cmd = aiChrUnsetFlag(cmd); break;
			case 0xbd: cmd = aiSetStageFlag(cmd); break;
			case 0xbe: cmd = aiUnsetStageFlag(cmd); break;
			case 0xbf: cmd = aiSetChrflag(cmd); break;
			case 0xc0: cmd = aiUnsetChrflag(cmd); break;
			case 0xc1: cmd = aiChrSetChrflag(cmd); break;
			case 0xc2: cmd = aiChrUnsetChrflag(cmd); break;
			case 0xc3: cmd = aiSetObjFlag(cmd); break;
			case 0xc4: cmd = aiUnsetObjFlag(cmd); break;
			case 0xc5: cmd = aiSetObjFlag2(cmd); break;
			case 0xc6: cmd = aiUnsetObjFlag2(cmd); break;
			case 0xc7: cmd = aiSetChrPreset(cmd); break;
			case 0xc8: cmd = aiSetChrTarget(cmd); break;
			case 0xc9: cmd = aiSetPadPreset(cmd); break;
			case 0xca: cmd = aiRestartTimer(cmd); break;
			case 0xcb: cmd = aiResetTimer(cmd); break;
			case 0xcc: cmd = aiPauseTimer(cmd); break;
			case 0xcd: cmd = aiResumeTimer(cmd); break;
			case 0xce: cmd = aiShowHudmsg(cmd); break;
			case 0xcf: cmd = aiShowHudmsgTopMiddle(cmd); break;
			case 0xd0: cmd = aiSpeak(cmd); break;
			case 0xd1: cmd = aiPlaySound(cmd); break;
			case 0xd2: cmd = ai00cf(cmd); break;
			case 0xd3: cmd = aiAudioMuteChannel(cmd); break;
			case 0xd4: cmd = aiSetObjImage(cmd); break;
			case 0xd5: cmd = aiSetDoorOpen(cmd); break;
			case 0xd6: cmd = aiChrDrawWeapon(cmd); break;
			case 0xd7: cmd = aiSetTarget(cmd); break;
			case 0xd8: cmd = aiObjectDoAnimation(cmd); break;
			case 0xd9: cmd = aiEnableChr(cmd); break;
			case 0xda: cmd = aiDisableChr(cmd); break;
			case 0xdb: cmd = aiEnableObj(cmd); break;
			case 0xdc: cmd = aiDisableObj(cmd); break;
			case 0xdd: cmd = aiSetObjFlag3(cmd); break;
			case 0xde: cmd = aiUnsetObjFlag3(cmd); break;
			case 0xdf: cmd = aiChrSetHiddenFlag(cmd); break;
			case 0xe0: cmd = aiChrUnsetHiddenFlag(cmd); break;
			case 0xe1: cmd = aiGoToCover(cmd); break;
			case 0xe2: cmd = ai012f(cmd); break;
			case 0xe3: cmd = aiSayQuip(cmd); break;
			case 0xe4: cmd = aiIncreaseSquadronAlertness(cmd); break;
			case 0xe5: cmd = aiSetAction(cmd); break;
			case 0xe6: cmd = aiRetreat(cmd); break;
			case 0xe7: cmd = ai0139(cmd); break;
			case 0xe8: cmd = ai013e(cmd); break;
			case 0xe9: cmd = aiRebuildTeams(cmd); break;
			case 0xea: cmd = aiHovercopterFireRocket(cmd); break;
			case 0xeb: cmd = aiDamageChrByAmount(cmd); break;
			case 0xec: cmd = ai0175(cmd); break;
			case 0xed: cmd = ai0179(cmd); break;
			case 0xee: cmd = aiAssignSound(cmd); break;
			case 0xef: cmd = ai0184(cmd); break;
			case 0xf0: cmd = aiSetObjHealth(cmd); break;
			case 0xf1: cmd = aiSetChrSpecialDeathAnimation(cmd); break;
			case 0xf2: cmd = aiSetRoomToSearch(cmd); break;
			case 0xf3: cmd = aiDoPresetAnimation(cmd); break;
			case 0xf4: cmd = aiShowHudmsgMiddle(cmd); break;
			case 0xf5: cmd = aiToggleP1P2(cmd); break;
			case 0xf6: cmd = aiChrSetCloaked(cmd); break;
			case 0xf7: cmd = aiSetAutogunTargetTeam(cmd); break;
			case 0xf8: cmd = aiSetShootingAtMeList(cmd); break;
			case 0xf9: cmd = aiSetDarkRoomList(cmd); break;
			case 0xfa: cmd = aiFadeScreen(cmd); break;
			case 0xfb: cmd = aiChrEmitSparks(cmd); break;
			case 0xfc: cmd = aiChrKill(cmd); break;
			case 0xff: cmd = aiSubCommand(cmd); break;
			default:
				while (1);
			}
		} while (cmd);
	}
}
