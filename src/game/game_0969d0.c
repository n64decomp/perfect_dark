#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_096890.h"
#include "gvars/gvars.h"
#include "types.h"

f32 func0f0969d0(f32 value)
{
	s16 intval;

	if (value >= 1) {
		intval = 32767;
	} else if (value <= -1) {
		intval = -32767;
	} else {
		intval = value * 32767.0f;
	}

	return (func0f096910(intval) * M_PI) / 65535.0f;
}

f32 func0f096a7c(f32 value)
{
	s16 intval;

	if (value >= 1) {
		intval = 32767;
	} else if (value <= -1) {
		intval = -32767;
	} else {
		intval = (value * 32767.0f);
	}

	return (func0f096964(intval) * M_PI) / 65535.0f;
}
