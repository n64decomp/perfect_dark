#include <ultra64.h>
#include "game/data/data_000000.h"

void osViSwapBuffer(void *frameBufPtr)
{
	u32 saveMask = __osDisableInt();

	__osViNext->framep = frameBufPtr;
	__osViNext->state |= VI_STATE_10;

	__osRestoreInt(saveMask);
}
