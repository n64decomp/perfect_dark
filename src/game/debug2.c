#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/debug.h"
#include "lib/rmon.h"
#include "lib/vi.h"
#include "lib/vm.h"
#include "bss.h"
#include "data.h"
#include "types.h"

#define DEBUGMENU_MAIN     0
#define DEBUGMENU_CUTSCENE 1

#define DEBUGOPT_ALLLEVELS     13
#define DEBUGOPT_ALLTRAINING   29
#define DEBUGOPT_PROPS         32
#define DEBUGOPT_PADS          40
#define DEBUGOPT_44            44
#define DEBUGOPT_TILES         39
#define DEBUGOPT_CHRSTATS      65
#define DEBUGOPT_ALLCHALLENGES 67
#define DEBUGOPT_VMSTATS       69
#define DEBUGOPT_MEMINFO       70
#define DEBUGOPT_ALLBUDDIES    94
#define DEBUGOPT_SETCOMPLETE   95

#if VERSION == VERSION_PAL_BETA
#define DEBUGOPT_MANPOS        102
#else
#define DEBUGOPT_MANPOS        101
#endif

#if VERSION == VERSION_PAL_BETA
s32 var80075d60 = 2;
s32 var80075d64 = 2;
s32 var80075d68 = 2;
s32 var800786f4nb = 2;
#endif

s32 g_DebugMenuOffsets[] = {
	15,
	30,
	45,
	59,
	72,
	84,
#if VERSION == VERSION_PAL_BETA
	96,
	109,
#else
	95,
	108,
#endif
	-1,
};

s32 g_DebugMenuPositions[][2] = {
	{ 8, 2  },
	{ 8, 3  },
	{ 8, 4  },
	{ 8, 5  },
	{ 8, 6  },
	{ 8, 7  },
	{ 8, 8  },
	{ 8, 9  },
	{ 8, 10 },
	{ 8, 11 },
	{ 8, 12 },
	{ 8, 13 },
	{ 8, 14 },
	{ 8, 15 },
	{ 8, 16 },

	{ 25, 2  },
	{ 25, 3  },
	{ 25, 4  },
	{ 25, 5  },
	{ 25, 6  },
	{ 25, 7  },
	{ 25, 8  },
	{ 25, 9  },
	{ 25, 10 },
	{ 25, 11 },
	{ 25, 12 },
	{ 25, 13 },
	{ 25, 14 },
	{ 25, 15 },
	{ 25, 16 },

	{ 40, 2  },
	{ 40, 3  },
	{ 40, 4  },
	{ 40, 5  },
	{ 40, 6  },
	{ 40, 7  },
	{ 40, 8  },
	{ 40, 9  },
	{ 40, 10 },
	{ 40, 11 },
	{ 40, 12 },
	{ 40, 13 },
	{ 40, 14 },
	{ 40, 15 },
	{ 40, 16 },

	{ 57, 2  },
	{ 57, 3  },
	{ 57, 4  },
	{ 57, 5  },
	{ 57, 6  },
	{ 57, 7  },
	{ 57, 8  },
	{ 57, 9  },
	{ 57, 10 },
	{ 57, 11 },
	{ 57, 12 },
	{ 57, 13 },
	{ 57, 14 },
	{ 57, 15 },

	{ 8, 18 },
	{ 8, 19 },
	{ 8, 20 },
	{ 8, 21 },
	{ 8, 22 },
	{ 8, 23 },
	{ 8, 24 },
	{ 8, 25 },
	{ 8, 26 },
	{ 8, 27 },
	{ 8, 28 },
	{ 8, 29 },
	{ 8, 30 },

	{ 25, 18 },
	{ 25, 19 },
	{ 25, 20 },
	{ 25, 21 },
	{ 25, 22 },
	{ 25, 23 },
	{ 25, 24 },
	{ 25, 25 },
	{ 25, 26 },
	{ 25, 27 },
	{ 25, 28 },
	{ 25, 29 },

	{ 40, 18 },
	{ 40, 19 },
	{ 40, 20 },
	{ 40, 21 },
	{ 40, 22 },
	{ 40, 23 },
	{ 40, 24 },
	{ 40, 25 },
	{ 40, 26 },
	{ 40, 27 },
	{ 40, 28 },
#if VERSION == VERSION_PAL_BETA
	{ 40, 29 },
#endif

	{ 57, 18 },
	{ 57, 19 },
	{ 57, 20 },
	{ 57, 21 },
	{ 57, 22 },
	{ 57, 23 },
	{ 57, 24 },
	{ 57, 25 },
	{ 57, 26 },
	{ 57, 27 },
	{ 57, 28 },
	{ 57, 29 },
	{ 57, 30 },
};

// ntsc-beta rodata at 7f1af170
char *g_DebugMenuLabels[] = {
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"All Levels",
	"-",

	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"All Training",

	"-",
	"-",
#if VERSION == VERSION_NTSC_BETA
	"props",
#else
	"-",
#endif
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
#if VERSION == VERSION_NTSC_BETA
	"tiles",
	"pads",
#else
	"-",
	"-",
#endif
	"-",
	"-",
	"-",
	"-",

	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",

	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
#if VERSION == VERSION_NTSC_BETA
	"chr stats",
#else
	"-",
#endif
	"-",
	"all challenges",
	"-",
	"VM Stats",
	"Mem Info",
	"-",

	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",

	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"all buddies",
#if VERSION == VERSION_PAL_BETA
	"set complete",
#endif

	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
	"testing man pos",
	"-",
	"-",
	"-",
	"-",
	"-",
	"-",
};

s32 g_DebugCutsceneOffsets[] = {
	0, -1,
};

s32 g_DebugCutscenePositions[][2] = {
	{ 8, 2  },
	{ 8, 3  },
	{ 8, 4  },
	{ 8, 5  },
	{ 8, 6  },
	{ 8, 7  },
	{ 8, 8  },
	{ 8, 9  },
	{ 8, 10 },
	{ 8, 11 },
};

char *g_DebugCutsceneLabelPtrs[10];
char g_DebugCutsceneLabelBuffers[10][20];
u32 var800a7950nb;

s32 g_DebugCurMenu = DEBUGMENU_MAIN;
s32 g_DebugSelectedOptionsByMenu[2] = {0, 0};

#if VERSION == VERSION_NTSC_BETA
s32 var80075d60 = 2;
s32 var80075d64 = 2;
s32 var80075d68 = 2;
s32 var800786f4nb = 2;
#endif

s32 var800786f8nb = 0;
bool g_DebugRenderBg = true;
bool g_DebugRenderProps = true;
s32 var80078704nb = 1;
s32 var80078708nb = 0;
bool g_DebugRoomState = false;
s32 var80078710nb = 0;
s32 var80078714nb = 0;
s32 var80078718nb = 0;
s32 var8007871cnb = 0;
bool g_DebugLineMode = false;
s32 var80078724nb = 0;
s32 var80078728nb = 0;
s32 var8007872cnb = 0;
bool g_DebugManPos = false;
bool g_DebugTurboMode = false;
bool g_DebugObjectives = false;
bool g_DebugZBufferDisabled = false;
s32 var80078740nb = 0;
s32 var80078744nb = 0;
s32 var80078748nb = 0;
s32 var8007874cnb = 0;
s32 var80078750nb = 0;
s32 var80078754nb = 0;
s32 var80078758nb = 0;
s32 var8007875cnb = 0;
s32 var80078760nb = 0;
s32 g_DebugSlowMotion = SLOWMOTION_OFF;
s32 var80078768nb = 0;
s32 g_DebugTiles = 0;
s32 g_DebugPads = 0;
s32 var80078774nb = 0;
s32 var80078778nb = 0;
s32 var8007877cnb = 0;
s32 var80078780nb = 0;
s32 var80078784nb = 0;
s32 var80078788nb = 0;
s32 var8007878cnb = 0;
s32 var80078790nb = 0;
bool g_DebugFootsteps = true;
bool g_DebugAllChallenges = false;
bool g_DebugAllBuddies = false;
#if VERSION == VERSION_PAL_BETA
bool g_DebugSetComplete = false;
#endif
bool g_DebugAllTraining = false;
s32 var800787a4nb = 0;
s32 var800787a8nb = 0;
bool g_DebugMemInfo = false;
s32 var800787b0nb = 0;
s32 var800787b4nb = 0;
s32 var800787b8nb = 0;
s32 var800787bcnb = 0;
s32 var800787c0nb = 0;
s32 var800787c4nb = 1;
s32 var800787c8nb = 0;
s32 var800787ccnb = 0;
s32 var800787d0nb = 0;
s32 var800787d4nb = 0;
s32 var800787d8nb = 0;
s32 var800787dcnb = 0;
s32 var800787e0nb = 0;
bool g_DebugChrStats = false;
s32 var800787e8nb = 0;
s32 var800787ecnb = 0;
s32 var800787f0nb = 0;
u32 var800787f4nb = 0x80500000;
u32 var800787f8nb = 0x00040000;
u32 var800787fcnb = 0x7f000000;
u32 var80078800nb = 0x7f100000;
u32 var80078804nb = 0x80600000;
u32 var80078808nb = 0x00040000;
u32 var8007880cnb = 0x70000000;
u32 var80078810nb = 0x70100000;
s32 g_DebugScreenshotRgb = 0;
s32 g_DebugScreenshotJpg = 0;
bool g_DebugIsMenuOpen = false;

u32 var80078820nb = 0;
u32 var80078824nb = 0;
u32 var80078828nb = 0;
u32 var8007882cnb = 0;
u32 var80078830nb = 0;
u32 var80078834nb = 0xbf800000;
u32 var80078838nb = 0;
u32 var8007883cnb = 0x3f800000;
u32 var80078840nb = 0;
u32 var80078844nb = 0;
u32 var80078848nb = 0x3f800000;
u32 var8007884cnb = 0;
u32 var80078850nb = 0;
u32 var80078854nb = 0x3f800000;
u32 var80078858nb = 0;
u32 var8007885cnb = 0;
u32 var80078860nb = 0;
u32 var80078864nb = 0;
u32 var80078868nb = 0;
u32 var8007886cnb = 0;
u32 var80078870nb = 0;
u32 var80078874nb = 0;
u32 var80078878nb = 0x3f800000;

void debugUpdateMenu(void)
{
	s32 i;

	if (g_DebugCurMenu == DEBUGMENU_MAIN) {
		dmenuSetMenu(g_DebugMenuLabels, g_DebugMenuPositions, g_DebugMenuOffsets);
	} else if (g_DebugCurMenu == DEBUGMENU_CUTSCENE) {
		for (i = 0; i < 10; i++) {
			g_DebugCutsceneLabelPtrs[i] = g_DebugCutsceneLabelBuffers[i];
		}

		g_DebugCutsceneOffsets[0] = 0;

		strcpy(g_DebugCutsceneLabelPtrs[0], "main");
		g_DebugCutsceneOffsets[0]++;

		for (i = 0; ; i++) {
			if (ailistFindById(0xc00 + i) == NULL) {
				break;
			}

			sprintf(g_DebugCutsceneLabelPtrs[i + 1], "scene %d", i);
			g_DebugCutsceneOffsets[0]++;
		}

		dmenuSetMenu(g_DebugCutsceneLabelPtrs, g_DebugCutscenePositions, g_DebugCutsceneOffsets);
	}

	dmenuSetSelectedOption(g_DebugSelectedOptionsByMenu[g_DebugCurMenu]);
}

void debugSaveSelectedOption(void)
{
	g_DebugSelectedOptionsByMenu[g_DebugCurMenu] = dmenuGetSelectedOption();
}

void debug0f1193e4nb(void)
{
	// empty
}

void debug0f1193ecnb(void)
{
	// empty
}

void debug0f1193f4nb(void)
{
	var80075d60 = var80075d64 = var800786f4nb = 2;
}

void debug0f11941cnb(void)
{
	rmon0002fa30(&var800787f4nb, 2);
	rmon0002fa38(250);
}

void debug0f11944cnb(void)
{
	rmon0002fa40();
}

bool debugProcessInput(s8 stickx, s8 sticky, u16 buttons, u16 buttonsthisframe)
{
	s32 i;
	s32 prev;
	s32 tmp = 3;

	debugUpdateMenu();

	if (g_DebugScreenshotRgb) {
		prev = g_DebugScreenshotRgb++;

		if (tmp == prev) {
			viGrabRgb32();
			g_DebugScreenshotRgb = 0;
			viSet16Bit();
			osViBlack(false);
		}
	}

	if (g_DebugScreenshotJpg) {
		prev = g_DebugScreenshotJpg++;

		if (tmp == prev) {
			viGrabJpg32();
			g_DebugScreenshotJpg = 0;
			viSet16Bit();
			osViBlack(false);
		}
	}

	if (!g_DebugIsMenuOpen) {
		tmp = (buttons & U_CBUTTONS) && (buttons & D_CBUTTONS);
		g_DebugIsMenuOpen = tmp;
		return tmp;
	}

	if (var80075d68 != -2) {
		var800786f4nb = var80075d68;
		var80075d68 = -2;
	}

	if (buttonsthisframe & L_JPAD) {
		dmenuNavigateLeft();
		var80075d68 = -2;
	}

	if (buttonsthisframe & R_JPAD) {
		dmenuNavigateRight();
		var80075d68 = -2;
	}

	if (buttonsthisframe & U_JPAD) {
		dmenuNavigateUp();
		var80075d68 = -2;
	}

	if (buttonsthisframe & D_JPAD) {
		dmenuNavigateDown();
		var80075d68 = -2;
	}

	if (buttonsthisframe & (A_BUTTON | START_BUTTON)) {
		if (g_DebugCurMenu == DEBUGMENU_CUTSCENE) {
			if (dmenuGetSelectedOption() == 0) {
				// Selected "main" from cutscene menu
				g_DebugCurMenu = DEBUGMENU_MAIN;
				dhudReset();
				debugUpdateMenu();
			} else {
				cutsceneStart(0xc00 + dmenuGetSelectedOption() - 1);
			}
		} else if (g_DebugCurMenu == DEBUGMENU_MAIN) {
			switch (dmenuGetSelectedOption()) {
#if VERSION == VERSION_PAL_BETA
			case DEBUGOPT_MANPOS:
				g_DebugManPos ^= 1;
				break;
			case DEBUGOPT_ALLBUDDIES:
				g_DebugAllBuddies ^= 1;
				break;
			case DEBUGOPT_SETCOMPLETE:
				g_DebugSetComplete ^= 1;
				break;
			case DEBUGOPT_VMSTATS:
				g_VmShowStats ^= 1;
				break;
			case DEBUGOPT_MEMINFO:
				g_DebugMemInfo ^= 1;
				break;
			case DEBUGOPT_ALLLEVELS:
				for (i = 0; i < 21; i++) {
					for (tmp = 0; tmp < 3; tmp++) {
						g_GameFile.besttimes[i][tmp] = 7;
					}
				}

				g_AltTitleUnlocked = true;
				break;
			case DEBUGOPT_ALLCHALLENGES:
				g_DebugAllChallenges ^= 1;
				mpDetermineUnlockedFeatures();
				break;
			case DEBUGOPT_ALLTRAINING:
				g_DebugAllTraining ^= 1;

				for (i = 0; i < ARRAYCOUNT(g_GameFile.firingrangescores); i++) {
					g_GameFile.firingrangescores[i] = 0xff;
				}

				gamefileSetFlag(GAMEFILEFLAG_CI_CLOAK_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_DISGUISE_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_XRAY_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_IR_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_RTRACKER_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_DOORDECODER_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_NIGHTVISION_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_CAMSPY_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_ECMMINE_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_UPLINK_DONE);
				break;
#else
			case DEBUGOPT_MANPOS:
				g_DebugManPos ^= 1;
				break;
			case DEBUGOPT_PADS:
				g_DebugPads = (g_DebugPads + 1) % 4;
				break;
			case DEBUGOPT_TILES:
				g_DebugTiles = (g_DebugTiles + 1) % 4;
				break;
			case DEBUGOPT_ALLLEVELS:
				for (i = 0; i < 21; i++) {
					for (tmp = 0; tmp < 3; tmp++) {
						g_GameFile.besttimes[i][tmp] = 7;
					}
				}

				g_AltTitleUnlocked = true;
				break;
			case DEBUGOPT_ALLCHALLENGES:
				g_DebugAllChallenges ^= 1;
				mpDetermineUnlockedFeatures();
				break;
			case DEBUGOPT_ALLBUDDIES:
				g_DebugAllBuddies ^= 1;
				break;
			case DEBUGOPT_ALLTRAINING:
				g_DebugAllTraining ^= 1;

				for (i = 0; i < ARRAYCOUNT(g_GameFile.firingrangescores); i++) {
					g_GameFile.firingrangescores[i] = 0xff;
				}

				gamefileSetFlag(GAMEFILEFLAG_CI_CLOAK_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_DISGUISE_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_XRAY_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_IR_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_RTRACKER_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_DOORDECODER_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_NIGHTVISION_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_CAMSPY_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_ECMMINE_DONE);
				gamefileSetFlag(GAMEFILEFLAG_CI_UPLINK_DONE);
				break;
			case DEBUGOPT_44:
				// This is one of the "-" labels. The value is returned in a
				// getter function but the getter function is never called.
				var800787a4nb ^= 1;
				break;
			case DEBUGOPT_CHRSTATS:
				g_DebugChrStats ^= 1;
				break;
			case DEBUGOPT_PROPS:
				g_DebugRenderProps ^= 1;
				break;
			case DEBUGOPT_VMSTATS:
				g_VmShowStats ^= 1;
				break;
			case DEBUGOPT_MEMINFO:
				g_DebugMemInfo ^= 1;
				break;
#endif
			}
		}
	}

	if (buttonsthisframe & START_BUTTON) {
		if (g_DebugIsMenuOpen == true) {
			dhudReset();
		}

		g_DebugIsMenuOpen = false;
	}

	debugSaveSelectedOption();

	return g_DebugIsMenuOpen;
}

bool debug0f11ed70(void)
{
	return var800786f8nb;
}

bool debugIsBgRenderingEnabled(void)
{
	return g_DebugRenderBg;
}

bool debugIsPropRenderingEnabled(void)
{
	return g_DebugRenderProps;
}

bool debug0f11990cnb(void)
{
	return var80078708nb;
}

bool debugIsManPosEnabled(void)
{
	return g_DebugManPos;
}

void debugSetManPos(bool enabled)
{
	g_DebugManPos = enabled;
}

bool debug0f119930nb(void)
{
	return var80078710nb;
}

bool debug0f11993cnb(void)
{
	return var80078714nb;
}

bool debug0f11edb0(void)
{
	return var80078718nb;
}

bool debug0f11edb8(void)
{
	return var8007871cnb;
}

bool debugIsRoomStateDebugEnabled(void)
{
	return g_DebugRoomState;
}

bool debugIsLineModeEnabled(void)
{
	return g_DebugLineMode;
}

void debugSetLineModeEnabled(bool enabled)
{
	g_DebugLineMode = enabled;
}

bool debugIsTurboModeEnabled(void)
{
	return g_DebugTurboMode;
}

void debugSetTurboMode(bool enabled)
{
	g_DebugTurboMode = enabled;
}

bool debugForceAllObjectivesComplete(void)
{
	return g_DebugObjectives;
}

bool debugIsZBufferDisabled(void)
{
	return g_DebugZBufferDisabled;
}

bool debug0f11ee30(void)
{
	return var80078744nb;
}

bool debug0f11ee38(void)
{
	return var80078750nb;
}

bool debug0f11ee40(void)
{
	return var80078754nb;
}

bool debug0f1199d8nb(void)
{
	return var80078758nb;
}

bool debug0f1199e4nb(void)
{
	return var80078740nb;
}

bool debug0f1199f0nb(void)
{
	return var80078724nb;
}

bool debug0f1199fcnb(void)
{
	return var80078728nb;
}

bool debug0f119a08nb(void)
{
	return var8007872cnb;
}

bool debug0f119a14nb(void)
{
	return var80078748nb;
}

bool debug0f119a20nb(void)
{
	return var8007874cnb;
}

bool debug0f119a2cnb(void)
{
	return var8007875cnb;
}

s32 debugGetSlowMotion(void)
{
	return g_DebugSlowMotion;
}

bool debug0f119a44nb(void)
{
	return var80078768nb;
}

bool debug0f119a50nb(void)
{
	return var80078760nb;
}

s32 debugGetTilesDebugMode(void)
{
	return g_DebugTiles;
}

s32 debugGetPadsDebugMode(void)
{
	return g_DebugPads;
}

bool debug0f119a74nb(void)
{
	return var80078774nb;
}

void debug0f119a80nb(void)
{
	var80078774nb = 0;
}

bool debug0f119a8cnb(void)
{
	return var80078778nb;
}

bool debug0f11eea8(void)
{
	return var80078780nb;
}

bool debug0f119aa4nb(void)
{
	return false;
}

bool debugDangerousProps(void)
{
	return var800787ecnb;
}

bool debug0f119ab8nb(void)
{
	return var800787d8nb;
}

bool debug0f119ac4nb(void)
{
	return var800787dcnb;
}

bool debug0f119ad0nb(void)
{
	return var8007877cnb;
}

bool debugGetMotionBlur(void)
{
	return var80078784nb;
}

bool debug0f119ae8nb(void)
{
	return var80078790nb;
}

u32 dprint()
{
	return var800787b8nb;
}

bool debug0f119b00nb(void)
{
	return var800787c0nb;
}

bool debugAllowEndLevel(void)
{
	return var800787c4nb;
}

bool debug0f119b18nb(void)
{
	return var800787c8nb;
}

bool debug0f119b24nb(void)
{
	return var800787ccnb;
}

bool debug0f119b30nb(void)
{
	return var800787d0nb;
}

bool debug0f119b3cnb(void)
{
	return var800787d4nb;
}

bool debugIsFootstepsEnabled(void)
{
	return g_DebugFootsteps;
}

bool debugIsAllChallengesEnabled(void)
{
	return g_DebugAllChallenges;
}

bool debugIsAllBuddiesEnabled(void)
{
	return g_DebugAllBuddies;
}

#if VERSION == VERSION_PAL_BETA
bool debugIsSetCompleteEnabled(void)
{
	return g_DebugSetComplete;
}
#endif

bool debugIsAllTrainingEnabled(void)
{
	return g_DebugAllTraining;
}

bool debug0f119b78nb(void)
{
	return var800787a4nb;
}

bool debug0f119b84nb(void)
{
	return var800787a8nb;
}

bool debugIsMemInfoEnabled(void)
{
	return g_DebugMemInfo;
}

bool debug0f119b9cnb(void)
{
	return var800787b0nb;
}

bool debug0f119ba8nb(void)
{
	return var800787bcnb;
}

bool debugIsChrStatsEnabled(void)
{
	return g_DebugChrStats;
}

bool debug0f11ef80(void)
{
	return var800787e8nb;
}

bool debug0f119bccnb(void)
{
	return var800787e0nb;
}

bool debug0f119bd8nb(void)
{
	return var800787f0nb;
}
