#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_000090.h"
#include "game/game_000130.h"
#include "game/chr/chr.h"
#include "gvars/gvars.h"
#include "lib/lib_1a500.h"
#include "types.h"

void func0f000090(void)
{
	g_TitleMode = -1;
	var800624b8 = 0;
	var800624c4 = 0;
	var800624e4 = -1;
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
