#include <ultra64.h>
#include "constants.h"
#include "game/objectives.h"
#include "game/game_096360.h"
#include "game/tex.h"
#include "game/training.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

void mtxLoadRandomRotation(Mtxf *mtx)
{
	struct coord coord = {0, 0, 0};

	coord.x = RANDOMFRAC() * PALUPF(M_BADTAU) * 0.0078125f - PALUPF(0.024539785459638f);
	coord.y = RANDOMFRAC() * PALUPF(M_BADTAU) * 0.0078125f - PALUPF(0.024539785459638f);
	coord.z = RANDOMFRAC() * PALUPF(M_BADTAU) * 0.0078125f - PALUPF(0.024539785459638f);

	mtx4LoadRotation(&coord, mtx);
}

void func0f0964b4(struct coord *coord, Mtxf *mtx)
{
	coord->x = RANDOMFRAC() * 1.6666666269302f * 4.0f - 3.3333332538605f;
	coord->y = RANDOMFRAC() * 1.6666666269302f * 4.0f;
	coord->z = RANDOMFRAC() * 1.6666666269302f * 4.0f - 3.3333332538605f;

	mtxLoadRandomRotation(mtx);
}

void func0f0965e4(f32 *arg0, f32 *arg1, f32 arg2)
{
	f32 tmp = arg1[0] - arg2 * 0.27777779f;
	arg0[0] += arg2 * (arg1[0] + tmp) * 0.5f;
	arg1[0] = tmp;
}

void func0f096698(Mtxf *arg0, Mtxf *arg1, s32 count)
{
	s32 i;

	for (i = 0; i < count; i++) {
		mtx00015be0(arg1, arg0);
	}
}
