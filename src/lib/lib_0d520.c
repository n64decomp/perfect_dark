#include <ultra64.h>
#include "boot/boot.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/debug.h"
#include "game/game_000000.h"
#include "game/game_000090.h"
#include "game/game_000130.h"
#include "game/game_000840.h"
#include "game/game_000850.h"
#include "game/game_000860.h"
#include "game/game_000870.h"
#include "game/game_000880.h"
#include "game/game_0008e0.h"
#include "game/game_0008f0.h"
#include "game/game_000900.h"
#include "game/game_000910.h"
#include "game/game_006bd0.h"
#include "game/game_00b190.h"
#include "game/game_00b200.h"
#include "game/game_00b210.h"
#include "game/game_00b320.h"
#include "game/title.h"
#include "game/game_01b0a0.h"
#include "game/game_095320.h"
#include "game/endscreen.h"
#include "game/game_127910.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "game/game_167ae0.h"
#include "game/timing.h"
#include "game/music.h"
#include "game/game_175f50.h"
#include "game/game_175f90.h"
#include "game/game_176080.h"
#include "game/game_1a78b0.h"
#include "game/mplayer.h"
#include "game/pak/pak.h"
#include "game/splat.h"
#include "game/utils.h"
#include "gvars/gvars.h"
#include "lib/lib_070d0.h"
#include "lib/lib_074f0.h"
#include "lib/lib_08a20.h"
#include "lib/lib_09660.h"
#include "lib/lib_0bfb0.h"
#include "lib/lib_0c000.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_126b0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_13750.h"
#include "lib/lib_13790.h"
#include "lib/lib_13900.h"
#include "lib/lib_15860.h"
#include "lib/lib_233c0.h"
#include "lib/lib_2f490.h"
#include "lib/lib_2fa00.h"
#include "types.h"

s32 var8005d9b0 = 0;
s32 g_StageNum = STAGE_TITLE;
u32 var8005d9b8 = 0x0004b000;
s32 var8005d9bc = 0;
s32 var8005d9c0 = 0;
s32 var8005d9c4 = 0;
s32 var8005d9c8 = 1;
u32 var8005d9cc = 0;
s32 var8005d9d0 = 0;
s32 var8005d9d4 = 0;

struct stageallocation g_StageAllocations8Mb[] = {
	{ STAGE_CITRAINING,    "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_DEFECTION,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_INVESTIGATION, "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_EXTRACTION,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_CHICAGO,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_G5BUILDING,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_VILLA,         "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma600" },
	{ STAGE_INFILTRATION,  "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_RESCUE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_ESCAPE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_AIRBASE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_AIRFORCEONE,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_CRASHSITE,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_PELAGIC,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_DEEPSEA,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_DEFENSE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_ATTACKSHIP,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_SKEDARRUINS,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
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
	{ STAGE_TEST_ASH,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_28,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_MBR,           "-ml0 -me0 -mgfx120 -mvtx100 -ma700"            },
	{ STAGE_TEST_SILO,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_24,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_MAIANSOS,      "-ml0 -me0 -mgfx120 -mvtx100 -ma500"            },
	{ STAGE_RETAKING,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_DEST,     "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_2B,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_WAR,           "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_UFF,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_OLD,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_DUEL,          "-ml0 -me0 -mgfx120 -mvtx100 -ma700"            },
	{ STAGE_TEST_LAM,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_ARCH,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx120 -mvtx98 -ma300"             },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx120 -mvtx98 -ma300"             },
};

struct stageallocation g_StageAllocations4Mb[] = {
	{ STAGE_MP_SKEDAR,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_PIPES,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_AREA52,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_RAVINE,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_G5BUILDING, "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_SEWERS,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_WAREHOUSE,  "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_BASE,       "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_COMPLEX,    "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_TEMPLE,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_FELICITY,   "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_GRID,       "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_TEST_RUN,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_CARPARK,    "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_RUINS,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_FORTRESS,   "-ml0 -me0 -mgfx96 -mvtx96 -ma130"              },
	{ STAGE_MP_VILLA,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_TEST_MP2,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP6,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP7,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP8,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP14,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP16,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP17,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP18,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP19,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP20,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx100 -mvtx96 -ma120"             },
	{ STAGE_4MBMENU,       "-mgfx100 -mvtx50 -ma50"                        },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx100 -mvtx96 -ma300"             },
};

const char var70053a98[] = "-level_";
const char var70053aa0[] = "          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400";

u32 var8005dcc8 = 0xbc000006;
u32 var8005dccc = 0x00000000;
u32 var8005dcd0 = 0x06000000;
u32 var8005dcd4 = (u32) &var800613a0;
u32 var8005dcd8 = 0x06000000;
u32 var8005dcdc = (u32) &var80061380;
u32 var8005dce0 = 0xe9000000;
u32 var8005dce4 = 0x00000000;
u32 var8005dce8 = 0xb8000000;
u32 var8005dcec = 0x00000000;
u32 var8005dcf0 = 0xbc000006;
u32 var8005dcf4 = 0x00000000;
u32 var8005dcf8 = 0x06000000;
u32 var8005dcfc = (u32) &var800613a0;
u32 var8005dd00 = 0x06000000;
u32 var8005dd04 = (u32) &var80061380;
u32 var8005dd08 = 0xe9000000;
u32 var8005dd0c = 0x00000000;
u32 var8005dd10 = 0xb8000000;
u32 var8005dd14 = 0x00000000;
u32 var8005dd18 = 0x00000001;
u32 var8005dd1c = 0x00020000;
u32 var8005dd20 = 0x00000000;
u32 var8005dd24 = 0x00000000;
u32 var8005dd28 = 0x00000000;
u32 var8005dd2c = 0x00000000;
u32 var8005dd30 = 0x00000000;
u32 var8005dd34 = 0x00000000;
u32 var8005dd38 = 0x00000000;
u32 var8005dd3c = 0x00000000;
u32 var8005dd40 = 0x00000000;
u32 var8005dd44 = 0x00000000;
u32 var8005dd48 = 0x00000000;
u32 var8005dd4c = 0x00000000;
u32 var8005dd50 = 0x00000000;
s32 g_MainStageNum = -1;
u32 var8005dd58 = 0x00000000;

GLOBAL_ASM(
glabel mainInit
/*     d520:	27bdeb28 */ 	addiu	$sp,$sp,-5336
/*     d524:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     d528:	0c002fec */ 	jal	faultCreateThread
/*     d52c:	afb00028 */ 	sw	$s0,0x28($sp)
/*     d530:	0c003428 */ 	jal	func0000d0a0
/*     d534:	00000000 */ 	nop
/*     d538:	0c002288 */ 	jal	audioAllocateStack
/*     d53c:	00000000 */ 	nop
/*     d540:	0c005618 */ 	jal	initGlobalVariables
/*     d544:	00000000 */ 	nop
/*     d548:	0c004878 */ 	jal	func000121e0
/*     d54c:	00000000 */ 	nop
/*     d550:	0c004a83 */ 	jal	func00012a0c
/*     d554:	00000000 */ 	nop
/*     d558:	0c004dd6 */ 	jal	func00013758
/*     d55c:	00000000 */ 	nop
/*     d560:	0c0026ac */ 	jal	func00009ab0
/*     d564:	00000000 */ 	nop
/*     d568:	0c00be82 */ 	jal	func0002fa08
/*     d56c:	00000000 */ 	nop
/*     d570:	3c018006 */ 	lui	$at,%hi(var8005d9b0)
/*     d574:	0c004f25 */ 	jal	func00013c94
/*     d578:	ac22d9b0 */ 	sw	$v0,%lo(var8005d9b0)($at)
/*     d57c:	27a41490 */ 	addiu	$a0,$sp,0x1490
/*     d580:	27a514cc */ 	addiu	$a1,$sp,0x14cc
/*     d584:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     d588:	24060001 */ 	addiu	$a2,$zero,0x1
/*     d58c:	00008025 */ 	or	$s0,$zero,$zero
/*     d590:	3c070047 */ 	lui	$a3,0x47
.L0000d594:
/*     d594:	240e0000 */ 	addiu	$t6,$zero,0x0
/*     d598:	240f0000 */ 	addiu	$t7,$zero,0x0
/*     d59c:	27b81490 */ 	addiu	$t8,$sp,0x1490
/*     d5a0:	27b914cc */ 	addiu	$t9,$sp,0x14cc
/*     d5a4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*     d5a8:	afb80018 */ 	sw	$t8,0x18($sp)
/*     d5ac:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     d5b0:	afae0010 */ 	sw	$t6,0x10($sp)
/*     d5b4:	34e7868c */ 	ori	$a3,$a3,0x868c
/*     d5b8:	27a414a8 */ 	addiu	$a0,$sp,0x14a8
/*     d5bc:	0c0122c8 */ 	jal	osSetTimer
/*     d5c0:	24060000 */ 	addiu	$a2,$zero,0x0
/*     d5c4:	27a41490 */ 	addiu	$a0,$sp,0x1490
/*     d5c8:	27a514cc */ 	addiu	$a1,$sp,0x14cc
/*     d5cc:	0c0121bc */ 	jal	osRecvMesg
/*     d5d0:	24060001 */ 	addiu	$a2,$zero,0x1
/*     d5d4:	24010001 */ 	addiu	$at,$zero,0x1
/*     d5d8:	56010006 */ 	bnel	$s0,$at,.L0000d5f4
/*     d5dc:	2a010002 */ 	slti	$at,$s0,0x2
/*     d5e0:	0c004f7f */ 	jal	func00013dfc
/*     d5e4:	00000000 */ 	nop
/*     d5e8:	10000007 */ 	b	.L0000d608
/*     d5ec:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d5f0:	2a010002 */ 	slti	$at,$s0,0x2
.L0000d5f4:
/*     d5f4:	54200004 */ 	bnezl	$at,.L0000d608
/*     d5f8:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d5fc:	0c0050bc */ 	jal	func000142f0
/*     d600:	00000000 */ 	nop
/*     d604:	26100001 */ 	addiu	$s0,$s0,0x1
.L0000d608:
/*     d608:	24010004 */ 	addiu	$at,$zero,0x4
/*     d60c:	5601ffe1 */ 	bnel	$s0,$at,.L0000d594
/*     d610:	3c070047 */ 	lui	$a3,0x47
/*     d614:	3c057005 */ 	lui	$a1,%hi(var70053a98)
/*     d618:	24a53a98 */ 	addiu	$a1,$a1,%lo(var70053a98)
/*     d61c:	0c004c04 */ 	jal	func00013010
/*     d620:	24040001 */ 	addiu	$a0,$zero,0x1
/*     d624:	14400004 */ 	bnez	$v0,.L0000d638
/*     d628:	00002025 */ 	or	$a0,$zero,$zero
/*     d62c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*     d630:	3c018006 */ 	lui	$at,%hi(var8005d9b0)
/*     d634:	ac2bd9b0 */ 	sw	$t3,%lo(var8005d9b0)($at)
.L0000d638:
/*     d638:	0c0053d8 */ 	jal	func00014f60
/*     d63c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d640:	14400010 */ 	bnez	$v0,.L0000d684
/*     d644:	24040001 */ 	addiu	$a0,$zero,0x1
/*     d648:	0c0053d8 */ 	jal	func00014f60
/*     d64c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d650:	1440000c */ 	bnez	$v0,.L0000d684
/*     d654:	24040002 */ 	addiu	$a0,$zero,0x2
/*     d658:	0c0053d8 */ 	jal	func00014f60
/*     d65c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d660:	14400008 */ 	bnez	$v0,.L0000d684
/*     d664:	24040003 */ 	addiu	$a0,$zero,0x3
/*     d668:	0c0053d8 */ 	jal	func00014f60
/*     d66c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d670:	14400004 */ 	bnez	$v0,.L0000d684
/*     d674:	3c108006 */ 	lui	$s0,%hi(var8005d9d4)
/*     d678:	2610d9d4 */ 	addiu	$s0,$s0,%lo(var8005d9d4)
/*     d67c:	10000005 */ 	b	.L0000d694
/*     d680:	ae000000 */ 	sw	$zero,0x0($s0)
.L0000d684:
/*     d684:	3c108006 */ 	lui	$s0,%hi(var8005d9d4)
/*     d688:	2610d9d4 */ 	addiu	$s0,$s0,%lo(var8005d9d4)
/*     d68c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*     d690:	ae0c0000 */ 	sw	$t4,0x0($s0)
.L0000d694:
/*     d694:	3c0e8006 */ 	lui	$t6,%hi(var8005dd1c)
/*     d698:	afa01470 */ 	sw	$zero,0x1470($sp)
/*     d69c:	25cedd1c */ 	addiu	$t6,$t6,%lo(var8005dd1c)
/*     d6a0:	8dc10000 */ 	lw	$at,0x0($t6)
/*     d6a4:	8dd90004 */ 	lw	$t9,0x4($t6)
/*     d6a8:	27ad1450 */ 	addiu	$t5,$sp,0x1450
/*     d6ac:	ada10000 */ 	sw	$at,0x0($t5)
/*     d6b0:	adb90004 */ 	sw	$t9,0x4($t5)
/*     d6b4:	8dd9000c */ 	lw	$t9,0xc($t6)
/*     d6b8:	8dc10008 */ 	lw	$at,0x8($t6)
/*     d6bc:	adb9000c */ 	sw	$t9,0xc($t5)
/*     d6c0:	ada10008 */ 	sw	$at,0x8($t5)
/*     d6c4:	8dc10010 */ 	lw	$at,0x10($t6)
/*     d6c8:	8dd90014 */ 	lw	$t9,0x14($t6)
/*     d6cc:	ada10010 */ 	sw	$at,0x10($t5)
/*     d6d0:	adb90014 */ 	sw	$t9,0x14($t5)
/*     d6d4:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*     d6d8:	8dc10018 */ 	lw	$at,0x18($t6)
/*     d6dc:	adb9001c */ 	sw	$t9,0x1c($t5)
/*     d6e0:	0c0005b0 */ 	jal	osGetMemSize
/*     d6e4:	ada10018 */ 	sw	$at,0x18($t5)
/*     d6e8:	3c010040 */ 	lui	$at,0x40
/*     d6ec:	34210001 */ 	ori	$at,$at,0x1
/*     d6f0:	0041082a */ 	slt	$at,$v0,$at
/*     d6f4:	1020000e */ 	beqz	$at,.L0000d730
/*     d6f8:	3c028080 */ 	lui	$v0,0x8080
/*     d6fc:	3c0b8006 */ 	lui	$t3,%hi(var8005cf84)
/*     d700:	8d6bcf84 */ 	lw	$t3,%lo(var8005cf84)($t3)
/*     d704:	3c18803f */ 	lui	$t8,0x803f
/*     d708:	371850b8 */ 	ori	$t8,$t8,0x50b8
/*     d70c:	3c01ffef */ 	lui	$at,0xffef
/*     d710:	000b60c0 */ 	sll	$t4,$t3,0x3
/*     d714:	030c1023 */ 	subu	$v0,$t8,$t4
/*     d718:	34214000 */ 	ori	$at,$at,0x4000
/*     d71c:	00411021 */ 	addu	$v0,$v0,$at
/*     d720:	304f1fff */ 	andi	$t7,$v0,0x1fff
/*     d724:	004f1023 */ 	subu	$v0,$v0,$t7
/*     d728:	10000001 */ 	b	.L0000d730
/*     d72c:	2442e380 */ 	addiu	$v0,$v0,-7296
.L0000d730:
/*     d730:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*     d734:	3c01fff6 */ 	lui	$at,0xfff6
/*     d738:	3421a000 */ 	ori	$at,$at,0xa000
/*     d73c:	00411021 */ 	addu	$v0,$v0,$at
/*     d740:	11a0000f */ 	beqz	$t5,.L0000d780
/*     d744:	2442ffc0 */ 	addiu	$v0,$v0,-64
/*     d748:	3c018000 */ 	lui	$at,0x8000
/*     d74c:	00418025 */ 	or	$s0,$v0,$at
/*     d750:	2610003f */ 	addiu	$s0,$s0,0x3f
/*     d754:	3c030200 */ 	lui	$v1,%hi(_accessingpakSegmentRomStart)
/*     d758:	360e003f */ 	ori	$t6,$s0,0x3f
/*     d75c:	3c0b0200 */ 	lui	$t3,%hi(_accessingpakSegmentRomEnd)
/*     d760:	2465f550 */ 	addiu	$a1,$v1,%lo(_accessingpakSegmentRomStart)
/*     d764:	256bfe00 */ 	addiu	$t3,$t3,%lo(_accessingpakSegmentRomEnd)
/*     d768:	39c4003f */ 	xori	$a0,$t6,0x3f
/*     d76c:	00808025 */ 	or	$s0,$a0,$zero
/*     d770:	0c003504 */ 	jal	func0000d410
/*     d774:	01653023 */ 	subu	$a2,$t3,$a1
/*     d778:	1000000e */ 	b	.L0000d7b4
/*     d77c:	3c01ffff */ 	lui	$at,0xffff
.L0000d780:
/*     d780:	3c018000 */ 	lui	$at,0x8000
/*     d784:	00418025 */ 	or	$s0,$v0,$at
/*     d788:	2610003f */ 	addiu	$s0,$s0,0x3f
/*     d78c:	3c030200 */ 	lui	$v1,%hi(_copyrightSegmentRomStart)
/*     d790:	3618003f */ 	ori	$t8,$s0,0x3f
/*     d794:	3c0f0200 */ 	lui	$t7,%hi(_copyrightSegmentRomEnd)
/*     d798:	2465ea20 */ 	addiu	$a1,$v1,%lo(_copyrightSegmentRomStart)
/*     d79c:	25eff550 */ 	addiu	$t7,$t7,%lo(_copyrightSegmentRomEnd)
/*     d7a0:	3b04003f */ 	xori	$a0,$t8,0x3f
/*     d7a4:	00808025 */ 	or	$s0,$a0,$zero
/*     d7a8:	0c003504 */ 	jal	func0000d410
/*     d7ac:	01e53023 */ 	subu	$a2,$t7,$a1
/*     d7b0:	3c01ffff */ 	lui	$at,0xffff
.L0000d7b4:
/*     d7b4:	342141e0 */ 	ori	$at,$at,0x41e0
/*     d7b8:	02012821 */ 	addu	$a1,$s0,$at
/*     d7bc:	afa50048 */ 	sw	$a1,0x48($sp)
/*     d7c0:	02002025 */ 	or	$a0,$s0,$zero
/*     d7c4:	0c001d3c */ 	jal	func000074f0
/*     d7c8:	27a60050 */ 	addiu	$a2,$sp,0x50
/*     d7cc:	3c050004 */ 	lui	$a1,0x4
/*     d7d0:	8faa0048 */ 	lw	$t2,0x48($sp)
/*     d7d4:	34a53800 */ 	ori	$a1,$a1,0x3800
/*     d7d8:	00003825 */ 	or	$a3,$zero,$zero
/*     d7dc:	24040500 */ 	addiu	$a0,$zero,0x500
/*     d7e0:	00076840 */ 	sll	$t5,$a3,0x1
.L0000d7e4:
/*     d7e4:	020d1821 */ 	addu	$v1,$s0,$t5
/*     d7e8:	00001025 */ 	or	$v0,$zero,$zero
.L0000d7ec:
/*     d7ec:	00627021 */ 	addu	$t6,$v1,$v0
/*     d7f0:	24420002 */ 	addiu	$v0,$v0,0x2
/*     d7f4:	1444fffd */ 	bne	$v0,$a0,.L0000d7ec
/*     d7f8:	a5c00000 */ 	sh	$zero,0x0($t6)
/*     d7fc:	24e70240 */ 	addiu	$a3,$a3,0x240
/*     d800:	00e5082a */ 	slt	$at,$a3,$a1
/*     d804:	5420fff7 */ 	bnezl	$at,.L0000d7e4
/*     d808:	00076840 */ 	sll	$t5,$a3,0x1
/*     d80c:	3c198000 */ 	lui	$t9,0x8000
/*     d810:	8f390300 */ 	lw	$t9,0x300($t9)
/*     d814:	00003825 */ 	or	$a3,$zero,$zero
/*     d818:	00003025 */ 	or	$a2,$zero,$zero
/*     d81c:	13200010 */ 	beqz	$t9,.L0000d860
/*     d820:	24095f10 */ 	addiu	$t1,$zero,0x5f10
/*     d824:	240503f6 */ 	addiu	$a1,$zero,0x3f6
.L0000d828:
/*     d828:	00075840 */ 	sll	$t3,$a3,0x1
/*     d82c:	0006c040 */ 	sll	$t8,$a2,0x1
/*     d830:	01582021 */ 	addu	$a0,$t2,$t8
/*     d834:	020b1821 */ 	addu	$v1,$s0,$t3
/*     d838:	00001025 */ 	or	$v0,$zero,$zero
.L0000d83c:
/*     d83c:	00826021 */ 	addu	$t4,$a0,$v0
/*     d840:	958f0000 */ 	lhu	$t7,0x0($t4)
/*     d844:	00626821 */ 	addu	$t5,$v1,$v0
/*     d848:	24420002 */ 	addiu	$v0,$v0,0x2
/*     d84c:	1445fffb */ 	bne	$v0,$a1,.L0000d83c
/*     d850:	a5af008a */ 	sh	$t7,0x8a($t5)
/*     d854:	24c601fb */ 	addiu	$a2,$a2,0x1fb
/*     d858:	14c9fff3 */ 	bne	$a2,$t1,.L0000d828
/*     d85c:	24e70240 */ 	addiu	$a3,$a3,0x240
.L0000d860:
/*     d860:	0c002aac */ 	jal	func0000aab0
/*     d864:	24040002 */ 	addiu	$a0,$zero,0x2
/*     d868:	0c0026d4 */ 	jal	func00009b50
/*     d86c:	02002025 */ 	or	$a0,$s0,$zero
/*     d870:	8faa0048 */ 	lw	$t2,0x48($sp)
/*     d874:	3c018006 */ 	lui	$at,%hi(var8005f044)
/*     d878:	3c048009 */ 	lui	$a0,%hi(var8008db30)
/*     d87c:	ac2af044 */ 	sw	$t2,%lo(var8005f044)($at)
/*     d880:	3c018006 */ 	lui	$at,%hi(var8005f040)
/*     d884:	254e0800 */ 	addiu	$t6,$t2,0x800
/*     d888:	ac2ef040 */ 	sw	$t6,%lo(var8005f040)($at)
/*     d88c:	2484db30 */ 	addiu	$a0,$a0,%lo(var8008db30)
/*     d890:	27a51470 */ 	addiu	$a1,$sp,0x1470
/*     d894:	0c0121bc */ 	jal	osRecvMesg
/*     d898:	00003025 */ 	or	$a2,$zero,$zero
/*     d89c:	14400007 */ 	bnez	$v0,.L0000d8bc
.L0000d8a0:
/*     d8a0:	3c048009 */ 	lui	$a0,%hi(var8008db30)
/*     d8a4:	2484db30 */ 	addiu	$a0,$a0,%lo(var8008db30)
/*     d8a8:	27a51470 */ 	addiu	$a1,$sp,0x1470
/*     d8ac:	0c0121bc */ 	jal	osRecvMesg
/*     d8b0:	00003025 */ 	or	$a2,$zero,$zero
/*     d8b4:	1040fffa */ 	beqz	$v0,.L0000d8a0
/*     d8b8:	00000000 */ 	nop
.L0000d8bc:
/*     d8bc:	00001825 */ 	or	$v1,$zero,$zero
.L0000d8c0:
/*     d8c0:	3c048009 */ 	lui	$a0,%hi(var8008db30)
/*     d8c4:	2484db30 */ 	addiu	$a0,$a0,%lo(var8008db30)
/*     d8c8:	27a51470 */ 	addiu	$a1,$sp,0x1470
/*     d8cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*     d8d0:	0c0121bc */ 	jal	osRecvMesg
/*     d8d4:	afa31488 */ 	sw	$v1,0x1488($sp)
/*     d8d8:	8fb91470 */ 	lw	$t9,0x1470($sp)
/*     d8dc:	24010001 */ 	addiu	$at,$zero,0x1
/*     d8e0:	8fa31488 */ 	lw	$v1,0x1488($sp)
/*     d8e4:	872b0000 */ 	lh	$t3,0x0($t9)
/*     d8e8:	27b01450 */ 	addiu	$s0,$sp,0x1450
/*     d8ec:	5561000d */ 	bnel	$t3,$at,.L0000d924
/*     d8f0:	28610006 */ 	slti	$at,$v1,0x6
/*     d8f4:	0c002811 */ 	jal	func0000a044
/*     d8f8:	afa31488 */ 	sw	$v1,0x1488($sp)
/*     d8fc:	3c048006 */ 	lui	$a0,%hi(var8005dcc8)
/*     d900:	3c058006 */ 	lui	$a1,%hi(var8005dcf0)
/*     d904:	24a5dcf0 */ 	addiu	$a1,$a1,%lo(var8005dcf0)
/*     d908:	2484dcc8 */ 	addiu	$a0,$a0,%lo(var8005dcc8)
/*     d90c:	00003025 */ 	or	$a2,$zero,$zero
/*     d910:	0c00be3d */ 	jal	func0002f8f4
/*     d914:	02003825 */ 	or	$a3,$s0,$zero
/*     d918:	8fa31488 */ 	lw	$v1,0x1488($sp)
/*     d91c:	24630001 */ 	addiu	$v1,$v1,0x1
/*     d920:	28610006 */ 	slti	$at,$v1,0x6
.L0000d924:
/*     d924:	1420ffe6 */ 	bnez	$at,.L0000d8c0
/*     d928:	00000000 */ 	nop
/*     d92c:	3c188000 */ 	lui	$t8,0x8000
/*     d930:	8f180300 */ 	lw	$t8,0x300($t8)
/*     d934:	17000003 */ 	bnez	$t8,.L0000d944
/*     d938:	00000000 */ 	nop
.L0000d93c:
/*     d93c:	1000ffff */ 	b	.L0000d93c
/*     d940:	00000000 */ 	nop
.L0000d944:
/*     d944:	0c001c34 */ 	jal	func000070d0
/*     d948:	00000000 */ 	nop
/*     d94c:	0fc69e2c */ 	jal	func0f1a78b0
/*     d950:	00000000 */ 	nop
/*     d954:	0fc59bdd */ 	jal	func0f166f74
/*     d958:	00000000 */ 	nop
/*     d95c:	0fc5d7d4 */ 	jal	func0f175f50
/*     d960:	00000000 */ 	nop
/*     d964:	0fc5d7e4 */ 	jal	func0f175f90
/*     d968:	00000000 */ 	nop
/*     d96c:	3c0c8006 */ 	lui	$t4,%hi(var8005d9b0)
/*     d970:	8d8cd9b0 */ 	lw	$t4,%lo(var8005d9b0)($t4)
/*     d974:	11800003 */ 	beqz	$t4,.L0000d984
/*     d978:	3c047005 */ 	lui	$a0,%hi(var70053aa0)
/*     d97c:	0c004bbf */ 	jal	func00012efc
/*     d980:	24843aa0 */ 	addiu	$a0,$a0,%lo(var70053aa0)
.L0000d984:
/*     d984:	3c04800b */ 	lui	$a0,%hi(var800ad1c0)
/*     d988:	0c012d20 */ 	jal	osVirtualToPhysical
/*     d98c:	2484d1c0 */ 	addiu	$a0,$a0,%lo(var800ad1c0)
/*     d990:	3c038009 */ 	lui	$v1,%hi(var80090b00)
/*     d994:	8c630b00 */ 	lw	$v1,%lo(var80090b00)($v1)
/*     d998:	3c018000 */ 	lui	$at,0x8000
/*     d99c:	00412025 */ 	or	$a0,$v0,$at
/*     d9a0:	0c00487a */ 	jal	func000121e8
/*     d9a4:	00642823 */ 	subu	$a1,$v1,$a0
/*     d9a8:	0c00494a */ 	jal	func00012528
/*     d9ac:	24040008 */ 	addiu	$a0,$zero,0x8
/*     d9b0:	0c00494a */ 	jal	func00012528
/*     d9b4:	24040006 */ 	addiu	$a0,$zero,0x6
/*     d9b8:	0c0033be */ 	jal	func0000cef8
/*     d9bc:	00000000 */ 	nop
/*     d9c0:	0fc02c84 */ 	jal	func0f00b210
/*     d9c4:	00000000 */ 	nop
/*     d9c8:	0fc5db77 */ 	jal	func0f176ddc
/*     d9cc:	00000000 */ 	nop
/*     d9d0:	0c000d34 */ 	jal	func000034d0
/*     d9d4:	00000000 */ 	nop
/*     d9d8:	0fc02c64 */ 	jal	loadTextureList
/*     d9dc:	00000000 */ 	nop
/*     d9e0:	0fc00000 */ 	jal	func0f000000
/*     d9e4:	00000000 */ 	nop
/*     d9e8:	0fc59ebe */ 	jal	func0f167af8
/*     d9ec:	00000000 */ 	nop
/*     d9f0:	0fc41d3b */ 	jal	cheatsDisableAll
/*     d9f4:	00000000 */ 	nop
/*     d9f8:	0c003a70 */ 	jal	func0000e9c0
/*     d9fc:	00000000 */ 	nop
/*     da00:	0fc54c68 */ 	jal	func0f1531a0
/*     da04:	00000000 */ 	nop
/*     da08:	0c004de4 */ 	jal	func00013790
/*     da0c:	00000000 */ 	nop
/*     da10:	0fc49e44 */ 	jal	func0f127910
/*     da14:	00000000 */ 	nop
/*     da18:	0fc5b384 */ 	jal	func0f16ce10
/*     da1c:	00000000 */ 	nop
/*     da20:	0fc02c80 */ 	jal	func0f00b200
/*     da24:	00000000 */ 	nop
/*     da28:	0c0026a0 */ 	jal	func00009a80
/*     da2c:	00000000 */ 	nop
/*     da30:	0fc0021c */ 	jal	func0f000870
/*     da34:	00000000 */ 	nop
/*     da38:	0fc00220 */ 	jal	func0f000880
/*     da3c:	00000000 */ 	nop
/*     da40:	0fc00238 */ 	jal	func0f0008e0
/*     da44:	00000000 */ 	nop
/*     da48:	0fc0023c */ 	jal	func0f0008f0
/*     da4c:	00000000 */ 	nop
/*     da50:	0fc00240 */ 	jal	func0f000900
/*     da54:	00000000 */ 	nop
/*     da58:	0fc02c60 */ 	jal	func0f00b180
/*     da5c:	00000000 */ 	nop
/*     da60:	0fc00244 */ 	jal	func0f000910
/*     da64:	00000000 */ 	nop
/*     da68:	0fc00210 */ 	jal	func0f000840
/*     da6c:	00000000 */ 	nop
/*     da70:	0fc62084 */ 	jal	func0f188210
/*     da74:	00000000 */ 	nop
/*     da78:	0fc528ca */ 	jal	func0f14a328
/*     da7c:	00000000 */ 	nop
/*     da80:	0fc46276 */ 	jal	func0f1189d8
/*     da84:	00000000 */ 	nop
/*     da88:	0fc528ef */ 	jal	func0f14a3bc
/*     da8c:	00000000 */ 	nop
/*     da90:	0c008cf0 */ 	jal	func000233c0
/*     da94:	00000000 */ 	nop
/*     da98:	0fc00040 */ 	jal	func0f000100
/*     da9c:	00000000 */ 	nop
/*     daa0:	0fc0004c */ 	jal	func0f000130
/*     daa4:	00000000 */ 	nop
/*     daa8:	0fc00214 */ 	jal	func0f000850
/*     daac:	00000000 */ 	nop
/*     dab0:	0fc00218 */ 	jal	func0f000860
/*     dab4:	00000000 */ 	nop
/*     dab8:	0fc00024 */ 	jal	func0f000090
/*     dabc:	00000000 */ 	nop
/*     dac0:	0c0026fe */ 	jal	func00009bf8
/*     dac4:	00000000 */ 	nop
/*     dac8:	0c0027b1 */ 	jal	func00009ec4
/*     dacc:	24040001 */ 	addiu	$a0,$zero,0x1
/*     dad0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     dad4:	3c018006 */ 	lui	$at,%hi(var8005dd18)
/*     dad8:	8fb00028 */ 	lw	$s0,0x28($sp)
/*     dadc:	ac20dd18 */ 	sw	$zero,%lo(var8005dd18)($at)
/*     dae0:	03e00008 */ 	jr	$ra
/*     dae4:	27bd14d8 */ 	addiu	$sp,$sp,0x14d8
);

void mainEntry(void)
{
	mainInit();
	func0002f8a0();
	func0000f804();

	while (true) {
		mainLoop();
	}
}

void func0000db30(char *string, u32 *ptr)
{
	// empty
}

/**
 * This function enters an infinite loop which iterates once per stage load.
 * Within this loop is an inner loop which runs very frequently and decides
 * whether to run mainTick on each iteration.
 */
void mainLoop(void)
{
	s32 ending = false;
	u32 array[] = {0x20000, 0, 0, 0, 0, 0, 0, 0};
	OSMesg msg;
	s32 index;
	s32 numplayers;
	s32 stagenum;

	func0f175f98();

	var8005d9c4 = 0;
	func000130d4(&g_StageNum);

	if (var8005d9d4 != 0) {
		g_Vars.unk0004e4 = 253;
		g_StageNum = STAGE_BOOTPAKMENU;
	}

	if (g_StageNum != STAGE_TITLE) {
		titleSetNextStage(g_StageNum);

		if (g_StageNum < STAGE_TITLE) {
			func0f01b148(0);

			if (func00013010(1, "-hard")) {
				setDifficulty(func00013010(1, "-hard")[0] - '0');
			}
		}
	}

	if (g_StageNum == STAGE_CITRAINING && IS4MB()) {
		g_StageNum = STAGE_4MBMENU;
	}

	rngSetSeed(osGetCount());

	// Outer loop - this is infinite because ending is never changed
	while (!ending) {
		var8005d9cc = 0;
		var8005d9c8 = 1;
		msg = NULL;
		var8005d9d0 = 0;

		if (var8005d9b0 && var8005d9c4 == 0) {
			index = -1;

			if (IS4MB()) {
				if (g_StageNum < STAGE_TITLE && getNumPlayers() >= 2) {
					index = 0;

					while (g_StageAllocations4Mb[index].stagenum) {
						if (g_StageAllocations4Mb[index].stagenum == g_StageNum + 400) {
							break;
						}

						index++;
					}

					if (g_StageAllocations4Mb[index].stagenum == 0) {
						index = -1;
					}
				}

				if (index) {
					// empty
				}

				if (index < 0) {
					index = 0;

					while (g_StageAllocations4Mb[index].stagenum) {
						if (g_StageNum == g_StageAllocations4Mb[index].stagenum) {
							break;
						}

						index++;
					}
				}

				func00012efc(g_StageAllocations4Mb[index].string);
			} else {
				// 8MB
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

				func00012efc(g_StageAllocations8Mb[index].string);
			}
		}

		var8005d9c4 = 0;

		func00012528(7);
		func00012528(4);
		func0f1672f0(4);

		if (func00013010(1, "-ma")) {
			var8005d9b8 = func00013408(func00013010(1, "-ma"), NULL, 0) * 1024;
		}

		func00012a14(malloc(var8005d9b8, 4), var8005d9b8);
		stageLoadCommonLang(g_StageNum);
		playersUnrefAll();

		if (g_StageNum >= STAGE_TITLE) {
			numplayers = 0;
		} else {
			if (func00013010(1, "-play")) {
				numplayers = func00013408(func00013010(1, "-play"), NULL, 0);
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
		} else if (func00013010(1, "-coop")) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = 1;
			g_Vars.antiplayernum = -1;
		} else if (func00013010(1, "-anti")) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = 1;
		}

		playersAllocate(numplayers);

		if (func00013010(1, "-mpbots")) {
			g_Vars.lvmpbotlevel = 1;
		}

		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
			g_MpSetup.chrslots = 0x03;
			func0f187944();
		} else if (g_Vars.perfectbuddynum) {
			func0f187944();
		} else if (g_Vars.mplayerisrunning == false
				&& (numplayers >= 2 || g_Vars.lvmpbotlevel || func00013010(1, "-play"))) {
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
			func0f187944();
		}

		func0f167350();
		func00013dfc();
		func00013798();
		func0f17608c(g_StageNum);
		func0f167e7c(g_StageNum);
		func00009c3c(g_StageNum);
		func0f16ce94();
		func00009a90();

		while (osRecvMesg(&var8008db30, &msg, OS_MESG_NOBLOCK) != -1) {
			// empty
		}

		while ((g_MainStageNum < 0 || var8005d9cc != 0)) {
			s32 tmp;
			osRecvMesg(&var8008db30, &msg, OS_MESG_BLOCK);

			switch (*(s16 *)msg) {
			case 1:
				tmp = osGetCount() - g_Vars.thisframetime;
				if (tmp >= g_Vars.mininc60 * 781250 - 781250 / 2) {
					mainTick();
				}
				break;
			case 2:
				var8005d9cc--;
				break;
			case 5:
				var8005d9cc = 4;
				break;
			}
		}

		stageLoad();
		func00012594(4);
		func00012594(7);
		func0f1672f0(4);
		func00009ec4(1);
		func0f116994();

		g_StageNum = g_MainStageNum;
		g_MainStageNum = -1;
	}

	// Unreachable
	func0f175fc8();
}

void mainTick(void)
{
	Gfx *gdl;
	Gfx *gdlstart;
	u32 array[] = {0x20000, 0, 0, 0, 0, 0, 0, 0};
	s32 i;

	if (g_MainStageNum < 0 && var8005d9cc < 2) {
		func0f16ce94();
		func00009a98();
		func00009a90();
		func00009aa0(0x20000);
		func000034d8();
		func000142f0();
		func00001b28(0);

		if (var8005d9c8) {
			gdl = gdlstart = func0f16793c();

			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

			func0f16b96c();
			randomisePlayerOrder();

			if (g_StageNum < STAGE_TITLE) {
				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(getPlayerByOrderNum(i));

					if (g_StageNum != STAGE_TEST_OLD || !titleIsKeepingMode()) {
						viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
						viSetFovAspectAndSize(
								g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
								g_Vars.currentplayer->viewx, g_Vars.currentplayer->viewy);
					}

					currentPlayerRecordDistanceMoved();
				}
			}

			gdl = func0f169374(gdl);
			func000034e0(&gdl);

			if (debug0f11ed70() >= 2) {
				gdl = debugRenderSomething(gdl);
			}

			gDPFullSync(gdl++);
			gSPEndDisplayList(gdl++);
		}

		if (var8005d9c8) {
			func0f167a18();
			func0000a044();
		}

		func0002f8f4(gdlstart, gdl, 0, array);
		var8005d9cc++;
		func00012a8c();
		func0f16cf94();
		func00009aa0(0x10000);
	}
}

void mainEndStage(void)
{
	envStopNosedive();

	if (var8005d9d0 == 0) {
		func0f11c6d0();
		func00013dd4();

		if (g_Vars.coopplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				setCurrentPlayerNum(i);
				soloPushCoopModeEndscreen();
			}

			setCurrentPlayerNum(prevplayernum);
			musicStartForMenu();
		} else if (g_Vars.antiplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				setCurrentPlayerNum(i);
				soloPushAntiModeEndscreen();
			}

			setCurrentPlayerNum(prevplayernum);
			musicStartForMenu();
		} else if (g_Vars.normmplayerisrunning) {
			func0f18b9e4();
		} else {
			endscreenPrepare();
			musicStartForMenu();
		}
	}

	var8005d9d0 = 1;
}

void mainSetStageNum(s32 stagenum)
{
	func0f11c6d0();

	g_MainStageNum = stagenum;
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
