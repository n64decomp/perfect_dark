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
	memp_reset_pool(MEMPOOL_5);
	files_stop(5);
}

void func0f175fc8(void)
{
	memp_disable_pool(MEMPOOL_5);
	files_stop(5);
}
