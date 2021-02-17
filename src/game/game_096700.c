#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

f32 func0f096700(f32 value)
{
	return sqrtf(sinf(value) / cosf(value) + 1);
}
