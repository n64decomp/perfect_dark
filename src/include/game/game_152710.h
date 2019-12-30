#ifndef IN_GAME_GAME_152710_H
#define IN_GAME_GAME_152710_H
#include <ultra64.h>
#include "types.h"

u32 optionsGetControlMode(void);
u32 optionsSetControlMode(void);
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
u32 optionsGetInGameSubtitles(void);
u32 optionsGetCutsceneSubtitles(void);
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
u32 optionsSetInGameSubtitles(void);
u32 optionsSetCutsceneSubtitles(void);
void optionsSetHeadRoll(s32 optionsindex, bool enable);
u32 func0f152d80(void);
s32 optionsGetScreenSize(void);
void optionsSetScreenSize(s32 size);
s32 optionsGetScreenRatio(void);
void optionsSetScreenRatio(s32 ratio);
u8 optionsGetScreenSplit(void);
void optionsSetScreenSplit(u8 split);
s32 optionsGetMusicVolume(void);
void optionsSetMusicVolume(u16 volume);

#endif
