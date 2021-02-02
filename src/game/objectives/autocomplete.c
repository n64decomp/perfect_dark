#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "types.h"

void objectivesAutocomplete(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Objectives); i++) {
		if (g_Objectives[i]
				&& (g_Objectives[i]->flags & OBJECTIVEFLAG_AUTOCOMPLETE)
				&& g_ObjectiveStatuses[i] != OBJECTIVE_FAILED) {
			g_ObjectiveStatuses[i] = OBJECTIVE_COMPLETE;
		}
	}
}
