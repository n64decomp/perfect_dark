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
#include "lib/memory.h"
#include "types.h"

void func0f0108d0(void)
{
	s32 i;

	g_AudioChannels = malloc(ALIGN16((IS4MB() ? 30 : 40) * sizeof(struct audiochannel)), MEMPOOL_STAGE);

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		g_AudioChannels[i].flags = AUDIOCHANNELFLAG_IDLE;
		g_AudioChannels[i].audiohandle = NULL;
		g_AudioChannels[i].unk4c = -1;
	}
}
