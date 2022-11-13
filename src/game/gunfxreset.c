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

	for (i = 0; i < 8; i++) {
		g_BoltBeams[i].unk00 = -1;
	}

	g_BeamsActive = 0;
}

void lasersightsReset(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		g_LaserSights[i].id = -1;
	}

	g_LasersightsActive = 0;
}
