#ifndef _IN_LIB_LIB_13900_H
#define _IN_LIB_LIB_13900_H
#include <ultra64.h>
#include "types.h"

void func00013900(void);
void func00013938(void);
void func00013974(u32 value);
u32 func00013980(void);
void func0001398c(s32 value);
void func000139c8(void);
s32 contShiftPfsStates(void);
void contRecordPfsState(u8 pfsstate);
void contCheckPfs(s32 arg0);
void contSetPfsTemporarilyPlugged(s8 index);
void contSystemInit(void);
void contDisableTemporarily(void);
void func00013dfc(void);
void func00013e84(void);
u32 contGetConnectedControllers(void);
void contConsumeSamples(struct contdata *contdata);
void func00014238(void);
void contDebugJoy(void);
s32 contStartReadData(OSMesgQueue *mq);
void contReadData(void);
void contPoll(void);
void func00014810(bool value);
s32 contGetNumSamples(void);
s32 contGetStickXOnSample(s32 samplenum, s8 contpadnum);
s32 contGetStickYOnSample(s32 samplenum, s8 contpadnum);
s32 contGetStickYOnSampleIndex(s32 samplenum, s8 contpadnum);
u16 contGetButtonsOnSample(s32 samplenum, s8 contpadnum, u16 mask);
u16 contGetButtonsPressedOnSample(s32 samplenum, s8 contpadnum, u16 mask);
s32 contCountButtonsOnSpecificSamples(u32 *arg0, s8 contpadnum, u16 mask);
s8 contGetStickX(s8 contpadnum);
s8 contGetStickY(s8 contpadnum);
u16 contGetButtons(s8 contpadnum, u16 mask);
u16 contGetButtonsPressedThisFrame(s8 contpadnum, u16 mask);
s32 func000150c4(void);
void func000150e8(void);
void func00015144(void);
void func0001519c(void);
void func000152d0(s8 playernum, s32 *arg1, s32 *arg2);
void func000153c4(s8 arg0, s32 arg1);
s32 func000155b4(s8 index);
s32 func000155f4(s8 index);
void func0001561c(void);

#endif
