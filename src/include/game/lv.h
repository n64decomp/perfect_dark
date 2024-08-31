#ifndef _IN_GAME_LV_H
#define _IN_GAME_LV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 get_var80084040(void);
void lv_init(void);
void lv_reset(s32 stagenum);
Gfx *lv_render(Gfx *gdl);
s32 lv_get_slow_motion_type(void);
void lv_tick(void);
void lv_tick_player(void);
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
