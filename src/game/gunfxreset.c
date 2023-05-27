#include <ultra64.h>
#include "constants.h"
#include "game/chr.h"
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

void boltbeamsReset(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_BoltBeams); i++) {
		g_BoltBeams[i].unk00 = -1;
	}
}

void lasersightsReset(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_LaserSights); i++) {
		g_LaserSights[i].id = -1;
	}
}
