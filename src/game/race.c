#include <ultra64.h>
#include "constants.h"
#include "game/race.h"
#include "game/floor.h"
#include "bss.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

static u16 raceInitAnim(s16 animnum, s32 frame, s32 endframe)
{
	s16 sp48[4];
	u16 count = 0;

	while (frame < endframe) {
		count += anim0002485c(0, false, &g_SkelChr, animnum, frame, sp48, false);
		frame++;
	}

	return count;
}

static s32 race0f000358(s16 animnum, s32 frame, s32 endframe)
{
	s32 count = 0;
	s16 sp44[4];

	while (frame < endframe) {
		anim0002485c(0, false, &g_SkelChr, animnum, frame, sp44, false);
		count += sp44[2];
		frame++;
	}

	return count;
}

static s32 raceInitAnimGroup(struct attackanimconfig *configs)
{
	s32 count = 0;
	struct attackanimconfig *config = configs;

	while (config->animnum != 0) {
		u16 value = raceInitAnim(config->animnum, 0, floor(config->unk04));

		if (config->unk04 > 0) {
			if (value < 0x8000) {
				config->unk08 = value * 0.00009585853695171f / config->unk04;
			} else {
				config->unk08 = (value * 0.00009585853695171f - M_BADTAU) / config->unk04;
			}
		} else {
			config->unk08 = 0;
		}

		config++;
		count++;
	}

	return count;
}

static void raceInitAnimGroups(struct attackanimgroup **groups)
{
	s32 i;

	for (i = 0; i < 32; i++) {
		if (groups[i]->len < 0) {
			groups[i]->len = raceInitAnimGroup(groups[i]->animcfg);
		}
	}
}

static s32 raceCountAnims(struct animtablerow *rows)
{
	s32 i;

	for (i = 0; rows[i].animnum > 0; i++);

	return i;
}

static f32 race0f0005c0(s16 animnum)
{
	f32 tmp = race0f000358(animnum, 0, animGetNumFrames(animnum) - 1) / (f32) animGetNumFrames(animnum);

	var8005f014[animnum] = tmp;

	return tmp * 0.1000000089407f;
}

void raceInitAnims(void)
{
	s32 race;
	s32 i;

	for (race = 0; race < 5; race++) {
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
	raceInitAnimGroup(&g_AttackAnimHeavyWalk);
}
