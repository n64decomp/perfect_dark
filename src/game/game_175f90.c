#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/file.h"
#include "game/game_175f90.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "types.h"

void func0f175f90(void)
{
	// empty
}

void func0f175f98(void)
{
	func0f167330();
	memResetPool(MEMPOOL_5);
	func0f1672f0(5);
}

void func0f175fc8(void)
{
	memDisablePool(MEMPOOL_5);
	func0f1672f0(5);
}

char *func0f175ff0(void)
{
	return "Apr  6 2000 15:05:01";
}
