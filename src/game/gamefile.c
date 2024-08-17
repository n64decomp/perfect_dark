#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/bg.h"
#include "game/challenge.h"
#include "game/lang.h"
#include "game/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/options.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/fault.h"
#include "lib/snd.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

u8 *gamefile_get_flags(void)
{
	return g_GameFile.flags;
}

void gamefile_set_flag(u32 value)
{
	pak_set_bitflag(value, g_GameFile.flags, true);
}

void gamefile_unset_flag(u32 value)
{
	pak_set_bitflag(value, g_GameFile.flags, false);
}

u32 gamefile_has_flag(u32 value)
{
	return pak_has_bitflag(value, g_GameFile.flags);
}

void gamefile_print_flags(void)
{
	s32 i;

	for (i = 0x23; i != 0x4f; i++) {
		osSyncPrintf("Flag %d = %s", i,
				pak_has_bitflag(i, g_GameFile.flags) ? "TRUE" : "FALSE");
	}
}

void gamefile_apply_options(struct gamefile *file)
{
	s32 player1 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 0 : 4;
	s32 player2 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 1 : 5;

	options_set_forward_pitch(player1, pak_has_bitflag(GAMEFILEFLAG_P1_FORWARDPITCH, file->flags));
	options_set_auto_aim(player1, pak_has_bitflag(GAMEFILEFLAG_P1_AUTOAIM, file->flags));
	options_set_aim_control(player1, pak_has_bitflag(GAMEFILEFLAG_P1_AIMCONTROL, file->flags));
	options_set_sight_on_screen(player1, pak_has_bitflag(GAMEFILEFLAG_P1_SIGHTONSCREEN, file->flags));
	options_set_look_ahead(player1, pak_has_bitflag(GAMEFILEFLAG_P1_LOOKAHEAD, file->flags));
	options_set_ammo_on_screen(player1, pak_has_bitflag(GAMEFILEFLAG_P1_AMMOONSCREEN, file->flags));
	options_set_head_roll(player1, pak_has_bitflag(GAMEFILEFLAG_P1_HEADROLL, file->flags));
	options_set_show_gun_function(player1, pak_has_bitflag(GAMEFILEFLAG_P1_SHOWGUNFUNCTION, file->flags));
	options_set_always_show_target(player1, pak_has_bitflag(GAMEFILEFLAG_P1_ALWAYSSHOWTARGET, file->flags));
	options_set_show_zoom_range(player1, pak_has_bitflag(GAMEFILEFLAG_P1_SHOWZOOMRANGE, file->flags));
	options_set_show_mission_time(player1, pak_has_bitflag(GAMEFILEFLAG_P1_SHOWMISSIONTIME, file->flags));
	options_set_paintball(player1, pak_has_bitflag(GAMEFILEFLAG_P1_PAINTBALL, file->flags));

	options_set_forward_pitch(player2, pak_has_bitflag(GAMEFILEFLAG_P2_FORWARDPITCH, file->flags));
	options_set_auto_aim(player2, pak_has_bitflag(GAMEFILEFLAG_P2_AUTOAIM, file->flags));
	options_set_aim_control(player2, pak_has_bitflag(GAMEFILEFLAG_P2_AIMCONTROL, file->flags));
	options_set_sight_on_screen(player2, pak_has_bitflag(GAMEFILEFLAG_P2_SIGHTONSCREEN, file->flags));
	options_set_look_ahead(player2, pak_has_bitflag(GAMEFILEFLAG_P2_LOOKAHEAD, file->flags));
	options_set_ammo_on_screen(player2, pak_has_bitflag(GAMEFILEFLAG_P2_AMMOONSCREEN, file->flags));
	options_set_head_roll(player2, pak_has_bitflag(GAMEFILEFLAG_P2_HEADROLL, file->flags));
	options_set_show_gun_function(player2, pak_has_bitflag(GAMEFILEFLAG_P2_SHOWGUNFUNCTION, file->flags));
	options_set_always_show_target(player2, pak_has_bitflag(GAMEFILEFLAG_P2_ALWAYSSHOWTARGET, file->flags));
	options_set_show_zoom_range(player2, pak_has_bitflag(GAMEFILEFLAG_P2_SHOWZOOMRANGE, file->flags));
	options_set_show_mission_time(player2, pak_has_bitflag(GAMEFILEFLAG_P2_SHOWMISSIONTIME, file->flags));
	options_set_paintball(player2, pak_has_bitflag(GAMEFILEFLAG_P2_PAINTBALL, file->flags));

	options_set_in_game_subtitles(pak_has_bitflag(GAMEFILEFLAG_INGAMESUBTITLES, file->flags));
	options_set_cutscene_subtitles(pak_has_bitflag(GAMEFILEFLAG_CUTSCENESUBTITLES, file->flags));

	// Duplicate
	options_set_paintball(player2, pak_has_bitflag(GAMEFILEFLAG_P2_PAINTBALL, file->flags));

	g_Vars.langfilteron = pak_has_bitflag(GAMEFILEFLAG_LANGFILTERON, file->flags);

	if (pak_has_bitflag(GAMEFILEFLAG_HIRES, file->flags)) {
		if (IS4MB()) {
			player_set_hi_res_enabled(false);
		} else {
			player_set_hi_res_enabled(true);
		}
	} else {
		player_set_hi_res_enabled(false);
	}

	if (IS4MB()) {
		options_set_screen_split(SCREENSPLIT_HORIZONTAL);
		options_set_screen_ratio(SCREENRATIO_NORMAL);
	} else {
		options_set_screen_split(pak_has_bitflag(GAMEFILEFLAG_SCREENSPLIT, file->flags));
		options_set_screen_ratio(pak_has_bitflag(GAMEFILEFLAG_SCREENRATIO, file->flags));
	}

	if (pak_has_bitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, file->flags)) {
		options_set_screen_size(SCREENSIZE_CINEMA);
	} else if (pak_has_bitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, file->flags)) {
		options_set_screen_size(SCREENSIZE_WIDE);
	} else {
		options_set_screen_size(SCREENSIZE_FULL);
	}

	g_Vars.pendingantiplayernum = pak_has_bitflag(GAMEFILEFLAG_ANTIPLAYERNUM, file->flags) ? 1 : 0;
	g_Vars.coopradaron = pak_has_bitflag(GAMEFILEFLAG_COOPRADARON, file->flags) ? true : false;
	g_Vars.coopfriendlyfire = pak_has_bitflag(GAMEFILEFLAG_COOPFRIENDLYFIRE, file->flags) ? true : false;
	g_Vars.antiradaron = pak_has_bitflag(GAMEFILEFLAG_ANTIRADARON, file->flags) ? true : false;

#if VERSION >= VERSION_PAL_BETA
	g_Vars.language = 0;

	if (pak_has_bitflag(GAMEFILEFLAG_LANGBIT1, file->flags)) {
		g_Vars.language |= 0x01;
	}

	if (pak_has_bitflag(GAMEFILEFLAG_LANGBIT2, file->flags)) {
		g_Vars.language |= 0x02;
	}

	if (pak_has_bitflag(GAMEFILEFLAG_LANGBIT3, file->flags)) {
		g_Vars.language |= 0x04;
	}

	lang_set_european(g_Vars.language);
#endif
}

void gamefile_load_defaults(struct gamefile *file)
{
	s32 player1 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 0 : 4;
	s32 player2 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 1 : 5;
	s32 i;
	s32 j;

	strcpy(file->name, "Dark");
	file->thumbnail = 0;
	file->autodifficulty = 0;
	file->autostageindex = 0;
	file->totaltime = 0;
#if VERSION >= VERSION_NTSC_1_0
	snd_set_sfx_volume(0x5000);
	options_set_music_volume(0x5000);
#else
	snd_set_sfx_volume(0x7f80);
	options_set_music_volume(0x7f80);
#endif
	snd_set_sound_mode(SOUNDMODE_STEREO);
	options_set_control_mode(player1, CONTROLMODE_11);
	options_set_control_mode(player2, CONTROLMODE_11);
	pak_clear_all_bitflags(file->flags);

	pak_set_bitflag(GAMEFILEFLAG_P1_FORWARDPITCH, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_P1_AUTOAIM, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P1_AIMCONTROL, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_P1_SIGHTONSCREEN, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P1_LOOKAHEAD, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P1_AMMOONSCREEN, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P1_HEADROLL, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P1_SHOWGUNFUNCTION, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_INGAMESUBTITLES, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P1_ALWAYSSHOWTARGET, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P1_SHOWZOOMRANGE, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P1_SHOWMISSIONTIME, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_P1_PAINTBALL, file->flags, false);

	pak_set_bitflag(GAMEFILEFLAG_P2_FORWARDPITCH, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_P2_AUTOAIM, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P2_AIMCONTROL, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_P2_SIGHTONSCREEN, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P2_LOOKAHEAD, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P2_AMMOONSCREEN, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P2_HEADROLL, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P2_SHOWGUNFUNCTION, file->flags, true);

#if VERSION >= VERSION_JPN_FINAL
	pak_set_bitflag(GAMEFILEFLAG_CUTSCENESUBTITLES, file->flags, true);
#else
	pak_set_bitflag(GAMEFILEFLAG_CUTSCENESUBTITLES, file->flags, false);
#endif

	pak_set_bitflag(GAMEFILEFLAG_P2_ALWAYSSHOWTARGET, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P2_SHOWZOOMRANGE, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_P2_SHOWMISSIONTIME, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_P2_PAINTBALL, file->flags, false);

	pak_set_bitflag(GAMEFILEFLAG_SCREENSPLIT, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_SCREENRATIO, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, file->flags, false);

	pak_set_bitflag(GAMEFILEFLAG_HIRES, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_LANGFILTERON, file->flags, false);

#if VERSION >= VERSION_NTSC_1_0
	pak_set_bitflag(GAMEFILEFLAG_FOUNDTIMEDMINE, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_FOUNDPROXYMINE, file->flags, false);
	pak_set_bitflag(GAMEFILEFLAG_FOUNDREMOTEMINE, file->flags, false);
#endif

	pak_set_bitflag(GAMEFILEFLAG_COOPRADARON, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_COOPFRIENDLYFIRE, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_ANTIRADARON, file->flags, true);
	pak_set_bitflag(GAMEFILEFLAG_ANTIPLAYERNUM, file->flags, true);

#if VERSION >= VERSION_PAL_BETA
	pak_set_bitflag(GAMEFILEFLAG_LANGBIT1, g_GameFile.flags, ((g_Vars.language & 0x01) == 0x01));
	pak_set_bitflag(GAMEFILEFLAG_LANGBIT2, g_GameFile.flags, ((g_Vars.language & 0x02) == 0x02));
	pak_set_bitflag(GAMEFILEFLAG_LANGBIT3, g_GameFile.flags, ((g_Vars.language & 0x04) == 0x04));
#endif

	file->unk1e = 0;

	for (i = 0; i < ARRAYCOUNT(file->besttimes); i++) {
		for (j = 0; j < ARRAYCOUNT(file->besttimes[0]); j++) {
			file->besttimes[i][j] = 0;
		}
	}

	for (i = 0; i < ARRAYCOUNT(g_MpChallenges); i++) {
		for (j = 1; j < MAX_PLAYERS + 1; j++) {
			challenge_set_completed_by_any_player_with_num_players(i, j, false);
		}
	}

	challenge_determine_unlocked_features();

	for (i = 0; i < ARRAYCOUNT(g_GameFile.coopcompletions); i++) {
		g_GameFile.coopcompletions[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_GameFile.firingrangescores); i++) {
		g_GameFile.firingrangescores[i] = 0;
	}

#if VERSION >= VERSION_NTSC_1_0
	for (i = 0; i < ARRAYCOUNT(g_GameFile.weaponsfound); i++)
#else
	for (i = 0; i < ARRAYCOUNT(g_GameFile.weaponsfound) - 2; i++)
#endif
	{
		g_GameFile.weaponsfound[i] = 0;
	}

	gamefile_apply_options(file);
}

const char var7f1b38e8[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b391c[] = "pdoptions.c";
const char var7f1b3928[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b395c[] = "pdoptions.c";
const char var7f1b3968[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b399c[] = "pdoptions.c";

s32 gamefile_load(s32 device)
{
	s32 p1index;
	s32 p2index;
	u32 volume;
	s32 i;
	s32 j;
	struct savebuffer buffer;
	s32 ret;
	u32 stack;

	p1index = g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 ? 0 : 4;
	p2index = g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 ? 1 : 5;

	if (device >= 0) {
		savebuffer_clear(&buffer);
		ret = pak_read_body_at_guid(device, g_GameFileGuid.fileid, buffer.bytes, 0);
		g_FilemgrLastPakError = ret;

		if (ret == 0) {
			cheats_init();
			savebuffer_read_string(&buffer, g_GameFile.name, 0);
			g_GameFile.thumbnail = savebuffer_read_bits(&buffer, 5);
			g_GameFile.totaltime = savebuffer_read_bits(&buffer, 32);
			g_GameFile.autodifficulty = savebuffer_read_bits(&buffer, 2);
			g_GameFile.autostageindex = savebuffer_read_bits(&buffer, 5);

			volume = savebuffer_read_bits(&buffer, 6) * 4;

			if (volume >= 252) {
				volume = 255;
			}

			snd_set_sfx_volume((volume & 0x1ff) * 128);

			volume = savebuffer_read_bits(&buffer, 6) * 4;

			if (volume >= 252) {
				volume = 255;
			}

			options_set_music_volume((volume & 0x1ff) * 128);

			snd_set_sound_mode(savebuffer_read_bits(&buffer, 2));
			options_set_control_mode(p1index, savebuffer_read_bits(&buffer, 3));
			options_set_control_mode(p2index, savebuffer_read_bits(&buffer, 3));

			for (i = 0; i < ARRAYCOUNT(g_GameFile.flags); i++) {
				g_GameFile.flags[i] = savebuffer_read_bits(&buffer, 8);
			}

			g_GameFile.unk1e = savebuffer_read_bits(&buffer, 16);

			for (i = 0; i < ARRAYCOUNT(g_GameFile.besttimes); i++) {
				for (j = 0; j < ARRAYCOUNT(g_GameFile.besttimes[i]); j++) {
					g_GameFile.besttimes[i][j] = savebuffer_read_bits(&buffer, 12);
				}
			}

			for (i = 0; i < ARRAYCOUNT(g_MpChallenges); i++) {
				for (j = 1; j < MAX_PLAYERS + 1; j++) {
					challenge_set_completed_by_any_player_with_num_players(i, j, savebuffer_read_bits(&buffer, 1));
				}
			}

			challenge_determine_unlocked_features();

			for (i = 0; i < ARRAYCOUNT(g_GameFile.coopcompletions); i++) {
				g_GameFile.coopcompletions[i] = savebuffer_read_bits(&buffer, NUM_SOLOSTAGES);
			}

			for (i = 0; i < ARRAYCOUNT(g_GameFile.firingrangescores); i++) {
				s32 numbits = i == ARRAYCOUNT(g_GameFile.firingrangescores) - 1 ? 2 : 8;
				g_GameFile.firingrangescores[i] = savebuffer_read_bits(&buffer, numbits);
			}

			for (i = 0; i < 4; i++) {
				g_GameFile.weaponsfound[i] = savebuffer_read_bits(&buffer, 8);
			}

#if VERSION >= VERSION_NTSC_1_0
			if (pak_has_bitflag(GAMEFILEFLAG_FOUNDTIMEDMINE, g_GameFile.flags)) {
				fr_set_weapon_found(WEAPON_TIMEDMINE);
			}

			if (pak_has_bitflag(GAMEFILEFLAG_FOUNDPROXYMINE, g_GameFile.flags)) {
				fr_set_weapon_found(WEAPON_PROXIMITYMINE);
			}

			if (pak_has_bitflag(GAMEFILEFLAG_FOUNDREMOTEMINE, g_GameFile.flags)) {
				fr_set_weapon_found(WEAPON_REMOTEMINE);
			}
#endif

			func0f0d54c4(&buffer);
			gamefile_apply_options(&g_GameFile);

			return 0;
		}

		return -1;
	}

	return -1;
}

s32 gamefile_save(s32 device, s32 fileid, u16 deviceserial)
{
	u32 value;
	s32 newfileid;
	s32 ret;
	s32 i;
	s32 j;
	s32 p1index;
	s32 p2index;
	struct savebuffer buffer;

	p1index = g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 ? 0 : 4;
	p2index = g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 ? 1 : 5;

	var80075bd0[0] = 1;

	pak_set_bitflag(GAMEFILEFLAG_P1_FORWARDPITCH, g_GameFile.flags, options_get_forward_pitch(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_AUTOAIM, g_GameFile.flags, options_get_auto_aim(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_AIMCONTROL, g_GameFile.flags, options_get_aim_control(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_SIGHTONSCREEN, g_GameFile.flags, options_get_sight_on_screen(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_LOOKAHEAD, g_GameFile.flags, options_get_look_ahead(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_AMMOONSCREEN, g_GameFile.flags, options_get_ammo_on_screen(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_HEADROLL, g_GameFile.flags, options_get_head_roll(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_SHOWGUNFUNCTION, g_GameFile.flags, options_get_show_gun_function(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_ALWAYSSHOWTARGET, g_GameFile.flags, options_get_always_show_target(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_SHOWZOOMRANGE, g_GameFile.flags, options_get_show_zoom_range(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_SHOWMISSIONTIME, g_GameFile.flags, options_get_show_mission_time(p1index));
	pak_set_bitflag(GAMEFILEFLAG_P1_PAINTBALL, g_GameFile.flags, options_get_paintball(p1index));

	pak_set_bitflag(GAMEFILEFLAG_P2_FORWARDPITCH, g_GameFile.flags, options_get_forward_pitch(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_AUTOAIM, g_GameFile.flags, options_get_auto_aim(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_AIMCONTROL, g_GameFile.flags, options_get_aim_control(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_SIGHTONSCREEN, g_GameFile.flags, options_get_sight_on_screen(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_LOOKAHEAD, g_GameFile.flags, options_get_look_ahead(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_AMMOONSCREEN, g_GameFile.flags, options_get_ammo_on_screen(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_HEADROLL, g_GameFile.flags, options_get_head_roll(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_SHOWGUNFUNCTION, g_GameFile.flags, options_get_show_gun_function(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_ALWAYSSHOWTARGET, g_GameFile.flags, options_get_always_show_target(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_SHOWZOOMRANGE, g_GameFile.flags, options_get_show_zoom_range(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_SHOWMISSIONTIME, g_GameFile.flags, options_get_show_mission_time(p2index));
	pak_set_bitflag(GAMEFILEFLAG_P2_PAINTBALL, g_GameFile.flags, options_get_paintball(p2index));

	pak_set_bitflag(GAMEFILEFLAG_SCREENSPLIT, g_GameFile.flags, options_get_screen_split());
	pak_set_bitflag(GAMEFILEFLAG_SCREENRATIO, g_GameFile.flags, options_get_screen_ratio());

#if VERSION >= VERSION_NTSC_1_0
	pak_set_bitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, g_GameFile.flags, options_get_screen_size() == SCREENSIZE_WIDE);
	pak_set_bitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, g_GameFile.flags, options_get_screen_size() == SCREENSIZE_CINEMA);
#else
	pak_set_bitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, g_GameFile.flags, options_get_effective_screen_size() == SCREENSIZE_WIDE);
	pak_set_bitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, g_GameFile.flags, options_get_effective_screen_size() == SCREENSIZE_CINEMA);
#endif

	pak_set_bitflag(GAMEFILEFLAG_HIRES, g_GameFile.flags, g_ViRes == VIRES_HI);
	pak_set_bitflag(GAMEFILEFLAG_INGAMESUBTITLES, g_GameFile.flags, options_get_in_game_subtitles());
	pak_set_bitflag(GAMEFILEFLAG_CUTSCENESUBTITLES, g_GameFile.flags, options_get_cutscene_subtitles());
	pak_set_bitflag(GAMEFILEFLAG_LANGFILTERON, g_GameFile.flags, g_Vars.langfilteron);

#if VERSION >= VERSION_NTSC_1_0
	pak_set_bitflag(GAMEFILEFLAG_FOUNDTIMEDMINE, g_GameFile.flags, fr_is_weapon_found(WEAPON_TIMEDMINE));
	pak_set_bitflag(GAMEFILEFLAG_FOUNDPROXYMINE, g_GameFile.flags, fr_is_weapon_found(WEAPON_PROXIMITYMINE));
	pak_set_bitflag(GAMEFILEFLAG_FOUNDREMOTEMINE, g_GameFile.flags, fr_is_weapon_found(WEAPON_REMOTEMINE));
#endif

#if VERSION >= VERSION_NTSC_1_0
	switch (options_get_screen_size())
#else
	switch (options_get_effective_screen_size())
#endif
	{
	case SCREENSIZE_FULL:
		break;
	case SCREENSIZE_WIDE:
		break;
	case SCREENSIZE_CINEMA:
		break;
	}

	pak_set_bitflag(GAMEFILEFLAG_ANTIPLAYERNUM, g_GameFile.flags, g_Vars.pendingantiplayernum == 1);
	pak_set_bitflag(GAMEFILEFLAG_COOPRADARON, g_GameFile.flags, g_Vars.coopradaron == true);
	pak_set_bitflag(GAMEFILEFLAG_COOPFRIENDLYFIRE, g_GameFile.flags, g_Vars.coopfriendlyfire == true);
	pak_set_bitflag(GAMEFILEFLAG_ANTIRADARON, g_GameFile.flags, g_Vars.antiradaron == true);

#if VERSION >= VERSION_PAL_BETA
	pak_set_bitflag(GAMEFILEFLAG_LANGBIT1, g_GameFile.flags, (g_Vars.language & 0x01) == 0x01);
	pak_set_bitflag(GAMEFILEFLAG_LANGBIT2, g_GameFile.flags, (g_Vars.language & 0x02) == 0x02);
	pak_set_bitflag(GAMEFILEFLAG_LANGBIT3, g_GameFile.flags, (g_Vars.language & 0x04) == 0x04);
#endif

	if (device >= 0) {
		savebuffer_clear(&buffer);
		func0f0d55a4(&buffer, g_GameFile.name);

		savebuffer_or(&buffer, g_GameFile.thumbnail, 5);
		savebuffer_or(&buffer, g_GameFile.totaltime, 32);
		savebuffer_or(&buffer, g_GameFile.autodifficulty, 2);
		savebuffer_or(&buffer, g_GameFile.autostageindex, 5);

		value = VOLUME(g_SfxVolume) >> 7;
		savebuffer_or(&buffer, value >> 2, 6);

		value = options_get_music_volume() >> 7;
		savebuffer_or(&buffer, value >> 2, 6);

		value = g_SoundMode;
		savebuffer_or(&buffer, value, 2);

		savebuffer_or(&buffer, options_get_control_mode(p1index), 3);
		savebuffer_or(&buffer, options_get_control_mode(p2index), 3);

		for (i = 0; i < ARRAYCOUNT(g_GameFile.flags); i++) {
			savebuffer_or(&buffer, g_GameFile.flags[i], 8);
		}

		savebuffer_or(&buffer, g_GameFile.unk1e, 16);

		for (i = 0; i < ARRAYCOUNT(g_GameFile.besttimes); i++) {
			for (j = 0; j < ARRAYCOUNT(g_GameFile.besttimes[i]); j++) {
				savebuffer_or(&buffer, g_GameFile.besttimes[i][j], 12);
			}
		}

		for (i = 0; i < ARRAYCOUNT(g_MpChallenges); i++) {
			for (j = 1; j < MAX_PLAYERS + 1; j++) {
				savebuffer_or(&buffer, challenge_is_completed_by_any_player_with_num_players(i, j), 1);
			}
		}

		for (i = 0; i < ARRAYCOUNT(g_GameFile.coopcompletions); i++) {
			savebuffer_or(&buffer, g_GameFile.coopcompletions[i], NUM_SOLOSTAGES);
		}

		for (i = 0; i < ARRAYCOUNT(g_GameFile.firingrangescores); i++) {
			savebuffer_or(&buffer, g_GameFile.firingrangescores[i], i == 8 ? 2 : 8);
		}

		for (i = 0; i < 4; i++) {
			savebuffer_or(&buffer, g_GameFile.weaponsfound[i], 8);
		}

		func0f0d54c4(&buffer);

		ret = pak_save_at_guid(device, fileid, PAKFILETYPE_GAME, buffer.bytes, &newfileid, 0);
		g_FilemgrLastPakError = ret;

		if (ret == 0) {
			g_GameFileGuid.fileid = newfileid;
			g_GameFileGuid.deviceserial = deviceserial;

			return 0;
		}

		return -1;
	}

	return -1;
}

void gamefile_get_overview(char *arg0, char *name, u8 *stage, u8 *difficulty, u32 *time)
{
	struct savebuffer buffer;

	func0f0d5484(&buffer, arg0, 15);
	savebuffer_read_string(&buffer, name, false);

	*stage = savebuffer_read_bits(&buffer, 5);

#if VERSION >= VERSION_NTSC_1_0
	*time = savebuffer_read_bits(&buffer, 32);
#else
	*time = (u16) savebuffer_read_bits(&buffer, 32);
#endif

	*difficulty = savebuffer_read_bits(&buffer, 2);
}
