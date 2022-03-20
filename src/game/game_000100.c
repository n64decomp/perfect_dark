#include <ultra64.h>
#include "constants.h"
#include "game/game_000130.h"
#include "game/chr.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void racesInit(void)
{
	modelSetVtxAllocatorFunc(&chrAllocateVertices);
	func0f000648();
}
