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

void projectile_load_random_rotation(Mtxf *mtx)
{
	struct coord rot = {0, 0, 0};

	rot.x = RANDOMFRAC() * PALUPF(M_BADTAU) * (1.0f / 128.0f) - PALUPF(M_BADPI / 128.0f);
	rot.y = RANDOMFRAC() * PALUPF(M_BADTAU) * (1.0f / 128.0f) - PALUPF(M_BADPI / 128.0f);
	rot.z = RANDOMFRAC() * PALUPF(M_BADTAU) * (1.0f / 128.0f) - PALUPF(M_BADPI / 128.0f);

	mtx4_load_rotation(&rot, mtx);
}

void projectile_load_random_speed_rotation(struct coord *speed, Mtxf *mtx)
{
	speed->x = RANDOMFRAC() * (10.0f / 6.0f) * 4.0f - (10.0f / 3.0f);
	speed->y = RANDOMFRAC() * (10.0f / 6.0f) * 4.0f;
	speed->z = RANDOMFRAC() * (10.0f / 6.0f) * 4.0f - (10.0f / 3.0f);

	projectile_load_random_rotation(mtx);
}

void projectile_update_fall(f32 *yincrement, f32 *speedptr, f32 lvupdate60)
{
	f32 speed = *speedptr - lvupdate60 * 0.27777779f;
	*yincrement += lvupdate60 * (*speedptr + speed) * 0.5f;
	*speedptr = speed;
}

void projectile_update_3d(f32 *increment, f32 *speed, f32 lvupdate60)
{
	projectile_update_fall(&increment[1], &speed[1], lvupdate60);

	increment[0] += lvupdate60 * speed[0];
	increment[2] += lvupdate60 * speed[2];
}

void projectile_update_matrix(Mtxf *arg0, Mtxf *arg1, s32 lvupdate240)
{
	s32 i;

	for (i = 0; i < lvupdate240; i++) {
		mtx00015be0(arg1, arg0);
	}
}
