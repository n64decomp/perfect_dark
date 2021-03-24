#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

void func0f0150a0(void)
{
	s32 i;

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		if (g_AudioChannels[i].flags & AUDIOCHANNELFLAG_0010) {
			snd0000fbc4(g_AudioChannels[i].soundnum26);
			g_AudioChannels[i].flags &= ~AUDIOCHANNELFLAG_0010;
			g_AudioChannels[i].flags &= ~AUDIOCHANNELFLAG_0002;
		} else if (g_AudioChannels[i].audiohandle && audioIsPlaying(g_AudioChannels[i].audiohandle)) {
			audioStop(g_AudioChannels[i].audiohandle);
			g_AudioChannels[i].flags &= ~AUDIOCHANNELFLAG_0002;
		}
	}
}
