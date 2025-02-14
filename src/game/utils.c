#include <ultra64.h>
#include "constants.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void *var800ac0d0;
u32 var800ac0d4;
u32 var800ac0d8;
u32 var800ac0dc;
u32 var800ac0e0;
u32 var800ac0e4;
u8 *var800ac0e8[4];
u32 var800ac0f8[4];

f32 g_UtilsMaxSaneFloat = 999999;
f32 g_UtilsMinSaneFloat = 0.00001f;
s32 g_UtilsSavedInt = 1;
struct coord var800845dc = {0, 0, 0};
u32 var800845e8 = 0x00000000;
u32 var800845ec = 0x3f800000;
u32 var800845f0 = 0x00000000;
struct coord var800845f4 = {0, 0, 1};
u32 var80084600 = 0x3f800000;
u32 var80084604 = 0x00000000;
u32 var80084608 = 0x00000000;
u32 var8008460c = 0xffffffff;
u8 *var80084610 = NULL;
u8 *var80084614 = NULL;
u8 *var80084618 = NULL;
u32 var8008461c = 0x00000004;
u32 var80084620 = 0x00000000;

void utils_set_int(s32 value)
{
	g_UtilsSavedInt = value;
}

s32 utils_get_int(void)
{
	return g_UtilsSavedInt;
}

u32 align4(u32 arg0)
{
	if (arg0 & 3) {
		arg0 = (arg0 & ~3) + 4;
	}

	return arg0;
}

u32 align16(u32 arg0)
{
	if (arg0 & 0xf) {
		arg0 = (arg0 & ~15) + 16;
	}

	return arg0;
}

u32 align32(u32 arg0)
{
	if (arg0 & 0x1f) {
		arg0 = (arg0 & ~31) + 32;
	}

	return arg0;
}

void utils_init(void)
{
	s32 i;
	u32 stack;
	u32 slotssize = 0x1900;
	u32 allocsize;

	osSyncPrintf("UM_Make : In\n");

	var800ac0d0 = memp_alloc(10000, MEMPOOL_8);

	allocsize = align16(0x3900);
	var800ac0e8[0] = memp_alloc(allocsize, MEMPOOL_8);

	if (var800ac0e8[0] != NULL) {
		for (i = 0; i < ARRAYCOUNT(var800ac0e8); i++) {
			var800ac0e8[i] = var800ac0e8[0] + ((i * 100) << 4);
		}
	} else {
		for (i = 0; i < ARRAYCOUNT(var800ac0e8); i++) {
			var800ac0e8[i] = NULL;
		}
	}

	var80084610 = var800ac0e8[0] + slotssize;
	var80084618 = var800ac0e8[0] + allocsize - 1;
	var80084614 = var80084610;

	osSyncPrintf("UM_Make : Out\n");
}

const char var7f1b7cd0[] = "Utils -> ERROR at Line %d of %s\n";

s32 utils_get_ceiled_quotient(s32 dividend, s32 divisor)
{
	if (dividend % divisor == 0) {
		return dividend;
	}

	return (dividend / divisor + 1) * divisor;
}

void vec3f_sum2(struct coord *a, struct coord *b, struct coord *dst)
{
	dst->x = a->x + b->x;
	dst->y = a->y + b->y;
	dst->z = a->z + b->z;
}

void vec3f_sum3(struct coord *a, struct coord *b, struct coord *c, struct coord *dst)
{
	dst->x = a->x + b->x + c->x;
	dst->y = a->y + b->y + c->y;
	dst->z = a->z + b->z + c->z;
}

void vec3f_sum4(struct coord *a, struct coord *b, struct coord *c, struct coord *d, struct coord *dst)
{
	dst->x = a->x + b->x + c->x + d->x;
	dst->y = a->y + b->y + c->y + d->y;
	dst->z = a->z + b->z + c->z + d->z;
}

void vec3f_subtract(struct coord *a, struct coord *b, struct coord *dst)
{
	dst->x = b->x - a->x;
	dst->y = b->y - a->y;
	dst->z = b->z - a->z;
}

void vec3f_multiply_scalar(struct coord *a, f32 mult, struct coord *dst)
{
	dst->x = a->x * mult;
	dst->y = a->y * mult;
	dst->z = a->z * mult;
}

f32 vec3f_sqdist(struct coord *a, struct coord *b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

void func0f1770ac(struct coord *a, struct coord *b, struct coord *out)
{
	out->x = a->y * b->z - a->z * b->y;
	out->y = -(a->x * b->z - a->z * b->x);
	out->z = a->x * b->y - a->y * b->x;
}

void vec3f_copy(struct coord *src, struct coord *dst)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

void vec3f_invert(struct coord *src, struct coord *dst)
{
	dst->x = -src->x;
	dst->y = -src->y;
	dst->z = -src->z;
}

bool vec3f_normalise(struct coord *src, struct coord *dst, u32 line, char *file)
{
	f32 hypotenuse;
	f32 mult;

	osSyncPrintf("Utils -> UM_fVec3_NormaliseTo - Vec = %s%s (%f,%f,%f)\n", "", "", src->x, src->y, src->z);

	hypotenuse = src->x * src->x + src->y * src->y + src->z * src->z;

	if (hypotenuse < g_UtilsMinSaneFloat) {
		osSyncPrintf("Utils -> Attempt to normalise zeo length vector\n");

		src->x = var800845f4.x;
		src->y = var800845f4.y;
		src->z = var800845f4.z;

		return false;
	}

	mult = 1.0f / sqrtf(hypotenuse);

	dst->x = src->x * mult;
	dst->y = src->y * mult;
	dst->z = src->z * mult;

	return true;
}

bool func0f177230(struct coord *a, struct coord *b, struct coord *c)
{
	struct coord diff;
	diff.x = a->x - b->x;
	diff.y = a->y - b->y;
	diff.z = a->z - b->z;

	return diff.x * c->x + diff.y * c->y + diff.z * c->z > 0;
}

bool func0f177298(struct coord *a, struct coord *b, struct coord *c)
{
	struct coord diff;
	diff.x = a->x - b->x;
	diff.y = a->y - b->y;
	diff.z = a->z - b->z;

	return diff.x * c->x + diff.y * c->y + diff.z * c->z < 0;
}

bool vec3f_is_practically_equal(struct coord *a, struct coord *b)
{
	f32 diff = a->x - b->x;

	if (ABS(diff) < g_UtilsMinSaneFloat) {
		diff = a->y - b->y;

		if (ABS(diff) < g_UtilsMinSaneFloat) {
			diff = a->z - b->z;

			if (ABS(diff) < g_UtilsMinSaneFloat) {
				return true;
			}
		}
	}

	return false;
}

bool vec3f_is_pos_within_radius(struct coord *pos, struct coord *radius)
{
	if (pos->x < radius->x && pos->x > -radius->x
			&& pos->y < radius->y && pos->y > -radius->y
			&& pos->z < radius->z && pos->z > -radius->z) {
		return true;
	}

	return false;
}

f32 vec3f_get_distance(struct coord *a, struct coord *b)
{
	f32 xdiff = b->x - a->x;
	f32 ydiff = b->y - a->y;
	f32 zdiff = b->z - a->z;

	return sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
}

bool vec3f_make_normal_to(struct coord *arg0, struct coord *arg1, struct coord *out)
{
	struct coord a;
	struct coord b;
	struct coord c;
	f32 mult;

	if (!vec3f_normalise(arg1, &a, 702, "utils.c")) {
		osSyncPrintf("UTILS -> DEBUG ERROR - UM_fVec3_MakeNormalTo - Cant normalise\n");
		return false;
	}

	if (!vec3f_normalise(arg0, &b, 710, "utils.c")) {
		osSyncPrintf("UTILS -> DEBUG ERROR - UM_fVec3_MakeNormalTo - Cant normalise\n");
		return false;
	}

	mult = -(a.x * b.x + a.y * b.y + a.z * b.z);

	c.x = mult * a.x;
	c.y = mult * a.y;
	c.z = mult * a.z;

	out->x = b.x + c.x;
	out->y = b.y + c.y;
	out->z = b.z + c.z;

	return true;
}

void func0f17758c(f32 *arg0, f32 *arg1, struct coord *arg2, f32 *arg3)
{
	f32 a = arg0[0] - arg1[0];
	f32 b = arg0[1] - arg1[1];
	f32 c = arg0[2] - arg1[2];
	f32 sum = a * arg2->x + b * arg2->y + c * arg2->z;

	a = -sum * arg2->x;
	b = -sum * arg2->y;
	c = -sum * arg2->z;

	arg3[0] = a + arg0[0];
	arg3[1] = b + arg0[1];
	arg3[2] = c + arg0[2];
}

void func0f177624(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3)
{
	f32 dist;
	f32 tmpx;
	f32 tmpz;

	vec3f_normalise(arg0, arg1, 771, "utils.c");

	dist = sqrtf(arg1->x * arg1->x + arg1->z * arg1->z);

	tmpx = (arg1->x / dist);
	tmpz = arg1->z / dist;

	arg2->x = tmpz;
	arg2->y = 0.0f;
	arg2->z = -tmpx;

	arg3->x = arg1->y * tmpz;
	arg3->y = -dist;
	arg3->z = arg1->y * arg2->z;
}

const char var7f1b7e00[] = "WARNING - UTILS -> DEBUG - Triangle passed to Planar Poly Test\n";

f32 func0f1776cc(struct coord *a, struct coord *b, struct coord *c)
{
	f32 xdiff = c->x - a->x;
	f32 ydiff = c->y - a->y;
	f32 zdiff = c->z - a->z;

	f32 sqdist = xdiff * b->x + ydiff * b->y + zdiff * b->z;

	if (sqdist < g_UtilsMinSaneFloat && sqdist > -g_UtilsMinSaneFloat) {
		return g_UtilsMaxSaneFloat;
	}

	return (xdiff * xdiff + ydiff * ydiff + zdiff * zdiff) / sqdist;
}

bool func0f17776c(struct coord *a, struct coord *b, f32 mult, struct coord *out)
{
	struct coord tmp;
	tmp.x = b->x * mult;
	tmp.y = b->y * mult;
	tmp.z = b->z * mult;

	out->x = a->x + tmp.x;
	out->y = a->y + tmp.y;
	out->z = a->z + tmp.z;

	return true;
}

bool func0f1777b8(struct coord *a, struct coord *b, struct coord *c, struct coord *out)
{
	f32 mult = func0f1776cc(a, b, c);
	func0f17776c(a, b, mult, out);

	return true;
}

void utils_reset(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800ac0f8); i++) {
		var800ac0f8[i] = 0;
	}
}

bool func0f17781c(struct coord *arg0, s32 arg1)
{
	s32 i;
	struct coord sp78;
	struct coord sp6c;
	struct coord sp60;
	f32 f0;
	struct coord sp50;

	if (arg1 == 3) {
		return true;
	}

	sp78.x = arg0[1].x - arg0[0].x;
	sp78.y = arg0[1].y - arg0[0].y;
	sp78.z = arg0[1].z - arg0[0].z;

	sp6c.x = arg0[2].x - arg0[0].x;
	sp6c.y = arg0[2].y - arg0[0].y;
	sp6c.z = arg0[2].z - arg0[0].z;

	func0f1770ac(&sp78, &sp6c, &sp60);

	vec3f_normalise(&sp60, &sp60, 1101, "utils.c");

	for (i = 3; i < arg1; i++) {
		sp50.x = arg0[i].x - arg0[0].x;
		sp50.y = arg0[i].y - arg0[0].y;
		sp50.z = arg0[i].z - arg0[0].z;

		vec3f_normalise(&sp50, &sp50, 1109, "utils.c");

		f0 = sp50.x * sp60.x + sp50.y * sp60.y + sp50.z * sp60.z;

		if (ABS(f0) > 0.001f) {
			return false;
		}
	}

	return true;
}

void func0f1779f0(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
	u32 stack[2];

	if (stack[0]) {
		// empty
	}
}

void func0f177a10(u32 arg0)
{
	// empty
}

void func0f177a14(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
	u32 stack[2];

	if (stack[0]) {
		// empty
	}
}

void func0f177a30(u32 arg0)
{
	// empty
}

void func0f177a38(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
	u32 stack[2];

	if (stack[0]) {
		// empty
	}
}

s32 func0f177a54(u8 *src, s32 count, u8 *dst, s32 stepsize)
{
	s32 i = 0;
	s32 dstlen = 0;
	s32 accum = 0;

	for (; i < count; i++) {
		s32 index = i * stepsize;

		if (src[index] != 0) {
			u8 *srcptr = &src[index];

			if (i != 0 && srcptr[-stepsize] == 0) {
				dst[dstlen++] = 0;

				if (accum == 255) {
					dst[dstlen++] = 200;
					dst[dstlen++] = 0;
					accum -= 200;
				} else {
					while (accum > 255) {
						dst[dstlen++] = 255;
						accum -= 255;
					}
				}

				dst[dstlen++] = accum;
				accum = 0;
			}

			dst[dstlen++] = src[index];
		} else {
			accum++;
		}
	}

	dst[dstlen++] = 0;
	dst[dstlen++] = 0;

	return dstlen;
}

u8 func0f177b44(u8 *arg0, s32 *arg1)
{
	static s32 var800ac108;

	if (*arg1 == -1) {
		var800ac108 = 0;
	}

	if (arg0[var800ac108] == 0) {
		var800ac108++;

		if (arg0[var800ac108] != 0) {
			*arg1 += arg0[var800ac108];
			var800ac108++;
		}
	}

	*arg1 += 1;

	return arg0[var800ac108++];
}

const char var7f1b7e50[] = "UM_ZeroRunVerify_U8 - FAILED on item %d\n";

s32 func0f177bb4(u8 *arg0, s32 *arg1, s32 *arg2)
{
	s32 result = 0;
	s32 value;
	s32 tmp = 255;

	static s32 var80084624 = 0;

	if (arg0 == NULL) {
		return -1;
	}

	if (*arg1 == 0) {
		*arg2 = -1;
	}

	var80084624--;

	if (var80084624 <= 0) {
		if (arg0[*arg1] != 0) {
			result = arg0[*arg1];
		} else {
			*arg1 += 1;

			if (arg0[*arg1] != 0) {
				var80084624 = 0;
				value = arg0[*arg1];

				while (tmp == value) {
					var80084624 += tmp;
					*arg1 += 1;
					value = arg0[*arg1];
				}

				var80084624 += value;
			} else {
				return -1;
			}
		}

		*arg1 += 1;
	}

	*arg2 += 1;

	return result;
}

s32 func0f177c8c(u8 *arg0, s32 *arg1, s32 *arg2)
{
	s32 result;

	if (*arg1 == 0) {
		*arg2 = -1;
	}

	while (arg0[*arg1] == 0) {
		*arg1 += 1;

		if (arg0[*arg1]) {
			while (arg0[*arg1] == 255) {
				*arg2 += 255;
				*arg1 += 1;
			}

			*arg2 += arg0[*arg1];
			*arg1 += 1;
		} else {
			return -1;
		}
	}

	*arg2 += 1;

	result = arg0[*arg1];

	*arg1 += 1;

	return result;
}

bool func0f177d5c(u8 *arg0, u8 *arg1)
{
	s32 sp34 = 0; \
	s32 sp30 = 0; \
	s32 value = func0f177bb4(arg1, &sp34, &sp30);

	while (value >= 0) {
		if (value != arg0[sp30]) {
			return false;
		}

		value = func0f177bb4(arg1, &sp34, &sp30);
	}

	return true;
}
