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

static void func0f16d430(void);
static void musicQueueType5Event(void);
static bool musicIsAnyPlayerInAmbientRoom(void);

s32 g_MusicStageNum;
struct musicevent g_MusicEventQueue[40];
struct var800aaa38 var800aaa38[3];
u32 g_AudioXReasonsActive[4];
s32 g_MusicXReasonMinDurations[4];
s32 g_MusicXReasonMaxDurations[4];

s32 g_MenuTrack = -1;
s32 g_MusicEventQueueLength = 0;
s32 g_TemporaryPrimaryTrack = -1;
s32 g_TemporaryAmbientTrack = -1;

s32 var800840d0 = -1;

u32 g_MusicNextEventId = 0;
bool g_MusicNrgIsActive = false;
bool g_MusicMpDeathIsPlaying = false;
s32 var800840e0 = 15;
s32 var800840e4 = 0;
bool g_MusicSoloDeathIsPlaying = false;

u16 g_MusicVolume = 0x5000;

s32 g_MusicDeathTimer240 = 0;     // Counts down 5 seconds while death music plays
s32 g_MusicAge60 = 0;             // The current age of the MP track being played
s32 g_MusicLife60 = TICKS(120); // The max age of any MP track (this value is changed in MP code)
s32 g_MusicSilenceTimer60 = 0;    // Counts down the 2 second silence between MP track changes

u16 musicGetVolume(void)
{
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
}

void musicSetVolume(u16 volume)
{
	s32 i;

	if (volume > 0x5000) {
		volume = 0x5000;
	}

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].tracktype != TRACKTYPE_NONE && var800aaa38[i].tracktype != TRACKTYPE_AMBIENT) {
			seqSetVolume(&g_SeqInstances[i], volume);
		}
	}

	g_MusicVolume = volume;
}

static bool func0f16d0a8(s32 tracktype, s32 arg1)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].tracktype == tracktype) {
			switch (arg1) {
			case 0: return var800aaa38[i].unk04 <= 0;
			case 1: return var800aaa38[i].unk04;
			case 2: return var800aaa38[i].unk08;
			}
		}
	}

	return false;
}

static s32 func0f16d124(s32 tracktype)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].tracktype == tracktype) {
			if (var800aaa38[i].unk08) {
				return 2;
			}

			if (var800aaa38[i].unk04) {
				return 1;
			}
		}
	}

	return 0;
}

void musicQueueStartEvent(u32 tracktype, u32 tracknum, f32 arg2, u16 volume)
{
	g_MusicEventQueue[g_MusicEventQueueLength].tracktype = tracktype;
	g_MusicEventQueue[g_MusicEventQueueLength].tracknum = tracknum;
	g_MusicEventQueue[g_MusicEventQueueLength].unk0c = arg2;
	g_MusicEventQueue[g_MusicEventQueueLength].volume = volume;
	g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_PLAY;
	g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
	g_MusicEventQueue[g_MusicEventQueueLength].numattempts = 0;
	g_MusicEventQueue[g_MusicEventQueueLength].failcount = 0;
	g_MusicEventQueueLength++;
}

void musicQueueStopEvent(s32 tracktype)
{
	g_MusicEventQueue[g_MusicEventQueueLength].tracktype = tracktype;
	g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_STOP;
	g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
	g_MusicEventQueue[g_MusicEventQueueLength].numattempts = 0;
	g_MusicEventQueue[g_MusicEventQueueLength].failcount = 0;
	g_MusicEventQueueLength++;
}

void musicQueueFadeEvent(s32 tracktype, f32 arg1, bool fadetopause)
{
	g_MusicEventQueue[g_MusicEventQueueLength].tracktype = tracktype;
	g_MusicEventQueue[g_MusicEventQueueLength].unk0c = arg1;
	g_MusicEventQueue[g_MusicEventQueueLength].fadetopause = fadetopause;
	g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_FADE;
	g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
	g_MusicEventQueue[g_MusicEventQueueLength].numattempts = 0;
	g_MusicEventQueue[g_MusicEventQueueLength].failcount = 0;
	g_MusicEventQueueLength++;
}

void musicReset(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		g_AudioXReasonsActive[i] = 0;
		g_MusicXReasonMinDurations[i] = 0;
		g_MusicXReasonMaxDurations[i] = 0;
	}

	func0f16d430();
	musicQueueStopAllEvent();
	musicQueueType5Event();

	g_MusicSoloDeathIsPlaying = false;
	g_MusicDeathTimer240 = 0;
	g_MenuTrack = -1;
	g_TemporaryPrimaryTrack = -1;
	g_TemporaryAmbientTrack = -1;
	g_MusicNrgIsActive = false;
}

void musicQueueStopAllEvent(void)
{
	g_MusicEventQueue[0].tracktype = TRACKTYPE_6;

	g_MusicEventQueue[0].eventtype = MUSICEVENTTYPE_STOPALL;
	g_MusicEventQueue[0].id = g_MusicNextEventId++;
	g_MusicEventQueue[0].numattempts = 0;
	g_MusicEventQueue[0].failcount = 0;

	g_MusicEventQueueLength = 1;

	musicTickEvents();
}

static void func0f16d430(void)
{
	var800840d0 = var800840e0;
	var800840e0 = 0;
}

static void musicQueueType5Event(void)
{
	g_MusicEventQueue[g_MusicEventQueueLength].tracktype = TRACKTYPE_6;
	g_MusicEventQueue[g_MusicEventQueueLength].eventtype = MUSICEVENTTYPE_5;
	g_MusicEventQueue[g_MusicEventQueueLength].id = g_MusicNextEventId++;
	g_MusicEventQueue[g_MusicEventQueueLength].tracknum = var800840d0;
	g_MusicEventQueueLength++;

	g_MusicEventQueue[0].numattempts = 0;
	g_MusicEventQueue[0].failcount = 0;
}

#define PRIMARYTRACK() (g_TemporaryPrimaryTrack != -1 ? g_TemporaryPrimaryTrack : stageGetPrimaryTrack(g_MusicStageNum))

void musicStartPrimary(f32 arg0)
{
	if (PRIMARYTRACK() >= 0) {
		musicQueueStartEvent(TRACKTYPE_PRIMARY, PRIMARYTRACK(), arg0, musicGetVolume());
	}
}

#define AMBIENTTRACK() (g_TemporaryAmbientTrack != -1 ? g_TemporaryAmbientTrack : stageGetAmbientTrack(g_MusicStageNum))

static void musicStartAmbient(f32 arg0)
{
	s32 pass = false;

	if (AMBIENTTRACK() >= 0) {
		if (g_TemporaryAmbientTrack != -1) {
			pass = true;
		} else if (musicIsAnyPlayerInAmbientRoom()) {
			if (g_Vars.tickmode != TICKMODE_CUTSCENE && AMBIENTTRACK() != stageGetAmbientTrack(g_MusicStageNum)) {
				musicQueueStopEvent(TRACKTYPE_AMBIENT);
				musicStartTemporaryAmbient(stageGetAmbientTrack(g_MusicStageNum));
				return;
			}

			pass = true;
		}
	}

	if (pass) {
		pass = func0f16d124(TRACKTYPE_AMBIENT);

		if (pass == 0 || pass == 2) {
			musicQueueStartEvent(TRACKTYPE_AMBIENT, AMBIENTTRACK(), arg0, VOLUME(g_SfxVolume));
		}
	}
}

static bool musicIsAnyPlayerInAmbientRoom(void)
{
	s32 i;

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		return false;
	}

	if (g_LvIsPaused) {
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

static void musicStartNrg(f32 arg0)
{
	musicQueueStartEvent(TRACKTYPE_NRG, stageGetNrgTrack(g_MusicStageNum), arg0, musicGetVolume());
}

/**
 * Play a specific track as a menu track.
 *
 * Used in credits and the soundtrack dialog in MP setup.
 */
void musicStartTrackAsMenu(s32 tracknum)
{
	if (tracknum != g_MenuTrack) {
		musicQueueStopEvent(TRACKTYPE_MENU);
		musicQueueStopEvent(TRACKTYPE_DEATH);
		musicQueueFadeEvent(TRACKTYPE_PRIMARY, 0.5f, FADETYPE_PAUSE);
		musicQueueFadeEvent(TRACKTYPE_NRG, 0.5f, FADETYPE_PAUSE);
		musicQueueFadeEvent(TRACKTYPE_AMBIENT, 0.5f, FADETYPE_PAUSE);
		musicQueueStartEvent(TRACKTYPE_MENU, tracknum, 0, musicGetVolume());
	}

	g_MenuTrack = tracknum;
}

/**
 * Used when starting combat simulator matches.
 */
void musicSetStageAndStartMusic(s32 stagenum)
{
	g_MusicStageNum = stagenum;

	musicStartPrimary(0);

	if (stageGetAmbientTrack(g_MusicStageNum) >= 0) {
		musicStartAmbient(0);
	}
}

/**
 * Used for solo missions.
 */
void musicSetStage(s32 stagenum)
{
	g_MusicStageNum = stagenum;
}

void musicStop(void)
{
	func0f16d430();
	musicQueueStopAllEvent();
	musicQueueType5Event();
}

void musicActivateNrg(void)
{
	if (!g_MusicNrgIsActive) {
		if (stageGetNrgTrack(g_MusicStageNum) >= 0) {
			musicQueueStopEvent(TRACKTYPE_NRG);
			musicQueueStopEvent(TRACKTYPE_MENU);
			musicQueueStopEvent(TRACKTYPE_DEATH);
			musicQueueFadeEvent(TRACKTYPE_PRIMARY, 0.5, FADETYPE_PAUSE);
			musicStartNrg(0);

			g_MusicNrgIsActive = true;
		}
	}
}

void musicDeactivateNrg(void)
{
	if (g_MusicNrgIsActive) {
		musicQueueStopEvent(TRACKTYPE_MENU);
		musicQueueStopEvent(TRACKTYPE_DEATH);
		musicQueueFadeEvent(TRACKTYPE_NRG, 1, FADETYPE_STOP);

		if (g_Vars.dontplaynrg == false) {
			musicStartPrimary(0.5);
		}

		g_MusicNrgIsActive = false;
	}
}

/**
 * Called in many places when opening a pause menu.
 */
void musicStartMenu(void)
{
	musicStartTrackAsMenu(menuChooseMusic());
}

void musicEndMenu(void)
{
	musicQueueFadeEvent(TRACKTYPE_MENU, 1, FADETYPE_STOP);

	if (func0f16d0a8(TRACKTYPE_NRG, 1)) {
		musicStartNrg(1);
	} else {
		musicStartPrimary(1);
	}

	g_MenuTrack = -1;
}

void musicStartSoloDeath(void)
{
	g_MusicSoloDeathIsPlaying = true;

	func0f16d430();

	musicQueueStopEvent(TRACKTYPE_MENU);
	musicQueueStopEvent(TRACKTYPE_DEATH);
	musicUnsetXReason(-1);
	musicQueueStopEvent(TRACKTYPE_NRG);
	musicQueueStopEvent(TRACKTYPE_PRIMARY);
	musicQueueStopEvent(TRACKTYPE_AMBIENT);
	musicQueueStartEvent(TRACKTYPE_PRIMARY, MUSIC_DEATH_SOLO, 0, VOLUME(g_SfxVolume) > musicGetVolume() ? VOLUME(g_SfxVolume) : musicGetVolume());

	musicQueueType5Event();
}

void musicStartMpDeath(void)
{
	func0f16d430();

	musicQueueStopEvent(TRACKTYPE_MENU);
	musicQueueStopEvent(TRACKTYPE_DEATH);
	musicQueueStopEvent(TRACKTYPE_AMBIENT);

	if (g_MusicNrgIsActive) {
		musicQueueFadeEvent(TRACKTYPE_NRG, 0.1f, FADETYPE_PAUSE);
	} else {
		musicQueueFadeEvent(TRACKTYPE_PRIMARY, 0.1f, FADETYPE_PAUSE);
	}

	func0f16d430();
	musicQueueStartEvent(TRACKTYPE_DEATH, MUSIC_DEATH_MP, 0, VOLUME(g_SfxVolume) > musicGetVolume() ? VOLUME(g_SfxVolume) : musicGetVolume());
	musicQueueType5Event();

	g_MusicDeathTimer240 = TICKS(1200);
	g_MusicMpDeathIsPlaying = true;

	musicQueueType5Event();
}

void musicEndDeath(void)
{
	musicQueueFadeEvent(TRACKTYPE_DEATH, 2, FADETYPE_STOP);

	if (g_MusicNrgIsActive) {
		musicStartNrg(2);
	} else {
		musicStartPrimary(2);
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
void musicPlayTrackIsolated(s32 tracknum)
{
	func0f16d430();

	musicQueueStopEvent(TRACKTYPE_MENU);
	musicQueueStopEvent(TRACKTYPE_DEATH);
	musicUnsetXReason(-1);
	musicQueueStopEvent(TRACKTYPE_NRG);
	musicQueueStopEvent(TRACKTYPE_PRIMARY);
	musicQueueStopEvent(TRACKTYPE_AMBIENT);
	musicQueueStartEvent(TRACKTYPE_PRIMARY, tracknum, 0, musicGetVolume());

	musicQueueType5Event();
}

/**
 * Restart the level's default tracks after using the isolated track above.
 *
 * It's used by the AI scripting language, specifically when ending CI training.
 */
void musicPlayDefaultTracks(void)
{
	musicQueueStopEvent(TRACKTYPE_PRIMARY);
	musicQueueStopEvent(TRACKTYPE_AMBIENT);
	musicStartPrimary(0.5f);
}

/**
 * Used by the title screen, as well as AF1's NRG theme which never ends.
 */
void musicStartTemporaryPrimary(s32 tracknum)
{
	musicQueueStopEvent(TRACKTYPE_PRIMARY);

	g_TemporaryPrimaryTrack = tracknum;

	musicStartPrimary(0.5f);
}

/**
 * Used by AI scripting on each stage.
 *
 * The cutscene track is played with a primary tracktype.
 *
 * The NRG theme will not play while a cutscene theme is active.
 */
void musicStartCutscene(s32 tracknum)
{
	u32 volume;

	musicQueueStopEvent(TRACKTYPE_MENU);
	musicQueueStopEvent(TRACKTYPE_DEATH);
	musicUnsetXReason(-1);
	musicQueueStopEvent(TRACKTYPE_NRG);
	musicQueueStopEvent(TRACKTYPE_PRIMARY);

	if (g_SfxVolume < musicGetVolume()) {
		volume = musicGetVolume();
	} else {
		volume = g_SfxVolume;
	}

	musicQueueStartEvent(TRACKTYPE_PRIMARY, tracknum, 0, volume);

	g_Vars.dontplaynrg = true;
}

/**
 * Used by AI scripting on each stage.
 */
void musicEndCutscene(void)
{
	g_Vars.dontplaynrg = false;

	if (!g_IsTitleDemo) {
		musicQueueStopEvent(TRACKTYPE_PRIMARY);
		musicQueueStopEvent(TRACKTYPE_AMBIENT);
		musicStartPrimary(0.5f);
	}
}

/**
 * Used by AI scripting, and only to set the ambient track during the Defection
 * intro and Extraction outro to traffic noises.
 */
void musicStartTemporaryAmbient(s32 tracknum)
{
	g_TemporaryAmbientTrack = tracknum;
	musicQueueStopEvent(TRACKTYPE_AMBIENT);

	musicQueueStartEvent(TRACKTYPE_AMBIENT, tracknum, 0, VOLUME(g_SfxVolume));
}

void musicEndTemporaryAmbient(void)
{
	g_TemporaryAmbientTrack = -1;
	musicQueueStopEvent(TRACKTYPE_AMBIENT);
}

void musicSetXReason(s32 reason, u32 minsecs, u32 maxsecs)
{
	if (g_AudioXReasonsActive[reason] == false) {
		g_AudioXReasonsActive[reason] = true;
		g_MusicXReasonMinDurations[reason] = minsecs * TICKS(240);
		g_MusicXReasonMaxDurations[reason] = maxsecs * TICKS(240);
	}
}

void musicUnsetXReason(s32 reason)
{
	s32 i;

	if (reason >= 0) {
		g_AudioXReasonsActive[reason] = false;
	} else {
		for (i = 0; i < 4; i++) {
			g_AudioXReasonsActive[i] = false;
			g_MusicXReasonMinDurations[i] = 0;
			g_MusicXReasonMaxDurations[i] = 0;
		}

		if (g_MusicNrgIsActive) {
			musicDeactivateNrg();
		}
	}
}

/**
 * Called by musicTick every 0.25 seconds.
 */
void musicTickAmbient(void)
{
	if (g_TemporaryAmbientTrack == -1) {
		if (musicIsAnyPlayerInAmbientRoom()) {
			musicStartAmbient(1);
		} else if (func0f16d124(TRACKTYPE_AMBIENT) == 1) {
			musicQueueFadeEvent(TRACKTYPE_AMBIENT, 1, FADETYPE_PAUSE);
		}
	} else if (stageGetAmbientTrack(g_MusicStageNum) >= 0) {
		musicStartAmbient(1);
	}
}
