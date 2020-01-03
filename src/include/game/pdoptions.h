#ifndef IN_GAME_PDOPTIONS_H
#define IN_GAME_PDOPTIONS_H
#include <ultra64.h>
#include "types.h"

s32 optionsGetControlMode(s32 mpchrnum);
void optionsSetControlMode(s32 mpchrnum, s32 mode);
s32 optionsGetUnk45(s32 mpchrnum);
s32 optionsGetUnk46(s32 mpchrnum);
s32 optionsGetForwardPitch(s32 mpchrnum);
s32 optionsGetAutoAim(s32 mpchrnum);
s32 optionsGetLookAhead(s32 mpchrnum);
s32 optionsGetAimControl(s32 mpchrnum);
s32 optionsGetSightOnScreen(s32 mpchrnum);
s32 optionsGetAmmoOnScreen(s32 mpchrnum);
s32 optionsGetShowGunFunction(s32 mpchrnum);
s32 optionsGetAlwaysShowTarget(s32 mpchrnum);
s32 optionsGetShowZoomRange(s32 mpchrnum);
s32 optionsGetPaintball(s32 mpchrnum);
s32 optionsGetShowMissionTime(s32 mpchrnum);
u8 optionsGetInGameSubtitles(void);
u8 optionsGetCutsceneSubtitles(void);
s32 optionsGetHeadRoll(s32 mpchrnum);

void optionsSetForwardPitch(s32 mpchrnum, bool enable);
void optionsSetAutoAim(s32 mpchrnum, bool enable);
void optionsSetLookAhead(s32 mpchrnum, bool enable);
void optionsSetAimControl(s32 mpchrnum, s32 index);
void optionsSetSightOnScreen(s32 mpchrnum, bool enable);
void optionsSetAmmoOnScreen(s32 mpchrnum, bool enable);
void optionsSetShowGunFunction(s32 mpchrnum, bool enable);
void optionsSetAlwaysShowTarget(s32 mpchrnum, bool enable);
void optionsSetShowZoomRange(s32 mpchrnum, bool enable);
void optionsSetPaintball(s32 mpchrnum, bool enable);
void optionsSetShowMissionTime(s32 mpchrnum, bool enable);
void optionsSetInGameSubtitles(s32 enable);
void optionsSetCutsceneSubtitles(s32 enable);
void optionsSetHeadRoll(s32 mpchrnum, bool enable);
s32 optionsGetEffectiveScreenSize(void);
s32 optionsGetScreenSize(void);
void optionsSetScreenSize(s32 size);
s32 optionsGetScreenRatio(void);
void optionsSetScreenRatio(s32 ratio);
u8 optionsGetScreenSplit(void);
void optionsSetScreenSplit(u8 split);
s32 optionsGetMusicVolume(void);
void optionsSetMusicVolume(u16 volume);

#endif
