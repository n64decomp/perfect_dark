#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_0601b0.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "types.h"

void explosionsClearAll(void)
{
	s32 i;

	var8007e4a0 = 0;
	func0000aa50(0);

	if (g_Explosions) {
		for (i = 0; i < 6; i++) {
			if (g_Explosions[i].prop) {
				func0f0605c4(g_Explosions[i].prop);
				propHide(g_Explosions[i].prop);
				propFree(g_Explosions[i].prop);

				g_Explosions[i].prop = NULL;
			}
		}
	}
}
