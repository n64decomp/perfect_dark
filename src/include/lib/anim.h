#ifndef _IN_LIB_ANIM_H
#define _IN_LIB_ANIM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void anims_init(void);
void anims_reset(void);
s32 anim_get_num_frames(s16 anim_id);
bool anim_has_frames(s16 animnum);
s32 anim_get_num_animations(void);
s32 anim_get_remapped_frame(s16 animnum, s32 frame);
bool anim_is_frame_cut_skipped(s16 animnum, s32 frame);
u8 anim_load_frame(s16 animnum, s32 framenum);
void anim_forget_frame_births(void);
void anim_load_header(s16 animnum);
void anim_get_rot_translate_scale(s32 part, bool flip, struct skeleton *skel, s16 animnum, u8 frameslot, struct coord *rot, struct coord *translate, struct coord *scale);
u16 anim_get_pos_angle_as_int(s32 part, bool flip, struct skeleton *skel, s16 animnum, s32 framenum, s16 inttranslate[3], bool use_cache);
f32 anim_get_translate_angle(s32 part, bool flip, struct skeleton *skel, s16 animnum, s32 framenum, struct coord *pos, bool arg6);
f32 anim_get_camera_value(s32 part, s16 animnum, u8 frameslot);

#endif
