#include <ultra64.h>
#include "constants.h"
#include "game/game_095320.h"
#include "game/game_096360.h"
#include "game/game_0b3350.h"
#include "game/training/training.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

void func0f096360(Mtxf *mtx)
{
	struct coord coord = {0, 0, 0};

	coord.x = random() * (1.0f / U32_MAX) * PALUPF(M_BADTAU) * 0.0078125f - PALUPF(0.024539785459638f);
	coord.y = random() * (1.0f / U32_MAX) * PALUPF(M_BADTAU) * 0.0078125f - PALUPF(0.024539785459638f);
	coord.z = random() * (1.0f / U32_MAX) * PALUPF(M_BADTAU) * 0.0078125f - PALUPF(0.024539785459638f);

	func0001648c(&coord, mtx);
}

void func0f0964b4(f32 *arg0, Mtxf *mtx)
{
	arg0[0] = random() * (1.0f / U32_MAX) * 1.6666666269302f * 4.0f - 3.3333332538605f;
	arg0[1] = random() * (1.0f / U32_MAX) * 1.6666666269302f * 4.0f;
	arg0[2] = random() * (1.0f / U32_MAX) * 1.6666666269302f * 4.0f - 3.3333332538605f;

	func0f096360(mtx);
}

void func0f0965e4(f32 *arg0, f32 *arg1, f32 arg2)
{
	f32 tmp = arg1[0] - arg2 * 0.27777779f;
	arg0[0] += arg2 * (arg1[0] + tmp) * 0.5f;
	arg1[0] = tmp;
}

void func0f096628(f32 *arg0, f32 *arg1, f32 arg2)
{
	func0f0965e4(&arg0[1], &arg1[1], arg2);

	arg0[0] += arg2 * arg1[0];
	arg0[2] += arg2 * arg1[2];
}

void func0f096698(Mtxf *arg0, Mtxf *arg1, s32 count)
{
	s32 i;

	for (i = 0; i < count; i++) {
		func00015be0(arg1, arg0);
	}
}
