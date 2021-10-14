#include <os_internal.h>
#include "piint.h"

s32 osPiReadIo(u32 devAddr, u32 *data)
{
	register s32 ret;
	__osPiGetAccess();
	ret = osPiRawReadIo(devAddr, data);
	__osPiRelAccess();
	return ret;
}
