#ifndef _IN_GAME_PROJECTILE_H
#define _IN_GAME_PROJECTILE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void projectile_load_random_rotation(Mtxf *mtx);
void projectile_load_random_speed_rotation(struct coord *speed, Mtxf *mtx);
void projectile_update_fall(f32 *yincrement, f32 *speed, f32 lvupdate60);
void projectile_update_matrix(Mtxf *arg0, Mtxf *arg1, s32 lvupdate240);

#endif
