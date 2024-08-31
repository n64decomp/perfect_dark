#ifndef IN_GAME_MUSIC_H
#define IN_GAME_MUSIC_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u16 music_get_volume(void);
void music_set_volume(u16 volume);
bool music_is_track_state(s32 tracktype, s32 state);
void music_queue_start_event(u32 tracktype, u32 tracknum, f32 arg2, u16 volume);
void music_queue_stop_event(s32 tracktype);
void music_queue_fade_event(s32 tracktype, f32 arg1, bool keepafterfade);
void music_reset(void);
void music_queue_stop_all_event(void);
void music_start_primary(f32 arg0);
void music_start_track_as_menu(s32 tracknum);
void music_set_stage_and_start_music(s32 stagenum);
void music_set_stage(s32 stagenum);
void music_stop(void);
void music_activate_nrg(void);
void music_deactivate_nrg(void);
void music_start_menu(void);
void music_end_menu(void);
void music_start_solo_death(void);
void music_start_mp_death(void);
void music_end_death(void);
void music_play_track_isolated(s32 tracknum);
void music_play_default_tracks(void);
void music_start_temporary_primary(s32 tracknum);
void music_start_cutscene(s32 tracknum);
void music_end_cutscene(void);
void music_start_temporary_ambient(s32 tracknum);
void music_end_temporary_ambient(void);
void music_set_x_reason(s32 reason, u32 minsecs, u32 maxsecs);
void music_unset_x_reason(s32 reason);
void music_tick_ambient(void);

#endif
