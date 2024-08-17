#ifndef IN_GAME_BOTACT_H
#define IN_GAME_BOTACT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 botact_get_ammo_type_by_function(s32 weaponnum, s32 funcnum);
s32 botact_get_clip_capacity_by_function(s32 weaponnum, u32 funcnum);
void botact_reload(struct chrdata *chr, s32 handnum, bool withsound);
s32 botact_get_ammo_quantity_by_weapon(struct aibot *aibot, s32 weaponnum, s32 funcnum, bool include_equipped);
s32 botact_get_ammo_quantity_by_type(struct aibot *aibot, s32 ammotype, bool include_equipped);
s32 botact_try_remove_ammo_from_reserve(struct aibot *aibot, s32 weaponnum, s32 funcnum, s32 qty);
void botact_give_ammo_by_weapon(struct aibot *aibot, s32 weaponnum, s32 funcnum, s32 qty);
void botact_give_ammo_by_type(struct aibot *aibot, u32 ammotype, s32 quantity);
bool botact_shoot_farsight(struct chrdata *chr, s32 arg1, struct coord *arg2, struct coord *arg3);
bool botact_is_weapon_throwable(s32 weaponnum, bool is_secondary);
u32 botact_get_projectile_throw_interval(u32 weapon);
s32 botact_get_weapon_by_ammo_type(s32 ammotype);
void botact_throw(struct chrdata *chr);
s32 botact_get_shoot_interval60(s32 weaponnum, s32 funcnum);
bool botact_find_rocket_route(struct chrdata *chr, struct coord *frompos, struct coord *topos, RoomNum *fromrooms, RoomNum *torooms, struct projectile *projectile);
void botact_get_rocket_next_step_pos(u16 padnum, struct coord *pos);
void botact_create_slayer_rocket(struct chrdata *chr);

#endif
