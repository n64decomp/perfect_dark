#include <libultra_internal.h>
#include "game/data/data_000000.h"
#include "gvars/gvars.h"

void __osPiCreateAccessQueue(void)
{
	__osPiAccessQueueEnabled = 1;
	osCreateMesgQueue(&__osPiAccessQueue, &piAccessBuf, 1);
	osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

void __osPiGetAccess(void)
{
	OSMesg dummyMesg;

	if (!__osPiAccessQueueEnabled) {
		__osPiCreateAccessQueue();
	}

	osRecvMesg(&__osPiAccessQueue, &dummyMesg, OS_MESG_BLOCK);
}

void __osPiRelAccess(void)
{
	osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
