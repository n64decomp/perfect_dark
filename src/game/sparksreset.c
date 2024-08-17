#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void sparks_reset(void)
{
	s32 i;
	g_NextSparkIndex = 0;

	for (i = 0; i < ARRAYCOUNT(g_SparkGroups); i++) {
		g_SparkGroups[i].age = 0;
	}

	g_NextSparkGroupIndex = 0;
	g_SparksAreActive = false;
}
