#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

#define NUM_CHANNELS 40

void propsndReset(void)
{
	s32 i;

	g_AudioChannels = mempAlloc(ALIGN16(NUM_CHANNELS * sizeof(struct audiochannel)), MEMPOOL_STAGE);

	for (i = 0; i < NUM_CHANNELS; i++) {
		g_AudioChannels[i].flags = AUDIOCHANNELFLAG_IDLE;
		g_AudioChannels[i].audiohandle = NULL;
		g_AudioChannels[i].unk4c = -1;
	}
}
