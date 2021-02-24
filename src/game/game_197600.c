#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/debug.h"
#include "game/chr/chr.h"
#include "game/ceil.h"
#include "game/game_0b0fd0.h"
#include "game/game_127910.h"
#include "game/mplayer/setup.h"
#include "game/game_190260.h"
#include "game/game_197600.h"
#include "game/game_1999b0.h"
#include "game/mplayer/mplayer.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

f32 var80087e50[][3] = {
	{ 0,    120,  10000 },
	{ 300,  450,  4500  },
	{ 300,  600,  4500  },
	{ 600,  1200, 4500  },
	{ 150,  250,  4500  },
	{ 1000, 2000, 3000  },
	{ 0,    250,  10000 },
	{ 450,  700,  4500  },
};

struct aibotweaponpreference g_AibotWeaponPreferences[] = {
	/*0x00*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0      }, // WEAPON_NONE
	/*0x01*/ { 13,  13,  13,  13,  1, 1, 0, 0, 0,    0,   0,  0,  0      }, // WEAPON_UNARMED
	/*0x02*/ { 56,  60,  84,  88,  1, 1, 1, 0, 30,   0,   10, 0,  0x2000 }, // WEAPON_FALCON2
	/*0x03*/ { 52,  60,  80,  88,  1, 1, 1, 0, 30,   0,   10, 0,  0x2000 }, // WEAPON_FALCON2_SILENCER
	/*0x04*/ { 60,  60,  88,  88,  1, 1, 1, 0, 30,   0,   10, 0,  0x2000 }, // WEAPON_FALCON2_SCOPE
	/*0x05*/ { 76,  88,  104, 120, 1, 1, 1, 2, 30,   30,  10, 10, 0x2000 }, // WEAPON_MAGSEC4
	/*0x06*/ { 64,  88,  92,  120, 1, 1, 1, 2, 30,   30,  10, 10, 0x2000 }, // WEAPON_MAULER
	/*0x07*/ { 72,  76,  100, 120, 1, 1, 1, 2, 30,   30,  10, 10, 0x4000 }, // WEAPON_PHOENIX
	/*0x08*/ { 68,  76,  96,  120, 1, 1, 1, 0, 30,   0,   8,  0,  0x6000 }, // WEAPON_DY357MAGNUM
	/*0x09*/ { 180, 188, 184, 188, 1, 1, 1, 0, 20,   0,   6,  0,  0x6000 }, // WEAPON_DY357LX
	/*0x0a*/ { 116, 128, 136, 152, 1, 1, 2, 2, 100,  100, 30, 30, 0x4000 }, // WEAPON_CMP150
	/*0x0b*/ { 120, 128, 132, 140, 1, 1, 2, 2, 150,  150, 50, 50, 0x4000 }, // WEAPON_CYCLONE
	/*0x0c*/ { 152, 176, 0,   0,   1, 1, 2, 2, 100,  70,  25, 15, 0x4000 }, // WEAPON_CALLISTONTG
	/*0x0d*/ { 172, 188, 0,   0,   1, 0, 2, 2, 300,  0,   40, 0,  0x4000 }, // WEAPON_RCP120
	/*0x0e*/ { 128, 140, 0,   0,   1, 1, 2, 2, 100,  0,   30, 0,  0x6000 }, // WEAPON_LAPTOPGUN
	/*0x0f*/ { 124, 148, 0,   0,   1, 1, 2, 2, 90,   0,   30, 0,  0x2000 }, // WEAPON_DRAGON
	/*0x10*/ { 156, 180, 0,   0,   1, 0, 2, 2, 150,  0,   40, 0,  0x4000 }, // WEAPON_K7AVENGER
	/*0x11*/ { 148, 176, 0,   0,   1, 0, 2, 2, 120,  0,   40, 0,  0x4000 }, // WEAPON_AR34
	/*0x12*/ { 164, 188, 0,   0,   1, 1, 2, 3, 120,  20,  30, 6,  0x2000 }, // WEAPON_SUPERDRAGON
	/*0x13*/ { 140, 156, 0,   0,   1, 1, 1, 1, 18,   18,  8,  8,  0xd000 }, // WEAPON_SHOTGUN
	/*0x14*/ { 144, 176, 0,   0,   1, 1, 2, 0, 400,  0,   80, 0,  0x6000 }, // WEAPON_REAPER
	/*0x15*/ { 28,  40,  0,   0,   1, 0, 2, 2, 30,   30,  10, 10, 0x4000 }, // WEAPON_SNIPERRIFLE
	/*0x16*/ { 188, 188, 0,   0,   1, 0, 3, 5, 16,   0,   4,  0,  0x4000 }, // WEAPON_FARSIGHTXR20
	/*0x17*/ { 176, 188, 0,   0,   1, 1, 3, 3, 20,   20,  4,  4,  0x4000 }, // WEAPON_DEVASTATOR
	/*0x18*/ { 160, 188, 0,   0,   1, 1, 3, 3, 2,    2,   1,  1,  0x4000 }, // WEAPON_ROCKETLAUNCHER
	/*0x19*/ { 168, 188, 0,   0,   1, 1, 3, 3, 2,    2,   1,  1,  0x6000 }, // WEAPON_SLAYER
	/*0x1a*/ { 20,  40,  24,  40,  1, 1, 0, 2, 0,    5,   0,  1,  0x2000 }, // WEAPON_COMBATKNIFE
	/*0x1b*/ { 108, 176, 0,   0,   1, 1, 2, 2, 15,   15,  5,  5,  0x9000 }, // WEAPON_CROSSBOW
	/*0x1c*/ { 48,  188, 0,   0,   1, 1, 2, 0, 20,   24,  6,  8,  0x2000 }, // WEAPON_TRANQUILIZER
	/*0x1d*/ { 112, 112, 0,   0,   1, 1, 2, 0, 0,    0,   0,  0,  0x2000 }, // WEAPON_LASER
	/*0x1e*/ { 36,  172, 0,   0,   1, 1, 7, 7, 6,    6,   2,  2,  0x2000 }, // WEAPON_GRENADE
	/*0x1f*/ { 32,  188, 0,   0,   1, 1, 7, 7, 3,    3,   1,  1,  0x2000 }, // WEAPON_NBOMB
	/*0x20*/ { 12,  12,  0,   0,   0, 0, 7, 2, 5,    5,   1,  1,  0x2000 }, // WEAPON_TIMEDMINE
	/*0x21*/ { 40,  176, 0,   0,   0, 0, 7, 2, 5,    5,   1,  1,  0x2000 }, // WEAPON_PROXIMITYMINE
	/*0x22*/ { 44,  156, 0,   0,   1, 0, 2, 2, 5,    5,   2,  2,  0x2000 }, // WEAPON_REMOTEMINE
	/*0x23*/ { 8,   8,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_COMBATBOOST
	/*0x24*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_PP9I
	/*0x25*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_CC13
	/*0x26*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_KL01313
	/*0x27*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_KF7SPECIAL
	/*0x28*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_ZZT
	/*0x29*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_DMC
	/*0x2a*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_AR53
	/*0x2b*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_RCP45
	/*0x2c*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_PSYCHOSISGUN
	/*0x2d*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_NIGHTVISION
	/*0x2e*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_EYESPY
	/*0x2f*/ { 4,   4,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_XRAYSCANNER
	/*0x30*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_IRSCANNER
	/*0x31*/ { 218, 218, 0,   0,   0, 0, 2, 2, 1200, 0,   0,  0,  0x2000 }, // WEAPON_CLOAKINGDEVICE
	/*0x32*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_HORIZONSCANNER
	/*0x33*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_TESTER
	/*0x34*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_ROCKETLAUNCHER_34
	/*0x35*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_ECMMINE
	/*0x36*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_DATAUPLINK
	/*0x37*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_RTRACKER
	/*0x38*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_PRESIDENTSCANNER
	/*0x39*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_DOORDECODER
	/*0x3a*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_AUTOSURGEON
	/*0x3b*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_EXPLOSIVES
	/*0x3c*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_SKEDARBOMB
	/*0x3d*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_COMMSRIDER
	/*0x3e*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_TRACERBUG
	/*0x3f*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_TARGETAMPLIFIER
	/*0x40*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_DISGUISE40
	/*0x41*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_DISGUISE41
	/*0x42*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_FLIGHTPLANS
	/*0x43*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_RESEARCHTAPE
	/*0x44*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_BACKUPDISK
	/*0x45*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_KEYCARD45
	/*0x46*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_KEYCARD46
	/*0x47*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_KEYCARD47
	/*0x48*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_KEYCARD48
	/*0x49*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_KEYCARD49
	/*0x4a*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_KEYCARD4A
	/*0x4b*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_KEYCARD4B
	/*0x4c*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_KEYCARD4C
	/*0x4d*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_SUITCASE
	/*0x4e*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_BRIEFCASE
	/*0x4f*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_SHIELD
	/*0x50*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_NECKLACE
	/*0x51*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_HAMMER
	/*0x52*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_52
	/*0x53*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_ROCKET
	/*0x54*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_HOMINGROCKET
	/*0x55*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_GRENADEROUND
	/*0x56*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_BOLT
	/*0x57*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_BRIEFCASE2
	/*0x58*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_ROCKET2
	/*0x59*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_59
	/*0x5a*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_5A
	/*0x5b*/ { 220, 220, 0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_MPSHIELD
	/*0x5c*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_DISABLED
	/*0x5d*/ { 0,   0,   0,   0,   0, 0, 2, 2, 0,    0,   0,  0,  0x2000 }, // WEAPON_SUICIDEPILL
};

void func0f197600(struct chrdata *chr)
{
	s32 index;
	f32 *limits;
	f32 distance;
	u8 new074;
	struct aibot *aibot = chr->aibot;
	s32 prev074 = aibot->unk074;
	struct prop *prop = NULL;
	s32 somevalue = 0;
	f32 limit1;
	f32 limit2;
	f32 limit3;
	u32 stack;

	if (aibot->simulant->base.simtype == SIMTYPE_KAZE) {
		index = 4;
	} else {
		index = func0f198e38(aibot->weaponnum, aibot->gunfunc);
	}

	if (chr->myaction == MA_AIBOTFOLLOW && aibot->followingplayernum >= 0) {
		limits = var80087e50[6];
		prop = g_MpPlayerChrs[aibot->followingplayernum]->prop;
		somevalue = aibot->unk16c[aibot->followingplayernum];

		if (chr->target != -1 && (index == 0 || index == 4)) {
			struct prop *target = chrGetTargetProp(chr);
			f32 xdiff = prop->pos.x - target->pos.x;
			f32 ydiff = prop->pos.y - target->pos.y;
			f32 zdiff = prop->pos.z - target->pos.z;

			if (xdiff * xdiff + ydiff * ydiff + zdiff * zdiff < 500 * 500) {
				limits = var80087e50[index];
				prop = target;
				somevalue = aibot->unk128;
			}
		}
	} else {
		limits = var80087e50[index];

		if (chr->myaction == MA_AIBOTATTACK && aibot->attackingplayernum >= 0) {
			prop = g_MpPlayerChrs[aibot->attackingplayernum]->prop;
			somevalue = aibot->unk16c[aibot->attackingplayernum];
		} else if (chr->target != -1) {
			prop = chrGetTargetProp(chr);
			somevalue = aibot->unk128;
		}
	}

	if (prop == NULL) {
		return;
	}

	if (!chrHasGround(prop->chr)) {
		return;
	}

	distance = chrGetDistanceToCoord(chr, &prop->pos);
	limit1 = limits[0];
	limit2 = limits[1];
	limit3 = limits[2];

	if (chr->aibot->simulant->difficulty == SIMDIFF_MEAT) {
		limit1 *= 0.35f;
	} else if (chr->aibot->simulant->difficulty == SIMDIFF_EASY) {
		limit1 *= 0.5f;
	}

	if (aibot->unk074 == 1) {
		limit1 += 25.0f;
	} else if (aibot->unk074 == 3 || aibot->unk074 == 4) {
		limit2 -= 25.0f;
	}

	if (distance < limit1) {
		new074 = 1;
	} else if (distance >= limit1 && distance < limit2) {
		new074 = 2;
	} else if (distance >= limit2 && distance < limit3) {
		new074 = 3;
	} else {
		new074 = 4;
	}

	if (new074 != 1 || somevalue == 0 || aibot->unk050 != prop) {
		aibot->unk050 = NULL;
		aibot->unk09d = 0;
	}

	if (new074 == 2) {
		if (somevalue == 0) {
			new074 = 3;
		}
	} else if (new074 == 1) {
		if (somevalue == 0) {
			new074 = 3;
			aibot->unk050 = prop;
			aibot->unk09d = 20 + (random() % 120);
		} else if (aibot->unk050) {
			if (aibot->unk09d > g_Vars.lvupdate240_60) {
				aibot->unk09d -= g_Vars.lvupdate240_60;
				new074 = 2;
			} else {
				aibot->unk050 = NULL;
				aibot->unk09d = 0;
			}
		}
	}

	aibot->unk074 = new074;

	if (aibot->unk0d0 >= 0) {
		aibot->unk0d0 -= g_Vars.lvupdate240_60;
	}

	if (new074 != prev074 || (new074 != 2 && (chr->actiontype == ACT_STAND || aibot->unk0d0 <= 0))) {
		switch (new074) {
		case 1:
			chrRunFromPos(chr, SPEED_RUN, 10000, &prop->pos);
			break;
		case 2:
			chrTryStop(chr);
			break;
		case 3:
			chrGoToProp(chr, prop, SPEED_RUN);
			break;
		case 4:
			chrGoToProp(chr, prop, SPEED_RUN);
			break;
		}

		aibot->unk0d0 = 60;
	}
}

void mpAibotApplyCommand(struct chrdata *chr, u32 command)
{
	f32 value;

	switch (command) {
	case AIBOTCMD_ATTACK:
		amOpenPickTarget();
		break;
	case AIBOTCMD_FOLLOW:
		mpAibotApplyFollow(chr, g_Vars.currentplayer->prop);
		break;
	case AIBOTCMD_PROTECT:
		mpAibotApplyProtect(chr, g_Vars.currentplayer->prop);
		break;
	case AIBOTCMD_DEFEND:
		value = chrGetInverseTheta(g_Vars.currentplayer->prop->chr);
		mpAibotApplyDefend(chr, &g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, value);
		break;
	case AIBOTCMD_HOLD:
		value = chrGetInverseTheta(g_Vars.currentplayer->prop->chr);
		mpAibotApplyHold(chr, &g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, value);
		break;
	default:
		mpAibotApplyScenarioCommand(chr, command);
		break;
	}
}

void aibotClearInventory(struct chrdata *chr)
{
	if (chr && chr->aibot) {
		s32 i = 0;

		for (i = 0; i < chr->aibot->maxitems; i++) {
			chr->aibot->items[i].type = -1;
		}

		dprint();
	}
}

struct invitem *aibotGetFreeInvSlot(struct chrdata *chr)
{
	s32 i;

	if (!chr || !chr->aibot) {
		return NULL;
	}

	for (i = 0; i < chr->aibot->maxitems; i++) {
		if (chr->aibot->items[i].type == -1) {
			return &chr->aibot->items[i];
		}
	}

	dprint();

	return NULL;
}

struct invitem *aibotGetInvItem(struct chrdata *chr, u32 weaponnum)
{
	s32 i;

	if (!chr || !chr->aibot) {
		return NULL;
	}

	for (i = 0; i < chr->aibot->maxitems; i++) {
		struct invitem *item = &chr->aibot->items[i];

		if (item->type == -1) {
			continue;
		}

		if (item->type == INVITEMTYPE_WEAP || item->type == INVITEMTYPE_DUAL) {
			if (item->type_weap.weapon1 == weaponnum) {
				return item;
			}
		}
	}

	return NULL;
}

void aibotRemoveInvItem(struct chrdata *chr, s32 weaponnum)
{
	s32 i;

	if (!chr || !chr->aibot) {
		return;
	}

	for (i = 0; i < chr->aibot->maxitems; i++) {
		struct invitem *item = &chr->aibot->items[i];

		if (item->type == -1) {
			continue;
		}

		if (item->type == INVITEMTYPE_WEAP || item->type == INVITEMTYPE_DUAL) {
			if (item->type_weap.weapon1 == weaponnum) {
				chr->aibot->items[i].type = -1;
				return;
			}
		}
	}
}

u32 aibotGetInvItemType(struct chrdata *chr, u32 weaponnum)
{
	struct invitem *item;

	if (!chr || !chr->aibot) {
		return 0;
	}

	item = aibotGetInvItem(chr, weaponnum);

	if (item) {
		return item->type;
	}

	return 0;
}

bool aibotGiveSingleWeapon(struct chrdata *chr, u32 weaponnum)
{
	if (!chr || !chr->aibot) {
		return false;
	}

	if (!aibotGetInvItemType(chr, weaponnum)) {
		struct invitem *item = aibotGetFreeInvSlot(chr);

		if (item) {
			item->type = INVITEMTYPE_WEAP;
			item->type_weap.weapon1 = weaponnum;
			item->type_weap.pickuppad = -1;
		}

		return true;
	}

	return false;
}

void aibotGiveDualWeapon(struct chrdata *chr, u32 weaponnum)
{
	struct invitem *item = aibotGetInvItem(chr, weaponnum);

	if (item) {
		item->type = INVITEMTYPE_DUAL;
	}
}

s16 aibotGetWeaponPad(struct chrdata *chr, u32 weaponnum)
{
	struct invitem *item = aibotGetInvItem(chr, weaponnum);

	if (item && item->type == INVITEMTYPE_WEAP) {
		return item->type_weap.pickuppad;
	}

	return -1;
}

bool aibotGiveProp(struct chrdata *chr, struct prop *prop)
{
	bool result = false;
	struct defaultobj *obj;
	s32 i;

	if (!chr || !chr->aibot) {
		return false;
	}

	obj = prop->obj;

	if (prop->type == PROPTYPE_WEAPON) {
		if (obj->type == OBJTYPE_WEAPON) {
			struct weaponobj *weapon = prop->weapon;
			s32 weaponnum = weapon->weaponnum;
			result = aibotGiveSingleWeapon(chr, weaponnum);

			if (result) {
				struct invitem *item = aibotGetInvItem(chr, weaponnum);
				item->type_weap.pickuppad = obj->pad;
			}
		}
	} else if (obj->type == OBJTYPE_MULTIAMMOCRATE) {
		struct multiammocrateobj *multi = (struct multiammocrateobj *)prop->obj;

		for (i = 0; i < 0x13; i++) {
			if (multi->quantities[i].unk02 > 0) {
				s32 weaponnum = ammotypeGetWeapon(i + 1);

				if (weaponnum > 0) {
					aibotGiveSingleWeapon(chr, weaponnum);
				}
			}
		}
	}

	return result;
}

void func0f198060(u32 arg0)
{
	// empty
}

void func0f198068(struct chrdata *chr, s32 *weaponnums, s32 *scores1, s32 *scores2)
{
	s32 i;
	s32 pri1;
	s32 pri2;
	s32 sec1;
	s32 sec2;

	// Gather scores for each weapon in the setup,
	// taking the higher score out of both gun functions
	for (i = 0; i < ARRAYCOUNT(g_MpSetup.weapons); i++) {
		s32 weaponnum = g_MpWeapons[g_MpSetup.weapons[i]].weaponnum;
		weaponnums[i] = weaponnum;

		func0f198df8(chr, weaponnum, FUNC_PRIMARY, -1, false, &pri1, &pri2);
		func0f198df8(chr, weaponnum, FUNC_SECONDARY, -1, false, &sec1, &sec2);

		scores1[i] = pri1 >= sec1 ? pri1 : sec1;
		scores2[i] = pri2 >= sec2 ? pri2 : sec2;
	}

	// Sort all three arrays by score1 descending
	for (i = 0; i < ARRAYCOUNT(g_MpSetup.weapons); i++) {
		s32 swapindex = i;
		s32 tmp;
		s32 j;

		for (j = i + 1; j < ARRAYCOUNT(g_MpSetup.weapons); j++) {
			if (scores1[j] > scores1[swapindex]) {
				swapindex = j;
			}
		}

		if (swapindex != i) {
			tmp = scores1[swapindex];
			scores1[swapindex] = scores1[i];
			scores1[i] = tmp;

			tmp = scores2[swapindex];
			scores2[swapindex] = scores2[i];
			scores2[i] = tmp;

			tmp = weaponnums[swapindex];
			weaponnums[swapindex] = weaponnums[i];
			weaponnums[i] = tmp;
		}
	}
}

bool mpHasShield(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpSetup.weapons); i++) {
		s32 weaponnum = g_MpWeapons[g_MpSetup.weapons[i]].weaponnum;

		if (weaponnum == WEAPON_MPSHIELD) {
			return true;
		}
	}

	return false;
}

s32 mpGetWeaponIndexByWeaponNum(s32 weaponnum)
{
	s32 result = -1;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpSetup.weapons); i++) {
		if (g_MpWeapons[g_MpSetup.weapons[i]].weaponnum == weaponnum && i < 6) {
			result = i;
			break;
		}
	}

	return result;
}

void aibotScoreWeapon(struct chrdata *chr, s32 weaponnum, s32 funcnum, s32 arg3, bool arg4, s32 *dst1, s32 *dst2, bool arg7, bool arg8)
{
	s32 score1 = 0;
	s32 score2 = 0;
	s32 extra = 0;

	// @dangerous: Array overflow can occur if more weapons are added to the
	// game without extending the preferences table
	if (arg3 < 0
			|| (!funcnum && arg3 == g_AibotWeaponPreferences[weaponnum].unk04_00)
			|| (funcnum && arg3 == g_AibotWeaponPreferences[weaponnum].unk04_01)) {
		if (arg4) {
			score1 = g_AibotWeaponPreferences[weaponnum].unk02;
			score2 = g_AibotWeaponPreferences[weaponnum].unk03;
		} else {
			score1 = g_AibotWeaponPreferences[weaponnum].unk00;
			score2 = g_AibotWeaponPreferences[weaponnum].unk01;
		}

		if (chr && chr->aibot) {
			// Add weighting for explosive weapons for rocket sims
			// and weighting for shields for shield sims, with extra
			// weighting if the sim is meat or easy.
			if (chr->aibot->simulant->difficulty == SIMDIFF_MEAT) {
				extra = 100;
			} else if (chr->aibot->simulant->difficulty == SIMDIFF_EASY) {
				extra = 50;
			}

			if (chr->aibot->simulant->base.simtype == SIMTYPE_ROCKET) {
				if (weaponnum == WEAPON_ROCKETLAUNCHER) {
					score1 = extra + 300;
				} else if (weaponnum == WEAPON_SLAYER) {
					score1 = extra + 299;
				} else if (weaponnum == WEAPON_DEVASTATOR) {
					score1 = extra + 280;
				} else if (weaponnum == WEAPON_SUPERDRAGON && funcnum != FUNC_PRIMARY) {
					score1 = extra + 279;
				} else if (weaponnum == WEAPON_PHOENIX && funcnum != FUNC_PRIMARY) {
					score1 = extra + 260;
				} else if (weaponnum == WEAPON_GRENADE) {
					score1 = extra + 240;
				}
			} else if (chr->aibot->simulant->base.simtype == SIMTYPE_SHIELD) {
				if (weaponnum == WEAPON_MPSHIELD) {
					score1 = extra + 300;
				}
			}
		}
	}

	// Missing from this list:
	// Mauler, K7 Avenger, AR34, sniper rifle, Farsight, laser, grenade
	switch (weaponnum) {
	case WEAPON_UNARMED:
		if (arg7 && funcnum != FUNC_PRIMARY) {
			if (chr->target != -1
					&& mpchrGetTargetsWeaponNum(chr) > WEAPON_UNARMED
					&& chr->aibot->simulant->difficulty > SIMDIFF_MEAT) {
				score1 = 26;
				score2 = 26;
			} else {
				score1 = 0;
				score2 = 0;
			}
		}
		break;
	case WEAPON_FALCON2:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 15;
			score2 = 15;
		}
		break;
	case WEAPON_FALCON2_SILENCER:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 14;
			score2 = 14;
		}
		break;
	case WEAPON_FALCON2_SCOPE:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 16;
			score2 = 16;
		}
		break;
	case WEAPON_MAGSEC4:
		if (funcnum == FUNC_PRIMARY) {
			score1 = arg4 ? 91 : 63;
		}
		break;
	case WEAPON_PHOENIX:
		if (chr->aibot->simulant->base.simtype != SIMDIFF_HARD) {
			if (funcnum != FUNC_PRIMARY) {
				if ((g_MpSetup.options & MPOPTION_ONEHITKILLS)
						&& chr->aibot->simulant->difficulty >= SIMDIFF_NORMAL) {
					score1 = 110;
					score2 = 150;
				}
			} else {
				score1 = arg4 ? 90 : 62;
			}
		}
		break;
	case WEAPON_DY357MAGNUM:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 17;
			score2 = 17;
		}
		break;
	case WEAPON_DY357LX:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 18;
			score2 = 18;
		}
		break;
	case WEAPON_CYCLONE:
		if (funcnum == (chr->aibot->unk210 & 1)) {
			score1--;
		}
		break;
	case WEAPON_CALLISTONTG:
		if (funcnum == (chr->aibot->unk210 & 1)) {
			score1--;
		}
		break;
	case WEAPON_RCP120:
		if (chr->aibot->cloakdeviceenabled == false
				&& func0f199be4(chr->aibot, WEAPON_RCP120, FUNC_PRIMARY, true) > 500
				&& chr->aibot->simulant->difficulty > SIMDIFF_MEAT) {
			score1 += chr->aibot->unk210 % 10;
			score2 += chr->aibot->unk210 % 10;
		}
		break;
	case WEAPON_LAPTOPGUN:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 0;
			score2 = 0;
		}
		break;
	case WEAPON_DRAGON:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 0;
			score2 = 0;
		}
		break;
	case WEAPON_SUPERDRAGON:
		if (chr->aibot->simulant->base.simtype != SIMDIFF_HARD
				&& (chr->aibot->unk210 & 1) == funcnum) {
			score1 -= 15;
		}
		break;
	case WEAPON_SHOTGUN:
		if (funcnum == (chr->aibot->unk210 & 1)) {
			score1--;
		}
		break;
	case WEAPON_REAPER:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 19;
			score2 = 80;
		}
		break;
	case WEAPON_DEVASTATOR:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 0;
			score2 = 0;
		}
		break;
	case WEAPON_ROCKETLAUNCHER:
		if (funcnum == (chr->aibot->unk210 & 1)) {
			score1--;
		}
		break;
	case WEAPON_SLAYER:
		if (chr->aibot->simulant->base.simtype == SIMDIFF_HARD) {
			if (funcnum != FUNC_PRIMARY) {
				if (chr->aibot->simulant->difficulty > SIMDIFF_MEAT) {
					if (arg7) {
						if (chr->target != -1
								&& chr->aibot->unk16c[mpPlayerGetIndex(chrGetTargetProp(chr)->chr)] == 0
								&& (chr->aibot->unk210 & 1) == 0) {
							score1 += 10;
						} else {
							score1 -= 10;
						}
					}
				} else {
					score1 = 0;
					score2 = 0;
				}
			}
		} else {
			if (funcnum != FUNC_PRIMARY) {
				if (chr->aibot->simulant->difficulty >= SIMDIFF_NORMAL) {
					if (arg7) {
						if (chr->target != -1
								&& chr->aibot->unk16c[mpPlayerGetIndex(chrGetTargetProp(chr)->chr)] == 0
								&& (chr->aibot->unk210 & 1) == 0) {
							score1 = 178;
							score2 = 188;
						} else {
							score1 -= 15;
							score2 -= 15;
						}
					}
				} else {
					score1 = 0;
					score2 = 0;
				}
			}
		}
		break;
	case WEAPON_COMBATKNIFE:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 0;
			score2 = 0;
		}
		break;
	case WEAPON_CROSSBOW:
		if (funcnum != FUNC_PRIMARY) {
			if (chr->aibot->simulant->difficulty > SIMDIFF_MEAT) {
				score1 = 158;
				score2 = 176;
			} else {
				score1 = 0;
				score2 = 0;
			}
		} else {
			if (arg7 && chr->target != -1 && chrGetTargetProp(chr)->chr->blurdrugamount > 3500) {
				score1 = 0;
				score2 = 0;
			} else {
				score1 = 49;
				score2 = 188;
			}
		}
		break;
	case WEAPON_TRANQUILIZER:
		if (arg7) {
			s32 bluramount = 0;

			if (chr->target != -1) {
				bluramount = chrGetTargetProp(chr)->chr->blurdrugamount;
			}

			if (funcnum != FUNC_PRIMARY) {
				if (chr->aibot->simulant->difficulty <= SIMDIFF_MEAT) {
					score1 = 0;
					score2 = 0;
				} else if (bluramount > 3500 && (chr->aibot->unk210 & 1) == 0) {
					score1 = chr->aibot->unk210 % 140 + 48;
					score2 = 188;
				} else if (chr->aibot->unk210 % 10 == 0) {
					score1 = chr->aibot->unk210 % 140 + 48;
					score2 = 188;
				} else {
					score1 = 0;
					score2 = 0;
				}
			} else {
				if (bluramount >= 5000) {
					score2 = 48;

					if (chr->aibot->unk210 & 1) {
						score1 = 0;
						score2 = 0;
					}
				} else if (bluramount > 3500) {
					u32 value = (-bluramount * 16 + 80000) / 1500;

					if (value > 15) {
						value = 15;
					}

					value *= value;
					value *= value;
					value *= value;

					if (value < chr->aibot->unk210) {
						score2 = 48;

						if (chr->aibot->unk210 & 1) {
							score1 = 0;
							score2 = 0;
						}
					}
				}
			}
		}
		break;
	case WEAPON_NBOMB:
		if (arg7 && chr->target != -1) {
			mpchrGetTargetsWeaponNum(chr);
		}
		break;
	}

	if (arg8) {
		s32 weaponindex;
		s32 extra = 0;
		f32 float1;
		f32 killrate = 1;
		f32 float2;

		if (g_Vars.lvframe60 > 0) {
			killrate = g_Vars.totalkills * 3600.0f / (f32)(g_Vars.lvframe60 * g_MpNumPlayers);

			if (killrate < 1) {
				killrate = 1;
			}
		}

		weaponindex = mpGetWeaponIndexByWeaponNum(weaponnum);

		if (weaponindex >= 0) {
			float2 = ceilf(chr->aibot->unk274[weaponindex][funcnum] * (1.0f / 3600.0f));

			if (float2 > 0) {
				float1 = chr->aibot->killsbygunfunc[weaponindex][funcnum];

				if (chr->aibot->simulant->difficulty >= SIMDIFF_NORMAL) {
					float1 -= 3.0f * chr->aibot->suicidesbygunfunc[weaponindex][funcnum];
				}

				float1 = float1 / float2;

				extra = float1 * 10.0f / killrate;
			}

			if (extra > 30) {
				extra = 30;
			}

			extra += chr->aibot->unk2a8[weaponindex];

			score1 += extra;
			score2 += extra;

			if (score1 < 0) {
				score1 = 0;
			}

			if (score2 < 0) {
				score2 = 0;
			}
		}
	}

	*dst1 = score1;
	*dst2 = score2;
}

void func0f198db4(struct chrdata *chr, s32 weaponnum, s32 funcnum, s32 arg3, bool arg4, s32 *dst1, s32 *dst2)
{
	aibotScoreWeapon(chr, weaponnum, funcnum, arg3, arg4, dst1, dst2, true, true);
}

void func0f198df8(struct chrdata *chr, s32 weaponnum, s32 funcnum, s32 arg3, bool arg4, s32 *dst1, s32 *dst2)
{
	aibotScoreWeapon(chr, weaponnum, funcnum, arg3, arg4, dst1, dst2, false, true);
}

s32 func0f198e38(s32 weaponnum, s32 funcnum)
{
	if (funcnum != FUNC_PRIMARY) {
		return g_AibotWeaponPreferences[weaponnum].unk04_06;
	}

	return g_AibotWeaponPreferences[weaponnum].unk04_02;
}

bool func0f198e78(struct chrdata *chr, s32 weaponnum, s32 funcnum)
{
	bool result = true;

	if (chr->aibot->simulant->base.simtype == SIMTYPE_FIST) {
		if (funcnum != FUNC_PRIMARY) {
			if (g_AibotWeaponPreferences[weaponnum].unk04_06) {
				result = false;
			}
		} else {
			if (g_AibotWeaponPreferences[weaponnum].unk04_02) {
				result = false;
			}
		}
	}

	return result;
}

GLOBAL_ASM(
glabel func0f198eec
.late_rodata
glabel var7f1b9090
.word 0x3f666666
glabel var7f1b9094
.word 0x44bb8000
.text
/*  f198eec:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f198ef0:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f198ef4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f198ef8:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f198efc:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f198f00:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f198f04:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f198f08:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f198f0c:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f198f10:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f198f14:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f198f18:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f198f1c:	00802825 */ 	or	$a1,$a0,$zero
/*  f198f20:	afae009c */ 	sw	$t6,0x9c($sp)
/*  f198f24:	afa00098 */ 	sw	$zero,0x98($sp)
/*  f198f28:	10800155 */ 	beqz	$a0,.L0f199480
/*  f198f2c:	0000b025 */ 	or	$s6,$zero,$zero
/*  f198f30:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f198f34:	50400153 */ 	beqzl	$v0,.L0f199484
/*  f198f38:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f198f3c:	8c440020 */ 	lw	$a0,0x20($v0)
/*  f198f40:	afa500a0 */ 	sw	$a1,0xa0($sp)
/*  f198f44:	0fc660b5 */ 	jal	mpGetWeaponIndexByWeaponNum
/*  f198f48:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f198f4c:	0440000e */ 	bltz	$v0,.L0f198f88
/*  f198f50:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f198f54:	8c99004c */ 	lw	$t9,0x4c($a0)
/*  f198f58:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f198f5c:	3c17800a */ 	lui	$s7,%hi(g_Vars)
/*  f198f60:	00194080 */ 	sll	$t0,$t9,0x2
/*  f198f64:	00084fc2 */ 	srl	$t1,$t0,0x1f
/*  f198f68:	00095080 */ 	sll	$t2,$t1,0x2
/*  f198f6c:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f198f70:	26f79fc0 */ 	addiu	$s7,$s7,%lo(g_Vars)
/*  f198f74:	030a1821 */ 	addu	$v1,$t8,$t2
/*  f198f78:	8c6b0274 */ 	lw	$t3,0x274($v1)
/*  f198f7c:	8eec0038 */ 	lw	$t4,0x38($s7)
/*  f198f80:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f198f84:	ac6d0274 */ 	sw	$t5,0x274($v1)
.L0f198f88:
/*  f198f88:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f198f8c:	3c17800a */ 	lui	$s7,%hi(g_Vars)
/*  f198f90:	26f79fc0 */ 	addiu	$s7,$s7,%lo(g_Vars)
/*  f198f94:	8eef0038 */ 	lw	$t7,0x38($s7)
/*  f198f98:	8c8e02c0 */ 	lw	$t6,0x2c0($a0)
/*  f198f9c:	01cfc823 */ 	subu	$t9,$t6,$t7
/*  f198fa0:	07210021 */ 	bgez	$t9,.L0f199028
/*  f198fa4:	ac9902c0 */ 	sw	$t9,0x2c0($a0)
/*  f198fa8:	0c004b70 */ 	jal	random
/*  f198fac:	00000000 */ 	nop
/*  f198fb0:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f198fb4:	0041001b */ 	divu	$zero,$v0,$at
/*  f198fb8:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f198fbc:	00004810 */ 	mfhi	$t1
/*  f198fc0:	25380e10 */ 	addiu	$t8,$t1,0xe10
/*  f198fc4:	3c017f1c */ 	lui	$at,%hi(var7f1b9090)
/*  f198fc8:	ac9802c0 */ 	sw	$t8,0x2c0($a0)
/*  f198fcc:	c4209090 */ 	lwc1	$f0,%lo(var7f1b9090)($at)
/*  f198fd0:	24020006 */ 	addiu	$v0,$zero,0x6
/*  f198fd4:	0000f025 */ 	or	$s8,$zero,$zero
/*  f198fd8:	00801825 */ 	or	$v1,$a0,$zero
/*  f198fdc:	c46c0244 */ 	lwc1	$f12,0x244($v1)
/*  f198fe0:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f198fe4:	c4700248 */ 	lwc1	$f16,0x248($v1)
/*  f198fe8:	46006482 */ 	mul.s	$f18,$f12,$f0
/*  f198fec:	13c2000a */ 	beq	$s8,$v0,.L0f199018
/*  f198ff0:	00000000 */ 	nop
.L0f198ff4:
/*  f198ff4:	46008382 */ 	mul.s	$f14,$f16,$f0
/*  f198ff8:	c46c024c */ 	lwc1	$f12,0x24c($v1)
/*  f198ffc:	c4700250 */ 	lwc1	$f16,0x250($v1)
/*  f199000:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f199004:	e4720244 */ 	swc1	$f18,0x244($v1)
/*  f199008:	46006482 */ 	mul.s	$f18,$f12,$f0
/*  f19900c:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f199010:	17c2fff8 */ 	bne	$s8,$v0,.L0f198ff4
/*  f199014:	e46e0240 */ 	swc1	$f14,0x240($v1)
.L0f199018:
/*  f199018:	46008382 */ 	mul.s	$f14,$f16,$f0
/*  f19901c:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f199020:	e472023c */ 	swc1	$f18,0x23c($v1)
/*  f199024:	e46e0240 */ 	swc1	$f14,0x240($v1)
.L0f199028:
/*  f199028:	8c8a02a4 */ 	lw	$t2,0x2a4($a0)
/*  f19902c:	8eeb0038 */ 	lw	$t3,0x38($s7)
/*  f199030:	014b6023 */ 	subu	$t4,$t2,$t3
/*  f199034:	0581003a */ 	bgez	$t4,.L0f199120
/*  f199038:	ac8c02a4 */ 	sw	$t4,0x2a4($a0)
/*  f19903c:	0c004b70 */ 	jal	random
/*  f199040:	00000000 */ 	nop
/*  f199044:	24010bb8 */ 	addiu	$at,$zero,0xbb8
/*  f199048:	0041001b */ 	divu	$zero,$v0,$at
/*  f19904c:	8fb00090 */ 	lw	$s0,0x90($sp)
/*  f199050:	00007010 */ 	mfhi	$t6
/*  f199054:	25cf0258 */ 	addiu	$t7,$t6,0x258
/*  f199058:	0000f025 */ 	or	$s8,$zero,$zero
/*  f19905c:	00008825 */ 	or	$s1,$zero,$zero
/*  f199060:	2415001e */ 	addiu	$s5,$zero,0x1e
/*  f199064:	24140064 */ 	addiu	$s4,$zero,0x64
/*  f199068:	24130018 */ 	addiu	$s3,$zero,0x18
/*  f19906c:	241200c8 */ 	addiu	$s2,$zero,0xc8
/*  f199070:	ae0f02a4 */ 	sw	$t7,0x2a4($s0)
.L0f199074:
/*  f199074:	8fa30090 */ 	lw	$v1,0x90($sp)
/*  f199078:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19907c:	8c790004 */ 	lw	$t9,0x4($v1)
/*  f199080:	93220048 */ 	lbu	$v0,0x48($t9)
/*  f199084:	1440000c */ 	bnez	$v0,.L0f1990b8
/*  f199088:	00000000 */ 	nop
/*  f19908c:	0c004b70 */ 	jal	random
/*  f199090:	00000000 */ 	nop
/*  f199094:	0052001b */ 	divu	$zero,$v0,$s2
/*  f199098:	00004010 */ 	mfhi	$t0
/*  f19909c:	2509ff9c */ 	addiu	$t1,$t0,-100
/*  f1990a0:	16400002 */ 	bnez	$s2,.L0f1990ac
/*  f1990a4:	00000000 */ 	nop
/*  f1990a8:	0007000d */ 	break	0x7
.L0f1990ac:
/*  f1990ac:	ae0902a8 */ 	sw	$t1,0x2a8($s0)
/*  f1990b0:	10000018 */ 	b	.L0f199114
/*  f1990b4:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f1990b8:
/*  f1990b8:	1441000c */ 	bne	$v0,$at,.L0f1990ec
/*  f1990bc:	00000000 */ 	nop
/*  f1990c0:	0c004b70 */ 	jal	random
/*  f1990c4:	00000000 */ 	nop
/*  f1990c8:	0054001b */ 	divu	$zero,$v0,$s4
/*  f1990cc:	0000c010 */ 	mfhi	$t8
/*  f1990d0:	270affce */ 	addiu	$t2,$t8,-50
/*  f1990d4:	16800002 */ 	bnez	$s4,.L0f1990e0
/*  f1990d8:	00000000 */ 	nop
/*  f1990dc:	0007000d */ 	break	0x7
.L0f1990e0:
/*  f1990e0:	ae0a02a8 */ 	sw	$t2,0x2a8($s0)
/*  f1990e4:	1000000b */ 	b	.L0f199114
/*  f1990e8:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f1990ec:
/*  f1990ec:	0c004b70 */ 	jal	random
/*  f1990f0:	00000000 */ 	nop
/*  f1990f4:	0055001b */ 	divu	$zero,$v0,$s5
/*  f1990f8:	00005810 */ 	mfhi	$t3
/*  f1990fc:	256cfff1 */ 	addiu	$t4,$t3,-15
/*  f199100:	ae0c02a8 */ 	sw	$t4,0x2a8($s0)
/*  f199104:	16a00002 */ 	bnez	$s5,.L0f199110
/*  f199108:	00000000 */ 	nop
/*  f19910c:	0007000d */ 	break	0x7
.L0f199110:
/*  f199110:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f199114:
/*  f199114:	1633ffd7 */ 	bne	$s1,$s3,.L0f199074
/*  f199118:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f19911c:	8fa40090 */ 	lw	$a0,0x90($sp)
.L0f199120:
/*  f199120:	8c8d020c */ 	lw	$t5,0x20c($a0)
/*  f199124:	8eee0038 */ 	lw	$t6,0x38($s7)
/*  f199128:	01ae7823 */ 	subu	$t7,$t5,$t6
/*  f19912c:	05e1000c */ 	bgez	$t7,.L0f199160
/*  f199130:	ac8f020c */ 	sw	$t7,0x20c($a0)
/*  f199134:	0c004b70 */ 	jal	random
/*  f199138:	00000000 */ 	nop
/*  f19913c:	24010258 */ 	addiu	$at,$zero,0x258
/*  f199140:	0041001b */ 	divu	$zero,$v0,$at
/*  f199144:	8fb80090 */ 	lw	$t8,0x90($sp)
/*  f199148:	00004010 */ 	mfhi	$t0
/*  f19914c:	25090078 */ 	addiu	$t1,$t0,0x78
/*  f199150:	0c004b70 */ 	jal	random
/*  f199154:	af09020c */ 	sw	$t1,0x20c($t8)
/*  f199158:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f19915c:	ac820210 */ 	sw	$v0,0x210($a0)
.L0f199160:
/*  f199160:	8c8b00c8 */ 	lw	$t3,0xc8($a0)
/*  f199164:	556000c7 */ 	bnezl	$t3,.L0f199484
/*  f199168:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f19916c:	8c8c00c4 */ 	lw	$t4,0xc4($a0)
/*  f199170:	558000c4 */ 	bnezl	$t4,.L0f199484
/*  f199174:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f199178:	908d004e */ 	lbu	$t5,0x4e($a0)
/*  f19917c:	5da000c1 */ 	bgtzl	$t5,.L0f199484
/*  f199180:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f199184:	908e004d */ 	lbu	$t6,0x4d($a0)
/*  f199188:	5dc000be */ 	bgtzl	$t6,.L0f199484
/*  f19918c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f199190:	848f00e2 */ 	lh	$t7,0xe2($a0)
/*  f199194:	5de000bb */ 	bgtzl	$t7,.L0f199484
/*  f199198:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f19919c:	849900e0 */ 	lh	$t9,0xe0($a0)
/*  f1991a0:	5f2000b8 */ 	bgtzl	$t9,.L0f199484
/*  f1991a4:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f1991a8:	8c880044 */ 	lw	$t0,0x44($a0)
/*  f1991ac:	8fa900a0 */ 	lw	$t1,0xa0($sp)
/*  f1991b0:	550000b4 */ 	bnezl	$t0,.L0f199484
/*  f1991b4:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f1991b8:	913802a0 */ 	lbu	$t8,0x2a0($t1)
/*  f1991bc:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f1991c0:	17010002 */ 	bne	$t8,$at,.L0f1991cc
/*  f1991c4:	00000000 */ 	nop
/*  f1991c8:	24160001 */ 	addiu	$s6,$zero,0x1
.L0f1991cc:
/*  f1991cc:	16c00009 */ 	bnez	$s6,.L0f1991f4
/*  f1991d0:	00000000 */ 	nop
/*  f1991d4:	8c8a0004 */ 	lw	$t2,0x4($a0)
/*  f1991d8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1991dc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1991e0:	914b0047 */ 	lbu	$t3,0x47($t2)
/*  f1991e4:	15610003 */ 	bne	$t3,$at,.L0f1991f4
/*  f1991e8:	00000000 */ 	nop
/*  f1991ec:	afac0098 */ 	sw	$t4,0x98($sp)
/*  f1991f0:	24160001 */ 	addiu	$s6,$zero,0x1
.L0f1991f4:
/*  f1991f4:	56c00055 */ 	bnezl	$s6,.L0f19934c
/*  f1991f8:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f1991fc:	80830018 */ 	lb	$v1,0x18($a0)
/*  f199200:	00009825 */ 	or	$s3,$zero,$zero
/*  f199204:	241effff */ 	addiu	$s8,$zero,-1
/*  f199208:	0460004f */ 	bltz	$v1,.L0f199348
/*  f19920c:	24170003 */ 	addiu	$s7,$zero,0x3
/*  f199210:	27b6007c */ 	addiu	$s6,$sp,0x7c
/*  f199214:	27b50080 */ 	addiu	$s5,$sp,0x80
/*  f199218:	2411ffff */ 	addiu	$s1,$zero,-1
.L0f19921c:
/*  f19921c:	07c10003 */ 	bgez	$s8,.L0f19922c
/*  f199220:	00009025 */ 	or	$s2,$zero,$zero
/*  f199224:	1000000d */ 	b	.L0f19925c
/*  f199228:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f19922c:
/*  f19922c:	8c8d0014 */ 	lw	$t5,0x14($a0)
/*  f199230:	001e7080 */ 	sll	$t6,$s8,0x2
/*  f199234:	01de7021 */ 	addu	$t6,$t6,$s8
/*  f199238:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19923c:	01ae9021 */ 	addu	$s2,$t5,$t6
/*  f199240:	8e420000 */ 	lw	$v0,0x0($s2)
/*  f199244:	24010001 */ 	addiu	$at,$zero,0x1
/*  f199248:	50410004 */ 	beql	$v0,$at,.L0f19925c
/*  f19924c:	86510004 */ 	lh	$s1,0x4($s2)
/*  f199250:	16e20002 */ 	bne	$s7,$v0,.L0f19925c
/*  f199254:	00000000 */ 	nop
/*  f199258:	86510004 */ 	lh	$s1,0x4($s2)
.L0f19925c:
/*  f19925c:	06200036 */ 	bltz	$s1,.L0f199338
/*  f199260:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f199264:	3c198008 */ 	lui	$t9,%hi(g_AibotWeaponPreferences)
/*  f199268:	27397eb0 */ 	addiu	$t9,$t9,%lo(g_AibotWeaponPreferences)
/*  f19926c:	00117900 */ 	sll	$t7,$s1,0x4
/*  f199270:	01f9a021 */ 	addu	$s4,$t7,$t9
.L0f199274:
/*  f199274:	12000005 */ 	beqz	$s0,.L0f19928c
/*  f199278:	96830004 */ 	lhu	$v1,0x4($s4)
/*  f19927c:	00031440 */ 	sll	$v0,$v1,0x11
/*  f199280:	000247c2 */ 	srl	$t0,$v0,0x1f
/*  f199284:	10000002 */ 	b	.L0f199290
/*  f199288:	01001025 */ 	or	$v0,$t0,$zero
.L0f19928c:
/*  f19928c:	000313c2 */ 	srl	$v0,$v1,0xf
.L0f199290:
/*  f199290:	10400024 */ 	beqz	$v0,.L0f199324
/*  f199294:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f199298:	02202825 */ 	or	$a1,$s1,$zero
/*  f19929c:	0fc6639e */ 	jal	func0f198e78
/*  f1992a0:	02003025 */ 	or	$a2,$s0,$zero
/*  f1992a4:	1040001f */ 	beqz	$v0,.L0f199324
/*  f1992a8:	0012182b */ 	sltu	$v1,$zero,$s2
/*  f1992ac:	10600004 */ 	beqz	$v1,.L0f1992c0
/*  f1992b0:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f1992b4:	8e490000 */ 	lw	$t1,0x0($s2)
/*  f1992b8:	02e91826 */ 	xor	$v1,$s7,$t1
/*  f1992bc:	2c630001 */ 	sltiu	$v1,$v1,0x1
.L0f1992c0:
/*  f1992c0:	02202825 */ 	or	$a1,$s1,$zero
/*  f1992c4:	02003025 */ 	or	$a2,$s0,$zero
/*  f1992c8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1992cc:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f1992d0:	afb50014 */ 	sw	$s5,0x14($sp)
/*  f1992d4:	0fc6636d */ 	jal	func0f198db4
/*  f1992d8:	afb60018 */ 	sw	$s6,0x18($sp)
/*  f1992dc:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f1992e0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1992e4:	0313082a */ 	slt	$at,$t8,$s3
/*  f1992e8:	5420000f */ 	bnezl	$at,.L0f199328
/*  f1992ec:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f1992f0:	0fc6666c */ 	jal	weaponGetAmmoTypeByFunction
/*  f1992f4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1992f8:	10400007 */ 	beqz	$v0,.L0f199318
/*  f1992fc:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f199300:	02202825 */ 	or	$a1,$s1,$zero
/*  f199304:	02003025 */ 	or	$a2,$s0,$zero
/*  f199308:	0fc666f9 */ 	jal	func0f199be4
/*  f19930c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f199310:	58400005 */ 	blezl	$v0,.L0f199328
/*  f199314:	2610ffff */ 	addiu	$s0,$s0,-1
.L0f199318:
/*  f199318:	8fb30080 */ 	lw	$s3,0x80($sp)
/*  f19931c:	afb1009c */ 	sw	$s1,0x9c($sp)
/*  f199320:	afb00098 */ 	sw	$s0,0x98($sp)
.L0f199324:
/*  f199324:	2610ffff */ 	addiu	$s0,$s0,-1
.L0f199328:
/*  f199328:	0601ffd2 */ 	bgez	$s0,.L0f199274
/*  f19932c:	00000000 */ 	nop
/*  f199330:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f199334:	80830018 */ 	lb	$v1,0x18($a0)
.L0f199338:
/*  f199338:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f19933c:	03c3082a */ 	slt	$at,$s8,$v1
/*  f199340:	5420ffb6 */ 	bnezl	$at,.L0f19921c
/*  f199344:	2411ffff */ 	addiu	$s1,$zero,-1
.L0f199348:
/*  f199348:	8fab009c */ 	lw	$t3,0x9c($sp)
.L0f19934c:
/*  f19934c:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f199350:	24170003 */ 	addiu	$s7,$zero,0x3
/*  f199354:	1561002b */ 	bne	$t3,$at,.L0f199404
/*  f199358:	2405001a */ 	addiu	$a1,$zero,0x1a
/*  f19935c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f199360:	0fc666f9 */ 	jal	func0f199be4
/*  f199364:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f199368:	28410002 */ 	slti	$at,$v0,0x2
/*  f19936c:	14200025 */ 	bnez	$at,.L0f199404
/*  f199370:	8fac00a0 */ 	lw	$t4,0xa0($sp)
/*  f199374:	858d017e */ 	lh	$t5,0x17e($t4)
/*  f199378:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19937c:	51a10022 */ 	beql	$t5,$at,.L0f199408
/*  f199380:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f199384:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f199388:	01802025 */ 	or	$a0,$t4,$zero
/*  f19938c:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f199390:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f199394:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f199398:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f19939c:	3c014348 */ 	lui	$at,0x4348
/*  f1993a0:	8dcf02d4 */ 	lw	$t7,0x2d4($t6)
/*  f1993a4:	44818000 */ 	mtc1	$at,$f16
/*  f1993a8:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f1993ac:	c512013c */ 	lwc1	$f18,0x13c($t0)
/*  f1993b0:	4612803c */ 	c.lt.s	$f16,$f18
/*  f1993b4:	00000000 */ 	nop
/*  f1993b8:	45020013 */ 	bc1fl	.L0f199408
/*  f1993bc:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f1993c0:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f1993c4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1993c8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1993cc:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1993d0:	8fa900a0 */ 	lw	$t1,0xa0($sp)
/*  f1993d4:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1993d8:	3c017f1c */ 	lui	$at,%hi(var7f1b9094)
/*  f1993dc:	8d3802d4 */ 	lw	$t8,0x2d4($t1)
/*  f1993e0:	c4269094 */ 	lwc1	$f6,%lo(var7f1b9094)($at)
/*  f1993e4:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1993e8:	030a5821 */ 	addu	$t3,$t8,$t2
/*  f1993ec:	c564013c */ 	lwc1	$f4,0x13c($t3)
/*  f1993f0:	4606203c */ 	c.lt.s	$f4,$f6
/*  f1993f4:	00000000 */ 	nop
/*  f1993f8:	45020003 */ 	bc1fl	.L0f199408
/*  f1993fc:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f199400:	afad0098 */ 	sw	$t5,0x98($sp)
.L0f199404:
/*  f199404:	8fa40090 */ 	lw	$a0,0x90($sp)
.L0f199408:
/*  f199408:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f19940c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f199410:	8c8c0004 */ 	lw	$t4,0x4($a0)
/*  f199414:	918f0047 */ 	lbu	$t7,0x47($t4)
/*  f199418:	56ef0016 */ 	bnel	$s7,$t7,.L0f199474
/*  f19941c:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f199420:	17210008 */ 	bne	$t9,$at,.L0f199444
/*  f199424:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f199428:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19942c:	0fc666f9 */ 	jal	func0f199be4
/*  f199430:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f199434:	18400003 */ 	blez	$v0,.L0f199444
/*  f199438:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f19943c:	1000000c */ 	b	.L0f199470
/*  f199440:	afa80098 */ 	sw	$t0,0x98($sp)
.L0f199444:
/*  f199444:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f199448:	24010012 */ 	addiu	$at,$zero,0x12
/*  f19944c:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f199450:	15c10007 */ 	bne	$t6,$at,.L0f199470
/*  f199454:	24050012 */ 	addiu	$a1,$zero,0x12
/*  f199458:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19945c:	0fc666f9 */ 	jal	func0f199be4
/*  f199460:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f199464:	18400002 */ 	blez	$v0,.L0f199470
/*  f199468:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f19946c:	afa90098 */ 	sw	$t1,0x98($sp)
.L0f199470:
/*  f199470:	8fa400a0 */ 	lw	$a0,0xa0($sp)
.L0f199474:
/*  f199474:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f199478:	0fc6652c */ 	jal	aibotSwitchToWeapon
/*  f19947c:	8fa60098 */ 	lw	$a2,0x98($sp)
.L0f199480:
/*  f199480:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f199484:
/*  f199484:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f199488:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f19948c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f199490:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f199494:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f199498:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f19949c:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f1994a0:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f1994a4:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f1994a8:	03e00008 */ 	jr	$ra
/*  f1994ac:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

bool aibotSwitchToWeapon(struct chrdata *chr, s32 weaponnum, s32 funcnum)
{
	struct invitem *item;
	struct weaponfunc *func;
	struct aibot *aibot;
	s32 i;
	s32 modelnum;
	bool changinggun;
	bool changingfunc;

	if (!chr || !chr->aibot) {
		return false;
	}

	aibot = chr->aibot;

	if (weaponnum == WEAPON_BRIEFCASE2) {
		return true;
	}

	// If changing to anything other than unarmed, make sure the aibot has the
	// weapon in their inventory. Otherwise make them switch to unarmed.
	if (weaponnum != WEAPON_UNARMED) {
		item = aibotGetInvItem(chr, weaponnum);

		if (!item) {
			weaponnum = WEAPON_UNARMED;
			funcnum = FUNC_PRIMARY;
		}
	}

	changinggun = weaponnum != aibot->weaponnum;
	changingfunc = funcnum != aibot->gunfunc;

	if (changinggun) {
		aibot->unk0cc = 60;

		for (i = 0; i < 2; i++) {
			aibot->unk0c4[i] = 0;
			aibot->unk04d[i] = 0;
			aibot->unk0e0[i] = 0;

			if (chr->weapons_held[i]) {
				chr->weapons_held[i]->obj->hidden |= OBJHFLAG_00000004;
				chr->weapons_held[i] = NULL;
			}
		}
	}

	// Return any loaded ammo to reserve
	if (changingfunc || changinggun) {
		for (i = 0; i < 2; i++) {
			if (aibot->loadedammo[i] > 0) {
				aibotGiveAmmoByWeapon(aibot, aibot->weaponnum, aibot->gunfunc, aibot->loadedammo[i]);
				aibot->loadedammo[i] = 0;
			}
		}
	}

	// Assign new weapon and function
	aibot->gunfunc = funcnum;
	aibot->weaponnum = weaponnum;

	// Load ammo from reserve into new weapon
	if (changingfunc && !changinggun) {
		for (i = 0; i < 2; i++) {
			if (chr->weapons_held[i]) {
				aibotReloadWeapon(chr, i, false);
			}
		}
	}

	if (!changinggun) {
		modelnum = weaponGetModel(weaponnum);

		// @dangerous: item is uninitialised if weaponnum is WEAPON_UNARMED.
		// This function assumes weaponGetModel returns a negative value for
		// WEAPON_UNARMED which is a dangerous assumption to make, but correct.
		if (modelnum >= 0 && item && item->type == INVITEMTYPE_DUAL && chr->weapons_held[1] == NULL) {
			chrGiveWeapon(chr, modelnum, weaponnum, 0x10000000);
			aibotReloadWeapon(chr, HAND_LEFT, false);
		}
	}

	func = weaponGetFunctionById(weaponnum, funcnum);

	aibot->iscloserangeweapon = func && func->type == INVENTORYFUNCTYPE_CLOSE;

	for (i = 0; i < 2; i++) {
		if (chr->weapons_held[i]) {
			chr->weapons_held[i]->weapon->gunfunc = chr->aibot->gunfunc;
		}
	}

	return true;
}

void func0f19978c(struct chrdata *chr, s32 weaponnum, u8 arg2)
{
	s32 i;

	if (!chr || !chr->aibot) {
		return;
	}

	for (i = 0; i < chr->aibot->maxitems; i++) {
		struct invitem *item = &chr->aibot->items[i];

		if (item->type == -1) {
			continue;
		}

		if ((item->type == INVITEMTYPE_WEAP || item->type == INVITEMTYPE_DUAL)
				&& (arg2 || weaponnum == item->type_weap.weapon1)) {
			if (weaponHasFlag(item->type_weap.weapon1, WEAPONFLAG_08000000) == 0
					|| (g_Vars.normmplayerisrunning
						&& g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL
						&& item->type_weap.weapon1 == WEAPON_DATAUPLINK)) {
				s32 modelnum = weaponGetModel(item->type_weap.weapon1);

				if (modelnum > 0) {
					struct prop *prop = func0f08b8e8(chr, modelnum, item->type_weap.weapon1, 0x20000000, 0, 0);

					if (prop) {
						propobjSetDropped(prop, DROPREASON_1);
						func0f08307c(prop, true);

						if (item->type_weap.weapon1 == WEAPON_BRIEFCASE2) {
							func0f187288(chr, prop);
						}
					}
				}
			}
		}
	}

	if ((arg2 && weaponnum >= WEAPON_FALCON2)
			|| (!arg2 && weaponnum == chr->aibot->weaponnum)) {
		aibotSwitchToWeapon(chr, WEAPON_UNARMED, FUNC_PRIMARY);
	}

	chr->hidden |= CHRHFLAG_00000001;

	if (!arg2) {
		aibotRemoveInvItem(chr, weaponnum);
	}
}

void func0f199964(struct chrdata *chr, u32 weaponnum)
{
	func0f19978c(chr, weaponnum, true);
}

void func0f199984(struct chrdata *chr, u32 weaponnum)
{
	func0f19978c(chr, weaponnum, false);
}
