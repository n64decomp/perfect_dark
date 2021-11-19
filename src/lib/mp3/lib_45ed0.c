#include <ultra64.h>
#include "internal.h"

f32 func00045ed0(f32 arg0, f32 arg1)
{
	s32 arg1int = arg1;
	f32 sp30;
	register bool s0;

	if (arg0 != 0 && arg1 == 0) {
		return 1;
	}

	if (arg0 == 0) {
		return 0;
	}

	if ((arg0 == 0 && arg1 == 0) || (arg0 < 0 && arg1int != arg1)) {
		return 0;
	}

	if (arg1int != arg1) {
		arg0 = func00047d20(func00047ef0(arg0) * arg1);
	} else if (arg1 > 0) {
		arg1--;
		sp30 = arg0;

		for (s0 = (arg1-- != 0); s0; s0 = (arg1-- != 0)) {
			arg0 *= sp30;
		}
	} else {
		sp30 = 1;

		for (s0 = (arg1++ != 0); s0; s0 = (arg1++ != 0)) {
			sp30 /= arg0;
		}

		arg0 = sp30;
	}

	return arg0;
}
