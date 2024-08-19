#ifndef IN_GAME_PDOPTIONS_H
#define IN_GAME_PDOPTIONS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 options_get_control_mode(s32 mpchrnum);
void options_set_control_mode(s32 mpchrnum, s32 mode);
s32 options_get_contpad_num1(s32 mpchrnum);
s32 options_get_contpad_num2(s32 mpchrnum);
s32 options_get_forward_pitch(s32 mpchrnum);
s32 options_get_autoaim(s32 mpchrnum);
s32 options_get_look_ahead(s32 mpchrnum);
s32 options_get_aim_control(s32 mpchrnum);
s32 options_get_sight_on_screen(s32 mpchrnum);
s32 options_get_ammo_on_screen(s32 mpchrnum);
s32 options_get_show_gun_function(s32 mpchrnum);
s32 options_get_always_show_target(s32 mpchrnum);
s32 options_get_show_zoom_range(s32 mpchrnum);
s32 options_get_paintball(s32 mpchrnum);
s32 options_get_show_mission_time(s32 mpchrnum);
u8 options_get_in_game_subtitles(void);
u8 options_get_cutscene_subtitles(void);
s32 options_get_head_roll(s32 mpchrnum);

void options_set_forward_pitch(s32 mpchrnum, bool enable);
void options_set_autoaim(s32 mpchrnum, bool enable);
void options_set_look_ahead(s32 mpchrnum, bool enable);
void options_set_aim_control(s32 mpchrnum, s32 index);
void options_set_sight_on_screen(s32 mpchrnum, bool enable);
void options_set_ammo_on_screen(s32 mpchrnum, bool enable);
void options_set_show_gun_function(s32 mpchrnum, bool enable);
void options_set_always_show_target(s32 mpchrnum, bool enable);
void options_set_show_zoom_range(s32 mpchrnum, bool enable);
void options_set_paintball(s32 mpchrnum, bool enable);
void options_set_show_mission_time(s32 mpchrnum, bool enable);
void options_set_in_game_subtitles(s32 enable);
void options_set_cutscene_subtitles(s32 enable);
void options_set_head_roll(s32 mpchrnum, bool enable);
s32 options_get_effective_screen_size(void);
s32 options_get_screen_size(void);
void options_set_screen_size(s32 size);
s32 options_get_screen_ratio(void);
void options_set_screen_ratio(s32 ratio);
u8 options_get_screen_split(void);
void options_set_screen_split(u8 split);
u16 options_get_music_volume(void);
void options_set_music_volume(u16 volume);

#endif
