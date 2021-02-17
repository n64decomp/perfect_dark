#include <ultra64.h>
#include "data.h"

void osViSwapBuffer(void *frameBufPtr)
{
	u32 saveMask = __osDisableInt();

	__osViNext->framep = frameBufPtr;
	__osViNext->state |= VI_STATE_10;

	__osRestoreInt(saveMask);
}
