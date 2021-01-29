#include <ultra64.h>

u32 osDpGetStatus()
{
	return IO_READ(DPC_STATUS_REG);
}
