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
void joyInit(void);
void joyDisableTemporarily(void);
void joyReset(void);
u32 joyGetConnectedControllers(void);
void joyConsumeSamples(struct joydata *joydata);
void joyDebugJoy(void);
s32 joyStartReadData(OSMesgQueue *mq);
void joysTick(void);
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
void joyDisableCyclicPolling(void);
void joyEnableCyclicPolling(void);
void joyDestroy(void);
void joyGetContpadNumsForPlayer(s8 playernum, s32 *pad1, s32 *pad2);
void joyStopRumble(s8 device, bool disablepolling);
s32 joy000155b4(s8 device);
s32 joy000155f4(s8 device);

#endif
