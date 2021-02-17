#include "libultra_internal.h"
#include "data.h"

OSYieldResult osSpTaskYielded(OSTask *tp)
{
	u32 status;
	OSYieldResult result;

	status = __osSpGetStatus();

	if (status & SP_STATUS_YIELDED) {
		result = OS_TASK_YIELDED;
	} else {
		result = 0;
	}

	if (status & SP_STATUS_YIELD) {
		tp->t.flags |= result;
		tp->t.flags &= ~(OS_TASK_DP_WAIT);
	}

	return result;
}
