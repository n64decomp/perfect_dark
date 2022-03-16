#include <ultra64.h>
#include "constants.h"
#include "game/game_000090.h"
#include "game/game_000130.h"
#include "game/chr/chr.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void func0f000100(void)
{
	modelSetVtxAllocatorFunc(&chrAllocateVertices);
	func0f000648();
}
