#include <os_internal.h>
#include "osint.h"

__OSEventState __osEventStateTab[OS_NUM_EVENTS];

u32 var80060890 = 0;

extern u32 _osShutdown;

void osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg)
{
	register u32 saveMask = __osDisableInt();
	__OSEventState *es;

	es = &__osEventStateTab[event];
	es->messageQueue = mq;
	es->message = msg;

	if (event == OS_EVENT_PRENMI) {
		if (_osShutdown != 0 && var80060890 == 0) {
			osSendMesg(mq, msg, OS_MESG_NOBLOCK);
		}

		var80060890 = 1;
	}

	__osRestoreInt(saveMask);
}
