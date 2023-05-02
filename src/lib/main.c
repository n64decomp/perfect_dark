#include <ultra64.h>
#include <sched.h>
#include "lib/ailist.h"
#include "lib/sched.h"
#include "lib/vars.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/file.h"
#include "game/lang.h"
#include "game/race.h"
#include "game/body.h"
#include "game/stubs/game_000840.h"
#include "game/stubs/game_000850.h"
#include "game/stubs/game_000860.h"
#include "game/stubs/game_000870.h"
#include "game/smoke.h"
#include "game/stubs/game_0008e0.h"
#include "game/stubs/game_0008f0.h"
#include "game/stubs/game_000900.h"
#include "game/stubs/game_000910.h"
#include "game/tex.h"
#include "game/stubs/game_00b180.h"
#include "game/stubs/game_00b200.h"
#include "game/challenge.h"
#include "game/title.h"
#include "game/pdmode.h"
#include "game/objectives.h"
#include "game/endscreen.h"
#include "game/playermgr.h"
#include "game/game_1531a0.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/lv.h"
#include "game/timing.h"
#include "game/music.h"
#include "game/stubs/game_175f50.h"
#include "game/game_175f90.h"
#include "game/game_176080.h"
#include "game/game_1a78b0.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/splat.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/audiomgr.h"
#include "lib/args.h"
#include "lib/boot.h"
#include "lib/vm.h"
#include "lib/rzip.h"
#include "lib/vi.h"
#include "lib/dma.h"
#include "lib/joy.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/mema.h"
#include "lib/profile.h"
#include "lib/anim.h"
#include "lib/rdp.h"
#include "lib/lib_34d0.h"
#include "lib/lib_2f490.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

extern u8 g_LvShowStats;
extern u8 g_LvStatsPage;

bool var8005d9b0 = false;
s32 g_StageNum = STAGE_TITLE;
u32 g_MainMemaHeapSize = 1024 * 300;
bool var8005d9bc = false;
s32 var8005d9c0 = 0;
s32 var8005d9c4 = 0;
u32 g_MainNumGfxTasks = 0;
bool g_MainIsEndscreen = false;
s32 g_DoBootPakMenu = 0;

struct stageallocation g_StageAllocations8Mb[] = {
	{ STAGE_CITRAINING,    "-ml0 -me0 -mgfx120 -mvtx98 -ma100"             },
	{ STAGE_DEFECTION,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_INVESTIGATION, "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_EXTRACTION,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_CHICAGO,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_G5BUILDING,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_VILLA,         "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_INFILTRATION,  "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_RESCUE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_ESCAPE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_AIRBASE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_AIRFORCEONE,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_CRASHSITE,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_PELAGIC,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_DEEPSEA,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_DEFENSE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma100" },
	{ STAGE_ATTACKSHIP,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_SKEDARRUINS,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_MP_SKEDAR,     "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_RAVINE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_PIPES,      "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_G5BUILDING, "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_SEWERS,     "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_WAREHOUSE,  "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_BASE,       "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_COMPLEX,    "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_TEMPLE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_FELICITY,   "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_AREA52,     "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_GRID,       "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_CARPARK,    "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_RUINS,      "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_FORTRESS,   "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_MP_VILLA,      "-ml0 -me0 -mgfx200 -mvtx200 -ma100"            },
	{ STAGE_TEST_RUN,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP2,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP6,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP7,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP8,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP14,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP16,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP17,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP18,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP19,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP20,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_ASH,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_28,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_MBR,           "-ml0 -me0 -mgfx120 -mvtx100 -ma100"            },
	{ STAGE_TEST_SILO,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_24,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_MAIANSOS,      "-ml0 -me0 -mgfx120 -mvtx100 -ma500"            },
	{ STAGE_RETAKING,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_DEST,     "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_2B,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_WAR,           "-ml0 -me0 -mgfx120 -mvtx98 -ma100"             },
	{ STAGE_TEST_UFF,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_OLD,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_DUEL,          "-ml0 -me0 -mgfx120 -mvtx100 -ma100"            },
	{ STAGE_TEST_LAM,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_ARCH,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx120 -mvtx98 -ma300"             },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx120 -mvtx98 -ma300"             },
};

Gfx var8005dcc8[] = {
	gsSPSegment(0x00, 0x00000000),
	gsSPDisplayList(&var800613a0),
	gsSPDisplayList(&var80061380),
	gsDPFullSync(),
	gsSPEndDisplayList(),
};

Gfx var8005dcf0[] = {
	gsSPSegment(0x00, 0x00000000),
	gsSPDisplayList(&var800613a0),
	gsSPDisplayList(&var80061380),
	gsDPFullSync(),
	gsSPEndDisplayList(),
};

s32 var8005dd18 = 1;

extern u8 _accessingpakSegmentRomStart;
extern u8 _accessingpakSegmentRomEnd;
extern u8 _copyrightSegmentRomStart;
extern u8 _copyrightSegmentRomEnd;
extern u8 _setupdishasmSegmentEnd;

/**
 * Initialise various subsystems, display the copyright or accessing pak texture,
 * then initialise more subsystems.
 */
void mainInit(void)
{
	s32 x;
	s32 dsty;
	OSMesg msg;
	OSTimer timer;
	OSMesgQueue queue;
	s32 i;
	s32 j;
	u16 *fb;
	s32 srcy;
	u32 addr;
	u8 *start;
	u8 *end;

	dmaInit();
	amgrInit();
	varsInit();
	viConfigureForLogos();
	var8005d9b0 = 1;
	joyInit();
	osCreateMesgQueue(&queue, &msg, 1);

	// Wait a bit, reset the controllers and wait a bit more
	for (i = 0; i < 4; i++) {
		osSetTimer(&timer, 781250 * 6, 0, &queue, &msg);
		osRecvMesg(&queue, &msg, OS_MESG_BLOCK);

		if (i == 1) {
			joyReset();
		} else if (i >= 2) {
			joyDebugJoy();
		}

		if (1);
		if (1);
	}

	if (argFindByPrefix(1, "-level_") == NULL) {
		var8005d9b0 = true;
	}

	// If holding start on any controller, open boot pak menu
	if (joyGetButtons(0, START_BUTTON) == 0
			&& joyGetButtons(1, START_BUTTON) == 0
			&& joyGetButtons(2, START_BUTTON) == 0
			&& joyGetButtons(3, START_BUTTON) == 0) {
		g_DoBootPakMenu = false;
	} else {
		g_DoBootPakMenu = true;
	}

	{
		OSMesg receivedmsg = NULL;
		OSScMsg scdonemsg = { OS_SC_DONE_MSG };
		u16 *texture;
		s32 numpages;
		u8 scratch[1024 * 5 - 8];

		// Choose where to place the temporary framebuffer.
		// In 4MB mode, place it close to the end of memory,
		// but before the thread stacks and VM system.
		// In 8MB mode, put it at the end of the expansion pak.
		if (bootGetMemSize() <= 4 * 1024 * 1024) {
			addr = K0BASE + 4 * 1024 * 1024;
			addr -= STACKSIZE_MAIN;
			addr -= STACKSIZE_IDLE;
			addr -= STACKSIZE_RMON;
			addr -= STACKSIZE_SCHED;
			addr -= STACKSIZE_AUDIO;
			addr -= 8; // markers for stack overflow detection
			addr -= g_VmNumPages * 8; // vm state table
			addr -= 268 * 4096; // vm loaded pages buffer
			addr -= addr % 0x2000; // align down to a multiple of 0x2000
			addr -= 0x1c80; // buffer for single biggest game zip
		} else {
			addr = K0BASE + 8 * 1024 * 1024;
		}

		addr -= 640 * 480 * 2; // the framebuffer itself
		addr -= 0x40; // align down to a multiple of 0x40

		fb = (u16 *) ALIGN64(PHYS_TO_K0(addr));

		// Prepare space for the unzipped texture immediately before the framebuffer.
		// Both textures are 507x48.
		texture = fb - 507 * 48;

		// DMA the compressed texture from the ROM to the framebuffer.
		// It's using the framebuffer as a temporary data buffer.
		if (g_DoBootPakMenu) {
			start = &_accessingpakSegmentRomStart;
			end = &_accessingpakSegmentRomEnd;
			dmaExec(fb, (u32) start, end - start);
		} else {
			start = &_copyrightSegmentRomStart;
			end = &_copyrightSegmentRomEnd;
			dmaExec(fb, (u32) start, end - start);
		}

		// This is required for a match
		numpages = g_VmNumPages;

		if ((f64) numpages && (f64) numpages);

		// Unzip the compressed texture from fb to texture
		rzipInflate(fb, texture, scratch);

		// Clear the framebuffer except for the bottom 48 rows,
		// because that's where the texture will go.
		// The increment here is too small, so some pixels are zeroed twice.
		for (dsty = 0; dsty < (480 - 48) * 640; dsty += 576) {
			for (x = 0; x < 640; x++) {
				fb[dsty + x] = 0;
			}
		}

		if (osTvType != OS_TV_PAL) {
			// Copy the texture to the framebuffer.
			// The framebuffer will be displayed at 576 wide,
			// and the texture is right aligned.
			dsty = 0;

			for (srcy = 0; srcy < 507 * 48; srcy += 507) {
				for (x = 0; x < 507; x++) {
					fb[dsty + (576 - 507) + x] = texture[srcy + x];
				}

				dsty += 576;
			}
		}

		viSetMode(VIMODE_HI);
		viConfigureForCopyright(fb);

		g_RdpOutBufferStart = texture;
		g_RdpOutBufferEnd = texture + 0x400; // 0x800 bytes, because texture is u16

		while (osRecvMesg(&g_SchedMesgQueue, &receivedmsg, OS_MESG_NOBLOCK) == 0) {
			// empty
		}

		j = 0;

		while (j < 6) {
			osRecvMesg(&g_SchedMesgQueue, &receivedmsg, OS_MESG_BLOCK);

			i = (s32) &scdonemsg;

			if (*(s16 *) receivedmsg == 1) {
				viUpdateMode();
				rdpCreateTask(var8005dcc8, var8005dcf0, 0, (void *) i);
				j++;
			}
		}
	}

	// From the N64 SDK:
	//
	//     Please design the game program so that it won't execute normally
	//     when an unexpected television system format is detected by osTvType.
	//     Design the program to either go into an infinite loop or display a
	//     message indicating a system error.
	//
	if (osTvType == OS_TV_PAL) {
		while (1);
	}

	vmInit();
	func0f1a78b0();
	filesInit();

	if (var8005d9b0) {
		argSetString("          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400");
	}

	start = (u8 *) PHYS_TO_K0(osVirtualToPhysical(&_setupdishasmSegmentEnd));
	end = g_VmMarker;
	mempSetHeap(start, end - start);

	mempResetPool(MEMPOOL_8);
	mempResetPool(MEMPOOL_PERMANENT);

	challengesInit();
	utilsInit();
	texInit();
	lvInit();
	cheatsInit();
	playermgrInit();
	frametimeInit();
	smokesInit();
	mpInit();
	paksInit();
	animsInit();
	racesInit();
	bodiesInit();
	titleInit();
	viConfigureForLegal();
	viBlack(true);

	var8005dd18 = 0;
}

u32 var8005dd3c = 0x00000000;
u32 var8005dd40 = 0x00000000;
u32 var8005dd44 = 0x00000000;
u32 var8005dd48 = 0x00000000;
u32 var8005dd4c = 0x00000000;
u32 var8005dd50 = 0x00000000;
s32 g_MainChangeToStageNum = -1;
bool g_MainIsDebugMenuOpen = false;

void mainProc(void)
{
	mainInit();
	rdpInit();
	sndInit();

	while (true) {
		mainLoop();
	}
}

/**
 * This function enters an infinite loop which iterates once per stage load.
 * Within this loop is an inner loop which runs very frequently and decides
 * whether to run mainTick on each iteration.
 */
void mainLoop(void)
{
	s32 ending = false;
	OSScMsg msg2 = {OS_SC_DONE_MSG};
	OSMesg msg;
	s32 index;
	s32 numplayers;

	func0f175f98();

	var8005d9c4 = 0;
	argGetLevel(&g_StageNum);

	if (g_DoBootPakMenu) {
		g_Vars.unk0004e4 = 0xfd;
		g_StageNum = STAGE_BOOTPAKMENU;
	}

	if (g_StageNum != STAGE_TITLE) {
		titleSetNextStage(g_StageNum);

		if (g_StageNum < STAGE_TITLE) {
			func0f01b148(0);

			if (argFindByPrefix(1, "-hard")) {
				lvSetDifficulty(argFindByPrefix(1, "-hard")[0] - '0');
			}
		}
	}

	rngSetSeed(osGetCount());

	// Outer loop - this is infinite because ending is never changed
	while (!ending) {
		g_MainNumGfxTasks = 0;
		msg = NULL;
		g_MainIsEndscreen = false;

		if (var8005d9b0 && var8005d9c4 == 0) {
			index = -1;

			if (g_StageNum < STAGE_TITLE && getNumPlayers() >= 2) {
				index = 0;

				while (g_StageAllocations8Mb[index].stagenum) {
					if (g_StageNum + 400 == g_StageAllocations8Mb[index].stagenum) {
						break;
					}

					index++;
				}

				if (g_StageAllocations8Mb[index].stagenum == 0) {
					index = -1;
				}
			}

			if (index < 0) {
				index = 0;

				while (g_StageAllocations8Mb[index].stagenum) {
					if (g_StageNum == g_StageAllocations8Mb[index].stagenum) {
						break;
					}

					index++;
				}
			}

			argSetString(g_StageAllocations8Mb[index].string);
		}

		var8005d9c4 = 0;

		mempResetPool(MEMPOOL_7);
		mempResetPool(MEMPOOL_STAGE);
		filesStop(4);

		if (argFindByPrefix(1, "-ma")) {
			g_MainMemaHeapSize = strtol(argFindByPrefix(1, "-ma"), NULL, 0) * 1024;
		}

		memaReset(mempAlloc(g_MainMemaHeapSize, MEMPOOL_STAGE), g_MainMemaHeapSize);
		langReset(g_StageNum);
		playermgrReset();

		if (g_StageNum >= STAGE_TITLE) {
			numplayers = 0;
		} else {
			if (argFindByPrefix(1, "-play")) {
				numplayers = strtol(argFindByPrefix(1, "-play"), NULL, 0);
			} else {
				numplayers = 1;
			}

			if (getNumPlayers() >= 2) {
				numplayers = getNumPlayers();
			}
		}

		if (numplayers < 2) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = -1;
		} else if (argFindByPrefix(1, "-coop")) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = 1;
			g_Vars.antiplayernum = -1;
		} else if (argFindByPrefix(1, "-anti")) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = 1;
		}

		playermgrAllocatePlayers(numplayers);

		if (argFindByPrefix(1, "-mpbots")) {
			g_Vars.lvmpbotlevel = 1;
		}

		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
			g_MpSetup.chrslots = 0x03;
			mpReset();
		} else if (g_Vars.perfectbuddynum) {
			mpReset();
		} else if (g_Vars.mplayerisrunning == false
				&& (numplayers >= 2 || g_Vars.lvmpbotlevel || argFindByPrefix(1, "-play"))) {
			g_MpSetup.chrslots = 1;

			if (numplayers >= 2) {
				g_MpSetup.chrslots |= 1 << 1;
			}

			if (numplayers >= 3) {
				g_MpSetup.chrslots |= 1 << 2;
			}

			if (numplayers >= 4) {
				g_MpSetup.chrslots |= 1 << 3;
			}

			g_MpSetup.stagenum = g_StageNum;
			mpReset();
		}

		gfxReset();
		joyReset();
		mblurReset(g_StageNum);
		lvReset(g_StageNum);
		viReset(g_StageNum);
		frametimeCalculate();
#if PROFILING
		profileReset();
#endif

		while (osRecvMesg(&g_SchedMesgQueue, &msg, OS_MESG_NOBLOCK) != -1) {
			// empty
		}

		while (g_MainChangeToStageNum < 0 || g_MainNumGfxTasks != 0) {
			while (g_MainChangeToStageNum < 0 && g_MainNumGfxTasks < 2) {
				if (osGetCount() - g_Vars.thisframestartt >= CYCLES_PER_FRAME / 2) {
					mainTick();
				}
			}

			osRecvMesg(&g_SchedMesgQueue, &msg, OS_MESG_BLOCK);

			switch ((s32) msg) {
			case OS_SC_DONE_MSG:
				g_MainNumGfxTasks--;
				break;
			case OS_SC_PRE_NMI_MSG:
				// This seems to be a hack to get this loop to keep ticking...
				// maybe graphics tasks stop being created after pre NMI?
				g_MainNumGfxTasks = 4;
				break;
			}
		}

		lvStop();
		mempDisablePool(MEMPOOL_STAGE);
		mempDisablePool(MEMPOOL_7);
		filesStop(4);
		viBlack(true);
		pak0f116994();

		g_StageNum = g_MainChangeToStageNum;
		g_MainChangeToStageNum = -1;
	}

	// Unreachable
	func0f175fc8();
}

void mainTick(void)
{
	Gfx *gdl;
	Gfx *gdlstart;
	s32 i;

	frametimeCalculate();
#if PROFILING
	profileReset();
#endif
	joyDebugJoy();

	profileStart(PROFILEMARKER_CPU);
	gdl = gdlstart = gfxGetMasterDisplayList();

	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

	PROFILE(PROFILEMARKER_LVTICK, lvTick());

	profileStart(PROFILEMARKER_LVTICKPLAYERS);
	playermgrShuffle();

	if (g_StageNum < STAGE_TITLE) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(playermgrGetPlayerAtOrder(i));

			viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
			viSetFovAspectAndSize(
					g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
					g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);

			lvTickPlayer();
		}
	}

	profileEnd(PROFILEMARKER_LVTICKPLAYERS);

	PROFILE(PROFILEMARKER_LVRENDER, gdl = lvRender(gdl));

	profileEnd(PROFILEMARKER_CPU);

#if PROFILING
	if (g_LvShowStats) {
		if (g_LvStatsPage == 1) {
			gdl = profileRender(gdl);
		} else if (g_LvStatsPage == 2) {
			gdl = profileRenderDynamic(gdl);
		}
	}
#endif

	gDPFullSync(gdl++);
	gSPEndDisplayList(gdl++);

	gfxSwapBuffers();
	viUpdateMode();

	rdpCreateTask(gdlstart, gdl, 0, (void *) OS_SC_DONE_MSG);
	g_MainNumGfxTasks++;
}

void mainEndStage(void)
{
	sndStopNosedive();

	if (!g_MainIsEndscreen) {
		pak0f11c6d0();
		joyDisableTemporarily();

		if (g_Vars.coopplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				setCurrentPlayerNum(i);
				endscreenPushCoop();
			}

			setCurrentPlayerNum(prevplayernum);
			musicStartMenu();
		} else if (g_Vars.antiplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				setCurrentPlayerNum(i);
				endscreenPushAnti();
			}

			setCurrentPlayerNum(prevplayernum);
			musicStartMenu();
		} else if (g_Vars.normmplayerisrunning) {
			mpEndMatch();
		} else {
			endscreenPrepare();
			musicStartMenu();
		}
	}

	g_MainIsEndscreen = true;
}

/**
 * Change to the given stage at the end of the current frame.
 */
void mainChangeToStage(s32 stagenum)
{
	pak0f11c6d0();

	g_MainChangeToStageNum = stagenum;
}

s32 mainGetStageNum(void)
{
	return g_StageNum;
}

void func0000e990(void)
{
	objectivesCheckAll();
	objectivesDisableChecking();
	mainEndStage();
}
