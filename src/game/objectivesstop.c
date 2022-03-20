#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void objectivesStop(void)
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
