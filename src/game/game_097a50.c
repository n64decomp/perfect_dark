#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "data.h"
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
