#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/title.h"
#include "game/pdmode.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/menu.h"
#include "game/playermgr.h"
#include "game/game_1531a0.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/mpstats.h"
#include "game/challenge.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "bss.h"
#include "lib/args.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

// bss
struct chrdata *g_MpAllChrPtrs[MAX_MPCHRS];
struct mpchrconfig *g_MpAllChrConfigPtrs[MAX_MPCHRS];
s32 g_MpNumChrs;
u32 var800ac534;
struct mpbotconfig g_BotConfigsArray[MAX_BOTS];
u8 g_MpSimulantDifficultiesPerNumPlayers[MAX_BOTS][4];
struct mpplayerconfig g_PlayerConfigsArray[6];
u8 g_AmBotCommands[16];
struct mpsetup g_MpSetup;
struct bossfile g_BossFile;
u32 var800acc1c;
struct mplockinfo g_MpLockInfo;
struct modelfiledata *var800acc28[18];

// Forward declaractions
struct mpweaponset g_MpWeaponSets[12];
s32 g_MpWeaponSetNum;

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b8a00[] = "||||||||||||| Starting game... players %d\n";
#endif

s32 var80087260 = 0x00000000;
bool g_MpEnableMusicSwitching = false;

struct mpweapon g_MpWeapons[NUM_MPWEAPONS] = {
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
#if VERSION != VERSION_JPN_FINAL
	/*0x19*/ { WEAPON_COMBATKNIFE,      0x09, 0x05, 0x00, 0x00, 1, 0,                                MODEL_CHRKNIFE,         0x0100 },
#endif
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
	/*0x26*/ { WEAPON_DISABLED },
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

void func0f187838(struct mpchrconfig *mpchr)
{
	s32 i = 0;

	while (i < ARRAYCOUNT(mpchr->killcounts)) {
		mpchr->killcounts[i++] = 0;
	}

	mpchr->numdeaths = 0;
	mpchr->numpoints = 0;
	mpchr->unk40 = 0;
}

void mpStartMatch(void)
{
	s32 i;
	s32 numplayers = 0;
	s32 stagenum;

	mpConfigureQuickTeamSimulants();

	if (!challengeIsFeatureUnlocked(MPFEATURE_ONEHITKILLS)) {
		g_MpSetup.options &= ~MPOPTION_ONEHITKILLS;
	}

	if (!challengeIsFeatureUnlocked(MPFEATURE_SLOWMOTION)) {
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
	mainChangeToStage(stagenum);
	setNumPlayers(numplayers);
	titleSetNextMode(TITLEMODE_SKIP);

	g_Vars.perfectbuddynum = 1;
}

void mpReset(void)
{
	s32 i;
	s32 mpindex = 0;

	g_MpNumChrs = 0;
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
		struct mpplayerconfig tmp;

		tmp = g_PlayerConfigsArray[4];
		g_PlayerConfigsArray[4] = g_PlayerConfigsArray[0];
		g_PlayerConfigsArray[0] = tmp;

		tmp = g_PlayerConfigsArray[5];
		g_PlayerConfigsArray[5] = g_PlayerConfigsArray[1];
		g_PlayerConfigsArray[1] = tmp;

		// Player index 0
		g_Vars.playerstats[0].mpindex = 0;

		g_PlayerConfigsArray[0].contpad1 = 0;
		g_PlayerConfigsArray[0].contpad2 = 2;

		if ((g_Vars.coopplayernum >= 0 && g_Vars.coopradaron)
				|| (g_Vars.antiplayernum >= 0 && g_Vars.antiradaron)) {
			g_PlayerConfigsArray[0].base.displayoptions |= MPDISPLAYOPTION_RADAR;
		} else {
			g_PlayerConfigsArray[0].base.displayoptions &= ~MPDISPLAYOPTION_RADAR;
		}

		// Player index 1
		g_Vars.playerstats[1].mpindexu32 = 1;

		g_PlayerConfigsArray[1].contpad1 = 1;
		g_PlayerConfigsArray[1].contpad2 = 3;

		if ((g_Vars.coopplayernum >= 0 && g_Vars.coopradaron)
				|| (g_Vars.antiplayernum >= 0 && g_Vars.antiradaron)) {
			g_PlayerConfigsArray[1].base.displayoptions |= MPDISPLAYOPTION_RADAR;
		} else {
			g_PlayerConfigsArray[1].base.displayoptions &= ~MPDISPLAYOPTION_RADAR;
		}

		g_MpNumChrs = 2;
	} else {
		for (i = 0; i < 4; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				g_Vars.playerstats[mpindex].mpindex = i;

				g_PlayerConfigsArray[i].contpad1 = i;
				g_PlayerConfigsArray[i].contpad2 = 0;

				mpCalculatePlayerTitle(&g_PlayerConfigsArray[i]);


				g_PlayerConfigsArray[i].newtitle = g_PlayerConfigsArray[i].title;
				g_MpNumChrs++;
				mpindex++;
			}
		}
	}

	for (i = 0; i != MAX_MPCHRS; i++) {
		struct mpchrconfig *mpchr = MPCHR(i);

		func0f187838(mpchr);

#if VERSION >= VERSION_NTSC_1_0
		g_MpAllChrPtrs[i] = NULL;
#endif
	}

	g_MpSetup.paused = false;

	g_MpEnableMusicSwitching = false;

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
				g_MpEnableMusicSwitching = true;
			}
		}

		g_MpLockInfo.unk04 = -1;
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

	// Iterate simulants, which go after players in the g_MpAllChrPtrs array
	for (i = playercount; i < g_MpNumChrs; i++) {
		if (!g_MpAllChrPtrs[i]) {
			continue;
		}

		g_MpAllChrPtrs[i]->aibot->teamisonlyai = true;

		if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
			// Iterate human players
			for (j = 0; j < playercount; j++) {
				if (g_MpAllChrPtrs[i]->team == g_MpAllChrPtrs[j]->team) {
					g_MpAllChrPtrs[i]->aibot->teamisonlyai = false;
					break;
				}
			}
		}
	}
}

void func0f187fbc(s32 playernum)
{
	g_PlayerConfigsArray[playernum].base.unk18 = 80;
	g_PlayerConfigsArray[playernum].base.unk1a = 80;
	g_PlayerConfigsArray[playernum].base.unk1c = 75;
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

	g_PlayerConfigsArray[playernum].controlmode = CONTROLMODE_11;

	g_PlayerConfigsArray[playernum].options = OPTION_LOOKAHEAD
		| OPTION_SIGHTONSCREEN
		| OPTION_AUTOAIM
		| OPTION_AMMOONSCREEN
		| OPTION_SHOWGUNFUNCTION
		| OPTION_HEADROLL
		| OPTION_0100
		| OPTION_ALWAYSSHOWTARGET
		| OPTION_SHOWZOOMRANGE;

	g_PlayerConfigsArray[playernum].handicap = 128;

	switch (playernum) {
	case 0:
	default:
		g_PlayerConfigsArray[playernum].base.mpbodynum = MPBODY_DARK_COMBAT;
		break;
	case 1:
		g_PlayerConfigsArray[playernum].base.mpbodynum = MPBODY_CASSANDRA;
		break;
	case 2:
		g_PlayerConfigsArray[playernum].base.mpbodynum = MPBODY_CARRINGTON;
		break;
	case 3:
		g_PlayerConfigsArray[playernum].base.mpbodynum = MPBODY_CILABTECH;
		break;
	}

	g_PlayerConfigsArray[playernum].base.mpheadnum = mpGetMpheadnumByMpbodynum(g_PlayerConfigsArray[playernum].base.mpbodynum);
	g_PlayerConfigsArray[playernum].base.displayoptions = MPDISPLAYOPTION_RADAR | MPDISPLAYOPTION_HIGHLIGHTTEAMS;
	g_PlayerConfigsArray[playernum].fileguid.fileid = 0;
	g_PlayerConfigsArray[playernum].fileguid.deviceserial = 0;

	if (autonames) {
		// "Player 1" etc
		sprintf(g_PlayerConfigsArray[playernum].base.name, "%s %d\n", langGet(L_MISC_437), playernum + 1);
	} else {
		g_PlayerConfigsArray[playernum].base.name[0] = '\0';
	}

	g_PlayerConfigsArray[playernum].kills = 0;
	g_PlayerConfigsArray[playernum].deaths = 0;
	g_PlayerConfigsArray[playernum].gamesplayed = 0;
	g_PlayerConfigsArray[playernum].gameswon = 0;
	g_PlayerConfigsArray[playernum].gameslost = 0;
	g_PlayerConfigsArray[playernum].time = 0;
	g_PlayerConfigsArray[playernum].distance = 0;
	g_PlayerConfigsArray[playernum].accuracy = 1000;
	g_PlayerConfigsArray[playernum].damagedealt = 0;
	g_PlayerConfigsArray[playernum].painreceived = 0;
	g_PlayerConfigsArray[playernum].headshots = 0;
	g_PlayerConfigsArray[playernum].ammoused = 0;
	g_PlayerConfigsArray[playernum].accuracymedals = 0;
	g_PlayerConfigsArray[playernum].headshotmedals = 0;
	g_PlayerConfigsArray[playernum].killmastermedals = 0;
	g_PlayerConfigsArray[playernum].survivormedals = 0;
	g_PlayerConfigsArray[playernum].title = MPPLAYERTITLE_BEGINNER;

	if (playernum < 4) {
		for (i = 0; i < 30; i++) {
			for (j = 1; j <= 4; j++) {
				challengeSetCompletedByPlayerWithNumPlayers(playernum, i, j, false);
			}
		}

		challengeDetermineUnlockedFeatures();
	}

	for (i = 0; i < 6; i++) {
		g_PlayerConfigsArray[playernum].gunfuncs[i] = 0;
	}
}

void func0f1881d4(s32 index)
{
	g_BotConfigsArray[index].base.name[0] = '\0';
	g_BotConfigsArray[index].base.mpheadnum = MPHEAD_DARK_COMBAT;
	g_BotConfigsArray[index].base.mpbodynum = MPBODY_DARK_COMBAT;
	g_BotConfigsArray[index].type = BOTTYPE_GENERAL;
	g_BotConfigsArray[index].difficulty = BOTDIFF_DISABLED;
}

void mpInit(void)
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

	g_MpSetup.fileguid.fileid = 0;
	g_MpSetup.fileguid.deviceserial = 0;

	strcpy(g_MpSetup.name, "");

	for (i = 0; i < 6; i++) {
		mpPlayerSetDefaults(i, false);
	}

	for (i = 0; i < MAX_BOTS; i++) {
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

	challengeForceUnlockBotFeatures();

	for (i = 0; i < ARRAYCOUNT(g_PlayerConfigsArray); i++) {
		for (j = 0; j < 6; j++) {
			g_PlayerConfigsArray[i].gunfuncs[j] = 0;
		}
	}

	g_MpSetup.chrslots = 0;
}

#if VERSION >= VERSION_PAL_BETA
void mpGetTeamsWithDefaultName(u8 *mask)
{
	s32 i;

	*mask = 0;

	for (i = 0; i < 8; i++) {
		if (strcmp(g_BossFile.teamnames[i], langGet(L_OPTIONS_008 + i)) == 0) {
			*mask |= 1 << i;
		}
	}
}
#endif

#if VERSION >= VERSION_PAL_BETA
void mpSetTeamNamesToDefault(u8 mask)
{
	s32 i;

	for (i = 0; i < 8; i++) {
		if (mask & (1 << i)) {
			strcpy(g_BossFile.teamnames[i], langGet(L_OPTIONS_008 + i));
		}
	}
}
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
		if (g_BossFile.teamnames[i][0] == '\0') {
			strcpy(g_BossFile.teamnames[i], langGet(L_OPTIONS_008 + i)); // "Red", "Yellow" etc
		}
	}

	// Player names
	for (i = 0; i < 4; i++) {
		if (g_PlayerConfigsArray[i].base.name[0] == '\0') {
			sprintf(g_PlayerConfigsArray[i].base.name, "%s %d\n", langGet(L_MISC_437), i + 1); // "Player 1" etc
		}
	}
}

s32 mpCalculateTeamScoreLimit(void)
{
	s32 limit = g_MpSetup.teamscorelimit;
	s32 i;

	if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE
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

/**
 * Given a pointer to an array of 12 ranking structs, populate those rankings
 * with the winner first, loser last. Return the number of rows (players).
 *
 * The function also populates the placement an rankablescore values in the
 * mpchr structs and calculates the last winner and loser for the lock settings.
 */
s32 mpGetPlayerRankings(struct ranking *rankings)
{
	s32 i;
	s32 scores[MAX_MPCHRS];
	u32 rankablescores[MAX_MPCHRS];
	struct mpchrconfig *mpchrs[MAX_MPCHRS];
	s32 chrnums[MAX_MPCHRS];
	s32 count = 0;
	s32 numteams;
	struct ranking teamrankings[MAX_MPCHRS];
	s32 winner;
	s32 loser;
	s32 score;
	s32 deaths;
	struct mpchrconfig *mpchr;
	s32 dstindex;
	bool found;
	u32 rankablescore;
	s32 j;

	if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
		numteams = mpGetTeamRankings(teamrankings);
	}

	// Populate 4 arrays with player info, sorted by highest score descending
	for (i = 0; i < MAX_MPCHRS; i++) {
		if (g_MpSetup.chrslots & (1 << i)) {
			mpchr = MPCHR(i);

			scenarioCalculatePlayerScore(mpchr, i, &score, &deaths);

			rankablescore = (score + 0x8000) << 16 | (0xffff - deaths);
			dstindex = 0;
			found = false;

			// Find where this player should be placed in the sorted arrays
			for (j = 0; j < count && !found; j++) {
				if (rankablescore > rankablescores[j]) {
					dstindex = j;
					found = true;
				}
			}

			if (!found) {
				dstindex = count;
			}

			// Shuffle everything forward after dstindex to create a gap
			for (j = count; j > dstindex; j--) {
				rankablescores[j] = rankablescores[j - 1];
				scores[j] = scores[j - 1];
				mpchrs[j] = mpchrs[j - 1];
				chrnums[j] = chrnums[j - 1];
			}

			count++;

			// Write the new figures
			rankablescores[dstindex] = (score + 0x8000) << 16 | (0xffff - deaths);
			scores[dstindex] = score;
			mpchrs[dstindex] = mpchr;
			chrnums[dstindex] = i;
		}
	}

	// Populate the rankings array, copy some values into the mpchr structs
	// and calculate the winner and loser
	winner = -1;
	loser = -1;

	for (j = 0; j < count; j++) {
		rankings[j].mpchr = mpchrs[j];
		rankings[j].teamnum = chrnums[j];
		rankings[j].positionindex = j;
		rankings[j].unk0c = 0;
		rankings[j].score = scores[j];

		// For a team game, the mpchr's placement has to be the team's placement
		// and not the placement of the individual player.
		if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
			s32 placement = numteams - 1;
			s32 i;

			for (i = 0; i < numteams; i++) {
				if (teamrankings[i].teamnum == mpchrs[j]->team) {
					placement = i;
				}
			}

			mpchrs[j]->placement = placement;
#if VERSION >= VERSION_NTSC_1_0
			mpchrs[j]->rankablescore = 255 - placement;
#endif
		} else {
			mpchrs[j]->placement = j;
#if VERSION >= VERSION_NTSC_1_0
			mpchrs[j]->rankablescore = rankablescores[j];
#endif
		}

#if VERSION < VERSION_NTSC_1_0
		mpchrs[j]->rankablescore = rankablescores[j];
#endif

		if (chrnums[j] < 4) {
			loser = chrnums[j];

			if (winner == -1) {
				winner = chrnums[j];
				if (1);
			}
		}
	}

	g_MpLockInfo.lastwinner = winner;
	g_MpLockInfo.lastloser = loser;

	if (g_BossFile.locktype == MPLOCKTYPE_RANDOM) {
		g_MpLockInfo.lockedplayernum = mpChooseRandomLockPlayer();
	}

	return count;
}

/**
 * Iterate players on the given team and add their scores.
 *
 * There are two score values:
 * - The team score, which is written to the result pointer and eventually
 *   displayed on screen
 * - The rankable score, which is the returned value. The rankable score is
 *   similar to the team score but uses the number of deaths as a tie breaker.
 */
s32 mpCalculateTeamScore(s32 teamnum, s32 *result)
{
	struct mpchrconfig *mpchr;
	s32 teamscore = 0;
	s32 teamdeaths = 0;
	bool teamexists = false;
	s32 i;
	u32 stack;
	s32 score;
	s32 deaths;

	for (i = 0; i < MAX_MPCHRS; i++) {
		if (g_MpSetup.chrslots & (1 << i)) {
			mpchr = MPCHR(i);

			if (mpchr->team == teamnum) {
				scenarioCalculatePlayerScore(mpchr, i, &score, &deaths);
				teamexists = true;
				teamscore += score;
				teamdeaths += deaths;
			}
		}
	}

	if (teamexists) {
		*result = teamscore;
		return (teamscore + 0x8000) << 16 | (0xffff - teamdeaths);
	}

	return 0;
}

/**
 * Given a pointer to an array of 8 ranking structs, populate those rankings
 * with the winning team first, losing team last. Return the number of rows
 * (teams).
 */
s32 mpGetTeamRankings(struct ranking *rankings)
{
	s32 i;
	s32 count;
	s32 apparentscores[8];
	u32 rankablescores[8];
	u32 bestrankablescore;
	s32 thisteamnum;

	count = 0;

	// Calculate scores for each team
	for (i = 0; i < 8; i++) {
		apparentscores[i] = -8000;
		rankablescores[i] = mpCalculateTeamScore(i, &apparentscores[i]);
	}

	// Iterate each slot and determine which team belongs in it.
	// As each team is found, set their apparent score to -8000 so they're not
	// found again.
	do {
		bestrankablescore = 0;
		thisteamnum = -8000;

		// Check which team has the best remaining score
		for (i = 0; i < 8; i++) {
			if (apparentscores[7 - i] > -8000 && rankablescores[7 - i] >= bestrankablescore) {
				thisteamnum = 7 - i;
				bestrankablescore = rankablescores[thisteamnum];
			}
		}

		if (thisteamnum > -8000) {
			// Append to the rankings array
			rankings[count].mpchr = NULL;
			rankings[count].teamnum = thisteamnum;
			rankings[count].positionindex = count + 1;
			rankings[count].unk0c = 0;
			rankings[count].score = apparentscores[thisteamnum];

			apparentscores[thisteamnum] = -8000;

			count++;
		}
	} while (thisteamnum != -8000);

	return count;
}

s32 func0f188bcc(void)
{
	return NUM_MPWEAPONS;
}

s32 mpGetNumWeaponOptions(void)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpWeapons); i++) {
		if (challengeIsFeatureUnlocked(g_MpWeapons[i].unlockfeature)) {
			count++;
		}
	}

	return count;
}

char *mpGetWeaponLabel(s32 weaponnum)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpWeapons); i++) {
		if (challengeIsFeatureUnlocked(g_MpWeapons[i].unlockfeature)) {
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

				return bgunGetName(g_MpWeapons[i].weaponnum);
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

void mpSetWeaponSlot(s32 slot, s32 mpweaponnum)
{
	s32 optionindex = mpweaponnum;
	s32 i;

	for (i = 0; i <= mpweaponnum; i++) {
		if (challengeIsFeatureUnlocked(g_MpWeapons[i].unlockfeature) == 0) {
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
		if (challengeIsFeatureUnlocked(g_MpWeapons[i].unlockfeature)) {
			count++;
		}
	}

	return count;
}

struct mpweapon *func0f188e24(s32 arg0)
{
	s32 v0 = arg0 + 1;
	s32 slot = 0;
	s32 a2 = v0;
	u8 mpweaponnum;

	while (v0 > 0) {
		mpweaponnum = g_MpSetup.weapons[slot];

		if (g_MpWeapons[mpweaponnum].weaponnum != WEAPON_DISABLED) {
			v0--;
		}

		if (v0 > 0) {
			slot++;

			if (slot >= 6) {
				slot = 0;

				if (a2 == v0) {
					mpweaponnum = 0;
					v0 = 0;
				}

				a2 = v0;
			}
		}
	}

	return &g_MpWeapons[mpweaponnum];
}

s32 mpCountWeaponSetThing(s32 weaponsetindex)
{
	s32 i;
	s32 count = 0;

	if (weaponsetindex >= ARRAYCOUNT(g_MpWeaponSets)) {
		count = weaponsetindex - ARRAYCOUNT(g_MpWeaponSets);
		weaponsetindex = ARRAYCOUNT(g_MpWeaponSets);
	}

	for (i = 0; i < weaponsetindex; i++) {
		if ((challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[0])
				&& challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[1])
				&& challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[2])
				&& challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[3])) || g_MpWeaponSets[i].unk0c != WEAPON_DISABLED) {
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
		if ((challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[0])
					&& challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[1])
					&& challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[2])
					&& challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[3]))
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

void func0f18913c(void)
{
	s32 i;
	bool done = false;
	u8 *ptr;
	s32 j;

	for (i = 0; !done && i < 12; i++) {
		if (challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[0])
				&& challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[1])
				&& challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[2])
				&& challengeIsFeatureUnlocked(g_MpWeaponSets[i].requirefeatures[3])) {
			ptr = &g_MpWeaponSets[i].slots[0];
		} else if (g_MpWeaponSets[i].unk0c != WEAPON_DISABLED) {
			ptr = &g_MpWeaponSets[i].unk0c;
		} else {
			ptr = NULL;
		}

		if (ptr != NULL) {
			bool ok = true;

			for (j = 0; j < 6; j++) {
				s32 weaponnum = ptr[j];

				if (weaponnum == WEAPON_MPSHIELD) {
					if (!challengeIsFeatureUnlocked(MPFEATURE_WEAPON_SHIELD)) {
						weaponnum = 0;
					}
				}

				if (weaponnum != g_MpWeapons[g_MpSetup.weapons[j]].weaponnum) {
					ok = false;
				}
			}

			if (ok) {
				done = true;
				g_MpWeaponSetNum = i;
			}
		}
	}

	if (!done) {
		g_MpWeaponSetNum = WEAPONSET_CUSTOM;
	}
}

void mpApplyWeaponSet(void)
{
	s32 i;
	u8 *ptr;

	if (g_MpWeaponSetNum >= 0 && g_MpWeaponSetNum < 12) {
		if (challengeIsFeatureUnlocked(g_MpWeaponSets[g_MpWeaponSetNum].requirefeatures[0])
				&& challengeIsFeatureUnlocked(g_MpWeaponSets[g_MpWeaponSetNum].requirefeatures[1])
				&& challengeIsFeatureUnlocked(g_MpWeaponSets[g_MpWeaponSetNum].requirefeatures[2])
				&& challengeIsFeatureUnlocked(g_MpWeaponSets[g_MpWeaponSetNum].requirefeatures[3])) {
			ptr = &g_MpWeaponSets[g_MpWeaponSetNum].slots[0];
		} else if (g_MpWeaponSets[g_MpWeaponSetNum].unk0c != WEAPON_DISABLED) {
			ptr = &g_MpWeaponSets[g_MpWeaponSetNum].unk0c;
		} else {
			ptr = NULL;
		}

		if (ptr != NULL) {
			for (i = 0; i < 6; i++) {
				u32 j;
				bool done = false;
				s32 mpweaponnum = MPWEAPON_NONE;
				s32 weaponnum = ptr[i];

				if (weaponnum == WEAPON_MPSHIELD && !challengeIsFeatureUnlocked(MPFEATURE_WEAPON_SHIELD)) {
					weaponnum = 0;
				}

				for (j = 0; !done; j++) {
					if (j > MPWEAPON_DISABLED) {
						done = true;
					} else if (weaponnum == g_MpWeapons[j].weaponnum) {
						mpweaponnum = j;
						done = true;
					}
				}

				g_MpSetup.weapons[i] = mpweaponnum;
			}
		}
	} else if (g_MpWeaponSetNum == WEAPONSET_RANDOM) {
		s32 numoptions = mpGetNumWeaponOptions();

		for (i = 0; i < 6; i++) {
			mpSetWeaponSlot(i, random() % numoptions);
		}
	} else if (g_MpWeaponSetNum == WEAPONSET_RANDOMFIVE) {
		s32 numoptions = mpGetNumWeaponOptions() - 2;

		for (i = 0; i < 5; i++) {
			mpSetWeaponSlot(i, random() % numoptions + 1);
		}

		mpSetWeaponSlot(i, mpGetNumWeaponOptions() - 1);
	}
}

void mpSetWeaponSet(s32 weaponsetnum)
{
	g_MpWeaponSetNum = func0f188f9c(weaponsetnum);
	mpApplyWeaponSet();
}

void func0f1895e8(void)
{
	if (g_MpWeaponSetNum < 12) {
		mpApplyWeaponSet();
	}
}

s32 mpGetWeaponSet(void)
{
	return mpCountWeaponSetThing(g_MpWeaponSetNum);
}

bool mpIsPaused(void)
{
	if (PLAYERCOUNT() == 1
			&& g_Vars.mplayerisrunning
			&& g_Menus[g_Vars.currentplayerstats->mpindex].curdialog) {
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
 *
 * @bug: When calling textRender(), viGetWidth() is used twice but it should be
 * viGetViewWidth() and viGetViewHeight(). These arguments to textRender() set
 * the crop box for the text, but the text doesn't extend past the box anyway
 * so it has no effect.
 */
Gfx *mpRenderModalText(Gfx *gdl)
{
	s32 textwidth;
	s32 textheight;
	s32 x;
	s32 y;
	char text[50];
	s32 stack1;

#if VERSION >= VERSION_JPN_FINAL
	g_ScaleX = g_ViRes == VIRES_HI ? 2 : 1;
#endif

	if (g_MpSetup.paused == MPPAUSEMODE_PAUSED) {
		s32 red = (s32) ((1.0f - g_20SecIntervalFrac) * 20.0f * 255.0f) % 255;
		s32 stack2;

		gdl = text0f153628(gdl);

		strcpy(text, langGet(L_MPWEAPONS_040)); // "Paused"

		x = viGetViewLeft() + viGetViewWidth() / 2;

#if VERSION >= VERSION_JPN_FINAL
		x = x / g_ScaleX;
#endif

#if VERSION >= VERSION_NTSC_1_0
		if (g_Menus[g_Vars.currentplayerstats->mpindex].curdialog)
#else
		if (g_Menus[g_Vars.currentplayernum].curdialog)
#endif
		{
			y = viGetViewTop() + 10;
		} else {
			y = viGetViewTop() + viGetViewHeight() / 2;
		}

#if VERSION >= VERSION_JPN_FINAL
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
#elif PAL
		// Use smaller fonts
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
#else
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicMd, g_FontHandelGothicMd, 0);
#endif
		x -= textwidth / 2;

#if VERSION >= VERSION_JPN_FINAL
		gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, (red << 24) | 0x00ff00ff, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);
#elif PAL
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, (red << 24) | 0x00ff00ff, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);
#else
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicMd, g_FontHandelGothicMd, (red << 24) | 0x00ff00ff, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);
#endif

		gdl = text0f153780(gdl);
	} else if (!g_MainIsEndscreen
			&& g_MpSetup.paused == MPPAUSEMODE_UNPAUSED
			&& g_Vars.currentplayer->isdead
			&& g_Vars.currentplayer->redbloodfinished
			&& g_Vars.currentplayer->deathanimfinished
			&& !(g_Vars.coopplayernum >= 0 && ((g_Vars.bond->isdead && g_Vars.coop->isdead) || !g_Vars.currentplayer->coopcanrestart || g_InCutscene))
			&& !(g_Vars.antiplayernum >= 0 && ((g_Vars.currentplayer != g_Vars.anti || g_InCutscene)))
			&& g_NumReasonsToEndMpMatch == 0) {
		// Render "Press START" text
		gdl = text0f153628(gdl);

		strcpy(text, langGet(L_MPWEAPONS_039));

		x = viGetViewLeft() + viGetViewWidth() / 2;

#if VERSION >= VERSION_JPN_FINAL
		x = x / g_ScaleX;
#endif

		y = viGetViewTop() + viGetViewHeight() / 2;

		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
		x -= textwidth / 2;

#if VERSION >= VERSION_JPN_FINAL
		gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xff0000ff, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);
#else
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xff0000ff, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);
#endif

		if (g_Vars.currentplayer->deadtimer > 0) {
			// Render countdown timer
			s32 countdowny = viGetViewTop() + viGetViewHeight() / 2 + textheight + 2;
			s32 countdownx = viGetViewLeft() + viGetViewWidth() / 2;

#if VERSION >= VERSION_JPN_FINAL
			countdownx = countdownx / g_ScaleX;
#endif
			sprintf(text, "%d\n", (g_Vars.currentplayer->deadtimer + TICKS(60) - 1) / TICKS(60));

			textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
			x = countdownx - textwidth / 2;
			y = countdowny;

#if VERSION >= VERSION_JPN_FINAL
			gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xff0000ff, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);
#else
			gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xff0000ff, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);
#endif
		}

		gdl = text0f153780(gdl);

		g_Menus[g_Vars.currentplayerstats->mpindex].openinhibit = 10;
	}

#if VERSION >= VERSION_JPN_FINAL
	g_ScaleX = 1;
#endif

	return gdl;
}

s32 mpFindMaxInt(s32 numplayers, s32 val0, s32 val1, s32 val2, s32 val3)
{
	s32 bestvalue = val0;
	s32 bestplayer = 0;

	if (numplayers >= 2) {
		if (val1 > bestvalue || (val1 == bestvalue && (random() % 2))) {
			bestplayer = 1;
			bestvalue = val1;
		} else {
			bestvalue = val0;
			bestplayer = 0;
		}

		if (numplayers >= 3) {
			if (val2 > bestvalue || (val2 == bestvalue && (random() % 2))) {
				bestplayer = 2;
				bestvalue = val2;
			}

			if (numplayers >= 4) {
				if (val3 > bestvalue || (val3 == bestvalue && (random() % 2))) {
					bestplayer = 3;
				}
			}
		}
	}

	return bestplayer;
}

s32 mpFindMinInt(s32 numplayers, s32 val0, s32 val1, s32 val2, s32 val3)
{
	s32 bestvalue = val0;
	s32 bestplayer = 0;

	if (numplayers >= 2) {
		if (val1 < bestvalue || (val1 == bestvalue && (random() % 2))) {
			bestplayer = 1;
			bestvalue = val1;
		} else {
			bestvalue = val0;
			bestplayer = 0;
		}

		if (numplayers >= 3) {
			if (val2 < bestvalue || (val2 == bestvalue && (random() % 2))) {
				bestplayer = 2;
				bestvalue = val2;
			}

			if (numplayers >= 4) {
				if (val3 < bestvalue || (val3 == bestvalue && (random() % 2))) {
					bestplayer = 3;
				}
			}
		}
	}

	return bestplayer;
}

s32 mpFindMaxFloat(s32 numplayers, f32 val0, f32 val1, f32 val2, f32 val3)
{
	// @bug: bestvalue should be an f32. Any value saved into here will be
	// rounded down which may cause the function to return an incorrect result.
	s32 bestvalue;
	s32 bestplayer = 0;

	if (numplayers >= 2) {
		if (val1 > val0 || (val1 == val0 && (random() % 2))) {
			bestplayer = 1;
			bestvalue = val1;
		} else {
			bestvalue = val0;
			bestplayer = 0;
		}

		if (numplayers >= 3) {
			if (val2 > bestvalue || (val2 == bestvalue && (random() % 2))) {
				bestplayer = 2;
				bestvalue = val2;
			}

			if (numplayers >= 4) {
				if (val3 > bestvalue || (val3 == bestvalue && (random() % 2))) {
					bestplayer = 3;
				}
			}
		}
	}

	return bestplayer;
}

s32 mpFindMinFloat(s32 numplayers, f32 val0, f32 val1, f32 val2, f32 val3)
{
	// @bug: bestvalue should be an f32. Any value saved into here will be
	// rounded down which may cause the function to return an incorrect result.
	s32 bestvalue;
	s32 bestplayer = 0;

	if (numplayers >= 2) {
		if (val0);

		if (val1 < val0 || (val1 == val0 && (random() % 2))) {
			bestplayer = 1;
			bestvalue = val1;
		} else {
			bestplayer = 0;
			bestvalue = val0;
		}

		if (numplayers >= 3) {
			if (val2 < bestvalue || (val2 == bestvalue && (random() % 2))) {
				bestplayer = 2;
				bestvalue = val2;
			}

			if (numplayers >= 4) {
				if (val3 < bestvalue || (val3 == bestvalue && (random() % 2))) {
					bestplayer = 3;
				}
			}
		}
	}

	return bestplayer;
}

struct mpweaponset g_MpWeaponSets[12] = {
	{ /*0x00*/ L_MPWEAPONS_055, { WEAPON_FALCON2,          WEAPON_MAGSEC4,     WEAPON_PHOENIX,     WEAPON_MAULER,         WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_PHOENIX,         MPFEATURE_WEAPON_MAULER,     0,                              0                       }, WEAPON_FALCON2,     WEAPON_MAGSEC4,     WEAPON_FALCON2,   WEAPON_DY357MAGNUM,    WEAPON_MPSHIELD, WEAPON_DISABLED }, // Pistols
	{ /*0x01*/ L_MPWEAPONS_054, { WEAPON_FALCON2,          WEAPON_CMP150,      WEAPON_LAPTOPGUN,   WEAPON_AR34,           WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_LAPTOPGUN,       0,                           0,                              0                       }, WEAPON_FALCON2,     WEAPON_CMP150,      WEAPON_DRAGON,    WEAPON_AR34,           WEAPON_MPSHIELD, WEAPON_DISABLED }, // Automatics
	{ /*0x02*/ L_MPWEAPONS_053, { WEAPON_MAGSEC4,          WEAPON_DY357MAGNUM, WEAPON_SHOTGUN,     WEAPON_RCP120,         WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_SHOTGUN,         MPFEATURE_WEAPON_RCP120,     0,                              0                       }, WEAPON_MAGSEC4,     WEAPON_DY357MAGNUM, WEAPON_DRAGON,    WEAPON_AR34,           WEAPON_MPSHIELD, WEAPON_DISABLED }, // Power
	{ /*0x03*/ L_MPWEAPONS_052, { WEAPON_PHOENIX,          WEAPON_CYCLONE,     WEAPON_CALLISTO,    WEAPON_FARSIGHT,       WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_FARSIGHT,        MPFEATURE_WEAPON_CALLISTO,   0,                              0                       }, WEAPON_DISABLED,    WEAPON_DISABLED,    WEAPON_DISABLED,  WEAPON_DISABLED,       WEAPON_DISABLED, WEAPON_DISABLED }, // FarSight
	{ /*0x04*/ L_MPWEAPONS_051, { WEAPON_FALCON2,          WEAPON_CMP150,      WEAPON_DRAGON,      WEAPON_TRANQUILIZER,   WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_TRANQUILIZER,    0,                           0,                              0                       }, WEAPON_DISABLED,    WEAPON_DISABLED,    WEAPON_DISABLED,  WEAPON_DISABLED,       WEAPON_DISABLED, WEAPON_DISABLED }, // Tranquilizer
	{ /*0x05*/ L_MPWEAPONS_050, { WEAPON_MAULER,           WEAPON_K7AVENGER,   WEAPON_REAPER,      WEAPON_SUPERDRAGON,    WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_SUPERDRAGON,     MPFEATURE_WEAPON_MAULER,     MPFEATURE_WEAPON_K7AVENGER,     MPFEATURE_WEAPON_REAPER }, WEAPON_DISABLED,    WEAPON_DISABLED,    WEAPON_DISABLED,  WEAPON_DISABLED,       WEAPON_DISABLED, WEAPON_DISABLED }, // Heavy
	{ /*0x06*/ L_MPWEAPONS_049, { WEAPON_FALCON2_SILENCER, WEAPON_GRENADE,     WEAPON_CMP150,      WEAPON_DY357LX,        WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_FALCON2SILENCED, MPFEATURE_WEAPON_DY357LX,    0,                              0                       }, WEAPON_DISABLED,    WEAPON_DISABLED,    WEAPON_DISABLED,  WEAPON_DISABLED,       WEAPON_DISABLED, WEAPON_DISABLED }, // Golden Magnum
	{ /*0x07*/ L_MPWEAPONS_048, { WEAPON_DEVASTATOR,       WEAPON_DEVASTATOR,  WEAPON_SUPERDRAGON, WEAPON_SUPERDRAGON,    WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_SUPERDRAGON,     MPFEATURE_WEAPON_DEVASTATOR, 0,                              0                       }, WEAPON_DISABLED,    WEAPON_DISABLED,    WEAPON_DISABLED,  WEAPON_DISABLED,       WEAPON_DISABLED, WEAPON_DISABLED }, // Explosive
	{ /*0x08*/ L_MPWEAPONS_047, { WEAPON_MAGSEC4,          WEAPON_CMP150,      WEAPON_AR34,        WEAPON_DEVASTATOR,     WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_DEVASTATOR,      0,                           0,                              0                       }, WEAPON_DISABLED,    WEAPON_DISABLED,    WEAPON_DISABLED,  WEAPON_DISABLED,       WEAPON_DISABLED, WEAPON_DISABLED }, // Grenade Launcher
	{ /*0x09*/ L_MPWEAPONS_046, { WEAPON_MAULER,           WEAPON_CYCLONE,     WEAPON_DRAGON,      WEAPON_ROCKETLAUNCHER, WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_MAULER,          0,                           0,                              0                       }, WEAPON_FALCON2,     WEAPON_CYCLONE,     WEAPON_DRAGON,    WEAPON_ROCKETLAUNCHER, WEAPON_MPSHIELD, WEAPON_DISABLED }, // Rocket Launcher
	{ /*0x0a*/ L_MPWEAPONS_045, { WEAPON_MAGSEC4,          WEAPON_LAPTOPGUN,   WEAPON_K7AVENGER,   WEAPON_PROXIMITYMINE,  WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_LAPTOPGUN,       MPFEATURE_WEAPON_K7AVENGER,  MPFEATURE_WEAPON_PROXIMITYMINE, 0                       }, WEAPON_DISABLED,    WEAPON_DISABLED,    WEAPON_DISABLED,  WEAPON_DISABLED,       WEAPON_DISABLED, WEAPON_DISABLED }, // Proximity Mine
#if VERSION == VERSION_JPN_FINAL
	{ /*0x0b*/ L_MPWEAPONS_044, { WEAPON_TIMEDMINE,        WEAPON_CROSSBOW,    WEAPON_TIMEDMINE,   WEAPON_CROSSBOW,       WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_CROSSBOW,        0,                           0,                              0                       }, WEAPON_TIMEDMINE,   WEAPON_TIMEDMINE,   WEAPON_TIMEDMINE, WEAPON_TIMEDMINE,      WEAPON_MPSHIELD, WEAPON_DISABLED }, // Close Combat
#else
	{ /*0x0b*/ L_MPWEAPONS_044, { WEAPON_COMBATKNIFE,      WEAPON_COMBATKNIFE, WEAPON_TIMEDMINE,   WEAPON_CROSSBOW,       WEAPON_MPSHIELD, WEAPON_DISABLED }, { MPFEATURE_WEAPON_CROSSBOW,        0,                           0,                              0                       }, WEAPON_COMBATKNIFE, WEAPON_COMBATKNIFE, WEAPON_TIMEDMINE, WEAPON_TIMEDMINE,      WEAPON_MPSHIELD, WEAPON_DISABLED }, // Close Combat
#endif
};

s32 g_MpWeaponSetNum = 0x00000000;

u16 g_AwardNames[] = {
	L_MPMENU_000, // "Most Suicidal"
	L_MPMENU_001, // "Who Needs Ammo?"
	L_MPMENU_002, // "Least Shielded"
	L_MPMENU_003, // "Best Protected"
	L_MPMENU_004, // "Marksmanship"
	L_MPMENU_005, // "Most Professional"
	L_MPMENU_006, // "Most Deadly"
	L_MPMENU_007, // "Most Harmless"
	L_MPMENU_008, // "Most Cowardly"
	L_MPMENU_009, // "Most Frantic"
	L_MPMENU_010, // "Most Honorable"
	L_MPMENU_011, // "Most Dishonourable"
	L_MPMENU_012, // "Shortest Life"
	L_MPMENU_013, // "Longest Life"
	L_MPMENU_014, // "Double Kill"
	L_MPMENU_015, // "Triple Kill"
	L_MPMENU_016, // "Quad Kill"
};

#if VERSION >= VERSION_NTSC_1_0
void mpCalculatePlayerTitle(struct mpplayerconfig *mpplayer)
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
u32 var80089c70nb[10] = {0};

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

struct mphead g_MpBeauHeads[NUM_MPBEAUHEADS] = {
	// head, require feature
	{ HEAD_BEAU2, 0 },
	{ HEAD_BEAU3, 0 },
	{ HEAD_BEAU4, 0 },
	{ HEAD_BEAU5, 0 },
	{ HEAD_BEAU6, 0 },
};

struct mphead g_MpHeads[NUM_MPHEADS] = {
	// head, require feature
	{ /*0x00*/ HEAD_DARK_COMBAT,  0                          },
	{ /*0x01*/ HEAD_DARK_FROCK,   MPFEATURE_CHR_CI           },
	{ /*0x02*/ HEAD_DARKAQUA,     MPFEATURE_CHR_PELAGIC      },
	{ /*0x03*/ HEAD_DARK_SNOW,    MPFEATURE_4A               },
	{ /*0x04*/ HEAD_ELVIS,        MPFEATURE_CHR_ELVIS        },
	{ /*0x05*/ HEAD_ELVIS_GOGS,   MPFEATURE_CHR_ELVIS        },
	{ /*0x06*/ HEAD_CARRINGTON,   0                          },
	{ /*0x07*/ HEAD_MRBLONDE,     MPFEATURE_CHR_MRBLONDE     },
	{ /*0x08*/ HEAD_CASSANDRA,    0                          },
	{ /*0x09*/ HEAD_TRENT,        MPFEATURE_CHR_TRENT        },
	{ /*0x0a*/ HEAD_JONATHAN,     MPFEATURE_CHR_INFILTRATION },
	{ /*0x0b*/ HEAD_VD,           0                          },
	{ /*0x0c*/ HEAD_PRESIDENT,    MPFEATURE_CHR_CI           },
	{ /*0x0d*/ HEAD_DDSHOCK,      0                          },
	{ /*0x0e*/ HEAD_BIOTECH,      MPFEATURE_CHR_BIOTECH      },
	{ /*0x0f*/ HEAD_DDSNIPER,     MPFEATURE_CHR_VILLACHRS    },
	{ /*0x10*/ HEAD_A51FACEPLATE, MPFEATURE_CHR_INFILTRATION },
	{ /*0x11*/ HEAD_SECRETARY,    0                          },
	{ /*0x12*/ HEAD_FEM_GUARD,    MPFEATURE_CHR_FEMGUARD     },
	{ /*0x13*/ HEAD_FEM_GUARD2,   MPFEATURE_CHR_FEMGUARD     },
	{ /*0x14*/ HEAD_MAIAN_S,      MPFEATURE_CHR_ELVIS        },
	{ /*0x15*/ HEAD_JON,          0                          },
	{ /*0x16*/ HEAD_BEAU1,        0                          },
	{ /*0x17*/ HEAD_ROSS,         0                          },
	{ /*0x18*/ HEAD_MARK2,        0                          },
	{ /*0x19*/ HEAD_CHRIST,       0                          },
	{ /*0x1a*/ HEAD_RUSS,         0                          },
	{ /*0x1b*/ HEAD_DARLING,      0                          },
	{ /*0x1c*/ HEAD_BRIAN,        0                          },
	{ /*0x1d*/ HEAD_JAMIE,        0                          },
	{ /*0x1e*/ HEAD_DUNCAN2,      0                          },
	{ /*0x1f*/ HEAD_KEITH,        0                          },
	{ /*0x20*/ HEAD_STEVEM,       0                          },
	{ /*0x21*/ HEAD_GRANT,        0                          },
	{ /*0x22*/ HEAD_PENNY,        0                          },
	{ /*0x23*/ HEAD_DAVEC,        0                          },
	{ /*0x24*/ HEAD_JONES,        0                          },
	{ /*0x25*/ HEAD_GRAHAM,       0                          },
	{ /*0x26*/ HEAD_ROBERT,       0                          },
	{ /*0x27*/ HEAD_NEIL2,        0                          },
	{ /*0x28*/ HEAD_SHAUN,        0                          },
	{ /*0x29*/ HEAD_ROBIN,        0                          },
	{ /*0x2a*/ HEAD_COOK,         0                          },
	{ /*0x2b*/ HEAD_PRYCE,        0                          },
	{ /*0x2c*/ HEAD_SILKE,        0                          },
	{ /*0x2d*/ HEAD_SMITH,        0                          },
	{ /*0x2e*/ HEAD_GARETH,       0                          },
	{ /*0x2f*/ HEAD_MURCHIE,      0                          },
	{ /*0x30*/ HEAD_WONG,         0                          },
	{ /*0x31*/ HEAD_CARTER,       0                          },
	{ /*0x32*/ HEAD_TINTIN,       0                          },
	{ /*0x33*/ HEAD_MUNTON,       0                          },
	{ /*0x34*/ HEAD_STAMPER,      0                          },
	{ /*0x35*/ HEAD_PHELPS,       0                          },
	{ /*0x36*/ HEAD_ALEX,         0                          },
	{ /*0x37*/ HEAD_JULIANNE,     0                          },
	{ /*0x38*/ HEAD_LAURA,        0                          },
	{ /*0x39*/ HEAD_EDMCG,        0                          },
	{ /*0x3a*/ HEAD_ANKA,         0                          },
	{ /*0x3b*/ HEAD_LESLIE_S,     0                          },
	{ /*0x3c*/ HEAD_MATT_C,       0                          },
	{ /*0x3d*/ HEAD_PEER_S,       0                          },
	{ /*0x3e*/ HEAD_EILEEN_T,     0                          },
	{ /*0x3f*/ HEAD_ANDY_R,       0                          },
	{ /*0x40*/ HEAD_BEN_R,        0                          },
	{ /*0x41*/ HEAD_STEVE_K,      0                          },
	{ /*0x42*/ HEAD_SANCHEZ,      0                          },
	{ /*0x43*/ HEAD_TIM,          0                          },
	{ /*0x44*/ HEAD_KEN,          0                          },
	{ /*0x45*/ HEAD_EILEEN_H,     0                          },
	{ /*0x46*/ HEAD_SCOTT_H,      0                          },
	{ /*0x47*/ HEAD_JOEL,         0                          },
	{ /*0x48*/ HEAD_GRIFFEY,      0                          },
#if VERSION != VERSION_JPN_FINAL
	{ /*0x49*/ HEAD_MOTO,         0                          },
#endif
	{ /*0x4a*/ HEAD_WINNER,       0                          },
};

u32 g_BotHeads[] = {
	MPHEAD_JON,
	MPHEAD_BEAU1,
	MPHEAD_ROSS,
	MPHEAD_MARK2,
	MPHEAD_CHRIST,
	MPHEAD_RUSS,
	MPHEAD_DARLING,
	MPHEAD_BRIAN,
	MPHEAD_JAMIE,
	MPHEAD_DUNCAN2,
	MPHEAD_KEITH,
	MPHEAD_STEVEM,
	MPHEAD_GRANT,
	MPHEAD_PENNY,
	MPHEAD_DAVEC,
	MPHEAD_JONES,
	MPHEAD_GRAHAM,
	MPHEAD_ROBERT,
	MPHEAD_NEIL2,
	MPHEAD_SHAUN,
	MPHEAD_ROBIN,
	MPHEAD_COOK,
	MPHEAD_PRYCE,
	MPHEAD_SILKE,
	MPHEAD_SMITH,
	MPHEAD_GARETH,
	MPHEAD_MURCHIE,
	MPHEAD_WONG,
	MPHEAD_CARTER,
	MPHEAD_TINTIN,
	MPHEAD_MUNTON,
	MPHEAD_STAMPER,
	MPHEAD_PHELPS,
	MPHEAD_ALEX,
	MPHEAD_JULIANNE,
	MPHEAD_LAURA,
	MPHEAD_EDMCG,
	MPHEAD_ANKA,
	MPHEAD_LESLIE_S,
	MPHEAD_MATT_C,
	MPHEAD_PEER_S,
	MPHEAD_EILEEN_T,
	MPHEAD_ANDY_R,
	MPHEAD_BEN_R,
	MPHEAD_STEVE_K,
	MPHEAD_SANCHEZ,
	MPHEAD_TIM,
	MPHEAD_KEN,
	MPHEAD_EILEEN_H,
	MPHEAD_SCOTT_H,
	MPHEAD_JOEL,
	MPHEAD_GRIFFEY,
#if VERSION != VERSION_JPN_FINAL
	MPHEAD_MOTO,
#endif
};

// 2d74c
struct botprofile g_BotProfiles[] = {
	// type,           difficulty,      name,       body,                 require feature
	{ BOTTYPE_GENERAL, BOTDIFF_MEAT,    L_MISC_088, MPBODY_DD_GUARD,      0                         },
	{ BOTTYPE_GENERAL, BOTDIFF_EASY,    L_MISC_089, MPBODY_DD_SECGUARD,   0                         },
	{ BOTTYPE_GENERAL, BOTDIFF_NORMAL,  L_MISC_090, MPBODY_DD_SHOCK_INF,  0                         },
	{ BOTTYPE_GENERAL, BOTDIFF_HARD,    L_MISC_091, MPBODY_DDSHOCK,       MPFEATURE_BOTDIFF_HARD    },
	{ BOTTYPE_GENERAL, BOTDIFF_PERFECT, L_MISC_092, MPBODY_STRIPES,       MPFEATURE_BOTDIFF_PERFECT },
	{ BOTTYPE_GENERAL, BOTDIFF_DARK,    L_MISC_093, MPBODY_MOORE,         MPFEATURE_BOTDIFF_DARK    },
	{ BOTTYPE_PEACE,   BOTDIFF_NORMAL,  L_MISC_094, MPBODY_DD_LABTECH,    0                         },
	{ BOTTYPE_SHIELD,  BOTDIFF_NORMAL,  L_MISC_095, MPBODY_G5_SWAT_GUARD, 0                         },
	{ BOTTYPE_ROCKET,  BOTDIFF_NORMAL,  L_MISC_096, MPBODY_G5_GUARD,      0                         },
	{ BOTTYPE_KAZE,    BOTDIFF_NORMAL,  L_MISC_097, MPBODY_PRES_SECURITY, 0                         },
	{ BOTTYPE_FIST,    BOTDIFF_NORMAL,  L_MISC_098, MPBODY_PELAGIC_GUARD, 0                         },
	{ BOTTYPE_PREY,    BOTDIFF_NORMAL,  L_MISC_099, MPBODY_DDSHOCK,       0                         },
	{ BOTTYPE_COWARD,  BOTDIFF_NORMAL,  L_MISC_100, MPBODY_PRESIDENT,     0                         },
	{ BOTTYPE_JUDGE,   BOTDIFF_NORMAL,  L_MISC_101, MPBODY_STEWARD,       0                         },
	{ BOTTYPE_FEUD,    BOTDIFF_NORMAL,  L_MISC_102, MPBODY_NSA_LACKEY,    0                         },
	{ BOTTYPE_SPEED,   BOTDIFF_NORMAL,  L_MISC_103, MPBODY_MRBLONDE,      0                         },
	{ BOTTYPE_TURTLE,  BOTDIFF_NORMAL,  L_MISC_104, MPBODY_CARRINGTON,    0                         },
	{ BOTTYPE_VENGE,   BOTDIFF_NORMAL,  L_MISC_105, MPBODY_ALASKAN_GUARD, 0                         },
};

// 2d7dc
struct mpbody g_MpBodies[NUM_MPBODIES] = {
	// global body ID,                name,             head,             require feature
	/*0x00*/ { BODY_DARK_COMBAT,      L_OPTIONS_016,    HEAD_DARK_COMBAT, 0               },
	/*0x01*/ { BODY_DARK_TRENCH,      L_OPTIONS_017,    HEAD_DARK_COMBAT, MPFEATURE_CHR_JOTRENCH    },
	/*0x02*/ { BODY_DARK_FROCK,       L_OPTIONS_018,    HEAD_DARK_FROCK,  MPFEATURE_CHR_CI    },
	/*0x03*/ { BODY_DARK_RIPPED,      L_OPTIONS_019,    HEAD_DARK_FROCK,  MPFEATURE_CHR_CI    },
	/*0x04*/ { BODY_DARK_AF1,         L_OPTIONS_020,    HEAD_DARK_COMBAT, MPFEATURE_CHR_AF1    },
	/*0x05*/ { BODY_DARK_LEATHER,     L_MPWEAPONS_156, HEAD_DARK_COMBAT, MPFEATURE_CHR_G5    },
	/*0x06*/ { BODY_DARK_NEGOTIATOR,  L_MPWEAPONS_157, HEAD_DARK_COMBAT, MPFEATURE_CHR_VILLACHRS    },
	/*0x07*/ { BODY_DARKWET,          L_OPTIONS_021,    HEAD_DARKAQUA,    MPFEATURE_CHR_PELAGIC    },
	/*0x08*/ { BODY_DARKAQUALUNG,     L_OPTIONS_022,    HEAD_DARKAQUA,    MPFEATURE_CHR_PELAGIC    },
	/*0x09*/ { BODY_DARKSNOW,         L_OPTIONS_023,    HEAD_DARK_SNOW,   MPFEATURE_4A    },
	/*0x0a*/ { BODY_DARKLAB,          L_OPTIONS_024,    HEAD_DARK_COMBAT, MPFEATURE_CHR_INFILTRATION    },
	/*0x0b*/ { BODY_THEKING,          L_OPTIONS_025,    HEAD_ELVIS,       MPFEATURE_CHR_ELVIS    },
	/*0x0c*/ { BODY_ELVIS1,           L_OPTIONS_026,    HEAD_ELVIS,       MPFEATURE_CHR_ELVIS    },
	/*0x0d*/ { BODY_ELVISWAISTCOAT,   L_MPWEAPONS_158, HEAD_ELVIS,       MPFEATURE_CHR_ELVIS    },
	/*0x0e*/ { BODY_CARRINGTON,       L_OPTIONS_027,    HEAD_CARRINGTON,  0               },
	/*0x0f*/ { BODY_CARREVENINGSUIT,  L_OPTIONS_028,    HEAD_CARRINGTON,  MPFEATURE_CHR_CI    },
	/*0x10*/ { BODY_MRBLONDE,         L_OPTIONS_029,    HEAD_MRBLONDE,    MPFEATURE_CHR_MRBLONDE    },
	/*0x11*/ { BODY_CASSANDRA,        L_OPTIONS_030,    HEAD_CASSANDRA,   0               },
	/*0x12*/ { BODY_TRENT,            L_OPTIONS_031,    HEAD_TRENT,       MPFEATURE_CHR_TRENT    },
	/*0x13*/ { BODY_JONATHAN,         L_OPTIONS_032,    HEAD_JONATHAN,    MPFEATURE_4C    },
	/*0x14*/ { BODY_CILABTECH,        L_OPTIONS_033,    1000,             0               },
	/*0x15*/ { BODY_CIFEMTECH,        L_OPTIONS_034,    1000,             0               },
	/*0x16*/ { BODY_CISOLDIER,        L_OPTIONS_035,    1000,             0               },
	/*0x17*/ { BODY_DDSHOCK,          L_OPTIONS_036,    HEAD_DDSHOCK,     0               },
	/*0x18*/ { BODY_FEM_GUARD,        L_OPTIONS_037,    1000,             MPFEATURE_CHR_FEMGUARD    },
	/*0x19*/ { BODY_DD_SECGUARD,      L_OPTIONS_038,    1000,             0               },
	/*0x1a*/ { BODY_DD_GUARD,         L_OPTIONS_039,    1000,             0               },
	/*0x1b*/ { BODY_DD_SHOCK_INF,     L_OPTIONS_040,    1000,             0               },
	/*0x1c*/ { BODY_SECRETARY,        L_OPTIONS_041,    1000,             0               },
	/*0x1d*/ { BODY_OFFICEWORKER,     L_OPTIONS_042,    1000,             MPFEATURE_CHR_OFFICEWORKER    },
	/*0x1e*/ { BODY_OFFICEWORKER2,    L_OPTIONS_043,    1000,             MPFEATURE_CHR_OFFICEWORKER    },
	/*0x1f*/ { BODY_NEGOTIATOR,       L_OPTIONS_044,    1000,             MPFEATURE_CHR_VILLACHRS    },
	/*0x20*/ { BODY_DDSNIPER,         L_OPTIONS_045,    HEAD_DDSNIPER,    MPFEATURE_CHR_VILLACHRS    },
	/*0x21*/ { BODY_G5_GUARD,         L_OPTIONS_046,    1000,             MPFEATURE_CHR_G5    },
	/*0x22*/ { BODY_G5_SWAT_GUARD,    L_OPTIONS_047,    1000,             MPFEATURE_CHR_G5    },
	/*0x23*/ { BODY_CIAGUY,           L_OPTIONS_048,    1000,             MPFEATURE_CHR_CIAFBI    },
	/*0x24*/ { BODY_FBIGUY,           L_OPTIONS_049,    1000,             MPFEATURE_CHR_CIAFBI    },
	/*0x25*/ { BODY_AREA51GUARD,      L_OPTIONS_050,    1000,             MPFEATURE_CHR_INFILTRATION    },
	/*0x26*/ { BODY_A51TROOPER,       L_OPTIONS_051,    1000,             MPFEATURE_CHR_INFILTRATION    },
	/*0x27*/ { BODY_A51AIRMAN,        L_OPTIONS_052,    1000,             MPFEATURE_CHR_INFILTRATION    },
	/*0x28*/ { BODY_OVERALL,          L_OPTIONS_053,    1000,             MPFEATURE_CHR_INFILTRATION    },
	/*0x29*/ { BODY_STRIPES,          L_OPTIONS_054,    1000,             MPFEATURE_CHR_STRIPES    },
	/*0x2a*/ { BODY_LABTECH,          L_OPTIONS_055,    1000,             MPFEATURE_CHR_LABTECH    },
	/*0x2b*/ { BODY_FEMLABTECH,       L_OPTIONS_056,    1000,             MPFEATURE_CHR_LABTECH    },
	/*0x2c*/ { BODY_DD_LABTECH,       L_OPTIONS_057,    1000,             MPFEATURE_CHR_LABTECH    },
	/*0x2d*/ { BODY_BIOTECH,          L_OPTIONS_058,    HEAD_BIOTECH,     MPFEATURE_CHR_BIOTECH    },
	/*0x2e*/ { BODY_ALASKAN_GUARD,    L_OPTIONS_059,    1000,             MPFEATURE_CHR_ALASKANGUARD    },
	/*0x2f*/ { BODY_PILOTAF1,         L_OPTIONS_060,    1000,             MPFEATURE_CHR_AF1    },
	/*0x30*/ { BODY_STEWARD,          L_OPTIONS_061,    1000,             MPFEATURE_CHR_AF1    },
	/*0x31*/ { BODY_STEWARDESS,       L_OPTIONS_062,    1000,             MPFEATURE_CHR_AF1    },
	/*0x32*/ { BODY_STEWARDESS_COAT,  L_OPTIONS_063,    1000,             MPFEATURE_CHR_AF1    },
	/*0x33*/ { BODY_PRESIDENT,        L_OPTIONS_064,    HEAD_PRESIDENT,   MPFEATURE_CHR_CI    },
	/*0x34*/ { BODY_NSA_LACKEY,       L_OPTIONS_065,    1000,             MPFEATURE_CHR_NSALACKEY    },
	/*0x35*/ { BODY_PRES_SECURITY,    L_OPTIONS_066,    1000,             MPFEATURE_CHR_PRESSECURITY    },
	/*0x36*/ { BODY_PRESIDENT_CLONE2, L_OPTIONS_067,    HEAD_PRESIDENT,   MPFEATURE_CHR_PRESCLONE    },
	/*0x37*/ { BODY_PELAGIC_GUARD,    L_OPTIONS_068,    1000,             MPFEATURE_CHR_PELAGIC    },
	/*0x38*/ { BODY_MAIAN_SOLDIER,    L_OPTIONS_069,    HEAD_MAIAN_S,     MPFEATURE_CHR_ELVIS    },
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
#if VERSION != VERSION_JPN_FINAL
	HEAD_MOTO,
#endif
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
/**
 * Calculate player awards, medals, and update character statistics.
 */
void mpCalculateAwards(void)
{
	s32 playercount;
	s32 i;
	s32 j;
	s32 prevplayernum;
	s32 duration60;
	struct awardmetrics metrics[4];

	// @bug: playerrankings should have 12 elements. Because it's too small,
	// overflow occurs in mpGetPlayerRankings. The overflow writes into the
	// metrics array (above) which is yet to be initialised, so this bug has
	// no effect on IDO.
#ifdef AVOID_UB
	struct ranking playerrankings[MAX_MPCHRS];
#else
	struct ranking playerrankings[1];
#endif

	s32 numchrs;
	s32 numteams;
	struct ranking teamrankings[MAX_MPCHRS];
	u32 stack[4];

	playercount = PLAYERCOUNT();

	duration60 = playerGetMissionTime();

	func00033dd8();

	numchrs = mpGetPlayerRankings(playerrankings);
	numteams = (g_MpSetup.options & MPOPTION_TEAMSENABLED) ? mpGetTeamRankings(teamrankings) : 0;

	prevplayernum = g_Vars.currentplayernum;

	// Iterate all human players and update their character stats.
	// At the same time, populate the metrics array
	// which is a temporary array for award calculation.
	for (i = 0; i < playercount; i++) {
		struct mpchrconfig *mpchr = mpGetChrConfigBySlotNum(i);
		struct mpplayerconfig *mpplayer = (struct mpplayerconfig *)mpchr;
		s32 chrnum = mpGetChrIndexBySlotNum(i);
		s32 sum;

		setCurrentPlayerNum(i);

		g_Vars.currentplayer->award1 = NULL;
		g_Vars.currentplayer->award2 = NULL;

		metrics[i].numshots = mpstatsGetPlayerShotCountByRegion(SHOTREGION_TOTAL);
		metrics[i].numheadshots = mpstatsGetPlayerShotCountByRegion(SHOTREGION_HEAD);
		metrics[i].numkills = 0;
		metrics[i].numdeaths = 0;
		metrics[i].numsuicides = 0;

		for (j = 0; j < MAX_MPCHRS; j++) {
			if (chrnum == j) {
				metrics[i].numsuicides += mpchr->killcounts[j];
			} else {
				metrics[i].numkills += mpchr->killcounts[j];
			}
		}

		for (j = 0; j < MAX_MPCHRS; j++) {
			struct mpchrconfig *othermpchr = MPCHR(j);
			metrics[i].numdeaths += othermpchr->killcounts[chrnum];
		}

		metrics[i].ksratio = metrics[i].numkills * 100.0f / (metrics[i].numshots + 1.0f);
		metrics[i].kdratio = metrics[i].numkills * 100.0f / (metrics[i].numdeaths + 1.0f);
		metrics[i].backshotcount = g_Vars.playerstats[i].backshotcount;
		metrics[i].drawplayercount = g_Vars.playerstats[i].drawplayercount;
		metrics[i].avgkmperhour = g_Vars.playerstats[i].distance / 100000.0f / ((duration60 + 1) / (3600.0f * 60.0f));
		metrics[i].armourcount = g_Vars.playerstats[i].armourcount;
		metrics[i].awards = 0;
		metrics[i].longestlife = g_Vars.playerstats[i].longestlife;
		metrics[i].shortestlife = g_Vars.playerstats[i].shortestlife;

		sum = mpstatsGetPlayerShotCountByRegion(SHOTREGION_HEAD)
			+ mpstatsGetPlayerShotCountByRegion(SHOTREGION_BODY)
			+ mpstatsGetPlayerShotCountByRegion(SHOTREGION_LIMB)
			+ mpstatsGetPlayerShotCountByRegion(SHOTREGION_GUN)
			+ mpstatsGetPlayerShotCountByRegion(SHOTREGION_HAT)
			+ mpstatsGetPlayerShotCountByRegion(SHOTREGION_OBJECT);

		if (metrics[i].numshots > 0) {
			metrics[i].accuracyfrac = sum / (f32)metrics[i].numshots;
		} else {
			metrics[i].accuracyfrac = 0.0f;
		}

		if (metrics[i].accuracyfrac > 1.0f) {
			metrics[i].accuracyfrac = 1.0f;
		}

		mpplayer->medals = 0;

		if (!g_CheatsActiveBank0 && !g_CheatsActiveBank1) {
			mpplayer->kills += metrics[i].numkills;
			mpplayer->deaths += metrics[i].numdeaths;
			mpplayer->gamesplayed++;
			mpplayer->time += duration60 / 60;
			mpplayer->distance += (u32)(g_Vars.playerstats[i].distance / 10000.0f);

			if (metrics[i].numshots > 0) {
				if (mpplayer->gamesplayed < 2) {
					mpplayer->accuracy = metrics[i].accuracyfrac * 1000.0f;
				} else {
					mpplayer->accuracy = ((metrics[i].accuracyfrac * 0.3f) + (mpplayer->accuracy / 1000.0f * 0.7f)) * 1000.0f;
				}
			}

			mpplayer->damagedealt += (u32)(g_Vars.playerstats[i].damtransmitted / 0.1f);
			mpplayer->painreceived += (u32)(g_Vars.playerstats[i].damreceived / 0.1f);
			mpplayer->headshots += metrics[i].numheadshots;
			mpplayer->ammoused += metrics[i].numshots;

			if ((numchrs >= 2 && (g_MpSetup.options & MPOPTION_TEAMSENABLED) == 0) || numteams >= 2) {
				bool lost = false;

				if (mpplayer->base.placement == 0) {
					for (j = 0; j < MAX_MPCHRS; j++) {
						if (g_MpSetup.chrslots & (1 << j)) {
							struct mpchrconfig *othermpchr = MPCHR(j);

							if (othermpchr->rankablescore == mpplayer->base.rankablescore
									&& othermpchr != &mpplayer->base
									&& !((g_MpSetup.options & MPOPTION_TEAMSENABLED) && othermpchr->team == mpplayer->base.team)) {
								lost = true;
							}
						}
					}

					if (!lost) {
						mpplayer->gameswon++;
					}
				}

				if (((g_MpSetup.options & MPOPTION_TEAMSENABLED) == 0 && numchrs == mpplayer->base.placement + 1)
						|| ((g_MpSetup.options & MPOPTION_TEAMSENABLED) && numteams == mpplayer->base.placement + 1)) {
					bool won = false;

					for (j = 0; j < MAX_MPCHRS; j++) {
						if (g_MpSetup.chrslots & (1 << j)) {
							struct mpchrconfig *othermpchr = MPCHR(j);

							if (othermpchr->rankablescore == mpplayer->base.rankablescore
									&& &mpplayer->base != othermpchr
									&& !((g_MpSetup.options & MPOPTION_TEAMSENABLED) && othermpchr->team == mpplayer->base.team)) {
								won = true;
							}
						}
					}

					if (!won) {
						mpplayer->gameslost++;
					}
				}
			} else {
				// empty
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);

	// Choose which players are eligible for which awards
	i = mpFindMaxInt(playercount, metrics[0].numsuicides, metrics[1].numsuicides, metrics[2].numsuicides, metrics[3].numsuicides);

	if (metrics[i].numsuicides > 0) {
		metrics[i].awards |= AWARD_MOSTSUICIDAL;
	}

	i = mpFindMinInt(playercount, metrics[0].numshots, metrics[1].numshots, metrics[2].numshots, metrics[3].numshots);

	if (metrics[i].numshots < 100) {
		metrics[i].awards |= AWARD_WHONEEDSAMMO;
	}

	i = mpFindMinFloat(playercount, metrics[0].armourcount, metrics[1].armourcount, metrics[2].armourcount, metrics[3].armourcount);

	if (metrics[i].armourcount <= 2.0f) {
		metrics[i].awards |= AWARD_LEASTSHIELDED;
	}

	i = mpFindMaxFloat(playercount, metrics[0].armourcount, metrics[1].armourcount, metrics[2].armourcount, metrics[3].armourcount);

	if (metrics[i].armourcount > 6.0f) {
		metrics[i].awards |= AWARD_BESTPROTECTED;
	}

	i = mpFindMaxInt(playercount, metrics[0].numheadshots, metrics[1].numheadshots, metrics[2].numheadshots, metrics[3].numheadshots);

	if (metrics[i].numheadshots > 0) {
		metrics[i].awards |= AWARD_MARKSMANSHIP;
	}

	i = mpFindMaxFloat(playercount, metrics[0].ksratio, metrics[1].ksratio, metrics[2].ksratio, metrics[3].ksratio);

	if (metrics[i].ksratio > 0.0f) {
		metrics[i].awards |= AWARD_MOSTPROFESSIONAL;
	}

	i = mpFindMaxFloat(playercount, metrics[0].kdratio, metrics[1].kdratio, metrics[2].kdratio, metrics[3].kdratio);

	if (metrics[i].kdratio > 0.0f) {
		metrics[i].awards |= AWARD_MOSTDEADLY;
	}

	i = mpFindMinFloat(playercount, metrics[0].kdratio, metrics[1].kdratio, metrics[2].kdratio, metrics[3].kdratio);

	if (PLAYERCOUNT() >= 2) {
		metrics[i].awards |= AWARD_MOSTHARMLESS;
	}

	i = mpFindMinInt(playercount, metrics[0].drawplayercount, metrics[1].drawplayercount, metrics[2].drawplayercount, metrics[3].drawplayercount);

	if (PLAYERCOUNT() >= 2) {
		metrics[i].awards |= AWARD_MOSTCOWARDLY;
	}

	i = mpFindMaxFloat(playercount, metrics[0].avgkmperhour, metrics[1].avgkmperhour, metrics[2].avgkmperhour, metrics[3].avgkmperhour);

	if (metrics[i].avgkmperhour > 10.0f) {
		metrics[i].awards |= AWARD_MOSTFRANTIC;
	}

	i = mpFindMinInt(playercount, metrics[0].backshotcount, metrics[1].backshotcount, metrics[2].backshotcount, metrics[3].backshotcount);
	metrics[i].awards |= AWARD_MOSTHONORABLE;

	i = mpFindMaxInt(playercount, metrics[0].backshotcount, metrics[1].backshotcount, metrics[2].backshotcount, metrics[3].backshotcount);

	if (metrics[i].backshotcount > 0 && (metrics[i].awards & AWARD_MOSTHONORABLE) == 0) {
		metrics[i].awards |= AWARD_MOSTDISHONORABLE;
	}

	i = mpFindMaxInt(playercount, metrics[0].longestlife, metrics[1].longestlife, metrics[2].longestlife, metrics[3].longestlife);

	if (metrics[i].longestlife > 0) {
		metrics[i].awards |= AWARD_LONGESTLIFE;
	}

	i = mpFindMinInt(playercount, metrics[0].shortestlife, metrics[1].shortestlife, metrics[2].shortestlife, metrics[3].shortestlife);

	if (metrics[i].shortestlife > 0 && metrics[i].numdeaths > 0) {
		metrics[i].awards |= AWARD_SHORTESTLIFE;
	}

	for (i = 0; i < playercount; i++) {
		if (g_Vars.playerstats[i].maxsimulkills == 4) {
			metrics[i].awards |= AWARD_QUADKILL;
		} else if (g_Vars.playerstats[i].maxsimulkills == 3) {
			metrics[i].awards |= AWARD_TRIPLEKILL;
		} else if (g_Vars.playerstats[i].maxsimulkills == 2) {
			metrics[i].awards |= AWARD_DOUBLEKILL;
		}
	}

	// These loops would have printed each player's awards
	for (i = 0; i < playercount; i++) {
		for (j = 0; j < 17; j++) {
			if (metrics[i].awards & (1 << j));
		}
	}

	// For each player, choose which two awards to actually give them.
	// Note that the first award checked is quad kill, but after that the awards
	// are checked randomly. So if a player has quad kill they'll definitely see
	// it on the endscreen, but this is not the case for triple kill or any
	// other awards.
	for (i = 0; i < playercount; i++) {
		s32 numdone = 0;
		s32 awardindex = 16;

		if (playercount == 1) {
			// In a single player game, only allow the following awards
			metrics[i].awards &= 0
				| AWARD_MARKSMANSHIP
				| AWARD_MOSTPROFESSIONAL
				| AWARD_MOSTDEADLY
				| AWARD_MOSTFRANTIC
				| AWARD_MOSTHONORABLE
				| AWARD_DOUBLEKILL
				| AWARD_TRIPLEKILL
				| AWARD_QUADKILL;
		}

		while (numdone == 0) {
			if (metrics[i].awards & (1 << awardindex)) {
				metrics[i].awards &= ~(1 << awardindex);
				g_Vars.players[i]->award1 = langGet(g_AwardNames[awardindex]);
				numdone = 1;
			}

			if (metrics[i].awards == 0) {
				numdone = 1;
			}

			awardindex = random() % 17;
		}

		while (numdone < 2) {
			awardindex = random() % 17;

			if (metrics[i].awards & (1 << awardindex)) {
				metrics[i].awards &= ~(1 << awardindex);
				g_Vars.players[i]->award2 = langGet(g_AwardNames[awardindex]);
				numdone = 2;
			}

			if (metrics[i].awards == 0) {
				numdone = 2;
			}
		}
	}

	// Calculate KillMaster and Survivor medals
	if (numchrs >= 2) {
		s32 mostkillsvalue = 0;
		s32 mostkillsplayer = -1;
		s32 leastdeathsvalue = 0xffffff;
		s32 leastdeathsplayer = -1;
		s32 k;

		for (k = 0; k < MAX_MPCHRS; k++) {
			if (g_MpSetup.chrslots & (1 << k)) {
				s32 totalkills = 0;
				struct mpchrconfig *mpchr = MPCHR(k);

				for (j = 0; j < MAX_MPCHRS; j++) {
					// @bug: i should be k. The value of i was incremented after
					// the last iteration of its loop above so it'll be between
					// 1 and 4 inclusively depending on the number of players.
					// The bot nums start from 4 regardless of how many players
					// there are. So in a game with 4 humans, the kills on the
					// first bot will not be considered for the killmaster medal
					// which means the medal could go to a player who got fewer
					// total kills. Additionally, suicides are counted as kills
					// while the intention here was to omit them.
					if (i != j) {
						totalkills += mpchr->killcounts[j];
					}
				}

				if (totalkills == mostkillsvalue) {
					mostkillsplayer = -1;
				}

				if (totalkills > mostkillsvalue) {
					mostkillsplayer = k;
					mostkillsvalue = totalkills;
				}

				if (mpchr->numdeaths == leastdeathsvalue) {
					leastdeathsplayer = -1;
				}

				if (mpchr->numdeaths < leastdeathsvalue) {
					leastdeathsplayer = k;
					leastdeathsvalue = mpchr->numdeaths;
				}
			}
		}

		if (!g_CheatsActiveBank0 && !g_CheatsActiveBank1) {
			if (mostkillsplayer < 4 && mostkillsplayer >= 0) {
				struct mpplayerconfig *mpplayer = (struct mpplayerconfig *)MPCHR(mostkillsplayer);
				mpplayer->medals |= MEDAL_KILLMASTER;
				mpplayer->killmastermedals++;
			}

			if (leastdeathsplayer < 4 && leastdeathsplayer >= 0) {
				struct mpplayerconfig *mpplayer = (struct mpplayerconfig *)MPCHR(leastdeathsplayer);
				mpplayer->medals |= MEDAL_SURVIVOR;
				mpplayer->survivormedals++;
			}
		}
	}

	// Calculate Headshot and Accuracy medals
	if (!g_CheatsActiveBank0 && !g_CheatsActiveBank1 && playercount >= 2) {
		s32 mostheadshotvalue = 0;
		f32 mostaccuratevalue = 0.5f;
		s32 mostheadshotplayer = -1;
		s32 mostaccurateplayer = -1;

		for (i = 0; i < playercount; i++) {
			if (mostheadshotvalue == metrics[i].numheadshots) {
				mostheadshotplayer = -1;
			}

			if (metrics[i].numheadshots > mostheadshotvalue) {
				mostheadshotplayer = i;
				mostheadshotvalue = metrics[i].numheadshots;
			}

			if (metrics[i].accuracyfrac > mostaccuratevalue) {
				mostaccurateplayer = i;
				mostaccuratevalue = metrics[i].accuracyfrac;
			}
		}

		if (mostheadshotplayer >= 0) {
			struct mpplayerconfig *mpplayer = (struct mpplayerconfig *)mpGetChrConfigBySlotNum(mostheadshotplayer);
			mpplayer->medals |= MEDAL_HEADSHOT;
			mpplayer->headshotmedals++;
		}

		if (mostaccurateplayer >= 0) {
			struct mpplayerconfig *mpplayer = (struct mpplayerconfig *)mpGetChrConfigBySlotNum(mostaccurateplayer);
			mpplayer->medals |= MEDAL_ACCURACY;
			mpplayer->accuracymedals++;
		}
	}

	// Recalculate title for all players
	for (i = 0; i < playercount; i++) {
		struct mpplayerconfig *mpchr = (struct mpplayerconfig *)mpGetChrConfigBySlotNum(i);
		mpCalculatePlayerTitle(mpchr);
	}
}
#else
GLOBAL_ASM(
glabel mpCalculateAwards
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
/*  f1849b4:	0fc2ff91 */ 	jal	playerGetMissionTime
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
/*  f184a28:	0fc61a7b */ 	jal	mpGetChrConfigBySlotNum
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
/*  f185178:	0fc6102a */ 	jal	mpFindMaxInt
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
/*  f1851c0:	0fc6106c */ 	jal	mpFindMinInt
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
/*  f18520c:	0fc61106 */ 	jal	mpFindMinFloat
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
/*  f185264:	0fc610ae */ 	jal	mpFindMaxFloat
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
/*  f1852bc:	0fc6102a */ 	jal	mpFindMaxInt
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
/*  f185304:	0fc610ae */ 	jal	mpFindMaxFloat
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
/*  f18535c:	0fc610ae */ 	jal	mpFindMaxFloat
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
/*  f1853b4:	0fc61106 */ 	jal	mpFindMinFloat
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
/*  f185480:	0fc6106c */ 	jal	mpFindMinInt
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
/*  f18554c:	0fc610ae */ 	jal	mpFindMaxFloat
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
/*  f1855a4:	0fc6106c */ 	jal	mpFindMinInt
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
/*  f1855e0:	0fc6102a */ 	jal	mpFindMaxInt
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
/*  f185630:	0fc6102a */ 	jal	mpFindMaxInt
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
/*  f185678:	0fc6106c */ 	jal	mpFindMinInt
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
/*  f185b98:	0fc61a7b */ 	jal	mpGetChrConfigBySlotNum
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
/*  f185bc0:	0fc61a7b */ 	jal	mpGetChrConfigBySlotNum
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
/*  f185bec:	0fc61a7b */ 	jal	mpGetChrConfigBySlotNum
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

	musicStartMenu();
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
	mpCalculateAwards();

	if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
		challengeConsiderMarkingComplete();
	}

	func0f0f820c(NULL, -6);
}

s32 mpGetNumHeads2(void)
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
		if (g_HeadsAndBodies[g_MpBodies[mpbodynum].bodynum].ismale) {
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

void mpFindUnusedHeadAndBody(u8 *mpheadnum, u8 *mpbodynum)
{
	struct mpchrconfig *mpchr;
	bool available;
	u8 trympheadnum;
	u8 trympbodynum;
	s32 i;

	do {
		available = true;
		trympheadnum = random() % NUM_MPHEADS;
		trympbodynum = random() % NUM_MPBODIES;

		for (i = 0; i < MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				mpchr = MPCHR(i);

				if (mpchr->mpheadnum == trympheadnum) {
					available = false;
				}

				if (mpchr->mpbodynum == trympbodynum) {
					available = false;
				}
			}
		}
	} while (!available);

	if (1);

	*mpheadnum = trympheadnum;
	*mpbodynum = trympbodynum;
}

s32 mpChooseRandomLockPlayer(void)
{
	s32 start = random() % 4;
	s32 i;

	for (i = (start + 1) % 4;; i = (i + 1) % 4) {
		if ((g_MpSetup.chrslots & (1 << i)) || i == start) {
			break;
		}
	}

	return i;
}

bool mpSetLock(s32 locktype, s32 playernum)
{
	g_BossFile.locktype = locktype;

	if (g_BossFile.locktype == MPLOCKTYPE_RANDOM) {
		g_MpLockInfo.lockedplayernum = mpChooseRandomLockPlayer();
	} else {
		g_MpLockInfo.lockedplayernum = playernum;
	}

	return true;
}

s32 mpGetLockType(void)
{
	return g_BossFile.locktype;
}

u32 mpGetLockPlayerNum(void)
{
	return g_MpLockInfo.lockedplayernum;
}

bool mpIsPlayerLockedOut(s32 playernum)
{
	if (g_BossFile.locktype == MPLOCKTYPE_NONE) {
		return false;
	}

	if (g_MpLockInfo.lockedplayernum == playernum) {
		return false;
	}

	return true;
}

void mpCalculateLockIfLastWinnerOrLoser(void)
{
	if (g_BossFile.locktype == MPLOCKTYPE_LASTWINNER && g_MpLockInfo.lastwinner >= 0) {
		g_MpLockInfo.lockedplayernum = g_MpLockInfo.lastwinner;
	}

	if (g_BossFile.locktype == MPLOCKTYPE_LASTLOSER && g_MpLockInfo.lastloser >= 0) {
		g_MpLockInfo.lockedplayernum = g_MpLockInfo.lastloser;
	}

	if (g_MpLockInfo.lockedplayernum >= 0
			&& g_BossFile.locktype != MPLOCKTYPE_CHALLENGE
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
			if (g_GameFile.besttimes[stageindex][i]) {
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
	g_BossFile.usingmultipletunes = enable;
}

bool mpGetUsingMultipleTunes(void)
{
	return g_BossFile.usingmultipletunes;
}

bool mpIsMultiTrackSlotEnabled(s32 slot)
{
	s32 tracknum = mpGetTrackNumAtSlotIndex(slot);
	u8 index = tracknum >> 3;
	u8 value = 1 << (tracknum & 7);

	if ((g_BossFile.multipletracknums[index] & value) == 0) {
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
		g_BossFile.multipletracknums[index] |= value;
	} else {
		g_BossFile.multipletracknums[index] &= ~value;
	}
}

void mpSetTrackSlotEnabled(s32 slot)
{
	if (mpGetUsingMultipleTunes()) {
		mpSetMultiTrackSlotEnabled(slot, 1 - mpIsMultiTrackSlotEnabled(slot));
	} else {
		g_BossFile.tracknum = mpGetTrackNumAtSlotIndex(slot);
	}
}

void mpEnableAllMultiTracks(void)
{
	s32 i;

	for (i = 0; i != 6; i++) {
		g_BossFile.multipletracknums[i] = 0xff;
	}
}

void mpDisableAllMultiTracks(void)
{
	s32 i;

	for (i = 0; i != 6; i++) {
		g_BossFile.multipletracknums[i] = 0;
	}
}

void mpRandomiseMultiTracks(void)
{
	s32 i;

	for (i = 0; i != 6; i++) {
		g_BossFile.multipletracknums[i] = random();
	}
}

void mpSetTrackToRandom(void)
{
	g_BossFile.tracknum = -1;
}

s32 mpGetCurrentTrackSlotNum(void)
{
	if (g_BossFile.tracknum < 0) {
		return g_BossFile.tracknum;
	}

	return mpGetTrackSlotIndex(g_BossFile.tracknum);
}

s32 mpChooseTrack(void)
{
	s32 i;
	s32 tracknum;

	if (mpGetUsingMultipleTunes()) {
		s32 numunlocked = mpGetNumUnlockedTracks();
		s32 numselected = 0;

		for (i = 0; i < numunlocked; i++) {
			if (mpIsMultiTrackSlotEnabled(i)) {
				numselected++;
			}
		}

		if (numselected == 0) {
			do {
				tracknum = mpGetTrackNumAtSlotIndex(random() % numunlocked);
			} while (tracknum == g_MpLockInfo.unk04);

			g_MpLockInfo.unk04 = tracknum;
			g_MusicLife60 = g_MpTracks[tracknum].duration * TICKS(60);

			return g_MpTracks[tracknum].musicnum;
		}

		do {
			s32 selectionindex = random() % numselected;
			s32 selectioncount = 0;
			tracknum = -1;

			for (i = 0; i < numunlocked; i++) {
				if (mpIsMultiTrackSlotEnabled(i)) {
					if (selectionindex == selectioncount) {
						tracknum = i;
					}

					selectioncount++;
				}
			}

			if (tracknum == -1) {
				g_MusicLife60 = g_MpTracks[0].duration * TICKS(60);
				return g_MpTracks[0].musicnum;
			}

			tracknum = mpGetTrackNumAtSlotIndex(tracknum);
		} while (numselected > 1 && tracknum == g_MpLockInfo.unk04);

		g_MpLockInfo.unk04 = tracknum;
		g_MusicLife60 = g_MpTracks[tracknum].duration * TICKS(60);

		return g_MpTracks[tracknum].musicnum;
	}

	tracknum = mpGetCurrentTrackSlotNum();

	if (tracknum < 0) {
		s32 numunlocked = mpGetNumUnlockedTracks();

		do {
			tracknum = mpGetTrackNumAtSlotIndex(random() % numunlocked);
		} while (tracknum == g_MpLockInfo.unk04);

		g_MpLockInfo.unk04 = tracknum;
		g_MusicLife60 = g_MpTracks[tracknum].duration * TICKS(60);
		return g_MpTracks[tracknum].musicnum;
	}

	tracknum = mpGetTrackNumAtSlotIndex(tracknum);
	g_MpLockInfo.unk04 = tracknum;
	g_MusicLife60 = g_MpTracks[tracknum].duration * TICKS(60);

	return g_MpTracks[tracknum].musicnum;
}

struct mpchrconfig *mpGetChrConfigBySlotNum(s32 slot)
{
	s32 count = 0;
	struct mpchrconfig *result = NULL;
	s32 i;

	for (i = 0; i < MAX_MPCHRS; i++) {
		if (g_MpSetup.chrslots & (1 << i)) {
			if (count == slot) {
				result = MPCHR(i);
				break;
			}

			count++;
		}
	}

	return result;
}

#if VERSION >= VERSION_NTSC_1_0
s32 mpGetChrIndexBySlotNum(s32 slot)
{
	s32 count = 0;
	s32 result = 0;
	s32 i;

	for (i = 0; i < MAX_MPCHRS; i++) {
		if (g_MpSetup.chrslots & (1 << i)) {
			if (count == slot) {
				result = i;
				break;
			}

			count++;
		}
	}

	return result;
}
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

u8 mpFindUnusedTeamNum(void)
{
	u8 teamnum = 0;
	bool available = false;
	s32 i;

	while (teamnum < 7 && !available) {
		available = true;

		for (i = 0; i < MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchrconfig *mpchr = MPCHR(i);

				if (mpchr->team == teamnum) {
					available = false;
				}
			}
		}

		if (!available) {
			teamnum++;
		}
	}

	if (teamnum > 7) {
		teamnum = 7;
	}

	return teamnum;
}

void mpCreateBotFromProfile(s32 botnum, u8 profilenum)
{
	s32 headnum = 0;
	u8 team = mpFindUnusedTeamNum();
	bool available = false;
	s32 i;

	g_BotConfigsArray[botnum].type = g_BotProfiles[profilenum].type;
	g_BotConfigsArray[botnum].difficulty = g_BotProfiles[profilenum].difficulty;

	for (i = 0; i < 4; i++) {
		g_MpSimulantDifficultiesPerNumPlayers[botnum][i] = g_BotConfigsArray[botnum].difficulty;
	}

	g_MpSetup.chrslots |= 1 << (botnum + 4);
	strcpy(g_BotConfigsArray[botnum].base.name, "Sim\n");
	g_BotConfigsArray[botnum].base.team = team;

	while (!available) {
		headnum = g_BotHeads[random() % ARRAYCOUNT(g_BotHeads)];
		available = true;

		for (i = 0; i < MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchrconfig *mpchr = MPCHR(i);

				if (mpchr->mpheadnum == headnum) {
					available = false;
				}
			}
		}
	}

	g_BotConfigsArray[botnum].base.mpheadnum = headnum;
	g_BotConfigsArray[botnum].base.mpbodynum = g_BotProfiles[profilenum].body;
}

void mpSetBotDifficulty(s32 botnum, s32 difficulty)
{
	s32 i;

	g_BotConfigsArray[botnum].difficulty = difficulty;

	for (i = 0; i < 4; i++) {
		g_MpSimulantDifficultiesPerNumPlayers[botnum][i] = g_BotConfigsArray[botnum].difficulty;
	}
}

/**
 * Return the first unused bot slot (0-7), or return 7 if all slots are full.
 *
 * This is used for the quick team feature.
 */
s32 mpGetSlotForNewBot(void)
{
	s32 i = 0;

	while (i < MAX_BOTS - 1 && g_MpSetup.chrslots & (1 << (i + 4))) {
		i++;
	}

	return i;
}

void mpRemoveSimulant(s32 index)
{
	g_MpSetup.chrslots &= ~(1 << (index + 4));
	g_BotConfigsArray[index].base.name[0] = '\0';
	func0f1881d4(index);
	mpGenerateBotNames();
}

bool mpHasSimulants(void)
{
	if ((g_MpSetup.chrslots & 0xfff0) != 0) {
		return true;
	}

	return false;
}

bool mpHasUnusedBotSlots(void)
{
	s32 numvacant = challengeIsFeatureUnlocked(MPFEATURE_8BOTS) ? MAX_BOTS : 4;
	s32 i;

	for (i = 4; i < MAX_MPCHRS; i++) {
		if (g_MpSetup.chrslots & (1 << i)) {
			numvacant--;
		}
	}

	if (numvacant > 0) {
		return true;
	}

	return false;
}

bool mpIsSimSlotEnabled(s32 slot)
{
	s32 numfree = MAX_BOTS;
	s32 i;

	if ((g_MpSetup.chrslots & (1 << (slot + 4))) == 0) {
		for (i = 0; i < MAX_BOTS; i++) {
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

s32 mpFindBotProfile(s32 type, s32 difficulty)
{
	s32 i;

	if (type == BOTTYPE_GENERAL) {
		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (g_BotProfiles[i].difficulty == difficulty) {
				break;
			}
		}
	} else {
		for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
			if (g_BotProfiles[i].type == type) {
				break;
			}
		}
	}

	if (i >= ARRAYCOUNT(g_BotProfiles)) {
		i = -1;
	}

	return i;
}

void mpGenerateBotNames(void)
{
	s32 counts[ARRAYCOUNT(g_BotProfiles)];
	s32 profilenum;
	s32 i;
	char name[16];

	for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
		counts[i] = 0;
	}

	// Count the number of bots using each profile (MeatSim, TurtleSim etc)
	for (i = 4; i < MAX_MPCHRS; i++) {
		if (g_MpSetup.chrslots & (1 << i)) {
			profilenum = mpFindBotProfile(g_BotConfigsArray[i - 4].type, g_BotConfigsArray[i - 4].difficulty);

			if (profilenum >= 0 && profilenum < ARRAYCOUNT(g_BotProfiles)) {
				counts[profilenum]++;
			}
		}
	}

	// Profiles with only one bot don't need to have to number appended to the
	// name, so mark those as -1. For profiles with multiple bots, reset them
	// to 0 because they'll be a counter for the final loop.
	for (i = 0; i < ARRAYCOUNT(g_BotProfiles); i++) {
		if (counts[i] <= 1) {
			counts[i] = -1;
		} else {
			counts[i] = 0;
		}
	}

	for (i = 4; i < MAX_MPCHRS; i++) {
		if (g_MpSetup.chrslots & (1 << i)) {
			profilenum = mpFindBotProfile(g_BotConfigsArray[i - 4].type, g_BotConfigsArray[i - 4].difficulty);

			if (profilenum >= 0 && profilenum < ARRAYCOUNT(g_BotProfiles)) {
				if (counts[profilenum] >= 0) {
					// Multiple bots using this profile - append the number
					counts[profilenum]++;
					sprintf(name, "%s:%d\n", langGet(g_BotProfiles[profilenum].name), counts[profilenum]);
					strcpy(g_BotConfigsArray[i - 4].base.name, name);
				} else {
					// One bots using this profile - just use the profile name
					sprintf(name, "%s\n", langGet(g_BotProfiles[profilenum].name));
					strcpy(g_BotConfigsArray[i - 4].base.name, name);
				}
			}
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b8b80[] = "Adding GBCHead to load to slot %d: guid is %x-%x, player is %d\n";
const char var7f1b8bc0[] = "PakId for player %d: %d\n";
const char var7f1b8bdc[] = "Save Player Result: %d   New GUID: %x\n";
const char var7f1b8c04[] = "PakId for player %d: %d\n";
const char var7f1b8c20[] = "Load Player - Result: %d\n";
#endif

s32 mpPlayerGetIndex(struct chrdata *chr)
{
	s32 i;

	for (i = 0; i < g_MpNumChrs; i++) {
		if (g_MpAllChrPtrs[i] == chr) {
			return i;
		}
	}

	return -1;
}

struct chrdata *mpGetChrFromPlayerIndex(s32 index)
{
	if (index >= 0 && index < g_MpNumChrs) {
		return g_MpAllChrPtrs[index];
	}

	return NULL;
}

s32 func0f18d074(s32 index)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (&g_PlayerConfigsArray[i].base == g_MpAllChrConfigPtrs[index]) {
			return i;
		}
	}

	for (i = 0; i < MAX_BOTS; i++) {
		if (&g_BotConfigsArray[i].base == g_MpAllChrConfigPtrs[index]) {
			return i + 4;
		}
	}

	return -1;
}

s32 func0f18d0e8(s32 arg0)
{
	s32 i;

	if (arg0 < 4) {
		for (i = 0; i < g_MpNumChrs; i++) {
			if (g_MpAllChrConfigPtrs[i] == &g_PlayerConfigsArray[arg0].base) {
				return i;
			}
		}
	} else {
		for (i = 0; i < g_MpNumChrs; i++) {
			if (g_MpAllChrConfigPtrs[i] == &g_BotConfigsArray[arg0 - 4].base) {
				return i;
			}
		}
	}

	return -1;
}

void mpplayerfileLoadGunFuncs(struct savebuffer *buffer, s32 playernum)
{
	s32 bitsremaining = 35;
	s32 i = 0;

	while (bitsremaining > 0) {
		s32 numbits = bitsremaining;

		if (numbits > 8) {
			numbits = 8;
		}

		g_PlayerConfigsArray[playernum].gunfuncs[i] = savebufferReadBits(buffer, numbits);

		bitsremaining -= 8;
		i++;
	}
}

void mpplayerfileSaveGunFuncs(struct savebuffer *buffer, s32 playernum)
{
	s32 bitsremaining = 35;
	s32 i = 0;

	while (bitsremaining > 0) {
		s32 numbits = bitsremaining;

		if (numbits > 8) {
			numbits = 8;
		}

		savebufferOr(buffer, g_PlayerConfigsArray[playernum].gunfuncs[i], numbits);

		bitsremaining -= 8;
		i++;
	}
}

void mpplayerfileLoadWad(s32 playernum, struct savebuffer *buffer, s32 arg2)
{
	struct fileguid guid;
	u32 stack;
	s32 i;
	s32 j;

	savebufferReadString(buffer, g_PlayerConfigsArray[playernum].base.name, 1);
	g_PlayerConfigsArray[playernum].time = savebufferReadBits(buffer, 28);

	if (arg2 != 0) {
		g_PlayerConfigsArray[playernum].base.mpheadnum = savebufferReadBits(buffer, 7);
		g_PlayerConfigsArray[playernum].base.mpbodynum = savebufferReadBits(buffer, 7);

		savebufferReadGuid(buffer, &guid);

		if (g_PlayerConfigsArray[playernum].base.mpheadnum >= mpGetNumHeads2()) {
			if (guid.fileid != 0 && guid.deviceserial != 0) {
				if (g_MenuData.unk668 < 11) {
					g_MenuData.unk668++;
					g_MenuData.unk5d8[g_MenuData.unk668].fileguid.fileid = guid.fileid;
					g_MenuData.unk5d8[g_MenuData.unk668].fileguid.deviceserial = guid.deviceserial;
					g_MenuData.unk5d8[g_MenuData.unk668].unk08 = g_MpPlayerNum;
					g_MenuData.unk5d8[g_MenuData.unk668].unk09 = g_MpPlayerNum;
				}
			} else {
				g_PlayerConfigsArray[playernum].base.mpheadnum = MPHEAD_DARK_COMBAT;
			}
		}
	} else {
		savebufferReadBits(buffer, 7);
		savebufferReadBits(buffer, 7);
		savebufferReadGuid(buffer, &guid);
	}

	g_PlayerConfigsArray[playernum].base.displayoptions = savebufferReadBits(buffer, 8);
	g_PlayerConfigsArray[playernum].kills = savebufferReadBits(buffer, 20);
	g_PlayerConfigsArray[playernum].deaths = savebufferReadBits(buffer, 20);
	g_PlayerConfigsArray[playernum].gamesplayed = savebufferReadBits(buffer, 19);
	g_PlayerConfigsArray[playernum].gameswon = savebufferReadBits(buffer, 19);
	g_PlayerConfigsArray[playernum].gameslost = savebufferReadBits(buffer, 19);
	g_PlayerConfigsArray[playernum].distance = savebufferReadBits(buffer, 25);
	g_PlayerConfigsArray[playernum].accuracy = savebufferReadBits(buffer, 10);
	g_PlayerConfigsArray[playernum].damagedealt = savebufferReadBits(buffer, 26);
	g_PlayerConfigsArray[playernum].painreceived = savebufferReadBits(buffer, 26);
	g_PlayerConfigsArray[playernum].headshots = savebufferReadBits(buffer, 20);
	g_PlayerConfigsArray[playernum].ammoused = savebufferReadBits(buffer, 30);
	g_PlayerConfigsArray[playernum].accuracymedals = savebufferReadBits(buffer, 18);
	g_PlayerConfigsArray[playernum].headshotmedals = savebufferReadBits(buffer, 18);
	g_PlayerConfigsArray[playernum].killmastermedals = savebufferReadBits(buffer, 18);
	g_PlayerConfigsArray[playernum].survivormedals = savebufferReadBits(buffer, 16);
	g_PlayerConfigsArray[playernum].controlmode = savebufferReadBits(buffer, 2);
	g_PlayerConfigsArray[playernum].options = savebufferReadBits(buffer, 12);

	for (i = 0; i < 30; i++) {
		for (j = 1; j < 5; j++) {
			challengeSetCompletedByPlayerWithNumPlayers(playernum, i, j, savebufferReadBits(buffer, 1));
		}
	}

	challengeDetermineUnlockedFeatures();
	mpCalculatePlayerTitle(&g_PlayerConfigsArray[playernum]);
	mpplayerfileLoadGunFuncs(buffer, playernum);
}

void mpplayerfileSaveWad(s32 playernum, struct savebuffer *buffer)
{
	s32 i;
	s32 j;
	u32 stack;

	func0f0d55a4(buffer, g_PlayerConfigsArray[playernum].base.name);

	if (g_PlayerConfigsArray[playernum].time > 0x0fffffff) { // over 3106 days
		g_PlayerConfigsArray[playernum].time = 0x0fffffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].time, 28);
	savebufferOr(buffer, g_PlayerConfigsArray[playernum].base.mpheadnum, 7);
	savebufferOr(buffer, g_PlayerConfigsArray[playernum].base.mpbodynum, 7);

	{
		struct fileguid guid;
		guid.deviceserial = 0;
		guid.fileid = 0;
		savebufferWriteGuid(buffer, &guid);
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].base.displayoptions, 8);

	if (g_PlayerConfigsArray[playernum].kills > 0xfffff) { // 1,048,575
		g_PlayerConfigsArray[playernum].kills = 0xfffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].kills, 20);

	if (g_PlayerConfigsArray[playernum].deaths > 0xfffff) { // 1,048,575
		g_PlayerConfigsArray[playernum].deaths = 0xfffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].deaths, 20);

	if (g_PlayerConfigsArray[playernum].gamesplayed > 0x7ffff) { // 524,287
		g_PlayerConfigsArray[playernum].gamesplayed = 0x7ffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].gamesplayed, 19);

	if (g_PlayerConfigsArray[playernum].gameswon > 0x7ffff) { // 524,287
		g_PlayerConfigsArray[playernum].gameswon = 0x7ffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].gameswon, 19);

	if (g_PlayerConfigsArray[playernum].gameslost > 0x7ffff) { // 524,287
		g_PlayerConfigsArray[playernum].gameslost = 0x7ffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].gameslost, 19);

	if (g_PlayerConfigsArray[playernum].distance > 0x1ffffff) { // 33,554,431
		g_PlayerConfigsArray[playernum].distance = 0x1ffffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].distance, 25);

	if (g_PlayerConfigsArray[playernum].accuracy > 0x3ff) { // 1023
		g_PlayerConfigsArray[playernum].accuracy = 0x3ff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].accuracy, 10);

	if (g_PlayerConfigsArray[playernum].damagedealt > 0x3ffffff) { // 67,108,863
		g_PlayerConfigsArray[playernum].damagedealt = 0x3ffffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].damagedealt, 26);

	if (g_PlayerConfigsArray[playernum].painreceived > 0x3ffffff) { // 67,108,863
		g_PlayerConfigsArray[playernum].painreceived = 0x3ffffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].painreceived, 26);

	if (g_PlayerConfigsArray[playernum].headshots > 0xfffff) { // 1,048,575
		g_PlayerConfigsArray[playernum].headshots = 0xfffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].headshots, 20);

	if (g_PlayerConfigsArray[playernum].ammoused > 0x3fffffff) { // 1,073,741,823
		g_PlayerConfigsArray[playernum].ammoused = 0x3fffffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].ammoused, 30);

	if (g_PlayerConfigsArray[playernum].accuracymedals > 0x3ffff) { // 262,143
		g_PlayerConfigsArray[playernum].accuracymedals = 0x3ffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].accuracymedals, 18);

	if (g_PlayerConfigsArray[playernum].headshotmedals > 0x3ffff) { // 262,143
		g_PlayerConfigsArray[playernum].headshotmedals = 0x3ffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].headshotmedals, 18);

	if (g_PlayerConfigsArray[playernum].killmastermedals > 0x3ffff) { // 262,143
		g_PlayerConfigsArray[playernum].killmastermedals = 0x3ffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].killmastermedals, 18);

	if (g_PlayerConfigsArray[playernum].survivormedals > 0xffff) { // 65,535
		g_PlayerConfigsArray[playernum].survivormedals = 0xffff;
	}

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].survivormedals, 16);

	savebufferOr(buffer, g_PlayerConfigsArray[playernum].controlmode, 2);
	savebufferOr(buffer, g_PlayerConfigsArray[playernum].options, 12);

	for (i = 0; i < 30; i++) {
		for (j = 1; j < 5; j++) {
			savebufferOr(buffer, challengeIsCompletedByPlayerWithNumPlayers(playernum, i, j), 1);
		}
	}

	mpplayerfileSaveGunFuncs(buffer, playernum);
}

void mpplayerfileGetOverview(char *arg0, char *name, u32 *playtime)
{
	struct savebuffer buffer;

	func0f0d5484(&buffer, arg0, 15);

	savebufferReadString(&buffer, name, 0);
	*playtime = savebufferReadBits(&buffer, 28);
}

s32 mpplayerfileSave(s32 playernum, s32 device, s32 fileid, u16 deviceserial)
{
	s32 ret;
	s32 newfileid;
	struct savebuffer buffer;

	if (device >= 0) {
		savebufferClear(&buffer);
		mpplayerfileSaveWad(playernum, &buffer);
		func0f0d54c4(&buffer);

		var80075bd0[2] = true;

		ret = pakSaveAtGuid(device, fileid, PAKFILETYPE_MPPLAYER, buffer.bytes, &newfileid, 0);

		if (ret == 0) {
			g_PlayerConfigsArray[playernum].fileguid.fileid = newfileid;
			g_PlayerConfigsArray[playernum].fileguid.deviceserial = deviceserial;
			return 0;
		}

		g_FilemgrLastPakError = ret;
		return -1;
	}

	return -1;
}

s32 mpplayerfileLoad(s32 playernum, s32 device, s32 fileid, u16 deviceserial)
{
	s32 ret;
	struct savebuffer buffer;

	if (device >= 0) {
		savebufferClear(&buffer);

		ret = pakReadBodyAtGuid(device, fileid, buffer.bytes, 0);

		if (ret == 0) {
			g_PlayerConfigsArray[playernum].fileguid.fileid = fileid;
			g_PlayerConfigsArray[playernum].fileguid.deviceserial = deviceserial;

			mpplayerfileLoadWad(playernum, &buffer, 1);
			func0f0d54c4(&buffer);

			g_PlayerConfigsArray[playernum].handicap = 0x80;
			return 0;
		}

		g_FilemgrLastPakError = ret;
		return -1;
	}

	return -1;
}

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
		if (!challengeIsFeatureUnlocked(g_MpPresets[presetnum].requirefeatures[i]) &&
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

void mpApplyConfig(struct mpconfigfull *config)
{
	s32 i;
	s32 j;
	u16 chrslots;

	g_MpSetup.scenario = config->config.setup.scenario;

#if VERSION >= VERSION_PAL_FINAL
	chrslots = g_MpSetup.chrslots;
#endif

	scenarioInit();

	g_MpSetup = config->config.setup;

#if VERSION >= VERSION_PAL_FINAL
	g_MpSetup.chrslots = chrslots;
#endif

	for (i = 0; i < MAX_BOTS; i++) {
		g_BotConfigsArray[i].type = config->config.simulants[i].type;

		for (j = 0; j < 4; j++) {
			g_MpSimulantDifficultiesPerNumPlayers[i][j] = config->config.simulants[i].difficulties[j];
		}

		g_BotConfigsArray[i].difficulty = g_MpSimulantDifficultiesPerNumPlayers[i][0];

#if VERSION >= VERSION_NTSC_1_0
		if (IS4MB()) {
			// "ShockSim:%d"
			sprintf(g_BotConfigsArray[i].base.name, langGet(L_MPWEAPONS_241), i + 1);
		} else {
			strcpy(g_BotConfigsArray[i].base.name, config->strings.aibotnames[i]);
		}
#else
		strcpy(g_BotConfigsArray[i].base.name, config->strings.aibotnames[i]);
#endif

		g_BotConfigsArray[i].base.mpheadnum = config->config.simulants[i].mpheadnum;
		g_BotConfigsArray[i].base.mpbodynum = config->config.simulants[i].mpbodynum;
		g_BotConfigsArray[i].base.team = config->config.simulants[i].team;
	}

	if (!challengeIsFeatureUnlocked(MPFEATURE_WEAPON_SHIELD)) {
		for (i = 0; i < 6; i++) {
			if (g_MpSetup.weapons[i] == MPWEAPON_SHIELD) {
				g_MpSetup.weapons[i] = MPWEAPON_NONE;
			}
		}
	}

	func0f18913c();
	challengeRemoveForceUnlocks();
}

void mp0f18dec4(s32 slot)
{
	struct mpconfigfull *config;
	u8 buffer[0x1ca];
	s32 confignum = 0;
	u32 i;

	for (i = 0; i < 14; i++) {
		if (mpIsPresetUnlocked(i)) {
			if (slot == 0) {
				confignum = g_MpPresets[i].confignum;
				break;
			}

			slot--;
		}
	}

	config = challengeLoadConfig(confignum, buffer, sizeof(buffer));

	mpApplyConfig(config);

#if VERSION >= VERSION_JPN_FINAL
	g_MpSetup.chrslots &= 0x0f;

	for (i = 0; i < MAX_BOTS; i++) {
		if (g_BotConfigsArray[i].difficulty != BOTDIFF_DISABLED) {
			g_MpSetup.chrslots |= 1 << (i + 4);
		}
	}
#endif
}

void mpsetupfileLoadWad(struct savebuffer *buffer)
{
	s32 i;
	s32 j;

	savebufferReadString(buffer, g_MpSetup.name, false);
	savebufferReadBits(buffer, 4);

	g_MpSetup.stagenum = savebufferReadBits(buffer, 7);
	g_MpSetup.scenario = savebufferReadBits(buffer, 3);

	scenarioInit();
	scenarioReadSave(buffer);

	g_MpSetup.options = savebufferReadBits(buffer, 21);
	g_MpSetup.chrslots &= 0x000f;

	for (i = 0; i < MAX_BOTS; i++) {
		g_BotConfigsArray[i].base.name[0] = '\0';
		g_BotConfigsArray[i].type = savebufferReadBits(buffer, 5);
		g_BotConfigsArray[i].difficulty = savebufferReadBits(buffer, 3);

		for (j = 0; j < 4; j++) {
			g_MpSimulantDifficultiesPerNumPlayers[i][j] = g_BotConfigsArray[i].difficulty;
		}

		if (g_BotConfigsArray[i].difficulty != BOTDIFF_DISABLED) {
			g_MpSetup.chrslots |= 1 << (i + 4);
		}

		g_BotConfigsArray[i].base.mpheadnum = savebufferReadBits(buffer, 7);
		g_BotConfigsArray[i].base.mpbodynum = savebufferReadBits(buffer, 7);
		g_BotConfigsArray[i].base.team = savebufferReadBits(buffer, 3);
	}

	mpGenerateBotNames();

	for (i = 0; i < 6; i++) {
		g_MpSetup.weapons[i] = savebufferReadBits(buffer, 7);
	}

	func0f18913c();

	g_MpSetup.timelimit = savebufferReadBits(buffer, 6);
	g_MpSetup.scorelimit = savebufferReadBits(buffer, 7);
	g_MpSetup.teamscorelimit = savebufferReadBits(buffer, 9);

	for (i = 0; i < 4; i++) {
		g_PlayerConfigsArray[i].base.team = savebufferReadBits(buffer, 3);
	}

	challengeForceUnlockBotFeatures();
}

void mpsetupfileSaveWad(struct savebuffer *buffer)
{
	s32 numsims = 0;
	s32 mpbodynum;
	s32 i;

	func0f0d55a4(buffer, g_MpSetup.name);

	for (i = 0; i < MAX_BOTS; i++) {
		if (g_MpSetup.chrslots & (1 << (i + 4))) {
			numsims++;
		}
	}

	savebufferOr(buffer, numsims, 4);
	savebufferOr(buffer, g_MpSetup.stagenum, 7);
	savebufferOr(buffer, g_MpSetup.scenario, 3);

	scenarioWriteSave(buffer);

	savebufferOr(buffer, g_MpSetup.options, 21);

	for (i = 0; i < MAX_BOTS; i++) {
		savebufferOr(buffer, g_BotConfigsArray[i].type, 5);

		if (g_MpSetup.chrslots & (1 << (i + 4))) {
			savebufferOr(buffer, g_BotConfigsArray[i].difficulty, 3);
		} else {
			savebufferOr(buffer, BOTDIFF_DISABLED, 3);
		}

		savebufferOr(buffer, g_BotConfigsArray[i].base.mpheadnum, 7);

		if (g_BotConfigsArray[i].base.mpbodynum == 0xff) {
			s32 profilenum = mpFindBotProfile(g_BotConfigsArray[i].type, g_BotConfigsArray[i].difficulty);

			if (profilenum < 0 || profilenum >= ARRAYCOUNT(g_BotProfiles)) {
				profilenum = 0;
			}

			mpbodynum = g_BotProfiles[profilenum].body;
		} else {
			mpbodynum = g_BotConfigsArray[i].base.mpbodynum;
		}

		savebufferOr(buffer, mpbodynum, 7);
		savebufferOr(buffer, g_BotConfigsArray[i].base.team, 3);
	}

	for (i = 0; i < 6; i++) {
		savebufferOr(buffer, g_MpSetup.weapons[i], 7);
	}

	savebufferOr(buffer, g_MpSetup.timelimit, 6);
	savebufferOr(buffer, g_MpSetup.scorelimit, 7);
	savebufferOr(buffer, g_MpSetup.teamscorelimit, 9);

	for (i = 0; i < 4; i++) {
		savebufferOr(buffer, g_PlayerConfigsArray[i].base.team, 3);
	}
}

void mpsetupfileGetOverview(char *arg0, char *filename, u16 *numsims, u16 *stagenum, u16 *scenarionum)
{
	struct savebuffer buffer;

	func0f0d5484(&buffer, arg0, 15);

	savebufferReadString(&buffer, filename, 0);

	*numsims = savebufferReadBits(&buffer, 4);
	*stagenum = savebufferReadBits(&buffer, 7);
	*scenarionum = savebufferReadBits(&buffer, 3);
}

s32 mpsetupfileSave(s32 device, s32 fileid, u16 deviceserial)
{
	s32 ret;
	s32 newfileid;
	struct savebuffer buffer;

	if (device >= 0) {
		savebufferClear(&buffer);
		mpsetupfileSaveWad(&buffer);
		func0f0d54c4(&buffer);

		ret = pakSaveAtGuid(device, fileid, PAKFILETYPE_MPSETUP, buffer.bytes, &newfileid, 0);
		var80075bd0[1] = true;

		if (ret == 0) {
			g_MpSetup.fileguid.fileid = newfileid;
			g_MpSetup.fileguid.deviceserial = deviceserial;
			return 0;
		}

		g_FilemgrLastPakError = ret;
		return -1;
	}

	return -1;
}

s32 mpsetupfileLoad(s32 device, s32 fileid, u16 deviceserial)
{
	s32 ret;
	struct savebuffer buffer;

	if (device >= 0) {
		savebufferClear(&buffer);
		ret = pakReadBodyAtGuid(device, fileid, buffer.bytes, 0);

		if (ret == 0) {
			g_MpSetup.fileguid.fileid = fileid;
			g_MpSetup.fileguid.deviceserial = deviceserial;

			mpsetupfileLoadWad(&buffer);
			func0f0d54c4(&buffer);

			return 0;
		}

		g_FilemgrLastPakError = ret;

		return -1;
	}

	return -1;
}

void func0f18e558(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var800acc28); i++) {
		var800acc28[i] = NULL;
	}
}

struct modelfiledata *func0f18e57c(s32 index, s32 *headnum)
{
	return var800acc28[index];
}
