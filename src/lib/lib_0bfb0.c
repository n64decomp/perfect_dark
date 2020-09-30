#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_0c000.h"
#include "lib/lib_2fa00.h"
#include "types.h"

void faultCreateThread(void)
{
	faultCreateThread2();
}

void func0000bfd0(char *arg0, char *arg1, s32 arg2)
{
	func0002faa4("ASSERTION : %s, %d: (\"%s\")\n", arg1, arg2, arg0);
}
