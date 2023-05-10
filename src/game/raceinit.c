#include <ultra64.h>
#include "constants.h"
#include "game/race.h"
#include "game/chr.h"
#include "lib/model.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void racesInit(void)
{
	g_ModelVtxAllocatorFunc = &chrAllocateVertices;
	raceInitAnims();
}
