#include <ultra64.h>
#include "game/acosfasinf.h"
#include "data.h"
#include "types.h"

f32 atan2f(f32 x, f32 z)
{
	f32 result;

	if (x == 0) {
		if (z >= 0) {
			result = 0;
		} else {
			result = DTOR(180);
		}
	} else if (z == 0) {
		if (x > 0) {
			result = DTOR(90);
		} else {
			result = DTOR(270);
		}
	} else {
		result = sqrtf(x * x + z * z);

		if (z < x) {
			result = acosf(z / result);

			if (x < 0) {
				result = DTOR(360) - result;
			}
		} else {
			result = acosf(x / result);
			result = DTOR(90) - result;

			if (z < 0) {
				result = DTOR(180) - result;
			}

			if (result < 0) {
				result += DTOR(360);
			}
		}
	}

	return result;
}
