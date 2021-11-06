#ifndef _IN_LIB_ANIM_H
#define _IN_LIB_ANIM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void animsInit(void);
void anim00023640(void);
void anim0002373c(void);
s32 animGetNumFrames(s16 anim_id);
bool animHasFrames(s16 animnum);
s32 animGetNumAnimations(void);
u32 anim000237e8(void);
s32 anim0002384c(s32 animnum, s32 frame);
u32 anim00023908(void);
bool anim000239e0(s16 animnum, s32 frame);
s32 anim00023ab0(s16 animnum, s32 framenum);
void anim00023d0c(void);
void anim00023d38(s16 animnum);
u32 anim00023f50(void);
u32 anim00023fe0(void);
void anim00024050(s32 arg0, s32 arg1, struct modeltype *arg2, s32 animnum, u32 arg4, struct coord *arg5, struct coord *arg6, struct coord *arg7);
u32 anim0002485c(s32 arg0, s32 arg1, struct modeltype *arg2, s16 animnum, s32 loopframe, s16 *arg5, s32 arg6);
f32 anim00024b64(u32 arg0, u32 arg1, struct modeltype *arg2, s16 animnum, u32 arg4, struct coord *coord, u32 arg6);
f32 anim00024c14(u32 arg0, s32 animnum, u8 arg2);

#endif
