#ifndef _IN_GAME_LV_H
#define _IN_GAME_LV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 get_var80084040(void);
void lv_init(void);
void lv_reset_misc_sfx(void);
s32 lv_get_misc_sfx_index(u32 arg0);
void lv_set_misc_sfx_state(u32 type, bool play);
void lv_update_misc_sfx(void);
void lv_reset(s32 stagenum);
Gfx *lv_render_fade(Gfx *gdl);
void lv_fade_reset(void);
bool lv_update_tracked_prop(struct trackedprop *trackedprop, s32 index);
void lv_find_threats_for_prop(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *param_5);
void func0f168f24(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *distances);
void lv_find_threats(void);
Gfx *lv_render(Gfx *gdl);
void lv_update_solo_handicaps(void);
s32 sub54321(s32 value);
void lv_update_cutscene_time(void);
s32 lv_get_slow_motion_type(void);
void lv_tick(void);
void lv_tick_player(void);
void lv_check_pause_state_changed(void);
void lv_set_paused(bool paused);
void lv_configure_fade(u32 color, s16 num_frames);
bool lv_is_fade_active(void);
void lv_stop(void);
bool lv_is_paused(void);
s32 lv_get_difficulty(void);
void lv_set_difficulty(s32 difficulty);
void lv_set_mp_time_limit60(u32 limit);
void lv_set_mp_score_limit(u32 limit);
void lv_set_mp_team_score_limit(u32 limit);
f32 lv_get_stage_time_in_seconds(void);
s32 lv_get_stage_time60(void);

#endif
