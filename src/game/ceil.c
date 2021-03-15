#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

f32 ceilf(f32 value)
{
	f32 fvalue;

	if (value <= 0) {
		return (s32)value;
	}

	fvalue = (s32)value;

	if (value == fvalue) {
		return fvalue;
	}

	return fvalue + 1;
}

s32 ceil(f32 value)
{
	s32 ivalue;

	if (value <= 0) {
		return value;
	}

	ivalue = value;

	if (ivalue == value) {
		return value;
	}

	return ivalue + 1;
}
