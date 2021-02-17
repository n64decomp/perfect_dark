#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "data.h"
#include "types.h"

f32 floorf(f32 value)
{
	f32 fvalue;

	if (value >= 0) {
		return (s32)value;
	}

	fvalue = (s32)value;

	if (value == fvalue) {
		return fvalue;
	}

	return fvalue - 1;
}

s32 floor(f32 value)
{
	s32 ivalue;

	if (value >= 0) {
		return value;
	}

	ivalue = value;

	if (value == ivalue) {
		return ivalue;
	}

	return ivalue - 1;
}
