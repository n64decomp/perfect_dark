#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02a0e0.h"
#include "game/data/data_02da90.h"
#include "game/game_0f09f0.h"
#include "game/game_167ae0.h"
#include "game/game_16cfa0.h"
#include "game/game_176080.h"
#include "gvars/gvars.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_11420.h"
#include "types.h"

u16 audioGetVolume(void)
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

void func0f16cfe8(u16 volume)
{
	s32 i;

	if (volume > 0x5000) {
		volume = 0x5000;
	}

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].unk00 != 0 && var800aaa38[i].unk00 != 5) {
			func0000fd9c(&var80094ed8[i], volume);
		}
	}

	var800840ec = volume;
}

bool func0f16d0a8(s32 arg0, s32 arg1)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].unk00 == arg0) {
			switch (arg1) {
			case 0: return var800aaa38[i].unk04 <= 0;
			case 1: return var800aaa38[i].unk04;
			case 2: return var800aaa38[i].unk08;
			}
		}
	}

	return false;
}

s32 func0f16d124(s32 arg0)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].unk00 == arg0) {
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

s32 func0f16d180(s32 arg0)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800aaa38); i++) {
		if (var800aaa38[i].unk00 == arg0) {
			return i;
		}
	}

	return -1;
}

void func0f16d1bc(u32 arg0, u32 tracknum, f32 arg2, u16 volume)
{
	if (var8005dda0 == 0) {
		var800aa5d8[var800840c4].unk00 = arg0;
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

void func0f16d240(s32 arg0)
{
	if (var8005dda0 == 0) {
		var800aa5d8[var800840c4].unk00 = arg0;
		var800aa5d8[var800840c4].unk12 = 2;
		var800aa5d8[var800840c4].unk14 = var800840d4++;
		var800aa5d8[var800840c4].unk18 = 0;
		var800aa5d8[var800840c4].unk16 = 0;
		var800840c4++;
	}
}

void func0f16d2ac(s32 arg0, f32 arg1, s32 arg2)
{
	if (var8005dda0 == 0) {
		var800aa5d8[var800840c4].unk00 = arg0;
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

	if (var8005dda0 == 0) {
		for (i = 0; i < 4; i++) {
			var800aaa68[i] = 0;
			var800aaa78[i] = 0;
			var800aaa88[i] = 0;
		}

		func0f16d430();
		func0f16d3d0();
		func0f16d44c();

		var800840e8 = 0;
		var800840f0 = 0;
		g_AudioCurrentBgMusicNum = -1;
		var800840c8 = -1;
		var800840cc = -1;
		var800840d8 = 0;
	}
}

void func0f16d3d0(void)
{
	var800aa5d8[0].unk00 = 6;
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
	var800aa5d8[var800840c4].unk00 = 6;
	var800aa5d8[var800840c4].unk12 = 5;
	var800aa5d8[var800840c4].unk14 = var800840d4++;
	var800aa5d8[var800840c4].tracknum = var800840d0;
	var800840c4++;

	var800aa5d8[0].unk18 = 0;
	var800aa5d8[0].unk16 = 0;
}

#define TRACKNUM2() (var800840c8 != -1 ? var800840c8 : stageGetPrimaryTrack(var800aa5d0))

void func0f16d4b8(f32 arg0)
{
	if (TRACKNUM2() >= 0) {
		func0f16d1bc(1, TRACKNUM2(), arg0, audioGetVolume());
	}
}

#define TRACKNUM() (var800840cc != -1 ? var800840cc : stageGetAmbientTrack(var800aa5d0))

void func0f16d548(f32 arg0)
{
	s32 pass = false;

	if (TRACKNUM() >= 0) {
		if (var800840cc != -1) {
			pass = true;
		} else if (audioIsAnyPlayerInRoomWithFlag4000()) {
			if (g_Vars.tickmode != TICKMODE_6 && TRACKNUM() != stageGetAmbientTrack(var800aa5d0)) {
				func0f16d240(5);
				audioSetAuxTrack(stageGetAmbientTrack(var800aa5d0));
				return;
			}

			pass = true;
		}
	}

	if (pass) {
		pass = func0f16d124(5);

		if (pass == 0 || pass == 2) {
			func0f16d1bc(5, TRACKNUM(), arg0, VOLUME(g_SfxVolume));
		}
	}
}

bool audioIsAnyPlayerInRoomWithFlag4000(void)
{
	s32 i;

	if (g_Vars.tickmode == TICKMODE_6) {
		return false;
	}

	if (soloIsPaused()) {
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

			if (g_Rooms[g_Vars.players[i]->prop->rooms[0]].flags & ROOMFLAG_4000) {
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

void func0f16d89c(f32 arg0)
{
	func0f16d1bc(2, stageGetXTrack(var800aa5d0), arg0, audioGetVolume());
}

void func0f16d8e0(f32 arg0)
{
	func0f16d1bc(3, menuChooseMusic(), arg0, audioGetVolume());
}

void audioSetBgMusic(s32 tracknum)
{
	if (tracknum != g_AudioCurrentBgMusicNum) {
		func0f16d240(3);
		func0f16d240(4);
		func0f16d2ac(1, 0.5f, 1);
		func0f16d2ac(2, 0.5f, 1);
		func0f16d2ac(5, 0.5f, 1);
		func0f16d1bc(3, tracknum, 0, audioGetVolume());
	}

	g_AudioCurrentBgMusicNum = tracknum;
}

void func0f16d9a8(s32 stagenum)
{
	var800aa5d0 = stagenum;

	func0f16d4b8(0);

	if (stageGetAmbientTrack(var800aa5d0) >= 0) {
		func0f16d548(0);
	}
}

void func0f16d9f0(s32 stagenum)
{
	var800aa5d0 = stagenum;
}

void func0f16d9fc(void)
{
	func0f16d430();
	func0f16d3d0();
	func0f16d44c();
}

void func0f16da2c(void)
{
	if (var800840d8 == 0 && stageGetXTrack(var800aa5d0) >= 0) {
		func0f16d240(2);
		func0f16d240(3);
		func0f16d240(4);
		func0f16d2ac(1, 0.5, 1);
		func0f16d89c(0);

		var800840d8 = 1;
	}
}

void func0f16daa4(void)
{
	if (var800840d8) {
		func0f16d240(3);
		func0f16d240(4);
		func0f16d2ac(2, 1, 0);

		if (g_Vars.unk0004c8 == 0) {
			func0f16d4b8(0.5);
		}

		var800840d8 = 0;
	}
}

void audioSetBgMusicForMenu(void)
{
	audioSetBgMusic(menuChooseMusic());
}

void func0f16db3c(void)
{
	func0f16d2ac(3, 1, 0);

	if (func0f16d0a8(2, 1)) {
		func0f16d89c(1);
	} else {
		func0f16d4b8(1);
	}

	g_AudioCurrentBgMusicNum = -1;
}

void audioPlaySoloDeathTrack(void)
{
	var800840e8 = 1;

	func0f16d430();
	func0f16d240(3);
	func0f16d240(4);
	audioStopTrack(-1);
	func0f16d240(2);
	func0f16d240(1);
	func0f16d240(5);
	func0f16d1bc(1, MUSIC_DEATH_SOLO, 0, VOLUME(g_SfxVolume) > audioGetVolume() ? VOLUME(g_SfxVolume) : audioGetVolume());
	func0f16d44c();
}

void audioPlayMpDeathTrack(f32 arg0)
{
	func0f16d430();
	func0f16d1bc(4, MUSIC_DEATH_MP, arg0, VOLUME(g_SfxVolume) > audioGetVolume() ? VOLUME(g_SfxVolume) : audioGetVolume());
	func0f16d44c();
}

void func0f16dd14(void)
{
	func0f16d430();
	func0f16d240(3);
	func0f16d240(4);
	func0f16d240(5);

	if (var800840d8) {
		func0f16d2ac(2, 0.1f, 1);
	} else {
		func0f16d2ac(1, 0.1f, 1);
	}

	audioPlayMpDeathTrack(0);
	var800840f0 = 1200;
	var800840dc = 1;
	func0f16d44c();
}

void func0f16ddb0(void)
{
	func0f16d2ac(4, 2, 0);

	if (var800840d8) {
		func0f16d89c(2);
	} else {
		func0f16d4b8(2);
	}

	var800840dc = 0;
}

void audioPlayTrack(s32 tracknum)
{
	func0f16d430();
	func0f16d240(3);
	func0f16d240(4);
	audioStopTrack(-1);
	func0f16d240(2);
	func0f16d240(1);
	func0f16d240(5);
	func0f16d1bc(1, tracknum, 0, audioGetVolume());
	func0f16d44c();
}

void audioRestartTrack(void)
{
	func0f16d240(1);
	func0f16d240(5);
	func0f16d4b8(0.5f);
}

void func0f16deb8(s32 tracknum)
{
	func0f16d240(1);

	var800840c8 = tracknum;

	func0f16d4b8(0.5f);
}

void audioSetTrack(s32 tracknum)
{
	u32 volume;

	func0f16d240(3);
	func0f16d240(4);
	audioStopTrack(-1);
	func0f16d240(2);
	func0f16d240(1);

	if (g_SfxVolume < audioGetVolume()) {
		volume = audioGetVolume();
	} else {
		volume = g_SfxVolume;
	}

	func0f16d1bc(1, tracknum, 0, volume);

	g_Vars.unk0004c8 = 1;
}

void audioRestartDefaultTrack(void)
{
	g_Vars.unk0004c8 = 0;

	if (var800624a4 == 0) {
		func0f16d240(1);
		func0f16d240(5);
		func0f16d4b8(0.5f);
	}
}

void audioSetAuxTrack(s32 tracknum)
{
	var800840cc = tracknum;
	func0f16d240(5);

	func0f16d1bc(5, tracknum, 0, VOLUME(g_SfxVolume));
}

void audioRestartAuxTrack(void)
{
	var800840cc = -1;
	func0f16d240(5);
}

void audioPlayXTrack(s32 index, u32 arg1, u32 duration)
{
	if (var800aaa68[index] == false) {
		var800aaa68[index] = true;
		var800aaa78[index] = arg1 * 240;
		var800aaa88[index] = duration * 240;
	}
}

void audioStopTrack(s32 index)
{
	s32 i;

	if (index >= 0) {
		var800aaa68[index] = false;
	} else {
		for (i = 0; i < 4; i++) {
			var800aaa68[i] = false;
			var800aaa78[i] = 0;
			var800aaa88[i] = 0;
		}

		if (var800840d8) {
			func0f16daa4();
		}
	}
}

void func0f16e138(void)
{
	if (var800840cc == -1) {
		if (audioIsAnyPlayerInRoomWithFlag4000()) {
			func0f16d548(1);
		} else if (func0f16d124(5) == 1) {
			func0f16d2ac(5, 1, 1);
		}
	} else {
		if (stageGetAmbientTrack(var800aa5d0) >= 0) {
			func0f16d548(1);
		}
	}
}

void func0f16e1cc(void)
{
	// empty
}
