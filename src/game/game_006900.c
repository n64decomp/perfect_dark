#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "game/game_006900.h"
#include "game/game_092610.h"
#include "game/bg.h"
#include "bss.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

f32 var80061630 = 0;
f32 var80061634 = 0;

/**
 * Blends two colours together.
 *
 * The aweight argument is how much weight is given to colour A, on a scale of
 * 0 to 255.
 */
u32 colourBlend(u32 a, u32 b, u32 aweight)
{
	u32 bweight = 0xff - aweight;

	return (((aweight * ((a >> 24) & 0xff) + bweight * ((b >> 24) & 0xff)) >> 8) << 24)
		| (((aweight * ((a >> 16) & 0xff) + bweight * ((b >> 16) & 0xff)) >> 8) << 16)
		| (((aweight * ((a >> 8) & 0xff) + bweight * ((b >> 8) & 0xff)) >> 8) << 8)
		| ((aweight * (a & 0xff) + bweight * (b & 0xff)) >> 8);
}

void func0f0069dc(void)
{
#if VERSION >= VERSION_PAL_FINAL
	var80061630 = var80061630 + g_Vars.diffframe240freal / 4800.0f;
#else
	var80061630 = var80061630 + g_Vars.diffframe240f / 4800.0f;
#endif

	if (var80061630 > 1.0f) {
		var80061630 -= 1.0f;
	}

#if VERSION >= VERSION_PAL_FINAL
	var80061634 = var80061634 + g_Vars.lvupdate240freal / 4800.0f;
#else
	var80061634 = var80061634 + g_Vars.lvupdate240f / 4800.0f;
#endif

	if (var80061634 > 1.0f) {
		var80061634 -= 1.0f;
	}

#if PIRACYCHECKS
	{
		u32 *ptr = (u32 *)&func00015fd0;
		u32 *end = (u32 *)&func00016054;
		u32 checksum = 0;

		while (ptr < end) {
			checksum ^= ~*ptr;
			checksum <<= 1;
			ptr++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			u32 *ptr = (u32 *)&bgInit;
			ptr += random() % 0x40;
			end = &ptr[4];

			while (ptr < end) {
				*ptr = 0x00000012;
				ptr++;
			}
		}
	}
#endif
}

GLOBAL_ASM(
glabel func0f006b08
.late_rodata
glabel var7f1a7e70
.word 0x40490fdb
.text
/*  f006b08:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f006b0c:	c4241630 */ 	lwc1	$f4,%lo(var80061630)($at)
/*  f006b10:	3c017f1a */ 	lui	$at,%hi(var7f1a7e70)
/*  f006b14:	c4287e70 */ 	lwc1	$f8,%lo(var7f1a7e70)($at)
/*  f006b18:	46046002 */ 	mul.s	$f0,$f12,$f4
/*  f006b1c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f006b20:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f006b24:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f006b28:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f006b2c:	0c0068f7 */ 	jal	sinf
/*  f006b30:	00000000 */ 	nop
/*  f006b34:	3c013f00 */ 	lui	$at,0x3f00
/*  f006b38:	44815000 */ 	mtc1	$at,$f10
/*  f006b3c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f006b40:	44819000 */ 	mtc1	$at,$f18
/*  f006b44:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f006b48:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f006b4c:	03e00008 */ 	jr	$ra
/*  f006b50:	46128000 */ 	add.s	$f0,$f16,$f18
);

GLOBAL_ASM(
glabel func0f006b54
.late_rodata
glabel var7f1a7e74
.word 0x40490fdb
.text
/*  f006b54:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f006b58:	c4241630 */ 	lwc1	$f4,%lo(var80061630)($at)
/*  f006b5c:	3c017f1a */ 	lui	$at,%hi(var7f1a7e74)
/*  f006b60:	c4287e74 */ 	lwc1	$f8,%lo(var7f1a7e74)($at)
/*  f006b64:	46046002 */ 	mul.s	$f0,$f12,$f4
/*  f006b68:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f006b6c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f006b70:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f006b74:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f006b78:	0c0068f4 */ 	jal	cosf
/*  f006b7c:	00000000 */ 	nop
/*  f006b80:	3c013f00 */ 	lui	$at,0x3f00
/*  f006b84:	44815000 */ 	mtc1	$at,$f10
/*  f006b88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f006b8c:	44819000 */ 	mtc1	$at,$f18
/*  f006b90:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f006b94:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f006b98:	03e00008 */ 	jr	$ra
/*  f006b9c:	46128000 */ 	add.s	$f0,$f16,$f18
);

GLOBAL_ASM(
glabel func0f006ba0
/*  f006ba0:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f006ba4:	c4241630 */ 	lwc1	$f4,%lo(var80061630)($at)
/*  f006ba8:	460c2082 */ 	mul.s	$f2,$f4,$f12
/*  f006bac:	4600118d */ 	trunc.w.s	$f6,$f2
/*  f006bb0:	440f3000 */ 	mfc1	$t7,$f6
/*  f006bb4:	00000000 */ 	nop
/*  f006bb8:	448f4000 */ 	mtc1	$t7,$f8
/*  f006bbc:	00000000 */ 	nop
/*  f006bc0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f006bc4:	460a1081 */ 	sub.s	$f2,$f2,$f10
/*  f006bc8:	03e00008 */ 	jr	$ra
/*  f006bcc:	46001006 */ 	mov.s	$f0,$f2
);

#if VERSION < VERSION_NTSC_1_0
f32 func0f006bd0(f32 arg0)
{
	s32 ival = arg0 * 4.0f;
	f32 fval = arg0 * 4.0f - (f32)(ival / 4) * 4.0f;

	if (fval < 1.0f) {
		return fval;
	}

	if (fval < 2.0f) {
		return 1.0f;
	}

	if (fval < 3.0f) {
		return 1.0f - (fval - 2.0f);
	}

	return 0.0f;
}
#endif
