#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

f32 func0f096700(f32 value)
{
	return sqrtf(sinf(value) / cosf(value) + 1);
}
