// The pragma statement below must not fall on a 2^16 byte boundary after
// pre-processing because it can cause cfe to crash. So it's placed above the
// includes to ensure it isn't.
float fabsf(float value);

#pragma intrinsic (fabsf)

#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

f32 func00047d20(f32 arg0)
{
	f32 sp1c;
	f32 sp18;
	f32 sp14;
	f32 sp10;
	f32 sp0c;
	s32 sp08;
	s32 sp04;

	sp0c = fabsf(arg0);

	if (sp0c < 0.00000011920929f) {
		return 1;
	}

	sp04 = (s32) (sp0c / 0.6931471824646f);

	if (sp04 > 1024) {
		if (arg0 >= 0) {
			return MAXFLOAT;
		} else {
			return 0;
		}
	}

	sp10 = sp0c - sp04 * 0.6931471824646f;
	sp08 = 1;
	sp1c = 1;
	sp18 = 1;

	do {
		sp14 = sp1c;
		sp18 *= sp10 / sp08;
		sp1c += sp18;
		sp08++;
	} while (sp1c != sp14);

	while (sp04) {
		sp1c *= 2;
		sp04--;
	}

	if (arg0 >= 0) {
		return sp1c;
	} else {
		return 1 / sp1c;
	}
}
