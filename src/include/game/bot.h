#ifndef _IN_GAME_BOT_H
#define _IN_GAME_BOT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool botroom_find_pos(RoomNum room, struct coord *pos, f32 *angleptr, s32 *padnumptr, s32 *covernumptr);

bool bot_is_dizzy(struct chrdata *chr);
void bot_reset(struct chrdata *chr, u8 respawning);
void bot_spawn(struct chrdata *chr, u8 full);
void bot_spawn_all(void);
u32 add87654321(u32 value);
u32 bot_pickup_prop(struct prop *prop, struct chrdata *chr);
bool bot_test_prop_for_pickup(struct prop *prop, struct chrdata *chr);
void bot_check_pickups(struct chrdata *chr);
s32 bot_guess_crouch_pos(struct chrdata *chr);
bool bot_apply_movement(struct chrdata *chr);
bool bot_is_about_to_attack(struct chrdata *chr, bool arg1);
s32 bot_tick(struct prop *prop);
f32 bot_calculate_max_speed(struct chrdata *chr);

#if VERSION >= VERSION_NTSC_1_0
void bot_update_lateral(struct chrdata *chr, f32 *move, s32 numupdates, f32 arg3);
#else
void bot_update_lateral(struct chrdata *chr, f32 *move);
#endif

void bot_disarm(struct chrdata *chr, struct prop *attacker);
void bot_set_target(struct chrdata *chr, s32 propnum);
bool bot_is_target_invisible(struct chrdata *botchr, struct chrdata *otherchr);
bool bot_has_ground(struct chrdata *chr);
void bot_update_zero_angle(struct chrdata *chr);
bool bot_passes_peace_check(struct chrdata *botchr, struct chrdata *otherchr);
bool bot_passes_coward_check(struct chrdata *botchr, struct chrdata *otherchr);
void bot_choose_general_target(struct chrdata *chr);
void bot_schedule_reload(struct chrdata *chr, s32 handnum);
struct prop *bot_find_pickup(struct chrdata *chr, s32 criteria);
s32 bot_get_num_opponents_in_hill(struct chrdata *chr);
void bot_tick_unpaused(struct chrdata *chr);
s32 bot_is_obj_collectable(struct defaultobj *obj);
s32 bot_get_weapon_num(struct chrdata *chr);
u8 bot_get_targets_weapon_num(struct chrdata *chr);
char *bot_get_command_name(s32 command);
void bot_apply_attack(struct chrdata *chr, struct prop *prop);
void bot_apply_follow(struct chrdata *chr, struct prop *prop);
void bot_apply_protect(struct chrdata *chr, struct prop *prop);
void bot_apply_defend(struct chrdata *chr, struct coord *pos, RoomNum *room, f32 angle);
void bot_apply_hold(struct chrdata *chr, struct coord *pos, RoomNum *room, f32 angle);
void bot_apply_scenario_command(struct chrdata *chr, u32 arg1);
bool bot_can_follow(struct chrdata *leader, struct chrdata *follower);
s32 bot_find_teammate_to_follow(struct chrdata *chr, f32 range);
bool bot_can_do_critical_pickup(struct chrdata *chr);
struct prop *bot_find_default_pickup(struct chrdata *chr);
struct prop *bot_find_any_pickup(struct chrdata *chr);
s32 bot_get_team_size(struct chrdata *chr);
s32 bot_get_count_in_team_doing_command(struct chrdata *self, u32 command, bool includeself);
s32 bot_is_chrs_ctc_token_held(struct chrdata *chr);
bool bot_should_return_ctc_token(struct chrdata *chr);
s32 bot_get_num_teammates_defending_hill(struct chrdata *bot);
void bot_check_fetch(struct chrdata *chr);

#endif
