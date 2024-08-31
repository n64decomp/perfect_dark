#ifndef _IN_GAME_BOT_H
#define _IN_GAME_BOT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool botroom_find_pos(RoomNum room, struct coord *pos, f32 *angleptr, s32 *padnumptr, s32 *covernumptr);

void bot_spawn(struct chrdata *chr, u8 full);
void bot_spawn_all(void);
u32 bot_pickup_prop(struct prop *prop, struct chrdata *chr);
bool bot_test_prop_for_pickup(struct prop *prop, struct chrdata *chr);
s32 bot_guess_crouch_pos(struct chrdata *chr);
s32 bot_tick(struct prop *prop);
f32 bot_calculate_max_speed(struct chrdata *chr);

#if VERSION >= VERSION_NTSC_1_0
void bot_update_lateral(struct chrdata *chr, f32 *move, s32 numupdates, f32 arg3);
#else
void bot_update_lateral(struct chrdata *chr, f32 *move);
#endif

void bot_disarm(struct chrdata *chr, struct prop *attacker);
bool bot_is_target_invisible(struct chrdata *botchr, struct chrdata *otherchr);
bool bot_has_ground(struct chrdata *chr);
void bot_tick_unpaused(struct chrdata *chr);
u8 bot_get_targets_weapon_num(struct chrdata *chr);
char *bot_get_command_name(s32 command);
void bot_apply_attack(struct chrdata *chr, struct prop *prop);
void bot_apply_follow(struct chrdata *chr, struct prop *prop);
void bot_apply_protect(struct chrdata *chr, struct prop *prop);
void bot_apply_defend(struct chrdata *chr, struct coord *pos, RoomNum *room, f32 angle);
void bot_apply_hold(struct chrdata *chr, struct coord *pos, RoomNum *room, f32 angle);
void bot_apply_scenario_command(struct chrdata *chr, u32 arg1);
void bot_check_fetch(struct chrdata *chr);

#endif
