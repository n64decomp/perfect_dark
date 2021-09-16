#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_0c000.h"
#include "lib/lib_2fa00.h"
#include "data.h"
#include "types.h"

void faultCreateThread(void)
{
	faultCreateThread2();
}

void faultAssert(char *message, char *file, s32 line)
{
	crashPrint("ASSERTION : %s, %d: (\"%s\")\n", file, line, message);
}
