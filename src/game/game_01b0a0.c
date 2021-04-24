#include <ultra64.h>
#include "constants.h"
#include "game/game_01b0a0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0fd0.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
#include "game/options.h"
#include "bss.h"
#include "data.h"
#include "types.h"

f32 pdmodeGetEnemyReactionSpeed(void)
{
	return 0;
}

f32 pdmodeGetEnemyHealth(void)
{
	if (g_MissionConfig.pdmode) {
		return g_MissionConfig.pdmodehealthf;
	}

	return 1;
}

f32 pdmodeGetEnemyDamage(void)
{
	if (g_MissionConfig.pdmode) {
		return g_MissionConfig.pdmodedamagef;
	}

	return 1;
}

f32 pdmodeGetEnemyAccuracy(void)
{
	if (g_MissionConfig.pdmode) {
		return g_MissionConfig.pdmodeaccuracyf;
	}

	return 1;
}

void func0f01b148(u32 arg0)
{
	var800624e0 = arg0;
}

void titleSetNextStage(s32 stagenum)
{
	g_TitleNextStage = stagenum;
}
