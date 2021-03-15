#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

void shardsInit(void)
{
	s32 i;

	g_MaxShards = 200 / PLAYERCOUNT();

	if (IS4MB()) {
		g_MaxShards = g_MaxShards / 2;
	}

	if (g_Vars.stagenum >= STAGE_TITLE) {
		g_MaxShards = 0;
	}

	if (g_MaxShards == 0) {
		g_Shards = NULL;
	} else {
		g_Shards = malloc(g_MaxShards * sizeof(struct shard) + 0xf & ~0xf, MEMPOOL_STAGE);

		for (i = 0; i < g_MaxShards; i++) {
			g_Shards[i].age60 = 0;
		}
	}

	g_NextShardNum = 0;
}
