#ifndef IN_GAME_PDOPTIONS_H
#define IN_GAME_PDOPTIONS_H
#include <ultra64.h>
#include "bss.h"
#include "data.h"
#include "types.h"

extern u8 g_InGameSubtitles;
extern u8 g_CutsceneSubtitles;
extern s32 g_ScreenSize;
extern s32 g_ScreenRatio;
extern u8 g_ScreenSplit;

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
void optionsSetHeadRoll(s32 mpchrnum, bool enable);
s32 optionsGetEffectiveScreenSize(void);

inline static void optionsSetControlMode(s32 mpchrnum, s32 mode)
{
	g_PlayerConfigsArray[mpchrnum].controlmode = mode;
}

inline static s32 optionsGetForwardPitch(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_FORWARDPITCH) != 0;
}

inline static s32 optionsGetAutoAim(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_AUTOAIM) != 0;
}

inline static s32 optionsGetLookAhead(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_LOOKAHEAD) != 0;
}

inline static s32 optionsGetAimControl(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_AIMCONTROL) != 0;
}

inline static s32 optionsGetSightOnScreen(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SIGHTONSCREEN) != 0;
}

inline static s32 optionsGetAmmoOnScreen(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_AMMOONSCREEN) != 0;
}

inline static s32 optionsGetShowGunFunction(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SHOWGUNFUNCTION) != 0;
}

inline static s32 optionsGetAlwaysShowTarget(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_ALWAYSSHOWTARGET) != 0;
}

inline static s32 optionsGetShowZoomRange(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SHOWZOOMRANGE) != 0;
}

inline static s32 optionsGetPaintball(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_PAINTBALL) != 0;
}

inline static s32 optionsGetShowMissionTime(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SHOWMISSIONTIME) != 0;
}

inline static s32 optionsGetHeadRoll(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_HEADROLL) != 0;
}

#endif
