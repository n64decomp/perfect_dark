#include <libultra_internal.h>

s32 __osSiRawWriteIo(u32 devAddr, u32 data)
{
    if (__osSiDeviceBusy()) {
        return -1;
	}

    IO_WRITE(devAddr, data);

    return 0;
}
