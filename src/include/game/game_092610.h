#ifndef IN_GAME_GAME_092610_H
#define IN_GAME_GAME_092610_H
#include <ultra64.h>
#include "types.h"

bool func0f092610(struct prop *prop, s32 arg1);
void func0f0926bc(struct prop *prop, s32 arg1, u16 arg2);
s32 func0f0927d4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
s32 channelGetUnk06(s32 channelnum);
u32 func0f09294c(void);
void func0f092a98(s32 channelnum);
u32 func0f092b50(void);
u32 func0f092b7c(void);
void func0f092c04(s32 channelnum);
u32 func0f093508(void);
void func0f093630(struct prop *prop, f32 arg1, s32 arg2);
void func0f093790(struct prop *prop, s32 arg1);
void func0f0938ec(struct prop *prop);
s16 func0f0939f8(struct audiochannel *channel, struct prop *prop, s16 soundnum, s16 padnum, s32 arg4, u16 flags, u16 flags2, s32 arg7, struct coord *pos, f32 arg9, s16 *rooms, s32 room, f32 arg12, f32 arg13, f32 arg14);
void audioMuteChannel(s32 channelnum);
bool audioIsChannelIdle(s32 channelnum);
void audioPlayFromProp2(s32 channelnum, s32 soundnum, s16 padnum, struct prop *prop, s32 arg4, s32 arg5, s32 arg6, u16 arg7);
u32 func0f0946b0(void);
u32 func0f094940(void);
u32 func0f094b1c(void);
u32 func0f094d78(void);
u32 func0f094ef4(void);
u32 func0f09505c(void);
u32 func0f095200(void);
s32 func0f095278(s32 channelnum);

#endif
