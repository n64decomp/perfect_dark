#ifndef IN_GAME_PROPSND_H
#define IN_GAME_PROPSND_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void propsndReset(void);

void propsndStop(void);

bool func0f092610(struct prop *prop, s32 arg1);
void func0f0926bc(struct prop *prop, s32 arg1, u16 arg2);
s32 channelGetUnk06(s32 channelnum);
void propsnd0f09294c(struct prop *prop, s16 soundnum, s32 arg2);
void propsndPrintChannel(struct audiochannel *channel);
s32 propsndGetSubtitleOpacity(s32 channelnum);
void propsndTick(void);
void func0f093630(struct prop *prop, f32 arg1, s32 arg2);
void func0f093790(struct prop *prop, s32 arg1);
s16 propsnd0f0939f8(struct audiochannel *channel, struct prop *prop, s16 soundnum, s16 padnum, s32 arg4, u16 flags, u16 flags2, s32 arg7, struct coord *pos, f32 arg9, s16 *rooms, s32 room, f32 arg12, f32 arg13, f32 arg14);
void audioMuteChannel(s32 channelnum);
bool audioIsChannelIdle(s32 channelnum);
void audioPlayFromProp2(s32 channelnum, s32 arg1, s16 padnum, struct prop *prop, s32 arg4, s32 arg5, s32 arg6, u16 arg7);
void propsnd0f094ef4(struct coord *pos, s16 *rooms, s16 soundnum, s32 *arg3, s32 *arg4);
void func0f09505c(struct sndstate *handle, struct coord *pos, f32 arg2, f32 arg3, f32 arg4, s16 *rooms, s16 soundnum, s32 arg7, f32 *arg8);
s32 propsndGetRandomSparkSound(void);
s32 propsndGetDuration60(s32 channelnum);

#endif
