#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_16cfa0.h"

s32 optionsGetControlMode(s32 optionsindex)
{
	return g_Options[optionsindex].controlmode;
}

void optionsSetControlMode(s32 optionsindex, s32 mode)
{
	g_Options[optionsindex].controlmode = mode;
}

s32 optionsGetUnk45(s32 optionsindex)
{
	return g_Options[optionsindex].unk45;
}

s32 optionsGetUnk46(s32 optionsindex)
{
	return g_Options[optionsindex].unk46;
}

s32 optionsGetForwardPitch(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_FORWARDPITCH) != 0;
}

s32 optionsGetAutoAim(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_AUTOAIM) != 0;
}

s32 optionsGetLookAhead(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_LOOKAHEAD) != 0;
}

s32 optionsGetAimControl(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_AIMCONTROL) != 0;
}

s32 optionsGetSightOnScreen(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_SIGHTONSCREEN) != 0;
}

s32 optionsGetAmmoOnScreen(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_AMMOONSCREEN) != 0;
}

s32 optionsGetShowGunFunction(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_SHOWGUNFUNCTION) != 0;
}

s32 optionsGetAlwaysShowTarget(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_ALWAYSSHOWTARGET) != 0;
}

s32 optionsGetShowZoomRange(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_SHOWZOOMRANGE) != 0;
}

s32 optionsGetPaintball(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_PAINTBALL) != 0;
}

s32 optionsGetShowMissionTime(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_SHOWMISSIONTIME) != 0;
}

u8 optionsGetInGameSubtitles(void)
{
	return g_InGameSubtitles;
}

u8 optionsGetCutsceneSubtitles(void)
{
	return g_CutsceneSubtitles;
}

s32 optionsGetHeadRoll(s32 optionsindex)
{
	return (g_Options[optionsindex].booleans & OPTION_HEADROLL) != 0;
}

void optionsSetForwardPitch(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_FORWARDPITCH;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_FORWARDPITCH;
	}
}

void optionsSetAutoAim(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_AUTOAIM;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_AUTOAIM;
	}
}

void optionsSetLookAhead(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_LOOKAHEAD;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_LOOKAHEAD;
	}
}

void optionsSetAimControl(s32 optionsindex, s32 index)
{
	if (index) {
		g_Options[optionsindex].booleans |= OPTION_AIMCONTROL;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_AIMCONTROL;
	}
}

void optionsSetSightOnScreen(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_SIGHTONSCREEN;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_SIGHTONSCREEN;
	}
}

void optionsSetAmmoOnScreen(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_AMMOONSCREEN;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_AMMOONSCREEN;
	}
}

void optionsSetShowGunFunction(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_SHOWGUNFUNCTION;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_SHOWGUNFUNCTION;
	}
}

void optionsSetAlwaysShowTarget(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_ALWAYSSHOWTARGET;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_ALWAYSSHOWTARGET;
	}
}

void optionsSetShowZoomRange(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_SHOWZOOMRANGE;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_SHOWZOOMRANGE;
	}
}

void optionsSetPaintball(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_PAINTBALL;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_PAINTBALL;
	}
}

void optionsSetShowMissionTime(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_SHOWMISSIONTIME;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_SHOWMISSIONTIME;
	}
}

void optionsSetInGameSubtitles(s32 enable)
{
	g_InGameSubtitles = enable;
}

void optionsSetCutsceneSubtitles(s32 enable)
{
	g_CutsceneSubtitles = enable;
}

void optionsSetHeadRoll(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].booleans |= OPTION_HEADROLL;
	} else {
		g_Options[optionsindex].booleans &= ~OPTION_HEADROLL;
	}
}

s32 optionsGetEffectiveScreenSize(void)
{
	if (var80090af0 == 1) {
		return SCREENSIZE_FULL;
	}

	if (var800a19c4 == 13) {
		g_MenuStackDepth = 0;

		if (g_MenuStack[g_MenuStackDepth].unk00 && var8009dfc0) {
			return SCREENSIZE_FULL;
		}
	}

	if (g_MenuStack[g_MenuStackDepth].unk00 && (
				g_MenuStack[g_MenuStackDepth].unk00->dialog == &menudialog_control4 ||
				g_MenuStack[g_MenuStackDepth].unk00->dialog == &menudialog_control3 ||
				g_MenuStack[g_MenuStackDepth].unk00->dialog == &g_ControlStyleSingleMenuDialog)) {
		return SCREENSIZE_FULL;
	}

	if ((g_Vars.players[0] ? 1 : 0) +
			(g_Vars.players[1] ? 1 : 0) +
			(g_Vars.players[2] ? 1 : 0) +
			(g_Vars.players[3] ? 1 : 0) >= 2 ||
			var800a19c4 == 3) {
		return SCREENSIZE_FULL;
	}

	return g_ScreenSize;
}

s32 optionsGetScreenSize(void)
{
	return g_ScreenSize;
}

void optionsSetScreenSize(s32 size)
{
	g_ScreenSize = size;
}

s32 optionsGetScreenRatio(void)
{
	return g_ScreenRatio;
}

void optionsSetScreenRatio(s32 ratio)
{
	g_ScreenRatio = ratio;
}

u8 optionsGetScreenSplit(void)
{
	return g_ScreenSplit;
}

void optionsSetScreenSplit(u8 split)
{
	g_ScreenSplit = split;
}

s32 optionsGetMusicVolume(void)
{
	return func0f16cfa0();
}

void optionsSetMusicVolume(u16 volume)
{
	func0f16cfe8(volume);
}
