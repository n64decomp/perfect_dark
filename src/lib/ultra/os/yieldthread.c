#include <libultra_internal.h>
#include "game/data/data_000000.h"

void osYieldThread(void)
{
	register u32 saveMask = __osDisableInt();
	__osRunningThread->state = OS_STATE_RUNNABLE;
	__osEnqueueAndYield(&__osRunQueue);
	__osRestoreInt(saveMask);
}
