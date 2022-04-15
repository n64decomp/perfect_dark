#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void sparksReset(void)
{
	s32 i;
	g_NextSparkIndex = 0;

	for (i = 0; i < 10; i++) {
		g_SparkGroups[i].age = 0;
	}

	g_NextSparkGroupIndex = 0;
	g_SparksAreActive = false;
}
