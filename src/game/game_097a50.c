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
#include "types.h"

f32 func0f097a50(f32 value)
{
	f32 i = 0;
	f32 result = 0;
	f32 adder = 1;

	while (0 != adder) {
		i++;
		result += adder;
		adder *= value / i;
	}

	return result;
}
