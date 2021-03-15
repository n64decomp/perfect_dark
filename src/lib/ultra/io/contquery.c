#include <libultra_internal.h>
#include "data.h"
#include "bss.h"

s32 osContStartQuery(OSMesgQueue *mq)
{
	s32 ret;
	ret = 0;

	__osSiGetAccess();

	if (__osContLastCmd != CONT_CMD_REQUEST_STATUS) {
		__osPackRequestData(CONT_CMD_REQUEST_STATUS);
		ret = __osSiRawStartDma(OS_WRITE, &__osContPifRam);
		osRecvMesg(mq, NULL, OS_MESG_BLOCK);
	}

	ret = __osSiRawStartDma(OS_READ, &__osContPifRam);
	__osContLastCmd = CONT_CMD_REQUEST_STATUS;
	__osSiRelAccess();

	return ret;
}

void osContGetQuery(OSContStatus *data)
{
	u8 pattern;
	__osContGetInitData(&pattern, data);
}
