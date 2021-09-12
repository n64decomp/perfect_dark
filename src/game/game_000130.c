#include <ultra64.h>
#include "constants.h"
#include "game/game_000130.h"
#include "game/floor.h"
#include "bss.h"
#include "lib/lib_233c0.h"
#include "data.h"
#include "types.h"

void func0f000130(void)
{
	g_NumBondBodies = 0;

	while (g_BondBodies[g_NumBondBodies] >= 0) {
		g_NumBondBodies++;
	}

	g_NumMaleGuardTeamHeads = 0;

	while (g_MaleGuardTeamHeads[g_NumMaleGuardTeamHeads] >= 0) {
		g_NumMaleGuardTeamHeads++;
	}

	g_NumFemaleGuardTeamHeads = 0;

	while (g_FemaleGuardTeamHeads[g_NumFemaleGuardTeamHeads] >= 0) {
		g_NumFemaleGuardTeamHeads++;
	}

	g_NumMaleGuardHeads = 0;

	while (g_MaleGuardHeads[g_NumMaleGuardHeads] >= 0) {
		g_NumMaleGuardHeads++;
	}

	g_NumFemaleGuardHeads = 0;

	while (g_FemaleGuardHeads[g_NumFemaleGuardHeads] >= 0) {
		g_NumFemaleGuardHeads++;
	}
}

u16 func0f0002a0(s16 animnum, s32 frame, s32 endframe)
{
	s16 sp48[4];
	u16 count = 0;

	while (frame < endframe) {
		count += func0002485c(0, 0, &g_ModelTypeChr, animnum, frame, sp48, 0);
		frame++;
	}

	return count;
}

s32 func0f000358(s16 animnum, s32 frame, s32 endframe)
{
	s32 count = 0;
	s16 sp44[4];

	while (frame < endframe) {
		func0002485c(0, 0, &g_ModelTypeChr, animnum, frame, sp44, 0);
		count += sp44[2];
		frame++;
	}

	return count;
}

s32 func0f00040c(struct attackanimconfig *configs)
{
	s32 count = 0;
	struct attackanimconfig *config = configs;

	while (config->animnum != 0) {
		u16 value = func0f0002a0(config->animnum, 0, floor(config->unk04));

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

void func0f00052c(struct attackanimgroup **groups)
{
	s32 i;

	for (i = 0; i < 32; i++) {
		if (groups[i]->len < 0) {
			groups[i]->len = func0f00040c(groups[i]->animcfg);
		}
	}
}

s32 func0f000590(struct animtablerow *rows)
{
	s32 i;

	for (i = 0; rows[i].animnum > 0; i++);

	return i;
}

f32 func0f0005c0(s16 animnum)
{
	f32 tmp = func0f000358(animnum, 0, animGetNumFrames(animnum) - 1) / (f32) animGetNumFrames(animnum);

	var8005f014[animnum] = tmp;

	return tmp * 0.1000000089407f;
}

void func0f000648(void)
{
	s32 race;
	s32 i;

	for (race = 0; race < 5; race++) {
		for (i = 0; g_AnimTablesByRace[race][i].hitpart != -1; i++) {
			if (g_AnimTablesByRace[race][i].deathanims) {
				g_AnimTablesByRace[race][i].deathanimcount = func0f000590(g_AnimTablesByRace[race][i].deathanims);
			} else {
				g_AnimTablesByRace[race][i].deathanimcount = 0;
			}

			if (g_AnimTablesByRace[race][i].injuryanims) {
				g_AnimTablesByRace[race][i].injuryanimcount = func0f000590(g_AnimTablesByRace[race][i].injuryanims);
			} else {
				g_AnimTablesByRace[race][i].injuryanimcount = 0;
			}
		}

		for (i = 0; var80067fdc[race][i].animnum >= 0; i++) {
			var80067fdc[race][i].value = func0f0005c0(var80067fdc[race][i].animnum);
		}
	}

	func0f000590(g_AnimTableHumanSlumped);

	for (race = 0; race < 2; race++) {
		func0f00052c(g_StandHeavyAttackAnims[race]);
		func0f00052c(g_StandLightAttackAnims[race]);
		func0f00052c(g_StandDualAttackAnims[race]);
		func0f00052c(g_KneelHeavyAttackAnims[race]);
		func0f00052c(g_KneelLightAttackAnims[race]);
		func0f00052c(g_KneelDualAttackAnims[race]);
	}

	func0f00040c(g_RollAttackAnims);
	func0f00040c(&g_AttackAnimHeavyWalk);
}
