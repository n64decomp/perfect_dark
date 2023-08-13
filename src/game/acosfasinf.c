#include <ultra64.h>
#include "constants.h"
#include "game/acosasin.h"
#include "bss.h"
#include "data.h"
#include "types.h"

f32 acosf(f32 value)
{
	s16 intval;

	if (value >= 1) {
		intval = 32767;
	} else if (value <= -1) {
		intval = -32767;
	} else {
		intval = value * 32767.0f;
	}

	return acosx(intval) * M_PI / 65535.0f;
}

f32 asinf(f32 value)
{
	s16 intval;

	if (value >= 1) {
		intval = 32767;
	} else if (value <= -1) {
		intval = -32767;
	} else {
		intval = value * 32767.0f;
	}

	return asinx(intval) * M_PI / 65535.0f;
}
