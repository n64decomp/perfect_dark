#include <libultra_internal.h>
#include "game/data/data_000000.h"

OSMesgQueue *osPiGetCmdQueue(void)
{
	if (!__osPiDevMgr.active) {
		return NULL;
	}

	return __osPiDevMgr.cmdQueue;
}
