#include <libultra_internal.h>
#include "data.h"

OSMesgQueue *osPiGetCmdQueue(void)
{
	if (!__osPiDevMgr.active) {
		return NULL;
	}

	return __osPiDevMgr.cmdQueue;
}
