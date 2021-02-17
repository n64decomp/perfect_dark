#include "libultra_internal.h"
#include "data.h"

u32 __osSpGetStatus()
{
	return IO_READ(SP_STATUS_REG);
}
