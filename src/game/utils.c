#include <ultra64.h>
#include "constants.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/memp.h"
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

void func0f1770ac(struct coord *a, struct coord *b, struct coord *out)
{
	out->x = a->y * b->z - a->z * b->y;
	out->y = -(a->x * b->z - a->z * b->x);
	out->z = a->x * b->y - a->y * b->x;
}

bool func0f177164(struct coord *arg0, struct coord *arg1, u32 line, char *file)
{
	f32 sqdist = arg0->x * arg0->x + arg0->y * arg0->y + arg0->z * arg0->z;
	f32 mult;

	if (sqdist < var800845d4) {
		arg0->x = var800845f4.x;
		arg0->y = var800845f4.y;
		arg0->z = var800845f4.z;

		return false;
	}

	mult = 1.0f / sqrtf(sqdist);

	arg1->x = arg0->x * mult;
	arg1->y = arg0->y * mult;
	arg1->z = arg0->z * mult;

	return true;
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

const char var7f1b7e00[] = "WARNING - UTILS -> DEBUG - Triangle passed to Planar Poly Test\n";

void utilsReset(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		var800ac0f8[i] = 0;
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
