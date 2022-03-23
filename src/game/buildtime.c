#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

char *buildGetTimestamp(void)
{
#if VERSION >= VERSION_JPN_FINAL
	return "Jul 19 2000 09:43:24";
#elif VERSION >= VERSION_PAL_FINAL
	return "Apr 28 2000 14:40:49";
#elif VERSION >= VERSION_PAL_BETA
	return "Apr 26 2000 16:36:48";
#elif VERSION >= VERSION_NTSC_1_0
	return "Apr  6 2000 15:05:01";
#else
	return "Mar 22 2000 00:26:50";
#endif
}
