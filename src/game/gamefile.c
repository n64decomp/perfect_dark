#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/bg.h"
#include "game/challenge.h"
#include "game/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "game/music.h"
#include "game/pak.h"
#include "game/options.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

void gamefileSetFlag(u32 value)
{
	pakSetBitflag(value, g_GameFile.flags, true);
}

void gamefileUnsetFlag(u32 value)
{
	pakSetBitflag(value, g_GameFile.flags, false);
}

u32 gamefileHasFlag(u32 value)
{
	return pakHasBitflag(value, g_GameFile.flags);
}

void gamefileApplyOptions(struct gamefile *file)
{
	s32 player1 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 0 : 4;
	s32 player2 = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) ? 1 : 5;

	optionsSetForwardPitch(player1, pakHasBitflag(GAMEFILEFLAG_P1_FORWARDPITCH, file->flags));
	optionsSetAutoAim(player1, pakHasBitflag(GAMEFILEFLAG_P1_AUTOAIM, file->flags));
	optionsSetAimControl(player1, pakHasBitflag(GAMEFILEFLAG_P1_AIMCONTROL, file->flags));
	optionsSetSightOnScreen(player1, pakHasBitflag(GAMEFILEFLAG_P1_SIGHTONSCREEN, file->flags));
	optionsSetLookAhead(player1, pakHasBitflag(GAMEFILEFLAG_P1_LOOKAHEAD, file->flags));
	optionsSetAmmoOnScreen(player1, pakHasBitflag(GAMEFILEFLAG_P1_AMMOONSCREEN, file->flags));
	optionsSetHeadRoll(player1, pakHasBitflag(GAMEFILEFLAG_P1_HEADROLL, file->flags));
	optionsSetShowGunFunction(player1, pakHasBitflag(GAMEFILEFLAG_P1_SHOWGUNFUNCTION, file->flags));
	optionsSetAlwaysShowTarget(player1, pakHasBitflag(GAMEFILEFLAG_P1_ALWAYSSHOWTARGET, file->flags));
	optionsSetShowZoomRange(player1, pakHasBitflag(GAMEFILEFLAG_P1_SHOWZOOMRANGE, file->flags));
	optionsSetShowMissionTime(player1, pakHasBitflag(GAMEFILEFLAG_P1_SHOWMISSIONTIME, file->flags));
	optionsSetPaintball(player1, pakHasBitflag(GAMEFILEFLAG_P1_PAINTBALL, file->flags));

	optionsSetForwardPitch(player2, pakHasBitflag(GAMEFILEFLAG_P2_FORWARDPITCH, file->flags));
	optionsSetAutoAim(player2, pakHasBitflag(GAMEFILEFLAG_P2_AUTOAIM, file->flags));
	optionsSetAimControl(player2, pakHasBitflag(GAMEFILEFLAG_P2_AIMCONTROL, file->flags));
	optionsSetSightOnScreen(player2, pakHasBitflag(GAMEFILEFLAG_P2_SIGHTONSCREEN, file->flags));
	optionsSetLookAhead(player2, pakHasBitflag(GAMEFILEFLAG_P2_LOOKAHEAD, file->flags));
	optionsSetAmmoOnScreen(player2, pakHasBitflag(GAMEFILEFLAG_P2_AMMOONSCREEN, file->flags));
	optionsSetHeadRoll(player2, pakHasBitflag(GAMEFILEFLAG_P2_HEADROLL, file->flags));
	optionsSetShowGunFunction(player2, pakHasBitflag(GAMEFILEFLAG_P2_SHOWGUNFUNCTION, file->flags));
	optionsSetAlwaysShowTarget(player2, pakHasBitflag(GAMEFILEFLAG_P2_ALWAYSSHOWTARGET, file->flags));
	optionsSetShowZoomRange(player2, pakHasBitflag(GAMEFILEFLAG_P2_SHOWZOOMRANGE, file->flags));
	optionsSetShowMissionTime(player2, pakHasBitflag(GAMEFILEFLAG_P2_SHOWMISSIONTIME, file->flags));
	optionsSetPaintball(player2, pakHasBitflag(GAMEFILEFLAG_P2_PAINTBALL, file->flags));

	g_InGameSubtitles = pakHasBitflag(GAMEFILEFLAG_INGAMESUBTITLES, file->flags);
	g_CutsceneSubtitles = pakHasBitflag(GAMEFILEFLAG_CUTSCENESUBTITLES, file->flags);

	// Duplicate
	optionsSetPaintball(player2, pakHasBitflag(GAMEFILEFLAG_P2_PAINTBALL, file->flags));

	g_Vars.langfilteron = pakHasBitflag(GAMEFILEFLAG_LANGFILTERON, file->flags);

	g_ScreenSplit = pakHasBitflag(GAMEFILEFLAG_SCREENSPLIT, file->flags);
	g_ScreenRatio = pakHasBitflag(GAMEFILEFLAG_SCREENRATIO, file->flags);

	if (pakHasBitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, file->flags)) {
		g_ScreenSize = SCREENSIZE_CINEMA;
	} else if (pakHasBitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, file->flags)) {
		g_ScreenSize = SCREENSIZE_WIDE;
	} else {
		g_ScreenSize = SCREENSIZE_FULL;
	}

	g_Vars.pendingantiplayernum = pakHasBitflag(GAMEFILEFLAG_ANTIPLAYERNUM, file->flags) ? 1 : 0;
	g_Vars.coopradaron = pakHasBitflag(GAMEFILEFLAG_COOPRADARON, file->flags) ? 1 : 0;
	g_Vars.coopfriendlyfire = pakHasBitflag(GAMEFILEFLAG_COOPFRIENDLYFIRE, file->flags) ? 1 : 0;
	g_Vars.antiradaron = pakHasBitflag(GAMEFILEFLAG_ANTIRADARON, file->flags) ? 1 : 0;
}

void gamefileLoadDefaults(struct gamefile *file)
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
	sndSetSfxVolume(0x5000);
	musicSetVolume(0x5000);
	sndSetSoundMode(SOUNDMODE_STEREO);
	optionsSetControlMode(player1, CONTROLMODE_11);
	optionsSetControlMode(player2, CONTROLMODE_11);
	pakClearAllBitflags(file->flags);

	pakSetBitflag(GAMEFILEFLAG_P1_FORWARDPITCH, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_P1_AUTOAIM, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_AIMCONTROL, file->flags, AIMCONTROL_HOLD);
	pakSetBitflag(GAMEFILEFLAG_P1_SIGHTONSCREEN, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_LOOKAHEAD, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_AMMOONSCREEN, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_HEADROLL, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWGUNFUNCTION, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_INGAMESUBTITLES, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_ALWAYSSHOWTARGET, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWZOOMRANGE, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWMISSIONTIME, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_P1_PAINTBALL, file->flags, false);

	pakSetBitflag(GAMEFILEFLAG_P2_FORWARDPITCH, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_P2_AUTOAIM, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_AIMCONTROL, file->flags, AIMCONTROL_HOLD);
	pakSetBitflag(GAMEFILEFLAG_P2_SIGHTONSCREEN, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_LOOKAHEAD, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_AMMOONSCREEN, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_HEADROLL, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWGUNFUNCTION, file->flags, true);

	pakSetBitflag(GAMEFILEFLAG_CUTSCENESUBTITLES, file->flags, false);

	pakSetBitflag(GAMEFILEFLAG_P2_ALWAYSSHOWTARGET, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWZOOMRANGE, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWMISSIONTIME, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_P2_PAINTBALL, file->flags, false);

	pakSetBitflag(GAMEFILEFLAG_SCREENSPLIT, file->flags, SCREENSPLIT_HORIZONTAL);
	pakSetBitflag(GAMEFILEFLAG_SCREENRATIO, file->flags, SCREENRATIO_NORMAL);
	pakSetBitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, file->flags, false);

	pakSetBitflag(GAMEFILEFLAG_HIRES, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_LANGFILTERON, file->flags, false);

	pakSetBitflag(GAMEFILEFLAG_FOUNDTIMEDMINE, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_FOUNDPROXYMINE, file->flags, false);
	pakSetBitflag(GAMEFILEFLAG_FOUNDREMOTEMINE, file->flags, false);

	pakSetBitflag(GAMEFILEFLAG_COOPRADARON, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_COOPFRIENDLYFIRE, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_ANTIRADARON, file->flags, true);
	pakSetBitflag(GAMEFILEFLAG_ANTIPLAYERNUM, file->flags, 1);

	file->unk1e = 0;

	for (i = 0; i < ARRAYCOUNT(file->besttimes); i++) {
		for (j = 0; j < ARRAYCOUNT(file->besttimes[0]); j++) {
			file->besttimes[i][j] = 0;
		}
	}

	for (i = 0; i < 30; i++) {
		for (j = 1; j != 5; j++) {
			challengeSetCompletedByAnyPlayerWithNumPlayers(i, j, false);
		}
	}

	challengeDetermineUnlockedFeatures();

	for (i = 0; i < ARRAYCOUNT(g_GameFile.coopcompletions); i++) {
		g_GameFile.coopcompletions[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_GameFile.firingrangescores); i++) {
		g_GameFile.firingrangescores[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_GameFile.weaponsfound); i++) {
		g_GameFile.weaponsfound[i] = 0;
	}

	gamefileApplyOptions(file);
}


s32 gamefileLoad(s32 device)
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
		savebufferClear(&buffer);
		ret = pakReadBodyAtGuid(device, g_GameFileGuid.fileid, buffer.bytes, 0);

		if (ret == 0) {
			cheatsInit();
			savebufferReadString(&buffer, g_GameFile.name, 0);
			g_GameFile.thumbnail = savebufferReadBits(&buffer, 5);
			g_GameFile.totaltime = savebufferReadBits(&buffer, 32);
			g_GameFile.autodifficulty = savebufferReadBits(&buffer, 2);
			g_GameFile.autostageindex = savebufferReadBits(&buffer, 5);

			volume = savebufferReadBits(&buffer, 6) * 4;

			if (volume >= 252) {
				volume = 255;
			}

			sndSetSfxVolume((volume & 0x1ff) * 128);

			volume = savebufferReadBits(&buffer, 6) * 4;

			if (volume >= 252) {
				volume = 255;
			}

			musicSetVolume((volume & 0x1ff) * 128);

			sndSetSoundMode(savebufferReadBits(&buffer, 2));
			optionsSetControlMode(p1index, savebufferReadBits(&buffer, 3));
			optionsSetControlMode(p2index, savebufferReadBits(&buffer, 3));

			for (i = 0; i < 10; i++) {
				g_GameFile.flags[i] = savebufferReadBits(&buffer, 8);
			}

			g_GameFile.unk1e = savebufferReadBits(&buffer, 16);

			for (i = 0; i < NUM_SOLOSTAGES; i++) {
				for (j = 0; j < 3; j++) {
					g_GameFile.besttimes[i][j] = savebufferReadBits(&buffer, 12);
				}
			}

			for (i = 0; i < 30; i++) {
				for (j = 1; j < 5; j++) {
					challengeSetCompletedByAnyPlayerWithNumPlayers(i, j, savebufferReadBits(&buffer, 1));
				}
			}

			challengeDetermineUnlockedFeatures();

			for (i = 0; i < 3; i++) {
				g_GameFile.coopcompletions[i] = savebufferReadBits(&buffer, 21);
			}

			for (i = 0; i < 9; i++) {
				s32 numbits = i == 8 ? 2 : 8;
				g_GameFile.firingrangescores[i] = savebufferReadBits(&buffer, numbits);
			}

			for (i = 0; i < 4; i++) {
				g_GameFile.weaponsfound[i] = savebufferReadBits(&buffer, 8);
			}

			if (pakHasBitflag(GAMEFILEFLAG_FOUNDTIMEDMINE, g_GameFile.flags)) {
				frSetWeaponFound(WEAPON_TIMEDMINE);
			}

			if (pakHasBitflag(GAMEFILEFLAG_FOUNDPROXYMINE, g_GameFile.flags)) {
				frSetWeaponFound(WEAPON_PROXIMITYMINE);
			}

			if (pakHasBitflag(GAMEFILEFLAG_FOUNDREMOTEMINE, g_GameFile.flags)) {
				frSetWeaponFound(WEAPON_REMOTEMINE);
			}

			func0f0d54c4(&buffer);
			gamefileApplyOptions(&g_GameFile);

			return 0;
		}

		return -1;
	}

	return -1;
}

s32 gamefileSave(s32 device, s32 fileid, u16 deviceserial)
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

	pakSetBitflag(GAMEFILEFLAG_P1_FORWARDPITCH, g_GameFile.flags, optionsGetForwardPitch(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_AUTOAIM, g_GameFile.flags, optionsGetAutoAim(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_AIMCONTROL, g_GameFile.flags, optionsGetAimControl(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_SIGHTONSCREEN, g_GameFile.flags, optionsGetSightOnScreen(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_LOOKAHEAD, g_GameFile.flags, optionsGetLookAhead(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_AMMOONSCREEN, g_GameFile.flags, optionsGetAmmoOnScreen(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_HEADROLL, g_GameFile.flags, optionsGetHeadRoll(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWGUNFUNCTION, g_GameFile.flags, optionsGetShowGunFunction(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_ALWAYSSHOWTARGET, g_GameFile.flags, optionsGetAlwaysShowTarget(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWZOOMRANGE, g_GameFile.flags, optionsGetShowZoomRange(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_SHOWMISSIONTIME, g_GameFile.flags, optionsGetShowMissionTime(p1index));
	pakSetBitflag(GAMEFILEFLAG_P1_PAINTBALL, g_GameFile.flags, optionsGetPaintball(p1index));

	pakSetBitflag(GAMEFILEFLAG_P2_FORWARDPITCH, g_GameFile.flags, optionsGetForwardPitch(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_AUTOAIM, g_GameFile.flags, optionsGetAutoAim(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_AIMCONTROL, g_GameFile.flags, optionsGetAimControl(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_SIGHTONSCREEN, g_GameFile.flags, optionsGetSightOnScreen(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_LOOKAHEAD, g_GameFile.flags, optionsGetLookAhead(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_AMMOONSCREEN, g_GameFile.flags, optionsGetAmmoOnScreen(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_HEADROLL, g_GameFile.flags, optionsGetHeadRoll(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWGUNFUNCTION, g_GameFile.flags, optionsGetShowGunFunction(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_ALWAYSSHOWTARGET, g_GameFile.flags, optionsGetAlwaysShowTarget(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWZOOMRANGE, g_GameFile.flags, optionsGetShowZoomRange(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_SHOWMISSIONTIME, g_GameFile.flags, optionsGetShowMissionTime(p2index));
	pakSetBitflag(GAMEFILEFLAG_P2_PAINTBALL, g_GameFile.flags, optionsGetPaintball(p2index));

	pakSetBitflag(GAMEFILEFLAG_SCREENSPLIT, g_GameFile.flags, g_ScreenSplit);
	pakSetBitflag(GAMEFILEFLAG_SCREENRATIO, g_GameFile.flags, g_ScreenRatio);

	pakSetBitflag(GAMEFILEFLAG_SCREENSIZE_WIDE, g_GameFile.flags, g_ScreenSize == SCREENSIZE_WIDE);
	pakSetBitflag(GAMEFILEFLAG_SCREENSIZE_CINEMA, g_GameFile.flags, g_ScreenSize == SCREENSIZE_CINEMA);

	pakSetBitflag(GAMEFILEFLAG_HIRES, g_GameFile.flags, 0);
	pakSetBitflag(GAMEFILEFLAG_INGAMESUBTITLES, g_GameFile.flags, g_InGameSubtitles);
	pakSetBitflag(GAMEFILEFLAG_CUTSCENESUBTITLES, g_GameFile.flags, g_CutsceneSubtitles);
	pakSetBitflag(GAMEFILEFLAG_LANGFILTERON, g_GameFile.flags, g_Vars.langfilteron);

	pakSetBitflag(GAMEFILEFLAG_FOUNDTIMEDMINE, g_GameFile.flags, frIsWeaponFound(WEAPON_TIMEDMINE));
	pakSetBitflag(GAMEFILEFLAG_FOUNDPROXYMINE, g_GameFile.flags, frIsWeaponFound(WEAPON_PROXIMITYMINE));
	pakSetBitflag(GAMEFILEFLAG_FOUNDREMOTEMINE, g_GameFile.flags, frIsWeaponFound(WEAPON_REMOTEMINE));

	pakSetBitflag(GAMEFILEFLAG_ANTIPLAYERNUM, g_GameFile.flags, g_Vars.pendingantiplayernum == 1);
	pakSetBitflag(GAMEFILEFLAG_COOPRADARON, g_GameFile.flags, g_Vars.coopradaron == 1);
	pakSetBitflag(GAMEFILEFLAG_COOPFRIENDLYFIRE, g_GameFile.flags, g_Vars.coopfriendlyfire == 1);
	pakSetBitflag(GAMEFILEFLAG_ANTIRADARON, g_GameFile.flags, g_Vars.antiradaron == 1);

	if (device >= 0) {
		savebufferClear(&buffer);
		func0f0d55a4(&buffer, g_GameFile.name);

		savebufferOr(&buffer, g_GameFile.thumbnail, 5);
		savebufferOr(&buffer, g_GameFile.totaltime, 32);
		savebufferOr(&buffer, g_GameFile.autodifficulty, 2);
		savebufferOr(&buffer, g_GameFile.autostageindex, 5);

		value = VOLUME(g_SfxVolume) >> 7;
		savebufferOr(&buffer, value >> 2, 6);

		value = musicGetVolume() >> 7;
		savebufferOr(&buffer, value >> 2, 6);

		value = g_SoundMode;
		savebufferOr(&buffer, value, 2);

		savebufferOr(&buffer, g_PlayerConfigsArray[p1index].controlmode, 3);
		savebufferOr(&buffer, g_PlayerConfigsArray[p2index].controlmode, 3);

		for (i = 0; i < 10; i++) {
			savebufferOr(&buffer, g_GameFile.flags[i], 8);
		}

		savebufferOr(&buffer, g_GameFile.unk1e, 16);

		for (i = 0; i < NUM_SOLOSTAGES; i++) {
			for (j = 0; j < 3; j++) {
				savebufferOr(&buffer, g_GameFile.besttimes[i][j], 12);
			}
		}

		for (i = 0; i < 30; i++) {
			for (j = 1; j < 5; j++) {
				savebufferOr(&buffer, challengeIsCompletedByAnyPlayerWithNumPlayers(i, j), 1);
			}
		}

		for (i = 0; i < 3; i++) {
			savebufferOr(&buffer, g_GameFile.coopcompletions[i], 21);
		}

		for (i = 0; i < 9; i++) {
			savebufferOr(&buffer, g_GameFile.firingrangescores[i], i == 8 ? 2 : 8);
		}

		for (i = 0; i < 4; i++) {
			savebufferOr(&buffer, g_GameFile.weaponsfound[i], 8);
		}

		func0f0d54c4(&buffer);

		ret = pakSaveAtGuid(device, fileid, PAKFILETYPE_GAME, buffer.bytes, &newfileid, 0);

		if (ret == 0) {
			g_GameFileGuid.fileid = newfileid;
			g_GameFileGuid.deviceserial = deviceserial;

			return 0;
		}

		return -1;
	}

	return -1;
}

void gamefileGetOverview(char *arg0, char *name, u8 *stage, u8 *difficulty, u32 *time)
{
	struct savebuffer buffer;

	func0f0d5484(&buffer, arg0, 15);
	savebufferReadString(&buffer, name, false);

	*stage = savebufferReadBits(&buffer, 5);

	*time = savebufferReadBits(&buffer, 32);

	*difficulty = savebufferReadBits(&buffer, 2);
}
