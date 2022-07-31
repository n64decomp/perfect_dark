#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/savebuffer.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

f32 func0f1577f0(f32 arg0[2], f32 arg1[2], f32 arg2[2], f32 arg3[2])
{
	f32 mult1 = arg2[1] - arg3[1];
	f32 mult2 = arg3[0] - arg2[0];
	f32 a = (arg2[1] - arg0[1]) * mult2 + (arg2[0] - arg0[0]) * mult1;
	f32 b = (arg1[1] - arg0[1]) * mult2 + (arg1[0] - arg0[0]) * mult1;

	if (b == 0.0f) {
		return 1.0f;
	}

	a /= b;

	if (a < 0.0f || a > 1.0f) {
		return 1.0f;
	}

	return a;
}

f32 func0f1578c8(struct coord *arg0, struct coord *arg1, struct coord *arg2)
{
	f32 value2;
	f32 value1;
	f32 sp24;
	f32 mult1;
	f32 mult2;

	mult1 = arg2->x - arg0->y;
	mult2 = arg2->y - arg0->z;

	value1 = mult2 * arg1->x - mult1 * arg1->y;
	value2 = mult1 * arg1->x + mult2 * arg1->y;

	sp24 = (arg0->x - value1) * (arg0->x + value1);

	if (sp24 < 0.0f) {
		return MAXFLOAT;
	}

	value2 -= sqrtf(sp24);

	if (value2 < 0.0f) {
		if (value2 * value2 + value1 * value1 <= arg0->x * arg0->x) {
			return 0.0f;
		}

		return MAXFLOAT;
	}

	return value2;
}

GLOBAL_ASM(
glabel func0f1579cc
/*  f1579cc:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f1579d0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1579d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1579d8:	afa600b8 */ 	sw	$a2,0xb8($sp)
/*  f1579dc:	c4e00000 */ 	lwc1	$f0,0x0($a3)
/*  f1579e0:	c4e20004 */ 	lwc1	$f2,0x4($a3)
/*  f1579e4:	00a08025 */ 	or	$s0,$a1,$zero
/*  f1579e8:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f1579ec:	afa700bc */ 	sw	$a3,0xbc($sp)
/*  f1579f0:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f1579f4:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f1579f8:	0c012974 */ 	jal	sqrtf
/*  f1579fc:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f157a00:	44803000 */ 	mtc1	$zero,$f6
/*  f157a04:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f157a08:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f157a0c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f157a10:	46000386 */ 	mov.s	$f14,$f0
/*  f157a14:	3c013f80 */ 	lui	$at,0x3f80
/*  f157a18:	45020006 */ 	bc1fl	.L0f157a34
/*  f157a1c:	44814000 */ 	mtc1	$at,$f8
/*  f157a20:	3c013f80 */ 	lui	$at,0x3f80
/*  f157a24:	44810000 */ 	mtc1	$at,$f0
/*  f157a28:	100000dc */ 	b	.L0f157d9c
/*  f157a2c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f157a30:	44814000 */ 	mtc1	$at,$f8
.L0f157a34:
/*  f157a34:	c4e40000 */ 	lwc1	$f4,0x0($a3)
/*  f157a38:	8fa200b8 */ 	lw	$v0,0xb8($sp)
/*  f157a3c:	460e4403 */ 	div.s	$f16,$f8,$f14
/*  f157a40:	46102282 */ 	mul.s	$f10,$f4,$f16
/*  f157a44:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f157a48:	c4e60004 */ 	lwc1	$f6,0x4($a3)
/*  f157a4c:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f157a50:	e7a800a4 */ 	swc1	$f8,0xa4($sp)
/*  f157a54:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f157a58:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f157a5c:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f157a60:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f157a64:	460a2001 */ 	sub.s	$f0,$f4,$f10
/*  f157a68:	e7b00044 */ 	swc1	$f16,0x44($sp)
/*  f157a6c:	e7ae00ac */ 	swc1	$f14,0xac($sp)
/*  f157a70:	46083081 */ 	sub.s	$f2,$f6,$f8
/*  f157a74:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f157a78:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f157a7c:	afa700bc */ 	sw	$a3,0xbc($sp)
/*  f157a80:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f157a84:	e7a2009c */ 	swc1	$f2,0x9c($sp)
/*  f157a88:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f157a8c:	0c012974 */ 	jal	sqrtf
/*  f157a90:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f157a94:	44803000 */ 	mtc1	$zero,$f6
/*  f157a98:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f157a9c:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f157aa0:	46060032 */ 	c.eq.s	$f0,$f6
/*  f157aa4:	3c013f80 */ 	lui	$at,0x3f80
/*  f157aa8:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157aac:	45010077 */ 	bc1t	.L0f157c8c
/*  f157ab0:	00000000 */ 	nop
/*  f157ab4:	44814000 */ 	mtc1	$at,$f8
/*  f157ab8:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f157abc:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f157ac0:	46004483 */ 	div.s	$f18,$f8,$f0
/*  f157ac4:	02001025 */ 	or	$v0,$s0,$zero
/*  f157ac8:	46003207 */ 	neg.s	$f8,$f6
/*  f157acc:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f157ad0:	00000000 */ 	nop
/*  f157ad4:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f157ad8:	e7aa002c */ 	swc1	$f10,0x2c($sp)
/*  f157adc:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f157ae0:	e7a40028 */ 	swc1	$f4,0x28($sp)
/*  f157ae4:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f157ae8:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f157aec:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*  f157af0:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*  f157af4:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f157af8:	460a4382 */ 	mul.s	$f14,$f8,$f10
/*  f157afc:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f157b00:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f157b04:	46044402 */ 	mul.s	$f16,$f8,$f4
/*  f157b08:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f157b0c:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f157b10:	e7aa0030 */ 	swc1	$f10,0x30($sp)
/*  f157b14:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*  f157b18:	46024101 */ 	sub.s	$f4,$f8,$f2
/*  f157b1c:	c60c0004 */ 	lwc1	$f12,0x4($s0)
/*  f157b20:	460c5201 */ 	sub.s	$f8,$f10,$f12
/*  f157b24:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f157b28:	00000000 */ 	nop
/*  f157b2c:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f157b30:	44804000 */ 	mtc1	$zero,$f8
/*  f157b34:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f157b38:	4608503c */ 	c.lt.s	$f10,$f8
/*  f157b3c:	00000000 */ 	nop
/*  f157b40:	45000003 */ 	bc1f	.L0f157b50
/*  f157b44:	00000000 */ 	nop
/*  f157b48:	46007387 */ 	neg.s	$f14,$f14
/*  f157b4c:	46008407 */ 	neg.s	$f16,$f16
.L0f157b50:
/*  f157b50:	460e1180 */ 	add.s	$f6,$f2,$f14
/*  f157b54:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f157b58:	46106100 */ 	add.s	$f4,$f12,$f16
/*  f157b5c:	e7a60078 */ 	swc1	$f6,0x78($sp)
/*  f157b60:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f157b64:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f157b68:	460e5200 */ 	add.s	$f8,$f10,$f14
/*  f157b6c:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f157b70:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f157b74:	46103100 */ 	add.s	$f4,$f6,$f16
/*  f157b78:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f157b7c:	e7a40074 */ 	swc1	$f4,0x74($sp)
/*  f157b80:	c4ea0004 */ 	lwc1	$f10,0x4($a3)
/*  f157b84:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f157b88:	e7aa0048 */ 	swc1	$f10,0x48($sp)
/*  f157b8c:	c4e80000 */ 	lwc1	$f8,0x0($a3)
/*  f157b90:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f157b94:	e7a8004c */ 	swc1	$f8,0x4c($sp)
/*  f157b98:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f157b9c:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f157ba0:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f157ba4:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f157ba8:	46044202 */ 	mul.s	$f8,$f8,$f4
/*  f157bac:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*  f157bb0:	46085281 */ 	sub.s	$f10,$f10,$f8
/*  f157bb4:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f157bb8:	e7aa0068 */ 	swc1	$f10,0x68($sp)
/*  f157bbc:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f157bc0:	46064202 */ 	mul.s	$f8,$f8,$f6
/*  f157bc4:	c7aa0020 */ 	lwc1	$f10,0x20($sp)
/*  f157bc8:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*  f157bcc:	46044381 */ 	sub.s	$f14,$f8,$f4
/*  f157bd0:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f157bd4:	46043182 */ 	mul.s	$f6,$f6,$f4
/*  f157bd8:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f157bdc:	e7ae006c */ 	swc1	$f14,0x6c($sp)
/*  f157be0:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*  f157be4:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*  f157be8:	46005306 */ 	mov.s	$f12,$f10
/*  f157bec:	46043481 */ 	sub.s	$f18,$f6,$f4
/*  f157bf0:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f157bf4:	460a903c */ 	c.lt.s	$f18,$f10
/*  f157bf8:	00000000 */ 	nop
/*  f157bfc:	4502000a */ 	bc1fl	.L0f157c28
/*  f157c00:	460c9032 */ 	c.eq.s	$f18,$f12
/*  f157c04:	46008407 */ 	neg.s	$f16,$f16
/*  f157c08:	46003107 */ 	neg.s	$f4,$f6
/*  f157c0c:	46009306 */ 	mov.s	$f12,$f18
/*  f157c10:	00608025 */ 	or	$s0,$v1,$zero
/*  f157c14:	46005486 */ 	mov.s	$f18,$f10
/*  f157c18:	00401825 */ 	or	$v1,$v0,$zero
/*  f157c1c:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f157c20:	e7b00088 */ 	swc1	$f16,0x88($sp)
/*  f157c24:	460c9032 */ 	c.eq.s	$f18,$f12
.L0f157c28:
/*  f157c28:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f157c2c:	02003025 */ 	or	$a2,$s0,$zero
/*  f157c30:	45020012 */ 	bc1fl	.L0f157c7c
/*  f157c34:	460e903c */ 	c.lt.s	$f18,$f14
/*  f157c38:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157c3c:	afa300b8 */ 	sw	$v1,0xb8($sp)
/*  f157c40:	0fc55e32 */ 	jal	func0f1578c8
/*  f157c44:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f157c48:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f157c4c:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157c50:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*  f157c54:	0fc55e32 */ 	jal	func0f1578c8
/*  f157c58:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f157c5c:	c7a20060 */ 	lwc1	$f2,0x60($sp)
/*  f157c60:	4602003c */ 	c.lt.s	$f0,$f2
/*  f157c64:	00000000 */ 	nop
/*  f157c68:	45020038 */ 	bc1fl	.L0f157d4c
/*  f157c6c:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f157c70:	10000035 */ 	b	.L0f157d48
/*  f157c74:	46000086 */ 	mov.s	$f2,$f0
/*  f157c78:	460e903c */ 	c.lt.s	$f18,$f14
.L0f157c7c:
/*  f157c7c:	00000000 */ 	nop
/*  f157c80:	45020007 */ 	bc1fl	.L0f157ca0
/*  f157c84:	460c703c */ 	c.lt.s	$f14,$f12
/*  f157c88:	afa300b8 */ 	sw	$v1,0xb8($sp)
.L0f157c8c:
/*  f157c8c:	0fc55e32 */ 	jal	func0f1578c8
/*  f157c90:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*  f157c94:	1000002c */ 	b	.L0f157d48
/*  f157c98:	46000086 */ 	mov.s	$f2,$f0
/*  f157c9c:	460c703c */ 	c.lt.s	$f14,$f12
.L0f157ca0:
/*  f157ca0:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157ca4:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*  f157ca8:	45020006 */ 	bc1fl	.L0f157cc4
/*  f157cac:	c60c0004 */ 	lwc1	$f12,0x4($s0)
/*  f157cb0:	0fc55e32 */ 	jal	func0f1578c8
/*  f157cb4:	02003025 */ 	or	$a2,$s0,$zero
/*  f157cb8:	10000023 */ 	b	.L0f157d48
/*  f157cbc:	46000086 */ 	mov.s	$f2,$f0
/*  f157cc0:	c60c0004 */ 	lwc1	$f12,0x4($s0)
.L0f157cc4:
/*  f157cc4:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
/*  f157cc8:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f157ccc:	460c4181 */ 	sub.s	$f6,$f8,$f12
/*  f157cd0:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f157cd4:	3c013f80 */ 	lui	$at,0x3f80
/*  f157cd8:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f157cdc:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f157ce0:	46023281 */ 	sub.s	$f10,$f6,$f2
/*  f157ce4:	46105282 */ 	mul.s	$f10,$f10,$f16
/*  f157ce8:	46045000 */ 	add.s	$f0,$f10,$f4
/*  f157cec:	c7aa004c */ 	lwc1	$f10,0x4c($sp)
/*  f157cf0:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f157cf4:	46022181 */ 	sub.s	$f6,$f4,$f2
/*  f157cf8:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f157cfc:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f157d00:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f157d04:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*  f157d08:	460c3201 */ 	sub.s	$f8,$f6,$f12
/*  f157d0c:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f157d10:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f157d14:	46065380 */ 	add.s	$f14,$f10,$f6
/*  f157d18:	460e0032 */ 	c.eq.s	$f0,$f14
/*  f157d1c:	00000000 */ 	nop
/*  f157d20:	45020005 */ 	bc1fl	.L0f157d38
/*  f157d24:	46040201 */ 	sub.s	$f8,$f0,$f4
/*  f157d28:	44810000 */ 	mtc1	$at,$f0
/*  f157d2c:	1000001b */ 	b	.L0f157d9c
/*  f157d30:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f157d34:	46040201 */ 	sub.s	$f8,$f0,$f4
.L0f157d38:
/*  f157d38:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f157d3c:	460e0101 */ 	sub.s	$f4,$f0,$f14
/*  f157d40:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f157d44:	46043083 */ 	div.s	$f2,$f6,$f4
.L0f157d48:
/*  f157d48:	c7a800ac */ 	lwc1	$f8,0xac($sp)
.L0f157d4c:
/*  f157d4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f157d50:	4602403c */ 	c.lt.s	$f8,$f2
/*  f157d54:	00000000 */ 	nop
/*  f157d58:	45020005 */ 	bc1fl	.L0f157d70
/*  f157d5c:	44805000 */ 	mtc1	$zero,$f10
/*  f157d60:	44810000 */ 	mtc1	$at,$f0
/*  f157d64:	1000000d */ 	b	.L0f157d9c
/*  f157d68:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f157d6c:	44805000 */ 	mtc1	$zero,$f10
.L0f157d70:
/*  f157d70:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f157d74:	460a103c */ 	c.lt.s	$f2,$f10
/*  f157d78:	00000000 */ 	nop
/*  f157d7c:	45000004 */ 	bc1f	.L0f157d90
/*  f157d80:	00000000 */ 	nop
/*  f157d84:	44800000 */ 	mtc1	$zero,$f0
/*  f157d88:	10000004 */ 	b	.L0f157d9c
/*  f157d8c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f157d90:
/*  f157d90:	46061002 */ 	mul.s	$f0,$f2,$f6
/*  f157d94:	00000000 */ 	nop
/*  f157d98:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f157d9c:
/*  f157d9c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f157da0:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f157da4:	03e00008 */ 	jr	$ra
/*  f157da8:	00000000 */ 	nop
);
