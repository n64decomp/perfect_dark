#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/crash.h"
#include "lib/rmon.h"
#include "data.h"
#include "types.h"

void fault_init(void)
{
	crash_create_thread();
}

void fault_assert(char *message, char *file, s32 line)
{
	rmon_printf("ASSERTION : %s, %d: (\"%s\")\n", file, line, message);
}
