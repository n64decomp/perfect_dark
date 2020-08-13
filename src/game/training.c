#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/data/data_02e820.h"
#include "game/dlights.h"
#include "game/game_0601b0.h"
#include "game/game_092610.h"
#include "game/game_095320.h"
#include "game/game_096750.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b63b0.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/game_111600.h"
#include "game/explosion.h"
#include "game/game_150820.h"
#include "game/game_1531a0.h"
#include "game/game_157db0.h"
#include "game/training.h"
#include "game/game_1a3340.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/pad.h"
#include "game/padhalllv.h"
#include "game/propobj.h"
#include "game/wallhit.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "types.h"

#define FRSCRIPTINDEX_WEAPONS 0x00
#define FRSCRIPTINDEX_TARGETS 0x22
#define FRSCRIPTINDEX_HELP    0x71

extern u8 *_firingrangeSegmentRomStart;
extern u8 *_firingrangeSegmentRomEnd;

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

bool ciIsTourDone(void)
{
	return savefileHasFlag(SAVEFILEFLAG_CI_TOUR_DONE);
}

u8 ciGetFiringRangeScore(s32 weaponindex)
{
	// Data at firingrangescores is a u8 array where each score uses 2 bits
	return (g_SoloSaveFile.firingrangescores[weaponindex >> 2] >> (weaponindex % 4) * 2) & 3;
}

void frSaveScoreIfBest(s32 weaponindex, s32 difficulty)
{
	if (ciGetFiringRangeScore(weaponindex) < difficulty) {
		u32 byteindex = weaponindex >> 2;
		u32 shiftamount = (weaponindex % 4) * 2;
		u32 value = g_SoloSaveFile.firingrangescores[byteindex];
		u32 mask = (1 << shiftamount) + (1 << (shiftamount + 1));

		value &= 255 - mask;
		value += (difficulty << shiftamount) & mask;

		g_SoloSaveFile.firingrangescores[byteindex] = value;
	}
}

s32 func0f19ca78(u32 weaponnum)
{
	s32 slot = -1;
	s32 i;

	for (i = 0; i <= WEAPON_HORIZONSCANNER; i++) {
		switch (i) {
		case WEAPON_FALCON2:
		case WEAPON_FALCON2_SCOPE:
		case WEAPON_FALCON2_SILENCER:
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
		case WEAPON_K7AVENGER:
		case WEAPON_AR34:
		case WEAPON_SUPERDRAGON:
		case WEAPON_SHOTGUN:
		case WEAPON_SNIPERRIFLE:
		case WEAPON_FARSIGHTXR20:
		case WEAPON_CROSSBOW:
		case WEAPON_TRANQUILIZER:
		case WEAPON_REAPER:
		case WEAPON_DEVASTATOR:
		case WEAPON_ROCKETLAUNCHER:
		case WEAPON_SLAYER:
		case WEAPON_COMBATKNIFE:
		case WEAPON_LASER:
		case WEAPON_GRENADE:
		case WEAPON_TIMEDMINE:
		case WEAPON_PROXIMITYMINE:
		case WEAPON_REMOTEMINE:
			slot++;
		}

		if (i == weaponnum) {
			return slot;
		}
	}

	return -1;
}

u8 frIsWeaponFound(s32 weaponnum)
{
	if (weaponnum <= WEAPON_UNARMED) {
		return true;
	}

	if (weaponnum < (s32)sizeof(g_SoloSaveFile.weaponsfound) * 8) {
		u32 byteindex = weaponnum >> 3;
		return g_SoloSaveFile.weaponsfound[byteindex] & (1 << (weaponnum % 8));
	}

	return false;
}

void frSetWeaponFound(s32 weaponnum)
{
	if (weaponnum < (s32)sizeof(g_SoloSaveFile.weaponsfound) * 8) {
		u32 byteindex = weaponnum >> 3;
		u32 value = g_SoloSaveFile.weaponsfound[byteindex];

		value |= (1 << (weaponnum % 8));

		g_SoloSaveFile.weaponsfound[byteindex] = value;
	}
}

s32 ciIsStageComplete(s32 stageindex)
{
	return g_SoloSaveFile.besttimes[stageindex][0]
		|| g_SoloSaveFile.besttimes[stageindex][1]
		|| g_SoloSaveFile.besttimes[stageindex][2];
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

bool frIsWeaponAvailable(s32 weapon)
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
	case WEAPON_CALLISTONTG:      return 10;
	case WEAPON_RCP120:           return 11;
	case WEAPON_LAPTOPGUN:        return 12;
	case WEAPON_DRAGON:           return 13;
	case WEAPON_K7AVENGER:        return 14;
	case WEAPON_AR34:             return 15;
	case WEAPON_SUPERDRAGON:      return 16;
	case WEAPON_SHOTGUN:          return 17;
	case WEAPON_SNIPERRIFLE:      return 18;
	case WEAPON_FARSIGHTXR20:     return 19;
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

u32 frGetWeaponScriptIndex(u32 weaponnum)
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
	case WEAPON_CALLISTONTG:      return 11;
	case WEAPON_RCP120:           return 12;
	case WEAPON_LAPTOPGUN:        return 13;
	case WEAPON_DRAGON:           return 14;
	case WEAPON_K7AVENGER:        return 15;
	case WEAPON_AR34:             return 16;
	case WEAPON_SUPERDRAGON:      return 17;
	case WEAPON_SHOTGUN:          return 18;
	case WEAPON_SNIPERRIFLE:      return 19;
	case WEAPON_FARSIGHTXR20:     return 20;
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

void frInitLighting(void)
{
	if (g_FrData.donelighting == false) {
		s32 roomnum;

		for (roomnum = 7; roomnum < 10; roomnum++) {
			roomSetLighting(roomnum, LIGHTOP_3, 50, 100, 32);
		}

		roomSetLighting(CIROOM_FIRINGRANGE, LIGHTOP_3, 25, 100, 32);

		g_FrData.donelighting = true;

		audioStart(var80095200, 0x5d5, NULL, -1, -1, -1, -1, -1);
	}

	chrSetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
}

void frRestoreLighting(void)
{
	if (g_FrData.donelighting == true) {
		s32 roomnum;

		for (roomnum = 7; roomnum < 10; roomnum++) {
			roomSetLighting(roomnum, LIGHTOP_3, 100, 50, 8);
		}

		roomSetLighting(CIROOM_FIRINGRANGE, LIGHTOP_3, 100, 25, 8);

		g_FrData.donelighting = false;

		audioStart(var80095200, 0x5d6, NULL, -1, -1, -1, -1, -1);
	}
}

void frUnloadData(void)
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

void *frLoadRomData(u32 len)
{
	g_FrRomData = malloc(ALIGN16(len), 4);

	if (g_FrRomData) {
		return func0000d488(g_FrRomData, &_firingrangeSegmentRomStart, len);
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

u32 frGetDifficulty(void)
{
	return g_FrData.difficulty;
}

void frInitDefaults(void)
{
	s32 i;
	struct pad pad;

	g_FrNumSounds = 0;

	padUnpack(g_FrPads[0], PADFIELD_POS, &pad);

	g_FrData.maxactivetargets = 0;
	g_FrData.goalscore = 0;
	g_FrData.timelimit = 200;
	g_FrData.ammolimit = 255;
	g_FrData.sdgrenadelimit = 255;
	g_FrData.goalaccuracy = 0;
	g_FrData.goaltargets = 255;
	g_FrData.speed = 1;

	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		g_FrData.targets[i].dstpos.x = pad.pos.x;
		g_FrData.targets[i].dstpos.y = pad.pos.y;
		g_FrData.targets[i].dstpos.z = pad.pos.z;
		g_FrData.targets[i].dstpos.z += 6.0f * i;

		g_FrData.targets[i].inuse = false;
		g_FrData.targets[i].rotateoncloak = false;
		g_FrData.targets[i].destroyed = false;
		g_FrData.targets[i].damage = 0;
		g_FrData.targets[i].scriptoffset = 0;

		g_FrData.targets[i].travelspeed = 0;
		g_FrData.targets[i].scriptsleep = SECSTOFRAMES60(255);
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

		func0f13e40c(g_FrData.targets[i].prop, false);
		func0f13e40c(g_FrData.targets[i].prop, true);
	}

	g_FrData.timetaken = -240;
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

u32 frResolveFrPad(u32 arg0)
{
	switch (arg0) {
	case 31: return random() % 9 + 4;  // 4 - 12
	case 32: return random() % 9 + 13; // 13 - 21
	case 33: return random() % 9 + 22; // 22 - 30
	case 34: return random() % 27 + 4; // 4 - 30
	}

	return g_FrData.padindexoffset + arg0;
}

bool frIsDifficulty(u32 flags)
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

GLOBAL_ASM(
glabel frExecuteWeaponScript
.late_rodata
glabel var7f1b93bc
.word frExecuteWeaponScript+0xc4 # f19d9d0
glabel var7f1b93c0
.word frExecuteWeaponScript+0x1f4 # f19db00
glabel var7f1b93c4
.word frExecuteWeaponScript+0x24c # f19db58
glabel var7f1b93c8
.word frExecuteWeaponScript+0x278 # f19db84
glabel var7f1b93cc
.word frExecuteWeaponScript+0x2ac # f19dbb8
glabel var7f1b93d0
.word frExecuteWeaponScript+0x360 # f19dc6c
glabel var7f1b93d4
.word frExecuteWeaponScript+0x3b8 # f19dcc4
glabel var7f1b93d8
.word frExecuteWeaponScript+0x3dc # f19dce8
glabel var7f1b93dc
.word frExecuteWeaponScript+0x400 # f19dd0c
glabel var7f1b93e0
.word frExecuteWeaponScript+0x310 # f19dc1c
glabel var7f1b93e4
.word frExecuteWeaponScript+0xac # f19d9b8
glabel var7f1b93e8
.word frExecuteWeaponScript+0x218 # f19db24
glabel var7f1b93ec
.word 0x3dcccccd
.text
/*  f19d90c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f19d910:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19d914:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f19d918:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f19d91c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f19d920:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f19d924:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f19d928:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19d92c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f19d930:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19d934:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19d938:	0480012e */ 	bltz	$a0,.L0f19ddf4
/*  f19d93c:	00009025 */ 	or	$s2,$zero,$zero
/*  f19d940:	28810022 */ 	slti	$at,$a0,0x22
/*  f19d944:	1020012b */ 	beqz	$at,.L0f19ddf4
/*  f19d948:	3c0e8009 */ 	lui	$t6,%hi(g_FrScriptOffsets)
/*  f19d94c:	8dce8800 */ 	lw	$t6,%lo(g_FrScriptOffsets)($t6)
/*  f19d950:	00047840 */ 	sll	$t7,$a0,0x1
/*  f19d954:	3c088009 */ 	lui	$t0,%hi(g_FrRomData)
/*  f19d958:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f19d95c:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f19d960:	8d088810 */ 	lw	$t0,%lo(g_FrRomData)($t0)
/*  f19d964:	24010013 */ 	addiu	$at,$zero,0x13
/*  f19d968:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f19d96c:	0328a021 */ 	addu	$s4,$t9,$t0
/*  f19d970:	92890000 */ 	lbu	$t1,0x0($s4)
/*  f19d974:	02808821 */ 	addu	$s1,$s4,$zero
/*  f19d978:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f19d97c:	1121011d */ 	beq	$t1,$at,.L0f19ddf4
/*  f19d980:	312200ff */ 	andi	$v0,$t1,0xff
/*  f19d984:	3c10800b */ 	lui	$s0,%hi(g_FrData)
/*  f19d988:	2610cd20 */ 	addiu	$s0,$s0,%lo(g_FrData)
/*  f19d98c:	241700ff */ 	addiu	$s7,$zero,0xff
/*  f19d990:	2415003c */ 	addiu	$s5,$zero,0x3c
/*  f19d994:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f19d998:	2c41000c */ 	sltiu	$at,$v0,0xc
.L0f19d99c:
/*  f19d99c:	10200111 */ 	beqz	$at,.L0f19dde4
/*  f19d9a0:	00025080 */ 	sll	$t2,$v0,0x2
/*  f19d9a4:	3c017f1c */ 	lui	$at,%hi(var7f1b93bc)
/*  f19d9a8:	002a0821 */ 	addu	$at,$at,$t2
/*  f19d9ac:	8c2a93bc */ 	lw	$t2,%lo(var7f1b93bc)($at)
/*  f19d9b0:	01400008 */ 	jr	$t2
/*  f19d9b4:	00000000 */ 	nop
/*  f19d9b8:	922b0001 */ 	lbu	$t3,0x1($s1)
/*  f19d9bc:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f19d9c0:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f19d9c4:	a20b0470 */ 	sb	$t3,0x470($s0)
/*  f19d9c8:	10000106 */ 	b	.L0f19dde4
/*  f19d9cc:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19d9d0:	0fc67629 */ 	jal	frIsDifficulty
/*  f19d9d4:	92240004 */ 	lbu	$a0,0x4($s1)
/*  f19d9d8:	54400006 */ 	bnezl	$v0,.L0f19d9f4
/*  f19d9dc:	920c0454 */ 	lbu	$t4,0x454($s0)
/*  f19d9e0:	26520005 */ 	addiu	$s2,$s2,0x5
/*  f19d9e4:	26310005 */ 	addiu	$s1,$s1,0x5
/*  f19d9e8:	100000fe */ 	b	.L0f19dde4
/*  f19d9ec:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19d9f0:	920c0454 */ 	lbu	$t4,0x454($s0)
.L0f19d9f4:
/*  f19d9f4:	29810012 */ 	slti	$at,$t4,0x12
/*  f19d9f8:	5020003e */ 	beqzl	$at,.L0f19daf4
/*  f19d9fc:	26520005 */ 	addiu	$s2,$s2,0x5
/*  f19da00:	0fc675f6 */ 	jal	frResolveFrPad
/*  f19da04:	92240001 */ 	lbu	$a0,0x1($s1)
/*  f19da08:	920d0454 */ 	lbu	$t5,0x454($s0)
/*  f19da0c:	30580003 */ 	andi	$t8,$v0,0x3
/*  f19da10:	01b50019 */ 	multu	$t5,$s5
/*  f19da14:	00007012 */ 	mflo	$t6
/*  f19da18:	020e1821 */ 	addu	$v1,$s0,$t6
/*  f19da1c:	90790010 */ 	lbu	$t9,0x10($v1)
/*  f19da20:	3328fffc */ 	andi	$t0,$t9,0xfffc
/*  f19da24:	03084825 */ 	or	$t1,$t8,$t0
/*  f19da28:	a0690010 */ 	sb	$t1,0x10($v1)
/*  f19da2c:	920b0454 */ 	lbu	$t3,0x454($s0)
/*  f19da30:	922a0002 */ 	lbu	$t2,0x2($s1)
/*  f19da34:	01750019 */ 	multu	$t3,$s5
/*  f19da38:	00006012 */ 	mflo	$t4
/*  f19da3c:	020c6821 */ 	addu	$t5,$s0,$t4
/*  f19da40:	a1aa0012 */ 	sb	$t2,0x12($t5)
/*  f19da44:	920f0454 */ 	lbu	$t7,0x454($s0)
/*  f19da48:	922e0003 */ 	lbu	$t6,0x3($s1)
/*  f19da4c:	01f50019 */ 	multu	$t7,$s5
/*  f19da50:	0000c812 */ 	mflo	$t9
/*  f19da54:	0219c021 */ 	addu	$t8,$s0,$t9
/*  f19da58:	a30e0011 */ 	sb	$t6,0x11($t8)
/*  f19da5c:	92080454 */ 	lbu	$t0,0x454($s0)
/*  f19da60:	01150019 */ 	multu	$t0,$s5
/*  f19da64:	00004812 */ 	mflo	$t1
/*  f19da68:	02091821 */ 	addu	$v1,$s0,$t1
/*  f19da6c:	906c0010 */ 	lbu	$t4,0x10($v1)
/*  f19da70:	358a0080 */ 	ori	$t2,$t4,0x80
/*  f19da74:	a06a0010 */ 	sb	$t2,0x10($v1)
/*  f19da78:	920f0454 */ 	lbu	$t7,0x454($s0)
/*  f19da7c:	922d0004 */ 	lbu	$t5,0x4($s1)
/*  f19da80:	01f50019 */ 	multu	$t7,$s5
/*  f19da84:	0000c812 */ 	mflo	$t9
/*  f19da88:	02197021 */ 	addu	$t6,$s0,$t9
/*  f19da8c:	a1cd0040 */ 	sb	$t5,0x40($t6)
/*  f19da90:	92040454 */ 	lbu	$a0,0x454($s0)
/*  f19da94:	00950019 */ 	multu	$a0,$s5
/*  f19da98:	0000c012 */ 	mflo	$t8
/*  f19da9c:	02181821 */ 	addu	$v1,$s0,$t8
/*  f19daa0:	90650040 */ 	lbu	$a1,0x40($v1)
/*  f19daa4:	30a80008 */ 	andi	$t0,$a1,0x8
/*  f19daa8:	5100000b */ 	beqzl	$t0,.L0f19dad8
/*  f19daac:	30af0020 */ 	andi	$t7,$a1,0x20
/*  f19dab0:	906b0010 */ 	lbu	$t3,0x10($v1)
/*  f19dab4:	356c0004 */ 	ori	$t4,$t3,0x4
/*  f19dab8:	a06c0010 */ 	sb	$t4,0x10($v1)
/*  f19dabc:	92040454 */ 	lbu	$a0,0x454($s0)
/*  f19dac0:	00045100 */ 	sll	$t2,$a0,0x4
/*  f19dac4:	01445023 */ 	subu	$t2,$t2,$a0
/*  f19dac8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f19dacc:	020a1821 */ 	addu	$v1,$s0,$t2
/*  f19dad0:	90650040 */ 	lbu	$a1,0x40($v1)
/*  f19dad4:	30af0020 */ 	andi	$t7,$a1,0x20
.L0f19dad8:
/*  f19dad8:	51e00004 */ 	beqzl	$t7,.L0f19daec
/*  f19dadc:	24990001 */ 	addiu	$t9,$a0,0x1
/*  f19dae0:	a07e0011 */ 	sb	$s8,0x11($v1)
/*  f19dae4:	92040454 */ 	lbu	$a0,0x454($s0)
/*  f19dae8:	24990001 */ 	addiu	$t9,$a0,0x1
.L0f19daec:
/*  f19daec:	a2190454 */ 	sb	$t9,0x454($s0)
/*  f19daf0:	26520005 */ 	addiu	$s2,$s2,0x5
.L0f19daf4:
/*  f19daf4:	26310005 */ 	addiu	$s1,$s1,0x5
/*  f19daf8:	100000ba */ 	b	.L0f19dde4
/*  f19dafc:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19db00:	920d0448 */ 	lbu	$t5,0x448($s0)
/*  f19db04:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19db08:	01b27021 */ 	addu	$t6,$t5,$s2
/*  f19db0c:	01d4c021 */ 	addu	$t8,$t6,$s4
/*  f19db10:	93080001 */ 	lbu	$t0,0x1($t8)
/*  f19db14:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19db18:	a2080000 */ 	sb	$t0,0x0($s0)
/*  f19db1c:	100000b1 */ 	b	.L0f19dde4
/*  f19db20:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19db24:	92090448 */ 	lbu	$t1,0x448($s0)
/*  f19db28:	33d600ff */ 	andi	$s6,$s8,0xff
/*  f19db2c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19db30:	01325821 */ 	addu	$t3,$t1,$s2
/*  f19db34:	01746021 */ 	addu	$t4,$t3,$s4
/*  f19db38:	91820001 */ 	lbu	$v0,0x1($t4)
/*  f19db3c:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19db40:	18400003 */ 	blez	$v0,.L0f19db50
/*  f19db44:	00000000 */ 	nop
/*  f19db48:	10000001 */ 	b	.L0f19db50
/*  f19db4c:	305600ff */ 	andi	$s6,$v0,0xff
.L0f19db50:
/*  f19db50:	100000a4 */ 	b	.L0f19dde4
/*  f19db54:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19db58:	920a0448 */ 	lbu	$t2,0x448($s0)
/*  f19db5c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19db60:	01527821 */ 	addu	$t7,$t2,$s2
/*  f19db64:	01f4c821 */ 	addu	$t9,$t7,$s4
/*  f19db68:	932d0001 */ 	lbu	$t5,0x1($t9)
/*  f19db6c:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19db70:	01b60019 */ 	multu	$t5,$s6
/*  f19db74:	00007012 */ 	mflo	$t6
/*  f19db78:	a60e0002 */ 	sh	$t6,0x2($s0)
/*  f19db7c:	10000099 */ 	b	.L0f19dde4
/*  f19db80:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19db84:	92180448 */ 	lbu	$t8,0x448($s0)
/*  f19db88:	240a0078 */ 	addiu	$t2,$zero,0x78
/*  f19db8c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19db90:	03124021 */ 	addu	$t0,$t8,$s2
/*  f19db94:	01144821 */ 	addu	$t1,$t0,$s4
/*  f19db98:	912b0001 */ 	lbu	$t3,0x1($t1)
/*  f19db9c:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dba0:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f19dba4:	16ec0002 */ 	bne	$s7,$t4,.L0f19dbb0
/*  f19dba8:	a20b0005 */ 	sb	$t3,0x5($s0)
/*  f19dbac:	a20a0005 */ 	sb	$t2,0x5($s0)
.L0f19dbb0:
/*  f19dbb0:	1000008c */ 	b	.L0f19dde4
/*  f19dbb4:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dbb8:	0fc6749a */ 	jal	frGetWeaponBySlot
/*  f19dbbc:	96040456 */ 	lhu	$a0,0x456($s0)
/*  f19dbc0:	00402025 */ 	or	$a0,$v0,$zero
/*  f19dbc4:	0fc2a685 */ 	jal	weaponGetAmmoType
/*  f19dbc8:	00002825 */ 	or	$a1,$zero,$zero
/*  f19dbcc:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f19dbd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f19dbd4:	920f0448 */ 	lbu	$t7,0x448($s0)
/*  f19dbd8:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19dbdc:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f19dbe0:	03346821 */ 	addu	$t5,$t9,$s4
/*  f19dbe4:	91ae0001 */ 	lbu	$t6,0x1($t5)
/*  f19dbe8:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dbec:	31c300ff */ 	andi	$v1,$t6,0xff
/*  f19dbf0:	12e30008 */ 	beq	$s7,$v1,.L0f19dc14
/*  f19dbf4:	a20e0006 */ 	sb	$t6,0x6($s0)
/*  f19dbf8:	0043082a */ 	slt	$at,$v0,$v1
/*  f19dbfc:	10200004 */ 	beqz	$at,.L0f19dc10
/*  f19dc00:	0062c023 */ 	subu	$t8,$v1,$v0
/*  f19dc04:	3c01800b */ 	lui	$at,%hi(g_FrData+0x476)
/*  f19dc08:	10000002 */ 	b	.L0f19dc14
/*  f19dc0c:	a438d196 */ 	sh	$t8,%lo(g_FrData+0x476)($at)
.L0f19dc10:
/*  f19dc10:	a6000476 */ 	sh	$zero,0x476($s0)
.L0f19dc14:
/*  f19dc14:	10000073 */ 	b	.L0f19dde4
/*  f19dc18:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dc1c:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f19dc20:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19dc24:	92080448 */ 	lbu	$t0,0x448($s0)
/*  f19dc28:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19dc2c:	01124821 */ 	addu	$t1,$t0,$s2
/*  f19dc30:	01345821 */ 	addu	$t3,$t1,$s4
/*  f19dc34:	916c0001 */ 	lbu	$t4,0x1($t3)
/*  f19dc38:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dc3c:	318300ff */ 	andi	$v1,$t4,0xff
/*  f19dc40:	12e30008 */ 	beq	$s7,$v1,.L0f19dc64
/*  f19dc44:	a20c0007 */ 	sb	$t4,0x7($s0)
/*  f19dc48:	0043082a */ 	slt	$at,$v0,$v1
/*  f19dc4c:	10200004 */ 	beqz	$at,.L0f19dc60
/*  f19dc50:	00625023 */ 	subu	$t2,$v1,$v0
/*  f19dc54:	3c01800b */ 	lui	$at,%hi(g_FrData+0x478)
/*  f19dc58:	10000002 */ 	b	.L0f19dc64
/*  f19dc5c:	a42ad198 */ 	sh	$t2,%lo(g_FrData+0x478)($at)
.L0f19dc60:
/*  f19dc60:	a6000478 */ 	sh	$zero,0x478($s0)
.L0f19dc64:
/*  f19dc64:	1000005f */ 	b	.L0f19dde4
/*  f19dc68:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dc6c:	920f0448 */ 	lbu	$t7,0x448($s0)
/*  f19dc70:	3c014f80 */ 	lui	$at,0x4f80
/*  f19dc74:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f19dc78:	03346821 */ 	addu	$t5,$t9,$s4
/*  f19dc7c:	91ae0001 */ 	lbu	$t6,0x1($t5)
/*  f19dc80:	448e2000 */ 	mtc1	$t6,$f4
/*  f19dc84:	05c10004 */ 	bgez	$t6,.L0f19dc98
/*  f19dc88:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f19dc8c:	44814000 */ 	mtc1	$at,$f8
/*  f19dc90:	00000000 */ 	nop
/*  f19dc94:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f19dc98:
/*  f19dc98:	3c017f1c */ 	lui	$at,%hi(var7f1b93ec)
/*  f19dc9c:	c42a93ec */ 	lwc1	$f10,%lo(var7f1b93ec)($at)
/*  f19dca0:	3c013f80 */ 	lui	$at,0x3f80
/*  f19dca4:	44819000 */ 	mtc1	$at,$f18
/*  f19dca8:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f19dcac:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dcb0:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19dcb4:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f19dcb8:	e604000c */ 	swc1	$f4,0xc($s0)
/*  f19dcbc:	10000049 */ 	b	.L0f19dde4
/*  f19dcc0:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dcc4:	92180448 */ 	lbu	$t8,0x448($s0)
/*  f19dcc8:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19dccc:	03124021 */ 	addu	$t0,$t8,$s2
/*  f19dcd0:	01144821 */ 	addu	$t1,$t0,$s4
/*  f19dcd4:	912b0001 */ 	lbu	$t3,0x1($t1)
/*  f19dcd8:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dcdc:	a20b0008 */ 	sb	$t3,0x8($s0)
/*  f19dce0:	10000040 */ 	b	.L0f19dde4
/*  f19dce4:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dce8:	920c0448 */ 	lbu	$t4,0x448($s0)
/*  f19dcec:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f19dcf0:	01925021 */ 	addu	$t2,$t4,$s2
/*  f19dcf4:	01547821 */ 	addu	$t7,$t2,$s4
/*  f19dcf8:	91f90001 */ 	lbu	$t9,0x1($t7)
/*  f19dcfc:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f19dd00:	a2190004 */ 	sb	$t9,0x4($s0)
/*  f19dd04:	10000037 */ 	b	.L0f19dde4
/*  f19dd08:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f19dd0c:	922d0001 */ 	lbu	$t5,0x1($s1)
/*  f19dd10:	a21e0468 */ 	sb	$s8,0x468($s0)
/*  f19dd14:	3c0e8009 */ 	lui	$t6,%hi(g_FrScriptOffsets)
/*  f19dd18:	a20d0466 */ 	sb	$t5,0x466($s0)
/*  f19dd1c:	8dce8800 */ 	lw	$t6,%lo(g_FrScriptOffsets)($t6)
/*  f19dd20:	31a300ff */ 	andi	$v1,$t5,0xff
/*  f19dd24:	24630071 */ 	addiu	$v1,$v1,0x71
/*  f19dd28:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f19dd2c:	92020448 */ 	lbu	$v0,0x448($s0)
/*  f19dd30:	3c0b8009 */ 	lui	$t3,%hi(g_FrRomData)
/*  f19dd34:	01d84021 */ 	addu	$t0,$t6,$t8
/*  f19dd38:	95090000 */ 	lhu	$t1,0x0($t0)
/*  f19dd3c:	8d6b8810 */ 	lw	$t3,%lo(g_FrRomData)($t3)
/*  f19dd40:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f19dd44:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f19dd48:	14400003 */ 	bnez	$v0,.L0f19dd58
/*  f19dd4c:	012b2821 */ 	addu	$a1,$t1,$t3
/*  f19dd50:	1000000a */ 	b	.L0f19dd7c
/*  f19dd54:	241300fb */ 	addiu	$s3,$zero,0xfb
.L0f19dd58:
/*  f19dd58:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19dd5c:	54410004 */ 	bnel	$v0,$at,.L0f19dd70
/*  f19dd60:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19dd64:	10000005 */ 	b	.L0f19dd7c
/*  f19dd68:	241300fc */ 	addiu	$s3,$zero,0xfc
/*  f19dd6c:	24010002 */ 	addiu	$at,$zero,0x2
.L0f19dd70:
/*  f19dd70:	54410003 */ 	bnel	$v0,$at,.L0f19dd80
/*  f19dd74:	a2000467 */ 	sb	$zero,0x467($s0)
/*  f19dd78:	241300fd */ 	addiu	$s3,$zero,0xfd
.L0f19dd7c:
/*  f19dd7c:	a2000467 */ 	sb	$zero,0x467($s0)
.L0f19dd80:
/*  f19dd80:	00a01025 */ 	or	$v0,$a1,$zero
.L0f19dd84:
/*  f19dd84:	920c0467 */ 	lbu	$t4,0x467($s0)
/*  f19dd88:	258a0001 */ 	addiu	$t2,$t4,0x1
/*  f19dd8c:	a20a0467 */ 	sb	$t2,0x467($s0)
/*  f19dd90:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f19dd94:	166f0011 */ 	bne	$s3,$t7,.L0f19dddc
/*  f19dd98:	00000000 */ 	nop
/*  f19dd9c:	90430001 */ 	lbu	$v1,0x1($v0)
/*  f19dda0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19dda4:	254d0001 */ 	addiu	$t5,$t2,0x1
/*  f19dda8:	286100fb */ 	slti	$at,$v1,0xfb
/*  f19ddac:	54200004 */ 	bnezl	$at,.L0f19ddc0
/*  f19ddb0:	286100fb */ 	slti	$at,$v1,0xfb
/*  f19ddb4:	a20d0467 */ 	sb	$t5,0x467($s0)
/*  f19ddb8:	90430001 */ 	lbu	$v1,0x1($v0)
/*  f19ddbc:	286100fb */ 	slti	$at,$v1,0xfb
.L0f19ddc0:
/*  f19ddc0:	14200004 */ 	bnez	$at,.L0f19ddd4
/*  f19ddc4:	00000000 */ 	nop
/*  f19ddc8:	920e0467 */ 	lbu	$t6,0x467($s0)
/*  f19ddcc:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f19ddd0:	a2180467 */ 	sb	$t8,0x467($s0)
.L0f19ddd4:
/*  f19ddd4:	10000003 */ 	b	.L0f19dde4
/*  f19ddd8:	92220000 */ 	lbu	$v0,0x0($s1)
.L0f19dddc:
/*  f19dddc:	1000ffe9 */ 	b	.L0f19dd84
/*  f19dde0:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f19dde4:
/*  f19dde4:	24010013 */ 	addiu	$at,$zero,0x13
/*  f19dde8:	5441feec */ 	bnel	$v0,$at,.L0f19d99c
/*  f19ddec:	2c41000c */ 	sltiu	$at,$v0,0xc
/*  f19ddf0:	afb30044 */ 	sw	$s3,0x44($sp)
.L0f19ddf4:
/*  f19ddf4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f19ddf8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19ddfc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19de00:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19de04:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f19de08:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f19de0c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f19de10:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f19de14:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f19de18:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f19de1c:	03e00008 */ 	jr	$ra
/*  f19de20:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

// Mismatch around d7c
//void frExecuteWeaponScript(s32 scriptindex)
//{
//	s32 offset = 0;
//
//	if (scriptindex >= FRSCRIPTINDEX_WEAPONS && scriptindex < FRSCRIPTINDEX_TARGETS) {
//		u8 *script = &g_FrRomData[g_FrScriptOffsets[scriptindex]];
//		s32 mult = 1;
//		s32 start;
//		s32 capacity;
//		s32 index;
//		u8 *subscript;
//
//		while (script[offset] != FRCMD_END) {
//			switch (script[offset]) {
//			case FRCMD_SETPADINDEXOFFSET: // f19d9b8
//				g_FrData.padindexoffset = script[offset + 1];
//				offset += 2;
//				break;
//			case FRCMD_ADDTARGET: // f19d9d0
//				if (!frIsDifficulty(script[offset + 4])) {
//					offset += 5;
//					break;
//				}
//				if (g_FrData.numtargets < ARRAYCOUNT(g_FrData.targets)) {
//					g_FrData.targets[g_FrData.numtargets].frpadindex = frResolveFrPad(script[offset + 1]);
//					g_FrData.targets[g_FrData.numtargets].scriptindex = script[offset + 2];
//					g_FrData.targets[g_FrData.numtargets].maxdamage = script[offset + 3];
//					g_FrData.targets[g_FrData.numtargets].inuse = true;
//					g_FrData.targets[g_FrData.numtargets].flags = script[offset + 4];
//
//					if (g_FrData.targets[g_FrData.numtargets].flags & FRTARGETFLAG_ROTATEONCLOAK) {
//						g_FrData.targets[g_FrData.numtargets].rotateoncloak = true;
//					}
//
//					if (g_FrData.targets[g_FrData.numtargets].flags & FRTARGETFLAG_ONEHITEXPLODE) {
//						g_FrData.targets[g_FrData.numtargets].maxdamage = 1;
//					}
//
//					g_FrData.numtargets++;
//				}
//				offset += 5;
//				break;
//			case FRCMD_SETMAXACTIVETARGETS: // f19db00
//				g_FrData.maxactivetargets = script[offset + 1 + g_FrData.difficulty];
//				offset += 4;
//				break;
//			case FRCMD_SETSCOREMULTIPLIER: // f19db24
//				if (script[offset + 1 + g_FrData.difficulty] > 0) {
//					mult = script[offset + 1 + g_FrData.difficulty];
//				} else {
//					mult = 1;
//				}
//				offset += 4;
//				break;
//			case FRCMD_SETGOALSCORE: // f19db58
//				g_FrData.goalscore = script[offset + 1 + g_FrData.difficulty] * mult;
//				offset += 4;
//				break;
//			case FRCMD_SETTIMELIMIT: // f19db84
//				g_FrData.timelimit = script[offset + 1 + g_FrData.difficulty];
//				if (g_FrData.timelimit == 255) {
//					g_FrData.timelimit = 120;
//				}
//				offset += 4;
//				break;
//			case FRCMD_SETAMMOLIMIT: // f19dbb8
//				capacity = ammotypeGetMaxCapacity(weaponGetAmmoType(frGetWeaponBySlot(g_FrData.slot), 0));
//				g_FrData.ammolimit = script[offset + 1 + g_FrData.difficulty];
//
//				if (g_FrData.ammolimit != 255) {
//					if (g_FrData.ammolimit > capacity) {
//						g_FrData.ammoextra = g_FrData.ammolimit - capacity;
//					} else {
//						g_FrData.ammoextra = 0;
//					}
//				}
//
//				offset += 4;
//				break;
//			case FRCMD_SETGRENADELIMIT: // f19dc1c
//				capacity = ammotypeGetMaxCapacity(AMMOTYPE_DEVASTATOR);
//				g_FrData.sdgrenadelimit = script[offset + 1 + g_FrData.difficulty];
//
//				if (g_FrData.sdgrenadelimit != 255) {
//					if (g_FrData.sdgrenadelimit > capacity) {
//						g_FrData.sdgrenadeextra = g_FrData.sdgrenadelimit - capacity;
//					} else {
//						g_FrData.sdgrenadeextra = 0;
//					}
//				}
//
//				offset += 4;
//				break;
//			case FRCMD_SETEXTRASPEED: // f19dc6c
//				g_FrData.speed = script[offset + 1 + g_FrData.difficulty] * 0.1f + 1.0f;
//				offset += 4;
//				break;
//			case FRCMD_SETGOALACCURACY: // f19dcc4
//				g_FrData.goalaccuracy = script[offset + 1 + g_FrData.difficulty];
//				offset += 4;
//				break;
//			case FRCMD_SETGOALTARGETS: // f19dce8
//				g_FrData.goaltargets = script[offset + 1 + g_FrData.difficulty];
//				offset += 4;
//				break;
//			case FRCMD_SETHELPSCRIPT: // f19dd0c
//				g_FrData.helpscriptindex = script[offset + 1];
//				g_FrData.helpscriptenabled = true;
//				index = FRSCRIPTINDEX_HELP + g_FrData.helpscriptindex;
//				subscript = &g_FrRomData[g_FrScriptOffsets[index]];
//				offset += 2;
//
//				// d48
//				if (g_FrData.difficulty == FRDIFFICULTY_BRONZE) {
//					start = FRCMD_IFBRONZE;
//				} else /*d58*/ if (g_FrData.difficulty == FRDIFFICULTY_SILVER) {
//					start = FRCMD_IFSILVER;
//				} else /*d6c*/ if (g_FrData.difficulty == FRDIFFICULTY_GOLD) {
//					start = FRCMD_IFGOLD;
//				}
//
//				// d7c
//				g_FrData.helpscriptoffset = 0;
//
//				while (subscript[g_FrData.helpscriptoffset++] != start);
//
//				if (subscript[g_FrData.helpscriptoffset] >= FRCMD_IFBRONZE) {
//					g_FrData.helpscriptoffset++;
//				}
//
//				if (subscript[g_FrData.helpscriptoffset] >= FRCMD_IFBRONZE) {
//					g_FrData.helpscriptoffset++;
//				}
//
//				break;
//			}
//		}
//	}
//}

void frSetTargetProps(void)
{
	s32 i;
	u32 targets[] = {
		0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x11,
		0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a,
	};

	for (i = 0; i < ARRAYCOUNT(targets); i++) {
		struct defaultobj *obj = objFindByTagId(targets[i]);

		if (obj) {
			g_FrData.targets[i].prop = obj->prop;
			obj->flags2 |= OBJFLAG2_INVISIBLE;
		}
	}
}

s32 g_FrWeaponNum = WEAPON_UNARMED;

bool frTargetIsAtScriptStart(s32 targetnum)
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
char *frGetInstructionalText(u32 index)
{
	u16 textid = (u16)(g_FrRomData[index * 2] << 8) | g_FrRomData[index * 2 + 1];

	return langGet(textid);
}

void frExecuteHelpScript(void)
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
			hudmsgCreateViaPreset(frGetInstructionalText(script[offset + 1]), HUDMSGTYPE_TRAINING);
			g_FrData.helpscriptoffset += 2;
			break;
		case FRCMD_HELPWAITSECONDS:
			g_FrData.helpscriptsleep = SECSTOFRAMES60(script[offset + 1]);
			g_FrData.helpscriptoffset += 2;
			break;
		case FRCMD_WAITUNTILSHOOT:
			if (g_FrData.numshots) {
				g_FrData.helpscriptoffset++;
			}
			break;
		}
	} else {
		g_FrData.helpscriptsleep -= g_Vars.lvupdate240_60;

		if (g_FrData.helpscriptsleep <= 0) {
			g_FrData.helpscriptsleep = 0;
		}
	}
}

GLOBAL_ASM(
glabel frExecuteTargetScript
.late_rodata
glabel var7f1b93f0
.word frExecuteTargetScript+0xa8 # f19e138
glabel var7f1b93f4
.word frExecuteTargetScript+0x254 # f19e2e4
glabel var7f1b93f8
.word frExecuteTargetScript+0x260 # f19e2f0
glabel var7f1b93fc
.word frExecuteTargetScript+0x290 # f19e320
glabel var7f1b9400
.word frExecuteTargetScript+0x33c # f19e3cc
glabel var7f1b9404
.word frExecuteTargetScript+0x33c # f19e3cc
glabel var7f1b9408
.word frExecuteTargetScript+0x33c # f19e3cc
glabel var7f1b940c
.word frExecuteTargetScript+0x8c # f19e11c
glabel var7f1b9410
.word 0xbfc90fdb
glabel var7f1b9414
.word 0xc0490fdb
glabel var7f1b9418
.word 0x3fc90fdb
glabel var7f1b941c
.word 0x40490fdb
.text
/*  f19e090:	2409003c */ 	addiu	$t1,$zero,0x3c
/*  f19e094:	00890019 */ 	multu	$a0,$t1
/*  f19e098:	3c18800b */ 	lui	$t8,%hi(g_FrData)
/*  f19e09c:	2718cd20 */ 	addiu	$t8,$t8,%lo(g_FrData)
/*  f19e0a0:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f19e0a4:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f19e0a8:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*  f19e0ac:	3c0a8009 */ 	lui	$t2,%hi(g_FrScriptOffsets)
/*  f19e0b0:	3c0e8009 */ 	lui	$t6,%hi(g_FrRomData)
/*  f19e0b4:	00007812 */ 	mflo	$t7
/*  f19e0b8:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f19e0bc:	8c670010 */ 	lw	$a3,0x10($v1)
/*  f19e0c0:	0007cfc2 */ 	srl	$t9,$a3,0x1f
/*  f19e0c4:	532000c2 */ 	beqzl	$t9,.L0f19e3d0
/*  f19e0c8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19e0cc:	90620012 */ 	lbu	$v0,0x12($v1)
/*  f19e0d0:	8d4a8800 */ 	lw	$t2,%lo(g_FrScriptOffsets)($t2)
/*  f19e0d4:	8dce8810 */ 	lw	$t6,%lo(g_FrRomData)($t6)
/*  f19e0d8:	24420022 */ 	addiu	$v0,$v0,0x22
/*  f19e0dc:	00025840 */ 	sll	$t3,$v0,0x1
/*  f19e0e0:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f19e0e4:	958d0000 */ 	lhu	$t5,0x0($t4)
/*  f19e0e8:	90660031 */ 	lbu	$a2,0x31($v1)
/*  f19e0ec:	01ae2021 */ 	addu	$a0,$t5,$t6
/*  f19e0f0:	00864021 */ 	addu	$t0,$a0,$a2
/*  f19e0f4:	910f0000 */ 	lbu	$t7,0x0($t0)
/*  f19e0f8:	25f8fff4 */ 	addiu	$t8,$t7,-12
/*  f19e0fc:	2f010008 */ 	sltiu	$at,$t8,0x8
/*  f19e100:	102000b2 */ 	beqz	$at,.L0f19e3cc
/*  f19e104:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f19e108:	3c017f1c */ 	lui	$at,%hi(var7f1b93f0)
/*  f19e10c:	00380821 */ 	addu	$at,$at,$t8
/*  f19e110:	8c3893f0 */ 	lw	$t8,%lo(var7f1b93f0)($at)
/*  f19e114:	03000008 */ 	jr	$t8
/*  f19e118:	00000000 */ 	nop
/*  f19e11c:	906a0010 */ 	lbu	$t2,0x10($v1)
/*  f19e120:	240c3bc4 */ 	addiu	$t4,$zero,0x3bc4
/*  f19e124:	ac6c0024 */ 	sw	$t4,0x24($v1)
/*  f19e128:	354b0010 */ 	ori	$t3,$t2,0x10
/*  f19e12c:	a06b0010 */ 	sb	$t3,0x10($v1)
/*  f19e130:	100000a7 */ 	b	.L0f19e3d0
/*  f19e134:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19e138:	91040001 */ 	lbu	$a0,0x1($t0)
/*  f19e13c:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f19e140:	0fc675f6 */ 	jal	frResolveFrPad
/*  f19e144:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f19e148:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f19e14c:	00403825 */ 	or	$a3,$v0,$zero
/*  f19e150:	0007c040 */ 	sll	$t8,$a3,0x1
/*  f19e154:	806d0044 */ 	lb	$t5,0x44($v1)
/*  f19e158:	3c048009 */ 	lui	$a0,%hi(g_FrPads)
/*  f19e15c:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f19e160:	144d0006 */ 	bne	$v0,$t5,.L0f19e17c
/*  f19e164:	00982021 */ 	addu	$a0,$a0,$t8
/*  f19e168:	906e0031 */ 	lbu	$t6,0x31($v1)
/*  f19e16c:	00001025 */ 	or	$v0,$zero,$zero
/*  f19e170:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*  f19e174:	10000096 */ 	b	.L0f19e3d0
/*  f19e178:	a06f0031 */ 	sb	$t7,0x31($v1)
.L0f19e17c:
/*  f19e17c:	a0670044 */ 	sb	$a3,0x44($v1)
/*  f19e180:	94848814 */ 	lhu	$a0,%lo(g_FrPads)($a0)
/*  f19e184:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19e188:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f19e18c:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f19e190:	0fc456ac */ 	jal	padUnpack
/*  f19e194:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f19e198:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*  f19e19c:	3c0140c0 */ 	lui	$at,0x40c0
/*  f19e1a0:	44814000 */ 	mtc1	$at,$f8
/*  f19e1a4:	44995000 */ 	mtc1	$t9,$f10
/*  f19e1a8:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f19e1ac:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f19e1b0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f19e1b4:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f19e1b8:	e4640018 */ 	swc1	$f4,0x18($v1)
/*  f19e1bc:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f19e1c0:	e466001c */ 	swc1	$f6,0x1c($v1)
/*  f19e1c4:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f19e1c8:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f19e1cc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f19e1d0:	3c098009 */ 	lui	$t1,%hi(g_FrNumSounds)
/*  f19e1d4:	2529880c */ 	addiu	$t1,$t1,%lo(g_FrNumSounds)
/*  f19e1d8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f19e1dc:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f19e1e0:	e4660020 */ 	swc1	$f6,0x20($v1)
/*  f19e1e4:	91040002 */ 	lbu	$a0,0x2($t0)
/*  f19e1e8:	14810005 */ 	bne	$a0,$at,.L0f19e200
/*  f19e1ec:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19e1f0:	44810000 */ 	mtc1	$at,$f0
/*  f19e1f4:	a06a0043 */ 	sb	$t2,0x43($v1)
/*  f19e1f8:	1000002f */ 	b	.L0f19e2b8
/*  f19e1fc:	e460002c */ 	swc1	$f0,0x2c($v1)
.L0f19e200:
/*  f19e200:	91220000 */ 	lbu	$v0,0x0($t1)
/*  f19e204:	240605d9 */ 	addiu	$a2,$zero,0x5d9
/*  f19e208:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19e20c:	28410003 */ 	slti	$at,$v0,0x3
/*  f19e210:	10200019 */ 	beqz	$at,.L0f19e278
/*  f19e214:	244b0001 */ 	addiu	$t3,$v0,0x1
/*  f19e218:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19e21c:	44810000 */ 	mtc1	$at,$f0
/*  f19e220:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19e224:	240dffff */ 	addiu	$t5,$zero,-1
/*  f19e228:	a12b0000 */ 	sb	$t3,0x0($t1)
/*  f19e22c:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f19e230:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f19e234:	00002025 */ 	or	$a0,$zero,$zero
/*  f19e238:	8c650014 */ 	lw	$a1,0x14($v1)
/*  f19e23c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19e240:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f19e244:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f19e248:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f19e24c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19e250:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f19e254:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f19e258:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f19e25c:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f19e260:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f19e264:	0fc24e7e */ 	jal	func0f0939f8
/*  f19e268:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f19e26c:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f19e270:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f19e274:	91040002 */ 	lbu	$a0,0x2($t0)
.L0f19e278:
/*  f19e278:	44845000 */ 	mtc1	$a0,$f10
/*  f19e27c:	3c014f80 */ 	lui	$at,0x4f80
/*  f19e280:	04810004 */ 	bgez	$a0,.L0f19e294
/*  f19e284:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f19e288:	44818000 */ 	mtc1	$at,$f16
/*  f19e28c:	00000000 */ 	nop
/*  f19e290:	46104200 */ 	add.s	$f8,$f8,$f16
.L0f19e294:
/*  f19e294:	3c014270 */ 	lui	$at,0x4270
/*  f19e298:	44812000 */ 	mtc1	$at,$f4
/*  f19e29c:	3c01800b */ 	lui	$at,0x800b
/*  f19e2a0:	c426cd2c */ 	lwc1	$f6,-0x32d4($at)
/*  f19e2a4:	46044483 */ 	div.s	$f18,$f8,$f4
/*  f19e2a8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f19e2ac:	a06e0043 */ 	sb	$t6,0x43($v1)
/*  f19e2b0:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f19e2b4:	e46a002c */ 	swc1	$f10,0x2c($v1)
.L0f19e2b8:
/*  f19e2b8:	910f0003 */ 	lbu	$t7,0x3($t0)
/*  f19e2bc:	90790031 */ 	lbu	$t9,0x31($v1)
/*  f19e2c0:	a0600042 */ 	sb	$zero,0x42($v1)
/*  f19e2c4:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f19e2c8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f19e2cc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f19e2d0:	272a0004 */ 	addiu	$t2,$t9,0x4
/*  f19e2d4:	ac780024 */ 	sw	$t8,0x24($v1)
/*  f19e2d8:	a06a0031 */ 	sb	$t2,0x31($v1)
/*  f19e2dc:	1000003c */ 	b	.L0f19e3d0
/*  f19e2e0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19e2e4:	a0600031 */ 	sb	$zero,0x31($v1)
/*  f19e2e8:	10000039 */ 	b	.L0f19e3d0
/*  f19e2ec:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19e2f0:	906c0010 */ 	lbu	$t4,0x10($v1)
/*  f19e2f4:	24d80002 */ 	addiu	$t8,$a2,0x2
/*  f19e2f8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19e2fc:	358d0010 */ 	ori	$t5,$t4,0x10
/*  f19e300:	a06d0010 */ 	sb	$t5,0x10($v1)
/*  f19e304:	910e0001 */ 	lbu	$t6,0x1($t0)
/*  f19e308:	a0780031 */ 	sb	$t8,0x31($v1)
/*  f19e30c:	01c90019 */ 	multu	$t6,$t1
/*  f19e310:	00007812 */ 	mflo	$t7
/*  f19e314:	ac6f0024 */ 	sw	$t7,0x24($v1)
/*  f19e318:	1000002e */ 	b	.L0f19e3d4
/*  f19e31c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f19e320:	00075140 */ 	sll	$t2,$a3,0x5
/*  f19e324:	05400025 */ 	bltz	$t2,.L0f19e3bc
/*  f19e328:	3c017f1c */ 	lui	$at,%hi(var7f1b9410)
/*  f19e32c:	c4309410 */ 	lwc1	$f16,%lo(var7f1b9410)($at)
/*  f19e330:	3c017f1c */ 	lui	$at,%hi(var7f1b9414)
/*  f19e334:	c4289414 */ 	lwc1	$f8,%lo(var7f1b9414)($at)
/*  f19e338:	3c017f1c */ 	lui	$at,%hi(var7f1b9418)
/*  f19e33c:	c4249418 */ 	lwc1	$f4,%lo(var7f1b9418)($at)
/*  f19e340:	3c017f1c */ 	lui	$at,%hi(var7f1b941c)
/*  f19e344:	c432941c */ 	lwc1	$f18,%lo(var7f1b941c)($at)
/*  f19e348:	e7b0005c */ 	swc1	$f16,0x5c($sp)
/*  f19e34c:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f19e350:	e7a40064 */ 	swc1	$f4,0x64($sp)
/*  f19e354:	e7b20068 */ 	swc1	$f18,0x68($sp)
/*  f19e358:	910b0001 */ 	lbu	$t3,0x1($t0)
/*  f19e35c:	27a2005c */ 	addiu	$v0,$sp,0x5c
/*  f19e360:	c46a0038 */ 	lwc1	$f10,0x38($v1)
/*  f19e364:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f19e368:	004c6821 */ 	addu	$t5,$v0,$t4
/*  f19e36c:	c5a60000 */ 	lwc1	$f6,0x0($t5)
/*  f19e370:	906c0010 */ 	lbu	$t4,0x10($v1)
/*  f19e374:	90660031 */ 	lbu	$a2,0x31($v1)
/*  f19e378:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f19e37c:	e470003c */ 	swc1	$f16,0x3c($v1)
/*  f19e380:	91190002 */ 	lbu	$t9,0x2($t0)
/*  f19e384:	910e0001 */ 	lbu	$t6,0x1($t0)
/*  f19e388:	00195100 */ 	sll	$t2,$t9,0x4
/*  f19e38c:	01595023 */ 	subu	$t2,$t2,$t9
/*  f19e390:	448a2000 */ 	mtc1	$t2,$f4
/*  f19e394:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f19e398:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f19e39c:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f19e3a0:	c7080000 */ 	lwc1	$f8,0x0($t8)
/*  f19e3a4:	358e0008 */ 	ori	$t6,$t4,0x8
/*  f19e3a8:	a06e0010 */ 	sb	$t6,0x10($v1)
/*  f19e3ac:	31cf00ef */ 	andi	$t7,$t6,0xef
/*  f19e3b0:	a06f0010 */ 	sb	$t7,0x10($v1)
/*  f19e3b4:	46124183 */ 	div.s	$f6,$f8,$f18
/*  f19e3b8:	e4660034 */ 	swc1	$f6,0x34($v1)
.L0f19e3bc:
/*  f19e3bc:	24d80003 */ 	addiu	$t8,$a2,0x3
/*  f19e3c0:	a0780031 */ 	sb	$t8,0x31($v1)
/*  f19e3c4:	10000002 */ 	b	.L0f19e3d0
/*  f19e3c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19e3cc:
/*  f19e3cc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19e3d0:
/*  f19e3d0:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f19e3d4:
/*  f19e3d4:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
/*  f19e3d8:	03e00008 */ 	jr	$ra
/*  f19e3dc:	00000000 */ 	nop
);

// Regalloc when calculating script and offset
//bool frExecuteTargetScript(s32 targetnum)
//{
//	if (g_FrData.targets[targetnum].inuse) {
//		s32 index = FRSCRIPTINDEX_TARGETS + g_FrData.targets[targetnum].scriptindex;
//		u8 *script = &g_FrRomData[g_FrScriptOffsets[index]];
//		u32 offset = g_FrData.targets[targetnum].scriptoffset;
//		struct pad pad;
//		s32 frpadnum;
//
//		switch (script[offset]) {
//		case FRCMD_END:
//			g_FrData.targets[targetnum].scriptenabled = true;
//			g_FrData.targets[targetnum].scriptsleep = SECSTOFRAMES60(255);
//			return true;
//		case FRCMD_GOTOPAD:
//			frpadnum = frResolveFrPad(script[offset + 1]);
//
//			if (frpadnum == g_FrData.targets[targetnum].frpadnum) {
//				g_FrData.targets[targetnum].scriptoffset += 4;
//				return false;
//			}
//
//			g_FrData.targets[targetnum].frpadnum = frpadnum;
//
//			padUnpack(g_FrPads[frpadnum], PADFIELD_POS, &pad);
//
//			g_FrData.targets[targetnum].dstpos.x = pad.pos.x;
//			g_FrData.targets[targetnum].dstpos.y = pad.pos.y;
//			g_FrData.targets[targetnum].dstpos.z = pad.pos.z;
//			g_FrData.targets[targetnum].dstpos.z += 6.0f * targetnum;
//
//			if (script[offset + 2] == 0xff) {
//				g_FrData.targets[targetnum].travelspeed = -1;
//				g_FrData.targets[targetnum].travelling = true;
//			} else {
//				if (g_FrNumSounds < 3) {
//					g_FrNumSounds++;
//					func0f0939f8(NULL, g_FrData.targets[targetnum].prop, 0x5d9, -1,
//							-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
//				}
//
//				g_FrData.targets[targetnum].travelspeed = (script[offset + 2] / 60.0f) * g_FrData.speed;
//				g_FrData.targets[targetnum].travelling = true;
//			}
//
//			g_FrData.targets[targetnum].scriptsleep = SECSTOFRAMES60(script[offset + 3]);
//			g_FrData.targets[targetnum].donestopsound = false;
//			g_FrData.targets[targetnum].scriptoffset += 4;
//			return true;
//		case FRCMD_RESTART:
//			g_FrData.targets[targetnum].scriptoffset = 0;
//			return true;
//		case FRCMD_WAITSECONDS:
//			g_FrData.targets[targetnum].scriptenabled = true;
//			g_FrData.targets[targetnum].scriptsleep = SECSTOFRAMES60(script[offset + 1]);
//			g_FrData.targets[targetnum].scriptoffset += 2;
//			return true;
//		case FRCMD_ROTATE:
//			if (g_FrData.targets[targetnum].rotateoncloak == false) {
//				f32 angles[4];
//				angles[0] = DEG2RAD(-90);
//				angles[1] = DEG2RAD(-180);
//				angles[2] = DEG2RAD(90);
//				angles[3] = DEG2RAD(180);
//
//				g_FrData.targets[targetnum].rotatetoangle = g_FrData.targets[targetnum].angle + angles[script[offset + 1]];
//				g_FrData.targets[targetnum].rotatespeed = angles[script[offset + 1]] / (script[offset + 2] * 15);
//				g_FrData.targets[targetnum].rotating = true;
//				g_FrData.targets[targetnum].scriptenabled = false;
//			}
//
//			g_FrData.targets[targetnum].scriptoffset += 3;
//			return true;
//		}
//	}
//
//	return true;
//}

void frHideAllTargets(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		struct prop *prop = g_FrData.targets[i].prop;
		struct defaultobj *target = prop->obj;

		target->flags2 |= OBJFLAG2_INVISIBLE;

		func0f0926bc(prop, 1, 0xffff);
	}
}

struct pospad {
	struct coord pos;
	struct pad pad;
};

/**
 * About pospad:
 * This function has a coord struct and a pad struct next to each other in the
 * stack. When using separate variables for these a mismatched is introduced
 * because the compiler stores the pos fields in callee-save fp registers
 * instead of using the stack. It can do this because pos is not referenced by
 * its address anywhere.
 *
 * Combining the two into a single struct is probably not how the original
 * source does it, but it forces the stack to be used for pos and is the only
 * way I've found that matches.
 */
void frInitTargets(void)
{
	s32 count = 0;
	s32 i;
	struct prop *prop;
	struct defaultobj *obj;
	struct pospad pospad;
	f32 sp144[16];
	f32 sp108[9];

	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
		prop = g_FrData.targets[i].prop;

		if (prop) {
			obj = prop->obj;

			setupParseObject(obj, false, true);

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

				padUnpack(g_FrPads[g_FrData.targets[i].frpadindex], PADFIELD_POS, &pospad.pad);

				pospad.pos.x = pospad.pad.pos.x;
				pospad.pos.y = pospad.pad.pos.y;
				pospad.pos.z = pospad.pad.pos.z;
				pospad.pos.z += 6.0f * i;

				frExecuteTargetScript(i);

				if (g_FrData.targets[i].travelspeed == -1) {
					pospad.pos.x = g_FrData.targets[i].dstpos.x;
					pospad.pos.y = g_FrData.targets[i].dstpos.y;
					pospad.pos.z = g_FrData.targets[i].dstpos.z;
				}

				count++;
			} else {
				obj->flags2 |= OBJFLAG2_INVISIBLE;
			}

			if (obj->flags2 & OBJFLAG2_INVISIBLE) {
				pospad.pos.x = 0.0f;
				pospad.pos.y = 5000.0f;
				pospad.pos.z = 6.0f * i;
			}

			if (g_FrData.targets[i].flags & FRTARGETFLAG_SPAWNFACINGAWAY) {
				func00016374(0.0f, sp144);
				g_FrData.targets[i].angle = M_PI;
			} else {
				func00016374(M_PI, sp144);
			}

			func00015f04(obj->model->unk14, sp144);
			func00015da0(sp144, sp108);
			func00015cd8(sp108, obj->realrot);

			prop->pos.x = pospad.pos.x;
			prop->pos.y = pospad.pos.y;
			prop->pos.z = pospad.pos.z;

			func0f069c70(obj, true, false);
		}
	}
}

void frCloseAndLockDoor(void)
{
	struct defaultobj *obj = objFindByTagId(0x91);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *)obj;
		door->keyflags |= 0x40;
		doorActivate(door, DOORMODE_CLOSING);
	}
}

void frUnlockDoor(void)
{
	struct defaultobj *obj = objFindByTagId(0x91);

	if (obj && obj->prop && obj->prop->type == PROPTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *)obj;
		door->keyflags &= ~0x40;
	}
}

GLOBAL_ASM(
glabel frLoadData
/*  f19e7a8:	3c028009 */ 	lui	$v0,%hi(g_FrDataLoaded)
/*  f19e7ac:	24428808 */ 	addiu	$v0,$v0,%lo(g_FrDataLoaded)
/*  f19e7b0:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f19e7b4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f19e7b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19e7bc:	15c0004c */ 	bnez	$t6,.L0f19e8f0
/*  f19e7c0:	3c0f007f */ 	lui	$t7,0x7f
/*  f19e7c4:	3c18007f */ 	lui	$t8,0x7f
/*  f19e7c8:	27189d20 */ 	addiu	$t8,$t8,-25312
/*  f19e7cc:	25efb270 */ 	addiu	$t7,$t7,-19856
/*  f19e7d0:	01f82023 */ 	subu	$a0,$t7,$t8
/*  f19e7d4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f19e7d8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f19e7dc:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f19e7e0:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f19e7e4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f19e7e8:	afa4002c */ 	sw	$a0,0x2c($sp)
/*  f19e7ec:	0fc67558 */ 	jal	frLoadRomData
/*  f19e7f0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19e7f4:	8faa0018 */ 	lw	$t2,0x18($sp)
/*  f19e7f8:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f19e7fc:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f19e800:	2d410013 */ 	sltiu	$at,$t2,0x13
/*  f19e804:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*  f19e808:	1420000c */ 	bnez	$at,.L0f19e83c
/*  f19e80c:	24030012 */ 	addiu	$v1,$zero,0x12
/*  f19e810:	3c028009 */ 	lui	$v0,%hi(g_FrRomData)
/*  f19e814:	8c428810 */ 	lw	$v0,%lo(g_FrRomData)($v0)
/*  f19e818:	240800fe */ 	addiu	$t0,$zero,0xfe
/*  f19e81c:	24420012 */ 	addiu	$v0,$v0,0x12
.L0f19e820:
/*  f19e820:	904b0000 */ 	lbu	$t3,0x0($v0)
/*  f19e824:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f19e828:	150b0002 */ 	bne	$t0,$t3,.L0f19e834
/*  f19e82c:	00000000 */ 	nop
/*  f19e830:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f19e834:
/*  f19e834:	1469fffa */ 	bne	$v1,$t1,.L0f19e820
/*  f19e838:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f19e83c:
/*  f19e83c:	00072040 */ 	sll	$a0,$a3,0x1
/*  f19e840:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f19e844:	348c000f */ 	ori	$t4,$a0,0xf
/*  f19e848:	3984000f */ 	xori	$a0,$t4,0xf
/*  f19e84c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f19e850:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f19e854:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f19e858:	0c0048f2 */ 	jal	malloc
/*  f19e85c:	afa9002c */ 	sw	$t1,0x2c($sp)
/*  f19e860:	3c048009 */ 	lui	$a0,%hi(g_FrScriptOffsets)
/*  f19e864:	24848800 */ 	addiu	$a0,$a0,%lo(g_FrScriptOffsets)
/*  f19e868:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f19e86c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f19e870:	240800fe */ 	addiu	$t0,$zero,0xfe
/*  f19e874:	10400015 */ 	beqz	$v0,.L0f19e8cc
/*  f19e878:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*  f19e87c:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f19e880:	3c028009 */ 	lui	$v0,%hi(g_FrRomData)
/*  f19e884:	24428810 */ 	addiu	$v0,$v0,%lo(g_FrRomData)
/*  f19e888:	2de10013 */ 	sltiu	$at,$t7,0x13
/*  f19e88c:	1420000f */ 	bnez	$at,.L0f19e8cc
/*  f19e890:	24030012 */ 	addiu	$v1,$zero,0x12
/*  f19e894:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f19e898:
/*  f19e898:	246b0001 */ 	addiu	$t3,$v1,0x1
/*  f19e89c:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f19e8a0:	932a0000 */ 	lbu	$t2,0x0($t9)
/*  f19e8a4:	550a0007 */ 	bnel	$t0,$t2,.L0f19e8c4
/*  f19e8a8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f19e8ac:	8c8c0000 */ 	lw	$t4,0x0($a0)
/*  f19e8b0:	00066840 */ 	sll	$t5,$a2,0x1
/*  f19e8b4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f19e8b8:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f19e8bc:	a5cb0000 */ 	sh	$t3,0x0($t6)
/*  f19e8c0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f19e8c4:
/*  f19e8c4:	5469fff4 */ 	bnel	$v1,$t1,.L0f19e898
/*  f19e8c8:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f19e8cc:
/*  f19e8cc:	0fc67789 */ 	jal	frSetTargetProps
/*  f19e8d0:	00000000 */ 	nop
/*  f19e8d4:	3c02800b */ 	lui	$v0,%hi(g_FrData)
/*  f19e8d8:	2442cd20 */ 	addiu	$v0,$v0,%lo(g_FrData)
/*  f19e8dc:	904f0465 */ 	lbu	$t7,0x465($v0)
/*  f19e8e0:	a4400456 */ 	sh	$zero,0x456($v0)
/*  f19e8e4:	a0400448 */ 	sb	$zero,0x448($v0)
/*  f19e8e8:	31f8ffef */ 	andi	$t8,$t7,0xffef
/*  f19e8ec:	a0580465 */ 	sb	$t8,0x465($v0)
.L0f19e8f0:
/*  f19e8f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19e8f4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f19e8f8:	03e00008 */ 	jr	$ra
/*  f19e8fc:	00000000 */ 	nop
);

//void frLoadData(void)
//{
//	// 7bc
//	if (g_FrDataLoaded == false) {
//		u32 len = (u32)&_firingrangeSegmentRomEnd - (u32)&_firingrangeSegmentRomStart;
//		u32 index = 0;
//		s32 i;
//		s32 count = 1;
//		s32 j;
//		u32 len2 = (u32)&_firingrangeSegmentRomEnd - (u32)&_firingrangeSegmentRomStart;
//
//		g_FrDataLoaded = true;
//
//		// 7ec
//		frLoadRomData(len2);
//
//		if (len > 0x12) {
//			for (i = 0x12; i != len2; i++) {
//				if (g_FrRomData[i] == 0xfe) {
//					count++;
//				}
//			}
//		}
//
//		// 83c
//		g_FrScriptOffsets = malloc(ALIGN16(count * 2), 4);
//
//		// 860
//		if (g_FrScriptOffsets) {
//			if (len > 0x12) {
//				for (j = 0x12; j != len; j++) {
//					if (g_FrRomData[j] == 0xfe) {
//						g_FrScriptOffsets[index++] = j + 1;
//					}
//				}
//			}
//		}
//
//		// 8cc
//		frSetTargetProps();
//
//		g_FrData.slot = 0;
//		g_FrData.difficulty = FRDIFFICULTY_BRONZE;
//		g_FrData.donelighting = false;
//	}
//}

u32 frInitAmmo(s32 weaponnum)
{
	u32 scriptindex;
	u32 ammotype = weaponGetAmmoType(weaponnum, 0);
	u32 capacity = ammotypeGetMaxCapacity(ammotype);

	frInitDefaults();
	scriptindex = frGetWeaponScriptIndex(weaponnum);
	frExecuteWeaponScript(scriptindex);

	if (g_FrData.ammolimit == 255) {
		currentPlayerSetAmmoQuantity(ammotype, capacity);
	} else {
		currentPlayerSetAmmoQuantity(ammotype, g_FrData.ammolimit);
	}

	if (weaponnum == WEAPON_SUPERDRAGON) {
		if (g_FrData.sdgrenadelimit == 255) {
			currentPlayerSetAmmoQuantity(AMMOTYPE_DEVASTATOR, capacity);
		} else {
			currentPlayerSetAmmoQuantity(AMMOTYPE_DEVASTATOR, g_FrData.sdgrenadelimit);
		}
	}

	return scriptindex;
}

void frBeginSession(s32 weapon)
{
	s32 i;
	struct defaultobj *obj = objFindByTagId(0x7f); // computer

	if (obj) {
		obj->flags |= OBJFLAG_CANNOT_ACTIVATE;
	}

	frCloseAndLockDoor();

	for (i = 0; i < 2; i++) {
		if (g_Vars.currentplayer->equippedammotypes[i] >= 0) {
			g_Vars.currentplayer->hands[0].loadedammo[i] = 0;
			g_Vars.currentplayer->hands[1].loadedammo[i] = 0;
		}
	}

	g_FrIsValidWeapon = frInitAmmo(weapon) == 0 ? false : true;
	frInitTargets();
	playersSetPassiveMode(false);
}

char *frGetWeaponDescription(void)
{
	u32 weapon = frGetWeaponBySlot(g_FrData.slot);

	switch (weapon) {
	case WEAPON_FALCON2:          return langGet(L_MISC(377));
	case WEAPON_FALCON2_SCOPE:    return langGet(L_MISC(378));
	case WEAPON_FALCON2_SILENCER: return langGet(L_MISC(379));
	case WEAPON_MAGSEC4:          return langGet(L_MISC(380));
	case WEAPON_MAULER:           return langGet(L_MISC(381));
	case WEAPON_PHOENIX:          return langGet(L_MISC(382));
	case WEAPON_DY357MAGNUM:      return langGet(L_MISC(383));
	case WEAPON_DY357LX:          return langGet(L_MISC(384));
	case WEAPON_CMP150:           return langGet(L_MISC(385));
	case WEAPON_CYCLONE:          return langGet(L_MISC(386));
	case WEAPON_CALLISTONTG:      return langGet(L_MISC(387));
	case WEAPON_RCP120:           return langGet(L_MISC(388));
	case WEAPON_LAPTOPGUN:        return langGet(L_MISC(389));
	case WEAPON_DRAGON:           return langGet(L_MISC(390));
	case WEAPON_K7AVENGER:        return langGet(L_MISC(391));
	case WEAPON_AR34:             return langGet(L_MISC(392));
	case WEAPON_SUPERDRAGON:      return langGet(L_MISC(393));
	case WEAPON_SHOTGUN:          return langGet(L_MISC(394));
	case WEAPON_SNIPERRIFLE:      return langGet(L_MISC(395));
	case WEAPON_FARSIGHTXR20:     return langGet(L_MISC(396));
	case WEAPON_CROSSBOW:         return langGet(L_MISC(397));
	case WEAPON_TRANQUILIZER:     return langGet(L_MISC(398));
	case WEAPON_REAPER:           return langGet(L_MISC(399));
	case WEAPON_DEVASTATOR:       return langGet(L_MISC(400));
	case WEAPON_ROCKETLAUNCHER:   return langGet(L_MISC(401));
	case WEAPON_SLAYER:           return langGet(L_MISC(402));
	case WEAPON_COMBATKNIFE:      return langGet(L_MISC(403));
	case WEAPON_LASER:            return langGet(L_MISC(404));
	case WEAPON_GRENADE:          return langGet(L_MISC(405));
	case WEAPON_NBOMB:            return langGet(L_MISC(406));
	case WEAPON_TIMEDMINE:        return langGet(L_MISC(407));
	case WEAPON_PROXIMITYMINE:    return langGet(L_MISC(408));
	case WEAPON_REMOTEMINE:       return langGet(L_MISC(409));
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
		struct defaultobj *terminal = objFindByTagId(0x7f);

		if (terminal) {
			terminal->flags &= ~OBJFLAG_CANNOT_ACTIVATE;
		}

		frUnlockDoor();

		if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKET) {
			g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
		}

		playersSetPassiveMode(true);

		g_FrIsValidWeapon = 0;

		frRestoreLighting();

		if (hidetargets) {
			frHideAllTargets();
		}

		if (g_ThrownLaptops->base.prop) {
			setupParseObjectWithArg2False(g_ThrownLaptops, true);
		}

		roomsCopy(g_Vars.currentplayer->prop->rooms, rooms);

		for (i = 0; g_Vars.currentplayer->prop->rooms[i] != -1; i++) {
			func0f1645a8(g_Vars.currentplayer->prop->rooms[i], rooms2, 10);
			func0f0657d8(rooms2, rooms, 20);
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
						setupParseObjectWithArg2False(obj, true);
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
								|| weapon->weaponnum == WEAPON_ROCKET2
								|| (weapon->weaponnum == WEAPON_DRAGON && weapon->thrown == true)
								|| (weapon->weaponnum == WEAPON_LAPTOPGUN && weapon->thrown == true)) {
							setupParseObjectWithArg2False(obj, true);
						}
					}
				}
			}

			propnumptr++;
		}

		// Remove explosions
		for (i = 0; i < g_NumExplosions; i++) {
			g_Explosions[i].age = 256;

			for (j = 0; j < 40; j++) {
				g_Explosions[i].unk08[j].unk14 = 0;
			}
		}

		// Remove smoke
		for (i = 0; i < g_NumSmokes; i++) {
			g_Smokes[i].age = 256;

			for (j = 0; j < 10; j++) {
				g_Smokes[i].smokebits[j].size = 0;
			}
		}
	}

	func0f0bb69c();

	g_Vars.currentplayer->bondhealth = 1;
}

bool frWasTooInaccurate(void)
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

void frSetFailReason(s32 failreason)
{
	frEndSession(false);

	g_FrData.failreason = frWasTooInaccurate() ? FRFAILREASON_INACCURATE : failreason;
	g_FrData.menutype = FRMENUTYPE_FAILED;
	g_FrData.menucountdown = 60;
}

void frSetCompleted(void)
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

	g_FrData.menucountdown = 60;
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

f32 frGetTargetAngleToPos(struct coord *targetpos, f32 targetangle, struct coord *pos)
{
	f32 xdiff = targetpos->x - pos->x;
	f32 zdiff = targetpos->z - pos->z;
	f32 directangle = func0f096750(xdiff, zdiff);
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

GLOBAL_ASM(
glabel frChooseAutogunTarget
.late_rodata
glabel var7f1b94b8
.word 0x4096c5bf
glabel var7f1b94bc
.word 0x3fc90fdb
.text
/*  f19f39c:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f19f3a0:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f19f3a4:	3c014e00 */ 	lui	$at,0x4e00
/*  f19f3a8:	4481b000 */ 	mtc1	$at,$f22
/*  f19f3ac:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f19f3b0:	3c017f1c */ 	lui	$at,%hi(var7f1b94b8)
/*  f19f3b4:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f19f3b8:	c43894b8 */ 	lwc1	$f24,%lo(var7f1b94b8)($at)
/*  f19f3bc:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f19f3c0:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f19f3c4:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f19f3c8:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f19f3cc:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f19f3d0:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f19f3d4:	3c017f1c */ 	lui	$at,%hi(var7f1b94bc)
/*  f19f3d8:	3c11800b */ 	lui	$s1,%hi(g_FrData)
/*  f19f3dc:	00809825 */ 	or	$s3,$a0,$zero
/*  f19f3e0:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f19f3e4:	00009025 */ 	or	$s2,$zero,$zero
/*  f19f3e8:	0000a825 */ 	or	$s5,$zero,$zero
/*  f19f3ec:	2631cd20 */ 	addiu	$s1,$s1,%lo(g_FrData)
/*  f19f3f0:	c43494bc */ 	lwc1	$f20,%lo(var7f1b94bc)($at)
/*  f19f3f4:	00008025 */ 	or	$s0,$zero,$zero
/*  f19f3f8:	27b40084 */ 	addiu	$s4,$sp,0x84
.L0f19f3fc:
/*  f19f3fc:	8e220010 */ 	lw	$v0,0x10($s1)
/*  f19f400:	000277c2 */ 	srl	$t6,$v0,0x1f
/*  f19f404:	11c00014 */ 	beqz	$t6,.L0f19f458
/*  f19f408:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f19f40c:	07000012 */ 	bltz	$t8,.L0f19f458
/*  f19f410:	00024040 */ 	sll	$t0,$v0,0x1
/*  f19f414:	05010010 */ 	bgez	$t0,.L0f19f458
/*  f19f418:	02603025 */ 	or	$a2,$s3,$zero
/*  f19f41c:	8e240014 */ 	lw	$a0,0x14($s1)
/*  f19f420:	8e250038 */ 	lw	$a1,0x38($s1)
/*  f19f424:	0fc67ca5 */ 	jal	frGetTargetAngleToPos
/*  f19f428:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f19f42c:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f19f430:	00124880 */ 	sll	$t1,$s2,0x2
/*  f19f434:	02895021 */ 	addu	$t2,$s4,$t1
/*  f19f438:	45020006 */ 	bc1fl	.L0f19f454
/*  f19f43c:	ad500000 */ 	sw	$s0,0x0($t2)
/*  f19f440:	4618003c */ 	c.lt.s	$f0,$f24
/*  f19f444:	00000000 */ 	nop
/*  f19f448:	45030004 */ 	bc1tl	.L0f19f45c
/*  f19f44c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19f450:	ad500000 */ 	sw	$s0,0x0($t2)
.L0f19f454:
/*  f19f454:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f19f458:
/*  f19f458:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19f45c:
/*  f19f45c:	2a010012 */ 	slti	$at,$s0,0x12
/*  f19f460:	1420ffe6 */ 	bnez	$at,.L0f19f3fc
/*  f19f464:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f19f468:	1a400021 */ 	blez	$s2,.L0f19f4f0
/*  f19f46c:	00008025 */ 	or	$s0,$zero,$zero
/*  f19f470:	3c04800b */ 	lui	$a0,%hi(g_FrData)
/*  f19f474:	2484cd20 */ 	addiu	$a0,$a0,%lo(g_FrData)
/*  f19f478:	27a30084 */ 	addiu	$v1,$sp,0x84
/*  f19f47c:	c6700000 */ 	lwc1	$f16,0x0($s3)
/*  f19f480:	c6720004 */ 	lwc1	$f18,0x4($s3)
/*  f19f484:	c6740008 */ 	lwc1	$f20,0x8($s3)
/*  f19f488:	2405003c */ 	addiu	$a1,$zero,0x3c
.L0f19f48c:
/*  f19f48c:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f19f490:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19f494:	01650019 */ 	multu	$t3,$a1
/*  f19f498:	00006012 */ 	mflo	$t4
/*  f19f49c:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f19f4a0:	8da20014 */ 	lw	$v0,0x14($t5)
/*  f19f4a4:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f19f4a8:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f19f4ac:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f19f4b0:	46102001 */ 	sub.s	$f0,$f4,$f16
/*  f19f4b4:	46123081 */ 	sub.s	$f2,$f6,$f18
/*  f19f4b8:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f19f4bc:	46144301 */ 	sub.s	$f12,$f8,$f20
/*  f19f4c0:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f19f4c4:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f19f4c8:	460c6202 */ 	mul.s	$f8,$f12,$f12
/*  f19f4cc:	46083380 */ 	add.s	$f14,$f6,$f8
/*  f19f4d0:	4616703c */ 	c.lt.s	$f14,$f22
/*  f19f4d4:	00000000 */ 	nop
/*  f19f4d8:	45000003 */ 	bc1f	.L0f19f4e8
/*  f19f4dc:	00000000 */ 	nop
/*  f19f4e0:	46007586 */ 	mov.s	$f22,$f14
/*  f19f4e4:	0040a825 */ 	or	$s5,$v0,$zero
.L0f19f4e8:
/*  f19f4e8:	1612ffe8 */ 	bne	$s0,$s2,.L0f19f48c
/*  f19f4ec:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f19f4f0:
/*  f19f4f0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f19f4f4:	02a01025 */ 	or	$v0,$s5,$zero
/*  f19f4f8:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f19f4fc:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f19f500:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f19f504:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f19f508:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f19f50c:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f19f510:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f19f514:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f19f518:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f19f51c:	03e00008 */ 	jr	$ra
/*  f19f520:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);

// Regalloc: s3 and s4 are swapped.
// s3 should be autogunpos and s4 should be facingtargets.
//struct prop *frChooseAutogunTarget(struct coord *autogunpos)
//{
//	f32 closestdist = 0x20000000;
//	s32 facingtargets[ARRAYCOUNT(g_FrData.targets)];
//	s32 len = 0;
//	struct prop *closesttarget = NULL;
//	s32 i;
//
//	// Make list of targets which are facing the laptop gun
//	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
//		if (g_FrData.targets[i].inuse
//				&& g_FrData.targets[i].destroyed == false
//				&& g_FrData.targets[i].active) {
//			f32 angle = frGetTargetAngleToPos(&g_FrData.targets[i].prop->pos, g_FrData.targets[i].angle, autogunpos);
//
//			//if (!(angle > BADDEG2RAD(90) && angle < BADDEG2RAD(270))) {
//			if (!(angle > 1.5707963705063f && angle < 4.7116389274597f)) {
//				facingtargets[len++] = i;
//			}
//		}
//	}
//
//	// Determine which of the facing targets is closest
//	for (i = 0; i < len; i++) {
//		struct prop *prop = g_FrData.targets[facingtargets[i]].prop;
//		f32 xdiff = prop->pos.x - autogunpos->x;
//		f32 ydiff = prop->pos.y - autogunpos->y;
//		f32 zdiff = prop->pos.z - autogunpos->z;
//		f32 dist = xdiff * xdiff + ydiff * ydiff + zdiff * zdiff;
//
//		if (dist < closestdist) {
//			closestdist = dist;
//			closesttarget = prop;
//		}
//	}
//
//	return closesttarget;
//}

bool frIsAmmoWasted(void)
{
	s32 weaponnum = frGetWeaponBySlot(g_FrData.slot);
	s32 i;
	s32 priammotype = weaponGetAmmoType(weaponnum, 0);
	s32 secammotype = weaponGetAmmoType(weaponnum, 1);
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
	ammototal[0] = ammoGetQuantity(priammotype) + ammoloaded[0];
	ammototal[1] = ammoGetQuantity(secammotype) + ammoloaded[1];

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
			if (g_Explosions[i].unk00) {
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
				func0f1645a8(g_Vars.currentplayer->prop->rooms[i], rooms10, 10);
				func0f0657d8(rooms10, rooms20, 20);
			}

			roomGetProps(rooms20, propnums, 256);
			propnumptr = propnums;

			while (*propnumptr >= 0) {
				prop = &g_Vars.props[*propnumptr];
				child = prop->child;

				if ((child && child->type == PROPTYPE_WEAPON && child->weapon->weaponnum == WEAPON_TIMEDMINE)
						|| (child && child->type == PROPTYPE_WEAPON && child->weapon->weaponnum == WEAPON_REMOTEMINE)
						|| (child && child->type == PROPTYPE_WEAPON && child->weapon->weaponnum == WEAPON_PROXIMITYMINE)
						|| (child && child->type == PROPTYPE_WEAPON && child->weapon->weaponnum == WEAPON_GRENADEROUND)) {
					return false;
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
						if (prop->obj->hidden & OBJHFLAG_00000080) {
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
							ammotype = weaponGetAmmoType(weaponnum, 0);
							hand = &g_Vars.currentplayer->hands[0];

							if (ammoGetQuantity(ammotype) + hand->loadedammo[0] == 0) {
								g_FrData.proxyendtimer = 300;
							}

							return false;
						}

						g_FrData.proxyendtimer -= g_Vars.lvupdate240_60;

						if (g_FrData.proxyendtimer <= 0) {
							// Timer has just hit zero - deactivate (or explode?) all mines
							for (i = 0; i < ARRAYCOUNT(g_ProxyMines); i++) {
								if (g_ProxyMines[i]) {
									g_ProxyMines[i]->unk62 = 0;
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

GLOBAL_ASM(
glabel frTick
.late_rodata
glabel var7f1b94c0
.word 0x4012a974
glabel var7f1b94c4
.word 0x407f7642
glabel var7f1b94c8
.word 0x40490fdb
glabel var7f1b94cc
.word 0xc59c4000
glabel var7f1b94d0
.word 0x40c907a9
glabel var7f1b94d4
.word 0x40490fdb
glabel var7f1b94d8
.word 0xbd0efa35
glabel var7f1b94dc
.word 0x40490fdb
glabel var7f1b94e0
.word 0x3d0efa35
glabel var7f1b94e4
.word 0x40490fdb
.text
/*  f19f994:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f19f998:	3c0e8009 */ 	lui	$t6,%hi(g_FrIsValidWeapon)
/*  f19f99c:	91ce8804 */ 	lbu	$t6,%lo(g_FrIsValidWeapon)($t6)
/*  f19f9a0:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f19f9a4:	afb60078 */ 	sw	$s6,0x78($sp)
/*  f19f9a8:	afb50074 */ 	sw	$s5,0x74($sp)
/*  f19f9ac:	afb40070 */ 	sw	$s4,0x70($sp)
/*  f19f9b0:	afb3006c */ 	sw	$s3,0x6c($sp)
/*  f19f9b4:	afb20068 */ 	sw	$s2,0x68($sp)
/*  f19f9b8:	afb10064 */ 	sw	$s1,0x64($sp)
/*  f19f9bc:	afb00060 */ 	sw	$s0,0x60($sp)
/*  f19f9c0:	f7b80058 */ 	sdc1	$f24,0x58($sp)
/*  f19f9c4:	f7b60050 */ 	sdc1	$f22,0x50($sp)
/*  f19f9c8:	11c00014 */ 	beqz	$t6,.L0f19fa1c
/*  f19f9cc:	f7b40048 */ 	sdc1	$f20,0x48($sp)
/*  f19f9d0:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f19f9d4:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f19f9d8:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f19f9dc:	3c15800b */ 	lui	$s5,%hi(g_FrData)
/*  f19f9e0:	26b5cd20 */ 	addiu	$s5,$s5,%lo(g_FrData)
/*  f19f9e4:	8df81580 */ 	lw	$t8,0x1580($t7)
/*  f19f9e8:	00184f00 */ 	sll	$t1,$t8,0x1c
/*  f19f9ec:	0520000b */ 	bltz	$t1,.L0f19fa1c
/*  f19f9f0:	00000000 */ 	nop
/*  f19f9f4:	0fc6749a */ 	jal	frGetWeaponBySlot
/*  f19f9f8:	96a40456 */ 	lhu	$a0,0x456($s5)
/*  f19f9fc:	0fc44727 */ 	jal	currentPlayerCanHaveWeapon
/*  f19fa00:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fa04:	10400005 */ 	beqz	$v0,.L0f19fa1c
/*  f19fa08:	00000000 */ 	nop
/*  f19fa0c:	0fc6749a */ 	jal	frGetWeaponBySlot
/*  f19fa10:	96a40456 */ 	lhu	$a0,0x456($s5)
/*  f19fa14:	0fc2865b */ 	jal	currentPlayerEquipWeapon
/*  f19fa18:	00402025 */ 	or	$a0,$v0,$zero
.L0f19fa1c:
/*  f19fa1c:	3c15800b */ 	lui	$s5,%hi(g_FrData)
/*  f19fa20:	26b5cd20 */ 	addiu	$s5,$s5,%lo(g_FrData)
/*  f19fa24:	82a30464 */ 	lb	$v1,0x464($s5)
/*  f19fa28:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f19fa2c:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f19fa30:	5060006e */ 	beqzl	$v1,.L0f19fbec
/*  f19fa34:	8ec20284 */ 	lw	$v0,0x284($s6)
/*  f19fa38:	8eca0038 */ 	lw	$t2,0x38($s6)
/*  f19fa3c:	3c10800b */ 	lui	$s0,%hi(g_FrData)
/*  f19fa40:	3c11800b */ 	lui	$s1,%hi(g_FrData+0x438)
/*  f19fa44:	006a5823 */ 	subu	$t3,$v1,$t2
/*  f19fa48:	a2ab0464 */ 	sb	$t3,0x464($s5)
/*  f19fa4c:	82a30464 */ 	lb	$v1,0x464($s5)
/*  f19fa50:	2631d158 */ 	addiu	$s1,$s1,%lo(g_FrData+0x438)
/*  f19fa54:	2610cd20 */ 	addiu	$s0,$s0,%lo(g_FrData)
/*  f19fa58:	1c60000f */ 	bgtz	$v1,.L0f19fa98
/*  f19fa5c:	00000000 */ 	nop
/*  f19fa60:	92a20465 */ 	lbu	$v0,0x465($s5)
/*  f19fa64:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19fa68:	00026142 */ 	srl	$t4,$v0,0x5
/*  f19fa6c:	11810003 */ 	beq	$t4,$at,.L0f19fa7c
/*  f19fa70:	24010003 */ 	addiu	$at,$zero,0x3
/*  f19fa74:	15810008 */ 	bne	$t4,$at,.L0f19fa98
/*  f19fa78:	00000000 */ 	nop
.L0f19fa7c:
/*  f19fa7c:	8ecd0284 */ 	lw	$t5,0x284($s6)
/*  f19fa80:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f19fa84:	91ae0638 */ 	lbu	$t6,0x638($t5)
/*  f19fa88:	126e0003 */ 	beq	$s3,$t6,.L0f19fa98
/*  f19fa8c:	00000000 */ 	nop
/*  f19fa90:	a2b30464 */ 	sb	$s3,0x464($s5)
/*  f19fa94:	82a30464 */ 	lb	$v1,0x464($s5)
.L0f19fa98:
/*  f19fa98:	1c600395 */ 	bgtz	$v1,.L0f1a08f0
/*  f19fa9c:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f19faa0:	a2a00464 */ 	sb	$zero,0x464($s5)
/*  f19faa4:	8e040014 */ 	lw	$a0,0x14($s0)
.L0f19faa8:
/*  f19faa8:	02602825 */ 	or	$a1,$s3,$zero
/*  f19faac:	50800004 */ 	beqzl	$a0,.L0f19fac0
/*  f19fab0:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19fab4:	0fc249af */ 	jal	func0f0926bc
/*  f19fab8:	3406ffff */ 	dli	$a2,0xffff
/*  f19fabc:	2610003c */ 	addiu	$s0,$s0,0x3c
.L0f19fac0:
/*  f19fac0:	5611fff9 */ 	bnel	$s0,$s1,.L0f19faa8
/*  f19fac4:	8e040014 */ 	lw	$a0,0x14($s0)
/*  f19fac8:	3c02800b */ 	lui	$v0,%hi(g_FrData+0x465)
/*  f19facc:	9042d185 */ 	lbu	$v0,%lo(g_FrData+0x465)($v0)
/*  f19fad0:	00027942 */ 	srl	$t7,$v0,0x5
/*  f19fad4:	11e0000b */ 	beqz	$t7,.L0f19fb04
/*  f19fad8:	00000000 */ 	nop
/*  f19fadc:	11f30010 */ 	beq	$t7,$s3,.L0f19fb20
/*  f19fae0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f19fae4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f19fae8:	11e10012 */ 	beq	$t7,$at,.L0f19fb34
/*  f19faec:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f19faf0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f19faf4:	11e10023 */ 	beq	$t7,$at,.L0f19fb84
/*  f19faf8:	3c048009 */ 	lui	$a0,%hi(menudialog_frtraininginfo2)
/*  f19fafc:	1000037d */ 	b	.L0f1a08f4
/*  f19fb00:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fb04:
/*  f19fb04:	0fc69d55 */ 	jal	ciGetFrWeaponListMenuDialog
/*  f19fb08:	00000000 */ 	nop
/*  f19fb0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fb10:	0fc3e178 */ 	jal	func0f0f85e0
/*  f19fb14:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f19fb18:	10000376 */ 	b	.L0f1a08f4
/*  f19fb1c:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fb20:
/*  f19fb20:	24848f60 */ 	addiu	$a0,$a0,%lo(menudialog_frtraininginfo2)
/*  f19fb24:	0fc3e178 */ 	jal	func0f0f85e0
/*  f19fb28:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f19fb2c:	10000371 */ 	b	.L0f1a08f4
/*  f19fb30:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fb34:
/*  f19fb34:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19fb38:	4481c000 */ 	mtc1	$at,$f24
/*  f19fb3c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f19fb40:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f19fb44:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f19fb48:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f19fb4c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f19fb50:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f19fb54:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f19fb58:	240505db */ 	addiu	$a1,$zero,0x5db
/*  f19fb5c:	00003025 */ 	or	$a2,$zero,$zero
/*  f19fb60:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19fb64:	0c004241 */ 	jal	audioStart
/*  f19fb68:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*  f19fb6c:	3c048009 */ 	lui	$a0,%hi(g_MenuDialogFrTrainingStatsFailed)
/*  f19fb70:	24849198 */ 	addiu	$a0,$a0,%lo(g_MenuDialogFrTrainingStatsFailed)
/*  f19fb74:	0fc3e178 */ 	jal	func0f0f85e0
/*  f19fb78:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f19fb7c:	1000035d */ 	b	.L0f1a08f4
/*  f19fb80:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fb84:
/*  f19fb84:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19fb88:	4481c000 */ 	mtc1	$at,$f24
/*  f19fb8c:	240affff */ 	addiu	$t2,$zero,-1
/*  f19fb90:	240bffff */ 	addiu	$t3,$zero,-1
/*  f19fb94:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19fb98:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f19fb9c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f19fba0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f19fba4:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f19fba8:	240505dc */ 	addiu	$a1,$zero,0x5dc
/*  f19fbac:	00003025 */ 	or	$a2,$zero,$zero
/*  f19fbb0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19fbb4:	0c004241 */ 	jal	audioStart
/*  f19fbb8:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*  f19fbbc:	3c048009 */ 	lui	$a0,%hi(g_MenuDialogFrTrainingStatsCompleted)
/*  f19fbc0:	2484907c */ 	addiu	$a0,$a0,%lo(g_MenuDialogFrTrainingStatsCompleted)
/*  f19fbc4:	0fc3e178 */ 	jal	func0f0f85e0
/*  f19fbc8:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f19fbcc:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f19fbd0:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f19fbd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f19fbd8:	0fc42539 */ 	jal	func0f1094e4
/*  f19fbdc:	00003025 */ 	or	$a2,$zero,$zero
/*  f19fbe0:	10000344 */ 	b	.L0f1a08f4
/*  f19fbe4:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f19fbe8:	8ec20284 */ 	lw	$v0,0x284($s6)
.L0f19fbec:
/*  f19fbec:	3c038009 */ 	lui	$v1,%hi(g_FrIsValidWeapon)
/*  f19fbf0:	2401000a */ 	addiu	$at,$zero,0xa
/*  f19fbf4:	8c4d00bc */ 	lw	$t5,0xbc($v0)
/*  f19fbf8:	90638804 */ 	lbu	$v1,%lo(g_FrIsValidWeapon)($v1)
/*  f19fbfc:	85ae0028 */ 	lh	$t6,0x28($t5)
/*  f19fc00:	11c10024 */ 	beq	$t6,$at,.L0f19fc94
/*  f19fc04:	00000000 */ 	nop
/*  f19fc08:	10600339 */ 	beqz	$v1,.L0f1a08f0
/*  f19fc0c:	3c10800b */ 	lui	$s0,%hi(g_FrData)
/*  f19fc10:	3c11800b */ 	lui	$s1,%hi(g_FrData+0x438)
/*  f19fc14:	2631d158 */ 	addiu	$s1,$s1,%lo(g_FrData+0x438)
/*  f19fc18:	2610cd20 */ 	addiu	$s0,$s0,%lo(g_FrData)
/*  f19fc1c:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f19fc20:
/*  f19fc20:	00027fc2 */ 	srl	$t7,$v0,0x1f
/*  f19fc24:	11e0000e */ 	beqz	$t7,.L0f19fc60
/*  f19fc28:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f19fc2c:	0722000d */ 	bltzl	$t9,.L0f19fc64
/*  f19fc30:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19fc34:	92090041 */ 	lbu	$t1,0x41($s0)
/*  f19fc38:	5520000a */ 	bnezl	$t1,.L0f19fc64
/*  f19fc3c:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19fc40:	920a0043 */ 	lbu	$t2,0x43($s0)
/*  f19fc44:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f19fc48:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19fc4c:	11400004 */ 	beqz	$t2,.L0f19fc60
/*  f19fc50:	3406ffff */ 	dli	$a2,0xffff
/*  f19fc54:	a20b0041 */ 	sb	$t3,0x41($s0)
/*  f19fc58:	0fc249af */ 	jal	func0f0926bc
/*  f19fc5c:	8e040014 */ 	lw	$a0,0x14($s0)
.L0f19fc60:
/*  f19fc60:	2610003c */ 	addiu	$s0,$s0,0x3c
.L0f19fc64:
/*  f19fc64:	5611ffee */ 	bnel	$s0,$s1,.L0f19fc20
/*  f19fc68:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f19fc6c:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f19fc70:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f19fc74:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f19fc78:	0fc67b37 */ 	jal	frEndSession
/*  f19fc7c:	ac401c08 */ 	sw	$zero,0x1c08($v0)
/*  f19fc80:	00002025 */ 	or	$a0,$zero,$zero
/*  f19fc84:	0fc127d2 */ 	jal	chrUnsetStageFlag
/*  f19fc88:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19fc8c:	10000319 */ 	b	.L0f1a08f4
/*  f19fc90:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fc94:
/*  f19fc94:	50600317 */ 	beqzl	$v1,.L0f1a08f4
/*  f19fc98:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f19fc9c:	8c4c00d8 */ 	lw	$t4,0xd8($v0)
/*  f19fca0:	51800004 */ 	beqzl	$t4,.L0f19fcb4
/*  f19fca4:	8ecd0034 */ 	lw	$t5,0x34($s6)
/*  f19fca8:	0fc67b37 */ 	jal	frEndSession
/*  f19fcac:	00002025 */ 	or	$a0,$zero,$zero
/*  f19fcb0:	8ecd0034 */ 	lw	$t5,0x34($s6)
.L0f19fcb4:
/*  f19fcb4:	3c10800b */ 	lui	$s0,%hi(g_FrData)
/*  f19fcb8:	2610cd20 */ 	addiu	$s0,$s0,%lo(g_FrData)
/*  f19fcbc:	15a00018 */ 	bnez	$t5,.L0f19fd20
/*  f19fcc0:	3c11800b */ 	lui	$s1,%hi(g_FrData+0x438)
/*  f19fcc4:	2631d158 */ 	addiu	$s1,$s1,%lo(g_FrData+0x438)
/*  f19fcc8:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f19fccc:
/*  f19fccc:	000277c2 */ 	srl	$t6,$v0,0x1f
/*  f19fcd0:	11c0000e */ 	beqz	$t6,.L0f19fd0c
/*  f19fcd4:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f19fcd8:	0702000d */ 	bltzl	$t8,.L0f19fd10
/*  f19fcdc:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19fce0:	92190041 */ 	lbu	$t9,0x41($s0)
/*  f19fce4:	5720000a */ 	bnezl	$t9,.L0f19fd10
/*  f19fce8:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f19fcec:	92090043 */ 	lbu	$t1,0x43($s0)
/*  f19fcf0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f19fcf4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19fcf8:	11200004 */ 	beqz	$t1,.L0f19fd0c
/*  f19fcfc:	3406ffff */ 	dli	$a2,0xffff
/*  f19fd00:	a20a0041 */ 	sb	$t2,0x41($s0)
/*  f19fd04:	0fc249af */ 	jal	func0f0926bc
/*  f19fd08:	8e040014 */ 	lw	$a0,0x14($s0)
.L0f19fd0c:
/*  f19fd0c:	2610003c */ 	addiu	$s0,$s0,0x3c
.L0f19fd10:
/*  f19fd10:	5611ffee */ 	bnel	$s0,$s1,.L0f19fccc
/*  f19fd14:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f19fd18:	100002f6 */ 	b	.L0f1a08f4
/*  f19fd1c:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f19fd20:
/*  f19fd20:	8ecc0284 */ 	lw	$t4,0x284($s6)
/*  f19fd24:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f19fd28:	0fc677d6 */ 	jal	frExecuteHelpScript
/*  f19fd2c:	ad8b1c08 */ 	sw	$t3,0x1c08($t4)
/*  f19fd30:	92ad045a */ 	lbu	$t5,0x45a($s5)
/*  f19fd34:	51a0004b */ 	beqzl	$t5,.L0f19fe64
/*  f19fd38:	8eab044c */ 	lw	$t3,0x44c($s5)
/*  f19fd3c:	0fc6749a */ 	jal	frGetWeaponBySlot
/*  f19fd40:	96a40456 */ 	lhu	$a0,0x456($s5)
/*  f19fd44:	00409025 */ 	or	$s2,$v0,$zero
/*  f19fd48:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fd4c:	0fc2a685 */ 	jal	weaponGetAmmoType
/*  f19fd50:	00002825 */ 	or	$a1,$zero,$zero
/*  f19fd54:	00408825 */ 	or	$s1,$v0,$zero
/*  f19fd58:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f19fd5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f19fd60:	00408025 */ 	or	$s0,$v0,$zero
/*  f19fd64:	02402025 */ 	or	$a0,$s2,$zero
/*  f19fd68:	0fc2c47b */ 	jal	weaponGetAmmoByFunction
/*  f19fd6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f19fd70:	10400003 */ 	beqz	$v0,.L0f19fd80
/*  f19fd74:	00001825 */ 	or	$v1,$zero,$zero
/*  f19fd78:	10000001 */ 	b	.L0f19fd80
/*  f19fd7c:	84430008 */ 	lh	$v1,0x8($v0)
.L0f19fd80:
/*  f19fd80:	86a20476 */ 	lh	$v0,0x476($s5)
/*  f19fd84:	02038023 */ 	subu	$s0,$s0,$v1
/*  f19fd88:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19fd8c:	18400011 */ 	blez	$v0,.L0f19fdd4
/*  f19fd90:	00000000 */ 	nop
/*  f19fd94:	0fc2a5dc */ 	jal	ammoGetQuantity
/*  f19fd98:	02202025 */ 	or	$a0,$s1,$zero
/*  f19fd9c:	92a3045a */ 	lbu	$v1,0x45a($s5)
/*  f19fda0:	86ae0476 */ 	lh	$t6,0x476($s5)
/*  f19fda4:	00403025 */ 	or	$a2,$v0,$zero
/*  f19fda8:	00662821 */ 	addu	$a1,$v1,$a2
/*  f19fdac:	01c37823 */ 	subu	$t7,$t6,$v1
/*  f19fdb0:	a6af0476 */ 	sh	$t7,0x476($s5)
/*  f19fdb4:	86b80476 */ 	lh	$t8,0x476($s5)
/*  f19fdb8:	07010002 */ 	bgez	$t8,.L0f19fdc4
/*  f19fdbc:	00000000 */ 	nop
/*  f19fdc0:	a6a00476 */ 	sh	$zero,0x476($s5)
.L0f19fdc4:
/*  f19fdc4:	0fc2a58a */ 	jal	currentPlayerSetAmmoQuantity
/*  f19fdc8:	02202025 */ 	or	$a0,$s1,$zero
/*  f19fdcc:	10000006 */ 	b	.L0f19fde8
/*  f19fdd0:	24010012 */ 	addiu	$at,$zero,0x12
.L0f19fdd4:
/*  f19fdd4:	14410003 */ 	bne	$v0,$at,.L0f19fde4
/*  f19fdd8:	02202025 */ 	or	$a0,$s1,$zero
/*  f19fddc:	0fc2a58a */ 	jal	currentPlayerSetAmmoQuantity
/*  f19fde0:	02002825 */ 	or	$a1,$s0,$zero
.L0f19fde4:
/*  f19fde4:	24010012 */ 	addiu	$at,$zero,0x12
.L0f19fde8:
/*  f19fde8:	5641001d */ 	bnel	$s2,$at,.L0f19fe60
/*  f19fdec:	a2a0045a */ 	sb	$zero,0x45a($s5)
/*  f19fdf0:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f19fdf4:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19fdf8:	86a30478 */ 	lh	$v1,0x478($s5)
/*  f19fdfc:	00408025 */ 	or	$s0,$v0,$zero
/*  f19fe00:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19fe04:	18600011 */ 	blez	$v1,.L0f19fe4c
/*  f19fe08:	00000000 */ 	nop
/*  f19fe0c:	0fc2a5dc */ 	jal	ammoGetQuantity
/*  f19fe10:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19fe14:	92a3045a */ 	lbu	$v1,0x45a($s5)
/*  f19fe18:	86b90478 */ 	lh	$t9,0x478($s5)
/*  f19fe1c:	00403025 */ 	or	$a2,$v0,$zero
/*  f19fe20:	00662821 */ 	addu	$a1,$v1,$a2
/*  f19fe24:	03234823 */ 	subu	$t1,$t9,$v1
/*  f19fe28:	a6a90478 */ 	sh	$t1,0x478($s5)
/*  f19fe2c:	86aa0478 */ 	lh	$t2,0x478($s5)
/*  f19fe30:	05410002 */ 	bgez	$t2,.L0f19fe3c
/*  f19fe34:	00000000 */ 	nop
/*  f19fe38:	a6a00478 */ 	sh	$zero,0x478($s5)
.L0f19fe3c:
/*  f19fe3c:	0fc2a58a */ 	jal	currentPlayerSetAmmoQuantity
/*  f19fe40:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19fe44:	10000006 */ 	b	.L0f19fe60
/*  f19fe48:	a2a0045a */ 	sb	$zero,0x45a($s5)
.L0f19fe4c:
/*  f19fe4c:	14610003 */ 	bne	$v1,$at,.L0f19fe5c
/*  f19fe50:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f19fe54:	0fc2a58a */ 	jal	currentPlayerSetAmmoQuantity
/*  f19fe58:	02002825 */ 	or	$a1,$s0,$zero
.L0f19fe5c:
/*  f19fe5c:	a2a0045a */ 	sb	$zero,0x45a($s5)
.L0f19fe60:
/*  f19fe60:	8eab044c */ 	lw	$t3,0x44c($s5)
.L0f19fe64:
/*  f19fe64:	8ecc0038 */ 	lw	$t4,0x38($s6)
/*  f19fe68:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f19fe6c:	05a10032 */ 	bgez	$t5,.L0f19ff38
/*  f19fe70:	aead044c */ 	sw	$t5,0x44c($s5)
/*  f19fe74:	96ae0458 */ 	lhu	$t6,0x458($s5)
/*  f19fe78:	55c00026 */ 	bnezl	$t6,.L0f19ff14
/*  f19fe7c:	8eb90464 */ 	lw	$t9,0x464($s5)
/*  f19fe80:	8ea30464 */ 	lw	$v1,0x464($s5)
/*  f19fe84:	29a1ff4d */ 	slti	$at,$t5,-179
/*  f19fe88:	0003c300 */ 	sll	$t8,$v1,0xc
/*  f19fe8c:	07020016 */ 	bltzl	$t8,.L0f19fee8
/*  f19fe90:	00037ac0 */ 	sll	$t7,$v1,0xb
/*  f19fe94:	14200013 */ 	bnez	$at,.L0f19fee4
/*  f19fe98:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f19fe9c:	92a90465 */ 	lbu	$t1,0x465($s5)
/*  f19fea0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19fea4:	4481c000 */ 	mtc1	$at,$f24
/*  f19fea8:	352a0008 */ 	ori	$t2,$t1,0x8
/*  f19feac:	a2aa0465 */ 	sb	$t2,0x465($s5)
/*  f19feb0:	240bffff */ 	addiu	$t3,$zero,-1
/*  f19feb4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19feb8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f19febc:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f19fec0:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f19fec4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f19fec8:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f19fecc:	240505d4 */ 	addiu	$a1,$zero,0x5d4
/*  f19fed0:	00003025 */ 	or	$a2,$zero,$zero
/*  f19fed4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19fed8:	0c004241 */ 	jal	audioStart
/*  f19fedc:	e7b80014 */ 	swc1	$f24,0x14($sp)
/*  f19fee0:	8ea30464 */ 	lw	$v1,0x464($s5)
.L0f19fee4:
/*  f19fee4:	00037ac0 */ 	sll	$t7,$v1,0xb
.L0f19fee8:
/*  f19fee8:	05e20282 */ 	bltzl	$t7,.L0f1a08f4
/*  f19feec:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f19fef0:	8eb8044c */ 	lw	$t8,0x44c($s5)
/*  f19fef4:	2b01ff20 */ 	slti	$at,$t8,-224
/*  f19fef8:	5420027e */ 	bnezl	$at,.L0f1a08f4
/*  f19fefc:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f19ff00:	0fc674ce */ 	jal	frInitLighting
/*  f19ff04:	00000000 */ 	nop
/*  f19ff08:	1000027a */ 	b	.L0f1a08f4
/*  f19ff0c:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f19ff10:	8eb90464 */ 	lw	$t9,0x464($s5)
.L0f19ff14:
/*  f19ff14:	001952c0 */ 	sll	$t2,$t9,0xb
/*  f19ff18:	05420004 */ 	bltzl	$t2,.L0f19ff2c
/*  f19ff1c:	92ac0465 */ 	lbu	$t4,0x465($s5)
/*  f19ff20:	0fc674ce */ 	jal	frInitLighting
/*  f19ff24:	00000000 */ 	nop
/*  f19ff28:	92ac0465 */ 	lbu	$t4,0x465($s5)
.L0f19ff2c:
/*  f19ff2c:	aea0044c */ 	sw	$zero,0x44c($s5)
/*  f19ff30:	358d0008 */ 	ori	$t5,$t4,0x8
/*  f19ff34:	a2ad0465 */ 	sb	$t5,0x465($s5)
.L0f19ff38:
/*  f19ff38:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19ff3c:	4481c000 */ 	mtc1	$at,$f24
/*  f19ff40:	3c017f1c */ 	lui	$at,%hi(var7f1b94c0)
/*  f19ff44:	3c10800b */ 	lui	$s0,%hi(g_FrData)
/*  f19ff48:	3c14800b */ 	lui	$s4,%hi(g_FrData+0x438)
/*  f19ff4c:	4480b000 */ 	mtc1	$zero,$f22
/*  f19ff50:	2694d158 */ 	addiu	$s4,$s4,%lo(g_FrData+0x438)
/*  f19ff54:	2610cd20 */ 	addiu	$s0,$s0,%lo(g_FrData)
/*  f19ff58:	c43494c0 */ 	lwc1	$f20,%lo(var7f1b94c0)($at)
/*  f19ff5c:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f19ff60:
/*  f19ff60:	000277c2 */ 	srl	$t6,$v0,0x1f
/*  f19ff64:	11c000d5 */ 	beqz	$t6,.L0f1a02bc
/*  f19ff68:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f19ff6c:	070000d3 */ 	bltz	$t8,.L0f1a02bc
/*  f19ff70:	00024840 */ 	sll	$t1,$v0,0x1
/*  f19ff74:	052100d1 */ 	bgez	$t1,.L0f1a02bc
/*  f19ff78:	00009025 */ 	or	$s2,$zero,$zero
/*  f19ff7c:	a3a00123 */ 	sb	$zero,0x123($sp)
/*  f19ff80:	0fc6749a */ 	jal	frGetWeaponBySlot
/*  f19ff84:	96a40456 */ 	lhu	$a0,0x456($s5)
/*  f19ff88:	8e110014 */ 	lw	$s1,0x14($s0)
/*  f19ff8c:	304300ff */ 	andi	$v1,$v0,0xff
/*  f19ff90:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f19ff94:	10610003 */ 	beq	$v1,$at,.L0f19ffa4
/*  f19ff98:	8e330004 */ 	lw	$s3,0x4($s1)
/*  f19ff9c:	24010021 */ 	addiu	$at,$zero,0x21
/*  f19ffa0:	14610003 */ 	bne	$v1,$at,.L0f19ffb0
.L0f19ffa4:
/*  f19ffa4:	26240008 */ 	addiu	$a0,$s1,0x8
/*  f19ffa8:	0fc22af5 */ 	jal	func0f08abd4
/*  f19ffac:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f19ffb0:
/*  f19ffb0:	920a0043 */ 	lbu	$t2,0x43($s0)
/*  f19ffb4:	5140001c */ 	beqzl	$t2,.L0f1a0028
/*  f19ffb8:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f19ffbc:	920b0041 */ 	lbu	$t3,0x41($s0)
/*  f19ffc0:	51600019 */ 	beqzl	$t3,.L0f1a0028
/*  f19ffc4:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f19ffc8:	c604002c */ 	lwc1	$f4,0x2c($s0)
/*  f19ffcc:	00002025 */ 	or	$a0,$zero,$zero
/*  f19ffd0:	240605d9 */ 	addiu	$a2,$zero,0x5d9
/*  f19ffd4:	4604c032 */ 	c.eq.s	$f24,$f4
/*  f19ffd8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19ffdc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19ffe0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f19ffe4:	45030010 */ 	bc1tl	.L0f1a0028
/*  f19ffe8:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f19ffec:	a2000041 */ 	sb	$zero,0x41($s0)
/*  f19fff0:	8e050014 */ 	lw	$a1,0x14($s0)
/*  f19fff4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f19fff8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19fffc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1a0000:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1a0004:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f1a0008:	e7b80024 */ 	swc1	$f24,0x24($sp)
/*  f1a000c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a0010:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f1a0014:	e7b80030 */ 	swc1	$f24,0x30($sp)
/*  f1a0018:	e7b80034 */ 	swc1	$f24,0x34($sp)
/*  f1a001c:	0fc24e7e */ 	jal	func0f0939f8
/*  f1a0020:	e7b80038 */ 	swc1	$f24,0x38($sp)
/*  f1a0024:	c6000038 */ 	lwc1	$f0,0x38($s0)
.L0f1a0028:
/*  f1a0028:	3c017f1c */ 	lui	$at,%hi(var7f1b94c4)
/*  f1a002c:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f1a0030:	00000000 */ 	nop
/*  f1a0034:	45020008 */ 	bc1fl	.L0f1a0058
/*  f1a0038:	920e0040 */ 	lbu	$t6,0x40($s0)
/*  f1a003c:	c42694c4 */ 	lwc1	$f6,%lo(var7f1b94c4)($at)
/*  f1a0040:	4606003c */ 	c.lt.s	$f0,$f6
/*  f1a0044:	00000000 */ 	nop
/*  f1a0048:	45020003 */ 	bc1fl	.L0f1a0058
/*  f1a004c:	920e0040 */ 	lbu	$t6,0x40($s0)
/*  f1a0050:	a660004c */ 	sh	$zero,0x4c($s3)
/*  f1a0054:	920e0040 */ 	lbu	$t6,0x40($s0)
.L0f1a0058:
/*  f1a0058:	31cf0080 */ 	andi	$t7,$t6,0x80
/*  f1a005c:	51e0000a */ 	beqzl	$t7,.L0f1a0088
/*  f1a0060:	8662004c */ 	lh	$v0,0x4c($s3)
/*  f1a0064:	8e020048 */ 	lw	$v0,0x48($s0)
/*  f1a0068:	2841012c */ 	slti	$at,$v0,0x12c
/*  f1a006c:	50200006 */ 	beqzl	$at,.L0f1a0088
/*  f1a0070:	8662004c */ 	lh	$v0,0x4c($s3)
/*  f1a0074:	8ed80038 */ 	lw	$t8,0x38($s6)
/*  f1a0078:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f1a007c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f1a0080:	ae190048 */ 	sw	$t9,0x48($s0)
/*  f1a0084:	8662004c */ 	lh	$v0,0x4c($s3)
.L0f1a0088:
/*  f1a0088:	58400025 */ 	blezl	$v0,.L0f1a0120
/*  f1a008c:	93aa0123 */ 	lbu	$t2,0x123($sp)
/*  f1a0090:	16400007 */ 	bnez	$s2,.L0f1a00b0
/*  f1a0094:	3c017f1c */ 	lui	$at,%hi(var7f1b94c8)
/*  f1a0098:	c42894c8 */ 	lwc1	$f8,%lo(var7f1b94c8)($at)
/*  f1a009c:	c60a0038 */ 	lwc1	$f10,0x38($s0)
/*  f1a00a0:	460a4032 */ 	c.eq.s	$f8,$f10
/*  f1a00a4:	00000000 */ 	nop
/*  f1a00a8:	45020004 */ 	bc1fl	.L0f1a00bc
/*  f1a00ac:	92090040 */ 	lbu	$t1,0x40($s0)
.L0f1a00b0:
/*  f1a00b0:	1000001a */ 	b	.L0f1a011c
/*  f1a00b4:	a660004c */ 	sh	$zero,0x4c($s3)
/*  f1a00b8:	92090040 */ 	lbu	$t1,0x40($s0)
.L0f1a00bc:
/*  f1a00bc:	312a0020 */ 	andi	$t2,$t1,0x20
/*  f1a00c0:	5540000b */ 	bnezl	$t2,.L0f1a00f0
/*  f1a00c4:	96ac045c */ 	lhu	$t4,0x45c($s5)
/*  f1a00c8:	866b004e */ 	lh	$t3,0x4e($s3)
/*  f1a00cc:	004b082a */ 	slt	$at,$v0,$t3
/*  f1a00d0:	50200007 */ 	beqzl	$at,.L0f1a00f0
/*  f1a00d4:	96ac045c */ 	lhu	$t4,0x45c($s5)
/*  f1a00d8:	0fc6749a */ 	jal	frGetWeaponBySlot
/*  f1a00dc:	96a40456 */ 	lhu	$a0,0x456($s5)
/*  f1a00e0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f1a00e4:	5441000e */ 	bnel	$v0,$at,.L0f1a0120
/*  f1a00e8:	93aa0123 */ 	lbu	$t2,0x123($sp)
/*  f1a00ec:	96ac045c */ 	lhu	$t4,0x45c($s5)
.L0f1a00f0:
/*  f1a00f0:	8eae0450 */ 	lw	$t6,0x450($s5)
/*  f1a00f4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1a00f8:	2419003c */ 	addiu	$t9,$zero,0x3c
/*  f1a00fc:	2409000b */ 	addiu	$t1,$zero,0xb
/*  f1a0100:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f1a0104:	25cf000a */ 	addiu	$t7,$t6,0xa
/*  f1a0108:	a6ad045c */ 	sh	$t5,0x45c($s5)
/*  f1a010c:	aeaf0450 */ 	sw	$t7,0x450($s5)
/*  f1a0110:	a3b80123 */ 	sb	$t8,0x123($sp)
/*  f1a0114:	a2b90472 */ 	sb	$t9,0x472($s5)
/*  f1a0118:	a2a90471 */ 	sb	$t1,0x471($s5)
.L0f1a011c:
/*  f1a011c:	93aa0123 */ 	lbu	$t2,0x123($sp)
.L0f1a0120:
/*  f1a0120:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a0124:	26320008 */ 	addiu	$s2,$s1,0x8
/*  f1a0128:	15400009 */ 	bnez	$t2,.L0f1a0150
/*  f1a012c:	00000000 */ 	nop
/*  f1a0130:	92020011 */ 	lbu	$v0,0x11($s0)
/*  f1a0134:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a0138:	10410060 */ 	beq	$v0,$at,.L0f1a02bc
/*  f1a013c:	00000000 */ 	nop
/*  f1a0140:	920b0030 */ 	lbu	$t3,0x30($s0)
/*  f1a0144:	0162082a */ 	slt	$at,$t3,$v0
/*  f1a0148:	1420005c */ 	bnez	$at,.L0f1a02bc
/*  f1a014c:	00000000 */ 	nop
.L0f1a0150:
/*  f1a0150:	0fc1a2bd */ 	jal	func0f068af4
/*  f1a0154:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a0158:	3c038009 */ 	lui	$v1,%hi(g_FrNumSounds)
/*  f1a015c:	9063880c */ 	lbu	$v1,%lo(g_FrNumSounds)($v1)
/*  f1a0160:	00404025 */ 	or	$t0,$v0,$zero
/*  f1a0164:	5060000d */ 	beqzl	$v1,.L0f1a019c
/*  f1a0168:	c5100004 */ 	lwc1	$f16,0x4($t0)
/*  f1a016c:	920c0043 */ 	lbu	$t4,0x43($s0)
/*  f1a0170:	246dffff */ 	addiu	$t5,$v1,-1
/*  f1a0174:	3c018009 */ 	lui	$at,%hi(g_FrNumSounds)
/*  f1a0178:	11800007 */ 	beqz	$t4,.L0f1a0198
/*  f1a017c:	02202025 */ 	or	$a0,$s1,$zero
/*  f1a0180:	a02d880c */ 	sb	$t5,%lo(g_FrNumSounds)($at)
/*  f1a0184:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a0188:	3406ffff */ 	dli	$a2,0xffff
/*  f1a018c:	0fc249af */ 	jal	func0f0926bc
/*  f1a0190:	afa20118 */ 	sw	$v0,0x118($sp)
/*  f1a0194:	8fa80118 */ 	lw	$t0,0x118($sp)
.L0f1a0198:
/*  f1a0198:	c5100004 */ 	lwc1	$f16,0x4($t0)
.L0f1a019c:
/*  f1a019c:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f1a01a0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a01a4:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f1a01a8:	c5120008 */ 	lwc1	$f18,0x8($t0)
/*  f1a01ac:	2665001c */ 	addiu	$a1,$s3,0x1c
/*  f1a01b0:	26660028 */ 	addiu	$a2,$s3,0x28
/*  f1a01b4:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f1a01b8:	c504000c */ 	lwc1	$f4,0xc($t0)
/*  f1a01bc:	26670034 */ 	addiu	$a3,$s3,0x34
/*  f1a01c0:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*  f1a01c4:	c5060010 */ 	lwc1	$f6,0x10($t0)
/*  f1a01c8:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f1a01cc:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f1a01d0:	0fc54208 */ 	jal	func0f150820
/*  f1a01d4:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f1a01d8:	92af0455 */ 	lbu	$t7,0x455($s5)
/*  f1a01dc:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1a01e0:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f1a01e4:	a2b80455 */ 	sb	$t8,0x455($s5)
/*  f1a01e8:	92190040 */ 	lbu	$t9,0x40($s0)
/*  f1a01ec:	33290020 */ 	andi	$t1,$t9,0x20
/*  f1a01f0:	51200008 */ 	beqzl	$t1,.L0f1a0214
/*  f1a01f4:	920b0010 */ 	lbu	$t3,0x10($s0)
/*  f1a01f8:	8e040014 */ 	lw	$a0,0x14($s0)
/*  f1a01fc:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f1a0200:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1a0204:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f1a0208:	0fc4a640 */ 	jal	explosionCreateSimple
/*  f1a020c:	24860028 */ 	addiu	$a2,$a0,0x28
/*  f1a0210:	920b0010 */ 	lbu	$t3,0x10($s0)
.L0f1a0214:
/*  f1a0214:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f1a0218:	3c010008 */ 	lui	$at,0x8
/*  f1a021c:	316effbf */ 	andi	$t6,$t3,0xffbf
/*  f1a0220:	a20e0010 */ 	sb	$t6,0x10($s0)
/*  f1a0224:	35cf0020 */ 	ori	$t7,$t6,0x20
/*  f1a0228:	a20f0010 */ 	sb	$t7,0x10($s0)
/*  f1a022c:	8e78000c */ 	lw	$t8,0xc($s3)
/*  f1a0230:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a0234:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a0238:	0301c825 */ 	or	$t9,$t8,$at
/*  f1a023c:	ae79000c */ 	sw	$t9,0xc($s3)
/*  f1a0240:	e6360008 */ 	swc1	$f22,0x8($s1)
/*  f1a0244:	3c017f1c */ 	lui	$at,%hi(var7f1b94cc)
/*  f1a0248:	c42894cc */ 	lwc1	$f8,%lo(var7f1b94cc)($at)
/*  f1a024c:	e6360010 */ 	swc1	$f22,0x10($s1)
/*  f1a0250:	00003025 */ 	or	$a2,$zero,$zero
/*  f1a0254:	0fc1a71c */ 	jal	func0f069c70
/*  f1a0258:	e628000c */ 	swc1	$f8,0xc($s1)
/*  f1a025c:	3c03800b */ 	lui	$v1,%hi(g_FrData)
/*  f1a0260:	2463cd20 */ 	addiu	$v1,$v1,%lo(g_FrData)
/*  f1a0264:	8c620010 */ 	lw	$v0,0x10($v1)
.L0f1a0268:
/*  f1a0268:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1a026c:	05400010 */ 	bltz	$t2,.L0f1a02b0
/*  f1a0270:	00025fc2 */ 	srl	$t3,$v0,0x1f
/*  f1a0274:	1160000e */ 	beqz	$t3,.L0f1a02b0
/*  f1a0278:	00026840 */ 	sll	$t5,$v0,0x1
/*  f1a027c:	05a2000d */ 	bltzl	$t5,.L0f1a02b4
/*  f1a0280:	2463003c */ 	addiu	$v1,$v1,60
/*  f1a0284:	8c6e0014 */ 	lw	$t6,0x14($v1)
/*  f1a0288:	90780010 */ 	lbu	$t8,0x10($v1)
/*  f1a028c:	3c01fff7 */ 	lui	$at,0xfff7
/*  f1a0290:	8dc20004 */ 	lw	$v0,0x4($t6)
/*  f1a0294:	37190040 */ 	ori	$t9,$t8,0x40
/*  f1a0298:	a0790010 */ 	sb	$t9,0x10($v1)
/*  f1a029c:	8c49000c */ 	lw	$t1,0xc($v0)
/*  f1a02a0:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1a02a4:	01215024 */ 	and	$t2,$t1,$at
/*  f1a02a8:	10000004 */ 	b	.L0f1a02bc
/*  f1a02ac:	ac4a000c */ 	sw	$t2,0xc($v0)
.L0f1a02b0:
/*  f1a02b0:	2463003c */ 	addiu	$v1,$v1,60
.L0f1a02b4:
/*  f1a02b4:	5474ffec */ 	bnel	$v1,$s4,.L0f1a0268
/*  f1a02b8:	8c620010 */ 	lw	$v0,0x10($v1)
.L0f1a02bc:
/*  f1a02bc:	3c0b800b */ 	lui	$t3,%hi(g_FrData+0x438)
/*  f1a02c0:	256bd158 */ 	addiu	$t3,$t3,%lo(g_FrData+0x438)
/*  f1a02c4:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f1a02c8:	020b082b */ 	sltu	$at,$s0,$t3
/*  f1a02cc:	5420ff24 */ 	bnezl	$at,.L0f19ff60
/*  f1a02d0:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f1a02d4:	92a30004 */ 	lbu	$v1,0x4($s5)
/*  f1a02d8:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a02dc:	5461000f */ 	bnel	$v1,$at,.L0f1a031c
/*  f1a02e0:	92a20455 */ 	lbu	$v0,0x455($s5)
/*  f1a02e4:	96a20002 */ 	lhu	$v0,0x2($s5)
/*  f1a02e8:	10400009 */ 	beqz	$v0,.L0f1a0310
/*  f1a02ec:	00000000 */ 	nop
/*  f1a02f0:	8eac0450 */ 	lw	$t4,0x450($s5)
/*  f1a02f4:	0182082a */ 	slt	$at,$t4,$v0
/*  f1a02f8:	14200005 */ 	bnez	$at,.L0f1a0310
/*  f1a02fc:	00000000 */ 	nop
/*  f1a0300:	0fc67c63 */ 	jal	frSetCompleted
/*  f1a0304:	00000000 */ 	nop
/*  f1a0308:	1000017a */ 	b	.L0f1a08f4
/*  f1a030c:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f1a0310:
/*  f1a0310:	10000010 */ 	b	.L0f1a0354
/*  f1a0314:	92a20455 */ 	lbu	$v0,0x455($s5)
/*  f1a0318:	92a20455 */ 	lbu	$v0,0x455($s5)
.L0f1a031c:
/*  f1a031c:	0043082a */ 	slt	$at,$v0,$v1
/*  f1a0320:	5420000d */ 	bnezl	$at,.L0f1a0358
/*  f1a0324:	92ae0454 */ 	lbu	$t6,0x454($s5)
/*  f1a0328:	96a30002 */ 	lhu	$v1,0x2($s5)
/*  f1a032c:	10600005 */ 	beqz	$v1,.L0f1a0344
/*  f1a0330:	00000000 */ 	nop
/*  f1a0334:	8ead0450 */ 	lw	$t5,0x450($s5)
/*  f1a0338:	01a3082a */ 	slt	$at,$t5,$v1
/*  f1a033c:	54200006 */ 	bnezl	$at,.L0f1a0358
/*  f1a0340:	92ae0454 */ 	lbu	$t6,0x454($s5)
.L0f1a0344:
/*  f1a0344:	0fc67c63 */ 	jal	frSetCompleted
/*  f1a0348:	00000000 */ 	nop
/*  f1a034c:	10000169 */ 	b	.L0f1a08f4
/*  f1a0350:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f1a0354:
/*  f1a0354:	92ae0454 */ 	lbu	$t6,0x454($s5)
.L0f1a0358:
/*  f1a0358:	004e082a */ 	slt	$at,$v0,$t6
/*  f1a035c:	14200005 */ 	bnez	$at,.L0f1a0374
/*  f1a0360:	00000000 */ 	nop
/*  f1a0364:	0fc67c49 */ 	jal	frSetFailReason
/*  f1a0368:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f1a036c:	10000161 */ 	b	.L0f1a08f4
/*  f1a0370:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f1a0374:
/*  f1a0374:	0fc67d49 */ 	jal	frIsAmmoWasted
/*  f1a0378:	00000000 */ 	nop
/*  f1a037c:	50400006 */ 	beqzl	$v0,.L0f1a0398
/*  f1a0380:	92a20005 */ 	lbu	$v0,0x5($s5)
/*  f1a0384:	0fc67c49 */ 	jal	frSetFailReason
/*  f1a0388:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1a038c:	10000159 */ 	b	.L0f1a08f4
/*  f1a0390:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f1a0394:	92a20005 */ 	lbu	$v0,0x5($s5)
.L0f1a0398:
/*  f1a0398:	240100ff */ 	addiu	$at,$zero,0xff
/*  f1a039c:	00009025 */ 	or	$s2,$zero,$zero
/*  f1a03a0:	1041000b */ 	beq	$v0,$at,.L0f1a03d0
/*  f1a03a4:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f1a03a8:	8eaf044c */ 	lw	$t7,0x44c($s5)
/*  f1a03ac:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f1a03b0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1a03b4:	01f8082a */ 	slt	$at,$t7,$t8
/*  f1a03b8:	14200005 */ 	bnez	$at,.L0f1a03d0
/*  f1a03bc:	00000000 */ 	nop
/*  f1a03c0:	0fc67c49 */ 	jal	frSetFailReason
/*  f1a03c4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1a03c8:	1000014a */ 	b	.L0f1a08f4
/*  f1a03cc:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f1a03d0:
/*  f1a03d0:	3c10800b */ 	lui	$s0,%hi(g_FrData)
/*  f1a03d4:	3c017f1c */ 	lui	$at,%hi(var7f1b94d0)
/*  f1a03d8:	c43494d0 */ 	lwc1	$f20,%lo(var7f1b94d0)($at)
/*  f1a03dc:	2610cd20 */ 	addiu	$s0,$s0,%lo(g_FrData)
/*  f1a03e0:	27b50098 */ 	addiu	$s5,$sp,0x98
/*  f1a03e4:	27b400bc */ 	addiu	$s4,$sp,0xbc
.L0f1a03e8:
/*  f1a03e8:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f1a03ec:	0002cfc2 */ 	srl	$t9,$v0,0x1f
/*  f1a03f0:	1320013b */ 	beqz	$t9,.L0f1a08e0
/*  f1a03f4:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1a03f8:	05400139 */ 	bltz	$t2,.L0f1a08e0
/*  f1a03fc:	00026040 */ 	sll	$t4,$v0,0x1
/*  f1a0400:	05830138 */ 	bgezl	$t4,.L0f1a08e4
/*  f1a0404:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1a0408:	920d0043 */ 	lbu	$t5,0x43($s0)
/*  f1a040c:	8e110014 */ 	lw	$s1,0x14($s0)
/*  f1a0410:	11a00089 */ 	beqz	$t5,.L0f1a0638
/*  f1a0414:	8e330004 */ 	lw	$s3,0x4($s1)
/*  f1a0418:	c60a002c */ 	lwc1	$f10,0x2c($s0)
/*  f1a041c:	3c013f80 */ 	lui	$at,0x3f80
/*  f1a0420:	44817000 */ 	mtc1	$at,$f14
/*  f1a0424:	460ac032 */ 	c.eq.s	$f24,$f10
/*  f1a0428:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1a042c:	3c01c000 */ 	lui	$at,0xc000
/*  f1a0430:	45020006 */ 	bc1fl	.L0f1a044c
/*  f1a0434:	c6100018 */ 	lwc1	$f16,0x18($s0)
/*  f1a0438:	44816000 */ 	mtc1	$at,$f12
/*  f1a043c:	a20e0042 */ 	sb	$t6,0x42($s0)
/*  f1a0440:	10000043 */ 	b	.L0f1a0550
/*  f1a0444:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f1a0448:	c6100018 */ 	lwc1	$f16,0x18($s0)
.L0f1a044c:
/*  f1a044c:	c6320008 */ 	lwc1	$f18,0x8($s1)
/*  f1a0450:	c606001c */ 	lwc1	$f6,0x1c($s0)
/*  f1a0454:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f1a0458:	c6100020 */ 	lwc1	$f16,0x20($s0)
/*  f1a045c:	e7a40158 */ 	swc1	$f4,0x158($sp)
/*  f1a0460:	c628000c */ 	lwc1	$f8,0xc($s1)
/*  f1a0464:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f1a0468:	c7a60158 */ 	lwc1	$f6,0x158($sp)
/*  f1a046c:	e7aa015c */ 	swc1	$f10,0x15c($sp)
/*  f1a0470:	c6320010 */ 	lwc1	$f18,0x10($s1)
/*  f1a0474:	46063202 */ 	mul.s	$f8,$f6,$f6
/*  f1a0478:	c7aa015c */ 	lwc1	$f10,0x15c($sp)
/*  f1a047c:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f1a0480:	e7ae0110 */ 	swc1	$f14,0x110($sp)
/*  f1a0484:	460a5402 */ 	mul.s	$f16,$f10,$f10
/*  f1a0488:	e7a40160 */ 	swc1	$f4,0x160($sp)
/*  f1a048c:	c7a40160 */ 	lwc1	$f4,0x160($sp)
/*  f1a0490:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f1a0494:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f1a0498:	0c012974 */ 	jal	sqrtf
/*  f1a049c:	46123300 */ 	add.s	$f12,$f6,$f18
/*  f1a04a0:	46160032 */ 	c.eq.s	$f0,$f22
/*  f1a04a4:	c7ae0110 */ 	lwc1	$f14,0x110($sp)
/*  f1a04a8:	46000306 */ 	mov.s	$f12,$f0
/*  f1a04ac:	3c01c000 */ 	lui	$at,0xc000
/*  f1a04b0:	45030026 */ 	bc1tl	.L0f1a054c
/*  f1a04b4:	44816000 */ 	mtc1	$at,$f12
/*  f1a04b8:	3c013e80 */ 	lui	$at,0x3e80
/*  f1a04bc:	44813000 */ 	mtc1	$at,$f6
/*  f1a04c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1a04c4:	44819000 */ 	mtc1	$at,$f18
/*  f1a04c8:	8ecf0034 */ 	lw	$t7,0x34($s6)
/*  f1a04cc:	c60a002c */ 	lwc1	$f10,0x2c($s0)
/*  f1a04d0:	46009083 */ 	div.s	$f2,$f18,$f0
/*  f1a04d4:	448f4000 */ 	mtc1	$t7,$f8
/*  f1a04d8:	00000000 */ 	nop
/*  f1a04dc:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f1a04e0:	c7a80158 */ 	lwc1	$f8,0x158($sp)
/*  f1a04e4:	46105102 */ 	mul.s	$f4,$f10,$f16
/*  f1a04e8:	c7b0015c */ 	lwc1	$f16,0x15c($sp)
/*  f1a04ec:	46062382 */ 	mul.s	$f14,$f4,$f6
/*  f1a04f0:	c7a60160 */ 	lwc1	$f6,0x160($sp)
/*  f1a04f4:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f1a04f8:	00000000 */ 	nop
/*  f1a04fc:	46028102 */ 	mul.s	$f4,$f16,$f2
/*  f1a0500:	00000000 */ 	nop
/*  f1a0504:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f1a0508:	e7aa0158 */ 	swc1	$f10,0x158($sp)
/*  f1a050c:	460e5202 */ 	mul.s	$f8,$f10,$f14
/*  f1a0510:	e7a4015c */ 	swc1	$f4,0x15c($sp)
/*  f1a0514:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*  f1a0518:	e7b20160 */ 	swc1	$f18,0x160($sp)
/*  f1a051c:	c6300008 */ 	lwc1	$f16,0x8($s1)
/*  f1a0520:	46104180 */ 	add.s	$f6,$f8,$f16
/*  f1a0524:	e7a6014c */ 	swc1	$f6,0x14c($sp)
/*  f1a0528:	c628000c */ 	lwc1	$f8,0xc($s1)
/*  f1a052c:	460e9182 */ 	mul.s	$f6,$f18,$f14
/*  f1a0530:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f1a0534:	e7b00150 */ 	swc1	$f16,0x150($sp)
/*  f1a0538:	c6240010 */ 	lwc1	$f4,0x10($s1)
/*  f1a053c:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f1a0540:	10000003 */ 	b	.L0f1a0550
/*  f1a0544:	e7aa0154 */ 	swc1	$f10,0x154($sp)
/*  f1a0548:	44816000 */ 	mtc1	$at,$f12
.L0f1a054c:
/*  f1a054c:	00000000 */ 	nop
.L0f1a0550:
/*  f1a0550:	460e603e */ 	c.le.s	$f12,$f14
/*  f1a0554:	00000000 */ 	nop
/*  f1a0558:	4502002d */ 	bc1fl	.L0f1a0610
/*  f1a055c:	c7a6014c */ 	lwc1	$f6,0x14c($sp)
/*  f1a0560:	92190010 */ 	lbu	$t9,0x10($s0)
/*  f1a0564:	920a0042 */ 	lbu	$t2,0x42($s0)
/*  f1a0568:	c6080018 */ 	lwc1	$f8,0x18($s0)
/*  f1a056c:	c610001c */ 	lwc1	$f16,0x1c($s0)
/*  f1a0570:	c6120020 */ 	lwc1	$f18,0x20($s0)
/*  f1a0574:	37290010 */ 	ori	$t1,$t9,0x10
/*  f1a0578:	a2090010 */ 	sb	$t1,0x10($s0)
/*  f1a057c:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f1a0580:	e7a8014c */ 	swc1	$f8,0x14c($sp)
/*  f1a0584:	e7b00150 */ 	swc1	$f16,0x150($sp)
/*  f1a0588:	15400020 */ 	bnez	$t2,.L0f1a060c
/*  f1a058c:	e7b20154 */ 	swc1	$f18,0x154($sp)
/*  f1a0590:	3c028009 */ 	lui	$v0,%hi(g_FrNumSounds)
/*  f1a0594:	2442880c */ 	addiu	$v0,$v0,%lo(g_FrNumSounds)
/*  f1a0598:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f1a059c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1a05a0:	a20b0042 */ 	sb	$t3,0x42($s0)
/*  f1a05a4:	10600003 */ 	beqz	$v1,.L0f1a05b4
/*  f1a05a8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1a05ac:	246cffff */ 	addiu	$t4,$v1,-1
/*  f1a05b0:	a04c0000 */ 	sb	$t4,0x0($v0)
.L0f1a05b4:
/*  f1a05b4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a05b8:	0fc249af */ 	jal	func0f0926bc
/*  f1a05bc:	3406ffff */ 	dli	$a2,0xffff
/*  f1a05c0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f1a05c4:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f1a05c8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1a05cc:	afaf002c */ 	sw	$t7,0x2c($sp)
/*  f1a05d0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1a05d4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1a05d8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a05dc:	02202825 */ 	or	$a1,$s1,$zero
/*  f1a05e0:	240605da */ 	addiu	$a2,$zero,0x5da
/*  f1a05e4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1a05e8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1a05ec:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1a05f0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f1a05f4:	e7b80024 */ 	swc1	$f24,0x24($sp)
/*  f1a05f8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1a05fc:	e7b80030 */ 	swc1	$f24,0x30($sp)
/*  f1a0600:	e7b80034 */ 	swc1	$f24,0x34($sp)
/*  f1a0604:	0fc24e7e */ 	jal	func0f0939f8
/*  f1a0608:	e7b80038 */ 	swc1	$f24,0x38($sp)
.L0f1a060c:
/*  f1a060c:	c7a6014c */ 	lwc1	$f6,0x14c($sp)
.L0f1a0610:
/*  f1a0610:	02602025 */ 	or	$a0,$s3,$zero
/*  f1a0614:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1a0618:	e6260008 */ 	swc1	$f6,0x8($s1)
/*  f1a061c:	c7a40150 */ 	lwc1	$f4,0x150($sp)
/*  f1a0620:	00003025 */ 	or	$a2,$zero,$zero
/*  f1a0624:	e624000c */ 	swc1	$f4,0xc($s1)
/*  f1a0628:	c7aa0154 */ 	lwc1	$f10,0x154($sp)
/*  f1a062c:	0fc1a71c */ 	jal	func0f069c70
/*  f1a0630:	e62a0010 */ 	swc1	$f10,0x10($s1)
/*  f1a0634:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f1a0638:
/*  f1a0638:	0002c940 */ 	sll	$t9,$v0,0x5
/*  f1a063c:	07210033 */ 	bgez	$t9,.L0f1a070c
/*  f1a0640:	00025100 */ 	sll	$t2,$v0,0x4
/*  f1a0644:	05420032 */ 	bltzl	$t2,.L0f1a0710
/*  f1a0648:	00027100 */ 	sll	$t6,$v0,0x4
/*  f1a064c:	8e020028 */ 	lw	$v0,0x28($s0)
/*  f1a0650:	54400025 */ 	bnezl	$v0,.L0f1a06e8
/*  f1a0654:	8ed80038 */ 	lw	$t8,0x38($s6)
/*  f1a0658:	8ecb0284 */ 	lw	$t3,0x284($s6)
/*  f1a065c:	3c017f1c */ 	lui	$at,%hi(var7f1b94d4)
/*  f1a0660:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f1a0664:	8d820004 */ 	lw	$v0,0x4($t4)
/*  f1a0668:	8c430014 */ 	lw	$v1,0x14($v0)
/*  f1a066c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f1a0670:	05a3000f */ 	bgezl	$t5,.L0f1a06b0
/*  f1a0674:	c6060038 */ 	lwc1	$f6,0x38($s0)
/*  f1a0678:	c42894d4 */ 	lwc1	$f8,%lo(var7f1b94d4)($at)
/*  f1a067c:	c6100038 */ 	lwc1	$f16,0x38($s0)
/*  f1a0680:	240e003c */ 	addiu	$t6,$zero,0x3c
/*  f1a0684:	3c017f1c */ 	lui	$at,%hi(var7f1b94d8)
/*  f1a0688:	46104032 */ 	c.eq.s	$f8,$f16
/*  f1a068c:	00000000 */ 	nop
/*  f1a0690:	4500001c */ 	bc1f	.L0f1a0704
/*  f1a0694:	00000000 */ 	nop
/*  f1a0698:	ae0e0028 */ 	sw	$t6,0x28($s0)
/*  f1a069c:	e616003c */ 	swc1	$f22,0x3c($s0)
/*  f1a06a0:	c43294d8 */ 	lwc1	$f18,%lo(var7f1b94d8)($at)
/*  f1a06a4:	10000017 */ 	b	.L0f1a0704
/*  f1a06a8:	e6120034 */ 	swc1	$f18,0x34($s0)
/*  f1a06ac:	c6060038 */ 	lwc1	$f6,0x38($s0)
.L0f1a06b0:
/*  f1a06b0:	240f003c */ 	addiu	$t7,$zero,0x3c
/*  f1a06b4:	3c017f1c */ 	lui	$at,%hi(var7f1b94dc)
/*  f1a06b8:	4606b032 */ 	c.eq.s	$f22,$f6
/*  f1a06bc:	00000000 */ 	nop
/*  f1a06c0:	45000010 */ 	bc1f	.L0f1a0704
/*  f1a06c4:	00000000 */ 	nop
/*  f1a06c8:	ae0f0028 */ 	sw	$t7,0x28($s0)
/*  f1a06cc:	c42494dc */ 	lwc1	$f4,%lo(var7f1b94dc)($at)
/*  f1a06d0:	3c017f1c */ 	lui	$at,%hi(var7f1b94e0)
/*  f1a06d4:	e604003c */ 	swc1	$f4,0x3c($s0)
/*  f1a06d8:	c42a94e0 */ 	lwc1	$f10,%lo(var7f1b94e0)($at)
/*  f1a06dc:	10000009 */ 	b	.L0f1a0704
/*  f1a06e0:	e60a0034 */ 	swc1	$f10,0x34($s0)
/*  f1a06e4:	8ed80038 */ 	lw	$t8,0x38($s6)
.L0f1a06e8:
/*  f1a06e8:	0058c823 */ 	subu	$t9,$v0,$t8
/*  f1a06ec:	1f200005 */ 	bgtz	$t9,.L0f1a0704
/*  f1a06f0:	ae190028 */ 	sw	$t9,0x28($s0)
/*  f1a06f4:	920b0010 */ 	lbu	$t3,0x10($s0)
/*  f1a06f8:	ae000028 */ 	sw	$zero,0x28($s0)
/*  f1a06fc:	356c0008 */ 	ori	$t4,$t3,0x8
/*  f1a0700:	a20c0010 */ 	sb	$t4,0x10($s0)
.L0f1a0704:
/*  f1a0704:	10000054 */ 	b	.L0f1a0858
/*  f1a0708:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f1a070c:
/*  f1a070c:	00027100 */ 	sll	$t6,$v0,0x4
.L0f1a0710:
/*  f1a0710:	05c30052 */ 	bgezl	$t6,.L0f1a085c
/*  f1a0714:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f1a0718:	c60c003c */ 	lwc1	$f12,0x3c($s0)
/*  f1a071c:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a0720:	c60e0034 */ 	lwc1	$f14,0x34($s0)
/*  f1a0724:	00001025 */ 	or	$v0,$zero,$zero
/*  f1a0728:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1a072c:	46006086 */ 	mov.s	$f2,$f12
/*  f1a0730:	45020003 */ 	bc1fl	.L0f1a0740
/*  f1a0734:	8ed80034 */ 	lw	$t8,0x34($s6)
/*  f1a0738:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1a073c:	8ed80034 */ 	lw	$t8,0x34($s6)
.L0f1a0740:
/*  f1a0740:	3c013e80 */ 	lui	$at,0x3e80
/*  f1a0744:	44813000 */ 	mtc1	$at,$f6
/*  f1a0748:	44984000 */ 	mtc1	$t8,$f8
/*  f1a074c:	304f00ff */ 	andi	$t7,$v0,0xff
/*  f1a0750:	01e01025 */ 	or	$v0,$t7,$zero
/*  f1a0754:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f1a0758:	00001825 */ 	or	$v1,$zero,$zero
/*  f1a075c:	3c017f1c */ 	lui	$at,%hi(var7f1b94e4)
/*  f1a0760:	46107482 */ 	mul.s	$f18,$f14,$f16
/*  f1a0764:	00000000 */ 	nop
/*  f1a0768:	46069102 */ 	mul.s	$f4,$f18,$f6
/*  f1a076c:	46040280 */ 	add.s	$f10,$f0,$f4
/*  f1a0770:	e60a0038 */ 	swc1	$f10,0x38($s0)
/*  f1a0774:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a0778:	4602003c */ 	c.lt.s	$f0,$f2
/*  f1a077c:	00000000 */ 	nop
/*  f1a0780:	45000002 */ 	bc1f	.L0f1a078c
/*  f1a0784:	00000000 */ 	nop
/*  f1a0788:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1a078c:
/*  f1a078c:	307900ff */ 	andi	$t9,$v1,0xff
/*  f1a0790:	57220006 */ 	bnel	$t9,$v0,.L0f1a07ac
/*  f1a0794:	92090010 */ 	lbu	$t1,0x10($s0)
/*  f1a0798:	46001032 */ 	c.eq.s	$f2,$f0
/*  f1a079c:	00000000 */ 	nop
/*  f1a07a0:	4500001e */ 	bc1f	.L0f1a081c
/*  f1a07a4:	00000000 */ 	nop
/*  f1a07a8:	92090010 */ 	lbu	$t1,0x10($s0)
.L0f1a07ac:
/*  f1a07ac:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f1a07b0:	e60c0038 */ 	swc1	$f12,0x38($s0)
/*  f1a07b4:	312cfff7 */ 	andi	$t4,$t1,0xfff7
/*  f1a07b8:	a20c0010 */ 	sb	$t4,0x10($s0)
/*  f1a07bc:	358d0010 */ 	ori	$t5,$t4,0x10
/*  f1a07c0:	a20d0010 */ 	sb	$t5,0x10($s0)
/*  f1a07c4:	45000009 */ 	bc1f	.L0f1a07ec
/*  f1a07c8:	ae000024 */ 	sw	$zero,0x24($s0)
/*  f1a07cc:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a07d0:	46140201 */ 	sub.s	$f8,$f0,$f20
.L0f1a07d4:
/*  f1a07d4:	e6080038 */ 	swc1	$f8,0x38($s0)
/*  f1a07d8:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a07dc:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f1a07e0:	00000000 */ 	nop
/*  f1a07e4:	4503fffb */ 	bc1tl	.L0f1a07d4
/*  f1a07e8:	46140201 */ 	sub.s	$f8,$f0,$f20
.L0f1a07ec:
/*  f1a07ec:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a07f0:	4616003c */ 	c.lt.s	$f0,$f22
/*  f1a07f4:	00000000 */ 	nop
/*  f1a07f8:	45000008 */ 	bc1f	.L0f1a081c
/*  f1a07fc:	00000000 */ 	nop
/*  f1a0800:	46140400 */ 	add.s	$f16,$f0,$f20
.L0f1a0804:
/*  f1a0804:	e6100038 */ 	swc1	$f16,0x38($s0)
/*  f1a0808:	c6000038 */ 	lwc1	$f0,0x38($s0)
/*  f1a080c:	4616003c */ 	c.lt.s	$f0,$f22
/*  f1a0810:	00000000 */ 	nop
/*  f1a0814:	4503fffb */ 	bc1tl	.L0f1a0804
/*  f1a0818:	46140400 */ 	add.s	$f16,$f0,$f20
.L0f1a081c:
/*  f1a081c:	c43294e4 */ 	lwc1	$f18,%lo(var7f1b94e4)($at)
/*  f1a0820:	02802825 */ 	or	$a1,$s4,$zero
/*  f1a0824:	0c0058dd */ 	jal	func00016374
/*  f1a0828:	46120300 */ 	add.s	$f12,$f0,$f18
/*  f1a082c:	8e6e0018 */ 	lw	$t6,0x18($s3)
/*  f1a0830:	02802825 */ 	or	$a1,$s4,$zero
/*  f1a0834:	0c0057c1 */ 	jal	func00015f04
/*  f1a0838:	c5cc0014 */ 	lwc1	$f12,0x14($t6)
/*  f1a083c:	02802025 */ 	or	$a0,$s4,$zero
/*  f1a0840:	0c005768 */ 	jal	func00015da0
/*  f1a0844:	02a02825 */ 	or	$a1,$s5,$zero
/*  f1a0848:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1a084c:	0c005736 */ 	jal	func00015cd8
/*  f1a0850:	2665001c */ 	addiu	$a1,$s3,0x1c
/*  f1a0854:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f1a0858:
/*  f1a0858:	0002c0c0 */ 	sll	$t8,$v0,0x3
.L0f1a085c:
/*  f1a085c:	07030021 */ 	bgezl	$t8,.L0f1a08e4
/*  f1a0860:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1a0864:	8e020024 */ 	lw	$v0,0x24($s0)
/*  f1a0868:	24013bc4 */ 	addiu	$at,$zero,0x3bc4
/*  f1a086c:	5041001d */ 	beql	$v0,$at,.L0f1a08e4
/*  f1a0870:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1a0874:	8ed90038 */ 	lw	$t9,0x38($s6)
/*  f1a0878:	00594823 */ 	subu	$t1,$v0,$t9
/*  f1a087c:	1d200018 */ 	bgtz	$t1,.L0f1a08e0
/*  f1a0880:	ae090024 */ 	sw	$t1,0x24($s0)
/*  f1a0884:	920b0010 */ 	lbu	$t3,0x10($s0)
/*  f1a0888:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a088c:	316cffef */ 	andi	$t4,$t3,0xffef
/*  f1a0890:	0fc67824 */ 	jal	frExecuteTargetScript
/*  f1a0894:	a20c0010 */ 	sb	$t4,0x10($s0)
/*  f1a0898:	14400005 */ 	bnez	$v0,.L0f1a08b0
/*  f1a089c:	00000000 */ 	nop
.L0f1a08a0:
/*  f1a08a0:	0fc67824 */ 	jal	frExecuteTargetScript
/*  f1a08a4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a08a8:	1040fffd */ 	beqz	$v0,.L0f1a08a0
/*  f1a08ac:	00000000 */ 	nop
.L0f1a08b0:
/*  f1a08b0:	0fc677bd */ 	jal	frTargetIsAtScriptStart
/*  f1a08b4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a08b8:	5040000a */ 	beqzl	$v0,.L0f1a08e4
/*  f1a08bc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1a08c0:	0fc67824 */ 	jal	frExecuteTargetScript
/*  f1a08c4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a08c8:	54400006 */ 	bnezl	$v0,.L0f1a08e4
/*  f1a08cc:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f1a08d0:
/*  f1a08d0:	0fc67824 */ 	jal	frExecuteTargetScript
/*  f1a08d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1a08d8:	1040fffd */ 	beqz	$v0,.L0f1a08d0
/*  f1a08dc:	00000000 */ 	nop
.L0f1a08e0:
/*  f1a08e0:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f1a08e4:
/*  f1a08e4:	24010012 */ 	addiu	$at,$zero,0x12
/*  f1a08e8:	1641febf */ 	bne	$s2,$at,.L0f1a03e8
/*  f1a08ec:	2610003c */ 	addiu	$s0,$s0,0x3c
.L0f1a08f0:
/*  f1a08f0:	8fbf007c */ 	lw	$ra,0x7c($sp)
.L0f1a08f4:
/*  f1a08f4:	d7b40048 */ 	ldc1	$f20,0x48($sp)
/*  f1a08f8:	d7b60050 */ 	ldc1	$f22,0x50($sp)
/*  f1a08fc:	d7b80058 */ 	ldc1	$f24,0x58($sp)
/*  f1a0900:	8fb00060 */ 	lw	$s0,0x60($sp)
/*  f1a0904:	8fb10064 */ 	lw	$s1,0x64($sp)
/*  f1a0908:	8fb20068 */ 	lw	$s2,0x68($sp)
/*  f1a090c:	8fb3006c */ 	lw	$s3,0x6c($sp)
/*  f1a0910:	8fb40070 */ 	lw	$s4,0x70($sp)
/*  f1a0914:	8fb50074 */ 	lw	$s5,0x74($sp)
/*  f1a0918:	8fb60078 */ 	lw	$s6,0x78($sp)
/*  f1a091c:	03e00008 */ 	jr	$ra
/*  f1a0920:	27bd0170 */ 	addiu	$sp,$sp,0x170
);

// Mismatch issues:
// - Floating point math at 448 is very different
// - g_FrNumSounds at 590 is calculated differently
// - Goal has extra mov.s instruction near 730
//void frTick(void)
//{
//	struct coord diff; // sp344
//	struct coord newpos; // sp332
//	f32 s5[9]; // sp152
//	f32 s4[21]; // sp188
//	s32 ammotype;
//	s32 capacity;
//	s32 weaponnum;
//	u8 weaponnum2;
//	struct prop *prop;
//	struct defaultobj *obj;
//	struct defaultobj *obj2;
//	s32 invincible;
//	u8 exploding;
//	s32 i;
//	s32 j;
//	f32 dist;
//	f32 mult;
//	struct inventory_ammo *ammo;
//	struct model08thing *model08thing;
//	bool oldside;
//	bool newside;
//
//	// 9c8
//	if (g_FrIsValidWeapon
//			&& g_Vars.currentplayer->unk1583_04 == 0
//			&& currentPlayerCanHaveWeapon(frGetWeaponBySlot(g_FrData.slot))) {
//		// a0c
//		currentPlayerEquipWeapon(frGetWeaponBySlot(g_FrData.slot));
//	}
//
//	// a1c
//	// Handle the menu countdown
//	if (g_FrData.menucountdown != 0) {
//		g_FrData.menucountdown -= g_Vars.lvupdate240_60;
//
//		// Prevent showing the menu until gun is put away
//		if (g_FrData.menucountdown <= 0) {
//			if ((g_FrData.menutype == FRMENUTYPE_FAILED || g_FrData.menutype == FRMENUTYPE_COMPLETED)
//					&& g_Vars.currentplayer->hands[0].weaponnum != WEAPON_UNARMED) {
//				g_FrData.menucountdown = 1;
//			}
//		}
//
//		if (g_FrData.menucountdown <= 0) {
//			g_FrData.menucountdown = 0;
//
//			for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
//				if (g_FrData.targets[i].prop) {
//					func0f0926bc(g_FrData.targets[i].prop, 1, 0xffff);
//				}
//			}
//
//			switch (g_FrData.menutype) {
//			case FRMENUTYPE_WEAPONLIST:
//				func0f0f85e0(ciGetFrWeaponListMenuDialog(), MENUROOT_TRAINING);
//				break;
//			case FRMENUTYPE_DETAILS:
//				func0f0f85e0(&menudialog_frtraininginfo2, MENUROOT_TRAINING);
//				break;
//			case FRMENUTYPE_FAILED:
//				audioStart(var80095200, 0x5db, NULL, -1, -1, -1, -1, -1);
//				func0f0f85e0(&g_MenuDialogFrTrainingStatsFailed, MENUROOT_TRAINING);
//				break;
//			case FRMENUTYPE_COMPLETED:
//				audioStart(var80095200, 0x5dc, NULL, -1, -1, -1, -1, -1);
//				func0f0f85e0(&g_MenuDialogFrTrainingStatsCompleted, MENUROOT_TRAINING);
//				func0f1094e4(&var800a22c0, 0, 0);
//				break;
//			}
//		}
//		return;
//	}
//
//	// be8
//	// End the session if the player slipped through the door before it closed
//	if (g_Vars.currentplayer->prop->rooms[0] != CIROOM_FIRINGRANGE) {
//		if (g_FrIsValidWeapon) {
//			for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
//				if (g_FrData.targets[i].inuse
//						&& g_FrData.targets[i].destroyed == false
//						&& g_FrData.targets[i].silent == false
//						&& g_FrData.targets[i].travelling) {
//					g_FrData.targets[i].silent = true;
//					func0f0926bc(g_FrData.targets[i].prop, 1, 0xffff);
//				}
//			}
//
//			g_Vars.currentplayer->training = false;
//			frEndSession(true);
//			chrUnsetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
//		}
//		return;
//	}
//
//	// c94
//	if (!g_FrIsValidWeapon) {
//		return;
//	}
//
//	if (g_Vars.currentplayer->isdead) {
//		frEndSession(false);
//	}
//
//	// If paused, stop any target sounds
//	if (g_Vars.lvupdate240 == 0) {
//		for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
//			if (g_FrData.targets[i].inuse
//					&& g_FrData.targets[i].destroyed == false
//					&& g_FrData.targets[i].silent == false
//					&& g_FrData.targets[i].travelling) {
//				g_FrData.targets[i].silent = true;
//				func0f0926bc(g_FrData.targets[i].prop, 1, 0xffff);
//			}
//		}
//		return;
//	}
//
//	g_Vars.currentplayer->training = true;
//	frExecuteHelpScript();
//
//	// d34
//	// Top up the player's ammo if the config defined more ammo than the
//	// weapon allows, or if it defined unlimited ammo
//	if (g_FrData.numshotssincetopup != 0) {
//		u32 tmp;
//		weaponnum = frGetWeaponBySlot(g_FrData.slot);
//		ammotype = weaponGetAmmoType(weaponnum, 0);
//		capacity = ammotypeGetMaxCapacity(ammotype);
//		ammo = weaponGetAmmoByFunction(weaponnum, 0);
//		capacity -= (ammo ? ammo->clipsize : 0);
//
//		// d8c
//		if (g_FrData.ammoextra > 0) {
//			tmp = ammoGetQuantity(ammotype);
//			g_FrData.ammoextra -= g_FrData.numshotssincetopup;
//
//			if (g_FrData.ammoextra < 0) {
//				g_FrData.ammoextra = 0;
//			}
//
//			capacity = tmp + g_FrData.numshotssincetopup;
//			currentPlayerSetAmmoQuantity(ammotype, capacity);
//		} else /*dd4*/ if (g_FrData.ammoextra == -1) {
//			currentPlayerSetAmmoQuantity(ammotype, capacity);
//		}
//
//		// de8
//		if (weaponnum == WEAPON_SUPERDRAGON) {
//			capacity = ammotypeGetMaxCapacity(AMMOTYPE_DEVASTATOR);
//
//			// e04
//			if (g_FrData.sdgrenadeextra > 0) {
//				tmp = ammoGetQuantity(AMMOTYPE_DEVASTATOR);
//				g_FrData.sdgrenadeextra -= g_FrData.numshotssincetopup;
//
//				if (g_FrData.sdgrenadeextra < 0) {
//					g_FrData.sdgrenadeextra = 0;
//				}
//
//				capacity = tmp + g_FrData.numshotssincetopup;
//				currentPlayerSetAmmoQuantity(AMMOTYPE_DEVASTATOR, capacity);
//			} else /*e4c*/ if (g_FrData.sdgrenadeextra == -1) {
//				currentPlayerSetAmmoQuantity(AMMOTYPE_DEVASTATOR, capacity);
//			}
//		}
//
//		// e60
//		g_FrData.numshotssincetopup = 0;
//	}
//
//	g_FrData.timetaken += g_Vars.lvupdate240_60;
//
//	// e6c
//	// Handle prestart
//	if (g_FrData.timetaken < 0) {
//		if (g_FrData.numshots == 0) {
//			if (g_FrData.donealarm == false && g_FrData.timetaken > -180) {
//				g_FrData.donealarm = true;
//				audioStart(var80095200, 0x5d4, NULL, -1, -1, -1, -1, -1);
//			}
//
//			if (!g_FrData.donelighting && g_FrData.timetaken > -225) {
//				frInitLighting();
//			}
//
//			return;
//		}
//
//		// Fired a shot during prestart
//		if (!g_FrData.donelighting) {
//			frInitLighting();
//		}
//
//		g_FrData.timetaken = 0;
//		g_FrData.donealarm = true;
//	}
//
//	// f38
//	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
//		if (g_FrData.targets[i].inuse
//				&& g_FrData.targets[i].destroyed == false
//				&& g_FrData.targets[i].active) {
//			// f7c
//			invincible = false;
//			exploding = false;
//			weaponnum2 = frGetWeaponBySlot(g_FrData.slot);
//			prop = g_FrData.targets[i].prop;
//			obj = prop->obj;
//
//			// f94
//			switch (weaponnum2) {
//			case WEAPON_GRENADE:
//			case WEAPON_PROXIMITYMINE:
//				func0f08abd4(&prop->pos, 1);
//				break;
//			}
//
//			// fb0
//			if (g_FrData.targets[i].travelling
//					&& g_FrData.targets[i].silent
//					&& g_FrData.targets[i].travelspeed != -1) {
//				g_FrData.targets[i].silent = false;
//				func0f0939f8(NULL, g_FrData.targets[i].prop, 0x5d9, -1,
//						-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
//			}
//
//			// 028
//			if (g_FrData.targets[i].angle > 2.2915925979614f
//					&& g_FrData.targets[i].angle < 3.9915928840637f) {
//				obj->damage = 0;
//			}
//
//			// 058
//			if (g_FrData.targets[i].flags & FRTARGETFLAG_TMPINVINCIBLE
//					&& g_FrData.targets[i].invincibletimer < 300) {
//				invincible = true;
//				g_FrData.targets[i].invincibletimer += g_Vars.lvupdate240_60;
//			}
//
//			// 088
//			if (obj->damage > 0) {
//				// 090
//				if (invincible || g_FrData.targets[i].angle == M_PI) {
//					obj->damage = 0;
//				} else /*0bc*/ if (g_FrData.targets[i].flags & FRTARGETFLAG_ONEHITEXPLODE
//						|| obj->damage >= obj->maxdamage
//						|| frGetWeaponBySlot(g_FrData.slot) == WEAPON_PHOENIX) {
//					g_FrData.numhitsbullseye++;
//					g_FrData.score += 10;
//					exploding = true;
//					g_FrData.feedbackttl = 60;
//					g_FrData.feedbackzone = FRZONE_EXPLODE;
//				}
//			}
//
//			// 11c
//			// Handle target being destroyed
//			if (exploding || (g_FrData.targets[i].maxdamage != 255 && g_FrData.targets[i].damage >= g_FrData.targets[i].maxdamage)) {
//				// 150
//				model08thing = func0f068af4(obj);
//
//				if (g_FrNumSounds && g_FrData.targets[i].travelling) {
//					g_FrNumSounds--;
//					func0f0926bc(prop, 1, 0xffff);
//				}
//
//				// 1d0
//				func0f150820(&prop->pos, &obj->realrot[0], &obj->realrot[3], &obj->realrot[6],
//						model08thing->unk04[0], model08thing->unk04[1], model08thing->unk04[2],
//						model08thing->unk04[3], 2, prop);
//
//				g_FrData.targetsdestroyed++;
//
//				if (g_FrData.targets[i].flags & FRTARGETFLAG_ONEHITEXPLODE) {
//					explosionCreateSimple(g_FrData.targets[i].prop, &g_FrData.targets[i].prop->pos, g_FrData.targets[i].prop->rooms, EXPLOSIONTYPE_5, 1);
//				}
//
//				// 210
//				g_FrData.targets[i].travelling = false;
//				g_FrData.targets[i].active = false;
//				g_FrData.targets[i].destroyed = true;
//
//				obj->flags2 |= OBJFLAG2_INVISIBLE;
//
//				prop->pos.x = 0;
//				prop->pos.y = -5000;
//				prop->pos.z = 0;
//
//				func0f069c70(obj, true, false);
//
//				// 25c
//				// Activate another target
//				for (j = 0; j < ARRAYCOUNT(g_FrData.targets); j++) {
//					if (g_FrData.targets[j].destroyed == false
//							&& g_FrData.targets[j].inuse
//							&& g_FrData.targets[j].active == false) {
//						obj2 = g_FrData.targets[j].prop->obj;
//						g_FrData.targets[j].active = true;
//						obj2->flags2 &= ~OBJFLAG2_INVISIBLE;
//						break;
//					}
//				}
//			}
//		}
//
//		// 2bc
//	}
//
//	// 2dc
//	if (g_FrData.goaltargets == 255) {
//		if (g_FrData.goalscore && g_FrData.score >= g_FrData.goalscore) {
//			frSetCompleted();
//			return;
//		}
//	} else if (g_FrData.targetsdestroyed >= g_FrData.goaltargets
//			&& (g_FrData.goalscore == 0 || g_FrData.score >= g_FrData.goalscore)) {
//		frSetCompleted();
//		return;
//	}
//
//	// 354
//	if (g_FrData.targetsdestroyed >= g_FrData.numtargets) {
//		frSetFailReason(FRFAILREASON_SCOREUNATTAINABLE);
//		return;
//	}
//
//	// 374
//	if (frIsAmmoWasted()) {
//		frSetFailReason(FRFAILREASON_OUTOFAMMO);
//		return;
//	}
//
//	// 398
//	if (g_FrData.timelimit != 255
//			&& g_FrData.timetaken >= SECSTOFRAMES60(g_FrData.timelimit)) {
//		frSetFailReason(FRFAILREASON_TIMEOVER);
//		return;
//	}
//
//	// 3d0
//	// Iterate targets and handle travelling, rotation and script execution
//	for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
//		if (g_FrData.targets[i].inuse
//				&& g_FrData.targets[i].destroyed == false
//				&& g_FrData.targets[i].active) {
//			prop = g_FrData.targets[i].prop;
//			obj = prop->obj;
//
//			// 410
//			if (g_FrData.targets[i].travelling) {
//				// 430
//				if (g_FrData.targets[i].travelspeed == -1) {
//					g_FrData.targets[i].donestopsound = true;
//					g_FrData.targets[i].travelling = false;
//					mult = 1;
//					dist = -2;
//				} else {
//					// 448
//					f32 sum = 0;
//					diff.x = g_FrData.targets[i].dstpos.x - prop->pos.x;
//					diff.y = g_FrData.targets[i].dstpos.y - prop->pos.y;
//					diff.z = g_FrData.targets[i].dstpos.z - prop->pos.z;
//					sum = sum + diff.x * diff.x;
//					sum = sum + diff.y * diff.y;
//					sum = sum + diff.z * diff.z;
//
//					dist = sqrtf(sum);
//					mult = 1;
//
//					// 4b0
//					if (dist != 0) {
//						mult = (g_FrData.targets[i].travelspeed * g_Vars.lvupdate240) * 0.25f;
//						diff.x *= 1.0f / dist;
//						diff.y *= 1.0f / dist;
//						diff.z *= 1.0f / dist;
//						newpos.x = diff.x * mult + prop->pos.x;
//						newpos.y = diff.y * mult + prop->pos.y;
//						newpos.z = diff.z * mult + prop->pos.z;
//					} else {
//						dist = -2;
//					}
//				}
//
//				// 550
//				if (mult >= dist) {
//					// Stopping
//					newpos.x = g_FrData.targets[i].dstpos.x;
//					newpos.y = g_FrData.targets[i].dstpos.y;
//					newpos.z = g_FrData.targets[i].dstpos.z;
//
//					g_FrData.targets[i].scriptenabled = true;
//					g_FrData.targets[i].travelling = false;
//
//					if (g_FrData.targets[i].donestopsound == false) {
//						// 590
//						g_FrData.targets[i].donestopsound = true;
//
//						if (g_FrNumSounds) {
//							g_FrNumSounds--;
//						}
//
//						// 5b8
//						func0f0926bc(prop, 1, 0xffff);
//						func0f0939f8(NULL, prop, 0x5da, -1,
//								-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);
//					}
//				}
//
//				prop->pos.x = newpos.x;
//				prop->pos.y = newpos.y;
//				prop->pos.z = newpos.z;
//
//				func0f069c70(obj, true, false);
//			}
//
//			// 63c
//			if (g_FrData.targets[i].rotateoncloak
//					&& g_FrData.targets[i].rotating == false) {
//				// 650
//				if (g_FrData.targets[i].timeuntilrotate == 0) {
//					struct chrdata *chr = g_Vars.currentplayer->prop->chr;
//					bool cloaked = chr->hidden & CHRHFLAG_CLOAKED;
//
//					// 670
//					if (cloaked) {
//						// 690
//						if (g_FrData.targets[i].angle == M_PI) {
//							g_FrData.targets[i].timeuntilrotate = 60;
//							g_FrData.targets[i].rotatetoangle = 0;
//							g_FrData.targets[i].rotatespeed = -M_PI / 90;
//						}
//					} else {
//						// 6ac
//						if (g_FrData.targets[i].angle == 0) {
//							g_FrData.targets[i].timeuntilrotate = 60;
//							g_FrData.targets[i].rotatetoangle = M_PI;
//							g_FrData.targets[i].rotatespeed = M_PI / 90;
//						}
//					}
//				} else {
//					// 6e4
//					g_FrData.targets[i].timeuntilrotate -= g_Vars.lvupdate240_60;
//
//					if (g_FrData.targets[i].timeuntilrotate <= 0) {
//						g_FrData.targets[i].timeuntilrotate = 0;
//						g_FrData.targets[i].rotating = true;
//					}
//				}
//			} else /*70c*/ if (g_FrData.targets[i].rotating) {
//				f32 speed = g_FrData.targets[i].rotatespeed;
//				f32 toangle = g_FrData.targets[i].rotatetoangle;
//				oldside = 0;
//
//				// 730
//				if (g_FrData.targets[i].angle < toangle) {
//					oldside = 1;
//				}
//
//				oldside = (u8)oldside;
//
//				// 73c
//				g_FrData.targets[i].angle += (speed * g_Vars.lvupdate240) * 0.25f;
//
//				newside = 0;
//
//				// 778
//				if (g_FrData.targets[i].angle < toangle) {
//					newside = 1;
//				}
//
//				newside = (u8)newside;
//
//				// 78c
//				if (newside != oldside || g_FrData.targets[i].angle == toangle) {
//					// 7b0
//					// Reached desired angle
//					g_FrData.targets[i].angle = toangle;
//					g_FrData.targets[i].rotating = false;
//					g_FrData.targets[i].scriptenabled = true;
//					g_FrData.targets[i].scriptsleep = 0;
//
//					while (g_FrData.targets[i].angle > M_TAU) {
//						g_FrData.targets[i].angle -= M_TAU;
//					}
//
//					while (g_FrData.targets[i].angle < 0) {
//						g_FrData.targets[i].angle += M_TAU;
//					}
//				}
//
//				// 81c
//				func00016374(g_FrData.targets[i].angle + M_PI, s4);
//				func00015f04(obj->model->unk14, s4);
//				func00015da0(s4, s5);
//				func00015cd8(s5, obj->realrot);
//			}
//
//			// 854
//			if (g_FrData.targets[i].scriptenabled
//					&& g_FrData.targets[i].scriptsleep != SECSTOFRAMES60(255)) {
//				// 874
//				g_FrData.targets[i].scriptsleep -= g_Vars.lvupdate240_60;
//
//				// 87c
//				if (g_FrData.targets[i].scriptsleep <= 0) {
//					g_FrData.targets[i].scriptenabled = false;
//
//					while (!frExecuteTargetScript(i));
//
//					if (frTargetIsAtScriptStart(i)) {
//						while (!frExecuteTargetScript(i));
//					}
//				}
//			}
//		}
//	}
//}

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

		modelSetRedBox(obj->model, &sp56, &sp64, &sp60, &sp68);

		for (i = 0; i < 4; i++) {
			if (g_Vars.currentplayer->cmpfollowprops[i].prop == prop) {
				return;
			}

			if (g_Vars.currentplayer->cmpfollowprops[i].prop == NULL) {
				g_Vars.currentplayer->cmpfollowprops[i].prop = prop;

				g_Vars.currentplayer->cmpfollowprops[i].unk04 = sp64 - 2;
				g_Vars.currentplayer->cmpfollowprops[i].unk08 = sp56 + 2;
				g_Vars.currentplayer->cmpfollowprops[i].unk06 = sp68 - 2;
				g_Vars.currentplayer->cmpfollowprops[i].unk0a = sp60 + 2;
				g_Vars.currentplayer->unk1b90[i] = 0;
				return;
			}
		}
	}
}

GLOBAL_ASM(
glabel frChooseFarsightTarget
/*  f1a0a70:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f1a0a74:	f7bc0030 */ 	sdc1	$f28,0x30($sp)
/*  f1a0a78:	3c013f80 */ 	lui	$at,0x3f80
/*  f1a0a7c:	4481e000 */ 	mtc1	$at,$f28
/*  f1a0a80:	f7be0038 */ 	sdc1	$f30,0x38($sp)
/*  f1a0a84:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1a0a88:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f1a0a8c:	afb50058 */ 	sw	$s5,0x58($sp)
/*  f1a0a90:	afb40054 */ 	sw	$s4,0x54($sp)
/*  f1a0a94:	4481f000 */ 	mtc1	$at,$f30
/*  f1a0a98:	afb30050 */ 	sw	$s3,0x50($sp)
/*  f1a0a9c:	afb2004c */ 	sw	$s2,0x4c($sp)
/*  f1a0aa0:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f1a0aa4:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f1a0aa8:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*  f1a0aac:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f1a0ab0:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f1a0ab4:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f1a0ab8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1a0abc:	0000a825 */ 	or	$s5,$zero,$zero
/*  f1a0ac0:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f1a0ac4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1a0ac8:	24010016 */ 	addiu	$at,$zero,0x16
/*  f1a0acc:	14410042 */ 	bne	$v0,$at,.L0f1a0bd8
/*  f1a0ad0:	3c11800b */ 	lui	$s1,%hi(g_FrData)
/*  f1a0ad4:	3c13800b */ 	lui	$s3,%hi(g_FrData+0x438)
/*  f1a0ad8:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f1a0adc:	4480d000 */ 	mtc1	$zero,$f26
/*  f1a0ae0:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f1a0ae4:	2673d158 */ 	addiu	$s3,$s3,%lo(g_FrData+0x438)
/*  f1a0ae8:	2631cd20 */ 	addiu	$s1,$s1,%lo(g_FrData)
/*  f1a0aec:	8e220010 */ 	lw	$v0,0x10($s1)
.L0f1a0af0:
/*  f1a0af0:	000277c2 */ 	srl	$t6,$v0,0x1f
/*  f1a0af4:	11c00035 */ 	beqz	$t6,.L0f1a0bcc
/*  f1a0af8:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f1a0afc:	07000033 */ 	bltz	$t8,.L0f1a0bcc
/*  f1a0b00:	00024040 */ 	sll	$t0,$v0,0x1
/*  f1a0b04:	05030032 */ 	bgezl	$t0,.L0f1a0bd0
/*  f1a0b08:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f1a0b0c:	92290040 */ 	lbu	$t1,0x40($s1)
/*  f1a0b10:	312a0040 */ 	andi	$t2,$t1,0x40
/*  f1a0b14:	5140002e */ 	beqzl	$t2,.L0f1a0bd0
/*  f1a0b18:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f1a0b1c:	8e300014 */ 	lw	$s0,0x14($s1)
/*  f1a0b20:	8e420284 */ 	lw	$v0,0x284($s2)
/*  f1a0b24:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f1a0b28:	c444037c */ 	lwc1	$f4,0x37c($v0)
/*  f1a0b2c:	c60a000c */ 	lwc1	$f10,0xc($s0)
/*  f1a0b30:	c4480380 */ 	lwc1	$f8,0x380($v0)
/*  f1a0b34:	46062501 */ 	sub.s	$f20,$f4,$f6
/*  f1a0b38:	c6120010 */ 	lwc1	$f18,0x10($s0)
/*  f1a0b3c:	c4500384 */ 	lwc1	$f16,0x384($v0)
/*  f1a0b40:	460a4581 */ 	sub.s	$f22,$f8,$f10
/*  f1a0b44:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f1a0b48:	46128601 */ 	sub.s	$f24,$f16,$f18
/*  f1a0b4c:	4616b182 */ 	mul.s	$f6,$f22,$f22
/*  f1a0b50:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f1a0b54:	4618c282 */ 	mul.s	$f10,$f24,$f24
/*  f1a0b58:	0c012974 */ 	jal	sqrtf
/*  f1a0b5c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f1a0b60:	4600d03c */ 	c.lt.s	$f26,$f0
/*  f1a0b64:	00000000 */ 	nop
/*  f1a0b68:	45020019 */ 	bc1fl	.L0f1a0bd0
/*  f1a0b6c:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f1a0b70:	8e420284 */ 	lw	$v0,0x284($s2)
/*  f1a0b74:	c4500388 */ 	lwc1	$f16,0x388($v0)
/*  f1a0b78:	c444038c */ 	lwc1	$f4,0x38c($v0)
/*  f1a0b7c:	c44a0390 */ 	lwc1	$f10,0x390($v0)
/*  f1a0b80:	4610a482 */ 	mul.s	$f18,$f20,$f16
/*  f1a0b84:	00000000 */ 	nop
/*  f1a0b88:	4604b182 */ 	mul.s	$f6,$f22,$f4
/*  f1a0b8c:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f1a0b90:	46185402 */ 	mul.s	$f16,$f10,$f24
/*  f1a0b94:	46088100 */ 	add.s	$f4,$f16,$f8
/*  f1a0b98:	46002083 */ 	div.s	$f2,$f4,$f0
/*  f1a0b9c:	461a103c */ 	c.lt.s	$f2,$f26
/*  f1a0ba0:	00000000 */ 	nop
/*  f1a0ba4:	45000009 */ 	bc1f	.L0f1a0bcc
/*  f1a0ba8:	00000000 */ 	nop
/*  f1a0bac:	461c103c */ 	c.lt.s	$f2,$f28
/*  f1a0bb0:	00000000 */ 	nop
/*  f1a0bb4:	45020006 */ 	bc1fl	.L0f1a0bd0
/*  f1a0bb8:	2631003c */ 	addiu	$s1,$s1,0x3c
/*  f1a0bbc:	46001706 */ 	mov.s	$f28,$f2
/*  f1a0bc0:	0200a025 */ 	or	$s4,$s0,$zero
/*  f1a0bc4:	46000786 */ 	mov.s	$f30,$f0
/*  f1a0bc8:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f1a0bcc:
/*  f1a0bcc:	2631003c */ 	addiu	$s1,$s1,0x3c
.L0f1a0bd0:
/*  f1a0bd0:	5633ffc7 */ 	bnel	$s1,$s3,.L0f1a0af0
/*  f1a0bd4:	8e220010 */ 	lw	$v0,0x10($s1)
.L0f1a0bd8:
/*  f1a0bd8:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f1a0bdc:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f1a0be0:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f1a0be4:	02a01025 */ 	or	$v0,$s5,$zero
/*  f1a0be8:	e57e0258 */ 	swc1	$f30,0x258($t3)
/*  f1a0bec:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f1a0bf0:	ad94025c */ 	sw	$s4,0x25c($t4)
/*  f1a0bf4:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f1a0bf8:	8fb50058 */ 	lw	$s5,0x58($sp)
/*  f1a0bfc:	8fb40054 */ 	lw	$s4,0x54($sp)
/*  f1a0c00:	8fb30050 */ 	lw	$s3,0x50($sp)
/*  f1a0c04:	8fb2004c */ 	lw	$s2,0x4c($sp)
/*  f1a0c08:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f1a0c0c:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f1a0c10:	d7be0038 */ 	ldc1	$f30,0x38($sp)
/*  f1a0c14:	d7bc0030 */ 	ldc1	$f28,0x30($sp)
/*  f1a0c18:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*  f1a0c1c:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f1a0c20:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f1a0c24:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f1a0c28:	03e00008 */ 	jr	$ra
/*  f1a0c2c:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

// Mismatch because f26 and f28 are swapped and the multiplication order for
// travelspeed is different. f26 should be constant 0 (used in dist > 0 and
// value < 0 checks) and f28 should be bestvalue.
//bool frChooseFarsightTarget(void)
//{
//	f32 bestvalue = 1;
//	f32 bestdist = -1;
//	struct prop *bestprop = NULL;
//	bool found = false;
//	s32 i;
//
//	if (getCurrentPlayerWeaponId(0) == WEAPON_FARSIGHTXR20) {
//		for (i = 0; i < ARRAYCOUNT(g_FrData.targets); i++) {
//			if (g_FrData.targets[i].inuse
//					&& g_FrData.targets[i].destroyed == false
//					&& g_FrData.targets[i].active
//					&& g_FrData.targets[i].flags & FRTARGETFLAG_FARSIGHTAUTOTARGETABLE) {
//				struct prop *prop = g_FrData.targets[i].prop;
//				f32 xdiff = g_Vars.currentplayer->bond2.unk10.x - prop->pos.x;
//				f32 ydiff = g_Vars.currentplayer->bond2.unk10.y - prop->pos.y;
//				f32 zdiff = g_Vars.currentplayer->bond2.unk10.z - prop->pos.z;
//				f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
//
//				if (dist > 0) {
//					f32 value = (
//							g_Vars.currentplayer->bond2.unk1c.x * xdiff +
//							g_Vars.currentplayer->bond2.unk1c.y * ydiff +
//							g_Vars.currentplayer->bond2.unk1c.z * zdiff) / dist;
//
//					if (value < 0 && value < bestvalue) {
//						bestvalue = value;
//						bestprop = prop;
//						bestdist = dist;
//						found = true;
//					}
//				}
//			}
//		}
//	}
//
//	g_Vars.currentplayer->autoeraserdist = bestdist;
//	g_Vars.currentplayer->autoerasertarget = bestprop;
//
//	return found;
//}

s32 frIsInTraining(void)
{
	if (g_FrData.menucountdown > 0 &&
			(g_FrData.menutype == FRMENUTYPE_FAILED || g_FrData.menutype == FRMENUTYPE_COMPLETED)) {
		return true;
	}

	return g_Vars.currentplayer->prop->rooms[0] == CIROOM_FIRINGRANGE
		&& g_FrIsValidWeapon
		&& getCurrentStageId() == STAGE_CITRAINING;
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
					|| g_FrData.targets[i].invincibletimer >= 300) {
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

			g_FrData.feedbackttl = 60;
			g_FrData.score += g_FrData.feedbackzone;
		}
	}
}

void frIncrementNumShots(void)
{
	g_FrData.numshots++;
	g_FrData.numshotssincetopup++;
}

bool ciIsChrBioUnlocked(u32 bodynum)
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

u8 var800888a0 = 0;

struct chrbio *ciGetChrBioByBodynum(u32 bodynum)
{
	struct chrbio bios[] = {
		// name, race, age, profile
		/*0*/ { L_MISC(219), L_MISC(220), L_MISC(221), L_MISC(222) }, // Joanna Dark
		/*1*/ { L_MISC(223), L_MISC(224), L_MISC(225), L_MISC(226) }, // Jonathan
		/*2*/ { L_MISC(227), L_MISC(228), L_MISC(229), L_MISC(230) }, // Daniel Carrington
		/*3*/ { L_MISC(231), L_MISC(232), L_MISC(233), L_MISC(234) }, // Cassandra De Vries
		/*4*/ { L_MISC(235), L_MISC(236), L_MISC(237), L_MISC(238) }, // Trent Easton
		/*5*/ { L_MISC(239), L_MISC(240), L_MISC(241), L_MISC(242) }, // Dr. Caroll
		/*6*/ { L_MISC(243), L_MISC(244), L_MISC(245), L_MISC(246) }, // Elvis
		/*7*/ { L_MISC(247), L_MISC(248), L_MISC(249), L_MISC(250) }, // Mr. Blonde
		/*8*/ { L_MISC(251), L_MISC(252), L_MISC(253), L_MISC(254) }, // Mr. Blonde (repeat)
		/*9*/ { L_MISC(255), L_MISC(256), L_MISC(257), L_MISC(258) }, // The U.S. President
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
	struct chrbio *bio = ciGetChrBioByBodynum(ciGetChrBioIndexBySlot(var800888a0));
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

s32 ciGetChrBioIndexBySlot(s32 slot)
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
	struct miscbio bios[] = {
		// name, description
		{ L_MISC(259), L_MISC(260) },
		{ L_MISC(261), L_MISC(262) },
		{ L_MISC(263), L_MISC(264) },
		{ L_MISC(265), L_MISC(266) },
	};

	switch (index) {
	case MISCBIO_MAIANS:     return &bios[0];
	case MISCBIO_SKEDAR:     return &bios[1];
	case MISCBIO_BACKGROUND: return &bios[2];
	case MISCBIO_STORY:      return &bios[3];
	}

	return NULL;
}

bool ciIsMiscBioUnlocked(s32 index)
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
	s32 index = ciGetMiscBioIndexBySlot(var800888a0 - ciGetNumUnlockedChrBios());
	struct miscbio *bio = ciGetMiscBio(index);

	return langGet(bio->description);
}

bool ciIsHangarBioAVehicle(s32 index)
{
	return index >= HANGARBIO_JUMPSHIP;
}

u8 g_HangarBioSlot = 0;

struct hangarbio *ciGetHangarBio(s32 index)
{
	struct hangarbio bios[] = {
		// name, description
		{ L_MISC(290), L_MISC(313) }, // Carrington Institute
		{ L_MISC(291), L_MISC(314) }, // Lucerne Tower
		{ L_MISC(292), L_MISC(315) }, // Laboratory Basement
		{ L_MISC(293), L_MISC(316) }, // Carrington Villa
		{ L_MISC(294), L_MISC(317) }, // Chicago
		{ L_MISC(295), L_MISC(318) }, // G5 Building
		{ L_MISC(296), L_MISC(319) }, // Area 51
		{ L_MISC(297), L_MISC(320) }, // Alaskan Air Base
		{ L_MISC(298), L_MISC(321) }, // Air Force One
		{ L_MISC(299), L_MISC(322) }, // Crash Site
		{ L_MISC(300), L_MISC(323) }, // Pelagic II
		{ L_MISC(301), L_MISC(324) }, // Cetan Ship
		{ L_MISC(302), L_MISC(325) }, // Skedar Assault Ship
		{ L_MISC(303), L_MISC(326) }, // Skedar Homeworld
		{ L_MISC(304), L_MISC(327) }, // Jumpship
		{ L_MISC(305), L_MISC(328) }, // HoverCrate
		{ L_MISC(306), L_MISC(329) }, // HoverBike
		{ L_MISC(307), L_MISC(330) }, // Cleaning Hovbot
		{ L_MISC(308), L_MISC(331) }, // Hovercopter
		{ L_MISC(309), L_MISC(332) }, // G5 Robot
		{ L_MISC(310), L_MISC(333) }, // A51 Interceptor
		{ L_MISC(311), L_MISC(334) }, // Maian Vessel
		{ L_MISC(312), L_MISC(335) }, // Skedar Shuttle
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

bool ciIsHangarBioUnlocked(u32 bioindex)
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

void dtRestorePlayer(void)
{
	playersSetPassiveMode(true);

	if (g_DtData.obj) {
		setupParseObjectWithArg2False(g_DtData.obj, true);
	}

	g_DtData.obj = NULL;

	if (dtGetWeaponByDeviceIndex(dtGetIndexBySlot(g_DtSlot)) == WEAPON_ECMMINE) {
		currentPlayerSetAmmoQuantity(AMMOTYPE_ECM_MINE, 0);
	}

	if (g_Vars.currentplayer->eyespy) {
		struct chrdata *chr = g_Vars.currentplayer->eyespy->prop->chr;
		g_Vars.currentplayer->eyespy->initialised = false;
		g_Vars.currentplayer->eyespy->init = true;
		g_Vars.currentplayer->eyespy->active = false;

		chr->chrflags |= CHRCFLAG_HIDDEN;

		func0f0926bc(g_Vars.currentplayer->eyespy->prop, 1, 0xffff);

		g_Vars.currentplayer->itemswitch &= ~0x04;
	}
}

void dtPushEndscreen(void)
{
	if (g_DtData.completed) {
		func0f0f85e0(&g_DeviceTrainingStatsCompletedMenuDialog, MENUROOT_TRAINING);
	} else if (g_DtData.failed) {
		func0f0f85e0(&g_DeviceTrainingStatsFailedMenuDialog, MENUROOT_TRAINING);
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
			g_DtData.timetaken += g_Vars.lvupdate240_60;

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
				g_DtData.timeleft -= g_Vars.lvupdate240_60;
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
	playersSetPassiveMode(false);
	chrSetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
}

void dtEnd(void)
{
	g_DtData.intraining = false;
	dtRestorePlayer();
	currentPlayerSetAmmoQuantity(AMMOTYPE_CLOAK, 0);
	chrSetStageFlag(NULL, STAGEFLAG_CI_DEVICE_ABORTING);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_DEVICE_FAILURE);
	chrUnsetStageFlag(NULL, ciGetStageFlagByDeviceIndex(dtGetIndexBySlot(g_DtSlot)));
	g_Vars.currentplayer->training = false;
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
	func0f0bb69c();
	g_Vars.currentplayer->bondhealth = 1;
}

bool dtIsAvailable(s32 deviceindex)
{
	u8 flags[] = {
		SAVEFILEFLAG_CI_UPLINK_DONE,
		SAVEFILEFLAG_CI_ECMMINE_DONE,
		SAVEFILEFLAG_CI_CAMSPY_DONE,
		SAVEFILEFLAG_CI_NIGHTVISION_DONE,
		SAVEFILEFLAG_CI_DOORDECODER_DONE,
		SAVEFILEFLAG_CI_RTRACKER_DONE,
		SAVEFILEFLAG_CI_IR_DONE,
		SAVEFILEFLAG_CI_XRAY_DONE,
		SAVEFILEFLAG_CI_DISGUISE_DONE,
		SAVEFILEFLAG_CI_CLOAK_DONE,
	};

	deviceindex--;

	if (deviceindex >= 10) {
		return true;
	}

	if (deviceindex < 0 || savefileHasFlag(flags[deviceindex])) {
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
	u32 weapons[] = {
		WEAPON_DATAUPLINK,
		WEAPON_ECMMINE,
		WEAPON_CAMSPY,
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

u32 ciGetStageFlagByDeviceIndex(u32 deviceindex)
{
	u32 flags[] = {
		STAGEFLAG_CI_TRIGGER_UPLINK,
		STAGEFLAG_CI_TRIGGER_ECMMINE,
		STAGEFLAG_CI_TRIGGER_CAMSPY,
		STAGEFLAG_CI_TRIGGER_NIGHTVISION,
		STAGEFLAG_CI_TRIGGER_DOORDECODER,
		STAGEFLAG_CI_TRIGGER_RTRACKER,
		STAGEFLAG_CI_TRIGGER_IR,
		STAGEFLAG_CI_TRIGGER_XRAY,
		STAGEFLAG_CI_TRIGGER_DISGUISE,
		STAGEFLAG_CI_TRIGGER_CLOAK,
	};

	return flags[deviceindex];
}

char *dtGetDescription(void)
{
	u32 texts[] = {
		/*0*/ L_MISC(280), // Data uplink
		/*1*/ L_MISC(279), // ECM mine
		/*2*/ L_MISC(271), // CamSpy
		/*3*/ L_MISC(272), // Night vision
		/*4*/ L_MISC(273), // Door decoder
		/*5*/ L_MISC(277), // R-tracker
		/*6*/ L_MISC(276), // IR scanner
		/*7*/ L_MISC(274), // X-ray scanner
		/*8*/ L_MISC(275), // Disguise
		/*9*/ L_MISC(278), // Cloak
	};

	return langGet(texts[dtGetIndexBySlot(g_DtSlot)]);
}

char *dtGetTip1(void)
{
	u32 texts[] = {
		/*0*/ L_MISC(357),
		/*1*/ L_MISC(358),
		/*2*/ L_MISC(359),
		/*3*/ L_MISC(360),
		/*4*/ L_MISC(361),
		/*5*/ L_MISC(362),
		/*6*/ L_MISC(363),
		/*7*/ L_MISC(364),
		/*8*/ L_MISC(365),
		/*9*/ L_MISC(366),
	};

	return langGet(texts[dtGetIndexBySlot(g_DtSlot)]);
}

char *dtGetTip2(void)
{
	u32 texts[] = {
		/*0*/ L_MISC(367),
		/*1*/ L_MISC(368),
		/*2*/ L_MISC(369),
		/*3*/ L_MISC(370),
		/*4*/ L_MISC(371),
		/*5*/ L_MISC(372),
		/*6*/ L_MISC(373),
		/*7*/ L_MISC(374),
		/*8*/ L_MISC(375),
		/*9*/ L_MISC(376),
	};

	return langGet(texts[dtGetIndexBySlot(g_DtSlot)]);
}

struct trainingdata *getHoloTrainingData(void)
{
	return &g_HoloTrainingData;
}

void htPushEndscreen(void)
{
	if (g_HoloTrainingData.completed) {
		func0f0f85e0(&g_HoloTrainingStatsCompletedMenuDialog, MENUROOT_TRAINING);
	} else if (g_HoloTrainingData.failed) {
		func0f0f85e0(&g_HoloTrainingStatsFailedMenuDialog, MENUROOT_TRAINING);
	}

	g_HoloTrainingData.timeleft = 0;
	g_HoloTrainingData.completed = false;
	g_HoloTrainingData.failed = false;
	g_HoloTrainingData.finished = false;
}

u8 var80088bb4 = 0;
u8 var80088bb8 = 0;

void htTick(void)
{
	if (var80088bb8) {
		if (g_HoloTrainingData.intraining) {
			g_HoloTrainingData.timetaken += g_Vars.lvupdate240_60;

			if (g_Vars.currentplayer->isdead) {
				htEnd();
			}

			if (chrHasStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_FAILURE)) {
				htEnd();
				g_HoloTrainingData.failed = true;
				g_HoloTrainingData.timeleft = 1;
				g_HoloTrainingData.finished = true;
			} else if (chrHasStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_SUCCESS)) {
				htEnd();
				g_HoloTrainingData.completed = true;
				g_HoloTrainingData.timeleft = 1;
				g_HoloTrainingData.finished = true;
			}
		} else if (g_HoloTrainingData.finished) {
			if (g_HoloTrainingData.timeleft <= 0) {
				htPushEndscreen();
			} else {
				g_HoloTrainingData.timeleft -= g_Vars.lvupdate240_60;
			}
		}
	}
}

void func0f1a2198(void)
{
	if (var80088bb8 == false) {
		var80088bb8 = true;
		g_HoloTrainingData.intraining = false;
		g_HoloTrainingData.failed = false;
		g_HoloTrainingData.completed = false;
		g_HoloTrainingData.finished = false;
		g_HoloTrainingData.timeleft = 0;
		g_HoloTrainingData.timetaken = 0;
		chrUnsetStageFlag(NULL, STAGEFLAG_CI_HOLO_ABORTING);
		chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_SUCCESS);
		chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_FAILURE);
	}
}

void htBegin(void)
{
	struct stagesetup00 *setup00 = g_StageSetup.unk00;

	g_HoloTrainingData.intraining = true;
	g_HoloTrainingData.timetaken = 0;
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_HOLO_ABORTING);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_SUCCESS);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_FAILURE);
	chrSetStageFlag(NULL, func0f1a25c0(htGetIndexBySlot(var80088bb4)));
	func0f115a48(&setup00->unk200, &setup00->unk310);
	g_Vars.currentplayer->training = true;
	playersSetPassiveMode(false);
	chrSetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
}

void htEnd(void)
{
	struct prop *prop;
	s16 *propnum;
	s16 propnums[256];
	s16 rooms[5] = { 0x0016, 0x0017, 0x0018, 0x0019, -1 };
	struct stagesetup00 *setup00 = g_StageSetup.unk00;

	g_HoloTrainingData.intraining = false;
	chrSetStageFlag(NULL, STAGEFLAG_CI_HOLO_ABORTING);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_TRIGGER_HOLO_FAILURE);
	chrUnsetStageFlag(NULL, func0f1a25c0(htGetIndexBySlot(var80088bb4)));
	func0f115a78(&setup00->unk200, &setup00->unk310);
	g_Vars.currentplayer->training = false;
	roomGetProps(rooms, propnums, 256);
	propnum = &propnums[0];

	// Remove dropped weapons
	while (*propnum >= 0) {
		prop = &g_Vars.props[*propnum];

		if (prop && prop->type == PROPTYPE_WEAPON) {
			struct defaultobj *obj = prop->obj;

			if (obj->type == OBJTYPE_WEAPON) {
				setupParseObjectWithArg2False(obj, true);
			}
		}

		propnum++;
	}

	playersSetPassiveMode(true);
	chrUnsetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
	func0f0bb69c();
	g_Vars.currentplayer->bondhealth = 1;
}

bool htIsUnlocked(u32 value)
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
	u32 texts[] = {
		L_MISC(410), // "Holo 1 - Looking Around"
		L_MISC(411), // "Holo 2 - Movement 1"
		L_MISC(412), // "Holo 3 - Movement 2"
		L_MISC(413), // "Holo 4 - Unarmed Combat 1"
		L_MISC(414), // "Holo 5 - Unarmed Combat 2"
		L_MISC(415), // "Holo 6 - Live Combat 1"
		L_MISC(416), // "Holo 7 - Live Combat 2"
	};

	return langGet(texts[index]);
}

u32 func0f1a25c0(s32 index)
{
	u32 flags[] = {
		STAGEFLAG_CI_IN_HOLO1,
		STAGEFLAG_CI_IN_HOLO2,
		STAGEFLAG_CI_IN_HOLO3,
		STAGEFLAG_CI_IN_HOLO4,
		STAGEFLAG_CI_IN_HOLO5,
		STAGEFLAG_CI_IN_HOLO6,
		STAGEFLAG_CI_IN_HOLO7,
		STAGEFLAG_CI_GENERAL_PURPOSE,
	};

	return flags[index];
}

char *htGetDescription(void)
{
	u32 texts[] = {
		L_MISC(336),
		L_MISC(337),
		L_MISC(338),
		L_MISC(339),
		L_MISC(340),
		L_MISC(341),
		L_MISC(342),
	};

	return langGet(texts[htGetIndexBySlot(var80088bb4)]);
}

char *htGetTip1(void)
{
	u32 texts[] = {
		L_MISC(343), // "For greater precision..."
		L_MISC(344), // "Think about where you want to go..."
		L_MISC(345), // "Ducking enables you to..."
		L_MISC(346), // "Attacking opponents from behind..."
		L_MISC(347), // "Only stay close long enough..."
		L_MISC(348), // "Don't hang around and wait..."
		L_MISC(349), // "Go for the armed opponents..."
	};

	return langGet(texts[htGetIndexBySlot(var80088bb4)]);
}

char *htGetTip2(void)
{
	u32 texts[] = {
		L_MISC(350), // "For greater precision..."
		L_MISC(351), // "Sidestepping and strafing..."
		L_MISC(352), // "Ducking enables you to..."
		L_MISC(353), // "Attacking opponents from behind..."
		L_MISC(354), // "Only stay close long enough..."
		L_MISC(355), // "Don't hang around and wait..."
		L_MISC(356), // "Go for the armed opponents..."
	};

	return langGet(texts[htGetIndexBySlot(var80088bb4)]);
}

void frGetGoalTargetsText(char *buffer)
{
	// "GOAL TARGETS:"
	sprintf(buffer, "%s %d\n", langGet(L_MISC(417)), g_FrData.goaltargets);
}

void frGetTargetsDestroyedValue(char *buffer)
{
	sprintf(buffer, "%02d\n", g_FrData.targetsdestroyed);
}

void frGetScoreValue(char *buffer)
{
	sprintf(buffer, "%03d\n", g_FrData.score);
}

void frGetGoalScoreText(char *buffer)
{
	if (g_FrData.goalscore) {
		// "GOAL SCORE:"
		sprintf(buffer, "%s %d\n", langGet(L_MISC(418)), g_FrData.goalscore);
	} else {
		sprintf(buffer, "");
	}
}

f32 frGetAccuracy(char *buffer)
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

bool frGetMinAccuracy(char *buffer, f32 accuracy)
{
	// "MIN ACCURACY:"
	sprintf(buffer, "%s %d%%\n", langGet(L_MISC(419)), g_FrData.goalaccuracy);

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
bool frFormatTime(char *buffer)
{
	s32 mins = 0;
	s32 mult = 1;
	f32 secs = g_FrData.timetaken / 60.0f;
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

bool frGetHudMiddleSubtext(char *buffer)
{
	s32 secs;
	s32 mins;

	if (g_FrData.timetaken < -180) {
		sprintf(buffer, "%s", langGet(L_MISC(420))); // "FIRE TO START"
		return false;
	}

	if (g_FrData.timetaken < 0) {
		sprintf(buffer, "%s", langGet(L_MISC(421))); // "GET READY!"
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

	sprintf(buffer, "%s %02d:%02d\n", langGet(L_MISC(422)), mins, secs); // "LIMIT:"
	return true;
}

bool frGetFeedback(char *scorebuffer, char *zonebuffer)
{
	u32 texts[] = {
		L_MISC(423), // "ZONE 3"
		L_MISC(424), // "ZONE 2"
		L_MISC(425), // "ZONE 1"
		L_MISC(426), // "BULL'S-EYE"
		L_MISC(427), // "EXPLODED"
	};

	if (g_FrData.feedbackzone) {
		g_FrData.feedbackttl -= g_Vars.lvupdate240_60;

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
			sprintf(zonebuffer, "%s", langGet(texts[0]));
			return true;
		case FRZONE_RING2:
			sprintf(zonebuffer, "%s", langGet(texts[1]));
			return true;
		case FRZONE_RING1:
			sprintf(zonebuffer, "%s", langGet(texts[2]));
			return true;
		case FRZONE_BULLSEYE:
			sprintf(zonebuffer, "%s", langGet(texts[3]));
			return true;
		case FRZONE_EXPLODE:
			sprintf(zonebuffer, "%s", langGet(texts[4]));
			return true;
		}

		sprintf(zonebuffer, "\n");
		return true;
	}

	return false;
}

Gfx *frRenderHudElement(Gfx *gdl, s32 x, s32 y, char *string1, char *string2, u32 colour, u8 alpha)
{
	s32 textheight;
	s32 textwidth;
	s32 x2;
	s32 y2;

	u32 halfalpha = alpha >> 1;
	u32 fullcolour = (colour & 0xffffff00) | alpha;

	textMeasure(&textheight, &textwidth, string1, var8007fb18, var8007fb14, 0);

	x2 = x - (textwidth >> 1);
	y2 = y;
	gdl = func0f153858(gdl, &x2, &y2, &textwidth, &textheight);

	gdl = textRender(gdl, &x2, &y2, string1,
			var8007fb18, var8007fb14, fullcolour, halfalpha, viGetX(), viGetY(), 0, 0);

	if (string2) {
		textMeasure(&textheight, &textwidth, string2, var8007fb08, var8007fb04, 0);

		x2 = x - (textwidth >> 1);
		y2 = y + 17;
		gdl = func0f153858(gdl, &x2, &y2, &textwidth, &textheight);

		gdl = textRender(gdl, &x2, &y2, string2,
			var8007fb08, var8007fb04, fullcolour, halfalpha, viGetX(), viGetY(), 0, 0);
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

	if (viGetViewX() > 400) {
		mult = 2;
	} else {
		mult = 1;
	}

	if (!g_FrIsValidWeapon && g_FrData.menucountdown <= 0) {
		return gdl;
	}

	if (g_FrData.menucountdown != 0) {
		alpha = (f32)(g_FrData.menucountdown * 160) / 60.0f;
	}

	gdl = func0f153628(gdl);

	// Time
	red = frFormatTime(string1);
	exists = frGetHudMiddleSubtext(string2);

	gdl = frRenderHudElement(gdl, viGetViewX() >> 1, viGetViewTop() + 12,
			string1, exists ? string2 : NULL,
			red ? 0xff000000 | 0xa0 : 0x00ff0000 | 0xa0,
			alpha);

	// Score
	frGetScoreValue(string1);
	frGetGoalScoreText(string2);
	gdl = frRenderHudElement(gdl, viGetViewLeft() + 65.0f * mult, viGetViewTop() + 12,
			string1, string2, 0x00ff00a0, alpha);

	// Feedback
	if (frGetFeedback(string1, string2)) {
		gdl = frRenderHudElement(gdl,viGetViewLeft() + 65.0f * mult, viGetViewTop() + 40,
				string1, string2, 0x00ff00a0, alpha);
	}

	if (g_FrData.goalaccuracy > 0) {
		red = frGetMinAccuracy(string2, frGetAccuracy(string1));

		gdl = frRenderHudElement(gdl, viGetViewLeft() + viGetViewX() - 70.0f * mult, viGetViewTop() + 12,
				string1, string2,
				red ? 0xff000000 | 0xa0 : 0x00ff0000 | 0xa0,
				alpha);
	} else if (g_FrData.goaltargets != 255) {
		frGetTargetsDestroyedValue(string1);
		frGetGoalTargetsText(string2);

		if (mult == 2) {
			mult = 2.4;
		}

		gdl = frRenderHudElement(gdl, viGetViewLeft() + viGetViewX() - 70.0f * mult, viGetViewTop() + 12,
				string1, string2, 0x00ff00a0, alpha);
	}

	return func0f153780(gdl);
}
