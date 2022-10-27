#include <ultra64.h>
#include "constants.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

const char var7f1b7cb0[] = "UM_Make : In\n";
const char var7f1b7cc0[] = "UM_Make : Out\n";
const char var7f1b7cd0[] = "Utils -> ERROR at Line %d of %s\n";
const char var7f1b7cf4[] = "Utils -> UM_fVec3_NormaliseTo - Vec = %s%s (%f,%f,%f)\n";
const char var7f1b7d2c[] = "";
const char var7f1b7d30[] = "";
const char var7f1b7d34[] = "Utils -> Attempt to normalise zeo length vector\n";

void *var800ac0d0;
u32 var800ac0d4;
u32 var800ac0d8;
u32 var800ac0dc;
u32 var800ac0e0;
u32 var800ac0e4;
u8 *var800ac0e8[4];
u32 var800ac0f8[4];

f32 var800845d0 = 999999;
f32 var800845d4 = 0.00001f;
s32 var800845d8 = 1;
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

void func0f176d70(s32 arg0)
{
	var800845d8 = arg0;
}

s32 func0f176d7c(void)
{
	return var800845d8;
}

u32 align4(u32 arg0)
{
	if (arg0 & 3) {
		arg0 = (arg0 & 0xfffffffc) + 4;
	}

	return arg0;
}

u32 align16(u32 arg0)
{
	if (arg0 & 0xf) {
		arg0 = (arg0 & 0xfffffff0) + 0x10;
	}

	return arg0;
}

u32 align32(u32 arg0)
{
	if (arg0 & 0x1f) {
		arg0 = (arg0 & 0xffffffe0) + 0x20;
	}

	return arg0;
}

void utilsInit(void)
{
	s32 i;
	u32 stack;
	u32 slotssize = 0x1900;
	u32 allocsize;

	var800ac0d0 = mempAlloc(10000, MEMPOOL_8);

	allocsize = align16(0x3900);
	var800ac0e8[0] = mempAlloc(allocsize, MEMPOOL_8);

	if (var800ac0e8[0] != NULL) {
		for (i = 0; i < 4; i++) {
			var800ac0e8[i] = var800ac0e8[0] + ((i * 100) << 4);
		}
	} else {
		for (i = 0; i < 4; i++) {
			var800ac0e8[i] = NULL;
		}
	}

	var80084610 = var800ac0e8[0] + slotssize;
	var80084618 = var800ac0e8[0] + allocsize - 1;
	var80084614 = var80084610;
}

s32 func0f176eb0(s32 arg0, s32 arg1)
{
	if (arg0 % arg1 == 0) {
		return arg0;
	}

	return (arg0 / arg1 + 1) * arg1;
}

void func0f176f34(struct coord *a, struct coord *b, struct coord *out)
{
	out->x = a->x + b->x;
	out->y = a->y + b->y;
	out->z = a->z + b->z;
}

void func0f176f68(struct coord *a, struct coord *b, struct coord *c, struct coord *out)
{
	out->x = a->x + b->x + c->x;
	out->y = a->y + b->y + c->y;
	out->z = a->z + b->z + c->z;
}

void func0f176fb4(struct coord *a, struct coord *b, struct coord *c, struct coord *d, struct coord *out)
{
	out->x = a->x + b->x + c->x + d->x;
	out->y = a->y + b->y + c->y + d->y;
	out->z = a->z + b->z + c->z + d->z;
}

void func0f17701c(struct coord *a, struct coord *b, struct coord *out)
{
	out->x = b->x - a->x;
	out->y = b->y - a->y;
	out->z = b->z - a->z;
}

void func0f177050(struct coord *a, f32 mult, struct coord *out)
{
	out->x = a->x * mult;
	out->y = a->y * mult;
	out->z = a->z * mult;
}

f32 func0f17707c(struct coord *a, struct coord *b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

void func0f1770ac(struct coord *a, struct coord *b, struct coord *out)
{
	out->x = a->y * b->z - a->z * b->y;
	out->y = -(a->x * b->z - a->z * b->x);
	out->z = a->x * b->y - a->y * b->x;
}

void func0f177120(struct coord *in, struct coord *out)
{
	*out = *in;
}

void func0f17713c(struct coord *in, struct coord *out)
{
	out->x = -in->x;
	out->y = -in->y;
	out->z = -in->z;
}

bool func0f177164(struct coord *arg0, struct coord *arg1, u32 line, char *file)
{
	f32 sqdist = arg0->x * arg0->x + arg0->y * arg0->y + arg0->z * arg0->z;
	f32 mult;

	if (sqdist < var800845d4) {
		*arg0 = var800845f4;

		return false;
	}

	mult = 1.0f / sqrtf(sqdist);

	arg1->x = arg0->x * mult;
	arg1->y = arg0->y * mult;
	arg1->z = arg0->z * mult;

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

bool func0f177300(struct coord *a, struct coord *b)
{
	f32 diff = a->x - b->x;

	if (ABS(diff) < var800845d4) {
		diff = a->y - b->y;

		if (ABS(diff) < var800845d4) {
			diff = a->z - b->z;

			if (ABS(diff) < var800845d4) {
				return true;
			}
		}
	}

	return false;
}

bool func0f1773c8(struct coord *a, struct coord *b)
{
	if (a->x < b->x && -b->x < a->x
			&& a->y < b->y && -b->y < a->y
			&& a->z < b->z && -b->z < a->z) {
		return true;
	}

	return false;
}

f32 coordsGetDistance(struct coord *a, struct coord *b)
{
	f32 xdiff = b->x - a->x;
	f32 ydiff = b->y - a->y;
	f32 zdiff = b->z - a->z;

	return sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
}

bool func0f1774b4(struct coord *arg0, struct coord *arg1, struct coord *out)
{
	struct coord a;
	struct coord b;
	struct coord c;
	f32 mult;

	if (!func0f177164(arg1, &a, 702, "utils.c")) {
		osSyncPrintf("UTILS -> DEBUG ERROR - UM_fVec3_MakeNormalTo - Cant normalise\n");
		return false;
	}

	if (!func0f177164(arg0, &b, 710, "utils.c")) {
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

	func0f177164(arg0, arg1, 771, "utils.c");

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

	if (sqdist < var800845d4 && sqdist > -var800845d4) {
		return var800845d0;
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

void utilsReset(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
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

	func0f177164(&sp60, &sp60, 1101, "utils.c");

	for (i = 3; i < arg1; i++) {
		sp50.x = arg0[i].x - arg0[0].x;
		sp50.y = arg0[i].y - arg0[0].y;
		sp50.z = arg0[i].z - arg0[0].z;

		func0f177164(&sp50, &sp50, 1109, "utils.c");

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

s32 func0f177a54(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3)
{
	s32 i = 0;
	s32 v1 = 0;
	s32 t0 = 0;

	for (; i < arg1; i++) {
		s32 index = i * arg3;

		if (arg0[index] != 0) {
			u8 *ptr = &arg0[index];

			if (i != 0 && ptr[-arg3] == 0) {
				arg2[v1++] = 0;

				if (t0 == 255) {
					arg2[v1++] = 200;
					arg2[v1++] = 0;
					t0 -= 200;
				} else {
					while (t0 > 255) {
						arg2[v1++] = 255;
						t0 -= 255;
					}
				}

				arg2[v1++] = t0;
				t0 = 0;
			}

			arg2[v1++] = arg0[index];
		} else {
			t0++;
		}
	}

	arg2[v1++] = 0;
	arg2[v1++] = 0;

	return v1;
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

/**
 * randomfrac() returns a random float in the range 0.0 to 1.0.
 *
 * To avoid a bunch of FPU operations, we precompute 256 values within this
 * range and then use random() to get an index into the array. It lowers the
 * sample size but this is good enough.
 *
 * To prevent returning 0.0, we offset each value by 0.001953125
 * which is half of one increment.
 */
f32 g_Fracs[256] = {
	0.001953125f + 1.0f / 256.0f * 0,
	0.001953125f + 1.0f / 256.0f * 1,
	0.001953125f + 1.0f / 256.0f * 2,
	0.001953125f + 1.0f / 256.0f * 3,
	0.001953125f + 1.0f / 256.0f * 4,
	0.001953125f + 1.0f / 256.0f * 5,
	0.001953125f + 1.0f / 256.0f * 6,
	0.001953125f + 1.0f / 256.0f * 7,
	0.001953125f + 1.0f / 256.0f * 8,
	0.001953125f + 1.0f / 256.0f * 9,
	0.001953125f + 1.0f / 256.0f * 10,
	0.001953125f + 1.0f / 256.0f * 11,
	0.001953125f + 1.0f / 256.0f * 12,
	0.001953125f + 1.0f / 256.0f * 13,
	0.001953125f + 1.0f / 256.0f * 14,
	0.001953125f + 1.0f / 256.0f * 15,
	0.001953125f + 1.0f / 256.0f * 16,
	0.001953125f + 1.0f / 256.0f * 17,
	0.001953125f + 1.0f / 256.0f * 18,
	0.001953125f + 1.0f / 256.0f * 19,
	0.001953125f + 1.0f / 256.0f * 20,
	0.001953125f + 1.0f / 256.0f * 21,
	0.001953125f + 1.0f / 256.0f * 22,
	0.001953125f + 1.0f / 256.0f * 23,
	0.001953125f + 1.0f / 256.0f * 24,
	0.001953125f + 1.0f / 256.0f * 25,
	0.001953125f + 1.0f / 256.0f * 26,
	0.001953125f + 1.0f / 256.0f * 27,
	0.001953125f + 1.0f / 256.0f * 28,
	0.001953125f + 1.0f / 256.0f * 29,
	0.001953125f + 1.0f / 256.0f * 30,
	0.001953125f + 1.0f / 256.0f * 31,
	0.001953125f + 1.0f / 256.0f * 32,
	0.001953125f + 1.0f / 256.0f * 33,
	0.001953125f + 1.0f / 256.0f * 34,
	0.001953125f + 1.0f / 256.0f * 35,
	0.001953125f + 1.0f / 256.0f * 36,
	0.001953125f + 1.0f / 256.0f * 37,
	0.001953125f + 1.0f / 256.0f * 38,
	0.001953125f + 1.0f / 256.0f * 39,
	0.001953125f + 1.0f / 256.0f * 40,
	0.001953125f + 1.0f / 256.0f * 41,
	0.001953125f + 1.0f / 256.0f * 42,
	0.001953125f + 1.0f / 256.0f * 43,
	0.001953125f + 1.0f / 256.0f * 44,
	0.001953125f + 1.0f / 256.0f * 45,
	0.001953125f + 1.0f / 256.0f * 46,
	0.001953125f + 1.0f / 256.0f * 47,
	0.001953125f + 1.0f / 256.0f * 48,
	0.001953125f + 1.0f / 256.0f * 49,
	0.001953125f + 1.0f / 256.0f * 50,
	0.001953125f + 1.0f / 256.0f * 51,
	0.001953125f + 1.0f / 256.0f * 52,
	0.001953125f + 1.0f / 256.0f * 53,
	0.001953125f + 1.0f / 256.0f * 54,
	0.001953125f + 1.0f / 256.0f * 55,
	0.001953125f + 1.0f / 256.0f * 56,
	0.001953125f + 1.0f / 256.0f * 57,
	0.001953125f + 1.0f / 256.0f * 58,
	0.001953125f + 1.0f / 256.0f * 59,
	0.001953125f + 1.0f / 256.0f * 60,
	0.001953125f + 1.0f / 256.0f * 61,
	0.001953125f + 1.0f / 256.0f * 62,
	0.001953125f + 1.0f / 256.0f * 63,
	0.001953125f + 1.0f / 256.0f * 64,
	0.001953125f + 1.0f / 256.0f * 65,
	0.001953125f + 1.0f / 256.0f * 66,
	0.001953125f + 1.0f / 256.0f * 67,
	0.001953125f + 1.0f / 256.0f * 68,
	0.001953125f + 1.0f / 256.0f * 69,
	0.001953125f + 1.0f / 256.0f * 70,
	0.001953125f + 1.0f / 256.0f * 71,
	0.001953125f + 1.0f / 256.0f * 72,
	0.001953125f + 1.0f / 256.0f * 73,
	0.001953125f + 1.0f / 256.0f * 74,
	0.001953125f + 1.0f / 256.0f * 75,
	0.001953125f + 1.0f / 256.0f * 76,
	0.001953125f + 1.0f / 256.0f * 77,
	0.001953125f + 1.0f / 256.0f * 78,
	0.001953125f + 1.0f / 256.0f * 79,
	0.001953125f + 1.0f / 256.0f * 80,
	0.001953125f + 1.0f / 256.0f * 81,
	0.001953125f + 1.0f / 256.0f * 82,
	0.001953125f + 1.0f / 256.0f * 83,
	0.001953125f + 1.0f / 256.0f * 84,
	0.001953125f + 1.0f / 256.0f * 85,
	0.001953125f + 1.0f / 256.0f * 86,
	0.001953125f + 1.0f / 256.0f * 87,
	0.001953125f + 1.0f / 256.0f * 88,
	0.001953125f + 1.0f / 256.0f * 89,
	0.001953125f + 1.0f / 256.0f * 90,
	0.001953125f + 1.0f / 256.0f * 91,
	0.001953125f + 1.0f / 256.0f * 92,
	0.001953125f + 1.0f / 256.0f * 93,
	0.001953125f + 1.0f / 256.0f * 94,
	0.001953125f + 1.0f / 256.0f * 95,
	0.001953125f + 1.0f / 256.0f * 96,
	0.001953125f + 1.0f / 256.0f * 97,
	0.001953125f + 1.0f / 256.0f * 98,
	0.001953125f + 1.0f / 256.0f * 99,
	0.001953125f + 1.0f / 256.0f * 100,
	0.001953125f + 1.0f / 256.0f * 101,
	0.001953125f + 1.0f / 256.0f * 102,
	0.001953125f + 1.0f / 256.0f * 103,
	0.001953125f + 1.0f / 256.0f * 104,
	0.001953125f + 1.0f / 256.0f * 105,
	0.001953125f + 1.0f / 256.0f * 106,
	0.001953125f + 1.0f / 256.0f * 107,
	0.001953125f + 1.0f / 256.0f * 108,
	0.001953125f + 1.0f / 256.0f * 109,
	0.001953125f + 1.0f / 256.0f * 110,
	0.001953125f + 1.0f / 256.0f * 111,
	0.001953125f + 1.0f / 256.0f * 112,
	0.001953125f + 1.0f / 256.0f * 113,
	0.001953125f + 1.0f / 256.0f * 114,
	0.001953125f + 1.0f / 256.0f * 115,
	0.001953125f + 1.0f / 256.0f * 116,
	0.001953125f + 1.0f / 256.0f * 117,
	0.001953125f + 1.0f / 256.0f * 118,
	0.001953125f + 1.0f / 256.0f * 119,
	0.001953125f + 1.0f / 256.0f * 120,
	0.001953125f + 1.0f / 256.0f * 121,
	0.001953125f + 1.0f / 256.0f * 122,
	0.001953125f + 1.0f / 256.0f * 123,
	0.001953125f + 1.0f / 256.0f * 124,
	0.001953125f + 1.0f / 256.0f * 125,
	0.001953125f + 1.0f / 256.0f * 126,
	0.001953125f + 1.0f / 256.0f * 127,
	0.001953125f + 1.0f / 256.0f * 128,
	0.001953125f + 1.0f / 256.0f * 129,
	0.001953125f + 1.0f / 256.0f * 130,
	0.001953125f + 1.0f / 256.0f * 131,
	0.001953125f + 1.0f / 256.0f * 132,
	0.001953125f + 1.0f / 256.0f * 133,
	0.001953125f + 1.0f / 256.0f * 134,
	0.001953125f + 1.0f / 256.0f * 135,
	0.001953125f + 1.0f / 256.0f * 136,
	0.001953125f + 1.0f / 256.0f * 137,
	0.001953125f + 1.0f / 256.0f * 138,
	0.001953125f + 1.0f / 256.0f * 139,
	0.001953125f + 1.0f / 256.0f * 140,
	0.001953125f + 1.0f / 256.0f * 141,
	0.001953125f + 1.0f / 256.0f * 142,
	0.001953125f + 1.0f / 256.0f * 143,
	0.001953125f + 1.0f / 256.0f * 144,
	0.001953125f + 1.0f / 256.0f * 145,
	0.001953125f + 1.0f / 256.0f * 146,
	0.001953125f + 1.0f / 256.0f * 147,
	0.001953125f + 1.0f / 256.0f * 148,
	0.001953125f + 1.0f / 256.0f * 149,
	0.001953125f + 1.0f / 256.0f * 150,
	0.001953125f + 1.0f / 256.0f * 151,
	0.001953125f + 1.0f / 256.0f * 152,
	0.001953125f + 1.0f / 256.0f * 153,
	0.001953125f + 1.0f / 256.0f * 154,
	0.001953125f + 1.0f / 256.0f * 155,
	0.001953125f + 1.0f / 256.0f * 156,
	0.001953125f + 1.0f / 256.0f * 157,
	0.001953125f + 1.0f / 256.0f * 158,
	0.001953125f + 1.0f / 256.0f * 159,
	0.001953125f + 1.0f / 256.0f * 160,
	0.001953125f + 1.0f / 256.0f * 161,
	0.001953125f + 1.0f / 256.0f * 162,
	0.001953125f + 1.0f / 256.0f * 163,
	0.001953125f + 1.0f / 256.0f * 164,
	0.001953125f + 1.0f / 256.0f * 165,
	0.001953125f + 1.0f / 256.0f * 166,
	0.001953125f + 1.0f / 256.0f * 167,
	0.001953125f + 1.0f / 256.0f * 168,
	0.001953125f + 1.0f / 256.0f * 169,
	0.001953125f + 1.0f / 256.0f * 170,
	0.001953125f + 1.0f / 256.0f * 171,
	0.001953125f + 1.0f / 256.0f * 172,
	0.001953125f + 1.0f / 256.0f * 173,
	0.001953125f + 1.0f / 256.0f * 174,
	0.001953125f + 1.0f / 256.0f * 175,
	0.001953125f + 1.0f / 256.0f * 176,
	0.001953125f + 1.0f / 256.0f * 177,
	0.001953125f + 1.0f / 256.0f * 178,
	0.001953125f + 1.0f / 256.0f * 179,
	0.001953125f + 1.0f / 256.0f * 180,
	0.001953125f + 1.0f / 256.0f * 181,
	0.001953125f + 1.0f / 256.0f * 182,
	0.001953125f + 1.0f / 256.0f * 183,
	0.001953125f + 1.0f / 256.0f * 184,
	0.001953125f + 1.0f / 256.0f * 185,
	0.001953125f + 1.0f / 256.0f * 186,
	0.001953125f + 1.0f / 256.0f * 187,
	0.001953125f + 1.0f / 256.0f * 188,
	0.001953125f + 1.0f / 256.0f * 189,
	0.001953125f + 1.0f / 256.0f * 190,
	0.001953125f + 1.0f / 256.0f * 191,
	0.001953125f + 1.0f / 256.0f * 192,
	0.001953125f + 1.0f / 256.0f * 193,
	0.001953125f + 1.0f / 256.0f * 194,
	0.001953125f + 1.0f / 256.0f * 195,
	0.001953125f + 1.0f / 256.0f * 196,
	0.001953125f + 1.0f / 256.0f * 197,
	0.001953125f + 1.0f / 256.0f * 198,
	0.001953125f + 1.0f / 256.0f * 199,
	0.001953125f + 1.0f / 256.0f * 200,
	0.001953125f + 1.0f / 256.0f * 201,
	0.001953125f + 1.0f / 256.0f * 202,
	0.001953125f + 1.0f / 256.0f * 203,
	0.001953125f + 1.0f / 256.0f * 204,
	0.001953125f + 1.0f / 256.0f * 205,
	0.001953125f + 1.0f / 256.0f * 206,
	0.001953125f + 1.0f / 256.0f * 207,
	0.001953125f + 1.0f / 256.0f * 208,
	0.001953125f + 1.0f / 256.0f * 209,
	0.001953125f + 1.0f / 256.0f * 210,
	0.001953125f + 1.0f / 256.0f * 211,
	0.001953125f + 1.0f / 256.0f * 212,
	0.001953125f + 1.0f / 256.0f * 213,
	0.001953125f + 1.0f / 256.0f * 214,
	0.001953125f + 1.0f / 256.0f * 215,
	0.001953125f + 1.0f / 256.0f * 216,
	0.001953125f + 1.0f / 256.0f * 217,
	0.001953125f + 1.0f / 256.0f * 218,
	0.001953125f + 1.0f / 256.0f * 219,
	0.001953125f + 1.0f / 256.0f * 220,
	0.001953125f + 1.0f / 256.0f * 221,
	0.001953125f + 1.0f / 256.0f * 222,
	0.001953125f + 1.0f / 256.0f * 223,
	0.001953125f + 1.0f / 256.0f * 224,
	0.001953125f + 1.0f / 256.0f * 225,
	0.001953125f + 1.0f / 256.0f * 226,
	0.001953125f + 1.0f / 256.0f * 227,
	0.001953125f + 1.0f / 256.0f * 228,
	0.001953125f + 1.0f / 256.0f * 229,
	0.001953125f + 1.0f / 256.0f * 230,
	0.001953125f + 1.0f / 256.0f * 231,
	0.001953125f + 1.0f / 256.0f * 232,
	0.001953125f + 1.0f / 256.0f * 233,
	0.001953125f + 1.0f / 256.0f * 234,
	0.001953125f + 1.0f / 256.0f * 235,
	0.001953125f + 1.0f / 256.0f * 236,
	0.001953125f + 1.0f / 256.0f * 237,
	0.001953125f + 1.0f / 256.0f * 238,
	0.001953125f + 1.0f / 256.0f * 239,
	0.001953125f + 1.0f / 256.0f * 240,
	0.001953125f + 1.0f / 256.0f * 241,
	0.001953125f + 1.0f / 256.0f * 242,
	0.001953125f + 1.0f / 256.0f * 243,
	0.001953125f + 1.0f / 256.0f * 244,
	0.001953125f + 1.0f / 256.0f * 245,
	0.001953125f + 1.0f / 256.0f * 246,
	0.001953125f + 1.0f / 256.0f * 247,
	0.001953125f + 1.0f / 256.0f * 248,
	0.001953125f + 1.0f / 256.0f * 249,
	0.001953125f + 1.0f / 256.0f * 250,
	0.001953125f + 1.0f / 256.0f * 251,
	0.001953125f + 1.0f / 256.0f * 252,
	0.001953125f + 1.0f / 256.0f * 253,
	0.001953125f + 1.0f / 256.0f * 254,
	0.001953125f + 1.0f / 256.0f * 255,
};

f32 randomfrac(void)
{
	return g_Fracs[(random() & 0x3fc) >> 2];
}
