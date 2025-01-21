#ifndef _IN_LIB_LIB_317F0_H
#define _IN_LIB_LIB_317F0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void sndp_set_addref_callback(void *fn);
void sndp_set_removeref_callback(void *fn);
s32 sndp_get_state(struct sndstate *handle);
struct sndstate *sndp_play_sound(s32 arg0, s16 soundnum, u16 vol, ALPan pan, f32 pitch, u8 fxmix, u8 fxbus, struct sndstate **handleptr);
void sndp_stop_sound(struct sndstate *handle);
void sndp_cleanup(void);
void sndp_stop_all(void);
void sndp_post_event(struct sndstate *handle, s16 type, s32 data);
u16 sndp_get_volume_entry(u8 index);
struct sndstate *sndp_get_head_state(void);
ALMicroTime sndp_get_curtime(void);
void sndp_set_volume_entry(u8 index, u16 volume);

#endif
