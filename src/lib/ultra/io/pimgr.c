#include <os_internal.h>
#include "piint.h"

OSPiHandle CartRomHandle;
OSPiHandle LeoDiskHandle;
OSThread piThread;
char piThreadStack[512];
OSMesgQueue piEventQueue;
OSMesg piEventBuf[4];

s32 osPiRawStartDma(s32 direction, u32 devAddr, void *dramAddr, u32 size);
s32 osEPiRawStartDma(OSPiHandle *handle, s32 direction, u32 devAddr, void *dramAddr, u32 size);

OSDevMgr __osPiDevMgr = {0};
OSPiHandle *__osCurrentHandle[2] = { &CartRomHandle, &LeoDiskHandle };

void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt)
{
	u32 savedMask;
	OSPri oldPri;
	OSPri myPri;

	if (!__osPiDevMgr.active) {
		osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
		osCreateMesgQueue(&piEventQueue, (OSMesg*) &piEventBuf, 4);

		if (!__osPiAccessQueueEnabled) {
			__osPiCreateAccessQueue();
		}

		osSetEventMesg(OS_EVENT_PI, &piEventQueue, (OSMesg) 0x22222222);

		oldPri = -1;
		myPri = osGetThreadPri(NULL);

		if (myPri < pri) {
			oldPri = myPri;
			osSetThreadPri(NULL, pri);
		}

		savedMask = __osDisableInt();

		__osPiDevMgr.active = 1;
		__osPiDevMgr.thread = &piThread;
		__osPiDevMgr.cmdQueue = cmdQ;
		__osPiDevMgr.evtQueue = &piEventQueue;
		__osPiDevMgr.acsQueue = &__osPiAccessQueue;
		__osPiDevMgr.dma = osPiRawStartDma;
		__osPiDevMgr.edma = osEPiRawStartDma;

		osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, &piThreadStack[512], pri);
		osStartThread(&piThread);

		__osRestoreInt(savedMask);

		if (oldPri != -1) {
			osSetThreadPri(NULL, oldPri);
		}
	}
}
