#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_4a360.h"
#include "types.h"

void scaleTo1(f32 *x, f32 *y, f32 *z)
{
	f32 hyp = sqrtf(*x * *x + *y * *y + *z * *z);

	if (hyp > 0.0f) {
		f32 hyp2 = 1.0f / hyp;
		*x = *x * hyp2;
		*y = *y * hyp2;
		*z = *z * hyp2;
	} else {
		*x = 0.0f;
		*y = 0.0f;
		*z = 1.0f;
	}
}
