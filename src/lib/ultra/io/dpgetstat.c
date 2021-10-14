#include <os_internal.h>
#include <rcp.h>

u32 osDpGetStatus()
{
	return IO_READ(DPC_STATUS_REG);
}
