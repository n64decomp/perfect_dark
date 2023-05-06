#include <os_internal.h>

OSMesg piAccessBuf;
OSMesgQueue __osPiAccessQueue;

u32 __osPiAccessQueueEnabled = 0;

void __osPiCreateAccessQueue(void)
{
	__osPiAccessQueueEnabled = 1;
	osCreateMesgQueue(&__osPiAccessQueue, &piAccessBuf, 1);
	osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
