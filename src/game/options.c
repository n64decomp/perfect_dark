#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/mainmenu.h"
#include "game/music.h"
#include "game/options.h"
#include "bss.h"
#include "data.h"
#include "types.h"

u8 g_InGameSubtitles = 1;
u8 g_CutsceneSubtitles = 0;
u32 var8007fa98 = 0x00000000;
u32 var8007fa9c = 0x00000001;
u32 var8007faa0 = 0x00000000;
u32 var8007faa4 = 0x00000001;
u32 var8007faa8 = 0x00000001;
u32 var8007faac = 0x00000001;
s32 g_ScreenSize = SCREENSIZE_FULL;
s32 g_ScreenRatio = SCREENRATIO_NORMAL;
u8 g_ScreenSplit = SCREENSPLIT_HORIZONTAL;

#if VERSION < VERSION_NTSC_1_0
u16 var8008231cnb = 0x7fff;
#endif

s32 options_get_control_mode(s32 mpchrnum)
{
	return g_PlayerConfigsArray[mpchrnum].controlmode;
}

void options_set_control_mode(s32 mpchrnum, s32 mode)
{
	g_PlayerConfigsArray[mpchrnum].controlmode = mode;
}

s32 options_get_contpad_num1(s32 mpchrnum)
{
	return g_PlayerConfigsArray[mpchrnum].contpad1;
}

s32 options_get_contpad_num2(s32 mpchrnum)
{
	return g_PlayerConfigsArray[mpchrnum].contpad2;
}

s32 options_get_forward_pitch(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_FORWARDPITCH) != 0;
}

s32 options_get_autoaim(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_AUTOAIM) != 0;
}

s32 options_get_look_ahead(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_LOOKAHEAD) != 0;
}

s32 options_get_aim_control(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_AIMCONTROL) != 0;
}

s32 options_get_sight_on_screen(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SIGHTONSCREEN) != 0;
}

s32 options_get_ammo_on_screen(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_AMMOONSCREEN) != 0;
}

s32 options_get_show_gun_function(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SHOWGUNFUNCTION) != 0;
}

s32 options_get_always_show_target(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_ALWAYSSHOWTARGET) != 0;
}

s32 options_get_show_zoom_range(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SHOWZOOMRANGE) != 0;
}

s32 options_get_paintball(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_PAINTBALL) != 0;
}

s32 options_get_show_mission_time(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SHOWMISSIONTIME) != 0;
}

u8 options_get_in_game_subtitles(void)
{
	return g_InGameSubtitles;
}

u8 options_get_cutscene_subtitles(void)
{
	return g_CutsceneSubtitles;
}

s32 options_get_head_roll(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_HEADROLL) != 0;
}

void options_set_forward_pitch(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_FORWARDPITCH;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_FORWARDPITCH;
	}
}

void options_set_autoaim(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_AUTOAIM;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_AUTOAIM;
	}
}

void options_set_look_ahead(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_LOOKAHEAD;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_LOOKAHEAD;
	}
}

void options_set_aim_control(s32 mpchrnum, s32 index)
{
	if (index) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_AIMCONTROL;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_AIMCONTROL;
	}
}

void options_set_sight_on_screen(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_SIGHTONSCREEN;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_SIGHTONSCREEN;
	}
}

void options_set_ammo_on_screen(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_AMMOONSCREEN;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_AMMOONSCREEN;
	}
}

void options_set_show_gun_function(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_SHOWGUNFUNCTION;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_SHOWGUNFUNCTION;
	}
}

void options_set_always_show_target(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_ALWAYSSHOWTARGET;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_ALWAYSSHOWTARGET;
	}
}

void options_set_show_zoom_range(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_SHOWZOOMRANGE;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_SHOWZOOMRANGE;
	}
}

void options_set_paintball(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_PAINTBALL;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_PAINTBALL;
	}
}

void options_set_show_mission_time(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_SHOWMISSIONTIME;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_SHOWMISSIONTIME;
	}
}

void options_set_in_game_subtitles(s32 enable)
{
	g_InGameSubtitles = enable;
}

void options_set_cutscene_subtitles(s32 enable)
{
	g_CutsceneSubtitles = enable;
}

void options_set_head_roll(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_HEADROLL;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_HEADROLL;
	}
}

s32 options_get_effective_screen_size(void)
{
	if (IS4MB()) {
		return SCREENSIZE_FULL;
	}

	if (g_MenuData.root == MENUROOT_TRAINING) {
		g_MpPlayerNum = 0;

		if (g_Menus[g_MpPlayerNum].curdialog && var8009dfc0) {
			return SCREENSIZE_FULL;
		}
	}

	if (g_Menus[g_MpPlayerNum].curdialog) {
		if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_CiControlStylePlayer2MenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_CiControlStyleMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_SoloMissionControlStyleMenuDialog) {
			return SCREENSIZE_FULL;
		}

#if VERSION >= VERSION_JPN_FINAL
		if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_CheatsFunMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_CheatsGameplayMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_CheatsSoloWeaponsMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_CheatsClassicWeaponsMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_CheatsWeaponsMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_CheatsBuddiesMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_CheatsMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_AcceptMissionMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PreAndPostMissionBriefingMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_RetryMissionMenuDialog
				|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_NextMissionMenuDialog) {
			return SCREENSIZE_FULL;
		}
#endif
	}

	if (PLAYERCOUNT() >= 2 || g_MenuData.root == MENUROOT_MPSETUP) {
		return SCREENSIZE_FULL;
	}

	return g_ScreenSize;
}

#if VERSION >= VERSION_NTSC_1_0
s32 options_get_screen_size(void)
{
	return g_ScreenSize;
}
#endif

void options_set_screen_size(s32 size)
{
	g_ScreenSize = size;
}

s32 options_get_screen_ratio(void)
{
	return g_ScreenRatio;
}

void options_set_screen_ratio(s32 ratio)
{
	g_ScreenRatio = ratio;
}

u8 options_get_screen_split(void)
{
	return g_ScreenSplit;
}

void options_set_screen_split(u8 split)
{
	g_ScreenSplit = split;
}

u16 options_get_music_volume(void)
{
#if VERSION >= VERSION_NTSC_1_0
	return music_get_volume();
#else
	if (g_Vars.stagenum == STAGE_CREDITS) {
		return 0x7fff;
	}

	return var8008231cnb;
#endif
}

void options_set_music_volume(u16 volume)
{
#if VERSION >= VERSION_NTSC_1_0
	music_set_volume(volume);
#else
	var8008231cnb = volume;
	music_set_volume(var8008231cnb);
#endif
}
