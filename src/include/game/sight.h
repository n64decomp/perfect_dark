#ifndef _IN_GAME_SIGHT_H
#define _IN_GAME_SIGHT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool sight_is_prop_friendly(struct prop *prop);
bool sight_can_target_prop(struct prop *prop, s32 max);
bool sight_is_reactive_to_prop(struct prop *prop);
s32 sight_find_free_target_index(s32 max);
void func0f0d7364(void);
void sight_tick(bool sighton);
s32 sight_calculate_box_bound(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
Gfx *sight_draw_target_box(Gfx *gdl, struct trackedprop *trackedprop, s32 textid, s32 time);
Gfx *sight_draw_aimer(Gfx *gdl, s32 x, s32 y, s32 radius, s32 cornergap, u32 colour);
Gfx *sight_draw_delayed_aimer(Gfx *gdl, s32 x, s32 y, s32 radius, s32 cornergap, u32 colour);
Gfx *sight_draw_default(Gfx *gdl, bool sighton);
Gfx *sight_draw_classic(Gfx *gdl, bool sighton);
Gfx *sight_draw_type2(Gfx *gdl, bool sighton);
Gfx *sight_draw_skedar_triangle(Gfx *gdl, s32 x, s32 y, s32 dir, u32 colour);
Gfx *sight_draw_skedar(Gfx *gdl, bool sighton);
Gfx *sight_draw_zoom(Gfx *gdl, bool sighton);
Gfx *sight_draw_maian(Gfx *gdl, bool sighton);
Gfx *sight_draw_target(Gfx *gdl);
bool sight_has_target_while_aiming(s32 sight);
Gfx *sight_draw(Gfx *gdl, bool sighton, s32 sight);

#endif
