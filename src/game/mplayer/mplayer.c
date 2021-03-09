#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/title.h"
#include "game/game_01b0a0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b69d0.h"
#include "game/game_0d4690.h"
#include "game/game_0f09f0.h"
#include "game/game_127910.h"
#include "game/game_1531a0.h"
#include "game/core.h"
#include "game/music.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/mpstats.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "gvars/gvars.h"
#include "lib/args.h"
#include "lib/lib_09a80.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

// bss
struct chrdata *g_MpPlayerChrs[MAX_MPCHRS];
struct mpchr *var800ac500[MAX_MPCHRS];
s32 g_MpNumPlayers;
u32 var800ac534;
struct mpsim g_MpSimulants[MAX_SIMULANTS];
u8 g_MpSimulantDifficultiesPerNumPlayers[32];
struct mpplayer g_MpPlayers[6];
u8 g_AmBotCommands[16];
struct mpsetup g_MpSetup;
struct savefile_setup g_MpSetupSaveFile;
u32 var800acc1c;
struct mplockinfo g_MpLockInfo;
u32 var800acc28[18];

// Forward declaractions
struct mpweaponset g_MpWeaponSets[12];
u32 var800874c8;

const char var7f1b8a00[] = "||||||||||||| Starting game... players %d\n";

s32 var80087260 = 0x00000000;
u32 var80087264 = 0x00000000;

struct mpweapon g_MpWeapons[0x27] = {
	/*0x00*/ { WEAPON_NONE,             0x00, 0x00, 0x00, 0x00, 1, 0,                                MODEL_CHRTT33,          0x0100 },
	/*0x01*/ { WEAPON_FALCON2,          0x01, 0x50, 0x00, 0x00, 1, 0,                                MODEL_CHRFALCON2,       0x0100 },
	/*0x02*/ { WEAPON_FALCON2_SILENCER, 0x01, 0x50, 0x00, 0x00, 1, MPFEATURE_WEAPON_FALCON2SILENCED, MODEL_CHRFALCON2SIL,    0x0100 },
	/*0x03*/ { WEAPON_FALCON2_SCOPE,    0x01, 0x50, 0x00, 0x00, 1, MPFEATURE_WEAPON_FALCON2SCOPE,    MODEL_CHRFALCON2SCOPE,  0x0100 },
	/*0x04*/ { WEAPON_MAGSEC4,          0x01, 0x50, 0x00, 0x00, 1, 0,                                MODEL_CHRLEEGUN1,       0x0100 },
	/*0x05*/ { WEAPON_MAULER,           0x01, 0x5c, 0x00, 0x00, 1, MPFEATURE_WEAPON_MAULER,          MODEL_CHRMAULER,        0x0100 },
	/*0x06*/ { WEAPON_PHOENIX,          0x01, 0x40, 0x00, 0x00, 1, MPFEATURE_WEAPON_PHOENIX,         MODEL_CHRMAIANPISTOL,   0x0100 },
	/*0x07*/ { WEAPON_DY357MAGNUM,      0x0a, 0x32, 0x00, 0x00, 1, 0,                                MODEL_CHRDY357,         0x0100 },
	/*0x08*/ { WEAPON_DY357LX,          0x0a, 0x32, 0x00, 0x00, 1, MPFEATURE_WEAPON_DY357LX,         MODEL_CHRDY357TRENT,    0x0100 },
	/*0x09*/ { WEAPON_CMP150,           0x02, 0x64, 0x00, 0x00, 1, 0,                                MODEL_CHRCMP150,        0x0100 },
	/*0x0a*/ { WEAPON_CYCLONE,          0x02, 0x96, 0x00, 0x00, 1, 0,                                MODEL_CHRCYCLONE,       0x0100 },
	/*0x0b*/ { WEAPON_CALLISTONTG,      0x02, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_CALLISTO,        MODEL_CHRMAIANSMG,      0x0100 },
	/*0x0c*/ { WEAPON_RCP120,           0x02, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_RCP120,          MODEL_CHRRCP120,        0x0100 },
	/*0x0d*/ { WEAPON_LAPTOPGUN,        0x02, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_LAPTOPGUN,       MODEL_CHRPCGUN,         0x0100 },
	/*0x0e*/ { WEAPON_DRAGON,           0x04, 0x96, 0x00, 0x00, 1, 0,                                MODEL_CHRDRAGON,        0x0100 },
	/*0x0f*/ { WEAPON_K7AVENGER,        0x04, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_K7AVENGER,       MODEL_CHRAVENGER,       0x0100 },
	/*0x10*/ { WEAPON_AR34,             0x04, 0x64, 0x00, 0x00, 1, 0,                                MODEL_CHRAR34,          0x0100 },
	/*0x11*/ { WEAPON_SUPERDRAGON,      0x04, 0x96, 0x0b, 0x10, 1, MPFEATURE_WEAPON_SUPERDRAGON,     MODEL_CHRSUPERDRAGON,   0x0100 },
	/*0x12*/ { WEAPON_SHOTGUN,          0x05, 0x10, 0x00, 0x00, 1, MPFEATURE_WEAPON_SHOTGUN,         MODEL_CHRSHOTGUN,       0x0100 },
	/*0x13*/ { WEAPON_REAPER,           0x0f, 0xc8, 0x00, 0x00, 1, MPFEATURE_WEAPON_REAPER,          MODEL_CHRSKMINIGUN,     0x0100 },
	/*0x14*/ { WEAPON_SNIPERRIFLE,      0x04, 0x32, 0x00, 0x00, 1, 0,                                MODEL_CHRSNIPERRIFLE,   0x0100 },
	/*0x15*/ { WEAPON_FARSIGHTXR20,     0x06, 0x0a, 0x00, 0x00, 1, MPFEATURE_WEAPON_FARSIGHT,        MODEL_CHRZ2020,         0x0100 },
	/*0x16*/ { WEAPON_DEVASTATOR,       0x0b, 0x10, 0x00, 0x00, 1, MPFEATURE_WEAPON_DEVASTATOR,      MODEL_CHRDEVASTATOR,    0x0100 },
	/*0x17*/ { WEAPON_ROCKETLAUNCHER,   0x08, 0x03, 0x00, 0x00, 1, 0,                                MODEL_CHRDYROCKET,      0x0100 },
	/*0x18*/ { WEAPON_SLAYER,           0x08, 0x03, 0x00, 0x00, 1, MPFEATURE_WEAPON_SLAYER,          MODEL_CHRSKROCKET,      0x0100 },
	/*0x19*/ { WEAPON_COMBATKNIFE,      0x09, 0x05, 0x00, 0x00, 1, 0,                                MODEL_CHRKNIFE,         0x0100 },
	/*0x1a*/ { WEAPON_CROSSBOW,         0x03, 0x0a, 0x00, 0x00, 1, MPFEATURE_WEAPON_CROSSBOW,        MODEL_CHRCROSSBOW,      0x0100 },
	/*0x1b*/ { WEAPON_TRANQUILIZER,     0x13, 0x32, 0x00, 0x00, 1, MPFEATURE_WEAPON_TRANQUILIZER,    MODEL_CHRDRUGGUN,       0x0100 },
	/*0x1c*/ { WEAPON_GRENADE,          0x07, 0x05, 0x00, 0x00, 0, 0,                                MODEL_CHRGRENADE,       0x0100 },
	/*0x1d*/ { WEAPON_NBOMB,            0x12, 0x03, 0x00, 0x00, 0, MPFEATURE_WEAPON_NBOMB,           MODEL_CHRNBOMB,         0x0100 },
	/*0x1e*/ { WEAPON_TIMEDMINE,        0x0e, 0x05, 0x00, 0x00, 0, 0,                                MODEL_CHRTIMEDMINE,     0x0180 },
	/*0x1f*/ { WEAPON_PROXIMITYMINE,    0x0d, 0x05, 0x00, 0x00, 0, MPFEATURE_WEAPON_PROXIMITYMINE,   MODEL_CHRPROXIMITYMINE, 0x0180 },
	/*0x20*/ { WEAPON_REMOTEMINE,       0x0c, 0x05, 0x00, 0x00, 0, MPFEATURE_WEAPON_REMOTEMINE,      MODEL_CHRREMOTEMINE,    0x0180 },
	/*0x21*/ { WEAPON_LASER,            0x00, 0x00, 0x00, 0x00, 1, MPFEATURE_WEAPON_LASER,           MODEL_CHRLASER,         0x0200 },
	/*0x22*/ { WEAPON_XRAYSCANNER,      0x00, 0x00, 0x00, 0x00, 1, MPFEATURE_WEAPON_XRAYSCANNER,     MODEL_CHRNIGHTSIGHT,    0x0100 },
	/*0x23*/ { WEAPON_CLOAKINGDEVICE,   0x00, 0x00, 0x00, 0x00, 1, MPFEATURE_WEAPON_CLOAKINGDEVICE,  MODEL_CHRCLOAKER,       0x0100 },
	/*0x24*/ { WEAPON_COMBATBOOST,      0x00, 0x00, 0x00, 0x00, 1, MPFEATURE_WEAPON_COMBATBOOST,     MODEL_CHRSPEEDPILL,     0x0100 },
	/*0x25*/ { WEAPON_MPSHIELD,         0x00, 0x00, 0x00, 0x00, 1, MPFEATURE_WEAPON_SHIELD,          MODEL_CHRSHIELD,        0x0100 },
	/*0x26*/ { WEAPON_DISABLED,         0x00, 0x00, 0x00, 0x00, 0, 0x00,                             0,                      0x0000 },
};

/**
 * Converts the given value into a float on a curved scale from 0.1 to 10.
 *
 * value 0 will return 0.1
 * value 127 will return 1
 * value 255 will return 10
 */
f32 func0f187770(u8 value)
{
	f32 tmp;

	if (value < 127) {
		return (value / 127.0f) * (value / 127.0f) * 0.9f + 0.1f;
	}

	if (value == 127) {
		return 1;
	}

	tmp = (value - 128) / 127.0f + 1;

	return tmp * tmp * 3 - 2;
}

void func0f187838(struct mpchr *mpchr)
{
	s32 i = 0;

	while (i < ARRAYCOUNT(mpchr->killcounts)) {
		mpchr->killcounts[i++] = 0;
	}

	mpchr->numdeaths = 0;
	mpchr->unk3e = 0;
	mpchr->unk40 = 0;
}

void mpStartMatch(void)
{
	s32 i;
	s32 numplayers = 0;
	s32 stagenum;

	mpConfigureQuickTeamSimulants();

	if (!mpIsFeatureUnlocked(MPFEATURE_ONEHITKILLS)) {
		g_MpSetup.options &= ~MPOPTION_ONEHITKILLS;
	}

	if (!mpIsFeatureUnlocked(MPFEATURE_SLOWMOTION)) {
		g_MpSetup.options &= ~(MPOPTION_SLOWMOTION_ON | MPOPTION_SLOWMOTION_SMART);
	}

	for (i = 0; i < 4; i++) {
		if (g_MpSetup.chrslots & (1 << i)) {
			numplayers++;
		}
	}

	stagenum = g_MpSetup.stagenum;

	if (g_MpSetup.stagenum == STAGE_MP_RANDOM) {
		stagenum = mpChooseRandomStage();
	}

	titleSetNextStage(stagenum);
	mainSetStageNum(stagenum);
	setNumPlayers(numplayers);
	titleSetNextMode(TITLEMODE_SKIP);

	g_Vars.perfectbuddynum = 1;
}

void mpInit(void)
{
	s32 i;
	s32 mpindex = 0;

	g_MpNumPlayers = 0;
	g_Vars.mplayerisrunning = true;

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		g_Vars.normmplayerisrunning = false;
	} else {
		g_Vars.normmplayerisrunning = true;
	}

	g_Vars.perfectbuddynum = 0;

	if (mpHasSimulants()) {
		g_Vars.lvmpbotlevel = true;
	}

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		struct mpplayer tmp;

		tmp = g_MpPlayers[4];
		g_MpPlayers[4] = g_MpPlayers[0];
		g_MpPlayers[0] = tmp;

		tmp = g_MpPlayers[5];
		g_MpPlayers[5] = g_MpPlayers[1];
		g_MpPlayers[1] = tmp;

		// Player index 0
		g_Vars.playerstats[0].mpindex = 0;

		g_MpPlayers[0].base.contpad1 = 0;
		g_MpPlayers[0].base.contpad2 = 2;

		if ((g_Vars.coopplayernum >= 0 && g_Vars.coopradaron)
				|| (g_Vars.antiplayernum >= 0 && g_Vars.antiradaron)) {
			g_MpPlayers[0].base.displayoptions |= MPDISPLAYOPTION_RADAR;
		} else {
			g_MpPlayers[0].base.displayoptions &= ~MPDISPLAYOPTION_RADAR;
		}

		// Player index 1
		g_Vars.playerstats[1].mpindexu32 = 1;

		g_MpPlayers[1].base.contpad1 = 1;
		g_MpPlayers[1].base.contpad2 = 3;

		if ((g_Vars.coopplayernum >= 0 && g_Vars.coopradaron)
				|| (g_Vars.antiplayernum >= 0 && g_Vars.antiradaron)) {
			g_MpPlayers[1].base.displayoptions |= MPDISPLAYOPTION_RADAR;
		} else {
			g_MpPlayers[1].base.displayoptions &= ~MPDISPLAYOPTION_RADAR;
		}

		g_MpNumPlayers = 2;
	} else {
		for (i = 0; i < 4; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				g_Vars.playerstats[mpindex].mpindex = i;

				g_MpPlayers[i].base.contpad1 = i;
				g_MpPlayers[i].base.contpad2 = 0;

				mpCalculatePlayerTitle(&g_MpPlayers[i]);


				g_MpPlayers[i].newtitle = g_MpPlayers[i].title;
				g_MpNumPlayers++;
				mpindex++;
			}
		}
	}

	for (i = 0; i != 12; i++) {
		struct mpchr *mpchr;

		if (i < 4) {
			mpchr = &g_MpPlayers[i].base;
		} else {
			mpchr = &g_MpSimulants[i - 4].base;
		}

		func0f187838(mpchr);

		g_MpPlayerChrs[i] = NULL;
	}

	g_MpSetup.paused = false;

	var80087264 = 0;

	if (g_Vars.normmplayerisrunning) {
		if (mpGetUsingMultipleTunes()) {
			s32 i = 0;
			s32 count = 0;
			s32 numtracks = mpGetNumUnlockedTracks();

			for (i; i < numtracks && count < 2; i++) {
				if (mpIsMultiTrackSlotEnabled(i)) {
					count++;
				}
			}

			if (count >= 2) {
				var80087264 = 1;
			}
		}

		g_MpLockInfo.unk04 = 0xffffffff;
	}

	// Assign aibot commands to active menu slots
	for (i = 0; i < 9; i++) {
		g_AmBotCommands[i] = AIBOTCMD_NORMAL;
	}

	g_AmBotCommands[1] = AIBOTCMD_ATTACK;
	g_AmBotCommands[7] = AIBOTCMD_NORMAL;
	g_AmBotCommands[0] = AIBOTCMD_FOLLOW;
	g_AmBotCommands[2] = AIBOTCMD_PROTECT;
	g_AmBotCommands[3] = AIBOTCMD_DEFEND;
	g_AmBotCommands[5] = AIBOTCMD_HOLD;

	switch (g_MpSetup.scenario) {
	case MPSCENARIO_CAPTURETHECASE:
		g_AmBotCommands[3] = AIBOTCMD_GETCASE;
		g_AmBotCommands[5] = AIBOTCMD_SAVECASE;
		break;
	case MPSCENARIO_KINGOFTHEHILL:
		g_AmBotCommands[6] = AIBOTCMD_DEFHILL;
		g_AmBotCommands[8] = AIBOTCMD_HOLDHILL;
		break;
	case MPSCENARIO_HACKERCENTRAL:
		g_AmBotCommands[6] = AIBOTCMD_DOWNLOAD;
		g_AmBotCommands[8] = AIBOTCMD_DOWNLOAD;
		break;
	case MPSCENARIO_POPACAP:
		g_AmBotCommands[6] = AIBOTCMD_POPCAP;
		g_AmBotCommands[8] = AIBOTCMD_POPCAP;
		break;
	case MPSCENARIO_HOLDTHEBRIEFCASE:
		g_AmBotCommands[6] = AIBOTCMD_GETCASE2;
		g_AmBotCommands[8] = AIBOTCMD_GETCASE2;
		break;
	default:
		g_AmBotCommands[0] = AIBOTCMD_FOLLOW;
		g_AmBotCommands[1] = AIBOTCMD_ATTACK;
		g_AmBotCommands[2] = AIBOTCMD_PROTECT;
		g_AmBotCommands[3] = AIBOTCMD_DEFEND;
		g_AmBotCommands[5] = AIBOTCMD_HOLD;
		g_AmBotCommands[7] = AIBOTCMD_NORMAL;
		break;
	}
}

void mpCalculateTeamIsOnlyAi(void)
{
	s32 playercount = PLAYERCOUNT();
	s32 i;
	s32 j;

	// Iterate simulants, which go after players in the g_MpPlayerChrs array
	for (i = playercount; i < g_MpNumPlayers; i++) {
		if (!g_MpPlayerChrs[i]) {
			continue;
		}

		g_MpPlayerChrs[i]->aibot->teamisonlyai = true;

		if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
			// Iterate human players
			for (j = 0; j < playercount; j++) {
				if (g_MpPlayerChrs[i]->team == g_MpPlayerChrs[j]->team) {
					g_MpPlayerChrs[i]->aibot->teamisonlyai = false;
					break;
				}
			}
		}
	}
}

void func0f187fbc(s32 playernum)
{
	g_MpPlayers[playernum].base.unk18 = 80;
	g_MpPlayers[playernum].base.unk1a = 80;
	g_MpPlayers[playernum].base.unk1c = 75;
}

void func0f187fec(void)
{
	g_MpSetup.timelimit = 9;
	g_MpSetup.scorelimit = 9;
	g_MpSetup.teamscorelimit = 19;
}

void mpPlayerSetDefaults(s32 playernum, bool autonames)
{
	s32 i;
	s32 j;

	func0f187fbc(playernum);

	g_MpPlayers[playernum].base.controlmode = CONTROLMODE_11;

	g_MpPlayers[playernum].options = OPTION_LOOKAHEAD
		| OPTION_SIGHTONSCREEN
		| OPTION_AUTOAIM
		| OPTION_AMMOONSCREEN
		| OPTION_SHOWGUNFUNCTION
		| OPTION_HEADROLL
		| OPTION_0100
		| OPTION_ALWAYSSHOWTARGET
		| OPTION_SHOWZOOMRANGE;

	g_MpPlayers[playernum].handicap = 128;

	switch (playernum) {
	case 0:
	default:
		g_MpPlayers[playernum].base.mpbodynum = MPBODY_DARK_COMBAT;
		break;
	case 1:
		g_MpPlayers[playernum].base.mpbodynum = MPBODY_CASSANDRA;
		break;
	case 2:
		g_MpPlayers[playernum].base.mpbodynum = MPBODY_CARRINGTON;
		break;
	case 3:
		g_MpPlayers[playernum].base.mpbodynum = MPBODY_CILABTECH;
		break;
	}

	g_MpPlayers[playernum].base.mpheadnum = mpGetMpheadnumByMpbodynum(g_MpPlayers[playernum].base.mpbodynum);
	g_MpPlayers[playernum].base.displayoptions = MPDISPLAYOPTION_RADAR | MPDISPLAYOPTION_HIGHLIGHTTEAMS;
	g_MpPlayers[playernum].unk4c.unk00 = 0;
	g_MpPlayers[playernum].unk4c.unk04 = 0;

	if (autonames) {
		// "Player 1" etc
		sprintf(g_MpPlayers[playernum].base.name, "%s %d\n", langGet(L_MISC(437)), playernum + 1);
	} else {
		g_MpPlayers[playernum].base.name[0] = '\0';
	}

	g_MpPlayers[playernum].kills = 0;
	g_MpPlayers[playernum].deaths = 0;
	g_MpPlayers[playernum].gamesplayed = 0;
	g_MpPlayers[playernum].gameswon = 0;
	g_MpPlayers[playernum].gameslost = 0;
	g_MpPlayers[playernum].time = 0;
	g_MpPlayers[playernum].distance = 0;
	g_MpPlayers[playernum].accuracy = 1000;
	g_MpPlayers[playernum].damagedealt = 0;
	g_MpPlayers[playernum].painreceived = 0;
	g_MpPlayers[playernum].headshots = 0;
	g_MpPlayers[playernum].ammoused = 0;
	g_MpPlayers[playernum].accuracymedals = 0;
	g_MpPlayers[playernum].headshotmedals = 0;
	g_MpPlayers[playernum].killmastermedals = 0;
	g_MpPlayers[playernum].survivormedals = 0;
	g_MpPlayers[playernum].title = MPPLAYERTITLE_BEGINNER;

	if (playernum < 4) {
		for (i = 0; i < 30; i++) {
			for (j = 1; j <= 4; j++) {
				mpSetChallengeCompletedByPlayerWithNumPlayers(playernum, i, j, false);
			}
		}

		mpDetermineUnlockedFeatures();
	}

	for (i = 0; i < 6; i++) {
		g_MpPlayers[playernum].gunfuncs[i] = 0;
	}
}

void func0f1881d4(s32 index)
{
	g_MpSimulants[index].base.name[0] = '\0';
	g_MpSimulants[index].base.mpheadnum = MPHEAD_DARK_COMBAT;
	g_MpSimulants[index].base.mpbodynum = MPBODY_DARK_COMBAT;
	g_MpSimulants[index].base.simtype = SIMTYPE_GENERAL;
	g_MpSimulants[index].difficulty = SIMDIFF_DISABLED;
}

void mpSetDefaultSetup(void)
{
	s32 i;
	s32 j;

	g_MpSetup.scenario = MPSCENARIO_COMBAT;
	g_MpSetup.stagenum = STAGE_MP_SKEDAR;
	g_MpSetup.options = MPOPTION_DISPLAYTEAM
		| MPOPTION_KILLSSCORE
		| MPOPTION_HTB_HIGHLIGHTBRIEFCASE
		| MPOPTION_HTB_SHOWONRADAR
		| MPOPTION_CTC_SHOWONRADAR
		| MPOPTION_KOH_HILLONRADAR
		| MPOPTION_KOH_MOBILEHILL
		| MPOPTION_00010000
		| MPOPTION_HTM_HIGHLIGHTTERMINAL
		| MPOPTION_HTM_SHOWONRADAR
		| MPOPTION_PAC_HIGHLIGHTTARGET
		| MPOPTION_PAC_SHOWONRADAR;

	g_Vars.mphilltime = 10;

	func0f187fec();

	g_MpSetup.unk20.unk00 = 0;
	g_MpSetup.unk20.unk04 = 0;

	strcpy(g_MpSetup.name, "");

	for (i = 0; i < 6; i++) {
		mpPlayerSetDefaults(i, false);
	}

	for (i = 0; i < 8; i++) {
		func0f1881d4(i);
	}

	if (argFindByPrefix(1, "-mpwpnset")) {
		char *value = argFindByPrefix(1, "-mpwpnset");
		mpSetWeaponSet(*value - 0x30);
	} else {
		mpSetWeaponSet(0);
	}

	g_Vars.mplayerisrunning = false;
	g_Vars.normmplayerisrunning = false;
	g_Vars.lvmpbotlevel = 0;

	g_MpLockInfo.lockedplayernum = 0;
	g_MpLockInfo.lastwinner = -1;
	g_MpLockInfo.lastloser = -1;
	g_MpLockInfo.unk03 = -1;
	g_MpLockInfo.unk04 = -1;

	mpForceUnlockSimulantFeatures();

	for (i = 0; i < ARRAYCOUNT(g_MpPlayers); i++) {
		for (j = 0; j < 6; j++) {
			g_MpPlayers[i].gunfuncs[j] = 0;
		}
	}

	g_MpSetup.chrslots = 0;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f1892fcpf
/*  f1892fc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f189300:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f189304:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f189308:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18930c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f189310:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f189314:	3c11800b */ 	lui	$s1,0x800b
/*  f189318:	00809025 */ 	move	$s2,$a0
/*  f18931c:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f189320:	2631d150 */ 	addiu	$s1,$s1,-11952
/*  f189324:	00008025 */ 	move	$s0,$zero
/*  f189328:	24130008 */ 	li	$s3,0x8
.PF0f18932c:
/*  f18932c:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f189330:	26045608 */ 	addiu	$a0,$s0,0x5608
/*  f189334:	02202025 */ 	move	$a0,$s1
/*  f189338:	0c004c01 */ 	jal	0x13004
/*  f18933c:	00402825 */ 	move	$a1,$v0
/*  f189340:	54400007 */ 	bnezl	$v0,.PF0f189360
/*  f189344:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f189348:	924e0000 */ 	lbu	$t6,0x0($s2)
/*  f18934c:	240f0001 */ 	li	$t7,0x1
/*  f189350:	020fc004 */ 	sllv	$t8,$t7,$s0
/*  f189354:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f189358:	a2590000 */ 	sb	$t9,0x0($s2)
/*  f18935c:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f189360:
/*  f189360:	1613fff2 */ 	bne	$s0,$s3,.PF0f18932c
/*  f189364:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f189368:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18936c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f189370:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f189374:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f189378:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18937c:	03e00008 */ 	jr	$ra
/*  f189380:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f189384pf
/*  f189384:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f189388:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18938c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f189390:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f189394:	309300ff */ 	andi	$s3,$a0,0xff
/*  f189398:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18939c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1893a0:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f1893a4:	00008025 */ 	move	$s0,$zero
/*  f1893a8:	24120008 */ 	li	$s2,0x8
/*  f1893ac:	240f0001 */ 	li	$t7,0x1
.PF0f1893b0:
/*  f1893b0:	020fc004 */ 	sllv	$t8,$t7,$s0
/*  f1893b4:	0278c824 */ 	and	$t9,$s3,$t8
/*  f1893b8:	1320000b */ 	beqz	$t9,.PF0f1893e8
/*  f1893bc:	26045608 */ 	addiu	$a0,$s0,0x5608
/*  f1893c0:	00104080 */ 	sll	$t0,$s0,0x2
/*  f1893c4:	01104023 */ 	subu	$t0,$t0,$s0
/*  f1893c8:	3c09800b */ 	lui	$t1,0x800b
/*  f1893cc:	2529d150 */ 	addiu	$t1,$t1,-11952
/*  f1893d0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1893d4:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f1893d8:	01098821 */ 	addu	$s1,$t0,$t1
/*  f1893dc:	02202025 */ 	move	$a0,$s1
/*  f1893e0:	0c004bb0 */ 	jal	0x12ec0
/*  f1893e4:	00402825 */ 	move	$a1,$v0
.PF0f1893e8:
/*  f1893e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1893ec:	5612fff0 */ 	bnel	$s0,$s2,.PF0f1893b0
/*  f1893f0:	240f0001 */ 	li	$t7,0x1
/*  f1893f4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1893f8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1893fc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f189400:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f189404:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f189408:	03e00008 */ 	jr	$ra
/*  f18940c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
#endif

void mpSetDefaultNamesIfEmpty(void)
{
	s32 i;

	// Setup file name
	if (g_MpSetup.name[0] == '\0') {
		strcpy(g_MpSetup.name, langGet(L_MISC(438))); // empty string
	}

	// Team names
	for (i = 0; i < 8; i++) {
		if (g_MpSetupSaveFile.teamnames[i][0] == '\0') {
			strcpy(g_MpSetupSaveFile.teamnames[i], langGet(L_OPTIONS(8) + i)); // "Red", "Yellow" etc
		}
	}

	// Player names
	for (i = 0; i < 4; i++) {
		if (g_MpPlayers[i].base.name[0] == '\0') {
			sprintf(g_MpPlayers[i].base.name, "%s %d\n", langGet(L_MISC(437)), i + 1); // "Player 1" etc
		}
	}
}

s32 mpCalculateTeamScoreLimit(void)
{
	s32 limit = g_MpSetup.teamscorelimit;
	s32 i;

	if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE
			&& g_MpSetup.teamscorelimit != 400
			&& (g_MpSetup.scenario == MPSCENARIO_COMBAT || g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL)) {
		s32 numchrs = 0;

		for (i = 0; i < 4; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				numchrs++;
			}
		}

		switch (numchrs) {
		case 1:
			break;
		case 2:
			limit = limit * 2 + 1;
			break;
		case 3:
			limit = (limit * 5 + 5) / 2 - 1;
			break;
		case 4:
			limit = limit * 3 + 2;
			break;
		}
	}

	return limit;
}

void mpApplyLimits(void)
{
	if (g_MpSetup.timelimit >= 60) {
		coreSetMpTimeLimit60(0);
	} else {
		coreSetMpTimeLimit60(SECSTOTIME60((g_MpSetup.timelimit + 1) * 60));
	}

	if (g_MpSetup.scorelimit >= 100) {
		coreSetMpScoreLimit(0);
	} else {
		coreSetMpScoreLimit(g_MpSetup.scorelimit + 1);
	}

	if (g_MpSetup.teamscorelimit >= 400) {
		coreSetMpTeamScoreLimit(0);
	} else {
		coreSetMpTeamScoreLimit(mpCalculateTeamScoreLimit() + 1);
	}
}

GLOBAL_ASM(
glabel mpGetPlayerRankings
/*  f1885e4:	27bdfdc8 */ 	addiu	$sp,$sp,-568
/*  f1885e8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1885ec:	3c14800b */ 	lui	$s4,%hi(g_MpSetup)
/*  f1885f0:	2694cb88 */ 	addiu	$s4,$s4,%lo(g_MpSetup)
/*  f1885f4:	8e8e000c */ 	lw	$t6,0xc($s4)
/*  f1885f8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1885fc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f188600:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f188604:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f188608:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18860c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188610:	afa40238 */ 	sw	$a0,0x238($sp)
/*  f188614:	11e00004 */ 	beqz	$t7,.L0f188628
/*  f188618:	00008025 */ 	or	$s0,$zero,$zero
/*  f18861c:	0fc622a1 */ 	jal	mpGetTeamRankings
/*  f188620:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f188624:	afa2016c */ 	sw	$v0,0x16c($sp)
.L0f188628:
/*  f188628:	8fac016c */ 	lw	$t4,0x16c($sp)
/*  f18862c:	00008825 */ 	or	$s1,$zero,$zero
/*  f188630:	27b301d4 */ 	addiu	$s3,$sp,0x1d4
/*  f188634:	96980016 */ 	lhu	$t8,0x16($s4)
.L0f188638:
/*  f188638:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18863c:	02397004 */ 	sllv	$t6,$t9,$s1
/*  f188640:	030e7824 */ 	and	$t7,$t8,$t6
/*  f188644:	11e00064 */ 	beqz	$t7,.L0f1887d8
/*  f188648:	00004025 */ 	or	$t0,$zero,$zero
/*  f18864c:	2a210004 */ 	slti	$at,$s1,0x4
/*  f188650:	10200008 */ 	beqz	$at,.L0f188674
/*  f188654:	00001825 */ 	or	$v1,$zero,$zero
/*  f188658:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f18865c:	0331c821 */ 	addu	$t9,$t9,$s1
/*  f188660:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f188664:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f188668:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f18866c:	1000000a */ 	b	.L0f188698
/*  f188670:	03389021 */ 	addu	$s2,$t9,$t8
.L0f188674:
/*  f188674:	00117080 */ 	sll	$t6,$s1,0x2
/*  f188678:	01d17021 */ 	addu	$t6,$t6,$s1
/*  f18867c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f188680:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f188684:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f188688:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f18868c:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f188690:	25cffed0 */ 	addiu	$t7,$t6,-304
/*  f188694:	01f99021 */ 	addu	$s2,$t7,$t9
.L0f188698:
/*  f188698:	02402025 */ 	or	$a0,$s2,$zero
/*  f18869c:	02202825 */ 	or	$a1,$s1,$zero
/*  f1886a0:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f1886a4:	27a7006c */ 	addiu	$a3,$sp,0x6c
/*  f1886a8:	afa30060 */ 	sw	$v1,0x60($sp)
/*  f1886ac:	afa80064 */ 	sw	$t0,0x64($sp)
/*  f1886b0:	0fc61705 */ 	jal	func0f185c14
/*  f1886b4:	afac016c */ 	sw	$t4,0x16c($sp)
/*  f1886b8:	8fa30060 */ 	lw	$v1,0x60($sp)
/*  f1886bc:	8fa80064 */ 	lw	$t0,0x64($sp)
/*  f1886c0:	8fac016c */ 	lw	$t4,0x16c($sp)
/*  f1886c4:	1a000017 */ 	blez	$s0,.L0f188724
/*  f1886c8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1886cc:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f1886d0:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f1886d4:	34018000 */ 	dli	$at,0x8000
/*  f1886d8:	0161c021 */ 	addu	$t8,$t3,$at
/*  f1886dc:	00187400 */ 	sll	$t6,$t8,0x10
/*  f1886e0:	3419ffff */ 	dli	$t9,0xffff
/*  f1886e4:	032fc023 */ 	subu	$t8,$t9,$t7
/*  f1886e8:	0000c880 */ 	sll	$t9,$zero,0x2
/*  f1886ec:	02791021 */ 	addu	$v0,$s3,$t9
/*  f1886f0:	01d84825 */ 	or	$t1,$t6,$t8
/*  f1886f4:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f1886f8:
/*  f1886f8:	01e9082b */ 	sltu	$at,$t7,$t1
/*  f1886fc:	50200004 */ 	beqzl	$at,.L0f188710
/*  f188700:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f188704:	00804025 */ 	or	$t0,$a0,$zero
/*  f188708:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f18870c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f188710:
/*  f188710:	0090082a */ 	slt	$at,$a0,$s0
/*  f188714:	10200003 */ 	beqz	$at,.L0f188724
/*  f188718:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18871c:	5060fff6 */ 	beqzl	$v1,.L0f1886f8
/*  f188720:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f188724:
/*  f188724:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f188728:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f18872c:	34018000 */ 	dli	$at,0x8000
/*  f188730:	01617021 */ 	addu	$t6,$t3,$at
/*  f188734:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f188738:	340fffff */ 	dli	$t7,0xffff
/*  f18873c:	01f97023 */ 	subu	$t6,$t7,$t9
/*  f188740:	14600002 */ 	bnez	$v1,.L0f18874c
/*  f188744:	030e4825 */ 	or	$t1,$t8,$t6
/*  f188748:	02004025 */ 	or	$t0,$s0,$zero
.L0f18874c:
/*  f18874c:	0110082a */ 	slt	$at,$t0,$s0
/*  f188750:	10200017 */ 	beqz	$at,.L0f1887b0
/*  f188754:	02002025 */ 	or	$a0,$s0,$zero
/*  f188758:	00045080 */ 	sll	$t2,$a0,0x2
/*  f18875c:	27af0204 */ 	addiu	$t7,$sp,0x204
/*  f188760:	27b901a4 */ 	addiu	$t9,$sp,0x1a4
/*  f188764:	27b80174 */ 	addiu	$t8,$sp,0x174
/*  f188768:	01583021 */ 	addu	$a2,$t2,$t8
/*  f18876c:	01592821 */ 	addu	$a1,$t2,$t9
/*  f188770:	014f3821 */ 	addu	$a3,$t2,$t7
/*  f188774:	026a1021 */ 	addu	$v0,$s3,$t2
.L0f188778:
/*  f188778:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f18877c:	8ceffffc */ 	lw	$t7,-0x4($a3)
/*  f188780:	8cb9fffc */ 	lw	$t9,-0x4($a1)
/*  f188784:	8cd8fffc */ 	lw	$t8,-0x4($a2)
/*  f188788:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f18878c:	2442fffc */ 	addiu	$v0,$v0,-4
/*  f188790:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f188794:	24a5fffc */ 	addiu	$a1,$a1,-4
/*  f188798:	24c6fffc */ 	addiu	$a2,$a2,-4
/*  f18879c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1887a0:	acef0004 */ 	sw	$t7,0x4($a3)
/*  f1887a4:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1887a8:	1504fff3 */ 	bne	$t0,$a0,.L0f188778
/*  f1887ac:	acd80004 */ 	sw	$t8,0x4($a2)
.L0f1887b0:
/*  f1887b0:	00081080 */ 	sll	$v0,$t0,0x2
/*  f1887b4:	02627021 */ 	addu	$t6,$s3,$v0
/*  f1887b8:	adc90000 */ 	sw	$t1,0x0($t6)
/*  f1887bc:	03a27821 */ 	addu	$t7,$sp,$v0
/*  f1887c0:	adeb0204 */ 	sw	$t3,0x204($t7)
/*  f1887c4:	03a2c821 */ 	addu	$t9,$sp,$v0
/*  f1887c8:	af3201a4 */ 	sw	$s2,0x1a4($t9)
/*  f1887cc:	03a2c021 */ 	addu	$t8,$sp,$v0
/*  f1887d0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1887d4:	af110174 */ 	sw	$s1,0x174($t8)
.L0f1887d8:
/*  f1887d8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1887dc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1887e0:	5621ff95 */ 	bnel	$s1,$at,.L0f188638
/*  f1887e4:	96980016 */ 	lhu	$t8,0x16($s4)
/*  f1887e8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f1887ec:	241fffff */ 	addiu	$ra,$zero,-1
/*  f1887f0:	1a00003a */ 	blez	$s0,.L0f1888dc
/*  f1887f4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1887f8:	00005025 */ 	or	$t2,$zero,$zero
/*  f1887fc:	27a70204 */ 	addiu	$a3,$sp,0x204
/*  f188800:	27a501a4 */ 	addiu	$a1,$sp,0x1a4
/*  f188804:	27a60174 */ 	addiu	$a2,$sp,0x174
/*  f188808:	8fab0238 */ 	lw	$t3,0x238($sp)
/*  f18880c:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f188810:	241100ff */ 	addiu	$s1,$zero,0xff
.L0f188814:
/*  f188814:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f188818:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f18881c:	256b0014 */ 	addiu	$t3,$t3,0x14
/*  f188820:	ad6effec */ 	sw	$t6,-0x14($t3)
/*  f188824:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f188828:	ad64fff4 */ 	sw	$a0,-0xc($t3)
/*  f18882c:	a160fff8 */ 	sb	$zero,-0x8($t3)
/*  f188830:	ad6ffff0 */ 	sw	$t7,-0x10($t3)
/*  f188834:	8cf9fffc */ 	lw	$t9,-0x4($a3)
/*  f188838:	2589ffff */ 	addiu	$t1,$t4,-1
/*  f18883c:	ad79fffc */ 	sw	$t9,-0x4($t3)
/*  f188840:	8e98000c */ 	lw	$t8,0xc($s4)
/*  f188844:	330e0002 */ 	andi	$t6,$t8,0x2
/*  f188848:	51c00014 */ 	beqzl	$t6,.L0f18889c
/*  f18884c:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f188850:	1980000b */ 	blez	$t4,.L0f188880
/*  f188854:	00001025 */ 	or	$v0,$zero,$zero
/*  f188858:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f18885c:	27a3007c */ 	addiu	$v1,$sp,0x7c
/*  f188860:	91e80011 */ 	lbu	$t0,0x11($t7)
.L0f188864:
/*  f188864:	8c790004 */ 	lw	$t9,0x4($v1)
/*  f188868:	57280003 */ 	bnel	$t9,$t0,.L0f188878
/*  f18886c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f188870:	00404825 */ 	or	$t1,$v0,$zero
/*  f188874:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f188878:
/*  f188878:	144cfffa */ 	bne	$v0,$t4,.L0f188864
/*  f18887c:	24630014 */ 	addiu	$v1,$v1,0x14
.L0f188880:
/*  f188880:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f188884:	02297023 */ 	subu	$t6,$s1,$t1
/*  f188888:	a309001e */ 	sb	$t1,0x1e($t8)
/*  f18888c:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f188890:	10000007 */ 	b	.L0f1888b0
/*  f188894:	adee0020 */ 	sw	$t6,0x20($t7)
/*  f188898:	8cb90000 */ 	lw	$t9,0x0($a1)
.L0f18889c:
/*  f18889c:	026ac021 */ 	addu	$t8,$s3,$t2
/*  f1888a0:	a324001e */ 	sb	$a0,0x1e($t9)
/*  f1888a4:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f1888a8:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f1888ac:	adee0020 */ 	sw	$t6,0x20($t7)
.L0f1888b0:
/*  f1888b0:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f1888b4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f1888b8:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f1888bc:	28410004 */ 	slti	$at,$v0,0x4
/*  f1888c0:	10200004 */ 	beqz	$at,.L0f1888d4
/*  f1888c4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f1888c8:	15b20002 */ 	bne	$t5,$s2,.L0f1888d4
/*  f1888cc:	0040f825 */ 	or	$ra,$v0,$zero
/*  f1888d0:	00406825 */ 	or	$t5,$v0,$zero
.L0f1888d4:
/*  f1888d4:	1490ffcf */ 	bne	$a0,$s0,.L0f188814
/*  f1888d8:	24c60004 */ 	addiu	$a2,$a2,0x4
.L0f1888dc:
/*  f1888dc:	3c11800b */ 	lui	$s1,%hi(g_MpLockInfo)
/*  f1888e0:	2631cc20 */ 	addiu	$s1,$s1,%lo(g_MpLockInfo)
/*  f1888e4:	a22d0001 */ 	sb	$t5,0x1($s1)
/*  f1888e8:	a23f0002 */ 	sb	$ra,0x2($s1)
/*  f1888ec:	3c19800b */ 	lui	$t9,%hi(g_MpSetup+0x88)
/*  f1888f0:	9339cc10 */ 	lbu	$t9,%lo(g_MpSetup+0x88)($t9)
/*  f1888f4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1888f8:	57210005 */ 	bnel	$t9,$at,.L0f188910
/*  f1888fc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f188900:	0fc62fba */ 	jal	mpChooseRandomLockPlayer
/*  f188904:	00000000 */ 	nop
/*  f188908:	a2220000 */ 	sb	$v0,0x0($s1)
/*  f18890c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f188910:
/*  f188910:	02001025 */ 	or	$v0,$s0,$zero
/*  f188914:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188918:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18891c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f188920:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f188924:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f188928:	03e00008 */ 	jr	$ra
/*  f18892c:	27bd0238 */ 	addiu	$sp,$sp,0x238
);

GLOBAL_ASM(
glabel func0f188930
/*  f188930:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f188934:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f188938:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18893c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f188940:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f188944:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f188948:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18894c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f188950:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188954:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188958:	3c14800b */ 	lui	$s4,%hi(g_MpSetup)
/*  f18895c:	3c15800b */ 	lui	$s5,%hi(g_MpPlayers)
/*  f188960:	00809825 */ 	or	$s3,$a0,$zero
/*  f188964:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f188968:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f18896c:	00008825 */ 	or	$s1,$zero,$zero
/*  f188970:	00009025 */ 	or	$s2,$zero,$zero
/*  f188974:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f188978:	26b5c7b8 */ 	addiu	$s5,$s5,%lo(g_MpPlayers)
/*  f18897c:	2694cb88 */ 	addiu	$s4,$s4,%lo(g_MpSetup)
/*  f188980:	00008025 */ 	or	$s0,$zero,$zero
/*  f188984:	241600a0 */ 	addiu	$s6,$zero,0xa0
/*  f188988:	27b70044 */ 	addiu	$s7,$sp,0x44
/*  f18898c:	27be0040 */ 	addiu	$s8,$sp,0x40
/*  f188990:	968e0016 */ 	lhu	$t6,0x16($s4)
.L0f188994:
/*  f188994:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f188998:	020fc004 */ 	sllv	$t8,$t7,$s0
/*  f18899c:	01d8c824 */ 	and	$t9,$t6,$t8
/*  f1889a0:	1320001c */ 	beqz	$t9,.L0f188a14
/*  f1889a4:	2a010004 */ 	slti	$at,$s0,0x4
/*  f1889a8:	10200006 */ 	beqz	$at,.L0f1889c4
/*  f1889ac:	00104880 */ 	sll	$t1,$s0,0x2
/*  f1889b0:	02160019 */ 	multu	$s0,$s6
/*  f1889b4:	00004012 */ 	mflo	$t0
/*  f1889b8:	02a82021 */ 	addu	$a0,$s5,$t0
/*  f1889bc:	1000000a */ 	b	.L0f1889e8
/*  f1889c0:	908c0011 */ 	lbu	$t4,0x11($a0)
.L0f1889c4:
/*  f1889c4:	01304821 */ 	addu	$t1,$t1,$s0
/*  f1889c8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1889cc:	01304823 */ 	subu	$t1,$t1,$s0
/*  f1889d0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1889d4:	3c0b800b */ 	lui	$t3,%hi(g_MpSimulants)
/*  f1889d8:	256bc538 */ 	addiu	$t3,$t3,%lo(g_MpSimulants)
/*  f1889dc:	252afed0 */ 	addiu	$t2,$t1,-304
/*  f1889e0:	014b2021 */ 	addu	$a0,$t2,$t3
/*  f1889e4:	908c0011 */ 	lbu	$t4,0x11($a0)
.L0f1889e8:
/*  f1889e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1889ec:	02e03025 */ 	or	$a2,$s7,$zero
/*  f1889f0:	166c0008 */ 	bne	$s3,$t4,.L0f188a14
/*  f1889f4:	03c03825 */ 	or	$a3,$s8,$zero
/*  f1889f8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1889fc:	0fc61705 */ 	jal	func0f185c14
/*  f188a00:	afad0050 */ 	sw	$t5,0x50($sp)
/*  f188a04:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f188a08:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f188a0c:	022f8821 */ 	addu	$s1,$s1,$t7
/*  f188a10:	024e9021 */ 	addu	$s2,$s2,$t6
.L0f188a14:
/*  f188a14:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f188a18:	2401000c */ 	addiu	$at,$zero,0xc
/*  f188a1c:	5601ffdd */ 	bnel	$s0,$at,.L0f188994
/*  f188a20:	968e0016 */ 	lhu	$t6,0x16($s4)
/*  f188a24:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f188a28:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f188a2c:	34018000 */ 	dli	$at,0x8000
/*  f188a30:	13000008 */ 	beqz	$t8,.L0f188a54
/*  f188a34:	00001025 */ 	or	$v0,$zero,$zero
/*  f188a38:	02214021 */ 	addu	$t0,$s1,$at
/*  f188a3c:	340affff */ 	dli	$t2,0xffff
/*  f188a40:	01525823 */ 	subu	$t3,$t2,$s2
/*  f188a44:	00084c00 */ 	sll	$t1,$t0,0x10
/*  f188a48:	af310000 */ 	sw	$s1,0x0($t9)
/*  f188a4c:	10000001 */ 	b	.L0f188a54
/*  f188a50:	012b1025 */ 	or	$v0,$t1,$t3
.L0f188a54:
/*  f188a54:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f188a58:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188a5c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f188a60:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f188a64:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f188a68:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f188a6c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f188a70:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f188a74:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f188a78:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f188a7c:	03e00008 */ 	jr	$ra
/*  f188a80:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel mpGetTeamRankings
/*  f188a84:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f188a88:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f188a8c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f188a90:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f188a94:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f188a98:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f188a9c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f188aa0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f188aa4:	0080b025 */ 	or	$s6,$a0,$zero
/*  f188aa8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f188aac:	0000a825 */ 	or	$s5,$zero,$zero
/*  f188ab0:	00008025 */ 	or	$s0,$zero,$zero
/*  f188ab4:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f188ab8:	27b20068 */ 	addiu	$s2,$sp,0x68
/*  f188abc:	27b30048 */ 	addiu	$s3,$sp,0x48
/*  f188ac0:	2414e0c0 */ 	addiu	$s4,$zero,-8000
.L0f188ac4:
/*  f188ac4:	ae540000 */ 	sw	$s4,0x0($s2)
/*  f188ac8:	02002025 */ 	or	$a0,$s0,$zero
/*  f188acc:	0fc6224c */ 	jal	func0f188930
/*  f188ad0:	02402825 */ 	or	$a1,$s2,$zero
/*  f188ad4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f188ad8:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f188adc:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f188ae0:	1611fff8 */ 	bne	$s0,$s1,.L0f188ac4
/*  f188ae4:	ae62fffc */ 	sw	$v0,-0x4($s3)
/*  f188ae8:	27ab0068 */ 	addiu	$t3,$sp,0x68
/*  f188aec:	240a0014 */ 	addiu	$t2,$zero,0x14
/*  f188af0:	27a90048 */ 	addiu	$t1,$sp,0x48
/*  f188af4:	24080007 */ 	addiu	$t0,$zero,0x7
/*  f188af8:	27a70064 */ 	addiu	$a3,$sp,0x64
/*  f188afc:	00002825 */ 	or	$a1,$zero,$zero
.L0f188b00:
/*  f188b00:	02803025 */ 	or	$a2,$s4,$zero
/*  f188b04:	00008025 */ 	or	$s0,$zero,$zero
/*  f188b08:	00001825 */ 	or	$v1,$zero,$zero
/*  f188b0c:	27a40084 */ 	addiu	$a0,$sp,0x84
.L0f188b10:
/*  f188b10:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f188b14:	00037823 */ 	negu	$t7,$v1
/*  f188b18:	2484fffc */ 	addiu	$a0,$a0,-4
/*  f188b1c:	29c1e0c1 */ 	slti	$at,$t6,-7999
/*  f188b20:	14200009 */ 	bnez	$at,.L0f188b48
/*  f188b24:	00efc021 */ 	addu	$t8,$a3,$t7
/*  f188b28:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f188b2c:	0325082b */ 	sltu	$at,$t9,$a1
/*  f188b30:	54200006 */ 	bnezl	$at,.L0f188b4c
/*  f188b34:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f188b38:	01103023 */ 	subu	$a2,$t0,$s0
/*  f188b3c:	00066080 */ 	sll	$t4,$a2,0x2
/*  f188b40:	012c6821 */ 	addu	$t5,$t1,$t4
/*  f188b44:	8da50000 */ 	lw	$a1,0x0($t5)
.L0f188b48:
/*  f188b48:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f188b4c:
/*  f188b4c:	1611fff0 */ 	bne	$s0,$s1,.L0f188b10
/*  f188b50:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f188b54:	28c1e0c1 */ 	slti	$at,$a2,-7999
/*  f188b58:	1420000f */ 	bnez	$at,.L0f188b98
/*  f188b5c:	00000000 */ 	nop
/*  f188b60:	02aa0019 */ 	multu	$s5,$t2
/*  f188b64:	26a30001 */ 	addiu	$v1,$s5,0x1
/*  f188b68:	00067880 */ 	sll	$t7,$a2,0x2
/*  f188b6c:	016f2021 */ 	addu	$a0,$t3,$t7
/*  f188b70:	0060a825 */ 	or	$s5,$v1,$zero
/*  f188b74:	00007012 */ 	mflo	$t6
/*  f188b78:	02ce1021 */ 	addu	$v0,$s6,$t6
/*  f188b7c:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f188b80:	ac460004 */ 	sw	$a2,0x4($v0)
/*  f188b84:	ac430008 */ 	sw	$v1,0x8($v0)
/*  f188b88:	a040000c */ 	sb	$zero,0xc($v0)
/*  f188b8c:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f188b90:	ac580010 */ 	sw	$t8,0x10($v0)
/*  f188b94:	ac940000 */ 	sw	$s4,0x0($a0)
.L0f188b98:
/*  f188b98:	54d4ffd9 */ 	bnel	$a2,$s4,.L0f188b00
/*  f188b9c:	00002825 */ 	or	$a1,$zero,$zero
/*  f188ba0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f188ba4:	02a01025 */ 	or	$v0,$s5,$zero
/*  f188ba8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f188bac:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f188bb0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f188bb4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f188bb8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f188bbc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f188bc0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f188bc4:	03e00008 */ 	jr	$ra
/*  f188bc8:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

s32 func0f188bcc(void)
{
	return 39;
}

s32 mpGetNumWeaponOptions(void)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpWeapons); i++) {
		if (mpIsFeatureUnlocked(g_MpWeapons[i].unlockfeature)) {
			count++;
		}
	}

	return count;
}

char *mpGetWeaponLabel(s32 weaponnum)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpWeapons); i++) {
		if (mpIsFeatureUnlocked(g_MpWeapons[i].unlockfeature)) {
			if (weaponnum == 0) {
				if (g_MpWeapons[i].weaponnum == WEAPON_NONE) {
					return langGet(L_MPWEAPONS(58)); // "Nothing"
				}

				if (g_MpWeapons[i].weaponnum == WEAPON_MPSHIELD) {
					return langGet(L_MPWEAPONS(59)); // "Shield"
				}

				if (g_MpWeapons[i].weaponnum == WEAPON_DISABLED) {
					return langGet(L_MPWEAPONS(60)); // "Disabled"
				}

				return weaponGetName(g_MpWeapons[i].weaponnum);
			}

			weaponnum--;
		}
	}

	return "";
}

const char var7f1b8a5c[] = "Gun index %d -> slot %d = gun %d\n\n";
const char var7f1b8a80[] = "HOLDER: selecting weapon set %d\n";
const char var7f1b8aa4[] = "%d\n";

void mpSetWeaponSlot(s32 slot, s32 mpweaponnum)
{
	s32 optionindex = mpweaponnum;
	s32 i;

	for (i = 0; i <= mpweaponnum; i++) {
		if (mpIsFeatureUnlocked(g_MpWeapons[i].unlockfeature) == 0) {
			mpweaponnum++;
		}

		optionindex = mpweaponnum;
	}

	g_MpSetup.weapons[slot] = optionindex;
}

s32 mpGetWeaponSlot(s32 slot)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < g_MpSetup.weapons[slot]; i++) {
		if (mpIsFeatureUnlocked(g_MpWeapons[i].unlockfeature)) {
			count++;
		}
	}

	return count;
}

GLOBAL_ASM(
glabel func0f188e24
/*  f188e24:	24860001 */ 	addiu	$a2,$a0,0x1
/*  f188e28:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*  f188e2c:	00c01025 */ 	or	$v0,$a2,$zero
/*  f188e30:	18c0001e */ 	blez	$a2,.L0f188eac
/*  f188e34:	00002825 */ 	or	$a1,$zero,$zero
/*  f188e38:	3c088008 */ 	lui	$t0,%hi(g_MpWeapons)
/*  f188e3c:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f188e40:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f188e44:	25087268 */ 	addiu	$t0,$t0,%lo(g_MpWeapons)
/*  f188e48:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f188e4c:	2407005c */ 	addiu	$a3,$zero,0x5c
/*  f188e50:	00857021 */ 	addu	$t6,$a0,$a1
.L0f188e54:
/*  f188e54:	91c30018 */ 	lbu	$v1,0x18($t6)
/*  f188e58:	00690019 */ 	multu	$v1,$t1
/*  f188e5c:	00007812 */ 	mflo	$t7
/*  f188e60:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f188e64:	93190000 */ 	lbu	$t9,0x0($t8)
/*  f188e68:	10f90002 */ 	beq	$a3,$t9,.L0f188e74
/*  f188e6c:	00000000 */ 	nop
/*  f188e70:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f188e74:
/*  f188e74:	1840000a */ 	blez	$v0,.L0f188ea0
/*  f188e78:	00000000 */ 	nop
/*  f188e7c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f188e80:	28a10006 */ 	slti	$at,$a1,0x6
/*  f188e84:	14200006 */ 	bnez	$at,.L0f188ea0
/*  f188e88:	00000000 */ 	nop
/*  f188e8c:	14c20003 */ 	bne	$a2,$v0,.L0f188e9c
/*  f188e90:	00002825 */ 	or	$a1,$zero,$zero
/*  f188e94:	00001825 */ 	or	$v1,$zero,$zero
/*  f188e98:	00001025 */ 	or	$v0,$zero,$zero
.L0f188e9c:
/*  f188e9c:	00403025 */ 	or	$a2,$v0,$zero
.L0f188ea0:
/*  f188ea0:	5c40ffec */ 	bgtzl	$v0,.L0f188e54
/*  f188ea4:	00857021 */ 	addu	$t6,$a0,$a1
/*  f188ea8:	a3a30003 */ 	sb	$v1,0x3($sp)
.L0f188eac:
/*  f188eac:	93a30003 */ 	lbu	$v1,0x3($sp)
/*  f188eb0:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f188eb4:	3c088008 */ 	lui	$t0,%hi(g_MpWeapons)
/*  f188eb8:	00690019 */ 	multu	$v1,$t1
/*  f188ebc:	25087268 */ 	addiu	$t0,$t0,%lo(g_MpWeapons)
/*  f188ec0:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*  f188ec4:	00005012 */ 	mflo	$t2
/*  f188ec8:	010a1021 */ 	addu	$v0,$t0,$t2
/*  f188ecc:	03e00008 */ 	jr	$ra
/*  f188ed0:	00000000 */ 	nop
);

s32 mpCountWeaponSetThing(s32 weaponsetindex)
{
	s32 i;
	s32 count = 0;

	if (weaponsetindex >= ARRAYCOUNT(g_MpWeaponSets)) {
		count = weaponsetindex - ARRAYCOUNT(g_MpWeaponSets);
		weaponsetindex = ARRAYCOUNT(g_MpWeaponSets);
	}

	for (i = 0; i < weaponsetindex; i++) {
		if ((mpIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[0])
				&& mpIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[1])
				&& mpIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[2])
				&& mpIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[3])) || g_MpWeaponSets[i].unk0c != 0x5c) {
			count++;
		}
	}

	return count;
}

s32 func0f188f9c(s32 arg0)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpWeaponSets); i++) {
		// @bug? Shouldn't the disabled check be == WEAPON_DISABLED?
		if ((mpIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[0])
					&& mpIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[1])
					&& mpIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[2])
					&& mpIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[3]))
				|| g_MpWeaponSets[i].unk0c != WEAPON_DISABLED) {
			if (arg0 == 0) {
				break;
			}

			arg0--;
		}
	}

	return i + arg0;
}

s32 func0f189058(s32 arg0)
{
	return mpCountWeaponSetThing(arg0 ? 15 : 12);
}

s32 func0f189088(void)
{
	return mpCountWeaponSetThing(14);
}

char *mpGetWeaponSetName(s32 index)
{
	index = func0f188f9c(index);

	if (index < 0 || index >= 14) {
		return langGet(L_MPWEAPONS(41)); // "Custom"
	}

	if (index == 13) {
		return langGet(L_MPWEAPONS(42)); // "Random"
	}

	if (index == 12) {
		return langGet(L_MPWEAPONS(43)); // "Random Five"
	}

	return langGet(g_MpWeaponSets[index].name);
}

GLOBAL_ASM(
glabel func0f18913c
/*  f18913c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f189140:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f189144:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f189148:	3c0f8008 */ 	lui	$t7,%hi(g_MpWeaponSets)
/*  f18914c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f189150:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f189154:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f189158:	25ef73f0 */ 	addiu	$t7,$t7,%lo(g_MpWeaponSets)
/*  f18915c:	3c158008 */ 	lui	$s5,%hi(g_MpWeapons)
/*  f189160:	3c17800b */ 	lui	$s7,%hi(g_MpSetup+0x6)
/*  f189164:	00007100 */ 	sll	$t6,$zero,0x4
/*  f189168:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f18916c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f189170:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f189174:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f189178:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18917c:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f189180:	01cff021 */ 	addu	$s8,$t6,$t7
/*  f189184:	26f7cb8e */ 	addiu	$s7,$s7,%lo(g_MpSetup+0x6)
/*  f189188:	26b57268 */ 	addiu	$s5,$s5,%lo(g_MpWeapons)
/*  f18918c:	2414005b */ 	addiu	$s4,$zero,0x5b
/*  f189190:	2416000a */ 	addiu	$s6,$zero,0xa
/*  f189194:	afa00044 */ 	sw	$zero,0x44($sp)
.L0f189198:
/*  f189198:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f18919c:	93c40008 */ 	lbu	$a0,0x8($s8)
/*  f1891a0:	50400010 */ 	beqzl	$v0,.L0f1891e4
/*  f1891a4:	93d8000c */ 	lbu	$t8,0xc($s8)
/*  f1891a8:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f1891ac:	93c40009 */ 	lbu	$a0,0x9($s8)
/*  f1891b0:	5040000c */ 	beqzl	$v0,.L0f1891e4
/*  f1891b4:	93d8000c */ 	lbu	$t8,0xc($s8)
/*  f1891b8:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f1891bc:	93c4000a */ 	lbu	$a0,0xa($s8)
/*  f1891c0:	50400008 */ 	beqzl	$v0,.L0f1891e4
/*  f1891c4:	93d8000c */ 	lbu	$t8,0xc($s8)
/*  f1891c8:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f1891cc:	93c4000b */ 	lbu	$a0,0xb($s8)
/*  f1891d0:	50400004 */ 	beqzl	$v0,.L0f1891e4
/*  f1891d4:	93d8000c */ 	lbu	$t8,0xc($s8)
/*  f1891d8:	10000008 */ 	b	.L0f1891fc
/*  f1891dc:	27c20002 */ 	addiu	$v0,$s8,0x2
/*  f1891e0:	93d8000c */ 	lbu	$t8,0xc($s8)
.L0f1891e4:
/*  f1891e4:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f1891e8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1891ec:	13010003 */ 	beq	$t8,$at,.L0f1891fc
/*  f1891f0:	00000000 */ 	nop
/*  f1891f4:	10000001 */ 	b	.L0f1891fc
/*  f1891f8:	27c2000c */ 	addiu	$v0,$s8,0xc
.L0f1891fc:
/*  f1891fc:	1040001d */ 	beqz	$v0,.L0f189274
/*  f189200:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f189204:	3c11800b */ 	lui	$s1,%hi(g_MpSetup)
/*  f189208:	2631cb88 */ 	addiu	$s1,$s1,%lo(g_MpSetup)
/*  f18920c:	00409025 */ 	or	$s2,$v0,$zero
.L0f189210:
/*  f189210:	92500000 */ 	lbu	$s0,0x0($s2)
/*  f189214:	56140007 */ 	bnel	$s0,$s4,.L0f189234
/*  f189218:	92390018 */ 	lbu	$t9,0x18($s1)
/*  f18921c:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f189220:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f189224:	54400003 */ 	bnezl	$v0,.L0f189234
/*  f189228:	92390018 */ 	lbu	$t9,0x18($s1)
/*  f18922c:	00008025 */ 	or	$s0,$zero,$zero
/*  f189230:	92390018 */ 	lbu	$t9,0x18($s1)
.L0f189234:
/*  f189234:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f189238:	03360019 */ 	multu	$t9,$s6
/*  f18923c:	00004012 */ 	mflo	$t0
/*  f189240:	02a84821 */ 	addu	$t1,$s5,$t0
/*  f189244:	912a0000 */ 	lbu	$t2,0x0($t1)
/*  f189248:	120a0002 */ 	beq	$s0,$t2,.L0f189254
/*  f18924c:	00000000 */ 	nop
/*  f189250:	00009825 */ 	or	$s3,$zero,$zero
.L0f189254:
/*  f189254:	1637ffee */ 	bne	$s1,$s7,.L0f189210
/*  f189258:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18925c:	12600005 */ 	beqz	$s3,.L0f189274
/*  f189260:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f189264:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f189268:	3c018008 */ 	lui	$at,%hi(var800874c8)
/*  f18926c:	afab0040 */ 	sw	$t3,0x40($sp)
/*  f189270:	ac2274c8 */ 	sw	$v0,%lo(var800874c8)($at)
.L0f189274:
/*  f189274:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f189278:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f18927c:	27de0012 */ 	addiu	$s8,$s8,0x12
/*  f189280:	15800004 */ 	bnez	$t4,.L0f189294
/*  f189284:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f189288:	2401000c */ 	addiu	$at,$zero,0xc
/*  f18928c:	1441ffc2 */ 	bne	$v0,$at,.L0f189198
/*  f189290:	afa20044 */ 	sw	$v0,0x44($sp)
.L0f189294:
/*  f189294:	8fad0040 */ 	lw	$t5,0x40($sp)
/*  f189298:	240e000e */ 	addiu	$t6,$zero,0xe
/*  f18929c:	3c018008 */ 	lui	$at,%hi(var800874c8)
/*  f1892a0:	55a00003 */ 	bnezl	$t5,.L0f1892b0
/*  f1892a4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1892a8:	ac2e74c8 */ 	sw	$t6,%lo(var800874c8)($at)
/*  f1892ac:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1892b0:
/*  f1892b0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1892b4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1892b8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1892bc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1892c0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1892c4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f1892c8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f1892cc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f1892d0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f1892d4:	03e00008 */ 	jr	$ra
/*  f1892d8:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f1892dc
/*  f1892dc:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f1892e0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1892e4:	3c108008 */ 	lui	$s0,%hi(var800874c8)
/*  f1892e8:	261074c8 */ 	addiu	$s0,$s0,%lo(var800874c8)
/*  f1892ec:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f1892f0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1892f4:	04400077 */ 	bltz	$v0,.L0f1894d4
/*  f1892f8:	2841000c */ 	slti	$at,$v0,0xc
/*  f1892fc:	10200075 */ 	beqz	$at,.L0f1894d4
/*  f189300:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f189304:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f189308:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f18930c:	3c048008 */ 	lui	$a0,%hi(g_MpWeaponSets+0x8)
/*  f189310:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f189314:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f189318:	908473f8 */ 	lbu	$a0,%lo(g_MpWeaponSets+0x8)($a0)
/*  f18931c:	50400029 */ 	beqzl	$v0,.L0f1893c4
/*  f189320:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f189324:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f189328:	3c048008 */ 	lui	$a0,%hi(g_MpWeaponSets+0x9)
/*  f18932c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f189330:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f189334:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f189338:	00982021 */ 	addu	$a0,$a0,$t8
/*  f18933c:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f189340:	908473f9 */ 	lbu	$a0,%lo(g_MpWeaponSets+0x9)($a0)
/*  f189344:	5040001f */ 	beqzl	$v0,.L0f1893c4
/*  f189348:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18934c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f189350:	3c048008 */ 	lui	$a0,%hi(g_MpWeaponSets+0xa)
/*  f189354:	001960c0 */ 	sll	$t4,$t9,0x3
/*  f189358:	01996021 */ 	addu	$t4,$t4,$t9
/*  f18935c:	000c6040 */ 	sll	$t4,$t4,0x1
/*  f189360:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f189364:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f189368:	908473fa */ 	lbu	$a0,%lo(g_MpWeaponSets+0xa)($a0)
/*  f18936c:	50400015 */ 	beqzl	$v0,.L0f1893c4
/*  f189370:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f189374:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f189378:	3c048008 */ 	lui	$a0,%hi(g_MpWeaponSets+0xb)
/*  f18937c:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f189380:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f189384:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f189388:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f18938c:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f189390:	908473fb */ 	lbu	$a0,%lo(g_MpWeaponSets+0xb)($a0)
/*  f189394:	5040000b */ 	beqzl	$v0,.L0f1893c4
/*  f189398:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18939c:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1893a0:	3c0c8008 */ 	lui	$t4,%hi(g_MpWeaponSets)
/*  f1893a4:	258c73f0 */ 	addiu	$t4,$t4,%lo(g_MpWeaponSets)
/*  f1893a8:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f1893ac:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1893b0:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f1893b4:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f1893b8:	1000000f */ 	b	.L0f1893f8
/*  f1893bc:	032c1021 */ 	addu	$v0,$t9,$t4
/*  f1893c0:	8e0d0000 */ 	lw	$t5,0x0($s0)
.L0f1893c4:
/*  f1893c4:	3c0f8008 */ 	lui	$t7,%hi(g_MpWeaponSets)
/*  f1893c8:	25ef73f0 */ 	addiu	$t7,$t7,%lo(g_MpWeaponSets)
/*  f1893cc:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f1893d0:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f1893d4:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f1893d8:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f1893dc:	9078000c */ 	lbu	$t8,0xc($v1)
/*  f1893e0:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f1893e4:	53010004 */ 	beql	$t8,$at,.L0f1893f8
/*  f1893e8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1893ec:	10000002 */ 	b	.L0f1893f8
/*  f1893f0:	2462000c */ 	addiu	$v0,$v1,0xc
/*  f1893f4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1893f8:
/*  f1893f8:	1040006b */ 	beqz	$v0,.L0f1895a8
/*  f1893fc:	00405825 */ 	or	$t3,$v0,$zero
/*  f189400:	3c0a800b */ 	lui	$t2,%hi(g_MpSetup)
/*  f189404:	3c088008 */ 	lui	$t0,%hi(g_MpWeapons)
/*  f189408:	25087268 */ 	addiu	$t0,$t0,%lo(g_MpWeapons)
/*  f18940c:	254acb88 */ 	addiu	$t2,$t2,%lo(g_MpSetup)
/*  f189410:	2410005b */ 	addiu	$s0,$zero,0x5b
/*  f189414:	2409000a */ 	addiu	$t1,$zero,0xa
.L0f189418:
/*  f189418:	91660000 */ 	lbu	$a2,0x0($t3)
/*  f18941c:	00002825 */ 	or	$a1,$zero,$zero
/*  f189420:	00003825 */ 	or	$a3,$zero,$zero
/*  f189424:	14d00014 */ 	bne	$a2,$s0,.L0f189478
/*  f189428:	00001825 */ 	or	$v1,$zero,$zero
/*  f18942c:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f189430:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f189434:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f189438:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f18943c:	afa0003c */ 	sw	$zero,0x3c($sp)
/*  f189440:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f189444:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f189448:	afab0028 */ 	sw	$t3,0x28($sp)
/*  f18944c:	3c088008 */ 	lui	$t0,%hi(g_MpWeapons)
/*  f189450:	25087268 */ 	addiu	$t0,$t0,%lo(g_MpWeapons)
/*  f189454:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f189458:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f18945c:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f189460:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f189464:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f189468:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f18946c:	14400002 */ 	bnez	$v0,.L0f189478
/*  f189470:	8fab0028 */ 	lw	$t3,0x28($sp)
/*  f189474:	00003025 */ 	or	$a2,$zero,$zero
.L0f189478:
/*  f189478:	2c610027 */ 	sltiu	$at,$v1,0x27
/*  f18947c:	14200003 */ 	bnez	$at,.L0f18948c
/*  f189480:	00000000 */ 	nop
/*  f189484:	10000009 */ 	b	.L0f1894ac
/*  f189488:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18948c:
/*  f18948c:	00690019 */ 	multu	$v1,$t1
/*  f189490:	0000c812 */ 	mflo	$t9
/*  f189494:	01196021 */ 	addu	$t4,$t0,$t9
/*  f189498:	918d0000 */ 	lbu	$t5,0x0($t4)
/*  f18949c:	14cd0003 */ 	bne	$a2,$t5,.L0f1894ac
/*  f1894a0:	00000000 */ 	nop
/*  f1894a4:	00603825 */ 	or	$a3,$v1,$zero
/*  f1894a8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1894ac:
/*  f1894ac:	10a0fff2 */ 	beqz	$a1,.L0f189478
/*  f1894b0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1894b4:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0x6)
/*  f1894b8:	25cecb8e */ 	addiu	$t6,$t6,%lo(g_MpSetup+0x6)
/*  f1894bc:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f1894c0:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f1894c4:	154effd4 */ 	bne	$t2,$t6,.L0f189418
/*  f1894c8:	a1470017 */ 	sb	$a3,0x17($t2)
/*  f1894cc:	10000037 */ 	b	.L0f1895ac
/*  f1894d0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1894d4:
/*  f1894d4:	2401000d */ 	addiu	$at,$zero,0xd
/*  f1894d8:	54410017 */ 	bnel	$v0,$at,.L0f189538
/*  f1894dc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1894e0:	0fc622f5 */ 	jal	mpGetNumWeaponOptions
/*  f1894e4:	00000000 */ 	nop
/*  f1894e8:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f1894ec:	00008025 */ 	or	$s0,$zero,$zero
.L0f1894f0:
/*  f1894f0:	0c004b70 */ 	jal	random
/*  f1894f4:	00000000 */ 	nop
/*  f1894f8:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f1894fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f189500:	004f001b */ 	divu	$zero,$v0,$t7
/*  f189504:	00002810 */ 	mfhi	$a1
/*  f189508:	15e00002 */ 	bnez	$t7,.L0f189514
/*  f18950c:	00000000 */ 	nop
/*  f189510:	0007000d */ 	break	0x7
.L0f189514:
/*  f189514:	0fc62346 */ 	jal	mpSetWeaponSlot
/*  f189518:	00000000 */ 	nop
/*  f18951c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f189520:	24010006 */ 	addiu	$at,$zero,0x6
/*  f189524:	1601fff2 */ 	bne	$s0,$at,.L0f1894f0
/*  f189528:	00000000 */ 	nop
/*  f18952c:	1000001f */ 	b	.L0f1895ac
/*  f189530:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f189534:	2401000c */ 	addiu	$at,$zero,0xc
.L0f189538:
/*  f189538:	5441001c */ 	bnel	$v0,$at,.L0f1895ac
/*  f18953c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f189540:	0fc622f5 */ 	jal	mpGetNumWeaponOptions
/*  f189544:	00000000 */ 	nop
/*  f189548:	2458fffe */ 	addiu	$t8,$v0,-2
/*  f18954c:	afb80030 */ 	sw	$t8,0x30($sp)
/*  f189550:	00008025 */ 	or	$s0,$zero,$zero
.L0f189554:
/*  f189554:	0c004b70 */ 	jal	random
/*  f189558:	00000000 */ 	nop
/*  f18955c:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f189560:	02002025 */ 	or	$a0,$s0,$zero
/*  f189564:	0059001b */ 	divu	$zero,$v0,$t9
/*  f189568:	00002810 */ 	mfhi	$a1
/*  f18956c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f189570:	17200002 */ 	bnez	$t9,.L0f18957c
/*  f189574:	00000000 */ 	nop
/*  f189578:	0007000d */ 	break	0x7
.L0f18957c:
/*  f18957c:	0fc62346 */ 	jal	mpSetWeaponSlot
/*  f189580:	00000000 */ 	nop
/*  f189584:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f189588:	24010005 */ 	addiu	$at,$zero,0x5
/*  f18958c:	1601fff1 */ 	bne	$s0,$at,.L0f189554
/*  f189590:	00000000 */ 	nop
/*  f189594:	0fc622f5 */ 	jal	mpGetNumWeaponOptions
/*  f189598:	00000000 */ 	nop
/*  f18959c:	02002025 */ 	or	$a0,$s0,$zero
/*  f1895a0:	0fc62346 */ 	jal	mpSetWeaponSlot
/*  f1895a4:	2445ffff */ 	addiu	$a1,$v0,-1
.L0f1895a8:
/*  f1895a8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1895ac:
/*  f1895ac:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1895b0:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f1895b4:	03e00008 */ 	jr	$ra
/*  f1895b8:	00000000 */ 	nop
);

void mpSetWeaponSet(s32 weaponsetnum)
{
	var800874c8 = func0f188f9c(weaponsetnum);
	func0f1892dc();
}

GLOBAL_ASM(
glabel func0f1895e8
/*  f1895e8:	3c0e8008 */ 	lui	$t6,%hi(var800874c8)
/*  f1895ec:	8dce74c8 */ 	lw	$t6,%lo(var800874c8)($t6)
/*  f1895f0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1895f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1895f8:	29c1000c */ 	slti	$at,$t6,0xc
/*  f1895fc:	50200004 */ 	beqzl	$at,.L0f189610
/*  f189600:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189604:	0fc624b7 */ 	jal	func0f1892dc
/*  f189608:	00000000 */ 	nop
/*  f18960c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f189610:
/*  f189610:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f189614:	03e00008 */ 	jr	$ra
/*  f189618:	00000000 */ 	nop
);

s32 mpGetWeaponSet(void)
{
	return mpCountWeaponSetThing(var800874c8);
}

bool mpIsPaused(void)
{
	if (PLAYERCOUNT() == 1
			&& g_Vars.mplayerisrunning
			&& g_Menus[g_Vars.currentplayerstats->mpindex].curframe) {
		return true;
	}

	if (g_MpSetup.paused == PAUSEMODE_UNPAUSED) {
		return false;
	}

	return true;
}

void mpSetPaused(u8 mode)
{
	g_MpSetup.paused = mode;
}

/**
 * Render "Paused" in the middle of the viewport if paused,
 * or "Press START" if player has finished their death animation.
 */
GLOBAL_ASM(
glabel mpRenderModalText
/*  f18973c:	3c02800b */ 	lui	$v0,%hi(g_MpSetup+0x1e)
/*  f189740:	9042cba6 */ 	lbu	$v0,%lo(g_MpSetup+0x1e)($v0)
/*  f189744:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f189748:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18974c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f189750:	14410077 */ 	bne	$v0,$at,.L0f189930
/*  f189754:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f189758:	3c013f80 */ 	lui	$at,0x3f80
/*  f18975c:	44812000 */ 	mtc1	$at,$f4
/*  f189760:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f189764:	c4261630 */ 	lwc1	$f6,%lo(var80061630)($at)
/*  f189768:	3c0141a0 */ 	lui	$at,0x41a0
/*  f18976c:	44815000 */ 	mtc1	$at,$f10
/*  f189770:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f189774:	3c01437f */ 	lui	$at,0x437f
/*  f189778:	44819000 */ 	mtc1	$at,$f18
/*  f18977c:	240100ff */ 	addiu	$at,$zero,0xff
/*  f189780:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f189784:	00000000 */ 	nop
/*  f189788:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f18978c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f189790:	440f3000 */ 	mfc1	$t7,$f6
/*  f189794:	00000000 */ 	nop
/*  f189798:	01e1001a */ 	div	$zero,$t7,$at
/*  f18979c:	0000c010 */ 	mfhi	$t8
/*  f1897a0:	afb80054 */ 	sw	$t8,0x54($sp)
/*  f1897a4:	0fc54d8a */ 	jal	func0f153628
/*  f1897a8:	00000000 */ 	nop
/*  f1897ac:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f1897b0:	0fc5b9f1 */ 	jal	langGet
/*  f1897b4:	24045428 */ 	addiu	$a0,$zero,0x5428
/*  f1897b8:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f1897bc:	0c004c4c */ 	jal	strcpy
/*  f1897c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1897c4:	0c002f40 */ 	jal	viGetViewLeft
/*  f1897c8:	00000000 */ 	nop
/*  f1897cc:	0c002f22 */ 	jal	viGetViewWidth
/*  f1897d0:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f1897d4:	87a80042 */ 	lh	$t0,0x42($sp)
/*  f1897d8:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x288)
/*  f1897dc:	8d4aa248 */ 	lw	$t2,%lo(g_Vars+0x288)($t2)
/*  f1897e0:	04410003 */ 	bgez	$v0,.L0f1897f0
/*  f1897e4:	0002c843 */ 	sra	$t9,$v0,0x1
/*  f1897e8:	24410001 */ 	addiu	$at,$v0,0x1
/*  f1897ec:	0001c843 */ 	sra	$t9,$at,0x1
.L0f1897f0:
/*  f1897f0:	03284821 */ 	addu	$t1,$t9,$t0
/*  f1897f4:	afa90094 */ 	sw	$t1,0x94($sp)
/*  f1897f8:	8d4b0070 */ 	lw	$t3,0x70($t2)
/*  f1897fc:	3c0d800a */ 	lui	$t5,%hi(g_Menus+0x4f8)
/*  f189800:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f189804:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f189808:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f18980c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f189810:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f189814:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f189818:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f18981c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f189820:	8dade4f8 */ 	lw	$t5,%lo(g_Menus+0x4f8)($t5)
/*  f189824:	11a00006 */ 	beqz	$t5,.L0f189840
/*  f189828:	00000000 */ 	nop
/*  f18982c:	0c002f44 */ 	jal	viGetViewTop
/*  f189830:	00000000 */ 	nop
/*  f189834:	244e000a */ 	addiu	$t6,$v0,0xa
/*  f189838:	1000000c */ 	b	.L0f18986c
/*  f18983c:	afae0090 */ 	sw	$t6,0x90($sp)
.L0f189840:
/*  f189840:	0c002f44 */ 	jal	viGetViewTop
/*  f189844:	00000000 */ 	nop
/*  f189848:	0c002f26 */ 	jal	viGetViewHeight
/*  f18984c:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f189850:	87b80042 */ 	lh	$t8,0x42($sp)
/*  f189854:	04410003 */ 	bgez	$v0,.L0f189864
/*  f189858:	00027843 */ 	sra	$t7,$v0,0x1
/*  f18985c:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189860:	00017843 */ 	sra	$t7,$at,0x1
.L0f189864:
/*  f189864:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f189868:	afb90090 */ 	sw	$t9,0x90($sp)
.L0f18986c:
/*  f18986c:	3c088008 */ 	lui	$t0,%hi(g_FontHandelGothicMd2)
/*  f189870:	8d08fb14 */ 	lw	$t0,%lo(g_FontHandelGothicMd2)($t0)
/*  f189874:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicMd1)
/*  f189878:	8ce7fb18 */ 	lw	$a3,%lo(g_FontHandelGothicMd1)($a3)
/*  f18987c:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f189880:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f189884:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f189888:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18988c:	0fc55cbe */ 	jal	textMeasure
/*  f189890:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f189894:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f189898:	8fa90094 */ 	lw	$t1,0x94($sp)
/*  f18989c:	05410003 */ 	bgez	$t2,.L0f1898ac
/*  f1898a0:	000a5843 */ 	sra	$t3,$t2,0x1
/*  f1898a4:	25410001 */ 	addiu	$at,$t2,0x1
/*  f1898a8:	00015843 */ 	sra	$t3,$at,0x1
.L0f1898ac:
/*  f1898ac:	012b6023 */ 	subu	$t4,$t1,$t3
/*  f1898b0:	0c002f02 */ 	jal	viGetWidth
/*  f1898b4:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f1898b8:	0c002f02 */ 	jal	viGetWidth
/*  f1898bc:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f1898c0:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f1898c4:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicMd1)
/*  f1898c8:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicMd2)
/*  f1898cc:	3c0100ff */ 	lui	$at,0xff
/*  f1898d0:	8dcefb14 */ 	lw	$t6,%lo(g_FontHandelGothicMd2)($t6)
/*  f1898d4:	8dadfb18 */ 	lw	$t5,%lo(g_FontHandelGothicMd1)($t5)
/*  f1898d8:	87aa0040 */ 	lh	$t2,0x40($sp)
/*  f1898dc:	342100ff */ 	ori	$at,$at,0xff
/*  f1898e0:	000fc600 */ 	sll	$t8,$t7,0x18
/*  f1898e4:	0301c825 */ 	or	$t9,$t8,$at
/*  f1898e8:	240800ff */ 	addiu	$t0,$zero,0xff
/*  f1898ec:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f1898f0:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1898f4:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f1898f8:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f1898fc:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f189900:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f189904:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f189908:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18990c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f189910:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f189914:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f189918:	0fc55b92 */ 	jal	textRender
/*  f18991c:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f189920:	0fc54de0 */ 	jal	func0f153780
/*  f189924:	00402025 */ 	or	$a0,$v0,$zero
/*  f189928:	100000e0 */ 	b	.L0f189cac
/*  f18992c:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0f189930:
/*  f189930:	3c098006 */ 	lui	$t1,%hi(var8005d9d0)
/*  f189934:	8d29d9d0 */ 	lw	$t1,%lo(var8005d9d0)($t1)
/*  f189938:	552000dd */ 	bnezl	$t1,.L0f189cb0
/*  f18993c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f189940:	144000da */ 	bnez	$v0,.L0f189cac
/*  f189944:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f189948:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f18994c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f189950:	8c4b00d8 */ 	lw	$t3,0xd8($v0)
/*  f189954:	516000d6 */ 	beqzl	$t3,.L0f189cb0
/*  f189958:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18995c:	8c4c032c */ 	lw	$t4,0x32c($v0)
/*  f189960:	518000d3 */ 	beqzl	$t4,.L0f189cb0
/*  f189964:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f189968:	8c4d0330 */ 	lw	$t5,0x330($v0)
/*  f18996c:	51a000d0 */ 	beqzl	$t5,.L0f189cb0
/*  f189970:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f189974:	8c6e0298 */ 	lw	$t6,0x298($v1)
/*  f189978:	05c20011 */ 	bltzl	$t6,.L0f1899c0
/*  f18997c:	8c6b029c */ 	lw	$t3,0x29c($v1)
/*  f189980:	8c6f02a0 */ 	lw	$t7,0x2a0($v1)
/*  f189984:	8df800d8 */ 	lw	$t8,0xd8($t7)
/*  f189988:	53000006 */ 	beqzl	$t8,.L0f1899a4
/*  f18998c:	8c4a1c10 */ 	lw	$t2,0x1c10($v0)
/*  f189990:	8c7902a4 */ 	lw	$t9,0x2a4($v1)
/*  f189994:	8f2800d8 */ 	lw	$t0,0xd8($t9)
/*  f189998:	550000c5 */ 	bnezl	$t0,.L0f189cb0
/*  f18999c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899a0:	8c4a1c10 */ 	lw	$t2,0x1c10($v0)
.L0f1899a4:
/*  f1899a4:	3c098007 */ 	lui	$t1,%hi(g_InCutscene)
/*  f1899a8:	514000c1 */ 	beqzl	$t2,.L0f189cb0
/*  f1899ac:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899b0:	8d290764 */ 	lw	$t1,%lo(g_InCutscene)($t1)
/*  f1899b4:	552000be */ 	bnezl	$t1,.L0f189cb0
/*  f1899b8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899bc:	8c6b029c */ 	lw	$t3,0x29c($v1)
.L0f1899c0:
/*  f1899c0:	3c0e8008 */ 	lui	$t6,%hi(g_NumReasonsToEndMpMatch)
/*  f1899c4:	05600008 */ 	bltz	$t3,.L0f1899e8
/*  f1899c8:	00000000 */ 	nop
/*  f1899cc:	8c6c02a8 */ 	lw	$t4,0x2a8($v1)
/*  f1899d0:	3c0d8007 */ 	lui	$t5,%hi(g_InCutscene)
/*  f1899d4:	558200b6 */ 	bnel	$t4,$v0,.L0f189cb0
/*  f1899d8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899dc:	8dad0764 */ 	lw	$t5,%lo(g_InCutscene)($t5)
/*  f1899e0:	55a000b3 */ 	bnezl	$t5,.L0f189cb0
/*  f1899e4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f1899e8:
/*  f1899e8:	8dce4038 */ 	lw	$t6,%lo(g_NumReasonsToEndMpMatch)($t6)
/*  f1899ec:	55c000b0 */ 	bnezl	$t6,.L0f189cb0
/*  f1899f0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1899f4:	0fc54d8a */ 	jal	func0f153628
/*  f1899f8:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f1899fc:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f189a00:	0fc5b9f1 */ 	jal	langGet
/*  f189a04:	24045427 */ 	addiu	$a0,$zero,0x5427
/*  f189a08:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f189a0c:	0c004c4c */ 	jal	strcpy
/*  f189a10:	00402825 */ 	or	$a1,$v0,$zero
/*  f189a14:	0c002f40 */ 	jal	viGetViewLeft
/*  f189a18:	00000000 */ 	nop
/*  f189a1c:	0c002f22 */ 	jal	viGetViewWidth
/*  f189a20:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f189a24:	87b80042 */ 	lh	$t8,0x42($sp)
/*  f189a28:	04410003 */ 	bgez	$v0,.L0f189a38
/*  f189a2c:	00027843 */ 	sra	$t7,$v0,0x1
/*  f189a30:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189a34:	00017843 */ 	sra	$t7,$at,0x1
.L0f189a38:
/*  f189a38:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f189a3c:	0c002f44 */ 	jal	viGetViewTop
/*  f189a40:	afb90094 */ 	sw	$t9,0x94($sp)
/*  f189a44:	0c002f26 */ 	jal	viGetViewHeight
/*  f189a48:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f189a4c:	87aa0042 */ 	lh	$t2,0x42($sp)
/*  f189a50:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicSm2)
/*  f189a54:	8d6bfb0c */ 	lw	$t3,%lo(g_FontHandelGothicSm2)($t3)
/*  f189a58:	04410003 */ 	bgez	$v0,.L0f189a68
/*  f189a5c:	00024043 */ 	sra	$t0,$v0,0x1
/*  f189a60:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189a64:	00014043 */ 	sra	$t0,$at,0x1
.L0f189a68:
/*  f189a68:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm1)
/*  f189a6c:	010a4821 */ 	addu	$t1,$t0,$t2
/*  f189a70:	afa90090 */ 	sw	$t1,0x90($sp)
/*  f189a74:	8ce7fb10 */ 	lw	$a3,%lo(g_FontHandelGothicSm1)($a3)
/*  f189a78:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f189a7c:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f189a80:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f189a84:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f189a88:	0fc55cbe */ 	jal	textMeasure
/*  f189a8c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f189a90:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f189a94:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f189a98:	05a10003 */ 	bgez	$t5,.L0f189aa8
/*  f189a9c:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f189aa0:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f189aa4:	00017043 */ 	sra	$t6,$at,0x1
.L0f189aa8:
/*  f189aa8:	018e7823 */ 	subu	$t7,$t4,$t6
/*  f189aac:	0c002f02 */ 	jal	viGetWidth
/*  f189ab0:	afaf0094 */ 	sw	$t7,0x94($sp)
/*  f189ab4:	0c002f02 */ 	jal	viGetWidth
/*  f189ab8:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f189abc:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicSm1)
/*  f189ac0:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm2)
/*  f189ac4:	8f39fb0c */ 	lw	$t9,%lo(g_FontHandelGothicSm2)($t9)
/*  f189ac8:	8f18fb10 */ 	lw	$t8,%lo(g_FontHandelGothicSm1)($t8)
/*  f189acc:	87a90040 */ 	lh	$t1,0x40($sp)
/*  f189ad0:	3c08ff00 */ 	lui	$t0,0xff00
/*  f189ad4:	350800ff */ 	ori	$t0,$t0,0xff
/*  f189ad8:	240a00ff */ 	addiu	$t2,$zero,0xff
/*  f189adc:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f189ae0:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f189ae4:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f189ae8:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f189aec:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f189af0:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f189af4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f189af8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f189afc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f189b00:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f189b04:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f189b08:	0fc55b92 */ 	jal	textRender
/*  f189b0c:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f189b10:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x284)
/*  f189b14:	8d6ba244 */ 	lw	$t3,%lo(g_Vars+0x284)($t3)
/*  f189b18:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f189b1c:	8d6d1c0c */ 	lw	$t5,0x1c0c($t3)
/*  f189b20:	19a00051 */ 	blez	$t5,.L0f189c68
/*  f189b24:	00000000 */ 	nop
/*  f189b28:	0c002f44 */ 	jal	viGetViewTop
/*  f189b2c:	00000000 */ 	nop
/*  f189b30:	0c002f26 */ 	jal	viGetViewHeight
/*  f189b34:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f189b38:	87ae0042 */ 	lh	$t6,0x42($sp)
/*  f189b3c:	8fb80098 */ 	lw	$t8,0x98($sp)
/*  f189b40:	04410003 */ 	bgez	$v0,.L0f189b50
/*  f189b44:	00026043 */ 	sra	$t4,$v0,0x1
/*  f189b48:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189b4c:	00016043 */ 	sra	$t4,$at,0x1
.L0f189b50:
/*  f189b50:	018e7821 */ 	addu	$t7,$t4,$t6
/*  f189b54:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f189b58:	27280002 */ 	addiu	$t0,$t9,0x2
/*  f189b5c:	0c002f40 */ 	jal	viGetViewLeft
/*  f189b60:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f189b64:	0c002f22 */ 	jal	viGetViewWidth
/*  f189b68:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f189b6c:	87a90042 */ 	lh	$t1,0x42($sp)
/*  f189b70:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x284)
/*  f189b74:	8dada244 */ 	lw	$t5,%lo(g_Vars+0x284)($t5)
/*  f189b78:	04410003 */ 	bgez	$v0,.L0f189b88
/*  f189b7c:	00025043 */ 	sra	$t2,$v0,0x1
/*  f189b80:	24410001 */ 	addiu	$at,$v0,0x1
/*  f189b84:	00015043 */ 	sra	$t2,$at,0x1
.L0f189b88:
/*  f189b88:	01495821 */ 	addu	$t3,$t2,$t1
/*  f189b8c:	afab0048 */ 	sw	$t3,0x48($sp)
/*  f189b90:	8da61c0c */ 	lw	$a2,0x1c0c($t5)
/*  f189b94:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f189b98:	3c057f1c */ 	lui	$a1,%hi(var7f1b8aa4)
/*  f189b9c:	24c6003b */ 	addiu	$a2,$a2,0x3b
/*  f189ba0:	00c1001a */ 	div	$zero,$a2,$at
/*  f189ba4:	00003012 */ 	mflo	$a2
/*  f189ba8:	24a58aa4 */ 	addiu	$a1,$a1,%lo(var7f1b8aa4)
/*  f189bac:	0c004dad */ 	jal	sprintf
/*  f189bb0:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f189bb4:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicSm2)
/*  f189bb8:	8dcefb0c */ 	lw	$t6,%lo(g_FontHandelGothicSm2)($t6)
/*  f189bbc:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm1)
/*  f189bc0:	8ce7fb10 */ 	lw	$a3,%lo(g_FontHandelGothicSm1)($a3)
/*  f189bc4:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f189bc8:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f189bcc:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f189bd0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f189bd4:	0fc55cbe */ 	jal	textMeasure
/*  f189bd8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f189bdc:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f189be0:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f189be4:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f189be8:	07010003 */ 	bgez	$t8,.L0f189bf8
/*  f189bec:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f189bf0:	27010001 */ 	addiu	$at,$t8,0x1
/*  f189bf4:	0001c843 */ 	sra	$t9,$at,0x1
.L0f189bf8:
/*  f189bf8:	01f94023 */ 	subu	$t0,$t7,$t9
/*  f189bfc:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f189c00:	0c002f02 */ 	jal	viGetWidth
/*  f189c04:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f189c08:	0c002f02 */ 	jal	viGetWidth
/*  f189c0c:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f189c10:	3c098008 */ 	lui	$t1,%hi(g_FontHandelGothicSm1)
/*  f189c14:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicSm2)
/*  f189c18:	8d6bfb0c */ 	lw	$t3,%lo(g_FontHandelGothicSm2)($t3)
/*  f189c1c:	8d29fb10 */ 	lw	$t1,%lo(g_FontHandelGothicSm1)($t1)
/*  f189c20:	87ae0040 */ 	lh	$t6,0x40($sp)
/*  f189c24:	3c0dff00 */ 	lui	$t5,0xff00
/*  f189c28:	35ad00ff */ 	ori	$t5,$t5,0xff
/*  f189c2c:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f189c30:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f189c34:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f189c38:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f189c3c:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f189c40:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f189c44:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f189c48:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f189c4c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f189c50:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f189c54:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f189c58:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f189c5c:	0fc55b92 */ 	jal	textRender
/*  f189c60:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f189c64:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0f189c68:
/*  f189c68:	0fc54de0 */ 	jal	func0f153780
/*  f189c6c:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f189c70:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x288)
/*  f189c74:	8defa248 */ 	lw	$t7,%lo(g_Vars+0x288)($t7)
/*  f189c78:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f189c7c:	3c01800a */ 	lui	$at,%hi(g_Menus+0x83c)
/*  f189c80:	8df90070 */ 	lw	$t9,0x70($t7)
/*  f189c84:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f189c88:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f189c8c:	01194023 */ 	subu	$t0,$t0,$t9
/*  f189c90:	00084080 */ 	sll	$t0,$t0,0x2
/*  f189c94:	01194021 */ 	addu	$t0,$t0,$t9
/*  f189c98:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f189c9c:	01194023 */ 	subu	$t0,$t0,$t9
/*  f189ca0:	00084100 */ 	sll	$t0,$t0,0x4
/*  f189ca4:	00280821 */ 	addu	$at,$at,$t0
/*  f189ca8:	a038e83c */ 	sb	$t8,%lo(g_Menus+0x83c)($at)
.L0f189cac:
/*  f189cac:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f189cb0:
/*  f189cb0:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f189cb4:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f189cb8:	03e00008 */ 	jr	$ra
/*  f189cbc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f189cc0
/*  f189cc0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f189cc4:	28810002 */ 	slti	$at,$a0,0x2
/*  f189cc8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f189ccc:	14200039 */ 	bnez	$at,.L0f189db4
/*  f189cd0:	00004025 */ 	or	$t0,$zero,$zero
/*  f189cd4:	00a6082a */ 	slt	$at,$a1,$a2
/*  f189cd8:	54200011 */ 	bnezl	$at,.L0f189d20
/*  f189cdc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f189ce0:	54c50012 */ 	bnel	$a2,$a1,.L0f189d2c
/*  f189ce4:	00a01825 */ 	or	$v1,$a1,$zero
/*  f189ce8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189cec:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f189cf0:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f189cf4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f189cf8:	0c004b70 */ 	jal	random
/*  f189cfc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f189d00:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f189d04:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189d08:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f189d0c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f189d10:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f189d14:	11c00004 */ 	beqz	$t6,.L0f189d28
/*  f189d18:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189d1c:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f189d20:
/*  f189d20:	10000002 */ 	b	.L0f189d2c
/*  f189d24:	00c01825 */ 	or	$v1,$a2,$zero
.L0f189d28:
/*  f189d28:	00a01825 */ 	or	$v1,$a1,$zero
.L0f189d2c:
/*  f189d2c:	28810003 */ 	slti	$at,$a0,0x3
/*  f189d30:	14200020 */ 	bnez	$at,.L0f189db4
/*  f189d34:	0067082a */ 	slt	$at,$v1,$a3
/*  f189d38:	5420000f */ 	bnezl	$at,.L0f189d78
/*  f189d3c:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f189d40:	54e3000f */ 	bnel	$a3,$v1,.L0f189d80
/*  f189d44:	28810004 */ 	slti	$at,$a0,0x4
/*  f189d48:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f189d4c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189d50:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f189d54:	0c004b70 */ 	jal	random
/*  f189d58:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f189d5c:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f189d60:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f189d64:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189d68:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f189d6c:	11e00003 */ 	beqz	$t7,.L0f189d7c
/*  f189d70:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189d74:	24080002 */ 	addiu	$t0,$zero,0x2
.L0f189d78:
/*  f189d78:	00e01825 */ 	or	$v1,$a3,$zero
.L0f189d7c:
/*  f189d7c:	28810004 */ 	slti	$at,$a0,0x4
.L0f189d80:
/*  f189d80:	1420000c */ 	bnez	$at,.L0f189db4
/*  f189d84:	8fa20030 */ 	lw	$v0,0x30($sp)
/*  f189d88:	0062082a */ 	slt	$at,$v1,$v0
/*  f189d8c:	54200009 */ 	bnezl	$at,.L0f189db4
/*  f189d90:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f189d94:	54430008 */ 	bnel	$v0,$v1,.L0f189db8
/*  f189d98:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189d9c:	0c004b70 */ 	jal	random
/*  f189da0:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f189da4:	30580001 */ 	andi	$t8,$v0,0x1
/*  f189da8:	13000002 */ 	beqz	$t8,.L0f189db4
/*  f189dac:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189db0:	24080003 */ 	addiu	$t0,$zero,0x3
.L0f189db4:
/*  f189db4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f189db8:
/*  f189db8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f189dbc:	01001025 */ 	or	$v0,$t0,$zero
/*  f189dc0:	03e00008 */ 	jr	$ra
/*  f189dc4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f189dc8
/*  f189dc8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f189dcc:	28810002 */ 	slti	$at,$a0,0x2
/*  f189dd0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f189dd4:	14200039 */ 	bnez	$at,.L0f189ebc
/*  f189dd8:	00004025 */ 	or	$t0,$zero,$zero
/*  f189ddc:	00c5082a */ 	slt	$at,$a2,$a1
/*  f189de0:	54200011 */ 	bnezl	$at,.L0f189e28
/*  f189de4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f189de8:	54c50012 */ 	bnel	$a2,$a1,.L0f189e34
/*  f189dec:	00a01825 */ 	or	$v1,$a1,$zero
/*  f189df0:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189df4:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f189df8:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f189dfc:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f189e00:	0c004b70 */ 	jal	random
/*  f189e04:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f189e08:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f189e0c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189e10:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f189e14:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f189e18:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f189e1c:	11c00004 */ 	beqz	$t6,.L0f189e30
/*  f189e20:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189e24:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f189e28:
/*  f189e28:	10000002 */ 	b	.L0f189e34
/*  f189e2c:	00c01825 */ 	or	$v1,$a2,$zero
.L0f189e30:
/*  f189e30:	00a01825 */ 	or	$v1,$a1,$zero
.L0f189e34:
/*  f189e34:	28810003 */ 	slti	$at,$a0,0x3
/*  f189e38:	14200020 */ 	bnez	$at,.L0f189ebc
/*  f189e3c:	00e3082a */ 	slt	$at,$a3,$v1
/*  f189e40:	5420000f */ 	bnezl	$at,.L0f189e80
/*  f189e44:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f189e48:	54e3000f */ 	bnel	$a3,$v1,.L0f189e88
/*  f189e4c:	28810004 */ 	slti	$at,$a0,0x4
/*  f189e50:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f189e54:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189e58:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f189e5c:	0c004b70 */ 	jal	random
/*  f189e60:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f189e64:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f189e68:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f189e6c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189e70:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f189e74:	11e00003 */ 	beqz	$t7,.L0f189e84
/*  f189e78:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189e7c:	24080002 */ 	addiu	$t0,$zero,0x2
.L0f189e80:
/*  f189e80:	00e01825 */ 	or	$v1,$a3,$zero
.L0f189e84:
/*  f189e84:	28810004 */ 	slti	$at,$a0,0x4
.L0f189e88:
/*  f189e88:	1420000c */ 	bnez	$at,.L0f189ebc
/*  f189e8c:	8fa20030 */ 	lw	$v0,0x30($sp)
/*  f189e90:	0043082a */ 	slt	$at,$v0,$v1
/*  f189e94:	54200009 */ 	bnezl	$at,.L0f189ebc
/*  f189e98:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f189e9c:	54430008 */ 	bnel	$v0,$v1,.L0f189ec0
/*  f189ea0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189ea4:	0c004b70 */ 	jal	random
/*  f189ea8:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f189eac:	30580001 */ 	andi	$t8,$v0,0x1
/*  f189eb0:	13000002 */ 	beqz	$t8,.L0f189ebc
/*  f189eb4:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f189eb8:	24080003 */ 	addiu	$t0,$zero,0x3
.L0f189ebc:
/*  f189ebc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f189ec0:
/*  f189ec0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f189ec4:	01001025 */ 	or	$v0,$t0,$zero
/*  f189ec8:	03e00008 */ 	jr	$ra
/*  f189ecc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f189ed0
/*  f189ed0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f189ed4:	44856000 */ 	mtc1	$a1,$f12
/*  f189ed8:	44867000 */ 	mtc1	$a2,$f14
/*  f189edc:	28810002 */ 	slti	$at,$a0,0x2
/*  f189ee0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f189ee4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f189ee8:	1420004c */ 	bnez	$at,.L0f18a01c
/*  f189eec:	00002825 */ 	or	$a1,$zero,$zero
/*  f189ef0:	460e603c */ 	c.lt.s	$f12,$f14
/*  f189ef4:	00000000 */ 	nop
/*  f189ef8:	45030011 */ 	bc1tl	.L0f189f40
/*  f189efc:	4600710d */ 	trunc.w.s	$f4,$f14
/*  f189f00:	460c7032 */ 	c.eq.s	$f14,$f12
/*  f189f04:	00000000 */ 	nop
/*  f189f08:	45020012 */ 	bc1fl	.L0f189f54
/*  f189f0c:	4600618d */ 	trunc.w.s	$f6,$f12
/*  f189f10:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189f14:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f189f18:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*  f189f1c:	0c004b70 */ 	jal	random
/*  f189f20:	e7ae0028 */ 	swc1	$f14,0x28($sp)
/*  f189f24:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f189f28:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189f2c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f189f30:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f189f34:	11c00006 */ 	beqz	$t6,.L0f189f50
/*  f189f38:	c7ae0028 */ 	lwc1	$f14,0x28($sp)
/*  f189f3c:	4600710d */ 	trunc.w.s	$f4,$f14
.L0f189f40:
/*  f189f40:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f189f44:	44032000 */ 	mfc1	$v1,$f4
/*  f189f48:	10000005 */ 	b	.L0f189f60
/*  f189f4c:	28810003 */ 	slti	$at,$a0,0x3
.L0f189f50:
/*  f189f50:	4600618d */ 	trunc.w.s	$f6,$f12
.L0f189f54:
/*  f189f54:	44033000 */ 	mfc1	$v1,$f6
/*  f189f58:	00000000 */ 	nop
/*  f189f5c:	28810003 */ 	slti	$at,$a0,0x3
.L0f189f60:
/*  f189f60:	5420002f */ 	bnezl	$at,.L0f18a020
/*  f189f64:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189f68:	44834000 */ 	mtc1	$v1,$f8
/*  f189f6c:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f189f70:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f189f74:	460a003c */ 	c.lt.s	$f0,$f10
/*  f189f78:	00000000 */ 	nop
/*  f189f7c:	4503000f */ 	bc1tl	.L0f189fbc
/*  f189f80:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f189f84:	46005032 */ 	c.eq.s	$f10,$f0
/*  f189f88:	00000000 */ 	nop
/*  f189f8c:	45020010 */ 	bc1fl	.L0f189fd0
/*  f189f90:	28810004 */ 	slti	$at,$a0,0x4
/*  f189f94:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f189f98:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f189f9c:	0c004b70 */ 	jal	random
/*  f189fa0:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f189fa4:	30590001 */ 	andi	$t9,$v0,0x1
/*  f189fa8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f189fac:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f189fb0:	13200006 */ 	beqz	$t9,.L0f189fcc
/*  f189fb4:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f189fb8:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
.L0f189fbc:
/*  f189fbc:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f189fc0:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f189fc4:	44039000 */ 	mfc1	$v1,$f18
/*  f189fc8:	00000000 */ 	nop
.L0f189fcc:
/*  f189fcc:	28810004 */ 	slti	$at,$a0,0x4
.L0f189fd0:
/*  f189fd0:	54200013 */ 	bnezl	$at,.L0f18a020
/*  f189fd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f189fd8:	44832000 */ 	mtc1	$v1,$f4
/*  f189fdc:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f189fe0:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f189fe4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f189fe8:	00000000 */ 	nop
/*  f189fec:	4503000b */ 	bc1tl	.L0f18a01c
/*  f189ff0:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f189ff4:	46001032 */ 	c.eq.s	$f2,$f0
/*  f189ff8:	00000000 */ 	nop
/*  f189ffc:	45020008 */ 	bc1fl	.L0f18a020
/*  f18a000:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18a004:	0c004b70 */ 	jal	random
/*  f18a008:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f18a00c:	30490001 */ 	andi	$t1,$v0,0x1
/*  f18a010:	11200002 */ 	beqz	$t1,.L0f18a01c
/*  f18a014:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f18a018:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f18a01c:
/*  f18a01c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f18a020:
/*  f18a020:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f18a024:	00a01025 */ 	or	$v0,$a1,$zero
/*  f18a028:	03e00008 */ 	jr	$ra
/*  f18a02c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f18a030
/*  f18a030:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f18a034:	44856000 */ 	mtc1	$a1,$f12
/*  f18a038:	44867000 */ 	mtc1	$a2,$f14
/*  f18a03c:	28810002 */ 	slti	$at,$a0,0x2
/*  f18a040:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18a044:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f18a048:	1420004c */ 	bnez	$at,.L0f18a17c
/*  f18a04c:	00002825 */ 	or	$a1,$zero,$zero
/*  f18a050:	460c703c */ 	c.lt.s	$f14,$f12
/*  f18a054:	00000000 */ 	nop
/*  f18a058:	45030011 */ 	bc1tl	.L0f18a0a0
/*  f18a05c:	4600710d */ 	trunc.w.s	$f4,$f14
/*  f18a060:	460c7032 */ 	c.eq.s	$f14,$f12
/*  f18a064:	00000000 */ 	nop
/*  f18a068:	45020012 */ 	bc1fl	.L0f18a0b4
/*  f18a06c:	4600618d */ 	trunc.w.s	$f6,$f12
/*  f18a070:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f18a074:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18a078:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*  f18a07c:	0c004b70 */ 	jal	random
/*  f18a080:	e7ae0028 */ 	swc1	$f14,0x28($sp)
/*  f18a084:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f18a088:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f18a08c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f18a090:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f18a094:	11c00006 */ 	beqz	$t6,.L0f18a0b0
/*  f18a098:	c7ae0028 */ 	lwc1	$f14,0x28($sp)
/*  f18a09c:	4600710d */ 	trunc.w.s	$f4,$f14
.L0f18a0a0:
/*  f18a0a0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18a0a4:	44032000 */ 	mfc1	$v1,$f4
/*  f18a0a8:	10000005 */ 	b	.L0f18a0c0
/*  f18a0ac:	28810003 */ 	slti	$at,$a0,0x3
.L0f18a0b0:
/*  f18a0b0:	4600618d */ 	trunc.w.s	$f6,$f12
.L0f18a0b4:
/*  f18a0b4:	44033000 */ 	mfc1	$v1,$f6
/*  f18a0b8:	00000000 */ 	nop
/*  f18a0bc:	28810003 */ 	slti	$at,$a0,0x3
.L0f18a0c0:
/*  f18a0c0:	5420002f */ 	bnezl	$at,.L0f18a180
/*  f18a0c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18a0c8:	44834000 */ 	mtc1	$v1,$f8
/*  f18a0cc:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f18a0d0:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f18a0d4:	4600503c */ 	c.lt.s	$f10,$f0
/*  f18a0d8:	00000000 */ 	nop
/*  f18a0dc:	4503000f */ 	bc1tl	.L0f18a11c
/*  f18a0e0:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f18a0e4:	46005032 */ 	c.eq.s	$f10,$f0
/*  f18a0e8:	00000000 */ 	nop
/*  f18a0ec:	45020010 */ 	bc1fl	.L0f18a130
/*  f18a0f0:	28810004 */ 	slti	$at,$a0,0x4
/*  f18a0f4:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f18a0f8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f18a0fc:	0c004b70 */ 	jal	random
/*  f18a100:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f18a104:	30590001 */ 	andi	$t9,$v0,0x1
/*  f18a108:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f18a10c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f18a110:	13200006 */ 	beqz	$t9,.L0f18a12c
/*  f18a114:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f18a118:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
.L0f18a11c:
/*  f18a11c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f18a120:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f18a124:	44039000 */ 	mfc1	$v1,$f18
/*  f18a128:	00000000 */ 	nop
.L0f18a12c:
/*  f18a12c:	28810004 */ 	slti	$at,$a0,0x4
.L0f18a130:
/*  f18a130:	54200013 */ 	bnezl	$at,.L0f18a180
/*  f18a134:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18a138:	44832000 */ 	mtc1	$v1,$f4
/*  f18a13c:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f18a140:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f18a144:	4600103c */ 	c.lt.s	$f2,$f0
/*  f18a148:	00000000 */ 	nop
/*  f18a14c:	4503000b */ 	bc1tl	.L0f18a17c
/*  f18a150:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18a154:	46001032 */ 	c.eq.s	$f2,$f0
/*  f18a158:	00000000 */ 	nop
/*  f18a15c:	45020008 */ 	bc1fl	.L0f18a180
/*  f18a160:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18a164:	0c004b70 */ 	jal	random
/*  f18a168:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f18a16c:	30490001 */ 	andi	$t1,$v0,0x1
/*  f18a170:	11200002 */ 	beqz	$t1,.L0f18a17c
/*  f18a174:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f18a178:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f18a17c:
/*  f18a17c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f18a180:
/*  f18a180:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f18a184:	00a01025 */ 	or	$v0,$a1,$zero
/*  f18a188:	03e00008 */ 	jr	$ra
/*  f18a18c:	00000000 */ 	nop
);

struct mpweaponset g_MpWeaponSets[12] = {
	{ /*0x00*/ L_MPWEAPONS(55), { WEAPON_FALCON2,          WEAPON_MAGSEC4,     WEAPON_PHOENIX,     WEAPON_MAULER,         WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_PHOENIX,         MPFEATURE_WEAPON_MAULER,     0,                              0                       }, 0x02, 0x05, 0x02, 0x08, 0x5b, 0x5c }, // Pistols
	{ /*0x01*/ L_MPWEAPONS(54), { WEAPON_FALCON2,          WEAPON_CMP150,      WEAPON_LAPTOPGUN,   WEAPON_AR34,           WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_LAPTOPGUN,       0,                           0,                              0                       }, 0x02, 0x0a, 0x0f, 0x11, 0x5b, 0x5c }, // Automatics
	{ /*0x02*/ L_MPWEAPONS(53), { WEAPON_MAGSEC4,          WEAPON_DY357MAGNUM, WEAPON_SHOTGUN,     WEAPON_RCP120,         WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_SHOTGUN,         MPFEATURE_WEAPON_RCP120,     0,                              0                       }, 0x05, 0x08, 0x0f, 0x11, 0x5b, 0x5c }, // Power
	{ /*0x03*/ L_MPWEAPONS(52), { WEAPON_PHOENIX,          WEAPON_CYCLONE,     WEAPON_CALLISTONTG, WEAPON_FARSIGHTXR20,   WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_FARSIGHT,        MPFEATURE_WEAPON_CALLISTO,   0,                              0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // FarSight
	{ /*0x04*/ L_MPWEAPONS(51), { WEAPON_FALCON2,          WEAPON_CMP150,      WEAPON_DRAGON,      WEAPON_TRANQUILIZER,   WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_TRANQUILIZER,    0,                           0,                              0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Tranquilizer
	{ /*0x05*/ L_MPWEAPONS(50), { WEAPON_MAULER,           WEAPON_K7AVENGER,   WEAPON_REAPER,      WEAPON_SUPERDRAGON,    WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_SUPERDRAGON,     MPFEATURE_WEAPON_MAULER,     MPFEATURE_WEAPON_K7AVENGER,     MPFEATURE_WEAPON_REAPER }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Heavy
	{ /*0x06*/ L_MPWEAPONS(49), { WEAPON_FALCON2_SILENCER, WEAPON_GRENADE,     WEAPON_CMP150,      WEAPON_DY357LX,        WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_FALCON2SILENCED, MPFEATURE_WEAPON_DY357LX,    0,                              0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Golden Magnum
	{ /*0x07*/ L_MPWEAPONS(48), { WEAPON_DEVASTATOR,       WEAPON_DEVASTATOR,  WEAPON_SUPERDRAGON, WEAPON_SUPERDRAGON,    WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_SUPERDRAGON,     MPFEATURE_WEAPON_DEVASTATOR, 0,                              0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Explosive
	{ /*0x08*/ L_MPWEAPONS(47), { WEAPON_MAGSEC4,          WEAPON_CMP150,      WEAPON_AR34,        WEAPON_DEVASTATOR,     WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_DEVASTATOR,      0,                           0,                              0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Grenade Launcher
	{ /*0x09*/ L_MPWEAPONS(46), { WEAPON_MAULER,           WEAPON_CYCLONE,     WEAPON_DRAGON,      WEAPON_ROCKETLAUNCHER, WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_MAULER,          0,                           0,                              0                       }, 0x02, 0x0b, 0x0f, 0x18, 0x5b, 0x5c }, // Rocket Launcher
	{ /*0x0a*/ L_MPWEAPONS(45), { WEAPON_MAGSEC4,          WEAPON_LAPTOPGUN,   WEAPON_K7AVENGER,   WEAPON_PROXIMITYMINE,  WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_LAPTOPGUN,       MPFEATURE_WEAPON_K7AVENGER,  MPFEATURE_WEAPON_PROXIMITYMINE, 0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Proximity Mine
	{ /*0x0b*/ L_MPWEAPONS(44), { WEAPON_COMBATKNIFE,      WEAPON_COMBATKNIFE, WEAPON_TIMEDMINE,   WEAPON_CROSSBOW,       WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_CROSSBOW,        0,                           0,                              0                       }, 0x1a, 0x1a, 0x20, 0x20, 0x5b, 0x5c }, // Close Combat
};

u32 var800874c8 = 0x00000000;
u32 var800874cc = 0x50005001;
u32 var800874d0 = 0x50025003;
u32 var800874d4 = 0x50045005;
u32 var800874d8 = 0x50065007;
u32 var800874dc = 0x50085009;
u32 var800874e0 = 0x500a500b;
u32 var800874e4 = 0x500c500d;
u32 var800874e8 = 0x500e500f;
u32 var800874ec = 0x50100000;

void mpCalculatePlayerTitle(struct mpplayer *mpplayer)
{
	const u32 tiers[] = { 2, 4, 8, 16, 28, 60, 100, 150, 210, 300 };
	s32 tallies[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	s32 sum;
	s32 i;

	for (i = 0; i < 10; i++) {
		if (mpplayer->kills >= tiers[i] * 60) {
			tallies[0]++;
		} else {
			break;
		}
	}

	for (i = 0; i < 10; i++) {
		if (mpplayer->gameswon >= tiers[i] * 3) {
			tallies[1]++;
		} else {
			break;
		}
	}

	for (i = 0; i < 10; i++) {
		if (mpplayer->accuracymedals >= tiers[i] * 3) {
			tallies[2]++;
		} else {
			break;
		}
	}

	for (i = 0; i < 10; i++) {
		if (mpplayer->headshotmedals >= tiers[i] * 3) {
			tallies[3]++;
		} else {
			break;
		}
	}

	for (i = 0; i < 10; i++) {
		if (mpplayer->killmastermedals >= tiers[i] * 3) {
			tallies[4]++;
		} else {
			break;
		}
	}

	for (i = 0; i < 10; i++) {
		if (mpplayer->time >= tiers[i] * 3600) {
			tallies[5]++;
		} else {
			break;
		}
	}

	for (i = 0; i < 10; i++) {
		if (mpplayer->distance >= tiers[i] * 300) {
			tallies[6]++;
		} else {
			break;
		}
	}

	for (i = 0; i < 10; i++) {
		if (mpplayer->damagedealt >= tiers[i] * 3) {
			tallies[7]++;
		} else {
			break;
		}
	}

	for (i = 0; i < 10; i++) {
		if (mpplayer->ammoused >= tiers[i] * 1500) {
			tallies[8]++;
		} else {
			break;
		}
	}

	for (i = 0; i < 10; i++) {
		if (mpplayer->survivormedals >= tiers[i] * 3) {
			tallies[9]++;
		} else {
			break;
		}
	}

	sum = 0;

	for (i = 0; i < 10; i++) {
		sum = sum + tallies[i];
	}

	if (sum > 100) {
		sum = 100;
	}

	mpplayer->title = sum / 5;

	if (mpplayer->title > MPPLAYERTITLE_PERFECT) {
		mpplayer->title = MPPLAYERTITLE_PERFECT;
	}
}

const char var7f1b8ad0[] = "%s%sAccuracy Peak! real value: %f (*100)\n";
const char var7f1b8afc[] = "";
const char var7f1b8b00[] = "";
const char var7f1b8b04[] = "%splayer %d Accuracy :%f\n";
const char var7f1b8b20[] = "";
const char var7f1b8b24[] = "%splayer %d dist:%f -> %f = %d\n";
const char var7f1b8b44[] = "";
const char var7f1b8b48[] = "Player %d TitleCalc ============\n";
const char var7f1b8b6c[] = "Sim\n";
const char var7f1b8b74[] = "%s:%d\n";
const char var7f1b8b7c[] = "%s\n";
const char var7f1b8b80[] = "Adding GBCHead to load to slot %d: guid is %x-%x, player is %d\n";
const char var7f1b8bc0[] = "PakId for player %d: %d\n";
const char var7f1b8bdc[] = "Save Player Result: %d   New GUID: %x\n";
const char var7f1b8c04[] = "PakId for player %d: %d\n";
const char var7f1b8c20[] = "Load Player - Result: %d\n";

struct mphead g_MpBeauHeads[NUM_MPBEAUHEADS] = {
	// head, require feature
	{ HEAD_BEAU2, 0 },
	{ HEAD_BEAU3, 0 },
	{ HEAD_BEAU4, 0 },
	{ HEAD_BEAU5, 0 },
	{ HEAD_BEAU6, 0 },
};

struct mphead g_MpHeads[75] = {
	// head, require feature
	{ /*0x00*/ HEAD_DARK_COMBAT,  0            },
	{ /*0x01*/ HEAD_DARK_FROCK,   MPFEATURE_41 },
	{ /*0x02*/ HEAD_DARKAQUA,     MPFEATURE_45 },
	{ /*0x03*/ HEAD_DARK_SNOW,    MPFEATURE_4A },
	{ /*0x04*/ HEAD_ELVIS,        MPFEATURE_3D },
	{ /*0x05*/ HEAD_ELVIS_GOGS,   MPFEATURE_3D },
	{ /*0x06*/ HEAD_CARRINGTON,   0            },
	{ /*0x07*/ HEAD_MRBLONDE,     MPFEATURE_38 },
	{ /*0x08*/ HEAD_CASSANDRA,    0            },
	{ /*0x09*/ HEAD_TRENT,        MPFEATURE_35 },
	{ /*0x0a*/ HEAD_JONATHAN,     MPFEATURE_3A },
	{ /*0x0b*/ HEAD_VD,           0            },
	{ /*0x0c*/ HEAD_PRESIDENT,    MPFEATURE_41 },
	{ /*0x0d*/ HEAD_DDSHOCK,      0            },
	{ /*0x0e*/ HEAD_BIOTECH,      MPFEATURE_3C },
	{ /*0x0f*/ HEAD_DDSNIPER,     MPFEATURE_34 },
	{ /*0x10*/ HEAD_A51FACEPLATE, MPFEATURE_3A },
	{ /*0x11*/ HEAD_SECRETARY,    0            },
	{ /*0x12*/ HEAD_FEM_GUARD,    MPFEATURE_32 },
	{ /*0x13*/ HEAD_FEM_GUARD2,   MPFEATURE_32 },
	{ /*0x14*/ HEAD_MAIAN_S,      MPFEATURE_3D },
	{ /*0x15*/ HEAD_JON,          0            },
	{ /*0x16*/ HEAD_BEAU1,        0            },
	{ /*0x17*/ HEAD_ROSS,         0            },
	{ /*0x18*/ HEAD_MARK2,        0            },
	{ /*0x19*/ HEAD_CHRIST,       0            },
	{ /*0x1a*/ HEAD_RUSS,         0            },
	{ /*0x1b*/ HEAD_DARLING,      0            },
	{ /*0x1c*/ HEAD_BRIAN,        0            },
	{ /*0x1d*/ HEAD_JAMIE,        0            },
	{ /*0x1e*/ HEAD_DUNCAN2,      0            },
	{ /*0x1f*/ HEAD_KEITH,        0            },
	{ /*0x20*/ HEAD_STEVEM,       0            },
	{ /*0x21*/ HEAD_GRANT,        0            },
	{ /*0x22*/ HEAD_PENNY,        0            },
	{ /*0x23*/ HEAD_DAVEC,        0            },
	{ /*0x24*/ HEAD_JONES,        0            },
	{ /*0x25*/ HEAD_GRAHAM,       0            },
	{ /*0x26*/ HEAD_ROBERT,       0            },
	{ /*0x27*/ HEAD_NEIL2,        0            },
	{ /*0x28*/ HEAD_SHAUN,        0            },
	{ /*0x29*/ HEAD_ROBIN,        0            },
	{ /*0x2a*/ HEAD_COOK,         0            },
	{ /*0x2b*/ HEAD_PRYCE,        0            },
	{ /*0x2c*/ HEAD_SILKE,        0            },
	{ /*0x2d*/ HEAD_SMITH,        0            },
	{ /*0x2e*/ HEAD_GARETH,       0            },
	{ /*0x2f*/ HEAD_MURCHIE,      0            },
	{ /*0x30*/ HEAD_WONG,         0            },
	{ /*0x31*/ HEAD_CARTER,       0            },
	{ /*0x32*/ HEAD_TINTIN,       0            },
	{ /*0x33*/ HEAD_MUNTON,       0            },
	{ /*0x34*/ HEAD_STAMPER,      0            },
	{ /*0x35*/ HEAD_PHELPS,       0            },
	{ /*0x36*/ HEAD_ALEX,         0            },
	{ /*0x37*/ HEAD_JULIANNE,     0            },
	{ /*0x38*/ HEAD_LAURA,        0            },
	{ /*0x39*/ HEAD_EDMCG,        0            },
	{ /*0x3a*/ HEAD_ANKA,         0            },
	{ /*0x3b*/ HEAD_LESLIE_S,     0            },
	{ /*0x3c*/ HEAD_MATT_C,       0            },
	{ /*0x3d*/ HEAD_PEER_S,       0            },
	{ /*0x3e*/ HEAD_EILEEN_T,     0            },
	{ /*0x3f*/ HEAD_ANDY_R,       0            },
	{ /*0x40*/ HEAD_BEN_R,        0            },
	{ /*0x41*/ HEAD_STEVE_K,      0            },
	{ /*0x42*/ HEAD_SANCHEZ,      0            },
	{ /*0x43*/ HEAD_TIM,          0            },
	{ /*0x44*/ HEAD_KEN,          0            },
	{ /*0x45*/ HEAD_EILEEN_H,     0            },
	{ /*0x46*/ HEAD_SCOTT_H,      0            },
	{ /*0x47*/ HEAD_JOEL,         0            },
	{ /*0x48*/ HEAD_GRIFFEY,      0            },
	{ /*0x49*/ HEAD_MOTO,         0            },
	{ /*0x4a*/ HEAD_WINNER,       0            },
};

// 2d678
u32 table_0x2d678[] = {
	21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
	31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
	51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
	61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
	71, 72, 73,
};

// 2d74c
struct mpsimulanttype g_MpSimulantTypes[] = {
	// type,           difficulty,      name,        body,                 require feature
	{ SIMTYPE_GENERAL, SIMDIFF_MEAT,    L_MISC(88),  MPBODY_DD_GUARD,      0                         },
	{ SIMTYPE_GENERAL, SIMDIFF_EASY,    L_MISC(89),  MPBODY_DD_SECGUARD,   0                         },
	{ SIMTYPE_GENERAL, SIMDIFF_NORMAL,  L_MISC(90),  MPBODY_DD_SHOCK_INF,  0                         },
	{ SIMTYPE_GENERAL, SIMDIFF_HARD,    L_MISC(91),  MPBODY_DDSHOCK,       MPFEATURE_SIMDIFF_HARD    },
	{ SIMTYPE_GENERAL, SIMDIFF_PERFECT, L_MISC(92),  MPBODY_STRIPES,       MPFEATURE_SIMDIFF_PERFECT },
	{ SIMTYPE_GENERAL, SIMDIFF_DARK,    L_MISC(93),  MPBODY_MOORE,         MPFEATURE_SIMDIFF_DARK    },
	{ SIMTYPE_PEACE,   SIMDIFF_NORMAL,  L_MISC(94),  MPBODY_DD_LABTECH,    0                         },
	{ SIMTYPE_SHIELD,  SIMDIFF_NORMAL,  L_MISC(95),  MPBODY_G5_SWAT_GUARD, 0                         },
	{ SIMTYPE_ROCKET,  SIMDIFF_NORMAL,  L_MISC(96),  MPBODY_G5_GUARD,      0                         },
	{ SIMTYPE_KAZE,    SIMDIFF_NORMAL,  L_MISC(97),  MPBODY_PRES_SECURITY, 0                         },
	{ SIMTYPE_FIST,    SIMDIFF_NORMAL,  L_MISC(98),  MPBODY_PELAGIC_GUARD, 0                         },
	{ SIMTYPE_PREY,    SIMDIFF_NORMAL,  L_MISC(99),  MPBODY_DDSHOCK,       0                         },
	{ SIMTYPE_COWARD,  SIMDIFF_NORMAL,  L_MISC(100), MPBODY_PRESIDENT,     0                         },
	{ SIMTYPE_JUDGE,   SIMDIFF_NORMAL,  L_MISC(101), MPBODY_STEWARD,       0                         },
	{ SIMTYPE_FEUD,    SIMDIFF_NORMAL,  L_MISC(102), MPBODY_NSA_LACKEY,    0                         },
	{ SIMTYPE_SPEED,   SIMDIFF_NORMAL,  L_MISC(103), MPBODY_MRBLONDE,      0                         },
	{ SIMTYPE_TURTLE,  SIMDIFF_NORMAL,  L_MISC(104), MPBODY_CARRINGTON,    0                         },
	{ SIMTYPE_VENGE,   SIMDIFF_NORMAL,  L_MISC(105), MPBODY_ALASKAN_GUARD, 0                         },
};

// 2d7dc
struct mpbody g_MpBodies[NUM_MPBODIES] = {
	// global body ID,                name,             head,             require feature
	/*0x00*/ { BODY_DARK_COMBAT,      L_OPTIONS(16),    HEAD_DARK_COMBAT, 0               },
	/*0x01*/ { BODY_DARK_TRENCH,      L_OPTIONS(17),    HEAD_DARK_COMBAT, MPFEATURE_46    },
	/*0x02*/ { BODY_DARK_FROCK,       L_OPTIONS(18),    HEAD_DARK_FROCK,  MPFEATURE_41    },
	/*0x03*/ { BODY_DARK_RIPPED,      L_OPTIONS(19),    HEAD_DARK_FROCK,  MPFEATURE_41    },
	/*0x04*/ { BODY_DARK_AF1,         L_OPTIONS(20),    HEAD_DARK_COMBAT, MPFEATURE_3F    },
	/*0x05*/ { BODY_DARK_LEATHER,     L_MPWEAPONS(156), HEAD_DARK_COMBAT, MPFEATURE_37    },
	/*0x06*/ { BODY_DARK_NEGOTIATOR,  L_MPWEAPONS(157), HEAD_DARK_COMBAT, MPFEATURE_34    },
	/*0x07*/ { BODY_DARKWET,          L_OPTIONS(21),    HEAD_DARKAQUA,    MPFEATURE_45    },
	/*0x08*/ { BODY_DARKAQUALUNG,     L_OPTIONS(22),    HEAD_DARKAQUA,    MPFEATURE_45    },
	/*0x09*/ { BODY_DARKSNOW,         L_OPTIONS(23),    HEAD_DARK_SNOW,   MPFEATURE_4A    },
	/*0x0a*/ { BODY_DARKLAB,          L_OPTIONS(24),    HEAD_DARK_COMBAT, MPFEATURE_3A    },
	/*0x0b*/ { BODY_THEKING,          L_OPTIONS(25),    HEAD_ELVIS,       MPFEATURE_3D    },
	/*0x0c*/ { BODY_ELVIS1,           L_OPTIONS(26),    HEAD_ELVIS,       MPFEATURE_3D    },
	/*0x0d*/ { BODY_ELVISWAISTCOAT,   L_MPWEAPONS(158), HEAD_ELVIS,       MPFEATURE_3D    },
	/*0x0e*/ { BODY_CARRINGTON,       L_OPTIONS(27),    HEAD_CARRINGTON,  0               },
	/*0x0f*/ { BODY_CARREVENINGSUIT,  L_OPTIONS(28),    HEAD_CARRINGTON,  MPFEATURE_41    },
	/*0x10*/ { BODY_MRBLONDE,         L_OPTIONS(29),    HEAD_MRBLONDE,    MPFEATURE_38    },
	/*0x11*/ { BODY_CASSANDRA,        L_OPTIONS(30),    HEAD_CASSANDRA,   0               },
	/*0x12*/ { BODY_TRENT,            L_OPTIONS(31),    HEAD_TRENT,       MPFEATURE_35    },
	/*0x13*/ { BODY_JONATHAN,         L_OPTIONS(32),    HEAD_JONATHAN,    MPFEATURE_4C    },
	/*0x14*/ { BODY_CILABTECH,        L_OPTIONS(33),    1000,             0               },
	/*0x15*/ { BODY_CIFEMTECH,        L_OPTIONS(34),    1000,             0               },
	/*0x16*/ { BODY_CISOLDIER,        L_OPTIONS(35),    1000,             0               },
	/*0x17*/ { BODY_DDSHOCK,          L_OPTIONS(36),    HEAD_DDSHOCK,     0               },
	/*0x18*/ { BODY_FEM_GUARD,        L_OPTIONS(37),    1000,             MPFEATURE_32    },
	/*0x19*/ { BODY_DD_SECGUARD,      L_OPTIONS(38),    1000,             0               },
	/*0x1a*/ { BODY_DD_GUARD,         L_OPTIONS(39),    1000,             0               },
	/*0x1b*/ { BODY_DD_SHOCK_INF,     L_OPTIONS(40),    1000,             0               },
	/*0x1c*/ { BODY_SECRETARY,        L_OPTIONS(41),    1000,             0               },
	/*0x1d*/ { BODY_OFFICEWORKER,     L_OPTIONS(42),    1000,             MPFEATURE_33    },
	/*0x1e*/ { BODY_OFFICEWORKER2,    L_OPTIONS(43),    1000,             MPFEATURE_33    },
	/*0x1f*/ { BODY_NEGOTIATOR,       L_OPTIONS(44),    1000,             MPFEATURE_34    },
	/*0x20*/ { BODY_DDSNIPER,         L_OPTIONS(45),    HEAD_DDSNIPER,    MPFEATURE_34    },
	/*0x21*/ { BODY_G5_GUARD,         L_OPTIONS(46),    1000,             MPFEATURE_37    },
	/*0x22*/ { BODY_G5_SWAT_GUARD,    L_OPTIONS(47),    1000,             MPFEATURE_37    },
	/*0x23*/ { BODY_CIAGUY,           L_OPTIONS(48),    1000,             MPFEATURE_39    },
	/*0x24*/ { BODY_FBIGUY,           L_OPTIONS(49),    1000,             MPFEATURE_39    },
	/*0x25*/ { BODY_AREA51GUARD,      L_OPTIONS(50),    1000,             MPFEATURE_3A    },
	/*0x26*/ { BODY_A51TROOPER,       L_OPTIONS(51),    1000,             MPFEATURE_3A    },
	/*0x27*/ { BODY_A51AIRMAN,        L_OPTIONS(52),    1000,             MPFEATURE_3A    },
	/*0x28*/ { BODY_OVERALL,          L_OPTIONS(53),    1000,             MPFEATURE_3A    },
	/*0x29*/ { BODY_STRIPES,          L_OPTIONS(54),    1000,             MPFEATURE_44    },
	/*0x2a*/ { BODY_LABTECH,          L_OPTIONS(55),    1000,             MPFEATURE_3B    },
	/*0x2b*/ { BODY_FEMLABTECH,       L_OPTIONS(56),    1000,             MPFEATURE_3B    },
	/*0x2c*/ { BODY_DD_LABTECH,       L_OPTIONS(57),    1000,             MPFEATURE_3B    },
	/*0x2d*/ { BODY_BIOTECH,          L_OPTIONS(58),    HEAD_BIOTECH,     MPFEATURE_3C    },
	/*0x2e*/ { BODY_ALASKAN_GUARD,    L_OPTIONS(59),    1000,             MPFEATURE_3E    },
	/*0x2f*/ { BODY_PILOTAF1,         L_OPTIONS(60),    1000,             MPFEATURE_3F    },
	/*0x30*/ { BODY_STEWARD,          L_OPTIONS(61),    1000,             MPFEATURE_3F    },
	/*0x31*/ { BODY_STEWARDESS,       L_OPTIONS(62),    1000,             MPFEATURE_3F    },
	/*0x32*/ { BODY_STEWARDESS_COAT,  L_OPTIONS(63),    1000,             MPFEATURE_3F    },
	/*0x33*/ { BODY_PRESIDENT,        L_OPTIONS(64),    HEAD_PRESIDENT,   MPFEATURE_41    },
	/*0x34*/ { BODY_NSA_LACKEY,       L_OPTIONS(65),    1000,             MPFEATURE_36    },
	/*0x35*/ { BODY_PRES_SECURITY,    L_OPTIONS(66),    1000,             MPFEATURE_43    },
	/*0x36*/ { BODY_PRESIDENT_CLONE2, L_OPTIONS(67),    HEAD_PRESIDENT,   MPFEATURE_42    },
	/*0x37*/ { BODY_PELAGIC_GUARD,    L_OPTIONS(68),    1000,             MPFEATURE_45    },
	/*0x38*/ { BODY_MAIAN_SOLDIER,    L_OPTIONS(69),    HEAD_MAIAN_S,     MPFEATURE_3D    },
	/*0x39*/ { BODY_CONNERY,          L_OPTIONS(70),    1000,             MPFEATURE_8BOTS },
	/*0x3a*/ { BODY_MOORE,            L_OPTIONS(70),    1000,             MPFEATURE_8BOTS },
	/*0x3b*/ { BODY_DALTON,           L_OPTIONS(70),    1000,             MPFEATURE_8BOTS },
	/*0x3c*/ { BODY_DJBOND,           L_OPTIONS(70),    1000,             MPFEATURE_8BOTS },
};

u32 g_MpMaleHeads[] = {
	HEAD_JON,
	HEAD_BEAU1,
	HEAD_ROSS,
	HEAD_MARK2,
	HEAD_CHRIST,
	HEAD_RUSS,
	HEAD_DARLING,
	HEAD_BRIAN,
	HEAD_JAMIE,
	HEAD_DUNCAN2,
	HEAD_KEITH,
	HEAD_STEVEM,
	HEAD_GRANT,
	HEAD_PENNY,
	HEAD_DAVEC,
	HEAD_JONES,
	HEAD_GRAHAM,
	HEAD_NEIL2,
	HEAD_SHAUN,
	HEAD_ROBIN,
	HEAD_COOK,
	HEAD_PRYCE,
	HEAD_SILKE,
	HEAD_SMITH,
	HEAD_GARETH,
	HEAD_MURCHIE,
	HEAD_WONG,
	HEAD_CARTER,
	HEAD_TINTIN,
	HEAD_MUNTON,
	HEAD_STAMPER,
	HEAD_PHELPS,
	HEAD_EDMCG,
	HEAD_MATT_C,
	HEAD_PEER_S,
	HEAD_ANDY_R,
	HEAD_BEN_R,
	HEAD_STEVE_K,
	HEAD_SANCHEZ,
	HEAD_TIM,
	HEAD_KEN,
	HEAD_SCOTT_H,
	HEAD_JOEL,
	HEAD_MOTO,
};

u32 g_MpFemaleHeads[] = {
	HEAD_ALEX,
	HEAD_JULIANNE,
	HEAD_LAURA,
	HEAD_ANKA,
	HEAD_LESLIE_S,
	HEAD_EILEEN_T,
	HEAD_EILEEN_H,
};

GLOBAL_ASM(
glabel func0f18a56c
.late_rodata
glabel var7f1b8d98
.word 0x4852f000
glabel var7f1b8d9c
.word 0x47c35000
glabel var7f1b8da0
.word 0x461c4000
glabel var7f1b8da4
.word 0x3e99999a
glabel var7f1b8da8
.word 0x3f333333
glabel var7f1b8dac
.word 0x3dcccccd
glabel var7f1b8db0
.word 0x3dcccccd
.text
/*  f18a56c:	27bdfd00 */ 	addiu	$sp,$sp,-768
/*  f18a570:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f18a574:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f18a578:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f18a57c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f18a580:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f18a584:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f18a588:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f18a58c:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f18a590:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f18a594:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f18a598:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f18a59c:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f18a5a0:	11c00004 */ 	beqz	$t6,.L0f18a5b4
/*  f18a5a4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f18a5a8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18a5ac:	10000002 */ 	b	.L0f18a5b8
/*  f18a5b0:	afaf0064 */ 	sw	$t7,0x64($sp)
.L0f18a5b4:
/*  f18a5b4:	afa00064 */ 	sw	$zero,0x64($sp)
.L0f18a5b8:
/*  f18a5b8:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f18a5bc:	13000003 */ 	beqz	$t8,.L0f18a5cc
/*  f18a5c0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18a5c4:	10000002 */ 	b	.L0f18a5d0
/*  f18a5c8:	afb90068 */ 	sw	$t9,0x68($sp)
.L0f18a5cc:
/*  f18a5cc:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f18a5d0:
/*  f18a5d0:	8c4d0064 */ 	lw	$t5,0x64($v0)
/*  f18a5d4:	11a00003 */ 	beqz	$t5,.L0f18a5e4
/*  f18a5d8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18a5dc:	10000002 */ 	b	.L0f18a5e8
/*  f18a5e0:	afae006c */ 	sw	$t6,0x6c($sp)
.L0f18a5e4:
/*  f18a5e4:	afa0006c */ 	sw	$zero,0x6c($sp)
.L0f18a5e8:
/*  f18a5e8:	8c4f0070 */ 	lw	$t7,0x70($v0)
/*  f18a5ec:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f18a5f0:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f18a5f4:	51e00004 */ 	beqzl	$t7,.L0f18a608
/*  f18a5f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f18a5fc:	10000002 */ 	b	.L0f18a608
/*  f18a600:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f18a604:	00008825 */ 	or	$s1,$zero,$zero
.L0f18a608:
/*  f18a608:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f18a60c:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f18a610:	032d7021 */ 	addu	$t6,$t9,$t5
/*  f18a614:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f18a618:	0fc3089f */ 	jal	getMissionTime
/*  f18a61c:	afb002fc */ 	sw	$s0,0x2fc($sp)
/*  f18a620:	0c00cf76 */ 	jal	func00033dd8
/*  f18a624:	afa202ec */ 	sw	$v0,0x2ec($sp)
/*  f18a628:	0fc62179 */ 	jal	mpGetPlayerRankings
/*  f18a62c:	27a401e8 */ 	addiu	$a0,$sp,0x1e8
/*  f18a630:	3c15800b */ 	lui	$s5,%hi(g_MpSetup)
/*  f18a634:	26b5cb88 */ 	addiu	$s5,$s5,%lo(g_MpSetup)
/*  f18a638:	8eb8000c */ 	lw	$t8,0xc($s5)
/*  f18a63c:	afa201e4 */ 	sw	$v0,0x1e4($sp)
/*  f18a640:	33190002 */ 	andi	$t9,$t8,0x2
/*  f18a644:	53200006 */ 	beqzl	$t9,.L0f18a660
/*  f18a648:	afa001e0 */ 	sw	$zero,0x1e0($sp)
/*  f18a64c:	0fc622a1 */ 	jal	mpGetTeamRankings
/*  f18a650:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f18a654:	10000002 */ 	b	.L0f18a660
/*  f18a658:	afa201e0 */ 	sw	$v0,0x1e0($sp)
/*  f18a65c:	afa001e0 */ 	sw	$zero,0x1e0($sp)
.L0f18a660:
/*  f18a660:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x28c)
/*  f18a664:	8dada24c */ 	lw	$t5,%lo(g_Vars+0x28c)($t5)
/*  f18a668:	0000b025 */ 	or	$s6,$zero,$zero
/*  f18a66c:	1a000224 */ 	blez	$s0,.L0f18af00
/*  f18a670:	afad02f0 */ 	sw	$t5,0x2f0($sp)
/*  f18a674:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f18a678:	3c017f1c */ 	lui	$at,%hi(var7f1b8d98)
/*  f18a67c:	c4288d98 */ 	lwc1	$f8,%lo(var7f1b8d98)($at)
/*  f18a680:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f18a684:	448f2000 */ 	mtc1	$t7,$f4
/*  f18a688:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f18a68c:	3c1e800b */ 	lui	$s8,%hi(g_MpPlayers)
/*  f18a690:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f18a694:	27dec7b8 */ 	addiu	$s8,$s8,%lo(g_MpPlayers)
/*  f18a698:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f18a69c:	27b301fc */ 	addiu	$s3,$sp,0x1fc
/*  f18a6a0:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f18a6a4:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f18a6a8:	e7aa0048 */ 	swc1	$f10,0x48($sp)
.L0f18a6ac:
/*  f18a6ac:	0fc631e5 */ 	jal	func0f18c794
/*  f18a6b0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18a6b4:	00409025 */ 	or	$s2,$v0,$zero
/*  f18a6b8:	00408025 */ 	or	$s0,$v0,$zero
/*  f18a6bc:	0fc6320a */ 	jal	func0f18c828
/*  f18a6c0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18a6c4:	00408825 */ 	or	$s1,$v0,$zero
/*  f18a6c8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f18a6cc:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18a6d0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f18a6d4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f18a6d8:	8c580284 */ 	lw	$t8,0x284($v0)
/*  f18a6dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f18a6e0:	af001974 */ 	sw	$zero,0x1974($t8)
/*  f18a6e4:	8c590284 */ 	lw	$t9,0x284($v0)
/*  f18a6e8:	0fc2c14b */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f18a6ec:	af201978 */ 	sw	$zero,0x1978($t9)
/*  f18a6f0:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f18a6f4:	0fc2c14b */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f18a6f8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f18a6fc:	ae620004 */ 	sw	$v0,0x4($s3)
/*  f18a700:	ae600008 */ 	sw	$zero,0x8($s3)
/*  f18a704:	ae60000c */ 	sw	$zero,0xc($s3)
/*  f18a708:	ae600010 */ 	sw	$zero,0x10($s3)
/*  f18a70c:	00113040 */ 	sll	$a2,$s1,0x1
/*  f18a710:	00002025 */ 	or	$a0,$zero,$zero
/*  f18a714:	02402825 */ 	or	$a1,$s2,$zero
.L0f18a718:
/*  f18a718:	54c40007 */ 	bnel	$a2,$a0,.L0f18a738
/*  f18a71c:	8e780008 */ 	lw	$t8,0x8($s3)
/*  f18a720:	8e6d0010 */ 	lw	$t5,0x10($s3)
/*  f18a724:	84ae0024 */ 	lh	$t6,0x24($a1)
/*  f18a728:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f18a72c:	10000005 */ 	b	.L0f18a744
/*  f18a730:	ae6f0010 */ 	sw	$t7,0x10($s3)
/*  f18a734:	8e780008 */ 	lw	$t8,0x8($s3)
.L0f18a738:
/*  f18a738:	84b90024 */ 	lh	$t9,0x24($a1)
/*  f18a73c:	03196821 */ 	addu	$t5,$t8,$t9
/*  f18a740:	ae6d0008 */ 	sw	$t5,0x8($s3)
.L0f18a744:
/*  f18a744:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f18a748:	28810018 */ 	slti	$at,$a0,0x18
/*  f18a74c:	1420fff2 */ 	bnez	$at,.L0f18a718
/*  f18a750:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f18a754:	00001825 */ 	or	$v1,$zero,$zero
/*  f18a758:	00112040 */ 	sll	$a0,$s1,0x1
/*  f18a75c:	240500a0 */ 	addiu	$a1,$zero,0xa0
.L0f18a760:
/*  f18a760:	28610004 */ 	slti	$at,$v1,0x4
/*  f18a764:	10200006 */ 	beqz	$at,.L0f18a780
/*  f18a768:	00037880 */ 	sll	$t7,$v1,0x2
/*  f18a76c:	00650019 */ 	multu	$v1,$a1
/*  f18a770:	00007012 */ 	mflo	$t6
/*  f18a774:	03ce1021 */ 	addu	$v0,$s8,$t6
/*  f18a778:	1000000a */ 	b	.L0f18a7a4
/*  f18a77c:	00447021 */ 	addu	$t6,$v0,$a0
.L0f18a780:
/*  f18a780:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f18a784:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18a788:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f18a78c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18a790:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f18a794:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f18a798:	25f8fed0 */ 	addiu	$t8,$t7,-304
/*  f18a79c:	03191021 */ 	addu	$v0,$t8,$t9
/*  f18a7a0:	00447021 */ 	addu	$t6,$v0,$a0
.L0f18a7a4:
/*  f18a7a4:	85cf0024 */ 	lh	$t7,0x24($t6)
/*  f18a7a8:	8e6d000c */ 	lw	$t5,0xc($s3)
/*  f18a7ac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18a7b0:	2861000c */ 	slti	$at,$v1,0xc
/*  f18a7b4:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f18a7b8:	1420ffe9 */ 	bnez	$at,.L0f18a760
/*  f18a7bc:	ae78000c */ 	sw	$t8,0xc($s3)
/*  f18a7c0:	8e790008 */ 	lw	$t9,0x8($s3)
/*  f18a7c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f18a7c8:	44811000 */ 	mtc1	$at,$f2
/*  f18a7cc:	44998000 */ 	mtc1	$t9,$f16
/*  f18a7d0:	3c0142c8 */ 	lui	$at,0x42c8
/*  f18a7d4:	44812000 */ 	mtc1	$at,$f4
/*  f18a7d8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f18a7dc:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f18a7e0:	03006825 */ 	or	$t5,$t8,$zero
/*  f18a7e4:	8e8f00b0 */ 	lw	$t7,0xb0($s4)
/*  f18a7e8:	448e3000 */ 	mtc1	$t6,$f6
/*  f18a7ec:	8e9800a8 */ 	lw	$t8,0xa8($s4)
/*  f18a7f0:	46049002 */ 	mul.s	$f0,$f18,$f4
/*  f18a7f4:	448d9000 */ 	mtc1	$t5,$f18
/*  f18a7f8:	3c017f1c */ 	lui	$at,%hi(var7f1b8d9c)
/*  f18a7fc:	ae6f001c */ 	sw	$t7,0x1c($s3)
/*  f18a800:	ae780020 */ 	sw	$t8,0x20($s3)
/*  f18a804:	8e9900c0 */ 	lw	$t9,0xc0($s4)
/*  f18a808:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f18a80c:	8e8e00c4 */ 	lw	$t6,0xc4($s4)
/*  f18a810:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f18a814:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f18a818:	46024280 */ 	add.s	$f10,$f8,$f2
/*  f18a81c:	46022180 */ 	add.s	$f6,$f4,$f2
/*  f18a820:	460a0403 */ 	div.s	$f16,$f0,$f10
/*  f18a824:	c68a00ac */ 	lwc1	$f10,0xac($s4)
/*  f18a828:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f18a82c:	e6700014 */ 	swc1	$f16,0x14($s3)
/*  f18a830:	e6680018 */ 	swc1	$f8,0x18($s3)
/*  f18a834:	c4308d9c */ 	lwc1	$f16,%lo(var7f1b8d9c)($at)
/*  f18a838:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f18a83c:	c68800b4 */ 	lwc1	$f8,0xb4($s4)
/*  f18a840:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f18a844:	ae60002c */ 	sw	$zero,0x2c($s3)
/*  f18a848:	ae790030 */ 	sw	$t9,0x30($s3)
/*  f18a84c:	ae6e0034 */ 	sw	$t6,0x34($s3)
/*  f18a850:	e6680028 */ 	swc1	$f8,0x28($s3)
/*  f18a854:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f18a858:	0fc2c14b */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f18a85c:	e6660024 */ 	swc1	$f6,0x24($s3)
/*  f18a860:	00409025 */ 	or	$s2,$v0,$zero
/*  f18a864:	0fc2c14b */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f18a868:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f18a86c:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f18a870:	0fc2c14b */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f18a874:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f18a878:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f18a87c:	0fc2c14b */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f18a880:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f18a884:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f18a888:	0fc2c14b */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f18a88c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f18a890:	00408825 */ 	or	$s1,$v0,$zero
/*  f18a894:	0fc2c14b */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f18a898:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f18a89c:	8e630000 */ 	lw	$v1,0x0($s3)
/*  f18a8a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f18a8a4:	44811000 */ 	mtc1	$at,$f2
/*  f18a8a8:	18600010 */ 	blez	$v1,.L0f18a8ec
/*  f18a8ac:	00516821 */ 	addu	$t5,$v0,$s1
/*  f18a8b0:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f18a8b4:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f18a8b8:	44839000 */ 	mtc1	$v1,$f18
/*  f18a8bc:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f18a8c0:	8fad0064 */ 	lw	$t5,0x64($sp)
/*  f18a8c4:	03197021 */ 	addu	$t6,$t8,$t9
/*  f18a8c8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f18a8cc:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f18a8d0:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f18a8d4:	44985000 */ 	mtc1	$t8,$f10
/*  f18a8d8:	00000000 */ 	nop
/*  f18a8dc:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f18a8e0:	46048183 */ 	div.s	$f6,$f16,$f4
/*  f18a8e4:	10000004 */ 	b	.L0f18a8f8
/*  f18a8e8:	e6660038 */ 	swc1	$f6,0x38($s3)
.L0f18a8ec:
/*  f18a8ec:	44804000 */ 	mtc1	$zero,$f8
/*  f18a8f0:	00000000 */ 	nop
/*  f18a8f4:	e6680038 */ 	swc1	$f8,0x38($s3)
.L0f18a8f8:
/*  f18a8f8:	c66a0038 */ 	lwc1	$f10,0x38($s3)
/*  f18a8fc:	3c19800a */ 	lui	$t9,%hi(g_CheatsActiveBank0)
/*  f18a900:	3c0e800a */ 	lui	$t6,%hi(g_CheatsActiveBank1)
/*  f18a904:	460a103c */ 	c.lt.s	$f2,$f10
/*  f18a908:	00000000 */ 	nop
/*  f18a90c:	45020003 */ 	bc1fl	.L0f18a91c
/*  f18a910:	a2000094 */ 	sb	$zero,0x94($s0)
/*  f18a914:	e6620038 */ 	swc1	$f2,0x38($s3)
/*  f18a918:	a2000094 */ 	sb	$zero,0x94($s0)
.L0f18a91c:
/*  f18a91c:	8f3921d0 */ 	lw	$t9,%lo(g_CheatsActiveBank0)($t9)
/*  f18a920:	57200173 */ 	bnezl	$t9,.L0f18aef0
/*  f18a924:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f18a928:	8dce21d4 */ 	lw	$t6,%lo(g_CheatsActiveBank1)($t6)
/*  f18a92c:	55c00170 */ 	bnezl	$t6,.L0f18aef0
/*  f18a930:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f18a934:	8e0d0054 */ 	lw	$t5,0x54($s0)
/*  f18a938:	8e6f0008 */ 	lw	$t7,0x8($s3)
/*  f18a93c:	8e190058 */ 	lw	$t9,0x58($s0)
/*  f18a940:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f18a944:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f18a948:	ae180054 */ 	sw	$t8,0x54($s0)
/*  f18a94c:	8e6e000c */ 	lw	$t6,0xc($s3)
/*  f18a950:	8e0f005c */ 	lw	$t7,0x5c($s0)
/*  f18a954:	032e6821 */ 	addu	$t5,$t9,$t6
/*  f18a958:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f18a95c:	ae0d0058 */ 	sw	$t5,0x58($s0)
/*  f18a960:	ae18005c */ 	sw	$t8,0x5c($s0)
/*  f18a964:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f18a968:	8e190068 */ 	lw	$t9,0x68($s0)
/*  f18a96c:	01c1001a */ 	div	$zero,$t6,$at
/*  f18a970:	00006812 */ 	mflo	$t5
/*  f18a974:	032d7821 */ 	addu	$t7,$t9,$t5
/*  f18a978:	ae0f0068 */ 	sw	$t7,0x68($s0)
/*  f18a97c:	3c017f1c */ 	lui	$at,%hi(var7f1b8da0)
/*  f18a980:	c4308da0 */ 	lwc1	$f16,%lo(var7f1b8da0)($at)
/*  f18a984:	c69200ac */ 	lwc1	$f18,0xac($s4)
/*  f18a988:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18a98c:	3c014f00 */ 	lui	$at,0x4f00
/*  f18a990:	46109103 */ 	div.s	$f4,$f18,$f16
/*  f18a994:	4458f800 */ 	cfc1	$t8,$31
/*  f18a998:	44cef800 */ 	ctc1	$t6,$31
/*  f18a99c:	00000000 */ 	nop
/*  f18a9a0:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f18a9a4:	444ef800 */ 	cfc1	$t6,$31
/*  f18a9a8:	00000000 */ 	nop
/*  f18a9ac:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18a9b0:	51c00013 */ 	beqzl	$t6,.L0f18aa00
/*  f18a9b4:	440e3000 */ 	mfc1	$t6,$f6
/*  f18a9b8:	44813000 */ 	mtc1	$at,$f6
/*  f18a9bc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18a9c0:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f18a9c4:	44cef800 */ 	ctc1	$t6,$31
/*  f18a9c8:	00000000 */ 	nop
/*  f18a9cc:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f18a9d0:	444ef800 */ 	cfc1	$t6,$31
/*  f18a9d4:	00000000 */ 	nop
/*  f18a9d8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18a9dc:	15c00005 */ 	bnez	$t6,.L0f18a9f4
/*  f18a9e0:	00000000 */ 	nop
/*  f18a9e4:	440e3000 */ 	mfc1	$t6,$f6
/*  f18a9e8:	3c018000 */ 	lui	$at,0x8000
/*  f18a9ec:	10000007 */ 	b	.L0f18aa0c
/*  f18a9f0:	01c17025 */ 	or	$t6,$t6,$at
.L0f18a9f4:
/*  f18a9f4:	10000005 */ 	b	.L0f18aa0c
/*  f18a9f8:	240effff */ 	addiu	$t6,$zero,-1
/*  f18a9fc:	440e3000 */ 	mfc1	$t6,$f6
.L0f18aa00:
/*  f18aa00:	00000000 */ 	nop
/*  f18aa04:	05c0fffb */ 	bltz	$t6,.L0f18a9f4
/*  f18aa08:	00000000 */ 	nop
.L0f18aa0c:
/*  f18aa0c:	8e19006c */ 	lw	$t9,0x6c($s0)
/*  f18aa10:	44d8f800 */ 	ctc1	$t8,$31
/*  f18aa14:	032e6821 */ 	addu	$t5,$t9,$t6
/*  f18aa18:	ae0d006c */ 	sw	$t5,0x6c($s0)
/*  f18aa1c:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f18aa20:	19e00062 */ 	blez	$t7,.L0f18abac
/*  f18aa24:	00000000 */ 	nop
/*  f18aa28:	8e18005c */ 	lw	$t8,0x5c($s0)
/*  f18aa2c:	2f010002 */ 	sltiu	$at,$t8,0x2
/*  f18aa30:	10200027 */ 	beqz	$at,.L0f18aad0
/*  f18aa34:	3c01447a */ 	lui	$at,0x447a
/*  f18aa38:	44815000 */ 	mtc1	$at,$f10
/*  f18aa3c:	c6680038 */ 	lwc1	$f8,0x38($s3)
/*  f18aa40:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18aa44:	3c014f00 */ 	lui	$at,0x4f00
/*  f18aa48:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f18aa4c:	4459f800 */ 	cfc1	$t9,$31
/*  f18aa50:	44cef800 */ 	ctc1	$t6,$31
/*  f18aa54:	00000000 */ 	nop
/*  f18aa58:	46009424 */ 	cvt.w.s	$f16,$f18
/*  f18aa5c:	444ef800 */ 	cfc1	$t6,$31
/*  f18aa60:	00000000 */ 	nop
/*  f18aa64:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18aa68:	51c00013 */ 	beqzl	$t6,.L0f18aab8
/*  f18aa6c:	440e8000 */ 	mfc1	$t6,$f16
/*  f18aa70:	44818000 */ 	mtc1	$at,$f16
/*  f18aa74:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18aa78:	46109401 */ 	sub.s	$f16,$f18,$f16
/*  f18aa7c:	44cef800 */ 	ctc1	$t6,$31
/*  f18aa80:	00000000 */ 	nop
/*  f18aa84:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f18aa88:	444ef800 */ 	cfc1	$t6,$31
/*  f18aa8c:	00000000 */ 	nop
/*  f18aa90:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18aa94:	15c00005 */ 	bnez	$t6,.L0f18aaac
/*  f18aa98:	00000000 */ 	nop
/*  f18aa9c:	440e8000 */ 	mfc1	$t6,$f16
/*  f18aaa0:	3c018000 */ 	lui	$at,0x8000
/*  f18aaa4:	10000007 */ 	b	.L0f18aac4
/*  f18aaa8:	01c17025 */ 	or	$t6,$t6,$at
.L0f18aaac:
/*  f18aaac:	10000005 */ 	b	.L0f18aac4
/*  f18aab0:	240effff */ 	addiu	$t6,$zero,-1
/*  f18aab4:	440e8000 */ 	mfc1	$t6,$f16
.L0f18aab8:
/*  f18aab8:	00000000 */ 	nop
/*  f18aabc:	05c0fffb */ 	bltz	$t6,.L0f18aaac
/*  f18aac0:	00000000 */ 	nop
.L0f18aac4:
/*  f18aac4:	44d9f800 */ 	ctc1	$t9,$31
/*  f18aac8:	10000038 */ 	b	.L0f18abac
/*  f18aacc:	ae0e0070 */ 	sw	$t6,0x70($s0)
.L0f18aad0:
/*  f18aad0:	3c01447a */ 	lui	$at,0x447a
/*  f18aad4:	44810000 */ 	mtc1	$at,$f0
/*  f18aad8:	8e0d0070 */ 	lw	$t5,0x70($s0)
/*  f18aadc:	3c017f1c */ 	lui	$at,%hi(var7f1b8da4)
/*  f18aae0:	c4268da4 */ 	lwc1	$f6,%lo(var7f1b8da4)($at)
/*  f18aae4:	c6640038 */ 	lwc1	$f4,0x38($s3)
/*  f18aae8:	448d5000 */ 	mtc1	$t5,$f10
/*  f18aaec:	3c014f80 */ 	lui	$at,0x4f80
/*  f18aaf0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f18aaf4:	05a10004 */ 	bgez	$t5,.L0f18ab08
/*  f18aaf8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f18aafc:	44818000 */ 	mtc1	$at,$f16
/*  f18ab00:	00000000 */ 	nop
/*  f18ab04:	46109480 */ 	add.s	$f18,$f18,$f16
.L0f18ab08:
/*  f18ab08:	46009103 */ 	div.s	$f4,$f18,$f0
/*  f18ab0c:	3c017f1c */ 	lui	$at,%hi(var7f1b8da8)
/*  f18ab10:	c4268da8 */ 	lwc1	$f6,%lo(var7f1b8da8)($at)
/*  f18ab14:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18ab18:	3c014f00 */ 	lui	$at,0x4f00
/*  f18ab1c:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f18ab20:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f18ab24:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f18ab28:	444ff800 */ 	cfc1	$t7,$31
/*  f18ab2c:	44d8f800 */ 	ctc1	$t8,$31
/*  f18ab30:	00000000 */ 	nop
/*  f18ab34:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f18ab38:	4458f800 */ 	cfc1	$t8,$31
/*  f18ab3c:	00000000 */ 	nop
/*  f18ab40:	33180078 */ 	andi	$t8,$t8,0x78
/*  f18ab44:	53000013 */ 	beqzl	$t8,.L0f18ab94
/*  f18ab48:	44182000 */ 	mfc1	$t8,$f4
/*  f18ab4c:	44812000 */ 	mtc1	$at,$f4
/*  f18ab50:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18ab54:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f18ab58:	44d8f800 */ 	ctc1	$t8,$31
/*  f18ab5c:	00000000 */ 	nop
/*  f18ab60:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f18ab64:	4458f800 */ 	cfc1	$t8,$31
/*  f18ab68:	00000000 */ 	nop
/*  f18ab6c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f18ab70:	17000005 */ 	bnez	$t8,.L0f18ab88
/*  f18ab74:	00000000 */ 	nop
/*  f18ab78:	44182000 */ 	mfc1	$t8,$f4
/*  f18ab7c:	3c018000 */ 	lui	$at,0x8000
/*  f18ab80:	10000007 */ 	b	.L0f18aba0
/*  f18ab84:	0301c025 */ 	or	$t8,$t8,$at
.L0f18ab88:
/*  f18ab88:	10000005 */ 	b	.L0f18aba0
/*  f18ab8c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f18ab90:	44182000 */ 	mfc1	$t8,$f4
.L0f18ab94:
/*  f18ab94:	00000000 */ 	nop
/*  f18ab98:	0700fffb */ 	bltz	$t8,.L0f18ab88
/*  f18ab9c:	00000000 */ 	nop
.L0f18aba0:
/*  f18aba0:	44cff800 */ 	ctc1	$t7,$31
/*  f18aba4:	ae180070 */ 	sw	$t8,0x70($s0)
/*  f18aba8:	00000000 */ 	nop
.L0f18abac:
/*  f18abac:	3c017f1c */ 	lui	$at,%hi(var7f1b8dac)
/*  f18abb0:	c4288dac */ 	lwc1	$f8,%lo(var7f1b8dac)($at)
/*  f18abb4:	c68600f0 */ 	lwc1	$f6,0xf0($s4)
/*  f18abb8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18abbc:	3c014f00 */ 	lui	$at,0x4f00
/*  f18abc0:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f18abc4:	4459f800 */ 	cfc1	$t9,$31
/*  f18abc8:	44cef800 */ 	ctc1	$t6,$31
/*  f18abcc:	00000000 */ 	nop
/*  f18abd0:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f18abd4:	444ef800 */ 	cfc1	$t6,$31
/*  f18abd8:	00000000 */ 	nop
/*  f18abdc:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18abe0:	51c00013 */ 	beqzl	$t6,.L0f18ac30
/*  f18abe4:	440e8000 */ 	mfc1	$t6,$f16
/*  f18abe8:	44818000 */ 	mtc1	$at,$f16
/*  f18abec:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18abf0:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f18abf4:	44cef800 */ 	ctc1	$t6,$31
/*  f18abf8:	00000000 */ 	nop
/*  f18abfc:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f18ac00:	444ef800 */ 	cfc1	$t6,$31
/*  f18ac04:	00000000 */ 	nop
/*  f18ac08:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f18ac0c:	15c00005 */ 	bnez	$t6,.L0f18ac24
/*  f18ac10:	00000000 */ 	nop
/*  f18ac14:	440e8000 */ 	mfc1	$t6,$f16
/*  f18ac18:	3c018000 */ 	lui	$at,0x8000
/*  f18ac1c:	10000007 */ 	b	.L0f18ac3c
/*  f18ac20:	01c17025 */ 	or	$t6,$t6,$at
.L0f18ac24:
/*  f18ac24:	10000005 */ 	b	.L0f18ac3c
/*  f18ac28:	240effff */ 	addiu	$t6,$zero,-1
/*  f18ac2c:	440e8000 */ 	mfc1	$t6,$f16
.L0f18ac30:
/*  f18ac30:	00000000 */ 	nop
/*  f18ac34:	05c0fffb */ 	bltz	$t6,.L0f18ac24
/*  f18ac38:	00000000 */ 	nop
.L0f18ac3c:
/*  f18ac3c:	8e0d0074 */ 	lw	$t5,0x74($s0)
/*  f18ac40:	3c017f1c */ 	lui	$at,%hi(var7f1b8db0)
/*  f18ac44:	44d9f800 */ 	ctc1	$t9,$31
/*  f18ac48:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f18ac4c:	ae0f0074 */ 	sw	$t7,0x74($s0)
/*  f18ac50:	c4248db0 */ 	lwc1	$f4,%lo(var7f1b8db0)($at)
/*  f18ac54:	c69200ec */ 	lwc1	$f18,0xec($s4)
/*  f18ac58:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18ac5c:	3c014f00 */ 	lui	$at,0x4f00
/*  f18ac60:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f18ac64:	4458f800 */ 	cfc1	$t8,$31
/*  f18ac68:	44d9f800 */ 	ctc1	$t9,$31
/*  f18ac6c:	00000000 */ 	nop
/*  f18ac70:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f18ac74:	4459f800 */ 	cfc1	$t9,$31
/*  f18ac78:	00000000 */ 	nop
/*  f18ac7c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f18ac80:	53200013 */ 	beqzl	$t9,.L0f18acd0
/*  f18ac84:	44194000 */ 	mfc1	$t9,$f8
/*  f18ac88:	44814000 */ 	mtc1	$at,$f8
/*  f18ac8c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18ac90:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f18ac94:	44d9f800 */ 	ctc1	$t9,$31
/*  f18ac98:	00000000 */ 	nop
/*  f18ac9c:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f18aca0:	4459f800 */ 	cfc1	$t9,$31
/*  f18aca4:	00000000 */ 	nop
/*  f18aca8:	33390078 */ 	andi	$t9,$t9,0x78
/*  f18acac:	17200005 */ 	bnez	$t9,.L0f18acc4
/*  f18acb0:	00000000 */ 	nop
/*  f18acb4:	44194000 */ 	mfc1	$t9,$f8
/*  f18acb8:	3c018000 */ 	lui	$at,0x8000
/*  f18acbc:	10000007 */ 	b	.L0f18acdc
/*  f18acc0:	0321c825 */ 	or	$t9,$t9,$at
.L0f18acc4:
/*  f18acc4:	10000005 */ 	b	.L0f18acdc
/*  f18acc8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f18accc:	44194000 */ 	mfc1	$t9,$f8
.L0f18acd0:
/*  f18acd0:	00000000 */ 	nop
/*  f18acd4:	0720fffb */ 	bltz	$t9,.L0f18acc4
/*  f18acd8:	00000000 */ 	nop
.L0f18acdc:
/*  f18acdc:	8e0d0078 */ 	lw	$t5,0x78($s0)
/*  f18ace0:	44d8f800 */ 	ctc1	$t8,$31
/*  f18ace4:	8e0f007c */ 	lw	$t7,0x7c($s0)
/*  f18ace8:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f18acec:	ae0e0078 */ 	sw	$t6,0x78($s0)
/*  f18acf0:	8e780004 */ 	lw	$t8,0x4($s3)
/*  f18acf4:	8e190080 */ 	lw	$t9,0x80($s0)
/*  f18acf8:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f18acfc:	ae0d007c */ 	sw	$t5,0x7c($s0)
/*  f18ad00:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f18ad04:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f18ad08:	ae0f0080 */ 	sw	$t7,0x80($s0)
/*  f18ad0c:	8fb801e4 */ 	lw	$t8,0x1e4($sp)
/*  f18ad10:	8fae01e0 */ 	lw	$t6,0x1e0($sp)
/*  f18ad14:	2b010002 */ 	slti	$at,$t8,0x2
/*  f18ad18:	54200005 */ 	bnezl	$at,.L0f18ad30
/*  f18ad1c:	29c10002 */ 	slti	$at,$t6,0x2
/*  f18ad20:	8ead000c */ 	lw	$t5,0xc($s5)
/*  f18ad24:	31b90002 */ 	andi	$t9,$t5,0x2
/*  f18ad28:	13200003 */ 	beqz	$t9,.L0f18ad38
/*  f18ad2c:	29c10002 */ 	slti	$at,$t6,0x2
.L0f18ad30:
/*  f18ad30:	5420006f */ 	bnezl	$at,.L0f18aef0
/*  f18ad34:	8faf02fc */ 	lw	$t7,0x2fc($sp)
.L0f18ad38:
/*  f18ad38:	820f001e */ 	lb	$t7,0x1e($s0)
/*  f18ad3c:	00002825 */ 	or	$a1,$zero,$zero
/*  f18ad40:	00001825 */ 	or	$v1,$zero,$zero
/*  f18ad44:	55e0002e */ 	bnezl	$t7,.L0f18ae00
/*  f18ad48:	8ea6000c */ 	lw	$a2,0xc($s5)
/*  f18ad4c:	96a70016 */ 	lhu	$a3,0x16($s5)
/*  f18ad50:	24180001 */ 	addiu	$t8,$zero,0x1
.L0f18ad54:
/*  f18ad54:	00786804 */ 	sllv	$t5,$t8,$v1
/*  f18ad58:	00edc824 */ 	and	$t9,$a3,$t5
/*  f18ad5c:	1320001f */ 	beqz	$t9,.L0f18addc
/*  f18ad60:	28610004 */ 	slti	$at,$v1,0x4
/*  f18ad64:	10200006 */ 	beqz	$at,.L0f18ad80
/*  f18ad68:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f18ad6c:	00037080 */ 	sll	$t6,$v1,0x2
/*  f18ad70:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f18ad74:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18ad78:	1000000a */ 	b	.L0f18ada4
/*  f18ad7c:	03ce1021 */ 	addu	$v0,$s8,$t6
.L0f18ad80:
/*  f18ad80:	00037880 */ 	sll	$t7,$v1,0x2
/*  f18ad84:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f18ad88:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18ad8c:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f18ad90:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18ad94:	3c0d800b */ 	lui	$t5,%hi(g_MpSimulants)
/*  f18ad98:	25adc538 */ 	addiu	$t5,$t5,%lo(g_MpSimulants)
/*  f18ad9c:	25f8fed0 */ 	addiu	$t8,$t7,-304
/*  f18ada0:	030d1021 */ 	addu	$v0,$t8,$t5
.L0f18ada4:
/*  f18ada4:	8c590020 */ 	lw	$t9,0x20($v0)
/*  f18ada8:	5499000d */ 	bnel	$a0,$t9,.L0f18ade0
/*  f18adac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18adb0:	5202000b */ 	beql	$s0,$v0,.L0f18ade0
/*  f18adb4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18adb8:	8eae000c */ 	lw	$t6,0xc($s5)
/*  f18adbc:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f18adc0:	51e00006 */ 	beqzl	$t7,.L0f18addc
/*  f18adc4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18adc8:	92180011 */ 	lbu	$t8,0x11($s0)
/*  f18adcc:	904d0011 */ 	lbu	$t5,0x11($v0)
/*  f18add0:	530d0003 */ 	beql	$t8,$t5,.L0f18ade0
/*  f18add4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18add8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18addc:
/*  f18addc:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18ade0:
/*  f18ade0:	5477ffdc */ 	bnel	$v1,$s7,.L0f18ad54
/*  f18ade4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18ade8:	54a00005 */ 	bnezl	$a1,.L0f18ae00
/*  f18adec:	8ea6000c */ 	lw	$a2,0xc($s5)
/*  f18adf0:	8e190060 */ 	lw	$t9,0x60($s0)
/*  f18adf4:	272e0001 */ 	addiu	$t6,$t9,0x1
/*  f18adf8:	ae0e0060 */ 	sw	$t6,0x60($s0)
/*  f18adfc:	8ea6000c */ 	lw	$a2,0xc($s5)
.L0f18ae00:
/*  f18ae00:	30cf0002 */ 	andi	$t7,$a2,0x2
/*  f18ae04:	15e00006 */ 	bnez	$t7,.L0f18ae20
/*  f18ae08:	01e03025 */ 	or	$a2,$t7,$zero
/*  f18ae0c:	820d001e */ 	lb	$t5,0x1e($s0)
/*  f18ae10:	8fb801e4 */ 	lw	$t8,0x1e4($sp)
/*  f18ae14:	25b90001 */ 	addiu	$t9,$t5,0x1
/*  f18ae18:	53190008 */ 	beql	$t8,$t9,.L0f18ae3c
/*  f18ae1c:	00002825 */ 	or	$a1,$zero,$zero
.L0f18ae20:
/*  f18ae20:	10c00032 */ 	beqz	$a2,.L0f18aeec
/*  f18ae24:	00000000 */ 	nop
/*  f18ae28:	820f001e */ 	lb	$t7,0x1e($s0)
/*  f18ae2c:	8fae01e0 */ 	lw	$t6,0x1e0($sp)
/*  f18ae30:	25ed0001 */ 	addiu	$t5,$t7,0x1
/*  f18ae34:	15cd002d */ 	bne	$t6,$t5,.L0f18aeec
/*  f18ae38:	00002825 */ 	or	$a1,$zero,$zero
.L0f18ae3c:
/*  f18ae3c:	00001825 */ 	or	$v1,$zero,$zero
/*  f18ae40:	96a70016 */ 	lhu	$a3,0x16($s5)
/*  f18ae44:	240800a0 */ 	addiu	$t0,$zero,0xa0
/*  f18ae48:	24180001 */ 	addiu	$t8,$zero,0x1
.L0f18ae4c:
/*  f18ae4c:	0078c804 */ 	sllv	$t9,$t8,$v1
/*  f18ae50:	00f97824 */ 	and	$t7,$a3,$t9
/*  f18ae54:	11e0001d */ 	beqz	$t7,.L0f18aecc
/*  f18ae58:	28610004 */ 	slti	$at,$v1,0x4
/*  f18ae5c:	10200006 */ 	beqz	$at,.L0f18ae78
/*  f18ae60:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f18ae64:	00680019 */ 	multu	$v1,$t0
/*  f18ae68:	00007012 */ 	mflo	$t6
/*  f18ae6c:	03ce1021 */ 	addu	$v0,$s8,$t6
/*  f18ae70:	1000000b */ 	b	.L0f18aea0
/*  f18ae74:	8c4f0020 */ 	lw	$t7,0x20($v0)
.L0f18ae78:
/*  f18ae78:	00036880 */ 	sll	$t5,$v1,0x2
/*  f18ae7c:	01a36821 */ 	addu	$t5,$t5,$v1
/*  f18ae80:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18ae84:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f18ae88:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18ae8c:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f18ae90:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f18ae94:	25b8fed0 */ 	addiu	$t8,$t5,-304
/*  f18ae98:	03191021 */ 	addu	$v0,$t8,$t9
/*  f18ae9c:	8c4f0020 */ 	lw	$t7,0x20($v0)
.L0f18aea0:
/*  f18aea0:	548f000b */ 	bnel	$a0,$t7,.L0f18aed0
/*  f18aea4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18aea8:	52020009 */ 	beql	$s0,$v0,.L0f18aed0
/*  f18aeac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18aeb0:	50c00006 */ 	beqzl	$a2,.L0f18aecc
/*  f18aeb4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18aeb8:	920e0011 */ 	lbu	$t6,0x11($s0)
/*  f18aebc:	904d0011 */ 	lbu	$t5,0x11($v0)
/*  f18aec0:	51cd0003 */ 	beql	$t6,$t5,.L0f18aed0
/*  f18aec4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18aec8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f18aecc:
/*  f18aecc:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18aed0:
/*  f18aed0:	5477ffde */ 	bnel	$v1,$s7,.L0f18ae4c
/*  f18aed4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18aed8:	14a00004 */ 	bnez	$a1,.L0f18aeec
/*  f18aedc:	00000000 */ 	nop
/*  f18aee0:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f18aee4:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f18aee8:	ae190064 */ 	sw	$t9,0x64($s0)
.L0f18aeec:
/*  f18aeec:	8faf02fc */ 	lw	$t7,0x2fc($sp)
.L0f18aef0:
/*  f18aef0:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18aef4:	2673003c */ 	addiu	$s3,$s3,0x3c
/*  f18aef8:	16cffdec */ 	bne	$s6,$t7,.L0f18a6ac
/*  f18aefc:	26940080 */ 	addiu	$s4,$s4,0x80
.L0f18af00:
/*  f18af00:	3c1e800b */ 	lui	$s8,%hi(g_MpPlayers)
/*  f18af04:	27dec7b8 */ 	addiu	$s8,$s8,%lo(g_MpPlayers)
/*  f18af08:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f18af0c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f18af10:	8fa402f0 */ 	lw	$a0,0x2f0($sp)
/*  f18af14:	8fae02c0 */ 	lw	$t6,0x2c0($sp)
/*  f18af18:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18af1c:	8fa5020c */ 	lw	$a1,0x20c($sp)
/*  f18af20:	8fa60248 */ 	lw	$a2,0x248($sp)
/*  f18af24:	8fa70284 */ 	lw	$a3,0x284($sp)
/*  f18af28:	0fc62730 */ 	jal	func0f189cc0
/*  f18af2c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f18af30:	00026900 */ 	sll	$t5,$v0,0x4
/*  f18af34:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18af38:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18af3c:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18af40:	01b88021 */ 	addu	$s0,$t5,$t8
/*  f18af44:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f18af48:	5b200005 */ 	blezl	$t9,.L0f18af60
/*  f18af4c:	8fad02b0 */ 	lw	$t5,0x2b0($sp)
/*  f18af50:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f18af54:	35ee0001 */ 	ori	$t6,$t7,0x1
/*  f18af58:	ae0e002c */ 	sw	$t6,0x2c($s0)
/*  f18af5c:	8fad02b0 */ 	lw	$t5,0x2b0($sp)
.L0f18af60:
/*  f18af60:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18af64:	8fa501fc */ 	lw	$a1,0x1fc($sp)
/*  f18af68:	8fa60238 */ 	lw	$a2,0x238($sp)
/*  f18af6c:	8fa70274 */ 	lw	$a3,0x274($sp)
/*  f18af70:	0fc62772 */ 	jal	func0f189dc8
/*  f18af74:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f18af78:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f18af7c:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f18af80:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f18af84:	27b901fc */ 	addiu	$t9,$sp,0x1fc
/*  f18af88:	03198021 */ 	addu	$s0,$t8,$t9
/*  f18af8c:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f18af90:	29e10064 */ 	slti	$at,$t7,0x64
/*  f18af94:	50200005 */ 	beqzl	$at,.L0f18afac
/*  f18af98:	c7aa02d8 */ 	lwc1	$f10,0x2d8($sp)
/*  f18af9c:	8e0e002c */ 	lw	$t6,0x2c($s0)
/*  f18afa0:	35cd0002 */ 	ori	$t5,$t6,0x2
/*  f18afa4:	ae0d002c */ 	sw	$t5,0x2c($s0)
/*  f18afa8:	c7aa02d8 */ 	lwc1	$f10,0x2d8($sp)
.L0f18afac:
/*  f18afac:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18afb0:	8fa50224 */ 	lw	$a1,0x224($sp)
/*  f18afb4:	8fa60260 */ 	lw	$a2,0x260($sp)
/*  f18afb8:	8fa7029c */ 	lw	$a3,0x29c($sp)
/*  f18afbc:	0fc6280c */ 	jal	func0f18a030
/*  f18afc0:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f18afc4:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f18afc8:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f18afcc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f18afd0:	27b901fc */ 	addiu	$t9,$sp,0x1fc
/*  f18afd4:	03198021 */ 	addu	$s0,$t8,$t9
/*  f18afd8:	3c014000 */ 	lui	$at,0x4000
/*  f18afdc:	44818000 */ 	mtc1	$at,$f16
/*  f18afe0:	c6120028 */ 	lwc1	$f18,0x28($s0)
/*  f18afe4:	4610903e */ 	c.le.s	$f18,$f16
/*  f18afe8:	00000000 */ 	nop
/*  f18afec:	45020005 */ 	bc1fl	.L0f18b004
/*  f18aff0:	c7a402d8 */ 	lwc1	$f4,0x2d8($sp)
/*  f18aff4:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f18aff8:	35ee0004 */ 	ori	$t6,$t7,0x4
/*  f18affc:	ae0e002c */ 	sw	$t6,0x2c($s0)
/*  f18b000:	c7a402d8 */ 	lwc1	$f4,0x2d8($sp)
.L0f18b004:
/*  f18b004:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b008:	8fa50224 */ 	lw	$a1,0x224($sp)
/*  f18b00c:	8fa60260 */ 	lw	$a2,0x260($sp)
/*  f18b010:	8fa7029c */ 	lw	$a3,0x29c($sp)
/*  f18b014:	0fc627b4 */ 	jal	func0f189ed0
/*  f18b018:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f18b01c:	00026900 */ 	sll	$t5,$v0,0x4
/*  f18b020:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18b024:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b028:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18b02c:	01b88021 */ 	addu	$s0,$t5,$t8
/*  f18b030:	3c0140c0 */ 	lui	$at,0x40c0
/*  f18b034:	44813000 */ 	mtc1	$at,$f6
/*  f18b038:	c6080028 */ 	lwc1	$f8,0x28($s0)
/*  f18b03c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f18b040:	00000000 */ 	nop
/*  f18b044:	45020005 */ 	bc1fl	.L0f18b05c
/*  f18b048:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f18b04c:	8e19002c */ 	lw	$t9,0x2c($s0)
/*  f18b050:	372f0008 */ 	ori	$t7,$t9,0x8
/*  f18b054:	ae0f002c */ 	sw	$t7,0x2c($s0)
/*  f18b058:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
.L0f18b05c:
/*  f18b05c:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b060:	8fa50200 */ 	lw	$a1,0x200($sp)
/*  f18b064:	8fa6023c */ 	lw	$a2,0x23c($sp)
/*  f18b068:	8fa70278 */ 	lw	$a3,0x278($sp)
/*  f18b06c:	0fc62730 */ 	jal	func0f189cc0
/*  f18b070:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f18b074:	00026900 */ 	sll	$t5,$v0,0x4
/*  f18b078:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18b07c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b080:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18b084:	01b88021 */ 	addu	$s0,$t5,$t8
/*  f18b088:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f18b08c:	5b200005 */ 	blezl	$t9,.L0f18b0a4
/*  f18b090:	c7aa02c4 */ 	lwc1	$f10,0x2c4($sp)
/*  f18b094:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f18b098:	35ee0010 */ 	ori	$t6,$t7,0x10
/*  f18b09c:	ae0e002c */ 	sw	$t6,0x2c($s0)
/*  f18b0a0:	c7aa02c4 */ 	lwc1	$f10,0x2c4($sp)
.L0f18b0a4:
/*  f18b0a4:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b0a8:	8fa50210 */ 	lw	$a1,0x210($sp)
/*  f18b0ac:	8fa6024c */ 	lw	$a2,0x24c($sp)
/*  f18b0b0:	8fa70288 */ 	lw	$a3,0x288($sp)
/*  f18b0b4:	0fc627b4 */ 	jal	func0f189ed0
/*  f18b0b8:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f18b0bc:	00026900 */ 	sll	$t5,$v0,0x4
/*  f18b0c0:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18b0c4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b0c8:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18b0cc:	01b88021 */ 	addu	$s0,$t5,$t8
/*  f18b0d0:	c6120014 */ 	lwc1	$f18,0x14($s0)
/*  f18b0d4:	44808000 */ 	mtc1	$zero,$f16
/*  f18b0d8:	00000000 */ 	nop
/*  f18b0dc:	4612803c */ 	c.lt.s	$f16,$f18
/*  f18b0e0:	00000000 */ 	nop
/*  f18b0e4:	45020005 */ 	bc1fl	.L0f18b0fc
/*  f18b0e8:	c7a402c8 */ 	lwc1	$f4,0x2c8($sp)
/*  f18b0ec:	8e19002c */ 	lw	$t9,0x2c($s0)
/*  f18b0f0:	372f0020 */ 	ori	$t7,$t9,0x20
/*  f18b0f4:	ae0f002c */ 	sw	$t7,0x2c($s0)
/*  f18b0f8:	c7a402c8 */ 	lwc1	$f4,0x2c8($sp)
.L0f18b0fc:
/*  f18b0fc:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b100:	8fa50214 */ 	lw	$a1,0x214($sp)
/*  f18b104:	8fa60250 */ 	lw	$a2,0x250($sp)
/*  f18b108:	8fa7028c */ 	lw	$a3,0x28c($sp)
/*  f18b10c:	0fc627b4 */ 	jal	func0f189ed0
/*  f18b110:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f18b114:	00027100 */ 	sll	$t6,$v0,0x4
/*  f18b118:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f18b11c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18b120:	27ad01fc */ 	addiu	$t5,$sp,0x1fc
/*  f18b124:	01cd8021 */ 	addu	$s0,$t6,$t5
/*  f18b128:	c6080018 */ 	lwc1	$f8,0x18($s0)
/*  f18b12c:	44803000 */ 	mtc1	$zero,$f6
/*  f18b130:	00000000 */ 	nop
/*  f18b134:	4608303c */ 	c.lt.s	$f6,$f8
/*  f18b138:	00000000 */ 	nop
/*  f18b13c:	45020005 */ 	bc1fl	.L0f18b154
/*  f18b140:	c7aa02c8 */ 	lwc1	$f10,0x2c8($sp)
/*  f18b144:	8e18002c */ 	lw	$t8,0x2c($s0)
/*  f18b148:	37190040 */ 	ori	$t9,$t8,0x40
/*  f18b14c:	ae19002c */ 	sw	$t9,0x2c($s0)
/*  f18b150:	c7aa02c8 */ 	lwc1	$f10,0x2c8($sp)
.L0f18b154:
/*  f18b154:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b158:	8fa50214 */ 	lw	$a1,0x214($sp)
/*  f18b15c:	8fa60250 */ 	lw	$a2,0x250($sp)
/*  f18b160:	8fa7028c */ 	lw	$a3,0x28c($sp)
/*  f18b164:	0fc6280c */ 	jal	func0f18a030
/*  f18b168:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f18b16c:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x6c)
/*  f18b170:	8defa02c */ 	lw	$t7,%lo(g_Vars+0x6c)($t7)
/*  f18b174:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x68)
/*  f18b178:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x64)
/*  f18b17c:	11e00003 */ 	beqz	$t7,.L0f18b18c
/*  f18b180:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18b184:	10000002 */ 	b	.L0f18b190
/*  f18b188:	afae0064 */ 	sw	$t6,0x64($sp)
.L0f18b18c:
/*  f18b18c:	afa00064 */ 	sw	$zero,0x64($sp)
.L0f18b190:
/*  f18b190:	8dada028 */ 	lw	$t5,%lo(g_Vars+0x68)($t5)
/*  f18b194:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x70)
/*  f18b198:	11a00003 */ 	beqz	$t5,.L0f18b1a8
/*  f18b19c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18b1a0:	10000002 */ 	b	.L0f18b1ac
/*  f18b1a4:	afb80068 */ 	sw	$t8,0x68($sp)
.L0f18b1a8:
/*  f18b1a8:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f18b1ac:
/*  f18b1ac:	8f39a024 */ 	lw	$t9,%lo(g_Vars+0x64)($t9)
/*  f18b1b0:	13200003 */ 	beqz	$t9,.L0f18b1c0
/*  f18b1b4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18b1b8:	10000002 */ 	b	.L0f18b1c4
/*  f18b1bc:	afaf006c */ 	sw	$t7,0x6c($sp)
.L0f18b1c0:
/*  f18b1c0:	afa0006c */ 	sw	$zero,0x6c($sp)
.L0f18b1c4:
/*  f18b1c4:	8dcea030 */ 	lw	$t6,%lo(g_Vars+0x70)($t6)
/*  f18b1c8:	8fad006c */ 	lw	$t5,0x6c($sp)
/*  f18b1cc:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f18b1d0:	51c00004 */ 	beqzl	$t6,.L0f18b1e4
/*  f18b1d4:	00008825 */ 	or	$s1,$zero,$zero
/*  f18b1d8:	10000002 */ 	b	.L0f18b1e4
/*  f18b1dc:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f18b1e0:	00008825 */ 	or	$s1,$zero,$zero
.L0f18b1e4:
/*  f18b1e4:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f18b1e8:	022dc021 */ 	addu	$t8,$s1,$t5
/*  f18b1ec:	03197821 */ 	addu	$t7,$t8,$t9
/*  f18b1f0:	01ee6821 */ 	addu	$t5,$t7,$t6
/*  f18b1f4:	29a10002 */ 	slti	$at,$t5,0x2
/*  f18b1f8:	14200008 */ 	bnez	$at,.L0f18b21c
/*  f18b1fc:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f18b200:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f18b204:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f18b208:	27b901fc */ 	addiu	$t9,$sp,0x1fc
/*  f18b20c:	03198021 */ 	addu	$s0,$t8,$t9
/*  f18b210:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f18b214:	35ee0080 */ 	ori	$t6,$t7,0x80
/*  f18b218:	ae0e002c */ 	sw	$t6,0x2c($s0)
.L0f18b21c:
/*  f18b21c:	8fad02d0 */ 	lw	$t5,0x2d0($sp)
/*  f18b220:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b224:	8fa5021c */ 	lw	$a1,0x21c($sp)
/*  f18b228:	8fa60258 */ 	lw	$a2,0x258($sp)
/*  f18b22c:	8fa70294 */ 	lw	$a3,0x294($sp)
/*  f18b230:	0fc62772 */ 	jal	func0f189dc8
/*  f18b234:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f18b238:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x6c)
/*  f18b23c:	8f18a02c */ 	lw	$t8,%lo(g_Vars+0x6c)($t8)
/*  f18b240:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x68)
/*  f18b244:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x64)
/*  f18b248:	13000003 */ 	beqz	$t8,.L0f18b258
/*  f18b24c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18b250:	10000002 */ 	b	.L0f18b25c
/*  f18b254:	afb90064 */ 	sw	$t9,0x64($sp)
.L0f18b258:
/*  f18b258:	afa00064 */ 	sw	$zero,0x64($sp)
.L0f18b25c:
/*  f18b25c:	8defa028 */ 	lw	$t7,%lo(g_Vars+0x68)($t7)
/*  f18b260:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x70)
/*  f18b264:	11e00003 */ 	beqz	$t7,.L0f18b274
/*  f18b268:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18b26c:	10000002 */ 	b	.L0f18b278
/*  f18b270:	afae0068 */ 	sw	$t6,0x68($sp)
.L0f18b274:
/*  f18b274:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f18b278:
/*  f18b278:	8dada024 */ 	lw	$t5,%lo(g_Vars+0x64)($t5)
/*  f18b27c:	11a00003 */ 	beqz	$t5,.L0f18b28c
/*  f18b280:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18b284:	10000002 */ 	b	.L0f18b290
/*  f18b288:	afb8006c */ 	sw	$t8,0x6c($sp)
.L0f18b28c:
/*  f18b28c:	afa0006c */ 	sw	$zero,0x6c($sp)
.L0f18b290:
/*  f18b290:	8f39a030 */ 	lw	$t9,%lo(g_Vars+0x70)($t9)
/*  f18b294:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f18b298:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f18b29c:	53200004 */ 	beqzl	$t9,.L0f18b2b0
/*  f18b2a0:	00008825 */ 	or	$s1,$zero,$zero
/*  f18b2a4:	10000002 */ 	b	.L0f18b2b0
/*  f18b2a8:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f18b2ac:	00008825 */ 	or	$s1,$zero,$zero
.L0f18b2b0:
/*  f18b2b0:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f18b2b4:	022f7021 */ 	addu	$t6,$s1,$t7
/*  f18b2b8:	01cdc021 */ 	addu	$t8,$t6,$t5
/*  f18b2bc:	03197821 */ 	addu	$t7,$t8,$t9
/*  f18b2c0:	29e10002 */ 	slti	$at,$t7,0x2
/*  f18b2c4:	14200008 */ 	bnez	$at,.L0f18b2e8
/*  f18b2c8:	00027100 */ 	sll	$t6,$v0,0x4
/*  f18b2cc:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f18b2d0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18b2d4:	27ad01fc */ 	addiu	$t5,$sp,0x1fc
/*  f18b2d8:	01cd8021 */ 	addu	$s0,$t6,$t5
/*  f18b2dc:	8e18002c */ 	lw	$t8,0x2c($s0)
/*  f18b2e0:	37190100 */ 	ori	$t9,$t8,0x100
/*  f18b2e4:	ae19002c */ 	sw	$t9,0x2c($s0)
.L0f18b2e8:
/*  f18b2e8:	c7b002d4 */ 	lwc1	$f16,0x2d4($sp)
/*  f18b2ec:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b2f0:	8fa50220 */ 	lw	$a1,0x220($sp)
/*  f18b2f4:	8fa6025c */ 	lw	$a2,0x25c($sp)
/*  f18b2f8:	8fa70298 */ 	lw	$a3,0x298($sp)
/*  f18b2fc:	0fc627b4 */ 	jal	func0f189ed0
/*  f18b300:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f18b304:	00027900 */ 	sll	$t7,$v0,0x4
/*  f18b308:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18b30c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18b310:	27ae01fc */ 	addiu	$t6,$sp,0x1fc
/*  f18b314:	01ee8021 */ 	addu	$s0,$t7,$t6
/*  f18b318:	3c014120 */ 	lui	$at,0x4120
/*  f18b31c:	44819000 */ 	mtc1	$at,$f18
/*  f18b320:	c6040024 */ 	lwc1	$f4,0x24($s0)
/*  f18b324:	4604903c */ 	c.lt.s	$f18,$f4
/*  f18b328:	00000000 */ 	nop
/*  f18b32c:	45020005 */ 	bc1fl	.L0f18b344
/*  f18b330:	8fb902cc */ 	lw	$t9,0x2cc($sp)
/*  f18b334:	8e0d002c */ 	lw	$t5,0x2c($s0)
/*  f18b338:	35b80200 */ 	ori	$t8,$t5,0x200
/*  f18b33c:	ae18002c */ 	sw	$t8,0x2c($s0)
/*  f18b340:	8fb902cc */ 	lw	$t9,0x2cc($sp)
.L0f18b344:
/*  f18b344:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b348:	8fa50218 */ 	lw	$a1,0x218($sp)
/*  f18b34c:	8fa60254 */ 	lw	$a2,0x254($sp)
/*  f18b350:	8fa70290 */ 	lw	$a3,0x290($sp)
/*  f18b354:	0fc62772 */ 	jal	func0f189dc8
/*  f18b358:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f18b35c:	00027900 */ 	sll	$t7,$v0,0x4
/*  f18b360:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18b364:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18b368:	27ae01fc */ 	addiu	$t6,$sp,0x1fc
/*  f18b36c:	01ee8021 */ 	addu	$s0,$t7,$t6
/*  f18b370:	8e0d002c */ 	lw	$t5,0x2c($s0)
/*  f18b374:	35b80400 */ 	ori	$t8,$t5,0x400
/*  f18b378:	ae18002c */ 	sw	$t8,0x2c($s0)
/*  f18b37c:	8fb902cc */ 	lw	$t9,0x2cc($sp)
/*  f18b380:	8fa70290 */ 	lw	$a3,0x290($sp)
/*  f18b384:	8fa60254 */ 	lw	$a2,0x254($sp)
/*  f18b388:	8fa50218 */ 	lw	$a1,0x218($sp)
/*  f18b38c:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b390:	0fc62730 */ 	jal	func0f189cc0
/*  f18b394:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f18b398:	00027900 */ 	sll	$t7,$v0,0x4
/*  f18b39c:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18b3a0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18b3a4:	27ae01fc */ 	addiu	$t6,$sp,0x1fc
/*  f18b3a8:	01ee8021 */ 	addu	$s0,$t7,$t6
/*  f18b3ac:	8e0d001c */ 	lw	$t5,0x1c($s0)
/*  f18b3b0:	59a00007 */ 	blezl	$t5,.L0f18b3d0
/*  f18b3b4:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f18b3b8:	8e03002c */ 	lw	$v1,0x2c($s0)
/*  f18b3bc:	30780400 */ 	andi	$t8,$v1,0x400
/*  f18b3c0:	17000002 */ 	bnez	$t8,.L0f18b3cc
/*  f18b3c4:	34790800 */ 	ori	$t9,$v1,0x800
/*  f18b3c8:	ae19002c */ 	sw	$t9,0x2c($s0)
.L0f18b3cc:
/*  f18b3cc:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
.L0f18b3d0:
/*  f18b3d0:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b3d4:	8fa5022c */ 	lw	$a1,0x22c($sp)
/*  f18b3d8:	8fa60268 */ 	lw	$a2,0x268($sp)
/*  f18b3dc:	8fa702a4 */ 	lw	$a3,0x2a4($sp)
/*  f18b3e0:	0fc62730 */ 	jal	func0f189cc0
/*  f18b3e4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f18b3e8:	00027100 */ 	sll	$t6,$v0,0x4
/*  f18b3ec:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f18b3f0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18b3f4:	27ad01fc */ 	addiu	$t5,$sp,0x1fc
/*  f18b3f8:	01cd8021 */ 	addu	$s0,$t6,$t5
/*  f18b3fc:	8e180030 */ 	lw	$t8,0x30($s0)
/*  f18b400:	5b000005 */ 	blezl	$t8,.L0f18b418
/*  f18b404:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f18b408:	8e19002c */ 	lw	$t9,0x2c($s0)
/*  f18b40c:	372f2000 */ 	ori	$t7,$t9,0x2000
/*  f18b410:	ae0f002c */ 	sw	$t7,0x2c($s0)
/*  f18b414:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
.L0f18b418:
/*  f18b418:	8fa402fc */ 	lw	$a0,0x2fc($sp)
/*  f18b41c:	8fa50230 */ 	lw	$a1,0x230($sp)
/*  f18b420:	8fa6026c */ 	lw	$a2,0x26c($sp)
/*  f18b424:	8fa702a8 */ 	lw	$a3,0x2a8($sp)
/*  f18b428:	0fc62772 */ 	jal	func0f189dc8
/*  f18b42c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f18b430:	00026900 */ 	sll	$t5,$v0,0x4
/*  f18b434:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18b438:	27a701fc */ 	addiu	$a3,$sp,0x1fc
/*  f18b43c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b440:	00ed8021 */ 	addu	$s0,$a3,$t5
/*  f18b444:	8e180034 */ 	lw	$t8,0x34($s0)
/*  f18b448:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f18b44c:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f18b450:	1b000007 */ 	blez	$t8,.L0f18b470
/*  f18b454:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f18b458:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f18b45c:	5b200005 */ 	blezl	$t9,.L0f18b474
/*  f18b460:	8fa802fc */ 	lw	$t0,0x2fc($sp)
/*  f18b464:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f18b468:	35ee1000 */ 	ori	$t6,$t7,0x1000
/*  f18b46c:	ae0e002c */ 	sw	$t6,0x2c($s0)
.L0f18b470:
/*  f18b470:	8fa802fc */ 	lw	$t0,0x2fc($sp)
.L0f18b474:
/*  f18b474:	0000b025 */ 	or	$s6,$zero,$zero
/*  f18b478:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18b47c:	19000021 */ 	blez	$t0,.L0f18b504
/*  f18b480:	3c040001 */ 	lui	$a0,0x1
/*  f18b484:	24030004 */ 	addiu	$v1,$zero,0x4
.L0f18b488:
/*  f18b488:	8e8200cc */ 	lw	$v0,0xcc($s4)
/*  f18b48c:	00166900 */ 	sll	$t5,$s6,0x4
/*  f18b490:	01b66823 */ 	subu	$t5,$t5,$s6
/*  f18b494:	14620006 */ 	bne	$v1,$v0,.L0f18b4b0
/*  f18b498:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b49c:	00ed9821 */ 	addu	$s3,$a3,$t5
/*  f18b4a0:	8e78002c */ 	lw	$t8,0x2c($s3)
/*  f18b4a4:	0304c825 */ 	or	$t9,$t8,$a0
/*  f18b4a8:	10000012 */ 	b	.L0f18b4f4
/*  f18b4ac:	ae79002c */ 	sw	$t9,0x2c($s3)
.L0f18b4b0:
/*  f18b4b0:	14a20008 */ 	bne	$a1,$v0,.L0f18b4d4
/*  f18b4b4:	00167900 */ 	sll	$t7,$s6,0x4
/*  f18b4b8:	01f67823 */ 	subu	$t7,$t7,$s6
/*  f18b4bc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f18b4c0:	00ef9821 */ 	addu	$s3,$a3,$t7
/*  f18b4c4:	8e6e002c */ 	lw	$t6,0x2c($s3)
/*  f18b4c8:	35cd8000 */ 	ori	$t5,$t6,0x8000
/*  f18b4cc:	10000009 */ 	b	.L0f18b4f4
/*  f18b4d0:	ae6d002c */ 	sw	$t5,0x2c($s3)
.L0f18b4d4:
/*  f18b4d4:	14c20007 */ 	bne	$a2,$v0,.L0f18b4f4
/*  f18b4d8:	0016c100 */ 	sll	$t8,$s6,0x4
/*  f18b4dc:	0316c023 */ 	subu	$t8,$t8,$s6
/*  f18b4e0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f18b4e4:	00f89821 */ 	addu	$s3,$a3,$t8
/*  f18b4e8:	8e79002c */ 	lw	$t9,0x2c($s3)
/*  f18b4ec:	372f4000 */ 	ori	$t7,$t9,0x4000
/*  f18b4f0:	ae6f002c */ 	sw	$t7,0x2c($s3)
.L0f18b4f4:
/*  f18b4f4:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18b4f8:	16c8ffe3 */ 	bne	$s6,$t0,.L0f18b488
/*  f18b4fc:	26940080 */ 	addiu	$s4,$s4,0x80
/*  f18b500:	0000b025 */ 	or	$s6,$zero,$zero
.L0f18b504:
/*  f18b504:	1900000a */ 	blez	$t0,.L0f18b530
/*  f18b508:	27b301fc */ 	addiu	$s3,$sp,0x1fc
/*  f18b50c:	24020011 */ 	addiu	$v0,$zero,0x11
.L0f18b510:
/*  f18b510:	00001825 */ 	or	$v1,$zero,$zero
/*  f18b514:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18b518:
/*  f18b518:	5462ffff */ 	bnel	$v1,$v0,.L0f18b518
/*  f18b51c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18b520:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18b524:	16c8fffa */ 	bne	$s6,$t0,.L0f18b510
/*  f18b528:	2673003c */ 	addiu	$s3,$s3,0x3c
/*  f18b52c:	0000b025 */ 	or	$s6,$zero,$zero
.L0f18b530:
/*  f18b530:	19000066 */ 	blez	$t0,.L0f18b6cc
/*  f18b534:	3c148008 */ 	lui	$s4,%hi(var800874cc)
/*  f18b538:	269474cc */ 	addiu	$s4,$s4,%lo(var800874cc)
/*  f18b53c:	24150011 */ 	addiu	$s5,$zero,0x11
/*  f18b540:	8fae02fc */ 	lw	$t6,0x2fc($sp)
.L0f18b544:
/*  f18b544:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18b548:	00009025 */ 	or	$s2,$zero,$zero
/*  f18b54c:	15c1000b */ 	bne	$t6,$at,.L0f18b57c
/*  f18b550:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f18b554:	00166900 */ 	sll	$t5,$s6,0x4
/*  f18b558:	01b66823 */ 	subu	$t5,$t5,$s6
/*  f18b55c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b560:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18b564:	01b89821 */ 	addu	$s3,$t5,$t8
/*  f18b568:	8e79002c */ 	lw	$t9,0x2c($s3)
/*  f18b56c:	3c010001 */ 	lui	$at,0x1
/*  f18b570:	3421c670 */ 	ori	$at,$at,0xc670
/*  f18b574:	03217824 */ 	and	$t7,$t9,$at
/*  f18b578:	ae6f002c */ 	sw	$t7,0x2c($s3)
.L0f18b57c:
/*  f18b57c:	00167100 */ 	sll	$t6,$s6,0x4
/*  f18b580:	01d67023 */ 	subu	$t6,$t6,$s6
/*  f18b584:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18b588:	27ad01fc */ 	addiu	$t5,$sp,0x1fc
/*  f18b58c:	01cd9821 */ 	addu	$s3,$t6,$t5
/*  f18b590:	8e70002c */ 	lw	$s0,0x2c($s3)
.L0f18b594:
/*  f18b594:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18b598:	00b81004 */ 	sllv	$v0,$t8,$a1
/*  f18b59c:	0202c824 */ 	and	$t9,$s0,$v0
/*  f18b5a0:	1320000f */ 	beqz	$t9,.L0f18b5e0
/*  f18b5a4:	00407827 */ 	nor	$t7,$v0,$zero
/*  f18b5a8:	020f7024 */ 	and	$t6,$s0,$t7
/*  f18b5ac:	3c0f800a */ 	lui	$t7,%hi(g_Vars)
/*  f18b5b0:	00056840 */ 	sll	$t5,$a1,0x1
/*  f18b5b4:	028dc021 */ 	addu	$t8,$s4,$t5
/*  f18b5b8:	25ef9fc0 */ 	addiu	$t7,$t7,%lo(g_Vars)
/*  f18b5bc:	0016c880 */ 	sll	$t9,$s6,0x2
/*  f18b5c0:	ae6e002c */ 	sw	$t6,0x2c($s3)
/*  f18b5c4:	032f8821 */ 	addu	$s1,$t9,$t7
/*  f18b5c8:	97040000 */ 	lhu	$a0,0x0($t8)
/*  f18b5cc:	0fc5b9f1 */ 	jal	langGet
/*  f18b5d0:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f18b5d4:	8e2e0064 */ 	lw	$t6,0x64($s1)
/*  f18b5d8:	adc21974 */ 	sw	$v0,0x1974($t6)
/*  f18b5dc:	8e70002c */ 	lw	$s0,0x2c($s3)
.L0f18b5e0:
/*  f18b5e0:	16000002 */ 	bnez	$s0,.L0f18b5ec
/*  f18b5e4:	00000000 */ 	nop
/*  f18b5e8:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f18b5ec:
/*  f18b5ec:	0c004b70 */ 	jal	random
/*  f18b5f0:	00000000 */ 	nop
/*  f18b5f4:	0055001b */ 	divu	$zero,$v0,$s5
/*  f18b5f8:	00002810 */ 	mfhi	$a1
/*  f18b5fc:	16a00002 */ 	bnez	$s5,.L0f18b608
/*  f18b600:	00000000 */ 	nop
/*  f18b604:	0007000d */ 	break	0x7
.L0f18b608:
/*  f18b608:	5240ffe2 */ 	beqzl	$s2,.L0f18b594
/*  f18b60c:	8e70002c */ 	lw	$s0,0x2c($s3)
/*  f18b610:	2a410002 */ 	slti	$at,$s2,0x2
/*  f18b614:	10200029 */ 	beqz	$at,.L0f18b6bc
/*  f18b618:	00166900 */ 	sll	$t5,$s6,0x4
/*  f18b61c:	01b66823 */ 	subu	$t5,$t5,$s6
/*  f18b620:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b624:	27b801fc */ 	addiu	$t8,$sp,0x1fc
/*  f18b628:	01b89821 */ 	addu	$s3,$t5,$t8
.L0f18b62c:
/*  f18b62c:	0c004b70 */ 	jal	random
/*  f18b630:	00000000 */ 	nop
/*  f18b634:	0055001b */ 	divu	$zero,$v0,$s5
/*  f18b638:	8e70002c */ 	lw	$s0,0x2c($s3)
/*  f18b63c:	00001810 */ 	mfhi	$v1
/*  f18b640:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18b644:	00797804 */ 	sllv	$t7,$t9,$v1
/*  f18b648:	16a00002 */ 	bnez	$s5,.L0f18b654
/*  f18b64c:	00000000 */ 	nop
/*  f18b650:	0007000d */ 	break	0x7
.L0f18b654:
/*  f18b654:	020f7024 */ 	and	$t6,$s0,$t7
/*  f18b658:	11c00012 */ 	beqz	$t6,.L0f18b6a4
/*  f18b65c:	00602825 */ 	or	$a1,$v1,$zero
/*  f18b660:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f18b664:	006dc004 */ 	sllv	$t8,$t5,$v1
/*  f18b668:	0300c827 */ 	nor	$t9,$t8,$zero
/*  f18b66c:	02197824 */ 	and	$t7,$s0,$t9
/*  f18b670:	3c19800a */ 	lui	$t9,%hi(g_Vars)
/*  f18b674:	00037040 */ 	sll	$t6,$v1,0x1
/*  f18b678:	028e6821 */ 	addu	$t5,$s4,$t6
/*  f18b67c:	27399fc0 */ 	addiu	$t9,$t9,%lo(g_Vars)
/*  f18b680:	0016c080 */ 	sll	$t8,$s6,0x2
/*  f18b684:	ae6f002c */ 	sw	$t7,0x2c($s3)
/*  f18b688:	03198821 */ 	addu	$s1,$t8,$t9
/*  f18b68c:	95a40000 */ 	lhu	$a0,0x0($t5)
/*  f18b690:	0fc5b9f1 */ 	jal	langGet
/*  f18b694:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f18b698:	8e2f0064 */ 	lw	$t7,0x64($s1)
/*  f18b69c:	ade21978 */ 	sw	$v0,0x1978($t7)
/*  f18b6a0:	8e70002c */ 	lw	$s0,0x2c($s3)
.L0f18b6a4:
/*  f18b6a4:	56000003 */ 	bnezl	$s0,.L0f18b6b4
/*  f18b6a8:	2a410002 */ 	slti	$at,$s2,0x2
/*  f18b6ac:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f18b6b0:	2a410002 */ 	slti	$at,$s2,0x2
.L0f18b6b4:
/*  f18b6b4:	1420ffdd */ 	bnez	$at,.L0f18b62c
/*  f18b6b8:	00000000 */ 	nop
.L0f18b6bc:
/*  f18b6bc:	8fae02fc */ 	lw	$t6,0x2fc($sp)
/*  f18b6c0:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18b6c4:	56ceff9f */ 	bnel	$s6,$t6,.L0f18b544
/*  f18b6c8:	8fae02fc */ 	lw	$t6,0x2fc($sp)
.L0f18b6cc:
/*  f18b6cc:	8fad01e4 */ 	lw	$t5,0x1e4($sp)
/*  f18b6d0:	29a10002 */ 	slti	$at,$t5,0x2
/*  f18b6d4:	14200072 */ 	bnez	$at,.L0f18b8a0
/*  f18b6d8:	3c0800ff */ 	lui	$t0,0xff
/*  f18b6dc:	3c07800b */ 	lui	$a3,%hi(g_MpSetup+0x16)
/*  f18b6e0:	3c0b800b */ 	lui	$t3,%hi(g_MpSimulants)
/*  f18b6e4:	00003025 */ 	or	$a2,$zero,$zero
/*  f18b6e8:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f18b6ec:	3508ffff */ 	ori	$t0,$t0,0xffff
/*  f18b6f0:	240affff */ 	addiu	$t2,$zero,-1
/*  f18b6f4:	256bc538 */ 	addiu	$t3,$t3,%lo(g_MpSimulants)
/*  f18b6f8:	94e7cb9e */ 	lhu	$a3,%lo(g_MpSetup+0x16)($a3)
/*  f18b6fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f18b700:	240c004c */ 	addiu	$t4,$zero,0x4c
/*  f18b704:	24180001 */ 	addiu	$t8,$zero,0x1
.L0f18b708:
/*  f18b708:	00b8c804 */ 	sllv	$t9,$t8,$a1
/*  f18b70c:	00f97824 */ 	and	$t7,$a3,$t9
/*  f18b710:	11e00024 */ 	beqz	$t7,.L0f18b7a4
/*  f18b714:	28a10004 */ 	slti	$at,$a1,0x4
/*  f18b718:	10200006 */ 	beqz	$at,.L0f18b734
/*  f18b71c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18b720:	00057080 */ 	sll	$t6,$a1,0x2
/*  f18b724:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f18b728:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18b72c:	10000005 */ 	b	.L0f18b744
/*  f18b730:	03ce2021 */ 	addu	$a0,$s8,$t6
.L0f18b734:
/*  f18b734:	00ac0019 */ 	multu	$a1,$t4
/*  f18b738:	00006812 */ 	mflo	$t5
/*  f18b73c:	016d2021 */ 	addu	$a0,$t3,$t5
/*  f18b740:	2484fed0 */ 	addiu	$a0,$a0,-304
.L0f18b744:
/*  f18b744:	00001825 */ 	or	$v1,$zero,$zero
.L0f18b748:
/*  f18b748:	12c30004 */ 	beq	$s6,$v1,.L0f18b75c
/*  f18b74c:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f18b750:	0098c821 */ 	addu	$t9,$a0,$t8
/*  f18b754:	872f0024 */ 	lh	$t7,0x24($t9)
/*  f18b758:	004f1021 */ 	addu	$v0,$v0,$t7
.L0f18b75c:
/*  f18b75c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18b760:	1477fff9 */ 	bne	$v1,$s7,.L0f18b748
/*  f18b764:	00000000 */ 	nop
/*  f18b768:	14460002 */ 	bne	$v0,$a2,.L0f18b774
/*  f18b76c:	00c2082a */ 	slt	$at,$a2,$v0
/*  f18b770:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f18b774:
/*  f18b774:	50200004 */ 	beqzl	$at,.L0f18b788
/*  f18b778:	8482003c */ 	lh	$v0,0x3c($a0)
/*  f18b77c:	00a04825 */ 	or	$t1,$a1,$zero
/*  f18b780:	00403025 */ 	or	$a2,$v0,$zero
/*  f18b784:	8482003c */ 	lh	$v0,0x3c($a0)
.L0f18b788:
/*  f18b788:	15020002 */ 	bne	$t0,$v0,.L0f18b794
/*  f18b78c:	0048082a */ 	slt	$at,$v0,$t0
/*  f18b790:	240affff */ 	addiu	$t2,$zero,-1
.L0f18b794:
/*  f18b794:	50200004 */ 	beqzl	$at,.L0f18b7a8
/*  f18b798:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f18b79c:	00a05025 */ 	or	$t2,$a1,$zero
/*  f18b7a0:	00404025 */ 	or	$t0,$v0,$zero
.L0f18b7a4:
/*  f18b7a4:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f18b7a8:
/*  f18b7a8:	54b7ffd7 */ 	bnel	$a1,$s7,.L0f18b708
/*  f18b7ac:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18b7b0:	3c0e800a */ 	lui	$t6,%hi(g_CheatsActiveBank0)
/*  f18b7b4:	8dce21d0 */ 	lw	$t6,%lo(g_CheatsActiveBank0)($t6)
/*  f18b7b8:	3c0d800a */ 	lui	$t5,%hi(g_CheatsActiveBank1)
/*  f18b7bc:	15c00038 */ 	bnez	$t6,.L0f18b8a0
/*  f18b7c0:	00000000 */ 	nop
/*  f18b7c4:	8dad21d4 */ 	lw	$t5,%lo(g_CheatsActiveBank1)($t5)
/*  f18b7c8:	29210004 */ 	slti	$at,$t1,0x4
/*  f18b7cc:	15a00034 */ 	bnez	$t5,.L0f18b8a0
/*  f18b7d0:	00000000 */ 	nop
/*  f18b7d4:	50200019 */ 	beqzl	$at,.L0f18b83c
/*  f18b7d8:	29410004 */ 	slti	$at,$t2,0x4
/*  f18b7dc:	05200016 */ 	bltz	$t1,.L0f18b838
/*  f18b7e0:	29210004 */ 	slti	$at,$t1,0x4
/*  f18b7e4:	10200006 */ 	beqz	$at,.L0f18b800
/*  f18b7e8:	0009c880 */ 	sll	$t9,$t1,0x2
/*  f18b7ec:	0009c080 */ 	sll	$t8,$t1,0x2
/*  f18b7f0:	0309c021 */ 	addu	$t8,$t8,$t1
/*  f18b7f4:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f18b7f8:	10000009 */ 	b	.L0f18b820
/*  f18b7fc:	03d81021 */ 	addu	$v0,$s8,$t8
.L0f18b800:
/*  f18b800:	0329c821 */ 	addu	$t9,$t9,$t1
/*  f18b804:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18b808:	0329c823 */ 	subu	$t9,$t9,$t1
/*  f18b80c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18b810:	3c0e800b */ 	lui	$t6,%hi(g_MpSimulants)
/*  f18b814:	25cec538 */ 	addiu	$t6,$t6,%lo(g_MpSimulants)
/*  f18b818:	272ffed0 */ 	addiu	$t7,$t9,-304
/*  f18b81c:	01ee1021 */ 	addu	$v0,$t7,$t6
.L0f18b820:
/*  f18b820:	904d0094 */ 	lbu	$t5,0x94($v0)
/*  f18b824:	8c59008c */ 	lw	$t9,0x8c($v0)
/*  f18b828:	35b80001 */ 	ori	$t8,$t5,0x1
/*  f18b82c:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f18b830:	a0580094 */ 	sb	$t8,0x94($v0)
/*  f18b834:	ac4f008c */ 	sw	$t7,0x8c($v0)
.L0f18b838:
/*  f18b838:	29410004 */ 	slti	$at,$t2,0x4
.L0f18b83c:
/*  f18b83c:	10200018 */ 	beqz	$at,.L0f18b8a0
/*  f18b840:	00000000 */ 	nop
/*  f18b844:	05400016 */ 	bltz	$t2,.L0f18b8a0
/*  f18b848:	29410004 */ 	slti	$at,$t2,0x4
/*  f18b84c:	10200006 */ 	beqz	$at,.L0f18b868
/*  f18b850:	000a6880 */ 	sll	$t5,$t2,0x2
/*  f18b854:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f18b858:	01ca7021 */ 	addu	$t6,$t6,$t2
/*  f18b85c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18b860:	10000009 */ 	b	.L0f18b888
/*  f18b864:	03ce1021 */ 	addu	$v0,$s8,$t6
.L0f18b868:
/*  f18b868:	01aa6821 */ 	addu	$t5,$t5,$t2
/*  f18b86c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b870:	01aa6823 */ 	subu	$t5,$t5,$t2
/*  f18b874:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18b878:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f18b87c:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f18b880:	25b8fed0 */ 	addiu	$t8,$t5,-304
/*  f18b884:	03191021 */ 	addu	$v0,$t8,$t9
.L0f18b888:
/*  f18b888:	904f0094 */ 	lbu	$t7,0x94($v0)
/*  f18b88c:	8c4d0090 */ 	lw	$t5,0x90($v0)
/*  f18b890:	35ee0008 */ 	ori	$t6,$t7,0x8
/*  f18b894:	25b80001 */ 	addiu	$t8,$t5,0x1
/*  f18b898:	a04e0094 */ 	sb	$t6,0x94($v0)
/*  f18b89c:	ac580090 */ 	sw	$t8,0x90($v0)
.L0f18b8a0:
/*  f18b8a0:	3c0f800a */ 	lui	$t7,%hi(g_CheatsActiveBank0)
/*  f18b8a4:	8def21d0 */ 	lw	$t7,%lo(g_CheatsActiveBank0)($t7)
/*  f18b8a8:	8fb902fc */ 	lw	$t9,0x2fc($sp)
/*  f18b8ac:	0000b025 */ 	or	$s6,$zero,$zero
/*  f18b8b0:	15e00035 */ 	bnez	$t7,.L0f18b988
/*  f18b8b4:	3c0e800a */ 	lui	$t6,%hi(g_CheatsActiveBank1)
/*  f18b8b8:	8dce21d4 */ 	lw	$t6,%lo(g_CheatsActiveBank1)($t6)
/*  f18b8bc:	2b210002 */ 	slti	$at,$t9,0x2
/*  f18b8c0:	55c00032 */ 	bnezl	$t6,.L0f18b98c
/*  f18b8c4:	8fa802fc */ 	lw	$t0,0x2fc($sp)
/*  f18b8c8:	1420002f */ 	bnez	$at,.L0f18b988
/*  f18b8cc:	00001825 */ 	or	$v1,$zero,$zero
/*  f18b8d0:	3c013f00 */ 	lui	$at,0x3f00
/*  f18b8d4:	44811000 */ 	mtc1	$at,$f2
/*  f18b8d8:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f18b8dc:	1b200016 */ 	blez	$t9,.L0f18b938
/*  f18b8e0:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f18b8e4:	27b301fc */ 	addiu	$s3,$sp,0x1fc
.L0f18b8e8:
/*  f18b8e8:	8e620004 */ 	lw	$v0,0x4($s3)
/*  f18b8ec:	8fad02fc */ 	lw	$t5,0x2fc($sp)
/*  f18b8f0:	14620002 */ 	bne	$v1,$v0,.L0f18b8fc
/*  f18b8f4:	0062082a */ 	slt	$at,$v1,$v0
/*  f18b8f8:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f18b8fc:
/*  f18b8fc:	50200004 */ 	beqzl	$at,.L0f18b910
/*  f18b900:	c6600038 */ 	lwc1	$f0,0x38($s3)
/*  f18b904:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18b908:	00401825 */ 	or	$v1,$v0,$zero
/*  f18b90c:	c6600038 */ 	lwc1	$f0,0x38($s3)
.L0f18b910:
/*  f18b910:	4600103c */ 	c.lt.s	$f2,$f0
/*  f18b914:	00000000 */ 	nop
/*  f18b918:	45020004 */ 	bc1fl	.L0f18b92c
/*  f18b91c:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18b920:	02c08025 */ 	or	$s0,$s6,$zero
/*  f18b924:	46000086 */ 	mov.s	$f2,$f0
/*  f18b928:	26d60001 */ 	addiu	$s6,$s6,0x1
.L0f18b92c:
/*  f18b92c:	16cdffee */ 	bne	$s6,$t5,.L0f18b8e8
/*  f18b930:	2673003c */ 	addiu	$s3,$s3,0x3c
/*  f18b934:	0000b025 */ 	or	$s6,$zero,$zero
.L0f18b938:
/*  f18b938:	04800009 */ 	bltz	$a0,.L0f18b960
/*  f18b93c:	00000000 */ 	nop
/*  f18b940:	0fc631e5 */ 	jal	func0f18c794
/*  f18b944:	00000000 */ 	nop
/*  f18b948:	90580094 */ 	lbu	$t8,0x94($v0)
/*  f18b94c:	8c4e0088 */ 	lw	$t6,0x88($v0)
/*  f18b950:	370f0002 */ 	ori	$t7,$t8,0x2
/*  f18b954:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f18b958:	a04f0094 */ 	sb	$t7,0x94($v0)
/*  f18b95c:	ac590088 */ 	sw	$t9,0x88($v0)
.L0f18b960:
/*  f18b960:	0602000a */ 	bltzl	$s0,.L0f18b98c
/*  f18b964:	8fa802fc */ 	lw	$t0,0x2fc($sp)
/*  f18b968:	0fc631e5 */ 	jal	func0f18c794
/*  f18b96c:	02002025 */ 	or	$a0,$s0,$zero
/*  f18b970:	904d0094 */ 	lbu	$t5,0x94($v0)
/*  f18b974:	8c4f0084 */ 	lw	$t7,0x84($v0)
/*  f18b978:	35b80004 */ 	ori	$t8,$t5,0x4
/*  f18b97c:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f18b980:	a0580094 */ 	sb	$t8,0x94($v0)
/*  f18b984:	ac4e0084 */ 	sw	$t6,0x84($v0)
.L0f18b988:
/*  f18b988:	8fa802fc */ 	lw	$t0,0x2fc($sp)
.L0f18b98c:
/*  f18b98c:	5900000a */ 	blezl	$t0,.L0f18b9b8
/*  f18b990:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f18b994:
/*  f18b994:	0fc631e5 */ 	jal	func0f18c794
/*  f18b998:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18b99c:	0fc62864 */ 	jal	mpCalculatePlayerTitle
/*  f18b9a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f18b9a4:	8fb902fc */ 	lw	$t9,0x2fc($sp)
/*  f18b9a8:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18b9ac:	16d9fff9 */ 	bne	$s6,$t9,.L0f18b994
/*  f18b9b0:	00000000 */ 	nop
/*  f18b9b4:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f18b9b8:
/*  f18b9b8:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f18b9bc:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f18b9c0:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f18b9c4:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f18b9c8:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f18b9cc:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f18b9d0:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f18b9d4:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f18b9d8:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f18b9dc:	03e00008 */ 	jr	$ra
/*  f18b9e0:	27bd0300 */ 	addiu	$sp,$sp,0x300
);

void mpEndMatch(void)
{
	s32 stack;
	s32 playercount = PLAYERCOUNT();
	s32 prevplayernum;
	s32 i;

	musicStartForMenu();
	mpSetPaused(MPPAUSEMODE_GAMEOVER);

	prevplayernum = g_Vars.currentplayernum;

	for (i = 0; i < playercount; i++) {
		setCurrentPlayerNum(i);

		g_Vars.currentplayer->award1 = NULL;
		g_Vars.currentplayer->award2 = NULL;

		if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKET) {
			g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
		}
	}

	setCurrentPlayerNum(prevplayernum);
	func0f18a56c();

	if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
		mpConsiderMarkingCurrentChallengeComplete();
	}

	func0f0f820c(NULL, -6);
}

s32 func0f18bb1c(void)
{
	return NUM_MPHEADS;
}

s32 mpGetNumHeads(void)
{
	return NUM_MPHEADS;
}

s32 mpGetHeadId(u8 headnum)
{
	return g_MpHeads[headnum].headnum;
}

s32 mpGetHeadRequiredFeature(u8 headnum)
{
	return g_MpHeads[headnum].requirefeature;
}

s32 mpGetBeauHeadId(u8 headnum)
{
	return g_MpBeauHeads[headnum].headnum;
}

s32 mpGetNumBeauHeads(void)
{
	return NUM_MPBEAUHEADS;
}

u32 mpGetNumBodies(void)
{
	return NUM_MPBODIES;
}

s32 mpGetBodyId(u8 bodynum)
{
	if (bodynum >= 62) {
		if (bodynum == 62) {
			return BODY_DRCAROLL;
		}

		return BODY_DARK_COMBAT;
	}

	return g_MpBodies[bodynum].bodynum;
}

s32 mpGetMpbodynumByBodynum(u16 bodynum)
{
	s32 i;

	if (bodynum == BODY_DRCAROLL) {
		return 62; // NUM_MPBODIES + 1
	}

	for (i = 0; i != NUM_MPBODIES; i++) {
		if (g_MpBodies[i].bodynum == bodynum) {
			return i;
		}
	}

	// @bug: Should return 0 as a fallback, not the first body's bodynum
	return g_MpBodies[0].bodynum;
}

char *mpGetBodyName(u8 mpbodynum)
{
	// Possible @bug: This should probably be >=
	if (mpbodynum > NUM_MPBODIES) {
		mpbodynum = 0;
	}

	return langGet(g_MpBodies[mpbodynum].name);
}

u8 mpGetBodyRequiredFeature(u8 bodynum)
{
	// Possible @bug: This should probably be >=
	if (bodynum > NUM_MPBODIES) {
		bodynum = 0;
	}

	return g_MpBodies[bodynum].requirefeature;
}

s32 mpGetMpheadnumByMpbodynum(s32 mpbodynum)
{
	s32 headnum;
	s32 index = 0;
	s32 i;

	if (mpbodynum >= HEAD_VD) {
		mpbodynum = 0;
	}

	headnum = g_MpBodies[mpbodynum].headnum;

	if (headnum == 1000) {
		if (g_Bodies[g_MpBodies[mpbodynum].bodynum].ismale) {
			headnum = g_MpMaleHeads[random() % ARRAYCOUNT(g_MpMaleHeads)];
		} else {
			headnum = g_MpFemaleHeads[random() % ARRAYCOUNT(g_MpFemaleHeads)];
		}
	}

	for (i = 0; i != ARRAYCOUNT(g_MpHeads); i++) {
		if (g_MpHeads[i].headnum == headnum) {
			index = i;
		}
	}

	return index;
}

GLOBAL_ASM(
glabel func0f18bd90
/*  f18bd90:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f18bd94:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f18bd98:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18bd9c:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f18bda0:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f18bda4:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f18bda8:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18bdac:	3c12800b */ 	lui	$s2,%hi(g_MpPlayers)
/*  f18bdb0:	3c15800b */ 	lui	$s5,%hi(g_MpSimulants)
/*  f18bdb4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f18bdb8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18bdbc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18bdc0:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f18bdc4:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f18bdc8:	26b5c538 */ 	addiu	$s5,$s5,%lo(g_MpSimulants)
/*  f18bdcc:	2652c7b8 */ 	addiu	$s2,$s2,%lo(g_MpPlayers)
/*  f18bdd0:	241300a0 */ 	addiu	$s3,$zero,0xa0
/*  f18bdd4:	2414000c */ 	addiu	$s4,$zero,0xc
/*  f18bdd8:	2416004c */ 	addiu	$s6,$zero,0x4c
/*  f18bddc:	2417004b */ 	addiu	$s7,$zero,0x4b
.L0f18bde0:
/*  f18bde0:	0c004b70 */ 	jal	random
/*  f18bde4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f18bde8:	0057001b */ 	divu	$zero,$v0,$s7
/*  f18bdec:	00008810 */ 	mfhi	$s1
/*  f18bdf0:	322e00ff */ 	andi	$t6,$s1,0xff
/*  f18bdf4:	16e00002 */ 	bnez	$s7,.L0f18be00
/*  f18bdf8:	00000000 */ 	nop
/*  f18bdfc:	0007000d */ 	break	0x7
.L0f18be00:
/*  f18be00:	01c08825 */ 	or	$s1,$t6,$zero
/*  f18be04:	0c004b70 */ 	jal	random
/*  f18be08:	00000000 */ 	nop
/*  f18be0c:	3c07800b */ 	lui	$a3,%hi(g_MpSetup+0x16)
/*  f18be10:	94e7cb9e */ 	lhu	$a3,%lo(g_MpSetup+0x16)($a3)
/*  f18be14:	00002025 */ 	or	$a0,$zero,$zero
/*  f18be18:	240f0001 */ 	addiu	$t7,$zero,0x1
.L0f18be1c:
/*  f18be1c:	008fc004 */ 	sllv	$t8,$t7,$a0
/*  f18be20:	00f8c824 */ 	and	$t9,$a3,$t8
/*  f18be24:	13200019 */ 	beqz	$t9,.L0f18be8c
/*  f18be28:	02202825 */ 	or	$a1,$s1,$zero
/*  f18be2c:	2401003d */ 	addiu	$at,$zero,0x3d
/*  f18be30:	0041001b */ 	divu	$zero,$v0,$at
/*  f18be34:	00003010 */ 	mfhi	$a2
/*  f18be38:	30c800ff */ 	andi	$t0,$a2,0xff
/*  f18be3c:	28810004 */ 	slti	$at,$a0,0x4
/*  f18be40:	10200006 */ 	beqz	$at,.L0f18be5c
/*  f18be44:	01003025 */ 	or	$a2,$t0,$zero
/*  f18be48:	00930019 */ 	multu	$a0,$s3
/*  f18be4c:	00004812 */ 	mflo	$t1
/*  f18be50:	02491821 */ 	addu	$v1,$s2,$t1
/*  f18be54:	10000006 */ 	b	.L0f18be70
/*  f18be58:	906b000f */ 	lbu	$t3,0xf($v1)
.L0f18be5c:
/*  f18be5c:	00960019 */ 	multu	$a0,$s6
/*  f18be60:	00005012 */ 	mflo	$t2
/*  f18be64:	02aa1821 */ 	addu	$v1,$s5,$t2
/*  f18be68:	2463fed0 */ 	addiu	$v1,$v1,-304
/*  f18be6c:	906b000f */ 	lbu	$t3,0xf($v1)
.L0f18be70:
/*  f18be70:	54ab0003 */ 	bnel	$a1,$t3,.L0f18be80
/*  f18be74:	906c0010 */ 	lbu	$t4,0x10($v1)
/*  f18be78:	00008025 */ 	or	$s0,$zero,$zero
/*  f18be7c:	906c0010 */ 	lbu	$t4,0x10($v1)
.L0f18be80:
/*  f18be80:	54cc0003 */ 	bnel	$a2,$t4,.L0f18be90
/*  f18be84:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18be88:	00008025 */ 	or	$s0,$zero,$zero
.L0f18be8c:
/*  f18be8c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f18be90:
/*  f18be90:	5494ffe2 */ 	bnel	$a0,$s4,.L0f18be1c
/*  f18be94:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18be98:	1200ffd1 */ 	beqz	$s0,.L0f18bde0
/*  f18be9c:	00000000 */ 	nop
/*  f18bea0:	2401003d */ 	addiu	$at,$zero,0x3d
/*  f18bea4:	0041001b */ 	divu	$zero,$v0,$at
/*  f18bea8:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f18beac:	00006810 */ 	mfhi	$t5
/*  f18beb0:	a1d10000 */ 	sb	$s1,0x0($t6)
/*  f18beb4:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f18beb8:	a1ed0000 */ 	sb	$t5,0x0($t7)
/*  f18bebc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18bec0:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f18bec4:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f18bec8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f18becc:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f18bed0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18bed4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18bed8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18bedc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18bee0:	03e00008 */ 	jr	$ra
/*  f18bee4:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel mpChooseRandomLockPlayer
/*  f18bee8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18beec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18bef0:	0c004b70 */ 	jal	random
/*  f18bef4:	00000000 */ 	nop
/*  f18bef8:	30440003 */ 	andi	$a0,$v0,0x3
/*  f18befc:	24830001 */ 	addiu	$v1,$a0,0x1
/*  f18bf00:	04610004 */ 	bgez	$v1,.L0f18bf14
/*  f18bf04:	306e0003 */ 	andi	$t6,$v1,0x3
/*  f18bf08:	11c00002 */ 	beqz	$t6,.L0f18bf14
/*  f18bf0c:	00000000 */ 	nop
/*  f18bf10:	25cefffc */ 	addiu	$t6,$t6,-4
.L0f18bf14:
/*  f18bf14:	3c05800b */ 	lui	$a1,%hi(g_MpSetup+0x16)
/*  f18bf18:	94a5cb9e */ 	lhu	$a1,%lo(g_MpSetup+0x16)($a1)
/*  f18bf1c:	01c01825 */ 	or	$v1,$t6,$zero
/*  f18bf20:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18bf24:	006fc004 */ 	sllv	$t8,$t7,$v1
/*  f18bf28:	00b8c824 */ 	and	$t9,$a1,$t8
/*  f18bf2c:	1720000d */ 	bnez	$t9,.L0f18bf64
/*  f18bf30:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f18bf34:
/*  f18bf34:	1064000b */ 	beq	$v1,$a0,.L0f18bf64
/*  f18bf38:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18bf3c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18bf40:	04610004 */ 	bgez	$v1,.L0f18bf54
/*  f18bf44:	30680003 */ 	andi	$t0,$v1,0x3
/*  f18bf48:	11000002 */ 	beqz	$t0,.L0f18bf54
/*  f18bf4c:	00000000 */ 	nop
/*  f18bf50:	2508fffc */ 	addiu	$t0,$t0,-4
.L0f18bf54:
/*  f18bf54:	010fc004 */ 	sllv	$t8,$t7,$t0
/*  f18bf58:	00b8c824 */ 	and	$t9,$a1,$t8
/*  f18bf5c:	1320fff5 */ 	beqz	$t9,.L0f18bf34
/*  f18bf60:	01001825 */ 	or	$v1,$t0,$zero
.L0f18bf64:
/*  f18bf64:	00601025 */ 	or	$v0,$v1,$zero
/*  f18bf68:	03e00008 */ 	jr	$ra
/*  f18bf6c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

bool mpSetLock(s32 locktype, s32 playernum)
{
	g_MpSetupSaveFile.locktype = locktype;

	if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_RANDOM) {
		g_MpLockInfo.lockedplayernum = mpChooseRandomLockPlayer();
	} else {
		g_MpLockInfo.lockedplayernum = playernum;
	}

	return true;
}

s32 mpGetLockType(void)
{
	return g_MpSetupSaveFile.locktype;
}

u32 mpGetLockPlayerNum(void)
{
	return g_MpLockInfo.lockedplayernum;
}

bool mpIsPlayerLockedOut(u32 playernum)
{
	if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_NONE) {
		return false;
	}

	if (g_MpLockInfo.lockedplayernum == playernum) {
		return false;
	}

	return true;
}

void mpCalculateLockIfLastWinnerOrLoser(void)
{
	if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_LASTWINNER && g_MpLockInfo.lastwinner >= 0) {
		g_MpLockInfo.lockedplayernum = g_MpLockInfo.lastwinner;
	}

	if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_LASTLOSER && g_MpLockInfo.lastloser >= 0) {
		g_MpLockInfo.lockedplayernum = g_MpLockInfo.lastloser;
	}

	if (g_MpLockInfo.lockedplayernum >= 0
			&& g_MpSetupSaveFile.locktype != MPLOCKTYPE_CHALLENGE
			&& (g_MpSetup.chrslots & (1 << g_MpLockInfo.lockedplayernum)) == 0) {
		g_MpLockInfo.lastwinner = g_MpLockInfo.lastloser = -1;
		g_MpLockInfo.lockedplayernum = mpChooseRandomLockPlayer();
	}
}

struct mptrack g_MpTracks[NUM_MPTRACKS] = {
	// Audio ID, duration, name, unlock after stage
	/*0x00*/ { MUSIC_DARK_COMBAT,     160, L_MISC(124), -1 }, // "Dark Combat"
	/*0x01*/ { MUSIC_SKEDAR_MYSTERY,  170, L_MISC(125), -1 }, // "Skedar Mystery"
	/*0x02*/ { MUSIC_CI_OPERATIVE,    170, L_MISC(126), -1 }, // "CI Operative"
	/*0x03*/ { MUSIC_DATADYNE_ACTION, 180, L_MISC(127), -1 }, // "dataDyne Action"
	/*0x04*/ { MUSIC_MAIAN_TEARS,     200, L_MISC(128), -1 }, // "Maian Tears"
	/*0x05*/ { MUSIC_ALIEN_CONFLICT,  197, L_MISC(129), -1 }, // "Alien Conflict"
	/*0x06*/ { MUSIC_CI,              120, L_MISC(130), -1 }, // "Carrington Institute"
	/*0x07*/ { MUSIC_DEFECTION,       120, L_MISC(131), SOLOSTAGEINDEX_DEFECTION }, // "dD Central"
	/*0x08*/ { MUSIC_DEFECTION_X,     120, L_MISC(132), SOLOSTAGEINDEX_DEFECTION }, // "dD Central X"
	/*0x09*/ { MUSIC_INVESTIGATION,   120, L_MISC(133), SOLOSTAGEINDEX_INVESTIGATION }, // "dD Research"
	/*0x0a*/ { MUSIC_INVESTIGATION_X, 120, L_MISC(134), SOLOSTAGEINDEX_INVESTIGATION }, // "dD Research X"
	/*0x0b*/ { MUSIC_EXTRACTION,      120, L_MISC(135), SOLOSTAGEINDEX_EXTRACTION }, // "dD Extraction"
	/*0x0c*/ { MUSIC_EXTRACTION_X,    120, L_MISC(136), SOLOSTAGEINDEX_EXTRACTION }, // "dD Extraction X"
	/*0x0d*/ { MUSIC_VILLA,           120, L_MISC(137), SOLOSTAGEINDEX_VILLA }, // "Carrington Villa"
	/*0x0e*/ { MUSIC_VILLA_X,         120, L_MISC(138), SOLOSTAGEINDEX_VILLA }, // "Carrington Villa X"
	/*0x0f*/ { MUSIC_CHICAGO,         120, L_MISC(139), SOLOSTAGEINDEX_CHICAGO }, // "Chicago"
	/*0x10*/ { MUSIC_CHICAGO_X,       120, L_MISC(140), SOLOSTAGEINDEX_CHICAGO }, // "Chicago X"
	/*0x11*/ { MUSIC_G5,              120, L_MISC(141), SOLOSTAGEINDEX_G5BUILDING }, // "G5 Building"
	/*0x12*/ { MUSIC_G5_X,            120, L_MISC(142), SOLOSTAGEINDEX_G5BUILDING }, // "G5 Building X"
	/*0x13*/ { MUSIC_INFILTRATION,    120, L_MISC(143), SOLOSTAGEINDEX_INFILTRATION }, // "A51 Infiltration"
	/*0x14*/ { MUSIC_INFILTRATION_X,  120, L_MISC(144), SOLOSTAGEINDEX_INFILTRATION }, // "A51 Infiltration X"
	/*0x15*/ { MUSIC_RESCUE,          120, L_MISC(145), SOLOSTAGEINDEX_RESCUE }, // "A51 Rescue"
	/*0x16*/ { MUSIC_RESCUE_X,        120, L_MISC(146), SOLOSTAGEINDEX_RESCUE }, // "A51 Rescue X"
	/*0x17*/ { MUSIC_ESCAPE,          120, L_MISC(147), SOLOSTAGEINDEX_ESCAPE }, // "A51 Escape"
	/*0x18*/ { MUSIC_ESCAPE_X,        120, L_MISC(148), SOLOSTAGEINDEX_ESCAPE }, // "A51 Escape X"
	/*0x19*/ { MUSIC_AIRBASE,         120, L_MISC(149), SOLOSTAGEINDEX_AIRBASE }, // "Air Base"
	/*0x1a*/ { MUSIC_AIRBASE_X,       120, L_MISC(150), SOLOSTAGEINDEX_AIRBASE }, // "Air Base X"
	/*0x1b*/ { MUSIC_AIRFORCEONE,     120, L_MISC(151), SOLOSTAGEINDEX_AIRFORCEONE }, // "Air Force One"
	/*0x1c*/ { MUSIC_AIRFORCEONE_X,   120, L_MISC(152), SOLOSTAGEINDEX_AIRFORCEONE }, // "Air Force One X"
	/*0x1d*/ { MUSIC_CRASHSITE,       120, L_MISC(153), SOLOSTAGEINDEX_CRASHSITE }, // "Crash Site"
	/*0x1e*/ { MUSIC_CRASHSITE_X,     120, L_MISC(154), SOLOSTAGEINDEX_CRASHSITE }, // "Crash Site X"
	/*0x1f*/ { MUSIC_PELAGIC,         120, L_MISC(155), SOLOSTAGEINDEX_PELAGIC }, // "Pelagic II"
	/*0x20*/ { MUSIC_PELAGIC_X,       120, L_MISC(156), SOLOSTAGEINDEX_PELAGIC }, // "Pelagic II X"
	/*0x21*/ { MUSIC_DEEPSEA,         120, L_MISC(157), SOLOSTAGEINDEX_DEEPSEA }, // "Deep Sea"
	/*0x22*/ { MUSIC_DEEPSEA_X,       120, L_MISC(158), SOLOSTAGEINDEX_DEEPSEA }, // "Deep Sea X"
	/*0x23*/ { MUSIC_DEFENSE,         120, L_MISC(159), SOLOSTAGEINDEX_DEFENSE }, // "Institute Defense"
	/*0x24*/ { MUSIC_DEFENSE_X,       120, L_MISC(160), SOLOSTAGEINDEX_DEFENSE }, // "Institute Defense X"
	/*0x25*/ { MUSIC_ATTACKSHIP,      120, L_MISC(161), SOLOSTAGEINDEX_ATTACKSHIP }, // "Attack Ship"
	/*0x26*/ { MUSIC_ATTACKSHIP_X,    120, L_MISC(162), SOLOSTAGEINDEX_ATTACKSHIP }, // "Attack Ship X"
	/*0x27*/ { MUSIC_SKEDARRUINS,     120, L_MISC(163), SOLOSTAGEINDEX_SKEDARRUINS }, // "Skedar Ruins"
	/*0x28*/ { MUSIC_SKEDARRUINS_X,   120, L_MISC(164), SOLOSTAGEINDEX_SKEDARRUINS }, // "Skedar Ruins X"
	/*0x29*/ { MUSIC_CREDITS,         120, L_MISC(165), SOLOSTAGEINDEX_SKEDARRUINS }, // "End Credits"
};

bool mpIsTrackUnlocked(s32 tracknum)
{
	s16 stageindex = g_MpTracks[tracknum].unlockstage;
	bool unlocked = false;
	u32 i;

	if (stageindex < 0 || stageindex >= NUM_SOLONORMALSTAGES) {
		unlocked = true;
	} else {
		for (i = 0; i != 3; i++) {
			if (g_SoloSaveFile.besttimes[stageindex][i]) {
				unlocked = true;
				break;
			}
		}
	}

	return unlocked;
}

s32 mpGetTrackSlotIndex(s32 tracknum)
{
	s32 i;
	s32 slotindex = 0;

	for (i = 0; i < tracknum; i++) {
		if (mpIsTrackUnlocked(i)) {
			slotindex++;
		}
	}

	return slotindex;
}

s32 mpGetTrackNumAtSlotIndex(s32 slotindex)
{
	s32 i;
	s32 numunlocked = 0;

	for (i = 0; i != NUM_MPTRACKS; i++) {
		if (mpIsTrackUnlocked(i)) {
			if (numunlocked == slotindex) {
				break;
			}

			numunlocked++;
		}
	}

	return i;
}

s32 mpGetNumUnlockedTracks(void)
{
	return mpGetTrackSlotIndex(NUM_MPTRACKS);
}

s32 mpGetTrackMusicNum(s32 slotindex)
{
	s32 tracknum = mpGetTrackNumAtSlotIndex(slotindex);

	return g_MpTracks[tracknum].musicnum;
}

char *mpGetTrackName(s32 slotindex)
{
	s32 tracknum = mpGetTrackNumAtSlotIndex(slotindex);

	return langGet(g_MpTracks[tracknum].name);
}

void mpSetUsingMultipleTunes(bool enable)
{
	g_MpSetupSaveFile.usingmultipletunes = enable;
}

bool mpGetUsingMultipleTunes(void)
{
	return g_MpSetupSaveFile.usingmultipletunes;
}

bool mpIsMultiTrackSlotEnabled(s32 slot)
{
	s32 tracknum = mpGetTrackNumAtSlotIndex(slot);
	u8 index = tracknum >> 3;
	u8 value = 1 << (tracknum & 7);

	if ((g_MpSetupSaveFile.multipletracknums[index] & value) == 0) {
		return false;
	}

	return true;
}

void mpSetMultiTrackSlotEnabled(s32 slot, bool enable)
{
	s32 tracknum = mpGetTrackNumAtSlotIndex(slot);
	u8 value = 1 << (tracknum & 7);
	u8 index = tracknum >> 3;

	if (enable) {
		g_MpSetupSaveFile.multipletracknums[index] |= value;
	} else {
		g_MpSetupSaveFile.multipletracknums[index] &= ~value;
	}
}

void mpSetTrackSlotEnabled(s32 slot)
{
	if (mpGetUsingMultipleTunes()) {
		mpSetMultiTrackSlotEnabled(slot, 1 - mpIsMultiTrackSlotEnabled(slot));
	} else {
		g_MpSetupSaveFile.tracknum = mpGetTrackNumAtSlotIndex(slot);
	}
}

void mpEnableAllMultiTracks(void)
{
	s32 i;

	for (i = 0; i != 6; i++) {
		g_MpSetupSaveFile.multipletracknums[i] = 0xff;
	}
}

void mpDisableAllMultiTracks(void)
{
	s32 i;

	for (i = 0; i != 6; i++) {
		g_MpSetupSaveFile.multipletracknums[i] = 0;
	}
}

void mpRandomiseMultiTracks(void)
{
	s32 i;

	for (i = 0; i != 6; i++) {
		g_MpSetupSaveFile.multipletracknums[i] = random();
	}
}

void mpSetTrackToRandom(void)
{
	g_MpSetupSaveFile.tracknum = -1;
}

s32 mpGetCurrentTrackSlotNum(void)
{
	if (g_MpSetupSaveFile.tracknum < 0) {
		return g_MpSetupSaveFile.tracknum;
	}

	return mpGetTrackSlotIndex(g_MpSetupSaveFile.tracknum);
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f18c4c0
/*  f18d564:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f18d568:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f18d56c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18d570:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18d574:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18d578:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18d57c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18d580:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18d584:	0fc634d2 */ 	jal	0xf18d348
/*  f18d588:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18d58c:	1040006f */ 	beqz	$v0,.PF0f18d74c
/*  f18d590:	00000000 */ 	nop
/*  f18d594:	0fc634a9 */ 	jal	0xf18d2a4
/*  f18d598:	00000000 */ 	nop
/*  f18d59c:	0040a025 */ 	move	$s4,$v0
/*  f18d5a0:	0000a825 */ 	move	$s5,$zero
/*  f18d5a4:	18400009 */ 	blez	$v0,.PF0f18d5cc
/*  f18d5a8:	00008025 */ 	move	$s0,$zero
.PF0f18d5ac:
/*  f18d5ac:	0fc634d5 */ 	jal	0xf18d354
/*  f18d5b0:	02002025 */ 	move	$a0,$s0
/*  f18d5b4:	10400002 */ 	beqz	$v0,.PF0f18d5c0
/*  f18d5b8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18d5bc:	26b50001 */ 	addiu	$s5,$s5,0x1
.PF0f18d5c0:
/*  f18d5c0:	0214082a */ 	slt	$at,$s0,$s4
/*  f18d5c4:	1420fff9 */ 	bnez	$at,.PF0f18d5ac
/*  f18d5c8:	00000000 */ 	nop
.PF0f18d5cc:
/*  f18d5cc:	16a00020 */ 	bnez	$s5,.PF0f18d650
/*  f18d5d0:	3c16800b */ 	lui	$s6,0x800b
/*  f18d5d4:	26d6d1c0 */ 	addiu	$s6,$s6,-11840
.PF0f18d5d8:
/*  f18d5d8:	0c004ad4 */ 	jal	0x12b50
/*  f18d5dc:	00000000 */ 	nop
/*  f18d5e0:	0054001b */ 	divu	$zero,$v0,$s4
/*  f18d5e4:	00002010 */ 	mfhi	$a0
/*  f18d5e8:	16800002 */ 	bnez	$s4,.PF0f18d5f4
/*  f18d5ec:	00000000 */ 	nop
/*  f18d5f0:	0007000d */ 	break	0x7
.PF0f18d5f4:
/*  f18d5f4:	0fc6348e */ 	jal	0xf18d238
/*  f18d5f8:	00000000 */ 	nop
/*  f18d5fc:	8ece0004 */ 	lw	$t6,0x4($s6)
/*  f18d600:	00409825 */ 	move	$s3,$v0
/*  f18d604:	104efff4 */ 	beq	$v0,$t6,.PF0f18d5d8
/*  f18d608:	00000000 */ 	nop
/*  f18d60c:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18d610:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18d614:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f18d618:	3c038008 */ 	lui	$v1,0x8008
/*  f18d61c:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18d620:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f18d624:	94637fc0 */ 	lhu	$v1,0x7fc0($v1)
/*  f18d628:	3c018008 */ 	lui	$at,0x8008
/*  f18d62c:	307801ff */ 	andi	$t8,$v1,0x1ff
/*  f18d630:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f18d634:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f18d638:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f18d63c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f18d640:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f18d644:	ac394638 */ 	sw	$t9,0x4638($at)
/*  f18d648:	1000007b */ 	b	.PF0f18d838
/*  f18d64c:	00031242 */ 	srl	$v0,$v1,0x9
.PF0f18d650:
/*  f18d650:	3c16800b */ 	lui	$s6,0x800b
/*  f18d654:	26d6d1c0 */ 	addiu	$s6,$s6,-11840
/*  f18d658:	00008025 */ 	move	$s0,$zero
.PF0f18d65c:
/*  f18d65c:	0c004ad4 */ 	jal	0x12b50
/*  f18d660:	00008825 */ 	move	$s1,$zero
/*  f18d664:	0055001b */ 	divu	$zero,$v0,$s5
/*  f18d668:	00009010 */ 	mfhi	$s2
/*  f18d66c:	2413ffff */ 	li	$s3,-1
/*  f18d670:	16a00002 */ 	bnez	$s5,.PF0f18d67c
/*  f18d674:	00000000 */ 	nop
/*  f18d678:	0007000d */ 	break	0x7
.PF0f18d67c:
/*  f18d67c:	5a80000d */ 	blezl	$s4,.PF0f18d6b4
/*  f18d680:	2401ffff */ 	li	$at,-1
.PF0f18d684:
/*  f18d684:	0fc634d5 */ 	jal	0xf18d354
/*  f18d688:	02002025 */ 	move	$a0,$s0
/*  f18d68c:	50400006 */ 	beqzl	$v0,.PF0f18d6a8
/*  f18d690:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18d694:	56510003 */ 	bnel	$s2,$s1,.PF0f18d6a4
/*  f18d698:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18d69c:	02009825 */ 	move	$s3,$s0
/*  f18d6a0:	26310001 */ 	addiu	$s1,$s1,0x1
.PF0f18d6a4:
/*  f18d6a4:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f18d6a8:
/*  f18d6a8:	1614fff6 */ 	bne	$s0,$s4,.PF0f18d684
/*  f18d6ac:	00000000 */ 	nop
/*  f18d6b0:	2401ffff */ 	li	$at,-1
.PF0f18d6b4:
/*  f18d6b4:	1661000c */ 	bne	$s3,$at,.PF0f18d6e8
/*  f18d6b8:	3c038008 */ 	lui	$v1,0x8008
/*  f18d6bc:	94637fc0 */ 	lhu	$v1,0x7fc0($v1)
/*  f18d6c0:	3c018008 */ 	lui	$at,0x8008
/*  f18d6c4:	306801ff */ 	andi	$t0,$v1,0x1ff
/*  f18d6c8:	00084880 */ 	sll	$t1,$t0,0x2
/*  f18d6cc:	01284823 */ 	subu	$t1,$t1,$t0
/*  f18d6d0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f18d6d4:	01284821 */ 	addu	$t1,$t1,$t0
/*  f18d6d8:	00094840 */ 	sll	$t1,$t1,0x1
/*  f18d6dc:	ac294638 */ 	sw	$t1,0x4638($at)
/*  f18d6e0:	10000055 */ 	b	.PF0f18d838
/*  f18d6e4:	00031242 */ 	srl	$v0,$v1,0x9
.PF0f18d6e8:
/*  f18d6e8:	0fc6348e */ 	jal	0xf18d238
/*  f18d6ec:	02602025 */ 	move	$a0,$s3
/*  f18d6f0:	2aa10002 */ 	slti	$at,$s5,0x2
/*  f18d6f4:	14200004 */ 	bnez	$at,.PF0f18d708
/*  f18d6f8:	00409825 */ 	move	$s3,$v0
/*  f18d6fc:	8eca0004 */ 	lw	$t2,0x4($s6)
/*  f18d700:	504affd6 */ 	beql	$v0,$t2,.PF0f18d65c
/*  f18d704:	00008025 */ 	move	$s0,$zero
.PF0f18d708:
/*  f18d708:	00135880 */ 	sll	$t3,$s3,0x2
/*  f18d70c:	01735823 */ 	subu	$t3,$t3,$s3
/*  f18d710:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f18d714:	3c038008 */ 	lui	$v1,0x8008
/*  f18d718:	aed30004 */ 	sw	$s3,0x4($s6)
/*  f18d71c:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f18d720:	94637fc0 */ 	lhu	$v1,0x7fc0($v1)
/*  f18d724:	3c018008 */ 	lui	$at,0x8008
/*  f18d728:	306c01ff */ 	andi	$t4,$v1,0x1ff
/*  f18d72c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f18d730:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f18d734:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f18d738:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f18d73c:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f18d740:	ac2d4638 */ 	sw	$t5,0x4638($at)
/*  f18d744:	1000003c */ 	b	.PF0f18d838
/*  f18d748:	00031242 */ 	srl	$v0,$v1,0x9
.PF0f18d74c:
/*  f18d74c:	0fc6354b */ 	jal	0xf18d52c
/*  f18d750:	00000000 */ 	nop
/*  f18d754:	04410024 */ 	bgez	$v0,.PF0f18d7e8
/*  f18d758:	00409825 */ 	move	$s3,$v0
/*  f18d75c:	0fc634a9 */ 	jal	0xf18d2a4
/*  f18d760:	00000000 */ 	nop
/*  f18d764:	3c16800b */ 	lui	$s6,0x800b
/*  f18d768:	00408025 */ 	move	$s0,$v0
/*  f18d76c:	26d6d1c0 */ 	addiu	$s6,$s6,-11840
.PF0f18d770:
/*  f18d770:	0c004ad4 */ 	jal	0x12b50
/*  f18d774:	00000000 */ 	nop
/*  f18d778:	0050001b */ 	divu	$zero,$v0,$s0
/*  f18d77c:	00002010 */ 	mfhi	$a0
/*  f18d780:	16000002 */ 	bnez	$s0,.PF0f18d78c
/*  f18d784:	00000000 */ 	nop
/*  f18d788:	0007000d */ 	break	0x7
.PF0f18d78c:
/*  f18d78c:	0fc6348e */ 	jal	0xf18d238
/*  f18d790:	00000000 */ 	nop
/*  f18d794:	8ece0004 */ 	lw	$t6,0x4($s6)
/*  f18d798:	00409825 */ 	move	$s3,$v0
/*  f18d79c:	104efff4 */ 	beq	$v0,$t6,.PF0f18d770
/*  f18d7a0:	00000000 */ 	nop
/*  f18d7a4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18d7a8:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18d7ac:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f18d7b0:	3c038008 */ 	lui	$v1,0x8008
/*  f18d7b4:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18d7b8:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f18d7bc:	94637fc0 */ 	lhu	$v1,0x7fc0($v1)
/*  f18d7c0:	3c018008 */ 	lui	$at,0x8008
/*  f18d7c4:	307801ff */ 	andi	$t8,$v1,0x1ff
/*  f18d7c8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f18d7cc:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f18d7d0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f18d7d4:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f18d7d8:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f18d7dc:	ac394638 */ 	sw	$t9,0x4638($at)
/*  f18d7e0:	10000015 */ 	b	.PF0f18d838
/*  f18d7e4:	00031242 */ 	srl	$v0,$v1,0x9
.PF0f18d7e8:
/*  f18d7e8:	0fc6348e */ 	jal	0xf18d238
/*  f18d7ec:	02602025 */ 	move	$a0,$s3
/*  f18d7f0:	00024080 */ 	sll	$t0,$v0,0x2
/*  f18d7f4:	3c16800b */ 	lui	$s6,0x800b
/*  f18d7f8:	01024023 */ 	subu	$t0,$t0,$v0
/*  f18d7fc:	26d6d1c0 */ 	addiu	$s6,$s6,-11840
/*  f18d800:	00084040 */ 	sll	$t0,$t0,0x1
/*  f18d804:	3c038008 */ 	lui	$v1,0x8008
/*  f18d808:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18d80c:	00681821 */ 	addu	$v1,$v1,$t0
/*  f18d810:	94637fc0 */ 	lhu	$v1,0x7fc0($v1)
/*  f18d814:	3c018008 */ 	lui	$at,0x8008
/*  f18d818:	306901ff */ 	andi	$t1,$v1,0x1ff
/*  f18d81c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f18d820:	01495023 */ 	subu	$t2,$t2,$t1
/*  f18d824:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f18d828:	01495021 */ 	addu	$t2,$t2,$t1
/*  f18d82c:	000a5040 */ 	sll	$t2,$t2,0x1
/*  f18d830:	ac2a4638 */ 	sw	$t2,0x4638($at)
/*  f18d834:	00031242 */ 	srl	$v0,$v1,0x9
.PF0f18d838:
/*  f18d838:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18d83c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18d840:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18d844:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18d848:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18d84c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18d850:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18d854:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18d858:	03e00008 */ 	jr	$ra
/*  f18d85c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#else
GLOBAL_ASM(
glabel func0f18c4c0
/*  f18c4c0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f18c4c4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f18c4c8:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18c4cc:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18c4d0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18c4d4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18c4d8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18c4dc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18c4e0:	0fc630a9 */ 	jal	mpGetUsingMultipleTunes
/*  f18c4e4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18c4e8:	10400069 */ 	beqz	$v0,.L0f18c690
/*  f18c4ec:	00000000 */ 	nop
/*  f18c4f0:	0fc63080 */ 	jal	mpGetNumUnlockedTracks
/*  f18c4f4:	00000000 */ 	nop
/*  f18c4f8:	0040a025 */ 	or	$s4,$v0,$zero
/*  f18c4fc:	0000a825 */ 	or	$s5,$zero,$zero
/*  f18c500:	18400009 */ 	blez	$v0,.L0f18c528
/*  f18c504:	00008025 */ 	or	$s0,$zero,$zero
.L0f18c508:
/*  f18c508:	0fc630ac */ 	jal	mpIsMultiTrackSlotEnabled
/*  f18c50c:	02002025 */ 	or	$a0,$s0,$zero
/*  f18c510:	10400002 */ 	beqz	$v0,.L0f18c51c
/*  f18c514:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18c518:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f18c51c:
/*  f18c51c:	0214082a */ 	slt	$at,$s0,$s4
/*  f18c520:	1420fff9 */ 	bnez	$at,.L0f18c508
/*  f18c524:	00000000 */ 	nop
.L0f18c528:
/*  f18c528:	16a0001e */ 	bnez	$s5,.L0f18c5a4
/*  f18c52c:	3c16800b */ 	lui	$s6,%hi(g_MpLockInfo)
/*  f18c530:	26d6cc20 */ 	addiu	$s6,$s6,%lo(g_MpLockInfo)
.L0f18c534:
/*  f18c534:	0c004b70 */ 	jal	random
/*  f18c538:	00000000 */ 	nop
/*  f18c53c:	0054001b */ 	divu	$zero,$v0,$s4
/*  f18c540:	00002010 */ 	mfhi	$a0
/*  f18c544:	16800002 */ 	bnez	$s4,.L0f18c550
/*  f18c548:	00000000 */ 	nop
/*  f18c54c:	0007000d */ 	break	0x7
.L0f18c550:
/*  f18c550:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c554:	00000000 */ 	nop
/*  f18c558:	8ece0004 */ 	lw	$t6,0x4($s6)
/*  f18c55c:	00409825 */ 	or	$s3,$v0,$zero
/*  f18c560:	104efff4 */ 	beq	$v0,$t6,.L0f18c534
/*  f18c564:	00000000 */ 	nop
/*  f18c568:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18c56c:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18c570:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f18c574:	3c038008 */ 	lui	$v1,%hi(g_MpTracks)
/*  f18c578:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18c57c:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f18c580:	94637a70 */ 	lhu	$v1,%lo(g_MpTracks)($v1)
/*  f18c584:	3c018008 */ 	lui	$at,%hi(var800840f8)
/*  f18c588:	307801ff */ 	andi	$t8,$v1,0x1ff
/*  f18c58c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f18c590:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f18c594:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18c598:	ac3940f8 */ 	sw	$t9,%lo(var800840f8)($at)
/*  f18c59c:	10000073 */ 	b	.L0f18c76c
/*  f18c5a0:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c5a4:
/*  f18c5a4:	3c16800b */ 	lui	$s6,%hi(g_MpLockInfo)
/*  f18c5a8:	26d6cc20 */ 	addiu	$s6,$s6,%lo(g_MpLockInfo)
/*  f18c5ac:	00008025 */ 	or	$s0,$zero,$zero
.L0f18c5b0:
/*  f18c5b0:	0c004b70 */ 	jal	random
/*  f18c5b4:	00008825 */ 	or	$s1,$zero,$zero
/*  f18c5b8:	0055001b */ 	divu	$zero,$v0,$s5
/*  f18c5bc:	00009010 */ 	mfhi	$s2
/*  f18c5c0:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f18c5c4:	16a00002 */ 	bnez	$s5,.L0f18c5d0
/*  f18c5c8:	00000000 */ 	nop
/*  f18c5cc:	0007000d */ 	break	0x7
.L0f18c5d0:
/*  f18c5d0:	5a80000d */ 	blezl	$s4,.L0f18c608
/*  f18c5d4:	2401ffff */ 	addiu	$at,$zero,-1
.L0f18c5d8:
/*  f18c5d8:	0fc630ac */ 	jal	mpIsMultiTrackSlotEnabled
/*  f18c5dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f18c5e0:	50400006 */ 	beqzl	$v0,.L0f18c5fc
/*  f18c5e4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18c5e8:	56510003 */ 	bnel	$s2,$s1,.L0f18c5f8
/*  f18c5ec:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18c5f0:	02009825 */ 	or	$s3,$s0,$zero
/*  f18c5f4:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18c5f8:
/*  f18c5f8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18c5fc:
/*  f18c5fc:	1614fff6 */ 	bne	$s0,$s4,.L0f18c5d8
/*  f18c600:	00000000 */ 	nop
/*  f18c604:	2401ffff */ 	addiu	$at,$zero,-1
.L0f18c608:
/*  f18c608:	1661000a */ 	bne	$s3,$at,.L0f18c634
/*  f18c60c:	3c038008 */ 	lui	$v1,%hi(g_MpTracks)
/*  f18c610:	94637a70 */ 	lhu	$v1,%lo(g_MpTracks)($v1)
/*  f18c614:	3c018008 */ 	lui	$at,%hi(var800840f8)
/*  f18c618:	306801ff */ 	andi	$t0,$v1,0x1ff
/*  f18c61c:	00084900 */ 	sll	$t1,$t0,0x4
/*  f18c620:	01284823 */ 	subu	$t1,$t1,$t0
/*  f18c624:	00094880 */ 	sll	$t1,$t1,0x2
/*  f18c628:	ac2940f8 */ 	sw	$t1,%lo(var800840f8)($at)
/*  f18c62c:	1000004f */ 	b	.L0f18c76c
/*  f18c630:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c634:
/*  f18c634:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c638:	02602025 */ 	or	$a0,$s3,$zero
/*  f18c63c:	2aa10002 */ 	slti	$at,$s5,0x2
/*  f18c640:	14200004 */ 	bnez	$at,.L0f18c654
/*  f18c644:	00409825 */ 	or	$s3,$v0,$zero
/*  f18c648:	8eca0004 */ 	lw	$t2,0x4($s6)
/*  f18c64c:	504affd8 */ 	beql	$v0,$t2,.L0f18c5b0
/*  f18c650:	00008025 */ 	or	$s0,$zero,$zero
.L0f18c654:
/*  f18c654:	00135880 */ 	sll	$t3,$s3,0x2
/*  f18c658:	01735823 */ 	subu	$t3,$t3,$s3
/*  f18c65c:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f18c660:	3c038008 */ 	lui	$v1,%hi(g_MpTracks)
/*  f18c664:	aed30004 */ 	sw	$s3,0x4($s6)
/*  f18c668:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f18c66c:	94637a70 */ 	lhu	$v1,%lo(g_MpTracks)($v1)
/*  f18c670:	3c018008 */ 	lui	$at,%hi(var800840f8)
/*  f18c674:	306c01ff */ 	andi	$t4,$v1,0x1ff
/*  f18c678:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f18c67c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f18c680:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f18c684:	ac2d40f8 */ 	sw	$t5,%lo(var800840f8)($at)
/*  f18c688:	10000038 */ 	b	.L0f18c76c
/*  f18c68c:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c690:
/*  f18c690:	0fc63122 */ 	jal	mpGetCurrentTrackSlotNum
/*  f18c694:	00000000 */ 	nop
/*  f18c698:	04410022 */ 	bgez	$v0,.L0f18c724
/*  f18c69c:	00409825 */ 	or	$s3,$v0,$zero
/*  f18c6a0:	0fc63080 */ 	jal	mpGetNumUnlockedTracks
/*  f18c6a4:	00000000 */ 	nop
/*  f18c6a8:	3c16800b */ 	lui	$s6,%hi(g_MpLockInfo)
/*  f18c6ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f18c6b0:	26d6cc20 */ 	addiu	$s6,$s6,%lo(g_MpLockInfo)
.L0f18c6b4:
/*  f18c6b4:	0c004b70 */ 	jal	random
/*  f18c6b8:	00000000 */ 	nop
/*  f18c6bc:	0050001b */ 	divu	$zero,$v0,$s0
/*  f18c6c0:	00002010 */ 	mfhi	$a0
/*  f18c6c4:	16000002 */ 	bnez	$s0,.L0f18c6d0
/*  f18c6c8:	00000000 */ 	nop
/*  f18c6cc:	0007000d */ 	break	0x7
.L0f18c6d0:
/*  f18c6d0:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c6d4:	00000000 */ 	nop
/*  f18c6d8:	8ece0004 */ 	lw	$t6,0x4($s6)
/*  f18c6dc:	00409825 */ 	or	$s3,$v0,$zero
/*  f18c6e0:	104efff4 */ 	beq	$v0,$t6,.L0f18c6b4
/*  f18c6e4:	00000000 */ 	nop
/*  f18c6e8:	00027880 */ 	sll	$t7,$v0,0x2
/*  f18c6ec:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18c6f0:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f18c6f4:	3c038008 */ 	lui	$v1,%hi(g_MpTracks)
/*  f18c6f8:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18c6fc:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f18c700:	94637a70 */ 	lhu	$v1,%lo(g_MpTracks)($v1)
/*  f18c704:	3c018008 */ 	lui	$at,%hi(var800840f8)
/*  f18c708:	307801ff */ 	andi	$t8,$v1,0x1ff
/*  f18c70c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f18c710:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f18c714:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18c718:	ac3940f8 */ 	sw	$t9,%lo(var800840f8)($at)
/*  f18c71c:	10000013 */ 	b	.L0f18c76c
/*  f18c720:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c724:
/*  f18c724:	0fc63065 */ 	jal	mpGetTrackNumAtSlotIndex
/*  f18c728:	02602025 */ 	or	$a0,$s3,$zero
/*  f18c72c:	00024080 */ 	sll	$t0,$v0,0x2
/*  f18c730:	3c16800b */ 	lui	$s6,%hi(g_MpLockInfo)
/*  f18c734:	01024023 */ 	subu	$t0,$t0,$v0
/*  f18c738:	26d6cc20 */ 	addiu	$s6,$s6,%lo(g_MpLockInfo)
/*  f18c73c:	00084040 */ 	sll	$t0,$t0,0x1
/*  f18c740:	3c038008 */ 	lui	$v1,%hi(g_MpTracks)
/*  f18c744:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f18c748:	00681821 */ 	addu	$v1,$v1,$t0
/*  f18c74c:	94637a70 */ 	lhu	$v1,%lo(g_MpTracks)($v1)
/*  f18c750:	3c018008 */ 	lui	$at,%hi(var800840f8)
/*  f18c754:	306901ff */ 	andi	$t1,$v1,0x1ff
/*  f18c758:	00095100 */ 	sll	$t2,$t1,0x4
/*  f18c75c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f18c760:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f18c764:	ac2a40f8 */ 	sw	$t2,%lo(var800840f8)($at)
/*  f18c768:	00031242 */ 	srl	$v0,$v1,0x9
.L0f18c76c:
/*  f18c76c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18c770:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18c774:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18c778:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18c77c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18c780:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18c784:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18c788:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18c78c:	03e00008 */ 	jr	$ra
/*  f18c790:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#endif

GLOBAL_ASM(
glabel func0f18c794
/*  f18c794:	3c06800b */ 	lui	$a2,%hi(g_MpSetup+0x16)
/*  f18c798:	00001025 */ 	or	$v0,$zero,$zero
/*  f18c79c:	00001825 */ 	or	$v1,$zero,$zero
/*  f18c7a0:	94c6cb9e */ 	lhu	$a2,%lo(g_MpSetup+0x16)($a2)
/*  f18c7a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f18c7a8:	2407000c */ 	addiu	$a3,$zero,0xc
/*  f18c7ac:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f18c7b0:
/*  f18c7b0:	00ae7804 */ 	sllv	$t7,$t6,$a1
/*  f18c7b4:	00cfc024 */ 	and	$t8,$a2,$t7
/*  f18c7b8:	53000017 */ 	beqzl	$t8,.L0f18c818
/*  f18c7bc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f18c7c0:	14440013 */ 	bne	$v0,$a0,.L0f18c810
/*  f18c7c4:	28a10004 */ 	slti	$at,$a1,0x4
/*  f18c7c8:	10200008 */ 	beqz	$at,.L0f18c7ec
/*  f18c7cc:	00054880 */ 	sll	$t1,$a1,0x2
/*  f18c7d0:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f18c7d4:	0325c821 */ 	addu	$t9,$t9,$a1
/*  f18c7d8:	3c08800b */ 	lui	$t0,%hi(g_MpPlayers)
/*  f18c7dc:	2508c7b8 */ 	addiu	$t0,$t0,%lo(g_MpPlayers)
/*  f18c7e0:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f18c7e4:	03e00008 */ 	jr	$ra
/*  f18c7e8:	03281021 */ 	addu	$v0,$t9,$t0
.L0f18c7ec:
/*  f18c7ec:	01254821 */ 	addu	$t1,$t1,$a1
/*  f18c7f0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f18c7f4:	01254823 */ 	subu	$t1,$t1,$a1
/*  f18c7f8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f18c7fc:	3c0b800b */ 	lui	$t3,%hi(g_MpSimulants)
/*  f18c800:	256bc538 */ 	addiu	$t3,$t3,%lo(g_MpSimulants)
/*  f18c804:	252afed0 */ 	addiu	$t2,$t1,-304
/*  f18c808:	03e00008 */ 	jr	$ra
/*  f18c80c:	014b1021 */ 	addu	$v0,$t2,$t3
.L0f18c810:
/*  f18c810:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18c814:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f18c818:
/*  f18c818:	54a7ffe5 */ 	bnel	$a1,$a3,.L0f18c7b0
/*  f18c81c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18c820:	03e00008 */ 	jr	$ra
/*  f18c824:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f18c828
/*  f18c828:	3c06800b */ 	lui	$a2,%hi(g_MpSetup+0x16)
/*  f18c82c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18c830:	00001825 */ 	or	$v1,$zero,$zero
/*  f18c834:	94c6cb9e */ 	lhu	$a2,%lo(g_MpSetup+0x16)($a2)
/*  f18c838:	00002825 */ 	or	$a1,$zero,$zero
/*  f18c83c:	2407000c */ 	addiu	$a3,$zero,0xc
/*  f18c840:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f18c844:
/*  f18c844:	00ae7804 */ 	sllv	$t7,$t6,$a1
/*  f18c848:	00cfc024 */ 	and	$t8,$a2,$t7
/*  f18c84c:	53000007 */ 	beqzl	$t8,.L0f18c86c
/*  f18c850:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f18c854:	54440004 */ 	bnel	$v0,$a0,.L0f18c868
/*  f18c858:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18c85c:	03e00008 */ 	jr	$ra
/*  f18c860:	00a01025 */ 	or	$v0,$a1,$zero
/*  f18c864:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f18c868:
/*  f18c868:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f18c86c:
/*  f18c86c:	54a7fff5 */ 	bnel	$a1,$a3,.L0f18c844
/*  f18c870:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18c874:	03e00008 */ 	jr	$ra
/*  f18c878:	00601025 */ 	or	$v0,$v1,$zero
);

s32 mpGetNumChrs(void)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i != MAX_MPCHRS; i++) {
		if (g_MpSetup.chrslots & (1 << i)) {
			count++;
		}
	}

	return count;
}

GLOBAL_ASM(
glabel func0f18c8b8
/*  f18c8b8:	3c05800b */ 	lui	$a1,%hi(g_MpSetup+0x16)
/*  f18c8bc:	3c0b800b */ 	lui	$t3,%hi(g_MpSimulants)
/*  f18c8c0:	3c08800b */ 	lui	$t0,%hi(g_MpPlayers)
/*  f18c8c4:	00001825 */ 	or	$v1,$zero,$zero
/*  f18c8c8:	2508c7b8 */ 	addiu	$t0,$t0,%lo(g_MpPlayers)
/*  f18c8cc:	256bc538 */ 	addiu	$t3,$t3,%lo(g_MpSimulants)
/*  f18c8d0:	94a5cb9e */ 	lhu	$a1,%lo(g_MpSetup+0x16)($a1)
/*  f18c8d4:	240c004c */ 	addiu	$t4,$zero,0x4c
/*  f18c8d8:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f18c8dc:	240900a0 */ 	addiu	$t1,$zero,0xa0
/*  f18c8e0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18c8e4:
/*  f18c8e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f18c8e8:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f18c8ec:
/*  f18c8ec:	008e7804 */ 	sllv	$t7,$t6,$a0
/*  f18c8f0:	00afc024 */ 	and	$t8,$a1,$t7
/*  f18c8f4:	13000010 */ 	beqz	$t8,.L0f18c938
/*  f18c8f8:	28810004 */ 	slti	$at,$a0,0x4
/*  f18c8fc:	10200006 */ 	beqz	$at,.L0f18c918
/*  f18c900:	00603825 */ 	or	$a3,$v1,$zero
/*  f18c904:	00890019 */ 	multu	$a0,$t1
/*  f18c908:	0000c812 */ 	mflo	$t9
/*  f18c90c:	01193021 */ 	addu	$a2,$t0,$t9
/*  f18c910:	10000006 */ 	b	.L0f18c92c
/*  f18c914:	90ce0011 */ 	lbu	$t6,0x11($a2)
.L0f18c918:
/*  f18c918:	008c0019 */ 	multu	$a0,$t4
/*  f18c91c:	00006812 */ 	mflo	$t5
/*  f18c920:	016d3021 */ 	addu	$a2,$t3,$t5
/*  f18c924:	24c6fed0 */ 	addiu	$a2,$a2,-304
/*  f18c928:	90ce0011 */ 	lbu	$t6,0x11($a2)
.L0f18c92c:
/*  f18c92c:	54ee0003 */ 	bnel	$a3,$t6,.L0f18c93c
/*  f18c930:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18c934:	00001025 */ 	or	$v0,$zero,$zero
.L0f18c938:
/*  f18c938:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f18c93c:
/*  f18c93c:	548affeb */ 	bnel	$a0,$t2,.L0f18c8ec
/*  f18c940:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18c944:	54400005 */ 	bnezl	$v0,.L0f18c95c
/*  f18c948:	28610007 */ 	slti	$at,$v1,0x7
/*  f18c94c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18c950:	306f00ff */ 	andi	$t7,$v1,0xff
/*  f18c954:	01e01825 */ 	or	$v1,$t7,$zero
/*  f18c958:	28610007 */ 	slti	$at,$v1,0x7
.L0f18c95c:
/*  f18c95c:	50200004 */ 	beqzl	$at,.L0f18c970
/*  f18c960:	28610008 */ 	slti	$at,$v1,0x8
/*  f18c964:	5040ffdf */ 	beqzl	$v0,.L0f18c8e4
/*  f18c968:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f18c96c:	28610008 */ 	slti	$at,$v1,0x8
.L0f18c970:
/*  f18c970:	14200002 */ 	bnez	$at,.L0f18c97c
/*  f18c974:	00000000 */ 	nop
/*  f18c978:	24030007 */ 	addiu	$v1,$zero,0x7
.L0f18c97c:
/*  f18c97c:	03e00008 */ 	jr	$ra
/*  f18c980:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f18c984
/*  f18c984:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f18c988:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f18c98c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18c990:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18c994:	00808025 */ 	or	$s0,$a0,$zero
/*  f18c998:	30b200ff */ 	andi	$s2,$a1,0xff
/*  f18c99c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f18c9a0:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f18c9a4:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18c9a8:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18c9ac:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18c9b0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18c9b4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18c9b8:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f18c9bc:	0fc6322e */ 	jal	func0f18c8b8
/*  f18c9c0:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f18c9c4:	2415004c */ 	addiu	$s5,$zero,0x4c
/*  f18c9c8:	02150019 */ 	multu	$s0,$s5
/*  f18c9cc:	3c188008 */ 	lui	$t8,%hi(g_MpSimulantTypes)
/*  f18c9d0:	2718772c */ 	addiu	$t8,$t8,%lo(g_MpSimulantTypes)
/*  f18c9d4:	001278c0 */ 	sll	$t7,$s2,0x3
/*  f18c9d8:	01f83821 */ 	addu	$a3,$t7,$t8
/*  f18c9dc:	90e80001 */ 	lbu	$t0,0x1($a3)
/*  f18c9e0:	3c14800b */ 	lui	$s4,%hi(g_MpSimulants)
/*  f18c9e4:	90f90000 */ 	lbu	$t9,0x0($a3)
/*  f18c9e8:	2694c538 */ 	addiu	$s4,$s4,%lo(g_MpSimulants)
/*  f18c9ec:	3c0a800b */ 	lui	$t2,%hi(g_MpSimulantDifficultiesPerNumPlayers)
/*  f18c9f0:	00007012 */ 	mflo	$t6
/*  f18c9f4:	028ef021 */ 	addu	$s8,$s4,$t6
/*  f18c9f8:	305100ff */ 	andi	$s1,$v0,0xff
/*  f18c9fc:	254ac798 */ 	addiu	$t2,$t2,%lo(g_MpSimulantDifficultiesPerNumPlayers)
/*  f18ca00:	00104880 */ 	sll	$t1,$s0,0x2
/*  f18ca04:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f18ca08:	012a2021 */ 	addu	$a0,$t1,$t2
/*  f18ca0c:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f18ca10:	00001825 */ 	or	$v1,$zero,$zero
/*  f18ca14:	a3c80048 */ 	sb	$t0,0x48($s8)
/*  f18ca18:	310500ff */ 	andi	$a1,$t0,0xff
/*  f18ca1c:	a3d90047 */ 	sb	$t9,0x47($s8)
.L0f18ca20:
/*  f18ca20:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18ca24:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18ca28:	1462fffd */ 	bne	$v1,$v0,.L0f18ca20
/*  f18ca2c:	a085ffff */ 	sb	$a1,-0x1($a0)
/*  f18ca30:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f18ca34:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f18ca38:	944b0016 */ 	lhu	$t3,0x16($v0)
/*  f18ca3c:	260c0004 */ 	addiu	$t4,$s0,0x4
/*  f18ca40:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f18ca44:	018d7004 */ 	sllv	$t6,$t5,$t4
/*  f18ca48:	3c057f1c */ 	lui	$a1,%hi(var7f1b8b6c)
/*  f18ca4c:	016e7825 */ 	or	$t7,$t3,$t6
/*  f18ca50:	a44f0016 */ 	sh	$t7,0x16($v0)
/*  f18ca54:	24a58b6c */ 	addiu	$a1,$a1,%lo(var7f1b8b6c)
/*  f18ca58:	03c02025 */ 	or	$a0,$s8,$zero
/*  f18ca5c:	afa6005c */ 	sw	$a2,0x5c($sp)
/*  f18ca60:	0c004c4c */ 	jal	strcpy
/*  f18ca64:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f18ca68:	a3d10011 */ 	sb	$s1,0x11($s8)
/*  f18ca6c:	3c11800b */ 	lui	$s1,%hi(g_MpPlayers)
/*  f18ca70:	3c168008 */ 	lui	$s6,%hi(table_0x2d678)
/*  f18ca74:	26d67658 */ 	addiu	$s6,$s6,%lo(table_0x2d678)
/*  f18ca78:	2631c7b8 */ 	addiu	$s1,$s1,%lo(g_MpPlayers)
/*  f18ca7c:	24170035 */ 	addiu	$s7,$zero,0x35
/*  f18ca80:	2413000c */ 	addiu	$s3,$zero,0xc
/*  f18ca84:	241200a0 */ 	addiu	$s2,$zero,0xa0
.L0f18ca88:
/*  f18ca88:	0c004b70 */ 	jal	random
/*  f18ca8c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f18ca90:	0057001b */ 	divu	$zero,$v0,$s7
/*  f18ca94:	0000c010 */ 	mfhi	$t8
/*  f18ca98:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f18ca9c:	02d94021 */ 	addu	$t0,$s6,$t9
/*  f18caa0:	3c04800b */ 	lui	$a0,%hi(g_MpSetup+0x16)
/*  f18caa4:	8d060000 */ 	lw	$a2,0x0($t0)
/*  f18caa8:	16e00002 */ 	bnez	$s7,.L0f18cab4
/*  f18caac:	00000000 */ 	nop
/*  f18cab0:	0007000d */ 	break	0x7
.L0f18cab4:
/*  f18cab4:	9484cb9e */ 	lhu	$a0,%lo(g_MpSetup+0x16)($a0)
/*  f18cab8:	00001825 */ 	or	$v1,$zero,$zero
/*  f18cabc:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f18cac0:
/*  f18cac0:	00695004 */ 	sllv	$t2,$t1,$v1
/*  f18cac4:	008a6824 */ 	and	$t5,$a0,$t2
/*  f18cac8:	11a00010 */ 	beqz	$t5,.L0f18cb0c
/*  f18cacc:	28610004 */ 	slti	$at,$v1,0x4
/*  f18cad0:	10200006 */ 	beqz	$at,.L0f18caec
/*  f18cad4:	00000000 */ 	nop
/*  f18cad8:	00720019 */ 	multu	$v1,$s2
/*  f18cadc:	00006012 */ 	mflo	$t4
/*  f18cae0:	022c1021 */ 	addu	$v0,$s1,$t4
/*  f18cae4:	10000006 */ 	b	.L0f18cb00
/*  f18cae8:	904e000f */ 	lbu	$t6,0xf($v0)
.L0f18caec:
/*  f18caec:	00750019 */ 	multu	$v1,$s5
/*  f18caf0:	00005812 */ 	mflo	$t3
/*  f18caf4:	028b1021 */ 	addu	$v0,$s4,$t3
/*  f18caf8:	2442fed0 */ 	addiu	$v0,$v0,-304
/*  f18cafc:	904e000f */ 	lbu	$t6,0xf($v0)
.L0f18cb00:
/*  f18cb00:	54ce0003 */ 	bnel	$a2,$t6,.L0f18cb10
/*  f18cb04:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18cb08:	00008025 */ 	or	$s0,$zero,$zero
.L0f18cb0c:
/*  f18cb0c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18cb10:
/*  f18cb10:	5473ffeb */ 	bnel	$v1,$s3,.L0f18cac0
/*  f18cb14:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f18cb18:	1200ffdb */ 	beqz	$s0,.L0f18ca88
/*  f18cb1c:	00000000 */ 	nop
/*  f18cb20:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f18cb24:	a3c6000f */ 	sb	$a2,0xf($s8)
/*  f18cb28:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f18cb2c:	85f80004 */ 	lh	$t8,0x4($t7)
/*  f18cb30:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18cb34:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18cb38:	a3d80010 */ 	sb	$t8,0x10($s8)
/*  f18cb3c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f18cb40:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18cb44:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18cb48:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18cb4c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18cb50:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18cb54:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f18cb58:	03e00008 */ 	jr	$ra
/*  f18cb5c:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f18cb60
/*  f18cb60:	00047080 */ 	sll	$t6,$a0,0x2
/*  f18cb64:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f18cb68:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18cb6c:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f18cb70:	3c0f800b */ 	lui	$t7,%hi(g_MpSimulants)
/*  f18cb74:	25efc538 */ 	addiu	$t7,$t7,%lo(g_MpSimulants)
/*  f18cb78:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18cb7c:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f18cb80:	3c19800b */ 	lui	$t9,%hi(g_MpSimulantDifficultiesPerNumPlayers)
/*  f18cb84:	a0450048 */ 	sb	$a1,0x48($v0)
/*  f18cb88:	2739c798 */ 	addiu	$t9,$t9,%lo(g_MpSimulantDifficultiesPerNumPlayers)
/*  f18cb8c:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f18cb90:	03193021 */ 	addu	$a2,$t8,$t9
/*  f18cb94:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f18cb98:	00001825 */ 	or	$v1,$zero,$zero
/*  f18cb9c:	30a700ff */ 	andi	$a3,$a1,0xff
.L0f18cba0:
/*  f18cba0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18cba4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f18cba8:	1462fffd */ 	bne	$v1,$v0,.L0f18cba0
/*  f18cbac:	a0c7ffff */ 	sb	$a3,-0x1($a2)
/*  f18cbb0:	03e00008 */ 	jr	$ra
/*  f18cbb4:	00000000 */ 	nop
);

s32 mpGetNumSimulants(void)
{
	s32 i = 0;

	// @bug: This won't count the last simulant if there's 8
	while (i < MAX_SIMULANTS - 1 && g_MpSetup.chrslots & (1 << (i + 4))) {
		i++;
	}

	return i;
}

void mpRemoveSimulant(s32 index)
{
	g_MpSetup.chrslots &= ~(1 << (index + 4));
	g_MpSimulants[index].base.name[0] = '\0';
	func0f1881d4(index);
	func0f18cddc();
}

bool mpHasSimulants(void)
{
	if ((g_MpSetup.chrslots & 0xfff0) != 0) {
		return true;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f18cc8c
/*  f18cc8c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f18cc90:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18cc94:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f18cc98:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f18cc9c:	10400003 */ 	beqz	$v0,.L0f18ccac
/*  f18cca0:	3c04800b */ 	lui	$a0,%hi(g_MpSetup+0x16)
/*  f18cca4:	10000002 */ 	b	.L0f18ccb0
/*  f18cca8:	24030008 */ 	addiu	$v1,$zero,0x8
.L0f18ccac:
/*  f18ccac:	24030004 */ 	addiu	$v1,$zero,0x4
.L0f18ccb0:
/*  f18ccb0:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f18ccb4:	9484cb9e */ 	lhu	$a0,%lo(g_MpSetup+0x16)($a0)
/*  f18ccb8:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f18ccbc:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f18ccc0:
/*  f18ccc0:	004e7804 */ 	sllv	$t7,$t6,$v0
/*  f18ccc4:	008fc024 */ 	and	$t8,$a0,$t7
/*  f18ccc8:	13000002 */ 	beqz	$t8,.L0f18ccd4
/*  f18cccc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18ccd0:	2463ffff */ 	addiu	$v1,$v1,-1
.L0f18ccd4:
/*  f18ccd4:	5445fffa */ 	bnel	$v0,$a1,.L0f18ccc0
/*  f18ccd8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f18ccdc:	18600003 */ 	blez	$v1,.L0f18ccec
/*  f18cce0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18cce4:	10000002 */ 	b	.L0f18ccf0
/*  f18cce8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18ccec:
/*  f18ccec:	00001025 */ 	or	$v0,$zero,$zero
.L0f18ccf0:
/*  f18ccf0:	03e00008 */ 	jr	$ra
/*  f18ccf4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

bool mpIsSimSlotEnabled(s32 slot)
{
	s32 numfree = 8;
	s32 i;

	if ((g_MpSetup.chrslots & (1 << (slot + 4))) == 0) {
		for (i = 0; i < 8; i++) {
			if (g_MpSetup.chrslots & (1 << (i + 4))) {
				numfree--;
			}
		}

		if (numfree > 0) {
			return true;
		}

		return false;
	}

	return true;
}

s32 mpGetSimTypeIndex(s32 type, s32 difficulty)
{
	s32 i;

	if (type == SIMTYPE_GENERAL) {
		for (i = 0; i < ARRAYCOUNT(g_MpSimulantTypes); i++) {
			if (g_MpSimulantTypes[i].difficulty == difficulty) {
				break;
			}
		}
	} else {
		for (i = 0; i < ARRAYCOUNT(g_MpSimulantTypes); i++) {
			if (g_MpSimulantTypes[i].type == type) {
				break;
			}
		}
	}

	if (i >= ARRAYCOUNT(g_MpSimulantTypes)) {
		i = -1;
	}

	return i;
}

GLOBAL_ASM(
glabel func0f18cddc
/*  f18cddc:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f18cde0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f18cde4:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f18cde8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f18cdec:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18cdf0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18cdf4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18cdf8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18cdfc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18ce00:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18ce04:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18ce08:	27a20068 */ 	addiu	$v0,$sp,0x68
/*  f18ce0c:	27a300b0 */ 	addiu	$v1,$sp,0xb0
.L0f18ce10:
/*  f18ce10:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18ce14:	0043082b */ 	sltu	$at,$v0,$v1
/*  f18ce18:	1420fffd */ 	bnez	$at,.L0f18ce10
/*  f18ce1c:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f18ce20:	3c17800b */ 	lui	$s7,%hi(g_MpSimulants)
/*  f18ce24:	3c16800b */ 	lui	$s6,%hi(g_MpSetup)
/*  f18ce28:	26d6cb88 */ 	addiu	$s6,$s6,%lo(g_MpSetup)
/*  f18ce2c:	26f7c538 */ 	addiu	$s7,$s7,%lo(g_MpSimulants)
/*  f18ce30:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f18ce34:	241e004c */ 	addiu	$s8,$zero,0x4c
/*  f18ce38:	27b50068 */ 	addiu	$s5,$sp,0x68
/*  f18ce3c:	96ce0016 */ 	lhu	$t6,0x16($s6)
.L0f18ce40:
/*  f18ce40:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18ce44:	022fc004 */ 	sllv	$t8,$t7,$s1
/*  f18ce48:	01d8c824 */ 	and	$t9,$t6,$t8
/*  f18ce4c:	53200010 */ 	beqzl	$t9,.L0f18ce90
/*  f18ce50:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18ce54:	023e0019 */ 	multu	$s1,$s8
/*  f18ce58:	00004012 */ 	mflo	$t0
/*  f18ce5c:	02e88021 */ 	addu	$s0,$s7,$t0
/*  f18ce60:	9204ff17 */ 	lbu	$a0,-0xe9($s0)
/*  f18ce64:	0fc6335a */ 	jal	mpGetSimTypeIndex
/*  f18ce68:	9205ff18 */ 	lbu	$a1,-0xe8($s0)
/*  f18ce6c:	04400007 */ 	bltz	$v0,.L0f18ce8c
/*  f18ce70:	28410012 */ 	slti	$at,$v0,0x12
/*  f18ce74:	10200005 */ 	beqz	$at,.L0f18ce8c
/*  f18ce78:	00024880 */ 	sll	$t1,$v0,0x2
/*  f18ce7c:	02a91821 */ 	addu	$v1,$s5,$t1
/*  f18ce80:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f18ce84:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f18ce88:	ac6b0000 */ 	sw	$t3,0x0($v1)
.L0f18ce8c:
/*  f18ce8c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18ce90:
/*  f18ce90:	2a21000c */ 	slti	$at,$s1,0xc
/*  f18ce94:	5420ffea */ 	bnezl	$at,.L0f18ce40
/*  f18ce98:	96ce0016 */ 	lhu	$t6,0x16($s6)
/*  f18ce9c:	27a20068 */ 	addiu	$v0,$sp,0x68
/*  f18cea0:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*  f18cea4:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f18cea8:	8c4c0000 */ 	lw	$t4,0x0($v0)
.L0f18ceac:
/*  f18ceac:	29810002 */ 	slti	$at,$t4,0x2
/*  f18ceb0:	50200004 */ 	beqzl	$at,.L0f18cec4
/*  f18ceb4:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f18ceb8:	10000002 */ 	b	.L0f18cec4
/*  f18cebc:	ac430000 */ 	sw	$v1,0x0($v0)
/*  f18cec0:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f18cec4:
/*  f18cec4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18cec8:	0044082b */ 	sltu	$at,$v0,$a0
/*  f18cecc:	5420fff7 */ 	bnezl	$at,.L0f18ceac
/*  f18ced0:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f18ced4:	3c148008 */ 	lui	$s4,%hi(g_MpSimulantTypes)
/*  f18ced8:	2694772c */ 	addiu	$s4,$s4,%lo(g_MpSimulantTypes)
/*  f18cedc:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f18cee0:	27b30050 */ 	addiu	$s3,$sp,0x50
/*  f18cee4:	96cd0016 */ 	lhu	$t5,0x16($s6)
.L0f18cee8:
/*  f18cee8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18ceec:	022f7004 */ 	sllv	$t6,$t7,$s1
/*  f18cef0:	01aec024 */ 	and	$t8,$t5,$t6
/*  f18cef4:	53000031 */ 	beqzl	$t8,.L0f18cfbc
/*  f18cef8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18cefc:	023e0019 */ 	multu	$s1,$s8
/*  f18cf00:	0000c812 */ 	mflo	$t9
/*  f18cf04:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f18cf08:	9204ff17 */ 	lbu	$a0,-0xe9($s0)
/*  f18cf0c:	0fc6335a */ 	jal	mpGetSimTypeIndex
/*  f18cf10:	9205ff18 */ 	lbu	$a1,-0xe8($s0)
/*  f18cf14:	04400028 */ 	bltz	$v0,.L0f18cfb8
/*  f18cf18:	00401825 */ 	or	$v1,$v0,$zero
/*  f18cf1c:	28410012 */ 	slti	$at,$v0,0x12
/*  f18cf20:	10200025 */ 	beqz	$at,.L0f18cfb8
/*  f18cf24:	00024080 */ 	sll	$t0,$v0,0x2
/*  f18cf28:	02a84821 */ 	addu	$t1,$s5,$t0
/*  f18cf2c:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f18cf30:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f18cf34:	2612fed0 */ 	addiu	$s2,$s0,-304
/*  f18cf38:	05400015 */ 	bltz	$t2,.L0f18cf90
/*  f18cf3c:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f18cf40:	00025880 */ 	sll	$t3,$v0,0x2
/*  f18cf44:	02ab8021 */ 	addu	$s0,$s5,$t3
/*  f18cf48:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18cf4c:	000268c0 */ 	sll	$t5,$v0,0x3
/*  f18cf50:	028d7021 */ 	addu	$t6,$s4,$t5
/*  f18cf54:	258f0001 */ 	addiu	$t7,$t4,0x1
/*  f18cf58:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f18cf5c:	0fc5b9f1 */ 	jal	langGet
/*  f18cf60:	85c40002 */ 	lh	$a0,0x2($t6)
/*  f18cf64:	3c057f1c */ 	lui	$a1,%hi(var7f1b8b74)
/*  f18cf68:	24a58b74 */ 	addiu	$a1,$a1,%lo(var7f1b8b74)
/*  f18cf6c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18cf70:	00403025 */ 	or	$a2,$v0,$zero
/*  f18cf74:	0c004dad */ 	jal	sprintf
/*  f18cf78:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f18cf7c:	02402025 */ 	or	$a0,$s2,$zero
/*  f18cf80:	0c004c4c */ 	jal	strcpy
/*  f18cf84:	02602825 */ 	or	$a1,$s3,$zero
/*  f18cf88:	1000000c */ 	b	.L0f18cfbc
/*  f18cf8c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18cf90:
/*  f18cf90:	0fc5b9f1 */ 	jal	langGet
/*  f18cf94:	87240002 */ 	lh	$a0,0x2($t9)
/*  f18cf98:	3c057f1c */ 	lui	$a1,%hi(var7f1b8b7c)
/*  f18cf9c:	24a58b7c */ 	addiu	$a1,$a1,%lo(var7f1b8b7c)
/*  f18cfa0:	02602025 */ 	or	$a0,$s3,$zero
/*  f18cfa4:	0c004dad */ 	jal	sprintf
/*  f18cfa8:	00403025 */ 	or	$a2,$v0,$zero
/*  f18cfac:	02402025 */ 	or	$a0,$s2,$zero
/*  f18cfb0:	0c004c4c */ 	jal	strcpy
/*  f18cfb4:	02602825 */ 	or	$a1,$s3,$zero
.L0f18cfb8:
/*  f18cfb8:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f18cfbc:
/*  f18cfbc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f18cfc0:	5621ffc9 */ 	bnel	$s1,$at,.L0f18cee8
/*  f18cfc4:	96cd0016 */ 	lhu	$t5,0x16($s6)
/*  f18cfc8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f18cfcc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18cfd0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18cfd4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18cfd8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18cfdc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18cfe0:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18cfe4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18cfe8:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f18cfec:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f18cff0:	03e00008 */ 	jr	$ra
/*  f18cff4:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

s32 mpPlayerGetIndex(struct chrdata *chr)
{
	s32 i;

	for (i = 0; i < g_MpNumPlayers; i++) {
		if (g_MpPlayerChrs[i] == chr) {
			return i;
		}
	}

	return -1;
}

struct chrdata *mpGetChrFromPlayerIndex(s32 index)
{
	if (index >= 0 && index < g_MpNumPlayers) {
		return g_MpPlayerChrs[index];
	}

	return NULL;
}

s32 func0f18d074(s32 index)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (&g_MpPlayers[i].base == var800ac500[index]) {
			return i;
		}
	}

	for (i = 0; i < MAX_SIMULANTS; i++) {
		if (&g_MpSimulants[i].base == var800ac500[index]) {
			return i + 4;
		}
	}

	return -1;
}

GLOBAL_ASM(
glabel func0f18d0e8
/*  f18d0e8:	28810004 */ 	slti	$at,$a0,0x4
/*  f18d0ec:	10200018 */ 	beqz	$at,.L0f18d150
/*  f18d0f0:	3c02800b */ 	lui	$v0,%hi(g_MpNumPlayers)
/*  f18d0f4:	3c02800b */ 	lui	$v0,%hi(g_MpNumPlayers)
/*  f18d0f8:	8c42c530 */ 	lw	$v0,%lo(g_MpNumPlayers)($v0)
/*  f18d0fc:	3c05800b */ 	lui	$a1,%hi(var800ac500)
/*  f18d100:	24a5c500 */ 	addiu	$a1,$a1,%lo(var800ac500)
/*  f18d104:	18400029 */ 	blez	$v0,.L0f18d1ac
/*  f18d108:	00001825 */ 	or	$v1,$zero,$zero
/*  f18d10c:	00047080 */ 	sll	$t6,$a0,0x2
/*  f18d110:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f18d114:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f18d118:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f18d11c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18d120:	01cf3021 */ 	addu	$a2,$t6,$t7
.L0f18d124:
/*  f18d124:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f18d128:	57060004 */ 	bnel	$t8,$a2,.L0f18d13c
/*  f18d12c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18d130:	03e00008 */ 	jr	$ra
/*  f18d134:	00601025 */ 	or	$v0,$v1,$zero
/*  f18d138:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18d13c:
/*  f18d13c:	0062082a */ 	slt	$at,$v1,$v0
/*  f18d140:	1420fff8 */ 	bnez	$at,.L0f18d124
/*  f18d144:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f18d148:	10000019 */ 	b	.L0f18d1b0
/*  f18d14c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18d150:
/*  f18d150:	8c42c530 */ 	lw	$v0,%lo(g_MpNumPlayers)($v0)
/*  f18d154:	3c05800b */ 	lui	$a1,%hi(var800ac500)
/*  f18d158:	24a5c500 */ 	addiu	$a1,$a1,%lo(var800ac500)
/*  f18d15c:	18400013 */ 	blez	$v0,.L0f18d1ac
/*  f18d160:	00001825 */ 	or	$v1,$zero,$zero
/*  f18d164:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f18d168:	0324c821 */ 	addu	$t9,$t9,$a0
/*  f18d16c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18d170:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f18d174:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18d178:	3c09800b */ 	lui	$t1,%hi(g_MpSimulants)
/*  f18d17c:	2529c538 */ 	addiu	$t1,$t1,%lo(g_MpSimulants)
/*  f18d180:	2728fed0 */ 	addiu	$t0,$t9,-304
/*  f18d184:	01093021 */ 	addu	$a2,$t0,$t1
.L0f18d188:
/*  f18d188:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f18d18c:	55460004 */ 	bnel	$t2,$a2,.L0f18d1a0
/*  f18d190:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18d194:	03e00008 */ 	jr	$ra
/*  f18d198:	00601025 */ 	or	$v0,$v1,$zero
/*  f18d19c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f18d1a0:
/*  f18d1a0:	0062082a */ 	slt	$at,$v1,$v0
/*  f18d1a4:	1420fff8 */ 	bnez	$at,.L0f18d188
/*  f18d1a8:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0f18d1ac:
/*  f18d1ac:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18d1b0:
/*  f18d1b0:	03e00008 */ 	jr	$ra
/*  f18d1b4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f18d1b8
/*  f18d1b8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18d1bc:	00057080 */ 	sll	$t6,$a1,0x2
/*  f18d1c0:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f18d1c4:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f18d1c8:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18d1cc:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18d1d0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18d1d4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18d1d8:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f18d1dc:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18d1e0:	00809025 */ 	or	$s2,$a0,$zero
/*  f18d1e4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18d1e8:	24100023 */ 	addiu	$s0,$zero,0x23
/*  f18d1ec:	01cf8821 */ 	addu	$s1,$t6,$t7
/*  f18d1f0:	2413fffb */ 	addiu	$s3,$zero,-5
.L0f18d1f4:
/*  f18d1f4:	2a010009 */ 	slti	$at,$s0,0x9
/*  f18d1f8:	14200002 */ 	bnez	$at,.L0f18d204
/*  f18d1fc:	02002825 */ 	or	$a1,$s0,$zero
/*  f18d200:	24050008 */ 	addiu	$a1,$zero,0x8
.L0f18d204:
/*  f18d204:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d208:	02402025 */ 	or	$a0,$s2,$zero
/*  f18d20c:	2610fff8 */ 	addiu	$s0,$s0,-8
/*  f18d210:	a2220097 */ 	sb	$v0,0x97($s1)
/*  f18d214:	1613fff7 */ 	bne	$s0,$s3,.L0f18d1f4
/*  f18d218:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18d21c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18d220:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18d224:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18d228:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18d22c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18d230:	03e00008 */ 	jr	$ra
/*  f18d234:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18d238
/*  f18d238:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18d23c:	00057080 */ 	sll	$t6,$a1,0x2
/*  f18d240:	01c57021 */ 	addu	$t6,$t6,$a1
/*  f18d244:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f18d248:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18d24c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18d250:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18d254:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18d258:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f18d25c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18d260:	00809025 */ 	or	$s2,$a0,$zero
/*  f18d264:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18d268:	24100023 */ 	addiu	$s0,$zero,0x23
/*  f18d26c:	01cf8821 */ 	addu	$s1,$t6,$t7
/*  f18d270:	2413fffb */ 	addiu	$s3,$zero,-5
.L0f18d274:
/*  f18d274:	2a010009 */ 	slti	$at,$s0,0x9
/*  f18d278:	14200002 */ 	bnez	$at,.L0f18d284
/*  f18d27c:	02003025 */ 	or	$a2,$s0,$zero
/*  f18d280:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f18d284:
/*  f18d284:	02402025 */ 	or	$a0,$s2,$zero
/*  f18d288:	0fc354be */ 	jal	savefileGetSomething
/*  f18d28c:	92250097 */ 	lbu	$a1,0x97($s1)
/*  f18d290:	2610fff8 */ 	addiu	$s0,$s0,-8
/*  f18d294:	1613fff7 */ 	bne	$s0,$s3,.L0f18d274
/*  f18d298:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18d29c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18d2a0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18d2a4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18d2a8:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18d2ac:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18d2b0:	03e00008 */ 	jr	$ra
/*  f18d2b4:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18d2b8
/*  f18d2b8:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f18d2bc:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f18d2c0:	0080a025 */ 	or	$s4,$a0,$zero
/*  f18d2c4:	00147080 */ 	sll	$t6,$s4,0x2
/*  f18d2c8:	01d47021 */ 	addu	$t6,$t6,$s4
/*  f18d2cc:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f18d2d0:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f18d2d4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18d2d8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18d2dc:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f18d2e0:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18d2e4:	00c08025 */ 	or	$s0,$a2,$zero
/*  f18d2e8:	00a09825 */ 	or	$s3,$a1,$zero
/*  f18d2ec:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f18d2f0:	01cfa821 */ 	addu	$s5,$t6,$t7
/*  f18d2f4:	00a02025 */ 	or	$a0,$a1,$zero
/*  f18d2f8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18d2fc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18d300:	02a02825 */ 	or	$a1,$s5,$zero
/*  f18d304:	0fc35539 */ 	jal	func0f0d54e4
/*  f18d308:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18d30c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d310:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d314:	2405001c */ 	addiu	$a1,$zero,0x1c
/*  f18d318:	12000037 */ 	beqz	$s0,.L0f18d3f8
/*  f18d31c:	aea20068 */ 	sw	$v0,0x68($s5)
/*  f18d320:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d324:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d328:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18d32c:	a2a2000f */ 	sb	$v0,0xf($s5)
/*  f18d330:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d334:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d338:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18d33c:	a2a20010 */ 	sb	$v0,0x10($s5)
/*  f18d340:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d344:	0fc355e7 */ 	jal	func0f0d579c
/*  f18d348:	27a50050 */ 	addiu	$a1,$sp,0x50
/*  f18d34c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f18d350:	00000000 */ 	nop
/*  f18d354:	92b8000f */ 	lbu	$t8,0xf($s5)
/*  f18d358:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f18d35c:	0302082a */ 	slt	$at,$t8,$v0
/*  f18d360:	5420002f */ 	bnezl	$at,.L0f18d420
/*  f18d364:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d368:	10c00021 */ 	beqz	$a2,.L0f18d3f0
/*  f18d36c:	97a70054 */ 	lhu	$a3,0x54($sp)
/*  f18d370:	10e0001f */ 	beqz	$a3,.L0f18d3f0
/*  f18d374:	3c02800a */ 	lui	$v0,%hi(g_MenuData)
/*  f18d378:	244219c0 */ 	addiu	$v0,$v0,%lo(g_MenuData)
/*  f18d37c:	80450668 */ 	lb	$a1,0x668($v0)
/*  f18d380:	28a1000b */ 	slti	$at,$a1,0xb
/*  f18d384:	10200025 */ 	beqz	$at,.L0f18d41c
/*  f18d388:	24b90001 */ 	addiu	$t9,$a1,0x1
/*  f18d38c:	a0590668 */ 	sb	$t9,0x668($v0)
/*  f18d390:	80480668 */ 	lb	$t0,0x668($v0)
/*  f18d394:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f18d398:	3c038007 */ 	lui	$v1,%hi(g_MpPlayerNum)
/*  f18d39c:	01040019 */ 	multu	$t0,$a0
/*  f18d3a0:	00004812 */ 	mflo	$t1
/*  f18d3a4:	00495021 */ 	addu	$t2,$v0,$t1
/*  f18d3a8:	ad4605d8 */ 	sw	$a2,0x5d8($t2)
/*  f18d3ac:	804b0668 */ 	lb	$t3,0x668($v0)
/*  f18d3b0:	01640019 */ 	multu	$t3,$a0
/*  f18d3b4:	00006012 */ 	mflo	$t4
/*  f18d3b8:	004c6821 */ 	addu	$t5,$v0,$t4
/*  f18d3bc:	a5a705dc */ 	sh	$a3,0x5dc($t5)
/*  f18d3c0:	804e0668 */ 	lb	$t6,0x668($v0)
/*  f18d3c4:	8c631448 */ 	lw	$v1,%lo(g_MpPlayerNum)($v1)
/*  f18d3c8:	01c40019 */ 	multu	$t6,$a0
/*  f18d3cc:	00007812 */ 	mflo	$t7
/*  f18d3d0:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f18d3d4:	a30305e0 */ 	sb	$v1,0x5e0($t8)
/*  f18d3d8:	80590668 */ 	lb	$t9,0x668($v0)
/*  f18d3dc:	03240019 */ 	multu	$t9,$a0
/*  f18d3e0:	00004012 */ 	mflo	$t0
/*  f18d3e4:	00484821 */ 	addu	$t1,$v0,$t0
/*  f18d3e8:	1000000c */ 	b	.L0f18d41c
/*  f18d3ec:	a12305e1 */ 	sb	$v1,0x5e1($t1)
.L0f18d3f0:
/*  f18d3f0:	1000000a */ 	b	.L0f18d41c
/*  f18d3f4:	a2a0000f */ 	sb	$zero,0xf($s5)
.L0f18d3f8:
/*  f18d3f8:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d3fc:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d400:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18d404:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d408:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d40c:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18d410:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d414:	0fc355e7 */ 	jal	func0f0d579c
/*  f18d418:	27a50050 */ 	addiu	$a1,$sp,0x50
.L0f18d41c:
/*  f18d41c:	02602025 */ 	or	$a0,$s3,$zero
.L0f18d420:
/*  f18d420:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d424:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f18d428:	aea20014 */ 	sw	$v0,0x14($s5)
/*  f18d42c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d430:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d434:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f18d438:	aea20054 */ 	sw	$v0,0x54($s5)
/*  f18d43c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d440:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d444:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f18d448:	aea20058 */ 	sw	$v0,0x58($s5)
/*  f18d44c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d450:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d454:	24050013 */ 	addiu	$a1,$zero,0x13
/*  f18d458:	aea2005c */ 	sw	$v0,0x5c($s5)
/*  f18d45c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d460:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d464:	24050013 */ 	addiu	$a1,$zero,0x13
/*  f18d468:	aea20060 */ 	sw	$v0,0x60($s5)
/*  f18d46c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d470:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d474:	24050013 */ 	addiu	$a1,$zero,0x13
/*  f18d478:	aea20064 */ 	sw	$v0,0x64($s5)
/*  f18d47c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d480:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d484:	24050019 */ 	addiu	$a1,$zero,0x19
/*  f18d488:	aea2006c */ 	sw	$v0,0x6c($s5)
/*  f18d48c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d490:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d494:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f18d498:	aea20070 */ 	sw	$v0,0x70($s5)
/*  f18d49c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4a0:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d4a4:	2405001a */ 	addiu	$a1,$zero,0x1a
/*  f18d4a8:	aea20074 */ 	sw	$v0,0x74($s5)
/*  f18d4ac:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4b0:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d4b4:	2405001a */ 	addiu	$a1,$zero,0x1a
/*  f18d4b8:	aea20078 */ 	sw	$v0,0x78($s5)
/*  f18d4bc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4c0:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d4c4:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f18d4c8:	aea2007c */ 	sw	$v0,0x7c($s5)
/*  f18d4cc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4d0:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d4d4:	2405001e */ 	addiu	$a1,$zero,0x1e
/*  f18d4d8:	aea20080 */ 	sw	$v0,0x80($s5)
/*  f18d4dc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4e0:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d4e4:	24050012 */ 	addiu	$a1,$zero,0x12
/*  f18d4e8:	aea20084 */ 	sw	$v0,0x84($s5)
/*  f18d4ec:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d4f0:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d4f4:	24050012 */ 	addiu	$a1,$zero,0x12
/*  f18d4f8:	aea20088 */ 	sw	$v0,0x88($s5)
/*  f18d4fc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d500:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d504:	24050012 */ 	addiu	$a1,$zero,0x12
/*  f18d508:	aea2008c */ 	sw	$v0,0x8c($s5)
/*  f18d50c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d510:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d514:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f18d518:	aea20090 */ 	sw	$v0,0x90($s5)
/*  f18d51c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d520:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d524:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f18d528:	a2a20044 */ 	sb	$v0,0x44($s5)
/*  f18d52c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d530:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d534:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f18d538:	a6a20048 */ 	sh	$v0,0x48($s5)
/*  f18d53c:	00008825 */ 	or	$s1,$zero,$zero
/*  f18d540:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f18d544:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f18d548:
/*  f18d548:	02602025 */ 	or	$a0,$s3,$zero
.L0f18d54c:
/*  f18d54c:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d550:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18d554:	02802025 */ 	or	$a0,$s4,$zero
/*  f18d558:	02202825 */ 	or	$a1,$s1,$zero
/*  f18d55c:	02003025 */ 	or	$a2,$s0,$zero
/*  f18d560:	0fc6712e */ 	jal	mpSetChallengeCompletedByPlayerWithNumPlayers
/*  f18d564:	00403825 */ 	or	$a3,$v0,$zero
/*  f18d568:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18d56c:	5612fff7 */ 	bnel	$s0,$s2,.L0f18d54c
/*  f18d570:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d574:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18d578:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f18d57c:	5621fff2 */ 	bnel	$s1,$at,.L0f18d548
/*  f18d580:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f18d584:	0fc66bf7 */ 	jal	mpDetermineUnlockedFeatures
/*  f18d588:	00000000 */ 	nop
/*  f18d58c:	0fc62864 */ 	jal	mpCalculatePlayerTitle
/*  f18d590:	02a02025 */ 	or	$a0,$s5,$zero
/*  f18d594:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d598:	0fc6346e */ 	jal	func0f18d1b8
/*  f18d59c:	02802825 */ 	or	$a1,$s4,$zero
/*  f18d5a0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f18d5a4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18d5a8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18d5ac:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18d5b0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18d5b4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f18d5b8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f18d5bc:	03e00008 */ 	jr	$ra
/*  f18d5c0:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f18d5c4
/*  f18d5c4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f18d5c8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18d5cc:	0080a025 */ 	or	$s4,$a0,$zero
/*  f18d5d0:	00147080 */ 	sll	$t6,$s4,0x2
/*  f18d5d4:	01d47021 */ 	addu	$t6,$t6,$s4
/*  f18d5d8:	3c0f800b */ 	lui	$t7,%hi(g_MpPlayers)
/*  f18d5dc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18d5e0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18d5e4:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_MpPlayers)
/*  f18d5e8:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18d5ec:	00a09825 */ 	or	$s3,$a1,$zero
/*  f18d5f0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f18d5f4:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f18d5f8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f18d5fc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18d600:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18d604:	0fc35569 */ 	jal	func0f0d55a4
/*  f18d608:	02002825 */ 	or	$a1,$s0,$zero
/*  f18d60c:	8e050068 */ 	lw	$a1,0x68($s0)
/*  f18d610:	3c011000 */ 	lui	$at,0x1000
/*  f18d614:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d618:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d61c:	14200003 */ 	bnez	$at,.L0f18d62c
/*  f18d620:	3c180fff */ 	lui	$t8,0xfff
/*  f18d624:	3705ffff */ 	ori	$a1,$t8,0xffff
/*  f18d628:	ae050068 */ 	sw	$a1,0x68($s0)
.L0f18d62c:
/*  f18d62c:	0fc354be */ 	jal	savefileGetSomething
/*  f18d630:	2406001c */ 	addiu	$a2,$zero,0x1c
/*  f18d634:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d638:	9205000f */ 	lbu	$a1,0xf($s0)
/*  f18d63c:	0fc354be */ 	jal	savefileGetSomething
/*  f18d640:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18d644:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d648:	92050010 */ 	lbu	$a1,0x10($s0)
/*  f18d64c:	0fc354be */ 	jal	savefileGetSomething
/*  f18d650:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18d654:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f18d658:	00000000 */ 	nop
/*  f18d65c:	9219000f */ 	lbu	$t9,0xf($s0)
/*  f18d660:	0322082a */ 	slt	$at,$t9,$v0
/*  f18d664:	5420000e */ 	bnezl	$at,.L0f18d6a0
/*  f18d668:	a7a00040 */ 	sh	$zero,0x40($sp)
/*  f18d66c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f18d670:	00000000 */ 	nop
/*  f18d674:	9208000f */ 	lbu	$t0,0xf($s0)
/*  f18d678:	27b10044 */ 	addiu	$s1,$sp,0x44
/*  f18d67c:	02202825 */ 	or	$a1,$s1,$zero
/*  f18d680:	0fc541ed */ 	jal	func0f1507b4
/*  f18d684:	01022023 */ 	subu	$a0,$t0,$v0
/*  f18d688:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d68c:	0fc355d7 */ 	jal	func0f0d575c
/*  f18d690:	02202825 */ 	or	$a1,$s1,$zero
/*  f18d694:	10000007 */ 	b	.L0f18d6b4
/*  f18d698:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d69c:	a7a00040 */ 	sh	$zero,0x40($sp)
.L0f18d6a0:
/*  f18d6a0:	afa0003c */ 	sw	$zero,0x3c($sp)
/*  f18d6a4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d6a8:	0fc355d7 */ 	jal	func0f0d575c
/*  f18d6ac:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f18d6b0:	02602025 */ 	or	$a0,$s3,$zero
.L0f18d6b4:
/*  f18d6b4:	8e050014 */ 	lw	$a1,0x14($s0)
/*  f18d6b8:	0fc354be */ 	jal	savefileGetSomething
/*  f18d6bc:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f18d6c0:	8e050054 */ 	lw	$a1,0x54($s0)
/*  f18d6c4:	3c010010 */ 	lui	$at,0x10
/*  f18d6c8:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d6cc:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d6d0:	14200003 */ 	bnez	$at,.L0f18d6e0
/*  f18d6d4:	3c09000f */ 	lui	$t1,0xf
/*  f18d6d8:	3525ffff */ 	ori	$a1,$t1,0xffff
/*  f18d6dc:	ae050054 */ 	sw	$a1,0x54($s0)
.L0f18d6e0:
/*  f18d6e0:	0fc354be */ 	jal	savefileGetSomething
/*  f18d6e4:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f18d6e8:	8e050058 */ 	lw	$a1,0x58($s0)
/*  f18d6ec:	3c010010 */ 	lui	$at,0x10
/*  f18d6f0:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d6f4:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d6f8:	14200003 */ 	bnez	$at,.L0f18d708
/*  f18d6fc:	3c0a000f */ 	lui	$t2,0xf
/*  f18d700:	3545ffff */ 	ori	$a1,$t2,0xffff
/*  f18d704:	ae050058 */ 	sw	$a1,0x58($s0)
.L0f18d708:
/*  f18d708:	0fc354be */ 	jal	savefileGetSomething
/*  f18d70c:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f18d710:	8e05005c */ 	lw	$a1,0x5c($s0)
/*  f18d714:	3c110008 */ 	lui	$s1,0x8
/*  f18d718:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d71c:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d720:	14200004 */ 	bnez	$at,.L0f18d734
/*  f18d724:	24060013 */ 	addiu	$a2,$zero,0x13
/*  f18d728:	3c120007 */ 	lui	$s2,0x7
/*  f18d72c:	3645ffff */ 	ori	$a1,$s2,0xffff
/*  f18d730:	ae05005c */ 	sw	$a1,0x5c($s0)
.L0f18d734:
/*  f18d734:	3c120007 */ 	lui	$s2,0x7
/*  f18d738:	0fc354be */ 	jal	savefileGetSomething
/*  f18d73c:	3652ffff */ 	ori	$s2,$s2,0xffff
/*  f18d740:	8e050060 */ 	lw	$a1,0x60($s0)
/*  f18d744:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d748:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d74c:	14200003 */ 	bnez	$at,.L0f18d75c
/*  f18d750:	00000000 */ 	nop
/*  f18d754:	ae120060 */ 	sw	$s2,0x60($s0)
/*  f18d758:	02402825 */ 	or	$a1,$s2,$zero
.L0f18d75c:
/*  f18d75c:	0fc354be */ 	jal	savefileGetSomething
/*  f18d760:	24060013 */ 	addiu	$a2,$zero,0x13
/*  f18d764:	8e050064 */ 	lw	$a1,0x64($s0)
/*  f18d768:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d76c:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d770:	14200003 */ 	bnez	$at,.L0f18d780
/*  f18d774:	00000000 */ 	nop
/*  f18d778:	ae120064 */ 	sw	$s2,0x64($s0)
/*  f18d77c:	02402825 */ 	or	$a1,$s2,$zero
.L0f18d780:
/*  f18d780:	0fc354be */ 	jal	savefileGetSomething
/*  f18d784:	24060013 */ 	addiu	$a2,$zero,0x13
/*  f18d788:	8e05006c */ 	lw	$a1,0x6c($s0)
/*  f18d78c:	3c010200 */ 	lui	$at,0x200
/*  f18d790:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d794:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d798:	14200003 */ 	bnez	$at,.L0f18d7a8
/*  f18d79c:	3c0b01ff */ 	lui	$t3,0x1ff
/*  f18d7a0:	3565ffff */ 	ori	$a1,$t3,0xffff
/*  f18d7a4:	ae05006c */ 	sw	$a1,0x6c($s0)
.L0f18d7a8:
/*  f18d7a8:	0fc354be */ 	jal	savefileGetSomething
/*  f18d7ac:	24060019 */ 	addiu	$a2,$zero,0x19
/*  f18d7b0:	8e050070 */ 	lw	$a1,0x70($s0)
/*  f18d7b4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d7b8:	2ca10400 */ 	sltiu	$at,$a1,0x400
/*  f18d7bc:	14200003 */ 	bnez	$at,.L0f18d7cc
/*  f18d7c0:	00000000 */ 	nop
/*  f18d7c4:	240503ff */ 	addiu	$a1,$zero,0x3ff
/*  f18d7c8:	ae050070 */ 	sw	$a1,0x70($s0)
.L0f18d7cc:
/*  f18d7cc:	0fc354be */ 	jal	savefileGetSomething
/*  f18d7d0:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f18d7d4:	8e050074 */ 	lw	$a1,0x74($s0)
/*  f18d7d8:	3c110400 */ 	lui	$s1,0x400
/*  f18d7dc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d7e0:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d7e4:	14200003 */ 	bnez	$at,.L0f18d7f4
/*  f18d7e8:	3c0d03ff */ 	lui	$t5,0x3ff
/*  f18d7ec:	35a5ffff */ 	ori	$a1,$t5,0xffff
/*  f18d7f0:	ae050074 */ 	sw	$a1,0x74($s0)
.L0f18d7f4:
/*  f18d7f4:	0fc354be */ 	jal	savefileGetSomething
/*  f18d7f8:	2406001a */ 	addiu	$a2,$zero,0x1a
/*  f18d7fc:	8e050078 */ 	lw	$a1,0x78($s0)
/*  f18d800:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d804:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d808:	14200003 */ 	bnez	$at,.L0f18d818
/*  f18d80c:	3c0e03ff */ 	lui	$t6,0x3ff
/*  f18d810:	35c5ffff */ 	ori	$a1,$t6,0xffff
/*  f18d814:	ae050078 */ 	sw	$a1,0x78($s0)
.L0f18d818:
/*  f18d818:	0fc354be */ 	jal	savefileGetSomething
/*  f18d81c:	2406001a */ 	addiu	$a2,$zero,0x1a
/*  f18d820:	8e05007c */ 	lw	$a1,0x7c($s0)
/*  f18d824:	3c010010 */ 	lui	$at,0x10
/*  f18d828:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d82c:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d830:	14200003 */ 	bnez	$at,.L0f18d840
/*  f18d834:	3c0f000f */ 	lui	$t7,0xf
/*  f18d838:	35e5ffff */ 	ori	$a1,$t7,0xffff
/*  f18d83c:	ae05007c */ 	sw	$a1,0x7c($s0)
.L0f18d840:
/*  f18d840:	0fc354be */ 	jal	savefileGetSomething
/*  f18d844:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f18d848:	8e050080 */ 	lw	$a1,0x80($s0)
/*  f18d84c:	3c014000 */ 	lui	$at,0x4000
/*  f18d850:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d854:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d858:	14200003 */ 	bnez	$at,.L0f18d868
/*  f18d85c:	3c183fff */ 	lui	$t8,0x3fff
/*  f18d860:	3705ffff */ 	ori	$a1,$t8,0xffff
/*  f18d864:	ae050080 */ 	sw	$a1,0x80($s0)
.L0f18d868:
/*  f18d868:	0fc354be */ 	jal	savefileGetSomething
/*  f18d86c:	2406001e */ 	addiu	$a2,$zero,0x1e
/*  f18d870:	8e050084 */ 	lw	$a1,0x84($s0)
/*  f18d874:	3c110004 */ 	lui	$s1,0x4
/*  f18d878:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d87c:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d880:	14200004 */ 	bnez	$at,.L0f18d894
/*  f18d884:	24060012 */ 	addiu	$a2,$zero,0x12
/*  f18d888:	3c120003 */ 	lui	$s2,0x3
/*  f18d88c:	3645ffff */ 	ori	$a1,$s2,0xffff
/*  f18d890:	ae050084 */ 	sw	$a1,0x84($s0)
.L0f18d894:
/*  f18d894:	3c120003 */ 	lui	$s2,0x3
/*  f18d898:	0fc354be */ 	jal	savefileGetSomething
/*  f18d89c:	3652ffff */ 	ori	$s2,$s2,0xffff
/*  f18d8a0:	8e050088 */ 	lw	$a1,0x88($s0)
/*  f18d8a4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d8a8:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d8ac:	14200003 */ 	bnez	$at,.L0f18d8bc
/*  f18d8b0:	00000000 */ 	nop
/*  f18d8b4:	ae120088 */ 	sw	$s2,0x88($s0)
/*  f18d8b8:	02402825 */ 	or	$a1,$s2,$zero
.L0f18d8bc:
/*  f18d8bc:	0fc354be */ 	jal	savefileGetSomething
/*  f18d8c0:	24060012 */ 	addiu	$a2,$zero,0x12
/*  f18d8c4:	8e05008c */ 	lw	$a1,0x8c($s0)
/*  f18d8c8:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d8cc:	00b1082b */ 	sltu	$at,$a1,$s1
/*  f18d8d0:	14200003 */ 	bnez	$at,.L0f18d8e0
/*  f18d8d4:	00000000 */ 	nop
/*  f18d8d8:	ae12008c */ 	sw	$s2,0x8c($s0)
/*  f18d8dc:	02402825 */ 	or	$a1,$s2,$zero
.L0f18d8e0:
/*  f18d8e0:	0fc354be */ 	jal	savefileGetSomething
/*  f18d8e4:	24060012 */ 	addiu	$a2,$zero,0x12
/*  f18d8e8:	8e050090 */ 	lw	$a1,0x90($s0)
/*  f18d8ec:	3c010001 */ 	lui	$at,0x1
/*  f18d8f0:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d8f4:	00a1082b */ 	sltu	$at,$a1,$at
/*  f18d8f8:	14200003 */ 	bnez	$at,.L0f18d908
/*  f18d8fc:	00000000 */ 	nop
/*  f18d900:	3405ffff */ 	dli	$a1,0xffff
/*  f18d904:	ae050090 */ 	sw	$a1,0x90($s0)
.L0f18d908:
/*  f18d908:	0fc354be */ 	jal	savefileGetSomething
/*  f18d90c:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f18d910:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d914:	92050044 */ 	lbu	$a1,0x44($s0)
/*  f18d918:	0fc354be */ 	jal	savefileGetSomething
/*  f18d91c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f18d920:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d924:	96050048 */ 	lhu	$a1,0x48($s0)
/*  f18d928:	0fc354be */ 	jal	savefileGetSomething
/*  f18d92c:	2406000c */ 	addiu	$a2,$zero,0xc
/*  f18d930:	00008825 */ 	or	$s1,$zero,$zero
/*  f18d934:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f18d938:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f18d93c:
/*  f18d93c:	02802025 */ 	or	$a0,$s4,$zero
.L0f18d940:
/*  f18d940:	02202825 */ 	or	$a1,$s1,$zero
/*  f18d944:	0fc6711f */ 	jal	mpIsChallengeCompletedByPlayerWithNumPlayers
/*  f18d948:	02003025 */ 	or	$a2,$s0,$zero
/*  f18d94c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d950:	00402825 */ 	or	$a1,$v0,$zero
/*  f18d954:	0fc354be */ 	jal	savefileGetSomething
/*  f18d958:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18d95c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18d960:	5612fff7 */ 	bnel	$s0,$s2,.L0f18d940
/*  f18d964:	02802025 */ 	or	$a0,$s4,$zero
/*  f18d968:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18d96c:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f18d970:	5621fff2 */ 	bnel	$s1,$at,.L0f18d93c
/*  f18d974:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f18d978:	02602025 */ 	or	$a0,$s3,$zero
/*  f18d97c:	0fc6348e */ 	jal	func0f18d238
/*  f18d980:	02802825 */ 	or	$a1,$s4,$zero
/*  f18d984:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f18d988:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18d98c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18d990:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18d994:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18d998:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18d99c:	03e00008 */ 	jr	$ra
/*  f18d9a0:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f18d9a4
/*  f18d9a4:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f18d9a8:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f18d9ac:	00802825 */ 	or	$a1,$a0,$zero
/*  f18d9b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18d9b4:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*  f18d9b8:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f18d9bc:	2406000f */ 	addiu	$a2,$zero,0xf
/*  f18d9c0:	0fc35521 */ 	jal	func0f0d5484
/*  f18d9c4:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18d9c8:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18d9cc:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f18d9d0:	0fc35539 */ 	jal	func0f0d54e4
/*  f18d9d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f18d9d8:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18d9dc:	0fc354fe */ 	jal	savefileGetInteger
/*  f18d9e0:	2405001c */ 	addiu	$a1,$zero,0x1c
/*  f18d9e4:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f18d9e8:	adc20000 */ 	sw	$v0,0x0($t6)
/*  f18d9ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18d9f0:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
/*  f18d9f4:	03e00008 */ 	jr	$ra
/*  f18d9f8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f18d9fc
/*  f18d9fc:	27bdfef8 */ 	addiu	$sp,$sp,-264
/*  f18da00:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f18da04:	afa40108 */ 	sw	$a0,0x108($sp)
/*  f18da08:	afa5010c */ 	sw	$a1,0x10c($sp)
/*  f18da0c:	afa60110 */ 	sw	$a2,0x110($sp)
/*  f18da10:	04a00026 */ 	bltz	$a1,.L0f18daac
/*  f18da14:	afa70114 */ 	sw	$a3,0x114($sp)
/*  f18da18:	0fc35517 */ 	jal	func0f0d545c
/*  f18da1c:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f18da20:	8fa40108 */ 	lw	$a0,0x108($sp)
/*  f18da24:	0fc63571 */ 	jal	func0f18d5c4
/*  f18da28:	27a50020 */ 	addiu	$a1,$sp,0x20
/*  f18da2c:	0fc35531 */ 	jal	func0f0d54c4
/*  f18da30:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f18da34:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18da38:	3c018007 */ 	lui	$at,%hi(g_FileLists+0x18)
/*  f18da3c:	27b80100 */ 	addiu	$t8,$sp,0x100
/*  f18da40:	ac2f5bd8 */ 	sw	$t7,%lo(g_FileLists+0x18)($at)
/*  f18da44:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f18da48:	83a4010f */ 	lb	$a0,0x10f($sp)
/*  f18da4c:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f18da50:	24060020 */ 	addiu	$a2,$zero,0x20
/*  f18da54:	27a70024 */ 	addiu	$a3,$sp,0x24
/*  f18da58:	0fc45a0a */ 	jal	func0f116828
/*  f18da5c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18da60:	1440000e */ 	bnez	$v0,.L0f18da9c
/*  f18da64:	00401825 */ 	or	$v1,$v0,$zero
/*  f18da68:	8fb90108 */ 	lw	$t9,0x108($sp)
/*  f18da6c:	3c09800b */ 	lui	$t1,%hi(g_MpPlayers)
/*  f18da70:	8faa0100 */ 	lw	$t2,0x100($sp)
/*  f18da74:	00194080 */ 	sll	$t0,$t9,0x2
/*  f18da78:	01194021 */ 	addu	$t0,$t0,$t9
/*  f18da7c:	97ab0116 */ 	lhu	$t3,0x116($sp)
/*  f18da80:	00084140 */ 	sll	$t0,$t0,0x5
/*  f18da84:	2529c7b8 */ 	addiu	$t1,$t1,%lo(g_MpPlayers)
/*  f18da88:	01091821 */ 	addu	$v1,$t0,$t1
/*  f18da8c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18da90:	ac6a004c */ 	sw	$t2,0x4c($v1)
/*  f18da94:	10000006 */ 	b	.L0f18dab0
/*  f18da98:	a46b0050 */ 	sh	$t3,0x50($v1)
.L0f18da9c:
/*  f18da9c:	3c01800a */ 	lui	$at,%hi(var800a21f8)
/*  f18daa0:	ac2321f8 */ 	sw	$v1,%lo(var800a21f8)($at)
/*  f18daa4:	10000002 */ 	b	.L0f18dab0
/*  f18daa8:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18daac:
/*  f18daac:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18dab0:
/*  f18dab0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f18dab4:	27bd0108 */ 	addiu	$sp,$sp,0x108
/*  f18dab8:	03e00008 */ 	jr	$ra
/*  f18dabc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f18dac0
/*  f18dac0:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f18dac4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18dac8:	afa40100 */ 	sw	$a0,0x100($sp)
/*  f18dacc:	afa50104 */ 	sw	$a1,0x104($sp)
/*  f18dad0:	afa60108 */ 	sw	$a2,0x108($sp)
/*  f18dad4:	04a00024 */ 	bltz	$a1,.L0f18db68
/*  f18dad8:	afa7010c */ 	sw	$a3,0x10c($sp)
/*  f18dadc:	0fc35517 */ 	jal	func0f0d545c
/*  f18dae0:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f18dae4:	83a40107 */ 	lb	$a0,0x107($sp)
/*  f18dae8:	8fa50108 */ 	lw	$a1,0x108($sp)
/*  f18daec:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f18daf0:	0fc45a00 */ 	jal	func0f116800
/*  f18daf4:	00003825 */ 	or	$a3,$zero,$zero
/*  f18daf8:	14400017 */ 	bnez	$v0,.L0f18db58
/*  f18dafc:	00401825 */ 	or	$v1,$v0,$zero
/*  f18db00:	8fa40100 */ 	lw	$a0,0x100($sp)
/*  f18db04:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f18db08:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f18db0c:	00047880 */ 	sll	$t7,$a0,0x2
/*  f18db10:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f18db14:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f18db18:	8fb90108 */ 	lw	$t9,0x108($sp)
/*  f18db1c:	97a8010e */ 	lhu	$t0,0x10e($sp)
/*  f18db20:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f18db24:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f18db28:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*  f18db2c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18db30:	ac79004c */ 	sw	$t9,0x4c($v1)
/*  f18db34:	0fc634ae */ 	jal	func0f18d2b8
/*  f18db38:	a4680050 */ 	sh	$t0,0x50($v1)
/*  f18db3c:	0fc35531 */ 	jal	func0f0d54c4
/*  f18db40:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f18db44:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f18db48:	24090080 */ 	addiu	$t1,$zero,0x80
/*  f18db4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18db50:	10000006 */ 	b	.L0f18db6c
/*  f18db54:	a069009d */ 	sb	$t1,0x9d($v1)
.L0f18db58:
/*  f18db58:	3c01800a */ 	lui	$at,%hi(var800a21f8)
/*  f18db5c:	ac2321f8 */ 	sw	$v1,%lo(var800a21f8)($at)
/*  f18db60:	10000002 */ 	b	.L0f18db6c
/*  f18db64:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18db68:
/*  f18db68:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18db6c:
/*  f18db6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18db70:	27bd0100 */ 	addiu	$sp,$sp,0x100
/*  f18db74:	03e00008 */ 	jr	$ra
/*  f18db78:	00000000 */ 	nop
);

struct mppreset g_MpPresets[NUM_MPPRESETS] = {
	{ L_MPWEAPONS(25), MPCONFIG_NOSHIELD   }, // "No Shield"
	{ L_MPWEAPONS(26), MPCONFIG_AUTOMATICS }, // "Automatics"
	{ L_MPWEAPONS(27), MPCONFIG_ROCKETS    }, // "Rocket Launcher"
	{ L_MPWEAPONS(28), MPCONFIG_SIMULANTS  }, // "Simulants"
	{ L_MPWEAPONS(29), MPCONFIG_SKEDARKING }, // "King of the Hill"
	{ L_MPWEAPONS(30), MPCONFIG_FARSIGHT   }, // "Complex FarSight"
	{ L_MPWEAPONS(31), MPCONFIG_BRIEFCASE  }, // "Hold the Briefcase"
	{ L_MPWEAPONS(32), MPCONFIG_PISTOLS    }, // "Pistol One-Hit Kills"
	{ L_MPWEAPONS(33), MPCONFIG_FLAGS      }, // "Capture the Case"
	{ L_MPWEAPONS(34), MPCONFIG_CLOAKING   }, // "Cloaking"
	{ L_MPWEAPONS(35), MPCONFIG_TEMPLE     }, // "Temple Explosives"
	{ L_MPWEAPONS(36), MPCONFIG_SLAYER     }, // "Slayer"
	{ L_MPWEAPONS(37), MPCONFIG_DRUGGUN    }, // "Tranquilizr"
	{ L_MPWEAPONS(38), MPCONFIG_SLOWMO     }, // "Slow Motion"
};

s32 mpGetNumPresets(void)
{
	return NUM_MPPRESETS;
}

bool mpIsPresetUnlocked(s32 presetnum)
{
	s32 i;

	for (i = 0; i != 16; i++) {
		if (!mpIsFeatureUnlocked(g_MpPresets[presetnum].requirefeatures[i]) &&
				g_MpPresets[presetnum].requirefeatures[i] != MPFEATURE_WEAPON_SHIELD) {
			return false;
		}
	}

	return true;
}

s32 mpGetNumUnlockedPresets(void)
{
	s32 numunlocked = 0;
	s32 i;

	for (i = 0; i != NUM_MPPRESETS; i++) {
		if (mpIsPresetUnlocked(i)) {
			numunlocked++;
		}
	}

	return numunlocked;
}

char *mpGetPresetNameBySlot(s32 slot)
{
	s32 i;

	for (i = 0; i != 14; i++) {
		if (mpIsPresetUnlocked(i)) {
			if (slot == 0) {
				return langGet(g_MpPresets[i].name);
			}

			slot--;
		}
	}

	return "";
}

const char var7f1b8c40[] = "bot %d headId %d bodyId %d\n";
const char var7f1b8c5c[] = "team change %s %d\n";

#if VERSION >= VERSION_PAL_FINAL
const char var7f1b8c70[] = "options/mplayer.c";
#else
const char var7f1b8c70[] = "mplayer.c";
#endif

const char var7f1b8c7c[] = "team change %s %d\n";

#if VERSION >= VERSION_PAL_FINAL
const char var7f1b8c90[] = "options/mplayer.c";
#else
const char var7f1b8c90[] = "mplayer.c";
#endif

const char var7f1b8c9c[] = "SaveMultiGameFile : PakId=0x%x, FileId=0x%x\n";
const char var7f1b8ccc[] = "SaveGame Result: %d   New GUID: %x\n";
const char var7f1b8cf0[] = "LoadMultiGameFile : PakId=0x%x, FileId=0x%x\n";
const char var7f1b8d20[] = "LoadGame Result: %d\n";
const char var7f1b8d38[] = "GBCHead: Call to create head for slot %d (gbcheadobjs[slotno]=%x)\n";

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f18dcec
/*  f18edb8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f18edbc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18edc0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f18edc4:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f18edc8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f18edcc:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18edd0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18edd4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18edd8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18eddc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18ede0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18ede4:	908e0010 */ 	lbu	$t6,0x10($a0)
/*  f18ede8:	3c10800b */ 	lui	$s0,0x800b
/*  f18edec:	2610d128 */ 	addiu	$s0,$s0,-11992
/*  f18edf0:	0080f025 */ 	move	$s8,$a0
/*  f18edf4:	96120016 */ 	lhu	$s2,0x16($s0)
/*  f18edf8:	0fc61922 */ 	jal	0xf186488
/*  f18edfc:	a20e0010 */ 	sb	$t6,0x10($s0)
/*  f18ee00:	03c0c825 */ 	move	$t9,$s8
/*  f18ee04:	02004025 */ 	move	$t0,$s0
/*  f18ee08:	27d80024 */ 	addiu	$t8,$s8,0x24
.PF0f18ee0c:
/*  f18ee0c:	8f210000 */ 	lw	$at,0x0($t9)
/*  f18ee10:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f18ee14:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f18ee18:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f18ee1c:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f18ee20:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f18ee24:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f18ee28:	1738fff8 */ 	bne	$t9,$t8,.PF0f18ee0c
/*  f18ee2c:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f18ee30:	8f210000 */ 	lw	$at,0x0($t9)
/*  f18ee34:	3c09800b */ 	lui	$t1,0x800b
/*  f18ee38:	2537cd38 */ 	addiu	$s7,$t1,-13000
/*  f18ee3c:	ad010000 */ 	sw	$at,0x0($t0)
/*  f18ee40:	a6120016 */ 	sh	$s2,0x16($s0)
/*  f18ee44:	3c11800b */ 	lui	$s1,0x800b
/*  f18ee48:	2631cad8 */ 	addiu	$s1,$s1,-13608
/*  f18ee4c:	24100004 */ 	li	$s0,0x4
/*  f18ee50:	02e0a825 */ 	move	$s5,$s7
/*  f18ee54:	00009825 */ 	move	$s3,$zero
/*  f18ee58:	03c0a025 */ 	move	$s4,$s8
/*  f18ee5c:	03c0b025 */ 	move	$s6,$s8
.PF0f18ee60:
/*  f18ee60:	928a0028 */ 	lbu	$t2,0x28($s4)
/*  f18ee64:	00001025 */ 	move	$v0,$zero
/*  f18ee68:	02a01825 */ 	move	$v1,$s5
/*  f18ee6c:	02c02025 */ 	move	$a0,$s6
/*  f18ee70:	a22a0047 */ 	sb	$t2,0x47($s1)
.PF0f18ee74:
/*  f18ee74:	908b002c */ 	lbu	$t3,0x2c($a0)
/*  f18ee78:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18ee7c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18ee80:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18ee84:	1450fffb */ 	bne	$v0,$s0,.PF0f18ee74
/*  f18ee88:	a06bffff */ 	sb	$t3,-0x1($v1)
/*  f18ee8c:	92ec0000 */ 	lbu	$t4,0x0($s7)
/*  f18ee90:	3c0d8009 */ 	lui	$t5,0x8009
/*  f18ee94:	24010001 */ 	li	$at,0x1
/*  f18ee98:	a22c0048 */ 	sb	$t4,0x48($s1)
/*  f18ee9c:	91ad1040 */ 	lbu	$t5,0x1040($t5)
/*  f18eea0:	00137100 */ 	sll	$t6,$s3,0x4
/*  f18eea4:	01d37023 */ 	subu	$t6,$t6,$s3
/*  f18eea8:	15a1000a */ 	bne	$t5,$at,.PF0f18eed4
/*  f18eeac:	02202025 */ 	move	$a0,$s1
/*  f18eeb0:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f18eeb4:	240454f2 */ 	li	$a0,0x54f2
/*  f18eeb8:	26720001 */ 	addiu	$s2,$s3,0x1
/*  f18eebc:	02403025 */ 	move	$a2,$s2
/*  f18eec0:	02202025 */ 	move	$a0,$s1
/*  f18eec4:	0c004d11 */ 	jal	0x13444
/*  f18eec8:	00402825 */ 	move	$a1,$v0
/*  f18eecc:	10000006 */ 	b	.PF0f18eee8
/*  f18eed0:	928f0029 */ 	lbu	$t7,0x29($s4)
.PF0f18eed4:
/*  f18eed4:	03ce2821 */ 	addu	$a1,$s8,$t6
/*  f18eed8:	0c004bb0 */ 	jal	0x12ec0
/*  f18eedc:	24a50130 */ 	addiu	$a1,$a1,0x130
/*  f18eee0:	26720001 */ 	addiu	$s2,$s3,0x1
/*  f18eee4:	928f0029 */ 	lbu	$t7,0x29($s4)
.PF0f18eee8:
/*  f18eee8:	2a410008 */ 	slti	$at,$s2,0x8
/*  f18eeec:	02409825 */ 	move	$s3,$s2
/*  f18eef0:	a22f000f */ 	sb	$t7,0xf($s1)
/*  f18eef4:	9298002a */ 	lbu	$t8,0x2a($s4)
/*  f18eef8:	2631004c */ 	addiu	$s1,$s1,0x4c
/*  f18eefc:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f18ef00:	a238ffc4 */ 	sb	$t8,-0x3c($s1)
/*  f18ef04:	92990023 */ 	lbu	$t9,0x23($s4)
/*  f18ef08:	26b50004 */ 	addiu	$s5,$s5,0x4
/*  f18ef0c:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f18ef10:	26f70004 */ 	addiu	$s7,$s7,0x4
/*  f18ef14:	1420ffd2 */ 	bnez	$at,.PF0f18ee60
/*  f18ef18:	a239ffc5 */ 	sb	$t9,-0x3b($s1)
/*  f18ef1c:	0fc67684 */ 	jal	0xf19da10
/*  f18ef20:	24040016 */ 	li	$a0,0x16
/*  f18ef24:	1440000c */ 	bnez	$v0,.PF0f18ef58
/*  f18ef28:	3c04800b */ 	lui	$a0,0x800b
/*  f18ef2c:	3c02800b */ 	lui	$v0,0x800b
/*  f18ef30:	2442d128 */ 	addiu	$v0,$v0,-11992
/*  f18ef34:	2484d12e */ 	addiu	$a0,$a0,-11986
/*  f18ef38:	24030025 */ 	li	$v1,0x25
/*  f18ef3c:	90480018 */ 	lbu	$t0,0x18($v0)
.PF0f18ef40:
/*  f18ef40:	54680003 */ 	bnel	$v1,$t0,.PF0f18ef50
/*  f18ef44:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18ef48:	a0400018 */ 	sb	$zero,0x18($v0)
/*  f18ef4c:	24420001 */ 	addiu	$v0,$v0,0x1
.PF0f18ef50:
/*  f18ef50:	5444fffb */ 	bnel	$v0,$a0,.PF0f18ef40
/*  f18ef54:	90480018 */ 	lbu	$t0,0x18($v0)
.PF0f18ef58:
/*  f18ef58:	0fc62878 */ 	jal	0xf18a1e0
/*  f18ef5c:	00000000 */ 	nop
/*  f18ef60:	0fc674a4 */ 	jal	0xf19d290
/*  f18ef64:	00000000 */ 	nop
/*  f18ef68:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f18ef6c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18ef70:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18ef74:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18ef78:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18ef7c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18ef80:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18ef84:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18ef88:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f18ef8c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f18ef90:	03e00008 */ 	jr	$ra
/*  f18ef94:	27bd0040 */ 	addiu	$sp,$sp,0x40
);
#else
GLOBAL_ASM(
glabel func0f18dcec
/*  f18dcec:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f18dcf0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18dcf4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f18dcf8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f18dcfc:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f18dd00:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18dd04:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18dd08:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18dd0c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18dd10:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18dd14:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18dd18:	908e0010 */ 	lbu	$t6,0x10($a0)
/*  f18dd1c:	3c10800b */ 	lui	$s0,%hi(g_MpSetup)
/*  f18dd20:	2610cb88 */ 	addiu	$s0,$s0,%lo(g_MpSetup)
/*  f18dd24:	0080f025 */ 	or	$s8,$a0,$zero
/*  f18dd28:	0fc61521 */ 	jal	scenarioInit
/*  f18dd2c:	a20e0010 */ 	sb	$t6,0x10($s0)
/*  f18dd30:	03c0c825 */ 	or	$t9,$s8,$zero
/*  f18dd34:	02004025 */ 	or	$t0,$s0,$zero
/*  f18dd38:	27d80024 */ 	addiu	$t8,$s8,0x24
.L0f18dd3c:
/*  f18dd3c:	8f210000 */ 	lw	$at,0x0($t9)
/*  f18dd40:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f18dd44:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f18dd48:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f18dd4c:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f18dd50:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f18dd54:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f18dd58:	1738fff8 */ 	bne	$t9,$t8,.L0f18dd3c
/*  f18dd5c:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f18dd60:	8f210000 */ 	lw	$at,0x0($t9)
/*  f18dd64:	3c09800b */ 	lui	$t1,%hi(g_MpSimulantDifficultiesPerNumPlayers)
/*  f18dd68:	2537c798 */ 	addiu	$s7,$t1,%lo(g_MpSimulantDifficultiesPerNumPlayers)
/*  f18dd6c:	3c11800b */ 	lui	$s1,%hi(g_MpSimulants)
/*  f18dd70:	2631c538 */ 	addiu	$s1,$s1,%lo(g_MpSimulants)
/*  f18dd74:	02e0a825 */ 	or	$s5,$s7,$zero
/*  f18dd78:	00009825 */ 	or	$s3,$zero,$zero
/*  f18dd7c:	03c0a025 */ 	or	$s4,$s8,$zero
/*  f18dd80:	03c0b025 */ 	or	$s6,$s8,$zero
/*  f18dd84:	24100004 */ 	addiu	$s0,$zero,0x4
/*  f18dd88:	ad010000 */ 	sw	$at,0x0($t0)
.L0f18dd8c:
/*  f18dd8c:	928a0028 */ 	lbu	$t2,0x28($s4)
/*  f18dd90:	00001025 */ 	or	$v0,$zero,$zero
/*  f18dd94:	02a01825 */ 	or	$v1,$s5,$zero
/*  f18dd98:	02c02025 */ 	or	$a0,$s6,$zero
/*  f18dd9c:	a22a0047 */ 	sb	$t2,0x47($s1)
.L0f18dda0:
/*  f18dda0:	908b002c */ 	lbu	$t3,0x2c($a0)
/*  f18dda4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18dda8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18ddac:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18ddb0:	1450fffb */ 	bne	$v0,$s0,.L0f18dda0
/*  f18ddb4:	a06bffff */ 	sb	$t3,-0x1($v1)
/*  f18ddb8:	92ec0000 */ 	lbu	$t4,0x0($s7)
/*  f18ddbc:	3c0d8009 */ 	lui	$t5,%hi(g_Is4Mb)
/*  f18ddc0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18ddc4:	a22c0048 */ 	sb	$t4,0x48($s1)
/*  f18ddc8:	91ad0af0 */ 	lbu	$t5,%lo(g_Is4Mb)($t5)
/*  f18ddcc:	00137100 */ 	sll	$t6,$s3,0x4
/*  f18ddd0:	01d37023 */ 	subu	$t6,$t6,$s3
/*  f18ddd4:	15a1000a */ 	bne	$t5,$at,.L0f18de00
/*  f18ddd8:	02202025 */ 	or	$a0,$s1,$zero
/*  f18dddc:	0fc5b9f1 */ 	jal	langGet
/*  f18dde0:	240454f1 */ 	addiu	$a0,$zero,0x54f1
/*  f18dde4:	26720001 */ 	addiu	$s2,$s3,0x1
/*  f18dde8:	02403025 */ 	or	$a2,$s2,$zero
/*  f18ddec:	02202025 */ 	or	$a0,$s1,$zero
/*  f18ddf0:	0c004dad */ 	jal	sprintf
/*  f18ddf4:	00402825 */ 	or	$a1,$v0,$zero
/*  f18ddf8:	10000006 */ 	b	.L0f18de14
/*  f18ddfc:	928f0029 */ 	lbu	$t7,0x29($s4)
.L0f18de00:
/*  f18de00:	03ce2821 */ 	addu	$a1,$s8,$t6
/*  f18de04:	0c004c4c */ 	jal	strcpy
/*  f18de08:	24a50130 */ 	addiu	$a1,$a1,0x130
/*  f18de0c:	26720001 */ 	addiu	$s2,$s3,0x1
/*  f18de10:	928f0029 */ 	lbu	$t7,0x29($s4)
.L0f18de14:
/*  f18de14:	2a410008 */ 	slti	$at,$s2,0x8
/*  f18de18:	02409825 */ 	or	$s3,$s2,$zero
/*  f18de1c:	a22f000f */ 	sb	$t7,0xf($s1)
/*  f18de20:	9298002a */ 	lbu	$t8,0x2a($s4)
/*  f18de24:	2631004c */ 	addiu	$s1,$s1,0x4c
/*  f18de28:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f18de2c:	a238ffc4 */ 	sb	$t8,-0x3c($s1)
/*  f18de30:	92990023 */ 	lbu	$t9,0x23($s4)
/*  f18de34:	26b50004 */ 	addiu	$s5,$s5,0x4
/*  f18de38:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f18de3c:	26f70004 */ 	addiu	$s7,$s7,0x4
/*  f18de40:	1420ffd2 */ 	bnez	$at,.L0f18dd8c
/*  f18de44:	a239ffc5 */ 	sb	$t9,-0x3b($s1)
/*  f18de48:	0fc67244 */ 	jal	mpIsFeatureUnlocked
/*  f18de4c:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f18de50:	1440000c */ 	bnez	$v0,.L0f18de84
/*  f18de54:	3c04800b */ 	lui	$a0,%hi(g_MpSetup+0x6)
/*  f18de58:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f18de5c:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f18de60:	2484cb8e */ 	addiu	$a0,$a0,%lo(g_MpSetup+0x6)
/*  f18de64:	24030025 */ 	addiu	$v1,$zero,0x25
/*  f18de68:	90480018 */ 	lbu	$t0,0x18($v0)
.L0f18de6c:
/*  f18de6c:	54680003 */ 	bnel	$v1,$t0,.L0f18de7c
/*  f18de70:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18de74:	a0400018 */ 	sb	$zero,0x18($v0)
/*  f18de78:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f18de7c:
/*  f18de7c:	5444fffb */ 	bnel	$v0,$a0,.L0f18de6c
/*  f18de80:	90480018 */ 	lbu	$t0,0x18($v0)
.L0f18de84:
/*  f18de84:	0fc6244f */ 	jal	func0f18913c
/*  f18de88:	00000000 */ 	nop
/*  f18de8c:	0fc67064 */ 	jal	func0f19c190
/*  f18de90:	00000000 */ 	nop
/*  f18de94:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f18de98:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18de9c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18dea0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18dea4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18dea8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18deac:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18deb0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18deb4:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f18deb8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f18debc:	03e00008 */ 	jr	$ra
/*  f18dec0:	27bd0040 */ 	addiu	$sp,$sp,0x40
);
#endif

GLOBAL_ASM(
glabel func0f18dec4
/*  f18dec4:	27bdfe00 */ 	addiu	$sp,$sp,-512
/*  f18dec8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18decc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18ded0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18ded4:	00808825 */ 	or	$s1,$a0,$zero
/*  f18ded8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18dedc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f18dee0:	00008025 */ 	or	$s0,$zero,$zero
/*  f18dee4:	2412000e */ 	addiu	$s2,$zero,0xe
.L0f18dee8:
/*  f18dee8:	0fc636e1 */ 	jal	mpIsPresetUnlocked
/*  f18deec:	02002025 */ 	or	$a0,$s0,$zero
/*  f18def0:	5040000c */ 	beqzl	$v0,.L0f18df24
/*  f18def4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18def8:	16200008 */ 	bnez	$s1,.L0f18df1c
/*  f18defc:	00107080 */ 	sll	$t6,$s0,0x2
/*  f18df00:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f18df04:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f18df08:	3c0f8008 */ 	lui	$t7,%hi(g_MpPresets+0x4)
/*  f18df0c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f18df10:	8def7b70 */ 	lw	$t7,%lo(g_MpPresets+0x4)($t7)
/*  f18df14:	10000005 */ 	b	.L0f18df2c
/*  f18df18:	afaf002c */ 	sw	$t7,0x2c($sp)
.L0f18df1c:
/*  f18df1c:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f18df20:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18df24:
/*  f18df24:	1612fff0 */ 	bne	$s0,$s2,.L0f18dee8
/*  f18df28:	00000000 */ 	nop
.L0f18df2c:
/*  f18df2c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f18df30:	27a50030 */ 	addiu	$a1,$sp,0x30
/*  f18df34:	0fc66e45 */ 	jal	mpLoadConfig
/*  f18df38:	240601ca */ 	addiu	$a2,$zero,0x1ca
/*  f18df3c:	0fc6373b */ 	jal	func0f18dcec
/*  f18df40:	00402025 */ 	or	$a0,$v0,$zero
/*  f18df44:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18df48:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18df4c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18df50:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18df54:	03e00008 */ 	jr	$ra
/*  f18df58:	27bd0200 */ 	addiu	$sp,$sp,0x200
);

GLOBAL_ASM(
glabel func0f18df5c
/*  f18df5c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f18df60:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18df64:	3c15800b */ 	lui	$s5,%hi(g_MpSetup)
/*  f18df68:	26b5cb88 */ 	addiu	$s5,$s5,%lo(g_MpSetup)
/*  f18df6c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f18df70:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18df74:	00809825 */ 	or	$s3,$a0,$zero
/*  f18df78:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18df7c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18df80:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18df84:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18df88:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18df8c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f18df90:	0fc35539 */ 	jal	func0f0d54e4
/*  f18df94:	00003025 */ 	or	$a2,$zero,$zero
/*  f18df98:	02602025 */ 	or	$a0,$s3,$zero
/*  f18df9c:	0fc354fe */ 	jal	savefileGetInteger
/*  f18dfa0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f18dfa4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18dfa8:	0fc354fe */ 	jal	savefileGetInteger
/*  f18dfac:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18dfb0:	a2a20011 */ 	sb	$v0,0x11($s5)
/*  f18dfb4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18dfb8:	0fc354fe */ 	jal	savefileGetInteger
/*  f18dfbc:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18dfc0:	0fc61521 */ 	jal	scenarioInit
/*  f18dfc4:	a2a20010 */ 	sb	$v0,0x10($s5)
/*  f18dfc8:	0fc614f4 */ 	jal	scenarioCallback40
/*  f18dfcc:	02602025 */ 	or	$a0,$s3,$zero
/*  f18dfd0:	02602025 */ 	or	$a0,$s3,$zero
/*  f18dfd4:	0fc354fe */ 	jal	savefileGetInteger
/*  f18dfd8:	24050015 */ 	addiu	$a1,$zero,0x15
/*  f18dfdc:	96ae0016 */ 	lhu	$t6,0x16($s5)
/*  f18dfe0:	3c11800b */ 	lui	$s1,%hi(g_MpSimulants)
/*  f18dfe4:	3c14800b */ 	lui	$s4,%hi(g_MpSimulantDifficultiesPerNumPlayers)
/*  f18dfe8:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f18dfec:	aea2000c */ 	sw	$v0,0xc($s5)
/*  f18dff0:	a6af0016 */ 	sh	$t7,0x16($s5)
/*  f18dff4:	2694c798 */ 	addiu	$s4,$s4,%lo(g_MpSimulantDifficultiesPerNumPlayers)
/*  f18dff8:	2631c538 */ 	addiu	$s1,$s1,%lo(g_MpSimulants)
/*  f18dffc:	00009025 */ 	or	$s2,$zero,$zero
/*  f18e000:	24160006 */ 	addiu	$s6,$zero,0x6
/*  f18e004:	24100004 */ 	addiu	$s0,$zero,0x4
.L0f18e008:
/*  f18e008:	a2200000 */ 	sb	$zero,0x0($s1)
/*  f18e00c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e010:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e014:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f18e018:	a2220047 */ 	sb	$v0,0x47($s1)
/*  f18e01c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e020:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e024:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18e028:	a2220048 */ 	sb	$v0,0x48($s1)
/*  f18e02c:	00001825 */ 	or	$v1,$zero,$zero
/*  f18e030:	02802025 */ 	or	$a0,$s4,$zero
/*  f18e034:	304500ff */ 	andi	$a1,$v0,0xff
.L0f18e038:
/*  f18e038:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18e03c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18e040:	1470fffd */ 	bne	$v1,$s0,.L0f18e038
/*  f18e044:	a085ffff */ 	sb	$a1,-0x1($a0)
/*  f18e048:	12c50007 */ 	beq	$s6,$a1,.L0f18e068
/*  f18e04c:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e050:	96b80016 */ 	lhu	$t8,0x16($s5)
/*  f18e054:	26590004 */ 	addiu	$t9,$s2,0x4
/*  f18e058:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f18e05c:	03284804 */ 	sllv	$t1,$t0,$t9
/*  f18e060:	03095025 */ 	or	$t2,$t8,$t1
/*  f18e064:	a6aa0016 */ 	sh	$t2,0x16($s5)
.L0f18e068:
/*  f18e068:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e06c:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18e070:	a222000f */ 	sb	$v0,0xf($s1)
/*  f18e074:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e078:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e07c:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18e080:	a2220010 */ 	sb	$v0,0x10($s1)
/*  f18e084:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e088:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e08c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18e090:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18e094:	2a410008 */ 	slti	$at,$s2,0x8
/*  f18e098:	2631004c */ 	addiu	$s1,$s1,0x4c
/*  f18e09c:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f18e0a0:	1420ffd9 */ 	bnez	$at,.L0f18e008
/*  f18e0a4:	a222ffc5 */ 	sb	$v0,-0x3b($s1)
/*  f18e0a8:	0fc63377 */ 	jal	func0f18cddc
/*  f18e0ac:	00000000 */ 	nop
/*  f18e0b0:	3c10800b */ 	lui	$s0,%hi(g_MpSetup)
/*  f18e0b4:	3c11800b */ 	lui	$s1,%hi(g_MpSetup+0x6)
/*  f18e0b8:	2631cb8e */ 	addiu	$s1,$s1,%lo(g_MpSetup+0x6)
/*  f18e0bc:	2610cb88 */ 	addiu	$s0,$s0,%lo(g_MpSetup)
.L0f18e0c0:
/*  f18e0c0:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e0c4:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e0c8:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18e0cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18e0d0:	0211082b */ 	sltu	$at,$s0,$s1
/*  f18e0d4:	1420fffa */ 	bnez	$at,.L0f18e0c0
/*  f18e0d8:	a2020017 */ 	sb	$v0,0x17($s0)
/*  f18e0dc:	0fc6244f */ 	jal	func0f18913c
/*  f18e0e0:	00000000 */ 	nop
/*  f18e0e4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e0e8:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e0ec:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f18e0f0:	a2a20012 */ 	sb	$v0,0x12($s5)
/*  f18e0f4:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e0f8:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e0fc:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18e100:	a2a20013 */ 	sb	$v0,0x13($s5)
/*  f18e104:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e108:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e10c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f18e110:	3c10800b */ 	lui	$s0,%hi(g_MpPlayers)
/*  f18e114:	3c11800b */ 	lui	$s1,%hi(g_MpPlayers+0x280)
/*  f18e118:	a6a20014 */ 	sh	$v0,0x14($s5)
/*  f18e11c:	2631ca38 */ 	addiu	$s1,$s1,%lo(g_MpPlayers+0x280)
/*  f18e120:	2610c7b8 */ 	addiu	$s0,$s0,%lo(g_MpPlayers)
.L0f18e124:
/*  f18e124:	02602025 */ 	or	$a0,$s3,$zero
/*  f18e128:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e12c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18e130:	261000a0 */ 	addiu	$s0,$s0,0xa0
/*  f18e134:	1611fffb */ 	bne	$s0,$s1,.L0f18e124
/*  f18e138:	a202ff71 */ 	sb	$v0,-0x8f($s0)
/*  f18e13c:	0fc66fe8 */ 	jal	mpForceUnlockSimulantFeatures
/*  f18e140:	00000000 */ 	nop
/*  f18e144:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18e148:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18e14c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18e150:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18e154:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18e158:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18e15c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18e160:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18e164:	03e00008 */ 	jr	$ra
/*  f18e168:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f18e16c
/*  f18e16c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f18e170:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f18e174:	3c13800b */ 	lui	$s3,%hi(g_MpSetup)
/*  f18e178:	2673cb88 */ 	addiu	$s3,$s3,%lo(g_MpSetup)
/*  f18e17c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18e180:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f18e184:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18e188:	00809025 */ 	or	$s2,$a0,$zero
/*  f18e18c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18e190:	00008025 */ 	or	$s0,$zero,$zero
/*  f18e194:	0fc35569 */ 	jal	func0f0d55a4
/*  f18e198:	02602825 */ 	or	$a1,$s3,$zero
/*  f18e19c:	00008825 */ 	or	$s1,$zero,$zero
/*  f18e1a0:	96620016 */ 	lhu	$v0,0x16($s3)
/*  f18e1a4:	262e0004 */ 	addiu	$t6,$s1,0x4
.L0f18e1a8:
/*  f18e1a8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18e1ac:	01cfc004 */ 	sllv	$t8,$t7,$t6
/*  f18e1b0:	0058c824 */ 	and	$t9,$v0,$t8
/*  f18e1b4:	13200002 */ 	beqz	$t9,.L0f18e1c0
/*  f18e1b8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18e1bc:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18e1c0:
/*  f18e1c0:	2a210008 */ 	slti	$at,$s1,0x8
/*  f18e1c4:	5420fff8 */ 	bnezl	$at,.L0f18e1a8
/*  f18e1c8:	262e0004 */ 	addiu	$t6,$s1,0x4
/*  f18e1cc:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e1d0:	02002825 */ 	or	$a1,$s0,$zero
/*  f18e1d4:	0fc354be */ 	jal	savefileGetSomething
/*  f18e1d8:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f18e1dc:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e1e0:	92650011 */ 	lbu	$a1,0x11($s3)
/*  f18e1e4:	0fc354be */ 	jal	savefileGetSomething
/*  f18e1e8:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18e1ec:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e1f0:	92650010 */ 	lbu	$a1,0x10($s3)
/*  f18e1f4:	0fc354be */ 	jal	savefileGetSomething
/*  f18e1f8:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f18e1fc:	0fc6150a */ 	jal	scenarioCallback44
/*  f18e200:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e204:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e208:	8e65000c */ 	lw	$a1,0xc($s3)
/*  f18e20c:	0fc354be */ 	jal	savefileGetSomething
/*  f18e210:	24060015 */ 	addiu	$a2,$zero,0x15
/*  f18e214:	3c10800b */ 	lui	$s0,%hi(g_MpSimulants)
/*  f18e218:	2610c538 */ 	addiu	$s0,$s0,%lo(g_MpSimulants)
/*  f18e21c:	00008825 */ 	or	$s1,$zero,$zero
.L0f18e220:
/*  f18e220:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e224:	92050047 */ 	lbu	$a1,0x47($s0)
/*  f18e228:	0fc354be */ 	jal	savefileGetSomething
/*  f18e22c:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f18e230:	96680016 */ 	lhu	$t0,0x16($s3)
/*  f18e234:	26290004 */ 	addiu	$t1,$s1,0x4
/*  f18e238:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f18e23c:	012a5804 */ 	sllv	$t3,$t2,$t1
/*  f18e240:	010b6024 */ 	and	$t4,$t0,$t3
/*  f18e244:	11800007 */ 	beqz	$t4,.L0f18e264
/*  f18e248:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e24c:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e250:	92050048 */ 	lbu	$a1,0x48($s0)
/*  f18e254:	0fc354be */ 	jal	savefileGetSomething
/*  f18e258:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f18e25c:	10000005 */ 	b	.L0f18e274
/*  f18e260:	02402025 */ 	or	$a0,$s2,$zero
.L0f18e264:
/*  f18e264:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f18e268:	0fc354be */ 	jal	savefileGetSomething
/*  f18e26c:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f18e270:	02402025 */ 	or	$a0,$s2,$zero
.L0f18e274:
/*  f18e274:	9205000f */ 	lbu	$a1,0xf($s0)
/*  f18e278:	0fc354be */ 	jal	savefileGetSomething
/*  f18e27c:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18e280:	92020010 */ 	lbu	$v0,0x10($s0)
/*  f18e284:	240100ff */ 	addiu	$at,$zero,0xff
/*  f18e288:	1441000f */ 	bne	$v0,$at,.L0f18e2c8
/*  f18e28c:	00402825 */ 	or	$a1,$v0,$zero
/*  f18e290:	92040047 */ 	lbu	$a0,0x47($s0)
/*  f18e294:	0fc6335a */ 	jal	mpGetSimTypeIndex
/*  f18e298:	92050048 */ 	lbu	$a1,0x48($s0)
/*  f18e29c:	04400004 */ 	bltz	$v0,.L0f18e2b0
/*  f18e2a0:	00401825 */ 	or	$v1,$v0,$zero
/*  f18e2a4:	28410012 */ 	slti	$at,$v0,0x12
/*  f18e2a8:	54200003 */ 	bnezl	$at,.L0f18e2b8
/*  f18e2ac:	000368c0 */ 	sll	$t5,$v1,0x3
.L0f18e2b0:
/*  f18e2b0:	00001825 */ 	or	$v1,$zero,$zero
/*  f18e2b4:	000368c0 */ 	sll	$t5,$v1,0x3
.L0f18e2b8:
/*  f18e2b8:	3c058008 */ 	lui	$a1,%hi(g_MpSimulantTypes+0x4)
/*  f18e2bc:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f18e2c0:	10000001 */ 	b	.L0f18e2c8
/*  f18e2c4:	84a57730 */ 	lh	$a1,%lo(g_MpSimulantTypes+0x4)($a1)
.L0f18e2c8:
/*  f18e2c8:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e2cc:	0fc354be */ 	jal	savefileGetSomething
/*  f18e2d0:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18e2d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e2d8:	92050011 */ 	lbu	$a1,0x11($s0)
/*  f18e2dc:	0fc354be */ 	jal	savefileGetSomething
/*  f18e2e0:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f18e2e4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18e2e8:	2a210008 */ 	slti	$at,$s1,0x8
/*  f18e2ec:	1420ffcc */ 	bnez	$at,.L0f18e220
/*  f18e2f0:	2610004c */ 	addiu	$s0,$s0,0x4c
/*  f18e2f4:	3c10800b */ 	lui	$s0,%hi(g_MpSetup)
/*  f18e2f8:	3c11800b */ 	lui	$s1,%hi(g_MpSetup+0x6)
/*  f18e2fc:	2631cb8e */ 	addiu	$s1,$s1,%lo(g_MpSetup+0x6)
/*  f18e300:	2610cb88 */ 	addiu	$s0,$s0,%lo(g_MpSetup)
/*  f18e304:	02402025 */ 	or	$a0,$s2,$zero
.L0f18e308:
/*  f18e308:	92050018 */ 	lbu	$a1,0x18($s0)
/*  f18e30c:	0fc354be */ 	jal	savefileGetSomething
/*  f18e310:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18e314:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18e318:	0211082b */ 	sltu	$at,$s0,$s1
/*  f18e31c:	5420fffa */ 	bnezl	$at,.L0f18e308
/*  f18e320:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e324:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e328:	92650012 */ 	lbu	$a1,0x12($s3)
/*  f18e32c:	0fc354be */ 	jal	savefileGetSomething
/*  f18e330:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f18e334:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e338:	92650013 */ 	lbu	$a1,0x13($s3)
/*  f18e33c:	0fc354be */ 	jal	savefileGetSomething
/*  f18e340:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f18e344:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e348:	96650014 */ 	lhu	$a1,0x14($s3)
/*  f18e34c:	0fc354be */ 	jal	savefileGetSomething
/*  f18e350:	24060009 */ 	addiu	$a2,$zero,0x9
/*  f18e354:	3c10800b */ 	lui	$s0,%hi(g_MpPlayers)
/*  f18e358:	3c11800b */ 	lui	$s1,%hi(g_MpPlayers+0x280)
/*  f18e35c:	2631ca38 */ 	addiu	$s1,$s1,%lo(g_MpPlayers+0x280)
/*  f18e360:	2610c7b8 */ 	addiu	$s0,$s0,%lo(g_MpPlayers)
/*  f18e364:	02402025 */ 	or	$a0,$s2,$zero
.L0f18e368:
/*  f18e368:	92050011 */ 	lbu	$a1,0x11($s0)
/*  f18e36c:	0fc354be */ 	jal	savefileGetSomething
/*  f18e370:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f18e374:	261000a0 */ 	addiu	$s0,$s0,0xa0
/*  f18e378:	5611fffb */ 	bnel	$s0,$s1,.L0f18e368
/*  f18e37c:	02402025 */ 	or	$a0,$s2,$zero
/*  f18e380:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f18e384:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18e388:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18e38c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f18e390:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18e394:	03e00008 */ 	jr	$ra
/*  f18e398:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f18e39c
/*  f18e39c:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f18e3a0:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f18e3a4:	00802825 */ 	or	$a1,$a0,$zero
/*  f18e3a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18e3ac:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*  f18e3b0:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f18e3b4:	afa70104 */ 	sw	$a3,0x104($sp)
/*  f18e3b8:	2406000f */ 	addiu	$a2,$zero,0xf
/*  f18e3bc:	0fc35521 */ 	jal	func0f0d5484
/*  f18e3c0:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18e3c4:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18e3c8:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f18e3cc:	0fc35539 */ 	jal	func0f0d54e4
/*  f18e3d0:	00003025 */ 	or	$a2,$zero,$zero
/*  f18e3d4:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18e3d8:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e3dc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f18e3e0:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f18e3e4:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18e3e8:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f18e3ec:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e3f0:	a5c20000 */ 	sh	$v0,0x0($t6)
/*  f18e3f4:	8faf0104 */ 	lw	$t7,0x104($sp)
/*  f18e3f8:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f18e3fc:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18e400:	0fc354fe */ 	jal	savefileGetInteger
/*  f18e404:	a5e20000 */ 	sh	$v0,0x0($t7)
/*  f18e408:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f18e40c:	a7020000 */ 	sh	$v0,0x0($t8)
/*  f18e410:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18e414:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
/*  f18e418:	03e00008 */ 	jr	$ra
/*  f18e41c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f18e420
/*  f18e420:	27bdfef8 */ 	addiu	$sp,$sp,-264
/*  f18e424:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f18e428:	afa40108 */ 	sw	$a0,0x108($sp)
/*  f18e42c:	afa5010c */ 	sw	$a1,0x10c($sp)
/*  f18e430:	04800020 */ 	bltz	$a0,.L0f18e4b4
/*  f18e434:	afa60110 */ 	sw	$a2,0x110($sp)
/*  f18e438:	0fc35517 */ 	jal	func0f0d545c
/*  f18e43c:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f18e440:	0fc6385b */ 	jal	func0f18e16c
/*  f18e444:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f18e448:	0fc35531 */ 	jal	func0f0d54c4
/*  f18e44c:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f18e450:	27af0100 */ 	addiu	$t7,$sp,0x100
/*  f18e454:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f18e458:	83a4010b */ 	lb	$a0,0x10b($sp)
/*  f18e45c:	8fa5010c */ 	lw	$a1,0x10c($sp)
/*  f18e460:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f18e464:	27a70024 */ 	addiu	$a3,$sp,0x24
/*  f18e468:	0fc45a0a */ 	jal	func0f116828
/*  f18e46c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f18e470:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18e474:	3c018007 */ 	lui	$at,%hi(g_FileLists+0x14)
/*  f18e478:	00401825 */ 	or	$v1,$v0,$zero
/*  f18e47c:	14400009 */ 	bnez	$v0,.L0f18e4a4
/*  f18e480:	ac385bd4 */ 	sw	$t8,%lo(g_FileLists+0x14)($at)
/*  f18e484:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f18e488:	97a80112 */ 	lhu	$t0,0x112($sp)
/*  f18e48c:	3c03800b */ 	lui	$v1,%hi(g_MpSetup)
/*  f18e490:	2463cb88 */ 	addiu	$v1,$v1,%lo(g_MpSetup)
/*  f18e494:	00001025 */ 	or	$v0,$zero,$zero
/*  f18e498:	ac790020 */ 	sw	$t9,0x20($v1)
/*  f18e49c:	10000006 */ 	b	.L0f18e4b8
/*  f18e4a0:	a4680024 */ 	sh	$t0,0x24($v1)
.L0f18e4a4:
/*  f18e4a4:	3c01800a */ 	lui	$at,%hi(var800a21f8)
/*  f18e4a8:	ac2321f8 */ 	sw	$v1,%lo(var800a21f8)($at)
/*  f18e4ac:	10000002 */ 	b	.L0f18e4b8
/*  f18e4b0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18e4b4:
/*  f18e4b4:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18e4b8:
/*  f18e4b8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f18e4bc:	27bd0108 */ 	addiu	$sp,$sp,0x108
/*  f18e4c0:	03e00008 */ 	jr	$ra
/*  f18e4c4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f18e4c8
/*  f18e4c8:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f18e4cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f18e4d0:	afa40100 */ 	sw	$a0,0x100($sp)
/*  f18e4d4:	afa50104 */ 	sw	$a1,0x104($sp)
/*  f18e4d8:	0480001a */ 	bltz	$a0,.L0f18e544
/*  f18e4dc:	afa60108 */ 	sw	$a2,0x108($sp)
/*  f18e4e0:	0fc35517 */ 	jal	func0f0d545c
/*  f18e4e4:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f18e4e8:	83a40103 */ 	lb	$a0,0x103($sp)
/*  f18e4ec:	8fa50104 */ 	lw	$a1,0x104($sp)
/*  f18e4f0:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f18e4f4:	0fc45a00 */ 	jal	func0f116800
/*  f18e4f8:	00003825 */ 	or	$a3,$zero,$zero
/*  f18e4fc:	1440000d */ 	bnez	$v0,.L0f18e534
/*  f18e500:	00401825 */ 	or	$v1,$v0,$zero
/*  f18e504:	8faf0104 */ 	lw	$t7,0x104($sp)
/*  f18e508:	97b8010a */ 	lhu	$t8,0x10a($sp)
/*  f18e50c:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*  f18e510:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*  f18e514:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f18e518:	ac4f0020 */ 	sw	$t7,0x20($v0)
/*  f18e51c:	0fc637d7 */ 	jal	func0f18df5c
/*  f18e520:	a4580024 */ 	sh	$t8,0x24($v0)
/*  f18e524:	0fc35531 */ 	jal	func0f0d54c4
/*  f18e528:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f18e52c:	10000006 */ 	b	.L0f18e548
/*  f18e530:	00001025 */ 	or	$v0,$zero,$zero
.L0f18e534:
/*  f18e534:	3c01800a */ 	lui	$at,%hi(var800a21f8)
/*  f18e538:	ac2321f8 */ 	sw	$v1,%lo(var800a21f8)($at)
/*  f18e53c:	10000002 */ 	b	.L0f18e548
/*  f18e540:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18e544:
/*  f18e544:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f18e548:
/*  f18e548:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f18e54c:	27bd0100 */ 	addiu	$sp,$sp,0x100
/*  f18e550:	03e00008 */ 	jr	$ra
/*  f18e554:	00000000 */ 	nop
);

void func0f18e558(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800acc28); i++) {
		var800acc28[i] = 0;
	}
}

u32 func0f18e57c(u32 index, u32 arg1)
{
	return var800acc28[index];
}
