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

f32 func0f006b08(f32 arg0)
{
	return sinf((arg0 * var80061630 + arg0 * var80061630) * M_PI) * 0.5f + .5f;
}

f32 func0f006b54(f32 arg0)
{
	return cosf((arg0 * var80061630 + arg0 * var80061630) * M_PI) * 0.5f + .5f;
}

f32 func0f006ba0(f32 arg0)
{
	f32 tmp = var80061630 * arg0;

	tmp -= (s32)tmp;

	return tmp;
}

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
