#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
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
