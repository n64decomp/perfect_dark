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
void *var800ac0e8[4];
u32 var800ac0f8[4];

f32 var800845d0 = 999999;
f32 var800845d4 = 0.00001f;
s32 var800845d8 = 1;
u32 var800845dc = 0x00000000;
u32 var800845e0 = 0x00000000;
u32 var800845e4 = 0x00000000;
u32 var800845e8 = 0x00000000;
u32 var800845ec = 0x3f800000;
u32 var800845f0 = 0x00000000;
struct coord var800845f4 = {0, 0, 1};
u32 var80084600 = 0x3f800000;
u32 var80084604 = 0x00000000;
u32 var80084608 = 0x00000000;
u32 var8008460c = 0xffffffff;
void *var80084610 = NULL;
void *var80084614 = NULL;
void *var80084618 = NULL;
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

GLOBAL_ASM(
glabel utilsInit
/*  f176ddc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f176de0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f176de4:	24042710 */ 	addiu	$a0,$zero,0x2710
/*  f176de8:	0c0048f2 */ 	jal	mempAlloc
/*  f176dec:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f176df0:	3c01800b */ 	lui	$at,%hi(var800ac0d0)
/*  f176df4:	ac22c0d0 */ 	sw	$v0,%lo(var800ac0d0)($at)
/*  f176df8:	0fc5db69 */ 	jal	align16
/*  f176dfc:	24043900 */ 	addiu	$a0,$zero,0x3900
/*  f176e00:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f176e04:	00402025 */ 	or	$a0,$v0,$zero
/*  f176e08:	0c0048f2 */ 	jal	mempAlloc
/*  f176e0c:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f176e10:	3c05800b */ 	lui	$a1,%hi(var800ac0e8)
/*  f176e14:	24a5c0e8 */ 	addiu	$a1,$a1,%lo(var800ac0e8)
/*  f176e18:	1040000e */ 	beqz	$v0,.L0f176e54
/*  f176e1c:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f176e20:	3c02800b */ 	lui	$v0,%hi(var800ac0e8)
/*  f176e24:	2442c0e8 */ 	addiu	$v0,$v0,%lo(var800ac0e8)
/*  f176e28:	00001825 */ 	or	$v1,$zero,$zero
/*  f176e2c:	24040190 */ 	addiu	$a0,$zero,0x190
.L0f176e30:
/*  f176e30:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f176e34:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f176e38:	24630064 */ 	addiu	$v1,$v1,0x64
/*  f176e3c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f176e40:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f176e44:	1464fffa */ 	bne	$v1,$a0,.L0f176e30
/*  f176e48:	ac59fffc */ 	sw	$t9,-0x4($v0)
/*  f176e4c:	10000009 */ 	b	.L0f176e74
/*  f176e50:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f176e54:
/*  f176e54:	3c02800b */ 	lui	$v0,%hi(var800ac0e8)
/*  f176e58:	3c03800b */ 	lui	$v1,%hi(var800ac0f8)
/*  f176e5c:	2463c0f8 */ 	addiu	$v1,$v1,%lo(var800ac0f8)
/*  f176e60:	2442c0e8 */ 	addiu	$v0,$v0,%lo(var800ac0e8)
.L0f176e64:
/*  f176e64:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f176e68:	1443fffe */ 	bne	$v0,$v1,.L0f176e64
/*  f176e6c:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f176e70:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f176e74:
/*  f176e74:	8fa90018 */ 	lw	$t1,0x18($sp)
/*  f176e78:	3c018008 */ 	lui	$at,%hi(var80084610)
/*  f176e7c:	24481900 */ 	addiu	$t0,$v0,0x1900
/*  f176e80:	ac284610 */ 	sw	$t0,%lo(var80084610)($at)
/*  f176e84:	00495021 */ 	addu	$t2,$v0,$t1
/*  f176e88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f176e8c:	254bffff */ 	addiu	$t3,$t2,-1
/*  f176e90:	3c018008 */ 	lui	$at,%hi(var80084618)
/*  f176e94:	3c0c8008 */ 	lui	$t4,%hi(var80084610)
/*  f176e98:	8d8c4610 */ 	lw	$t4,%lo(var80084610)($t4)
/*  f176e9c:	ac2b4618 */ 	sw	$t3,%lo(var80084618)($at)
/*  f176ea0:	3c018008 */ 	lui	$at,%hi(var80084614)
/*  f176ea4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f176ea8:	03e00008 */ 	jr	$ra
/*  f176eac:	ac2c4614 */ 	sw	$t4,%lo(var80084614)($at)
);

// Mismatch: Different codegen in last 3 statements
//void utilsInit(void)
//{
//	u32 stack1;
//	u32 stack2;
//	s32 i;
//	u32 size;
//
//	static void *var80084610 = NULL;
//	static void *var80084614 = NULL;
//	static void *var80084618 = NULL;
//	static void *var800ac0e8[4];
//
//	var800ac0d0 = mempAlloc(10000, MEMPOOL_8);
//
//	size = align16(0x3900);
//	var800ac0e8[0] = mempAlloc(size, MEMPOOL_8);
//
//	if (var800ac0e8[0] != NULL) {
//		for (i = 0; i < 4; i++) {
//			var800ac0e8[i] = (void *)((u32)var800ac0e8[0] + ((i * 100) << 4));
//		}
//	} else {
//		for (i = 0; i < 4; i++) {
//			var800ac0e8[i] = NULL;
//		}
//	}
//
//	var80084610 = (void *)((u32)var800ac0e8[0] + 0x1900);
//	var80084614 = var80084610;
//	var80084618 = (void *)((u32)var800ac0e8[0] + size - 1);
//}

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
	out->x = in->x;
	out->y = in->y;
	out->z = in->z;
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

GLOBAL_ASM(
glabel func0f177a54
/*  f177a54:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f177a58:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f177a5c:	00c08025 */ 	or	$s0,$a2,$zero
/*  f177a60:	00001025 */ 	or	$v0,$zero,$zero
/*  f177a64:	00001825 */ 	or	$v1,$zero,$zero
/*  f177a68:	18a0002d */ 	blez	$a1,.L0f177b20
/*  f177a6c:	00004025 */ 	or	$t0,$zero,$zero
/*  f177a70:	00803025 */ 	or	$a2,$a0,$zero
/*  f177a74:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f177a78:	240b00c8 */ 	addiu	$t3,$zero,0xc8
/*  f177a7c:	240a00ff */ 	addiu	$t2,$zero,0xff
.L0f177a80:
/*  f177a80:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f177a84:	50800023 */ 	beqzl	$a0,.L0f177b14
/*  f177a88:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f177a8c:	1040001d */ 	beqz	$v0,.L0f177b04
/*  f177a90:	02034821 */ 	addu	$t1,$s0,$v1
/*  f177a94:	00c77023 */ 	subu	$t6,$a2,$a3
/*  f177a98:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*  f177a9c:	55e0001a */ 	bnezl	$t7,.L0f177b08
/*  f177aa0:	a1240000 */ 	sb	$a0,0x0($t1)
/*  f177aa4:	a1200000 */ 	sb	$zero,0x0($t1)
/*  f177aa8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177aac:	150a0007 */ 	bne	$t0,$t2,.L0f177acc
/*  f177ab0:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f177ab4:	a12b0000 */ 	sb	$t3,0x0($t1)
/*  f177ab8:	a1200001 */ 	sb	$zero,0x1($t1)
/*  f177abc:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f177ac0:	25290002 */ 	addiu	$t1,$t1,0x2
/*  f177ac4:	1000000a */ 	b	.L0f177af0
/*  f177ac8:	2508ff38 */ 	addiu	$t0,$t0,-200
.L0f177acc:
/*  f177acc:	29010100 */ 	slti	$at,$t0,0x100
/*  f177ad0:	54200008 */ 	bnezl	$at,.L0f177af4
/*  f177ad4:	a1280000 */ 	sb	$t0,0x0($t1)
.L0f177ad8:
/*  f177ad8:	2508ff01 */ 	addiu	$t0,$t0,-255
/*  f177adc:	29010100 */ 	slti	$at,$t0,0x100
/*  f177ae0:	a12c0000 */ 	sb	$t4,0x0($t1)
/*  f177ae4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177ae8:	1020fffb */ 	beqz	$at,.L0f177ad8
/*  f177aec:	25290001 */ 	addiu	$t1,$t1,0x1
.L0f177af0:
/*  f177af0:	a1280000 */ 	sb	$t0,0x0($t1)
.L0f177af4:
/*  f177af4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177af8:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f177afc:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f177b00:	00004025 */ 	or	$t0,$zero,$zero
.L0f177b04:
/*  f177b04:	a1240000 */ 	sb	$a0,0x0($t1)
.L0f177b08:
/*  f177b08:	10000002 */ 	b	.L0f177b14
/*  f177b0c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177b10:	25080001 */ 	addiu	$t0,$t0,0x1
.L0f177b14:
/*  f177b14:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f177b18:	1445ffd9 */ 	bne	$v0,$a1,.L0f177a80
/*  f177b1c:	00c73021 */ 	addu	$a2,$a2,$a3
.L0f177b20:
/*  f177b20:	0203c021 */ 	addu	$t8,$s0,$v1
/*  f177b24:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f177b28:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f177b2c:	0203c821 */ 	addu	$t9,$s0,$v1
/*  f177b30:	a3200000 */ 	sb	$zero,0x0($t9)
/*  f177b34:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f177b38:	24620001 */ 	addiu	$v0,$v1,0x1
/*  f177b3c:	03e00008 */ 	jr	$ra
/*  f177b40:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

// Mismatch: Goal moves a0 to a2
//s32 func0f177a54(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3)
//{
//	s32 i = 0;
//	s32 v1 = 0;
//	s32 t0 = 0;
//
//	for (; i < arg1; i++) {
//		if (*arg0 != 0) {
//			if (i != 0 && arg0[-arg3] == 0) {
//				arg2[v1++] = 0;
//
//				if (t0 == 255) {
//					arg2[v1++] = 200;
//					arg2[v1++] = 0;
//					t0 -= 200;
//				} else {
//					while (t0 > 255) {
//						arg2[v1++] = 255;
//						t0 -= 255;
//					}
//				}
//
//				arg2[v1++] = t0;
//				t0 = 0;
//			}
//
//			arg2[v1++] = *arg0;
//		} else {
//			t0++;
//		}
//
//		arg0 += arg3;
//	}
//
//	arg2[v1++] = 0;
//	arg2[v1++] = 0;
//
//	return v1;
//}

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
