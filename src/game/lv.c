#include <ultra64.h>
#include "constants.h"
#include "game/activemenu/activemenu.h"
#include "game/activemenu/tick.h"
#include "game/bondmove.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/game_006900.h"
#include "game/nbomb.h"
#include "game/game_00b480.h"
#include "game/game_00b820.h"
#include "game/game_00c240.h"
#include "game/game_00c490.h"
#include "game/game_0108d0.h"
#include "game/objectives.h"
#include "game/casing.h"
#include "game/game_011110.h"
#include "game/inventory/init.h"
#include "game/game_0125a0.h"
#include "game/explosions/init.h"
#include "game/smoke/init.h"
#include "game/sparks/init.h"
#include "game/weather/init.h"
#include "game/stubs/game_013540.h"
#include "game/game_013550.h"
#include "game/game_013cf0.h"
#include "game/game_0147a0.h"
#include "game/game_0147d0.h"
#include "game/game_014f10.h"
#include "game/game_015010.h"
#include "game/game_0150a0.h"
#include "game/stubs/game_015260.h"
#include "game/stubs/game_015270.h"
#include "game/explosions/reset.h"
#include "game/smoke/reset.h"
#include "game/stubs/game_0153f0.h"
#include "game/stubs/game_015400.h"
#include "game/stubs/game_015410.h"
#include "game/shards.h"
#include "game/game_015470.h"
#include "game/title.h"
#include "game/game_01b0a0.h"
#include "game/game_01bea0.h"
#include "game/weather/tick.h"
#include "game/game_01d860.h"
#include "game/game_01d990.h"
#include "game/chr/chr.h"
#include "game/prop.h"
#include "game/game_095320.h"
#include "game/bondgun.h"
#include "game/game_0abe70.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b28d0.h"
#include "game/game_0b63b0.h"
#include "game/game_0b69d0.h"
#include "game/savebuffer.h"
#include "game/hudmsg.h"
#include "game/game_0f09f0.h"
#include "game/filemgr.h"
#include "game/game_10c9c0.h"
#include "game/game_11f000.h"
#include "game/game_127910.h"
#include "game/game_129210.h"
#include "game/explosions/explosions.h"
#include "game/sparks/sparks.h"
#include "game/weather/weather.h"
#include "game/sky.h"
#include "game/credits.h"
#include "game/game_13c510.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/bg.h"
#include "game/game_165670.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/texdecompress.h"
#include "game/game_176080.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/propobj.h"
#include "game/sparks/tick.h"
#include "game/splat.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/args.h"
#include "lib/joy.h"
#include "lib/lib_06440.h"
#include "lib/lib_09a80.h"
#include "lib/lib_09a80.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/lib_11420.h"
#include "lib/rng.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

#if VERSION < VERSION_NTSC_1_0
const char var7f1b1e20nb[] = "lv.c";
const char var7f1b1e28nb[] = "R=%d(%d)";
const char var7f1b1e34nb[] = "%s%sx %4.0f";
const char var7f1b1e40nb[] = "";
const char var7f1b1e44nb[] = "";
const char var7f1b1e48nb[] = "%s%sy %4.0f";
const char var7f1b1e54nb[] = "";
const char var7f1b1e58nb[] = "";
const char var7f1b1e5cnb[] = "%s%sz %4.0f";
const char var7f1b1e68nb[] = "";
const char var7f1b1e6cnb[] = "";
const char var7f1b1e70nb[] = "%s %3d";
const char var7f1b1e78nb[] = "lv.c Master DL overrun!";
#endif

const char var7f1b7730[] = "fr: %d\n";

#if VERSION < VERSION_NTSC_1_0
const char var7f1b1e98nb[] = "lv.c";
#endif

const char var7f1b7738[] = "cutsceneframe: %d\n";
const char var7f1b774c[] = "pos:%s%s %.2f %.2f %.2f\n";
const char var7f1b7768[] = "";
const char var7f1b776c[] = "";

struct audiohandle *g_MiscSfxAudioHandles[3];
u32 var800aa5bc;
s32 g_MiscSfxActiveTypes[3];

u32 var80084010 = 0;
bool var80084014 = false;
f32 var80084018 = 1;
u32 var8008401c = 0x00000001;

s32 g_Difficulty = DIFF_A;

s32 g_StageTimeElapsed60 = 0;
s32 g_MpTimeLimit60 = SECSTOTIME60(60 * 10); // 10 minutes
s32 g_MpScoreLimit = 10;
s32 g_MpTeamScoreLimit = 20;
struct audiohandle *g_MiscAudioHandle = NULL;
s32 g_NumReasonsToEndMpMatch = 0;
f32 g_StageTimeElapsed1f = 0;
bool var80084040 = true;

u32 g_MiscSfxSounds[] = {
	SFX_HEARTBEAT,
	SFX_SLAYER_WHIR,
	SFX_SLAYER_BEEP,
};

s32 var80084050 = 0;

s16 g_FadeNumFrames = 0;
f32 g_FadeFrac = -1;
u32 g_FadePrevColour = 0;
u32 g_FadeColour = 0;
s16 g_FadeDelay = 0;

u32 getVar80084040(void)
{
	return var80084040;
}

void setVar80084040(u32 value)
{
	var80084040 = value;
}

void lv0f167af8(void)
{
	g_Vars.lockscreen = 0;
	g_Vars.joydisableframestogo = -1;
}

void lvStopAllMiscSfx(void)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MiscSfxAudioHandles); i++) {
		g_MiscSfxAudioHandles[i] = NULL;
		g_MiscSfxActiveTypes[i] = -1;
	}
}

s32 lvGetMiscSfxIndex(u32 type)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MiscSfxActiveTypes); i++) {
		if (g_MiscSfxActiveTypes[i] == type) {
			return i;
		}
	}

	return -1;
}

#if VERSION >= VERSION_NTSC_1_0
void lvSetMiscSfxState(u32 type, bool play)
{
	if (play) {
		if (lvGetMiscSfxIndex(type) == -1) {
			s32 index = lvGetMiscSfxIndex(-1);

			if (index != -1 && g_MiscSfxAudioHandles[index] == NULL) {
				sndStart(var80095200, g_MiscSfxSounds[type], &g_MiscSfxAudioHandles[index], -1, -1, -1, -1, -1);
				g_MiscSfxActiveTypes[index] = type;
			}
		}
	} else {
		u32 stack;
		s32 index = lvGetMiscSfxIndex(type);

		if (index != -1) {
			audioStop(g_MiscSfxAudioHandles[index]);
			g_MiscSfxActiveTypes[index] = -1;
		}
	}
}
#else
GLOBAL_ASM(
glabel lvSetMiscSfxState
/*  f1624c4:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f1624c8:	10a00027 */ 	beqz	$a1,.NB0f162568
/*  f1624cc:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1624d0:	0fc58922 */ 	jal	lvGetMiscSfxIndex
/*  f1624d4:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f1624d8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1624dc:	54410036 */ 	bnel	$v0,$at,.NB0f1625b8
/*  f1624e0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1624e4:	0fc58922 */ 	jal	lvGetMiscSfxIndex
/*  f1624e8:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f1624ec:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1624f0:	10410030 */ 	beq	$v0,$at,.NB0f1625b4
/*  f1624f4:	3c04800a */ 	lui	$a0,0x800a
/*  f1624f8:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f1624fc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f162500:	44812000 */ 	mtc1	$at,$f4
/*  f162504:	3c058008 */ 	lui	$a1,0x8008
/*  f162508:	3c18800b */ 	lui	$t8,0x800b
/*  f16250c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f162510:	00af2821 */ 	addu	$a1,$a1,$t7
/*  f162514:	2718ee60 */ 	addiu	$t8,$t8,-4512
/*  f162518:	00021880 */ 	sll	$v1,$v0,0x2
/*  f16251c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f162520:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f162524:	240affff */ 	addiu	$t2,$zero,-1
/*  f162528:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f16252c:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f162530:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f162534:	00783021 */ 	addu	$a2,$v1,$t8
/*  f162538:	afa30030 */ 	sw	$v1,0x30($sp)
/*  f16253c:	84a568a6 */ 	lh	$a1,0x68a6($a1)
/*  f162540:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f162544:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f162548:	0c004338 */ 	jal	sndStart
/*  f16254c:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f162550:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f162554:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f162558:	3c01800b */ 	lui	$at,0x800b
/*  f16255c:	00230821 */ 	addu	$at,$at,$v1
/*  f162560:	10000014 */ 	beqz	$zero,.NB0f1625b4
/*  f162564:	ac2bee70 */ 	sw	$t3,-0x1190($at)
.NB0f162568:
/*  f162568:	0fc58922 */ 	jal	lvGetMiscSfxIndex
/*  f16256c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162570:	2401ffff */ 	addiu	$at,$zero,-1
/*  f162574:	1041000f */ 	beq	$v0,$at,.NB0f1625b4
/*  f162578:	3c0c800b */ 	lui	$t4,0x800b
/*  f16257c:	00021080 */ 	sll	$v0,$v0,0x2
/*  f162580:	258cee60 */ 	addiu	$t4,$t4,-4512
/*  f162584:	004c1821 */ 	addu	$v1,$v0,$t4
/*  f162588:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f16258c:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f162590:	0c00d428 */ 	jal	audioStop
/*  f162594:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f162598:	8fa20030 */ 	lw	$v0,0x30($sp)
/*  f16259c:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f1625a0:	3c01800b */ 	lui	$at,0x800b
/*  f1625a4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f1625a8:	00220821 */ 	addu	$at,$at,$v0
/*  f1625ac:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f1625b0:	ac2dee70 */ 	sw	$t5,-0x1190($at)
.NB0f1625b4:
/*  f1625b4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.NB0f1625b8:
/*  f1625b8:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f1625bc:	03e00008 */ 	jr	$ra
/*  f1625c0:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void lvUpdateMiscSfx(void)
{
	s32 i;

	if (g_Vars.lvupdate240 == 0) {
		for (i = 0; i != ARRAYCOUNT(g_MiscSfxActiveTypes); i++) {
			lvSetMiscSfxState(i, false);
		}
	} else {
		bool usingboost = g_Vars.speedpillon
			&& lvGetSlowMotionType() == SLOWMOTION_OFF
			&& g_Vars.in_cutscene == false;
		bool usingrocket;

		lvSetMiscSfxState(MISCSFX_BOOSTHEARTBEAT, usingboost);

		usingrocket = false;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.players[i]->visionmode == VISIONMODE_SLAYERROCKET) {
				usingrocket = true;
			}
		}

		lvSetMiscSfxState(MISCSFX_SLAYERROCKETHUM, usingrocket);
		lvSetMiscSfxState(MISCSFX_SLAYERROCKETBEEP, usingrocket);
	}

	if (g_Vars.lvupdate240 == 0 && g_MiscAudioHandle && audioIsPlaying(g_MiscAudioHandle)) {
		audioStop(g_MiscAudioHandle);
	}
}

#if VERSION >= VERSION_NTSC_1_0
void lvInit(s32 stagenum)
{
	lvCancelFade();

	var80084014 = false;
	var80084010 = 0;

	joy00013900();

	g_Vars.joydisableframestogo = 10;
	g_Vars.paksconnected2 = 0;
	g_Vars.paksconnected = 0;
	g_Vars.stagenum = stagenum;

	cheatsActivate();

	var80084040 = true;
	g_Vars.lvframenum = 0;
	var80084050 = 0;

	g_Vars.lvframe60 = 0;
	g_Vars.lvupdate240 = 4;

	g_Vars.lvupdate240f = 1;
	g_Vars.lvupdate240frealprev = PALUPF(1.0f);
	g_Vars.lvupdate240freal = g_Vars.lvupdate240frealprev;

	g_StageTimeElapsed60 = 0;
	g_StageTimeElapsed1f = 0;

	g_Vars.speedpilltime = 0;
	g_Vars.speedpillchange = 0;
	g_Vars.speedpillwant = 0;
	g_Vars.speedpillon = false;

	g_Vars.restartlevel = false;
	g_Vars.aibuddiesspawned = false;
	g_Vars.totalkills = 0;
	g_Vars.antiheadnum = -1;
	g_Vars.antibodynum = -1;
	g_Vars.dontplaynrg = false;
	g_Vars.in_cutscene = false;
	g_Vars.autocutplaying = false;
	g_Vars.autocutfinished = false;
	g_Vars.autocutgroupskip = false;

	g_MiscAudioHandle = NULL;

	func0f16d324();
	func0f011124(true);
	func0f013b80();
	texturesLoadConfigs();
	fontsLoadForCurrentStage();
	hudmsgsInit();

	if (stagenum == STAGE_TEST_OLD) {
		func0f00b480();
	}

	if (stagenum == STAGE_TITLE) {
		func0f00b480();
	} else if (stagenum == STAGE_BOOTPAKMENU) {
		// empty
	} else if (stagenum == STAGE_CREDITS) {
		// empty
	} else if (stagenum == STAGE_4MBMENU) {
		// empty
	} else {
		s32 i;
		s32 j;

		stageLoadTiles();
		bgInit(g_Vars.stagenum);
		bgBuildTables(g_Vars.stagenum);
		func0f0147a0(g_Vars.stagenum);

		if (g_Vars.normmplayerisrunning) {
			musicSetStageAndStartMusic(stagenum);
		} else {
			musicSetStage(stagenum);
		}

		if (g_Vars.normmplayerisrunning) {
			mpApplyLimits();
		}

		if (g_Vars.mplayerisrunning == false) {
			g_Vars.playerstats[0].mpindex = 4;
			g_MpPlayers[4].base.contpad1 = 0;
			g_MpPlayers[4].base.contpad2 = 1;
		}

		for (i = 0; i != ARRAYCOUNT(g_Vars.playerstats); i++) {
			g_Vars.playerstats[i].damagescale = 1;
			g_Vars.playerstats[i].drawplayercount = 0;
			g_Vars.playerstats[i].distance = 0;
			g_Vars.playerstats[i].backshotcount = 0;
			g_Vars.playerstats[i].armourcount = 0;
			g_Vars.playerstats[i].fastest2kills = S32_MAX;
			g_Vars.playerstats[i].slowest2kills = 0;
			g_Vars.playerstats[i].maxkills = 0;
			g_Vars.playerstats[i].maxsimulkills = 0;
			g_Vars.playerstats[i].longestlife = 0;
			g_Vars.playerstats[i].shortestlife = S32_MAX;
			g_Vars.playerstats[i].tokenheldtime = 0;
			g_Vars.playerstats[i].damreceived = 0;
			g_Vars.playerstats[i].damtransmitted = 0;

			for (j = 0; j != ARRAYCOUNT(g_Vars.playerstats[i].kills); j++) {
				g_Vars.playerstats[i].kills[j] = 0;
			}
		}
	}

	mpSetDefaultNamesIfEmpty();
	func0002373c();
	objectivesReset();
	func0f013ba0();
	func0f011110();
	func0f0108d0();
	setupLoadFiles(stagenum);
	mpPrepareScenario();
	gvarsInitProps();
	setupInit();
	func0f00b510();
	stageChooseActiveHeads(stagenum);
	setupParseObjects(stagenum);
	tagsAllocatePtrs();
	explosionsInit();
	smokeInit();
	sparksInit();
	weatherInit();
	lvStopAllMiscSfx();

	switch (g_Vars.stagenum) {
	case STAGE_ESCAPE:
	case STAGE_EXTRACTION:
	case STAGE_INFILTRATION:
	case STAGE_DEFECTION:
	case STAGE_ATTACKSHIP:
	case STAGE_TEST_OLD:
		skyInit();
		break;
	}

	func0f0099a4();
	func0f0147d0();
	lasersightsReset();
	stub0f013540();
	shardsInit();
	frUnloadData();

	if (g_Vars.stagenum == STAGE_TITLE) {
		// empty
	} else if (stagenum == STAGE_BOOTPAKMENU) {
		setCurrentPlayerNum(0);
		menuInit();
	} else if (stagenum == STAGE_4MBMENU) {
		setCurrentPlayerNum(0);
		menuInit();
	} else if (stagenum == STAGE_CREDITS) {
		creditsInit();
	} else {
		s32 i;

		func0f1777f8();
		casingsReset();

		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);
			g_Vars.currentplayer->usedowntime = 0;
			g_Vars.currentplayer->invdowntime = g_Vars.currentplayer->usedowntime;

			menuInit();
			amInit();
			invInitGunsHeld();
			func0f010bb0();
			currentPlayerResetToDefault();
			currentPlayerInit();
			currentPlayerSpawn();
			currentPlayerInitAnimation();

			if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
				currentPlayerCalculateAiBuddyNums();
			}
		}

		acousticReset();
		func0f0b65f8();
		func0f001bdc();
		setCurrentPlayerNum(0);
	}

	if (g_Vars.lvmpbotlevel) {
		mpCalculateTeamIsOnlyAi();
	}

	func0f11a2e4();
	snd0000eadc();

	if (stagenum == STAGE_BOOTPAKMENU) {
		pakPushPakMenuDialog();
	}

	if (stagenum == STAGE_4MBMENU) {
		func0f10cb2c();
	}

	if (IS8MB()) {
		func0f14a3c4();
	}

	func0f011124(false);
	var80084018 = 1;
	bbufResetIndexes();
	lvSetPaused(0);

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *i = (s32 *)&lvGetSlowMotionType;
		s32 *end = (s32 *)&lvTick;

		while (i < end) {
			checksum += *i;
			i++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			u32 address = 0;
			u32 buffer[4];
			buffer[0] = 0xbb8b80bd;
			buffer[1] = 0xffffffff;
			buffer[2] = 0x020f0100;
			buffer[3] = 0xcd31100b;
			osEepromLongWrite(&var80099e78, address, (u8 *)&buffer, 0x10);
			var800a2380[4].unk2be = 0;
		}
	}
#endif
}
#else
GLOBAL_ASM(
glabel lvInit
.late_rodata
glabel var7f1b1ed8nc
.word lvInit+0x38c
glabel var7f1b1edcnc
.word lvInit+0x394
glabel var7f1b1ee0nc
.word lvInit+0x394
glabel var7f1b1ee4nc
.word lvInit+0x394
glabel var7f1b1ee8nc
.word lvInit+0x394
glabel var7f1b1eecnc
.word lvInit+0x394
glabel var7f1b1ef0nc
.word lvInit+0x394
glabel var7f1b1ef4nc
.word lvInit+0x394
glabel var7f1b1ef8nc
.word lvInit+0x394
glabel var7f1b1efcnc
.word lvInit+0x38c
glabel var7f1b1f00nc
.word lvInit+0x394
glabel var7f1b1f04nc
.word lvInit+0x394
glabel var7f1b1f08nc
.word lvInit+0x394
glabel var7f1b1f0cnc
.word lvInit+0x394
glabel var7f1b1f10nc
.word lvInit+0x394
glabel var7f1b1f14nc
.word lvInit+0x394
glabel var7f1b1f18nc
.word lvInit+0x394
glabel var7f1b1f1cnc
.word lvInit+0x394
glabel var7f1b1f20nc
.word lvInit+0x394
glabel var7f1b1f24nc
.word lvInit+0x394
glabel var7f1b1f28nc
.word lvInit+0x394
glabel var7f1b1f2cnc
.word lvInit+0x394
glabel var7f1b1f30nc
.word lvInit+0x38c
glabel var7f1b1f34nc
.word lvInit+0x38c
glabel var7f1b1f38nc
.word lvInit+0x394
glabel var7f1b1f3cnc
.word lvInit+0x394
glabel var7f1b1f40nc
.word lvInit+0x394
glabel var7f1b1f44nc
.word lvInit+0x38c
.text
/*  f1627b8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1627bc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1627c0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1627c4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1627c8:	0fc58c64 */ 	jal	lvCancelFade
/*  f1627cc:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1627d0:	3c018008 */ 	lui	$at,0x8008
/*  f1627d4:	ac206874 */ 	sw	$zero,0x6874($at)
/*  f1627d8:	3c018008 */ 	lui	$at,0x8008
/*  f1627dc:	0c005812 */ 	jal	joy000150c4
/*  f1627e0:	ac206870 */ 	sw	$zero,0x6870($at)
/*  f1627e4:	10400008 */ 	beqz	$v0,.NB0f162808
/*  f1627e8:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1627ec:	24a51e20 */ 	addiu	$a1,$a1,0x1e20
/*  f1627f0:	0c00581b */ 	jal	joy000150e8
/*  f1627f4:	240402f8 */ 	addiu	$a0,$zero,0x2f8
/*  f1627f8:	3c11800a */ 	lui	$s1,0x800a
/*  f1627fc:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f162800:	240e000a */ 	addiu	$t6,$zero,0xa
/*  f162804:	ae2e04d8 */ 	sw	$t6,0x4d8($s1)
.NB0f162808:
/*  f162808:	3c11800a */ 	lui	$s1,0x800a
/*  f16280c:	8faf0020 */ 	lw	$t7,0x20($sp)
/*  f162810:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f162814:	a22004d1 */ 	sb	$zero,0x4d1($s1)
/*  f162818:	a22004d0 */ 	sb	$zero,0x4d0($s1)
/*  f16281c:	0fc40c64 */ 	jal	cheatsActivate
/*  f162820:	ae2f04b4 */ 	sw	$t7,0x4b4($s1)
/*  f162824:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f162828:	3c018008 */ 	lui	$at,0x8008
/*  f16282c:	ac3868a0 */ 	sw	$t8,0x68a0($at)
/*  f162830:	ae20000c */ 	sw	$zero,0xc($s1)
/*  f162834:	3c018008 */ 	lui	$at,0x8008
/*  f162838:	ac2068b0 */ 	sw	$zero,0x68b0($at)
/*  f16283c:	3c013f80 */ 	lui	$at,0x3f80
/*  f162840:	44812000 */ 	mtc1	$at,$f4
/*  f162844:	44813000 */ 	mtc1	$at,$f6
/*  f162848:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f16284c:	e6240050 */ 	swc1	$f4,0x50($s1)
/*  f162850:	c6280050 */ 	lwc1	$f8,0x50($s1)
/*  f162854:	44800000 */ 	mtc1	$zero,$f0
/*  f162858:	ae200008 */ 	sw	$zero,0x8($s1)
/*  f16285c:	ae260034 */ 	sw	$a2,0x34($s1)
/*  f162860:	3c018008 */ 	lui	$at,0x8008
/*  f162864:	e6260044 */ 	swc1	$f6,0x44($s1)
/*  f162868:	e628004c */ 	swc1	$f8,0x4c($s1)
/*  f16286c:	ac206884 */ 	sw	$zero,0x6884($at)
/*  f162870:	3c018008 */ 	lui	$at,0x8008
/*  f162874:	e420689c */ 	swc1	$f0,0x689c($at)
/*  f162878:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f16287c:	ae20045c */ 	sw	$zero,0x45c($s1)
/*  f162880:	ae200460 */ 	sw	$zero,0x460($s1)
/*  f162884:	ae200464 */ 	sw	$zero,0x464($s1)
/*  f162888:	ae200468 */ 	sw	$zero,0x468($s1)
/*  f16288c:	ae20046c */ 	sw	$zero,0x46c($s1)
/*  f162890:	ae200478 */ 	sw	$zero,0x478($s1)
/*  f162894:	ae200488 */ 	sw	$zero,0x488($s1)
/*  f162898:	ae220440 */ 	sw	$v0,0x440($s1)
/*  f16289c:	ae220444 */ 	sw	$v0,0x444($s1)
/*  f1628a0:	ae2004c8 */ 	sw	$zero,0x4c8($s1)
/*  f1628a4:	ae2004cc */ 	sw	$zero,0x4cc($s1)
/*  f1628a8:	a22004d3 */ 	sb	$zero,0x4d3($s1)
/*  f1628ac:	a22004d6 */ 	sb	$zero,0x4d6($s1)
/*  f1628b0:	a22004d7 */ 	sb	$zero,0x4d7($s1)
/*  f1628b4:	3c018008 */ 	lui	$at,0x8008
/*  f1628b8:	0fc5a026 */ 	jal	func0f16d324
/*  f1628bc:	ac206894 */ 	sw	$zero,0x6894($at)
/*  f1628c0:	0fc04399 */ 	jal	func0f011124
/*  f1628c4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1628c8:	0fc04e28 */ 	jal	func0f013b80
/*  f1628cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1628d0:	0fc5b898 */ 	jal	texturesLoadConfigs
/*  f1628d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1628d8:	0fc5367b */ 	jal	fontsLoadForCurrentStage
/*  f1628dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1628e0:	0fc36cec */ 	jal	hudmsgsInit
/*  f1628e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1628e8:	8fa20020 */ 	lw	$v0,0x20($sp)
/*  f1628ec:	2410004e */ 	addiu	$s0,$zero,0x4e
/*  f1628f0:	54500005 */ 	bnel	$v0,$s0,.NB0f162908
/*  f1628f4:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f1628f8:	0fc02c4c */ 	jal	func0f00b480
/*  f1628fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162900:	8fa20020 */ 	lw	$v0,0x20($sp)
/*  f162904:	2401005a */ 	addiu	$at,$zero,0x5a
.NB0f162908:
/*  f162908:	54410006 */ 	bnel	$v0,$at,.NB0f162924
/*  f16290c:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f162910:	0fc02c4c */ 	jal	func0f00b480
/*  f162914:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162918:	10000053 */ 	beqz	$zero,.NB0f162a68
/*  f16291c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162920:	2401005b */ 	addiu	$at,$zero,0x5b
.NB0f162924:
/*  f162924:	54410004 */ 	bnel	$v0,$at,.NB0f162938
/*  f162928:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f16292c:	1000004e */ 	beqz	$zero,.NB0f162a68
/*  f162930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162934:	2401005c */ 	addiu	$at,$zero,0x5c
.NB0f162938:
/*  f162938:	54410004 */ 	bnel	$v0,$at,.NB0f16294c
/*  f16293c:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f162940:	10000049 */ 	beqz	$zero,.NB0f162a68
/*  f162944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162948:	2401005d */ 	addiu	$at,$zero,0x5d
.NB0f16294c:
/*  f16294c:	14410003 */ 	bne	$v0,$at,.NB0f16295c
/*  f162950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162954:	10000044 */ 	beqz	$zero,.NB0f162a68
/*  f162958:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f16295c:
/*  f16295c:	0fc04e84 */ 	jal	stageLoadTiles
/*  f162960:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162964:	0fc55745 */ 	jal	bgInit
/*  f162968:	8e2404b4 */ 	lw	$a0,0x4b4($s1)
/*  f16296c:	0fc55818 */ 	jal	bgBuildTables
/*  f162970:	8e2404b4 */ 	lw	$a0,0x4b4($s1)
/*  f162974:	0fc05130 */ 	jal	func0f0147a0
/*  f162978:	8e2404b4 */ 	lw	$a0,0x4b4($s1)
/*  f16297c:	8e390318 */ 	lw	$t9,0x318($s1)
/*  f162980:	13200006 */ 	beqz	$t9,.NB0f16299c
/*  f162984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162988:	0fc5a199 */ 	jal	musicSetStageAndStartMusic
/*  f16298c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f162990:	44800000 */ 	mtc1	$zero,$f0
/*  f162994:	10000005 */ 	beqz	$zero,.NB0f1629ac
/*  f162998:	24060004 */ 	addiu	$a2,$zero,0x4
.NB0f16299c:
/*  f16299c:	0fc5a1ab */ 	jal	musicSetStage
/*  f1629a0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f1629a4:	44800000 */ 	mtc1	$zero,$f0
/*  f1629a8:	24060004 */ 	addiu	$a2,$zero,0x4
.NB0f1629ac:
/*  f1629ac:	8e290318 */ 	lw	$t1,0x318($s1)
/*  f1629b0:	51200006 */ 	beqzl	$t1,.NB0f1629cc
/*  f1629b4:	8e2a0314 */ 	lw	$t2,0x314($s1)
/*  f1629b8:	0fc60a4d */ 	jal	mpApplyLimits
/*  f1629bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1629c0:	44800000 */ 	mtc1	$zero,$f0
/*  f1629c4:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f1629c8:	8e2a0314 */ 	lw	$t2,0x314($s1)
.NB0f1629cc:
/*  f1629cc:	3c0c800a */ 	lui	$t4,0x800a
/*  f1629d0:	2585e6c0 */ 	addiu	$a1,$t4,-6464
/*  f1629d4:	15400007 */ 	bnez	$t2,.NB0f1629f4
/*  f1629d8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f1629dc:	3c02800b */ 	lui	$v0,0x800b
/*  f1629e0:	24421068 */ 	addiu	$v0,$v0,0x1068
/*  f1629e4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1629e8:	ae2600e4 */ 	sw	$a2,0xe4($s1)
/*  f1629ec:	a04002c5 */ 	sb	$zero,0x2c5($v0)
/*  f1629f0:	a04b02c6 */ 	sb	$t3,0x2c6($v0)
.NB0f1629f4:
/*  f1629f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f1629f8:	3c08800a */ 	lui	$t0,0x800a
/*  f1629fc:	3c077fff */ 	lui	$a3,0x7fff
/*  f162a00:	44811000 */ 	mtc1	$at,$f2
/*  f162a04:	34e7ffff */ 	ori	$a3,$a3,0xffff
/*  f162a08:	2508e8c0 */ 	addiu	$t0,$t0,-5952
.NB0f162a0c:
/*  f162a0c:	e48200d0 */ 	swc1	$f2,0xd0($a0)
/*  f162a10:	ac8000a8 */ 	sw	$zero,0xa8($a0)
/*  f162a14:	e48000ac */ 	swc1	$f0,0xac($a0)
/*  f162a18:	ac8000b0 */ 	sw	$zero,0xb0($a0)
/*  f162a1c:	e48000b4 */ 	swc1	$f0,0xb4($a0)
/*  f162a20:	ac8700b8 */ 	sw	$a3,0xb8($a0)
/*  f162a24:	ac8000bc */ 	sw	$zero,0xbc($a0)
/*  f162a28:	ac8000c8 */ 	sw	$zero,0xc8($a0)
/*  f162a2c:	ac8000cc */ 	sw	$zero,0xcc($a0)
/*  f162a30:	ac8000c0 */ 	sw	$zero,0xc0($a0)
/*  f162a34:	ac8700c4 */ 	sw	$a3,0xc4($a0)
/*  f162a38:	ac8000d4 */ 	sw	$zero,0xd4($a0)
/*  f162a3c:	e48000ec */ 	swc1	$f0,0xec($a0)
/*  f162a40:	e48000f0 */ 	swc1	$f0,0xf0($a0)
/*  f162a44:	00001025 */ 	or	$v0,$zero,$zero
/*  f162a48:	00a01825 */ 	or	$v1,$a1,$zero
.NB0f162a4c:
/*  f162a4c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f162a50:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f162a54:	1446fffd */ 	bne	$v0,$a2,.NB0f162a4c
/*  f162a58:	ac600094 */ 	sw	$zero,0x94($v1)
/*  f162a5c:	24a50080 */ 	addiu	$a1,$a1,0x80
/*  f162a60:	14a8ffea */ 	bne	$a1,$t0,.NB0f162a0c
/*  f162a64:	24840080 */ 	addiu	$a0,$a0,0x80
.NB0f162a68:
/*  f162a68:	0fc609dc */ 	jal	mpSetDefaultNamesIfEmpty
/*  f162a6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162a70:	0c0092c7 */ 	jal	func0002373c
/*  f162a74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162a78:	0fc041c4 */ 	jal	objectivesReset
/*  f162a7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162a80:	0fc04e30 */ 	jal	func0f013ba0
/*  f162a84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162a88:	0fc04394 */ 	jal	func0f011110
/*  f162a8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162a90:	0fc04180 */ 	jal	func0f0108d0
/*  f162a94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162a98:	0fc03a25 */ 	jal	setupLoadFiles
/*  f162a9c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f162aa0:	0fc6019d */ 	jal	mpPrepareScenario
/*  f162aa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162aa8:	0fc02fbc */ 	jal	gvarsInitProps
/*  f162aac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ab0:	0fc03050 */ 	jal	setupInit
/*  f162ab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ab8:	0fc02c70 */ 	jal	func0f00b510
/*  f162abc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ac0:	0fc02d34 */ 	jal	stageChooseActiveHeads
/*  f162ac4:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f162ac8:	0fc03ba9 */ 	jal	setupParseObjects
/*  f162acc:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f162ad0:	0fc24d44 */ 	jal	tagsAllocatePtrs
/*  f162ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ad8:	0fc04b4c */ 	jal	explosionsInit
/*  f162adc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ae0:	0fc04b94 */ 	jal	smokeInit
/*  f162ae4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ae8:	0fc04be0 */ 	jal	sparksInit
/*  f162aec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162af0:	0fc04bf0 */ 	jal	weatherInit
/*  f162af4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162af8:	0fc58914 */ 	jal	lvStopAllMiscSfx
/*  f162afc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162b00:	8e2204b4 */ 	lw	$v0,0x4b4($s1)
/*  f162b04:	28410035 */ 	slti	$at,$v0,0x35
/*  f162b08:	54200006 */ 	bnezl	$at,.NB0f162b24
/*  f162b0c:	244dffe7 */ 	addiu	$t5,$v0,-25
/*  f162b10:	1050000c */ 	beq	$v0,$s0,.NB0f162b44
/*  f162b14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162b18:	1000000c */ 	beqz	$zero,.NB0f162b4c
/*  f162b1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162b20:	244dffe7 */ 	addiu	$t5,$v0,-25
.NB0f162b24:
/*  f162b24:	2da1001c */ 	sltiu	$at,$t5,0x1c
/*  f162b28:	10200008 */ 	beqz	$at,.NB0f162b4c
/*  f162b2c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f162b30:	3c017f1b */ 	lui	$at,0x7f1b
/*  f162b34:	002d0821 */ 	addu	$at,$at,$t5
/*  f162b38:	8c2d1ed8 */ 	lw	$t5,0x1ed8($at)
/*  f162b3c:	01a00008 */ 	jr	$t5
/*  f162b40:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f162b44:
/*  f162b44:	0fc4c31e */ 	jal	skyInit
/*  f162b48:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f162b4c:
/*  f162b4c:	0fc02595 */ 	jal	func0f0099a4
/*  f162b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162b54:	0fc0513c */ 	jal	func0f0147d0
/*  f162b58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162b5c:	0fc05146 */ 	jal	lasersightsReset
/*  f162b60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162b64:	0fc04c98 */ 	jal	stub0f013540
/*  f162b68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162b6c:	0fc04dc4 */ 	jal	shardsInit
/*  f162b70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162b74:	0fc65d63 */ 	jal	frUnloadData
/*  f162b78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162b7c:	8e2e04b4 */ 	lw	$t6,0x4b4($s1)
/*  f162b80:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f162b84:	8faf0020 */ 	lw	$t7,0x20($sp)
/*  f162b88:	11c10080 */ 	beq	$t6,$at,.NB0f162d8c
/*  f162b8c:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f162b90:	15e10007 */ 	bne	$t7,$at,.NB0f162bb0
/*  f162b94:	8fb80020 */ 	lw	$t8,0x20($sp)
/*  f162b98:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f162b9c:	00002025 */ 	or	$a0,$zero,$zero
/*  f162ba0:	0fc3d53b */ 	jal	menuInit
/*  f162ba4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ba8:	10000079 */ 	beqz	$zero,.NB0f162d90
/*  f162bac:	8e2a031c */ 	lw	$t2,0x31c($s1)
.NB0f162bb0:
/*  f162bb0:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f162bb4:	17010007 */ 	bne	$t8,$at,.NB0f162bd4
/*  f162bb8:	8fb90020 */ 	lw	$t9,0x20($sp)
/*  f162bbc:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f162bc0:	00002025 */ 	or	$a0,$zero,$zero
/*  f162bc4:	0fc3d53b */ 	jal	menuInit
/*  f162bc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162bcc:	10000070 */ 	beqz	$zero,.NB0f162d90
/*  f162bd0:	8e2a031c */ 	lw	$t2,0x31c($s1)
.NB0f162bd4:
/*  f162bd4:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f162bd8:	17210005 */ 	bne	$t9,$at,.NB0f162bf0
/*  f162bdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162be0:	0fc4d7f1 */ 	jal	creditsInit
/*  f162be4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162be8:	10000069 */ 	beqz	$zero,.NB0f162d90
/*  f162bec:	8e2a031c */ 	lw	$t2,0x31c($s1)
.NB0f162bf0:
/*  f162bf0:	0fc5c926 */ 	jal	func0f1777f8
/*  f162bf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162bf8:	0fc04218 */ 	jal	casingsReset
/*  f162bfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162c00:	8e29006c */ 	lw	$t1,0x6c($s1)
/*  f162c04:	00008025 */ 	or	$s0,$zero,$zero
/*  f162c08:	00002825 */ 	or	$a1,$zero,$zero
/*  f162c0c:	11200003 */ 	beqz	$t1,.NB0f162c1c
/*  f162c10:	00002025 */ 	or	$a0,$zero,$zero
/*  f162c14:	10000001 */ 	beqz	$zero,.NB0f162c1c
/*  f162c18:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f162c1c:
/*  f162c1c:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f162c20:	00001825 */ 	or	$v1,$zero,$zero
/*  f162c24:	11400003 */ 	beqz	$t2,.NB0f162c34
/*  f162c28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162c2c:	10000001 */ 	beqz	$zero,.NB0f162c34
/*  f162c30:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f162c34:
/*  f162c34:	8e2b0064 */ 	lw	$t3,0x64($s1)
/*  f162c38:	00001025 */ 	or	$v0,$zero,$zero
/*  f162c3c:	11600003 */ 	beqz	$t3,.NB0f162c4c
/*  f162c40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162c44:	10000001 */ 	beqz	$zero,.NB0f162c4c
/*  f162c48:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f162c4c:
/*  f162c4c:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*  f162c50:	11800003 */ 	beqz	$t4,.NB0f162c60
/*  f162c54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162c58:	10000001 */ 	beqz	$zero,.NB0f162c60
/*  f162c5c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f162c60:
/*  f162c60:	00436821 */ 	addu	$t5,$v0,$v1
/*  f162c64:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f162c68:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f162c6c:	19e0003f */ 	blez	$t7,.NB0f162d6c
/*  f162c70:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f162c74:
/*  f162c74:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f162c78:	02002025 */ 	or	$a0,$s0,$zero
/*  f162c7c:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f162c80:	a700024e */ 	sh	$zero,0x24e($t8)
/*  f162c84:	8e220284 */ 	lw	$v0,0x284($s1)
/*  f162c88:	8459024e */ 	lh	$t9,0x24e($v0)
/*  f162c8c:	0fc3d53b */ 	jal	menuInit
/*  f162c90:	a459024c */ 	sh	$t9,0x24c($v0)
/*  f162c94:	0fc3eb1b */ 	jal	amInit
/*  f162c98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162c9c:	0fc0485c */ 	jal	invInitGunsHeld
/*  f162ca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ca4:	0fc0423c */ 	jal	func0f010bb0
/*  f162ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162cac:	0fc2d548 */ 	jal	currentPlayerResetToDefault
/*  f162cb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162cb4:	0fc0458d */ 	jal	currentPlayerInit
/*  f162cb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162cbc:	0fc2d75f */ 	jal	currentPlayerSpawn
/*  f162cc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162cc4:	0fc048e9 */ 	jal	currentPlayerInitAnimation
/*  f162cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ccc:	8e290318 */ 	lw	$t1,0x318($s1)
/*  f162cd0:	3c0a800b */ 	lui	$t2,0x800b
/*  f162cd4:	51200008 */ 	beqzl	$t1,.NB0f162cf8
/*  f162cd8:	8e2c006c */ 	lw	$t4,0x6c($s1)
/*  f162cdc:	8d4a1444 */ 	lw	$t2,0x1444($t2)
/*  f162ce0:	314b0002 */ 	andi	$t3,$t2,0x2
/*  f162ce4:	51600004 */ 	beqzl	$t3,.NB0f162cf8
/*  f162ce8:	8e2c006c */ 	lw	$t4,0x6c($s1)
/*  f162cec:	0fc48d1d */ 	jal	currentPlayerCalculateAiBuddyNums
/*  f162cf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162cf4:	8e2c006c */ 	lw	$t4,0x6c($s1)
.NB0f162cf8:
/*  f162cf8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f162cfc:	00002825 */ 	or	$a1,$zero,$zero
/*  f162d00:	11800003 */ 	beqz	$t4,.NB0f162d10
/*  f162d04:	00002025 */ 	or	$a0,$zero,$zero
/*  f162d08:	10000001 */ 	beqz	$zero,.NB0f162d10
/*  f162d0c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f162d10:
/*  f162d10:	8e2d0068 */ 	lw	$t5,0x68($s1)
/*  f162d14:	00001825 */ 	or	$v1,$zero,$zero
/*  f162d18:	00001025 */ 	or	$v0,$zero,$zero
/*  f162d1c:	11a00003 */ 	beqz	$t5,.NB0f162d2c
/*  f162d20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162d24:	10000001 */ 	beqz	$zero,.NB0f162d2c
/*  f162d28:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f162d2c:
/*  f162d2c:	8e2e0064 */ 	lw	$t6,0x64($s1)
/*  f162d30:	11c00003 */ 	beqz	$t6,.NB0f162d40
/*  f162d34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162d38:	10000001 */ 	beqz	$zero,.NB0f162d40
/*  f162d3c:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f162d40:
/*  f162d40:	8e2f0070 */ 	lw	$t7,0x70($s1)
/*  f162d44:	11e00003 */ 	beqz	$t7,.NB0f162d54
/*  f162d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162d4c:	10000001 */ 	beqz	$zero,.NB0f162d54
/*  f162d50:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f162d54:
/*  f162d54:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f162d58:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f162d5c:	03254821 */ 	addu	$t1,$t9,$a1
/*  f162d60:	0209082a */ 	slt	$at,$s0,$t1
/*  f162d64:	1420ffc3 */ 	bnez	$at,.NB0f162c74
/*  f162d68:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f162d6c:
/*  f162d6c:	0fc2d131 */ 	jal	acousticReset
/*  f162d70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162d74:	0fc2d0d6 */ 	jal	func0f0b65f8
/*  f162d78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162d7c:	0fc0071d */ 	jal	func0f001bdc
/*  f162d80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162d84:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f162d88:	00002025 */ 	or	$a0,$zero,$zero
.NB0f162d8c:
/*  f162d8c:	8e2a031c */ 	lw	$t2,0x31c($s1)
.NB0f162d90:
/*  f162d90:	11400003 */ 	beqz	$t2,.NB0f162da0
/*  f162d94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162d98:	0fc6089d */ 	jal	mpCalculateTeamIsOnlyAi
/*  f162d9c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f162da0:
/*  f162da0:	0fc4506d */ 	jal	func0f11a2e4
/*  f162da4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162da8:	0c003ca1 */ 	jal	snd0000eadc
/*  f162dac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162db0:	8fab0020 */ 	lw	$t3,0x20($sp)
/*  f162db4:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f162db8:	55610004 */ 	bnel	$t3,$at,.NB0f162dcc
/*  f162dbc:	8fac0020 */ 	lw	$t4,0x20($sp)
/*  f162dc0:	0fc41ea4 */ 	jal	pakPushPakMenuDialog
/*  f162dc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162dc8:	8fac0020 */ 	lw	$t4,0x20($sp)
.NB0f162dcc:
/*  f162dcc:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f162dd0:	15810003 */ 	bne	$t4,$at,.NB0f162de0
/*  f162dd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162dd8:	0fc41f13 */ 	jal	func0f10cb2c
/*  f162ddc:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f162de0:
/*  f162de0:	3c0d8009 */ 	lui	$t5,0x8009
/*  f162de4:	91ad30e0 */ 	lbu	$t5,0x30e0($t5)
/*  f162de8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f162dec:	11a10003 */ 	beq	$t5,$at,.NB0f162dfc
/*  f162df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162df4:	0fc512e5 */ 	jal	func0f14a3c4
/*  f162df8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f162dfc:
/*  f162dfc:	0fc04399 */ 	jal	func0f011124
/*  f162e00:	00002025 */ 	or	$a0,$zero,$zero
/*  f162e04:	3c013f80 */ 	lui	$at,0x3f80
/*  f162e08:	44815000 */ 	mtc1	$at,$f10
/*  f162e0c:	3c018008 */ 	lui	$at,0x8008
/*  f162e10:	0c0009d6 */ 	jal	bbufResetIndexes
/*  f162e14:	e42a6878 */ 	swc1	$f10,0x6878($at)
/*  f162e18:	0fc59ebc */ 	jal	lvSetPaused
/*  f162e1c:	00002025 */ 	or	$a0,$zero,$zero
/*  f162e20:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f162e24:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f162e28:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f162e2c:	03e00008 */ 	jr	$ra
/*  f162e30:	27bd0020 */ 	addiu	$sp,$sp,0x20
);
#endif

void lvConfigureFade(u32 color, s16 num_frames)
{
	g_FadeNumFrames = num_frames;
	g_FadePrevColour = g_FadeColour;

	if (g_FadeNumFrames == 0) {
		g_FadeColour = color;
		g_FadeFrac = -1;
		return;
	}

	g_FadeFrac = 0;
	g_FadeColour = color;
	g_FadeDelay = 2;
}

Gfx *lvRenderFade(Gfx *gdl)
{
	u32 colour = g_FadeColour;
	u32 inset = 0;

	if (g_Vars.stagenum == STAGE_TEST_OLD) {
		inset = 61;
	}

	if (g_FadeFrac >= 0) {
		if (g_FadeDelay > 0) {
			g_FadeDelay--;
		} else {
#if VERSION >= VERSION_PAL_FINAL
			g_FadeFrac += g_Vars.diffframe60freal / g_FadeNumFrames;
#else
			g_FadeFrac += g_Vars.diffframe60f / g_FadeNumFrames;
#endif

			if (g_FadeFrac >= 1) {
				g_FadeFrac = -1;
			}
		}
	}

	if (g_FadeFrac < 0) {
		if ((g_FadeColour & 0xff) == 0) {
			return gdl;
		}
	} else {
		colour = colourBlend(g_FadeColour, g_FadePrevColour, g_FadeFrac * 255);
	}

	if ((colour & 0xff) == 0) {
		return gdl;
	}

	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);

	gDPFillRectangle(gdl++,
			viGetViewLeft(),
			viGetViewTop() + inset,
			viGetViewLeft() + viGetViewWidth() + 1,
			viGetViewTop() + viGetViewHeight() - inset + 2);

	return func0f153838(gdl);
}

bool lvIsFadeActive(void)
{
	return g_FadeFrac >= 0;
}

void lvCancelFade(void)
{
	g_FadeNumFrames = 0;
	g_FadeFrac = -1;
	g_FadePrevColour = 0;
	g_FadeColour = 0;
	g_FadeDelay = 0;
}

bool lvCheckCmpFollowThreat(struct threat *threat, s32 index)
{
	f32 sp76;
	f32 sp72;
	f32 sp68;
	f32 sp64;
	struct prop *prop = threat->prop;
	struct chrdata *chr;

	if (threat->prop && prop->chr) {
		switch (threat->prop->type) {
		case PROPTYPE_PLAYER:
			if (propGetPlayerNum(prop) == g_Vars.currentplayernum) {
				return false;
			}
			// fall through
		case PROPTYPE_CHR:
			chr = threat->prop->chr;

			if (chrIsDead(threat->prop->chr)) {
				if (index >= 0) {
					// Existing threat
					if (g_Vars.currentplayer->targetset[index] < PALDOWN(129)) {
						g_Vars.currentplayer->targetset[index] = PALDOWN(129);
					}

					if (g_Vars.currentplayer->targetset[index] >= (PAL ? 146 : 175)) {
						threat->prop = NULL;
						return false;
					}
				} else {
					// Attempting to add a new threat, but chr is dead
					threat->prop = NULL;
					return false;
				}
			}

			if ((threat->prop->flags & PROPFLAG_ONSCREEN)
					&& (chr->chrflags & CHRCFLAG_NOAUTOAIM) == 0) {
				struct model *model = chr->model;
				sp72 = -1;
				sp76 = -1;
				sp64 = -2;
				sp68 = -2;

				if (modelSetRedBox(model, &sp64, &sp72, &sp68, &sp76)) {
					break;
				}
				return false;
			}
			return false;
		case PROPTYPE_OBJ:
		case PROPTYPE_WEAPON:
			if (threat->prop->flags & PROPFLAG_ONSCREEN) {
				struct defaultobj *obj = threat->prop->obj;
				struct model *model = obj->model;
				sp72 = -1;
				sp76 = -1;
				sp64 = -2;
				sp68 = -2;

				if (modelSetRedBox(model, &sp64, &sp72, &sp68, &sp76)) {
					break;
				}
				return false;
			}
			return false;
		case PROPTYPE_DOOR:
		case PROPTYPE_EYESPY:
		case PROPTYPE_EXPLOSION:
		case PROPTYPE_SMOKE:
		default:
			return false;
		}

		threat->x1 = sp72 - 2;
		threat->x2 = sp64 + 2;
		threat->y1 = sp76 - 2;
		threat->y2 = sp68 + 2;
	}

	return true;
}

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func7f163414nb
.late_rodata
glabel var7f1b1f68
.word 0x40490fdb
.text
/*  f163414:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f163418:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f16341c:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f163420:	00808825 */ 	or	$s1,$a0,$zero
/*  f163424:	0fc46646 */ 	jal	debug0f119918nb
/*  f163428:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f16342c:	104000f6 */ 	beqz	$v0,.NB0f163808
/*  f163430:	3c10800a */ 	lui	$s0,0x800a
/*  f163434:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f163438:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f16343c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f163440:	25ef68c8 */ 	addiu	$t7,$t7,0x68c8
/*  f163444:	8de10000 */ 	lw	$at,0x0($t7)
/*  f163448:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f16344c:	c440036c */ 	lwc1	$f0,0x36c($v0)
/*  f163450:	27ae0050 */ 	addiu	$t6,$sp,0x50
/*  f163454:	c44e0374 */ 	lwc1	$f14,0x374($v0)
/*  f163458:	adc10000 */ 	sw	$at,0x0($t6)
/*  f16345c:	8de10008 */ 	lw	$at,0x8($t7)
/*  f163460:	add90004 */ 	sw	$t9,0x4($t6)
/*  f163464:	8df9000c */ 	lw	$t9,0xc($t7)
/*  f163468:	adc10008 */ 	sw	$at,0x8($t6)
/*  f16346c:	8de10010 */ 	lw	$at,0x10($t7)
/*  f163470:	add9000c */ 	sw	$t9,0xc($t6)
/*  f163474:	8df90014 */ 	lw	$t9,0x14($t7)
/*  f163478:	adc10010 */ 	sw	$at,0x10($t6)
/*  f16347c:	99e1001a */ 	lwr	$at,0x1a($t7)
/*  f163480:	add90014 */ 	sw	$t9,0x14($t6)
/*  f163484:	46000307 */ 	neg.s	$f12,$f0
/*  f163488:	0fc251b8 */ 	jal	atan2f
/*  f16348c:	b9c1001a */ 	swr	$at,0x1a($t6)
/*  f163490:	3c014334 */ 	lui	$at,0x4334
/*  f163494:	44812000 */ 	mtc1	$at,$f4
/*  f163498:	3c017f1b */ 	lui	$at,0x7f1b
/*  f16349c:	c4281f68 */ 	lwc1	$f8,0x1f68($at)
/*  f1634a0:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f1634a4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f1634a8:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1634ac:	24a51e28 */ 	addiu	$a1,$a1,0x1e28
/*  f1634b0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1634b4:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f1634b8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f1634bc:	44098000 */ 	mfc1	$t1,$f16
/*  f1634c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1634c4:	afa9004c */ 	sw	$t1,0x4c($sp)
/*  f1634c8:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f1634cc:	8c471ba0 */ 	lw	$a3,0x1ba0($v0)
/*  f1634d0:	0c004fc1 */ 	jal	sprintf
/*  f1634d4:	85460028 */ 	lh	$a2,0x28($t2)
/*  f1634d8:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f1634dc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1634e0:	3c067f1b */ 	lui	$a2,0x7f1b
/*  f1634e4:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f1634e8:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f1634ec:	24e71e44 */ 	addiu	$a3,$a3,0x1e44
/*  f1634f0:	c5920008 */ 	lwc1	$f18,0x8($t4)
/*  f1634f4:	24c61e40 */ 	addiu	$a2,$a2,0x1e40
/*  f1634f8:	24a51e34 */ 	addiu	$a1,$a1,0x1e34
/*  f1634fc:	46009121 */ 	cvt.d.s	$f4,$f18
/*  f163500:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*  f163504:	0c004fc1 */ 	jal	sprintf
/*  f163508:	f7a40010 */ 	sdc1	$f4,0x10($sp)
/*  f16350c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f163510:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f163514:	3c067f1b */ 	lui	$a2,0x7f1b
/*  f163518:	8db800bc */ 	lw	$t8,0xbc($t5)
/*  f16351c:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f163520:	24e71e58 */ 	addiu	$a3,$a3,0x1e58
/*  f163524:	c706000c */ 	lwc1	$f6,0xc($t8)
/*  f163528:	24c61e54 */ 	addiu	$a2,$a2,0x1e54
/*  f16352c:	24a51e48 */ 	addiu	$a1,$a1,0x1e48
/*  f163530:	46003221 */ 	cvt.d.s	$f8,$f6
/*  f163534:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f163538:	0c004fc1 */ 	jal	sprintf
/*  f16353c:	f7a80010 */ 	sdc1	$f8,0x10($sp)
/*  f163540:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f163544:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f163548:	3c067f1b */ 	lui	$a2,0x7f1b
/*  f16354c:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f163550:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f163554:	24e71e6c */ 	addiu	$a3,$a3,0x1e6c
/*  f163558:	c5ea0010 */ 	lwc1	$f10,0x10($t7)
/*  f16355c:	24c61e68 */ 	addiu	$a2,$a2,0x1e68
/*  f163560:	24a51e5c */ 	addiu	$a1,$a1,0x1e5c
/*  f163564:	46005421 */ 	cvt.d.s	$f16,$f10
/*  f163568:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f16356c:	0c004fc1 */ 	jal	sprintf
/*  f163570:	f7b00010 */ 	sdc1	$f16,0x10($sp)
/*  f163574:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f163578:	2401002d */ 	addiu	$at,$zero,0x2d
/*  f16357c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f163580:	24f90016 */ 	addiu	$t9,$a3,0x16
/*  f163584:	0321001a */ 	div	$zero,$t9,$at
/*  f163588:	00004012 */ 	mflo	$t0
/*  f16358c:	00084880 */ 	sll	$t1,$t0,0x2
/*  f163590:	01284823 */ 	subu	$t1,$t1,$t0
/*  f163594:	27aa0050 */ 	addiu	$t2,$sp,0x50
/*  f163598:	012a3021 */ 	addu	$a2,$t1,$t2
/*  f16359c:	24a51e70 */ 	addiu	$a1,$a1,0x1e70
/*  f1635a0:	0c004fc1 */ 	jal	sprintf
/*  f1635a4:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f1635a8:	0c002fb5 */ 	jal	viGetViewLeft
/*  f1635ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1635b0:	244b0011 */ 	addiu	$t3,$v0,0x11
/*  f1635b4:	0c002fb9 */ 	jal	viGetViewTop
/*  f1635b8:	afab007c */ 	sw	$t3,0x7c($sp)
/*  f1635bc:	24430011 */ 	addiu	$v1,$v0,0x11
/*  f1635c0:	2470000a */ 	addiu	$s0,$v1,0xa
/*  f1635c4:	afa30078 */ 	sw	$v1,0x78($sp)
/*  f1635c8:	0fc5374a */ 	jal	func0f153628
/*  f1635cc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1635d0:	0c002f77 */ 	jal	viGetWidth
/*  f1635d4:	00408825 */ 	or	$s1,$v0,$zero
/*  f1635d8:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f1635dc:	260c0001 */ 	addiu	$t4,$s0,0x1
/*  f1635e0:	240d0064 */ 	addiu	$t5,$zero,0x64
/*  f1635e4:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f1635e8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1635ec:	02202025 */ 	or	$a0,$s1,$zero
/*  f1635f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1635f4:	00403825 */ 	or	$a3,$v0,$zero
/*  f1635f8:	0fc53824 */ 	jal	func0f153a34
/*  f1635fc:	2466ffff */ 	addiu	$a2,$v1,-1
/*  f163600:	0c002f77 */ 	jal	viGetWidth
/*  f163604:	00408825 */ 	or	$s1,$v0,$zero
/*  f163608:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16360c:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f163610:	0c002f7b */ 	jal	viGetHeight
/*  f163614:	03008025 */ 	or	$s0,$t8,$zero
/*  f163618:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16361c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f163620:	8def236c */ 	lw	$t7,0x236c($t7)
/*  f163624:	8dce2370 */ 	lw	$t6,0x2370($t6)
/*  f163628:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f16362c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f163630:	02202025 */ 	or	$a0,$s1,$zero
/*  f163634:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f163638:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f16363c:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f163640:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f163644:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f163648:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f16364c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f163650:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f163654:	0fc541a6 */ 	jal	textRenderProjected
/*  f163658:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f16365c:	0c002fb5 */ 	jal	viGetViewLeft
/*  f163660:	00408825 */ 	or	$s1,$v0,$zero
/*  f163664:	24480057 */ 	addiu	$t0,$v0,0x57
/*  f163668:	0c002f77 */ 	jal	viGetWidth
/*  f16366c:	afa8007c */ 	sw	$t0,0x7c($sp)
/*  f163670:	00028400 */ 	sll	$s0,$v0,0x10
/*  f163674:	00104c03 */ 	sra	$t1,$s0,0x10
/*  f163678:	0c002f7b */ 	jal	viGetHeight
/*  f16367c:	01208025 */ 	or	$s0,$t1,$zero
/*  f163680:	3c0a8008 */ 	lui	$t2,0x8008
/*  f163684:	3c0b8008 */ 	lui	$t3,0x8008
/*  f163688:	8d6b236c */ 	lw	$t3,0x236c($t3)
/*  f16368c:	8d4a2370 */ 	lw	$t2,0x2370($t2)
/*  f163690:	240cffff */ 	addiu	$t4,$zero,-1
/*  f163694:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f163698:	02202025 */ 	or	$a0,$s1,$zero
/*  f16369c:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f1636a0:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f1636a4:	27a700b0 */ 	addiu	$a3,$sp,0xb0
/*  f1636a8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1636ac:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1636b0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1636b4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1636b8:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f1636bc:	0fc541a6 */ 	jal	textRenderProjected
/*  f1636c0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1636c4:	0c002fb5 */ 	jal	viGetViewLeft
/*  f1636c8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1636cc:	244d008d */ 	addiu	$t5,$v0,0x8d
/*  f1636d0:	0c002f77 */ 	jal	viGetWidth
/*  f1636d4:	afad007c */ 	sw	$t5,0x7c($sp)
/*  f1636d8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1636dc:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f1636e0:	0c002f7b */ 	jal	viGetHeight
/*  f1636e4:	03008025 */ 	or	$s0,$t8,$zero
/*  f1636e8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1636ec:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1636f0:	8def236c */ 	lw	$t7,0x236c($t7)
/*  f1636f4:	8dce2370 */ 	lw	$t6,0x2370($t6)
/*  f1636f8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f1636fc:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f163700:	02202025 */ 	or	$a0,$s1,$zero
/*  f163704:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f163708:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f16370c:	27a700a0 */ 	addiu	$a3,$sp,0xa0
/*  f163710:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f163714:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f163718:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f16371c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f163720:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f163724:	0fc541a6 */ 	jal	textRenderProjected
/*  f163728:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f16372c:	0c002fb5 */ 	jal	viGetViewLeft
/*  f163730:	00408825 */ 	or	$s1,$v0,$zero
/*  f163734:	244800c3 */ 	addiu	$t0,$v0,0xc3
/*  f163738:	0c002f77 */ 	jal	viGetWidth
/*  f16373c:	afa8007c */ 	sw	$t0,0x7c($sp)
/*  f163740:	00028400 */ 	sll	$s0,$v0,0x10
/*  f163744:	00104c03 */ 	sra	$t1,$s0,0x10
/*  f163748:	0c002f7b */ 	jal	viGetHeight
/*  f16374c:	01208025 */ 	or	$s0,$t1,$zero
/*  f163750:	3c0a8008 */ 	lui	$t2,0x8008
/*  f163754:	3c0b8008 */ 	lui	$t3,0x8008
/*  f163758:	8d6b236c */ 	lw	$t3,0x236c($t3)
/*  f16375c:	8d4a2370 */ 	lw	$t2,0x2370($t2)
/*  f163760:	240cffff */ 	addiu	$t4,$zero,-1
/*  f163764:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f163768:	02202025 */ 	or	$a0,$s1,$zero
/*  f16376c:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f163770:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f163774:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f163778:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f16377c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f163780:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f163784:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f163788:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f16378c:	0fc541a6 */ 	jal	textRenderProjected
/*  f163790:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f163794:	0c002fb5 */ 	jal	viGetViewLeft
/*  f163798:	00408825 */ 	or	$s1,$v0,$zero
/*  f16379c:	244d00f9 */ 	addiu	$t5,$v0,0xf9
/*  f1637a0:	0c002f77 */ 	jal	viGetWidth
/*  f1637a4:	afad007c */ 	sw	$t5,0x7c($sp)
/*  f1637a8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1637ac:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f1637b0:	0c002f7b */ 	jal	viGetHeight
/*  f1637b4:	03008025 */ 	or	$s0,$t8,$zero
/*  f1637b8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1637bc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1637c0:	8def236c */ 	lw	$t7,0x236c($t7)
/*  f1637c4:	8dce2370 */ 	lw	$t6,0x2370($t6)
/*  f1637c8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f1637cc:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1637d0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1637d4:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f1637d8:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f1637dc:	27a70080 */ 	addiu	$a3,$sp,0x80
/*  f1637e0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1637e4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f1637e8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f1637ec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1637f0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1637f4:	0fc541a6 */ 	jal	textRenderProjected
/*  f1637f8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1637fc:	0fc537a0 */ 	jal	func0f153780
/*  f163800:	00402025 */ 	or	$a0,$v0,$zero
/*  f163804:	00408825 */ 	or	$s1,$v0,$zero
.NB0f163808:
/*  f163808:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f16380c:	02201025 */ 	or	$v0,$s1,$zero
/*  f163810:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f163814:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f163818:	03e00008 */ 	jr	$ra
/*  f16381c:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);
#endif

void lvFindThreatsForProp(struct prop *prop, bool inchild, struct coord *playerpos, bool *activeslots, f32 *distances)
{
	bool condition = true;
	struct defaultobj *obj;
	bool pass;
	f32 sp88;
	f32 sp84;
	f32 sp80;
	f32 sp76;
	s32 i;
	struct model *model;
	struct weaponobj *weapon;

	if (!inchild && prop->z < 0) {
		condition = false;
	}

	if (prop->obj
			&& (prop->flags & PROPFLAG_ONSCREEN)
			&& (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON)
			&& condition) {
		pass = false;
		obj = prop->obj;
		model = prop->obj->model;

		if (obj
				&& obj->type == OBJTYPE_AUTOGUN
				&& (obj->flags2 & (OBJFLAG2_80000000 | OBJFLAG2_AICANNOTUSE)) == 0) {
			pass = true;
		}

		if (obj && obj->modelnum == MODEL_SK_SHUTTLE) {
			pass = true;
		}

		weapon = (struct weaponobj *)prop->obj;

		if (weapon && prop->obj->type == OBJTYPE_WEAPON) {
			switch (weapon->weaponnum) {
			case WEAPON_GRENADE:
			case WEAPON_NBOMB:
			case WEAPON_TIMEDMINE:
			case WEAPON_PROXIMITYMINE:
			case WEAPON_REMOTEMINE:
				pass = true;
				break;
			case WEAPON_DRAGON:
				if (weapon->gunfunc == (u32)FUNC_SECONDARY) {
					pass = true;
				}
				break;
			}
		}

		if (obj->modelnum == MODEL_TARGET && frIsTargetOneHitExplodable(prop)) {
			pass = true;
		}

		if (pass) {
			for (i = 0; i != 4; i++) {
				if (g_Vars.currentplayer->cmpfollowprops[i].prop == prop) {
					pass = false;
				}
			}
		}

		if (pass) {
			sp84 = -1;
			sp88 = -1;
			sp76 = -2;
			sp80 = -2;

			if (!modelSetRedBox(model, &sp76, &sp84, &sp80, &sp88)) {
				pass = false;
			}
		}

		if (pass) {
			f32 furtherestdist = 0;
			s32 index = -1;

			f32 sqdist =
				(prop->pos.f[0] - playerpos->f[0]) * (prop->pos.f[0] - playerpos->f[0]) +
				(prop->pos.f[1] - playerpos->f[1]) * (prop->pos.f[1] - playerpos->f[1]) +
				(prop->pos.f[2] - playerpos->f[2]) * (prop->pos.f[2] - playerpos->f[2]);

			for (i = 0; i < 4; i++) {
				if (!activeslots[i]) {
					index = i;
				}
			}

			if (index == -1) {
				// No slots available - consider replacing the furtherest
				for (i = 0; i != 4; i++) {
					if (distances[i] > furtherestdist) {
						furtherestdist = distances[i];
						index = i;
					}
				}

				if (sqdist >= furtherestdist) {
					index = -1;
				}
			}

			if (index >= 0) {
				g_Vars.currentplayer->cmpfollowprops[index].prop = prop;
				g_Vars.currentplayer->cmpfollowprops[index].x1 = sp84 - 2;
				g_Vars.currentplayer->cmpfollowprops[index].x2 = sp76 + 2;
				g_Vars.currentplayer->cmpfollowprops[index].y1 = sp88 - 2;
				g_Vars.currentplayer->cmpfollowprops[index].y2 = sp80 + 2;
				g_Vars.currentplayer->targetset[index] = 0;
				activeslots[index] = true;
				distances[index] = sqdist;
			}
		}
	}

	if (prop->child) {
		lvFindThreatsForProp(prop->child, true, playerpos, activeslots, distances);
	}

	if (inchild && prop->next) {
		lvFindThreatsForProp(prop->next, inchild, playerpos, activeslots, distances);
	}
}

void func0f168f24(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *distances)
{
	s32 i;
	f32 sp128;
	f32 sp124;
	f32 sp120;
	f32 sp116;
	struct model *model;

	for (i = 0; i != 4; i++) {
		if (g_Vars.currentplayer->cmpfollowprops[i].prop == prop
				&& (prop->flags & PROPFLAG_ONSCREEN)) {
			model = NULL;

			if (prop->type == PROPTYPE_OBJ
					|| prop->type == PROPTYPE_WEAPON
					|| prop->type == PROPTYPE_DOOR) {
				model = g_Vars.currentplayer->cmpfollowprops[i].prop->obj->model;
			} else {
				if (prop->type == PROPTYPE_CHR
						|| (prop->type == PROPTYPE_PLAYER
							&& propGetPlayerNum(prop) != g_Vars.currentplayernum)) {
					model = g_Vars.currentplayer->cmpfollowprops[i].prop->chr->model;
				}
			}

			if (model) {
				sp124 = -1;
				sp128 = -1;
				sp116 = -2;
				sp120 = -2;

				if (modelSetRedBox(model, &sp116, &sp124, &sp120, &sp128)) {
					activeslots[i] = true;
					g_Vars.currentplayer->cmpfollowprops[i].x1 = sp124 - 2;
					g_Vars.currentplayer->cmpfollowprops[i].x2 = sp116 + 2;
					g_Vars.currentplayer->cmpfollowprops[i].y1 = sp128 - 2;
					g_Vars.currentplayer->cmpfollowprops[i].y2 = sp120 + 2;

					distances[i] =
						(prop->pos.f[0] - playerpos->f[0]) * (prop->pos.f[0] - playerpos->f[0]) +
						(prop->pos.f[1] - playerpos->f[1]) * (prop->pos.f[1] - playerpos->f[1]) +
						(prop->pos.f[2] - playerpos->f[2]) * (prop->pos.f[2] - playerpos->f[2]);
				}
			}
		}
	}

	if (prop->child) {
		func0f168f24(prop->child, true, playerpos, activeslots, distances);
	}

	if (inchild && prop->next) {
		func0f168f24(prop->next, inchild, playerpos, activeslots, distances);
	}
}

void lvFindThreats(void)
{
	s32 i;
	struct prop *prop;
	f32 distances[] = {0, 0, 0, 0};
	s32 activeslots[] = {false, false, false, false};
	struct prop **propptr = g_Vars.endonscreenprops - 1;
	struct coord campos;

	campos.x = g_Vars.currentplayer->cam_pos.x;
	campos.y = g_Vars.currentplayer->cam_pos.y;
	campos.z = g_Vars.currentplayer->cam_pos.z;

	while (propptr >= g_Vars.onscreenprops) {
		prop = *propptr;

		if (prop) {
			func0f168f24(prop, false, &campos, activeslots, distances);
		}

		propptr--;
	}

	for (i = 0; i != ARRAYCOUNT(activeslots); i++) {
		if (!activeslots[i]) {
			g_Vars.currentplayer->cmpfollowprops[i].prop = NULL;
			g_Vars.currentplayer->cmpfollowprops[i].x1 = -1;
			g_Vars.currentplayer->cmpfollowprops[i].x2 = -2;
		}
	}

	propptr = g_Vars.endonscreenprops - 1;

	while (propptr >= g_Vars.onscreenprops) {
		prop = *propptr;

		if (prop) {
			lvFindThreatsForProp(prop, false, &campos, activeslots, distances);
		}

		propptr--;
	}
}

#if VERSION >= VERSION_PAL_FINAL
struct coord coreRender_spd4 = {0, 0, 0};
s8 coreRender_spd0[] = {30, 0, 0, 0};

GLOBAL_ASM(
glabel lvRender
.late_rodata
glabel var7f1b8e64pf
.word 0x3f866666
glabel var7f1b8e68pf
.word 0x3cbd0bd1
glabel var7f1b8e6cpf
.word 0x3f8ccccd
glabel var7f1b8e70pf
.word 0x3bfc0fc1
glabel var7f1b8e74pf
.word 0x3cbd0bd1
glabel var7f1b8e78pf
.word 0x3f8ccccd
glabel var7f1b8e7cpf
.word 0x3bfc0fc1
.text
/*  f16a2f8:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f16a2fc:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f16a300:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f16a304:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16a308:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f16a30c:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f16a310:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f16a314:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f16a318:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f16a31c:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f16a320:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f16a324:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f16a328:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f16a32c:	35ce0006 */ 	ori	$t6,$t6,0x6
/*  f16a330:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f16a334:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f16a338:	0fc35807 */ 	jal	func0f0d5a7c
/*  f16a33c:	24930008 */ 	addiu	$s3,$a0,0x8
/*  f16a340:	3c12800a */ 	lui	$s2,0x800a
/*  f16a344:	2652a510 */ 	addiu	$s2,$s2,-23280
/*  f16a348:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f16a34c:	2401005a */ 	li	$at,0x5a
/*  f16a350:	10410006 */ 	beq	$v0,$at,.PF0f16a36c
/*  f16a354:	2401004e */ 	li	$at,0x4e
/*  f16a358:	5441005f */ 	bnel	$v0,$at,.PF0f16a4d8
/*  f16a35c:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f16a360:	0fc06b27 */ 	jal	titleIsKeepingMode
/*  f16a364:	00000000 */ 	nop
/*  f16a368:	1040005a */ 	beqz	$v0,.PF0f16a4d4
.PF0f16a36c:
/*  f16a36c:	02601025 */ 	move	$v0,$s3
/*  f16a370:	3c188006 */ 	lui	$t8,0x8006
/*  f16a374:	27181070 */ 	addiu	$t8,$t8,0x1070
/*  f16a378:	3c0f0600 */ 	lui	$t7,0x600
/*  f16a37c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f16a380:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f16a384:	0fc47e4a */ 	jal	debug0f11ee28
/*  f16a388:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a38c:	10400008 */ 	beqz	$v0,.PF0f16a3b0
/*  f16a390:	02601025 */ 	move	$v0,$s3
/*  f16a394:	3c0a8006 */ 	lui	$t2,0x8006
/*  f16a398:	254a1030 */ 	addiu	$t2,$t2,0x1030
/*  f16a39c:	3c190600 */ 	lui	$t9,0x600
/*  f16a3a0:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f16a3a4:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f16a3a8:	10000008 */ 	b	.PF0f16a3cc
/*  f16a3ac:	26730008 */ 	addiu	$s3,$s3,0x8
.PF0f16a3b0:
/*  f16a3b0:	02601025 */ 	move	$v0,$s3
/*  f16a3b4:	3c0c8006 */ 	lui	$t4,0x8006
/*  f16a3b8:	258c1050 */ 	addiu	$t4,$t4,0x1050
/*  f16a3bc:	3c0b0600 */ 	lui	$t3,0x600
/*  f16a3c0:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f16a3c4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f16a3c8:	26730008 */ 	addiu	$s3,$s3,0x8
.PF0f16a3cc:
/*  f16a3cc:	0c002bf1 */ 	jal	func0000b280
/*  f16a3d0:	02602025 */ 	move	$a0,$s3
/*  f16a3d4:	0c002bc5 */ 	jal	func0000b1d0
/*  f16a3d8:	00402025 */ 	move	$a0,$v0
/*  f16a3dc:	00408825 */ 	move	$s1,$v0
/*  f16a3e0:	0c002e91 */ 	jal	viGetViewLeft
/*  f16a3e4:	24530008 */ 	addiu	$s3,$v0,0x8
/*  f16a3e8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16a3ec:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f16a3f0:	0c002e95 */ 	jal	viGetViewTop
/*  f16a3f4:	01a08025 */ 	move	$s0,$t5
/*  f16a3f8:	44822000 */ 	mtc1	$v0,$f4
/*  f16a3fc:	44908000 */ 	mtc1	$s0,$f16
/*  f16a400:	3c014080 */ 	lui	$at,0x4080
/*  f16a404:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16a408:	4481a000 */ 	mtc1	$at,$f20
/*  f16a40c:	3c01ed00 */ 	lui	$at,0xed00
/*  f16a410:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f16a414:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f16a418:	00000000 */ 	nop
/*  f16a41c:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f16a420:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f16a424:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f16a428:	440f5000 */ 	mfc1	$t7,$f10
/*  f16a42c:	440b3000 */ 	mfc1	$t3,$f6
/*  f16a430:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f16a434:	0301c825 */ 	or	$t9,$t8,$at
/*  f16a438:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f16a43c:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f16a440:	032d7025 */ 	or	$t6,$t9,$t5
/*  f16a444:	0c002e73 */ 	jal	viGetViewWidth
/*  f16a448:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f16a44c:	0c002e91 */ 	jal	viGetViewLeft
/*  f16a450:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f16a454:	0c002e95 */ 	jal	viGetViewTop
/*  f16a458:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a45c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16a460:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f16a464:	0c002e77 */ 	jal	viGetViewHeight
/*  f16a468:	01e08025 */ 	move	$s0,$t7
/*  f16a46c:	87b80090 */ 	lh	$t8,0x90($sp)
/*  f16a470:	87aa008e */ 	lh	$t2,0x8e($sp)
/*  f16a474:	00507821 */ 	addu	$t7,$v0,$s0
/*  f16a478:	448f2000 */ 	mtc1	$t7,$f4
/*  f16a47c:	030a5821 */ 	addu	$t3,$t8,$t2
/*  f16a480:	448b4000 */ 	mtc1	$t3,$f8
/*  f16a484:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16a488:	02602025 */ 	move	$a0,$s3
/*  f16a48c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f16a490:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f16a494:	00000000 */ 	nop
/*  f16a498:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f16a49c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f16a4a0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f16a4a4:	44199000 */ 	mfc1	$t9,$f18
/*  f16a4a8:	440a5000 */ 	mfc1	$t2,$f10
/*  f16a4ac:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f16a4b0:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f16a4b4:	314b0fff */ 	andi	$t3,$t2,0xfff
/*  f16a4b8:	016e6025 */ 	or	$t4,$t3,$t6
/*  f16a4bc:	0fc06bf9 */ 	jal	titleRender
/*  f16a4c0:	ae2c0004 */ 	sw	$t4,0x4($s1)
/*  f16a4c4:	0fc5a557 */ 	jal	lvRenderFade
/*  f16a4c8:	00402025 */ 	move	$a0,$v0
/*  f16a4cc:	100005e8 */ 	b	.PF0f16bc70
/*  f16a4d0:	00409825 */ 	move	$s3,$v0
.PF0f16a4d4:
/*  f16a4d4:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
.PF0f16a4d8:
/*  f16a4d8:	2401005b */ 	li	$at,0x5b
/*  f16a4dc:	24070002 */ 	li	$a3,0x2
/*  f16a4e0:	14410040 */ 	bne	$v0,$at,.PF0f16a5e4
/*  f16a4e4:	3408fffe */ 	li	$t0,0xfffe
/*  f16a4e8:	02601025 */ 	move	$v0,$s3
/*  f16a4ec:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a4f0:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f16a4f4:	37390404 */ 	ori	$t9,$t9,0x404
/*  f16a4f8:	02601825 */ 	move	$v1,$s3
/*  f16a4fc:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a500:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f16a504:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f16a508:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f16a50c:	35ad0c04 */ 	ori	$t5,$t5,0xc04
/*  f16a510:	02602025 */ 	move	$a0,$s3
/*  f16a514:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f16a518:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16a51c:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f16a520:	35ef1404 */ 	ori	$t7,$t7,0x1404
/*  f16a524:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a528:	02602825 */ 	move	$a1,$s3
/*  f16a52c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f16a530:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f16a534:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a538:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f16a53c:	37181c04 */ 	ori	$t8,$t8,0x1c04
/*  f16a540:	02603025 */ 	move	$a2,$s3
/*  f16a544:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f16a548:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f16a54c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a550:	3c0a8006 */ 	lui	$t2,0x8006
/*  f16a554:	3c090600 */ 	lui	$t1,0x600
/*  f16a558:	254a1070 */ 	addiu	$t2,$t2,0x1070
/*  f16a55c:	02601025 */ 	move	$v0,$s3
/*  f16a560:	3c0b8006 */ 	lui	$t3,0x8006
/*  f16a564:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f16a568:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f16a56c:	256b1050 */ 	addiu	$t3,$t3,0x1050
/*  f16a570:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f16a574:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f16a578:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a57c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16a580:	00002025 */ 	move	$a0,$zero
/*  f16a584:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a588:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16a58c:	0c002e7b */ 	jal	viSetViewPosition
/*  f16a590:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16a594:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a598:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16a59c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16a5a0:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16a5a4:	0c002ec7 */ 	jal	viSetFovAspectAndSize
/*  f16a5a8:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16a5ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a5b0:	44816000 */ 	mtc1	$at,$f12
/*  f16a5b4:	0c005936 */ 	jal	func00016748
/*  f16a5b8:	00000000 */ 	nop
/*  f16a5bc:	0c002bc5 */ 	jal	func0000b1d0
/*  f16a5c0:	02602025 */ 	move	$a0,$s3
/*  f16a5c4:	0c002c1d */ 	jal	func0000b330
/*  f16a5c8:	00402025 */ 	move	$a0,$v0
/*  f16a5cc:	0fc576bd */ 	jal	currentPlayerScissorToViewport
/*  f16a5d0:	00402025 */ 	move	$a0,$v0
/*  f16a5d4:	0fc3f0f0 */ 	jal	func0f0fbc30
/*  f16a5d8:	00402025 */ 	move	$a0,$v0
/*  f16a5dc:	100005a4 */ 	b	.PF0f16bc70
/*  f16a5e0:	00409825 */ 	move	$s3,$v0
.PF0f16a5e4:
/*  f16a5e4:	2401005d */ 	li	$at,0x5d
/*  f16a5e8:	14410063 */ 	bne	$v0,$at,.PF0f16a778
/*  f16a5ec:	24070002 */ 	li	$a3,0x2
/*  f16a5f0:	02601025 */ 	move	$v0,$s3
/*  f16a5f4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a5f8:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16a5fc:	35ce0404 */ 	ori	$t6,$t6,0x404
/*  f16a600:	02601825 */ 	move	$v1,$s3
/*  f16a604:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a608:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f16a60c:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f16a610:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f16a614:	358c0c04 */ 	ori	$t4,$t4,0xc04
/*  f16a618:	02602025 */ 	move	$a0,$s3
/*  f16a61c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f16a620:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16a624:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f16a628:	3408fffe */ 	li	$t0,0xfffe
/*  f16a62c:	37391404 */ 	ori	$t9,$t9,0x1404
/*  f16a630:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a634:	02602825 */ 	move	$a1,$s3
/*  f16a638:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f16a63c:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f16a640:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a644:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f16a648:	35ad1c04 */ 	ori	$t5,$t5,0x1c04
/*  f16a64c:	02603025 */ 	move	$a2,$s3
/*  f16a650:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f16a654:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f16a658:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a65c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f16a660:	3c090600 */ 	lui	$t1,0x600
/*  f16a664:	25ef1070 */ 	addiu	$t7,$t7,0x1070
/*  f16a668:	02601025 */ 	move	$v0,$s3
/*  f16a66c:	3c188006 */ 	lui	$t8,0x8006
/*  f16a670:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f16a674:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f16a678:	27181050 */ 	addiu	$t8,$t8,0x1050
/*  f16a67c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f16a680:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f16a684:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a688:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16a68c:	00002025 */ 	move	$a0,$zero
/*  f16a690:	0c0029fd */ 	jal	func0000aab0
/*  f16a694:	24040001 */ 	li	$a0,0x1
/*  f16a698:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a69c:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16a6a0:	0c002e7b */ 	jal	viSetViewPosition
/*  f16a6a4:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16a6a8:	0fc2f272 */ 	jal	viGetFbWidth
/*  f16a6ac:	00000000 */ 	nop
/*  f16a6b0:	0fc2f27d */ 	jal	viGetFbHeight
/*  f16a6b4:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a6b8:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f16a6bc:	00055403 */ 	sra	$t2,$a1,0x10
/*  f16a6c0:	01402825 */ 	move	$a1,$t2
/*  f16a6c4:	0c002e4a */ 	jal	viSetXY
/*  f16a6c8:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f16a6cc:	0fc2f272 */ 	jal	viGetFbWidth
/*  f16a6d0:	00000000 */ 	nop
/*  f16a6d4:	0fc2f27d */ 	jal	viGetFbHeight
/*  f16a6d8:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a6dc:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f16a6e0:	00055c03 */ 	sra	$t3,$a1,0x10
/*  f16a6e4:	01602825 */ 	move	$a1,$t3
/*  f16a6e8:	0c002e39 */ 	jal	viSetBuf
/*  f16a6ec:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f16a6f0:	0fc2f272 */ 	jal	viGetFbWidth
/*  f16a6f4:	00000000 */ 	nop
/*  f16a6f8:	0fc2f27d */ 	jal	viGetFbHeight
/*  f16a6fc:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a700:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f16a704:	00057403 */ 	sra	$t6,$a1,0x10
/*  f16a708:	01c02825 */ 	move	$a1,$t6
/*  f16a70c:	0c002e5b */ 	jal	viSetViewSize
/*  f16a710:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f16a714:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a718:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16a71c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16a720:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16a724:	0c002ec7 */ 	jal	viSetFovAspectAndSize
/*  f16a728:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16a72c:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a730:	44816000 */ 	mtc1	$at,$f12
/*  f16a734:	0c005936 */ 	jal	func00016748
/*  f16a738:	00000000 */ 	nop
/*  f16a73c:	0c002bc5 */ 	jal	func0000b1d0
/*  f16a740:	02602025 */ 	move	$a0,$s3
/*  f16a744:	0fc576bd */ 	jal	currentPlayerScissorToViewport
/*  f16a748:	00402025 */ 	move	$a0,$v0
/*  f16a74c:	0fc3f0f0 */ 	jal	func0f0fbc30
/*  f16a750:	00402025 */ 	move	$a0,$v0
/*  f16a754:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16a758:	00409825 */ 	move	$s3,$v0
/*  f16a75c:	8d991a24 */ 	lw	$t9,0x1a24($t4)
/*  f16a760:	53200544 */ 	beqzl	$t9,.PF0f16bc74
/*  f16a764:	824b04d3 */ 	lb	$t3,0x4d3($s2)
/*  f16a768:	0fc2ecb3 */ 	jal	currentPlayerTickPauseMenu
/*  f16a76c:	00000000 */ 	nop
/*  f16a770:	10000540 */ 	b	.PF0f16bc74
/*  f16a774:	824b04d3 */ 	lb	$t3,0x4d3($s2)
.PF0f16a778:
/*  f16a778:	2401005c */ 	li	$at,0x5c
/*  f16a77c:	14410041 */ 	bne	$v0,$at,.PF0f16a884
/*  f16a780:	24070002 */ 	li	$a3,0x2
/*  f16a784:	02601025 */ 	move	$v0,$s3
/*  f16a788:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a78c:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f16a790:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f16a794:	02601825 */ 	move	$v1,$s3
/*  f16a798:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a79c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f16a7a0:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f16a7a4:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f16a7a8:	35ef0c04 */ 	ori	$t7,$t7,0xc04
/*  f16a7ac:	02602025 */ 	move	$a0,$s3
/*  f16a7b0:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f16a7b4:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16a7b8:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f16a7bc:	3408fffe */ 	li	$t0,0xfffe
/*  f16a7c0:	37181404 */ 	ori	$t8,$t8,0x1404
/*  f16a7c4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a7c8:	02602825 */ 	move	$a1,$s3
/*  f16a7cc:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f16a7d0:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f16a7d4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a7d8:	3c0abc00 */ 	lui	$t2,0xbc00
/*  f16a7dc:	354a1c04 */ 	ori	$t2,$t2,0x1c04
/*  f16a7e0:	02603025 */ 	move	$a2,$s3
/*  f16a7e4:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f16a7e8:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f16a7ec:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a7f0:	3c0b8006 */ 	lui	$t3,0x8006
/*  f16a7f4:	3c090600 */ 	lui	$t1,0x600
/*  f16a7f8:	256b1070 */ 	addiu	$t3,$t3,0x1070
/*  f16a7fc:	02601025 */ 	move	$v0,$s3
/*  f16a800:	3c0e8006 */ 	lui	$t6,0x8006
/*  f16a804:	accb0004 */ 	sw	$t3,0x4($a2)
/*  f16a808:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f16a80c:	25ce1050 */ 	addiu	$t6,$t6,0x1050
/*  f16a810:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f16a814:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f16a818:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a81c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16a820:	00002025 */ 	move	$a0,$zero
/*  f16a824:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a828:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16a82c:	0c002e7b */ 	jal	viSetViewPosition
/*  f16a830:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16a834:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a838:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16a83c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16a840:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16a844:	0c002ec7 */ 	jal	viSetFovAspectAndSize
/*  f16a848:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16a84c:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a850:	44816000 */ 	mtc1	$at,$f12
/*  f16a854:	0c005936 */ 	jal	func00016748
/*  f16a858:	00000000 */ 	nop
/*  f16a85c:	0c002bbb */ 	jal	func0000b1a8
/*  f16a860:	02602025 */ 	move	$a0,$s3
/*  f16a864:	0c002bc5 */ 	jal	func0000b1d0
/*  f16a868:	00402025 */ 	move	$a0,$v0
/*  f16a86c:	0c002c1d */ 	jal	func0000b330
/*  f16a870:	00402025 */ 	move	$a0,$v0
/*  f16a874:	0fc4eef2 */ 	jal	creditsRender
/*  f16a878:	00402025 */ 	move	$a0,$v0
/*  f16a87c:	100004fc */ 	b	.PF0f16bc70
/*  f16a880:	00409825 */ 	move	$s3,$v0
.PF0f16a884:
/*  f16a884:	8e500298 */ 	lw	$s0,0x298($s2)
/*  f16a888:	06010006 */ 	bgez	$s0,.PF0f16a8a4
/*  f16a88c:	00000000 */ 	nop
/*  f16a890:	8e50029c */ 	lw	$s0,0x29c($s2)
/*  f16a894:	2a190000 */ 	slti	$t9,$s0,0x0
/*  f16a898:	3b300001 */ 	xori	$s0,$t9,0x1
/*  f16a89c:	12000004 */ 	beqz	$s0,.PF0f16a8b0
/*  f16a8a0:	00000000 */ 	nop
.PF0f16a8a4:
/*  f16a8a4:	0fc2f28f */ 	jal	func0f0bc4c0
/*  f16a8a8:	00000000 */ 	nop
/*  f16a8ac:	0002802b */ 	sltu	$s0,$zero,$v0
.PF0f16a8b0:
/*  f16a8b0:	12000004 */ 	beqz	$s0,.PF0f16a8c4
/*  f16a8b4:	afb00104 */ 	sw	$s0,0x104($sp)
/*  f16a8b8:	240d0001 */ 	li	$t5,0x1
/*  f16a8bc:	1000001c */ 	b	.PF0f16a930
/*  f16a8c0:	afad010c */ 	sw	$t5,0x10c($sp)
.PF0f16a8c4:
/*  f16a8c4:	8e4f006c */ 	lw	$t7,0x6c($s2)
/*  f16a8c8:	00002025 */ 	move	$a0,$zero
/*  f16a8cc:	00001825 */ 	move	$v1,$zero
/*  f16a8d0:	11e00003 */ 	beqz	$t7,.PF0f16a8e0
/*  f16a8d4:	00001025 */ 	move	$v0,$zero
/*  f16a8d8:	10000001 */ 	b	.PF0f16a8e0
/*  f16a8dc:	24040001 */ 	li	$a0,0x1
.PF0f16a8e0:
/*  f16a8e0:	8e580068 */ 	lw	$t8,0x68($s2)
/*  f16a8e4:	00008025 */ 	move	$s0,$zero
/*  f16a8e8:	13000003 */ 	beqz	$t8,.PF0f16a8f8
/*  f16a8ec:	00000000 */ 	nop
/*  f16a8f0:	10000001 */ 	b	.PF0f16a8f8
/*  f16a8f4:	24030001 */ 	li	$v1,0x1
.PF0f16a8f8:
/*  f16a8f8:	8e4a0064 */ 	lw	$t2,0x64($s2)
/*  f16a8fc:	11400003 */ 	beqz	$t2,.PF0f16a90c
/*  f16a900:	00000000 */ 	nop
/*  f16a904:	10000001 */ 	b	.PF0f16a90c
/*  f16a908:	24020001 */ 	li	$v0,0x1
.PF0f16a90c:
/*  f16a90c:	8e4b0070 */ 	lw	$t3,0x70($s2)
/*  f16a910:	11600003 */ 	beqz	$t3,.PF0f16a920
/*  f16a914:	00000000 */ 	nop
/*  f16a918:	10000001 */ 	b	.PF0f16a920
/*  f16a91c:	24100001 */ 	li	$s0,0x1
.PF0f16a920:
/*  f16a920:	02027021 */ 	addu	$t6,$s0,$v0
/*  f16a924:	01c36021 */ 	addu	$t4,$t6,$v1
/*  f16a928:	0184c821 */ 	addu	$t9,$t4,$a0
/*  f16a92c:	afb9010c */ 	sw	$t9,0x10c($sp)
.PF0f16a930:
/*  f16a930:	02601025 */ 	move	$v0,$s3
/*  f16a934:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a938:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f16a93c:	24070002 */ 	li	$a3,0x2
/*  f16a940:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f16a944:	02601825 */ 	move	$v1,$s3
/*  f16a948:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a94c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f16a950:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f16a954:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f16a958:	35ef0c04 */ 	ori	$t7,$t7,0xc04
/*  f16a95c:	02602025 */ 	move	$a0,$s3
/*  f16a960:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f16a964:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16a968:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f16a96c:	3408fffe */ 	li	$t0,0xfffe
/*  f16a970:	37181404 */ 	ori	$t8,$t8,0x1404
/*  f16a974:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a978:	02602825 */ 	move	$a1,$s3
/*  f16a97c:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f16a980:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f16a984:	3c0abc00 */ 	lui	$t2,0xbc00
/*  f16a988:	354a1c04 */ 	ori	$t2,$t2,0x1c04
/*  f16a98c:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f16a990:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f16a994:	8fab010c */ 	lw	$t3,0x10c($sp)
/*  f16a998:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a99c:	00008025 */ 	move	$s0,$zero
/*  f16a9a0:	196004b3 */ 	blez	$t3,.PF0f16bc70
/*  f16a9a4:	3c0e8006 */ 	lui	$t6,0x8006
/*  f16a9a8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f16a9ac:	25ce1070 */ 	addiu	$t6,$t6,0x1070
/*  f16a9b0:	4481a000 */ 	mtc1	$at,$f20
/*  f16a9b4:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f16a9b8:	241e0001 */ 	li	$s8,0x1
/*  f16a9bc:	2417ffff */ 	li	$s7,-1
/*  f16a9c0:	2416fffe */ 	li	$s6,-2
/*  f16a9c4:	24150004 */ 	li	$s5,0x4
/*  f16a9c8:	8fac0104 */ 	lw	$t4,0x104($sp)
.PF0f16a9cc:
/*  f16a9cc:	0000a025 */ 	move	$s4,$zero
/*  f16a9d0:	afb30108 */ 	sw	$s3,0x108($sp)
/*  f16a9d4:	11800007 */ 	beqz	$t4,.PF0f16a9f4
/*  f16a9d8:	00002025 */ 	move	$a0,$zero
/*  f16a9dc:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16a9e0:	24110001 */ 	li	$s1,0x1
/*  f16a9e4:	26190001 */ 	addiu	$t9,$s0,0x1
/*  f16a9e8:	ae400290 */ 	sw	$zero,0x290($s2)
/*  f16a9ec:	1000000a */ 	b	.PF0f16aa18
/*  f16a9f0:	afb90064 */ 	sw	$t9,0x64($sp)
.PF0f16a9f4:
/*  f16a9f4:	0fc4a666 */ 	jal	getPlayerByOrderNum
/*  f16a9f8:	02002025 */ 	move	$a0,$s0
/*  f16a9fc:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16aa00:	00402025 */ 	move	$a0,$v0
/*  f16aa04:	8fad010c */ 	lw	$t5,0x10c($sp)
/*  f16aa08:	26020001 */ 	addiu	$v0,$s0,0x1
/*  f16aa0c:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f16aa10:	01a28826 */ 	xor	$s1,$t5,$v0
/*  f16aa14:	2e310001 */ 	sltiu	$s1,$s1,0x1
.PF0f16aa18:
/*  f16aa18:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f16aa1c:	24010006 */ 	li	$at,0x6
/*  f16aa20:	11e10029 */ 	beq	$t7,$at,.PF0f16aac8
/*  f16aa24:	00000000 */ 	nop
/*  f16aa28:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16aa2c:	8e1800bc */ 	lw	$t8,0xbc($s0)
/*  f16aa30:	8f020004 */ 	lw	$v0,0x4($t8)
/*  f16aa34:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f16aa38:	18800023 */ 	blez	$a0,.PF0f16aac8
/*  f16aa3c:	00000000 */ 	nop
/*  f16aa40:	920a1922 */ 	lbu	$t2,0x1922($s0)
/*  f16aa44:	15400020 */ 	bnez	$t2,.PF0f16aac8
/*  f16aa48:	00000000 */ 	nop
/*  f16aa4c:	8e0b1c08 */ 	lw	$t3,0x1c08($s0)
/*  f16aa50:	24011046 */ 	li	$at,0x1046
/*  f16aa54:	1560001c */ 	bnez	$t3,.PF0f16aac8
/*  f16aa58:	00000000 */ 	nop
/*  f16aa5c:	0004a180 */ 	sll	$s4,$a0,0x6
/*  f16aa60:	0284a021 */ 	addu	$s4,$s4,$a0
/*  f16aa64:	0014a040 */ 	sll	$s4,$s4,0x1
/*  f16aa68:	0281001a */ 	div	$zero,$s4,$at
/*  f16aa6c:	00007012 */ 	mflo	$t6
/*  f16aa70:	25d40064 */ 	addiu	$s4,$t6,0x64
/*  f16aa74:	2e8100e7 */ 	sltiu	$at,$s4,0xe7
/*  f16aa78:	14200002 */ 	bnez	$at,.PF0f16aa84
/*  f16aa7c:	240c1046 */ 	li	$t4,0x1046
/*  f16aa80:	241400e6 */ 	li	$s4,0xe6
.PF0f16aa84:
/*  f16aa84:	28811047 */ 	slti	$at,$a0,0x1047
/*  f16aa88:	54200004 */ 	bnezl	$at,.PF0f16aa9c
/*  f16aa8c:	904d02ff */ 	lbu	$t5,0x2ff($v0)
/*  f16aa90:	a44c02d8 */ 	sh	$t4,0x2d8($v0)
/*  f16aa94:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f16aa98:	904d02ff */ 	lbu	$t5,0x2ff($v0)
.PF0f16aa9c:
/*  f16aa9c:	8e590038 */ 	lw	$t9,0x38($s2)
/*  f16aaa0:	25af0001 */ 	addiu	$t7,$t5,0x1
/*  f16aaa4:	032f0019 */ 	multu	$t9,$t7
/*  f16aaa8:	0000c012 */ 	mflo	$t8
/*  f16aaac:	00985023 */ 	subu	$t2,$a0,$t8
/*  f16aab0:	a44a02d8 */ 	sh	$t2,0x2d8($v0)
/*  f16aab4:	844b02d8 */ 	lh	$t3,0x2d8($v0)
/*  f16aab8:	1d600003 */ 	bgtz	$t3,.PF0f16aac8
/*  f16aabc:	00000000 */ 	nop
/*  f16aac0:	a44002d8 */ 	sh	$zero,0x2d8($v0)
/*  f16aac4:	a04002ff */ 	sb	$zero,0x2ff($v0)
.PF0f16aac8:
/*  f16aac8:	0fc525fd */ 	jal	bviewSetBlur
/*  f16aacc:	02802025 */ 	move	$a0,$s4
/*  f16aad0:	02601025 */ 	move	$v0,$s3
/*  f16aad4:	3c0e0600 */ 	lui	$t6,0x600
/*  f16aad8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f16aadc:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f16aae0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16aae4:	0fc47e4a */ 	jal	debug0f11ee28
/*  f16aae8:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f16aaec:	10400009 */ 	beqz	$v0,.PF0f16ab14
/*  f16aaf0:	3c0f0600 */ 	lui	$t7,0x600
/*  f16aaf4:	02601025 */ 	move	$v0,$s3
/*  f16aaf8:	3c198006 */ 	lui	$t9,0x8006
/*  f16aafc:	27391030 */ 	addiu	$t9,$t9,0x1030
/*  f16ab00:	3c0d0600 */ 	lui	$t5,0x600
/*  f16ab04:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f16ab08:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f16ab0c:	10000007 */ 	b	.PF0f16ab2c
/*  f16ab10:	26730008 */ 	addiu	$s3,$s3,0x8
.PF0f16ab14:
/*  f16ab14:	02601025 */ 	move	$v0,$s3
/*  f16ab18:	3c188006 */ 	lui	$t8,0x8006
/*  f16ab1c:	27181050 */ 	addiu	$t8,$t8,0x1050
/*  f16ab20:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f16ab24:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f16ab28:	26730008 */ 	addiu	$s3,$s3,0x8
.PF0f16ab2c:
/*  f16ab2c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ab30:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16ab34:	0c002e7b */ 	jal	viSetViewPosition
/*  f16ab38:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16ab3c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ab40:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16ab44:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16ab48:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16ab4c:	0c002ec7 */ 	jal	viSetFovAspectAndSize
/*  f16ab50:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16ab54:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f16ab58:	0c005936 */ 	jal	func00016748
/*  f16ab5c:	c54c0074 */ 	lwc1	$f12,0x74($t2)
/*  f16ab60:	0fc599de */ 	jal	func0f1657f8
/*  f16ab64:	00000000 */ 	nop
/*  f16ab68:	0fc5dcb2 */ 	jal	func0f176298
/*  f16ab6c:	00000000 */ 	nop
/*  f16ab70:	0c002bf1 */ 	jal	func0000b280
/*  f16ab74:	02602025 */ 	move	$a0,$s3
/*  f16ab78:	0c002bc5 */ 	jal	func0000b1d0
/*  f16ab7c:	00402025 */ 	move	$a0,$v0
/*  f16ab80:	0fc576bd */ 	jal	currentPlayerScissorToViewport
/*  f16ab84:	00402025 */ 	move	$a0,$v0
/*  f16ab88:	0fc4f420 */ 	jal	func0f13c510
/*  f16ab8c:	00409825 */ 	move	$s3,$v0
/*  f16ab90:	8e4b04b4 */ 	lw	$t3,0x4b4($s2)
/*  f16ab94:	24010026 */ 	li	$at,0x26
/*  f16ab98:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16ab9c:	5561000a */ 	bnel	$t3,$at,.PF0f16abc8
/*  f16aba0:	8e4d000c */ 	lw	$t5,0xc($s2)
/*  f16aba4:	8dce77b0 */ 	lw	$t6,0x77b0($t6)
/*  f16aba8:	3c0c800a */ 	lui	$t4,0x800a
/*  f16abac:	5dc0001a */ 	bgtzl	$t6,.PF0f16ac18
/*  f16abb0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16abb4:	8d8c1f64 */ 	lw	$t4,0x1f64($t4)
/*  f16abb8:	24010003 */ 	li	$at,0x3
/*  f16abbc:	51810016 */ 	beql	$t4,$at,.PF0f16ac18
/*  f16abc0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16abc4:	8e4d000c */ 	lw	$t5,0xc($s2)
.PF0f16abc8:
/*  f16abc8:	29a10006 */ 	slti	$at,$t5,0x6
/*  f16abcc:	50200012 */ 	beqzl	$at,.PF0f16ac18
/*  f16abd0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16abd4:	8e590318 */ 	lw	$t9,0x318($s2)
/*  f16abd8:	5720000f */ 	bnezl	$t9,.PF0f16ac18
/*  f16abdc:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16abe0:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f16abe4:	24010006 */ 	li	$at,0x6
/*  f16abe8:	3c028008 */ 	lui	$v0,0x8008
/*  f16abec:	51e1000a */ 	beql	$t7,$at,.PF0f16ac18
/*  f16abf0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16abf4:	8c424590 */ 	lw	$v0,0x4590($v0)
/*  f16abf8:	28410006 */ 	slti	$at,$v0,0x6
/*  f16abfc:	10200002 */ 	beqz	$at,.PF0f16ac08
/*  f16ac00:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f16ac04:	ae5e0320 */ 	sw	$s8,0x320($s2)
.PF0f16ac08:
/*  f16ac08:	3c018008 */ 	lui	$at,0x8008
/*  f16ac0c:	1000001d */ 	b	.PF0f16ac84
/*  f16ac10:	ac384590 */ 	sw	$t8,0x4590($at)
/*  f16ac14:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16ac18:
/*  f16ac18:	3c0c8007 */ 	lui	$t4,0x8007
/*  f16ac1c:	8e0a1580 */ 	lw	$t2,0x1580($s0)
/*  f16ac20:	000a7780 */ 	sll	$t6,$t2,0x1e
/*  f16ac24:	05c30018 */ 	bgezl	$t6,.PF0f16ac88
/*  f16ac28:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16ac2c:	8d8c6230 */ 	lw	$t4,0x6230($t4)
/*  f16ac30:	24010002 */ 	li	$at,0x2
/*  f16ac34:	55810014 */ 	bnel	$t4,$at,.PF0f16ac88
/*  f16ac38:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16ac3c:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f16ac40:	24010002 */ 	li	$at,0x2
/*  f16ac44:	53c20010 */ 	beql	$s8,$v0,.PF0f16ac88
/*  f16ac48:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16ac4c:	1041000d */ 	beq	$v0,$at,.PF0f16ac84
/*  f16ac50:	3c0d800a */ 	lui	$t5,0x800a
/*  f16ac54:	8dade560 */ 	lw	$t5,-0x1aa0($t5)
/*  f16ac58:	55a0000b */ 	bnezl	$t5,.PF0f16ac88
/*  f16ac5c:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16ac60:	0fc27b66 */ 	jal	bgun0f09eae4
/*  f16ac64:	00000000 */ 	nop
/*  f16ac68:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ac6c:	00027840 */ 	sll	$t7,$v0,0x1
/*  f16ac70:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f16ac74:	920a1583 */ 	lbu	$t2,0x1583($s0)
/*  f16ac78:	314bfffd */ 	andi	$t3,$t2,0xfffd
/*  f16ac7c:	030b7025 */ 	or	$t6,$t8,$t3
/*  f16ac80:	a20e1583 */ 	sb	$t6,0x1583($s0)
.PF0f16ac84:
/*  f16ac84:	8e4c0320 */ 	lw	$t4,0x320($s2)
.PF0f16ac88:
/*  f16ac88:	02602025 */ 	move	$a0,$s3
/*  f16ac8c:	2405ffff */ 	li	$a1,-1
/*  f16ac90:	11800008 */ 	beqz	$t4,.PF0f16acb4
/*  f16ac94:	3c0f800a */ 	lui	$t7,0x800a
/*  f16ac98:	0fc50bea */ 	jal	bviewRenderMotionBlur
/*  f16ac9c:	240600ff */ 	li	$a2,0xff
/*  f16aca0:	8e4d0320 */ 	lw	$t5,0x320($s2)
/*  f16aca4:	00409825 */ 	move	$s3,$v0
/*  f16aca8:	25b9ffff */ 	addiu	$t9,$t5,-1
/*  f16acac:	100003dc */ 	b	.PF0f16bc20
/*  f16acb0:	ae590320 */ 	sw	$t9,0x320($s2)
.PF0f16acb4:
/*  f16acb4:	8defe560 */ 	lw	$t7,-0x1aa0($t7)
/*  f16acb8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f16acbc:	11e00012 */ 	beqz	$t7,.PF0f16ad08
/*  f16acc0:	00000000 */ 	nop
/*  f16acc4:	0c002c1d */ 	jal	func0000b330
/*  f16acc8:	02602025 */ 	move	$a0,$s3
/*  f16accc:	0fc576bd */ 	jal	currentPlayerScissorToViewport
/*  f16acd0:	00402025 */ 	move	$a0,$v0
/*  f16acd4:	3c013f80 */ 	lui	$at,0x3f80
/*  f16acd8:	44816000 */ 	mtc1	$at,$f12
/*  f16acdc:	0c005936 */ 	jal	func00016748
/*  f16ace0:	00409825 */ 	move	$s3,$v0
/*  f16ace4:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16ace8:	8d581c50 */ 	lw	$t8,0x1c50($t2)
/*  f16acec:	00185fc2 */ 	srl	$t3,$t8,0x1f
/*  f16acf0:	116003cb */ 	beqz	$t3,.PF0f16bc20
/*  f16acf4:	00000000 */ 	nop
/*  f16acf8:	0fc3f0f0 */ 	jal	func0f0fbc30
/*  f16acfc:	02602025 */ 	move	$a0,$s3
/*  f16ad00:	100003c7 */ 	b	.PF0f16bc20
/*  f16ad04:	00409825 */ 	move	$s3,$v0
.PF0f16ad08:
/*  f16ad08:	8dce6230 */ 	lw	$t6,0x6230($t6)
/*  f16ad0c:	24010002 */ 	li	$at,0x2
/*  f16ad10:	15c10004 */ 	bne	$t6,$at,.PF0f16ad24
/*  f16ad14:	00000000 */ 	nop
/*  f16ad18:	0fc3014e */ 	jal	currentPlayerUpdateShootRot
/*  f16ad1c:	02602025 */ 	move	$a0,$s3
/*  f16ad20:	00409825 */ 	move	$s3,$v0
.PF0f16ad24:
/*  f16ad24:	0c002c1d */ 	jal	func0000b330
/*  f16ad28:	02602025 */ 	move	$a0,$s3
/*  f16ad2c:	0fc48121 */ 	jal	func0f11f984
/*  f16ad30:	00402025 */ 	move	$a0,$v0
/*  f16ad34:	0fc57660 */ 	jal	roomsTick
/*  f16ad38:	00409825 */ 	move	$s3,$v0
/*  f16ad3c:	0fc010c5 */ 	jal	func0f004314
/*  f16ad40:	00000000 */ 	nop
/*  f16ad44:	0fc18ca3 */ 	jal	propsTick
/*  f16ad48:	02202025 */ 	move	$a0,$s1
/*  f16ad4c:	0fc619c9 */ 	jal	scenarioCallback14
/*  f16ad50:	00002025 */ 	move	$a0,$zero
/*  f16ad54:	0fc18104 */ 	jal	propsSort
/*  f16ad58:	00000000 */ 	nop
/*  f16ad5c:	0fc193de */ 	jal	autoaimTick
/*  f16ad60:	00000000 */ 	nop
/*  f16ad64:	0fc18b63 */ 	jal	handsTickAttack
/*  f16ad68:	00000000 */ 	nop
/*  f16ad6c:	8e4c006c */ 	lw	$t4,0x6c($s2)
/*  f16ad70:	00002025 */ 	move	$a0,$zero
/*  f16ad74:	00001825 */ 	move	$v1,$zero
/*  f16ad78:	11800003 */ 	beqz	$t4,.PF0f16ad88
/*  f16ad7c:	00001025 */ 	move	$v0,$zero
/*  f16ad80:	10000001 */ 	b	.PF0f16ad88
/*  f16ad84:	03c02025 */ 	move	$a0,$s8
.PF0f16ad88:
/*  f16ad88:	8e4d0068 */ 	lw	$t5,0x68($s2)
/*  f16ad8c:	00008025 */ 	move	$s0,$zero
/*  f16ad90:	11a00003 */ 	beqz	$t5,.PF0f16ada0
/*  f16ad94:	00000000 */ 	nop
/*  f16ad98:	10000001 */ 	b	.PF0f16ada0
/*  f16ad9c:	03c01825 */ 	move	$v1,$s8
.PF0f16ada0:
/*  f16ada0:	8e590064 */ 	lw	$t9,0x64($s2)
/*  f16ada4:	13200003 */ 	beqz	$t9,.PF0f16adb4
/*  f16ada8:	00000000 */ 	nop
/*  f16adac:	10000001 */ 	b	.PF0f16adb4
/*  f16adb0:	03c01025 */ 	move	$v0,$s8
.PF0f16adb4:
/*  f16adb4:	8e4f0070 */ 	lw	$t7,0x70($s2)
/*  f16adb8:	11e00003 */ 	beqz	$t7,.PF0f16adc8
/*  f16adbc:	00000000 */ 	nop
/*  f16adc0:	10000001 */ 	b	.PF0f16adc8
/*  f16adc4:	03c08025 */ 	move	$s0,$s8
.PF0f16adc8:
/*  f16adc8:	02025021 */ 	addu	$t2,$s0,$v0
/*  f16adcc:	0143c021 */ 	addu	$t8,$t2,$v1
/*  f16add0:	03045821 */ 	addu	$t3,$t8,$a0
/*  f16add4:	53cb0012 */ 	beql	$s8,$t3,.PF0f16ae20
/*  f16add8:	00002025 */ 	move	$a0,$zero
/*  f16addc:	8e4e0298 */ 	lw	$t6,0x298($s2)
/*  f16ade0:	05c3000f */ 	bgezl	$t6,.PF0f16ae20
/*  f16ade4:	00002025 */ 	move	$a0,$zero
/*  f16ade8:	8e4c029c */ 	lw	$t4,0x29c($s2)
/*  f16adec:	0583000c */ 	bgezl	$t4,.PF0f16ae20
/*  f16adf0:	00002025 */ 	move	$a0,$zero
/*  f16adf4:	0fc28737 */ 	jal	bgunGetWeaponNum
/*  f16adf8:	00002025 */ 	move	$a0,$zero
/*  f16adfc:	00402025 */ 	move	$a0,$v0
/*  f16ae00:	0fc2c720 */ 	jal	weaponHasFlag
/*  f16ae04:	3c054000 */ 	lui	$a1,0x4000
/*  f16ae08:	50400050 */ 	beqzl	$v0,.PF0f16af4c
/*  f16ae0c:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16ae10:	0fc32020 */ 	jal	bmoveIsInSightAimMode
/*  f16ae14:	00000000 */ 	nop
/*  f16ae18:	1040004b */ 	beqz	$v0,.PF0f16af48
/*  f16ae1c:	00002025 */ 	move	$a0,$zero
.PF0f16ae20:
/*  f16ae20:	00002825 */ 	move	$a1,$zero
/*  f16ae24:	0fc187ed */ 	jal	func0f061d54
/*  f16ae28:	00003025 */ 	move	$a2,$zero
/*  f16ae2c:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f16ae30:	ada21624 */ 	sw	$v0,0x1624($t5)
/*  f16ae34:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ae38:	8e041624 */ 	lw	$a0,0x1624($s0)
/*  f16ae3c:	50800046 */ 	beqzl	$a0,.PF0f16af58
/*  f16ae40:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16ae44:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f16ae48:	24010003 */ 	li	$at,0x3
/*  f16ae4c:	10410003 */ 	beq	$v0,$at,.PF0f16ae5c
/*  f16ae50:	24010006 */ 	li	$at,0x6
/*  f16ae54:	1441001f */ 	bne	$v0,$at,.PF0f16aed4
/*  f16ae58:	00000000 */ 	nop
.PF0f16ae5c:
/*  f16ae5c:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f16ae60:	8c590014 */ 	lw	$t9,0x14($v0)
/*  f16ae64:	00197880 */ 	sll	$t7,$t9,0x2
/*  f16ae68:	05e3003b */ 	bgezl	$t7,.PF0f16af58
/*  f16ae6c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16ae70:	8e0a00d8 */ 	lw	$t2,0xd8($s0)
/*  f16ae74:	3c188007 */ 	lui	$t8,0x8007
/*  f16ae78:	55400014 */ 	bnezl	$t2,.PF0f16aecc
/*  f16ae7c:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16ae80:	8f180a44 */ 	lw	$t8,0xa44($t8)
/*  f16ae84:	57000011 */ 	bnezl	$t8,.PF0f16aecc
/*  f16ae88:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16ae8c:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16ae90:	50400007 */ 	beqzl	$v0,.PF0f16aeb0
/*  f16ae94:	8e0c1c54 */ 	lw	$t4,0x1c54($s0)
/*  f16ae98:	5040000c */ 	beqzl	$v0,.PF0f16aecc
/*  f16ae9c:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16aea0:	804b0037 */ 	lb	$t3,0x37($v0)
/*  f16aea4:	55600009 */ 	bnezl	$t3,.PF0f16aecc
/*  f16aea8:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16aeac:	8e0c1c54 */ 	lw	$t4,0x1c54($s0)
.PF0f16aeb0:
/*  f16aeb0:	8e0e00c4 */ 	lw	$t6,0xc4($s0)
/*  f16aeb4:	01806827 */ 	nor	$t5,$t4,$zero
/*  f16aeb8:	01cdc824 */ 	and	$t9,$t6,$t5
/*  f16aebc:	332f0008 */ 	andi	$t7,$t9,0x8
/*  f16aec0:	55e00025 */ 	bnezl	$t7,.PF0f16af58
/*  f16aec4:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16aec8:	ae001624 */ 	sw	$zero,0x1624($s0)
.PF0f16aecc:
/*  f16aecc:	10000021 */ 	b	.PF0f16af54
/*  f16aed0:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16aed4:
/*  f16aed4:	53c20006 */ 	beql	$s8,$v0,.PF0f16aef0
/*  f16aed8:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f16aedc:	12a20003 */ 	beq	$s5,$v0,.PF0f16aeec
/*  f16aee0:	24010002 */ 	li	$at,0x2
/*  f16aee4:	54410016 */ 	bnel	$v0,$at,.PF0f16af40
/*  f16aee8:	ae001624 */ 	sw	$zero,0x1624($s0)
.PF0f16aeec:
/*  f16aeec:	8c830004 */ 	lw	$v1,0x4($a0)
.PF0f16aef0:
/*  f16aef0:	8c6a0010 */ 	lw	$t2,0x10($v1)
/*  f16aef4:	31588000 */ 	andi	$t8,$t2,0x8000
/*  f16aef8:	57000017 */ 	bnezl	$t8,.PF0f16af58
/*  f16aefc:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16af00:	8e4b04b4 */ 	lw	$t3,0x4b4($s2)
/*  f16af04:	24010026 */ 	li	$at,0x26
/*  f16af08:	5561000a */ 	bnel	$t3,$at,.PF0f16af34
/*  f16af0c:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16af10:	84620004 */ 	lh	$v0,0x4($v1)
/*  f16af14:	2401014c */ 	li	$at,0x14c
/*  f16af18:	1041000e */ 	beq	$v0,$at,.PF0f16af54
/*  f16af1c:	240101aa */ 	li	$at,0x1aa
/*  f16af20:	1041000c */ 	beq	$v0,$at,.PF0f16af54
/*  f16af24:	240100b0 */ 	li	$at,0xb0
/*  f16af28:	5041000b */ 	beql	$v0,$at,.PF0f16af58
/*  f16af2c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16af30:	ae001624 */ 	sw	$zero,0x1624($s0)
.PF0f16af34:
/*  f16af34:	10000007 */ 	b	.PF0f16af54
/*  f16af38:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16af3c:	ae001624 */ 	sw	$zero,0x1624($s0)
.PF0f16af40:
/*  f16af40:	10000004 */ 	b	.PF0f16af54
/*  f16af44:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16af48:
/*  f16af48:	8e4c0284 */ 	lw	$t4,0x284($s2)
.PF0f16af4c:
/*  f16af4c:	ad801624 */ 	sw	$zero,0x1624($t4)
/*  f16af50:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16af54:
/*  f16af54:	26040638 */ 	addiu	$a0,$s0,0x638
.PF0f16af58:
/*  f16af58:	0fc2c8e8 */ 	jal	gsetHasFunctionFlags
/*  f16af5c:	3c050008 */ 	lui	$a1,0x8
/*  f16af60:	10400005 */ 	beqz	$v0,.PF0f16af78
/*  f16af64:	00000000 */ 	nop
/*  f16af68:	0fc5a851 */ 	jal	lvFindThreats
/*  f16af6c:	00000000 */ 	nop
/*  f16af70:	10000033 */ 	b	.PF0f16b040
/*  f16af74:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16af78:
/*  f16af78:	0fc28737 */ 	jal	bgunGetWeaponNum
/*  f16af7c:	00002025 */ 	move	$a0,$zero
/*  f16af80:	00402025 */ 	move	$a0,$v0
/*  f16af84:	0fc2c720 */ 	jal	weaponHasFlag
/*  f16af88:	3c054000 */ 	lui	$a1,0x4000
/*  f16af8c:	5040002c */ 	beqzl	$v0,.PF0f16b040
/*  f16af90:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16af94:	0fc68746 */ 	jal	frIsInTraining
/*  f16af98:	00000000 */ 	nop
/*  f16af9c:	5040000f */ 	beqzl	$v0,.PF0f16afdc
/*  f16afa0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16afa4:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f16afa8:	8dcd1624 */ 	lw	$t5,0x1624($t6)
/*  f16afac:	51a0000b */ 	beqzl	$t5,.PF0f16afdc
/*  f16afb0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16afb4:	0fc32020 */ 	jal	bmoveIsInSightAimMode
/*  f16afb8:	00000000 */ 	nop
/*  f16afbc:	50400007 */ 	beqzl	$v0,.PF0f16afdc
/*  f16afc0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16afc4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f16afc8:	0fc68683 */ 	jal	func0f1a0924
/*  f16afcc:	8f241624 */ 	lw	$a0,0x1624($t9)
/*  f16afd0:	1000000a */ 	b	.PF0f16affc
/*  f16afd4:	00008825 */ 	move	$s1,$zero
/*  f16afd8:	8e440284 */ 	lw	$a0,0x284($s2)
.PF0f16afdc:
/*  f16afdc:	02e02825 */ 	move	$a1,$s7
/*  f16afe0:	0fc5a620 */ 	jal	lvCheckCmpFollowThreat
/*  f16afe4:	24841624 */ 	addiu	$a0,$a0,0x1624
/*  f16afe8:	54400004 */ 	bnezl	$v0,.PF0f16affc
/*  f16afec:	00008825 */ 	move	$s1,$zero
/*  f16aff0:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f16aff4:	ade01624 */ 	sw	$zero,0x1624($t7)
/*  f16aff8:	00008825 */ 	move	$s1,$zero
.PF0f16affc:
/*  f16affc:	00008025 */ 	move	$s0,$zero
.PF0f16b000:
/*  f16b000:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16b004:	02202825 */ 	move	$a1,$s1
/*  f16b008:	01502021 */ 	addu	$a0,$t2,$s0
/*  f16b00c:	0fc5a620 */ 	jal	lvCheckCmpFollowThreat
/*  f16b010:	24841630 */ 	addiu	$a0,$a0,0x1630
/*  f16b014:	14400007 */ 	bnez	$v0,.PF0f16b034
/*  f16b018:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f16b01c:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f16b020:	03105821 */ 	addu	$t3,$t8,$s0
/*  f16b024:	a5771634 */ 	sh	$s7,0x1634($t3)
/*  f16b028:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16b02c:	01907021 */ 	addu	$t6,$t4,$s0
/*  f16b030:	a5d61638 */ 	sh	$s6,0x1638($t6)
.PF0f16b034:
/*  f16b034:	1635fff2 */ 	bne	$s1,$s5,.PF0f16b000
/*  f16b038:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f16b03c:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b040:
/*  f16b040:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16b044:	50400071 */ 	beqzl	$v0,.PF0f16b20c
/*  f16b048:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
/*  f16b04c:	8e191c54 */ 	lw	$t9,0x1c54($s0)
/*  f16b050:	8e0d00c4 */ 	lw	$t5,0xc4($s0)
/*  f16b054:	03207827 */ 	nor	$t7,$t9,$zero
/*  f16b058:	01af5024 */ 	and	$t2,$t5,$t7
/*  f16b05c:	31580004 */ 	andi	$t8,$t2,0x4
/*  f16b060:	5300006a */ 	beqzl	$t8,.PF0f16b20c
/*  f16b064:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
/*  f16b068:	804b0039 */ 	lb	$t3,0x39($v0)
/*  f16b06c:	51600067 */ 	beqzl	$t3,.PF0f16b20c
/*  f16b070:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
/*  f16b074:	9043006b */ 	lbu	$v1,0x6b($v0)
/*  f16b078:	3c0143c8 */ 	lui	$at,0x43c8
/*  f16b07c:	14600010 */ 	bnez	$v1,.PF0f16b0c0
/*  f16b080:	00000000 */ 	nop
/*  f16b084:	44816000 */ 	mtc1	$at,$f12
/*  f16b088:	0fc257ea */ 	jal	objectiveCheckHolograph
/*  f16b08c:	00000000 */ 	nop
/*  f16b090:	3c048009 */ 	lui	$a0,0x8009
/*  f16b094:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b098:	240504ff */ 	li	$a1,0x4ff
/*  f16b09c:	00003025 */ 	move	$a2,$zero
/*  f16b0a0:	02e03825 */ 	move	$a3,$s7
/*  f16b0a4:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b0a8:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b0ac:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b0b0:	0c0041a0 */ 	jal	sndStart
/*  f16b0b4:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16b0b8:	10000053 */ 	b	.PF0f16b208
/*  f16b0bc:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b0c0:
/*  f16b0c0:	17c30032 */ 	bne	$s8,$v1,.PF0f16b18c
/*  f16b0c4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16b0c8:	8e0c0490 */ 	lw	$t4,0x490($s0)
/*  f16b0cc:	3c048009 */ 	lui	$a0,0x8009
/*  f16b0d0:	24058052 */ 	li	$a1,-32686
/*  f16b0d4:	11800024 */ 	beqz	$t4,.PF0f16b168
/*  f16b0d8:	00003025 */ 	move	$a2,$zero
/*  f16b0dc:	3c048009 */ 	lui	$a0,0x8009
/*  f16b0e0:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b0e4:	24058057 */ 	li	$a1,-32681
/*  f16b0e8:	00003025 */ 	move	$a2,$zero
/*  f16b0ec:	02e03825 */ 	move	$a3,$s7
/*  f16b0f0:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b0f4:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b0f8:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b0fc:	0c0041a0 */ 	jal	sndStart
/*  f16b100:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16b104:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b108:	240b001c */ 	li	$t3,0x1c
/*  f16b10c:	00002825 */ 	move	$a1,$zero
/*  f16b110:	8e0e0490 */ 	lw	$t6,0x490($s0)
/*  f16b114:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f16b118:	25d9ffff */ 	addiu	$t9,$t6,-1
/*  f16b11c:	ae190490 */ 	sw	$t9,0x490($s0)
/*  f16b120:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b124:	8e0d0480 */ 	lw	$t5,0x480($s0)
/*  f16b128:	c5b00004 */ 	lwc1	$f16,0x4($t5)
/*  f16b12c:	e7b000c0 */ 	swc1	$f16,0xc0($sp)
/*  f16b130:	8e0f0480 */ 	lw	$t7,0x480($s0)
/*  f16b134:	c5f20008 */ 	lwc1	$f18,0x8($t7)
/*  f16b138:	e7b200c4 */ 	swc1	$f18,0xc4($sp)
/*  f16b13c:	8e0a0480 */ 	lw	$t2,0x480($s0)
/*  f16b140:	c544000c */ 	lwc1	$f4,0xc($t2)
/*  f16b144:	e7a400c8 */ 	swc1	$f4,0xc8($sp)
/*  f16b148:	8e180480 */ 	lw	$t8,0x480($s0)
/*  f16b14c:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f16b150:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f16b154:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f16b158:	0fc24477 */ 	jal	projectileCreate
/*  f16b15c:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f16b160:	10000008 */ 	b	.PF0f16b184
/*  f16b164:	00000000 */ 	nop
.PF0f16b168:
/*  f16b168:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b16c:	02e03825 */ 	move	$a3,$s7
/*  f16b170:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b174:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b178:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b17c:	0c0041a0 */ 	jal	sndStart
/*  f16b180:	afb7001c */ 	sw	$s7,0x1c($sp)
.PF0f16b184:
/*  f16b184:	10000020 */ 	b	.PF0f16b208
/*  f16b188:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b18c:
/*  f16b18c:	25ce45c8 */ 	addiu	$t6,$t6,0x45c8
/*  f16b190:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f16b194:	27ac00b4 */ 	addiu	$t4,$sp,0xb4
/*  f16b198:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f16b19c:	ad810000 */ 	sw	$at,0x0($t4)
/*  f16b1a0:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f16b1a4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f16b1a8:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f16b1ac:	ad810008 */ 	sw	$at,0x8($t4)
/*  f16b1b0:	8d4a45d4 */ 	lw	$t2,0x45d4($t2)
/*  f16b1b4:	24070017 */ 	li	$a3,0x17
/*  f16b1b8:	afaa00b0 */ 	sw	$t2,0xb0($sp)
/*  f16b1bc:	8e180480 */ 	lw	$t8,0x480($s0)
/*  f16b1c0:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f16b1c4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f16b1c8:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f16b1cc:	0fc4a8f4 */ 	jal	explosionCreateSimple
/*  f16b1d0:	24860028 */ 	addiu	$a2,$a0,0x28
/*  f16b1d4:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f16b1d8:	27ac00b0 */ 	addiu	$t4,$sp,0xb0
/*  f16b1dc:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f16b1e0:	8d6d0480 */ 	lw	$t5,0x480($t3)
/*  f16b1e4:	24060000 */ 	li	$a2,0x0
/*  f16b1e8:	00003825 */ 	move	$a3,$zero
/*  f16b1ec:	8db90000 */ 	lw	$t9,0x0($t5)
/*  f16b1f0:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f16b1f4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f16b1f8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f16b1fc:	0fc0c6bb */ 	jal	chrBeginDeath
/*  f16b200:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f16b204:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b208:
/*  f16b208:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
.PF0f16b20c:
/*  f16b20c:	51c0000c */ 	beqzl	$t6,.PF0f16b240
/*  f16b210:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16b214:	0fc18c35 */ 	jal	currentPlayerInteract
/*  f16b218:	00002025 */ 	move	$a0,$zero
/*  f16b21c:	10400012 */ 	beqz	$v0,.PF0f16b268
/*  f16b220:	00000000 */ 	nop
/*  f16b224:	0fc28953 */ 	jal	bgunReloadIfPossible
/*  f16b228:	00002025 */ 	move	$a0,$zero
/*  f16b22c:	0fc28953 */ 	jal	bgunReloadIfPossible
/*  f16b230:	03c02025 */ 	move	$a0,$s8
/*  f16b234:	1000000c */ 	b	.PF0f16b268
/*  f16b238:	00000000 */ 	nop
/*  f16b23c:	8e020480 */ 	lw	$v0,0x480($s0)
.PF0f16b240:
/*  f16b240:	10400009 */ 	beqz	$v0,.PF0f16b268
/*  f16b244:	00000000 */ 	nop
/*  f16b248:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f16b24c:	11e00006 */ 	beqz	$t7,.PF0f16b268
/*  f16b250:	00000000 */ 	nop
/*  f16b254:	904a006a */ 	lbu	$t2,0x6a($v0)
/*  f16b258:	11400003 */ 	beqz	$t2,.PF0f16b268
/*  f16b25c:	00000000 */ 	nop
/*  f16b260:	0fc18c35 */ 	jal	currentPlayerInteract
/*  f16b264:	03c02025 */ 	move	$a0,$s8
.PF0f16b268:
/*  f16b268:	0fc19121 */ 	jal	func0f0641f4
/*  f16b26c:	00000000 */ 	nop
/*  f16b270:	0fc57698 */ 	jal	bgRender
/*  f16b274:	02602025 */ 	move	$a0,$s3
/*  f16b278:	3c108007 */ 	lui	$s0,0x8007
/*  f16b27c:	8e106238 */ 	lw	$s0,0x6238($s0)
/*  f16b280:	00409825 */ 	move	$s3,$v0
/*  f16b284:	3a18000f */ 	xori	$t8,$s0,0xf
/*  f16b288:	2f100001 */ 	sltiu	$s0,$t8,0x1
/*  f16b28c:	16000005 */ 	bnez	$s0,.PF0f16b2a4
/*  f16b290:	00000000 */ 	nop
/*  f16b294:	3c108006 */ 	lui	$s0,0x8006
/*  f16b298:	8e10ecd0 */ 	lw	$s0,-0x1330($s0)
/*  f16b29c:	0010582b */ 	sltu	$t3,$zero,$s0
/*  f16b2a0:	01608025 */ 	move	$s0,$t3
.PF0f16b2a4:
/*  f16b2a4:	0fc0a16f */ 	jal	func0f028498
/*  f16b2a8:	02002025 */ 	move	$a0,$s0
/*  f16b2ac:	0fc1fe48 */ 	jal	propsRenderBeams
/*  f16b2b0:	02602025 */ 	move	$a0,$s3
/*  f16b2b4:	0fc54ce5 */ 	jal	shardsRender
/*  f16b2b8:	00402025 */ 	move	$a0,$v0
/*  f16b2bc:	0fc4c2ee */ 	jal	sparksRender
/*  f16b2c0:	00402025 */ 	move	$a0,$v0
/*  f16b2c4:	0fc4c6f4 */ 	jal	weatherRender
/*  f16b2c8:	00402025 */ 	move	$a0,$v0
/*  f16b2cc:	3c0d8006 */ 	lui	$t5,0x8006
/*  f16b2d0:	8dad1310 */ 	lw	$t5,0x1310($t5)
/*  f16b2d4:	00409825 */ 	move	$s3,$v0
/*  f16b2d8:	11a00004 */ 	beqz	$t5,.PF0f16b2ec
/*  f16b2dc:	00000000 */ 	nop
/*  f16b2e0:	0fc0285e */ 	jal	nbombsRender
/*  f16b2e4:	00402025 */ 	move	$a0,$v0
/*  f16b2e8:	00409825 */ 	move	$s3,$v0
.PF0f16b2ec:
/*  f16b2ec:	3c198007 */ 	lui	$t9,0x8007
/*  f16b2f0:	8f396230 */ 	lw	$t9,0x6230($t9)
/*  f16b2f4:	24010002 */ 	li	$at,0x2
/*  f16b2f8:	17210005 */ 	bne	$t9,$at,.PF0f16b310
/*  f16b2fc:	00000000 */ 	nop
/*  f16b300:	0fc3034d */ 	jal	currentPlayerRenderHud
/*  f16b304:	02602025 */ 	move	$a0,$s3
/*  f16b308:	1000000b */ 	b	.PF0f16b338
/*  f16b30c:	00409825 */ 	move	$s3,$v0
.PF0f16b310:
/*  f16b310:	0fc2bce6 */ 	jal	func0f0aeed8
/*  f16b314:	02602025 */ 	move	$a0,$s3
/*  f16b318:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16b31c:	00409825 */ 	move	$s3,$v0
/*  f16b320:	958e0010 */ 	lhu	$t6,0x10($t4)
/*  f16b324:	13ce0004 */ 	beq	$s8,$t6,.PF0f16b338
/*  f16b328:	00000000 */ 	nop
/*  f16b32c:	0fc57025 */ 	jal	func0f15b114
/*  f16b330:	00402025 */ 	move	$a0,$v0
/*  f16b334:	00409825 */ 	move	$s3,$v0
.PF0f16b338:
/*  f16b338:	3c0f8007 */ 	lui	$t7,0x8007
/*  f16b33c:	8def6248 */ 	lw	$t7,0x6248($t7)
/*  f16b340:	1de001f6 */ 	bgtz	$t7,.PF0f16bb1c
/*  f16b344:	00000000 */ 	nop
/*  f16b348:	8e4a02ac */ 	lw	$t2,0x2ac($s2)
/*  f16b34c:	24010006 */ 	li	$at,0x6
/*  f16b350:	00008825 */ 	move	$s1,$zero
/*  f16b354:	1541006f */ 	bne	$t2,$at,.PF0f16b514
/*  f16b358:	3c10800a */ 	lui	$s0,0x800a
/*  f16b35c:	8610e38c */ 	lh	$s0,-0x1c74($s0)
/*  f16b360:	24010181 */ 	li	$at,0x181
/*  f16b364:	3c048008 */ 	lui	$a0,0x8008
/*  f16b368:	12010011 */ 	beq	$s0,$at,.PF0f16b3b0
/*  f16b36c:	24010183 */ 	li	$at,0x183
/*  f16b370:	1201000f */ 	beq	$s0,$at,.PF0f16b3b0
/*  f16b374:	24010188 */ 	li	$at,0x188
/*  f16b378:	1201000d */ 	beq	$s0,$at,.PF0f16b3b0
/*  f16b37c:	240101e5 */ 	li	$at,0x1e5
/*  f16b380:	16010064 */ 	bne	$s0,$at,.PF0f16b514
/*  f16b384:	3c02800a */ 	lui	$v0,0x800a
/*  f16b388:	8c42e380 */ 	lw	$v0,-0x1c80($v0)
/*  f16b38c:	28410348 */ 	slti	$at,$v0,0x348
/*  f16b390:	14200060 */ 	bnez	$at,.PF0f16b514
/*  f16b394:	28410583 */ 	slti	$at,$v0,0x583
/*  f16b398:	1020005e */ 	beqz	$at,.PF0f16b514
/*  f16b39c:	00000000 */ 	nop
/*  f16b3a0:	0fc522da */ 	jal	bviewRenderHorizonScanner
/*  f16b3a4:	02602025 */ 	move	$a0,$s3
/*  f16b3a8:	1000005a */ 	b	.PF0f16b514
/*  f16b3ac:	00409825 */ 	move	$s3,$v0
.PF0f16b3b0:
/*  f16b3b0:	8c8445d8 */ 	lw	$a0,0x45d8($a0)
/*  f16b3b4:	00008025 */ 	move	$s0,$zero
/*  f16b3b8:	03c08825 */ 	move	$s1,$s8
/*  f16b3bc:	1480000b */ 	bnez	$a0,.PF0f16b3ec
/*  f16b3c0:	2405059f */ 	li	$a1,0x59f
/*  f16b3c4:	3c048009 */ 	lui	$a0,0x8009
/*  f16b3c8:	3c068008 */ 	lui	$a2,0x8008
/*  f16b3cc:	24c645d8 */ 	addiu	$a2,$a2,0x45d8
/*  f16b3d0:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b3d4:	02e03825 */ 	move	$a3,$s7
/*  f16b3d8:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b3dc:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b3e0:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b3e4:	0c0041a0 */ 	jal	sndStart
/*  f16b3e8:	afb7001c */ 	sw	$s7,0x1c($sp)
.PF0f16b3ec:
/*  f16b3ec:	3c188008 */ 	lui	$t8,0x8008
/*  f16b3f0:	8f1845dc */ 	lw	$t8,0x45dc($t8)
/*  f16b3f4:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f16b3f8:	3c018008 */ 	lui	$at,0x8008
/*  f16b3fc:	030b6823 */ 	subu	$t5,$t8,$t3
/*  f16b400:	05a1000b */ 	bgez	$t5,.PF0f16b430
/*  f16b404:	ac2d45dc */ 	sw	$t5,0x45dc($at)
/*  f16b408:	0c004ad4 */ 	jal	random
/*  f16b40c:	00000000 */ 	nop
/*  f16b410:	240100a6 */ 	li	$at,0xa6
/*  f16b414:	0041001b */ 	divu	$zero,$v0,$at
/*  f16b418:	0000c810 */ 	mfhi	$t9
/*  f16b41c:	272c0021 */ 	addiu	$t4,$t9,0x21
/*  f16b420:	3c018008 */ 	lui	$at,0x8008
/*  f16b424:	ac2c45dc */ 	sw	$t4,0x45dc($at)
/*  f16b428:	3c018008 */ 	lui	$at,0x8008
/*  f16b42c:	a02045e0 */ 	sb	$zero,0x45e0($at)
.PF0f16b430:
/*  f16b430:	02602025 */ 	move	$a0,$s3
/*  f16b434:	2405ffff */ 	li	$a1,-1
/*  f16b438:	0fc50d3f */ 	jal	bviewRenderFilmLens
/*  f16b43c:	2406ffff */ 	li	$a2,-1
/*  f16b440:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16b444:	8dce45dc */ 	lw	$t6,0x45dc($t6)
/*  f16b448:	00409825 */ 	move	$s3,$v0
/*  f16b44c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f16b450:	29c1000c */ 	slti	$at,$t6,0xc
/*  f16b454:	10200017 */ 	beqz	$at,.PF0f16b4b4
/*  f16b458:	00000000 */ 	nop
/*  f16b45c:	91ef45e0 */ 	lbu	$t7,0x45e0($t7)
/*  f16b460:	240a0001 */ 	li	$t2,0x1
/*  f16b464:	3c018008 */ 	lui	$at,0x8008
/*  f16b468:	15e0000b */ 	bnez	$t7,.PF0f16b498
/*  f16b46c:	3c048009 */ 	lui	$a0,0x8009
/*  f16b470:	a02a45e0 */ 	sb	$t2,0x45e0($at)
/*  f16b474:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b478:	2405059e */ 	li	$a1,0x59e
/*  f16b47c:	00003025 */ 	move	$a2,$zero
/*  f16b480:	02e03825 */ 	move	$a3,$s7
/*  f16b484:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b488:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b48c:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b490:	0c0041a0 */ 	jal	sndStart
/*  f16b494:	afb7001c */ 	sw	$s7,0x1c($sp)
.PF0f16b498:
/*  f16b498:	3c188008 */ 	lui	$t8,0x8008
/*  f16b49c:	8f1845dc */ 	lw	$t8,0x45dc($t8)
/*  f16b4a0:	240d00e1 */ 	li	$t5,0xe1
/*  f16b4a4:	00185880 */ 	sll	$t3,$t8,0x2
/*  f16b4a8:	01785823 */ 	subu	$t3,$t3,$t8
/*  f16b4ac:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f16b4b0:	01ab8023 */ 	subu	$s0,$t5,$t3
.PF0f16b4b4:
/*  f16b4b4:	0c004ad4 */ 	jal	random
/*  f16b4b8:	00000000 */ 	nop
/*  f16b4bc:	2401003c */ 	li	$at,0x3c
/*  f16b4c0:	0041001b */ 	divu	$zero,$v0,$at
/*  f16b4c4:	0000c810 */ 	mfhi	$t9
/*  f16b4c8:	24010001 */ 	li	$at,0x1
/*  f16b4cc:	1721000b */ 	bne	$t9,$at,.PF0f16b4fc
/*  f16b4d0:	3c048009 */ 	lui	$a0,0x8009
/*  f16b4d4:	241000ff */ 	li	$s0,0xff
/*  f16b4d8:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b4dc:	2405059d */ 	li	$a1,0x59d
/*  f16b4e0:	00003025 */ 	move	$a2,$zero
/*  f16b4e4:	02e03825 */ 	move	$a3,$s7
/*  f16b4e8:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b4ec:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b4f0:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b4f4:	0c0041a0 */ 	jal	sndStart
/*  f16b4f8:	afb7001c */ 	sw	$s7,0x1c($sp)
.PF0f16b4fc:
/*  f16b4fc:	12000005 */ 	beqz	$s0,.PF0f16b514
/*  f16b500:	02602025 */ 	move	$a0,$s3
/*  f16b504:	2405ffff */ 	li	$a1,-1
/*  f16b508:	0fc50c6d */ 	jal	bviewRenderStatic
/*  f16b50c:	02003025 */ 	move	$a2,$s0
/*  f16b510:	00409825 */ 	move	$s3,$v0
.PF0f16b514:
/*  f16b514:	3c048008 */ 	lui	$a0,0x8008
/*  f16b518:	8c8445d8 */ 	lw	$a0,0x45d8($a0)
/*  f16b51c:	50800006 */ 	beqzl	$a0,.PF0f16b538
/*  f16b520:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b524:	56200004 */ 	bnezl	$s1,.PF0f16b538
/*  f16b528:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b52c:	0c00cd09 */ 	jal	audioStop
/*  f16b530:	00000000 */ 	nop
/*  f16b534:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b538:
/*  f16b538:	24010002 */ 	li	$at,0x2
/*  f16b53c:	960c0010 */ 	lhu	$t4,0x10($s0)
/*  f16b540:	5581001c */ 	bnel	$t4,$at,.PF0f16b5b4
/*  f16b544:	96030010 */ 	lhu	$v1,0x10($s0)
/*  f16b548:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
/*  f16b54c:	24010006 */ 	li	$at,0x6
/*  f16b550:	02602025 */ 	move	$a0,$s3
/*  f16b554:	11c10016 */ 	beq	$t6,$at,.PF0f16b5b0
/*  f16b558:	2405ffff */ 	li	$a1,-1
/*  f16b55c:	0fc50cb9 */ 	jal	bviewRenderSlayerRocketLens
/*  f16b560:	2406ffff */ 	li	$a2,-1
/*  f16b564:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b568:	00409825 */ 	move	$s3,$v0
/*  f16b56c:	2401004b */ 	li	$at,0x4b
/*  f16b570:	8e0300c8 */ 	lw	$v1,0xc8($s0)
/*  f16b574:	02602025 */ 	move	$a0,$s3
/*  f16b578:	3c054fff */ 	lui	$a1,0x4fff
/*  f16b57c:	1860000c */ 	blez	$v1,.PF0f16b5b0
/*  f16b580:	00033200 */ 	sll	$a2,$v1,0x8
/*  f16b584:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16b588:	00c1001a */ 	div	$zero,$a2,$at
/*  f16b58c:	00003012 */ 	mflo	$a2
/*  f16b590:	2cc10100 */ 	sltiu	$at,$a2,0x100
/*  f16b594:	14200002 */ 	bnez	$at,.PF0f16b5a0
/*  f16b598:	00000000 */ 	nop
/*  f16b59c:	240600ff */ 	li	$a2,0xff
.PF0f16b5a0:
/*  f16b5a0:	0fc50c6d */ 	jal	bviewRenderStatic
/*  f16b5a4:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f16b5a8:	00409825 */ 	move	$s3,$v0
/*  f16b5ac:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b5b0:
/*  f16b5b0:	96030010 */ 	lhu	$v1,0x10($s0)
.PF0f16b5b4:
/*  f16b5b4:	24010003 */ 	li	$at,0x3
/*  f16b5b8:	02602025 */ 	move	$a0,$s3
/*  f16b5bc:	14610009 */ 	bne	$v1,$at,.PF0f16b5e4
/*  f16b5c0:	3c054fff */ 	lui	$a1,0x4fff
/*  f16b5c4:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f16b5c8:	0fc50c6d */ 	jal	bviewRenderStatic
/*  f16b5cc:	240600ff */ 	li	$a2,0xff
/*  f16b5d0:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16b5d4:	00409825 */ 	move	$s3,$v0
/*  f16b5d8:	a5400010 */ 	sh	$zero,0x10($t2)
/*  f16b5dc:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b5e0:	96030010 */ 	lhu	$v1,0x10($s0)
.PF0f16b5e4:
/*  f16b5e4:	57c3001f */ 	bnel	$s8,$v1,.PF0f16b664
/*  f16b5e8:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16b5ec:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f16b5f0:	24010006 */ 	li	$at,0x6
/*  f16b5f4:	5301001b */ 	beql	$t8,$at,.PF0f16b664
/*  f16b5f8:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16b5fc:	8e020254 */ 	lw	$v0,0x254($s0)
/*  f16b600:	24060063 */ 	li	$a2,0x63
/*  f16b604:	240c00f9 */ 	li	$t4,0xf9
/*  f16b608:	284100a6 */ 	slti	$at,$v0,0xa6
/*  f16b60c:	1020000c */ 	beqz	$at,.PF0f16b640
/*  f16b610:	00026880 */ 	sll	$t5,$v0,0x2
/*  f16b614:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f16b618:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f16b61c:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f16b620:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f16b624:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f16b628:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f16b62c:	24010032 */ 	li	$at,0x32
/*  f16b630:	01a1001a */ 	div	$zero,$t5,$at
/*  f16b634:	00005812 */ 	mflo	$t3
/*  f16b638:	000bc883 */ 	sra	$t9,$t3,0x2
/*  f16b63c:	01993023 */ 	subu	$a2,$t4,$t9
.PF0f16b640:
/*  f16b640:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b644:	c4208e64 */ 	lwc1	$f0,-0x719c($at)
/*  f16b648:	02602025 */ 	move	$a0,$s3
/*  f16b64c:	2405ffff */ 	li	$a1,-1
/*  f16b650:	44070000 */ 	mfc1	$a3,$f0
/*  f16b654:	0fc50dd8 */ 	jal	bviewRenderZoomBlur
/*  f16b658:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16b65c:	00409825 */ 	move	$s3,$v0
/*  f16b660:	8e430460 */ 	lw	$v1,0x460($s2)
.PF0f16b664:
/*  f16b664:	18600003 */ 	blez	$v1,.PF0f16b674
/*  f16b668:	2861001a */ 	slti	$at,$v1,0x1a
/*  f16b66c:	5420000c */ 	bnezl	$at,.PF0f16b6a0
/*  f16b670:	2401001a */ 	li	$at,0x1a
.PF0f16b674:
/*  f16b674:	8e420464 */ 	lw	$v0,0x464($s2)
/*  f16b678:	10400004 */ 	beqz	$v0,.PF0f16b68c
/*  f16b67c:	00000000 */ 	nop
/*  f16b680:	8e4e0468 */ 	lw	$t6,0x468($s2)
/*  f16b684:	51c00006 */ 	beqzl	$t6,.PF0f16b6a0
/*  f16b688:	2401001a */ 	li	$at,0x1a
.PF0f16b68c:
/*  f16b68c:	54400085 */ 	bnezl	$v0,.PF0f16b8a4
/*  f16b690:	2861000e */ 	slti	$at,$v1,0xe
/*  f16b694:	8e4f0468 */ 	lw	$t7,0x468($s2)
/*  f16b698:	11e00081 */ 	beqz	$t7,.PF0f16b8a0
/*  f16b69c:	2401001a */ 	li	$at,0x1a
.PF0f16b6a0:
/*  f16b6a0:	54610018 */ 	bnel	$v1,$at,.PF0f16b704
/*  f16b6a4:	2861000d */ 	slti	$at,$v1,0xd
/*  f16b6a8:	8e4a0464 */ 	lw	$t2,0x464($s2)
/*  f16b6ac:	55400015 */ 	bnezl	$t2,.PF0f16b704
/*  f16b6b0:	2861000d */ 	slti	$at,$v1,0xd
/*  f16b6b4:	0fc5b180 */ 	jal	lvGetSlowMotionType
/*  f16b6b8:	00000000 */ 	nop
/*  f16b6bc:	10400003 */ 	beqz	$v0,.PF0f16b6cc
/*  f16b6c0:	3c048009 */ 	lui	$a0,0x8009
/*  f16b6c4:	10000002 */ 	b	.PF0f16b6d0
/*  f16b6c8:	241005c9 */ 	li	$s0,0x5c9
.PF0f16b6cc:
/*  f16b6cc:	241002ad */ 	li	$s0,0x2ad
.PF0f16b6d0:
/*  f16b6d0:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f16b6d4:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f16b6d8:	03002825 */ 	move	$a1,$t8
/*  f16b6dc:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b6e0:	00003025 */ 	move	$a2,$zero
/*  f16b6e4:	02e03825 */ 	move	$a3,$s7
/*  f16b6e8:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b6ec:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b6f0:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b6f4:	0c0041a0 */ 	jal	sndStart
/*  f16b6f8:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16b6fc:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16b700:	2861000d */ 	slti	$at,$v1,0xd
.PF0f16b704:
/*  f16b704:	10200026 */ 	beqz	$at,.PF0f16b7a0
/*  f16b708:	240c001a */ 	li	$t4,0x1a
/*  f16b70c:	2401000d */ 	li	$at,0xd
/*  f16b710:	00033080 */ 	sll	$a2,$v1,0x2
/*  f16b714:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16b718:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b71c:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16b720:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b724:	00c33021 */ 	addu	$a2,$a2,$v1
/*  f16b728:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b72c:	00c1001a */ 	div	$zero,$a2,$at
/*  f16b730:	44833000 */ 	mtc1	$v1,$f6
/*  f16b734:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b738:	c42a8e68 */ 	lwc1	$f10,-0x7198($at)
/*  f16b73c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f16b740:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b744:	c4328e6c */ 	lwc1	$f18,-0x7194($at)
/*  f16b748:	00003012 */ 	mflo	$a2
/*  f16b74c:	02602025 */ 	move	$a0,$s3
/*  f16b750:	2405ffff */ 	li	$a1,-1
/*  f16b754:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f16b758:	46128000 */ 	add.s	$f0,$f16,$f18
/*  f16b75c:	44070000 */ 	mfc1	$a3,$f0
/*  f16b760:	0fc50dd8 */ 	jal	bviewRenderZoomBlur
/*  f16b764:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16b768:	8e4b0460 */ 	lw	$t3,0x460($s2)
/*  f16b76c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b770:	c4288e70 */ 	lwc1	$f8,-0x7190($at)
/*  f16b774:	448b2000 */ 	mtc1	$t3,$f4
/*  f16b778:	00402025 */ 	move	$a0,$v0
/*  f16b77c:	240500ff */ 	li	$a1,0xff
/*  f16b780:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16b784:	240600ff */ 	li	$a2,0xff
/*  f16b788:	240700ff */ 	li	$a3,0xff
/*  f16b78c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f16b790:	0fc2ed6b */ 	jal	fadeDraw
/*  f16b794:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f16b798:	10000029 */ 	b	.PF0f16b840
/*  f16b79c:	00409825 */ 	move	$s3,$v0
.PF0f16b7a0:
/*  f16b7a0:	2401000d */ 	li	$at,0xd
/*  f16b7a4:	01831023 */ 	subu	$v0,$t4,$v1
/*  f16b7a8:	00023080 */ 	sll	$a2,$v0,0x2
/*  f16b7ac:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f16b7b0:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b7b4:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f16b7b8:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b7bc:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f16b7c0:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b7c4:	00c1001a */ 	div	$zero,$a2,$at
/*  f16b7c8:	44828000 */ 	mtc1	$v0,$f16
/*  f16b7cc:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b7d0:	c4248e74 */ 	lwc1	$f4,-0x718c($at)
/*  f16b7d4:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f16b7d8:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b7dc:	c4288e78 */ 	lwc1	$f8,-0x7188($at)
/*  f16b7e0:	00003012 */ 	mflo	$a2
/*  f16b7e4:	02602025 */ 	move	$a0,$s3
/*  f16b7e8:	2405ffff */ 	li	$a1,-1
/*  f16b7ec:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f16b7f0:	46083000 */ 	add.s	$f0,$f6,$f8
/*  f16b7f4:	44070000 */ 	mfc1	$a3,$f0
/*  f16b7f8:	0fc50dd8 */ 	jal	bviewRenderZoomBlur
/*  f16b7fc:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16b800:	8e4e0460 */ 	lw	$t6,0x460($s2)
/*  f16b804:	3c0141d0 */ 	lui	$at,0x41d0
/*  f16b808:	44815000 */ 	mtc1	$at,$f10
/*  f16b80c:	448e8000 */ 	mtc1	$t6,$f16
/*  f16b810:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b814:	c4268e7c */ 	lwc1	$f6,-0x7184($at)
/*  f16b818:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f16b81c:	00402025 */ 	move	$a0,$v0
/*  f16b820:	240500ff */ 	li	$a1,0xff
/*  f16b824:	240600ff */ 	li	$a2,0xff
/*  f16b828:	240700ff */ 	li	$a3,0xff
/*  f16b82c:	46125101 */ 	sub.s	$f4,$f10,$f18
/*  f16b830:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f16b834:	0fc2ed6b */ 	jal	fadeDraw
/*  f16b838:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f16b83c:	00409825 */ 	move	$s3,$v0
.PF0f16b840:
/*  f16b840:	8e4f028c */ 	lw	$t7,0x28c($s2)
/*  f16b844:	55e0000c */ 	bnezl	$t7,.PF0f16b878
/*  f16b848:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16b84c:	8e4a0464 */ 	lw	$t2,0x464($s2)
/*  f16b850:	51400006 */ 	beqzl	$t2,.PF0f16b86c
/*  f16b854:	8e4b0460 */ 	lw	$t3,0x460($s2)
/*  f16b858:	8e580460 */ 	lw	$t8,0x460($s2)
/*  f16b85c:	270d0001 */ 	addiu	$t5,$t8,0x1
/*  f16b860:	10000004 */ 	b	.PF0f16b874
/*  f16b864:	ae4d0460 */ 	sw	$t5,0x460($s2)
/*  f16b868:	8e4b0460 */ 	lw	$t3,0x460($s2)
.PF0f16b86c:
/*  f16b86c:	256cffff */ 	addiu	$t4,$t3,-1
/*  f16b870:	ae4c0460 */ 	sw	$t4,0x460($s2)
.PF0f16b874:
/*  f16b874:	8e430460 */ 	lw	$v1,0x460($s2)
.PF0f16b878:
/*  f16b878:	2861001b */ 	slti	$at,$v1,0x1b
/*  f16b87c:	14200004 */ 	bnez	$at,.PF0f16b890
/*  f16b880:	00000000 */ 	nop
/*  f16b884:	2403001a */ 	li	$v1,0x1a
/*  f16b888:	10000005 */ 	b	.PF0f16b8a0
/*  f16b88c:	ae430460 */ 	sw	$v1,0x460($s2)
.PF0f16b890:
/*  f16b890:	04630004 */ 	bgezl	$v1,.PF0f16b8a4
/*  f16b894:	2861000e */ 	slti	$at,$v1,0xe
/*  f16b898:	ae400460 */ 	sw	$zero,0x460($s2)
/*  f16b89c:	00001825 */ 	move	$v1,$zero
.PF0f16b8a0:
/*  f16b8a0:	2861000e */ 	slti	$at,$v1,0xe
.PF0f16b8a4:
/*  f16b8a4:	54200004 */ 	bnezl	$at,.PF0f16b8b8
/*  f16b8a8:	ae400468 */ 	sw	$zero,0x468($s2)
/*  f16b8ac:	10000002 */ 	b	.PF0f16b8b8
/*  f16b8b0:	ae5e0468 */ 	sw	$s8,0x468($s2)
/*  f16b8b4:	ae400468 */ 	sw	$zero,0x468($s2)
.PF0f16b8b8:
/*  f16b8b8:	52800009 */ 	beqzl	$s4,.PF0f16b8e0
/*  f16b8bc:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
/*  f16b8c0:	0fc52608 */ 	jal	bviewClearBlur
/*  f16b8c4:	00000000 */ 	nop
/*  f16b8c8:	02602025 */ 	move	$a0,$s3
/*  f16b8cc:	2405ffff */ 	li	$a1,-1
/*  f16b8d0:	0fc50bea */ 	jal	bviewRenderMotionBlur
/*  f16b8d4:	02803025 */ 	move	$a2,$s4
/*  f16b8d8:	00409825 */ 	move	$s3,$v0
/*  f16b8dc:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
.PF0f16b8e0:
/*  f16b8e0:	24010006 */ 	li	$at,0x6
/*  f16b8e4:	15c10031 */ 	bne	$t6,$at,.PF0f16b9ac
/*  f16b8e8:	00000000 */ 	nop
/*  f16b8ec:	0fc2eb66 */ 	jal	cutsceneGetBlurFrac
/*  f16b8f0:	00000000 */ 	nop
/*  f16b8f4:	44808000 */ 	mtc1	$zero,$f16
/*  f16b8f8:	3c01437f */ 	lui	$at,0x437f
/*  f16b8fc:	4600803c */ 	c.lt.s	$f16,$f0
/*  f16b900:	00000000 */ 	nop
/*  f16b904:	45000029 */ 	bc1f	.PF0f16b9ac
/*  f16b908:	00000000 */ 	nop
/*  f16b90c:	44815000 */ 	mtc1	$at,$f10
/*  f16b910:	24060001 */ 	li	$a2,0x1
/*  f16b914:	3c014f00 */ 	lui	$at,0x4f00
/*  f16b918:	460a0482 */ 	mul.s	$f18,$f0,$f10
/*  f16b91c:	02602025 */ 	move	$a0,$s3
/*  f16b920:	2405ff00 */ 	li	$a1,-256
/*  f16b924:	444ff800 */ 	cfc1	$t7,$31
/*  f16b928:	44c6f800 */ 	ctc1	$a2,$31
/*  f16b92c:	00000000 */ 	nop
/*  f16b930:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f16b934:	4446f800 */ 	cfc1	$a2,$31
/*  f16b938:	00000000 */ 	nop
/*  f16b93c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f16b940:	50c00013 */ 	beqzl	$a2,.PF0f16b990
/*  f16b944:	44062000 */ 	mfc1	$a2,$f4
/*  f16b948:	44812000 */ 	mtc1	$at,$f4
/*  f16b94c:	24060001 */ 	li	$a2,0x1
/*  f16b950:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f16b954:	44c6f800 */ 	ctc1	$a2,$31
/*  f16b958:	00000000 */ 	nop
/*  f16b95c:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f16b960:	4446f800 */ 	cfc1	$a2,$31
/*  f16b964:	00000000 */ 	nop
/*  f16b968:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f16b96c:	14c00005 */ 	bnez	$a2,.PF0f16b984
/*  f16b970:	00000000 */ 	nop
/*  f16b974:	44062000 */ 	mfc1	$a2,$f4
/*  f16b978:	3c018000 */ 	lui	$at,0x8000
/*  f16b97c:	10000007 */ 	b	.PF0f16b99c
/*  f16b980:	00c13025 */ 	or	$a2,$a2,$at
.PF0f16b984:
/*  f16b984:	10000005 */ 	b	.PF0f16b99c
/*  f16b988:	2406ffff */ 	li	$a2,-1
/*  f16b98c:	44062000 */ 	mfc1	$a2,$f4
.PF0f16b990:
/*  f16b990:	00000000 */ 	nop
/*  f16b994:	04c0fffb */ 	bltz	$a2,.PF0f16b984
/*  f16b998:	00000000 */ 	nop
.PF0f16b99c:
/*  f16b99c:	44cff800 */ 	ctc1	$t7,$31
/*  f16b9a0:	0fc50bea */ 	jal	bviewRenderMotionBlur
/*  f16b9a4:	00000000 */ 	nop
/*  f16b9a8:	00409825 */ 	move	$s3,$v0
.PF0f16b9ac:
/*  f16b9ac:	0fc47e76 */ 	jal	debugGetMotionBlur
/*  f16b9b0:	00000000 */ 	nop
/*  f16b9b4:	145e0006 */ 	bne	$v0,$s8,.PF0f16b9d0
/*  f16b9b8:	02602025 */ 	move	$a0,$s3
/*  f16b9bc:	2405ff00 */ 	li	$a1,-256
/*  f16b9c0:	0fc50bea */ 	jal	bviewRenderMotionBlur
/*  f16b9c4:	24060080 */ 	li	$a2,0x80
/*  f16b9c8:	10000014 */ 	b	.PF0f16ba1c
/*  f16b9cc:	00409825 */ 	move	$s3,$v0
.PF0f16b9d0:
/*  f16b9d0:	0fc47e76 */ 	jal	debugGetMotionBlur
/*  f16b9d4:	00000000 */ 	nop
/*  f16b9d8:	24010002 */ 	li	$at,0x2
/*  f16b9dc:	14410006 */ 	bne	$v0,$at,.PF0f16b9f8
/*  f16b9e0:	02602025 */ 	move	$a0,$s3
/*  f16b9e4:	2405ff00 */ 	li	$a1,-256
/*  f16b9e8:	0fc50bea */ 	jal	bviewRenderMotionBlur
/*  f16b9ec:	240600c0 */ 	li	$a2,0xc0
/*  f16b9f0:	1000000a */ 	b	.PF0f16ba1c
/*  f16b9f4:	00409825 */ 	move	$s3,$v0
.PF0f16b9f8:
/*  f16b9f8:	0fc47e76 */ 	jal	debugGetMotionBlur
/*  f16b9fc:	00000000 */ 	nop
/*  f16ba00:	24010003 */ 	li	$at,0x3
/*  f16ba04:	14410005 */ 	bne	$v0,$at,.PF0f16ba1c
/*  f16ba08:	02602025 */ 	move	$a0,$s3
/*  f16ba0c:	2405ff00 */ 	li	$a1,-256
/*  f16ba10:	0fc50bea */ 	jal	bviewRenderMotionBlur
/*  f16ba14:	240600e6 */ 	li	$a2,0xe6
/*  f16ba18:	00409825 */ 	move	$s3,$v0
.PF0f16ba1c:
/*  f16ba1c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ba20:	24010003 */ 	li	$at,0x3
/*  f16ba24:	92031bfc */ 	lbu	$v1,0x1bfc($s0)
/*  f16ba28:	1860003c */ 	blez	$v1,.PF0f16bb1c
/*  f16ba2c:	00000000 */ 	nop
/*  f16ba30:	14610002 */ 	bne	$v1,$at,.PF0f16ba3c
/*  f16ba34:	00008825 */ 	move	$s1,$zero
/*  f16ba38:	241100ff */ 	li	$s1,0xff
.PF0f16ba3c:
/*  f16ba3c:	56a30009 */ 	bnel	$s5,$v1,.PF0f16ba64
/*  f16ba40:	24010002 */ 	li	$at,0x2
/*  f16ba44:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f16ba48:	28410010 */ 	slti	$at,$v0,0x10
/*  f16ba4c:	50200005 */ 	beqzl	$at,.PF0f16ba64
/*  f16ba50:	24010002 */ 	li	$at,0x2
/*  f16ba54:	00028823 */ 	negu	$s1,$v0
/*  f16ba58:	00115100 */ 	sll	$t2,$s1,0x4
/*  f16ba5c:	255100f0 */ 	addiu	$s1,$t2,0xf0
/*  f16ba60:	24010002 */ 	li	$at,0x2
.PF0f16ba64:
/*  f16ba64:	1461000b */ 	bne	$v1,$at,.PF0f16ba94
/*  f16ba68:	00000000 */ 	nop
/*  f16ba6c:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f16ba70:	28410021 */ 	slti	$at,$v0,0x21
/*  f16ba74:	54200004 */ 	bnezl	$at,.PF0f16ba88
/*  f16ba78:	24010030 */ 	li	$at,0x30
/*  f16ba7c:	00028900 */ 	sll	$s1,$v0,0x4
/*  f16ba80:	2631fe00 */ 	addiu	$s1,$s1,-512
/*  f16ba84:	24010030 */ 	li	$at,0x30
.PF0f16ba88:
/*  f16ba88:	14410002 */ 	bne	$v0,$at,.PF0f16ba94
/*  f16ba8c:	00000000 */ 	nop
/*  f16ba90:	241100ff */ 	li	$s1,0xff
.PF0f16ba94:
/*  f16ba94:	12200021 */ 	beqz	$s1,.PF0f16bb1c
/*  f16ba98:	00000000 */ 	nop
/*  f16ba9c:	0fc550cf */ 	jal	func0f153628
/*  f16baa0:	02602025 */ 	move	$a0,$s3
/*  f16baa4:	0c002e91 */ 	jal	viGetViewLeft
/*  f16baa8:	00409825 */ 	move	$s3,$v0
/*  f16baac:	0c002e95 */ 	jal	viGetViewTop
/*  f16bab0:	a7a20072 */ 	sh	$v0,0x72($sp)
/*  f16bab4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16bab8:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f16babc:	0c002e91 */ 	jal	viGetViewLeft
/*  f16bac0:	03008025 */ 	move	$s0,$t8
/*  f16bac4:	0c002e73 */ 	jal	viGetViewWidth
/*  f16bac8:	a7a20076 */ 	sh	$v0,0x76($sp)
/*  f16bacc:	0c002e95 */ 	jal	viGetViewTop
/*  f16bad0:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f16bad4:	0c002e77 */ 	jal	viGetViewHeight
/*  f16bad8:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16badc:	87ac0090 */ 	lh	$t4,0x90($sp)
/*  f16bae0:	87ad008e */ 	lh	$t5,0x8e($sp)
/*  f16bae4:	87ab0076 */ 	lh	$t3,0x76($sp)
/*  f16bae8:	2401ff00 */ 	li	$at,-256
/*  f16baec:	02217025 */ 	or	$t6,$s1,$at
/*  f16baf0:	004cc821 */ 	addu	$t9,$v0,$t4
/*  f16baf4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f16baf8:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f16bafc:	02602025 */ 	move	$a0,$s3
/*  f16bb00:	87a50072 */ 	lh	$a1,0x72($sp)
/*  f16bb04:	02003025 */ 	move	$a2,$s0
/*  f16bb08:	0fc551d2 */ 	jal	func0f153a34
/*  f16bb0c:	01ab3821 */ 	addu	$a3,$t5,$t3
/*  f16bb10:	0fc55125 */ 	jal	func0f153780
/*  f16bb14:	00402025 */ 	move	$a0,$v0
/*  f16bb18:	00409825 */ 	move	$s3,$v0
.PF0f16bb1c:
/*  f16bb1c:	0fc619de */ 	jal	func0f185774
/*  f16bb20:	02602025 */ 	move	$a0,$s3
/*  f16bb24:	0fc5a557 */ 	jal	lvRenderFade
/*  f16bb28:	00402025 */ 	move	$a0,$v0
/*  f16bb2c:	3c0f8009 */ 	lui	$t7,0x8009
/*  f16bb30:	91ef8d54 */ 	lbu	$t7,-0x72ac($t7)
/*  f16bb34:	00409825 */ 	move	$s3,$v0
/*  f16bb38:	11e00004 */ 	beqz	$t7,.PF0f16bb4c
/*  f16bb3c:	00000000 */ 	nop
/*  f16bb40:	0fc69012 */ 	jal	frRenderHud
/*  f16bb44:	00402025 */ 	move	$a0,$v0
/*  f16bb48:	00409825 */ 	move	$s3,$v0
.PF0f16bb4c:
/*  f16bb4c:	0fc47e62 */ 	jal	debug0f11ee88
/*  f16bb50:	00000000 */ 	nop
/*  f16bb54:	14400013 */ 	bnez	$v0,.PF0f16bba4
/*  f16bb58:	00000000 */ 	nop
/*  f16bb5c:	0fc47e64 */ 	jal	debug0f11ee90
/*  f16bb60:	00000000 */ 	nop
/*  f16bb64:	1440000f */ 	bnez	$v0,.PF0f16bba4
/*  f16bb68:	00000000 */ 	nop
/*  f16bb6c:	0fc47e6a */ 	jal	debug0f11eea8
/*  f16bb70:	00000000 */ 	nop
/*  f16bb74:	1440000b */ 	bnez	$v0,.PF0f16bba4
/*  f16bb78:	00000000 */ 	nop
/*  f16bb7c:	0fc47ea0 */ 	jal	debug0f11ef80
/*  f16bb80:	00000000 */ 	nop
/*  f16bb84:	14400007 */ 	bnez	$v0,.PF0f16bba4
/*  f16bb88:	00000000 */ 	nop
/*  f16bb8c:	0fc47e9e */ 	jal	debug0f11ef78
/*  f16bb90:	00000000 */ 	nop
/*  f16bb94:	14400003 */ 	bnez	$v0,.PF0f16bba4
/*  f16bb98:	00000000 */ 	nop
/*  f16bb9c:	0fc47e50 */ 	jal	debug0f11ee40
/*  f16bba0:	00000000 */ 	nop
.PF0f16bba4:
/*  f16bba4:	0fc49fea */ 	jal	func0f1274d8
/*  f16bba8:	02602025 */ 	move	$a0,$s3
/*  f16bbac:	0fc40494 */ 	jal	amRender
/*  f16bbb0:	00402025 */ 	move	$a0,$v0
/*  f16bbb4:	3c013f80 */ 	lui	$at,0x3f80
/*  f16bbb8:	44816000 */ 	mtc1	$at,$f12
/*  f16bbbc:	0c005936 */ 	jal	func00016748
/*  f16bbc0:	00409825 */ 	move	$s3,$v0
/*  f16bbc4:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16bbc8:	8d581c50 */ 	lw	$t8,0x1c50($t2)
/*  f16bbcc:	00186fc2 */ 	srl	$t5,$t8,0x1f
/*  f16bbd0:	51a00005 */ 	beqzl	$t5,.PF0f16bbe8
/*  f16bbd4:	8e4b0288 */ 	lw	$t3,0x288($s2)
/*  f16bbd8:	0fc3f0f0 */ 	jal	func0f0fbc30
/*  f16bbdc:	02602025 */ 	move	$a0,$s3
/*  f16bbe0:	00409825 */ 	move	$s3,$v0
/*  f16bbe4:	8e4b0288 */ 	lw	$t3,0x288($s2)
.PF0f16bbe8:
/*  f16bbe8:	0c005936 */ 	jal	func00016748
/*  f16bbec:	c56c0074 */ 	lwc1	$f12,0x74($t3)
/*  f16bbf0:	8e4c0314 */ 	lw	$t4,0x314($s2)
/*  f16bbf4:	51800005 */ 	beqzl	$t4,.PF0f16bc0c
/*  f16bbf8:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f16bbfc:	0fc629f8 */ 	jal	mpRenderModalText
/*  f16bc00:	02602025 */ 	move	$a0,$s3
/*  f16bc04:	00409825 */ 	move	$s3,$v0
/*  f16bc08:	8e590284 */ 	lw	$t9,0x284($s2)
.PF0f16bc0c:
/*  f16bc0c:	932e19b3 */ 	lbu	$t6,0x19b3($t9)
/*  f16bc10:	11c00003 */ 	beqz	$t6,.PF0f16bc20
/*  f16bc14:	00000000 */ 	nop
/*  f16bc18:	0fc2ddff */ 	jal	currentPlayerStartNewLife
/*  f16bc1c:	00000000 */ 	nop
.PF0f16bc20:
/*  f16bc20:	0fc4f42f */ 	jal	func0f13c54c
/*  f16bc24:	00000000 */ 	nop
/*  f16bc28:	8e4f0298 */ 	lw	$t7,0x298($s2)
/*  f16bc2c:	05e10004 */ 	bgez	$t7,.PF0f16bc40
/*  f16bc30:	00000000 */ 	nop
/*  f16bc34:	8e4a029c */ 	lw	$t2,0x29c($s2)
/*  f16bc38:	0542000a */ 	bltzl	$t2,.PF0f16bc64
/*  f16bc3c:	8fb00064 */ 	lw	$s0,0x64($sp)
.PF0f16bc40:
/*  f16bc40:	0fc2f28f */ 	jal	func0f0bc4c0
/*  f16bc44:	00000000 */ 	nop
/*  f16bc48:	50400006 */ 	beqzl	$v0,.PF0f16bc64
/*  f16bc4c:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f16bc50:	8e58028c */ 	lw	$t8,0x28c($s2)
/*  f16bc54:	53000003 */ 	beqzl	$t8,.PF0f16bc64
/*  f16bc58:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f16bc5c:	8fb30108 */ 	lw	$s3,0x108($sp)
/*  f16bc60:	8fb00064 */ 	lw	$s0,0x64($sp)
.PF0f16bc64:
/*  f16bc64:	8fad010c */ 	lw	$t5,0x10c($sp)
/*  f16bc68:	560dfb58 */ 	bnel	$s0,$t5,.PF0f16a9cc
/*  f16bc6c:	8fac0104 */ 	lw	$t4,0x104($sp)
.PF0f16bc70:
/*  f16bc70:	824b04d3 */ 	lb	$t3,0x4d3($s2)
.PF0f16bc74:
/*  f16bc74:	3c014080 */ 	lui	$at,0x4080
/*  f16bc78:	4481a000 */ 	mtc1	$at,$f20
/*  f16bc7c:	11600013 */ 	beqz	$t3,.PF0f16bccc
/*  f16bc80:	2417ffff */ 	li	$s7,-1
/*  f16bc84:	824c04d6 */ 	lb	$t4,0x4d6($s2)
/*  f16bc88:	51800011 */ 	beqzl	$t4,.PF0f16bcd0
/*  f16bc8c:	824a04d3 */ 	lb	$t2,0x4d3($s2)
/*  f16bc90:	825904d7 */ 	lb	$t9,0x4d7($s2)
/*  f16bc94:	a24004d3 */ 	sb	$zero,0x4d3($s2)
/*  f16bc98:	a24004d6 */ 	sb	$zero,0x4d6($s2)
/*  f16bc9c:	53200004 */ 	beqzl	$t9,.PF0f16bcb0
/*  f16bca0:	824e04d4 */ 	lb	$t6,0x4d4($s2)
/*  f16bca4:	a25704d4 */ 	sb	$s7,0x4d4($s2)
/*  f16bca8:	a24004d5 */ 	sb	$zero,0x4d5($s2)
/*  f16bcac:	824e04d4 */ 	lb	$t6,0x4d4($s2)
.PF0f16bcb0:
/*  f16bcb0:	05c30007 */ 	bgezl	$t6,.PF0f16bcd0
/*  f16bcb4:	824a04d3 */ 	lb	$t2,0x4d3($s2)
/*  f16bcb8:	824f04d5 */ 	lb	$t7,0x4d5($s2)
/*  f16bcbc:	5de00004 */ 	bgtzl	$t7,.PF0f16bcd0
/*  f16bcc0:	824a04d3 */ 	lb	$t2,0x4d3($s2)
/*  f16bcc4:	0c0039af */ 	jal	mainSetStageNum
/*  f16bcc8:	2404005a */ 	li	$a0,0x5a
.PF0f16bccc:
/*  f16bccc:	824a04d3 */ 	lb	$t2,0x4d3($s2)
.PF0f16bcd0:
/*  f16bcd0:	55400044 */ 	bnezl	$t2,.PF0f16bde4
/*  f16bcd4:	02608825 */ 	move	$s1,$s3
/*  f16bcd8:	825804d4 */ 	lb	$t8,0x4d4($s2)
/*  f16bcdc:	07020041 */ 	bltzl	$t8,.PF0f16bde4
/*  f16bce0:	02608825 */ 	move	$s1,$s3
/*  f16bce4:	824d04d5 */ 	lb	$t5,0x4d5($s2)
/*  f16bce8:	59a0003e */ 	blezl	$t5,.PF0f16bde4
/*  f16bcec:	02608825 */ 	move	$s1,$s3
/*  f16bcf0:	0fc37925 */ 	jal	hudmsgRemoveAll
/*  f16bcf4:	00000000 */ 	nop
/*  f16bcf8:	824b04d4 */ 	lb	$t3,0x4d4($s2)
/*  f16bcfc:	3c118007 */ 	lui	$s1,0x8007
/*  f16bd00:	26313abc */ 	addiu	$s1,$s1,0x3abc
/*  f16bd04:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f16bd08:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f16bd0c:	3c10800a */ 	lui	$s0,0x800a
/*  f16bd10:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f16bd14:	2610e588 */ 	addiu	$s0,$s0,-6776
/*  f16bd18:	022cc821 */ 	addu	$t9,$s1,$t4
/*  f16bd1c:	8f2e0004 */ 	lw	$t6,0x4($t9)
/*  f16bd20:	920f0003 */ 	lbu	$t7,0x3($s0)
/*  f16bd24:	ae400314 */ 	sw	$zero,0x314($s2)
/*  f16bd28:	ae400318 */ 	sw	$zero,0x318($s2)
/*  f16bd2c:	31f8ff7f */ 	andi	$t8,$t7,0xff7f
/*  f16bd30:	a2180003 */ 	sb	$t8,0x3($s0)
/*  f16bd34:	330d00bf */ 	andi	$t5,$t8,0xbf
/*  f16bd38:	ae400294 */ 	sw	$zero,0x294($s2)
/*  f16bd3c:	ae570298 */ 	sw	$s7,0x298($s2)
/*  f16bd40:	ae57029c */ 	sw	$s7,0x29c($s2)
/*  f16bd44:	a20d0003 */ 	sb	$t5,0x3($s0)
/*  f16bd48:	24040001 */ 	li	$a0,0x1
/*  f16bd4c:	0fc0690e */ 	jal	setNumPlayers
/*  f16bd50:	a24e04d2 */ 	sb	$t6,0x4d2($s2)
/*  f16bd54:	0fc06a32 */ 	jal	titleSetNextMode
/*  f16bd58:	24040005 */ 	li	$a0,0x5
/*  f16bd5c:	920b0000 */ 	lbu	$t3,0x0($s0)
/*  f16bd60:	00002025 */ 	move	$a0,$zero
/*  f16bd64:	316cff01 */ 	andi	$t4,$t3,0xff01
/*  f16bd68:	0fc5b6fd */ 	jal	lvSetDifficulty
/*  f16bd6c:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f16bd70:	825904d4 */ 	lb	$t9,0x4d4($s2)
/*  f16bd74:	00197080 */ 	sll	$t6,$t9,0x2
/*  f16bd78:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f16bd7c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f16bd80:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f16bd84:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f16bd88:	84440000 */ 	lh	$a0,0x0($v0)
/*  f16bd8c:	a20f0002 */ 	sb	$t7,0x2($s0)
/*  f16bd90:	0fc06c91 */ 	jal	titleSetNextStage
/*  f16bd94:	a2040001 */ 	sb	$a0,0x1($s0)
/*  f16bd98:	824a04d4 */ 	lb	$t2,0x4d4($s2)
/*  f16bd9c:	000ac080 */ 	sll	$t8,$t2,0x2
/*  f16bda0:	030ac023 */ 	subu	$t8,$t8,$t2
/*  f16bda4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f16bda8:	02386821 */ 	addu	$t5,$s1,$t8
/*  f16bdac:	0c0039af */ 	jal	mainSetStageNum
/*  f16bdb0:	85a40000 */ 	lh	$a0,0x0($t5)
/*  f16bdb4:	824b04d5 */ 	lb	$t3,0x4d5($s2)
/*  f16bdb8:	256cffff */ 	addiu	$t4,$t3,-1
/*  f16bdbc:	a24c04d5 */ 	sb	$t4,0x4d5($s2)
/*  f16bdc0:	825904d5 */ 	lb	$t9,0x4d5($s2)
/*  f16bdc4:	5b200006 */ 	blezl	$t9,.PF0f16bde0
/*  f16bdc8:	a25704d4 */ 	sb	$s7,0x4d4($s2)
/*  f16bdcc:	824e04d4 */ 	lb	$t6,0x4d4($s2)
/*  f16bdd0:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f16bdd4:	10000002 */ 	b	.PF0f16bde0
/*  f16bdd8:	a24f04d4 */ 	sb	$t7,0x4d4($s2)
/*  f16bddc:	a25704d4 */ 	sb	$s7,0x4d4($s2)
.PF0f16bde0:
/*  f16bde0:	02608825 */ 	move	$s1,$s3
.PF0f16bde4:
/*  f16bde4:	3c0aed00 */ 	lui	$t2,0xed00
/*  f16bde8:	ae2a0000 */ 	sw	$t2,0x0($s1)
/*  f16bdec:	0c002e53 */ 	jal	viGetWidth
/*  f16bdf0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16bdf4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16bdf8:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f16bdfc:	0c002e57 */ 	jal	viGetHeight
/*  f16be00:	03008025 */ 	move	$s0,$t8
/*  f16be04:	44823000 */ 	mtc1	$v0,$f6
/*  f16be08:	44909000 */ 	mtc1	$s0,$f18
/*  f16be0c:	02601025 */ 	move	$v0,$s3
/*  f16be10:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f16be14:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f16be18:	46144402 */ 	mul.s	$f16,$f8,$f20
/*  f16be1c:	00000000 */ 	nop
/*  f16be20:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f16be24:	4600828d */ 	trunc.w.s	$f10,$f16
/*  f16be28:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f16be2c:	440b5000 */ 	mfc1	$t3,$f10
/*  f16be30:	440e4000 */ 	mfc1	$t6,$f8
/*  f16be34:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f16be38:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f16be3c:	000f5300 */ 	sll	$t2,$t7,0xc
/*  f16be40:	018ac025 */ 	or	$t8,$t4,$t2
/*  f16be44:	ae380004 */ 	sw	$t8,0x4($s1)
/*  f16be48:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f16be4c:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f16be50:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f16be54:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f16be58:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f16be5c:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f16be60:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f16be64:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f16be68:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f16be6c:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f16be70:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f16be74:	03e00008 */ 	jr	$ra
/*  f16be78:	27bd0170 */ 	addiu	$sp,$sp,0x170
);
#elif VERSION >= VERSION_NTSC_1_0
/**
 * Renders a complete frame for all players, and also does some other game logic
 * that really doesn't belong here.
 *
 * This function is pretty big, so here's an overview of its structure:
 *
 * if (stage == STAGE_TITLE) {
 *     // title screen rendering
 * } else if (stage == STAGE_BOOTPAKMENU) {
 *     // boot pak menu rendering
 * } else if (stage == STAGE_4MBMENU) {
 *     // 4MB menu rendering
 * } else if (stage == STAGE_CREDITS) {
 *     // credits rendering
 * } else {
 *     for (i = 0; i < numplayers; i++) {
 *         // rendering and logic per player
 *     }
 * }
 * // logic for auto-playing cutscene advancement
 *
 * The player loop takes up the majority of the function. In addition to
 * rendering the scene and HUD, it also handles the following logic:
 * - decreasing dizziness
 * - detecting if the prop being looked at is still valid
 * - pressing Z when using eyespy
 * - opening doors and reloading
 * - random static in the Infiltration intro cutscene
 * - combat boost activation and reverting
 */
Gfx *lvRender(Gfx *gdl)
{
	gSPSegment(gdl++, 0x00, 0x00000000);

	func0f0d5a7c();

	if (g_Vars.stagenum == STAGE_TITLE
			|| (g_Vars.stagenum == STAGE_TEST_OLD && titleIsKeepingMode())) {
		gSPDisplayList(gdl++, &var800613a0);

		if (debug0f11ee28()) {
			gSPDisplayList(gdl++, &var80061360);
		} else {
			gSPDisplayList(gdl++, &var80061380);
		}

		gdl = func0000b280(gdl);
		gdl = func0000b1d0(gdl);

		gDPSetScissorFrac(gdl++, 0,
				viGetViewLeft() * 4.0f, viGetViewTop() * 4.0f,
				(viGetViewLeft() + viGetViewWidth()) * 4.0f,
				(viGetViewTop() + viGetViewHeight()) * 4.0f);

		gdl = titleRender(gdl);
		gdl = lvRenderFade(gdl);
	} else if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		setCurrentPlayerNum(0);
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
		func00016748(1);

		gdl = func0000b1d0(gdl);
		gdl = func0000b330(gdl);
		gdl = currentPlayerScissorToViewport(gdl);
		gdl = func0f0fbc30(gdl);
	} else if (g_Vars.stagenum == STAGE_4MBMENU) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		setCurrentPlayerNum(0);
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
		func00016748(1);

		gdl = func0000b1d0(gdl);
		gdl = currentPlayerScissorToViewport(gdl);
		gdl = func0f0fbc30(gdl);

		if (g_Vars.currentplayer->pausemode != PAUSEMODE_UNPAUSED) {
			currentPlayerTickPauseMenu();
		}
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		setCurrentPlayerNum(0);
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
		func00016748(1);

		gdl = func0000b1a8(gdl);
		gdl = func0000b1d0(gdl);
		gdl = func0000b330(gdl);
		gdl = creditsRender(gdl);
	} else {
		// Normal stages
		s32 i;
		s32 playercount;
		Gfx *savedgdl;
		bool forcesingleplayer = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
			&& func0f0bc4c0();
		struct player *player;
		struct chrdata *chr;

		playercount = forcesingleplayer ? 1 : PLAYERCOUNT();

		gSPClipRatio(gdl++, FRUSTRATIO_2);

		for (i = 0; i < playercount; i++) {
			bool islastplayer;
			u32 bluramount = 0;

			savedgdl = gdl;

			if (forcesingleplayer) {
				setCurrentPlayerNum(0);
				g_Vars.currentplayerindex = 0;
				islastplayer = true;
			} else {
				s32 nextplayernum = i + 1;
				setCurrentPlayerNum(getPlayerByOrderNum(i));
				islastplayer = playercount == nextplayernum;
			}

			// Calculate bluramount - this will be used later
			if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
				player = g_Vars.currentplayer;
				chr = player->prop->chr;

				if (chr->blurdrugamount > 0
						&& !g_Vars.currentplayer->invincible
						&& !g_Vars.currentplayer->training) {
					bluramount = (chr->blurdrugamount * 130) / 5000 + 100;

					if (bluramount > 230) {
						bluramount = 230;
					}

					if (chr->blurdrugamount > 5000) {
						chr->blurdrugamount = 5000;
					}

					chr->blurdrugamount -= g_Vars.lvupdate240_60 * (chr->blurnumtimesdied + 1);

					if (chr->blurdrugamount < 1) {
						chr->blurdrugamount = 0;
						chr->blurnumtimesdied = 0;
					}
				}
			}

			bviewSetBlur(bluramount);

			gSPDisplayList(gdl++, &var800613a0);

			if (debug0f11ee28()) {
				gSPDisplayList(gdl++, &var80061360);
			} else {
				gSPDisplayList(gdl++, &var80061380);
			}

			viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
			viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
					g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
			func00016748(g_Vars.currentplayerstats->scale_bg2gfx);
			func0f1657f8();
			func0f176298();
			gdl = func0000b280(gdl);
			gdl = func0000b1d0(gdl);
			gdl = currentPlayerScissorToViewport(gdl);
			func0f13c510();

			if ((g_Vars.stagenum != STAGE_CITRAINING || (var80087260 <= 0 && g_MenuData.root != MENUROOT_MPSETUP))
					&& g_Vars.lvframenum <= 5
					&& !g_Vars.normmplayerisrunning
					&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
				if (var80084050 < 6) {
					g_Vars.lockscreen = 1;
				}

				var80084050++;
			} else if (g_Vars.currentplayer->gunctrl.unk1583_06
					&& var80075d60 == 2
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY
					&& var8009dfc0 == 0) {
				g_Vars.currentplayer->gunctrl.unk1583_06 = bgun0f09eae4();
			}

			if (g_Vars.lockscreen) {
				gdl = bviewRenderMotionBlur(gdl, 0xffffffff, 255);
				g_Vars.lockscreen--;
			} else if (var8009dfc0) {
				gdl = func0000b330(gdl);
				gdl = currentPlayerScissorToViewport(gdl);
				func00016748(1);

				if (g_Vars.currentplayer->unk1c50_01) {
					gdl = func0f0fbc30(gdl);
				}
			} else {
				if (var80075d60 == 2) {
					gdl = currentPlayerUpdateShootRot(gdl);
				}

				gdl = func0000b330(gdl);
				gdl = func0f11f984(gdl);
				roomsTick();
				func0f004314();
				propsTick(islastplayer);
				scenarioCallback14(NULL);
				propsSort();
				autoaimTick();
				handsTickAttack();

				// Calculate lookingatprop
				if (PLAYERCOUNT() == 1
						|| g_Vars.coopplayernum >= 0
						|| g_Vars.antiplayernum >= 0
						|| (weaponHasFlag(bgunGetWeaponNum(HAND_RIGHT), WEAPONFLAG_AIMTRACK) && bmoveIsInSightAimMode())) {
					g_Vars.currentplayer->lookingatprop.prop = func0f061d54(HAND_RIGHT, 0, 0);

					if (g_Vars.currentplayer->lookingatprop.prop) {
						if (g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_CHR
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_PLAYER) {
							chr = g_Vars.currentplayer->lookingatprop.prop->chr;

							if (chr->hidden & CHRHFLAG_CLOAKED) {
								if (g_Vars.currentplayer->isdead
										|| g_InCutscene
										|| !EYESPYINACTIVE()
										|| (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_IRSCANNER) == false) {
									g_Vars.currentplayer->lookingatprop.prop = NULL;
								}
							}
						} else if (g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_OBJ
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_WEAPON
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_DOOR) {
							struct defaultobj *obj = g_Vars.currentplayer->lookingatprop.prop->obj;

							if ((obj->flags3 & OBJFLAG3_00008000) == 0) {
								if (g_Vars.stagenum != STAGE_CITRAINING
										|| (obj->modelnum != MODEL_TARGET
											&& obj->modelnum != MODEL_CIHUB
											&& obj->modelnum != MODEL_COMHUB)) {
									g_Vars.currentplayer->lookingatprop.prop = NULL;
								}
							}
						} else {
							g_Vars.currentplayer->lookingatprop.prop = NULL;
						}
					}
				} else {
					g_Vars.currentplayer->lookingatprop.prop = NULL;
				}

				if (gsetHasFunctionFlags(&g_Vars.currentplayer->hands[0].gset, FUNCFLAG_THREATDETECTOR)) {
					lvFindThreats();
				} else if (weaponHasFlag(bgunGetWeaponNum(HAND_RIGHT), WEAPONFLAG_AIMTRACK)) {
					s32 j;

					if (frIsInTraining()
							&& g_Vars.currentplayer->lookingatprop.prop
							&& bmoveIsInSightAimMode()) {
						func0f1a0924(g_Vars.currentplayer->lookingatprop.prop);
					} else if (lvCheckCmpFollowThreat(&g_Vars.currentplayer->lookingatprop, -1) == 0) {
						g_Vars.currentplayer->lookingatprop.prop = NULL;
					}

					for (j = 0; j < ARRAYCOUNT(g_Vars.currentplayer->cmpfollowprops); j++) {
						if (!lvCheckCmpFollowThreat(&g_Vars.currentplayer->cmpfollowprops[j], j)) {
							g_Vars.currentplayer->cmpfollowprops[j].x1 = -1;
							g_Vars.currentplayer->cmpfollowprops[j].x2 = -2;
						}
					}
				}

				// Handle eyespy Z presses
				if (g_Vars.currentplayer->eyespy
						&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)
						&& g_Vars.currentplayer->eyespy->camerabuttonheld) {
					if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
						objectiveCheckHolograph(400);
						sndStart(var80095200, SFX_CAMSPY_SHUTTER, 0, -1, -1, -1, -1, -1);
					} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
						if (g_Vars.currentplayer->eyespydarts) {
							// Fire dart
							struct coord direction;
							sndStart(var80095200, SFX_DRUGSPY_FIREDART, 0, -1, -1, -1, -1, -1);
							g_Vars.currentplayer->eyespydarts--;

							direction.x = g_Vars.currentplayer->eyespy->look.x;
							direction.y = g_Vars.currentplayer->eyespy->look.y;
							direction.z = g_Vars.currentplayer->eyespy->look.z;

							projectileCreate(g_Vars.currentplayer->eyespy->prop, 0,
									&g_Vars.currentplayer->eyespy->prop->pos, &direction, WEAPON_TRANQUILIZER, NULL);
						} else {
							// No dart ammo
							sndStart(var80095200, SFX_FIREEMPTY, 0, -1, -1, -1, -1, -1);
						}
					} else { // EYESPYMODE_BOMBSPY
						struct coord vel = {0, 0, 0};
						struct gset gset = {WEAPON_GRENADE, 0, 0, FUNC_PRIMARY};
						explosionCreateSimple(g_Vars.currentplayer->eyespy->prop,
								&g_Vars.currentplayer->eyespy->prop->pos,
								g_Vars.currentplayer->eyespy->prop->rooms,
								EXPLOSIONTYPE_23, 0);
						chrBeginDeath(g_Vars.currentplayer->eyespy->prop->chr, &vel, 0, 0, &gset, false, 0);
					}
				}

				// Handle opening doors and reloading
				if (g_Vars.currentplayer->bondactivateorreload) {
					if (currentPlayerInteract(false)) {
						bgunReloadIfPossible(HAND_RIGHT);
						bgunReloadIfPossible(HAND_LEFT);
					}
				} else if (g_Vars.currentplayer->eyespy
						&& g_Vars.currentplayer->eyespy->active
						&& g_Vars.currentplayer->eyespy->opendoor) {
					currentPlayerInteract(true);
				}

				func0f0641f4();
				gdl = bgRender(gdl);
				func0f028498(var80075d68 == 15 || var8005f020);
				gdl = propsRenderBeams(gdl);
				gdl = shardsRender(gdl);
				gdl = sparksRender(gdl);
				gdl = weatherRender(gdl);

				if (g_NbombsActive) {
					gdl = nbombsRender(gdl);
				}

				if (var80075d60 == 2) {
					gdl = currentPlayerRenderHud(gdl);
				} else {
					gdl = func0f0aeed8(gdl);

					if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
						gdl = func0f15b114(gdl);
					}
				}

				if (var80075d78 <= 0) {
					static struct audiohandle *g_CutsceneStaticAudioHandle = NULL;
					static s32 g_CutsceneStaticTimer = 100;
					static u8 g_CutsceneStaticActive = false;
					bool cutscenehasstatic = false;
					u32 alpha;

					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						// This chunk of code is unreachable
						// (STAGE_TEST_OLD is not used)
						if (g_Vars.stagenum == STAGE_TEST_OLD) {
							f32 frac = 0;
							u32 colour;
							s32 endframe = animGetNumFrames(g_CutsceneAnimNum) - 1;

							colour = 0;

							if (g_CutsceneCurAnimFrame60 < 90) {
								frac = 1.0f - (f32)g_CutsceneCurAnimFrame60 / 90.0f;
							}

							if (g_CutsceneAnimNum != ANIM_046C) {
								if (g_CutsceneCurAnimFrame60 > endframe - 90) {
									frac = (g_CutsceneCurAnimFrame60 - endframe + 90) / 90.0f;
								}
							} else {
								if (g_CutsceneCurAnimFrame60 > endframe - 30) {
									colour = 0xffffff00;
									frac = (g_CutsceneCurAnimFrame60 - endframe + 30) / 30.0f;
								}
							}

							if (frac > 0) {
								alpha = 255 * frac;

								gDPPipeSync(gdl++);
								gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
								gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
								gDPSetPrimColorViaWord(gdl++, 0, 0, colour | alpha);

								gDPFillRectangle(gdl++,
									viGetViewLeft(),
									viGetViewTop(),
									viGetViewLeft() + viGetViewWidth(),
									viGetViewTop() + viGetViewHeight());

								gdl = func0f153838(gdl);
							}
						}

						// Handle visual effects in cutscenes
						switch (g_CutsceneAnimNum) {
						case 0x1e5:
							// Horizon scanner in Air Base intro
							if (g_CutsceneCurAnimFrame60 > 839 && g_CutsceneCurAnimFrame60 < 1411) {
								gdl = bviewRenderHorizonScanner(gdl);
							}
							break;
						case 0x181:
						case 0x183:
						case 0x188:
							{
								// Show static randomly in Infiltration intro
								s32 cutscenestatic = 0;
								cutscenehasstatic = true;

								if (g_CutsceneStaticAudioHandle == NULL) {
									sndStart(var80095200, SFX_INFIL_STATIC_LONG, &g_CutsceneStaticAudioHandle, -1, -1, -1, -1, -1);
								}

								g_CutsceneStaticTimer -= g_Vars.diffframe60;

								if (g_CutsceneStaticTimer < 0) {
									g_CutsceneStaticTimer = random() % 200 + 40;
									g_CutsceneStaticActive = false;
								}

								gdl = bviewRenderFilmLens(gdl, 0xffffffff, 0xffffffff);

								if (g_CutsceneStaticTimer < 15) {
									if (g_CutsceneStaticActive == false) {
										g_CutsceneStaticActive = true;
										sndStart(var80095200, SFX_INFIL_STATIC_MEDIUM, NULL, -1, -1, -1, -1, -1);
									}

									cutscenestatic = 225 - g_CutsceneStaticTimer * 10;
								}

								// Consider a single frame of static, separate
								// to the main static above
								if (random() % 60 == 1) {
									cutscenestatic = 255;
									sndStart(var80095200, SFX_INFIL_STATIC_SHORT, NULL, -1, -1, -1, -1, -1);
								}

								if (cutscenestatic) {
									gdl = bviewRenderStatic(gdl, 0xffffffff, cutscenestatic);
								}
							}
							break;
						}
					}

					if (g_CutsceneStaticAudioHandle && !cutscenehasstatic) {
						audioStop(g_CutsceneStaticAudioHandle);
					}

					// Slayer rocket shows static when flying out of bounds
					if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKET
							&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
						gdl = bviewRenderSlayerRocketLens(gdl, 0xffffffff, 0xffffffff);

						if (g_Vars.currentplayer->badrockettime > 0) {
							u32 slayerstatic = g_Vars.currentplayer->badrockettime * 255 / 90;

							if (slayerstatic > 255) {
								slayerstatic = 255;
							}

							gdl = bviewRenderStatic(gdl, 0x4fffffff, slayerstatic);
						}
					}

					if (g_Vars.currentplayer->visionmode == VISIONMODE_3) {
						gdl = bviewRenderStatic(gdl, 0x4fffffff, 255);
						g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
					}

					if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY
							&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
						s32 xraything = 99;

						if (g_Vars.currentplayer->erasertime < 200) {
							xraything = 249 - (g_Vars.currentplayer->erasertime * 3 >> 2);
						}

						gdl = bviewRenderZoomBlur(gdl, 0xffffffff, xraything, 1.05f, 1.05f);
					}

					// Handle combat boosts
					if ((g_Vars.speedpillchange > 0 && g_Vars.speedpillchange < 30)
							|| (g_Vars.speedpillwant && !g_Vars.speedpillon)
							|| (!g_Vars.speedpillwant && g_Vars.speedpillon)) {
						if (g_Vars.speedpillchange == 30 && !g_Vars.speedpillwant) {
							sndStart(var80095200, lvGetSlowMotionType() ? SFX_JO_BOOST_ACTIVATE : SFX_ARGH_JO_02AD, 0, -1, -1, -1, -1, -1);
						}

						if (g_Vars.speedpillchange < 15) {
							gdl = bviewRenderZoomBlur(gdl, 0xffffffff,
									g_Vars.speedpillchange * 180 / 15,
									(f32)g_Vars.speedpillchange * 0.02000000141561f + 1.1f,
									(f32)g_Vars.speedpillchange * 0.02000000141561f + 1.1f);
							gdl = fadeDraw(gdl, 0xff, 0xff, 0xff,
									g_Vars.speedpillchange * 0.0066666668280959f);
						} else {
							gdl = bviewRenderZoomBlur(gdl, 0xffffffff,
									(30 - g_Vars.speedpillchange) * 180 / 15,
									(f32)(30 - g_Vars.speedpillchange) * 0.02000000141561f + 1.1f,
									(f32)(30 - g_Vars.speedpillchange) * 0.02000000141561f + 1.1f);
							gdl = fadeDraw(gdl, 0xff, 0xff, 0xff,
									(30.0f - g_Vars.speedpillchange) * 0.0066666668280959f);
						}

						if (g_Vars.currentplayernum == 0) {
							if (g_Vars.speedpillwant) {
								g_Vars.speedpillchange++;
							} else {
								g_Vars.speedpillchange--;
							}
						}

						if (g_Vars.speedpillchange > 30) {
							g_Vars.speedpillchange = 30;
						} else if (g_Vars.speedpillchange < 0) {
							g_Vars.speedpillchange = 0;
						}
					}

					if (g_Vars.speedpillchange > 15) {
						g_Vars.speedpillon = true;
					} else {
						g_Vars.speedpillon = false;
					}

					if (bluramount) {
						// empty
					}

					if (bluramount) {
						bviewClearBlur();
						gdl = bviewRenderMotionBlur(gdl, 0xffffffff, bluramount);
					}

					// Handle blur effect in cutscenes (Extraction intro?)
					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						f32 cutsceneblurfrac = cutsceneGetBlurFrac();

						if (cutsceneblurfrac > 0) {
							u32 bluramount = cutsceneblurfrac * 255;
							gdl = bviewRenderMotionBlur(gdl, 0xffffff00, bluramount);
						}
					}

					if (debugGetMotionBlur() == 1) {
						gdl = bviewRenderMotionBlur(gdl, 0xffffff00, 128);
					} else if (debugGetMotionBlur() == 2) {
						gdl = bviewRenderMotionBlur(gdl, 0xffffff00, 192);
					} else if (debugGetMotionBlur() == 3) {
						gdl = bviewRenderMotionBlur(gdl, 0xffffff00, 230);
					}

					if (bluramount) {
						// empty
					}

					// Render white when teleporting
					if (g_Vars.currentplayer->teleportstate > TELEPORTSTATE_INACTIVE) {
						alpha = 0;

						if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_WHITE) {
							alpha = 255;
						}

						if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_EXITING
								&& g_Vars.currentplayer->teleporttime < 16) {
							alpha = -g_Vars.currentplayer->teleporttime * 16 + 240;
						}

						if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_ENTERING) {
							if (g_Vars.currentplayer->teleporttime > 32) {
								alpha = g_Vars.currentplayer->teleporttime * 16 - 512;
							}

							if (g_Vars.currentplayer->teleporttime == 48) {
								alpha = 255;
							}
						}

						if (alpha) {
							gdl = func0f153628(gdl);
							gdl = func0f153a34(gdl,
									viGetViewLeft(), viGetViewTop(),
									viGetViewLeft() + viGetViewWidth(),
									viGetViewTop() + viGetViewHeight(), 0xffffff00 | alpha);
							gdl = func0f153780(gdl);
						}
					}
				}

				gdl = func0f185774(gdl);
				gdl = lvRenderFade(gdl);

				if (g_FrIsValidWeapon) {
					gdl = frRenderHud(gdl);
				}

				if (debug0f11ee88() == 0
						&& debug0f11ee90() == 0
						&& debug0f11eea8() == 0
						&& debug0f11ef80() == 0
						&& debug0f11ef78() == 0) {
					debug0f11ee40();
				}

				gdl = func0f1274d8(gdl);
				gdl = amRender(gdl);
				func00016748(1);

				if (g_Vars.currentplayer->unk1c50_01) {
					gdl = func0f0fbc30(gdl);
				}

				func00016748(g_Vars.currentplayerstats->scale_bg2gfx);

				if (g_Vars.mplayerisrunning) {
					gdl = mpRenderModalText(gdl);
				}

				if (g_Vars.currentplayer->dostartnewlife) {
					currentPlayerStartNewLife();
				}
			}

			func0f13c54c();

			if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
					&& func0f0bc4c0()
					&& g_Vars.currentplayernum != 0) {
				gdl = savedgdl;
			}
		} // end of player loop
	} // end of stage if-statements

	if (g_Vars.autocutplaying) {
		if (g_Vars.autocutfinished) {
			g_Vars.autocutplaying = false;
			g_Vars.autocutfinished = false;

			if (g_Vars.autocutgroupskip) {
				g_Vars.autocutgroupcur = -1;
				g_Vars.autocutgroupleft = 0;
			}

			if (g_Vars.autocutgroupcur < 0 && g_Vars.autocutgroupleft <= 0) {
				mainSetStageNum(STAGE_TITLE);
			}
		}
	}

	// Advance the cutscenes when autoplaying
	if (!g_Vars.autocutplaying && g_Vars.autocutgroupcur >= 0 && g_Vars.autocutgroupleft > 0) {
		hudmsgRemoveAll();
		g_Vars.autocutnum = g_Cutscenes[g_Vars.autocutgroupcur].scene;
		g_MissionConfig.iscoop = false;
		g_Vars.mplayerisrunning = false;
		g_Vars.normmplayerisrunning = false;
		g_Vars.bondplayernum = 0;
		g_Vars.coopplayernum = -1;
		g_Vars.antiplayernum = -1;
		g_MissionConfig.isanti = false;
		setNumPlayers(1);
		titleSetNextMode(TITLEMODE_SKIP);
		g_MissionConfig.difficulty = DIFF_A;
		lvSetDifficulty(DIFF_A);
		g_MissionConfig.stageindex = g_Cutscenes[g_Vars.autocutgroupcur].mission;
		g_MissionConfig.stagenum = g_Cutscenes[g_Vars.autocutgroupcur].stage;
		titleSetNextStage(g_Cutscenes[g_Vars.autocutgroupcur].stage);
		mainSetStageNum(g_Cutscenes[g_Vars.autocutgroupcur].stage);

		g_Vars.autocutgroupleft--;

		if (g_Vars.autocutgroupleft > 0) {
			g_Vars.autocutgroupcur++;
		} else {
			g_Vars.autocutgroupcur = -1;
		}
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetWidth(), viGetHeight());

	return gdl;
}
#else
GLOBAL_ASM(
glabel lvRender
.late_rodata
glabel var7f1b1fbcnb
.word 0x3f866666
glabel var7f1b1fc0nb
.word 0x3ca3d70b
glabel var7f1b1fc4nb
.word 0x3f8ccccd
glabel var7f1b1fc8nb
.word 0x3bda740e
glabel var7f1b1fccnb
.word 0x3ca3d70b
glabel var7f1b1fd0nb
.word 0x3f8ccccd
glabel var7f1b1fd4nb
.word 0x3bda740e
.text
/*  f164048:	27bdfe10 */ 	addiu	$sp,$sp,-496
/*  f16404c:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f164050:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f164054:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f164058:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f16405c:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f164060:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f164064:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f164068:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f16406c:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f164070:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f164074:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f164078:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16407c:	3c12800a */ 	lui	$s2,0x800a
/*  f164080:	35ce0006 */ 	ori	$t6,$t6,0x6
/*  f164084:	2652e6c0 */ 	addiu	$s2,$s2,-6464
/*  f164088:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f16408c:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f164090:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f164094:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f164098:	24930008 */ 	addiu	$s3,$a0,0x8
/*  f16409c:	10410006 */ 	beq	$v0,$at,.NB0f1640b8
/*  f1640a0:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f1640a4:	54410060 */ 	bnel	$v0,$at,.NB0f164228
/*  f1640a8:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f1640ac:	0fc06a36 */ 	jal	titleIsKeepingMode
/*  f1640b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1640b4:	1040005b */ 	beqz	$v0,.NB0f164224
.NB0f1640b8:
/*  f1640b8:	02601025 */ 	or	$v0,$s3,$zero
/*  f1640bc:	3c188006 */ 	lui	$t8,0x8006
/*  f1640c0:	271838b0 */ 	addiu	$t8,$t8,0x38b0
/*  f1640c4:	3c0f0600 */ 	lui	$t7,0x600
/*  f1640c8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f1640cc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1640d0:	0fc4666a */ 	jal	debug0f11ee28
/*  f1640d4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1640d8:	10400008 */ 	beqz	$v0,.NB0f1640fc
/*  f1640dc:	02601025 */ 	or	$v0,$s3,$zero
/*  f1640e0:	3c0a8006 */ 	lui	$t2,0x8006
/*  f1640e4:	254a3870 */ 	addiu	$t2,$t2,0x3870
/*  f1640e8:	3c190600 */ 	lui	$t9,0x600
/*  f1640ec:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1640f0:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f1640f4:	10000008 */ 	beqz	$zero,.NB0f164118
/*  f1640f8:	26730008 */ 	addiu	$s3,$s3,0x8
.NB0f1640fc:
/*  f1640fc:	02601025 */ 	or	$v0,$s3,$zero
/*  f164100:	3c0c8006 */ 	lui	$t4,0x8006
/*  f164104:	258c3890 */ 	addiu	$t4,$t4,0x3890
/*  f164108:	3c0b0600 */ 	lui	$t3,0x600
/*  f16410c:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f164110:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f164114:	26730008 */ 	addiu	$s3,$s3,0x8
.NB0f164118:
/*  f164118:	0c002d00 */ 	jal	func0000b280
/*  f16411c:	02602025 */ 	or	$a0,$s3,$zero
/*  f164120:	0c002cd4 */ 	jal	func0000b1d0
/*  f164124:	00402025 */ 	or	$a0,$v0,$zero
/*  f164128:	0040a025 */ 	or	$s4,$v0,$zero
/*  f16412c:	0c002fb5 */ 	jal	viGetViewLeft
/*  f164130:	24530008 */ 	addiu	$s3,$v0,0x8
/*  f164134:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f164138:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f16413c:	0c002fb9 */ 	jal	viGetViewTop
/*  f164140:	01a08825 */ 	or	$s1,$t5,$zero
/*  f164144:	44822000 */ 	mtc1	$v0,$f4
/*  f164148:	44918000 */ 	mtc1	$s1,$f16
/*  f16414c:	3c014080 */ 	lui	$at,0x4080
/*  f164150:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f164154:	4481a000 */ 	mtc1	$at,$f20
/*  f164158:	3c01ed00 */ 	lui	$at,0xed00
/*  f16415c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f164160:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f164164:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164168:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f16416c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f164170:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f164174:	440f5000 */ 	mfc1	$t7,$f10
/*  f164178:	440b3000 */ 	mfc1	$t3,$f6
/*  f16417c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f164180:	0301c825 */ 	or	$t9,$t8,$at
/*  f164184:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f164188:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f16418c:	032d7025 */ 	or	$t6,$t9,$t5
/*  f164190:	0c002f97 */ 	jal	viGetViewWidth
/*  f164194:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f164198:	0c002fb5 */ 	jal	viGetViewLeft
/*  f16419c:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f1641a0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1641a4:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f1641a8:	0c002fb9 */ 	jal	viGetViewTop
/*  f1641ac:	01e08025 */ 	or	$s0,$t7,$zero
/*  f1641b0:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f1641b4:	0011c403 */ 	sra	$t8,$s1,0x10
/*  f1641b8:	0c002f9b */ 	jal	viGetViewHeight
/*  f1641bc:	03008825 */ 	or	$s1,$t8,$zero
/*  f1641c0:	87ad008e */ 	lh	$t5,0x8e($sp)
/*  f1641c4:	00515021 */ 	addu	$t2,$v0,$s1
/*  f1641c8:	448a4000 */ 	mtc1	$t2,$f8
/*  f1641cc:	020d7021 */ 	addu	$t6,$s0,$t5
/*  f1641d0:	448e2000 */ 	mtc1	$t6,$f4
/*  f1641d4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1641d8:	02602025 */ 	or	$a0,$s3,$zero
/*  f1641dc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1641e0:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f1641e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1641e8:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f1641ec:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f1641f0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1641f4:	440c9000 */ 	mfc1	$t4,$f18
/*  f1641f8:	44185000 */ 	mfc1	$t8,$f10
/*  f1641fc:	31990fff */ 	andi	$t9,$t4,0xfff
/*  f164200:	330a0fff */ 	andi	$t2,$t8,0xfff
/*  f164204:	000a5b00 */ 	sll	$t3,$t2,0xc
/*  f164208:	032b6025 */ 	or	$t4,$t9,$t3
/*  f16420c:	0fc06b08 */ 	jal	titleRender
/*  f164210:	ae8c0004 */ 	sw	$t4,0x4($s4)
/*  f164214:	0fc58ba8 */ 	jal	lvRenderFade
/*  f164218:	00402025 */ 	or	$a0,$v0,$zero
/*  f16421c:	1000069c */ 	beqz	$zero,.NB0f165c90
/*  f164220:	00409825 */ 	or	$s3,$v0,$zero
.NB0f164224:
/*  f164224:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
.NB0f164228:
/*  f164228:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f16422c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f164230:	14410040 */ 	bne	$v0,$at,.NB0f164334
/*  f164234:	3408fffe */ 	dli	$t0,0xfffe
/*  f164238:	02601025 */ 	or	$v0,$s3,$zero
/*  f16423c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164240:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f164244:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f164248:	02601825 */ 	or	$v1,$s3,$zero
/*  f16424c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164250:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f164254:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f164258:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16425c:	35ce0c04 */ 	ori	$t6,$t6,0xc04
/*  f164260:	02602025 */ 	or	$a0,$s3,$zero
/*  f164264:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f164268:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16426c:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f164270:	35ef1404 */ 	ori	$t7,$t7,0x1404
/*  f164274:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164278:	02602825 */ 	or	$a1,$s3,$zero
/*  f16427c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f164280:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f164284:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164288:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f16428c:	37181c04 */ 	ori	$t8,$t8,0x1c04
/*  f164290:	02603025 */ 	or	$a2,$s3,$zero
/*  f164294:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f164298:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f16429c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1642a0:	3c0a8006 */ 	lui	$t2,0x8006
/*  f1642a4:	3c090600 */ 	lui	$t1,0x600
/*  f1642a8:	254a38b0 */ 	addiu	$t2,$t2,0x38b0
/*  f1642ac:	02601025 */ 	or	$v0,$s3,$zero
/*  f1642b0:	3c198006 */ 	lui	$t9,0x8006
/*  f1642b4:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f1642b8:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1642bc:	27393890 */ 	addiu	$t9,$t9,0x3890
/*  f1642c0:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f1642c4:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1642c8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1642cc:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f1642d0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1642d4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1642d8:	86040634 */ 	lh	$a0,0x634($s0)
/*  f1642dc:	0c002f9f */ 	jal	viSetViewPosition
/*  f1642e0:	86050636 */ 	lh	$a1,0x636($s0)
/*  f1642e4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1642e8:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f1642ec:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f1642f0:	86060630 */ 	lh	$a2,0x630($s0)
/*  f1642f4:	0c002feb */ 	jal	viSetFovAspectAndSize
/*  f1642f8:	86070632 */ 	lh	$a3,0x632($s0)
/*  f1642fc:	3c013f80 */ 	lui	$at,0x3f80
/*  f164300:	44816000 */ 	mtc1	$at,$f12
/*  f164304:	0c005db6 */ 	jal	func00016748
/*  f164308:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16430c:	0c002cd4 */ 	jal	func0000b1d0
/*  f164310:	02602025 */ 	or	$a0,$s3,$zero
/*  f164314:	0c002d2c */ 	jal	func0000b330
/*  f164318:	00402025 */ 	or	$a0,$v0,$zero
/*  f16431c:	0fc55c96 */ 	jal	currentPlayerScissorToViewport
/*  f164320:	00402025 */ 	or	$a0,$v0,$zero
/*  f164324:	0fc3e0e0 */ 	jal	func0f0fbc30
/*  f164328:	00402025 */ 	or	$a0,$v0,$zero
/*  f16432c:	10000658 */ 	beqz	$zero,.NB0f165c90
/*  f164330:	00409825 */ 	or	$s3,$v0,$zero
.NB0f164334:
/*  f164334:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f164338:	14410046 */ 	bne	$v0,$at,.NB0f164454
/*  f16433c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f164340:	02601025 */ 	or	$v0,$s3,$zero
/*  f164344:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164348:	3c0bbc00 */ 	lui	$t3,0xbc00
/*  f16434c:	356b0404 */ 	ori	$t3,$t3,0x404
/*  f164350:	02601825 */ 	or	$v1,$s3,$zero
/*  f164354:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164358:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f16435c:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f164360:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f164364:	358c0c04 */ 	ori	$t4,$t4,0xc04
/*  f164368:	02602025 */ 	or	$a0,$s3,$zero
/*  f16436c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f164370:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f164374:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f164378:	3408fffe */ 	dli	$t0,0xfffe
/*  f16437c:	35ad1404 */ 	ori	$t5,$t5,0x1404
/*  f164380:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164384:	02602825 */ 	or	$a1,$s3,$zero
/*  f164388:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f16438c:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f164390:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164394:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f164398:	35ce1c04 */ 	ori	$t6,$t6,0x1c04
/*  f16439c:	02603025 */ 	or	$a2,$s3,$zero
/*  f1643a0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1643a4:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f1643a8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1643ac:	3c0f8006 */ 	lui	$t7,0x8006
/*  f1643b0:	3c090600 */ 	lui	$t1,0x600
/*  f1643b4:	25ef38b0 */ 	addiu	$t7,$t7,0x38b0
/*  f1643b8:	02601025 */ 	or	$v0,$s3,$zero
/*  f1643bc:	3c188006 */ 	lui	$t8,0x8006
/*  f1643c0:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f1643c4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1643c8:	27183890 */ 	addiu	$t8,$t8,0x3890
/*  f1643cc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1643d0:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1643d4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1643d8:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f1643dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1643e0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1643e4:	86040634 */ 	lh	$a0,0x634($s0)
/*  f1643e8:	0c002f9f */ 	jal	viSetViewPosition
/*  f1643ec:	86050636 */ 	lh	$a1,0x636($s0)
/*  f1643f0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1643f4:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f1643f8:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f1643fc:	86060630 */ 	lh	$a2,0x630($s0)
/*  f164400:	0c002feb */ 	jal	viSetFovAspectAndSize
/*  f164404:	86070632 */ 	lh	$a3,0x632($s0)
/*  f164408:	3c013f80 */ 	lui	$at,0x3f80
/*  f16440c:	44816000 */ 	mtc1	$at,$f12
/*  f164410:	0c005db6 */ 	jal	func00016748
/*  f164414:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164418:	0c002cd4 */ 	jal	func0000b1d0
/*  f16441c:	02602025 */ 	or	$a0,$s3,$zero
/*  f164420:	0fc55c96 */ 	jal	currentPlayerScissorToViewport
/*  f164424:	00402025 */ 	or	$a0,$v0,$zero
/*  f164428:	0fc3e0e0 */ 	jal	func0f0fbc30
/*  f16442c:	00402025 */ 	or	$a0,$v0,$zero
/*  f164430:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f164434:	00409825 */ 	or	$s3,$v0,$zero
/*  f164438:	8d591a24 */ 	lw	$t9,0x1a24($t2)
/*  f16443c:	53200615 */ 	beqzl	$t9,.NB0f165c94
/*  f164440:	825904d3 */ 	lb	$t9,0x4d3($s2)
/*  f164444:	0fc2e290 */ 	jal	currentPlayerTickPauseMenu
/*  f164448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16444c:	10000611 */ 	beqz	$zero,.NB0f165c94
/*  f164450:	825904d3 */ 	lb	$t9,0x4d3($s2)
.NB0f164454:
/*  f164454:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f164458:	14410041 */ 	bne	$v0,$at,.NB0f164560
/*  f16445c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f164460:	02601025 */ 	or	$v0,$s3,$zero
/*  f164464:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164468:	3c0bbc00 */ 	lui	$t3,0xbc00
/*  f16446c:	356b0404 */ 	ori	$t3,$t3,0x404
/*  f164470:	02601825 */ 	or	$v1,$s3,$zero
/*  f164474:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164478:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f16447c:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f164480:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f164484:	358c0c04 */ 	ori	$t4,$t4,0xc04
/*  f164488:	02602025 */ 	or	$a0,$s3,$zero
/*  f16448c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f164490:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f164494:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f164498:	3408fffe */ 	dli	$t0,0xfffe
/*  f16449c:	35ad1404 */ 	ori	$t5,$t5,0x1404
/*  f1644a0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1644a4:	02602825 */ 	or	$a1,$s3,$zero
/*  f1644a8:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f1644ac:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f1644b0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1644b4:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f1644b8:	35ce1c04 */ 	ori	$t6,$t6,0x1c04
/*  f1644bc:	02603025 */ 	or	$a2,$s3,$zero
/*  f1644c0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1644c4:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f1644c8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1644cc:	3c0f8006 */ 	lui	$t7,0x8006
/*  f1644d0:	3c090600 */ 	lui	$t1,0x600
/*  f1644d4:	25ef38b0 */ 	addiu	$t7,$t7,0x38b0
/*  f1644d8:	02601025 */ 	or	$v0,$s3,$zero
/*  f1644dc:	3c188006 */ 	lui	$t8,0x8006
/*  f1644e0:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f1644e4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1644e8:	27183890 */ 	addiu	$t8,$t8,0x3890
/*  f1644ec:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1644f0:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1644f4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1644f8:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f1644fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f164500:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164504:	86040634 */ 	lh	$a0,0x634($s0)
/*  f164508:	0c002f9f */ 	jal	viSetViewPosition
/*  f16450c:	86050636 */ 	lh	$a1,0x636($s0)
/*  f164510:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164514:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f164518:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16451c:	86060630 */ 	lh	$a2,0x630($s0)
/*  f164520:	0c002feb */ 	jal	viSetFovAspectAndSize
/*  f164524:	86070632 */ 	lh	$a3,0x632($s0)
/*  f164528:	3c013f80 */ 	lui	$at,0x3f80
/*  f16452c:	44816000 */ 	mtc1	$at,$f12
/*  f164530:	0c005db6 */ 	jal	func00016748
/*  f164534:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164538:	0c002cca */ 	jal	func0000b1a8
/*  f16453c:	02602025 */ 	or	$a0,$s3,$zero
/*  f164540:	0c002cd4 */ 	jal	func0000b1d0
/*  f164544:	00402025 */ 	or	$a0,$v0,$zero
/*  f164548:	0c002d2c */ 	jal	func0000b330
/*  f16454c:	00402025 */ 	or	$a0,$v0,$zero
/*  f164550:	0fc4d6d9 */ 	jal	creditsRender
/*  f164554:	00402025 */ 	or	$a0,$v0,$zero
/*  f164558:	100005cd */ 	beqz	$zero,.NB0f165c90
/*  f16455c:	00409825 */ 	or	$s3,$v0,$zero
.NB0f164560:
/*  f164560:	8e500298 */ 	lw	$s0,0x298($s2)
/*  f164564:	06010006 */ 	bgez	$s0,.NB0f164580
/*  f164568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16456c:	8e50029c */ 	lw	$s0,0x29c($s2)
/*  f164570:	2a190000 */ 	slti	$t9,$s0,0x0
/*  f164574:	3b300001 */ 	xori	$s0,$t9,0x1
/*  f164578:	1200000e */ 	beqz	$s0,.NB0f1645b4
/*  f16457c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f164580:
/*  f164580:	3c108007 */ 	lui	$s0,0x8007
/*  f164584:	8e102e24 */ 	lw	$s0,0x2e24($s0)
/*  f164588:	0010582b */ 	sltu	$t3,$zero,$s0
/*  f16458c:	11600005 */ 	beqz	$t3,.NB0f1645a4
/*  f164590:	3c108006 */ 	lui	$s0,0x8006
/*  f164594:	8e10f2f0 */ 	lw	$s0,-0xd10($s0)
/*  f164598:	2e0c0001 */ 	sltiu	$t4,$s0,0x1
/*  f16459c:	15800005 */ 	bnez	$t4,.NB0f1645b4
/*  f1645a0:	01808025 */ 	or	$s0,$t4,$zero
.NB0f1645a4:
/*  f1645a4:	0fc3e4d2 */ 	jal	menuGetRoot
/*  f1645a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1645ac:	38500009 */ 	xori	$s0,$v0,0x9
/*  f1645b0:	2e100001 */ 	sltiu	$s0,$s0,0x1
.NB0f1645b4:
/*  f1645b4:	12000004 */ 	beqz	$s0,.NB0f1645c8
/*  f1645b8:	afb00184 */ 	sw	$s0,0x184($sp)
/*  f1645bc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1645c0:	1000001c */ 	beqz	$zero,.NB0f164634
/*  f1645c4:	afad018c */ 	sw	$t5,0x18c($sp)
.NB0f1645c8:
/*  f1645c8:	8e4e006c */ 	lw	$t6,0x6c($s2)
/*  f1645cc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1645d0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1645d4:	11c00003 */ 	beqz	$t6,.NB0f1645e4
/*  f1645d8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1645dc:	10000001 */ 	beqz	$zero,.NB0f1645e4
/*  f1645e0:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f1645e4:
/*  f1645e4:	8e4f0068 */ 	lw	$t7,0x68($s2)
/*  f1645e8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1645ec:	11e00003 */ 	beqz	$t7,.NB0f1645fc
/*  f1645f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1645f4:	10000001 */ 	beqz	$zero,.NB0f1645fc
/*  f1645f8:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f1645fc:
/*  f1645fc:	8e580064 */ 	lw	$t8,0x64($s2)
/*  f164600:	13000003 */ 	beqz	$t8,.NB0f164610
/*  f164604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164608:	10000001 */ 	beqz	$zero,.NB0f164610
/*  f16460c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f164610:
/*  f164610:	8e4a0070 */ 	lw	$t2,0x70($s2)
/*  f164614:	11400003 */ 	beqz	$t2,.NB0f164624
/*  f164618:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16461c:	10000001 */ 	beqz	$zero,.NB0f164624
/*  f164620:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f164624:
/*  f164624:	0202c821 */ 	addu	$t9,$s0,$v0
/*  f164628:	03235821 */ 	addu	$t3,$t9,$v1
/*  f16462c:	01646021 */ 	addu	$t4,$t3,$a0
/*  f164630:	afac018c */ 	sw	$t4,0x18c($sp)
.NB0f164634:
/*  f164634:	02601025 */ 	or	$v0,$s3,$zero
/*  f164638:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16463c:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f164640:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f164644:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f164648:	02601825 */ 	or	$v1,$s3,$zero
/*  f16464c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164650:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f164654:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f164658:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16465c:	35ce0c04 */ 	ori	$t6,$t6,0xc04
/*  f164660:	02602025 */ 	or	$a0,$s3,$zero
/*  f164664:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f164668:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16466c:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f164670:	3408fffe */ 	dli	$t0,0xfffe
/*  f164674:	35ef1404 */ 	ori	$t7,$t7,0x1404
/*  f164678:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16467c:	02602825 */ 	or	$a1,$s3,$zero
/*  f164680:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f164684:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f164688:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f16468c:	37181c04 */ 	ori	$t8,$t8,0x1c04
/*  f164690:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f164694:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f164698:	8faa018c */ 	lw	$t2,0x18c($sp)
/*  f16469c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1646a0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1646a4:	1940057a */ 	blez	$t2,.NB0f165c90
/*  f1646a8:	3c198006 */ 	lui	$t9,0x8006
/*  f1646ac:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1646b0:	273938b0 */ 	addiu	$t9,$t9,0x38b0
/*  f1646b4:	4481a000 */ 	mtc1	$at,$f20
/*  f1646b8:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f1646bc:	27be00c8 */ 	addiu	$s8,$sp,0xc8
/*  f1646c0:	24170004 */ 	addiu	$s7,$zero,0x4
/*  f1646c4:	27b500b0 */ 	addiu	$s5,$sp,0xb0
/*  f1646c8:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f1646cc:	8fab0184 */ 	lw	$t3,0x184($sp)
.NB0f1646d0:
/*  f1646d0:	0000b025 */ 	or	$s6,$zero,$zero
/*  f1646d4:	afb30188 */ 	sw	$s3,0x188($sp)
/*  f1646d8:	11600007 */ 	beqz	$t3,.NB0f1646f8
/*  f1646dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1646e0:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f1646e4:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f1646e8:	260c0001 */ 	addiu	$t4,$s0,0x1
/*  f1646ec:	ae400290 */ 	sw	$zero,0x290($s2)
/*  f1646f0:	1000000a */ 	beqz	$zero,.NB0f16471c
/*  f1646f4:	afac0064 */ 	sw	$t4,0x64($sp)
.NB0f1646f8:
/*  f1646f8:	0fc48ec2 */ 	jal	getPlayerByOrderNum
/*  f1646fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f164700:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f164704:	00402025 */ 	or	$a0,$v0,$zero
/*  f164708:	8fad018c */ 	lw	$t5,0x18c($sp)
/*  f16470c:	26020001 */ 	addiu	$v0,$s0,0x1
/*  f164710:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f164714:	01a28826 */ 	xor	$s1,$t5,$v0
/*  f164718:	2e310001 */ 	sltiu	$s1,$s1,0x1
.NB0f16471c:
/*  f16471c:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
/*  f164720:	24010006 */ 	addiu	$at,$zero,0x6
/*  f164724:	11c10029 */ 	beq	$t6,$at,.NB0f1647cc
/*  f164728:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16472c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164730:	8e0f00bc */ 	lw	$t7,0xbc($s0)
/*  f164734:	8de20004 */ 	lw	$v0,0x4($t7)
/*  f164738:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f16473c:	18800023 */ 	blez	$a0,.NB0f1647cc
/*  f164740:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164744:	92181922 */ 	lbu	$t8,0x1922($s0)
/*  f164748:	17000020 */ 	bnez	$t8,.NB0f1647cc
/*  f16474c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164750:	8e0a1c08 */ 	lw	$t2,0x1c08($s0)
/*  f164754:	24011388 */ 	addiu	$at,$zero,0x1388
/*  f164758:	1540001c */ 	bnez	$t2,.NB0f1647cc
/*  f16475c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164760:	0004b180 */ 	sll	$s6,$a0,0x6
/*  f164764:	02c4b021 */ 	addu	$s6,$s6,$a0
/*  f164768:	0016b040 */ 	sll	$s6,$s6,0x1
/*  f16476c:	02c1001a */ 	div	$zero,$s6,$at
/*  f164770:	0000c812 */ 	mflo	$t9
/*  f164774:	27360064 */ 	addiu	$s6,$t9,0x64
/*  f164778:	2ec100e7 */ 	sltiu	$at,$s6,0xe7
/*  f16477c:	14200002 */ 	bnez	$at,.NB0f164788
/*  f164780:	240b1388 */ 	addiu	$t3,$zero,0x1388
/*  f164784:	241600e6 */ 	addiu	$s6,$zero,0xe6
.NB0f164788:
/*  f164788:	28811389 */ 	slti	$at,$a0,0x1389
/*  f16478c:	54200004 */ 	bnezl	$at,.NB0f1647a0
/*  f164790:	904d02ff */ 	lbu	$t5,0x2ff($v0)
/*  f164794:	a44b02d8 */ 	sh	$t3,0x2d8($v0)
/*  f164798:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f16479c:	904d02ff */ 	lbu	$t5,0x2ff($v0)
.NB0f1647a0:
/*  f1647a0:	8e4c0038 */ 	lw	$t4,0x38($s2)
/*  f1647a4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f1647a8:	018e0019 */ 	multu	$t4,$t6
/*  f1647ac:	00007812 */ 	mflo	$t7
/*  f1647b0:	008fc023 */ 	subu	$t8,$a0,$t7
/*  f1647b4:	a45802d8 */ 	sh	$t8,0x2d8($v0)
/*  f1647b8:	844a02d8 */ 	lh	$t2,0x2d8($v0)
/*  f1647bc:	1d400003 */ 	bgtz	$t2,.NB0f1647cc
/*  f1647c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1647c4:	a44002d8 */ 	sh	$zero,0x2d8($v0)
/*  f1647c8:	a04002ff */ 	sb	$zero,0x2ff($v0)
.NB0f1647cc:
/*  f1647cc:	0fc50cc5 */ 	jal	bviewSetBlur
/*  f1647d0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1647d4:	02601025 */ 	or	$v0,$s3,$zero
/*  f1647d8:	3c190600 */ 	lui	$t9,0x600
/*  f1647dc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1647e0:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f1647e4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1647e8:	0fc4666a */ 	jal	debug0f11ee28
/*  f1647ec:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f1647f0:	10400009 */ 	beqz	$v0,.NB0f164818
/*  f1647f4:	3c0e0600 */ 	lui	$t6,0x600
/*  f1647f8:	02601025 */ 	or	$v0,$s3,$zero
/*  f1647fc:	3c0c8006 */ 	lui	$t4,0x8006
/*  f164800:	258c3870 */ 	addiu	$t4,$t4,0x3870
/*  f164804:	3c0d0600 */ 	lui	$t5,0x600
/*  f164808:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f16480c:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f164810:	10000007 */ 	beqz	$zero,.NB0f164830
/*  f164814:	26730008 */ 	addiu	$s3,$s3,0x8
.NB0f164818:
/*  f164818:	02601025 */ 	or	$v0,$s3,$zero
/*  f16481c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f164820:	25ef3890 */ 	addiu	$t7,$t7,0x3890
/*  f164824:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f164828:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f16482c:	26730008 */ 	addiu	$s3,$s3,0x8
.NB0f164830:
/*  f164830:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164834:	86040634 */ 	lh	$a0,0x634($s0)
/*  f164838:	0c002f9f */ 	jal	viSetViewPosition
/*  f16483c:	86050636 */ 	lh	$a1,0x636($s0)
/*  f164840:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164844:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f164848:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16484c:	86060630 */ 	lh	$a2,0x630($s0)
/*  f164850:	0c002feb */ 	jal	viSetFovAspectAndSize
/*  f164854:	86070632 */ 	lh	$a3,0x632($s0)
/*  f164858:	8e580288 */ 	lw	$t8,0x288($s2)
/*  f16485c:	0c005db6 */ 	jal	func00016748
/*  f164860:	c70c0074 */ 	lwc1	$f12,0x74($t8)
/*  f164864:	0fc57ffe */ 	jal	func0f1657f8
/*  f164868:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16486c:	0fc5c3ce */ 	jal	func0f176298
/*  f164870:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164874:	0c002d00 */ 	jal	func0000b280
/*  f164878:	02602025 */ 	or	$a0,$s3,$zero
/*  f16487c:	0c002cd4 */ 	jal	func0000b1d0
/*  f164880:	00402025 */ 	or	$a0,$v0,$zero
/*  f164884:	0fc55c96 */ 	jal	currentPlayerScissorToViewport
/*  f164888:	00402025 */ 	or	$a0,$v0,$zero
/*  f16488c:	0fc4dc04 */ 	jal	func0f13c510
/*  f164890:	00409825 */ 	or	$s3,$v0,$zero
/*  f164894:	8e4a04b4 */ 	lw	$t2,0x4b4($s2)
/*  f164898:	24010026 */ 	addiu	$at,$zero,0x26
/*  f16489c:	3c198009 */ 	lui	$t9,0x8009
/*  f1648a0:	5541000a */ 	bnel	$t2,$at,.NB0f1648cc
/*  f1648a4:	8e4d000c */ 	lw	$t5,0xc($s2)
/*  f1648a8:	8f3999e0 */ 	lw	$t9,-0x6620($t9)
/*  f1648ac:	3c0b800a */ 	lui	$t3,0x800a
/*  f1648b0:	5f20001b */ 	bgtzl	$t9,.NB0f164920
/*  f1648b4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1648b8:	8d6b5eb4 */ 	lw	$t3,0x5eb4($t3)
/*  f1648bc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1648c0:	51610017 */ 	beql	$t3,$at,.NB0f164920
/*  f1648c4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1648c8:	8e4d000c */ 	lw	$t5,0xc($s2)
.NB0f1648cc:
/*  f1648cc:	29a10006 */ 	slti	$at,$t5,0x6
/*  f1648d0:	50200013 */ 	beqzl	$at,.NB0f164920
/*  f1648d4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1648d8:	8e4c0318 */ 	lw	$t4,0x318($s2)
/*  f1648dc:	55800010 */ 	bnezl	$t4,.NB0f164920
/*  f1648e0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1648e4:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
/*  f1648e8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1648ec:	3c028008 */ 	lui	$v0,0x8008
/*  f1648f0:	51c1000b */ 	beql	$t6,$at,.NB0f164920
/*  f1648f4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1648f8:	8c4268b0 */ 	lw	$v0,0x68b0($v0)
/*  f1648fc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f164900:	28410006 */ 	slti	$at,$v0,0x6
/*  f164904:	10200002 */ 	beqz	$at,.NB0f164910
/*  f164908:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f16490c:	ae4f0320 */ 	sw	$t7,0x320($s2)
.NB0f164910:
/*  f164910:	3c018008 */ 	lui	$at,0x8008
/*  f164914:	1000001d */ 	beqz	$zero,.NB0f16498c
/*  f164918:	ac3868b0 */ 	sw	$t8,0x68b0($at)
/*  f16491c:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164920:
/*  f164920:	3c0d8008 */ 	lui	$t5,0x8008
/*  f164924:	8e0a1580 */ 	lw	$t2,0x1580($s0)
/*  f164928:	000a5f80 */ 	sll	$t3,$t2,0x1e
/*  f16492c:	05630018 */ 	bgezl	$t3,.NB0f164990
/*  f164930:	8e4d0320 */ 	lw	$t5,0x320($s2)
/*  f164934:	8dad86e8 */ 	lw	$t5,-0x7918($t5)
/*  f164938:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16493c:	55a10014 */ 	bnel	$t5,$at,.NB0f164990
/*  f164940:	8e4d0320 */ 	lw	$t5,0x320($s2)
/*  f164944:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f164948:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16494c:	1041000f */ 	beq	$v0,$at,.NB0f16498c
/*  f164950:	24010002 */ 	addiu	$at,$zero,0x2
/*  f164954:	1041000d */ 	beq	$v0,$at,.NB0f16498c
/*  f164958:	3c0c800a */ 	lui	$t4,0x800a
/*  f16495c:	8d8c2780 */ 	lw	$t4,0x2780($t4)
/*  f164960:	5580000b */ 	bnezl	$t4,.NB0f164990
/*  f164964:	8e4d0320 */ 	lw	$t5,0x320($s2)
/*  f164968:	0fc2725e */ 	jal	bgun0f09eae4
/*  f16496c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164970:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164974:	00027840 */ 	sll	$t7,$v0,0x1
/*  f164978:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f16497c:	920a1583 */ 	lbu	$t2,0x1583($s0)
/*  f164980:	3159fffd */ 	andi	$t9,$t2,0xfffd
/*  f164984:	03195825 */ 	or	$t3,$t8,$t9
/*  f164988:	a20b1583 */ 	sb	$t3,0x1583($s0)
.NB0f16498c:
/*  f16498c:	8e4d0320 */ 	lw	$t5,0x320($s2)
.NB0f164990:
/*  f164990:	02602025 */ 	or	$a0,$s3,$zero
/*  f164994:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f164998:	11a00008 */ 	beqz	$t5,.NB0f1649bc
/*  f16499c:	3c0f800a */ 	lui	$t7,0x800a
/*  f1649a0:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f1649a4:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f1649a8:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f1649ac:	00409825 */ 	or	$s3,$v0,$zero
/*  f1649b0:	258effff */ 	addiu	$t6,$t4,-1
/*  f1649b4:	10000499 */ 	beqz	$zero,.NB0f165c1c
/*  f1649b8:	ae4e0320 */ 	sw	$t6,0x320($s2)
.NB0f1649bc:
/*  f1649bc:	8def2780 */ 	lw	$t7,0x2780($t7)
/*  f1649c0:	3c0b8008 */ 	lui	$t3,0x8008
/*  f1649c4:	11e00012 */ 	beqz	$t7,.NB0f164a10
/*  f1649c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1649cc:	0c002d2c */ 	jal	func0000b330
/*  f1649d0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1649d4:	0fc55c96 */ 	jal	currentPlayerScissorToViewport
/*  f1649d8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1649dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f1649e0:	44816000 */ 	mtc1	$at,$f12
/*  f1649e4:	0c005db6 */ 	jal	func00016748
/*  f1649e8:	00409825 */ 	or	$s3,$v0,$zero
/*  f1649ec:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f1649f0:	8d581c50 */ 	lw	$t8,0x1c50($t2)
/*  f1649f4:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f1649f8:	13200488 */ 	beqz	$t9,.NB0f165c1c
/*  f1649fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a00:	0fc3e0e0 */ 	jal	func0f0fbc30
/*  f164a04:	02602025 */ 	or	$a0,$s3,$zero
/*  f164a08:	10000484 */ 	beqz	$zero,.NB0f165c1c
/*  f164a0c:	00409825 */ 	or	$s3,$v0,$zero
.NB0f164a10:
/*  f164a10:	8d6b86e8 */ 	lw	$t3,-0x7918($t3)
/*  f164a14:	24010002 */ 	addiu	$at,$zero,0x2
/*  f164a18:	15610004 */ 	bne	$t3,$at,.NB0f164a2c
/*  f164a1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a20:	0fc2f6ee */ 	jal	currentPlayerUpdateShootRot
/*  f164a24:	02602025 */ 	or	$a0,$s3,$zero
/*  f164a28:	00409825 */ 	or	$s3,$v0,$zero
.NB0f164a2c:
/*  f164a2c:	0c002d2c */ 	jal	func0000b330
/*  f164a30:	02602025 */ 	or	$a0,$s3,$zero
/*  f164a34:	0fc46971 */ 	jal	func0f11f984
/*  f164a38:	00402025 */ 	or	$a0,$v0,$zero
/*  f164a3c:	0fc55c2f */ 	jal	roomsTick
/*  f164a40:	00409825 */ 	or	$s3,$v0,$zero
/*  f164a44:	0fc01017 */ 	jal	func0f004314
/*  f164a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a4c:	0fc188ac */ 	jal	propsTick
/*  f164a50:	02202025 */ 	or	$a0,$s1,$zero
/*  f164a54:	0fc5ff30 */ 	jal	scenarioCallback14
/*  f164a58:	00002025 */ 	or	$a0,$zero,$zero
/*  f164a5c:	0fc17d1c */ 	jal	propsSort
/*  f164a60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a64:	0fc18fd4 */ 	jal	autoaimTick
/*  f164a68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a6c:	0fc1876c */ 	jal	handsTickAttack
/*  f164a70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a74:	8e4d006c */ 	lw	$t5,0x6c($s2)
/*  f164a78:	24010001 */ 	addiu	$at,$zero,0x1
/*  f164a7c:	00002025 */ 	or	$a0,$zero,$zero
/*  f164a80:	11a00003 */ 	beqz	$t5,.NB0f164a90
/*  f164a84:	00001825 */ 	or	$v1,$zero,$zero
/*  f164a88:	10000001 */ 	beqz	$zero,.NB0f164a90
/*  f164a8c:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f164a90:
/*  f164a90:	8e4c0068 */ 	lw	$t4,0x68($s2)
/*  f164a94:	00001025 */ 	or	$v0,$zero,$zero
/*  f164a98:	00008025 */ 	or	$s0,$zero,$zero
/*  f164a9c:	11800003 */ 	beqz	$t4,.NB0f164aac
/*  f164aa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164aa4:	10000001 */ 	beqz	$zero,.NB0f164aac
/*  f164aa8:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f164aac:
/*  f164aac:	8e4e0064 */ 	lw	$t6,0x64($s2)
/*  f164ab0:	11c00003 */ 	beqz	$t6,.NB0f164ac0
/*  f164ab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164ab8:	10000001 */ 	beqz	$zero,.NB0f164ac0
/*  f164abc:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f164ac0:
/*  f164ac0:	8e4f0070 */ 	lw	$t7,0x70($s2)
/*  f164ac4:	11e00003 */ 	beqz	$t7,.NB0f164ad4
/*  f164ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164acc:	10000001 */ 	beqz	$zero,.NB0f164ad4
/*  f164ad0:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f164ad4:
/*  f164ad4:	02025021 */ 	addu	$t2,$s0,$v0
/*  f164ad8:	0143c021 */ 	addu	$t8,$t2,$v1
/*  f164adc:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f164ae0:	53210012 */ 	beql	$t9,$at,.NB0f164b2c
/*  f164ae4:	00002025 */ 	or	$a0,$zero,$zero
/*  f164ae8:	8e4b0298 */ 	lw	$t3,0x298($s2)
/*  f164aec:	0563000f */ 	bgezl	$t3,.NB0f164b2c
/*  f164af0:	00002025 */ 	or	$a0,$zero,$zero
/*  f164af4:	8e4d029c */ 	lw	$t5,0x29c($s2)
/*  f164af8:	05a3000c */ 	bgezl	$t5,.NB0f164b2c
/*  f164afc:	00002025 */ 	or	$a0,$zero,$zero
/*  f164b00:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f164b04:	00002025 */ 	or	$a0,$zero,$zero
/*  f164b08:	00402025 */ 	or	$a0,$v0,$zero
/*  f164b0c:	0fc2bd48 */ 	jal	weaponHasFlag
/*  f164b10:	3c054000 */ 	lui	$a1,0x4000
/*  f164b14:	50400051 */ 	beqzl	$v0,.NB0f164c5c
/*  f164b18:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f164b1c:	0fc314d4 */ 	jal	bmoveIsInSightAimMode
/*  f164b20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164b24:	1040004c */ 	beqz	$v0,.NB0f164c58
/*  f164b28:	00002025 */ 	or	$a0,$zero,$zero
.NB0f164b2c:
/*  f164b2c:	00002825 */ 	or	$a1,$zero,$zero
/*  f164b30:	0fc183f6 */ 	jal	func0f061d54
/*  f164b34:	00003025 */ 	or	$a2,$zero,$zero
/*  f164b38:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f164b3c:	ad821624 */ 	sw	$v0,0x1624($t4)
/*  f164b40:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164b44:	8e041624 */ 	lw	$a0,0x1624($s0)
/*  f164b48:	50800047 */ 	beqzl	$a0,.NB0f164c68
/*  f164b4c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f164b50:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f164b54:	24010003 */ 	addiu	$at,$zero,0x3
/*  f164b58:	10410003 */ 	beq	$v0,$at,.NB0f164b68
/*  f164b5c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f164b60:	54410020 */ 	bnel	$v0,$at,.NB0f164be4
/*  f164b64:	24010001 */ 	addiu	$at,$zero,0x1
.NB0f164b68:
/*  f164b68:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f164b6c:	8c4e0014 */ 	lw	$t6,0x14($v0)
/*  f164b70:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f164b74:	05e3003c */ 	bgezl	$t7,.NB0f164c68
/*  f164b78:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f164b7c:	8e0a00d8 */ 	lw	$t2,0xd8($s0)
/*  f164b80:	3c188007 */ 	lui	$t8,0x8007
/*  f164b84:	55400014 */ 	bnezl	$t2,.NB0f164bd8
/*  f164b88:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f164b8c:	8f182e24 */ 	lw	$t8,0x2e24($t8)
/*  f164b90:	57000011 */ 	bnezl	$t8,.NB0f164bd8
/*  f164b94:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f164b98:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f164b9c:	50400007 */ 	beqzl	$v0,.NB0f164bbc
/*  f164ba0:	8e0d1c54 */ 	lw	$t5,0x1c54($s0)
/*  f164ba4:	5040000c */ 	beqzl	$v0,.NB0f164bd8
/*  f164ba8:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f164bac:	80590037 */ 	lb	$t9,0x37($v0)
/*  f164bb0:	57200009 */ 	bnezl	$t9,.NB0f164bd8
/*  f164bb4:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f164bb8:	8e0d1c54 */ 	lw	$t5,0x1c54($s0)
.NB0f164bbc:
/*  f164bbc:	8e0b00c4 */ 	lw	$t3,0xc4($s0)
/*  f164bc0:	01a06027 */ 	nor	$t4,$t5,$zero
/*  f164bc4:	016c7024 */ 	and	$t6,$t3,$t4
/*  f164bc8:	31cf0008 */ 	andi	$t7,$t6,0x8
/*  f164bcc:	55e00026 */ 	bnezl	$t7,.NB0f164c68
/*  f164bd0:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f164bd4:	ae001624 */ 	sw	$zero,0x1624($s0)
.NB0f164bd8:
/*  f164bd8:	10000022 */ 	beqz	$zero,.NB0f164c64
/*  f164bdc:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164be0:	24010001 */ 	addiu	$at,$zero,0x1
.NB0f164be4:
/*  f164be4:	50410006 */ 	beql	$v0,$at,.NB0f164c00
/*  f164be8:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f164bec:	12e20003 */ 	beq	$s7,$v0,.NB0f164bfc
/*  f164bf0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f164bf4:	54410016 */ 	bnel	$v0,$at,.NB0f164c50
/*  f164bf8:	ae001624 */ 	sw	$zero,0x1624($s0)
.NB0f164bfc:
/*  f164bfc:	8c830004 */ 	lw	$v1,0x4($a0)
.NB0f164c00:
/*  f164c00:	8c6a0010 */ 	lw	$t2,0x10($v1)
/*  f164c04:	31588000 */ 	andi	$t8,$t2,0x8000
/*  f164c08:	57000017 */ 	bnezl	$t8,.NB0f164c68
/*  f164c0c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f164c10:	8e5904b4 */ 	lw	$t9,0x4b4($s2)
/*  f164c14:	24010026 */ 	addiu	$at,$zero,0x26
/*  f164c18:	5721000a */ 	bnel	$t9,$at,.NB0f164c44
/*  f164c1c:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f164c20:	84620004 */ 	lh	$v0,0x4($v1)
/*  f164c24:	2401014c */ 	addiu	$at,$zero,0x14c
/*  f164c28:	1041000e */ 	beq	$v0,$at,.NB0f164c64
/*  f164c2c:	240101aa */ 	addiu	$at,$zero,0x1aa
/*  f164c30:	1041000c */ 	beq	$v0,$at,.NB0f164c64
/*  f164c34:	240100b0 */ 	addiu	$at,$zero,0xb0
/*  f164c38:	5041000b */ 	beql	$v0,$at,.NB0f164c68
/*  f164c3c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f164c40:	ae001624 */ 	sw	$zero,0x1624($s0)
.NB0f164c44:
/*  f164c44:	10000007 */ 	beqz	$zero,.NB0f164c64
/*  f164c48:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164c4c:	ae001624 */ 	sw	$zero,0x1624($s0)
.NB0f164c50:
/*  f164c50:	10000004 */ 	beqz	$zero,.NB0f164c64
/*  f164c54:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164c58:
/*  f164c58:	8e4d0284 */ 	lw	$t5,0x284($s2)
.NB0f164c5c:
/*  f164c5c:	ada01624 */ 	sw	$zero,0x1624($t5)
/*  f164c60:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164c64:
/*  f164c64:	26040638 */ 	addiu	$a0,$s0,0x638
.NB0f164c68:
/*  f164c68:	0fc2bf02 */ 	jal	gsetHasFunctionFlags
/*  f164c6c:	3c050008 */ 	lui	$a1,0x8
/*  f164c70:	10400005 */ 	beqz	$v0,.NB0f164c88
/*  f164c74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164c78:	0fc58fa5 */ 	jal	lvFindThreats
/*  f164c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164c80:	10000034 */ 	beqz	$zero,.NB0f164d54
/*  f164c84:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164c88:
/*  f164c88:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f164c8c:	00002025 */ 	or	$a0,$zero,$zero
/*  f164c90:	00402025 */ 	or	$a0,$v0,$zero
/*  f164c94:	0fc2bd48 */ 	jal	weaponHasFlag
/*  f164c98:	3c054000 */ 	lui	$a1,0x4000
/*  f164c9c:	5040002d */ 	beqzl	$v0,.NB0f164d54
/*  f164ca0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164ca4:	0fc66b10 */ 	jal	frIsInTraining
/*  f164ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164cac:	5040000f */ 	beqzl	$v0,.NB0f164cec
/*  f164cb0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f164cb4:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f164cb8:	8d6c1624 */ 	lw	$t4,0x1624($t3)
/*  f164cbc:	5180000b */ 	beqzl	$t4,.NB0f164cec
/*  f164cc0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f164cc4:	0fc314d4 */ 	jal	bmoveIsInSightAimMode
/*  f164cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164ccc:	50400007 */ 	beqzl	$v0,.NB0f164cec
/*  f164cd0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f164cd4:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f164cd8:	0fc66a4d */ 	jal	func0f1a0924
/*  f164cdc:	8dc41624 */ 	lw	$a0,0x1624($t6)
/*  f164ce0:	1000000a */ 	beqz	$zero,.NB0f164d0c
/*  f164ce4:	00008825 */ 	or	$s1,$zero,$zero
/*  f164ce8:	8e440284 */ 	lw	$a0,0x284($s2)
.NB0f164cec:
/*  f164cec:	02802825 */ 	or	$a1,$s4,$zero
/*  f164cf0:	0fc58c71 */ 	jal	lvCheckCmpFollowThreat
/*  f164cf4:	24841624 */ 	addiu	$a0,$a0,0x1624
/*  f164cf8:	54400004 */ 	bnezl	$v0,.NB0f164d0c
/*  f164cfc:	00008825 */ 	or	$s1,$zero,$zero
/*  f164d00:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f164d04:	ade01624 */ 	sw	$zero,0x1624($t7)
/*  f164d08:	00008825 */ 	or	$s1,$zero,$zero
.NB0f164d0c:
/*  f164d0c:	00008025 */ 	or	$s0,$zero,$zero
.NB0f164d10:
/*  f164d10:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f164d14:	02202825 */ 	or	$a1,$s1,$zero
/*  f164d18:	01502021 */ 	addu	$a0,$t2,$s0
/*  f164d1c:	0fc58c71 */ 	jal	lvCheckCmpFollowThreat
/*  f164d20:	24841630 */ 	addiu	$a0,$a0,0x1630
/*  f164d24:	14400008 */ 	bnez	$v0,.NB0f164d48
/*  f164d28:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f164d2c:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f164d30:	240dfffe */ 	addiu	$t5,$zero,-2
/*  f164d34:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f164d38:	a7341634 */ 	sh	$s4,0x1634($t9)
/*  f164d3c:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f164d40:	01706021 */ 	addu	$t4,$t3,$s0
/*  f164d44:	a58d1638 */ 	sh	$t5,0x1638($t4)
.NB0f164d48:
/*  f164d48:	1637fff1 */ 	bne	$s1,$s7,.NB0f164d10
/*  f164d4c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f164d50:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164d54:
/*  f164d54:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f164d58:	50400072 */ 	beqzl	$v0,.NB0f164f24
/*  f164d5c:	8e0c00d0 */ 	lw	$t4,0xd0($s0)
/*  f164d60:	8e0f1c54 */ 	lw	$t7,0x1c54($s0)
/*  f164d64:	8e0e00c4 */ 	lw	$t6,0xc4($s0)
/*  f164d68:	01e05027 */ 	nor	$t2,$t7,$zero
/*  f164d6c:	01cac024 */ 	and	$t8,$t6,$t2
/*  f164d70:	33190004 */ 	andi	$t9,$t8,0x4
/*  f164d74:	5320006b */ 	beqzl	$t9,.NB0f164f24
/*  f164d78:	8e0c00d0 */ 	lw	$t4,0xd0($s0)
/*  f164d7c:	804b0039 */ 	lb	$t3,0x39($v0)
/*  f164d80:	51600068 */ 	beqzl	$t3,.NB0f164f24
/*  f164d84:	8e0c00d0 */ 	lw	$t4,0xd0($s0)
/*  f164d88:	9043006b */ 	lbu	$v1,0x6b($v0)
/*  f164d8c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f164d90:	14600011 */ 	bnez	$v1,.NB0f164dd8
/*  f164d94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164d98:	3c0143c8 */ 	lui	$at,0x43c8
/*  f164d9c:	44816000 */ 	mtc1	$at,$f12
/*  f164da0:	0fc25005 */ 	jal	objectiveCheckHolograph
/*  f164da4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164da8:	3c04800a */ 	lui	$a0,0x800a
/*  f164dac:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f164db0:	240504ff */ 	addiu	$a1,$zero,0x4ff
/*  f164db4:	00003025 */ 	or	$a2,$zero,$zero
/*  f164db8:	02803825 */ 	or	$a3,$s4,$zero
/*  f164dbc:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f164dc0:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f164dc4:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f164dc8:	0c004338 */ 	jal	sndStart
/*  f164dcc:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f164dd0:	10000053 */ 	beqz	$zero,.NB0f164f20
/*  f164dd4:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164dd8:
/*  f164dd8:	14610032 */ 	bne	$v1,$at,.NB0f164ea4
/*  f164ddc:	3c0c8008 */ 	lui	$t4,0x8008
/*  f164de0:	8e0d0490 */ 	lw	$t5,0x490($s0)
/*  f164de4:	3c04800a */ 	lui	$a0,0x800a
/*  f164de8:	24058052 */ 	addiu	$a1,$zero,-32686
/*  f164dec:	11a00024 */ 	beqz	$t5,.NB0f164e80
/*  f164df0:	00003025 */ 	or	$a2,$zero,$zero
/*  f164df4:	3c04800a */ 	lui	$a0,0x800a
/*  f164df8:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f164dfc:	24058057 */ 	addiu	$a1,$zero,-32681
/*  f164e00:	00003025 */ 	or	$a2,$zero,$zero
/*  f164e04:	02803825 */ 	or	$a3,$s4,$zero
/*  f164e08:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f164e0c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f164e10:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f164e14:	0c004338 */ 	jal	sndStart
/*  f164e18:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f164e1c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164e20:	240b001c */ 	addiu	$t3,$zero,0x1c
/*  f164e24:	00002825 */ 	or	$a1,$zero,$zero
/*  f164e28:	8e0c0490 */ 	lw	$t4,0x490($s0)
/*  f164e2c:	27a70140 */ 	addiu	$a3,$sp,0x140
/*  f164e30:	258fffff */ 	addiu	$t7,$t4,-1
/*  f164e34:	ae0f0490 */ 	sw	$t7,0x490($s0)
/*  f164e38:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164e3c:	8e0e0480 */ 	lw	$t6,0x480($s0)
/*  f164e40:	c5d00004 */ 	lwc1	$f16,0x4($t6)
/*  f164e44:	e7b00140 */ 	swc1	$f16,0x140($sp)
/*  f164e48:	8e0a0480 */ 	lw	$t2,0x480($s0)
/*  f164e4c:	c5520008 */ 	lwc1	$f18,0x8($t2)
/*  f164e50:	e7b20144 */ 	swc1	$f18,0x144($sp)
/*  f164e54:	8e180480 */ 	lw	$t8,0x480($s0)
/*  f164e58:	c704000c */ 	lwc1	$f4,0xc($t8)
/*  f164e5c:	e7a40148 */ 	swc1	$f4,0x148($sp)
/*  f164e60:	8e190480 */ 	lw	$t9,0x480($s0)
/*  f164e64:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f164e68:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f164e6c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f164e70:	0fc23e35 */ 	jal	projectileCreate
/*  f164e74:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f164e78:	10000008 */ 	beqz	$zero,.NB0f164e9c
/*  f164e7c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f164e80:
/*  f164e80:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f164e84:	02803825 */ 	or	$a3,$s4,$zero
/*  f164e88:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f164e8c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f164e90:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f164e94:	0c004338 */ 	jal	sndStart
/*  f164e98:	afb4001c */ 	sw	$s4,0x1c($sp)
.NB0f164e9c:
/*  f164e9c:	10000020 */ 	beqz	$zero,.NB0f164f20
/*  f164ea0:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164ea4:
/*  f164ea4:	258c6904 */ 	addiu	$t4,$t4,0x6904
/*  f164ea8:	8d810000 */ 	lw	$at,0x0($t4)
/*  f164eac:	27ad0134 */ 	addiu	$t5,$sp,0x134
/*  f164eb0:	8d8a0004 */ 	lw	$t2,0x4($t4)
/*  f164eb4:	ada10000 */ 	sw	$at,0x0($t5)
/*  f164eb8:	8d810008 */ 	lw	$at,0x8($t4)
/*  f164ebc:	3c188008 */ 	lui	$t8,0x8008
/*  f164ec0:	adaa0004 */ 	sw	$t2,0x4($t5)
/*  f164ec4:	ada10008 */ 	sw	$at,0x8($t5)
/*  f164ec8:	8f186910 */ 	lw	$t8,0x6910($t8)
/*  f164ecc:	24070017 */ 	addiu	$a3,$zero,0x17
/*  f164ed0:	afb80130 */ 	sw	$t8,0x130($sp)
/*  f164ed4:	8e190480 */ 	lw	$t9,0x480($s0)
/*  f164ed8:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f164edc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f164ee0:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f164ee4:	0fc49158 */ 	jal	explosionCreateSimple
/*  f164ee8:	24860028 */ 	addiu	$a2,$a0,0x28
/*  f164eec:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f164ef0:	27ad0130 */ 	addiu	$t5,$sp,0x130
/*  f164ef4:	27a50134 */ 	addiu	$a1,$sp,0x134
/*  f164ef8:	8d6e0480 */ 	lw	$t6,0x480($t3)
/*  f164efc:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f164f00:	00003825 */ 	or	$a3,$zero,$zero
/*  f164f04:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f164f08:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f164f0c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f164f10:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f164f14:	0fc0c4ba */ 	jal	chrBeginDeath
/*  f164f18:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f164f1c:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164f20:
/*  f164f20:	8e0c00d0 */ 	lw	$t4,0xd0($s0)
.NB0f164f24:
/*  f164f24:	5180000c */ 	beqzl	$t4,.NB0f164f58
/*  f164f28:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f164f2c:	0fc1883e */ 	jal	currentPlayerInteract
/*  f164f30:	00002025 */ 	or	$a0,$zero,$zero
/*  f164f34:	10400012 */ 	beqz	$v0,.NB0f164f80
/*  f164f38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f3c:	0fc27fe5 */ 	jal	bgunReloadIfPossible
/*  f164f40:	00002025 */ 	or	$a0,$zero,$zero
/*  f164f44:	0fc27fe5 */ 	jal	bgunReloadIfPossible
/*  f164f48:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f164f4c:	1000000c */ 	beqz	$zero,.NB0f164f80
/*  f164f50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f54:	8e020480 */ 	lw	$v0,0x480($s0)
.NB0f164f58:
/*  f164f58:	10400009 */ 	beqz	$v0,.NB0f164f80
/*  f164f5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f60:	804a0037 */ 	lb	$t2,0x37($v0)
/*  f164f64:	11400006 */ 	beqz	$t2,.NB0f164f80
/*  f164f68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f6c:	9058006a */ 	lbu	$t8,0x6a($v0)
/*  f164f70:	13000003 */ 	beqz	$t8,.NB0f164f80
/*  f164f74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f78:	0fc1883e */ 	jal	currentPlayerInteract
/*  f164f7c:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f164f80:
/*  f164f80:	0fc18d1a */ 	jal	func0f0641f4
/*  f164f84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f88:	0fc55c71 */ 	jal	bgRender
/*  f164f8c:	02602025 */ 	or	$a0,$s3,$zero
/*  f164f90:	3c108008 */ 	lui	$s0,0x8008
/*  f164f94:	8e1086f0 */ 	lw	$s0,-0x7910($s0)
/*  f164f98:	00409825 */ 	or	$s3,$v0,$zero
/*  f164f9c:	3a19000f */ 	xori	$t9,$s0,0xf
/*  f164fa0:	2f300001 */ 	sltiu	$s0,$t9,0x1
/*  f164fa4:	16000005 */ 	bnez	$s0,.NB0f164fbc
/*  f164fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164fac:	3c108006 */ 	lui	$s0,0x8006
/*  f164fb0:	8e101530 */ 	lw	$s0,0x1530($s0)
/*  f164fb4:	0010582b */ 	sltu	$t3,$zero,$s0
/*  f164fb8:	01608025 */ 	or	$s0,$t3,$zero
.NB0f164fbc:
/*  f164fbc:	0fc09fa8 */ 	jal	func0f028498
/*  f164fc0:	02002025 */ 	or	$a0,$s0,$zero
/*  f164fc4:	0fc1f852 */ 	jal	propsRenderBeams
/*  f164fc8:	02602025 */ 	or	$a0,$s3,$zero
/*  f164fcc:	0fc53373 */ 	jal	shardsRender
/*  f164fd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f164fd4:	0fc4aaf5 */ 	jal	sparksRender
/*  f164fd8:	00402025 */ 	or	$a0,$v0,$zero
/*  f164fdc:	0fc4aefc */ 	jal	weatherRender
/*  f164fe0:	00402025 */ 	or	$a0,$v0,$zero
/*  f164fe4:	3c0e8006 */ 	lui	$t6,0x8006
/*  f164fe8:	8dce3b50 */ 	lw	$t6,0x3b50($t6)
/*  f164fec:	00409825 */ 	or	$s3,$v0,$zero
/*  f164ff0:	11c00004 */ 	beqz	$t6,.NB0f165004
/*  f164ff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164ff8:	0fc0278e */ 	jal	nbombsRender
/*  f164ffc:	00402025 */ 	or	$a0,$v0,$zero
/*  f165000:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165004:
/*  f165004:	3c0f8008 */ 	lui	$t7,0x8008
/*  f165008:	8def86e8 */ 	lw	$t7,-0x7918($t7)
/*  f16500c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f165010:	15e10007 */ 	bne	$t7,$at,.NB0f165030
/*  f165014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165018:	0fc2f8ed */ 	jal	currentPlayerRenderHud
/*  f16501c:	02602025 */ 	or	$a0,$s3,$zero
/*  f165020:	0fc58d05 */ 	jal	func7f163414nb
/*  f165024:	00402025 */ 	or	$a0,$v0,$zero
/*  f165028:	1000000c */ 	beqz	$zero,.NB0f16505c
/*  f16502c:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165030:
/*  f165030:	0fc2b30e */ 	jal	func0f0aeed8
/*  f165034:	02602025 */ 	or	$a0,$s3,$zero
/*  f165038:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f16503c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f165040:	00409825 */ 	or	$s3,$v0,$zero
/*  f165044:	95ac0010 */ 	lhu	$t4,0x10($t5)
/*  f165048:	11810004 */ 	beq	$t4,$at,.NB0f16505c
/*  f16504c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165050:	0fc555df */ 	jal	func0f15b114
/*  f165054:	00402025 */ 	or	$a0,$v0,$zero
/*  f165058:	00409825 */ 	or	$s3,$v0,$zero
.NB0f16505c:
/*  f16505c:	3c0a8008 */ 	lui	$t2,0x8008
/*  f165060:	8d4a8814 */ 	lw	$t2,-0x77ec($t2)
/*  f165064:	1d40027f */ 	bgtz	$t2,.NB0f165a64
/*  f165068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16506c:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f165070:	24010006 */ 	addiu	$at,$zero,0x6
/*  f165074:	afa0012c */ 	sw	$zero,0x12c($sp)
/*  f165078:	1701010a */ 	bne	$t8,$at,.NB0f1654a4
/*  f16507c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165080:	8e5904b4 */ 	lw	$t9,0x4b4($s2)
/*  f165084:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f165088:	3c04800a */ 	lui	$a0,0x800a
/*  f16508c:	17210095 */ 	bne	$t9,$at,.NB0f1652e4
/*  f165090:	00008025 */ 	or	$s0,$zero,$zero
/*  f165094:	44800000 */ 	mtc1	$zero,$f0
/*  f165098:	848425f8 */ 	lh	$a0,0x25f8($a0)
/*  f16509c:	0c0092d2 */ 	jal	animGetNumFrames
/*  f1650a0:	e7a00124 */ 	swc1	$f0,0x124($sp)
/*  f1650a4:	3c03800a */ 	lui	$v1,0x800a
/*  f1650a8:	8c6325f0 */ 	lw	$v1,0x25f0($v1)
/*  f1650ac:	c7a00124 */ 	lwc1	$f0,0x124($sp)
/*  f1650b0:	3c0b800a */ 	lui	$t3,0x800a
/*  f1650b4:	2861005a */ 	slti	$at,$v1,0x5a
/*  f1650b8:	10200009 */ 	beqz	$at,.NB0f1650e0
/*  f1650bc:	2444ffff */ 	addiu	$a0,$v0,-1
/*  f1650c0:	44833000 */ 	mtc1	$v1,$f6
/*  f1650c4:	3c0142b4 */ 	lui	$at,0x42b4
/*  f1650c8:	44815000 */ 	mtc1	$at,$f10
/*  f1650cc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1650d0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1650d4:	44819000 */ 	mtc1	$at,$f18
/*  f1650d8:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f1650dc:	46109001 */ 	sub.s	$f0,$f18,$f16
.NB0f1650e0:
/*  f1650e0:	856b25f8 */ 	lh	$t3,0x25f8($t3)
/*  f1650e4:	2401046c */ 	addiu	$at,$zero,0x46c
/*  f1650e8:	248cffe2 */ 	addiu	$t4,$a0,-30
/*  f1650ec:	1161000d */ 	beq	$t3,$at,.NB0f165124
/*  f1650f0:	3c19e700 */ 	lui	$t9,0xe700
/*  f1650f4:	2444ffff */ 	addiu	$a0,$v0,-1
/*  f1650f8:	248effa6 */ 	addiu	$t6,$a0,-90
/*  f1650fc:	01c3082a */ 	slt	$at,$t6,$v1
/*  f165100:	10200012 */ 	beqz	$at,.NB0f16514c
/*  f165104:	00647823 */ 	subu	$t7,$v1,$a0
/*  f165108:	25ed005a */ 	addiu	$t5,$t7,0x5a
/*  f16510c:	448d2000 */ 	mtc1	$t5,$f4
/*  f165110:	3c0142b4 */ 	lui	$at,0x42b4
/*  f165114:	44814000 */ 	mtc1	$at,$f8
/*  f165118:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16511c:	1000000b */ 	beqz	$zero,.NB0f16514c
/*  f165120:	46083003 */ 	div.s	$f0,$f6,$f8
.NB0f165124:
/*  f165124:	0183082a */ 	slt	$at,$t4,$v1
/*  f165128:	10200008 */ 	beqz	$at,.NB0f16514c
/*  f16512c:	00645023 */ 	subu	$t2,$v1,$a0
/*  f165130:	2558001e */ 	addiu	$t8,$t2,0x1e
/*  f165134:	44985000 */ 	mtc1	$t8,$f10
/*  f165138:	3c0141f0 */ 	lui	$at,0x41f0
/*  f16513c:	44818000 */ 	mtc1	$at,$f16
/*  f165140:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f165144:	2410ff00 */ 	addiu	$s0,$zero,-256
/*  f165148:	46109003 */ 	div.s	$f0,$f18,$f16
.NB0f16514c:
/*  f16514c:	44802000 */ 	mtc1	$zero,$f4
/*  f165150:	3c0bb900 */ 	lui	$t3,0xb900
/*  f165154:	3c0e0050 */ 	lui	$t6,0x50
/*  f165158:	4600203c */ 	c.lt.s	$f4,$f0
/*  f16515c:	02601025 */ 	or	$v0,$s3,$zero
/*  f165160:	35ce4340 */ 	ori	$t6,$t6,0x4340
/*  f165164:	356b031d */ 	ori	$t3,$t3,0x31d
/*  f165168:	4500005e */ 	bc1f	.NB0f1652e4
/*  f16516c:	3c0ffcff */ 	lui	$t7,0xfcff
/*  f165170:	3c01437f */ 	lui	$at,0x437f
/*  f165174:	44813000 */ 	mtc1	$at,$f6
/*  f165178:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f16517c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f165180:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f165184:	02601825 */ 	or	$v1,$s3,$zero
/*  f165188:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f16518c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f165190:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f165194:	02602025 */ 	or	$a0,$s3,$zero
/*  f165198:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f16519c:	444af800 */ 	cfc1	$t2,$31
/*  f1651a0:	44d8f800 */ 	ctc1	$t8,$31
/*  f1651a4:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f1651a8:	3c0dfffd */ 	lui	$t5,0xfffd
/*  f1651ac:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f1651b0:	35adf6fb */ 	ori	$t5,$t5,0xf6fb
/*  f1651b4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1651b8:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f1651bc:	4458f800 */ 	cfc1	$t8,$31
/*  f1651c0:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1651c4:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f1651c8:	02602825 */ 	or	$a1,$s3,$zero
/*  f1651cc:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f1651d0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f1651d4:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f1651d8:	13000013 */ 	beqz	$t8,.NB0f165228
/*  f1651dc:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1651e0:	3c014f00 */ 	lui	$at,0x4f00
/*  f1651e4:	44815000 */ 	mtc1	$at,$f10
/*  f1651e8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1651ec:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f1651f0:	44d8f800 */ 	ctc1	$t8,$31
/*  f1651f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1651f8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f1651fc:	4458f800 */ 	cfc1	$t8,$31
/*  f165200:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165204:	33180078 */ 	andi	$t8,$t8,0x78
/*  f165208:	17000005 */ 	bnez	$t8,.NB0f165220
/*  f16520c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165210:	44185000 */ 	mfc1	$t8,$f10
/*  f165214:	3c018000 */ 	lui	$at,0x8000
/*  f165218:	10000007 */ 	beqz	$zero,.NB0f165238
/*  f16521c:	0301c025 */ 	or	$t8,$t8,$at
.NB0f165220:
/*  f165220:	10000005 */ 	beqz	$zero,.NB0f165238
/*  f165224:	2418ffff */ 	addiu	$t8,$zero,-1
.NB0f165228:
/*  f165228:	44185000 */ 	mfc1	$t8,$f10
/*  f16522c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165230:	0700fffb */ 	bltz	$t8,.NB0f165220
/*  f165234:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f165238:
/*  f165238:	0218c825 */ 	or	$t9,$s0,$t8
/*  f16523c:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f165240:	44caf800 */ 	ctc1	$t2,$31
/*  f165244:	afb30108 */ 	sw	$s3,0x108($sp)
/*  f165248:	0c002f97 */ 	jal	viGetViewWidth
/*  f16524c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f165250:	0c002fb5 */ 	jal	viGetViewLeft
/*  f165254:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f165258:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16525c:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f165260:	0c002fb9 */ 	jal	viGetViewTop
/*  f165264:	01608025 */ 	or	$s0,$t3,$zero
/*  f165268:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f16526c:	00117403 */ 	sra	$t6,$s1,0x10
/*  f165270:	0c002f9b */ 	jal	viGetViewHeight
/*  f165274:	01c08825 */ 	or	$s1,$t6,$zero
/*  f165278:	87b8008e */ 	lh	$t8,0x8e($sp)
/*  f16527c:	00517821 */ 	addu	$t7,$v0,$s1
/*  f165280:	31ed03ff */ 	andi	$t5,$t7,0x3ff
/*  f165284:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f165288:	0218c821 */ 	addu	$t9,$s0,$t8
/*  f16528c:	332b03ff */ 	andi	$t3,$t9,0x3ff
/*  f165290:	3c01f600 */ 	lui	$at,0xf600
/*  f165294:	8fad0108 */ 	lw	$t5,0x108($sp)
/*  f165298:	01815025 */ 	or	$t2,$t4,$at
/*  f16529c:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f1652a0:	014e7825 */ 	or	$t7,$t2,$t6
/*  f1652a4:	0c002fb5 */ 	jal	viGetViewLeft
/*  f1652a8:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f1652ac:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f1652b0:	00116403 */ 	sra	$t4,$s1,0x10
/*  f1652b4:	0c002fb9 */ 	jal	viGetViewTop
/*  f1652b8:	01808825 */ 	or	$s1,$t4,$zero
/*  f1652bc:	305803ff */ 	andi	$t8,$v0,0x3ff
/*  f1652c0:	322b03ff */ 	andi	$t3,$s1,0x3ff
/*  f1652c4:	8faf0108 */ 	lw	$t7,0x108($sp)
/*  f1652c8:	000b5380 */ 	sll	$t2,$t3,0xe
/*  f1652cc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1652d0:	032a7025 */ 	or	$t6,$t9,$t2
/*  f1652d4:	02602025 */ 	or	$a0,$s3,$zero
/*  f1652d8:	0fc537ce */ 	jal	func0f153838
/*  f1652dc:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f1652e0:	00409825 */ 	or	$s3,$v0,$zero
.NB0f1652e4:
/*  f1652e4:	3c10800a */ 	lui	$s0,0x800a
/*  f1652e8:	861025f8 */ 	lh	$s0,0x25f8($s0)
/*  f1652ec:	24010181 */ 	addiu	$at,$zero,0x181
/*  f1652f0:	3c048008 */ 	lui	$a0,0x8008
/*  f1652f4:	12010011 */ 	beq	$s0,$at,.NB0f16533c
/*  f1652f8:	24010183 */ 	addiu	$at,$zero,0x183
/*  f1652fc:	1201000f */ 	beq	$s0,$at,.NB0f16533c
/*  f165300:	24010188 */ 	addiu	$at,$zero,0x188
/*  f165304:	1201000d */ 	beq	$s0,$at,.NB0f16533c
/*  f165308:	240101e5 */ 	addiu	$at,$zero,0x1e5
/*  f16530c:	16010065 */ 	bne	$s0,$at,.NB0f1654a4
/*  f165310:	3c03800a */ 	lui	$v1,0x800a
/*  f165314:	8c6325f0 */ 	lw	$v1,0x25f0($v1)
/*  f165318:	28610348 */ 	slti	$at,$v1,0x348
/*  f16531c:	14200061 */ 	bnez	$at,.NB0f1654a4
/*  f165320:	28610583 */ 	slti	$at,$v1,0x583
/*  f165324:	1020005f */ 	beqz	$at,.NB0f1654a4
/*  f165328:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16532c:	0fc50990 */ 	jal	bviewRenderHorizonScanner
/*  f165330:	02602025 */ 	or	$a0,$s3,$zero
/*  f165334:	1000005b */ 	beqz	$zero,.NB0f1654a4
/*  f165338:	00409825 */ 	or	$s3,$v0,$zero
.NB0f16533c:
/*  f16533c:	8c846914 */ 	lw	$a0,0x6914($a0)
/*  f165340:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f165344:	00008025 */ 	or	$s0,$zero,$zero
/*  f165348:	1480000c */ 	bnez	$a0,.NB0f16537c
/*  f16534c:	afad012c */ 	sw	$t5,0x12c($sp)
/*  f165350:	3c04800a */ 	lui	$a0,0x800a
/*  f165354:	3c068008 */ 	lui	$a2,0x8008
/*  f165358:	24c66914 */ 	addiu	$a2,$a2,0x6914
/*  f16535c:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f165360:	2405059f */ 	addiu	$a1,$zero,0x59f
/*  f165364:	02803825 */ 	or	$a3,$s4,$zero
/*  f165368:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f16536c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f165370:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f165374:	0c004338 */ 	jal	sndStart
/*  f165378:	afb4001c */ 	sw	$s4,0x1c($sp)
.NB0f16537c:
/*  f16537c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f165380:	8d8c6918 */ 	lw	$t4,0x6918($t4)
/*  f165384:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f165388:	3c018008 */ 	lui	$at,0x8008
/*  f16538c:	01985823 */ 	subu	$t3,$t4,$t8
/*  f165390:	0561000b */ 	bgez	$t3,.NB0f1653c0
/*  f165394:	ac2b6918 */ 	sw	$t3,0x6918($at)
/*  f165398:	0c004d84 */ 	jal	random
/*  f16539c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1653a0:	240100c8 */ 	addiu	$at,$zero,0xc8
/*  f1653a4:	0041001b */ 	divu	$zero,$v0,$at
/*  f1653a8:	0000c810 */ 	mfhi	$t9
/*  f1653ac:	272a0028 */ 	addiu	$t2,$t9,0x28
/*  f1653b0:	3c018008 */ 	lui	$at,0x8008
/*  f1653b4:	ac2a6918 */ 	sw	$t2,0x6918($at)
/*  f1653b8:	3c018008 */ 	lui	$at,0x8008
/*  f1653bc:	a020691c */ 	sb	$zero,0x691c($at)
.NB0f1653c0:
/*  f1653c0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1653c4:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1653c8:	0fc4f51f */ 	jal	bviewRenderFilmLens
/*  f1653cc:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1653d0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1653d4:	8dce6918 */ 	lw	$t6,0x6918($t6)
/*  f1653d8:	00409825 */ 	or	$s3,$v0,$zero
/*  f1653dc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1653e0:	29c1000f */ 	slti	$at,$t6,0xf
/*  f1653e4:	10200017 */ 	beqz	$at,.NB0f165444
/*  f1653e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1653ec:	91ef691c */ 	lbu	$t7,0x691c($t7)
/*  f1653f0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1653f4:	3c018008 */ 	lui	$at,0x8008
/*  f1653f8:	15e0000b */ 	bnez	$t7,.NB0f165428
/*  f1653fc:	3c04800a */ 	lui	$a0,0x800a
/*  f165400:	a02d691c */ 	sb	$t5,0x691c($at)
/*  f165404:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f165408:	2405059e */ 	addiu	$a1,$zero,0x59e
/*  f16540c:	00003025 */ 	or	$a2,$zero,$zero
/*  f165410:	02803825 */ 	or	$a3,$s4,$zero
/*  f165414:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f165418:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16541c:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f165420:	0c004338 */ 	jal	sndStart
/*  f165424:	afb4001c */ 	sw	$s4,0x1c($sp)
.NB0f165428:
/*  f165428:	3c0c8008 */ 	lui	$t4,0x8008
/*  f16542c:	8d8c6918 */ 	lw	$t4,0x6918($t4)
/*  f165430:	240b00e1 */ 	addiu	$t3,$zero,0xe1
/*  f165434:	000cc080 */ 	sll	$t8,$t4,0x2
/*  f165438:	030cc021 */ 	addu	$t8,$t8,$t4
/*  f16543c:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f165440:	01788023 */ 	subu	$s0,$t3,$t8
.NB0f165444:
/*  f165444:	0c004d84 */ 	jal	random
/*  f165448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16544c:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f165450:	0041001b */ 	divu	$zero,$v0,$at
/*  f165454:	0000c810 */ 	mfhi	$t9
/*  f165458:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16545c:	1721000b */ 	bne	$t9,$at,.NB0f16548c
/*  f165460:	3c04800a */ 	lui	$a0,0x800a
/*  f165464:	241000ff */ 	addiu	$s0,$zero,0xff
/*  f165468:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f16546c:	2405059d */ 	addiu	$a1,$zero,0x59d
/*  f165470:	00003025 */ 	or	$a2,$zero,$zero
/*  f165474:	02803825 */ 	or	$a3,$s4,$zero
/*  f165478:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f16547c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f165480:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f165484:	0c004338 */ 	jal	sndStart
/*  f165488:	afb4001c */ 	sw	$s4,0x1c($sp)
.NB0f16548c:
/*  f16548c:	12000005 */ 	beqz	$s0,.NB0f1654a4
/*  f165490:	02602025 */ 	or	$a0,$s3,$zero
/*  f165494:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f165498:	0fc4f44d */ 	jal	bviewRenderStatic
/*  f16549c:	02003025 */ 	or	$a2,$s0,$zero
/*  f1654a0:	00409825 */ 	or	$s3,$v0,$zero
.NB0f1654a4:
/*  f1654a4:	3c048008 */ 	lui	$a0,0x8008
/*  f1654a8:	8c846914 */ 	lw	$a0,0x6914($a0)
/*  f1654ac:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f1654b0:	50800006 */ 	beqzl	$a0,.NB0f1654cc
/*  f1654b4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1654b8:	55400004 */ 	bnezl	$t2,.NB0f1654cc
/*  f1654bc:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1654c0:	0c00d428 */ 	jal	audioStop
/*  f1654c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1654c8:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f1654cc:
/*  f1654cc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1654d0:	960e0010 */ 	lhu	$t6,0x10($s0)
/*  f1654d4:	55c1001c */ 	bnel	$t6,$at,.NB0f165548
/*  f1654d8:	960c0010 */ 	lhu	$t4,0x10($s0)
/*  f1654dc:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f1654e0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1654e4:	02602025 */ 	or	$a0,$s3,$zero
/*  f1654e8:	11e10016 */ 	beq	$t7,$at,.NB0f165544
/*  f1654ec:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1654f0:	0fc4f499 */ 	jal	bviewRenderSlayerRocketLens
/*  f1654f4:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1654f8:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1654fc:	00409825 */ 	or	$s3,$v0,$zero
/*  f165500:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f165504:	8e0300c8 */ 	lw	$v1,0xc8($s0)
/*  f165508:	02602025 */ 	or	$a0,$s3,$zero
/*  f16550c:	3c054fff */ 	lui	$a1,0x4fff
/*  f165510:	1860000c */ 	blez	$v1,.NB0f165544
/*  f165514:	00033200 */ 	sll	$a2,$v1,0x8
/*  f165518:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16551c:	00c1001a */ 	div	$zero,$a2,$at
/*  f165520:	00003012 */ 	mflo	$a2
/*  f165524:	2cc10100 */ 	sltiu	$at,$a2,0x100
/*  f165528:	14200002 */ 	bnez	$at,.NB0f165534
/*  f16552c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165530:	240600ff */ 	addiu	$a2,$zero,0xff
.NB0f165534:
/*  f165534:	0fc4f44d */ 	jal	bviewRenderStatic
/*  f165538:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f16553c:	00409825 */ 	or	$s3,$v0,$zero
/*  f165540:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f165544:
/*  f165544:	960c0010 */ 	lhu	$t4,0x10($s0)
.NB0f165548:
/*  f165548:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16554c:	55810017 */ 	bnel	$t4,$at,.NB0f1655ac
/*  f165550:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f165554:	8e4b02ac */ 	lw	$t3,0x2ac($s2)
/*  f165558:	24010006 */ 	addiu	$at,$zero,0x6
/*  f16555c:	51610013 */ 	beql	$t3,$at,.NB0f1655ac
/*  f165560:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f165564:	8e020254 */ 	lw	$v0,0x254($s0)
/*  f165568:	24060063 */ 	addiu	$a2,$zero,0x63
/*  f16556c:	240a00f9 */ 	addiu	$t2,$zero,0xf9
/*  f165570:	284100c8 */ 	slti	$at,$v0,0xc8
/*  f165574:	10200004 */ 	beqz	$at,.NB0f165588
/*  f165578:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f16557c:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f165580:	0018c883 */ 	sra	$t9,$t8,0x2
/*  f165584:	01593023 */ 	subu	$a2,$t2,$t9
.NB0f165588:
/*  f165588:	3c017f1b */ 	lui	$at,0x7f1b
/*  f16558c:	c4201fbc */ 	lwc1	$f0,0x1fbc($at)
/*  f165590:	02602025 */ 	or	$a0,$s3,$zero
/*  f165594:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f165598:	44070000 */ 	mfc1	$a3,$f0
/*  f16559c:	0fc4f5b8 */ 	jal	bviewRenderZoomBlur
/*  f1655a0:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f1655a4:	00409825 */ 	or	$s3,$v0,$zero
/*  f1655a8:	8e430460 */ 	lw	$v1,0x460($s2)
.NB0f1655ac:
/*  f1655ac:	18600003 */ 	blez	$v1,.NB0f1655bc
/*  f1655b0:	2861001e */ 	slti	$at,$v1,0x1e
/*  f1655b4:	5420000c */ 	bnezl	$at,.NB0f1655e8
/*  f1655b8:	2401001e */ 	addiu	$at,$zero,0x1e
.NB0f1655bc:
/*  f1655bc:	8e420464 */ 	lw	$v0,0x464($s2)
/*  f1655c0:	10400004 */ 	beqz	$v0,.NB0f1655d4
/*  f1655c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1655c8:	8e4e0468 */ 	lw	$t6,0x468($s2)
/*  f1655cc:	51c00006 */ 	beqzl	$t6,.NB0f1655e8
/*  f1655d0:	2401001e */ 	addiu	$at,$zero,0x1e
.NB0f1655d4:
/*  f1655d4:	54400085 */ 	bnezl	$v0,.NB0f1657ec
/*  f1655d8:	28610010 */ 	slti	$at,$v1,0x10
/*  f1655dc:	8e4f0468 */ 	lw	$t7,0x468($s2)
/*  f1655e0:	11e00081 */ 	beqz	$t7,.NB0f1657e8
/*  f1655e4:	2401001e */ 	addiu	$at,$zero,0x1e
.NB0f1655e8:
/*  f1655e8:	54610018 */ 	bnel	$v1,$at,.NB0f16564c
/*  f1655ec:	2861000f */ 	slti	$at,$v1,0xf
/*  f1655f0:	8e4d0464 */ 	lw	$t5,0x464($s2)
/*  f1655f4:	55a00015 */ 	bnezl	$t5,.NB0f16564c
/*  f1655f8:	2861000f */ 	slti	$at,$v1,0xf
/*  f1655fc:	0fc599a0 */ 	jal	lvGetSlowMotionType
/*  f165600:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165604:	10400003 */ 	beqz	$v0,.NB0f165614
/*  f165608:	3c04800a */ 	lui	$a0,0x800a
/*  f16560c:	10000002 */ 	beqz	$zero,.NB0f165618
/*  f165610:	241005c9 */ 	addiu	$s0,$zero,0x5c9
.NB0f165614:
/*  f165614:	241002ad */ 	addiu	$s0,$zero,0x2ad
.NB0f165618:
/*  f165618:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f16561c:	00056403 */ 	sra	$t4,$a1,0x10
/*  f165620:	01802825 */ 	or	$a1,$t4,$zero
/*  f165624:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f165628:	00003025 */ 	or	$a2,$zero,$zero
/*  f16562c:	02803825 */ 	or	$a3,$s4,$zero
/*  f165630:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f165634:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f165638:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f16563c:	0c004338 */ 	jal	sndStart
/*  f165640:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f165644:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f165648:	2861000f */ 	slti	$at,$v1,0xf
.NB0f16564c:
/*  f16564c:	10200026 */ 	beqz	$at,.NB0f1656e8
/*  f165650:	240a001e */ 	addiu	$t2,$zero,0x1e
/*  f165654:	2401000f */ 	addiu	$at,$zero,0xf
/*  f165658:	00033080 */ 	sll	$a2,$v1,0x2
/*  f16565c:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f165660:	00063080 */ 	sll	$a2,$a2,0x2
/*  f165664:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f165668:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16566c:	00c33021 */ 	addu	$a2,$a2,$v1
/*  f165670:	00063080 */ 	sll	$a2,$a2,0x2
/*  f165674:	00c1001a */ 	div	$zero,$a2,$at
/*  f165678:	44839000 */ 	mtc1	$v1,$f18
/*  f16567c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f165680:	c4241fc0 */ 	lwc1	$f4,0x1fc0($at)
/*  f165684:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f165688:	3c017f1b */ 	lui	$at,0x7f1b
/*  f16568c:	c4281fc4 */ 	lwc1	$f8,0x1fc4($at)
/*  f165690:	00003012 */ 	mflo	$a2
/*  f165694:	02602025 */ 	or	$a0,$s3,$zero
/*  f165698:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f16569c:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f1656a0:	46083000 */ 	add.s	$f0,$f6,$f8
/*  f1656a4:	44070000 */ 	mfc1	$a3,$f0
/*  f1656a8:	0fc4f5b8 */ 	jal	bviewRenderZoomBlur
/*  f1656ac:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f1656b0:	8e580460 */ 	lw	$t8,0x460($s2)
/*  f1656b4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1656b8:	c4301fc8 */ 	lwc1	$f16,0x1fc8($at)
/*  f1656bc:	44985000 */ 	mtc1	$t8,$f10
/*  f1656c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1656c4:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f1656c8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f1656cc:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f1656d0:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f1656d4:	46109102 */ 	mul.s	$f4,$f18,$f16
/*  f1656d8:	0fc2e348 */ 	jal	fadeDraw
/*  f1656dc:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f1656e0:	10000029 */ 	beqz	$zero,.NB0f165788
/*  f1656e4:	00409825 */ 	or	$s3,$v0,$zero
.NB0f1656e8:
/*  f1656e8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f1656ec:	01431023 */ 	subu	$v0,$t2,$v1
/*  f1656f0:	00023080 */ 	sll	$a2,$v0,0x2
/*  f1656f4:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f1656f8:	00063080 */ 	sll	$a2,$a2,0x2
/*  f1656fc:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f165700:	00063080 */ 	sll	$a2,$a2,0x2
/*  f165704:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f165708:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16570c:	00c1001a */ 	div	$zero,$a2,$at
/*  f165710:	44823000 */ 	mtc1	$v0,$f6
/*  f165714:	3c017f1b */ 	lui	$at,0x7f1b
/*  f165718:	c42a1fcc */ 	lwc1	$f10,0x1fcc($at)
/*  f16571c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f165720:	3c017f1b */ 	lui	$at,0x7f1b
/*  f165724:	c4301fd0 */ 	lwc1	$f16,0x1fd0($at)
/*  f165728:	00003012 */ 	mflo	$a2
/*  f16572c:	02602025 */ 	or	$a0,$s3,$zero
/*  f165730:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f165734:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f165738:	46109000 */ 	add.s	$f0,$f18,$f16
/*  f16573c:	44070000 */ 	mfc1	$a3,$f0
/*  f165740:	0fc4f5b8 */ 	jal	bviewRenderZoomBlur
/*  f165744:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f165748:	8e4e0460 */ 	lw	$t6,0x460($s2)
/*  f16574c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f165750:	44812000 */ 	mtc1	$at,$f4
/*  f165754:	448e3000 */ 	mtc1	$t6,$f6
/*  f165758:	3c017f1b */ 	lui	$at,0x7f1b
/*  f16575c:	c4321fd4 */ 	lwc1	$f18,0x1fd4($at)
/*  f165760:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f165764:	00402025 */ 	or	$a0,$v0,$zero
/*  f165768:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f16576c:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f165770:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f165774:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f165778:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f16577c:	0fc2e348 */ 	jal	fadeDraw
/*  f165780:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f165784:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165788:
/*  f165788:	8e4f028c */ 	lw	$t7,0x28c($s2)
/*  f16578c:	55e0000c */ 	bnezl	$t7,.NB0f1657c0
/*  f165790:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f165794:	8e4d0464 */ 	lw	$t5,0x464($s2)
/*  f165798:	51a00006 */ 	beqzl	$t5,.NB0f1657b4
/*  f16579c:	8e580460 */ 	lw	$t8,0x460($s2)
/*  f1657a0:	8e4c0460 */ 	lw	$t4,0x460($s2)
/*  f1657a4:	258b0001 */ 	addiu	$t3,$t4,0x1
/*  f1657a8:	10000004 */ 	beqz	$zero,.NB0f1657bc
/*  f1657ac:	ae4b0460 */ 	sw	$t3,0x460($s2)
/*  f1657b0:	8e580460 */ 	lw	$t8,0x460($s2)
.NB0f1657b4:
/*  f1657b4:	270affff */ 	addiu	$t2,$t8,-1
/*  f1657b8:	ae4a0460 */ 	sw	$t2,0x460($s2)
.NB0f1657bc:
/*  f1657bc:	8e430460 */ 	lw	$v1,0x460($s2)
.NB0f1657c0:
/*  f1657c0:	2861001f */ 	slti	$at,$v1,0x1f
/*  f1657c4:	14200004 */ 	bnez	$at,.NB0f1657d8
/*  f1657c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1657cc:	2403001e */ 	addiu	$v1,$zero,0x1e
/*  f1657d0:	10000005 */ 	beqz	$zero,.NB0f1657e8
/*  f1657d4:	ae430460 */ 	sw	$v1,0x460($s2)
.NB0f1657d8:
/*  f1657d8:	04630004 */ 	bgezl	$v1,.NB0f1657ec
/*  f1657dc:	28610010 */ 	slti	$at,$v1,0x10
/*  f1657e0:	ae400460 */ 	sw	$zero,0x460($s2)
/*  f1657e4:	00001825 */ 	or	$v1,$zero,$zero
.NB0f1657e8:
/*  f1657e8:	28610010 */ 	slti	$at,$v1,0x10
.NB0f1657ec:
/*  f1657ec:	14200003 */ 	bnez	$at,.NB0f1657fc
/*  f1657f0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1657f4:	10000002 */ 	beqz	$zero,.NB0f165800
/*  f1657f8:	ae4e0468 */ 	sw	$t6,0x468($s2)
.NB0f1657fc:
/*  f1657fc:	ae400468 */ 	sw	$zero,0x468($s2)
.NB0f165800:
/*  f165800:	52c00009 */ 	beqzl	$s6,.NB0f165828
/*  f165804:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f165808:	0fc50cd0 */ 	jal	bviewClearBlur
/*  f16580c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165810:	02602025 */ 	or	$a0,$s3,$zero
/*  f165814:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f165818:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f16581c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f165820:	00409825 */ 	or	$s3,$v0,$zero
/*  f165824:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
.NB0f165828:
/*  f165828:	24010006 */ 	addiu	$at,$zero,0x6
/*  f16582c:	15e10031 */ 	bne	$t7,$at,.NB0f1658f4
/*  f165830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165834:	0fc2e143 */ 	jal	cutsceneGetBlurFrac
/*  f165838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16583c:	44803000 */ 	mtc1	$zero,$f6
/*  f165840:	3c01437f */ 	lui	$at,0x437f
/*  f165844:	4600303c */ 	c.lt.s	$f6,$f0
/*  f165848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16584c:	45000029 */ 	bc1f	.NB0f1658f4
/*  f165850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165854:	44812000 */ 	mtc1	$at,$f4
/*  f165858:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16585c:	3c014f00 */ 	lui	$at,0x4f00
/*  f165860:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f165864:	02602025 */ 	or	$a0,$s3,$zero
/*  f165868:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f16586c:	444df800 */ 	cfc1	$t5,$31
/*  f165870:	44c6f800 */ 	ctc1	$a2,$31
/*  f165874:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165878:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f16587c:	4446f800 */ 	cfc1	$a2,$31
/*  f165880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165884:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f165888:	50c00013 */ 	beqzl	$a2,.NB0f1658d8
/*  f16588c:	44065000 */ 	mfc1	$a2,$f10
/*  f165890:	44815000 */ 	mtc1	$at,$f10
/*  f165894:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f165898:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f16589c:	44c6f800 */ 	ctc1	$a2,$31
/*  f1658a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658a4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f1658a8:	4446f800 */ 	cfc1	$a2,$31
/*  f1658ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658b0:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f1658b4:	14c00005 */ 	bnez	$a2,.NB0f1658cc
/*  f1658b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658bc:	44065000 */ 	mfc1	$a2,$f10
/*  f1658c0:	3c018000 */ 	lui	$at,0x8000
/*  f1658c4:	10000007 */ 	beqz	$zero,.NB0f1658e4
/*  f1658c8:	00c13025 */ 	or	$a2,$a2,$at
.NB0f1658cc:
/*  f1658cc:	10000005 */ 	beqz	$zero,.NB0f1658e4
/*  f1658d0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1658d4:	44065000 */ 	mfc1	$a2,$f10
.NB0f1658d8:
/*  f1658d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658dc:	04c0fffb */ 	bltz	$a2,.NB0f1658cc
/*  f1658e0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1658e4:
/*  f1658e4:	44cdf800 */ 	ctc1	$t5,$31
/*  f1658e8:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f1658ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658f0:	00409825 */ 	or	$s3,$v0,$zero
.NB0f1658f4:
/*  f1658f4:	0fc466b7 */ 	jal	debugGetMotionBlur
/*  f1658f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f165900:	14410006 */ 	bne	$v0,$at,.NB0f16591c
/*  f165904:	02602025 */ 	or	$a0,$s3,$zero
/*  f165908:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f16590c:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f165910:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f165914:	10000014 */ 	beqz	$zero,.NB0f165968
/*  f165918:	00409825 */ 	or	$s3,$v0,$zero
.NB0f16591c:
/*  f16591c:	0fc466b7 */ 	jal	debugGetMotionBlur
/*  f165920:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165924:	24010002 */ 	addiu	$at,$zero,0x2
/*  f165928:	14410006 */ 	bne	$v0,$at,.NB0f165944
/*  f16592c:	02602025 */ 	or	$a0,$s3,$zero
/*  f165930:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f165934:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f165938:	240600c0 */ 	addiu	$a2,$zero,0xc0
/*  f16593c:	1000000a */ 	beqz	$zero,.NB0f165968
/*  f165940:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165944:
/*  f165944:	0fc466b7 */ 	jal	debugGetMotionBlur
/*  f165948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16594c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f165950:	14410005 */ 	bne	$v0,$at,.NB0f165968
/*  f165954:	02602025 */ 	or	$a0,$s3,$zero
/*  f165958:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f16595c:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f165960:	240600e6 */ 	addiu	$a2,$zero,0xe6
/*  f165964:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165968:
/*  f165968:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16596c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f165970:	92031bfc */ 	lbu	$v1,0x1bfc($s0)
/*  f165974:	1860003b */ 	blez	$v1,.NB0f165a64
/*  f165978:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16597c:	14610002 */ 	bne	$v1,$at,.NB0f165988
/*  f165980:	00008825 */ 	or	$s1,$zero,$zero
/*  f165984:	241100ff */ 	addiu	$s1,$zero,0xff
.NB0f165988:
/*  f165988:	56e30009 */ 	bnel	$s7,$v1,.NB0f1659b0
/*  f16598c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f165990:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f165994:	28410010 */ 	slti	$at,$v0,0x10
/*  f165998:	50200005 */ 	beqzl	$at,.NB0f1659b0
/*  f16599c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1659a0:	00028823 */ 	negu	$s1,$v0
/*  f1659a4:	00116100 */ 	sll	$t4,$s1,0x4
/*  f1659a8:	259100f0 */ 	addiu	$s1,$t4,0xf0
/*  f1659ac:	24010002 */ 	addiu	$at,$zero,0x2
.NB0f1659b0:
/*  f1659b0:	1461000b */ 	bne	$v1,$at,.NB0f1659e0
/*  f1659b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1659b8:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f1659bc:	28410021 */ 	slti	$at,$v0,0x21
/*  f1659c0:	54200004 */ 	bnezl	$at,.NB0f1659d4
/*  f1659c4:	24010030 */ 	addiu	$at,$zero,0x30
/*  f1659c8:	00028900 */ 	sll	$s1,$v0,0x4
/*  f1659cc:	2631fe00 */ 	addiu	$s1,$s1,-512
/*  f1659d0:	24010030 */ 	addiu	$at,$zero,0x30
.NB0f1659d4:
/*  f1659d4:	14410002 */ 	bne	$v0,$at,.NB0f1659e0
/*  f1659d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1659dc:	241100ff */ 	addiu	$s1,$zero,0xff
.NB0f1659e0:
/*  f1659e0:	12200020 */ 	beqz	$s1,.NB0f165a64
/*  f1659e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1659e8:	0fc5374a */ 	jal	func0f153628
/*  f1659ec:	02602025 */ 	or	$a0,$s3,$zero
/*  f1659f0:	0c002fb5 */ 	jal	viGetViewLeft
/*  f1659f4:	00409825 */ 	or	$s3,$v0,$zero
/*  f1659f8:	0c002fb9 */ 	jal	viGetViewTop
/*  f1659fc:	a7a20072 */ 	sh	$v0,0x72($sp)
/*  f165a00:	0c002fb5 */ 	jal	viGetViewLeft
/*  f165a04:	a7a20074 */ 	sh	$v0,0x74($sp)
/*  f165a08:	0c002f97 */ 	jal	viGetViewWidth
/*  f165a0c:	a7a20076 */ 	sh	$v0,0x76($sp)
/*  f165a10:	0c002fb9 */ 	jal	viGetViewTop
/*  f165a14:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f165a18:	00028400 */ 	sll	$s0,$v0,0x10
/*  f165a1c:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f165a20:	0c002f9b */ 	jal	viGetViewHeight
/*  f165a24:	01608025 */ 	or	$s0,$t3,$zero
/*  f165a28:	87b8008e */ 	lh	$t8,0x8e($sp)
/*  f165a2c:	87aa0076 */ 	lh	$t2,0x76($sp)
/*  f165a30:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f165a34:	02217025 */ 	or	$t6,$s1,$at
/*  f165a38:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f165a3c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f165a40:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f165a44:	02602025 */ 	or	$a0,$s3,$zero
/*  f165a48:	87a50072 */ 	lh	$a1,0x72($sp)
/*  f165a4c:	87a60074 */ 	lh	$a2,0x74($sp)
/*  f165a50:	0fc53824 */ 	jal	func0f153a34
/*  f165a54:	030a3821 */ 	addu	$a3,$t8,$t2
/*  f165a58:	0fc537a0 */ 	jal	func0f153780
/*  f165a5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f165a60:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165a64:
/*  f165a64:	0fc58ba8 */ 	jal	lvRenderFade
/*  f165a68:	02602025 */ 	or	$a0,$s3,$zero
/*  f165a6c:	0fc5ff45 */ 	jal	func0f185774
/*  f165a70:	00402025 */ 	or	$a0,$v0,$zero
/*  f165a74:	3c0f8009 */ 	lui	$t7,0x8009
/*  f165a78:	91efaf74 */ 	lbu	$t7,-0x508c($t7)
/*  f165a7c:	00409825 */ 	or	$s3,$v0,$zero
/*  f165a80:	11e00004 */ 	beqz	$t7,.NB0f165a94
/*  f165a84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165a88:	0fc673dc */ 	jal	frRenderHud
/*  f165a8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f165a90:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165a94:
/*  f165a94:	0fc46697 */ 	jal	debug0f11ee88
/*  f165a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165a9c:	54400016 */ 	bnezl	$v0,.NB0f165af8
/*  f165aa0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165aa4:	0fc4669a */ 	jal	debug0f11ee90
/*  f165aa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165aac:	54400012 */ 	bnezl	$v0,.NB0f165af8
/*  f165ab0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165ab4:	0fc466a6 */ 	jal	debug0f11eea8
/*  f165ab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165abc:	5440000e */ 	bnezl	$v0,.NB0f165af8
/*  f165ac0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165ac4:	0fc466f0 */ 	jal	debug0f11ef80
/*  f165ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165acc:	5440000a */ 	bnezl	$v0,.NB0f165af8
/*  f165ad0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165ad4:	0fc466ed */ 	jal	debug0f11ef78
/*  f165ad8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165adc:	54400006 */ 	bnezl	$v0,.NB0f165af8
/*  f165ae0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165ae4:	0fc46673 */ 	jal	debug0f11ee40
/*  f165ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165aec:	1040002c */ 	beqz	$v0,.NB0f165ba0
/*  f165af0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165af4:	8e4d0284 */ 	lw	$t5,0x284($s2)
.NB0f165af8:
/*  f165af8:	00001825 */ 	or	$v1,$zero,$zero
/*  f165afc:	27a200c8 */ 	addiu	$v0,$sp,0xc8
/*  f165b00:	8dac0014 */ 	lw	$t4,0x14($t5)
/*  f165b04:	a7b4009e */ 	sh	$s4,0x9e($sp)
/*  f165b08:	27b0009c */ 	addiu	$s0,$sp,0x9c
/*  f165b0c:	a7ac009c */ 	sh	$t4,0x9c($sp)
/*  f165b10:	87ab009c */ 	lh	$t3,0x9c($sp)
/*  f165b14:	528b0009 */ 	beql	$s4,$t3,.NB0f165b3c
/*  f165b18:	00035040 */ 	sll	$t2,$v1,0x1
/*  f165b1c:	86040000 */ 	lh	$a0,0x0($s0)
.NB0f165b20:
/*  f165b20:	a4440000 */ 	sh	$a0,0x0($v0)
/*  f165b24:	86040002 */ 	lh	$a0,0x2($s0)
/*  f165b28:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f165b2c:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f165b30:	1684fffb */ 	bne	$s4,$a0,.NB0f165b20
/*  f165b34:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f165b38:	00035040 */ 	sll	$t2,$v1,0x1
.NB0f165b3c:
/*  f165b3c:	03cac821 */ 	addu	$t9,$s8,$t2
/*  f165b40:	a7340000 */ 	sh	$s4,0x0($t9)
/*  f165b44:	87ae009c */ 	lh	$t6,0x9c($sp)
/*  f165b48:	27b0009c */ 	addiu	$s0,$sp,0x9c
/*  f165b4c:	128e000d */ 	beq	$s4,$t6,.NB0f165b84
/*  f165b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165b54:	86040000 */ 	lh	$a0,0x0($s0)
/*  f165b58:	02a02825 */ 	or	$a1,$s5,$zero
.NB0f165b5c:
/*  f165b5c:	0fc57b6a */ 	jal	roomGetNeighbours
/*  f165b60:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f165b64:	02a02025 */ 	or	$a0,$s5,$zero
/*  f165b68:	03c02825 */ 	or	$a1,$s8,$zero
/*  f165b6c:	0fc19290 */ 	jal	roomsAppend
/*  f165b70:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f165b74:	86040002 */ 	lh	$a0,0x2($s0)
/*  f165b78:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f165b7c:	5684fff7 */ 	bnel	$s4,$a0,.NB0f165b5c
/*  f165b80:	02a02825 */ 	or	$a1,$s5,$zero
.NB0f165b84:
/*  f165b84:	0fc466ed */ 	jal	debug0f11ef78
/*  f165b88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165b8c:	10400004 */ 	beqz	$v0,.NB0f165ba0
/*  f165b90:	02602025 */ 	or	$a0,$s3,$zero
/*  f165b94:	0fc1307a */ 	jal	func0f04c1e8nb
/*  f165b98:	03c02825 */ 	or	$a1,$s8,$zero
/*  f165b9c:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165ba0:
/*  f165ba0:	0fc48846 */ 	jal	func0f1274d8
/*  f165ba4:	02602025 */ 	or	$a0,$s3,$zero
/*  f165ba8:	0fc3f30d */ 	jal	amRender
/*  f165bac:	00402025 */ 	or	$a0,$v0,$zero
/*  f165bb0:	3c013f80 */ 	lui	$at,0x3f80
/*  f165bb4:	44816000 */ 	mtc1	$at,$f12
/*  f165bb8:	0c005db6 */ 	jal	func00016748
/*  f165bbc:	00409825 */ 	or	$s3,$v0,$zero
/*  f165bc0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165bc4:	8dac1c50 */ 	lw	$t4,0x1c50($t5)
/*  f165bc8:	000c5fc2 */ 	srl	$t3,$t4,0x1f
/*  f165bcc:	51600005 */ 	beqzl	$t3,.NB0f165be4
/*  f165bd0:	8e580288 */ 	lw	$t8,0x288($s2)
/*  f165bd4:	0fc3e0e0 */ 	jal	func0f0fbc30
/*  f165bd8:	02602025 */ 	or	$a0,$s3,$zero
/*  f165bdc:	00409825 */ 	or	$s3,$v0,$zero
/*  f165be0:	8e580288 */ 	lw	$t8,0x288($s2)
.NB0f165be4:
/*  f165be4:	0c005db6 */ 	jal	func00016748
/*  f165be8:	c70c0074 */ 	lwc1	$f12,0x74($t8)
/*  f165bec:	8e4a0314 */ 	lw	$t2,0x314($s2)
/*  f165bf0:	51400005 */ 	beqzl	$t2,.NB0f165c08
/*  f165bf4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f165bf8:	0fc60ecb */ 	jal	mpRenderModalText
/*  f165bfc:	02602025 */ 	or	$a0,$s3,$zero
/*  f165c00:	00409825 */ 	or	$s3,$v0,$zero
/*  f165c04:	8e590284 */ 	lw	$t9,0x284($s2)
.NB0f165c08:
/*  f165c08:	932e19b3 */ 	lbu	$t6,0x19b3($t9)
/*  f165c0c:	11c00003 */ 	beqz	$t6,.NB0f165c1c
/*  f165c10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165c14:	0fc2d40c */ 	jal	currentPlayerStartNewLife
/*  f165c18:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f165c1c:
/*  f165c1c:	0fc4dc13 */ 	jal	func0f13c54c
/*  f165c20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165c24:	8e4f0298 */ 	lw	$t7,0x298($s2)
/*  f165c28:	3c0c8007 */ 	lui	$t4,0x8007
/*  f165c2c:	05e10004 */ 	bgez	$t7,.NB0f165c40
/*  f165c30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165c34:	8e4d029c */ 	lw	$t5,0x29c($s2)
/*  f165c38:	05a20012 */ 	bltzl	$t5,.NB0f165c84
/*  f165c3c:	8fb00064 */ 	lw	$s0,0x64($sp)
.NB0f165c40:
/*  f165c40:	8d8c2e24 */ 	lw	$t4,0x2e24($t4)
/*  f165c44:	3c0b8006 */ 	lui	$t3,0x8006
/*  f165c48:	11800004 */ 	beqz	$t4,.NB0f165c5c
/*  f165c4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165c50:	8d6bf2f0 */ 	lw	$t3,-0xd10($t3)
/*  f165c54:	51600007 */ 	beqzl	$t3,.NB0f165c74
/*  f165c58:	8e58028c */ 	lw	$t8,0x28c($s2)
.NB0f165c5c:
/*  f165c5c:	0fc3e4d2 */ 	jal	menuGetRoot
/*  f165c60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165c64:	24010009 */ 	addiu	$at,$zero,0x9
/*  f165c68:	54410006 */ 	bnel	$v0,$at,.NB0f165c84
/*  f165c6c:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f165c70:	8e58028c */ 	lw	$t8,0x28c($s2)
.NB0f165c74:
/*  f165c74:	53000003 */ 	beqzl	$t8,.NB0f165c84
/*  f165c78:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f165c7c:	8fb30188 */ 	lw	$s3,0x188($sp)
/*  f165c80:	8fb00064 */ 	lw	$s0,0x64($sp)
.NB0f165c84:
/*  f165c84:	8faa018c */ 	lw	$t2,0x18c($sp)
/*  f165c88:	560afa91 */ 	bnel	$s0,$t2,.NB0f1646d0
/*  f165c8c:	8fab0184 */ 	lw	$t3,0x184($sp)
.NB0f165c90:
/*  f165c90:	825904d3 */ 	lb	$t9,0x4d3($s2)
.NB0f165c94:
/*  f165c94:	3c014080 */ 	lui	$at,0x4080
/*  f165c98:	4481a000 */ 	mtc1	$at,$f20
/*  f165c9c:	13200013 */ 	beqz	$t9,.NB0f165cec
/*  f165ca0:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f165ca4:	824e04d6 */ 	lb	$t6,0x4d6($s2)
/*  f165ca8:	51c00011 */ 	beqzl	$t6,.NB0f165cf0
/*  f165cac:	824b04d3 */ 	lb	$t3,0x4d3($s2)
/*  f165cb0:	824f04d7 */ 	lb	$t7,0x4d7($s2)
/*  f165cb4:	a24004d3 */ 	sb	$zero,0x4d3($s2)
/*  f165cb8:	a24004d6 */ 	sb	$zero,0x4d6($s2)
/*  f165cbc:	51e00004 */ 	beqzl	$t7,.NB0f165cd0
/*  f165cc0:	824d04d4 */ 	lb	$t5,0x4d4($s2)
/*  f165cc4:	a25404d4 */ 	sb	$s4,0x4d4($s2)
/*  f165cc8:	a24004d5 */ 	sb	$zero,0x4d5($s2)
/*  f165ccc:	824d04d4 */ 	lb	$t5,0x4d4($s2)
.NB0f165cd0:
/*  f165cd0:	05a30007 */ 	bgezl	$t5,.NB0f165cf0
/*  f165cd4:	824b04d3 */ 	lb	$t3,0x4d3($s2)
/*  f165cd8:	824c04d5 */ 	lb	$t4,0x4d5($s2)
/*  f165cdc:	5d800004 */ 	bgtzl	$t4,.NB0f165cf0
/*  f165ce0:	824b04d3 */ 	lb	$t3,0x4d3($s2)
/*  f165ce4:	0c003c56 */ 	jal	mainSetStageNum
/*  f165ce8:	2404005a */ 	addiu	$a0,$zero,0x5a
.NB0f165cec:
/*  f165cec:	824b04d3 */ 	lb	$t3,0x4d3($s2)
.NB0f165cf0:
/*  f165cf0:	5560004a */ 	bnezl	$t3,.NB0f165e1c
/*  f165cf4:	02608025 */ 	or	$s0,$s3,$zero
/*  f165cf8:	825804d4 */ 	lb	$t8,0x4d4($s2)
/*  f165cfc:	07020047 */ 	bltzl	$t8,.NB0f165e1c
/*  f165d00:	02608025 */ 	or	$s0,$s3,$zero
/*  f165d04:	824a04d5 */ 	lb	$t2,0x4d5($s2)
/*  f165d08:	59400044 */ 	blezl	$t2,.NB0f165e1c
/*  f165d0c:	02608025 */ 	or	$s0,$s3,$zero
/*  f165d10:	0fc36d1e */ 	jal	hudmsgRemoveAll
/*  f165d14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165d18:	825904d4 */ 	lb	$t9,0x4d4($s2)
/*  f165d1c:	2415000c */ 	addiu	$s5,$zero,0xc
/*  f165d20:	3c118007 */ 	lui	$s1,0x8007
/*  f165d24:	03350019 */ 	multu	$t9,$s5
/*  f165d28:	26315c38 */ 	addiu	$s1,$s1,0x5c38
/*  f165d2c:	00007012 */ 	mflo	$t6
/*  f165d30:	022e7821 */ 	addu	$t7,$s1,$t6
/*  f165d34:	8ded0004 */ 	lw	$t5,0x4($t7)
/*  f165d38:	0c003c59 */ 	jal	mainGetStageNum
/*  f165d3c:	a24d04d2 */ 	sb	$t5,0x4d2($s2)
/*  f165d40:	824c04d4 */ 	lb	$t4,0x4d4($s2)
/*  f165d44:	3c10800a */ 	lui	$s0,0x800a
/*  f165d48:	261027a8 */ 	addiu	$s0,$s0,0x27a8
/*  f165d4c:	01950019 */ 	multu	$t4,$s5
/*  f165d50:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f165d54:	00005812 */ 	mflo	$t3
/*  f165d58:	022bc021 */ 	addu	$t8,$s1,$t3
/*  f165d5c:	870a0000 */ 	lh	$t2,0x0($t8)
/*  f165d60:	504a0023 */ 	beql	$v0,$t2,.NB0f165df0
/*  f165d64:	824c04d5 */ 	lb	$t4,0x4d5($s2)
/*  f165d68:	92190003 */ 	lbu	$t9,0x3($s0)
/*  f165d6c:	ae400314 */ 	sw	$zero,0x314($s2)
/*  f165d70:	ae400318 */ 	sw	$zero,0x318($s2)
/*  f165d74:	332fff7f */ 	andi	$t7,$t9,0xff7f
/*  f165d78:	a20f0003 */ 	sb	$t7,0x3($s0)
/*  f165d7c:	31ed00bf */ 	andi	$t5,$t7,0xbf
/*  f165d80:	ae400294 */ 	sw	$zero,0x294($s2)
/*  f165d84:	ae540298 */ 	sw	$s4,0x298($s2)
/*  f165d88:	ae54029c */ 	sw	$s4,0x29c($s2)
/*  f165d8c:	0fc06821 */ 	jal	setNumPlayers
/*  f165d90:	a20d0003 */ 	sb	$t5,0x3($s0)
/*  f165d94:	0fc06945 */ 	jal	titleSetNextMode
/*  f165d98:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f165d9c:	920c0000 */ 	lbu	$t4,0x0($s0)
/*  f165da0:	00002025 */ 	or	$a0,$zero,$zero
/*  f165da4:	318bff01 */ 	andi	$t3,$t4,0xff01
/*  f165da8:	0fc59ed6 */ 	jal	lvSetDifficulty
/*  f165dac:	a20b0000 */ 	sb	$t3,0x0($s0)
/*  f165db0:	825804d4 */ 	lb	$t8,0x4d4($s2)
/*  f165db4:	03150019 */ 	multu	$t8,$s5
/*  f165db8:	00005012 */ 	mflo	$t2
/*  f165dbc:	022a1021 */ 	addu	$v0,$s1,$t2
/*  f165dc0:	84590002 */ 	lh	$t9,0x2($v0)
/*  f165dc4:	84440000 */ 	lh	$a0,0x0($v0)
/*  f165dc8:	a2190002 */ 	sb	$t9,0x2($s0)
/*  f165dcc:	0fc06ba1 */ 	jal	titleSetNextStage
/*  f165dd0:	a2040001 */ 	sb	$a0,0x1($s0)
/*  f165dd4:	824e04d4 */ 	lb	$t6,0x4d4($s2)
/*  f165dd8:	01d50019 */ 	multu	$t6,$s5
/*  f165ddc:	00007812 */ 	mflo	$t7
/*  f165de0:	022f6821 */ 	addu	$t5,$s1,$t7
/*  f165de4:	0c003c56 */ 	jal	mainSetStageNum
/*  f165de8:	85a40000 */ 	lh	$a0,0x0($t5)
/*  f165dec:	824c04d5 */ 	lb	$t4,0x4d5($s2)
.NB0f165df0:
/*  f165df0:	258bffff */ 	addiu	$t3,$t4,-1
/*  f165df4:	a24b04d5 */ 	sb	$t3,0x4d5($s2)
/*  f165df8:	825804d5 */ 	lb	$t8,0x4d5($s2)
/*  f165dfc:	5b000006 */ 	blezl	$t8,.NB0f165e18
/*  f165e00:	a25404d4 */ 	sb	$s4,0x4d4($s2)
/*  f165e04:	824a04d4 */ 	lb	$t2,0x4d4($s2)
/*  f165e08:	25590001 */ 	addiu	$t9,$t2,0x1
/*  f165e0c:	10000002 */ 	beqz	$zero,.NB0f165e18
/*  f165e10:	a25904d4 */ 	sb	$t9,0x4d4($s2)
/*  f165e14:	a25404d4 */ 	sb	$s4,0x4d4($s2)
.NB0f165e18:
/*  f165e18:	02608025 */ 	or	$s0,$s3,$zero
.NB0f165e1c:
/*  f165e1c:	3c0eed00 */ 	lui	$t6,0xed00
/*  f165e20:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f165e24:	0c002f77 */ 	jal	viGetWidth
/*  f165e28:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f165e2c:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f165e30:	00117c03 */ 	sra	$t7,$s1,0x10
/*  f165e34:	0c002f7b */ 	jal	viGetHeight
/*  f165e38:	01e08825 */ 	or	$s1,$t7,$zero
/*  f165e3c:	44829000 */ 	mtc1	$v0,$f18
/*  f165e40:	44914000 */ 	mtc1	$s1,$f8
/*  f165e44:	3c03800b */ 	lui	$v1,0x800b
/*  f165e48:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f165e4c:	3c04800b */ 	lui	$a0,0x800b
/*  f165e50:	2484ee30 */ 	addiu	$a0,$a0,-4560
/*  f165e54:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f165e58:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f165e5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165e60:	46145482 */ 	mul.s	$f18,$f10,$f20
/*  f165e64:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f165e68:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f165e6c:	440c2000 */ 	mfc1	$t4,$f4
/*  f165e70:	440a8000 */ 	mfc1	$t2,$f16
/*  f165e74:	318b0fff */ 	andi	$t3,$t4,0xfff
/*  f165e78:	31590fff */ 	andi	$t9,$t2,0xfff
/*  f165e7c:	00197300 */ 	sll	$t6,$t9,0xc
/*  f165e80:	016e7825 */ 	or	$t7,$t3,$t6
/*  f165e84:	ae0f0004 */ 	sw	$t7,0x4($s0)
/*  f165e88:	9063ee50 */ 	lbu	$v1,-0x11b0($v1)
/*  f165e8c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f165e90:	008d6021 */ 	addu	$t4,$a0,$t5
/*  f165e94:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f165e98:	00035080 */ 	sll	$t2,$v1,0x2
/*  f165e9c:	008ac821 */ 	addu	$t9,$a0,$t2
/*  f165ea0:	0278082b */ 	sltu	$at,$s3,$t8
/*  f165ea4:	14200005 */ 	bnez	$at,.NB0f165ebc
/*  f165ea8:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f165eac:	8f2b0004 */ 	lw	$t3,0x4($t9)
/*  f165eb0:	0173082b */ 	sltu	$at,$t3,$s3
/*  f165eb4:	50200006 */ 	beqzl	$at,.NB0f165ed0
/*  f165eb8:	8fbf0054 */ 	lw	$ra,0x54($sp)
.NB0f165ebc:
/*  f165ebc:	0c003074 */ 	jal	func0000c1d0nb
/*  f165ec0:	24841e78 */ 	addiu	$a0,$a0,0x1e78
/*  f165ec4:	240e0045 */ 	addiu	$t6,$zero,0x45
/*  f165ec8:	a00e0000 */ 	sb	$t6,0x0($zero)
/*  f165ecc:	8fbf0054 */ 	lw	$ra,0x54($sp)
.NB0f165ed0:
/*  f165ed0:	02601025 */ 	or	$v0,$s3,$zero
/*  f165ed4:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f165ed8:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f165edc:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f165ee0:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f165ee4:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f165ee8:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f165eec:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f165ef0:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f165ef4:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f165ef8:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f165efc:	03e00008 */ 	jr	$ra
/*  f165f00:	27bd01f0 */ 	addiu	$sp,$sp,0x1f0
);
#endif

#if VERSION >= VERSION_PAL_FINAL
u32 var800840a4 = 0;
u32 var800840a8 = 100;
u32 var800840ac = 0;
u32 g_CutsceneTime240_60 = 0;
#else
u32 g_CutsceneTime240_60 = 0;
u32 var800840a8 = 0;
u32 var800840ac = 0;
u32 var800840b0 = 0;
#endif

u32 var800840b4 = 0;
u32 var800840b8 = 0;
u32 var800840bc = 0;

void lvUpdateSoloHandicaps(void)
{
	if (g_Vars.antiplayernum >= 0) {
		if (g_Difficulty == DIFF_A) {
			g_CameraWaitMultiplier = 2;
			var8006994c = 2;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 2;
			g_EnemyAccuracyScale = 0.5f;
			g_DamageReceivedScale = 0.35f;
			g_DamageDealtScale = 4;
			g_ExplosionDamageReceivedScale = 0.25f;
			var80069880 = 1.5f;
			g_AmmoMultiplier = 3;
			var80062cac = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CameraWaitMultiplier = 2;
			var8006994c = 1.5f;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 1.5f;
			g_EnemyAccuracyScale = 0.6f;
			g_DamageReceivedScale = 0.5f;
			g_DamageDealtScale = 3;
			g_ExplosionDamageReceivedScale = 0.25f;
			var80069880 = 1.1f;
			g_AmmoMultiplier = 2.5f;
			var80062cac = 0.5f;
		} else {
			g_CameraWaitMultiplier = 2;
			var8006994c = 1;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 1;
			g_EnemyAccuracyScale = 0.7f;
			g_DamageReceivedScale = 0.65f;
			g_DamageDealtScale = 2;
			g_ExplosionDamageReceivedScale = 0.25f;
			var80069880 = 0.75f;
			g_AmmoMultiplier = 2;
			var80062cac = 1;
		}
	} else if (g_Vars.coopplayernum >= 0) {
		if (g_Difficulty == DIFF_A) {
			g_CameraWaitMultiplier = 2;
			var8006994c = 2;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 2;
			g_EnemyAccuracyScale = 0.6f;
			g_DamageReceivedScale = 0.5f;
			g_DamageDealtScale = 2;
			g_ExplosionDamageReceivedScale = 0.25f;
			var80069880 = 1.5f;
			g_AmmoMultiplier = 2;
			var80062cac = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 0.75f;
			var80069954 = 1;
			var80069958 = 1;
			g_EnemyAccuracyScale = 0.75f;
			g_DamageReceivedScale = 1;
			g_DamageDealtScale = 1;
			g_ExplosionDamageReceivedScale = 1;
			var80069880 = g_Jpn ? 1.1f : 0.75f;
			g_AmmoMultiplier = 1.5f;
			var80062cac = 0.5f;
		} else {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 1;
			var80069954 = 1.5f;
			var80069958 = 1;
			g_EnemyAccuracyScale = 1.5f;
			g_DamageReceivedScale = 1.5f;
			g_DamageDealtScale = 1;
			g_ExplosionDamageReceivedScale = 1.5f;
			var80069880 = g_Jpn ? 0.75f : 0.2f;
			g_AmmoMultiplier = 1;
			var80062cac = 1;
		}
	} else {
		if (g_Difficulty == DIFF_A) {
			f32 totalhealth;
			f32 frac = 1;

			if (g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
				totalhealth = currentPlayerGetHealthFrac() + currentPlayerGetShieldFrac();

				if (totalhealth <= 0.125f) {
					frac = 0.5f;
				} else {
					frac = 1;

					if (totalhealth <= 0.6f) {
						frac = (totalhealth - 0.125f) * 0.5f / 0.47500002384186f + 0.5f;
					}
				}
			}

			g_CameraWaitMultiplier = 2;
			var8006994c = 2;
			var80069950 = 0.5f * frac;
			var80069954 = 0.5f * frac;
			var80069958 = 2;
			g_EnemyAccuracyScale = 0.6f;
			g_DamageReceivedScale = 0.5f * frac;
			g_DamageDealtScale = 2;
			g_ExplosionDamageReceivedScale = 0.25f * frac;
			var80069880 = 1.5f;
			g_AmmoMultiplier = 2;
			var80062cac = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 0.75f;
			var80069954 = 0.75f;
			var80069958 = 1;
			g_EnemyAccuracyScale = 0.8f;
			g_DamageReceivedScale = 0.6f;
			g_DamageDealtScale = 1;
			g_ExplosionDamageReceivedScale = 0.75f;
			var80069880 = g_Jpn ? 1.1f : 0.75f;
			g_AmmoMultiplier = 1.5f;
			var80062cac = 0.5f;
		} else if (g_Difficulty == DIFF_PA) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 1;
			var80069954 = 1;
			var80069958 = 1;
			g_EnemyAccuracyScale = 1.175f;
			g_DamageReceivedScale = 1;
			g_DamageDealtScale = 1;
			g_ExplosionDamageReceivedScale = 1;
			var80069880 = g_Jpn ? 0.75f : 0.2f;
			g_AmmoMultiplier = 1;
			var80062cac = 1;
		} else if (g_Difficulty == DIFF_PD) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 1;
			var80069954 = 1;
			var80069958 = 1;
			g_EnemyAccuracyScale = 1.1f;
			g_DamageReceivedScale = 1;
			g_DamageDealtScale = 1;
			g_ExplosionDamageReceivedScale = 1;
			var80069880 = 1;
			g_AmmoMultiplier = 1;
			var80062cac = 1;
		}
	}
}

#if PIRACYCHECKS
s32 sub54321(s32 value)
{
#if PAL
	return value - 6661;
#else
	return value - 54321;
#endif
}
#endif

void lvUpdateCutsceneTime(void)
{
	if (g_Vars.in_cutscene) {
		g_CutsceneTime240_60 += g_Vars.lvupdate240_60;
		return;
	}

	g_CutsceneTime240_60 = 0;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel lvGetSlowMotionType
/*  f16b854:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f16b858:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16b85c:	3c04b000 */ 	lui	$a0,0xb000
/*  f16b860:	0fc5ae00 */ 	jal	sub54321
/*  f16b864:	3484de8d */ 	ori	$a0,$a0,0x1d45
/*  f16b868:	3c041741 */ 	lui	$a0,0x330
/*  f16b86c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f16b870:	0fc5ae00 */ 	jal	sub54321
/*  f16b874:	3484d42a */ 	ori	$a0,$a0,0xe225
/*  f16b878:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f16b87c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f16b880:	0c013994 */ 	jal	osPiReadIo
/*  f16b884:	27a50028 */ 	addiu	$a1,$sp,0x28
/*  f16b888:	8fae0028 */ 	lw	$t6,0x28($sp)
/*  f16b88c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f16b890:	3c058006 */ 	lui	$a1,%hi(rspbootTextStart)
/*  f16b894:	24a29fe0 */ 	addiu	$v0,$a1,%lo(rspbootTextStart)
/*  f16b898:	11cf000d */ 	beq	$t6,$t7,.L0f16b8d0
/*  f16b89c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x318)
/*  f16b8a0:	3c188006 */ 	lui	$t8,%hi(rspbootTextStart+0x1)
/*  f16b8a4:	24431000 */ 	addiu	$v1,$v0,0x1000
/*  f16b8a8:	27189fe1 */ 	addiu	$t8,$t8,%lo(rspbootTextStart+0x1)
/*  f16b8ac:	0078082b */ 	sltu	$at,$v1,$t8
/*  f16b8b0:	14200007 */ 	bnez	$at,.L0f16b8d0
/*  f16b8b4:	00000000 */ 	nop
.L0f16b8b8:
/*  f16b8b8:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f16b8bc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f16b8c0:	0043082b */ 	sltu	$at,$v0,$v1
/*  f16b8c4:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f16b8c8:	1420fffb */ 	bnez	$at,.L0f16b8b8
/*  f16b8cc:	ac48fffc */ 	sw	$t0,-0x4($v0)
.L0f16b8d0:
/*  f16b8d0:	8d29a2d8 */ 	lw	$t1,%lo(g_Vars+0x318)($t1)
/*  f16b8d4:	3c02800b */ 	lui	$v0,%hi(g_MpSetup+0xc)
/*  f16b8d8:	1120000b */ 	beqz	$t1,.L0f16b908
/*  f16b8dc:	00000000 */ 	nop
/*  f16b8e0:	8c42cb94 */ 	lw	$v0,%lo(g_MpSetup+0xc)($v0)
/*  f16b8e4:	304a0040 */ 	andi	$t2,$v0,0x40
/*  f16b8e8:	11400003 */ 	beqz	$t2,.L0f16b8f8
/*  f16b8ec:	304b0080 */ 	andi	$t3,$v0,0x80
/*  f16b8f0:	1000001a */ 	b	.L0f16b95c
/*  f16b8f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16b8f8:
/*  f16b8f8:	51600018 */ 	beqzl	$t3,.L0f16b95c
/*  f16b8fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f16b900:	10000016 */ 	b	.L0f16b95c
/*  f16b904:	24020002 */ 	addiu	$v0,$zero,0x2
.L0f16b908:
/*  f16b908:	0fc41b99 */ 	jal	cheatIsActive
/*  f16b90c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f16b910:	10400003 */ 	beqz	$v0,.L0f16b920
/*  f16b914:	00000000 */ 	nop
/*  f16b918:	10000010 */ 	b	.L0f16b95c
/*  f16b91c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16b920:
/*  f16b920:	0fc47b9c */ 	jal	debugGetSlowMotion
/*  f16b924:	00000000 */ 	nop
/*  f16b928:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16b92c:	14410003 */ 	bne	$v0,$at,.L0f16b93c
/*  f16b930:	00000000 */ 	nop
/*  f16b934:	10000009 */ 	b	.L0f16b95c
/*  f16b938:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16b93c:
/*  f16b93c:	0fc47b9c */ 	jal	debugGetSlowMotion
/*  f16b940:	00000000 */ 	nop
/*  f16b944:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16b948:	54410004 */ 	bnel	$v0,$at,.L0f16b95c
/*  f16b94c:	00001025 */ 	or	$v0,$zero,$zero
/*  f16b950:	10000002 */ 	b	.L0f16b95c
/*  f16b954:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f16b958:	00001025 */ 	or	$v0,$zero,$zero
.L0f16b95c:
/*  f16b95c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16b960:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f16b964:	03e00008 */ 	jr	$ra
/*  f16b968:	00000000 */ 	nop
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel lvGetSlowMotionType
/*  f16b854:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f16b858:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16b85c:	3c04b000 */ 	lui	$a0,0xb000
/*  f16b860:	0fc5ae00 */ 	jal	sub54321
/*  f16b864:	3484de8d */ 	ori	$a0,$a0,0xde8d
/*  f16b868:	3c041741 */ 	lui	$a0,0x1741
/*  f16b86c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f16b870:	0fc5ae00 */ 	jal	sub54321
/*  f16b874:	3484d42a */ 	ori	$a0,$a0,0xd42a
/*  f16b878:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f16b87c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f16b880:	0c013994 */ 	jal	osPiReadIo
/*  f16b884:	27a50028 */ 	addiu	$a1,$sp,0x28
/*  f16b888:	8fae0028 */ 	lw	$t6,0x28($sp)
/*  f16b88c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f16b890:	3c058006 */ 	lui	$a1,%hi(rspbootTextStart)
/*  f16b894:	24a29fe0 */ 	addiu	$v0,$a1,%lo(rspbootTextStart)
/*  f16b898:	11cf000d */ 	beq	$t6,$t7,.L0f16b8d0
/*  f16b89c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x318)
/*  f16b8a0:	3c188006 */ 	lui	$t8,%hi(rspbootTextStart+0x1)
/*  f16b8a4:	24431000 */ 	addiu	$v1,$v0,0x1000
/*  f16b8a8:	27189fe1 */ 	addiu	$t8,$t8,%lo(rspbootTextStart+0x1)
/*  f16b8ac:	0078082b */ 	sltu	$at,$v1,$t8
/*  f16b8b0:	14200007 */ 	bnez	$at,.L0f16b8d0
/*  f16b8b4:	00000000 */ 	nop
.L0f16b8b8:
/*  f16b8b8:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f16b8bc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f16b8c0:	0043082b */ 	sltu	$at,$v0,$v1
/*  f16b8c4:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f16b8c8:	1420fffb */ 	bnez	$at,.L0f16b8b8
/*  f16b8cc:	ac48fffc */ 	sw	$t0,-0x4($v0)
.L0f16b8d0:
/*  f16b8d0:	8d29a2d8 */ 	lw	$t1,%lo(g_Vars+0x318)($t1)
/*  f16b8d4:	3c02800b */ 	lui	$v0,%hi(g_MpSetup+0xc)
/*  f16b8d8:	1120000b */ 	beqz	$t1,.L0f16b908
/*  f16b8dc:	00000000 */ 	nop
/*  f16b8e0:	8c42cb94 */ 	lw	$v0,%lo(g_MpSetup+0xc)($v0)
/*  f16b8e4:	304a0040 */ 	andi	$t2,$v0,0x40
/*  f16b8e8:	11400003 */ 	beqz	$t2,.L0f16b8f8
/*  f16b8ec:	304b0080 */ 	andi	$t3,$v0,0x80
/*  f16b8f0:	1000001a */ 	b	.L0f16b95c
/*  f16b8f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16b8f8:
/*  f16b8f8:	51600018 */ 	beqzl	$t3,.L0f16b95c
/*  f16b8fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f16b900:	10000016 */ 	b	.L0f16b95c
/*  f16b904:	24020002 */ 	addiu	$v0,$zero,0x2
.L0f16b908:
/*  f16b908:	0fc41b99 */ 	jal	cheatIsActive
/*  f16b90c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f16b910:	10400003 */ 	beqz	$v0,.L0f16b920
/*  f16b914:	00000000 */ 	nop
/*  f16b918:	10000010 */ 	b	.L0f16b95c
/*  f16b91c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16b920:
/*  f16b920:	0fc47b9c */ 	jal	debugGetSlowMotion
/*  f16b924:	00000000 */ 	nop
/*  f16b928:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16b92c:	14410003 */ 	bne	$v0,$at,.L0f16b93c
/*  f16b930:	00000000 */ 	nop
/*  f16b934:	10000009 */ 	b	.L0f16b95c
/*  f16b938:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16b93c:
/*  f16b93c:	0fc47b9c */ 	jal	debugGetSlowMotion
/*  f16b940:	00000000 */ 	nop
/*  f16b944:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16b948:	54410004 */ 	bnel	$v0,$at,.L0f16b95c
/*  f16b94c:	00001025 */ 	or	$v0,$zero,$zero
/*  f16b950:	10000002 */ 	b	.L0f16b95c
/*  f16b954:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f16b958:	00001025 */ 	or	$v0,$zero,$zero
.L0f16b95c:
/*  f16b95c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16b960:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f16b964:	03e00008 */ 	jr	$ra
/*  f16b968:	00000000 */ 	nop
);
#else
// Can't match the antipiracy part (used in ntsc-1.0 and above)
s32 lvGetSlowMotionType(void)
{
#if PIRACYCHECKS
	u32 addr = sub54321(0xb0000a5c + 54321);
	u32 actual;
	u32 expected = sub54321(0x1740fff9);
	osPiReadIo(addr, &actual);

	if (actual != expected) {
		extern u32 rspbootTextStart;
		extern u32 rspbootStartPlusOne;
		u32 *ptr = &rspbootStart;
		u32 *end = &ptr[1024];

		if (!(end < &rspbootStartPlusOne)) {
			do {
				*ptr += 8;
				ptr++;
			} while (ptr < end);
		}
	}
#endif

	if (g_Vars.normmplayerisrunning) {
		if (g_MpSetup.options & MPOPTION_SLOWMOTION_ON) {
			return SLOWMOTION_ON;
		}
		if (g_MpSetup.options & MPOPTION_SLOWMOTION_SMART) {
			return SLOWMOTION_SMART;
		}
	} else {
		if (cheatIsActive(CHEAT_SLOMO)) {
			return SLOWMOTION_ON;
		}
		if (debugGetSlowMotion() == SLOWMOTION_ON) {
			return SLOWMOTION_ON;
		}
		if (debugGetSlowMotion() == SLOWMOTION_SMART) {
			return SLOWMOTION_SMART;
		}
	}

	return SLOWMOTION_OFF;
}
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel lvTick
.late_rodata
glabel var7f1b8ed0pf
.word 0x3f99999a
.text
/*  f16c718:	27bdfd70 */ 	addiu	$sp,$sp,-656
/*  f16c71c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f16c720:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f16c724:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f16c728:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f16c72c:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f16c730:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f16c734:	0fc5b6cc */ 	jal	lvCheckPauseStateChanged
/*  f16c738:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f16c73c:	3c14800a */ 	lui	$s4,0x800a
/*  f16c740:	2694a510 */ 	addiu	$s4,$s4,-23280
/*  f16c744:	968e04e4 */ 	lhu	$t6,0x4e4($s4)
/*  f16c748:	51c00004 */ 	beqzl	$t6,.PF0f16c75c
/*  f16c74c:	8e8204d8 */ 	lw	$v0,0x4d8($s4)
/*  f16c750:	0fc47412 */ 	jal	func0f11c54c
/*  f16c754:	00000000 */ 	nop
/*  f16c758:	8e8204d8 */ 	lw	$v0,0x4d8($s4)
.PF0f16c75c:
/*  f16c75c:	18400003 */ 	blez	$v0,.PF0f16c76c
/*  f16c760:	244fffff */ 	addiu	$t7,$v0,-1
/*  f16c764:	10000015 */ 	b	.PF0f16c7bc
/*  f16c768:	ae8f04d8 */ 	sw	$t7,0x4d8($s4)
.PF0f16c76c:
/*  f16c76c:	14400013 */ 	bnez	$v0,.PF0f16c7bc
/*  f16c770:	00000000 */ 	nop
/*  f16c774:	0c004db2 */ 	jal	joy00013938
/*  f16c778:	00000000 */ 	nop
/*  f16c77c:	8e8204b4 */ 	lw	$v0,0x4b4($s4)
/*  f16c780:	2401005a */ 	li	$at,0x5a
/*  f16c784:	10410007 */ 	beq	$v0,$at,.PF0f16c7a4
/*  f16c788:	2401005b */ 	li	$at,0x5b
/*  f16c78c:	10410005 */ 	beq	$v0,$at,.PF0f16c7a4
/*  f16c790:	2401005c */ 	li	$at,0x5c
/*  f16c794:	10410003 */ 	beq	$v0,$at,.PF0f16c7a4
/*  f16c798:	2401005d */ 	li	$at,0x5d
/*  f16c79c:	14410003 */ 	bne	$v0,$at,.PF0f16c7ac
/*  f16c7a0:	2418001f */ 	li	$t8,0x1f
.PF0f16c7a4:
/*  f16c7a4:	10000003 */ 	b	.PF0f16c7b4
/*  f16c7a8:	a28004d1 */ 	sb	$zero,0x4d1($s4)
.PF0f16c7ac:
/*  f16c7ac:	0fc47a8d */ 	jal	func0f11df38
/*  f16c7b0:	a29804d1 */ 	sb	$t8,0x4d1($s4)
.PF0f16c7b4:
/*  f16c7b4:	2415ffff */ 	li	$s5,-1
/*  f16c7b8:	ae9504d8 */ 	sw	$s5,0x4d8($s4)
.PF0f16c7bc:
/*  f16c7bc:	3c198009 */ 	lui	$t9,0x8009
/*  f16c7c0:	93391040 */ 	lbu	$t9,0x1040($t9)
/*  f16c7c4:	24100001 */ 	li	$s0,0x1
/*  f16c7c8:	2415ffff */ 	li	$s5,-1
/*  f16c7cc:	56190004 */ 	bnel	$s0,$t9,.PF0f16c7e0
/*  f16c7d0:	8e8c006c */ 	lw	$t4,0x6c($s4)
/*  f16c7d4:	0fc66f10 */ 	jal	func0f19ab40
/*  f16c7d8:	00000000 */ 	nop
/*  f16c7dc:	8e8c006c */ 	lw	$t4,0x6c($s4)
.PF0f16c7e0:
/*  f16c7e0:	00003825 */ 	move	$a3,$zero
/*  f16c7e4:	51800004 */ 	beqzl	$t4,.PF0f16c7f8
/*  f16c7e8:	00002825 */ 	move	$a1,$zero
/*  f16c7ec:	10000002 */ 	b	.PF0f16c7f8
/*  f16c7f0:	02002825 */ 	move	$a1,$s0
/*  f16c7f4:	00002825 */ 	move	$a1,$zero
.PF0f16c7f8:
/*  f16c7f8:	8e8d0068 */ 	lw	$t5,0x68($s4)
/*  f16c7fc:	51a00004 */ 	beqzl	$t5,.PF0f16c810
/*  f16c800:	00002025 */ 	move	$a0,$zero
/*  f16c804:	10000002 */ 	b	.PF0f16c810
/*  f16c808:	02002025 */ 	move	$a0,$s0
/*  f16c80c:	00002025 */ 	move	$a0,$zero
.PF0f16c810:
/*  f16c810:	8e8e0064 */ 	lw	$t6,0x64($s4)
/*  f16c814:	51c00004 */ 	beqzl	$t6,.PF0f16c828
/*  f16c818:	00001825 */ 	move	$v1,$zero
/*  f16c81c:	10000002 */ 	b	.PF0f16c828
/*  f16c820:	02001825 */ 	move	$v1,$s0
/*  f16c824:	00001825 */ 	move	$v1,$zero
.PF0f16c828:
/*  f16c828:	8e8f0070 */ 	lw	$t7,0x70($s4)
/*  f16c82c:	51e00004 */ 	beqzl	$t7,.PF0f16c840
/*  f16c830:	00001025 */ 	move	$v0,$zero
/*  f16c834:	10000002 */ 	b	.PF0f16c840
/*  f16c838:	02001025 */ 	move	$v0,$s0
/*  f16c83c:	00001025 */ 	move	$v0,$zero
.PF0f16c840:
/*  f16c840:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f16c844:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f16c848:	03256021 */ 	addu	$t4,$t9,$a1
/*  f16c84c:	19800026 */ 	blez	$t4,.PF0f16c8e8
/*  f16c850:	00076880 */ 	sll	$t5,$a3,0x2
/*  f16c854:	028d3021 */ 	addu	$a2,$s4,$t5
/*  f16c858:	8cce0064 */ 	lw	$t6,0x64($a2)
.PF0f16c85c:
/*  f16c85c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f16c860:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f16c864:	adc01490 */ 	sw	$zero,0x1490($t6)
/*  f16c868:	8ccf0060 */ 	lw	$t7,0x60($a2)
/*  f16c86c:	00002825 */ 	move	$a1,$zero
/*  f16c870:	00002025 */ 	move	$a0,$zero
/*  f16c874:	ade00cec */ 	sw	$zero,0xcec($t7)
/*  f16c878:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f16c87c:	00001825 */ 	move	$v1,$zero
/*  f16c880:	00001025 */ 	move	$v0,$zero
/*  f16c884:	13000003 */ 	beqz	$t8,.PF0f16c894
/*  f16c888:	00000000 */ 	nop
/*  f16c88c:	10000001 */ 	b	.PF0f16c894
/*  f16c890:	02002825 */ 	move	$a1,$s0
.PF0f16c894:
/*  f16c894:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f16c898:	13200003 */ 	beqz	$t9,.PF0f16c8a8
/*  f16c89c:	00000000 */ 	nop
/*  f16c8a0:	10000001 */ 	b	.PF0f16c8a8
/*  f16c8a4:	02002025 */ 	move	$a0,$s0
.PF0f16c8a8:
/*  f16c8a8:	8e8c0064 */ 	lw	$t4,0x64($s4)
/*  f16c8ac:	11800003 */ 	beqz	$t4,.PF0f16c8bc
/*  f16c8b0:	00000000 */ 	nop
/*  f16c8b4:	10000001 */ 	b	.PF0f16c8bc
/*  f16c8b8:	02001825 */ 	move	$v1,$s0
.PF0f16c8bc:
/*  f16c8bc:	8e8d0070 */ 	lw	$t5,0x70($s4)
/*  f16c8c0:	11a00003 */ 	beqz	$t5,.PF0f16c8d0
/*  f16c8c4:	00000000 */ 	nop
/*  f16c8c8:	10000001 */ 	b	.PF0f16c8d0
/*  f16c8cc:	02001025 */ 	move	$v0,$s0
.PF0f16c8d0:
/*  f16c8d0:	00437021 */ 	addu	$t6,$v0,$v1
/*  f16c8d4:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f16c8d8:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f16c8dc:	00f8082a */ 	slt	$at,$a3,$t8
/*  f16c8e0:	5420ffde */ 	bnezl	$at,.PF0f16c85c
/*  f16c8e4:	8cce0064 */ 	lw	$t6,0x64($a2)
.PF0f16c8e8:
/*  f16c8e8:	0fc5b6f7 */ 	jal	lvIsPaused
/*  f16c8ec:	00000000 */ 	nop
/*  f16c8f0:	10400003 */ 	beqz	$v0,.PF0f16c900
/*  f16c8f4:	00000000 */ 	nop
/*  f16c8f8:	1000011a */ 	b	.PF0f16cd64
/*  f16c8fc:	ae800034 */ 	sw	$zero,0x34($s4)
.PF0f16c900:
/*  f16c900:	0fc629b9 */ 	jal	mpIsPaused
/*  f16c904:	00000000 */ 	nop
/*  f16c908:	10400044 */ 	beqz	$v0,.PF0f16ca1c
/*  f16c90c:	00000000 */ 	nop
/*  f16c910:	8e99006c */ 	lw	$t9,0x6c($s4)
/*  f16c914:	ae800034 */ 	sw	$zero,0x34($s4)
/*  f16c918:	00003825 */ 	move	$a3,$zero
/*  f16c91c:	13200003 */ 	beqz	$t9,.PF0f16c92c
/*  f16c920:	00002825 */ 	move	$a1,$zero
/*  f16c924:	10000001 */ 	b	.PF0f16c92c
/*  f16c928:	24050001 */ 	li	$a1,0x1
.PF0f16c92c:
/*  f16c92c:	8e8c0068 */ 	lw	$t4,0x68($s4)
/*  f16c930:	00002025 */ 	move	$a0,$zero
/*  f16c934:	00001825 */ 	move	$v1,$zero
/*  f16c938:	11800003 */ 	beqz	$t4,.PF0f16c948
/*  f16c93c:	00001025 */ 	move	$v0,$zero
/*  f16c940:	10000001 */ 	b	.PF0f16c948
/*  f16c944:	24040001 */ 	li	$a0,0x1
.PF0f16c948:
/*  f16c948:	8e8d0064 */ 	lw	$t5,0x64($s4)
/*  f16c94c:	00076080 */ 	sll	$t4,$a3,0x2
/*  f16c950:	028c3021 */ 	addu	$a2,$s4,$t4
/*  f16c954:	11a00003 */ 	beqz	$t5,.PF0f16c964
/*  f16c958:	3c08efff */ 	lui	$t0,0xefff
/*  f16c95c:	10000001 */ 	b	.PF0f16c964
/*  f16c960:	24030001 */ 	li	$v1,0x1
.PF0f16c964:
/*  f16c964:	8e8e0070 */ 	lw	$t6,0x70($s4)
/*  f16c968:	3508efff */ 	ori	$t0,$t0,0xefff
/*  f16c96c:	11c00003 */ 	beqz	$t6,.PF0f16c97c
/*  f16c970:	00000000 */ 	nop
/*  f16c974:	10000001 */ 	b	.PF0f16c97c
/*  f16c978:	24020001 */ 	li	$v0,0x1
.PF0f16c97c:
/*  f16c97c:	00437821 */ 	addu	$t7,$v0,$v1
/*  f16c980:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f16c984:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f16c988:	5b2000f7 */ 	blezl	$t9,.PF0f16cd68
/*  f16c98c:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16c990:	8ccd0064 */ 	lw	$t5,0x64($a2)
.PF0f16c994:
/*  f16c994:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f16c998:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f16c99c:	ada81c40 */ 	sw	$t0,0x1c40($t5)
/*  f16c9a0:	8e8e006c */ 	lw	$t6,0x6c($s4)
/*  f16c9a4:	00002825 */ 	move	$a1,$zero
/*  f16c9a8:	00002025 */ 	move	$a0,$zero
/*  f16c9ac:	11c00003 */ 	beqz	$t6,.PF0f16c9bc
/*  f16c9b0:	00001825 */ 	move	$v1,$zero
/*  f16c9b4:	10000001 */ 	b	.PF0f16c9bc
/*  f16c9b8:	24050001 */ 	li	$a1,0x1
.PF0f16c9bc:
/*  f16c9bc:	8e8f0068 */ 	lw	$t7,0x68($s4)
/*  f16c9c0:	00001025 */ 	move	$v0,$zero
/*  f16c9c4:	11e00003 */ 	beqz	$t7,.PF0f16c9d4
/*  f16c9c8:	00000000 */ 	nop
/*  f16c9cc:	10000001 */ 	b	.PF0f16c9d4
/*  f16c9d0:	24040001 */ 	li	$a0,0x1
.PF0f16c9d4:
/*  f16c9d4:	8e980064 */ 	lw	$t8,0x64($s4)
/*  f16c9d8:	13000003 */ 	beqz	$t8,.PF0f16c9e8
/*  f16c9dc:	00000000 */ 	nop
/*  f16c9e0:	10000001 */ 	b	.PF0f16c9e8
/*  f16c9e4:	24030001 */ 	li	$v1,0x1
.PF0f16c9e8:
/*  f16c9e8:	8e990070 */ 	lw	$t9,0x70($s4)
/*  f16c9ec:	13200003 */ 	beqz	$t9,.PF0f16c9fc
/*  f16c9f0:	00000000 */ 	nop
/*  f16c9f4:	10000001 */ 	b	.PF0f16c9fc
/*  f16c9f8:	24020001 */ 	li	$v0,0x1
.PF0f16c9fc:
/*  f16c9fc:	00436021 */ 	addu	$t4,$v0,$v1
/*  f16ca00:	01846821 */ 	addu	$t5,$t4,$a0
/*  f16ca04:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f16ca08:	00ee082a */ 	slt	$at,$a3,$t6
/*  f16ca0c:	5420ffe1 */ 	bnezl	$at,.PF0f16c994
/*  f16ca10:	8ccd0064 */ 	lw	$t5,0x64($a2)
/*  f16ca14:	100000d4 */ 	b	.PF0f16cd68
/*  f16ca18:	8e830034 */ 	lw	$v1,0x34($s4)
.PF0f16ca1c:
/*  f16ca1c:	0fc5b180 */ 	jal	lvGetSlowMotionType
/*  f16ca20:	00000000 */ 	nop
/*  f16ca24:	8e8f0040 */ 	lw	$t7,0x40($s4)
/*  f16ca28:	24010002 */ 	li	$at,0x2
/*  f16ca2c:	1450000f */ 	bne	$v0,$s0,.PF0f16ca6c
/*  f16ca30:	ae8f0034 */ 	sw	$t7,0x34($s4)
/*  f16ca34:	8e980468 */ 	lw	$t8,0x468($s4)
/*  f16ca38:	53000005 */ 	beqzl	$t8,.PF0f16ca50
/*  f16ca3c:	8e8c0034 */ 	lw	$t4,0x34($s4)
/*  f16ca40:	8e9904cc */ 	lw	$t9,0x4cc($s4)
/*  f16ca44:	13200007 */ 	beqz	$t9,.PF0f16ca64
/*  f16ca48:	00000000 */ 	nop
/*  f16ca4c:	8e8c0034 */ 	lw	$t4,0x34($s4)
.PF0f16ca50:
/*  f16ca50:	24150004 */ 	li	$s5,0x4
/*  f16ca54:	29810005 */ 	slti	$at,$t4,0x5
/*  f16ca58:	14200002 */ 	bnez	$at,.PF0f16ca64
/*  f16ca5c:	00000000 */ 	nop
/*  f16ca60:	ae950034 */ 	sw	$s5,0x34($s4)
.PF0f16ca64:
/*  f16ca64:	100000c0 */ 	b	.PF0f16cd68
/*  f16ca68:	8e830034 */ 	lw	$v1,0x34($s4)
.PF0f16ca6c:
/*  f16ca6c:	544100b2 */ 	bnel	$v0,$at,.PF0f16cd38
/*  f16ca70:	8e8f0468 */ 	lw	$t7,0x468($s4)
/*  f16ca74:	8e8d0468 */ 	lw	$t5,0x468($s4)
/*  f16ca78:	51a00005 */ 	beqzl	$t5,.PF0f16ca90
/*  f16ca7c:	8e8f0314 */ 	lw	$t7,0x314($s4)
/*  f16ca80:	8e8e04cc */ 	lw	$t6,0x4cc($s4)
/*  f16ca84:	11c000a9 */ 	beqz	$t6,.PF0f16cd2c
/*  f16ca88:	00000000 */ 	nop
/*  f16ca8c:	8e8f0314 */ 	lw	$t7,0x314($s4)
.PF0f16ca90:
/*  f16ca90:	51e000a1 */ 	beqzl	$t7,.PF0f16cd18
/*  f16ca94:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f16ca98:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f16ca9c:	00009025 */ 	move	$s2,$zero
/*  f16caa0:	00009825 */ 	move	$s3,$zero
/*  f16caa4:	11200003 */ 	beqz	$t1,.PF0f16cab4
/*  f16caa8:	00002825 */ 	move	$a1,$zero
/*  f16caac:	10000001 */ 	b	.PF0f16cab4
/*  f16cab0:	24050001 */ 	li	$a1,0x1
.PF0f16cab4:
/*  f16cab4:	8e870068 */ 	lw	$a3,0x68($s4)
/*  f16cab8:	00002025 */ 	move	$a0,$zero
/*  f16cabc:	00001825 */ 	move	$v1,$zero
/*  f16cac0:	10e00003 */ 	beqz	$a3,.PF0f16cad0
/*  f16cac4:	00001025 */ 	move	$v0,$zero
/*  f16cac8:	10000001 */ 	b	.PF0f16cad0
/*  f16cacc:	24040001 */ 	li	$a0,0x1
.PF0f16cad0:
/*  f16cad0:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f16cad4:	00136880 */ 	sll	$t5,$s3,0x2
/*  f16cad8:	028d7021 */ 	addu	$t6,$s4,$t5
/*  f16cadc:	11000003 */ 	beqz	$t0,.PF0f16caec
/*  f16cae0:	00000000 */ 	nop
/*  f16cae4:	10000001 */ 	b	.PF0f16caec
/*  f16cae8:	24030001 */ 	li	$v1,0x1
.PF0f16caec:
/*  f16caec:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f16caf0:	10c00003 */ 	beqz	$a2,.PF0f16cb00
/*  f16caf4:	00000000 */ 	nop
/*  f16caf8:	10000001 */ 	b	.PF0f16cb00
/*  f16cafc:	24020001 */ 	li	$v0,0x1
.PF0f16cb00:
/*  f16cb00:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f16cb04:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f16cb08:	03256021 */ 	addu	$t4,$t9,$a1
/*  f16cb0c:	1980006f */ 	blez	$t4,.PF0f16cccc
/*  f16cb10:	00000000 */ 	nop
/*  f16cb14:	afae004c */ 	sw	$t6,0x4c($sp)
/*  f16cb18:	8faf004c */ 	lw	$t7,0x4c($sp)
.PF0f16cb1c:
/*  f16cb1c:	8de20064 */ 	lw	$v0,0x64($t7)
/*  f16cb20:	8c5800d8 */ 	lw	$t8,0xd8($v0)
/*  f16cb24:	5700004e */ 	bnezl	$t8,.PF0f16cc60
/*  f16cb28:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f16cb2c:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f16cb30:	84790028 */ 	lh	$t9,0x28($v1)
/*  f16cb34:	24630028 */ 	addiu	$v1,$v1,0x28
/*  f16cb38:	52b90049 */ 	beql	$s5,$t9,.PF0f16cc60
/*  f16cb3c:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f16cb40:	16400046 */ 	bnez	$s2,.PF0f16cc5c
/*  f16cb44:	00006040 */ 	sll	$t4,$zero,0x1
/*  f16cb48:	006c8821 */ 	addu	$s1,$v1,$t4
.PF0f16cb4c:
/*  f16cb4c:	11200003 */ 	beqz	$t1,.PF0f16cb5c
/*  f16cb50:	00008025 */ 	move	$s0,$zero
/*  f16cb54:	10000002 */ 	b	.PF0f16cb60
/*  f16cb58:	24050001 */ 	li	$a1,0x1
.PF0f16cb5c:
/*  f16cb5c:	00002825 */ 	move	$a1,$zero
.PF0f16cb60:
/*  f16cb60:	10e00003 */ 	beqz	$a3,.PF0f16cb70
/*  f16cb64:	00002025 */ 	move	$a0,$zero
/*  f16cb68:	10000001 */ 	b	.PF0f16cb70
/*  f16cb6c:	24040001 */ 	li	$a0,0x1
.PF0f16cb70:
/*  f16cb70:	11000003 */ 	beqz	$t0,.PF0f16cb80
/*  f16cb74:	00001825 */ 	move	$v1,$zero
/*  f16cb78:	10000001 */ 	b	.PF0f16cb80
/*  f16cb7c:	24030001 */ 	li	$v1,0x1
.PF0f16cb80:
/*  f16cb80:	10c00003 */ 	beqz	$a2,.PF0f16cb90
/*  f16cb84:	00001025 */ 	move	$v0,$zero
/*  f16cb88:	10000001 */ 	b	.PF0f16cb90
/*  f16cb8c:	24020001 */ 	li	$v0,0x1
.PF0f16cb90:
/*  f16cb90:	00436821 */ 	addu	$t5,$v0,$v1
/*  f16cb94:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f16cb98:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f16cb9c:	59e0002a */ 	blezl	$t7,.PF0f16cc48
/*  f16cba0:	86390002 */ 	lh	$t9,0x2($s1)
.PF0f16cba4:
/*  f16cba4:	1270000c */ 	beq	$s3,$s0,.PF0f16cbd8
/*  f16cba8:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f16cbac:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f16cbb0:	8f2c0064 */ 	lw	$t4,0x64($t9)
/*  f16cbb4:	02002825 */ 	move	$a1,$s0
/*  f16cbb8:	8d8d00d8 */ 	lw	$t5,0xd8($t4)
/*  f16cbbc:	55a00007 */ 	bnezl	$t5,.PF0f16cbdc
/*  f16cbc0:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f16cbc4:	0fc579c8 */ 	jal	roomIsVisibleByPlayer
/*  f16cbc8:	86240000 */ 	lh	$a0,0x0($s1)
/*  f16cbcc:	50400003 */ 	beqzl	$v0,.PF0f16cbdc
/*  f16cbd0:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f16cbd4:	24120001 */ 	li	$s2,0x1
.PF0f16cbd8:
/*  f16cbd8:	8e89006c */ 	lw	$t1,0x6c($s4)
.PF0f16cbdc:
/*  f16cbdc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16cbe0:	8e870068 */ 	lw	$a3,0x68($s4)
/*  f16cbe4:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f16cbe8:	11200003 */ 	beqz	$t1,.PF0f16cbf8
/*  f16cbec:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f16cbf0:	10000002 */ 	b	.PF0f16cbfc
/*  f16cbf4:	24050001 */ 	li	$a1,0x1
.PF0f16cbf8:
/*  f16cbf8:	00002825 */ 	move	$a1,$zero
.PF0f16cbfc:
/*  f16cbfc:	10e00003 */ 	beqz	$a3,.PF0f16cc0c
/*  f16cc00:	00002025 */ 	move	$a0,$zero
/*  f16cc04:	10000001 */ 	b	.PF0f16cc0c
/*  f16cc08:	24040001 */ 	li	$a0,0x1
.PF0f16cc0c:
/*  f16cc0c:	11000003 */ 	beqz	$t0,.PF0f16cc1c
/*  f16cc10:	00001825 */ 	move	$v1,$zero
/*  f16cc14:	10000001 */ 	b	.PF0f16cc1c
/*  f16cc18:	24030001 */ 	li	$v1,0x1
.PF0f16cc1c:
/*  f16cc1c:	10c00003 */ 	beqz	$a2,.PF0f16cc2c
/*  f16cc20:	00001025 */ 	move	$v0,$zero
/*  f16cc24:	10000001 */ 	b	.PF0f16cc2c
/*  f16cc28:	24020001 */ 	li	$v0,0x1
.PF0f16cc2c:
/*  f16cc2c:	00437021 */ 	addu	$t6,$v0,$v1
/*  f16cc30:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f16cc34:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f16cc38:	0218082a */ 	slt	$at,$s0,$t8
/*  f16cc3c:	1420ffd9 */ 	bnez	$at,.PF0f16cba4
/*  f16cc40:	00000000 */ 	nop
/*  f16cc44:	86390002 */ 	lh	$t9,0x2($s1)
.PF0f16cc48:
/*  f16cc48:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f16cc4c:	52b90004 */ 	beql	$s5,$t9,.PF0f16cc60
/*  f16cc50:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f16cc54:	1240ffbd */ 	beqz	$s2,.PF0f16cb4c
/*  f16cc58:	00000000 */ 	nop
.PF0f16cc5c:
/*  f16cc5c:	8fac004c */ 	lw	$t4,0x4c($sp)
.PF0f16cc60:
/*  f16cc60:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f16cc64:	00002825 */ 	move	$a1,$zero
/*  f16cc68:	258d0004 */ 	addiu	$t5,$t4,0x4
/*  f16cc6c:	11200003 */ 	beqz	$t1,.PF0f16cc7c
/*  f16cc70:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f16cc74:	10000001 */ 	b	.PF0f16cc7c
/*  f16cc78:	24050001 */ 	li	$a1,0x1
.PF0f16cc7c:
/*  f16cc7c:	10e00003 */ 	beqz	$a3,.PF0f16cc8c
/*  f16cc80:	00002025 */ 	move	$a0,$zero
/*  f16cc84:	10000001 */ 	b	.PF0f16cc8c
/*  f16cc88:	24040001 */ 	li	$a0,0x1
.PF0f16cc8c:
/*  f16cc8c:	11000003 */ 	beqz	$t0,.PF0f16cc9c
/*  f16cc90:	00001825 */ 	move	$v1,$zero
/*  f16cc94:	10000001 */ 	b	.PF0f16cc9c
/*  f16cc98:	24030001 */ 	li	$v1,0x1
.PF0f16cc9c:
/*  f16cc9c:	10c00003 */ 	beqz	$a2,.PF0f16ccac
/*  f16cca0:	00001025 */ 	move	$v0,$zero
/*  f16cca4:	10000001 */ 	b	.PF0f16ccac
/*  f16cca8:	24020001 */ 	li	$v0,0x1
.PF0f16ccac:
/*  f16ccac:	00437021 */ 	addu	$t6,$v0,$v1
/*  f16ccb0:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f16ccb4:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f16ccb8:	0278082a */ 	slt	$at,$s3,$t8
/*  f16ccbc:	10200003 */ 	beqz	$at,.PF0f16cccc
/*  f16ccc0:	00000000 */ 	nop
/*  f16ccc4:	5240ff95 */ 	beqzl	$s2,.PF0f16cb1c
/*  f16ccc8:	8faf004c */ 	lw	$t7,0x4c($sp)
.PF0f16cccc:
/*  f16cccc:	5240000a */ 	beqzl	$s2,.PF0f16ccf8
/*  f16ccd0:	8e8c0034 */ 	lw	$t4,0x34($s4)
/*  f16ccd4:	8e990034 */ 	lw	$t9,0x34($s4)
/*  f16ccd8:	24150004 */ 	li	$s5,0x4
/*  f16ccdc:	2b210005 */ 	slti	$at,$t9,0x5
/*  f16cce0:	14200002 */ 	bnez	$at,.PF0f16ccec
/*  f16cce4:	00000000 */ 	nop
/*  f16cce8:	ae950034 */ 	sw	$s5,0x34($s4)
.PF0f16ccec:
/*  f16ccec:	1000001e */ 	b	.PF0f16cd68
/*  f16ccf0:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16ccf4:	8e8c0034 */ 	lw	$t4,0x34($s4)
.PF0f16ccf8:
/*  f16ccf8:	240d0008 */ 	li	$t5,0x8
/*  f16ccfc:	29810009 */ 	slti	$at,$t4,0x9
/*  f16cd00:	14200002 */ 	bnez	$at,.PF0f16cd0c
/*  f16cd04:	00000000 */ 	nop
/*  f16cd08:	ae8d0034 */ 	sw	$t5,0x34($s4)
.PF0f16cd0c:
/*  f16cd0c:	10000016 */ 	b	.PF0f16cd68
/*  f16cd10:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16cd14:	8e8e0034 */ 	lw	$t6,0x34($s4)
.PF0f16cd18:
/*  f16cd18:	24150004 */ 	li	$s5,0x4
/*  f16cd1c:	29c10005 */ 	slti	$at,$t6,0x5
/*  f16cd20:	14200002 */ 	bnez	$at,.PF0f16cd2c
/*  f16cd24:	00000000 */ 	nop
/*  f16cd28:	ae950034 */ 	sw	$s5,0x34($s4)
.PF0f16cd2c:
/*  f16cd2c:	1000000e */ 	b	.PF0f16cd68
/*  f16cd30:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16cd34:	8e8f0468 */ 	lw	$t7,0x468($s4)
.PF0f16cd38:
/*  f16cd38:	51e0000b */ 	beqzl	$t7,.PF0f16cd68
/*  f16cd3c:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16cd40:	8e9804cc */ 	lw	$t8,0x4cc($s4)
/*  f16cd44:	57000008 */ 	bnezl	$t8,.PF0f16cd68
/*  f16cd48:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16cd4c:	8e990034 */ 	lw	$t9,0x34($s4)
/*  f16cd50:	24150004 */ 	li	$s5,0x4
/*  f16cd54:	2b210005 */ 	slti	$at,$t9,0x5
/*  f16cd58:	54200003 */ 	bnezl	$at,.PF0f16cd68
/*  f16cd5c:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16cd60:	ae950034 */ 	sw	$s5,0x34($s4)
.PF0f16cd64:
/*  f16cd64:	8e830034 */ 	lw	$v1,0x34($s4)
.PF0f16cd68:
/*  f16cd68:	8e8c003c */ 	lw	$t4,0x3c($s4)
/*  f16cd6c:	24150004 */ 	li	$s5,0x4
/*  f16cd70:	44832000 */ 	mtc1	$v1,$f4
/*  f16cd74:	006c6821 */ 	addu	$t5,$v1,$t4
/*  f16cd78:	ae8d0038 */ 	sw	$t5,0x38($s4)
/*  f16cd7c:	31ae0003 */ 	andi	$t6,$t5,0x3
/*  f16cd80:	000d7883 */ 	sra	$t7,$t5,0x2
/*  f16cd84:	ae8e003c */ 	sw	$t6,0x3c($s4)
/*  f16cd88:	18600004 */ 	blez	$v1,.PF0f16cd9c
/*  f16cd8c:	ae8f0038 */ 	sw	$t7,0x38($s4)
/*  f16cd90:	8e98000c */ 	lw	$t8,0xc($s4)
/*  f16cd94:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f16cd98:	ae99000c */ 	sw	$t9,0xc($s4)
.PF0f16cd9c:
/*  f16cd9c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16cda0:	3c013e80 */ 	lui	$at,0x3e80
/*  f16cda4:	44814000 */ 	mtc1	$at,$f8
/*  f16cda8:	8e8c0008 */ 	lw	$t4,0x8($s4)
/*  f16cdac:	8e8d0038 */ 	lw	$t5,0x38($s4)
/*  f16cdb0:	8e8f0030 */ 	lw	$t7,0x30($s4)
/*  f16cdb4:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f16cdb8:	c690004c */ 	lwc1	$f16,0x4c($s4)
/*  f16cdbc:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f16cdc0:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f16cdc4:	ae8e0008 */ 	sw	$t6,0x8($s4)
/*  f16cdc8:	ae980030 */ 	sw	$t8,0x30($s4)
/*  f16cdcc:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16cdd0:	e68a0044 */ 	swc1	$f10,0x44($s4)
/*  f16cdd4:	e6900050 */ 	swc1	$f16,0x50($s4)
/*  f16cdd8:	c4248ed0 */ 	lwc1	$f4,-0x7130($at)
/*  f16cddc:	c6920044 */ 	lwc1	$f18,0x44($s4)
/*  f16cde0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f16cde4:	0fc2b039 */ 	jal	bgunTickBoost
/*  f16cde8:	e686004c */ 	swc1	$f6,0x4c($s4)
/*  f16cdec:	0fc37e77 */ 	jal	hudmsgsTick
/*  f16cdf0:	00000000 */ 	nop
/*  f16cdf4:	00002025 */ 	move	$a0,$zero
/*  f16cdf8:	0c00536a */ 	jal	joyGetButtonsPressedThisFrame
/*  f16cdfc:	3405ffff */ 	li	$a1,0xffff
/*  f16ce00:	1440005c */ 	bnez	$v0,.PF0f16cf74
/*  f16ce04:	00000000 */ 	nop
/*  f16ce08:	0c0052e6 */ 	jal	joyGetStickX
/*  f16ce0c:	00002025 */ 	move	$a0,$zero
/*  f16ce10:	2841000b */ 	slti	$at,$v0,0xb
/*  f16ce14:	10200057 */ 	beqz	$at,.PF0f16cf74
/*  f16ce18:	00000000 */ 	nop
/*  f16ce1c:	0c0052e6 */ 	jal	joyGetStickX
/*  f16ce20:	00002025 */ 	move	$a0,$zero
/*  f16ce24:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16ce28:	14200052 */ 	bnez	$at,.PF0f16cf74
/*  f16ce2c:	00000000 */ 	nop
/*  f16ce30:	0c005310 */ 	jal	joyGetStickY
/*  f16ce34:	00002025 */ 	move	$a0,$zero
/*  f16ce38:	2841000b */ 	slti	$at,$v0,0xb
/*  f16ce3c:	1020004d */ 	beqz	$at,.PF0f16cf74
/*  f16ce40:	00000000 */ 	nop
/*  f16ce44:	0c005310 */ 	jal	joyGetStickY
/*  f16ce48:	00002025 */ 	move	$a0,$zero
/*  f16ce4c:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16ce50:	14200048 */ 	bnez	$at,.PF0f16cf74
/*  f16ce54:	24040001 */ 	li	$a0,0x1
/*  f16ce58:	0c00536a */ 	jal	joyGetButtonsPressedThisFrame
/*  f16ce5c:	3405ffff */ 	li	$a1,0xffff
/*  f16ce60:	14400044 */ 	bnez	$v0,.PF0f16cf74
/*  f16ce64:	00000000 */ 	nop
/*  f16ce68:	0c0052e6 */ 	jal	joyGetStickX
/*  f16ce6c:	24040001 */ 	li	$a0,0x1
/*  f16ce70:	2841000b */ 	slti	$at,$v0,0xb
/*  f16ce74:	1020003f */ 	beqz	$at,.PF0f16cf74
/*  f16ce78:	00000000 */ 	nop
/*  f16ce7c:	0c0052e6 */ 	jal	joyGetStickX
/*  f16ce80:	24040001 */ 	li	$a0,0x1
/*  f16ce84:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16ce88:	1420003a */ 	bnez	$at,.PF0f16cf74
/*  f16ce8c:	00000000 */ 	nop
/*  f16ce90:	0c005310 */ 	jal	joyGetStickY
/*  f16ce94:	24040001 */ 	li	$a0,0x1
/*  f16ce98:	2841000b */ 	slti	$at,$v0,0xb
/*  f16ce9c:	10200035 */ 	beqz	$at,.PF0f16cf74
/*  f16cea0:	00000000 */ 	nop
/*  f16cea4:	0c005310 */ 	jal	joyGetStickY
/*  f16cea8:	24040001 */ 	li	$a0,0x1
/*  f16ceac:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16ceb0:	14200030 */ 	bnez	$at,.PF0f16cf74
/*  f16ceb4:	24040002 */ 	li	$a0,0x2
/*  f16ceb8:	0c00536a */ 	jal	joyGetButtonsPressedThisFrame
/*  f16cebc:	3405ffff */ 	li	$a1,0xffff
/*  f16cec0:	1440002c */ 	bnez	$v0,.PF0f16cf74
/*  f16cec4:	00000000 */ 	nop
/*  f16cec8:	0c0052e6 */ 	jal	joyGetStickX
/*  f16cecc:	24040002 */ 	li	$a0,0x2
/*  f16ced0:	2841000b */ 	slti	$at,$v0,0xb
/*  f16ced4:	10200027 */ 	beqz	$at,.PF0f16cf74
/*  f16ced8:	00000000 */ 	nop
/*  f16cedc:	0c0052e6 */ 	jal	joyGetStickX
/*  f16cee0:	24040002 */ 	li	$a0,0x2
/*  f16cee4:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16cee8:	14200022 */ 	bnez	$at,.PF0f16cf74
/*  f16ceec:	00000000 */ 	nop
/*  f16cef0:	0c005310 */ 	jal	joyGetStickY
/*  f16cef4:	24040002 */ 	li	$a0,0x2
/*  f16cef8:	2841000b */ 	slti	$at,$v0,0xb
/*  f16cefc:	1020001d */ 	beqz	$at,.PF0f16cf74
/*  f16cf00:	00000000 */ 	nop
/*  f16cf04:	0c005310 */ 	jal	joyGetStickY
/*  f16cf08:	24040002 */ 	li	$a0,0x2
/*  f16cf0c:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16cf10:	14200018 */ 	bnez	$at,.PF0f16cf74
/*  f16cf14:	24040003 */ 	li	$a0,0x3
/*  f16cf18:	0c00536a */ 	jal	joyGetButtonsPressedThisFrame
/*  f16cf1c:	3405ffff */ 	li	$a1,0xffff
/*  f16cf20:	14400014 */ 	bnez	$v0,.PF0f16cf74
/*  f16cf24:	00000000 */ 	nop
/*  f16cf28:	0c0052e6 */ 	jal	joyGetStickX
/*  f16cf2c:	24040003 */ 	li	$a0,0x3
/*  f16cf30:	2841000b */ 	slti	$at,$v0,0xb
/*  f16cf34:	1020000f */ 	beqz	$at,.PF0f16cf74
/*  f16cf38:	00000000 */ 	nop
/*  f16cf3c:	0c0052e6 */ 	jal	joyGetStickX
/*  f16cf40:	24040003 */ 	li	$a0,0x3
/*  f16cf44:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16cf48:	1420000a */ 	bnez	$at,.PF0f16cf74
/*  f16cf4c:	00000000 */ 	nop
/*  f16cf50:	0c005310 */ 	jal	joyGetStickY
/*  f16cf54:	24040003 */ 	li	$a0,0x3
/*  f16cf58:	2841000b */ 	slti	$at,$v0,0xb
/*  f16cf5c:	10200005 */ 	beqz	$at,.PF0f16cf74
/*  f16cf60:	00000000 */ 	nop
/*  f16cf64:	0c005310 */ 	jal	joyGetStickY
/*  f16cf68:	24040003 */ 	li	$a0,0x3
/*  f16cf6c:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16cf70:	1020000e */ 	beqz	$at,.PF0f16cfac
.PF0f16cf74:
/*  f16cf74:	3c108006 */ 	lui	$s0,0x8006
/*  f16cf78:	26102174 */ 	addiu	$s0,$s0,0x2174
/*  f16cf7c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f16cf80:	5320000b */ 	beqzl	$t9,.PF0f16cfb0
/*  f16cf84:	8e8d04b4 */ 	lw	$t5,0x4b4($s4)
/*  f16cf88:	8e8c04b4 */ 	lw	$t4,0x4b4($s4)
/*  f16cf8c:	2401005a */ 	li	$at,0x5a
/*  f16cf90:	51810006 */ 	beql	$t4,$at,.PF0f16cfac
/*  f16cf94:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f16cf98:	0fc06a32 */ 	jal	titleSetNextMode
/*  f16cf9c:	24040005 */ 	li	$a0,0x5
/*  f16cfa0:	0c0039af */ 	jal	mainSetStageNum
/*  f16cfa4:	2404005a */ 	li	$a0,0x5a
/*  f16cfa8:	ae000000 */ 	sw	$zero,0x0($s0)
.PF0f16cfac:
/*  f16cfac:	8e8d04b4 */ 	lw	$t5,0x4b4($s4)
.PF0f16cfb0:
/*  f16cfb0:	3c108006 */ 	lui	$s0,0x8006
/*  f16cfb4:	26102174 */ 	addiu	$s0,$s0,0x2174
/*  f16cfb8:	29a1005a */ 	slti	$at,$t5,0x5a
/*  f16cfbc:	10200072 */ 	beqz	$at,.PF0f16d188
/*  f16cfc0:	3c028006 */ 	lui	$v0,0x8006
/*  f16cfc4:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f16cfc8:	15c0006f */ 	bnez	$t6,.PF0f16d188
/*  f16cfcc:	00000000 */ 	nop
/*  f16cfd0:	8e8f04cc */ 	lw	$t7,0x4cc($s4)
/*  f16cfd4:	00002025 */ 	move	$a0,$zero
/*  f16cfd8:	15e0006b */ 	bnez	$t7,.PF0f16d188
/*  f16cfdc:	00000000 */ 	nop
/*  f16cfe0:	0c00533a */ 	jal	joyGetButtons
/*  f16cfe4:	3405ffff */ 	li	$a1,0xffff
/*  f16cfe8:	14400063 */ 	bnez	$v0,.PF0f16d178
/*  f16cfec:	00000000 */ 	nop
/*  f16cff0:	0c0052e6 */ 	jal	joyGetStickX
/*  f16cff4:	00002025 */ 	move	$a0,$zero
/*  f16cff8:	2841000a */ 	slti	$at,$v0,0xa
/*  f16cffc:	1020005e */ 	beqz	$at,.PF0f16d178
/*  f16d000:	00000000 */ 	nop
/*  f16d004:	0c0052e6 */ 	jal	joyGetStickX
/*  f16d008:	00002025 */ 	move	$a0,$zero
/*  f16d00c:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d010:	14200059 */ 	bnez	$at,.PF0f16d178
/*  f16d014:	00000000 */ 	nop
/*  f16d018:	0c005310 */ 	jal	joyGetStickY
/*  f16d01c:	00002025 */ 	move	$a0,$zero
/*  f16d020:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d024:	10200054 */ 	beqz	$at,.PF0f16d178
/*  f16d028:	00000000 */ 	nop
/*  f16d02c:	0c005310 */ 	jal	joyGetStickY
/*  f16d030:	00002025 */ 	move	$a0,$zero
/*  f16d034:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d038:	1420004f */ 	bnez	$at,.PF0f16d178
/*  f16d03c:	24040001 */ 	li	$a0,0x1
/*  f16d040:	0c00533a */ 	jal	joyGetButtons
/*  f16d044:	3405ffff */ 	li	$a1,0xffff
/*  f16d048:	1440004b */ 	bnez	$v0,.PF0f16d178
/*  f16d04c:	00000000 */ 	nop
/*  f16d050:	0c0052e6 */ 	jal	joyGetStickX
/*  f16d054:	24040001 */ 	li	$a0,0x1
/*  f16d058:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d05c:	10200046 */ 	beqz	$at,.PF0f16d178
/*  f16d060:	00000000 */ 	nop
/*  f16d064:	0c0052e6 */ 	jal	joyGetStickX
/*  f16d068:	24040001 */ 	li	$a0,0x1
/*  f16d06c:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d070:	14200041 */ 	bnez	$at,.PF0f16d178
/*  f16d074:	00000000 */ 	nop
/*  f16d078:	0c005310 */ 	jal	joyGetStickY
/*  f16d07c:	24040001 */ 	li	$a0,0x1
/*  f16d080:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d084:	1020003c */ 	beqz	$at,.PF0f16d178
/*  f16d088:	00000000 */ 	nop
/*  f16d08c:	0c005310 */ 	jal	joyGetStickY
/*  f16d090:	24040001 */ 	li	$a0,0x1
/*  f16d094:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d098:	14200037 */ 	bnez	$at,.PF0f16d178
/*  f16d09c:	24040002 */ 	li	$a0,0x2
/*  f16d0a0:	0c00533a */ 	jal	joyGetButtons
/*  f16d0a4:	3405ffff */ 	li	$a1,0xffff
/*  f16d0a8:	14400033 */ 	bnez	$v0,.PF0f16d178
/*  f16d0ac:	00000000 */ 	nop
/*  f16d0b0:	0c0052e6 */ 	jal	joyGetStickX
/*  f16d0b4:	24040002 */ 	li	$a0,0x2
/*  f16d0b8:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d0bc:	1020002e */ 	beqz	$at,.PF0f16d178
/*  f16d0c0:	00000000 */ 	nop
/*  f16d0c4:	0c0052e6 */ 	jal	joyGetStickX
/*  f16d0c8:	24040002 */ 	li	$a0,0x2
/*  f16d0cc:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d0d0:	14200029 */ 	bnez	$at,.PF0f16d178
/*  f16d0d4:	00000000 */ 	nop
/*  f16d0d8:	0c005310 */ 	jal	joyGetStickY
/*  f16d0dc:	24040002 */ 	li	$a0,0x2
/*  f16d0e0:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d0e4:	10200024 */ 	beqz	$at,.PF0f16d178
/*  f16d0e8:	00000000 */ 	nop
/*  f16d0ec:	0c005310 */ 	jal	joyGetStickY
/*  f16d0f0:	24040002 */ 	li	$a0,0x2
/*  f16d0f4:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d0f8:	1420001f */ 	bnez	$at,.PF0f16d178
/*  f16d0fc:	24040003 */ 	li	$a0,0x3
/*  f16d100:	0c00533a */ 	jal	joyGetButtons
/*  f16d104:	3405ffff */ 	li	$a1,0xffff
/*  f16d108:	1440001b */ 	bnez	$v0,.PF0f16d178
/*  f16d10c:	00000000 */ 	nop
/*  f16d110:	0c0052e6 */ 	jal	joyGetStickX
/*  f16d114:	24040003 */ 	li	$a0,0x3
/*  f16d118:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d11c:	10200016 */ 	beqz	$at,.PF0f16d178
/*  f16d120:	00000000 */ 	nop
/*  f16d124:	0c0052e6 */ 	jal	joyGetStickX
/*  f16d128:	24040003 */ 	li	$a0,0x3
/*  f16d12c:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d130:	14200011 */ 	bnez	$at,.PF0f16d178
/*  f16d134:	00000000 */ 	nop
/*  f16d138:	0c005310 */ 	jal	joyGetStickY
/*  f16d13c:	24040003 */ 	li	$a0,0x3
/*  f16d140:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d144:	1020000c */ 	beqz	$at,.PF0f16d178
/*  f16d148:	00000000 */ 	nop
/*  f16d14c:	0c005310 */ 	jal	joyGetStickY
/*  f16d150:	24040003 */ 	li	$a0,0x3
/*  f16d154:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d158:	14200007 */ 	bnez	$at,.PF0f16d178
/*  f16d15c:	3c028006 */ 	lui	$v0,0x8006
/*  f16d160:	24422180 */ 	addiu	$v0,$v0,0x2180
/*  f16d164:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f16d168:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f16d16c:	03196021 */ 	addu	$t4,$t8,$t9
/*  f16d170:	10000007 */ 	b	.PF0f16d190
/*  f16d174:	ac4c0000 */ 	sw	$t4,0x0($v0)
.PF0f16d178:
/*  f16d178:	3c028006 */ 	lui	$v0,0x8006
/*  f16d17c:	24422180 */ 	addiu	$v0,$v0,0x2180
/*  f16d180:	10000003 */ 	b	.PF0f16d190
/*  f16d184:	ac400000 */ 	sw	$zero,0x0($v0)
.PF0f16d188:
/*  f16d188:	24422180 */ 	addiu	$v0,$v0,0x2180
/*  f16d18c:	ac400000 */ 	sw	$zero,0x0($v0)
.PF0f16d190:
/*  f16d190:	8e8d0318 */ 	lw	$t5,0x318($s4)
/*  f16d194:	3c118008 */ 	lui	$s1,0x8008
/*  f16d198:	26314578 */ 	addiu	$s1,$s1,0x4578
/*  f16d19c:	11a00139 */ 	beqz	$t5,.PF0f16d684
/*  f16d1a0:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f16d1a4:	8e8e04b4 */ 	lw	$t6,0x4b4($s4)
/*  f16d1a8:	3c038008 */ 	lui	$v1,0x8008
/*  f16d1ac:	29c1005a */ 	slti	$at,$t6,0x5a
/*  f16d1b0:	10200134 */ 	beqz	$at,.PF0f16d684
/*  f16d1b4:	00000000 */ 	nop
/*  f16d1b8:	8c634568 */ 	lw	$v1,0x4568($v1)
/*  f16d1bc:	3c028008 */ 	lui	$v0,0x8008
/*  f16d1c0:	2401003c */ 	li	$at,0x3c
/*  f16d1c4:	18600098 */ 	blez	$v1,.PF0f16d428
/*  f16d1c8:	00033080 */ 	sll	$a2,$v1,0x2
/*  f16d1cc:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16d1d0:	000630c0 */ 	sll	$a2,$a2,0x3
/*  f16d1d4:	00c33021 */ 	addu	$a2,$a2,$v1
/*  f16d1d8:	00063040 */ 	sll	$a2,$a2,0x1
/*  f16d1dc:	00c1001a */ 	div	$zero,$a2,$at
/*  f16d1e0:	8c534564 */ 	lw	$s3,0x4564($v0)
/*  f16d1e4:	00003012 */ 	mflo	$a2
/*  f16d1e8:	8e8f0038 */ 	lw	$t7,0x38($s4)
/*  f16d1ec:	24c4f448 */ 	addiu	$a0,$a2,-3000
/*  f16d1f0:	0264082a */ 	slt	$at,$s3,$a0
/*  f16d1f4:	10200052 */ 	beqz	$at,.PF0f16d340
/*  f16d1f8:	01f39021 */ 	addu	$s2,$t7,$s3
/*  f16d1fc:	0244082a */ 	slt	$at,$s2,$a0
/*  f16d200:	54200050 */ 	bnezl	$at,.PF0f16d344
/*  f16d204:	0266082a */ 	slt	$at,$s3,$a2
/*  f16d208:	8e99006c */ 	lw	$t9,0x6c($s4)
/*  f16d20c:	00008025 */ 	move	$s0,$zero
/*  f16d210:	00002825 */ 	move	$a1,$zero
/*  f16d214:	13200003 */ 	beqz	$t9,.PF0f16d224
/*  f16d218:	00002025 */ 	move	$a0,$zero
/*  f16d21c:	10000001 */ 	b	.PF0f16d224
/*  f16d220:	24050001 */ 	li	$a1,0x1
.PF0f16d224:
/*  f16d224:	8e8c0068 */ 	lw	$t4,0x68($s4)
/*  f16d228:	00001825 */ 	move	$v1,$zero
/*  f16d22c:	00001025 */ 	move	$v0,$zero
/*  f16d230:	11800003 */ 	beqz	$t4,.PF0f16d240
/*  f16d234:	00000000 */ 	nop
/*  f16d238:	10000001 */ 	b	.PF0f16d240
/*  f16d23c:	24040001 */ 	li	$a0,0x1
.PF0f16d240:
/*  f16d240:	8e8d0064 */ 	lw	$t5,0x64($s4)
/*  f16d244:	11a00003 */ 	beqz	$t5,.PF0f16d254
/*  f16d248:	00000000 */ 	nop
/*  f16d24c:	10000001 */ 	b	.PF0f16d254
/*  f16d250:	24030001 */ 	li	$v1,0x1
.PF0f16d254:
/*  f16d254:	8e8e0070 */ 	lw	$t6,0x70($s4)
/*  f16d258:	11c00003 */ 	beqz	$t6,.PF0f16d268
/*  f16d25c:	00000000 */ 	nop
/*  f16d260:	10000001 */ 	b	.PF0f16d268
/*  f16d264:	24020001 */ 	li	$v0,0x1
.PF0f16d268:
/*  f16d268:	00437821 */ 	addu	$t7,$v0,$v1
/*  f16d26c:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f16d270:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f16d274:	5b200033 */ 	blezl	$t9,.PF0f16d344
/*  f16d278:	0266082a */ 	slt	$at,$s3,$a2
.PF0f16d27c:
/*  f16d27c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16d280:	02002025 */ 	move	$a0,$s0
/*  f16d284:	0fc5bdaa */ 	jal	langGet
/*  f16d288:	24045807 */ 	li	$a0,0x5807
/*  f16d28c:	00402025 */ 	move	$a0,$v0
/*  f16d290:	0fc37954 */ 	jal	hudmsgCreate
/*  f16d294:	00002825 */ 	move	$a1,$zero
/*  f16d298:	8e8c006c */ 	lw	$t4,0x6c($s4)
/*  f16d29c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16d2a0:	00002825 */ 	move	$a1,$zero
/*  f16d2a4:	11800003 */ 	beqz	$t4,.PF0f16d2b4
/*  f16d2a8:	00002025 */ 	move	$a0,$zero
/*  f16d2ac:	10000001 */ 	b	.PF0f16d2b4
/*  f16d2b0:	24050001 */ 	li	$a1,0x1
.PF0f16d2b4:
/*  f16d2b4:	8e8d0068 */ 	lw	$t5,0x68($s4)
/*  f16d2b8:	00001825 */ 	move	$v1,$zero
/*  f16d2bc:	00001025 */ 	move	$v0,$zero
/*  f16d2c0:	11a00003 */ 	beqz	$t5,.PF0f16d2d0
/*  f16d2c4:	00000000 */ 	nop
/*  f16d2c8:	10000001 */ 	b	.PF0f16d2d0
/*  f16d2cc:	24040001 */ 	li	$a0,0x1
.PF0f16d2d0:
/*  f16d2d0:	8e8e0064 */ 	lw	$t6,0x64($s4)
/*  f16d2d4:	11c00003 */ 	beqz	$t6,.PF0f16d2e4
/*  f16d2d8:	00000000 */ 	nop
/*  f16d2dc:	10000001 */ 	b	.PF0f16d2e4
/*  f16d2e0:	24030001 */ 	li	$v1,0x1
.PF0f16d2e4:
/*  f16d2e4:	8e8f0070 */ 	lw	$t7,0x70($s4)
/*  f16d2e8:	11e00003 */ 	beqz	$t7,.PF0f16d2f8
/*  f16d2ec:	00000000 */ 	nop
/*  f16d2f0:	10000001 */ 	b	.PF0f16d2f8
/*  f16d2f4:	24020001 */ 	li	$v0,0x1
.PF0f16d2f8:
/*  f16d2f8:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f16d2fc:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f16d300:	03256021 */ 	addu	$t4,$t9,$a1
/*  f16d304:	020c082a */ 	slt	$at,$s0,$t4
/*  f16d308:	1420ffdc */ 	bnez	$at,.PF0f16d27c
/*  f16d30c:	00000000 */ 	nop
/*  f16d310:	3c068008 */ 	lui	$a2,0x8008
/*  f16d314:	8cc64568 */ 	lw	$a2,0x4568($a2)
/*  f16d318:	2401003c */ 	li	$at,0x3c
/*  f16d31c:	00066880 */ 	sll	$t5,$a2,0x2
/*  f16d320:	01a66823 */ 	subu	$t5,$t5,$a2
/*  f16d324:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f16d328:	01a66821 */ 	addu	$t5,$t5,$a2
/*  f16d32c:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f16d330:	01a1001a */ 	div	$zero,$t5,$at
/*  f16d334:	00003012 */ 	mflo	$a2
/*  f16d338:	00000000 */ 	nop
/*  f16d33c:	00000000 */ 	nop
.PF0f16d340:
/*  f16d340:	0266082a */ 	slt	$at,$s3,$a2
.PF0f16d344:
/*  f16d344:	10200011 */ 	beqz	$at,.PF0f16d38c
/*  f16d348:	0246082a */ 	slt	$at,$s2,$a2
/*  f16d34c:	54200010 */ 	bnezl	$at,.PF0f16d390
/*  f16d350:	24d9fe0c */ 	addiu	$t9,$a2,-500
/*  f16d354:	0c0038f9 */ 	jal	mainEndStage
/*  f16d358:	00000000 */ 	nop
/*  f16d35c:	3c068008 */ 	lui	$a2,0x8008
/*  f16d360:	8cc64568 */ 	lw	$a2,0x4568($a2)
/*  f16d364:	2401003c */ 	li	$at,0x3c
/*  f16d368:	00067880 */ 	sll	$t7,$a2,0x2
/*  f16d36c:	01e67823 */ 	subu	$t7,$t7,$a2
/*  f16d370:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f16d374:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f16d378:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f16d37c:	01e1001a */ 	div	$zero,$t7,$at
/*  f16d380:	00003012 */ 	mflo	$a2
/*  f16d384:	00000000 */ 	nop
/*  f16d388:	00000000 */ 	nop
.PF0f16d38c:
/*  f16d38c:	24d9fe0c */ 	addiu	$t9,$a2,-500
.PF0f16d390:
/*  f16d390:	0259082a */ 	slt	$at,$s2,$t9
/*  f16d394:	14200024 */ 	bnez	$at,.PF0f16d428
/*  f16d398:	3c108008 */ 	lui	$s0,0x8008
/*  f16d39c:	26104574 */ 	addiu	$s0,$s0,0x4574
/*  f16d3a0:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f16d3a4:	55800021 */ 	bnezl	$t4,.PF0f16d42c
/*  f16d3a8:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f16d3ac:	0fc5b6f7 */ 	jal	lvIsPaused
/*  f16d3b0:	00000000 */ 	nop
/*  f16d3b4:	1440001c */ 	bnez	$v0,.PF0f16d428
/*  f16d3b8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f16d3bc:	8dad4568 */ 	lw	$t5,0x4568($t5)
/*  f16d3c0:	2401003c */ 	li	$at,0x3c
/*  f16d3c4:	02002025 */ 	move	$a0,$s0
/*  f16d3c8:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f16d3cc:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f16d3d0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f16d3d4:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f16d3d8:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f16d3dc:	01c1001a */ 	div	$zero,$t6,$at
/*  f16d3e0:	00007812 */ 	mflo	$t7
/*  f16d3e4:	024f082a */ 	slt	$at,$s2,$t7
/*  f16d3e8:	1020000f */ 	beqz	$at,.PF0f16d428
/*  f16d3ec:	00002825 */ 	move	$a1,$zero
/*  f16d3f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f16d3f4:	44814000 */ 	mtc1	$at,$f8
/*  f16d3f8:	241800a3 */ 	li	$t8,0xa3
/*  f16d3fc:	24190001 */ 	li	$t9,0x1
/*  f16d400:	240cffff */ 	li	$t4,-1
/*  f16d404:	240d0001 */ 	li	$t5,0x1
/*  f16d408:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f16d40c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f16d410:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f16d414:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f16d418:	24067fff */ 	li	$a2,0x7fff
/*  f16d41c:	24070040 */ 	li	$a3,0x40
/*  f16d420:	0c004125 */ 	jal	snd00010718
/*  f16d424:	e7a80014 */ 	swc1	$f8,0x14($sp)
.PF0f16d428:
/*  f16d428:	8e8e0034 */ 	lw	$t6,0x34($s4)
.PF0f16d42c:
/*  f16d42c:	00008025 */ 	move	$s0,$zero
/*  f16d430:	00005825 */ 	move	$t3,$zero
/*  f16d434:	11c00093 */ 	beqz	$t6,.PF0f16d684
/*  f16d438:	00000000 */ 	nop
/*  f16d43c:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f16d440:	8e870068 */ 	lw	$a3,0x68($s4)
/*  f16d444:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f16d448:	11200003 */ 	beqz	$t1,.PF0f16d458
/*  f16d44c:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f16d450:	10000002 */ 	b	.PF0f16d45c
/*  f16d454:	24050001 */ 	li	$a1,0x1
.PF0f16d458:
/*  f16d458:	00002825 */ 	move	$a1,$zero
.PF0f16d45c:
/*  f16d45c:	10e00003 */ 	beqz	$a3,.PF0f16d46c
/*  f16d460:	00002025 */ 	move	$a0,$zero
/*  f16d464:	10000001 */ 	b	.PF0f16d46c
/*  f16d468:	24040001 */ 	li	$a0,0x1
.PF0f16d46c:
/*  f16d46c:	11000003 */ 	beqz	$t0,.PF0f16d47c
/*  f16d470:	00001825 */ 	move	$v1,$zero
/*  f16d474:	10000001 */ 	b	.PF0f16d47c
/*  f16d478:	24030001 */ 	li	$v1,0x1
.PF0f16d47c:
/*  f16d47c:	10c00003 */ 	beqz	$a2,.PF0f16d48c
/*  f16d480:	00001025 */ 	move	$v0,$zero
/*  f16d484:	10000001 */ 	b	.PF0f16d48c
/*  f16d488:	24020001 */ 	li	$v0,0x1
.PF0f16d48c:
/*  f16d48c:	00437821 */ 	addu	$t7,$v0,$v1
/*  f16d490:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f16d494:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f16d498:	1b20002d */ 	blez	$t9,.PF0f16d550
/*  f16d49c:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f16d4a0:	44800000 */ 	mtc1	$zero,$f0
/*  f16d4a4:	028c5021 */ 	addu	$t2,$s4,$t4
/*  f16d4a8:	8d420064 */ 	lw	$v0,0x64($t2)
.PF0f16d4ac:
/*  f16d4ac:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f16d4b0:	00002825 */ 	move	$a1,$zero
/*  f16d4b4:	8c4d00d8 */ 	lw	$t5,0xd8($v0)
/*  f16d4b8:	00002025 */ 	move	$a0,$zero
/*  f16d4bc:	00001825 */ 	move	$v1,$zero
/*  f16d4c0:	11a0000d */ 	beqz	$t5,.PF0f16d4f8
/*  f16d4c4:	00000000 */ 	nop
/*  f16d4c8:	8c4e032c */ 	lw	$t6,0x32c($v0)
/*  f16d4cc:	51c0000a */ 	beqzl	$t6,.PF0f16d4f8
/*  f16d4d0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16d4d4:	8c4f0330 */ 	lw	$t7,0x330($v0)
/*  f16d4d8:	51e00007 */ 	beqzl	$t7,.PF0f16d4f8
/*  f16d4dc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16d4e0:	c44a02ec */ 	lwc1	$f10,0x2ec($v0)
/*  f16d4e4:	460a003e */ 	c.le.s	$f0,$f10
/*  f16d4e8:	00000000 */ 	nop
/*  f16d4ec:	45000002 */ 	bc1f	.PF0f16d4f8
/*  f16d4f0:	00000000 */ 	nop
/*  f16d4f4:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f16d4f8:
/*  f16d4f8:	11200003 */ 	beqz	$t1,.PF0f16d508
/*  f16d4fc:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f16d500:	10000001 */ 	b	.PF0f16d508
/*  f16d504:	24050001 */ 	li	$a1,0x1
.PF0f16d508:
/*  f16d508:	10e00003 */ 	beqz	$a3,.PF0f16d518
/*  f16d50c:	00001025 */ 	move	$v0,$zero
/*  f16d510:	10000001 */ 	b	.PF0f16d518
/*  f16d514:	24040001 */ 	li	$a0,0x1
.PF0f16d518:
/*  f16d518:	11000003 */ 	beqz	$t0,.PF0f16d528
/*  f16d51c:	00000000 */ 	nop
/*  f16d520:	10000001 */ 	b	.PF0f16d528
/*  f16d524:	24030001 */ 	li	$v1,0x1
.PF0f16d528:
/*  f16d528:	10c00003 */ 	beqz	$a2,.PF0f16d538
/*  f16d52c:	00000000 */ 	nop
/*  f16d530:	10000001 */ 	b	.PF0f16d538
/*  f16d534:	24020001 */ 	li	$v0,0x1
.PF0f16d538:
/*  f16d538:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f16d53c:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f16d540:	03256021 */ 	addu	$t4,$t9,$a1
/*  f16d544:	016c082a */ 	slt	$at,$t3,$t4
/*  f16d548:	5420ffd8 */ 	bnezl	$at,.PF0f16d4ac
/*  f16d54c:	8d420064 */ 	lw	$v0,0x64($t2)
.PF0f16d550:
/*  f16d550:	3c04800b */ 	lui	$a0,0x800b
/*  f16d554:	8c84cad0 */ 	lw	$a0,-0x3530($a0)
/*  f16d558:	3c0d800b */ 	lui	$t5,0x800b
/*  f16d55c:	25a2ca70 */ 	addiu	$v0,$t5,-13712
/*  f16d560:	1880000c */ 	blez	$a0,.PF0f16d594
/*  f16d564:	3c198008 */ 	lui	$t9,0x8008
/*  f16d568:	00047080 */ 	sll	$t6,$a0,0x2
/*  f16d56c:	01c21821 */ 	addu	$v1,$t6,$v0
/*  f16d570:	8c4f0000 */ 	lw	$t7,0x0($v0)
.PF0f16d574:
/*  f16d574:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f16d578:	0043082b */ 	sltu	$at,$v0,$v1
/*  f16d57c:	81f80007 */ 	lb	$t8,0x7($t7)
/*  f16d580:	16b80002 */ 	bne	$s5,$t8,.PF0f16d58c
/*  f16d584:	00000000 */ 	nop
/*  f16d588:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f16d58c:
/*  f16d58c:	5420fff9 */ 	bnezl	$at,.PF0f16d574
/*  f16d590:	8c4f0000 */ 	lw	$t7,0x0($v0)
.PF0f16d594:
/*  f16d594:	8f39456c */ 	lw	$t9,0x456c($t9)
/*  f16d598:	27a4016c */ 	addiu	$a0,$sp,0x16c
/*  f16d59c:	1b200017 */ 	blez	$t9,.PF0f16d5fc
/*  f16d5a0:	00000000 */ 	nop
/*  f16d5a4:	0fc625a2 */ 	jal	mpGetPlayerRankings
/*  f16d5a8:	00005825 */ 	move	$t3,$zero
/*  f16d5ac:	18400013 */ 	blez	$v0,.PF0f16d5fc
/*  f16d5b0:	00401825 */ 	move	$v1,$v0
/*  f16d5b4:	00037080 */ 	sll	$t6,$v1,0x2
/*  f16d5b8:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f16d5bc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f16d5c0:	3c048008 */ 	lui	$a0,0x8008
/*  f16d5c4:	27a2016c */ 	addiu	$v0,$sp,0x16c
/*  f16d5c8:	01c22821 */ 	addu	$a1,$t6,$v0
/*  f16d5cc:	8c84456c */ 	lw	$a0,0x456c($a0)
/*  f16d5d0:	8c4d0010 */ 	lw	$t5,0x10($v0)
.PF0f16d5d4:
/*  f16d5d4:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f16d5d8:	01a4082a */ 	slt	$at,$t5,$a0
/*  f16d5dc:	54200005 */ 	bnezl	$at,.PF0f16d5f4
/*  f16d5e0:	0045082b */ 	sltu	$at,$v0,$a1
/*  f16d5e4:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f16d5e8:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f16d5ec:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f16d5f0:	0045082b */ 	sltu	$at,$v0,$a1
.PF0f16d5f4:
/*  f16d5f4:	5420fff7 */ 	bnezl	$at,.PF0f16d5d4
/*  f16d5f8:	8c4d0010 */ 	lw	$t5,0x10($v0)
.PF0f16d5fc:
/*  f16d5fc:	3c198008 */ 	lui	$t9,0x8008
/*  f16d600:	8f394570 */ 	lw	$t9,0x4570($t9)
/*  f16d604:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f16d608:	5b200018 */ 	blezl	$t9,.PF0f16d66c
/*  f16d60c:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f16d610:	0fc626ca */ 	jal	mpGetTeamRankings
/*  f16d614:	00005825 */ 	move	$t3,$zero
/*  f16d618:	18400013 */ 	blez	$v0,.PF0f16d668
/*  f16d61c:	00401825 */ 	move	$v1,$v0
/*  f16d620:	00036080 */ 	sll	$t4,$v1,0x2
/*  f16d624:	01836021 */ 	addu	$t4,$t4,$v1
/*  f16d628:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f16d62c:	3c048008 */ 	lui	$a0,0x8008
/*  f16d630:	27a20078 */ 	addiu	$v0,$sp,0x78
/*  f16d634:	01822821 */ 	addu	$a1,$t4,$v0
/*  f16d638:	8c844570 */ 	lw	$a0,0x4570($a0)
/*  f16d63c:	8c4d0010 */ 	lw	$t5,0x10($v0)
.PF0f16d640:
/*  f16d640:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f16d644:	01a4082a */ 	slt	$at,$t5,$a0
/*  f16d648:	54200005 */ 	bnezl	$at,.PF0f16d660
/*  f16d64c:	0045082b */ 	sltu	$at,$v0,$a1
/*  f16d650:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f16d654:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f16d658:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f16d65c:	0045082b */ 	sltu	$at,$v0,$a1
.PF0f16d660:
/*  f16d660:	5420fff7 */ 	bnezl	$at,.PF0f16d640
/*  f16d664:	8c4d0010 */ 	lw	$t5,0x10($v0)
.PF0f16d668:
/*  f16d668:	8e390000 */ 	lw	$t9,0x0($s1)
.PF0f16d66c:
/*  f16d66c:	1b200005 */ 	blez	$t9,.PF0f16d684
/*  f16d670:	00000000 */ 	nop
/*  f16d674:	16000003 */ 	bnez	$s0,.PF0f16d684
/*  f16d678:	00000000 */ 	nop
/*  f16d67c:	0c0038f9 */ 	jal	mainEndStage
/*  f16d680:	00000000 */ 	nop
.PF0f16d684:
/*  f16d684:	3c0c8008 */ 	lui	$t4,0x8008
/*  f16d688:	8d8c4564 */ 	lw	$t4,0x4564($t4)
/*  f16d68c:	8e8e0038 */ 	lw	$t6,0x38($s4)
/*  f16d690:	3c018008 */ 	lui	$at,0x8008
/*  f16d694:	24040001 */ 	li	$a0,0x1
/*  f16d698:	018e6821 */ 	addu	$t5,$t4,$t6
/*  f16d69c:	448d8000 */ 	mtc1	$t5,$f16
/*  f16d6a0:	ac2d4564 */ 	sw	$t5,0x4564($at)
/*  f16d6a4:	3c014248 */ 	lui	$at,0x4248
/*  f16d6a8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f16d6ac:	44812000 */ 	mtc1	$at,$f4
/*  f16d6b0:	3c018008 */ 	lui	$at,0x8008
/*  f16d6b4:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f16d6b8:	0c002e99 */ 	jal	viSetUseZBuf
/*  f16d6bc:	e426457c */ 	swc1	$f6,0x457c($at)
/*  f16d6c0:	8e8204b4 */ 	lw	$v0,0x4b4($s4)
/*  f16d6c4:	2401004e */ 	li	$at,0x4e
/*  f16d6c8:	54410007 */ 	bnel	$v0,$at,.PF0f16d6e8
/*  f16d6cc:	2401005a */ 	li	$at,0x5a
/*  f16d6d0:	0fc06bc9 */ 	jal	titleTickOld
/*  f16d6d4:	00000000 */ 	nop
/*  f16d6d8:	0c0046c5 */ 	jal	func00011d84
/*  f16d6dc:	00000000 */ 	nop
/*  f16d6e0:	8e8204b4 */ 	lw	$v0,0x4b4($s4)
/*  f16d6e4:	2401005a */ 	li	$at,0x5a
.PF0f16d6e8:
/*  f16d6e8:	5441000a */ 	bnel	$v0,$at,.PF0f16d714
/*  f16d6ec:	2401005b */ 	li	$at,0x5b
/*  f16d6f0:	0fc06a3d */ 	jal	titleTick
/*  f16d6f4:	00000000 */ 	nop
/*  f16d6f8:	0fc0764c */ 	jal	func0f01d860
/*  f16d6fc:	00000000 */ 	nop
/*  f16d700:	0c0046c5 */ 	jal	func00011d84
/*  f16d704:	00000000 */ 	nop
/*  f16d708:	10000089 */ 	b	.PF0f16d930
/*  f16d70c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f16d710:	2401005b */ 	li	$at,0x5b
.PF0f16d714:
/*  f16d714:	54410010 */ 	bnel	$v0,$at,.PF0f16d758
/*  f16d718:	2401005d */ 	li	$at,0x5d
/*  f16d71c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16d720:	00002025 */ 	move	$a0,$zero
/*  f16d724:	0fc2f738 */ 	jal	currentPlayerConfigureVi
/*  f16d728:	00000000 */ 	nop
/*  f16d72c:	0fc07006 */ 	jal	menuTickAll
/*  f16d730:	00000000 */ 	nop
/*  f16d734:	0c0046c5 */ 	jal	func00011d84
/*  f16d738:	00000000 */ 	nop
/*  f16d73c:	0fc0764c */ 	jal	func0f01d860
/*  f16d740:	00000000 */ 	nop
/*  f16d744:	0fc474a7 */ 	jal	pakExecuteDebugOperations
/*  f16d748:	00000000 */ 	nop
/*  f16d74c:	10000078 */ 	b	.PF0f16d930
/*  f16d750:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f16d754:	2401005d */ 	li	$at,0x5d
.PF0f16d758:
/*  f16d758:	5441000c */ 	bnel	$v0,$at,.PF0f16d78c
/*  f16d75c:	2401005c */ 	li	$at,0x5c
/*  f16d760:	0fc07006 */ 	jal	menuTickAll
/*  f16d764:	00000000 */ 	nop
/*  f16d768:	0c0046c5 */ 	jal	func00011d84
/*  f16d76c:	00000000 */ 	nop
/*  f16d770:	0fc0764c */ 	jal	func0f01d860
/*  f16d774:	00000000 */ 	nop
/*  f16d778:	0fc474a7 */ 	jal	pakExecuteDebugOperations
/*  f16d77c:	00000000 */ 	nop
/*  f16d780:	1000006b */ 	b	.PF0f16d930
/*  f16d784:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f16d788:	2401005c */ 	li	$at,0x5c
.PF0f16d78c:
/*  f16d78c:	14410007 */ 	bne	$v0,$at,.PF0f16d7ac
/*  f16d790:	00000000 */ 	nop
/*  f16d794:	0c0046c5 */ 	jal	func00011d84
/*  f16d798:	00000000 */ 	nop
/*  f16d79c:	0fc0764c */ 	jal	func0f01d860
/*  f16d7a0:	00000000 */ 	nop
/*  f16d7a4:	10000062 */ 	b	.PF0f16d930
/*  f16d7a8:	8fbf0044 */ 	lw	$ra,0x44($sp)
.PF0f16d7ac:
/*  f16d7ac:	0fc5b16f */ 	jal	lvUpdateCutsceneTime
/*  f16d7b0:	00000000 */ 	nop
/*  f16d7b4:	0fc4a79b */ 	jal	func0f12939c
/*  f16d7b8:	00000000 */ 	nop
/*  f16d7bc:	0fc5af9f */ 	jal	lvUpdateSoloHandicaps
/*  f16d7c0:	00000000 */ 	nop
/*  f16d7c4:	0fc07678 */ 	jal	func0f01d8c0
/*  f16d7c8:	00000000 */ 	nop
/*  f16d7cc:	0fc076ac */ 	jal	func0f01d990
/*  f16d7d0:	00000000 */ 	nop
/*  f16d7d4:	0fc077a3 */ 	jal	casingsTick
/*  f16d7d8:	00000000 */ 	nop
/*  f16d7dc:	0fc077d4 */ 	jal	shardsTick
/*  f16d7e0:	00000000 */ 	nop
/*  f16d7e4:	0fc0785c */ 	jal	sparksTick
/*  f16d7e8:	00000000 */ 	nop
/*  f16d7ec:	0fc4fdad */ 	jal	func0f13eb44
/*  f16d7f0:	00000000 */ 	nop
/*  f16d7f4:	0fc52945 */ 	jal	func0f149864
/*  f16d7f8:	00000000 */ 	nop
/*  f16d7fc:	3c0f8006 */ 	lui	$t7,0x8006
/*  f16d800:	8def20c0 */ 	lw	$t7,0x20c0($t7)
/*  f16d804:	11e00003 */ 	beqz	$t7,.PF0f16d814
/*  f16d808:	00000000 */ 	nop
/*  f16d80c:	0fc07610 */ 	jal	weatherTick
/*  f16d810:	00000000 */ 	nop
.PF0f16d814:
/*  f16d814:	3c188006 */ 	lui	$t8,0x8006
/*  f16d818:	8f181310 */ 	lw	$t8,0x1310($t8)
/*  f16d81c:	13000003 */ 	beqz	$t8,.PF0f16d82c
/*  f16d820:	00000000 */ 	nop
/*  f16d824:	0fc027af */ 	jal	nbombsTick
/*  f16d828:	00000000 */ 	nop
.PF0f16d82c:
/*  f16d82c:	0fc5a302 */ 	jal	lvUpdateMiscSfx
/*  f16d830:	00000000 */ 	nop
/*  f16d834:	0c003f01 */ 	jal	sndTick
/*  f16d838:	00000000 */ 	nop
/*  f16d83c:	0fc474a7 */ 	jal	pakExecuteDebugOperations
/*  f16d840:	00000000 */ 	nop
/*  f16d844:	0fc00cec */ 	jal	lightingTick
/*  f16d848:	00000000 */ 	nop
/*  f16d84c:	0fc2cb89 */ 	jal	func0f0b2904
/*  f16d850:	00000000 */ 	nop
/*  f16d854:	0fc2bd1e */ 	jal	func0f0aefb8
/*  f16d858:	00000000 */ 	nop
/*  f16d85c:	0fc06c94 */ 	jal	amTick
/*  f16d860:	00000000 */ 	nop
/*  f16d864:	0fc07006 */ 	jal	menuTickAll
/*  f16d868:	00000000 */ 	nop
/*  f16d86c:	0fc619ac */ 	jal	scenarioTick
/*  f16d870:	00000000 */ 	nop
/*  f16d874:	3c198006 */ 	lui	$t9,0x8006
/*  f16d878:	8f39d670 */ 	lw	$t9,-0x2990($t9)
/*  f16d87c:	17200003 */ 	bnez	$t9,.PF0f16d88c
/*  f16d880:	00000000 */ 	nop
/*  f16d884:	0fc078dc */ 	jal	propsTick2
/*  f16d888:	00000000 */ 	nop
.PF0f16d88c:
/*  f16d88c:	0c0046c5 */ 	jal	func00011d84
/*  f16d890:	00000000 */ 	nop
/*  f16d894:	0fc0764c */ 	jal	func0f01d860
/*  f16d898:	00000000 */ 	nop
/*  f16d89c:	0fc19017 */ 	jal	propsTickPadEffects
/*  f16d8a0:	00000000 */ 	nop
/*  f16d8a4:	0c0039b9 */ 	jal	mainGetStageNum
/*  f16d8a8:	00000000 */ 	nop
/*  f16d8ac:	24010026 */ 	li	$at,0x26
/*  f16d8b0:	5441001f */ 	bnel	$v0,$at,.PF0f16d930
/*  f16d8b4:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f16d8b8:	0fc68a40 */ 	jal	dtGetData
/*  f16d8bc:	00000000 */ 	nop
/*  f16d8c0:	8e8c0284 */ 	lw	$t4,0x284($s4)
/*  f16d8c4:	8d8e00bc */ 	lw	$t6,0xbc($t4)
/*  f16d8c8:	85c30028 */ 	lh	$v1,0x28($t6)
/*  f16d8cc:	28610016 */ 	slti	$at,$v1,0x16
/*  f16d8d0:	14200002 */ 	bnez	$at,.PF0f16d8dc
/*  f16d8d4:	2861001a */ 	slti	$at,$v1,0x1a
/*  f16d8d8:	1420000b */ 	bnez	$at,.PF0f16d908
.PF0f16d8dc:
/*  f16d8dc:	2401000a */ 	li	$at,0xa
/*  f16d8e0:	10610009 */ 	beq	$v1,$at,.PF0f16d908
/*  f16d8e4:	00000000 */ 	nop
/*  f16d8e8:	10400005 */ 	beqz	$v0,.PF0f16d900
/*  f16d8ec:	00002025 */ 	move	$a0,$zero
/*  f16d8f0:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f16d8f4:	000d7fc2 */ 	srl	$t7,$t5,0x1f
/*  f16d8f8:	15e00003 */ 	bnez	$t7,.PF0f16d908
/*  f16d8fc:	00000000 */ 	nop
.PF0f16d900:
/*  f16d900:	0fc12838 */ 	jal	chrUnsetStageFlag
/*  f16d904:	24050001 */ 	li	$a1,0x1
.PF0f16d908:
/*  f16d908:	0fc682aa */ 	jal	frTick
/*  f16d90c:	00000000 */ 	nop
/*  f16d910:	8e980034 */ 	lw	$t8,0x34($s4)
/*  f16d914:	53000006 */ 	beqzl	$t8,.PF0f16d930
/*  f16d918:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f16d91c:	0fc68aa0 */ 	jal	dtTick
/*  f16d920:	00000000 */ 	nop
/*  f16d924:	0fc68c56 */ 	jal	htTick
/*  f16d928:	00000000 */ 	nop
/*  f16d92c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.PF0f16d930:
/*  f16d930:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f16d934:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f16d938:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f16d93c:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f16d940:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f16d944:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f16d948:	03e00008 */ 	jr	$ra
/*  f16d94c:	27bd0290 */ 	addiu	$sp,$sp,0x290
);
#elif VERSION >= VERSION_NTSC_1_0
void lvTick(void)
{
	s32 j;
	s32 i;

	lvCheckPauseStateChanged();

	if (g_Vars.unk0004e4) {
		func0f11c54c();
	}

	if (g_Vars.joydisableframestogo > 0) {
		g_Vars.joydisableframestogo--;
	} else if (g_Vars.joydisableframestogo == 0) {
		joy00013938();

		if (g_Vars.stagenum == STAGE_TITLE
				|| g_Vars.stagenum == STAGE_BOOTPAKMENU
				|| g_Vars.stagenum == STAGE_CREDITS
				|| g_Vars.stagenum == STAGE_4MBMENU) {
			g_Vars.paksconnected2 = 0;
		} else {
			g_Vars.paksconnected2 = 31;
			func0f11df38();
		}

		g_Vars.joydisableframestogo = -1;
	}

	if (IS4MB()) {
		func0f19ab40();
	}

	for (j = 0; j < PLAYERCOUNT(); j++) {
		g_Vars.players[j]->hands[HAND_LEFT].unk0cec = 0;
		g_Vars.players[j]->hands[HAND_RIGHT].unk0cec = 0;
	}

	if (lvIsPaused()) {
		g_Vars.lvupdate240 = 0;
	} else if (mpIsPaused()) {
		g_Vars.lvupdate240 = 0;

		for (j = 0; j < PLAYERCOUNT(); j++) {
			g_Vars.players[j]->joybutinhibit = 0xefffefff;
		}
	} else {
		s32 slowmo = lvGetSlowMotionType();
		g_Vars.lvupdate240 = g_Vars.diffframe240;

		if (slowmo == SLOWMOTION_ON) {
			if (g_Vars.speedpillon == false || g_Vars.in_cutscene) {
				if (g_Vars.lvupdate240 > 4) {
					g_Vars.lvupdate240 = 4;
				}
			}
		} else if (slowmo == SLOWMOTION_SMART) {
			// Smart slow motion - activates if an enemy chr is nearby
			if (g_Vars.speedpillon == false || g_Vars.in_cutscene) {
				if (g_Vars.mplayerisrunning) {
					bool foundnearbychr = false;
					s32 playernum;

					// Check if another player is in a nearby room
					for (playernum = 0; playernum < PLAYERCOUNT() && !foundnearbychr; playernum++) {
						if (g_Vars.players[playernum]->isdead == false) {
							s16 *rooms = g_Vars.players[playernum]->prop->rooms;
							s32 r;

							for (r = 0; rooms[r] != -1 && !foundnearbychr; r++) {
								s32 otherplayernum;
								for (otherplayernum = 0; otherplayernum < PLAYERCOUNT(); otherplayernum++) {
									if (playernum != otherplayernum
											&& g_Vars.players[otherplayernum]->isdead == false
											&& roomIsVisibleByPlayer(rooms[r], otherplayernum)) {
										foundnearbychr = true;
									}
								}
							}
						}
					}

					if (foundnearbychr) {
						if (g_Vars.lvupdate240 > 4) {
							g_Vars.lvupdate240 = 4;
						}
					} else {
						if (g_Vars.lvupdate240 > 8) {
							g_Vars.lvupdate240 = 8;
						}
					}
				} else {
					if (g_Vars.lvupdate240 > 4) {
						g_Vars.lvupdate240 = 4;
					}
				}
			}
		} else {
			// Slow motion settings are off
			if (g_Vars.speedpillon && g_Vars.in_cutscene == false) {
				if (g_Vars.lvupdate240 > 4) {
					g_Vars.lvupdate240 = 4;
				}
			}
		}
	}

	g_Vars.lvupdate240_60 = g_Vars.lvupdate240 + g_Vars.lvupdate240_60error;
	g_Vars.lvupdate240_60error = g_Vars.lvupdate240_60 & 3;
	g_Vars.lvupdate240_60 >>= 2;

	if (g_Vars.lvupdate240 > 0) {
		g_Vars.lvframenum++;
	}

	g_Vars.lvupdate240f = g_Vars.lvupdate240 * 0.25f;
	g_Vars.lvframe60 += g_Vars.lvupdate240_60;
	g_Vars.lvframe240 += g_Vars.lvupdate240;
	g_Vars.lvupdate240frealprev = g_Vars.lvupdate240freal;
	g_Vars.lvupdate240freal = PALUPF(g_Vars.lvupdate240f);

	bgunTickBoost();
	hudmsgsTick();

	if ((joyGetButtonsPressedThisFrame(0, 0xffff) != 0
				|| joyGetStickX(0) > 10
				|| joyGetStickX(0) < -10
				|| joyGetStickY(0) > 10
				|| joyGetStickY(0) < -10
				|| joyGetButtonsPressedThisFrame(1, 0xffff) != 0
				|| joyGetStickX(1) > 10
				|| joyGetStickX(1) < -10
				|| joyGetStickY(1) > 10
				|| joyGetStickY(1) < -10
				|| joyGetButtonsPressedThisFrame(2, 0xffff) != 0
				|| joyGetStickX(2) > 10
				|| joyGetStickX(2) < -10
				|| joyGetStickY(2) > 10
				|| joyGetStickY(2) < -10
				|| joyGetButtonsPressedThisFrame(3, 0xffff) != 0
				|| joyGetStickX(3) > 10
				|| joyGetStickX(3) < -10
				|| joyGetStickY(3) > 10
				|| joyGetStickY(3) < -10) && var800624a4) {
		if (g_Vars.stagenum != STAGE_TITLE) {
			titleSetNextMode(TITLEMODE_SKIP);
			mainSetStageNum(STAGE_TITLE);
		}

		var800624a4 = 0;
	}

	if (g_Vars.stagenum < STAGE_TITLE && !var800624a4 && !g_Vars.in_cutscene) {
		if (joyGetButtons(0, 0xffff) == 0
				&& joyGetStickX(0) < 10
				&& joyGetStickX(0) > -10
				&& joyGetStickY(0) < 10
				&& joyGetStickY(0) > -10
				&& joyGetButtons(1, 0xffff) == 0
				&& joyGetStickX(1) < 10
				&& joyGetStickX(1) > -10
				&& joyGetStickY(1) < 10
				&& joyGetStickY(1) > -10
				&& joyGetButtons(2, 0xffff) == 0
				&& joyGetStickX(2) < 10
				&& joyGetStickX(2) > -10
				&& joyGetStickY(2) < 10
				&& joyGetStickY(2) > -10
				&& joyGetButtons(3, 0xffff) == 0
				&& joyGetStickX(3) < 10
				&& joyGetStickX(3) > -10
				&& joyGetStickY(3) < 10
				&& joyGetStickY(3) > -10) {
			var800624b0 += g_Vars.diffframe60;
		} else {
			var800624b0 = 0;
		}
	} else {
		var800624b0 = 0;
	}

	g_NumReasonsToEndMpMatch = 0;

	// Handle MP match ending
	if (g_Vars.normmplayerisrunning && g_Vars.stagenum < STAGE_TITLE) {
		if (g_MpTimeLimit60 > 0) {
			s32 elapsed = g_StageTimeElapsed60;
			s32 nexttime = g_Vars.lvupdate240_60 + g_StageTimeElapsed60;
			s32 warntime = g_MpTimeLimit60 - 3600;

			// Show HUD message at one minute remaining
			if (elapsed < warntime && nexttime >= warntime) {
				s32 i;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(i);
					hudmsgCreate(langGet(L_MISC_068), HUDMSGTYPE_DEFAULT); // "One minute left."
				}
			}

			if (elapsed < g_MpTimeLimit60 && nexttime >= g_MpTimeLimit60) {
				// Match is ending due to time limit reached
				mainEndStage();
			}

			// Sound alarm at 10 seconds remaining
			if (nexttime >= g_MpTimeLimit60 - 600
					&& g_MiscAudioHandle == NULL
					&& !lvIsPaused()
					&& nexttime < g_MpTimeLimit60) {
				snd00010718(&g_MiscAudioHandle, 0, 0x7fff, 0x40, 163, 1, 1, -1, 1);
			}
		}

		if (g_Vars.lvupdate240 != 0) {
			s32 numdying = 0;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				if (g_Vars.players[i]->isdead) {
					if (g_Vars.players[i]->redbloodfinished == false
							|| g_Vars.players[i]->deathanimfinished == false
							|| g_Vars.players[i]->colourfadetimemax60 >= 0) {
						numdying++;
					}
				}
			}

			for (i = 0; i < g_MpNumPlayers; i++) {
				if (g_MpPlayerChrs[i]->actiontype == ACT_DIE) {
					numdying++;
				}
			}

			if (g_MpScoreLimit > 0) {
				struct mpteaminfo info[12];
				s32 count = mpGetPlayerRankings(info);

				for (i = 0; i < count; i++) {
					if (info[i].score >= g_MpScoreLimit) {
						g_NumReasonsToEndMpMatch++;
					}
				}
			}

			if (g_MpTeamScoreLimit > 0) {
				struct mpteaminfo info[12];
				s32 count = mpGetTeamRankings(info);

				for (i = 0; i < count; i++) {
					if (info[i].score >= g_MpTeamScoreLimit) {
						g_NumReasonsToEndMpMatch++;
					}
				}
			}

			if (g_NumReasonsToEndMpMatch > 0 && numdying == 0) {
				mainEndStage();
			}
		}
	}

	g_StageTimeElapsed60 += g_Vars.lvupdate240_60;
	g_StageTimeElapsed1f = g_StageTimeElapsed60 / 60.0f;

	viSetUseZBuf(true);

	if (g_Vars.stagenum == STAGE_TEST_OLD) {
		titleTickOld();
		func00011d84();
	}

	if (g_Vars.stagenum == STAGE_TITLE) {
		titleTick();
		func0f01d860();
		func00011d84();
	} else if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		setCurrentPlayerNum(0);
		menuTickAll();
		func00011d84();
		func0f01d860();
		pakExecuteDebugOperations();
	} else if (g_Vars.stagenum == STAGE_4MBMENU) {
		menuTickAll();
		func00011d84();
		func0f01d860();
		pakExecuteDebugOperations();
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		func00011d84();
		func0f01d860();
	} else {
		lvUpdateCutsceneTime();
		func0f12939c();
		lvUpdateSoloHandicaps();
		func0f01d8c0();
		func0f01d990();
		casingsTick();
		shardsTick();
		sparksTick();
		func0f13eb44();
		func0f149864();

		if (g_WeatherActive) {
			weatherTick();
		}

		if (g_NbombsActive) {
			nbombsTick();
		}

		lvUpdateMiscSfx();
		sndTick();
		pakExecuteDebugOperations();
		lightingTick();
		func0f0b2904();
		func0f0aefb8();
		amTick();
		menuTickAll();
		scenarioTick();

		if (!g_MainIsEndscreen) {
			propsTick2();
		}

		func00011d84();
		func0f01d860();
		propsTickPadEffects();

		if (mainGetStageNum() == STAGE_CITRAINING) {
			struct trainingdata *trainingdata = dtGetData();

			if ((g_Vars.currentplayer->prop->rooms[0] < CIROOM_HOLOSTART || g_Vars.currentplayer->prop->rooms[0] > CIROOM_HOLOEND)
					&& g_Vars.currentplayer->prop->rooms[0] != CIROOM_FIRINGRANGE
					&& (trainingdata == NULL || trainingdata->intraining == false)) {
				chrUnsetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
			}

			frTick();

			if (g_Vars.lvupdate240 != 0) {
				dtTick();
				htTick();
			}
		}
	}
}
#else
GLOBAL_ASM(
glabel lvTick
/*  f166724:	27bdfd70 */ 	addiu	$sp,$sp,-656
/*  f166728:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f16672c:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f166730:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f166734:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f166738:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f16673c:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f166740:	0fc59ea5 */ 	jal	lvCheckPauseStateChanged
/*  f166744:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f166748:	3c14800a */ 	lui	$s4,0x800a
/*  f16674c:	2694e6c0 */ 	addiu	$s4,$s4,-6464
/*  f166750:	8e8204d8 */ 	lw	$v0,0x4d8($s4)
/*  f166754:	18400003 */ 	blez	$v0,.NB0f166764
/*  f166758:	244effff */ 	addiu	$t6,$v0,-1
/*  f16675c:	1000001a */ 	beqz	$zero,.NB0f1667c8
/*  f166760:	ae8e04d8 */ 	sw	$t6,0x4d8($s4)
.NB0f166764:
/*  f166764:	14400018 */ 	bnez	$v0,.NB0f1667c8
/*  f166768:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16676c:	0c005812 */ 	jal	joy000150c4
/*  f166770:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166774:	14400004 */ 	bnez	$v0,.NB0f166788
/*  f166778:	24040cce */ 	addiu	$a0,$zero,0xcce
/*  f16677c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f166780:	0c005834 */ 	jal	joy00015144
/*  f166784:	24a51e98 */ 	addiu	$a1,$a1,0x1e98
.NB0f166788:
/*  f166788:	8e8204b4 */ 	lw	$v0,0x4b4($s4)
/*  f16678c:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f166790:	10410007 */ 	beq	$v0,$at,.NB0f1667b0
/*  f166794:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f166798:	10410005 */ 	beq	$v0,$at,.NB0f1667b0
/*  f16679c:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f1667a0:	10410003 */ 	beq	$v0,$at,.NB0f1667b0
/*  f1667a4:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f1667a8:	14410003 */ 	bne	$v0,$at,.NB0f1667b8
/*  f1667ac:	240f001f */ 	addiu	$t7,$zero,0x1f
.NB0f1667b0:
/*  f1667b0:	10000003 */ 	beqz	$zero,.NB0f1667c0
/*  f1667b4:	a28004d1 */ 	sb	$zero,0x4d1($s4)
.NB0f1667b8:
/*  f1667b8:	0fc45ecc */ 	jal	func0f11df38
/*  f1667bc:	a28f04d1 */ 	sb	$t7,0x4d1($s4)
.NB0f1667c0:
/*  f1667c0:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f1667c4:	ae9504d8 */ 	sw	$s5,0x4d8($s4)
.NB0f1667c8:
/*  f1667c8:	3c188009 */ 	lui	$t8,0x8009
/*  f1667cc:	931830e0 */ 	lbu	$t8,0x30e0($t8)
/*  f1667d0:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f1667d4:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f1667d8:	56180004 */ 	bnel	$s0,$t8,.NB0f1667ec
/*  f1667dc:	8e99006c */ 	lw	$t9,0x6c($s4)
/*  f1667e0:	0fc652c8 */ 	jal	func0f19ab40
/*  f1667e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1667e8:	8e99006c */ 	lw	$t9,0x6c($s4)
.NB0f1667ec:
/*  f1667ec:	00003825 */ 	or	$a3,$zero,$zero
/*  f1667f0:	53200004 */ 	beqzl	$t9,.NB0f166804
/*  f1667f4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1667f8:	10000002 */ 	beqz	$zero,.NB0f166804
/*  f1667fc:	02002825 */ 	or	$a1,$s0,$zero
/*  f166800:	00002825 */ 	or	$a1,$zero,$zero
.NB0f166804:
/*  f166804:	8e8c0068 */ 	lw	$t4,0x68($s4)
/*  f166808:	51800004 */ 	beqzl	$t4,.NB0f16681c
/*  f16680c:	00002025 */ 	or	$a0,$zero,$zero
/*  f166810:	10000002 */ 	beqz	$zero,.NB0f16681c
/*  f166814:	02002025 */ 	or	$a0,$s0,$zero
/*  f166818:	00002025 */ 	or	$a0,$zero,$zero
.NB0f16681c:
/*  f16681c:	8e8d0064 */ 	lw	$t5,0x64($s4)
/*  f166820:	51a00004 */ 	beqzl	$t5,.NB0f166834
/*  f166824:	00001825 */ 	or	$v1,$zero,$zero
/*  f166828:	10000002 */ 	beqz	$zero,.NB0f166834
/*  f16682c:	02001825 */ 	or	$v1,$s0,$zero
/*  f166830:	00001825 */ 	or	$v1,$zero,$zero
.NB0f166834:
/*  f166834:	8e8e0070 */ 	lw	$t6,0x70($s4)
/*  f166838:	51c00004 */ 	beqzl	$t6,.NB0f16684c
/*  f16683c:	00001025 */ 	or	$v0,$zero,$zero
/*  f166840:	10000002 */ 	beqz	$zero,.NB0f16684c
/*  f166844:	02001025 */ 	or	$v0,$s0,$zero
/*  f166848:	00001025 */ 	or	$v0,$zero,$zero
.NB0f16684c:
/*  f16684c:	00437821 */ 	addu	$t7,$v0,$v1
/*  f166850:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f166854:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f166858:	1b200026 */ 	blez	$t9,.NB0f1668f4
/*  f16685c:	00076080 */ 	sll	$t4,$a3,0x2
/*  f166860:	028c3021 */ 	addu	$a2,$s4,$t4
/*  f166864:	8ccd0064 */ 	lw	$t5,0x64($a2)
.NB0f166868:
/*  f166868:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f16686c:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f166870:	ada01490 */ 	sw	$zero,0x1490($t5)
/*  f166874:	8cce0060 */ 	lw	$t6,0x60($a2)
/*  f166878:	00002825 */ 	or	$a1,$zero,$zero
/*  f16687c:	00002025 */ 	or	$a0,$zero,$zero
/*  f166880:	adc00cec */ 	sw	$zero,0xcec($t6)
/*  f166884:	8e8f006c */ 	lw	$t7,0x6c($s4)
/*  f166888:	00001825 */ 	or	$v1,$zero,$zero
/*  f16688c:	00001025 */ 	or	$v0,$zero,$zero
/*  f166890:	11e00003 */ 	beqz	$t7,.NB0f1668a0
/*  f166894:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166898:	10000001 */ 	beqz	$zero,.NB0f1668a0
/*  f16689c:	02002825 */ 	or	$a1,$s0,$zero
.NB0f1668a0:
/*  f1668a0:	8e980068 */ 	lw	$t8,0x68($s4)
/*  f1668a4:	13000003 */ 	beqz	$t8,.NB0f1668b4
/*  f1668a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1668ac:	10000001 */ 	beqz	$zero,.NB0f1668b4
/*  f1668b0:	02002025 */ 	or	$a0,$s0,$zero
.NB0f1668b4:
/*  f1668b4:	8e990064 */ 	lw	$t9,0x64($s4)
/*  f1668b8:	13200003 */ 	beqz	$t9,.NB0f1668c8
/*  f1668bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1668c0:	10000001 */ 	beqz	$zero,.NB0f1668c8
/*  f1668c4:	02001825 */ 	or	$v1,$s0,$zero
.NB0f1668c8:
/*  f1668c8:	8e8c0070 */ 	lw	$t4,0x70($s4)
/*  f1668cc:	11800003 */ 	beqz	$t4,.NB0f1668dc
/*  f1668d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1668d4:	10000001 */ 	beqz	$zero,.NB0f1668dc
/*  f1668d8:	02001025 */ 	or	$v0,$s0,$zero
.NB0f1668dc:
/*  f1668dc:	00436821 */ 	addu	$t5,$v0,$v1
/*  f1668e0:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f1668e4:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f1668e8:	00ef082a */ 	slt	$at,$a3,$t7
/*  f1668ec:	5420ffde */ 	bnezl	$at,.NB0f166868
/*  f1668f0:	8ccd0064 */ 	lw	$t5,0x64($a2)
.NB0f1668f4:
/*  f1668f4:	0fc59ed0 */ 	jal	lvIsPaused
/*  f1668f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1668fc:	10400003 */ 	beqz	$v0,.NB0f16690c
/*  f166900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166904:	1000011a */ 	beqz	$zero,.NB0f166d70
/*  f166908:	ae800034 */ 	sw	$zero,0x34($s4)
.NB0f16690c:
/*  f16690c:	0fc60e8c */ 	jal	mpIsPaused
/*  f166910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166914:	10400044 */ 	beqz	$v0,.NB0f166a28
/*  f166918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16691c:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f166920:	ae800034 */ 	sw	$zero,0x34($s4)
/*  f166924:	00003825 */ 	or	$a3,$zero,$zero
/*  f166928:	13000003 */ 	beqz	$t8,.NB0f166938
/*  f16692c:	00002825 */ 	or	$a1,$zero,$zero
/*  f166930:	10000001 */ 	beqz	$zero,.NB0f166938
/*  f166934:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f166938:
/*  f166938:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f16693c:	00002025 */ 	or	$a0,$zero,$zero
/*  f166940:	00001825 */ 	or	$v1,$zero,$zero
/*  f166944:	13200003 */ 	beqz	$t9,.NB0f166954
/*  f166948:	00001025 */ 	or	$v0,$zero,$zero
/*  f16694c:	10000001 */ 	beqz	$zero,.NB0f166954
/*  f166950:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f166954:
/*  f166954:	8e8c0064 */ 	lw	$t4,0x64($s4)
/*  f166958:	0007c880 */ 	sll	$t9,$a3,0x2
/*  f16695c:	02993021 */ 	addu	$a2,$s4,$t9
/*  f166960:	11800003 */ 	beqz	$t4,.NB0f166970
/*  f166964:	3c08efff */ 	lui	$t0,0xefff
/*  f166968:	10000001 */ 	beqz	$zero,.NB0f166970
/*  f16696c:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f166970:
/*  f166970:	8e8d0070 */ 	lw	$t5,0x70($s4)
/*  f166974:	3508efff */ 	ori	$t0,$t0,0xefff
/*  f166978:	11a00003 */ 	beqz	$t5,.NB0f166988
/*  f16697c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166980:	10000001 */ 	beqz	$zero,.NB0f166988
/*  f166984:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f166988:
/*  f166988:	00437021 */ 	addu	$t6,$v0,$v1
/*  f16698c:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f166990:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f166994:	5b0000f7 */ 	blezl	$t8,.NB0f166d74
/*  f166998:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16699c:	8ccc0064 */ 	lw	$t4,0x64($a2)
.NB0f1669a0:
/*  f1669a0:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f1669a4:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f1669a8:	ad881c40 */ 	sw	$t0,0x1c40($t4)
/*  f1669ac:	8e8d006c */ 	lw	$t5,0x6c($s4)
/*  f1669b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1669b4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1669b8:	11a00003 */ 	beqz	$t5,.NB0f1669c8
/*  f1669bc:	00001825 */ 	or	$v1,$zero,$zero
/*  f1669c0:	10000001 */ 	beqz	$zero,.NB0f1669c8
/*  f1669c4:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f1669c8:
/*  f1669c8:	8e8e0068 */ 	lw	$t6,0x68($s4)
/*  f1669cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1669d0:	11c00003 */ 	beqz	$t6,.NB0f1669e0
/*  f1669d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1669d8:	10000001 */ 	beqz	$zero,.NB0f1669e0
/*  f1669dc:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f1669e0:
/*  f1669e0:	8e8f0064 */ 	lw	$t7,0x64($s4)
/*  f1669e4:	11e00003 */ 	beqz	$t7,.NB0f1669f4
/*  f1669e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1669ec:	10000001 */ 	beqz	$zero,.NB0f1669f4
/*  f1669f0:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f1669f4:
/*  f1669f4:	8e980070 */ 	lw	$t8,0x70($s4)
/*  f1669f8:	13000003 */ 	beqz	$t8,.NB0f166a08
/*  f1669fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166a00:	10000001 */ 	beqz	$zero,.NB0f166a08
/*  f166a04:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f166a08:
/*  f166a08:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f166a0c:	03246021 */ 	addu	$t4,$t9,$a0
/*  f166a10:	01856821 */ 	addu	$t5,$t4,$a1
/*  f166a14:	00ed082a */ 	slt	$at,$a3,$t5
/*  f166a18:	5420ffe1 */ 	bnezl	$at,.NB0f1669a0
/*  f166a1c:	8ccc0064 */ 	lw	$t4,0x64($a2)
/*  f166a20:	100000d4 */ 	beqz	$zero,.NB0f166d74
/*  f166a24:	8e830034 */ 	lw	$v1,0x34($s4)
.NB0f166a28:
/*  f166a28:	0fc599a0 */ 	jal	lvGetSlowMotionType
/*  f166a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166a30:	8e8e0040 */ 	lw	$t6,0x40($s4)
/*  f166a34:	24010002 */ 	addiu	$at,$zero,0x2
/*  f166a38:	1450000f */ 	bne	$v0,$s0,.NB0f166a78
/*  f166a3c:	ae8e0034 */ 	sw	$t6,0x34($s4)
/*  f166a40:	8e8f0468 */ 	lw	$t7,0x468($s4)
/*  f166a44:	51e00005 */ 	beqzl	$t7,.NB0f166a5c
/*  f166a48:	8e990034 */ 	lw	$t9,0x34($s4)
/*  f166a4c:	8e9804cc */ 	lw	$t8,0x4cc($s4)
/*  f166a50:	13000007 */ 	beqz	$t8,.NB0f166a70
/*  f166a54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166a58:	8e990034 */ 	lw	$t9,0x34($s4)
.NB0f166a5c:
/*  f166a5c:	24150004 */ 	addiu	$s5,$zero,0x4
/*  f166a60:	2b210005 */ 	slti	$at,$t9,0x5
/*  f166a64:	14200002 */ 	bnez	$at,.NB0f166a70
/*  f166a68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166a6c:	ae950034 */ 	sw	$s5,0x34($s4)
.NB0f166a70:
/*  f166a70:	100000c0 */ 	beqz	$zero,.NB0f166d74
/*  f166a74:	8e830034 */ 	lw	$v1,0x34($s4)
.NB0f166a78:
/*  f166a78:	544100b2 */ 	bnel	$v0,$at,.NB0f166d44
/*  f166a7c:	8e8e0468 */ 	lw	$t6,0x468($s4)
/*  f166a80:	8e8c0468 */ 	lw	$t4,0x468($s4)
/*  f166a84:	51800005 */ 	beqzl	$t4,.NB0f166a9c
/*  f166a88:	8e8e0314 */ 	lw	$t6,0x314($s4)
/*  f166a8c:	8e8d04cc */ 	lw	$t5,0x4cc($s4)
/*  f166a90:	11a000a9 */ 	beqz	$t5,.NB0f166d38
/*  f166a94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166a98:	8e8e0314 */ 	lw	$t6,0x314($s4)
.NB0f166a9c:
/*  f166a9c:	51c000a1 */ 	beqzl	$t6,.NB0f166d24
/*  f166aa0:	8e8d0034 */ 	lw	$t5,0x34($s4)
/*  f166aa4:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f166aa8:	00009025 */ 	or	$s2,$zero,$zero
/*  f166aac:	00009825 */ 	or	$s3,$zero,$zero
/*  f166ab0:	11200003 */ 	beqz	$t1,.NB0f166ac0
/*  f166ab4:	00002825 */ 	or	$a1,$zero,$zero
/*  f166ab8:	10000001 */ 	beqz	$zero,.NB0f166ac0
/*  f166abc:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f166ac0:
/*  f166ac0:	8e870068 */ 	lw	$a3,0x68($s4)
/*  f166ac4:	00002025 */ 	or	$a0,$zero,$zero
/*  f166ac8:	00001825 */ 	or	$v1,$zero,$zero
/*  f166acc:	10e00003 */ 	beqz	$a3,.NB0f166adc
/*  f166ad0:	00001025 */ 	or	$v0,$zero,$zero
/*  f166ad4:	10000001 */ 	beqz	$zero,.NB0f166adc
/*  f166ad8:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f166adc:
/*  f166adc:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f166ae0:	00136080 */ 	sll	$t4,$s3,0x2
/*  f166ae4:	028c6821 */ 	addu	$t5,$s4,$t4
/*  f166ae8:	11000003 */ 	beqz	$t0,.NB0f166af8
/*  f166aec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166af0:	10000001 */ 	beqz	$zero,.NB0f166af8
/*  f166af4:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f166af8:
/*  f166af8:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f166afc:	10c00003 */ 	beqz	$a2,.NB0f166b0c
/*  f166b00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166b04:	10000001 */ 	beqz	$zero,.NB0f166b0c
/*  f166b08:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f166b0c:
/*  f166b0c:	00437821 */ 	addu	$t7,$v0,$v1
/*  f166b10:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f166b14:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f166b18:	1b20006f */ 	blez	$t9,.NB0f166cd8
/*  f166b1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166b20:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f166b24:	8fae004c */ 	lw	$t6,0x4c($sp)
.NB0f166b28:
/*  f166b28:	8dc20064 */ 	lw	$v0,0x64($t6)
/*  f166b2c:	8c4f00d8 */ 	lw	$t7,0xd8($v0)
/*  f166b30:	55e0004e */ 	bnezl	$t7,.NB0f166c6c
/*  f166b34:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f166b38:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f166b3c:	84780028 */ 	lh	$t8,0x28($v1)
/*  f166b40:	24630028 */ 	addiu	$v1,$v1,0x28
/*  f166b44:	52b80049 */ 	beql	$s5,$t8,.NB0f166c6c
/*  f166b48:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f166b4c:	16400046 */ 	bnez	$s2,.NB0f166c68
/*  f166b50:	0000c840 */ 	sll	$t9,$zero,0x1
/*  f166b54:	00798821 */ 	addu	$s1,$v1,$t9
.NB0f166b58:
/*  f166b58:	11200003 */ 	beqz	$t1,.NB0f166b68
/*  f166b5c:	00008025 */ 	or	$s0,$zero,$zero
/*  f166b60:	10000002 */ 	beqz	$zero,.NB0f166b6c
/*  f166b64:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f166b68:
/*  f166b68:	00002825 */ 	or	$a1,$zero,$zero
.NB0f166b6c:
/*  f166b6c:	10e00003 */ 	beqz	$a3,.NB0f166b7c
/*  f166b70:	00002025 */ 	or	$a0,$zero,$zero
/*  f166b74:	10000001 */ 	beqz	$zero,.NB0f166b7c
/*  f166b78:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f166b7c:
/*  f166b7c:	11000003 */ 	beqz	$t0,.NB0f166b8c
/*  f166b80:	00001825 */ 	or	$v1,$zero,$zero
/*  f166b84:	10000001 */ 	beqz	$zero,.NB0f166b8c
/*  f166b88:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f166b8c:
/*  f166b8c:	10c00003 */ 	beqz	$a2,.NB0f166b9c
/*  f166b90:	00001025 */ 	or	$v0,$zero,$zero
/*  f166b94:	10000001 */ 	beqz	$zero,.NB0f166b9c
/*  f166b98:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f166b9c:
/*  f166b9c:	00436021 */ 	addu	$t4,$v0,$v1
/*  f166ba0:	01846821 */ 	addu	$t5,$t4,$a0
/*  f166ba4:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f166ba8:	59c0002a */ 	blezl	$t6,.NB0f166c54
/*  f166bac:	86380002 */ 	lh	$t8,0x2($s1)
.NB0f166bb0:
/*  f166bb0:	1270000c */ 	beq	$s3,$s0,.NB0f166be4
/*  f166bb4:	00107880 */ 	sll	$t7,$s0,0x2
/*  f166bb8:	028fc021 */ 	addu	$t8,$s4,$t7
/*  f166bbc:	8f190064 */ 	lw	$t9,0x64($t8)
/*  f166bc0:	02002825 */ 	or	$a1,$s0,$zero
/*  f166bc4:	8f2c00d8 */ 	lw	$t4,0xd8($t9)
/*  f166bc8:	55800007 */ 	bnezl	$t4,.NB0f166be8
/*  f166bcc:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f166bd0:	0fc55fa1 */ 	jal	roomIsVisibleByPlayer
/*  f166bd4:	86240000 */ 	lh	$a0,0x0($s1)
/*  f166bd8:	50400003 */ 	beqzl	$v0,.NB0f166be8
/*  f166bdc:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f166be0:	24120001 */ 	addiu	$s2,$zero,0x1
.NB0f166be4:
/*  f166be4:	8e89006c */ 	lw	$t1,0x6c($s4)
.NB0f166be8:
/*  f166be8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f166bec:	8e870068 */ 	lw	$a3,0x68($s4)
/*  f166bf0:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f166bf4:	11200003 */ 	beqz	$t1,.NB0f166c04
/*  f166bf8:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f166bfc:	10000002 */ 	beqz	$zero,.NB0f166c08
/*  f166c00:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f166c04:
/*  f166c04:	00002825 */ 	or	$a1,$zero,$zero
.NB0f166c08:
/*  f166c08:	10e00003 */ 	beqz	$a3,.NB0f166c18
/*  f166c0c:	00002025 */ 	or	$a0,$zero,$zero
/*  f166c10:	10000001 */ 	beqz	$zero,.NB0f166c18
/*  f166c14:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f166c18:
/*  f166c18:	11000003 */ 	beqz	$t0,.NB0f166c28
/*  f166c1c:	00001825 */ 	or	$v1,$zero,$zero
/*  f166c20:	10000001 */ 	beqz	$zero,.NB0f166c28
/*  f166c24:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f166c28:
/*  f166c28:	10c00003 */ 	beqz	$a2,.NB0f166c38
/*  f166c2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f166c30:	10000001 */ 	beqz	$zero,.NB0f166c38
/*  f166c34:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f166c38:
/*  f166c38:	00436821 */ 	addu	$t5,$v0,$v1
/*  f166c3c:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f166c40:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f166c44:	020f082a */ 	slt	$at,$s0,$t7
/*  f166c48:	1420ffd9 */ 	bnez	$at,.NB0f166bb0
/*  f166c4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166c50:	86380002 */ 	lh	$t8,0x2($s1)
.NB0f166c54:
/*  f166c54:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f166c58:	52b80004 */ 	beql	$s5,$t8,.NB0f166c6c
/*  f166c5c:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f166c60:	1240ffbd */ 	beqz	$s2,.NB0f166b58
/*  f166c64:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f166c68:
/*  f166c68:	8fb9004c */ 	lw	$t9,0x4c($sp)
.NB0f166c6c:
/*  f166c6c:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f166c70:	00002825 */ 	or	$a1,$zero,$zero
/*  f166c74:	272c0004 */ 	addiu	$t4,$t9,0x4
/*  f166c78:	11200003 */ 	beqz	$t1,.NB0f166c88
/*  f166c7c:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f166c80:	10000001 */ 	beqz	$zero,.NB0f166c88
/*  f166c84:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f166c88:
/*  f166c88:	10e00003 */ 	beqz	$a3,.NB0f166c98
/*  f166c8c:	00002025 */ 	or	$a0,$zero,$zero
/*  f166c90:	10000001 */ 	beqz	$zero,.NB0f166c98
/*  f166c94:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f166c98:
/*  f166c98:	11000003 */ 	beqz	$t0,.NB0f166ca8
/*  f166c9c:	00001825 */ 	or	$v1,$zero,$zero
/*  f166ca0:	10000001 */ 	beqz	$zero,.NB0f166ca8
/*  f166ca4:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f166ca8:
/*  f166ca8:	10c00003 */ 	beqz	$a2,.NB0f166cb8
/*  f166cac:	00001025 */ 	or	$v0,$zero,$zero
/*  f166cb0:	10000001 */ 	beqz	$zero,.NB0f166cb8
/*  f166cb4:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f166cb8:
/*  f166cb8:	00436821 */ 	addu	$t5,$v0,$v1
/*  f166cbc:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f166cc0:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f166cc4:	026f082a */ 	slt	$at,$s3,$t7
/*  f166cc8:	10200003 */ 	beqz	$at,.NB0f166cd8
/*  f166ccc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166cd0:	5240ff95 */ 	beqzl	$s2,.NB0f166b28
/*  f166cd4:	8fae004c */ 	lw	$t6,0x4c($sp)
.NB0f166cd8:
/*  f166cd8:	5240000a */ 	beqzl	$s2,.NB0f166d04
/*  f166cdc:	8e990034 */ 	lw	$t9,0x34($s4)
/*  f166ce0:	8e980034 */ 	lw	$t8,0x34($s4)
/*  f166ce4:	24150004 */ 	addiu	$s5,$zero,0x4
/*  f166ce8:	2b010005 */ 	slti	$at,$t8,0x5
/*  f166cec:	14200002 */ 	bnez	$at,.NB0f166cf8
/*  f166cf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166cf4:	ae950034 */ 	sw	$s5,0x34($s4)
.NB0f166cf8:
/*  f166cf8:	1000001e */ 	beqz	$zero,.NB0f166d74
/*  f166cfc:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f166d00:	8e990034 */ 	lw	$t9,0x34($s4)
.NB0f166d04:
/*  f166d04:	240c0008 */ 	addiu	$t4,$zero,0x8
/*  f166d08:	2b210009 */ 	slti	$at,$t9,0x9
/*  f166d0c:	14200002 */ 	bnez	$at,.NB0f166d18
/*  f166d10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166d14:	ae8c0034 */ 	sw	$t4,0x34($s4)
.NB0f166d18:
/*  f166d18:	10000016 */ 	beqz	$zero,.NB0f166d74
/*  f166d1c:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f166d20:	8e8d0034 */ 	lw	$t5,0x34($s4)
.NB0f166d24:
/*  f166d24:	24150004 */ 	addiu	$s5,$zero,0x4
/*  f166d28:	29a10005 */ 	slti	$at,$t5,0x5
/*  f166d2c:	14200002 */ 	bnez	$at,.NB0f166d38
/*  f166d30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166d34:	ae950034 */ 	sw	$s5,0x34($s4)
.NB0f166d38:
/*  f166d38:	1000000e */ 	beqz	$zero,.NB0f166d74
/*  f166d3c:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f166d40:	8e8e0468 */ 	lw	$t6,0x468($s4)
.NB0f166d44:
/*  f166d44:	51c0000b */ 	beqzl	$t6,.NB0f166d74
/*  f166d48:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f166d4c:	8e8f04cc */ 	lw	$t7,0x4cc($s4)
/*  f166d50:	55e00008 */ 	bnezl	$t7,.NB0f166d74
/*  f166d54:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f166d58:	8e980034 */ 	lw	$t8,0x34($s4)
/*  f166d5c:	24150004 */ 	addiu	$s5,$zero,0x4
/*  f166d60:	2b010005 */ 	slti	$at,$t8,0x5
/*  f166d64:	54200003 */ 	bnezl	$at,.NB0f166d74
/*  f166d68:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f166d6c:	ae950034 */ 	sw	$s5,0x34($s4)
.NB0f166d70:
/*  f166d70:	8e830034 */ 	lw	$v1,0x34($s4)
.NB0f166d74:
/*  f166d74:	8e99003c */ 	lw	$t9,0x3c($s4)
/*  f166d78:	24150004 */ 	addiu	$s5,$zero,0x4
/*  f166d7c:	44832000 */ 	mtc1	$v1,$f4
/*  f166d80:	00796021 */ 	addu	$t4,$v1,$t9
/*  f166d84:	ae8c0038 */ 	sw	$t4,0x38($s4)
/*  f166d88:	318d0003 */ 	andi	$t5,$t4,0x3
/*  f166d8c:	000c7083 */ 	sra	$t6,$t4,0x2
/*  f166d90:	ae8d003c */ 	sw	$t5,0x3c($s4)
/*  f166d94:	18600004 */ 	blez	$v1,.NB0f166da8
/*  f166d98:	ae8e0038 */ 	sw	$t6,0x38($s4)
/*  f166d9c:	8e8f000c */ 	lw	$t7,0xc($s4)
/*  f166da0:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f166da4:	ae98000c */ 	sw	$t8,0xc($s4)
.NB0f166da8:
/*  f166da8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f166dac:	3c013e80 */ 	lui	$at,0x3e80
/*  f166db0:	44814000 */ 	mtc1	$at,$f8
/*  f166db4:	8e990008 */ 	lw	$t9,0x8($s4)
/*  f166db8:	8e8c0038 */ 	lw	$t4,0x38($s4)
/*  f166dbc:	8e8e0030 */ 	lw	$t6,0x30($s4)
/*  f166dc0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f166dc4:	c690004c */ 	lwc1	$f16,0x4c($s4)
/*  f166dc8:	032c6821 */ 	addu	$t5,$t9,$t4
/*  f166dcc:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f166dd0:	ae8d0008 */ 	sw	$t5,0x8($s4)
/*  f166dd4:	ae8f0030 */ 	sw	$t7,0x30($s4)
/*  f166dd8:	e6900050 */ 	swc1	$f16,0x50($s4)
/*  f166ddc:	e68a0044 */ 	swc1	$f10,0x44($s4)
/*  f166de0:	c6920044 */ 	lwc1	$f18,0x44($s4)
/*  f166de4:	0fc2a662 */ 	jal	bgunTickBoost
/*  f166de8:	e692004c */ 	swc1	$f18,0x4c($s4)
/*  f166dec:	0fc37207 */ 	jal	hudmsgsTick
/*  f166df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166df4:	00002025 */ 	or	$a0,$zero,$zero
/*  f166df8:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*  f166dfc:	3405ffff */ 	dli	$a1,0xffff
/*  f166e00:	1440005c */ 	bnez	$v0,.NB0f166f74
/*  f166e04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166e08:	0c00573c */ 	jal	joyGetStickX
/*  f166e0c:	00002025 */ 	or	$a0,$zero,$zero
/*  f166e10:	2841000b */ 	slti	$at,$v0,0xb
/*  f166e14:	10200057 */ 	beqz	$at,.NB0f166f74
/*  f166e18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166e1c:	0c00573c */ 	jal	joyGetStickX
/*  f166e20:	00002025 */ 	or	$a0,$zero,$zero
/*  f166e24:	2841fff6 */ 	slti	$at,$v0,-10
/*  f166e28:	14200052 */ 	bnez	$at,.NB0f166f74
/*  f166e2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166e30:	0c005766 */ 	jal	joyGetStickY
/*  f166e34:	00002025 */ 	or	$a0,$zero,$zero
/*  f166e38:	2841000b */ 	slti	$at,$v0,0xb
/*  f166e3c:	1020004d */ 	beqz	$at,.NB0f166f74
/*  f166e40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166e44:	0c005766 */ 	jal	joyGetStickY
/*  f166e48:	00002025 */ 	or	$a0,$zero,$zero
/*  f166e4c:	2841fff6 */ 	slti	$at,$v0,-10
/*  f166e50:	14200048 */ 	bnez	$at,.NB0f166f74
/*  f166e54:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f166e58:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*  f166e5c:	3405ffff */ 	dli	$a1,0xffff
/*  f166e60:	14400044 */ 	bnez	$v0,.NB0f166f74
/*  f166e64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166e68:	0c00573c */ 	jal	joyGetStickX
/*  f166e6c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f166e70:	2841000b */ 	slti	$at,$v0,0xb
/*  f166e74:	1020003f */ 	beqz	$at,.NB0f166f74
/*  f166e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166e7c:	0c00573c */ 	jal	joyGetStickX
/*  f166e80:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f166e84:	2841fff6 */ 	slti	$at,$v0,-10
/*  f166e88:	1420003a */ 	bnez	$at,.NB0f166f74
/*  f166e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166e90:	0c005766 */ 	jal	joyGetStickY
/*  f166e94:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f166e98:	2841000b */ 	slti	$at,$v0,0xb
/*  f166e9c:	10200035 */ 	beqz	$at,.NB0f166f74
/*  f166ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166ea4:	0c005766 */ 	jal	joyGetStickY
/*  f166ea8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f166eac:	2841fff6 */ 	slti	$at,$v0,-10
/*  f166eb0:	14200030 */ 	bnez	$at,.NB0f166f74
/*  f166eb4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f166eb8:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*  f166ebc:	3405ffff */ 	dli	$a1,0xffff
/*  f166ec0:	1440002c */ 	bnez	$v0,.NB0f166f74
/*  f166ec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166ec8:	0c00573c */ 	jal	joyGetStickX
/*  f166ecc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f166ed0:	2841000b */ 	slti	$at,$v0,0xb
/*  f166ed4:	10200027 */ 	beqz	$at,.NB0f166f74
/*  f166ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166edc:	0c00573c */ 	jal	joyGetStickX
/*  f166ee0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f166ee4:	2841fff6 */ 	slti	$at,$v0,-10
/*  f166ee8:	14200022 */ 	bnez	$at,.NB0f166f74
/*  f166eec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166ef0:	0c005766 */ 	jal	joyGetStickY
/*  f166ef4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f166ef8:	2841000b */ 	slti	$at,$v0,0xb
/*  f166efc:	1020001d */ 	beqz	$at,.NB0f166f74
/*  f166f00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166f04:	0c005766 */ 	jal	joyGetStickY
/*  f166f08:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f166f0c:	2841fff6 */ 	slti	$at,$v0,-10
/*  f166f10:	14200018 */ 	bnez	$at,.NB0f166f74
/*  f166f14:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f166f18:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*  f166f1c:	3405ffff */ 	dli	$a1,0xffff
/*  f166f20:	14400014 */ 	bnez	$v0,.NB0f166f74
/*  f166f24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166f28:	0c00573c */ 	jal	joyGetStickX
/*  f166f2c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f166f30:	2841000b */ 	slti	$at,$v0,0xb
/*  f166f34:	1020000f */ 	beqz	$at,.NB0f166f74
/*  f166f38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166f3c:	0c00573c */ 	jal	joyGetStickX
/*  f166f40:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f166f44:	2841fff6 */ 	slti	$at,$v0,-10
/*  f166f48:	1420000a */ 	bnez	$at,.NB0f166f74
/*  f166f4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166f50:	0c005766 */ 	jal	joyGetStickY
/*  f166f54:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f166f58:	2841000b */ 	slti	$at,$v0,0xb
/*  f166f5c:	10200005 */ 	beqz	$at,.NB0f166f74
/*  f166f60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166f64:	0c005766 */ 	jal	joyGetStickY
/*  f166f68:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f166f6c:	2841fff6 */ 	slti	$at,$v0,-10
/*  f166f70:	1020000e */ 	beqz	$at,.NB0f166fac
.NB0f166f74:
/*  f166f74:	3c108006 */ 	lui	$s0,0x8006
/*  f166f78:	261049b4 */ 	addiu	$s0,$s0,0x49b4
/*  f166f7c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f166f80:	5300000b */ 	beqzl	$t8,.NB0f166fb0
/*  f166f84:	8e8c04b4 */ 	lw	$t4,0x4b4($s4)
/*  f166f88:	8e9904b4 */ 	lw	$t9,0x4b4($s4)
/*  f166f8c:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f166f90:	53210006 */ 	beql	$t9,$at,.NB0f166fac
/*  f166f94:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f166f98:	0fc06945 */ 	jal	titleSetNextMode
/*  f166f9c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f166fa0:	0c003c56 */ 	jal	mainSetStageNum
/*  f166fa4:	2404005a */ 	addiu	$a0,$zero,0x5a
/*  f166fa8:	ae000000 */ 	sw	$zero,0x0($s0)
.NB0f166fac:
/*  f166fac:	8e8c04b4 */ 	lw	$t4,0x4b4($s4)
.NB0f166fb0:
/*  f166fb0:	3c108006 */ 	lui	$s0,0x8006
/*  f166fb4:	261049b4 */ 	addiu	$s0,$s0,0x49b4
/*  f166fb8:	2981005a */ 	slti	$at,$t4,0x5a
/*  f166fbc:	10200072 */ 	beqz	$at,.NB0f167188
/*  f166fc0:	3c028006 */ 	lui	$v0,0x8006
/*  f166fc4:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f166fc8:	15a0006f */ 	bnez	$t5,.NB0f167188
/*  f166fcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166fd0:	8e8e04cc */ 	lw	$t6,0x4cc($s4)
/*  f166fd4:	00002025 */ 	or	$a0,$zero,$zero
/*  f166fd8:	15c0006b */ 	bnez	$t6,.NB0f167188
/*  f166fdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166fe0:	0c005790 */ 	jal	joyGetButtons
/*  f166fe4:	3405ffff */ 	dli	$a1,0xffff
/*  f166fe8:	14400063 */ 	bnez	$v0,.NB0f167178
/*  f166fec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f166ff0:	0c00573c */ 	jal	joyGetStickX
/*  f166ff4:	00002025 */ 	or	$a0,$zero,$zero
/*  f166ff8:	2841000a */ 	slti	$at,$v0,0xa
/*  f166ffc:	1020005e */ 	beqz	$at,.NB0f167178
/*  f167000:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167004:	0c00573c */ 	jal	joyGetStickX
/*  f167008:	00002025 */ 	or	$a0,$zero,$zero
/*  f16700c:	2841fff7 */ 	slti	$at,$v0,-9
/*  f167010:	14200059 */ 	bnez	$at,.NB0f167178
/*  f167014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167018:	0c005766 */ 	jal	joyGetStickY
/*  f16701c:	00002025 */ 	or	$a0,$zero,$zero
/*  f167020:	2841000a */ 	slti	$at,$v0,0xa
/*  f167024:	10200054 */ 	beqz	$at,.NB0f167178
/*  f167028:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16702c:	0c005766 */ 	jal	joyGetStickY
/*  f167030:	00002025 */ 	or	$a0,$zero,$zero
/*  f167034:	2841fff7 */ 	slti	$at,$v0,-9
/*  f167038:	1420004f */ 	bnez	$at,.NB0f167178
/*  f16703c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f167040:	0c005790 */ 	jal	joyGetButtons
/*  f167044:	3405ffff */ 	dli	$a1,0xffff
/*  f167048:	1440004b */ 	bnez	$v0,.NB0f167178
/*  f16704c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167050:	0c00573c */ 	jal	joyGetStickX
/*  f167054:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f167058:	2841000a */ 	slti	$at,$v0,0xa
/*  f16705c:	10200046 */ 	beqz	$at,.NB0f167178
/*  f167060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167064:	0c00573c */ 	jal	joyGetStickX
/*  f167068:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16706c:	2841fff7 */ 	slti	$at,$v0,-9
/*  f167070:	14200041 */ 	bnez	$at,.NB0f167178
/*  f167074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167078:	0c005766 */ 	jal	joyGetStickY
/*  f16707c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f167080:	2841000a */ 	slti	$at,$v0,0xa
/*  f167084:	1020003c */ 	beqz	$at,.NB0f167178
/*  f167088:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16708c:	0c005766 */ 	jal	joyGetStickY
/*  f167090:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f167094:	2841fff7 */ 	slti	$at,$v0,-9
/*  f167098:	14200037 */ 	bnez	$at,.NB0f167178
/*  f16709c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1670a0:	0c005790 */ 	jal	joyGetButtons
/*  f1670a4:	3405ffff */ 	dli	$a1,0xffff
/*  f1670a8:	14400033 */ 	bnez	$v0,.NB0f167178
/*  f1670ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1670b0:	0c00573c */ 	jal	joyGetStickX
/*  f1670b4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1670b8:	2841000a */ 	slti	$at,$v0,0xa
/*  f1670bc:	1020002e */ 	beqz	$at,.NB0f167178
/*  f1670c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1670c4:	0c00573c */ 	jal	joyGetStickX
/*  f1670c8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1670cc:	2841fff7 */ 	slti	$at,$v0,-9
/*  f1670d0:	14200029 */ 	bnez	$at,.NB0f167178
/*  f1670d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1670d8:	0c005766 */ 	jal	joyGetStickY
/*  f1670dc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1670e0:	2841000a */ 	slti	$at,$v0,0xa
/*  f1670e4:	10200024 */ 	beqz	$at,.NB0f167178
/*  f1670e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1670ec:	0c005766 */ 	jal	joyGetStickY
/*  f1670f0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1670f4:	2841fff7 */ 	slti	$at,$v0,-9
/*  f1670f8:	1420001f */ 	bnez	$at,.NB0f167178
/*  f1670fc:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f167100:	0c005790 */ 	jal	joyGetButtons
/*  f167104:	3405ffff */ 	dli	$a1,0xffff
/*  f167108:	1440001b */ 	bnez	$v0,.NB0f167178
/*  f16710c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167110:	0c00573c */ 	jal	joyGetStickX
/*  f167114:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f167118:	2841000a */ 	slti	$at,$v0,0xa
/*  f16711c:	10200016 */ 	beqz	$at,.NB0f167178
/*  f167120:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167124:	0c00573c */ 	jal	joyGetStickX
/*  f167128:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f16712c:	2841fff7 */ 	slti	$at,$v0,-9
/*  f167130:	14200011 */ 	bnez	$at,.NB0f167178
/*  f167134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167138:	0c005766 */ 	jal	joyGetStickY
/*  f16713c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f167140:	2841000a */ 	slti	$at,$v0,0xa
/*  f167144:	1020000c */ 	beqz	$at,.NB0f167178
/*  f167148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16714c:	0c005766 */ 	jal	joyGetStickY
/*  f167150:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f167154:	2841fff7 */ 	slti	$at,$v0,-9
/*  f167158:	14200007 */ 	bnez	$at,.NB0f167178
/*  f16715c:	3c028006 */ 	lui	$v0,0x8006
/*  f167160:	244249c0 */ 	addiu	$v0,$v0,0x49c0
/*  f167164:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f167168:	8e980000 */ 	lw	$t8,0x0($s4)
/*  f16716c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f167170:	10000007 */ 	beqz	$zero,.NB0f167190
/*  f167174:	ac590000 */ 	sw	$t9,0x0($v0)
.NB0f167178:
/*  f167178:	3c028006 */ 	lui	$v0,0x8006
/*  f16717c:	244249c0 */ 	addiu	$v0,$v0,0x49c0
/*  f167180:	10000003 */ 	beqz	$zero,.NB0f167190
/*  f167184:	ac400000 */ 	sw	$zero,0x0($v0)
.NB0f167188:
/*  f167188:	244249c0 */ 	addiu	$v0,$v0,0x49c0
/*  f16718c:	ac400000 */ 	sw	$zero,0x0($v0)
.NB0f167190:
/*  f167190:	8e8c0318 */ 	lw	$t4,0x318($s4)
/*  f167194:	3c118008 */ 	lui	$s1,0x8008
/*  f167198:	26316898 */ 	addiu	$s1,$s1,0x6898
/*  f16719c:	11800116 */ 	beqz	$t4,.NB0f1675f8
/*  f1671a0:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f1671a4:	8e8d04b4 */ 	lw	$t5,0x4b4($s4)
/*  f1671a8:	3c068008 */ 	lui	$a2,0x8008
/*  f1671ac:	29a1005a */ 	slti	$at,$t5,0x5a
/*  f1671b0:	10200111 */ 	beqz	$at,.NB0f1675f8
/*  f1671b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1671b8:	8cc66888 */ 	lw	$a2,0x6888($a2)
/*  f1671bc:	3c028008 */ 	lui	$v0,0x8008
/*  f1671c0:	58c00077 */ 	blezl	$a2,.NB0f1673a0
/*  f1671c4:	8e8c0034 */ 	lw	$t4,0x34($s4)
/*  f1671c8:	8c536884 */ 	lw	$s3,0x6884($v0)
/*  f1671cc:	8e8e0038 */ 	lw	$t6,0x38($s4)
/*  f1671d0:	24c3f1f0 */ 	addiu	$v1,$a2,-3600
/*  f1671d4:	0263082a */ 	slt	$at,$s3,$v1
/*  f1671d8:	10200048 */ 	beqz	$at,.NB0f1672fc
/*  f1671dc:	01d39021 */ 	addu	$s2,$t6,$s3
/*  f1671e0:	0243082a */ 	slt	$at,$s2,$v1
/*  f1671e4:	54200046 */ 	bnezl	$at,.NB0f167300
/*  f1671e8:	0266082a */ 	slt	$at,$s3,$a2
/*  f1671ec:	8e8f006c */ 	lw	$t7,0x6c($s4)
/*  f1671f0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1671f4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1671f8:	11e00003 */ 	beqz	$t7,.NB0f167208
/*  f1671fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f167200:	10000001 */ 	beqz	$zero,.NB0f167208
/*  f167204:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f167208:
/*  f167208:	8e980068 */ 	lw	$t8,0x68($s4)
/*  f16720c:	00001825 */ 	or	$v1,$zero,$zero
/*  f167210:	00001025 */ 	or	$v0,$zero,$zero
/*  f167214:	13000003 */ 	beqz	$t8,.NB0f167224
/*  f167218:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16721c:	10000001 */ 	beqz	$zero,.NB0f167224
/*  f167220:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f167224:
/*  f167224:	8e990064 */ 	lw	$t9,0x64($s4)
/*  f167228:	13200003 */ 	beqz	$t9,.NB0f167238
/*  f16722c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167230:	10000001 */ 	beqz	$zero,.NB0f167238
/*  f167234:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f167238:
/*  f167238:	8e8c0070 */ 	lw	$t4,0x70($s4)
/*  f16723c:	11800003 */ 	beqz	$t4,.NB0f16724c
/*  f167240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167244:	10000001 */ 	beqz	$zero,.NB0f16724c
/*  f167248:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f16724c:
/*  f16724c:	00436821 */ 	addu	$t5,$v0,$v1
/*  f167250:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f167254:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f167258:	59e00029 */ 	blezl	$t7,.NB0f167300
/*  f16725c:	0266082a */ 	slt	$at,$s3,$a2
.NB0f167260:
/*  f167260:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f167264:	02002025 */ 	or	$a0,$s0,$zero
/*  f167268:	0fc5a4dd */ 	jal	langGet
/*  f16726c:	24045844 */ 	addiu	$a0,$zero,0x5844
/*  f167270:	00402025 */ 	or	$a0,$v0,$zero
/*  f167274:	0fc36d4d */ 	jal	hudmsgCreate
/*  f167278:	00002825 */ 	or	$a1,$zero,$zero
/*  f16727c:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f167280:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f167284:	00002825 */ 	or	$a1,$zero,$zero
/*  f167288:	13000003 */ 	beqz	$t8,.NB0f167298
/*  f16728c:	00002025 */ 	or	$a0,$zero,$zero
/*  f167290:	10000001 */ 	beqz	$zero,.NB0f167298
/*  f167294:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f167298:
/*  f167298:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f16729c:	00001825 */ 	or	$v1,$zero,$zero
/*  f1672a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1672a4:	13200003 */ 	beqz	$t9,.NB0f1672b4
/*  f1672a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1672ac:	10000001 */ 	beqz	$zero,.NB0f1672b4
/*  f1672b0:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f1672b4:
/*  f1672b4:	8e8c0064 */ 	lw	$t4,0x64($s4)
/*  f1672b8:	11800003 */ 	beqz	$t4,.NB0f1672c8
/*  f1672bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1672c0:	10000001 */ 	beqz	$zero,.NB0f1672c8
/*  f1672c4:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f1672c8:
/*  f1672c8:	8e8d0070 */ 	lw	$t5,0x70($s4)
/*  f1672cc:	11a00003 */ 	beqz	$t5,.NB0f1672dc
/*  f1672d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1672d4:	10000001 */ 	beqz	$zero,.NB0f1672dc
/*  f1672d8:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f1672dc:
/*  f1672dc:	00437021 */ 	addu	$t6,$v0,$v1
/*  f1672e0:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f1672e4:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f1672e8:	0218082a */ 	slt	$at,$s0,$t8
/*  f1672ec:	1420ffdc */ 	bnez	$at,.NB0f167260
/*  f1672f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1672f4:	3c068008 */ 	lui	$a2,0x8008
/*  f1672f8:	8cc66888 */ 	lw	$a2,0x6888($a2)
.NB0f1672fc:
/*  f1672fc:	0266082a */ 	slt	$at,$s3,$a2
.NB0f167300:
/*  f167300:	10200007 */ 	beqz	$at,.NB0f167320
/*  f167304:	0246082a */ 	slt	$at,$s2,$a2
/*  f167308:	54200006 */ 	bnezl	$at,.NB0f167324
/*  f16730c:	24d9fda8 */ 	addiu	$t9,$a2,-600
/*  f167310:	0c003ba2 */ 	jal	mainEndStage
/*  f167314:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167318:	3c068008 */ 	lui	$a2,0x8008
/*  f16731c:	8cc66888 */ 	lw	$a2,0x6888($a2)
.NB0f167320:
/*  f167320:	24d9fda8 */ 	addiu	$t9,$a2,-600
.NB0f167324:
/*  f167324:	0259082a */ 	slt	$at,$s2,$t9
/*  f167328:	1420001c */ 	bnez	$at,.NB0f16739c
/*  f16732c:	3c108008 */ 	lui	$s0,0x8008
/*  f167330:	26106894 */ 	addiu	$s0,$s0,0x6894
/*  f167334:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f167338:	55800019 */ 	bnezl	$t4,.NB0f1673a0
/*  f16733c:	8e8c0034 */ 	lw	$t4,0x34($s4)
/*  f167340:	0fc59ed0 */ 	jal	lvIsPaused
/*  f167344:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167348:	14400014 */ 	bnez	$v0,.NB0f16739c
/*  f16734c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f167350:	8dad6888 */ 	lw	$t5,0x6888($t5)
/*  f167354:	02002025 */ 	or	$a0,$s0,$zero
/*  f167358:	00002825 */ 	or	$a1,$zero,$zero
/*  f16735c:	024d082a */ 	slt	$at,$s2,$t5
/*  f167360:	1020000e */ 	beqz	$at,.NB0f16739c
/*  f167364:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f167368:	3c013f80 */ 	lui	$at,0x3f80
/*  f16736c:	44812000 */ 	mtc1	$at,$f4
/*  f167370:	240e00a3 */ 	addiu	$t6,$zero,0xa3
/*  f167374:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f167378:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f16737c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f167380:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f167384:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f167388:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f16738c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f167390:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f167394:	0c0042bf */ 	jal	snd00010718
/*  f167398:	e7a40014 */ 	swc1	$f4,0x14($sp)
.NB0f16739c:
/*  f16739c:	8e8c0034 */ 	lw	$t4,0x34($s4)
.NB0f1673a0:
/*  f1673a0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1673a4:	00005825 */ 	or	$t3,$zero,$zero
/*  f1673a8:	11800093 */ 	beqz	$t4,.NB0f1675f8
/*  f1673ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1673b0:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f1673b4:	8e870068 */ 	lw	$a3,0x68($s4)
/*  f1673b8:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f1673bc:	11200003 */ 	beqz	$t1,.NB0f1673cc
/*  f1673c0:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f1673c4:	10000002 */ 	beqz	$zero,.NB0f1673d0
/*  f1673c8:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f1673cc:
/*  f1673cc:	00002825 */ 	or	$a1,$zero,$zero
.NB0f1673d0:
/*  f1673d0:	10e00003 */ 	beqz	$a3,.NB0f1673e0
/*  f1673d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1673d8:	10000001 */ 	beqz	$zero,.NB0f1673e0
/*  f1673dc:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f1673e0:
/*  f1673e0:	11000003 */ 	beqz	$t0,.NB0f1673f0
/*  f1673e4:	00001825 */ 	or	$v1,$zero,$zero
/*  f1673e8:	10000001 */ 	beqz	$zero,.NB0f1673f0
/*  f1673ec:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f1673f0:
/*  f1673f0:	10c00003 */ 	beqz	$a2,.NB0f167400
/*  f1673f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1673f8:	10000001 */ 	beqz	$zero,.NB0f167400
/*  f1673fc:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f167400:
/*  f167400:	00436821 */ 	addu	$t5,$v0,$v1
/*  f167404:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f167408:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f16740c:	19e0002d */ 	blez	$t7,.NB0f1674c4
/*  f167410:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f167414:	44800000 */ 	mtc1	$zero,$f0
/*  f167418:	02985021 */ 	addu	$t2,$s4,$t8
/*  f16741c:	8d420064 */ 	lw	$v0,0x64($t2)
.NB0f167420:
/*  f167420:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f167424:	00002825 */ 	or	$a1,$zero,$zero
/*  f167428:	8c5900d8 */ 	lw	$t9,0xd8($v0)
/*  f16742c:	00002025 */ 	or	$a0,$zero,$zero
/*  f167430:	00001825 */ 	or	$v1,$zero,$zero
/*  f167434:	1320000d */ 	beqz	$t9,.NB0f16746c
/*  f167438:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16743c:	8c4c032c */ 	lw	$t4,0x32c($v0)
/*  f167440:	5180000a */ 	beqzl	$t4,.NB0f16746c
/*  f167444:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f167448:	8c4d0330 */ 	lw	$t5,0x330($v0)
/*  f16744c:	51a00007 */ 	beqzl	$t5,.NB0f16746c
/*  f167450:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f167454:	c44602ec */ 	lwc1	$f6,0x2ec($v0)
/*  f167458:	4606003e */ 	c.le.s	$f0,$f6
/*  f16745c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167460:	45000002 */ 	bc1f	.NB0f16746c
/*  f167464:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167468:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f16746c:
/*  f16746c:	11200003 */ 	beqz	$t1,.NB0f16747c
/*  f167470:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f167474:	10000001 */ 	beqz	$zero,.NB0f16747c
/*  f167478:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f16747c:
/*  f16747c:	10e00003 */ 	beqz	$a3,.NB0f16748c
/*  f167480:	00001025 */ 	or	$v0,$zero,$zero
/*  f167484:	10000001 */ 	beqz	$zero,.NB0f16748c
/*  f167488:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f16748c:
/*  f16748c:	11000003 */ 	beqz	$t0,.NB0f16749c
/*  f167490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167494:	10000001 */ 	beqz	$zero,.NB0f16749c
/*  f167498:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f16749c:
/*  f16749c:	10c00003 */ 	beqz	$a2,.NB0f1674ac
/*  f1674a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1674a4:	10000001 */ 	beqz	$zero,.NB0f1674ac
/*  f1674a8:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f1674ac:
/*  f1674ac:	00437021 */ 	addu	$t6,$v0,$v1
/*  f1674b0:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f1674b4:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f1674b8:	0178082a */ 	slt	$at,$t3,$t8
/*  f1674bc:	5420ffd8 */ 	bnezl	$at,.NB0f167420
/*  f1674c0:	8d420064 */ 	lw	$v0,0x64($t2)
.NB0f1674c4:
/*  f1674c4:	3c04800b */ 	lui	$a0,0x800b
/*  f1674c8:	8c840de0 */ 	lw	$a0,0xde0($a0)
/*  f1674cc:	3c19800b */ 	lui	$t9,0x800b
/*  f1674d0:	27220d80 */ 	addiu	$v0,$t9,0xd80
/*  f1674d4:	1880000c */ 	blez	$a0,.NB0f167508
/*  f1674d8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1674dc:	00046080 */ 	sll	$t4,$a0,0x2
/*  f1674e0:	01821821 */ 	addu	$v1,$t4,$v0
/*  f1674e4:	8c4d0000 */ 	lw	$t5,0x0($v0)
.NB0f1674e8:
/*  f1674e8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1674ec:	0043082b */ 	sltu	$at,$v0,$v1
/*  f1674f0:	81ae0007 */ 	lb	$t6,0x7($t5)
/*  f1674f4:	16ae0002 */ 	bne	$s5,$t6,.NB0f167500
/*  f1674f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1674fc:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f167500:
/*  f167500:	5420fff9 */ 	bnezl	$at,.NB0f1674e8
/*  f167504:	8c4d0000 */ 	lw	$t5,0x0($v0)
.NB0f167508:
/*  f167508:	8def688c */ 	lw	$t7,0x688c($t7)
/*  f16750c:	27a4016c */ 	addiu	$a0,$sp,0x16c
/*  f167510:	19e00017 */ 	blez	$t7,.NB0f167570
/*  f167514:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167518:	0fc60a7a */ 	jal	mpGetPlayerRankings
/*  f16751c:	00005825 */ 	or	$t3,$zero,$zero
/*  f167520:	18400013 */ 	blez	$v0,.NB0f167570
/*  f167524:	00401825 */ 	or	$v1,$v0,$zero
/*  f167528:	00036080 */ 	sll	$t4,$v1,0x2
/*  f16752c:	01836021 */ 	addu	$t4,$t4,$v1
/*  f167530:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f167534:	3c048008 */ 	lui	$a0,0x8008
/*  f167538:	27a2016c */ 	addiu	$v0,$sp,0x16c
/*  f16753c:	01822821 */ 	addu	$a1,$t4,$v0
/*  f167540:	8c84688c */ 	lw	$a0,0x688c($a0)
/*  f167544:	8c590010 */ 	lw	$t9,0x10($v0)
.NB0f167548:
/*  f167548:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f16754c:	0324082a */ 	slt	$at,$t9,$a0
/*  f167550:	54200005 */ 	bnezl	$at,.NB0f167568
/*  f167554:	0045082b */ 	sltu	$at,$v0,$a1
/*  f167558:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f16755c:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f167560:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f167564:	0045082b */ 	sltu	$at,$v0,$a1
.NB0f167568:
/*  f167568:	5420fff7 */ 	bnezl	$at,.NB0f167548
/*  f16756c:	8c590010 */ 	lw	$t9,0x10($v0)
.NB0f167570:
/*  f167570:	3c0f8008 */ 	lui	$t7,0x8008
/*  f167574:	8def6890 */ 	lw	$t7,0x6890($t7)
/*  f167578:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f16757c:	59e00018 */ 	blezl	$t7,.NB0f1675e0
/*  f167580:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f167584:	0fc60b9d */ 	jal	mpGetTeamRankings
/*  f167588:	00005825 */ 	or	$t3,$zero,$zero
/*  f16758c:	18400013 */ 	blez	$v0,.NB0f1675dc
/*  f167590:	00401825 */ 	or	$v1,$v0,$zero
/*  f167594:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f167598:	0303c021 */ 	addu	$t8,$t8,$v1
/*  f16759c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1675a0:	3c048008 */ 	lui	$a0,0x8008
/*  f1675a4:	27a20078 */ 	addiu	$v0,$sp,0x78
/*  f1675a8:	03022821 */ 	addu	$a1,$t8,$v0
/*  f1675ac:	8c846890 */ 	lw	$a0,0x6890($a0)
/*  f1675b0:	8c590010 */ 	lw	$t9,0x10($v0)
.NB0f1675b4:
/*  f1675b4:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f1675b8:	0324082a */ 	slt	$at,$t9,$a0
/*  f1675bc:	54200005 */ 	bnezl	$at,.NB0f1675d4
/*  f1675c0:	0045082b */ 	sltu	$at,$v0,$a1
/*  f1675c4:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f1675c8:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f1675cc:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f1675d0:	0045082b */ 	sltu	$at,$v0,$a1
.NB0f1675d4:
/*  f1675d4:	5420fff7 */ 	bnezl	$at,.NB0f1675b4
/*  f1675d8:	8c590010 */ 	lw	$t9,0x10($v0)
.NB0f1675dc:
/*  f1675dc:	8e2f0000 */ 	lw	$t7,0x0($s1)
.NB0f1675e0:
/*  f1675e0:	19e00005 */ 	blez	$t7,.NB0f1675f8
/*  f1675e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1675e8:	16000003 */ 	bnez	$s0,.NB0f1675f8
/*  f1675ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1675f0:	0c003ba2 */ 	jal	mainEndStage
/*  f1675f4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1675f8:
/*  f1675f8:	3c188008 */ 	lui	$t8,0x8008
/*  f1675fc:	8f186884 */ 	lw	$t8,0x6884($t8)
/*  f167600:	8e8c0038 */ 	lw	$t4,0x38($s4)
/*  f167604:	3c018008 */ 	lui	$at,0x8008
/*  f167608:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16760c:	030cc821 */ 	addu	$t9,$t8,$t4
/*  f167610:	44994000 */ 	mtc1	$t9,$f8
/*  f167614:	ac396884 */ 	sw	$t9,0x6884($at)
/*  f167618:	3c014270 */ 	lui	$at,0x4270
/*  f16761c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f167620:	44818000 */ 	mtc1	$at,$f16
/*  f167624:	3c018008 */ 	lui	$at,0x8008
/*  f167628:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f16762c:	0c002fbd */ 	jal	viSetUseZBuf
/*  f167630:	e432689c */ 	swc1	$f18,0x689c($at)
/*  f167634:	8e8204b4 */ 	lw	$v0,0x4b4($s4)
/*  f167638:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f16763c:	54410007 */ 	bnel	$v0,$at,.NB0f16765c
/*  f167640:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f167644:	0fc06ad8 */ 	jal	titleTickOld
/*  f167648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16764c:	0c004848 */ 	jal	func00011d84
/*  f167650:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167654:	8e8204b4 */ 	lw	$v0,0x4b4($s4)
/*  f167658:	2401005a */ 	addiu	$at,$zero,0x5a
.NB0f16765c:
/*  f16765c:	5441000a */ 	bnel	$v0,$at,.NB0f167688
/*  f167660:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f167664:	0fc06950 */ 	jal	titleTick
/*  f167668:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16766c:	0fc07550 */ 	jal	func0f01d860
/*  f167670:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167674:	0c004848 */ 	jal	func00011d84
/*  f167678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16767c:	10000087 */ 	beqz	$zero,.NB0f16789c
/*  f167680:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f167684:	2401005b */ 	addiu	$at,$zero,0x5b
.NB0f167688:
/*  f167688:	5441000e */ 	bnel	$v0,$at,.NB0f1676c4
/*  f16768c:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f167690:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f167694:	00002025 */ 	or	$a0,$zero,$zero
/*  f167698:	0fc06f0a */ 	jal	menuTickAll
/*  f16769c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1676a0:	0c004848 */ 	jal	func00011d84
/*  f1676a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1676a8:	0fc07550 */ 	jal	func0f01d860
/*  f1676ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1676b0:	0fc45920 */ 	jal	pakExecuteDebugOperations
/*  f1676b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1676b8:	10000078 */ 	beqz	$zero,.NB0f16789c
/*  f1676bc:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1676c0:	2401005d */ 	addiu	$at,$zero,0x5d
.NB0f1676c4:
/*  f1676c4:	5441000c */ 	bnel	$v0,$at,.NB0f1676f8
/*  f1676c8:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f1676cc:	0fc06f0a */ 	jal	menuTickAll
/*  f1676d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1676d4:	0c004848 */ 	jal	func00011d84
/*  f1676d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1676dc:	0fc07550 */ 	jal	func0f01d860
/*  f1676e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1676e4:	0fc45920 */ 	jal	pakExecuteDebugOperations
/*  f1676e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1676ec:	1000006b */ 	beqz	$zero,.NB0f16789c
/*  f1676f0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1676f4:	2401005c */ 	addiu	$at,$zero,0x5c
.NB0f1676f8:
/*  f1676f8:	14410007 */ 	bne	$v0,$at,.NB0f167718
/*  f1676fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167700:	0c004848 */ 	jal	func00011d84
/*  f167704:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167708:	0fc07550 */ 	jal	func0f01d860
/*  f16770c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167710:	10000062 */ 	beqz	$zero,.NB0f16789c
/*  f167714:	8fbf0044 */ 	lw	$ra,0x44($sp)
.NB0f167718:
/*  f167718:	0fc5998f */ 	jal	lvUpdateCutsceneTime
/*  f16771c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167720:	0fc48ff7 */ 	jal	func0f12939c
/*  f167724:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167728:	0fc597c1 */ 	jal	lvUpdateSoloHandicaps
/*  f16772c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167730:	0fc07568 */ 	jal	func0f01d8c0
/*  f167734:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167738:	0fc0759c */ 	jal	func0f01d990
/*  f16773c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167740:	0fc07693 */ 	jal	casingsTick
/*  f167744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167748:	0fc076c4 */ 	jal	shardsTick
/*  f16774c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167750:	0fc0774c */ 	jal	sparksTick
/*  f167754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167758:	0fc4e591 */ 	jal	func0f13eb44
/*  f16775c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167760:	0fc5100d */ 	jal	func0f149864
/*  f167764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167768:	3c0d8006 */ 	lui	$t5,0x8006
/*  f16776c:	8dad4900 */ 	lw	$t5,0x4900($t5)
/*  f167770:	11a00003 */ 	beqz	$t5,.NB0f167780
/*  f167774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167778:	0fc07514 */ 	jal	weatherTick
/*  f16777c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f167780:
/*  f167780:	3c0e8006 */ 	lui	$t6,0x8006
/*  f167784:	8dce3b50 */ 	lw	$t6,0x3b50($t6)
/*  f167788:	11c00003 */ 	beqz	$t6,.NB0f167798
/*  f16778c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167790:	0fc026dd */ 	jal	nbombsTick
/*  f167794:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f167798:
/*  f167798:	0fc58971 */ 	jal	lvUpdateMiscSfx
/*  f16779c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1677a0:	0c0040f6 */ 	jal	sndTick
/*  f1677a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1677a8:	0fc45920 */ 	jal	pakExecuteDebugOperations
/*  f1677ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1677b0:	0fc00d10 */ 	jal	lightingTick
/*  f1677b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1677b8:	0fc2c199 */ 	jal	func0f0b2904
/*  f1677bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1677c0:	0fc2b346 */ 	jal	func0f0aefb8
/*  f1677c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1677c8:	0fc06ba4 */ 	jal	amTick
/*  f1677cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1677d0:	0fc06f0a */ 	jal	menuTickAll
/*  f1677d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1677d8:	0fc5ff13 */ 	jal	scenarioTick
/*  f1677dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1677e0:	3c0f8006 */ 	lui	$t7,0x8006
/*  f1677e4:	8deff2f0 */ 	lw	$t7,-0xd10($t7)
/*  f1677e8:	15e00003 */ 	bnez	$t7,.NB0f1677f8
/*  f1677ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1677f0:	0fc077cc */ 	jal	propsTick2
/*  f1677f4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1677f8:
/*  f1677f8:	0c004848 */ 	jal	func00011d84
/*  f1677fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167800:	0fc07550 */ 	jal	func0f01d860
/*  f167804:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167808:	0fc18c10 */ 	jal	propsTickPadEffects
/*  f16780c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167810:	0c003c59 */ 	jal	mainGetStageNum
/*  f167814:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167818:	24010026 */ 	addiu	$at,$zero,0x26
/*  f16781c:	5441001f */ 	bnel	$v0,$at,.NB0f16789c
/*  f167820:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f167824:	0fc66e0a */ 	jal	dtGetData
/*  f167828:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16782c:	8e980284 */ 	lw	$t8,0x284($s4)
/*  f167830:	8f0c00bc */ 	lw	$t4,0xbc($t8)
/*  f167834:	85830028 */ 	lh	$v1,0x28($t4)
/*  f167838:	28610016 */ 	slti	$at,$v1,0x16
/*  f16783c:	14200002 */ 	bnez	$at,.NB0f167848
/*  f167840:	2861001a */ 	slti	$at,$v1,0x1a
/*  f167844:	1420000b */ 	bnez	$at,.NB0f167874
.NB0f167848:
/*  f167848:	2401000a */ 	addiu	$at,$zero,0xa
/*  f16784c:	10610009 */ 	beq	$v1,$at,.NB0f167874
/*  f167850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167854:	10400005 */ 	beqz	$v0,.NB0f16786c
/*  f167858:	00002025 */ 	or	$a0,$zero,$zero
/*  f16785c:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f167860:	00196fc2 */ 	srl	$t5,$t9,0x1f
/*  f167864:	15a00003 */ 	bnez	$t5,.NB0f167874
/*  f167868:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f16786c:
/*  f16786c:	0fc124ce */ 	jal	chrUnsetStageFlag
/*  f167870:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f167874:
/*  f167874:	0fc66666 */ 	jal	frTick
/*  f167878:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16787c:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f167880:	51c00006 */ 	beqzl	$t6,.NB0f16789c
/*  f167884:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f167888:	0fc66e6a */ 	jal	dtTick
/*  f16788c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167890:	0fc67020 */ 	jal	htTick
/*  f167894:	00000000 */ 	sll	$zero,$zero,0x0
/*  f167898:	8fbf0044 */ 	lw	$ra,0x44($sp)
.NB0f16789c:
/*  f16789c:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f1678a0:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f1678a4:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f1678a8:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f1678ac:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f1678b0:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f1678b4:	03e00008 */ 	jr	$ra
/*  f1678b8:	27bd0290 */ 	addiu	$sp,$sp,0x290
);
#endif

void lvRecordDistanceMoved(void)
{
	f32 xdiff;
	f32 zdiff;

	if (var80075d64 == 2) {
		if (var80075d68 == 2) {
			func0f0bd904(true);
		} else {
			func0f0bd904(false);
		}
	}

	xdiff = g_Vars.currentplayer->prop->pos.x - g_Vars.currentplayer->bondprevpos.x;
	zdiff = g_Vars.currentplayer->prop->pos.z - g_Vars.currentplayer->bondprevpos.z;

	g_Vars.currentplayerstats->distance += sqrtf(xdiff * xdiff + zdiff * zdiff);
}

void lvReset(void)
{
	func0f11dcb0(1);

	if (g_MiscAudioHandle && audioIsPlaying(g_MiscAudioHandle)) {
		audioStop(g_MiscAudioHandle);
	}

	if (g_Vars.stagenum < NUM_STAGES) {
		s32 bank = langGetLangBankIndexFromStagenum(g_Vars.stagenum);
		langClearBank(bank);
		stub0f015270();
	}

	chrsReset();
	explosionsReset();
	smokeReset();
	stub0f015400();
	stub0f015410();
	shardsReset();
	stub0f0153f0();
	alarmReset();
	objsReset(); // props/setup related
	weatherReset();
	objectivesAutocomplete();
	stub0f015260();
	func0f015470();
	func0f0150a0();
	musicReset();
	hudmsgsReset();

	if (g_Vars.stagenum < NUM_STAGES) {
		func0f15c850();
	}

	func00033dd8();

	if (g_FileState == FILESTATE_CHANGINGAGENT) {
		menuPlaySound(MENUSOUND_EXPLOSION);
		g_FileState = FILESTATE_UNSELECTED;
	}

#if VERSION >= VERSION_NTSC_1_0
	func0f01bea0();
#endif
}

void lvCheckPauseStateChanged(void)
{
	u32 paused = mpIsPaused();

	if (paused != var80084010) {
		if (paused) {
			func0f11deb8();
		} else {
			func0f11df38();
		}
	}

	var80084010 = paused;
}

void lvSetPaused(bool paused)
{
	if (paused) {
		func0f11deb8();
		snd0000fe20();
	} else {
		snd0000fe50();
		func0f11df38();
	}

	var80084014 = paused;
}

bool lvIsPaused(void)
{
	return var80084014;
}

s32 lvGetDifficulty(void)
{
	return g_Difficulty;
}

void lvSetDifficulty(s32 difficulty)
{
	if (difficulty < DIFF_A || difficulty > DIFF_PD) {
		difficulty = DIFF_A;
	}

	g_Difficulty = difficulty;
}

void lvSetMpTimeLimit60(u32 limit)
{
	g_MpTimeLimit60 = limit;
}

void lvSetMpScoreLimit(u32 limit)
{
	g_MpScoreLimit = limit;
}

void lvSetMpTeamScoreLimit(u32 limit)
{
	g_MpTeamScoreLimit = limit;
}

f32 lvGetStageTimeInSeconds(void)
{
	return g_StageTimeElapsed1f;
}

s32 lvGetStageTime60(void)
{
	return g_StageTimeElapsed60;
}

u32 func0f16ce04(u32 arg0)
{
	return arg0;
}
