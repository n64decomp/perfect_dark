#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/dma.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

void bgunStop(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		for (j = 0; j < 2; j++) {
			struct hand *hand = &g_Vars.players[i]->hands[j];

			if (hand->audiohandle2 && sndGetState(hand->audiohandle2) != AL_STOPPED) {
				audioStop(hand->audiohandle2);
			}
		}
	}
}
