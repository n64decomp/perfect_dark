#ifndef _IN_LIB_JOY_H
#define _IN_LIB_JOY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void joy00013900(void);
void joy00013938(void);
void joy00013974(u32 value);
u32 joy00013980(void);
void joy0001398c(s32 value);
void joy000139c8(void);
s32 joyShiftPfsStates(void);
void joyRecordPfsState(u8 pfsstate);
void joyCheckPfs(s32 arg0);
void joySetPfsTemporarilyPlugged(s8 index);
void joySystemInit(void);
void joyDisableTemporarily(void);
void joy00013dfc(void);
void joy00013e84(void);
u32 joyGetConnectedControllers(void);
void joyConsumeSamples(struct joydata *joydata);
void joy00014238(void);
void joyDebugJoy(void);
s32 joyStartReadData(OSMesgQueue *mq);
void joyReadData(void);
void joyPoll(void);
void joy00014810(bool value);
s32 joyGetNumSamples(void);
s32 joyGetStickXOnSample(s32 samplenum, s8 contpadnum);
s32 joyGetStickYOnSample(s32 samplenum, s8 contpadnum);
s32 joyGetStickYOnSampleIndex(s32 samplenum, s8 contpadnum);
u16 joyGetButtonsOnSample(s32 samplenum, s8 contpadnum, u16 mask);
u16 joyGetButtonsPressedOnSample(s32 samplenum, s8 contpadnum, u16 mask);
s32 joyCountButtonsOnSpecificSamples(u32 *arg0, s8 contpadnum, u16 mask);
s8 joyGetStickX(s8 contpadnum);
s8 joyGetStickY(s8 contpadnum);
u16 joyGetButtons(s8 contpadnum, u16 mask);
u16 joyGetButtonsPressedThisFrame(s8 contpadnum, u16 mask);
s32 joy000150c4(void);

#if VERSION >= VERSION_NTSC_1_0
void joy000150e8(void);
void joy00015144(void);
#else
void joy000150e8(s32 line, char *file);
void joy00015144(s32 line, char *file);
#endif

void joy0001519c(void);
void joy000152d0(s8 playernum, s32 *arg1, s32 *arg2);
void joy000153c4(s8 arg0, s32 arg1);
s32 joy000155b4(s8 index);
s32 joy000155f4(s8 index);
void joy0001561c(void);

#endif
