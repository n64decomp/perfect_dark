#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "lib/ailist.h"
#include "lib/anim.h"
#include "lib/lib_317f0.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/mtx.h"
#include "lib/rng.h"
#include "lib/snd.h"
#include "game/atan2f.h"
#include "game/bg.h"
#include "game/bondgun.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chr.h"
#include "game/chraction.h"
#include "game/dlights.h"
#include "game/explosions.h"
#include "game/game_0b0fd0.h"
#include "game/hudmsg.h"
#include "game/inv.h"
#include "game/lang.h"
#include "game/lv.h"
#include "game/modelmgr.h"
#include "game/objectives.h"
#include "game/pad.h"
#include "game/player.h"
#include "game/playermgr.h"
#include "game/playerreset.h"
#include "game/prop.h"
#include "game/propobj.h"
#include "game/propsnd.h"
#include "game/smoke.h"
#include "game/stagetable.h"
#include "game/training.h"
#include "types.h"

bool ai0045(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	return chr && chr->prop && chrHasLineOfSightToPos(self, &chr->prop->pos, chr->prop->rooms);
}

void ai00cf(s32 channel, s32 tagnum, bool thing)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		audioPlayFromProp2(channel, -1, -1, obj->prop, thing, 2500, 3000, 0);
	}
}

void ai00d0(s32 padnum, s32 sound)
{
	propsnd0f0939f8(0, NULL, sound, padnum, -1, 2, 0, 0, 0, -1, 0, -1, -1, -1, -1);
}

void ai0139(struct chrdata *self, u32 angle, s32 arg1, s32 arg2)
{
	struct coord pos;

	chr0f04c874(self, angle, &pos, arg1, arg2);
}

void ai013e(struct chrdata *self)
{
	if (func0f03aca0(self, 400, true) == 0 && chrAssignCoverAwayFromDanger(self, 1000, 12000) != -1) {
		chrGoToCover(self, GOPOSFLAG_RUN);
	}
}

void ai016b(s32 channel, s32 tagnum, s32 thing1, s32 thing2, s32 thing3)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		s32 thing1again;

		if (thing1 == 0) {
			thing1again = -1;
		} else {
			thing1again = thing1;
		}

		audioPlayFromProp2(channel, -1, -1, obj->prop, thing1again, thing2, thing3, 2);
	}
}

bool ai0176(struct chrdata *self)
{
	if (self->aibot->unk059 == 1) {
		self->aibot->unk059 = 0;
		return true;
	}

	return false;
}

bool ai01b4(struct chrdata *self)
{
	return self && self->prop && chr0f01f264(self, &self->prop->pos, self->prop->rooms, 0, false);
}

void aiActivateLift(s32 liftnum, s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		liftActivate(obj->prop, liftnum);
	}
}

void aiAssignSound(s32 soundnum, s32 channel)
{
	audioPlayFromProp(channel, soundnum, -1, NULL, 11, 0);
}

void aiAttackAmount(struct chrdata *self, s32 value1, s32 value2)
{
	chrTryAttackAmount(self, 512, 0, value1, value2);
}

void aiAutoWalk(struct chrdata *self, s32 chrref, s32 padnum, s32 walkspeed, s32 turnspeed, s32 lookup, s32 dist)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		playerAutoWalk(padnum, walkspeed, turnspeed, lookup, dist);
		setCurrentPlayerNum(prevplayernum);
	}
}

void aiChrBeginTeleport(struct chrdata *self, s32 chrref, s32 padnum)
{
	f32 fvalue;
	struct chrdata *chr;
	s32 mainpri;
	u32 playernum;
	u32 prevplayernum;
	s32 audiopri;
	struct sndstate *handle;
	fvalue = 0.4;

	chr = chrFindById(self, chrref);
	prevplayernum = g_Vars.currentplayernum;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
	}

	g_Vars.currentplayer->teleporttime = 0;
	g_Vars.currentplayer->teleportstate = TELEPORTSTATE_PREENTER;
	g_Vars.currentplayer->teleportpad = padnum;
	g_Vars.currentplayer->teleportcamerapad = 0;

	mainpri = osGetThreadPri(0);
	audiopri = osGetThreadPri(&g_AudioManager.thread);
	osSetThreadPri(0, audiopri + 1);

	handle = sndStart(var80095200, SFX_RELOAD_FARSIGHT, NULL, -1, -1, -1, -1, -1);

	if (handle) {
		audioPostEvent(handle, 16, *(u32 *)&fvalue);
	}

	osSetThreadPri(0, mainpri);

	setCurrentPlayerNum(prevplayernum);
}

void aiChrEndTeleport(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr;
	u32 playernum;
	u32 prevplayernum;

	chr = chrFindById(self, chrref);
	prevplayernum = g_Vars.currentplayernum;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
	}

	g_Vars.currentplayer->teleportstate = TELEPORTSTATE_EXITING;
	g_Vars.currentplayer->teleporttime = 0;

	setCurrentPlayerNum(prevplayernum);
}

void aiCallRng(struct chrdata *self)
{
	self->random = random() & 0xff;
}

bool aiCheckCoverOutOfSight(struct chrdata *self)
{
	return chrCheckCoverOutOfSight(self, self->cover, false);
}

void aiChrAddAlertness(struct chrdata *self, s32 chrref, s32 amount)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop) {
		incrementByte(&chr->alertness, amount);
	}
}

void aiChrAddMotionBlur(struct chrdata *self, s32 chrref, s32 amount)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr) {
		chr->blurdrugamount += TICKS(amount);
	}
}

bool aiChrCopyProperties(struct chrdata *self, s32 srcchrref)
{
	struct chrdata *chr = chrFindById(self, srcchrref);

	if (chr && chr->model) {
		self->hearingscale = chr->hearingscale;
		self->visionrange = chr->visionrange;
		self->padpreset1 = chr->padpreset1;
		self->chrpreset1 = chr->chrpreset1;
		self->flags = chr->flags;
		self->flags2 = chr->flags2;
		self->team = chr->team;
		self->squadron = chr->squadron;
		self->naturalanim = chr->naturalanim;
		self->myspecial = chr->myspecial;
		self->yvisang = chr->yvisang;
		self->teamscandist = chr->teamscandist;

		return true;
	}

	return false;
}

void aiChrDamageChr(struct chrdata *self, s32 chr1num, s32 chr2num, s32 hitpart)
{
	struct chrdata *chr1 = chrFindById(self, chr1num);
	struct chrdata *chr2 = chrFindById(self, chr2num);

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
			chrDamageByImpact(chr2, damage, &vector, &weapon->gset, chr1->prop, hitpart);
		}
	}
}

void aiChrDoAnimation(struct chrdata *self, s32 chrref, s32 anim_id, s32 startframe, s32 endframe, s32 chranimflags, s32 timemerge, s32 animspeed)
{
	struct chrdata *chr = NULL;
	f32 fstartframe;
	f32 fendframe;

	if (self) {
		chr = chrFindById(self, chrref);
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
		f32 speed = 1.0f / animspeed;

		if (g_Vars.in_cutscene) {
			if (startframe != 0xfffe) {
				fstartframe += g_CutsceneFrameOverrun240 * speed * 0.25f;
			}

			chr->prop->propupdate240 = 0;
		}

		chrTryStartAnim(chr, anim_id, fstartframe, fendframe, chranimflags, timemerge, speed);

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
}

void aiChrEmitSparks(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr) {
		chrDrCarollEmitSparks(chr);
	}
}

void aiChrExplosions(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		playerSurroundWithExplosions(0);
		setCurrentPlayerNum(prevplayernum);
	}
}

void aiChrGrabObject(struct chrdata *self, s32 chrref, s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];
	struct chrdata *chr = chrFindById(self, chrref);

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
}

void aiChrKill(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

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
}

bool aiChrMoveToChr(struct chrdata *self, s32 chrref, s32 chrref2)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop) {
		struct chrdata *chr2 = chrFindById(self, chrref2);

		if (chr2 && chr2->prop) {
			f32 theta = chrGetInverseTheta(chr2);
			return chrMoveToPos(chr, &chr2->prop->pos, chr2->prop->rooms, theta, 0);
		}
	}

	return false;
}

bool aiChrMoveToPad(struct chrdata *self, s32 chrref, s32 padnum, bool allowonscreen)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop) {
		padnum = chrResolvePadId(chr, padnum);

		if (padnum >= 0) {
			struct pad *pad = &g_Pads[padnum];
			f32 theta = atan2f(pad->look.x, pad->look.z);
			s16 rooms[2];

			rooms[0] = pad->room;
			rooms[1] = -1;

			return chrMoveToPos(chr, &pad->pos, rooms, theta, allowonscreen);
		}
	}

	return false;
}

void aiChrSetCutsceneWeapon(struct chrdata *self, s32 chrref, s32 weapon1num, s32 weapon2num)
{
	struct chrdata *chr = chrFindById(self, chrref);
	s32 model_id = playermgrGetModelOfWeapon(weapon1num);
	s32 fallback_model_id = playermgrGetModelOfWeapon(weapon2num);

	if (chr) {
		if (weapon1num == 0xff) {
			if (weapon2num == 0xff) {
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
					weaponCreateForChr(chr, fallback_model_id, weapon2num, 0, NULL, NULL);
				}
			}
		} else {
			weaponDeleteFromChr(chr, HAND_LEFT);
			weaponDeleteFromChr(chr, HAND_RIGHT);

			if (model_id >= 0) {
				weaponCreateForChr(chr, model_id, weapon1num, 0, NULL, NULL);
			}

			if (fallback_model_id >= 0) {
				weaponCreateForChr(chr, fallback_model_id, weapon2num, OBJFLAG_WEAPON_LEFTHANDED, NULL, NULL);
			}
		}
	}
}

void aiChrSetFiringInCutscene(struct chrdata *self, s32 chrref, bool firing)
{
	struct chrdata *chr = chrFindById(self, chrref);
	struct coord from = {0, 0, 0};
	struct coord to = {0, 0, 0};

	if (chr && chr->weapons_held[HAND_RIGHT]) {
		if (firing) {
			chrSetFiring(chr, HAND_RIGHT, true);
			chrCreateFireslot(chr, HAND_RIGHT, true, false, &from, &to);
		} else {
			chrSetFiring(chr, HAND_RIGHT, false);
		}
	}
}

void aiChrSetChrflag(struct chrdata *self, s32 chrref, u32 flag)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr) {
		chr->chrflags |= flag;
	}
}

void aiChrSetCloaked(struct chrdata *self, s32 chrref, bool enable, bool withsound)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop && !chrIsDead(chr)) {
		if (enable) {
			chrCloak(chr, withsound);
		} else {
			chrUncloak(chr, withsound);
		}
	}
}

void aiChrSetHiddenFlag(struct chrdata *self, s32 chrref, u32 flag)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr) {
		chr->hidden |= flag;
	}
}

void aiChrSetTeam(struct chrdata *self, s32 chrref, s32 team)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr) {
		chr->team = team;
	}
}

void aiChrToggleModelPart(struct chrdata *self, s32 chrref, s32 partnum)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr) {
		chrToggleModelPart(chr, partnum);
	}
}

void aiChrToggleP1P2(struct chrdata *self, s32 chrref)
{
	if (g_Vars.coopplayernum >= 0) {
		struct chrdata *chr = chrFindById(self, chrref);

		if (chr) {
			if (chr->p1p2 == g_Vars.bondplayernum && !g_Vars.coop->isdead) {
				chr->p1p2 = g_Vars.coopplayernum;
			} else if (!g_Vars.bond->isdead) {
				chr->p1p2 = g_Vars.bondplayernum;
			}
		}
	}
}

void aiChrUnsetChrflag(struct chrdata *self, s32 chrref, u32 flag)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr) {
		chr->chrflags &= ~flag;
	}
}

void aiChrUnsetHiddenFlag(struct chrdata *self, s32 chrref, u32 flag)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr) {
		chr->hidden &= ~flag;
	}
}

void aiClearInventory(void)
{
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 playernum;

	for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
		setCurrentPlayerNum(playernum);

		if (g_Vars.currentplayer == g_Vars.bond || g_Vars.currentplayer == g_Vars.coop) {
			invClear();
			g_Vars.currentplayer->devicesactive = 0;
			invGiveSingleWeapon(WEAPON_UNARMED);
			bgunEquipWeapon(WEAPON_UNARMED);
		}
	}

	setCurrentPlayerNum(prevplayernum);
}

void aiCloseDoor(s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		doorsRequestMode(door, DOORMODE_CLOSING);
	}
}

bool aiConsiderGrenadeThrow(struct chrdata *self)
{
	return chrConsiderGrenadeThrow(self, 512, 0);
}

void aiDamageChrByAmount(struct chrdata *self, s32 chrref, f32 damage)
{
	struct coord coord = {0, 0, 0};
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop) {
		chrDamageByMisc(chr, damage, &coord, NULL, NULL);
	}
}

void aiDamageAndPoisonChrByAmount(struct chrdata *self, s32 chrref, f32 damage)
{
	struct coord coord = {0, 0, 0};
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop) {
		struct gset gset = {WEAPON_COMBATKNIFE, 0, 0, FUNC_POISON};
		chrDamageByMisc(chr, damage, &coord, &gset, NULL);
	}
}

void aiDamageChr(struct chrdata *self, s32 chrref, s32 hitpart, u32 gset)
{
	struct chrdata *chr = chrFindById(self, chrref);
	struct coord pos = {0, 0, 0};

	if (chr && chr->prop) {
		f32 damage = gsetGetDamage((struct gset *)&gset);
		chrDamageByImpact(chr, damage, &pos, (struct gset *)&gset, NULL, hitpart);
	}
}

void aiDestroyObject(s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

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
}

bool aiDetectEnemy(struct chrdata *self, f32 maxdist)
{
	s16 *chrnums;
	s32 team = 0;
	f32 closestdist = 10000000;
	s16 closesttarg = -1;

	chrnums = teamGetChrIds(1);

	if (!self) {
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

		while (*chrnums != -2 && self->team != teamvalue) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->prop
					&& !chrIsDead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP
					&& chrCompareTeams(self, chr, COMPARE_ENEMIES)
					&& chr != self
					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
					&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0
					&& (chr->hidden & CHRHFLAG_DISGUISED) == 0
					&& chr->team != TEAM_NONCOMBAT
					&& (
						(self->hidden & CHRHFLAG_PSYCHOSISED) == 0
						|| (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0
						|| (chr->hidden & CHRHFLAG_DONTSHOOTME))) {
				f32 distance = chrGetDistanceToChr(self, chr->chrnum);

				if (distance < maxdist && distance != 0 && distance < closestdist
						&& chrCanSeeProp(self, chr->prop)
						&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0) {
					if (self->yvisang == 0) {
						closestdist = distance;
						closesttarg = chr->chrnum;
					} else {
						s16 prevtarget = self->target;
						self->target = propGetIndexByChrId(self, chr->chrnum);

						if (chrIsVerticalAngleToTargetWithin(self, self->yvisang)) {
							closestdist = distance;
							closesttarg = chr->chrnum;
						}

						self->target = prevtarget;
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
		self->target = propGetIndexByChrId(self, closesttarg);
		return true;
	}

	return false;
}

bool aiDetectEnemyOnSameFloor(struct chrdata *self)
{
	s32 team = 0;
	f32 closestdist = 9999.9;
	f32 distance;
	u32 stack[2];
	f32 y;
	f32 scandist;
	s16 *chrnums = teamGetChrIds(1);
	struct chrdata *chr;
	s16 newtarget = -1;

	if (self->teamscandist == 0) {
		scandist = 1500;
	} else if (self->teamscandist == 255) {
		scandist = 9999;
	} else {
		scandist = self->teamscandist * 40.0f;
	}

	y = self->prop->pos.y;

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
					&& chrCompareTeams(self, chr, COMPARE_ENEMIES)
					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
					&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0
					&& (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0
					&& y - chr->prop->pos.y > -200
					&& y - chr->prop->pos.y < 200
					&& ((self->hidden & CHRHFLAG_PSYCHOSISED) == 0
						|| (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0
						|| (chr->hidden & CHRHFLAG_DONTSHOOTME))
					&& self->chrnum != chr->chrnum) {
				distance = chrGetDistanceToChr(self, chr->chrnum);

				if (distance < closestdist) {
					if (distance < scandist || g_Vars.stagenum == STAGE_MAIANSOS) {
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
		self->target = propGetIndexByChrId(self, newtarget);
		return true;
	}

	return false;
}

void aiDoPresetAnimation(struct chrdata *self, u32 value)
{
	// These all appear to be talking animations
	static u16 anims[] = {
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

	if (value == 255) {
		chrTryStartAnim(self, anims[7 + (random() % 8)], 0, -1, 0, 15, 0.5);
	} else if (value == 254) {
		struct prop *prop0 = chrGetHeldProp(self, 1);
		struct prop *prop1 = chrGetHeldProp(self, 0);

		if (weaponIsOneHanded(prop0) || weaponIsOneHanded(prop1)) {
			chrTryStartAnim(self, ANIM_FIX_GUN_JAM_EASY, 0, -1, 0, 5, 0.5);
		} else {
			chrTryStartAnim(self, ANIM_FIX_GUN_JAM_HARD, 0, -1, 0, 5, 0.5);
		}
	} else if (value == 3) {
		chrTryStartAnim(self, anims[3 + (random() & 1)], 0, -1, 0, 15, 0.5);
	} else {
		chrTryStartAnim(self, anims[value], 0, -1, 0, 15, 0.5);
	}
}

void aiChrDrawWeapon(struct chrdata *self, s32 chrref, s32 weaponnum)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		bgunEquipWeapon2(0, weaponnum);
		bgunEquipWeapon2(1, 0);
		setCurrentPlayerNum(prevplayernum);
	}
}

void aiChrDrawWeaponInCutscene(struct chrdata *self, s32 chrref, s32 weaponnum)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		bgunEquipWeapon(weaponnum);
		setCurrentPlayerNum(prevplayernum);
	}
}

void aiChrDropItems(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop) {
		chrDropConcealedItems(chr);
	}
}

void aiChrDropWeapon(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 prevplayernum = g_Vars.currentplayernum;
			u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
			u32 weaponnum;
			setCurrentPlayerNum(playernum);
			weaponnum = bgunGetWeaponNum(HAND_RIGHT);
			invRemoveItemByNum(weaponnum);
			bgunCycleBack();
			setCurrentPlayerNum(prevplayernum);
		} else {
			if (chr->weapons_held[0]) {
				objSetDropped(chr->weapons_held[0], DROPTYPE_DEFAULT);
				chr->hidden |= CHRHFLAG_00000001;
			}

			if (chr->weapons_held[1]) {
				objSetDropped(chr->weapons_held[1], DROPTYPE_DEFAULT);
				chr->hidden |= CHRHFLAG_00000001;
			}
		}
	}
}

void aiDisableChr(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop && chr->model) {
		propDeregisterRooms(chr->prop);
		propDelist(chr->prop);
		propDisable(chr->prop);
	}
}

void aiDisableObj(s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop && obj->model) {
		if (obj->prop->parent) {
			objDetach(obj->prop);
		} else {
			propDeregisterRooms(obj->prop);
			propDelist(obj->prop);
			propDisable(obj->prop);
		}
	}
}

bool aiDuplicateChr(struct chrdata *self, s32 chrref, u8 *ailist, u32 spawnflags)
{
	struct chrdata *chr = chrFindById(self, chrref);
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
		cloneprop = chrSpawnAtChr(self, chr->bodynum, -1, chr->chrnum, ailist, spawnflags);

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

			return true;
		}
	}

	return false;
}

void aiEnableChr(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop && chr->model) {
		propActivate(chr->prop);
		propEnable(chr->prop);
		chr0f0220ac(chr);
	}
}

void aiEnableObj(s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

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
}

void aiEndLevel(void)
{
	if (g_IsTitleDemo) {
		mainChangeToStage(STAGE_TITLE);
	} else if (g_Vars.autocutplaying) {
		g_Vars.autocutfinished = true;
	} else {
		func0000e990();
	}
}

bool aiFindCover(struct chrdata *self, u32 criteria)
{
	return self && self->prop && chrAssignCoverByCriteria(self, criteria, 0) != -1;
}

f32 aiGetChrShield(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	return chr->cshield;
}

bool aiIfRoomIsOnScreen(struct chrdata *self, s32 padnum)
{
	s32 roomnum = chrGetPadRoom(self, padnum);

	return roomnum >= 0 && roomIsOnscreen(roomnum);
}

s32 aiGetHoverbotNextStep(void)
{
	if (g_Vars.hovercar) {
		return g_Vars.hovercar->nextstep;
	}

	return 0;
}

s32 aiGetKillCount(void)
{
	return g_Vars.killcount;
}

s32 aiGetNumChrsInSquadron(s32 squadron)
{
	s32 count = 0;
	s16 *chrnums = squadronGetChrIds(squadron);

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

	return count;
}

s32 aiGetNumPlayers(void)
{
	return PLAYERCOUNT();
}

s32 aiGetObjDamage(s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (!obj || !obj->prop) {
		return 0;
	}

	return obj->damage;
}

s32 aiGetTimer(struct chrdata *self)
{
	if (self) {
		return self->timer60;
	}

	if (g_Vars.hovercar) {
		return chopperGetTimer(g_Vars.hovercar);
	}

	return 0;
}

s32 aiGetRandom(struct chrdata *self)
{
	if (self) {
		return self->random;
	}

	if (g_Vars.hovercar) {
		return random() & 0xff;
	}

	return 0;
}

void aiGiveObjectToChr(struct chrdata *self, s32 tagnum, s32 chrref)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];
	struct chrdata *chr = chrFindById(self, chrref);

	if (obj && obj->prop && chr && chr->prop) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			u32 something;
			u32 prevplayernum = g_Vars.currentplayernum;
			struct defaultobj *obj2 = obj->prop->obj;
			u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
			setCurrentPlayerNum(playernum);

			if (obj->prop->parent) {
				objDetach(obj->prop);
				objFreeEmbedmentOrProjectile(obj->prop);
				propActivate(obj->prop);
			}

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
}

void aiGoToPadPreset(struct chrdata *self, s32 speed)
{
	chrGoToPad(self, self->padpreset1, speed);
}

void aiGrantControl(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

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
}

void aiHeliArmWeapons(void)
{
	if (g_Vars.hovercar) {
		chopperSetArmed(g_Vars.hovercar, true);
	}
}

void aiHideCutsceneChrs(void)
{
	s32 i;

	for (i = g_NumChrSlots - 1; i >= 0; i--) {
		if (g_ChrSlots[i].chrnum >= 0 && g_ChrSlots[i].prop &&
				(g_ChrSlots[i].chrflags & (CHRCFLAG_UNPLAYABLE | CHRCFLAG_HIDDEN)) == 0) {
			g_ChrSlots[i].hidden2 |= CHRH2FLAG_HIDDENFORCUTSCENE;
			g_ChrSlots[i].chrflags |= CHRCFLAG_HIDDEN;
		}
	}
}

void aiHovercarBeginPath(s32 pathid)
{
	struct path *path = pathFindById(pathid);

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
}

void aiHovercopterFireRocket(s32 side)
{
	chopperFireRocket(g_Vars.hovercar, side);
}

bool aiIfAnyoneActivatedObject(s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		if (obj->hidden & (OBJHFLAG_ACTIVATED_BY_BOND | OBJHFLAG_ACTIVATED_BY_COOP)) {
			obj->hidden &= ~(OBJHFLAG_ACTIVATED_BY_BOND | OBJHFLAG_ACTIVATED_BY_COOP);
			return true;
		}
	}

	return false;
}

bool aiIfAutoWalkFinished(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	return !(chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER && g_Vars.tickmode == TICKMODE_AUTOWALK);
}

bool aiIfCanSeeAttackTarget(struct chrdata *self)
{
	return (self && self->prop && chrCanSeeAttackTarget(self, &self->prop->pos, self->prop->rooms, true))
		|| (g_Vars.hovercar && chopperCheckTargetInFov(g_Vars.hovercar, 64) && chopperCheckTargetInSight(g_Vars.hovercar));
}

bool aiIfCanSeeTarget(struct chrdata *self)
{
	return (self && chrCanSeeTarget(self))
		|| (g_Vars.hovercar && chopperCheckTargetInFov(g_Vars.hovercar, 64) && chopperCheckTargetInSight(g_Vars.hovercar));
}

bool aiIfChrActivatedObject(struct chrdata *self, s32 chrref, s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		struct chrdata *chr = chrFindById(self, chrref);

		if (chr && chr->prop) {
			if (chr->prop == g_Vars.bond->prop && (obj->hidden & OBJHFLAG_ACTIVATED_BY_BOND)) {
				obj->hidden &= ~OBJHFLAG_ACTIVATED_BY_BOND;
				return true;
			}

			if (g_Vars.coopplayernum >= 0 && chr->prop == g_Vars.coop->prop && (obj->hidden & OBJHFLAG_ACTIVATED_BY_COOP)) {
				obj->hidden &= ~OBJHFLAG_ACTIVATED_BY_COOP;
				return true;
			}
		}
	}

	return false;
}

bool aiIfChrDead(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (!chr) {
		return true;
	}

	if (chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		return false;
	}

	if (!chr->model || chr->actiontype == ACT_DEAD || chr->actiontype == ACT_DIE) {
		return true;
	}

	return false;
}

bool aiIfChrDeadish(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);
	bool dead = false;

	if (!chr || !chr->prop) {
		dead = true;
	} else if (chr->prop->type == PROPTYPE_PLAYER) {
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		dead = g_Vars.players[playernum]->isdead;
	} else {
		if (!chr->model
				|| chr->actiontype == ACT_DEAD
				|| chr->actiontype == ACT_DIE
				|| chr->actiontype == ACT_DRUGGEDKO
				|| chr->actiontype == ACT_DRUGGEDDROP
				|| chr->actiontype == ACT_DRUGGEDCOMINGUP) {
			dead = true;
		}
	}

	return dead;
}

bool aiIfChrDeathAnimationFinished(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (!chr || !chr->prop) {
		return true;
	}

	if (chr->prop->type == PROPTYPE_PLAYER) {
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		return g_Vars.players[playernum]->isdead;
	}

	return chr->actiontype == ACT_DEAD;
}

bool aiIfChrDistanceToPadGreaterThan(struct chrdata *self, s32 chrref, s32 padnum, f32 distance)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (padnum == 9000) {
		padnum = self->padpreset1;
	}

	return chr && padnum < 9000 && chrGetSquaredDistanceToPad(chr, padnum) > distance * distance;
}

bool aiIfChrDistanceToPadLessThan(struct chrdata *self, s32 chrref, s32 padnum, f32 distance)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (padnum == 9000) {
		padnum = self->padpreset1;
	}

	return chr && padnum < 9000 && chrGetSquaredDistanceToPad(chr, padnum) < distance * distance;
}

bool aiIfChrInjuredTarget(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && (chr->chrflags & CHRCFLAG_INJUREDTARGET)) {
		chr->chrflags &= ~CHRCFLAG_INJUREDTARGET;
		return true;
	}

	return false;
}

bool aiIfChrInSameRoomAsPad(struct chrdata *self, s32 chrref, s32 padnum)
{
	struct chrdata *chr = chrFindById(self, chrref);
	s32 room = chrGetPadRoom(self, padnum);

	return room >= 0 && chr && chr->prop && chr->prop->rooms[0] == room;
}

bool aiIfChrInSearchRoom(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	return chr && chr->prop && chr->prop->rooms[0] == self->roomtosearch;
}

bool aiIfCountdownTimerExpired(void)
{
	return g_CountdownTimerValue60 <= 0.0f;
}

bool aiIfCutsceneButtonPressed(void)
{
	return (g_CutsceneSkipRequested && g_Vars.in_cutscene)
		|| (g_Vars.stagenum == STAGE_CITRAINING && var80087260 > 0);
}

bool aiIfEyespyNearG5Pad(s32 padnum)
{
	s32 i;

	if (g_Vars.stagenum == STAGE_G5BUILDING) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.players[i]->eyespy && g_Vars.players[i]->eyespy->prop
					&& chrGetSquaredDistanceToPad(g_Vars.players[i]->eyespy->prop->chr, padnum) < 22500.0f) {
				return true;
			}
		}
	}

	return false;
}

bool aiIfChrAmmoQuantityLessThan(struct chrdata *self, s32 chrref, s32 ammotype, s32 qty)
{
	struct chrdata *chr = chrFindById(self, chrref);
	bool passes = false;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);

		if (bgunGetAmmoCount(ammotype) < qty) {
			passes = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	return passes;
}

bool aiIfChrKnockedOut(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	return ((!chr || !chr->prop || chr->prop->type != PROPTYPE_PLAYER)
			&& (!chr || !chr->model || chr->actiontype == ACT_DRUGGEDKO || chr->actiontype == ACT_DRUGGEDDROP || chr->actiontype == ACT_DRUGGEDCOMINGUP));
}

bool aiIfChrSameFloorDistanceToPadLessThan(struct chrdata *self, s32 chrref, s32 padnum, f32 distance)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (padnum == 9000) {
		padnum = self->padpreset1;
	}

	return chr && chrGetSameFloorDistanceToPad(chr, padnum) < distance;
}

bool aiIfShieldDamaged(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && (chr->chrflags & CHRCFLAG_SHIELDDAMAGED)) {
		chr->chrflags &= ~CHRCFLAG_SHIELDDAMAGED;
		return true;
	}

	return false;
}

bool aiIfCheckFovWithTarget0(struct chrdata *self, s32 angle)
{
	return chrIsVerticalAngleToTargetWithin(self, angle);
}

bool aiIfCheckFovWithTarget1(struct chrdata *self, s32 angle)
{
	return chrIsInTargetsFovX(self, angle);
}

bool aiIfCheckFovWithTarget2(struct chrdata *self)
{
	return self->yvisang && chrIsVerticalAngleToTargetWithin(self, self->yvisang) == 0;
}

bool aiIfChrHasChrflag(struct chrdata *self, s32 chrref, u32 flag)
{
	struct chrdata *chr = chrFindById(self, chrref);

	return chr && (chr->chrflags & flag) == flag;
}

bool aiIfChrHasGun(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	return chr && chr->model && chr->gunprop == NULL;
}

bool aiIfChrHasHiddenFlag(struct chrdata *self, s32 chrref, u32 flag)
{
	struct chrdata *chr = chrFindById(self, chrref);

	return chr && (chr->hidden & flag) == flag;
}

bool aiIfChrHasObject(struct chrdata *self, s32 chrref, s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];
	struct chrdata *chr = chrFindById(self, chrref);
	bool hasprop = false;

	if (obj && obj->prop && chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		s32 prevplayernum = g_Vars.currentplayernum;
		setCurrentPlayerNum(playermgrGetPlayerNumByProp(chr->prop));
		hasprop = invHasProp(obj->prop);
		setCurrentPlayerNum(prevplayernum);
	}

	return hasprop;
}

bool aiIfChrHasWeaponEquipped(struct chrdata *self, s32 chrref, s32 weaponnum)
{
	struct chrdata *chr = chrFindById(self, chrref);
	bool passes = false;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);

		if (bgunGetWeaponNum(HAND_RIGHT) == weaponnum) {
			passes = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	return passes;
}

bool aiIfChrInSquadronDoingAction(struct chrdata *self, s32 action)
{
	s16 *chrnums = squadronGetChrIds(self->squadron);

	if (chrnums) {
		for (; *chrnums != -2; chrnums++) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->model && chrIsDead(chr) == false &&
					chr->actiontype != ACT_DEAD &&
					chrCompareTeams(self, chr, COMPARE_FRIENDS) &&
					self->chrnum != chr->chrnum &&
					chrGetDistanceToChr(self, chr->chrnum) < 3500 &&
					chr->myaction == action) {
				return true;
			}
		}
	}

	return false;
}

bool aiIfChrNotTalking(s32 chrref)
{
	struct chrdata *chr = chrFindByLiteralId(chrref);

	return chr && chr->propsoundcount == 0;
}

bool aiIfChrTarget(struct chrdata *self, s32 chr1ref, s32 chr2ref)
{
	struct chrdata *chr1 = chrFindById(self, chr1ref);
	struct chrdata *chr2 = chrFindById(self, chr2ref);

	return chr2 && chr2->prop && chrGetTargetProp(chr1) == chr2->prop;
}

bool aiIfChrYGreaterThan(struct chrdata *self, s32 chrref, f32 limit)
{
	struct chrdata *chr = NULL;

	if (chrref == CHR_TARGET && g_Vars.hovercar) {
		struct chopperobj *chopper = chopperFromHovercar(g_Vars.hovercar);

		if (chopper) {
			struct prop *target = chopperGetTargetProp(chopper);

			if (target && (target->type & (PROPTYPE_CHR | PROPTYPE_PLAYER))) {
				chr = target->chr;
			}
		}
	} else {
		chr = chrFindById(self, chrref);
	}

	return chr && chr->prop && chr->prop->pos.y > limit;
}

bool aiIfChrYLessThan(struct chrdata *self, s32 chrref, f32 limit)
{
	struct chrdata *chr = NULL;

	if (chrref == CHR_TARGET && g_Vars.hovercar) {
		struct chopperobj *chopper = chopperFromHovercar(g_Vars.hovercar);

		if (chopper) {
			struct prop *target = chopperGetTargetProp(chopper);

			if (target && (target->type & (PROPTYPE_CHR | PROPTYPE_PLAYER))) {
				chr = target->chr;
			}
		}
	} else {
		chr = chrFindById(self, chrref);
	}

	return chr && chr->prop && chr->prop->pos.y < limit;
}

bool aiIfCoopMode(void)
{
	return !g_Vars.normmplayerisrunning && g_MissionConfig.iscoop;
}

bool aiIfDistanceToGunLessThan(struct chrdata *self, f32 distance)
{
	f32 xdiff = 0;
	f32 ydiff = 0;
	f32 zdiff = 0;

	if (self->gunprop) {
		xdiff = self->prop->pos.x - self->gunprop->pos.x;
		ydiff = self->prop->pos.y - self->gunprop->pos.y;
		zdiff = self->prop->pos.z - self->gunprop->pos.z;
	}

	return ydiff < 200 && ydiff > -200
		&& xdiff < distance && xdiff > -distance
		&& zdiff < distance && zdiff > -distance;
}

bool aiIfDoorLocked(s32 tagnum, u32 flags)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;

		return (door->keyflags & flags) == flags;
	}

	return false;
}

bool aiIfDoorState(s32 tagnum, u32 state)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop && obj->type == OBJTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;

		if (door->mode == DOORMODE_IDLE) {
			if (door->frac <= 0) {
				return (state & DOORSTATE_CLOSED);
			} else {
				return (state & DOORSTATE_OPEN);
			}
		} else if (door->mode == DOORMODE_OPENING || door->mode == DOORMODE_WAITING) {
			return (state & DOORSTATE_OPENING);
		} else if (door->mode == DOORMODE_CLOSING) {
			return (state & DOORSTATE_CLOSING);
		}
	}

	return false;
}

bool aiIfGunLanded(struct chrdata *self)
{
	struct weaponobj *weapon = self->gunprop->weapon;

	if ((weapon->base.hidden & OBJHFLAG_PROJECTILE) == 0) {
		return true;
	}

	return false;
}

bool aiIfGunUnclaimed(struct chrdata *self)
{
	struct weaponobj *weapon = self->gunprop->weapon;

	if (weapon && weapon->base.prop) {
		weapon->base.flags |= OBJFLAG_00400000;
		return true;
	}

	return false;
}

bool aiIfInjured(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && (chr->chrflags & CHRCFLAG_JUST_INJURED)) {
		chr->chrflags &= ~CHRCFLAG_JUST_INJURED;
		return true;
	}

	return false;
}

bool aiIfLiftStationary(s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop && obj->type == OBJTYPE_LIFT) {
		struct liftobj *lift = (struct liftobj *)obj;

		if ((obj->flags & OBJFLAG_DEACTIVATED) || lift->dist == 0) {
			return true;
		}
	}

	return false;
}

bool aiIfObjectiveComplete(s32 index)
{
	return index < (g_ObjectiveLastIndex + 1)
		&& g_ObjectiveStatuses[index] == OBJECTIVE_COMPLETE
		&& objectiveGetDifficultyBits(index) & (1 << g_Difficulty);
}

bool aiIfObjectiveFailed(s32 index)
{
	return index < (g_ObjectiveLastIndex + 1)
		&& g_ObjectiveStatuses[index] == OBJECTIVE_FAILED
		&& objectiveGetDifficultyBits(index) & (1 << g_Difficulty);
}

bool aiIfObjectDistanceToPadLessThan(struct chrdata *self, s32 tagnum, s32 padnum, f32 distance)
{
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		padnum = chrResolvePadId(self, padnum);

		if (padnum >= 0) {
			xdiff = obj->prop->pos.x - g_Pads[padnum].pos.x;
			ydiff = obj->prop->pos.y - g_Pads[padnum].pos.y;
			zdiff = obj->prop->pos.z - g_Pads[padnum].pos.z;

			if (ydiff < 200 && ydiff > -200 &&
					xdiff < distance && xdiff > -distance &&
					zdiff < distance && zdiff > -distance) {
				return true;
			}
		}
	}

	return false;
}

bool aiIfObjectHealthy(s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	return obj && obj->prop && objIsHealthy(obj);
}

bool aiIfObjectInRoom(struct chrdata *self, s32 tagnum, s32 padnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];
	s32 roomnum = chrGetPadRoom(self, padnum);

	return roomnum >= 0 && obj && obj->prop && roomnum == obj->prop->rooms[0];
}

bool aiIfObjHasFlag2(s32 tagnum, u32 flag)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	return obj && obj->prop && (obj->flags2 & flag) == flag;
}

bool aiIfOnScreen(struct chrdata *self)
{
	return self->prop->flags & (PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK);
}

bool aiIfPatrolling(struct chrdata *self)
{
	return self->actiontype == ACT_PATROL
		|| (self->actiontype == ACT_GOPOS && self->act_gopos.flags & GOPOSFLAG_FORPATHSTART);
}

bool aiIfPlayerLookingAtObject(struct chrdata *self, s32 chrref, s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];
	bool pass = false;
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);

		if (g_Vars.currentplayer->lookingatprop.prop == obj->prop) {
			pass = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	return pass;
}

bool aiIfPlayerUsingCmpOrAr34(void)
{
	s32 weaponnum = bgunGetWeaponNum(HAND_RIGHT);

	return weaponnum == WEAPON_CMP150 || weaponnum == WEAPON_AR34;
}

bool aiIfPlayerUsingDevice(struct chrdata *self, s32 chrref, s32 device)
{
	struct chrdata *chr = chrFindById(self, chrref);
	struct prop *prop = chr ? chr->prop : NULL;
	u8 active = false;

	if (prop && prop->type == PROPTYPE_PLAYER) {
		u32 playernum = playermgrGetPlayerNumByProp(prop);
		u32 prevplayernum = g_Vars.currentplayernum;
		setCurrentPlayerNum(playernum);

		if (currentPlayerGetDeviceState(device) == DEVICESTATE_ACTIVE) {
			active = true;
		}

		setCurrentPlayerNum(prevplayernum);
	}

	return active;
}

bool aiIfPresetsTargetIsNotMyTarget(struct chrdata *self)
{
	return self->target != -1
		&& (self->chrpreset1 == -1 || self->target != propGetIndexByChrId(self, self->chrpreset1));
}

bool aiIfSafety2LessThan(struct chrdata *self, s32 limit)
{
	u8 score;
	u8 numnearby;
	s16 *chrnums = teamGetChrIds(self->team);

	score = 6;
	numnearby = 0;

	if (self->numarghs > 0) {
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
				&& self->squadron == chr->squadron
				&& self->chrnum != chr->chrnum
				&& chrGetDistanceToChr(self, chr->chrnum) < 3500) {
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

	return score < limit;
}

bool aiIfSeesSuspiciousItem(struct chrdata *self)
{
	s16 *ptr;
	struct prop *prop;
	struct defaultobj *obj;
	s16 propnums[256];
	struct prop *chrprop = self->prop;

	roomGetProps(chrprop->rooms, &propnums[0], 256);

	ptr = &propnums[0];

	while (*ptr >= 0) {
		prop = &g_Vars.props[*ptr];
		obj = prop->obj;

		if (prop->type == PROPTYPE_WEAPON) {
			if ((obj->hidden & OBJHFLAG_SUSPICIOUS) && chrCanSeeProp(self, prop)) {
				return true;
			}
		} else if (prop->type == PROPTYPE_OBJ) {
			if (((obj->hidden & OBJHFLAG_SUSPICIOUS) || !objIsHealthy(obj)) && chrCanSeeProp(self, prop)) {
				return true;
			}
		} else if (prop->type == PROPTYPE_EXPLOSION) {
			if (chrCanSeeProp(self, prop)) {
				return true;
			}
		}

		ptr++;
	}

	return false;
}

bool aiIfSquadronIsDead(s32 squadron)
{
	/**
	 * @bug: anyalive is initialised to true here, and reset to false in each
	 * loop iteration. This causes it to use the last chr's status only.
	 */
	bool anyalive = true;
	s16 *chrnums = squadronGetChrIds(squadron);

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

	return !anyalive;
}

bool aiIfTargetIsPlayer(struct chrdata *self)
{
	struct prop *target = chrGetTargetProp(self);

	return target->type & (PROPTYPE_EYESPY | PROPTYPE_PLAYER);
}

bool aiIfTargetMovingSlowly(struct chrdata *self)
{
	f32 delta = chrGetDistanceLostToTargetInLastSecond(self);
	f32 absdelta = absf(delta);

	return absdelta < 50;
}

bool aiIfChrTeleportFullWhite(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 mainpri;
	f32 fvalue;
	s32 audiopri;
	struct sndstate *handle;
	bool ready;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
	}

	if (g_Vars.currentplayer->teleportstate < TELEPORTSTATE_WHITE) {
		ready = false;
	} else {
		fvalue = 0.4;

		mainpri = osGetThreadPri(0);
		audiopri = osGetThreadPri(&g_AudioManager.thread);
		osSetThreadPri(0, audiopri + 1);

		handle = sndStart(var80095200, SFX_FIRE_SHOTGUN, NULL, -1, -1, -1, -1, -1);

		if (handle) {
			audioPostEvent(handle, 16, *(u32 *)&fvalue);
		}

		osSetThreadPri(0, mainpri);

		g_Vars.currentplayer->teleportstate = TELEPORTSTATE_WHITE;

		ready = true;
	}

	setCurrentPlayerNum(prevplayernum);

	return ready;
}

bool aiIfTrainingPcHolographed(void)
{
	struct trainingdata *data = dtGetData();

	return data->holographedpc;
}

bool aiIfWeaponThrownOnObject(s32 weaponnum, s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		struct prop *prop = obj->prop->child;

		while (prop) {
			if (prop->type == PROPTYPE_WEAPON) {
				struct weaponobj *weapon = prop->weapon;

				if (weapon->weaponnum == weaponnum) {
					return true;
				}
			}

			prop = prop->next;
		}
	}

	return false;
}

void aiIncreaseSquadronAlertness(struct chrdata *self, s32 amount)
{
	s16 *chrnums = teamGetChrIds(self->team);

	for (; *chrnums != -2; chrnums++) {
		struct chrdata *chr = chrFindByLiteralId(*chrnums);

		if (chr &&
				chr->model &&
				!chrIsDead(chr) &&
				chr->actiontype != ACT_DEAD &&
				(self->squadron == chr->squadron || self->squadron == 255) &&
				self->chrnum != chr->chrnum &&
				(chrGetDistanceToChr(self, chr->chrnum) < 1000 || chrHasFlag(self, CHRFLAG0_SQUADALERTANYDIST, BANK_0))) {
			incrementByte(&chr->alertness, amount);
		}
	}
}

void aiJogToPad(struct chrdata *self, s32 padnum)
{
	chrGoToPad(self, padnum, GOPOSFLAG_JOG);
}

void aiLockDoor(s32 tagnum, u32 flags)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		door->keyflags |= flags;
	}
}

bool aiMiniSkedarTryPounce(struct chrdata *self)
{
	return chrTrySkJump(self, self->pouncebits, 4, 14, 0);
}

void aiObjectDoAnimation(s32 anim_id, s32 tagnum, s32 arg2, s32 startframe)
{
	struct defaultobj *obj = NULL;
	f32 thing;
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

	if (tagnum == 255) {
		if (g_Vars.chrdata && g_Vars.chrdata->myspecial >= 0) {
			obj = g_ObjsByTag[g_Vars.chrdata->myspecial];
		}
	} else {
		obj = g_ObjsByTag[tagnum];
	}

	if (obj && obj->prop) {
		struct anim *anim = obj->model->anim;

		if (obj->model->anim == NULL) {
			obj->model->anim = modelmgrInstantiateAnim();
		}

		if (obj->model->anim) {
			thing = 1.0f / arg2;

			if (g_Vars.in_cutscene && startframe != 0xfffe) {
				fstartframe += g_CutsceneFrameOverrun240 * thing * 0.25f;
			}

			animInit(obj->model->anim);
			modelSetAnimation(obj->model, anim_id, 0, fstartframe, thing, 0);
			modelSetAnimScale(obj->model, func0f15c888() * obj->model->scale * 100.0f);
		}
	}
}

void aiObjectMoveToPad(s32 tagnum, s32 padnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];
	Mtxf matrix;
	struct pad *pad;
	s16 rooms[2];

	if (obj && obj->prop) {
		pad = &g_Pads[padnum];

		mtx00016d58(&matrix, 0, 0, 0, -pad->look.x, -pad->look.y, -pad->look.z, pad->up.x, pad->up.y, pad->up.z);

		if (obj->model) {
			mtx00015f04(obj->model->scale, &matrix);
		}

		rooms[0] = pad->room;
		rooms[1] = -1;

		func0f06a730(obj, &pad->pos, &matrix, rooms, &pad->pos);
	}
}

void aiObjSetModelPartVisible(s32 tagnum, s32 partnum, bool visible)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		objSetModelPartVisible(obj, partnum, visible);
	}
}

void aiOpenDoor(s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		if (!doorCallLift(obj->prop, false)) {
			struct doorobj *door = (struct doorobj *) obj;
			doorsRequestMode(door, DOORMODE_OPENING);
		}
	}
}

void aiPlaySoundFromChr(struct chrdata *self, s32 chrref, s32 channel, u32 thing2, u32 thing3)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop) {
		audioPlayFromProp2(channel, -1, -1, chr->prop, 1, thing2, thing3, 0);
	}
}

void aiPlaySoundFromObj(s32 channel, s32 tagnum, u32 thing2, u32 thing3)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		audioPlayFromProp2(channel, -1, -1, obj->prop, 1, thing2, thing3, 0);
	}
}

void aiPlaySoundFromProp(s32 channel, s32 tagnum, s32 soundnum, s32 unk1, s32 unk2)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	audioPlayFromProp(channel, soundnum, 0xffff, obj->prop, unk1, unk2);
}

void aiRecoverGun(struct chrdata *self)
{
	struct prop *prop = self->gunprop;
	self->gunprop = NULL;

	if (prop && prop->obj && prop->parent == NULL && prop->type == PROPTYPE_WEAPON) {
		propDeregisterRooms(prop);
		propDelist(prop);
		propDisable(prop);
		chrEquipWeapon(prop->weapon, self);
	}
}

void aiRemoveChr(struct chrdata *self, s32 chrref)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop) {
		chr->hidden |= 0x20;
	}
}

void aiRemoveReferencesToChr(struct chrdata *self)
{
	if (self && self->prop) {
		chrClearReferences(self->prop - g_Vars.props);
	}
}

void aiRestartTimer(struct chrdata *self)
{
	if (self) {
		chrRestartTimer(self);
	} else if (g_Vars.hovercar) {
		chopperRestartTimer(g_Vars.hovercar);
	}
}

u8 *aiReturn(struct chrdata *self)
{
	u8 *ailist = NULL;

	if (self) {
		ailist = self->aireturnlist;
		self->ailist = ailist;
	} else if (g_Vars.hovercar) {
		ailist = g_Vars.hovercar->aireturnlist;
	}

	return ailist;
}

void aiRetreatFromTarget(struct chrdata *self)
{
	struct prop *target = chrGetTargetProp(self);
	chrRunFromPos(self, GOPOSFLAG_RUN, 10000, &target->pos);
}

void aiRetreatToCover(struct chrdata *self)
{
	chrAssignCoverByCriteria(self, COVERCRITERIA_FURTHEREST
			| COVERCRITERIA_DISTTOTARGET
			| COVERCRITERIA_ONLYNEIGHBOURINGROOMS
			| COVERCRITERIA_ROOMSFROMME, 0);
	chrGoToCover(self, GOPOSFLAG_RUN);
}

void aiRevokeControl(struct chrdata *self, s32 chrref, u32 flags)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 prevplayernum = g_Vars.currentplayernum;
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		setCurrentPlayerNum(playernum);
		bgunSetSightVisible(GUNSIGHTREASON_NOCONTROL, false);
		bgunSetGunAmmoVisible(GUNAMMOREASON_NOCONTROL, false);

		if ((flags & 2) == 0) {
			hudmsgsSetOff(HUDMSGREASON_NOCONTROL);
		}

		if ((flags & 4) == 0) {
			countdownTimerSetVisible(COUNTDOWNTIMERREASON_NOCONTROL, false);
		}

		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		setCurrentPlayerNum(prevplayernum);
	}
}

void aiRunToPad(struct chrdata *self, s32 padnum)
{
	chrGoToPad(self, padnum, GOPOSFLAG_RUN);
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

void aiSayCiStaffQuip(struct chrdata *self, s32 ciquip, s32 channel)
{
	s32 quip;

	if (ciquip == CIQUIP_GREETING) {
		quip = g_CiGreetingQuips[self->morale][random() % 3];
	} else if (ciquip == CIQUIP_MAIN) {
		quip = g_CiMainQuips[self->morale][random() % 3];
	} else if (ciquip == CIQUIP_ANNOYED) {
		quip = g_CiAnnoyedQuips[self->morale][random() % 3];
	} else {
		quip = g_CiThanksQuips[self->morale];
	}

	audioPlayFromProp(channel, quip, 0, self->prop, 9, 0);
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
	{ QUIP_SHOTUNALERT,        SFX_M0_HOLY_SHH,                  SFX_M0_HOLY_SHH,                  SFX_M0_WHAT_THE_HELL              },
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
	{ QUIP_INSPECTBODY,        SFX_M1_NOOO,                    SFX_M1_OH_GOD_HES_DEAD,          SFX_M1_HES_GONE                   },
	{ QUIP_20,                 SFX_M1_M2_LOOK_OUT_SHES_COMING, SFX_M1_M2_TAKE_COVER,            SFX_M1_M2_LOOK_OUT_LOOK_OUT       },
	{ QUIP_HITPLAYER,          SFX_M1_IM_JUST_TOO_GOOD,        SFX_M1_YEAH_BABY,                SFX_M1_YEAH_BABY                  },
	{ QUIP_MISSEDPLAYER1,      SFX_M1_BLOODY_STUPID_GUN,       SFX_M1_MY_GUN_ITS_USELESS,       SFX_M1_DAMN_IT                    },
	{ QUIP_MISSEDPLAYER2,      SFX_M1_STOP_DODGING,            SFX_M1_SOMEONE_HIT_HER,          SFX_M1_DAMN_SHES_GOOD             },
	{ QUIP_GOTOCOVER2,         SFX_M1_GO_FOR_IT,               SFX_M1_GO_GO_GO,                 SFX_M1_RUN                        },
	{ QUIP_DIE,                SFX_M1_SCREAM,                  SFX_M1_WHY_ME,                   SFX_M1_CHOKING                    },
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
	{ QUIP_DIE,                SFX_M2_NOOO,                            SFX_M2_OH_GOD_IM_DYING,                 SFX_M2_I_DONT_WANT_TO_DIE               },
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
	{ QUIP_MISSEDPLAYER2,      SFX_F_STAND_STILL,        SFX_F_SOMEONE_HIT_HER,    SFX_F_DAMN_SHES_GOOD    },
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

void aiSayQuip(struct chrdata *self, s32 chrref, s32 row, s32 probability, s32 soundgap, s32 conditions, s32 special, s32 textrow, u32 colour)
{
	u8 column; // 167
	s16 audioid; // 164
	u8 i; // 163
	s32 numnearbychrs; // 152
	bool issomeonetalking; // 148
	u32 stack; // 140 - not referenced
	s16 *chrnums; // 136
	s16 (*bank)[4]; // 132
	char *text; // 128
	struct chrdata *chr = chrFindById(self, chrref); // 124
	u32 prevplayernum = g_Vars.currentplayernum; // 120
	f32 distance; // 116 - not referenced
	u32 playernum; // 108 - not referenced
	u8 headshotted = (self->hidden2 & CHRH2FLAG_HEADSHOTTED) & 0xff; // 107
	struct chrdata *loopchr; // 100

	// Choose bank
	// 2c0
	if (CHRRACE(self) == RACE_SKEDAR) {
		bank = g_SkedarQuipBank;

		if (row > 5) {
			row = 0;
		}
		// 2e0
	} else if (self->headnum == HEAD_MAIAN_S) {
		bank = g_MaianQuipBank;

		if (row > 2) {
			row = random() & 1;
		}
		// 324
	} else if (special == 0) {
		if (self->voicebox > 3) {
			self->voicebox = 3;
		}

		bank = &g_GuardQuipBank[self->voicebox * 41];
	} else {
		// 37c
		bank = g_SpecialQuipBank;
	}

	// 37c
	if (!row && probability && conditions) {
		self->soundtimer = 0;
		return;
	}

	// 3bc
	chrnums = teamGetChrIds(self->team);
	numnearbychrs = 0;
	issomeonetalking = false;

	// Make it impossible for Elvis and Jon to use anything but special phrases
	// 3f0
	if ((self->headnum == HEAD_ELVIS
				|| self->headnum == HEAD_THEKING
				|| self->headnum == HEAD_ELVIS_GOGS
				|| self->headnum == HEAD_JONATHAN) &&
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
	if ((self->soundgap == 0 || self->soundgap * 60 < self->soundtimer)
			&& probability > (u8)random()) {
		// Try and find a chr in the same squadron who is currently talking
		// 4dc
		while (*chrnums != -2) {
			loopchr = chrFindByLiteralId(*chrnums);

			if (loopchr && loopchr->model
					&& !chrIsDead(loopchr)
					&& loopchr->actiontype != ACT_DEAD
					&& self->squadron == loopchr->squadron
					&& loopchr->alertness >= 100
					&& self->chrnum != loopchr->chrnum
					&& chrGetDistanceToChr(self, loopchr->chrnum) < 7000) {
				// 584
				numnearbychrs++;

				// 594
				if (loopchr->soundtimer < 60 && conditions != 0 && conditions != 255) {
					issomeonetalking = true;
				}
			}

			chrnums++;
		}

		// 5dc
		if (!issomeonetalking &&
				((numnearbychrs == 0 && (conditions == 0 || conditions == 255)) ||
				 (numnearbychrs > 0 && conditions > 0))) {
			column = random() % 3;

			// 64c
			if ((special & 0x80) == 0) {
				audioid = bank[row][1 + column];
			} else {
				audioid = bank[row][1 + self->tude];
			}

			// 6a0
			if (audioWasNotPlayedRecently(audioid) || CHRRACE(self) == RACE_SKEDAR) {
				// 6d4
				audioMarkAsRecentlyPlayed(audioid);

				// 6e8
				// Replace gurgle with "why me"
				if (audioid == 0x34e && !headshotted) {
					audioid = 0x34d;
				}

				// 700
				self->soundtimer = 0;
				self->soundgap = soundgap;
				self->propsoundcount++;

				// 72c
				if (audioid != 0x3f7 && audioid != 0x331 && audioid != 0x3a1) {
					func0f0926bc(self->prop, 9, 0xffff);
					// 7a8
					propsnd0f0939f8(0, self->prop, audioid, -1,
							-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
				} else {
					// Audio is "Stop moving", "Stop dodging" or "Stand still"
					distance = chrGetDistanceLostToTargetInLastSecond(self);

					if (absf(distance) > 50) {
						func0f0926bc(self->prop, 9, 0xffff);
						// 840
						propsnd0f0939f8(0, self->prop, audioid, -1,
								-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
					}
				}

				// Consider putting text on screen
				if (textrow && (special & 0x80) == 0) {
					if (column > 2) {
						column = 2;
					}

					text = langGet(g_QuipTexts[textrow - 1][1 + column]);

					if (!sndIsFiltered(audioid)) {
						// 8ac
						hudmsgCreateWithColour(text, HUDMSGTYPE_INGAMESUBTITLE, colour);
					}
				} else if (textrow) {
					text = langGet(g_QuipTexts[textrow - 1][1 + self->tude]);

					if (!sndIsFiltered(audioid)) {
						// 904
						hudmsgCreateWithColour(text, HUDMSGTYPE_INGAMESUBTITLE, colour);
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

					self->soundtimer = 0;
					self->soundgap = soundgap;
					self->propsoundcount++;

					// 9fc
					if (audioid != 0x3f7 && audioid != 0x331 && audioid != 0x3a1) {
						func0f0926bc(self->prop, 9, 0xffff);
						// a80
						propsnd0f0939f8(0, self->prop, audioid, -1,
								-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
					} else {
						// Audio is "Stop moving", "Stop dodging" or "Stand still"
						// a90
						distance = chrGetDistanceLostToTargetInLastSecond(self);

						if (absf(distance) > 50) {
							func0f0926bc(self->prop, 9, 0xffff);
							// b28
							propsnd0f0939f8(0, self->prop, audioid, -1,
									-1, 8, 0, 9, 0, -1, 0, -1, -1, -1, -1);
						}
					}

					// b44
					if (textrow) {
						text = langGet(g_QuipTexts[textrow - 1][i]);

						if (!sndIsFiltered(audioid)) {
							// b78
							hudmsgCreateWithColour(text, HUDMSGTYPE_INGAMESUBTITLE, colour);
						}
					}
				} else {
					self->soundtimer = 0;
					self->soundgap = soundgap;
					chrUnsetFlags(self, CHRFLAG1_TALKINGTODISGUISE, BANK_1);
				}
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);
}

void aiSetAllRoomsAmbient(void)
{
	s32 i;

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags |= ROOMFLAG_PLAYAMBIENTTRACK;
	}
}

void aiSetAutogunTargetTeam(s32 tagnum, s32 team)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop && obj->type == OBJTYPE_AUTOGUN) {
		struct autogunobj *autogun = (struct autogunobj *)obj;
		autogun->targetteam = team;
		autogun->target = NULL;
	}
}

bool aiSetCameraAnimation(s32 animnum)
{
	playerStartCutscene(animnum);

	return !g_Vars.currentplayer->haschrbody;
}

void aiSetChrHudpieceVisible(struct chrdata *self, s32 chrref, bool visible)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr && chr->prop && chr->model) {
		chrSetHudpieceVisible(chr, visible);
	}
}

void aiSetChrList(struct chrdata *self, s32 chrref, u8 *ailist)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr) {
		chr->ailist = ailist;
		chr->aioffset = ailist;
		chr->sleep = 0;
	}
}

bool aiSetChrPresetToUnalertedTeammate(struct chrdata *self)
{
	f32 closest_distance = 30999.9;
	s16 candidate_chrnum = -1;
	s16 *chrnums = teamGetChrIds(self->team);

	for (; *chrnums != -2; chrnums++) {
		struct chrdata *chr = chrFindByLiteralId(*chrnums);

		if (chr && chr->model
				&& !chrIsDead(chr)
				&& chr->actiontype != ACT_DEAD
				&& chr->actiontype != ACT_DIE
				&& chr->actiontype != ACT_DRUGGEDKO
				&& chr->actiontype != ACT_DRUGGEDDROP
				&& chr->actiontype != ACT_DRUGGEDCOMINGUP
				&& chr->alertness < 100
				&& (self->squadron == chr->squadron || self->squadron == 0xff)
				&& self->chrnum != chr->chrnum) {
			f32 distance = chrGetDistanceToChr(self, chr->chrnum);

			if (distance < closest_distance) {
				closest_distance = distance;
				candidate_chrnum = chr->chrnum;
			}
		}
	}

	if (candidate_chrnum != -1) {
		chrSetChrPreset(self, candidate_chrnum);
		return true;
	}

	return false;
}

void aiSetChrSpecialDeathAnimation(struct chrdata *self, s32 chrref, s32 specialdie)
{
	struct chrdata *chr = chrFindById(self, chrref);

	if (chr) {
		chr->specialdie = specialdie;
	}
}

void aiSetCoverUnused(s32 covernum)
{
	if (covernum >= 0) {
		coverSetInUse(covernum, false);
	}
}

void aiSetDarkRoomList(struct chrdata *self, u8 *ailist)
{
	if (self) {
		self->aidarkroomlist = ailist;
	}
}

void aiSetDoorOpen(s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

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
}

void aiSetDrCarollImages(struct chrdata *self, s32 chrref, s32 image1, s32 image2)
{
	struct chrdata *drcaroll = chrFindById(self, chrref);

	if (drcaroll) {
		if (image2 == 7) {
			if ((g_Vars.lvframenum % 4) == 2) {
				drcaroll->drcarollimage_left = random() % 6;
			}
		} else if (image2 == 8) {
			drcaroll->drcarollimage_left = random() % 6;
		} else {
			drcaroll->drcarollimage_left = image2;
		}

		if (image1 == 7) {
			if ((g_Vars.lvframenum % 4) == 2) {
				drcaroll->drcarollimage_right = random() % 6;
			}
		} else if (image1 == 8) {
			drcaroll->drcarollimage_right = random() % 6;
		} else {
			drcaroll->drcarollimage_right = image1;
		}
	}
}

void aiSetLights(struct chrdata *self, s32 padnum, s32 operation, s32 arg2, s32 arg3, s32 arg4)
{
	s32 roomnum = chrGetPadRoom(self, padnum);

	if (roomnum >= 0) {
		switch (operation) {
		case LIGHTOP_TURNOFF:
			roomSetLightsOn(roomnum, false);
			break;
		case LIGHTOP_TURNON:
			roomSetLightsOn(roomnum, true);
			break;
		default:
			roomSetLighting(roomnum, operation, arg2, arg3, arg4);
			break;
		}
	}
}

void aiSetMaxDamage(struct chrdata *self, s32 chrref, f32 maxdamage)
{
	if (g_Vars.hovercar) {
		chopperSetMaxDamage(g_Vars.hovercar, maxdamage);
	} else {
		struct chrdata *chr = chrFindById(self, chrref);

		if (chr && chr->prop && !chrIsDead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP) {
			chrSetMaxDamage(chr, maxdamage);
		}
	}
}

void aiSetMyList(struct chrdata *self, u8 *ailist)
{
	if (self) {
		self->ailist = ailist;
	}
}

void aiSetObjFlag(s32 tagnum, u32 flag)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		obj->flags |= flag;
	}
}

void aiSetObjFlag2(s32 tagnum, u32 flag)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		obj->flags2 |= flag;
	}
}

void aiSetObjFlag3(s32 tagnum, u32 flag)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		obj->flags3 |= flag;
	}
}

void aiSetObjDamage(s32 tagnum, s32 damage)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		obj->damage = damage;
	}
}

void aiSetObjImage(s32 tagnum, s32 slot, s32 image)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		if (obj->type == OBJTYPE_SINGLEMONITOR) {
			struct singlemonitorobj *sm = (struct singlemonitorobj *) obj;
			tvscreenSetImageByNum(&sm->screen, image);
		} else if (obj->type == OBJTYPE_MULTIMONITOR) {
			struct multimonitorobj *mm = (struct multimonitorobj *) obj;
			tvscreenSetImageByNum(&mm->screens[slot], image);
		}
	}
}

void aiSetPadPreset(struct chrdata *self, s32 padnum)
{
	if (self) {
		chrSetPadPreset(self, padnum);
	}
}

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

void aiSetPadPresetToInvestigationTerminal(struct chrdata *self, s32 tagnum)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];
	s32 i;

	if (obj) {
		for (i = 0; i < sizeof(g_InvestigationPadMap) / sizeof(g_InvestigationPadMap[0]); i += 2) {
			if (obj->pad == g_InvestigationPadMap[i]) {
				chrSetPadPreset(self, g_InvestigationPadMap[i + 1]);
				break;
			}
		}
	}
}

void aiSetPortalFlag(s32 portalnum, u32 flag)
{
	g_BgPortals[portalnum].flags |= flag;
}

void aiSetReturnList(struct chrdata *self, s32 chrref, u8 *ailist)
{
	if (self) {
		if (chrref == CHR_SELF) {
			self->aireturnlist = ailist;
		} else {
			struct chrdata *chr = chrFindById(self, chrref);

			if (chr) {
				chr->aireturnlist = ailist;
			}
		}
	} else if (g_Vars.hovercar) {
		g_Vars.hovercar->aireturnlist = ailist;
	}
}

void aiSetRoomFlag(s32 roomnum, u32 flag)
{
	g_Rooms[roomnum].flags |= flag;
}

void aiSetRoomToSearch(struct chrdata *self)
{
	struct chrdata *target = chrFindById(self, CHR_TARGET);

	if (target && target->prop) {
		self->roomtosearch = target->prop->rooms[0];
	}
}

void aiSetShield(struct chrdata *self, f32 amount)
{
	if (cheatIsActive(CHEAT_ENEMYSHIELDS) && amount < 8) {
		amount = 8;
	}

	chrSetShield(self, amount);
}

void aiSetShootingAtMeList(struct chrdata *self, u8 *ailist)
{
	if (self) {
		self->aishootingatmelist = ailist;
	}
}

void aiSetShotList(struct chrdata *self, u8 *ailist)
{
	if (self) {
		self->aishotlist = ailist;
	}
}

void aiSetStageFlag(u32 flag)
{
	g_StageFlags |= flag;
	g_ObjectivesDirty = flag; // we just need a non-zero value; this avoids an li instruction
}

void aiSetTargetChr(struct chrdata *self, s32 chrref)
{
	if (self) {
		s16 prop_id = propGetIndexByChrId(self, chrref);

		if (prop_id != self->target) {
			self->lastvisibletarget60 = 0;
			self->lastseetarget60 = 0;
			self->lastheartarget60 = 0;
			self->hidden &= ~CHRHFLAG_IS_HEARING_TARGET;
			self->chrflags &= ~CHRCFLAG_NEAR_MISS;
			self->target = prop_id;
		}
	} else if (g_Vars.hovercar) {
		chopperSetTarget(g_Vars.hovercar, chrref);
	}
}

bool aiSetTargetToEyespyIfInSight(struct chrdata *self)
{
	s16 prevtarget = self->target;
	struct eyespy *eyespy = g_Vars.players[self->p1p2]->eyespy;

	if (eyespy) {
		struct chrdata *chr = eyespy->prop->chr;
		self->target = propGetIndexByChrId(self, chr->chrnum);

		if (chrCheckTargetInSight(self)) {
			return true;
		}

		self->target = prevtarget;
	}

	return false;
}

bool aiSetTeamOrders(struct chrdata *self)
{
	struct chrnumaction *chraction;
	s32 chrcount = 1;
	s16 *chrnums;
	struct chrnumaction chractions[50];
	s32 num;

	// Get list of chrs in the current chr's squadron
	chrnums = squadronGetChrIds(self->squadron);

	// Iterate chrs in squadron and build list of their actions.
	// Put the current chr's action first.
	chraction = chractions;
	chraction->chrnum = self->chrnum;
	chraction->myaction = self->myaction;
	chraction++;

	if (chrnums) {
		while (*chrnums != -2) {
			struct chrdata *chr = chrFindByLiteralId(*chrnums);

			if (chr && chr->model
					&& !chrIsDead(chr)
					&& chr->actiontype != ACT_DEAD
					&& chrCompareTeams(self, chr, COMPARE_FRIENDS)
					&& self->chrnum != chr->chrnum) {
				if (chr->myaction == MA_COVERWAIT
						|| chr->myaction == MA_NORMAL
						|| chr->myaction == MA_WAITING
						|| chr->myaction == MA_SHOOTING) {
					if (chrGetDistanceToChr(self, chr->chrnum) < 3500) {
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
					self->orders = MA_COVERGOTO;
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
				self->orders = MA_FLANKLEFT;
				break;
			case MA_FLANKRIGHT:
				if (chrIsInTargetsFovX(chr, 50)) {
					chr->orders = MA_FLANKLEFT;
				} else {
					chr->orders = MA_SHOOTING;
				}
				num++;
				self->orders = MA_FLANKRIGHT;
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

		return num != 1;
	}

	return false;
}

void aiSetVehicleSpeed(f32 speedaim, f32 speedtime)
{
	if (g_Vars.hovercar) {
		g_Vars.hovercar->speedaim = speedaim;
		g_Vars.hovercar->speedtime60 = speedtime;
	}
}

void aiSetViewDistance(struct chrdata *self, s32 value)
{
	if (!cheatIsActive(CHEAT_PERFECTDARKNESS)) {
		self->visionrange = value;
	}
}

void aiShowCutsceneChrs(void)
{
	s32 i;

	for (i = g_NumChrSlots - 1; i >= 0; i--) {
		if (g_ChrSlots[i].chrnum >= 0 && g_ChrSlots[i].prop && (g_ChrSlots[i].hidden2 & CHRH2FLAG_HIDDENFORCUTSCENE)) {
			g_ChrSlots[i].hidden2 &= ~CHRH2FLAG_HIDDENFORCUTSCENE;
			g_ChrSlots[i].chrflags &= ~CHRCFLAG_HIDDEN;
		}
	}
}

void aiShowHudmsg(struct chrdata *self, s32 chrref, s32 textid)
{
	char *text = langGet(textid);
	struct chrdata *chr = chrFindById(self, chrref);

	u32 prevplayernum = g_Vars.currentplayernum;
	u32 playernum = g_Vars.currentplayernum;

	if (chr && chr->prop && (chr->prop->type & 0xff) == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(chr->prop);
	}

	setCurrentPlayerNum(playernum);
	hudmsgCreate(text, HUDMSGTYPE_DEFAULT);
	setCurrentPlayerNum(prevplayernum);
}

void aiShowHudmsgTopMiddle(struct chrdata *self, s32 chrref, s32 textid, s32 colour)
{
	char *text = langGet(textid);
	struct chrdata *chr = chrFindById(self, chrref);

	u32 prevplayernum = g_Vars.currentplayernum;
	u32 playernum = g_Vars.currentplayernum;

	if (chr && chr->prop && (chr->prop->type & 0xff) == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(chr->prop);
	}

	setCurrentPlayerNum(playernum);
	hudmsgCreateWithColour(text, HUDMSGTYPE_INGAMESUBTITLE, colour);
	setCurrentPlayerNum(prevplayernum);
}

void aiShuffleInvestigationTerminals(s32 goodtagnum, s32 badtagnum, s32 pc1, s32 pc2, s32 pc3)
{
	u8 rand1 = random() % 3;
	u8 rand2 = random() % 3;

	// Place the good terminal
	if (rand1 == 0) {
		g_ObjsByTag[goodtagnum] = g_ObjsByTag[pc1];
	} else if (rand1 == 1) {
		g_ObjsByTag[goodtagnum] = g_ObjsByTag[pc2];
	} else {
		g_ObjsByTag[goodtagnum] = g_ObjsByTag[pc3];
	}

	// Handle both good and alarm terminals having the same destination
	if (rand2 == rand1 && rand2 > 0) {
		rand2--;
	} else if (rand2 == rand1 && rand2 < 3) {
		rand2++;
	}

	// Place the alarm terminal
	if (rand2 == 0) {
		g_ObjsByTag[badtagnum] = g_ObjsByTag[pc1];
	} else if (rand2 == 1) {
		g_ObjsByTag[badtagnum] = g_ObjsByTag[pc2];
	} else {
		g_ObjsByTag[badtagnum] = g_ObjsByTag[pc3];
	}
}

void aiShufflePelagicSwitches(void)
{
	u8 buttonsdone[] = {0, 0, 0, 0, 0, 0, 0, 0};
	u8 i;
	u8 j;
	struct tag *tag;
	struct tag *button;
	u8 index;

	for (i = 8; i < 16; i++) {
		index = random() & 7;

		if (buttonsdone[index] == 0) {
			// Switch has not yet been mapped
			g_ObjsByTag[i] = g_ObjsByTag[index];
			buttonsdone[index] = 1;
		} else {
			// Switch is already mapped - find first unmapped switch
			for (j = 0; buttonsdone[j]; j++);

			g_ObjsByTag[i] = g_ObjsByTag[j];
			buttonsdone[j] = 1;
		}
	}
}

void aiShuffleRuinsPillars(void)
{
	u8 marked1index = random() % 5;
	u8 marked2index = random() % 5;
	u8 marked3index = random() % 5;
	u8 pillars[5];
	u8 mines[5];
	pillars[0] = 0x2a;
	pillars[1] = 0x2b;
	pillars[2] = 0x2c;
	pillars[3] = 0x2d;
	pillars[4] = 0x2e;
	mines[0] = 0x2f;
	mines[1] = 0x30;
	mines[2] = 0x31;
	mines[3] = 0x32;
	mines[4] = 0x33;

	while (marked2index == marked1index) {
		marked2index = random() % 5;
	}

	while (marked3index == marked2index || marked3index == marked1index) {
		marked3index = random() % 5;
	}

	// Pillar/mine 1
	g_ObjsByTag[0x01] = g_ObjsByTag[pillars[marked1index]];
	g_ObjsByTag[0x27] = g_ObjsByTag[mines[marked1index]];

	// Pillar/mine 2
	g_ObjsByTag[0x02] = g_ObjsByTag[pillars[marked2index]];
	g_ObjsByTag[0x28] = g_ObjsByTag[mines[marked2index]];

	// Pillar/mine 3
	g_ObjsByTag[0x03] = g_ObjsByTag[pillars[marked3index]];
	g_ObjsByTag[0x29] = g_ObjsByTag[mines[marked3index]];
}

void aiSpeak(struct chrdata *self, s32 chrref, s32 text_id, s32 audio_id, s32 channel, s32 colour)
{
	struct chrdata *chr = chrFindById(self, chrref);
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 playernum = prevplayernum;
	u32 channelnum;
	char *text = text_id >= 0 ? langGet(text_id) : NULL;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(chr->prop);
	}

	setCurrentPlayerNum(playernum);

	if (text && chrref != CHR_P1P2) {
		func0f0926bc(self->prop, 9, 0xffff);
	}

	if (chrref == CHR_P1P2) {
		channelnum = audioPlayFromProp(channel, audio_id, 0, self->prop, 0, 512);
	} else {
		channelnum = audioPlayFromProp(channel, audio_id, 0, self->prop, 9, 512);
	}

	if (text && !sndIsFiltered(audio_id)) {
		hudmsgCreateAsSubtitle(text, HUDMSGTYPE_INGAMESUBTITLE, colour, channelnum);
	}

	setCurrentPlayerNum(prevplayernum);
}

void aiStop(struct chrdata *self)
{
	if (self) {
		chrTryStop(self);
	} else if (g_Vars.hovercar) {
		chopperStop(g_Vars.hovercar);
	}
}

struct prop *aiTryEquipWeapon(struct chrdata *self, s32 model, s32 weaponnum, u32 flags)
{
	struct prop *prop = NULL;

	if (self && self->prop && self->model) {
		if (cheatIsActive(CHEAT_MARQUIS)) {
			flags &= ~OBJFLAG_WEAPON_LEFTHANDED;
			flags |= OBJFLAG_WEAPON_AICANNOTUSE;

			prop = chrGiveWeapon(self, model, weaponnum, flags);
		} else if (cheatIsActive(CHEAT_ENEMYROCKETS)) {
			switch (weaponnum) {
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
				prop = chrGiveWeapon(self, MODEL_CHRDYROCKET, WEAPON_ROCKETLAUNCHER, flags);
				break;
			case WEAPON_K7AVENGER:
				if (g_Vars.stagenum == STAGE_INVESTIGATION && g_Difficulty == DIFF_PA) {
					prop = chrGiveWeapon(self, model, weaponnum, flags);
				} else {
					prop = chrGiveWeapon(self, MODEL_CHRDYROCKET, WEAPON_ROCKETLAUNCHER, flags);
				}
				break;
			default:
				prop = chrGiveWeapon(self, model, weaponnum, flags);
				break;
			}
		} else {
			prop = chrGiveWeapon(self, model, weaponnum, flags);
		}
	}

	return prop;
}

bool aiTryJogToChr(struct chrdata *self, s32 chrref)
{
	return chrGoToChr(self, chrref, GOPOSFLAG_JOG);
}

bool aiTryJogToTarget(struct chrdata *self)
{
	return chrGoToTarget(self, GOPOSFLAG_JOG);
}

bool aiTryMelee(struct chrdata *self)
{
	return self && chrTryPunch(self, 0);
}

bool aiTryModifyAttack(struct chrdata *self, u32 thingtype, u32 thingid)
{
	return (self && chrTryModifyAttack(self, thingtype, thingid))
		|| (g_Vars.hovercar && chopperAttack(g_Vars.hovercar));
}

bool aiTryRunToChr(struct chrdata *self, s32 chrref)
{
	return chrGoToChr(self, chrref, GOPOSFLAG_RUN);
}

bool aiTryRunToTarget(struct chrdata *self)
{
	return chrGoToTarget(self, GOPOSFLAG_RUN);
}

bool aiTryWalkToTarget(struct chrdata *self)
{
	return chrGoToTarget(self, GOPOSFLAG_WALK);
}

void aiUnlockDoor(s32 tagnum, u32 flags)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;
		door->keyflags &= ~flags;
	}
}

void aiUnsetAllRoomsAmbient(void)
{
	s32 i;

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags &= ~ROOMFLAG_PLAYAMBIENTTRACK;
	}
}

void aiUnsetObjFlag(s32 tagnum, u32 flag)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		obj->flags &= ~flag;
	}
}

void aiUnsetObjFlag2(s32 tagnum, u32 flag)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		obj->flags2 &= ~flag;
	}
}

void aiUnsetObjFlag3(s32 tagnum, u32 flag)
{
	struct defaultobj *obj = g_ObjsByTag[tagnum];

	if (obj && obj->prop) {
		obj->flags3 &= ~flag;
	}
}

void aiUnsetRoomFlag(s32 roomnum, u32 flag)
{
	g_Rooms[roomnum].flags &= ~flag;
}

void aiUnsetStageFlag(u32 flag)
{
	g_StageFlags &= flag;
	g_ObjectivesDirty = flag; // we just need a non-zero value; this avoids an li instruction
}

void aiWalkToPad(struct chrdata *self, s32 padnum)
{
	chrGoToPad(self, padnum, GOPOSFLAG_WALK);
}

void propDecrementSoundCount(struct prop *prop)
{
	if (prop && prop->chr && prop->chr->model && prop->chr->propsoundcount > 0) {
		prop->chr->propsoundcount--;
	}
}
