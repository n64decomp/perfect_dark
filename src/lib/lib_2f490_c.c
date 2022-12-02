#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "lib/mtx.h"
#include "types.h"

static bool implementation(
		f32 f0, f32 f1, f32 f2,
		f32 f12, f32 f13, f32 f14,
		f32 f15, f32 f16, f32 f17,
		struct coord *arg3, struct coord *t0, struct coord *t1,
		struct coord *t2, struct coord *t3, struct coord *t4)
{
	f32 f3;
	f32 f4;
	f32 f5;
	f32 f6;
	f32 f7;
	f32 f8;
	f32 f9;
	f32 f10;
	f32 f11;
	f32 f18;
	f32 f19;
	f32 f20;
	f32 f21;
	f32 f22;
	f32 f23;
	f32 f24;
	f32 f25;
	f32 f26;
	f32 f27;
	f32 f28;

	f3 = f12 - f0;
	f4 = f13 - f1;
	f5 = f14 - f2;
	f6 = f15 - f12;
	f7 = f16 - f13;
	f8 = f17 - f14;
	f9 = f15 - f0;
	f10 = f16 - f1;
	f11 = f17 - f2;

	if (arg3 != NULL) {
		f0 += arg3->x;
		f1 += arg3->y;
		f2 += arg3->z;
	}

	f12 = f4 * f8;
	f13 = f7 * f5;
	f14 = f5 * f6;
	f12 = f12 - f13;
	f15 = f8 * f3;
	f16 = f3 * f7;
	f13 = f14 - f15;
	f14 = f6 * f4;
	f14 = f16 - f14;
	f15 = f12 * f0;
	f16 = f13 * f1;
	f17 = f14 * f2;
	f15 = f15 + f16;
	f15 = f15 + f17;

	f16 = t2->x;
	f17 = t2->y;
	f18 = t2->z;

	f19 = f12 * f16;
	f20 = f13 * f17;
	f19 = f19 + f20;
	f20 = f14 * f18;
	f19 = f19 + f20;

	if (f19 == 0.0f) {
		return false;
	}

	f20 = t1->x;
	f21 = t1->y;
	f22 = t1->z;
	f23 = f12 * f20;
	f24 = f13 * f21;
	f23 = f15 - f23;
	f25 = f14 * f22;
	f23 = f23 - f24;
	f23 = f23 - f25;
	f19 = f23 / f19;
	f23 = f19 * f16;
	f24 = f19 * f17;
	f23 = f20 + f23;
	f25 = f19 * f18;
	f24 = f21 + f24;
	f25 = f22 + f25;
	f26 = f23 - f20;
	f26 = f16 * f26;
	f27 = f24 - f21;
	f27 = f17 * f27;
	f28 = f25 - f22;
	f26 = f26 + f27;
	f27 = f18 * f28;
	f26 = f26 + f27;

	if (f26 > 0) {
		return false;
	}

	f20 = t0->x;
	f21 = t0->y;
	f22 = t0->z;
	f26 = f23 - f20;
	f26 = f16 * f26;
	f27 = f24 - f21;
	f27 = f17 * f27;
	f28 = f25 - f22;
	f26 = f26 + f27;
	f27 = f18 * f28;
	f26 = f26 + f27;

	if (f26 < 0) {
		return false;
	}

	f0 = f23 - f0;
	f1 = f24 - f1;
	f2 = f25 - f2;
	f26 = f6 * f4;
	f27 = f3 * f7;
	f26 = f26 - f27;

	if (f26 != 0.0f) {
		f27 = f0 * f4;
		f28 = f1 * f3;
	} else {
		f26 = f7 * f5;
		f27 = f4 * f8;
		f26 = f26 - f27;

		if (f26 != 0.0f) {
			f27 = f1 * f5;
			f28 = f2 * f4;
		} else {
			f26 = f8 * f3;
			f27 = f5 * f6;
			f26 = f26 - f27;
			f27 = f2 * f3;
			f28 = f0 * f5;
		}
	}

	f27 = f27 - f28;
	f27 = f27 / f26;

	if (f27 < 0.0f) {
		return false;
	}

	if (f3 != 0.0f) {
		f28 = f27 * f9;
		f28 = f0 - f28;
		f28 = f28 / f3;
	} else if (f4 != 0.0f) {
		f28 = f27 * f10;
		f28 = f1 - f28;
		f28 = f28 / f4;
	} else {
		f28 = f27 * f11;
		f28 = f2 - f28;
		f28 = f28 / f5;
	}

	if (f28 >= 0.0f && f28 + f27 <= 1.0f) {
		if (t3 != NULL) {
			t3->x = f23;
			t3->y = f24;
			t3->z = f25;
		}

		if (t4 != NULL) {
			t4->x = f12;
			t4->y = f13;
			t4->z = f14;
		}

		return true;
	}

	return false;
}

bool func0002f490(struct vec3s16 *arg0, struct vec3s16 *arg1, struct vec3s16 *arg2,
		struct coord *arg3, struct coord *t0, struct coord *t1,
		struct coord *t2, struct coord *t3, struct coord *t4)
{
	// Casting arg0/arg1/arg2 properties from s16 to float
	return implementation(
			arg0->x, arg0->y, arg0->z,
			arg1->x, arg1->y, arg1->z,
			arg2->x, arg2->y, arg2->z,
			arg3, t0, t1, t2, t3, t4);
}

bool func0002f560(struct coord *arg0, struct coord *arg1, struct coord *arg2,
		struct coord *arg3, struct coord *t0, struct coord *t1,
		struct coord *t2, struct coord *t3, struct coord *t4)
{
	// No casting (arg0/arg1/arg2 properties are already floats)
	return implementation(
			arg0->x, arg0->y, arg0->z,
			arg1->x, arg1->y, arg1->z,
			arg2->x, arg2->y, arg2->z,
			arg3, t0, t1, t2, t3, t4);
}
