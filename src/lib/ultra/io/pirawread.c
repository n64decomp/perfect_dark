#include <os_internal.h>
#include "controller.h"
#include "piint.h"
#include "types.h"

s32 osPiRawReadIo(u32 devAddr, u32 *data)
{
	register u32 stat;

	WAIT_ON_IOBUSY(stat);

	*data = IO_READ((uintptr_t) osRomBase | devAddr);

	return 0;
}
