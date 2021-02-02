#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/prop.h"
#include "gvars/gvars.h"
#include "types.h"

void smokeReset(void)
{
	s32 i;

	if (g_Smokes) {
		for (i = 0; i < g_MaxSmokes; i++) {
			if (g_Smokes[i].prop) {
				propRemoveFromCurrentList(g_Smokes[i].prop);
				propHide(g_Smokes[i].prop);
				propFree(g_Smokes[i].prop);

				g_Smokes[i].prop = NULL;
			}
		}
	}
}
