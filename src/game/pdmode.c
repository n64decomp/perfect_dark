#include <ultra64.h>
#include "constants.h"
#include "game/pdmode.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/options.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void titleSetNextStage(s32 stagenum)
{
	g_TitleNextStage = stagenum;
}
