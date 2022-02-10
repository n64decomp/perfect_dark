#include <ultra64.h>
#include "constants.h"
#include "game/game_097a50.h"
#include "game/game_097aa0.h"
#include "bss.h"
#include "data.h"
#include "types.h"

f32 func0f097aa0(f32 arg0)
{
	f32 f16;
	f32 f20;
	f32 f18;
	f32 f0 = (arg0 - 1) / (arg0 + 1);
	f32 f2 = f0;
	f32 f14 = f0 * f0;

	f16 = 0;
	f18 = 1;

	do {
		f2 *= f14;
		f20 = f0 / f18;
		f16 += f20;
		f18 += 2;
	} while (f20 != 0.0f);

	return f16 + f16;
}

f32 func0f097b10(f32 arg0, f32 arg1)
{
	return func0f097a50(func0f097aa0(arg0) * arg1);
}

void func0f097b40(f32 *a, f32 *b, f32 *dst)
{
	dst[0] = b[0] * a[0];
	dst[1] = b[1] * a[1];
}

void func0f097b64(f32 *a, f32 *b, f32 scale, f32 *dst)
{
	dst[0] = (b[0] - a[0]) * scale + a[0];
	dst[1] = (b[1] - a[1]) * scale + a[1];
}
