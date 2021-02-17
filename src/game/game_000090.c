#include <ultra64.h>
#include "constants.h"
#include "game/game_000090.h"
#include "game/game_000130.h"
#include "game/chr/chr.h"
#include "gvars/gvars.h"
#include "data.h"
#include "types.h"

void func0f000090(void)
{
	g_TitleMode = -1;
	g_TitleNextMode = TITLEMODE_LEGAL;
	g_TitleTimer = 0;
	g_TitleNextStage = -1;
	var800624e0 = 0;
	var800624e8 = 1;
	var800624ec = 0;
	var800624f0 = 0;
	var800624f4 = 1;
	g_MissionConfig.pdmodereaction = 0;
	g_MissionConfig.pdmodehealth = 128;
	g_MissionConfig.pdmodedamage = 128;
	g_MissionConfig.pdmodeaccuracy = 128;
}

void func0f000100(void)
{
	func0001a518(&func0f01e760);
	func0f000648();
}
