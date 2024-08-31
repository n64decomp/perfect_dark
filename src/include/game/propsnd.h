#ifndef IN_GAME_PROPSND_H
#define IN_GAME_PROPSND_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void ps_reset(void);

void ps_stop(void);

bool ps_prop_has_sound_with_context(struct prop *prop, s32 type);
void ps_stop_sound(struct prop *prop, s32 type, u16 flags);
s32 ps_calculate_volume_from_distance(f32 playerdist, f32 dist1, f32 dist2, f32 dist3, s32 fullvolume);
s32 ps_get_volume(s32 channelnum);
void ps_create_if_not_dupe(struct prop *prop, s16 soundnum, s32 type);
s32 ps_get_subtitle_opacity(s32 channelnum);
void ps_tick(void);
void ps_set_pitch(struct prop *prop, f32 targetpitch, s32 changespeed);
void ps_set_volume(struct prop *prop, s32 vol);
s16 ps_create(struct pschannel *channel, struct prop *prop, s16 soundnum, s16 padnum, s32 vol, u16 flags, u16 flags2, s32 type, struct coord *pos, f32 pitch, RoomNum *rooms, s32 room, f32 dist1, f32 dist2, f32 dist3);
s32 ps_play_from_prop(s32 channelnum, s16 soundnum, s32 vol, struct prop *prop, s16 type, u16 flags);
void ps_mute_channel(s32 channelnum);
bool ps_is_channel_free(s32 channelnum);
void ps_modify(s32 channelnum, s32 arg1, s16 padnum, struct prop *prop, s32 volchangetimer60, s32 dist2, s32 dist3, u16 flags);
void ps_get_theoretical_vol_pan(struct coord *pos, RoomNum *rooms, s16 soundnum, s32 *vol, s32 *pan);
void ps_apply_vol_pan(struct sndstate *handle, struct coord *pos, f32 dist1, f32 dist2, f32 dist3, RoomNum *rooms, s16 soundnum, s32 arg7, f32 *distanceptr);
s32 ps_get_random_spark_sound(void);
s32 ps_get_duration60(s32 channelnum);

#endif
