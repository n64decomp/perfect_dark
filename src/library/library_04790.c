#include <ultra64.h>
#include "types.h"
#include "library/library_4a360.h"

void scaleTo1(float *x, float *y, float *z)
{
	float hyp = sqrtf(*x * *x + *y * *y + *z * *z);

	if (hyp > 0.0f) {
		float hyp2 = 1.0f / hyp;
		*x = *x * hyp2;
		*y = *y * hyp2;
		*z = *z * hyp2;
	} else {
		*x = 0.0f;
		*y = 0.0f;
		*z = 1.0f;
	}
}
