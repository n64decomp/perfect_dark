#include <ultra64.h>
#include "constants.h"
#include "game/race.h"
#include "game/floor.h"
#include "bss.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

u16 race_get_anim_sum_angle_as_int(s16 animnum, s32 frame, s32 endframe)
{
	s16 inttranslate[3];
	u16 sumangle = 0;

	while (frame < endframe) {
		sumangle += anim_get_pos_angle_as_int(0, false, &g_SkelChr, animnum, frame, inttranslate, false);
		frame++;
	}

	return sumangle;
}

s32 race_get_anim_sum_forward_as_int(s16 animnum, s32 frame, s32 endframe)
{
	s32 sumforward = 0;
	s16 inttranslate[3];

	while (frame < endframe) {
		anim_get_pos_angle_as_int(0, false, &g_SkelChr, animnum, frame, inttranslate, false);
		sumforward += inttranslate[2];
		frame++;
	}

	return sumforward;
}

s32 race_init_anim_group(struct attackanimconfig *configs)
{
	s32 count = 0;
	struct attackanimconfig *config = configs;

	while (config->animnum != 0) {
		u16 angle = race_get_anim_sum_angle_as_int(config->animnum, 0, floor(config->unk04));

		if (config->unk04 > 0) {
			if (angle < 32768) {
				config->unk08 = angle * (1.0f / (32768 / BADDTOR(180))) / config->unk04;
			} else {
				config->unk08 = (angle * (1.0f / (32768 / BADDTOR(180))) - BADDTOR(360)) / config->unk04;
			}
		} else {
			config->unk08 = 0;
		}

		config++;
		count++;
	}

	return count;
}

void race_init_anim_groups(struct attackanimgroup **groups)
{
	s32 i;

	for (i = 0; i < 32; i++) {
		if (groups[i]->len < 0) {
			groups[i]->len = race_init_anim_group(groups[i]->animcfg);
		}
	}
}

s32 race_count_anims(struct animtablerow *rows)
{
	s32 i;

	for (i = 0; rows[i].animnum > 0; i++);

	return i;
}

f32 race_get_anim_avg_forward(s16 animnum)
{
	f32 avgforward = race_get_anim_sum_forward_as_int(animnum, 0, anim_get_num_frames(animnum) - 1) / (f32) anim_get_num_frames(animnum);

	g_AnimAverageMoveDist[animnum] = avgforward;

	return avgforward * 0.1000000089407f;
}

void race_init_anims(void)
{
	s32 race;
	s32 i;

	for (race = 0; race < ARRAYCOUNT(g_AnimTablesByRace); race++) {
		for (i = 0; g_AnimTablesByRace[race][i].hitpart != -1; i++) {
			if (g_AnimTablesByRace[race][i].deathanims) {
				g_AnimTablesByRace[race][i].deathanimcount = race_count_anims(g_AnimTablesByRace[race][i].deathanims);
			} else {
				g_AnimTablesByRace[race][i].deathanimcount = 0;
			}

			if (g_AnimTablesByRace[race][i].injuryanims) {
				g_AnimTablesByRace[race][i].injuryanimcount = race_count_anims(g_AnimTablesByRace[race][i].injuryanims);
			} else {
				g_AnimTablesByRace[race][i].injuryanimcount = 0;
			}
		}

		for (i = 0; g_ChrAvgAnimMoveDists[race][i].animnum >= 0; i++) {
			g_ChrAvgAnimMoveDists[race][i].value = race_get_anim_avg_forward(g_ChrAvgAnimMoveDists[race][i].animnum);
		}
	}

	race_count_anims(g_AnimTableHumanSlumped);

	for (race = 0; race < 2; race++) {
		race_init_anim_groups(g_StandHeavyAttackAnims[race]);
		race_init_anim_groups(g_StandLightAttackAnims[race]);
		race_init_anim_groups(g_StandDualAttackAnims[race]);
		race_init_anim_groups(g_KneelHeavyAttackAnims[race]);
		race_init_anim_groups(g_KneelLightAttackAnims[race]);
		race_init_anim_groups(g_KneelDualAttackAnims[race]);
	}

	race_init_anim_group(g_RollAttackAnims);
	race_init_anim_group(g_WalkAttackAnims);
}
