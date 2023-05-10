#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/dlights.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/atan2f.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/player.h"
#include "game/hudmsg.h"
#include "game/menu.h"
#include "game/filemgr.h"
#include "game/inv.h"
#include "game/explosions.h"
#include "game/game_1531a0.h"
#include "game/bg.h"
#include "game/trainingmenus.h"
#include "game/training.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/pad.h"
#include "game/padhalllv.h"
#include "game/propobj.h"
#include "game/shards.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

#define FRSCRIPTINDEX_WEAPONS 0x00
#define FRSCRIPTINDEX_TARGETS 0x22
#define FRSCRIPTINDEX_HELP    0x71

extern u8 *_firingrangeSegmentRomStart;
extern u8 *_firingrangeSegmentRomEnd;

struct frdata g_FrData;
struct trainingdata g_DtData;
struct trainingdata g_HtData;

u16 *g_FrScriptOffsets = NULL;
u8 g_FrIsValidWeapon = false;
u8 g_FrDataLoaded = false;
u8 g_FrNumSounds = 0;
u8 *g_FrRomData = NULL;

u16 g_FrPads[] = {
	0x00d6, 0x00d7, 0x00d9, 0x00d8, 0x00da, 0x00db, 0x00dc, 0x00dd,
	0x00de, 0x00df, 0x00e0, 0x00e1, 0x00e2, 0x00e3, 0x00e4, 0x00e5,
	0x00e6, 0x00e7, 0x00e8, 0x00e9, 0x00ea, 0x00eb, 0x00f4, 0x00f3,
	0x00f2, 0x00f1, 0x00f0, 0x00ef, 0x00ee, 0x00ed, 0x00ec,
};

static u32 func0f1a25c0(s32 index);
static u32 ciGetStageFlagByDeviceIndex(u32 deviceindex);

bool ciIsTourDone(void)
{
	return gamefileHasFlag(GAMEFILEFLAG_CI_TOUR_DONE);
}

u8 ciGetFiringRangeScore(s32 weaponindex)
{
	// Data at firingrangescores is a u8 array where each score uses 2 bits

	return (g_GameFile.firingrangescores[weaponindex >> 2] >> (weaponindex % 4) * 2) & 3;
}

static void frSaveScoreIfBest(s32 weaponindex, s32 difficulty)
{
	if (ciGetFiringRangeScore(weaponindex) < difficulty) {
		u32 byteindex = weaponindex >> 2;
		u32 shiftamount = (weaponindex % 4) * 2;
		u32 value = g_GameFile.firingrangescores[byteindex];
		u32 mask = (1 << shiftamount) + (1 << (shiftamount + 1));

		value &= 255 - mask;
		value += (difficulty << shiftamount) & mask;

		g_GameFile.firingrangescores[byteindex] = value;
	}
}

u8 frIsWeaponFound(s32 weaponnum)
{
	u32 byteindex;

	if (weaponnum <= WEAPON_UNARMED) {
		return true;
	}

	if (weaponnum < (s32)sizeof(g_GameFile.weaponsfound) * 8) {
		byteindex = weaponnum >> 3;
		return g_GameFile.weaponsfound[byteindex] & (1 << (weaponnum % 8));
	}

	return false;
}

void frSetWeaponFound(s32 weaponnum)
{
	if (weaponnum < (s32)sizeof(g_GameFile.weaponsfound) * 8) {
		u32 byteindex = weaponnum >> 3;
		u32 value = g_GameFile.weaponsfound[byteindex];

		value |= (1 << (weaponnum % 8));

		g_GameFile.weaponsfound[byteindex] = value;
	}
}

static s32 ciIsStageComplete(s32 stageindex)
{
	return g_GameFile.besttimes[stageindex][0]
		|| g_GameFile.besttimes[stageindex][1]
		|| g_GameFile.besttimes[stageindex][2];
}

bool func0f19cbcc(s32 weapon)
{
	if (weapon <= 0 || weapon == WEAPON_PSYCHOSISGUN) {
		return false;
	}

	if (weapon == WEAPON_XRAYSCANNER && ciIsStageComplete(SOLOSTAGEINDEX_INFILTRATION)) {
		return true;
	}

	if (weapon == WEAPON_CLOAKINGDEVICE && ciIsStageComplete(SOLOSTAGEINDEX_CHICAGO)) {
		return true;
	}

	return frIsWeaponFound(weapon);
}

static bool frIsWeaponAvailable(s32 weapon)
{
	if (weapon < WEAPON_FALCON2 || weapon > WEAPON_REMOTEMINE
			|| weapon == WEAPON_PSYCHOSISGUN
			|| weapon == WEAPON_COMBATBOOST
			|| weapon == WEAPON_NBOMB) {
		return false;
	}

	if (weapon == WEAPON_FALCON2 || weapon == WEAPON_CMP150) {
		return true;
	}

	return frIsWeaponFound(weapon);
}

u32 frGetWeaponIndexByWeapon(u32 weaponnum)
{
	switch (weaponnum) {
	case WEAPON_FALCON2:          return 0;
	case WEAPON_FALCON2_SCOPE:    return 1;
	case WEAPON_FALCON2_SILENCER: return 2;
	case WEAPON_MAGSEC4:          return 3;
	case WEAPON_MAULER:           return 4;
	case WEAPON_PHOENIX:          return 5;
	case WEAPON_DY357MAGNUM:      return 6;
	case WEAPON_DY357LX:          return 7;
	case WEAPON_CMP150:           return 8;
	case WEAPON_CYCLONE:          return 9;
	case WEAPON_CALLISTO:         return 10;
	case WEAPON_RCP120:           return 11;
	case WEAPON_LAPTOPGUN:        return 12;
	case WEAPON_DRAGON:           return 13;
	case WEAPON_K7AVENGER:        return 14;
	case WEAPON_AR34:             return 15;
	case WEAPON_SUPERDRAGON:      return 16;
	case WEAPON_SHOTGUN:          return 17;
	case WEAPON_SNIPERRIFLE:      return 18;
	case WEAPON_FARSIGHT:         return 19;
	case WEAPON_CROSSBOW:         return 20;
	case WEAPON_TRANQUILIZER:     return 21;
	case WEAPON_REAPER:           return 22;
	case WEAPON_DEVASTATOR:       return 23;
	case WEAPON_ROCKETLAUNCHER:   return 24;
	case WEAPON_SLAYER:           return 25;
	case WEAPON_COMBATKNIFE:      return 26;
	case WEAPON_LASER:            return 27;
	case WEAPON_GRENADE:          return 28;
	case WEAPON_TIMEDMINE:        return 29;
	case WEAPON_PROXIMITYMINE:    return 30;
	case WEAPON_REMOTEMINE:       return 31;
	}

	return 0;
}

static u32 frGetWeaponScriptIndex(u32 weaponnum)
{
	switch (weaponnum) {
	case WEAPON_FALCON2:          return 1;
	case WEAPON_FALCON2_SCOPE:    return 2;
	case WEAPON_FALCON2_SILENCER: return 3;
	case WEAPON_MAGSEC4:          return 4;
	case WEAPON_MAULER:           return 5;
	case WEAPON_PHOENIX:          return 6;
	case WEAPON_DY357MAGNUM:      return 7;
	case WEAPON_DY357LX:          return 8;
	case WEAPON_CMP150:           return 9;
	case WEAPON_CYCLONE:          return 10;
	case WEAPON_CALLISTO:         return 11;
	case WEAPON_RCP120:           return 12;
	case WEAPON_LAPTOPGUN:        return 13;
	case WEAPON_DRAGON:           return 14;
	case WEAPON_K7AVENGER:        return 15;
	case WEAPON_AR34:             return 16;
	case WEAPON_SUPERDRAGON:      return 17;
	case WEAPON_SHOTGUN:          return 18;
	case WEAPON_SNIPERRIFLE:      return 19;
	case WEAPON_FARSIGHT:         return 20;
	case WEAPON_CROSSBOW:         return 21;
	case WEAPON_TRANQUILIZER:     return 22;
	case WEAPON_REAPER:           return 23;
	case WEAPON_DEVASTATOR:       return 24;
	case WEAPON_ROCKETLAUNCHER:   return 25;
	case WEAPON_SLAYER:           return 26;
	case WEAPON_COMBATKNIFE:      return 27;
	case WEAPON_LASER:            return 28;
	case WEAPON_GRENADE:          return 29;
	case WEAPON_TIMEDMINE:        return 31;
	case WEAPON_PROXIMITYMINE:    return 32;
	case WEAPON_REMOTEMINE:       return 33;
	}

	return 0;
}

s32 frIsClassicWeaponUnlocked(u32 weapon)
{
	switch (weapon) {
	case WEAPON_PP9I:
		return ciGetFiringRangeScore(0) == 3
			&& ciGetFiringRangeScore(1) == 3
			&& ciGetFiringRangeScore(2) == 3;
	case WEAPON_CC13:
		return ciGetFiringRangeScore(3) == 3
			&& ciGetFiringRangeScore(4) == 3
			&& ciGetFiringRangeScore(5) == 3
			&& ciGetFiringRangeScore(6) == 3
			&& ciGetFiringRangeScore(7) == 3;
	case WEAPON_KL01313:
		return ciGetFiringRangeScore(8) == 3
			&& ciGetFiringRangeScore(9) == 3
			&& ciGetFiringRangeScore(10) == 3
			&& ciGetFiringRangeScore(11) == 3;
	case WEAPON_KF7SPECIAL:
		return ciGetFiringRangeScore(12) == 3
			&& ciGetFiringRangeScore(13) == 3
			&& ciGetFiringRangeScore(14) == 3
			&& ciGetFiringRangeScore(15) == 3
			&& ciGetFiringRangeScore(16) == 3;
	case WEAPON_ZZT:
		return ciGetFiringRangeScore(17) == 3
			&& ciGetFiringRangeScore(18) == 3
			&& ciGetFiringRangeScore(24) == 3
			&& ciGetFiringRangeScore(25) == 3;
	case WEAPON_DMC:
		return ciGetFiringRangeScore(29) == 3
			&& ciGetFiringRangeScore(30) == 3
			&& ciGetFiringRangeScore(31) == 3;
	case WEAPON_AR53:
		return ciGetFiringRangeScore(19) == 3
			&& ciGetFiringRangeScore(20) == 3
			&& ciGetFiringRangeScore(26) == 3
			&& ciGetFiringRangeScore(28) == 3;
	case WEAPON_RCP45:
		return ciGetFiringRangeScore(21) == 3
			&& ciGetFiringRangeScore(22) == 3
			&& ciGetFiringRangeScore(23) == 3;
	}

	return false;
}

s32 frGetSlot(void)
{
	return g_FrData.slot;
}

void frSetSlot(s32 slot)
{
	g_FrData.slot = slot;
}

u32 frGetWeaponBySlot(s32 slot)
{
	s32 index = -1;
	s32 weapon;

	for (weapon = WEAPON_NONE; weapon <= WEAPON_HORIZONSCANNER; weapon++) {
		if (frIsWeaponAvailable(weapon)) {
			index++;
		}

		if (slot == index) {
			return weapon;
		}
	}

	return WEAPON_UNARMED;
}

s32 frGetNumWeaponsAvailable(void)
{
	s32 count = 0;
	s32 i;

	for (i = WEAPON_UNARMED; i <= WEAPON_HORIZONSCANNER; i++) {
		if (frIsWeaponAvailable(i)) {
			count++;
		}
	}

	return count;
}

static void frInitLighting(void)
{
	if (g_FrData.donelighting == false) {
		s32 roomnum;

		for (roomnum = 7; roomnum < 10; roomnum++) {
			roomSetLighting(roomnum, LIGHTOP_3, 50, 100, TICKS(32));
		}

		roomSetLighting(ROOM_DISH_FIRINGRANGE, LIGHTOP_3, 25, 100, TICKS(32));

		g_FrData.donelighting = true;

		sndStart(var80095200, SFX_FR_LIGHTSON, NULL, -1, -1, -1, -1, -1);
	}

	chrSetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
}

static void frRestoreLighting(void)
{
	if (g_FrData.donelighting == true) {
		s32 roomnum;

		for (roomnum = 7; roomnum < 10; roomnum++) {
			roomSetLighting(roomnum, LIGHTOP_3, 100, 50, TICKS(8));
		}

		roomSetLighting(ROOM_DISH_FIRINGRANGE, LIGHTOP_3, 100, 25, TICKS(8));

		g_FrData.donelighting = false;

		sndStart(var80095200, SFX_FR_LIGHTSOFF, NULL, -1, -1, -1, -1, -1);
	}
}

void frReset(void)
{
	s32 i;

	g_FrScriptOffsets = NULL;

	g_FrDataLoaded = false;
	g_FrIsValidWeapon = false;
	g_FrRomData = NULL;

	g_FrData.helpscriptindex = 0;
	g_FrData.helpscriptoffset = 0;
	g_FrData.helpscriptenabled = false;
	g_FrData.helpscriptsleep = 0;

	g_FrData.menucountdown = 0;
	g_FrData.maxactivetargets = 0;

	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		g_FrData.targets[i].prop = NULL;
		g_FrData.targets[i].inuse = false;
	}

	g_FrNumSounds = 0;
}

static void *frLoadRomData(u32 len)
{
	g_FrRomData = mempAlloc(ALIGN16(len), MEMPOOL_STAGE);

	if (g_FrRomData) {
		return dmaExecWithAutoAlign(g_FrRomData, (u32)&_firingrangeSegmentRomStart, len);
	}

	return NULL;
}

void frSetDifficulty(s32 difficulty)
{
	if (difficulty < FRDIFFICULTY_BRONZE) {
		difficulty = FRDIFFICULTY_BRONZE;
	}

	if (difficulty > FRDIFFICULTY_GOLD) {
		difficulty = FRDIFFICULTY_GOLD;
	}

	g_FrData.difficulty = difficulty;
}

static void frInitDefaults(void)
{
	s32 i;
	struct pad *pad;

	g_FrNumSounds = 0;

	pad = &g_Pads[g_FrPads[0]];

	g_FrData.maxactivetargets = 0;
	g_FrData.goalscore = 0;
	g_FrData.timelimit = 200;
	g_FrData.ammolimit = 255;
	g_FrData.sdgrenadelimit = 255;
	g_FrData.goalaccuracy = 0;
	g_FrData.goaltargets = 255;
	g_FrData.speed = 1;

	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		g_FrData.targets[i].dstpos = pad->pos;

		g_FrData.targets[i].dstpos.z += 6.0f * i;

		g_FrData.targets[i].inuse = false;
		g_FrData.targets[i].rotateoncloak = false;
		g_FrData.targets[i].destroyed = false;
		g_FrData.targets[i].damage = 0;
		g_FrData.targets[i].scriptoffset = 0;

		g_FrData.targets[i].travelspeed = 0;
		g_FrData.targets[i].scriptsleep = SECSTOTIME60(255);
		g_FrData.targets[i].timeuntilrotate = 0;

		g_FrData.targets[i].rotating = false;
		g_FrData.targets[i].rotatespeed = 0;
		g_FrData.targets[i].angle = 0;
		g_FrData.targets[i].rotatetoangle = 0;
		g_FrData.targets[i].silent = 0;
		g_FrData.targets[i].donestopsound = false;
		g_FrData.targets[i].travelling = false;
		g_FrData.targets[i].invincibletimer = 0;
		g_FrData.targets[i].frpadnum = -1;

		wallhitsFreeByProp(g_FrData.targets[i].prop, 0);
		wallhitsFreeByProp(g_FrData.targets[i].prop, 1);
	}

	g_FrData.timetaken = TICKS(-240);
	g_FrData.score = 0;
	g_FrData.numtargets = 0;
	g_FrData.targetsdestroyed = 0;
	g_FrData.menucountdown = 0;
	g_FrData.padindexoffset = 0;
	g_FrData.feedbackzone = 0;
	g_FrData.feedbackttl = 0;
	g_FrData.failreason = 0;
	g_FrData.numshots = 0;
	g_FrData.numhitsring3 = 0;
	g_FrData.numhitsring2 = 0;
	g_FrData.numhitsring1 = 0;
	g_FrData.numhitsbullseye = 0;
	g_FrData.helpscriptindex = 0;
	g_FrData.helpscriptoffset = 0;
	g_FrData.helpscriptenabled = false;
	g_FrData.helpscriptsleep = 0;
	g_FrData.proxyendtimer = 0;
	g_FrData.donealarm = false;
	g_FrData.ammohasgrace = true;
	g_FrData.ammoextra = -1;
}

struct frdata *frGetData(void)
{
	return &g_FrData;
}

static u32 frResolveFrPad(u32 arg0)
{
	switch (arg0) {
	case 31: return random() % 9 + 4;  // 4 - 12
	case 32: return random() % 9 + 13; // 13 - 21
	case 33: return random() % 9 + 22; // 22 - 30
	case 34: return random() % 27 + 4; // 4 - 30
	}

	return g_FrData.padindexoffset + arg0;
}

static bool frIsDifficulty(u32 flags)
{
	if (g_FrData.difficulty == FRDIFFICULTY_BRONZE) {
		if ((flags & FRTARGETFLAG_BRONZE) == 0) {
			return false;
		}
	} else if (g_FrData.difficulty == FRDIFFICULTY_SILVER) {
		if ((flags & FRTARGETFLAG_SILVER) == 0) {
			return false;
		}
	} else if (g_FrData.difficulty == FRDIFFICULTY_GOLD) {
		if ((flags & FRTARGETFLAG_GOLD) == 0) {
			return false;
		}
	}

	return true;
}

static void frExecuteWeaponScript(s32 scriptindex)
{
	s32 offset = 0;

	if (scriptindex >= FRSCRIPTINDEX_WEAPONS && scriptindex < FRSCRIPTINDEX_TARGETS) {
		u8 *script = &g_FrRomData[g_FrScriptOffsets[scriptindex]];
		u8 mult = 1;
		u32 stack[5];
		s32 start;
		s32 capacity;
		s32 index;
		u8 *subscript;
		s32 i;
		s32 val;

		while (script[offset] != FRCMD_END) {
			switch (script[offset]) {
			case FRCMD_SETPADINDEXOFFSET:
				g_FrData.padindexoffset = script[offset + 1];
				offset += 2;
				break;
			case FRCMD_ADDTARGET:
				if (!frIsDifficulty(script[offset + 4])) {
					offset += 5;
					break;
				}
				if (g_FrData.numtargets < ARRAYCOUNT(g_FrData.targets)) {
					g_FrData.targets[g_FrData.numtargets].frpadindex = frResolveFrPad(script[offset + 1]);
					g_FrData.targets[g_FrData.numtargets].scriptindex = script[offset + 2];
					g_FrData.targets[g_FrData.numtargets].maxdamage = script[offset + 3];
					g_FrData.targets[g_FrData.numtargets].inuse = true;
					g_FrData.targets[g_FrData.numtargets].flags = script[offset + 4];

					if (g_FrData.targets[g_FrData.numtargets].flags & FRTARGETFLAG_ROTATEONCLOAK) {
						g_FrData.targets[g_FrData.numtargets].rotateoncloak = true;
					}

					if (g_FrData.targets[g_FrData.numtargets].flags & FRTARGETFLAG_ONEHITEXPLODE) {
						g_FrData.targets[g_FrData.numtargets].maxdamage = 1;
					}

					g_FrData.numtargets++;
				}
				offset += 5;
				break;
			case FRCMD_SETMAXACTIVETARGETS:
				g_FrData.maxactivetargets = script[g_FrData.difficulty + offset + 1];
				offset += 4;
				break;
			case FRCMD_SETSCOREMULTIPLIER:
				if (script[g_FrData.difficulty + offset + 1] > 0) {
					mult = script[g_FrData.difficulty + offset + 1];
				} else {
					mult = 1;
				}
				offset += 4;
				break;
			case FRCMD_SETGOALSCORE:
				g_FrData.goalscore = script[g_FrData.difficulty + offset + 1] * mult;
				offset += 4;
				break;
			case FRCMD_SETTIMELIMIT:
				g_FrData.timelimit = script[g_FrData.difficulty + offset + 1];
				if (g_FrData.timelimit == 255) {
					g_FrData.timelimit = 120;
				}
				offset += 4;
				break;
			case FRCMD_SETAMMOLIMIT:
				capacity = bgunGetCapacityByAmmotype(bgunGetAmmoTypeForWeapon(frGetWeaponBySlot(g_FrData.slot), 0));
				g_FrData.ammolimit = script[g_FrData.difficulty + offset + 1];

				if (g_FrData.ammolimit != 255) {
					if (g_FrData.ammolimit > capacity) {
						g_FrData.ammoextra = g_FrData.ammolimit - capacity;
					} else {
						g_FrData.ammoextra = 0;
					}
				}

				offset += 4;
				break;
			case FRCMD_SETGRENADELIMIT:
				capacity = bgunGetCapacityByAmmotype(AMMOTYPE_DEVASTATOR);
				g_FrData.sdgrenadelimit = script[g_FrData.difficulty + offset + 1];

				if (g_FrData.sdgrenadelimit != 255) {
					if (g_FrData.sdgrenadelimit > capacity) {
						g_FrData.sdgrenadeextra = g_FrData.sdgrenadelimit - capacity;
					} else {
						g_FrData.sdgrenadeextra = 0;
					}
				}

				offset += 4;
				break;
			case FRCMD_SETEXTRASPEED:
				g_FrData.speed = script[g_FrData.difficulty + offset + 1] * 0.1f + 1.0f;
				offset += 4;
				break;
			case FRCMD_SETGOALACCURACY:
				g_FrData.goalaccuracy = script[g_FrData.difficulty + offset + 1];
				offset += 4;
				break;
			case FRCMD_SETGOALTARGETS:
				g_FrData.goaltargets = script[g_FrData.difficulty + offset + 1];
				offset += 4;
				break;
			case FRCMD_SETHELPSCRIPT:
				g_FrData.helpscriptindex = script[offset + 1];
				g_FrData.helpscriptenabled = true;
				index = FRSCRIPTINDEX_HELP + g_FrData.helpscriptindex;
				if (&g_FrRomData[g_FrScriptOffsets[index]]);
				subscript = &g_FrRomData[g_FrScriptOffsets[index]];
				offset += 2;

				if (g_FrData.difficulty == FRDIFFICULTY_BRONZE) {
					start = FRCMD_IFBRONZE;
				} else if (g_FrData.difficulty == FRDIFFICULTY_SILVER) {
					start = FRCMD_IFSILVER;
				} else if (g_FrData.difficulty == FRDIFFICULTY_GOLD) {
					start = FRCMD_IFGOLD;
				}

				g_FrData.helpscriptoffset = 0;
				i = 0;

				while (1) {
					g_FrData.helpscriptoffset++;

					if (subscript[i] == start) {
						i++;

						val = subscript[i];

						if (val >= FRCMD_IFBRONZE) {
							g_FrData.helpscriptoffset++;
							val = subscript[i + 1];
						}

						if (val >= FRCMD_IFBRONZE) {
							g_FrData.helpscriptoffset++;
						}
						break;
					}

					i++;
				}
				break;
			}
		}
	}
}

static void frSetTargetProps(void)
{
	s32 i;
	static u32 targets[] = {
		0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x11,
		0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a,
	};

	for (i = 0; i < ARRAYCOUNT(targets); i++) {
		struct defaultobj *obj = g_ObjsByTag[targets[i]];

		if (obj) {
			g_FrData.targets[i].prop = obj->prop;
			obj->flags2 |= OBJFLAG2_INVISIBLE;
		}
	}
}

s32 g_FrWeaponNum = WEAPON_UNARMED;

static bool frTargetIsAtScriptStart(s32 targetnum)
{
	return g_FrData.targets[targetnum].scriptoffset == 0;
}

/**
 * 0 => "FIRING\n Press Z Button to fire gun.\n"
 * 1 => "AUTO RELOAD\n Release Z Button when out of ammo.\n"
 * 2 => "MANUAL RELOAD\n Press B Button to reload early if magazine not full.\n"
 * 3 => "Aiming: Hold down R Button to enter Aim mode.\n"
 * 4 => "Use Control Stick to move aiming sight.\n"
 * 5 => "AUTO FIRE\n Hold Z Button to repeatedly fire automatically.\n"
 * 6 => "ALTER AIM\n Press Up C Button or Down C Button to move sight up/down.\n"
 * 7 => "ZOOM\n Hold R Button to enter Zoom mode.\n"
 * 8 => "FAST FIRE\n Press Z Button quickly to fire faster.\n"
 */
static char *frGetInstructionalText(u32 index)
{
	u16 textid = (u16)(g_FrRomData[index * 2] << 8) | g_FrRomData[index * 2 + 1];

	return langGet(textid);
}

static void frExecuteHelpScript(void)
{
	if (!g_FrData.helpscriptenabled || g_Vars.lvupdate240 == 0) {
		return;
	}

	if (g_FrData.helpscriptsleep == 0) {
		s32 index = FRSCRIPTINDEX_HELP + g_FrData.helpscriptindex;
		u8 *script = &g_FrRomData[g_FrScriptOffsets[index]];
		u32 offset = g_FrData.helpscriptoffset;

		switch (script[offset]) {
		case FRCMD_END:
		case FRCMD_IFBRONZE:
		case FRCMD_IFSILVER:
		case FRCMD_IFGOLD:
			g_FrData.helpscriptenabled = false;
			break;
		case FRCMD_HUDMSG:
			hudmsgCreate(frGetInstructionalText(script[offset + 1]), HUDMSGTYPE_TRAINING);
			g_FrData.helpscriptoffset += 2;
			break;
		case FRCMD_HELPWAITSECONDS:
#if PAL
			g_FrData.helpscriptsleep = script[offset + 1] * 50;
#else
			g_FrData.helpscriptsleep = SECSTOTIME60(script[offset + 1]);
#endif
			g_FrData.helpscriptoffset += 2;
			break;
		case FRCMD_WAITUNTILSHOOT:
			if (g_FrData.numshots) {
				g_FrData.helpscriptoffset++;
			}
			break;
		}
	} else {
		g_FrData.helpscriptsleep -= g_Vars.lvupdate60;

		if (g_FrData.helpscriptsleep <= 0) {
			g_FrData.helpscriptsleep = 0;
		}
	}
}

static bool frExecuteTargetScript(s32 targetnum)
{
	if (g_FrData.targets[targetnum].inuse) {
		s32 index = FRSCRIPTINDEX_TARGETS + g_FrData.targets[targetnum].scriptindex;
		u8 *script = &g_FrRomData[g_FrScriptOffsets[index]];
		s32 offset = g_FrData.targets[targetnum].scriptoffset;
		s32 frpadnum;

		switch (script[offset]) {
		case FRCMD_END:
			g_FrData.targets[targetnum].scriptenabled = true;
			g_FrData.targets[targetnum].scriptsleep = 255 * 60;
			return true;
		case FRCMD_GOTOPAD:
			frpadnum = frResolveFrPad(script[offset + 1]);

			if (frpadnum == g_FrData.targets[targetnum].frpadnum) {
				g_FrData.targets[targetnum].scriptoffset += 4;
				return false;
			}

			g_FrData.targets[targetnum].frpadnum = frpadnum;

			g_FrData.targets[targetnum].dstpos = g_Pads[g_FrPads[frpadnum]].pos;

			g_FrData.targets[targetnum].dstpos.z += 6.0f * targetnum;

			if (script[offset + 2] == 0xff) {
				g_FrData.targets[targetnum].travelspeed = -1;
				g_FrData.targets[targetnum].travelling = true;
			} else {
				if (g_FrNumSounds < 3) {
					g_FrNumSounds++;
					propsnd0f0939f8(NULL, g_FrData.targets[targetnum].prop, SFX_FR_CONVEYER, -1,
							-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
				}

				g_FrData.targets[targetnum].travelspeed = script[offset + 2] / 60.0f * g_FrData.speed;
				g_FrData.targets[targetnum].travelling = true;
			}

			g_FrData.targets[targetnum].scriptsleep = script[offset + 3] * TICKS(60);
			g_FrData.targets[targetnum].donestopsound = false;
			g_FrData.targets[targetnum].scriptoffset += 4;
			return true;
		case FRCMD_RESTART:
			g_FrData.targets[targetnum].scriptoffset = 0;
			return true;
		case FRCMD_WAITSECONDS:
			g_FrData.targets[targetnum].scriptenabled = true;
			g_FrData.targets[targetnum].scriptsleep = script[offset + 1] * TICKS(60);
			g_FrData.targets[targetnum].scriptoffset += 2;
			return true;
		case FRCMD_ROTATE:
			if (g_FrData.targets[targetnum].rotateoncloak == false) {
				f32 angles[4];
				angles[0] = DEG2RAD(-90);
				angles[1] = DEG2RAD(-180);
				angles[2] = DEG2RAD(90);
				angles[3] = DEG2RAD(180);

				g_FrData.targets[targetnum].rotatetoangle = g_FrData.targets[targetnum].angle + angles[script[offset + 1]];
				g_FrData.targets[targetnum].rotatespeed = angles[script[offset + 1]] / (script[offset + 2] * 15);
				g_FrData.targets[targetnum].rotating = true;
				g_FrData.targets[targetnum].scriptenabled = false;
			}

			if (1);
			g_FrData.targets[targetnum].scriptoffset += 3;
			return true;
		}
	}

	return true;
}

static void frHideAllTargets(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		struct prop *prop = g_FrData.targets[i].prop;
		struct defaultobj *target = prop->obj;

		target->flags2 |= OBJFLAG2_INVISIBLE;

		func0f0926bc(prop, 1, 0xffff);
	}
}

static void frInitTargets(void)
{
	s32 count = 0;
	s32 i;
	struct prop *prop;
	struct defaultobj *obj;
	struct pad pad;
	struct coord pos;
	Mtxf sp144;
	f32 sp108[3][3];

	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		prop = g_FrData.targets[i].prop;

		if (prop) {
			obj = prop->obj;

			objFree(obj, false, true);

			obj->damage = 0;
			prop->timetoregen = 0;

			if (g_FrData.targets[i].inuse) {
				g_FrData.targets[i].scriptenabled = false;
				g_FrData.targets[i].destroyed = false;

				if (count < g_FrData.maxactivetargets) {
					obj->flags2 &= ~OBJFLAG2_INVISIBLE;
					g_FrData.targets[i].active = true;
				} else {
					obj->flags2 |= OBJFLAG2_INVISIBLE;
					g_FrData.targets[i].active = false;
				}

				pos.f[0] = g_Pads[g_FrPads[g_FrData.targets[i].frpadindex]].pos.f[0];
				pos.f[1] = g_Pads[g_FrPads[g_FrData.targets[i].frpadindex]].pos.f[1];
				pos.f[2] = g_Pads[g_FrPads[g_FrData.targets[i].frpadindex]].pos.f[2] + 6.0f * i;

				frExecuteTargetScript(i);

				if (g_FrData.targets[i].travelspeed == -1) {
					pos = g_FrData.targets[i].dstpos;
				}

				count++;
			} else {
				obj->flags2 |= OBJFLAG2_INVISIBLE;
			}

			if (obj->flags2 & OBJFLAG2_INVISIBLE) {
				pos.x = 0.0f;
				pos.y = 5000.0f;
				pos.z = 6.0f * i;
			}

			if (g_FrData.targets[i].flags & FRTARGETFLAG_SPAWNFACINGAWAY) {
				mtx4LoadYRotation(0.0f, &sp144);
				g_FrData.targets[i].angle = M_PI;
			} else {
				mtx4LoadYRotation(M_PI, &sp144);
			}

			mtx00015f04(obj->model->scale, &sp144);
			mtx4ToMtx3(&sp144, sp108);
			mtx3Copy(sp108, obj->realrot);

			prop->pos = pos;

			func0f069c70(obj, true, false);
		}
	}
}

static void frCloseAndLockDoor(void)
{
	struct defaultobj *obj = g_ObjsByTag[0x91];

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *)obj;
		door->keyflags |= 0x40;
		doorsRequestMode(door, DOORMODE_CLOSING);
	}
}

static void frUnlockDoor(void)
{
	struct defaultobj *obj = g_ObjsByTag[0x91];

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *)obj;
		door->keyflags &= ~0x40;
	}
}

void frLoadData(void)
{
	if (!g_FrDataLoaded) {
		s32 len = (s32)&_firingrangeSegmentRomEnd - (s32)&_firingrangeSegmentRomStart;
		s32 index = 0;
		u32 i;
		u32 numscripts = 1;
		s32 size;

		if (index);

		g_FrDataLoaded = true;

		frLoadRomData(len);

		for (i = 0x12; i < len; i++) {
			if (g_FrRomData[i] == FRCMD_START) {
				numscripts++;
			}
		}

		size = numscripts * sizeof(*g_FrScriptOffsets);
		g_FrScriptOffsets = mempAlloc(ALIGN16(size), MEMPOOL_STAGE);

		if (numscripts < 0);

		if (g_FrScriptOffsets) {
			for (i = 0x12; i < len; i++) {
				if (g_FrRomData[i] == FRCMD_START) {
					g_FrScriptOffsets[index] = i + 1;
					index++;
				}
			}
		}

		frSetTargetProps();

		g_FrData.slot = 0;
		g_FrData.difficulty = FRDIFFICULTY_BRONZE;
		g_FrData.donelighting = false;
	}
}

u32 frInitAmmo(s32 weaponnum)
{
	u32 scriptindex;
	u32 ammotype = bgunGetAmmoTypeForWeapon(weaponnum, 0);
	u32 capacity = bgunGetCapacityByAmmotype(ammotype);

	frInitDefaults();
	scriptindex = frGetWeaponScriptIndex(weaponnum);
	frExecuteWeaponScript(scriptindex);

	if (g_FrData.ammolimit == 255) {
		bgunSetAmmoQuantity(ammotype, capacity);
	} else {
		bgunSetAmmoQuantity(ammotype, g_FrData.ammolimit);
	}

	if (weaponnum == WEAPON_SUPERDRAGON) {
		if (g_FrData.sdgrenadelimit == 255) {
			bgunSetAmmoQuantity(AMMOTYPE_DEVASTATOR, capacity);
		} else {
			bgunSetAmmoQuantity(AMMOTYPE_DEVASTATOR, g_FrData.sdgrenadelimit);
		}
	}

	return scriptindex;
}

void frBeginSession(s32 weapon)
{
	s32 i;
	struct defaultobj *obj = g_ObjsByTag[0x7f]; // computer

	if (obj) {
		obj->flags |= OBJFLAG_CANNOT_ACTIVATE;
	}

	frCloseAndLockDoor();

	for (i = 0; i < 2; i++) {
		if (g_Vars.currentplayer->gunctrl.ammotypes[i] >= 0) {
			g_Vars.currentplayer->hands[0].loadedammo[i] = 0;
			g_Vars.currentplayer->hands[1].loadedammo[i] = 0;
		}
	}

	g_FrIsValidWeapon = frInitAmmo(weapon) == 0 ? false : true;
	frInitTargets();
	bgunSetPassiveMode(false);
}

char *frGetWeaponDescription(void)
{
	u32 weapon = frGetWeaponBySlot(g_FrData.slot);

	switch (weapon) {
	case WEAPON_FALCON2:          return langGet(L_MISC_377);
	case WEAPON_FALCON2_SCOPE:    return langGet(L_MISC_378);
	case WEAPON_FALCON2_SILENCER: return langGet(L_MISC_379);
	case WEAPON_MAGSEC4:          return langGet(L_MISC_380);
	case WEAPON_MAULER:           return langGet(L_MISC_381);
	case WEAPON_PHOENIX:          return langGet(L_MISC_382);
	case WEAPON_DY357MAGNUM:      return langGet(L_MISC_383);
	case WEAPON_DY357LX:          return langGet(L_MISC_384);
	case WEAPON_CMP150:           return langGet(L_MISC_385);
	case WEAPON_CYCLONE:          return langGet(L_MISC_386);
	case WEAPON_CALLISTO:         return langGet(L_MISC_387);
	case WEAPON_RCP120:           return langGet(L_MISC_388);
	case WEAPON_LAPTOPGUN:        return langGet(L_MISC_389);
	case WEAPON_DRAGON:           return langGet(L_MISC_390);
	case WEAPON_K7AVENGER:        return langGet(L_MISC_391);
	case WEAPON_AR34:             return langGet(L_MISC_392);
	case WEAPON_SUPERDRAGON:      return langGet(L_MISC_393);
	case WEAPON_SHOTGUN:          return langGet(L_MISC_394);
	case WEAPON_SNIPERRIFLE:      return langGet(L_MISC_395);
	case WEAPON_FARSIGHT:         return langGet(L_MISC_396);
	case WEAPON_CROSSBOW:         return langGet(L_MISC_397);
	case WEAPON_TRANQUILIZER:     return langGet(L_MISC_398);
	case WEAPON_REAPER:           return langGet(L_MISC_399);
	case WEAPON_DEVASTATOR:       return langGet(L_MISC_400);
	case WEAPON_ROCKETLAUNCHER:   return langGet(L_MISC_401);
	case WEAPON_SLAYER:           return langGet(L_MISC_402);
	case WEAPON_COMBATKNIFE:      return langGet(L_MISC_403);
	case WEAPON_LASER:            return langGet(L_MISC_404);
	case WEAPON_GRENADE:          return langGet(L_MISC_405);
	case WEAPON_NBOMB:            return langGet(L_MISC_406);
	case WEAPON_TIMEDMINE:        return langGet(L_MISC_407);
	case WEAPON_PROXIMITYMINE:    return langGet(L_MISC_408);
	case WEAPON_REMOTEMINE:       return langGet(L_MISC_409);
	}

	return NULL;
}

void frEndSession(bool hidetargets)
{
	s32 i;
	s32 j;
	s16 propnums[256];
	s16 *propnumptr;
	s16 rooms[20];
	u32 stack1;
	s16 rooms2[10];
	u32 stack2;

	if (g_FrDataLoaded) {
		struct defaultobj *terminal = g_ObjsByTag[0x7f];

		if (terminal) {
			terminal->flags &= ~OBJFLAG_CANNOT_ACTIVATE;
		}

		frUnlockDoor();

		if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKET) {
			g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
		}

		bgunSetPassiveMode(true);

		g_FrIsValidWeapon = 0;

		frRestoreLighting();

		if (hidetargets) {
			frHideAllTargets();
		}

		if (g_ThrownLaptops[0].base.prop) {
			objFreePermanently(&g_ThrownLaptops[0].base, true);
		}

		roomsCopy(g_Vars.currentplayer->prop->rooms, rooms);

		for (i = 0; g_Vars.currentplayer->prop->rooms[i] != -1; i++) {
			roomGetNeighbours(g_Vars.currentplayer->prop->rooms[i], rooms2, 10);
			roomsAppend(rooms2, rooms, 20);
		}

		// Remove projectiles and throwables
		roomGetProps(rooms, propnums, 256);

		propnumptr = propnums;

		while (*propnumptr >= 0) {
			struct prop *prop = &g_Vars.props[*propnumptr];

			if (prop) {
				struct defaultobj *obj = prop->obj;

				if (prop->type == PROPTYPE_WEAPON) {
					if (obj->type == OBJTYPE_AUTOGUN) {
						objFreePermanently(obj, true);
					}

					if (obj->type == OBJTYPE_WEAPON) {
						struct weaponobj *weapon = (struct weaponobj *)obj;

						if (weapon->weaponnum == WEAPON_NBOMB
								|| weapon->weaponnum == WEAPON_BOLT
								|| weapon->weaponnum == WEAPON_COMBATKNIFE
								|| weapon->weaponnum == WEAPON_HOMINGROCKET
								|| weapon->weaponnum == WEAPON_GRENADE
								|| weapon->weaponnum == WEAPON_GRENADEROUND
								|| weapon->weaponnum == WEAPON_PROXIMITYMINE
								|| weapon->weaponnum == WEAPON_REMOTEMINE
								|| weapon->weaponnum == WEAPON_ROCKET
								|| weapon->weaponnum == WEAPON_TIMEDMINE
								|| weapon->weaponnum == WEAPON_SKROCKET
								|| (weapon->weaponnum == WEAPON_DRAGON && weapon->gunfunc == FUNC_SECONDARY)
								|| (weapon->weaponnum == WEAPON_LAPTOPGUN && weapon->gunfunc == FUNC_SECONDARY)) {
							objFreePermanently(obj, true);
						}
					}
				}
			}

			propnumptr++;
		}

		// Remove explosions
		for (i = 0; i < g_MaxExplosions; i++) {
			g_Explosions[i].age = 256;

			for (j = 0; j < 40; j++) {
				g_Explosions[i].parts[j].frame = 0;
			}
		}

		// Remove smoke
		for (i = 0; i < g_MaxSmokes; i++) {
			g_Smokes[i].age = 256;

			for (j = 0; j < 10; j++) {
				g_Smokes[i].parts[j].size = 0;
			}
		}
	}

	playerDisplayHealth();

	g_Vars.currentplayer->bondhealth = 1;
}

static bool frWasTooInaccurate(void)
{
	f32 sum = (g_FrData.numhitsring3 +
		+ g_FrData.numhitsbullseye
		+ g_FrData.numhitsring1
		+ g_FrData.numhitsring2) * 100.0f;

	if (g_FrData.numshots) {
		f32 accuracy = sum / g_FrData.numshots;

		if (accuracy < g_FrData.goalaccuracy) {
			return true;
		}
	}

	return false;
}

static void frSetFailReason(s32 failreason)
{
	frEndSession(false);

	g_FrData.failreason = frWasTooInaccurate() ? FRFAILREASON_INACCURATE : failreason;
	g_FrData.menutype = FRMENUTYPE_FAILED;
	g_FrData.menucountdown = TICKS(60);
}

static void frSetCompleted(void)
{
	frEndSession(false);

	if (frWasTooInaccurate()) {
		g_FrData.failreason = FRFAILREASON_INACCURATE;
		g_FrData.menutype = FRMENUTYPE_FAILED;
	} else {
		u32 frweaponindex = frGetWeaponIndexByWeapon(frGetWeaponBySlot(g_FrData.slot));
		frSaveScoreIfBest(frweaponindex, g_FrData.difficulty + 1);
		g_FrData.menutype = FRMENUTYPE_COMPLETED;
	}

	g_FrData.menucountdown = TICKS(60);
}

bool frIsTargetOneHitExplodable(struct prop *prop)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		if (g_FrData.targets[i].inuse
				&& g_FrData.targets[i].destroyed == false
				&& g_FrData.targets[i].active
				&& prop == g_FrData.targets[i].prop) {
			if (g_FrData.targets[i].flags & FRTARGETFLAG_ONEHITEXPLODE) {
				return true;
			}

			return false;
		}
	}

	return false;
}

static f32 frGetTargetAngleToPos(struct coord *targetpos, f32 targetangle, struct coord *pos)
{
	f32 xdiff = targetpos->x - pos->x;
	f32 zdiff = targetpos->z - pos->z;
	f32 directangle = atan2f(xdiff, zdiff);
	f32 relativeangle = directangle - targetangle;

	if (directangle < targetangle) {
		relativeangle += M_BADTAU;
	}

	return relativeangle;
}

bool frIsTargetFacingPos(struct prop *prop, struct coord *pos)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		if (prop == g_FrData.targets[i].prop) {
			f32 angle;

			if (g_FrData.targets[i].destroyed) {
				return false;
			}

			angle = frGetTargetAngleToPos(&prop->pos, g_FrData.targets[i].angle, pos);

			//if (angle > DEG2RAD(90) && angle < DEG2RAD(270)) {
			if (angle > 1.5707963705063f && angle < 4.7116389274597f) {
				return false;
			}

			return true;
		}
	}

	return true;
}

struct prop *frChooseAutogunTarget(struct coord *autogunpos)
{
	f32 closestdist = 0x20000000;
	s32 facingtargets[ARRAYCOUNT(g_FrData.targets)];
	s32 len = 0;
	struct prop *closesttarget = NULL;
	s32 i;

	// Make list of targets which are facing the laptop gun
	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		if (g_FrData.targets[i].inuse
				&& g_FrData.targets[i].destroyed == false
				&& g_FrData.targets[i].active) {
			f32 angle = frGetTargetAngleToPos(&g_FrData.targets[i].prop->pos, g_FrData.targets[i].angle, autogunpos);

			if (!(angle > 1.5707963705063f && angle < 4.7116389274597f)) {
				facingtargets[len++] = i;
			}
		}
	}

	// Determine which of the facing targets is closest
	for (i = 0; i < len; i++) {
		struct prop *prop = g_FrData.targets[facingtargets[i]].prop;
		f32 xdiff = prop->pos.f[0] - autogunpos->f[0];
		f32 ydiff = prop->pos.f[1] - autogunpos->f[1];
		f32 zdiff = prop->pos.f[2] - autogunpos->f[2];
		f32 dist = xdiff * xdiff + ydiff * ydiff + zdiff * zdiff;

		if (dist < closestdist) {
			closestdist = dist;
			closesttarget = prop;
		}
	}

	if (facingtargets);

	return closesttarget;
}

static bool frIsAmmoWasted(void)
{
	s32 weaponnum = frGetWeaponBySlot(g_FrData.slot);
	s32 i;
	s32 priammotype = bgunGetAmmoTypeForWeapon(weaponnum, 0);
	s32 secammotype = bgunGetAmmoTypeForWeapon(weaponnum, 1);
	struct hand *hand0 = &g_Vars.currentplayer->hands[0];
	struct hand *hand1 = &g_Vars.currentplayer->hands[1];
	s32 ammoloaded[2];
	s32 ammototal[2];
	s16 *propnumptr;
	s16 propnums[258];
	s16 rooms20[22];
	s16 rooms10[12];
	u32 stack[4];
	s32 ammotype;
	struct hand *hand;
	struct prop *prop;
	struct prop *child;

	// Laser has unlimited ammo
	if (weaponnum == WEAPON_LASER) {
		return false;
	}

	// Check if player has ammo
	ammoloaded[0] = hand0->loadedammo[0] + hand1->loadedammo[0];
	ammoloaded[1] = hand0->loadedammo[1] + hand1->loadedammo[1];
	ammototal[0] = bgunGetReservedAmmoCount(priammotype) + ammoloaded[0];
	ammototal[1] = bgunGetReservedAmmoCount(secammotype) + ammoloaded[1];

	if (ammototal[0] <= 0 && ammototal[1] <= 0) {
		// Don't do any further checks if this is the first frame where we've
		// gotten this far. I'm guessing this fixes a frame perfect bug, however
		// testing with this check removed doesn't cause any unusual behaviour.
		if (g_FrData.ammohasgrace) {
			g_FrData.ammohasgrace = false;
			return false;
		}

		// Check if there are any explosions
		for (i = 0; i != 6; i++) {
			if (g_Explosions[i].prop) {
				return false;
			}
		}

		// Check projectiles
		if (weaponnum == WEAPON_ROCKETLAUNCHER
				|| weaponnum == WEAPON_SLAYER
				|| weaponnum == WEAPON_DEVASTATOR
				|| weaponnum == WEAPON_SUPERDRAGON
				|| weaponnum == WEAPON_COMBATKNIFE
				|| weaponnum == WEAPON_CROSSBOW
				|| weaponnum == WEAPON_GRENADE
				|| weaponnum == WEAPON_NBOMB
				|| weaponnum == WEAPON_TIMEDMINE
				|| weaponnum == WEAPON_PROXIMITYMINE
				|| weaponnum == WEAPON_REMOTEMINE) {
			roomsCopy(g_Vars.currentplayer->prop->rooms, rooms20);

			for (i = 0; g_Vars.currentplayer->prop->rooms[i] != -1; i++) {
				roomGetNeighbours(g_Vars.currentplayer->prop->rooms[i], rooms10, 10);
				roomsAppend(rooms10, rooms20, 20);
			}

			roomGetProps(rooms20, propnums, 256);
			propnumptr = propnums;

			while (*propnumptr >= 0) {
				prop = &g_Vars.props[*propnumptr];
				child = prop->child;

				if (child && child->type == PROPTYPE_WEAPON) {
					if (child->weapon->weaponnum == WEAPON_TIMEDMINE
							|| child->weapon->weaponnum == WEAPON_REMOTEMINE
							|| child->weapon->weaponnum == WEAPON_PROXIMITYMINE
							|| child->weapon->weaponnum == WEAPON_GRENADEROUND) {
						return false;
					}
				}

				if (prop->type == PROPTYPE_WEAPON) {
					if (prop->weapon->weaponnum == WEAPON_ROCKET
							|| prop->weapon->weaponnum == WEAPON_HOMINGROCKET
							|| prop->weapon->weaponnum == WEAPON_GRENADE
							|| prop->weapon->weaponnum == WEAPON_GRENADEROUND) {
						return false;
					}

					if (prop->weapon->weaponnum == WEAPON_BOLT
							|| prop->weapon->weaponnum == WEAPON_COMBATKNIFE) {
						if (prop->obj->hidden & OBJHFLAG_PROJECTILE) {
							return false;
						}
					} else if (prop->weapon->weaponnum == WEAPON_TIMEDMINE
							|| prop->weapon->weaponnum == WEAPON_REMOTEMINE) {
						return false;
					} else if (prop->weapon->weaponnum == WEAPON_PROXIMITYMINE) {
						if (g_FrData.proxyendtimer == -255) {
							return false;
						}

						if (g_FrData.proxyendtimer == 0) {
							// Initial state - set the timer to 5 seconds if player is now out of mines
							ammotype = bgunGetAmmoTypeForWeapon(weaponnum, 0);
							hand = &g_Vars.currentplayer->hands[HAND_RIGHT];

							if (bgunGetReservedAmmoCount(ammotype) + hand->loadedammo[0] == 0) {
								g_FrData.proxyendtimer = TICKS(300);
							}

							return false;
						}

						g_FrData.proxyendtimer -= g_Vars.lvupdate60;

						if (g_FrData.proxyendtimer <= 0) {
							// Timer has just hit zero - remove all proxy items
							for (i = 0; i < ARRAYCOUNT(g_Proxies); i++) {
								if (g_Proxies[i]) {
									g_Proxies[i]->timer240 = 0;
								}
							}

							g_FrData.proxyendtimer = -255;
							return true;
						}

						return false;
					}
				}

				propnumptr++;
			}
		}

		return true;
	}

	return false;
}

void frTick(void)
{
	s32 ammotype;
	s32 capacity;
	s32 weaponnum;
	struct coord diff;
	struct coord newpos;
	u8 weaponnum2;
	struct prop *prop;
	struct defaultobj *obj;
	struct defaultobj *obj2;
	s32 invincible;
	s32 i;
	s32 j;
	f32 dist;
	u32 stack;
	struct inventory_ammo *ammo;
	u8 exploding;
	bool oldside;
	struct modelrodata_bbox *bbox;
	s32 tmp;
	f32 mult;
	bool newside;
	struct chrdata *chr;
	bool cloaked;
	f32 toangle;
	f32 speed;
	Mtxf spbc;
	f32 sp98[3][3];

	if (g_FrIsValidWeapon
			&& g_Vars.currentplayer->gunctrl.unk1583_04 == 0
			&& invHasSingleWeaponIncAllGuns(frGetWeaponBySlot(g_FrData.slot))) {
		bgunEquipWeapon(frGetWeaponBySlot(g_FrData.slot));
	}

	// Handle the menu countdown
	if (g_FrData.menucountdown != 0) {
		g_FrData.menucountdown -= g_Vars.lvupdate60;

		// Prevent showing the menu until gun is put away
		if (g_FrData.menucountdown <= 0) {
			if ((g_FrData.menutype == FRMENUTYPE_FAILED || g_FrData.menutype == FRMENUTYPE_COMPLETED)
					&& g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponnum != WEAPON_UNARMED) {
				g_FrData.menucountdown = 1;
			}
		}

		if (g_FrData.menucountdown <= 0) {
			g_FrData.menucountdown = 0;

			for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
				if (g_FrData.targets[i].prop) {
					func0f0926bc(g_FrData.targets[i].prop, 1, 0xffff);
				}
			}

			switch (g_FrData.menutype) {
			case FRMENUTYPE_WEAPONLIST:
				func0f0f85e0(ciGetFrWeaponListMenuDialog(), MENUROOT_TRAINING);
				break;
			case FRMENUTYPE_DETAILS:
				func0f0f85e0(&g_FrTrainingInfoPreGameMenuDialog, MENUROOT_TRAINING);
				break;
			case FRMENUTYPE_FAILED:
				sndStart(var80095200, SFX_TRAINING_FAIL, NULL, -1, -1, -1, -1, -1);
				func0f0f85e0(&g_FrFailedMenuDialog, MENUROOT_TRAINING);
				break;
			case FRMENUTYPE_COMPLETED:
				sndStart(var80095200, SFX_TRAINING_COMPLETE, NULL, -1, -1, -1, -1, -1);
				func0f0f85e0(&g_FrCompletedMenuDialog, MENUROOT_TRAINING);
				filemgrSaveOrLoad(&g_GameFileGuid, FILEOP_SAVE_GAME_000, 0);
				break;
			}
		}
		return;
	}

	// End the session if the player slipped through the door before it closed
	if (g_Vars.currentplayer->prop->rooms[0] != ROOM_DISH_FIRINGRANGE) {
		if (g_FrIsValidWeapon) {
			for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
				if (g_FrData.targets[i].inuse
						&& g_FrData.targets[i].destroyed == false
						&& g_FrData.targets[i].silent == false
						&& g_FrData.targets[i].travelling) {
					g_FrData.targets[i].silent = true;
					func0f0926bc(g_FrData.targets[i].prop, 1, 0xffff);
				}
			}

			g_Vars.currentplayer->training = false;
			frEndSession(true);
			chrUnsetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
		}
		return;
	}

	if (!g_FrIsValidWeapon) {
		return;
	}

	if (g_Vars.currentplayer->isdead) {
		frEndSession(false);
	}

	// If paused, stop any target sounds
	if (g_Vars.lvupdate240 == 0) {
		for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
			if (g_FrData.targets[i].inuse
					&& g_FrData.targets[i].destroyed == false
					&& g_FrData.targets[i].silent == false
					&& g_FrData.targets[i].travelling) {
				g_FrData.targets[i].silent = true;
				func0f0926bc(g_FrData.targets[i].prop, 1, 0xffff);
			}
		}
		return;
	}

	g_Vars.currentplayer->training = true;
	frExecuteHelpScript();

	// Top up the player's ammo if the config defined more ammo than the
	// weapon allows, or if it defined unlimited ammo
	if (g_FrData.numshotssincetopup != 0) {
		weaponnum = frGetWeaponBySlot(g_FrData.slot);
		ammotype = bgunGetAmmoTypeForWeapon(weaponnum, 0);
		capacity = bgunGetCapacityByAmmotype(ammotype);
		ammo = weaponGetAmmoByFunction(weaponnum, 0);
		capacity -= (ammo ? ammo->clipsize : 0);

		if (g_FrData.ammoextra > 0) {
			tmp = bgunGetReservedAmmoCount(ammotype);
			g_FrData.ammoextra -= g_FrData.numshotssincetopup;

			if (g_FrData.ammoextra < 0) {
				g_FrData.ammoextra = 0;
			}

			capacity = tmp + g_FrData.numshotssincetopup;
			bgunSetAmmoQuantity(ammotype, capacity);
		} else if (g_FrData.ammoextra == -1) {
			bgunSetAmmoQuantity(ammotype, capacity);
		}

		if (weaponnum == WEAPON_SUPERDRAGON) {
			capacity = bgunGetCapacityByAmmotype(AMMOTYPE_DEVASTATOR);

			if (g_FrData.sdgrenadeextra > 0) {
				tmp = bgunGetReservedAmmoCount(AMMOTYPE_DEVASTATOR);
				g_FrData.sdgrenadeextra -= g_FrData.numshotssincetopup;

				if (g_FrData.sdgrenadeextra < 0) {
					g_FrData.sdgrenadeextra = 0;
				}

				capacity = tmp + g_FrData.numshotssincetopup;
				bgunSetAmmoQuantity(AMMOTYPE_DEVASTATOR, capacity);
			} else if (g_FrData.sdgrenadeextra == -1) {
				bgunSetAmmoQuantity(AMMOTYPE_DEVASTATOR, capacity);
			}
		}

		g_FrData.numshotssincetopup = 0;
	}

	g_FrData.timetaken += g_Vars.lvupdate60;

	// Handle prestart
	if (g_FrData.timetaken < 0) {
		if (g_FrData.numshots == 0) {
			if (g_FrData.donealarm == false && g_FrData.timetaken > TICKS(-180)) {
				g_FrData.donealarm = true;
				sndStart(var80095200, SFX_FR_ALARM, NULL, -1, -1, -1, -1, -1);
			}

			if (!g_FrData.donelighting && g_FrData.timetaken > TICKS(-225)) {
				frInitLighting();
			}

			return;
		}

		// Fired a shot during prestart
		if (!g_FrData.donelighting) {
			frInitLighting();
		}

		g_FrData.timetaken = 0;
		g_FrData.donealarm = true;
	}

	// Iterate each target and handle their health active/inactive state
	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		if (g_FrData.targets[i].inuse && g_FrData.targets[i].destroyed == false && g_FrData.targets[i].active) {
			invincible = false;
			exploding = false;
			weaponnum2 = frGetWeaponBySlot(g_FrData.slot);
			prop = g_FrData.targets[i].prop;
			obj = prop->obj;

			switch (weaponnum2) {
			case WEAPON_GRENADE:
			case WEAPON_PROXIMITYMINE:
				coordTriggerProxies(&prop->pos, true);
				break;
			}

			if (g_FrData.targets[i].travelling && g_FrData.targets[i].silent && g_FrData.targets[i].travelspeed != -1) {
				g_FrData.targets[i].silent = false;
				propsnd0f0939f8(NULL, g_FrData.targets[i].prop, SFX_FR_CONVEYER, -1,
						-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
			}

			if (g_FrData.targets[i].angle > 2.2915925979614f && g_FrData.targets[i].angle < 3.9915928840637f) {
				obj->damage = 0;
			}

			if ((g_FrData.targets[i].flags & FRTARGETFLAG_TMPINVINCIBLE)
					&& g_FrData.targets[i].invincibletimer < TICKS(300)) {
				invincible = true;
				g_FrData.targets[i].invincibletimer += g_Vars.lvupdate60;
			}

			if (obj->damage > 0) {
				if (invincible || g_FrData.targets[i].angle == M_PI) {
					obj->damage = 0;
				} else if (g_FrData.targets[i].flags & FRTARGETFLAG_ONEHITEXPLODE
						|| obj->damage >= obj->maxdamage
						|| frGetWeaponBySlot(g_FrData.slot) == WEAPON_PHOENIX) {
					g_FrData.numhitsbullseye++;
					g_FrData.score += 10;
					exploding = true;
					g_FrData.feedbackttl = TICKS(60);
					g_FrData.feedbackzone = FRZONE_EXPLODE;
				}
			}

			// Handle target being destroyed
			if (exploding || (g_FrData.targets[i].maxdamage != 255
						&& g_FrData.targets[i].damage >= g_FrData.targets[i].maxdamage)) {
				bbox = objFindBboxRodata(obj);

				if (g_FrNumSounds && g_FrData.targets[i].travelling) {
					g_FrNumSounds--;
					func0f0926bc(prop, 1, 0xffff);
				}

				if (g_FrNumSounds);

				shardsCreate(&prop->pos, &obj->realrot[0][0], &obj->realrot[1][0], &obj->realrot[2][0],
						bbox->xmin, bbox->xmax, bbox->ymin, bbox->ymax, 2, prop);

				g_FrData.targetsdestroyed++;

				if (g_FrData.targets[i].flags & FRTARGETFLAG_ONEHITEXPLODE) {
					explosionCreateSimple(g_FrData.targets[i].prop, &g_FrData.targets[i].prop->pos,
							g_FrData.targets[i].prop->rooms, EXPLOSIONTYPE_FRTARGET, 1);
				}

				g_FrData.targets[i].travelling = false;
				g_FrData.targets[i].active = false;
				g_FrData.targets[i].destroyed = true;

				obj->flags2 |= OBJFLAG2_INVISIBLE;

				prop->pos.x = 0;
				prop->pos.y = -5000;
				prop->pos.z = 0;

				func0f069c70(obj, true, false);

				// Activate another target
				for (j = 0; j < ARRAYCOUNT(g_FrData.targets); j++) {
					if (g_FrData.targets[j].destroyed == false
							&& g_FrData.targets[j].inuse
							&& g_FrData.targets[j].active == false) {
						obj2 = g_FrData.targets[j].prop->obj;
						g_FrData.targets[j].active = true;
						obj2->flags2 &= ~OBJFLAG2_INVISIBLE;
						break;
					}
				}
			}
		}
	}

	// Check if the session should end
	if (g_FrData.goaltargets == 255) {
		if (g_FrData.goalscore && g_FrData.score >= g_FrData.goalscore) {
			frSetCompleted();
			return;
		}
	} else {
		if (g_FrData.targetsdestroyed >= g_FrData.goaltargets
				&& (g_FrData.goalscore == 0 || g_FrData.score >= g_FrData.goalscore)) {
			frSetCompleted();
			return;
		}
	}

	if (g_FrData.targetsdestroyed >= g_FrData.numtargets) {
		frSetFailReason(FRFAILREASON_SCOREUNATTAINABLE);
		return;
	}

	if (frIsAmmoWasted()) {
		frSetFailReason(FRFAILREASON_OUTOFAMMO);
		return;
	}

	if (g_FrData.timelimit != 255 && g_FrData.timetaken >= g_FrData.timelimit * TICKS(60)) {
		frSetFailReason(FRFAILREASON_TIMEOVER);
		return;
	}

	// Tick each target
	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		if (g_FrData.targets[i].inuse
				&& g_FrData.targets[i].destroyed == false
				&& g_FrData.targets[i].active) {
			prop = g_FrData.targets[i].prop;
			obj = prop->obj;

			if (g_FrData.targets[i].travelling) {
				if (g_FrData.targets[i].travelspeed == -1) {
					g_FrData.targets[i].donestopsound = true;
					g_FrData.targets[i].travelling = false;
					mult = 1;
					dist = -2;
				} else {
					diff.x = g_FrData.targets[i].dstpos.x - prop->pos.x;
					diff.y = g_FrData.targets[i].dstpos.y - prop->pos.y;
					diff.z = g_FrData.targets[i].dstpos.z - prop->pos.z;

					dist = sqrtf(diff.f[0] * diff.f[0] + diff.f[1] * diff.f[1] + diff.f[2] * diff.f[2]);
					mult = 1;

					if (dist != 0) {
						mult = (g_FrData.targets[i].travelspeed * g_Vars.lvupdate240) * 0.25f;
						diff.x *= 1.0f / dist;
						diff.y *= 1.0f / dist;
						diff.z *= 1.0f / dist;
						newpos.x = diff.x * mult + prop->pos.x;
						newpos.y = diff.y * mult + prop->pos.y;
						newpos.z = diff.z * mult + prop->pos.z;
					} else {
						dist = -2;
					}
				}

				if (mult >= dist) {
					// Target is stopping
					newpos = g_FrData.targets[i].dstpos;

					g_FrData.targets[i].scriptenabled = true;
					g_FrData.targets[i].travelling = false;

					if (g_FrData.targets[i].donestopsound == false) {
						g_FrData.targets[i].donestopsound = true;

						if (g_FrNumSounds) {
							g_FrNumSounds--;
						}

						func0f0926bc(prop, 1, 0xffff);
						propsnd0f0939f8(NULL, prop, SFX_FR_CONVEYER_STOP, -1,
								-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);

						if (g_FrNumSounds);
					}
				}

				prop->pos = newpos;

				func0f069c70(obj, true, false);
			}

			if (g_FrData.targets[i].rotateoncloak && g_FrData.targets[i].rotating == false) {
				if (g_FrData.targets[i].timeuntilrotate == 0) {
					chr = g_Vars.currentplayer->prop->chr;
					cloaked = chr->hidden & CHRHFLAG_CLOAKED;

					if (cloaked) {
						if (g_FrData.targets[i].angle == M_PI) {
							g_FrData.targets[i].timeuntilrotate = TICKS(60);
							g_FrData.targets[i].rotatetoangle = 0;
							g_FrData.targets[i].rotatespeed = -M_PI / 90;
						}
					} else {
						if (g_FrData.targets[i].angle == 0) {
							g_FrData.targets[i].timeuntilrotate = TICKS(60);
							g_FrData.targets[i].rotatetoangle = M_PI;
							g_FrData.targets[i].rotatespeed = M_PI / 90;
						}
					}
				} else {
					g_FrData.targets[i].timeuntilrotate -= g_Vars.lvupdate60;

					if (g_FrData.targets[i].timeuntilrotate <= 0) {
						g_FrData.targets[i].timeuntilrotate = 0;
						g_FrData.targets[i].rotating = true;
					}
				}
			} else if (g_FrData.targets[i].rotating) {
				toangle = g_FrData.targets[i].rotatetoangle;
				speed = g_FrData.targets[i].rotatespeed;

				if (toangle);

				oldside = 0;

				if (g_FrData.targets[i].angle < toangle) {
					oldside = 1;
				}

				oldside = (u8)oldside;

				g_FrData.targets[i].angle += speed * g_Vars.lvupdate240 * 0.25f;

				newside = 0;

				toangle = g_FrData.targets[i].rotatetoangle;

				if (g_FrData.targets[i].angle < toangle) {
					newside = 1;
				}

				newside = (u8)newside;

				if (newside != oldside || g_FrData.targets[i].angle == toangle) {
					// Reached desired angle
					g_FrData.targets[i].angle = g_FrData.targets[i].rotatetoangle;
					g_FrData.targets[i].rotating = false;
					g_FrData.targets[i].scriptenabled = true;
					g_FrData.targets[i].scriptsleep = 0;

					while (g_FrData.targets[i].angle > M_BADTAU) {
						g_FrData.targets[i].angle -= M_BADTAU;
					}

					while (g_FrData.targets[i].angle < 0) {
						g_FrData.targets[i].angle += M_BADTAU;
					}
				}

				mtx4LoadYRotation(g_FrData.targets[i].angle + M_PI, &spbc);
				mtx00015f04(obj->model->scale, &spbc);
				mtx4ToMtx3(&spbc, sp98);
				mtx3Copy(sp98, obj->realrot);
			}

			if (g_FrData.targets[i].scriptenabled && g_FrData.targets[i].scriptsleep != SECSTOTIME60(255)) {
				g_FrData.targets[i].scriptsleep -= g_Vars.lvupdate60;

				if (g_FrData.targets[i].scriptsleep <= 0) {
					g_FrData.targets[i].scriptenabled = false;

					while (!frExecuteTargetScript(i));

					if (frTargetIsAtScriptStart(i)) {
						while (!frExecuteTargetScript(i));
					}
				}
			}
		}
	}
}

void func0f1a0924(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;
	s32 i;

	if (obj->modelnum == MODEL_TARGET) {
		f32 sp68;
		f32 sp64;
		f32 sp60;
		f32 sp56;

		sp64 = -1;
		sp68 = -1;
		sp56 = -2;
		sp60 = -2;

		modelGetScreenCoords(obj->model, &sp56, &sp64, &sp60, &sp68);

		for (i = 0; i < 4; i++) {
			if (g_Vars.currentplayer->trackedprops[i].prop == prop) {
				return;
			}

			if (g_Vars.currentplayer->trackedprops[i].prop == NULL) {
				g_Vars.currentplayer->trackedprops[i].prop = prop;

				g_Vars.currentplayer->trackedprops[i].x1 = sp64 - 2;
				g_Vars.currentplayer->trackedprops[i].x2 = sp56 + 2;
				g_Vars.currentplayer->trackedprops[i].y1 = sp68 - 2;
				g_Vars.currentplayer->trackedprops[i].y2 = sp60 + 2;
				g_Vars.currentplayer->targetset[i] = 0;
				return;
			}
		}
	}
}

bool frChooseFarsightTarget(void)
{
	struct prop *bestprop = NULL;
	f32 bestvalue = 1;
	f32 bestdist = -1;
	bool found = false;
	s32 i;

	if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_FARSIGHT) {
		for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
			if (g_FrData.targets[i].inuse
					&& g_FrData.targets[i].destroyed == false
					&& g_FrData.targets[i].active
					&& g_FrData.targets[i].flags & FRTARGETFLAG_FARSIGHTAUTOTARGETABLE) {
				struct prop *prop = g_FrData.targets[i].prop;
				f32 xdiff = g_Vars.currentplayer->bond2.unk10.x - prop->pos.x;
				f32 ydiff = g_Vars.currentplayer->bond2.unk10.y - prop->pos.y;
				f32 zdiff = g_Vars.currentplayer->bond2.unk10.z - prop->pos.z;
				f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

				if (dist > 0) {
					f32 value = (xdiff * g_Vars.currentplayer->bond2.unk1c.f[0]
							+ ydiff * g_Vars.currentplayer->bond2.unk1c.f[1]
							+ zdiff * g_Vars.currentplayer->bond2.unk1c.f[2]) / dist;

					if (value);

					if (value < 0 && value < bestvalue) {
						bestvalue = value;
						bestprop = prop;
						bestdist = dist;
						found = true;
					}
				}
			}
		}
	}

	g_Vars.currentplayer->autoeraserdist = bestdist;
	g_Vars.currentplayer->autoerasertarget = bestprop;

	return found;
}

s32 frIsInTraining(void)
{
	if (g_FrData.menucountdown > 0 &&
			(g_FrData.menutype == FRMENUTYPE_FAILED || g_FrData.menutype == FRMENUTYPE_COMPLETED)) {
		return true;
	}

	return g_Vars.currentplayer->prop->rooms[0] == ROOM_DISH_FIRINGRANGE
		&& g_FrIsValidWeapon
		&& g_StageNum == STAGE_CITRAINING;
}

void frCalculateHit(struct defaultobj *obj, struct coord *hitpos, f32 maulercharge)
{
	s32 i;

	if (g_FrIsValidWeapon == false) {
		return;
	}

	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		struct prop *prop = g_FrData.targets[i].prop;

		if (obj == prop->obj) {
			f32 xdiff = hitpos->x - prop->pos.x;
			f32 ydiff = hitpos->y - prop->pos.y;
			f32 zdiff = hitpos->z - prop->pos.z;

			f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

			if (g_FrData.targets[i].flags & FRTARGETFLAG_ONEHITEXPLODE) {
				g_FrData.targets[i].damage = g_FrData.targets[i].maxdamage;
			} else if (frGetWeaponBySlot(g_FrData.slot) == WEAPON_MAULER) {
				g_FrData.targets[i].damage += (f32)((s32)(maulercharge * 0.1f) + 1);
			} else if ((g_FrData.targets[i].flags & FRTARGETFLAG_TMPINVINCIBLE) == 0
					|| g_FrData.targets[i].invincibletimer >= TICKS(300)) {
				g_FrData.targets[i].damage++;
			}

			if (dist < 18) {
				g_FrData.feedbackzone = FRZONE_BULLSEYE;
				g_FrData.numhitsbullseye++;
			} else if (dist < 37) {
				g_FrData.feedbackzone = FRZONE_RING1;
				g_FrData.numhitsring1++;
			} else if (dist < 56) {
				g_FrData.feedbackzone = FRZONE_RING2;
				g_FrData.numhitsring2++;
			} else {
				g_FrData.feedbackzone = FRZONE_RING3;
				g_FrData.numhitsring3++;
			}

			g_FrData.feedbackttl = TICKS(60);
			g_FrData.score += g_FrData.feedbackzone;
		}
	}
}

void frIncrementNumShots(void)
{
	g_FrData.numshots++;
	g_FrData.numshotssincetopup++;
}

static bool ciIsChrBioUnlocked(u32 bodynum)
{
	switch (bodynum) {
	case BODY_DARK_COMBAT:
	case BODY_CARRINGTON:
		return true;
	case BODY_CASSANDRA:
		return ciIsStageComplete(SOLOSTAGEINDEX_DEFECTION);
	case BODY_DRCAROLL:
		return ciIsStageComplete(SOLOSTAGEINDEX_INVESTIGATION);
	case BODY_MRBLONDE:
		return ciIsStageComplete(SOLOSTAGEINDEX_EXTRACTION);
	case BODY_TRENT:
		return ciIsStageComplete(SOLOSTAGEINDEX_G5BUILDING);
	case BODY_JONATHAN:
		return ciIsStageComplete(SOLOSTAGEINDEX_INFILTRATION);
	case BODY_THEKING:
		return ciIsStageComplete(SOLOSTAGEINDEX_RESCUE);
	case BODY_PRESIDENT:
		return ciIsStageComplete(SOLOSTAGEINDEX_AIRFORCEONE);
	}

	return false;
}

u8 g_ChrBioSlot = 0;

struct chrbio *ciGetChrBioByBodynum(u32 bodynum)
{
	static struct chrbio bios[] = {
		// name, race, age, profile
		/*0*/ { L_MISC_219, L_MISC_220, L_MISC_221, L_MISC_222 }, // Joanna Dark
		/*1*/ { L_MISC_223, L_MISC_224, L_MISC_225, L_MISC_226 }, // Jonathan
		/*2*/ { L_MISC_227, L_MISC_228, L_MISC_229, L_MISC_230 }, // Daniel Carrington
		/*3*/ { L_MISC_231, L_MISC_232, L_MISC_233, L_MISC_234 }, // Cassandra De Vries
		/*4*/ { L_MISC_235, L_MISC_236, L_MISC_237, L_MISC_238 }, // Trent Easton
		/*5*/ { L_MISC_239, L_MISC_240, L_MISC_241, L_MISC_242 }, // Dr. Caroll
		/*6*/ { L_MISC_243, L_MISC_244, L_MISC_245, L_MISC_246 }, // Elvis
		/*7*/ { L_MISC_247, L_MISC_248, L_MISC_249, L_MISC_250 }, // Mr. Blonde
		/*8*/ { L_MISC_251, L_MISC_252, L_MISC_253, L_MISC_254 }, // Mr. Blonde (repeat)
		/*9*/ { L_MISC_255, L_MISC_256, L_MISC_257, L_MISC_258 }, // The U.S. President
	};

	switch (bodynum) {
	case BODY_DARK_COMBAT:
		return &bios[0];
	case BODY_JONATHAN:
		return &bios[1];
	case BODY_CARRINGTON:
		return &bios[2];
	case BODY_CASSANDRA:
		return &bios[3];
	case BODY_TRENT:
		return &bios[4];
	case BODY_DRCAROLL:
		return &bios[5];
	case BODY_THEKING:
		return &bios[6];
	case BODY_MRBLONDE:
		if (ciIsStageComplete(SOLOSTAGEINDEX_CRASHSITE)) {
			return &bios[8];
		}
		return &bios[7];
	case BODY_PRESIDENT:
		return &bios[9];
	}

	return NULL;
}

char *ciGetChrBioDescription(void)
{
	struct chrbio *bio = ciGetChrBioByBodynum(ciGetChrBioBodynumBySlot(g_ChrBioSlot));
	return langGet(bio->description);
}

s32 ciGetNumUnlockedChrBios(void)
{
	s32 count = 0;
	s32 bodynum;

	for (bodynum = 0; bodynum < NUM_BODIES; bodynum++) {
		if (ciIsChrBioUnlocked(bodynum)) {
			count++;
		}
	}

	return count;
}

s32 ciGetChrBioBodynumBySlot(s32 slot)
{
	s32 index = -1;
	s32 bodynum;

	for (bodynum = 0; bodynum < NUM_BODIES; bodynum++) {
		if (ciIsChrBioUnlocked(bodynum)) {
			index++;
		}

		if (index == slot) {
			return bodynum;
		}
	}

	return 0;
}

struct miscbio *ciGetMiscBio(s32 index)
{
	static struct miscbio bios[] = {
		// name, description
		{ L_MISC_259, L_MISC_260 },
		{ L_MISC_261, L_MISC_262 },
		{ L_MISC_263, L_MISC_264 },
		{ L_MISC_265, L_MISC_266 },
	};

	switch (index) {
	case MISCBIO_MAIANS:     return &bios[0];
	case MISCBIO_SKEDAR:     return &bios[1];
	case MISCBIO_BACKGROUND: return &bios[2];
	case MISCBIO_STORY:      return &bios[3];
	}

	return NULL;
}

static bool ciIsMiscBioUnlocked(s32 index)
{
	switch (index) {
	case MISCBIO_MAIANS:
		return ciIsStageComplete(SOLOSTAGEINDEX_RESCUE);
	case MISCBIO_SKEDAR:
		return ciIsStageComplete(SOLOSTAGEINDEX_ATTACKSHIP);
	case MISCBIO_BACKGROUND:
	case MISCBIO_STORY:
		return ciIsStageComplete(SOLOSTAGEINDEX_MBR);
	}

	return false;
}

s32 ciGetNumUnlockedMiscBios(void)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < 4; i++) {
		if (ciIsMiscBioUnlocked(i)) {
			count++;
		}
	}

	return count;
}

s32 ciGetMiscBioIndexBySlot(s32 slot)
{
	s32 index = -1;
	s32 i;

	for (i = 0; i < 4; i++) {
		if (ciIsMiscBioUnlocked(i)) {
			index++;
		}

		if (index == slot) {
			return i;
		}
	}

	return 0;
}

char *ciGetMiscBioDescription(void)
{
	s32 index = ciGetMiscBioIndexBySlot(g_ChrBioSlot - ciGetNumUnlockedChrBios());
	struct miscbio *bio = ciGetMiscBio(index);

	return langGet(bio->description);
}

static bool ciIsHangarBioAVehicle(s32 index)
{
	return index >= HANGARBIO_JUMPSHIP;
}

u8 g_HangarBioSlot = 0;

struct hangarbio *ciGetHangarBio(s32 index)
{
	static struct hangarbio bios[] = {
		// name, description
		{ L_MISC_290, L_MISC_313 }, // Carrington Institute
		{ L_MISC_291, L_MISC_314 }, // Lucerne Tower
		{ L_MISC_292, L_MISC_315 }, // Laboratory Basement
		{ L_MISC_293, L_MISC_316 }, // Carrington Villa
		{ L_MISC_294, L_MISC_317 }, // Chicago
		{ L_MISC_295, L_MISC_318 }, // G5 Building
		{ L_MISC_296, L_MISC_319 }, // Area 51
		{ L_MISC_297, L_MISC_320 }, // Alaskan Air Base
		{ L_MISC_298, L_MISC_321 }, // Air Force One
		{ L_MISC_299, L_MISC_322 }, // Crash Site
		{ L_MISC_300, L_MISC_323 }, // Pelagic II
		{ L_MISC_301, L_MISC_324 }, // Cetan Ship
		{ L_MISC_302, L_MISC_325 }, // Skedar Assault Ship
		{ L_MISC_303, L_MISC_326 }, // Skedar Homeworld
		{ L_MISC_304, L_MISC_327 }, // Jumpship
		{ L_MISC_305, L_MISC_328 }, // HoverCrate
		{ L_MISC_306, L_MISC_329 }, // HoverBike
		{ L_MISC_307, L_MISC_330 }, // Cleaning Hovbot
		{ L_MISC_308, L_MISC_331 }, // Hovercopter
		{ L_MISC_309, L_MISC_332 }, // G5 Robot
		{ L_MISC_310, L_MISC_333 }, // A51 Interceptor
		{ L_MISC_311, L_MISC_334 }, // Maian Vessel
		{ L_MISC_312, L_MISC_335 }, // Skedar Shuttle
	};

	switch (index) {
	case HANGARBIO_INSTITUTE:      return &bios[0];
	case HANGARBIO_DDTOWER:        return &bios[1];
	case HANGARBIO_LABBASEMENT:    return &bios[2];
	case HANGARBIO_VILLA:          return &bios[3];
	case HANGARBIO_CHICAGO:        return &bios[4];
	case HANGARBIO_G5:             return &bios[5];
	case HANGARBIO_AREA51:         return &bios[6];
	case HANGARBIO_AIRBASE:        return &bios[7];
	case HANGARBIO_AIRFORCEONE:    return &bios[8];
	case HANGARBIO_CRASHSITE:      return &bios[9];
	case HANGARBIO_PELAGIC:        return &bios[10];
	case HANGARBIO_DEEPSEA:        return &bios[11];
	case HANGARBIO_ATTACKSHIP:     return &bios[12];
	case HANGARBIO_SKEDARRUINS:    return &bios[13];
	case HANGARBIO_JUMPSHIP:       return &bios[14];
	case HANGARBIO_HOVERCRATE:     return &bios[15];
	case HANGARBIO_HOVERBIKE:      return &bios[16];
	case HANGARBIO_HOVERBOT:       return &bios[17];
	case HANGARBIO_HOVERCOPTER:    return &bios[18];
	case HANGARBIO_G5ROBOT:        return &bios[19];
	case HANGARBIO_A51INTERCEPTOR: return &bios[20];
	case HANGARBIO_MAIANVESSEL:    return &bios[21];
	case HANGARBIO_SKEDARSHUTTLE:  return &bios[22];
	}

	return NULL;
}

u8 g_DtSlot = 0;
u8 var80088adc = 0;

static bool ciIsHangarBioUnlocked(u32 bioindex)
{
	u32 stage;

	switch (bioindex) {
	case HANGARBIO_INSTITUTE:
	case HANGARBIO_HOVERCRATE:
		return true;
	case HANGARBIO_DDTOWER:
		stage = SOLOSTAGEINDEX_DEFECTION;
		break;
	case HANGARBIO_LABBASEMENT:
	case HANGARBIO_HOVERBOT:
		stage = SOLOSTAGEINDEX_INVESTIGATION;
		break;
	case HANGARBIO_HOVERCOPTER:
		stage = SOLOSTAGEINDEX_EXTRACTION;
		break;
	case HANGARBIO_VILLA:
	case HANGARBIO_JUMPSHIP:
		stage = SOLOSTAGEINDEX_VILLA;
		break;
	case HANGARBIO_CHICAGO:
		stage = SOLOSTAGEINDEX_CHICAGO;
		break;
	case HANGARBIO_G5:
	case HANGARBIO_G5ROBOT:
		stage = SOLOSTAGEINDEX_G5BUILDING;
		break;
	case HANGARBIO_AREA51:
	case HANGARBIO_HOVERBIKE:
	case HANGARBIO_A51INTERCEPTOR:
		stage = SOLOSTAGEINDEX_INFILTRATION;
		break;
	case HANGARBIO_AIRBASE:
		stage = SOLOSTAGEINDEX_AIRBASE;
		break;
	case HANGARBIO_AIRFORCEONE:
		stage = SOLOSTAGEINDEX_AIRFORCEONE;
		break;
	case HANGARBIO_CRASHSITE:
	case HANGARBIO_MAIANVESSEL:
		stage = SOLOSTAGEINDEX_CRASHSITE;
		break;
	case HANGARBIO_PELAGIC:
		stage = SOLOSTAGEINDEX_PELAGIC;
		break;
	case HANGARBIO_DEEPSEA:
		stage = SOLOSTAGEINDEX_DEEPSEA;
		break;
	case HANGARBIO_ATTACKSHIP:
	case HANGARBIO_SKEDARSHUTTLE:
		stage = SOLOSTAGEINDEX_DEFENSE;
		break;
	case HANGARBIO_SKEDARRUINS:
		stage = SOLOSTAGEINDEX_ATTACKSHIP;
		break;
	default:
		return false;
	}

	return ciIsStageComplete(stage);
}

s32 ciGetNumUnlockedLocationBios(void)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < 23; i++) {
		if (ciIsHangarBioAVehicle(i)) {
			return count;
		}

		if (ciIsHangarBioUnlocked(i)) {
			count++;
		}
	}

	return count;
}

s32 ciGetNumUnlockedHangarBios(void)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < 23; i++) {
		if (ciIsHangarBioUnlocked(i)) {
			count++;
		}
	}

	return count;
}

s32 ciGetHangarBioIndexBySlot(s32 slot)
{
	s32 index = -1;
	s32 i;

	for (i = 0; i < 23; i++) {
		if (ciIsHangarBioUnlocked(i)) {
			index++;
		}

		if (index == slot) {
			return i;
		}
	}

	return 0;
}

char *ciGetHangarBioDescription(void)
{
	struct hangarbio *bio = ciGetHangarBio(ciGetHangarBioIndexBySlot(g_HangarBioSlot));
	return langGet(bio->description);
}

struct trainingdata *dtGetData(void)
{
	return &g_DtData;
}

static void dtRestorePlayer(void)
{
	bgunSetPassiveMode(true);

	if (g_DtData.obj) {
		objFreePermanently(g_DtData.obj, true);
	}

	g_DtData.obj = NULL;

	if (dtGetWeaponByDeviceIndex(dtGetIndexBySlot(g_DtSlot)) == WEAPON_ECMMINE) {
		bgunSetAmmoQuantity(AMMOTYPE_ECM_MINE, 0);
	}

	if (g_Vars.currentplayer->eyespy) {
		struct chrdata *chr = g_Vars.currentplayer->eyespy->prop->chr;
		g_Vars.currentplayer->eyespy->deployed = false;
		g_Vars.currentplayer->eyespy->held = true;
		g_Vars.currentplayer->eyespy->active = false;

		chr->chrflags |= CHRCFLAG_HIDDEN;

		func0f0926bc(g_Vars.currentplayer->eyespy->prop, 1, 0xffff);

		g_Vars.currentplayer->devicesactive &= ~DEVICE_EYESPY;
	}
}

void dtPushEndscreen(void)
{
	if (g_DtData.completed) {
		func0f0f85e0(&g_DtCompletedMenuDialog, MENUROOT_TRAINING);
	} else if (g_DtData.failed) {
		func0f0f85e0(&g_DtFailedMenuDialog, MENUROOT_TRAINING);
	}

	g_DtData.timeleft = 0;
	g_DtData.completed = false;
	g_DtData.failed = false;
	g_DtData.finished = false;
	g_DtData.holographedpc = false;
}

void dtTick(void)
{
	if (var80088adc) {
		if (g_DtData.intraining) {
			g_DtData.timetaken += g_Vars.lvupdate60;

			if (g_Vars.currentplayer->isdead) {
				dtEnd();
			}

			if (chrHasStageFlag(NULL, STAGEFLAG_CI_TRIGGER_DEVICE_FAILURE)) {
				dtEnd();
				g_DtData.failed = true;
				g_DtData.timeleft = 1;
				g_DtData.finished = true;
			} else if (chrHasStageFlag(NULL, STAGEFLAG_CI_TRIGGER_DEVICE_SUCCESS)) {
				dtEnd();
				g_DtData.completed = true;
				g_DtData.timeleft = 1;
				g_DtData.finished = true;
			}
		} else if (g_DtData.finished) {
			if (g_DtData.timeleft <= 0) {
				dtPushEndscreen();
			} else {
				g_DtData.timeleft -= g_Vars.lvupdate60;
			}
		}
	}
}

void func0f1a1ac0(void)
{
	if (var80088adc == false) {
		var80088adc = true;
		g_DtData.intraining = false;
		g_DtData.failed = false;
		g_DtData.completed = false;
		g_DtData.finished = false;
		g_DtData.timeleft = 0;
		g_DtData.holographedpc = false;
		g_DtData.timetaken = 0;
		g_DtData.obj = NULL;
		chrUnsetStageFlag(NULL, STAGEFLAG_CI_DEVICE_ABORTING);
		chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_DEVICE_SUCCESS);
		chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_DEVICE_FAILURE);
	}
}

void dtBegin(void)
{
	g_DtData.intraining = true;
	g_DtData.timetaken = 0;
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_DEVICE_ABORTING);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_DEVICE_SUCCESS);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_DEVICE_FAILURE);
	chrSetStageFlag(NULL, ciGetStageFlagByDeviceIndex(dtGetIndexBySlot(g_DtSlot)));
	g_Vars.currentplayer->training = true;
	bgunSetPassiveMode(false);
	chrSetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
}

void dtEnd(void)
{
	g_DtData.intraining = false;
	dtRestorePlayer();
	bgunSetAmmoQuantity(AMMOTYPE_CLOAK, 0);
	chrSetStageFlag(NULL, STAGEFLAG_CI_DEVICE_ABORTING);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_DEVICE_FAILURE);
	chrUnsetStageFlag(NULL, ciGetStageFlagByDeviceIndex(dtGetIndexBySlot(g_DtSlot)));
	g_Vars.currentplayer->training = false;
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
	playerDisplayHealth();
	g_Vars.currentplayer->bondhealth = 1;
}

static bool dtIsAvailable(s32 deviceindex)
{
	deviceindex--;

	if (deviceindex >= 10) {
		return true;
	}

	if (deviceindex < 0 || gamefileHasFlag(GAMEFILEFLAG_CI_UPLINK_DONE - deviceindex)) {
		return true;
	}

	return false;
}

s32 dtGetNumAvailable(void)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < 10; i++) {
		if (dtIsAvailable(i)) {
			count++;
		}
	}

	return count;
}

s32 dtGetIndexBySlot(s32 wantindex)
{
	s32 index = -1;
	s32 i;

	for (i = 0; i < 10; i++) {
		if (dtIsAvailable(i)) {
			index++;
		}

		if (index == wantindex) {
			return i;
		}
	}

	return 0;
}

u32 dtGetWeaponByDeviceIndex(s32 deviceindex)
{
	static u32 weapons[] = {
		WEAPON_DATAUPLINK,
		WEAPON_ECMMINE,
		WEAPON_EYESPY,
		WEAPON_NIGHTVISION,
		WEAPON_DOORDECODER,
		WEAPON_RTRACKER,
		WEAPON_IRSCANNER,
		WEAPON_XRAYSCANNER,
		WEAPON_DISGUISE41,
		WEAPON_CLOAKINGDEVICE,
	};

	return weapons[deviceindex];
}

static u32 ciGetStageFlagByDeviceIndex(u32 deviceindex)
{
	return STAGEFLAG_CI_TRIGGER_UPLINK << deviceindex;
}

char *dtGetDescription(void)
{
	static u32 texts[] = {
		/*0*/ L_MISC_280, // Data uplink
		/*1*/ L_MISC_279, // ECM mine
		/*2*/ L_MISC_271, // CamSpy
		/*3*/ L_MISC_272, // Night vision
		/*4*/ L_MISC_273, // Door decoder
		/*5*/ L_MISC_277, // R-tracker
		/*6*/ L_MISC_276, // IR scanner
		/*7*/ L_MISC_274, // X-ray scanner
		/*8*/ L_MISC_275, // Disguise
		/*9*/ L_MISC_278, // Cloak
	};

	return langGet(texts[dtGetIndexBySlot(g_DtSlot)]);
}

char *dtGetTip1(void)
{
	return langGet(L_MISC_357 + dtGetIndexBySlot(g_DtSlot));
}

char *dtGetTip2(void)
{
	return langGet(L_MISC_367 + dtGetIndexBySlot(g_DtSlot));
}

struct trainingdata *getHoloTrainingData(void)
{
	return &g_HtData;
}

void htPushEndscreen(void)
{
	if (g_HtData.completed) {
		func0f0f85e0(&g_HtCompletedMenuDialog, MENUROOT_TRAINING);
	} else if (g_HtData.failed) {
		func0f0f85e0(&g_HtFailedMenuDialog, MENUROOT_TRAINING);
	}

	g_HtData.timeleft = 0;
	g_HtData.completed = false;
	g_HtData.failed = false;
	g_HtData.finished = false;
}

u8 var80088bb4 = 0;
u8 var80088bb8 = 0;

void htTick(void)
{
	if (var80088bb8) {
		if (g_HtData.intraining) {
			g_HtData.timetaken += g_Vars.lvupdate60;

			if (g_Vars.currentplayer->isdead) {
				htEnd();
			}

			if (chrHasStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_FAILURE)) {
				htEnd();
				g_HtData.failed = true;
				g_HtData.timeleft = 1;
				g_HtData.finished = true;
			} else if (chrHasStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_SUCCESS)) {
				htEnd();
				g_HtData.completed = true;
				g_HtData.timeleft = 1;
				g_HtData.finished = true;
			}
		} else if (g_HtData.finished) {
			if (g_HtData.timeleft <= 0) {
				htPushEndscreen();
			} else {
				g_HtData.timeleft -= g_Vars.lvupdate60;
			}
		}
	}
}

void func0f1a2198(void)
{
	if (var80088bb8 == false) {
		var80088bb8 = true;
		g_HtData.intraining = false;
		g_HtData.failed = false;
		g_HtData.completed = false;
		g_HtData.finished = false;
		g_HtData.timeleft = 0;
		g_HtData.timetaken = 0;
		chrUnsetStageFlag(NULL, STAGEFLAG_CI_HOLO_ABORTING);
		chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_SUCCESS);
		chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_FAILURE);
	}
}

void htBegin(void)
{
	struct waypoint *waypoints = g_StageSetup.waypoints;

	g_HtData.intraining = true;
	g_HtData.timetaken = 0;
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_HOLO_ABORTING);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_SUCCESS);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_FAILURE);
	chrSetStageFlag(NULL, func0f1a25c0(htGetIndexBySlot(var80088bb4)));

	// Disable segment leading out of the door
	waypointDisableSegment(&waypoints[0x20], &waypoints[0x31]);

	g_Vars.currentplayer->training = true;
	bgunSetPassiveMode(false);
	chrSetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
}

void htEnd(void)
{
	struct prop *prop;
	s16 *propnum;
	s16 propnums[256];
	static s16 rooms[5] = { 0x0016, 0x0017, 0x0018, 0x0019, -1 };
	struct waypoint *waypoints = g_StageSetup.waypoints;

	g_HtData.intraining = false;
	chrSetStageFlag(NULL, STAGEFLAG_CI_HOLO_ABORTING);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_FAILURE);
	chrUnsetStageFlag(NULL, func0f1a25c0(htGetIndexBySlot(var80088bb4)));

	// Enable segment leading out of the door
	waypointEnableSegment(&waypoints[0x20], &waypoints[0x31]);

	g_Vars.currentplayer->training = false;
	roomGetProps(rooms, propnums, 256);
	propnum = &propnums[0];

	// Remove dropped weapons
	while (*propnum >= 0) {
		prop = &g_Vars.props[*propnum];

		if (prop && prop->type == PROPTYPE_WEAPON) {
			struct defaultobj *obj = prop->obj;

			if (obj->type == OBJTYPE_WEAPON) {
				objFreePermanently(obj, true);
			}
		}

		propnum++;
	}

	bgunSetPassiveMode(true);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
	playerDisplayHealth();
	g_Vars.currentplayer->bondhealth = 1;
}

static bool htIsUnlocked(u32 value)
{
	switch (value) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		return true;
	}

	return false;
}

s32 htGetNumUnlocked(void)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < 7; i++) {
		if (htIsUnlocked(i)) {
			count++;
		}
	}

	return count;
}

s32 htGetIndexBySlot(s32 slot)
{
	s32 index = -1;
	s32 i;

	for (i = 0; i < 7; i++) {
		if (htIsUnlocked(i)) {
			index++;
		}

		if (index == slot) {
			return i;
		}
	}

	return 0;
}

char *htGetName(s32 index)
{
	return langGet(L_MISC_410 + index);
}

static u32 func0f1a25c0(s32 index)
{
	return STAGEFLAG_CI_IN_HOLO1 << index;
}

char *htGetDescription(void)
{
	return langGet(L_MISC_336 + htGetIndexBySlot(var80088bb4));
}

char *htGetTip1(void)
{
	return langGet(L_MISC_343 + htGetIndexBySlot(var80088bb4));
}

char *htGetTip2(void)
{
	return langGet(L_MISC_350 + htGetIndexBySlot(var80088bb4));
}

static void frGetGoalTargetsText(char *buffer)
{
	// "GOAL TARGETS:"
	sprintf(buffer, "%s %d\n", langGet(L_MISC_417), g_FrData.goaltargets);
}

static void frGetTargetsDestroyedValue(char *buffer)
{
	sprintf(buffer, "%02d\n", g_FrData.targetsdestroyed);
}

static void frGetScoreValue(char *buffer)
{
	sprintf(buffer, "%03d\n", g_FrData.score);
}

static void frGetGoalScoreText(char *buffer)
{
	if (g_FrData.goalscore) {
		// "GOAL SCORE:"
		sprintf(buffer, "%s %d\n", langGet(L_MISC_418), g_FrData.goalscore);
	} else {
		sprintf(buffer, "");
	}
}

static f32 frGetAccuracy(char *buffer)
{
	f32 sum = (g_FrData.numhitsring3
		+ g_FrData.numhitsbullseye
		+ g_FrData.numhitsring1
		+ g_FrData.numhitsring2) * 100.0f;
	f32 accuracy = 100.0f;

	if (g_FrData.numshots) {
		accuracy = sum / (f32)g_FrData.numshots;
	}

	if (accuracy > 100.0f) {
		accuracy = 100.0f;
	}

	sprintf(buffer, "%s%s%.2f%%\n", "", "", accuracy);

	return accuracy;
}

static bool frGetMinAccuracy(char *buffer, f32 accuracy)
{
	// "MIN ACCURACY:"
	sprintf(buffer, "%s %d%%\n", langGet(L_MISC_419), g_FrData.goalaccuracy);

	return accuracy < g_FrData.goalaccuracy;
}

/**
 * Formats either the time taken or time limit into buffer, and returns true if
 * the time should induce a failure.
 *
 * The time limit will be used if it exists and the time take exceeds it,
 * otherwise time taken will be used.
 *
 * Negative time taken (such as when the player aborts before the challenge
 * starts) is wrapped to positive and will induce a failure.
 */
static bool frFormatTime(char *buffer)
{
	s32 mins = 0;
	s32 mult = 1;
	f32 secs = g_FrData.timetaken / TICKS(60.0f);
	u8 failed = false;

	if (g_FrData.timelimit != 255 && secs >= g_FrData.timelimit) {
		failed = true;
		secs = g_FrData.timelimit;
	} else if (g_FrData.timetaken < 0) {
		failed = true;
	}

	if (secs < 0) {
		mult = -1;
		secs = -secs;
	}

	if (secs >= 60) {
		while (secs >= 60) {
			secs -= 60;
			mins++;
		}
	}

	sprintf(buffer, "%02d:%02d\n", mult * mins, (s32)secs);

	return failed;
}

static bool frGetHudMiddleSubtext(char *buffer)
{
	s32 secs;
	s32 mins;

	if (g_FrData.timetaken < TICKS(-180)) {
		sprintf(buffer, "%s", langGet(L_MISC_420)); // "FIRE TO START"
		return false;
	}

	if (g_FrData.timetaken < 0) {
		sprintf(buffer, "%s", langGet(L_MISC_421)); // "GET READY!"
		return true;
	}

	if (g_FrData.timelimit == 255) {
		return false;
	}

	secs = g_FrData.timelimit;
	mins = 0;

	if (secs >= 60) {
		while (secs >= 60) {
			secs -= 60;
			mins++;
		}
	}

	sprintf(buffer, "%s %02d:%02d\n", langGet(L_MISC_422), mins, secs); // "LIMIT:"
	return true;
}

static bool frGetFeedback(char *scorebuffer, char *zonebuffer)
{
	if (g_FrData.feedbackzone) {
		g_FrData.feedbackttl -= g_Vars.lvupdate60;

		if (g_FrData.feedbackttl <= 0) {
			g_FrData.feedbackzone = 0;
			g_FrData.feedbackttl = 0;
			return false;
		}

		if (g_FrData.feedbackzone == FRZONE_EXPLODE) {
			sprintf(scorebuffer, "010\n");
		} else {
			sprintf(scorebuffer, "%03d\n", g_FrData.feedbackzone);
		}

		switch (g_FrData.feedbackzone) {
		case FRZONE_RING3:
			sprintf(zonebuffer, "%s", langGet(L_MISC_423));
			return true;
		case FRZONE_RING2:
			sprintf(zonebuffer, "%s", langGet(L_MISC_424));
			return true;
		case FRZONE_RING1:
			sprintf(zonebuffer, "%s", langGet(L_MISC_425));
			return true;
		case FRZONE_BULLSEYE:
			sprintf(zonebuffer, "%s", langGet(L_MISC_426));
			return true;
		case FRZONE_EXPLODE:
			sprintf(zonebuffer, "%s", langGet(L_MISC_427));
			return true;
		}

		sprintf(zonebuffer, "\n");
		return true;
	}

	return false;
}

static Gfx *frRenderHudElement(Gfx *gdl, s32 x, s32 y, char *string1, char *string2, u32 colour, u8 alpha)
{
	s32 textheight;
	s32 textwidth;
	s32 x2;
	s32 y2;

	u32 halfalpha = alpha >> 1;
	u32 fullcolour = (colour & 0xffffff00) | alpha;

	textMeasure(&textheight, &textwidth, string1, g_CharsHandelGothicMd, g_FontHandelGothicMd, 0);

	x2 = x - (textwidth >> 1);
	y2 = y;
	gdl = text0f153858(gdl, &x2, &y2, &textwidth, &textheight);

	gdl = textRender(gdl, &x2, &y2, string1,
			g_CharsHandelGothicMd, g_FontHandelGothicMd, fullcolour, halfalpha, g_ViBackData->x, g_ViBackData->y, 0, 0);

	if (string2) {
		textMeasure(&textheight, &textwidth, string2, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x2 = x - (textwidth >> 1);
		y2 = y + 17;
		gdl = text0f153858(gdl, &x2, &y2, &textwidth, &textheight);

		gdl = textRender(gdl, &x2, &y2, string2,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, fullcolour, halfalpha, g_ViBackData->x, g_ViBackData->y, 0, 0);
	}

	return gdl;
}

Gfx *frRenderHud(Gfx *gdl)
{
	char string1[128];
	char string2[128];
	bool red;
	bool exists;
	s32 alpha = 0xa0;
	f32 mult;

	if (g_ViBackData->viewx > 400) {
		mult = 2;
	} else {
		mult = 1;
	}

	if (!g_FrIsValidWeapon && g_FrData.menucountdown <= 0) {
		return gdl;
	}

	if (g_FrData.menucountdown != 0) {
		alpha = (f32)(g_FrData.menucountdown * 160) / TICKS(60.0f);
	}

	gdl = text0f153628(gdl);

	// Time
	red = frFormatTime(string1);
	exists = frGetHudMiddleSubtext(string2);

	gdl = frRenderHudElement(gdl, g_ViBackData->viewx >> 1, g_ViBackData->viewtop + 12,
			string1, exists ? string2 : NULL,
			red ? 0xff0000a0 : 0x00ff00a0,
			alpha);

	// Score
	frGetScoreValue(string1);
	frGetGoalScoreText(string2);
	gdl = frRenderHudElement(gdl, g_ViBackData->viewleft + 65.0f * mult, g_ViBackData->viewtop + 12,
			string1, string2, 0x00ff00a0, alpha);

	// Feedback
	if (frGetFeedback(string1, string2)) {
		gdl = frRenderHudElement(gdl,g_ViBackData->viewleft + 65.0f * mult, g_ViBackData->viewtop + 40,
				string1, string2, 0x00ff00a0, alpha);
	}

	if (g_FrData.goalaccuracy > 0) {
		red = frGetMinAccuracy(string2, frGetAccuracy(string1));

		gdl = frRenderHudElement(gdl, g_ViBackData->viewleft + g_ViBackData->viewx - 70.0f * mult, g_ViBackData->viewtop + 12,
				string1, string2,
				red ? 0xff0000a0 : 0x00ff00a0,
				alpha);
	} else if (g_FrData.goaltargets != 255) {
		frGetTargetsDestroyedValue(string1);
		frGetGoalTargetsText(string2);

		if (mult == 2) {
			mult = 2.4;
		}

		gdl = frRenderHudElement(gdl, g_ViBackData->viewleft + g_ViBackData->viewx - 70.0f * mult, g_ViBackData->viewtop + 12,
				string1, string2, 0x00ff00a0, alpha);
	}

	return text0f153780(gdl);
}
