#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/crash.h"
#include "lib/rmon.h"
#include "data.h"
#include "types.h"

void faultCreateThread(void)
{
	crashCreateThread();
}

void faultAssert(char *message, char *file, s32 line)
{
	rmonPrint("ASSERTION : %s, %d: (\"%s\")\n", file, line, message);
}
