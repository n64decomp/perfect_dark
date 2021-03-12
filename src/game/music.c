#include <ultra64.h>
#include "constants.h"
#include "game/game_0f09f0.h"
#include "game/core.h"
#include "game/music.h"
#include "game/game_176080.h"
#include "gvars/gvars.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_11420.h"
#include "data.h"
#include "types.h"

s32 g_MusicStageNum;
u32 var800aa5d4;
struct var800aa5d8 var800aa5d8[40];
struct var800aaa38 var800aaa38[3];
u32 g_AudioXReasonsActive[4];
u32 var800aaa78[4];
u32 g_AudioXReasonDurations[4];

s32 g_MenuTrack = -1;
u32 var800840c4 = 0x00000000;
s32 g_TemporaryPrimaryTrack = -1;
s32 g_TemporaryAmbientTrack = -1;
s32 var800840d0 = -1;
u32 var800840d4 = 0x00000000;
u32 var800840d8 = 0x00000000;
s32 var800840dc = 0;
u32 var800840e0 = 0x0000000f;
u32 var800840e4 = 0x00000000;
s32 var800840e8 = 0;
u16 var800840ec = 0x5000;
u32 var800840f0 = 0x00000000;
u32 var800840f4 = 0x00000000;
u32 var800840f8 = PAL ? 100 : 120;
u32 var800840fc = 0x00000000;

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

u16 musicGetVolume(void)
{
	u32 volume;

	if (g_Vars.stagenum == STAGE_CREDITS) {
		return 0x5000;
	}

	if (var800840ec < 0x5000) {
		volume = var800840ec;
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
		if (var800aaa38[i].tracktype != 0 && var800aaa38[i].tracktype != TRACKTYPE_AMBIENT) {
			func0000fd9c(&var80094ed8[i], volume);
		}
	}

	var800840ec = volume;
}

bool func0f16d0a8(s32 tracktype, s32 arg1)
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

s32 func0f16d124(s32 tracktype)
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

s32 func0f16d180(s32 tracktype)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].tracktype == tracktype) {
			return i;
		}
	}

	return -1;
}

void musicStart(u32 tracktype, u32 tracknum, f32 arg2, u16 volume)
{
	if (!g_Silent) {
		var800aa5d8[var800840c4].tracktype = tracktype;
		var800aa5d8[var800840c4].tracknum = tracknum;
		var800aa5d8[var800840c4].unk0c = arg2;
		var800aa5d8[var800840c4].volume = volume;
		var800aa5d8[var800840c4].unk12 = 1;
		var800aa5d8[var800840c4].unk14 = var800840d4++;
		var800aa5d8[var800840c4].unk18 = 0;
		var800aa5d8[var800840c4].unk16 = 0;
		var800840c4++;
	}
}

void musicEnd(s32 tracktype)
{
	if (!g_Silent) {
		var800aa5d8[var800840c4].tracktype = tracktype;
		var800aa5d8[var800840c4].unk12 = 2;
		var800aa5d8[var800840c4].unk14 = var800840d4++;
		var800aa5d8[var800840c4].unk18 = 0;
		var800aa5d8[var800840c4].unk16 = 0;
		var800840c4++;
	}
}

void func0f16d2ac(s32 tracktype, f32 arg1, s32 arg2)
{
	if (!g_Silent) {
		var800aa5d8[var800840c4].tracktype = tracktype;
		var800aa5d8[var800840c4].unk0c = arg1;
		var800aa5d8[var800840c4].unk08 = arg2;
		var800aa5d8[var800840c4].unk12 = 3;
		var800aa5d8[var800840c4].unk14 = var800840d4++;
		var800aa5d8[var800840c4].unk18 = 0;
		var800aa5d8[var800840c4].unk16 = 0;
		var800840c4++;
	}
}

void func0f16d324(void)
{
	s32 i;

	if (!g_Silent) {
		for (i = 0; i < 4; i++) {
			g_AudioXReasonsActive[i] = 0;
			var800aaa78[i] = 0;
			g_AudioXReasonDurations[i] = 0;
		}

		func0f16d430();
		func0f16d3d0();
		func0f16d44c();

		var800840e8 = 0;
		var800840f0 = 0;
		g_MenuTrack = -1;
		g_TemporaryPrimaryTrack = -1;
		g_TemporaryAmbientTrack = -1;
		var800840d8 = 0;
	}
}

void func0f16d3d0(void)
{
	var800aa5d8[0].tracktype = TRACKTYPE_6;
	var800aa5d8[0].unk12 = 4;
	var800aa5d8[0].unk14 = var800840d4++;
	var800aa5d8[0].unk18 = 0;
	var800aa5d8[0].unk16 = 0;

	var800840c4 = 1;

	func0001190c();
}

void func0f16d430(void)
{
	var800840d0 = var800840e0;
	var800840e0 = 0;
}

void func0f16d44c(void)
{
	var800aa5d8[var800840c4].tracktype = TRACKTYPE_6;
	var800aa5d8[var800840c4].unk12 = 5;
	var800aa5d8[var800840c4].unk14 = var800840d4++;
	var800aa5d8[var800840c4].tracknum = var800840d0;
	var800840c4++;

	var800aa5d8[0].unk18 = 0;
	var800aa5d8[0].unk16 = 0;
}

#define PRIMARYTRACK() (g_TemporaryPrimaryTrack != -1 ? g_TemporaryPrimaryTrack : stageGetPrimaryTrack(g_MusicStageNum))

void musicStartPrimary(f32 arg0)
{
	if (PRIMARYTRACK() >= 0) {
		musicStart(TRACKTYPE_PRIMARY, PRIMARYTRACK(), arg0, musicGetVolume());
	}
}

#define AMBIENTTRACK() (g_TemporaryAmbientTrack != -1 ? g_TemporaryAmbientTrack : stageGetAmbientTrack(g_MusicStageNum))

void musicStartAmbient(f32 arg0)
{
	s32 pass = false;

	if (AMBIENTTRACK() >= 0) {
		if (g_TemporaryAmbientTrack != -1) {
			pass = true;
		} else if (musicIsAnyPlayerInAmbientRoom()) {
			if (g_Vars.tickmode != TICKMODE_CUTSCENE && AMBIENTTRACK() != stageGetAmbientTrack(g_MusicStageNum)) {
				musicEnd(TRACKTYPE_AMBIENT);
				musicStartTemporary(stageGetAmbientTrack(g_MusicStageNum));
				return;
			}

			pass = true;
		}
	}

	if (pass) {
		pass = func0f16d124(TRACKTYPE_AMBIENT);

		if (pass == 0 || pass == 2) {
			musicStart(TRACKTYPE_AMBIENT, AMBIENTTRACK(), arg0, VOLUME(g_SfxVolume));
		}
	}
}

bool musicIsAnyPlayerInAmbientRoom(void)
{
	s32 i;

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		return false;
	}

	if (coreIsPaused()) {
		return false;
	}

	if (var800840e8) {
		return false;
	}

	if (var800840d8 && var800840dc) {
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

void musicStartX(f32 arg0)
{
	musicStart(TRACKTYPE_X, stageGetXTrack(g_MusicStageNum), arg0, musicGetVolume());
}

void musicStartMenu(f32 arg0)
{
	musicStart(TRACKTYPE_MENU, menuChooseMusic(), arg0, musicGetVolume());
}

void musicStartMenu2(s32 tracknum)
{
	if (tracknum != g_MenuTrack) {
		musicEnd(TRACKTYPE_MENU);
		musicEnd(TRACKTYPE_DEATH);
		func0f16d2ac(TRACKTYPE_PRIMARY, 0.5f, 1);
		func0f16d2ac(TRACKTYPE_X, 0.5f, 1);
		func0f16d2ac(TRACKTYPE_AMBIENT, 0.5f, 1);
		musicStart(TRACKTYPE_MENU, tracknum, 0, musicGetVolume());
	}

	g_MenuTrack = tracknum;
}

void musicSetStageAndStartMusic(s32 stagenum)
{
	g_MusicStageNum = stagenum;

	musicStartPrimary(0);

	if (stageGetAmbientTrack(g_MusicStageNum) >= 0) {
		musicStartAmbient(0);
	}
}

void musicSetStage(s32 stagenum)
{
	g_MusicStageNum = stagenum;
}

void musicReset(void)
{
	func0f16d430();
	func0f16d3d0();
	func0f16d44c();
}

void func0f16da2c(void)
{
	if (var800840d8 == 0 && stageGetXTrack(g_MusicStageNum) >= 0) {
		musicEnd(TRACKTYPE_X);
		musicEnd(TRACKTYPE_MENU);
		musicEnd(TRACKTYPE_DEATH);
		func0f16d2ac(TRACKTYPE_PRIMARY, 0.5, 1);
		musicStartX(0);

		var800840d8 = 1;
	}
}

void func0f16daa4(void)
{
	if (var800840d8) {
		musicEnd(TRACKTYPE_MENU);
		musicEnd(TRACKTYPE_DEATH);
		func0f16d2ac(TRACKTYPE_X, 1, 0);

		if (g_Vars.dontplaynrg == false) {
			musicStartPrimary(0.5);
		}

		var800840d8 = 0;
	}
}

void musicStartForMenu(void)
{
	musicStartMenu2(menuChooseMusic());
}

void musicResumeAfterUnpause(void)
{
	func0f16d2ac(TRACKTYPE_MENU, 1, 0);

	if (func0f16d0a8(TRACKTYPE_X, 1)) {
		musicStartX(1);
	} else {
		musicStartPrimary(1);
	}

	g_MenuTrack = -1;
}

void musicStartSoloDeath(void)
{
	var800840e8 = 1;

	func0f16d430();
	musicEnd(TRACKTYPE_MENU);
	musicEnd(TRACKTYPE_DEATH);
	musicUnsetXReason(-1);
	musicEnd(TRACKTYPE_X);
	musicEnd(TRACKTYPE_PRIMARY);
	musicEnd(TRACKTYPE_AMBIENT);
	musicStart(TRACKTYPE_PRIMARY, MUSIC_DEATH_SOLO, 0, VOLUME(g_SfxVolume) > musicGetVolume() ? VOLUME(g_SfxVolume) : musicGetVolume());
	func0f16d44c();
}

void musicStartMpDeath(f32 arg0)
{
	func0f16d430();
	musicStart(TRACKTYPE_DEATH, MUSIC_DEATH_MP, arg0, VOLUME(g_SfxVolume) > musicGetVolume() ? VOLUME(g_SfxVolume) : musicGetVolume());
	func0f16d44c();
}

void func0f16dd14(void)
{
	func0f16d430();
	musicEnd(TRACKTYPE_MENU);
	musicEnd(TRACKTYPE_DEATH);
	musicEnd(TRACKTYPE_AMBIENT);

	if (var800840d8) {
		func0f16d2ac(TRACKTYPE_X, 0.1f, 1);
	} else {
		func0f16d2ac(TRACKTYPE_PRIMARY, 0.1f, 1);
	}

	musicStartMpDeath(0);
	var800840f0 = PALDOWN(1200);
	var800840dc = 1;
	func0f16d44c();
}

void func0f16ddb0(void)
{
	func0f16d2ac(TRACKTYPE_DEATH, 2, 0);

	if (var800840d8) {
		musicStartX(2);
	} else {
		musicStartPrimary(2);
	}

	var800840dc = 0;
}

void musicPlayTrackIsolated(s32 tracknum)
{
	func0f16d430();
	musicEnd(TRACKTYPE_MENU);
	musicEnd(TRACKTYPE_DEATH);
	musicUnsetXReason(-1);
	musicEnd(TRACKTYPE_X);
	musicEnd(TRACKTYPE_PRIMARY);
	musicEnd(TRACKTYPE_AMBIENT);
	musicStart(TRACKTYPE_PRIMARY, tracknum, 0, musicGetVolume());
	func0f16d44c();
}

void musicPlayDefaultTracks(void)
{
	musicEnd(TRACKTYPE_PRIMARY);
	musicEnd(TRACKTYPE_AMBIENT);
	musicStartPrimary(0.5f);
}

void musicStartTemporaryPrimary(s32 tracknum)
{
	musicEnd(TRACKTYPE_PRIMARY);

	g_TemporaryPrimaryTrack = tracknum;

	musicStartPrimary(0.5f);
}

void musicStartCutscene(s32 tracknum)
{
	u32 volume;

	musicEnd(TRACKTYPE_MENU);
	musicEnd(TRACKTYPE_DEATH);
	musicUnsetXReason(-1);
	musicEnd(TRACKTYPE_X);
	musicEnd(TRACKTYPE_PRIMARY);

	if (g_SfxVolume < musicGetVolume()) {
		volume = musicGetVolume();
	} else {
		volume = g_SfxVolume;
	}

	musicStart(TRACKTYPE_PRIMARY, tracknum, 0, volume);

	g_Vars.dontplaynrg = true;
}

void musicEndCutscene(void)
{
	g_Vars.dontplaynrg = false;

	if (var800624a4 == 0) {
		musicEnd(TRACKTYPE_PRIMARY);
		musicEnd(TRACKTYPE_AMBIENT);
		musicStartPrimary(0.5f);
	}
}

void musicStartTemporary(s32 tracknum)
{
	g_TemporaryAmbientTrack = tracknum;
	musicEnd(TRACKTYPE_AMBIENT);

	musicStart(TRACKTYPE_AMBIENT, tracknum, 0, VOLUME(g_SfxVolume));
}

void musicEndAmbient(void)
{
	g_TemporaryAmbientTrack = -1;
	musicEnd(TRACKTYPE_AMBIENT);
}

void musicSetXReason(s32 reason, u32 arg1, u32 duration)
{
	if (g_AudioXReasonsActive[reason] == false) {
		g_AudioXReasonsActive[reason] = true;
		var800aaa78[reason] = arg1 * PALDOWN(240);
		g_AudioXReasonDurations[reason] = duration * PALDOWN(240);
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
			var800aaa78[i] = 0;
			g_AudioXReasonDurations[i] = 0;
		}

		if (var800840d8) {
			func0f16daa4();
		}
	}
}

void func0f16e138(void)
{
	if (g_TemporaryAmbientTrack == -1) {
		if (musicIsAnyPlayerInAmbientRoom()) {
			musicStartAmbient(1);
		} else if (func0f16d124(TRACKTYPE_AMBIENT) == 1) {
			func0f16d2ac(TRACKTYPE_AMBIENT, 1, 1);
		}
	} else if (stageGetAmbientTrack(g_MusicStageNum) >= 0) {
		musicStartAmbient(1);
	}
}

void func0f16e1cc(void)
{
	// empty
}
