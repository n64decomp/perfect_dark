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

#define DEBUGOPT_PROPS         32
#define DEBUGOPT_PADS          40
#define DEBUGOPT_44            44
#define DEBUGOPT_ALLTRAINING   29
#define DEBUGOPT_TILES         39
#define DEBUGOPT_ALLLEVELS     13
#define DEBUGOPT_CHRSTATS      65
#define DEBUGOPT_ALLCHALLENGES 67
#define DEBUGOPT_VMSTATS       69
#define DEBUGOPT_MEMINFO       70
#define DEBUGOPT_ALLBUDDIES    94
#define DEBUGOPT_MANPOS        101

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
bool g_DebugAllTraining = false;
s32 var800787a4nb = 0;
s32 var800787a8nb = 0;
bool g_DebugMemInfo = false;
s32 var800787b0nb = 0;
s32 var800787b4nb = 0;
s32 var800787b8nb = 0;
s32 var800787bcnb = 0;
s32 var800787c0nb = 0;
#if VERSION == VERSION_PAL_BETA
s32 var800781f0pb = 0;
#endif
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

#if VERSION == VERSION_PAL_BETA
GLOBAL_ASM(
glabel debugProcessInput
.late_rodata
glabel var7f1b6f38pb
.word 0x7f1200b8
.word 0x7f120158
.word 0x7f120040
.word 0x7f120058
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120010
.word 0x7f120028
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f120158
.word 0x7f11fff8
.text
/*  f11fd9c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f11fda0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11fda4:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f11fda8:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f11fdac:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f11fdb0:	0fc47ee8 */ 	jal	0xf11fba0
/*  f11fdb4:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f11fdb8:	3c048008 */ 	lui	$a0,0x8008
/*  f11fdbc:	24848244 */ 	addiu	$a0,$a0,-32188
/*  f11fdc0:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f11fdc4:	24060003 */ 	li	$a2,0x3
/*  f11fdc8:	1040000b */ 	beqz	$v0,.PB0f11fdf8
/*  f11fdcc:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f11fdd0:	14c20009 */ 	bne	$a2,$v0,.PB0f11fdf8
/*  f11fdd4:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f11fdd8:	0c002f34 */ 	jal	0xbcd0
/*  f11fddc:	00000000 */ 	nop
/*  f11fde0:	3c048008 */ 	lui	$a0,0x8008
/*  f11fde4:	24848244 */ 	addiu	$a0,$a0,-32188
/*  f11fde8:	0c002a0b */ 	jal	0xa82c
/*  f11fdec:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f11fdf0:	0c0124a8 */ 	jal	0x492a0
/*  f11fdf4:	00002025 */ 	move	$a0,$zero
.PB0f11fdf8:
/*  f11fdf8:	3c048008 */ 	lui	$a0,0x8008
/*  f11fdfc:	24848248 */ 	addiu	$a0,$a0,-32184
/*  f11fe00:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f11fe04:	24060003 */ 	li	$a2,0x3
/*  f11fe08:	1040000b */ 	beqz	$v0,.PB0f11fe38
/*  f11fe0c:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f11fe10:	14c20009 */ 	bne	$a2,$v0,.PB0f11fe38
/*  f11fe14:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f11fe18:	0c002f30 */ 	jal	0xbcc0
/*  f11fe1c:	00000000 */ 	nop
/*  f11fe20:	3c048008 */ 	lui	$a0,0x8008
/*  f11fe24:	24848248 */ 	addiu	$a0,$a0,-32184
/*  f11fe28:	0c002a0b */ 	jal	0xa82c
/*  f11fe2c:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f11fe30:	0c0124a8 */ 	jal	0x492a0
/*  f11fe34:	00002025 */ 	move	$a0,$zero
.PB0f11fe38:
/*  f11fe38:	3c188008 */ 	lui	$t8,0x8008
/*  f11fe3c:	8f18824c */ 	lw	$t8,-0x7db4($t8)
/*  f11fe40:	3c048007 */ 	lui	$a0,0x8007
/*  f11fe44:	3c018008 */ 	lui	$at,0x8008
/*  f11fe48:	1700000c */ 	bnez	$t8,.PB0f11fe7c
/*  f11fe4c:	24847b78 */ 	addiu	$a0,$a0,0x7b78
/*  f11fe50:	97a4003a */ 	lhu	$a0,0x3a($sp)
/*  f11fe54:	30820008 */ 	andi	$v0,$a0,0x8
/*  f11fe58:	0002182b */ 	sltu	$v1,$zero,$v0
/*  f11fe5c:	10600004 */ 	beqz	$v1,.PB0f11fe70
/*  f11fe60:	00000000 */ 	nop
/*  f11fe64:	30830004 */ 	andi	$v1,$a0,0x4
/*  f11fe68:	0003402b */ 	sltu	$t0,$zero,$v1
/*  f11fe6c:	01001825 */ 	move	$v1,$t0
.PB0f11fe70:
/*  f11fe70:	ac23824c */ 	sw	$v1,-0x7db4($at)
/*  f11fe74:	100000c9 */ 	b	.PB0f12019c
/*  f11fe78:	00601025 */ 	move	$v0,$v1
.PB0f11fe7c:
/*  f11fe7c:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f11fe80:	2403fffe */ 	li	$v1,-2
/*  f11fe84:	3c018007 */ 	lui	$at,0x8007
/*  f11fe88:	50620004 */ 	beql	$v1,$v0,.PB0f11fe9c
/*  f11fe8c:	97a9003e */ 	lhu	$t1,0x3e($sp)
/*  f11fe90:	ac227b7c */ 	sw	$v0,0x7b7c($at)
/*  f11fe94:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f11fe98:	97a9003e */ 	lhu	$t1,0x3e($sp)
.PB0f11fe9c:
/*  f11fe9c:	312a0200 */ 	andi	$t2,$t1,0x200
/*  f11fea0:	11400007 */ 	beqz	$t2,.PB0f11fec0
/*  f11fea4:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f11fea8:	0fc47ea9 */ 	jal	0xf11faa4
/*  f11feac:	00000000 */ 	nop
/*  f11feb0:	3c048007 */ 	lui	$a0,0x8007
/*  f11feb4:	24847b78 */ 	addiu	$a0,$a0,0x7b78
/*  f11feb8:	2403fffe */ 	li	$v1,-2
/*  f11febc:	ac830000 */ 	sw	$v1,0x0($a0)
.PB0f11fec0:
/*  f11fec0:	8fab001c */ 	lw	$t3,0x1c($sp)
/*  f11fec4:	316c0100 */ 	andi	$t4,$t3,0x100
/*  f11fec8:	51800008 */ 	beqzl	$t4,.PB0f11feec
/*  f11fecc:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f11fed0:	0fc47e6c */ 	jal	0xf11f9b0
/*  f11fed4:	00000000 */ 	nop
/*  f11fed8:	3c048007 */ 	lui	$a0,0x8007
/*  f11fedc:	24847b78 */ 	addiu	$a0,$a0,0x7b78
/*  f11fee0:	2403fffe */ 	li	$v1,-2
/*  f11fee4:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f11fee8:	8fad001c */ 	lw	$t5,0x1c($sp)
.PB0f11feec:
/*  f11feec:	31ae0800 */ 	andi	$t6,$t5,0x800
/*  f11fef0:	51c00008 */ 	beqzl	$t6,.PB0f11ff14
/*  f11fef4:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f11fef8:	0fc47e2e */ 	jal	0xf11f8b8
/*  f11fefc:	00000000 */ 	nop
/*  f11ff00:	3c048007 */ 	lui	$a0,0x8007
/*  f11ff04:	24847b78 */ 	addiu	$a0,$a0,0x7b78
/*  f11ff08:	2403fffe */ 	li	$v1,-2
/*  f11ff0c:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f11ff10:	8faf001c */ 	lw	$t7,0x1c($sp)
.PB0f11ff14:
/*  f11ff14:	31f80400 */ 	andi	$t8,$t7,0x400
/*  f11ff18:	53000008 */ 	beqzl	$t8,.PB0f11ff3c
/*  f11ff1c:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f11ff20:	0fc47e4e */ 	jal	0xf11f938
/*  f11ff24:	00000000 */ 	nop
/*  f11ff28:	3c048007 */ 	lui	$a0,0x8007
/*  f11ff2c:	24847b78 */ 	addiu	$a0,$a0,0x7b78
/*  f11ff30:	2403fffe */ 	li	$v1,-2
/*  f11ff34:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f11ff38:	8fb9001c */ 	lw	$t9,0x1c($sp)
.PB0f11ff3c:
/*  f11ff3c:	3c028008 */ 	lui	$v0,0x8008
/*  f11ff40:	33289000 */ 	andi	$t0,$t9,0x9000
/*  f11ff44:	51000085 */ 	beqzl	$t0,.PB0f12015c
/*  f11ff48:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f11ff4c:	8c428118 */ 	lw	$v0,-0x7ee8($v0)
/*  f11ff50:	24010001 */ 	li	$at,0x1
/*  f11ff54:	14410011 */ 	bne	$v0,$at,.PB0f11ff9c
/*  f11ff58:	00000000 */ 	nop
/*  f11ff5c:	0fc47e28 */ 	jal	0xf11f8a0
/*  f11ff60:	00000000 */ 	nop
/*  f11ff64:	14400007 */ 	bnez	$v0,.PB0f11ff84
/*  f11ff68:	3c018008 */ 	lui	$at,0x8008
/*  f11ff6c:	0c004f11 */ 	jal	0x13c44
/*  f11ff70:	ac208118 */ 	sw	$zero,-0x7ee8($at)
/*  f11ff74:	0fc47ee8 */ 	jal	0xf11fba0
/*  f11ff78:	00000000 */ 	nop
/*  f11ff7c:	10000077 */ 	b	.PB0f12015c
/*  f11ff80:	8faf001c */ 	lw	$t7,0x1c($sp)
.PB0f11ff84:
/*  f11ff84:	0fc47e28 */ 	jal	0xf11f8a0
/*  f11ff88:	00000000 */ 	nop
/*  f11ff8c:	0fc120fc */ 	jal	0xf0483f0
/*  f11ff90:	24440bff */ 	addiu	$a0,$v0,0xbff
/*  f11ff94:	10000071 */ 	b	.PB0f12015c
/*  f11ff98:	8faf001c */ 	lw	$t7,0x1c($sp)
.PB0f11ff9c:
/*  f11ff9c:	5440006f */ 	bnezl	$v0,.PB0f12015c
/*  f11ffa0:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f11ffa4:	0fc47e28 */ 	jal	0xf11f8a0
/*  f11ffa8:	00000000 */ 	nop
/*  f11ffac:	2841001e */ 	slti	$at,$v0,0x1e
/*  f11ffb0:	1420000a */ 	bnez	$at,.PB0f11ffdc
/*  f11ffb4:	24060003 */ 	li	$a2,0x3
/*  f11ffb8:	2449ffbd */ 	addiu	$t1,$v0,-67
/*  f11ffbc:	2d210024 */ 	sltiu	$at,$t1,0x24
/*  f11ffc0:	10200065 */ 	beqz	$at,.PB0f120158
/*  f11ffc4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11ffc8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f11ffcc:	00290821 */ 	addu	$at,$at,$t1
/*  f11ffd0:	8c296f38 */ 	lw	$t1,0x6f38($at)
/*  f11ffd4:	01200008 */ 	jr	$t1
/*  f11ffd8:	00000000 */ 	nop
.PB0f11ffdc:
/*  f11ffdc:	2401000d */ 	li	$at,0xd
/*  f11ffe0:	10410023 */ 	beq	$v0,$at,.PB0f120070
/*  f11ffe4:	2401001d */ 	li	$at,0x1d
/*  f11ffe8:	1041003b */ 	beq	$v0,$at,.PB0f1200d8
/*  f11ffec:	3c048008 */ 	lui	$a0,0x8008
/*  f11fff0:	1000005a */ 	b	.PB0f12015c
/*  f11fff4:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f11fff8:	3c028008 */ 	lui	$v0,0x8008
/*  f11fffc:	2442815c */ 	addiu	$v0,$v0,-32420
/*  f120000:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f120004:	394b0001 */ 	xori	$t3,$t2,0x1
/*  f120008:	10000053 */ 	b	.PB0f120158
/*  f12000c:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f120010:	3c028008 */ 	lui	$v0,0x8008
/*  f120014:	244281c8 */ 	addiu	$v0,$v0,-32312
/*  f120018:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f12001c:	398d0001 */ 	xori	$t5,$t4,0x1
/*  f120020:	1000004d */ 	b	.PB0f120158
/*  f120024:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f120028:	3c028008 */ 	lui	$v0,0x8008
/*  f12002c:	244281cc */ 	addiu	$v0,$v0,-32308
/*  f120030:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f120034:	39cf0001 */ 	xori	$t7,$t6,0x1
/*  f120038:	10000047 */ 	b	.PB0f120158
/*  f12003c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f120040:	3c028006 */ 	lui	$v0,0x8006
/*  f120044:	2442d910 */ 	addiu	$v0,$v0,-9968
/*  f120048:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f12004c:	3b190001 */ 	xori	$t9,$t8,0x1
/*  f120050:	10000041 */ 	b	.PB0f120158
/*  f120054:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f120058:	3c028008 */ 	lui	$v0,0x8008
/*  f12005c:	244281dc */ 	addiu	$v0,$v0,-32292
/*  f120060:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f120064:	39090001 */ 	xori	$t1,$t0,0x1
/*  f120068:	1000003b */ 	b	.PB0f120158
/*  f12006c:	ac490000 */ 	sw	$t1,0x0($v0)
.PB0f120070:
/*  f120070:	3c05800a */ 	lui	$a1,0x800a
/*  f120074:	3c07800a */ 	lui	$a3,0x800a
/*  f120078:	24e767ae */ 	addiu	$a3,$a3,0x67ae
/*  f12007c:	24a56730 */ 	addiu	$a1,$a1,0x6730
/*  f120080:	24040007 */ 	li	$a0,0x7
/*  f120084:	00001025 */ 	move	$v0,$zero
.PB0f120088:
/*  f120088:	00a01825 */ 	move	$v1,$a1
.PB0f12008c:
/*  f12008c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f120090:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f120094:	1446fffd */ 	bne	$v0,$a2,.PB0f12008c
/*  f120098:	a464001e */ 	sh	$a0,0x1e($v1)
/*  f12009c:	24a50006 */ 	addiu	$a1,$a1,0x6
/*  f1200a0:	54a7fff9 */ 	bnel	$a1,$a3,.PB0f120088
/*  f1200a4:	00001025 */ 	move	$v0,$zero
/*  f1200a8:	240a0001 */ 	li	$t2,0x1
/*  f1200ac:	3c01800a */ 	lui	$at,0x800a
/*  f1200b0:	10000029 */ 	b	.PB0f120158
/*  f1200b4:	a02a685b */ 	sb	$t2,0x685b($at)
/*  f1200b8:	3c028008 */ 	lui	$v0,0x8008
/*  f1200bc:	244281c4 */ 	addiu	$v0,$v0,-32316
/*  f1200c0:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f1200c4:	396c0001 */ 	xori	$t4,$t3,0x1
/*  f1200c8:	0fc67317 */ 	jal	0xf19cc5c
/*  f1200cc:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f1200d0:	10000022 */ 	b	.PB0f12015c
/*  f1200d4:	8faf001c */ 	lw	$t7,0x1c($sp)
.PB0f1200d8:
/*  f1200d8:	248481d0 */ 	addiu	$a0,$a0,-32304
/*  f1200dc:	8c8d0000 */ 	lw	$t5,0x0($a0)
/*  f1200e0:	3c02800a */ 	lui	$v0,0x800a
/*  f1200e4:	24426730 */ 	addiu	$v0,$v0,0x6730
/*  f1200e8:	39ae0001 */ 	xori	$t6,$t5,0x1
/*  f1200ec:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1200f0:	3c04800a */ 	lui	$a0,0x800a
/*  f1200f4:	24846739 */ 	addiu	$a0,$a0,0x6739
/*  f1200f8:	240300ff */ 	li	$v1,0xff
.PB0f1200fc:
/*  f1200fc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f120100:	1444fffe */ 	bne	$v0,$a0,.PB0f1200fc
/*  f120104:	a04300ab */ 	sb	$v1,0xab($v0)
/*  f120108:	0fc43e23 */ 	jal	0xf10f88c
/*  f12010c:	24040030 */ 	li	$a0,0x30
/*  f120110:	0fc43e23 */ 	jal	0xf10f88c
/*  f120114:	24040031 */ 	li	$a0,0x31
/*  f120118:	0fc43e23 */ 	jal	0xf10f88c
/*  f12011c:	24040032 */ 	li	$a0,0x32
/*  f120120:	0fc43e23 */ 	jal	0xf10f88c
/*  f120124:	24040033 */ 	li	$a0,0x33
/*  f120128:	0fc43e23 */ 	jal	0xf10f88c
/*  f12012c:	24040034 */ 	li	$a0,0x34
/*  f120130:	0fc43e23 */ 	jal	0xf10f88c
/*  f120134:	24040035 */ 	li	$a0,0x35
/*  f120138:	0fc43e23 */ 	jal	0xf10f88c
/*  f12013c:	24040036 */ 	li	$a0,0x36
/*  f120140:	0fc43e23 */ 	jal	0xf10f88c
/*  f120144:	24040037 */ 	li	$a0,0x37
/*  f120148:	0fc43e23 */ 	jal	0xf10f88c
/*  f12014c:	24040038 */ 	li	$a0,0x38
/*  f120150:	0fc43e23 */ 	jal	0xf10f88c
/*  f120154:	24040039 */ 	li	$a0,0x39
.PB0f120158:
/*  f120158:	8faf001c */ 	lw	$t7,0x1c($sp)
.PB0f12015c:
/*  f12015c:	3c198008 */ 	lui	$t9,0x8008
/*  f120160:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f120164:	13000009 */ 	beqz	$t8,.PB0f12018c
/*  f120168:	00000000 */ 	nop
/*  f12016c:	8f39824c */ 	lw	$t9,-0x7db4($t9)
/*  f120170:	24010001 */ 	li	$at,0x1
/*  f120174:	17210003 */ 	bne	$t9,$at,.PB0f120184
/*  f120178:	00000000 */ 	nop
/*  f12017c:	0c004f11 */ 	jal	0x13c44
/*  f120180:	00000000 */ 	nop
.PB0f120184:
/*  f120184:	3c018008 */ 	lui	$at,0x8008
/*  f120188:	ac20824c */ 	sw	$zero,-0x7db4($at)
.PB0f12018c:
/*  f12018c:	0fc47f38 */ 	jal	0xf11fce0
/*  f120190:	00000000 */ 	nop
/*  f120194:	3c028008 */ 	lui	$v0,0x8008
/*  f120198:	8c42824c */ 	lw	$v0,-0x7db4($v0)
.PB0f12019c:
/*  f12019c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1201a0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1201a4:	03e00008 */ 	jr	$ra
/*  f1201a8:	00000000 */ 	nop
);
#else
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
#endif

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

#if VERSION == VERSION_PAL_BETA
GLOBAL_ASM(
glabel func0f1204a8nb
/*  f1204a8:	3c028008 */ 	lui	$v0,0x8008
/*  f1204ac:	03e00008 */ 	jr	$ra
/*  f1204b0:	8c428220 */ 	lw	$v0,-0x7de0($v0)
);
#endif
