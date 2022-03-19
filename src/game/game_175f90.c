#include <ultra64.h>
#include "constants.h"
#include "game/file.h"
#include "game/game_175f90.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void func0f175f90(void)
{
	// empty
}

void func0f175f98(void)
{
	func0f167330();
	mempResetPool(MEMPOOL_5);
	filesReset(5);
}

void func0f175fc8(void)
{
	mempDisablePool(MEMPOOL_5);
	filesReset(5);
}

char *func0f175ff0(void)
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
