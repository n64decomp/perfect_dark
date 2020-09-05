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

void func0f0151f0(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Objectives); i++) {
		if (g_Objectives[i] && (g_Objectives[i]->unk0e & 1) && g_ObjectiveStatuses[i] != 2) {
			g_ObjectiveStatuses[i] = 1;
		}
	}
}
