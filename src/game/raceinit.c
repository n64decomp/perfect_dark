#include <ultra64.h>
#include "constants.h"
#include "game/race.h"
#include "game/chr.h"
#include "lib/model.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void races_init(void)
{
	model_set_vtx_allocator_func(&chr_allocate_vertices);
	race_init_anims();
}
