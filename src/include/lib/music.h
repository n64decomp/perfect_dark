#ifndef _IN_LIB_MUSIC_H
#define _IN_LIB_MUSIC_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 music_handle_play_event(struct musicevent *event, s32 result);
s32 music_handle_stop_event(struct musicevent *event, s32 result);
s32 music_handle_fade_event(struct musicevent *event, s32 result);
s32 music_handle_stop_all_event(s32 result);
s32 music_handle_set_interval_event(struct musicevent *event, s32 result);
void music_tick_events(void);
void music_tick(void);

#endif
