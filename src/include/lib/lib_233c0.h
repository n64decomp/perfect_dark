#ifndef _IN_LIB_LIB_233C0_H
#define _IN_LIB_LIB_233C0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func000233c0(void);
u32 func00023640(void);
void func0002373c(void);
s32 animGetNumFrames(s16 anim_id);
bool animHasFrames(s16 animnum);
s32 getNumAnimations(void);
u32 func000237e8(void);
s32 func0002384c(s32 animnum, s32 frame);
u32 func00023908(void);
bool func000239e0(s16 animnum, s32 frame);
s32 func00023ab0(s16 animnum, s32 framenum);
void func00023d0c(void);
void func00023d38(s16 animnum);
u32 func00023f50(void);
u32 func00023fe0(void);
void func00024050(s32 arg0, s32 arg1, struct modeltype *arg2, s32 animnum, u32 arg4, struct coord *arg5, struct coord *arg6, struct coord *arg7);
void func0002485c(s32 arg0, s32 arg1, struct modeltype *arg2, s16 animnum, s32 loopframe, s16 *arg5, s32 arg6);
f32 func00024b64(u32 arg0, u32 arg1, struct modeltype *arg2, s32 animnum, u32 arg4, struct coord *coord, u32 arg6);
f32 func00024c14(u32 arg0, s32 animnum, u8 arg2);

#endif
