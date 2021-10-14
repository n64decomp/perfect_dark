#include <os_internal.h>
#include <rcp.h>

u32 __osSpGetStatus()
{
	return IO_READ(SP_STATUS_REG);
}
