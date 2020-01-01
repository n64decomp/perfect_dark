#include <ultra64.h>
#include "constants.h"
#include "game/chr/chr.h"
#include "game/game_000130.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "types.h"

void func0f000090(void)
{
	var800624b4 = -1;
	var800624b8 = 0;
	var800624c4 = 0;
	var800624e4 = -1;
	var800624e0 = 0;
	var800624e8 = 1;
	var800624ec = 0;
	var800624f0 = 0;
	var800624f4 = 1;
	g_MissionConfig.unk04 = 0;
	g_MissionConfig.updmodehealth = 128;
	g_MissionConfig.updmodedamage = 128;
	g_MissionConfig.updmodeaccuracy = 128;
}

void func0f000100(void)
{
	func0001a518(&func0f01e760);
	func0f000648();
}
