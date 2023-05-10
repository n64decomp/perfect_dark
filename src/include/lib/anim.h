#ifndef _IN_LIB_ANIM_H
#define _IN_LIB_ANIM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void animsInit(void);
void animsReset(void);
s32 animGetNumAnimations(void);
s32 anim0002384c(s16 animnum, s32 frame);
bool anim000239e0(s16 animnum, s32 frame);
u8 anim00023ab0(s16 animnum, s32 framenum);
void anim00023d0c(void);
void anim00023d38(s16 animnum);
void anim00024050(s32 arg0, bool flip, struct skeleton *skel, s16 animnum, u8 arg4, struct coord *arg5, struct coord *arg6, struct coord *arg7);
u16 anim0002485c(s32 arg0, bool arg1, struct skeleton *skel, s16 animnum, s32 loopframe, s16 *arg5, s32 arg6);
f32 anim00024b64(u32 arg0, u32 arg1, struct skeleton *skel, s16 animnum, u32 arg4, struct coord *coord, u32 arg6);
f32 anim00024c14(s32 arg0, s16 animnum, u8 arg2);

static inline s32 animGetNumFrames(s16 animnum)
{
	return g_Anims[animnum].numframes;
}

static inline bool animHasFrames(s16 animnum)
{
	return animnum < g_NumAnimations && g_Anims[animnum].numframes > 0;
}

#endif
