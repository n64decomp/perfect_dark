#include <ultra64.h>
#include "constants.h"
#include "game/lasersights.h"
#include "game/chr.h"
#include "game/game_02cde0.h"
#include "game/prop.h"
#include "game/botcmd.h"
#include "game/mplayer/mplayer.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/ailist.h"
#include "data.h"
#include "types.h"

void func0f0147d0(void)
{
	s32 i;

	for (i = 0; i < 8; i++) {
		var8009da60[i].unk00 = -1;
	}
}

void lasersightsReset(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		g_LaserSights[i].id = -1;
	}
}
