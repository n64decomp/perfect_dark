#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

void ps_stop(void)
{
	s32 i;

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		if (g_PsChannels[i].flags & PSFLAG_ISMP3) {
			snd_stop_mp3(g_PsChannels[i].requestedsoundnum);
			g_PsChannels[i].flags &= ~PSFLAG_ISMP3;
			g_PsChannels[i].flags &= ~PSFLAG_REPEATING;
		} else if (g_PsChannels[i].audiohandle && sndp_get_state(g_PsChannels[i].audiohandle) != AL_STOPPED) {
			sndp_stop_sound(g_PsChannels[i].audiohandle);
			g_PsChannels[i].flags &= ~PSFLAG_REPEATING;
		}
	}
}
