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
#include "game/lv.h"
#include "game/music.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/mpstats.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "bss.h"
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

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b8a00[] = "||||||||||||| Starting game... players %d\n";
#endif

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
	/*0x0b*/ { WEAPON_CALLISTO,         0x02, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_CALLISTO,        MODEL_CHRMAIANSMG,      0x0100 },
	/*0x0c*/ { WEAPON_RCP120,           0x02, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_RCP120,          MODEL_CHRRCP120,        0x0100 },
	/*0x0d*/ { WEAPON_LAPTOPGUN,        0x02, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_LAPTOPGUN,       MODEL_CHRPCGUN,         0x0100 },
	/*0x0e*/ { WEAPON_DRAGON,           0x04, 0x96, 0x00, 0x00, 1, 0,                                MODEL_CHRDRAGON,        0x0100 },
	/*0x0f*/ { WEAPON_K7AVENGER,        0x04, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_K7AVENGER,       MODEL_CHRAVENGER,       0x0100 },
	/*0x10*/ { WEAPON_AR34,             0x04, 0x64, 0x00, 0x00, 1, 0,                                MODEL_CHRAR34,          0x0100 },
	/*0x11*/ { WEAPON_SUPERDRAGON,      0x04, 0x96, 0x0b, 0x10, 1, MPFEATURE_WEAPON_SUPERDRAGON,     MODEL_CHRSUPERDRAGON,   0x0100 },
	/*0x12*/ { WEAPON_SHOTGUN,          0x05, 0x10, 0x00, 0x00, 1, MPFEATURE_WEAPON_SHOTGUN,         MODEL_CHRSHOTGUN,       0x0100 },
	/*0x13*/ { WEAPON_REAPER,           0x0f, 0xc8, 0x00, 0x00, 1, MPFEATURE_WEAPON_REAPER,          MODEL_CHRSKMINIGUN,     0x0100 },
	/*0x14*/ { WEAPON_SNIPERRIFLE,      0x04, 0x32, 0x00, 0x00, 1, 0,                                MODEL_CHRSNIPERRIFLE,   0x0100 },
	/*0x15*/ { WEAPON_FARSIGHT,         0x06, 0x0a, 0x00, 0x00, 1, MPFEATURE_WEAPON_FARSIGHT,        MODEL_CHRZ2020,         0x0100 },
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
f32 mpHandicapToDamageScale(u8 value)
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

#if VERSION >= VERSION_NTSC_1_0
		g_MpPlayerChrs[i] = NULL;
#endif
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
		sprintf(g_MpPlayers[playernum].base.name, "%s %d\n", langGet(L_MISC_437), playernum + 1);
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
/*  f18932c:	0fc5bdaa */ 	jal	langGet
/*  f189330:	26045608 */ 	addiu	$a0,$s0,0x5608
/*  f189334:	02202025 */ 	move	$a0,$s1
/*  f189338:	0c004c01 */ 	jal	strcmp
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
/*  f1893d4:	0fc5bdaa */ 	jal	langGet
/*  f1893d8:	01098821 */ 	addu	$s1,$t0,$t1
/*  f1893dc:	02202025 */ 	move	$a0,$s1
/*  f1893e0:	0c004bb0 */ 	jal	strcpy
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
		strcpy(g_MpSetup.name, langGet(L_MISC_438)); // empty string
	}

	// Team names
	for (i = 0; i < 8; i++) {
		if (g_MpSetupSaveFile.teamnames[i][0] == '\0') {
			strcpy(g_MpSetupSaveFile.teamnames[i], langGet(L_OPTIONS_008 + i)); // "Red", "Yellow" etc
		}
	}

	// Player names
	for (i = 0; i < 4; i++) {
		if (g_MpPlayers[i].base.name[0] == '\0') {
			sprintf(g_MpPlayers[i].base.name, "%s %d\n", langGet(L_MISC_437), i + 1); // "Player 1" etc
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
		lvSetMpTimeLimit60(0);
	} else {
		lvSetMpTimeLimit60(SECSTOTIME60((g_MpSetup.timelimit + 1) * 60));
	}

	if (g_MpSetup.scorelimit >= 100) {
		lvSetMpScoreLimit(0);
	} else {
		lvSetMpScoreLimit(g_MpSetup.scorelimit + 1);
	}

	if (g_MpSetup.teamscorelimit >= 400) {
		lvSetMpTeamScoreLimit(0);
	} else {
		lvSetMpTeamScoreLimit(mpCalculateTeamScoreLimit() + 1);
	}
}

#if VERSION >= VERSION_NTSC_1_0
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
#else
GLOBAL_ASM(
glabel mpGetPlayerRankings
/*  f1829e8:	27bdfdd0 */ 	addiu	$sp,$sp,-560
/*  f1829ec:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1829f0:	3c13800b */ 	lui	$s3,0x800b
/*  f1829f4:	26731438 */ 	addiu	$s3,$s3,0x1438
/*  f1829f8:	8e6e000c */ 	lw	$t6,0xc($s3)
/*  f1829fc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f182a00:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f182a04:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f182a08:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f182a0c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f182a10:	afa40230 */ 	sw	$a0,0x230($sp)
/*  f182a14:	11e00004 */ 	beqz	$t7,.NB0f182a28
/*  f182a18:	00008025 */ 	or	$s0,$zero,$zero
/*  f182a1c:	0fc60b9d */ 	jal	mpGetTeamRankings
/*  f182a20:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f182a24:	afa20164 */ 	sw	$v0,0x164($sp)
.NB0f182a28:
/*  f182a28:	8fac0164 */ 	lw	$t4,0x164($sp)
/*  f182a2c:	00008825 */ 	or	$s1,$zero,$zero
/*  f182a30:	96780016 */ 	lhu	$t8,0x16($s3)
.NB0f182a34:
/*  f182a34:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f182a38:	02397004 */ 	sllv	$t6,$t9,$s1
/*  f182a3c:	030e7824 */ 	and	$t7,$t8,$t6
/*  f182a40:	11e00066 */ 	beqz	$t7,.NB0f182bdc
/*  f182a44:	00001825 */ 	or	$v1,$zero,$zero
/*  f182a48:	2a210004 */ 	slti	$at,$s1,0x4
/*  f182a4c:	10200008 */ 	beqz	$at,.NB0f182a70
/*  f182a50:	00001025 */ 	or	$v0,$zero,$zero
/*  f182a54:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f182a58:	0331c821 */ 	addu	$t9,$t9,$s1
/*  f182a5c:	3c18800b */ 	lui	$t8,0x800b
/*  f182a60:	27181068 */ 	addiu	$t8,$t8,0x1068
/*  f182a64:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f182a68:	1000000a */ 	beqz	$zero,.NB0f182a94
/*  f182a6c:	03389021 */ 	addu	$s2,$t9,$t8
.NB0f182a70:
/*  f182a70:	00117080 */ 	sll	$t6,$s1,0x2
/*  f182a74:	01d17021 */ 	addu	$t6,$t6,$s1
/*  f182a78:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f182a7c:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f182a80:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f182a84:	3c19800b */ 	lui	$t9,0x800b
/*  f182a88:	27390de8 */ 	addiu	$t9,$t9,0xde8
/*  f182a8c:	25cffed0 */ 	addiu	$t7,$t6,-304
/*  f182a90:	01f99021 */ 	addu	$s2,$t7,$t9
.NB0f182a94:
/*  f182a94:	02402025 */ 	or	$a0,$s2,$zero
/*  f182a98:	02202825 */ 	or	$a1,$s1,$zero
/*  f182a9c:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f182aa0:	27a70064 */ 	addiu	$a3,$sp,0x64
/*  f182aa4:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f182aa8:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f182aac:	0fc6001f */ 	jal	func0f185c14
/*  f182ab0:	afac0164 */ 	sw	$t4,0x164($sp)
/*  f182ab4:	8fa20058 */ 	lw	$v0,0x58($sp)
/*  f182ab8:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f182abc:	8fac0164 */ 	lw	$t4,0x164($sp)
/*  f182ac0:	1a000018 */ 	blez	$s0,.NB0f182b24
/*  f182ac4:	00002825 */ 	or	$a1,$zero,$zero
/*  f182ac8:	8faa0068 */ 	lw	$t2,0x68($sp)
/*  f182acc:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f182ad0:	34018000 */ 	dli	$at,0x8000
/*  f182ad4:	0141c021 */ 	addu	$t8,$t2,$at
/*  f182ad8:	00187400 */ 	sll	$t6,$t8,0x10
/*  f182adc:	3419ffff */ 	dli	$t9,0xffff
/*  f182ae0:	032fc023 */ 	subu	$t8,$t9,$t7
/*  f182ae4:	27af01cc */ 	addiu	$t7,$sp,0x1cc
/*  f182ae8:	0000c880 */ 	sll	$t9,$zero,0x2
/*  f182aec:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f182af0:	01d84825 */ 	or	$t1,$t6,$t8
/*  f182af4:	8c8e0000 */ 	lw	$t6,0x0($a0)
.NB0f182af8:
/*  f182af8:	01c9082b */ 	sltu	$at,$t6,$t1
/*  f182afc:	50200004 */ 	beqzl	$at,.NB0f182b10
/*  f182b00:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f182b04:	00a01825 */ 	or	$v1,$a1,$zero
/*  f182b08:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f182b0c:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f182b10:
/*  f182b10:	00b0082a */ 	slt	$at,$a1,$s0
/*  f182b14:	10200003 */ 	beqz	$at,.NB0f182b24
/*  f182b18:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f182b1c:	5040fff6 */ 	beqzl	$v0,.NB0f182af8
/*  f182b20:	8c8e0000 */ 	lw	$t6,0x0($a0)
.NB0f182b24:
/*  f182b24:	8faa0068 */ 	lw	$t2,0x68($sp)
/*  f182b28:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f182b2c:	34018000 */ 	dli	$at,0x8000
/*  f182b30:	0141c021 */ 	addu	$t8,$t2,$at
/*  f182b34:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f182b38:	340effff */ 	dli	$t6,0xffff
/*  f182b3c:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f182b40:	14400002 */ 	bnez	$v0,.NB0f182b4c
/*  f182b44:	03384825 */ 	or	$t1,$t9,$t8
/*  f182b48:	02001825 */ 	or	$v1,$s0,$zero
.NB0f182b4c:
/*  f182b4c:	0070082a */ 	slt	$at,$v1,$s0
/*  f182b50:	10200018 */ 	beqz	$at,.NB0f182bb4
/*  f182b54:	02002825 */ 	or	$a1,$s0,$zero
/*  f182b58:	00051080 */ 	sll	$v0,$a1,0x2
/*  f182b5c:	27ae01cc */ 	addiu	$t6,$sp,0x1cc
/*  f182b60:	27af01fc */ 	addiu	$t7,$sp,0x1fc
/*  f182b64:	27b9019c */ 	addiu	$t9,$sp,0x19c
/*  f182b68:	27b8016c */ 	addiu	$t8,$sp,0x16c
/*  f182b6c:	00583821 */ 	addu	$a3,$v0,$t8
/*  f182b70:	00593021 */ 	addu	$a2,$v0,$t9
/*  f182b74:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f182b78:	004e2021 */ 	addu	$a0,$v0,$t6
.NB0f182b7c:
/*  f182b7c:	8c8efffc */ 	lw	$t6,-0x4($a0)
/*  f182b80:	8d0ffffc */ 	lw	$t7,-0x4($t0)
/*  f182b84:	8cd9fffc */ 	lw	$t9,-0x4($a2)
/*  f182b88:	8cf8fffc */ 	lw	$t8,-0x4($a3)
/*  f182b8c:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f182b90:	2484fffc */ 	addiu	$a0,$a0,-4
/*  f182b94:	2508fffc */ 	addiu	$t0,$t0,-4
/*  f182b98:	24c6fffc */ 	addiu	$a2,$a2,-4
/*  f182b9c:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f182ba0:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f182ba4:	ad0f0004 */ 	sw	$t7,0x4($t0)
/*  f182ba8:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f182bac:	1465fff3 */ 	bne	$v1,$a1,.NB0f182b7c
/*  f182bb0:	acf80004 */ 	sw	$t8,0x4($a3)
.NB0f182bb4:
/*  f182bb4:	00031080 */ 	sll	$v0,$v1,0x2
/*  f182bb8:	03a27021 */ 	addu	$t6,$sp,$v0
/*  f182bbc:	adc901cc */ 	sw	$t1,0x1cc($t6)
/*  f182bc0:	03a27821 */ 	addu	$t7,$sp,$v0
/*  f182bc4:	adea01fc */ 	sw	$t2,0x1fc($t7)
/*  f182bc8:	03a2c821 */ 	addu	$t9,$sp,$v0
/*  f182bcc:	af32019c */ 	sw	$s2,0x19c($t9)
/*  f182bd0:	03a2c021 */ 	addu	$t8,$sp,$v0
/*  f182bd4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f182bd8:	af11016c */ 	sw	$s1,0x16c($t8)
.NB0f182bdc:
/*  f182bdc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f182be0:	2401000c */ 	addiu	$at,$zero,0xc
/*  f182be4:	5621ff93 */ 	bnel	$s1,$at,.NB0f182a34
/*  f182be8:	96780016 */ 	lhu	$t8,0x16($s3)
/*  f182bec:	240dffff */ 	addiu	$t5,$zero,-1
/*  f182bf0:	241fffff */ 	addiu	$ra,$zero,-1
/*  f182bf4:	1a000036 */ 	blez	$s0,.NB0f182cd0
/*  f182bf8:	00002825 */ 	or	$a1,$zero,$zero
/*  f182bfc:	27a401cc */ 	addiu	$a0,$sp,0x1cc
/*  f182c00:	27a801fc */ 	addiu	$t0,$sp,0x1fc
/*  f182c04:	27a6019c */ 	addiu	$a2,$sp,0x19c
/*  f182c08:	27a7016c */ 	addiu	$a3,$sp,0x16c
/*  f182c0c:	8fab0230 */ 	lw	$t3,0x230($sp)
/*  f182c10:	2411ffff */ 	addiu	$s1,$zero,-1
.NB0f182c14:
/*  f182c14:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f182c18:	25080004 */ 	addiu	$t0,$t0,0x4
/*  f182c1c:	256b0014 */ 	addiu	$t3,$t3,0x14
/*  f182c20:	ad6effec */ 	sw	$t6,-0x14($t3)
/*  f182c24:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f182c28:	ad65fff4 */ 	sw	$a1,-0xc($t3)
/*  f182c2c:	a160fff8 */ 	sb	$zero,-0x8($t3)
/*  f182c30:	ad6ffff0 */ 	sw	$t7,-0x10($t3)
/*  f182c34:	8d19fffc */ 	lw	$t9,-0x4($t0)
/*  f182c38:	258affff */ 	addiu	$t2,$t4,-1
/*  f182c3c:	ad79fffc */ 	sw	$t9,-0x4($t3)
/*  f182c40:	8e78000c */ 	lw	$t8,0xc($s3)
/*  f182c44:	330e0002 */ 	andi	$t6,$t8,0x2
/*  f182c48:	51c00011 */ 	beqzl	$t6,.NB0f182c90
/*  f182c4c:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f182c50:	1980000b */ 	blez	$t4,.NB0f182c80
/*  f182c54:	00001025 */ 	or	$v0,$zero,$zero
/*  f182c58:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f182c5c:	27a30074 */ 	addiu	$v1,$sp,0x74
/*  f182c60:	91e90011 */ 	lbu	$t1,0x11($t7)
.NB0f182c64:
/*  f182c64:	8c790004 */ 	lw	$t9,0x4($v1)
/*  f182c68:	57290003 */ 	bnel	$t9,$t1,.NB0f182c78
/*  f182c6c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182c70:	00405025 */ 	or	$t2,$v0,$zero
/*  f182c74:	24420001 */ 	addiu	$v0,$v0,0x1
.NB0f182c78:
/*  f182c78:	144cfffa */ 	bne	$v0,$t4,.NB0f182c64
/*  f182c7c:	24630014 */ 	addiu	$v1,$v1,0x14
.NB0f182c80:
/*  f182c80:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f182c84:	10000003 */ 	beqz	$zero,.NB0f182c94
/*  f182c88:	a30a001e */ 	sb	$t2,0x1e($t8)
/*  f182c8c:	8cce0000 */ 	lw	$t6,0x0($a2)
.NB0f182c90:
/*  f182c90:	a1c5001e */ 	sb	$a1,0x1e($t6)
.NB0f182c94:
/*  f182c94:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f182c98:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f182c9c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f182ca0:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f182ca4:	af2f0020 */ 	sw	$t7,0x20($t9)
/*  f182ca8:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f182cac:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f182cb0:	28410004 */ 	slti	$at,$v0,0x4
/*  f182cb4:	10200004 */ 	beqz	$at,.NB0f182cc8
/*  f182cb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182cbc:	15b10002 */ 	bne	$t5,$s1,.NB0f182cc8
/*  f182cc0:	0040f825 */ 	or	$ra,$v0,$zero
/*  f182cc4:	00406825 */ 	or	$t5,$v0,$zero
.NB0f182cc8:
/*  f182cc8:	14b0ffd2 */ 	bne	$a1,$s0,.NB0f182c14
/*  f182ccc:	24e70004 */ 	addiu	$a3,$a3,0x4
.NB0f182cd0:
/*  f182cd0:	3c11800b */ 	lui	$s1,0x800b
/*  f182cd4:	263114d0 */ 	addiu	$s1,$s1,0x14d0
/*  f182cd8:	a22d0001 */ 	sb	$t5,0x1($s1)
/*  f182cdc:	a23f0002 */ 	sb	$ra,0x2($s1)
/*  f182ce0:	3c18800b */ 	lui	$t8,0x800b
/*  f182ce4:	931814c0 */ 	lbu	$t8,0x14c0($t8)
/*  f182ce8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f182cec:	57010005 */ 	bnel	$t8,$at,.NB0f182d04
/*  f182cf0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f182cf4:	0fc61850 */ 	jal	mpChooseRandomLockPlayer
/*  f182cf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f182cfc:	a2220000 */ 	sb	$v0,0x0($s1)
/*  f182d00:	8fbf0024 */ 	lw	$ra,0x24($sp)
.NB0f182d04:
/*  f182d04:	02001025 */ 	or	$v0,$s0,$zero
/*  f182d08:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f182d0c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f182d10:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f182d14:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f182d18:	03e00008 */ 	jr	$ra
/*  f182d1c:	27bd0230 */ 	addiu	$sp,$sp,0x230
);
#endif

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
					return langGet(L_MPWEAPONS_058); // "Nothing"
				}

				if (g_MpWeapons[i].weaponnum == WEAPON_MPSHIELD) {
					return langGet(L_MPWEAPONS_059); // "Shield"
				}

				if (g_MpWeapons[i].weaponnum == WEAPON_DISABLED) {
					return langGet(L_MPWEAPONS_060); // "Disabled"
				}

				return weaponGetName(g_MpWeapons[i].weaponnum);
			}

			weaponnum--;
		}
	}

	return "";
}

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b8a5c[] = "Gun index %d -> slot %d = gun %d\n\n";
const char var7f1b8a80[] = "HOLDER: selecting weapon set %d\n";
#endif

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
		return langGet(L_MPWEAPONS_041); // "Custom"
	}

	if (index == 13) {
		return langGet(L_MPWEAPONS_042); // "Random"
	}

	if (index == 12) {
		return langGet(L_MPWEAPONS_043); // "Random Five"
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
#if VERSION >= VERSION_PAL_FINAL
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
/*  f1897b4:	24045428 */ 	addiu	$a0,$zero,0x5429
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
/*  f18986c:	3c088008 */ 	lui	$t0,%hi(g_FontHandelGothicSm2)
/*  f189870:	8d08fb14 */ 	lw	$t0,%lo(g_FontHandelGothicSm2)($t0)
/*  f189874:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm1)
/*  f189878:	8ce7fb18 */ 	lw	$a3,%lo(g_FontHandelGothicSm1)($a3)
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
/*  f1898c4:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm1)
/*  f1898c8:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicSm2)
/*  f1898cc:	3c0100ff */ 	lui	$at,0xff
/*  f1898d0:	8dcefb14 */ 	lw	$t6,%lo(g_FontHandelGothicSm2)($t6)
/*  f1898d4:	8dadfb18 */ 	lw	$t5,%lo(g_FontHandelGothicSm1)($t5)
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
/*  f189a04:	24045427 */ 	addiu	$a0,$zero,0x5428
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
/*  f189b94:	2401003c */ 	addiu	$at,$zero,0x32
/*  f189b98:	3c057f1c */ 	lui	$a1,%hi(var7f1b8aa4)
/*  f189b9c:	24c6003b */ 	addiu	$a2,$a2,0x31
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
#elif VERSION >= VERSION_NTSC_1_0
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
#else
GLOBAL_ASM(
glabel mpRenderModalText
/*  f183b2c:	3c02800b */ 	lui	$v0,0x800b
/*  f183b30:	90421456 */ 	lbu	$v0,0x1456($v0)
/*  f183b34:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f183b38:	24010001 */ 	addiu	$at,$zero,0x1
/*  f183b3c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f183b40:	14410075 */ 	bne	$v0,$at,.NB0f183d18
/*  f183b44:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f183b48:	3c013f80 */ 	lui	$at,0x3f80
/*  f183b4c:	44812000 */ 	mtc1	$at,$f4
/*  f183b50:	3c018006 */ 	lui	$at,0x8006
/*  f183b54:	c4263b40 */ 	lwc1	$f6,0x3b40($at)
/*  f183b58:	3c0141a0 */ 	lui	$at,0x41a0
/*  f183b5c:	44815000 */ 	mtc1	$at,$f10
/*  f183b60:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f183b64:	3c01437f */ 	lui	$at,0x437f
/*  f183b68:	44819000 */ 	mtc1	$at,$f18
/*  f183b6c:	240100ff */ 	addiu	$at,$zero,0xff
/*  f183b70:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f183b74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183b78:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f183b7c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f183b80:	440f3000 */ 	mfc1	$t7,$f6
/*  f183b84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183b88:	01e1001a */ 	div	$zero,$t7,$at
/*  f183b8c:	0000c010 */ 	mfhi	$t8
/*  f183b90:	afb80054 */ 	sw	$t8,0x54($sp)
/*  f183b94:	0fc5374a */ 	jal	func0f153628
/*  f183b98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183b9c:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f183ba0:	0fc5a4dd */ 	jal	langGet
/*  f183ba4:	24045428 */ 	addiu	$a0,$zero,0x5428
/*  f183ba8:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f183bac:	0c004e60 */ 	jal	strcpy
/*  f183bb0:	00402825 */ 	or	$a1,$v0,$zero
/*  f183bb4:	0c002fb5 */ 	jal	viGetViewLeft
/*  f183bb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183bbc:	0c002f97 */ 	jal	viGetViewWidth
/*  f183bc0:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f183bc4:	3c0a800a */ 	lui	$t2,0x800a
/*  f183bc8:	8d4ae94c */ 	lw	$t2,-0x16b4($t2)
/*  f183bcc:	3c0c800a */ 	lui	$t4,0x800a
/*  f183bd0:	87a80042 */ 	lh	$t0,0x42($sp)
/*  f183bd4:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f183bd8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f183bdc:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f183be0:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f183be4:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f183be8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f183bec:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f183bf0:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f183bf4:	8d8c2c48 */ 	lw	$t4,0x2c48($t4)
/*  f183bf8:	04410003 */ 	bgez	$v0,.NB0f183c08
/*  f183bfc:	0002c843 */ 	sra	$t9,$v0,0x1
/*  f183c00:	24410001 */ 	addiu	$at,$v0,0x1
/*  f183c04:	0001c843 */ 	sra	$t9,$at,0x1
.NB0f183c08:
/*  f183c08:	03284821 */ 	addu	$t1,$t9,$t0
/*  f183c0c:	11800006 */ 	beqz	$t4,.NB0f183c28
/*  f183c10:	afa90094 */ 	sw	$t1,0x94($sp)
/*  f183c14:	0c002fb9 */ 	jal	viGetViewTop
/*  f183c18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183c1c:	244d000a */ 	addiu	$t5,$v0,0xa
/*  f183c20:	1000000c */ 	beqz	$zero,.NB0f183c54
/*  f183c24:	afad0090 */ 	sw	$t5,0x90($sp)
.NB0f183c28:
/*  f183c28:	0c002fb9 */ 	jal	viGetViewTop
/*  f183c2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183c30:	0c002f9b */ 	jal	viGetViewHeight
/*  f183c34:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f183c38:	87af0042 */ 	lh	$t7,0x42($sp)
/*  f183c3c:	04410003 */ 	bgez	$v0,.NB0f183c4c
/*  f183c40:	00027043 */ 	sra	$t6,$v0,0x1
/*  f183c44:	24410001 */ 	addiu	$at,$v0,0x1
/*  f183c48:	00017043 */ 	sra	$t6,$at,0x1
.NB0f183c4c:
/*  f183c4c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f183c50:	afb80090 */ 	sw	$t8,0x90($sp)
.NB0f183c54:
/*  f183c54:	3c198008 */ 	lui	$t9,0x8008
/*  f183c58:	8f392374 */ 	lw	$t9,0x2374($t9)
/*  f183c5c:	3c078008 */ 	lui	$a3,0x8008
/*  f183c60:	8ce72378 */ 	lw	$a3,0x2378($a3)
/*  f183c64:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f183c68:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f183c6c:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f183c70:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f183c74:	0fc54655 */ 	jal	textMeasure
/*  f183c78:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f183c7c:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*  f183c80:	8fa80094 */ 	lw	$t0,0x94($sp)
/*  f183c84:	05210003 */ 	bgez	$t1,.NB0f183c94
/*  f183c88:	00095043 */ 	sra	$t2,$t1,0x1
/*  f183c8c:	25210001 */ 	addiu	$at,$t1,0x1
/*  f183c90:	00015043 */ 	sra	$t2,$at,0x1
.NB0f183c94:
/*  f183c94:	010a5823 */ 	subu	$t3,$t0,$t2
/*  f183c98:	0c002f77 */ 	jal	viGetWidth
/*  f183c9c:	afab0094 */ 	sw	$t3,0x94($sp)
/*  f183ca0:	0c002f77 */ 	jal	viGetWidth
/*  f183ca4:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f183ca8:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f183cac:	3c0c8008 */ 	lui	$t4,0x8008
/*  f183cb0:	3c0d8008 */ 	lui	$t5,0x8008
/*  f183cb4:	3c0100ff */ 	lui	$at,0xff
/*  f183cb8:	8dad2374 */ 	lw	$t5,0x2374($t5)
/*  f183cbc:	8d8c2378 */ 	lw	$t4,0x2378($t4)
/*  f183cc0:	87a90040 */ 	lh	$t1,0x40($sp)
/*  f183cc4:	342100ff */ 	ori	$at,$at,0xff
/*  f183cc8:	000e7e00 */ 	sll	$t7,$t6,0x18
/*  f183ccc:	01e1c025 */ 	or	$t8,$t7,$at
/*  f183cd0:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f183cd4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f183cd8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f183cdc:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f183ce0:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f183ce4:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f183ce8:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f183cec:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f183cf0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f183cf4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f183cf8:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f183cfc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f183d00:	0fc54529 */ 	jal	textRender
/*  f183d04:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f183d08:	0fc537a0 */ 	jal	func0f153780
/*  f183d0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f183d10:	100000e0 */ 	beqz	$zero,.NB0f184094
/*  f183d14:	afa200a0 */ 	sw	$v0,0xa0($sp)
.NB0f183d18:
/*  f183d18:	3c088006 */ 	lui	$t0,0x8006
/*  f183d1c:	8d08f2f0 */ 	lw	$t0,-0xd10($t0)
/*  f183d20:	550000dd */ 	bnezl	$t0,.NB0f184098
/*  f183d24:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f183d28:	144000da */ 	bnez	$v0,.NB0f184094
/*  f183d2c:	3c03800a */ 	lui	$v1,0x800a
/*  f183d30:	2463e6c0 */ 	addiu	$v1,$v1,-6464
/*  f183d34:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f183d38:	8c4a00d8 */ 	lw	$t2,0xd8($v0)
/*  f183d3c:	514000d6 */ 	beqzl	$t2,.NB0f184098
/*  f183d40:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f183d44:	8c4b032c */ 	lw	$t3,0x32c($v0)
/*  f183d48:	516000d3 */ 	beqzl	$t3,.NB0f184098
/*  f183d4c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f183d50:	8c4c0330 */ 	lw	$t4,0x330($v0)
/*  f183d54:	518000d0 */ 	beqzl	$t4,.NB0f184098
/*  f183d58:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f183d5c:	8c6d0298 */ 	lw	$t5,0x298($v1)
/*  f183d60:	05a20011 */ 	bltzl	$t5,.NB0f183da8
/*  f183d64:	8c6a029c */ 	lw	$t2,0x29c($v1)
/*  f183d68:	8c6e02a0 */ 	lw	$t6,0x2a0($v1)
/*  f183d6c:	8dcf00d8 */ 	lw	$t7,0xd8($t6)
/*  f183d70:	51e00006 */ 	beqzl	$t7,.NB0f183d8c
/*  f183d74:	8c491c10 */ 	lw	$t1,0x1c10($v0)
/*  f183d78:	8c7802a4 */ 	lw	$t8,0x2a4($v1)
/*  f183d7c:	8f1900d8 */ 	lw	$t9,0xd8($t8)
/*  f183d80:	572000c5 */ 	bnezl	$t9,.NB0f184098
/*  f183d84:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f183d88:	8c491c10 */ 	lw	$t1,0x1c10($v0)
.NB0f183d8c:
/*  f183d8c:	3c088007 */ 	lui	$t0,0x8007
/*  f183d90:	512000c1 */ 	beqzl	$t1,.NB0f184098
/*  f183d94:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f183d98:	8d082e24 */ 	lw	$t0,0x2e24($t0)
/*  f183d9c:	550000be */ 	bnezl	$t0,.NB0f184098
/*  f183da0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f183da4:	8c6a029c */ 	lw	$t2,0x29c($v1)
.NB0f183da8:
/*  f183da8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f183dac:	05400008 */ 	bltz	$t2,.NB0f183dd0
/*  f183db0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183db4:	8c6b02a8 */ 	lw	$t3,0x2a8($v1)
/*  f183db8:	3c0c8007 */ 	lui	$t4,0x8007
/*  f183dbc:	556200b6 */ 	bnel	$t3,$v0,.NB0f184098
/*  f183dc0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f183dc4:	8d8c2e24 */ 	lw	$t4,0x2e24($t4)
/*  f183dc8:	558000b3 */ 	bnezl	$t4,.NB0f184098
/*  f183dcc:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f183dd0:
/*  f183dd0:	8dad6898 */ 	lw	$t5,0x6898($t5)
/*  f183dd4:	55a000b0 */ 	bnezl	$t5,.NB0f184098
/*  f183dd8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f183ddc:	0fc5374a */ 	jal	func0f153628
/*  f183de0:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f183de4:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f183de8:	0fc5a4dd */ 	jal	langGet
/*  f183dec:	24045427 */ 	addiu	$a0,$zero,0x5427
/*  f183df0:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f183df4:	0c004e60 */ 	jal	strcpy
/*  f183df8:	00402825 */ 	or	$a1,$v0,$zero
/*  f183dfc:	0c002fb5 */ 	jal	viGetViewLeft
/*  f183e00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183e04:	0c002f97 */ 	jal	viGetViewWidth
/*  f183e08:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f183e0c:	87af0042 */ 	lh	$t7,0x42($sp)
/*  f183e10:	04410003 */ 	bgez	$v0,.NB0f183e20
/*  f183e14:	00027043 */ 	sra	$t6,$v0,0x1
/*  f183e18:	24410001 */ 	addiu	$at,$v0,0x1
/*  f183e1c:	00017043 */ 	sra	$t6,$at,0x1
.NB0f183e20:
/*  f183e20:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f183e24:	0c002fb9 */ 	jal	viGetViewTop
/*  f183e28:	afb80094 */ 	sw	$t8,0x94($sp)
/*  f183e2c:	0c002f9b */ 	jal	viGetViewHeight
/*  f183e30:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f183e34:	87a90042 */ 	lh	$t1,0x42($sp)
/*  f183e38:	3c0a8008 */ 	lui	$t2,0x8008
/*  f183e3c:	8d4a236c */ 	lw	$t2,0x236c($t2)
/*  f183e40:	04410003 */ 	bgez	$v0,.NB0f183e50
/*  f183e44:	0002c843 */ 	sra	$t9,$v0,0x1
/*  f183e48:	24410001 */ 	addiu	$at,$v0,0x1
/*  f183e4c:	0001c843 */ 	sra	$t9,$at,0x1
.NB0f183e50:
/*  f183e50:	3c078008 */ 	lui	$a3,0x8008
/*  f183e54:	03294021 */ 	addu	$t0,$t9,$t1
/*  f183e58:	afa80090 */ 	sw	$t0,0x90($sp)
/*  f183e5c:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f183e60:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f183e64:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f183e68:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f183e6c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f183e70:	0fc54655 */ 	jal	textMeasure
/*  f183e74:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f183e78:	8fac009c */ 	lw	$t4,0x9c($sp)
/*  f183e7c:	8fab0094 */ 	lw	$t3,0x94($sp)
/*  f183e80:	05810003 */ 	bgez	$t4,.NB0f183e90
/*  f183e84:	000c6843 */ 	sra	$t5,$t4,0x1
/*  f183e88:	25810001 */ 	addiu	$at,$t4,0x1
/*  f183e8c:	00016843 */ 	sra	$t5,$at,0x1
.NB0f183e90:
/*  f183e90:	016d7023 */ 	subu	$t6,$t3,$t5
/*  f183e94:	0c002f77 */ 	jal	viGetWidth
/*  f183e98:	afae0094 */ 	sw	$t6,0x94($sp)
/*  f183e9c:	0c002f77 */ 	jal	viGetWidth
/*  f183ea0:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f183ea4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f183ea8:	3c188008 */ 	lui	$t8,0x8008
/*  f183eac:	8f18236c */ 	lw	$t8,0x236c($t8)
/*  f183eb0:	8def2370 */ 	lw	$t7,0x2370($t7)
/*  f183eb4:	87a80040 */ 	lh	$t0,0x40($sp)
/*  f183eb8:	3c19ff00 */ 	lui	$t9,0xff00
/*  f183ebc:	373900ff */ 	ori	$t9,$t9,0xff
/*  f183ec0:	240900ff */ 	addiu	$t1,$zero,0xff
/*  f183ec4:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f183ec8:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f183ecc:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f183ed0:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f183ed4:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f183ed8:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f183edc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f183ee0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f183ee4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f183ee8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f183eec:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f183ef0:	0fc54529 */ 	jal	textRender
/*  f183ef4:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f183ef8:	3c0a800a */ 	lui	$t2,0x800a
/*  f183efc:	8d4ae944 */ 	lw	$t2,-0x16bc($t2)
/*  f183f00:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f183f04:	8d4c1c0c */ 	lw	$t4,0x1c0c($t2)
/*  f183f08:	19800051 */ 	blez	$t4,.NB0f184050
/*  f183f0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183f10:	0c002fb9 */ 	jal	viGetViewTop
/*  f183f14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f183f18:	0c002f9b */ 	jal	viGetViewHeight
/*  f183f1c:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f183f20:	87ad0042 */ 	lh	$t5,0x42($sp)
/*  f183f24:	8faf0098 */ 	lw	$t7,0x98($sp)
/*  f183f28:	04410003 */ 	bgez	$v0,.NB0f183f38
/*  f183f2c:	00025843 */ 	sra	$t3,$v0,0x1
/*  f183f30:	24410001 */ 	addiu	$at,$v0,0x1
/*  f183f34:	00015843 */ 	sra	$t3,$at,0x1
.NB0f183f38:
/*  f183f38:	016d7021 */ 	addu	$t6,$t3,$t5
/*  f183f3c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f183f40:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f183f44:	0c002fb5 */ 	jal	viGetViewLeft
/*  f183f48:	afb9004c */ 	sw	$t9,0x4c($sp)
/*  f183f4c:	0c002f97 */ 	jal	viGetViewWidth
/*  f183f50:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f183f54:	87a80042 */ 	lh	$t0,0x42($sp)
/*  f183f58:	3c0c800a */ 	lui	$t4,0x800a
/*  f183f5c:	8d8ce944 */ 	lw	$t4,-0x16bc($t4)
/*  f183f60:	04410003 */ 	bgez	$v0,.NB0f183f70
/*  f183f64:	00024843 */ 	sra	$t1,$v0,0x1
/*  f183f68:	24410001 */ 	addiu	$at,$v0,0x1
/*  f183f6c:	00014843 */ 	sra	$t1,$at,0x1
.NB0f183f70:
/*  f183f70:	01285021 */ 	addu	$t2,$t1,$t0
/*  f183f74:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f183f78:	8d861c0c */ 	lw	$a2,0x1c0c($t4)
/*  f183f7c:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f183f80:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f183f84:	24c6003b */ 	addiu	$a2,$a2,0x3b
/*  f183f88:	00c1001a */ 	div	$zero,$a2,$at
/*  f183f8c:	00003012 */ 	mflo	$a2
/*  f183f90:	24a53320 */ 	addiu	$a1,$a1,0x3320
/*  f183f94:	0c004fc1 */ 	jal	sprintf
/*  f183f98:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f183f9c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f183fa0:	8dad236c */ 	lw	$t5,0x236c($t5)
/*  f183fa4:	3c078008 */ 	lui	$a3,0x8008
/*  f183fa8:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f183fac:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f183fb0:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f183fb4:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f183fb8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f183fbc:	0fc54655 */ 	jal	textMeasure
/*  f183fc0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f183fc4:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f183fc8:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f183fcc:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f183fd0:	05e10003 */ 	bgez	$t7,.NB0f183fe0
/*  f183fd4:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f183fd8:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f183fdc:	0001c043 */ 	sra	$t8,$at,0x1
.NB0f183fe0:
/*  f183fe0:	01d8c823 */ 	subu	$t9,$t6,$t8
/*  f183fe4:	afb90094 */ 	sw	$t9,0x94($sp)
/*  f183fe8:	0c002f77 */ 	jal	viGetWidth
/*  f183fec:	afa90090 */ 	sw	$t1,0x90($sp)
/*  f183ff0:	0c002f77 */ 	jal	viGetWidth
/*  f183ff4:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f183ff8:	3c088008 */ 	lui	$t0,0x8008
/*  f183ffc:	3c0a8008 */ 	lui	$t2,0x8008
/*  f184000:	8d4a236c */ 	lw	$t2,0x236c($t2)
/*  f184004:	8d082370 */ 	lw	$t0,0x2370($t0)
/*  f184008:	87ad0040 */ 	lh	$t5,0x40($sp)
/*  f18400c:	3c0cff00 */ 	lui	$t4,0xff00
/*  f184010:	358c00ff */ 	ori	$t4,$t4,0xff
/*  f184014:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f184018:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f18401c:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f184020:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f184024:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f184028:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f18402c:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f184030:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f184034:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f184038:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f18403c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f184040:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f184044:	0fc54529 */ 	jal	textRender
/*  f184048:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f18404c:	afa200a0 */ 	sw	$v0,0xa0($sp)
.NB0f184050:
/*  f184050:	0fc537a0 */ 	jal	func0f153780
/*  f184054:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f184058:	3c0e800a */ 	lui	$t6,0x800a
/*  f18405c:	8dcee948 */ 	lw	$t6,-0x16b8($t6)
/*  f184060:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f184064:	3c01800a */ 	lui	$at,0x800a
/*  f184068:	8dd80070 */ 	lw	$t8,0x70($t6)
/*  f18406c:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f184070:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f184074:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f184078:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f18407c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f184080:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f184084:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f184088:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18408c:	00390821 */ 	addu	$at,$at,$t9
/*  f184090:	a02f2f58 */ 	sb	$t7,0x2f58($at)
.NB0f184094:
/*  f184094:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f184098:
/*  f184098:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f18409c:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f1840a0:	03e00008 */ 	jr	$ra
/*  f1840a4:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

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
	{ /*0x00*/ L_MPWEAPONS_055, { WEAPON_FALCON2,          WEAPON_MAGSEC4,     WEAPON_PHOENIX,     WEAPON_MAULER,         WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_PHOENIX,         MPFEATURE_WEAPON_MAULER,     0,                              0                       }, 0x02, 0x05, 0x02, 0x08, 0x5b, 0x5c }, // Pistols
	{ /*0x01*/ L_MPWEAPONS_054, { WEAPON_FALCON2,          WEAPON_CMP150,      WEAPON_LAPTOPGUN,   WEAPON_AR34,           WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_LAPTOPGUN,       0,                           0,                              0                       }, 0x02, 0x0a, 0x0f, 0x11, 0x5b, 0x5c }, // Automatics
	{ /*0x02*/ L_MPWEAPONS_053, { WEAPON_MAGSEC4,          WEAPON_DY357MAGNUM, WEAPON_SHOTGUN,     WEAPON_RCP120,         WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_SHOTGUN,         MPFEATURE_WEAPON_RCP120,     0,                              0                       }, 0x05, 0x08, 0x0f, 0x11, 0x5b, 0x5c }, // Power
	{ /*0x03*/ L_MPWEAPONS_052, { WEAPON_PHOENIX,          WEAPON_CYCLONE,     WEAPON_CALLISTO,    WEAPON_FARSIGHT,       WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_FARSIGHT,        MPFEATURE_WEAPON_CALLISTO,   0,                              0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // FarSight
	{ /*0x04*/ L_MPWEAPONS_051, { WEAPON_FALCON2,          WEAPON_CMP150,      WEAPON_DRAGON,      WEAPON_TRANQUILIZER,   WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_TRANQUILIZER,    0,                           0,                              0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Tranquilizer
	{ /*0x05*/ L_MPWEAPONS_050, { WEAPON_MAULER,           WEAPON_K7AVENGER,   WEAPON_REAPER,      WEAPON_SUPERDRAGON,    WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_SUPERDRAGON,     MPFEATURE_WEAPON_MAULER,     MPFEATURE_WEAPON_K7AVENGER,     MPFEATURE_WEAPON_REAPER }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Heavy
	{ /*0x06*/ L_MPWEAPONS_049, { WEAPON_FALCON2_SILENCER, WEAPON_GRENADE,     WEAPON_CMP150,      WEAPON_DY357LX,        WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_FALCON2SILENCED, MPFEATURE_WEAPON_DY357LX,    0,                              0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Golden Magnum
	{ /*0x07*/ L_MPWEAPONS_048, { WEAPON_DEVASTATOR,       WEAPON_DEVASTATOR,  WEAPON_SUPERDRAGON, WEAPON_SUPERDRAGON,    WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_SUPERDRAGON,     MPFEATURE_WEAPON_DEVASTATOR, 0,                              0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Explosive
	{ /*0x08*/ L_MPWEAPONS_047, { WEAPON_MAGSEC4,          WEAPON_CMP150,      WEAPON_AR34,        WEAPON_DEVASTATOR,     WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_DEVASTATOR,      0,                           0,                              0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Grenade Launcher
	{ /*0x09*/ L_MPWEAPONS_046, { WEAPON_MAULER,           WEAPON_CYCLONE,     WEAPON_DRAGON,      WEAPON_ROCKETLAUNCHER, WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_MAULER,          0,                           0,                              0                       }, 0x02, 0x0b, 0x0f, 0x18, 0x5b, 0x5c }, // Rocket Launcher
	{ /*0x0a*/ L_MPWEAPONS_045, { WEAPON_MAGSEC4,          WEAPON_LAPTOPGUN,   WEAPON_K7AVENGER,   WEAPON_PROXIMITYMINE,  WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_LAPTOPGUN,       MPFEATURE_WEAPON_K7AVENGER,  MPFEATURE_WEAPON_PROXIMITYMINE, 0                       }, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c, 0x5c }, // Proximity Mine
	{ /*0x0b*/ L_MPWEAPONS_044, { WEAPON_COMBATKNIFE,      WEAPON_COMBATKNIFE, WEAPON_TIMEDMINE,   WEAPON_CROSSBOW,       WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_CROSSBOW,        0,                           0,                              0                       }, 0x1a, 0x1a, 0x20, 0x20, 0x5b, 0x5c }, // Close Combat
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

#if VERSION >= VERSION_NTSC_1_0
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
#else
GLOBAL_ASM(
glabel mpCalculatePlayerTitle
/*  f184578:	3c0f7f1b */ 	lui	$t7,0x7f1b
/*  f18457c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f184580:	25ef3324 */ 	addiu	$t7,$t7,0x3324
/*  f184584:	25e80024 */ 	addiu	$t0,$t7,0x24
/*  f184588:	27ae0038 */ 	addiu	$t6,$sp,0x38
.NB0f18458c:
/*  f18458c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f184590:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f184594:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f184598:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f18459c:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f1845a0:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f1845a4:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f1845a8:	15e8fff8 */ 	bne	$t7,$t0,.NB0f18458c
/*  f1845ac:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f1845b0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1845b4:	3c0a8009 */ 	lui	$t2,0x8009
/*  f1845b8:	254a9c70 */ 	addiu	$t2,$t2,-25488
/*  f1845bc:	254d0024 */ 	addiu	$t5,$t2,0x24
/*  f1845c0:	27a90010 */ 	addiu	$t1,$sp,0x10
/*  f1845c4:	adc10000 */ 	sw	$at,0x0($t6)
.NB0f1845c8:
/*  f1845c8:	8d410000 */ 	lw	$at,0x0($t2)
/*  f1845cc:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f1845d0:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f1845d4:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*  f1845d8:	8d41fff8 */ 	lw	$at,-0x8($t2)
/*  f1845dc:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*  f1845e0:	8d41fffc */ 	lw	$at,-0x4($t2)
/*  f1845e4:	154dfff8 */ 	bne	$t2,$t5,.NB0f1845c8
/*  f1845e8:	ad21fffc */ 	sw	$at,-0x4($t1)
/*  f1845ec:	8d410000 */ 	lw	$at,0x0($t2)
/*  f1845f0:	27a20038 */ 	addiu	$v0,$sp,0x38
/*  f1845f4:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f1845f8:	24030014 */ 	addiu	$v1,$zero,0x14
/*  f1845fc:	ad210000 */ 	sw	$at,0x0($t1)
/*  f184600:	8c580000 */ 	lw	$t8,0x0($v0)
.NB0f184604:
/*  f184604:	8c990054 */ 	lw	$t9,0x54($a0)
/*  f184608:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f18460c:	03030019 */ 	multu	$t8,$v1
/*  f184610:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f184614:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f184618:	00004012 */ 	mflo	$t0
/*  f18461c:	0328082b */ 	sltu	$at,$t9,$t0
/*  f184620:	14200003 */ 	bnez	$at,.NB0f184630
/*  f184624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184628:	10000003 */ 	beqz	$zero,.NB0f184638
/*  f18462c:	afae0010 */ 	sw	$t6,0x10($sp)
.NB0f184630:
/*  f184630:	10000005 */ 	beqz	$zero,.NB0f184648
/*  f184634:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184638:
/*  f184638:	0045082b */ 	sltu	$at,$v0,$a1
/*  f18463c:	5420fff1 */ 	bnezl	$at,.NB0f184604
/*  f184640:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f184644:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184648:
/*  f184648:	27a30060 */ 	addiu	$v1,$sp,0x60
/*  f18464c:	8c8c0060 */ 	lw	$t4,0x60($a0)
.NB0f184650:
/*  f184650:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f184654:	8fad0014 */ 	lw	$t5,0x14($sp)
/*  f184658:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18465c:	018b082b */ 	sltu	$at,$t4,$t3
/*  f184660:	14200003 */ 	bnez	$at,.NB0f184670
/*  f184664:	25aa0001 */ 	addiu	$t2,$t5,0x1
/*  f184668:	10000003 */ 	beqz	$zero,.NB0f184678
/*  f18466c:	afaa0014 */ 	sw	$t2,0x14($sp)
.NB0f184670:
/*  f184670:	10000005 */ 	beqz	$zero,.NB0f184688
/*  f184674:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184678:
/*  f184678:	0043082b */ 	sltu	$at,$v0,$v1
/*  f18467c:	5420fff4 */ 	bnezl	$at,.NB0f184650
/*  f184680:	8c8c0060 */ 	lw	$t4,0x60($a0)
/*  f184684:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184688:
/*  f184688:	27a30060 */ 	addiu	$v1,$sp,0x60
/*  f18468c:	8c890084 */ 	lw	$t1,0x84($a0)
.NB0f184690:
/*  f184690:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f184694:	8fb90018 */ 	lw	$t9,0x18($sp)
/*  f184698:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18469c:	0138082b */ 	sltu	$at,$t1,$t8
/*  f1846a0:	14200003 */ 	bnez	$at,.NB0f1846b0
/*  f1846a4:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f1846a8:	10000003 */ 	beqz	$zero,.NB0f1846b8
/*  f1846ac:	afa80018 */ 	sw	$t0,0x18($sp)
.NB0f1846b0:
/*  f1846b0:	10000005 */ 	beqz	$zero,.NB0f1846c8
/*  f1846b4:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f1846b8:
/*  f1846b8:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1846bc:	5420fff4 */ 	bnezl	$at,.NB0f184690
/*  f1846c0:	8c890084 */ 	lw	$t1,0x84($a0)
/*  f1846c4:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f1846c8:
/*  f1846c8:	27a30060 */ 	addiu	$v1,$sp,0x60
/*  f1846cc:	8c8f0088 */ 	lw	$t7,0x88($a0)
.NB0f1846d0:
/*  f1846d0:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f1846d4:	8fac001c */ 	lw	$t4,0x1c($sp)
/*  f1846d8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1846dc:	01ee082b */ 	sltu	$at,$t7,$t6
/*  f1846e0:	14200003 */ 	bnez	$at,.NB0f1846f0
/*  f1846e4:	258b0001 */ 	addiu	$t3,$t4,0x1
/*  f1846e8:	10000003 */ 	beqz	$zero,.NB0f1846f8
/*  f1846ec:	afab001c */ 	sw	$t3,0x1c($sp)
.NB0f1846f0:
/*  f1846f0:	10000005 */ 	beqz	$zero,.NB0f184708
/*  f1846f4:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f1846f8:
/*  f1846f8:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1846fc:	5420fff4 */ 	bnezl	$at,.NB0f1846d0
/*  f184700:	8c8f0088 */ 	lw	$t7,0x88($a0)
/*  f184704:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184708:
/*  f184708:	27a30060 */ 	addiu	$v1,$sp,0x60
/*  f18470c:	8c8d008c */ 	lw	$t5,0x8c($a0)
.NB0f184710:
/*  f184710:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f184714:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f184718:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18471c:	01aa082b */ 	sltu	$at,$t5,$t2
/*  f184720:	14200003 */ 	bnez	$at,.NB0f184730
/*  f184724:	25380001 */ 	addiu	$t8,$t1,0x1
/*  f184728:	10000003 */ 	beqz	$zero,.NB0f184738
/*  f18472c:	afb80020 */ 	sw	$t8,0x20($sp)
.NB0f184730:
/*  f184730:	10000005 */ 	beqz	$zero,.NB0f184748
/*  f184734:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184738:
/*  f184738:	0043082b */ 	sltu	$at,$v0,$v1
/*  f18473c:	5420fff4 */ 	bnezl	$at,.NB0f184710
/*  f184740:	8c8d008c */ 	lw	$t5,0x8c($a0)
/*  f184744:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184748:
/*  f184748:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f18474c:	240304b0 */ 	addiu	$v1,$zero,0x4b0
/*  f184750:	8c480000 */ 	lw	$t0,0x0($v0)
.NB0f184754:
/*  f184754:	8c990068 */ 	lw	$t9,0x68($a0)
/*  f184758:	8fae0024 */ 	lw	$t6,0x24($sp)
/*  f18475c:	01030019 */ 	multu	$t0,$v1
/*  f184760:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f184764:	25cc0001 */ 	addiu	$t4,$t6,0x1
/*  f184768:	00007812 */ 	mflo	$t7
/*  f18476c:	032f082b */ 	sltu	$at,$t9,$t7
/*  f184770:	14200003 */ 	bnez	$at,.NB0f184780
/*  f184774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184778:	10000003 */ 	beqz	$zero,.NB0f184788
/*  f18477c:	afac0024 */ 	sw	$t4,0x24($sp)
.NB0f184780:
/*  f184780:	10000005 */ 	beqz	$zero,.NB0f184798
/*  f184784:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184788:
/*  f184788:	0045082b */ 	sltu	$at,$v0,$a1
/*  f18478c:	5420fff1 */ 	bnezl	$at,.NB0f184754
/*  f184790:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f184794:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184798:
/*  f184798:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f18479c:	24030064 */ 	addiu	$v1,$zero,0x64
/*  f1847a0:	8c4d0000 */ 	lw	$t5,0x0($v0)
.NB0f1847a4:
/*  f1847a4:	8c8b006c */ 	lw	$t3,0x6c($a0)
/*  f1847a8:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f1847ac:	01a30019 */ 	multu	$t5,$v1
/*  f1847b0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1847b4:	25380001 */ 	addiu	$t8,$t1,0x1
/*  f1847b8:	00005012 */ 	mflo	$t2
/*  f1847bc:	016a082b */ 	sltu	$at,$t3,$t2
/*  f1847c0:	14200003 */ 	bnez	$at,.NB0f1847d0
/*  f1847c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1847c8:	10000003 */ 	beqz	$zero,.NB0f1847d8
/*  f1847cc:	afb80028 */ 	sw	$t8,0x28($sp)
.NB0f1847d0:
/*  f1847d0:	10000005 */ 	beqz	$zero,.NB0f1847e8
/*  f1847d4:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f1847d8:
/*  f1847d8:	0045082b */ 	sltu	$at,$v0,$a1
/*  f1847dc:	5420fff1 */ 	bnezl	$at,.NB0f1847a4
/*  f1847e0:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f1847e4:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f1847e8:
/*  f1847e8:	27a30060 */ 	addiu	$v1,$sp,0x60
/*  f1847ec:	8c880074 */ 	lw	$t0,0x74($a0)
.NB0f1847f0:
/*  f1847f0:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f1847f4:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f1847f8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1847fc:	0119082b */ 	sltu	$at,$t0,$t9
/*  f184800:	14200003 */ 	bnez	$at,.NB0f184810
/*  f184804:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f184808:	10000003 */ 	beqz	$zero,.NB0f184818
/*  f18480c:	afae002c */ 	sw	$t6,0x2c($sp)
.NB0f184810:
/*  f184810:	10000005 */ 	beqz	$zero,.NB0f184828
/*  f184814:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184818:
/*  f184818:	0043082b */ 	sltu	$at,$v0,$v1
/*  f18481c:	5420fff4 */ 	bnezl	$at,.NB0f1847f0
/*  f184820:	8c880074 */ 	lw	$t0,0x74($a0)
/*  f184824:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184828:
/*  f184828:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f18482c:	240301f4 */ 	addiu	$v1,$zero,0x1f4
/*  f184830:	8c4d0000 */ 	lw	$t5,0x0($v0)
.NB0f184834:
/*  f184834:	8c8c0080 */ 	lw	$t4,0x80($a0)
/*  f184838:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f18483c:	01a30019 */ 	multu	$t5,$v1
/*  f184840:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f184844:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f184848:	00005812 */ 	mflo	$t3
/*  f18484c:	018b082b */ 	sltu	$at,$t4,$t3
/*  f184850:	14200003 */ 	bnez	$at,.NB0f184860
/*  f184854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184858:	10000003 */ 	beqz	$zero,.NB0f184868
/*  f18485c:	afa90030 */ 	sw	$t1,0x30($sp)
.NB0f184860:
/*  f184860:	10000005 */ 	beqz	$zero,.NB0f184878
/*  f184864:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184868:
/*  f184868:	0045082b */ 	sltu	$at,$v0,$a1
/*  f18486c:	5420fff1 */ 	bnezl	$at,.NB0f184834
/*  f184870:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f184874:	27a20038 */ 	addiu	$v0,$sp,0x38
.NB0f184878:
/*  f184878:	27a30060 */ 	addiu	$v1,$sp,0x60
/*  f18487c:	8c980090 */ 	lw	$t8,0x90($a0)
.NB0f184880:
/*  f184880:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f184884:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f184888:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18488c:	0308082b */ 	sltu	$at,$t8,$t0
/*  f184890:	14200003 */ 	bnez	$at,.NB0f1848a0
/*  f184894:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f184898:	10000003 */ 	beqz	$zero,.NB0f1848a8
/*  f18489c:	afaf0034 */ 	sw	$t7,0x34($sp)
.NB0f1848a0:
/*  f1848a0:	10000005 */ 	beqz	$zero,.NB0f1848b8
/*  f1848a4:	00001025 */ 	or	$v0,$zero,$zero
.NB0f1848a8:
/*  f1848a8:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1848ac:	5420fff4 */ 	bnezl	$at,.NB0f184880
/*  f1848b0:	8c980090 */ 	lw	$t8,0x90($a0)
/*  f1848b4:	00001025 */ 	or	$v0,$zero,$zero
.NB0f1848b8:
/*  f1848b8:	27a30010 */ 	addiu	$v1,$sp,0x10
/*  f1848bc:	27a50038 */ 	addiu	$a1,$sp,0x38
.NB0f1848c0:
/*  f1848c0:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f1848c4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1848c8:	1465fffd */ 	bne	$v1,$a1,.NB0f1848c0
/*  f1848cc:	01c21021 */ 	addu	$v0,$t6,$v0
/*  f1848d0:	28410065 */ 	slti	$at,$v0,0x65
/*  f1848d4:	14200002 */ 	bnez	$at,.NB0f1848e0
/*  f1848d8:	240b0014 */ 	addiu	$t3,$zero,0x14
/*  f1848dc:	24020064 */ 	addiu	$v0,$zero,0x64
.NB0f1848e0:
/*  f1848e0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1848e4:	0041001a */ 	div	$zero,$v0,$at
/*  f1848e8:	00006812 */ 	mflo	$t5
/*  f1848ec:	31ac00ff */ 	andi	$t4,$t5,0xff
/*  f1848f0:	29810015 */ 	slti	$at,$t4,0x15
/*  f1848f4:	14200002 */ 	bnez	$at,.NB0f184900
/*  f1848f8:	a08d0095 */ 	sb	$t5,0x95($a0)
/*  f1848fc:	a08b0095 */ 	sb	$t3,0x95($a0)
.NB0f184900:
/*  f184900:	03e00008 */ 	jr	$ra
/*  f184904:	27bd0060 */ 	addiu	$sp,$sp,0x60
);
#endif

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b8ad0[] = "%s%sAccuracy Peak! real value: %f (*100)\n";
const char var7f1b8afc[] = "";
const char var7f1b8b00[] = "";
const char var7f1b8b04[] = "%splayer %d Accuracy :%f\n";
const char var7f1b8b20[] = "";
const char var7f1b8b24[] = "%splayer %d dist:%f -> %f = %d\n";
const char var7f1b8b44[] = "";
const char var7f1b8b48[] = "Player %d TitleCalc ============\n";
#else
const u32 var7f1b3324nb[] = {2, 4, 8, 0x10, 0x1c, 0x30, 0x4e, 0x8a, 0xc6, 0x12c };
#endif

const char var7f1b8b6c[] = "Sim\n";
const char var7f1b8b74[] = "%s:%d\n";
const char var7f1b8b7c[] = "%s\n";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b8b80[] = "Adding GBCHead to load to slot %d: guid is %x-%x, player is %d\n";
const char var7f1b8bc0[] = "PakId for player %d: %d\n";
const char var7f1b8bdc[] = "Save Player Result: %d   New GUID: %x\n";
const char var7f1b8c04[] = "PakId for player %d: %d\n";
const char var7f1b8c20[] = "Load Player - Result: %d\n";
#endif

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
	{ SIMTYPE_GENERAL, SIMDIFF_MEAT,    L_MISC_088,  MPBODY_DD_GUARD,      0                         },
	{ SIMTYPE_GENERAL, SIMDIFF_EASY,    L_MISC_089,  MPBODY_DD_SECGUARD,   0                         },
	{ SIMTYPE_GENERAL, SIMDIFF_NORMAL,  L_MISC_090,  MPBODY_DD_SHOCK_INF,  0                         },
	{ SIMTYPE_GENERAL, SIMDIFF_HARD,    L_MISC_091,  MPBODY_DDSHOCK,       MPFEATURE_SIMDIFF_HARD    },
	{ SIMTYPE_GENERAL, SIMDIFF_PERFECT, L_MISC_092,  MPBODY_STRIPES,       MPFEATURE_SIMDIFF_PERFECT },
	{ SIMTYPE_GENERAL, SIMDIFF_DARK,    L_MISC_093,  MPBODY_MOORE,         MPFEATURE_SIMDIFF_DARK    },
	{ SIMTYPE_PEACE,   SIMDIFF_NORMAL,  L_MISC_094,  MPBODY_DD_LABTECH,    0                         },
	{ SIMTYPE_SHIELD,  SIMDIFF_NORMAL,  L_MISC_095,  MPBODY_G5_SWAT_GUARD, 0                         },
	{ SIMTYPE_ROCKET,  SIMDIFF_NORMAL,  L_MISC_096,  MPBODY_G5_GUARD,      0                         },
	{ SIMTYPE_KAZE,    SIMDIFF_NORMAL,  L_MISC_097,  MPBODY_PRES_SECURITY, 0                         },
	{ SIMTYPE_FIST,    SIMDIFF_NORMAL,  L_MISC_098,  MPBODY_PELAGIC_GUARD, 0                         },
	{ SIMTYPE_PREY,    SIMDIFF_NORMAL,  L_MISC_099,  MPBODY_DDSHOCK,       0                         },
	{ SIMTYPE_COWARD,  SIMDIFF_NORMAL,  L_MISC_100, MPBODY_PRESIDENT,     0                         },
	{ SIMTYPE_JUDGE,   SIMDIFF_NORMAL,  L_MISC_101, MPBODY_STEWARD,       0                         },
	{ SIMTYPE_FEUD,    SIMDIFF_NORMAL,  L_MISC_102, MPBODY_NSA_LACKEY,    0                         },
	{ SIMTYPE_SPEED,   SIMDIFF_NORMAL,  L_MISC_103, MPBODY_MRBLONDE,      0                         },
	{ SIMTYPE_TURTLE,  SIMDIFF_NORMAL,  L_MISC_104, MPBODY_CARRINGTON,    0                         },
	{ SIMTYPE_VENGE,   SIMDIFF_NORMAL,  L_MISC_105, MPBODY_ALASKAN_GUARD, 0                         },
};

// 2d7dc
struct mpbody g_MpBodies[NUM_MPBODIES] = {
	// global body ID,                name,             head,             require feature
	/*0x00*/ { BODY_DARK_COMBAT,      L_OPTIONS_016,    HEAD_DARK_COMBAT, 0               },
	/*0x01*/ { BODY_DARK_TRENCH,      L_OPTIONS_017,    HEAD_DARK_COMBAT, MPFEATURE_46    },
	/*0x02*/ { BODY_DARK_FROCK,       L_OPTIONS_018,    HEAD_DARK_FROCK,  MPFEATURE_41    },
	/*0x03*/ { BODY_DARK_RIPPED,      L_OPTIONS_019,    HEAD_DARK_FROCK,  MPFEATURE_41    },
	/*0x04*/ { BODY_DARK_AF1,         L_OPTIONS_020,    HEAD_DARK_COMBAT, MPFEATURE_3F    },
	/*0x05*/ { BODY_DARK_LEATHER,     L_MPWEAPONS_156, HEAD_DARK_COMBAT, MPFEATURE_37    },
	/*0x06*/ { BODY_DARK_NEGOTIATOR,  L_MPWEAPONS_157, HEAD_DARK_COMBAT, MPFEATURE_34    },
	/*0x07*/ { BODY_DARKWET,          L_OPTIONS_021,    HEAD_DARKAQUA,    MPFEATURE_45    },
	/*0x08*/ { BODY_DARKAQUALUNG,     L_OPTIONS_022,    HEAD_DARKAQUA,    MPFEATURE_45    },
	/*0x09*/ { BODY_DARKSNOW,         L_OPTIONS_023,    HEAD_DARK_SNOW,   MPFEATURE_4A    },
	/*0x0a*/ { BODY_DARKLAB,          L_OPTIONS_024,    HEAD_DARK_COMBAT, MPFEATURE_3A    },
	/*0x0b*/ { BODY_THEKING,          L_OPTIONS_025,    HEAD_ELVIS,       MPFEATURE_3D    },
	/*0x0c*/ { BODY_ELVIS1,           L_OPTIONS_026,    HEAD_ELVIS,       MPFEATURE_3D    },
	/*0x0d*/ { BODY_ELVISWAISTCOAT,   L_MPWEAPONS_158, HEAD_ELVIS,       MPFEATURE_3D    },
	/*0x0e*/ { BODY_CARRINGTON,       L_OPTIONS_027,    HEAD_CARRINGTON,  0               },
	/*0x0f*/ { BODY_CARREVENINGSUIT,  L_OPTIONS_028,    HEAD_CARRINGTON,  MPFEATURE_41    },
	/*0x10*/ { BODY_MRBLONDE,         L_OPTIONS_029,    HEAD_MRBLONDE,    MPFEATURE_38    },
	/*0x11*/ { BODY_CASSANDRA,        L_OPTIONS_030,    HEAD_CASSANDRA,   0               },
	/*0x12*/ { BODY_TRENT,            L_OPTIONS_031,    HEAD_TRENT,       MPFEATURE_35    },
	/*0x13*/ { BODY_JONATHAN,         L_OPTIONS_032,    HEAD_JONATHAN,    MPFEATURE_4C    },
	/*0x14*/ { BODY_CILABTECH,        L_OPTIONS_033,    1000,             0               },
	/*0x15*/ { BODY_CIFEMTECH,        L_OPTIONS_034,    1000,             0               },
	/*0x16*/ { BODY_CISOLDIER,        L_OPTIONS_035,    1000,             0               },
	/*0x17*/ { BODY_DDSHOCK,          L_OPTIONS_036,    HEAD_DDSHOCK,     0               },
	/*0x18*/ { BODY_FEM_GUARD,        L_OPTIONS_037,    1000,             MPFEATURE_32    },
	/*0x19*/ { BODY_DD_SECGUARD,      L_OPTIONS_038,    1000,             0               },
	/*0x1a*/ { BODY_DD_GUARD,         L_OPTIONS_039,    1000,             0               },
	/*0x1b*/ { BODY_DD_SHOCK_INF,     L_OPTIONS_040,    1000,             0               },
	/*0x1c*/ { BODY_SECRETARY,        L_OPTIONS_041,    1000,             0               },
	/*0x1d*/ { BODY_OFFICEWORKER,     L_OPTIONS_042,    1000,             MPFEATURE_33    },
	/*0x1e*/ { BODY_OFFICEWORKER2,    L_OPTIONS_043,    1000,             MPFEATURE_33    },
	/*0x1f*/ { BODY_NEGOTIATOR,       L_OPTIONS_044,    1000,             MPFEATURE_34    },
	/*0x20*/ { BODY_DDSNIPER,         L_OPTIONS_045,    HEAD_DDSNIPER,    MPFEATURE_34    },
	/*0x21*/ { BODY_G5_GUARD,         L_OPTIONS_046,    1000,             MPFEATURE_37    },
	/*0x22*/ { BODY_G5_SWAT_GUARD,    L_OPTIONS_047,    1000,             MPFEATURE_37    },
	/*0x23*/ { BODY_CIAGUY,           L_OPTIONS_048,    1000,             MPFEATURE_39    },
	/*0x24*/ { BODY_FBIGUY,           L_OPTIONS_049,    1000,             MPFEATURE_39    },
	/*0x25*/ { BODY_AREA51GUARD,      L_OPTIONS_050,    1000,             MPFEATURE_3A    },
	/*0x26*/ { BODY_A51TROOPER,       L_OPTIONS_051,    1000,             MPFEATURE_3A    },
	/*0x27*/ { BODY_A51AIRMAN,        L_OPTIONS_052,    1000,             MPFEATURE_3A    },
	/*0x28*/ { BODY_OVERALL,          L_OPTIONS_053,    1000,             MPFEATURE_3A    },
	/*0x29*/ { BODY_STRIPES,          L_OPTIONS_054,    1000,             MPFEATURE_44    },
	/*0x2a*/ { BODY_LABTECH,          L_OPTIONS_055,    1000,             MPFEATURE_3B    },
	/*0x2b*/ { BODY_FEMLABTECH,       L_OPTIONS_056,    1000,             MPFEATURE_3B    },
	/*0x2c*/ { BODY_DD_LABTECH,       L_OPTIONS_057,    1000,             MPFEATURE_3B    },
	/*0x2d*/ { BODY_BIOTECH,          L_OPTIONS_058,    HEAD_BIOTECH,     MPFEATURE_3C    },
	/*0x2e*/ { BODY_ALASKAN_GUARD,    L_OPTIONS_059,    1000,             MPFEATURE_3E    },
	/*0x2f*/ { BODY_PILOTAF1,         L_OPTIONS_060,    1000,             MPFEATURE_3F    },
	/*0x30*/ { BODY_STEWARD,          L_OPTIONS_061,    1000,             MPFEATURE_3F    },
	/*0x31*/ { BODY_STEWARDESS,       L_OPTIONS_062,    1000,             MPFEATURE_3F    },
	/*0x32*/ { BODY_STEWARDESS_COAT,  L_OPTIONS_063,    1000,             MPFEATURE_3F    },
	/*0x33*/ { BODY_PRESIDENT,        L_OPTIONS_064,    HEAD_PRESIDENT,   MPFEATURE_41    },
	/*0x34*/ { BODY_NSA_LACKEY,       L_OPTIONS_065,    1000,             MPFEATURE_36    },
	/*0x35*/ { BODY_PRES_SECURITY,    L_OPTIONS_066,    1000,             MPFEATURE_43    },
	/*0x36*/ { BODY_PRESIDENT_CLONE2, L_OPTIONS_067,    HEAD_PRESIDENT,   MPFEATURE_42    },
	/*0x37*/ { BODY_PELAGIC_GUARD,    L_OPTIONS_068,    1000,             MPFEATURE_45    },
	/*0x38*/ { BODY_MAIAN_SOLDIER,    L_OPTIONS_069,    HEAD_MAIAN_S,     MPFEATURE_3D    },
	/*0x39*/ { BODY_CONNERY,          L_OPTIONS_070,    1000,             MPFEATURE_8BOTS },
	/*0x3a*/ { BODY_MOORE,            L_OPTIONS_070,    1000,             MPFEATURE_8BOTS },
	/*0x3b*/ { BODY_DALTON,           L_OPTIONS_070,    1000,             MPFEATURE_8BOTS },
	/*0x3c*/ { BODY_DJBOND,           L_OPTIONS_070,    1000,             MPFEATURE_8BOTS },
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

#if VERSION >= VERSION_NTSC_1_0
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
#else
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
/*  f184908:	27bdfdf0 */ 	addiu	$sp,$sp,-528
/*  f18490c:	3c02800a */ 	lui	$v0,0x800a
/*  f184910:	2442e6c0 */ 	addiu	$v0,$v0,-6464
/*  f184914:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f184918:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f18491c:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f184920:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f184924:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f184928:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f18492c:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f184930:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f184934:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f184938:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f18493c:	11c00004 */ 	beqz	$t6,.NB0f184950
/*  f184940:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f184944:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f184948:	10000002 */ 	beqz	$zero,.NB0f184954
/*  f18494c:	afaf006c */ 	sw	$t7,0x6c($sp)
.NB0f184950:
/*  f184950:	afa0006c */ 	sw	$zero,0x6c($sp)
.NB0f184954:
/*  f184954:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f184958:	13000003 */ 	beqz	$t8,.NB0f184968
/*  f18495c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f184960:	10000002 */ 	beqz	$zero,.NB0f18496c
/*  f184964:	afb90070 */ 	sw	$t9,0x70($sp)
.NB0f184968:
/*  f184968:	afa00070 */ 	sw	$zero,0x70($sp)
.NB0f18496c:
/*  f18496c:	8c4d0064 */ 	lw	$t5,0x64($v0)
/*  f184970:	11a00003 */ 	beqz	$t5,.NB0f184980
/*  f184974:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f184978:	10000002 */ 	beqz	$zero,.NB0f184984
/*  f18497c:	afae0074 */ 	sw	$t6,0x74($sp)
.NB0f184980:
/*  f184980:	afa00074 */ 	sw	$zero,0x74($sp)
.NB0f184984:
/*  f184984:	8c4f0070 */ 	lw	$t7,0x70($v0)
/*  f184988:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f18498c:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f184990:	51e00004 */ 	beqzl	$t7,.NB0f1849a4
/*  f184994:	00009025 */ 	or	$s2,$zero,$zero
/*  f184998:	10000002 */ 	beqz	$zero,.NB0f1849a4
/*  f18499c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f1849a0:	00009025 */ 	or	$s2,$zero,$zero
.NB0f1849a4:
/*  f1849a4:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f1849a8:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f1849ac:	032d7021 */ 	addu	$t6,$t9,$t5
/*  f1849b0:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f1849b4:	0fc2ff91 */ 	jal	getMissionTime
/*  f1849b8:	afb0020c */ 	sw	$s0,0x20c($sp)
/*  f1849bc:	0c00d474 */ 	jal	func00033dd8
/*  f1849c0:	afa201fc */ 	sw	$v0,0x1fc($sp)
/*  f1849c4:	0fc60a7a */ 	jal	mpGetPlayerRankings
/*  f1849c8:	27a400f8 */ 	addiu	$a0,$sp,0xf8
/*  f1849cc:	3c18800a */ 	lui	$t8,0x800a
/*  f1849d0:	8f18e94c */ 	lw	$t8,-0x16b4($t8)
/*  f1849d4:	afa200f4 */ 	sw	$v0,0xf4($sp)
/*  f1849d8:	0000b025 */ 	or	$s6,$zero,$zero
/*  f1849dc:	1a0001dc */ 	blez	$s0,.NB0f185150
/*  f1849e0:	afb80200 */ 	sw	$t8,0x200($sp)
/*  f1849e4:	8fb901fc */ 	lw	$t9,0x1fc($sp)
/*  f1849e8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1849ec:	c4283380 */ 	lwc1	$f8,0x3380($at)
/*  f1849f0:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f1849f4:	448d2000 */ 	mtc1	$t5,$f4
/*  f1849f8:	3c14800a */ 	lui	$s4,0x800a
/*  f1849fc:	3c1e800b */ 	lui	$s8,0x800b
/*  f184a00:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f184a04:	3c11800b */ 	lui	$s1,0x800b
/*  f184a08:	26311438 */ 	addiu	$s1,$s1,0x1438
/*  f184a0c:	27de1068 */ 	addiu	$s8,$s8,0x1068
/*  f184a10:	2694e6c0 */ 	addiu	$s4,$s4,-6464
/*  f184a14:	27b3010c */ 	addiu	$s3,$sp,0x10c
/*  f184a18:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f184a1c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f184a20:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f184a24:	e7aa004c */ 	swc1	$f10,0x4c($sp)
.NB0f184a28:
/*  f184a28:	0fc61a7b */ 	jal	func0f18c794
/*  f184a2c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f184a30:	00409025 */ 	or	$s2,$v0,$zero
/*  f184a34:	00408025 */ 	or	$s0,$v0,$zero
/*  f184a38:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f184a3c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f184a40:	3c02800a */ 	lui	$v0,0x800a
/*  f184a44:	2442e6c0 */ 	addiu	$v0,$v0,-6464
/*  f184a48:	8c4e0284 */ 	lw	$t6,0x284($v0)
/*  f184a4c:	00002025 */ 	or	$a0,$zero,$zero
/*  f184a50:	adc01974 */ 	sw	$zero,0x1974($t6)
/*  f184a54:	8c4f0284 */ 	lw	$t7,0x284($v0)
/*  f184a58:	0fc2b8a3 */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f184a5c:	ade01978 */ 	sw	$zero,0x1978($t7)
/*  f184a60:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f184a64:	0fc2b8a3 */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f184a68:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f184a6c:	ae620004 */ 	sw	$v0,0x4($s3)
/*  f184a70:	ae600008 */ 	sw	$zero,0x8($s3)
/*  f184a74:	ae60000c */ 	sw	$zero,0xc($s3)
/*  f184a78:	ae600010 */ 	sw	$zero,0x10($s3)
/*  f184a7c:	00163040 */ 	sll	$a2,$s6,0x1
/*  f184a80:	00002025 */ 	or	$a0,$zero,$zero
/*  f184a84:	02402825 */ 	or	$a1,$s2,$zero
.NB0f184a88:
/*  f184a88:	54c40007 */ 	bnel	$a2,$a0,.NB0f184aa8
/*  f184a8c:	8e6e0008 */ 	lw	$t6,0x8($s3)
/*  f184a90:	8e780010 */ 	lw	$t8,0x10($s3)
/*  f184a94:	84b90024 */ 	lh	$t9,0x24($a1)
/*  f184a98:	03196821 */ 	addu	$t5,$t8,$t9
/*  f184a9c:	10000005 */ 	beqz	$zero,.NB0f184ab4
/*  f184aa0:	ae6d0010 */ 	sw	$t5,0x10($s3)
/*  f184aa4:	8e6e0008 */ 	lw	$t6,0x8($s3)
.NB0f184aa8:
/*  f184aa8:	84af0024 */ 	lh	$t7,0x24($a1)
/*  f184aac:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f184ab0:	ae780008 */ 	sw	$t8,0x8($s3)
.NB0f184ab4:
/*  f184ab4:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f184ab8:	28810018 */ 	slti	$at,$a0,0x18
/*  f184abc:	1420fff2 */ 	bnez	$at,.NB0f184a88
/*  f184ac0:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f184ac4:	00001825 */ 	or	$v1,$zero,$zero
/*  f184ac8:	240500a0 */ 	addiu	$a1,$zero,0xa0
.NB0f184acc:
/*  f184acc:	28610004 */ 	slti	$at,$v1,0x4
/*  f184ad0:	10200006 */ 	beqz	$at,.NB0f184aec
/*  f184ad4:	00036880 */ 	sll	$t5,$v1,0x2
/*  f184ad8:	00650019 */ 	multu	$v1,$a1
/*  f184adc:	0000c812 */ 	mflo	$t9
/*  f184ae0:	03d91021 */ 	addu	$v0,$s8,$t9
/*  f184ae4:	1000000a */ 	beqz	$zero,.NB0f184b10
/*  f184ae8:	0055c821 */ 	addu	$t9,$v0,$s5
.NB0f184aec:
/*  f184aec:	01a36821 */ 	addu	$t5,$t5,$v1
/*  f184af0:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f184af4:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f184af8:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f184afc:	3c0f800b */ 	lui	$t7,0x800b
/*  f184b00:	25ef0de8 */ 	addiu	$t7,$t7,0xde8
/*  f184b04:	25aefed0 */ 	addiu	$t6,$t5,-304
/*  f184b08:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f184b0c:	0055c821 */ 	addu	$t9,$v0,$s5
.NB0f184b10:
/*  f184b10:	872d0024 */ 	lh	$t5,0x24($t9)
/*  f184b14:	8e78000c */ 	lw	$t8,0xc($s3)
/*  f184b18:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f184b1c:	2861000c */ 	slti	$at,$v1,0xc
/*  f184b20:	030d7021 */ 	addu	$t6,$t8,$t5
/*  f184b24:	1420ffe9 */ 	bnez	$at,.NB0f184acc
/*  f184b28:	ae6e000c */ 	sw	$t6,0xc($s3)
/*  f184b2c:	8e6f0008 */ 	lw	$t7,0x8($s3)
/*  f184b30:	3c013f80 */ 	lui	$at,0x3f80
/*  f184b34:	44811000 */ 	mtc1	$at,$f2
/*  f184b38:	448f8000 */ 	mtc1	$t7,$f16
/*  f184b3c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f184b40:	44812000 */ 	mtc1	$at,$f4
/*  f184b44:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f184b48:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f184b4c:	01c0c025 */ 	or	$t8,$t6,$zero
/*  f184b50:	8e8d00b0 */ 	lw	$t5,0xb0($s4)
/*  f184b54:	44993000 */ 	mtc1	$t9,$f6
/*  f184b58:	8e8e00a8 */ 	lw	$t6,0xa8($s4)
/*  f184b5c:	46049002 */ 	mul.s	$f0,$f18,$f4
/*  f184b60:	44989000 */ 	mtc1	$t8,$f18
/*  f184b64:	3c017f1b */ 	lui	$at,0x7f1b
/*  f184b68:	ae6d001c */ 	sw	$t5,0x1c($s3)
/*  f184b6c:	ae6e0020 */ 	sw	$t6,0x20($s3)
/*  f184b70:	8e8f00c0 */ 	lw	$t7,0xc0($s4)
/*  f184b74:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f184b78:	8e9900c4 */ 	lw	$t9,0xc4($s4)
/*  f184b7c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f184b80:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f184b84:	46024280 */ 	add.s	$f10,$f8,$f2
/*  f184b88:	46022180 */ 	add.s	$f6,$f4,$f2
/*  f184b8c:	460a0403 */ 	div.s	$f16,$f0,$f10
/*  f184b90:	c68a00ac */ 	lwc1	$f10,0xac($s4)
/*  f184b94:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f184b98:	e6700014 */ 	swc1	$f16,0x14($s3)
/*  f184b9c:	e6680018 */ 	swc1	$f8,0x18($s3)
/*  f184ba0:	c4303384 */ 	lwc1	$f16,0x3384($at)
/*  f184ba4:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f184ba8:	c68800b4 */ 	lwc1	$f8,0xb4($s4)
/*  f184bac:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f184bb0:	ae60002c */ 	sw	$zero,0x2c($s3)
/*  f184bb4:	ae6f0030 */ 	sw	$t7,0x30($s3)
/*  f184bb8:	ae790034 */ 	sw	$t9,0x34($s3)
/*  f184bbc:	e6680028 */ 	swc1	$f8,0x28($s3)
/*  f184bc0:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f184bc4:	0fc2b8a3 */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f184bc8:	e6660024 */ 	swc1	$f6,0x24($s3)
/*  f184bcc:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f184bd0:	0fc2b8a3 */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f184bd4:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f184bd8:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f184bdc:	0fc2b8a3 */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f184be0:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f184be4:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f184be8:	0fc2b8a3 */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f184bec:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f184bf0:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f184bf4:	0fc2b8a3 */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f184bf8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f184bfc:	00409025 */ 	or	$s2,$v0,$zero
/*  f184c00:	0fc2b8a3 */ 	jal	mpstatsGetPlayerShotCountByRegion
/*  f184c04:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f184c08:	8e630000 */ 	lw	$v1,0x0($s3)
/*  f184c0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f184c10:	44810000 */ 	mtc1	$at,$f0
/*  f184c14:	18600011 */ 	blez	$v1,.NB0f184c5c
/*  f184c18:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f184c1c:	8fad0074 */ 	lw	$t5,0x74($sp)
/*  f184c20:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f184c24:	0052c021 */ 	addu	$t8,$v0,$s2
/*  f184c28:	030d7021 */ 	addu	$t6,$t8,$t5
/*  f184c2c:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f184c30:	01cfc821 */ 	addu	$t9,$t6,$t7
/*  f184c34:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f184c38:	03386821 */ 	addu	$t5,$t9,$t8
/*  f184c3c:	44839000 */ 	mtc1	$v1,$f18
/*  f184c40:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f184c44:	448f5000 */ 	mtc1	$t7,$f10
/*  f184c48:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f184c4c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f184c50:	46048183 */ 	div.s	$f6,$f16,$f4
/*  f184c54:	10000004 */ 	beqz	$zero,.NB0f184c68
/*  f184c58:	e6660038 */ 	swc1	$f6,0x38($s3)
.NB0f184c5c:
/*  f184c5c:	44804000 */ 	mtc1	$zero,$f8
/*  f184c60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184c64:	e6680038 */ 	swc1	$f8,0x38($s3)
.NB0f184c68:
/*  f184c68:	c66a0038 */ 	lwc1	$f10,0x38($s3)
/*  f184c6c:	3c19800a */ 	lui	$t9,0x800a
/*  f184c70:	3c18800a */ 	lui	$t8,0x800a
/*  f184c74:	460a003c */ 	c.lt.s	$f0,$f10
/*  f184c78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184c7c:	45020003 */ 	bc1fl	.NB0f184c8c
/*  f184c80:	a2000094 */ 	sb	$zero,0x94($s0)
/*  f184c84:	e6600038 */ 	swc1	$f0,0x38($s3)
/*  f184c88:	a2000094 */ 	sb	$zero,0x94($s0)
.NB0f184c8c:
/*  f184c8c:	8f3966c0 */ 	lw	$t9,0x66c0($t9)
/*  f184c90:	5720012b */ 	bnezl	$t9,.NB0f185140
/*  f184c94:	8fad020c */ 	lw	$t5,0x20c($sp)
/*  f184c98:	8f1866c4 */ 	lw	$t8,0x66c4($t8)
/*  f184c9c:	57000128 */ 	bnezl	$t8,.NB0f185140
/*  f184ca0:	8fad020c */ 	lw	$t5,0x20c($sp)
/*  f184ca4:	8e0d0054 */ 	lw	$t5,0x54($s0)
/*  f184ca8:	8e6e0008 */ 	lw	$t6,0x8($s3)
/*  f184cac:	8e190058 */ 	lw	$t9,0x58($s0)
/*  f184cb0:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f184cb4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f184cb8:	ae0f0054 */ 	sw	$t7,0x54($s0)
/*  f184cbc:	8e78000c */ 	lw	$t8,0xc($s3)
/*  f184cc0:	8e0e005c */ 	lw	$t6,0x5c($s0)
/*  f184cc4:	03386821 */ 	addu	$t5,$t9,$t8
/*  f184cc8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f184ccc:	ae0d0058 */ 	sw	$t5,0x58($s0)
/*  f184cd0:	ae0f005c */ 	sw	$t7,0x5c($s0)
/*  f184cd4:	8fb801fc */ 	lw	$t8,0x1fc($sp)
/*  f184cd8:	8e190068 */ 	lw	$t9,0x68($s0)
/*  f184cdc:	0301001a */ 	div	$zero,$t8,$at
/*  f184ce0:	00006812 */ 	mflo	$t5
/*  f184ce4:	032d7021 */ 	addu	$t6,$t9,$t5
/*  f184ce8:	ae0e0068 */ 	sw	$t6,0x68($s0)
/*  f184cec:	3c017f1b */ 	lui	$at,0x7f1b
/*  f184cf0:	c4303388 */ 	lwc1	$f16,0x3388($at)
/*  f184cf4:	c69200ac */ 	lwc1	$f18,0xac($s4)
/*  f184cf8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f184cfc:	3c014f00 */ 	lui	$at,0x4f00
/*  f184d00:	46109103 */ 	div.s	$f4,$f18,$f16
/*  f184d04:	444ff800 */ 	cfc1	$t7,$31
/*  f184d08:	44d8f800 */ 	ctc1	$t8,$31
/*  f184d0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184d10:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f184d14:	4458f800 */ 	cfc1	$t8,$31
/*  f184d18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184d1c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f184d20:	53000013 */ 	beqzl	$t8,.NB0f184d70
/*  f184d24:	44183000 */ 	mfc1	$t8,$f6
/*  f184d28:	44813000 */ 	mtc1	$at,$f6
/*  f184d2c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f184d30:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f184d34:	44d8f800 */ 	ctc1	$t8,$31
/*  f184d38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184d3c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f184d40:	4458f800 */ 	cfc1	$t8,$31
/*  f184d44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184d48:	33180078 */ 	andi	$t8,$t8,0x78
/*  f184d4c:	17000005 */ 	bnez	$t8,.NB0f184d64
/*  f184d50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184d54:	44183000 */ 	mfc1	$t8,$f6
/*  f184d58:	3c018000 */ 	lui	$at,0x8000
/*  f184d5c:	10000007 */ 	beqz	$zero,.NB0f184d7c
/*  f184d60:	0301c025 */ 	or	$t8,$t8,$at
.NB0f184d64:
/*  f184d64:	10000005 */ 	beqz	$zero,.NB0f184d7c
/*  f184d68:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f184d6c:	44183000 */ 	mfc1	$t8,$f6
.NB0f184d70:
/*  f184d70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184d74:	0700fffb */ 	bltz	$t8,.NB0f184d64
/*  f184d78:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f184d7c:
/*  f184d7c:	8e19006c */ 	lw	$t9,0x6c($s0)
/*  f184d80:	8e0e0070 */ 	lw	$t6,0x70($s0)
/*  f184d84:	3c017f1b */ 	lui	$at,0x7f1b
/*  f184d88:	03386821 */ 	addu	$t5,$t9,$t8
/*  f184d8c:	ae0d006c */ 	sw	$t5,0x6c($s0)
/*  f184d90:	44cff800 */ 	ctc1	$t7,$31
/*  f184d94:	c42a338c */ 	lwc1	$f10,0x338c($at)
/*  f184d98:	c6680038 */ 	lwc1	$f8,0x38($s3)
/*  f184d9c:	448e8000 */ 	mtc1	$t6,$f16
/*  f184da0:	3c014f80 */ 	lui	$at,0x4f80
/*  f184da4:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f184da8:	05c10004 */ 	bgez	$t6,.NB0f184dbc
/*  f184dac:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f184db0:	44813000 */ 	mtc1	$at,$f6
/*  f184db4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184db8:	46062100 */ 	add.s	$f4,$f4,$f6
.NB0f184dbc:
/*  f184dbc:	3c01447a */ 	lui	$at,0x447a
/*  f184dc0:	44814000 */ 	mtc1	$at,$f8
/*  f184dc4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f184dc8:	c4303390 */ 	lwc1	$f16,0x3390($at)
/*  f184dcc:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f184dd0:	3c01447a */ 	lui	$at,0x447a
/*  f184dd4:	44814000 */ 	mtc1	$at,$f8
/*  f184dd8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f184ddc:	3c014f00 */ 	lui	$at,0x4f00
/*  f184de0:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f184de4:	46069100 */ 	add.s	$f4,$f18,$f6
/*  f184de8:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f184dec:	444ff800 */ 	cfc1	$t7,$31
/*  f184df0:	44d9f800 */ 	ctc1	$t9,$31
/*  f184df4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184df8:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f184dfc:	4459f800 */ 	cfc1	$t9,$31
/*  f184e00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184e04:	33390078 */ 	andi	$t9,$t9,0x78
/*  f184e08:	53200013 */ 	beqzl	$t9,.NB0f184e58
/*  f184e0c:	44198000 */ 	mfc1	$t9,$f16
/*  f184e10:	44818000 */ 	mtc1	$at,$f16
/*  f184e14:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f184e18:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f184e1c:	44d9f800 */ 	ctc1	$t9,$31
/*  f184e20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184e24:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f184e28:	4459f800 */ 	cfc1	$t9,$31
/*  f184e2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184e30:	33390078 */ 	andi	$t9,$t9,0x78
/*  f184e34:	17200005 */ 	bnez	$t9,.NB0f184e4c
/*  f184e38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184e3c:	44198000 */ 	mfc1	$t9,$f16
/*  f184e40:	3c018000 */ 	lui	$at,0x8000
/*  f184e44:	10000007 */ 	beqz	$zero,.NB0f184e64
/*  f184e48:	0321c825 */ 	or	$t9,$t9,$at
.NB0f184e4c:
/*  f184e4c:	10000005 */ 	beqz	$zero,.NB0f184e64
/*  f184e50:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f184e54:	44198000 */ 	mfc1	$t9,$f16
.NB0f184e58:
/*  f184e58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184e5c:	0720fffb */ 	bltz	$t9,.NB0f184e4c
/*  f184e60:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f184e64:
/*  f184e64:	ae190070 */ 	sw	$t9,0x70($s0)
/*  f184e68:	3c017f1b */ 	lui	$at,0x7f1b
/*  f184e6c:	44cff800 */ 	ctc1	$t7,$31
/*  f184e70:	c4263394 */ 	lwc1	$f6,0x3394($at)
/*  f184e74:	c69200f0 */ 	lwc1	$f18,0xf0($s4)
/*  f184e78:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f184e7c:	3c014f00 */ 	lui	$at,0x4f00
/*  f184e80:	46069103 */ 	div.s	$f4,$f18,$f6
/*  f184e84:	4458f800 */ 	cfc1	$t8,$31
/*  f184e88:	44cdf800 */ 	ctc1	$t5,$31
/*  f184e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184e90:	46002224 */ 	cvt.w.s	$f8,$f4
/*  f184e94:	444df800 */ 	cfc1	$t5,$31
/*  f184e98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184e9c:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f184ea0:	51a00013 */ 	beqzl	$t5,.NB0f184ef0
/*  f184ea4:	440d4000 */ 	mfc1	$t5,$f8
/*  f184ea8:	44814000 */ 	mtc1	$at,$f8
/*  f184eac:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f184eb0:	46082201 */ 	sub.s	$f8,$f4,$f8
/*  f184eb4:	44cdf800 */ 	ctc1	$t5,$31
/*  f184eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184ebc:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f184ec0:	444df800 */ 	cfc1	$t5,$31
/*  f184ec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184ec8:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f184ecc:	15a00005 */ 	bnez	$t5,.NB0f184ee4
/*  f184ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184ed4:	440d4000 */ 	mfc1	$t5,$f8
/*  f184ed8:	3c018000 */ 	lui	$at,0x8000
/*  f184edc:	10000007 */ 	beqz	$zero,.NB0f184efc
/*  f184ee0:	01a16825 */ 	or	$t5,$t5,$at
.NB0f184ee4:
/*  f184ee4:	10000005 */ 	beqz	$zero,.NB0f184efc
/*  f184ee8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f184eec:	440d4000 */ 	mfc1	$t5,$f8
.NB0f184ef0:
/*  f184ef0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184ef4:	05a0fffb */ 	bltz	$t5,.NB0f184ee4
/*  f184ef8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f184efc:
/*  f184efc:	8e0e0074 */ 	lw	$t6,0x74($s0)
/*  f184f00:	3c017f1b */ 	lui	$at,0x7f1b
/*  f184f04:	44d8f800 */ 	ctc1	$t8,$31
/*  f184f08:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f184f0c:	ae0f0074 */ 	sw	$t7,0x74($s0)
/*  f184f10:	c4303398 */ 	lwc1	$f16,0x3398($at)
/*  f184f14:	c68a00ec */ 	lwc1	$f10,0xec($s4)
/*  f184f18:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f184f1c:	3c014f00 */ 	lui	$at,0x4f00
/*  f184f20:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f184f24:	4459f800 */ 	cfc1	$t9,$31
/*  f184f28:	44d8f800 */ 	ctc1	$t8,$31
/*  f184f2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184f30:	460091a4 */ 	cvt.w.s	$f6,$f18
/*  f184f34:	4458f800 */ 	cfc1	$t8,$31
/*  f184f38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184f3c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f184f40:	53000013 */ 	beqzl	$t8,.NB0f184f90
/*  f184f44:	44183000 */ 	mfc1	$t8,$f6
/*  f184f48:	44813000 */ 	mtc1	$at,$f6
/*  f184f4c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f184f50:	46069181 */ 	sub.s	$f6,$f18,$f6
/*  f184f54:	44d8f800 */ 	ctc1	$t8,$31
/*  f184f58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184f5c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f184f60:	4458f800 */ 	cfc1	$t8,$31
/*  f184f64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184f68:	33180078 */ 	andi	$t8,$t8,0x78
/*  f184f6c:	17000005 */ 	bnez	$t8,.NB0f184f84
/*  f184f70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184f74:	44183000 */ 	mfc1	$t8,$f6
/*  f184f78:	3c018000 */ 	lui	$at,0x8000
/*  f184f7c:	10000007 */ 	beqz	$zero,.NB0f184f9c
/*  f184f80:	0301c025 */ 	or	$t8,$t8,$at
.NB0f184f84:
/*  f184f84:	10000005 */ 	beqz	$zero,.NB0f184f9c
/*  f184f88:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f184f8c:	44183000 */ 	mfc1	$t8,$f6
.NB0f184f90:
/*  f184f90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f184f94:	0700fffb */ 	bltz	$t8,.NB0f184f84
/*  f184f98:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f184f9c:
/*  f184f9c:	8e0e0078 */ 	lw	$t6,0x78($s0)
/*  f184fa0:	44d9f800 */ 	ctc1	$t9,$31
/*  f184fa4:	8e0f007c */ 	lw	$t7,0x7c($s0)
/*  f184fa8:	01d86821 */ 	addu	$t5,$t6,$t8
/*  f184fac:	ae0d0078 */ 	sw	$t5,0x78($s0)
/*  f184fb0:	8e790004 */ 	lw	$t9,0x4($s3)
/*  f184fb4:	8e180080 */ 	lw	$t8,0x80($s0)
/*  f184fb8:	01f97021 */ 	addu	$t6,$t7,$t9
/*  f184fbc:	ae0e007c */ 	sw	$t6,0x7c($s0)
/*  f184fc0:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f184fc4:	030d7821 */ 	addu	$t7,$t8,$t5
/*  f184fc8:	ae0f0080 */ 	sw	$t7,0x80($s0)
/*  f184fcc:	8fb900f4 */ 	lw	$t9,0xf4($sp)
/*  f184fd0:	2b210002 */ 	slti	$at,$t9,0x2
/*  f184fd4:	5420005a */ 	bnezl	$at,.NB0f185140
/*  f184fd8:	8fad020c */ 	lw	$t5,0x20c($sp)
/*  f184fdc:	8206001e */ 	lb	$a2,0x1e($s0)
/*  f184fe0:	2727ffff */ 	addiu	$a3,$t9,-1
/*  f184fe4:	00002825 */ 	or	$a1,$zero,$zero
/*  f184fe8:	14c00029 */ 	bnez	$a2,.NB0f185090
/*  f184fec:	00001825 */ 	or	$v1,$zero,$zero
/*  f184ff0:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f184ff4:	28610004 */ 	slti	$at,$v1,0x4
.NB0f184ff8:
/*  f184ff8:	10200006 */ 	beqz	$at,.NB0f185014
/*  f184ffc:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f185000:	00037080 */ 	sll	$t6,$v1,0x2
/*  f185004:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f185008:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f18500c:	10000009 */ 	beqz	$zero,.NB0f185034
/*  f185010:	03ce1021 */ 	addu	$v0,$s8,$t6
.NB0f185014:
/*  f185014:	0303c021 */ 	addu	$t8,$t8,$v1
/*  f185018:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f18501c:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f185020:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f185024:	3c0f800b */ 	lui	$t7,0x800b
/*  f185028:	25ef0de8 */ 	addiu	$t7,$t7,0xde8
/*  f18502c:	270dfed0 */ 	addiu	$t5,$t8,-304
/*  f185030:	01af1021 */ 	addu	$v0,$t5,$t7
.NB0f185034:
/*  f185034:	8c590020 */ 	lw	$t9,0x20($v0)
/*  f185038:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18503c:	1499000c */ 	bne	$a0,$t9,.NB0f185070
/*  f185040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185044:	1202000a */ 	beq	$s0,$v0,.NB0f185070
/*  f185048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18504c:	8e2e000c */ 	lw	$t6,0xc($s1)
/*  f185050:	31d80002 */ 	andi	$t8,$t6,0x2
/*  f185054:	53000006 */ 	beqzl	$t8,.NB0f185070
/*  f185058:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18505c:	920d0011 */ 	lbu	$t5,0x11($s0)
/*  f185060:	904f0011 */ 	lbu	$t7,0x11($v0)
/*  f185064:	11af0002 */ 	beq	$t5,$t7,.NB0f185070
/*  f185068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18506c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f185070:
/*  f185070:	5477ffe1 */ 	bnel	$v1,$s7,.NB0f184ff8
/*  f185074:	28610004 */ 	slti	$at,$v1,0x4
/*  f185078:	14a00005 */ 	bnez	$a1,.NB0f185090
/*  f18507c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185080:	8e190060 */ 	lw	$t9,0x60($s0)
/*  f185084:	8206001e */ 	lb	$a2,0x1e($s0)
/*  f185088:	272e0001 */ 	addiu	$t6,$t9,0x1
/*  f18508c:	ae0e0060 */ 	sw	$t6,0x60($s0)
.NB0f185090:
/*  f185090:	14e6002a */ 	bne	$a3,$a2,.NB0f18513c
/*  f185094:	00002825 */ 	or	$a1,$zero,$zero
/*  f185098:	00001825 */ 	or	$v1,$zero,$zero
/*  f18509c:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f1850a0:	240600a0 */ 	addiu	$a2,$zero,0xa0
/*  f1850a4:	28610004 */ 	slti	$at,$v1,0x4
.NB0f1850a8:
/*  f1850a8:	10200006 */ 	beqz	$at,.NB0f1850c4
/*  f1850ac:	00036880 */ 	sll	$t5,$v1,0x2
/*  f1850b0:	00660019 */ 	multu	$v1,$a2
/*  f1850b4:	0000c012 */ 	mflo	$t8
/*  f1850b8:	03d81021 */ 	addu	$v0,$s8,$t8
/*  f1850bc:	1000000a */ 	beqz	$zero,.NB0f1850e8
/*  f1850c0:	8c4e0020 */ 	lw	$t6,0x20($v0)
.NB0f1850c4:
/*  f1850c4:	01a36821 */ 	addu	$t5,$t5,$v1
/*  f1850c8:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f1850cc:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f1850d0:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f1850d4:	3c19800b */ 	lui	$t9,0x800b
/*  f1850d8:	27390de8 */ 	addiu	$t9,$t9,0xde8
/*  f1850dc:	25affed0 */ 	addiu	$t7,$t5,-304
/*  f1850e0:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f1850e4:	8c4e0020 */ 	lw	$t6,0x20($v0)
.NB0f1850e8:
/*  f1850e8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1850ec:	148e000c */ 	bne	$a0,$t6,.NB0f185120
/*  f1850f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1850f4:	1202000a */ 	beq	$s0,$v0,.NB0f185120
/*  f1850f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1850fc:	8e38000c */ 	lw	$t8,0xc($s1)
/*  f185100:	330d0002 */ 	andi	$t5,$t8,0x2
/*  f185104:	51a00006 */ 	beqzl	$t5,.NB0f185120
/*  f185108:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f18510c:	920f0011 */ 	lbu	$t7,0x11($s0)
/*  f185110:	90590011 */ 	lbu	$t9,0x11($v0)
/*  f185114:	11f90002 */ 	beq	$t7,$t9,.NB0f185120
/*  f185118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18511c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f185120:
/*  f185120:	5477ffe1 */ 	bnel	$v1,$s7,.NB0f1850a8
/*  f185124:	28610004 */ 	slti	$at,$v1,0x4
/*  f185128:	54a00005 */ 	bnezl	$a1,.NB0f185140
/*  f18512c:	8fad020c */ 	lw	$t5,0x20c($sp)
/*  f185130:	8e0e0064 */ 	lw	$t6,0x64($s0)
/*  f185134:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f185138:	ae180064 */ 	sw	$t8,0x64($s0)
.NB0f18513c:
/*  f18513c:	8fad020c */ 	lw	$t5,0x20c($sp)
.NB0f185140:
/*  f185140:	2673003c */ 	addiu	$s3,$s3,0x3c
/*  f185144:	26b50002 */ 	addiu	$s5,$s5,0x2
/*  f185148:	16cdfe37 */ 	bne	$s6,$t5,.NB0f184a28
/*  f18514c:	26940080 */ 	addiu	$s4,$s4,0x80
.NB0f185150:
/*  f185150:	3c1e800b */ 	lui	$s8,0x800b
/*  f185154:	27de1068 */ 	addiu	$s8,$s8,0x1068
/*  f185158:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f18515c:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f185160:	8fa40200 */ 	lw	$a0,0x200($sp)
/*  f185164:	8faf01d0 */ 	lw	$t7,0x1d0($sp)
/*  f185168:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f18516c:	8fa5011c */ 	lw	$a1,0x11c($sp)
/*  f185170:	8fa60158 */ 	lw	$a2,0x158($sp)
/*  f185174:	8fa70194 */ 	lw	$a3,0x194($sp)
/*  f185178:	0fc6102a */ 	jal	func0f189cc0
/*  f18517c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f185180:	0002c900 */ 	sll	$t9,$v0,0x4
/*  f185184:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f185188:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18518c:	27ae010c */ 	addiu	$t6,$sp,0x10c
/*  f185190:	032e8021 */ 	addu	$s0,$t9,$t6
/*  f185194:	8e180010 */ 	lw	$t8,0x10($s0)
/*  f185198:	5b000005 */ 	blezl	$t8,.NB0f1851b0
/*  f18519c:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f1851a0:	8e0d002c */ 	lw	$t5,0x2c($s0)
/*  f1851a4:	35af0001 */ 	ori	$t7,$t5,0x1
/*  f1851a8:	ae0f002c */ 	sw	$t7,0x2c($s0)
/*  f1851ac:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
.NB0f1851b0:
/*  f1851b0:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f1851b4:	8fa5010c */ 	lw	$a1,0x10c($sp)
/*  f1851b8:	8fa60148 */ 	lw	$a2,0x148($sp)
/*  f1851bc:	8fa70184 */ 	lw	$a3,0x184($sp)
/*  f1851c0:	0fc6106c */ 	jal	func0f189dc8
/*  f1851c4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1851c8:	00027100 */ 	sll	$t6,$v0,0x4
/*  f1851cc:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f1851d0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1851d4:	27b8010c */ 	addiu	$t8,$sp,0x10c
/*  f1851d8:	01d88021 */ 	addu	$s0,$t6,$t8
/*  f1851dc:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f1851e0:	29a10064 */ 	slti	$at,$t5,0x64
/*  f1851e4:	50200005 */ 	beqzl	$at,.NB0f1851fc
/*  f1851e8:	c7a401e8 */ 	lwc1	$f4,0x1e8($sp)
/*  f1851ec:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*  f1851f0:	35f90002 */ 	ori	$t9,$t7,0x2
/*  f1851f4:	ae19002c */ 	sw	$t9,0x2c($s0)
/*  f1851f8:	c7a401e8 */ 	lwc1	$f4,0x1e8($sp)
.NB0f1851fc:
/*  f1851fc:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f185200:	8fa50134 */ 	lw	$a1,0x134($sp)
/*  f185204:	8fa60170 */ 	lw	$a2,0x170($sp)
/*  f185208:	8fa701ac */ 	lw	$a3,0x1ac($sp)
/*  f18520c:	0fc61106 */ 	jal	func0f18a030
/*  f185210:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f185214:	00027100 */ 	sll	$t6,$v0,0x4
/*  f185218:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f18521c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f185220:	27b8010c */ 	addiu	$t8,$sp,0x10c
/*  f185224:	01d88021 */ 	addu	$s0,$t6,$t8
/*  f185228:	3c014000 */ 	lui	$at,0x4000
/*  f18522c:	44814000 */ 	mtc1	$at,$f8
/*  f185230:	c60a0028 */ 	lwc1	$f10,0x28($s0)
/*  f185234:	4608503e */ 	c.le.s	$f10,$f8
/*  f185238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18523c:	45020005 */ 	bc1fl	.NB0f185254
/*  f185240:	c7b001e8 */ 	lwc1	$f16,0x1e8($sp)
/*  f185244:	8e0d002c */ 	lw	$t5,0x2c($s0)
/*  f185248:	35af0004 */ 	ori	$t7,$t5,0x4
/*  f18524c:	ae0f002c */ 	sw	$t7,0x2c($s0)
/*  f185250:	c7b001e8 */ 	lwc1	$f16,0x1e8($sp)
.NB0f185254:
/*  f185254:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f185258:	8fa50134 */ 	lw	$a1,0x134($sp)
/*  f18525c:	8fa60170 */ 	lw	$a2,0x170($sp)
/*  f185260:	8fa701ac */ 	lw	$a3,0x1ac($sp)
/*  f185264:	0fc610ae */ 	jal	func0f189ed0
/*  f185268:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f18526c:	0002c900 */ 	sll	$t9,$v0,0x4
/*  f185270:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f185274:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f185278:	27ae010c */ 	addiu	$t6,$sp,0x10c
/*  f18527c:	032e8021 */ 	addu	$s0,$t9,$t6
/*  f185280:	3c0140c0 */ 	lui	$at,0x40c0
/*  f185284:	44819000 */ 	mtc1	$at,$f18
/*  f185288:	c6060028 */ 	lwc1	$f6,0x28($s0)
/*  f18528c:	4606903c */ 	c.lt.s	$f18,$f6
/*  f185290:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185294:	45020005 */ 	bc1fl	.NB0f1852ac
/*  f185298:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f18529c:	8e18002c */ 	lw	$t8,0x2c($s0)
/*  f1852a0:	370d0008 */ 	ori	$t5,$t8,0x8
/*  f1852a4:	ae0d002c */ 	sw	$t5,0x2c($s0)
/*  f1852a8:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
.NB0f1852ac:
/*  f1852ac:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f1852b0:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f1852b4:	8fa6014c */ 	lw	$a2,0x14c($sp)
/*  f1852b8:	8fa70188 */ 	lw	$a3,0x188($sp)
/*  f1852bc:	0fc6102a */ 	jal	func0f189cc0
/*  f1852c0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1852c4:	0002c900 */ 	sll	$t9,$v0,0x4
/*  f1852c8:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f1852cc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1852d0:	27ae010c */ 	addiu	$t6,$sp,0x10c
/*  f1852d4:	032e8021 */ 	addu	$s0,$t9,$t6
/*  f1852d8:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f1852dc:	5b000005 */ 	blezl	$t8,.NB0f1852f4
/*  f1852e0:	c7a401d4 */ 	lwc1	$f4,0x1d4($sp)
/*  f1852e4:	8e0d002c */ 	lw	$t5,0x2c($s0)
/*  f1852e8:	35af0010 */ 	ori	$t7,$t5,0x10
/*  f1852ec:	ae0f002c */ 	sw	$t7,0x2c($s0)
/*  f1852f0:	c7a401d4 */ 	lwc1	$f4,0x1d4($sp)
.NB0f1852f4:
/*  f1852f4:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f1852f8:	8fa50120 */ 	lw	$a1,0x120($sp)
/*  f1852fc:	8fa6015c */ 	lw	$a2,0x15c($sp)
/*  f185300:	8fa70198 */ 	lw	$a3,0x198($sp)
/*  f185304:	0fc610ae */ 	jal	func0f189ed0
/*  f185308:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f18530c:	0002c900 */ 	sll	$t9,$v0,0x4
/*  f185310:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f185314:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f185318:	27ae010c */ 	addiu	$t6,$sp,0x10c
/*  f18531c:	032e8021 */ 	addu	$s0,$t9,$t6
/*  f185320:	c60a0014 */ 	lwc1	$f10,0x14($s0)
/*  f185324:	44804000 */ 	mtc1	$zero,$f8
/*  f185328:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18532c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f185330:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185334:	45020005 */ 	bc1fl	.NB0f18534c
/*  f185338:	c7b001d8 */ 	lwc1	$f16,0x1d8($sp)
/*  f18533c:	8e18002c */ 	lw	$t8,0x2c($s0)
/*  f185340:	370d0020 */ 	ori	$t5,$t8,0x20
/*  f185344:	ae0d002c */ 	sw	$t5,0x2c($s0)
/*  f185348:	c7b001d8 */ 	lwc1	$f16,0x1d8($sp)
.NB0f18534c:
/*  f18534c:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f185350:	8fa50124 */ 	lw	$a1,0x124($sp)
/*  f185354:	8fa60160 */ 	lw	$a2,0x160($sp)
/*  f185358:	8fa7019c */ 	lw	$a3,0x19c($sp)
/*  f18535c:	0fc610ae */ 	jal	func0f189ed0
/*  f185360:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f185364:	00027900 */ 	sll	$t7,$v0,0x4
/*  f185368:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f18536c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f185370:	27b9010c */ 	addiu	$t9,$sp,0x10c
/*  f185374:	01f98021 */ 	addu	$s0,$t7,$t9
/*  f185378:	c6060018 */ 	lwc1	$f6,0x18($s0)
/*  f18537c:	44809000 */ 	mtc1	$zero,$f18
/*  f185380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185384:	4606903c */ 	c.lt.s	$f18,$f6
/*  f185388:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18538c:	45020005 */ 	bc1fl	.NB0f1853a4
/*  f185390:	c7a401d8 */ 	lwc1	$f4,0x1d8($sp)
/*  f185394:	8e0e002c */ 	lw	$t6,0x2c($s0)
/*  f185398:	35d80040 */ 	ori	$t8,$t6,0x40
/*  f18539c:	ae18002c */ 	sw	$t8,0x2c($s0)
/*  f1853a0:	c7a401d8 */ 	lwc1	$f4,0x1d8($sp)
.NB0f1853a4:
/*  f1853a4:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f1853a8:	8fa50124 */ 	lw	$a1,0x124($sp)
/*  f1853ac:	8fa60160 */ 	lw	$a2,0x160($sp)
/*  f1853b0:	8fa7019c */ 	lw	$a3,0x19c($sp)
/*  f1853b4:	0fc61106 */ 	jal	func0f18a030
/*  f1853b8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f1853bc:	3c0d800a */ 	lui	$t5,0x800a
/*  f1853c0:	8dade72c */ 	lw	$t5,-0x18d4($t5)
/*  f1853c4:	3c19800a */ 	lui	$t9,0x800a
/*  f1853c8:	3c18800a */ 	lui	$t8,0x800a
/*  f1853cc:	11a00003 */ 	beqz	$t5,.NB0f1853dc
/*  f1853d0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1853d4:	10000002 */ 	beqz	$zero,.NB0f1853e0
/*  f1853d8:	afaf006c */ 	sw	$t7,0x6c($sp)
.NB0f1853dc:
/*  f1853dc:	afa0006c */ 	sw	$zero,0x6c($sp)
.NB0f1853e0:
/*  f1853e0:	8f39e728 */ 	lw	$t9,-0x18d8($t9)
/*  f1853e4:	3c0f800a */ 	lui	$t7,0x800a
/*  f1853e8:	13200003 */ 	beqz	$t9,.NB0f1853f8
/*  f1853ec:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1853f0:	10000002 */ 	beqz	$zero,.NB0f1853fc
/*  f1853f4:	afae0070 */ 	sw	$t6,0x70($sp)
.NB0f1853f8:
/*  f1853f8:	afa00070 */ 	sw	$zero,0x70($sp)
.NB0f1853fc:
/*  f1853fc:	8f18e724 */ 	lw	$t8,-0x18dc($t8)
/*  f185400:	13000003 */ 	beqz	$t8,.NB0f185410
/*  f185404:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f185408:	10000002 */ 	beqz	$zero,.NB0f185414
/*  f18540c:	afad0074 */ 	sw	$t5,0x74($sp)
.NB0f185410:
/*  f185410:	afa00074 */ 	sw	$zero,0x74($sp)
.NB0f185414:
/*  f185414:	8defe730 */ 	lw	$t7,-0x18d0($t7)
/*  f185418:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f18541c:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f185420:	51e00004 */ 	beqzl	$t7,.NB0f185434
/*  f185424:	00009025 */ 	or	$s2,$zero,$zero
/*  f185428:	10000002 */ 	beqz	$zero,.NB0f185434
/*  f18542c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f185430:	00009025 */ 	or	$s2,$zero,$zero
.NB0f185434:
/*  f185434:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f185438:	02597021 */ 	addu	$t6,$s2,$t9
/*  f18543c:	01d86821 */ 	addu	$t5,$t6,$t8
/*  f185440:	01afc821 */ 	addu	$t9,$t5,$t7
/*  f185444:	2b210002 */ 	slti	$at,$t9,0x2
/*  f185448:	14200008 */ 	bnez	$at,.NB0f18546c
/*  f18544c:	00027100 */ 	sll	$t6,$v0,0x4
/*  f185450:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f185454:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f185458:	27b8010c */ 	addiu	$t8,$sp,0x10c
/*  f18545c:	01d88021 */ 	addu	$s0,$t6,$t8
/*  f185460:	8e0d002c */ 	lw	$t5,0x2c($s0)
/*  f185464:	35af0080 */ 	ori	$t7,$t5,0x80
/*  f185468:	ae0f002c */ 	sw	$t7,0x2c($s0)
.NB0f18546c:
/*  f18546c:	8fb901e0 */ 	lw	$t9,0x1e0($sp)
/*  f185470:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f185474:	8fa5012c */ 	lw	$a1,0x12c($sp)
/*  f185478:	8fa60168 */ 	lw	$a2,0x168($sp)
/*  f18547c:	8fa701a4 */ 	lw	$a3,0x1a4($sp)
/*  f185480:	0fc6106c */ 	jal	func0f189dc8
/*  f185484:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f185488:	3c0e800a */ 	lui	$t6,0x800a
/*  f18548c:	8dcee72c */ 	lw	$t6,-0x18d4($t6)
/*  f185490:	3c0d800a */ 	lui	$t5,0x800a
/*  f185494:	3c19800a */ 	lui	$t9,0x800a
/*  f185498:	11c00003 */ 	beqz	$t6,.NB0f1854a8
/*  f18549c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1854a0:	10000002 */ 	beqz	$zero,.NB0f1854ac
/*  f1854a4:	afb8006c */ 	sw	$t8,0x6c($sp)
.NB0f1854a8:
/*  f1854a8:	afa0006c */ 	sw	$zero,0x6c($sp)
.NB0f1854ac:
/*  f1854ac:	8dade728 */ 	lw	$t5,-0x18d8($t5)
/*  f1854b0:	3c18800a */ 	lui	$t8,0x800a
/*  f1854b4:	11a00003 */ 	beqz	$t5,.NB0f1854c4
/*  f1854b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1854bc:	10000002 */ 	beqz	$zero,.NB0f1854c8
/*  f1854c0:	afaf0070 */ 	sw	$t7,0x70($sp)
.NB0f1854c4:
/*  f1854c4:	afa00070 */ 	sw	$zero,0x70($sp)
.NB0f1854c8:
/*  f1854c8:	8f39e724 */ 	lw	$t9,-0x18dc($t9)
/*  f1854cc:	13200003 */ 	beqz	$t9,.NB0f1854dc
/*  f1854d0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1854d4:	10000002 */ 	beqz	$zero,.NB0f1854e0
/*  f1854d8:	afae0074 */ 	sw	$t6,0x74($sp)
.NB0f1854dc:
/*  f1854dc:	afa00074 */ 	sw	$zero,0x74($sp)
.NB0f1854e0:
/*  f1854e0:	8f18e730 */ 	lw	$t8,-0x18d0($t8)
/*  f1854e4:	8fad0074 */ 	lw	$t5,0x74($sp)
/*  f1854e8:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f1854ec:	53000004 */ 	beqzl	$t8,.NB0f185500
/*  f1854f0:	00009025 */ 	or	$s2,$zero,$zero
/*  f1854f4:	10000002 */ 	beqz	$zero,.NB0f185500
/*  f1854f8:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f1854fc:	00009025 */ 	or	$s2,$zero,$zero
.NB0f185500:
/*  f185500:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f185504:	024d7821 */ 	addu	$t7,$s2,$t5
/*  f185508:	01f97021 */ 	addu	$t6,$t7,$t9
/*  f18550c:	01d86821 */ 	addu	$t5,$t6,$t8
/*  f185510:	29a10002 */ 	slti	$at,$t5,0x2
/*  f185514:	14200008 */ 	bnez	$at,.NB0f185538
/*  f185518:	00027900 */ 	sll	$t7,$v0,0x4
/*  f18551c:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f185520:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f185524:	27b9010c */ 	addiu	$t9,$sp,0x10c
/*  f185528:	01f98021 */ 	addu	$s0,$t7,$t9
/*  f18552c:	8e0e002c */ 	lw	$t6,0x2c($s0)
/*  f185530:	35d80100 */ 	ori	$t8,$t6,0x100
/*  f185534:	ae18002c */ 	sw	$t8,0x2c($s0)
.NB0f185538:
/*  f185538:	c7a801e4 */ 	lwc1	$f8,0x1e4($sp)
/*  f18553c:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f185540:	8fa50130 */ 	lw	$a1,0x130($sp)
/*  f185544:	8fa6016c */ 	lw	$a2,0x16c($sp)
/*  f185548:	8fa701a8 */ 	lw	$a3,0x1a8($sp)
/*  f18554c:	0fc610ae */ 	jal	func0f189ed0
/*  f185550:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f185554:	00026900 */ 	sll	$t5,$v0,0x4
/*  f185558:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f18555c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f185560:	27af010c */ 	addiu	$t7,$sp,0x10c
/*  f185564:	01af8021 */ 	addu	$s0,$t5,$t7
/*  f185568:	3c014120 */ 	lui	$at,0x4120
/*  f18556c:	44815000 */ 	mtc1	$at,$f10
/*  f185570:	c6100024 */ 	lwc1	$f16,0x24($s0)
/*  f185574:	4610503c */ 	c.lt.s	$f10,$f16
/*  f185578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18557c:	45020005 */ 	bc1fl	.NB0f185594
/*  f185580:	8fb801dc */ 	lw	$t8,0x1dc($sp)
/*  f185584:	8e19002c */ 	lw	$t9,0x2c($s0)
/*  f185588:	372e0200 */ 	ori	$t6,$t9,0x200
/*  f18558c:	ae0e002c */ 	sw	$t6,0x2c($s0)
/*  f185590:	8fb801dc */ 	lw	$t8,0x1dc($sp)
.NB0f185594:
/*  f185594:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f185598:	8fa50128 */ 	lw	$a1,0x128($sp)
/*  f18559c:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f1855a0:	8fa701a0 */ 	lw	$a3,0x1a0($sp)
/*  f1855a4:	0fc6106c */ 	jal	func0f189dc8
/*  f1855a8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1855ac:	00026900 */ 	sll	$t5,$v0,0x4
/*  f1855b0:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f1855b4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f1855b8:	27af010c */ 	addiu	$t7,$sp,0x10c
/*  f1855bc:	01af8021 */ 	addu	$s0,$t5,$t7
/*  f1855c0:	8e19002c */ 	lw	$t9,0x2c($s0)
/*  f1855c4:	372e0400 */ 	ori	$t6,$t9,0x400
/*  f1855c8:	ae0e002c */ 	sw	$t6,0x2c($s0)
/*  f1855cc:	8fb801dc */ 	lw	$t8,0x1dc($sp)
/*  f1855d0:	8fa701a0 */ 	lw	$a3,0x1a0($sp)
/*  f1855d4:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f1855d8:	8fa50128 */ 	lw	$a1,0x128($sp)
/*  f1855dc:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f1855e0:	0fc6102a */ 	jal	func0f189cc0
/*  f1855e4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1855e8:	00026900 */ 	sll	$t5,$v0,0x4
/*  f1855ec:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f1855f0:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f1855f4:	27af010c */ 	addiu	$t7,$sp,0x10c
/*  f1855f8:	01af8021 */ 	addu	$s0,$t5,$t7
/*  f1855fc:	8e19001c */ 	lw	$t9,0x1c($s0)
/*  f185600:	5b200007 */ 	blezl	$t9,.NB0f185620
/*  f185604:	8fad01f0 */ 	lw	$t5,0x1f0($sp)
/*  f185608:	8e03002c */ 	lw	$v1,0x2c($s0)
/*  f18560c:	306e0400 */ 	andi	$t6,$v1,0x400
/*  f185610:	15c00002 */ 	bnez	$t6,.NB0f18561c
/*  f185614:	34780800 */ 	ori	$t8,$v1,0x800
/*  f185618:	ae18002c */ 	sw	$t8,0x2c($s0)
.NB0f18561c:
/*  f18561c:	8fad01f0 */ 	lw	$t5,0x1f0($sp)
.NB0f185620:
/*  f185620:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f185624:	8fa5013c */ 	lw	$a1,0x13c($sp)
/*  f185628:	8fa60178 */ 	lw	$a2,0x178($sp)
/*  f18562c:	8fa701b4 */ 	lw	$a3,0x1b4($sp)
/*  f185630:	0fc6102a */ 	jal	func0f189cc0
/*  f185634:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f185638:	00027900 */ 	sll	$t7,$v0,0x4
/*  f18563c:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f185640:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f185644:	27b9010c */ 	addiu	$t9,$sp,0x10c
/*  f185648:	01f98021 */ 	addu	$s0,$t7,$t9
/*  f18564c:	8e0e0030 */ 	lw	$t6,0x30($s0)
/*  f185650:	59c00005 */ 	blezl	$t6,.NB0f185668
/*  f185654:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f185658:	8e18002c */ 	lw	$t8,0x2c($s0)
/*  f18565c:	370d2000 */ 	ori	$t5,$t8,0x2000
/*  f185660:	ae0d002c */ 	sw	$t5,0x2c($s0)
/*  f185664:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
.NB0f185668:
/*  f185668:	8fa4020c */ 	lw	$a0,0x20c($sp)
/*  f18566c:	8fa50140 */ 	lw	$a1,0x140($sp)
/*  f185670:	8fa6017c */ 	lw	$a2,0x17c($sp)
/*  f185674:	8fa701b8 */ 	lw	$a3,0x1b8($sp)
/*  f185678:	0fc6106c */ 	jal	func0f189dc8
/*  f18567c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f185680:	2409003c */ 	addiu	$t1,$zero,0x3c
/*  f185684:	00490019 */ 	multu	$v0,$t1
/*  f185688:	27a7010c */ 	addiu	$a3,$sp,0x10c
/*  f18568c:	3c14800a */ 	lui	$s4,0x800a
/*  f185690:	2694e6c0 */ 	addiu	$s4,$s4,-6464
/*  f185694:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f185698:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f18569c:	3c040001 */ 	lui	$a0,0x1
/*  f1856a0:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f1856a4:	0000c812 */ 	mflo	$t9
/*  f1856a8:	00f98021 */ 	addu	$s0,$a3,$t9
/*  f1856ac:	8e0e0034 */ 	lw	$t6,0x34($s0)
/*  f1856b0:	59c00008 */ 	blezl	$t6,.NB0f1856d4
/*  f1856b4:	8fa8020c */ 	lw	$t0,0x20c($sp)
/*  f1856b8:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f1856bc:	5b000005 */ 	blezl	$t8,.NB0f1856d4
/*  f1856c0:	8fa8020c */ 	lw	$t0,0x20c($sp)
/*  f1856c4:	8e0d002c */ 	lw	$t5,0x2c($s0)
/*  f1856c8:	35af1000 */ 	ori	$t7,$t5,0x1000
/*  f1856cc:	ae0f002c */ 	sw	$t7,0x2c($s0)
/*  f1856d0:	8fa8020c */ 	lw	$t0,0x20c($sp)
.NB0f1856d4:
/*  f1856d4:	0000b025 */ 	or	$s6,$zero,$zero
/*  f1856d8:	19000020 */ 	blez	$t0,.NB0f18575c
/*  f1856dc:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1856e0:
/*  f1856e0:	8e8200cc */ 	lw	$v0,0xcc($s4)
/*  f1856e4:	14620008 */ 	bne	$v1,$v0,.NB0f185708
/*  f1856e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1856ec:	02c90019 */ 	multu	$s6,$t1
/*  f1856f0:	0000c812 */ 	mflo	$t9
/*  f1856f4:	00f99821 */ 	addu	$s3,$a3,$t9
/*  f1856f8:	8e6e002c */ 	lw	$t6,0x2c($s3)
/*  f1856fc:	01c4c025 */ 	or	$t8,$t6,$a0
/*  f185700:	10000012 */ 	beqz	$zero,.NB0f18574c
/*  f185704:	ae78002c */ 	sw	$t8,0x2c($s3)
.NB0f185708:
/*  f185708:	14a20008 */ 	bne	$a1,$v0,.NB0f18572c
/*  f18570c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185710:	02c90019 */ 	multu	$s6,$t1
/*  f185714:	00006812 */ 	mflo	$t5
/*  f185718:	00ed9821 */ 	addu	$s3,$a3,$t5
/*  f18571c:	8e6f002c */ 	lw	$t7,0x2c($s3)
/*  f185720:	35f98000 */ 	ori	$t9,$t7,0x8000
/*  f185724:	10000009 */ 	beqz	$zero,.NB0f18574c
/*  f185728:	ae79002c */ 	sw	$t9,0x2c($s3)
.NB0f18572c:
/*  f18572c:	54c20008 */ 	bnel	$a2,$v0,.NB0f185750
/*  f185730:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f185734:	02c90019 */ 	multu	$s6,$t1
/*  f185738:	00007012 */ 	mflo	$t6
/*  f18573c:	00ee9821 */ 	addu	$s3,$a3,$t6
/*  f185740:	8e78002c */ 	lw	$t8,0x2c($s3)
/*  f185744:	370d4000 */ 	ori	$t5,$t8,0x4000
/*  f185748:	ae6d002c */ 	sw	$t5,0x2c($s3)
.NB0f18574c:
/*  f18574c:	26d60001 */ 	addiu	$s6,$s6,0x1
.NB0f185750:
/*  f185750:	16c8ffe3 */ 	bne	$s6,$t0,.NB0f1856e0
/*  f185754:	26940080 */ 	addiu	$s4,$s4,0x80
/*  f185758:	0000b025 */ 	or	$s6,$zero,$zero
.NB0f18575c:
/*  f18575c:	1900000a */ 	blez	$t0,.NB0f185788
/*  f185760:	27b3010c */ 	addiu	$s3,$sp,0x10c
/*  f185764:	24020011 */ 	addiu	$v0,$zero,0x11
.NB0f185768:
/*  f185768:	00001825 */ 	or	$v1,$zero,$zero
/*  f18576c:	24630001 */ 	addiu	$v1,$v1,0x1
.NB0f185770:
/*  f185770:	5462ffff */ 	bnel	$v1,$v0,.NB0f185770
/*  f185774:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f185778:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18577c:	16c8fffa */ 	bne	$s6,$t0,.NB0f185768
/*  f185780:	2673003c */ 	addiu	$s3,$s3,0x3c
/*  f185784:	0000b025 */ 	or	$s6,$zero,$zero
.NB0f185788:
/*  f185788:	19000066 */ 	blez	$t0,.NB0f185924
/*  f18578c:	3c148009 */ 	lui	$s4,0x8009
/*  f185790:	26949c4c */ 	addiu	$s4,$s4,-25524
/*  f185794:	24150011 */ 	addiu	$s5,$zero,0x11
/*  f185798:	8faf020c */ 	lw	$t7,0x20c($sp)
.NB0f18579c:
/*  f18579c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1857a0:	00009025 */ 	or	$s2,$zero,$zero
/*  f1857a4:	15e1000b */ 	bne	$t7,$at,.NB0f1857d4
/*  f1857a8:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f1857ac:	0016c900 */ 	sll	$t9,$s6,0x4
/*  f1857b0:	0336c823 */ 	subu	$t9,$t9,$s6
/*  f1857b4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1857b8:	27ae010c */ 	addiu	$t6,$sp,0x10c
/*  f1857bc:	032e9821 */ 	addu	$s3,$t9,$t6
/*  f1857c0:	8e78002c */ 	lw	$t8,0x2c($s3)
/*  f1857c4:	3c010001 */ 	lui	$at,0x1
/*  f1857c8:	3421c670 */ 	ori	$at,$at,0xc670
/*  f1857cc:	03016824 */ 	and	$t5,$t8,$at
/*  f1857d0:	ae6d002c */ 	sw	$t5,0x2c($s3)
.NB0f1857d4:
/*  f1857d4:	00167900 */ 	sll	$t7,$s6,0x4
/*  f1857d8:	01f67823 */ 	subu	$t7,$t7,$s6
/*  f1857dc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1857e0:	27b9010c */ 	addiu	$t9,$sp,0x10c
/*  f1857e4:	01f99821 */ 	addu	$s3,$t7,$t9
/*  f1857e8:	8e70002c */ 	lw	$s0,0x2c($s3)
.NB0f1857ec:
/*  f1857ec:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1857f0:	00ae1004 */ 	sllv	$v0,$t6,$a1
/*  f1857f4:	0202c024 */ 	and	$t8,$s0,$v0
/*  f1857f8:	1300000f */ 	beqz	$t8,.NB0f185838
/*  f1857fc:	00406827 */ 	nor	$t5,$v0,$zero
/*  f185800:	020d7824 */ 	and	$t7,$s0,$t5
/*  f185804:	3c0d800a */ 	lui	$t5,0x800a
/*  f185808:	0005c840 */ 	sll	$t9,$a1,0x1
/*  f18580c:	02997021 */ 	addu	$t6,$s4,$t9
/*  f185810:	25ade6c0 */ 	addiu	$t5,$t5,-6464
/*  f185814:	0016c080 */ 	sll	$t8,$s6,0x2
/*  f185818:	ae6f002c */ 	sw	$t7,0x2c($s3)
/*  f18581c:	030d8821 */ 	addu	$s1,$t8,$t5
/*  f185820:	95c40000 */ 	lhu	$a0,0x0($t6)
/*  f185824:	0fc5a4dd */ 	jal	langGet
/*  f185828:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f18582c:	8e2f0064 */ 	lw	$t7,0x64($s1)
/*  f185830:	ade21974 */ 	sw	$v0,0x1974($t7)
/*  f185834:	8e70002c */ 	lw	$s0,0x2c($s3)
.NB0f185838:
/*  f185838:	16000002 */ 	bnez	$s0,.NB0f185844
/*  f18583c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185840:	24120001 */ 	addiu	$s2,$zero,0x1
.NB0f185844:
/*  f185844:	0c004d84 */ 	jal	random
/*  f185848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18584c:	0055001b */ 	divu	$zero,$v0,$s5
/*  f185850:	00002810 */ 	mfhi	$a1
/*  f185854:	16a00002 */ 	bnez	$s5,.NB0f185860
/*  f185858:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18585c:	0007000d */ 	break	0x7
.NB0f185860:
/*  f185860:	5240ffe2 */ 	beqzl	$s2,.NB0f1857ec
/*  f185864:	8e70002c */ 	lw	$s0,0x2c($s3)
/*  f185868:	2a410002 */ 	slti	$at,$s2,0x2
/*  f18586c:	10200029 */ 	beqz	$at,.NB0f185914
/*  f185870:	0016c900 */ 	sll	$t9,$s6,0x4
/*  f185874:	0336c823 */ 	subu	$t9,$t9,$s6
/*  f185878:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f18587c:	27ae010c */ 	addiu	$t6,$sp,0x10c
/*  f185880:	032e9821 */ 	addu	$s3,$t9,$t6
.NB0f185884:
/*  f185884:	0c004d84 */ 	jal	random
/*  f185888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18588c:	0055001b */ 	divu	$zero,$v0,$s5
/*  f185890:	8e70002c */ 	lw	$s0,0x2c($s3)
/*  f185894:	00001810 */ 	mfhi	$v1
/*  f185898:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f18589c:	00786804 */ 	sllv	$t5,$t8,$v1
/*  f1858a0:	16a00002 */ 	bnez	$s5,.NB0f1858ac
/*  f1858a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1858a8:	0007000d */ 	break	0x7
.NB0f1858ac:
/*  f1858ac:	020d7824 */ 	and	$t7,$s0,$t5
/*  f1858b0:	11e00012 */ 	beqz	$t7,.NB0f1858fc
/*  f1858b4:	00602825 */ 	or	$a1,$v1,$zero
/*  f1858b8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1858bc:	00797004 */ 	sllv	$t6,$t9,$v1
/*  f1858c0:	01c0c027 */ 	nor	$t8,$t6,$zero
/*  f1858c4:	02186824 */ 	and	$t5,$s0,$t8
/*  f1858c8:	3c18800a */ 	lui	$t8,0x800a
/*  f1858cc:	00037840 */ 	sll	$t7,$v1,0x1
/*  f1858d0:	028fc821 */ 	addu	$t9,$s4,$t7
/*  f1858d4:	2718e6c0 */ 	addiu	$t8,$t8,-6464
/*  f1858d8:	00167080 */ 	sll	$t6,$s6,0x2
/*  f1858dc:	ae6d002c */ 	sw	$t5,0x2c($s3)
/*  f1858e0:	01d88821 */ 	addu	$s1,$t6,$t8
/*  f1858e4:	97240000 */ 	lhu	$a0,0x0($t9)
/*  f1858e8:	0fc5a4dd */ 	jal	langGet
/*  f1858ec:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f1858f0:	8e2d0064 */ 	lw	$t5,0x64($s1)
/*  f1858f4:	ada21978 */ 	sw	$v0,0x1978($t5)
/*  f1858f8:	8e70002c */ 	lw	$s0,0x2c($s3)
.NB0f1858fc:
/*  f1858fc:	56000003 */ 	bnezl	$s0,.NB0f18590c
/*  f185900:	2a410002 */ 	slti	$at,$s2,0x2
/*  f185904:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f185908:	2a410002 */ 	slti	$at,$s2,0x2
.NB0f18590c:
/*  f18590c:	1420ffdd */ 	bnez	$at,.NB0f185884
/*  f185910:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f185914:
/*  f185914:	8faf020c */ 	lw	$t7,0x20c($sp)
/*  f185918:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f18591c:	56cfff9f */ 	bnel	$s6,$t7,.NB0f18579c
/*  f185920:	8faf020c */ 	lw	$t7,0x20c($sp)
.NB0f185924:
/*  f185924:	8fb900f4 */ 	lw	$t9,0xf4($sp)
/*  f185928:	2b210002 */ 	slti	$at,$t9,0x2
/*  f18592c:	14200072 */ 	bnez	$at,.NB0f185af8
/*  f185930:	3c0700ff */ 	lui	$a3,0xff
/*  f185934:	3c0a800b */ 	lui	$t2,0x800b
/*  f185938:	3c0b800b */ 	lui	$t3,0x800b
/*  f18593c:	00003025 */ 	or	$a2,$zero,$zero
/*  f185940:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f185944:	34e7ffff */ 	ori	$a3,$a3,0xffff
/*  f185948:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f18594c:	256b0de8 */ 	addiu	$t3,$t3,0xde8
/*  f185950:	954a144e */ 	lhu	$t2,0x144e($t2)
/*  f185954:	00002825 */ 	or	$a1,$zero,$zero
/*  f185958:	240c004c */ 	addiu	$t4,$zero,0x4c
/*  f18595c:	240e0001 */ 	addiu	$t6,$zero,0x1
.NB0f185960:
/*  f185960:	00aec004 */ 	sllv	$t8,$t6,$a1
/*  f185964:	01586824 */ 	and	$t5,$t2,$t8
/*  f185968:	11a00024 */ 	beqz	$t5,.NB0f1859fc
/*  f18596c:	28a10004 */ 	slti	$at,$a1,0x4
/*  f185970:	10200006 */ 	beqz	$at,.NB0f18598c
/*  f185974:	00001025 */ 	or	$v0,$zero,$zero
/*  f185978:	00057880 */ 	sll	$t7,$a1,0x2
/*  f18597c:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f185980:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f185984:	10000005 */ 	beqz	$zero,.NB0f18599c
/*  f185988:	03cf2021 */ 	addu	$a0,$s8,$t7
.NB0f18598c:
/*  f18598c:	00ac0019 */ 	multu	$a1,$t4
/*  f185990:	0000c812 */ 	mflo	$t9
/*  f185994:	01792021 */ 	addu	$a0,$t3,$t9
/*  f185998:	2484fed0 */ 	addiu	$a0,$a0,-304
.NB0f18599c:
/*  f18599c:	00001825 */ 	or	$v1,$zero,$zero
.NB0f1859a0:
/*  f1859a0:	12c30004 */ 	beq	$s6,$v1,.NB0f1859b4
/*  f1859a4:	00037040 */ 	sll	$t6,$v1,0x1
/*  f1859a8:	008ec021 */ 	addu	$t8,$a0,$t6
/*  f1859ac:	870d0024 */ 	lh	$t5,0x24($t8)
/*  f1859b0:	004d1021 */ 	addu	$v0,$v0,$t5
.NB0f1859b4:
/*  f1859b4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1859b8:	1477fff9 */ 	bne	$v1,$s7,.NB0f1859a0
/*  f1859bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1859c0:	14460002 */ 	bne	$v0,$a2,.NB0f1859cc
/*  f1859c4:	00c2082a */ 	slt	$at,$a2,$v0
/*  f1859c8:	2408ffff */ 	addiu	$t0,$zero,-1
.NB0f1859cc:
/*  f1859cc:	50200004 */ 	beqzl	$at,.NB0f1859e0
/*  f1859d0:	8482003c */ 	lh	$v0,0x3c($a0)
/*  f1859d4:	00a04025 */ 	or	$t0,$a1,$zero
/*  f1859d8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1859dc:	8482003c */ 	lh	$v0,0x3c($a0)
.NB0f1859e0:
/*  f1859e0:	14e20002 */ 	bne	$a3,$v0,.NB0f1859ec
/*  f1859e4:	0047082a */ 	slt	$at,$v0,$a3
/*  f1859e8:	2409ffff */ 	addiu	$t1,$zero,-1
.NB0f1859ec:
/*  f1859ec:	50200004 */ 	beqzl	$at,.NB0f185a00
/*  f1859f0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1859f4:	00a04825 */ 	or	$t1,$a1,$zero
/*  f1859f8:	00403825 */ 	or	$a3,$v0,$zero
.NB0f1859fc:
/*  f1859fc:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f185a00:
/*  f185a00:	54b7ffd7 */ 	bnel	$a1,$s7,.NB0f185960
/*  f185a04:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f185a08:	3c0f800a */ 	lui	$t7,0x800a
/*  f185a0c:	8def66c0 */ 	lw	$t7,0x66c0($t7)
/*  f185a10:	3c19800a */ 	lui	$t9,0x800a
/*  f185a14:	15e00038 */ 	bnez	$t7,.NB0f185af8
/*  f185a18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185a1c:	8f3966c4 */ 	lw	$t9,0x66c4($t9)
/*  f185a20:	29010004 */ 	slti	$at,$t0,0x4
/*  f185a24:	17200034 */ 	bnez	$t9,.NB0f185af8
/*  f185a28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185a2c:	50200019 */ 	beqzl	$at,.NB0f185a94
/*  f185a30:	29210004 */ 	slti	$at,$t1,0x4
/*  f185a34:	05000016 */ 	bltz	$t0,.NB0f185a90
/*  f185a38:	29010004 */ 	slti	$at,$t0,0x4
/*  f185a3c:	10200006 */ 	beqz	$at,.NB0f185a58
/*  f185a40:	0008c080 */ 	sll	$t8,$t0,0x2
/*  f185a44:	00087080 */ 	sll	$t6,$t0,0x2
/*  f185a48:	01c87021 */ 	addu	$t6,$t6,$t0
/*  f185a4c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f185a50:	10000009 */ 	beqz	$zero,.NB0f185a78
/*  f185a54:	03ce1021 */ 	addu	$v0,$s8,$t6
.NB0f185a58:
/*  f185a58:	0308c021 */ 	addu	$t8,$t8,$t0
/*  f185a5c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f185a60:	0308c023 */ 	subu	$t8,$t8,$t0
/*  f185a64:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f185a68:	3c0f800b */ 	lui	$t7,0x800b
/*  f185a6c:	25ef0de8 */ 	addiu	$t7,$t7,0xde8
/*  f185a70:	270dfed0 */ 	addiu	$t5,$t8,-304
/*  f185a74:	01af1021 */ 	addu	$v0,$t5,$t7
.NB0f185a78:
/*  f185a78:	90590094 */ 	lbu	$t9,0x94($v0)
/*  f185a7c:	8c58008c */ 	lw	$t8,0x8c($v0)
/*  f185a80:	372e0001 */ 	ori	$t6,$t9,0x1
/*  f185a84:	270d0001 */ 	addiu	$t5,$t8,0x1
/*  f185a88:	a04e0094 */ 	sb	$t6,0x94($v0)
/*  f185a8c:	ac4d008c */ 	sw	$t5,0x8c($v0)
.NB0f185a90:
/*  f185a90:	29210004 */ 	slti	$at,$t1,0x4
.NB0f185a94:
/*  f185a94:	10200018 */ 	beqz	$at,.NB0f185af8
/*  f185a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185a9c:	05200016 */ 	bltz	$t1,.NB0f185af8
/*  f185aa0:	29210004 */ 	slti	$at,$t1,0x4
/*  f185aa4:	10200006 */ 	beqz	$at,.NB0f185ac0
/*  f185aa8:	0009c880 */ 	sll	$t9,$t1,0x2
/*  f185aac:	00097880 */ 	sll	$t7,$t1,0x2
/*  f185ab0:	01e97821 */ 	addu	$t7,$t7,$t1
/*  f185ab4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f185ab8:	10000009 */ 	beqz	$zero,.NB0f185ae0
/*  f185abc:	03cf1021 */ 	addu	$v0,$s8,$t7
.NB0f185ac0:
/*  f185ac0:	0329c821 */ 	addu	$t9,$t9,$t1
/*  f185ac4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f185ac8:	0329c823 */ 	subu	$t9,$t9,$t1
/*  f185acc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f185ad0:	3c18800b */ 	lui	$t8,0x800b
/*  f185ad4:	27180de8 */ 	addiu	$t8,$t8,0xde8
/*  f185ad8:	272efed0 */ 	addiu	$t6,$t9,-304
/*  f185adc:	01d81021 */ 	addu	$v0,$t6,$t8
.NB0f185ae0:
/*  f185ae0:	904d0094 */ 	lbu	$t5,0x94($v0)
/*  f185ae4:	8c590090 */ 	lw	$t9,0x90($v0)
/*  f185ae8:	35af0008 */ 	ori	$t7,$t5,0x8
/*  f185aec:	272e0001 */ 	addiu	$t6,$t9,0x1
/*  f185af0:	a04f0094 */ 	sb	$t7,0x94($v0)
/*  f185af4:	ac4e0090 */ 	sw	$t6,0x90($v0)
.NB0f185af8:
/*  f185af8:	3c0d800a */ 	lui	$t5,0x800a
/*  f185afc:	8dad66c0 */ 	lw	$t5,0x66c0($t5)
/*  f185b00:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f185b04:	0000b025 */ 	or	$s6,$zero,$zero
/*  f185b08:	15a00035 */ 	bnez	$t5,.NB0f185be0
/*  f185b0c:	3c0f800a */ 	lui	$t7,0x800a
/*  f185b10:	8def66c4 */ 	lw	$t7,0x66c4($t7)
/*  f185b14:	2b010002 */ 	slti	$at,$t8,0x2
/*  f185b18:	55e00032 */ 	bnezl	$t7,.NB0f185be4
/*  f185b1c:	8fa8020c */ 	lw	$t0,0x20c($sp)
/*  f185b20:	1420002f */ 	bnez	$at,.NB0f185be0
/*  f185b24:	00001825 */ 	or	$v1,$zero,$zero
/*  f185b28:	3c013f00 */ 	lui	$at,0x3f00
/*  f185b2c:	44811000 */ 	mtc1	$at,$f2
/*  f185b30:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f185b34:	1b000016 */ 	blez	$t8,.NB0f185b90
/*  f185b38:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f185b3c:	27b3010c */ 	addiu	$s3,$sp,0x10c
.NB0f185b40:
/*  f185b40:	8e620004 */ 	lw	$v0,0x4($s3)
/*  f185b44:	8fb9020c */ 	lw	$t9,0x20c($sp)
/*  f185b48:	14620002 */ 	bne	$v1,$v0,.NB0f185b54
/*  f185b4c:	0062082a */ 	slt	$at,$v1,$v0
/*  f185b50:	2404ffff */ 	addiu	$a0,$zero,-1
.NB0f185b54:
/*  f185b54:	50200004 */ 	beqzl	$at,.NB0f185b68
/*  f185b58:	c6600038 */ 	lwc1	$f0,0x38($s3)
/*  f185b5c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f185b60:	00401825 */ 	or	$v1,$v0,$zero
/*  f185b64:	c6600038 */ 	lwc1	$f0,0x38($s3)
.NB0f185b68:
/*  f185b68:	4600103c */ 	c.lt.s	$f2,$f0
/*  f185b6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185b70:	45020004 */ 	bc1fl	.NB0f185b84
/*  f185b74:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f185b78:	02c08025 */ 	or	$s0,$s6,$zero
/*  f185b7c:	46000086 */ 	mov.s	$f2,$f0
/*  f185b80:	26d60001 */ 	addiu	$s6,$s6,0x1
.NB0f185b84:
/*  f185b84:	16d9ffee */ 	bne	$s6,$t9,.NB0f185b40
/*  f185b88:	2673003c */ 	addiu	$s3,$s3,0x3c
/*  f185b8c:	0000b025 */ 	or	$s6,$zero,$zero
.NB0f185b90:
/*  f185b90:	04800009 */ 	bltz	$a0,.NB0f185bb8
/*  f185b94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185b98:	0fc61a7b */ 	jal	func0f18c794
/*  f185b9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185ba0:	904e0094 */ 	lbu	$t6,0x94($v0)
/*  f185ba4:	8c4f0088 */ 	lw	$t7,0x88($v0)
/*  f185ba8:	35cd0002 */ 	ori	$t5,$t6,0x2
/*  f185bac:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f185bb0:	a04d0094 */ 	sb	$t5,0x94($v0)
/*  f185bb4:	ac580088 */ 	sw	$t8,0x88($v0)
.NB0f185bb8:
/*  f185bb8:	0602000a */ 	bltzl	$s0,.NB0f185be4
/*  f185bbc:	8fa8020c */ 	lw	$t0,0x20c($sp)
/*  f185bc0:	0fc61a7b */ 	jal	func0f18c794
/*  f185bc4:	02002025 */ 	or	$a0,$s0,$zero
/*  f185bc8:	90590094 */ 	lbu	$t9,0x94($v0)
/*  f185bcc:	8c4d0084 */ 	lw	$t5,0x84($v0)
/*  f185bd0:	372e0004 */ 	ori	$t6,$t9,0x4
/*  f185bd4:	25af0001 */ 	addiu	$t7,$t5,0x1
/*  f185bd8:	a04e0094 */ 	sb	$t6,0x94($v0)
/*  f185bdc:	ac4f0084 */ 	sw	$t7,0x84($v0)
.NB0f185be0:
/*  f185be0:	8fa8020c */ 	lw	$t0,0x20c($sp)
.NB0f185be4:
/*  f185be4:	5900000a */ 	blezl	$t0,.NB0f185c10
/*  f185be8:	8fbf0044 */ 	lw	$ra,0x44($sp)
.NB0f185bec:
/*  f185bec:	0fc61a7b */ 	jal	func0f18c794
/*  f185bf0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f185bf4:	0fc6115e */ 	jal	mpCalculatePlayerTitle
/*  f185bf8:	00402025 */ 	or	$a0,$v0,$zero
/*  f185bfc:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f185c00:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f185c04:	16d8fff9 */ 	bne	$s6,$t8,.NB0f185bec
/*  f185c08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f185c0c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.NB0f185c10:
/*  f185c10:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f185c14:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f185c18:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f185c1c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f185c20:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f185c24:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f185c28:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f185c2c:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f185c30:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f185c34:	03e00008 */ 	jr	$ra
/*  f185c38:	27bd0210 */ 	addiu	$sp,$sp,0x210
);
#endif

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
	/*0x00*/ { MUSIC_DARK_COMBAT,     160, L_MISC_124, -1 }, // "Dark Combat"
	/*0x01*/ { MUSIC_SKEDAR_MYSTERY,  170, L_MISC_125, -1 }, // "Skedar Mystery"
	/*0x02*/ { MUSIC_CI_OPERATIVE,    170, L_MISC_126, -1 }, // "CI Operative"
	/*0x03*/ { MUSIC_DATADYNE_ACTION, 180, L_MISC_127, -1 }, // "dataDyne Action"
	/*0x04*/ { MUSIC_MAIAN_TEARS,     200, L_MISC_128, -1 }, // "Maian Tears"
	/*0x05*/ { MUSIC_ALIEN_CONFLICT,  197, L_MISC_129, -1 }, // "Alien Conflict"
	/*0x06*/ { MUSIC_CI,              120, L_MISC_130, -1 }, // "Carrington Institute"
	/*0x07*/ { MUSIC_DEFECTION,       120, L_MISC_131, SOLOSTAGEINDEX_DEFECTION }, // "dD Central"
	/*0x08*/ { MUSIC_DEFECTION_X,     120, L_MISC_132, SOLOSTAGEINDEX_DEFECTION }, // "dD Central X"
	/*0x09*/ { MUSIC_INVESTIGATION,   120, L_MISC_133, SOLOSTAGEINDEX_INVESTIGATION }, // "dD Research"
	/*0x0a*/ { MUSIC_INVESTIGATION_X, 120, L_MISC_134, SOLOSTAGEINDEX_INVESTIGATION }, // "dD Research X"
	/*0x0b*/ { MUSIC_EXTRACTION,      120, L_MISC_135, SOLOSTAGEINDEX_EXTRACTION }, // "dD Extraction"
	/*0x0c*/ { MUSIC_EXTRACTION_X,    120, L_MISC_136, SOLOSTAGEINDEX_EXTRACTION }, // "dD Extraction X"
	/*0x0d*/ { MUSIC_VILLA,           120, L_MISC_137, SOLOSTAGEINDEX_VILLA }, // "Carrington Villa"
	/*0x0e*/ { MUSIC_VILLA_X,         120, L_MISC_138, SOLOSTAGEINDEX_VILLA }, // "Carrington Villa X"
	/*0x0f*/ { MUSIC_CHICAGO,         120, L_MISC_139, SOLOSTAGEINDEX_CHICAGO }, // "Chicago"
	/*0x10*/ { MUSIC_CHICAGO_X,       120, L_MISC_140, SOLOSTAGEINDEX_CHICAGO }, // "Chicago X"
	/*0x11*/ { MUSIC_G5,              120, L_MISC_141, SOLOSTAGEINDEX_G5BUILDING }, // "G5 Building"
	/*0x12*/ { MUSIC_G5_X,            120, L_MISC_142, SOLOSTAGEINDEX_G5BUILDING }, // "G5 Building X"
	/*0x13*/ { MUSIC_INFILTRATION,    120, L_MISC_143, SOLOSTAGEINDEX_INFILTRATION }, // "A51 Infiltration"
	/*0x14*/ { MUSIC_INFILTRATION_X,  120, L_MISC_144, SOLOSTAGEINDEX_INFILTRATION }, // "A51 Infiltration X"
	/*0x15*/ { MUSIC_RESCUE,          120, L_MISC_145, SOLOSTAGEINDEX_RESCUE }, // "A51 Rescue"
	/*0x16*/ { MUSIC_RESCUE_X,        120, L_MISC_146, SOLOSTAGEINDEX_RESCUE }, // "A51 Rescue X"
	/*0x17*/ { MUSIC_ESCAPE,          120, L_MISC_147, SOLOSTAGEINDEX_ESCAPE }, // "A51 Escape"
	/*0x18*/ { MUSIC_ESCAPE_X,        120, L_MISC_148, SOLOSTAGEINDEX_ESCAPE }, // "A51 Escape X"
	/*0x19*/ { MUSIC_AIRBASE,         120, L_MISC_149, SOLOSTAGEINDEX_AIRBASE }, // "Air Base"
	/*0x1a*/ { MUSIC_AIRBASE_X,       120, L_MISC_150, SOLOSTAGEINDEX_AIRBASE }, // "Air Base X"
	/*0x1b*/ { MUSIC_AIRFORCEONE,     120, L_MISC_151, SOLOSTAGEINDEX_AIRFORCEONE }, // "Air Force One"
	/*0x1c*/ { MUSIC_AIRFORCEONE_X,   120, L_MISC_152, SOLOSTAGEINDEX_AIRFORCEONE }, // "Air Force One X"
	/*0x1d*/ { MUSIC_CRASHSITE,       120, L_MISC_153, SOLOSTAGEINDEX_CRASHSITE }, // "Crash Site"
	/*0x1e*/ { MUSIC_CRASHSITE_X,     120, L_MISC_154, SOLOSTAGEINDEX_CRASHSITE }, // "Crash Site X"
	/*0x1f*/ { MUSIC_PELAGIC,         120, L_MISC_155, SOLOSTAGEINDEX_PELAGIC }, // "Pelagic II"
	/*0x20*/ { MUSIC_PELAGIC_X,       120, L_MISC_156, SOLOSTAGEINDEX_PELAGIC }, // "Pelagic II X"
	/*0x21*/ { MUSIC_DEEPSEA,         120, L_MISC_157, SOLOSTAGEINDEX_DEEPSEA }, // "Deep Sea"
	/*0x22*/ { MUSIC_DEEPSEA_X,       120, L_MISC_158, SOLOSTAGEINDEX_DEEPSEA }, // "Deep Sea X"
	/*0x23*/ { MUSIC_DEFENSE,         120, L_MISC_159, SOLOSTAGEINDEX_DEFENSE }, // "Institute Defense"
	/*0x24*/ { MUSIC_DEFENSE_X,       120, L_MISC_160, SOLOSTAGEINDEX_DEFENSE }, // "Institute Defense X"
	/*0x25*/ { MUSIC_ATTACKSHIP,      120, L_MISC_161, SOLOSTAGEINDEX_ATTACKSHIP }, // "Attack Ship"
	/*0x26*/ { MUSIC_ATTACKSHIP_X,    120, L_MISC_162, SOLOSTAGEINDEX_ATTACKSHIP }, // "Attack Ship X"
	/*0x27*/ { MUSIC_SKEDARRUINS,     120, L_MISC_163, SOLOSTAGEINDEX_SKEDARRUINS }, // "Skedar Ruins"
	/*0x28*/ { MUSIC_SKEDARRUINS_X,   120, L_MISC_164, SOLOSTAGEINDEX_SKEDARRUINS }, // "Skedar Ruins X"
	/*0x29*/ { MUSIC_CREDITS,         120, L_MISC_165, SOLOSTAGEINDEX_SKEDARRUINS }, // "End Credits"
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
/*  f18d584:	0fc634d2 */ 	jal	mpGetUsingMultipleTunes
/*  f18d588:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18d58c:	1040006f */ 	beqz	$v0,.PF0f18d74c
/*  f18d590:	00000000 */ 	nop
/*  f18d594:	0fc634a9 */ 	jal	mpGetNumUnlockedTracks
/*  f18d598:	00000000 */ 	nop
/*  f18d59c:	0040a025 */ 	move	$s4,$v0
/*  f18d5a0:	0000a825 */ 	move	$s5,$zero
/*  f18d5a4:	18400009 */ 	blez	$v0,.PF0f18d5cc
/*  f18d5a8:	00008025 */ 	move	$s0,$zero
.PF0f18d5ac:
/*  f18d5ac:	0fc634d5 */ 	jal	mpIsMultiTrackSlotEnabled
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
/*  f18d5d8:	0c004ad4 */ 	jal	random
/*  f18d5dc:	00000000 */ 	nop
/*  f18d5e0:	0054001b */ 	divu	$zero,$v0,$s4
/*  f18d5e4:	00002010 */ 	mfhi	$a0
/*  f18d5e8:	16800002 */ 	bnez	$s4,.PF0f18d5f4
/*  f18d5ec:	00000000 */ 	nop
/*  f18d5f0:	0007000d */ 	break	0x7
.PF0f18d5f4:
/*  f18d5f4:	0fc6348e */ 	jal	mpGetTrackNumAtSlotIndex
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
/*  f18d65c:	0c004ad4 */ 	jal	random
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
/*  f18d684:	0fc634d5 */ 	jal	mpIsMultiTrackSlotEnabled
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
/*  f18d6e8:	0fc6348e */ 	jal	mpGetTrackNumAtSlotIndex
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
/*  f18d74c:	0fc6354b */ 	jal	mpGetCurrentTrackSlotNum
/*  f18d750:	00000000 */ 	nop
/*  f18d754:	04410024 */ 	bgez	$v0,.PF0f18d7e8
/*  f18d758:	00409825 */ 	move	$s3,$v0
/*  f18d75c:	0fc634a9 */ 	jal	mpGetNumUnlockedTracks
/*  f18d760:	00000000 */ 	nop
/*  f18d764:	3c16800b */ 	lui	$s6,0x800b
/*  f18d768:	00408025 */ 	move	$s0,$v0
/*  f18d76c:	26d6d1c0 */ 	addiu	$s6,$s6,-11840
.PF0f18d770:
/*  f18d770:	0c004ad4 */ 	jal	random
/*  f18d774:	00000000 */ 	nop
/*  f18d778:	0050001b */ 	divu	$zero,$v0,$s0
/*  f18d77c:	00002010 */ 	mfhi	$a0
/*  f18d780:	16000002 */ 	bnez	$s0,.PF0f18d78c
/*  f18d784:	00000000 */ 	nop
/*  f18d788:	0007000d */ 	break	0x7
.PF0f18d78c:
/*  f18d78c:	0fc6348e */ 	jal	mpGetTrackNumAtSlotIndex
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
/*  f18d7e8:	0fc6348e */ 	jal	mpGetTrackNumAtSlotIndex
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

#if VERSION >= VERSION_NTSC_1_0
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
#endif

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
	{ L_MPWEAPONS_025, MPCONFIG_NOSHIELD   }, // "No Shield"
	{ L_MPWEAPONS_026, MPCONFIG_AUTOMATICS }, // "Automatics"
	{ L_MPWEAPONS_027, MPCONFIG_ROCKETS    }, // "Rocket Launcher"
	{ L_MPWEAPONS_028, MPCONFIG_SIMULANTS  }, // "Simulants"
	{ L_MPWEAPONS_029, MPCONFIG_SKEDARKING }, // "King of the Hill"
	{ L_MPWEAPONS_030, MPCONFIG_FARSIGHT   }, // "Complex FarSight"
	{ L_MPWEAPONS_031, MPCONFIG_BRIEFCASE  }, // "Hold the Briefcase"
	{ L_MPWEAPONS_032, MPCONFIG_PISTOLS    }, // "Pistol One-Hit Kills"
	{ L_MPWEAPONS_033, MPCONFIG_FLAGS      }, // "Capture the Case"
	{ L_MPWEAPONS_034, MPCONFIG_CLOAKING   }, // "Cloaking"
	{ L_MPWEAPONS_035, MPCONFIG_TEMPLE     }, // "Temple Explosives"
	{ L_MPWEAPONS_036, MPCONFIG_SLAYER     }, // "Slayer"
	{ L_MPWEAPONS_037, MPCONFIG_DRUGGUN    }, // "Tranquilizr"
	{ L_MPWEAPONS_038, MPCONFIG_SLOWMO     }, // "Slow Motion"
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

#if VERSION >= VERSION_NTSC_1_0
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
#endif // >= VERSION_NTSC_1_0

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
/*  f18edf8:	0fc61922 */ 	jal	scenarioInit
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
/*  f18eeb0:	0fc5bdaa */ 	jal	langGet
/*  f18eeb4:	240454f2 */ 	li	$a0,0x54f2
/*  f18eeb8:	26720001 */ 	addiu	$s2,$s3,0x1
/*  f18eebc:	02403025 */ 	move	$a2,$s2
/*  f18eec0:	02202025 */ 	move	$a0,$s1
/*  f18eec4:	0c004d11 */ 	jal	sprintf
/*  f18eec8:	00402825 */ 	move	$a1,$v0
/*  f18eecc:	10000006 */ 	b	.PF0f18eee8
/*  f18eed0:	928f0029 */ 	lbu	$t7,0x29($s4)
.PF0f18eed4:
/*  f18eed4:	03ce2821 */ 	addu	$a1,$s8,$t6
/*  f18eed8:	0c004bb0 */ 	jal	strcpy
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
/*  f18ef1c:	0fc67684 */ 	jal	mpIsFeatureUnlocked
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
/*  f18ef58:	0fc62878 */ 	jal	func0f18913c
/*  f18ef5c:	00000000 */ 	nop
/*  f18ef60:	0fc674a4 */ 	jal	func0f19c190
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
#elif VERSION >= VERSION_NTSC_1_0
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
#else
GLOBAL_ASM(
glabel func0f18dcec
/*  f187ef0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f187ef4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f187ef8:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f187efc:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f187f00:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f187f04:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f187f08:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f187f0c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f187f10:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f187f14:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f187f18:	908e0010 */ 	lbu	$t6,0x10($a0)
/*  f187f1c:	3c01800b */ 	lui	$at,0x800b
/*  f187f20:	00808025 */ 	or	$s0,$a0,$zero
/*  f187f24:	0fc5fe89 */ 	jal	scenarioInit
/*  f187f28:	a02e1448 */ 	sb	$t6,0x1448($at)
/*  f187f2c:	3c0f800b */ 	lui	$t7,0x800b
/*  f187f30:	25ef1438 */ 	addiu	$t7,$t7,0x1438
/*  f187f34:	02004825 */ 	or	$t1,$s0,$zero
/*  f187f38:	26080024 */ 	addiu	$t0,$s0,0x24
.NB0f187f3c:
/*  f187f3c:	8d210000 */ 	lw	$at,0x0($t1)
/*  f187f40:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f187f44:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f187f48:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*  f187f4c:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*  f187f50:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*  f187f54:	8d21fffc */ 	lw	$at,-0x4($t1)
/*  f187f58:	1528fff8 */ 	bne	$t1,$t0,.NB0f187f3c
/*  f187f5c:	ade1fffc */ 	sw	$at,-0x4($t7)
/*  f187f60:	8d210000 */ 	lw	$at,0x0($t1)
/*  f187f64:	3c0a800b */ 	lui	$t2,0x800b
/*  f187f68:	25551048 */ 	addiu	$s5,$t2,0x1048
/*  f187f6c:	3c11800b */ 	lui	$s1,0x800b
/*  f187f70:	02009025 */ 	or	$s2,$s0,$zero
/*  f187f74:	0200a025 */ 	or	$s4,$s0,$zero
/*  f187f78:	26170130 */ 	addiu	$s7,$s0,0x130
/*  f187f7c:	24100004 */ 	addiu	$s0,$zero,0x4
/*  f187f80:	26310de8 */ 	addiu	$s1,$s1,0xde8
/*  f187f84:	02a09825 */ 	or	$s3,$s5,$zero
/*  f187f88:	0000b025 */ 	or	$s6,$zero,$zero
/*  f187f8c:	ade10000 */ 	sw	$at,0x0($t7)
.NB0f187f90:
/*  f187f90:	924b0028 */ 	lbu	$t3,0x28($s2)
/*  f187f94:	00001025 */ 	or	$v0,$zero,$zero
/*  f187f98:	02601825 */ 	or	$v1,$s3,$zero
/*  f187f9c:	02802025 */ 	or	$a0,$s4,$zero
/*  f187fa0:	a22b0047 */ 	sb	$t3,0x47($s1)
.NB0f187fa4:
/*  f187fa4:	908c002c */ 	lbu	$t4,0x2c($a0)
/*  f187fa8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f187fac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f187fb0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f187fb4:	1450fffb */ 	bne	$v0,$s0,.NB0f187fa4
/*  f187fb8:	a06cffff */ 	sb	$t4,-0x1($v1)
/*  f187fbc:	92ad0000 */ 	lbu	$t5,0x0($s5)
/*  f187fc0:	02202025 */ 	or	$a0,$s1,$zero
/*  f187fc4:	02e02825 */ 	or	$a1,$s7,$zero
/*  f187fc8:	0c004e60 */ 	jal	strcpy
/*  f187fcc:	a22d0048 */ 	sb	$t5,0x48($s1)
/*  f187fd0:	924e0029 */ 	lbu	$t6,0x29($s2)
/*  f187fd4:	26d6000f */ 	addiu	$s6,$s6,0xf
/*  f187fd8:	2ac10078 */ 	slti	$at,$s6,0x78
/*  f187fdc:	a22e000f */ 	sb	$t6,0xf($s1)
/*  f187fe0:	9259002a */ 	lbu	$t9,0x2a($s2)
/*  f187fe4:	2631004c */ 	addiu	$s1,$s1,0x4c
/*  f187fe8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f187fec:	a239ffc4 */ 	sb	$t9,-0x3c($s1)
/*  f187ff0:	92580023 */ 	lbu	$t8,0x23($s2)
/*  f187ff4:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f187ff8:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f187ffc:	26b50004 */ 	addiu	$s5,$s5,0x4
/*  f188000:	26f7000f */ 	addiu	$s7,$s7,0xf
/*  f188004:	1420ffe2 */ 	bnez	$at,.NB0f187f90
/*  f188008:	a238ffc5 */ 	sb	$t8,-0x3b($s1)
/*  f18800c:	0fc65a5e */ 	jal	mpIsFeatureUnlocked
/*  f188010:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f188014:	1440000c */ 	bnez	$v0,.NB0f188048
/*  f188018:	3c04800b */ 	lui	$a0,0x800b
/*  f18801c:	3c02800b */ 	lui	$v0,0x800b
/*  f188020:	24421438 */ 	addiu	$v0,$v0,0x1438
/*  f188024:	2484143e */ 	addiu	$a0,$a0,0x143e
/*  f188028:	24030025 */ 	addiu	$v1,$zero,0x25
/*  f18802c:	90480018 */ 	lbu	$t0,0x18($v0)
.NB0f188030:
/*  f188030:	54680003 */ 	bnel	$v1,$t0,.NB0f188040
/*  f188034:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f188038:	a0400018 */ 	sb	$zero,0x18($v0)
/*  f18803c:	24420001 */ 	addiu	$v0,$v0,0x1
.NB0f188040:
/*  f188040:	5444fffb */ 	bnel	$v0,$a0,.NB0f188030
/*  f188044:	90480018 */ 	lbu	$t0,0x18($v0)
.NB0f188048:
/*  f188048:	0fc60d4b */ 	jal	func0f18913c
/*  f18804c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188050:	0fc6587f */ 	jal	func0f19c190
/*  f188054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f188058:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18805c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f188060:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f188064:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f188068:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f18806c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f188070:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f188074:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f188078:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f18807c:	03e00008 */ 	jr	$ra
/*  f188080:	27bd0038 */ 	addiu	$sp,$sp,0x38
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
