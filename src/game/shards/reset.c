#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "data.h"
#include "types.h"

void shardsReset(void)
{
	s32 i;

	for (i = 0; i < g_MaxShards; i++) {
		g_Shards[i].age60 = 0;
	}
}
