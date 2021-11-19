#include <ultra64.h>
#include "internal.h"

f32 func00047ef0(f32 arg0)
{
	s32 sp14;
	f32 sp10;
	f32 sp0c;
	f32 sp08;
	f32 sp04;

	if (arg0 < 0) {
		return 0;
	}

	if (arg0 == 0) {
		return 0;
	}

	sp08 = 0;

	while (arg0 >= 2) {
		arg0 /= 2;
		sp08 += 0.6931471824646f;
	}

	while (arg0 < 1) {
		arg0 *= 2;
		sp08 -= 0.6931471824646f;
	}

	sp14 = 1;
	sp10 = (arg0 - 1) / (arg0 + 1);
	sp0c = 2 * sp10;
	sp10 *= sp10;

	do {
		sp04 = sp08;
		sp08 += sp0c / sp14;
		sp0c *= sp10;
		sp14 += 2;
	} while (sp08 != sp04);

	return sp08;
}
