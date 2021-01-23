#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_01b0a0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0fd0.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_13130.h"
#include "lib/lib_13900.h"
#include "types.h"

f32 pdmodeGetReaction(void)
{
	return 0;
}

f32 pdmodeGetHealth(void)
{
	if (g_MissionConfig.pdmode) {
		return g_MissionConfig.pdmodehealthf;
	}

	return 1;
}

f32 pdmodeGetDamage(void)
{
	if (g_MissionConfig.pdmode) {
		return g_MissionConfig.pdmodedamagef;
	}

	return 1;
}

f32 pdmodeGetAccuracy(void)
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
