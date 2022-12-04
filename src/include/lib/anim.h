#ifndef _IN_LIB_ANIM_H
#define _IN_LIB_ANIM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void animsInit(void);
void animsInitTables(void);
void animsReset(void);
s32 animGetNumFrames(s16 anim_id);
bool animHasFrames(s16 animnum);
s32 animGetNumAnimations(void);
u8 *animDma(u8 *dst, u32 segoffset, u32 len);
s32 animGetRemappedFrame(s16 animnum, s32 frame);
bool animRemapFrameForLoad(s16 animnum, s32 frame, s32 *frameptr);
bool animIsFrameCutSkipped(s16 animnum, s32 frame);
u8 animLoadFrame(s16 animnum, s32 framenum);
void animForgetFrameBirths(void);
void animLoadHeader(s16 animnum);
s32 animReadBits(u8 *ptr, u8 readbitlen, u32 bitoffset);
s32 animReadSignedShort(u8 *arg0, u8 arg1, s32 arg2);
void animGetRotTranslateScale(s32 part, bool flip, struct skeleton *skel, s16 animnum, u8 frameslot, struct coord *rot, struct coord *translate, struct coord *scale);
u16 animGetPosAngleAsInt(s32 part, bool flip, struct skeleton *skel, s16 animnum, s32 framenum, s16 inttranslate[3], bool arg6);
f32 animGetTranslateAngle(s32 part, bool flip, struct skeleton *skel, s16 animnum, s32 framenum, struct coord *pos, bool arg6);
f32 animGetCameraValue(s32 part, s16 animnum, u8 frameslot);

#endif
