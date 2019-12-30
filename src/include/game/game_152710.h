#ifndef IN_GAME_GAME_152710_H
#define IN_GAME_GAME_152710_H
#include <ultra64.h>
#include "types.h"

u32 func0f152710(void);
u32 func0f15272c(void);
u32 func0f152748(void);
u32 func0f152764(void);
s32 optionsGetForwardPitch(s32 optionsindex);
s32 optionsGetAutoAim(s32 optionsindex);
s32 optionsGetLookAhead(s32 optionsindex);
s32 optionsGetAimControl(s32 optionsindex);
s32 optionsGetSightOnScreen(s32 optionsindex);
s32 optionsGetAmmoOnScreen(s32 optionsindex);
s32 optionsGetShowGunFunction(s32 optionsindex);
s32 optionsGetAlwaysShowTarget(s32 optionsindex);
s32 optionsGetShowZoomRange(s32 optionsindex);
s32 optionsGetPaintball(s32 optionsindex);
s32 optionsGetShowMissionTime(s32 optionsindex);
u32 func0f15290c(void);
u32 func0f152918(void);
s32 optionsGetHeadRoll(s32 optionsindex);

void optionsSetForwardPitch(s32 optionsindex, bool enable);
void optionsSetAutoAim(s32 optionsindex, bool enable);
void optionsSetLookAhead(s32 optionsindex, bool enable);
void optionsSetAimControl(s32 optionsindex, s32 index);
void optionsSetSightOnScreen(s32 optionsindex, bool enable);
void optionsSetAmmoOnScreen(s32 optionsindex, bool enable);
void optionsSetShowGunFunction(s32 optionsindex, bool enable);
void optionsSetAlwaysShowTarget(s32 optionsindex, bool enable);
void optionsSetShowZoomRange(s32 optionsindex, bool enable);
void optionsSetPaintball(s32 optionsindex, bool enable);
void optionsSetShowMissionTime(s32 optionsindex, bool enable);
u32 func0f152d10(void);
u32 func0f152d1c(void);
void optionsSetHeadRoll(s32 optionsindex, bool enable);
u32 func0f152d80(void);
u32 func0f152f04(void);
u32 func0f152f10(void);
u32 func0f152f1c(void);
u32 func0f152f28(void);
u32 func0f152f34(void);
u32 func0f152f40(void);
u32 func0f152f50(void);
void func0f152f70(u32 arg0);

#endif
