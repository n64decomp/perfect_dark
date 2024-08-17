#ifndef IN_GAME_NBOMB_H
#define IN_GAME_NBOMB_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *func0f008558(Gfx *gdl, s32 depth);
void nbomb_reset(struct nbomb *nbomb);
s32 nbomb_calculate_alpha(struct nbomb *nbomb);
Gfx *nbomb_create_gdl(void);
Gfx *nbomb_render(Gfx *gdl, struct nbomb *nbomb, Gfx *subgdl);
void func0f0099a4(void);
void nbomb_inflict_damage(struct nbomb *nbomb);
void nbomb_tick(struct nbomb *nbomb);
void nbombs_tick(void);
Gfx *nbombs_render(Gfx *gdl);
void nbomb_create_storm(struct coord *pos, struct prop *ownerprop);
f32 gas_get_door_frac(s32 tagnum);
Gfx *nbomb_render_overlay(Gfx *gdl);
Gfx *gas_render(Gfx *gdl);

#endif
