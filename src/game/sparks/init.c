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

void sparksInit(void)
{
	s32 i;
	g_NextSparkIndex = 0;

	for (i = 0; i < 10; i++) {
		g_SparkGroups[i].age = 0;
	}

	var800a4130 = 0;
	g_SparksAreActive = false;
}
