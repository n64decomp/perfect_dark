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
