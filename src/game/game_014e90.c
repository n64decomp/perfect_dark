#include <ultra64.h>
#include "constants.h"
#include "game/game_0147d0.h"
#include "game/chr/chr.h"
#include "game/game_02cde0.h"
#include "game/prop.h"
#include "game/game_197600.h"
#include "game/mplayer/mplayer.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

void aibotAllocateInventory(struct chrdata *chr, s32 maxitems)
{
	if (chr && chr->aibot && maxitems > 0) {
		if (maxitems > 255) {
			maxitems = 255;
		}

		chr->aibot->maxitems = maxitems;
		chr->aibot->items = malloc(ALIGN16(maxitems * sizeof(struct invitem)), MEMPOOL_STAGE);

		aibotClearInventory(chr);
	}
}
