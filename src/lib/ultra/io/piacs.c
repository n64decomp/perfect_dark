#include <libultra_internal.h>
#include "data.h"
#include "bss.h"

OSMesg piAccessBuf;
u32 var8009c7a4;
OSMesgQueue __osPiAccessQueue;

u32 __osPiAccessQueueEnabled = 0;

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
