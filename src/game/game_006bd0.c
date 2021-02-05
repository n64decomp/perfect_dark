#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/dlights.h"
#include "game/game_005fd0.h"
#include "game/nbomb.h"
#include "game/chr/chr.h"
#include "game/chr/chraction.h"
#include "game/prop.h"
#include "game/game_095320.h"
#include "game/atan2f.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/room.h"
#include "game/file.h"
#include "game/gfxmemory.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0e9d0.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_317f0.h"
#include "types.h"

f32 func0f006bd0(f32 arg0)
{
	s32 ival = arg0 * 4.0f;
	f32 fval = arg0 * 4.0f - (f32)(ival / 4) * 4.0f;

	if (fval < 1.0f) {
		return fval;
	}

	if (fval < 2.0f) {
		return 1.0f;
	}

	if (fval < 3.0f) {
		return 1.0f - (fval - 2.0f);
	}

	return 0.0f;
}
