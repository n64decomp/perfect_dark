#include <ultra64.h>
#include "bss.h"
#include "constants.h"
#include "data.h"
#include "game/botinv.h"
#include "lib/memp.h"
#include "types.h"

void botinvInit(struct chrdata *chr, s32 maxitems)
{
	if (chr && chr->aibot && maxitems > 0) {
		if (maxitems > 255) {
			maxitems = 255;
		}

		chr->aibot->maxitems = maxitems;
		chr->aibot->items = mempAlloc(ALIGN16(maxitems * sizeof(struct invitem)), MEMPOOL_STAGE);

		botinvClear(chr);
	}
}
