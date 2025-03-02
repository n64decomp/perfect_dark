#include <ultra64.h>
#include "constants.h"
#include "game/menu.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/options.h"
#include "game/stagemusic.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/music.h"
#include "data.h"
#include "types.h"

#define FADETYPE_STOP  0
#define FADETYPE_PAUSE 1

s32 g_MusicStageNum;
struct musicevent g_MusicEventQueue[40];
struct seqchannel g_SeqChannels[3];
u32 g_AudioXReasonsActive[4];
s32 g_MusicXReasonMinDurations[4];
s32 g_MusicXReasonMaxDurations[4];

s32 g_MenuTrack = -1;
s32 g_MusicEventQueueLength = 0;
s32 g_TemporaryPrimaryTrack = -1;
s32 g_TemporaryAmbientTrack = -1;

#if VERSION >= VERSION_NTSC_1_0
s32 g_MusicSavedInterval240 = -1;
#endif

u32 g_MusicNextEventId = 0;
bool g_MusicNrgIsActive = false;
bool g_MusicMpDeathIsPlaying = false;
s32 g_MusicInterval240 = 15;
s32 g_MusicSleepRemaining240 = 0;
bool g_MusicSoloDeathIsPlaying = false;

#if VERSION >= VERSION_NTSC_1_0
u16 g_MusicVolume = 0x5000;
#endif

s32 g_MusicDeathTimer240 = 0;   // Counts down 5 seconds while death music plays
s32 g_MusicAge60 = 0;           // The current age of the MP track being played
s32 g_MusicLife60 = TICKS(120); // The max age of any MP track (this value is changed in MP code)
s32 g_MusicSilenceTimer60 = 0;  // Counts down the 2 second silence between MP track changes

#if VERSION < VERSION_NTSC_1_0
const char var7f1b2030nb[] = "MUSIC : musicPlayLevel\n";
const char var7f1b2048nb[] = "MUSIC : SWITCHING TO CORRECT AMBIENT TUNE\n";
const char var7f1b2074nb[] = "musicStartLevel\n";
const char var7f1b2088nb[] = "musicEndLevel\n";
const char var7f1b2098nb[] = "musicStartNRG\n";
const char var7f1b20a8nb[] = "musicEndNRG\n";
const char var7f1b20b8nb[] = "musicStartWatch start\n";
const char var7f1b20d0nb[] = "musicEndWatch start\n";
const char var7f1b20e8nb[] = "musicEndWatch end\n";
const char var7f1b20fcnb[] = "musicStartDead\n";
const char var7f1b210cnb[] = "musicStartTemporary\n";
const char var7f1b2124nb[] = "musicEndTemporary\n";
const char var7f1b2138nb[] = "musicStartCutscene\n";
const char var7f1b214cnb[] = "musicEndCutscene\n";
const char var7f1b2160nb[] = "musicStartAmbient : Tune=%d\n";
const char var7f1b2180nb[] = "musicEndAmbient\n";
#endif

char *var80084100[] = {
	"null",
	"leveltune",
	"nrgtune,watchtune,mpdeathtune",
	"ambience",
	"NULL",
	"playing",
	"paused",
};

#if VERSION >= VERSION_PAL_FINAL
u32 var8008465cpf = 0;
#endif

const char var7f1b7918[] = "MUSIC : activedeath=%d\n";

void music_save_interval(void);
void music_restore_interval(void);
bool music_is_any_player_in_ambient_room(void);

u16 music_get_volume(void)
{
#if VERSION >= VERSION_NTSC_1_0
	u32 volume;

	if (g_Vars.stagenum == STAGE_CREDITS) {
		return 0x5000;
	}

	if (g_MusicVolume < 0x5000) {
		volume = g_MusicVolume;
	} else {
		volume = 0x5000;
	}

	return volume;
#else
	return options_get_music_volume();
#endif
}

void music_set_volume(u16 volume)
{
	s32 i;

#if VERSION >= VERSION_NTSC_1_0
	if (volume > 0x5000) {
		volume = 0x5000;
	}
#endif

	for (i = 0; i < ARRAYCOUNT(g_SeqChannels); i++) {
		if (g_SeqChannels[i].tracktype != TRACKTYPE_NONE && g_SeqChannels[i].tracktype != TRACKTYPE_AMBIENT) {
			seq_set_volume(&g_SeqInstances[i], volume);
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	g_MusicVolume = volume;
#endif
}

bool music_is_track_state(s32 tracktype, s32 state)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_SeqChannels); i++) {
		if (g_SeqChannels[i].tracktype == tracktype) {
			switch (state) {
			case AL_STOPPED:
				return !g_SeqChannels[i].inuse;
			case AL_PLAYING:
				return g_SeqChannels[i].inuse;
			case AL_STOPPING:
				return g_SeqChannels[i].keepafterfade;
			}
		}
	}

	return false;
}

s32 music_get_track_state(s32 tracktype)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_SeqChannels); i++) {
		if (g_SeqChannels[i].tracktype == tracktype) {
			if (g_SeqChannels[i].keepafterfade) {
				return AL_STOPPING;
			}

			if (g_SeqChannels[i].inuse) {
				return AL_PLAYING;
			}
		}
	}

	return AL_STOPPED;
}

s32 music_get_channel_by_track_type(s32 tracktype)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_SeqChannels); i++) {
		if (g_SeqChannels[i].tracktype == tracktype) {
			return i;
		}
	}

	return -1;
}

void music_queue_start_event(u32 tracktype, u32 tracknum, f32 seconds, u16 volume)
{
	if (!g_SndDisabled) {
		g_MusicEventQueue[g_MusicEventQueueLength].tracktype = tracktype;
		g_MusicEventQueue[g_MusicEventQueueLength].tracknum = tracknum;
		g_MusicEventQueue[g_MusicEventQueueLength].fadesecs = seconds;
		g_MusicEventQueue[g_MusicEventQueueLength].volume = volume;
		g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_PLAY;
		g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
		g_MusicEventQueue[g_MusicEventQueueLength].numattempts = 0;
		g_MusicEventQueue[g_MusicEventQueueLength].failcount = 0;
		g_MusicEventQueueLength++;
	}
}

void music_queue_stop_event(s32 tracktype)
{
	if (!g_SndDisabled) {
		g_MusicEventQueue[g_MusicEventQueueLength].tracktype = tracktype;
		g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_STOP;
		g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
		g_MusicEventQueue[g_MusicEventQueueLength].numattempts = 0;
		g_MusicEventQueue[g_MusicEventQueueLength].failcount = 0;
		g_MusicEventQueueLength++;
	}
}

void music_queue_fade_event(s32 tracktype, f32 seconds, bool keepafterfade)
{
	if (!g_SndDisabled) {
		g_MusicEventQueue[g_MusicEventQueueLength].tracktype = tracktype;
		g_MusicEventQueue[g_MusicEventQueueLength].fadesecs = seconds;
		g_MusicEventQueue[g_MusicEventQueueLength].keepafterfade = keepafterfade;
		g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_FADE;
		g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
		g_MusicEventQueue[g_MusicEventQueueLength].numattempts = 0;
		g_MusicEventQueue[g_MusicEventQueueLength].failcount = 0;
		g_MusicEventQueueLength++;
	}
}

void music_reset(void)
{
	s32 i;

	if (!g_SndDisabled) {
		for (i = 0; i < ARRAYCOUNT(g_AudioXReasonsActive); i++) {
			g_AudioXReasonsActive[i] = 0;
			g_MusicXReasonMinDurations[i] = 0;
			g_MusicXReasonMaxDurations[i] = 0;
		}

#if VERSION >= VERSION_NTSC_1_0
		music_save_interval();
		music_queue_stop_all_event();
		music_restore_interval();
#else
		music_queue_stop_all_event();
#endif

		g_MusicSoloDeathIsPlaying = false;
		g_MusicDeathTimer240 = 0;
		g_MenuTrack = -1;
		g_TemporaryPrimaryTrack = -1;
		g_TemporaryAmbientTrack = -1;
		g_MusicNrgIsActive = false;
	}
}

void music_queue_stop_all_event(void)
{
#if VERSION >= VERSION_NTSC_1_0
	g_MusicEventQueue[0].tracktype = TRACKTYPE_6;
#endif

	g_MusicEventQueue[0].eventtype = MUSICEVENTTYPE_STOPALL;
	g_MusicEventQueue[0].id = g_MusicNextEventId++;
	g_MusicEventQueue[0].numattempts = 0;
	g_MusicEventQueue[0].failcount = 0;

	g_MusicEventQueueLength = 1;

	music_tick_events();
}

#if VERSION >= VERSION_NTSC_1_0
void music_save_interval(void)
{
	g_MusicSavedInterval240 = g_MusicInterval240;
	g_MusicInterval240 = 0;
}

void music_restore_interval(void)
{
	g_MusicEventQueue[g_MusicEventQueueLength].tracktype = TRACKTYPE_6;
	g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_SETINTERVAL;
	g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
	g_MusicEventQueue[g_MusicEventQueueLength].timer240 = g_MusicSavedInterval240;
	g_MusicEventQueueLength++;

	// @bug: This should be modifying the interval queue item, not the first queue item
	g_MusicEventQueue[0].numattempts = 0;
	g_MusicEventQueue[0].failcount = 0;
}
#endif

#define PRIMARYTRACK() (g_TemporaryPrimaryTrack != -1 ? g_TemporaryPrimaryTrack : stage_get_primary_track(g_MusicStageNum))
#define AMBIENTTRACK() (g_TemporaryAmbientTrack != -1 ? g_TemporaryAmbientTrack : stage_get_ambient_track(g_MusicStageNum))

void music_start_primary(f32 arg0)
{
	if (PRIMARYTRACK() >= 0) {
		music_queue_start_event(TRACKTYPE_PRIMARY, PRIMARYTRACK(), arg0, music_get_volume());
	}
}

void music_start_ambient(f32 arg0)
{
	s32 pass = false;

	if (AMBIENTTRACK() >= 0) {
		if (g_TemporaryAmbientTrack != -1) {
			pass = true;
		} else if (music_is_any_player_in_ambient_room()) {
			if (g_Vars.tickmode != TICKMODE_CUTSCENE && AMBIENTTRACK() != stage_get_ambient_track(g_MusicStageNum)) {
				music_queue_stop_event(TRACKTYPE_AMBIENT);
				music_start_temporary_ambient(stage_get_ambient_track(g_MusicStageNum));
				return;
			}

			pass = true;
		}
	}

	if (pass) {
		switch (music_get_track_state(TRACKTYPE_AMBIENT)) {
		case AL_STOPPED:
		case AL_STOPPING:
			music_queue_start_event(TRACKTYPE_AMBIENT, AMBIENTTRACK(), arg0, VOLUME(g_SfxVolume));
			break;
		}
	}
}

bool music_is_any_player_in_ambient_room(void)
{
	s32 i;

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		return false;
	}

	if (lv_is_paused()) {
		return false;
	}

	if (g_MusicSoloDeathIsPlaying) {
		return false;
	}

	if (g_MusicNrgIsActive && g_MusicMpDeathIsPlaying) {
		return false;
	}

	for (i = 0; i < PLAYERCOUNT(); i++) {
		if (g_Vars.players[i]->prop
				&& g_Vars.players[i]->prop->rooms
				&& g_Vars.players[i]->prop->rooms[0] != -1) {
			bool hasflag;

			if (g_Rooms[g_Vars.players[i]->prop->rooms[0]].flags & ROOMFLAG_PLAYAMBIENTTRACK) {
				hasflag = true;
			} else {
				hasflag = false;
			}

			if (hasflag) {
				return true;
			}
		}
	}

	return false;
}

void music_start_nrg(f32 arg0)
{
	music_queue_start_event(TRACKTYPE_NRG, stage_get_nrg_track(g_MusicStageNum), arg0, music_get_volume());
}

/**
 * Not called.
 */
void music_start_watch(f32 arg0)
{
	music_queue_start_event(TRACKTYPE_MENU, menu_choose_music(), arg0, music_get_volume());
}

/**
 * Play a specific track as a menu track.
 *
 * Used in credits and the soundtrack dialog in MP setup.
 */
void music_start_track_as_menu(s32 tracknum)
{
	if (tracknum != g_MenuTrack) {
		music_queue_stop_event(TRACKTYPE_MENU);
		music_queue_stop_event(TRACKTYPE_DEATH);
		music_queue_fade_event(TRACKTYPE_PRIMARY, 0.5f, FADETYPE_PAUSE);
		music_queue_fade_event(TRACKTYPE_NRG, 0.5f, FADETYPE_PAUSE);
		music_queue_fade_event(TRACKTYPE_AMBIENT, 0.5f, FADETYPE_PAUSE);
		music_queue_start_event(TRACKTYPE_MENU, tracknum, 0, music_get_volume());
	}

	g_MenuTrack = tracknum;
}

/**
 * Used when starting combat simulator matches.
 */
void music_set_stage_and_start_music(s32 stagenum)
{
	g_MusicStageNum = stagenum;

	music_start_primary(0);

	if (stage_get_ambient_track(g_MusicStageNum) >= 0) {
		music_start_ambient(0);
	}
}

/**
 * Used for solo missions.
 */
void music_set_stage(s32 stagenum)
{
	g_MusicStageNum = stagenum;
}

void music_stop(void)
{
#if VERSION >= VERSION_NTSC_1_0
	music_save_interval();
	music_queue_stop_all_event();
	music_restore_interval();
#else
	music_queue_stop_all_event();
#endif
}

void music_activate_nrg(void)
{
#if VERSION >= VERSION_NTSC_1_0
	if (!g_MusicNrgIsActive)
#endif
	{
		if (stage_get_nrg_track(g_MusicStageNum) >= 0) {
			music_queue_stop_event(TRACKTYPE_NRG);
			music_queue_stop_event(TRACKTYPE_MENU);
			music_queue_stop_event(TRACKTYPE_DEATH);
			music_queue_fade_event(TRACKTYPE_PRIMARY, 0.5, FADETYPE_PAUSE);
			music_start_nrg(0);

			g_MusicNrgIsActive = true;
		}
	}
}

void music_deactivate_nrg(void)
{
#if VERSION >= VERSION_NTSC_1_0
	if (g_MusicNrgIsActive)
#endif
	{
		music_queue_stop_event(TRACKTYPE_MENU);
		music_queue_stop_event(TRACKTYPE_DEATH);
		music_queue_fade_event(TRACKTYPE_NRG, 1, FADETYPE_STOP);

		if (g_Vars.dontplaynrg == false) {
			music_start_primary(0.5);
		}

		g_MusicNrgIsActive = false;
	}
}

/**
 * Called in many places when opening a pause menu.
 */
void music_start_menu(void)
{
	music_start_track_as_menu(menu_choose_music());
}

void music_end_menu(void)
{
	music_queue_fade_event(TRACKTYPE_MENU, 1, FADETYPE_STOP);

	if (music_is_track_state(TRACKTYPE_NRG, AL_PLAYING)) {
		music_start_nrg(1);
	} else {
		music_start_primary(1);
	}

	g_MenuTrack = -1;
}

void music_start_solo_death(void)
{
	g_MusicSoloDeathIsPlaying = true;

#if VERSION >= VERSION_NTSC_1_0
	music_save_interval();
#endif

	music_queue_stop_event(TRACKTYPE_MENU);
	music_queue_stop_event(TRACKTYPE_DEATH);
	music_unset_x_reason(-1);
	music_queue_stop_event(TRACKTYPE_NRG);
	music_queue_stop_event(TRACKTYPE_PRIMARY);
	music_queue_stop_event(TRACKTYPE_AMBIENT);
	music_queue_start_event(TRACKTYPE_PRIMARY, MUSIC_DEATH_SOLO, 0, VOLUME(g_SfxVolume) > music_get_volume() ? VOLUME(g_SfxVolume) : music_get_volume());

#if VERSION >= VERSION_NTSC_1_0
	music_restore_interval();
#endif
}

void _music_start_mp_death(f32 arg0)
{
#if VERSION >= VERSION_NTSC_1_0
	music_save_interval();
	music_queue_start_event(TRACKTYPE_DEATH, MUSIC_DEATH_MP, arg0, VOLUME(g_SfxVolume) > music_get_volume() ? VOLUME(g_SfxVolume) : music_get_volume());
	music_restore_interval();
#else
	music_queue_start_event(TRACKTYPE_DEATH, MUSIC_DEATH_MP, arg0, VOLUME(g_SfxVolume) > music_get_volume() ? VOLUME(g_SfxVolume) : music_get_volume());
#endif
}

void music_start_mp_death(void)
{
#if VERSION >= VERSION_NTSC_1_0
	music_save_interval();
#endif

	music_queue_stop_event(TRACKTYPE_MENU);
	music_queue_stop_event(TRACKTYPE_DEATH);
	music_queue_stop_event(TRACKTYPE_AMBIENT);

	if (g_MusicNrgIsActive) {
		music_queue_fade_event(TRACKTYPE_NRG, 0.1f, FADETYPE_PAUSE);
	} else {
		music_queue_fade_event(TRACKTYPE_PRIMARY, 0.1f, FADETYPE_PAUSE);
	}

	_music_start_mp_death(0);

	g_MusicDeathTimer240 = TICKS(1200);
	g_MusicMpDeathIsPlaying = true;

#if VERSION >= VERSION_NTSC_1_0
	music_restore_interval();
#endif
}

void music_end_death(void)
{
	music_queue_fade_event(TRACKTYPE_DEATH, 2, FADETYPE_STOP);

	if (g_MusicNrgIsActive) {
		music_start_nrg(2);
	} else {
		music_start_primary(2);
	}

	g_MusicMpDeathIsPlaying = false;
}

/**
 * Stop all other music and play the given track.
 *
 * It's used by the AI scripting language, specifically for CI training and
 * the Skedar King battle.
 *
 * The track type used is primary.
 */
void music_play_track_isolated(s32 tracknum)
{
#if VERSION >= VERSION_NTSC_1_0
	music_save_interval();
#endif

	music_queue_stop_event(TRACKTYPE_MENU);
	music_queue_stop_event(TRACKTYPE_DEATH);
	music_unset_x_reason(-1);
	music_queue_stop_event(TRACKTYPE_NRG);
	music_queue_stop_event(TRACKTYPE_PRIMARY);
	music_queue_stop_event(TRACKTYPE_AMBIENT);
	music_queue_start_event(TRACKTYPE_PRIMARY, tracknum, 0, music_get_volume());

#if VERSION >= VERSION_NTSC_1_0
	music_restore_interval();
#endif
}

/**
 * Restart the level's default tracks after using the isolated track above.
 *
 * It's used by the AI scripting language, specifically when ending CI training.
 */
void music_play_default_tracks(void)
{
	music_queue_stop_event(TRACKTYPE_PRIMARY);
	music_queue_stop_event(TRACKTYPE_AMBIENT);
	music_start_primary(0.5f);
}

/**
 * Used by the title screen, as well as AF1's NRG theme which never ends.
 */
void music_start_temporary_primary(s32 tracknum)
{
	music_queue_stop_event(TRACKTYPE_PRIMARY);

	g_TemporaryPrimaryTrack = tracknum;

	music_start_primary(0.5f);
}

/**
 * Used by AI scripting on each stage.
 *
 * The cutscene track is played with a primary tracktype.
 *
 * The NRG theme will not play while a cutscene theme is active.
 */
void music_start_cutscene(s32 tracknum)
{
	u32 volume;

	music_queue_stop_event(TRACKTYPE_MENU);
	music_queue_stop_event(TRACKTYPE_DEATH);
	music_unset_x_reason(-1);
	music_queue_stop_event(TRACKTYPE_NRG);
	music_queue_stop_event(TRACKTYPE_PRIMARY);

	if (g_SfxVolume < music_get_volume()) {
		volume = music_get_volume();
	} else {
		volume = g_SfxVolume;
	}

	music_queue_start_event(TRACKTYPE_PRIMARY, tracknum, 0, volume);

	g_Vars.dontplaynrg = true;
}

/**
 * Used by AI scripting on each stage.
 */
void music_end_cutscene(void)
{
	g_Vars.dontplaynrg = false;

	if (!g_IsTitleDemo) {
		music_queue_stop_event(TRACKTYPE_PRIMARY);
		music_queue_stop_event(TRACKTYPE_AMBIENT);
		music_start_primary(0.5f);
	}
}

/**
 * Used by AI scripting, and only to set the ambient track during the Defection
 * intro and Extraction outro to traffic noises.
 */
void music_start_temporary_ambient(s32 tracknum)
{
	g_TemporaryAmbientTrack = tracknum;
	music_queue_stop_event(TRACKTYPE_AMBIENT);

	music_queue_start_event(TRACKTYPE_AMBIENT, tracknum, 0, VOLUME(g_SfxVolume));
}

void music_end_temporary_ambient(void)
{
	g_TemporaryAmbientTrack = -1;
	music_queue_stop_event(TRACKTYPE_AMBIENT);
}

void music_set_x_reason(s32 reason, u32 minsecs, u32 maxsecs)
{
	if (g_AudioXReasonsActive[reason] == false) {
		g_AudioXReasonsActive[reason] = true;
		g_MusicXReasonMinDurations[reason] = minsecs * TICKS(240);
		g_MusicXReasonMaxDurations[reason] = maxsecs * TICKS(240);
	}
}

void music_unset_x_reason(s32 reason)
{
	s32 i;

	if (reason >= 0) {
		g_AudioXReasonsActive[reason] = false;
	} else {
		for (i = 0; i < ARRAYCOUNT(g_AudioXReasonsActive); i++) {
			g_AudioXReasonsActive[i] = false;
			g_MusicXReasonMinDurations[i] = 0;
			g_MusicXReasonMaxDurations[i] = 0;
		}

#if VERSION >= VERSION_NTSC_1_0
		if (g_MusicNrgIsActive) {
			music_deactivate_nrg();
		}
#endif
	}
}

/**
 * Called by music_tick every 0.25 seconds.
 */
void music_tick_ambient(void)
{
	if (g_TemporaryAmbientTrack == -1) {
		if (music_is_any_player_in_ambient_room()) {
			music_start_ambient(1);
		} else if (music_get_track_state(TRACKTYPE_AMBIENT) == AL_PLAYING) {
			music_queue_fade_event(TRACKTYPE_AMBIENT, 1, FADETYPE_PAUSE);
		}
	} else if (stage_get_ambient_track(g_MusicStageNum) >= 0) {
		music_start_ambient(1);
	}
}

void func0f16e1cc(void)
{
	// empty
}
