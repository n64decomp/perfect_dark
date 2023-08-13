#include <ultra64.h>
#include "constants.h"
#include "game/race.h"
#include "game/floor.h"
#include "bss.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

u16 raceGetAnimSumAngleAsInt(s16 animnum, s32 frame, s32 endframe)
{
	s16 inttranslate[3];
	u16 sumangle = 0;

	while (frame < endframe) {
		sumangle += animGetPosAngleAsInt(0, false, &g_SkelChr, animnum, frame, inttranslate, false);
		frame++;
	}

	return sumangle;
}

s32 raceGetAnimSumForwardAsInt(s16 animnum, s32 frame, s32 endframe)
{
	s32 sumforward = 0;
	s16 inttranslate[3];

	while (frame < endframe) {
		animGetPosAngleAsInt(0, false, &g_SkelChr, animnum, frame, inttranslate, false);
		sumforward += inttranslate[2];
		frame++;
	}

	return sumforward;
}

s32 raceInitAnimGroup(struct attackanimconfig *configs)
{
	s32 count = 0;
	struct attackanimconfig *config = configs;

	while (config->animnum != 0) {
		u16 angle = raceGetAnimSumAngleAsInt(config->animnum, 0, floortoint(config->unk04));

		if (config->unk04 > 0) {
			if (angle < 0x8000) {
				config->unk08 = angle * 0.00009585853695171f / config->unk04;
			} else {
				config->unk08 = (angle * 0.00009585853695171f - M_BADTAU) / config->unk04;
			}
		} else {
			config->unk08 = 0;
		}

		config++;
		count++;
	}

	return count;
}

#ifdef AVOID_UB
// TODO: make raceInitAnimGroup call this or something
s32 raceInitAnimConfigSingle(struct attackanimconfig *config)
{
	s32 count = 0;


	if (config->animnum != 0) {
		u16 angle = raceGetAnimSumAngleAsInt(config->animnum, 0, floortoint(config->unk04));

		if (config->unk04 > 0) {
			if (angle < 0x8000) {
				config->unk08 = angle * 0.00009585853695171f / config->unk04;
			} else {
				config->unk08 = (angle * 0.00009585853695171f - M_BADTAU) / config->unk04;
			}
		} else {
			config->unk08 = 0;
		}

		count++;
	}

	return count;
}
#endif

void raceInitAnimGroups(struct attackanimgroup **groups)
{
	s32 i;

	for (i = 0; i < 32; i++) {
		if (groups[i]->len < 0) {
			groups[i]->len = raceInitAnimGroup(groups[i]->animcfg);
		}
	}
}

s32 raceCountAnims(struct animtablerow *rows)
{
	s32 i;

	for (i = 0; rows[i].animnum > 0; i++);

	return i;
}

f32 race0f0005c0(s16 animnum)
{
	f32 avgforward = raceGetAnimSumForwardAsInt(animnum, 0, animGetNumFrames(animnum) - 1) / (f32) animGetNumFrames(animnum);

	var8005f014[animnum] = avgforward;

	return avgforward * 0.1000000089407f;
}

void raceInitAnims(void)
{
	s32 race;
	s32 i;

	for (race = 0; race < ARRAYCOUNT(g_AnimTablesByRace); race++) {
		for (i = 0; g_AnimTablesByRace[race][i].hitpart != -1; i++) {
			if (g_AnimTablesByRace[race][i].deathanims) {
				g_AnimTablesByRace[race][i].deathanimcount = raceCountAnims(g_AnimTablesByRace[race][i].deathanims);
			} else {
				g_AnimTablesByRace[race][i].deathanimcount = 0;
			}

			if (g_AnimTablesByRace[race][i].injuryanims) {
				g_AnimTablesByRace[race][i].injuryanimcount = raceCountAnims(g_AnimTablesByRace[race][i].injuryanims);
			} else {
				g_AnimTablesByRace[race][i].injuryanimcount = 0;
			}
		}

		for (i = 0; var80067fdc[race][i].animnum >= 0; i++) {
			var80067fdc[race][i].value = race0f0005c0(var80067fdc[race][i].animnum);
		}
	}

	raceCountAnims(g_AnimTableHumanSlumped);

	for (race = 0; race < 2; race++) {
		raceInitAnimGroups(g_StandHeavyAttackAnims[race]);
		raceInitAnimGroups(g_StandLightAttackAnims[race]);
		raceInitAnimGroups(g_StandDualAttackAnims[race]);
		raceInitAnimGroups(g_KneelHeavyAttackAnims[race]);
		raceInitAnimGroups(g_KneelLightAttackAnims[race]);
		raceInitAnimGroups(g_KneelDualAttackAnims[race]);
	}

	raceInitAnimGroup(g_RollAttackAnims);

#ifdef AVOID_UB
	// don't depend on globalvar order
	for (s32 i = 0; g_AttackAnimArray[i]; ++i) {
		raceInitAnimConfigSingle(g_AttackAnimArray[i]);
	}
#else
	raceInitAnimGroup(&g_AttackAnimHeavyWalk);
#endif
}
