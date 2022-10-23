#include <ultra64.h>
#include <sched.h>
#include "lib/ailist.h"
#include "lib/sched.h"
#include "lib/vars.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/debug.h"
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
#include "lib/fault.h"
#include "lib/crash.h"
#include "lib/dma.h"
#include "lib/joy.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/mema.h"
#include "lib/profile.h"
#include "lib/videbug.h"
#include "lib/debughud.h"
#include "lib/anim.h"
#include "lib/rdp.h"
#include "lib/lib_34d0.h"
#include "lib/lib_2f490.h"
#include "lib/rmon.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

bool var8005d9b0 = false;
s32 g_StageNum = STAGE_TITLE;
u32 g_MainMemaHeapSize = 1024 * 300;
bool var8005d9bc = false;
s32 var8005d9c0 = 0;
s32 var8005d9c4 = 0;
bool g_MainGameLogicEnabled = true;
u32 g_MainNumGfxTasks = 0;
bool g_MainIsEndscreen = false;
s32 g_DoBootPakMenu = 0;

struct stageallocation g_StageAllocations8Mb[] = {
#if VERSION >= VERSION_NTSC_1_0
	{ STAGE_CITRAINING,    "-ml0 -me0 -mgfx120 -mvtx98 -ma200"             },
	{ STAGE_DEFECTION,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_INVESTIGATION, "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_EXTRACTION,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_CHICAGO,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_G5BUILDING,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_VILLA,         "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_INFILTRATION,  "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_RESCUE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_ESCAPE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_AIRBASE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_AIRFORCEONE,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_CRASHSITE,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_PELAGIC,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_DEEPSEA,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_DEFENSE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_ATTACKSHIP,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_SKEDARRUINS,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma200" },
	{ STAGE_MP_SKEDAR,     "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_RAVINE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_PIPES,      "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_G5BUILDING, "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_SEWERS,     "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_WAREHOUSE,  "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_BASE,       "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_COMPLEX,    "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_TEMPLE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_FELICITY,   "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_AREA52,     "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_GRID,       "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_CARPARK,    "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_RUINS,      "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_FORTRESS,   "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
	{ STAGE_MP_VILLA,      "-ml0 -me0 -mgfx200 -mvtx200 -ma200"            },
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
	{ STAGE_MBR,           "-ml0 -me0 -mgfx120 -mvtx100 -ma200"            },
	{ STAGE_TEST_SILO,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_24,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_MAIANSOS,      "-ml0 -me0 -mgfx120 -mvtx100 -ma500"            },
	{ STAGE_RETAKING,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_DEST,     "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_2B,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_WAR,           "-ml0 -me0 -mgfx120 -mvtx98 -ma200"             },
	{ STAGE_TEST_UFF,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_OLD,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_DUEL,          "-ml0 -me0 -mgfx120 -mvtx100 -ma200"            },
	{ STAGE_TEST_LAM,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_ARCH,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx120 -mvtx98 -ma300"             },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx120 -mvtx98 -ma300"             },
#else
	// ntsc-beta
	{ STAGE_CITRAINING,    "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_DEFECTION,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_INVESTIGATION, "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_EXTRACTION,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_CHICAGO,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_G5BUILDING,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_VILLA,         "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma600" },
	{ STAGE_INFILTRATION,  "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_RESCUE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_ESCAPE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_AIRBASE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_AIRFORCEONE,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_CRASHSITE,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_PELAGIC,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_DEEPSEA,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_DEFENSE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_ATTACKSHIP,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_SKEDARRUINS,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_MP_SKEDAR,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_RAVINE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_PIPES,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_G5BUILDING, "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_SEWERS,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_WAREHOUSE,  "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_BASE,       "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_COMPLEX,    "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_TEMPLE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_FELICITY,   "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_AREA52,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_GRID,       "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_CARPARK,    "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_RUINS,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_FORTRESS,   "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_VILLA,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
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
	{ STAGE_TEST_ASH,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_28,            "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_MBR,           "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_SILO,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_24,            "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_MAIANSOS,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_RETAKING,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_DEST,     "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_2B,            "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_WAR,           "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_UFF,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_OLD,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_DUEL,          "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_LAM,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_ARCH,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx120 -mvtx100 -ma300"            },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx120 -mvtx100 -ma300"            },
#endif
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
extern u8 _gameSegmentEnd;

#if VERSION >= VERSION_NTSC_1_0
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
	mempInit();
	memaInit();
	videbugInit();
	viConfigureForLogos();
	var8005d9b0 = rmonIsDisabled();
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

#if VERSION == VERSION_PAL_BETA
	// In PAL beta, pressing all C buttons during poweron sets g_CrashHasMessage.
	// If it's set, a sound effect is played on the legal screen.
	// It's likely some debug code to see how far the game got before crashing.
#define BUTTON_MASK (U_CBUTTONS | D_CBUTTONS | L_CBUTTONS | R_CBUTTONS)

	if (joyGetButtons(0, BUTTON_MASK) == BUTTON_MASK
			|| joyGetButtons(1, BUTTON_MASK) == BUTTON_MASK
			|| joyGetButtons(2, BUTTON_MASK) == BUTTON_MASK
			|| joyGetButtons(3, BUTTON_MASK) == BUTTON_MASK) {
		g_CrashHasMessage = true;
	}
#endif

	{
		OSMesg receivedmsg = NULL;
		OSScMsg scdonemsg = { OS_SC_DONE_MSG };
		u16 *texture;
		s32 numpages;
		u8 scratch[1024 * 5 - 8];
#if PAL
		u32 stack[2];
#endif

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

#if VERSION >= VERSION_JPN_FINAL
		if (osTvType == OS_TV_NTSC)
#elif PAL
		if (osTvType == OS_TV_PAL)
#else
		if (osTvType != OS_TV_PAL)
#endif
		{
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
#if VERSION >= VERSION_JPN_FINAL
	if (osTvType != OS_TV_NTSC) {
		while (1);
	}
#elif PAL
	if (osTvType != OS_TV_PAL) {
		while (1);
	}
#else
	if (osTvType == OS_TV_PAL) {
		while (1);
	}
#endif

	vmInit();
	func0f1a78b0();
	filesInit();
	stub0f175f50();
	func0f175f90();

	if (var8005d9b0) {
		argSetString("          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400");
	}

	start = (u8 *) PHYS_TO_K0(osVirtualToPhysical(&_gameSegmentEnd));
	end = g_VmMarker;
	mempSetHeap(start, end - start);

	mempResetPool(MEMPOOL_8);
	mempResetPool(MEMPOOL_PERMANENT);

	ailistPreprocessFile(g_GlobalAilists, MEMPOOL_PERMANENT);

	crashReset();
	challengesInit();
	utilsInit();
	func000034d0();
	texInit();
	langInit();
	lvInit();
	cheatsInit();
	func0000e9c0();
	textInit();
	dhudInit();
	playermgrInit();
	frametimeInit();
	stub0f00b200();
	profileInit();
	stub0f000870();
	smokesInit();
	stub0f0008e0();
	stub0f0008f0();
	stub0f000900();
	stub0f00b180();
	stub0f000910();
	stub0f000840();
	mpInit();
	paksInit();
	animsInit();
	racesInit();
	bodiesInit();
	stub0f000850();
	stub0f000860();
	titleInit();
	viConfigureForLegal();
	viBlack(true);

	var8005dd18 = 0;

#if VERSION >= VERSION_PAL_BETA && VERSION < VERSION_JPN_FINAL
	if (g_DoBootPakMenu) {
		osGetCount();
	}
#endif
}
#else
const char var70053a98[] = "-level_";
const char var70053aa0[] = "          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400";

u32 var8005dd1c = 0x00020000;
u32 var8005dd20 = 0x00000000;
u32 var8005dd24 = 0x00000000;
u32 var8005dd28 = 0x00000000;
u32 var8005dd2c = 0x00000000;
u32 var8005dd30 = 0x00000000;
u32 var8005dd34 = 0x00000000;
u32 var8005dd38 = 0x00000000;

GLOBAL_ASM(
glabel mainInit
/*     da80:	27bdeb20 */ 	addiu	$sp,$sp,-5344
/*     da84:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     da88:	afb20030 */ 	sw	$s2,0x30($sp)
/*     da8c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*     da90:	0c003060 */ 	jal	faultInit
/*     da94:	afb00028 */ 	sw	$s0,0x28($sp)
/*     da98:	0c0035b4 */ 	jal	dmaInit
/*     da9c:	00000000 */ 	sll	$zero,$zero,0x0
/*     daa0:	0c0022f0 */ 	jal	amgrInit
/*     daa4:	00000000 */ 	sll	$zero,$zero,0x0
/*     daa8:	0c0059d4 */ 	jal	varsInit
/*     daac:	00000000 */ 	sll	$zero,$zero,0x0
/*     dab0:	0c004994 */ 	jal	mempInit
/*     dab4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dab8:	0c004beb */ 	jal	memaInit
/*     dabc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dac0:	0c004fea */ 	jal	videbugInit
/*     dac4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dac8:	0c002714 */ 	jal	viConfigureForLogos
/*     dacc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dad0:	0c00c456 */ 	jal	rmonIsDisabled
/*     dad4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dad8:	3c018006 */ 	lui	$at,0x8006
/*     dadc:	0c0052b6 */ 	jal	joyInit
/*     dae0:	ac22f2d0 */ 	sw	$v0,-0xd30($at)
/*     dae4:	27b11498 */ 	addiu	$s1,$sp,0x1498
/*     dae8:	27b214d4 */ 	addiu	$s2,$sp,0x14d4
/*     daec:	02402825 */ 	or	$a1,$s2,$zero
/*     daf0:	02202025 */ 	or	$a0,$s1,$zero
/*     daf4:	0c0125c4 */ 	jal	osCreateMesgQueue
/*     daf8:	24060001 */ 	addiu	$a2,$zero,0x1
/*     dafc:	00008025 */ 	or	$s0,$zero,$zero
/*     db00:	3c070047 */ 	lui	$a3,0x47
.NB0000db04:
/*     db04:	240e0000 */ 	addiu	$t6,$zero,0x0
/*     db08:	240f0000 */ 	addiu	$t7,$zero,0x0
/*     db0c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     db10:	afae0010 */ 	sw	$t6,0x10($sp)
/*     db14:	34e7868c */ 	ori	$a3,$a3,0x868c
/*     db18:	27a414b0 */ 	addiu	$a0,$sp,0x14b0
/*     db1c:	24060000 */ 	addiu	$a2,$zero,0x0
/*     db20:	afb10018 */ 	sw	$s1,0x18($sp)
/*     db24:	0c0127bc */ 	jal	osSetTimer
/*     db28:	afb2001c */ 	sw	$s2,0x1c($sp)
/*     db2c:	02202025 */ 	or	$a0,$s1,$zero
/*     db30:	02402825 */ 	or	$a1,$s2,$zero
/*     db34:	0c0126b0 */ 	jal	osRecvMesg
/*     db38:	24060001 */ 	addiu	$a2,$zero,0x1
/*     db3c:	24010001 */ 	addiu	$at,$zero,0x1
/*     db40:	56010006 */ 	bnel	$s0,$at,.NB0000db5c
/*     db44:	2a010002 */ 	slti	$at,$s0,0x2
/*     db48:	0c005310 */ 	jal	joyReset
/*     db4c:	00000000 */ 	sll	$zero,$zero,0x0
/*     db50:	10000007 */ 	beqz	$zero,.NB0000db70
/*     db54:	26100001 */ 	addiu	$s0,$s0,0x1
/*     db58:	2a010002 */ 	slti	$at,$s0,0x2
.NB0000db5c:
/*     db5c:	54200004 */ 	bnezl	$at,.NB0000db70
/*     db60:	26100001 */ 	addiu	$s0,$s0,0x1
/*     db64:	0c005477 */ 	jal	joyDebugJoy
/*     db68:	00000000 */ 	sll	$zero,$zero,0x0
/*     db6c:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0000db70:
/*     db70:	24010004 */ 	addiu	$at,$zero,0x4
/*     db74:	5601ffe3 */ 	bnel	$s0,$at,.NB0000db04
/*     db78:	3c070047 */ 	lui	$a3,0x47
/*     db7c:	3c057005 */ 	lui	$a1,0x7005
/*     db80:	24a550e8 */ 	addiu	$a1,$a1,0x50e8
/*     db84:	0c004e18 */ 	jal	argFindByPrefix
/*     db88:	24040001 */ 	addiu	$a0,$zero,0x1
/*     db8c:	14400004 */ 	bnez	$v0,.NB0000dba0
/*     db90:	3c198000 */ 	lui	$t9,0x8000
/*     db94:	24180001 */ 	addiu	$t8,$zero,0x1
/*     db98:	3c018006 */ 	lui	$at,0x8006
/*     db9c:	ac38f2d0 */ 	sw	$t8,-0xd30($at)
.NB0000dba0:
/*     dba0:	8f390300 */ 	lw	$t9,0x300($t9)
/*     dba4:	24010001 */ 	addiu	$at,$zero,0x1
/*     dba8:	00002025 */ 	or	$a0,$zero,$zero
/*     dbac:	13210005 */ 	beq	$t9,$at,.NB0000dbc4
/*     dbb0:	24090001 */ 	addiu	$t1,$zero,0x1
/*     dbb4:	3c018006 */ 	lui	$at,0x8006
/*     dbb8:	ac29f2d0 */ 	sw	$t1,-0xd30($at)
.NB0000dbbc:
/*     dbbc:	1000ffff */ 	beqz	$zero,.NB0000dbbc
/*     dbc0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000dbc4:
/*     dbc4:	0c005790 */ 	jal	joyGetButtons
/*     dbc8:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     dbcc:	1440009e */ 	bnez	$v0,.NB0000de48
/*     dbd0:	24040001 */ 	addiu	$a0,$zero,0x1
/*     dbd4:	0c005790 */ 	jal	joyGetButtons
/*     dbd8:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     dbdc:	1440009a */ 	bnez	$v0,.NB0000de48
/*     dbe0:	24040002 */ 	addiu	$a0,$zero,0x2
/*     dbe4:	0c005790 */ 	jal	joyGetButtons
/*     dbe8:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     dbec:	14400096 */ 	bnez	$v0,.NB0000de48
/*     dbf0:	24040003 */ 	addiu	$a0,$zero,0x3
/*     dbf4:	0c005790 */ 	jal	joyGetButtons
/*     dbf8:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     dbfc:	14400092 */ 	bnez	$v0,.NB0000de48
/*     dc00:	3c0b8006 */ 	lui	$t3,0x8006
/*     dc04:	afa01478 */ 	sw	$zero,0x1478($sp)
/*     dc08:	256bf63c */ 	addiu	$t3,$t3,-2500
/*     dc0c:	8d610000 */ 	lw	$at,0x0($t3)
/*     dc10:	8d6e0004 */ 	lw	$t6,0x4($t3)
/*     dc14:	27aa1458 */ 	addiu	$t2,$sp,0x1458
/*     dc18:	ad410000 */ 	sw	$at,0x0($t2)
/*     dc1c:	8d610008 */ 	lw	$at,0x8($t3)
/*     dc20:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*     dc24:	8d6e000c */ 	lw	$t6,0xc($t3)
/*     dc28:	ad410008 */ 	sw	$at,0x8($t2)
/*     dc2c:	8d610010 */ 	lw	$at,0x10($t3)
/*     dc30:	ad4e000c */ 	sw	$t6,0xc($t2)
/*     dc34:	8d6e0014 */ 	lw	$t6,0x14($t3)
/*     dc38:	ad410010 */ 	sw	$at,0x10($t2)
/*     dc3c:	8d610018 */ 	lw	$at,0x18($t3)
/*     dc40:	ad4e0014 */ 	sw	$t6,0x14($t2)
/*     dc44:	8d6e001c */ 	lw	$t6,0x1c($t3)
/*     dc48:	ad410018 */ 	sw	$at,0x18($t2)
/*     dc4c:	3c018006 */ 	lui	$at,0x8006
/*     dc50:	ad4e001c */ 	sw	$t6,0x1c($t2)
/*     dc54:	0c013d4c */ 	jal	osGetMemSize
/*     dc58:	ac20f2f4 */ 	sw	$zero,-0xd0c($at)
/*     dc5c:	3c010040 */ 	lui	$at,0x40
/*     dc60:	34210001 */ 	ori	$at,$at,0x1
/*     dc64:	0041082b */ 	sltu	$at,$v0,$at
/*     dc68:	1020000e */ 	beqz	$at,.NB0000dca4
/*     dc6c:	3c0301fb */ 	lui	$v1,0x1fb
/*     dc70:	3c0f8006 */ 	lui	$t7,0x8006
/*     dc74:	8defe720 */ 	lw	$t7,-0x18e0($t7)
/*     dc78:	3c19803f */ 	lui	$t9,0x803f
/*     dc7c:	373950c0 */ 	ori	$t9,$t9,0x50c0
/*     dc80:	3c01ffef */ 	lui	$at,0xffef
/*     dc84:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*     dc88:	03381023 */ 	subu	$v0,$t9,$t8
/*     dc8c:	34216000 */ 	ori	$at,$at,0x6000
/*     dc90:	00411021 */ 	addu	$v0,$v0,$at
/*     dc94:	30491fff */ 	andi	$t1,$v0,0x1fff
/*     dc98:	00491023 */ 	subu	$v0,$v0,$t1
/*     dc9c:	10000002 */ 	beqz	$zero,.NB0000dca8
/*     dca0:	2442e380 */ 	addiu	$v0,$v0,-7296
.NB0000dca4:
/*     dca4:	3c028080 */ 	lui	$v0,0x8080
.NB0000dca8:
/*     dca8:	3c01fff6 */ 	lui	$at,0xfff6
/*     dcac:	3421a000 */ 	ori	$at,$at,0xa000
/*     dcb0:	00411021 */ 	addu	$v0,$v0,$at
/*     dcb4:	2442ffc0 */ 	addiu	$v0,$v0,-64
/*     dcb8:	3c018000 */ 	lui	$at,0x8000
/*     dcbc:	00418825 */ 	or	$s1,$v0,$at
/*     dcc0:	2631003f */ 	addiu	$s1,$s1,0x3f
/*     dcc4:	362d003f */ 	ori	$t5,$s1,0x3f
/*     dcc8:	3c0a01fb */ 	lui	$t2,0x1fb
/*     dccc:	2465bac0 */ 	addiu	$a1,$v1,-17728
/*     dcd0:	254ac5f0 */ 	addiu	$t2,$t2,-14864
/*     dcd4:	39a4003f */ 	xori	$a0,$t5,0x3f
/*     dcd8:	00808825 */ 	or	$s1,$a0,$zero
/*     dcdc:	0c003664 */ 	jal	dmaExec
/*     dce0:	01453023 */ 	subu	$a2,$t2,$a1
/*     dce4:	3c01ffff */ 	lui	$at,0xffff
/*     dce8:	342141e0 */ 	ori	$at,$at,0x41e0
/*     dcec:	02219021 */ 	addu	$s2,$s1,$at
/*     dcf0:	02402825 */ 	or	$a1,$s2,$zero
/*     dcf4:	02202025 */ 	or	$a0,$s1,$zero
/*     dcf8:	0c001da4 */ 	jal	rzipInflate
/*     dcfc:	27a60058 */ 	addiu	$a2,$sp,0x58
/*     dd00:	3c050004 */ 	lui	$a1,0x4
/*     dd04:	34a53800 */ 	ori	$a1,$a1,0x3800
/*     dd08:	00003825 */ 	or	$a3,$zero,$zero
/*     dd0c:	24040500 */ 	addiu	$a0,$zero,0x500
/*     dd10:	00075840 */ 	sll	$t3,$a3,0x1
.NB0000dd14:
/*     dd14:	022b1821 */ 	addu	$v1,$s1,$t3
/*     dd18:	00001025 */ 	or	$v0,$zero,$zero
.NB0000dd1c:
/*     dd1c:	00627021 */ 	addu	$t6,$v1,$v0
/*     dd20:	24420002 */ 	addiu	$v0,$v0,0x2
/*     dd24:	1444fffd */ 	bne	$v0,$a0,.NB0000dd1c
/*     dd28:	a5c00000 */ 	sh	$zero,0x0($t6)
/*     dd2c:	24e70240 */ 	addiu	$a3,$a3,0x240
/*     dd30:	00e5082a */ 	slt	$at,$a3,$a1
/*     dd34:	5420fff7 */ 	bnezl	$at,.NB0000dd14
/*     dd38:	00075840 */ 	sll	$t3,$a3,0x1
/*     dd3c:	00003825 */ 	or	$a3,$zero,$zero
/*     dd40:	00003025 */ 	or	$a2,$zero,$zero
/*     dd44:	240503f6 */ 	addiu	$a1,$zero,0x3f6
.NB0000dd48:
/*     dd48:	00077840 */ 	sll	$t7,$a3,0x1
/*     dd4c:	0006c840 */ 	sll	$t9,$a2,0x1
/*     dd50:	02592021 */ 	addu	$a0,$s2,$t9
/*     dd54:	022f1821 */ 	addu	$v1,$s1,$t7
/*     dd58:	00001025 */ 	or	$v0,$zero,$zero
.NB0000dd5c:
/*     dd5c:	0082c021 */ 	addu	$t8,$a0,$v0
/*     dd60:	97090000 */ 	lhu	$t1,0x0($t8)
/*     dd64:	00626821 */ 	addu	$t5,$v1,$v0
/*     dd68:	24420002 */ 	addiu	$v0,$v0,0x2
/*     dd6c:	1445fffb */ 	bne	$v0,$a1,.NB0000dd5c
/*     dd70:	a5a9008a */ 	sh	$t1,0x8a($t5)
/*     dd74:	24c601fb */ 	addiu	$a2,$a2,0x1fb
/*     dd78:	28c15f10 */ 	slti	$at,$a2,0x5f10
/*     dd7c:	1420fff2 */ 	bnez	$at,.NB0000dd48
/*     dd80:	24e70240 */ 	addiu	$a3,$a3,0x240
/*     dd84:	0c002b0c */ 	jal	viSetMode
/*     dd88:	24040002 */ 	addiu	$a0,$zero,0x2
/*     dd8c:	0c00273c */ 	jal	viConfigureForCopyright
/*     dd90:	02202025 */ 	or	$a0,$s1,$zero
/*     dd94:	3c018006 */ 	lui	$at,0x8006
/*     dd98:	3c118009 */ 	lui	$s1,0x8009
/*     dd9c:	ac321554 */ 	sw	$s2,0x1554($at)
/*     dda0:	26310160 */ 	addiu	$s1,$s1,0x160
/*     dda4:	3c018006 */ 	lui	$at,0x8006
/*     dda8:	264c0800 */ 	addiu	$t4,$s2,0x800
/*     ddac:	ac2c1550 */ 	sw	$t4,0x1550($at)
/*     ddb0:	02202025 */ 	or	$a0,$s1,$zero
/*     ddb4:	27a51478 */ 	addiu	$a1,$sp,0x1478
/*     ddb8:	0c0126b0 */ 	jal	osRecvMesg
/*     ddbc:	00003025 */ 	or	$a2,$zero,$zero
/*     ddc0:	14400006 */ 	bnez	$v0,.NB0000dddc
/*     ddc4:	02202025 */ 	or	$a0,$s1,$zero
.NB0000ddc8:
/*     ddc8:	27a51478 */ 	addiu	$a1,$sp,0x1478
/*     ddcc:	0c0126b0 */ 	jal	osRecvMesg
/*     ddd0:	00003025 */ 	or	$a2,$zero,$zero
/*     ddd4:	5040fffc */ 	beqzl	$v0,.NB0000ddc8
/*     ddd8:	02202025 */ 	or	$a0,$s1,$zero
.NB0000dddc:
/*     dddc:	3c128006 */ 	lui	$s2,0x8006
/*     dde0:	00008025 */ 	or	$s0,$zero,$zero
/*     dde4:	2652f5e8 */ 	addiu	$s2,$s2,-2584
/*     dde8:	02202025 */ 	or	$a0,$s1,$zero
.NB0000ddec:
/*     ddec:	27a51478 */ 	addiu	$a1,$sp,0x1478
/*     ddf0:	0c0126b0 */ 	jal	osRecvMesg
/*     ddf4:	24060001 */ 	addiu	$a2,$zero,0x1
/*     ddf8:	8faa1478 */ 	lw	$t2,0x1478($sp)
/*     ddfc:	24010001 */ 	addiu	$at,$zero,0x1
/*     de00:	27ae1458 */ 	addiu	$t6,$sp,0x1458
/*     de04:	854b0000 */ 	lh	$t3,0x0($t2)
/*     de08:	5561000b */ 	bnel	$t3,$at,.NB0000de38
/*     de0c:	2a010006 */ 	slti	$at,$s0,0x6
/*     de10:	0c002871 */ 	jal	viUpdateMode
/*     de14:	afae0054 */ 	sw	$t6,0x54($sp)
/*     de18:	3c058006 */ 	lui	$a1,0x8006
/*     de1c:	24a5f610 */ 	addiu	$a1,$a1,-2544
/*     de20:	02402025 */ 	or	$a0,$s2,$zero
/*     de24:	00003025 */ 	or	$a2,$zero,$zero
/*     de28:	0c00c411 */ 	jal	rdpCreateTask
/*     de2c:	8fa70054 */ 	lw	$a3,0x54($sp)
/*     de30:	26100001 */ 	addiu	$s0,$s0,0x1
/*     de34:	2a010006 */ 	slti	$at,$s0,0x6
.NB0000de38:
/*     de38:	5420ffec */ 	bnezl	$at,.NB0000ddec
/*     de3c:	02202025 */ 	or	$a0,$s1,$zero
/*     de40:	10000004 */ 	beqz	$zero,.NB0000de54
/*     de44:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000de48:
/*     de48:	240f0001 */ 	addiu	$t7,$zero,0x1
/*     de4c:	3c018006 */ 	lui	$at,0x8006
/*     de50:	ac2ff2f4 */ 	sw	$t7,-0xd0c($at)
.NB0000de54:
/*     de54:	0c001c6c */ 	jal	vmInit
/*     de58:	00000000 */ 	sll	$zero,$zero,0x0
/*     de5c:	0fc68554 */ 	jal	func0f1a78b0
/*     de60:	00000000 */ 	sll	$zero,$zero,0x0
/*     de64:	0fc585fd */ 	jal	filesInit
/*     de68:	00000000 */ 	sll	$zero,$zero,0x0
/*     de6c:	0fc5c2fc */ 	jal	stub0f175f50
/*     de70:	00000000 */ 	sll	$zero,$zero,0x0
/*     de74:	0fc5c30c */ 	jal	func0f175f90
/*     de78:	00000000 */ 	sll	$zero,$zero,0x0
/*     de7c:	3c198006 */ 	lui	$t9,0x8006
/*     de80:	8f39f2d0 */ 	lw	$t9,-0xd30($t9)
/*     de84:	13200003 */ 	beqz	$t9,.NB0000de94
/*     de88:	3c047005 */ 	lui	$a0,0x7005
/*     de8c:	0c004dd3 */ 	jal	argSetString
/*     de90:	248450f0 */ 	addiu	$a0,$a0,0x50f0
.NB0000de94:
/*     de94:	3c04800b */ 	lui	$a0,0x800b
/*     de98:	0c013100 */ 	jal	osVirtualToPhysical
/*     de9c:	24841a70 */ 	addiu	$a0,$a0,0x1a70
/*     dea0:	3c038009 */ 	lui	$v1,0x8009
/*     dea4:	8c6330f0 */ 	lw	$v1,0x30f0($v1)
/*     dea8:	3c018000 */ 	lui	$at,0x8000
/*     deac:	00412025 */ 	or	$a0,$v0,$at
/*     deb0:	0c004996 */ 	jal	mempSetHeap
/*     deb4:	00642823 */ 	subu	$a1,$v1,$a0
/*     deb8:	0c004ab1 */ 	jal	mempResetPool
/*     debc:	24040008 */ 	addiu	$a0,$zero,0x8
/*     dec0:	0c004ab1 */ 	jal	mempResetPool
/*     dec4:	24040006 */ 	addiu	$a0,$zero,0x6
/*     dec8:	0c003535 */ 	jal	crashReset
/*     decc:	00000000 */ 	sll	$zero,$zero,0x0
/*     ded0:	0fc02bb0 */ 	jal	challengesInit
/*     ded4:	00000000 */ 	sll	$zero,$zero,0x0
/*     ded8:	0fc5c69f */ 	jal	utilsInit
/*     dedc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dee0:	0c000dbc */ 	jal	func000034d0
/*     dee4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dee8:	0fc02b90 */ 	jal	texInit
/*     deec:	00000000 */ 	sll	$zero,$zero,0x0
/*     def0:	0fc00000 */ 	jal	langInit
/*     def4:	00000000 */ 	sll	$zero,$zero,0x0
/*     def8:	0fc5890e */ 	jal	lvInit
/*     defc:	00000000 */ 	sll	$zero,$zero,0x0
/*     df00:	0fc40c5b */ 	jal	cheatsInit
/*     df04:	00000000 */ 	sll	$zero,$zero,0x0
/*     df08:	0c003c68 */ 	jal	func0000e9c0
/*     df0c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df10:	0fc53628 */ 	jal	textInit
/*     df14:	00000000 */ 	sll	$zero,$zero,0x0
/*     df18:	0c005002 */ 	jal	dhudInit
/*     df1c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df20:	0fc48954 */ 	jal	playermgrInit
/*     df24:	00000000 */ 	sll	$zero,$zero,0x0
/*     df28:	0fc59ef0 */ 	jal	frametimeInit
/*     df2c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df30:	0fc02bac */ 	jal	stub0f00b200
/*     df34:	00000000 */ 	sll	$zero,$zero,0x0
/*     df38:	0c002708 */ 	jal	profileInit
/*     df3c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df40:	0fc0021c */ 	jal	stub0f000870
/*     df44:	00000000 */ 	sll	$zero,$zero,0x0
/*     df48:	0fc00220 */ 	jal	smokesInit
/*     df4c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df50:	0fc00238 */ 	jal	stub0f0008e0
/*     df54:	00000000 */ 	sll	$zero,$zero,0x0
/*     df58:	0fc0023c */ 	jal	stub0f0008f0
/*     df5c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df60:	0fc00240 */ 	jal	stub0f000900
/*     df64:	00000000 */ 	sll	$zero,$zero,0x0
/*     df68:	0fc02b8c */ 	jal	stub0f00b180
/*     df6c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df70:	0fc00244 */ 	jal	stub0f000910
/*     df74:	00000000 */ 	sll	$zero,$zero,0x0
/*     df78:	0fc00210 */ 	jal	stub0f000840
/*     df7c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df80:	0fc60985 */ 	jal	mpInit
/*     df84:	00000000 */ 	sll	$zero,$zero,0x0
/*     df88:	0fc512be */ 	jal	pheadInit
/*     df8c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df90:	0fc44b4c */ 	jal	paksInit
/*     df94:	00000000 */ 	sll	$zero,$zero,0x0
/*     df98:	0fc512e3 */ 	jal	pheadInit2
/*     df9c:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfa0:	0c0091e8 */ 	jal	animsInit
/*     dfa4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfa8:	0fc00040 */ 	jal	racesInit
/*     dfac:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfb0:	0fc0004c */ 	jal	bodiesInit
/*     dfb4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfb8:	0fc00214 */ 	jal	stub0f000850
/*     dfbc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfc0:	0fc00218 */ 	jal	stub0f000860
/*     dfc4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfc8:	0fc00024 */ 	jal	titleInit
/*     dfcc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfd0:	0c002767 */ 	jal	viConfigureForLegal
/*     dfd4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfd8:	0c00281a */ 	jal	viBlack
/*     dfdc:	24040001 */ 	addiu	$a0,$zero,0x1
/*     dfe0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     dfe4:	3c018006 */ 	lui	$at,0x8006
/*     dfe8:	8fb00028 */ 	lw	$s0,0x28($sp)
/*     dfec:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*     dff0:	8fb20030 */ 	lw	$s2,0x30($sp)
/*     dff4:	ac20f638 */ 	sw	$zero,-0x9c8($at)
/*     dff8:	03e00008 */ 	jr	$ra
/*     dffc:	27bd14e0 */ 	addiu	$sp,$sp,0x14e0
);
#endif

u32 var8005dd3c = 0x00000000;
u32 var8005dd40 = 0x00000000;
u32 var8005dd44 = 0x00000000;
u32 var8005dd48 = 0x00000000;
u32 var8005dd4c = 0x00000000;
u32 var8005dd50 = 0x00000000;
s32 g_MainChangeToStageNum = -1;
bool g_MainIsDebugMenuOpen = false;

#if VERSION < VERSION_NTSC_1_0
void main000e000nb(void)
{
	var8005d9bc = true;
}

void main000e010nb(void)
{
	var8005d9c0 ^= 1;
}
#endif

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
 * It's suspected that this function would have allowed developers to override
 * the value of variables while the game is running in order to view their
 * effects immediately rather than having to recompile the game each time.
 *
 * The developers would have used rmon to create a table of name/value pairs,
 * then this function would have looked up the given variable name in the table
 * and written the new value to the variable's address.
 */
void mainOverrideVariable(char *name, void *value)
{
	// empty
}

#if VERSION >= VERSION_NTSC_1_0
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

	if (g_StageNum == STAGE_CITRAINING && IS4MB()) {
		g_StageNum = STAGE_4MBMENU;
	}

	rngSetSeed(osGetCount());

	// Outer loop - this is infinite because ending is never changed
	while (!ending) {
		g_MainNumGfxTasks = 0;
		g_MainGameLogicEnabled = true;
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
		dhudReset();
		mblurReset(g_StageNum);
		lvReset(g_StageNum);
		viReset(g_StageNum);
		frametimeCalculate();
		profileReset();

		while (osRecvMesg(&g_SchedMesgQueue, &msg, OS_MESG_NOBLOCK) != -1) {
			// empty
		}

		while (g_MainChangeToStageNum < 0 || g_MainNumGfxTasks != 0) {
			s32 cycles;

			osRecvMesg(&g_SchedMesgQueue, &msg, OS_MESG_BLOCK);

			switch (*(s16 *) msg) {
			case OS_SC_RETRACE_MSG:
				cycles = osGetCount() - g_Vars.thisframestartt;

				if (cycles >= g_Vars.mininc60 * CYCLES_PER_FRAME - CYCLES_PER_FRAME / 2) {
					mainTick();
				}
				break;
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
#else
const char mainrodata00[] = "-hard";
const char mainrodata01[] = "-hard";
const char mainrodata02[] = "-ma";
const char mainrodata03[] = "-ma";
const char mainrodata04[] = "-play";
const char mainrodata05[] = "-play";
const char mainrodata06[] = "-coop";
const char mainrodata07[] = "-anti";
const char mainrodata08[] = "-mpbots";
const char mainrodata09[] = "-play";
const char mainrodata10[] = "boss.c default: %08x type %d\n";

u32 var8005f670nb[] = {
	0x00020000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

GLOBAL_ASM(
glabel mainLoop
/*     e07c:	27bdff18 */ 	addiu	$sp,$sp,-232
/*     e080:	3c0f8006 */ 	lui	$t7,0x8006
/*     e084:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     e088:	afbe0038 */ 	sw	$s8,0x38($sp)
/*     e08c:	afb70034 */ 	sw	$s7,0x34($sp)
/*     e090:	afb60030 */ 	sw	$s6,0x30($sp)
/*     e094:	afb5002c */ 	sw	$s5,0x2c($sp)
/*     e098:	afb40028 */ 	sw	$s4,0x28($sp)
/*     e09c:	afb30024 */ 	sw	$s3,0x24($sp)
/*     e0a0:	afb20020 */ 	sw	$s2,0x20($sp)
/*     e0a4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     e0a8:	afb00018 */ 	sw	$s0,0x18($sp)
/*     e0ac:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*     e0b0:	25eff67c */ 	addiu	$t7,$t7,-2436
/*     e0b4:	8de10000 */ 	lw	$at,0x0($t7)
/*     e0b8:	8de80004 */ 	lw	$t0,0x4($t7)
/*     e0bc:	27ae00c4 */ 	addiu	$t6,$sp,0xc4
/*     e0c0:	adc10000 */ 	sw	$at,0x0($t6)
/*     e0c4:	adc80004 */ 	sw	$t0,0x4($t6)
/*     e0c8:	8de8000c */ 	lw	$t0,0xc($t7)
/*     e0cc:	8de10008 */ 	lw	$at,0x8($t7)
/*     e0d0:	3c04bc00 */ 	lui	$a0,0xbc00
/*     e0d4:	adc8000c */ 	sw	$t0,0xc($t6)
/*     e0d8:	adc10008 */ 	sw	$at,0x8($t6)
/*     e0dc:	8de10010 */ 	lw	$at,0x10($t7)
/*     e0e0:	8de80014 */ 	lw	$t0,0x14($t7)
/*     e0e4:	00001825 */ 	or	$v1,$zero,$zero
/*     e0e8:	adc10010 */ 	sw	$at,0x10($t6)
/*     e0ec:	adc80014 */ 	sw	$t0,0x14($t6)
/*     e0f0:	8de8001c */ 	lw	$t0,0x1c($t7)
/*     e0f4:	8de10018 */ 	lw	$at,0x18($t7)
/*     e0f8:	adc8001c */ 	sw	$t0,0x1c($t6)
/*     e0fc:	adc10018 */ 	sw	$at,0x18($t6)
/*     e100:	24024f4a */ 	addiu	$v0,$zero,0x4f4a
/*     e104:	24014f4a */ 	addiu	$at,$zero,0x4f4a
/*     e108:	10410007 */ 	beq	$v0,$at,.NB0000e128
/*     e10c:	24014c53 */ 	addiu	$at,$zero,0x4c53
/*     e110:	10410005 */ 	beq	$v0,$at,.NB0000e128
/*     e114:	2401504d */ 	addiu	$at,$zero,0x504d
/*     e118:	10410003 */ 	beq	$v0,$at,.NB0000e128
/*     e11c:	24014d50 */ 	addiu	$at,$zero,0x4d50
/*     e120:	54410008 */ 	bnel	$v0,$at,.NB0000e144
/*     e124:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0000e128:
/*     e128:	24024653 */ 	addiu	$v0,$zero,0x4653
/*     e12c:	24014653 */ 	addiu	$at,$zero,0x4653
/*     e130:	10410004 */ 	beq	$v0,$at,.NB0000e144
/*     e134:	24015245 */ 	addiu	$at,$zero,0x5245
/*     e138:	10410002 */ 	beq	$v0,$at,.NB0000e144
/*     e13c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e140:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0000e144:
/*     e144:	10600003 */ 	beqz	$v1,.NB0000e154
/*     e148:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e14c:
/*     e14c:	1000ffff */ 	beqz	$zero,.NB0000e14c
/*     e150:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e154:
/*     e154:	0fc5c30e */ 	jal	func0f175f98
/*     e158:	00000000 */ 	sll	$zero,$zero,0x0
/*     e15c:	3c018006 */ 	lui	$at,0x8006
/*     e160:	3c048006 */ 	lui	$a0,0x8006
/*     e164:	ac20f2e4 */ 	sw	$zero,-0xd1c($at)
/*     e168:	0c004e49 */ 	jal	argGetLevel
/*     e16c:	2484f2d4 */ 	addiu	$a0,$a0,-3372
/*     e170:	3c098006 */ 	lui	$t1,0x8006
/*     e174:	8d29f2f4 */ 	lw	$t1,-0xd0c($t1)
/*     e178:	3c028006 */ 	lui	$v0,0x8006
/*     e17c:	2442f2d4 */ 	addiu	$v0,$v0,-3372
/*     e180:	11200002 */ 	beqz	$t1,.NB0000e18c
/*     e184:	240a005b */ 	addiu	$t2,$zero,0x5b
/*     e188:	ac4a0000 */ 	sw	$t2,0x0($v0)
.NB0000e18c:
/*     e18c:	3c028006 */ 	lui	$v0,0x8006
/*     e190:	2442f2d4 */ 	addiu	$v0,$v0,-3372
/*     e194:	8c440000 */ 	lw	$a0,0x0($v0)
/*     e198:	2401005a */ 	addiu	$at,$zero,0x5a
/*     e19c:	10810016 */ 	beq	$a0,$at,.NB0000e1f8
/*     e1a0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e1a4:	0fc06ba1 */ 	jal	titleSetNextStage
/*     e1a8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e1ac:	3c0b8006 */ 	lui	$t3,0x8006
/*     e1b0:	8d6bf2d4 */ 	lw	$t3,-0xd2c($t3)
/*     e1b4:	2961005a */ 	slti	$at,$t3,0x5a
/*     e1b8:	1020000f */ 	beqz	$at,.NB0000e1f8
/*     e1bc:	00000000 */ 	sll	$zero,$zero,0x0
/*     e1c0:	0fc06b9e */ 	jal	func0f01b148
/*     e1c4:	00002025 */ 	or	$a0,$zero,$zero
/*     e1c8:	3c057005 */ 	lui	$a1,0x7005
/*     e1cc:	24a55124 */ 	addiu	$a1,$a1,0x5124
/*     e1d0:	0c004e18 */ 	jal	argFindByPrefix
/*     e1d4:	24040001 */ 	addiu	$a0,$zero,0x1
/*     e1d8:	10400007 */ 	beqz	$v0,.NB0000e1f8
/*     e1dc:	24040001 */ 	addiu	$a0,$zero,0x1
/*     e1e0:	3c057005 */ 	lui	$a1,0x7005
/*     e1e4:	0c004e18 */ 	jal	argFindByPrefix
/*     e1e8:	24a5512c */ 	addiu	$a1,$a1,0x512c
/*     e1ec:	90440000 */ 	lbu	$a0,0x0($v0)
/*     e1f0:	0fc59ed6 */ 	jal	lvSetDifficulty
/*     e1f4:	2484ffd0 */ 	addiu	$a0,$a0,-48
.NB0000e1f8:
/*     e1f8:	3c028006 */ 	lui	$v0,0x8006
/*     e1fc:	2442f2d4 */ 	addiu	$v0,$v0,-3372
/*     e200:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*     e204:	24010026 */ 	addiu	$at,$zero,0x26
/*     e208:	3c0d8009 */ 	lui	$t5,0x8009
/*     e20c:	15810007 */ 	bne	$t4,$at,.NB0000e22c
/*     e210:	00000000 */ 	sll	$zero,$zero,0x0
/*     e214:	91ad30e0 */ 	lbu	$t5,0x30e0($t5)
/*     e218:	24170001 */ 	addiu	$s7,$zero,0x1
/*     e21c:	2419005d */ 	addiu	$t9,$zero,0x5d
/*     e220:	16ed0002 */ 	bne	$s7,$t5,.NB0000e22c
/*     e224:	00000000 */ 	sll	$zero,$zero,0x0
/*     e228:	ac590000 */ 	sw	$t9,0x0($v0)
.NB0000e22c:
/*     e22c:	0c012638 */ 	jal	osGetCount
/*     e230:	24170001 */ 	addiu	$s7,$zero,0x1
/*     e234:	0c004d96 */ 	jal	rngSetSeed
/*     e238:	00402025 */ 	or	$a0,$v0,$zero
/*     e23c:	3c1e8006 */ 	lui	$s8,0x8006
/*     e240:	3c138009 */ 	lui	$s3,0x8009
/*     e244:	3c12800a */ 	lui	$s2,0x800a
/*     e248:	3c108006 */ 	lui	$s0,0x8006
/*     e24c:	2610f2ec */ 	addiu	$s0,$s0,-3348
/*     e250:	2652e6c0 */ 	addiu	$s2,$s2,-6464
/*     e254:	26730160 */ 	addiu	$s3,$s3,0x160
/*     e258:	27def674 */ 	addiu	$s8,$s8,-2444
/*     e25c:	2416ffff */ 	addiu	$s6,$zero,-1
/*     e260:	27b50058 */ 	addiu	$s5,$sp,0x58
/*     e264:	27b400b8 */ 	addiu	$s4,$sp,0xb8
.NB0000e268:
/*     e268:	ae000000 */ 	sw	$zero,0x0($s0)
/*     e26c:	3c188006 */ 	lui	$t8,0x8006
/*     e270:	8f18f2d0 */ 	lw	$t8,-0xd30($t8)
/*     e274:	3c018006 */ 	lui	$at,0x8006
/*     e278:	ac37f2e8 */ 	sw	$s7,-0xd18($at)
/*     e27c:	3c018006 */ 	lui	$at,0x8006
/*     e280:	afa000b8 */ 	sw	$zero,0xb8($sp)
/*     e284:	1300007e */ 	beqz	$t8,.NB0000e480
/*     e288:	ac20f2f0 */ 	sw	$zero,-0xd10($at)
/*     e28c:	3c0e8006 */ 	lui	$t6,0x8006
/*     e290:	8dcef2e4 */ 	lw	$t6,-0xd1c($t6)
/*     e294:	3c0f8009 */ 	lui	$t7,0x8009
/*     e298:	15c00079 */ 	bnez	$t6,.NB0000e480
/*     e29c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e2a0:	91ef30e0 */ 	lbu	$t7,0x30e0($t7)
/*     e2a4:	02c02825 */ 	or	$a1,$s6,$zero
/*     e2a8:	3c088006 */ 	lui	$t0,0x8006
/*     e2ac:	16ef003c */ 	bne	$s7,$t7,.NB0000e3a0
/*     e2b0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e2b4:	3c088006 */ 	lui	$t0,0x8006
/*     e2b8:	8d08f2d4 */ 	lw	$t0,-0xd2c($t0)
/*     e2bc:	2901005a */ 	slti	$at,$t0,0x5a
/*     e2c0:	1020001f */ 	beqz	$at,.NB0000e340
/*     e2c4:	00000000 */ 	sll	$zero,$zero,0x0
/*     e2c8:	0fc0681e */ 	jal	getNumPlayers
/*     e2cc:	afa500b4 */ 	sw	$a1,0xb4($sp)
/*     e2d0:	28410002 */ 	slti	$at,$v0,0x2
/*     e2d4:	1420001a */ 	bnez	$at,.NB0000e340
/*     e2d8:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*     e2dc:	3c098006 */ 	lui	$t1,0x8006
/*     e2e0:	8d29f4f0 */ 	lw	$t1,-0xb10($t1)
/*     e2e4:	3c068006 */ 	lui	$a2,0x8006
/*     e2e8:	24c6f4f0 */ 	addiu	$a2,$a2,-2832
/*     e2ec:	1120000e */ 	beqz	$t1,.NB0000e328
/*     e2f0:	00002825 */ 	or	$a1,$zero,$zero
/*     e2f4:	3c048006 */ 	lui	$a0,0x8006
/*     e2f8:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e2fc:	3c0a8006 */ 	lui	$t2,0x8006
/*     e300:	2542f4f0 */ 	addiu	$v0,$t2,-2832
/*     e304:	8c430000 */ 	lw	$v1,0x0($v0)
/*     e308:	24840190 */ 	addiu	$a0,$a0,0x190
.NB0000e30c:
/*     e30c:	50830007 */ 	beql	$a0,$v1,.NB0000e32c
/*     e310:	000558c0 */ 	sll	$t3,$a1,0x3
/*     e314:	8c430008 */ 	lw	$v1,0x8($v0)
/*     e318:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     e31c:	24420008 */ 	addiu	$v0,$v0,0x8
/*     e320:	1460fffa */ 	bnez	$v1,.NB0000e30c
/*     e324:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e328:
/*     e328:	000558c0 */ 	sll	$t3,$a1,0x3
.NB0000e32c:
/*     e32c:	00cb6021 */ 	addu	$t4,$a2,$t3
/*     e330:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*     e334:	15a00002 */ 	bnez	$t5,.NB0000e340
/*     e338:	00000000 */ 	sll	$zero,$zero,0x0
/*     e33c:	02c02825 */ 	or	$a1,$s6,$zero
.NB0000e340:
/*     e340:	3c068006 */ 	lui	$a2,0x8006
/*     e344:	04a10010 */ 	bgez	$a1,.NB0000e388
/*     e348:	24c6f4f0 */ 	addiu	$a2,$a2,-2832
/*     e34c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*     e350:	00002825 */ 	or	$a1,$zero,$zero
/*     e354:	3c048006 */ 	lui	$a0,0x8006
/*     e358:	1320000b */ 	beqz	$t9,.NB0000e388
/*     e35c:	3c188006 */ 	lui	$t8,0x8006
/*     e360:	2702f4f0 */ 	addiu	$v0,$t8,-2832
/*     e364:	8c430000 */ 	lw	$v1,0x0($v0)
/*     e368:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
.NB0000e36c:
/*     e36c:	50830007 */ 	beql	$a0,$v1,.NB0000e38c
/*     e370:	000570c0 */ 	sll	$t6,$a1,0x3
/*     e374:	8c430008 */ 	lw	$v1,0x8($v0)
/*     e378:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     e37c:	24420008 */ 	addiu	$v0,$v0,0x8
/*     e380:	1460fffa */ 	bnez	$v1,.NB0000e36c
/*     e384:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e388:
/*     e388:	000570c0 */ 	sll	$t6,$a1,0x3
.NB0000e38c:
/*     e38c:	00ce7821 */ 	addu	$t7,$a2,$t6
/*     e390:	0c004dd3 */ 	jal	argSetString
/*     e394:	8de40004 */ 	lw	$a0,0x4($t7)
/*     e398:	10000039 */ 	beqz	$zero,.NB0000e480
/*     e39c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e3a0:
/*     e3a0:	8d08f2d4 */ 	lw	$t0,-0xd2c($t0)
/*     e3a4:	2901005a */ 	slti	$at,$t0,0x5a
/*     e3a8:	1020001f */ 	beqz	$at,.NB0000e428
/*     e3ac:	00000000 */ 	sll	$zero,$zero,0x0
/*     e3b0:	0fc0681e */ 	jal	getNumPlayers
/*     e3b4:	afa500b4 */ 	sw	$a1,0xb4($sp)
/*     e3b8:	28410002 */ 	slti	$at,$v0,0x2
/*     e3bc:	1420001a */ 	bnez	$at,.NB0000e428
/*     e3c0:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*     e3c4:	3c098006 */ 	lui	$t1,0x8006
/*     e3c8:	8d29f2f8 */ 	lw	$t1,-0xd08($t1)
/*     e3cc:	3c068006 */ 	lui	$a2,0x8006
/*     e3d0:	24c6f2f8 */ 	addiu	$a2,$a2,-3336
/*     e3d4:	1120000e */ 	beqz	$t1,.NB0000e410
/*     e3d8:	00002825 */ 	or	$a1,$zero,$zero
/*     e3dc:	3c048006 */ 	lui	$a0,0x8006
/*     e3e0:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e3e4:	3c0a8006 */ 	lui	$t2,0x8006
/*     e3e8:	2542f2f8 */ 	addiu	$v0,$t2,-3336
/*     e3ec:	8c430000 */ 	lw	$v1,0x0($v0)
/*     e3f0:	24840190 */ 	addiu	$a0,$a0,0x190
.NB0000e3f4:
/*     e3f4:	50830007 */ 	beql	$a0,$v1,.NB0000e414
/*     e3f8:	000558c0 */ 	sll	$t3,$a1,0x3
/*     e3fc:	8c430008 */ 	lw	$v1,0x8($v0)
/*     e400:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     e404:	24420008 */ 	addiu	$v0,$v0,0x8
/*     e408:	1460fffa */ 	bnez	$v1,.NB0000e3f4
/*     e40c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e410:
/*     e410:	000558c0 */ 	sll	$t3,$a1,0x3
.NB0000e414:
/*     e414:	00cb6021 */ 	addu	$t4,$a2,$t3
/*     e418:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*     e41c:	15a00002 */ 	bnez	$t5,.NB0000e428
/*     e420:	00000000 */ 	sll	$zero,$zero,0x0
/*     e424:	02c02825 */ 	or	$a1,$s6,$zero
.NB0000e428:
/*     e428:	3c068006 */ 	lui	$a2,0x8006
/*     e42c:	04a10010 */ 	bgez	$a1,.NB0000e470
/*     e430:	24c6f2f8 */ 	addiu	$a2,$a2,-3336
/*     e434:	8cd90000 */ 	lw	$t9,0x0($a2)
/*     e438:	00002825 */ 	or	$a1,$zero,$zero
/*     e43c:	3c048006 */ 	lui	$a0,0x8006
/*     e440:	1320000b */ 	beqz	$t9,.NB0000e470
/*     e444:	3c188006 */ 	lui	$t8,0x8006
/*     e448:	2702f2f8 */ 	addiu	$v0,$t8,-3336
/*     e44c:	8c430000 */ 	lw	$v1,0x0($v0)
/*     e450:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
.NB0000e454:
/*     e454:	50830007 */ 	beql	$a0,$v1,.NB0000e474
/*     e458:	000570c0 */ 	sll	$t6,$a1,0x3
/*     e45c:	8c430008 */ 	lw	$v1,0x8($v0)
/*     e460:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     e464:	24420008 */ 	addiu	$v0,$v0,0x8
/*     e468:	1460fffa */ 	bnez	$v1,.NB0000e454
/*     e46c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e470:
/*     e470:	000570c0 */ 	sll	$t6,$a1,0x3
.NB0000e474:
/*     e474:	00ce7821 */ 	addu	$t7,$a2,$t6
/*     e478:	0c004dd3 */ 	jal	argSetString
/*     e47c:	8de40004 */ 	lw	$a0,0x4($t7)
.NB0000e480:
/*     e480:	3c018006 */ 	lui	$at,0x8006
/*     e484:	ac20f2e4 */ 	sw	$zero,-0xd1c($at)
/*     e488:	0c004ab1 */ 	jal	mempResetPool
/*     e48c:	24040007 */ 	addiu	$a0,$zero,0x7
/*     e490:	0c004ab1 */ 	jal	mempResetPool
/*     e494:	24040004 */ 	addiu	$a0,$zero,0x4
/*     e498:	0fc58709 */ 	jal	filesStop
/*     e49c:	24040004 */ 	addiu	$a0,$zero,0x4
/*     e4a0:	3c057005 */ 	lui	$a1,0x7005
/*     e4a4:	24a55134 */ 	addiu	$a1,$a1,0x5134
/*     e4a8:	0c004e18 */ 	jal	argFindByPrefix
/*     e4ac:	02e02025 */ 	or	$a0,$s7,$zero
/*     e4b0:	1040000b */ 	beqz	$v0,.NB0000e4e0
/*     e4b4:	02e02025 */ 	or	$a0,$s7,$zero
/*     e4b8:	3c057005 */ 	lui	$a1,0x7005
/*     e4bc:	0c004e18 */ 	jal	argFindByPrefix
/*     e4c0:	24a55138 */ 	addiu	$a1,$a1,0x5138
/*     e4c4:	00402025 */ 	or	$a0,$v0,$zero
/*     e4c8:	00002825 */ 	or	$a1,$zero,$zero
/*     e4cc:	0c004f16 */ 	jal	strtol
/*     e4d0:	00003025 */ 	or	$a2,$zero,$zero
/*     e4d4:	00024280 */ 	sll	$t0,$v0,0xa
/*     e4d8:	3c018006 */ 	lui	$at,0x8006
/*     e4dc:	ac28f2d8 */ 	sw	$t0,-0xd28($at)
.NB0000e4e0:
/*     e4e0:	3c048006 */ 	lui	$a0,0x8006
/*     e4e4:	8c84f2d8 */ 	lw	$a0,-0xd28($a0)
/*     e4e8:	0c004a0e */ 	jal	mempAlloc
/*     e4ec:	24050004 */ 	addiu	$a1,$zero,0x4
/*     e4f0:	3c058006 */ 	lui	$a1,0x8006
/*     e4f4:	8ca5f2d8 */ 	lw	$a1,-0xd28($a1)
/*     e4f8:	0c004bed */ 	jal	memaReset
/*     e4fc:	00402025 */ 	or	$a0,$v0,$zero
/*     e500:	3c048006 */ 	lui	$a0,0x8006
/*     e504:	0fc02bf4 */ 	jal	langReset
/*     e508:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e50c:	0fc48964 */ 	jal	playermgrReset
/*     e510:	00000000 */ 	sll	$zero,$zero,0x0
/*     e514:	3c098006 */ 	lui	$t1,0x8006
/*     e518:	8d29f2d4 */ 	lw	$t1,-0xd2c($t1)
/*     e51c:	02e02025 */ 	or	$a0,$s7,$zero
/*     e520:	3c057005 */ 	lui	$a1,0x7005
/*     e524:	2921005a */ 	slti	$at,$t1,0x5a
/*     e528:	14200003 */ 	bnez	$at,.NB0000e538
/*     e52c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e530:	10000017 */ 	beqz	$zero,.NB0000e590
/*     e534:	00008825 */ 	or	$s1,$zero,$zero
.NB0000e538:
/*     e538:	0c004e18 */ 	jal	argFindByPrefix
/*     e53c:	24a5513c */ 	addiu	$a1,$a1,0x513c
/*     e540:	1040000b */ 	beqz	$v0,.NB0000e570
/*     e544:	02e08825 */ 	or	$s1,$s7,$zero
/*     e548:	3c057005 */ 	lui	$a1,0x7005
/*     e54c:	24a55144 */ 	addiu	$a1,$a1,0x5144
/*     e550:	0c004e18 */ 	jal	argFindByPrefix
/*     e554:	02e02025 */ 	or	$a0,$s7,$zero
/*     e558:	00402025 */ 	or	$a0,$v0,$zero
/*     e55c:	00002825 */ 	or	$a1,$zero,$zero
/*     e560:	0c004f16 */ 	jal	strtol
/*     e564:	00003025 */ 	or	$a2,$zero,$zero
/*     e568:	10000001 */ 	beqz	$zero,.NB0000e570
/*     e56c:	00408825 */ 	or	$s1,$v0,$zero
.NB0000e570:
/*     e570:	0fc0681e */ 	jal	getNumPlayers
/*     e574:	00000000 */ 	sll	$zero,$zero,0x0
/*     e578:	28410002 */ 	slti	$at,$v0,0x2
/*     e57c:	54200005 */ 	bnezl	$at,.NB0000e594
/*     e580:	2a210002 */ 	slti	$at,$s1,0x2
/*     e584:	0fc0681e */ 	jal	getNumPlayers
/*     e588:	00000000 */ 	sll	$zero,$zero,0x0
/*     e58c:	00408825 */ 	or	$s1,$v0,$zero
.NB0000e590:
/*     e590:	2a210002 */ 	slti	$at,$s1,0x2
.NB0000e594:
/*     e594:	10200005 */ 	beqz	$at,.NB0000e5ac
/*     e598:	02e02025 */ 	or	$a0,$s7,$zero
/*     e59c:	ae400294 */ 	sw	$zero,0x294($s2)
/*     e5a0:	ae560298 */ 	sw	$s6,0x298($s2)
/*     e5a4:	10000012 */ 	beqz	$zero,.NB0000e5f0
/*     e5a8:	ae56029c */ 	sw	$s6,0x29c($s2)
.NB0000e5ac:
/*     e5ac:	3c057005 */ 	lui	$a1,0x7005
/*     e5b0:	0c004e18 */ 	jal	argFindByPrefix
/*     e5b4:	24a5514c */ 	addiu	$a1,$a1,0x514c
/*     e5b8:	10400005 */ 	beqz	$v0,.NB0000e5d0
/*     e5bc:	02e02025 */ 	or	$a0,$s7,$zero
/*     e5c0:	ae400294 */ 	sw	$zero,0x294($s2)
/*     e5c4:	ae570298 */ 	sw	$s7,0x298($s2)
/*     e5c8:	10000009 */ 	beqz	$zero,.NB0000e5f0
/*     e5cc:	ae56029c */ 	sw	$s6,0x29c($s2)
.NB0000e5d0:
/*     e5d0:	3c057005 */ 	lui	$a1,0x7005
/*     e5d4:	0c004e18 */ 	jal	argFindByPrefix
/*     e5d8:	24a55154 */ 	addiu	$a1,$a1,0x5154
/*     e5dc:	10400004 */ 	beqz	$v0,.NB0000e5f0
/*     e5e0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e5e4:	ae400294 */ 	sw	$zero,0x294($s2)
/*     e5e8:	ae560298 */ 	sw	$s6,0x298($s2)
/*     e5ec:	ae57029c */ 	sw	$s7,0x29c($s2)
.NB0000e5f0:
/*     e5f0:	0fc48979 */ 	jal	playermgrAllocatePlayers
/*     e5f4:	02202025 */ 	or	$a0,$s1,$zero
/*     e5f8:	3c057005 */ 	lui	$a1,0x7005
/*     e5fc:	24a5515c */ 	addiu	$a1,$a1,0x515c
/*     e600:	0c004e18 */ 	jal	argFindByPrefix
/*     e604:	02e02025 */ 	or	$a0,$s7,$zero
/*     e608:	10400002 */ 	beqz	$v0,.NB0000e614
/*     e60c:	240c0003 */ 	addiu	$t4,$zero,0x3
/*     e610:	ae57031c */ 	sw	$s7,0x31c($s2)
.NB0000e614:
/*     e614:	8e4a0298 */ 	lw	$t2,0x298($s2)
/*     e618:	3c01800b */ 	lui	$at,0x800b
/*     e61c:	05410004 */ 	bgez	$t2,.NB0000e630
/*     e620:	00000000 */ 	sll	$zero,$zero,0x0
/*     e624:	8e4b029c */ 	lw	$t3,0x29c($s2)
/*     e628:	05620006 */ 	bltzl	$t3,.NB0000e644
/*     e62c:	8e4d0470 */ 	lw	$t5,0x470($s2)
.NB0000e630:
/*     e630:	0fc60755 */ 	jal	mpReset
/*     e634:	a42c144e */ 	sh	$t4,0x144e($at)
/*     e638:	10000033 */ 	beqz	$zero,.NB0000e708
/*     e63c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e640:	8e4d0470 */ 	lw	$t5,0x470($s2)
.NB0000e644:
/*     e644:	51a00006 */ 	beqzl	$t5,.NB0000e660
/*     e648:	8e590314 */ 	lw	$t9,0x314($s2)
/*     e64c:	0fc60755 */ 	jal	mpReset
/*     e650:	00000000 */ 	sll	$zero,$zero,0x0
/*     e654:	1000002c */ 	beqz	$zero,.NB0000e708
/*     e658:	00000000 */ 	sll	$zero,$zero,0x0
/*     e65c:	8e590314 */ 	lw	$t9,0x314($s2)
.NB0000e660:
/*     e660:	2a210002 */ 	slti	$at,$s1,0x2
/*     e664:	17200028 */ 	bnez	$t9,.NB0000e708
/*     e668:	00000000 */ 	sll	$zero,$zero,0x0
/*     e66c:	5020000a */ 	beqzl	$at,.NB0000e698
/*     e670:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     e674:	8e58031c */ 	lw	$t8,0x31c($s2)
/*     e678:	02e02025 */ 	or	$a0,$s7,$zero
/*     e67c:	3c057005 */ 	lui	$a1,0x7005
/*     e680:	57000005 */ 	bnezl	$t8,.NB0000e698
/*     e684:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     e688:	0c004e18 */ 	jal	argFindByPrefix
/*     e68c:	24a55164 */ 	addiu	$a1,$a1,0x5164
/*     e690:	1040001d */ 	beqz	$v0,.NB0000e708
/*     e694:	240e0001 */ 	addiu	$t6,$zero,0x1
.NB0000e698:
/*     e698:	3c01800b */ 	lui	$at,0x800b
/*     e69c:	a42e144e */ 	sh	$t6,0x144e($at)
/*     e6a0:	2a210002 */ 	slti	$at,$s1,0x2
/*     e6a4:	14200006 */ 	bnez	$at,.NB0000e6c0
/*     e6a8:	3c0d8006 */ 	lui	$t5,0x8006
/*     e6ac:	3c02800b */ 	lui	$v0,0x800b
/*     e6b0:	24421438 */ 	addiu	$v0,$v0,0x1438
/*     e6b4:	944f0016 */ 	lhu	$t7,0x16($v0)
/*     e6b8:	35e80002 */ 	ori	$t0,$t7,0x2
/*     e6bc:	a4480016 */ 	sh	$t0,0x16($v0)
.NB0000e6c0:
/*     e6c0:	2a210003 */ 	slti	$at,$s1,0x3
/*     e6c4:	14200005 */ 	bnez	$at,.NB0000e6dc
/*     e6c8:	3c02800b */ 	lui	$v0,0x800b
/*     e6cc:	24421438 */ 	addiu	$v0,$v0,0x1438
/*     e6d0:	94490016 */ 	lhu	$t1,0x16($v0)
/*     e6d4:	352a0004 */ 	ori	$t2,$t1,0x4
/*     e6d8:	a44a0016 */ 	sh	$t2,0x16($v0)
.NB0000e6dc:
/*     e6dc:	2a210004 */ 	slti	$at,$s1,0x4
/*     e6e0:	14200005 */ 	bnez	$at,.NB0000e6f8
/*     e6e4:	3c0b800b */ 	lui	$t3,0x800b
/*     e6e8:	956b144e */ 	lhu	$t3,0x144e($t3)
/*     e6ec:	3c01800b */ 	lui	$at,0x800b
/*     e6f0:	356c0008 */ 	ori	$t4,$t3,0x8
/*     e6f4:	a42c144e */ 	sh	$t4,0x144e($at)
.NB0000e6f8:
/*     e6f8:	8dadf2d4 */ 	lw	$t5,-0xd2c($t5)
/*     e6fc:	3c01800b */ 	lui	$at,0x800b
/*     e700:	0fc60755 */ 	jal	mpReset
/*     e704:	a02d1449 */ 	sb	$t5,0x1449($at)
.NB0000e708:
/*     e708:	0fc58724 */ 	jal	gfxReset
/*     e70c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e710:	0c005310 */ 	jal	joyReset
/*     e714:	00000000 */ 	sll	$zero,$zero,0x0
/*     e718:	0c005049 */ 	jal	dhudReset
/*     e71c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e720:	3c048006 */ 	lui	$a0,0x8006
/*     e724:	0fc5c34b */ 	jal	mblurReset
/*     e728:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e72c:	3c048006 */ 	lui	$a0,0x8006
/*     e730:	0fc589ee */ 	jal	lvReset
/*     e734:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e738:	3c048006 */ 	lui	$a0,0x8006
/*     e73c:	0c002778 */ 	jal	viReset
/*     e740:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e744:	0fc59f11 */ 	jal	frametimeCalculate
/*     e748:	00000000 */ 	sll	$zero,$zero,0x0
/*     e74c:	0c00270c */ 	jal	profileReset
/*     e750:	00000000 */ 	sll	$zero,$zero,0x0
/*     e754:	02602025 */ 	or	$a0,$s3,$zero
/*     e758:	02802825 */ 	or	$a1,$s4,$zero
/*     e75c:	0c0126b0 */ 	jal	osRecvMesg
/*     e760:	00003025 */ 	or	$a2,$zero,$zero
/*     e764:	10560006 */ 	beq	$v0,$s6,.NB0000e780
/*     e768:	02602025 */ 	or	$a0,$s3,$zero
.NB0000e76c:
/*     e76c:	02802825 */ 	or	$a1,$s4,$zero
/*     e770:	0c0126b0 */ 	jal	osRecvMesg
/*     e774:	00003025 */ 	or	$a2,$zero,$zero
/*     e778:	5456fffc */ 	bnel	$v0,$s6,.NB0000e76c
/*     e77c:	02602025 */ 	or	$a0,$s3,$zero
.NB0000e780:
/*     e780:	8fd90000 */ 	lw	$t9,0x0($s8)
/*     e784:	07220004 */ 	bltzl	$t9,.NB0000e798
/*     e788:	02602025 */ 	or	$a0,$s3,$zero
/*     e78c:	8e180000 */ 	lw	$t8,0x0($s0)
/*     e790:	13000038 */ 	beqz	$t8,.NB0000e874
/*     e794:	02602025 */ 	or	$a0,$s3,$zero
.NB0000e798:
/*     e798:	02802825 */ 	or	$a1,$s4,$zero
/*     e79c:	0c0126b0 */ 	jal	osRecvMesg
/*     e7a0:	02e03025 */ 	or	$a2,$s7,$zero
/*     e7a4:	0c0006fd */ 	jal	bootCheckStackOverflow
/*     e7a8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e7ac:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*     e7b0:	24010002 */ 	addiu	$at,$zero,0x2
/*     e7b4:	85c70000 */ 	lh	$a3,0x0($t6)
/*     e7b8:	10f70007 */ 	beq	$a3,$s7,.NB0000e7d8
/*     e7bc:	00000000 */ 	sll	$zero,$zero,0x0
/*     e7c0:	10e10018 */ 	beq	$a3,$at,.NB0000e824
/*     e7c4:	24010005 */ 	addiu	$at,$zero,0x5
/*     e7c8:	10e1001a */ 	beq	$a3,$at,.NB0000e834
/*     e7cc:	240d0004 */ 	addiu	$t5,$zero,0x4
/*     e7d0:	1000001a */ 	beqz	$zero,.NB0000e83c
/*     e7d4:	02a02025 */ 	or	$a0,$s5,$zero
.NB0000e7d8:
/*     e7d8:	0c012638 */ 	jal	osGetCount
/*     e7dc:	00000000 */ 	sll	$zero,$zero,0x0
/*     e7e0:	8e480028 */ 	lw	$t0,0x28($s2)
/*     e7e4:	3c01000b */ 	lui	$at,0xb
/*     e7e8:	3421ebc2 */ 	ori	$at,$at,0xebc2
/*     e7ec:	01010019 */ 	multu	$t0,$at
/*     e7f0:	8e4f0018 */ 	lw	$t7,0x18($s2)
/*     e7f4:	3c01fffa */ 	lui	$at,0xfffa
/*     e7f8:	34210a1f */ 	ori	$at,$at,0xa1f
/*     e7fc:	004f1823 */ 	subu	$v1,$v0,$t7
/*     e800:	00004812 */ 	mflo	$t1
/*     e804:	01215021 */ 	addu	$t2,$t1,$at
/*     e808:	006a082b */ 	sltu	$at,$v1,$t2
/*     e80c:	54200014 */ 	bnezl	$at,.NB0000e860
/*     e810:	8fd80000 */ 	lw	$t8,0x0($s8)
/*     e814:	0c003a3b */ 	jal	mainTick
/*     e818:	00000000 */ 	sll	$zero,$zero,0x0
/*     e81c:	10000010 */ 	beqz	$zero,.NB0000e860
/*     e820:	8fd80000 */ 	lw	$t8,0x0($s8)
.NB0000e824:
/*     e824:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*     e828:	256cffff */ 	addiu	$t4,$t3,-1
/*     e82c:	1000000b */ 	beqz	$zero,.NB0000e85c
/*     e830:	ae0c0000 */ 	sw	$t4,0x0($s0)
.NB0000e834:
/*     e834:	10000009 */ 	beqz	$zero,.NB0000e85c
/*     e838:	ae0d0000 */ 	sw	$t5,0x0($s0)
.NB0000e83c:
/*     e83c:	3c057005 */ 	lui	$a1,0x7005
/*     e840:	24a5516c */ 	addiu	$a1,$a1,0x516c
/*     e844:	0c004fc1 */ 	jal	sprintf
/*     e848:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*     e84c:	0c003074 */ 	jal	crashSetMessage
/*     e850:	02a02025 */ 	or	$a0,$s5,$zero
/*     e854:	24190045 */ 	addiu	$t9,$zero,0x45
/*     e858:	a0190000 */ 	sb	$t9,0x0($zero)
.NB0000e85c:
/*     e85c:	8fd80000 */ 	lw	$t8,0x0($s8)
.NB0000e860:
/*     e860:	0702ffcd */ 	bltzl	$t8,.NB0000e798
/*     e864:	02602025 */ 	or	$a0,$s3,$zero
/*     e868:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*     e86c:	55c0ffca */ 	bnezl	$t6,.NB0000e798
/*     e870:	02602025 */ 	or	$a0,$s3,$zero
.NB0000e874:
/*     e874:	0fc59e56 */ 	jal	lvStop
/*     e878:	00000000 */ 	sll	$zero,$zero,0x0
/*     e87c:	0c004acc */ 	jal	mempDisablePool
/*     e880:	24040004 */ 	addiu	$a0,$zero,0x4
/*     e884:	0c004acc */ 	jal	mempDisablePool
/*     e888:	24040007 */ 	addiu	$a0,$zero,0x7
/*     e88c:	0fc58709 */ 	jal	filesStop
/*     e890:	24040004 */ 	addiu	$a0,$zero,0x4
/*     e894:	0c00281a */ 	jal	viBlack
/*     e898:	02e02025 */ 	or	$a0,$s7,$zero
/*     e89c:	8fcf0000 */ 	lw	$t7,0x0($s8)
/*     e8a0:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*     e8a4:	3c018006 */ 	lui	$at,0x8006
/*     e8a8:	ac2ff2d4 */ 	sw	$t7,-0xd2c($at)
/*     e8ac:	1100fe6e */ 	beqz	$t0,.NB0000e268
/*     e8b0:	afd60000 */ 	sw	$s6,0x0($s8)
/*     e8b4:	0fc5c31a */ 	jal	func0f175fc8
/*     e8b8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e8bc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     e8c0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     e8c4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     e8c8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     e8cc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     e8d0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     e8d4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*     e8d8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*     e8dc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*     e8e0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*     e8e4:	03e00008 */ 	jr	$ra
/*     e8e8:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
);
#endif

void mainTick(void)
{
	Gfx *gdl;
	Gfx *gdlstart;
	OSScMsg msg = {OS_SC_DONE_MSG};
	s32 i;

	if (g_MainChangeToStageNum < 0 && g_MainNumGfxTasks < 2) {
		frametimeCalculate();
		profile00009a98();
		profileReset();
		profileSetMarker(PROFILE_MAINTICK_START);
		func000034d8();
		joyDebugJoy();
		schedSetCrashEnable2(false);

		if (g_MainGameLogicEnabled) {
			gdl = gdlstart = gfxGetMasterDisplayList();

			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
			if (g_MainIsDebugMenuOpen || joyGetButtons(0, U_CBUTTONS | D_CBUTTONS) == (U_CBUTTONS | D_CBUTTONS)) {
				g_MainIsDebugMenuOpen = debugProcessInput(joyGetStickX(0), joyGetStickY(0), joyGetButtons(0, 0xffff), joyGetButtonsPressedThisFrame(0, 0xffff));
			} else if (joyGetButtons(0, START_BUTTON) == 0) {
				var80075d68 = var800786f4nb;
			} else {
				g_MainIsDebugMenuOpen = debugProcessInput(joyGetStickX(0), joyGetStickY(0), joyGetButtons(0, 0xffff), joyGetButtonsPressedThisFrame(0, 0xffff));
			}
#endif

			lvTick();
			playermgrShuffle();

			if (g_StageNum < STAGE_TITLE) {
				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(playermgrGetPlayerAtOrder(i));

					if (g_StageNum != STAGE_TEST_OLD || !titleIsKeepingMode()) {
						viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
						viSetFovAspectAndSize(
								g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
								g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
					}

					lvTickPlayer();
				}
			}

			gdl = lvRender(gdl);
			func000034e0(&gdl);

#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
			if (debugIsLineModeEnabled()) {
				gDPPipeSync(gdl++);
				gDPSetCycleType(gdl++, G_CYC_1CYCLE);
				gDPSetBlendColor(gdl++, 0xff, 0xff, 0xff, 0xff);
				gDPSetPrimDepth(gdl++, 0xffff, 0xffff);
				gDPSetDepthSource(gdl++, G_ZS_PRIM);
				gDPSetRenderMode(gdl++, G_RM_VISCVG, G_RM_VISCVG2);
				gDPFillRectangle(gdl++, 0, 0, viGetWidth() - 1, viGetHeight() - 1);
			}

			gdl = dhudRender(gdl);
			dhudClear();
#endif

			if (debug0f11ed70() >= 2) {
				gdl = profileRender(gdl);
			}

#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
			if (g_MainIsDebugMenuOpen) {
				debugUpdateMenu();
				gdl = dmenuRender(gdl);
			}
#endif

			gDPFullSync(gdl++);
			gSPEndDisplayList(gdl++);
		}

		if (g_MainGameLogicEnabled) {
			gfxSwapBuffers();
			viUpdateMode();
		}

		rdpCreateTask(gdlstart, gdl, 0, &msg);
		g_MainNumGfxTasks++;
		memaPrint();
		func0f16cf94();
		profileSetMarker(PROFILE_MAINTICK_END);

#if VERSION == VERSION_PAL_BETA
		debug0f119a80nb();
#endif
	}
}

void mainEndStage(void)
{
	sndStopNosedive();

	if (!g_MainIsEndscreen) {
#if VERSION >= VERSION_NTSC_1_0
		pak0f11c6d0();
#endif
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
#if VERSION >= VERSION_NTSC_1_0
	pak0f11c6d0();
#endif

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

void func0000e9c0(void)
{
	// empty
}
