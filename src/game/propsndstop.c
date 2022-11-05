#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

#define NUM_CHANNELS 40

void propsndStop(void)
{
	s32 i;

	for (i = 0; i < NUM_CHANNELS; i++) {
		if (g_AudioChannels[i].flags & AUDIOCHANNELFLAG_ISMP3) {
			g_AudioChannels[i].flags &= ~AUDIOCHANNELFLAG_ISMP3;
			g_AudioChannels[i].flags &= ~AUDIOCHANNELFLAG_0002;
		} else if (g_AudioChannels[i].audiohandle && sndGetState(g_AudioChannels[i].audiohandle) != AL_STOPPED) {
			audioStop(g_AudioChannels[i].audiohandle);
			g_AudioChannels[i].flags &= ~AUDIOCHANNELFLAG_0002;
		}
	}
}
