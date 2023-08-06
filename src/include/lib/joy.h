#ifndef _IN_LIB_JOY_H
#define _IN_LIB_JOY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void joyLockCyclicPolling(void);
void joyUnlockCyclicPolling(void);
void joySetPfsPollEnabled(bool enabled);
bool joyIsPfsPollEnabled(void);
void joySetPfsPollInterval(s32 value);
void joySetDefaultPfsPollInterval(void);
s32 joyShiftPfsStates(void);
void joyRecordPfsState(u8 pfsstate);
void joyPollPfs(s32 force);
void joySetPfsTemporarilyPlugged(s8 index);
void joyInit(void);
void joyDisableTemporarily(void);
void joyReset(void);
void joy00013e84(void);
u32 joyGetConnectedControllers(void);
void joy00014238(void);
void joyDebugJoy(void);
s32 joyStartReadData(OSMesgQueue *mq);
void joyReadData(void);
void joysHandleRetrace(void);
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
bool joyIsCyclicPollingEnabled(void);

#if VERSION >= VERSION_NTSC_1_0
void joyDisableCyclicPolling(void);
void joyEnableCyclicPolling(void);
#else
void joyDisableCyclicPolling(s32 line, char *file);
void joyEnableCyclicPolling(s32 line, char *file);
#endif

void joyDestroy(void);
void joyGetContpadNumsForPlayer(s8 playernum, s32 *pad1, s32 *pad2);
void joyStopRumble(s8 device, bool disablepolling);
s32 joyGetPakState(s8 device);
s32 joyGetPakState2(s8 device);
void joysTickRumble(void);

#endif
