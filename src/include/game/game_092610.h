#ifndef IN_GAME_GAME_092610_H
#define IN_GAME_GAME_092610_H
#include <ultra64.h>
#include "types.h"

bool func0f092610(s32 arg0, s32 arg1);
void func0f0926bc(struct prop *prop, s32 arg1, u16 arg2);
s32 func0f0927d4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4);
s32 func0f092914(s32 arg0);
u32 func0f09294c(void);
u32 func0f092a98(void);
u32 func0f092b50(void);
u32 func0f092b7c(void);
u32 func0f092c04(void);
u32 func0f093508(void);
u32 func0f093630(void);
u32 func0f093790(void);
u32 func0f0938ec(void);
u32 func0f0939f8(void *arg0, struct prop *prop, s16 sound, s32 padnum, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, f32 arg9, s32 arg10, s32 arg11, f32 arg12, f32 arg13, f32 arg14);
void audioMuteChannel(s32 channel);
u32 audioIfChannelIdle(s32 channel);
bool audioPlayFromProp2(s8 channel_id, s32 audio_id, s32 volumemaybe, struct prop *prop, u32 arg4, s32 arg5, s32 arg6, s32 arg7);
u32 func0f0946b0(void);
u32 func0f094940(void);
u32 func0f094b1c(void);
u32 func0f094d78(void);
u32 func0f094ef4(void);
u32 func0f09505c(void);
u32 func0f095200(void);
u32 func0f095278(void);

#endif
