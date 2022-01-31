#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/game_006900.h"
#include "game/game_006bd0.h"
#include "game/game_02cde0.h"
#include "game/game_095320.h"
#include "game/game_096ca0.h"
#include "game/bondgun.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/game_0b69d0.h"
#include "game/game_1a7560.h"
#include "game/savebuffer.h"
#include "game/game_0e0770.h"
#include "game/menu/items.h"
#include "game/game_0f09f0.h"
#include "game/filemgr.h"
#include "game/credits.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/mplayer/setup.h"
#include "game/music.h"
#include "game/texdecompress.h"
#include "game/mplayer/setup.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/game_1a78b0.h"
#include "game/gamefile.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/options.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/joy.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_PAL_FINAL
char g_CheatMarqueeString[300];
#elif VERSION >= VERSION_NTSC_1_0
char g_CheatMarqueeString[252];
#else
char g_StringPointer[104];
char g_StringPointer2[100];
#endif

u8 *g_BlurBuffer;
s32 var8009dfc0;
u32 var8009dfc4;
struct briefing g_Briefing;
u32 var8009dfe4;
struct missionconfig g_MissionConfig;
struct menu g_Menus[4];
struct menudata g_MenuData;
s32 g_MenuScissorX1;
s32 g_MenuScissorX2;
s32 g_MenuScissorY1;
s32 g_MenuScissorY2;
Vp var800a2048[8];

#if VERSION >= VERSION_NTSC_1_0
struct menudialogdef g_PakCannotReadGameBoyMenuDialog;
struct menudialogdef g_PakDamagedMenuDialog;
struct menudialogdef g_PakDataLostMenuDialog;
#else
struct menudialogdef g_PakDamagedMenuDialog;
#endif

struct menudialogdef g_PakFullMenuDialog;
struct menudialogdef g_PakRemovedMenuDialog;
struct menudialogdef g_PakRepairFailedMenuDialog;
struct menudialogdef g_PakRepairSuccessMenuDialog;

const struct menucolourpalette g_MenuColourPalettes[] = {
	{ 0x20202000, 0x20202000, 0x20202000, 0x4f4f4f00, 0x00000000, 0x00000000, 0x4f4f4f00, 0x4f4f4f00, 0x4f4f4f00, 0x4f4f4f00, 0x00000000, 0x00000000, 0x4f4f4f00, 0x00000000, 0x00000000 },
	{ 0x0060bf7f, 0x0000507f, 0x00f0ff7f, 0xffffffff, 0x00002f7f, 0x00006f7f, 0x00ffffff, 0x007f7fff, 0xffffffff, 0x8fffffff, 0x000044ff, 0x000030ff, 0x7f7fffff, 0xffffffff, 0x6644ff7f },
	{ 0xbf00007f, 0x5000007f, 0xff00007f, 0xffff00ff, 0x2f00007f, 0x6f00007f, 0xff7050ff, 0x7f0000ff, 0xffff00ff, 0xff9070ff, 0x440000ff, 0x003000ff, 0xffff00ff, 0xffffffff, 0xff44447f },
	{ 0x00bf007f, 0x0050007f, 0x00ff007f, 0xffff00ff, 0x002f007f, 0x00ff0028, 0x55ff55ff, 0x006f00af, 0xffffffff, 0x00000000, 0x004400ff, 0x003000ff, 0xffff00ff, 0xffffffff, 0x44ff447f },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
	{ 0xaaaaaaff, 0xaaaaaa7f, 0xaaaaaaff, 0xffffffff, 0xffffff2f, 0xffffffff, 0xffffffff, 0xffffffff, 0xff8888ff, 0xffffffff, 0x00000000, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
};

const struct menucolourpalette g_MenuColourPalettes2[] = {
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x4f4f4f00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x006f6faf, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x006f6faf, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xff7f0000, 0xffffff00, 0xffffff00, 0x00ffff00, 0x006f6faf, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
};

const struct menucolourpalette g_MenuColourPalettes3[] = {
	{ 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x4f4f4f00, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x006f6faf, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x006f6faf, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0x44444400, 0x44444400, 0x44444400, 0x00ff0000, 0x44444400, 0x44444400, 0xffff0000, 0x006f6faf, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
};

#if VERSION >= VERSION_NTSC_1_0
char *g_StringPointer = g_CheatMarqueeString;
char *g_StringPointer2 = &g_CheatMarqueeString[PAL ? 150 : 125];
#endif

s32 g_MpPlayerNum = 0;

void menuPlaySound(s32 menusound)
{
	s32 sound = -1;
	s32 flag1 = false;
	s32 flag2 = false;
	f32 speed = 1;

	switch (menusound) {
	case MENUSOUND_SWIPE:
		sound = SFX_MENU_SWIPE;
		break;
	case MENUSOUND_OPENDIALOG:
		sound = SFX_MENU_OPENDIALOG;
		break;
	case MENUSOUND_FOCUS:
		sound = SFX_MENU_FOCUS;
		break;
	case MENUSOUND_SELECT:
		sound = SFX_MENU_SELECT;
		break;
	case MENUSOUND_ERROR:
		speed = 0.4f;
		sound = SFX_MENU_ERROR;
		flag1 = true;
		break;
	case MENUSOUND_EXPLOSION:
		sound = SFX_EXPLOSION_8098;
		break;
	case MENUSOUND_TOGGLEON:
		sound = SFX_MENU_SELECT;
		break;
	case MENUSOUND_TOGGLEOFF:
		sound = SFX_MENU_SUBFOCUS;
		break;
	case MENUSOUND_SUBFOCUS:
		sound = SFX_MENU_SUBFOCUS;
		break;
	case MENUSOUND_KEYBOARDFOCUS:
		sound = SFX_PICKUP_AMMO;
		flag1 = true;
		flag2 = true;
		speed = 3.5f;
		break;
	case MENUSOUND_KEYBOARDCANCEL:
		sound = SFX_MENU_CANCEL;
		flag1 = true;
		speed = 0.41904801130295f;
		break;
	}

	if (sound != -1) {
		struct sndstate *handle;

#if VERSION >= VERSION_NTSC_1_0
		OSPri prevpri = osGetThreadPri(NULL);
		osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#endif

		handle = sndStart(var80095200, sound, NULL, -1, -1, -1, -1, -1);

		if (handle && flag1) {
			audioPostEvent(handle, 16, *(s32 *)&speed);
		}

		if (handle && flag2) {
			audioPostEvent(handle, 8, 0x4000);
		}

#if VERSION >= VERSION_NTSC_1_0
		osSetThreadPri(0, prevpri);
#endif
	}
}

bool menuIsSoloMissionOrMp(void)
{
	switch (g_MenuData.root) {
	case MENUROOT_MAINMENU:
	case MENUROOT_TRAINING:
		if (g_Vars.stagenum == STAGE_CITRAINING) {
			return false;
		}

		return true;
	case MENUROOT_MPPAUSE:
		return true;
	}

	return false;
}

bool currentPlayerIsMenuOpenInSoloOrMp(void)
{
	s32 mpindex = g_Vars.currentplayerstats->mpindex;

	if (menuIsSoloMissionOrMp()) {
		if (mpindex >= 4) {
			mpindex -= 4;
		}

		if (g_Menus[mpindex].curdialog) {
			return true;
		}
	}

	return false;
}

bool func0f0f0c68(void)
{
	if (g_MenuData.bg || g_MenuData.nextbg != 255) {
		return false;
	}

	return true;
}

void menuSetBanner(s32 bannernum, bool allplayers)
{
	if (allplayers) {
		g_MenuData.bannernum = bannernum;
		return;
	}

	g_Menus[g_MpPlayerNum].bannernum = bannernum;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel menuRenderBanner
/*  f0f1408:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0f140c:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0f1410:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0f1414:	3c038008 */ 	lui	$v1,0x8008
/*  f0f1418:	3c088008 */ 	lui	$t0,0x8008
/*  f0f141c:	00808825 */ 	move	$s1,$a0
/*  f0f1420:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f1424:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0f1428:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f0f142c:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f0f1430:	afa7009c */ 	sw	$a3,0x9c($sp)
/*  f0f1434:	8c630070 */ 	lw	$v1,0x70($v1)
/*  f0f1438:	11c00008 */ 	beqz	$t6,.PF0f0f145c
/*  f0f143c:	8d08006c */ 	lw	$t0,0x6c($t0)
/*  f0f1440:	3c028008 */ 	lui	$v0,0x8008
/*  f0f1444:	8c420078 */ 	lw	$v0,0x78($v0)
/*  f0f1448:	50400005 */ 	beqzl	$v0,.PF0f0f1460
/*  f0f144c:	8faf0098 */ 	lw	$t7,0x98($sp)
/*  f0f1450:	3c088008 */ 	lui	$t0,0x8008
/*  f0f1454:	00401825 */ 	move	$v1,$v0
/*  f0f1458:	8d080074 */ 	lw	$t0,0x74($t0)
.PF0f0f145c:
/*  f0f145c:	8faf0098 */ 	lw	$t7,0x98($sp)
.PF0f0f1460:
/*  f0f1460:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0f1464:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f0f1468:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0f146c:	01f83021 */ 	addu	$a2,$t7,$t8
/*  f0f1470:	256b172c */ 	addiu	$t3,$t3,0x172c
/*  f0f1474:	00095040 */ 	sll	$t2,$t1,0x1
/*  f0f1478:	04c10003 */ 	bgez	$a2,.PF0f0f1488
/*  f0f147c:	0006c843 */ 	sra	$t9,$a2,0x1
/*  f0f1480:	24c10001 */ 	addiu	$at,$a2,0x1
/*  f0f1484:	0001c843 */ 	sra	$t9,$at,0x1
.PF0f0f1488:
/*  f0f1488:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f0f148c:	94440000 */ 	lhu	$a0,0x0($v0)
/*  f0f1490:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0f1494:	afb90084 */ 	sw	$t9,0x84($sp)
/*  f0f1498:	afa30064 */ 	sw	$v1,0x64($sp)
/*  f0f149c:	0fc5bdaa */ 	jal	langGet
/*  f0f14a0:	afa80060 */ 	sw	$t0,0x60($sp)
/*  f0f14a4:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0f14a8:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f0f14ac:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0f14b0:	00403025 */ 	move	$a2,$v0
/*  f0f14b4:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0f14b8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f14bc:	0fc5609a */ 	jal	textMeasure
/*  f0f14c0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f14c4:	0fc5bdaa */ 	jal	langGet
/*  f0f14c8:	240451ef */ 	li	$a0,0x51ef
/*  f0f14cc:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0f14d0:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0f14d4:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f14d8:	00403025 */ 	move	$a2,$v0
/*  f0f14dc:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0f14e0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f14e4:	0fc5609a */ 	jal	textMeasure
/*  f0f14e8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f14ec:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0f14f0:	240151eb */ 	li	$at,0x51eb
/*  f0f14f4:	02202025 */ 	move	$a0,$s1
/*  f0f14f8:	95cf0000 */ 	lhu	$t7,0x0($t6)
/*  f0f14fc:	55e10005 */ 	bnel	$t7,$at,.PF0f0f1514
/*  f0f1500:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*  f0f1504:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f0f1508:	27190007 */ 	addiu	$t9,$t8,0x7
/*  f0f150c:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f0f1510:	8fa2007c */ 	lw	$v0,0x7c($sp)
.PF0f0f1514:
/*  f0f1514:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f0f1518:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f151c:	2405007f */ 	li	$a1,0x7f
/*  f0f1520:	00434821 */ 	addu	$t1,$v0,$v1
/*  f0f1524:	05210003 */ 	bgez	$t1,.PF0f0f1534
/*  f0f1528:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0f152c:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f1530:	00015043 */ 	sra	$t2,$at,0x1
.PF0f0f1534:
/*  f0f1534:	00ca3023 */ 	subu	$a2,$a2,$t2
/*  f0f1538:	00c26021 */ 	addu	$t4,$a2,$v0
/*  f0f153c:	01836821 */ 	addu	$t5,$t4,$v1
/*  f0f1540:	24cbfffc */ 	addiu	$t3,$a2,-4
/*  f0f1544:	25ae0007 */ 	addiu	$t6,$t5,0x7
/*  f0f1548:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f0f154c:	afab006c */ 	sw	$t3,0x6c($sp)
/*  f0f1550:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0f1554:	0fc5513c */ 	jal	gfxSetPrimColour
/*  f0f1558:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f155c:	3c038008 */ 	lui	$v1,0x8008
/*  f0f1560:	24630020 */ 	addiu	$v1,$v1,0x20
/*  f0f1564:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0f1568:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0f156c:	8fac00a0 */ 	lw	$t4,0xa0($sp)
/*  f0f1570:	3c10f600 */ 	lui	$s0,0xf600
/*  f0f1574:	01f80019 */ 	multu	$t7,$t8
/*  f0f1578:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f0f157c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0f1580:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*  f0f1584:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f1588:	0000c812 */ 	mflo	$t9
/*  f0f158c:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f0f1590:	00095380 */ 	sll	$t2,$t1,0xe
/*  f0f1594:	01505825 */ 	or	$t3,$t2,$s0
/*  f0f1598:	016e7825 */ 	or	$t7,$t3,$t6
/*  f0f159c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0f15a0:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f15a4:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f0f15a8:	8fad0098 */ 	lw	$t5,0x98($sp)
/*  f0f15ac:	03190019 */ 	multu	$t8,$t9
/*  f0f15b0:	31ab03ff */ 	andi	$t3,$t5,0x3ff
/*  f0f15b4:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0f15b8:	00004812 */ 	mflo	$t1
/*  f0f15bc:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f15c0:	000a6380 */ 	sll	$t4,$t2,0xe
/*  f0f15c4:	018e7825 */ 	or	$t7,$t4,$t6
/*  f0f15c8:	0fc55153 */ 	jal	func0f153838
/*  f0f15cc:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f15d0:	00402025 */ 	move	$a0,$v0
/*  f0f15d4:	0fc5513c */ 	jal	gfxSetPrimColour
/*  f0f15d8:	24057f7f */ 	li	$a1,0x7f7f
/*  f0f15dc:	3c038008 */ 	lui	$v1,0x8008
/*  f0f15e0:	24630020 */ 	addiu	$v1,$v1,0x20
/*  f0f15e4:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f15e8:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0f15ec:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f15f0:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f15f4:	03190019 */ 	multu	$t8,$t9
/*  f0f15f8:	318e03ff */ 	andi	$t6,$t4,0x3ff
/*  f0f15fc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f1600:	322e03ff */ 	andi	$t6,$s1,0x3ff
/*  f0f1604:	00004812 */ 	mflo	$t1
/*  f0f1608:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f160c:	000a6b80 */ 	sll	$t5,$t2,0xe
/*  f0f1610:	01b05825 */ 	or	$t3,$t5,$s0
/*  f0f1614:	016fc025 */ 	or	$t8,$t3,$t7
/*  f0f1618:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0f161c:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f0f1620:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f0f1624:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f0f1628:	03290019 */ 	multu	$t9,$t1
/*  f0f162c:	00005012 */ 	mflo	$t2
/*  f0f1630:	314d03ff */ 	andi	$t5,$t2,0x3ff
/*  f0f1634:	000d6380 */ 	sll	$t4,$t5,0xe
/*  f0f1638:	018b7825 */ 	or	$t7,$t4,$t3
/*  f0f163c:	0fc55153 */ 	jal	func0f153838
/*  f0f1640:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f1644:	3c057f7f */ 	lui	$a1,0x7f7f
/*  f0f1648:	34a5ff7f */ 	ori	$a1,$a1,0xff7f
/*  f0f164c:	0fc5513c */ 	jal	gfxSetPrimColour
/*  f0f1650:	00402025 */ 	move	$a0,$v0
/*  f0f1654:	3c038008 */ 	lui	$v1,0x8008
/*  f0f1658:	24630020 */ 	addiu	$v1,$v1,0x20
/*  f0f165c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f1660:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0f1664:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f1668:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f0f166c:	03190019 */ 	multu	$t8,$t9
/*  f0f1670:	258b0004 */ 	addiu	$t3,$t4,0x4
/*  f0f1674:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f0f1678:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0f167c:	00004812 */ 	mflo	$t1
/*  f0f1680:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f1684:	000a6b80 */ 	sll	$t5,$t2,0xe
/*  f0f1688:	01b07025 */ 	or	$t6,$t5,$s0
/*  f0f168c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0f1690:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0f1694:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0f1698:	8fa90094 */ 	lw	$t1,0x94($sp)
/*  f0f169c:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0f16a0:	012a0019 */ 	multu	$t1,$t2
/*  f0f16a4:	25ee0002 */ 	addiu	$t6,$t7,0x2
/*  f0f16a8:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0f16ac:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f16b0:	00006812 */ 	mflo	$t5
/*  f0f16b4:	31ac03ff */ 	andi	$t4,$t5,0x3ff
/*  f0f16b8:	000c5b80 */ 	sll	$t3,$t4,0xe
/*  f0f16bc:	01794825 */ 	or	$t1,$t3,$t9
/*  f0f16c0:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f0f16c4:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f16c8:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f0f16cc:	262bfffe */ 	addiu	$t3,$s1,-2
/*  f0f16d0:	317903ff */ 	andi	$t9,$t3,0x3ff
/*  f0f16d4:	014d0019 */ 	multu	$t2,$t5
/*  f0f16d8:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0f16dc:	2639fffc */ 	addiu	$t9,$s1,-4
/*  f0f16e0:	00006012 */ 	mflo	$t4
/*  f0f16e4:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f0f16e8:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0f16ec:	01d0c025 */ 	or	$t8,$t6,$s0
/*  f0f16f0:	03095025 */ 	or	$t2,$t8,$t1
/*  f0f16f4:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f0f16f8:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f16fc:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f0f1700:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0f1704:	00184880 */ 	sll	$t1,$t8,0x2
/*  f0f1708:	01ac0019 */ 	multu	$t5,$t4
/*  f0f170c:	00007812 */ 	mflo	$t7
/*  f0f1710:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0f1714:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f0f1718:	01695025 */ 	or	$t2,$t3,$t1
/*  f0f171c:	0fc55153 */ 	jal	func0f153838
/*  f0f1720:	ac4a000c */ 	sw	$t2,0xc($v0)
/*  f0f1724:	0fc550cf */ 	jal	func0f153628
/*  f0f1728:	00402025 */ 	move	$a0,$v0
/*  f0f172c:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f0f1730:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f0f1734:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0f1738:	8fb800b0 */ 	lw	$t8,0xb0($sp)
/*  f0f173c:	01ac7821 */ 	addu	$t7,$t5,$t4
/*  f0f1740:	01eec821 */ 	addu	$t9,$t7,$t6
/*  f0f1744:	03381823 */ 	subu	$v1,$t9,$t8
/*  f0f1748:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f174c:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f1750:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0f1754:	00408825 */ 	move	$s1,$v0
/*  f0f1758:	04610003 */ 	bgez	$v1,.PF0f0f1768
/*  f0f175c:	00035843 */ 	sra	$t3,$v1,0x1
/*  f0f1760:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0f1764:	00015843 */ 	sra	$t3,$at,0x1
.PF0f0f1768:
/*  f0f1768:	01601825 */ 	move	$v1,$t3
/*  f0f176c:	05210003 */ 	bgez	$t1,.PF0f0f177c
/*  f0f1770:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0f1774:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f1778:	00015043 */ 	sra	$t2,$at,0x1
.PF0f0f177c:
/*  f0f177c:	006a6823 */ 	subu	$t5,$v1,$t2
/*  f0f1780:	25ac0002 */ 	addiu	$t4,$t5,0x2
/*  f0f1784:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f1788:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f0f178c:	95e40000 */ 	lhu	$a0,0x0($t7)
/*  f0f1790:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f1794:	0fc5bdaa */ 	jal	langGet
/*  f0f1798:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0f179c:	0c002e53 */ 	jal	viGetWidth
/*  f0f17a0:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f17a4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f17a8:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f17ac:	0c002e53 */ 	jal	viGetWidth
/*  f0f17b0:	01c08025 */ 	move	$s0,$t6
/*  f0f17b4:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f17b8:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f17bc:	240b00ff */ 	li	$t3,0xff
/*  f0f17c0:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f17c4:	02202025 */ 	move	$a0,$s1
/*  f0f17c8:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f17cc:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f17d0:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f17d4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f17d8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f17dc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f17e0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f17e4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f17e8:	0fc55c50 */ 	jal	textRenderProjected
/*  f0f17ec:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f17f0:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0f17f4:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0f17f8:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f17fc:	00408825 */ 	move	$s1,$v0
/*  f0f1800:	05410003 */ 	bgez	$t2,.PF0f0f1810
/*  f0f1804:	000a6843 */ 	sra	$t5,$t2,0x1
/*  f0f1808:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0f180c:	00016843 */ 	sra	$t5,$at,0x1
.PF0f0f1810:
/*  f0f1810:	012d6023 */ 	subu	$t4,$t1,$t5
/*  f0f1814:	258f0002 */ 	addiu	$t7,$t4,0x2
/*  f0f1818:	24c60003 */ 	addiu	$a2,$a2,0x3
/*  f0f181c:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f0f1820:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f1824:	0fc5bdaa */ 	jal	langGet
/*  f0f1828:	240451ef */ 	li	$a0,0x51ef
/*  f0f182c:	0c002e53 */ 	jal	viGetWidth
/*  f0f1830:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1834:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f1838:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f183c:	0c002e53 */ 	jal	viGetWidth
/*  f0f1840:	01c08025 */ 	move	$s0,$t6
/*  f0f1844:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f1848:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f184c:	240b00ff */ 	li	$t3,0xff
/*  f0f1850:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f1854:	02202025 */ 	move	$a0,$s1
/*  f0f1858:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f185c:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f1860:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f1864:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f1868:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f186c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1870:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f1874:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f1878:	0fc55c50 */ 	jal	textRenderProjected
/*  f0f187c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f1880:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f1884:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f0f1888:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0f188c:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0f1890:	00408825 */ 	move	$s1,$v0
/*  f0f1894:	05210003 */ 	bgez	$t1,.PF0f0f18a4
/*  f0f1898:	00096843 */ 	sra	$t5,$t1,0x1
/*  f0f189c:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f18a0:	00016843 */ 	sra	$t5,$at,0x1
.PF0f0f18a4:
/*  f0f18a4:	014d6023 */ 	subu	$t4,$t2,$t5
/*  f0f18a8:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f18ac:	95e40000 */ 	lhu	$a0,0x0($t7)
/*  f0f18b0:	0fc5bdaa */ 	jal	langGet
/*  f0f18b4:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f18b8:	0c002e53 */ 	jal	viGetWidth
/*  f0f18bc:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f18c0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f18c4:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f18c8:	0c002e53 */ 	jal	viGetWidth
/*  f0f18cc:	01c08025 */ 	move	$s0,$t6
/*  f0f18d0:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f18d4:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f18d8:	3c0bbfbf */ 	lui	$t3,0xbfbf
/*  f0f18dc:	356bffff */ 	ori	$t3,$t3,0xffff
/*  f0f18e0:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f18e4:	02202025 */ 	move	$a0,$s1
/*  f0f18e8:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f18ec:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f18f0:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f18f4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f18f8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f18fc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1900:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f1904:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f1908:	0fc55c50 */ 	jal	textRenderProjected
/*  f0f190c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f1910:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0f1914:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f1918:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0f191c:	00408825 */ 	move	$s1,$v0
/*  f0f1920:	05410003 */ 	bgez	$t2,.PF0f0f1930
/*  f0f1924:	000a6843 */ 	sra	$t5,$t2,0x1
/*  f0f1928:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0f192c:	00016843 */ 	sra	$t5,$at,0x1
.PF0f0f1930:
/*  f0f1930:	24c60003 */ 	addiu	$a2,$a2,0x3
/*  f0f1934:	012d6023 */ 	subu	$t4,$t1,$t5
/*  f0f1938:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f193c:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f1940:	0fc5bdaa */ 	jal	langGet
/*  f0f1944:	240451ef */ 	li	$a0,0x51ef
/*  f0f1948:	0c002e53 */ 	jal	viGetWidth
/*  f0f194c:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1950:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f1954:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0f1958:	0c002e53 */ 	jal	viGetWidth
/*  f0f195c:	01e08025 */ 	move	$s0,$t7
/*  f0f1960:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f0f1964:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0f1968:	3c18bfbf */ 	lui	$t8,0xbfbf
/*  f0f196c:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f0f1970:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f1974:	02202025 */ 	move	$a0,$s1
/*  f0f1978:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f197c:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f1980:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f1984:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f1988:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f198c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1990:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f1994:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f1998:	0fc55c50 */ 	jal	textRenderProjected
/*  f0f199c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f19a0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0f19a4:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0f19a8:	240151eb */ 	li	$at,0x51eb
/*  f0f19ac:	956a0000 */ 	lhu	$t2,0x0($t3)
/*  f0f19b0:	00408825 */ 	move	$s1,$v0
/*  f0f19b4:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f19b8:	15410023 */ 	bne	$t2,$at,.PF0f0f1a48
/*  f0f19bc:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f0f19c0:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0f19c4:	05210003 */ 	bgez	$t1,.PF0f0f19d4
/*  f0f19c8:	00096843 */ 	sra	$t5,$t1,0x1
/*  f0f19cc:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f19d0:	00016843 */ 	sra	$t5,$at,0x1
.PF0f0f19d4:
/*  f0f19d4:	01ac7821 */ 	addu	$t7,$t5,$t4
/*  f0f19d8:	25eefff9 */ 	addiu	$t6,$t7,-7
/*  f0f19dc:	afae0088 */ 	sw	$t6,0x88($sp)
/*  f0f19e0:	0c002e53 */ 	jal	viGetWidth
/*  f0f19e4:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f19e8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f19ec:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0f19f0:	0c002e53 */ 	jal	viGetWidth
/*  f0f19f4:	03208025 */ 	move	$s0,$t9
/*  f0f19f8:	3c188008 */ 	lui	$t8,0x8008
/*  f0f19fc:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0f1a00:	8d6b0064 */ 	lw	$t3,0x64($t3)
/*  f0f1a04:	8f180068 */ 	lw	$t8,0x68($t8)
/*  f0f1a08:	3c0abfbf */ 	lui	$t2,0xbfbf
/*  f0f1a0c:	354affff */ 	ori	$t2,$t2,0xffff
/*  f0f1a10:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0f1a14:	24e736d8 */ 	addiu	$a3,$a3,0x36d8
/*  f0f1a18:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0f1a1c:	02202025 */ 	move	$a0,$s1
/*  f0f1a20:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f1a24:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f1a28:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f1a2c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f1a30:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1a34:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f1a38:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f1a3c:	0fc55c50 */ 	jal	textRenderProjected
/*  f0f1a40:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f1a44:	00408825 */ 	move	$s1,$v0
.PF0f0f1a48:
/*  f0f1a48:	0fc55125 */ 	jal	func0f153780
/*  f0f1a4c:	02202025 */ 	move	$a0,$s1
/*  f0f1a50:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f1a54:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0f1a58:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0f1a5c:	03e00008 */ 	jr	$ra
/*  f0f1a60:	27bd0090 */ 	addiu	$sp,$sp,0x90
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuRenderBanner
/*  f0f0ce8:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0f0cec:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0f0cf0:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0f0cf4:	3c038008 */ 	lui	$v1,%hi(g_CharsHandelGothicSm)
/*  f0f0cf8:	3c088008 */ 	lui	$t0,%hi(g_FontHandelGothicSm)
/*  f0f0cfc:	00808825 */ 	or	$s1,$a0,$zero
/*  f0f0d00:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f0d04:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0f0d08:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f0f0d0c:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f0f0d10:	afa7009c */ 	sw	$a3,0x9c($sp)
/*  f0f0d14:	8c63fb10 */ 	lw	$v1,%lo(g_CharsHandelGothicSm)($v1)
/*  f0f0d18:	11c00005 */ 	beqz	$t6,.L0f0f0d30
/*  f0f0d1c:	8d08fb0c */ 	lw	$t0,%lo(g_FontHandelGothicSm)($t0)
/*  f0f0d20:	3c038008 */ 	lui	$v1,%hi(g_CharsHandelGothicMd)
/*  f0f0d24:	3c088008 */ 	lui	$t0,%hi(g_FontHandelGothicMd)
/*  f0f0d28:	8c63fb18 */ 	lw	$v1,%lo(g_CharsHandelGothicMd)($v1)
/*  f0f0d2c:	8d08fb14 */ 	lw	$t0,%lo(g_FontHandelGothicMd)($t0)
.L0f0f0d30:
/*  f0f0d30:	8faf0098 */ 	lw	$t7,0x98($sp)
/*  f0f0d34:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0f0d38:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f0f0d3c:	3c0b8007 */ 	lui	$t3,%hi(var8007144c)
/*  f0f0d40:	01f83021 */ 	addu	$a2,$t7,$t8
/*  f0f0d44:	256b144c */ 	addiu	$t3,$t3,%lo(var8007144c)
/*  f0f0d48:	00095040 */ 	sll	$t2,$t1,0x1
/*  f0f0d4c:	04c10003 */ 	bgez	$a2,.L0f0f0d5c
/*  f0f0d50:	0006c843 */ 	sra	$t9,$a2,0x1
/*  f0f0d54:	24c10001 */ 	addiu	$at,$a2,0x1
/*  f0f0d58:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f0d5c:
/*  f0f0d5c:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f0f0d60:	94440000 */ 	lhu	$a0,0x0($v0)
/*  f0f0d64:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0f0d68:	afb90084 */ 	sw	$t9,0x84($sp)
/*  f0f0d6c:	afa30064 */ 	sw	$v1,0x64($sp)
/*  f0f0d70:	0fc5b9f1 */ 	jal	langGet
/*  f0f0d74:	afa80060 */ 	sw	$t0,0x60($sp)
/*  f0f0d78:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0f0d7c:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f0f0d80:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0f0d84:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f0d88:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0f0d8c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f0d90:	0fc55cbe */ 	jal	textMeasure
/*  f0f0d94:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f0d98:	0fc5b9f1 */ 	jal	langGet
/*  f0f0d9c:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0f0da0:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0f0da4:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0f0da8:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f0dac:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f0db0:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0f0db4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f0db8:	0fc55cbe */ 	jal	textMeasure
/*  f0f0dbc:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f0dc0:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0f0dc4:	240151eb */ 	addiu	$at,$zero,0x51eb
/*  f0f0dc8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f0dcc:	95cf0000 */ 	lhu	$t7,0x0($t6)
/*  f0f0dd0:	55e10005 */ 	bnel	$t7,$at,.L0f0f0de8
/*  f0f0dd4:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*  f0f0dd8:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f0f0ddc:	27190007 */ 	addiu	$t9,$t8,0x7
/*  f0f0de0:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f0f0de4:	8fa2007c */ 	lw	$v0,0x7c($sp)
.L0f0f0de8:
/*  f0f0de8:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f0f0dec:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f0df0:	2405007f */ 	addiu	$a1,$zero,0x7f
/*  f0f0df4:	00434821 */ 	addu	$t1,$v0,$v1
/*  f0f0df8:	05210003 */ 	bgez	$t1,.L0f0f0e08
/*  f0f0dfc:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0f0e00:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f0e04:	00015043 */ 	sra	$t2,$at,0x1
.L0f0f0e08:
/*  f0f0e08:	00ca3023 */ 	subu	$a2,$a2,$t2
/*  f0f0e0c:	00c26021 */ 	addu	$t4,$a2,$v0
/*  f0f0e10:	01836821 */ 	addu	$t5,$t4,$v1
/*  f0f0e14:	24cbfffc */ 	addiu	$t3,$a2,-4
/*  f0f0e18:	25ae0007 */ 	addiu	$t6,$t5,0x7
/*  f0f0e1c:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f0f0e20:	afab006c */ 	sw	$t3,0x6c($sp)
/*  f0f0e24:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0f0e28:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0f0e2c:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f0e30:	3c038008 */ 	lui	$v1,%hi(g_ScaleX)
/*  f0f0e34:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScaleX)
/*  f0f0e38:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0f0e3c:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0f0e40:	8fac00a0 */ 	lw	$t4,0xa0($sp)
/*  f0f0e44:	3c10f600 */ 	lui	$s0,0xf600
/*  f0f0e48:	01f80019 */ 	multu	$t7,$t8
/*  f0f0e4c:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f0f0e50:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0f0e54:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*  f0f0e58:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f0e5c:	0000c812 */ 	mflo	$t9
/*  f0f0e60:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f0f0e64:	00095380 */ 	sll	$t2,$t1,0xe
/*  f0f0e68:	01505825 */ 	or	$t3,$t2,$s0
/*  f0f0e6c:	016e7825 */ 	or	$t7,$t3,$t6
/*  f0f0e70:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0f0e74:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f0e78:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f0f0e7c:	8fad0098 */ 	lw	$t5,0x98($sp)
/*  f0f0e80:	03190019 */ 	multu	$t8,$t9
/*  f0f0e84:	31ab03ff */ 	andi	$t3,$t5,0x3ff
/*  f0f0e88:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0f0e8c:	00004812 */ 	mflo	$t1
/*  f0f0e90:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f0e94:	000a6380 */ 	sll	$t4,$t2,0xe
/*  f0f0e98:	018e7825 */ 	or	$t7,$t4,$t6
/*  f0f0e9c:	0fc54e0e */ 	jal	func0f153838
/*  f0f0ea0:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f0ea4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0ea8:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0f0eac:	24057f7f */ 	addiu	$a1,$zero,0x7f7f
/*  f0f0eb0:	3c038008 */ 	lui	$v1,%hi(g_ScaleX)
/*  f0f0eb4:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScaleX)
/*  f0f0eb8:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f0ebc:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0f0ec0:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f0ec4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f0ec8:	03190019 */ 	multu	$t8,$t9
/*  f0f0ecc:	318e03ff */ 	andi	$t6,$t4,0x3ff
/*  f0f0ed0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f0ed4:	322e03ff */ 	andi	$t6,$s1,0x3ff
/*  f0f0ed8:	00004812 */ 	mflo	$t1
/*  f0f0edc:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f0ee0:	000a6b80 */ 	sll	$t5,$t2,0xe
/*  f0f0ee4:	01b05825 */ 	or	$t3,$t5,$s0
/*  f0f0ee8:	016fc025 */ 	or	$t8,$t3,$t7
/*  f0f0eec:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0f0ef0:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f0f0ef4:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f0f0ef8:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f0f0efc:	03290019 */ 	multu	$t9,$t1
/*  f0f0f00:	00005012 */ 	mflo	$t2
/*  f0f0f04:	314d03ff */ 	andi	$t5,$t2,0x3ff
/*  f0f0f08:	000d6380 */ 	sll	$t4,$t5,0xe
/*  f0f0f0c:	018b7825 */ 	or	$t7,$t4,$t3
/*  f0f0f10:	0fc54e0e */ 	jal	func0f153838
/*  f0f0f14:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f0f18:	3c057f7f */ 	lui	$a1,0x7f7f
/*  f0f0f1c:	34a5ff7f */ 	ori	$a1,$a1,0xff7f
/*  f0f0f20:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0f0f24:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0f28:	3c038008 */ 	lui	$v1,%hi(g_ScaleX)
/*  f0f0f2c:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScaleX)
/*  f0f0f30:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f0f34:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0f0f38:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f0f3c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f0f0f40:	03190019 */ 	multu	$t8,$t9
/*  f0f0f44:	258b0004 */ 	addiu	$t3,$t4,0x4
/*  f0f0f48:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f0f0f4c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0f0f50:	00004812 */ 	mflo	$t1
/*  f0f0f54:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f0f58:	000a6b80 */ 	sll	$t5,$t2,0xe
/*  f0f0f5c:	01b07025 */ 	or	$t6,$t5,$s0
/*  f0f0f60:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0f0f64:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0f0f68:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0f0f6c:	8fa90094 */ 	lw	$t1,0x94($sp)
/*  f0f0f70:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0f0f74:	012a0019 */ 	multu	$t1,$t2
/*  f0f0f78:	25ee0002 */ 	addiu	$t6,$t7,0x2
/*  f0f0f7c:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0f0f80:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f0f84:	00006812 */ 	mflo	$t5
/*  f0f0f88:	31ac03ff */ 	andi	$t4,$t5,0x3ff
/*  f0f0f8c:	000c5b80 */ 	sll	$t3,$t4,0xe
/*  f0f0f90:	01794825 */ 	or	$t1,$t3,$t9
/*  f0f0f94:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f0f0f98:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f0f9c:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f0f0fa0:	262bfffe */ 	addiu	$t3,$s1,-2
/*  f0f0fa4:	317903ff */ 	andi	$t9,$t3,0x3ff
/*  f0f0fa8:	014d0019 */ 	multu	$t2,$t5
/*  f0f0fac:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0f0fb0:	2639fffc */ 	addiu	$t9,$s1,-4
/*  f0f0fb4:	00006012 */ 	mflo	$t4
/*  f0f0fb8:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f0f0fbc:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0f0fc0:	01d0c025 */ 	or	$t8,$t6,$s0
/*  f0f0fc4:	03095025 */ 	or	$t2,$t8,$t1
/*  f0f0fc8:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f0f0fcc:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f0fd0:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f0f0fd4:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0f0fd8:	00184880 */ 	sll	$t1,$t8,0x2
/*  f0f0fdc:	01ac0019 */ 	multu	$t5,$t4
/*  f0f0fe0:	00007812 */ 	mflo	$t7
/*  f0f0fe4:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0f0fe8:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f0f0fec:	01695025 */ 	or	$t2,$t3,$t1
/*  f0f0ff0:	0fc54e0e */ 	jal	func0f153838
/*  f0f0ff4:	ac4a000c */ 	sw	$t2,0xc($v0)
/*  f0f0ff8:	0fc54d8a */ 	jal	func0f153628
/*  f0f0ffc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f1000:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f0f1004:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f0f1008:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0f100c:	8fb800b0 */ 	lw	$t8,0xb0($sp)
/*  f0f1010:	01ac7821 */ 	addu	$t7,$t5,$t4
/*  f0f1014:	01eec821 */ 	addu	$t9,$t7,$t6
/*  f0f1018:	03381823 */ 	subu	$v1,$t9,$t8
/*  f0f101c:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f1020:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f1024:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0f1028:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f102c:	04610003 */ 	bgez	$v1,.L0f0f103c
/*  f0f1030:	00035843 */ 	sra	$t3,$v1,0x1
/*  f0f1034:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0f1038:	00015843 */ 	sra	$t3,$at,0x1
.L0f0f103c:
/*  f0f103c:	01601825 */ 	or	$v1,$t3,$zero
/*  f0f1040:	05210003 */ 	bgez	$t1,.L0f0f1050
/*  f0f1044:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0f1048:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f104c:	00015043 */ 	sra	$t2,$at,0x1
.L0f0f1050:
/*  f0f1050:	006a6823 */ 	subu	$t5,$v1,$t2
/*  f0f1054:	25ac0002 */ 	addiu	$t4,$t5,0x2
/*  f0f1058:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f105c:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f0f1060:	95e40000 */ 	lhu	$a0,0x0($t7)
/*  f0f1064:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f1068:	0fc5b9f1 */ 	jal	langGet
/*  f0f106c:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0f1070:	0c002f02 */ 	jal	viGetWidth
/*  f0f1074:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1078:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f107c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f1080:	0c002f02 */ 	jal	viGetWidth
/*  f0f1084:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f1088:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f108c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f1090:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f0f1094:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f1098:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f109c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f10a0:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f10a4:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f10a8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f10ac:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f10b0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f10b4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f10b8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f10bc:	0fc5580f */ 	jal	textRenderProjected
/*  f0f10c0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f10c4:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0f10c8:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0f10cc:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f10d0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f10d4:	05410003 */ 	bgez	$t2,.L0f0f10e4
/*  f0f10d8:	000a6843 */ 	sra	$t5,$t2,0x1
/*  f0f10dc:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0f10e0:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f10e4:
/*  f0f10e4:	012d6023 */ 	subu	$t4,$t1,$t5
/*  f0f10e8:	258f0002 */ 	addiu	$t7,$t4,0x2
/*  f0f10ec:	24c60003 */ 	addiu	$a2,$a2,0x3
/*  f0f10f0:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f0f10f4:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f10f8:	0fc5b9f1 */ 	jal	langGet
/*  f0f10fc:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0f1100:	0c002f02 */ 	jal	viGetWidth
/*  f0f1104:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1108:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f110c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f1110:	0c002f02 */ 	jal	viGetWidth
/*  f0f1114:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f1118:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f111c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f1120:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f0f1124:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f1128:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f112c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f1130:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f1134:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f1138:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f113c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f1140:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1144:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f1148:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f114c:	0fc5580f */ 	jal	textRenderProjected
/*  f0f1150:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f1154:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f1158:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f0f115c:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0f1160:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0f1164:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f1168:	05210003 */ 	bgez	$t1,.L0f0f1178
/*  f0f116c:	00096843 */ 	sra	$t5,$t1,0x1
/*  f0f1170:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f1174:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f1178:
/*  f0f1178:	014d6023 */ 	subu	$t4,$t2,$t5
/*  f0f117c:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f1180:	95e40000 */ 	lhu	$a0,0x0($t7)
/*  f0f1184:	0fc5b9f1 */ 	jal	langGet
/*  f0f1188:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f118c:	0c002f02 */ 	jal	viGetWidth
/*  f0f1190:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1194:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f1198:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f119c:	0c002f02 */ 	jal	viGetWidth
/*  f0f11a0:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f11a4:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f11a8:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f11ac:	3c0bbfbf */ 	lui	$t3,0xbfbf
/*  f0f11b0:	356bffff */ 	ori	$t3,$t3,0xffff
/*  f0f11b4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f11b8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f11bc:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f11c0:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f11c4:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f11c8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f11cc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f11d0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f11d4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f11d8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f11dc:	0fc5580f */ 	jal	textRenderProjected
/*  f0f11e0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f11e4:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0f11e8:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f11ec:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0f11f0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f11f4:	05410003 */ 	bgez	$t2,.L0f0f1204
/*  f0f11f8:	000a6843 */ 	sra	$t5,$t2,0x1
/*  f0f11fc:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0f1200:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f1204:
/*  f0f1204:	24c60003 */ 	addiu	$a2,$a2,0x3
/*  f0f1208:	012d6023 */ 	subu	$t4,$t1,$t5
/*  f0f120c:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f1210:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f1214:	0fc5b9f1 */ 	jal	langGet
/*  f0f1218:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0f121c:	0c002f02 */ 	jal	viGetWidth
/*  f0f1220:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1224:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f1228:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0f122c:	0c002f02 */ 	jal	viGetWidth
/*  f0f1230:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0f1234:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f0f1238:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0f123c:	3c18bfbf */ 	lui	$t8,0xbfbf
/*  f0f1240:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f0f1244:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f1248:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f124c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f1250:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f1254:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f1258:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f125c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f1260:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1264:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f1268:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f126c:	0fc5580f */ 	jal	textRenderProjected
/*  f0f1270:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f1274:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0f1278:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0f127c:	240151eb */ 	addiu	$at,$zero,0x51eb
/*  f0f1280:	956a0000 */ 	lhu	$t2,0x0($t3)
/*  f0f1284:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f1288:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f128c:	15410023 */ 	bne	$t2,$at,.L0f0f131c
/*  f0f1290:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f0f1294:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0f1298:	05210003 */ 	bgez	$t1,.L0f0f12a8
/*  f0f129c:	00096843 */ 	sra	$t5,$t1,0x1
/*  f0f12a0:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f12a4:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f12a8:
/*  f0f12a8:	01ac7821 */ 	addu	$t7,$t5,$t4
/*  f0f12ac:	25eefff9 */ 	addiu	$t6,$t7,-7
/*  f0f12b0:	afae0088 */ 	sw	$t6,0x88($sp)
/*  f0f12b4:	0c002f02 */ 	jal	viGetWidth
/*  f0f12b8:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f12bc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f12c0:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0f12c4:	0c002f02 */ 	jal	viGetWidth
/*  f0f12c8:	03208025 */ 	or	$s0,$t9,$zero
/*  f0f12cc:	3c188008 */ 	lui	$t8,%hi(g_CharsHandelGothicXs)
/*  f0f12d0:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicXs)
/*  f0f12d4:	8d6bfb04 */ 	lw	$t3,%lo(g_FontHandelGothicXs)($t3)
/*  f0f12d8:	8f18fb08 */ 	lw	$t8,%lo(g_CharsHandelGothicXs)($t8)
/*  f0f12dc:	3c0abfbf */ 	lui	$t2,0xbfbf
/*  f0f12e0:	354affff */ 	ori	$t2,$t2,0xffff
/*  f0f12e4:	3c077f1b */ 	lui	$a3,%hi(var7f1b23e8)
/*  f0f12e8:	24e723e8 */ 	addiu	$a3,$a3,%lo(var7f1b23e8)
/*  f0f12ec:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0f12f0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f12f4:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f12f8:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f12fc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f1300:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f1304:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1308:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f130c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f1310:	0fc5580f */ 	jal	textRenderProjected
/*  f0f1314:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f1318:	00408825 */ 	or	$s1,$v0,$zero
.L0f0f131c:
/*  f0f131c:	0fc54de0 */ 	jal	func0f153780
/*  f0f1320:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f1324:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f1328:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0f132c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0f1330:	03e00008 */ 	jr	$ra
/*  f0f1334:	27bd0090 */ 	addiu	$sp,$sp,0x90
);
#else
GLOBAL_ASM(
glabel menuRenderBanner
/*  f0ed9ec:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0ed9f0:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f0ed9f4:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0ed9f8:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0ed9fc:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0eda00:	3c128008 */ 	lui	$s2,0x8008
/*  f0eda04:	3c138008 */ 	lui	$s3,0x8008
/*  f0eda08:	00808825 */ 	or	$s1,$a0,$zero
/*  f0eda0c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0eda10:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0eda14:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0eda18:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f0eda1c:	afa700a4 */ 	sw	$a3,0xa4($sp)
/*  f0eda20:	8e522370 */ 	lw	$s2,0x2370($s2)
/*  f0eda24:	11c00005 */ 	beqz	$t6,.NB0f0eda3c
/*  f0eda28:	8e73236c */ 	lw	$s3,0x236c($s3)
/*  f0eda2c:	3c128008 */ 	lui	$s2,0x8008
/*  f0eda30:	3c138008 */ 	lui	$s3,0x8008
/*  f0eda34:	8e522378 */ 	lw	$s2,0x2378($s2)
/*  f0eda38:	8e732374 */ 	lw	$s3,0x2374($s3)
.NB0f0eda3c:
/*  f0eda3c:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0eda40:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*  f0eda44:	8fa800b0 */ 	lw	$t0,0xb0($sp)
/*  f0eda48:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0eda4c:	01f83021 */ 	addu	$a2,$t7,$t8
/*  f0eda50:	254a3af4 */ 	addiu	$t2,$t2,0x3af4
/*  f0eda54:	00084840 */ 	sll	$t1,$t0,0x1
/*  f0eda58:	04c10003 */ 	bgez	$a2,.NB0f0eda68
/*  f0eda5c:	0006c843 */ 	sra	$t9,$a2,0x1
/*  f0eda60:	24c10001 */ 	addiu	$at,$a2,0x1
/*  f0eda64:	0001c843 */ 	sra	$t9,$at,0x1
.NB0f0eda68:
/*  f0eda68:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f0eda6c:	94440000 */ 	lhu	$a0,0x0($v0)
/*  f0eda70:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0eda74:	0fc5a4dd */ 	jal	langGet
/*  f0eda78:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f0eda7c:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0eda80:	27a50080 */ 	addiu	$a1,$sp,0x80
/*  f0eda84:	00403025 */ 	or	$a2,$v0,$zero
/*  f0eda88:	02403825 */ 	or	$a3,$s2,$zero
/*  f0eda8c:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0eda90:	0fc54655 */ 	jal	textMeasure
/*  f0eda94:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eda98:	0fc5a4dd */ 	jal	langGet
/*  f0eda9c:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0edaa0:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f0edaa4:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0edaa8:	00403025 */ 	or	$a2,$v0,$zero
/*  f0edaac:	02403825 */ 	or	$a3,$s2,$zero
/*  f0edab0:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0edab4:	0fc54655 */ 	jal	textMeasure
/*  f0edab8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0edabc:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f0edac0:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*  f0edac4:	8fa6008c */ 	lw	$a2,0x8c($sp)
/*  f0edac8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0edacc:	00435821 */ 	addu	$t3,$v0,$v1
/*  f0edad0:	05610003 */ 	bgez	$t3,.NB0f0edae0
/*  f0edad4:	000b6043 */ 	sra	$t4,$t3,0x1
/*  f0edad8:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0edadc:	00016043 */ 	sra	$t4,$at,0x1
.NB0f0edae0:
/*  f0edae0:	00cc3023 */ 	subu	$a2,$a2,$t4
/*  f0edae4:	00c27021 */ 	addu	$t6,$a2,$v0
/*  f0edae8:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f0edaec:	24cdfffc */ 	addiu	$t5,$a2,-4
/*  f0edaf0:	25f80007 */ 	addiu	$t8,$t7,0x7
/*  f0edaf4:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f0edaf8:	afad0074 */ 	sw	$t5,0x74($sp)
/*  f0edafc:	afb80070 */ 	sw	$t8,0x70($sp)
/*  f0edb00:	afa6008c */ 	sw	$a2,0x8c($sp)
/*  f0edb04:	0fc537b7 */ 	jal	gfxSetPrimColour
/*  f0edb08:	2405007f */ 	addiu	$a1,$zero,0x7f
/*  f0edb0c:	3c038008 */ 	lui	$v1,0x8008
/*  f0edb10:	24632320 */ 	addiu	$v1,$v1,0x2320
/*  f0edb14:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f0edb18:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f0edb1c:	8fad00a8 */ 	lw	$t5,0xa8($sp)
/*  f0edb20:	3c10f600 */ 	lui	$s0,0xf600
/*  f0edb24:	03280019 */ 	multu	$t9,$t0
/*  f0edb28:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f0edb2c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0edb30:	8fb10074 */ 	lw	$s1,0x74($sp)
/*  f0edb34:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0edb38:	00004812 */ 	mflo	$t1
/*  f0edb3c:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0edb40:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f0edb44:	01706025 */ 	or	$t4,$t3,$s0
/*  f0edb48:	018fc025 */ 	or	$t8,$t4,$t7
/*  f0edb4c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0edb50:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f0edb54:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f0edb58:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*  f0edb5c:	03280019 */ 	multu	$t9,$t0
/*  f0edb60:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f0edb64:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f0edb68:	00004812 */ 	mflo	$t1
/*  f0edb6c:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0edb70:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f0edb74:	016c7825 */ 	or	$t7,$t3,$t4
/*  f0edb78:	0fc537ce */ 	jal	func0f153838
/*  f0edb7c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0edb80:	00402025 */ 	or	$a0,$v0,$zero
/*  f0edb84:	0fc537b7 */ 	jal	gfxSetPrimColour
/*  f0edb88:	24057f7f */ 	addiu	$a1,$zero,0x7f7f
/*  f0edb8c:	3c038008 */ 	lui	$v1,0x8008
/*  f0edb90:	24632320 */ 	addiu	$v1,$v1,0x2320
/*  f0edb94:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0edb98:	8fb800a4 */ 	lw	$t8,0xa4($sp)
/*  f0edb9c:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f0edba0:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0edba4:	03190019 */ 	multu	$t8,$t9
/*  f0edba8:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f0edbac:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0edbb0:	322e03ff */ 	andi	$t6,$s1,0x3ff
/*  f0edbb4:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f0edbb8:	00004012 */ 	mflo	$t0
/*  f0edbbc:	310903ff */ 	andi	$t1,$t0,0x3ff
/*  f0edbc0:	00095380 */ 	sll	$t2,$t1,0xe
/*  f0edbc4:	01506825 */ 	or	$t5,$t2,$s0
/*  f0edbc8:	01ac7825 */ 	or	$t7,$t5,$t4
/*  f0edbcc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0edbd0:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0edbd4:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0edbd8:	03190019 */ 	multu	$t8,$t9
/*  f0edbdc:	00004012 */ 	mflo	$t0
/*  f0edbe0:	310903ff */ 	andi	$t1,$t0,0x3ff
/*  f0edbe4:	00095380 */ 	sll	$t2,$t1,0xe
/*  f0edbe8:	014b6825 */ 	or	$t5,$t2,$t3
/*  f0edbec:	0fc537ce */ 	jal	func0f153838
/*  f0edbf0:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f0edbf4:	3c057f7f */ 	lui	$a1,0x7f7f
/*  f0edbf8:	34a5ff7f */ 	ori	$a1,$a1,0xff7f
/*  f0edbfc:	0fc537b7 */ 	jal	gfxSetPrimColour
/*  f0edc00:	00402025 */ 	or	$a0,$v0,$zero
/*  f0edc04:	3c038008 */ 	lui	$v1,0x8008
/*  f0edc08:	24632320 */ 	addiu	$v1,$v1,0x2320
/*  f0edc0c:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0edc10:	8fac00a4 */ 	lw	$t4,0xa4($sp)
/*  f0edc14:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f0edc18:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f0edc1c:	018f0019 */ 	multu	$t4,$t7
/*  f0edc20:	25ca0004 */ 	addiu	$t2,$t6,0x4
/*  f0edc24:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f0edc28:	000b6880 */ 	sll	$t5,$t3,0x2
/*  f0edc2c:	0000c012 */ 	mflo	$t8
/*  f0edc30:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0edc34:	00194380 */ 	sll	$t0,$t9,0xe
/*  f0edc38:	01104825 */ 	or	$t1,$t0,$s0
/*  f0edc3c:	012d6025 */ 	or	$t4,$t1,$t5
/*  f0edc40:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0edc44:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0edc48:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0edc4c:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0edc50:	01f80019 */ 	multu	$t7,$t8
/*  f0edc54:	254b0002 */ 	addiu	$t3,$t2,0x2
/*  f0edc58:	316903ff */ 	andi	$t1,$t3,0x3ff
/*  f0edc5c:	00096880 */ 	sll	$t5,$t1,0x2
/*  f0edc60:	2629fffe */ 	addiu	$t1,$s1,-2
/*  f0edc64:	0000c812 */ 	mflo	$t9
/*  f0edc68:	332803ff */ 	andi	$t0,$t9,0x3ff
/*  f0edc6c:	00087380 */ 	sll	$t6,$t0,0xe
/*  f0edc70:	01cd6025 */ 	or	$t4,$t6,$t5
/*  f0edc74:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0edc78:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0edc7c:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f0edc80:	312e03ff */ 	andi	$t6,$t1,0x3ff
/*  f0edc84:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f0edc88:	01f80019 */ 	multu	$t7,$t8
/*  f0edc8c:	2629fffc */ 	addiu	$t1,$s1,-4
/*  f0edc90:	312e03ff */ 	andi	$t6,$t1,0x3ff
/*  f0edc94:	0000c812 */ 	mflo	$t9
/*  f0edc98:	332803ff */ 	andi	$t0,$t9,0x3ff
/*  f0edc9c:	00085380 */ 	sll	$t2,$t0,0xe
/*  f0edca0:	01505825 */ 	or	$t3,$t2,$s0
/*  f0edca4:	016d6025 */ 	or	$t4,$t3,$t5
/*  f0edca8:	ac4c0008 */ 	sw	$t4,0x8($v0)
/*  f0edcac:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0edcb0:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0edcb4:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f0edcb8:	01f80019 */ 	multu	$t7,$t8
/*  f0edcbc:	0000c812 */ 	mflo	$t9
/*  f0edcc0:	332803ff */ 	andi	$t0,$t9,0x3ff
/*  f0edcc4:	00085380 */ 	sll	$t2,$t0,0xe
/*  f0edcc8:	014b6825 */ 	or	$t5,$t2,$t3
/*  f0edccc:	0fc537ce */ 	jal	func0f153838
/*  f0edcd0:	ac4d000c */ 	sw	$t5,0xc($v0)
/*  f0edcd4:	0fc5374a */ 	jal	func0f153628
/*  f0edcd8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0edcdc:	8fac009c */ 	lw	$t4,0x9c($sp)
/*  f0edce0:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f0edce4:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f0edce8:	8fa6008c */ 	lw	$a2,0x8c($sp)
/*  f0edcec:	018f1821 */ 	addu	$v1,$t4,$t7
/*  f0edcf0:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f0edcf4:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f0edcf8:	00408825 */ 	or	$s1,$v0,$zero
/*  f0edcfc:	04610003 */ 	bgez	$v1,.NB0f0edd0c
/*  f0edd00:	0003c043 */ 	sra	$t8,$v1,0x1
/*  f0edd04:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0edd08:	0001c043 */ 	sra	$t8,$at,0x1
.NB0f0edd0c:
/*  f0edd0c:	03001825 */ 	or	$v1,$t8,$zero
/*  f0edd10:	07210003 */ 	bgez	$t9,.NB0f0edd20
/*  f0edd14:	00194043 */ 	sra	$t0,$t9,0x1
/*  f0edd18:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0edd1c:	00014043 */ 	sra	$t0,$at,0x1
.NB0f0edd20:
/*  f0edd20:	00684823 */ 	subu	$t1,$v1,$t0
/*  f0edd24:	252e0002 */ 	addiu	$t6,$t1,0x2
/*  f0edd28:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f0edd2c:	95440000 */ 	lhu	$a0,0x0($t2)
/*  f0edd30:	afa6008c */ 	sw	$a2,0x8c($sp)
/*  f0edd34:	0fc5a4dd */ 	jal	langGet
/*  f0edd38:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0edd3c:	0c002f77 */ 	jal	viGetWidth
/*  f0edd40:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f0edd44:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0edd48:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0edd4c:	0c002f77 */ 	jal	viGetWidth
/*  f0edd50:	01608025 */ 	or	$s0,$t3,$zero
/*  f0edd54:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f0edd58:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0edd5c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0edd60:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0edd64:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0edd68:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0edd6c:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0edd70:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f0edd74:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0edd78:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0edd7c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0edd80:	0fc541a6 */ 	jal	textRenderProjected
/*  f0edd84:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0edd88:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0edd8c:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0edd90:	8fa6008c */ 	lw	$a2,0x8c($sp)
/*  f0edd94:	00408825 */ 	or	$s1,$v0,$zero
/*  f0edd98:	05e10003 */ 	bgez	$t7,.NB0f0edda8
/*  f0edd9c:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0edda0:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0edda4:	0001c043 */ 	sra	$t8,$at,0x1
.NB0f0edda8:
/*  f0edda8:	0198c823 */ 	subu	$t9,$t4,$t8
/*  f0eddac:	27280002 */ 	addiu	$t0,$t9,0x2
/*  f0eddb0:	24c60003 */ 	addiu	$a2,$a2,0x3
/*  f0eddb4:	afa80090 */ 	sw	$t0,0x90($sp)
/*  f0eddb8:	afa6008c */ 	sw	$a2,0x8c($sp)
/*  f0eddbc:	0fc5a4dd */ 	jal	langGet
/*  f0eddc0:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0eddc4:	0c002f77 */ 	jal	viGetWidth
/*  f0eddc8:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f0eddcc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0eddd0:	00104c03 */ 	sra	$t1,$s0,0x10
/*  f0eddd4:	0c002f77 */ 	jal	viGetWidth
/*  f0eddd8:	01208025 */ 	or	$s0,$t1,$zero
/*  f0edddc:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f0edde0:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0edde4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0edde8:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0eddec:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0eddf0:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0eddf4:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0eddf8:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f0eddfc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0ede00:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0ede04:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ede08:	0fc541a6 */ 	jal	textRenderProjected
/*  f0ede0c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ede10:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f0ede14:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0ede18:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0ede1c:	8fa60088 */ 	lw	$a2,0x88($sp)
/*  f0ede20:	00408825 */ 	or	$s1,$v0,$zero
/*  f0ede24:	05610003 */ 	bgez	$t3,.NB0f0ede34
/*  f0ede28:	000b6843 */ 	sra	$t5,$t3,0x1
/*  f0ede2c:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0ede30:	00016843 */ 	sra	$t5,$at,0x1
.NB0f0ede34:
/*  f0ede34:	014d7823 */ 	subu	$t7,$t2,$t5
/*  f0ede38:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f0ede3c:	95840000 */ 	lhu	$a0,0x0($t4)
/*  f0ede40:	0fc5a4dd */ 	jal	langGet
/*  f0ede44:	afa6008c */ 	sw	$a2,0x8c($sp)
/*  f0ede48:	0c002f77 */ 	jal	viGetWidth
/*  f0ede4c:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f0ede50:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0ede54:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f0ede58:	0c002f77 */ 	jal	viGetWidth
/*  f0ede5c:	03008025 */ 	or	$s0,$t8,$zero
/*  f0ede60:	3c19bfbf */ 	lui	$t9,0xbfbf
/*  f0ede64:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f0ede68:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0ede6c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0ede70:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0ede74:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0ede78:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0ede7c:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0ede80:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f0ede84:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0ede88:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0ede8c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ede90:	0fc541a6 */ 	jal	textRenderProjected
/*  f0ede94:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ede98:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0ede9c:	8fa6008c */ 	lw	$a2,0x8c($sp)
/*  f0edea0:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0edea4:	00408825 */ 	or	$s1,$v0,$zero
/*  f0edea8:	05210003 */ 	bgez	$t1,.NB0f0edeb8
/*  f0edeac:	00097043 */ 	sra	$t6,$t1,0x1
/*  f0edeb0:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0edeb4:	00017043 */ 	sra	$t6,$at,0x1
.NB0f0edeb8:
/*  f0edeb8:	24c60003 */ 	addiu	$a2,$a2,0x3
/*  f0edebc:	010e5823 */ 	subu	$t3,$t0,$t6
/*  f0edec0:	afab0090 */ 	sw	$t3,0x90($sp)
/*  f0edec4:	afa6008c */ 	sw	$a2,0x8c($sp)
/*  f0edec8:	0fc5a4dd */ 	jal	langGet
/*  f0edecc:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0eded0:	0c002f77 */ 	jal	viGetWidth
/*  f0eded4:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f0eded8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0ededc:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0edee0:	0c002f77 */ 	jal	viGetWidth
/*  f0edee4:	01408025 */ 	or	$s0,$t2,$zero
/*  f0edee8:	3c0dbfbf */ 	lui	$t5,0xbfbf
/*  f0edeec:	35adffff */ 	ori	$t5,$t5,0xffff
/*  f0edef0:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0edef4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0edef8:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0edefc:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0edf00:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0edf04:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0edf08:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f0edf0c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0edf10:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0edf14:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0edf18:	0fc541a6 */ 	jal	textRenderProjected
/*  f0edf1c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0edf20:	0fc537a0 */ 	jal	func0f153780
/*  f0edf24:	00402025 */ 	or	$a0,$v0,$zero
/*  f0edf28:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0edf2c:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0edf30:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0edf34:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0edf38:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0edf3c:	03e00008 */ 	jr	$ra
/*  f0edf40:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#endif

u32 var8007144c = 0x51e451e5;
u32 var80071450 = 0x51e651e7;
u32 var80071454 = 0x51e851e9;
u32 var80071458 = 0x51ea51eb;
u32 var8007145c = 0x51ec51ed;
u32 var80071460 = 0x51ee0000;

#if VERSION >= VERSION_NTSC_1_0
const char var7f1b23e8[] = "TM";
#endif

// Mismatch: Regalloc at first y calculation. Note that the calculation of tmp
// is postponed until later (tmp is eventually stored in a compiler-managed
// stack slot).
//#if VERSION >= VERSION_NTSC_1_0
//Gfx *menuRenderBanner(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, bool big, s32 msgnum, s32 arg7, s32 arg8)
//#else
//Gfx *menuRenderBanner(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, bool big, s32 msgnum)
//#endif
//{
//	s32 tmp;
//	s32 x; // 88
//	s32 y; // 84
//	s32 texttop; // 80
//	s32 textheight; // 7c
//	s32 textwidth; // 78
//	s32 waitheight; // 74
//	s32 waitwidth; // 70
//	s32 bannertop; // 6c
//	s32 bannerbottom; // 68
//	struct fontchar *chars; // 64
//	struct font *font; // 60
//
//	static u16 msgs[] = {
//		L_MPMENU_484, // "Searching for Camera!"
//		L_MPMENU_485, // "Calibrating Camera"
//		L_MPMENU_486, // "Downloading Image"
//		L_MPMENU_487, // "Loading Image"
//		L_MPMENU_488, // "Saving Image"
//		L_MPMENU_489, // "Transferring Image"
//		L_MPMENU_490, // "Uploading Segment"
//		L_MPMENU_491, // "Checking Controller Pak"
//		L_MPMENU_492, // "Getting PerfectHead"
//		L_MPMENU_493, // "Saving PerfectHead"
//		L_MPMENU_494, // "Auto Camera Adjustment"
//	};
//
//	chars = g_CharsHandelGothicSm;
//	font = g_FontHandelGothicSm;
//
//	if (big) {
//#if VERSION >= VERSION_PAL_FINAL
//		if (g_CharsHandelGothicMd) {
//			chars = g_CharsHandelGothicMd;
//			font = g_FontHandelGothicMd;
//		}
//#else
//		chars = g_CharsHandelGothicMd;
//		font = g_FontHandelGothicMd;
//#endif
//	}
//
//#if VERSION >= VERSION_NTSC_1_0
//	tmp = x1 + arg7 + x2 - arg8;
//	tmp /= 2;
//#else
//	tmp = x1 + x2;
//	tmp /= 2;
//#endif
//
//	y = y1 + y2;
//	y /= 2;
//
//	textMeasure(&textheight, &textwidth, langGet(msgs[msgnum]), chars, font, 0);
//
//	// "Please Wait..."
//	textMeasure(&waitheight, &waitwidth, langGet(L_MPMENU_495), chars, font, 0);
//
//#if VERSION >= VERSION_NTSC_1_0
//	if (msgs[msgnum] == L_MPMENU_491) { // "Checking Controller Pak"
//		// Add space for "TM"
//		textwidth += 7;
//	}
//#endif
//
//	texttop = y - (textheight + waitheight) / 2;
//	bannertop = texttop - 4;
//	bannerbottom = texttop + textheight + waitheight + 7;
//
//	y = texttop;
//
//	// Black fill
//	gdl = gfxSetPrimColour(gdl, 0x0000007f);
//	gDPFillRectangleScaled(gdl++, x1, y1, x2, y2);
//	gdl = func0f153838(gdl);
//
//	// Dark blue fill
//	gdl = gfxSetPrimColour(gdl, 0x00007f7f);
//	gDPFillRectangleScaled(gdl++, x1, bannertop, x2, bannerbottom);
//	gdl = func0f153838(gdl);
//
//	// Top and bottom borders (light blue)
//	gdl = gfxSetPrimColour(gdl, 0x7f7fff7f);
//	gDPFillRectangleScaled(gdl++, x1, bannerbottom + 2, x2, bannerbottom + 4);
//	gDPFillRectangleScaled(gdl++, x1, bannertop - 4, x2, bannertop - 2);
//	gdl = func0f153838(gdl);
//
//	gdl = func0f153628(gdl);
//
//	// Render the selected message's shadow
//	x = tmp - textwidth / 2 + 2;
//	y += 2;
//	gdl = textRenderProjected(gdl, &x, &y, langGet(msgs[msgnum]),
//			chars, font, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);
//
//	// Render "Please Wait..." shadow
//	x = tmp - waitwidth / 2 + 2;
//	y += 3;
//	gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_495),
//			chars, font, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);
//
//	// Render the selected message proper
//	x = tmp - textwidth / 2;
//	y = texttop;
//	gdl = textRenderProjected(gdl, &x, &y, langGet(msgs[msgnum]),
//			chars, font, 0xbfbfffff, viGetWidth(), viGetWidth(), 0, 0);
//
//	// Render "Please Wait..." proper
//	x = tmp - waitwidth / 2;
//	y += 3;
//	gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_495),
//			chars, font, 0xbfbfffff, viGetWidth(), viGetWidth(), 0, 0);
//
//#if VERSION >= VERSION_NTSC_1_0
//	if (msgs[msgnum] == L_MPMENU_491) { // "Checking Controller Pak"
//		// Render "TM"
//		y = texttop - 1;
//		x = textwidth / 2 + tmp - 7;
//		gdl = textRenderProjected(gdl, &x, &y, "TM",
//				g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xbfbfffff, viGetWidth(), viGetWidth(), 0, 0);
//	}
//#endif
//
//	gdl = func0f153780(gdl);
//
//	return gdl;
//}

u32 var80071464 = 0;

struct menudfc *func0f0f1338(struct menuitem *item)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Menus[g_MpPlayerNum].unkdfc[i].item == item) {
			return &g_Menus[g_MpPlayerNum].unkdfc[i];
		}
	}

	return NULL;
}

void func0f0f139c(struct menuitem *item, f32 arg1)
{
	struct menudfc *thing = func0f0f1338(item);

	if (thing) {
		thing->unk04 = arg1;
		return;
	}

	thing = func0f0f1338(NULL);

	if (thing) {
		thing->item = item;
		thing->unk04 = arg1;
	}
}

void func0f0f13ec(struct menuitem *item)
{
	struct menudfc *thing = func0f0f1338(item);

	if (thing) {
		thing->item = NULL;
	}
}

void func0f0f1418(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Menus[g_MpPlayerNum].unkdfc[i].item) {
#if VERSION >= VERSION_PAL_FINAL
			g_Menus[g_MpPlayerNum].unkdfc[i].unk04 += g_Vars.diffframe60freal / 60.0f;
#else
			g_Menus[g_MpPlayerNum].unkdfc[i].unk04 += g_Vars.diffframe60f / 60.0f;
#endif
		}
	}
}

void func0f0f1494(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		g_Menus[g_MpPlayerNum].unkdfc[i].item = NULL;
	}
}

char *menuResolveText(u32 thing, void *dialogoritem)
{
	char *(*handler)(void *dialogoritem) = (void *)thing;

	// Null/zero
	if (thing == 0) {
		return NULL;
	}

	// Text ID
	if (thing < 0x5a00) {
		return langGet((u32)thing);
	}

	if (thing > (u32)func0f1a78b0) {
#if VERSION < VERSION_NTSC_1_0
		CRASH();
#endif
		return NULL;
	}

	// Function pointer
	if (handler) {
		return handler(dialogoritem);
	}

	return "";
}

char *menuResolveParam2Text(struct menuitem *item)
{
	return menuResolveText(item->param2, item);
}

char *menuResolveDialogTitle(struct menudialogdef *dialogdef)
{
	return menuResolveText(dialogdef->title, dialogdef);
}

void func0f0f15a4(struct menuitem *item, s32 *arg1)
{
	switch (item->type) {
	case MENUITEMTYPE_SLIDER:
	case MENUITEMTYPE_CHECKBOX:
	case MENUITEMTYPE_RANKING:
	case MENUITEMTYPE_14:
	case MENUITEMTYPE_18:
		*arg1 = 1;
		break;
#if VERSION < VERSION_PAL_FINAL
	case MENUITEMTYPE_SCROLLABLE:
#endif
	case MENUITEMTYPE_MARQUEE:
	case MENUITEMTYPE_CONTROLLER:
		*arg1 = 2;
		break;
	case MENUITEMTYPE_LIST:
#if VERSION >= VERSION_PAL_FINAL
	case MENUITEMTYPE_SCROLLABLE:
#endif
		*arg1 = 3;
		break;
	case MENUITEMTYPE_DROPDOWN:
		*arg1 = 4;
		break;
	case MENUITEMTYPE_PLAYERSTATS:
		*arg1 = 5;
		break;
	case MENUITEMTYPE_KEYBOARD:
	case MENUITEMTYPE_10:
	case MENUITEMTYPE_16:
		*arg1 = 3;
		break;
	}
}

void menuCalculateItemSize(struct menuitem *item, s16 *width, s16 *height, struct menudialog *dialog)
{
	char *text;
	s32 textwidth;
	s32 textheight;
	struct fontchar *chars = g_CharsHandelGothicSm;
	struct font *font = g_FontHandelGothicSm;
	s32 i;
	union handlerdata handlerdata;
	union handlerdata handlerdata2;
	char *text2;
	s32 numobjectives;

	// Check if item's handler handles MENUOP_CHECKHIDDEN
	if (item->handler && (item->flags & MENUITEMFLAG_00000004) == 0) {
		if (item->handler(MENUOP_CHECKHIDDEN, item, &handlerdata)) {
			*width = 0;
			*height = 0;
			return;
		}
	}

	switch (item->type) {
	case MENUITEMTYPE_CONTROLLER:
		*height = PAL ? 156 : 150;
		*width = 230;
		break;
	case MENUITEMTYPE_18:
		*height = item->param2 == 1 ? 170 : 126;
		*width = 210;
		break;
	case MENUITEMTYPE_14:
		*width = 90;
		*height = 54;
		break;
	case MENUITEMTYPE_METER:
		*width = 24;
		*height = 6;
		break;
	case MENUITEMTYPE_KEYBOARD:
		*width = 130;
		*height = 73;
		break;
	case MENUITEMTYPE_LIST:
		if (item->param2 > 0) {
			*width = item->param2;
		} else {
			*width = 80;

#if VERSION >= VERSION_NTSC_1_0
			if ((item->flags & MENUITEMFLAG_00000040) != 0) {
				*width = 180;
			}
#else
			if ((item->flags && MENUITEMFLAG_00000040) != 0) {
				*width = 180;
			}
#endif
		}

		*height = item->param3 > 0 ? item->param3 : 121;
		break;
	case MENUITEMTYPE_DROPDOWN:
		text = menuResolveParam2Text(item);

		if (text && strcmp(text, "") == 0) {
			*width = 0;
			*height = 0;
		} else {
			textwidth = 0;
			textheight = 0;

			if (text != NULL) {
				textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
			}

			*width = textwidth + 20;
			*height = 12;

			if (item->handler) {
				handlerdata2.dropdown.value = 0;
				item->handler(MENUOP_GETOPTIONVALUE, item, &handlerdata2);
				handlerdata2.dropdown.unk04 = 0;
				text2 = (char *)item->handler(MENUOP_GETOPTIONTEXT, item, &handlerdata2);
				textMeasure(&textheight, &textwidth, text2, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

#if VERSION >= VERSION_PAL_FINAL
				if ((item->flags & MENUITEMFLAG_00001000) == 0) {
					*width += textwidth + 10;
				} else {
					*width += textwidth + 3;
				}
#else
				*width += textwidth + 10;
#endif
			}
		}
		break;
	case MENUITEMTYPE_13:
		*width = 70;
		*height = 50;
		break;
	case MENUITEMTYPE_SLIDER:
		if (dialog && dialog->unk6e) {
			*width = 120;
			*height = 22;
			return;
		}

		*width = 150;
		*height = 12;

		if (item->flags & MENUITEMFLAG_00100000) {
			*height = 22;
			*width = 120;
		}
		break;
	case MENUITEMTYPE_CHECKBOX:
		if (item->flags & MENUITEMFLAG_00000200) {
			chars = g_CharsHandelGothicXs;
			font = g_FontHandelGothicXs;
		}

		text = menuResolveParam2Text(item);

		if (text == NULL) {
			*width = 120;
		} else if (strcmp(text, "") == 0) {
			*width = 0;
			*height = 0;
		} else {
			textMeasure(&textheight, &textwidth, text, chars, font, 0);
			*width = (s16)textwidth + 34;
		}
		*height = 12;
		break;
	case MENUITEMTYPE_MODEL:
		*width = item->param2;
		*height = item->param3;
		break;
	case MENUITEMTYPE_SEPARATOR:
		*width = 1;
		if (item->param2) {
			*width = item->param2;
		}
		*height = 5;
		break;
	case MENUITEMTYPE_MARQUEE:
		*width = 1;
		if (item->flags & MENUITEMFLAG_00000200) {
			*height = 11;
		} else {
			*height = 13;
		}
		break;
	case MENUITEMTYPE_LABEL:
	case MENUITEMTYPE_SELECTABLE:
		text = menuResolveParam2Text(item);

		if (text == NULL) {
			*width = 0;
			*height = 0;
			return;
		}

		if (item->flags & MENUITEMFLAG_00000200) {
			chars = g_CharsHandelGothicXs;
			font = g_FontHandelGothicXs;
		}

		if (item->flags & MENUITEMFLAG_00400000) {
			chars = g_CharsHandelGothicMd;
			font = g_FontHandelGothicMd;
		}

		if (strcmp(text, "") == 0) {
			*height = 0;
			*width = *height;
		} else {
			textMeasure(&textheight, &textwidth, text, chars, font, 0);
			*width = (s16)textwidth + 8;

			if ((item->flags & (MENUITEMFLAG_00000010 | MENUITEMFLAG_00001000)) == 0) {
				*width += 20;
			}

			*height = textheight + 3;

			if (item->flags & MENUITEMFLAG_00000200) {
				*height -= 2;
			}

			if ((item->flags & (MENUITEMFLAG_00008000 | MENUITEMFLAG_00400000)) == 0) {
				text = menuResolveText(item->param3, item);

				// @bug: This is not how you check for an empty string
				if (text != NULL && text != "") {
					textMeasure(&textheight, &textwidth, text, chars, font, 0);
					*width += textwidth + 5;

					if (item->flags & MENUITEMFLAG_00001000) {
						*width -= 6;
					}
				}
			}
		}

		if (item->flags & MENUITEMFLAG_00400000) {
			*height = 28;
			*width += 36;
		}

		if (item->flags & MENUITEMFLAG_02000000) {
			*height -= 1;
		}
		break;
	case MENUITEMTYPE_SCROLLABLE:
		*width = item->param2 > 0 ? item->param2 : 240;
		*height = item->param3 > 0 ? item->param3 : 150;
		break;
	case MENUITEMTYPE_OBJECTIVES:
		numobjectives = 0;
		*width = 240;

		for (i = 0; i < 6; i++) {
			if (g_Briefing.objectivenames[i] && (g_Briefing.objectivedifficulties[i] & (1 << lvGetDifficulty()))) {
				numobjectives++;
			}
		}

		if (item->param == 0) {
			*height = 9 + numobjectives * 18;
		} else if (item->param == 1) {
			*height = 9 + numobjectives * 14;
		} else if (item->param == 2) {
			*height = 9 + numobjectives * (PAL ? 34 : 30);
			*width = 120;
		}
		break;
	case MENUITEMTYPE_07:
		*width = 120;
		*height = 120;
		break;
	case MENUITEMTYPE_PLAYERSTATS:
		*width = 125;
		*height = 68;
		break;
	case MENUITEMTYPE_RANKING:
		*width = 125;
		*height = 58;
		break;
	case MENUITEMTYPE_10:
		*width = item->param2 ? item->param2 + 2 : 66;
		*height = *width;
		break;
	case MENUITEMTYPE_16:
		*width = 66;
		*height = *width;
		break;
	case MENUITEMTYPE_CAROUSEL:
		*width = 130;
		*height = item->param3;
		break;
	default:
		*width = 80;
		*height = 12;
		break;
	}
}

const char var7f1b2400[] = "(BNC:Menu) findItem Warning: Item not found\n";
const char var7f1b2430[] = "(BNC:Menu) menuFirstFocus - Menu %s does not have any focusable item!\n";
const char var7f1b2478[] = "(BNC:Menu) menuLastFocus - Menu %s does not have any focusable item!\n";
const char var7f1b24c0[] = "Init menu %x\n";
const char var7f1b24d0[] = "[]-[] Added Main menu to ctl slot %d\n";
const char var7f1b24f8[] = "[]-[] Added Slide menu to ctl slot %d\n";
const char var7f1b2520[] = "[]-[] StackStart Stats: slides %d, ctlPtr %d slidePtr %d\n";
const char var7f1b255c[] = "$-$-$avePtr: %d\n";
const char var7f1b2570[] = "[]-[] Menu End: now %d slides\n";
const char var7f1b2590[] = "Freeing challenge mem\n";
const char var7f1b25a8[] = "IG:) style %d gbHead:%d\n";
const char var7f1b25c4[] = "GRABBED GUN MEM!\n";
const char var7f1b25d8[] = "Freeing challenge mem\n";
const char var7f1b25f0[] = "mzn";
const char var7f1b25f4[] = "mzf";

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f0f1d6c
/*  f0f1d6c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0f1d70:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0f1d74:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f1d78:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f1d7c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0f1d80:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0f1d84:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0f1d88:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f1d8c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f1d90:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f1d94:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f1d98:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f0f1d9c:	8cc206d8 */ 	lw	$v0,0x6d8($a2)
/*  f0f1da0:	8c910008 */ 	lw	$s1,0x8($a0)
/*  f0f1da4:	84d7081e */ 	lh	$s7,0x81e($a2)
/*  f0f1da8:	8cd6065c */ 	lw	$s6,0x65c($a2)
/*  f0f1dac:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0f1db0:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0f1db4:	00a0f025 */ 	or	$s8,$a1,$zero
/*  f0f1db8:	00009825 */ 	or	$s3,$zero,$zero
/*  f0f1dbc:	a0a00005 */ 	sb	$zero,0x5($a1)
/*  f0f1dc0:	a0b80004 */ 	sb	$t8,0x4($a1)
/*  f0f1dc4:	1220003a */ 	beqz	$s1,.L0f0f1eb0
/*  f0f1dc8:	a4b70006 */ 	sh	$s7,0x6($a1)
/*  f0f1dcc:	92390000 */ 	lbu	$t9,0x0($s1)
/*  f0f1dd0:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0f1dd4:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0f1dd8:	13210035 */ 	beq	$t9,$at,.L0f0f1eb0
/*  f0f1ddc:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0f1de0:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0f1de4:	01224821 */ 	addu	$t1,$t1,$v0
/*  f0f1de8:	00094840 */ 	sll	$t1,$t1,0x1
/*  f0f1dec:	00165080 */ 	sll	$t2,$s6,0x2
/*  f0f1df0:	010a9021 */ 	addu	$s2,$t0,$t2
/*  f0f1df4:	01098021 */ 	addu	$s0,$t0,$t1
/*  f0f1df8:	2415ffff */ 	addiu	$s5,$zero,-1
.L0f0f1dfc:
/*  f0f1dfc:	8e2b0004 */ 	lw	$t3,0x4($s1)
/*  f0f1e00:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f1e04:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f0f1e08:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f0f1e0c:	11800002 */ 	beqz	$t4,.L0f0f1e18
/*  f0f1e10:	00000000 */ 	nop
/*  f0f1e14:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0f1e18:
/*  f0f1e18:	5280000d */ 	beqzl	$s4,.L0f0f1e50
/*  f0f1e1c:	afb50058 */ 	sw	$s5,0x58($sp)
/*  f0f1e20:	93cd0005 */ 	lbu	$t5,0x5($s8)
/*  f0f1e24:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f1e28:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f0f1e2c:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0f1e30:	a3ce0005 */ 	sb	$t6,0x5($s8)
/*  f0f1e34:	a6000660 */ 	sh	$zero,0x660($s0)
/*  f0f1e38:	a6000662 */ 	sh	$zero,0x662($s0)
/*  f0f1e3c:	a2000664 */ 	sb	$zero,0x664($s0)
/*  f0f1e40:	a2000668 */ 	sb	$zero,0x668($s0)
/*  f0f1e44:	a6160666 */ 	sh	$s6,0x666($s0)
/*  f0f1e48:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0f1e4c:	afb50058 */ 	sw	$s5,0x58($sp)
.L0f0f1e50:
/*  f0f1e50:	0fc3c569 */ 	jal	func0f0f15a4
/*  f0f1e54:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f0f1e58:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f0f1e5c:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f0f1e60:	51f50008 */ 	beql	$t7,$s5,.L0f0f1e84
/*  f0f1e64:	a25504ff */ 	sb	$s5,0x4ff($s2)
/*  f0f1e68:	a25704ff */ 	sb	$s7,0x4ff($s2)
/*  f0f1e6c:	87b8005a */ 	lh	$t8,0x5a($sp)
/*  f0f1e70:	02f8b821 */ 	addu	$s7,$s7,$t8
/*  f0f1e74:	0017cc00 */ 	sll	$t9,$s7,0x10
/*  f0f1e78:	10000002 */ 	b	.L0f0f1e84
/*  f0f1e7c:	0019bc03 */ 	sra	$s7,$t9,0x10
/*  f0f1e80:	a25504ff */ 	sb	$s5,0x4ff($s2)
.L0f0f1e84:
/*  f0f1e84:	a25304fe */ 	sb	$s3,0x4fe($s2)
/*  f0f1e88:	92080668 */ 	lbu	$t0,0x668($s0)
/*  f0f1e8c:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0f1e90:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f0f1e94:	250a0001 */ 	addiu	$t2,$t0,0x1
/*  f0f1e98:	a20a0668 */ 	sb	$t2,0x668($s0)
/*  f0f1e9c:	922b0014 */ 	lbu	$t3,0x14($s1)
/*  f0f1ea0:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0f1ea4:	26310014 */ 	addiu	$s1,$s1,0x14
/*  f0f1ea8:	1561ffd4 */ 	bne	$t3,$at,.L0f0f1dfc
/*  f0f1eac:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f0f1eb0:
/*  f0f1eb0:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0f1eb4:	244c0001 */ 	addiu	$t4,$v0,0x1
/*  f0f1eb8:	adac06d8 */ 	sw	$t4,0x6d8($t5)
/*  f0f1ebc:	adb6065c */ 	sw	$s6,0x65c($t5)
/*  f0f1ec0:	adb7081c */ 	sw	$s7,0x81c($t5)
/*  f0f1ec4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f1ec8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0f1ecc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0f1ed0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0f1ed4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0f1ed8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f1edc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f1ee0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f1ee4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f1ee8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f1eec:	03e00008 */ 	jr	$ra
/*  f0f1ef0:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#else
GLOBAL_ASM(
glabel func0f0f1d6c
/*  f0ee988:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0ee98c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0ee990:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0ee994:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ee998:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0ee99c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0ee9a0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0ee9a4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0ee9a8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0ee9ac:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0ee9b0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ee9b4:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f0ee9b8:	8cc20634 */ 	lw	$v0,0x634($a2)
/*  f0ee9bc:	8c910008 */ 	lw	$s1,0x8($a0)
/*  f0ee9c0:	84d7077a */ 	lh	$s7,0x77a($a2)
/*  f0ee9c4:	8cd605cc */ 	lw	$s6,0x5cc($a2)
/*  f0ee9c8:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0ee9cc:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0ee9d0:	00a0f025 */ 	or	$s8,$a1,$zero
/*  f0ee9d4:	00009825 */ 	or	$s3,$zero,$zero
/*  f0ee9d8:	a0a00005 */ 	sb	$zero,0x5($a1)
/*  f0ee9dc:	a0b80004 */ 	sb	$t8,0x4($a1)
/*  f0ee9e0:	1220003a */ 	beqz	$s1,.NB0f0eeacc
/*  f0ee9e4:	a4b70006 */ 	sh	$s7,0x6($a1)
/*  f0ee9e8:	92390000 */ 	lbu	$t9,0x0($s1)
/*  f0ee9ec:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0ee9f0:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0ee9f4:	13210035 */ 	beq	$t9,$at,.NB0f0eeacc
/*  f0ee9f8:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0ee9fc:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0eea00:	01224821 */ 	addu	$t1,$t1,$v0
/*  f0eea04:	00094840 */ 	sll	$t1,$t1,0x1
/*  f0eea08:	00165080 */ 	sll	$t2,$s6,0x2
/*  f0eea0c:	010a9021 */ 	addu	$s2,$t0,$t2
/*  f0eea10:	01098021 */ 	addu	$s0,$t0,$t1
/*  f0eea14:	2415ffff */ 	addiu	$s5,$zero,-1
.NB0f0eea18:
/*  f0eea18:	8e2b0004 */ 	lw	$t3,0x4($s1)
/*  f0eea1c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0eea20:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f0eea24:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f0eea28:	11800002 */ 	beqz	$t4,.NB0f0eea34
/*  f0eea2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eea30:	24140001 */ 	addiu	$s4,$zero,0x1
.NB0f0eea34:
/*  f0eea34:	5280000d */ 	beqzl	$s4,.NB0f0eea6c
/*  f0eea38:	afb50058 */ 	sw	$s5,0x58($sp)
/*  f0eea3c:	93cd0005 */ 	lbu	$t5,0x5($s8)
/*  f0eea40:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0eea44:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f0eea48:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0eea4c:	a3ce0005 */ 	sb	$t6,0x5($s8)
/*  f0eea50:	a60005d0 */ 	sh	$zero,0x5d0($s0)
/*  f0eea54:	a60005d2 */ 	sh	$zero,0x5d2($s0)
/*  f0eea58:	a20005d4 */ 	sb	$zero,0x5d4($s0)
/*  f0eea5c:	a20005d8 */ 	sb	$zero,0x5d8($s0)
/*  f0eea60:	a61605d6 */ 	sh	$s6,0x5d6($s0)
/*  f0eea64:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0eea68:	afb50058 */ 	sw	$s5,0x58($sp)
.NB0f0eea6c:
/*  f0eea6c:	0fc3b86d */ 	jal	func0f0f15a4
/*  f0eea70:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f0eea74:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f0eea78:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f0eea7c:	51f50008 */ 	beql	$t7,$s5,.NB0f0eeaa0
/*  f0eea80:	a255048f */ 	sb	$s5,0x48f($s2)
/*  f0eea84:	a257048f */ 	sb	$s7,0x48f($s2)
/*  f0eea88:	87b8005a */ 	lh	$t8,0x5a($sp)
/*  f0eea8c:	02f8b821 */ 	addu	$s7,$s7,$t8
/*  f0eea90:	0017cc00 */ 	sll	$t9,$s7,0x10
/*  f0eea94:	10000002 */ 	beqz	$zero,.NB0f0eeaa0
/*  f0eea98:	0019bc03 */ 	sra	$s7,$t9,0x10
/*  f0eea9c:	a255048f */ 	sb	$s5,0x48f($s2)
.NB0f0eeaa0:
/*  f0eeaa0:	a253048e */ 	sb	$s3,0x48e($s2)
/*  f0eeaa4:	920805d8 */ 	lbu	$t0,0x5d8($s0)
/*  f0eeaa8:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0eeaac:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f0eeab0:	250a0001 */ 	addiu	$t2,$t0,0x1
/*  f0eeab4:	a20a05d8 */ 	sb	$t2,0x5d8($s0)
/*  f0eeab8:	922b0014 */ 	lbu	$t3,0x14($s1)
/*  f0eeabc:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0eeac0:	26310014 */ 	addiu	$s1,$s1,0x14
/*  f0eeac4:	1561ffd4 */ 	bne	$t3,$at,.NB0f0eea18
/*  f0eeac8:	26730001 */ 	addiu	$s3,$s3,0x1
.NB0f0eeacc:
/*  f0eeacc:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0eead0:	244c0001 */ 	addiu	$t4,$v0,0x1
/*  f0eead4:	adac0634 */ 	sw	$t4,0x634($t5)
/*  f0eead8:	adb605cc */ 	sw	$s6,0x5cc($t5)
/*  f0eeadc:	adb70778 */ 	sw	$s7,0x778($t5)
/*  f0eeae0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0eeae4:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0eeae8:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0eeaec:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0eeaf0:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0eeaf4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0eeaf8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0eeafc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0eeb00:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0eeb04:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0eeb08:	03e00008 */ 	jr	$ra
/*  f0eeb0c:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#endif

// Mismatch: Goal stores colindex in v0 while the below stores it in v0
// initially but then all the increments in v1, resulting in one less
// instruction. Removing the + 1 from the assign to dialog->colstart or
// menu->colend causes the below to use v0 only, which is a closer
// match but is functionally incorrect.
//void func0f0f1d6c(struct menudialogdef *dialogdef, struct menudialog *dialog, struct menu *menu)
//{
//	s32 colindex = menu->colend - 1; // 64
//	s32 rowindex = menu->rowend;
//	s32 itemindex = 0;
//	s32 numblocksthisitem; // 58
//	struct menuitem *item = dialogdef->items;
//	s16 blockindex = menu->blockend;
//
//	dialog->numcols = 0;
//	dialog->colstart = colindex + 1;
//	dialog->blockstart = blockindex;
//
//	if (item) {
//		bool append = true;
//
//		while (item->type != MENUITEMTYPE_END) {
//			if (item->flags & MENUITEMFLAG_00000001) {
//				append = true;
//			}
//
//			if (append) {
//				dialog->numcols++;
//				colindex++;
//
//				menu->cols[colindex].width = 0;
//				menu->cols[colindex].height = 0;
//				menu->cols[colindex].unk04 = 0;
//				menu->cols[colindex].numrows = 0;
//				menu->cols[colindex].rowstart = rowindex;
//
//				append = false;
//			}
//
//			numblocksthisitem = -1;
//			func0f0f15a4(item, &numblocksthisitem);
//
//			if (numblocksthisitem != -1) {
//				menu->rows[rowindex].blockindex = blockindex;
//				blockindex += (s16)numblocksthisitem;
//			} else {
//				menu->rows[rowindex].blockindex = -1;
//			}
//
//			menu->rows[rowindex].itemindex = itemindex;
//			menu->cols[colindex].numrows++;
//			rowindex++;
//			item++;
//			itemindex++;
//		}
//	}
//
//	menu->colend = colindex + 1;
//	menu->rowend = rowindex;
//	menu->blockend = blockindex;
//}

void dialog0f0f1ef4(struct menudialog *dialog)
{
	s32 bodyheight = dialog->height - 12;
	s32 itemheight;
	s32 i;
	s32 j;

	if ((dialog->definition->flags & MENUDIALOGFLAG_SMOOTHSCROLLABLE) == 0
			&& g_MenuData.root != MENUROOT_TRAINING
			&& bodyheight < dialog->contentheight) {
		for (i = 0; i < dialog->numcols; i++) {
			s32 colindex = dialog->colstart + i;
			s32 remaining = g_Menus[g_MpPlayerNum].cols[colindex].height - bodyheight;

			if (remaining > 0) {
				for (j = 0; j < g_Menus[g_MpPlayerNum].cols[colindex].numrows; j++) {
					if (remaining > 0) {
						s32 itemheight = 0;
						s32 rowindex = g_Menus[g_MpPlayerNum].cols[colindex].rowstart + j;
						struct menuitem *item = &dialog->definition->items[g_Menus[g_MpPlayerNum].rows[rowindex].itemindex];

						switch (item->type) {
						case MENUITEMTYPE_LIST:
							if (item->flags & MENUITEMFLAG_00200000) {
								itemheight = remaining;

								if (g_Menus[g_MpPlayerNum].rows[rowindex].height - itemheight < 30) {
									itemheight = g_Menus[g_MpPlayerNum].rows[rowindex].height - 30;
								}
							} else {
								itemheight = (remaining + 10) / 11 * 11;
							}
							break;
						case MENUITEMTYPE_SCROLLABLE:
						case MENUITEMTYPE_MODEL:
							itemheight = remaining;
							if (g_Menus[g_MpPlayerNum].rows[rowindex].height - remaining < 50) {
								itemheight = g_Menus[g_MpPlayerNum].rows[rowindex].height - 50;
							}
							break;
						}

						if (itemheight > 0) {
							g_Menus[g_MpPlayerNum].rows[rowindex].height -= itemheight;
							remaining -= itemheight;
						}
					}
				}
			}
		}
	}
}

void dialogCalculateContentSize(struct menudialogdef *dialogdef, struct menudialog *dialog, struct menu *menu)
{
	s32 contentheight;
	s32 rowindex;
	s32 contentwidth;
	s32 titleextra;
	s32 i;
	s32 textwidth;
	s32 textheight;
	u32 stack;
	struct menuitem *item = dialogdef->items;
	s32 colindex = dialog->colstart - 1;

	// Iterate items and calculate their dimensions
	if (item != NULL) {
		bool newcolumn = true;
		s16 width;
		s16 height;

		while (item->type != MENUITEMTYPE_END) {
			if (item->flags & MENUITEMFLAG_00000001) {
				newcolumn = true;
			}

			if (newcolumn) {
				colindex++;
				menu->cols[colindex].width = 0;
				menu->cols[colindex].height = 0;

				newcolumn = false;
				rowindex = menu->cols[colindex].rowstart;
			}

			menuCalculateItemSize(item, &width, &height, dialog);

			if (width > menu->cols[colindex].width) {
				menu->cols[colindex].width = width;
			}

			menu->rows[rowindex].height = height;
			menu->cols[colindex].height += height;
			rowindex++;
			item++;
		}
	}

	contentheight = 0;
	contentwidth = 0;

	for (i = 0; i < dialog->numcols; i++) {
		s32 columnheight = menu->cols[dialog->colstart + i].height;

		contentwidth += menu->cols[dialog->colstart + i].width;

		if (columnheight > contentheight) {
			contentheight = columnheight;
		}
	}

	contentheight += 12;

	// Calculate and consider the title width.
	// Some of the multiplayer dialogs have a player number
	// in the top right, so extra space is considered for those.
	textMeasure(&textheight, &textwidth, menuResolveDialogTitle(dialog->definition), g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

	titleextra = 8;

	switch (g_MenuData.root) {
	case MENUROOT_MPSETUP:
	case MENUROOT_MPPAUSE:
	case MENUROOT_MPENDSCREEN:
	case MENUROOT_4MBMAINMENU:
		titleextra = 17;
		break;
	}

	if (textwidth + titleextra > contentwidth) {
		contentwidth = textwidth + titleextra;
	}

	dialog->contentwidth = contentwidth;
	dialog->contentheight = contentheight;
}

/**
 * Find the given item in the given dialog, and write its column and row indices
 * to the given pointers. Return the y value of the item relative to the dialog.
 */
s32 dialogFindItem(struct menudialog *dialog, struct menuitem *item, s32 *rowindex, s32 *colindex)
{
	for (*colindex = dialog->colstart; *colindex < dialog->colstart + dialog->numcols; *colindex += 1) {
		s32 y = 0;
		*rowindex = g_Menus[g_MpPlayerNum].cols[*colindex].rowstart;

		while (*rowindex < g_Menus[g_MpPlayerNum].cols[*colindex].rowstart + g_Menus[g_MpPlayerNum].cols[*colindex].numrows) {
			struct menuitem *thisitem = &dialog->definition->items[g_Menus[g_MpPlayerNum].rows[*rowindex].itemindex];

			if (thisitem == item) {
				return y;
			}

			y = y + g_Menus[g_MpPlayerNum].rows[*rowindex].height;
			*rowindex += 1;
		}
	}

	*colindex = dialog->colstart;
	*rowindex = g_Menus[g_MpPlayerNum].cols[*colindex].rowstart;

	return 0;
}

/**
 * If this returns true, the scrollable is rendered with less padding and
 * scrolling is disabled.
 */
bool menuIsScrollableUnscrollable(struct menuitem *item)
{
	if (item->type == MENUITEMTYPE_SCROLLABLE) {
		if (item->param == DESCRIPTION_MPCONFIG
				|| item->param == DESCRIPTION_MPCHALLENGE
				|| item->param == DESCRIPTION_DEVICETRAINING
				|| item->param == DESCRIPTION_FRWEAPON
				|| item->param == DESCRIPTION_HOLOTRAINING) {
			return true;
		}
	}

	return false;
}

bool menuIsItemDisabled(struct menuitem *item, struct menudialog *dialog)
{
	union handlerdata sp30;
	s16 width;
	s16 height;
	u32 stack[2];

	if (item->flags & MENUITEMFLAG_00000400) {
		return true;
	}

	if (mpIsPlayerLockedOut(g_MpPlayerNum) && item->flags & MENUITEMFLAG_00040000) {
		return true;
	}

	if (menuIsScrollableUnscrollable(item)) {
		return true;
	}

	if (item->handler
			&& (item->flags & MENUITEMFLAG_00000004) == 0
			&& item->handler(MENUOP_CHECKDISABLED, item, &sp30)) {
		return true;
	}

	menuCalculateItemSize(item, &width, &height, dialog);

	if (height == 0) {
		return true;
	}

	return false;
}

bool menuIsItemFocusable(struct menuitem *item, struct menudialog *dialog, s32 arg2)
{
	s32 rowindex;
	s32 colindex;

	switch (item->type) {
	case MENUITEMTYPE_LABEL:
	case MENUITEMTYPE_OBJECTIVES:
	case MENUITEMTYPE_07:
	case MENUITEMTYPE_SEPARATOR:
	case MENUITEMTYPE_MODEL:
	case MENUITEMTYPE_13:
	case MENUITEMTYPE_METER:
	case MENUITEMTYPE_MARQUEE:
	case MENUITEMTYPE_CONTROLLER:
		return false;
	case MENUITEMTYPE_10:
	case MENUITEMTYPE_14:
	case MENUITEMTYPE_16:
	case MENUITEMTYPE_18:
		dialogFindItem(dialog, item, &rowindex, &colindex);
	}

	if (menuIsItemDisabled(item, dialog)) {
		return false;
	}

	return true;
}

struct menuitem *dialogFindItemAtColY(s32 targety, s32 colindex, struct menudialogdef *dialogdef, s32 *rowindexptr, struct menudialog *dialog)
{
	struct menuitem *result = NULL;
	bool done = false;
	s32 rowindex = g_Menus[g_MpPlayerNum].cols[colindex].rowstart;
	s32 y;
	s32 i;

	for (i = 0, y = 0; !done && i < g_Menus[g_MpPlayerNum].cols[colindex].numrows; rowindex++, i++) {
		struct menuitem *item = &dialogdef->items[g_Menus[g_MpPlayerNum].rows[rowindex].itemindex];

		if (menuIsItemFocusable(item, dialog, 1)) {
			result = item;

			if (y >= targety) {
				done = true;
			}

			*rowindexptr = rowindex;
		}

		y = y + g_Menus[g_MpPlayerNum].rows[rowindex].height;
	}

	return result;
}

struct menuitem *dialogFindFirstItem(struct menudialog *dialog)
{
	s32 i;
	s32 colindex = dialog->colstart;
	s32 rowindex;

	for (i = 0; i < dialog->numcols; i++) {
		struct menuitem *item = dialogFindItemAtColY(0, colindex, dialog->definition, &rowindex, dialog);

		if (item != NULL) {
			return item;
		}

		colindex++;
	}

	menuResolveDialogTitle(dialog->definition);

	return dialog->definition->items;
}

struct menuitem *dialogFindFirstItemRight(struct menudialog *dialog)
{
	s32 i;
	s32 colindex = dialog->colstart + dialog->numcols - 1;
	s32 rowindex;

	for (i = 0; i < dialog->numcols; i++) {
		struct menuitem *item = dialogFindItemAtColY(0, colindex, dialog->definition, &rowindex, dialog);

		if (item != NULL) {
			return item;
		}

		colindex--;
	}

	menuResolveDialogTitle(dialog->definition);

	return dialog->definition->items;
}

void dialogChangeItemFocusVertically(struct menudialog *dialog, s32 updown)
{
	s32 rowindex;
	s32 colindex;
	bool done = false;
	s32 startrowindex;
	struct menuitem *item;
	s32 start;
	s32 end;

	dialogFindItem(dialog, dialog->focuseditem, &rowindex, &colindex);

	startrowindex = rowindex;

	while (!done) {
		rowindex += updown;
		start = g_Menus[g_MpPlayerNum].cols[colindex].rowstart;
		end = g_Menus[g_MpPlayerNum].cols[colindex].numrows + start;

		if (rowindex >= end) {
			rowindex = start;
		}

		if (rowindex < start) {
			rowindex = end - 1;
		}

		item = &dialog->definition->items[g_Menus[g_MpPlayerNum].rows[rowindex].itemindex];

		if (menuIsItemFocusable(item, dialog, updown)) {
			done = true;
		}

		if (rowindex == startrowindex) {
			done = true;
		}
	}

	dialog->focuseditem = item;
}

s32 dialogChangeItemFocusHorizontally(struct menudialog *dialog, s32 leftright)
{
	s32 rowindex;
	s32 colindex;
	bool done = false;
	s32 swipedir = 0;
	s32 y = dialogFindItem(dialog, dialog->focuseditem, &rowindex, &colindex);
	s32 startcolindex = colindex;
	struct menuitem *item;

	while (!done) {
		colindex += leftright;

		if (colindex >= dialog->colstart + dialog->numcols) {
			swipedir = 1;
			colindex = dialog->colstart;
		}

		if (colindex < dialog->colstart) {
			swipedir = -1;
			colindex = dialog->colstart + dialog->numcols - 1;
		}

		item = dialogFindItemAtColY(y, colindex, dialog->definition, &rowindex, dialog);

		if (item) {
			done = true;
		}

		if (colindex == startcolindex) {
			done = true;
		}
	}

	if (item) {
		dialog->focuseditem = item;
	}

	return swipedir;
}

s32 dialogChangeItemFocus(struct menudialog *dialog, s32 leftright, s32 updown)
{
	s32 swipedir = 0;

	if (leftright == 0 && updown == 0) {
		return 0;
	}

	if (updown != 0) {
		dialogChangeItemFocusVertically(dialog, updown);
	}

	if (leftright != 0) {
		swipedir = dialogChangeItemFocusHorizontally(dialog, leftright);
	}

	if (dialog->focuseditem != 0) {
		if (dialog->focuseditem->handler != NULL) {
			if ((dialog->focuseditem->flags & MENUITEMFLAG_00000004) == 0) {
				union handlerdata data;
				dialog->focuseditem->handler(MENUOP_FOCUS, dialog->focuseditem, &data);
			}
		}
	}

	return swipedir;
}

void menuOpenDialog(struct menudialogdef *dialogdef, struct menudialog *dialog, struct menu *menu)
{
	union handlerdata data3;
	struct menuitem *item;
	union handlerdata data1;
	union handlerdata data2;

	dialog->definition = dialogdef;

	switch (g_MenuData.root) {
	case MENUROOT_MPSETUP:
	case MENUROOT_4MBMAINMENU:
		dialog->unk6e = 1;
		break;
	case MENUROOT_MAINMENU:
	case MENUROOT_TRAINING:
	default:
		dialog->unk6e = 0;
		break;
	}

	func0f0f1d6c(dialogdef, dialog, menu);
	dialogInitItems(dialog);

	dialog->type = dialogdef->type;
	dialog->transitionfrac = -1;
	dialog->redrawtimer = 0;
	dialog->unk4c = random() * (1.0f / U32_MAX) * M_TAU;

	g_Menus[g_MpPlayerNum].curdialog->state = MENUDIALOGSTATE_PREOPEN;
	g_Menus[g_MpPlayerNum].curdialog->statefrac = 0;

	dialog->unk54 = 0;
	dialog->unk58 = 0;
	dialog->unk5c = 0;

	dialog->focuseditem = dialogFindFirstItem(dialog);

	// Check if any items should be focused automatically
	item = dialog->definition->items;

	while (item->type != MENUITEMTYPE_END) {
		if (item->handler
				&& (item->flags & MENUITEMFLAG_00000004) == 0
				&& item->handler(MENUOP_CHECKPREFOCUSED, item, &data1)) {
			dialog->focuseditem = item;
		}

		item++;
	}

	// Run focus handler
	if (dialog->focuseditem
			&& dialog->focuseditem->handler
			&& (dialog->focuseditem->flags & MENUITEMFLAG_00000004) == 0) {
		dialog->focuseditem->handler(MENUOP_FOCUS, dialog->focuseditem, &data2);
	}

	dialog->dimmed = false;
	dialog->scroll = 0;
	dialog->dstscroll = 0;

	if (dialogdef->handler) {
		dialogdef->handler(MENUOP_OPEN, dialogdef, &data3);
	}

	dialogCalculateContentSize(dialogdef, dialog, menu);
	dialogCalculatePosition(dialog);

	dialog->x = dialog->dstx;
	dialog->y = dialog->dsty;
	dialog->width = dialog->dstwidth;
	dialog->height = dialog->dstheight;
}

void menuPushDialog(struct menudialogdef *dialogdef)
{
	if (dialogdef) {
		func0f0f37a4(&g_Menus[g_MpPlayerNum].unk840);

		if (g_Menus[g_MpPlayerNum].depth < 6 && g_Menus[g_MpPlayerNum].numdialogs < ARRAYCOUNT(g_Menus[0].dialogs)) {
			struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth];
			struct menudialogdef *sibling;
			struct menudialog *dialog;

			g_Menus[g_MpPlayerNum].depth++;

			layer->numsiblings = 1;
			layer->cursibling = 0;

			dialog = &g_Menus[g_MpPlayerNum].dialogs[g_Menus[g_MpPlayerNum].numdialogs];
			g_Menus[g_MpPlayerNum].numdialogs++;
			layer->siblings[0] = dialog;
			g_Menus[g_MpPlayerNum].curdialog = dialog;
			dialog->swipedir = 0;

			menuOpenDialog(dialogdef, dialog, &g_Menus[g_MpPlayerNum]);

			dialog->dstx = (viGetWidth() - dialog->width) / 2;
			dialog->dsty = (viGetHeight() - dialog->height) / 2;

			g_Menus[g_MpPlayerNum].fm.unke40_00 = true;
			sibling = dialogdef->nextsibling;

			while (sibling && layer->numsiblings < 5) {
				// If this limit were to be reached, the game would soft lock
				// because sibling is incremented inside the if-statement block.
				if (g_Menus[g_MpPlayerNum].numdialogs < ARRAYCOUNT(g_Menus[0].dialogs)) {
					dialog = &g_Menus[g_MpPlayerNum].dialogs[g_Menus[g_MpPlayerNum].numdialogs];
					g_Menus[g_MpPlayerNum].numdialogs++;

					layer->siblings[layer->numsiblings] = dialog;
					layer->numsiblings++;

					dialog->swipedir = -1;

					menuOpenDialog(sibling, dialog, &g_Menus[g_MpPlayerNum]);

					dialog->dstx = dialog->x = -320;
					dialog->dsty = dialog->y = (viGetHeight() - dialog->height) / 2;
					dialog->type = 0;

					sibling = sibling->nextsibling;
				}
			}

			if (sibling);

			menuPlaySound(MENUSOUND_OPENDIALOG);

			if (dialogdef->type == MENUDIALOGTYPE_DANGER) {
				menuPlaySound(MENUSOUND_ERROR);
			}

			if (dialogdef->type == MENUDIALOGTYPE_SUCCESS) {
				menuPlaySound(MENUSOUND_SUCCESS);
			}
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
bool func0f0f3220(s32 arg0)
{
	bool save = true;
	s32 i;

	if (g_MenuData.unk669[arg0] == 4) {
		s32 prevplayernum = g_MpPlayerNum;

		for (i = 3; i >= 0; i--) {
			if (g_Menus[i].curdialog) {
				g_MpPlayerNum = i;
			}
		}

		if (g_Menus[g_MpPlayerNum].depth >= 2) {
			save = false;
		}

		if (g_Menus[g_MpPlayerNum].curdialog
				&& g_Menus[g_MpPlayerNum].curdialog->definition->type == MENUDIALOGTYPE_DANGER) {
			save = false;

			if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_MpEndscreenChallengeCheatedMenuDialog
					|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_MpEndscreenChallengeFailedMenuDialog) {
				save = true;
			}
		}

		if (save) {
			filemgrSaveOrLoad(&g_GameFileGuid, FILEOP_SAVE_GAME_000, 0);
		}

		g_MpPlayerNum = prevplayernum;
	} else if (g_MenuData.unk669[arg0] < 4) {
		s32 prevplayernum = g_MpPlayerNum;
		g_MpPlayerNum = g_MenuData.unk669[arg0];
		filemgrSaveOrLoad(&g_PlayerConfigsArray[g_MpPlayerNum].fileguid, FILEOP_SAVE_MPPLAYER, g_MpPlayerNum);
		save = true;
		g_MpPlayerNum = prevplayernum;
	}

	if (save) {
		g_MenuData.unk66e--;
	}

	return save;
}
#else
void func0f0f3220(s32 arg0)
{
	s32 i;

	if (g_MenuData.unk669[arg0] == 4) {
		s32 prevplayernum = g_MpPlayerNum;

		for (i = 3; i >= 0; i--) {
			if (g_Menus[i].curdialog) {
				g_MpPlayerNum = i;
			}
		}

		filemgrSaveOrLoad(&g_GameFileGuid, FILEOP_SAVE_GAME_000, 0);

		g_MpPlayerNum = prevplayernum;
	} else if (g_MenuData.unk669[arg0] < 4) {
		s32 prevplayernum = g_MpPlayerNum;
		g_MpPlayerNum = g_MenuData.unk669[arg0];
		filemgrSaveOrLoad(&g_PlayerConfigsArray[g_MpPlayerNum].fileguid, FILEOP_SAVE_MPPLAYER, g_MpPlayerNum);
		g_MpPlayerNum = prevplayernum;
	}

	g_MenuData.unk66e--;
}
#endif

void menuCloseDialog(void)
{
	if (g_Menus[g_MpPlayerNum].depth > 0) {
		union handlerdata data;
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];
		u32 value_prevent = 1; // constant value, but required for match
		s32 i;

		for (i = 0; i < layer->numsiblings; i++) {
			data.dialog1.preventclose = false;

			if (layer->siblings[i]->definition->handler) {
				layer->siblings[i]->definition->handler(MENUOP_CLOSE, layer->siblings[i]->definition, &data);
			}

			if (value_prevent == data.dialog1.preventclose) {
				return;
			}
		}

		for (i = 0; i < layer->numsiblings; i++) {
			g_Menus[g_MpPlayerNum].numdialogs--;
		}

		g_Menus[g_MpPlayerNum].rowend = g_Menus[g_MpPlayerNum].cols[layer->siblings[0]->colstart].rowstart;
		g_Menus[g_MpPlayerNum].colend = layer->siblings[0]->colstart;
		g_Menus[g_MpPlayerNum].blockend = layer->siblings[0]->blockstart;
		g_Menus[g_MpPlayerNum].depth--;

		menuPlaySound(MENUSOUND_0B);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (g_MenuData.unk66e > 0 && g_Menus[g_MpPlayerNum].depth == 0)
#else
	if (g_MenuData.unk66e > 0)
#endif
	{
		s32 value = g_MenuData.unk66e;

		while (value >= 0) {
			func0f0f3220(value);
			value--;
		}
	}

	if (g_Menus[g_MpPlayerNum].depth == 0) {
		g_Menus[g_MpPlayerNum].curdialog = NULL;
	} else {
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];
		g_Menus[g_MpPlayerNum].curdialog = layer->siblings[layer->cursibling];
	}
}

void menuUpdateCurFrame(void)
{
	s32 depth = g_Menus[g_MpPlayerNum].depth;

	if (depth == 0) {
		// No more parent menus - return control to the player
		g_Vars.currentplayer->joybutinhibit = 0xffffffff;
		menuClose();
		g_Menus[g_MpPlayerNum].curdialog = NULL;
	} else {
		// Set up parent menu
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[depth - 1];
		g_Menus[g_MpPlayerNum].curdialog = layer->siblings[layer->cursibling];
	}
}

void menuPopDialog(void)
{
	menuCloseDialog();
	menuUpdateCurFrame();
}

void func0f0f3704(struct menudialogdef *dialogdef)
{
	menuCloseDialog();
	menuPushDialog(dialogdef);
}

void func0f0f372c(struct menu840 *arg0, f32 x, f32 y, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, u8 flags)
{
	arg0->unk5b1_05 = true;

	if (flags & 2) {
		arg0->unk538 = x;
		arg0->unk53c = y;
		arg0->unk540 = arg3;
	}

	if (flags & 4) {
		arg0->unk548 = arg4;
		arg0->unk54c = arg5;
		arg0->unk550 = arg6;
	}

	if (flags & 1) {
		arg0->unk544 = arg7;
	}

	arg0->unk568 = flags;
	arg0->unk564 = 0.0f;
}

void func0f0f37a4(struct menu840 *arg0)
{
	if (arg0->unk010 == 0x4fac5ace) {
		mpClearCurrentChallenge();
	}

	arg0->unk000 = 0;
	arg0->unk00c = 0;
	arg0->unk010 = 0;
	arg0->bodymodeldef = 0;
	arg0->headmodeldef = 0;
	arg0->unk05c = 0;
	arg0->unk05e = 0;
	arg0->unk5b0 = 0;
	arg0->unk5b1_01 = false;
	arg0->unk5b1_02 = false;
	arg0->unk5b1_03 = false;
	arg0->unk5b1_04 = false;
	arg0->unk5b1_05 = false;
	arg0->unk5b1_06 = false;
	arg0->unk5b1_07 = false;
	arg0->partvisibility = NULL;
	arg0->unk560 = -1;
	arg0->headnum = -1;
	arg0->bodynum = -1;
	arg0->unk550 = 0.0f;
	arg0->unk54c = 0.0f;
	arg0->unk548 = 0.0f;
	arg0->unk540 = 0.0f;
	arg0->unk53c = 0.0f;
	arg0->unk538 = 0.0f;
	arg0->unk534 = 0.0f;
	arg0->unk530 = 0.0f;
	arg0->unk52c = 0.0f;
	arg0->unk528 = 0.0f;
	arg0->unk524 = 0.0f;
	arg0->unk520 = 0.0f;
	arg0->unk518 = 0.0f;
	arg0->unk514 = 0.0f;
	arg0->unk510 = 0.0f;
	arg0->unk558 = 0.0f;
	arg0->unk55c = 1.0f;
	arg0->unk51c = 1.0f;
	arg0->unk544 = 1.0f;
	arg0->unk554 = -1.0f;
}

u32 var80071468 = 0x96969600;
u32 var8007146c = 0x96969600;

u32 var80071470 = 0xffffff00;
u32 var80071474 = 0xffffff00;
u32 var80071478 = 0xb24d2e00;
u32 var8007147c = 0x00000000;

u32 var80071480 = 0x00000000;
u32 var80071484 = 0x00000001;
u32 var80071488 = 0x00000003;
u32 var8007148c = 0x00000000;
u32 var80071490 = 0x00000000;
u32 var80071494 = 0x00000000;
u32 var80071498 = 0x00000000;
u32 var8007149c = 0x00000000;
u32 var800714a0 = 0x00000000;
u32 var800714a4 = 0x00000000;
u32 var800714a8 = 0x00000000;
u32 var800714ac = 0x00000000;
u32 var800714b0 = 0x00000000;
u32 var800714b4 = 0x00000000;
u32 var800714b8 = 0x00000000;
u32 var800714bc = 0x00000000;

#if VERSION < VERSION_NTSC_1_0
u32 var80073b6cnb[3] = {0};
#endif

u32 var800714c0 = 0x0000000a;
u32 var800714c4 = 0x0000012c;

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel menuRenderModels
.late_rodata
glabel var7f1b3c1cpf
.word 0x40f33333
glabel var7f1b3c20pf
.word 0x3b1d4952
glabel var7f1b3c24pf
.word 0x3f7f62b7
glabel var7f1b3c28pf
.word 0x3f7f62b7
glabel var7f1b3c2cpf
.word 0x3b1d4952
glabel var7f1b3c30pf
.word 0x3b1d4952
glabel var7f1b3c34pf
.word 0x3b1d4952
glabel var7f1b3c38pf
.word 0x40490fdb
glabel var7f1b3c3cpf
.word 0xbf19999a
glabel var7f1b3c40pf
.word 0x3f19999a
.text
/*  f0f4004:	27bdfbc0 */ 	addiu	$sp,$sp,-1088
/*  f0f4008:	3c02800a */ 	lui	$v0,0x800a
/*  f0f400c:	8c42a9c4 */ 	lw	$v0,-0x563c($v0)
/*  f0f4010:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0f4014:	24010026 */ 	li	$at,0x26
/*  f0f4018:	00a08025 */ 	move	$s0,$a1
/*  f0f401c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f4020:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0f4024:	afa40440 */ 	sw	$a0,0x440($sp)
/*  f0f4028:	1041001d */ 	beq	$v0,$at,.PF0f0f40a0
/*  f0f402c:	afa60448 */ 	sw	$a2,0x448($sp)
/*  f0f4030:	2401005c */ 	li	$at,0x5c
/*  f0f4034:	1041001a */ 	beq	$v0,$at,.PF0f0f40a0
/*  f0f4038:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f403c:	81cf2535 */ 	lb	$t7,0x2535($t6)
/*  f0f4040:	24010001 */ 	li	$at,0x1
/*  f0f4044:	05e30008 */ 	bgezl	$t7,.PF0f0f4068
/*  f0f4048:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0f404c:	10c10005 */ 	beq	$a2,$at,.PF0f0f4064
/*  f0f4050:	28c10003 */ 	slti	$at,$a2,0x3
/*  f0f4054:	50200004 */ 	beqzl	$at,.PF0f0f4068
/*  f0f4058:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0f405c:	100005b5 */ 	b	.PF0f0f5734
/*  f0f4060:	00801025 */ 	move	$v0,$a0
.PF0f0f4064:
/*  f0f4064:	8e190004 */ 	lw	$t9,0x4($s0)
.PF0f0f4068:
/*  f0f4068:	5720000e */ 	bnezl	$t9,.PF0f0f40a4
/*  f0f406c:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0f4070:	0fc278ae */ 	jal	bgun0f09e004
/*  f0f4074:	24040001 */ 	li	$a0,0x1
/*  f0f4078:	10400007 */ 	beqz	$v0,.PF0f0f4098
/*  f0f407c:	00000000 */ 	nop
/*  f0f4080:	0fc27828 */ 	jal	bgunGetGunMem
/*  f0f4084:	00000000 */ 	nop
/*  f0f4088:	0fc2782c */ 	jal	bgunCalculateGunMemCapacity
/*  f0f408c:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0f4090:	10000003 */ 	b	.PF0f0f40a0
/*  f0f4094:	ae020008 */ 	sw	$v0,0x8($s0)
.PF0f0f4098:
/*  f0f4098:	100005a6 */ 	b	.PF0f0f5734
/*  f0f409c:	8fa20440 */ 	lw	$v0,0x440($sp)
.PF0f0f40a0:
/*  f0f40a0:	8e090004 */ 	lw	$t1,0x4($s0)
.PF0f0f40a4:
/*  f0f40a4:	55200004 */ 	bnezl	$t1,.PF0f0f40b8
/*  f0f40a8:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f40ac:	100005a1 */ 	b	.PF0f0f5734
/*  f0f40b0:	8fa20440 */ 	lw	$v0,0x440($sp)
/*  f0f40b4:	8e02000c */ 	lw	$v0,0xc($s0)
.PF0f0f40b8:
/*  f0f40b8:	504000dc */ 	beqzl	$v0,.PF0f0f442c
/*  f0f40bc:	8e0c0054 */ 	lw	$t4,0x54($s0)
/*  f0f40c0:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0f40c4:	3c014fac */ 	lui	$at,0x4fac
/*  f0f40c8:	34215ace */ 	ori	$at,$at,0x5ace
/*  f0f40cc:	14620004 */ 	bne	$v1,$v0,.PF0f0f40e0
/*  f0f40d0:	00000000 */ 	nop
/*  f0f40d4:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0f40d8:	100000d3 */ 	b	.PF0f0f4428
/*  f0f40dc:	a2000000 */ 	sb	$zero,0x0($s0)
.PF0f0f40e0:
/*  f0f40e0:	54610004 */ 	bnel	$v1,$at,.PF0f0f40f4
/*  f0f40e4:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0f40e8:	0fc674da */ 	jal	mpClearCurrentChallenge
/*  f0f40ec:	00000000 */ 	nop
/*  f0f40f0:	92020000 */ 	lbu	$v0,0x0($s0)
.PF0f0f40f4:
/*  f0f40f4:	240a0001 */ 	li	$t2,0x1
/*  f0f40f8:	14400004 */ 	bnez	$v0,.PF0f0f410c
/*  f0f40fc:	244bffff */ 	addiu	$t3,$v0,-1
/*  f0f4100:	a20a0000 */ 	sb	$t2,0x0($s0)
/*  f0f4104:	1000058b */ 	b	.PF0f0f5734
/*  f0f4108:	8fa20440 */ 	lw	$v0,0x440($sp)
.PF0f0f410c:
/*  f0f410c:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f0f4110:	158000c3 */ 	bnez	$t4,.PF0f0f4420
/*  f0f4114:	a20b0000 */ 	sb	$t3,0x0($s0)
/*  f0f4118:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f411c:	3401ffff */ 	li	$at,0xffff
/*  f0f4120:	304dffff */ 	andi	$t5,$v0,0xffff
/*  f0f4124:	11a10002 */ 	beq	$t5,$at,.PF0f0f4130
/*  f0f4128:	00027000 */ 	sll	$t6,$v0,0x0
/*  f0f412c:	05c10092 */ 	bgez	$t6,.PF0f0f4378
.PF0f0f4130:
/*  f0f4130:	00027800 */ 	sll	$t7,$v0,0x0
/*  f0f4134:	05e10008 */ 	bgez	$t7,.PF0f0f4158
/*  f0f4138:	3c01000f */ 	lui	$at,0xf
/*  f0f413c:	3421fc00 */ 	ori	$at,$at,0xfc00
/*  f0f4140:	0041c824 */ 	and	$t9,$v0,$at
/*  f0f4144:	305803ff */ 	andi	$t8,$v0,0x3ff
/*  f0f4148:	00194a82 */ 	srl	$t1,$t9,0xa
/*  f0f414c:	afb80400 */ 	sw	$t8,0x400($sp)
/*  f0f4150:	1000001a */ 	b	.PF0f0f41bc
/*  f0f4154:	afa90404 */ 	sw	$t1,0x404($sp)
.PF0f0f4158:
/*  f0f4158:	00028c02 */ 	srl	$s1,$v0,0x10
/*  f0f415c:	322a00ff */ 	andi	$t2,$s1,0xff
/*  f0f4160:	00025e02 */ 	srl	$t3,$v0,0x18
/*  f0f4164:	01408825 */ 	move	$s1,$t2
/*  f0f4168:	0fc6330d */ 	jal	mpGetBodyId
/*  f0f416c:	316400ff */ 	andi	$a0,$t3,0xff
/*  f0f4170:	0fc632f0 */ 	jal	mpGetNumHeads2
/*  f0f4174:	afa20404 */ 	sw	$v0,0x404($sp)
/*  f0f4178:	0222082a */ 	slt	$at,$s1,$v0
/*  f0f417c:	10200005 */ 	beqz	$at,.PF0f0f4194
/*  f0f4180:	00000000 */ 	nop
/*  f0f4184:	0fc632f4 */ 	jal	mpGetHeadId
/*  f0f4188:	322400ff */ 	andi	$a0,$s1,0xff
/*  f0f418c:	1000000b */ 	b	.PF0f0f41bc
/*  f0f4190:	afa20400 */ 	sw	$v0,0x400($sp)
.PF0f0f4194:
/*  f0f4194:	0fc632f0 */ 	jal	mpGetNumHeads2
/*  f0f4198:	00000000 */ 	nop
/*  f0f419c:	0fc52daa */ 	jal	func0f14a9f8
/*  f0f41a0:	02222023 */ 	subu	$a0,$s1,$v0
/*  f0f41a4:	0fc63302 */ 	jal	mpGetBeauHeadId
/*  f0f41a8:	304400ff */ 	andi	$a0,$v0,0xff
/*  f0f41ac:	0fc632f0 */ 	jal	mpGetNumHeads2
/*  f0f41b0:	afa20400 */ 	sw	$v0,0x400($sp)
/*  f0f41b4:	02226823 */ 	subu	$t5,$s1,$v0
/*  f0f41b8:	a20d05b0 */ 	sb	$t5,0x5b0($s0)
.PF0f0f41bc:
/*  f0f41bc:	8fae0404 */ 	lw	$t6,0x404($sp)
/*  f0f41c0:	3c188008 */ 	lui	$t8,0x8008
/*  f0f41c4:	2718d3d4 */ 	addiu	$t8,$t8,-11308
/*  f0f41c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f41cc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f41d0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f41d4:	01f88821 */ 	addu	$s1,$t7,$t8
/*  f0f41d8:	96220002 */ 	lhu	$v0,0x2($s1)
/*  f0f41dc:	00402025 */ 	move	$a0,$v0
/*  f0f41e0:	a7a2040a */ 	sh	$v0,0x40a($sp)
/*  f0f41e4:	0fc59ff5 */ 	jal	fileGetInflatedLength
/*  f0f41e8:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f0f41ec:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f0f41f0:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f41f4:	3479003f */ 	ori	$t9,$v1,0x3f
/*  f0f41f8:	000a6040 */ 	sll	$t4,$t2,0x1
/*  f0f41fc:	05810005 */ 	bgez	$t4,.PF0f0f4214
/*  f0f4200:	3b23003f */ 	xori	$v1,$t9,0x3f
/*  f0f4204:	240dffff */ 	li	$t5,-1
/*  f0f4208:	afad0400 */ 	sw	$t5,0x400($sp)
/*  f0f420c:	10000011 */ 	b	.PF0f0f4254
/*  f0f4210:	3411ffff */ 	li	$s1,0xffff
.PF0f0f4214:
/*  f0f4214:	8fae0400 */ 	lw	$t6,0x400($sp)
/*  f0f4218:	3c118008 */ 	lui	$s1,0x8008
/*  f0f421c:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f4220:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f4224:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f4228:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f422c:	022f8821 */ 	addu	$s1,$s1,$t7
/*  f0f4230:	9631d3d6 */ 	lhu	$s1,-0x2c2a($s1)
/*  f0f4234:	0fc59ff5 */ 	jal	fileGetInflatedLength
/*  f0f4238:	02202025 */ 	move	$a0,$s1
/*  f0f423c:	8fb80420 */ 	lw	$t8,0x420($sp)
/*  f0f4240:	2459003f */ 	addiu	$t9,$v0,0x3f
/*  f0f4244:	3729003f */ 	ori	$t1,$t9,0x3f
/*  f0f4248:	392a003f */ 	xori	$t2,$t1,0x3f
/*  f0f424c:	030a1821 */ 	addu	$v1,$t8,$t2
/*  f0f4250:	afa30420 */ 	sw	$v1,0x420($sp)
.PF0f0f4254:
/*  f0f4254:	8e0c0004 */ 	lw	$t4,0x4($s0)
/*  f0f4258:	8e0d0008 */ 	lw	$t5,0x8($s0)
/*  f0f425c:	24634000 */ 	addiu	$v1,$v1,0x4000
/*  f0f4260:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f4264:	27a40410 */ 	addiu	$a0,$sp,0x410
/*  f0f4268:	01832821 */ 	addu	$a1,$t4,$v1
/*  f0f426c:	0fc5cfa8 */ 	jal	func0f172e70
/*  f0f4270:	01a33023 */ 	subu	$a2,$t5,$v1
/*  f0f4274:	8fae0400 */ 	lw	$t6,0x400($sp)
/*  f0f4278:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f0f427c:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f4280:	a60e0002 */ 	sh	$t6,0x2($s0)
/*  f0f4284:	8faf0404 */ 	lw	$t7,0x404($sp)
/*  f0f4288:	a60f056a */ 	sh	$t7,0x56a($s0)
/*  f0f428c:	8fa60420 */ 	lw	$a2,0x420($sp)
/*  f0f4290:	0fc6a265 */ 	jal	func0f1a7794
/*  f0f4294:	97a4040a */ 	lhu	$a0,0x40a($sp)
/*  f0f4298:	ae020054 */ 	sw	$v0,0x54($s0)
/*  f0f429c:	0fc5a080 */ 	jal	fileGetSize
/*  f0f42a0:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f42a4:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f42a8:	3479003f */ 	ori	$t9,$v1,0x3f
/*  f0f42ac:	3b29003f */ 	xori	$t1,$t9,0x3f
/*  f0f42b0:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f42b4:	0c00898a */ 	jal	modelCalculateRwDataLen
/*  f0f42b8:	afa9040c */ 	sw	$t1,0x40c($sp)
/*  f0f42bc:	8fb80400 */ 	lw	$t8,0x400($sp)
/*  f0f42c0:	8fa3040c */ 	lw	$v1,0x40c($sp)
/*  f0f42c4:	3224ffff */ 	andi	$a0,$s1,0xffff
/*  f0f42c8:	07010003 */ 	bgez	$t8,.PF0f0f42d8
/*  f0f42cc:	8fab0420 */ 	lw	$t3,0x420($sp)
/*  f0f42d0:	10000010 */ 	b	.PF0f0f4314
/*  f0f42d4:	ae000058 */ 	sw	$zero,0x58($s0)
.PF0f0f42d8:
/*  f0f42d8:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f0f42dc:	afb10040 */ 	sw	$s1,0x40($sp)
/*  f0f42e0:	01633023 */ 	subu	$a2,$t3,$v1
/*  f0f42e4:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f42e8:	0fc6a265 */ 	jal	func0f1a7794
/*  f0f42ec:	01432821 */ 	addu	$a1,$t2,$v1
/*  f0f42f0:	ae020058 */ 	sw	$v0,0x58($s0)
/*  f0f42f4:	0fc5a080 */ 	jal	fileGetSize
/*  f0f42f8:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f42fc:	8e040058 */ 	lw	$a0,0x58($s0)
/*  f0f4300:	8fa50400 */ 	lw	$a1,0x400($sp)
/*  f0f4304:	0fc0b7b7 */ 	jal	bodyCalculateHeadOffset
/*  f0f4308:	8fa60404 */ 	lw	$a2,0x404($sp)
/*  f0f430c:	0c00898a */ 	jal	modelCalculateRwDataLen
/*  f0f4310:	8e040058 */ 	lw	$a0,0x58($s0)
.PF0f0f4314:
/*  f0f4314:	26040060 */ 	addiu	$a0,$s0,0x60
/*  f0f4318:	8e050054 */ 	lw	$a1,0x54($s0)
/*  f0f431c:	afa4003c */ 	sw	$a0,0x3c($sp)
/*  f0f4320:	26060110 */ 	addiu	$a2,$s0,0x110
/*  f0f4324:	0c008a2a */ 	jal	modelInit
/*  f0f4328:	24070001 */ 	li	$a3,0x1
/*  f0f432c:	26110084 */ 	addiu	$s1,$s0,0x84
/*  f0f4330:	0c008a69 */ 	jal	animInit
/*  f0f4334:	02202025 */ 	move	$a0,$s1
/*  f0f4338:	240c0100 */ 	li	$t4,0x100
/*  f0f433c:	a60c0062 */ 	sh	$t4,0x62($s0)
/*  f0f4340:	ae110080 */ 	sw	$s1,0x80($s0)
/*  f0f4344:	8e060054 */ 	lw	$a2,0x54($s0)
/*  f0f4348:	8e070058 */ 	lw	$a3,0x58($s0)
/*  f0f434c:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f0f4350:	240e0001 */ 	li	$t6,0x1
/*  f0f4354:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0f4358:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f435c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0f4360:	8fa50400 */ 	lw	$a1,0x400($sp)
/*  f0f4364:	8fa40404 */ 	lw	$a0,0x404($sp)
/*  f0f4368:	0fc0b3eb */ 	jal	func0f02ce8c
/*  f0f436c:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0f4370:	10000027 */ 	b	.PF0f0f4410
/*  f0f4374:	8e0b000c */ 	lw	$t3,0xc($s0)
.PF0f0f4378:
/*  f0f4378:	0fc59ff5 */ 	jal	fileGetInflatedLength
/*  f0f437c:	00402025 */ 	move	$a0,$v0
/*  f0f4380:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f4384:	346f003f */ 	ori	$t7,$v1,0x3f
/*  f0f4388:	39f9003f */ 	xori	$t9,$t7,0x3f
/*  f0f438c:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0f4390:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f0f4394:	27234000 */ 	addiu	$v1,$t9,0x4000
/*  f0f4398:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f439c:	27a40410 */ 	addiu	$a0,$sp,0x410
/*  f0f43a0:	01232821 */ 	addu	$a1,$t1,$v1
/*  f0f43a4:	0fc5cfa8 */ 	jal	func0f172e70
/*  f0f43a8:	03033023 */ 	subu	$a2,$t8,$v1
/*  f0f43ac:	2402ffff */ 	li	$v0,-1
/*  f0f43b0:	a6020002 */ 	sh	$v0,0x2($s0)
/*  f0f43b4:	a602056a */ 	sh	$v0,0x56a($s0)
/*  f0f43b8:	8fa60420 */ 	lw	$a2,0x420($sp)
/*  f0f43bc:	9604000e */ 	lhu	$a0,0xe($s0)
/*  f0f43c0:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f0f43c4:	0fc6a265 */ 	jal	func0f1a7794
/*  f0f43c8:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f43cc:	ae020054 */ 	sw	$v0,0x54($s0)
/*  f0f43d0:	0fc5a080 */ 	jal	fileGetSize
/*  f0f43d4:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f0f43d8:	0c00898a */ 	jal	modelCalculateRwDataLen
/*  f0f43dc:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f43e0:	26040060 */ 	addiu	$a0,$s0,0x60
/*  f0f43e4:	8e050054 */ 	lw	$a1,0x54($s0)
/*  f0f43e8:	26060110 */ 	addiu	$a2,$s0,0x110
/*  f0f43ec:	0c008a2a */ 	jal	modelInit
/*  f0f43f0:	24070001 */ 	li	$a3,0x1
/*  f0f43f4:	26110084 */ 	addiu	$s1,$s0,0x84
/*  f0f43f8:	0c008a69 */ 	jal	animInit
/*  f0f43fc:	02202025 */ 	move	$a0,$s1
/*  f0f4400:	240a0100 */ 	li	$t2,0x100
/*  f0f4404:	a60a0062 */ 	sh	$t2,0x62($s0)
/*  f0f4408:	ae110080 */ 	sw	$s1,0x80($s0)
/*  f0f440c:	8e0b000c */ 	lw	$t3,0xc($s0)
.PF0f0f4410:
/*  f0f4410:	a600005e */ 	sh	$zero,0x5e($s0)
/*  f0f4414:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0f4418:	10000003 */ 	b	.PF0f0f4428
/*  f0f441c:	ae0b0010 */ 	sw	$t3,0x10($s0)
.PF0f0f4420:
/*  f0f4420:	100004c4 */ 	b	.PF0f0f5734
/*  f0f4424:	8fa20440 */ 	lw	$v0,0x440($sp)
.PF0f0f4428:
/*  f0f4428:	8e0c0054 */ 	lw	$t4,0x54($s0)
.PF0f0f442c:
/*  f0f442c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f4430:	25ce1760 */ 	addiu	$t6,$t6,0x1760
/*  f0f4434:	118004be */ 	beqz	$t4,.PF0f0f5730
/*  f0f4438:	27ad03b8 */ 	addiu	$t5,$sp,0x3b8
/*  f0f443c:	25d9003c */ 	addiu	$t9,$t6,0x3c
.PF0f0f4440:
/*  f0f4440:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0f4444:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f0f4448:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f0f444c:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f0f4450:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f0f4454:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f0f4458:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f0f445c:	15d9fff8 */ 	bne	$t6,$t9,.PF0f0f4440
/*  f0f4460:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f0f4464:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0f4468:	26090060 */ 	addiu	$t1,$s0,0x60
/*  f0f446c:	ada10000 */ 	sw	$at,0x0($t5)
/*  f0f4470:	8fb80448 */ 	lw	$t8,0x448($sp)
/*  f0f4474:	afa9003c */ 	sw	$t1,0x3c($sp)
/*  f0f4478:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0f447c:	1020001b */ 	beqz	$at,.PF0f0f44ec
/*  f0f4480:	3c0a800a */ 	lui	$t2,0x800a
/*  f0f4484:	8d4a2534 */ 	lw	$t2,0x2534($t2)
/*  f0f4488:	000a6280 */ 	sll	$t4,$t2,0xa
/*  f0f448c:	05830018 */ 	bgezl	$t4,.PF0f0f44f0
/*  f0f4490:	8faa0440 */ 	lw	$t2,0x440($sp)
/*  f0f4494:	0c002bf1 */ 	jal	vi0000b280
/*  f0f4498:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f449c:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f44a0:	0c002bc5 */ 	jal	vi0000b1d0
/*  f0f44a4:	00402025 */ 	move	$a0,$v0
/*  f0f44a8:	3c0f800a */ 	lui	$t7,0x800a
/*  f0f44ac:	91ef2535 */ 	lbu	$t7,0x2535($t7)
/*  f0f44b0:	8fae0448 */ 	lw	$t6,0x448($sp)
/*  f0f44b4:	3c01800a */ 	lui	$at,0x800a
/*  f0f44b8:	31f9ffdf */ 	andi	$t9,$t7,0xffdf
/*  f0f44bc:	a0392535 */ 	sb	$t9,0x2535($at)
/*  f0f44c0:	24010002 */ 	li	$at,0x2
/*  f0f44c4:	11c10003 */ 	beq	$t6,$at,.PF0f0f44d4
/*  f0f44c8:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f44cc:	0fc3d610 */ 	jal	menuApplyScissor
/*  f0f44d0:	00402025 */ 	move	$a0,$v0
.PF0f0f44d4:
/*  f0f44d4:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f0f44d8:	afad0440 */ 	sw	$t5,0x440($sp)
/*  f0f44dc:	3c09b700 */ 	lui	$t1,0xb700
/*  f0f44e0:	24180001 */ 	li	$t8,0x1
/*  f0f44e4:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0f44e8:	ac490000 */ 	sw	$t1,0x0($v0)
.PF0f0f44ec:
/*  f0f44ec:	8faa0440 */ 	lw	$t2,0x440($sp)
.PF0f0f44f0:
/*  f0f44f0:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0f44f4:	25ef1050 */ 	addiu	$t7,$t7,0x1050
/*  f0f44f8:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0f44fc:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f4500:	3c0c0600 */ 	lui	$t4,0x600
/*  f0f4504:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0f4508:	ad4f0004 */ 	sw	$t7,0x4($t2)
/*  f0f450c:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f4510:	3c0d0600 */ 	lui	$t5,0x600
/*  f0f4514:	3c098006 */ 	lui	$t1,0x8006
/*  f0f4518:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0f451c:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f4520:	25291070 */ 	addiu	$t1,$t1,0x1070
/*  f0f4524:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f4528:	afa90038 */ 	sw	$t1,0x38($sp)
/*  f0f452c:	af290004 */ 	sw	$t1,0x4($t9)
/*  f0f4530:	afa00308 */ 	sw	$zero,0x308($sp)
/*  f0f4534:	c6060554 */ 	lwc1	$f6,0x554($s0)
/*  f0f4538:	44802000 */ 	mtc1	$zero,$f4
/*  f0f453c:	00000000 */ 	nop
/*  f0f4540:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0f4544:	00000000 */ 	nop
/*  f0f4548:	4500005c */ 	bc1f	.PF0f0f46bc
/*  f0f454c:	24180001 */ 	li	$t8,0x1
/*  f0f4550:	afb802f4 */ 	sw	$t8,0x2f4($sp)
/*  f0f4554:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4558:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0f455c:	254ad310 */ 	addiu	$t2,$t2,-11504
/*  f0f4560:	8c8b0004 */ 	lw	$t3,0x4($a0)
/*  f0f4564:	554b002f */ 	bnel	$t2,$t3,.PF0f0f4624
/*  f0f4568:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f0f456c:	0c0069ab */ 	jal	modelGetPart
/*  f0f4570:	24050006 */ 	li	$a1,0x6
/*  f0f4574:	5040002b */ 	beqzl	$v0,.PF0f0f4624
/*  f0f4578:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f0f457c:	8e0c0574 */ 	lw	$t4,0x574($s0)
/*  f0f4580:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0f4584:	44818000 */ 	mtc1	$at,$f16
/*  f0f4588:	448c4000 */ 	mtc1	$t4,$f8
/*  f0f458c:	8c510004 */ 	lw	$s1,0x4($v0)
/*  f0f4590:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0f4594:	0fc01af0 */ 	jal	func0f006bd0
/*  f0f4598:	46105303 */ 	div.s	$f12,$f10,$f16
/*  f0f459c:	44806000 */ 	mtc1	$zero,$f12
/*  f0f45a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f45a4:	44817000 */ 	mtc1	$at,$f14
/*  f0f45a8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f45ac:	e7ac02fc */ 	swc1	$f12,0x2fc($sp)
/*  f0f45b0:	c6320004 */ 	lwc1	$f18,0x4($s1)
/*  f0f45b4:	c4243c1c */ 	lwc1	$f4,0x3c1c($at)
/*  f0f45b8:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f0f45bc:	3c014387 */ 	lui	$at,0x4387
/*  f0f45c0:	240f0001 */ 	li	$t7,0x1
/*  f0f45c4:	afaf0308 */ 	sw	$t7,0x308($sp)
/*  f0f45c8:	e7ac0304 */ 	swc1	$f12,0x304($sp)
/*  f0f45cc:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f0f45d0:	46087281 */ 	sub.s	$f10,$f14,$f8
/*  f0f45d4:	44814000 */ 	mtc1	$at,$f8
/*  f0f45d8:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0f45dc:	46007101 */ 	sub.s	$f4,$f14,$f0
/*  f0f45e0:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0f45e4:	44815000 */ 	mtc1	$at,$f10
/*  f0f45e8:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f45ec:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0f45f0:	46106481 */ 	sub.s	$f18,$f12,$f16
/*  f0f45f4:	460a3080 */ 	add.s	$f2,$f6,$f10
/*  f0f45f8:	e7b20300 */ 	swc1	$f18,0x300($sp)
/*  f0f45fc:	44819000 */ 	mtc1	$at,$f18
/*  f0f4600:	e6020554 */ 	swc1	$f2,0x554($s0)
/*  f0f4604:	c6300004 */ 	lwc1	$f16,0x4($s1)
/*  f0f4608:	afa002f4 */ 	sw	$zero,0x2f4($sp)
/*  f0f460c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4610:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0f4614:	46041203 */ 	div.s	$f8,$f2,$f4
/*  f0f4618:	0fc1a34e */ 	jal	modelFindBboxRodata
/*  f0f461c:	e7a802f8 */ 	swc1	$f8,0x2f8($sp)
/*  f0f4620:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
.PF0f0f4624:
/*  f0f4624:	13200025 */ 	beqz	$t9,.PF0f0f46bc
/*  f0f4628:	00000000 */ 	nop
/*  f0f462c:	0fc1a34e */ 	jal	modelFindBboxRodata
/*  f0f4630:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4634:	10400021 */ 	beqz	$v0,.PF0f0f46bc
/*  f0f4638:	00000000 */ 	nop
/*  f0f463c:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0f4640:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f0f4644:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f4648:	44817000 */ 	mtc1	$at,$f14
/*  f0f464c:	46060281 */ 	sub.s	$f10,$f0,$f6
/*  f0f4650:	240e0001 */ 	li	$t6,0x1
/*  f0f4654:	460e5402 */ 	mul.s	$f16,$f10,$f14
/*  f0f4658:	46100481 */ 	sub.s	$f18,$f0,$f16
/*  f0f465c:	46009107 */ 	neg.s	$f4,$f18
/*  f0f4660:	e7a402fc */ 	swc1	$f4,0x2fc($sp)
/*  f0f4664:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0f4668:	c4420010 */ 	lwc1	$f2,0x10($v0)
/*  f0f466c:	46081181 */ 	sub.s	$f6,$f2,$f8
/*  f0f4670:	460e3282 */ 	mul.s	$f10,$f6,$f14
/*  f0f4674:	460a1401 */ 	sub.s	$f16,$f2,$f10
/*  f0f4678:	46008487 */ 	neg.s	$f18,$f16
/*  f0f467c:	e7b20300 */ 	swc1	$f18,0x300($sp)
/*  f0f4680:	c4440014 */ 	lwc1	$f4,0x14($v0)
/*  f0f4684:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f0f4688:	afae0308 */ 	sw	$t6,0x308($sp)
/*  f0f468c:	46046201 */ 	sub.s	$f8,$f12,$f4
/*  f0f4690:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f0f4694:	46066281 */ 	sub.s	$f10,$f12,$f6
/*  f0f4698:	46005407 */ 	neg.s	$f16,$f10
/*  f0f469c:	e7b00304 */ 	swc1	$f16,0x304($sp)
/*  f0f46a0:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f0f46a4:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f0f46a8:	c60a0554 */ 	lwc1	$f10,0x554($s0)
/*  f0f46ac:	46049201 */ 	sub.s	$f8,$f18,$f4
/*  f0f46b0:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f0f46b4:	46065403 */ 	div.s	$f16,$f10,$f6
/*  f0f46b8:	e7b002f8 */ 	swc1	$f16,0x2f8($sp)
.PF0f0f46bc:
/*  f0f46bc:	0c0055d0 */ 	jal	mtx4LoadIdentity
/*  f0f46c0:	27a40350 */ 	addiu	$a0,$sp,0x350
/*  f0f46c4:	8fad0448 */ 	lw	$t5,0x448($sp)
/*  f0f46c8:	24010001 */ 	li	$at,0x1
/*  f0f46cc:	15a1007d */ 	bne	$t5,$at,.PF0f0f48c4
/*  f0f46d0:	3c098009 */ 	lui	$t1,0x8009
/*  f0f46d4:	91291040 */ 	lbu	$t1,0x1040($t1)
/*  f0f46d8:	24010001 */ 	li	$at,0x1
/*  f0f46dc:	5121012c */ 	beql	$t1,$at,.PF0f0f4b90
/*  f0f46e0:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f0f46e4:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f46e8:	c6120510 */ 	lwc1	$f18,0x510($s0)
/*  f0f46ec:	3c03800a */ 	lui	$v1,0x800a
/*  f0f46f0:	2463a510 */ 	addiu	$v1,$v1,-23280
/*  f0f46f4:	46120032 */ 	c.eq.s	$f0,$f18
/*  f0f46f8:	00000000 */ 	nop
/*  f0f46fc:	45030014 */ 	bc1tl	.PF0f0f4750
/*  f0f4700:	c60c053c */ 	lwc1	$f12,0x53c($s0)
/*  f0f4704:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0f4708:	00001025 */ 	move	$v0,$zero
/*  f0f470c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f4710:	5b00000f */ 	blezl	$t8,.PF0f0f4750
/*  f0f4714:	c60c053c */ 	lwc1	$f12,0x53c($s0)
/*  f0f4718:	c4243c20 */ 	lwc1	$f4,0x3c20($at)
/*  f0f471c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f4720:	46040082 */ 	mul.s	$f2,$f0,$f4
/*  f0f4724:	c4203c24 */ 	lwc1	$f0,0x3c24($at)
/*  f0f4728:	c6080510 */ 	lwc1	$f8,0x510($s0)
.PF0f0f472c:
/*  f0f472c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f4730:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0f4734:	460a1180 */ 	add.s	$f6,$f2,$f10
/*  f0f4738:	e6060510 */ 	swc1	$f6,0x510($s0)
/*  f0f473c:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0f4740:	004a082a */ 	slt	$at,$v0,$t2
/*  f0f4744:	5420fff9 */ 	bnezl	$at,.PF0f0f472c
/*  f0f4748:	c6080510 */ 	lwc1	$f8,0x510($s0)
/*  f0f474c:	c60c053c */ 	lwc1	$f12,0x53c($s0)
.PF0f0f4750:
/*  f0f4750:	c6100514 */ 	lwc1	$f16,0x514($s0)
/*  f0f4754:	3c03800a */ 	lui	$v1,0x800a
/*  f0f4758:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f475c:	46106032 */ 	c.eq.s	$f12,$f16
/*  f0f4760:	c4203c28 */ 	lwc1	$f0,0x3c28($at)
/*  f0f4764:	2463a510 */ 	addiu	$v1,$v1,-23280
/*  f0f4768:	45030013 */ 	bc1tl	.PF0f0f47b8
/*  f0f476c:	c60c0540 */ 	lwc1	$f12,0x540($s0)
/*  f0f4770:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f0f4774:	00001025 */ 	move	$v0,$zero
/*  f0f4778:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f477c:	5960000e */ 	blezl	$t3,.PF0f0f47b8
/*  f0f4780:	c60c0540 */ 	lwc1	$f12,0x540($s0)
/*  f0f4784:	c4323c2c */ 	lwc1	$f18,0x3c2c($at)
/*  f0f4788:	46126082 */ 	mul.s	$f2,$f12,$f18
/*  f0f478c:	00000000 */ 	nop
/*  f0f4790:	c6040514 */ 	lwc1	$f4,0x514($s0)
.PF0f0f4794:
/*  f0f4794:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f4798:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f0f479c:	46081280 */ 	add.s	$f10,$f2,$f8
/*  f0f47a0:	e60a0514 */ 	swc1	$f10,0x514($s0)
/*  f0f47a4:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f47a8:	004c082a */ 	slt	$at,$v0,$t4
/*  f0f47ac:	5420fff9 */ 	bnezl	$at,.PF0f0f4794
/*  f0f47b0:	c6040514 */ 	lwc1	$f4,0x514($s0)
/*  f0f47b4:	c60c0540 */ 	lwc1	$f12,0x540($s0)
.PF0f0f47b8:
/*  f0f47b8:	c6060518 */ 	lwc1	$f6,0x518($s0)
/*  f0f47bc:	46066032 */ 	c.eq.s	$f12,$f6
/*  f0f47c0:	00000000 */ 	nop
/*  f0f47c4:	45030013 */ 	bc1tl	.PF0f0f4814
/*  f0f47c8:	c60c0544 */ 	lwc1	$f12,0x544($s0)
/*  f0f47cc:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0f47d0:	00001025 */ 	move	$v0,$zero
/*  f0f47d4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f47d8:	59e0000e */ 	blezl	$t7,.PF0f0f4814
/*  f0f47dc:	c60c0544 */ 	lwc1	$f12,0x544($s0)
/*  f0f47e0:	c4303c30 */ 	lwc1	$f16,0x3c30($at)
/*  f0f47e4:	46106082 */ 	mul.s	$f2,$f12,$f16
/*  f0f47e8:	00000000 */ 	nop
/*  f0f47ec:	c6120518 */ 	lwc1	$f18,0x518($s0)
.PF0f0f47f0:
/*  f0f47f0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f47f4:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0f47f8:	46041200 */ 	add.s	$f8,$f2,$f4
/*  f0f47fc:	e6080518 */ 	swc1	$f8,0x518($s0)
/*  f0f4800:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f4804:	0059082a */ 	slt	$at,$v0,$t9
/*  f0f4808:	5420fff9 */ 	bnezl	$at,.PF0f0f47f0
/*  f0f480c:	c6120518 */ 	lwc1	$f18,0x518($s0)
/*  f0f4810:	c60c0544 */ 	lwc1	$f12,0x544($s0)
.PF0f0f4814:
/*  f0f4814:	c60e051c */ 	lwc1	$f14,0x51c($s0)
/*  f0f4818:	460e6032 */ 	c.eq.s	$f12,$f14
/*  f0f481c:	00000000 */ 	nop
/*  f0f4820:	45030014 */ 	bc1tl	.PF0f0f4874
/*  f0f4824:	c6040510 */ 	lwc1	$f4,0x510($s0)
/*  f0f4828:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0f482c:	00001025 */ 	move	$v0,$zero
/*  f0f4830:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f4834:	59c0000f */ 	blezl	$t6,.PF0f0f4874
/*  f0f4838:	c6040510 */ 	lwc1	$f4,0x510($s0)
/*  f0f483c:	c42a3c34 */ 	lwc1	$f10,0x3c34($at)
/*  f0f4840:	460a6082 */ 	mul.s	$f2,$f12,$f10
/*  f0f4844:	00000000 */ 	nop
/*  f0f4848:	c606051c */ 	lwc1	$f6,0x51c($s0)
.PF0f0f484c:
/*  f0f484c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f4850:	46060402 */ 	mul.s	$f16,$f0,$f6
/*  f0f4854:	46101480 */ 	add.s	$f18,$f2,$f16
/*  f0f4858:	e612051c */ 	swc1	$f18,0x51c($s0)
/*  f0f485c:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f4860:	004d082a */ 	slt	$at,$v0,$t5
/*  f0f4864:	5420fff9 */ 	bnezl	$at,.PF0f0f484c
/*  f0f4868:	c606051c */ 	lwc1	$f6,0x51c($s0)
/*  f0f486c:	c60e051c */ 	lwc1	$f14,0x51c($s0)
/*  f0f4870:	c6040510 */ 	lwc1	$f4,0x510($s0)
.PF0f0f4874:
/*  f0f4874:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f4878:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f487c:	e7a40430 */ 	swc1	$f4,0x430($sp)
/*  f0f4880:	c6080514 */ 	lwc1	$f8,0x514($s0)
/*  f0f4884:	e7a8042c */ 	swc1	$f8,0x42c($sp)
/*  f0f4888:	c60a0518 */ 	lwc1	$f10,0x518($s0)
/*  f0f488c:	e7ae0424 */ 	swc1	$f14,0x424($sp)
/*  f0f4890:	e7aa0428 */ 	swc1	$f10,0x428($sp)
/*  f0f4894:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f4898:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f489c:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f48a0:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f48a4:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f48a8:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f48ac:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f48b0:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f48b4:	0c005887 */ 	jal	mtx4LoadRotation
/*  f0f48b8:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
/*  f0f48bc:	100000b4 */ 	b	.PF0f0f4b90
/*  f0f48c0:	3c01c2c8 */ 	lui	$at,0xc2c8
.PF0f0f48c4:
/*  f0f48c4:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f48c8:	3c01800a */ 	lui	$at,0x800a
/*  f0f48cc:	00024b00 */ 	sll	$t1,$v0,0xc
/*  f0f48d0:	000917c2 */ 	srl	$v0,$t1,0x1f
/*  f0f48d4:	10400093 */ 	beqz	$v0,.PF0f0f4b24
/*  f0f48d8:	00000000 */ 	nop
/*  f0f48dc:	c426a520 */ 	lwc1	$f6,-0x5ae0($at)
/*  f0f48e0:	3c014220 */ 	lui	$at,0x4220
/*  f0f48e4:	44818000 */ 	mtc1	$at,$f16
/*  f0f48e8:	c6040564 */ 	lwc1	$f4,0x564($s0)
/*  f0f48ec:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f48f0:	46103483 */ 	div.s	$f18,$f6,$f16
/*  f0f48f4:	44815000 */ 	mtc1	$at,$f10
/*  f0f48f8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f48fc:	46122200 */ 	add.s	$f8,$f4,$f18
/*  f0f4900:	e6080564 */ 	swc1	$f8,0x564($s0)
/*  f0f4904:	c6000564 */ 	lwc1	$f0,0x564($s0)
/*  f0f4908:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0f490c:	00000000 */ 	nop
/*  f0f4910:	45000010 */ 	bc1f	.PF0f0f4954
/*  f0f4914:	00000000 */ 	nop
/*  f0f4918:	920a05b1 */ 	lbu	$t2,0x5b1($s0)
/*  f0f491c:	c6060538 */ 	lwc1	$f6,0x538($s0)
/*  f0f4920:	c610053c */ 	lwc1	$f16,0x53c($s0)
/*  f0f4924:	314bfff7 */ 	andi	$t3,$t2,0xfff7
/*  f0f4928:	a20b05b1 */ 	sb	$t3,0x5b1($s0)
/*  f0f492c:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f4930:	c6040540 */ 	lwc1	$f4,0x540($s0)
/*  f0f4934:	c6120544 */ 	lwc1	$f18,0x544($s0)
/*  f0f4938:	00026300 */ 	sll	$t4,$v0,0xc
/*  f0f493c:	000c17c2 */ 	srl	$v0,$t4,0x1f
/*  f0f4940:	e6060510 */ 	swc1	$f6,0x510($s0)
/*  f0f4944:	e6100514 */ 	swc1	$f16,0x514($s0)
/*  f0f4948:	e6040518 */ 	swc1	$f4,0x518($s0)
/*  f0f494c:	10000075 */ 	b	.PF0f0f4b24
/*  f0f4950:	e612051c */ 	swc1	$f18,0x51c($s0)
.PF0f0f4954:
/*  f0f4954:	c4283c38 */ 	lwc1	$f8,0x3c38($at)
/*  f0f4958:	46080302 */ 	mul.s	$f12,$f0,$f8
/*  f0f495c:	0c006858 */ 	jal	cosf
/*  f0f4960:	00000000 */ 	nop
/*  f0f4964:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f4968:	44813000 */ 	mtc1	$at,$f6
/*  f0f496c:	46000287 */ 	neg.s	$f10,$f0
/*  f0f4970:	44812000 */ 	mtc1	$at,$f4
/*  f0f4974:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f0f4978:	92020568 */ 	lbu	$v0,0x568($s0)
/*  f0f497c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f4980:	44819000 */ 	mtc1	$at,$f18
/*  f0f4984:	30590002 */ 	andi	$t9,$v0,0x2
/*  f0f4988:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f498c:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f4990:	46048080 */ 	add.s	$f2,$f16,$f4
/*  f0f4994:	46001386 */ 	mov.s	$f14,$f2
/*  f0f4998:	13200017 */ 	beqz	$t9,.PF0f0f49f8
/*  f0f499c:	46029301 */ 	sub.s	$f12,$f18,$f2
/*  f0f49a0:	c6080510 */ 	lwc1	$f8,0x510($s0)
/*  f0f49a4:	c6060538 */ 	lwc1	$f6,0x538($s0)
/*  f0f49a8:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0f49ac:	00000000 */ 	nop
/*  f0f49b0:	46061402 */ 	mul.s	$f16,$f2,$f6
/*  f0f49b4:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f0f49b8:	e7a40430 */ 	swc1	$f4,0x430($sp)
/*  f0f49bc:	c6120514 */ 	lwc1	$f18,0x514($s0)
/*  f0f49c0:	c606053c */ 	lwc1	$f6,0x53c($s0)
/*  f0f49c4:	460c9202 */ 	mul.s	$f8,$f18,$f12
/*  f0f49c8:	00000000 */ 	nop
/*  f0f49cc:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0f49d0:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f0f49d4:	e7b0042c */ 	swc1	$f16,0x42c($sp)
/*  f0f49d8:	c6040518 */ 	lwc1	$f4,0x518($s0)
/*  f0f49dc:	c6060540 */ 	lwc1	$f6,0x540($s0)
/*  f0f49e0:	460c2482 */ 	mul.s	$f18,$f4,$f12
/*  f0f49e4:	00000000 */ 	nop
/*  f0f49e8:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0f49ec:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f0f49f0:	1000000b */ 	b	.PF0f0f4a20
/*  f0f49f4:	e7aa0428 */ 	swc1	$f10,0x428($sp)
.PF0f0f49f8:
/*  f0f49f8:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f49fc:	e6000510 */ 	swc1	$f0,0x510($s0)
/*  f0f4a00:	e7a00430 */ 	swc1	$f0,0x430($sp)
/*  f0f4a04:	c600053c */ 	lwc1	$f0,0x53c($s0)
/*  f0f4a08:	e6000514 */ 	swc1	$f0,0x514($s0)
/*  f0f4a0c:	e7a0042c */ 	swc1	$f0,0x42c($sp)
/*  f0f4a10:	c6000540 */ 	lwc1	$f0,0x540($s0)
/*  f0f4a14:	e6000518 */ 	swc1	$f0,0x518($s0)
/*  f0f4a18:	e7a00428 */ 	swc1	$f0,0x428($sp)
/*  f0f4a1c:	92020568 */ 	lbu	$v0,0x568($s0)
.PF0f0f4a20:
/*  f0f4a20:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f0f4a24:	51c0000a */ 	beqzl	$t6,.PF0f0f4a50
/*  f0f4a28:	c6000544 */ 	lwc1	$f0,0x544($s0)
/*  f0f4a2c:	c610051c */ 	lwc1	$f16,0x51c($s0)
/*  f0f4a30:	c6060544 */ 	lwc1	$f6,0x544($s0)
/*  f0f4a34:	460c8102 */ 	mul.s	$f4,$f16,$f12
/*  f0f4a38:	00000000 */ 	nop
/*  f0f4a3c:	46067482 */ 	mul.s	$f18,$f14,$f6
/*  f0f4a40:	46122200 */ 	add.s	$f8,$f4,$f18
/*  f0f4a44:	10000005 */ 	b	.PF0f0f4a5c
/*  f0f4a48:	e7a80424 */ 	swc1	$f8,0x424($sp)
/*  f0f4a4c:	c6000544 */ 	lwc1	$f0,0x544($s0)
.PF0f0f4a50:
/*  f0f4a50:	e600051c */ 	swc1	$f0,0x51c($s0)
/*  f0f4a54:	e7a00424 */ 	swc1	$f0,0x424($sp)
/*  f0f4a58:	92020568 */ 	lbu	$v0,0x568($s0)
.PF0f0f4a5c:
/*  f0f4a5c:	304d0004 */ 	andi	$t5,$v0,0x4
/*  f0f4a60:	51a00024 */ 	beqzl	$t5,.PF0f0f4af4
/*  f0f4a64:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f4a68:	c60a0520 */ 	lwc1	$f10,0x520($s0)
/*  f0f4a6c:	27b10290 */ 	addiu	$s1,$sp,0x290
/*  f0f4a70:	02202025 */ 	move	$a0,$s1
/*  f0f4a74:	e7aa0290 */ 	swc1	$f10,0x290($sp)
/*  f0f4a78:	c6100524 */ 	lwc1	$f16,0x524($s0)
/*  f0f4a7c:	27a502bc */ 	addiu	$a1,$sp,0x2bc
/*  f0f4a80:	e7b00294 */ 	swc1	$f16,0x294($sp)
/*  f0f4a84:	c6060528 */ 	lwc1	$f6,0x528($s0)
/*  f0f4a88:	e7ae02d0 */ 	swc1	$f14,0x2d0($sp)
/*  f0f4a8c:	0fc25af0 */ 	jal	func0f096ca0
/*  f0f4a90:	e7a60298 */ 	swc1	$f6,0x298($sp)
/*  f0f4a94:	c6040548 */ 	lwc1	$f4,0x548($s0)
/*  f0f4a98:	02202025 */ 	move	$a0,$s1
/*  f0f4a9c:	27a502ac */ 	addiu	$a1,$sp,0x2ac
/*  f0f4aa0:	e7a40290 */ 	swc1	$f4,0x290($sp)
/*  f0f4aa4:	c612054c */ 	lwc1	$f18,0x54c($s0)
/*  f0f4aa8:	e7b20294 */ 	swc1	$f18,0x294($sp)
/*  f0f4aac:	c6080550 */ 	lwc1	$f8,0x550($s0)
/*  f0f4ab0:	0fc25af0 */ 	jal	func0f096ca0
/*  f0f4ab4:	e7a80298 */ 	swc1	$f8,0x298($sp)
/*  f0f4ab8:	c7ae02d0 */ 	lwc1	$f14,0x2d0($sp)
/*  f0f4abc:	27b1029c */ 	addiu	$s1,$sp,0x29c
/*  f0f4ac0:	02203825 */ 	move	$a3,$s1
/*  f0f4ac4:	44067000 */ 	mfc1	$a2,$f14
/*  f0f4ac8:	27a402bc */ 	addiu	$a0,$sp,0x2bc
/*  f0f4acc:	0fc25c76 */ 	jal	func0f0972b8
/*  f0f4ad0:	27a502ac */ 	addiu	$a1,$sp,0x2ac
/*  f0f4ad4:	02202025 */ 	move	$a0,$s1
/*  f0f4ad8:	0fc25b7d */ 	jal	func0f096ed4
/*  f0f4adc:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f4ae0:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f4ae4:	00024b00 */ 	sll	$t1,$v0,0xc
/*  f0f4ae8:	1000000e */ 	b	.PF0f0f4b24
/*  f0f4aec:	000917c2 */ 	srl	$v0,$t1,0x1f
/*  f0f4af0:	c6020548 */ 	lwc1	$f2,0x548($s0)
.PF0f0f4af4:
/*  f0f4af4:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f4af8:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f4afc:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f4b00:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f4b04:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f4b08:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f4b0c:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f4b10:	0c005887 */ 	jal	mtx4LoadRotation
/*  f0f4b14:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
/*  f0f4b18:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f4b1c:	00025300 */ 	sll	$t2,$v0,0xc
/*  f0f4b20:	000a17c2 */ 	srl	$v0,$t2,0x1f
.PF0f0f4b24:
/*  f0f4b24:	5440001a */ 	bnezl	$v0,.PF0f0f4b90
/*  f0f4b28:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f0f4b2c:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f4b30:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f4b34:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f4b38:	e6000510 */ 	swc1	$f0,0x510($s0)
/*  f0f4b3c:	e7a00430 */ 	swc1	$f0,0x430($sp)
/*  f0f4b40:	c600053c */ 	lwc1	$f0,0x53c($s0)
/*  f0f4b44:	e6000514 */ 	swc1	$f0,0x514($s0)
/*  f0f4b48:	e7a0042c */ 	swc1	$f0,0x42c($sp)
/*  f0f4b4c:	c6000540 */ 	lwc1	$f0,0x540($s0)
/*  f0f4b50:	e6000518 */ 	swc1	$f0,0x518($s0)
/*  f0f4b54:	e7a00428 */ 	swc1	$f0,0x428($sp)
/*  f0f4b58:	c6000544 */ 	lwc1	$f0,0x544($s0)
/*  f0f4b5c:	e600051c */ 	swc1	$f0,0x51c($s0)
/*  f0f4b60:	e7a00424 */ 	swc1	$f0,0x424($sp)
/*  f0f4b64:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f4b68:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f4b6c:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f4b70:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f4b74:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f4b78:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f4b7c:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f4b80:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f4b84:	0c005887 */ 	jal	mtx4LoadRotation
/*  f0f4b88:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
/*  f0f4b8c:	3c01c2c8 */ 	lui	$at,0xc2c8
.PF0f0f4b90:
/*  f0f4b90:	44815000 */ 	mtc1	$at,$f10
/*  f0f4b94:	c7b00428 */ 	lwc1	$f16,0x428($sp)
/*  f0f4b98:	8fac0448 */ 	lw	$t4,0x448($sp)
/*  f0f4b9c:	24010001 */ 	li	$at,0x1
/*  f0f4ba0:	46105180 */ 	add.s	$f6,$f10,$f16
/*  f0f4ba4:	15810011 */ 	bne	$t4,$at,.PF0f0f4bec
/*  f0f4ba8:	e7a6030c */ 	swc1	$f6,0x30c($sp)
/*  f0f4bac:	3c0f8009 */ 	lui	$t7,0x8009
/*  f0f4bb0:	91ef1040 */ 	lbu	$t7,0x1040($t7)
/*  f0f4bb4:	24010001 */ 	li	$at,0x1
/*  f0f4bb8:	3c198008 */ 	lui	$t9,0x8008
/*  f0f4bbc:	51e10032 */ 	beql	$t7,$at,.PF0f0f4c88
/*  f0f4bc0:	27a40390 */ 	addiu	$a0,$sp,0x390
/*  f0f4bc4:	8f390020 */ 	lw	$t9,0x20($t9)
/*  f0f4bc8:	c6040510 */ 	lwc1	$f4,0x510($s0)
/*  f0f4bcc:	44999000 */ 	mtc1	$t9,$f18
/*  f0f4bd0:	00000000 */ 	nop
/*  f0f4bd4:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0f4bd8:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f0f4bdc:	e7aa0390 */ 	swc1	$f10,0x390($sp)
/*  f0f4be0:	c6100514 */ 	lwc1	$f16,0x514($s0)
/*  f0f4be4:	10000027 */ 	b	.PF0f0f4c84
/*  f0f4be8:	e7b00394 */ 	swc1	$f16,0x394($sp)
.PF0f0f4bec:
/*  f0f4bec:	0c002e91 */ 	jal	viGetViewLeft
/*  f0f4bf0:	00000000 */ 	nop
/*  f0f4bf4:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f4bf8:	00117403 */ 	sra	$t6,$s1,0x10
/*  f0f4bfc:	0c002e73 */ 	jal	viGetViewWidth
/*  f0f4c00:	01c08825 */ 	move	$s1,$t6
/*  f0f4c04:	44823000 */ 	mtc1	$v0,$f6
/*  f0f4c08:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0f4c0c:	8dad0020 */ 	lw	$t5,0x20($t5)
/*  f0f4c10:	468034a0 */ 	cvt.s.w	$f18,$f6
/*  f0f4c14:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f4c18:	448d8000 */ 	mtc1	$t5,$f16
/*  f0f4c1c:	44812000 */ 	mtc1	$at,$f4
/*  f0f4c20:	c7aa0430 */ 	lwc1	$f10,0x430($sp)
/*  f0f4c24:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0f4c28:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f0f4c2c:	44912000 */ 	mtc1	$s1,$f4
/*  f0f4c30:	46065482 */ 	mul.s	$f18,$f10,$f6
/*  f0f4c34:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f0f4c38:	46109280 */ 	add.s	$f10,$f18,$f16
/*  f0f4c3c:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f0f4c40:	0c002e95 */ 	jal	viGetViewTop
/*  f0f4c44:	e7a60390 */ 	swc1	$f6,0x390($sp)
/*  f0f4c48:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f4c4c:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0f4c50:	0c002e77 */ 	jal	viGetViewHeight
/*  f0f4c54:	01208825 */ 	move	$s1,$t1
/*  f0f4c58:	44822000 */ 	mtc1	$v0,$f4
/*  f0f4c5c:	44913000 */ 	mtc1	$s1,$f6
/*  f0f4c60:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f4c64:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f0f4c68:	44818000 */ 	mtc1	$at,$f16
/*  f0f4c6c:	c7aa042c */ 	lwc1	$f10,0x42c($sp)
/*  f0f4c70:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0f4c74:	46109202 */ 	mul.s	$f8,$f18,$f16
/*  f0f4c78:	46045480 */ 	add.s	$f18,$f10,$f4
/*  f0f4c7c:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f0f4c80:	e7b00394 */ 	swc1	$f16,0x394($sp)
.PF0f0f4c84:
/*  f0f4c84:	27a40390 */ 	addiu	$a0,$sp,0x390
.PF0f0f4c88:
/*  f0f4c88:	27a50398 */ 	addiu	$a1,$sp,0x398
/*  f0f4c8c:	0fc2d457 */ 	jal	func0f0b4c3c
/*  f0f4c90:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0f4c94:	0c0055d0 */ 	jal	mtx4LoadIdentity
/*  f0f4c98:	27a40310 */ 	addiu	$a0,$sp,0x310
/*  f0f4c9c:	8e0205b4 */ 	lw	$v0,0x5b4($s0)
/*  f0f4ca0:	5040001d */ 	beqzl	$v0,.PF0f0f4d18
/*  f0f4ca4:	8fab0448 */ 	lw	$t3,0x448($sp)
/*  f0f4ca8:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f0f4cac:	241100ff */ 	li	$s1,0xff
/*  f0f4cb0:	00401825 */ 	move	$v1,$v0
/*  f0f4cb4:	52250018 */ 	beql	$s1,$a1,.PF0f0f4d18
/*  f0f4cb8:	8fab0448 */ 	lw	$t3,0x448($sp)
/*  f0f4cbc:	8e040054 */ 	lw	$a0,0x54($s0)
.PF0f0f4cc0:
/*  f0f4cc0:	0c0069ab */ 	jal	modelGetPart
/*  f0f4cc4:	afa3028c */ 	sw	$v1,0x28c($sp)
/*  f0f4cc8:	8fa3028c */ 	lw	$v1,0x28c($sp)
/*  f0f4ccc:	1040000d */ 	beqz	$v0,.PF0f0f4d04
/*  f0f4cd0:	00402825 */ 	move	$a1,$v0
/*  f0f4cd4:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4cd8:	0c0069eb */ 	jal	modelGetNodeRwData
/*  f0f4cdc:	afa3028c */ 	sw	$v1,0x28c($sp)
/*  f0f4ce0:	10400008 */ 	beqz	$v0,.PF0f0f4d04
/*  f0f4ce4:	8fa3028c */ 	lw	$v1,0x28c($sp)
/*  f0f4ce8:	90780001 */ 	lbu	$t8,0x1($v1)
/*  f0f4cec:	240a0001 */ 	li	$t2,0x1
/*  f0f4cf0:	53000004 */ 	beqzl	$t8,.PF0f0f4d04
/*  f0f4cf4:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0f4cf8:	10000002 */ 	b	.PF0f0f4d04
/*  f0f4cfc:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f0f4d00:	ac400000 */ 	sw	$zero,0x0($v0)
.PF0f0f4d04:
/*  f0f4d04:	90650002 */ 	lbu	$a1,0x2($v1)
/*  f0f4d08:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0f4d0c:	5625ffec */ 	bnel	$s1,$a1,.PF0f0f4cc0
/*  f0f4d10:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4d14:	8fab0448 */ 	lw	$t3,0x448($sp)
.PF0f0f4d18:
/*  f0f4d18:	24010003 */ 	li	$at,0x3
/*  f0f4d1c:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f4d20:	55610009 */ 	bnel	$t3,$at,.PF0f0f4d48
/*  f0f4d24:	c7a203a0 */ 	lwc1	$f2,0x3a0($sp)
/*  f0f4d28:	c6060510 */ 	lwc1	$f6,0x510($s0)
/*  f0f4d2c:	e7a60398 */ 	swc1	$f6,0x398($sp)
/*  f0f4d30:	c60a0514 */ 	lwc1	$f10,0x514($s0)
/*  f0f4d34:	e7aa039c */ 	swc1	$f10,0x39c($sp)
/*  f0f4d38:	c6040518 */ 	lwc1	$f4,0x518($s0)
/*  f0f4d3c:	1000000e */ 	b	.PF0f0f4d78
/*  f0f4d40:	e7a403a0 */ 	swc1	$f4,0x3a0($sp)
/*  f0f4d44:	c7a203a0 */ 	lwc1	$f2,0x3a0($sp)
.PF0f0f4d48:
/*  f0f4d48:	c7a8030c */ 	lwc1	$f8,0x30c($sp)
/*  f0f4d4c:	c7b20398 */ 	lwc1	$f18,0x398($sp)
/*  f0f4d50:	c7a6039c */ 	lwc1	$f6,0x39c($sp)
/*  f0f4d54:	46024003 */ 	div.s	$f0,$f8,$f2
/*  f0f4d58:	46120402 */ 	mul.s	$f16,$f0,$f18
/*  f0f4d5c:	00000000 */ 	nop
/*  f0f4d60:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f0f4d64:	00000000 */ 	nop
/*  f0f4d68:	46020082 */ 	mul.s	$f2,$f0,$f2
/*  f0f4d6c:	e7b00398 */ 	swc1	$f16,0x398($sp)
/*  f0f4d70:	e7aa039c */ 	swc1	$f10,0x39c($sp)
/*  f0f4d74:	e7a203a0 */ 	swc1	$f2,0x3a0($sp)
.PF0f0f4d78:
/*  f0f4d78:	0c00591b */ 	jal	mtx4LoadTranslation
/*  f0f4d7c:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4d80:	8fac0308 */ 	lw	$t4,0x308($sp)
/*  f0f4d84:	5180000a */ 	beqzl	$t4,.PF0f0f4db0
/*  f0f4d88:	c7ac0424 */ 	lwc1	$f12,0x424($sp)
/*  f0f4d8c:	c7a40424 */ 	lwc1	$f4,0x424($sp)
/*  f0f4d90:	c7a802f8 */ 	lwc1	$f8,0x2f8($sp)
/*  f0f4d94:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4d98:	46082302 */ 	mul.s	$f12,$f4,$f8
/*  f0f4d9c:	0c005725 */ 	jal	mtx00015f04
/*  f0f4da0:	00000000 */ 	nop
/*  f0f4da4:	10000005 */ 	b	.PF0f0f4dbc
/*  f0f4da8:	8faf0308 */ 	lw	$t7,0x308($sp)
/*  f0f4dac:	c7ac0424 */ 	lwc1	$f12,0x424($sp)
.PF0f0f4db0:
/*  f0f4db0:	0c005725 */ 	jal	mtx00015f04
/*  f0f4db4:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4db8:	8faf0308 */ 	lw	$t7,0x308($sp)
.PF0f0f4dbc:
/*  f0f4dbc:	11e00005 */ 	beqz	$t7,.PF0f0f4dd4
/*  f0f4dc0:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0f4dc4:	0c00591b */ 	jal	mtx4LoadTranslation
/*  f0f4dc8:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f4dcc:	1000000b */ 	b	.PF0f0f4dfc
/*  f0f4dd0:	27b10244 */ 	addiu	$s1,$sp,0x244
.PF0f0f4dd4:
/*  f0f4dd4:	c612052c */ 	lwc1	$f18,0x52c($s0)
/*  f0f4dd8:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f4ddc:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f4de0:	e7b20398 */ 	swc1	$f18,0x398($sp)
/*  f0f4de4:	c6100530 */ 	lwc1	$f16,0x530($s0)
/*  f0f4de8:	e7b0039c */ 	swc1	$f16,0x39c($sp)
/*  f0f4dec:	c6060534 */ 	lwc1	$f6,0x534($s0)
/*  f0f4df0:	0c00591b */ 	jal	mtx4LoadTranslation
/*  f0f4df4:	e7a603a0 */ 	swc1	$f6,0x3a0($sp)
/*  f0f4df8:	27b10244 */ 	addiu	$s1,$sp,0x244
.PF0f0f4dfc:
/*  f0f4dfc:	02203025 */ 	move	$a2,$s1
/*  f0f4e00:	27a40310 */ 	addiu	$a0,$sp,0x310
/*  f0f4e04:	0c0055e4 */ 	jal	mtx4MultMtx4
/*  f0f4e08:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f4e0c:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f4e10:	24010003 */ 	li	$at,0x3
/*  f0f4e14:	5721000f */ 	bnel	$t9,$at,.PF0f0f4e54
/*  f0f4e18:	26060014 */ 	addiu	$a2,$s0,0x14
/*  f0f4e1c:	0fc4ee5a */ 	jal	func0f13ae04
/*  f0f4e20:	27a401c4 */ 	addiu	$a0,$sp,0x1c4
/*  f0f4e24:	27a401c4 */ 	addiu	$a0,$sp,0x1c4
/*  f0f4e28:	02202825 */ 	move	$a1,$s1
/*  f0f4e2c:	0c0055e4 */ 	jal	mtx4MultMtx4
/*  f0f4e30:	27a60184 */ 	addiu	$a2,$sp,0x184
/*  f0f4e34:	26060014 */ 	addiu	$a2,$s0,0x14
/*  f0f4e38:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0f4e3c:	27a40184 */ 	addiu	$a0,$sp,0x184
/*  f0f4e40:	0c0055e4 */ 	jal	mtx4MultMtx4
/*  f0f4e44:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f4e48:	10000006 */ 	b	.PF0f0f4e64
/*  f0f4e4c:	00000000 */ 	nop
/*  f0f4e50:	26060014 */ 	addiu	$a2,$s0,0x14
.PF0f0f4e54:
/*  f0f4e54:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0f4e58:	02202025 */ 	move	$a0,$s1
/*  f0f4e5c:	0c0055e4 */ 	jal	mtx4MultMtx4
/*  f0f4e60:	27a50204 */ 	addiu	$a1,$sp,0x204
.PF0f0f4e64:
/*  f0f4e64:	0fc38a89 */ 	jal	func0f0e2348
/*  f0f4e68:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f4e6c:	8fae0448 */ 	lw	$t6,0x448($sp)
/*  f0f4e70:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4e74:	29c10003 */ 	slti	$at,$t6,0x3
/*  f0f4e78:	5020006f */ 	beqzl	$at,.PF0f0f5038
/*  f0f4e7c:	8e090054 */ 	lw	$t1,0x54($s0)
/*  f0f4e80:	11c0000e */ 	beqz	$t6,.PF0f0f4ebc
/*  f0f4e84:	3c11800a */ 	lui	$s1,0x800a
/*  f0f4e88:	0fc353da */ 	jal	func0f0d49c8
/*  f0f4e8c:	00402025 */ 	move	$a0,$v0
/*  f0f4e90:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f0f4e94:	3c090103 */ 	lui	$t1,0x103
/*  f0f4e98:	35290040 */ 	ori	$t1,$t1,0x40
/*  f0f4e9c:	afad0440 */ 	sw	$t5,0x440($sp)
/*  f0f4ea0:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f0f4ea4:	0fc2d542 */ 	jal	currentPlayerGetUnk1750
/*  f0f4ea8:	00408825 */ 	move	$s1,$v0
/*  f0f4eac:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f0f4eb0:	00402025 */ 	move	$a0,$v0
/*  f0f4eb4:	1000005f */ 	b	.PF0f0f5034
/*  f0f4eb8:	ae220004 */ 	sw	$v0,0x4($s1)
.PF0f0f4ebc:
/*  f0f4ebc:	263125d8 */ 	addiu	$s1,$s1,0x25d8
/*  f0f4ec0:	3c18800a */ 	lui	$t8,0x800a
/*  f0f4ec4:	3c0c800a */ 	lui	$t4,0x800a
/*  f0f4ec8:	3c0f800a */ 	lui	$t7,0x800a
/*  f0f4ecc:	8def25e0 */ 	lw	$t7,0x25e0($t7)
/*  f0f4ed0:	8d8c25e4 */ 	lw	$t4,0x25e4($t4)
/*  f0f4ed4:	8f1825dc */ 	lw	$t8,0x25dc($t8)
/*  f0f4ed8:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f0f4edc:	018fc823 */ 	subu	$t9,$t4,$t7
/*  f0f4ee0:	44994000 */ 	mtc1	$t9,$f8
/*  f0f4ee4:	030a5823 */ 	subu	$t3,$t8,$t2
/*  f0f4ee8:	448b5000 */ 	mtc1	$t3,$f10
/*  f0f4eec:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0f4ef0:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f4ef4:	3c058007 */ 	lui	$a1,0x8007
/*  f0f4ef8:	24a517a0 */ 	addiu	$a1,$a1,0x17a0
/*  f0f4efc:	248438e0 */ 	addiu	$a0,$a0,0x38e0
/*  f0f4f00:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0f4f04:	46122403 */ 	div.s	$f16,$f4,$f18
/*  f0f4f08:	0c003624 */ 	jal	mainOverrideVariable
/*  f0f4f0c:	e7b0017c */ 	swc1	$f16,0x17c($sp)
/*  f0f4f10:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f4f14:	3c058007 */ 	lui	$a1,0x8007
/*  f0f4f18:	24a517a4 */ 	addiu	$a1,$a1,0x17a4
/*  f0f4f1c:	0c003624 */ 	jal	mainOverrideVariable
/*  f0f4f20:	248438e4 */ 	addiu	$a0,$a0,0x38e4
/*  f0f4f24:	0fc353da */ 	jal	func0f0d49c8
/*  f0f4f28:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f4f2c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0f4f30:	8dad0020 */ 	lw	$t5,0x20($t5)
/*  f0f4f34:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0f4f38:	3c05800a */ 	lui	$a1,0x800a
/*  f0f4f3c:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4f40:	01cd0019 */ 	multu	$t6,$t5
/*  f0f4f44:	84a525e2 */ 	lh	$a1,0x25e2($a1)
/*  f0f4f48:	00002012 */ 	mflo	$a0
/*  f0f4f4c:	00044c00 */ 	sll	$t1,$a0,0x10
/*  f0f4f50:	0c002e7b */ 	jal	viSetViewPosition
/*  f0f4f54:	00092403 */ 	sra	$a0,$t1,0x10
/*  f0f4f58:	3c0b800a */ 	lui	$t3,0x800a
/*  f0f4f5c:	8d6b25dc */ 	lw	$t3,0x25dc($t3)
/*  f0f4f60:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f0f4f64:	3c198008 */ 	lui	$t9,0x8008
/*  f0f4f68:	8f390020 */ 	lw	$t9,0x20($t9)
/*  f0f4f6c:	016c7823 */ 	subu	$t7,$t3,$t4
/*  f0f4f70:	3c0a800a */ 	lui	$t2,0x800a
/*  f0f4f74:	01f90019 */ 	multu	$t7,$t9
/*  f0f4f78:	3c09800a */ 	lui	$t1,0x800a
/*  f0f4f7c:	3c18800a */ 	lui	$t8,0x800a
/*  f0f4f80:	8f1825e0 */ 	lw	$t8,0x25e0($t8)
/*  f0f4f84:	8d2925e4 */ 	lw	$t1,0x25e4($t1)
/*  f0f4f88:	8d4aa794 */ 	lw	$t2,-0x586c($t2)
/*  f0f4f8c:	c7ae017c */ 	lwc1	$f14,0x17c($sp)
/*  f0f4f90:	01383823 */ 	subu	$a3,$t1,$t8
/*  f0f4f94:	c54c1854 */ 	lwc1	$f12,0x1854($t2)
/*  f0f4f98:	00075400 */ 	sll	$t2,$a3,0x10
/*  f0f4f9c:	00003012 */ 	mflo	$a2
/*  f0f4fa0:	00067400 */ 	sll	$t6,$a2,0x10
/*  f0f4fa4:	000e3403 */ 	sra	$a2,$t6,0x10
/*  f0f4fa8:	0c002ec7 */ 	jal	viSetFovAspectAndSize
/*  f0f4fac:	000a3c03 */ 	sra	$a3,$t2,0x10
/*  f0f4fb0:	3c0c8007 */ 	lui	$t4,0x8007
/*  f0f4fb4:	8d8c1728 */ 	lw	$t4,0x1728($t4)
/*  f0f4fb8:	3c19800a */ 	lui	$t9,0x800a
/*  f0f4fbc:	273925e8 */ 	addiu	$t9,$t9,0x25e8
/*  f0f4fc0:	000c7940 */ 	sll	$t7,$t4,0x5
/*  f0f4fc4:	01f92821 */ 	addu	$a1,$t7,$t9
/*  f0f4fc8:	0c002b11 */ 	jal	vi0000af00
/*  f0f4fcc:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f4fd0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f4fd4:	8dce17a0 */ 	lw	$t6,0x17a0($t6)
/*  f0f4fd8:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4fdc:	00402025 */ 	move	$a0,$v0
/*  f0f4fe0:	448e3000 */ 	mtc1	$t6,$f6
/*  f0f4fe4:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0f4fe8:	05c10005 */ 	bgez	$t6,.PF0f0f5000
/*  f0f4fec:	468031a0 */ 	cvt.s.w	$f6,$f6
/*  f0f4ff0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f4ff4:	44815000 */ 	mtc1	$at,$f10
/*  f0f4ff8:	00000000 */ 	nop
/*  f0f4ffc:	460a3180 */ 	add.s	$f6,$f6,$f10
.PF0f0f5000:
/*  f0f5000:	8dad17a4 */ 	lw	$t5,0x17a4($t5)
/*  f0f5004:	44053000 */ 	mfc1	$a1,$f6
/*  f0f5008:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f500c:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f5010:	05a10004 */ 	bgez	$t5,.PF0f0f5024
/*  f0f5014:	46804220 */ 	cvt.s.w	$f8,$f8
/*  f0f5018:	44812000 */ 	mtc1	$at,$f4
/*  f0f501c:	00000000 */ 	nop
/*  f0f5020:	46044200 */ 	add.s	$f8,$f8,$f4
.PF0f0f5024:
/*  f0f5024:	44064000 */ 	mfc1	$a2,$f8
/*  f0f5028:	0c002a7a */ 	jal	vi0000aca4
/*  f0f502c:	00000000 */ 	nop
/*  f0f5030:	afa20440 */ 	sw	$v0,0x440($sp)
.PF0f0f5034:
/*  f0f5034:	8e090054 */ 	lw	$t1,0x54($s0)
.PF0f0f5038:
/*  f0f5038:	8524000e */ 	lh	$a0,0xe($t1)
/*  f0f503c:	0004c180 */ 	sll	$t8,$a0,0x6
/*  f0f5040:	0fc5a25d */ 	jal	gfxAllocate
/*  f0f5044:	03002025 */ 	move	$a0,$t8
/*  f0f5048:	afa203b4 */ 	sw	$v0,0x3b4($sp)
/*  f0f504c:	8e0a0054 */ 	lw	$t2,0x54($s0)
/*  f0f5050:	00008825 */ 	move	$s1,$zero
/*  f0f5054:	854b000e */ 	lh	$t3,0xe($t2)
/*  f0f5058:	5960000d */ 	blezl	$t3,.PF0f0f5090
/*  f0f505c:	8605005c */ 	lh	$a1,0x5c($s0)
/*  f0f5060:	8faf03b4 */ 	lw	$t7,0x3b4($sp)
.PF0f0f5064:
/*  f0f5064:	00116180 */ 	sll	$t4,$s1,0x6
/*  f0f5068:	0c0055d0 */ 	jal	mtx4LoadIdentity
/*  f0f506c:	018f2021 */ 	addu	$a0,$t4,$t7
/*  f0f5070:	8e190054 */ 	lw	$t9,0x54($s0)
/*  f0f5074:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f5078:	872e000e */ 	lh	$t6,0xe($t9)
/*  f0f507c:	022e082a */ 	slt	$at,$s1,$t6
/*  f0f5080:	5420fff8 */ 	bnezl	$at,.PF0f0f5064
/*  f0f5084:	8faf03b4 */ 	lw	$t7,0x3b4($sp)
/*  f0f5088:	00008825 */ 	move	$s1,$zero
/*  f0f508c:	8605005c */ 	lh	$a1,0x5c($s0)
.PF0f0f5090:
/*  f0f5090:	8fad03b4 */ 	lw	$t5,0x3b4($sp)
/*  f0f5094:	10a00025 */ 	beqz	$a1,.PF0f0f512c
/*  f0f5098:	ae0d006c */ 	sw	$t5,0x6c($s0)
/*  f0f509c:	8609005e */ 	lh	$t1,0x5e($s0)
/*  f0f50a0:	50a90023 */ 	beql	$a1,$t1,.PF0f0f5130
/*  f0f50a4:	860f005e */ 	lh	$t7,0x5e($s0)
/*  f0f50a8:	8e1805b0 */ 	lw	$t8,0x5b0($s0)
/*  f0f50ac:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f50b0:	00003025 */ 	move	$a2,$zero
/*  f0f50b4:	00185ac0 */ 	sll	$t3,$t8,0xb
/*  f0f50b8:	05610014 */ 	bgez	$t3,.PF0f0f510c
/*  f0f50bc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f50c0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f50c4:	c4323c3c */ 	lwc1	$f18,0x3c3c($at)
/*  f0f50c8:	44808000 */ 	mtc1	$zero,$f16
/*  f0f50cc:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f50d0:	00003025 */ 	move	$a2,$zero
/*  f0f50d4:	24070000 */ 	li	$a3,0x0
/*  f0f50d8:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0f50dc:	0c0076a7 */ 	jal	modelSetAnimation
/*  f0f50e0:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0f50e4:	0c0073fa */ 	jal	modelGetNumAnimFrames
/*  f0f50e8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f50ec:	44823000 */ 	mtc1	$v0,$f6
/*  f0f50f0:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f50f4:	468031a0 */ 	cvt.s.w	$f6,$f6
/*  f0f50f8:	44053000 */ 	mfc1	$a1,$f6
/*  f0f50fc:	0c00777a */ 	jal	model0001e018
/*  f0f5100:	00000000 */ 	nop
/*  f0f5104:	10000008 */ 	b	.PF0f0f5128
/*  f0f5108:	860c005c */ 	lh	$t4,0x5c($s0)
.PF0f0f510c:
/*  f0f510c:	c42a3c40 */ 	lwc1	$f10,0x3c40($at)
/*  f0f5110:	44804000 */ 	mtc1	$zero,$f8
/*  f0f5114:	24070000 */ 	li	$a3,0x0
/*  f0f5118:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0f511c:	0c0076a7 */ 	jal	modelSetAnimation
/*  f0f5120:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0f5124:	860c005c */ 	lh	$t4,0x5c($s0)
.PF0f0f5128:
/*  f0f5128:	a60c005e */ 	sh	$t4,0x5e($s0)
.PF0f0f512c:
/*  f0f512c:	860f005e */ 	lh	$t7,0x5e($s0)
.PF0f0f5130:
/*  f0f5130:	a600005c */ 	sh	$zero,0x5c($s0)
/*  f0f5134:	11e00023 */ 	beqz	$t7,.PF0f0f51c4
/*  f0f5138:	3c05800a */ 	lui	$a1,0x800a
/*  f0f513c:	8ca5a550 */ 	lw	$a1,-0x5ab0($a1)
/*  f0f5140:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f5144:	0c007afa */ 	jal	model0001ee18
/*  f0f5148:	24060001 */ 	li	$a2,0x1
/*  f0f514c:	8e1905b0 */ 	lw	$t9,0x5b0($s0)
/*  f0f5150:	00196ac0 */ 	sll	$t5,$t9,0xb
/*  f0f5154:	05a1000c */ 	bgez	$t5,.PF0f0f5188
/*  f0f5158:	00000000 */ 	nop
/*  f0f515c:	0c0073fa */ 	jal	modelGetNumAnimFrames
/*  f0f5160:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f5164:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f5168:	0c0073d3 */ 	jal	modelGetCurAnimFrame
/*  f0f516c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f5170:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0f5174:	44892000 */ 	mtc1	$t1,$f4
/*  f0f5178:	00000000 */ 	nop
/*  f0f517c:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f0f5180:	10000004 */ 	b	.PF0f0f5194
/*  f0f5184:	46009081 */ 	sub.s	$f2,$f18,$f0
.PF0f0f5188:
/*  f0f5188:	0c0073d3 */ 	jal	modelGetCurAnimFrame
/*  f0f518c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f5190:	46000086 */ 	mov.s	$f2,$f0
.PF0f0f5194:
/*  f0f5194:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f5198:	0c0073fa */ 	jal	modelGetNumAnimFrames
/*  f0f519c:	e7a20178 */ 	swc1	$f2,0x178($sp)
/*  f0f51a0:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f0f51a4:	44988000 */ 	mtc1	$t8,$f16
/*  f0f51a8:	c7a20178 */ 	lwc1	$f2,0x178($sp)
/*  f0f51ac:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0f51b0:	4602303e */ 	c.le.s	$f6,$f2
/*  f0f51b4:	00000000 */ 	nop
/*  f0f51b8:	45020003 */ 	bc1fl	.PF0f0f51c8
/*  f0f51bc:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f51c0:	a600005e */ 	sh	$zero,0x5e($s0)
.PF0f0f51c4:
/*  f0f51c4:	8fa40040 */ 	lw	$a0,0x40($sp)
.PF0f0f51c8:
/*  f0f51c8:	0c0056aa */ 	jal	mtx4Copy
/*  f0f51cc:	8fa503b4 */ 	lw	$a1,0x3b4($sp)
/*  f0f51d0:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f0f51d4:	27a403b8 */ 	addiu	$a0,$sp,0x3b8
/*  f0f51d8:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0f51dc:	afaa03b8 */ 	sw	$t2,0x3b8($sp)
/*  f0f51e0:	8e0b006c */ 	lw	$t3,0x6c($s0)
/*  f0f51e4:	0c007323 */ 	jal	model0001cebc
/*  f0f51e8:	afab03c8 */ 	sw	$t3,0x3c8($sp)
/*  f0f51ec:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f51f0:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0f51f4:	258cd104 */ 	addiu	$t4,$t4,-12028
/*  f0f51f8:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f0f51fc:	558f0096 */ 	bnel	$t4,$t7,.PF0f0f5458
/*  f0f5200:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f5204:	0c0069ab */ 	jal	modelGetPart
/*  f0f5208:	00002825 */ 	move	$a1,$zero
/*  f0f520c:	50400032 */ 	beqzl	$v0,.PF0f0f52d8
/*  f0f5210:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f5214:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f0f5218:	00003825 */ 	move	$a3,$zero
/*  f0f521c:	00003025 */ 	move	$a2,$zero
/*  f0f5220:	84b90010 */ 	lh	$t9,0x10($a1)
/*  f0f5224:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0f5228:	3c08800a */ 	lui	$t0,0x800a
/*  f0f522c:	5b20002a */ 	blezl	$t9,.PF0f0f52d8
/*  f0f5230:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f5234:	44810000 */ 	mtc1	$at,$f0
/*  f0f5238:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0f523c:	c50a0010 */ 	lwc1	$f10,0x10($t0)
.PF0f0f5240:
/*  f0f5240:	8cae000c */ 	lw	$t6,0xc($a1)
/*  f0f5244:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0f5248:	01c61021 */ 	addu	$v0,$t6,$a2
/*  f0f524c:	844d0008 */ 	lh	$t5,0x8($v0)
/*  f0f5250:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0f5254:	44182000 */ 	mfc1	$t8,$f4
/*  f0f5258:	00000000 */ 	nop
/*  f0f525c:	01b85023 */ 	subu	$t2,$t5,$t8
/*  f0f5260:	a44a0008 */ 	sh	$t2,0x8($v0)
/*  f0f5264:	8cab000c */ 	lw	$t3,0xc($a1)
/*  f0f5268:	01666021 */ 	addu	$t4,$t3,$a2
/*  f0f526c:	858f0008 */ 	lh	$t7,0x8($t4)
/*  f0f5270:	29e1a000 */ 	slti	$at,$t7,-24576
/*  f0f5274:	50200012 */ 	beqzl	$at,.PF0f0f52c0
/*  f0f5278:	84aa0010 */ 	lh	$t2,0x10($a1)
/*  f0f527c:	84b90010 */ 	lh	$t9,0x10($a1)
/*  f0f5280:	00001825 */ 	move	$v1,$zero
/*  f0f5284:	00002025 */ 	move	$a0,$zero
/*  f0f5288:	5b20000d */ 	blezl	$t9,.PF0f0f52c0
/*  f0f528c:	84aa0010 */ 	lh	$t2,0x10($a1)
/*  f0f5290:	8cae000c */ 	lw	$t6,0xc($a1)
.PF0f0f5294:
/*  f0f5294:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f5298:	01c41021 */ 	addu	$v0,$t6,$a0
/*  f0f529c:	84490008 */ 	lh	$t1,0x8($v0)
/*  f0f52a0:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f0f52a4:	252d2000 */ 	addiu	$t5,$t1,0x2000
/*  f0f52a8:	a44d0008 */ 	sh	$t5,0x8($v0)
/*  f0f52ac:	84b80010 */ 	lh	$t8,0x10($a1)
/*  f0f52b0:	0078082a */ 	slt	$at,$v1,$t8
/*  f0f52b4:	5420fff7 */ 	bnezl	$at,.PF0f0f5294
/*  f0f52b8:	8cae000c */ 	lw	$t6,0xc($a1)
/*  f0f52bc:	84aa0010 */ 	lh	$t2,0x10($a1)
.PF0f0f52c0:
/*  f0f52c0:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f0f52c4:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f0f52c8:	00ea082a */ 	slt	$at,$a3,$t2
/*  f0f52cc:	5420ffdc */ 	bnezl	$at,.PF0f0f5240
/*  f0f52d0:	c50a0010 */ 	lwc1	$f10,0x10($t0)
/*  f0f52d4:	8e040054 */ 	lw	$a0,0x54($s0)
.PF0f0f52d8:
/*  f0f52d8:	0c0069ab */ 	jal	modelGetPart
/*  f0f52dc:	24050002 */ 	li	$a1,0x2
/*  f0f52e0:	10400019 */ 	beqz	$v0,.PF0f0f5348
/*  f0f52e4:	00402025 */ 	move	$a0,$v0
/*  f0f52e8:	0c0068ad */ 	jal	model0001a524
/*  f0f52ec:	00002825 */ 	move	$a1,$zero
/*  f0f52f0:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0f52f4:	0c0055d0 */ 	jal	mtx4LoadIdentity
/*  f0f52f8:	27a40120 */ 	addiu	$a0,$sp,0x120
/*  f0f52fc:	3c014080 */ 	lui	$at,0x4080
/*  f0f5300:	44816000 */ 	mtc1	$at,$f12
/*  f0f5304:	0fc01ad1 */ 	jal	func0f006b54
/*  f0f5308:	00000000 */ 	nop
/*  f0f530c:	46000306 */ 	mov.s	$f12,$f0
/*  f0f5310:	0c00581e */ 	jal	mtx4LoadXRotation
/*  f0f5314:	27a50120 */ 	addiu	$a1,$sp,0x120
/*  f0f5318:	8fac0160 */ 	lw	$t4,0x160($sp)
/*  f0f531c:	8fab03b4 */ 	lw	$t3,0x3b4($sp)
/*  f0f5320:	27a50120 */ 	addiu	$a1,$sp,0x120
/*  f0f5324:	000c7980 */ 	sll	$t7,$t4,0x6
/*  f0f5328:	016f3821 */ 	addu	$a3,$t3,$t7
/*  f0f532c:	00e02025 */ 	move	$a0,$a3
/*  f0f5330:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f0f5334:	0c0055e4 */ 	jal	mtx4MultMtx4
/*  f0f5338:	27a600e0 */ 	addiu	$a2,$sp,0xe0
/*  f0f533c:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0f5340:	0c0056aa */ 	jal	mtx4Copy
/*  f0f5344:	27a400e0 */ 	addiu	$a0,$sp,0xe0
.PF0f0f5348:
/*  f0f5348:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f534c:	0c0069ab */ 	jal	modelGetPart
/*  f0f5350:	24050001 */ 	li	$a1,0x1
/*  f0f5354:	1040003f */ 	beqz	$v0,.PF0f0f5454
/*  f0f5358:	00402025 */ 	move	$a0,$v0
/*  f0f535c:	3c02800a */ 	lui	$v0,0x800a
/*  f0f5360:	8c421f64 */ 	lw	$v0,0x1f64($v0)
/*  f0f5364:	24010002 */ 	li	$at,0x2
/*  f0f5368:	10410007 */ 	beq	$v0,$at,.PF0f0f5388
/*  f0f536c:	24010006 */ 	li	$at,0x6
/*  f0f5370:	10410005 */ 	beq	$v0,$at,.PF0f0f5388
/*  f0f5374:	24010003 */ 	li	$at,0x3
/*  f0f5378:	10410003 */ 	beq	$v0,$at,.PF0f0f5388
/*  f0f537c:	2401000d */ 	li	$at,0xd
/*  f0f5380:	54410035 */ 	bnel	$v0,$at,.PF0f0f5458
/*  f0f5384:	8fad0440 */ 	lw	$t5,0x440($sp)
.PF0f0f5388:
/*  f0f5388:	0c0068ad */ 	jal	model0001a524
/*  f0f538c:	00002825 */ 	move	$a1,$zero
/*  f0f5390:	8fb903b4 */ 	lw	$t9,0x3b4($sp)
/*  f0f5394:	00027180 */ 	sll	$t6,$v0,0x6
/*  f0f5398:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0f539c:	032e1821 */ 	addu	$v1,$t9,$t6
/*  f0f53a0:	c4720030 */ 	lwc1	$f18,0x30($v1)
/*  f0f53a4:	27a500c8 */ 	addiu	$a1,$sp,0xc8
/*  f0f53a8:	e7b200d0 */ 	swc1	$f18,0xd0($sp)
/*  f0f53ac:	c4700034 */ 	lwc1	$f16,0x34($v1)
/*  f0f53b0:	e7b000d4 */ 	swc1	$f16,0xd4($sp)
/*  f0f53b4:	c4660038 */ 	lwc1	$f6,0x38($v1)
/*  f0f53b8:	0fc2d489 */ 	jal	func0f0b4d04
/*  f0f53bc:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
/*  f0f53c0:	0c002e53 */ 	jal	viGetWidth
/*  f0f53c4:	00000000 */ 	nop
/*  f0f53c8:	c7aa00c8 */ 	lwc1	$f10,0xc8($sp)
/*  f0f53cc:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0f53d0:	8d8c0020 */ 	lw	$t4,0x20($t4)
/*  f0f53d4:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0f53d8:	440d4000 */ 	mfc1	$t5,$f8
/*  f0f53dc:	04410003 */ 	bgez	$v0,.PF0f0f53ec
/*  f0f53e0:	0002c043 */ 	sra	$t8,$v0,0x1
/*  f0f53e4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f53e8:	0001c043 */ 	sra	$t8,$at,0x1
.PF0f0f53ec:
/*  f0f53ec:	01b85023 */ 	subu	$t2,$t5,$t8
/*  f0f53f0:	014c001a */ 	div	$zero,$t2,$t4
/*  f0f53f4:	15800002 */ 	bnez	$t4,.PF0f0f5400
/*  f0f53f8:	00000000 */ 	nop
/*  f0f53fc:	0007000d */ 	break	0x7
.PF0f0f5400:
/*  f0f5400:	2401ffff */ 	li	$at,-1
/*  f0f5404:	15810004 */ 	bne	$t4,$at,.PF0f0f5418
/*  f0f5408:	3c018000 */ 	lui	$at,0x8000
/*  f0f540c:	15410002 */ 	bne	$t2,$at,.PF0f0f5418
/*  f0f5410:	00000000 */ 	nop
/*  f0f5414:	0006000d */ 	break	0x6
.PF0f0f5418:
/*  f0f5418:	3c01800a */ 	lui	$at,0x800a
/*  f0f541c:	00005812 */ 	mflo	$t3
/*  f0f5420:	ac2be408 */ 	sw	$t3,-0x1bf8($at)
/*  f0f5424:	0c002e57 */ 	jal	viGetHeight
/*  f0f5428:	00000000 */ 	nop
/*  f0f542c:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0f5430:	4600248d */ 	trunc.w.s	$f18,$f4
/*  f0f5434:	44199000 */ 	mfc1	$t9,$f18
/*  f0f5438:	04410003 */ 	bgez	$v0,.PF0f0f5448
/*  f0f543c:	00027043 */ 	sra	$t6,$v0,0x1
/*  f0f5440:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f5444:	00017043 */ 	sra	$t6,$at,0x1
.PF0f0f5448:
/*  f0f5448:	3c01800a */ 	lui	$at,0x800a
/*  f0f544c:	032e4823 */ 	subu	$t1,$t9,$t6
/*  f0f5450:	ac29e40c */ 	sw	$t1,-0x1bf4($at)
.PF0f0f5454:
/*  f0f5454:	8fad0440 */ 	lw	$t5,0x440($sp)
.PF0f0f5458:
/*  f0f5458:	3c0abc00 */ 	lui	$t2,0xbc00
/*  f0f545c:	3c0c8000 */ 	lui	$t4,0x8000
/*  f0f5460:	25b80008 */ 	addiu	$t8,$t5,0x8
/*  f0f5464:	afb80440 */ 	sw	$t8,0x440($sp)
/*  f0f5468:	358c0040 */ 	ori	$t4,$t4,0x40
/*  f0f546c:	354a0002 */ 	ori	$t2,$t2,0x2
/*  f0f5470:	adaa0000 */ 	sw	$t2,0x0($t5)
/*  f0f5474:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f0f5478:	8fab0440 */ 	lw	$t3,0x440($sp)
/*  f0f547c:	3c190386 */ 	lui	$t9,0x386
/*  f0f5480:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f5484:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f0f5488:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f548c:	25ce1750 */ 	addiu	$t6,$t6,0x1750
/*  f0f5490:	37390010 */ 	ori	$t9,$t9,0x10
/*  f0f5494:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f0f5498:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f0f549c:	8fa90440 */ 	lw	$t1,0x440($sp)
/*  f0f54a0:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0f54a4:	3c180388 */ 	lui	$t8,0x388
/*  f0f54a8:	252d0008 */ 	addiu	$t5,$t1,0x8
/*  f0f54ac:	afad0440 */ 	sw	$t5,0x440($sp)
/*  f0f54b0:	37180010 */ 	ori	$t8,$t8,0x10
/*  f0f54b4:	254a1748 */ 	addiu	$t2,$t2,0x1748
/*  f0f54b8:	ad2a0004 */ 	sw	$t2,0x4($t1)
/*  f0f54bc:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f0f54c0:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f54c4:	3c0f0384 */ 	lui	$t7,0x384
/*  f0f54c8:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f0f54cc:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f0f54d0:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f54d4:	ad8f0000 */ 	sw	$t7,0x0($t4)
/*  f0f54d8:	0fc2d732 */ 	jal	currentPlayerGetUnk175c
/*  f0f54dc:	afac00b8 */ 	sw	$t4,0xb8($sp)
/*  f0f54e0:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*  f0f54e4:	3c090382 */ 	lui	$t1,0x382
/*  f0f54e8:	35290010 */ 	ori	$t1,$t1,0x10
/*  f0f54ec:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0f54f0:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f54f4:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0f54f8:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f54fc:	af290000 */ 	sw	$t1,0x0($t9)
/*  f0f5500:	0fc2d732 */ 	jal	currentPlayerGetUnk175c
/*  f0f5504:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f0f5508:	8fa600b4 */ 	lw	$a2,0xb4($sp)
/*  f0f550c:	244d0010 */ 	addiu	$t5,$v0,0x10
/*  f0f5510:	24180001 */ 	li	$t8,0x1
/*  f0f5514:	accd0004 */ 	sw	$t5,0x4($a2)
/*  f0f5518:	8fab0440 */ 	lw	$t3,0x440($sp)
/*  f0f551c:	240affff */ 	li	$t2,-1
/*  f0f5520:	240cffff */ 	li	$t4,-1
/*  f0f5524:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f0f5528:	afb803e8 */ 	sw	$t8,0x3e8($sp)
/*  f0f552c:	afaa03ec */ 	sw	$t2,0x3ec($sp)
/*  f0f5530:	afac03f0 */ 	sw	$t4,0x3f0($sp)
/*  f0f5534:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f5538:	3c19b700 */ 	lui	$t9,0xb700
/*  f0f553c:	240e0001 */ 	li	$t6,0x1
/*  f0f5540:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f0f5544:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f0f5548:	8fa90440 */ 	lw	$t1,0x440($sp)
/*  f0f554c:	240d0001 */ 	li	$t5,0x1
/*  f0f5550:	afad03bc */ 	sw	$t5,0x3bc($sp)
/*  f0f5554:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0f5558:	27a403b8 */ 	addiu	$a0,$sp,0x3b8
/*  f0f555c:	0c0085fe */ 	jal	modelRender
/*  f0f5560:	afa903c4 */ 	sw	$t1,0x3c4($sp)
/*  f0f5564:	8fb803c4 */ 	lw	$t8,0x3c4($sp)
/*  f0f5568:	0c00593c */ 	jal	mtx00016760
/*  f0f556c:	afb80440 */ 	sw	$t8,0x440($sp)
/*  f0f5570:	8e0a0054 */ 	lw	$t2,0x54($s0)
/*  f0f5574:	00001025 */ 	move	$v0,$zero
/*  f0f5578:	854c000e */ 	lh	$t4,0xe($t2)
/*  f0f557c:	19800013 */ 	blez	$t4,.PF0f0f55cc
/*  f0f5580:	00000000 */ 	nop
/*  f0f5584:	8e0b006c */ 	lw	$t3,0x6c($s0)
.PF0f0f5588:
/*  f0f5588:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0f558c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f5590:	0c0056aa */ 	jal	mtx4Copy
/*  f0f5594:	01622021 */ 	addu	$a0,$t3,$v0
/*  f0f5598:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f0f559c:	0011c980 */ 	sll	$t9,$s1,0x6
/*  f0f55a0:	27a40070 */ 	addiu	$a0,$sp,0x70
/*  f0f55a4:	0c005779 */ 	jal	mtx00016054
/*  f0f55a8:	01f92821 */ 	addu	$a1,$t7,$t9
/*  f0f55ac:	8e0e0054 */ 	lw	$t6,0x54($s0)
/*  f0f55b0:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0f55b4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f55b8:	85c9000e */ 	lh	$t1,0xe($t6)
/*  f0f55bc:	24420040 */ 	addiu	$v0,$v0,0x40
/*  f0f55c0:	0229082a */ 	slt	$at,$s1,$t1
/*  f0f55c4:	5420fff0 */ 	bnezl	$at,.PF0f0f5588
/*  f0f55c8:	8e0b006c */ 	lw	$t3,0x6c($s0)
.PF0f0f55cc:
/*  f0f55cc:	0c005945 */ 	jal	mtx00016784
/*  f0f55d0:	00000000 */ 	nop
/*  f0f55d4:	8fad0448 */ 	lw	$t5,0x448($sp)
/*  f0f55d8:	29a10003 */ 	slti	$at,$t5,0x3
/*  f0f55dc:	50200005 */ 	beqzl	$at,.PF0f0f55f4
/*  f0f55e0:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f55e4:	0fc3534f */ 	jal	func0f0d479c
/*  f0f55e8:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f55ec:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f55f0:	8fb80440 */ 	lw	$t8,0x440($sp)
.PF0f0f55f4:
/*  f0f55f4:	3c0ce700 */ 	lui	$t4,0xe700
/*  f0f55f8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0f55fc:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f5600:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f5604:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0f5608:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f0f560c:	8fab0440 */ 	lw	$t3,0x440($sp)
/*  f0f5610:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f0f5614:	3c0db900 */ 	lui	$t5,0xb900
/*  f0f5618:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f0f561c:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f5620:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0f5624:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f0f5628:	8fae0440 */ 	lw	$t6,0x440($sp)
/*  f0f562c:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0f5630:	3c0cfc12 */ 	lui	$t4,0xfc12
/*  f0f5634:	25c90008 */ 	addiu	$t1,$t6,0x8
/*  f0f5638:	afa90440 */ 	sw	$t1,0x440($sp)
/*  f0f563c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f5640:	adcd0000 */ 	sw	$t5,0x0($t6)
/*  f0f5644:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f5648:	358c7e24 */ 	ori	$t4,$t4,0x7e24
/*  f0f564c:	240bf9fc */ 	li	$t3,-1540
/*  f0f5650:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f5654:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f5658:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f0f565c:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f0f5660:	8faf0440 */ 	lw	$t7,0x440($sp)
/*  f0f5664:	3c0eb600 */ 	lui	$t6,0xb600
/*  f0f5668:	24093000 */ 	li	$t1,0x3000
/*  f0f566c:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f0f5670:	afb90440 */ 	sw	$t9,0x440($sp)
/*  f0f5674:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f0f5678:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f0f567c:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f5680:	3c0aba00 */ 	lui	$t2,0xba00
/*  f0f5684:	354a0c02 */ 	ori	$t2,$t2,0xc02
/*  f0f5688:	25b80008 */ 	addiu	$t8,$t5,0x8
/*  f0f568c:	afb80440 */ 	sw	$t8,0x440($sp)
/*  f0f5690:	240c2000 */ 	li	$t4,0x2000
/*  f0f5694:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f0f5698:	adaa0000 */ 	sw	$t2,0x0($t5)
/*  f0f569c:	27b00440 */ 	addiu	$s0,$sp,0x440
/*  f0f56a0:	240f0001 */ 	li	$t7,0x1
/*  f0f56a4:	240b0002 */ 	li	$t3,0x2
/*  f0f56a8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f56ac:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f56b0:	02002025 */ 	move	$a0,$s0
/*  f0f56b4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f56b8:	00002825 */ 	move	$a1,$zero
/*  f0f56bc:	24060002 */ 	li	$a2,0x2
/*  f0f56c0:	0fc2cfb8 */ 	jal	func0f0b39c0
/*  f0f56c4:	00003825 */ 	move	$a3,$zero
/*  f0f56c8:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f56cc:	3c09b900 */ 	lui	$t1,0xb900
/*  f0f56d0:	3c0d0050 */ 	lui	$t5,0x50
/*  f0f56d4:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0f56d8:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f56dc:	35ad4240 */ 	ori	$t5,$t5,0x4240
/*  f0f56e0:	3529031d */ 	ori	$t1,$t1,0x31d
/*  f0f56e4:	af290000 */ 	sw	$t1,0x0($t9)
/*  f0f56e8:	af2d0004 */ 	sw	$t5,0x4($t9)
/*  f0f56ec:	24180002 */ 	li	$t8,0x2
/*  f0f56f0:	240a0001 */ 	li	$t2,0x1
/*  f0f56f4:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0f56f8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f56fc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f5700:	02002025 */ 	move	$a0,$s0
/*  f0f5704:	00002825 */ 	move	$a1,$zero
/*  f0f5708:	24060002 */ 	li	$a2,0x2
/*  f0f570c:	0fc2cfb8 */ 	jal	func0f0b39c0
/*  f0f5710:	00003825 */ 	move	$a3,$zero
/*  f0f5714:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f5718:	3c0f0600 */ 	lui	$t7,0x600
/*  f0f571c:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f0f5720:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f5724:	ad8f0000 */ 	sw	$t7,0x0($t4)
/*  f0f5728:	8fb90038 */ 	lw	$t9,0x38($sp)
/*  f0f572c:	ad990004 */ 	sw	$t9,0x4($t4)
.PF0f0f5730:
/*  f0f5730:	8fa20440 */ 	lw	$v0,0x440($sp)
.PF0f0f5734:
/*  f0f5734:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f5738:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0f573c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0f5740:	03e00008 */ 	jr	$ra
/*  f0f5744:	27bd0440 */ 	addiu	$sp,$sp,0x440
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuRenderModels
.late_rodata
glabel var7f1b292c
.word 0x40f33333
glabel var7f1b2930
.word 0x3b03126f
glabel var7f1b2934
.word 0x3f7f7cee
glabel var7f1b2938
.word 0x3f7f7cee
glabel var7f1b293c
.word 0x3b03126f
glabel var7f1b2940
.word 0x3b03126f
glabel var7f1b2944
.word 0x3b03126f
glabel var7f1b2948
.word 0x40490fdb
.text
/*  f0f38b0:	27bdfbc0 */ 	addiu	$sp,$sp,-1088
/*  f0f38b4:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x4b4)
/*  f0f38b8:	8c42a474 */ 	lw	$v0,%lo(g_Vars+0x4b4)($v0)
/*  f0f38bc:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0f38c0:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f38c4:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0f38c8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f38cc:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0f38d0:	afa40440 */ 	sw	$a0,0x440($sp)
/*  f0f38d4:	1041001d */ 	beq	$v0,$at,.L0f0f394c
/*  f0f38d8:	afa60448 */ 	sw	$a2,0x448($sp)
/*  f0f38dc:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f0f38e0:	1041001a */ 	beq	$v0,$at,.L0f0f394c
/*  f0f38e4:	3c0e800a */ 	lui	$t6,%hi(g_MenuData+0x5d5)
/*  f0f38e8:	81cf1f95 */ 	lb	$t7,%lo(g_MenuData+0x5d5)($t6)
/*  f0f38ec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f38f0:	05e30008 */ 	bgezl	$t7,.L0f0f3914
/*  f0f38f4:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0f38f8:	10c10005 */ 	beq	$a2,$at,.L0f0f3910
/*  f0f38fc:	28c10003 */ 	slti	$at,$a2,0x3
/*  f0f3900:	50200004 */ 	beqzl	$at,.L0f0f3914
/*  f0f3904:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0f3908:	100005b9 */ 	b	.L0f0f4ff0
/*  f0f390c:	00801025 */ 	or	$v0,$a0,$zero
.L0f0f3910:
/*  f0f3910:	8e190004 */ 	lw	$t9,0x4($s0)
.L0f0f3914:
/*  f0f3914:	5720000e */ 	bnezl	$t9,.L0f0f3950
/*  f0f3918:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f0f391c:	0fc27801 */ 	jal	bgun0f09e004
/*  f0f3920:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f3924:	10400007 */ 	beqz	$v0,.L0f0f3944
/*  f0f3928:	00000000 */ 	nop
/*  f0f392c:	0fc2777b */ 	jal	bgunGetGunMem
/*  f0f3930:	00000000 */ 	nop
/*  f0f3934:	0fc2777f */ 	jal	bgunCalculateGunMemCapacity
/*  f0f3938:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0f393c:	10000003 */ 	b	.L0f0f394c
/*  f0f3940:	ae020008 */ 	sw	$v0,0x8($s0)
.L0f0f3944:
/*  f0f3944:	100005aa */ 	b	.L0f0f4ff0
/*  f0f3948:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f394c:
/*  f0f394c:	8e0a0004 */ 	lw	$t2,0x4($s0)
.L0f0f3950:
/*  f0f3950:	55400004 */ 	bnezl	$t2,.L0f0f3964
/*  f0f3954:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f3958:	100005a5 */ 	b	.L0f0f4ff0
/*  f0f395c:	8fa20440 */ 	lw	$v0,0x440($sp)
/*  f0f3960:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f0f3964:
/*  f0f3964:	504000dc */ 	beqzl	$v0,.L0f0f3cd8
/*  f0f3968:	8e0a0054 */ 	lw	$t2,0x54($s0)
/*  f0f396c:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0f3970:	3c014fac */ 	lui	$at,0x4fac
/*  f0f3974:	34215ace */ 	ori	$at,$at,0x5ace
/*  f0f3978:	14620004 */ 	bne	$v1,$v0,.L0f0f398c
/*  f0f397c:	00000000 */ 	nop
/*  f0f3980:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0f3984:	100000d3 */ 	b	.L0f0f3cd4
/*  f0f3988:	a2000000 */ 	sb	$zero,0x0($s0)
.L0f0f398c:
/*  f0f398c:	54610004 */ 	bnel	$v1,$at,.L0f0f39a0
/*  f0f3990:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0f3994:	0fc6709a */ 	jal	mpClearCurrentChallenge
/*  f0f3998:	00000000 */ 	nop
/*  f0f399c:	92020000 */ 	lbu	$v0,0x0($s0)
.L0f0f39a0:
/*  f0f39a0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f39a4:	14400004 */ 	bnez	$v0,.L0f0f39b8
/*  f0f39a8:	244cffff */ 	addiu	$t4,$v0,-1
/*  f0f39ac:	a20b0000 */ 	sb	$t3,0x0($s0)
/*  f0f39b0:	1000058f */ 	b	.L0f0f4ff0
/*  f0f39b4:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f39b8:
/*  f0f39b8:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0f39bc:	15a000c3 */ 	bnez	$t5,.L0f0f3ccc
/*  f0f39c0:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f0f39c4:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f39c8:	3401ffff */ 	dli	$at,0xffff
/*  f0f39cc:	304effff */ 	andi	$t6,$v0,0xffff
/*  f0f39d0:	11c10002 */ 	beq	$t6,$at,.L0f0f39dc
/*  f0f39d4:	00027800 */ 	sll	$t7,$v0,0x0
/*  f0f39d8:	05e10092 */ 	bgez	$t7,.L0f0f3c24
.L0f0f39dc:
/*  f0f39dc:	0002c000 */ 	sll	$t8,$v0,0x0
/*  f0f39e0:	07010008 */ 	bgez	$t8,.L0f0f3a04
/*  f0f39e4:	3c01000f */ 	lui	$at,0xf
/*  f0f39e8:	3421fc00 */ 	ori	$at,$at,0xfc00
/*  f0f39ec:	00415024 */ 	and	$t2,$v0,$at
/*  f0f39f0:	305903ff */ 	andi	$t9,$v0,0x3ff
/*  f0f39f4:	000a5a82 */ 	srl	$t3,$t2,0xa
/*  f0f39f8:	afb90400 */ 	sw	$t9,0x400($sp)
/*  f0f39fc:	1000001a */ 	b	.L0f0f3a68
/*  f0f3a00:	afab0404 */ 	sw	$t3,0x404($sp)
.L0f0f3a04:
/*  f0f3a04:	00028c02 */ 	srl	$s1,$v0,0x10
/*  f0f3a08:	322c00ff */ 	andi	$t4,$s1,0xff
/*  f0f3a0c:	00026e02 */ 	srl	$t5,$v0,0x18
/*  f0f3a10:	01808825 */ 	or	$s1,$t4,$zero
/*  f0f3a14:	0fc62ee4 */ 	jal	mpGetBodyId
/*  f0f3a18:	31a400ff */ 	andi	$a0,$t5,0xff
/*  f0f3a1c:	0fc62ec7 */ 	jal	mpGetNumHeads2
/*  f0f3a20:	afa20404 */ 	sw	$v0,0x404($sp)
/*  f0f3a24:	0222082a */ 	slt	$at,$s1,$v0
/*  f0f3a28:	10200005 */ 	beqz	$at,.L0f0f3a40
/*  f0f3a2c:	00000000 */ 	nop
/*  f0f3a30:	0fc62ecb */ 	jal	mpGetHeadId
/*  f0f3a34:	322400ff */ 	andi	$a0,$s1,0xff
/*  f0f3a38:	1000000b */ 	b	.L0f0f3a68
/*  f0f3a3c:	afa20400 */ 	sw	$v0,0x400($sp)
.L0f0f3a40:
/*  f0f3a40:	0fc62ec7 */ 	jal	mpGetNumHeads2
/*  f0f3a44:	00000000 */ 	nop
/*  f0f3a48:	0fc52a7e */ 	jal	func0f14a9f8
/*  f0f3a4c:	02222023 */ 	subu	$a0,$s1,$v0
/*  f0f3a50:	0fc62ed9 */ 	jal	mpGetBeauHeadId
/*  f0f3a54:	304400ff */ 	andi	$a0,$v0,0xff
/*  f0f3a58:	0fc62ec7 */ 	jal	mpGetNumHeads2
/*  f0f3a5c:	afa20400 */ 	sw	$v0,0x400($sp)
/*  f0f3a60:	02227823 */ 	subu	$t7,$s1,$v0
/*  f0f3a64:	a20f05b0 */ 	sb	$t7,0x5b0($s0)
.L0f0f3a68:
/*  f0f3a68:	8fb80404 */ 	lw	$t8,0x404($sp)
/*  f0f3a6c:	3c0a8008 */ 	lui	$t2,%hi(g_HeadsAndBodies)
/*  f0f3a70:	254acf04 */ 	addiu	$t2,$t2,%lo(g_HeadsAndBodies)
/*  f0f3a74:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f3a78:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f3a7c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f3a80:	032a8821 */ 	addu	$s1,$t9,$t2
/*  f0f3a84:	96220002 */ 	lhu	$v0,0x2($s1)
/*  f0f3a88:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3a8c:	a7a2040a */ 	sh	$v0,0x40a($sp)
/*  f0f3a90:	0fc59c15 */ 	jal	fileGetInflatedLength
/*  f0f3a94:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f0f3a98:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f0f3a9c:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f3aa0:	346b003f */ 	ori	$t3,$v1,0x3f
/*  f0f3aa4:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f0f3aa8:	05e10005 */ 	bgez	$t7,.L0f0f3ac0
/*  f0f3aac:	3963003f */ 	xori	$v1,$t3,0x3f
/*  f0f3ab0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f3ab4:	afb80400 */ 	sw	$t8,0x400($sp)
/*  f0f3ab8:	10000011 */ 	b	.L0f0f3b00
/*  f0f3abc:	3411ffff */ 	dli	$s1,0xffff
.L0f0f3ac0:
/*  f0f3ac0:	8fb90400 */ 	lw	$t9,0x400($sp)
/*  f0f3ac4:	3c118008 */ 	lui	$s1,%hi(g_HeadsAndBodies+0x2)
/*  f0f3ac8:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f3acc:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0f3ad0:	01595021 */ 	addu	$t2,$t2,$t9
/*  f0f3ad4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f3ad8:	022a8821 */ 	addu	$s1,$s1,$t2
/*  f0f3adc:	9631cf06 */ 	lhu	$s1,%lo(g_HeadsAndBodies+0x2)($s1)
/*  f0f3ae0:	0fc59c15 */ 	jal	fileGetInflatedLength
/*  f0f3ae4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f3ae8:	8fab0420 */ 	lw	$t3,0x420($sp)
/*  f0f3aec:	244c003f */ 	addiu	$t4,$v0,0x3f
/*  f0f3af0:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0f3af4:	39ae003f */ 	xori	$t6,$t5,0x3f
/*  f0f3af8:	016e1821 */ 	addu	$v1,$t3,$t6
/*  f0f3afc:	afa30420 */ 	sw	$v1,0x420($sp)
.L0f0f3b00:
/*  f0f3b00:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f3b04:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f0f3b08:	24634000 */ 	addiu	$v1,$v1,0x4000
/*  f0f3b0c:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f3b10:	27a40410 */ 	addiu	$a0,$sp,0x410
/*  f0f3b14:	03032821 */ 	addu	$a1,$t8,$v1
/*  f0f3b18:	0fc5cb9c */ 	jal	func0f172e70
/*  f0f3b1c:	03233023 */ 	subu	$a2,$t9,$v1
/*  f0f3b20:	8faa0400 */ 	lw	$t2,0x400($sp)
/*  f0f3b24:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f0f3b28:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f3b2c:	a60a0002 */ 	sh	$t2,0x2($s0)
/*  f0f3b30:	8fac0404 */ 	lw	$t4,0x404($sp)
/*  f0f3b34:	a60c056a */ 	sh	$t4,0x56a($s0)
/*  f0f3b38:	8fa60420 */ 	lw	$a2,0x420($sp)
/*  f0f3b3c:	0fc69de5 */ 	jal	func0f1a7794
/*  f0f3b40:	97a4040a */ 	lhu	$a0,0x40a($sp)
/*  f0f3b44:	ae020054 */ 	sw	$v0,0x54($s0)
/*  f0f3b48:	0fc59ca0 */ 	jal	fileGetSize
/*  f0f3b4c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f3b50:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f3b54:	346d003f */ 	ori	$t5,$v1,0x3f
/*  f0f3b58:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0f3b5c:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f3b60:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f0f3b64:	afab040c */ 	sw	$t3,0x40c($sp)
/*  f0f3b68:	8fae0400 */ 	lw	$t6,0x400($sp)
/*  f0f3b6c:	8fa3040c */ 	lw	$v1,0x40c($sp)
/*  f0f3b70:	3224ffff */ 	andi	$a0,$s1,0xffff
/*  f0f3b74:	05c10003 */ 	bgez	$t6,.L0f0f3b84
/*  f0f3b78:	8fb80420 */ 	lw	$t8,0x420($sp)
/*  f0f3b7c:	10000010 */ 	b	.L0f0f3bc0
/*  f0f3b80:	ae000058 */ 	sw	$zero,0x58($s0)
.L0f0f3b84:
/*  f0f3b84:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f0f3b88:	afb10040 */ 	sw	$s1,0x40($sp)
/*  f0f3b8c:	03033023 */ 	subu	$a2,$t8,$v1
/*  f0f3b90:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f3b94:	0fc69de5 */ 	jal	func0f1a7794
/*  f0f3b98:	01e32821 */ 	addu	$a1,$t7,$v1
/*  f0f3b9c:	ae020058 */ 	sw	$v0,0x58($s0)
/*  f0f3ba0:	0fc59ca0 */ 	jal	fileGetSize
/*  f0f3ba4:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f3ba8:	8e040058 */ 	lw	$a0,0x58($s0)
/*  f0f3bac:	8fa50400 */ 	lw	$a1,0x400($sp)
/*  f0f3bb0:	0fc0b76f */ 	jal	bodyCalculateHeadOffset
/*  f0f3bb4:	8fa60404 */ 	lw	$a2,0x404($sp)
/*  f0f3bb8:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f0f3bbc:	8e040058 */ 	lw	$a0,0x58($s0)
.L0f0f3bc0:
/*  f0f3bc0:	26040060 */ 	addiu	$a0,$s0,0x60
/*  f0f3bc4:	8e050054 */ 	lw	$a1,0x54($s0)
/*  f0f3bc8:	afa4003c */ 	sw	$a0,0x3c($sp)
/*  f0f3bcc:	26060110 */ 	addiu	$a2,$s0,0x110
/*  f0f3bd0:	0c008be9 */ 	jal	modelInit
/*  f0f3bd4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f3bd8:	26110084 */ 	addiu	$s1,$s0,0x84
/*  f0f3bdc:	0c008c28 */ 	jal	animInit
/*  f0f3be0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f3be4:	24190100 */ 	addiu	$t9,$zero,0x100
/*  f0f3be8:	a6190062 */ 	sh	$t9,0x62($s0)
/*  f0f3bec:	ae110080 */ 	sw	$s1,0x80($s0)
/*  f0f3bf0:	8e060054 */ 	lw	$a2,0x54($s0)
/*  f0f3bf4:	8e070058 */ 	lw	$a3,0x58($s0)
/*  f0f3bf8:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f0f3bfc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f3c00:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f3c04:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f3c08:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0f3c0c:	8fa50400 */ 	lw	$a1,0x400($sp)
/*  f0f3c10:	8fa40404 */ 	lw	$a0,0x404($sp)
/*  f0f3c14:	0fc0b3a3 */ 	jal	func0f02ce8c
/*  f0f3c18:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0f3c1c:	10000027 */ 	b	.L0f0f3cbc
/*  f0f3c20:	8e19000c */ 	lw	$t9,0xc($s0)
.L0f0f3c24:
/*  f0f3c24:	0fc59c15 */ 	jal	fileGetInflatedLength
/*  f0f3c28:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3c2c:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f3c30:	346d003f */ 	ori	$t5,$v1,0x3f
/*  f0f3c34:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0f3c38:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f0f3c3c:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f0f3c40:	25634000 */ 	addiu	$v1,$t3,0x4000
/*  f0f3c44:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f3c48:	27a40410 */ 	addiu	$a0,$sp,0x410
/*  f0f3c4c:	01c32821 */ 	addu	$a1,$t6,$v1
/*  f0f3c50:	0fc5cb9c */ 	jal	func0f172e70
/*  f0f3c54:	01e33023 */ 	subu	$a2,$t7,$v1
/*  f0f3c58:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0f3c5c:	a6020002 */ 	sh	$v0,0x2($s0)
/*  f0f3c60:	a602056a */ 	sh	$v0,0x56a($s0)
/*  f0f3c64:	8fa60420 */ 	lw	$a2,0x420($sp)
/*  f0f3c68:	9604000e */ 	lhu	$a0,0xe($s0)
/*  f0f3c6c:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f0f3c70:	0fc69de5 */ 	jal	func0f1a7794
/*  f0f3c74:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f3c78:	ae020054 */ 	sw	$v0,0x54($s0)
/*  f0f3c7c:	0fc59ca0 */ 	jal	fileGetSize
/*  f0f3c80:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f0f3c84:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f0f3c88:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f3c8c:	26040060 */ 	addiu	$a0,$s0,0x60
/*  f0f3c90:	8e050054 */ 	lw	$a1,0x54($s0)
/*  f0f3c94:	26060110 */ 	addiu	$a2,$s0,0x110
/*  f0f3c98:	0c008be9 */ 	jal	modelInit
/*  f0f3c9c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f3ca0:	26110084 */ 	addiu	$s1,$s0,0x84
/*  f0f3ca4:	0c008c28 */ 	jal	animInit
/*  f0f3ca8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f3cac:	24180100 */ 	addiu	$t8,$zero,0x100
/*  f0f3cb0:	a6180062 */ 	sh	$t8,0x62($s0)
/*  f0f3cb4:	ae110080 */ 	sw	$s1,0x80($s0)
/*  f0f3cb8:	8e19000c */ 	lw	$t9,0xc($s0)
.L0f0f3cbc:
/*  f0f3cbc:	a600005e */ 	sh	$zero,0x5e($s0)
/*  f0f3cc0:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0f3cc4:	10000003 */ 	b	.L0f0f3cd4
/*  f0f3cc8:	ae190010 */ 	sw	$t9,0x10($s0)
.L0f0f3ccc:
/*  f0f3ccc:	100004c8 */ 	b	.L0f0f4ff0
/*  f0f3cd0:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f3cd4:
/*  f0f3cd4:	8e0a0054 */ 	lw	$t2,0x54($s0)
.L0f0f3cd8:
/*  f0f3cd8:	3c0d8007 */ 	lui	$t5,%hi(var80071480)
/*  f0f3cdc:	25ad1480 */ 	addiu	$t5,$t5,%lo(var80071480)
/*  f0f3ce0:	114004c2 */ 	beqz	$t2,.L0f0f4fec
/*  f0f3ce4:	27ac03b8 */ 	addiu	$t4,$sp,0x3b8
/*  f0f3ce8:	25ae003c */ 	addiu	$t6,$t5,0x3c
.L0f0f3cec:
/*  f0f3cec:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0f3cf0:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f0f3cf4:	258c000c */ 	addiu	$t4,$t4,0xc
/*  f0f3cf8:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*  f0f3cfc:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f0f3d00:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*  f0f3d04:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f0f3d08:	15aefff8 */ 	bne	$t5,$t6,.L0f0f3cec
/*  f0f3d0c:	ad81fffc */ 	sw	$at,-0x4($t4)
/*  f0f3d10:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0f3d14:	260f0060 */ 	addiu	$t7,$s0,0x60
/*  f0f3d18:	ad810000 */ 	sw	$at,0x0($t4)
/*  f0f3d1c:	8fb80448 */ 	lw	$t8,0x448($sp)
/*  f0f3d20:	afaf003c */ 	sw	$t7,0x3c($sp)
/*  f0f3d24:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0f3d28:	1020001b */ 	beqz	$at,.L0f0f3d98
/*  f0f3d2c:	3c19800a */ 	lui	$t9,%hi(g_MenuData+0x5d4)
/*  f0f3d30:	8f391f94 */ 	lw	$t9,%lo(g_MenuData+0x5d4)($t9)
/*  f0f3d34:	00195a80 */ 	sll	$t3,$t9,0xa
/*  f0f3d38:	05630018 */ 	bgezl	$t3,.L0f0f3d9c
/*  f0f3d3c:	8faa0440 */ 	lw	$t2,0x440($sp)
/*  f0f3d40:	0c002ca0 */ 	jal	vi0000b280
/*  f0f3d44:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f3d48:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f3d4c:	0c002c74 */ 	jal	vi0000b1d0
/*  f0f3d50:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3d54:	3c0e800a */ 	lui	$t6,%hi(g_MenuData+0x5d5)
/*  f0f3d58:	91ce1f95 */ 	lbu	$t6,%lo(g_MenuData+0x5d5)($t6)
/*  f0f3d5c:	8fac0448 */ 	lw	$t4,0x448($sp)
/*  f0f3d60:	3c01800a */ 	lui	$at,%hi(g_MenuData+0x5d5)
/*  f0f3d64:	31cdffdf */ 	andi	$t5,$t6,0xffdf
/*  f0f3d68:	a02d1f95 */ 	sb	$t5,%lo(g_MenuData+0x5d5)($at)
/*  f0f3d6c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f3d70:	11810003 */ 	beq	$t4,$at,.L0f0f3d80
/*  f0f3d74:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f3d78:	0fc3d43f */ 	jal	menuApplyScissor
/*  f0f3d7c:	00402025 */ 	or	$a0,$v0,$zero
.L0f0f3d80:
/*  f0f3d80:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f0f3d84:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f3d88:	3c18b700 */ 	lui	$t8,0xb700
/*  f0f3d8c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f3d90:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0f3d94:	ac580000 */ 	sw	$t8,0x0($v0)
.L0f0f3d98:
/*  f0f3d98:	8faa0440 */ 	lw	$t2,0x440($sp)
.L0f0f3d9c:
/*  f0f3d9c:	3c0d8006 */ 	lui	$t5,%hi(var80061380)
/*  f0f3da0:	25ad1380 */ 	addiu	$t5,$t5,%lo(var80061380)
/*  f0f3da4:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0f3da8:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f3dac:	3c0e0600 */ 	lui	$t6,0x600
/*  f0f3db0:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f0f3db4:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0f3db8:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f3dbc:	3c180600 */ 	lui	$t8,0x600
/*  f0f3dc0:	3c198006 */ 	lui	$t9,%hi(var800613a0)
/*  f0f3dc4:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f3dc8:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f3dcc:	273913a0 */ 	addiu	$t9,$t9,%lo(var800613a0)
/*  f0f3dd0:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f3dd4:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f0f3dd8:	ad990004 */ 	sw	$t9,0x4($t4)
/*  f0f3ddc:	afa00308 */ 	sw	$zero,0x308($sp)
/*  f0f3de0:	c6060554 */ 	lwc1	$f6,0x554($s0)
/*  f0f3de4:	44802000 */ 	mtc1	$zero,$f4
/*  f0f3de8:	00000000 */ 	nop
/*  f0f3dec:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0f3df0:	00000000 */ 	nop
/*  f0f3df4:	4500005c */ 	bc1f	.L0f0f3f68
/*  f0f3df8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f3dfc:	afaa02f4 */ 	sw	$t2,0x2f4($sp)
/*  f0f3e00:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f3e04:	3c0b8008 */ 	lui	$t3,%hi(g_SkelChr)
/*  f0f3e08:	256bce40 */ 	addiu	$t3,$t3,%lo(g_SkelChr)
/*  f0f3e0c:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f0f3e10:	556e002f */ 	bnel	$t3,$t6,.L0f0f3ed0
/*  f0f3e14:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f0f3e18:	0c006a47 */ 	jal	modelGetPart
/*  f0f3e1c:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f0f3e20:	5040002b */ 	beqzl	$v0,.L0f0f3ed0
/*  f0f3e24:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f0f3e28:	8e0d0574 */ 	lw	$t5,0x574($s0)
/*  f0f3e2c:	3c0143f0 */ 	lui	$at,0x43f0
/*  f0f3e30:	44812000 */ 	mtc1	$at,$f4
/*  f0f3e34:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f3e38:	8c510004 */ 	lw	$s1,0x4($v0)
/*  f0f3e3c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0f3e40:	0fc01af4 */ 	jal	func0f006bd0
/*  f0f3e44:	46045303 */ 	div.s	$f12,$f10,$f4
/*  f0f3e48:	44806000 */ 	mtc1	$zero,$f12
/*  f0f3e4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f3e50:	44817000 */ 	mtc1	$at,$f14
/*  f0f3e54:	3c017f1b */ 	lui	$at,%hi(var7f1b292c)
/*  f0f3e58:	e7ac02fc */ 	swc1	$f12,0x2fc($sp)
/*  f0f3e5c:	c6260004 */ 	lwc1	$f6,0x4($s1)
/*  f0f3e60:	c428292c */ 	lwc1	$f8,%lo(var7f1b292c)($at)
/*  f0f3e64:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0f3e68:	3c014387 */ 	lui	$at,0x4387
/*  f0f3e6c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f3e70:	afac0308 */ 	sw	$t4,0x308($sp)
/*  f0f3e74:	e7ac0304 */ 	swc1	$f12,0x304($sp)
/*  f0f3e78:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0f3e7c:	46047181 */ 	sub.s	$f6,$f14,$f4
/*  f0f3e80:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f3e84:	46007281 */ 	sub.s	$f10,$f14,$f0
/*  f0f3e88:	44813000 */ 	mtc1	$at,$f6
/*  f0f3e8c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0f3e90:	46086101 */ 	sub.s	$f4,$f12,$f8
/*  f0f3e94:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f3e98:	e7a40300 */ 	swc1	$f4,0x300($sp)
/*  f0f3e9c:	44812000 */ 	mtc1	$at,$f4
/*  f0f3ea0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f3ea4:	44813000 */ 	mtc1	$at,$f6
/*  f0f3ea8:	46044080 */ 	add.s	$f2,$f8,$f4
/*  f0f3eac:	e6020554 */ 	swc1	$f2,0x554($s0)
/*  f0f3eb0:	c62a0004 */ 	lwc1	$f10,0x4($s1)
/*  f0f3eb4:	afa002f4 */ 	sw	$zero,0x2f4($sp)
/*  f0f3eb8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f3ebc:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f3ec0:	46081103 */ 	div.s	$f4,$f2,$f8
/*  f0f3ec4:	0fc1a2aa */ 	jal	modelFindBboxRodata
/*  f0f3ec8:	e7a402f8 */ 	swc1	$f4,0x2f8($sp)
/*  f0f3ecc:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
.L0f0f3ed0:
/*  f0f3ed0:	11e00025 */ 	beqz	$t7,.L0f0f3f68
/*  f0f3ed4:	00000000 */ 	nop
/*  f0f3ed8:	0fc1a2aa */ 	jal	modelFindBboxRodata
/*  f0f3edc:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f3ee0:	10400021 */ 	beqz	$v0,.L0f0f3f68
/*  f0f3ee4:	00000000 */ 	nop
/*  f0f3ee8:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0f3eec:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f0f3ef0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f3ef4:	44817000 */ 	mtc1	$at,$f14
/*  f0f3ef8:	460a0181 */ 	sub.s	$f6,$f0,$f10
/*  f0f3efc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f3f00:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0f3f04:	46080101 */ 	sub.s	$f4,$f0,$f8
/*  f0f3f08:	46002287 */ 	neg.s	$f10,$f4
/*  f0f3f0c:	e7aa02fc */ 	swc1	$f10,0x2fc($sp)
/*  f0f3f10:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f0f3f14:	c4420010 */ 	lwc1	$f2,0x10($v0)
/*  f0f3f18:	46061201 */ 	sub.s	$f8,$f2,$f6
/*  f0f3f1c:	460e4102 */ 	mul.s	$f4,$f8,$f14
/*  f0f3f20:	46041281 */ 	sub.s	$f10,$f2,$f4
/*  f0f3f24:	46005187 */ 	neg.s	$f6,$f10
/*  f0f3f28:	e7a60300 */ 	swc1	$f6,0x300($sp)
/*  f0f3f2c:	c4480014 */ 	lwc1	$f8,0x14($v0)
/*  f0f3f30:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f0f3f34:	afb80308 */ 	sw	$t8,0x308($sp)
/*  f0f3f38:	46086101 */ 	sub.s	$f4,$f12,$f8
/*  f0f3f3c:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*  f0f3f40:	460a6181 */ 	sub.s	$f6,$f12,$f10
/*  f0f3f44:	46003207 */ 	neg.s	$f8,$f6
/*  f0f3f48:	e7a80304 */ 	swc1	$f8,0x304($sp)
/*  f0f3f4c:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f0f3f50:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0f3f54:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0f3f58:	c6040554 */ 	lwc1	$f4,0x554($s0)
/*  f0f3f5c:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0f3f60:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f0f3f64:	e7aa02f8 */ 	swc1	$f10,0x2f8($sp)
.L0f0f3f68:
/*  f0f3f68:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0f3f6c:	27a40350 */ 	addiu	$a0,$sp,0x350
/*  f0f3f70:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f3f74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f3f78:	17210083 */ 	bne	$t9,$at,.L0f0f4188
/*  f0f3f7c:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0f3f80:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0f3f84:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f3f88:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f3f8c:	11410130 */ 	beq	$t2,$at,.L0f0f4450
/*  f0f3f90:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f3f94:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f3f98:	c6060510 */ 	lwc1	$f6,0x510($s0)
/*  f0f3f9c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f3fa0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0f3fa4:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0f3fa8:	00000000 */ 	nop
/*  f0f3fac:	45030014 */ 	bc1tl	.L0f0f4000
/*  f0f3fb0:	c60c053c */ 	lwc1	$f12,0x53c($s0)
/*  f0f3fb4:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f0f3fb8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f3fbc:	3c017f1b */ 	lui	$at,%hi(var7f1b2930)
/*  f0f3fc0:	5960000f */ 	blezl	$t3,.L0f0f4000
/*  f0f3fc4:	c60c053c */ 	lwc1	$f12,0x53c($s0)
/*  f0f3fc8:	c4242930 */ 	lwc1	$f4,%lo(var7f1b2930)($at)
/*  f0f3fcc:	3c017f1b */ 	lui	$at,%hi(var7f1b2934)
/*  f0f3fd0:	46040082 */ 	mul.s	$f2,$f0,$f4
/*  f0f3fd4:	c4202934 */ 	lwc1	$f0,%lo(var7f1b2934)($at)
/*  f0f3fd8:	c6080510 */ 	lwc1	$f8,0x510($s0)
.L0f0f3fdc:
/*  f0f3fdc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f3fe0:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0f3fe4:	460a1180 */ 	add.s	$f6,$f2,$f10
/*  f0f3fe8:	e6060510 */ 	swc1	$f6,0x510($s0)
/*  f0f3fec:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0f3ff0:	004e082a */ 	slt	$at,$v0,$t6
/*  f0f3ff4:	5420fff9 */ 	bnezl	$at,.L0f0f3fdc
/*  f0f3ff8:	c6080510 */ 	lwc1	$f8,0x510($s0)
/*  f0f3ffc:	c60c053c */ 	lwc1	$f12,0x53c($s0)
.L0f0f4000:
/*  f0f4000:	c6040514 */ 	lwc1	$f4,0x514($s0)
/*  f0f4004:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f4008:	3c017f1b */ 	lui	$at,%hi(var7f1b2938)
/*  f0f400c:	46046032 */ 	c.eq.s	$f12,$f4
/*  f0f4010:	c4202938 */ 	lwc1	$f0,%lo(var7f1b2938)($at)
/*  f0f4014:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0f4018:	3c0b8007 */ 	lui	$t3,%hi(g_ViRes)
/*  f0f401c:	45030013 */ 	bc1tl	.L0f0f406c
/*  f0f4020:	c60c0540 */ 	lwc1	$f12,0x540($s0)
/*  f0f4024:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f4028:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f402c:	3c017f1b */ 	lui	$at,%hi(var7f1b293c)
/*  f0f4030:	59a0000e */ 	blezl	$t5,.L0f0f406c
/*  f0f4034:	c60c0540 */ 	lwc1	$f12,0x540($s0)
/*  f0f4038:	c428293c */ 	lwc1	$f8,%lo(var7f1b293c)($at)
/*  f0f403c:	46086082 */ 	mul.s	$f2,$f12,$f8
/*  f0f4040:	00000000 */ 	nop
/*  f0f4044:	c60a0514 */ 	lwc1	$f10,0x514($s0)
.L0f0f4048:
/*  f0f4048:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f404c:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0f4050:	46061100 */ 	add.s	$f4,$f2,$f6
/*  f0f4054:	e6040514 */ 	swc1	$f4,0x514($s0)
/*  f0f4058:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f405c:	004c082a */ 	slt	$at,$v0,$t4
/*  f0f4060:	5420fff9 */ 	bnezl	$at,.L0f0f4048
/*  f0f4064:	c60a0514 */ 	lwc1	$f10,0x514($s0)
/*  f0f4068:	c60c0540 */ 	lwc1	$f12,0x540($s0)
.L0f0f406c:
/*  f0f406c:	c6080518 */ 	lwc1	$f8,0x518($s0)
/*  f0f4070:	46086032 */ 	c.eq.s	$f12,$f8
/*  f0f4074:	00000000 */ 	nop
/*  f0f4078:	45030013 */ 	bc1tl	.L0f0f40c8
/*  f0f407c:	c60c0544 */ 	lwc1	$f12,0x544($s0)
/*  f0f4080:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0f4084:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f4088:	3c017f1b */ 	lui	$at,%hi(var7f1b2940)
/*  f0f408c:	59e0000e */ 	blezl	$t7,.L0f0f40c8
/*  f0f4090:	c60c0544 */ 	lwc1	$f12,0x544($s0)
/*  f0f4094:	c42a2940 */ 	lwc1	$f10,%lo(var7f1b2940)($at)
/*  f0f4098:	460a6082 */ 	mul.s	$f2,$f12,$f10
/*  f0f409c:	00000000 */ 	nop
/*  f0f40a0:	c6060518 */ 	lwc1	$f6,0x518($s0)
.L0f0f40a4:
/*  f0f40a4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f40a8:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f40ac:	46041200 */ 	add.s	$f8,$f2,$f4
/*  f0f40b0:	e6080518 */ 	swc1	$f8,0x518($s0)
/*  f0f40b4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0f40b8:	0058082a */ 	slt	$at,$v0,$t8
/*  f0f40bc:	5420fff9 */ 	bnezl	$at,.L0f0f40a4
/*  f0f40c0:	c6060518 */ 	lwc1	$f6,0x518($s0)
/*  f0f40c4:	c60c0544 */ 	lwc1	$f12,0x544($s0)
.L0f0f40c8:
/*  f0f40c8:	c60e051c */ 	lwc1	$f14,0x51c($s0)
/*  f0f40cc:	460e6032 */ 	c.eq.s	$f12,$f14
/*  f0f40d0:	00000000 */ 	nop
/*  f0f40d4:	45030014 */ 	bc1tl	.L0f0f4128
/*  f0f40d8:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f40dc:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f40e0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f40e4:	3c017f1b */ 	lui	$at,%hi(var7f1b2944)
/*  f0f40e8:	5b20000f */ 	blezl	$t9,.L0f0f4128
/*  f0f40ec:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f40f0:	c42a2944 */ 	lwc1	$f10,%lo(var7f1b2944)($at)
/*  f0f40f4:	460a6082 */ 	mul.s	$f2,$f12,$f10
/*  f0f40f8:	00000000 */ 	nop
/*  f0f40fc:	c606051c */ 	lwc1	$f6,0x51c($s0)
.L0f0f4100:
/*  f0f4100:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f4104:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f4108:	46041200 */ 	add.s	$f8,$f2,$f4
/*  f0f410c:	e608051c */ 	swc1	$f8,0x51c($s0)
/*  f0f4110:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0f4114:	004a082a */ 	slt	$at,$v0,$t2
/*  f0f4118:	5420fff9 */ 	bnezl	$at,.L0f0f4100
/*  f0f411c:	c606051c */ 	lwc1	$f6,0x51c($s0)
/*  f0f4120:	c60e051c */ 	lwc1	$f14,0x51c($s0)
/*  f0f4124:	c60a0510 */ 	lwc1	$f10,0x510($s0)
.L0f0f4128:
/*  f0f4128:	8d6b06c8 */ 	lw	$t3,%lo(g_ViRes)($t3)
/*  f0f412c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f4130:	e7aa0430 */ 	swc1	$f10,0x430($sp)
/*  f0f4134:	c6120518 */ 	lwc1	$f18,0x518($s0)
/*  f0f4138:	15610004 */ 	bne	$t3,$at,.L0f0f414c
/*  f0f413c:	c6100514 */ 	lwc1	$f16,0x514($s0)
/*  f0f4140:	c7a60430 */ 	lwc1	$f6,0x430($sp)
/*  f0f4144:	46063100 */ 	add.s	$f4,$f6,$f6
/*  f0f4148:	e7a40430 */ 	swc1	$f4,0x430($sp)
.L0f0f414c:
/*  f0f414c:	e7b0042c */ 	swc1	$f16,0x42c($sp)
/*  f0f4150:	e7b20428 */ 	swc1	$f18,0x428($sp)
/*  f0f4154:	e7ae0424 */ 	swc1	$f14,0x424($sp)
/*  f0f4158:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f415c:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f4160:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f4164:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f4168:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f416c:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f4170:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f4174:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f4178:	0c005923 */ 	jal	mtx4LoadRotation
/*  f0f417c:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
/*  f0f4180:	100000b4 */ 	b	.L0f0f4454
/*  f0f4184:	3c01c2c8 */ 	lui	$at,0xc2c8
.L0f0f4188:
/*  f0f4188:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f418c:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4)
/*  f0f4190:	00027300 */ 	sll	$t6,$v0,0xc
/*  f0f4194:	000e17c2 */ 	srl	$v0,$t6,0x1f
/*  f0f4198:	10400093 */ 	beqz	$v0,.L0f0f43e8
/*  f0f419c:	00000000 */ 	nop
/*  f0f41a0:	c4289fc4 */ 	lwc1	$f8,%lo(g_Vars+0x4)($at)
/*  f0f41a4:	3c014220 */ 	lui	$at,0x4220
/*  f0f41a8:	44815000 */ 	mtc1	$at,$f10
/*  f0f41ac:	c6040564 */ 	lwc1	$f4,0x564($s0)
/*  f0f41b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f41b4:	460a4183 */ 	div.s	$f6,$f8,$f10
/*  f0f41b8:	44815000 */ 	mtc1	$at,$f10
/*  f0f41bc:	3c017f1b */ 	lui	$at,%hi(var7f1b2948)
/*  f0f41c0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0f41c4:	e6080564 */ 	swc1	$f8,0x564($s0)
/*  f0f41c8:	c6000564 */ 	lwc1	$f0,0x564($s0)
/*  f0f41cc:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0f41d0:	00000000 */ 	nop
/*  f0f41d4:	45000010 */ 	bc1f	.L0f0f4218
/*  f0f41d8:	00000000 */ 	nop
/*  f0f41dc:	920c05b1 */ 	lbu	$t4,0x5b1($s0)
/*  f0f41e0:	c6040538 */ 	lwc1	$f4,0x538($s0)
/*  f0f41e4:	c606053c */ 	lwc1	$f6,0x53c($s0)
/*  f0f41e8:	318ffff7 */ 	andi	$t7,$t4,0xfff7
/*  f0f41ec:	a20f05b1 */ 	sb	$t7,0x5b1($s0)
/*  f0f41f0:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f41f4:	c6080540 */ 	lwc1	$f8,0x540($s0)
/*  f0f41f8:	c60a0544 */ 	lwc1	$f10,0x544($s0)
/*  f0f41fc:	0002c300 */ 	sll	$t8,$v0,0xc
/*  f0f4200:	001817c2 */ 	srl	$v0,$t8,0x1f
/*  f0f4204:	e6040510 */ 	swc1	$f4,0x510($s0)
/*  f0f4208:	e6060514 */ 	swc1	$f6,0x514($s0)
/*  f0f420c:	e6080518 */ 	swc1	$f8,0x518($s0)
/*  f0f4210:	10000075 */ 	b	.L0f0f43e8
/*  f0f4214:	e60a051c */ 	swc1	$f10,0x51c($s0)
.L0f0f4218:
/*  f0f4218:	c4242948 */ 	lwc1	$f4,%lo(var7f1b2948)($at)
/*  f0f421c:	46040302 */ 	mul.s	$f12,$f0,$f4
/*  f0f4220:	0c0068f4 */ 	jal	cosf
/*  f0f4224:	00000000 */ 	nop
/*  f0f4228:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f422c:	44814000 */ 	mtc1	$at,$f8
/*  f0f4230:	46000187 */ 	neg.s	$f6,$f0
/*  f0f4234:	44812000 */ 	mtc1	$at,$f4
/*  f0f4238:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0f423c:	92020568 */ 	lbu	$v0,0x568($s0)
/*  f0f4240:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f4244:	44813000 */ 	mtc1	$at,$f6
/*  f0f4248:	304a0002 */ 	andi	$t2,$v0,0x2
/*  f0f424c:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f4250:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f4254:	46045080 */ 	add.s	$f2,$f10,$f4
/*  f0f4258:	46001386 */ 	mov.s	$f14,$f2
/*  f0f425c:	11400017 */ 	beqz	$t2,.L0f0f42bc
/*  f0f4260:	46023301 */ 	sub.s	$f12,$f6,$f2
/*  f0f4264:	c6080510 */ 	lwc1	$f8,0x510($s0)
/*  f0f4268:	c6040538 */ 	lwc1	$f4,0x538($s0)
/*  f0f426c:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0f4270:	00000000 */ 	nop
/*  f0f4274:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f0f4278:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0f427c:	e7a80430 */ 	swc1	$f8,0x430($sp)
/*  f0f4280:	c6040514 */ 	lwc1	$f4,0x514($s0)
/*  f0f4284:	c606053c */ 	lwc1	$f6,0x53c($s0)
/*  f0f4288:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0f428c:	00000000 */ 	nop
/*  f0f4290:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0f4294:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0f4298:	e7a4042c */ 	swc1	$f4,0x42c($sp)
/*  f0f429c:	c6060518 */ 	lwc1	$f6,0x518($s0)
/*  f0f42a0:	c6080540 */ 	lwc1	$f8,0x540($s0)
/*  f0f42a4:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f0f42a8:	00000000 */ 	nop
/*  f0f42ac:	46081102 */ 	mul.s	$f4,$f2,$f8
/*  f0f42b0:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0f42b4:	1000000b */ 	b	.L0f0f42e4
/*  f0f42b8:	e7a60428 */ 	swc1	$f6,0x428($sp)
.L0f0f42bc:
/*  f0f42bc:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f42c0:	e6000510 */ 	swc1	$f0,0x510($s0)
/*  f0f42c4:	e7a00430 */ 	swc1	$f0,0x430($sp)
/*  f0f42c8:	c600053c */ 	lwc1	$f0,0x53c($s0)
/*  f0f42cc:	e6000514 */ 	swc1	$f0,0x514($s0)
/*  f0f42d0:	e7a0042c */ 	swc1	$f0,0x42c($sp)
/*  f0f42d4:	c6000540 */ 	lwc1	$f0,0x540($s0)
/*  f0f42d8:	e6000518 */ 	swc1	$f0,0x518($s0)
/*  f0f42dc:	e7a00428 */ 	swc1	$f0,0x428($sp)
/*  f0f42e0:	92020568 */ 	lbu	$v0,0x568($s0)
.L0f0f42e4:
/*  f0f42e4:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f0f42e8:	5160000a */ 	beqzl	$t3,.L0f0f4314
/*  f0f42ec:	c6000544 */ 	lwc1	$f0,0x544($s0)
/*  f0f42f0:	c608051c */ 	lwc1	$f8,0x51c($s0)
/*  f0f42f4:	c6040544 */ 	lwc1	$f4,0x544($s0)
/*  f0f42f8:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0f42fc:	00000000 */ 	nop
/*  f0f4300:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f0f4304:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0f4308:	10000005 */ 	b	.L0f0f4320
/*  f0f430c:	e7a80424 */ 	swc1	$f8,0x424($sp)
/*  f0f4310:	c6000544 */ 	lwc1	$f0,0x544($s0)
.L0f0f4314:
/*  f0f4314:	e600051c */ 	swc1	$f0,0x51c($s0)
/*  f0f4318:	e7a00424 */ 	swc1	$f0,0x424($sp)
/*  f0f431c:	92020568 */ 	lbu	$v0,0x568($s0)
.L0f0f4320:
/*  f0f4320:	304e0004 */ 	andi	$t6,$v0,0x4
/*  f0f4324:	51c00024 */ 	beqzl	$t6,.L0f0f43b8
/*  f0f4328:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f432c:	c6040520 */ 	lwc1	$f4,0x520($s0)
/*  f0f4330:	27b10290 */ 	addiu	$s1,$sp,0x290
/*  f0f4334:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f4338:	e7a40290 */ 	swc1	$f4,0x290($sp)
/*  f0f433c:	c60a0524 */ 	lwc1	$f10,0x524($s0)
/*  f0f4340:	27a502bc */ 	addiu	$a1,$sp,0x2bc
/*  f0f4344:	e7aa0294 */ 	swc1	$f10,0x294($sp)
/*  f0f4348:	c6060528 */ 	lwc1	$f6,0x528($s0)
/*  f0f434c:	e7ae02d0 */ 	swc1	$f14,0x2d0($sp)
/*  f0f4350:	0fc25b28 */ 	jal	func0f096ca0
/*  f0f4354:	e7a60298 */ 	swc1	$f6,0x298($sp)
/*  f0f4358:	c6080548 */ 	lwc1	$f8,0x548($s0)
/*  f0f435c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f4360:	27a502ac */ 	addiu	$a1,$sp,0x2ac
/*  f0f4364:	e7a80290 */ 	swc1	$f8,0x290($sp)
/*  f0f4368:	c604054c */ 	lwc1	$f4,0x54c($s0)
/*  f0f436c:	e7a40294 */ 	swc1	$f4,0x294($sp)
/*  f0f4370:	c60a0550 */ 	lwc1	$f10,0x550($s0)
/*  f0f4374:	0fc25b28 */ 	jal	func0f096ca0
/*  f0f4378:	e7aa0298 */ 	swc1	$f10,0x298($sp)
/*  f0f437c:	c7ae02d0 */ 	lwc1	$f14,0x2d0($sp)
/*  f0f4380:	27b1029c */ 	addiu	$s1,$sp,0x29c
/*  f0f4384:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f4388:	44067000 */ 	mfc1	$a2,$f14
/*  f0f438c:	27a402bc */ 	addiu	$a0,$sp,0x2bc
/*  f0f4390:	0fc25cae */ 	jal	func0f0972b8
/*  f0f4394:	27a502ac */ 	addiu	$a1,$sp,0x2ac
/*  f0f4398:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f439c:	0fc25bb5 */ 	jal	func0f096ed4
/*  f0f43a0:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f43a4:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f43a8:	00026b00 */ 	sll	$t5,$v0,0xc
/*  f0f43ac:	1000000e */ 	b	.L0f0f43e8
/*  f0f43b0:	000d17c2 */ 	srl	$v0,$t5,0x1f
/*  f0f43b4:	c6020548 */ 	lwc1	$f2,0x548($s0)
.L0f0f43b8:
/*  f0f43b8:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f43bc:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f43c0:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f43c4:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f43c8:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f43cc:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f43d0:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f43d4:	0c005923 */ 	jal	mtx4LoadRotation
/*  f0f43d8:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
/*  f0f43dc:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f43e0:	00027b00 */ 	sll	$t7,$v0,0xc
/*  f0f43e4:	000f17c2 */ 	srl	$v0,$t7,0x1f
.L0f0f43e8:
/*  f0f43e8:	5440001a */ 	bnezl	$v0,.L0f0f4454
/*  f0f43ec:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f0f43f0:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f43f4:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f43f8:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f43fc:	e6000510 */ 	swc1	$f0,0x510($s0)
/*  f0f4400:	e7a00430 */ 	swc1	$f0,0x430($sp)
/*  f0f4404:	c600053c */ 	lwc1	$f0,0x53c($s0)
/*  f0f4408:	e6000514 */ 	swc1	$f0,0x514($s0)
/*  f0f440c:	e7a0042c */ 	swc1	$f0,0x42c($sp)
/*  f0f4410:	c6000540 */ 	lwc1	$f0,0x540($s0)
/*  f0f4414:	e6000518 */ 	swc1	$f0,0x518($s0)
/*  f0f4418:	e7a00428 */ 	swc1	$f0,0x428($sp)
/*  f0f441c:	c6000544 */ 	lwc1	$f0,0x544($s0)
/*  f0f4420:	e600051c */ 	swc1	$f0,0x51c($s0)
/*  f0f4424:	e7a00424 */ 	swc1	$f0,0x424($sp)
/*  f0f4428:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f442c:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f4430:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f4434:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f4438:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f443c:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f4440:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f4444:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f4448:	0c005923 */ 	jal	mtx4LoadRotation
/*  f0f444c:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
.L0f0f4450:
/*  f0f4450:	3c01c2c8 */ 	lui	$at,0xc2c8
.L0f0f4454:
/*  f0f4454:	44813000 */ 	mtc1	$at,$f6
/*  f0f4458:	c7a80428 */ 	lwc1	$f8,0x428($sp)
/*  f0f445c:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f4460:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f4464:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0f4468:	17210011 */ 	bne	$t9,$at,.L0f0f44b0
/*  f0f446c:	e7a4030c */ 	swc1	$f4,0x30c($sp)
/*  f0f4470:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0f4474:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0f4478:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f447c:	3c0b8008 */ 	lui	$t3,%hi(g_ScaleX)
/*  f0f4480:	51410035 */ 	beql	$t2,$at,.L0f0f4558
/*  f0f4484:	27a40390 */ 	addiu	$a0,$sp,0x390
/*  f0f4488:	8d6bfac0 */ 	lw	$t3,%lo(g_ScaleX)($t3)
/*  f0f448c:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f4490:	448b3000 */ 	mtc1	$t3,$f6
/*  f0f4494:	00000000 */ 	nop
/*  f0f4498:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f449c:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0f44a0:	e7a40390 */ 	swc1	$f4,0x390($sp)
/*  f0f44a4:	c6060514 */ 	lwc1	$f6,0x514($s0)
/*  f0f44a8:	1000002a */ 	b	.L0f0f4554
/*  f0f44ac:	e7a60394 */ 	swc1	$f6,0x394($sp)
.L0f0f44b0:
/*  f0f44b0:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f44b4:	00000000 */ 	nop
/*  f0f44b8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f44bc:	00117403 */ 	sra	$t6,$s1,0x10
/*  f0f44c0:	0c002f22 */ 	jal	viGetViewWidth
/*  f0f44c4:	01c08825 */ 	or	$s1,$t6,$zero
/*  f0f44c8:	44825000 */ 	mtc1	$v0,$f10
/*  f0f44cc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f44d0:	44812000 */ 	mtc1	$at,$f4
/*  f0f44d4:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0f44d8:	3c0d8008 */ 	lui	$t5,%hi(g_ScaleX)
/*  f0f44dc:	8dadfac0 */ 	lw	$t5,%lo(g_ScaleX)($t5)
/*  f0f44e0:	c7aa0430 */ 	lwc1	$f10,0x430($sp)
/*  f0f44e4:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0f44e8:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f44ec:	00000000 */ 	nop
/*  f0f44f0:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0f44f4:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f0f44f8:	44915000 */ 	mtc1	$s1,$f10
/*  f0f44fc:	00000000 */ 	nop
/*  f0f4500:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0f4504:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0f4508:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0f450c:	0c002f44 */ 	jal	viGetViewTop
/*  f0f4510:	e7a80390 */ 	swc1	$f8,0x390($sp)
/*  f0f4514:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f4518:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0f451c:	0c002f26 */ 	jal	viGetViewHeight
/*  f0f4520:	01808825 */ 	or	$s1,$t4,$zero
/*  f0f4524:	44822000 */ 	mtc1	$v0,$f4
/*  f0f4528:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f452c:	44815000 */ 	mtc1	$at,$f10
/*  f0f4530:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f4534:	c7a4042c */ 	lwc1	$f4,0x42c($sp)
/*  f0f4538:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0f453c:	44913000 */ 	mtc1	$s1,$f6
/*  f0f4540:	00000000 */ 	nop
/*  f0f4544:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0f4548:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0f454c:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0f4550:	e7a40394 */ 	swc1	$f4,0x394($sp)
.L0f0f4554:
/*  f0f4554:	27a40390 */ 	addiu	$a0,$sp,0x390
.L0f0f4558:
/*  f0f4558:	27a50398 */ 	addiu	$a1,$sp,0x398
/*  f0f455c:	0fc2d30f */ 	jal	func0f0b4c3c
/*  f0f4560:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0f4564:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0f4568:	27a40310 */ 	addiu	$a0,$sp,0x310
/*  f0f456c:	8e0205b4 */ 	lw	$v0,0x5b4($s0)
/*  f0f4570:	5040001d */ 	beqzl	$v0,.L0f0f45e8
/*  f0f4574:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f4578:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f0f457c:	241100ff */ 	addiu	$s1,$zero,0xff
/*  f0f4580:	00401825 */ 	or	$v1,$v0,$zero
/*  f0f4584:	52250018 */ 	beql	$s1,$a1,.L0f0f45e8
/*  f0f4588:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f458c:	8e040054 */ 	lw	$a0,0x54($s0)
.L0f0f4590:
/*  f0f4590:	0c006a47 */ 	jal	modelGetPart
/*  f0f4594:	afa3028c */ 	sw	$v1,0x28c($sp)
/*  f0f4598:	8fa3028c */ 	lw	$v1,0x28c($sp)
/*  f0f459c:	1040000d */ 	beqz	$v0,.L0f0f45d4
/*  f0f45a0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0f45a4:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f45a8:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0f45ac:	afa3028c */ 	sw	$v1,0x28c($sp)
/*  f0f45b0:	10400008 */ 	beqz	$v0,.L0f0f45d4
/*  f0f45b4:	8fa3028c */ 	lw	$v1,0x28c($sp)
/*  f0f45b8:	906f0001 */ 	lbu	$t7,0x1($v1)
/*  f0f45bc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f45c0:	51e00004 */ 	beqzl	$t7,.L0f0f45d4
/*  f0f45c4:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0f45c8:	10000002 */ 	b	.L0f0f45d4
/*  f0f45cc:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0f45d0:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f0f45d4:
/*  f0f45d4:	90650002 */ 	lbu	$a1,0x2($v1)
/*  f0f45d8:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0f45dc:	5625ffec */ 	bnel	$s1,$a1,.L0f0f4590
/*  f0f45e0:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f45e4:	8fb90448 */ 	lw	$t9,0x448($sp)
.L0f0f45e8:
/*  f0f45e8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f45ec:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f45f0:	57210009 */ 	bnel	$t9,$at,.L0f0f4618
/*  f0f45f4:	c7a203a0 */ 	lwc1	$f2,0x3a0($sp)
/*  f0f45f8:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f45fc:	e7aa0398 */ 	swc1	$f10,0x398($sp)
/*  f0f4600:	c6080514 */ 	lwc1	$f8,0x514($s0)
/*  f0f4604:	e7a8039c */ 	swc1	$f8,0x39c($sp)
/*  f0f4608:	c6060518 */ 	lwc1	$f6,0x518($s0)
/*  f0f460c:	1000000e */ 	b	.L0f0f4648
/*  f0f4610:	e7a603a0 */ 	swc1	$f6,0x3a0($sp)
/*  f0f4614:	c7a203a0 */ 	lwc1	$f2,0x3a0($sp)
.L0f0f4618:
/*  f0f4618:	c7a4030c */ 	lwc1	$f4,0x30c($sp)
/*  f0f461c:	c7aa0398 */ 	lwc1	$f10,0x398($sp)
/*  f0f4620:	c7a6039c */ 	lwc1	$f6,0x39c($sp)
/*  f0f4624:	46022003 */ 	div.s	$f0,$f4,$f2
/*  f0f4628:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0f462c:	00000000 */ 	nop
/*  f0f4630:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f4634:	00000000 */ 	nop
/*  f0f4638:	46020082 */ 	mul.s	$f2,$f0,$f2
/*  f0f463c:	e7a80398 */ 	swc1	$f8,0x398($sp)
/*  f0f4640:	e7a4039c */ 	swc1	$f4,0x39c($sp)
/*  f0f4644:	e7a203a0 */ 	swc1	$f2,0x3a0($sp)
.L0f0f4648:
/*  f0f4648:	0c0059b7 */ 	jal	mtx4LoadTranslation
/*  f0f464c:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4650:	8faa0308 */ 	lw	$t2,0x308($sp)
/*  f0f4654:	5140000a */ 	beqzl	$t2,.L0f0f4680
/*  f0f4658:	c7ac0424 */ 	lwc1	$f12,0x424($sp)
/*  f0f465c:	c7aa0424 */ 	lwc1	$f10,0x424($sp)
/*  f0f4660:	c7a802f8 */ 	lwc1	$f8,0x2f8($sp)
/*  f0f4664:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4668:	46085302 */ 	mul.s	$f12,$f10,$f8
/*  f0f466c:	0c0057c1 */ 	jal	mtx00015f04
/*  f0f4670:	00000000 */ 	nop
/*  f0f4674:	10000005 */ 	b	.L0f0f468c
/*  f0f4678:	8fab0308 */ 	lw	$t3,0x308($sp)
/*  f0f467c:	c7ac0424 */ 	lwc1	$f12,0x424($sp)
.L0f0f4680:
/*  f0f4680:	0c0057c1 */ 	jal	mtx00015f04
/*  f0f4684:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4688:	8fab0308 */ 	lw	$t3,0x308($sp)
.L0f0f468c:
/*  f0f468c:	11600005 */ 	beqz	$t3,.L0f0f46a4
/*  f0f4690:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0f4694:	0c0059b7 */ 	jal	mtx4LoadTranslation
/*  f0f4698:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f469c:	1000000b */ 	b	.L0f0f46cc
/*  f0f46a0:	27b10244 */ 	addiu	$s1,$sp,0x244
.L0f0f46a4:
/*  f0f46a4:	c606052c */ 	lwc1	$f6,0x52c($s0)
/*  f0f46a8:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f46ac:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f46b0:	e7a60398 */ 	swc1	$f6,0x398($sp)
/*  f0f46b4:	c6040530 */ 	lwc1	$f4,0x530($s0)
/*  f0f46b8:	e7a4039c */ 	swc1	$f4,0x39c($sp)
/*  f0f46bc:	c60a0534 */ 	lwc1	$f10,0x534($s0)
/*  f0f46c0:	0c0059b7 */ 	jal	mtx4LoadTranslation
/*  f0f46c4:	e7aa03a0 */ 	swc1	$f10,0x3a0($sp)
/*  f0f46c8:	27b10244 */ 	addiu	$s1,$sp,0x244
.L0f0f46cc:
/*  f0f46cc:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f46d0:	27a40310 */ 	addiu	$a0,$sp,0x310
/*  f0f46d4:	0c005680 */ 	jal	mtx4MultMtx4
/*  f0f46d8:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f46dc:	8fae0448 */ 	lw	$t6,0x448($sp)
/*  f0f46e0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f46e4:	55c1000f */ 	bnel	$t6,$at,.L0f0f4724
/*  f0f46e8:	26060014 */ 	addiu	$a2,$s0,0x14
/*  f0f46ec:	0fc4eb81 */ 	jal	func0f13ae04
/*  f0f46f0:	27a401c4 */ 	addiu	$a0,$sp,0x1c4
/*  f0f46f4:	27a401c4 */ 	addiu	$a0,$sp,0x1c4
/*  f0f46f8:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f46fc:	0c005680 */ 	jal	mtx4MultMtx4
/*  f0f4700:	27a60184 */ 	addiu	$a2,$sp,0x184
/*  f0f4704:	26060014 */ 	addiu	$a2,$s0,0x14
/*  f0f4708:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0f470c:	27a40184 */ 	addiu	$a0,$sp,0x184
/*  f0f4710:	0c005680 */ 	jal	mtx4MultMtx4
/*  f0f4714:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f4718:	10000006 */ 	b	.L0f0f4734
/*  f0f471c:	00000000 */ 	nop
/*  f0f4720:	26060014 */ 	addiu	$a2,$s0,0x14
.L0f0f4724:
/*  f0f4724:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0f4728:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f472c:	0c005680 */ 	jal	mtx4MultMtx4
/*  f0f4730:	27a50204 */ 	addiu	$a1,$sp,0x204
.L0f0f4734:
/*  f0f4734:	0fc388d2 */ 	jal	func0f0e2348
/*  f0f4738:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f473c:	8fad0448 */ 	lw	$t5,0x448($sp)
/*  f0f4740:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4744:	29a10003 */ 	slti	$at,$t5,0x3
/*  f0f4748:	5020006f */ 	beqzl	$at,.L0f0f4908
/*  f0f474c:	8e0a0054 */ 	lw	$t2,0x54($s0)
/*  f0f4750:	11a0000e */ 	beqz	$t5,.L0f0f478c
/*  f0f4754:	3c11800a */ 	lui	$s1,%hi(g_MenuScissorX1)
/*  f0f4758:	0fc35272 */ 	jal	func0f0d49c8
/*  f0f475c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4760:	244c0008 */ 	addiu	$t4,$v0,0x8
/*  f0f4764:	3c0f0103 */ 	lui	$t7,0x103
/*  f0f4768:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f0f476c:	afac0440 */ 	sw	$t4,0x440($sp)
/*  f0f4770:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0f4774:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f0f4778:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f477c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0f4780:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4784:	1000005f */ 	b	.L0f0f4904
/*  f0f4788:	ae220004 */ 	sw	$v0,0x4($s1)
.L0f0f478c:
/*  f0f478c:	26312038 */ 	addiu	$s1,$s1,%lo(g_MenuScissorX1)
/*  f0f4790:	3c18800a */ 	lui	$t8,%hi(g_MenuScissorX2)
/*  f0f4794:	3c0b800a */ 	lui	$t3,%hi(g_MenuScissorY2)
/*  f0f4798:	3c0e800a */ 	lui	$t6,%hi(g_MenuScissorY1)
/*  f0f479c:	8dce2040 */ 	lw	$t6,%lo(g_MenuScissorY1)($t6)
/*  f0f47a0:	8d6b2044 */ 	lw	$t3,%lo(g_MenuScissorY2)($t3)
/*  f0f47a4:	8f18203c */ 	lw	$t8,%lo(g_MenuScissorX2)($t8)
/*  f0f47a8:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f0f47ac:	016e6823 */ 	subu	$t5,$t3,$t6
/*  f0f47b0:	448d2000 */ 	mtc1	$t5,$f4
/*  f0f47b4:	03195023 */ 	subu	$t2,$t8,$t9
/*  f0f47b8:	448a4000 */ 	mtc1	$t2,$f8
/*  f0f47bc:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0f47c0:	3c047f1b */ 	lui	$a0,%hi(var7f1b25f0)
/*  f0f47c4:	3c058007 */ 	lui	$a1,%hi(var800714c0)
/*  f0f47c8:	24a514c0 */ 	addiu	$a1,$a1,%lo(var800714c0)
/*  f0f47cc:	248425f0 */ 	addiu	$a0,$a0,%lo(var7f1b25f0)
/*  f0f47d0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0f47d4:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f0f47d8:	0c0036cc */ 	jal	mainOverrideVariable
/*  f0f47dc:	e7a8017c */ 	swc1	$f8,0x17c($sp)
/*  f0f47e0:	3c047f1b */ 	lui	$a0,%hi(var7f1b25f4)
/*  f0f47e4:	3c058007 */ 	lui	$a1,%hi(var800714c4)
/*  f0f47e8:	24a514c4 */ 	addiu	$a1,$a1,%lo(var800714c4)
/*  f0f47ec:	0c0036cc */ 	jal	mainOverrideVariable
/*  f0f47f0:	248425f4 */ 	addiu	$a0,$a0,%lo(var7f1b25f4)
/*  f0f47f4:	0fc35272 */ 	jal	func0f0d49c8
/*  f0f47f8:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f47fc:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f0f4800:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f0f4804:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f0f4808:	3c05800a */ 	lui	$a1,%hi(g_MenuScissorY1+0x2)
/*  f0f480c:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4810:	018f0019 */ 	multu	$t4,$t7
/*  f0f4814:	84a52042 */ 	lh	$a1,%lo(g_MenuScissorY1+0x2)($a1)
/*  f0f4818:	00002012 */ 	mflo	$a0
/*  f0f481c:	0004c400 */ 	sll	$t8,$a0,0x10
/*  f0f4820:	0c002f2a */ 	jal	viSetViewPosition
/*  f0f4824:	00182403 */ 	sra	$a0,$t8,0x10
/*  f0f4828:	3c0b800a */ 	lui	$t3,%hi(g_MenuScissorX2)
/*  f0f482c:	8d6b203c */ 	lw	$t3,%lo(g_MenuScissorX2)($t3)
/*  f0f4830:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0f4834:	3c0c8008 */ 	lui	$t4,%hi(g_ScaleX)
/*  f0f4838:	8d8cfac0 */ 	lw	$t4,%lo(g_ScaleX)($t4)
/*  f0f483c:	016e6823 */ 	subu	$t5,$t3,$t6
/*  f0f4840:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x284)
/*  f0f4844:	01ac0019 */ 	multu	$t5,$t4
/*  f0f4848:	8d4aa244 */ 	lw	$t2,%lo(g_Vars+0x284)($t2)
/*  f0f484c:	3c19800a */ 	lui	$t9,%hi(g_MenuScissorY2)
/*  f0f4850:	8f392044 */ 	lw	$t9,%lo(g_MenuScissorY2)($t9)
/*  f0f4854:	c54c1854 */ 	lwc1	$f12,0x1854($t2)
/*  f0f4858:	3c0a800a */ 	lui	$t2,%hi(g_MenuScissorY1)
/*  f0f485c:	8d4a2040 */ 	lw	$t2,%lo(g_MenuScissorY1)($t2)
/*  f0f4860:	c7ae017c */ 	lwc1	$f14,0x17c($sp)
/*  f0f4864:	032a3823 */ 	subu	$a3,$t9,$t2
/*  f0f4868:	00003012 */ 	mflo	$a2
/*  f0f486c:	00067c00 */ 	sll	$t7,$a2,0x10
/*  f0f4870:	00075c00 */ 	sll	$t3,$a3,0x10
/*  f0f4874:	000b3c03 */ 	sra	$a3,$t3,0x10
/*  f0f4878:	0c002f76 */ 	jal	viSetFovAspectAndSize
/*  f0f487c:	000f3403 */ 	sra	$a2,$t7,0x10
/*  f0f4880:	3c0d8007 */ 	lui	$t5,%hi(g_MpPlayerNum)
/*  f0f4884:	8dad1448 */ 	lw	$t5,%lo(g_MpPlayerNum)($t5)
/*  f0f4888:	3c0f800a */ 	lui	$t7,%hi(var800a2048)
/*  f0f488c:	25ef2048 */ 	addiu	$t7,$t7,%lo(var800a2048)
/*  f0f4890:	000d6140 */ 	sll	$t4,$t5,0x5
/*  f0f4894:	018f2821 */ 	addu	$a1,$t4,$t7
/*  f0f4898:	0c002bc0 */ 	jal	vi0000af00
/*  f0f489c:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f48a0:	3c188007 */ 	lui	$t8,%hi(var800714c0)
/*  f0f48a4:	8f1814c0 */ 	lw	$t8,%lo(var800714c0)($t8)
/*  f0f48a8:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f48ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f48b0:	44982000 */ 	mtc1	$t8,$f4
/*  f0f48b4:	3c198007 */ 	lui	$t9,%hi(var800714c4)
/*  f0f48b8:	07010005 */ 	bgez	$t8,.L0f0f48d0
/*  f0f48bc:	46802120 */ 	cvt.s.w	$f4,$f4
/*  f0f48c0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f48c4:	44813000 */ 	mtc1	$at,$f6
/*  f0f48c8:	00000000 */ 	nop
/*  f0f48cc:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f0f48d0:
/*  f0f48d0:	8f3914c4 */ 	lw	$t9,%lo(var800714c4)($t9)
/*  f0f48d4:	44052000 */ 	mfc1	$a1,$f4
/*  f0f48d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f48dc:	44995000 */ 	mtc1	$t9,$f10
/*  f0f48e0:	07210004 */ 	bgez	$t9,.L0f0f48f4
/*  f0f48e4:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f0f48e8:	44814000 */ 	mtc1	$at,$f8
/*  f0f48ec:	00000000 */ 	nop
/*  f0f48f0:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f0f48f4:
/*  f0f48f4:	44065000 */ 	mfc1	$a2,$f10
/*  f0f48f8:	0c002b29 */ 	jal	vi0000aca4
/*  f0f48fc:	00000000 */ 	nop
/*  f0f4900:	afa20440 */ 	sw	$v0,0x440($sp)
.L0f0f4904:
/*  f0f4904:	8e0a0054 */ 	lw	$t2,0x54($s0)
.L0f0f4908:
/*  f0f4908:	8544000e */ 	lh	$a0,0xe($t2)
/*  f0f490c:	00045980 */ 	sll	$t3,$a0,0x6
/*  f0f4910:	0fc59e7d */ 	jal	gfxAllocate
/*  f0f4914:	01602025 */ 	or	$a0,$t3,$zero
/*  f0f4918:	afa203b4 */ 	sw	$v0,0x3b4($sp)
/*  f0f491c:	8e0e0054 */ 	lw	$t6,0x54($s0)
/*  f0f4920:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f4924:	85cd000e */ 	lh	$t5,0xe($t6)
/*  f0f4928:	59a0000d */ 	blezl	$t5,.L0f0f4960
/*  f0f492c:	8605005c */ 	lh	$a1,0x5c($s0)
/*  f0f4930:	8faf03b4 */ 	lw	$t7,0x3b4($sp)
.L0f0f4934:
/*  f0f4934:	00116180 */ 	sll	$t4,$s1,0x6
/*  f0f4938:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0f493c:	018f2021 */ 	addu	$a0,$t4,$t7
/*  f0f4940:	8e180054 */ 	lw	$t8,0x54($s0)
/*  f0f4944:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f4948:	8719000e */ 	lh	$t9,0xe($t8)
/*  f0f494c:	0239082a */ 	slt	$at,$s1,$t9
/*  f0f4950:	5420fff8 */ 	bnezl	$at,.L0f0f4934
/*  f0f4954:	8faf03b4 */ 	lw	$t7,0x3b4($sp)
/*  f0f4958:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f495c:	8605005c */ 	lh	$a1,0x5c($s0)
.L0f0f4960:
/*  f0f4960:	8faa03b4 */ 	lw	$t2,0x3b4($sp)
/*  f0f4964:	10a00025 */ 	beqz	$a1,.L0f0f49fc
/*  f0f4968:	ae0a006c */ 	sw	$t2,0x6c($s0)
/*  f0f496c:	860b005e */ 	lh	$t3,0x5e($s0)
/*  f0f4970:	50ab0023 */ 	beql	$a1,$t3,.L0f0f4a00
/*  f0f4974:	8618005e */ 	lh	$t8,0x5e($s0)
/*  f0f4978:	8e0e05b0 */ 	lw	$t6,0x5b0($s0)
/*  f0f497c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4980:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f4984:	000e62c0 */ 	sll	$t4,$t6,0xb
/*  f0f4988:	05810014 */ 	bgez	$t4,.L0f0f49dc
/*  f0f498c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f4990:	3c01bf00 */ 	lui	$at,0xbf00
/*  f0f4994:	44812000 */ 	mtc1	$at,$f4
/*  f0f4998:	44803000 */ 	mtc1	$zero,$f6
/*  f0f499c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f49a0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f49a4:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0f49a8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0f49ac:	0c007733 */ 	jal	modelSetAnimation
/*  f0f49b0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0f49b4:	0c007486 */ 	jal	modelGetNumAnimFrames
/*  f0f49b8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f49bc:	44825000 */ 	mtc1	$v0,$f10
/*  f0f49c0:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f49c4:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f0f49c8:	44055000 */ 	mfc1	$a1,$f10
/*  f0f49cc:	0c007806 */ 	jal	model0001e018
/*  f0f49d0:	00000000 */ 	nop
/*  f0f49d4:	10000008 */ 	b	.L0f0f49f8
/*  f0f49d8:	860f005c */ 	lh	$t7,0x5c($s0)
.L0f0f49dc:
/*  f0f49dc:	44814000 */ 	mtc1	$at,$f8
/*  f0f49e0:	44802000 */ 	mtc1	$zero,$f4
/*  f0f49e4:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0f49e8:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0f49ec:	0c007733 */ 	jal	modelSetAnimation
/*  f0f49f0:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0f49f4:	860f005c */ 	lh	$t7,0x5c($s0)
.L0f0f49f8:
/*  f0f49f8:	a60f005e */ 	sh	$t7,0x5e($s0)
.L0f0f49fc:
/*  f0f49fc:	8618005e */ 	lh	$t8,0x5e($s0)
.L0f0f4a00:
/*  f0f4a00:	a600005c */ 	sh	$zero,0x5c($s0)
/*  f0f4a04:	13000023 */ 	beqz	$t8,.L0f0f4a94
/*  f0f4a08:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x40)
/*  f0f4a0c:	8ca5a000 */ 	lw	$a1,%lo(g_Vars+0x40)($a1)
/*  f0f4a10:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a14:	0c007b86 */ 	jal	model0001ee18
/*  f0f4a18:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0f4a1c:	8e1905b0 */ 	lw	$t9,0x5b0($s0)
/*  f0f4a20:	00195ac0 */ 	sll	$t3,$t9,0xb
/*  f0f4a24:	0561000c */ 	bgez	$t3,.L0f0f4a58
/*  f0f4a28:	00000000 */ 	nop
/*  f0f4a2c:	0c007486 */ 	jal	modelGetNumAnimFrames
/*  f0f4a30:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a34:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f4a38:	0c00745f */ 	jal	modelGetCurAnimFrame
/*  f0f4a3c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a40:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0f4a44:	448e3000 */ 	mtc1	$t6,$f6
/*  f0f4a48:	00000000 */ 	nop
/*  f0f4a4c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0f4a50:	10000004 */ 	b	.L0f0f4a64
/*  f0f4a54:	46005081 */ 	sub.s	$f2,$f10,$f0
.L0f0f4a58:
/*  f0f4a58:	0c00745f */ 	jal	modelGetCurAnimFrame
/*  f0f4a5c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a60:	46000086 */ 	mov.s	$f2,$f0
.L0f0f4a64:
/*  f0f4a64:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a68:	0c007486 */ 	jal	modelGetNumAnimFrames
/*  f0f4a6c:	e7a20178 */ 	swc1	$f2,0x178($sp)
/*  f0f4a70:	244dffff */ 	addiu	$t5,$v0,-1
/*  f0f4a74:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f4a78:	c7a20178 */ 	lwc1	$f2,0x178($sp)
/*  f0f4a7c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0f4a80:	4602203e */ 	c.le.s	$f4,$f2
/*  f0f4a84:	00000000 */ 	nop
/*  f0f4a88:	45020003 */ 	bc1fl	.L0f0f4a98
/*  f0f4a8c:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f4a90:	a600005e */ 	sh	$zero,0x5e($s0)
.L0f0f4a94:
/*  f0f4a94:	8fa40040 */ 	lw	$a0,0x40($sp)
.L0f0f4a98:
/*  f0f4a98:	0c005746 */ 	jal	mtx4Copy
/*  f0f4a9c:	8fa503b4 */ 	lw	$a1,0x3b4($sp)
/*  f0f4aa0:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f4aa4:	27a403b8 */ 	addiu	$a0,$sp,0x3b8
/*  f0f4aa8:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0f4aac:	afac03b8 */ 	sw	$t4,0x3b8($sp)
/*  f0f4ab0:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f0f4ab4:	0c0073af */ 	jal	model0001cebc
/*  f0f4ab8:	afaf03c8 */ 	sw	$t7,0x3c8($sp)
/*  f0f4abc:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4ac0:	3c188008 */ 	lui	$t8,%hi(g_SkelHudPiece)
/*  f0f4ac4:	2718cc34 */ 	addiu	$t8,$t8,%lo(g_SkelHudPiece)
/*  f0f4ac8:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f0f4acc:	57190092 */ 	bnel	$t8,$t9,.L0f0f4d18
/*  f0f4ad0:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f4ad4:	0c006a47 */ 	jal	modelGetPart
/*  f0f4ad8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4adc:	5040002e */ 	beqzl	$v0,.L0f0f4b98
/*  f0f4ae0:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4ae4:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f0f4ae8:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0f4aec:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0f4af0:	84aa0010 */ 	lh	$t2,0x10($a1)
/*  f0f4af4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f4af8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f4afc:	19400025 */ 	blez	$t2,.L0f0f4b94
/*  f0f4b00:	24080064 */ 	addiu	$t0,$zero,0x64
/*  f0f4b04:	8d2d0000 */ 	lw	$t5,0x0($t1)
.L0f0f4b08:
/*  f0f4b08:	8cab000c */ 	lw	$t3,0xc($a1)
/*  f0f4b0c:	01a80019 */ 	multu	$t5,$t0
/*  f0f4b10:	01661021 */ 	addu	$v0,$t3,$a2
/*  f0f4b14:	844e0008 */ 	lh	$t6,0x8($v0)
/*  f0f4b18:	00006012 */ 	mflo	$t4
/*  f0f4b1c:	01cc7823 */ 	subu	$t7,$t6,$t4
/*  f0f4b20:	a44f0008 */ 	sh	$t7,0x8($v0)
/*  f0f4b24:	8cb8000c */ 	lw	$t8,0xc($a1)
/*  f0f4b28:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f0f4b2c:	872a0008 */ 	lh	$t2,0x8($t9)
/*  f0f4b30:	2941a000 */ 	slti	$at,$t2,-24576
/*  f0f4b34:	50200012 */ 	beqzl	$at,.L0f0f4b80
/*  f0f4b38:	84b80010 */ 	lh	$t8,0x10($a1)
/*  f0f4b3c:	84ab0010 */ 	lh	$t3,0x10($a1)
/*  f0f4b40:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f4b44:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f4b48:	5960000d */ 	blezl	$t3,.L0f0f4b80
/*  f0f4b4c:	84b80010 */ 	lh	$t8,0x10($a1)
/*  f0f4b50:	8cad000c */ 	lw	$t5,0xc($a1)
.L0f0f4b54:
/*  f0f4b54:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f4b58:	01a41021 */ 	addu	$v0,$t5,$a0
/*  f0f4b5c:	844e0008 */ 	lh	$t6,0x8($v0)
/*  f0f4b60:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f0f4b64:	25cc2000 */ 	addiu	$t4,$t6,0x2000
/*  f0f4b68:	a44c0008 */ 	sh	$t4,0x8($v0)
/*  f0f4b6c:	84af0010 */ 	lh	$t7,0x10($a1)
/*  f0f4b70:	006f082a */ 	slt	$at,$v1,$t7
/*  f0f4b74:	5420fff7 */ 	bnezl	$at,.L0f0f4b54
/*  f0f4b78:	8cad000c */ 	lw	$t5,0xc($a1)
/*  f0f4b7c:	84b80010 */ 	lh	$t8,0x10($a1)
.L0f0f4b80:
/*  f0f4b80:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f0f4b84:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f0f4b88:	00f8082a */ 	slt	$at,$a3,$t8
/*  f0f4b8c:	5420ffde */ 	bnezl	$at,.L0f0f4b08
/*  f0f4b90:	8d2d0000 */ 	lw	$t5,0x0($t1)
.L0f0f4b94:
/*  f0f4b94:	8e040054 */ 	lw	$a0,0x54($s0)
.L0f0f4b98:
/*  f0f4b98:	0c006a47 */ 	jal	modelGetPart
/*  f0f4b9c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0f4ba0:	10400019 */ 	beqz	$v0,.L0f0f4c08
/*  f0f4ba4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4ba8:	0c006949 */ 	jal	model0001a524
/*  f0f4bac:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4bb0:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0f4bb4:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0f4bb8:	27a40120 */ 	addiu	$a0,$sp,0x120
/*  f0f4bbc:	3c014080 */ 	lui	$at,0x4080
/*  f0f4bc0:	44816000 */ 	mtc1	$at,$f12
/*  f0f4bc4:	0fc01ad5 */ 	jal	func0f006b54
/*  f0f4bc8:	00000000 */ 	nop
/*  f0f4bcc:	46000306 */ 	mov.s	$f12,$f0
/*  f0f4bd0:	0c0058ba */ 	jal	mtx4LoadXRotation
/*  f0f4bd4:	27a50120 */ 	addiu	$a1,$sp,0x120
/*  f0f4bd8:	8faa0160 */ 	lw	$t2,0x160($sp)
/*  f0f4bdc:	8fb903b4 */ 	lw	$t9,0x3b4($sp)
/*  f0f4be0:	27a50120 */ 	addiu	$a1,$sp,0x120
/*  f0f4be4:	000a5980 */ 	sll	$t3,$t2,0x6
/*  f0f4be8:	032b3821 */ 	addu	$a3,$t9,$t3
/*  f0f4bec:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0f4bf0:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f0f4bf4:	0c005680 */ 	jal	mtx4MultMtx4
/*  f0f4bf8:	27a600e0 */ 	addiu	$a2,$sp,0xe0
/*  f0f4bfc:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0f4c00:	0c005746 */ 	jal	mtx4Copy
/*  f0f4c04:	27a400e0 */ 	addiu	$a0,$sp,0xe0
.L0f0f4c08:
/*  f0f4c08:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4c0c:	0c006a47 */ 	jal	modelGetPart
/*  f0f4c10:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0f4c14:	1040003f */ 	beqz	$v0,.L0f0f4d14
/*  f0f4c18:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4c1c:	3c02800a */ 	lui	$v0,%hi(g_MenuData+0x4)
/*  f0f4c20:	8c4219c4 */ 	lw	$v0,%lo(g_MenuData+0x4)($v0)
/*  f0f4c24:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f4c28:	10410007 */ 	beq	$v0,$at,.L0f0f4c48
/*  f0f4c2c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f4c30:	10410005 */ 	beq	$v0,$at,.L0f0f4c48
/*  f0f4c34:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f4c38:	10410003 */ 	beq	$v0,$at,.L0f0f4c48
/*  f0f4c3c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f4c40:	54410035 */ 	bnel	$v0,$at,.L0f0f4d18
/*  f0f4c44:	8fb80440 */ 	lw	$t8,0x440($sp)
.L0f0f4c48:
/*  f0f4c48:	0c006949 */ 	jal	model0001a524
/*  f0f4c4c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4c50:	8fad03b4 */ 	lw	$t5,0x3b4($sp)
/*  f0f4c54:	00027180 */ 	sll	$t6,$v0,0x6
/*  f0f4c58:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0f4c5c:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f0f4c60:	c4660030 */ 	lwc1	$f6,0x30($v1)
/*  f0f4c64:	27a500c8 */ 	addiu	$a1,$sp,0xc8
/*  f0f4c68:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f0f4c6c:	c46a0034 */ 	lwc1	$f10,0x34($v1)
/*  f0f4c70:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0f4c74:	c4680038 */ 	lwc1	$f8,0x38($v1)
/*  f0f4c78:	0fc2d341 */ 	jal	func0f0b4d04
/*  f0f4c7c:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*  f0f4c80:	0c002f02 */ 	jal	viGetWidth
/*  f0f4c84:	00000000 */ 	nop
/*  f0f4c88:	c7a400c8 */ 	lwc1	$f4,0xc8($sp)
/*  f0f4c8c:	3c198008 */ 	lui	$t9,%hi(g_ScaleX)
/*  f0f4c90:	8f39fac0 */ 	lw	$t9,%lo(g_ScaleX)($t9)
/*  f0f4c94:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0f4c98:	440f3000 */ 	mfc1	$t7,$f6
/*  f0f4c9c:	04410003 */ 	bgez	$v0,.L0f0f4cac
/*  f0f4ca0:	0002c043 */ 	sra	$t8,$v0,0x1
/*  f0f4ca4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f4ca8:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0f4cac:
/*  f0f4cac:	01f85023 */ 	subu	$t2,$t7,$t8
/*  f0f4cb0:	0159001a */ 	div	$zero,$t2,$t9
/*  f0f4cb4:	17200002 */ 	bnez	$t9,.L0f0f4cc0
/*  f0f4cb8:	00000000 */ 	nop
/*  f0f4cbc:	0007000d */ 	break	0x7
.L0f0f4cc0:
/*  f0f4cc0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f4cc4:	17210004 */ 	bne	$t9,$at,.L0f0f4cd8
/*  f0f4cc8:	3c018000 */ 	lui	$at,0x8000
/*  f0f4ccc:	15410002 */ 	bne	$t2,$at,.L0f0f4cd8
/*  f0f4cd0:	00000000 */ 	nop
/*  f0f4cd4:	0006000d */ 	break	0x6
.L0f0f4cd8:
/*  f0f4cd8:	3c01800a */ 	lui	$at,%hi(var8009de98)
/*  f0f4cdc:	00005812 */ 	mflo	$t3
/*  f0f4ce0:	ac2bde98 */ 	sw	$t3,%lo(var8009de98)($at)
/*  f0f4ce4:	0c002f06 */ 	jal	viGetHeight
/*  f0f4ce8:	00000000 */ 	nop
/*  f0f4cec:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0f4cf0:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0f4cf4:	440e4000 */ 	mfc1	$t6,$f8
/*  f0f4cf8:	04410003 */ 	bgez	$v0,.L0f0f4d08
/*  f0f4cfc:	00026043 */ 	sra	$t4,$v0,0x1
/*  f0f4d00:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f4d04:	00016043 */ 	sra	$t4,$at,0x1
.L0f0f4d08:
/*  f0f4d08:	3c01800a */ 	lui	$at,%hi(var8009de9c)
/*  f0f4d0c:	01cc7823 */ 	subu	$t7,$t6,$t4
/*  f0f4d10:	ac2fde9c */ 	sw	$t7,%lo(var8009de9c)($at)
.L0f0f4d14:
/*  f0f4d14:	8fb80440 */ 	lw	$t8,0x440($sp)
.L0f0f4d18:
/*  f0f4d18:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f0f4d1c:	3c0b8000 */ 	lui	$t3,0x8000
/*  f0f4d20:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f4d24:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f4d28:	356b0040 */ 	ori	$t3,$t3,0x40
/*  f0f4d2c:	37390002 */ 	ori	$t9,$t9,0x2
/*  f0f4d30:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0f4d34:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f0f4d38:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f4d3c:	3c0c0386 */ 	lui	$t4,0x386
/*  f0f4d40:	3c0f8007 */ 	lui	$t7,%hi(var80071470)
/*  f0f4d44:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0f4d48:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f4d4c:	25ef1470 */ 	addiu	$t7,$t7,%lo(var80071470)
/*  f0f4d50:	358c0010 */ 	ori	$t4,$t4,0x10
/*  f0f4d54:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f0f4d58:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f0f4d5c:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f4d60:	3c0b8007 */ 	lui	$t3,%hi(var80071468)
/*  f0f4d64:	3c190388 */ 	lui	$t9,0x388
/*  f0f4d68:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f4d6c:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f4d70:	37390010 */ 	ori	$t9,$t9,0x10
/*  f0f4d74:	256b1468 */ 	addiu	$t3,$t3,%lo(var80071468)
/*  f0f4d78:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f0f4d7c:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0f4d80:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f4d84:	3c0c0384 */ 	lui	$t4,0x384
/*  f0f4d88:	358c0010 */ 	ori	$t4,$t4,0x10
/*  f0f4d8c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0f4d90:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f4d94:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f0f4d98:	0fc2d5ea */ 	jal	currentPlayerGetUnk175c
/*  f0f4d9c:	afad00b8 */ 	sw	$t5,0xb8($sp)
/*  f0f4da0:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*  f0f4da4:	3c0a0382 */ 	lui	$t2,0x382
/*  f0f4da8:	354a0010 */ 	ori	$t2,$t2,0x10
/*  f0f4dac:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0f4db0:	8faf0440 */ 	lw	$t7,0x440($sp)
/*  f0f4db4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0f4db8:	afb80440 */ 	sw	$t8,0x440($sp)
/*  f0f4dbc:	adea0000 */ 	sw	$t2,0x0($t7)
/*  f0f4dc0:	0fc2d5ea */ 	jal	currentPlayerGetUnk175c
/*  f0f4dc4:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f0f4dc8:	8fa600b4 */ 	lw	$a2,0xb4($sp)
/*  f0f4dcc:	24590010 */ 	addiu	$t9,$v0,0x10
/*  f0f4dd0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f4dd4:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f0f4dd8:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f4ddc:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0f4de0:	240effff */ 	addiu	$t6,$zero,-1
/*  f0f4de4:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f4de8:	afab03e8 */ 	sw	$t3,0x3e8($sp)
/*  f0f4dec:	afad03ec */ 	sw	$t5,0x3ec($sp)
/*  f0f4df0:	afae03f0 */ 	sw	$t6,0x3f0($sp)
/*  f0f4df4:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f4df8:	3c18b700 */ 	lui	$t8,0xb700
/*  f0f4dfc:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f4e00:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f0f4e04:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f4e08:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f4e0c:	afab03bc */ 	sw	$t3,0x3bc($sp)
/*  f0f4e10:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0f4e14:	27a403b8 */ 	addiu	$a0,$sp,0x3b8
/*  f0f4e18:	0c0087bd */ 	jal	modelRender
/*  f0f4e1c:	afb903c4 */ 	sw	$t9,0x3c4($sp)
/*  f0f4e20:	8fad03c4 */ 	lw	$t5,0x3c4($sp)
/*  f0f4e24:	0c0059d8 */ 	jal	mtx00016760
/*  f0f4e28:	afad0440 */ 	sw	$t5,0x440($sp)
/*  f0f4e2c:	8e0e0054 */ 	lw	$t6,0x54($s0)
/*  f0f4e30:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f4e34:	85cc000e */ 	lh	$t4,0xe($t6)
/*  f0f4e38:	19800013 */ 	blez	$t4,.L0f0f4e88
/*  f0f4e3c:	00000000 */ 	nop
/*  f0f4e40:	8e0f006c */ 	lw	$t7,0x6c($s0)
.L0f0f4e44:
/*  f0f4e44:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0f4e48:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f4e4c:	0c005746 */ 	jal	mtx4Copy
/*  f0f4e50:	01e22021 */ 	addu	$a0,$t7,$v0
/*  f0f4e54:	8e18006c */ 	lw	$t8,0x6c($s0)
/*  f0f4e58:	00115180 */ 	sll	$t2,$s1,0x6
/*  f0f4e5c:	27a40070 */ 	addiu	$a0,$sp,0x70
/*  f0f4e60:	0c005815 */ 	jal	mtx00016054
/*  f0f4e64:	030a2821 */ 	addu	$a1,$t8,$t2
/*  f0f4e68:	8e190054 */ 	lw	$t9,0x54($s0)
/*  f0f4e6c:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0f4e70:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f4e74:	872b000e */ 	lh	$t3,0xe($t9)
/*  f0f4e78:	24420040 */ 	addiu	$v0,$v0,64
/*  f0f4e7c:	022b082a */ 	slt	$at,$s1,$t3
/*  f0f4e80:	5420fff0 */ 	bnezl	$at,.L0f0f4e44
/*  f0f4e84:	8e0f006c */ 	lw	$t7,0x6c($s0)
.L0f0f4e88:
/*  f0f4e88:	0c0059e1 */ 	jal	mtx00016784
/*  f0f4e8c:	00000000 */ 	nop
/*  f0f4e90:	8fad0448 */ 	lw	$t5,0x448($sp)
/*  f0f4e94:	29a10003 */ 	slti	$at,$t5,0x3
/*  f0f4e98:	50200005 */ 	beqzl	$at,.L0f0f4eb0
/*  f0f4e9c:	8fae0440 */ 	lw	$t6,0x440($sp)
/*  f0f4ea0:	0fc351e7 */ 	jal	func0f0d479c
/*  f0f4ea4:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f4ea8:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4eac:	8fae0440 */ 	lw	$t6,0x440($sp)
.L0f0f4eb0:
/*  f0f4eb0:	3c0fe700 */ 	lui	$t7,0xe700
/*  f0f4eb4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0f4eb8:	25cc0008 */ 	addiu	$t4,$t6,0x8
/*  f0f4ebc:	afac0440 */ 	sw	$t4,0x440($sp)
/*  f0f4ec0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f4ec4:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f0f4ec8:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f4ecc:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f0f4ed0:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0f4ed4:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f4ed8:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f4edc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0f4ee0:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0f4ee4:	8fab0440 */ 	lw	$t3,0x440($sp)
/*  f0f4ee8:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f0f4eec:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f0f4ef0:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f0f4ef4:	afad0440 */ 	sw	$t5,0x440($sp)
/*  f0f4ef8:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0f4efc:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f4f00:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f4f04:	37187e24 */ 	ori	$t8,$t8,0x7e24
/*  f0f4f08:	240af9fc */ 	addiu	$t2,$zero,-1540
/*  f0f4f0c:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f4f10:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f4f14:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f0f4f18:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f4f1c:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f4f20:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f0f4f24:	3c0db600 */ 	lui	$t5,0xb600
/*  f0f4f28:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f0f4f2c:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f4f30:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0f4f34:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f4f38:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f4f3c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0f4f40:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f0f4f44:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f4f48:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f4f4c:	240a2000 */ 	addiu	$t2,$zero,0x2000
/*  f0f4f50:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f0f4f54:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f4f58:	27b00440 */ 	addiu	$s0,$sp,0x440
/*  f0f4f5c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0f4f60:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f4f64:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f4f68:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f4f6c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f4f70:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f4f74:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4f78:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f4f7c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0f4f80:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f4f84:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f4f88:	3c0cb900 */ 	lui	$t4,0xb900
/*  f0f4f8c:	3c0f0050 */ 	lui	$t7,0x50
/*  f0f4f90:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0f4f94:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f4f98:	35ef4240 */ 	ori	$t7,$t7,0x4240
/*  f0f4f9c:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f0f4fa0:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f0f4fa4:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f0f4fa8:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f0f4fac:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f4fb0:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0f4fb4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f4fb8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f4fbc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f4fc0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4fc4:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f4fc8:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0f4fcc:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f4fd0:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f4fd4:	3c0d0600 */ 	lui	$t5,0x600
/*  f0f4fd8:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f0f4fdc:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f4fe0:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f4fe4:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f0f4fe8:	af2e0004 */ 	sw	$t6,0x4($t9)
.L0f0f4fec:
/*  f0f4fec:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f4ff0:
/*  f0f4ff0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f4ff4:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0f4ff8:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0f4ffc:	03e00008 */ 	jr	$ra
/*  f0f5000:	27bd0440 */ 	addiu	$sp,$sp,0x440
);
#else
GLOBAL_ASM(
glabel menuRenderModels
.late_rodata
glabel var7f1b292c
.word 0x40f33333
glabel var7f1b2930
.word 0x3b03126f
glabel var7f1b2934
.word 0x3f7f7cee
glabel var7f1b2938
.word 0x3f7f7cee
glabel var7f1b293c
.word 0x3b03126f
glabel var7f1b2940
.word 0x3b03126f
glabel var7f1b2944
.word 0x3b03126f
glabel var7f1b2948
.word 0x40490fdb
.text
/*  f0f03f4:	27bdfb98 */ 	addiu	$sp,$sp,-1128
/*  f0f03f8:	3c02800a */ 	lui	$v0,0x800a
/*  f0f03fc:	8c42eb74 */ 	lw	$v0,-0x148c($v0)
/*  f0f0400:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0f0404:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f0408:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0f040c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f0410:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0f0414:	afa40468 */ 	sw	$a0,0x468($sp)
/*  f0f0418:	1041001d */ 	beq	$v0,$at,.NB0f0f0490
/*  f0f041c:	afa60470 */ 	sw	$a2,0x470($sp)
/*  f0f0420:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f0f0424:	1041001a */ 	beq	$v0,$at,.NB0f0f0490
/*  f0f0428:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f042c:	81cf6485 */ 	lb	$t7,0x6485($t6)
/*  f0f0430:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f0434:	05e30008 */ 	bgezl	$t7,.NB0f0f0458
/*  f0f0438:	8e390004 */ 	lw	$t9,0x4($s1)
/*  f0f043c:	10c10005 */ 	beq	$a2,$at,.NB0f0f0454
/*  f0f0440:	28c10003 */ 	slti	$at,$a2,0x3
/*  f0f0444:	50200004 */ 	beqzl	$at,.NB0f0f0458
/*  f0f0448:	8e390004 */ 	lw	$t9,0x4($s1)
/*  f0f044c:	100005d1 */ 	beqz	$zero,.NB0f0f1b94
/*  f0f0450:	00801025 */ 	or	$v0,$a0,$zero
.NB0f0f0454:
/*  f0f0454:	8e390004 */ 	lw	$t9,0x4($s1)
.NB0f0f0458:
/*  f0f0458:	5720000e */ 	bnezl	$t9,.NB0f0f0494
/*  f0f045c:	8e2a0004 */ 	lw	$t2,0x4($s1)
/*  f0f0460:	0fc26fc8 */ 	jal	bgun0f09e004
/*  f0f0464:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f0468:	10400007 */ 	beqz	$v0,.NB0f0f0488
/*  f0f046c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0470:	0fc26f42 */ 	jal	bgunGetGunMem
/*  f0f0474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0478:	0fc26f46 */ 	jal	bgunCalculateGunMemCapacity
/*  f0f047c:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0f0480:	10000003 */ 	beqz	$zero,.NB0f0f0490
/*  f0f0484:	ae220008 */ 	sw	$v0,0x8($s1)
.NB0f0f0488:
/*  f0f0488:	100005c2 */ 	beqz	$zero,.NB0f0f1b94
/*  f0f048c:	8fa20468 */ 	lw	$v0,0x468($sp)
.NB0f0f0490:
/*  f0f0490:	8e2a0004 */ 	lw	$t2,0x4($s1)
.NB0f0f0494:
/*  f0f0494:	55400004 */ 	bnezl	$t2,.NB0f0f04a8
/*  f0f0498:	8e22000c */ 	lw	$v0,0xc($s1)
/*  f0f049c:	100005bd */ 	beqz	$zero,.NB0f0f1b94
/*  f0f04a0:	8fa20468 */ 	lw	$v0,0x468($sp)
/*  f0f04a4:	8e22000c */ 	lw	$v0,0xc($s1)
.NB0f0f04a8:
/*  f0f04a8:	504000dc */ 	beqzl	$v0,.NB0f0f081c
/*  f0f04ac:	8e2a0054 */ 	lw	$t2,0x54($s1)
/*  f0f04b0:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0f04b4:	3c014fac */ 	lui	$at,0x4fac
/*  f0f04b8:	34215ace */ 	ori	$at,$at,0x5ace
/*  f0f04bc:	14620004 */ 	bne	$v1,$v0,.NB0f0f04d0
/*  f0f04c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f04c4:	ae20000c */ 	sw	$zero,0xc($s1)
/*  f0f04c8:	100000d3 */ 	beqz	$zero,.NB0f0f0818
/*  f0f04cc:	a2200000 */ 	sb	$zero,0x0($s1)
.NB0f0f04d0:
/*  f0f04d0:	54610004 */ 	bnel	$v1,$at,.NB0f0f04e4
/*  f0f04d4:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f0f04d8:	0fc658b5 */ 	jal	mpClearCurrentChallenge
/*  f0f04dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f04e0:	92220000 */ 	lbu	$v0,0x0($s1)
.NB0f0f04e4:
/*  f0f04e4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f04e8:	14400004 */ 	bnez	$v0,.NB0f0f04fc
/*  f0f04ec:	244cffff */ 	addiu	$t4,$v0,-1
/*  f0f04f0:	a22b0000 */ 	sb	$t3,0x0($s1)
/*  f0f04f4:	100005a7 */ 	beqz	$zero,.NB0f0f1b94
/*  f0f04f8:	8fa20468 */ 	lw	$v0,0x468($sp)
.NB0f0f04fc:
/*  f0f04fc:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0f0500:	15a000c3 */ 	bnez	$t5,.NB0f0f0810
/*  f0f0504:	a22c0000 */ 	sb	$t4,0x0($s1)
/*  f0f0508:	8e22000c */ 	lw	$v0,0xc($s1)
/*  f0f050c:	3401ffff */ 	dli	$at,0xffff
/*  f0f0510:	304effff */ 	andi	$t6,$v0,0xffff
/*  f0f0514:	11c10002 */ 	beq	$t6,$at,.NB0f0f0520
/*  f0f0518:	00027800 */ 	sll	$t7,$v0,0x0
/*  f0f051c:	05e10092 */ 	bgez	$t7,.NB0f0f0768
.NB0f0f0520:
/*  f0f0520:	0002c000 */ 	sll	$t8,$v0,0x0
/*  f0f0524:	07010008 */ 	bgez	$t8,.NB0f0f0548
/*  f0f0528:	3c01000f */ 	lui	$at,0xf
/*  f0f052c:	3421fc00 */ 	ori	$at,$at,0xfc00
/*  f0f0530:	00415024 */ 	and	$t2,$v0,$at
/*  f0f0534:	305903ff */ 	andi	$t9,$v0,0x3ff
/*  f0f0538:	000a5a82 */ 	srl	$t3,$t2,0xa
/*  f0f053c:	afb90428 */ 	sw	$t9,0x428($sp)
/*  f0f0540:	1000001a */ 	beqz	$zero,.NB0f0f05ac
/*  f0f0544:	afab042c */ 	sw	$t3,0x42c($sp)
.NB0f0f0548:
/*  f0f0548:	00028402 */ 	srl	$s0,$v0,0x10
/*  f0f054c:	320c00ff */ 	andi	$t4,$s0,0xff
/*  f0f0550:	00026e02 */ 	srl	$t5,$v0,0x18
/*  f0f0554:	01808025 */ 	or	$s0,$t4,$zero
/*  f0f0558:	0fc6177a */ 	jal	mpGetBodyId
/*  f0f055c:	31a400ff */ 	andi	$a0,$t5,0xff
/*  f0f0560:	0fc6175d */ 	jal	mpGetNumHeads2
/*  f0f0564:	afa2042c */ 	sw	$v0,0x42c($sp)
/*  f0f0568:	0202082a */ 	slt	$at,$s0,$v0
/*  f0f056c:	10200005 */ 	beqz	$at,.NB0f0f0584
/*  f0f0570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0574:	0fc61761 */ 	jal	mpGetHeadId
/*  f0f0578:	320400ff */ 	andi	$a0,$s0,0xff
/*  f0f057c:	1000000b */ 	beqz	$zero,.NB0f0f05ac
/*  f0f0580:	afa20428 */ 	sw	$v0,0x428($sp)
.NB0f0f0584:
/*  f0f0584:	0fc6175d */ 	jal	mpGetNumHeads2
/*  f0f0588:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f058c:	0fc51472 */ 	jal	func0f14a9f8
/*  f0f0590:	02022023 */ 	subu	$a0,$s0,$v0
/*  f0f0594:	0fc6176f */ 	jal	mpGetBeauHeadId
/*  f0f0598:	304400ff */ 	andi	$a0,$v0,0xff
/*  f0f059c:	0fc6175d */ 	jal	mpGetNumHeads2
/*  f0f05a0:	afa20428 */ 	sw	$v0,0x428($sp)
/*  f0f05a4:	02027823 */ 	subu	$t7,$s0,$v0
/*  f0f05a8:	a22f05b0 */ 	sb	$t7,0x5b0($s1)
.NB0f0f05ac:
/*  f0f05ac:	8fb8042c */ 	lw	$t8,0x42c($sp)
/*  f0f05b0:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0f05b4:	254af764 */ 	addiu	$t2,$t2,-2204
/*  f0f05b8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f05bc:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f05c0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f05c4:	032a8021 */ 	addu	$s0,$t9,$t2
/*  f0f05c8:	96020002 */ 	lhu	$v0,0x2($s0)
/*  f0f05cc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f05d0:	a7a20432 */ 	sh	$v0,0x432($sp)
/*  f0f05d4:	0fc58635 */ 	jal	fileGetInflatedLength
/*  f0f05d8:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0f05dc:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f0f05e0:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f05e4:	346b003f */ 	ori	$t3,$v1,0x3f
/*  f0f05e8:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f0f05ec:	05e10005 */ 	bgez	$t7,.NB0f0f0604
/*  f0f05f0:	3963003f */ 	xori	$v1,$t3,0x3f
/*  f0f05f4:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f05f8:	afb80428 */ 	sw	$t8,0x428($sp)
/*  f0f05fc:	10000011 */ 	beqz	$zero,.NB0f0f0644
/*  f0f0600:	3410ffff */ 	dli	$s0,0xffff
.NB0f0f0604:
/*  f0f0604:	8fb90428 */ 	lw	$t9,0x428($sp)
/*  f0f0608:	3c108008 */ 	lui	$s0,0x8008
/*  f0f060c:	afa30448 */ 	sw	$v1,0x448($sp)
/*  f0f0610:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0f0614:	01595021 */ 	addu	$t2,$t2,$t9
/*  f0f0618:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f061c:	020a8021 */ 	addu	$s0,$s0,$t2
/*  f0f0620:	9610f766 */ 	lhu	$s0,-0x89a($s0)
/*  f0f0624:	0fc58635 */ 	jal	fileGetInflatedLength
/*  f0f0628:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f062c:	8fab0448 */ 	lw	$t3,0x448($sp)
/*  f0f0630:	244c003f */ 	addiu	$t4,$v0,0x3f
/*  f0f0634:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0f0638:	39ae003f */ 	xori	$t6,$t5,0x3f
/*  f0f063c:	016e1821 */ 	addu	$v1,$t3,$t6
/*  f0f0640:	afa30448 */ 	sw	$v1,0x448($sp)
.NB0f0f0644:
/*  f0f0644:	8e380004 */ 	lw	$t8,0x4($s1)
/*  f0f0648:	8e390008 */ 	lw	$t9,0x8($s1)
/*  f0f064c:	24634000 */ 	addiu	$v1,$v1,0x4000
/*  f0f0650:	afa30448 */ 	sw	$v1,0x448($sp)
/*  f0f0654:	27a40438 */ 	addiu	$a0,$sp,0x438
/*  f0f0658:	03032821 */ 	addu	$a1,$t8,$v1
/*  f0f065c:	0fc5b6c2 */ 	jal	func0f172e70
/*  f0f0660:	03233023 */ 	subu	$a2,$t9,$v1
/*  f0f0664:	8faa0428 */ 	lw	$t2,0x428($sp)
/*  f0f0668:	8e250004 */ 	lw	$a1,0x4($s1)
/*  f0f066c:	27a70438 */ 	addiu	$a3,$sp,0x438
/*  f0f0670:	a62a0002 */ 	sh	$t2,0x2($s1)
/*  f0f0674:	8fac042c */ 	lw	$t4,0x42c($sp)
/*  f0f0678:	a62c056a */ 	sh	$t4,0x56a($s1)
/*  f0f067c:	8fa60448 */ 	lw	$a2,0x448($sp)
/*  f0f0680:	0c0091a1 */ 	jal	func0f1a7794
/*  f0f0684:	97a40432 */ 	lhu	$a0,0x432($sp)
/*  f0f0688:	ae220054 */ 	sw	$v0,0x54($s1)
/*  f0f068c:	0fc586ed */ 	jal	fileGetSize
/*  f0f0690:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f0694:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f0698:	346d003f */ 	ori	$t5,$v1,0x3f
/*  f0f069c:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0f06a0:	8e240054 */ 	lw	$a0,0x54($s1)
/*  f0f06a4:	0c008f6f */ 	jal	modelCalculateRwDataLen
/*  f0f06a8:	afab0434 */ 	sw	$t3,0x434($sp)
/*  f0f06ac:	8fae0428 */ 	lw	$t6,0x428($sp)
/*  f0f06b0:	8fa30434 */ 	lw	$v1,0x434($sp)
/*  f0f06b4:	3204ffff */ 	andi	$a0,$s0,0xffff
/*  f0f06b8:	05c10003 */ 	bgez	$t6,.NB0f0f06c8
/*  f0f06bc:	8fb80448 */ 	lw	$t8,0x448($sp)
/*  f0f06c0:	10000010 */ 	beqz	$zero,.NB0f0f0704
/*  f0f06c4:	ae200058 */ 	sw	$zero,0x58($s1)
.NB0f0f06c8:
/*  f0f06c8:	8e2f0004 */ 	lw	$t7,0x4($s1)
/*  f0f06cc:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f0f06d0:	03033023 */ 	subu	$a2,$t8,$v1
/*  f0f06d4:	27a70438 */ 	addiu	$a3,$sp,0x438
/*  f0f06d8:	0c0091a1 */ 	jal	func0f1a7794
/*  f0f06dc:	01e32821 */ 	addu	$a1,$t7,$v1
/*  f0f06e0:	ae220058 */ 	sw	$v0,0x58($s1)
/*  f0f06e4:	0fc586ed */ 	jal	fileGetSize
/*  f0f06e8:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0f06ec:	8e240058 */ 	lw	$a0,0x58($s1)
/*  f0f06f0:	8fa50428 */ 	lw	$a1,0x428($sp)
/*  f0f06f4:	0fc0b5be */ 	jal	bodyCalculateHeadOffset
/*  f0f06f8:	8fa6042c */ 	lw	$a2,0x42c($sp)
/*  f0f06fc:	0c008f6f */ 	jal	modelCalculateRwDataLen
/*  f0f0700:	8e240058 */ 	lw	$a0,0x58($s1)
.NB0f0f0704:
/*  f0f0704:	26240060 */ 	addiu	$a0,$s1,0x60
/*  f0f0708:	8e250054 */ 	lw	$a1,0x54($s1)
/*  f0f070c:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f0f0710:	26260110 */ 	addiu	$a2,$s1,0x110
/*  f0f0714:	0c00900f */ 	jal	modelInit
/*  f0f0718:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f071c:	26300084 */ 	addiu	$s0,$s1,0x84
/*  f0f0720:	0c00904e */ 	jal	animInit
/*  f0f0724:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f0728:	24190100 */ 	addiu	$t9,$zero,0x100
/*  f0f072c:	a6390062 */ 	sh	$t9,0x62($s1)
/*  f0f0730:	ae300080 */ 	sw	$s0,0x80($s1)
/*  f0f0734:	8e260054 */ 	lw	$a2,0x54($s1)
/*  f0f0738:	8e270058 */ 	lw	$a3,0x58($s1)
/*  f0f073c:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f0f0740:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f0744:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f0748:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f074c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0f0750:	8fa50428 */ 	lw	$a1,0x428($sp)
/*  f0f0754:	8fa4042c */ 	lw	$a0,0x42c($sp)
/*  f0f0758:	0fc0b20b */ 	jal	func0f02ce8c
/*  f0f075c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0f0760:	10000027 */ 	beqz	$zero,.NB0f0f0800
/*  f0f0764:	8e39000c */ 	lw	$t9,0xc($s1)
.NB0f0f0768:
/*  f0f0768:	0fc58635 */ 	jal	fileGetInflatedLength
/*  f0f076c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0770:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f0774:	346d003f */ 	ori	$t5,$v1,0x3f
/*  f0f0778:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0f077c:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f0f0780:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f0f0784:	25634000 */ 	addiu	$v1,$t3,0x4000
/*  f0f0788:	afa30448 */ 	sw	$v1,0x448($sp)
/*  f0f078c:	27a40438 */ 	addiu	$a0,$sp,0x438
/*  f0f0790:	01c32821 */ 	addu	$a1,$t6,$v1
/*  f0f0794:	0fc5b6c2 */ 	jal	func0f172e70
/*  f0f0798:	01e33023 */ 	subu	$a2,$t7,$v1
/*  f0f079c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0f07a0:	a6220002 */ 	sh	$v0,0x2($s1)
/*  f0f07a4:	a622056a */ 	sh	$v0,0x56a($s1)
/*  f0f07a8:	8fa60448 */ 	lw	$a2,0x448($sp)
/*  f0f07ac:	9624000e */ 	lhu	$a0,0xe($s1)
/*  f0f07b0:	8e250004 */ 	lw	$a1,0x4($s1)
/*  f0f07b4:	0c0091a1 */ 	jal	func0f1a7794
/*  f0f07b8:	27a70438 */ 	addiu	$a3,$sp,0x438
/*  f0f07bc:	ae220054 */ 	sw	$v0,0x54($s1)
/*  f0f07c0:	0fc586ed */ 	jal	fileGetSize
/*  f0f07c4:	8e24000c */ 	lw	$a0,0xc($s1)
/*  f0f07c8:	0c008f6f */ 	jal	modelCalculateRwDataLen
/*  f0f07cc:	8e240054 */ 	lw	$a0,0x54($s1)
/*  f0f07d0:	26240060 */ 	addiu	$a0,$s1,0x60
/*  f0f07d4:	8e250054 */ 	lw	$a1,0x54($s1)
/*  f0f07d8:	26260110 */ 	addiu	$a2,$s1,0x110
/*  f0f07dc:	0c00900f */ 	jal	modelInit
/*  f0f07e0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f07e4:	26300084 */ 	addiu	$s0,$s1,0x84
/*  f0f07e8:	0c00904e */ 	jal	animInit
/*  f0f07ec:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f07f0:	24180100 */ 	addiu	$t8,$zero,0x100
/*  f0f07f4:	a6380062 */ 	sh	$t8,0x62($s1)
/*  f0f07f8:	ae300080 */ 	sw	$s0,0x80($s1)
/*  f0f07fc:	8e39000c */ 	lw	$t9,0xc($s1)
.NB0f0f0800:
/*  f0f0800:	a620005e */ 	sh	$zero,0x5e($s1)
/*  f0f0804:	ae20000c */ 	sw	$zero,0xc($s1)
/*  f0f0808:	10000003 */ 	beqz	$zero,.NB0f0f0818
/*  f0f080c:	ae390010 */ 	sw	$t9,0x10($s1)
.NB0f0f0810:
/*  f0f0810:	100004e0 */ 	beqz	$zero,.NB0f0f1b94
/*  f0f0814:	8fa20468 */ 	lw	$v0,0x468($sp)
.NB0f0f0818:
/*  f0f0818:	8e2a0054 */ 	lw	$t2,0x54($s1)
.NB0f0f081c:
/*  f0f081c:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0f0820:	25ad3b28 */ 	addiu	$t5,$t5,0x3b28
/*  f0f0824:	114004da */ 	beqz	$t2,.NB0f0f1b90
/*  f0f0828:	27ac03e0 */ 	addiu	$t4,$sp,0x3e0
/*  f0f082c:	25ae003c */ 	addiu	$t6,$t5,0x3c
.NB0f0f0830:
/*  f0f0830:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0f0834:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f0f0838:	258c000c */ 	addiu	$t4,$t4,0xc
/*  f0f083c:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*  f0f0840:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f0f0844:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*  f0f0848:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f0f084c:	15aefff8 */ 	bne	$t5,$t6,.NB0f0f0830
/*  f0f0850:	ad81fffc */ 	sw	$at,-0x4($t4)
/*  f0f0854:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0f0858:	262f0060 */ 	addiu	$t7,$s1,0x60
/*  f0f085c:	ad810000 */ 	sw	$at,0x0($t4)
/*  f0f0860:	8fb80470 */ 	lw	$t8,0x470($sp)
/*  f0f0864:	afaf0040 */ 	sw	$t7,0x40($sp)
/*  f0f0868:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0f086c:	1020001b */ 	beqz	$at,.NB0f0f08dc
/*  f0f0870:	3c19800a */ 	lui	$t9,0x800a
/*  f0f0874:	8f396484 */ 	lw	$t9,0x6484($t9)
/*  f0f0878:	00195a80 */ 	sll	$t3,$t9,0xa
/*  f0f087c:	05630018 */ 	bgezl	$t3,.NB0f0f08e0
/*  f0f0880:	8faa0468 */ 	lw	$t2,0x468($sp)
/*  f0f0884:	0c002d00 */ 	jal	vi0000b280
/*  f0f0888:	8fa40468 */ 	lw	$a0,0x468($sp)
/*  f0f088c:	afa20468 */ 	sw	$v0,0x468($sp)
/*  f0f0890:	0c002cd4 */ 	jal	vi0000b1d0
/*  f0f0894:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0898:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f089c:	91ce6485 */ 	lbu	$t6,0x6485($t6)
/*  f0f08a0:	8fac0470 */ 	lw	$t4,0x470($sp)
/*  f0f08a4:	3c01800a */ 	lui	$at,0x800a
/*  f0f08a8:	31cdffdf */ 	andi	$t5,$t6,0xffdf
/*  f0f08ac:	a02d6485 */ 	sb	$t5,0x6485($at)
/*  f0f08b0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f08b4:	11810003 */ 	beq	$t4,$at,.NB0f0f08c4
/*  f0f08b8:	afa20468 */ 	sw	$v0,0x468($sp)
/*  f0f08bc:	0fc3c728 */ 	jal	menuApplyScissor
/*  f0f08c0:	00402025 */ 	or	$a0,$v0,$zero
.NB0f0f08c4:
/*  f0f08c4:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f0f08c8:	afaf0468 */ 	sw	$t7,0x468($sp)
/*  f0f08cc:	3c18b700 */ 	lui	$t8,0xb700
/*  f0f08d0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f08d4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0f08d8:	ac580000 */ 	sw	$t8,0x0($v0)
.NB0f0f08dc:
/*  f0f08dc:	8faa0468 */ 	lw	$t2,0x468($sp)
.NB0f0f08e0:
/*  f0f08e0:	3c0d8006 */ 	lui	$t5,0x8006
/*  f0f08e4:	25ad3890 */ 	addiu	$t5,$t5,0x3890
/*  f0f08e8:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0f08ec:	afab0468 */ 	sw	$t3,0x468($sp)
/*  f0f08f0:	3c0e0600 */ 	lui	$t6,0x600
/*  f0f08f4:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f0f08f8:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0f08fc:	8fac0468 */ 	lw	$t4,0x468($sp)
/*  f0f0900:	3c180600 */ 	lui	$t8,0x600
/*  f0f0904:	3c198006 */ 	lui	$t9,0x8006
/*  f0f0908:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f090c:	afaf0468 */ 	sw	$t7,0x468($sp)
/*  f0f0910:	273938b0 */ 	addiu	$t9,$t9,0x38b0
/*  f0f0914:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f0918:	afb9003c */ 	sw	$t9,0x3c($sp)
/*  f0f091c:	ad990004 */ 	sw	$t9,0x4($t4)
/*  f0f0920:	afa00330 */ 	sw	$zero,0x330($sp)
/*  f0f0924:	c6260554 */ 	lwc1	$f6,0x554($s1)
/*  f0f0928:	44802000 */ 	mtc1	$zero,$f4
/*  f0f092c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0930:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0f0934:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0938:	4500005c */ 	bc1f	.NB0f0f0aac
/*  f0f093c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f0940:	afaa031c */ 	sw	$t2,0x31c($sp)
/*  f0f0944:	8e240054 */ 	lw	$a0,0x54($s1)
/*  f0f0948:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0f094c:	256bf6a0 */ 	addiu	$t3,$t3,-2400
/*  f0f0950:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f0f0954:	556e002f */ 	bnel	$t3,$t6,.NB0f0f0a14
/*  f0f0958:	8faf031c */ 	lw	$t7,0x31c($sp)
/*  f0f095c:	0c006ea3 */ 	jal	modelGetPart
/*  f0f0960:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f0f0964:	5040002b */ 	beqzl	$v0,.NB0f0f0a14
/*  f0f0968:	8faf031c */ 	lw	$t7,0x31c($sp)
/*  f0f096c:	8e2d0574 */ 	lw	$t5,0x574($s1)
/*  f0f0970:	3c0143f0 */ 	lui	$at,0x43f0
/*  f0f0974:	44812000 */ 	mtc1	$at,$f4
/*  f0f0978:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f097c:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f0f0980:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0f0984:	0fc01a1d */ 	jal	func0f006bd0
/*  f0f0988:	46045303 */ 	div.s	$f12,$f10,$f4
/*  f0f098c:	44806000 */ 	mtc1	$zero,$f12
/*  f0f0990:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f0994:	44817000 */ 	mtc1	$at,$f14
/*  f0f0998:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f099c:	e7ac0324 */ 	swc1	$f12,0x324($sp)
/*  f0f09a0:	c6060004 */ 	lwc1	$f6,0x4($s0)
/*  f0f09a4:	c428cc58 */ 	lwc1	$f8,-0x33a8($at)
/*  f0f09a8:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0f09ac:	3c014387 */ 	lui	$at,0x4387
/*  f0f09b0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f09b4:	afac0330 */ 	sw	$t4,0x330($sp)
/*  f0f09b8:	e7ac032c */ 	swc1	$f12,0x32c($sp)
/*  f0f09bc:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0f09c0:	46047181 */ 	sub.s	$f6,$f14,$f4
/*  f0f09c4:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f09c8:	46007281 */ 	sub.s	$f10,$f14,$f0
/*  f0f09cc:	44813000 */ 	mtc1	$at,$f6
/*  f0f09d0:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0f09d4:	46086101 */ 	sub.s	$f4,$f12,$f8
/*  f0f09d8:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f09dc:	e7a40328 */ 	swc1	$f4,0x328($sp)
/*  f0f09e0:	44812000 */ 	mtc1	$at,$f4
/*  f0f09e4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f09e8:	44813000 */ 	mtc1	$at,$f6
/*  f0f09ec:	46044080 */ 	add.s	$f2,$f8,$f4
/*  f0f09f0:	e6220554 */ 	swc1	$f2,0x554($s1)
/*  f0f09f4:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*  f0f09f8:	afa0031c */ 	sw	$zero,0x31c($sp)
/*  f0f09fc:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f0a00:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f0a04:	46081103 */ 	div.s	$f4,$f2,$f8
/*  f0f0a08:	0fc19f4a */ 	jal	modelFindBboxRodata
/*  f0f0a0c:	e7a40320 */ 	swc1	$f4,0x320($sp)
/*  f0f0a10:	8faf031c */ 	lw	$t7,0x31c($sp)
.NB0f0f0a14:
/*  f0f0a14:	11e00025 */ 	beqz	$t7,.NB0f0f0aac
/*  f0f0a18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0a1c:	0fc19f4a */ 	jal	modelFindBboxRodata
/*  f0f0a20:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f0a24:	10400021 */ 	beqz	$v0,.NB0f0f0aac
/*  f0f0a28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0a2c:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0f0a30:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f0f0a34:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f0a38:	44817000 */ 	mtc1	$at,$f14
/*  f0f0a3c:	460a0181 */ 	sub.s	$f6,$f0,$f10
/*  f0f0a40:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f0a44:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0f0a48:	46080101 */ 	sub.s	$f4,$f0,$f8
/*  f0f0a4c:	46002287 */ 	neg.s	$f10,$f4
/*  f0f0a50:	e7aa0324 */ 	swc1	$f10,0x324($sp)
/*  f0f0a54:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f0f0a58:	c4420010 */ 	lwc1	$f2,0x10($v0)
/*  f0f0a5c:	46061201 */ 	sub.s	$f8,$f2,$f6
/*  f0f0a60:	460e4102 */ 	mul.s	$f4,$f8,$f14
/*  f0f0a64:	46041281 */ 	sub.s	$f10,$f2,$f4
/*  f0f0a68:	46005187 */ 	neg.s	$f6,$f10
/*  f0f0a6c:	e7a60328 */ 	swc1	$f6,0x328($sp)
/*  f0f0a70:	c4480014 */ 	lwc1	$f8,0x14($v0)
/*  f0f0a74:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f0f0a78:	afb80330 */ 	sw	$t8,0x330($sp)
/*  f0f0a7c:	46086101 */ 	sub.s	$f4,$f12,$f8
/*  f0f0a80:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*  f0f0a84:	460a6181 */ 	sub.s	$f6,$f12,$f10
/*  f0f0a88:	46003207 */ 	neg.s	$f8,$f6
/*  f0f0a8c:	e7a8032c */ 	swc1	$f8,0x32c($sp)
/*  f0f0a90:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f0f0a94:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0f0a98:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0f0a9c:	c6240554 */ 	lwc1	$f4,0x554($s1)
/*  f0f0aa0:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0f0aa4:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f0f0aa8:	e7aa0320 */ 	swc1	$f10,0x320($sp)
.NB0f0f0aac:
/*  f0f0aac:	0c005a28 */ 	jal	mtx4LoadIdentity
/*  f0f0ab0:	27a40378 */ 	addiu	$a0,$sp,0x378
/*  f0f0ab4:	8fb90470 */ 	lw	$t9,0x470($sp)
/*  f0f0ab8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f0abc:	17210083 */ 	bne	$t9,$at,.NB0f0f0ccc
/*  f0f0ac0:	3c0a8009 */ 	lui	$t2,0x8009
/*  f0f0ac4:	914a30e0 */ 	lbu	$t2,0x30e0($t2)
/*  f0f0ac8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f0acc:	27a403c0 */ 	addiu	$a0,$sp,0x3c0
/*  f0f0ad0:	11410130 */ 	beq	$t2,$at,.NB0f0f0f94
/*  f0f0ad4:	27a50378 */ 	addiu	$a1,$sp,0x378
/*  f0f0ad8:	c6200538 */ 	lwc1	$f0,0x538($s1)
/*  f0f0adc:	c6260510 */ 	lwc1	$f6,0x510($s1)
/*  f0f0ae0:	3c03800a */ 	lui	$v1,0x800a
/*  f0f0ae4:	2463e6c0 */ 	addiu	$v1,$v1,-6464
/*  f0f0ae8:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0f0aec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0af0:	45030014 */ 	bc1tl	.NB0f0f0b44
/*  f0f0af4:	c62c053c */ 	lwc1	$f12,0x53c($s1)
/*  f0f0af8:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f0f0afc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f0b00:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f0b04:	5960000f */ 	blezl	$t3,.NB0f0f0b44
/*  f0f0b08:	c62c053c */ 	lwc1	$f12,0x53c($s1)
/*  f0f0b0c:	c424cc5c */ 	lwc1	$f4,-0x33a4($at)
/*  f0f0b10:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f0b14:	46040082 */ 	mul.s	$f2,$f0,$f4
/*  f0f0b18:	c420cc60 */ 	lwc1	$f0,-0x33a0($at)
/*  f0f0b1c:	c6280510 */ 	lwc1	$f8,0x510($s1)
.NB0f0f0b20:
/*  f0f0b20:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f0b24:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0f0b28:	460a1180 */ 	add.s	$f6,$f2,$f10
/*  f0f0b2c:	e6260510 */ 	swc1	$f6,0x510($s1)
/*  f0f0b30:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0f0b34:	004e082a */ 	slt	$at,$v0,$t6
/*  f0f0b38:	5420fff9 */ 	bnezl	$at,.NB0f0f0b20
/*  f0f0b3c:	c6280510 */ 	lwc1	$f8,0x510($s1)
/*  f0f0b40:	c62c053c */ 	lwc1	$f12,0x53c($s1)
.NB0f0f0b44:
/*  f0f0b44:	c6240514 */ 	lwc1	$f4,0x514($s1)
/*  f0f0b48:	3c03800a */ 	lui	$v1,0x800a
/*  f0f0b4c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f0b50:	46046032 */ 	c.eq.s	$f12,$f4
/*  f0f0b54:	c420cc64 */ 	lwc1	$f0,-0x339c($at)
/*  f0f0b58:	2463e6c0 */ 	addiu	$v1,$v1,-6464
/*  f0f0b5c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0f0b60:	45030013 */ 	bc1tl	.NB0f0f0bb0
/*  f0f0b64:	c62c0540 */ 	lwc1	$f12,0x540($s1)
/*  f0f0b68:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f0b6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f0b70:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f0b74:	59a0000e */ 	blezl	$t5,.NB0f0f0bb0
/*  f0f0b78:	c62c0540 */ 	lwc1	$f12,0x540($s1)
/*  f0f0b7c:	c428cc68 */ 	lwc1	$f8,-0x3398($at)
/*  f0f0b80:	46086082 */ 	mul.s	$f2,$f12,$f8
/*  f0f0b84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0b88:	c62a0514 */ 	lwc1	$f10,0x514($s1)
.NB0f0f0b8c:
/*  f0f0b8c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f0b90:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0f0b94:	46061100 */ 	add.s	$f4,$f2,$f6
/*  f0f0b98:	e6240514 */ 	swc1	$f4,0x514($s1)
/*  f0f0b9c:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f0ba0:	004c082a */ 	slt	$at,$v0,$t4
/*  f0f0ba4:	5420fff9 */ 	bnezl	$at,.NB0f0f0b8c
/*  f0f0ba8:	c62a0514 */ 	lwc1	$f10,0x514($s1)
/*  f0f0bac:	c62c0540 */ 	lwc1	$f12,0x540($s1)
.NB0f0f0bb0:
/*  f0f0bb0:	c6280518 */ 	lwc1	$f8,0x518($s1)
/*  f0f0bb4:	46086032 */ 	c.eq.s	$f12,$f8
/*  f0f0bb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0bbc:	45030013 */ 	bc1tl	.NB0f0f0c0c
/*  f0f0bc0:	c62c0544 */ 	lwc1	$f12,0x544($s1)
/*  f0f0bc4:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0f0bc8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f0bcc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f0bd0:	59e0000e */ 	blezl	$t7,.NB0f0f0c0c
/*  f0f0bd4:	c62c0544 */ 	lwc1	$f12,0x544($s1)
/*  f0f0bd8:	c42acc6c */ 	lwc1	$f10,-0x3394($at)
/*  f0f0bdc:	460a6082 */ 	mul.s	$f2,$f12,$f10
/*  f0f0be0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0be4:	c6260518 */ 	lwc1	$f6,0x518($s1)
.NB0f0f0be8:
/*  f0f0be8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f0bec:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f0bf0:	46041200 */ 	add.s	$f8,$f2,$f4
/*  f0f0bf4:	e6280518 */ 	swc1	$f8,0x518($s1)
/*  f0f0bf8:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0f0bfc:	0058082a */ 	slt	$at,$v0,$t8
/*  f0f0c00:	5420fff9 */ 	bnezl	$at,.NB0f0f0be8
/*  f0f0c04:	c6260518 */ 	lwc1	$f6,0x518($s1)
/*  f0f0c08:	c62c0544 */ 	lwc1	$f12,0x544($s1)
.NB0f0f0c0c:
/*  f0f0c0c:	c62e051c */ 	lwc1	$f14,0x51c($s1)
/*  f0f0c10:	460e6032 */ 	c.eq.s	$f12,$f14
/*  f0f0c14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0c18:	45030014 */ 	bc1tl	.NB0f0f0c6c
/*  f0f0c1c:	c62a0510 */ 	lwc1	$f10,0x510($s1)
/*  f0f0c20:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f0c24:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f0c28:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f0c2c:	5b20000f */ 	blezl	$t9,.NB0f0f0c6c
/*  f0f0c30:	c62a0510 */ 	lwc1	$f10,0x510($s1)
/*  f0f0c34:	c42acc70 */ 	lwc1	$f10,-0x3390($at)
/*  f0f0c38:	460a6082 */ 	mul.s	$f2,$f12,$f10
/*  f0f0c3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0c40:	c626051c */ 	lwc1	$f6,0x51c($s1)
.NB0f0f0c44:
/*  f0f0c44:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f0c48:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f0c4c:	46041200 */ 	add.s	$f8,$f2,$f4
/*  f0f0c50:	e628051c */ 	swc1	$f8,0x51c($s1)
/*  f0f0c54:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0f0c58:	004a082a */ 	slt	$at,$v0,$t2
/*  f0f0c5c:	5420fff9 */ 	bnezl	$at,.NB0f0f0c44
/*  f0f0c60:	c626051c */ 	lwc1	$f6,0x51c($s1)
/*  f0f0c64:	c62e051c */ 	lwc1	$f14,0x51c($s1)
/*  f0f0c68:	c62a0510 */ 	lwc1	$f10,0x510($s1)
.NB0f0f0c6c:
/*  f0f0c6c:	8d6b2d88 */ 	lw	$t3,0x2d88($t3)
/*  f0f0c70:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f0c74:	e7aa0458 */ 	swc1	$f10,0x458($sp)
/*  f0f0c78:	c6320518 */ 	lwc1	$f18,0x518($s1)
/*  f0f0c7c:	15610004 */ 	bne	$t3,$at,.NB0f0f0c90
/*  f0f0c80:	c6300514 */ 	lwc1	$f16,0x514($s1)
/*  f0f0c84:	c7a60458 */ 	lwc1	$f6,0x458($sp)
/*  f0f0c88:	46063100 */ 	add.s	$f4,$f6,$f6
/*  f0f0c8c:	e7a40458 */ 	swc1	$f4,0x458($sp)
.NB0f0f0c90:
/*  f0f0c90:	e7b00454 */ 	swc1	$f16,0x454($sp)
/*  f0f0c94:	e7b20450 */ 	swc1	$f18,0x450($sp)
/*  f0f0c98:	e7ae044c */ 	swc1	$f14,0x44c($sp)
/*  f0f0c9c:	c6220548 */ 	lwc1	$f2,0x548($s1)
/*  f0f0ca0:	c62c054c */ 	lwc1	$f12,0x54c($s1)
/*  f0f0ca4:	c6200550 */ 	lwc1	$f0,0x550($s1)
/*  f0f0ca8:	e6220520 */ 	swc1	$f2,0x520($s1)
/*  f0f0cac:	e62c0524 */ 	swc1	$f12,0x524($s1)
/*  f0f0cb0:	e6200528 */ 	swc1	$f0,0x528($s1)
/*  f0f0cb4:	e7a203c0 */ 	swc1	$f2,0x3c0($sp)
/*  f0f0cb8:	e7ac03c4 */ 	swc1	$f12,0x3c4($sp)
/*  f0f0cbc:	0c005d07 */ 	jal	mtx4LoadRotation
/*  f0f0cc0:	e7a003c8 */ 	swc1	$f0,0x3c8($sp)
/*  f0f0cc4:	100000b4 */ 	beqz	$zero,.NB0f0f0f98
/*  f0f0cc8:	3c01c2c8 */ 	lui	$at,0xc2c8
.NB0f0f0ccc:
/*  f0f0ccc:	8e2205b0 */ 	lw	$v0,0x5b0($s1)
/*  f0f0cd0:	3c01800a */ 	lui	$at,0x800a
/*  f0f0cd4:	00027300 */ 	sll	$t6,$v0,0xc
/*  f0f0cd8:	000e17c2 */ 	srl	$v0,$t6,0x1f
/*  f0f0cdc:	10400093 */ 	beqz	$v0,.NB0f0f0f2c
/*  f0f0ce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0ce4:	c428e6c4 */ 	lwc1	$f8,-0x193c($at)
/*  f0f0ce8:	3c014220 */ 	lui	$at,0x4220
/*  f0f0cec:	44815000 */ 	mtc1	$at,$f10
/*  f0f0cf0:	c6240564 */ 	lwc1	$f4,0x564($s1)
/*  f0f0cf4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f0cf8:	460a4183 */ 	div.s	$f6,$f8,$f10
/*  f0f0cfc:	44815000 */ 	mtc1	$at,$f10
/*  f0f0d00:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f0d04:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0f0d08:	e6280564 */ 	swc1	$f8,0x564($s1)
/*  f0f0d0c:	c6200564 */ 	lwc1	$f0,0x564($s1)
/*  f0f0d10:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0f0d14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0d18:	45000010 */ 	bc1f	.NB0f0f0d5c
/*  f0f0d1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0d20:	922c05b1 */ 	lbu	$t4,0x5b1($s1)
/*  f0f0d24:	c6240538 */ 	lwc1	$f4,0x538($s1)
/*  f0f0d28:	c626053c */ 	lwc1	$f6,0x53c($s1)
/*  f0f0d2c:	318ffff7 */ 	andi	$t7,$t4,0xfff7
/*  f0f0d30:	a22f05b1 */ 	sb	$t7,0x5b1($s1)
/*  f0f0d34:	8e2205b0 */ 	lw	$v0,0x5b0($s1)
/*  f0f0d38:	c6280540 */ 	lwc1	$f8,0x540($s1)
/*  f0f0d3c:	c62a0544 */ 	lwc1	$f10,0x544($s1)
/*  f0f0d40:	0002c300 */ 	sll	$t8,$v0,0xc
/*  f0f0d44:	001817c2 */ 	srl	$v0,$t8,0x1f
/*  f0f0d48:	e6240510 */ 	swc1	$f4,0x510($s1)
/*  f0f0d4c:	e6260514 */ 	swc1	$f6,0x514($s1)
/*  f0f0d50:	e6280518 */ 	swc1	$f8,0x518($s1)
/*  f0f0d54:	10000075 */ 	beqz	$zero,.NB0f0f0f2c
/*  f0f0d58:	e62a051c */ 	swc1	$f10,0x51c($s1)
.NB0f0f0d5c:
/*  f0f0d5c:	c424cc74 */ 	lwc1	$f4,-0x338c($at)
/*  f0f0d60:	46040302 */ 	mul.s	$f12,$f0,$f4
/*  f0f0d64:	0c006d52 */ 	jal	cosf
/*  f0f0d68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0d6c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f0d70:	44814000 */ 	mtc1	$at,$f8
/*  f0f0d74:	46000187 */ 	neg.s	$f6,$f0
/*  f0f0d78:	44812000 */ 	mtc1	$at,$f4
/*  f0f0d7c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0f0d80:	92220568 */ 	lbu	$v0,0x568($s1)
/*  f0f0d84:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f0d88:	44813000 */ 	mtc1	$at,$f6
/*  f0f0d8c:	304a0002 */ 	andi	$t2,$v0,0x2
/*  f0f0d90:	27a403c0 */ 	addiu	$a0,$sp,0x3c0
/*  f0f0d94:	27a50378 */ 	addiu	$a1,$sp,0x378
/*  f0f0d98:	46045080 */ 	add.s	$f2,$f10,$f4
/*  f0f0d9c:	46001386 */ 	mov.s	$f14,$f2
/*  f0f0da0:	11400017 */ 	beqz	$t2,.NB0f0f0e00
/*  f0f0da4:	46023301 */ 	sub.s	$f12,$f6,$f2
/*  f0f0da8:	c6280510 */ 	lwc1	$f8,0x510($s1)
/*  f0f0dac:	c6240538 */ 	lwc1	$f4,0x538($s1)
/*  f0f0db0:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0f0db4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0db8:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f0f0dbc:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0f0dc0:	e7a80458 */ 	swc1	$f8,0x458($sp)
/*  f0f0dc4:	c6240514 */ 	lwc1	$f4,0x514($s1)
/*  f0f0dc8:	c626053c */ 	lwc1	$f6,0x53c($s1)
/*  f0f0dcc:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0f0dd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0dd4:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0f0dd8:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0f0ddc:	e7a40454 */ 	swc1	$f4,0x454($sp)
/*  f0f0de0:	c6260518 */ 	lwc1	$f6,0x518($s1)
/*  f0f0de4:	c6280540 */ 	lwc1	$f8,0x540($s1)
/*  f0f0de8:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f0f0dec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0df0:	46081102 */ 	mul.s	$f4,$f2,$f8
/*  f0f0df4:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0f0df8:	1000000b */ 	beqz	$zero,.NB0f0f0e28
/*  f0f0dfc:	e7a60450 */ 	swc1	$f6,0x450($sp)
.NB0f0f0e00:
/*  f0f0e00:	c6200538 */ 	lwc1	$f0,0x538($s1)
/*  f0f0e04:	e6200510 */ 	swc1	$f0,0x510($s1)
/*  f0f0e08:	e7a00458 */ 	swc1	$f0,0x458($sp)
/*  f0f0e0c:	c620053c */ 	lwc1	$f0,0x53c($s1)
/*  f0f0e10:	e6200514 */ 	swc1	$f0,0x514($s1)
/*  f0f0e14:	e7a00454 */ 	swc1	$f0,0x454($sp)
/*  f0f0e18:	c6200540 */ 	lwc1	$f0,0x540($s1)
/*  f0f0e1c:	e6200518 */ 	swc1	$f0,0x518($s1)
/*  f0f0e20:	e7a00450 */ 	swc1	$f0,0x450($sp)
/*  f0f0e24:	92220568 */ 	lbu	$v0,0x568($s1)
.NB0f0f0e28:
/*  f0f0e28:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f0f0e2c:	5160000a */ 	beqzl	$t3,.NB0f0f0e58
/*  f0f0e30:	c6200544 */ 	lwc1	$f0,0x544($s1)
/*  f0f0e34:	c628051c */ 	lwc1	$f8,0x51c($s1)
/*  f0f0e38:	c6240544 */ 	lwc1	$f4,0x544($s1)
/*  f0f0e3c:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0f0e40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0e44:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f0f0e48:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0f0e4c:	10000005 */ 	beqz	$zero,.NB0f0f0e64
/*  f0f0e50:	e7a8044c */ 	swc1	$f8,0x44c($sp)
/*  f0f0e54:	c6200544 */ 	lwc1	$f0,0x544($s1)
.NB0f0f0e58:
/*  f0f0e58:	e620051c */ 	swc1	$f0,0x51c($s1)
/*  f0f0e5c:	e7a0044c */ 	swc1	$f0,0x44c($sp)
/*  f0f0e60:	92220568 */ 	lbu	$v0,0x568($s1)
.NB0f0f0e64:
/*  f0f0e64:	304e0004 */ 	andi	$t6,$v0,0x4
/*  f0f0e68:	51c00024 */ 	beqzl	$t6,.NB0f0f0efc
/*  f0f0e6c:	c6220548 */ 	lwc1	$f2,0x548($s1)
/*  f0f0e70:	c6240520 */ 	lwc1	$f4,0x520($s1)
/*  f0f0e74:	27b002b8 */ 	addiu	$s0,$sp,0x2b8
/*  f0f0e78:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f0e7c:	e7a402b8 */ 	swc1	$f4,0x2b8($sp)
/*  f0f0e80:	c62a0524 */ 	lwc1	$f10,0x524($s1)
/*  f0f0e84:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f0f0e88:	e7aa02bc */ 	swc1	$f10,0x2bc($sp)
/*  f0f0e8c:	c6260528 */ 	lwc1	$f6,0x528($s1)
/*  f0f0e90:	e7ae02f8 */ 	swc1	$f14,0x2f8($sp)
/*  f0f0e94:	0fc2530c */ 	jal	func0f096ca0
/*  f0f0e98:	e7a602c0 */ 	swc1	$f6,0x2c0($sp)
/*  f0f0e9c:	c6280548 */ 	lwc1	$f8,0x548($s1)
/*  f0f0ea0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f0ea4:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f0f0ea8:	e7a802b8 */ 	swc1	$f8,0x2b8($sp)
/*  f0f0eac:	c624054c */ 	lwc1	$f4,0x54c($s1)
/*  f0f0eb0:	e7a402bc */ 	swc1	$f4,0x2bc($sp)
/*  f0f0eb4:	c62a0550 */ 	lwc1	$f10,0x550($s1)
/*  f0f0eb8:	0fc2530c */ 	jal	func0f096ca0
/*  f0f0ebc:	e7aa02c0 */ 	swc1	$f10,0x2c0($sp)
/*  f0f0ec0:	c7ae02f8 */ 	lwc1	$f14,0x2f8($sp)
/*  f0f0ec4:	27b002c4 */ 	addiu	$s0,$sp,0x2c4
/*  f0f0ec8:	02003825 */ 	or	$a3,$s0,$zero
/*  f0f0ecc:	44067000 */ 	mfc1	$a2,$f14
/*  f0f0ed0:	27a402e4 */ 	addiu	$a0,$sp,0x2e4
/*  f0f0ed4:	0fc25492 */ 	jal	func0f0972b8
/*  f0f0ed8:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f0f0edc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f0ee0:	0fc25399 */ 	jal	func0f096ed4
/*  f0f0ee4:	27a50378 */ 	addiu	$a1,$sp,0x378
/*  f0f0ee8:	8e2205b0 */ 	lw	$v0,0x5b0($s1)
/*  f0f0eec:	00026b00 */ 	sll	$t5,$v0,0xc
/*  f0f0ef0:	1000000e */ 	beqz	$zero,.NB0f0f0f2c
/*  f0f0ef4:	000d17c2 */ 	srl	$v0,$t5,0x1f
/*  f0f0ef8:	c6220548 */ 	lwc1	$f2,0x548($s1)
.NB0f0f0efc:
/*  f0f0efc:	c62c054c */ 	lwc1	$f12,0x54c($s1)
/*  f0f0f00:	c6200550 */ 	lwc1	$f0,0x550($s1)
/*  f0f0f04:	e6220520 */ 	swc1	$f2,0x520($s1)
/*  f0f0f08:	e62c0524 */ 	swc1	$f12,0x524($s1)
/*  f0f0f0c:	e6200528 */ 	swc1	$f0,0x528($s1)
/*  f0f0f10:	e7a203c0 */ 	swc1	$f2,0x3c0($sp)
/*  f0f0f14:	e7ac03c4 */ 	swc1	$f12,0x3c4($sp)
/*  f0f0f18:	0c005d07 */ 	jal	mtx4LoadRotation
/*  f0f0f1c:	e7a003c8 */ 	swc1	$f0,0x3c8($sp)
/*  f0f0f20:	8e2205b0 */ 	lw	$v0,0x5b0($s1)
/*  f0f0f24:	00027b00 */ 	sll	$t7,$v0,0xc
/*  f0f0f28:	000f17c2 */ 	srl	$v0,$t7,0x1f
.NB0f0f0f2c:
/*  f0f0f2c:	5440001a */ 	bnezl	$v0,.NB0f0f0f98
/*  f0f0f30:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f0f0f34:	c6200538 */ 	lwc1	$f0,0x538($s1)
/*  f0f0f38:	27a403c0 */ 	addiu	$a0,$sp,0x3c0
/*  f0f0f3c:	27a50378 */ 	addiu	$a1,$sp,0x378
/*  f0f0f40:	e6200510 */ 	swc1	$f0,0x510($s1)
/*  f0f0f44:	e7a00458 */ 	swc1	$f0,0x458($sp)
/*  f0f0f48:	c620053c */ 	lwc1	$f0,0x53c($s1)
/*  f0f0f4c:	e6200514 */ 	swc1	$f0,0x514($s1)
/*  f0f0f50:	e7a00454 */ 	swc1	$f0,0x454($sp)
/*  f0f0f54:	c6200540 */ 	lwc1	$f0,0x540($s1)
/*  f0f0f58:	e6200518 */ 	swc1	$f0,0x518($s1)
/*  f0f0f5c:	e7a00450 */ 	swc1	$f0,0x450($sp)
/*  f0f0f60:	c6200544 */ 	lwc1	$f0,0x544($s1)
/*  f0f0f64:	e620051c */ 	swc1	$f0,0x51c($s1)
/*  f0f0f68:	e7a0044c */ 	swc1	$f0,0x44c($sp)
/*  f0f0f6c:	c6220548 */ 	lwc1	$f2,0x548($s1)
/*  f0f0f70:	c62c054c */ 	lwc1	$f12,0x54c($s1)
/*  f0f0f74:	c6200550 */ 	lwc1	$f0,0x550($s1)
/*  f0f0f78:	e6220520 */ 	swc1	$f2,0x520($s1)
/*  f0f0f7c:	e62c0524 */ 	swc1	$f12,0x524($s1)
/*  f0f0f80:	e6200528 */ 	swc1	$f0,0x528($s1)
/*  f0f0f84:	e7a203c0 */ 	swc1	$f2,0x3c0($sp)
/*  f0f0f88:	e7ac03c4 */ 	swc1	$f12,0x3c4($sp)
/*  f0f0f8c:	0c005d07 */ 	jal	mtx4LoadRotation
/*  f0f0f90:	e7a003c8 */ 	swc1	$f0,0x3c8($sp)
.NB0f0f0f94:
/*  f0f0f94:	3c01c2c8 */ 	lui	$at,0xc2c8
.NB0f0f0f98:
/*  f0f0f98:	44813000 */ 	mtc1	$at,$f6
/*  f0f0f9c:	c7a80450 */ 	lwc1	$f8,0x450($sp)
/*  f0f0fa0:	8fb90470 */ 	lw	$t9,0x470($sp)
/*  f0f0fa4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f0fa8:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0f0fac:	17210011 */ 	bne	$t9,$at,.NB0f0f0ff4
/*  f0f0fb0:	e7a40334 */ 	swc1	$f4,0x334($sp)
/*  f0f0fb4:	3c0a8009 */ 	lui	$t2,0x8009
/*  f0f0fb8:	914a30e0 */ 	lbu	$t2,0x30e0($t2)
/*  f0f0fbc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f0fc0:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0f0fc4:	51410035 */ 	beql	$t2,$at,.NB0f0f109c
/*  f0f0fc8:	27a403b8 */ 	addiu	$a0,$sp,0x3b8
/*  f0f0fcc:	8d6b2320 */ 	lw	$t3,0x2320($t3)
/*  f0f0fd0:	c62a0510 */ 	lwc1	$f10,0x510($s1)
/*  f0f0fd4:	448b3000 */ 	mtc1	$t3,$f6
/*  f0f0fd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0fdc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f0fe0:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0f0fe4:	e7a403b8 */ 	swc1	$f4,0x3b8($sp)
/*  f0f0fe8:	c6260514 */ 	lwc1	$f6,0x514($s1)
/*  f0f0fec:	1000002a */ 	beqz	$zero,.NB0f0f1098
/*  f0f0ff0:	e7a603bc */ 	swc1	$f6,0x3bc($sp)
.NB0f0f0ff4:
/*  f0f0ff4:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0f0ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f0ffc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f1000:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f1004:	0c002f97 */ 	jal	viGetViewWidth
/*  f0f1008:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f100c:	44825000 */ 	mtc1	$v0,$f10
/*  f0f1010:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f1014:	44812000 */ 	mtc1	$at,$f4
/*  f0f1018:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0f101c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0f1020:	8dad2320 */ 	lw	$t5,0x2320($t5)
/*  f0f1024:	c7aa0458 */ 	lwc1	$f10,0x458($sp)
/*  f0f1028:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0f102c:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f1030:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1034:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0f1038:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f0f103c:	44905000 */ 	mtc1	$s0,$f10
/*  f0f1040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1044:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0f1048:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0f104c:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0f1050:	0c002fb9 */ 	jal	viGetViewTop
/*  f0f1054:	e7a803b8 */ 	swc1	$f8,0x3b8($sp)
/*  f0f1058:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f105c:	00106403 */ 	sra	$t4,$s0,0x10
/*  f0f1060:	0c002f9b */ 	jal	viGetViewHeight
/*  f0f1064:	01808025 */ 	or	$s0,$t4,$zero
/*  f0f1068:	44822000 */ 	mtc1	$v0,$f4
/*  f0f106c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f1070:	44815000 */ 	mtc1	$at,$f10
/*  f0f1074:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f1078:	c7a40454 */ 	lwc1	$f4,0x454($sp)
/*  f0f107c:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0f1080:	44903000 */ 	mtc1	$s0,$f6
/*  f0f1084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1088:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0f108c:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0f1090:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0f1094:	e7a403bc */ 	swc1	$f4,0x3bc($sp)
.NB0f0f1098:
/*  f0f1098:	27a403b8 */ 	addiu	$a0,$sp,0x3b8
.NB0f0f109c:
/*  f0f109c:	27a503c0 */ 	addiu	$a1,$sp,0x3c0
/*  f0f10a0:	0fc2ca67 */ 	jal	func0f0b4c3c
/*  f0f10a4:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0f10a8:	0c005a28 */ 	jal	mtx4LoadIdentity
/*  f0f10ac:	27a40338 */ 	addiu	$a0,$sp,0x338
/*  f0f10b0:	8e2205b4 */ 	lw	$v0,0x5b4($s1)
/*  f0f10b4:	5040001d */ 	beqzl	$v0,.NB0f0f112c
/*  f0f10b8:	8fb90470 */ 	lw	$t9,0x470($sp)
/*  f0f10bc:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f0f10c0:	241000ff */ 	addiu	$s0,$zero,0xff
/*  f0f10c4:	00401825 */ 	or	$v1,$v0,$zero
/*  f0f10c8:	52050018 */ 	beql	$s0,$a1,.NB0f0f112c
/*  f0f10cc:	8fb90470 */ 	lw	$t9,0x470($sp)
/*  f0f10d0:	8e240054 */ 	lw	$a0,0x54($s1)
.NB0f0f10d4:
/*  f0f10d4:	0c006ea3 */ 	jal	modelGetPart
/*  f0f10d8:	afa302b4 */ 	sw	$v1,0x2b4($sp)
/*  f0f10dc:	8fa302b4 */ 	lw	$v1,0x2b4($sp)
/*  f0f10e0:	1040000d */ 	beqz	$v0,.NB0f0f1118
/*  f0f10e4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0f10e8:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f10ec:	0c006bab */ 	jal	modelGetNodeRwData
/*  f0f10f0:	afa302b4 */ 	sw	$v1,0x2b4($sp)
/*  f0f10f4:	10400008 */ 	beqz	$v0,.NB0f0f1118
/*  f0f10f8:	8fa302b4 */ 	lw	$v1,0x2b4($sp)
/*  f0f10fc:	906f0001 */ 	lbu	$t7,0x1($v1)
/*  f0f1100:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f1104:	51e00004 */ 	beqzl	$t7,.NB0f0f1118
/*  f0f1108:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0f110c:	10000002 */ 	beqz	$zero,.NB0f0f1118
/*  f0f1110:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0f1114:	ac400000 */ 	sw	$zero,0x0($v0)
.NB0f0f1118:
/*  f0f1118:	90650002 */ 	lbu	$a1,0x2($v1)
/*  f0f111c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0f1120:	5605ffec */ 	bnel	$s0,$a1,.NB0f0f10d4
/*  f0f1124:	8e240054 */ 	lw	$a0,0x54($s1)
/*  f0f1128:	8fb90470 */ 	lw	$t9,0x470($sp)
.NB0f0f112c:
/*  f0f112c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f1130:	57210009 */ 	bnel	$t9,$at,.NB0f0f1158
/*  f0f1134:	c7a203c8 */ 	lwc1	$f2,0x3c8($sp)
/*  f0f1138:	c62a0510 */ 	lwc1	$f10,0x510($s1)
/*  f0f113c:	e7aa03c0 */ 	swc1	$f10,0x3c0($sp)
/*  f0f1140:	c6280514 */ 	lwc1	$f8,0x514($s1)
/*  f0f1144:	e7a803c4 */ 	swc1	$f8,0x3c4($sp)
/*  f0f1148:	c6260518 */ 	lwc1	$f6,0x518($s1)
/*  f0f114c:	1000000e */ 	beqz	$zero,.NB0f0f1188
/*  f0f1150:	e7a603c8 */ 	swc1	$f6,0x3c8($sp)
/*  f0f1154:	c7a203c8 */ 	lwc1	$f2,0x3c8($sp)
.NB0f0f1158:
/*  f0f1158:	c7a40334 */ 	lwc1	$f4,0x334($sp)
/*  f0f115c:	c7aa03c0 */ 	lwc1	$f10,0x3c0($sp)
/*  f0f1160:	c7a603c4 */ 	lwc1	$f6,0x3c4($sp)
/*  f0f1164:	46022003 */ 	div.s	$f0,$f4,$f2
/*  f0f1168:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0f116c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1170:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f1174:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1178:	46020082 */ 	mul.s	$f2,$f0,$f2
/*  f0f117c:	e7a803c0 */ 	swc1	$f8,0x3c0($sp)
/*  f0f1180:	e7a403c4 */ 	swc1	$f4,0x3c4($sp)
/*  f0f1184:	e7a203c8 */ 	swc1	$f2,0x3c8($sp)
.NB0f0f1188:
/*  f0f1188:	8e2a0010 */ 	lw	$t2,0x10($s1)
/*  f0f118c:	000a5800 */ 	sll	$t3,$t2,0x0
/*  f0f1190:	05610015 */ 	bgez	$t3,.NB0f0f11e8
/*  f0f1194:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f1198:	25ce3b68 */ 	addiu	$t6,$t6,0x3b68
/*  f0f119c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0f11a0:	27b00294 */ 	addiu	$s0,$sp,0x294
/*  f0f11a4:	ae010000 */ 	sw	$at,0x0($s0)
/*  f0f11a8:	8dcc0004 */ 	lw	$t4,0x4($t6)
/*  f0f11ac:	ae0c0004 */ 	sw	$t4,0x4($s0)
/*  f0f11b0:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0f11b4:	ae010008 */ 	sw	$at,0x8($s0)
/*  f0f11b8:	0c00710f */ 	jal	model0001b3bc
/*  f0f11bc:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f11c0:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f11c4:	0c006f63 */ 	jal	modelGetRootPosition
/*  f0f11c8:	27a502a0 */ 	addiu	$a1,$sp,0x2a0
/*  f0f11cc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f11d0:	0c005790 */ 	jal	joyGetButtons
/*  f0f11d4:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f0f11d8:	10400003 */ 	beqz	$v0,.NB0f0f11e8
/*  f0f11dc:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f11e0:	0c006f6d */ 	jal	modelSetRootPosition
/*  f0f11e4:	02002825 */ 	or	$a1,$s0,$zero
.NB0f0f11e8:
/*  f0f11e8:	27a403c0 */ 	addiu	$a0,$sp,0x3c0
/*  f0f11ec:	0c005d9b */ 	jal	mtx4LoadTranslation
/*  f0f11f0:	27a50338 */ 	addiu	$a1,$sp,0x338
/*  f0f11f4:	8faf0330 */ 	lw	$t7,0x330($sp)
/*  f0f11f8:	51e0000a */ 	beqzl	$t7,.NB0f0f1224
/*  f0f11fc:	c7ac044c */ 	lwc1	$f12,0x44c($sp)
/*  f0f1200:	c7aa044c */ 	lwc1	$f10,0x44c($sp)
/*  f0f1204:	c7a80320 */ 	lwc1	$f8,0x320($sp)
/*  f0f1208:	27a50338 */ 	addiu	$a1,$sp,0x338
/*  f0f120c:	46085302 */ 	mul.s	$f12,$f10,$f8
/*  f0f1210:	0c005b7d */ 	jal	mtx00015f04
/*  f0f1214:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1218:	10000005 */ 	beqz	$zero,.NB0f0f1230
/*  f0f121c:	8fb80330 */ 	lw	$t8,0x330($sp)
/*  f0f1220:	c7ac044c */ 	lwc1	$f12,0x44c($sp)
.NB0f0f1224:
/*  f0f1224:	0c005b7d */ 	jal	mtx00015f04
/*  f0f1228:	27a50338 */ 	addiu	$a1,$sp,0x338
/*  f0f122c:	8fb80330 */ 	lw	$t8,0x330($sp)
.NB0f0f1230:
/*  f0f1230:	13000005 */ 	beqz	$t8,.NB0f0f1248
/*  f0f1234:	27a40324 */ 	addiu	$a0,$sp,0x324
/*  f0f1238:	0c005d9b */ 	jal	mtx4LoadTranslation
/*  f0f123c:	27a50208 */ 	addiu	$a1,$sp,0x208
/*  f0f1240:	1000000b */ 	beqz	$zero,.NB0f0f1270
/*  f0f1244:	27b00248 */ 	addiu	$s0,$sp,0x248
.NB0f0f1248:
/*  f0f1248:	c626052c */ 	lwc1	$f6,0x52c($s1)
/*  f0f124c:	27a403c0 */ 	addiu	$a0,$sp,0x3c0
/*  f0f1250:	27a50208 */ 	addiu	$a1,$sp,0x208
/*  f0f1254:	e7a603c0 */ 	swc1	$f6,0x3c0($sp)
/*  f0f1258:	c6240530 */ 	lwc1	$f4,0x530($s1)
/*  f0f125c:	e7a403c4 */ 	swc1	$f4,0x3c4($sp)
/*  f0f1260:	c62a0534 */ 	lwc1	$f10,0x534($s1)
/*  f0f1264:	0c005d9b */ 	jal	mtx4LoadTranslation
/*  f0f1268:	e7aa03c8 */ 	swc1	$f10,0x3c8($sp)
/*  f0f126c:	27b00248 */ 	addiu	$s0,$sp,0x248
.NB0f0f1270:
/*  f0f1270:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f1274:	27a40338 */ 	addiu	$a0,$sp,0x338
/*  f0f1278:	0c005a3c */ 	jal	mtx4MultMtx4
/*  f0f127c:	27a50378 */ 	addiu	$a1,$sp,0x378
/*  f0f1280:	8fb90470 */ 	lw	$t9,0x470($sp)
/*  f0f1284:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f1288:	5721000f */ 	bnel	$t9,$at,.NB0f0f12c8
/*  f0f128c:	26260014 */ 	addiu	$a2,$s1,0x14
/*  f0f1290:	0fc4d643 */ 	jal	func0f13ae04
/*  f0f1294:	27a401c8 */ 	addiu	$a0,$sp,0x1c8
/*  f0f1298:	27a401c8 */ 	addiu	$a0,$sp,0x1c8
/*  f0f129c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f12a0:	0c005a3c */ 	jal	mtx4MultMtx4
/*  f0f12a4:	27a60188 */ 	addiu	$a2,$sp,0x188
/*  f0f12a8:	26260014 */ 	addiu	$a2,$s1,0x14
/*  f0f12ac:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f0f12b0:	27a40188 */ 	addiu	$a0,$sp,0x188
/*  f0f12b4:	0c005a3c */ 	jal	mtx4MultMtx4
/*  f0f12b8:	27a50208 */ 	addiu	$a1,$sp,0x208
/*  f0f12bc:	10000006 */ 	beqz	$zero,.NB0f0f12d8
/*  f0f12c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f12c4:	26260014 */ 	addiu	$a2,$s1,0x14
.NB0f0f12c8:
/*  f0f12c8:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f0f12cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f12d0:	0c005a3c */ 	jal	mtx4MultMtx4
/*  f0f12d4:	27a50208 */ 	addiu	$a1,$sp,0x208
.NB0f0f12d8:
/*  f0f12d8:	0fc37df7 */ 	jal	func0f0e2348
/*  f0f12dc:	8fa40468 */ 	lw	$a0,0x468($sp)
/*  f0f12e0:	8faa0470 */ 	lw	$t2,0x470($sp)
/*  f0f12e4:	afa20468 */ 	sw	$v0,0x468($sp)
/*  f0f12e8:	29410003 */ 	slti	$at,$t2,0x3
/*  f0f12ec:	5020006f */ 	beqzl	$at,.NB0f0f14ac
/*  f0f12f0:	8e2f0054 */ 	lw	$t7,0x54($s1)
/*  f0f12f4:	1140000e */ 	beqz	$t2,.NB0f0f1330
/*  f0f12f8:	3c10800a */ 	lui	$s0,0x800a
/*  f0f12fc:	0fc34852 */ 	jal	func0f0d49c8
/*  f0f1300:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f1304:	244b0008 */ 	addiu	$t3,$v0,0x8
/*  f0f1308:	3c0d0103 */ 	lui	$t5,0x103
/*  f0f130c:	35ad0040 */ 	ori	$t5,$t5,0x40
/*  f0f1310:	afab0468 */ 	sw	$t3,0x468($sp)
/*  f0f1314:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0f1318:	0fc2cb52 */ 	jal	currentPlayerGetUnk1750
/*  f0f131c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f1320:	0c013100 */ 	jal	osVirtualToPhysical
/*  f0f1324:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f1328:	1000005f */ 	beqz	$zero,.NB0f0f14a8
/*  f0f132c:	ae020004 */ 	sw	$v0,0x4($s0)
.NB0f0f1330:
/*  f0f1330:	26106528 */ 	addiu	$s0,$s0,0x6528
/*  f0f1334:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f1338:	3c18800a */ 	lui	$t8,0x800a
/*  f0f133c:	3c19800a */ 	lui	$t9,0x800a
/*  f0f1340:	8f396530 */ 	lw	$t9,0x6530($t9)
/*  f0f1344:	8f186534 */ 	lw	$t8,0x6534($t8)
/*  f0f1348:	8dce652c */ 	lw	$t6,0x652c($t6)
/*  f0f134c:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f0f1350:	03195023 */ 	subu	$t2,$t8,$t9
/*  f0f1354:	448a2000 */ 	mtc1	$t2,$f4
/*  f0f1358:	01cc7823 */ 	subu	$t7,$t6,$t4
/*  f0f135c:	448f4000 */ 	mtc1	$t7,$f8
/*  f0f1360:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0f1364:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f1368:	3c058007 */ 	lui	$a1,0x8007
/*  f0f136c:	24a53b74 */ 	addiu	$a1,$a1,0x3b74
/*  f0f1370:	2484c91c */ 	addiu	$a0,$a0,-14052
/*  f0f1374:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0f1378:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f0f137c:	0c00381c */ 	jal	mainOverrideVariable
/*  f0f1380:	e7a80180 */ 	swc1	$f8,0x180($sp)
/*  f0f1384:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f1388:	3c058007 */ 	lui	$a1,0x8007
/*  f0f138c:	24a53b78 */ 	addiu	$a1,$a1,0x3b78
/*  f0f1390:	0c00381c */ 	jal	mainOverrideVariable
/*  f0f1394:	2484c920 */ 	addiu	$a0,$a0,-14048
/*  f0f1398:	0fc34852 */ 	jal	func0f0d49c8
/*  f0f139c:	8fa40468 */ 	lw	$a0,0x468($sp)
/*  f0f13a0:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0f13a4:	8dad2320 */ 	lw	$t5,0x2320($t5)
/*  f0f13a8:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f0f13ac:	3c05800a */ 	lui	$a1,0x800a
/*  f0f13b0:	afa20468 */ 	sw	$v0,0x468($sp)
/*  f0f13b4:	016d0019 */ 	multu	$t3,$t5
/*  f0f13b8:	84a56532 */ 	lh	$a1,0x6532($a1)
/*  f0f13bc:	00002012 */ 	mflo	$a0
/*  f0f13c0:	00047400 */ 	sll	$t6,$a0,0x10
/*  f0f13c4:	0c002f9f */ 	jal	viSetViewPosition
/*  f0f13c8:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f0f13cc:	3c18800a */ 	lui	$t8,0x800a
/*  f0f13d0:	8f18652c */ 	lw	$t8,0x652c($t8)
/*  f0f13d4:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0f13d8:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0f13dc:	8d6b2320 */ 	lw	$t3,0x2320($t3)
/*  f0f13e0:	03195023 */ 	subu	$t2,$t8,$t9
/*  f0f13e4:	3c0f800a */ 	lui	$t7,0x800a
/*  f0f13e8:	014b0019 */ 	multu	$t2,$t3
/*  f0f13ec:	8defe944 */ 	lw	$t7,-0x16bc($t7)
/*  f0f13f0:	3c0c800a */ 	lui	$t4,0x800a
/*  f0f13f4:	8d8c6534 */ 	lw	$t4,0x6534($t4)
/*  f0f13f8:	c5ec1854 */ 	lwc1	$f12,0x1854($t7)
/*  f0f13fc:	3c0f800a */ 	lui	$t7,0x800a
/*  f0f1400:	8def6530 */ 	lw	$t7,0x6530($t7)
/*  f0f1404:	c7ae0180 */ 	lwc1	$f14,0x180($sp)
/*  f0f1408:	018f3823 */ 	subu	$a3,$t4,$t7
/*  f0f140c:	00003012 */ 	mflo	$a2
/*  f0f1410:	00066c00 */ 	sll	$t5,$a2,0x10
/*  f0f1414:	0007c400 */ 	sll	$t8,$a3,0x10
/*  f0f1418:	00183c03 */ 	sra	$a3,$t8,0x10
/*  f0f141c:	0c002feb */ 	jal	viSetFovAspectAndSize
/*  f0f1420:	000d3403 */ 	sra	$a2,$t5,0x10
/*  f0f1424:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0f1428:	8d4a3af0 */ 	lw	$t2,0x3af0($t2)
/*  f0f142c:	3c0d800a */ 	lui	$t5,0x800a
/*  f0f1430:	25ad6538 */ 	addiu	$t5,$t5,0x6538
/*  f0f1434:	000a5940 */ 	sll	$t3,$t2,0x5
/*  f0f1438:	016d2821 */ 	addu	$a1,$t3,$t5
/*  f0f143c:	0c002c20 */ 	jal	vi0000af00
/*  f0f1440:	8fa40468 */ 	lw	$a0,0x468($sp)
/*  f0f1444:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f1448:	8dce3b74 */ 	lw	$t6,0x3b74($t6)
/*  f0f144c:	afa20468 */ 	sw	$v0,0x468($sp)
/*  f0f1450:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f1454:	448e2000 */ 	mtc1	$t6,$f4
/*  f0f1458:	3c0c8007 */ 	lui	$t4,0x8007
/*  f0f145c:	05c10005 */ 	bgez	$t6,.NB0f0f1474
/*  f0f1460:	46802120 */ 	cvt.s.w	$f4,$f4
/*  f0f1464:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f1468:	44813000 */ 	mtc1	$at,$f6
/*  f0f146c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1470:	46062100 */ 	add.s	$f4,$f4,$f6
.NB0f0f1474:
/*  f0f1474:	8d8c3b78 */ 	lw	$t4,0x3b78($t4)
/*  f0f1478:	44052000 */ 	mfc1	$a1,$f4
/*  f0f147c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f1480:	448c5000 */ 	mtc1	$t4,$f10
/*  f0f1484:	05810004 */ 	bgez	$t4,.NB0f0f1498
/*  f0f1488:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f0f148c:	44814000 */ 	mtc1	$at,$f8
/*  f0f1490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1494:	46085280 */ 	add.s	$f10,$f10,$f8
.NB0f0f1498:
/*  f0f1498:	44065000 */ 	mfc1	$a2,$f10
/*  f0f149c:	0c002b89 */ 	jal	vi0000aca4
/*  f0f14a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f14a4:	afa20468 */ 	sw	$v0,0x468($sp)
.NB0f0f14a8:
/*  f0f14a8:	8e2f0054 */ 	lw	$t7,0x54($s1)
.NB0f0f14ac:
/*  f0f14ac:	85e4000e */ 	lh	$a0,0xe($t7)
/*  f0f14b0:	0004c180 */ 	sll	$t8,$a0,0x6
/*  f0f14b4:	0fc588cd */ 	jal	gfxAllocate
/*  f0f14b8:	03002025 */ 	or	$a0,$t8,$zero
/*  f0f14bc:	afa203dc */ 	sw	$v0,0x3dc($sp)
/*  f0f14c0:	8e390054 */ 	lw	$t9,0x54($s1)
/*  f0f14c4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0f14c8:	872a000e */ 	lh	$t2,0xe($t9)
/*  f0f14cc:	5940000d */ 	blezl	$t2,.NB0f0f1504
/*  f0f14d0:	8625005c */ 	lh	$a1,0x5c($s1)
/*  f0f14d4:	8fad03dc */ 	lw	$t5,0x3dc($sp)
.NB0f0f14d8:
/*  f0f14d8:	00105980 */ 	sll	$t3,$s0,0x6
/*  f0f14dc:	0c005a28 */ 	jal	mtx4LoadIdentity
/*  f0f14e0:	016d2021 */ 	addu	$a0,$t3,$t5
/*  f0f14e4:	8e2e0054 */ 	lw	$t6,0x54($s1)
/*  f0f14e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0f14ec:	85cc000e */ 	lh	$t4,0xe($t6)
/*  f0f14f0:	020c082a */ 	slt	$at,$s0,$t4
/*  f0f14f4:	5420fff8 */ 	bnezl	$at,.NB0f0f14d8
/*  f0f14f8:	8fad03dc */ 	lw	$t5,0x3dc($sp)
/*  f0f14fc:	00008025 */ 	or	$s0,$zero,$zero
/*  f0f1500:	8625005c */ 	lh	$a1,0x5c($s1)
.NB0f0f1504:
/*  f0f1504:	8faf03dc */ 	lw	$t7,0x3dc($sp)
/*  f0f1508:	10a00025 */ 	beqz	$a1,.NB0f0f15a0
/*  f0f150c:	ae2f006c */ 	sw	$t7,0x6c($s1)
/*  f0f1510:	8638005e */ 	lh	$t8,0x5e($s1)
/*  f0f1514:	50b80023 */ 	beql	$a1,$t8,.NB0f0f15a4
/*  f0f1518:	862e005e */ 	lh	$t6,0x5e($s1)
/*  f0f151c:	8e3905b0 */ 	lw	$t9,0x5b0($s1)
/*  f0f1520:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f1524:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f1528:	00195ac0 */ 	sll	$t3,$t9,0xb
/*  f0f152c:	05610014 */ 	bgez	$t3,.NB0f0f1580
/*  f0f1530:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f1534:	3c01bf00 */ 	lui	$at,0xbf00
/*  f0f1538:	44812000 */ 	mtc1	$at,$f4
/*  f0f153c:	44803000 */ 	mtc1	$zero,$f6
/*  f0f1540:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f1544:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f1548:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0f154c:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0f1550:	0c007b53 */ 	jal	modelSetAnimation
/*  f0f1554:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0f1558:	0c0078a6 */ 	jal	modelGetNumAnimFrames
/*  f0f155c:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f1560:	44825000 */ 	mtc1	$v0,$f10
/*  f0f1564:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f1568:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f0f156c:	44055000 */ 	mfc1	$a1,$f10
/*  f0f1570:	0c007c2c */ 	jal	model0001e018
/*  f0f1574:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1578:	10000008 */ 	beqz	$zero,.NB0f0f159c
/*  f0f157c:	862d005c */ 	lh	$t5,0x5c($s1)
.NB0f0f1580:
/*  f0f1580:	44814000 */ 	mtc1	$at,$f8
/*  f0f1584:	44802000 */ 	mtc1	$zero,$f4
/*  f0f1588:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0f158c:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0f1590:	0c007b53 */ 	jal	modelSetAnimation
/*  f0f1594:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0f1598:	862d005c */ 	lh	$t5,0x5c($s1)
.NB0f0f159c:
/*  f0f159c:	a62d005e */ 	sh	$t5,0x5e($s1)
.NB0f0f15a0:
/*  f0f15a0:	862e005e */ 	lh	$t6,0x5e($s1)
.NB0f0f15a4:
/*  f0f15a4:	a620005c */ 	sh	$zero,0x5c($s1)
/*  f0f15a8:	11c00023 */ 	beqz	$t6,.NB0f0f1638
/*  f0f15ac:	3c05800a */ 	lui	$a1,0x800a
/*  f0f15b0:	8ca5e700 */ 	lw	$a1,-0x1900($a1)
/*  f0f15b4:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f15b8:	0c007fac */ 	jal	model0001ee18
/*  f0f15bc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0f15c0:	8e2c05b0 */ 	lw	$t4,0x5b0($s1)
/*  f0f15c4:	000cc2c0 */ 	sll	$t8,$t4,0xb
/*  f0f15c8:	0701000c */ 	bgez	$t8,.NB0f0f15fc
/*  f0f15cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f15d0:	0c0078a6 */ 	jal	modelGetNumAnimFrames
/*  f0f15d4:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f15d8:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0f15dc:	0c00787f */ 	jal	modelGetCurAnimFrame
/*  f0f15e0:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f15e4:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f15e8:	44993000 */ 	mtc1	$t9,$f6
/*  f0f15ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f15f0:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0f15f4:	10000004 */ 	beqz	$zero,.NB0f0f1608
/*  f0f15f8:	46005081 */ 	sub.s	$f2,$f10,$f0
.NB0f0f15fc:
/*  f0f15fc:	0c00787f */ 	jal	modelGetCurAnimFrame
/*  f0f1600:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f1604:	46000086 */ 	mov.s	$f2,$f0
.NB0f0f1608:
/*  f0f1608:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f160c:	0c0078a6 */ 	jal	modelGetNumAnimFrames
/*  f0f1610:	e7a2017c */ 	swc1	$f2,0x17c($sp)
/*  f0f1614:	244affff */ 	addiu	$t2,$v0,-1
/*  f0f1618:	448a4000 */ 	mtc1	$t2,$f8
/*  f0f161c:	c7a2017c */ 	lwc1	$f2,0x17c($sp)
/*  f0f1620:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0f1624:	4602203e */ 	c.le.s	$f4,$f2
/*  f0f1628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f162c:	45020003 */ 	bc1fl	.NB0f0f163c
/*  f0f1630:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0f1634:	a620005e */ 	sh	$zero,0x5e($s1)
.NB0f0f1638:
/*  f0f1638:	8fa40044 */ 	lw	$a0,0x44($sp)
.NB0f0f163c:
/*  f0f163c:	0c005b02 */ 	jal	mtx4Copy
/*  f0f1640:	8fa503dc */ 	lw	$a1,0x3dc($sp)
/*  f0f1644:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f0f1648:	27a403e0 */ 	addiu	$a0,$sp,0x3e0
/*  f0f164c:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0f1650:	afab03e0 */ 	sw	$t3,0x3e0($sp)
/*  f0f1654:	8e2d006c */ 	lw	$t5,0x6c($s1)
/*  f0f1658:	0c0077cf */ 	jal	model0001cebc
/*  f0f165c:	afad03f0 */ 	sw	$t5,0x3f0($sp)
/*  f0f1660:	8e240054 */ 	lw	$a0,0x54($s1)
/*  f0f1664:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0f1668:	25cef494 */ 	addiu	$t6,$t6,-2924
/*  f0f166c:	8c8c0004 */ 	lw	$t4,0x4($a0)
/*  f0f1670:	55cc0092 */ 	bnel	$t6,$t4,.NB0f0f18bc
/*  f0f1674:	8fae0468 */ 	lw	$t6,0x468($sp)
/*  f0f1678:	0c006ea3 */ 	jal	modelGetPart
/*  f0f167c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f1680:	5040002e */ 	beqzl	$v0,.NB0f0f173c
/*  f0f1684:	8e240054 */ 	lw	$a0,0x54($s1)
/*  f0f1688:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f0f168c:	3c09800a */ 	lui	$t1,0x800a
/*  f0f1690:	2529e6c0 */ 	addiu	$t1,$t1,-6464
/*  f0f1694:	84af0010 */ 	lh	$t7,0x10($a1)
/*  f0f1698:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f169c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f16a0:	19e00025 */ 	blez	$t7,.NB0f0f1738
/*  f0f16a4:	24080064 */ 	addiu	$t0,$zero,0x64
/*  f0f16a8:	8d2a0000 */ 	lw	$t2,0x0($t1)
.NB0f0f16ac:
/*  f0f16ac:	8cb8000c */ 	lw	$t8,0xc($a1)
/*  f0f16b0:	01480019 */ 	multu	$t2,$t0
/*  f0f16b4:	03061021 */ 	addu	$v0,$t8,$a2
/*  f0f16b8:	84590008 */ 	lh	$t9,0x8($v0)
/*  f0f16bc:	00005812 */ 	mflo	$t3
/*  f0f16c0:	032b6823 */ 	subu	$t5,$t9,$t3
/*  f0f16c4:	a44d0008 */ 	sh	$t5,0x8($v0)
/*  f0f16c8:	8cae000c */ 	lw	$t6,0xc($a1)
/*  f0f16cc:	01c66021 */ 	addu	$t4,$t6,$a2
/*  f0f16d0:	858f0008 */ 	lh	$t7,0x8($t4)
/*  f0f16d4:	29e1a000 */ 	slti	$at,$t7,-24576
/*  f0f16d8:	50200012 */ 	beqzl	$at,.NB0f0f1724
/*  f0f16dc:	84ae0010 */ 	lh	$t6,0x10($a1)
/*  f0f16e0:	84b80010 */ 	lh	$t8,0x10($a1)
/*  f0f16e4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f16e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f16ec:	5b00000d */ 	blezl	$t8,.NB0f0f1724
/*  f0f16f0:	84ae0010 */ 	lh	$t6,0x10($a1)
/*  f0f16f4:	8caa000c */ 	lw	$t2,0xc($a1)
.NB0f0f16f8:
/*  f0f16f8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f16fc:	01441021 */ 	addu	$v0,$t2,$a0
/*  f0f1700:	84590008 */ 	lh	$t9,0x8($v0)
/*  f0f1704:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f0f1708:	272b2000 */ 	addiu	$t3,$t9,0x2000
/*  f0f170c:	a44b0008 */ 	sh	$t3,0x8($v0)
/*  f0f1710:	84ad0010 */ 	lh	$t5,0x10($a1)
/*  f0f1714:	006d082a */ 	slt	$at,$v1,$t5
/*  f0f1718:	5420fff7 */ 	bnezl	$at,.NB0f0f16f8
/*  f0f171c:	8caa000c */ 	lw	$t2,0xc($a1)
/*  f0f1720:	84ae0010 */ 	lh	$t6,0x10($a1)
.NB0f0f1724:
/*  f0f1724:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f0f1728:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f0f172c:	00ee082a */ 	slt	$at,$a3,$t6
/*  f0f1730:	5420ffde */ 	bnezl	$at,.NB0f0f16ac
/*  f0f1734:	8d2a0000 */ 	lw	$t2,0x0($t1)
.NB0f0f1738:
/*  f0f1738:	8e240054 */ 	lw	$a0,0x54($s1)
.NB0f0f173c:
/*  f0f173c:	0c006ea3 */ 	jal	modelGetPart
/*  f0f1740:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0f1744:	10400019 */ 	beqz	$v0,.NB0f0f17ac
/*  f0f1748:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f174c:	0c006da5 */ 	jal	model0001a524
/*  f0f1750:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f1754:	afa20164 */ 	sw	$v0,0x164($sp)
/*  f0f1758:	0c005a28 */ 	jal	mtx4LoadIdentity
/*  f0f175c:	27a40124 */ 	addiu	$a0,$sp,0x124
/*  f0f1760:	3c014080 */ 	lui	$at,0x4080
/*  f0f1764:	44816000 */ 	mtc1	$at,$f12
/*  f0f1768:	0fc019fe */ 	jal	func0f006b54
/*  f0f176c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1770:	46000306 */ 	mov.s	$f12,$f0
/*  f0f1774:	0c005c9e */ 	jal	mtx4LoadXRotation
/*  f0f1778:	27a50124 */ 	addiu	$a1,$sp,0x124
/*  f0f177c:	8faf0164 */ 	lw	$t7,0x164($sp)
/*  f0f1780:	8fac03dc */ 	lw	$t4,0x3dc($sp)
/*  f0f1784:	27a50124 */ 	addiu	$a1,$sp,0x124
/*  f0f1788:	000fc180 */ 	sll	$t8,$t7,0x6
/*  f0f178c:	01983821 */ 	addu	$a3,$t4,$t8
/*  f0f1790:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0f1794:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f0f1798:	0c005a3c */ 	jal	mtx4MultMtx4
/*  f0f179c:	27a600e4 */ 	addiu	$a2,$sp,0xe4
/*  f0f17a0:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0f17a4:	0c005b02 */ 	jal	mtx4Copy
/*  f0f17a8:	27a400e4 */ 	addiu	$a0,$sp,0xe4
.NB0f0f17ac:
/*  f0f17ac:	8e240054 */ 	lw	$a0,0x54($s1)
/*  f0f17b0:	0c006ea3 */ 	jal	modelGetPart
/*  f0f17b4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0f17b8:	1040003f */ 	beqz	$v0,.NB0f0f18b8
/*  f0f17bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f17c0:	3c02800a */ 	lui	$v0,0x800a
/*  f0f17c4:	8c425eb4 */ 	lw	$v0,0x5eb4($v0)
/*  f0f17c8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f17cc:	10410007 */ 	beq	$v0,$at,.NB0f0f17ec
/*  f0f17d0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f17d4:	10410005 */ 	beq	$v0,$at,.NB0f0f17ec
/*  f0f17d8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f17dc:	10410003 */ 	beq	$v0,$at,.NB0f0f17ec
/*  f0f17e0:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f17e4:	54410035 */ 	bnel	$v0,$at,.NB0f0f18bc
/*  f0f17e8:	8fae0468 */ 	lw	$t6,0x468($sp)
.NB0f0f17ec:
/*  f0f17ec:	0c006da5 */ 	jal	model0001a524
/*  f0f17f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f17f4:	8faa03dc */ 	lw	$t2,0x3dc($sp)
/*  f0f17f8:	0002c980 */ 	sll	$t9,$v0,0x6
/*  f0f17fc:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f0f1800:	01591821 */ 	addu	$v1,$t2,$t9
/*  f0f1804:	c4660030 */ 	lwc1	$f6,0x30($v1)
/*  f0f1808:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f0f180c:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0f1810:	c46a0034 */ 	lwc1	$f10,0x34($v1)
/*  f0f1814:	e7aa00d8 */ 	swc1	$f10,0xd8($sp)
/*  f0f1818:	c4680038 */ 	lwc1	$f8,0x38($v1)
/*  f0f181c:	0fc2ca99 */ 	jal	func0f0b4d04
/*  f0f1820:	e7a800dc */ 	swc1	$f8,0xdc($sp)
/*  f0f1824:	0c002f77 */ 	jal	viGetWidth
/*  f0f1828:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f182c:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0f1830:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0f1834:	8d8c2320 */ 	lw	$t4,0x2320($t4)
/*  f0f1838:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0f183c:	440d3000 */ 	mfc1	$t5,$f6
/*  f0f1840:	04410003 */ 	bgez	$v0,.NB0f0f1850
/*  f0f1844:	00027043 */ 	sra	$t6,$v0,0x1
/*  f0f1848:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f184c:	00017043 */ 	sra	$t6,$at,0x1
.NB0f0f1850:
/*  f0f1850:	01ae7823 */ 	subu	$t7,$t5,$t6
/*  f0f1854:	01ec001a */ 	div	$zero,$t7,$t4
/*  f0f1858:	15800002 */ 	bnez	$t4,.NB0f0f1864
/*  f0f185c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1860:	0007000d */ 	break	0x7
.NB0f0f1864:
/*  f0f1864:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f1868:	15810004 */ 	bne	$t4,$at,.NB0f0f187c
/*  f0f186c:	3c018000 */ 	lui	$at,0x8000
/*  f0f1870:	15e10002 */ 	bne	$t7,$at,.NB0f0f187c
/*  f0f1874:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1878:	0006000d */ 	break	0x6
.NB0f0f187c:
/*  f0f187c:	3c01800a */ 	lui	$at,0x800a
/*  f0f1880:	0000c012 */ 	mflo	$t8
/*  f0f1884:	ac382688 */ 	sw	$t8,0x2688($at)
/*  f0f1888:	0c002f7b */ 	jal	viGetHeight
/*  f0f188c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1890:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f0f1894:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0f1898:	44194000 */ 	mfc1	$t9,$f8
/*  f0f189c:	04410003 */ 	bgez	$v0,.NB0f0f18ac
/*  f0f18a0:	00025843 */ 	sra	$t3,$v0,0x1
/*  f0f18a4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f18a8:	00015843 */ 	sra	$t3,$at,0x1
.NB0f0f18ac:
/*  f0f18ac:	3c01800a */ 	lui	$at,0x800a
/*  f0f18b0:	032b6823 */ 	subu	$t5,$t9,$t3
/*  f0f18b4:	ac2d268c */ 	sw	$t5,0x268c($at)
.NB0f0f18b8:
/*  f0f18b8:	8fae0468 */ 	lw	$t6,0x468($sp)
.NB0f0f18bc:
/*  f0f18bc:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f0f18c0:	3c188000 */ 	lui	$t8,0x8000
/*  f0f18c4:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0f18c8:	afaf0468 */ 	sw	$t7,0x468($sp)
/*  f0f18cc:	37180040 */ 	ori	$t8,$t8,0x40
/*  f0f18d0:	358c0002 */ 	ori	$t4,$t4,0x2
/*  f0f18d4:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f0f18d8:	add80004 */ 	sw	$t8,0x4($t6)
/*  f0f18dc:	8faa0468 */ 	lw	$t2,0x468($sp)
/*  f0f18e0:	3c0b0386 */ 	lui	$t3,0x386
/*  f0f18e4:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0f18e8:	25590008 */ 	addiu	$t9,$t2,0x8
/*  f0f18ec:	afb90468 */ 	sw	$t9,0x468($sp)
/*  f0f18f0:	25ad3b18 */ 	addiu	$t5,$t5,0x3b18
/*  f0f18f4:	356b0010 */ 	ori	$t3,$t3,0x10
/*  f0f18f8:	ad4b0000 */ 	sw	$t3,0x0($t2)
/*  f0f18fc:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0f1900:	8fae0468 */ 	lw	$t6,0x468($sp)
/*  f0f1904:	3c188007 */ 	lui	$t8,0x8007
/*  f0f1908:	3c0c0388 */ 	lui	$t4,0x388
/*  f0f190c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0f1910:	afaf0468 */ 	sw	$t7,0x468($sp)
/*  f0f1914:	358c0010 */ 	ori	$t4,$t4,0x10
/*  f0f1918:	27183b10 */ 	addiu	$t8,$t8,0x3b10
/*  f0f191c:	add80004 */ 	sw	$t8,0x4($t6)
/*  f0f1920:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f0f1924:	8faa0468 */ 	lw	$t2,0x468($sp)
/*  f0f1928:	3c0b0384 */ 	lui	$t3,0x384
/*  f0f192c:	356b0010 */ 	ori	$t3,$t3,0x10
/*  f0f1930:	25590008 */ 	addiu	$t9,$t2,0x8
/*  f0f1934:	afb90468 */ 	sw	$t9,0x468($sp)
/*  f0f1938:	ad4b0000 */ 	sw	$t3,0x0($t2)
/*  f0f193c:	0fc2cd42 */ 	jal	currentPlayerGetUnk175c
/*  f0f1940:	afaa00bc */ 	sw	$t2,0xbc($sp)
/*  f0f1944:	8fa500bc */ 	lw	$a1,0xbc($sp)
/*  f0f1948:	3c0f0382 */ 	lui	$t7,0x382
/*  f0f194c:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f0f1950:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0f1954:	8fad0468 */ 	lw	$t5,0x468($sp)
/*  f0f1958:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0f195c:	afae0468 */ 	sw	$t6,0x468($sp)
/*  f0f1960:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0f1964:	0fc2cd42 */ 	jal	currentPlayerGetUnk175c
/*  f0f1968:	afad00b8 */ 	sw	$t5,0xb8($sp)
/*  f0f196c:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*  f0f1970:	244c0010 */ 	addiu	$t4,$v0,0x10
/*  f0f1974:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f1978:	accc0004 */ 	sw	$t4,0x4($a2)
/*  f0f197c:	8fab0468 */ 	lw	$t3,0x468($sp)
/*  f0f1980:	240affff */ 	addiu	$t2,$zero,-1
/*  f0f1984:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f1988:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f0f198c:	afb80410 */ 	sw	$t8,0x410($sp)
/*  f0f1990:	afaa0414 */ 	sw	$t2,0x414($sp)
/*  f0f1994:	afb90418 */ 	sw	$t9,0x418($sp)
/*  f0f1998:	afad0468 */ 	sw	$t5,0x468($sp)
/*  f0f199c:	3c0eb700 */ 	lui	$t6,0xb700
/*  f0f19a0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f19a4:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f0f19a8:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f19ac:	8fac0468 */ 	lw	$t4,0x468($sp)
/*  f0f19b0:	afb803e4 */ 	sw	$t8,0x3e4($sp)
/*  f0f19b4:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0f19b8:	27a403e0 */ 	addiu	$a0,$sp,0x3e0
/*  f0f19bc:	0c008be3 */ 	jal	modelRender
/*  f0f19c0:	afac03ec */ 	sw	$t4,0x3ec($sp)
/*  f0f19c4:	8faa03ec */ 	lw	$t2,0x3ec($sp)
/*  f0f19c8:	0c005dbc */ 	jal	mtx00016760
/*  f0f19cc:	afaa0468 */ 	sw	$t2,0x468($sp)
/*  f0f19d0:	8e390054 */ 	lw	$t9,0x54($s1)
/*  f0f19d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f19d8:	872b000e */ 	lh	$t3,0xe($t9)
/*  f0f19dc:	19600013 */ 	blez	$t3,.NB0f0f1a2c
/*  f0f19e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f19e4:	8e2d006c */ 	lw	$t5,0x6c($s1)
.NB0f0f19e8:
/*  f0f19e8:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f0f19ec:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f0f19f0:	0c005b02 */ 	jal	mtx4Copy
/*  f0f19f4:	01a22021 */ 	addu	$a0,$t5,$v0
/*  f0f19f8:	8e2e006c */ 	lw	$t6,0x6c($s1)
/*  f0f19fc:	00107980 */ 	sll	$t7,$s0,0x6
/*  f0f1a00:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0f1a04:	0c005bd1 */ 	jal	mtx00016054
/*  f0f1a08:	01cf2821 */ 	addu	$a1,$t6,$t7
/*  f0f1a0c:	8e2c0054 */ 	lw	$t4,0x54($s1)
/*  f0f1a10:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f0f1a14:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0f1a18:	8598000e */ 	lh	$t8,0xe($t4)
/*  f0f1a1c:	24420040 */ 	addiu	$v0,$v0,0x40
/*  f0f1a20:	0218082a */ 	slt	$at,$s0,$t8
/*  f0f1a24:	5420fff0 */ 	bnezl	$at,.NB0f0f19e8
/*  f0f1a28:	8e2d006c */ 	lw	$t5,0x6c($s1)
.NB0f0f1a2c:
/*  f0f1a2c:	0c005dc5 */ 	jal	mtx00016784
/*  f0f1a30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1a34:	8faa0470 */ 	lw	$t2,0x470($sp)
/*  f0f1a38:	29410003 */ 	slti	$at,$t2,0x3
/*  f0f1a3c:	50200005 */ 	beqzl	$at,.NB0f0f1a54
/*  f0f1a40:	8fb90468 */ 	lw	$t9,0x468($sp)
/*  f0f1a44:	0fc347cf */ 	jal	func0f0d479c
/*  f0f1a48:	8fa40468 */ 	lw	$a0,0x468($sp)
/*  f0f1a4c:	afa20468 */ 	sw	$v0,0x468($sp)
/*  f0f1a50:	8fb90468 */ 	lw	$t9,0x468($sp)
.NB0f0f1a54:
/*  f0f1a54:	3c0de700 */ 	lui	$t5,0xe700
/*  f0f1a58:	3c0cba00 */ 	lui	$t4,0xba00
/*  f0f1a5c:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f0f1a60:	afab0468 */ 	sw	$t3,0x468($sp)
/*  f0f1a64:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0f1a68:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f1a6c:	8fae0468 */ 	lw	$t6,0x468($sp)
/*  f0f1a70:	358c1402 */ 	ori	$t4,$t4,0x1402
/*  f0f1a74:	3c19b900 */ 	lui	$t9,0xb900
/*  f0f1a78:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0f1a7c:	afaf0468 */ 	sw	$t7,0x468($sp)
/*  f0f1a80:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f1a84:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f0f1a88:	8fb80468 */ 	lw	$t8,0x468($sp)
/*  f0f1a8c:	37390002 */ 	ori	$t9,$t9,0x2
/*  f0f1a90:	3c0efc12 */ 	lui	$t6,0xfc12
/*  f0f1a94:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f1a98:	afaa0468 */ 	sw	$t2,0x468($sp)
/*  f0f1a9c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0f1aa0:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0f1aa4:	8fab0468 */ 	lw	$t3,0x468($sp)
/*  f0f1aa8:	35ce7e24 */ 	ori	$t6,$t6,0x7e24
/*  f0f1aac:	240ff9fc */ 	addiu	$t7,$zero,-1540
/*  f0f1ab0:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f0f1ab4:	afad0468 */ 	sw	$t5,0x468($sp)
/*  f0f1ab8:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f0f1abc:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f1ac0:	8fac0468 */ 	lw	$t4,0x468($sp)
/*  f0f1ac4:	24193000 */ 	addiu	$t9,$zero,0x3000
/*  f0f1ac8:	3c0ab600 */ 	lui	$t2,0xb600
/*  f0f1acc:	25980008 */ 	addiu	$t8,$t4,0x8
/*  f0f1ad0:	afb80468 */ 	sw	$t8,0x468($sp)
/*  f0f1ad4:	ad990004 */ 	sw	$t9,0x4($t4)
/*  f0f1ad8:	ad8a0000 */ 	sw	$t2,0x0($t4)
/*  f0f1adc:	8fab0468 */ 	lw	$t3,0x468($sp)
/*  f0f1ae0:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0f1ae4:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f0f1ae8:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f0f1aec:	afad0468 */ 	sw	$t5,0x468($sp)
/*  f0f1af0:	240f2000 */ 	addiu	$t7,$zero,0x2000
/*  f0f1af4:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f0f1af8:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f1afc:	27b00468 */ 	addiu	$s0,$sp,0x468
/*  f0f1b00:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f0f1b04:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f1b08:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f1b0c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f1b10:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f1b14:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f1b18:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f1b1c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f1b20:	0fc2c5c8 */ 	jal	func0f0b39c0
/*  f0f1b24:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f1b28:	8faa0468 */ 	lw	$t2,0x468($sp)
/*  f0f1b2c:	3c0bb900 */ 	lui	$t3,0xb900
/*  f0f1b30:	3c0d0050 */ 	lui	$t5,0x50
/*  f0f1b34:	25590008 */ 	addiu	$t9,$t2,0x8
/*  f0f1b38:	afb90468 */ 	sw	$t9,0x468($sp)
/*  f0f1b3c:	35ad4240 */ 	ori	$t5,$t5,0x4240
/*  f0f1b40:	356b031d */ 	ori	$t3,$t3,0x31d
/*  f0f1b44:	ad4b0000 */ 	sw	$t3,0x0($t2)
/*  f0f1b48:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0f1b4c:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0f1b50:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f1b54:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f1b58:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f1b5c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f1b60:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f1b64:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f1b68:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f1b6c:	0fc2c5c8 */ 	jal	func0f0b39c0
/*  f0f1b70:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f1b74:	8fac0468 */ 	lw	$t4,0x468($sp)
/*  f0f1b78:	3c0a0600 */ 	lui	$t2,0x600
/*  f0f1b7c:	25980008 */ 	addiu	$t8,$t4,0x8
/*  f0f1b80:	afb80468 */ 	sw	$t8,0x468($sp)
/*  f0f1b84:	ad8a0000 */ 	sw	$t2,0x0($t4)
/*  f0f1b88:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f0f1b8c:	ad990004 */ 	sw	$t9,0x4($t4)
.NB0f0f1b90:
/*  f0f1b90:	8fa20468 */ 	lw	$v0,0x468($sp)
.NB0f0f1b94:
/*  f0f1b94:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f1b98:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0f1b9c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0f1ba0:	03e00008 */ 	jr	$ra
/*  f0f1ba4:	27bd0468 */ 	addiu	$sp,$sp,0x468
);
#endif

/**
 * Render the hudpiece as well as any models within dialogs.
 */
// Mismatch: Not functionally identical (hudpiece/chrbios/vehicles do not render).
// Revisit when more is known about the menu840 struct.
//Gfx *menuRenderModels(Gfx *gdl, struct menu840 *thing, s32 arg2)
//{
//	f32 sp430;
//	f32 sp42c;
//	f32 sp428;
//	f32 sp424;
//	s32 bodyfilelen; // 420
//	s32 sp410;
//	s32 bodyfilelen2; // 40c
//	u16 bodyfilenum; // 408
//	s32 bodynum; // 404
//	s32 headnum; // 400
//	struct modelrenderdata renderdata; // 3b8
//	Mtxf *sp3b4;
//	struct coord sp398;
//	f32 sp390[2];
//	Mtxf sp350;
//	Mtxf sp310;
//	f32 sp30c;
//	s32 sp308;
//	struct coord sp2fc;
//	f32 sp2f8;
//	s32 sp2f4;
//	f32 sp2d0;
//	struct coord sp2bc;
//	struct coord sp2ac;
//	f32 sp29c;
//	struct coord sp290;
//	Mtxf sp244;
//	Mtxf sp204;
//	Mtxf sp1c4;
//	Mtxf sp184;
//	f32 aspect; // 17c
//	f32 sp178;
//	s32 sp160;
//	Mtxf sp120;
//	Mtxf spe0;
//	struct coord spd0;
//	f32 spc8[2];
//	Mtxf sp70;
//	s32 headfilenum;
//	s32 i;
//	s32 j;
//	s32 totalfilelen;
//
//	if (g_Vars.stagenum != STAGE_CITRAINING && g_Vars.stagenum != STAGE_CREDITS) {
//		if (g_MenuData.unk5d5_01 && arg2 != 1 && arg2 < 3) {
//			return gdl;
//		}
//
//		if (thing->unk004 == NULL) {
//			if (bgun0f09e004(1)) {
//				thing->unk004 = bgunGetGunMem();
//				thing->unk008 = bgunCalculateGunMemCapacity();
//			} else {
//				return gdl;
//			}
//		}
//	}
//
//	if (thing->unk004 == NULL) {
//		return gdl;
//	}
//
//	if (thing->unk00c != 0) {
//		if (thing->unk010 == thing->unk00c) {
//			thing->unk00c = 0;
//			thing->unk000 = 0;
//		} else {
//			if (thing->unk010 == 0x4fac5ace) {
//				mpClearCurrentChallenge();
//			}
//
//			if (thing->unk000 == 0) {
//				thing->unk000 = 1;
//				return gdl;
//			}
//
//			thing->unk000--;
//
//			if (thing->unk000 == 0) {
//				if ((thing->unk00c & 0xffff) == 0xffff || (thing->unk00c & 0x80000000)) {
//					if (thing->unk00c & 0x80000000) {
//						headnum = thing->unk00c & 0x3ff;
//						bodynum = (thing->unk00c & 0xffc00) >> 10;
//					} else {
//						s32 mpheadnum = (thing->unk00c >> 16) & 0xff;
//						s32 mpbodynum = (thing->unk00c >> 24) & 0xff;
//						bodynum = mpGetBodyId(mpbodynum);
//
//						if (mpheadnum < mpGetNumHeads2()) {
//							headnum = mpGetHeadId(mpheadnum);
//						} else {
//							headnum = mpGetBeauHeadId(func0f14a9f8(mpheadnum - mpGetNumHeads2()));
//							thing->unk5b0 = mpheadnum - mpGetNumHeads2();
//						}
//					}
//
//					bodyfilenum = g_HeadsAndBodies[bodynum].filenum;
//					totalfilelen = ALIGN64(fileGetInflatedLength(g_HeadsAndBodies[bodynum].filenum));
//
//					if (g_HeadsAndBodies[bodynum].unk00_01) {
//						headnum = -1;
//						headfilenum = 0xffff;
//					} else {
//						headfilenum = g_HeadsAndBodies[headnum].filenum;
//						totalfilelen += ALIGN64(fileGetInflatedLength(headfilenum));
//					}
//
//					totalfilelen += 0x4000;
//
//					func0f172e70(&sp410, thing->unk004 + totalfilelen, thing->unk008 - totalfilelen);
//
//					thing->headnum = headnum;
//					thing->bodynum = bodynum;
//					thing->bodymodeldef = func0f1a7794(bodyfilenum, thing->unk004, totalfilelen, &sp410);
//					bodyfilelen2 = ALIGN64(fileGetSize(bodyfilenum));
//					modelCalculateRwDataLen(thing->bodymodeldef);
//
//					if (headnum < 0) {
//						thing->headmodeldef = NULL;
//					} else {
//						thing->headmodeldef = func0f1a7794(headfilenum, thing->unk004 + bodyfilelen2, totalfilelen - bodyfilelen2, &sp410);
//						fileGetSize(headfilenum);
//						bodyCalculateHeadOffset(thing->headmodeldef, headnum, bodynum);
//						modelCalculateRwDataLen(thing->headmodeldef);
//					}
//
//					modelInit(&thing->bodymodel, thing->bodymodeldef, &thing->unk110, true);
//					animInit(&thing->bodyanim);
//
//					thing->bodymodel.unk02 = 256;
//					thing->bodymodel.anim = &thing->bodyanim;
//
//					func0f02ce8c(bodynum, headnum, thing->bodymodeldef, thing->headmodeldef, false, &thing->bodymodel, false, 1);
//				} else {
//					totalfilelen = ALIGN64(fileGetInflatedLength(thing->unk00c)) + 0x4000;
//
//					func0f172e70(&sp410, thing->unk004 + totalfilelen, thing->unk008 - totalfilelen);
//
//					thing->headnum = -1;
//					thing->bodynum = -1;
//					thing->bodymodeldef = func0f1a7794(thing->unk00c, thing->unk004, totalfilelen, &sp410);
//
//					fileGetSize(thing->unk00c);
//					modelCalculateRwDataLen(thing->bodymodeldef);
//					modelInit(&thing->bodymodel, thing->bodymodeldef, &thing->unk110, true);
//					animInit(&thing->bodyanim);
//
//					thing->bodymodel.unk02 = 256;
//					thing->bodymodel.anim = &thing->bodyanim;
//				}
//
//				thing->unk010 = thing->unk00c;
//				thing->unk05e = 0;
//				thing->unk00c = 0;
//			} else {
//				return gdl;
//			}
//		}
//	}
//
//	if (thing->bodymodeldef != NULL) {
//		struct modelrenderdata sp3b8 = {NULL, false, 3};
//
//		if (arg2 < 3 && g_MenuData.unk5d5_03) {
//			gdl = vi0000b280(gdl);
//			gdl = vi0000b1d0(gdl);
//
//			g_MenuData.unk5d5_03 = false;
//
//			if (arg2 != 2) {
//				gdl = menuApplyScissor(gdl);
//			}
//
//			gSPSetGeometryMode(gdl++, G_ZBUFFER);
//		}
//
//		gSPDisplayList(gdl++, var80061380);
//		gSPDisplayList(gdl++, var800613a0);
//
//		sp308 = 0;
//
//		if (thing->unk554 > 0.0f) {
//			sp2f4 = 1;
//
//			if (thing->bodymodeldef->skel == &g_SkelChr) {
//				struct modelnode *node = modelGetPart(thing->bodymodeldef, MODELPART_CHR_0006);
//
//				if (node) {
//					struct modelrodata_position *rodata = &node->rodata->position;
//					f32 temp_f0 = func0f006bd0(thing->unk574 / 480.0f);
//
//					sp2fc.x = 0.0f;
//					sp2fc.y = 0.0f - (rodata->pos.y / 7.6f * (1.0f - temp_f0 * temp_f0));
//					sp2fc.z = 0.0f;
//
//					thing->unk554 = (1.0f - temp_f0) * 270.0f + 100.0f;
//					sp2f4 = 0;
//					sp2f8 = thing->unk554 / (rodata->pos.f[1] * 0.5f);
//					sp308 = 1;
//
//					modelFindBboxRodata(&thing->bodymodel);
//				}
//			}
//
//			if (sp2f4 != 0) {
//				struct modelrodata_bbox *bbox = modelFindBboxRodata(&thing->bodymodel);
//
//				if (bbox) {
//					sp2fc.x = -(bbox->xmax - ((bbox->xmax - bbox->xmin) * 0.5f));
//					sp2fc.y = -(bbox->ymax - ((bbox->ymax - bbox->ymin) * 0.5f));
//					sp2fc.z = -(bbox->zmax - ((bbox->zmax - bbox->zmin) * 0.5f));
//					sp308 = 1;
//					sp2f8 = thing->unk554 / ((bbox->ymax - bbox->ymin) * 0.5f);
//				}
//			}
//		}
//
//		mtx4LoadIdentity(&sp350);
//
//		if (arg2 == 1) {
//			if (IS8MB()) {
//				s32 i;
//				if (thing->unk538 != thing->unk510) {
//					for (i = 0; i < g_Vars.diffframe60; i++) {
//						thing->unk510 = (thing->unk538 * 0.002f) + (0.998f * thing->unk510);
//					}
//				}
//
//				if (thing->unk53c != thing->unk514) {
//					for (i = 0; i < g_Vars.diffframe60; i++) {
//						thing->unk514 = (thing->unk53c * 0.002f) + (0.998f * thing->unk514);
//					}
//				}
//
//				if (thing->unk540 != thing->unk518) {
//					for (i = 0; i < g_Vars.diffframe60; i++) {
//						thing->unk518 = (thing->unk540 * 0.002f) + (0.998f * thing->unk518);
//					}
//				}
//
//				if (thing->unk544 != thing->unk51c) {
//					for (i = 0; i < g_Vars.diffframe60; i++) {
//						thing->unk51c = (thing->unk544 * 0.002f) + (0.998f * thing->unk51c);
//					}
//				}
//
//				sp430 = thing->unk510;
//
//				if (g_ViRes == VIRES_HI) {
//					sp430 += sp430;
//				}
//
//				sp42c = thing->unk514;
//				sp428 = thing->unk518;
//				sp424 = thing->unk51c;
//
//				sp398.x = thing->unk520 = thing->unk548;
//				sp398.y = thing->unk524 = thing->unk54c;
//				sp398.z = thing->unk528 = thing->unk550;
//
//				mtx4LoadRotation(&sp398, &sp350);
//			}
//		} else {
//			if (thing->unk5b1_05) {
//				thing->unk564 += g_Vars.diffframe60f / 40.0f;
//
//				if (thing->unk564 > 1.0f) {
//					thing->unk5b1_05 = false;
//					thing->unk510 = thing->unk538;
//					thing->unk514 = thing->unk53c;
//					thing->unk518 = thing->unk540;
//					thing->unk51c = thing->unk544;
//				} else {
//					f32 sp2d0 = (-cosf(thing->unk564 * M_PI) * 0.5f) + 0.5f;
//					f32 f12 = 1.0f - sp2d0;
//
//					if (thing->unk568 & 2) {
//						sp430 = (thing->unk510 * f12) + (sp2d0 * thing->unk538);
//						sp42c = (thing->unk514 * f12) + (sp2d0 * thing->unk53c);
//						sp428 = (thing->unk518 * f12) + (sp2d0 * thing->unk540);
//					} else {
//						sp430 = thing->unk510 = thing->unk538;
//						sp42c = thing->unk514 = thing->unk53c;
//						sp428 = thing->unk518 = thing->unk540;
//					}
//
//					if (thing->unk568 & 1) {
//						sp424 = (thing->unk51c * f12) + (sp2d0 * thing->unk544);
//					} else {
//						sp424 = thing->unk51c = thing->unk544;
//					}
//
//					if (thing->unk568 & 4) {
//						sp290.x = thing->unk520;
//						sp290.y = thing->unk524;
//						sp290.z = thing->unk528;
//
//						func0f096ca0(&sp290, &sp2bc);
//
//						sp290.x = thing->unk548;
//						sp290.y = thing->unk54c;
//						sp290.z = thing->unk550;
//
//						func0f096ca0(&sp290, &sp2ac);
//						func0f0972b8(&sp2bc, &sp2ac, sp2d0, &sp29c);
//						func0f096ed4(&sp29c, &sp350);
//					} else {
//						sp398.x = thing->unk520 = thing->unk548;
//						sp398.y = thing->unk524 = thing->unk54c;
//						sp398.z = thing->unk528 = thing->unk550;
//
//						mtx4LoadRotation(&sp398, &sp350);
//					}
//				}
//			}
//
//			if (!thing->unk5b1_05) {
//				sp430 = thing->unk510 = thing->unk538;
//				sp42c = thing->unk514 = thing->unk53c;
//				sp428 = thing->unk518 = thing->unk540;
//				sp424 = thing->unk51c = thing->unk544;
//
//				thing->unk520 = thing->unk548;
//				thing->unk524 = thing->unk54c;
//				thing->unk528 = thing->unk550;
//
//				sp398.x = thing->unk548;
//				sp398.y = thing->unk54c;
//				sp398.z = thing->unk550;
//
//				mtx4LoadRotation(&sp398, &sp350);
//			}
//		}
//
//		sp30c = -100.0f + sp428;
//
//		if (arg2 == 1) {
//			if (IS8MB()) {
//				sp390[0] = thing->unk510 * g_ScaleX;
//				sp390[1] = thing->unk514;
//			}
//		} else {
//			sp390[0] = viGetViewLeft() + g_ScaleX * sp430 + 0.5f * viGetViewWidth();
//			sp390[1] = viGetViewTop() + viGetViewHeight() * 0.5f + sp42c;
//		}
//
//		func0f0b4c3c(sp390, &sp398, 1.0f);
//		mtx4LoadIdentity(&sp310);
//
//		if (thing->partvisibility != NULL) {
//			struct modelpartvisibility *ptr = thing->partvisibility;
//
//			while (ptr->part != 255) {
//				struct modelnode *node = modelGetPart(thing->bodymodeldef, ptr->part);
//
//				if (node) {
//					union modelrwdata *rwdata = modelGetNodeRwData(&thing->bodymodel, node);
//
//					if (rwdata) {
//						if (ptr->visible) {
//							rwdata->toggle.visible = true;
//						} else {
//							rwdata->toggle.visible = false;
//						}
//					}
//				}
//
//				ptr++;
//			}
//		}
//
//		if (arg2 == 3) {
//			sp398.x = thing->unk510;
//			sp398.y = thing->unk514;
//			sp398.z = thing->unk518;
//		} else {
//			f32 mult = sp30c / sp398.z;
//			sp398.x *= mult;
//			sp398.y *= mult;
//			sp398.z *= mult;
//		}
//
//#if VERSION < VERSION_NTSC_1_0
//		if (thing->unk010 < 0) {
//			struct coord newpos = {0, 0, 0};
//			struct coord oldpos;
//
//			model0001b3bc(&thing->bodymodel);
//
//			modelGetRootPosition(&thing->bodymodel, &oldpos);
//
//			if (joyGetButtons(0, L_TRIG)) {
//				modelSetRootPosition(&thing->bodymodel, &newpos);
//			}
//		}
//#endif
//
//		mtx4LoadTranslation(&sp398, &sp310);
//
//		if (sp308) {
//			mtx00015f04(sp424 * sp2f8, &sp310);
//		} else {
//			mtx00015f04(sp424, &sp310);
//		}
//
//		if (sp308) {
//			mtx4LoadTranslation(&sp2fc, &sp204);
//		} else {
//			sp398.x = thing->unk52c;
//			sp398.y = thing->unk530;
//			sp398.z = thing->unk534;
//			mtx4LoadTranslation(&sp398, &sp204);
//		}
//
//		mtx4MultMtx4(&sp310, &sp350, &sp244);
//
//		if (arg2 == 3) {
//			func0f13ae04(&sp1c4);
//			mtx4MultMtx4(&sp1c4, &sp244, &sp184);
//			mtx4MultMtx4(&sp184, &sp204, &thing->unk014);
//		} else {
//			mtx4MultMtx4(&sp244, &sp204, &thing->unk014);
//		}
//
//		gdl = func0f0e2348(gdl);
//
//		if (arg2 < 3) {
//			if (arg2 != 0) {
//				gdl = func0f0d49c8(gdl);
//				gSPMatrix(gdl++, osVirtualToPhysical(currentPlayerGetUnk1750()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
//			} else {
//				static u32 znear = 10;
//				static u32 zfar = 300;
//
//				aspect = (f32) (g_MenuScissorX2 - g_MenuScissorX1) / (f32) (g_MenuScissorY2 - g_MenuScissorY1);
//
//				mainOverrideVariable("mzn", &znear);
//				mainOverrideVariable("mzf", &zfar);
//
//				gdl = func0f0d49c8(gdl);
//
//				viSetViewPosition(g_MenuScissorX1 * g_ScaleX, g_MenuScissorY1);
//				viSetFovAspectAndSize(g_Vars.currentplayer->fovy, aspect, (g_MenuScissorX2 - g_MenuScissorX1) * g_ScaleX, g_MenuScissorY2 - g_MenuScissorY1);
//
//				gdl = vi0000af00(gdl, &var800a2048[g_MpPlayerNum]);
//				gdl = vi0000aca4(gdl, znear, zfar);
//			}
//		}
//
//		sp3b4 = gfxAllocate(thing->bodymodeldef->nummatrices * sizeof(Mtxf));
//
//		for (i = 0; i < thing->bodymodeldef->nummatrices; i++) {
//			mtx4LoadIdentity(&sp3b4[i]);
//		}
//
//		thing->bodymodel.matrices = sp3b4;
//
//		if (thing->unk05c && thing->unk05c != thing->unk05e) {
//			if (thing->unk5b1_04) {
//				modelSetAnimation(&thing->bodymodel, thing->unk05c, false, 0, -0.5f, 0.0f);
//				model0001e018(&thing->bodymodel, modelGetNumAnimFrames(&thing->bodymodel));
//			} else {
//				modelSetAnimation(&thing->bodymodel, thing->unk05c, false, 0, 0.5f, 0.0f);
//			}
//
//			thing->unk05e = thing->unk05c;
//		}
//
//		thing->unk05c = 0;
//
//		if (thing->unk05e != 0) {
//			model0001ee18(&thing->bodymodel, g_Vars.diffframe240, true);
//
//			if (thing->unk5b1_04) {
//				sp178 = modelGetNumAnimFrames(&thing->bodymodel) - modelGetCurAnimFrame(&thing->bodymodel);
//			} else {
//				sp178 = modelGetCurAnimFrame(&thing->bodymodel);
//			}
//
//			if (sp178 >= modelGetNumAnimFrames(&thing->bodymodel) - 1) {
//				thing->unk05e = 0;
//			}
//		}
//
//		mtx4Copy(&thing->unk014, sp3b4);
//
//		renderdata.unk00 = &thing->unk014;
//		renderdata.unk10 = thing->bodymodel.matrices;
//
//		model0001cebc(&renderdata, &thing->bodymodel);
//
//		if (thing->bodymodeldef->skel == &g_SkelHudPiece) {
//			struct modelnode *node = modelGetPart(thing->bodymodeldef, MODELPART_HUDPIECE_0000);
//
//			if (node) {
//				struct modelrodata_gundl *rodata = &node->rodata->gundl;
//				s32 i;
//
//				for (i = 0; i < rodata->unk10; i++) {
//					rodata->unk0c[i].unk08 -= g_Vars.diffframe60 * 100;
//
//					if (rodata->unk0c[i].unk08 < -0x6000) {
//						for (j = 0; j < rodata->unk10; j++) {
//							rodata->unk0c[j].unk08 += 0x2000;
//						}
//					}
//				}
//			}
//
//			node = modelGetPart(thing->bodymodeldef, MODELPART_HUDPIECE_0002);
//
//			if (node) {
//				sp160 = model0001a524(node, 0);
//				mtx4LoadIdentity(&sp120);
//				mtx4LoadXRotation(func0f006b54(4), &sp120);
//				mtx4MultMtx4(&sp3b4[sp160], &sp120, &spe0);
//				mtx4Copy(&spe0, &sp3b4[sp160]);
//			}
//
//			node = modelGetPart(thing->bodymodeldef, MODELPART_HUDPIECE_0001);
//
//			if (node) {
//				if (g_MenuData.root == MENUROOT_MAINMENU
//						|| g_MenuData.root == MENUROOT_FILEMGR
//						|| g_MenuData.root == MENUROOT_MPSETUP
//						|| g_MenuData.root == MENUROOT_TRAINING) {
//					Mtxf *mtx = &sp3b4[model0001a524(node, 0)];
//
//					spd0.x = mtx->m[3][0];
//					spd0.y = mtx->m[3][1];
//					spd0.z = mtx->m[3][2];
//
//					func0f0b4d04(&spd0, spc8);
//					var8009de98 = ((s32)spc8[0] - viGetWidth() / 2) / g_ScaleX;
//					var8009de9c = (s32)spc8[1] - viGetHeight() / 2;
//				}
//			}
//		}
//
//		gSPNumLights(gdl++, 1);
//		gSPLight(gdl++, &var80071470, 1);
//		gSPLight(gdl++, &var80071468, 2);
//		gSPLookAtX(gdl++, currentPlayerGetUnk175c()->m[0]);
//		gSPLookAtY(gdl++, currentPlayerGetUnk175c()->m[1]);
//
//		renderdata.unk30 = 1;
//		renderdata.envcolour = 0xffffffff;
//		renderdata.fogcolour = 0xffffffff;
//
//		gSPSetGeometryMode(gdl++, G_ZBUFFER);
//
//		renderdata.zbufferenabled = true;
//
//		renderdata.gdl = gdl;
//		modelRender(&renderdata, &thing->bodymodel);
//		gdl = renderdata.gdl;
//
//		mtx00016760();
//
//		for (i = 0; i < thing->bodymodeldef->nummatrices; i++) {
//			mtx4Copy(&thing->bodymodel.matrices[i], &sp70);
//			mtx00016054(&sp70, &thing->bodymodel.matrices[i]);
//		}
//
//		mtx00016784();
//
//		if (arg2 < 3) {
//			gdl = func0f0d479c(gdl);
//		}
//
//		gDPPipeSync(gdl++);
//		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//		gDPSetAlphaCompare(gdl++, G_AC_NONE);
//		gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
//		gSPClearGeometryMode(gdl++, G_CULL_BOTH);
//		gDPSetTextureFilter(gdl++, G_TF_BILERP);
//
//		func0f0b39c0(&gdl, NULL, 2, 0, 2, 1, NULL);
//
//		gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
//
//		func0f0b39c0(&gdl, NULL, 2, 0, 2, 1, NULL);
//
//		gSPDisplayList(gdl++, var800613a0);
//	}
//
//	return gdl;
//}

void menuGetTeamTitlebarColours(u32 *top, u32 *middle, u32 *bottom)
{
	const u32 colours[][3] = {
		// top, middle, bottom
		{ 0xbf000000, 0x50000000, 0xff000000 },
		{ 0xbfbf0000, 0x50500000, 0xffff0000 },
		{ 0x0000bf00, 0x00005000, 0x0000ff00 },
		{ 0xbf00bf00, 0x50005000, 0xff00ff00 },
		{ 0x00bfbf00, 0x00505000, 0x00ffff00 },
		{ 0xff885500, 0x7f482000, 0xff885500 },
		{ 0xff888800, 0x7f484800, 0xff888800 },
		{ 0x88445500, 0x48242000, 0x88445500 },
	};

	*top = colours[g_PlayerConfigsArray[g_MpPlayerNum].base.team][0] | (*top & 0xff);
	*middle = colours[g_PlayerConfigsArray[g_MpPlayerNum].base.team][1] | (*middle & 0xff);
	*bottom = colours[g_PlayerConfigsArray[g_MpPlayerNum].base.team][2] | (*bottom & 0xff);
}

Gfx *menuApplyScissor(Gfx *gdl)
{
	gDPPipeSync(gdl++);

#if VERSION >= VERSION_NTSC_1_0
	g_ScissorX1 = g_MenuScissorX1 * g_ScaleX;
	g_ScissorX2 = g_MenuScissorX2 * g_ScaleX;
	g_ScissorY1 = g_MenuScissorY1;
	g_ScissorY2 = g_MenuScissorY2;

	if (g_ScissorX1 < 0) {
		g_ScissorX1 = 0;
	}

	if (g_ScissorX2 < 0) {
		g_ScissorX2 = 0;
	}

	if (g_ScissorY1 < 0) {
		g_ScissorY1 = 0;
	}

	if (g_ScissorY2 < 0) {
		g_ScissorY2 = 0;
	}

	if (g_ScissorX1 > viGetBufWidth()) {
		g_ScissorX1 = viGetBufWidth();
	}

	if (g_ScissorX2 > viGetBufWidth()) {
		g_ScissorX2 = viGetBufWidth();
	}

	if (g_ScissorY1 > viGetBufHeight()) {
		g_ScissorY1 = viGetBufHeight();
	}

	if (g_ScissorY2 > viGetBufHeight()) {
		g_ScissorY2 = viGetBufHeight();
	}

	if (g_ScissorX2 < g_ScissorX1) {
		g_ScissorX2 = g_ScissorX1;
	}

	if (g_ScissorY2 < g_ScissorY1) {
		g_ScissorY2 = g_ScissorY1;
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);
#else
	gDPSetScissor(gdl++, G_SC_NON_INTERLACE,
			g_MenuScissorX1 * g_ScaleX, g_MenuScissorY1,
			g_MenuScissorX2 * g_ScaleX, g_MenuScissorY2);
#endif

	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel dialogRender
/*  f0f5360:	27bdfe18 */ 	addiu	$sp,$sp,-488
/*  f0f5364:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f0f5368:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0f536c:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f0f5370:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f0f5374:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f0f5378:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f0f537c:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f0f5380:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f0f5384:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f0f5388:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f0f538c:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0f5390:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f5394:	afa601f0 */ 	sw	$a2,0x1f0($sp)
/*  f0f5398:	afa701f4 */ 	sw	$a3,0x1f4($sp)
/*  f0f539c:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f0f53a0:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f0f53a4:	8fd80298 */ 	lw	$t8,0x298($s8)
/*  f0f53a8:	8cb50014 */ 	lw	$s5,0x14($a1)
/*  f0f53ac:	8cb30018 */ 	lw	$s3,0x18($a1)
/*  f0f53b0:	8cae001c */ 	lw	$t6,0x1c($a1)
/*  f0f53b4:	8caf0020 */ 	lw	$t7,0x20($a1)
/*  f0f53b8:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0f53bc:	02aeb021 */ 	addu	$s6,$s5,$t6
/*  f0f53c0:	07010005 */ 	bgez	$t8,.L0f0f53d8
/*  f0f53c4:	026fa021 */ 	addu	$s4,$s3,$t7
/*  f0f53c8:	8fd9029c */ 	lw	$t9,0x29c($s8)
/*  f0f53cc:	afa501ec */ 	sw	$a1,0x1ec($sp)
/*  f0f53d0:	0722000c */ 	bltzl	$t9,.L0f0f5404
/*  f0f53d4:	8fb001ec */ 	lw	$s0,0x1ec($sp)
.L0f0f53d8:
/*  f0f53d8:	0fc3f303 */ 	jal	menuGetRoot
/*  f0f53dc:	afb001ec */ 	sw	$s0,0x1ec($sp)
/*  f0f53e0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f53e4:	14410006 */ 	bne	$v0,$at,.L0f0f5400
/*  f0f53e8:	3c0b800a */ 	lui	$t3,%hi(var8009dfc0)
/*  f0f53ec:	8d6bdfc0 */ 	lw	$t3,%lo(var8009dfc0)($t3)
/*  f0f53f0:	55600004 */ 	bnezl	$t3,.L0f0f5404
/*  f0f53f4:	8fb001ec */ 	lw	$s0,0x1ec($sp)
/*  f0f53f8:	1000081e */ 	b	.L0f0f7474
/*  f0f53fc:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f5400:
/*  f0f5400:	8fb001ec */ 	lw	$s0,0x1ec($sp)
.L0f0f5404:
/*  f0f5404:	4480a000 */ 	mtc1	$zero,$f20
/*  f0f5408:	3c197f1b */ 	lui	$t9,%hi(g_MenuColourPalettes)
/*  f0f540c:	c6040040 */ 	lwc1	$f4,0x40($s0)
/*  f0f5410:	27391fb0 */ 	addiu	$t9,$t9,%lo(g_MenuColourPalettes)
/*  f0f5414:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0f5418:	00000000 */ 	nop
/*  f0f541c:	4502000c */ 	bc1fl	.L0f0f5450
/*  f0f5420:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f0f5424:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0f5428:	3c0e7f1b */ 	lui	$t6,%hi(g_MenuColourPalettes+0x28)
/*  f0f542c:	afb001ec */ 	sw	$s0,0x1ec($sp)
/*  f0f5430:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0f5434:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f5438:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f543c:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0f5440:	8dce1fd8 */ 	lw	$t6,%lo(g_MenuColourPalettes+0x28)($t6)
/*  f0f5444:	10000011 */ 	b	.L0f0f548c
/*  f0f5448:	afae01bc */ 	sw	$t6,0x1bc($sp)
/*  f0f544c:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f0f5450:
/*  f0f5450:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0f5454:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0f5458:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0f545c:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0f5460:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f5464:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f5468:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f546c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f5470:	03195821 */ 	addu	$t3,$t8,$t9
/*  f0f5474:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f0f5478:	8dc50028 */ 	lw	$a1,0x28($t6)
/*  f0f547c:	8d640028 */ 	lw	$a0,0x28($t3)
/*  f0f5480:	0fc01a40 */ 	jal	colourBlend
/*  f0f5484:	afb001ec */ 	sw	$s0,0x1ec($sp)
/*  f0f5488:	afa201bc */ 	sw	$v0,0x1bc($sp)
.L0f0f548c:
/*  f0f548c:	0fc5580c */ 	jal	func0f156030
/*  f0f5490:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0f5494:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f5498:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f549c:	3c0b800a */ 	lui	$t3,%hi(g_Menus)
/*  f0f54a0:	3c018008 */ 	lui	$at,%hi(var8007fb9c)
/*  f0f54a4:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f54a8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f54ac:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f54b0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f54b4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f54b8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f54bc:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f54c0:	256be000 */ 	addiu	$t3,$t3,%lo(g_Menus)
/*  f0f54c4:	ac20fb9c */ 	sw	$zero,%lo(var8007fb9c)($at)
/*  f0f54c8:	030b1821 */ 	addu	$v1,$t8,$t3
/*  f0f54cc:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f54d0:	8c6c04f8 */ 	lw	$t4,0x4f8($v1)
/*  f0f54d4:	54ec002d */ 	bnel	$a3,$t4,.L0f0f558c
/*  f0f54d8:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f0f54dc:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f0f54e0:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f0f54e4:	8db90010 */ 	lw	$t9,0x10($t5)
/*  f0f54e8:	332e0002 */ 	andi	$t6,$t9,0x2
/*  f0f54ec:	51c00027 */ 	beqzl	$t6,.L0f0f558c
/*  f0f54f0:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f0f54f4:	55e00025 */ 	bnezl	$t7,.L0f0f558c
/*  f0f54f8:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f0f54fc:	8c780df0 */ 	lw	$t8,0xdf0($v1)
/*  f0f5500:	8fad01e8 */ 	lw	$t5,0x1e8($sp)
/*  f0f5504:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f5508:	00185b80 */ 	sll	$t3,$t8,0xe
/*  f0f550c:	000b67c2 */ 	srl	$t4,$t3,0x1f
/*  f0f5510:	1581001d */ 	bne	$t4,$at,.L0f0f5588
/*  f0f5514:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f0f5518:	afb901e8 */ 	sw	$t9,0x1e8($sp)
/*  f0f551c:	3c0eb700 */ 	lui	$t6,0xb700
/*  f0f5520:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f5524:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f0f5528:	adae0000 */ 	sw	$t6,0x0($t5)
/*  f0f552c:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f0f5530:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f0f5534:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f5538:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f553c:	001858c0 */ 	sll	$t3,$t8,0x3
/*  f0f5540:	01785823 */ 	subu	$t3,$t3,$t8
/*  f0f5544:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f5548:	01785821 */ 	addu	$t3,$t3,$t8
/*  f0f554c:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f5550:	01785823 */ 	subu	$t3,$t3,$t8
/*  f0f5554:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f5558:	256c0840 */ 	addiu	$t4,$t3,0x840
/*  f0f555c:	018d2821 */ 	addu	$a1,$t4,$t5
/*  f0f5560:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5564:	0fc3ce2c */ 	jal	menuRenderModels
/*  f0f5568:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f556c:	24590008 */ 	addiu	$t9,$v0,0x8
/*  f0f5570:	afb901e8 */ 	sw	$t9,0x1e8($sp)
/*  f0f5574:	3c0eb600 */ 	lui	$t6,0xb600
/*  f0f5578:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f557c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f5580:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0f5584:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f5588:
/*  f0f5588:	8cf8001c */ 	lw	$t8,0x1c($a3)
.L0f0f558c:
/*  f0f558c:	3c0c8008 */ 	lui	$t4,%hi(g_MpReadyMenuDialog)
/*  f0f5590:	258c57b8 */ 	addiu	$t4,$t4,%lo(g_MpReadyMenuDialog)
/*  f0f5594:	a7b801ca */ 	sh	$t8,0x1ca($sp)
/*  f0f5598:	90eb0060 */ 	lbu	$t3,0x60($a3)
/*  f0f559c:	84f00022 */ 	lh	$s0,0x22($a3)
/*  f0f55a0:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f0f55a4:	55600029 */ 	bnezl	$t3,.L0f0f564c
/*  f0f55a8:	8ced0014 */ 	lw	$t5,0x14($a3)
/*  f0f55ac:	15840003 */ 	bne	$t4,$a0,.L0f0f55bc
/*  f0f55b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f55b4:	100007af */ 	b	.L0f0f7474
/*  f0f55b8:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f55bc:
/*  f0f55bc:	44813000 */ 	mtc1	$at,$f6
/*  f0f55c0:	8fcd0298 */ 	lw	$t5,0x298($s8)
/*  f0f55c4:	3c01800a */ 	lui	$at,%hi(g_MenuData+0x10)
/*  f0f55c8:	c42819d0 */ 	lwc1	$f8,%lo(g_MenuData+0x10)($at)
/*  f0f55cc:	05a10004 */ 	bgez	$t5,.L0f0f55e0
/*  f0f55d0:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f0f55d4:	8fd9029c */ 	lw	$t9,0x29c($s8)
/*  f0f55d8:	0720000b */ 	bltz	$t9,.L0f0f5608
/*  f0f55dc:	00000000 */ 	nop
.L0f0f55e0:
/*  f0f55e0:	0fc3f303 */ 	jal	menuGetRoot
/*  f0f55e4:	e7a00170 */ 	swc1	$f0,0x170($sp)
/*  f0f55e8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f55ec:	14410006 */ 	bne	$v0,$at,.L0f0f5608
/*  f0f55f0:	c7a00170 */ 	lwc1	$f0,0x170($sp)
/*  f0f55f4:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f55f8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f55fc:	44815000 */ 	mtc1	$at,$f10
/*  f0f5600:	c5d00050 */ 	lwc1	$f16,0x50($t6)
/*  f0f5604:	46105001 */ 	sub.s	$f0,$f10,$f16
.L0f0f5608:
/*  f0f5608:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0f560c:	44903000 */ 	mtc1	$s0,$f6
/*  f0f5610:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f5614:	44819000 */ 	mtc1	$at,$f18
/*  f0f5618:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f561c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f5620:	8cec0018 */ 	lw	$t4,0x18($a3)
/*  f0f5624:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f0f5628:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f0f562c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f5630:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f5634:	44108000 */ 	mfc1	$s0,$f16
/*  f0f5638:	00000000 */ 	nop
/*  f0f563c:	0010c400 */ 	sll	$t8,$s0,0x10
/*  f0f5640:	00188403 */ 	sra	$s0,$t8,0x10
/*  f0f5644:	0190a021 */ 	addu	$s4,$t4,$s0
/*  f0f5648:	8ced0014 */ 	lw	$t5,0x14($a3)
.L0f0f564c:
/*  f0f564c:	afad01e0 */ 	sw	$t5,0x1e0($sp)
/*  f0f5650:	8ce20018 */ 	lw	$v0,0x18($a3)
/*  f0f5654:	02021821 */ 	addu	$v1,$s0,$v0
/*  f0f5658:	afa301d4 */ 	sw	$v1,0x1d4($sp)
/*  f0f565c:	afa30084 */ 	sw	$v1,0x84($sp)
/*  f0f5660:	0fc3c560 */ 	jal	menuResolveDialogTitle
/*  f0f5664:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0f5668:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f566c:	0040b825 */ 	or	$s7,$v0,$zero
/*  f0f5670:	c4f20040 */ 	lwc1	$f18,0x40($a3)
/*  f0f5674:	4614903c */ 	c.lt.s	$f18,$f20
/*  f0f5678:	00000000 */ 	nop
/*  f0f567c:	4502000c */ 	bc1fl	.L0f0f56b0
/*  f0f5680:	90eb003d */ 	lbu	$t3,0x3d($a3)
/*  f0f5684:	90f9003c */ 	lbu	$t9,0x3c($a3)
/*  f0f5688:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f568c:	3c097f1b */ 	lui	$t1,%hi(g_MenuColourPalettes)
/*  f0f5690:	03280019 */ 	multu	$t9,$t0
/*  f0f5694:	25291fb0 */ 	addiu	$t1,$t1,%lo(g_MenuColourPalettes)
/*  f0f5698:	00007012 */ 	mflo	$t6
/*  f0f569c:	012e7821 */ 	addu	$t7,$t1,$t6
/*  f0f56a0:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0f56a4:	10000016 */ 	b	.L0f0f5700
/*  f0f56a8:	afb801bc */ 	sw	$t8,0x1bc($sp)
/*  f0f56ac:	90eb003d */ 	lbu	$t3,0x3d($a3)
.L0f0f56b0:
/*  f0f56b0:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f56b4:	3c0d7f1b */ 	lui	$t5,%hi(g_MenuColourPalettes)
/*  f0f56b8:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0f56bc:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f0f56c0:	25ad1fb0 */ 	addiu	$t5,$t5,%lo(g_MenuColourPalettes)
/*  f0f56c4:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f56c8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f56cc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f56d0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f56d4:	018dc821 */ 	addu	$t9,$t4,$t5
/*  f0f56d8:	01edc021 */ 	addu	$t8,$t7,$t5
/*  f0f56dc:	8f050000 */ 	lw	$a1,0x0($t8)
/*  f0f56e0:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0f56e4:	0fc01a40 */ 	jal	colourBlend
/*  f0f56e8:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f56ec:	3c097f1b */ 	lui	$t1,%hi(g_MenuColourPalettes)
/*  f0f56f0:	25291fb0 */ 	addiu	$t1,$t1,%lo(g_MenuColourPalettes)
/*  f0f56f4:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f56f8:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f56fc:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f5700:
/*  f0f5700:	c4e40040 */ 	lwc1	$f4,0x40($a3)
/*  f0f5704:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0f5708:	00000000 */ 	nop
/*  f0f570c:	45020009 */ 	bc1fl	.L0f0f5734
/*  f0f5710:	90ef003d */ 	lbu	$t7,0x3d($a3)
/*  f0f5714:	90eb003c */ 	lbu	$t3,0x3c($a3)
/*  f0f5718:	01680019 */ 	multu	$t3,$t0
/*  f0f571c:	00006012 */ 	mflo	$t4
/*  f0f5720:	012cc821 */ 	addu	$t9,$t1,$t4
/*  f0f5724:	8f2e0004 */ 	lw	$t6,0x4($t9)
/*  f0f5728:	10000012 */ 	b	.L0f0f5774
/*  f0f572c:	afae01b8 */ 	sw	$t6,0x1b8($sp)
/*  f0f5730:	90ef003d */ 	lbu	$t7,0x3d($a3)
.L0f0f5734:
/*  f0f5734:	90eb003c */ 	lbu	$t3,0x3c($a3)
/*  f0f5738:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f573c:	01e80019 */ 	multu	$t7,$t0
/*  f0f5740:	00006812 */ 	mflo	$t5
/*  f0f5744:	012dc021 */ 	addu	$t8,$t1,$t5
/*  f0f5748:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f0f574c:	01680019 */ 	multu	$t3,$t0
/*  f0f5750:	00006012 */ 	mflo	$t4
/*  f0f5754:	012cc821 */ 	addu	$t9,$t1,$t4
/*  f0f5758:	0fc01a40 */ 	jal	colourBlend
/*  f0f575c:	8f250004 */ 	lw	$a1,0x4($t9)
/*  f0f5760:	3c097f1b */ 	lui	$t1,%hi(g_MenuColourPalettes)
/*  f0f5764:	25291fb0 */ 	addiu	$t1,$t1,%lo(g_MenuColourPalettes)
/*  f0f5768:	afa201b8 */ 	sw	$v0,0x1b8($sp)
/*  f0f576c:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f5770:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f5774:
/*  f0f5774:	c4e60040 */ 	lwc1	$f6,0x40($a3)
/*  f0f5778:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0f577c:	00000000 */ 	nop
/*  f0f5780:	45020009 */ 	bc1fl	.L0f0f57a8
/*  f0f5784:	90eb003d */ 	lbu	$t3,0x3d($a3)
/*  f0f5788:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f578c:	01c80019 */ 	multu	$t6,$t0
/*  f0f5790:	00007812 */ 	mflo	$t7
/*  f0f5794:	012f6821 */ 	addu	$t5,$t1,$t7
/*  f0f5798:	8db80008 */ 	lw	$t8,0x8($t5)
/*  f0f579c:	1000000f */ 	b	.L0f0f57dc
/*  f0f57a0:	afb801b4 */ 	sw	$t8,0x1b4($sp)
/*  f0f57a4:	90eb003d */ 	lbu	$t3,0x3d($a3)
.L0f0f57a8:
/*  f0f57a8:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f57ac:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f57b0:	01680019 */ 	multu	$t3,$t0
/*  f0f57b4:	00006012 */ 	mflo	$t4
/*  f0f57b8:	012cc821 */ 	addu	$t9,$t1,$t4
/*  f0f57bc:	8f240008 */ 	lw	$a0,0x8($t9)
/*  f0f57c0:	01c80019 */ 	multu	$t6,$t0
/*  f0f57c4:	00007812 */ 	mflo	$t7
/*  f0f57c8:	012f6821 */ 	addu	$t5,$t1,$t7
/*  f0f57cc:	0fc01a40 */ 	jal	colourBlend
/*  f0f57d0:	8da50008 */ 	lw	$a1,0x8($t5)
/*  f0f57d4:	afa201b4 */ 	sw	$v0,0x1b4($sp)
/*  f0f57d8:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f57dc:
/*  f0f57dc:	8fb801e8 */ 	lw	$t8,0x1e8($sp)
/*  f0f57e0:	3c0cb600 */ 	lui	$t4,0xb600
/*  f0f57e4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f57e8:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f0f57ec:	afab01e8 */ 	sw	$t3,0x1e8($sp)
/*  f0f57f0:	af190004 */ 	sw	$t9,0x4($t8)
/*  f0f57f4:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f0f57f8:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f0f57fc:	8fb201b4 */ 	lw	$s2,0x1b4($sp)
/*  f0f5800:	8fb801b4 */ 	lw	$t8,0x1b4($sp)
/*  f0f5804:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0f5808:	2de10040 */ 	sltiu	$at,$t7,0x40
/*  f0f580c:	14200005 */ 	bnez	$at,.L0f0f5824
/*  f0f5810:	01c08825 */ 	or	$s1,$t6,$zero
/*  f0f5814:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f5818:	01c18824 */ 	and	$s1,$t6,$at
/*  f0f581c:	362d003f */ 	ori	$t5,$s1,0x3f
/*  f0f5820:	01a08825 */ 	or	$s1,$t5,$zero
.L0f0f5824:
/*  f0f5824:	330b00ff */ 	andi	$t3,$t8,0xff
/*  f0f5828:	2d610040 */ 	sltiu	$at,$t3,0x40
/*  f0f582c:	14200005 */ 	bnez	$at,.L0f0f5844
/*  f0f5830:	2419fc18 */ 	addiu	$t9,$zero,-1000
/*  f0f5834:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f5838:	03019024 */ 	and	$s2,$t8,$at
/*  f0f583c:	364c003f */ 	ori	$t4,$s2,0x3f
/*  f0f5840:	01809025 */ 	or	$s2,$t4,$zero
.L0f0f5844:
/*  f0f5844:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0f5848:	ac39de90 */ 	sw	$t9,%lo(var8009de90)($at)
/*  f0f584c:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0f5850:	240f03e8 */ 	addiu	$t7,$zero,0x3e8
/*  f0f5854:	ac2fde94 */ 	sw	$t7,%lo(var8009de94)($at)
/*  f0f5858:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0f585c:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x4)
/*  f0f5860:	8dc40010 */ 	lw	$a0,0x10($t6)
/*  f0f5864:	308d0100 */ 	andi	$t5,$a0,0x100
/*  f0f5868:	11a00002 */ 	beqz	$t5,.L0f0f5874
/*  f0f586c:	01a02025 */ 	or	$a0,$t5,$zero
/*  f0f5870:	2673000b */ 	addiu	$s3,$s3,0xb
.L0f0f5874:
/*  f0f5874:	8c6319c4 */ 	lw	$v1,%lo(g_MenuData+0x4)($v1)
/*  f0f5878:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f587c:	10610060 */ 	beq	$v1,$at,.L0f0f5a00
/*  f0f5880:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f5884:	14610004 */ 	bne	$v1,$at,.L0f0f5898
/*  f0f5888:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f588c:	8fcb0318 */ 	lw	$t3,0x318($s8)
/*  f0f5890:	1160005b */ 	beqz	$t3,.L0f0f5a00
/*  f0f5894:	00000000 */ 	nop
.L0f0f5898:
/*  f0f5898:	3c10800a */ 	lui	$s0,%hi(var800a4634)
/*  f0f589c:	26104634 */ 	addiu	$s0,$s0,%lo(var800a4634)
/*  f0f58a0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f0f58a4:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f58a8:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f58ac:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f58b0:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f58b4:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f58b8:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f58bc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f58c0:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f58c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f58c8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f58cc:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f58d0:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f58d4:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f58d8:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f58dc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f58e0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f58e4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f58e8:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f58ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f58f0:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f58f4:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f58f8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f58fc:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f5900:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f5904:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f5908:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f590c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f5910:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f5914:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5918:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f591c:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f5920:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f5924:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f5928:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f592c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f5930:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f5934:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f5938:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f593c:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f5940:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0f5944:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5948:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f594c:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f5950:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f5954:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f5958:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f595c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f5960:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f5964:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f5968:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f596c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f5970:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5974:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f5978:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f597c:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f5980:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f5984:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f5988:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f598c:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f5990:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f5994:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f5998:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f599c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f59a0:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f59a4:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f59a8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f59ac:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f59b0:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f59b4:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f59b8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f59bc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f59c0:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f59c4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f59c8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f59cc:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f59d0:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f59d4:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f59d8:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f59dc:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f59e0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f59e4:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f59e8:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f59ec:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f59f0:	8dcd0000 */ 	lw	$t5,0x0($t6)
/*  f0f59f4:	8da40010 */ 	lw	$a0,0x10($t5)
/*  f0f59f8:	308b0100 */ 	andi	$t3,$a0,0x100
/*  f0f59fc:	01602025 */ 	or	$a0,$t3,$zero
.L0f0f5a00:
/*  f0f5a00:	148000e3 */ 	bnez	$a0,.L0f0f5d90
/*  f0f5a04:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x4)
/*  f0f5a08:	8c6319c4 */ 	lw	$v1,%lo(g_MenuData+0x4)($v1)
/*  f0f5a0c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f5a10:	10610002 */ 	beq	$v1,$at,.L0f0f5a1c
/*  f0f5a14:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f5a18:	1461000c */ 	bne	$v1,$at,.L0f0f5a4c
.L0f0f5a1c:
/*  f0f5a1c:	3c18800b */ 	lui	$t8,%hi(g_MpSetup+0xc)
/*  f0f5a20:	8f18cb94 */ 	lw	$t8,%lo(g_MpSetup+0xc)($t8)
/*  f0f5a24:	330c0002 */ 	andi	$t4,$t8,0x2
/*  f0f5a28:	51800009 */ 	beqzl	$t4,.L0f0f5a50
/*  f0f5a2c:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f5a30:	8fd90490 */ 	lw	$t9,0x490($s8)
/*  f0f5a34:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f5a38:	27a401bc */ 	addiu	$a0,$sp,0x1bc
/*  f0f5a3c:	13210003 */ 	beq	$t9,$at,.L0f0f5a4c
/*  f0f5a40:	27a501b8 */ 	addiu	$a1,$sp,0x1b8
/*  f0f5a44:	0fc3d401 */ 	jal	menuGetTeamTitlebarColours
/*  f0f5a48:	27a601b4 */ 	addiu	$a2,$sp,0x1b4
.L0f0f5a4c:
/*  f0f5a4c:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
.L0f0f5a50:
/*  f0f5a50:	87af01ca */ 	lh	$t7,0x1ca($sp)
/*  f0f5a54:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f5a58:	8fad01bc */ 	lw	$t5,0x1bc($sp)
/*  f0f5a5c:	8fab01b8 */ 	lw	$t3,0x1b8($sp)
/*  f0f5a60:	8fae01b4 */ 	lw	$t6,0x1b4($sp)
/*  f0f5a64:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f0f5a68:	24510002 */ 	addiu	$s1,$v0,0x2
/*  f0f5a6c:	2470fffe */ 	addiu	$s0,$v1,-2
/*  f0f5a70:	24d5000b */ 	addiu	$s5,$a2,0xb
/*  f0f5a74:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f0f5a78:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5a7c:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5a80:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0f5a84:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5a88:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0f5a8c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f5a90:	0fc3873a */ 	jal	menugfxRenderGradient
/*  f0f5a94:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0f5a98:	8fac01bc */ 	lw	$t4,0x1bc($sp)
/*  f0f5a9c:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f5aa0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0f5aa4:	319900ff */ 	andi	$t9,$t4,0xff
/*  f0f5aa8:	00197842 */ 	srl	$t7,$t9,0x1
/*  f0f5aac:	240b0028 */ 	addiu	$t3,$zero,0x28
/*  f0f5ab0:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0f5ab4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f5ab8:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0f5abc:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f5ac0:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f5ac4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5ac8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5acc:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5ad0:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0f5ad4:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0f5ad8:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f0f5adc:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f5ae0:	24190028 */ 	addiu	$t9,$zero,0x28
/*  f0f5ae4:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f0f5ae8:	00186042 */ 	srl	$t4,$t8,0x1
/*  f0f5aec:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f5af0:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0f5af4:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f5af8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f5afc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5b00:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5b04:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5b08:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f0f5b0c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f5b10:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0f5b14:	24c6000a */ 	addiu	$a2,$a2,0xa
/*  f0f5b18:	8fb201e0 */ 	lw	$s2,0x1e0($sp)
/*  f0f5b1c:	8fb001dc */ 	lw	$s0,0x1dc($sp)
/*  f0f5b20:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5b24:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f0f5b28:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0f5b2c:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f5b30:	0fc54d8a */ 	jal	func0f153628
/*  f0f5b34:	afb201d0 */ 	sw	$s2,0x1d0($sp)
/*  f0f5b38:	8fad01f4 */ 	lw	$t5,0x1f4($sp)
/*  f0f5b3c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f5b40:	afa001b0 */ 	sw	$zero,0x1b0($sp)
/*  f0f5b44:	11a00003 */ 	beqz	$t5,.L0f0f5b54
/*  f0f5b48:	3c0e8007 */ 	lui	$t6,%hi(var800714c8)
/*  f0f5b4c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f5b50:	afab01b0 */ 	sw	$t3,0x1b0($sp)
.L0f0f5b54:
/*  f0f5b54:	25ce14c8 */ 	addiu	$t6,$t6,%lo(var800714c8)
/*  f0f5b58:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0f5b5c:	8fa301ec */ 	lw	$v1,0x1ec($sp)
/*  f0f5b60:	27b40154 */ 	addiu	$s4,$sp,0x154
/*  f0f5b64:	ae810000 */ 	sw	$at,0x0($s4)
/*  f0f5b68:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0f5b6c:	ae990004 */ 	sw	$t9,0x4($s4)
/*  f0f5b70:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0f5b74:	ae810008 */ 	sw	$at,0x8($s4)
/*  f0f5b78:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f0f5b7c:	3c0e7f1b */ 	lui	$t6,%hi(g_MenuColourPalettes)
/*  f0f5b80:	25ce1fb0 */ 	addiu	$t6,$t6,%lo(g_MenuColourPalettes)
/*  f0f5b84:	ae99000c */ 	sw	$t9,0xc($s4)
/*  f0f5b88:	c4680040 */ 	lwc1	$f8,0x40($v1)
/*  f0f5b8c:	4614403c */ 	c.lt.s	$f8,$f20
/*  f0f5b90:	00000000 */ 	nop
/*  f0f5b94:	4502000b */ 	bc1fl	.L0f0f5bc4
/*  f0f5b98:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0f5b9c:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0f5ba0:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes+0xc)
/*  f0f5ba4:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f5ba8:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f5bac:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f5bb0:	016d5821 */ 	addu	$t3,$t3,$t5
/*  f0f5bb4:	8d6b1fbc */ 	lw	$t3,%lo(g_MenuColourPalettes+0xc)($t3)
/*  f0f5bb8:	10000011 */ 	b	.L0f0f5c00
/*  f0f5bbc:	afab01bc */ 	sw	$t3,0x1bc($sp)
/*  f0f5bc0:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0f5bc4:
/*  f0f5bc4:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0f5bc8:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0f5bcc:	000cc100 */ 	sll	$t8,$t4,0x4
/*  f0f5bd0:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f5bd4:	030cc023 */ 	subu	$t8,$t8,$t4
/*  f0f5bd8:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f5bdc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f5be0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f5be4:	030ec821 */ 	addu	$t9,$t8,$t6
/*  f0f5be8:	01ae5821 */ 	addu	$t3,$t5,$t6
/*  f0f5bec:	8d65000c */ 	lw	$a1,0xc($t3)
/*  f0f5bf0:	0fc01a40 */ 	jal	colourBlend
/*  f0f5bf4:	8f24000c */ 	lw	$a0,0xc($t9)
/*  f0f5bf8:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f5bfc:	8fa301ec */ 	lw	$v1,0x1ec($sp)
.L0f0f5c00:
/*  f0f5c00:	9062003c */ 	lbu	$v0,0x3c($v1)
/*  f0f5c04:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0xc)
/*  f0f5c08:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0xc)
/*  f0f5c0c:	00026100 */ 	sll	$t4,$v0,0x4
/*  f0f5c10:	01826023 */ 	subu	$t4,$t4,$v0
/*  f0f5c14:	000c1080 */ 	sll	$v0,$t4,0x2
/*  f0f5c18:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0f5c1c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0f5c20:	8ca52124 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0xc)($a1)
/*  f0f5c24:	0fc54f8e */ 	jal	func0f153e38
/*  f0f5c28:	8c84228c */ 	lw	$a0,%lo(g_MenuColourPalettes3+0xc)($a0)
/*  f0f5c2c:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f5c30:	8fa501dc */ 	lw	$a1,0x1dc($sp)
/*  f0f5c34:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0f5c38:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0f5c3c:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f5c40:	0c002f06 */ 	jal	viGetHeight
/*  f0f5c44:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f5c48:	8faf01bc */ 	lw	$t7,0x1bc($sp)
/*  f0f5c4c:	3c118008 */ 	lui	$s1,%hi(g_CharsHandelGothicSm)
/*  f0f5c50:	3c138008 */ 	lui	$s3,%hi(g_FontHandelGothicSm)
/*  f0f5c54:	2673fb0c */ 	addiu	$s3,$s3,%lo(g_FontHandelGothicSm)
/*  f0f5c58:	2631fb10 */ 	addiu	$s1,$s1,%lo(g_CharsHandelGothicSm)
/*  f0f5c5c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0f5c60:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0f5c64:	87ae01ca */ 	lh	$t6,0x1ca($sp)
/*  f0f5c68:	31ed00ff */ 	andi	$t5,$t7,0xff
/*  f0f5c6c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f5c70:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5c74:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f5c78:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f5c7c:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0f5c80:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f5c84:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f5c88:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f5c8c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f5c90:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f5c94:	0fc5580f */ 	jal	textRenderProjected
/*  f0f5c98:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0f5c9c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f5ca0:	afb201d0 */ 	sw	$s2,0x1d0($sp)
/*  f0f5ca4:	0c002f06 */ 	jal	viGetHeight
/*  f0f5ca8:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f5cac:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0f5cb0:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f0f5cb4:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*  f0f5cb8:	87b901ca */ 	lh	$t9,0x1ca($sp)
/*  f0f5cbc:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5cc0:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f5cc4:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f5cc8:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0f5ccc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f5cd0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f5cd4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f5cd8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f5cdc:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f5ce0:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f5ce4:	0fc5580f */ 	jal	textRenderProjected
/*  f0f5ce8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f5cec:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x4)
/*  f0f5cf0:	8c6319c4 */ 	lw	$v1,%lo(g_MenuData+0x4)($v1)
/*  f0f5cf4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f5cf8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f5cfc:	10610007 */ 	beq	$v1,$at,.L0f0f5d1c
/*  f0f5d00:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f5d04:	10610005 */ 	beq	$v1,$at,.L0f0f5d1c
/*  f0f5d08:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f5d0c:	10610003 */ 	beq	$v1,$at,.L0f0f5d1c
/*  f0f5d10:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f5d14:	1461001b */ 	bne	$v1,$at,.L0f0f5d84
/*  f0f5d18:	00000000 */ 	nop
.L0f0f5d1c:
/*  f0f5d1c:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f0f5d20:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f5d24:	2463fff7 */ 	addiu	$v1,$v1,-9
/*  f0f5d28:	0c002f06 */ 	jal	viGetHeight
/*  f0f5d2c:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f5d30:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f5d34:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f5d38:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0f5d3c:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f0f5d40:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f0f5d44:	028d7021 */ 	addu	$t6,$s4,$t5
/*  f0f5d48:	8dc70000 */ 	lw	$a3,0x0($t6)
/*  f0f5d4c:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*  f0f5d50:	87b901ca */ 	lh	$t9,0x1ca($sp)
/*  f0f5d54:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f5d58:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f5d5c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f5d60:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5d64:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f5d68:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f5d6c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f5d70:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f5d74:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f5d78:	0fc5580f */ 	jal	textRenderProjected
/*  f0f5d7c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f5d80:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f5d84:
/*  f0f5d84:	0fc54de0 */ 	jal	func0f153780
/*  f0f5d88:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5d8c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f5d90:
/*  f0f5d90:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f5d94:	8fb501dc */ 	lw	$s5,0x1dc($sp)
/*  f0f5d98:	3c0f800a */ 	lui	$t7,%hi(g_MenuData+0x4)
/*  f0f5d9c:	c4400048 */ 	lwc1	$f0,0x48($v0)
/*  f0f5da0:	26b5000b */ 	addiu	$s5,$s5,0xb
/*  f0f5da4:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f5da8:	00000000 */ 	nop
/*  f0f5dac:	4503001b */ 	bc1tl	.L0f0f5e1c
/*  f0f5db0:	904b0060 */ 	lbu	$t3,0x60($v0)
/*  f0f5db4:	8def19c4 */ 	lw	$t7,%lo(g_MenuData+0x4)($t7)
/*  f0f5db8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f5dbc:	51e1001e */ 	beql	$t7,$at,.L0f0f5e38
/*  f0f5dc0:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f0f5dc4:	904d0060 */ 	lbu	$t5,0x60($v0)
/*  f0f5dc8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f5dcc:	29a10003 */ 	slti	$at,$t5,0x3
/*  f0f5dd0:	54200009 */ 	bnezl	$at,.L0f0f5df8
/*  f0f5dd4:	44060000 */ 	mfc1	$a2,$f0
/*  f0f5dd8:	44060000 */ 	mfc1	$a2,$f0
/*  f0f5ddc:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f0f5de0:	8c450018 */ 	lw	$a1,0x18($v0)
/*  f0f5de4:	0fc54f08 */ 	jal	func0f153c20
/*  f0f5de8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f5dec:	10000006 */ 	b	.L0f0f5e08
/*  f0f5df0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f5df4:	44060000 */ 	mfc1	$a2,$f0
.L0f0f5df8:
/*  f0f5df8:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f0f5dfc:	0fc54f08 */ 	jal	func0f153c20
/*  f0f5e00:	8c450018 */ 	lw	$a1,0x18($v0)
/*  f0f5e04:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f0f5e08:
/*  f0f5e08:	3c018008 */ 	lui	$at,%hi(var8007fb9c)
/*  f0f5e0c:	ac2efb9c */ 	sw	$t6,%lo(var8007fb9c)($at)
/*  f0f5e10:	10000008 */ 	b	.L0f0f5e34
/*  f0f5e14:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f5e18:	904b0060 */ 	lbu	$t3,0x60($v0)
.L0f0f5e1c:
/*  f0f5e1c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f5e20:	55610005 */ 	bnel	$t3,$at,.L0f0f5e38
/*  f0f5e24:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f0f5e28:	0fc54f62 */ 	jal	func0f153d88
/*  f0f5e2c:	c44c0050 */ 	lwc1	$f12,0x50($v0)
/*  f0f5e30:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.L0f0f5e34:
/*  f0f5e34:	8fac0084 */ 	lw	$t4,0x84($sp)
.L0f0f5e38:
/*  f0f5e38:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes)
/*  f0f5e3c:	256b1fb0 */ 	addiu	$t3,$t3,%lo(g_MenuColourPalettes)
/*  f0f5e40:	0195082a */ 	slt	$at,$t4,$s5
/*  f0f5e44:	50200003 */ 	beqzl	$at,.L0f0f5e54
/*  f0f5e48:	c44a0040 */ 	lwc1	$f10,0x40($v0)
/*  f0f5e4c:	afb501d4 */ 	sw	$s5,0x1d4($sp)
/*  f0f5e50:	c44a0040 */ 	lwc1	$f10,0x40($v0)
.L0f0f5e54:
/*  f0f5e54:	4614503c */ 	c.lt.s	$f10,$f20
/*  f0f5e58:	00000000 */ 	nop
/*  f0f5e5c:	4502000b */ 	bc1fl	.L0f0f5e8c
/*  f0f5e60:	904d003d */ 	lbu	$t5,0x3d($v0)
/*  f0f5e64:	9058003c */ 	lbu	$t8,0x3c($v0)
/*  f0f5e68:	3c0f7f1b */ 	lui	$t7,%hi(g_MenuColourPalettes+0x10)
/*  f0f5e6c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f5e70:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f5e74:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f5e78:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f0f5e7c:	8def1fc0 */ 	lw	$t7,%lo(g_MenuColourPalettes+0x10)($t7)
/*  f0f5e80:	10000011 */ 	b	.L0f0f5ec8
/*  f0f5e84:	afaf01bc */ 	sw	$t7,0x1bc($sp)
/*  f0f5e88:	904d003d */ 	lbu	$t5,0x3d($v0)
.L0f0f5e8c:
/*  f0f5e8c:	9058003c */ 	lbu	$t8,0x3c($v0)
/*  f0f5e90:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f5e94:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0f5e98:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f5e9c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f5ea0:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f5ea4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f5ea8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f5eac:	01cb6021 */ 	addu	$t4,$t6,$t3
/*  f0f5eb0:	032b7821 */ 	addu	$t7,$t9,$t3
/*  f0f5eb4:	8de50010 */ 	lw	$a1,0x10($t7)
/*  f0f5eb8:	0fc01a40 */ 	jal	colourBlend
/*  f0f5ebc:	8d840010 */ 	lw	$a0,0x10($t4)
/*  f0f5ec0:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f5ec4:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.L0f0f5ec8:
/*  f0f5ec8:	8c4d000c */ 	lw	$t5,0xc($v0)
/*  f0f5ecc:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0f5ed0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f5ed4:	51a0000b */ 	beqzl	$t5,.L0f0f5f04
/*  f0f5ed8:	c4500040 */ 	lwc1	$f16,0x40($v0)
/*  f0f5edc:	0fc01a40 */ 	jal	colourBlend
/*  f0f5ee0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0f5ee4:	8fac01bc */ 	lw	$t4,0x1bc($sp)
/*  f0f5ee8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f5eec:	00417024 */ 	and	$t6,$v0,$at
/*  f0f5ef0:	319800ff */ 	andi	$t8,$t4,0xff
/*  f0f5ef4:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0f5ef8:	afb901bc */ 	sw	$t9,0x1bc($sp)
/*  f0f5efc:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f5f00:	c4500040 */ 	lwc1	$f16,0x40($v0)
.L0f0f5f04:
/*  f0f5f04:	3c187f1b */ 	lui	$t8,%hi(g_MenuColourPalettes)
/*  f0f5f08:	27181fb0 */ 	addiu	$t8,$t8,%lo(g_MenuColourPalettes)
/*  f0f5f0c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0f5f10:	00000000 */ 	nop
/*  f0f5f14:	4502000b */ 	bc1fl	.L0f0f5f44
/*  f0f5f18:	904c003d */ 	lbu	$t4,0x3d($v0)
/*  f0f5f1c:	904b003c */ 	lbu	$t3,0x3c($v0)
/*  f0f5f20:	3c0d7f1b */ 	lui	$t5,%hi(g_MenuColourPalettes+0x14)
/*  f0f5f24:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0f5f28:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0f5f2c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f5f30:	01af6821 */ 	addu	$t5,$t5,$t7
/*  f0f5f34:	8dad1fc4 */ 	lw	$t5,%lo(g_MenuColourPalettes+0x14)($t5)
/*  f0f5f38:	10000011 */ 	b	.L0f0f5f80
/*  f0f5f3c:	afad01b8 */ 	sw	$t5,0x1b8($sp)
/*  f0f5f40:	904c003d */ 	lbu	$t4,0x3d($v0)
.L0f0f5f44:
/*  f0f5f44:	904b003c */ 	lbu	$t3,0x3c($v0)
/*  f0f5f48:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f5f4c:	000c7100 */ 	sll	$t6,$t4,0x4
/*  f0f5f50:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0f5f54:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f0f5f58:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0f5f5c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f5f60:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f5f64:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f0f5f68:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f0f5f6c:	8da50014 */ 	lw	$a1,0x14($t5)
/*  f0f5f70:	0fc01a40 */ 	jal	colourBlend
/*  f0f5f74:	8f240014 */ 	lw	$a0,0x14($t9)
/*  f0f5f78:	afa201b8 */ 	sw	$v0,0x1b8($sp)
/*  f0f5f7c:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.L0f0f5f80:
/*  f0f5f80:	8fac01f4 */ 	lw	$t4,0x1f4($sp)
/*  f0f5f84:	8fa901e0 */ 	lw	$t1,0x1e0($sp)
/*  f0f5f88:	5580008a */ 	bnezl	$t4,.L0f0f61b4
/*  f0f5f8c:	904d0060 */ 	lbu	$t5,0x60($v0)
/*  f0f5f90:	90430060 */ 	lbu	$v1,0x60($v0)
/*  f0f5f94:	87ae01ca */ 	lh	$t6,0x1ca($sp)
/*  f0f5f98:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f5f9c:	14610014 */ 	bne	$v1,$at,.L0f0f5ff0
/*  f0f5fa0:	01c94021 */ 	addu	$t0,$t6,$t1
/*  f0f5fa4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f5fa8:	44819000 */ 	mtc1	$at,$f18
/*  f0f5fac:	8fb901d4 */ 	lw	$t9,0x1d4($sp)
/*  f0f5fb0:	8fab01bc */ 	lw	$t3,0x1bc($sp)
/*  f0f5fb4:	8faf01b8 */ 	lw	$t7,0x1b8($sp)
/*  f0f5fb8:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f5fbc:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f5fc0:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5fc4:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5fc8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5fcc:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f5fd0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f5fd4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f5fd8:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f0f5fdc:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f5fe0:	0fc3836b */ 	jal	menugfxRenderDialogBackground
/*  f0f5fe4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f5fe8:	10000027 */ 	b	.L0f0f6088
/*  f0f5fec:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f5ff0:
/*  f0f5ff0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f5ff4:	14610013 */ 	bne	$v1,$at,.L0f0f6044
/*  f0f5ff8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5ffc:	8fb801d4 */ 	lw	$t8,0x1d4($sp)
/*  f0f6000:	8fad01bc */ 	lw	$t5,0x1bc($sp)
/*  f0f6004:	8fac01b8 */ 	lw	$t4,0x1b8($sp)
/*  f0f6008:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f600c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f6010:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f6014:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f6018:	c4440050 */ 	lwc1	$f4,0x50($v0)
/*  f0f601c:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f6020:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f6024:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6028:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f602c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6030:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6034:	0fc3836b */ 	jal	menugfxRenderDialogBackground
/*  f0f6038:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0f603c:	10000012 */ 	b	.L0f0f6088
/*  f0f6040:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6044:
/*  f0f6044:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f6048:	44813000 */ 	mtc1	$at,$f6
/*  f0f604c:	8fae01d4 */ 	lw	$t6,0x1d4($sp)
/*  f0f6050:	8fb901bc */ 	lw	$t9,0x1bc($sp)
/*  f0f6054:	8fab01b8 */ 	lw	$t3,0x1b8($sp)
/*  f0f6058:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f605c:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f6060:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6064:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f6068:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f606c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f6070:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f6074:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0f6078:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f607c:	0fc3836b */ 	jal	menugfxRenderDialogBackground
/*  f0f6080:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0f6084:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6088:
/*  f0f6088:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f608c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0f6090:	8df80010 */ 	lw	$t8,0x10($t7)
/*  f0f6094:	330d0100 */ 	andi	$t5,$t8,0x100
/*  f0f6098:	51a00046 */ 	beqzl	$t5,.L0f0f61b4
/*  f0f609c:	904d0060 */ 	lbu	$t5,0x60($v0)
/*  f0f60a0:	c4400040 */ 	lwc1	$f0,0x40($v0)
/*  f0f60a4:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f60a8:	00000000 */ 	nop
/*  f0f60ac:	4502000b */ 	bc1fl	.L0f0f60dc
/*  f0f60b0:	904b003d */ 	lbu	$t3,0x3d($v0)
/*  f0f60b4:	904c003c */ 	lbu	$t4,0x3c($v0)
/*  f0f60b8:	3c197f1b */ 	lui	$t9,%hi(g_MenuColourPalettes)
/*  f0f60bc:	27391fb0 */ 	addiu	$t9,$t9,%lo(g_MenuColourPalettes)
/*  f0f60c0:	000c7100 */ 	sll	$t6,$t4,0x4
/*  f0f60c4:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f0f60c8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f60cc:	01d91821 */ 	addu	$v1,$t6,$t9
/*  f0f60d0:	1000001b */ 	b	.L0f0f6140
/*  f0f60d4:	8c720000 */ 	lw	$s2,0x0($v1)
/*  f0f60d8:	904b003d */ 	lbu	$t3,0x3d($v0)
.L0f0f60dc:
/*  f0f60dc:	904c003c */ 	lbu	$t4,0x3c($v0)
/*  f0f60e0:	3c187f1b */ 	lui	$t8,%hi(g_MenuColourPalettes)
/*  f0f60e4:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0f60e8:	000c7100 */ 	sll	$t6,$t4,0x4
/*  f0f60ec:	27181fb0 */ 	addiu	$t8,$t8,%lo(g_MenuColourPalettes)
/*  f0f60f0:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0f60f4:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f0f60f8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f60fc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f6100:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f0f6104:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f0f6108:	8f250000 */ 	lw	$a1,0x0($t9)
/*  f0f610c:	8da40000 */ 	lw	$a0,0x0($t5)
/*  f0f6110:	0fc01a40 */ 	jal	colourBlend
/*  f0f6114:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f6118:	00409025 */ 	or	$s2,$v0,$zero
/*  f0f611c:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f6120:	3c0c7f1b */ 	lui	$t4,%hi(g_MenuColourPalettes)
/*  f0f6124:	258c1fb0 */ 	addiu	$t4,$t4,%lo(g_MenuColourPalettes)
/*  f0f6128:	904f003c */ 	lbu	$t7,0x3c($v0)
/*  f0f612c:	c4400040 */ 	lwc1	$f0,0x40($v0)
/*  f0f6130:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f6134:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f6138:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f613c:	01ac1821 */ 	addu	$v1,$t5,$t4
.L0f0f6140:
/*  f0f6140:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f6144:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes+0x8)
/*  f0f6148:	45020004 */ 	bc1fl	.L0f0f615c
/*  f0f614c:	904e003d */ 	lbu	$t6,0x3d($v0)
/*  f0f6150:	1000000b */ 	b	.L0f0f6180
/*  f0f6154:	8c680008 */ 	lw	$t0,0x8($v1)
/*  f0f6158:	904e003d */ 	lbu	$t6,0x3d($v0)
.L0f0f615c:
/*  f0f615c:	8c650008 */ 	lw	$a1,0x8($v1)
/*  f0f6160:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f6164:	000ec100 */ 	sll	$t8,$t6,0x4
/*  f0f6168:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f0f616c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f6170:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0f6174:	0fc01a40 */ 	jal	colourBlend
/*  f0f6178:	8c841fb8 */ 	lw	$a0,%lo(g_MenuColourPalettes+0x8)($a0)
/*  f0f617c:	00404025 */ 	or	$t0,$v0,$zero
.L0f0f6180:
/*  f0f6180:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0f6184:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6188:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f618c:	272f000c */ 	addiu	$t7,$t9,0xc
/*  f0f6190:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0f6194:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6198:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f619c:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f61a0:	0fc38bba */ 	jal	menugfxRenderDialogBorderLine
/*  f0f61a4:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0f61a8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f61ac:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f61b0:	904d0060 */ 	lbu	$t5,0x60($v0)
.L0f0f61b4:
/*  f0f61b4:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f61b8:	87ac01ca */ 	lh	$t4,0x1ca($sp)
/*  f0f61bc:	15a00003 */ 	bnez	$t5,.L0f0f61cc
/*  f0f61c0:	24720002 */ 	addiu	$s2,$v1,0x2
/*  f0f61c4:	100004ab */ 	b	.L0f0f7474
/*  f0f61c8:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f61cc:
/*  f0f61cc:	01835821 */ 	addu	$t3,$t4,$v1
/*  f0f61d0:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f61d4:	afab0088 */ 	sw	$t3,0x88($sp)
/*  f0f61d8:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0f61dc:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0f61e0:	004e001a */ 	div	$zero,$v0,$t6
/*  f0f61e4:	00009812 */ 	mflo	$s3
/*  f0f61e8:	15c00002 */ 	bnez	$t6,.L0f0f61f4
/*  f0f61ec:	00000000 */ 	nop
/*  f0f61f0:	0007000d */ 	break	0x7
.L0f0f61f4:
/*  f0f61f4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f61f8:	15c10004 */ 	bne	$t6,$at,.L0f0f620c
/*  f0f61fc:	3c018000 */ 	lui	$at,0x8000
/*  f0f6200:	14410002 */ 	bne	$v0,$at,.L0f0f620c
/*  f0f6204:	00000000 */ 	nop
/*  f0f6208:	0006000d */ 	break	0x6
.L0f0f620c:
/*  f0f620c:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6210:	00000000 */ 	nop
/*  f0f6214:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f6218:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0f621c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6220:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f0f6224:	0c002f22 */ 	jal	viGetViewWidth
/*  f0f6228:	03008025 */ 	or	$s0,$t8,$zero
/*  f0f622c:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f0f6230:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f0f6234:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f0f6238:	032f001a */ 	div	$zero,$t9,$t7
/*  f0f623c:	00008812 */ 	mflo	$s1
/*  f0f6240:	15e00002 */ 	bnez	$t7,.L0f0f624c
/*  f0f6244:	00000000 */ 	nop
/*  f0f6248:	0007000d */ 	break	0x7
.L0f0f624c:
/*  f0f624c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f6250:	15e10004 */ 	bne	$t7,$at,.L0f0f6264
/*  f0f6254:	3c018000 */ 	lui	$at,0x8000
/*  f0f6258:	17210002 */ 	bne	$t9,$at,.L0f0f6264
/*  f0f625c:	00000000 */ 	nop
/*  f0f6260:	0006000d */ 	break	0x6
.L0f0f6264:
/*  f0f6264:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6268:	00000000 */ 	nop
/*  f0f626c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6270:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0f6274:	0c002f26 */ 	jal	viGetViewHeight
/*  f0f6278:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0f627c:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f0f6280:	3c08800a */ 	lui	$t0,%hi(g_MenuScissorX1)
/*  f0f6284:	25082038 */ 	addiu	$t0,$t0,%lo(g_MenuScissorX1)
/*  f0f6288:	3c0a800a */ 	lui	$t2,%hi(g_MenuScissorX2)
/*  f0f628c:	ad120000 */ 	sw	$s2,0x0($t0)
/*  f0f6290:	3c01800a */ 	lui	$at,%hi(g_MenuScissorX2)
/*  f0f6294:	258bfffe */ 	addiu	$t3,$t4,-2
/*  f0f6298:	254a203c */ 	addiu	$t2,$t2,%lo(g_MenuScissorX2)
/*  f0f629c:	ac2b203c */ 	sw	$t3,%lo(g_MenuScissorX2)($at)
/*  f0f62a0:	8fae01d4 */ 	lw	$t6,0x1d4($sp)
/*  f0f62a4:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f0f62a8:	3c03800a */ 	lui	$v1,%hi(g_MenuScissorY2)
/*  f0f62ac:	3c09800a */ 	lui	$t1,%hi(g_MenuScissorY1)
/*  f0f62b0:	25292040 */ 	addiu	$t1,$t1,%lo(g_MenuScissorY1)
/*  f0f62b4:	24632044 */ 	addiu	$v1,$v1,%lo(g_MenuScissorY2)
/*  f0f62b8:	25d8ffff */ 	addiu	$t8,$t6,-1
/*  f0f62bc:	0093082a */ 	slt	$at,$a0,$s3
/*  f0f62c0:	ad350000 */ 	sw	$s5,0x0($t1)
/*  f0f62c4:	10200003 */ 	beqz	$at,.L0f0f62d4
/*  f0f62c8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0f62cc:	10000469 */ 	b	.L0f0f7474
/*  f0f62d0:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f62d4:
/*  f0f62d4:	8c650000 */ 	lw	$a1,0x0($v1)
/*  f0f62d8:	00b4082a */ 	slt	$at,$a1,$s4
/*  f0f62dc:	50200004 */ 	beqzl	$at,.L0f0f62f0
/*  f0f62e0:	8d060000 */ 	lw	$a2,0x0($t0)
/*  f0f62e4:	10000463 */ 	b	.L0f0f7474
/*  f0f62e8:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f62ec:	8d060000 */ 	lw	$a2,0x0($t0)
.L0f0f62f0:
/*  f0f62f0:	0226082a */ 	slt	$at,$s1,$a2
/*  f0f62f4:	50200004 */ 	beqzl	$at,.L0f0f6308
/*  f0f62f8:	8d270000 */ 	lw	$a3,0x0($t1)
/*  f0f62fc:	1000045d */ 	b	.L0f0f7474
/*  f0f6300:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f6304:	8d270000 */ 	lw	$a3,0x0($t1)
.L0f0f6308:
/*  f0f6308:	00501821 */ 	addu	$v1,$v0,$s0
/*  f0f630c:	0067082a */ 	slt	$at,$v1,$a3
/*  f0f6310:	50200004 */ 	beqzl	$at,.L0f0f6324
/*  f0f6314:	0224082a */ 	slt	$at,$s1,$a0
/*  f0f6318:	10000456 */ 	b	.L0f0f7474
/*  f0f631c:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f6320:	0224082a */ 	slt	$at,$s1,$a0
.L0f0f6324:
/*  f0f6324:	50200004 */ 	beqzl	$at,.L0f0f6338
/*  f0f6328:	0065082a */ 	slt	$at,$v1,$a1
/*  f0f632c:	ad510000 */ 	sw	$s1,0x0($t2)
/*  f0f6330:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f6334:	0065082a */ 	slt	$at,$v1,$a1
.L0f0f6338:
/*  f0f6338:	10200004 */ 	beqz	$at,.L0f0f634c
/*  f0f633c:	3c01800a */ 	lui	$at,%hi(g_MenuScissorY2)
/*  f0f6340:	ac232044 */ 	sw	$v1,%lo(g_MenuScissorY2)($at)
/*  f0f6344:	3c05800a */ 	lui	$a1,%hi(g_MenuScissorY2)
/*  f0f6348:	8ca52044 */ 	lw	$a1,%lo(g_MenuScissorY2)($a1)
.L0f0f634c:
/*  f0f634c:	00d3082a */ 	slt	$at,$a2,$s3
/*  f0f6350:	50200003 */ 	beqzl	$at,.L0f0f6360
/*  f0f6354:	0094082a */ 	slt	$at,$a0,$s4
/*  f0f6358:	ad130000 */ 	sw	$s3,0x0($t0)
/*  f0f635c:	0094082a */ 	slt	$at,$a0,$s4
.L0f0f6360:
/*  f0f6360:	10200002 */ 	beqz	$at,.L0f0f636c
/*  f0f6364:	00000000 */ 	nop
/*  f0f6368:	ad540000 */ 	sw	$s4,0x0($t2)
.L0f0f636c:
/*  f0f636c:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0f6370:	ac27de90 */ 	sw	$a3,%lo(var8009de90)($at)
/*  f0f6374:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0f6378:	ac25de94 */ 	sw	$a1,%lo(var8009de94)($at)
/*  f0f637c:	0fc3d43f */ 	jal	menuApplyScissor
/*  f0f6380:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6384:	3c198007 */ 	lui	$t9,%hi(g_MpPlayerNum)
/*  f0f6388:	8f391448 */ 	lw	$t9,%lo(g_MpPlayerNum)($t9)
/*  f0f638c:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f6390:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f6394:	001978c0 */ 	sll	$t7,$t9,0x3
/*  f0f6398:	01f97823 */ 	subu	$t7,$t7,$t9
/*  f0f639c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f63a0:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f0f63a4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f63a8:	01f97823 */ 	subu	$t7,$t7,$t9
/*  f0f63ac:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f63b0:	01ed1821 */ 	addu	$v1,$t7,$t5
/*  f0f63b4:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f63b8:	8c6c04f8 */ 	lw	$t4,0x4f8($v1)
/*  f0f63bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f63c0:	54ec0033 */ 	bnel	$a3,$t4,.L0f0f6490
/*  f0f63c4:	90f8003c */ 	lbu	$t8,0x3c($a3)
/*  f0f63c8:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f0f63cc:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
/*  f0f63d0:	8d6e0010 */ 	lw	$t6,0x10($t3)
/*  f0f63d4:	31d80002 */ 	andi	$t8,$t6,0x2
/*  f0f63d8:	5300002d */ 	beqzl	$t8,.L0f0f6490
/*  f0f63dc:	90f8003c */ 	lbu	$t8,0x3c($a3)
/*  f0f63e0:	5720002b */ 	bnezl	$t9,.L0f0f6490
/*  f0f63e4:	90f8003c */ 	lbu	$t8,0x3c($a3)
/*  f0f63e8:	8c6f0df0 */ 	lw	$t7,0xdf0($v1)
/*  f0f63ec:	3c0bb700 */ 	lui	$t3,0xb700
/*  f0f63f0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f63f4:	000f6380 */ 	sll	$t4,$t7,0xe
/*  f0f63f8:	05800024 */ 	bltz	$t4,.L0f0f648c
/*  f0f63fc:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f0f6400:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0f6404:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0f6408:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f0f640c:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f6410:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f6414:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0f6418:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f641c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f6420:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f6424:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f6428:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f642c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f6430:	272f0840 */ 	addiu	$t7,$t9,0x840
/*  f0f6434:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f6438:	01ed2821 */ 	addu	$a1,$t7,$t5
/*  f0f643c:	0fc3ce2c */ 	jal	menuRenderModels
/*  f0f6440:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f6444:	244c0008 */ 	addiu	$t4,$v0,0x8
/*  f0f6448:	afac01e8 */ 	sw	$t4,0x1e8($sp)
/*  f0f644c:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0f6450:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f6454:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0f6458:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0f645c:	8fd00284 */ 	lw	$s0,0x284($s8)
/*  f0f6460:	86040634 */ 	lh	$a0,0x634($s0)
/*  f0f6464:	0c002f2a */ 	jal	viSetViewPosition
/*  f0f6468:	86050636 */ 	lh	$a1,0x636($s0)
/*  f0f646c:	8fd00284 */ 	lw	$s0,0x284($s8)
/*  f0f6470:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f0f6474:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f0f6478:	86060630 */ 	lh	$a2,0x630($s0)
/*  f0f647c:	0c002f76 */ 	jal	viSetFovAspectAndSize
/*  f0f6480:	86070632 */ 	lh	$a3,0x632($s0)
/*  f0f6484:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f6488:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.L0f0f648c:
/*  f0f648c:	90f8003c */ 	lbu	$t8,0x3c($a3)
.L0f0f6490:
/*  f0f6490:	57000008 */ 	bnezl	$t8,.L0f0f64b4
/*  f0f6494:	8fb901e0 */ 	lw	$t9,0x1e0($sp)
/*  f0f6498:	c4e80040 */ 	lwc1	$f8,0x40($a3)
/*  f0f649c:	00809825 */ 	or	$s3,$a0,$zero
/*  f0f64a0:	4608a03e */ 	c.le.s	$f20,$f8
/*  f0f64a4:	00000000 */ 	nop
/*  f0f64a8:	45020292 */ 	bc1fl	.L0f0f6ef4
/*  f0f64ac:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f64b0:	8fb901e0 */ 	lw	$t9,0x1e0($sp)
.L0f0f64b4:
/*  f0f64b4:	afa00130 */ 	sw	$zero,0x130($sp)
/*  f0f64b8:	afa001e4 */ 	sw	$zero,0x1e4($sp)
/*  f0f64bc:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f64c0:	afb90194 */ 	sw	$t9,0x194($sp)
/*  f0f64c4:	90ef0005 */ 	lbu	$t7,0x5($a3)
/*  f0f64c8:	59e001e7 */ 	blezl	$t7,.L0f0f6c68
/*  f0f64cc:	8fad01f4 */ 	lw	$t5,0x1f4($sp)
/*  f0f64d0:	afa401e8 */ 	sw	$a0,0x1e8($sp)
.L0f0f64d4:
/*  f0f64d4:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f64d8:	8fad01dc */ 	lw	$t5,0x1dc($sp)
/*  f0f64dc:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes+0x18)
/*  f0f64e0:	8c4c0064 */ 	lw	$t4,0x64($v0)
/*  f0f64e4:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0f64e8:	01ac5821 */ 	addu	$t3,$t5,$t4
/*  f0f64ec:	256e000c */ 	addiu	$t6,$t3,0xc
/*  f0f64f0:	afae012c */ 	sw	$t6,0x12c($sp)
/*  f0f64f4:	9058003c */ 	lbu	$t8,0x3c($v0)
/*  f0f64f8:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0f64fc:	c44a0040 */ 	lwc1	$f10,0x40($v0)
/*  f0f6500:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f6504:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f6508:	4614503c */ 	c.lt.s	$f10,$f20
/*  f0f650c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f6510:	00b92821 */ 	addu	$a1,$a1,$t9
/*  f0f6514:	8ca51fc8 */ 	lw	$a1,%lo(g_MenuColourPalettes+0x18)($a1)
/*  f0f6518:	45020005 */ 	bc1fl	.L0f0f6530
/*  f0f651c:	904f003d */ 	lbu	$t7,0x3d($v0)
/*  f0f6520:	afa50120 */ 	sw	$a1,0x120($sp)
/*  f0f6524:	1000000d */ 	b	.L0f0f655c
/*  f0f6528:	90430004 */ 	lbu	$v1,0x4($v0)
/*  f0f652c:	904f003d */ 	lbu	$t7,0x3d($v0)
.L0f0f6530:
/*  f0f6530:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes+0x18)
/*  f0f6534:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f6538:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f653c:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f6540:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f6544:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0f6548:	0fc01a40 */ 	jal	colourBlend
/*  f0f654c:	8c841fc8 */ 	lw	$a0,%lo(g_MenuColourPalettes+0x18)($a0)
/*  f0f6550:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0f6554:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f6558:	90430004 */ 	lbu	$v1,0x4($v0)
.L0f0f655c:
/*  f0f655c:	8fab0120 */ 	lw	$t3,0x120($sp)
/*  f0f6560:	8fb901e4 */ 	lw	$t9,0x1e4($sp)
/*  f0f6564:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f6568:	01617024 */ 	and	$t6,$t3,$at
/*  f0f656c:	35d8003f */ 	ori	$t8,$t6,0x3f
/*  f0f6570:	afb80120 */ 	sw	$t8,0x120($sp)
/*  f0f6574:	13200010 */ 	beqz	$t9,.L0f0f65b8
/*  f0f6578:	00798021 */ 	addu	$s0,$v1,$t9
/*  f0f657c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0f6580:	8fa70194 */ 	lw	$a3,0x194($sp)
/*  f0f6584:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f6588:	8ded0010 */ 	lw	$t5,0x10($t7)
/*  f0f658c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6590:	24e5ffff */ 	addiu	$a1,$a3,-1
/*  f0f6594:	31ac0400 */ 	andi	$t4,$t5,0x400
/*  f0f6598:	15800007 */ 	bnez	$t4,.L0f0f65b8
/*  f0f659c:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f0f65a0:	8fab01d4 */ 	lw	$t3,0x1d4($sp)
/*  f0f65a4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f65a8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f65ac:	0fc38bd7 */ 	jal	gfxDrawFilledRect
/*  f0f65b0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f65b4:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f65b8:
/*  f0f65b8:	8fae01f0 */ 	lw	$t6,0x1f0($sp)
/*  f0f65bc:	0010c880 */ 	sll	$t9,$s0,0x2
/*  f0f65c0:	0330c821 */ 	addu	$t9,$t9,$s0
/*  f0f65c4:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f0f65c8:	01d92821 */ 	addu	$a1,$t6,$t9
/*  f0f65cc:	84a40660 */ 	lh	$a0,0x660($a1)
/*  f0f65d0:	8faf0130 */ 	lw	$t7,0x130($sp)
/*  f0f65d4:	8fb801ec */ 	lw	$t8,0x1ec($sp)
/*  f0f65d8:	8fab01e4 */ 	lw	$t3,0x1e4($sp)
/*  f0f65dc:	01e46021 */ 	addu	$t4,$t7,$a0
/*  f0f65e0:	afac0130 */ 	sw	$t4,0x130($sp)
/*  f0f65e4:	afa40124 */ 	sw	$a0,0x124($sp)
/*  f0f65e8:	93030005 */ 	lbu	$v1,0x5($t8)
/*  f0f65ec:	256e0001 */ 	addiu	$t6,$t3,0x1
/*  f0f65f0:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0f65f4:	15c30009 */ 	bne	$t6,$v1,.L0f0f661c
/*  f0f65f8:	00806825 */ 	or	$t5,$a0,$zero
/*  f0f65fc:	8faf01e0 */ 	lw	$t7,0x1e0($sp)
/*  f0f6600:	032f1023 */ 	subu	$v0,$t9,$t7
/*  f0f6604:	2442fffe */ 	addiu	$v0,$v0,-2
/*  f0f6608:	0182082a */ 	slt	$at,$t4,$v0
/*  f0f660c:	10200003 */ 	beqz	$at,.L0f0f661c
/*  f0f6610:	01a2c021 */ 	addu	$t8,$t5,$v0
/*  f0f6614:	030c5823 */ 	subu	$t3,$t8,$t4
/*  f0f6618:	afab0124 */ 	sw	$t3,0x124($sp)
.L0f0f661c:
/*  f0f661c:	90ae0668 */ 	lbu	$t6,0x668($a1)
/*  f0f6620:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0f6624:	19c00187 */ 	blez	$t6,.L0f0f6c44
/*  f0f6628:	272f000c */ 	addiu	$t7,$t9,0xc
/*  f0f662c:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f0f6630:	afa50080 */ 	sw	$a1,0x80($sp)
/*  f0f6634:	8fb80080 */ 	lw	$t8,0x80($sp)
.L0f0f6638:
/*  f0f6638:	afa00114 */ 	sw	$zero,0x114($sp)
/*  f0f663c:	8fab01c0 */ 	lw	$t3,0x1c0($sp)
/*  f0f6640:	970c0666 */ 	lhu	$t4,0x666($t8)
/*  f0f6644:	8fae01f0 */ 	lw	$t6,0x1f0($sp)
/*  f0f6648:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f664c:	018b1821 */ 	addu	$v1,$t4,$t3
/*  f0f6650:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0f6654:	01d91021 */ 	addu	$v0,$t6,$t9
/*  f0f6658:	904f04fe */ 	lbu	$t7,0x4fe($v0)
/*  f0f665c:	8dac0000 */ 	lw	$t4,0x0($t5)
/*  f0f6660:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f6664:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0f6668:	8d8b0008 */ 	lw	$t3,0x8($t4)
/*  f0f666c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f6670:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f6674:	030b3021 */ 	addu	$a2,$t8,$t3
/*  f0f6678:	afa60118 */ 	sw	$a2,0x118($sp)
/*  f0f667c:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f0f6680:	8dae0008 */ 	lw	$t6,0x8($t5)
/*  f0f6684:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f6688:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f668c:	54ce0008 */ 	bnel	$a2,$t6,.L0f0f66b0
/*  f0f6690:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0f6694:	afb90114 */ 	sw	$t9,0x114($sp)
/*  f0f6698:	8daf000c */ 	lw	$t7,0xc($t5)
/*  f0f669c:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f0f66a0:	51e00003 */ 	beqzl	$t7,.L0f0f66b0
/*  f0f66a4:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0f66a8:	afac0114 */ 	sw	$t4,0x114($sp)
/*  f0f66ac:	8fb8007c */ 	lw	$t8,0x7c($sp)
.L0f0f66b0:
/*  f0f66b0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f66b4:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0f66b8:	830204ff */ 	lb	$v0,0x4ff($t8)
/*  f0f66bc:	8fab01f0 */ 	lw	$t3,0x1f0($sp)
/*  f0f66c0:	8fb90194 */ 	lw	$t9,0x194($sp)
/*  f0f66c4:	10410003 */ 	beq	$v0,$at,.L0f0f66d4
/*  f0f66c8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0f66cc:	016e2821 */ 	addu	$a1,$t3,$t6
/*  f0f66d0:	24a506dc */ 	addiu	$a1,$a1,0x6dc
.L0f0f66d4:
/*  f0f66d4:	8fad0124 */ 	lw	$t5,0x124($sp)
/*  f0f66d8:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f0f66dc:	a7b90198 */ 	sh	$t9,0x198($sp)
/*  f0f66e0:	a7a3019a */ 	sh	$v1,0x19a($sp)
/*  f0f66e4:	a7ad019c */ 	sh	$t5,0x19c($sp)
/*  f0f66e8:	85ec04fc */ 	lh	$t4,0x4fc($t7)
/*  f0f66ec:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0f66f0:	00031400 */ 	sll	$v0,$v1,0x10
/*  f0f66f4:	0002c403 */ 	sra	$t8,$v0,0x10
/*  f0f66f8:	030c5821 */ 	addu	$t3,$t8,$t4
/*  f0f66fc:	016e082a */ 	slt	$at,$t3,$t6
/*  f0f6700:	03001025 */ 	or	$v0,$t8,$zero
/*  f0f6704:	10200002 */ 	beqz	$at,.L0f0f6710
/*  f0f6708:	a7ac019e */ 	sh	$t4,0x19e($sp)
/*  f0f670c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f6710:
/*  f0f6710:	8fb901d4 */ 	lw	$t9,0x1d4($sp)
/*  f0f6714:	87ad019e */ 	lh	$t5,0x19e($sp)
/*  f0f6718:	8faf0118 */ 	lw	$t7,0x118($sp)
/*  f0f671c:	0322082a */ 	slt	$at,$t9,$v0
/*  f0f6720:	10200002 */ 	beqz	$at,.L0f0f672c
/*  f0f6724:	00000000 */ 	nop
/*  f0f6728:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f672c:
/*  f0f672c:	15a00002 */ 	bnez	$t5,.L0f0f6738
/*  f0f6730:	00000000 */ 	nop
/*  f0f6734:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f6738:
/*  f0f6738:	54800133 */ 	bnezl	$a0,.L0f0f6c08
/*  f0f673c:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f6740:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f0f6744:	8fb80114 */ 	lw	$t8,0x114($sp)
/*  f0f6748:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f674c:	afaf01a0 */ 	sw	$t7,0x1a0($sp)
/*  f0f6750:	afa501ac */ 	sw	$a1,0x1ac($sp)
/*  f0f6754:	afb801a4 */ 	sw	$t8,0x1a4($sp)
/*  f0f6758:	1160000e */ 	beqz	$t3,.L0f0f6794
/*  f0f675c:	afac01a8 */ 	sw	$t4,0x1a8($sp)
/*  f0f6760:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f6764:	87b00196 */ 	lh	$s0,0x196($sp)
/*  f0f6768:	87ae0126 */ 	lh	$t6,0x126($sp)
/*  f0f676c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6770:	2446ffff */ 	addiu	$a2,$v0,-1
/*  f0f6774:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0f6778:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0f677c:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f6780:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f6784:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f6788:	0fc38bd7 */ 	jal	gfxDrawFilledRect
/*  f0f678c:	020e3821 */ 	addu	$a3,$s0,$t6
/*  f0f6790:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6794:
/*  f0f6794:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f0f6798:	8fb801f4 */ 	lw	$t8,0x1f4($sp)
/*  f0f679c:	8f2d0004 */ 	lw	$t5,0x4($t9)
/*  f0f67a0:	31af4000 */ 	andi	$t7,$t5,0x4000
/*  f0f67a4:	51e00046 */ 	beqzl	$t7,.L0f0f68c0
/*  f0f67a8:	8fb90114 */ 	lw	$t9,0x114($sp)
/*  f0f67ac:	17000043 */ 	bnez	$t8,.L0f0f68bc
/*  f0f67b0:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f67b4:	c5b00040 */ 	lwc1	$f16,0x40($t5)
/*  f0f67b8:	87b00198 */ 	lh	$s0,0x198($sp)
/*  f0f67bc:	87ae019c */ 	lh	$t6,0x19c($sp)
/*  f0f67c0:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0f67c4:	87b1019a */ 	lh	$s1,0x19a($sp)
/*  f0f67c8:	87b9019e */ 	lh	$t9,0x19e($sp)
/*  f0f67cc:	01d09021 */ 	addu	$s2,$t6,$s0
/*  f0f67d0:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f67d4:	45000009 */ 	bc1f	.L0f0f67fc
/*  f0f67d8:	03319821 */ 	addu	$s3,$t9,$s1
/*  f0f67dc:	91af003c */ 	lbu	$t7,0x3c($t5)
/*  f0f67e0:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes+0x28)
/*  f0f67e4:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0f67e8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f67ec:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f67f0:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0f67f4:	10000011 */ 	b	.L0f0f683c
/*  f0f67f8:	8c841fd8 */ 	lw	$a0,%lo(g_MenuColourPalettes+0x28)($a0)
.L0f0f67fc:
/*  f0f67fc:	91cc003d */ 	lbu	$t4,0x3d($t6)
/*  f0f6800:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0f6804:	91cd003c */ 	lbu	$t5,0x3c($t6)
/*  f0f6808:	01820019 */ 	multu	$t4,$v0
/*  f0f680c:	3c037f1b */ 	lui	$v1,%hi(g_MenuColourPalettes)
/*  f0f6810:	24631fb0 */ 	addiu	$v1,$v1,%lo(g_MenuColourPalettes)
/*  f0f6814:	8dc60044 */ 	lw	$a2,0x44($t6)
/*  f0f6818:	0000c812 */ 	mflo	$t9
/*  f0f681c:	00795821 */ 	addu	$t3,$v1,$t9
/*  f0f6820:	8d640028 */ 	lw	$a0,0x28($t3)
/*  f0f6824:	01a20019 */ 	multu	$t5,$v0
/*  f0f6828:	00007812 */ 	mflo	$t7
/*  f0f682c:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f0f6830:	0fc01a40 */ 	jal	colourBlend
/*  f0f6834:	8f050028 */ 	lw	$a1,0x28($t8)
/*  f0f6838:	00402025 */ 	or	$a0,$v0,$zero
.L0f0f683c:
/*  f0f683c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f6840:	00812824 */ 	and	$a1,$a0,$at
/*  f0f6844:	0fc01a40 */ 	jal	colourBlend
/*  f0f6848:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0f684c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6850:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0f6854:	00402825 */ 	or	$a1,$v0,$zero
/*  f0f6858:	3c038008 */ 	lui	$v1,%hi(g_ScaleX)
/*  f0f685c:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScaleX)
/*  f0f6860:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f6864:	3c01f600 */ 	lui	$at,0xf600
/*  f0f6868:	327803ff */ 	andi	$t8,$s3,0x3ff
/*  f0f686c:	024c0019 */ 	multu	$s2,$t4
/*  f0f6870:	00187080 */ 	sll	$t6,$t8,0x2
/*  f0f6874:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f6878:	0000c812 */ 	mflo	$t9
/*  f0f687c:	332b03ff */ 	andi	$t3,$t9,0x3ff
/*  f0f6880:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f0f6884:	01a17825 */ 	or	$t7,$t5,$at
/*  f0f6888:	01ee6025 */ 	or	$t4,$t7,$t6
/*  f0f688c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0f6890:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f6894:	322f03ff */ 	andi	$t7,$s1,0x3ff
/*  f0f6898:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0f689c:	02190019 */ 	multu	$s0,$t9
/*  f0f68a0:	00005812 */ 	mflo	$t3
/*  f0f68a4:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f0f68a8:	000dc380 */ 	sll	$t8,$t5,0xe
/*  f0f68ac:	030e6025 */ 	or	$t4,$t8,$t6
/*  f0f68b0:	0fc54e0e */ 	jal	func0f153838
/*  f0f68b4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0f68b8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f68bc:
/*  f0f68bc:	8fb90114 */ 	lw	$t9,0x114($sp)
.L0f0f68c0:
/*  f0f68c0:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f0f68c4:	532000c0 */ 	beqzl	$t9,.L0f0f6bc8
/*  f0f68c8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f68cc:	91620000 */ 	lbu	$v0,0x0($t3)
/*  f0f68d0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f68d4:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f68d8:	1041000b */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68dc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f68e0:	10410009 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68e4:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0f68e8:	10410007 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68ec:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f68f0:	10410005 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68f4:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f68f8:	10410003 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68fc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f6900:	54410015 */ 	bnel	$v0,$at,.L0f0f6958
/*  f0f6904:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0f6908:
/*  f0f6908:	c5a00040 */ 	lwc1	$f0,0x40($t5)
/*  f0f690c:	4600a03e */ 	c.le.s	$f20,$f0
/*  f0f6910:	00000000 */ 	nop
/*  f0f6914:	45020005 */ 	bc1fl	.L0f0f692c
/*  f0f6918:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f691c:	91af003d */ 	lbu	$t7,0x3d($t5)
/*  f0f6920:	51e0000d */ 	beqzl	$t7,.L0f0f6958
/*  f0f6924:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f6928:	4614003c */ 	c.lt.s	$f0,$f20
.L0f0f692c:
/*  f0f692c:	8fb801ec */ 	lw	$t8,0x1ec($sp)
/*  f0f6930:	45000004 */ 	bc1f	.L0f0f6944
/*  f0f6934:	00000000 */ 	nop
/*  f0f6938:	930e003c */ 	lbu	$t6,0x3c($t8)
/*  f0f693c:	51c00006 */ 	beqzl	$t6,.L0f0f6958
/*  f0f6940:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0f6944:
/*  f0f6944:	0fc55809 */ 	jal	func0f156024
/*  f0f6948:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f694c:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0f6950:	91820000 */ 	lbu	$v0,0x0($t4)
/*  f0f6954:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0f6958:
/*  f0f6958:	10410008 */ 	beq	$v0,$at,.L0f0f697c
/*  f0f695c:	87a3019c */ 	lh	$v1,0x19c($sp)
/*  f0f6960:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0f6964:	10410005 */ 	beq	$v0,$at,.L0f0f697c
/*  f0f6968:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f696c:	10410003 */ 	beq	$v0,$at,.L0f0f697c
/*  f0f6970:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f6974:	54410094 */ 	bnel	$v0,$at,.L0f0f6bc8
/*  f0f6978:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.L0f0f697c:
/*  f0f697c:	87ab019e */ 	lh	$t3,0x19e($sp)
/*  f0f6980:	8fb70120 */ 	lw	$s7,0x120($sp)
/*  f0f6984:	87a20198 */ 	lh	$v0,0x198($sp)
/*  f0f6988:	87b9019a */ 	lh	$t9,0x19a($sp)
/*  f0f698c:	05610003 */ 	bgez	$t3,.L0f0f699c
/*  f0f6990:	000b6843 */ 	sra	$t5,$t3,0x1
/*  f0f6994:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0f6998:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f699c:
/*  f0f699c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f69a0:	0061001a */ 	div	$zero,$v1,$at
/*  f0f69a4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f69a8:	02e1c024 */ 	and	$t8,$s7,$at
/*  f0f69ac:	00007812 */ 	mflo	$t7
/*  f0f69b0:	370e002f */ 	ori	$t6,$t8,0x2f
/*  f0f69b4:	032d8021 */ 	addu	$s0,$t9,$t5
/*  f0f69b8:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0f69bc:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f0f69c0:	0300b825 */ 	or	$s7,$t8,$zero
/*  f0f69c4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f69c8:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0f69cc:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f0f69d0:	0fc38926 */ 	jal	func0f0e2498
/*  f0f69d4:	004ff021 */ 	addu	$s8,$v0,$t7
/*  f0f69d8:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f69dc:	2615ffff */ 	addiu	$s5,$s0,-1
/*  f0f69e0:	2632fffd */ 	addiu	$s2,$s1,-3
/*  f0f69e4:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f69e8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f69ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f69f0:	02802825 */ 	or	$a1,$s4,$zero
/*  f0f69f4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f69f8:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f69fc:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f6a00:	0fc38963 */ 	jal	gfxDrawTri2
/*  f0f6a04:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f6a08:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f0f6a0c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0f6a10:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f6a14:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a18:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f6a1c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6a20:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6a24:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f6a28:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6a2c:	0fc38963 */ 	jal	gfxDrawTri2
/*  f0f6a30:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f6a34:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f6a38:	26130001 */ 	addiu	$s3,$s0,0x1
/*  f0f6a3c:	26160002 */ 	addiu	$s6,$s0,0x2
/*  f0f6a40:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6a44:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6a48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a4c:	02802825 */ 	or	$a1,$s4,$zero
/*  f0f6a50:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f6a54:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6a58:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f6a5c:	0fc38963 */ 	jal	gfxDrawTri2
/*  f0f6a60:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f6a64:	8fb90120 */ 	lw	$t9,0x120($sp)
/*  f0f6a68:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0f6a6c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f6a70:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a74:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f6a78:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6a7c:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6a80:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6a84:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6a88:	0fc38963 */ 	jal	gfxDrawTri2
/*  f0f6a8c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f6a90:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0f6a94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a98:	2625fffe */ 	addiu	$a1,$s1,-2
/*  f0f6a9c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f6aa0:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0f6aa4:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f6aa8:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f0f6aac:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6ab0:	0fc38963 */ 	jal	gfxDrawTri2
/*  f0f6ab4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f6ab8:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f0f6abc:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6ac0:	87a20198 */ 	lh	$v0,0x198($sp)
/*  f0f6ac4:	8f0e0004 */ 	lw	$t6,0x4($t8)
/*  f0f6ac8:	87a3019c */ 	lh	$v1,0x19c($sp)
/*  f0f6acc:	8fa80120 */ 	lw	$t0,0x120($sp)
/*  f0f6ad0:	31cc0020 */ 	andi	$t4,$t6,0x20
/*  f0f6ad4:	1180003b */ 	beqz	$t4,.L0f0f6bc4
/*  f0f6ad8:	00433821 */ 	addu	$a3,$v0,$v1
/*  f0f6adc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f6ae0:	0061001a */ 	div	$zero,$v1,$at
/*  f0f6ae4:	00005812 */ 	mflo	$t3
/*  f0f6ae8:	00e0a025 */ 	or	$s4,$a3,$zero
/*  f0f6aec:	24f1fff8 */ 	addiu	$s1,$a3,-8
/*  f0f6af0:	00ebf023 */ 	subu	$s8,$a3,$t3
/*  f0f6af4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6af8:	24e5fffb */ 	addiu	$a1,$a3,-5
/*  f0f6afc:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6b00:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f6b04:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0f6b08:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0f6b0c:	0fc38963 */ 	jal	gfxDrawTri2
/*  f0f6b10:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b14:	8fad0120 */ 	lw	$t5,0x120($sp)
/*  f0f6b18:	26320003 */ 	addiu	$s2,$s1,0x3
/*  f0f6b1c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f6b20:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f6b24:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f6b28:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6b2c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f6b30:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6b34:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f6b38:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b3c:	0fc38963 */ 	jal	gfxDrawTri2
/*  f0f6b40:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f6b44:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f0f6b48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6b4c:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f6b50:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6b54:	02803825 */ 	or	$a3,$s4,$zero
/*  f0f6b58:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6b5c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b60:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f6b64:	0fc38963 */ 	jal	gfxDrawTri2
/*  f0f6b68:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0f6b6c:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f0f6b70:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f6b74:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f6b78:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6b7c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f6b80:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6b84:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f6b88:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6b8c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b90:	0fc38963 */ 	jal	gfxDrawTri2
/*  f0f6b94:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0f6b98:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0f6b9c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6ba0:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0f6ba4:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f6ba8:	26270002 */ 	addiu	$a3,$s1,0x2
/*  f0f6bac:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f6bb0:	afb70014 */ 	sw	$s7,0x14($sp)
/*  f0f6bb4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6bb8:	0fc38963 */ 	jal	gfxDrawTri2
/*  f0f6bbc:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0f6bc0:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6bc4:
/*  f0f6bc4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.L0f0f6bc8:
/*  f0f6bc8:	0fc3c167 */ 	jal	menuitemRender
/*  f0f6bcc:	27a50198 */ 	addiu	$a1,$sp,0x198
/*  f0f6bd0:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f0f6bd4:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6bd8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f6bdc:	91790000 */ 	lbu	$t9,0x0($t3)
/*  f0f6be0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0f6be4:	57210003 */ 	bnel	$t9,$at,.L0f0f6bf4
/*  f0f6be8:	8faf0114 */ 	lw	$t7,0x114($sp)
/*  f0f6bec:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f0f6bf0:	8faf0114 */ 	lw	$t7,0x114($sp)
.L0f0f6bf4:
/*  f0f6bf4:	51e00004 */ 	beqzl	$t7,.L0f0f6c08
/*  f0f6bf8:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f6bfc:	0fc55809 */ 	jal	func0f156024
/*  f0f6c00:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f6c04:	8fae007c */ 	lw	$t6,0x7c($sp)
.L0f0f6c08:
/*  f0f6c08:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0f6c0c:	8fb8012c */ 	lw	$t8,0x12c($sp)
/*  f0f6c10:	85cc04fc */ 	lh	$t4,0x4fc($t6)
/*  f0f6c14:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f0f6c18:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f0f6c1c:	030c5821 */ 	addu	$t3,$t8,$t4
/*  f0f6c20:	afad01c0 */ 	sw	$t5,0x1c0($sp)
/*  f0f6c24:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0f6c28:	904f0668 */ 	lbu	$t7,0x668($v0)
/*  f0f6c2c:	01af082a */ 	slt	$at,$t5,$t7
/*  f0f6c30:	5420fe81 */ 	bnezl	$at,.L0f0f6638
/*  f0f6c34:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0f6c38:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f6c3c:	84440660 */ 	lh	$a0,0x660($v0)
/*  f0f6c40:	91c30005 */ 	lbu	$v1,0x5($t6)
.L0f0f6c44:
/*  f0f6c44:	8fab01e4 */ 	lw	$t3,0x1e4($sp)
/*  f0f6c48:	8fb80194 */ 	lw	$t8,0x194($sp)
/*  f0f6c4c:	25790001 */ 	addiu	$t9,$t3,0x1
/*  f0f6c50:	0323082a */ 	slt	$at,$t9,$v1
/*  f0f6c54:	03046021 */ 	addu	$t4,$t8,$a0
/*  f0f6c58:	afb901e4 */ 	sw	$t9,0x1e4($sp)
/*  f0f6c5c:	1420fe1d */ 	bnez	$at,.L0f0f64d4
/*  f0f6c60:	afac0194 */ 	sw	$t4,0x194($sp)
/*  f0f6c64:	8fad01f4 */ 	lw	$t5,0x1f4($sp)
.L0f0f6c68:
/*  f0f6c68:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6c6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f6c70:	15a00061 */ 	bnez	$t5,.L0f0f6df8
/*  f0f6c74:	8faf01e0 */ 	lw	$t7,0x1e0($sp)
/*  f0f6c78:	afaf0194 */ 	sw	$t7,0x194($sp)
/*  f0f6c7c:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0f6c80:	afa001e4 */ 	sw	$zero,0x1e4($sp)
/*  f0f6c84:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f6c88:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6c8c:	91c30005 */ 	lbu	$v1,0x5($t6)
/*  f0f6c90:	18600055 */ 	blez	$v1,.L0f0f6de8
/*  f0f6c94:	00000000 */ 	nop
.L0f0f6c98:
/*  f0f6c98:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f6c9c:	8fad01e4 */ 	lw	$t5,0x1e4($sp)
/*  f0f6ca0:	8fb801dc */ 	lw	$t8,0x1dc($sp)
/*  f0f6ca4:	91990004 */ 	lbu	$t9,0x4($t4)
/*  f0f6ca8:	8d8b0064 */ 	lw	$t3,0x64($t4)
/*  f0f6cac:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f0f6cb0:	032d8021 */ 	addu	$s0,$t9,$t5
/*  f0f6cb4:	00107080 */ 	sll	$t6,$s0,0x2
/*  f0f6cb8:	01d07021 */ 	addu	$t6,$t6,$s0
/*  f0f6cbc:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f0f6cc0:	030b8821 */ 	addu	$s1,$t8,$t3
/*  f0f6cc4:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0f6cc8:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f0f6ccc:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0f6cd0:	930b0668 */ 	lbu	$t3,0x668($t8)
/*  f0f6cd4:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f0f6cd8:	87b00196 */ 	lh	$s0,0x196($sp)
/*  f0f6cdc:	59600039 */ 	blezl	$t3,.L0f0f6dc4
/*  f0f6ce0:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0f6ce4:	8fac0080 */ 	lw	$t4,0x80($sp)
.L0f0f6ce8:
/*  f0f6ce8:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*  f0f6cec:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f0f6cf0:	95990666 */ 	lhu	$t9,0x666($t4)
/*  f0f6cf4:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f6cf8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f6cfc:	032d1821 */ 	addu	$v1,$t9,$t5
/*  f0f6d00:	00037080 */ 	sll	$t6,$v1,0x2
/*  f0f6d04:	01ee2021 */ 	addu	$a0,$t7,$t6
/*  f0f6d08:	909804fe */ 	lbu	$t8,0x4fe($a0)
/*  f0f6d0c:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0f6d10:	808204ff */ 	lb	$v0,0x4ff($a0)
/*  f0f6d14:	00185880 */ 	sll	$t3,$t8,0x2
/*  f0f6d18:	8f2d0008 */ 	lw	$t5,0x8($t9)
/*  f0f6d1c:	01785821 */ 	addu	$t3,$t3,$t8
/*  f0f6d20:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f6d24:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f6d28:	afa4007c */ 	sw	$a0,0x7c($sp)
/*  f0f6d2c:	10410005 */ 	beq	$v0,$at,.L0f0f6d44
/*  f0f6d30:	016d4821 */ 	addu	$t1,$t3,$t5
/*  f0f6d34:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0f6d38:	01ee4021 */ 	addu	$t0,$t7,$t6
/*  f0f6d3c:	250806dc */ 	addiu	$t0,$t0,0x6dc
/*  f0f6d40:	afa4007c */ 	sw	$a0,0x7c($sp)
.L0f0f6d44:
/*  f0f6d44:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f0f6d48:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f0f6d4c:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f6d50:	87270660 */ 	lh	$a3,0x660($t9)
/*  f0f6d54:	856d04fc */ 	lh	$t5,0x4fc($t3)
/*  f0f6d58:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f0f6d5c:	00113400 */ 	sll	$a2,$s1,0x10
/*  f0f6d60:	00066403 */ 	sra	$t4,$a2,0x10
/*  f0f6d64:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f0f6d68:	03002825 */ 	or	$a1,$t8,$zero
/*  f0f6d6c:	01803025 */ 	or	$a2,$t4,$zero
/*  f0f6d70:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0f6d74:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0f6d78:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6d7c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0f6d80:	0fc3c246 */ 	jal	menuitemOverlay
/*  f0f6d84:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f6d88:	8fac01c0 */ 	lw	$t4,0x1c0($sp)
/*  f0f6d8c:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f6d90:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f0f6d94:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6d98:	85d804fc */ 	lh	$t8,0x4fc($t6)
/*  f0f6d9c:	25990001 */ 	addiu	$t9,$t4,0x1
/*  f0f6da0:	afb901c0 */ 	sw	$t9,0x1c0($sp)
/*  f0f6da4:	916d0668 */ 	lbu	$t5,0x668($t3)
/*  f0f6da8:	02388821 */ 	addu	$s1,$s1,$t8
/*  f0f6dac:	032d082a */ 	slt	$at,$t9,$t5
/*  f0f6db0:	5420ffcd */ 	bnezl	$at,.L0f0f6ce8
/*  f0f6db4:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f0f6db8:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f6dbc:	91e30005 */ 	lbu	$v1,0x5($t7)
/*  f0f6dc0:	8fb80080 */ 	lw	$t8,0x80($sp)
.L0f0f6dc4:
/*  f0f6dc4:	8fb901e4 */ 	lw	$t9,0x1e4($sp)
/*  f0f6dc8:	8fae0194 */ 	lw	$t6,0x194($sp)
/*  f0f6dcc:	870c0660 */ 	lh	$t4,0x660($t8)
/*  f0f6dd0:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f0f6dd4:	01a3082a */ 	slt	$at,$t5,$v1
/*  f0f6dd8:	01cc5821 */ 	addu	$t3,$t6,$t4
/*  f0f6ddc:	afad01e4 */ 	sw	$t5,0x1e4($sp)
/*  f0f6de0:	1420ffad */ 	bnez	$at,.L0f0f6c98
/*  f0f6de4:	afab0194 */ 	sw	$t3,0x194($sp)
.L0f0f6de8:
/*  f0f6de8:	0fc54e0e */ 	jal	func0f153838
/*  f0f6dec:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6df0:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6df4:	00402025 */ 	or	$a0,$v0,$zero
.L0f0f6df8:
/*  f0f6df8:	00809825 */ 	or	$s3,$a0,$zero
/*  f0f6dfc:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f6e00:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f6e04:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f6e08:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6e0c:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0f6e10:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6e14:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0f6e18:	44829000 */ 	mtc1	$v0,$f18
/*  f0f6e1c:	44905000 */ 	mtc1	$s0,$f10
/*  f0f6e20:	3c014080 */ 	lui	$at,0x4080
/*  f0f6e24:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f6e28:	44810000 */ 	mtc1	$at,$f0
/*  f0f6e2c:	3c01ed00 */ 	lui	$at,0xed00
/*  f0f6e30:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0f6e34:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0f6e38:	00000000 */ 	nop
/*  f0f6e3c:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0f6e40:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f6e44:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f6e48:	440e4000 */ 	mfc1	$t6,$f8
/*  f0f6e4c:	440d2000 */ 	mfc1	$t5,$f4
/*  f0f6e50:	31cc0fff */ 	andi	$t4,$t6,0xfff
/*  f0f6e54:	01815825 */ 	or	$t3,$t4,$at
/*  f0f6e58:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0f6e5c:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0f6e60:	01787025 */ 	or	$t6,$t3,$t8
/*  f0f6e64:	0c002f22 */ 	jal	viGetViewWidth
/*  f0f6e68:	ae6e0000 */ 	sw	$t6,0x0($s3)
/*  f0f6e6c:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f6e70:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0f6e74:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f6e78:	01808825 */ 	or	$s1,$t4,$zero
/*  f0f6e7c:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0f6e80:	0012cc03 */ 	sra	$t9,$s2,0x10
/*  f0f6e84:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6e88:	03209025 */ 	or	$s2,$t9,$zero
/*  f0f6e8c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6e90:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0f6e94:	0c002f26 */ 	jal	viGetViewHeight
/*  f0f6e98:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0f6e9c:	00507821 */ 	addu	$t7,$v0,$s0
/*  f0f6ea0:	448f3000 */ 	mtc1	$t7,$f6
/*  f0f6ea4:	02516021 */ 	addu	$t4,$s2,$s1
/*  f0f6ea8:	448c9000 */ 	mtc1	$t4,$f18
/*  f0f6eac:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f6eb0:	3c014080 */ 	lui	$at,0x4080
/*  f0f6eb4:	44810000 */ 	mtc1	$at,$f0
/*  f0f6eb8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f6ebc:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f6ec0:	00000000 */ 	nop
/*  f0f6ec4:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0f6ec8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f6ecc:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f6ed0:	44188000 */ 	mfc1	$t8,$f16
/*  f0f6ed4:	440d4000 */ 	mfc1	$t5,$f8
/*  f0f6ed8:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f0f6edc:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0f6ee0:	000f5b00 */ 	sll	$t3,$t7,0xc
/*  f0f6ee4:	01cbc025 */ 	or	$t8,$t6,$t3
/*  f0f6ee8:	1000003e */ 	b	.L0f0f6fe4
/*  f0f6eec:	ae780004 */ 	sw	$t8,0x4($s3)
/*  f0f6ef0:	24840008 */ 	addiu	$a0,$a0,0x8
.L0f0f6ef4:
/*  f0f6ef4:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f6ef8:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f6efc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6f00:	00106403 */ 	sra	$t4,$s0,0x10
/*  f0f6f04:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6f08:	01808025 */ 	or	$s0,$t4,$zero
/*  f0f6f0c:	44825000 */ 	mtc1	$v0,$f10
/*  f0f6f10:	44903000 */ 	mtc1	$s0,$f6
/*  f0f6f14:	3c014080 */ 	lui	$at,0x4080
/*  f0f6f18:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0f6f1c:	44810000 */ 	mtc1	$at,$f0
/*  f0f6f20:	3c01ed00 */ 	lui	$at,0xed00
/*  f0f6f24:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f6f28:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0f6f2c:	00000000 */ 	nop
/*  f0f6f30:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f6f34:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f6f38:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f6f3c:	440d2000 */ 	mfc1	$t5,$f4
/*  f0f6f40:	44188000 */ 	mfc1	$t8,$f16
/*  f0f6f44:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0f6f48:	01e17025 */ 	or	$t6,$t7,$at
/*  f0f6f4c:	330c0fff */ 	andi	$t4,$t8,0xfff
/*  f0f6f50:	000ccb00 */ 	sll	$t9,$t4,0xc
/*  f0f6f54:	01d96825 */ 	or	$t5,$t6,$t9
/*  f0f6f58:	0c002f22 */ 	jal	viGetViewWidth
/*  f0f6f5c:	ae6d0000 */ 	sw	$t5,0x0($s3)
/*  f0f6f60:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f6f64:	00117c03 */ 	sra	$t7,$s1,0x10
/*  f0f6f68:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f6f6c:	01e08825 */ 	or	$s1,$t7,$zero
/*  f0f6f70:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0f6f74:	00125c03 */ 	sra	$t3,$s2,0x10
/*  f0f6f78:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6f7c:	01609025 */ 	or	$s2,$t3,$zero
/*  f0f6f80:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6f84:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f0f6f88:	0c002f26 */ 	jal	viGetViewHeight
/*  f0f6f8c:	03008025 */ 	or	$s0,$t8,$zero
/*  f0f6f90:	00506021 */ 	addu	$t4,$v0,$s0
/*  f0f6f94:	448c9000 */ 	mtc1	$t4,$f18
/*  f0f6f98:	02517821 */ 	addu	$t7,$s2,$s1
/*  f0f6f9c:	448f8000 */ 	mtc1	$t7,$f16
/*  f0f6fa0:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f6fa4:	3c014080 */ 	lui	$at,0x4080
/*  f0f6fa8:	44813000 */ 	mtc1	$at,$f6
/*  f0f6fac:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0f6fb0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0f6fb4:	44812000 */ 	mtc1	$at,$f4
/*  f0f6fb8:	00000000 */ 	nop
/*  f0f6fbc:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0f6fc0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0f6fc4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f6fc8:	44195000 */ 	mfc1	$t9,$f10
/*  f0f6fcc:	44184000 */ 	mfc1	$t8,$f8
/*  f0f6fd0:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f0f6fd4:	330c0fff */ 	andi	$t4,$t8,0xfff
/*  f0f6fd8:	000c7300 */ 	sll	$t6,$t4,0xc
/*  f0f6fdc:	01aec825 */ 	or	$t9,$t5,$t6
/*  f0f6fe0:	ae790004 */ 	sw	$t9,0x4($s3)
.L0f0f6fe4:
/*  f0f6fe4:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f6fe8:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f6fec:	3c18800a */ 	lui	$t8,%hi(g_Menus)
/*  f0f6ff0:	2718e000 */ 	addiu	$t8,$t8,%lo(g_Menus)
/*  f0f6ff4:	000f58c0 */ 	sll	$t3,$t7,0x3
/*  f0f6ff8:	016f5823 */ 	subu	$t3,$t3,$t7
/*  f0f6ffc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f7000:	016f5821 */ 	addu	$t3,$t3,$t7
/*  f0f7004:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f7008:	016f5823 */ 	subu	$t3,$t3,$t7
/*  f0f700c:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f7010:	01781821 */ 	addu	$v1,$t3,$t8
/*  f0f7014:	846c04f4 */ 	lh	$t4,0x4f4($v1)
/*  f0f7018:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f701c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0f7020:	91d9003c */ 	lbu	$t9,0x3c($t6)
/*  f0f7024:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f7028:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0f702c:	006d8821 */ 	addu	$s1,$v1,$t5
/*  f0f7030:	17200006 */ 	bnez	$t9,.L0f0f704c
/*  f0f7034:	2631044c */ 	addiu	$s1,$s1,0x44c
/*  f0f7038:	c5ca0040 */ 	lwc1	$f10,0x40($t6)
/*  f0f703c:	460aa03e */ 	c.le.s	$f20,$f10
/*  f0f7040:	00000000 */ 	nop
/*  f0f7044:	4502010b */ 	bc1fl	.L0f0f7474
/*  f0f7048:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f704c:
/*  f0f704c:	822b0015 */ 	lb	$t3,0x15($s1)
/*  f0f7050:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f7054:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f0f7058:	02386021 */ 	addu	$t4,$s1,$t8
/*  f0f705c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0f7060:	55ed0104 */ 	bnel	$t7,$t5,.L0f0f7474
/*  f0f7064:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f7068:	82390014 */ 	lb	$t9,0x14($s1)
/*  f0f706c:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0f7070:	142000ff */ 	bnez	$at,.L0f0f7470
/*  f0f7074:	3c014120 */ 	lui	$at,0x4120
/*  f0f7078:	44816000 */ 	mtc1	$at,$f12
/*  f0f707c:	0fc01ac2 */ 	jal	func0f006b08
/*  f0f7080:	00000000 */ 	nop
/*  f0f7084:	3c01437f */ 	lui	$at,0x437f
/*  f0f7088:	44818000 */ 	mtc1	$at,$f16
/*  f0f708c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0f7090:	3c014f00 */ 	lui	$at,0x4f00
/*  f0f7094:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0f7098:	8fab01ec */ 	lw	$t3,0x1ec($sp)
/*  f0f709c:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f70a0:	444ef800 */ 	cfc1	$t6,$31
/*  f0f70a4:	44d0f800 */ 	ctc1	$s0,$31
/*  f0f70a8:	00000000 */ 	nop
/*  f0f70ac:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f0f70b0:	4450f800 */ 	cfc1	$s0,$31
/*  f0f70b4:	00000000 */ 	nop
/*  f0f70b8:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0f70bc:	52000013 */ 	beqzl	$s0,.L0f0f710c
/*  f0f70c0:	44102000 */ 	mfc1	$s0,$f4
/*  f0f70c4:	44812000 */ 	mtc1	$at,$f4
/*  f0f70c8:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0f70cc:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f0f70d0:	44d0f800 */ 	ctc1	$s0,$31
/*  f0f70d4:	00000000 */ 	nop
/*  f0f70d8:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0f70dc:	4450f800 */ 	cfc1	$s0,$31
/*  f0f70e0:	00000000 */ 	nop
/*  f0f70e4:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0f70e8:	16000005 */ 	bnez	$s0,.L0f0f7100
/*  f0f70ec:	00000000 */ 	nop
/*  f0f70f0:	44102000 */ 	mfc1	$s0,$f4
/*  f0f70f4:	3c018000 */ 	lui	$at,0x8000
/*  f0f70f8:	10000007 */ 	b	.L0f0f7118
/*  f0f70fc:	02018025 */ 	or	$s0,$s0,$at
.L0f0f7100:
/*  f0f7100:	10000005 */ 	b	.L0f0f7118
/*  f0f7104:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f0f7108:	44102000 */ 	mfc1	$s0,$f4
.L0f0f710c:
/*  f0f710c:	00000000 */ 	nop
/*  f0f7110:	0600fffb */ 	bltz	$s0,.L0f0f7100
/*  f0f7114:	00000000 */ 	nop
.L0f0f7118:
/*  f0f7118:	44cef800 */ 	ctc1	$t6,$31
/*  f0f711c:	c5660040 */ 	lwc1	$f6,0x40($t3)
/*  f0f7120:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0f7124:	00000000 */ 	nop
/*  f0f7128:	4502000a */ 	bc1fl	.L0f0f7154
/*  f0f712c:	91ed003d */ 	lbu	$t5,0x3d($t7)
/*  f0f7130:	9178003c */ 	lbu	$t8,0x3c($t3)
/*  f0f7134:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes)
/*  f0f7138:	00186100 */ 	sll	$t4,$t8,0x4
/*  f0f713c:	01986023 */ 	subu	$t4,$t4,$t8
/*  f0f7140:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f7144:	00ac2821 */ 	addu	$a1,$a1,$t4
/*  f0f7148:	10000011 */ 	b	.L0f0f7190
/*  f0f714c:	8ca51fb0 */ 	lw	$a1,%lo(g_MenuColourPalettes)($a1)
/*  f0f7150:	91ed003d */ 	lbu	$t5,0x3d($t7)
.L0f0f7154:
/*  f0f7154:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0f7158:	91eb003c */ 	lbu	$t3,0x3c($t7)
/*  f0f715c:	01a20019 */ 	multu	$t5,$v0
/*  f0f7160:	3c037f1b */ 	lui	$v1,%hi(g_MenuColourPalettes)
/*  f0f7164:	24631fb0 */ 	addiu	$v1,$v1,%lo(g_MenuColourPalettes)
/*  f0f7168:	8de60044 */ 	lw	$a2,0x44($t7)
/*  f0f716c:	0000c812 */ 	mflo	$t9
/*  f0f7170:	00797021 */ 	addu	$t6,$v1,$t9
/*  f0f7174:	8dc40000 */ 	lw	$a0,0x0($t6)
/*  f0f7178:	01620019 */ 	multu	$t3,$v0
/*  f0f717c:	0000c012 */ 	mflo	$t8
/*  f0f7180:	00786021 */ 	addu	$t4,$v1,$t8
/*  f0f7184:	0fc01a40 */ 	jal	colourBlend
/*  f0f7188:	8d850000 */ 	lw	$a1,0x0($t4)
/*  f0f718c:	00402825 */ 	or	$a1,$v0,$zero
.L0f0f7190:
/*  f0f7190:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0f7194:	0fc01a40 */ 	jal	colourBlend
/*  f0f7198:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f719c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0f71a0:	4481a000 */ 	mtc1	$at,$f20
/*  f0f71a4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f71a8:	0fc01ac2 */ 	jal	func0f006b08
/*  f0f71ac:	4600a306 */ 	mov.s	$f12,$f20
/*  f0f71b0:	8fad01dc */ 	lw	$t5,0x1dc($sp)
/*  f0f71b4:	8fb901d4 */ 	lw	$t9,0x1d4($sp)
/*  f0f71b8:	8fa501e0 */ 	lw	$a1,0x1e0($sp)
/*  f0f71bc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f71c0:	01b9a821 */ 	addu	$s5,$t5,$t9
/*  f0f71c4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f71c8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f71cc:	24070009 */ 	addiu	$a3,$zero,0x9
/*  f0f71d0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f71d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f71d8:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0f71dc:	24a5fffb */ 	addiu	$a1,$a1,-5
/*  f0f71e0:	06a10003 */ 	bgez	$s5,.L0f0f71f0
/*  f0f71e4:	0015a043 */ 	sra	$s4,$s5,0x1
/*  f0f71e8:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f0f71ec:	0001a043 */ 	sra	$s4,$at,0x1
.L0f0f71f0:
/*  f0f71f0:	0fc38cc9 */ 	jal	func0f0e3324
/*  f0f71f4:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f71f8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f71fc:	0fc01ac2 */ 	jal	func0f006b08
/*  f0f7200:	4600a306 */ 	mov.s	$f12,$f20
/*  f0f7204:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0f7208:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f0f720c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f7210:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f7214:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f7218:	24070009 */ 	addiu	$a3,$zero,0x9
/*  f0f721c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f7220:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f7224:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0f7228:	0fc38cc9 */ 	jal	func0f0e3324
/*  f0f722c:	24a50005 */ 	addiu	$a1,$a1,0x5
/*  f0f7230:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x4)
/*  f0f7234:	8c6319c4 */ 	lw	$v1,%lo(g_MenuData+0x4)($v1)
/*  f0f7238:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f723c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f7240:	10610007 */ 	beq	$v1,$at,.L0f0f7260
/*  f0f7244:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f7248:	10610005 */ 	beq	$v1,$at,.L0f0f7260
/*  f0f724c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f7250:	10610003 */ 	beq	$v1,$at,.L0f0f7260
/*  f0f7254:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f7258:	54610086 */ 	bnel	$v1,$at,.L0f0f7474
/*  f0f725c:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f7260:
/*  f0f7260:	0fc54f93 */ 	jal	func0f153e4c
/*  f0f7264:	00000000 */ 	nop
/*  f0f7268:	0fc54c6e */ 	jal	textSetRotation90
/*  f0f726c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f7270:	0fc54d8a */ 	jal	func0f153628
/*  f0f7274:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f7278:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f727c:	82230015 */ 	lb	$v1,0x15($s1)
/*  f0f7280:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f7284:	04630004 */ 	bgezl	$v1,.L0f0f7298
/*  f0f7288:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0f728c:	82230014 */ 	lb	$v1,0x14($s1)
/*  f0f7290:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f7294:	0003c080 */ 	sll	$t8,$v1,0x2
.L0f0f7298:
/*  f0f7298:	02386021 */ 	addu	$t4,$s1,$t8
/*  f0f729c:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f0f72a0:	0fc3c560 */ 	jal	menuResolveDialogTitle
/*  f0f72a4:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f0f72a8:	3c138008 */ 	lui	$s3,%hi(g_FontHandelGothicXs)
/*  f0f72ac:	2673fb04 */ 	addiu	$s3,$s3,%lo(g_FontHandelGothicXs)
/*  f0f72b0:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0f72b4:	3c128008 */ 	lui	$s2,%hi(g_CharsHandelGothicXs)
/*  f0f72b8:	2652fb08 */ 	addiu	$s2,$s2,%lo(g_CharsHandelGothicXs)
/*  f0f72bc:	27b600b0 */ 	addiu	$s6,$sp,0xb0
/*  f0f72c0:	27b700ac */ 	addiu	$s7,$sp,0xac
/*  f0f72c4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f72c8:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0f72cc:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0f72d0:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f0f72d4:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f72d8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f72dc:	0fc55cbe */ 	jal	textMeasure
/*  f0f72e0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f72e4:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f0f72e8:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f72ec:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0f72f0:	02822823 */ 	subu	$a1,$s4,$v0
/*  f0f72f4:	24a5fffd */ 	addiu	$a1,$a1,-3
/*  f0f72f8:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f72fc:	00b9082a */ 	slt	$at,$a1,$t9
/*  f0f7300:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f7304:	10200009 */ 	beqz	$at,.L0f0f732c
/*  f0f7308:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f730c:	02a22823 */ 	subu	$a1,$s5,$v0
/*  f0f7310:	04a10003 */ 	bgez	$a1,.L0f0f7320
/*  f0f7314:	00057043 */ 	sra	$t6,$a1,0x1
/*  f0f7318:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0f731c:	00017043 */ 	sra	$t6,$at,0x1
.L0f0f7320:
/*  f0f7320:	2463fffd */ 	addiu	$v1,$v1,-3
/*  f0f7324:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f7328:	afae01cc */ 	sw	$t6,0x1cc($sp)
.L0f0f732c:
/*  f0f732c:	0c002f06 */ 	jal	viGetHeight
/*  f0f7330:	00000000 */ 	nop
/*  f0f7334:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f0f7338:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0f733c:	87af01ca */ 	lh	$t7,0x1ca($sp)
/*  f0f7340:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0f7344:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0f7348:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f734c:	27a501cc */ 	addiu	$a1,$sp,0x1cc
/*  f0f7350:	27a601d0 */ 	addiu	$a2,$sp,0x1d0
/*  f0f7354:	02003825 */ 	or	$a3,$s0,$zero
/*  f0f7358:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f735c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f7360:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f7364:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f7368:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f736c:	0fc5580f */ 	jal	textRenderProjected
/*  f0f7370:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f7374:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f7378:	82230015 */ 	lb	$v1,0x15($s1)
/*  f0f737c:	822d0014 */ 	lb	$t5,0x14($s1)
/*  f0f7380:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f7384:	006d082a */ 	slt	$at,$v1,$t5
/*  f0f7388:	54200003 */ 	bnezl	$at,.L0f0f7398
/*  f0f738c:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0f7390:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f7394:	0003c880 */ 	sll	$t9,$v1,0x2
.L0f0f7398:
/*  f0f7398:	02397021 */ 	addu	$t6,$s1,$t9
/*  f0f739c:	8dcb0000 */ 	lw	$t3,0x0($t6)
/*  f0f73a0:	0fc3c560 */ 	jal	menuResolveDialogTitle
/*  f0f73a4:	8d640000 */ 	lw	$a0,0x0($t3)
/*  f0f73a8:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0f73ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f73b0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0f73b4:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0f73b8:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f73bc:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f0f73c0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f73c4:	0fc55cbe */ 	jal	textMeasure
/*  f0f73c8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f73cc:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f0f73d0:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f0f73d4:	8fac01d4 */ 	lw	$t4,0x1d4($sp)
/*  f0f73d8:	26850003 */ 	addiu	$a1,$s4,0x3
/*  f0f73dc:	00a27821 */ 	addu	$t7,$a1,$v0
/*  f0f73e0:	24630007 */ 	addiu	$v1,$v1,0x7
/*  f0f73e4:	018f082a */ 	slt	$at,$t4,$t7
/*  f0f73e8:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f73ec:	10200009 */ 	beqz	$at,.L0f0f7414
/*  f0f73f0:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f73f4:	02a22823 */ 	subu	$a1,$s5,$v0
/*  f0f73f8:	04a10003 */ 	bgez	$a1,.L0f0f7408
/*  f0f73fc:	00056843 */ 	sra	$t5,$a1,0x1
/*  f0f7400:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0f7404:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f7408:
/*  f0f7408:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0f740c:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f7410:	afad01cc */ 	sw	$t5,0x1cc($sp)
.L0f0f7414:
/*  f0f7414:	0c002f06 */ 	jal	viGetHeight
/*  f0f7418:	00000000 */ 	nop
/*  f0f741c:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f0f7420:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0f7424:	87b801ca */ 	lh	$t8,0x1ca($sp)
/*  f0f7428:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0f742c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f7430:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f7434:	27a501cc */ 	addiu	$a1,$sp,0x1cc
/*  f0f7438:	27a601d0 */ 	addiu	$a2,$sp,0x1d0
/*  f0f743c:	02003825 */ 	or	$a3,$s0,$zero
/*  f0f7440:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f7444:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f7448:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f744c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f7450:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0f7454:	0fc5580f */ 	jal	textRenderProjected
/*  f0f7458:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0f745c:	0fc54de0 */ 	jal	func0f153780
/*  f0f7460:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f7464:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f7468:	0fc54c6e */ 	jal	textSetRotation90
/*  f0f746c:	00002025 */ 	or	$a0,$zero,$zero
.L0f0f7470:
/*  f0f7470:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f7474:
/*  f0f7474:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0f7478:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0f747c:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f0f7480:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f0f7484:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f0f7488:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f0f748c:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f0f7490:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f0f7494:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f0f7498:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f0f749c:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f0f74a0:	03e00008 */ 	jr	$ra
/*  f0f74a4:	27bd01e8 */ 	addiu	$sp,$sp,0x1e8
);
#else
GLOBAL_ASM(
glabel dialogRender
/*  f0f1d94:	27bdfe18 */ 	addiu	$sp,$sp,-488
/*  f0f1d98:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0f1d9c:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0f1da0:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f0f1da4:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f0f1da8:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f0f1dac:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f0f1db0:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f0f1db4:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f0f1db8:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f0f1dbc:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f0f1dc0:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f0f1dc4:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f1dc8:	afa601f0 */ 	sw	$a2,0x1f0($sp)
/*  f0f1dcc:	afa701f4 */ 	sw	$a3,0x1f4($sp)
/*  f0f1dd0:	4480a000 */ 	mtc1	$zero,$f20
/*  f0f1dd4:	c4a40040 */ 	lwc1	$f4,0x40($a1)
/*  f0f1dd8:	8cb50014 */ 	lw	$s5,0x14($a1)
/*  f0f1ddc:	8cb30018 */ 	lw	$s3,0x18($a1)
/*  f0f1de0:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0f1de4:	8cae001c */ 	lw	$t6,0x1c($a1)
/*  f0f1de8:	8caf0020 */ 	lw	$t7,0x20($a1)
/*  f0f1dec:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0f1df0:	02aeb021 */ 	addu	$s6,$s5,$t6
/*  f0f1df4:	4500000b */ 	bc1f	.NB0f0f1e24
/*  f0f1df8:	026fa021 */ 	addu	$s4,$s3,$t7
/*  f0f1dfc:	90b8003c */ 	lbu	$t8,0x3c($a1)
/*  f0f1e00:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0f1e04:	afa501ec */ 	sw	$a1,0x1ec($sp)
/*  f0f1e08:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f1e0c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f1e10:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f1e14:	01795821 */ 	addu	$t3,$t3,$t9
/*  f0f1e18:	8d6bc308 */ 	lw	$t3,-0x3cf8($t3)
/*  f0f1e1c:	10000013 */ 	beqz	$zero,.NB0f0f1e6c
/*  f0f1e20:	afab01bc */ 	sw	$t3,0x1bc($sp)
.NB0f0f1e24:
/*  f0f1e24:	920c003d */ 	lbu	$t4,0x3d($s0)
/*  f0f1e28:	9218003c */ 	lbu	$t8,0x3c($s0)
/*  f0f1e2c:	3c0e7f1b */ 	lui	$t6,0x7f1b
/*  f0f1e30:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0f1e34:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f1e38:	25cec2e0 */ 	addiu	$t6,$t6,-15648
/*  f0f1e3c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f1e40:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f1e44:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f1e48:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f1e4c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f1e50:	032e5821 */ 	addu	$t3,$t9,$t6
/*  f0f1e54:	8d650028 */ 	lw	$a1,0x28($t3)
/*  f0f1e58:	8de40028 */ 	lw	$a0,0x28($t7)
/*  f0f1e5c:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0f1e60:	0fc01990 */ 	jal	colourBlend
/*  f0f1e64:	afb001ec */ 	sw	$s0,0x1ec($sp)
/*  f0f1e68:	afa201bc */ 	sw	$v0,0x1bc($sp)
.NB0f0f1e6c:
/*  f0f1e6c:	8fb001ec */ 	lw	$s0,0x1ec($sp)
/*  f0f1e70:	0fc541a3 */ 	jal	func0f156030
/*  f0f1e74:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0f1e78:	3c0c8007 */ 	lui	$t4,0x8007
/*  f0f1e7c:	8d8c3af0 */ 	lw	$t4,0x3af0($t4)
/*  f0f1e80:	3c0f800a */ 	lui	$t7,0x800a
/*  f0f1e84:	3c018008 */ 	lui	$at,0x8008
/*  f0f1e88:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f0f1e8c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f1e90:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0f1e94:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f1e98:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f0f1e9c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f1ea0:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f1ea4:	25ef27c0 */ 	addiu	$t7,$t7,0x27c0
/*  f0f1ea8:	ac2023fc */ 	sw	$zero,0x23fc($at)
/*  f0f1eac:	01af1821 */ 	addu	$v1,$t5,$t7
/*  f0f1eb0:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f1eb4:	8c780488 */ 	lw	$t8,0x488($v1)
/*  f0f1eb8:	54f8002d */ 	bnel	$a3,$t8,.NB0f0f1f70
/*  f0f1ebc:	8ced001c */ 	lw	$t5,0x1c($a3)
/*  f0f1ec0:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0f1ec4:	8fac01f4 */ 	lw	$t4,0x1f4($sp)
/*  f0f1ec8:	8f2e0010 */ 	lw	$t6,0x10($t9)
/*  f0f1ecc:	31cb0002 */ 	andi	$t3,$t6,0x2
/*  f0f1ed0:	51600027 */ 	beqzl	$t3,.NB0f0f1f70
/*  f0f1ed4:	8ced001c */ 	lw	$t5,0x1c($a3)
/*  f0f1ed8:	55800025 */ 	bnezl	$t4,.NB0f0f1f70
/*  f0f1edc:	8ced001c */ 	lw	$t5,0x1c($a3)
/*  f0f1ee0:	8c6d0d4c */ 	lw	$t5,0xd4c($v1)
/*  f0f1ee4:	8fb901e8 */ 	lw	$t9,0x1e8($sp)
/*  f0f1ee8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f1eec:	000d7b80 */ 	sll	$t7,$t5,0xe
/*  f0f1ef0:	000fc7c2 */ 	srl	$t8,$t7,0x1f
/*  f0f1ef4:	1701001d */ 	bne	$t8,$at,.NB0f0f1f6c
/*  f0f1ef8:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0f1efc:	afae01e8 */ 	sw	$t6,0x1e8($sp)
/*  f0f1f00:	3c0bb700 */ 	lui	$t3,0xb700
/*  f0f1f04:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f1f08:	af2c0004 */ 	sw	$t4,0x4($t9)
/*  f0f1f0c:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f0f1f10:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0f1f14:	8dad3af0 */ 	lw	$t5,0x3af0($t5)
/*  f0f1f18:	3c19800a */ 	lui	$t9,0x800a
/*  f0f1f1c:	273927c0 */ 	addiu	$t9,$t9,0x27c0
/*  f0f1f20:	000d78c0 */ 	sll	$t7,$t5,0x3
/*  f0f1f24:	01ed7823 */ 	subu	$t7,$t7,$t5
/*  f0f1f28:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f1f2c:	01ed7823 */ 	subu	$t7,$t7,$t5
/*  f0f1f30:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f1f34:	01ed7823 */ 	subu	$t7,$t7,$t5
/*  f0f1f38:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f1f3c:	25f8079c */ 	addiu	$t8,$t7,0x79c
/*  f0f1f40:	03192821 */ 	addu	$a1,$t8,$t9
/*  f0f1f44:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f1f48:	0fc3c0fd */ 	jal	menuRenderModels
/*  f0f1f4c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f1f50:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0f1f54:	afae01e8 */ 	sw	$t6,0x1e8($sp)
/*  f0f1f58:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0f1f5c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f1f60:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0f1f64:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0f1f68:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.NB0f0f1f6c:
/*  f0f1f6c:	8ced001c */ 	lw	$t5,0x1c($a3)
.NB0f0f1f70:
/*  f0f1f70:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f1f74:	a7ad01ca */ 	sh	$t5,0x1ca($sp)
/*  f0f1f78:	90ef0060 */ 	lbu	$t7,0x60($a3)
/*  f0f1f7c:	84e20022 */ 	lh	$v0,0x22($a3)
/*  f0f1f80:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f0f1f84:	55e00014 */ 	bnezl	$t7,.NB0f0f1fd8
/*  f0f1f88:	8cec0014 */ 	lw	$t4,0x14($a3)
/*  f0f1f8c:	44813000 */ 	mtc1	$at,$f6
/*  f0f1f90:	3c01800a */ 	lui	$at,0x800a
/*  f0f1f94:	c4285ec0 */ 	lwc1	$f8,0x5ec0($at)
/*  f0f1f98:	44829000 */ 	mtc1	$v0,$f18
/*  f0f1f9c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f1fa0:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f0f1fa4:	44815000 */ 	mtc1	$at,$f10
/*  f0f1fa8:	8ceb0018 */ 	lw	$t3,0x18($a3)
/*  f0f1fac:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f1fb0:	46000402 */ 	mul.s	$f16,$f0,$f0
/*  f0f1fb4:	46105001 */ 	sub.s	$f0,$f10,$f16
/*  f0f1fb8:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0f1fbc:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f1fc0:	44024000 */ 	mfc1	$v0,$f8
/*  f0f1fc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f1fc8:	0002cc00 */ 	sll	$t9,$v0,0x10
/*  f0f1fcc:	00191403 */ 	sra	$v0,$t9,0x10
/*  f0f1fd0:	0162a021 */ 	addu	$s4,$t3,$v0
/*  f0f1fd4:	8cec0014 */ 	lw	$t4,0x14($a3)
.NB0f0f1fd8:
/*  f0f1fd8:	afac01e0 */ 	sw	$t4,0x1e0($sp)
/*  f0f1fdc:	8ce30018 */ 	lw	$v1,0x18($a3)
/*  f0f1fe0:	0043f021 */ 	addu	$s8,$v0,$v1
/*  f0f1fe4:	afbe01d4 */ 	sw	$s8,0x1d4($sp)
/*  f0f1fe8:	0fc3b864 */ 	jal	menuResolveDialogTitle
/*  f0f1fec:	afa301dc */ 	sw	$v1,0x1dc($sp)
/*  f0f1ff0:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f1ff4:	0040b825 */ 	or	$s7,$v0,$zero
/*  f0f1ff8:	c4ea0040 */ 	lwc1	$f10,0x40($a3)
/*  f0f1ffc:	4614503c */ 	c.lt.s	$f10,$f20
/*  f0f2000:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2004:	4502000c */ 	bc1fl	.NB0f0f2038
/*  f0f2008:	90ee003d */ 	lbu	$t6,0x3d($a3)
/*  f0f200c:	90ed003c */ 	lbu	$t5,0x3c($a3)
/*  f0f2010:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f2014:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f2018:	01a80019 */ 	multu	$t5,$t0
/*  f0f201c:	2529c2e0 */ 	addiu	$t1,$t1,-15648
/*  f0f2020:	00007812 */ 	mflo	$t7
/*  f0f2024:	012fc021 */ 	addu	$t8,$t1,$t7
/*  f0f2028:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f0f202c:	10000016 */ 	beqz	$zero,.NB0f0f2088
/*  f0f2030:	afb901bc */ 	sw	$t9,0x1bc($sp)
/*  f0f2034:	90ee003d */ 	lbu	$t6,0x3d($a3)
.NB0f0f2038:
/*  f0f2038:	90ef003c */ 	lbu	$t7,0x3c($a3)
/*  f0f203c:	3c0c7f1b */ 	lui	$t4,0x7f1b
/*  f0f2040:	000e5900 */ 	sll	$t3,$t6,0x4
/*  f0f2044:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0f2048:	258cc2e0 */ 	addiu	$t4,$t4,-15648
/*  f0f204c:	016e5823 */ 	subu	$t3,$t3,$t6
/*  f0f2050:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f2054:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f2058:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f205c:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f0f2060:	030cc821 */ 	addu	$t9,$t8,$t4
/*  f0f2064:	8f250000 */ 	lw	$a1,0x0($t9)
/*  f0f2068:	8da40000 */ 	lw	$a0,0x0($t5)
/*  f0f206c:	0fc01990 */ 	jal	colourBlend
/*  f0f2070:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f2074:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f2078:	2529c2e0 */ 	addiu	$t1,$t1,-15648
/*  f0f207c:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f2080:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f2084:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.NB0f0f2088:
/*  f0f2088:	c4f00040 */ 	lwc1	$f16,0x40($a3)
/*  f0f208c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0f2090:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2094:	45020009 */ 	bc1fl	.NB0f0f20bc
/*  f0f2098:	90f8003d */ 	lbu	$t8,0x3d($a3)
/*  f0f209c:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f20a0:	01c80019 */ 	multu	$t6,$t0
/*  f0f20a4:	00005812 */ 	mflo	$t3
/*  f0f20a8:	012b6821 */ 	addu	$t5,$t1,$t3
/*  f0f20ac:	8daf0004 */ 	lw	$t7,0x4($t5)
/*  f0f20b0:	10000012 */ 	beqz	$zero,.NB0f0f20fc
/*  f0f20b4:	afaf01b8 */ 	sw	$t7,0x1b8($sp)
/*  f0f20b8:	90f8003d */ 	lbu	$t8,0x3d($a3)
.NB0f0f20bc:
/*  f0f20bc:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f20c0:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f20c4:	03080019 */ 	multu	$t8,$t0
/*  f0f20c8:	00006012 */ 	mflo	$t4
/*  f0f20cc:	012cc821 */ 	addu	$t9,$t1,$t4
/*  f0f20d0:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f0f20d4:	01c80019 */ 	multu	$t6,$t0
/*  f0f20d8:	00005812 */ 	mflo	$t3
/*  f0f20dc:	012b6821 */ 	addu	$t5,$t1,$t3
/*  f0f20e0:	0fc01990 */ 	jal	colourBlend
/*  f0f20e4:	8da50004 */ 	lw	$a1,0x4($t5)
/*  f0f20e8:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f20ec:	2529c2e0 */ 	addiu	$t1,$t1,-15648
/*  f0f20f0:	afa201b8 */ 	sw	$v0,0x1b8($sp)
/*  f0f20f4:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f20f8:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.NB0f0f20fc:
/*  f0f20fc:	c4f20040 */ 	lwc1	$f18,0x40($a3)
/*  f0f2100:	4614903c */ 	c.lt.s	$f18,$f20
/*  f0f2104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2108:	45020009 */ 	bc1fl	.NB0f0f2130
/*  f0f210c:	90ee003d */ 	lbu	$t6,0x3d($a3)
/*  f0f2110:	90ef003c */ 	lbu	$t7,0x3c($a3)
/*  f0f2114:	01e80019 */ 	multu	$t7,$t0
/*  f0f2118:	0000c012 */ 	mflo	$t8
/*  f0f211c:	01386021 */ 	addu	$t4,$t1,$t8
/*  f0f2120:	8d990008 */ 	lw	$t9,0x8($t4)
/*  f0f2124:	10000012 */ 	beqz	$zero,.NB0f0f2170
/*  f0f2128:	afb901b4 */ 	sw	$t9,0x1b4($sp)
/*  f0f212c:	90ee003d */ 	lbu	$t6,0x3d($a3)
.NB0f0f2130:
/*  f0f2130:	90ef003c */ 	lbu	$t7,0x3c($a3)
/*  f0f2134:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f2138:	01c80019 */ 	multu	$t6,$t0
/*  f0f213c:	00005812 */ 	mflo	$t3
/*  f0f2140:	012b6821 */ 	addu	$t5,$t1,$t3
/*  f0f2144:	8da40008 */ 	lw	$a0,0x8($t5)
/*  f0f2148:	01e80019 */ 	multu	$t7,$t0
/*  f0f214c:	0000c012 */ 	mflo	$t8
/*  f0f2150:	01386021 */ 	addu	$t4,$t1,$t8
/*  f0f2154:	0fc01990 */ 	jal	colourBlend
/*  f0f2158:	8d850008 */ 	lw	$a1,0x8($t4)
/*  f0f215c:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f2160:	2529c2e0 */ 	addiu	$t1,$t1,-15648
/*  f0f2164:	afa201b4 */ 	sw	$v0,0x1b4($sp)
/*  f0f2168:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f216c:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.NB0f0f2170:
/*  f0f2170:	8fb901e8 */ 	lw	$t9,0x1e8($sp)
/*  f0f2174:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0f2178:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0f217c:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0f2180:	afae01e8 */ 	sw	$t6,0x1e8($sp)
/*  f0f2184:	af2d0004 */ 	sw	$t5,0x4($t9)
/*  f0f2188:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f0f218c:	8faf01bc */ 	lw	$t7,0x1bc($sp)
/*  f0f2190:	8fb201b4 */ 	lw	$s2,0x1b4($sp)
/*  f0f2194:	8fb901b4 */ 	lw	$t9,0x1b4($sp)
/*  f0f2198:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0f219c:	2f010040 */ 	sltiu	$at,$t8,0x40
/*  f0f21a0:	14200005 */ 	bnez	$at,.NB0f0f21b8
/*  f0f21a4:	01e08825 */ 	or	$s1,$t7,$zero
/*  f0f21a8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f21ac:	01e18824 */ 	and	$s1,$t7,$at
/*  f0f21b0:	362c003f */ 	ori	$t4,$s1,0x3f
/*  f0f21b4:	01808825 */ 	or	$s1,$t4,$zero
.NB0f0f21b8:
/*  f0f21b8:	332e00ff */ 	andi	$t6,$t9,0xff
/*  f0f21bc:	2dc10040 */ 	sltiu	$at,$t6,0x40
/*  f0f21c0:	14200005 */ 	bnez	$at,.NB0f0f21d8
/*  f0f21c4:	240dfc18 */ 	addiu	$t5,$zero,-1000
/*  f0f21c8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f21cc:	03219024 */ 	and	$s2,$t9,$at
/*  f0f21d0:	364b003f */ 	ori	$t3,$s2,0x3f
/*  f0f21d4:	01609025 */ 	or	$s2,$t3,$zero
.NB0f0f21d8:
/*  f0f21d8:	3c01800a */ 	lui	$at,0x800a
/*  f0f21dc:	ac2d2680 */ 	sw	$t5,0x2680($at)
/*  f0f21e0:	3c01800a */ 	lui	$at,0x800a
/*  f0f21e4:	241803e8 */ 	addiu	$t8,$zero,0x3e8
/*  f0f21e8:	ac382684 */ 	sw	$t8,0x2684($at)
/*  f0f21ec:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0f21f0:	3c03800a */ 	lui	$v1,0x800a
/*  f0f21f4:	8de40010 */ 	lw	$a0,0x10($t7)
/*  f0f21f8:	308c0100 */ 	andi	$t4,$a0,0x100
/*  f0f21fc:	11800002 */ 	beqz	$t4,.NB0f0f2208
/*  f0f2200:	01802025 */ 	or	$a0,$t4,$zero
/*  f0f2204:	2673000b */ 	addiu	$s3,$s3,0xb
.NB0f0f2208:
/*  f0f2208:	8c635eb4 */ 	lw	$v1,0x5eb4($v1)
/*  f0f220c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f2210:	10610064 */ 	beq	$v1,$at,.NB0f0f23a4
/*  f0f2214:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f2218:	14610004 */ 	bne	$v1,$at,.NB0f0f222c
/*  f0f221c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f2220:	8dcee9d8 */ 	lw	$t6,-0x1628($t6)
/*  f0f2224:	11c0005f */ 	beqz	$t6,.NB0f0f23a4
/*  f0f2228:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0f222c:
/*  f0f222c:	3c10800b */ 	lui	$s0,0x800b
/*  f0f2230:	26108db4 */ 	addiu	$s0,$s0,-29260
/*  f0f2234:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f0f2238:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f223c:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f2240:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f2244:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f2248:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f224c:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f2250:	0fc34923 */ 	jal	func0f0d4d0c
/*  f0f2254:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f2258:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f225c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f2260:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f2264:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f2268:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f226c:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f2270:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f2274:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f2278:	0fc34923 */ 	jal	func0f0d4d0c
/*  f0f227c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f2280:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f2284:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f2288:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f228c:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f2290:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f2294:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f2298:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f229c:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f22a0:	0fc34923 */ 	jal	func0f0d4d0c
/*  f0f22a4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f22a8:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f22ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f22b0:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f22b4:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f22b8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f22bc:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f22c0:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f22c4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f22c8:	0fc34923 */ 	jal	func0f0d4d0c
/*  f0f22cc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f22d0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f22d4:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f22d8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f22dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f22e0:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f22e4:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f22e8:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f22ec:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f22f0:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f22f4:	0fc34923 */ 	jal	func0f0d4d0c
/*  f0f22f8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f22fc:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f2300:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f2304:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0f2308:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f230c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f2310:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f2314:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f2318:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f231c:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f2320:	0fc34923 */ 	jal	func0f0d4d0c
/*  f0f2324:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f2328:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0f232c:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f2330:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0f2334:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f2338:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f233c:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f2340:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f2344:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f2348:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f234c:	0fc34923 */ 	jal	func0f0d4d0c
/*  f0f2350:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f2354:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f2358:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f235c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0f2360:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f2364:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f2368:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f236c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f2370:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f2374:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f2378:	0fc34923 */ 	jal	func0f0d4d0c
/*  f0f237c:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f2380:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f2384:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f2388:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f238c:	8dec0000 */ 	lw	$t4,0x0($t7)
/*  f0f2390:	2529c2e0 */ 	addiu	$t1,$t1,-15648
/*  f0f2394:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f2398:	8d840010 */ 	lw	$a0,0x10($t4)
/*  f0f239c:	308e0100 */ 	andi	$t6,$a0,0x100
/*  f0f23a0:	01c02025 */ 	or	$a0,$t6,$zero
.NB0f0f23a4:
/*  f0f23a4:	148000e7 */ 	bnez	$a0,.NB0f0f2744
/*  f0f23a8:	3c03800a */ 	lui	$v1,0x800a
/*  f0f23ac:	8c635eb4 */ 	lw	$v1,0x5eb4($v1)
/*  f0f23b0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f23b4:	10610002 */ 	beq	$v1,$at,.NB0f0f23c0
/*  f0f23b8:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f23bc:	1461000d */ 	bne	$v1,$at,.NB0f0f23f4
.NB0f0f23c0:
/*  f0f23c0:	3c19800b */ 	lui	$t9,0x800b
/*  f0f23c4:	8f391444 */ 	lw	$t9,0x1444($t9)
/*  f0f23c8:	3c0d800a */ 	lui	$t5,0x800a
/*  f0f23cc:	332b0002 */ 	andi	$t3,$t9,0x2
/*  f0f23d0:	51600009 */ 	beqzl	$t3,.NB0f0f23f8
/*  f0f23d4:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f23d8:	8dadeb50 */ 	lw	$t5,-0x14b0($t5)
/*  f0f23dc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f23e0:	27a401bc */ 	addiu	$a0,$sp,0x1bc
/*  f0f23e4:	11a10003 */ 	beq	$t5,$at,.NB0f0f23f4
/*  f0f23e8:	27a501b8 */ 	addiu	$a1,$sp,0x1b8
/*  f0f23ec:	0fc3c6ea */ 	jal	menuGetTeamTitlebarColours
/*  f0f23f0:	27a601b4 */ 	addiu	$a2,$sp,0x1b4
.NB0f0f23f4:
/*  f0f23f4:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
.NB0f0f23f8:
/*  f0f23f8:	87b801ca */ 	lh	$t8,0x1ca($sp)
/*  f0f23fc:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f2400:	8fac01bc */ 	lw	$t4,0x1bc($sp)
/*  f0f2404:	8fae01b8 */ 	lw	$t6,0x1b8($sp)
/*  f0f2408:	8faf01b4 */ 	lw	$t7,0x1b4($sp)
/*  f0f240c:	03031021 */ 	addu	$v0,$t8,$v1
/*  f0f2410:	24510002 */ 	addiu	$s1,$v0,0x2
/*  f0f2414:	2470fffe */ 	addiu	$s0,$v1,-2
/*  f0f2418:	24d5000b */ 	addiu	$s5,$a2,0xb
/*  f0f241c:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f0f2420:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f2424:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f2428:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0f242c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f2430:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f2434:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0f2438:	0fc37c5f */ 	jal	menugfxRenderGradient
/*  f0f243c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f2440:	8fab01bc */ 	lw	$t3,0x1bc($sp)
/*  f0f2444:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f2448:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f244c:	316d00ff */ 	andi	$t5,$t3,0xff
/*  f0f2450:	000dc042 */ 	srl	$t8,$t5,0x1
/*  f0f2454:	240e0028 */ 	addiu	$t6,$zero,0x28
/*  f0f2458:	24d90001 */ 	addiu	$t9,$a2,0x1
/*  f0f245c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f2460:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0f2464:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f2468:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0f246c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f2470:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f2474:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f2478:	0fc37fce */ 	jal	func0f0e2aa4
/*  f0f247c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0f2480:	8faf01bc */ 	lw	$t7,0x1bc($sp)
/*  f0f2484:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f2488:	240d0028 */ 	addiu	$t5,$zero,0x28
/*  f0f248c:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f0f2490:	00195842 */ 	srl	$t3,$t9,0x1
/*  f0f2494:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f2498:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0f249c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f24a0:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0f24a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f24a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f24ac:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f24b0:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f0f24b4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f24b8:	0fc37fce */ 	jal	func0f0e2aa4
/*  f0f24bc:	24c6000a */ 	addiu	$a2,$a2,0xa
/*  f0f24c0:	8fb201e0 */ 	lw	$s2,0x1e0($sp)
/*  f0f24c4:	8fb001dc */ 	lw	$s0,0x1dc($sp)
/*  f0f24c8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f24cc:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f0f24d0:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0f24d4:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f24d8:	0fc5374a */ 	jal	func0f153628
/*  f0f24dc:	afb201d0 */ 	sw	$s2,0x1d0($sp)
/*  f0f24e0:	8fac01f4 */ 	lw	$t4,0x1f4($sp)
/*  f0f24e4:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f24e8:	afa001b0 */ 	sw	$zero,0x1b0($sp)
/*  f0f24ec:	11800003 */ 	beqz	$t4,.NB0f0f24fc
/*  f0f24f0:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0f24f4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f24f8:	afae01b0 */ 	sw	$t6,0x1b0($sp)
.NB0f0f24fc:
/*  f0f24fc:	25ef3b7c */ 	addiu	$t7,$t7,0x3b7c
/*  f0f2500:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0f2504:	8fa301ec */ 	lw	$v1,0x1ec($sp)
/*  f0f2508:	27b40154 */ 	addiu	$s4,$sp,0x154
/*  f0f250c:	ae810000 */ 	sw	$at,0x0($s4)
/*  f0f2510:	8ded0004 */ 	lw	$t5,0x4($t7)
/*  f0f2514:	ae8d0004 */ 	sw	$t5,0x4($s4)
/*  f0f2518:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0f251c:	ae810008 */ 	sw	$at,0x8($s4)
/*  f0f2520:	8ded000c */ 	lw	$t5,0xc($t7)
/*  f0f2524:	3c0f7f1b */ 	lui	$t7,0x7f1b
/*  f0f2528:	25efc2e0 */ 	addiu	$t7,$t7,-15648
/*  f0f252c:	ae8d000c */ 	sw	$t5,0xc($s4)
/*  f0f2530:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0f2534:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0f2538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f253c:	4502000b */ 	bc1fl	.NB0f0f256c
/*  f0f2540:	906b003d */ 	lbu	$t3,0x3d($v1)
/*  f0f2544:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0f2548:	3c0e7f1b */ 	lui	$t6,0x7f1b
/*  f0f254c:	00186100 */ 	sll	$t4,$t8,0x4
/*  f0f2550:	01986023 */ 	subu	$t4,$t4,$t8
/*  f0f2554:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f2558:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f0f255c:	8dcec2ec */ 	lw	$t6,-0x3d14($t6)
/*  f0f2560:	10000011 */ 	beqz	$zero,.NB0f0f25a8
/*  f0f2564:	afae01bc */ 	sw	$t6,0x1bc($sp)
/*  f0f2568:	906b003d */ 	lbu	$t3,0x3d($v1)
.NB0f0f256c:
/*  f0f256c:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0f2570:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0f2574:	000bc900 */ 	sll	$t9,$t3,0x4
/*  f0f2578:	00186100 */ 	sll	$t4,$t8,0x4
/*  f0f257c:	032bc823 */ 	subu	$t9,$t9,$t3
/*  f0f2580:	01986023 */ 	subu	$t4,$t4,$t8
/*  f0f2584:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f2588:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f258c:	032f6821 */ 	addu	$t5,$t9,$t7
/*  f0f2590:	018f7021 */ 	addu	$t6,$t4,$t7
/*  f0f2594:	8dc5000c */ 	lw	$a1,0xc($t6)
/*  f0f2598:	0fc01990 */ 	jal	colourBlend
/*  f0f259c:	8da4000c */ 	lw	$a0,0xc($t5)
/*  f0f25a0:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f25a4:	8fa301ec */ 	lw	$v1,0x1ec($sp)
.NB0f0f25a8:
/*  f0f25a8:	9062003c */ 	lbu	$v0,0x3c($v1)
/*  f0f25ac:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f25b0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0f25b4:	00025900 */ 	sll	$t3,$v0,0x4
/*  f0f25b8:	01625823 */ 	subu	$t3,$t3,$v0
/*  f0f25bc:	000b1080 */ 	sll	$v0,$t3,0x2
/*  f0f25c0:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0f25c4:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0f25c8:	8ca5c454 */ 	lw	$a1,-0x3bac($a1)
/*  f0f25cc:	0fc53925 */ 	jal	func0f153e38
/*  f0f25d0:	8c84c5bc */ 	lw	$a0,-0x3a44($a0)
/*  f0f25d4:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f25d8:	8fa501dc */ 	lw	$a1,0x1dc($sp)
/*  f0f25dc:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0f25e0:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0f25e4:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f25e8:	0c002f7b */ 	jal	viGetHeight
/*  f0f25ec:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f25f0:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*  f0f25f4:	3c118008 */ 	lui	$s1,0x8008
/*  f0f25f8:	3c138008 */ 	lui	$s3,0x8008
/*  f0f25fc:	2673236c */ 	addiu	$s3,$s3,0x236c
/*  f0f2600:	26312370 */ 	addiu	$s1,$s1,0x2370
/*  f0f2604:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f0f2608:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0f260c:	87af01ca */ 	lh	$t7,0x1ca($sp)
/*  f0f2610:	330c00ff */ 	andi	$t4,$t8,0xff
/*  f0f2614:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0f2618:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f261c:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f2620:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f2624:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0f2628:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f262c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f2630:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f2634:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f2638:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0f263c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0f2640:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f2644:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f2648:	afb201d0 */ 	sw	$s2,0x1d0($sp)
/*  f0f264c:	0c002f7b */ 	jal	viGetHeight
/*  f0f2650:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f2654:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0f2658:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f0f265c:	8fb901bc */ 	lw	$t9,0x1bc($sp)
/*  f0f2660:	87ad01ca */ 	lh	$t5,0x1ca($sp)
/*  f0f2664:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f2668:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f266c:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f2670:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0f2674:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f2678:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f267c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f2680:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f2684:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f2688:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f268c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0f2690:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0f2694:	3c03800a */ 	lui	$v1,0x800a
/*  f0f2698:	8c635eb4 */ 	lw	$v1,0x5eb4($v1)
/*  f0f269c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f26a0:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f26a4:	10610007 */ 	beq	$v1,$at,.NB0f0f26c4
/*  f0f26a8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f26ac:	10610005 */ 	beq	$v1,$at,.NB0f0f26c4
/*  f0f26b0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f26b4:	10610003 */ 	beq	$v1,$at,.NB0f0f26c4
/*  f0f26b8:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f26bc:	1461001b */ 	bne	$v1,$at,.NB0f0f272c
/*  f0f26c0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0f26c4:
/*  f0f26c4:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f0f26c8:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f26cc:	2463fff7 */ 	addiu	$v1,$v1,-9
/*  f0f26d0:	0c002f7b */ 	jal	viGetHeight
/*  f0f26d4:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f26d8:	3c188007 */ 	lui	$t8,0x8007
/*  f0f26dc:	8f183af0 */ 	lw	$t8,0x3af0($t8)
/*  f0f26e0:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0f26e4:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f0f26e8:	00186080 */ 	sll	$t4,$t8,0x2
/*  f0f26ec:	028c7821 */ 	addu	$t7,$s4,$t4
/*  f0f26f0:	8de70000 */ 	lw	$a3,0x0($t7)
/*  f0f26f4:	8fb901bc */ 	lw	$t9,0x1bc($sp)
/*  f0f26f8:	87ad01ca */ 	lh	$t5,0x1ca($sp)
/*  f0f26fc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f2700:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f2704:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f2708:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f270c:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f2710:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f2714:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f2718:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f271c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f2720:	0fc541a6 */ 	jal	textRenderProjected
/*  f0f2724:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0f2728:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.NB0f0f272c:
/*  f0f272c:	0fc537a0 */ 	jal	func0f153780
/*  f0f2730:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f2734:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f2738:	2529c2e0 */ 	addiu	$t1,$t1,-15648
/*  f0f273c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f2740:	2408003c */ 	addiu	$t0,$zero,0x3c
.NB0f0f2744:
/*  f0f2744:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f2748:	8fb501dc */ 	lw	$s5,0x1dc($sp)
/*  f0f274c:	3c18800a */ 	lui	$t8,0x800a
/*  f0f2750:	c4400048 */ 	lwc1	$f0,0x48($v0)
/*  f0f2754:	26b5000b */ 	addiu	$s5,$s5,0xb
/*  f0f2758:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f275c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2760:	4503001e */ 	bc1tl	.NB0f0f27dc
/*  f0f2764:	904e0060 */ 	lbu	$t6,0x60($v0)
/*  f0f2768:	8f185eb4 */ 	lw	$t8,0x5eb4($t8)
/*  f0f276c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f2770:	53010024 */ 	beql	$t8,$at,.NB0f0f2804
/*  f0f2774:	03d5082a */ 	slt	$at,$s8,$s5
/*  f0f2778:	904c0060 */ 	lbu	$t4,0x60($v0)
/*  f0f277c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f2780:	29810003 */ 	slti	$at,$t4,0x3
/*  f0f2784:	54200009 */ 	bnezl	$at,.NB0f0f27ac
/*  f0f2788:	44060000 */ 	mfc1	$a2,$f0
/*  f0f278c:	44060000 */ 	mfc1	$a2,$f0
/*  f0f2790:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f0f2794:	8c450018 */ 	lw	$a1,0x18($v0)
/*  f0f2798:	0fc5389f */ 	jal	func0f153c20
/*  f0f279c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f27a0:	10000006 */ 	beqz	$zero,.NB0f0f27bc
/*  f0f27a4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f27a8:	44060000 */ 	mfc1	$a2,$f0
.NB0f0f27ac:
/*  f0f27ac:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f0f27b0:	0fc5389f */ 	jal	func0f153c20
/*  f0f27b4:	8c450018 */ 	lw	$a1,0x18($v0)
/*  f0f27b8:	240f0001 */ 	addiu	$t7,$zero,0x1
.NB0f0f27bc:
/*  f0f27bc:	3c018008 */ 	lui	$at,0x8008
/*  f0f27c0:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f27c4:	2529c2e0 */ 	addiu	$t1,$t1,-15648
/*  f0f27c8:	ac2f23fc */ 	sw	$t7,0x23fc($at)
/*  f0f27cc:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f27d0:	1000000b */ 	beqz	$zero,.NB0f0f2800
/*  f0f27d4:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f27d8:	904e0060 */ 	lbu	$t6,0x60($v0)
.NB0f0f27dc:
/*  f0f27dc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f27e0:	55c10008 */ 	bnel	$t6,$at,.NB0f0f2804
/*  f0f27e4:	03d5082a */ 	slt	$at,$s8,$s5
/*  f0f27e8:	0fc538f9 */ 	jal	func0f153d88
/*  f0f27ec:	c44c0050 */ 	lwc1	$f12,0x50($v0)
/*  f0f27f0:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f27f4:	2529c2e0 */ 	addiu	$t1,$t1,-15648
/*  f0f27f8:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f27fc:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.NB0f0f2800:
/*  f0f2800:	03d5082a */ 	slt	$at,$s8,$s5
.NB0f0f2804:
/*  f0f2804:	50200003 */ 	beqzl	$at,.NB0f0f2814
/*  f0f2808:	c4460040 */ 	lwc1	$f6,0x40($v0)
/*  f0f280c:	afb501d4 */ 	sw	$s5,0x1d4($sp)
/*  f0f2810:	c4460040 */ 	lwc1	$f6,0x40($v0)
.NB0f0f2814:
/*  f0f2814:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0f2818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f281c:	45020009 */ 	bc1fl	.NB0f0f2844
/*  f0f2820:	904c003d */ 	lbu	$t4,0x3d($v0)
/*  f0f2824:	904b003c */ 	lbu	$t3,0x3c($v0)
/*  f0f2828:	01680019 */ 	multu	$t3,$t0
/*  f0f282c:	0000c812 */ 	mflo	$t9
/*  f0f2830:	01396821 */ 	addu	$t5,$t1,$t9
/*  f0f2834:	8db80010 */ 	lw	$t8,0x10($t5)
/*  f0f2838:	10000012 */ 	beqz	$zero,.NB0f0f2884
/*  f0f283c:	afb801bc */ 	sw	$t8,0x1bc($sp)
/*  f0f2840:	904c003d */ 	lbu	$t4,0x3d($v0)
.NB0f0f2844:
/*  f0f2844:	904b003c */ 	lbu	$t3,0x3c($v0)
/*  f0f2848:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f284c:	01880019 */ 	multu	$t4,$t0
/*  f0f2850:	00007812 */ 	mflo	$t7
/*  f0f2854:	012f7021 */ 	addu	$t6,$t1,$t7
/*  f0f2858:	8dc40010 */ 	lw	$a0,0x10($t6)
/*  f0f285c:	01680019 */ 	multu	$t3,$t0
/*  f0f2860:	0000c812 */ 	mflo	$t9
/*  f0f2864:	01396821 */ 	addu	$t5,$t1,$t9
/*  f0f2868:	0fc01990 */ 	jal	colourBlend
/*  f0f286c:	8da50010 */ 	lw	$a1,0x10($t5)
/*  f0f2870:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f2874:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f2878:	2529c2e0 */ 	addiu	$t1,$t1,-15648
/*  f0f287c:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f2880:	2408003c */ 	addiu	$t0,$zero,0x3c
.NB0f0f2884:
/*  f0f2884:	8c58000c */ 	lw	$t8,0xc($v0)
/*  f0f2888:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0f288c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f2890:	5300000e */ 	beqzl	$t8,.NB0f0f28cc
/*  f0f2894:	c4480040 */ 	lwc1	$f8,0x40($v0)
/*  f0f2898:	0fc01990 */ 	jal	colourBlend
/*  f0f289c:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0f28a0:	8faf01bc */ 	lw	$t7,0x1bc($sp)
/*  f0f28a4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f28a8:	00416024 */ 	and	$t4,$v0,$at
/*  f0f28ac:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f0f28b0:	018e5825 */ 	or	$t3,$t4,$t6
/*  f0f28b4:	3c097f1b */ 	lui	$t1,0x7f1b
/*  f0f28b8:	2529c2e0 */ 	addiu	$t1,$t1,-15648
/*  f0f28bc:	afab01bc */ 	sw	$t3,0x1bc($sp)
/*  f0f28c0:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f28c4:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f28c8:	c4480040 */ 	lwc1	$f8,0x40($v0)
.NB0f0f28cc:
/*  f0f28cc:	4614403c */ 	c.lt.s	$f8,$f20
/*  f0f28d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f28d4:	45020009 */ 	bc1fl	.NB0f0f28fc
/*  f0f28d8:	904c003d */ 	lbu	$t4,0x3d($v0)
/*  f0f28dc:	9059003c */ 	lbu	$t9,0x3c($v0)
/*  f0f28e0:	03280019 */ 	multu	$t9,$t0
/*  f0f28e4:	00006812 */ 	mflo	$t5
/*  f0f28e8:	012dc021 */ 	addu	$t8,$t1,$t5
/*  f0f28ec:	8f0f0014 */ 	lw	$t7,0x14($t8)
/*  f0f28f0:	1000000f */ 	beqz	$zero,.NB0f0f2930
/*  f0f28f4:	afaf01b8 */ 	sw	$t7,0x1b8($sp)
/*  f0f28f8:	904c003d */ 	lbu	$t4,0x3d($v0)
.NB0f0f28fc:
/*  f0f28fc:	9059003c */ 	lbu	$t9,0x3c($v0)
/*  f0f2900:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f2904:	01880019 */ 	multu	$t4,$t0
/*  f0f2908:	00007012 */ 	mflo	$t6
/*  f0f290c:	012e5821 */ 	addu	$t3,$t1,$t6
/*  f0f2910:	8d640014 */ 	lw	$a0,0x14($t3)
/*  f0f2914:	03280019 */ 	multu	$t9,$t0
/*  f0f2918:	00006812 */ 	mflo	$t5
/*  f0f291c:	012dc021 */ 	addu	$t8,$t1,$t5
/*  f0f2920:	0fc01990 */ 	jal	colourBlend
/*  f0f2924:	8f050014 */ 	lw	$a1,0x14($t8)
/*  f0f2928:	afa201b8 */ 	sw	$v0,0x1b8($sp)
/*  f0f292c:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.NB0f0f2930:
/*  f0f2930:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f0f2934:	8fa901e0 */ 	lw	$t1,0x1e0($sp)
/*  f0f2938:	55e0008a */ 	bnezl	$t7,.NB0f0f2b64
/*  f0f293c:	90580060 */ 	lbu	$t8,0x60($v0)
/*  f0f2940:	90430060 */ 	lbu	$v1,0x60($v0)
/*  f0f2944:	87ac01ca */ 	lh	$t4,0x1ca($sp)
/*  f0f2948:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f294c:	14610014 */ 	bne	$v1,$at,.NB0f0f29a0
/*  f0f2950:	01894021 */ 	addu	$t0,$t4,$t1
/*  f0f2954:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f2958:	44815000 */ 	mtc1	$at,$f10
/*  f0f295c:	8fae01d4 */ 	lw	$t6,0x1d4($sp)
/*  f0f2960:	8fab01bc */ 	lw	$t3,0x1bc($sp)
/*  f0f2964:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f0f2968:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f296c:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f2970:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f2974:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f2978:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f297c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f2980:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f2984:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f2988:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*  f0f298c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f2990:	0fc3787b */ 	jal	menugfxRenderDialogBackground
/*  f0f2994:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f2998:	10000027 */ 	beqz	$zero,.NB0f0f2a38
/*  f0f299c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.NB0f0f29a0:
/*  f0f29a0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f29a4:	14610013 */ 	bne	$v1,$at,.NB0f0f29f4
/*  f0f29a8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f29ac:	8fad01d4 */ 	lw	$t5,0x1d4($sp)
/*  f0f29b0:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*  f0f29b4:	8faf01b8 */ 	lw	$t7,0x1b8($sp)
/*  f0f29b8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f29bc:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f29c0:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f29c4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f29c8:	c4500050 */ 	lwc1	$f16,0x50($v0)
/*  f0f29cc:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f29d0:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f29d4:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f29d8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f29dc:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f29e0:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f29e4:	0fc3787b */ 	jal	menugfxRenderDialogBackground
/*  f0f29e8:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*  f0f29ec:	10000012 */ 	beqz	$zero,.NB0f0f2a38
/*  f0f29f0:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.NB0f0f29f4:
/*  f0f29f4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f29f8:	44819000 */ 	mtc1	$at,$f18
/*  f0f29fc:	8fac01d4 */ 	lw	$t4,0x1d4($sp)
/*  f0f2a00:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f0f2a04:	8fab01b8 */ 	lw	$t3,0x1b8($sp)
/*  f0f2a08:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f2a0c:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f2a10:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f2a14:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f2a18:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f2a1c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f2a20:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f2a24:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f0f2a28:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0f2a2c:	0fc3787b */ 	jal	menugfxRenderDialogBackground
/*  f0f2a30:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0f2a34:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.NB0f0f2a38:
/*  f0f2a38:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f2a3c:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0f2a40:	8f2d0010 */ 	lw	$t5,0x10($t9)
/*  f0f2a44:	31b80100 */ 	andi	$t8,$t5,0x100
/*  f0f2a48:	53000046 */ 	beqzl	$t8,.NB0f0f2b64
/*  f0f2a4c:	90580060 */ 	lbu	$t8,0x60($v0)
/*  f0f2a50:	c4400040 */ 	lwc1	$f0,0x40($v0)
/*  f0f2a54:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f2a58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2a5c:	4502000b */ 	bc1fl	.NB0f0f2a8c
/*  f0f2a60:	904b003d */ 	lbu	$t3,0x3d($v0)
/*  f0f2a64:	904f003c */ 	lbu	$t7,0x3c($v0)
/*  f0f2a68:	3c0e7f1b */ 	lui	$t6,0x7f1b
/*  f0f2a6c:	25cec2e0 */ 	addiu	$t6,$t6,-15648
/*  f0f2a70:	000f6100 */ 	sll	$t4,$t7,0x4
/*  f0f2a74:	018f6023 */ 	subu	$t4,$t4,$t7
/*  f0f2a78:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f2a7c:	018e1821 */ 	addu	$v1,$t4,$t6
/*  f0f2a80:	1000001b */ 	beqz	$zero,.NB0f0f2af0
/*  f0f2a84:	8c720000 */ 	lw	$s2,0x0($v1)
/*  f0f2a88:	904b003d */ 	lbu	$t3,0x3d($v0)
.NB0f0f2a8c:
/*  f0f2a8c:	904f003c */ 	lbu	$t7,0x3c($v0)
/*  f0f2a90:	3c0d7f1b */ 	lui	$t5,0x7f1b
/*  f0f2a94:	000bc900 */ 	sll	$t9,$t3,0x4
/*  f0f2a98:	000f6100 */ 	sll	$t4,$t7,0x4
/*  f0f2a9c:	25adc2e0 */ 	addiu	$t5,$t5,-15648
/*  f0f2aa0:	032bc823 */ 	subu	$t9,$t9,$t3
/*  f0f2aa4:	018f6023 */ 	subu	$t4,$t4,$t7
/*  f0f2aa8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f2aac:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f2ab0:	032dc021 */ 	addu	$t8,$t9,$t5
/*  f0f2ab4:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0f2ab8:	8dc50000 */ 	lw	$a1,0x0($t6)
/*  f0f2abc:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f0f2ac0:	0fc01990 */ 	jal	colourBlend
/*  f0f2ac4:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f2ac8:	00409025 */ 	or	$s2,$v0,$zero
/*  f0f2acc:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f2ad0:	3c0f7f1b */ 	lui	$t7,0x7f1b
/*  f0f2ad4:	25efc2e0 */ 	addiu	$t7,$t7,-15648
/*  f0f2ad8:	9059003c */ 	lbu	$t9,0x3c($v0)
/*  f0f2adc:	c4400040 */ 	lwc1	$f0,0x40($v0)
/*  f0f2ae0:	0019c100 */ 	sll	$t8,$t9,0x4
/*  f0f2ae4:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0f2ae8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f2aec:	030f1821 */ 	addu	$v1,$t8,$t7
.NB0f0f2af0:
/*  f0f2af0:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f2af4:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f2af8:	45020004 */ 	bc1fl	.NB0f0f2b0c
/*  f0f2afc:	904c003d */ 	lbu	$t4,0x3d($v0)
/*  f0f2b00:	1000000b */ 	beqz	$zero,.NB0f0f2b30
/*  f0f2b04:	8c680008 */ 	lw	$t0,0x8($v1)
/*  f0f2b08:	904c003d */ 	lbu	$t4,0x3d($v0)
.NB0f0f2b0c:
/*  f0f2b0c:	8c650008 */ 	lw	$a1,0x8($v1)
/*  f0f2b10:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f2b14:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0f2b18:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f2b1c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f2b20:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0f2b24:	0fc01990 */ 	jal	colourBlend
/*  f0f2b28:	8c84c2e8 */ 	lw	$a0,-0x3d18($a0)
/*  f0f2b2c:	00404025 */ 	or	$t0,$v0,$zero
.NB0f0f2b30:
/*  f0f2b30:	8fae01dc */ 	lw	$t6,0x1dc($sp)
/*  f0f2b34:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f2b38:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f2b3c:	25d9000c */ 	addiu	$t9,$t6,0xc
/*  f0f2b40:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f2b44:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f2b48:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f2b4c:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f2b50:	0fc380df */ 	jal	menugfxRenderDialogBorderLine
/*  f0f2b54:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0f2b58:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f2b5c:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f2b60:	90580060 */ 	lbu	$t8,0x60($v0)
.NB0f0f2b64:
/*  f0f2b64:	57000004 */ 	bnezl	$t8,.NB0f0f2b78
/*  f0f2b68:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f2b6c:	1000049f */ 	beqz	$zero,.NB0f0f3dec
/*  f0f2b70:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f2b74:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
.NB0f0f2b78:
/*  f0f2b78:	87af01ca */ 	lh	$t7,0x1ca($sp)
/*  f0f2b7c:	24720002 */ 	addiu	$s2,$v1,0x2
/*  f0f2b80:	01e35821 */ 	addu	$t3,$t7,$v1
/*  f0f2b84:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0f2b88:	afab0088 */ 	sw	$t3,0x88($sp)
/*  f0f2b8c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0f2b90:	8d8c2320 */ 	lw	$t4,0x2320($t4)
/*  f0f2b94:	004c001a */ 	div	$zero,$v0,$t4
/*  f0f2b98:	00009812 */ 	mflo	$s3
/*  f0f2b9c:	15800002 */ 	bnez	$t4,.NB0f0f2ba8
/*  f0f2ba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2ba4:	0007000d */ 	break	0x7
.NB0f0f2ba8:
/*  f0f2ba8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f2bac:	15810004 */ 	bne	$t4,$at,.NB0f0f2bc0
/*  f0f2bb0:	3c018000 */ 	lui	$at,0x8000
/*  f0f2bb4:	14410002 */ 	bne	$v0,$at,.NB0f0f2bc0
/*  f0f2bb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2bbc:	0006000d */ 	break	0x6
.NB0f0f2bc0:
/*  f0f2bc0:	0c002fb9 */ 	jal	viGetViewTop
/*  f0f2bc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2bc8:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0f2bcc:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0f2bd0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f2bd4:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0f2bd8:	0c002f97 */ 	jal	viGetViewWidth
/*  f0f2bdc:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0f2be0:	3c198008 */ 	lui	$t9,0x8008
/*  f0f2be4:	8f392320 */ 	lw	$t9,0x2320($t9)
/*  f0f2be8:	00507021 */ 	addu	$t6,$v0,$s0
/*  f0f2bec:	01d9001a */ 	div	$zero,$t6,$t9
/*  f0f2bf0:	00008812 */ 	mflo	$s1
/*  f0f2bf4:	17200002 */ 	bnez	$t9,.NB0f0f2c00
/*  f0f2bf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2bfc:	0007000d */ 	break	0x7
.NB0f0f2c00:
/*  f0f2c00:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f2c04:	17210004 */ 	bne	$t9,$at,.NB0f0f2c18
/*  f0f2c08:	3c018000 */ 	lui	$at,0x8000
/*  f0f2c0c:	15c10002 */ 	bne	$t6,$at,.NB0f0f2c18
/*  f0f2c10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2c14:	0006000d */ 	break	0x6
.NB0f0f2c18:
/*  f0f2c18:	0c002fb9 */ 	jal	viGetViewTop
/*  f0f2c1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2c20:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f2c24:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f0f2c28:	0c002f9b */ 	jal	viGetViewHeight
/*  f0f2c2c:	03008025 */ 	or	$s0,$t8,$zero
/*  f0f2c30:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f0f2c34:	3c08800a */ 	lui	$t0,0x800a
/*  f0f2c38:	25086528 */ 	addiu	$t0,$t0,0x6528
/*  f0f2c3c:	3c0a800a */ 	lui	$t2,0x800a
/*  f0f2c40:	ad120000 */ 	sw	$s2,0x0($t0)
/*  f0f2c44:	3c01800a */ 	lui	$at,0x800a
/*  f0f2c48:	25ebfffe */ 	addiu	$t3,$t7,-2
/*  f0f2c4c:	254a652c */ 	addiu	$t2,$t2,0x652c
/*  f0f2c50:	ac2b652c */ 	sw	$t3,0x652c($at)
/*  f0f2c54:	8fac01d4 */ 	lw	$t4,0x1d4($sp)
/*  f0f2c58:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f0f2c5c:	3c03800a */ 	lui	$v1,0x800a
/*  f0f2c60:	3c09800a */ 	lui	$t1,0x800a
/*  f0f2c64:	25296530 */ 	addiu	$t1,$t1,0x6530
/*  f0f2c68:	24636534 */ 	addiu	$v1,$v1,0x6534
/*  f0f2c6c:	258dffff */ 	addiu	$t5,$t4,-1
/*  f0f2c70:	0093082a */ 	slt	$at,$a0,$s3
/*  f0f2c74:	ad350000 */ 	sw	$s5,0x0($t1)
/*  f0f2c78:	10200003 */ 	beqz	$at,.NB0f0f2c88
/*  f0f2c7c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0f2c80:	1000045a */ 	beqz	$zero,.NB0f0f3dec
/*  f0f2c84:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.NB0f0f2c88:
/*  f0f2c88:	8c650000 */ 	lw	$a1,0x0($v1)
/*  f0f2c8c:	00b4082a */ 	slt	$at,$a1,$s4
/*  f0f2c90:	50200004 */ 	beqzl	$at,.NB0f0f2ca4
/*  f0f2c94:	8d060000 */ 	lw	$a2,0x0($t0)
/*  f0f2c98:	10000454 */ 	beqz	$zero,.NB0f0f3dec
/*  f0f2c9c:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f2ca0:	8d060000 */ 	lw	$a2,0x0($t0)
.NB0f0f2ca4:
/*  f0f2ca4:	0226082a */ 	slt	$at,$s1,$a2
/*  f0f2ca8:	50200004 */ 	beqzl	$at,.NB0f0f2cbc
/*  f0f2cac:	8d270000 */ 	lw	$a3,0x0($t1)
/*  f0f2cb0:	1000044e */ 	beqz	$zero,.NB0f0f3dec
/*  f0f2cb4:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f2cb8:	8d270000 */ 	lw	$a3,0x0($t1)
.NB0f0f2cbc:
/*  f0f2cbc:	00501821 */ 	addu	$v1,$v0,$s0
/*  f0f2cc0:	0067082a */ 	slt	$at,$v1,$a3
/*  f0f2cc4:	50200004 */ 	beqzl	$at,.NB0f0f2cd8
/*  f0f2cc8:	0224082a */ 	slt	$at,$s1,$a0
/*  f0f2ccc:	10000447 */ 	beqz	$zero,.NB0f0f3dec
/*  f0f2cd0:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f2cd4:	0224082a */ 	slt	$at,$s1,$a0
.NB0f0f2cd8:
/*  f0f2cd8:	50200004 */ 	beqzl	$at,.NB0f0f2cec
/*  f0f2cdc:	0065082a */ 	slt	$at,$v1,$a1
/*  f0f2ce0:	ad510000 */ 	sw	$s1,0x0($t2)
/*  f0f2ce4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f2ce8:	0065082a */ 	slt	$at,$v1,$a1
.NB0f0f2cec:
/*  f0f2cec:	10200004 */ 	beqz	$at,.NB0f0f2d00
/*  f0f2cf0:	3c01800a */ 	lui	$at,0x800a
/*  f0f2cf4:	ac236534 */ 	sw	$v1,0x6534($at)
/*  f0f2cf8:	3c05800a */ 	lui	$a1,0x800a
/*  f0f2cfc:	8ca56534 */ 	lw	$a1,0x6534($a1)
.NB0f0f2d00:
/*  f0f2d00:	00d3082a */ 	slt	$at,$a2,$s3
/*  f0f2d04:	50200003 */ 	beqzl	$at,.NB0f0f2d14
/*  f0f2d08:	0094082a */ 	slt	$at,$a0,$s4
/*  f0f2d0c:	ad130000 */ 	sw	$s3,0x0($t0)
/*  f0f2d10:	0094082a */ 	slt	$at,$a0,$s4
.NB0f0f2d14:
/*  f0f2d14:	10200002 */ 	beqz	$at,.NB0f0f2d20
/*  f0f2d18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2d1c:	ad540000 */ 	sw	$s4,0x0($t2)
.NB0f0f2d20:
/*  f0f2d20:	3c01800a */ 	lui	$at,0x800a
/*  f0f2d24:	ac272680 */ 	sw	$a3,0x2680($at)
/*  f0f2d28:	3c01800a */ 	lui	$at,0x800a
/*  f0f2d2c:	ac252684 */ 	sw	$a1,0x2684($at)
/*  f0f2d30:	0fc3c728 */ 	jal	menuApplyScissor
/*  f0f2d34:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f2d38:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f2d3c:	8dce3af0 */ 	lw	$t6,0x3af0($t6)
/*  f0f2d40:	3c18800a */ 	lui	$t8,0x800a
/*  f0f2d44:	271827c0 */ 	addiu	$t8,$t8,0x27c0
/*  f0f2d48:	000ec8c0 */ 	sll	$t9,$t6,0x3
/*  f0f2d4c:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f0f2d50:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f2d54:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f0f2d58:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f2d5c:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f0f2d60:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f2d64:	03381821 */ 	addu	$v1,$t9,$t8
/*  f0f2d68:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f2d6c:	8c6f0488 */ 	lw	$t7,0x488($v1)
/*  f0f2d70:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f2d74:	54ef0035 */ 	bnel	$a3,$t7,.NB0f0f2e4c
/*  f0f2d78:	90ed003c */ 	lbu	$t5,0x3c($a3)
/*  f0f2d7c:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f0f2d80:	8fae01f4 */ 	lw	$t6,0x1f4($sp)
/*  f0f2d84:	8d6c0010 */ 	lw	$t4,0x10($t3)
/*  f0f2d88:	318d0002 */ 	andi	$t5,$t4,0x2
/*  f0f2d8c:	51a0002f */ 	beqzl	$t5,.NB0f0f2e4c
/*  f0f2d90:	90ed003c */ 	lbu	$t5,0x3c($a3)
/*  f0f2d94:	55c0002d */ 	bnezl	$t6,.NB0f0f2e4c
/*  f0f2d98:	90ed003c */ 	lbu	$t5,0x3c($a3)
/*  f0f2d9c:	8c790d4c */ 	lw	$t9,0xd4c($v1)
/*  f0f2da0:	3c0bb700 */ 	lui	$t3,0xb700
/*  f0f2da4:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f2da8:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0f2dac:	05e00026 */ 	bltz	$t7,.NB0f0f2e48
/*  f0f2db0:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0f2db4:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0f2db8:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0f2dbc:	8dad3af0 */ 	lw	$t5,0x3af0($t5)
/*  f0f2dc0:	3c18800a */ 	lui	$t8,0x800a
/*  f0f2dc4:	271827c0 */ 	addiu	$t8,$t8,0x27c0
/*  f0f2dc8:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f0f2dcc:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f2dd0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f2dd4:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f2dd8:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f2ddc:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f2de0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f2de4:	25d9079c */ 	addiu	$t9,$t6,0x79c
/*  f0f2de8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f2dec:	03382821 */ 	addu	$a1,$t9,$t8
/*  f0f2df0:	0fc3c0fd */ 	jal	menuRenderModels
/*  f0f2df4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f2df8:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f0f2dfc:	afaf01e8 */ 	sw	$t7,0x1e8($sp)
/*  f0f2e00:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0f2e04:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f2e08:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0f2e0c:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0f2e10:	3c10800a */ 	lui	$s0,0x800a
/*  f0f2e14:	8e10e944 */ 	lw	$s0,-0x16bc($s0)
/*  f0f2e18:	86040634 */ 	lh	$a0,0x634($s0)
/*  f0f2e1c:	0c002f9f */ 	jal	viSetViewPosition
/*  f0f2e20:	86050636 */ 	lh	$a1,0x636($s0)
/*  f0f2e24:	3c10800a */ 	lui	$s0,0x800a
/*  f0f2e28:	8e10e944 */ 	lw	$s0,-0x16bc($s0)
/*  f0f2e2c:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f0f2e30:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f0f2e34:	86060630 */ 	lh	$a2,0x630($s0)
/*  f0f2e38:	0c002feb */ 	jal	viSetFovAspectAndSize
/*  f0f2e3c:	86070632 */ 	lh	$a3,0x632($s0)
/*  f0f2e40:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f2e44:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.NB0f0f2e48:
/*  f0f2e48:	90ed003c */ 	lbu	$t5,0x3c($a3)
.NB0f0f2e4c:
/*  f0f2e4c:	55a00008 */ 	bnezl	$t5,.NB0f0f2e70
/*  f0f2e50:	8fae01e0 */ 	lw	$t6,0x1e0($sp)
/*  f0f2e54:	c4e40040 */ 	lwc1	$f4,0x40($a3)
/*  f0f2e58:	00809825 */ 	or	$s3,$a0,$zero
/*  f0f2e5c:	4604a03e */ 	c.le.s	$f20,$f4
/*  f0f2e60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f2e64:	45020281 */ 	bc1fl	.NB0f0f386c
/*  f0f2e68:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f2e6c:	8fae01e0 */ 	lw	$t6,0x1e0($sp)
.NB0f0f2e70:
/*  f0f2e70:	afa00130 */ 	sw	$zero,0x130($sp)
/*  f0f2e74:	afa001e4 */ 	sw	$zero,0x1e4($sp)
/*  f0f2e78:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f2e7c:	afae0194 */ 	sw	$t6,0x194($sp)
/*  f0f2e80:	90f90005 */ 	lbu	$t9,0x5($a3)
/*  f0f2e84:	5b2001d6 */ 	blezl	$t9,.NB0f0f35e0
/*  f0f2e88:	8fae01f4 */ 	lw	$t6,0x1f4($sp)
/*  f0f2e8c:	afa401e8 */ 	sw	$a0,0x1e8($sp)
.NB0f0f2e90:
/*  f0f2e90:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f2e94:	8fb801dc */ 	lw	$t8,0x1dc($sp)
/*  f0f2e98:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0f2e9c:	8c4f0064 */ 	lw	$t7,0x64($v0)
/*  f0f2ea0:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0f2ea4:	030f5821 */ 	addu	$t3,$t8,$t7
/*  f0f2ea8:	256c000c */ 	addiu	$t4,$t3,0xc
/*  f0f2eac:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0f2eb0:	904d003c */ 	lbu	$t5,0x3c($v0)
/*  f0f2eb4:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0f2eb8:	c4460040 */ 	lwc1	$f6,0x40($v0)
/*  f0f2ebc:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0f2ec0:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f2ec4:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0f2ec8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f2ecc:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f0f2ed0:	8ca5c2f8 */ 	lw	$a1,-0x3d08($a1)
/*  f0f2ed4:	45020005 */ 	bc1fl	.NB0f0f2eec
/*  f0f2ed8:	9059003d */ 	lbu	$t9,0x3d($v0)
/*  f0f2edc:	afa50120 */ 	sw	$a1,0x120($sp)
/*  f0f2ee0:	1000000d */ 	beqz	$zero,.NB0f0f2f18
/*  f0f2ee4:	90430004 */ 	lbu	$v1,0x4($v0)
/*  f0f2ee8:	9059003d */ 	lbu	$t9,0x3d($v0)
.NB0f0f2eec:
/*  f0f2eec:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f2ef0:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f2ef4:	0019c100 */ 	sll	$t8,$t9,0x4
/*  f0f2ef8:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0f2efc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f2f00:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0f2f04:	0fc01990 */ 	jal	colourBlend
/*  f0f2f08:	8c84c2f8 */ 	lw	$a0,-0x3d08($a0)
/*  f0f2f0c:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0f2f10:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f2f14:	90430004 */ 	lbu	$v1,0x4($v0)
.NB0f0f2f18:
/*  f0f2f18:	8fab0120 */ 	lw	$t3,0x120($sp)
/*  f0f2f1c:	8fae01e4 */ 	lw	$t6,0x1e4($sp)
/*  f0f2f20:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f2f24:	01616024 */ 	and	$t4,$t3,$at
/*  f0f2f28:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0f2f2c:	afad0120 */ 	sw	$t5,0x120($sp)
/*  f0f2f30:	11c00010 */ 	beqz	$t6,.NB0f0f2f74
/*  f0f2f34:	006e8021 */ 	addu	$s0,$v1,$t6
/*  f0f2f38:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0f2f3c:	8fa70194 */ 	lw	$a3,0x194($sp)
/*  f0f2f40:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f2f44:	8f380010 */ 	lw	$t8,0x10($t9)
/*  f0f2f48:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f2f4c:	24e5ffff */ 	addiu	$a1,$a3,-1
/*  f0f2f50:	330f0400 */ 	andi	$t7,$t8,0x400
/*  f0f2f54:	15e00007 */ 	bnez	$t7,.NB0f0f2f74
/*  f0f2f58:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f0f2f5c:	8fab01d4 */ 	lw	$t3,0x1d4($sp)
/*  f0f2f60:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0f2f64:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f2f68:	0fc380fc */ 	jal	gfxDrawFilledRect
/*  f0f2f6c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f2f70:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.NB0f0f2f74:
/*  f0f2f74:	8fac01f0 */ 	lw	$t4,0x1f0($sp)
/*  f0f2f78:	00107080 */ 	sll	$t6,$s0,0x2
/*  f0f2f7c:	01d07021 */ 	addu	$t6,$t6,$s0
/*  f0f2f80:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f0f2f84:	018e3021 */ 	addu	$a2,$t4,$t6
/*  f0f2f88:	84c505d0 */ 	lh	$a1,0x5d0($a2)
/*  f0f2f8c:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f0f2f90:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f2f94:	8fad01e4 */ 	lw	$t5,0x1e4($sp)
/*  f0f2f98:	0325c021 */ 	addu	$t8,$t9,$a1
/*  f0f2f9c:	afb80130 */ 	sw	$t8,0x130($sp)
/*  f0f2fa0:	91e30005 */ 	lbu	$v1,0x5($t7)
/*  f0f2fa4:	25ab0001 */ 	addiu	$t3,$t5,0x1
/*  f0f2fa8:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f0f2fac:	15630008 */ 	bne	$t3,$v1,.NB0f0f2fd0
/*  f0f2fb0:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0f2fb4:	8fae01e0 */ 	lw	$t6,0x1e0($sp)
/*  f0f2fb8:	018e1023 */ 	subu	$v0,$t4,$t6
/*  f0f2fbc:	2442fffe */ 	addiu	$v0,$v0,-2
/*  f0f2fc0:	0302082a */ 	slt	$at,$t8,$v0
/*  f0f2fc4:	10200002 */ 	beqz	$at,.NB0f0f2fd0
/*  f0f2fc8:	0082c821 */ 	addu	$t9,$a0,$v0
/*  f0f2fcc:	03382023 */ 	subu	$a0,$t9,$t8
.NB0f0f2fd0:
/*  f0f2fd0:	90cf05d8 */ 	lbu	$t7,0x5d8($a2)
/*  f0f2fd4:	8fad01dc */ 	lw	$t5,0x1dc($sp)
/*  f0f2fd8:	19e00178 */ 	blez	$t7,.NB0f0f35bc
/*  f0f2fdc:	25ab000c */ 	addiu	$t3,$t5,0xc
/*  f0f2fe0:	afab008c */ 	sw	$t3,0x8c($sp)
/*  f0f2fe4:	afa40124 */ 	sw	$a0,0x124($sp)
/*  f0f2fe8:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f0f2fec:	8fae0080 */ 	lw	$t6,0x80($sp)
.NB0f0f2ff0:
/*  f0f2ff0:	afa00114 */ 	sw	$zero,0x114($sp)
/*  f0f2ff4:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f0f2ff8:	95d905d6 */ 	lhu	$t9,0x5d6($t6)
/*  f0f2ffc:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f0f3000:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f3004:	03381821 */ 	addu	$v1,$t9,$t8
/*  f0f3008:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0f300c:	01ed1021 */ 	addu	$v0,$t7,$t5
/*  f0f3010:	904b048e */ 	lbu	$t3,0x48e($v0)
/*  f0f3014:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0f3018:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f301c:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0f3020:	8f380008 */ 	lw	$t8,0x8($t9)
/*  f0f3024:	01cb7021 */ 	addu	$t6,$t6,$t3
/*  f0f3028:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f302c:	01d83021 */ 	addu	$a2,$t6,$t8
/*  f0f3030:	afa60118 */ 	sw	$a2,0x118($sp)
/*  f0f3034:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f0f3038:	8d8f0008 */ 	lw	$t7,0x8($t4)
/*  f0f303c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f3040:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0f3044:	54cf0008 */ 	bnel	$a2,$t7,.NB0f0f3068
/*  f0f3048:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f304c:	afad0114 */ 	sw	$t5,0x114($sp)
/*  f0f3050:	8d8b000c */ 	lw	$t3,0xc($t4)
/*  f0f3054:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f0f3058:	51600003 */ 	beqzl	$t3,.NB0f0f3068
/*  f0f305c:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f3060:	afb90114 */ 	sw	$t9,0x114($sp)
/*  f0f3064:	8fae007c */ 	lw	$t6,0x7c($sp)
.NB0f0f3068:
/*  f0f3068:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f306c:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0f3070:	81c2048f */ 	lb	$v0,0x48f($t6)
/*  f0f3074:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f0f3078:	8fad0194 */ 	lw	$t5,0x194($sp)
/*  f0f307c:	10410003 */ 	beq	$v0,$at,.NB0f0f308c
/*  f0f3080:	00027880 */ 	sll	$t7,$v0,0x2
/*  f0f3084:	030f2821 */ 	addu	$a1,$t8,$t7
/*  f0f3088:	24a50638 */ 	addiu	$a1,$a1,0x638
.NB0f0f308c:
/*  f0f308c:	8fac0124 */ 	lw	$t4,0x124($sp)
/*  f0f3090:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f0f3094:	a7ad0198 */ 	sh	$t5,0x198($sp)
/*  f0f3098:	a7a3019a */ 	sh	$v1,0x19a($sp)
/*  f0f309c:	a7ac019c */ 	sh	$t4,0x19c($sp)
/*  f0f30a0:	8579048c */ 	lh	$t9,0x48c($t3)
/*  f0f30a4:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f0f30a8:	00031400 */ 	sll	$v0,$v1,0x10
/*  f0f30ac:	00027403 */ 	sra	$t6,$v0,0x10
/*  f0f30b0:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f0f30b4:	030f082a */ 	slt	$at,$t8,$t7
/*  f0f30b8:	01c01025 */ 	or	$v0,$t6,$zero
/*  f0f30bc:	10200002 */ 	beqz	$at,.NB0f0f30c8
/*  f0f30c0:	a7b9019e */ 	sh	$t9,0x19e($sp)
/*  f0f30c4:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f0f30c8:
/*  f0f30c8:	8fad01d4 */ 	lw	$t5,0x1d4($sp)
/*  f0f30cc:	87ac019e */ 	lh	$t4,0x19e($sp)
/*  f0f30d0:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f0f30d4:	01a2082a */ 	slt	$at,$t5,$v0
/*  f0f30d8:	10200002 */ 	beqz	$at,.NB0f0f30e4
/*  f0f30dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f30e0:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f0f30e4:
/*  f0f30e4:	15800002 */ 	bnez	$t4,.NB0f0f30f0
/*  f0f30e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f30ec:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f0f30f0:
/*  f0f30f0:	54800123 */ 	bnezl	$a0,.NB0f0f3580
/*  f0f30f4:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0f30f8:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f0f30fc:	8fae0114 */ 	lw	$t6,0x114($sp)
/*  f0f3100:	8fb901ec */ 	lw	$t9,0x1ec($sp)
/*  f0f3104:	afab01a0 */ 	sw	$t3,0x1a0($sp)
/*  f0f3108:	afa501ac */ 	sw	$a1,0x1ac($sp)
/*  f0f310c:	afae01a4 */ 	sw	$t6,0x1a4($sp)
/*  f0f3110:	1300000e */ 	beqz	$t8,.NB0f0f314c
/*  f0f3114:	afb901a8 */ 	sw	$t9,0x1a8($sp)
/*  f0f3118:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f311c:	87b00196 */ 	lh	$s0,0x196($sp)
/*  f0f3120:	87af0126 */ 	lh	$t7,0x126($sp)
/*  f0f3124:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3128:	2446ffff */ 	addiu	$a2,$v0,-1
/*  f0f312c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0f3130:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0f3134:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f3138:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f313c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f3140:	0fc380fc */ 	jal	gfxDrawFilledRect
/*  f0f3144:	020f3821 */ 	addu	$a3,$s0,$t7
/*  f0f3148:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.NB0f0f314c:
/*  f0f314c:	8fad0118 */ 	lw	$t5,0x118($sp)
/*  f0f3150:	8fae01f4 */ 	lw	$t6,0x1f4($sp)
/*  f0f3154:	8dac0004 */ 	lw	$t4,0x4($t5)
/*  f0f3158:	318b4000 */ 	andi	$t3,$t4,0x4000
/*  f0f315c:	51600046 */ 	beqzl	$t3,.NB0f0f3278
/*  f0f3160:	8fad0114 */ 	lw	$t5,0x114($sp)
/*  f0f3164:	15c00043 */ 	bnez	$t6,.NB0f0f3274
/*  f0f3168:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f316c:	c5880040 */ 	lwc1	$f8,0x40($t4)
/*  f0f3170:	87b00198 */ 	lh	$s0,0x198($sp)
/*  f0f3174:	87af019c */ 	lh	$t7,0x19c($sp)
/*  f0f3178:	4614403c */ 	c.lt.s	$f8,$f20
/*  f0f317c:	87b1019a */ 	lh	$s1,0x19a($sp)
/*  f0f3180:	87ad019e */ 	lh	$t5,0x19e($sp)
/*  f0f3184:	01f09021 */ 	addu	$s2,$t7,$s0
/*  f0f3188:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f318c:	45000009 */ 	bc1f	.NB0f0f31b4
/*  f0f3190:	01b19821 */ 	addu	$s3,$t5,$s1
/*  f0f3194:	918b003c */ 	lbu	$t3,0x3c($t4)
/*  f0f3198:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0f319c:	000b7100 */ 	sll	$t6,$t3,0x4
/*  f0f31a0:	01cb7023 */ 	subu	$t6,$t6,$t3
/*  f0f31a4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f31a8:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f0f31ac:	10000011 */ 	beqz	$zero,.NB0f0f31f4
/*  f0f31b0:	8c84c308 */ 	lw	$a0,-0x3cf8($a0)
.NB0f0f31b4:
/*  f0f31b4:	91f9003d */ 	lbu	$t9,0x3d($t7)
/*  f0f31b8:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0f31bc:	91ec003c */ 	lbu	$t4,0x3c($t7)
/*  f0f31c0:	03220019 */ 	multu	$t9,$v0
/*  f0f31c4:	3c037f1b */ 	lui	$v1,0x7f1b
/*  f0f31c8:	2463c2e0 */ 	addiu	$v1,$v1,-15648
/*  f0f31cc:	8de60044 */ 	lw	$a2,0x44($t7)
/*  f0f31d0:	00006812 */ 	mflo	$t5
/*  f0f31d4:	006dc021 */ 	addu	$t8,$v1,$t5
/*  f0f31d8:	8f040028 */ 	lw	$a0,0x28($t8)
/*  f0f31dc:	01820019 */ 	multu	$t4,$v0
/*  f0f31e0:	00005812 */ 	mflo	$t3
/*  f0f31e4:	006b7021 */ 	addu	$t6,$v1,$t3
/*  f0f31e8:	0fc01990 */ 	jal	colourBlend
/*  f0f31ec:	8dc50028 */ 	lw	$a1,0x28($t6)
/*  f0f31f0:	00402025 */ 	or	$a0,$v0,$zero
.NB0f0f31f4:
/*  f0f31f4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f31f8:	00812824 */ 	and	$a1,$a0,$at
/*  f0f31fc:	0fc01990 */ 	jal	colourBlend
/*  f0f3200:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0f3204:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3208:	0fc537b7 */ 	jal	gfxSetPrimColour
/*  f0f320c:	00402825 */ 	or	$a1,$v0,$zero
/*  f0f3210:	3c038008 */ 	lui	$v1,0x8008
/*  f0f3214:	24632320 */ 	addiu	$v1,$v1,0x2320
/*  f0f3218:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f321c:	3c01f600 */ 	lui	$at,0xf600
/*  f0f3220:	326e03ff */ 	andi	$t6,$s3,0x3ff
/*  f0f3224:	02590019 */ 	multu	$s2,$t9
/*  f0f3228:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f322c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f3230:	00006812 */ 	mflo	$t5
/*  f0f3234:	31b803ff */ 	andi	$t8,$t5,0x3ff
/*  f0f3238:	00186380 */ 	sll	$t4,$t8,0xe
/*  f0f323c:	01815825 */ 	or	$t3,$t4,$at
/*  f0f3240:	016fc825 */ 	or	$t9,$t3,$t7
/*  f0f3244:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0f3248:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f324c:	322b03ff */ 	andi	$t3,$s1,0x3ff
/*  f0f3250:	000b7880 */ 	sll	$t7,$t3,0x2
/*  f0f3254:	020d0019 */ 	multu	$s0,$t5
/*  f0f3258:	0000c012 */ 	mflo	$t8
/*  f0f325c:	330c03ff */ 	andi	$t4,$t8,0x3ff
/*  f0f3260:	000c7380 */ 	sll	$t6,$t4,0xe
/*  f0f3264:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f0f3268:	0fc537ce */ 	jal	func0f153838
/*  f0f326c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0f3270:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.NB0f0f3274:
/*  f0f3274:	8fad0114 */ 	lw	$t5,0x114($sp)
.NB0f0f3278:
/*  f0f3278:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f0f327c:	51a000b0 */ 	beqzl	$t5,.NB0f0f3540
/*  f0f3280:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3284:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f0f3288:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f328c:	1041000b */ 	beq	$v0,$at,.NB0f0f32bc
/*  f0f3290:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f3294:	10410009 */ 	beq	$v0,$at,.NB0f0f32bc
/*  f0f3298:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0f329c:	10410007 */ 	beq	$v0,$at,.NB0f0f32bc
/*  f0f32a0:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f32a4:	10410005 */ 	beq	$v0,$at,.NB0f0f32bc
/*  f0f32a8:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f32ac:	10410003 */ 	beq	$v0,$at,.NB0f0f32bc
/*  f0f32b0:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f32b4:	54410006 */ 	bnel	$v0,$at,.NB0f0f32d0
/*  f0f32b8:	24010004 */ 	addiu	$at,$zero,0x4
.NB0f0f32bc:
/*  f0f32bc:	0fc541a0 */ 	jal	func0f156024
/*  f0f32c0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f32c4:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0f32c8:	91820000 */ 	lbu	$v0,0x0($t4)
/*  f0f32cc:	24010004 */ 	addiu	$at,$zero,0x4
.NB0f0f32d0:
/*  f0f32d0:	10410008 */ 	beq	$v0,$at,.NB0f0f32f4
/*  f0f32d4:	87a3019c */ 	lh	$v1,0x19c($sp)
/*  f0f32d8:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0f32dc:	10410005 */ 	beq	$v0,$at,.NB0f0f32f4
/*  f0f32e0:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f32e4:	10410003 */ 	beq	$v0,$at,.NB0f0f32f4
/*  f0f32e8:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f32ec:	54410094 */ 	bnel	$v0,$at,.NB0f0f3540
/*  f0f32f0:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.NB0f0f32f4:
/*  f0f32f4:	87ae019e */ 	lh	$t6,0x19e($sp)
/*  f0f32f8:	8fb70120 */ 	lw	$s7,0x120($sp)
/*  f0f32fc:	87a20198 */ 	lh	$v0,0x198($sp)
/*  f0f3300:	87ab019a */ 	lh	$t3,0x19a($sp)
/*  f0f3304:	05c10003 */ 	bgez	$t6,.NB0f0f3314
/*  f0f3308:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f0f330c:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0f3310:	00017843 */ 	sra	$t7,$at,0x1
.NB0f0f3314:
/*  f0f3314:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f3318:	0061001a */ 	div	$zero,$v1,$at
/*  f0f331c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f3320:	02e16824 */ 	and	$t5,$s7,$at
/*  f0f3324:	0000c812 */ 	mflo	$t9
/*  f0f3328:	35b8002f */ 	ori	$t8,$t5,0x2f
/*  f0f332c:	016f8021 */ 	addu	$s0,$t3,$t7
/*  f0f3330:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0f3334:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f0f3338:	01a0b825 */ 	or	$s7,$t5,$zero
/*  f0f333c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3340:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0f3344:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f0f3348:	0fc37e4b */ 	jal	func0f0e2498
/*  f0f334c:	0059f021 */ 	addu	$s8,$v0,$t9
/*  f0f3350:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f3354:	2615ffff */ 	addiu	$s5,$s0,-1
/*  f0f3358:	2632fffd */ 	addiu	$s2,$s1,-3
/*  f0f335c:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f3360:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f3364:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3368:	02802825 */ 	or	$a1,$s4,$zero
/*  f0f336c:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f3370:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f3374:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f3378:	0fc37e88 */ 	jal	gfxDrawTri2
/*  f0f337c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f3380:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f0f3384:	240effff */ 	addiu	$t6,$zero,-1
/*  f0f3388:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0f338c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3390:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f3394:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f3398:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f339c:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f33a0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f33a4:	0fc37e88 */ 	jal	gfxDrawTri2
/*  f0f33a8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f33ac:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f33b0:	26130001 */ 	addiu	$s3,$s0,0x1
/*  f0f33b4:	26160002 */ 	addiu	$s6,$s0,0x2
/*  f0f33b8:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f33bc:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f33c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f33c4:	02802825 */ 	or	$a1,$s4,$zero
/*  f0f33c8:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f33cc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f33d0:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f33d4:	0fc37e88 */ 	jal	gfxDrawTri2
/*  f0f33d8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f33dc:	8fab0120 */ 	lw	$t3,0x120($sp)
/*  f0f33e0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0f33e4:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0f33e8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f33ec:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f33f0:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f33f4:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f33f8:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f33fc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f3400:	0fc37e88 */ 	jal	gfxDrawTri2
/*  f0f3404:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f3408:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f0f340c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3410:	2625fffe */ 	addiu	$a1,$s1,-2
/*  f0f3414:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f3418:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0f341c:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f3420:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f0f3424:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f3428:	0fc37e88 */ 	jal	gfxDrawTri2
/*  f0f342c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f3430:	8fad0118 */ 	lw	$t5,0x118($sp)
/*  f0f3434:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f3438:	87a20198 */ 	lh	$v0,0x198($sp)
/*  f0f343c:	8db80004 */ 	lw	$t8,0x4($t5)
/*  f0f3440:	87a3019c */ 	lh	$v1,0x19c($sp)
/*  f0f3444:	8fa80120 */ 	lw	$t0,0x120($sp)
/*  f0f3448:	330c0020 */ 	andi	$t4,$t8,0x20
/*  f0f344c:	1180003b */ 	beqz	$t4,.NB0f0f353c
/*  f0f3450:	00433821 */ 	addu	$a3,$v0,$v1
/*  f0f3454:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f3458:	0061001a */ 	div	$zero,$v1,$at
/*  f0f345c:	00007012 */ 	mflo	$t6
/*  f0f3460:	00e0a025 */ 	or	$s4,$a3,$zero
/*  f0f3464:	24f1fff8 */ 	addiu	$s1,$a3,-8
/*  f0f3468:	00eef023 */ 	subu	$s8,$a3,$t6
/*  f0f346c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3470:	24e5fffb */ 	addiu	$a1,$a3,-5
/*  f0f3474:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f3478:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f347c:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0f3480:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0f3484:	0fc37e88 */ 	jal	gfxDrawTri2
/*  f0f3488:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f348c:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f0f3490:	26320003 */ 	addiu	$s2,$s1,0x3
/*  f0f3494:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0f3498:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f349c:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f34a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f34a4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f34a8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f34ac:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f34b0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f34b4:	0fc37e88 */ 	jal	gfxDrawTri2
/*  f0f34b8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0f34bc:	8fb90120 */ 	lw	$t9,0x120($sp)
/*  f0f34c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f34c4:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f34c8:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f34cc:	02803825 */ 	or	$a3,$s4,$zero
/*  f0f34d0:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f34d4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f34d8:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f34dc:	0fc37e88 */ 	jal	gfxDrawTri2
/*  f0f34e0:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f34e4:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f0f34e8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0f34ec:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0f34f0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f34f4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f34f8:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f34fc:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f3500:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f3504:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f3508:	0fc37e88 */ 	jal	gfxDrawTri2
/*  f0f350c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f3510:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0f3514:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3518:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0f351c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f3520:	26270002 */ 	addiu	$a3,$s1,0x2
/*  f0f3524:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f3528:	afb70014 */ 	sw	$s7,0x14($sp)
/*  f0f352c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f3530:	0fc37e88 */ 	jal	gfxDrawTri2
/*  f0f3534:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0f3538:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.NB0f0f353c:
/*  f0f353c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.NB0f0f3540:
/*  f0f3540:	0fc3b4b3 */ 	jal	menuitemRender
/*  f0f3544:	27a50198 */ 	addiu	$a1,$sp,0x198
/*  f0f3548:	8fae0118 */ 	lw	$t6,0x118($sp)
/*  f0f354c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f3550:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f3554:	91cb0000 */ 	lbu	$t3,0x0($t6)
/*  f0f3558:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f355c:	55610003 */ 	bnel	$t3,$at,.NB0f0f356c
/*  f0f3560:	8fb90114 */ 	lw	$t9,0x114($sp)
/*  f0f3564:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f0f3568:	8fb90114 */ 	lw	$t9,0x114($sp)
.NB0f0f356c:
/*  f0f356c:	53200004 */ 	beqzl	$t9,.NB0f0f3580
/*  f0f3570:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0f3574:	0fc541a0 */ 	jal	func0f156024
/*  f0f3578:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f357c:	8fb8007c */ 	lw	$t8,0x7c($sp)
.NB0f0f3580:
/*  f0f3580:	8fa201c0 */ 	lw	$v0,0x1c0($sp)
/*  f0f3584:	8fad012c */ 	lw	$t5,0x12c($sp)
/*  f0f3588:	870c048c */ 	lh	$t4,0x48c($t8)
/*  f0f358c:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0f3590:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f3594:	01ac7021 */ 	addu	$t6,$t5,$t4
/*  f0f3598:	afa201c0 */ 	sw	$v0,0x1c0($sp)
/*  f0f359c:	afae012c */ 	sw	$t6,0x12c($sp)
/*  f0f35a0:	908b05d8 */ 	lbu	$t3,0x5d8($a0)
/*  f0f35a4:	004b082a */ 	slt	$at,$v0,$t3
/*  f0f35a8:	5420fe91 */ 	bnezl	$at,.NB0f0f2ff0
/*  f0f35ac:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f0f35b0:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f35b4:	848505d0 */ 	lh	$a1,0x5d0($a0)
/*  f0f35b8:	91e30005 */ 	lbu	$v1,0x5($t7)
.NB0f0f35bc:
/*  f0f35bc:	8fad01e4 */ 	lw	$t5,0x1e4($sp)
/*  f0f35c0:	8fb90194 */ 	lw	$t9,0x194($sp)
/*  f0f35c4:	25ac0001 */ 	addiu	$t4,$t5,0x1
/*  f0f35c8:	0183082a */ 	slt	$at,$t4,$v1
/*  f0f35cc:	0325c021 */ 	addu	$t8,$t9,$a1
/*  f0f35d0:	afac01e4 */ 	sw	$t4,0x1e4($sp)
/*  f0f35d4:	1420fe2e */ 	bnez	$at,.NB0f0f2e90
/*  f0f35d8:	afb80194 */ 	sw	$t8,0x194($sp)
/*  f0f35dc:	8fae01f4 */ 	lw	$t6,0x1f4($sp)
.NB0f0f35e0:
/*  f0f35e0:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f35e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f35e8:	15c00061 */ 	bnez	$t6,.NB0f0f3770
/*  f0f35ec:	8fab01e0 */ 	lw	$t3,0x1e0($sp)
/*  f0f35f0:	afab0194 */ 	sw	$t3,0x194($sp)
/*  f0f35f4:	0fc537b7 */ 	jal	gfxSetPrimColour
/*  f0f35f8:	afa001e4 */ 	sw	$zero,0x1e4($sp)
/*  f0f35fc:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f3600:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f3604:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0f3608:	91e30005 */ 	lbu	$v1,0x5($t7)
/*  f0f360c:	2738000c */ 	addiu	$t8,$t9,0xc
/*  f0f3610:	18600053 */ 	blez	$v1,.NB0f0f3760
/*  f0f3614:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3618:	afb8008c */ 	sw	$t8,0x8c($sp)
.NB0f0f361c:
/*  f0f361c:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f3620:	8fae01e4 */ 	lw	$t6,0x1e4($sp)
/*  f0f3624:	8fab01f0 */ 	lw	$t3,0x1f0($sp)
/*  f0f3628:	91ac0004 */ 	lbu	$t4,0x4($t5)
/*  f0f362c:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0f3630:	8fb1008c */ 	lw	$s1,0x8c($sp)
/*  f0f3634:	018e8021 */ 	addu	$s0,$t4,$t6
/*  f0f3638:	00107880 */ 	sll	$t7,$s0,0x2
/*  f0f363c:	01f07821 */ 	addu	$t7,$t7,$s0
/*  f0f3640:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f0f3644:	016fc821 */ 	addu	$t9,$t3,$t7
/*  f0f3648:	afb90080 */ 	sw	$t9,0x80($sp)
/*  f0f364c:	933805d8 */ 	lbu	$t8,0x5d8($t9)
/*  f0f3650:	87b00196 */ 	lh	$s0,0x196($sp)
/*  f0f3654:	5b000039 */ 	blezl	$t8,.NB0f0f373c
/*  f0f3658:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f0f365c:	8fad0080 */ 	lw	$t5,0x80($sp)
.NB0f0f3660:
/*  f0f3660:	8fae01c0 */ 	lw	$t6,0x1c0($sp)
/*  f0f3664:	8fab01f0 */ 	lw	$t3,0x1f0($sp)
/*  f0f3668:	95ac05d6 */ 	lhu	$t4,0x5d6($t5)
/*  f0f366c:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f3670:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f3674:	018e1821 */ 	addu	$v1,$t4,$t6
/*  f0f3678:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0f367c:	016f2021 */ 	addu	$a0,$t3,$t7
/*  f0f3680:	9099048e */ 	lbu	$t9,0x48e($a0)
/*  f0f3684:	8dac0000 */ 	lw	$t4,0x0($t5)
/*  f0f3688:	8082048f */ 	lb	$v0,0x48f($a0)
/*  f0f368c:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f0f3690:	8d8e0008 */ 	lw	$t6,0x8($t4)
/*  f0f3694:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f0f3698:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f369c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f36a0:	afa4007c */ 	sw	$a0,0x7c($sp)
/*  f0f36a4:	10410005 */ 	beq	$v0,$at,.NB0f0f36bc
/*  f0f36a8:	030e4821 */ 	addu	$t1,$t8,$t6
/*  f0f36ac:	00027880 */ 	sll	$t7,$v0,0x2
/*  f0f36b0:	016f4021 */ 	addu	$t0,$t3,$t7
/*  f0f36b4:	25080638 */ 	addiu	$t0,$t0,0x638
/*  f0f36b8:	afa4007c */ 	sw	$a0,0x7c($sp)
.NB0f0f36bc:
/*  f0f36bc:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f0f36c0:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0f36c4:	8fab01ec */ 	lw	$t3,0x1ec($sp)
/*  f0f36c8:	858705d0 */ 	lh	$a3,0x5d0($t4)
/*  f0f36cc:	870e048c */ 	lh	$t6,0x48c($t8)
/*  f0f36d0:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f0f36d4:	00113400 */ 	sll	$a2,$s1,0x10
/*  f0f36d8:	00066c03 */ 	sra	$t5,$a2,0x10
/*  f0f36dc:	0005cc03 */ 	sra	$t9,$a1,0x10
/*  f0f36e0:	03202825 */ 	or	$a1,$t9,$zero
/*  f0f36e4:	01a03025 */ 	or	$a2,$t5,$zero
/*  f0f36e8:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0f36ec:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0f36f0:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f36f4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f36f8:	0fc3b592 */ 	jal	menuitemOverlay
/*  f0f36fc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f3700:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*  f0f3704:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f0f3708:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0f370c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f3710:	85f9048c */ 	lh	$t9,0x48c($t7)
/*  f0f3714:	25ac0001 */ 	addiu	$t4,$t5,0x1
/*  f0f3718:	afac01c0 */ 	sw	$t4,0x1c0($sp)
/*  f0f371c:	930e05d8 */ 	lbu	$t6,0x5d8($t8)
/*  f0f3720:	02398821 */ 	addu	$s1,$s1,$t9
/*  f0f3724:	018e082a */ 	slt	$at,$t4,$t6
/*  f0f3728:	5420ffcd */ 	bnezl	$at,.NB0f0f3660
/*  f0f372c:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f0f3730:	8fab01ec */ 	lw	$t3,0x1ec($sp)
/*  f0f3734:	91630005 */ 	lbu	$v1,0x5($t3)
/*  f0f3738:	8fb90080 */ 	lw	$t9,0x80($sp)
.NB0f0f373c:
/*  f0f373c:	8fac01e4 */ 	lw	$t4,0x1e4($sp)
/*  f0f3740:	8faf0194 */ 	lw	$t7,0x194($sp)
/*  f0f3744:	872d05d0 */ 	lh	$t5,0x5d0($t9)
/*  f0f3748:	258e0001 */ 	addiu	$t6,$t4,0x1
/*  f0f374c:	01c3082a */ 	slt	$at,$t6,$v1
/*  f0f3750:	01edc021 */ 	addu	$t8,$t7,$t5
/*  f0f3754:	afae01e4 */ 	sw	$t6,0x1e4($sp)
/*  f0f3758:	1420ffb0 */ 	bnez	$at,.NB0f0f361c
/*  f0f375c:	afb80194 */ 	sw	$t8,0x194($sp)
.NB0f0f3760:
/*  f0f3760:	0fc537ce */ 	jal	func0f153838
/*  f0f3764:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3768:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f376c:	00402025 */ 	or	$a0,$v0,$zero
.NB0f0f3770:
/*  f0f3770:	00809825 */ 	or	$s3,$a0,$zero
/*  f0f3774:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f3778:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0f377c:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f3780:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f3784:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0f3788:	0c002fb9 */ 	jal	viGetViewTop
/*  f0f378c:	01608025 */ 	or	$s0,$t3,$zero
/*  f0f3790:	44825000 */ 	mtc1	$v0,$f10
/*  f0f3794:	44903000 */ 	mtc1	$s0,$f6
/*  f0f3798:	3c014080 */ 	lui	$at,0x4080
/*  f0f379c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0f37a0:	44810000 */ 	mtc1	$at,$f0
/*  f0f37a4:	3c01ed00 */ 	lui	$at,0xed00
/*  f0f37a8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f37ac:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0f37b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f37b4:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f37b8:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f37bc:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f37c0:	440f2000 */ 	mfc1	$t7,$f4
/*  f0f37c4:	440e8000 */ 	mfc1	$t6,$f16
/*  f0f37c8:	31ed0fff */ 	andi	$t5,$t7,0xfff
/*  f0f37cc:	01a1c025 */ 	or	$t8,$t5,$at
/*  f0f37d0:	31cb0fff */ 	andi	$t3,$t6,0xfff
/*  f0f37d4:	000bcb00 */ 	sll	$t9,$t3,0xc
/*  f0f37d8:	03197825 */ 	or	$t7,$t8,$t9
/*  f0f37dc:	0c002f97 */ 	jal	viGetViewWidth
/*  f0f37e0:	ae6f0000 */ 	sw	$t7,0x0($s3)
/*  f0f37e4:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f37e8:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f0f37ec:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0f37f0:	01a08825 */ 	or	$s1,$t5,$zero
/*  f0f37f4:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0f37f8:	00126403 */ 	sra	$t4,$s2,0x10
/*  f0f37fc:	0c002fb9 */ 	jal	viGetViewTop
/*  f0f3800:	01809025 */ 	or	$s2,$t4,$zero
/*  f0f3804:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f3808:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f380c:	0c002f9b */ 	jal	viGetViewHeight
/*  f0f3810:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f3814:	00505821 */ 	addu	$t3,$v0,$s0
/*  f0f3818:	448b9000 */ 	mtc1	$t3,$f18
/*  f0f381c:	02516821 */ 	addu	$t5,$s2,$s1
/*  f0f3820:	448d5000 */ 	mtc1	$t5,$f10
/*  f0f3824:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f3828:	3c014080 */ 	lui	$at,0x4080
/*  f0f382c:	44810000 */ 	mtc1	$at,$f0
/*  f0f3830:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0f3834:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0f3838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f383c:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0f3840:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f3844:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f3848:	44194000 */ 	mfc1	$t9,$f8
/*  f0f384c:	440e2000 */ 	mfc1	$t6,$f4
/*  f0f3850:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0f3854:	31cb0fff */ 	andi	$t3,$t6,0xfff
/*  f0f3858:	000bc300 */ 	sll	$t8,$t3,0xc
/*  f0f385c:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f0f3860:	1000003e */ 	beqz	$zero,.NB0f0f395c
/*  f0f3864:	ae790004 */ 	sw	$t9,0x4($s3)
/*  f0f3868:	24840008 */ 	addiu	$a0,$a0,0x8
.NB0f0f386c:
/*  f0f386c:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0f3870:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f3874:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f3878:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0f387c:	0c002fb9 */ 	jal	viGetViewTop
/*  f0f3880:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0f3884:	44823000 */ 	mtc1	$v0,$f6
/*  f0f3888:	44909000 */ 	mtc1	$s0,$f18
/*  f0f388c:	3c014080 */ 	lui	$at,0x4080
/*  f0f3890:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f3894:	44810000 */ 	mtc1	$at,$f0
/*  f0f3898:	3c01ed00 */ 	lui	$at,0xed00
/*  f0f389c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f38a0:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f38a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f38a8:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0f38ac:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f38b0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f38b4:	440e8000 */ 	mfc1	$t6,$f16
/*  f0f38b8:	44194000 */ 	mfc1	$t9,$f8
/*  f0f38bc:	31cb0fff */ 	andi	$t3,$t6,0xfff
/*  f0f38c0:	01617825 */ 	or	$t7,$t3,$at
/*  f0f38c4:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f0f38c8:	000d6300 */ 	sll	$t4,$t5,0xc
/*  f0f38cc:	01ec7025 */ 	or	$t6,$t7,$t4
/*  f0f38d0:	0c002f97 */ 	jal	viGetViewWidth
/*  f0f38d4:	ae6e0000 */ 	sw	$t6,0x0($s3)
/*  f0f38d8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f38dc:	00115c03 */ 	sra	$t3,$s1,0x10
/*  f0f38e0:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0f38e4:	01608825 */ 	or	$s1,$t3,$zero
/*  f0f38e8:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0f38ec:	0012c403 */ 	sra	$t8,$s2,0x10
/*  f0f38f0:	0c002fb9 */ 	jal	viGetViewTop
/*  f0f38f4:	03009025 */ 	or	$s2,$t8,$zero
/*  f0f38f8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f38fc:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0f3900:	0c002f9b */ 	jal	viGetViewHeight
/*  f0f3904:	03208025 */ 	or	$s0,$t9,$zero
/*  f0f3908:	00506821 */ 	addu	$t5,$v0,$s0
/*  f0f390c:	448d5000 */ 	mtc1	$t5,$f10
/*  f0f3910:	02515821 */ 	addu	$t3,$s2,$s1
/*  f0f3914:	448b4000 */ 	mtc1	$t3,$f8
/*  f0f3918:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0f391c:	3c014080 */ 	lui	$at,0x4080
/*  f0f3920:	44819000 */ 	mtc1	$at,$f18
/*  f0f3924:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0f3928:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0f392c:	44818000 */ 	mtc1	$at,$f16
/*  f0f3930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3934:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0f3938:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0f393c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f3940:	440c3000 */ 	mfc1	$t4,$f6
/*  f0f3944:	44192000 */ 	mfc1	$t9,$f4
/*  f0f3948:	318e0fff */ 	andi	$t6,$t4,0xfff
/*  f0f394c:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f0f3950:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f0f3954:	01cf6025 */ 	or	$t4,$t6,$t7
/*  f0f3958:	ae6c0004 */ 	sw	$t4,0x4($s3)
.NB0f0f395c:
/*  f0f395c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0f3960:	8d6b3af0 */ 	lw	$t3,0x3af0($t3)
/*  f0f3964:	3c19800a */ 	lui	$t9,0x800a
/*  f0f3968:	273927c0 */ 	addiu	$t9,$t9,0x27c0
/*  f0f396c:	000bc0c0 */ 	sll	$t8,$t3,0x3
/*  f0f3970:	030bc023 */ 	subu	$t8,$t8,$t3
/*  f0f3974:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f3978:	030bc023 */ 	subu	$t8,$t8,$t3
/*  f0f397c:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f3980:	030bc023 */ 	subu	$t8,$t8,$t3
/*  f0f3984:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f3988:	03191821 */ 	addu	$v1,$t8,$t9
/*  f0f398c:	846d0484 */ 	lh	$t5,0x484($v1)
/*  f0f3990:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f3994:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0f3998:	91ec003c */ 	lbu	$t4,0x3c($t7)
/*  f0f399c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f39a0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f39a4:	006e8821 */ 	addu	$s1,$v1,$t6
/*  f0f39a8:	15800006 */ 	bnez	$t4,.NB0f0f39c4
/*  f0f39ac:	263103dc */ 	addiu	$s1,$s1,0x3dc
/*  f0f39b0:	c5e60040 */ 	lwc1	$f6,0x40($t7)
/*  f0f39b4:	4606a03e */ 	c.le.s	$f20,$f6
/*  f0f39b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f39bc:	4502010b */ 	bc1fl	.NB0f0f3dec
/*  f0f39c0:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.NB0f0f39c4:
/*  f0f39c4:	82380015 */ 	lb	$t8,0x15($s1)
/*  f0f39c8:	8fab01ec */ 	lw	$t3,0x1ec($sp)
/*  f0f39cc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f39d0:	02396821 */ 	addu	$t5,$s1,$t9
/*  f0f39d4:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f0f39d8:	556e0104 */ 	bnel	$t3,$t6,.NB0f0f3dec
/*  f0f39dc:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f39e0:	822c0014 */ 	lb	$t4,0x14($s1)
/*  f0f39e4:	29810002 */ 	slti	$at,$t4,0x2
/*  f0f39e8:	142000ff */ 	bnez	$at,.NB0f0f3de8
/*  f0f39ec:	3c014120 */ 	lui	$at,0x4120
/*  f0f39f0:	44816000 */ 	mtc1	$at,$f12
/*  f0f39f4:	0fc019eb */ 	jal	func0f006b08
/*  f0f39f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f39fc:	3c01437f */ 	lui	$at,0x437f
/*  f0f3a00:	44814000 */ 	mtc1	$at,$f8
/*  f0f3a04:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0f3a08:	3c014f00 */ 	lui	$at,0x4f00
/*  f0f3a0c:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0f3a10:	8fb801ec */ 	lw	$t8,0x1ec($sp)
/*  f0f3a14:	8fab01ec */ 	lw	$t3,0x1ec($sp)
/*  f0f3a18:	444ff800 */ 	cfc1	$t7,$31
/*  f0f3a1c:	44d0f800 */ 	ctc1	$s0,$31
/*  f0f3a20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3a24:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0f3a28:	4450f800 */ 	cfc1	$s0,$31
/*  f0f3a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3a30:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0f3a34:	52000013 */ 	beqzl	$s0,.NB0f0f3a84
/*  f0f3a38:	44108000 */ 	mfc1	$s0,$f16
/*  f0f3a3c:	44818000 */ 	mtc1	$at,$f16
/*  f0f3a40:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0f3a44:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0f3a48:	44d0f800 */ 	ctc1	$s0,$31
/*  f0f3a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3a50:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0f3a54:	4450f800 */ 	cfc1	$s0,$31
/*  f0f3a58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3a5c:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0f3a60:	16000005 */ 	bnez	$s0,.NB0f0f3a78
/*  f0f3a64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3a68:	44108000 */ 	mfc1	$s0,$f16
/*  f0f3a6c:	3c018000 */ 	lui	$at,0x8000
/*  f0f3a70:	10000007 */ 	beqz	$zero,.NB0f0f3a90
/*  f0f3a74:	02018025 */ 	or	$s0,$s0,$at
.NB0f0f3a78:
/*  f0f3a78:	10000005 */ 	beqz	$zero,.NB0f0f3a90
/*  f0f3a7c:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f0f3a80:	44108000 */ 	mfc1	$s0,$f16
.NB0f0f3a84:
/*  f0f3a84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3a88:	0600fffb */ 	bltz	$s0,.NB0f0f3a78
/*  f0f3a8c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0f3a90:
/*  f0f3a90:	44cff800 */ 	ctc1	$t7,$31
/*  f0f3a94:	c7120040 */ 	lwc1	$f18,0x40($t8)
/*  f0f3a98:	4614903c */ 	c.lt.s	$f18,$f20
/*  f0f3a9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3aa0:	4502000a */ 	bc1fl	.NB0f0f3acc
/*  f0f3aa4:	916e003d */ 	lbu	$t6,0x3d($t3)
/*  f0f3aa8:	9319003c */ 	lbu	$t9,0x3c($t8)
/*  f0f3aac:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0f3ab0:	00196900 */ 	sll	$t5,$t9,0x4
/*  f0f3ab4:	01b96823 */ 	subu	$t5,$t5,$t9
/*  f0f3ab8:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f3abc:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f0f3ac0:	10000011 */ 	beqz	$zero,.NB0f0f3b08
/*  f0f3ac4:	8ca5c2e0 */ 	lw	$a1,-0x3d20($a1)
/*  f0f3ac8:	916e003d */ 	lbu	$t6,0x3d($t3)
.NB0f0f3acc:
/*  f0f3acc:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0f3ad0:	9178003c */ 	lbu	$t8,0x3c($t3)
/*  f0f3ad4:	01c20019 */ 	multu	$t6,$v0
/*  f0f3ad8:	3c037f1b */ 	lui	$v1,0x7f1b
/*  f0f3adc:	2463c2e0 */ 	addiu	$v1,$v1,-15648
/*  f0f3ae0:	8d660044 */ 	lw	$a2,0x44($t3)
/*  f0f3ae4:	00006012 */ 	mflo	$t4
/*  f0f3ae8:	006c7821 */ 	addu	$t7,$v1,$t4
/*  f0f3aec:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f0f3af0:	03020019 */ 	multu	$t8,$v0
/*  f0f3af4:	0000c812 */ 	mflo	$t9
/*  f0f3af8:	00796821 */ 	addu	$t5,$v1,$t9
/*  f0f3afc:	0fc01990 */ 	jal	colourBlend
/*  f0f3b00:	8da50000 */ 	lw	$a1,0x0($t5)
/*  f0f3b04:	00402825 */ 	or	$a1,$v0,$zero
.NB0f0f3b08:
/*  f0f3b08:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0f3b0c:	0fc01990 */ 	jal	colourBlend
/*  f0f3b10:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f3b14:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0f3b18:	4481a000 */ 	mtc1	$at,$f20
/*  f0f3b1c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f3b20:	0fc019eb */ 	jal	func0f006b08
/*  f0f3b24:	4600a306 */ 	mov.s	$f12,$f20
/*  f0f3b28:	8fae01dc */ 	lw	$t6,0x1dc($sp)
/*  f0f3b2c:	8fac01d4 */ 	lw	$t4,0x1d4($sp)
/*  f0f3b30:	8fa501e0 */ 	lw	$a1,0x1e0($sp)
/*  f0f3b34:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f3b38:	01cca821 */ 	addu	$s5,$t6,$t4
/*  f0f3b3c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0f3b40:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3b44:	24070009 */ 	addiu	$a3,$zero,0x9
/*  f0f3b48:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f3b4c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f3b50:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0f3b54:	24a5fffb */ 	addiu	$a1,$a1,-5
/*  f0f3b58:	06a10003 */ 	bgez	$s5,.NB0f0f3b68
/*  f0f3b5c:	0015a043 */ 	sra	$s4,$s5,0x1
/*  f0f3b60:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f0f3b64:	0001a043 */ 	sra	$s4,$at,0x1
.NB0f0f3b68:
/*  f0f3b68:	0fc381ee */ 	jal	func0f0e3324
/*  f0f3b6c:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f3b70:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f3b74:	0fc019eb */ 	jal	func0f006b08
/*  f0f3b78:	4600a306 */ 	mov.s	$f12,$f20
/*  f0f3b7c:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0f3b80:	24180003 */ 	addiu	$t8,$zero,0x3
/*  f0f3b84:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f3b88:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3b8c:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f3b90:	24070009 */ 	addiu	$a3,$zero,0x9
/*  f0f3b94:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f3b98:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f3b9c:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0f3ba0:	0fc381ee */ 	jal	func0f0e3324
/*  f0f3ba4:	24a50005 */ 	addiu	$a1,$a1,0x5
/*  f0f3ba8:	3c03800a */ 	lui	$v1,0x800a
/*  f0f3bac:	8c635eb4 */ 	lw	$v1,0x5eb4($v1)
/*  f0f3bb0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f3bb4:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f3bb8:	10610007 */ 	beq	$v1,$at,.NB0f0f3bd8
/*  f0f3bbc:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f3bc0:	10610005 */ 	beq	$v1,$at,.NB0f0f3bd8
/*  f0f3bc4:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f3bc8:	10610003 */ 	beq	$v1,$at,.NB0f0f3bd8
/*  f0f3bcc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f3bd0:	54610086 */ 	bnel	$v1,$at,.NB0f0f3dec
/*  f0f3bd4:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.NB0f0f3bd8:
/*  f0f3bd8:	0fc5392a */ 	jal	func0f153e4c
/*  f0f3bdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3be0:	0fc5362e */ 	jal	textSetRotation90
/*  f0f3be4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f3be8:	0fc5374a */ 	jal	func0f153628
/*  f0f3bec:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3bf0:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f3bf4:	82230015 */ 	lb	$v1,0x15($s1)
/*  f0f3bf8:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f3bfc:	04630004 */ 	bgezl	$v1,.NB0f0f3c10
/*  f0f3c00:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0f3c04:	82230014 */ 	lb	$v1,0x14($s1)
/*  f0f3c08:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f3c0c:	0003c880 */ 	sll	$t9,$v1,0x2
.NB0f0f3c10:
/*  f0f3c10:	02396821 */ 	addu	$t5,$s1,$t9
/*  f0f3c14:	8dab0000 */ 	lw	$t3,0x0($t5)
/*  f0f3c18:	0fc3b864 */ 	jal	menuResolveDialogTitle
/*  f0f3c1c:	8d640000 */ 	lw	$a0,0x0($t3)
/*  f0f3c20:	3c138008 */ 	lui	$s3,0x8008
/*  f0f3c24:	26732364 */ 	addiu	$s3,$s3,0x2364
/*  f0f3c28:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0f3c2c:	3c128008 */ 	lui	$s2,0x8008
/*  f0f3c30:	26522368 */ 	addiu	$s2,$s2,0x2368
/*  f0f3c34:	27b600b0 */ 	addiu	$s6,$sp,0xb0
/*  f0f3c38:	27b700ac */ 	addiu	$s7,$sp,0xac
/*  f0f3c3c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f3c40:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0f3c44:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0f3c48:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f0f3c4c:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f3c50:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f3c54:	0fc54655 */ 	jal	textMeasure
/*  f0f3c58:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f3c5c:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f0f3c60:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f3c64:	8fac01dc */ 	lw	$t4,0x1dc($sp)
/*  f0f3c68:	02822823 */ 	subu	$a1,$s4,$v0
/*  f0f3c6c:	24a5fffd */ 	addiu	$a1,$a1,-3
/*  f0f3c70:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f3c74:	00ac082a */ 	slt	$at,$a1,$t4
/*  f0f3c78:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f3c7c:	10200009 */ 	beqz	$at,.NB0f0f3ca4
/*  f0f3c80:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f3c84:	02a22823 */ 	subu	$a1,$s5,$v0
/*  f0f3c88:	04a10003 */ 	bgez	$a1,.NB0f0f3c98
/*  f0f3c8c:	00057843 */ 	sra	$t7,$a1,0x1
/*  f0f3c90:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0f3c94:	00017843 */ 	sra	$t7,$at,0x1
.NB0f0f3c98:
/*  f0f3c98:	2463fffd */ 	addiu	$v1,$v1,-3
/*  f0f3c9c:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f3ca0:	afaf01cc */ 	sw	$t7,0x1cc($sp)
.NB0f0f3ca4:
/*  f0f3ca4:	0c002f7b */ 	jal	viGetHeight
/*  f0f3ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3cac:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0f3cb0:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0f3cb4:	87ab01ca */ 	lh	$t3,0x1ca($sp)
/*  f0f3cb8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0f3cbc:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f3cc0:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3cc4:	27a501cc */ 	addiu	$a1,$sp,0x1cc
/*  f0f3cc8:	27a601d0 */ 	addiu	$a2,$sp,0x1d0
/*  f0f3ccc:	02003825 */ 	or	$a3,$s0,$zero
/*  f0f3cd0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f3cd4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f3cd8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f3cdc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f3ce0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f3ce4:	0fc541a6 */ 	jal	textRenderProjected
/*  f0f3ce8:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0f3cec:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f3cf0:	82230015 */ 	lb	$v1,0x15($s1)
/*  f0f3cf4:	822e0014 */ 	lb	$t6,0x14($s1)
/*  f0f3cf8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f3cfc:	006e082a */ 	slt	$at,$v1,$t6
/*  f0f3d00:	54200003 */ 	bnezl	$at,.NB0f0f3d10
/*  f0f3d04:	00036080 */ 	sll	$t4,$v1,0x2
/*  f0f3d08:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f3d0c:	00036080 */ 	sll	$t4,$v1,0x2
.NB0f0f3d10:
/*  f0f3d10:	022c7821 */ 	addu	$t7,$s1,$t4
/*  f0f3d14:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0f3d18:	0fc3b864 */ 	jal	menuResolveDialogTitle
/*  f0f3d1c:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f0f3d20:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0f3d24:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f3d28:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0f3d2c:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0f3d30:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f3d34:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f0f3d38:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f3d3c:	0fc54655 */ 	jal	textMeasure
/*  f0f3d40:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f3d44:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f0f3d48:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f0f3d4c:	8fad01d4 */ 	lw	$t5,0x1d4($sp)
/*  f0f3d50:	26850003 */ 	addiu	$a1,$s4,0x3
/*  f0f3d54:	00a25821 */ 	addu	$t3,$a1,$v0
/*  f0f3d58:	24630007 */ 	addiu	$v1,$v1,0x7
/*  f0f3d5c:	01ab082a */ 	slt	$at,$t5,$t3
/*  f0f3d60:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f3d64:	10200009 */ 	beqz	$at,.NB0f0f3d8c
/*  f0f3d68:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f3d6c:	02a22823 */ 	subu	$a1,$s5,$v0
/*  f0f3d70:	04a10003 */ 	bgez	$a1,.NB0f0f3d80
/*  f0f3d74:	00057043 */ 	sra	$t6,$a1,0x1
/*  f0f3d78:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0f3d7c:	00017043 */ 	sra	$t6,$at,0x1
.NB0f0f3d80:
/*  f0f3d80:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0f3d84:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f3d88:	afae01cc */ 	sw	$t6,0x1cc($sp)
.NB0f0f3d8c:
/*  f0f3d8c:	0c002f7b */ 	jal	viGetHeight
/*  f0f3d90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f3d94:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f0f3d98:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f0f3d9c:	87b901ca */ 	lh	$t9,0x1ca($sp)
/*  f0f3da0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f3da4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f3da8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f3dac:	27a501cc */ 	addiu	$a1,$sp,0x1cc
/*  f0f3db0:	27a601d0 */ 	addiu	$a2,$sp,0x1d0
/*  f0f3db4:	02003825 */ 	or	$a3,$s0,$zero
/*  f0f3db8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f3dbc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f3dc0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f3dc4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f3dc8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f3dcc:	0fc541a6 */ 	jal	textRenderProjected
/*  f0f3dd0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f3dd4:	0fc537a0 */ 	jal	func0f153780
/*  f0f3dd8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3ddc:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f3de0:	0fc5362e */ 	jal	textSetRotation90
/*  f0f3de4:	00002025 */ 	or	$a0,$zero,$zero
.NB0f0f3de8:
/*  f0f3de8:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.NB0f0f3dec:
/*  f0f3dec:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0f3df0:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0f3df4:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f0f3df8:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f0f3dfc:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f0f3e00:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f0f3e04:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f0f3e08:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f0f3e0c:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f0f3e10:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f0f3e14:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f0f3e18:	03e00008 */ 	jr	$ra
/*  f0f3e1c:	27bd01e8 */ 	addiu	$sp,$sp,0x1e8
);
#endif

const char var7f1b2658[] = "1\n";
const char var7f1b265c[] = "2\n";
const char var7f1b2660[] = "3\n";
const char var7f1b2664[] = "4\n";

u32 var800714c8 = (u32)&var7f1b2658;
u32 var800714cc = (u32)&var7f1b265c;
u32 var800714d0 = (u32)&var7f1b2660;
u32 var800714d4 = (u32)&var7f1b2664;

/**
 * Render a single menu dialog.
 *
 * The lightweight argument is always false. If set to true, a lighter-weight
 * variant of the dialog is rendered which has no borders, less background,
 * no overlays and no models such as inventory weapons.
 */
// Mismatch: Regalloc, and possibly some differences in compiler-managed stack
// usage.
//Gfx *dialogRender(Gfx *gdl, struct menudialog *dialog, struct menu *menu, bool lightweight)
//{
//	s32 i; // 1e4
//	s32 dialogleft; // 1e0
//	s32 dialogtop; // 1dc
//	s32 dialogright;
//	s32 dialogbottom; // 1d4
//	s32 x; // 1d0
//	s32 y; // 1cc
//	s16 dialogwidth; // 1ca
//	union menuitemdata *itemdata;
//	s32 j; // 1c0
//	u32 colour1; // 1bc
//	u32 colour2; // 1b8
//	u32 colour3; // 1b4
//	struct menurendercontext context; // 198
//	s32 curx; // 194
//	s32 bgx1;
//	s32 bgy1;
//	s32 bgx2;
//	s32 bgy2;
//	s16 dialogheight;
//	char *title;
//	u32 colour4;
//	u32 colour5;
//	f32 sp170;
//
//	bgx1 = dialog->x;
//	bgy1 = dialog->y;
//	bgx2 = dialog->x + dialog->width;
//	bgy2 = dialog->y + dialog->height;
//
//#if VERSION >= VERSION_NTSC_1_0
//	if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
//			&& menuGetRoot() == MENUROOT_MPENDSCREEN
//			&& !var8009dfc0) {
//		return gdl;
//	}
//#endif
//
//	// Colours are stored in an array of palette structures that's indexed by
//	// the dialog type. Usually this is a direct lookup, but if the dialog is
//	// transitioning between two types it has to blend the two colours together.
//	// This is done several times throughout the function, so a macro is used.
//#define GETCOLOUR(property) (dialog->transitionfrac < 0.0f \
//	? g_MenuColourPalettes[dialog->type].property \
//	: colourBlend(g_MenuColourPalettes[dialog->type2].property, g_MenuColourPalettes[dialog->type].property, dialog->colourweight))
//
//	colour1 = GETCOLOUR(unk28);
//
//	func0f156030(colour1);
//
//	var8007fb9c = 0;
//
//	if (g_Menus[g_MpPlayerNum].curdialog == dialog
//			&& (dialog->definition->flags & MENUDIALOGFLAG_0002)
//			&& !lightweight
//			&& g_Menus[g_MpPlayerNum].unk840.unk5b1_07 == 1) {
//		gSPSetGeometryMode(gdl++, G_ZBUFFER);
//		gdl = menuRenderModels(gdl, &g_Menus[g_MpPlayerNum].unk840, 2);
//		gSPClearGeometryMode(gdl++, G_ZBUFFER);
//	}
//
//	dialogwidth = dialog->width;
//	dialogheight = dialog->height;
//
//	if (dialog->state == MENUDIALOGSTATE_PREOPEN) {
//#if VERSION >= VERSION_NTSC_1_0
//		if (dialog->definition == &g_MpReadyMenuDialog) {
//			return gdl;
//		}
//#endif
//
//		sp170 = 1.0f - g_MenuData.unk010;
//
//#if VERSION >= VERSION_NTSC_1_0
//		if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) && menuGetRoot() == MENUROOT_MPENDSCREEN) {
//			sp170 = 1.0f - dialog->statefrac;
//		}
//#endif
//
//		sp170 = 1.0f - sp170 * sp170;
//		dialogheight *= sp170;
//		bgy2 = dialog->y + dialogheight;
//	}
//
//	dialogleft = dialog->x;
//	dialogtop = dialog->y;
//	dialogbottom = dialogtop + dialogheight;
//
//	title = menuResolveDialogTitle(dialog->definition);
//
//	colour1 = GETCOLOUR(unk00);
//	colour2 = GETCOLOUR(unk04);
//	colour3 = GETCOLOUR(unk08);
//
//	gSPClearGeometryMode(gdl++, G_ZBUFFER);
//
//	colour4 = colour1;
//	colour5 = colour3;
//
//	if ((colour4 & 0xff) > 0x3f) {
//		colour4 = (colour4 & 0xffffff00) | 0x3f;
//	}
//
//	if ((colour5 & 0xff) > 0x3f) {
//		colour5 = (colour5 & 0xffffff00) | 0x3f;
//	}
//
//	var8009de90 = -1000;
//	var8009de94 = 1000;
//
//	if (dialog->definition->flags & MENUDIALOGFLAG_DISABLETITLEBAR) {
//		bgy1 += 11;
//	}
//
//	// Render the walls/floor/ceiling coming from the projection source.
//	// Each surface is rendered a second time with the colours swapped.
//	// The order is top, right, bottom, left.
//	if (g_MenuData.root != MENUROOT_MPSETUP && (g_MenuData.root != MENUROOT_MPPAUSE || g_Vars.normmplayerisrunning)) {
//		var800a4634 = func0f0d4d0c(var800a4634, bgx1, bgy1, bgx2, bgy1, colour4, colour5, 0);
//		var800a4634 = func0f0d4d0c(var800a4634, bgx2, bgy1, bgx2, bgy2, colour5, colour4, 0);
//		var800a4634 = func0f0d4d0c(var800a4634, bgx2, bgy2, bgx1, bgy2, colour4, colour5, 0);
//		var800a4634 = func0f0d4d0c(var800a4634, bgx1, bgy2, bgx1, bgy1, colour5, colour4, 0);
//		var800a4634 = func0f0d4d0c(var800a4634, bgx1, bgy1, bgx2, bgy1, colour5, colour4, 1);
//		var800a4634 = func0f0d4d0c(var800a4634, bgx2, bgy1, bgx2, bgy2, colour4, colour5, 1);
//		var800a4634 = func0f0d4d0c(var800a4634, bgx2, bgy2, bgx1, bgy2, colour5, colour4, 1);
//		var800a4634 = func0f0d4d0c(var800a4634, bgx1, bgy2, bgx1, bgy1, colour4, colour5, 1);
//	}
//
//	// Render the title bar
//	if ((dialog->definition->flags & MENUDIALOGFLAG_DISABLETITLEBAR) == 0) {
//		if (((g_MenuData.root == MENUROOT_MPSETUP) || (g_MenuData.root == MENUROOT_4MBMAINMENU))
//				&& (g_MpSetup.options & MPOPTION_TEAMSENABLED)
//				&& g_Vars.mpsetupmenu != MPSETUPMENU_GENERAL) {
//			menuGetTeamTitlebarColours(&colour1, &colour2, &colour3);
//		}
//
//		gdl = menugfxRenderGradient(gdl, dialogleft - 2, dialogtop, dialogleft + dialogwidth + 2, dialogtop + 11, colour1, colour2, colour3);
//		gdl = func0f0e2aa4(gdl, dialogleft - 2, dialogtop, dialogleft + dialogwidth + 2, dialogtop + 1, (colour1 & 0xff) >> 1, 1, 40, 0);
//		gdl = func0f0e2aa4(gdl, dialogleft - 2, dialogtop + 10, dialogleft + dialogwidth + 2, dialogtop + 11, (colour1 & 0xff) >> 1, 0, 40, 1);
//
//		x = dialogleft + 2;
//		y = dialogtop + 2;
//
//		gdl = func0f153628(gdl);
//
//		context.unk18 = false;
//
//		if (lightweight) {
//			context.unk18 = true;
//		}
//
//		{
//			char *sp154[] = {
//				"1\n",
//				"2\n",
//				"3\n",
//				"4\n",
//			};
//
//			u32 stack;
//
//			colour1 = GETCOLOUR(unk0c);
//
//			func0f153e38(g_MenuColourPalettes3[dialog->type].unk0c, g_MenuColourPalettes2[dialog->type].unk0c);
//
//			// Title shadow
//			x = dialogleft + 3;
//			y = dialogtop + 3;
//
//			gdl = textRenderProjected(gdl, &x, &y, title, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour1 & 0xff, dialogwidth, viGetHeight(), 0, 0);
//
//			// Title proper
//			x = dialogleft + 2;
//			y = dialogtop + 2;
//
//			gdl = textRenderProjected(gdl, &x, &y, title, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour1, dialogwidth, viGetHeight(), 0, 0);
//
//			// In MP dialogs, render the player number in the top right
//			if (g_MenuData.root == MENUROOT_MPSETUP
//					|| g_MenuData.root == MENUROOT_MPPAUSE
//					|| g_MenuData.root == MENUROOT_MPENDSCREEN
//					|| g_MenuData.root == MENUROOT_4MBMAINMENU) {
//				x = dialogleft + dialogwidth - 9;
//				y = dialogtop + 2;
//
//				gdl = textRenderProjected(gdl, &x, &y, sp154[g_MpPlayerNum], g_CharsHandelGothicSm, g_FontHandelGothicSm, colour1, dialogwidth, viGetHeight(), 0, 0);
//			}
//		}
//
//		gdl = func0f153780(gdl);
//	}
//
//	// Configure things for the redraw effect
//	if (!(dialog->redrawtimer < 0.0f)) {
//		if (g_MenuData.root != MENUROOT_MPPAUSE) {
//			if (dialog->state >= MENUDIALOGSTATE_POPULATED) {
//				func0f153c20(dialog->x, dialog->y, dialog->redrawtimer, 1);
//			} else {
//				func0f153c20(dialog->x, dialog->y, dialog->redrawtimer, 0);
//			}
//
//			var8007fb9c = 1;
//		}
//	} else if (dialog->state == MENUDIALOGSTATE_POPULATED) {
//		func0f153d88(dialog->statefrac);
//	}
//
//	if (dialogbottom < dialogtop + 11) {
//		dialogbottom = dialogtop + 11;
//	}
//
//	colour1 = GETCOLOUR(unk10);
//
//	if (dialog->dimmed) {
//		colour1 = (colourBlend(colour1, 0x00000000, 44) & 0xffffff00) | (colour1 & 0xff);
//	}
//
//	colour2 = GETCOLOUR(unk14);
//
//	// Draw the dialog's background and outer borders
//	if (!lightweight) {
//		if (dialog->state == MENUDIALOGSTATE_OPENING) {
//			gdl = menugfxRenderDialogBackground(gdl, dialogleft + 1, dialogtop + 11, dialogleft + dialogwidth - 1, dialogbottom, dialog, colour1, colour2, 1.0f);
//		} else if (dialog->state == MENUDIALOGSTATE_POPULATING) {
//			gdl = menugfxRenderDialogBackground(gdl, dialogleft + 1, dialogtop + 11, dialogleft + dialogwidth - 1, dialogbottom, dialog, colour1, colour2, dialog->statefrac);
//		} else {
//			gdl = menugfxRenderDialogBackground(gdl, dialogleft + 1, dialogtop + 11, dialogleft + dialogwidth - 1, dialogbottom, dialog, colour1, colour2, -1.0f);
//		}
//
//		// No dialog has this flag, so this branch is unused
//		if (dialog->definition->flags & MENUDIALOGFLAG_DISABLETITLEBAR) {
//			gdl = menugfxRenderDialogBorderLine(gdl, dialogleft + 1, dialogtop + 11, dialogleft + dialogwidth - 1, dialogtop + 12, GETCOLOUR(unk00), GETCOLOUR(unk08));
//		}
//	}
//
//	if (dialog->state == MENUDIALOGSTATE_PREOPEN) {
//		return gdl;
//	}
//
//	{
//		struct menulayer *layer;
//		s32 viewleft = viGetViewLeft() / g_ScaleX;
//		s32 viewtop = viGetViewTop();
//		s32 viewright = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX;
//		s32 viewbottom = viGetViewTop() + viGetViewHeight();
//
//		// Goal loads the address of g_MenuScissorX2 for the store then loads it
//		// again for the load for the subsequent if statement. If we use one
//		// variable for this then it reuses the register instead of loading it
//		// again. To make this match, a second variable has been configured in
//		// the linker map with the same address as g_MenuScissorX2. This forces
//		// the compiler to do the second load. It's obviously not correct though.
//		extern s32 g_MenuScissorX2_2;
//
//		g_MenuScissorX1 = dialogleft + 2;
//		g_MenuScissorX2_2 = dialogleft + dialogwidth - 2;
//		g_MenuScissorY1 = dialogtop + 11;
//		g_MenuScissorY2 = dialogbottom - 1;
//
//		if (g_MenuScissorX2 < viewleft) {
//			return gdl;
//		}
//
//		if (g_MenuScissorY2 < viewtop) {
//			return gdl;
//		}
//
//		if (g_MenuScissorX1 > viewright) {
//			return gdl;
//		}
//
//		if (g_MenuScissorY1 > viewbottom) {
//			return gdl;
//		}
//
//		if (g_MenuScissorX2 > viewright) {
//			g_MenuScissorX2 = viewright;
//		}
//
//		if (g_MenuScissorY2 > viewbottom) {
//			g_MenuScissorY2 = viewbottom;
//		}
//
//		if (g_MenuScissorX1 < viewleft) {
//			g_MenuScissorX1 = viewleft;
//		}
//
//		// @bug: This should be g_MenuScissorY1
//		// but the condition can't pass anyway.
//		if (g_MenuScissorX2 < viewtop) {
//			g_MenuScissorX2 = viewtop;
//		}
//
//		var8009de90 = g_MenuScissorY1;
//		var8009de94 = g_MenuScissorY2;
//
//		gdl = menuApplyScissor(gdl);
//
//		// Render models (inventory, chr/vehicle bios)
//		if (g_Menus[g_MpPlayerNum].curdialog == dialog
//				&& (dialog->definition->flags & MENUDIALOGFLAG_0002)
//				&& !lightweight
//				&& !g_Menus[g_MpPlayerNum].unk840.unk5b1_07) {
//			gSPSetGeometryMode(gdl++, G_ZBUFFER);
//
//			gdl = menuRenderModels(gdl, &g_Menus[g_MpPlayerNum].unk840, 0);
//
//			gSPClearGeometryMode(gdl++, G_ZBUFFER);
//
//			viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
//			viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
//					g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
//		}
//
//		// Render menu items
//		if (dialog->type != 0 || dialog->transitionfrac >= 0.0f) {
//			s32 sumwidth; // 130
//			s32 cury; // 12c
//			bool prevwaslist; // 128
//			s32 colwidth; // 124
//			u32 sp120; // 120
//			bool offscreen;
//			struct menuitem *item; // 118
//			s32 focused; // 114
//			s32 colindex;
//			s32 rowindex;
//
//			sumwidth = 0;
//			curx = dialogleft;
//
//			for (i = 0; i < dialog->numcols; i++) {
//				cury = dialogtop + 12 + dialog->scroll;
//				prevwaslist = false;
//
//				sp120 = GETCOLOUR(unfocused);
//				sp120 = (sp120 & 0xffffff00) | 0x3f;
//
//				colindex = dialog->colstart + i;
//
//				if (i != 0 && (dialog->definition->flags & MENUDIALOGFLAG_0400) == 0) {
//					gdl = gfxDrawFilledRect(gdl, curx - 1, dialogtop + 12, curx, dialogbottom, sp120, sp120);
//				}
//
//				colwidth = menu->cols[colindex].width;
//				sumwidth += colwidth;
//
//				if (i == dialog->numcols - 1) {
//					s32 v0 = (dialogleft + dialogwidth - dialogleft) - 2;
//
//					if (sumwidth < v0) {
//						colwidth = (colwidth + v0) - sumwidth;
//					}
//				}
//
//				for (j = 0; j < menu->cols[colindex].numrows; j++) {
//					focused = 0;
//					rowindex = menu->cols[colindex].rowstart + j;
//					item = &dialog->definition->items[menu->rows[rowindex].itemindex];
//					itemdata = NULL;
//					offscreen = false;
//
//					if (item == dialog->focuseditem) {
//						focused = 1;
//
//						if (dialog->dimmed) {
//							focused = 3;
//						}
//					}
//
//					if (menu->rows[rowindex].blockindex != -1) {
//						itemdata = (union menuitemdata *)&menu->blocks[menu->rows[rowindex].blockindex];
//					}
//
//					context.x = curx;
//					context.y = cury;
//					context.width = colwidth;
//					context.height = menu->rows[rowindex].height;
//
//					if (context.y + context.height < dialogtop + 12) {
//						offscreen = true;
//					}
//
//					if (context.y > dialogbottom) {
//						offscreen = true;
//					}
//
//					if (context.height == 0) {
//						offscreen = true;
//					}
//
//					if (!offscreen) {
//						context.item = item;
//						context.data = itemdata;
//						context.focused = focused;
//						context.dialog = dialog;
//
//						if (prevwaslist) {
//							gdl = gfxDrawFilledRect(gdl, context.x, context.y - 1, context.x + context.width, context.y, sp120, sp120);
//							prevwaslist = false;
//						}
//
//						if ((item->flags & MENUITEMFLAG_00004000) && !lightweight) {
//							// Render a darker background behind the item
//							s32 x1 = context.x;
//							s32 y1 = context.y;
//							s32 x2 = x1 + context.width;
//							s32 y2 = y1 + context.height;
//							u32 colour;
//							u32 colour2;
//
//							colour2 = GETCOLOUR(unk28);
//							colour = colourBlend(colour2, colour2 & 0xffffff00, 127);
//
//							gdl = gfxSetPrimColour(gdl, colour);
//							gDPFillRectangleScaled(gdl++, x1, y1, x2, y2);
//							gdl = func0f153838(gdl);
//						}
//
//						if (focused) {
//							if (item->type == MENUITEMTYPE_03
//									|| item->type == MENUITEMTYPE_SELECTABLE
//									|| item->type == MENUITEMTYPE_CHECKBOX
//									|| item->type == MENUITEMTYPE_0A
//									|| item->type == MENUITEMTYPE_SLIDER
//									|| item->type == MENUITEMTYPE_DROPDOWN) {
//#if VERSION >= VERSION_NTSC_1_0
//								if (!(dialog->transitionfrac >= 0.0f && dialog->type2 == 0)
//										&& !(dialog->transitionfrac < 0.0f && dialog->type == 0)) {
//									func0f156024(1);
//								}
//#else
//								func0f156024(1);
//#endif
//							}
//
//							// Render the horizontal line behind the focused item
//							if (item->type == MENUITEMTYPE_SELECTABLE
//									|| item->type == MENUITEMTYPE_CHECKBOX
//									|| item->type == MENUITEMTYPE_0A
//									|| item->type == MENUITEMTYPE_DROPDOWN) {
//								s32 liney = context.y + context.height / 2 - 1;
//								s32 x1 = context.x;
//								s32 x3 = context.x + 8;
//								s32 x4 = context.x + context.width / 3;
//
//								// Left side
//								gdl = func0f0e2498(gdl);
//								gdl = gfxDrawTri2(gdl, x1, liney - 1, x3 - 3, liney, sp120, sp120, 0);
//								gdl = gfxDrawTri2(gdl, x3 - 3, liney - 1, x3, liney, sp120, 0xffffffff, 0);
//								gdl = gfxDrawTri2(gdl, x1, liney + 1, x3 - 3, liney + 2, sp120, sp120, 0);
//								gdl = gfxDrawTri2(gdl, x3 - 3, liney + 1, x3, liney + 2, sp120, 0xffffffff, 0);
//								gdl = gfxDrawTri2(gdl, x3 - 2, liney, x4, liney + 1, (sp120 & 0xffffff00) | 0x2f, sp120 & 0xffffff00, 0);
//
//								if (item->flags & MENUITEMFLAG_00000020) {
//									// Right side
//									x1 = context.x + context.width;
//									x3 = context.x + context.width - 8;
//									x4 = context.x + context.width - context.width / 3;
//
//									gdl = gfxDrawTri2(gdl, x1 - 5, liney - 1, x1, liney, sp120, sp120, 0);
//									gdl = gfxDrawTri2(gdl, x3, liney - 1, x3 + 3, liney, -1, sp120, 0);
//									gdl = gfxDrawTri2(gdl, x3 + 3, liney + 1, x1, liney + 2, sp120, sp120, 0);
//									gdl = gfxDrawTri2(gdl, x3, liney + 1, x3 + 3, liney + 2, -1, sp120, 0);
//									gdl = gfxDrawTri2(gdl, x4, liney, x3 + 2, liney + 1, sp120 & 0xffffff00, (sp120 & 0xffffff00) | 0x2f, 0);
//								}
//							}
//						}
//
//						gdl = menuitemRender(gdl, &context);
//
//						if (item->type == MENUITEMTYPE_LIST) {
//							prevwaslist = true;
//						}
//
//						if (focused) {
//							func0f156024(0);
//						}
//					}
//
//					cury += menu->rows[rowindex].height;
//				}
//
//				curx += menu->cols[colindex].width;
//			}
//
//			// Render overlays, such as dropdown menus
//			if (!lightweight) {
//				gdl = gfxSetPrimColour(gdl, 0x00000000);
//
//				curx = dialogleft;
//
//				for (i = 0; i < dialog->numcols; i++) {
//					s32 cury = dialogtop + 12 + dialog->scroll;
//					colindex = dialog->colstart + i;
//
//					for (j = 0; j < menu->cols[colindex].numrows; j++) {
//						union menuitemdata *itemdata;
//						struct menuitem *item;
//
//						rowindex = menu->cols[colindex].rowstart + j;
//						itemdata = NULL;
//						item = &dialog->definition->items[menu->rows[rowindex].itemindex];
//
//						if (menu->rows[rowindex].blockindex != -1) {
//							itemdata = (union menuitemdata *)&menu->blocks[menu->rows[rowindex].blockindex];
//						}
//
//						gdl = menuitemOverlay(gdl, curx, cury, menu->cols[colindex].width, menu->rows[rowindex].height, item, dialog, itemdata);
//
//						cury += menu->rows[rowindex].height;
//					}
//
//					curx += menu->cols[colindex].width;
//				}
//
//				gdl = func0f153838(gdl);
//			}
//
//			gDPSetScissor(gdl++, G_SC_NON_INTERLACE, viGetViewLeft(), viGetViewTop(),
//					viGetViewLeft() + viGetViewWidth(), viGetViewTop() + viGetViewHeight());
//		} else {
//			gDPSetScissor(gdl++, G_SC_NON_INTERLACE, viGetViewLeft(), viGetViewTop(),
//					viGetViewLeft() + viGetViewWidth(), viGetViewTop() + viGetViewHeight());
//		}
//
//		// Render left/right chevrons and sibling dialog titles
//		layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];
//
//		if ((dialog->type != 0 || dialog->transitionfrac >= 0.0f)
//				&& layer->siblings[layer->cursibling] == dialog
//				&& (layer->numsiblings >= 2)) {
//			// Draw chevrons
//			u32 colour1;
//			u32 colour;
//			u32 weight = func0f006b08(10) * 255.0f;
//
//			colour1 = GETCOLOUR(unk00);
//			colour = colourBlend(0xffffffff, colour1, weight);
//
//			gdl = func0f0e3324(gdl, dialogleft - 5, (dialogtop + dialogbottom) / 2, 9, 1, colour, colour, func0f006b08(20));
//			gdl = func0f0e3324(gdl, dialogleft + dialogwidth + 5, (dialogtop + dialogbottom) / 2, 9, 3, colour, colour, func0f006b08(20));
//
//			if (g_MenuData.root == MENUROOT_MAINMENU
//					|| g_MenuData.root == MENUROOT_4MBFILEMGR
//					|| g_MenuData.root == MENUROOT_TRAINING
//					|| g_MenuData.root == MENUROOT_FILEMGR) {
//				s32 previndex;
//				s32 nextindex;
//				s32 textheight; // b0
//				s32 textwidth; // ac
//				char *title;
//
//				func0f153e4c();
//				textSetRotation90(true);
//
//				gdl = func0f153628(gdl);
//
//				// Left/previous title
//				previndex = layer->cursibling - 1;
//
//				if (previndex < 0) {
//					previndex = layer->numsiblings - 1;
//				}
//
//				title = menuResolveDialogTitle(layer->siblings[previndex]->definition);
//
//				textMeasure(&textheight, &textwidth, title, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//
//				x = dialogleft - 1;
//				y = (dialogtop + dialogbottom) / 2 - textwidth - 3;
//
//				if (y < dialogtop) {
//					y = (dialogtop + dialogbottom - textwidth) / 2;
//					x -= 3;
//				}
//
//				gdl = textRenderProjected(gdl, &y, &x, title, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffffff, dialogwidth, viGetHeight(), 0, 0);
//
//				// Right/next title
//				nextindex = layer->cursibling + 1;
//
//				if (nextindex >= layer->numsiblings) {
//					nextindex = 0;
//				}
//
//				title = menuResolveDialogTitle(layer->siblings[nextindex]->definition);
//
//				textMeasure(&textheight, &textwidth, title, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//
//				x = dialogleft + dialogwidth + 7;
//				y = (dialogtop + dialogbottom) / 2 + 3;
//
//				if (y + textwidth > dialogbottom) {
//					y = (dialogtop + dialogbottom - textwidth) / 2;
//					x += 3;
//				}
//
//				gdl = textRenderProjected(gdl, &y, &x, title, g_CharsHandelGothicXs, g_FontHandelGothicXs, -1, dialogwidth, viGetHeight(), 0, 0);
//				gdl = func0f153780(gdl);
//
//				textSetRotation90(false);
//			}
//		}
//	}
//
//	return gdl;
//}

const char var7f1b2668[] = "[]-[] Terminate Complete\n";
const char var7f1b2684[] = "Enabling control %d\n";
const char var7f1b269c[] = "NOT IN MODE MULTIINGAME!\n";
const char var7f1b26b8[] = "Numactive now:%d\n";
const char var7f1b26cc[] = "[]-[] SwitchMenuMode called, context %d\n";

void menuGetContPads(s8 *contpadnum1, s8 *contpadnum2)
{
	switch (g_MenuData.root) {
	case MENUROOT_MPSETUP:
	case MENUROOT_FILEMGR:
	case MENUROOT_BOOTPAKMGR:
	case MENUROOT_4MBFILEMGR:
	case MENUROOT_4MBMAINMENU:
		*contpadnum1 = g_MpPlayerNum;
		*contpadnum2 = -1;
		break;
	default:
		*contpadnum1 = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
		*contpadnum2 = -1;

		if (!g_Vars.normmplayerisrunning) {
			s32 mode = optionsGetControlMode(g_Vars.currentplayerstats->mpindex);

			if (mode == CONTROLMODE_23 || mode == CONTROLMODE_24 || mode == CONTROLMODE_22 || mode == CONTROLMODE_21) {
				*contpadnum2 = optionsGetContpadNum2(g_Vars.currentplayerstats->mpindex);
			}
		}
		break;
	}
}

u32 g_MpNumJoined = 1;

/**
 * Choose which direction a new dialog should swipe from in the combat simulator
 * menus.
 */
void func0f0f7594(s32 arg0, s32 *vdir, s32 *hdir)
{
	if (g_MenuData.root == MENUROOT_MPSETUP) {
		s32 playernum = g_Menus[g_MpPlayerNum].playernum;

		*vdir = 0;
		*hdir = 0;

		switch (g_MpNumJoined) {
		case 1:
			*hdir = arg0;
			break;
		case 2:
			if (playernum == 0) {
				if (arg0 < 0) {
					*hdir = -1;
				} else {
					*vdir = -1;
				}
			} else {
				if (arg0 > 0) {
					*hdir = 1;
				} else {
					*vdir = 1;
				}
			}
			break;
		case 3:
			if (playernum == 2) {
				*hdir = arg0;
			} else if (playernum == 0) {
				if (arg0 < 0) {
					*hdir = -1;
				} else {
					*vdir = -1;
				}
			} else {
				if (arg0 > 0) {
					*hdir = 1;
				} else {
					*vdir = -1;
				}
			}
			break;
		case 4:
			if (playernum == 0 || playernum == 2) {
				if (arg0 < 0) {
					*hdir = -1;
				} else {
					*vdir = playernum == 0 ? -1 : 1;
				}
			} else {
				if (arg0 > 0) {
					*hdir = 1;
				} else {
					*vdir = playernum == 1 ? -1 : 1;
				}
			}
			break;
		}
	} else {
		*vdir = 0;
		*hdir = arg0;
	}
}

/**
 * Find the maximum possible dimensions for a dialog.
 *
 * This is pretty much the player's viewport with some adjustments made for
 * padding. There are some trickier calculations for MP setup where the players
 * are sharing a viewport.
 */
void menuFindAvailableSize(s32 *leftptr, s32 *topptr, s32 *rightptr, s32 *bottomptr)
{
	s32 left = viGetViewLeft() / g_ScaleX + 20;
	s32 top = viGetViewTop() + 4;
	s32 right = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX - 20;
	s32 bottom = viGetViewTop() + viGetViewHeight() - 4;
	s32 playernum;
	u32 stack[2];

	if (currentPlayerIsMenuOpenInSoloOrMp()) {
		// Make room for health bar
		top += 22;

		if (optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA) {
			top -= 8;
			bottom += 4;
		}
	}

	switch (g_MenuData.root) {
	case MENUROOT_MPSETUP:
	case MENUROOT_4MBMAINMENU:
		playernum = g_Menus[g_MpPlayerNum].playernum;

		// Make room for the "Press START" labels
		if (g_MenuData.playerjoinalpha[0] > 0 || g_MenuData.playerjoinalpha[1] > 0) {
			top += 10;
		}

		if (g_MenuData.playerjoinalpha[2] > 0 || g_MenuData.playerjoinalpha[3] > 0) {
			bottom -= 10;
		}

		switch (g_MpNumJoined) {
		case 1:
			// 1 player - the full screen is available
			*leftptr = left;
			*rightptr = right;
			*topptr = top;
			*bottomptr = bottom;
			return;
		case 2:
			// 2 players - left/right halves each
			*topptr = top;
			*bottomptr = bottom;

			if (playernum == 0) {
				*leftptr = left;
				*rightptr = (left + right) / 2;
			} else {
				*leftptr = (left + right) / 2;
				*rightptr = right;
			}
			return;
		case 3:
			// 3 players - top two quarters and the third takes the full bottom
			if (playernum == 0 || playernum == 1) {
				*topptr = top;
				*bottomptr = (top + bottom) / 2;

				if (playernum == 0) {
					*leftptr = left;
					*rightptr = (left + right) / 2;
				} else {
					*leftptr = (left + right) / 2;
					*rightptr = right;
				}
			} else {
				*topptr = (top + bottom) / 2;
				*bottomptr = bottom;
				*leftptr = left;
				*rightptr = right;
			}
			break;
		case 4:
			// 4 players - quarters
			if (playernum == 0 || playernum == 2) {
				*leftptr = left;
				*rightptr = (left + right) / 2;
			} else {
				*leftptr = (left + right) / 2;
				*rightptr = right;
			}
			if (playernum == 0 || playernum == 1) {
				*topptr = top;
				*bottomptr = (top + bottom) / 2;
			} else {
				*topptr = (top + bottom) / 2;
				*bottomptr = bottom;
			}
			break;
		}
		break;
	case MENUROOT_MPPAUSE:
	case MENUROOT_MPENDSCREEN:
	case MENUROOT_PICKTARGET:
	case MENUROOT_4MBFILEMGR:
		*leftptr = g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewleft / g_ScaleX;
		*topptr = g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewtop;
		*rightptr = (g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewleft + g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewwidth) / g_ScaleX;
		*bottomptr = g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewtop + g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewheight;

		if (PLAYERCOUNT() > 2) {
			if (g_Menus[g_MpPlayerNum].playernum == 0 || g_Menus[g_MpPlayerNum].playernum == 2) {
				*leftptr += 22;
			} else {
				*rightptr -= 22;
			}
		}

#if VERSION >= VERSION_NTSC_1_0
		if (PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()))
#else
		if (PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL)
#endif
		{
			if (g_Menus[g_MpPlayerNum].playernum == 0) {
				*leftptr += 22;
			} else {
				*rightptr -= 22;
			}
		}
		break;
	default:
		*leftptr = left;
		*topptr = top;
		*rightptr = right;
		*bottomptr = bottom;
		break;
	}
}

void dialogCalculatePosition(struct menudialog *dialog)
{
	s32 xmin;
	s32 xmax;
	s32 ymin;
	s32 ymax;
	s32 width;
	s32 height;
	s32 vdir;
	s32 hdir;

	menuFindAvailableSize(&xmin, &ymin, &xmax, &ymax);

	height = ymax - ymin - 6;
	width = xmax - xmin - 6;

	if (width > dialog->contentwidth) {
		width = dialog->contentwidth;
	}

	if (height > dialog->contentheight) {
		height = dialog->contentheight;
	}

	dialog->dstx = (xmax + xmin - width) / 2;
	dialog->dsty = (ymin + ymax - height) / 2;
	dialog->dstwidth = width;
	dialog->dstheight = height;

	if (dialog->swipedir != 0) {
		func0f0f7594(dialog->swipedir, &vdir, &hdir);

		if (hdir < 0) {
			dialog->dstx = -4 - dialog->dstwidth;
		}

		if (hdir > 0) {
			dialog->dstx = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX + 4;
		}

		if (vdir < 0) {
			dialog->dsty = -4 - dialog->dstheight;
		}

		if (vdir > 0) {
			dialog->dsty = viGetViewTop() + viGetViewHeight() + 4;
		}
	}
}

void menuClose(void)
{
	g_Menus[g_MpPlayerNum].depth = 0;
	g_Menus[g_MpPlayerNum].numdialogs = 0;
	g_Menus[g_MpPlayerNum].rowend = 0;
	g_Menus[g_MpPlayerNum].colend = 0;
	g_Menus[g_MpPlayerNum].blockend = 0;
	g_Menus[g_MpPlayerNum].curdialog = NULL;
	g_Menus[g_MpPlayerNum].openinhibit = 10;

	if (g_MenuData.root == MENUROOT_MPPAUSE) {
		g_PlayersWithControl[g_Menus[g_MpPlayerNum].playernum] = true;
	}

	g_MenuData.count--;

	if (g_MenuData.root == MENUROOT_MPPAUSE && g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
		g_Vars.currentplayer->activemenumode = AMMODE_VIEW;
	}

	if (g_MenuData.root == MENUROOT_BOOTPAKMGR) {
		mainChangeToStage(STAGE_TITLE);
	}
}

void func0f0f8120(void)
{
	struct menudialog *prev = g_Menus[g_MpPlayerNum].curdialog;
	s32 i;

	if (g_MenuData.unk66e > 0) {
		for (i = g_MenuData.unk66e; i >= 0; i--) {
			func0f0f3220(i);
		}
	}

	if (g_Menus[g_MpPlayerNum].curdialog == prev) {
		while (g_Menus[g_MpPlayerNum].depth > 0) {
			menuPopDialog();
		}
	}
}

void func0f0f820c(struct menudialogdef *dialogdef, s32 root)
{
	s32 i;
	s32 prevplayernum = g_MpPlayerNum;

	for (i = 0; i < 4; i++) {
		if (g_Menus[i].curdialog) {
			g_MpPlayerNum = i;
			func0f0f8120();
		}
	}

	g_MpPlayerNum = prevplayernum;

	g_MenuData.unk008 = root;
	g_MenuData.unk00c = dialogdef;
}

bool menuSetBackground(s32 bg)
{
	// Can only screenshot if there is no background already,
	// because we want a clean screenshot
	bool screenshot = g_MenuData.bg == 0;

	// If there's already a screenshottable background queued,
	// there's no need to create another
	if (g_MenuData.nextbg == MENUBG_BLUR || g_MenuData.nextbg == MENUBG_TUNNELALPHA) {
		screenshot = false;
	}

	if (g_MenuData.bg != bg) {
		g_MenuData.nextbg = bg;
	}

	if (screenshot && g_MenuData.bg == 0) {
		g_MenuData.screenshottimer = 1;
	}
}

void func0f0f8300(void)
{
	s32 i;

	if (g_MenuData.count == 0) {
		for (i = 0; i < 4; i++) {
			g_MenuData.playerjoinalpha[i] = 0;
		}
	}
}

void menuPushRootDialog(struct menudialogdef *dialogdef, s32 root)
{
	g_Menus[g_MpPlayerNum].numdialogs = 0;
	g_Menus[g_MpPlayerNum].depth = 0;

	g_MenuData.unk5d5_01 = false;
	g_MenuData.unk5d5_04 = false;

	g_PlayersWithControl[g_Menus[g_MpPlayerNum].playernum] = false;

	func0f0f1494();

	g_MenuData.count++;

	if (root == MENUROOT_PICKTARGET) {
		g_Menus[g_MpPlayerNum].mppause.unke40_00 = true;
		root = MENUROOT_MPPAUSE;
	}

	switch (root) {
	case MENUROOT_ENDSCREEN:
	case MENUROOT_MAINMENU:
	case MENUROOT_FILEMGR:
	case MENUROOT_BOOTPAKMGR:
	case MENUROOT_PICKTARGET:
	case MENUROOT_COOPCONTINUE:
	case MENUROOT_4MBFILEMGR:
	case MENUROOT_TRAINING:
		g_MenuData.count = 1;
		break;
	}

	g_Menus[g_MpPlayerNum].unk820 = 1;

	g_MenuData.root = root;
	g_MenuData.unk008 = -1;
	g_MenuData.unk5d5_02 = false;

	if (root == MENUROOT_MAINMENU
			|| root == MENUROOT_MPSETUP
			|| root == MENUROOT_TRAINING
			|| root == MENUROOT_FILEMGR) {
		if (IS8MB() && (g_MenuData.unk5d4 == 0 || g_MenuData.unk01c.unk5b1_04)) {
			if (!g_MenuData.unk5d5_04) {
				g_MenuData.unk5d5_05 = true;
			}
		}
	}

	menuPushDialog(dialogdef);

	switch (root) {
	case MENUROOT_MPSETUP:
		menuSetBackground(MENUBG_TUNNELALPHA);
		break;
	case MENUROOT_4MBFILEMGR:
		musicStartMenu();
		g_MenuData.bg = MENUBG_TUNNELOPAQUE;
		break;
	case MENUROOT_4MBMAINMENU:
		g_MenuData.bg = MENUBG_TUNNELOPAQUE;
		break;
	case MENUROOT_ENDSCREEN:
		if (dialogdef->type == MENUDIALOGTYPE_DANGER) {
			g_MenuData.unk5d4 = 0;
			g_MenuData.nextbg = MENUBG_FAILURE;
			break;
		}
		// fall-through
	case MENUROOT_MAINMENU:
	case MENUROOT_MPENDSCREEN:
	case MENUROOT_FILEMGR:
	case MENUROOT_COOPCONTINUE:
	case MENUROOT_TRAINING:
		menuSetBackground(MENUBG_BLUR);
		break;
	case MENUROOT_BOOTPAKMGR:
		musicStartMenu();
		g_MenuData.bg = MENUBG_GRADIENT;
		break;
	}

	if (menuIsSoloMissionOrMp()) {
		currentPlayerDisplayHealth();
	}
}

void func0f0f85e0(struct menudialogdef *dialogdef, s32 root)
{
	if (dialogdef == &g_CiMenuViaPcMenuDialog) {
		musicStartMenu();
	}

	menuPushRootDialog(dialogdef, root);
	lvSetPaused(true);
	g_Vars.currentplayer->pausemode = PAUSEMODE_PAUSED;
}

u32 g_MenuCThresh = 120;

Gfx *menuRenderDialog(Gfx *gdl, struct menudialog *dialog, struct menu *menu, bool lightweight)
{
	mainOverrideVariable("cthresh", &g_MenuCThresh);

	func0f153d50(dialog->unk54, dialog->unk58, g_MenuCThresh);

	gdl = dialogRender(gdl, dialog, menu, lightweight);

	func0f153e4c();

	return gdl;
}

const char var7f1b2700[] = "[]-[] slide from %d";
const char var7f1b2714[] = " to %d\n";
const char var7f1b271c[] = "UNPAUSE: enabling control 0\n";
const char var7f1b273c[] = "file: type %d guid %x-%x data %x err %d\n";
const char var7f1b2768[] = "StartSelects\n";

/**
 * Render all dialogs for the current player.
 *
 * There's usually only one on screen at a time, but there can be multiple when
 * transitioning between dialogs. This happens when swiping left or right beteen
 * dialogs on the same layer, or when opening or closing dialogs.
 */
Gfx *menuRenderDialogs(Gfx *gdl)
{
	if (g_Menus[g_MpPlayerNum].curdialog) {
		if (g_MenuData.root == MENUROOT_MPPAUSE
				|| g_MenuData.root == MENUROOT_PICKTARGET
				|| g_MenuData.root == MENUROOT_MPENDSCREEN) {
			var8009de98 = g_Menus[g_MpPlayerNum].curdialog->x + g_Menus[g_MpPlayerNum].curdialog->width / 2 - viGetWidth() / (g_ScaleX * 2);
			var8009de9c = g_Menus[g_MpPlayerNum].curdialog->y + g_Menus[g_MpPlayerNum].curdialog->height / 2 - viGetHeight() / 2;

			gdl = menuRenderDialog(gdl, g_Menus[g_MpPlayerNum].curdialog, &g_Menus[g_MpPlayerNum], 0);
		} else {
			s32 i;
			s32 j;

#if VERSION >= VERSION_NTSC_1_0
			// NTSC 1.0 and newer renders one "other" dialog plus the current
			// dialog. The other dialog is only rendered if on-screen, and it
			// ensures the current dialog is drawn last.
			struct menudialog *dialogs[] = { NULL, NULL };

			for (i = 0; i < g_Menus[g_MpPlayerNum].depth; i++) {
				struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[i];

				for (j = 0; j < layer->numsiblings; j++) {
					if (layer->siblings[j] != g_Menus[g_MpPlayerNum].curdialog) {
						if (layer->siblings[j]->type != 0 || layer->siblings[j]->transitionfrac >= 0) {
							dialogs[0] = layer->siblings[j];
						}
					}
				}
			}

			// Render the other dialog if any
			if (dialogs[0]) {
				gdl = menuRenderDialog(gdl, dialogs[0], &g_Menus[g_MpPlayerNum], 0);
			}

			// Render the current dialog
			if (g_Menus[g_MpPlayerNum].curdialog) {
				gdl = menuRenderDialog(gdl, g_Menus[g_MpPlayerNum].curdialog, &g_Menus[g_MpPlayerNum], 0);
			}
#else
			// NTSC beta renders all dialogs all the time, and in their natural order
			for (i = 0; i < g_Menus[g_MpPlayerNum].depth; i++) {
				struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[i];

				for (j = 0; j < layer->numsiblings; j++) {
					gdl = menuRenderDialog(gdl, layer->siblings[j], &g_Menus[g_MpPlayerNum], 0);
				}
			}
#endif
		}

		// Render banner messages
		if (g_Menus[g_MpPlayerNum].bannernum != -1
				&& (g_Menus[g_MpPlayerNum].curdialog->definition->flags & MENUDIALOGFLAG_DISABLEBANNER) == 0) {
			if (g_MenuData.count >= 2) {
				s32 xmin;
				s32 ymin;
				s32 xmax;
				s32 ymax;

				menuFindAvailableSize(&xmin, &ymin, &xmax, &ymax);

#if VERSION >= VERSION_NTSC_1_0
				gdl = menuRenderBanner(gdl, xmin, ymin, xmax, ymax, false, g_Menus[g_MpPlayerNum].bannernum, 0, 0);
#else
				gdl = menuRenderBanner(gdl, xmin, ymin, xmax, ymax, false, g_Menus[g_MpPlayerNum].bannernum);
#endif
			} else {
				s32 xmin = viGetViewLeft() / g_ScaleX;
				s32 ymin = viGetViewTop();
				s32 xmax = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX;
				s32 ymax = viGetViewTop() + viGetViewHeight();

#if VERSION >= VERSION_NTSC_1_0
				gdl = menuRenderBanner(gdl, xmin, ymin, xmax, ymax, true, g_Menus[g_MpPlayerNum].bannernum, 0, 0);
#else
				gdl = menuRenderBanner(gdl, xmin, ymin, xmax, ymax, true, g_Menus[g_MpPlayerNum].bannernum);
#endif
			}
		}
	}

	return gdl;
}

u32 var800714e8 = 0;

void func0f0f8bb4(struct menu840 *arg0, u32 arg1, u32 arg2)
{
	arg0->unk008 = arg1;
	arg0->unk004 = arg2 ? mempAlloc(arg1, MEMPOOL_STAGE) : NULL;
	arg0->unk54c = 0.0f;
	arg0->unk000 = 0;
	arg0->unk00c = 0xffff;
	arg0->bodymodeldef = NULL;
	arg0->unk010 = 0;
	arg0->unk56c = 0;
	arg0->unk570 = 0;
	arg0->partvisibility = NULL;
	arg0->unk5b1_01 = false;
	arg0->unk5b1_02 = false;
	arg0->unk5b1_04 = false;
	arg0->unk5b1_06 = false;
	arg0->headnum = -1;
	arg0->bodynum = -1;
	arg0->unk538 = 0.0f;
	arg0->unk510 = 0.0f;
	arg0->unk53c = 0.0f;
	arg0->unk514 = 0.0f;
	arg0->unk540 = 0.0f;
	arg0->unk518 = 0.0f;
	arg0->unk544 = 0.0f;
	arg0->unk51c = 0.0f;
	arg0->unk548 = 0.0f;
	arg0->unk520 = 0.0f;
	arg0->unk550 = 0.0f;
	arg0->unk528 = 0.0f;
	arg0->unk534 = 0.0f;
	arg0->unk530 = 0.0f;
	arg0->unk52c = 0.0f;
	arg0->unk524 = arg0->unk54c;
}

void menuInit(void)
{
	s32 i;

	func0f110bf0();

	var8009dfc0 = 0;

	if (IS8MB()) {
		g_BlurBuffer = mempAlloc(0x4b00, MEMPOOL_STAGE);
	}

	g_MenuData.unk5d5_01 = false;

	func0f0b3988(&var800ab5a8[1]);
	func0f0b3988(&var800ab5a8[6]);
	func0f0b3988(&var800ab5a8[51]);
	func0f0b3988(&var800ab5a8[52]);
	func0f0b3988(&var800ab5a8[53]);
	func0f0b3988(&var800ab5a8[54]);
	func0f0b3988(&var800ab5a8[55]);

	if (g_Vars.stagenum == STAGE_CITRAINING) {
		for (i = 12; i < 34; i++) {
			func0f0b3988(&var800ab5a8[i]);
		}

		func0f0b3988(&var800ab5a8[34]);
		func0f0b3988(&var800ab5a8[36]);
		func0f0b3988(&var800ab5a8[35]);
	}

	if (g_Vars.mplayerisrunning) {
		func0f0b3988(&var800ab5a8[35]);
	}

	for (i = 0; i < 4; i++) {
		g_Menus[i].unk840.unk004 = NULL;
	}

	g_MenuData.unk01c.unk004 = NULL;

	if (g_Vars.stagenum == STAGE_CITRAINING) {
		g_MissionConfig.iscoop = false;
		g_MissionConfig.isanti = false;
		g_MissionConfig.pdmode = false;
	}

	if (!g_Vars.mplayerisrunning) {
		s32 max = 0;

		if (g_Vars.stagenum == STAGE_CITRAINING) {
			max = 4;
		}

		if (g_Vars.stagenum == STAGE_4MBMENU) {
			max = 4;
		}

		for (i = 0; i < max; i++) {
			func0f0f8bb4(&g_Menus[i].unk840, IS4MB() ? 0xb400 : 0x25800, 1);
		}

		if (IS8MB()) {
			func0f0f8bb4(&g_MenuData.unk01c, 0xc800, 1);
		}

		g_MenuData.unk01c.unk00c = 0x259;
		g_MenuData.unk01c.unk524 = g_MenuData.unk01c.unk54c = -M_PI;
		g_MenuData.unk01c.unk520 = g_MenuData.unk01c.unk548 = 0;
		g_MenuData.unk01c.unk528 = g_MenuData.unk01c.unk550 = 0;
		g_MenuData.unk01c.unk510 = g_MenuData.unk01c.unk538 = -205.5f;
		g_MenuData.unk01c.unk514 = g_MenuData.unk01c.unk53c = 244.7f;
		g_MenuData.unk01c.unk518 = g_MenuData.unk01c.unk540 = 68.3f;
		g_MenuData.unk01c.unk51c = g_MenuData.unk01c.unk544 = 0.12209f;
		g_MenuData.unk01c.unk5b1_01 = false;
		g_MenuData.unk01c.unk574 = 0;
		g_MenuData.unk01c.unk580 = 0;
	}

	g_MenuData.unk5d4 = 0;
	g_MenuData.unk5d5_05 = false;

	for (i = 0; i < 4; i++) {
		g_Menus[i].curdialog = NULL;
		g_Menus[i].depth = 0;
		g_Menus[i].numdialogs = 0;
		g_Menus[i].unk820 = 0;
		g_Menus[i].rowend = 0;
		g_Menus[i].blockend = 0;
		g_Menus[i].colend = 0;
		g_Menus[i].bannernum = -1;
		g_Menus[i].fm.unke41 = 0;
		g_Menus[i].fm.unke64 = 0;
		g_Menus[i].fm.headtextures = NULL;
	}

	g_MenuData.unk668 = -1;
	g_MenuData.unk00c = 0;
	g_MenuData.unk008 = -1;
	g_MenuData.count = 0;
	g_MenuData.root = 0;
	g_MenuData.unk010 = 0;
	g_MenuData.bg = 0;
	g_MenuData.unk5d5_06 = false;
	g_MenuData.nextbg = 255;
	g_MenuData.bannernum = -1;

	for (i = 0; i < 5; i++) {
		g_MenuData.unk669[i] = 0xff;
	}

	g_MenuData.unk66e = 0;
	g_MenuData.unk66f = 0;
}

void menuSwipe(s32 direction)
{
	struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];
	struct menuitem *item;
	union handlerdata sp50;
	union handlerdata sp40;

	if (layer->numsiblings >= 2) {
		g_Menus[g_MpPlayerNum].curdialog->swipedir = -direction;

		layer->cursibling += (s8)direction;

		if (layer->cursibling < 0) {
			layer->cursibling = layer->numsiblings - 1;
		}

		if (layer->cursibling >= layer->numsiblings) {
			layer->cursibling = 0;
		}

		g_Menus[g_MpPlayerNum].curdialog = layer->siblings[layer->cursibling];

		if (direction == 1) {
			g_Menus[g_MpPlayerNum].curdialog->focuseditem = dialogFindFirstItem(g_Menus[g_MpPlayerNum].curdialog);
		} else {
			g_Menus[g_MpPlayerNum].curdialog->focuseditem = dialogFindFirstItemRight(g_Menus[g_MpPlayerNum].curdialog);
		}

		item = g_Menus[g_MpPlayerNum].curdialog->definition->items;

		while (item->type != MENUITEMTYPE_END) {
			if (item->handler
					&& (item->flags & MENUITEMFLAG_00000004) == 0
					&& item->handler(MENUOP_CHECKPREFOCUSED, item, &sp50)) {
				g_Menus[g_MpPlayerNum].curdialog->focuseditem = item;
			}

			item++;
		}

		if (g_Menus[g_MpPlayerNum].curdialog->focuseditem != 0
				&& g_Menus[g_MpPlayerNum].curdialog->focuseditem->handler
				&& ((g_Menus[g_MpPlayerNum].curdialog->focuseditem->flags & MENUITEMFLAG_00000004) == 0)) {
			g_Menus[g_MpPlayerNum].curdialog->focuseditem->handler(MENUOP_FOCUS, g_Menus[g_MpPlayerNum].curdialog->focuseditem, &sp40);
		}

		g_Menus[g_MpPlayerNum].curdialog->swipedir = direction;

		dialogCalculatePosition(g_Menus[g_MpPlayerNum].curdialog);

		g_Menus[g_MpPlayerNum].curdialog->x = g_Menus[g_MpPlayerNum].curdialog->dstx;
		g_Menus[g_MpPlayerNum].curdialog->y = g_Menus[g_MpPlayerNum].curdialog->dsty;
		g_Menus[g_MpPlayerNum].curdialog->swipedir = 0;
		g_Menus[g_MpPlayerNum].curdialog->state = MENUDIALOGSTATE_PREOPEN;
		g_Menus[g_MpPlayerNum].curdialog->statefrac = 0.0f;

		func0f0f37a4(&g_Menus[g_MpPlayerNum].unk840);

		menuPlaySound(MENUSOUND_SWIPE);
	}
}

extern struct menudialogdef g_MpDropOut4MbMenuDialog;

void dialogTick(struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags)
{
	bool usedefaultbehaviour;
	struct menudialogdef *definition;
	struct menu *menu;
	u8 transitiontotype;
	s32 oldfracint;
	s32 oldx;
	s32 col;
	f32 newx;
	union handlerdata data;
	struct menuinputs spd8;
	s32 oldy;
	f32 newy;
	s32 oldwidth;
	f32 newwidth;
	s32 oldheight;
	f32 newheight;
	s32 i;
	u32 stack;

	usedefaultbehaviour = false;
	definition = dialog->definition;
	menu = &g_Menus[g_MpPlayerNum];

	if (g_Menus[g_MpPlayerNum].fm.unke40_00 || g_MainIsDebugMenuOpen) {
		inputs->leftright = inputs->updown = inputs->select = inputs->back = inputs->xaxis = inputs->yaxis = inputs->shoulder = inputs->back2 = inputs->unk14 = 0;
		g_Menus[g_MpPlayerNum].fm.unke40_00 = false;
	}

	g_Menus[g_MpPlayerNum].fm.unke40_00 = false;

	spd8.select = 0;
	spd8.back = inputs->back;
	spd8.leftright = inputs->leftright;
	spd8.updown = inputs->updown;
	spd8.xaxis = inputs->xaxis;
	spd8.yaxis = inputs->yaxis;
	spd8.leftrightheld = inputs->leftrightheld;
	spd8.updownheld = inputs->updownheld;
	spd8.start = 0;
	spd8.unk0c = inputs->unk0c;
	spd8.unk10 = inputs->unk10;

	dialog->unk54++;
	dialog->unk5c += g_Vars.diffframe60;
	dialog->unk54 += dialog->unk5c / 9;
	dialog->unk5c %= 9;
	dialog->unk54 %= g_MenuCThresh;

	// For endscreens, handle transitioning of background and dialog type
	if (dialog->transitionfrac < 0.0f) {
		// Transition not yet started
		if (dialog == g_Menus[g_MpPlayerNum].curdialog) {
			transitiontotype = definition->type;

			if (mpIsPlayerLockedOut(g_MpPlayerNum) && (dialog->definition->flags & MENUDIALOGFLAG_MPLOCKABLE)) {
				transitiontotype = MENUDIALOGTYPE_DANGER;
			}

			if (g_MenuData.root == MENUROOT_ENDSCREEN) {
				if (g_MenuData.bg == MENUBG_8 || g_MenuData.bg == MENUBG_SUCCESS) {
					transitiontotype = MENUDIALOGTYPE_DEFAULT;
				}

				if (g_StageIndex == STAGEINDEX_DEFENSE
						&& g_MenuData.bg != MENUBG_FAILURE
						&& g_MenuData.nextbg != MENUBG_FAILURE) {
					transitiontotype = MENUDIALOGTYPE_WHITE;
					dialog->type = MENUDIALOGTYPE_WHITE;
				}
			}

			if (dialog->type != transitiontotype) {
				dialog->type2 = transitiontotype;
				dialog->colourweight = 0;
				dialog->transitionfrac = 0;
			}
		} else if (dialog->type != 0) {
			dialog->type2 = 0;
			dialog->colourweight = 0;
			dialog->transitionfrac = 0;
		}
	} else {
		// Mid-transition
		if (g_MenuData.root == MENUROOT_ENDSCREEN
				&& g_StageIndex == STAGEINDEX_DEFENSE
				&& g_MenuData.bg != MENUBG_FAILURE
				&& g_MenuData.nextbg != MENUBG_FAILURE
				&& dialog->type2 != 0) {
			dialog->type2 = MENUDIALOGTYPE_WHITE;
		}

		// Success endscreens transition to the background slower than failures
		if (g_MenuData.root == MENUROOT_ENDSCREEN
				&& dialog->type == MENUDIALOGTYPE_SUCCESS
				&& (g_MenuData.bg == MENUBG_8 || g_MenuData.bg == MENUBG_SUCCESS)) {
#if VERSION >= VERSION_PAL_FINAL
			dialog->transitionfrac += g_Vars.diffframe60freal * 0.01f;
#else
			dialog->transitionfrac += g_Vars.diffframe60f * 0.01f;
#endif
		} else {
#if VERSION >= VERSION_PAL_FINAL
			dialog->transitionfrac += g_Vars.diffframe60freal * 0.042f;
#else
			dialog->transitionfrac += g_Vars.diffframe60f * 0.042f;
#endif
		}

		if (dialog->transitionfrac > 1.0f) {
			dialog->transitionfrac = -1.0f;
			dialog->type = dialog->type2;
		}

		dialog->colourweight = dialog->transitionfrac * 255.0f;
	}

	// When fully open and ready, the dialog shows the text fully opaque for
	// 2 seconds (redrawtimer < 0.0f) then starts the redraw timer and waits for
	// it to finish before repeating the process. While the redraw timer is
	// active, the text begins to fade before being redrawn.
	if (dialog->state == MENUDIALOGSTATE_POPULATED) {
		if (g_MenuData.nextbg != MENUBG_TUNNELALPHA) {
			if (dialog->redrawtimer < 0.0f) {
#if VERSION >= VERSION_PAL_FINAL
				dialog->statefrac += g_Vars.diffframe60freal / 120.0f;
#else
				dialog->statefrac += g_Vars.diffframe60f / 120.0f;
#endif

				if (dialog->statefrac > 1.0f) {
					dialog->redrawtimer = 0.0f;
				}
			} else {
				dialog->statefrac = 0.0f;
			}
		}
	}

	// When populating the text for the first time, wait for both the redraw
	// timer to finish and a minimum duration.
	if (dialog->state == MENUDIALOGSTATE_POPULATING) {
#if VERSION >= VERSION_PAL_FINAL
		dialog->statefrac -= 0.05f * g_Vars.diffframe60freal;
#else
		dialog->statefrac -= 0.05f * g_Vars.diffframe60f;
#endif

		if (dialog->statefrac < 0.0f) {
			dialog->statefrac = 0.0f;

			if (dialog->redrawtimer < 0.0f) {
				dialog->state = MENUDIALOGSTATE_POPULATED;
			}
		}
	}

	// When opening the dialog, the height increases gradually over several
	// frames. This part doesn't actually change the height - it updates the
	// statefrac based on the current height.
	if (dialog->state == MENUDIALOGSTATE_OPENING) {
		oldfracint = dialog->statefrac;

		if (dialog->statefrac != dialog->height) {
			for (i = 0; i < g_Vars.diffframe60; i++) {
#if VERSION >= VERSION_PAL_FINAL
				dialog->statefrac = dialog->height * 0.235f + 0.765f * dialog->statefrac;
#else
				dialog->statefrac = dialog->height * 0.2f + 0.8f * dialog->statefrac;
#endif
			}
		}

		if ((s32)dialog->statefrac == oldfracint) {
			dialog->statefrac = oldfracint + 1.0f;
		}

		if (dialog->statefrac > dialog->height - 1.0f && dialog->statefrac < dialog->height + 1.0f) {
			dialog->state = MENUDIALOGSTATE_POPULATING;
			dialog->statefrac = 1.0f;
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	if (dialog->state == MENUDIALOGSTATE_PREOPEN) {
		if (dialog->definition == &g_MpReadyMenuDialog) {
			if (dialog->statefrac < 0.1f) {
				dialog->statefrac += 0.04f;
			} else {
				dialog->state = MENUDIALOGSTATE_OPENING;
				dialog->redrawtimer = 0.0f;
				dialog->statefrac = 0.5f;
			}
		} else if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) && menuGetRoot() == MENUROOT_MPENDSCREEN) {
			if (var8009dfc0) {
#if VERSION >= VERSION_PAL_FINAL
				dialog->statefrac += g_Vars.diffframe240freal / 60.0f;
#else
				dialog->statefrac += g_Vars.diffframe240 / 60.0f;
#endif

				if (dialog->statefrac > 1.0f) {
					dialog->state = MENUDIALOGSTATE_OPENING;
					dialog->redrawtimer = 0.0f;
					dialog->statefrac = 0.5f;
				}
			}
		} else {
			if (g_MenuData.nextbg == 255 || g_MenuData.bg != 0) {
				dialog->state = MENUDIALOGSTATE_OPENING;
				dialog->redrawtimer = 0.0f;
				dialog->statefrac = 0.5f;
			}
		}
	}
#else
	if (dialog->state == MENUDIALOGSTATE_PREOPEN) {
		if (g_MenuData.nextbg == 255 || g_MenuData.bg != 0) {
			dialog->state = MENUDIALOGSTATE_OPENING;
			dialog->redrawtimer = 0.0f;
			dialog->statefrac = 0.5f;
		}
	}
#endif

	// Increment the redraw timer, which makes the contents fade and then get
	// redrawn. The initial draw is done faster than subsequent draws.
	if (dialog->redrawtimer < 0.0f) {
		// Redraw not active
	} else {
#if VERSION >= VERSION_PAL_FINAL
		if (dialog->state == MENUDIALOGSTATE_POPULATED) {
			dialog->redrawtimer += g_Vars.diffframe60freal + g_Vars.diffframe60freal;
		} else {
			dialog->redrawtimer += 5 * g_Vars.diffframe60freal;
		}
#else
		if (dialog->state == MENUDIALOGSTATE_POPULATED) {
			dialog->redrawtimer += 2 * g_Vars.diffframe60;
		} else {
			dialog->redrawtimer += 5 * g_Vars.diffframe60;
		}
#endif

		if (dialog->redrawtimer > 600.0f) {
			dialog->redrawtimer = -1.0f;
		}
	}

	if ((dialog->definition->flags & MENUDIALOGFLAG_DISABLERESIZE) == 0) {
		dialogCalculateContentSize(dialog->definition, dialog, menu);
	}

	dialogCalculatePosition(dialog);
	dialog0f0f1ef4(dialog);

	// Update slide
	if (g_MenuData.root == MENUROOT_MPPAUSE
			|| g_MenuData.root == MENUROOT_PICKTARGET
			|| g_MenuData.root == MENUROOT_MPENDSCREEN) {
		// Don't slide
		dialog->x = dialog->dstx;
		dialog->y = dialog->dsty;
	} else {
		// Slide X
		if (dialog->x != dialog->dstx) {
			oldx = dialog->x;
			newx = dialog->x;

			for (i = 0; i < g_Vars.diffframe60; i++) {
#if VERSION >= VERSION_PAL_FINAL
				newx = dialog->dstx * 0.348f + 0.652f * newx;
#else
				newx = dialog->dstx * 0.3f + 0.7f * newx;
#endif
			}

			dialog->x = newx;

			if (dialog->x != dialog->dstx && dialog->x == oldx) {
				if (dialog->x < dialog->dstx) {
					dialog->x++;
				} else {
					dialog->x--;
				}
			}
		}

		// Slide Y
		if (dialog->y != dialog->dsty) {
			oldy = dialog->y;
			newy = dialog->y;

			for (i = 0; i < g_Vars.diffframe60; i++) {
#if VERSION >= VERSION_PAL_FINAL
				newy = dialog->dsty * 0.348f + 0.652f * newy;
#else
				newy = dialog->dsty * 0.3f + 0.7f * newy;
#endif
			}

			dialog->y = newy;

			if (dialog->y != dialog->dsty && dialog->y == oldy) {
				if (dialog->y < dialog->dsty) {
					dialog->y++;
				} else {
					dialog->y--;
				}
			}
		}
	}

	// Tween the width
	if (dialog->width != dialog->dstwidth) {
		oldwidth = dialog->width;
		newwidth = dialog->width;

		for (i = 0; i < g_Vars.diffframe60; i++) {
#if VERSION >= VERSION_PAL_FINAL
			newwidth = dialog->dstwidth * 0.348f + 0.652f * newwidth;
#else
			newwidth = dialog->dstwidth * 0.3f + 0.7f * newwidth;
#endif
		}

		dialog->width = newwidth;

		if (dialog->width != dialog->dstwidth && dialog->width == oldwidth) {
			if (dialog->width < dialog->dstwidth) {
				dialog->width++;
			} else {
				dialog->width--;
			}
		}
	}

	// Tween the height
	if (dialog->height != dialog->dstheight) {
		s32 i;
		oldheight = dialog->height;
		newheight = dialog->height;

		for (i = 0; i < g_Vars.diffframe60; i++) {
#if VERSION >= VERSION_PAL_FINAL
			newheight = dialog->dstheight * 0.348f + 0.652f * newheight;
#else
			newheight = dialog->dstheight * 0.3f + 0.7f * newheight;
#endif
		}

		dialog->height = newheight;

		if (dialog->height != dialog->dstheight && dialog->height == oldheight) {
			if (dialog->height < dialog->dstheight) {
				dialog->height++;
			} else {
				dialog->height--;
			}
		}
	}

	// Call the dialog's tick handler, if any
	data.dialog2.inputs = inputs;

	if (definition->handler != NULL) {
		definition->handler(MENUOP_TICK, definition, &data);
	}

	if (dialog->dimmed) {
		dialog->unk10 += g_Vars.diffframe60;
	} else {
		dialog->unk10 = 0;
	}

	// Tick each item in the dialog
	{
		s32 j;

		for (col = 0; col < dialog->numcols; col++) {
			s32 colindex = dialog->colstart + col;

			for (j = 0; j < menu->cols[colindex].numrows; j++) {
				s32 rowindex = menu->cols[colindex].rowstart + j;
				struct menuitem *item = &dialog->definition->items[menu->rows[rowindex].itemindex];
				union menuitemdata *handlerdata = NULL;
				struct menuinputs *inputsptr = inputs;

				if (mpIsPlayerLockedOut(g_MpPlayerNum) && (item->flags & MENUITEMFLAG_00020000)) {
					inputsptr = &spd8;
				} else if ((item->flags & MENUITEMFLAG_00080000) && mpGetWeaponSet() != func0f189088()) {
					inputsptr = &spd8;
				} else if (g_MenuData.root == MENUROOT_12) {
					inputsptr = &spd8;
				}

				if (inputsptr);

				if (menu->rows[rowindex].blockindex != -1) {
					handlerdata = (union menuitemdata *)&menu->blocks[menu->rows[rowindex].blockindex];
				}

				if (g_Menus[g_MpPlayerNum].fm.unke40_00 == 0 && !g_MainIsDebugMenuOpen) {
					if ((tickflags & MENUTICKFLAG_DIALOGISCURRENT) && item == dialog->focuseditem) {
						u32 itemtickflags = tickflags | MENUTICKFLAG_ITEMISFOCUSED;

						if (dialog->dimmed) {
							usedefaultbehaviour = menuitemTick(item, dialog, inputsptr, itemtickflags | MENUTICKFLAG_DIALOGISDIMMED, handlerdata);
						} else {
							usedefaultbehaviour = menuitemTick(item, dialog, inputsptr, itemtickflags, handlerdata);
						}
					} else {
						menuitemTick(item, dialog, inputsptr, tickflags, handlerdata);
					}
				}
			}
		}
	}

	// If the focused item is disabled somehow, automatically jump to the next
	if (dialog->focuseditem
			&& menuIsItemDisabled(dialog->focuseditem, dialog)
			&& (tickflags & MENUTICKFLAG_DIALOGISCURRENT)) {
		usedefaultbehaviour = true;
		inputs->updown = 1;
		dialog->dimmed = false;
	}

	// Apply default navigational behaviour if requested
	if (usedefaultbehaviour && (tickflags & MENUTICKFLAG_DIALOGISCURRENT) && !dialog->dimmed) {
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];

		if (layer->numsiblings <= 1) {
			struct menuitem *prevfocuseditem = dialog->focuseditem;

			dialogChangeItemFocus(dialog, inputs->leftright, inputs->updown);

			if (dialog->focuseditem != prevfocuseditem) {
				menuPlaySound(MENUSOUND_FOCUS);
			}
		} else {
			struct menuitem *prevfocuseditem = dialog->focuseditem;
			s32 swipedir = dialogChangeItemFocus(dialog, inputs->leftright, inputs->updown);

			if (swipedir != 0) {
				menuSwipe(swipedir);
			} else if (prevfocuseditem != dialog->focuseditem) {
				menuPlaySound(MENUSOUND_FOCUS);
			}
		}

		if (inputs->back) {
			if ((dialog->definition->flags & MENUDIALOGFLAG_DROPOUTONCLOSE) && g_Vars.unk000498) {
				if (IS4MB()) {
					menuPushDialog(&g_MpDropOut4MbMenuDialog);
				} else {
					menuPushDialog(&g_MpDropOutMenuDialog);
				}
			} else if ((dialog->definition->flags & MENUDIALOGFLAG_IGNOREBACK) == 0) {
				menuPopDialog();
			}
		} else if (dialog->definition->flags & MENUDIALOGFLAG_CLOSEONSELECT) {
			if (dialog->state > MENUDIALOGSTATE_PREOPEN) {
				if ((inputs->select & 1) == 1 || (inputs->back & 1) == 1) {
					menuPopDialog();
				}
			}
		}
	}

	// Scrolling related (when the dialog is too big vertically)
	if (dialog->focuseditem && (dialog->definition->flags & MENUDIALOGFLAG_DISABLEITEMSCROLL) == 0) {
#if VERSION >= VERSION_NTSC_1_0
		s32 dstscroll;
		s32 itemy;
		s32 rowindex;
		s32 colindex;
#else
		s32 dstscroll;
		s32 rowindex;
		s32 colindex;
		s32 itemy;
#endif

		s32 y = dialogFindItem(dialog, dialog->focuseditem, &rowindex, &colindex);

		if ((dialog->focuseditem->flags & MENUITEMFLAG_00010000) == 0) {
			itemy = y + menu->rows[rowindex].height / 2;
			dstscroll = (dialog->height - 12) / 2 - itemy;

			if (dstscroll > 0) {
				dstscroll = 0;
			}

			if (dstscroll < dialog->height - dialog->contentheight) {
				dstscroll = dialog->height - dialog->contentheight;
			}

			dialog->dstscroll = dstscroll;
		} else {
			dialog->dstscroll = 0;
		}
	} else if (dialog->definition->flags & MENUDIALOGFLAG_SMOOTHSCROLLABLE) {
#if VERSION >= VERSION_PAL_FINAL
		s32 adjustment = (s32)(inputs->yaxis * g_Vars.diffframe60freal / 20) - (s32)(inputs->updownheld * g_Vars.diffframe60freal);
#else
		s32 adjustment = inputs->yaxis * g_Vars.diffframe60 / 20 - inputs->updownheld * g_Vars.diffframe60;
#endif
		dialog->dstscroll += adjustment;

		if (dialog->dstscroll > 0) {
			dialog->dstscroll = 0;
		}

		if (dialog->dstscroll < dialog->height - dialog->contentheight) {
			dialog->dstscroll = dialog->height - dialog->contentheight;
		}

		dialog->scroll = dialog->dstscroll;
	}

	{
		if (dialog->scroll != dialog->dstscroll) {
			s32 oldscroll = dialog->scroll;
			f32 newscroll = dialog->scroll;
			s32 i;

			for (i = 0; i < g_Vars.diffframe60; i++) {
#if VERSION >= VERSION_PAL_FINAL
				newscroll = (dialog->dstscroll * 0.235f) + (0.765f * newscroll);
#else
				newscroll = (dialog->dstscroll * 0.2f) + (0.8f * newscroll);
#endif
			}

			dialog->scroll = newscroll;

			if (dialog->scroll != dialog->dstscroll && dialog->scroll == oldscroll) {
				if (dialog->scroll < dialog->dstscroll) {
					dialog->scroll++;
				} else {
					dialog->scroll--;
				}
			}
		}
	}

	if (g_Menus[g_MpPlayerNum].fm.unke40_00 || g_MainIsDebugMenuOpen) {
		inputs->leftright = inputs->updown = inputs->select = inputs->back = inputs->xaxis = inputs->yaxis = inputs->shoulder = inputs->back2 = inputs->unk14 = 0;
		g_Menus[g_MpPlayerNum].fm.unke40_00 = false;
	}
}

void dialogInitItems(struct menudialog *dialog)
{
	struct menu *menu = &g_Menus[g_MpPlayerNum];
	s32 i;
	s32 j;

	for (i = 0; i < dialog->numcols; i++) {
		s32 colindex = dialog->colstart + i;

		for (j = 0; j < menu->cols[colindex].numrows; j++) {
			s32 rowindex = menu->cols[colindex].rowstart + j;
			struct menuitem *item = &dialog->definition->items[menu->rows[rowindex].itemindex];
			union menuitemdata *data = NULL;

			if (menu->rows[rowindex].blockindex != -1) {
				data = (union menuitemdata *)&menu->blocks[menu->rows[rowindex].blockindex];
			}

			menuitemInit(item, data);
		}
	}
}

void func0f0fa6ac(void)
{
	switch (g_MenuData.root) {
	case MENUROOT_MAINMENU:
	case MENUROOT_MPSETUP:
	case MENUROOT_FILEMGR:
	case MENUROOT_4MBMAINMENU:
	case MENUROOT_TRAINING:
		currentPlayerUnpause();
		g_PlayersWithControl[0] = true;
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel menuProcessInput
.late_rodata
glabel var7f1b2a98
.word menuProcessInput+0xd64
glabel var7f1b2a9c
.word menuProcessInput+0xd64
glabel var7f1b2aa0
.word menuProcessInput+0xc8c
glabel var7f1b2aa4
.word menuProcessInput+0xd14
glabel var7f1b2aa8
.word menuProcessInput+0xd64
glabel var7f1b2aac
.word menuProcessInput+0xda8
glabel var7f1b2ab0
.word menuProcessInput+0xda8
glabel var7f1b2ab4
.word menuProcessInput+0xda8
glabel var7f1b2ab8
.word menuProcessInput+0xda8
glabel var7f1b2abc
.word menuProcessInput+0xda8
glabel var7f1b2ac0
.word menuProcessInput+0xc8c
glabel var7f1b2ac4
.word menuProcessInput+0xda8
glabel var7f1b2ac8
.word menuProcessInput+0xd64
.text
/*  f0fae40:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0fae44:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0fae48:	3c178007 */ 	lui	$s7,0x8007
/*  f0fae4c:	26f71728 */ 	addiu	$s7,$s7,0x1728
/*  f0fae50:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0fae54:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0fae58:	241e0e70 */ 	li	$s8,0xe70
/*  f0fae5c:	01de0019 */ 	multu	$t6,$s8
/*  f0fae60:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0fae64:	3c16800a */ 	lui	$s6,0x800a
/*  f0fae68:	26d6e5a0 */ 	addiu	$s6,$s6,-6752
/*  f0fae6c:	3c19800a */ 	lui	$t9,0x800a
/*  f0fae70:	8f391f64 */ 	lw	$t9,0x1f64($t9)
/*  f0fae74:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0fae78:	24010004 */ 	li	$at,0x4
/*  f0fae7c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0fae80:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0fae84:	00007812 */ 	mflo	$t7
/*  f0fae88:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0fae8c:	8cf804f8 */ 	lw	$t8,0x4f8($a3)
/*  f0fae90:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0fae94:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0fae98:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0fae9c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0faea0:	00006025 */ 	move	$t4,$zero
/*  f0faea4:	00004825 */ 	move	$t1,$zero
/*  f0faea8:	00004025 */ 	move	$t0,$zero
/*  f0faeac:	0000a825 */ 	move	$s5,$zero
/*  f0faeb0:	afa0011c */ 	sw	$zero,0x11c($sp)
/*  f0faeb4:	afa700fc */ 	sw	$a3,0xfc($sp)
/*  f0faeb8:	17210005 */ 	bne	$t9,$at,.PF0f0faed0
/*  f0faebc:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f0faec0:	3c0e800a */ 	lui	$t6,0x800a
/*  f0faec4:	8dcea79c */ 	lw	$t6,-0x5864($t6)
/*  f0faec8:	3c01800a */ 	lui	$at,0x800a
/*  f0faecc:	ac2e2758 */ 	sw	$t6,0x2758($at)
.PF0f0faed0:
/*  f0faed0:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0faed4:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0faed8:	0fc3c6d1 */ 	jal	func0f0f1418
/*  f0faedc:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0faee0:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0faee4:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0faee8:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0faeec:	01fe0019 */ 	multu	$t7,$s8
/*  f0faef0:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0faef4:	a3a00106 */ 	sb	$zero,0x106($sp)
/*  f0faef8:	a3a00107 */ 	sb	$zero,0x107($sp)
/*  f0faefc:	a3a0010a */ 	sb	$zero,0x10a($sp)
/*  f0faf00:	a3a0010b */ 	sb	$zero,0x10b($sp)
/*  f0faf04:	00005025 */ 	move	$t2,$zero
/*  f0faf08:	00005825 */ 	move	$t3,$zero
/*  f0faf0c:	3c0f800a */ 	lui	$t7,0x800a
/*  f0faf10:	0000c012 */ 	mflo	$t8
/*  f0faf14:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f0faf18:	8f2e04f8 */ 	lw	$t6,0x4f8($t9)
/*  f0faf1c:	51c00333 */ 	beqzl	$t6,.PF0f0fbbec
/*  f0faf20:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0faf24:	8def1f64 */ 	lw	$t7,0x1f64($t7)
/*  f0faf28:	24010007 */ 	li	$at,0x7
/*  f0faf2c:	afa000f8 */ 	sw	$zero,0xf8($sp)
/*  f0faf30:	15e1000b */ 	bne	$t7,$at,.PF0f0faf60
/*  f0faf34:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f0faf38:	24180001 */ 	li	$t8,0x1
/*  f0faf3c:	24190002 */ 	li	$t9,0x2
/*  f0faf40:	240e0003 */ 	li	$t6,0x3
/*  f0faf44:	240f0004 */ 	li	$t7,0x4
/*  f0faf48:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f0faf4c:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f0faf50:	afb900e0 */ 	sw	$t9,0xe0($sp)
/*  f0faf54:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f0faf58:	1000001b */ 	b	.PF0f0fafc8
/*  f0faf5c:	afaf00ec */ 	sw	$t7,0xec($sp)
.PF0f0faf60:
/*  f0faf60:	27a400d7 */ 	addiu	$a0,$sp,0xd7
/*  f0faf64:	27a500d6 */ 	addiu	$a1,$sp,0xd6
/*  f0faf68:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0faf6c:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0faf70:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0faf74:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0faf78:	0fc3defb */ 	jal	menuGetContPads
/*  f0faf7c:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0faf80:	83a200d7 */ 	lb	$v0,0xd7($sp)
/*  f0faf84:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0faf88:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0faf8c:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0faf90:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0faf94:	04400004 */ 	bltz	$v0,.PF0f0fafa8
/*  f0faf98:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0faf9c:	24030001 */ 	li	$v1,0x1
/*  f0fafa0:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f0fafa4:	afa300ec */ 	sw	$v1,0xec($sp)
.PF0f0fafa8:
/*  f0fafa8:	83a200d6 */ 	lb	$v0,0xd6($sp)
/*  f0fafac:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0fafb0:	04400005 */ 	bltz	$v0,.PF0f0fafc8
/*  f0fafb4:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0fafb8:	03b8c821 */ 	addu	$t9,$sp,$t8
/*  f0fafbc:	af2200d8 */ 	sw	$v0,0xd8($t9)
/*  f0fafc0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fafc4:	afa300ec */ 	sw	$v1,0xec($sp)
.PF0f0fafc8:
/*  f0fafc8:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0fafcc:	01de0019 */ 	multu	$t6,$s8
/*  f0fafd0:	00007812 */ 	mflo	$t7
/*  f0fafd4:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0fafd8:	90e20e41 */ 	lbu	$v0,0xe41($a3)
/*  f0fafdc:	1840001a */ 	blez	$v0,.PF0f0fb048
/*  f0fafe0:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f0fafe4:	331900ff */ 	andi	$t9,$t8,0xff
/*  f0fafe8:	17200014 */ 	bnez	$t9,.PF0f0fb03c
/*  f0fafec:	a0f80e41 */ 	sb	$t8,0xe41($a3)
/*  f0faff0:	8cee0e48 */ 	lw	$t6,0xe48($a3)
/*  f0faff4:	8cef0e4c */ 	lw	$t7,0xe4c($a3)
/*  f0faff8:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0faffc:	2405ffff */ 	li	$a1,-1
/*  f0fb000:	00003025 */ 	move	$a2,$zero
/*  f0fb004:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fb008:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fb00c:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fb010:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fb014:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fb018:	afae00cc */ 	sw	$t6,0xcc($sp)
/*  f0fb01c:	0fc42793 */ 	jal	filemgrSaveOrLoad
/*  f0fb020:	a7af00d0 */ 	sh	$t7,0xd0($sp)
/*  f0fb024:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fb028:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fb02c:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fb030:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fb034:	10000004 */ 	b	.PF0f0fb048
/*  f0fb038:	8fac012c */ 	lw	$t4,0x12c($sp)
.PF0f0fb03c:
/*  f0fb03c:	90f90e40 */ 	lbu	$t9,0xe40($a3)
/*  f0fb040:	372e0080 */ 	ori	$t6,$t9,0x80
/*  f0fb044:	a0ee0e40 */ 	sb	$t6,0xe40($a3)
.PF0f0fb048:
/*  f0fb048:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f0fb04c:	0000a025 */ 	move	$s4,$zero
/*  f0fb050:	19e00083 */ 	blez	$t7,.PF0f0fb260
/*  f0fb054:	27b300d8 */ 	addiu	$s3,$sp,0xd8
.PF0f0fb058:
/*  f0fb058:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fb05c:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fb060:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fb064:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fb068:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fb06c:	0c0052e6 */ 	jal	joyGetStickX
/*  f0fb070:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fb074:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0fb078:	0010c603 */ 	sra	$t8,$s0,0x18
/*  f0fb07c:	03008025 */ 	move	$s0,$t8
/*  f0fb080:	0c005310 */ 	jal	joyGetStickY
/*  f0fb084:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fb088:	00028e00 */ 	sll	$s1,$v0,0x18
/*  f0fb08c:	0011ce03 */ 	sra	$t9,$s1,0x18
/*  f0fb090:	03208825 */ 	move	$s1,$t9
/*  f0fb094:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fb098:	0c00533a */ 	jal	joyGetButtons
/*  f0fb09c:	3405ffff */ 	li	$a1,0xffff
/*  f0fb0a0:	3052ffff */ 	andi	$s2,$v0,0xffff
/*  f0fb0a4:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fb0a8:	0c00536a */ 	jal	joyGetButtonsPressedThisFrame
/*  f0fb0ac:	3405ffff */ 	li	$a1,0xffff
/*  f0fb0b0:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0fb0b4:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fb0b8:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fb0bc:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fb0c0:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fb0c4:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0fb0c8:	11c00003 */ 	beqz	$t6,.PF0f0fb0d8
/*  f0fb0cc:	00403025 */ 	move	$a2,$v0
/*  f0fb0d0:	240f0001 */ 	li	$t7,0x1
/*  f0fb0d4:	a3af0106 */ 	sb	$t7,0x106($sp)
.PF0f0fb0d8:
/*  f0fb0d8:	30d84000 */ 	andi	$t8,$a2,0x4000
/*  f0fb0dc:	13000003 */ 	beqz	$t8,.PF0f0fb0ec
/*  f0fb0e0:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f0fb0e4:	24190001 */ 	li	$t9,0x1
/*  f0fb0e8:	a3b90107 */ 	sb	$t9,0x107($sp)
.PF0f0fb0ec:
/*  f0fb0ec:	11c00003 */ 	beqz	$t6,.PF0f0fb0fc
/*  f0fb0f0:	30d81000 */ 	andi	$t8,$a2,0x1000
/*  f0fb0f4:	240f0001 */ 	li	$t7,0x1
/*  f0fb0f8:	a3af0106 */ 	sb	$t7,0x106($sp)
.PF0f0fb0fc:
/*  f0fb0fc:	13000003 */ 	beqz	$t8,.PF0f0fb10c
/*  f0fb100:	324e0010 */ 	andi	$t6,$s2,0x10
/*  f0fb104:	24190001 */ 	li	$t9,0x1
/*  f0fb108:	afb900f8 */ 	sw	$t9,0xf8($sp)
.PF0f0fb10c:
/*  f0fb10c:	11c00003 */ 	beqz	$t6,.PF0f0fb11c
/*  f0fb110:	02402825 */ 	move	$a1,$s2
/*  f0fb114:	240f0001 */ 	li	$t7,0x1
/*  f0fb118:	a3af010a */ 	sb	$t7,0x10a($sp)
.PF0f0fb11c:
/*  f0fb11c:	30b80020 */ 	andi	$t8,$a1,0x20
/*  f0fb120:	13000003 */ 	beqz	$t8,.PF0f0fb130
/*  f0fb124:	30ae0008 */ 	andi	$t6,$a1,0x8
/*  f0fb128:	24190001 */ 	li	$t9,0x1
/*  f0fb12c:	a3b9010a */ 	sb	$t9,0x10a($sp)
.PF0f0fb130:
/*  f0fb130:	05410003 */ 	bgez	$t2,.PF0f0fb140
/*  f0fb134:	30cf0008 */ 	andi	$t7,$a2,0x8
/*  f0fb138:	10000002 */ 	b	.PF0f0fb144
/*  f0fb13c:	000a2023 */ 	negu	$a0,$t2
.PF0f0fb140:
/*  f0fb140:	01402025 */ 	move	$a0,$t2
.PF0f0fb144:
/*  f0fb144:	06010003 */ 	bgez	$s0,.PF0f0fb154
/*  f0fb148:	30b80004 */ 	andi	$t8,$a1,0x4
/*  f0fb14c:	10000002 */ 	b	.PF0f0fb158
/*  f0fb150:	00101823 */ 	negu	$v1,$s0
.PF0f0fb154:
/*  f0fb154:	02001825 */ 	move	$v1,$s0
.PF0f0fb158:
/*  f0fb158:	0083082a */ 	slt	$at,$a0,$v1
/*  f0fb15c:	10200002 */ 	beqz	$at,.PF0f0fb168
/*  f0fb160:	30d90004 */ 	andi	$t9,$a2,0x4
/*  f0fb164:	02005025 */ 	move	$t2,$s0
.PF0f0fb168:
/*  f0fb168:	05610003 */ 	bgez	$t3,.PF0f0fb178
/*  f0fb16c:	01602025 */ 	move	$a0,$t3
/*  f0fb170:	10000001 */ 	b	.PF0f0fb178
/*  f0fb174:	000b2023 */ 	negu	$a0,$t3
.PF0f0fb178:
/*  f0fb178:	06210003 */ 	bgez	$s1,.PF0f0fb188
/*  f0fb17c:	02201825 */ 	move	$v1,$s1
/*  f0fb180:	10000001 */ 	b	.PF0f0fb188
/*  f0fb184:	00111823 */ 	negu	$v1,$s1
.PF0f0fb188:
/*  f0fb188:	0083082a */ 	slt	$at,$a0,$v1
/*  f0fb18c:	10200002 */ 	beqz	$at,.PF0f0fb198
/*  f0fb190:	00000000 */ 	nop
/*  f0fb194:	02205825 */ 	move	$t3,$s1
.PF0f0fb198:
/*  f0fb198:	11c00002 */ 	beqz	$t6,.PF0f0fb1a4
/*  f0fb19c:	00000000 */ 	nop
/*  f0fb1a0:	240cffff */ 	li	$t4,-1
.PF0f0fb1a4:
/*  f0fb1a4:	11e00002 */ 	beqz	$t7,.PF0f0fb1b0
/*  f0fb1a8:	30ae0002 */ 	andi	$t6,$a1,0x2
/*  f0fb1ac:	2408ffff */ 	li	$t0,-1
.PF0f0fb1b0:
/*  f0fb1b0:	13000002 */ 	beqz	$t8,.PF0f0fb1bc
/*  f0fb1b4:	30cf0002 */ 	andi	$t7,$a2,0x2
/*  f0fb1b8:	240c0001 */ 	li	$t4,0x1
.PF0f0fb1bc:
/*  f0fb1bc:	13200002 */ 	beqz	$t9,.PF0f0fb1c8
/*  f0fb1c0:	30b80001 */ 	andi	$t8,$a1,0x1
/*  f0fb1c4:	24080001 */ 	li	$t0,0x1
.PF0f0fb1c8:
/*  f0fb1c8:	11c00002 */ 	beqz	$t6,.PF0f0fb1d4
/*  f0fb1cc:	30d90001 */ 	andi	$t9,$a2,0x1
/*  f0fb1d0:	2409ffff */ 	li	$t1,-1
.PF0f0fb1d4:
/*  f0fb1d4:	11e00002 */ 	beqz	$t7,.PF0f0fb1e0
/*  f0fb1d8:	30ae0800 */ 	andi	$t6,$a1,0x800
/*  f0fb1dc:	2415ffff */ 	li	$s5,-1
.PF0f0fb1e0:
/*  f0fb1e0:	13000002 */ 	beqz	$t8,.PF0f0fb1ec
/*  f0fb1e4:	30cf0800 */ 	andi	$t7,$a2,0x800
/*  f0fb1e8:	24090001 */ 	li	$t1,0x1
.PF0f0fb1ec:
/*  f0fb1ec:	13200002 */ 	beqz	$t9,.PF0f0fb1f8
/*  f0fb1f0:	30b80400 */ 	andi	$t8,$a1,0x400
/*  f0fb1f4:	24150001 */ 	li	$s5,0x1
.PF0f0fb1f8:
/*  f0fb1f8:	11c00002 */ 	beqz	$t6,.PF0f0fb204
/*  f0fb1fc:	30d90400 */ 	andi	$t9,$a2,0x400
/*  f0fb200:	240cffff */ 	li	$t4,-1
.PF0f0fb204:
/*  f0fb204:	11e00002 */ 	beqz	$t7,.PF0f0fb210
/*  f0fb208:	30ae0200 */ 	andi	$t6,$a1,0x200
/*  f0fb20c:	2408ffff */ 	li	$t0,-1
.PF0f0fb210:
/*  f0fb210:	13000002 */ 	beqz	$t8,.PF0f0fb21c
/*  f0fb214:	30cf0200 */ 	andi	$t7,$a2,0x200
/*  f0fb218:	240c0001 */ 	li	$t4,0x1
.PF0f0fb21c:
/*  f0fb21c:	13200002 */ 	beqz	$t9,.PF0f0fb228
/*  f0fb220:	30b80100 */ 	andi	$t8,$a1,0x100
/*  f0fb224:	24080001 */ 	li	$t0,0x1
.PF0f0fb228:
/*  f0fb228:	11c00002 */ 	beqz	$t6,.PF0f0fb234
/*  f0fb22c:	30d90100 */ 	andi	$t9,$a2,0x100
/*  f0fb230:	2409ffff */ 	li	$t1,-1
.PF0f0fb234:
/*  f0fb234:	11e00002 */ 	beqz	$t7,.PF0f0fb240
/*  f0fb238:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f0fb23c:	2415ffff */ 	li	$s5,-1
.PF0f0fb240:
/*  f0fb240:	13000002 */ 	beqz	$t8,.PF0f0fb24c
/*  f0fb244:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0fb248:	24090001 */ 	li	$t1,0x1
.PF0f0fb24c:
/*  f0fb24c:	13200002 */ 	beqz	$t9,.PF0f0fb258
/*  f0fb250:	00000000 */ 	nop
/*  f0fb254:	24150001 */ 	li	$s5,0x1
.PF0f0fb258:
/*  f0fb258:	168eff7f */ 	bne	$s4,$t6,.PF0f0fb058
/*  f0fb25c:	26730004 */ 	addiu	$s3,$s3,0x4
.PF0f0fb260:
/*  f0fb260:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0fb264:	93ae0106 */ 	lbu	$t6,0x106($sp)
/*  f0fb268:	24100008 */ 	li	$s0,0x8
/*  f0fb26c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0fb270:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fb274:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fb278:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0fb27c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fb280:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fb284:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fb288:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f0fb28c:	11c00002 */ 	beqz	$t6,.PF0f0fb298
/*  f0fb290:	8f2404f8 */ 	lw	$a0,0x4f8($t9)
/*  f0fb294:	a3a00107 */ 	sb	$zero,0x107($sp)
.PF0f0fb298:
/*  f0fb298:	11000002 */ 	beqz	$t0,.PF0f0fb2a4
/*  f0fb29c:	2406001e */ 	li	$a2,0x1e
/*  f0fb2a0:	01006025 */ 	move	$t4,$t0
.PF0f0fb2a4:
/*  f0fb2a4:	12a00002 */ 	beqz	$s5,.PF0f0fb2b0
/*  f0fb2a8:	2413003c */ 	li	$s3,0x3c
/*  f0fb2ac:	02a04825 */ 	move	$t1,$s5
.PF0f0fb2b0:
/*  f0fb2b0:	24110021 */ 	li	$s1,0x21
/*  f0fb2b4:	2414002c */ 	li	$s4,0x2c
/*  f0fb2b8:	10800019 */ 	beqz	$a0,.PF0f0fb320
/*  f0fb2bc:	00009025 */ 	move	$s2,$zero
/*  f0fb2c0:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f0fb2c4:	10400016 */ 	beqz	$v0,.PF0f0fb320
/*  f0fb2c8:	00000000 */ 	nop
/*  f0fb2cc:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0fb2d0:	24010008 */ 	li	$at,0x8
/*  f0fb2d4:	10610003 */ 	beq	$v1,$at,.PF0f0fb2e4
/*  f0fb2d8:	24010010 */ 	li	$at,0x10
/*  f0fb2dc:	54610009 */ 	bnel	$v1,$at,.PF0f0fb304
/*  f0fb2e0:	2401000d */ 	li	$at,0xd
.PF0f0fb2e4:
/*  f0fb2e4:	8c8f000c */ 	lw	$t7,0xc($a0)
/*  f0fb2e8:	51e00006 */ 	beqzl	$t7,.PF0f0fb304
/*  f0fb2ec:	2401000d */ 	li	$at,0xd
/*  f0fb2f0:	24100004 */ 	li	$s0,0x4
/*  f0fb2f4:	24060014 */ 	li	$a2,0x14
/*  f0fb2f8:	2413001e */ 	li	$s3,0x1e
/*  f0fb2fc:	2411000a */ 	li	$s1,0xa
/*  f0fb300:	2401000d */ 	li	$at,0xd
.PF0f0fb304:
/*  f0fb304:	14610006 */ 	bne	$v1,$at,.PF0f0fb320
/*  f0fb308:	00000000 */ 	nop
/*  f0fb30c:	24120001 */ 	li	$s2,0x1
/*  f0fb310:	24100004 */ 	li	$s0,0x4
/*  f0fb314:	24060014 */ 	li	$a2,0x14
/*  f0fb318:	2411000a */ 	li	$s1,0xa
/*  f0fb31c:	2414000a */ 	li	$s4,0xa
.PF0f0fb320:
/*  f0fb320:	15200004 */ 	bnez	$t1,.PF0f0fb334
/*  f0fb324:	0000f825 */ 	move	$ra,$zero
/*  f0fb328:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb32c:	2418ffff */ 	li	$t8,-1
/*  f0fb330:	a478082c */ 	sh	$t8,0x82c($v1)
.PF0f0fb334:
/*  f0fb334:	12a00006 */ 	beqz	$s5,.PF0f0fb350
/*  f0fb338:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb33c:	a460082c */ 	sh	$zero,0x82c($v1)
/*  f0fb340:	ac600824 */ 	sw	$zero,0x824($v1)
/*  f0fb344:	a475082a */ 	sh	$s5,0x82a($v1)
/*  f0fb348:	10000004 */ 	b	.PF0f0fb35c
/*  f0fb34c:	241f0001 */ 	li	$ra,0x1
.PF0f0fb350:
/*  f0fb350:	51200003 */ 	beqzl	$t1,.PF0f0fb360
/*  f0fb354:	8c620824 */ 	lw	$v0,0x824($v1)
/*  f0fb358:	8469082a */ 	lh	$t1,0x82a($v1)
.PF0f0fb35c:
/*  f0fb35c:	8c620824 */ 	lw	$v0,0x824($v1)
.PF0f0fb360:
/*  f0fb360:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fb364:	28410033 */ 	slti	$at,$v0,0x33
/*  f0fb368:	14200004 */ 	bnez	$at,.PF0f0fb37c
/*  f0fb36c:	00000000 */ 	nop
/*  f0fb370:	24190001 */ 	li	$t9,0x1
/*  f0fb374:	a479082c */ 	sh	$t9,0x82c($v1)
/*  f0fb378:	8c620824 */ 	lw	$v0,0x824($v1)
.PF0f0fb37c:
/*  f0fb37c:	0050001a */ 	div	$zero,$v0,$s0
/*  f0fb380:	8dcea510 */ 	lw	$t6,-0x5af0($t6)
/*  f0fb384:	00003812 */ 	mflo	$a3
/*  f0fb388:	8478082c */ 	lh	$t8,0x82c($v1)
/*  f0fb38c:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0fb390:	01f0001a */ 	div	$zero,$t7,$s0
/*  f0fb394:	16000002 */ 	bnez	$s0,.PF0f0fb3a0
/*  f0fb398:	00000000 */ 	nop
/*  f0fb39c:	0007000d */ 	break	0x7
.PF0f0fb3a0:
/*  f0fb3a0:	2401ffff */ 	li	$at,-1
/*  f0fb3a4:	16010004 */ 	bne	$s0,$at,.PF0f0fb3b8
/*  f0fb3a8:	3c018000 */ 	lui	$at,0x8000
/*  f0fb3ac:	14410002 */ 	bne	$v0,$at,.PF0f0fb3b8
/*  f0fb3b0:	00000000 */ 	nop
/*  f0fb3b4:	0006000d */ 	break	0x6
.PF0f0fb3b8:
/*  f0fb3b8:	00006812 */ 	mflo	$t5
/*  f0fb3bc:	16000002 */ 	bnez	$s0,.PF0f0fb3c8
/*  f0fb3c0:	00000000 */ 	nop
/*  f0fb3c4:	0007000d */ 	break	0x7
.PF0f0fb3c8:
/*  f0fb3c8:	2401ffff */ 	li	$at,-1
/*  f0fb3cc:	16010004 */ 	bne	$s0,$at,.PF0f0fb3e0
/*  f0fb3d0:	3c018000 */ 	lui	$at,0x8000
/*  f0fb3d4:	15e10002 */ 	bne	$t7,$at,.PF0f0fb3e0
/*  f0fb3d8:	00000000 */ 	nop
/*  f0fb3dc:	0006000d */ 	break	0x6
.PF0f0fb3e0:
/*  f0fb3e0:	1700000b */ 	bnez	$t8,.PF0f0fb410
/*  f0fb3e4:	00000000 */ 	nop
/*  f0fb3e8:	04e10003 */ 	bgez	$a3,.PF0f0fb3f8
/*  f0fb3ec:	0007c843 */ 	sra	$t9,$a3,0x1
/*  f0fb3f0:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0fb3f4:	0001c843 */ 	sra	$t9,$at,0x1
.PF0f0fb3f8:
/*  f0fb3f8:	03203825 */ 	move	$a3,$t9
/*  f0fb3fc:	05a10003 */ 	bgez	$t5,.PF0f0fb40c
/*  f0fb400:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f0fb404:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f0fb408:	00017043 */ 	sra	$t6,$at,0x1
.PF0f0fb40c:
/*  f0fb40c:	01c06825 */ 	move	$t5,$t6
.PF0f0fb410:
/*  f0fb410:	05410003 */ 	bgez	$t2,.PF0f0fb420
/*  f0fb414:	a3a9010c */ 	sb	$t1,0x10c($sp)
/*  f0fb418:	10000002 */ 	b	.PF0f0fb424
/*  f0fb41c:	000a1023 */ 	negu	$v0,$t2
.PF0f0fb420:
/*  f0fb420:	01401025 */ 	move	$v0,$t2
.PF0f0fb424:
/*  f0fb424:	05610003 */ 	bgez	$t3,.PF0f0fb434
/*  f0fb428:	0046082a */ 	slt	$at,$v0,$a2
/*  f0fb42c:	10000002 */ 	b	.PF0f0fb438
/*  f0fb430:	000b1823 */ 	negu	$v1,$t3
.PF0f0fb434:
/*  f0fb434:	01601825 */ 	move	$v1,$t3
.PF0f0fb438:
/*  f0fb438:	14200070 */ 	bnez	$at,.PF0f0fb5fc
/*  f0fb43c:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fb440:	14200003 */ 	bnez	$at,.PF0f0fb450
/*  f0fb444:	00000000 */ 	nop
/*  f0fb448:	5240006d */ 	beqzl	$s2,.PF0f0fb600
/*  f0fb44c:	8fae00fc */ 	lw	$t6,0xfc($sp)
.PF0f0fb450:
/*  f0fb450:	05410006 */ 	bgez	$t2,.PF0f0fb46c
/*  f0fb454:	28410047 */ 	slti	$at,$v0,0x47
/*  f0fb458:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb45c:	846f0828 */ 	lh	$t7,0x828($v1)
/*  f0fb460:	59e00003 */ 	blezl	$t7,.PF0f0fb470
/*  f0fb464:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb468:	a4600828 */ 	sh	$zero,0x828($v1)
.PF0f0fb46c:
/*  f0fb46c:	8fa300fc */ 	lw	$v1,0xfc($sp)
.PF0f0fb470:
/*  f0fb470:	19400005 */ 	blez	$t2,.PF0f0fb488
/*  f0fb474:	84650828 */ 	lh	$a1,0x828($v1)
/*  f0fb478:	04a10003 */ 	bgez	$a1,.PF0f0fb488
/*  f0fb47c:	00000000 */ 	nop
/*  f0fb480:	a4600828 */ 	sh	$zero,0x828($v1)
/*  f0fb484:	84650828 */ 	lh	$a1,0x828($v1)
.PF0f0fb488:
/*  f0fb488:	14a00003 */ 	bnez	$a1,.PF0f0fb498
/*  f0fb48c:	00000000 */ 	nop
/*  f0fb490:	ac600824 */ 	sw	$zero,0x824($v1)
/*  f0fb494:	84650828 */ 	lh	$a1,0x828($v1)
.PF0f0fb498:
/*  f0fb498:	54200003 */ 	bnezl	$at,.PF0f0fb4a8
/*  f0fb49c:	00461023 */ 	subu	$v0,$v0,$a2
/*  f0fb4a0:	24020046 */ 	li	$v0,0x46
/*  f0fb4a4:	00461023 */ 	subu	$v0,$v0,$a2
.PF0f0fb4a8:
/*  f0fb4a8:	02220019 */ 	multu	$s1,$v0
/*  f0fb4ac:	24190046 */ 	li	$t9,0x46
/*  f0fb4b0:	03267023 */ 	subu	$t6,$t9,$a2
/*  f0fb4b4:	0000c012 */ 	mflo	$t8
/*  f0fb4b8:	00000000 */ 	nop
/*  f0fb4bc:	00000000 */ 	nop
/*  f0fb4c0:	030e001a */ 	div	$zero,$t8,$t6
/*  f0fb4c4:	15c00002 */ 	bnez	$t6,.PF0f0fb4d0
/*  f0fb4c8:	00000000 */ 	nop
/*  f0fb4cc:	0007000d */ 	break	0x7
.PF0f0fb4d0:
/*  f0fb4d0:	2401ffff */ 	li	$at,-1
/*  f0fb4d4:	15c10004 */ 	bne	$t6,$at,.PF0f0fb4e8
/*  f0fb4d8:	3c018000 */ 	lui	$at,0x8000
/*  f0fb4dc:	17010002 */ 	bne	$t8,$at,.PF0f0fb4e8
/*  f0fb4e0:	00000000 */ 	nop
/*  f0fb4e4:	0006000d */ 	break	0x6
.PF0f0fb4e8:
/*  f0fb4e8:	00007812 */ 	mflo	$t7
/*  f0fb4ec:	026f2023 */ 	subu	$a0,$s3,$t7
/*  f0fb4f0:	28a10003 */ 	slti	$at,$a1,0x3
/*  f0fb4f4:	10200004 */ 	beqz	$at,.PF0f0fb508
/*  f0fb4f8:	00801825 */ 	move	$v1,$a0
/*  f0fb4fc:	28a1fffe */ 	slti	$at,$a1,-2
/*  f0fb500:	10200005 */ 	beqz	$at,.PF0f0fb518
/*  f0fb504:	00000000 */ 	nop
.PF0f0fb508:
/*  f0fb508:	04810003 */ 	bgez	$a0,.PF0f0fb518
/*  f0fb50c:	00041843 */ 	sra	$v1,$a0,0x1
/*  f0fb510:	24810001 */ 	addiu	$at,$a0,0x1
/*  f0fb514:	00011843 */ 	sra	$v1,$at,0x1
.PF0f0fb518:
/*  f0fb518:	1860003a */ 	blez	$v1,.PF0f0fb604
/*  f0fb51c:	28610004 */ 	slti	$at,$v1,0x4
/*  f0fb520:	3c06800a */ 	lui	$a2,0x800a
/*  f0fb524:	1420000b */ 	bnez	$at,.PF0f0fb554
/*  f0fb528:	8cc6a510 */ 	lw	$a2,-0x5af0($a2)
/*  f0fb52c:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0fb530:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb534:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fb538:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f0fb53c:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f0fb540:	2401003c */ 	li	$at,0x3c
/*  f0fb544:	0321001a */ 	div	$zero,$t9,$at
/*  f0fb548:	0000c012 */ 	mflo	$t8
/*  f0fb54c:	03001825 */ 	move	$v1,$t8
/*  f0fb550:	00000000 */ 	nop
.PF0f0fb554:
/*  f0fb554:	8fae00fc */ 	lw	$t6,0xfc($sp)
/*  f0fb558:	24090001 */ 	li	$t1,0x1
/*  f0fb55c:	8dc20824 */ 	lw	$v0,0x824($t6)
/*  f0fb560:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fb564:	00467821 */ 	addu	$t7,$v0,$a2
/*  f0fb568:	00003812 */ 	mflo	$a3
/*  f0fb56c:	14600002 */ 	bnez	$v1,.PF0f0fb578
/*  f0fb570:	00000000 */ 	nop
/*  f0fb574:	0007000d */ 	break	0x7
.PF0f0fb578:
/*  f0fb578:	2401ffff */ 	li	$at,-1
/*  f0fb57c:	14610004 */ 	bne	$v1,$at,.PF0f0fb590
/*  f0fb580:	3c018000 */ 	lui	$at,0x8000
/*  f0fb584:	14410002 */ 	bne	$v0,$at,.PF0f0fb590
/*  f0fb588:	00000000 */ 	nop
/*  f0fb58c:	0006000d */ 	break	0x6
.PF0f0fb590:
/*  f0fb590:	01e3001a */ 	div	$zero,$t7,$v1
/*  f0fb594:	00006812 */ 	mflo	$t5
/*  f0fb598:	14600002 */ 	bnez	$v1,.PF0f0fb5a4
/*  f0fb59c:	00000000 */ 	nop
/*  f0fb5a0:	0007000d */ 	break	0x7
.PF0f0fb5a4:
/*  f0fb5a4:	2401ffff */ 	li	$at,-1
/*  f0fb5a8:	14610004 */ 	bne	$v1,$at,.PF0f0fb5bc
/*  f0fb5ac:	3c018000 */ 	lui	$at,0x8000
/*  f0fb5b0:	15e10002 */ 	bne	$t7,$at,.PF0f0fb5bc
/*  f0fb5b4:	00000000 */ 	nop
/*  f0fb5b8:	0006000d */ 	break	0x6
.PF0f0fb5bc:
/*  f0fb5bc:	05410003 */ 	bgez	$t2,.PF0f0fb5cc
/*  f0fb5c0:	00000000 */ 	nop
/*  f0fb5c4:	10000001 */ 	b	.PF0f0fb5cc
/*  f0fb5c8:	2409ffff */ 	li	$t1,-1
.PF0f0fb5cc:
/*  f0fb5cc:	10ed0002 */ 	beq	$a3,$t5,.PF0f0fb5d8
/*  f0fb5d0:	00000000 */ 	nop
/*  f0fb5d4:	241f0001 */ 	li	$ra,0x1
.PF0f0fb5d8:
/*  f0fb5d8:	14a00002 */ 	bnez	$a1,.PF0f0fb5e4
/*  f0fb5dc:	00000000 */ 	nop
/*  f0fb5e0:	241f0001 */ 	li	$ra,0x1
.PF0f0fb5e4:
/*  f0fb5e4:	13e00007 */ 	beqz	$ra,.PF0f0fb604
/*  f0fb5e8:	00000000 */ 	nop
/*  f0fb5ec:	8fb800fc */ 	lw	$t8,0xfc($sp)
/*  f0fb5f0:	00a9c821 */ 	addu	$t9,$a1,$t1
/*  f0fb5f4:	10000003 */ 	b	.PF0f0fb604
/*  f0fb5f8:	a7190828 */ 	sh	$t9,0x828($t8)
.PF0f0fb5fc:
/*  f0fb5fc:	8fae00fc */ 	lw	$t6,0xfc($sp)
.PF0f0fb600:
/*  f0fb600:	a5c00828 */ 	sh	$zero,0x828($t6)
.PF0f0fb604:
/*  f0fb604:	10ed0002 */ 	beq	$a3,$t5,.PF0f0fb610
/*  f0fb608:	3c18800a */ 	lui	$t8,0x800a
/*  f0fb60c:	241f0001 */ 	li	$ra,0x1
.PF0f0fb610:
/*  f0fb610:	17e00002 */ 	bnez	$ra,.PF0f0fb61c
/*  f0fb614:	00000000 */ 	nop
/*  f0fb618:	00004825 */ 	move	$t1,$zero
.PF0f0fb61c:
/*  f0fb61c:	11000007 */ 	beqz	$t0,.PF0f0fb63c
/*  f0fb620:	00006825 */ 	move	$t5,$zero
/*  f0fb624:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb628:	240d0001 */ 	li	$t5,0x1
/*  f0fb62c:	a4600838 */ 	sh	$zero,0x838($v1)
/*  f0fb630:	ac600830 */ 	sw	$zero,0x830($v1)
/*  f0fb634:	10000005 */ 	b	.PF0f0fb64c
/*  f0fb638:	a4680836 */ 	sh	$t0,0x836($v1)
.PF0f0fb63c:
/*  f0fb63c:	51800004 */ 	beqzl	$t4,.PF0f0fb650
/*  f0fb640:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb644:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f0fb648:	85ec0836 */ 	lh	$t4,0x836($t7)
.PF0f0fb64c:
/*  f0fb64c:	8fa300fc */ 	lw	$v1,0xfc($sp)
.PF0f0fb650:
/*  f0fb650:	8c620830 */ 	lw	$v0,0x830($v1)
/*  f0fb654:	28410033 */ 	slti	$at,$v0,0x33
/*  f0fb658:	14200004 */ 	bnez	$at,.PF0f0fb66c
/*  f0fb65c:	00000000 */ 	nop
/*  f0fb660:	24190001 */ 	li	$t9,0x1
/*  f0fb664:	a4790838 */ 	sh	$t9,0x838($v1)
/*  f0fb668:	8c620830 */ 	lw	$v0,0x830($v1)
.PF0f0fb66c:
/*  f0fb66c:	0050001a */ 	div	$zero,$v0,$s0
/*  f0fb670:	8f18a510 */ 	lw	$t8,-0x5af0($t8)
/*  f0fb674:	00003812 */ 	mflo	$a3
/*  f0fb678:	846f0838 */ 	lh	$t7,0x838($v1)
/*  f0fb67c:	00587021 */ 	addu	$t6,$v0,$t8
/*  f0fb680:	01d0001a */ 	div	$zero,$t6,$s0
/*  f0fb684:	16000002 */ 	bnez	$s0,.PF0f0fb690
/*  f0fb688:	00000000 */ 	nop
/*  f0fb68c:	0007000d */ 	break	0x7
.PF0f0fb690:
/*  f0fb690:	2401ffff */ 	li	$at,-1
/*  f0fb694:	16010004 */ 	bne	$s0,$at,.PF0f0fb6a8
/*  f0fb698:	3c018000 */ 	lui	$at,0x8000
/*  f0fb69c:	14410002 */ 	bne	$v0,$at,.PF0f0fb6a8
/*  f0fb6a0:	00000000 */ 	nop
/*  f0fb6a4:	0006000d */ 	break	0x6
.PF0f0fb6a8:
/*  f0fb6a8:	00004012 */ 	mflo	$t0
/*  f0fb6ac:	01601025 */ 	move	$v0,$t3
/*  f0fb6b0:	16000002 */ 	bnez	$s0,.PF0f0fb6bc
/*  f0fb6b4:	00000000 */ 	nop
/*  f0fb6b8:	0007000d */ 	break	0x7
.PF0f0fb6bc:
/*  f0fb6bc:	2401ffff */ 	li	$at,-1
/*  f0fb6c0:	16010004 */ 	bne	$s0,$at,.PF0f0fb6d4
/*  f0fb6c4:	3c018000 */ 	lui	$at,0x8000
/*  f0fb6c8:	15c10002 */ 	bne	$t6,$at,.PF0f0fb6d4
/*  f0fb6cc:	00000000 */ 	nop
/*  f0fb6d0:	0006000d */ 	break	0x6
.PF0f0fb6d4:
/*  f0fb6d4:	15e0000b */ 	bnez	$t7,.PF0f0fb704
/*  f0fb6d8:	00000000 */ 	nop
/*  f0fb6dc:	04e10003 */ 	bgez	$a3,.PF0f0fb6ec
/*  f0fb6e0:	0007c843 */ 	sra	$t9,$a3,0x1
/*  f0fb6e4:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0fb6e8:	0001c843 */ 	sra	$t9,$at,0x1
.PF0f0fb6ec:
/*  f0fb6ec:	03203825 */ 	move	$a3,$t9
/*  f0fb6f0:	05010003 */ 	bgez	$t0,.PF0f0fb700
/*  f0fb6f4:	0008c043 */ 	sra	$t8,$t0,0x1
/*  f0fb6f8:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0fb6fc:	0001c043 */ 	sra	$t8,$at,0x1
.PF0f0fb700:
/*  f0fb700:	03004025 */ 	move	$t0,$t8
.PF0f0fb704:
/*  f0fb704:	05610003 */ 	bgez	$t3,.PF0f0fb714
/*  f0fb708:	a3ac010d */ 	sb	$t4,0x10d($sp)
/*  f0fb70c:	10000001 */ 	b	.PF0f0fb714
/*  f0fb710:	000b1023 */ 	negu	$v0,$t3
.PF0f0fb714:
/*  f0fb714:	05410003 */ 	bgez	$t2,.PF0f0fb724
/*  f0fb718:	28410014 */ 	slti	$at,$v0,0x14
/*  f0fb71c:	10000002 */ 	b	.PF0f0fb728
/*  f0fb720:	000a1823 */ 	negu	$v1,$t2
.PF0f0fb724:
/*  f0fb724:	01401825 */ 	move	$v1,$t2
.PF0f0fb728:
/*  f0fb728:	14200067 */ 	bnez	$at,.PF0f0fb8c8
/*  f0fb72c:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fb730:	14200003 */ 	bnez	$at,.PF0f0fb740
/*  f0fb734:	3c06800a */ 	lui	$a2,0x800a
/*  f0fb738:	52400064 */ 	beqzl	$s2,.PF0f0fb8cc
/*  f0fb73c:	8fa300fc */ 	lw	$v1,0xfc($sp)
.PF0f0fb740:
/*  f0fb740:	05610006 */ 	bgez	$t3,.PF0f0fb75c
/*  f0fb744:	28410047 */ 	slti	$at,$v0,0x47
/*  f0fb748:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb74c:	846e0834 */ 	lh	$t6,0x834($v1)
/*  f0fb750:	05c30003 */ 	bgezl	$t6,.PF0f0fb760
/*  f0fb754:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb758:	a4600834 */ 	sh	$zero,0x834($v1)
.PF0f0fb75c:
/*  f0fb75c:	8fa300fc */ 	lw	$v1,0xfc($sp)
.PF0f0fb760:
/*  f0fb760:	19600005 */ 	blez	$t3,.PF0f0fb778
/*  f0fb764:	84650834 */ 	lh	$a1,0x834($v1)
/*  f0fb768:	18a00003 */ 	blez	$a1,.PF0f0fb778
/*  f0fb76c:	00000000 */ 	nop
/*  f0fb770:	a4600834 */ 	sh	$zero,0x834($v1)
/*  f0fb774:	84650834 */ 	lh	$a1,0x834($v1)
.PF0f0fb778:
/*  f0fb778:	14a00003 */ 	bnez	$a1,.PF0f0fb788
/*  f0fb77c:	00000000 */ 	nop
/*  f0fb780:	ac600830 */ 	sw	$zero,0x830($v1)
/*  f0fb784:	84650834 */ 	lh	$a1,0x834($v1)
.PF0f0fb788:
/*  f0fb788:	14200002 */ 	bnez	$at,.PF0f0fb794
/*  f0fb78c:	8cc6a510 */ 	lw	$a2,-0x5af0($a2)
/*  f0fb790:	24020046 */ 	li	$v0,0x46
.PF0f0fb794:
/*  f0fb794:	2442ffec */ 	addiu	$v0,$v0,-20
/*  f0fb798:	02820019 */ 	multu	$s4,$v0
/*  f0fb79c:	24010032 */ 	li	$at,0x32
/*  f0fb7a0:	00007812 */ 	mflo	$t7
/*  f0fb7a4:	00000000 */ 	nop
/*  f0fb7a8:	00000000 */ 	nop
/*  f0fb7ac:	01e1001a */ 	div	$zero,$t7,$at
/*  f0fb7b0:	0000c812 */ 	mflo	$t9
/*  f0fb7b4:	02792023 */ 	subu	$a0,$s3,$t9
/*  f0fb7b8:	28a10003 */ 	slti	$at,$a1,0x3
/*  f0fb7bc:	10200003 */ 	beqz	$at,.PF0f0fb7cc
/*  f0fb7c0:	00801825 */ 	move	$v1,$a0
/*  f0fb7c4:	28a1fffe */ 	slti	$at,$a1,-2
/*  f0fb7c8:	10200005 */ 	beqz	$at,.PF0f0fb7e0
.PF0f0fb7cc:
/*  f0fb7cc:	24010003 */ 	li	$at,0x3
/*  f0fb7d0:	0081001a */ 	div	$zero,$a0,$at
/*  f0fb7d4:	00001812 */ 	mflo	$v1
/*  f0fb7d8:	00000000 */ 	nop
/*  f0fb7dc:	00000000 */ 	nop
.PF0f0fb7e0:
/*  f0fb7e0:	18600036 */ 	blez	$v1,.PF0f0fb8bc
/*  f0fb7e4:	28610004 */ 	slti	$at,$v1,0x4
/*  f0fb7e8:	1420000b */ 	bnez	$at,.PF0f0fb818
/*  f0fb7ec:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f0fb7f0:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0fb7f4:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f0fb7f8:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fb7fc:	0303c021 */ 	addu	$t8,$t8,$v1
/*  f0fb800:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f0fb804:	2401003c */ 	li	$at,0x3c
/*  f0fb808:	0301001a */ 	div	$zero,$t8,$at
/*  f0fb80c:	00007012 */ 	mflo	$t6
/*  f0fb810:	01c01825 */ 	move	$v1,$t6
/*  f0fb814:	00000000 */ 	nop
.PF0f0fb818:
/*  f0fb818:	8de20830 */ 	lw	$v0,0x830($t7)
/*  f0fb81c:	240c0001 */ 	li	$t4,0x1
/*  f0fb820:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fb824:	0046c821 */ 	addu	$t9,$v0,$a2
/*  f0fb828:	00003812 */ 	mflo	$a3
/*  f0fb82c:	14600002 */ 	bnez	$v1,.PF0f0fb838
/*  f0fb830:	00000000 */ 	nop
/*  f0fb834:	0007000d */ 	break	0x7
.PF0f0fb838:
/*  f0fb838:	2401ffff */ 	li	$at,-1
/*  f0fb83c:	14610004 */ 	bne	$v1,$at,.PF0f0fb850
/*  f0fb840:	3c018000 */ 	lui	$at,0x8000
/*  f0fb844:	14410002 */ 	bne	$v0,$at,.PF0f0fb850
/*  f0fb848:	00000000 */ 	nop
/*  f0fb84c:	0006000d */ 	break	0x6
.PF0f0fb850:
/*  f0fb850:	0323001a */ 	div	$zero,$t9,$v1
/*  f0fb854:	00004012 */ 	mflo	$t0
/*  f0fb858:	14600002 */ 	bnez	$v1,.PF0f0fb864
/*  f0fb85c:	00000000 */ 	nop
/*  f0fb860:	0007000d */ 	break	0x7
.PF0f0fb864:
/*  f0fb864:	2401ffff */ 	li	$at,-1
/*  f0fb868:	14610004 */ 	bne	$v1,$at,.PF0f0fb87c
/*  f0fb86c:	3c018000 */ 	lui	$at,0x8000
/*  f0fb870:	17210002 */ 	bne	$t9,$at,.PF0f0fb87c
/*  f0fb874:	00000000 */ 	nop
/*  f0fb878:	0006000d */ 	break	0x6
.PF0f0fb87c:
/*  f0fb87c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb880:	19600003 */ 	blez	$t3,.PF0f0fb890
/*  f0fb884:	00000000 */ 	nop
/*  f0fb888:	10000001 */ 	b	.PF0f0fb890
/*  f0fb88c:	240cffff */ 	li	$t4,-1
.PF0f0fb890:
/*  f0fb890:	10e80002 */ 	beq	$a3,$t0,.PF0f0fb89c
/*  f0fb894:	00acc021 */ 	addu	$t8,$a1,$t4
/*  f0fb898:	240d0001 */ 	li	$t5,0x1
.PF0f0fb89c:
/*  f0fb89c:	14a00002 */ 	bnez	$a1,.PF0f0fb8a8
/*  f0fb8a0:	00000000 */ 	nop
/*  f0fb8a4:	240d0001 */ 	li	$t5,0x1
.PF0f0fb8a8:
/*  f0fb8a8:	51a00005 */ 	beqzl	$t5,.PF0f0fb8c0
/*  f0fb8ac:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb8b0:	a4780834 */ 	sh	$t8,0x834($v1)
/*  f0fb8b4:	3c06800a */ 	lui	$a2,0x800a
/*  f0fb8b8:	8cc6a510 */ 	lw	$a2,-0x5af0($a2)
.PF0f0fb8bc:
/*  f0fb8bc:	8fa300fc */ 	lw	$v1,0xfc($sp)
.PF0f0fb8c0:
/*  f0fb8c0:	10000006 */ 	b	.PF0f0fb8dc
/*  f0fb8c4:	8c620830 */ 	lw	$v0,0x830($v1)
.PF0f0fb8c8:
/*  f0fb8c8:	8fa300fc */ 	lw	$v1,0xfc($sp)
.PF0f0fb8cc:
/*  f0fb8cc:	3c06800a */ 	lui	$a2,0x800a
/*  f0fb8d0:	a4600834 */ 	sh	$zero,0x834($v1)
/*  f0fb8d4:	8cc6a510 */ 	lw	$a2,-0x5af0($a2)
/*  f0fb8d8:	8c620830 */ 	lw	$v0,0x830($v1)
.PF0f0fb8dc:
/*  f0fb8dc:	10e80002 */ 	beq	$a3,$t0,.PF0f0fb8e8
/*  f0fb8e0:	27b50104 */ 	addiu	$s5,$sp,0x104
/*  f0fb8e4:	240d0001 */ 	li	$t5,0x1
.PF0f0fb8e8:
/*  f0fb8e8:	55a00003 */ 	bnezl	$t5,.PF0f0fb8f8
/*  f0fb8ec:	8c6e0824 */ 	lw	$t6,0x824($v1)
/*  f0fb8f0:	00006025 */ 	move	$t4,$zero
/*  f0fb8f4:	8c6e0824 */ 	lw	$t6,0x824($v1)
.PF0f0fb8f8:
/*  f0fb8f8:	8fa500f8 */ 	lw	$a1,0xf8($sp)
/*  f0fb8fc:	3c19800a */ 	lui	$t9,0x800a
/*  f0fb900:	01c67821 */ 	addu	$t7,$t6,$a2
/*  f0fb904:	ac6f0824 */ 	sw	$t7,0x824($v1)
/*  f0fb908:	8f39a510 */ 	lw	$t9,-0x5af0($t9)
/*  f0fb90c:	240e0001 */ 	li	$t6,0x1
/*  f0fb910:	0059c021 */ 	addu	$t8,$v0,$t9
/*  f0fb914:	ac780830 */ 	sw	$t8,0x830($v1)
/*  f0fb918:	a3a90104 */ 	sb	$t1,0x104($sp)
/*  f0fb91c:	a3ac0105 */ 	sb	$t4,0x105($sp)
/*  f0fb920:	a3aa0108 */ 	sb	$t2,0x108($sp)
/*  f0fb924:	a3ab0109 */ 	sb	$t3,0x109($sp)
/*  f0fb928:	10a00003 */ 	beqz	$a1,.PF0f0fb938
/*  f0fb92c:	a3a00118 */ 	sb	$zero,0x118($sp)
/*  f0fb930:	10000002 */ 	b	.PF0f0fb93c
/*  f0fb934:	a3ae010e */ 	sb	$t6,0x10e($sp)
.PF0f0fb938:
/*  f0fb938:	a3a0010e */ 	sb	$zero,0x10e($sp)
.PF0f0fb93c:
/*  f0fb93c:	8ee30000 */ 	lw	$v1,0x0($s7)
/*  f0fb940:	007e0019 */ 	multu	$v1,$s8
/*  f0fb944:	00007812 */ 	mflo	$t7
/*  f0fb948:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0fb94c:	8ce404f8 */ 	lw	$a0,0x4f8($a3)
/*  f0fb950:	50800016 */ 	beqzl	$a0,.PF0f0fb9ac
/*  f0fb954:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb958:	50a00014 */ 	beqzl	$a1,.PF0f0fb9ac
/*  f0fb95c:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb960:	8c990000 */ 	lw	$t9,0x0($a0)
/*  f0fb964:	240f0001 */ 	li	$t7,0x1
/*  f0fb968:	8f380010 */ 	lw	$t8,0x10($t9)
/*  f0fb96c:	24190001 */ 	li	$t9,0x1
/*  f0fb970:	330e0004 */ 	andi	$t6,$t8,0x4
/*  f0fb974:	51c00004 */ 	beqzl	$t6,.PF0f0fb988
/*  f0fb978:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f0fb97c:	a3af0106 */ 	sb	$t7,0x106($sp)
/*  f0fb980:	afb9011c */ 	sw	$t9,0x11c($sp)
/*  f0fb984:	8c820008 */ 	lw	$v0,0x8($a0)
.PF0f0fb988:
/*  f0fb988:	50400008 */ 	beqzl	$v0,.PF0f0fb9ac
/*  f0fb98c:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb990:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f0fb994:	24010002 */ 	li	$at,0x2
/*  f0fb998:	240e0001 */ 	li	$t6,0x1
/*  f0fb99c:	57010003 */ 	bnel	$t8,$at,.PF0f0fb9ac
/*  f0fb9a0:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb9a4:	a3ae0106 */ 	sb	$t6,0x106($sp)
/*  f0fb9a8:	84e204f4 */ 	lh	$v0,0x4f4($a3)
.PF0f0fb9ac:
/*  f0fb9ac:	00009825 */ 	move	$s3,$zero
/*  f0fb9b0:	0000a025 */ 	move	$s4,$zero
/*  f0fb9b4:	1840003a */ 	blez	$v0,.PF0f0fbaa0
/*  f0fb9b8:	00000000 */ 	nop
/*  f0fb9bc:	afa00044 */ 	sw	$zero,0x44($sp)
.PF0f0fb9c0:
/*  f0fb9c0:	000378c0 */ 	sll	$t7,$v1,0x3
/*  f0fb9c4:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0fb9c8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fb9cc:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f0fb9d0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fb9d4:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f0fb9d8:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0fb9dc:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0fb9e0:	02cfc821 */ 	addu	$t9,$s6,$t7
/*  f0fb9e4:	03389021 */ 	addu	$s2,$t9,$t8
/*  f0fb9e8:	824e0478 */ 	lb	$t6,0x478($s2)
/*  f0fb9ec:	26520464 */ 	addiu	$s2,$s2,0x464
/*  f0fb9f0:	02408825 */ 	move	$s1,$s2
/*  f0fb9f4:	19c00024 */ 	blez	$t6,.PF0f0fba88
/*  f0fb9f8:	00008025 */ 	move	$s0,$zero
/*  f0fb9fc:	8ef90000 */ 	lw	$t9,0x0($s7)
.PF0f0fba00:
/*  f0fba00:	268f0001 */ 	addiu	$t7,$s4,0x1
/*  f0fba04:	00003025 */ 	move	$a2,$zero
/*  f0fba08:	033e0019 */ 	multu	$t9,$s8
/*  f0fba0c:	02a02825 */ 	move	$a1,$s5
/*  f0fba10:	0000c012 */ 	mflo	$t8
/*  f0fba14:	02d87021 */ 	addu	$t6,$s6,$t8
/*  f0fba18:	85d904f4 */ 	lh	$t9,0x4f4($t6)
/*  f0fba1c:	15f90008 */ 	bne	$t7,$t9,.PF0f0fba40
/*  f0fba20:	00000000 */ 	nop
/*  f0fba24:	82580015 */ 	lb	$t8,0x15($s2)
/*  f0fba28:	16180005 */ 	bne	$s0,$t8,.PF0f0fba40
/*  f0fba2c:	00000000 */ 	nop
/*  f0fba30:	16600003 */ 	bnez	$s3,.PF0f0fba40
/*  f0fba34:	00000000 */ 	nop
/*  f0fba38:	24060001 */ 	li	$a2,0x1
/*  f0fba3c:	24130001 */ 	li	$s3,0x1
.PF0f0fba40:
/*  f0fba40:	0fc3e6a8 */ 	jal	dialogTick
/*  f0fba44:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f0fba48:	824e0014 */ 	lb	$t6,0x14($s2)
/*  f0fba4c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0fba50:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0fba54:	020e082a */ 	slt	$at,$s0,$t6
/*  f0fba58:	5420ffe9 */ 	bnezl	$at,.PF0f0fba00
/*  f0fba5c:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f0fba60:	8ee30000 */ 	lw	$v1,0x0($s7)
/*  f0fba64:	000378c0 */ 	sll	$t7,$v1,0x3
/*  f0fba68:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0fba6c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fba70:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f0fba74:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fba78:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f0fba7c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0fba80:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0fba84:	84e204f4 */ 	lh	$v0,0x4f4($a3)
.PF0f0fba88:
/*  f0fba88:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0fba8c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0fba90:	0282082a */ 	slt	$at,$s4,$v0
/*  f0fba94:	27380018 */ 	addiu	$t8,$t9,0x18
/*  f0fba98:	1420ffc9 */ 	bnez	$at,.PF0f0fb9c0
/*  f0fba9c:	afb80044 */ 	sw	$t8,0x44($sp)
.PF0f0fbaa0:
/*  f0fbaa0:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fbaa4:	8dce1f64 */ 	lw	$t6,0x1f64($t6)
/*  f0fbaa8:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f0fbaac:	2de1000d */ 	sltiu	$at,$t7,0xd
/*  f0fbab0:	1020004d */ 	beqz	$at,.PF0f0fbbe8
/*  f0fbab4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fbab8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0fbabc:	002f0821 */ 	addu	$at,$at,$t7
/*  f0fbac0:	8c2f3d90 */ 	lw	$t7,0x3d90($at)
/*  f0fbac4:	01e00008 */ 	jr	$t7
/*  f0fbac8:	00000000 */ 	nop
/*  f0fbacc:	83b9010e */ 	lb	$t9,0x10e($sp)
/*  f0fbad0:	8fb8011c */ 	lw	$t8,0x11c($sp)
/*  f0fbad4:	53200045 */ 	beqzl	$t9,.PF0f0fbbec
/*  f0fbad8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fbadc:	57000043 */ 	bnezl	$t8,.PF0f0fbbec
/*  f0fbae0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fbae4:	8ce404f8 */ 	lw	$a0,0x4f8($a3)
/*  f0fbae8:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f0fbaec:	5080003f */ 	beqzl	$a0,.PF0f0fbbec
/*  f0fbaf0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fbaf4:	8dcf000c */ 	lw	$t7,0xc($t6)
/*  f0fbaf8:	3c19800a */ 	lui	$t9,0x800a
/*  f0fbafc:	55e0003b */ 	bnezl	$t7,.PF0f0fbbec
/*  f0fbb00:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fbb04:	8f39a9a0 */ 	lw	$t9,-0x5660($t9)
/*  f0fbb08:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0fbb0c:	24010002 */ 	li	$at,0x2
/*  f0fbb10:	13210008 */ 	beq	$t9,$at,.PF0f0fbb34
/*  f0fbb14:	3c048008 */ 	lui	$a0,0x8008
/*  f0fbb18:	24845d08 */ 	addiu	$a0,$a0,0x5d08
/*  f0fbb1c:	10820005 */ 	beq	$a0,$v0,.PF0f0fbb34
/*  f0fbb20:	00000000 */ 	nop
/*  f0fbb24:	0fc3cda8 */ 	jal	menuPushDialog
/*  f0fbb28:	00000000 */ 	nop
/*  f0fbb2c:	1000002f */ 	b	.PF0f0fbbec
/*  f0fbb30:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PF0f0fbb34:
/*  f0fbb34:	3c188008 */ 	lui	$t8,0x8008
/*  f0fbb38:	27186bd0 */ 	addiu	$t8,$t8,0x6bd0
/*  f0fbb3c:	5702002b */ 	bnel	$t8,$v0,.PF0f0fbbec
/*  f0fbb40:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fbb44:	0fc6011a */ 	jal	func0f17f428
/*  f0fbb48:	00000000 */ 	nop
/*  f0fbb4c:	10000027 */ 	b	.PF0f0fbbec
/*  f0fbb50:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fbb54:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0fbb58:	8dce0a44 */ 	lw	$t6,0xa44($t6)
/*  f0fbb5c:	51c00010 */ 	beqzl	$t6,.PF0f0fbba0
/*  f0fbb60:	240e000a */ 	li	$t6,0xa
/*  f0fbb64:	0fc3e219 */ 	jal	func0f0f8120
/*  f0fbb68:	00000000 */ 	nop
/*  f0fbb6c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0fbb70:	8def1728 */ 	lw	$t7,0x1728($t7)
/*  f0fbb74:	3c18800a */ 	lui	$t8,0x800a
/*  f0fbb78:	2718e5a0 */ 	addiu	$t8,$t8,-6752
/*  f0fbb7c:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f0fbb80:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f0fbb84:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fbb88:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f0fbb8c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fbb90:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f0fbb94:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fbb98:	03383821 */ 	addu	$a3,$t9,$t8
/*  f0fbb9c:	240e000a */ 	li	$t6,0xa
.PF0f0fbba0:
/*  f0fbba0:	a0ee083c */ 	sb	$t6,0x83c($a3)
/*  f0fbba4:	83af010e */ 	lb	$t7,0x10e($sp)
/*  f0fbba8:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0fbbac:	51e0000f */ 	beqzl	$t7,.PF0f0fbbec
/*  f0fbbb0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fbbb4:	5720000d */ 	bnezl	$t9,.PF0f0fbbec
/*  f0fbbb8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fbbbc:	8cf804f8 */ 	lw	$t8,0x4f8($a3)
/*  f0fbbc0:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f0fbbc4:	53000009 */ 	beqzl	$t8,.PF0f0fbbec
/*  f0fbbc8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fbbcc:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f0fbbd0:	8df90010 */ 	lw	$t9,0x10($t7)
/*  f0fbbd4:	33380020 */ 	andi	$t8,$t9,0x20
/*  f0fbbd8:	57000004 */ 	bnezl	$t8,.PF0f0fbbec
/*  f0fbbdc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fbbe0:	0fc3e219 */ 	jal	func0f0f8120
/*  f0fbbe4:	00000000 */ 	nop
.PF0f0fbbe8:
/*  f0fbbe8:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PF0f0fbbec:
/*  f0fbbec:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0fbbf0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0fbbf4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0fbbf8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0fbbfc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0fbc00:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0fbc04:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0fbc08:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0fbc0c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0fbc10:	03e00008 */ 	jr	$ra
/*  f0fbc14:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuProcessInput
.late_rodata
glabel var7f1b2a98
.word menuProcessInput+0xd10 # f0fb414
glabel var7f1b2a9c
.word menuProcessInput+0xd10 # f0fb414
glabel var7f1b2aa0
.word menuProcessInput+0xc38 # f0fb33c
glabel var7f1b2aa4
.word menuProcessInput+0xcc0 # f0fb3c4
glabel var7f1b2aa8
.word menuProcessInput+0xd10 # f0fb414
glabel var7f1b2aac
.word menuProcessInput+0xd54 # f0fb458
glabel var7f1b2ab0
.word menuProcessInput+0xd54 # f0fb458
glabel var7f1b2ab4
.word menuProcessInput+0xd54 # f0fb458
glabel var7f1b2ab8
.word menuProcessInput+0xd54 # f0fb458
glabel var7f1b2abc
.word menuProcessInput+0xd54 # f0fb458
glabel var7f1b2ac0
.word menuProcessInput+0xc38 # f0fb33c
glabel var7f1b2ac4
.word menuProcessInput+0xd54 # f0fb458
glabel var7f1b2ac8
.word menuProcessInput+0xd10 # f0fb414
.text
/*  f0fa704:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0fa708:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0fa70c:	3c178007 */ 	lui	$s7,%hi(g_MpPlayerNum)
/*  f0fa710:	26f71448 */ 	addiu	$s7,$s7,%lo(g_MpPlayerNum)
/*  f0fa714:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0fa718:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0fa71c:	241e0e70 */ 	addiu	$s8,$zero,0xe70
/*  f0fa720:	01de0019 */ 	multu	$t6,$s8
/*  f0fa724:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0fa728:	3c16800a */ 	lui	$s6,%hi(g_Menus)
/*  f0fa72c:	26d6e000 */ 	addiu	$s6,$s6,%lo(g_Menus)
/*  f0fa730:	3c19800a */ 	lui	$t9,%hi(g_MenuData+0x4)
/*  f0fa734:	8f3919c4 */ 	lw	$t9,%lo(g_MenuData+0x4)($t9)
/*  f0fa738:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0fa73c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fa740:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0fa744:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0fa748:	00007812 */ 	mflo	$t7
/*  f0fa74c:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0fa750:	8cf804f8 */ 	lw	$t8,0x4f8($a3)
/*  f0fa754:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0fa758:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0fa75c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0fa760:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0fa764:	00006025 */ 	or	$t4,$zero,$zero
/*  f0fa768:	00004825 */ 	or	$t1,$zero,$zero
/*  f0fa76c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0fa770:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0fa774:	afa0011c */ 	sw	$zero,0x11c($sp)
/*  f0fa778:	afa700fc */ 	sw	$a3,0xfc($sp)
/*  f0fa77c:	17210005 */ 	bne	$t9,$at,.L0f0fa794
/*  f0fa780:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f0fa784:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x28c)
/*  f0fa788:	8dcea24c */ 	lw	$t6,%lo(g_Vars+0x28c)($t6)
/*  f0fa78c:	3c01800a */ 	lui	$at,%hi(g_AmIndex)
/*  f0fa790:	ac2e21b8 */ 	sw	$t6,%lo(g_AmIndex)($at)
.L0f0fa794:
/*  f0fa794:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa798:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa79c:	0fc3c506 */ 	jal	func0f0f1418
/*  f0fa7a0:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa7a4:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0fa7a8:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa7ac:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa7b0:	01fe0019 */ 	multu	$t7,$s8
/*  f0fa7b4:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0fa7b8:	a3a00106 */ 	sb	$zero,0x106($sp)
/*  f0fa7bc:	a3a00107 */ 	sb	$zero,0x107($sp)
/*  f0fa7c0:	a3a0010a */ 	sb	$zero,0x10a($sp)
/*  f0fa7c4:	a3a0010b */ 	sb	$zero,0x10b($sp)
/*  f0fa7c8:	00005025 */ 	or	$t2,$zero,$zero
/*  f0fa7cc:	00005825 */ 	or	$t3,$zero,$zero
/*  f0fa7d0:	3c0f800a */ 	lui	$t7,%hi(g_MenuData+0x4)
/*  f0fa7d4:	0000c012 */ 	mflo	$t8
/*  f0fa7d8:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f0fa7dc:	8f2e04f8 */ 	lw	$t6,0x4f8($t9)
/*  f0fa7e0:	51c0031e */ 	beqzl	$t6,.L0f0fb45c
/*  f0fa7e4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fa7e8:	8def19c4 */ 	lw	$t7,%lo(g_MenuData+0x4)($t7)
/*  f0fa7ec:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0fa7f0:	afa000f8 */ 	sw	$zero,0xf8($sp)
/*  f0fa7f4:	15e1000b */ 	bne	$t7,$at,.L0f0fa824
/*  f0fa7f8:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f0fa7fc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fa800:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0fa804:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0fa808:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f0fa80c:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f0fa810:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f0fa814:	afb900e0 */ 	sw	$t9,0xe0($sp)
/*  f0fa818:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f0fa81c:	1000001b */ 	b	.L0f0fa88c
/*  f0fa820:	afaf00ec */ 	sw	$t7,0xec($sp)
.L0f0fa824:
/*  f0fa824:	27a400d7 */ 	addiu	$a0,$sp,0xd7
/*  f0fa828:	27a500d6 */ 	addiu	$a1,$sp,0xd6
/*  f0fa82c:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa830:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa834:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fa838:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fa83c:	0fc3dd2a */ 	jal	menuGetContPads
/*  f0fa840:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa844:	83a200d7 */ 	lb	$v0,0xd7($sp)
/*  f0fa848:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa84c:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa850:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fa854:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fa858:	04400004 */ 	bltz	$v0,.L0f0fa86c
/*  f0fa85c:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0fa860:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fa864:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f0fa868:	afa300ec */ 	sw	$v1,0xec($sp)
.L0f0fa86c:
/*  f0fa86c:	83a200d6 */ 	lb	$v0,0xd6($sp)
/*  f0fa870:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0fa874:	04400005 */ 	bltz	$v0,.L0f0fa88c
/*  f0fa878:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0fa87c:	03b8c821 */ 	addu	$t9,$sp,$t8
/*  f0fa880:	af2200d8 */ 	sw	$v0,0xd8($t9)
/*  f0fa884:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fa888:	afa300ec */ 	sw	$v1,0xec($sp)
.L0f0fa88c:
/*  f0fa88c:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0fa890:	01de0019 */ 	multu	$t6,$s8
/*  f0fa894:	00007812 */ 	mflo	$t7
/*  f0fa898:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0fa89c:	90e20e41 */ 	lbu	$v0,0xe41($a3)
/*  f0fa8a0:	1840001a */ 	blez	$v0,.L0f0fa90c
/*  f0fa8a4:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f0fa8a8:	331900ff */ 	andi	$t9,$t8,0xff
/*  f0fa8ac:	17200014 */ 	bnez	$t9,.L0f0fa900
/*  f0fa8b0:	a0f80e41 */ 	sb	$t8,0xe41($a3)
/*  f0fa8b4:	8cee0e48 */ 	lw	$t6,0xe48($a3)
/*  f0fa8b8:	8cef0e4c */ 	lw	$t7,0xe4c($a3)
/*  f0fa8bc:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0fa8c0:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0fa8c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fa8c8:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa8cc:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa8d0:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fa8d4:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fa8d8:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa8dc:	afae00cc */ 	sw	$t6,0xcc($sp)
/*  f0fa8e0:	0fc42539 */ 	jal	filemgrSaveOrLoad
/*  f0fa8e4:	a7af00d0 */ 	sh	$t7,0xd0($sp)
/*  f0fa8e8:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa8ec:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa8f0:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fa8f4:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fa8f8:	10000004 */ 	b	.L0f0fa90c
/*  f0fa8fc:	8fac012c */ 	lw	$t4,0x12c($sp)
.L0f0fa900:
/*  f0fa900:	90f90e40 */ 	lbu	$t9,0xe40($a3)
/*  f0fa904:	372e0080 */ 	ori	$t6,$t9,0x80
/*  f0fa908:	a0ee0e40 */ 	sb	$t6,0xe40($a3)
.L0f0fa90c:
/*  f0fa90c:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f0fa910:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0fa914:	19e00083 */ 	blez	$t7,.L0f0fab24
/*  f0fa918:	27b300d8 */ 	addiu	$s3,$sp,0xd8
.L0f0fa91c:
/*  f0fa91c:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa920:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa924:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fa928:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fa92c:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa930:	0c005384 */ 	jal	joyGetStickX
/*  f0fa934:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa938:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0fa93c:	0010c603 */ 	sra	$t8,$s0,0x18
/*  f0fa940:	03008025 */ 	or	$s0,$t8,$zero
/*  f0fa944:	0c0053ae */ 	jal	joyGetStickY
/*  f0fa948:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa94c:	00028e00 */ 	sll	$s1,$v0,0x18
/*  f0fa950:	0011ce03 */ 	sra	$t9,$s1,0x18
/*  f0fa954:	03208825 */ 	or	$s1,$t9,$zero
/*  f0fa958:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa95c:	0c0053d8 */ 	jal	joyGetButtons
/*  f0fa960:	3405ffff */ 	dli	$a1,0xffff
/*  f0fa964:	3052ffff */ 	andi	$s2,$v0,0xffff
/*  f0fa968:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa96c:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0fa970:	3405ffff */ 	dli	$a1,0xffff
/*  f0fa974:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0fa978:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa97c:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa980:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fa984:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fa988:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0fa98c:	11c00003 */ 	beqz	$t6,.L0f0fa99c
/*  f0fa990:	00403025 */ 	or	$a2,$v0,$zero
/*  f0fa994:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fa998:	a3af0106 */ 	sb	$t7,0x106($sp)
.L0f0fa99c:
/*  f0fa99c:	30d84000 */ 	andi	$t8,$a2,0x4000
/*  f0fa9a0:	13000003 */ 	beqz	$t8,.L0f0fa9b0
/*  f0fa9a4:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f0fa9a8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fa9ac:	a3b90107 */ 	sb	$t9,0x107($sp)
.L0f0fa9b0:
/*  f0fa9b0:	11c00003 */ 	beqz	$t6,.L0f0fa9c0
/*  f0fa9b4:	30d81000 */ 	andi	$t8,$a2,0x1000
/*  f0fa9b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fa9bc:	a3af0106 */ 	sb	$t7,0x106($sp)
.L0f0fa9c0:
/*  f0fa9c0:	13000003 */ 	beqz	$t8,.L0f0fa9d0
/*  f0fa9c4:	324e0010 */ 	andi	$t6,$s2,0x10
/*  f0fa9c8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fa9cc:	afb900f8 */ 	sw	$t9,0xf8($sp)
.L0f0fa9d0:
/*  f0fa9d0:	11c00003 */ 	beqz	$t6,.L0f0fa9e0
/*  f0fa9d4:	02402825 */ 	or	$a1,$s2,$zero
/*  f0fa9d8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fa9dc:	a3af010a */ 	sb	$t7,0x10a($sp)
.L0f0fa9e0:
/*  f0fa9e0:	30b80020 */ 	andi	$t8,$a1,0x20
/*  f0fa9e4:	13000003 */ 	beqz	$t8,.L0f0fa9f4
/*  f0fa9e8:	30ae0008 */ 	andi	$t6,$a1,0x8
/*  f0fa9ec:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fa9f0:	a3b9010a */ 	sb	$t9,0x10a($sp)
.L0f0fa9f4:
/*  f0fa9f4:	05410003 */ 	bgez	$t2,.L0f0faa04
/*  f0fa9f8:	30cf0008 */ 	andi	$t7,$a2,0x8
/*  f0fa9fc:	10000002 */ 	b	.L0f0faa08
/*  f0faa00:	000a2023 */ 	negu	$a0,$t2
.L0f0faa04:
/*  f0faa04:	01402025 */ 	or	$a0,$t2,$zero
.L0f0faa08:
/*  f0faa08:	06010003 */ 	bgez	$s0,.L0f0faa18
/*  f0faa0c:	30b80004 */ 	andi	$t8,$a1,0x4
/*  f0faa10:	10000002 */ 	b	.L0f0faa1c
/*  f0faa14:	00101823 */ 	negu	$v1,$s0
.L0f0faa18:
/*  f0faa18:	02001825 */ 	or	$v1,$s0,$zero
.L0f0faa1c:
/*  f0faa1c:	0083082a */ 	slt	$at,$a0,$v1
/*  f0faa20:	10200002 */ 	beqz	$at,.L0f0faa2c
/*  f0faa24:	30d90004 */ 	andi	$t9,$a2,0x4
/*  f0faa28:	02005025 */ 	or	$t2,$s0,$zero
.L0f0faa2c:
/*  f0faa2c:	05610003 */ 	bgez	$t3,.L0f0faa3c
/*  f0faa30:	01602025 */ 	or	$a0,$t3,$zero
/*  f0faa34:	10000001 */ 	b	.L0f0faa3c
/*  f0faa38:	000b2023 */ 	negu	$a0,$t3
.L0f0faa3c:
/*  f0faa3c:	06210003 */ 	bgez	$s1,.L0f0faa4c
/*  f0faa40:	02201825 */ 	or	$v1,$s1,$zero
/*  f0faa44:	10000001 */ 	b	.L0f0faa4c
/*  f0faa48:	00111823 */ 	negu	$v1,$s1
.L0f0faa4c:
/*  f0faa4c:	0083082a */ 	slt	$at,$a0,$v1
/*  f0faa50:	10200002 */ 	beqz	$at,.L0f0faa5c
/*  f0faa54:	00000000 */ 	nop
/*  f0faa58:	02205825 */ 	or	$t3,$s1,$zero
.L0f0faa5c:
/*  f0faa5c:	11c00002 */ 	beqz	$t6,.L0f0faa68
/*  f0faa60:	00000000 */ 	nop
/*  f0faa64:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0faa68:
/*  f0faa68:	11e00002 */ 	beqz	$t7,.L0f0faa74
/*  f0faa6c:	30ae0002 */ 	andi	$t6,$a1,0x2
/*  f0faa70:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f0faa74:
/*  f0faa74:	13000002 */ 	beqz	$t8,.L0f0faa80
/*  f0faa78:	30cf0002 */ 	andi	$t7,$a2,0x2
/*  f0faa7c:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f0faa80:
/*  f0faa80:	13200002 */ 	beqz	$t9,.L0f0faa8c
/*  f0faa84:	30b80001 */ 	andi	$t8,$a1,0x1
/*  f0faa88:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0faa8c:
/*  f0faa8c:	11c00002 */ 	beqz	$t6,.L0f0faa98
/*  f0faa90:	30d90001 */ 	andi	$t9,$a2,0x1
/*  f0faa94:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0faa98:
/*  f0faa98:	11e00002 */ 	beqz	$t7,.L0f0faaa4
/*  f0faa9c:	30ae0800 */ 	andi	$t6,$a1,0x800
/*  f0faaa0:	2415ffff */ 	addiu	$s5,$zero,-1
.L0f0faaa4:
/*  f0faaa4:	13000002 */ 	beqz	$t8,.L0f0faab0
/*  f0faaa8:	30cf0800 */ 	andi	$t7,$a2,0x800
/*  f0faaac:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0faab0:
/*  f0faab0:	13200002 */ 	beqz	$t9,.L0f0faabc
/*  f0faab4:	30b80400 */ 	andi	$t8,$a1,0x400
/*  f0faab8:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f0faabc:
/*  f0faabc:	11c00002 */ 	beqz	$t6,.L0f0faac8
/*  f0faac0:	30d90400 */ 	andi	$t9,$a2,0x400
/*  f0faac4:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0faac8:
/*  f0faac8:	11e00002 */ 	beqz	$t7,.L0f0faad4
/*  f0faacc:	30ae0200 */ 	andi	$t6,$a1,0x200
/*  f0faad0:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f0faad4:
/*  f0faad4:	13000002 */ 	beqz	$t8,.L0f0faae0
/*  f0faad8:	30cf0200 */ 	andi	$t7,$a2,0x200
/*  f0faadc:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f0faae0:
/*  f0faae0:	13200002 */ 	beqz	$t9,.L0f0faaec
/*  f0faae4:	30b80100 */ 	andi	$t8,$a1,0x100
/*  f0faae8:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0faaec:
/*  f0faaec:	11c00002 */ 	beqz	$t6,.L0f0faaf8
/*  f0faaf0:	30d90100 */ 	andi	$t9,$a2,0x100
/*  f0faaf4:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0faaf8:
/*  f0faaf8:	11e00002 */ 	beqz	$t7,.L0f0fab04
/*  f0faafc:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f0fab00:	2415ffff */ 	addiu	$s5,$zero,-1
.L0f0fab04:
/*  f0fab04:	13000002 */ 	beqz	$t8,.L0f0fab10
/*  f0fab08:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0fab0c:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0fab10:
/*  f0fab10:	13200002 */ 	beqz	$t9,.L0f0fab1c
/*  f0fab14:	00000000 */ 	nop
/*  f0fab18:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f0fab1c:
/*  f0fab1c:	168eff7f */ 	bne	$s4,$t6,.L0f0fa91c
/*  f0fab20:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f0fab24:
/*  f0fab24:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0fab28:	93ae0106 */ 	lbu	$t6,0x106($sp)
/*  f0fab2c:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f0fab30:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0fab34:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fab38:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fab3c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0fab40:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fab44:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fab48:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fab4c:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f0fab50:	11c00002 */ 	beqz	$t6,.L0f0fab5c
/*  f0fab54:	8f2404f8 */ 	lw	$a0,0x4f8($t9)
/*  f0fab58:	a3a00107 */ 	sb	$zero,0x107($sp)
.L0f0fab5c:
/*  f0fab5c:	11000002 */ 	beqz	$t0,.L0f0fab68
/*  f0fab60:	2406001e */ 	addiu	$a2,$zero,0x1e
/*  f0fab64:	01006025 */ 	or	$t4,$t0,$zero
.L0f0fab68:
/*  f0fab68:	12a00002 */ 	beqz	$s5,.L0f0fab74
/*  f0fab6c:	2413003c */ 	addiu	$s3,$zero,0x3c
/*  f0fab70:	02a04825 */ 	or	$t1,$s5,$zero
.L0f0fab74:
/*  f0fab74:	24110021 */ 	addiu	$s1,$zero,0x21
/*  f0fab78:	2414002c */ 	addiu	$s4,$zero,0x2c
/*  f0fab7c:	10800019 */ 	beqz	$a0,.L0f0fabe4
/*  f0fab80:	00009025 */ 	or	$s2,$zero,$zero
/*  f0fab84:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f0fab88:	10400016 */ 	beqz	$v0,.L0f0fabe4
/*  f0fab8c:	00000000 */ 	nop
/*  f0fab90:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0fab94:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0fab98:	10610003 */ 	beq	$v1,$at,.L0f0faba8
/*  f0fab9c:	24010010 */ 	addiu	$at,$zero,0x10
/*  f0faba0:	54610009 */ 	bnel	$v1,$at,.L0f0fabc8
/*  f0faba4:	2401000d */ 	addiu	$at,$zero,0xd
.L0f0faba8:
/*  f0faba8:	8c8f000c */ 	lw	$t7,0xc($a0)
/*  f0fabac:	51e00006 */ 	beqzl	$t7,.L0f0fabc8
/*  f0fabb0:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0fabb4:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f0fabb8:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f0fabbc:	2413001e */ 	addiu	$s3,$zero,0x1e
/*  f0fabc0:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f0fabc4:	2401000d */ 	addiu	$at,$zero,0xd
.L0f0fabc8:
/*  f0fabc8:	14610006 */ 	bne	$v1,$at,.L0f0fabe4
/*  f0fabcc:	00000000 */ 	nop
/*  f0fabd0:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0fabd4:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f0fabd8:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f0fabdc:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f0fabe0:	2414000a */ 	addiu	$s4,$zero,0xa
.L0f0fabe4:
/*  f0fabe4:	15200004 */ 	bnez	$t1,.L0f0fabf8
/*  f0fabe8:	0000f825 */ 	or	$ra,$zero,$zero
/*  f0fabec:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fabf0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0fabf4:	a478082c */ 	sh	$t8,0x82c($v1)
.L0f0fabf8:
/*  f0fabf8:	12a00006 */ 	beqz	$s5,.L0f0fac14
/*  f0fabfc:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fac00:	a460082c */ 	sh	$zero,0x82c($v1)
/*  f0fac04:	ac600824 */ 	sw	$zero,0x824($v1)
/*  f0fac08:	a475082a */ 	sh	$s5,0x82a($v1)
/*  f0fac0c:	10000004 */ 	b	.L0f0fac20
/*  f0fac10:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0fac14:
/*  f0fac14:	51200003 */ 	beqzl	$t1,.L0f0fac24
/*  f0fac18:	8c620824 */ 	lw	$v0,0x824($v1)
/*  f0fac1c:	8469082a */ 	lh	$t1,0x82a($v1)
.L0f0fac20:
/*  f0fac20:	8c620824 */ 	lw	$v0,0x824($v1)
.L0f0fac24:
/*  f0fac24:	3c0e800a */ 	lui	$t6,%hi(g_Vars)
/*  f0fac28:	2841003d */ 	slti	$at,$v0,0x3d
/*  f0fac2c:	14200004 */ 	bnez	$at,.L0f0fac40
/*  f0fac30:	00000000 */ 	nop
/*  f0fac34:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fac38:	a479082c */ 	sh	$t9,0x82c($v1)
/*  f0fac3c:	8c620824 */ 	lw	$v0,0x824($v1)
.L0f0fac40:
/*  f0fac40:	0050001a */ 	div	$zero,$v0,$s0
/*  f0fac44:	8dce9fc0 */ 	lw	$t6,%lo(g_Vars)($t6)
/*  f0fac48:	00003812 */ 	mflo	$a3
/*  f0fac4c:	8478082c */ 	lh	$t8,0x82c($v1)
/*  f0fac50:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0fac54:	01f0001a */ 	div	$zero,$t7,$s0
/*  f0fac58:	16000002 */ 	bnez	$s0,.L0f0fac64
/*  f0fac5c:	00000000 */ 	nop
/*  f0fac60:	0007000d */ 	break	0x7
.L0f0fac64:
/*  f0fac64:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fac68:	16010004 */ 	bne	$s0,$at,.L0f0fac7c
/*  f0fac6c:	3c018000 */ 	lui	$at,0x8000
/*  f0fac70:	14410002 */ 	bne	$v0,$at,.L0f0fac7c
/*  f0fac74:	00000000 */ 	nop
/*  f0fac78:	0006000d */ 	break	0x6
.L0f0fac7c:
/*  f0fac7c:	00006812 */ 	mflo	$t5
/*  f0fac80:	16000002 */ 	bnez	$s0,.L0f0fac8c
/*  f0fac84:	00000000 */ 	nop
/*  f0fac88:	0007000d */ 	break	0x7
.L0f0fac8c:
/*  f0fac8c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fac90:	16010004 */ 	bne	$s0,$at,.L0f0faca4
/*  f0fac94:	3c018000 */ 	lui	$at,0x8000
/*  f0fac98:	15e10002 */ 	bne	$t7,$at,.L0f0faca4
/*  f0fac9c:	00000000 */ 	nop
/*  f0faca0:	0006000d */ 	break	0x6
.L0f0faca4:
/*  f0faca4:	1700000b */ 	bnez	$t8,.L0f0facd4
/*  f0faca8:	00000000 */ 	nop
/*  f0facac:	04e10003 */ 	bgez	$a3,.L0f0facbc
/*  f0facb0:	0007c843 */ 	sra	$t9,$a3,0x1
/*  f0facb4:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0facb8:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0facbc:
/*  f0facbc:	03203825 */ 	or	$a3,$t9,$zero
/*  f0facc0:	05a10003 */ 	bgez	$t5,.L0f0facd0
/*  f0facc4:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f0facc8:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f0faccc:	00017043 */ 	sra	$t6,$at,0x1
.L0f0facd0:
/*  f0facd0:	01c06825 */ 	or	$t5,$t6,$zero
.L0f0facd4:
/*  f0facd4:	05410003 */ 	bgez	$t2,.L0f0face4
/*  f0facd8:	a3a9010c */ 	sb	$t1,0x10c($sp)
/*  f0facdc:	10000002 */ 	b	.L0f0face8
/*  f0face0:	000a1023 */ 	negu	$v0,$t2
.L0f0face4:
/*  f0face4:	01401025 */ 	or	$v0,$t2,$zero
.L0f0face8:
/*  f0face8:	05610003 */ 	bgez	$t3,.L0f0facf8
/*  f0facec:	0046082a */ 	slt	$at,$v0,$a2
/*  f0facf0:	10000002 */ 	b	.L0f0facfc
/*  f0facf4:	000b1823 */ 	negu	$v1,$t3
.L0f0facf8:
/*  f0facf8:	01601825 */ 	or	$v1,$t3,$zero
.L0f0facfc:
/*  f0facfc:	14200065 */ 	bnez	$at,.L0f0fae94
/*  f0fad00:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fad04:	14200003 */ 	bnez	$at,.L0f0fad14
/*  f0fad08:	00000000 */ 	nop
/*  f0fad0c:	52400062 */ 	beqzl	$s2,.L0f0fae98
/*  f0fad10:	8fb800fc */ 	lw	$t8,0xfc($sp)
.L0f0fad14:
/*  f0fad14:	05410006 */ 	bgez	$t2,.L0f0fad30
/*  f0fad18:	28410047 */ 	slti	$at,$v0,0x47
/*  f0fad1c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fad20:	846f0828 */ 	lh	$t7,0x828($v1)
/*  f0fad24:	59e00003 */ 	blezl	$t7,.L0f0fad34
/*  f0fad28:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fad2c:	a4600828 */ 	sh	$zero,0x828($v1)
.L0f0fad30:
/*  f0fad30:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fad34:
/*  f0fad34:	19400005 */ 	blez	$t2,.L0f0fad4c
/*  f0fad38:	84640828 */ 	lh	$a0,0x828($v1)
/*  f0fad3c:	04810003 */ 	bgez	$a0,.L0f0fad4c
/*  f0fad40:	00000000 */ 	nop
/*  f0fad44:	a4600828 */ 	sh	$zero,0x828($v1)
/*  f0fad48:	84640828 */ 	lh	$a0,0x828($v1)
.L0f0fad4c:
/*  f0fad4c:	14800003 */ 	bnez	$a0,.L0f0fad5c
/*  f0fad50:	00000000 */ 	nop
/*  f0fad54:	ac600824 */ 	sw	$zero,0x824($v1)
/*  f0fad58:	84640828 */ 	lh	$a0,0x828($v1)
.L0f0fad5c:
/*  f0fad5c:	54200003 */ 	bnezl	$at,.L0f0fad6c
/*  f0fad60:	00461023 */ 	subu	$v0,$v0,$a2
/*  f0fad64:	24020046 */ 	addiu	$v0,$zero,0x46
/*  f0fad68:	00461023 */ 	subu	$v0,$v0,$a2
.L0f0fad6c:
/*  f0fad6c:	02220019 */ 	multu	$s1,$v0
/*  f0fad70:	24190046 */ 	addiu	$t9,$zero,0x46
/*  f0fad74:	03267023 */ 	subu	$t6,$t9,$a2
/*  f0fad78:	0000c012 */ 	mflo	$t8
/*  f0fad7c:	00000000 */ 	nop
/*  f0fad80:	00000000 */ 	nop
/*  f0fad84:	030e001a */ 	div	$zero,$t8,$t6
/*  f0fad88:	15c00002 */ 	bnez	$t6,.L0f0fad94
/*  f0fad8c:	00000000 */ 	nop
/*  f0fad90:	0007000d */ 	break	0x7
.L0f0fad94:
/*  f0fad94:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fad98:	15c10004 */ 	bne	$t6,$at,.L0f0fadac
/*  f0fad9c:	3c018000 */ 	lui	$at,0x8000
/*  f0fada0:	17010002 */ 	bne	$t8,$at,.L0f0fadac
/*  f0fada4:	00000000 */ 	nop
/*  f0fada8:	0006000d */ 	break	0x6
.L0f0fadac:
/*  f0fadac:	00007812 */ 	mflo	$t7
/*  f0fadb0:	026f2823 */ 	subu	$a1,$s3,$t7
/*  f0fadb4:	28810003 */ 	slti	$at,$a0,0x3
/*  f0fadb8:	10200004 */ 	beqz	$at,.L0f0fadcc
/*  f0fadbc:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0fadc0:	2881fffe */ 	slti	$at,$a0,-2
/*  f0fadc4:	10200005 */ 	beqz	$at,.L0f0faddc
/*  f0fadc8:	00000000 */ 	nop
.L0f0fadcc:
/*  f0fadcc:	04a10003 */ 	bgez	$a1,.L0f0faddc
/*  f0fadd0:	00051843 */ 	sra	$v1,$a1,0x1
/*  f0fadd4:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0fadd8:	00011843 */ 	sra	$v1,$at,0x1
.L0f0faddc:
/*  f0faddc:	1860002f */ 	blez	$v1,.L0f0fae9c
/*  f0fade0:	00000000 */ 	nop
/*  f0fade4:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0fade8:	3c18800a */ 	lui	$t8,%hi(g_Vars)
/*  f0fadec:	8f189fc0 */ 	lw	$t8,%lo(g_Vars)($t8)
/*  f0fadf0:	8f220824 */ 	lw	$v0,0x824($t9)
/*  f0fadf4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0fadf8:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fadfc:	00587021 */ 	addu	$t6,$v0,$t8
/*  f0fae00:	00003812 */ 	mflo	$a3
/*  f0fae04:	14600002 */ 	bnez	$v1,.L0f0fae10
/*  f0fae08:	00000000 */ 	nop
/*  f0fae0c:	0007000d */ 	break	0x7
.L0f0fae10:
/*  f0fae10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fae14:	14610004 */ 	bne	$v1,$at,.L0f0fae28
/*  f0fae18:	3c018000 */ 	lui	$at,0x8000
/*  f0fae1c:	14410002 */ 	bne	$v0,$at,.L0f0fae28
/*  f0fae20:	00000000 */ 	nop
/*  f0fae24:	0006000d */ 	break	0x6
.L0f0fae28:
/*  f0fae28:	01c3001a */ 	div	$zero,$t6,$v1
/*  f0fae2c:	00006812 */ 	mflo	$t5
/*  f0fae30:	14600002 */ 	bnez	$v1,.L0f0fae3c
/*  f0fae34:	00000000 */ 	nop
/*  f0fae38:	0007000d */ 	break	0x7
.L0f0fae3c:
/*  f0fae3c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fae40:	14610004 */ 	bne	$v1,$at,.L0f0fae54
/*  f0fae44:	3c018000 */ 	lui	$at,0x8000
/*  f0fae48:	15c10002 */ 	bne	$t6,$at,.L0f0fae54
/*  f0fae4c:	00000000 */ 	nop
/*  f0fae50:	0006000d */ 	break	0x6
.L0f0fae54:
/*  f0fae54:	05410003 */ 	bgez	$t2,.L0f0fae64
/*  f0fae58:	00000000 */ 	nop
/*  f0fae5c:	10000001 */ 	b	.L0f0fae64
/*  f0fae60:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0fae64:
/*  f0fae64:	10ed0002 */ 	beq	$a3,$t5,.L0f0fae70
/*  f0fae68:	00000000 */ 	nop
/*  f0fae6c:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0fae70:
/*  f0fae70:	14800002 */ 	bnez	$a0,.L0f0fae7c
/*  f0fae74:	00000000 */ 	nop
/*  f0fae78:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0fae7c:
/*  f0fae7c:	13e00007 */ 	beqz	$ra,.L0f0fae9c
/*  f0fae80:	00000000 */ 	nop
/*  f0fae84:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0fae88:	00897821 */ 	addu	$t7,$a0,$t1
/*  f0fae8c:	10000003 */ 	b	.L0f0fae9c
/*  f0fae90:	a72f0828 */ 	sh	$t7,0x828($t9)
.L0f0fae94:
/*  f0fae94:	8fb800fc */ 	lw	$t8,0xfc($sp)
.L0f0fae98:
/*  f0fae98:	a7000828 */ 	sh	$zero,0x828($t8)
.L0f0fae9c:
/*  f0fae9c:	10ed0002 */ 	beq	$a3,$t5,.L0f0faea8
/*  f0faea0:	3c19800a */ 	lui	$t9,%hi(g_Vars)
/*  f0faea4:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0faea8:
/*  f0faea8:	17e00002 */ 	bnez	$ra,.L0f0faeb4
/*  f0faeac:	00000000 */ 	nop
/*  f0faeb0:	00004825 */ 	or	$t1,$zero,$zero
.L0f0faeb4:
/*  f0faeb4:	11000007 */ 	beqz	$t0,.L0f0faed4
/*  f0faeb8:	00006825 */ 	or	$t5,$zero,$zero
/*  f0faebc:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0faec0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0faec4:	a4600838 */ 	sh	$zero,0x838($v1)
/*  f0faec8:	ac600830 */ 	sw	$zero,0x830($v1)
/*  f0faecc:	10000005 */ 	b	.L0f0faee4
/*  f0faed0:	a4680836 */ 	sh	$t0,0x836($v1)
.L0f0faed4:
/*  f0faed4:	51800004 */ 	beqzl	$t4,.L0f0faee8
/*  f0faed8:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0faedc:	8fae00fc */ 	lw	$t6,0xfc($sp)
/*  f0faee0:	85cc0836 */ 	lh	$t4,0x836($t6)
.L0f0faee4:
/*  f0faee4:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0faee8:
/*  f0faee8:	8c620830 */ 	lw	$v0,0x830($v1)
/*  f0faeec:	2841003d */ 	slti	$at,$v0,0x3d
/*  f0faef0:	14200004 */ 	bnez	$at,.L0f0faf04
/*  f0faef4:	00000000 */ 	nop
/*  f0faef8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0faefc:	a46f0838 */ 	sh	$t7,0x838($v1)
/*  f0faf00:	8c620830 */ 	lw	$v0,0x830($v1)
.L0f0faf04:
/*  f0faf04:	0050001a */ 	div	$zero,$v0,$s0
/*  f0faf08:	8f399fc0 */ 	lw	$t9,%lo(g_Vars)($t9)
/*  f0faf0c:	00003812 */ 	mflo	$a3
/*  f0faf10:	846e0838 */ 	lh	$t6,0x838($v1)
/*  f0faf14:	0059c021 */ 	addu	$t8,$v0,$t9
/*  f0faf18:	0310001a */ 	div	$zero,$t8,$s0
/*  f0faf1c:	16000002 */ 	bnez	$s0,.L0f0faf28
/*  f0faf20:	00000000 */ 	nop
/*  f0faf24:	0007000d */ 	break	0x7
.L0f0faf28:
/*  f0faf28:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0faf2c:	16010004 */ 	bne	$s0,$at,.L0f0faf40
/*  f0faf30:	3c018000 */ 	lui	$at,0x8000
/*  f0faf34:	14410002 */ 	bne	$v0,$at,.L0f0faf40
/*  f0faf38:	00000000 */ 	nop
/*  f0faf3c:	0006000d */ 	break	0x6
.L0f0faf40:
/*  f0faf40:	00004012 */ 	mflo	$t0
/*  f0faf44:	01601025 */ 	or	$v0,$t3,$zero
/*  f0faf48:	16000002 */ 	bnez	$s0,.L0f0faf54
/*  f0faf4c:	00000000 */ 	nop
/*  f0faf50:	0007000d */ 	break	0x7
.L0f0faf54:
/*  f0faf54:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0faf58:	16010004 */ 	bne	$s0,$at,.L0f0faf6c
/*  f0faf5c:	3c018000 */ 	lui	$at,0x8000
/*  f0faf60:	17010002 */ 	bne	$t8,$at,.L0f0faf6c
/*  f0faf64:	00000000 */ 	nop
/*  f0faf68:	0006000d */ 	break	0x6
.L0f0faf6c:
/*  f0faf6c:	15c0000b */ 	bnez	$t6,.L0f0faf9c
/*  f0faf70:	00000000 */ 	nop
/*  f0faf74:	04e10003 */ 	bgez	$a3,.L0f0faf84
/*  f0faf78:	00077843 */ 	sra	$t7,$a3,0x1
/*  f0faf7c:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0faf80:	00017843 */ 	sra	$t7,$at,0x1
.L0f0faf84:
/*  f0faf84:	01e03825 */ 	or	$a3,$t7,$zero
/*  f0faf88:	05010003 */ 	bgez	$t0,.L0f0faf98
/*  f0faf8c:	0008c843 */ 	sra	$t9,$t0,0x1
/*  f0faf90:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0faf94:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0faf98:
/*  f0faf98:	03204025 */ 	or	$t0,$t9,$zero
.L0f0faf9c:
/*  f0faf9c:	05610003 */ 	bgez	$t3,.L0f0fafac
/*  f0fafa0:	a3ac010d */ 	sb	$t4,0x10d($sp)
/*  f0fafa4:	10000001 */ 	b	.L0f0fafac
/*  f0fafa8:	000b1023 */ 	negu	$v0,$t3
.L0f0fafac:
/*  f0fafac:	05410003 */ 	bgez	$t2,.L0f0fafbc
/*  f0fafb0:	28410014 */ 	slti	$at,$v0,0x14
/*  f0fafb4:	10000002 */ 	b	.L0f0fafc0
/*  f0fafb8:	000a1823 */ 	negu	$v1,$t2
.L0f0fafbc:
/*  f0fafbc:	01401825 */ 	or	$v1,$t2,$zero
.L0f0fafc0:
/*  f0fafc0:	1420005d */ 	bnez	$at,.L0f0fb138
/*  f0fafc4:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fafc8:	14200003 */ 	bnez	$at,.L0f0fafd8
/*  f0fafcc:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fafd0:	5240005a */ 	beqzl	$s2,.L0f0fb13c
/*  f0fafd4:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fafd8:
/*  f0fafd8:	05610006 */ 	bgez	$t3,.L0f0faff4
/*  f0fafdc:	28410047 */ 	slti	$at,$v0,0x47
/*  f0fafe0:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fafe4:	84780834 */ 	lh	$t8,0x834($v1)
/*  f0fafe8:	07030003 */ 	bgezl	$t8,.L0f0faff8
/*  f0fafec:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0faff0:	a4600834 */ 	sh	$zero,0x834($v1)
.L0f0faff4:
/*  f0faff4:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0faff8:
/*  f0faff8:	19600005 */ 	blez	$t3,.L0f0fb010
/*  f0faffc:	84640834 */ 	lh	$a0,0x834($v1)
/*  f0fb000:	18800003 */ 	blez	$a0,.L0f0fb010
/*  f0fb004:	00000000 */ 	nop
/*  f0fb008:	a4600834 */ 	sh	$zero,0x834($v1)
/*  f0fb00c:	84640834 */ 	lh	$a0,0x834($v1)
.L0f0fb010:
/*  f0fb010:	14800003 */ 	bnez	$a0,.L0f0fb020
/*  f0fb014:	00000000 */ 	nop
/*  f0fb018:	ac600830 */ 	sw	$zero,0x830($v1)
/*  f0fb01c:	84640834 */ 	lh	$a0,0x834($v1)
.L0f0fb020:
/*  f0fb020:	14200002 */ 	bnez	$at,.L0f0fb02c
/*  f0fb024:	8cc69fc0 */ 	lw	$a2,%lo(g_Vars)($a2)
/*  f0fb028:	24020046 */ 	addiu	$v0,$zero,0x46
.L0f0fb02c:
/*  f0fb02c:	2442ffec */ 	addiu	$v0,$v0,-20
/*  f0fb030:	02820019 */ 	multu	$s4,$v0
/*  f0fb034:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0fb038:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0fb03c:	00007012 */ 	mflo	$t6
/*  f0fb040:	00000000 */ 	nop
/*  f0fb044:	00000000 */ 	nop
/*  f0fb048:	01c1001a */ 	div	$zero,$t6,$at
/*  f0fb04c:	00007812 */ 	mflo	$t7
/*  f0fb050:	026f2823 */ 	subu	$a1,$s3,$t7
/*  f0fb054:	28810003 */ 	slti	$at,$a0,0x3
/*  f0fb058:	10200004 */ 	beqz	$at,.L0f0fb06c
/*  f0fb05c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0fb060:	2881fffe */ 	slti	$at,$a0,-2
/*  f0fb064:	10200006 */ 	beqz	$at,.L0f0fb080
/*  f0fb068:	00000000 */ 	nop
.L0f0fb06c:
/*  f0fb06c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fb070:	00a1001a */ 	div	$zero,$a1,$at
/*  f0fb074:	00001812 */ 	mflo	$v1
/*  f0fb078:	00000000 */ 	nop
/*  f0fb07c:	00000000 */ 	nop
.L0f0fb080:
/*  f0fb080:	5860002b */ 	blezl	$v1,.L0f0fb130
/*  f0fb084:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb088:	8f220830 */ 	lw	$v0,0x830($t9)
/*  f0fb08c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0fb090:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fb094:	0046c021 */ 	addu	$t8,$v0,$a2
/*  f0fb098:	00003812 */ 	mflo	$a3
/*  f0fb09c:	14600002 */ 	bnez	$v1,.L0f0fb0a8
/*  f0fb0a0:	00000000 */ 	nop
/*  f0fb0a4:	0007000d */ 	break	0x7
.L0f0fb0a8:
/*  f0fb0a8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fb0ac:	14610004 */ 	bne	$v1,$at,.L0f0fb0c0
/*  f0fb0b0:	3c018000 */ 	lui	$at,0x8000
/*  f0fb0b4:	14410002 */ 	bne	$v0,$at,.L0f0fb0c0
/*  f0fb0b8:	00000000 */ 	nop
/*  f0fb0bc:	0006000d */ 	break	0x6
.L0f0fb0c0:
/*  f0fb0c0:	0303001a */ 	div	$zero,$t8,$v1
/*  f0fb0c4:	00004012 */ 	mflo	$t0
/*  f0fb0c8:	14600002 */ 	bnez	$v1,.L0f0fb0d4
/*  f0fb0cc:	00000000 */ 	nop
/*  f0fb0d0:	0007000d */ 	break	0x7
.L0f0fb0d4:
/*  f0fb0d4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fb0d8:	14610004 */ 	bne	$v1,$at,.L0f0fb0ec
/*  f0fb0dc:	3c018000 */ 	lui	$at,0x8000
/*  f0fb0e0:	17010002 */ 	bne	$t8,$at,.L0f0fb0ec
/*  f0fb0e4:	00000000 */ 	nop
/*  f0fb0e8:	0006000d */ 	break	0x6
.L0f0fb0ec:
/*  f0fb0ec:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb0f0:	19600003 */ 	blez	$t3,.L0f0fb100
/*  f0fb0f4:	00000000 */ 	nop
/*  f0fb0f8:	10000001 */ 	b	.L0f0fb100
/*  f0fb0fc:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0fb100:
/*  f0fb100:	10e80002 */ 	beq	$a3,$t0,.L0f0fb10c
/*  f0fb104:	008c7021 */ 	addu	$t6,$a0,$t4
/*  f0fb108:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0fb10c:
/*  f0fb10c:	14800002 */ 	bnez	$a0,.L0f0fb118
/*  f0fb110:	00000000 */ 	nop
/*  f0fb114:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0fb118:
/*  f0fb118:	51a00005 */ 	beqzl	$t5,.L0f0fb130
/*  f0fb11c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb120:	a46e0834 */ 	sh	$t6,0x834($v1)
/*  f0fb124:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fb128:	8cc69fc0 */ 	lw	$a2,%lo(g_Vars)($a2)
/*  f0fb12c:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fb130:
/*  f0fb130:	10000006 */ 	b	.L0f0fb14c
/*  f0fb134:	8c620830 */ 	lw	$v0,0x830($v1)
.L0f0fb138:
/*  f0fb138:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fb13c:
/*  f0fb13c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fb140:	a4600834 */ 	sh	$zero,0x834($v1)
/*  f0fb144:	8cc69fc0 */ 	lw	$a2,%lo(g_Vars)($a2)
/*  f0fb148:	8c620830 */ 	lw	$v0,0x830($v1)
.L0f0fb14c:
/*  f0fb14c:	10e80002 */ 	beq	$a3,$t0,.L0f0fb158
/*  f0fb150:	27b50104 */ 	addiu	$s5,$sp,0x104
/*  f0fb154:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0fb158:
/*  f0fb158:	55a00003 */ 	bnezl	$t5,.L0f0fb168
/*  f0fb15c:	8c6f0824 */ 	lw	$t7,0x824($v1)
/*  f0fb160:	00006025 */ 	or	$t4,$zero,$zero
/*  f0fb164:	8c6f0824 */ 	lw	$t7,0x824($v1)
.L0f0fb168:
/*  f0fb168:	8fa500f8 */ 	lw	$a1,0xf8($sp)
/*  f0fb16c:	3c18800a */ 	lui	$t8,%hi(g_Vars)
/*  f0fb170:	01e6c821 */ 	addu	$t9,$t7,$a2
/*  f0fb174:	ac790824 */ 	sw	$t9,0x824($v1)
/*  f0fb178:	8f189fc0 */ 	lw	$t8,%lo(g_Vars)($t8)
/*  f0fb17c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fb180:	00587021 */ 	addu	$t6,$v0,$t8
/*  f0fb184:	ac6e0830 */ 	sw	$t6,0x830($v1)
/*  f0fb188:	a3a90104 */ 	sb	$t1,0x104($sp)
/*  f0fb18c:	a3ac0105 */ 	sb	$t4,0x105($sp)
/*  f0fb190:	a3aa0108 */ 	sb	$t2,0x108($sp)
/*  f0fb194:	a3ab0109 */ 	sb	$t3,0x109($sp)
/*  f0fb198:	10a00003 */ 	beqz	$a1,.L0f0fb1a8
/*  f0fb19c:	a3a00118 */ 	sb	$zero,0x118($sp)
/*  f0fb1a0:	10000002 */ 	b	.L0f0fb1ac
/*  f0fb1a4:	a3af010e */ 	sb	$t7,0x10e($sp)
.L0f0fb1a8:
/*  f0fb1a8:	a3a0010e */ 	sb	$zero,0x10e($sp)
.L0f0fb1ac:
/*  f0fb1ac:	8ee30000 */ 	lw	$v1,0x0($s7)
/*  f0fb1b0:	007e0019 */ 	multu	$v1,$s8
/*  f0fb1b4:	0000c812 */ 	mflo	$t9
/*  f0fb1b8:	02d93821 */ 	addu	$a3,$s6,$t9
/*  f0fb1bc:	8ce404f8 */ 	lw	$a0,0x4f8($a3)
/*  f0fb1c0:	50800016 */ 	beqzl	$a0,.L0f0fb21c
/*  f0fb1c4:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb1c8:	50a00014 */ 	beqzl	$a1,.L0f0fb21c
/*  f0fb1cc:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb1d0:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f0fb1d4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fb1d8:	8f0e0010 */ 	lw	$t6,0x10($t8)
/*  f0fb1dc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fb1e0:	31cf0004 */ 	andi	$t7,$t6,0x4
/*  f0fb1e4:	51e00004 */ 	beqzl	$t7,.L0f0fb1f8
/*  f0fb1e8:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f0fb1ec:	a3b90106 */ 	sb	$t9,0x106($sp)
/*  f0fb1f0:	afb8011c */ 	sw	$t8,0x11c($sp)
/*  f0fb1f4:	8c820008 */ 	lw	$v0,0x8($a0)
.L0f0fb1f8:
/*  f0fb1f8:	50400008 */ 	beqzl	$v0,.L0f0fb21c
/*  f0fb1fc:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb200:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f0fb204:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fb208:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fb20c:	55c10003 */ 	bnel	$t6,$at,.L0f0fb21c
/*  f0fb210:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb214:	a3af0106 */ 	sb	$t7,0x106($sp)
/*  f0fb218:	84e204f4 */ 	lh	$v0,0x4f4($a3)
.L0f0fb21c:
/*  f0fb21c:	00009825 */ 	or	$s3,$zero,$zero
/*  f0fb220:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0fb224:	1840003a */ 	blez	$v0,.L0f0fb310
/*  f0fb228:	00000000 */ 	nop
/*  f0fb22c:	afa00044 */ 	sw	$zero,0x44($sp)
.L0f0fb230:
/*  f0fb230:	0003c8c0 */ 	sll	$t9,$v1,0x3
/*  f0fb234:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb238:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fb23c:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f0fb240:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fb244:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f0fb248:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb24c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fb250:	02d9c021 */ 	addu	$t8,$s6,$t9
/*  f0fb254:	030e9021 */ 	addu	$s2,$t8,$t6
/*  f0fb258:	824f0478 */ 	lb	$t7,0x478($s2)
/*  f0fb25c:	26520464 */ 	addiu	$s2,$s2,0x464
/*  f0fb260:	02408825 */ 	or	$s1,$s2,$zero
/*  f0fb264:	19e00024 */ 	blez	$t7,.L0f0fb2f8
/*  f0fb268:	00008025 */ 	or	$s0,$zero,$zero
/*  f0fb26c:	8ef80000 */ 	lw	$t8,0x0($s7)
.L0f0fb270:
/*  f0fb270:	26990001 */ 	addiu	$t9,$s4,0x1
/*  f0fb274:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fb278:	031e0019 */ 	multu	$t8,$s8
/*  f0fb27c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0fb280:	00007012 */ 	mflo	$t6
/*  f0fb284:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f0fb288:	85f804f4 */ 	lh	$t8,0x4f4($t7)
/*  f0fb28c:	17380008 */ 	bne	$t9,$t8,.L0f0fb2b0
/*  f0fb290:	00000000 */ 	nop
/*  f0fb294:	824e0015 */ 	lb	$t6,0x15($s2)
/*  f0fb298:	160e0005 */ 	bne	$s0,$t6,.L0f0fb2b0
/*  f0fb29c:	00000000 */ 	nop
/*  f0fb2a0:	16600003 */ 	bnez	$s3,.L0f0fb2b0
/*  f0fb2a4:	00000000 */ 	nop
/*  f0fb2a8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb2ac:	24130001 */ 	addiu	$s3,$zero,0x1
.L0f0fb2b0:
/*  f0fb2b0:	0fc3e4d7 */ 	jal	dialogTick
/*  f0fb2b4:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f0fb2b8:	824f0014 */ 	lb	$t7,0x14($s2)
/*  f0fb2bc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0fb2c0:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0fb2c4:	020f082a */ 	slt	$at,$s0,$t7
/*  f0fb2c8:	5420ffe9 */ 	bnezl	$at,.L0f0fb270
/*  f0fb2cc:	8ef80000 */ 	lw	$t8,0x0($s7)
/*  f0fb2d0:	8ee30000 */ 	lw	$v1,0x0($s7)
/*  f0fb2d4:	0003c8c0 */ 	sll	$t9,$v1,0x3
/*  f0fb2d8:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb2dc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fb2e0:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f0fb2e4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fb2e8:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb2ec:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fb2f0:	02d93821 */ 	addu	$a3,$s6,$t9
/*  f0fb2f4:	84e204f4 */ 	lh	$v0,0x4f4($a3)
.L0f0fb2f8:
/*  f0fb2f8:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f0fb2fc:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0fb300:	0282082a */ 	slt	$at,$s4,$v0
/*  f0fb304:	270e0018 */ 	addiu	$t6,$t8,0x18
/*  f0fb308:	1420ffc9 */ 	bnez	$at,.L0f0fb230
/*  f0fb30c:	afae0044 */ 	sw	$t6,0x44($sp)
.L0f0fb310:
/*  f0fb310:	3c0f800a */ 	lui	$t7,%hi(g_MenuData+0x4)
/*  f0fb314:	8def19c4 */ 	lw	$t7,%lo(g_MenuData+0x4)($t7)
/*  f0fb318:	25f9ffff */ 	addiu	$t9,$t7,-1
/*  f0fb31c:	2f21000d */ 	sltiu	$at,$t9,0xd
/*  f0fb320:	1020004d */ 	beqz	$at,.L0f0fb458
/*  f0fb324:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fb328:	3c017f1b */ 	lui	$at,%hi(var7f1b2a98)
/*  f0fb32c:	00390821 */ 	addu	$at,$at,$t9
/*  f0fb330:	8c392a98 */ 	lw	$t9,%lo(var7f1b2a98)($at)
/*  f0fb334:	03200008 */ 	jr	$t9
/*  f0fb338:	00000000 */ 	nop
/*  f0fb33c:	83b8010e */ 	lb	$t8,0x10e($sp)
/*  f0fb340:	8fae011c */ 	lw	$t6,0x11c($sp)
/*  f0fb344:	53000045 */ 	beqzl	$t8,.L0f0fb45c
/*  f0fb348:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb34c:	55c00043 */ 	bnezl	$t6,.L0f0fb45c
/*  f0fb350:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb354:	8ce404f8 */ 	lw	$a0,0x4f8($a3)
/*  f0fb358:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0fb35c:	5080003f */ 	beqzl	$a0,.L0f0fb45c
/*  f0fb360:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb364:	8df9000c */ 	lw	$t9,0xc($t7)
/*  f0fb368:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x490)
/*  f0fb36c:	5720003b */ 	bnezl	$t9,.L0f0fb45c
/*  f0fb370:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb374:	8f18a450 */ 	lw	$t8,%lo(g_Vars+0x490)($t8)
/*  f0fb378:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0fb37c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fb380:	13010008 */ 	beq	$t8,$at,.L0f0fb3a4
/*  f0fb384:	3c048008 */ 	lui	$a0,%hi(g_MpReadyMenuDialog)
/*  f0fb388:	248457b8 */ 	addiu	$a0,$a0,%lo(g_MpReadyMenuDialog)
/*  f0fb38c:	10820005 */ 	beq	$a0,$v0,.L0f0fb3a4
/*  f0fb390:	00000000 */ 	nop
/*  f0fb394:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0fb398:	00000000 */ 	nop
/*  f0fb39c:	1000002f */ 	b	.L0f0fb45c
/*  f0fb3a0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0fb3a4:
/*  f0fb3a4:	3c0e8008 */ 	lui	$t6,%hi(g_MpQuickTeamGameSetupMenuDialog)
/*  f0fb3a8:	25ce6680 */ 	addiu	$t6,$t6,%lo(g_MpQuickTeamGameSetupMenuDialog)
/*  f0fb3ac:	55c2002b */ 	bnel	$t6,$v0,.L0f0fb45c
/*  f0fb3b0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb3b4:	0fc5fd0a */ 	jal	func0f17f428
/*  f0fb3b8:	00000000 */ 	nop
/*  f0fb3bc:	10000027 */ 	b	.L0f0fb45c
/*  f0fb3c0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb3c4:	3c0f8007 */ 	lui	$t7,%hi(g_InCutscene)
/*  f0fb3c8:	8def0764 */ 	lw	$t7,%lo(g_InCutscene)($t7)
/*  f0fb3cc:	51e00010 */ 	beqzl	$t7,.L0f0fb410
/*  f0fb3d0:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f0fb3d4:	0fc3e048 */ 	jal	func0f0f8120
/*  f0fb3d8:	00000000 */ 	nop
/*  f0fb3dc:	3c198007 */ 	lui	$t9,%hi(g_MpPlayerNum)
/*  f0fb3e0:	8f391448 */ 	lw	$t9,%lo(g_MpPlayerNum)($t9)
/*  f0fb3e4:	3c0e800a */ 	lui	$t6,%hi(g_Menus)
/*  f0fb3e8:	25cee000 */ 	addiu	$t6,$t6,%lo(g_Menus)
/*  f0fb3ec:	0019c0c0 */ 	sll	$t8,$t9,0x3
/*  f0fb3f0:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0fb3f4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fb3f8:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f0fb3fc:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fb400:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0fb404:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fb408:	030e3821 */ 	addu	$a3,$t8,$t6
/*  f0fb40c:	240f000a */ 	addiu	$t7,$zero,0xa
.L0f0fb410:
/*  f0fb410:	a0ef083c */ 	sb	$t7,0x83c($a3)
/*  f0fb414:	83b9010e */ 	lb	$t9,0x10e($sp)
/*  f0fb418:	8fb8011c */ 	lw	$t8,0x11c($sp)
/*  f0fb41c:	5320000f */ 	beqzl	$t9,.L0f0fb45c
/*  f0fb420:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb424:	5700000d */ 	bnezl	$t8,.L0f0fb45c
/*  f0fb428:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb42c:	8cee04f8 */ 	lw	$t6,0x4f8($a3)
/*  f0fb430:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0fb434:	51c00009 */ 	beqzl	$t6,.L0f0fb45c
/*  f0fb438:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb43c:	8df90000 */ 	lw	$t9,0x0($t7)
/*  f0fb440:	8f380010 */ 	lw	$t8,0x10($t9)
/*  f0fb444:	330e0020 */ 	andi	$t6,$t8,0x20
/*  f0fb448:	55c00004 */ 	bnezl	$t6,.L0f0fb45c
/*  f0fb44c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb450:	0fc3e048 */ 	jal	func0f0f8120
/*  f0fb454:	00000000 */ 	nop
.L0f0fb458:
/*  f0fb458:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0fb45c:
/*  f0fb45c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0fb460:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0fb464:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0fb468:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0fb46c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0fb470:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0fb474:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0fb478:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0fb47c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0fb480:	03e00008 */ 	jr	$ra
/*  f0fb484:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#else
GLOBAL_ASM(
glabel menuProcessInput
.late_rodata
glabel var7f1b2a98
.word menuProcessInput+0xd10
glabel var7f1b2a9c
.word menuProcessInput+0xd10
glabel var7f1b2aa0
.word menuProcessInput+0xc38
glabel var7f1b2aa4
.word menuProcessInput+0xcc0
glabel var7f1b2aa8
.word menuProcessInput+0xd10
glabel var7f1b2aac
.word menuProcessInput+0xd54
glabel var7f1b2ab0
.word menuProcessInput+0xd54
glabel var7f1b2ab4
.word menuProcessInput+0xd54
glabel var7f1b2ab8
.word menuProcessInput+0xd54
glabel var7f1b2abc
.word menuProcessInput+0xd54
glabel var7f1b2ac0
.word menuProcessInput+0xc38
glabel var7f1b2ac4
.word menuProcessInput+0xd54
glabel var7f1b2ac8
.word menuProcessInput+0xd10
.text
/*  f0f6e54:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0f6e58:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0f6e5c:	3c178007 */ 	lui	$s7,0x8007
/*  f0f6e60:	26f73af0 */ 	addiu	$s7,$s7,0x3af0
/*  f0f6e64:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0f6e68:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0f6e6c:	241e0dbc */ 	addiu	$s8,$zero,0xdbc
/*  f0f6e70:	01de0019 */ 	multu	$t6,$s8
/*  f0f6e74:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0f6e78:	3c16800a */ 	lui	$s6,0x800a
/*  f0f6e7c:	26d627c0 */ 	addiu	$s6,$s6,0x27c0
/*  f0f6e80:	3c19800a */ 	lui	$t9,0x800a
/*  f0f6e84:	8f395eb4 */ 	lw	$t9,0x5eb4($t9)
/*  f0f6e88:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0f6e8c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f6e90:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f6e94:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f6e98:	00007812 */ 	mflo	$t7
/*  f0f6e9c:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0f6ea0:	8cf80488 */ 	lw	$t8,0x488($a3)
/*  f0f6ea4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f6ea8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f6eac:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f6eb0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f6eb4:	00006025 */ 	or	$t4,$zero,$zero
/*  f0f6eb8:	00004825 */ 	or	$t1,$zero,$zero
/*  f0f6ebc:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f6ec0:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0f6ec4:	afa0011c */ 	sw	$zero,0x11c($sp)
/*  f0f6ec8:	afa700fc */ 	sw	$a3,0xfc($sp)
/*  f0f6ecc:	17210005 */ 	bne	$t9,$at,.NB0f0f6ee4
/*  f0f6ed0:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f0f6ed4:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f6ed8:	8dcee94c */ 	lw	$t6,-0x16b4($t6)
/*  f0f6edc:	3c01800a */ 	lui	$at,0x800a
/*  f0f6ee0:	ac2e66a8 */ 	sw	$t6,0x66a8($at)
.NB0f0f6ee4:
/*  f0f6ee4:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0f6ee8:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0f6eec:	0fc3b809 */ 	jal	func0f0f1418
/*  f0f6ef0:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0f6ef4:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0f6ef8:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0f6efc:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0f6f00:	01fe0019 */ 	multu	$t7,$s8
/*  f0f6f04:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0f6f08:	a3a00106 */ 	sb	$zero,0x106($sp)
/*  f0f6f0c:	a3a00107 */ 	sb	$zero,0x107($sp)
/*  f0f6f10:	a3a0010a */ 	sb	$zero,0x10a($sp)
/*  f0f6f14:	a3a0010b */ 	sb	$zero,0x10b($sp)
/*  f0f6f18:	00005025 */ 	or	$t2,$zero,$zero
/*  f0f6f1c:	00005825 */ 	or	$t3,$zero,$zero
/*  f0f6f20:	3c0f800a */ 	lui	$t7,0x800a
/*  f0f6f24:	0000c012 */ 	mflo	$t8
/*  f0f6f28:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f0f6f2c:	8f2e0488 */ 	lw	$t6,0x488($t9)
/*  f0f6f30:	51c0031e */ 	beqzl	$t6,.NB0f0f7bac
/*  f0f6f34:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f6f38:	8def5eb4 */ 	lw	$t7,0x5eb4($t7)
/*  f0f6f3c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0f6f40:	afa000f8 */ 	sw	$zero,0xf8($sp)
/*  f0f6f44:	15e1000b */ 	bne	$t7,$at,.NB0f0f6f74
/*  f0f6f48:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f0f6f4c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f6f50:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0f6f54:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0f6f58:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f0f6f5c:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f0f6f60:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f0f6f64:	afb900e0 */ 	sw	$t9,0xe0($sp)
/*  f0f6f68:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f0f6f6c:	1000001b */ 	beqz	$zero,.NB0f0f6fdc
/*  f0f6f70:	afaf00ec */ 	sw	$t7,0xec($sp)
.NB0f0f6f74:
/*  f0f6f74:	27a400d7 */ 	addiu	$a0,$sp,0xd7
/*  f0f6f78:	27a500d6 */ 	addiu	$a1,$sp,0xd6
/*  f0f6f7c:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0f6f80:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0f6f84:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0f6f88:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0f6f8c:	0fc3cf88 */ 	jal	menuGetContPads
/*  f0f6f90:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0f6f94:	83a200d7 */ 	lb	$v0,0xd7($sp)
/*  f0f6f98:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0f6f9c:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0f6fa0:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0f6fa4:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0f6fa8:	04400004 */ 	bltz	$v0,.NB0f0f6fbc
/*  f0f6fac:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0f6fb0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f6fb4:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f0f6fb8:	afa300ec */ 	sw	$v1,0xec($sp)
.NB0f0f6fbc:
/*  f0f6fbc:	83a200d6 */ 	lb	$v0,0xd6($sp)
/*  f0f6fc0:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0f6fc4:	04400005 */ 	bltz	$v0,.NB0f0f6fdc
/*  f0f6fc8:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0f6fcc:	03b8c821 */ 	addu	$t9,$sp,$t8
/*  f0f6fd0:	af2200d8 */ 	sw	$v0,0xd8($t9)
/*  f0f6fd4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f6fd8:	afa300ec */ 	sw	$v1,0xec($sp)
.NB0f0f6fdc:
/*  f0f6fdc:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0f6fe0:	01de0019 */ 	multu	$t6,$s8
/*  f0f6fe4:	00007812 */ 	mflo	$t7
/*  f0f6fe8:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0f6fec:	90e20d9d */ 	lbu	$v0,0xd9d($a3)
/*  f0f6ff0:	1840001a */ 	blez	$v0,.NB0f0f705c
/*  f0f6ff4:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f0f6ff8:	331900ff */ 	andi	$t9,$t8,0xff
/*  f0f6ffc:	17200014 */ 	bnez	$t9,.NB0f0f7050
/*  f0f7000:	a0f80d9d */ 	sb	$t8,0xd9d($a3)
/*  f0f7004:	8cee0da4 */ 	lw	$t6,0xda4($a3)
/*  f0f7008:	8cef0da8 */ 	lw	$t7,0xda8($a3)
/*  f0f700c:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0f7010:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0f7014:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f7018:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0f701c:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0f7020:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0f7024:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0f7028:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0f702c:	afae00cc */ 	sw	$t6,0xcc($sp)
/*  f0f7030:	0fc41358 */ 	jal	filemgrSaveOrLoad
/*  f0f7034:	a7af00d0 */ 	sh	$t7,0xd0($sp)
/*  f0f7038:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0f703c:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0f7040:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0f7044:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0f7048:	10000004 */ 	beqz	$zero,.NB0f0f705c
/*  f0f704c:	8fac012c */ 	lw	$t4,0x12c($sp)
.NB0f0f7050:
/*  f0f7050:	90f90d9c */ 	lbu	$t9,0xd9c($a3)
/*  f0f7054:	372e0080 */ 	ori	$t6,$t9,0x80
/*  f0f7058:	a0ee0d9c */ 	sb	$t6,0xd9c($a3)
.NB0f0f705c:
/*  f0f705c:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f0f7060:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0f7064:	19e00083 */ 	blez	$t7,.NB0f0f7274
/*  f0f7068:	27b300d8 */ 	addiu	$s3,$sp,0xd8
.NB0f0f706c:
/*  f0f706c:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0f7070:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0f7074:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0f7078:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0f707c:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0f7080:	0c00573c */ 	jal	joyGetStickX
/*  f0f7084:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0f7088:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0f708c:	0010c603 */ 	sra	$t8,$s0,0x18
/*  f0f7090:	03008025 */ 	or	$s0,$t8,$zero
/*  f0f7094:	0c005766 */ 	jal	joyGetStickY
/*  f0f7098:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0f709c:	00028e00 */ 	sll	$s1,$v0,0x18
/*  f0f70a0:	0011ce03 */ 	sra	$t9,$s1,0x18
/*  f0f70a4:	03208825 */ 	or	$s1,$t9,$zero
/*  f0f70a8:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0f70ac:	0c005790 */ 	jal	joyGetButtons
/*  f0f70b0:	3405ffff */ 	dli	$a1,0xffff
/*  f0f70b4:	3052ffff */ 	andi	$s2,$v0,0xffff
/*  f0f70b8:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0f70bc:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0f70c0:	3405ffff */ 	dli	$a1,0xffff
/*  f0f70c4:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0f70c8:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0f70cc:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0f70d0:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0f70d4:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0f70d8:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0f70dc:	11c00003 */ 	beqz	$t6,.NB0f0f70ec
/*  f0f70e0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f70e4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f70e8:	a3af0106 */ 	sb	$t7,0x106($sp)
.NB0f0f70ec:
/*  f0f70ec:	30d84000 */ 	andi	$t8,$a2,0x4000
/*  f0f70f0:	13000003 */ 	beqz	$t8,.NB0f0f7100
/*  f0f70f4:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f0f70f8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f70fc:	a3b90107 */ 	sb	$t9,0x107($sp)
.NB0f0f7100:
/*  f0f7100:	11c00003 */ 	beqz	$t6,.NB0f0f7110
/*  f0f7104:	30d81000 */ 	andi	$t8,$a2,0x1000
/*  f0f7108:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f710c:	a3af0106 */ 	sb	$t7,0x106($sp)
.NB0f0f7110:
/*  f0f7110:	13000003 */ 	beqz	$t8,.NB0f0f7120
/*  f0f7114:	324e0010 */ 	andi	$t6,$s2,0x10
/*  f0f7118:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f711c:	afb900f8 */ 	sw	$t9,0xf8($sp)
.NB0f0f7120:
/*  f0f7120:	11c00003 */ 	beqz	$t6,.NB0f0f7130
/*  f0f7124:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f7128:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f712c:	a3af010a */ 	sb	$t7,0x10a($sp)
.NB0f0f7130:
/*  f0f7130:	30b80020 */ 	andi	$t8,$a1,0x20
/*  f0f7134:	13000003 */ 	beqz	$t8,.NB0f0f7144
/*  f0f7138:	30ae0008 */ 	andi	$t6,$a1,0x8
/*  f0f713c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f7140:	a3b9010a */ 	sb	$t9,0x10a($sp)
.NB0f0f7144:
/*  f0f7144:	05410003 */ 	bgez	$t2,.NB0f0f7154
/*  f0f7148:	30cf0008 */ 	andi	$t7,$a2,0x8
/*  f0f714c:	10000002 */ 	beqz	$zero,.NB0f0f7158
/*  f0f7150:	000a2023 */ 	negu	$a0,$t2
.NB0f0f7154:
/*  f0f7154:	01402025 */ 	or	$a0,$t2,$zero
.NB0f0f7158:
/*  f0f7158:	06010003 */ 	bgez	$s0,.NB0f0f7168
/*  f0f715c:	30b80004 */ 	andi	$t8,$a1,0x4
/*  f0f7160:	10000002 */ 	beqz	$zero,.NB0f0f716c
/*  f0f7164:	00101823 */ 	negu	$v1,$s0
.NB0f0f7168:
/*  f0f7168:	02001825 */ 	or	$v1,$s0,$zero
.NB0f0f716c:
/*  f0f716c:	0083082a */ 	slt	$at,$a0,$v1
/*  f0f7170:	10200002 */ 	beqz	$at,.NB0f0f717c
/*  f0f7174:	30d90004 */ 	andi	$t9,$a2,0x4
/*  f0f7178:	02005025 */ 	or	$t2,$s0,$zero
.NB0f0f717c:
/*  f0f717c:	05610003 */ 	bgez	$t3,.NB0f0f718c
/*  f0f7180:	01602025 */ 	or	$a0,$t3,$zero
/*  f0f7184:	10000001 */ 	beqz	$zero,.NB0f0f718c
/*  f0f7188:	000b2023 */ 	negu	$a0,$t3
.NB0f0f718c:
/*  f0f718c:	06210003 */ 	bgez	$s1,.NB0f0f719c
/*  f0f7190:	02201825 */ 	or	$v1,$s1,$zero
/*  f0f7194:	10000001 */ 	beqz	$zero,.NB0f0f719c
/*  f0f7198:	00111823 */ 	negu	$v1,$s1
.NB0f0f719c:
/*  f0f719c:	0083082a */ 	slt	$at,$a0,$v1
/*  f0f71a0:	10200002 */ 	beqz	$at,.NB0f0f71ac
/*  f0f71a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f71a8:	02205825 */ 	or	$t3,$s1,$zero
.NB0f0f71ac:
/*  f0f71ac:	11c00002 */ 	beqz	$t6,.NB0f0f71b8
/*  f0f71b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f71b4:	240cffff */ 	addiu	$t4,$zero,-1
.NB0f0f71b8:
/*  f0f71b8:	11e00002 */ 	beqz	$t7,.NB0f0f71c4
/*  f0f71bc:	30ae0002 */ 	andi	$t6,$a1,0x2
/*  f0f71c0:	2408ffff */ 	addiu	$t0,$zero,-1
.NB0f0f71c4:
/*  f0f71c4:	13000002 */ 	beqz	$t8,.NB0f0f71d0
/*  f0f71c8:	30cf0002 */ 	andi	$t7,$a2,0x2
/*  f0f71cc:	240c0001 */ 	addiu	$t4,$zero,0x1
.NB0f0f71d0:
/*  f0f71d0:	13200002 */ 	beqz	$t9,.NB0f0f71dc
/*  f0f71d4:	30b80001 */ 	andi	$t8,$a1,0x1
/*  f0f71d8:	24080001 */ 	addiu	$t0,$zero,0x1
.NB0f0f71dc:
/*  f0f71dc:	11c00002 */ 	beqz	$t6,.NB0f0f71e8
/*  f0f71e0:	30d90001 */ 	andi	$t9,$a2,0x1
/*  f0f71e4:	2409ffff */ 	addiu	$t1,$zero,-1
.NB0f0f71e8:
/*  f0f71e8:	11e00002 */ 	beqz	$t7,.NB0f0f71f4
/*  f0f71ec:	30ae0800 */ 	andi	$t6,$a1,0x800
/*  f0f71f0:	2415ffff */ 	addiu	$s5,$zero,-1
.NB0f0f71f4:
/*  f0f71f4:	13000002 */ 	beqz	$t8,.NB0f0f7200
/*  f0f71f8:	30cf0800 */ 	andi	$t7,$a2,0x800
/*  f0f71fc:	24090001 */ 	addiu	$t1,$zero,0x1
.NB0f0f7200:
/*  f0f7200:	13200002 */ 	beqz	$t9,.NB0f0f720c
/*  f0f7204:	30b80400 */ 	andi	$t8,$a1,0x400
/*  f0f7208:	24150001 */ 	addiu	$s5,$zero,0x1
.NB0f0f720c:
/*  f0f720c:	11c00002 */ 	beqz	$t6,.NB0f0f7218
/*  f0f7210:	30d90400 */ 	andi	$t9,$a2,0x400
/*  f0f7214:	240cffff */ 	addiu	$t4,$zero,-1
.NB0f0f7218:
/*  f0f7218:	11e00002 */ 	beqz	$t7,.NB0f0f7224
/*  f0f721c:	30ae0200 */ 	andi	$t6,$a1,0x200
/*  f0f7220:	2408ffff */ 	addiu	$t0,$zero,-1
.NB0f0f7224:
/*  f0f7224:	13000002 */ 	beqz	$t8,.NB0f0f7230
/*  f0f7228:	30cf0200 */ 	andi	$t7,$a2,0x200
/*  f0f722c:	240c0001 */ 	addiu	$t4,$zero,0x1
.NB0f0f7230:
/*  f0f7230:	13200002 */ 	beqz	$t9,.NB0f0f723c
/*  f0f7234:	30b80100 */ 	andi	$t8,$a1,0x100
/*  f0f7238:	24080001 */ 	addiu	$t0,$zero,0x1
.NB0f0f723c:
/*  f0f723c:	11c00002 */ 	beqz	$t6,.NB0f0f7248
/*  f0f7240:	30d90100 */ 	andi	$t9,$a2,0x100
/*  f0f7244:	2409ffff */ 	addiu	$t1,$zero,-1
.NB0f0f7248:
/*  f0f7248:	11e00002 */ 	beqz	$t7,.NB0f0f7254
/*  f0f724c:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f0f7250:	2415ffff */ 	addiu	$s5,$zero,-1
.NB0f0f7254:
/*  f0f7254:	13000002 */ 	beqz	$t8,.NB0f0f7260
/*  f0f7258:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0f725c:	24090001 */ 	addiu	$t1,$zero,0x1
.NB0f0f7260:
/*  f0f7260:	13200002 */ 	beqz	$t9,.NB0f0f726c
/*  f0f7264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7268:	24150001 */ 	addiu	$s5,$zero,0x1
.NB0f0f726c:
/*  f0f726c:	168eff7f */ 	bne	$s4,$t6,.NB0f0f706c
/*  f0f7270:	26730004 */ 	addiu	$s3,$s3,0x4
.NB0f0f7274:
/*  f0f7274:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0f7278:	93ae0106 */ 	lbu	$t6,0x106($sp)
/*  f0f727c:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f0f7280:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f7284:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7288:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f728c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7290:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f7294:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7298:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f729c:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f0f72a0:	11c00002 */ 	beqz	$t6,.NB0f0f72ac
/*  f0f72a4:	8f240488 */ 	lw	$a0,0x488($t9)
/*  f0f72a8:	a3a00107 */ 	sb	$zero,0x107($sp)
.NB0f0f72ac:
/*  f0f72ac:	11000002 */ 	beqz	$t0,.NB0f0f72b8
/*  f0f72b0:	2406001e */ 	addiu	$a2,$zero,0x1e
/*  f0f72b4:	01006025 */ 	or	$t4,$t0,$zero
.NB0f0f72b8:
/*  f0f72b8:	12a00002 */ 	beqz	$s5,.NB0f0f72c4
/*  f0f72bc:	2413003c */ 	addiu	$s3,$zero,0x3c
/*  f0f72c0:	02a04825 */ 	or	$t1,$s5,$zero
.NB0f0f72c4:
/*  f0f72c4:	24110021 */ 	addiu	$s1,$zero,0x21
/*  f0f72c8:	2414002c */ 	addiu	$s4,$zero,0x2c
/*  f0f72cc:	10800019 */ 	beqz	$a0,.NB0f0f7334
/*  f0f72d0:	00009025 */ 	or	$s2,$zero,$zero
/*  f0f72d4:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f0f72d8:	10400016 */ 	beqz	$v0,.NB0f0f7334
/*  f0f72dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f72e0:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0f72e4:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f72e8:	10610003 */ 	beq	$v1,$at,.NB0f0f72f8
/*  f0f72ec:	24010010 */ 	addiu	$at,$zero,0x10
/*  f0f72f0:	54610009 */ 	bnel	$v1,$at,.NB0f0f7318
/*  f0f72f4:	2401000d */ 	addiu	$at,$zero,0xd
.NB0f0f72f8:
/*  f0f72f8:	8c8f000c */ 	lw	$t7,0xc($a0)
/*  f0f72fc:	51e00006 */ 	beqzl	$t7,.NB0f0f7318
/*  f0f7300:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f7304:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f0f7308:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f0f730c:	2413001e */ 	addiu	$s3,$zero,0x1e
/*  f0f7310:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f0f7314:	2401000d */ 	addiu	$at,$zero,0xd
.NB0f0f7318:
/*  f0f7318:	14610006 */ 	bne	$v1,$at,.NB0f0f7334
/*  f0f731c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7320:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0f7324:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f0f7328:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f0f732c:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f0f7330:	2414000a */ 	addiu	$s4,$zero,0xa
.NB0f0f7334:
/*  f0f7334:	15200004 */ 	bnez	$t1,.NB0f0f7348
/*  f0f7338:	0000f825 */ 	or	$ra,$zero,$zero
/*  f0f733c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f7340:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f7344:	a4780788 */ 	sh	$t8,0x788($v1)
.NB0f0f7348:
/*  f0f7348:	12a00006 */ 	beqz	$s5,.NB0f0f7364
/*  f0f734c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f7350:	a4600788 */ 	sh	$zero,0x788($v1)
/*  f0f7354:	ac600780 */ 	sw	$zero,0x780($v1)
/*  f0f7358:	a4750786 */ 	sh	$s5,0x786($v1)
/*  f0f735c:	10000004 */ 	beqz	$zero,.NB0f0f7370
/*  f0f7360:	241f0001 */ 	addiu	$ra,$zero,0x1
.NB0f0f7364:
/*  f0f7364:	51200003 */ 	beqzl	$t1,.NB0f0f7374
/*  f0f7368:	8c620780 */ 	lw	$v0,0x780($v1)
/*  f0f736c:	84690786 */ 	lh	$t1,0x786($v1)
.NB0f0f7370:
/*  f0f7370:	8c620780 */ 	lw	$v0,0x780($v1)
.NB0f0f7374:
/*  f0f7374:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f7378:	2841003d */ 	slti	$at,$v0,0x3d
/*  f0f737c:	14200004 */ 	bnez	$at,.NB0f0f7390
/*  f0f7380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7384:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f7388:	a4790788 */ 	sh	$t9,0x788($v1)
/*  f0f738c:	8c620780 */ 	lw	$v0,0x780($v1)
.NB0f0f7390:
/*  f0f7390:	0050001a */ 	div	$zero,$v0,$s0
/*  f0f7394:	8dcee6c0 */ 	lw	$t6,-0x1940($t6)
/*  f0f7398:	00003812 */ 	mflo	$a3
/*  f0f739c:	84780788 */ 	lh	$t8,0x788($v1)
/*  f0f73a0:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0f73a4:	01f0001a */ 	div	$zero,$t7,$s0
/*  f0f73a8:	16000002 */ 	bnez	$s0,.NB0f0f73b4
/*  f0f73ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f73b0:	0007000d */ 	break	0x7
.NB0f0f73b4:
/*  f0f73b4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f73b8:	16010004 */ 	bne	$s0,$at,.NB0f0f73cc
/*  f0f73bc:	3c018000 */ 	lui	$at,0x8000
/*  f0f73c0:	14410002 */ 	bne	$v0,$at,.NB0f0f73cc
/*  f0f73c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f73c8:	0006000d */ 	break	0x6
.NB0f0f73cc:
/*  f0f73cc:	00006812 */ 	mflo	$t5
/*  f0f73d0:	16000002 */ 	bnez	$s0,.NB0f0f73dc
/*  f0f73d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f73d8:	0007000d */ 	break	0x7
.NB0f0f73dc:
/*  f0f73dc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f73e0:	16010004 */ 	bne	$s0,$at,.NB0f0f73f4
/*  f0f73e4:	3c018000 */ 	lui	$at,0x8000
/*  f0f73e8:	15e10002 */ 	bne	$t7,$at,.NB0f0f73f4
/*  f0f73ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f73f0:	0006000d */ 	break	0x6
.NB0f0f73f4:
/*  f0f73f4:	1700000b */ 	bnez	$t8,.NB0f0f7424
/*  f0f73f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f73fc:	04e10003 */ 	bgez	$a3,.NB0f0f740c
/*  f0f7400:	0007c843 */ 	sra	$t9,$a3,0x1
/*  f0f7404:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0f7408:	0001c843 */ 	sra	$t9,$at,0x1
.NB0f0f740c:
/*  f0f740c:	03203825 */ 	or	$a3,$t9,$zero
/*  f0f7410:	05a10003 */ 	bgez	$t5,.NB0f0f7420
/*  f0f7414:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f0f7418:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f0f741c:	00017043 */ 	sra	$t6,$at,0x1
.NB0f0f7420:
/*  f0f7420:	01c06825 */ 	or	$t5,$t6,$zero
.NB0f0f7424:
/*  f0f7424:	05410003 */ 	bgez	$t2,.NB0f0f7434
/*  f0f7428:	a3a9010c */ 	sb	$t1,0x10c($sp)
/*  f0f742c:	10000002 */ 	beqz	$zero,.NB0f0f7438
/*  f0f7430:	000a1023 */ 	negu	$v0,$t2
.NB0f0f7434:
/*  f0f7434:	01401025 */ 	or	$v0,$t2,$zero
.NB0f0f7438:
/*  f0f7438:	05610003 */ 	bgez	$t3,.NB0f0f7448
/*  f0f743c:	0046082a */ 	slt	$at,$v0,$a2
/*  f0f7440:	10000002 */ 	beqz	$zero,.NB0f0f744c
/*  f0f7444:	000b1823 */ 	negu	$v1,$t3
.NB0f0f7448:
/*  f0f7448:	01601825 */ 	or	$v1,$t3,$zero
.NB0f0f744c:
/*  f0f744c:	14200065 */ 	bnez	$at,.NB0f0f75e4
/*  f0f7450:	0062082a */ 	slt	$at,$v1,$v0
/*  f0f7454:	14200003 */ 	bnez	$at,.NB0f0f7464
/*  f0f7458:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f745c:	52400062 */ 	beqzl	$s2,.NB0f0f75e8
/*  f0f7460:	8fb800fc */ 	lw	$t8,0xfc($sp)
.NB0f0f7464:
/*  f0f7464:	05410006 */ 	bgez	$t2,.NB0f0f7480
/*  f0f7468:	28410047 */ 	slti	$at,$v0,0x47
/*  f0f746c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f7470:	846f0784 */ 	lh	$t7,0x784($v1)
/*  f0f7474:	59e00003 */ 	blezl	$t7,.NB0f0f7484
/*  f0f7478:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f747c:	a4600784 */ 	sh	$zero,0x784($v1)
.NB0f0f7480:
/*  f0f7480:	8fa300fc */ 	lw	$v1,0xfc($sp)
.NB0f0f7484:
/*  f0f7484:	19400005 */ 	blez	$t2,.NB0f0f749c
/*  f0f7488:	84640784 */ 	lh	$a0,0x784($v1)
/*  f0f748c:	04810003 */ 	bgez	$a0,.NB0f0f749c
/*  f0f7490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7494:	a4600784 */ 	sh	$zero,0x784($v1)
/*  f0f7498:	84640784 */ 	lh	$a0,0x784($v1)
.NB0f0f749c:
/*  f0f749c:	14800003 */ 	bnez	$a0,.NB0f0f74ac
/*  f0f74a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f74a4:	ac600780 */ 	sw	$zero,0x780($v1)
/*  f0f74a8:	84640784 */ 	lh	$a0,0x784($v1)
.NB0f0f74ac:
/*  f0f74ac:	54200003 */ 	bnezl	$at,.NB0f0f74bc
/*  f0f74b0:	00461023 */ 	subu	$v0,$v0,$a2
/*  f0f74b4:	24020046 */ 	addiu	$v0,$zero,0x46
/*  f0f74b8:	00461023 */ 	subu	$v0,$v0,$a2
.NB0f0f74bc:
/*  f0f74bc:	02220019 */ 	multu	$s1,$v0
/*  f0f74c0:	24190046 */ 	addiu	$t9,$zero,0x46
/*  f0f74c4:	03267023 */ 	subu	$t6,$t9,$a2
/*  f0f74c8:	0000c012 */ 	mflo	$t8
/*  f0f74cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f74d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f74d4:	030e001a */ 	div	$zero,$t8,$t6
/*  f0f74d8:	15c00002 */ 	bnez	$t6,.NB0f0f74e4
/*  f0f74dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f74e0:	0007000d */ 	break	0x7
.NB0f0f74e4:
/*  f0f74e4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f74e8:	15c10004 */ 	bne	$t6,$at,.NB0f0f74fc
/*  f0f74ec:	3c018000 */ 	lui	$at,0x8000
/*  f0f74f0:	17010002 */ 	bne	$t8,$at,.NB0f0f74fc
/*  f0f74f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f74f8:	0006000d */ 	break	0x6
.NB0f0f74fc:
/*  f0f74fc:	00007812 */ 	mflo	$t7
/*  f0f7500:	026f2823 */ 	subu	$a1,$s3,$t7
/*  f0f7504:	28810003 */ 	slti	$at,$a0,0x3
/*  f0f7508:	10200004 */ 	beqz	$at,.NB0f0f751c
/*  f0f750c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0f7510:	2881fffe */ 	slti	$at,$a0,-2
/*  f0f7514:	10200005 */ 	beqz	$at,.NB0f0f752c
/*  f0f7518:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0f751c:
/*  f0f751c:	04a10003 */ 	bgez	$a1,.NB0f0f752c
/*  f0f7520:	00051843 */ 	sra	$v1,$a1,0x1
/*  f0f7524:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0f7528:	00011843 */ 	sra	$v1,$at,0x1
.NB0f0f752c:
/*  f0f752c:	1860002f */ 	blez	$v1,.NB0f0f75ec
/*  f0f7530:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7534:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0f7538:	3c18800a */ 	lui	$t8,0x800a
/*  f0f753c:	8f18e6c0 */ 	lw	$t8,-0x1940($t8)
/*  f0f7540:	8f220780 */ 	lw	$v0,0x780($t9)
/*  f0f7544:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0f7548:	0043001a */ 	div	$zero,$v0,$v1
/*  f0f754c:	00587021 */ 	addu	$t6,$v0,$t8
/*  f0f7550:	00003812 */ 	mflo	$a3
/*  f0f7554:	14600002 */ 	bnez	$v1,.NB0f0f7560
/*  f0f7558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f755c:	0007000d */ 	break	0x7
.NB0f0f7560:
/*  f0f7560:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7564:	14610004 */ 	bne	$v1,$at,.NB0f0f7578
/*  f0f7568:	3c018000 */ 	lui	$at,0x8000
/*  f0f756c:	14410002 */ 	bne	$v0,$at,.NB0f0f7578
/*  f0f7570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7574:	0006000d */ 	break	0x6
.NB0f0f7578:
/*  f0f7578:	01c3001a */ 	div	$zero,$t6,$v1
/*  f0f757c:	00006812 */ 	mflo	$t5
/*  f0f7580:	14600002 */ 	bnez	$v1,.NB0f0f758c
/*  f0f7584:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7588:	0007000d */ 	break	0x7
.NB0f0f758c:
/*  f0f758c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7590:	14610004 */ 	bne	$v1,$at,.NB0f0f75a4
/*  f0f7594:	3c018000 */ 	lui	$at,0x8000
/*  f0f7598:	15c10002 */ 	bne	$t6,$at,.NB0f0f75a4
/*  f0f759c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f75a0:	0006000d */ 	break	0x6
.NB0f0f75a4:
/*  f0f75a4:	05410003 */ 	bgez	$t2,.NB0f0f75b4
/*  f0f75a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f75ac:	10000001 */ 	beqz	$zero,.NB0f0f75b4
/*  f0f75b0:	2409ffff */ 	addiu	$t1,$zero,-1
.NB0f0f75b4:
/*  f0f75b4:	10ed0002 */ 	beq	$a3,$t5,.NB0f0f75c0
/*  f0f75b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f75bc:	241f0001 */ 	addiu	$ra,$zero,0x1
.NB0f0f75c0:
/*  f0f75c0:	14800002 */ 	bnez	$a0,.NB0f0f75cc
/*  f0f75c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f75c8:	241f0001 */ 	addiu	$ra,$zero,0x1
.NB0f0f75cc:
/*  f0f75cc:	13e00007 */ 	beqz	$ra,.NB0f0f75ec
/*  f0f75d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f75d4:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0f75d8:	00897821 */ 	addu	$t7,$a0,$t1
/*  f0f75dc:	10000003 */ 	beqz	$zero,.NB0f0f75ec
/*  f0f75e0:	a72f0784 */ 	sh	$t7,0x784($t9)
.NB0f0f75e4:
/*  f0f75e4:	8fb800fc */ 	lw	$t8,0xfc($sp)
.NB0f0f75e8:
/*  f0f75e8:	a7000784 */ 	sh	$zero,0x784($t8)
.NB0f0f75ec:
/*  f0f75ec:	10ed0002 */ 	beq	$a3,$t5,.NB0f0f75f8
/*  f0f75f0:	3c19800a */ 	lui	$t9,0x800a
/*  f0f75f4:	241f0001 */ 	addiu	$ra,$zero,0x1
.NB0f0f75f8:
/*  f0f75f8:	17e00002 */ 	bnez	$ra,.NB0f0f7604
/*  f0f75fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7600:	00004825 */ 	or	$t1,$zero,$zero
.NB0f0f7604:
/*  f0f7604:	11000007 */ 	beqz	$t0,.NB0f0f7624
/*  f0f7608:	00006825 */ 	or	$t5,$zero,$zero
/*  f0f760c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f7610:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0f7614:	a4600794 */ 	sh	$zero,0x794($v1)
/*  f0f7618:	ac60078c */ 	sw	$zero,0x78c($v1)
/*  f0f761c:	10000005 */ 	beqz	$zero,.NB0f0f7634
/*  f0f7620:	a4680792 */ 	sh	$t0,0x792($v1)
.NB0f0f7624:
/*  f0f7624:	51800004 */ 	beqzl	$t4,.NB0f0f7638
/*  f0f7628:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f762c:	8fae00fc */ 	lw	$t6,0xfc($sp)
/*  f0f7630:	85cc0792 */ 	lh	$t4,0x792($t6)
.NB0f0f7634:
/*  f0f7634:	8fa300fc */ 	lw	$v1,0xfc($sp)
.NB0f0f7638:
/*  f0f7638:	8c62078c */ 	lw	$v0,0x78c($v1)
/*  f0f763c:	2841003d */ 	slti	$at,$v0,0x3d
/*  f0f7640:	14200004 */ 	bnez	$at,.NB0f0f7654
/*  f0f7644:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7648:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f764c:	a46f0794 */ 	sh	$t7,0x794($v1)
/*  f0f7650:	8c62078c */ 	lw	$v0,0x78c($v1)
.NB0f0f7654:
/*  f0f7654:	0050001a */ 	div	$zero,$v0,$s0
/*  f0f7658:	8f39e6c0 */ 	lw	$t9,-0x1940($t9)
/*  f0f765c:	00003812 */ 	mflo	$a3
/*  f0f7660:	846e0794 */ 	lh	$t6,0x794($v1)
/*  f0f7664:	0059c021 */ 	addu	$t8,$v0,$t9
/*  f0f7668:	0310001a */ 	div	$zero,$t8,$s0
/*  f0f766c:	16000002 */ 	bnez	$s0,.NB0f0f7678
/*  f0f7670:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7674:	0007000d */ 	break	0x7
.NB0f0f7678:
/*  f0f7678:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f767c:	16010004 */ 	bne	$s0,$at,.NB0f0f7690
/*  f0f7680:	3c018000 */ 	lui	$at,0x8000
/*  f0f7684:	14410002 */ 	bne	$v0,$at,.NB0f0f7690
/*  f0f7688:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f768c:	0006000d */ 	break	0x6
.NB0f0f7690:
/*  f0f7690:	00004012 */ 	mflo	$t0
/*  f0f7694:	01601025 */ 	or	$v0,$t3,$zero
/*  f0f7698:	16000002 */ 	bnez	$s0,.NB0f0f76a4
/*  f0f769c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f76a0:	0007000d */ 	break	0x7
.NB0f0f76a4:
/*  f0f76a4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f76a8:	16010004 */ 	bne	$s0,$at,.NB0f0f76bc
/*  f0f76ac:	3c018000 */ 	lui	$at,0x8000
/*  f0f76b0:	17010002 */ 	bne	$t8,$at,.NB0f0f76bc
/*  f0f76b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f76b8:	0006000d */ 	break	0x6
.NB0f0f76bc:
/*  f0f76bc:	15c0000b */ 	bnez	$t6,.NB0f0f76ec
/*  f0f76c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f76c4:	04e10003 */ 	bgez	$a3,.NB0f0f76d4
/*  f0f76c8:	00077843 */ 	sra	$t7,$a3,0x1
/*  f0f76cc:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0f76d0:	00017843 */ 	sra	$t7,$at,0x1
.NB0f0f76d4:
/*  f0f76d4:	01e03825 */ 	or	$a3,$t7,$zero
/*  f0f76d8:	05010003 */ 	bgez	$t0,.NB0f0f76e8
/*  f0f76dc:	0008c843 */ 	sra	$t9,$t0,0x1
/*  f0f76e0:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0f76e4:	0001c843 */ 	sra	$t9,$at,0x1
.NB0f0f76e8:
/*  f0f76e8:	03204025 */ 	or	$t0,$t9,$zero
.NB0f0f76ec:
/*  f0f76ec:	05610003 */ 	bgez	$t3,.NB0f0f76fc
/*  f0f76f0:	a3ac010d */ 	sb	$t4,0x10d($sp)
/*  f0f76f4:	10000001 */ 	beqz	$zero,.NB0f0f76fc
/*  f0f76f8:	000b1023 */ 	negu	$v0,$t3
.NB0f0f76fc:
/*  f0f76fc:	05410003 */ 	bgez	$t2,.NB0f0f770c
/*  f0f7700:	28410014 */ 	slti	$at,$v0,0x14
/*  f0f7704:	10000002 */ 	beqz	$zero,.NB0f0f7710
/*  f0f7708:	000a1823 */ 	negu	$v1,$t2
.NB0f0f770c:
/*  f0f770c:	01401825 */ 	or	$v1,$t2,$zero
.NB0f0f7710:
/*  f0f7710:	1420005d */ 	bnez	$at,.NB0f0f7888
/*  f0f7714:	0062082a */ 	slt	$at,$v1,$v0
/*  f0f7718:	14200003 */ 	bnez	$at,.NB0f0f7728
/*  f0f771c:	3c06800a */ 	lui	$a2,0x800a
/*  f0f7720:	5240005a */ 	beqzl	$s2,.NB0f0f788c
/*  f0f7724:	8fa300fc */ 	lw	$v1,0xfc($sp)
.NB0f0f7728:
/*  f0f7728:	05610006 */ 	bgez	$t3,.NB0f0f7744
/*  f0f772c:	28410047 */ 	slti	$at,$v0,0x47
/*  f0f7730:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f7734:	84780790 */ 	lh	$t8,0x790($v1)
/*  f0f7738:	07030003 */ 	bgezl	$t8,.NB0f0f7748
/*  f0f773c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f7740:	a4600790 */ 	sh	$zero,0x790($v1)
.NB0f0f7744:
/*  f0f7744:	8fa300fc */ 	lw	$v1,0xfc($sp)
.NB0f0f7748:
/*  f0f7748:	19600005 */ 	blez	$t3,.NB0f0f7760
/*  f0f774c:	84640790 */ 	lh	$a0,0x790($v1)
/*  f0f7750:	18800003 */ 	blez	$a0,.NB0f0f7760
/*  f0f7754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7758:	a4600790 */ 	sh	$zero,0x790($v1)
/*  f0f775c:	84640790 */ 	lh	$a0,0x790($v1)
.NB0f0f7760:
/*  f0f7760:	14800003 */ 	bnez	$a0,.NB0f0f7770
/*  f0f7764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7768:	ac60078c */ 	sw	$zero,0x78c($v1)
/*  f0f776c:	84640790 */ 	lh	$a0,0x790($v1)
.NB0f0f7770:
/*  f0f7770:	14200002 */ 	bnez	$at,.NB0f0f777c
/*  f0f7774:	8cc6e6c0 */ 	lw	$a2,-0x1940($a2)
/*  f0f7778:	24020046 */ 	addiu	$v0,$zero,0x46
.NB0f0f777c:
/*  f0f777c:	2442ffec */ 	addiu	$v0,$v0,-20
/*  f0f7780:	02820019 */ 	multu	$s4,$v0
/*  f0f7784:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0f7788:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0f778c:	00007012 */ 	mflo	$t6
/*  f0f7790:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7794:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7798:	01c1001a */ 	div	$zero,$t6,$at
/*  f0f779c:	00007812 */ 	mflo	$t7
/*  f0f77a0:	026f2823 */ 	subu	$a1,$s3,$t7
/*  f0f77a4:	28810003 */ 	slti	$at,$a0,0x3
/*  f0f77a8:	10200004 */ 	beqz	$at,.NB0f0f77bc
/*  f0f77ac:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0f77b0:	2881fffe */ 	slti	$at,$a0,-2
/*  f0f77b4:	10200006 */ 	beqz	$at,.NB0f0f77d0
/*  f0f77b8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0f77bc:
/*  f0f77bc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f77c0:	00a1001a */ 	div	$zero,$a1,$at
/*  f0f77c4:	00001812 */ 	mflo	$v1
/*  f0f77c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f77cc:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0f77d0:
/*  f0f77d0:	5860002b */ 	blezl	$v1,.NB0f0f7880
/*  f0f77d4:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f77d8:	8f22078c */ 	lw	$v0,0x78c($t9)
/*  f0f77dc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f77e0:	0043001a */ 	div	$zero,$v0,$v1
/*  f0f77e4:	0046c021 */ 	addu	$t8,$v0,$a2
/*  f0f77e8:	00003812 */ 	mflo	$a3
/*  f0f77ec:	14600002 */ 	bnez	$v1,.NB0f0f77f8
/*  f0f77f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f77f4:	0007000d */ 	break	0x7
.NB0f0f77f8:
/*  f0f77f8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f77fc:	14610004 */ 	bne	$v1,$at,.NB0f0f7810
/*  f0f7800:	3c018000 */ 	lui	$at,0x8000
/*  f0f7804:	14410002 */ 	bne	$v0,$at,.NB0f0f7810
/*  f0f7808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f780c:	0006000d */ 	break	0x6
.NB0f0f7810:
/*  f0f7810:	0303001a */ 	div	$zero,$t8,$v1
/*  f0f7814:	00004012 */ 	mflo	$t0
/*  f0f7818:	14600002 */ 	bnez	$v1,.NB0f0f7824
/*  f0f781c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7820:	0007000d */ 	break	0x7
.NB0f0f7824:
/*  f0f7824:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7828:	14610004 */ 	bne	$v1,$at,.NB0f0f783c
/*  f0f782c:	3c018000 */ 	lui	$at,0x8000
/*  f0f7830:	17010002 */ 	bne	$t8,$at,.NB0f0f783c
/*  f0f7834:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7838:	0006000d */ 	break	0x6
.NB0f0f783c:
/*  f0f783c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f7840:	19600003 */ 	blez	$t3,.NB0f0f7850
/*  f0f7844:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7848:	10000001 */ 	beqz	$zero,.NB0f0f7850
/*  f0f784c:	240cffff */ 	addiu	$t4,$zero,-1
.NB0f0f7850:
/*  f0f7850:	10e80002 */ 	beq	$a3,$t0,.NB0f0f785c
/*  f0f7854:	008c7021 */ 	addu	$t6,$a0,$t4
/*  f0f7858:	240d0001 */ 	addiu	$t5,$zero,0x1
.NB0f0f785c:
/*  f0f785c:	14800002 */ 	bnez	$a0,.NB0f0f7868
/*  f0f7860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7864:	240d0001 */ 	addiu	$t5,$zero,0x1
.NB0f0f7868:
/*  f0f7868:	51a00005 */ 	beqzl	$t5,.NB0f0f7880
/*  f0f786c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0f7870:	a46e0790 */ 	sh	$t6,0x790($v1)
/*  f0f7874:	3c06800a */ 	lui	$a2,0x800a
/*  f0f7878:	8cc6e6c0 */ 	lw	$a2,-0x1940($a2)
/*  f0f787c:	8fa300fc */ 	lw	$v1,0xfc($sp)
.NB0f0f7880:
/*  f0f7880:	10000006 */ 	beqz	$zero,.NB0f0f789c
/*  f0f7884:	8c62078c */ 	lw	$v0,0x78c($v1)
.NB0f0f7888:
/*  f0f7888:	8fa300fc */ 	lw	$v1,0xfc($sp)
.NB0f0f788c:
/*  f0f788c:	3c06800a */ 	lui	$a2,0x800a
/*  f0f7890:	a4600790 */ 	sh	$zero,0x790($v1)
/*  f0f7894:	8cc6e6c0 */ 	lw	$a2,-0x1940($a2)
/*  f0f7898:	8c62078c */ 	lw	$v0,0x78c($v1)
.NB0f0f789c:
/*  f0f789c:	10e80002 */ 	beq	$a3,$t0,.NB0f0f78a8
/*  f0f78a0:	27b50104 */ 	addiu	$s5,$sp,0x104
/*  f0f78a4:	240d0001 */ 	addiu	$t5,$zero,0x1
.NB0f0f78a8:
/*  f0f78a8:	55a00003 */ 	bnezl	$t5,.NB0f0f78b8
/*  f0f78ac:	8c6f0780 */ 	lw	$t7,0x780($v1)
/*  f0f78b0:	00006025 */ 	or	$t4,$zero,$zero
/*  f0f78b4:	8c6f0780 */ 	lw	$t7,0x780($v1)
.NB0f0f78b8:
/*  f0f78b8:	8fa500f8 */ 	lw	$a1,0xf8($sp)
/*  f0f78bc:	3c18800a */ 	lui	$t8,0x800a
/*  f0f78c0:	01e6c821 */ 	addu	$t9,$t7,$a2
/*  f0f78c4:	ac790780 */ 	sw	$t9,0x780($v1)
/*  f0f78c8:	8f18e6c0 */ 	lw	$t8,-0x1940($t8)
/*  f0f78cc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f78d0:	00587021 */ 	addu	$t6,$v0,$t8
/*  f0f78d4:	ac6e078c */ 	sw	$t6,0x78c($v1)
/*  f0f78d8:	a3a90104 */ 	sb	$t1,0x104($sp)
/*  f0f78dc:	a3ac0105 */ 	sb	$t4,0x105($sp)
/*  f0f78e0:	a3aa0108 */ 	sb	$t2,0x108($sp)
/*  f0f78e4:	a3ab0109 */ 	sb	$t3,0x109($sp)
/*  f0f78e8:	10a00003 */ 	beqz	$a1,.NB0f0f78f8
/*  f0f78ec:	a3a00118 */ 	sb	$zero,0x118($sp)
/*  f0f78f0:	10000002 */ 	beqz	$zero,.NB0f0f78fc
/*  f0f78f4:	a3af010e */ 	sb	$t7,0x10e($sp)
.NB0f0f78f8:
/*  f0f78f8:	a3a0010e */ 	sb	$zero,0x10e($sp)
.NB0f0f78fc:
/*  f0f78fc:	8ee30000 */ 	lw	$v1,0x0($s7)
/*  f0f7900:	007e0019 */ 	multu	$v1,$s8
/*  f0f7904:	0000c812 */ 	mflo	$t9
/*  f0f7908:	02d93821 */ 	addu	$a3,$s6,$t9
/*  f0f790c:	8ce40488 */ 	lw	$a0,0x488($a3)
/*  f0f7910:	50800016 */ 	beqzl	$a0,.NB0f0f796c
/*  f0f7914:	84e20484 */ 	lh	$v0,0x484($a3)
/*  f0f7918:	50a00014 */ 	beqzl	$a1,.NB0f0f796c
/*  f0f791c:	84e20484 */ 	lh	$v0,0x484($a3)
/*  f0f7920:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f0f7924:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f7928:	8f0e0010 */ 	lw	$t6,0x10($t8)
/*  f0f792c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f7930:	31cf0004 */ 	andi	$t7,$t6,0x4
/*  f0f7934:	51e00004 */ 	beqzl	$t7,.NB0f0f7948
/*  f0f7938:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f0f793c:	a3b90106 */ 	sb	$t9,0x106($sp)
/*  f0f7940:	afb8011c */ 	sw	$t8,0x11c($sp)
/*  f0f7944:	8c820008 */ 	lw	$v0,0x8($a0)
.NB0f0f7948:
/*  f0f7948:	50400008 */ 	beqzl	$v0,.NB0f0f796c
/*  f0f794c:	84e20484 */ 	lh	$v0,0x484($a3)
/*  f0f7950:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f0f7954:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7958:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f795c:	55c10003 */ 	bnel	$t6,$at,.NB0f0f796c
/*  f0f7960:	84e20484 */ 	lh	$v0,0x484($a3)
/*  f0f7964:	a3af0106 */ 	sb	$t7,0x106($sp)
/*  f0f7968:	84e20484 */ 	lh	$v0,0x484($a3)
.NB0f0f796c:
/*  f0f796c:	00009825 */ 	or	$s3,$zero,$zero
/*  f0f7970:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0f7974:	1840003a */ 	blez	$v0,.NB0f0f7a60
/*  f0f7978:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f797c:	afa00044 */ 	sw	$zero,0x44($sp)
.NB0f0f7980:
/*  f0f7980:	0003c8c0 */ 	sll	$t9,$v1,0x3
/*  f0f7984:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0f7988:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f798c:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0f7990:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f7994:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f0f7998:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0f799c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f79a0:	02d9c021 */ 	addu	$t8,$s6,$t9
/*  f0f79a4:	030e9021 */ 	addu	$s2,$t8,$t6
/*  f0f79a8:	824f0408 */ 	lb	$t7,0x408($s2)
/*  f0f79ac:	265203f4 */ 	addiu	$s2,$s2,0x3f4
/*  f0f79b0:	02408825 */ 	or	$s1,$s2,$zero
/*  f0f79b4:	19e00024 */ 	blez	$t7,.NB0f0f7a48
/*  f0f79b8:	00008025 */ 	or	$s0,$zero,$zero
/*  f0f79bc:	8ef80000 */ 	lw	$t8,0x0($s7)
.NB0f0f79c0:
/*  f0f79c0:	26990001 */ 	addiu	$t9,$s4,0x1
/*  f0f79c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f79c8:	031e0019 */ 	multu	$t8,$s8
/*  f0f79cc:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f79d0:	00007012 */ 	mflo	$t6
/*  f0f79d4:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f0f79d8:	85f80484 */ 	lh	$t8,0x484($t7)
/*  f0f79dc:	17380008 */ 	bne	$t9,$t8,.NB0f0f7a00
/*  f0f79e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f79e4:	824e0015 */ 	lb	$t6,0x15($s2)
/*  f0f79e8:	160e0005 */ 	bne	$s0,$t6,.NB0f0f7a00
/*  f0f79ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f79f0:	16600003 */ 	bnez	$s3,.NB0f0f7a00
/*  f0f79f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f79f8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0f79fc:	24130001 */ 	addiu	$s3,$zero,0x1
.NB0f0f7a00:
/*  f0f7a00:	0fc3d6ec */ 	jal	dialogTick
/*  f0f7a04:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f0f7a08:	824f0014 */ 	lb	$t7,0x14($s2)
/*  f0f7a0c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0f7a10:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0f7a14:	020f082a */ 	slt	$at,$s0,$t7
/*  f0f7a18:	5420ffe9 */ 	bnezl	$at,.NB0f0f79c0
/*  f0f7a1c:	8ef80000 */ 	lw	$t8,0x0($s7)
/*  f0f7a20:	8ee30000 */ 	lw	$v1,0x0($s7)
/*  f0f7a24:	0003c8c0 */ 	sll	$t9,$v1,0x3
/*  f0f7a28:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0f7a2c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f7a30:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0f7a34:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f7a38:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0f7a3c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f7a40:	02d93821 */ 	addu	$a3,$s6,$t9
/*  f0f7a44:	84e20484 */ 	lh	$v0,0x484($a3)
.NB0f0f7a48:
/*  f0f7a48:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f0f7a4c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0f7a50:	0282082a */ 	slt	$at,$s4,$v0
/*  f0f7a54:	270e0018 */ 	addiu	$t6,$t8,0x18
/*  f0f7a58:	1420ffc9 */ 	bnez	$at,.NB0f0f7980
/*  f0f7a5c:	afae0044 */ 	sw	$t6,0x44($sp)
.NB0f0f7a60:
/*  f0f7a60:	3c0f800a */ 	lui	$t7,0x800a
/*  f0f7a64:	8def5eb4 */ 	lw	$t7,0x5eb4($t7)
/*  f0f7a68:	25f9ffff */ 	addiu	$t9,$t7,-1
/*  f0f7a6c:	2f21000d */ 	sltiu	$at,$t9,0xd
/*  f0f7a70:	1020004d */ 	beqz	$at,.NB0f0f7ba8
/*  f0f7a74:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f7a78:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f7a7c:	00390821 */ 	addu	$at,$at,$t9
/*  f0f7a80:	8c39cdb4 */ 	lw	$t9,-0x324c($at)
/*  f0f7a84:	03200008 */ 	jr	$t9
/*  f0f7a88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7a8c:	83b8010e */ 	lb	$t8,0x10e($sp)
/*  f0f7a90:	8fae011c */ 	lw	$t6,0x11c($sp)
/*  f0f7a94:	53000045 */ 	beqzl	$t8,.NB0f0f7bac
/*  f0f7a98:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f7a9c:	55c00043 */ 	bnezl	$t6,.NB0f0f7bac
/*  f0f7aa0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f7aa4:	8ce40488 */ 	lw	$a0,0x488($a3)
/*  f0f7aa8:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0f7aac:	5080003f */ 	beqzl	$a0,.NB0f0f7bac
/*  f0f7ab0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f7ab4:	8df9000c */ 	lw	$t9,0xc($t7)
/*  f0f7ab8:	3c18800a */ 	lui	$t8,0x800a
/*  f0f7abc:	5720003b */ 	bnezl	$t9,.NB0f0f7bac
/*  f0f7ac0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f7ac4:	8f18eb50 */ 	lw	$t8,-0x14b0($t8)
/*  f0f7ac8:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0f7acc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7ad0:	13010008 */ 	beq	$t8,$at,.NB0f0f7af4
/*  f0f7ad4:	3c048008 */ 	lui	$a0,0x8008
/*  f0f7ad8:	24847f34 */ 	addiu	$a0,$a0,0x7f34
/*  f0f7adc:	10820005 */ 	beq	$a0,$v0,.NB0f0f7af4
/*  f0f7ae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7ae4:	0fc3beda */ 	jal	menuPushDialog
/*  f0f7ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7aec:	1000002f */ 	beqz	$zero,.NB0f0f7bac
/*  f0f7af0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f0f7af4:
/*  f0f7af4:	3c0e8009 */ 	lui	$t6,0x8009
/*  f0f7af8:	25ce8dfc */ 	addiu	$t6,$t6,-29188
/*  f0f7afc:	55c2002b */ 	bnel	$t6,$v0,.NB0f0f7bac
/*  f0f7b00:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f7b04:	0fc5e6b1 */ 	jal	func0f17f428
/*  f0f7b08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7b0c:	10000027 */ 	beqz	$zero,.NB0f0f7bac
/*  f0f7b10:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f7b14:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0f7b18:	8def2e24 */ 	lw	$t7,0x2e24($t7)
/*  f0f7b1c:	51e00010 */ 	beqzl	$t7,.NB0f0f7b60
/*  f0f7b20:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f0f7b24:	0fc3d2a2 */ 	jal	func0f0f8120
/*  f0f7b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0f7b2c:	3c198007 */ 	lui	$t9,0x8007
/*  f0f7b30:	8f393af0 */ 	lw	$t9,0x3af0($t9)
/*  f0f7b34:	3c0e800a */ 	lui	$t6,0x800a
/*  f0f7b38:	25ce27c0 */ 	addiu	$t6,$t6,0x27c0
/*  f0f7b3c:	0019c0c0 */ 	sll	$t8,$t9,0x3
/*  f0f7b40:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0f7b44:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f7b48:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0f7b4c:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f7b50:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0f7b54:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f7b58:	030e3821 */ 	addu	$a3,$t8,$t6
/*  f0f7b5c:	240f000a */ 	addiu	$t7,$zero,0xa
.NB0f0f7b60:
/*  f0f7b60:	a0ef0798 */ 	sb	$t7,0x798($a3)
/*  f0f7b64:	83b9010e */ 	lb	$t9,0x10e($sp)
/*  f0f7b68:	8fb8011c */ 	lw	$t8,0x11c($sp)
/*  f0f7b6c:	5320000f */ 	beqzl	$t9,.NB0f0f7bac
/*  f0f7b70:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f7b74:	5700000d */ 	bnezl	$t8,.NB0f0f7bac
/*  f0f7b78:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f7b7c:	8cee0488 */ 	lw	$t6,0x488($a3)
/*  f0f7b80:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0f7b84:	51c00009 */ 	beqzl	$t6,.NB0f0f7bac
/*  f0f7b88:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f7b8c:	8df90000 */ 	lw	$t9,0x0($t7)
/*  f0f7b90:	8f380010 */ 	lw	$t8,0x10($t9)
/*  f0f7b94:	330e0020 */ 	andi	$t6,$t8,0x20
/*  f0f7b98:	55c00004 */ 	bnezl	$t6,.NB0f0f7bac
/*  f0f7b9c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f7ba0:	0fc3d2a2 */ 	jal	func0f0f8120
/*  f0f7ba4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0f7ba8:
/*  f0f7ba8:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f0f7bac:
/*  f0f7bac:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f7bb0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f7bb4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f7bb8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f7bbc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f7bc0:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0f7bc4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0f7bc8:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0f7bcc:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0f7bd0:	03e00008 */ 	jr	$ra
/*  f0f7bd4:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#endif

// Mismatch: regalloc in first for loop
//void menuProcessInput(void)
//{
//	s32 yhelddir; // 12c
//	s32 xhelddir; // 128
//	s32 ytapdir; // 124
//	s32 xtapdir; // 120
//	bool starttoselect; // 11c
//	struct menuinputs inputs; // 104
//	struct menudialog *dialog; // 100
//	struct menu *menu; // fc
//	bool starttap; // f8
//	s32 stickx; // f4
//	s32 sticky; // f0
//	s32 numcontpads; // ec
//	s32 i;
//	s32 contpadnums[4]; // d8
//	s8 contpadnum1; // d7
//	s8 contpadnum2; // d6
//	struct fileguid guid; // cc
//	s32 xdeadzone;
//	s32 ydeadzone;
//	s32 digitalrepeatinterval;
//	s32 xstickintervalmult;
//	s32 stickintervalbase;
//	s32 ystickintervalmult;
//	s32 allowdiagonal;
//
//	yhelddir = 0;
//	xhelddir = 0;
//	ytapdir = 0;
//	xtapdir = 0;
//	starttoselect = false;
//
//	menu = &g_Menus[g_MpPlayerNum];
//	dialog = g_Menus[g_MpPlayerNum].curdialog;
//
//	if (g_MenuData.root == MENUROOT_MPPAUSE) {
//		g_AmIndex = g_Vars.currentplayernum;
//	}
//
//	func0f0f1418();
//
//	inputs.select = 0;
//	inputs.back = 0;
//	inputs.shoulder = 0;
//	inputs.back2 = 0;
//
//	if (g_Menus[g_MpPlayerNum].curdialog) {
//		stickx = 0;
//		sticky = 0;
//		starttap = false;
//		numcontpads = 0;
//
//		// Decide which controller pads will control this player's menu
//		if (g_MenuData.root == MENUROOT_BOOTPAKMGR) {
//			contpadnums[0] = 0;
//			contpadnums[1] = 1;
//			contpadnums[2] = 2;
//			contpadnums[3] = 3;
//			numcontpads = 4;
//		} else {
//			menuGetContPads(&contpadnum1, &contpadnum2);
//
//			if (contpadnum1 >= 0) {
//				contpadnums[numcontpads] = contpadnum1;
//				numcontpads++;
//			}
//
//			if (contpadnum2 >= 0) {
//				contpadnums[numcontpads] = contpadnum2;
//				numcontpads++;
//			}
//		}
//
//		// Handle some kind of file save/load timer
//		if (g_Menus[g_MpPlayerNum].fm.unke41 > 0) {
//			g_Menus[g_MpPlayerNum].fm.unke41--;
//
//			if (g_Menus[g_MpPlayerNum].fm.unke41 == 0) {
//				guid.fileid = g_Menus[g_MpPlayerNum].fm.fileid;
//				guid.deviceserial = g_Menus[g_MpPlayerNum].fm.deviceserial;
//
//				filemgrSaveOrLoad(&guid, -1, 0);
//			} else {
//				g_Menus[g_MpPlayerNum].fm.unke40_00 = true;
//			}
//		}
//
//		// Iterate controllers and figure out which buttons are being pressed.
//		// For the control stick input, take whichever stick is pressed the most.
//		for (i = 0; i < numcontpads; i++) {
//			s8 thisstickx = joyGetStickX(contpadnums[i]);
//			s8 thissticky = joyGetStickY(contpadnums[i]);
//			u16 buttons = joyGetButtons(contpadnums[i], 0xffff);
//			s32 buttonsnow = joyGetButtonsPressedThisFrame(contpadnums[i], 0xffff);
//
//			if (buttonsnow & A_BUTTON) {
//				inputs.select = 1;
//			}
//
//			if (buttonsnow & B_BUTTON) {
//				inputs.back = 1;
//			}
//
//			if (buttonsnow & Z_TRIG) {
//				inputs.select = 1;
//			}
//
//			if (buttonsnow & START_BUTTON) {
//				starttap = true;
//			}
//
//			if (buttons & R_TRIG) {
//				inputs.shoulder = 1;
//			}
//
//			if (buttons & L_TRIG) {
//				inputs.shoulder = 1;
//			}
//
//			if ((stickx < 0 ? -stickx : stickx) < (thisstickx < 0 ? -thisstickx : thisstickx)) {
//				stickx = thisstickx;
//			}
//
//			if ((sticky < 0 ? -sticky : sticky) < (thissticky < 0 ? -thissticky : thissticky)) {
//				sticky = thissticky;
//			}
//
//			if (buttons & U_CBUTTONS) {
//				yhelddir = -1;
//			}
//
//			if (buttonsnow & U_CBUTTONS) {
//				ytapdir = -1;
//			}
//
//			if (buttons & D_CBUTTONS) {
//				yhelddir = 1;
//			}
//
//			if (buttonsnow & D_CBUTTONS) {
//				ytapdir = 1;
//			}
//
//			if (buttons & L_CBUTTONS) {
//				xhelddir = -1;
//			}
//
//			if (buttonsnow & L_CBUTTONS) {
//				xtapdir = -1;
//			}
//
//			if (buttons & R_CBUTTONS) {
//				xhelddir = 1;
//			}
//
//			if (buttonsnow & R_CBUTTONS) {
//				xtapdir = 1;
//			}
//
//			if (buttons & U_JPAD) {
//				yhelddir = -1;
//			}
//
//			if (buttonsnow & U_JPAD) {
//				ytapdir = -1;
//			}
//
//			if (buttons & D_JPAD) {
//				yhelddir = 1;
//			}
//
//			if (buttonsnow & D_JPAD) {
//				ytapdir = 1;
//			}
//
//			if (buttons & L_JPAD) {
//				xhelddir = -1;
//			}
//
//			if (buttonsnow & L_JPAD) {
//				xtapdir = -1;
//			}
//
//			if (buttons & R_JPAD) {
//				xhelddir = 1;
//			}
//
//			if (buttonsnow & R_JPAD) {
//				xtapdir = 1;
//			}
//		}
//
//		// Prevent select and going back on the same frame
//		if (inputs.select) {
//			inputs.back = 0;
//		}
//
//		if (ytapdir != 0) {
//			yhelddir = ytapdir;
//		}
//
//		if (xtapdir != 0) {
//			xhelddir = xtapdir;
//		}
//
//		// Choose repeat rate settings
//		digitalrepeatinterval = 10;
//		xdeadzone = 30;
//		ydeadzone = 20;
//		stickintervalbase = 60;
//		xstickintervalmult = 33;
//		ystickintervalmult = 44;
//		allowdiagonal = false;
//
//		if (g_Menus[g_MpPlayerNum].curdialog) {
//			struct menuitem *item = g_Menus[g_MpPlayerNum].curdialog->focuseditem;
//
//			if (item) {
//				if (item->type == MENUITEMTYPE_SLIDER || item->type == MENUITEMTYPE_10) {
//					if (g_Menus[g_MpPlayerNum].curdialog->dimmed) {
//						digitalrepeatinterval = PALDOWN(5);
//						xdeadzone = 20;
//						stickintervalbase = 30;
//						xstickintervalmult = 10;
//					}
//				}
//
//				if (item->type == MENUITEMTYPE_KEYBOARD) {
//					allowdiagonal = true;
//					digitalrepeatinterval = PALDOWN(5);
//					xdeadzone = 20;
//					xstickintervalmult = 10;
//					ystickintervalmult = 10;
//				}
//			}
//		}
//
//		// Handle left/right repeat
//		{
//			s32 absstickx;
//			s32 abssticky;
//			s32 oldslot;
//			s32 newslot;
//			s32 interval;
//			bool apply = false;
//
//			// This check doesn't exist in the up/down code later on...
//			// It's likely unnecessary
//			if (xhelddir == 0) {
//				menu->xrepeatmode = MENUREPEATMODE_RELEASED;
//			}
//
//			if (xtapdir != 0) {
//				// Direction was pressed this frame - reset the repeat properties
//				menu->xrepeatmode = MENUREPEATMODE_SLOW;
//				menu->xrepeattimer60 = 0;
//				menu->xrepeatdir = xtapdir;
//				apply = true;
//			} else if (xhelddir != 0) {
//				xhelddir = menu->xrepeatdir;
//			}
//
//			// If held for 1 second, repeat faster
//			if (menu->xrepeattimer60 > PALDOWN(60)) {
//				menu->xrepeatmode = MENUREPEATMODE_FAST;
//			}
//
//			// Calculate the old and new repeat slots.
//			// If these are different, the repeat will be applied on this tick.
//			oldslot = menu->xrepeattimer60 / digitalrepeatinterval;
//			newslot = (menu->xrepeattimer60 + g_Vars.diffframe60) / digitalrepeatinterval;
//
//			if (menu->xrepeatmode == MENUREPEATMODE_SLOW) {
//				oldslot /= 2;
//				newslot /= 2;
//			}
//
//			inputs.leftrightheld = xhelddir;
//
//			// Check if the stick is being pushed left or right
//			absstickx = stickx < 0 ? -stickx : stickx;
//			abssticky = sticky < 0 ? -sticky : sticky;
//
//			if (absstickx >= xdeadzone && (absstickx > abssticky || allowdiagonal)) {
//				// Reset the repeat if it's a different direction
//				if (stickx < 0 && menu->xrepeatcount > 0) {
//					menu->xrepeatcount = 0;
//				}
//
//				if (stickx > 0 && menu->xrepeatcount < 0) {
//					menu->xrepeatcount = 0;
//				}
//
//				if (menu->xrepeatcount == 0) {
//					menu->xrepeattimer60 = 0;
//				}
//
//				// Calculate the repeat interval based on the stick pressure
//				if (absstickx > 70) {
//					absstickx = 70;
//				}
//
//				absstickx -= xdeadzone;
//				interval = stickintervalbase - xstickintervalmult * absstickx / (70 - xdeadzone);
//
//				// After 3 repeats, halve the interval (ie. make faster)
//				if (menu->xrepeatcount >= 3 || menu->xrepeatcount <= -3) {
//					interval /= 2;
//				}
//
//				if (interval > 0) {
//#if PAL
//					if (interval > 3) {
//						interval = PALDOWN(interval);
//					}
//#endif
//					oldslot = menu->xrepeattimer60 / interval;
//					newslot = (menu->xrepeattimer60 + g_Vars.diffframe60) / interval;
//
//					xhelddir = stickx < 0 ? -1 : 1;
//
//					if (oldslot != newslot) {
//						apply = true;
//					}
//
//					if (menu->xrepeatcount == 0) {
//						apply = true;
//					}
//
//					if (apply) {
//						menu->xrepeatcount += xhelddir;
//					}
//				}
//			} else {
//				menu->xrepeatcount = 0;
//			}
//
//			if (oldslot != newslot) {
//				apply = true;
//			}
//
//			if (!apply) {
//				xhelddir = 0;
//			}
//		}
//
//		// Handle up/down repeat
//		{
//			s32 absstickx;
//			s32 abssticky;
//			s32 oldslot;
//			s32 newslot;
//			s32 interval;
//			bool apply = false;
//
//			if (ytapdir != 0) {
//				// Direction was pressed this frame - reset the repeat properties
//				apply = true;
//				menu->yrepeatmode = MENUREPEATMODE_SLOW;
//				menu->yrepeattimer60 = 0;
//				menu->yrepeatdir = ytapdir;
//			} else if (yhelddir != 0) {
//				yhelddir = menu->yrepeatdir;
//			}
//
//			// If held for 1 second, repeat faster
//			if (menu->yrepeattimer60 > PALDOWN(60)) {
//				menu->yrepeatmode = MENUREPEATMODE_FAST;
//			}
//
//			// Calculate the old and new repeat slots.
//			// If these are different, the repeat will be applied on this tick.
//			oldslot = menu->yrepeattimer60 / digitalrepeatinterval;
//			newslot = (menu->yrepeattimer60 + g_Vars.diffframe60) / digitalrepeatinterval;
//
//			if (menu->yrepeatmode == MENUREPEATMODE_SLOW) {
//				oldslot /= 2;
//				newslot /= 2;
//			}
//
//			inputs.updownheld = yhelddir;
//
//			// Check if the stick is being pushed up or down
//			abssticky = sticky < 0 ? -sticky : sticky;
//			absstickx = stickx < 0 ? -stickx : stickx;
//
//			if (abssticky >= ydeadzone && (abssticky > absstickx || allowdiagonal)) {
//				// Reset the repeat if it's a different direction
//				if (sticky < 0 && menu->yrepeatcount < 0) {
//					menu->yrepeatcount = 0;
//				}
//
//				if (sticky > 0 && menu->yrepeatcount > 0) {
//					menu->yrepeatcount = 0;
//				}
//
//				if (menu->yrepeatcount == 0) {
//					menu->yrepeattimer60 = 0;
//				}
//
//				// Calculate the repeat interval based on the stick pressure
//				if (abssticky > 70) {
//					abssticky = 70;
//				}
//
//				abssticky -= ydeadzone;
//				interval = stickintervalbase - ystickintervalmult * abssticky / 50;
//
//				// After 3 repeats, third the interval (ie. make faster)
//				if (menu->yrepeatcount >= 3 || menu->yrepeatcount <= -3) {
//					interval /= 3;
//				}
//
//				if (interval > 0) {
//#if PAL
//					if (interval > 3) {
//						interval = PALDOWN(interval);
//					}
//#endif
//
//					oldslot = menu->yrepeattimer60 / interval;
//					newslot = (menu->yrepeattimer60 + g_Vars.diffframe60) / interval;
//
//					yhelddir = sticky > 0 ? -1 : 1;
//
//					if (oldslot != newslot) {
//						apply = true;
//					}
//
//					if (menu->yrepeatcount == 0) {
//						apply = true;
//					}
//
//					if (apply) {
//						menu->yrepeatcount += yhelddir;
//					}
//				}
//			} else {
//				menu->yrepeatcount = 0;
//			}
//
//			if (oldslot != newslot) {
//				apply = true;
//			}
//
//			if (!apply) {
//				yhelddir = 0;
//			}
//		}
//
//		menu->xrepeattimer60 += g_Vars.diffframe60;
//		menu->yrepeattimer60 += g_Vars.diffframe60;
//
//		inputs.leftright = xhelddir;
//		inputs.updown = yhelddir;
//		inputs.xaxis = stickx;
//		inputs.yaxis = sticky;
//		inputs.unk14 = 0;
//		inputs.start = starttap ? true : false;
//
//		// Handle dialogs that allow pressing start to select,
//		// and handle pressing start on a list item.
//		if (g_Menus[g_MpPlayerNum].curdialog && starttap) {
//			struct menuitem *item;
//
//			if (g_Menus[g_MpPlayerNum].curdialog->definition->flags & MENUDIALOGFLAG_STARTSELECTS) {
//				inputs.select = true;
//				starttoselect = true;
//			}
//
//			item = g_Menus[g_MpPlayerNum].curdialog->focuseditem;
//
//			if (item && item->type == MENUITEMTYPE_LIST) {
//				inputs.select = true;
//			}
//		}
//
//		// Iterate all dialogs and give them the input for processing
//		{
//			bool foundcurrent = false;
//			s32 i;
//			s32 j;
//
//			for (i = 0; i < g_Menus[g_MpPlayerNum].depth; i++) {
//				struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[i];
//
//				for (j = 0; j < layer->numsiblings; j++) {
//					u32 tickflags = 0;
//
//					if (i == g_Menus[g_MpPlayerNum].depth - 1 && j == layer->cursibling && !foundcurrent) {
//						tickflags |= MENUTICKFLAG_DIALOGISCURRENT;
//						foundcurrent = true;
//					}
//
//					dialogTick(layer->siblings[j], &inputs, tickflags);
//				}
//			}
//		}
//
//		switch (g_MenuData.root) {
//		case MENUROOT_MPSETUP:
//		case MENUROOT_4MBMAINMENU:
//			// Allow pressing start on most MP setup dialogs to jump straight to
//			// the Ready dialog, or apply the quick start setup.
//			if (inputs.start && !starttoselect && g_Menus[g_MpPlayerNum].curdialog && !dialog->dimmed) {
//				if (g_Menus[g_MpPlayerNum].curdialog->definition);
//
//				if (g_Vars.mpsetupmenu != MPSETUPMENU_GENERAL
//						&& g_Menus[g_MpPlayerNum].curdialog->definition != &g_MpReadyMenuDialog) {
//					menuPushDialog(&g_MpReadyMenuDialog);
//				} else if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_MpQuickTeamGameSetupMenuDialog) {
//					func0f17f428();
//				}
//			}
//			break;
//		case MENUROOT_MPPAUSE:
//			if (g_InCutscene) {
//				func0f0f8120();
//			}
//			g_Menus[g_MpPlayerNum].openinhibit = 10;
//			// fall-through
//		case MENUROOT_ENDSCREEN:
//		case MENUROOT_MAINMENU:
//		case MENUROOT_MPENDSCREEN:
//		case MENUROOT_TRAINING:
//			if (inputs.start && !starttoselect && g_Menus[g_MpPlayerNum].curdialog
//					&& (dialog->definition->flags & MENUDIALOGFLAG_IGNOREBACK) == 0) {
//				func0f0f8120();
//			}
//			break;
//		}
//	}
//}

/**
 * Render layer 1 of the menu background.
 *
 * Layer 1 is drawn before the hud piece. Almost everything is in layer 1.
 *
 * frac is used when transitioning between two backgrounds.
 * A value of 1 means draw this background with full alpha.
 */
Gfx *menuRenderBackgroundLayer1(Gfx *gdl, u8 bg, f32 frac)
{
	static u32 bblur = 1;

	switch (bg) {
	case MENUBG_BLUR:
		{
			u32 alpha = 255 * frac;

			// Render the blurred background texture with full alpha
			gdl = menugfxRenderBgBlur(gdl, 0xffffff00 | alpha, 0, 0);

			// Render it twice more with half alpha and offset
			gdl = menugfxRenderBgBlur(gdl, 0xffffff00 | alpha >> 1, -30, -30);
			gdl = menugfxRenderBgBlur(gdl, 0xffffff00 | alpha >> 1, 30, 30);
		}
		break;
	case MENUBG_BLACK:
	case MENUBG_8:
		{
			u32 colour = 255 * frac;
			gSPDisplayList(gdl++, var800613a0);
			gdl = gfxSetPrimColour(gdl, colour);
			gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());
			gdl = func0f153838(gdl);
		}
		break;
	case MENUBG_SUCCESS:
		{
			// Fill with black
			gSPDisplayList(gdl++, var800613a0);
			gdl = gfxSetPrimColour(gdl, 0x000000ff);
			gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());
			gdl = func0f153838(gdl);

			// Render the success BG
			gdl = menugfxRenderBgSuccess(gdl);

			// Render alpha black if fading in
			{
				u32 alpha = (1.0f - frac) * 255;

				if (alpha) {
					gSPDisplayList(gdl++, var800613a0);
					gdl = gfxSetPrimColour(gdl, alpha);
					gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());
					gdl = func0f153838(gdl);
				}
			}
		}
		break;
	case MENUBG_FAILURE:
		{
			// Fill with white -> black while fading in
			u32 stack;
			u32 channel = (1.0f - frac) * 255;
			gSPDisplayList(gdl++, var800613a0);
			gdl = gfxSetPrimColour(gdl, channel << 24 | channel << 16 | channel << 8 | 0xff);
			gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());
			gdl = func0f153838(gdl);

			// Render the failure BG
			gdl = menugfxRenderBgFailure(gdl);
		}
		break;
	case MENUBG_TUNNELALPHA:
		mainOverrideVariable("bblur", &bblur);

		if (g_MenuData.screenshottimer) {
			return gdl;
		}

		if (bblur) {
			// Render the blurred background
			gdl = menugfxRenderBgBlur(gdl, 0xffffffff, 0, 0);

			// While fading, render red
			if (frac < 1.0f) {
				u32 alpha;
				u32 stack;

				gSPDisplayList(gdl++, var800613a0);
				alpha = (1.0f - frac) * 255;
				gdl = gfxSetPrimColour(gdl, 0xff000000 | alpha);
				gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());
				gdl = func0f153838(gdl);
			}
		}
		break;
	case MENUBG_GRADIENT:
		// Blue to red
		gdl = menugfxRenderGradient(gdl, 0, 0, viGetWidth(), viGetHeight(), 0x00007f7f, 0x000000ff, 0x8f0000ff);
		break;
	case MENUBG_TUNNELOPAQUE:
		// Yellow to yellow (ie. not a gradient)
		gdl = menugfxRenderGradient(gdl, 0, 0, viGetWidth(), viGetHeight(), 0x3f3f00ff, 0x7f0000ff, 0x3f3f00ff);
		break;
	}

	return gdl;
}

u32 var800714f0 = 1;

Gfx *menuRenderBackgroundLayer2(Gfx *gdl, u8 bg, f32 frac)
{
	if (bg == MENUBG_TUNNELALPHA || bg == MENUBG_TUNNELOPAQUE) {
		mainOverrideVariable("cone", &var800714f0);

		if (var800714f0
				&& (g_MenuData.nextbg == MENUBG_TUNNELALPHA || g_MenuData.nextbg == 0 || g_MenuData.nextbg == 255)) {
			gdl = func0f0e4190(gdl);
		}
	}

	return gdl;
}

Gfx *menuRender(Gfx *gdl)
{
	static u32 usepiece = 1;

	g_MpPlayerNum = 0;

#if PAL
	g_ScaleX = 1;
#else
	g_ScaleX = g_ViRes == VIRES_HI ? 2 : 1;
#endif

	gdl = func0f0d479c(gdl);

	gSPDisplayList(gdl++, var800613a0);

	// Render the background
	if (g_MenuData.nextbg != 255) {
		if (g_MenuData.nextbg == 0) {
			gdl = menuRenderBackgroundLayer1(gdl, g_MenuData.bg, 1.0f - g_MenuData.unk010);
		} else {
			gdl = menuRenderBackgroundLayer1(gdl, g_MenuData.bg, 1.0f);
			gdl = menuRenderBackgroundLayer1(gdl, g_MenuData.nextbg, g_MenuData.unk010);
		}
	} else {
		gdl = menuRenderBackgroundLayer1(gdl, g_MenuData.bg, 1.0f);
	}

	// Calculate hudpiece things then render it
	if (g_MenuData.unk5d5_05) {
		g_MenuData.unk01c.unk05e = 0;
		g_MenuData.unk01c.unk05c = 0x40d;
		g_MenuData.unk01c.unk580 = 0;
		g_MenuData.unk01c.unk5b1_04 = false;
		g_MenuData.unk5d4 = 1;
		g_MenuData.unk5d5_05 = false;
	}

	if (IS8MB() && g_MenuData.unk5d4) {
		bool removepiece = false;

		gSPSetGeometryMode(gdl++, G_ZBUFFER);

		// Everyone 1 in 100 frames on average, calculate a new X/Y for the hudpiece
		// Note: unintentional 64-bit float comparison done here
		if (random() * (1.0f / U32_MAX) < 0.01) {
			g_MenuData.unk01c.unk538 = random() * (1.0f / U32_MAX) * 80.0f + -205.5f - 40.0f;
			g_MenuData.unk01c.unk53c = random() * (1.0f / U32_MAX) * 80.0f + 244.7f - 40.0f;
		}

		var8009de98 = var8009de9c = 0;

		if (g_MenuData.root == MENUROOT_MPSETUP) {
			if (g_MenuData.count <= 0) {
				removepiece = true;
			}
		}

		if (g_MenuData.root != MENUROOT_MAINMENU
				&& g_MenuData.root != MENUROOT_MPSETUP
				&& g_MenuData.root != MENUROOT_FILEMGR
				&& g_MenuData.root != MENUROOT_TRAINING) {
			removepiece = true;
		}

		if (g_Menus[g_MpPlayerNum].curdialog == NULL) {
			if (g_MenuData.root != MENUROOT_MPSETUP) {
				removepiece = true;
			}
		}

		if (g_Vars.currentplayer->eyespy
				&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)
				&& g_Vars.currentplayer->eyespy->active) {
			removepiece = true;
		}

		if (removepiece) {
			if (g_MenuData.unk01c.unk580 == 0) {
				g_MenuData.unk01c.unk5b1_04 = true;
				g_MenuData.unk01c.unk05e = 0;
				g_MenuData.unk01c.unk05c = 0x40d;
				g_MenuData.unk01c.unk580 = 1;
			} else if (g_MenuData.unk01c.unk05e == 0) {
				g_MenuData.unk01c.unk580 = 0;
				g_MenuData.unk5d4 = 0;
			}
		}

		mainOverrideVariable("usePiece", &usepiece);

		if (usepiece) {
			g_MenuData.unk5d5_03 = false;

			gdl = menuRenderModels(gdl, &g_MenuData.unk01c, 1);
			gSPClearGeometryMode(gdl++, G_ZBUFFER);

			g_MenuData.unk5d5_03 = true;
		}
	} else {
		var8009de98 = var8009de9c = 0;
	}

	if (g_MenuData.unk5d5_04) {
		var8009de98 = g_MenuData.unk670;
		var8009de9c = g_MenuData.unk674;
	}

	// Render the second layer of the background (for the combat simulator
	// tunnel effect, which draws over the top of the hud piece)
	if (g_MenuData.nextbg != 255) {
		if (g_MenuData.nextbg == 0) {
			gdl = menuRenderBackgroundLayer2(gdl, g_MenuData.bg, 1.0f - g_MenuData.unk010);
		} else {
			gdl = menuRenderBackgroundLayer2(gdl, g_MenuData.bg, 1.0f);
			gdl = menuRenderBackgroundLayer2(gdl, g_MenuData.nextbg, g_MenuData.unk010);
		}
	} else {
		gdl = menuRenderBackgroundLayer2(gdl, g_MenuData.bg, 1.0f);
	}

	// Render the health bar (playerRenderHealthBar may choose not to render)
	if ((g_MenuData.bg || g_MenuData.nextbg != 255)
			&& (!g_Vars.currentplayer->eyespy || !g_Vars.currentplayer->eyespy->active)) {
		gdl = func0f0d49c8(gdl);
		gdl = playerRenderHealthBar(gdl);
		gdl = func0f0d479c(gdl);
	}

	if (g_MenuData.count > 0) {
		// Render dialogs
		gdl = func0f153ab0(gdl);

		if (g_MenuData.root == MENUROOT_MPPAUSE || g_MenuData.root == MENUROOT_MPENDSCREEN) {
			g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;
			gdl = menuRenderDialogs(gdl);
		} else {
			s32 i;

			for (i = 0; i < 4; i++) {
				g_MpPlayerNum = i;
				gdl = menuRenderDialogs(gdl);
			}
		}

		g_MpPlayerNum = 0;

		gSPMatrix(gdl++, osVirtualToPhysical(currentPlayerGetUnk1750()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gSPDisplayList(gdl++, var800613a0);

		func0f153b40();

		// Render corner texts in combat simulator
		if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
			s32 i;
			s32 j;
			s32 viewleft = viGetViewLeft() / g_ScaleX + 20;
			s32 viewtop = viGetViewTop() + 4;
			s32 viewright = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX - 20;
			s32 viewbottom = viGetViewTop() + viGetViewHeight() - 4;
			s32 textheight;
			s32 textwidth;
			bool renderit;
			char text[32];
			s32 tmp1;
			s32 tmp2;
			s32 x;
			s32 y;
			s32 colour;

			gdl = func0f153628(gdl);

			for (i = 0; i < 4; i++) {
				// Figure out what text will be displayed. The text calculated
				// here is for measuring purposes only and isn't rendered.
				// Amusingly, there's a %d placeholder in the text which isn't
				// replaced prior to measuring, so the width is slightly wrong.
				if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL && g_Vars.waitingtojoin[i]) {
					// Player has pressed start but they can't open the player-specific
					// dialog yet because they're still on the Combat Simulator dialog
					// or similar. Show "Ready" in their corner.
					renderit = true;
					// "Player %d: " and "Ready!"
					sprintf(text, "%s%s", langGet(L_MPMENU_482), langGet(L_MISC_461));
				} else {
					if (g_MenuData.root == MENUROOT_4MBMAINMENU) {
						if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL) {
							renderit = true;

							for (j = 0; j < 4; j++) {
								if (g_Vars.waitingtojoin[j]) {
									renderit = false;
								}
							}
						} else {
							renderit = g_MpNumJoined < 2;
						}
					} else {
						renderit = true;
					}

					// "Player %d: " and "Press START!"
					sprintf(text, "%s%s", langGet(L_MPMENU_482), langGet(L_MPMENU_483));
				}

				if (renderit) {
					textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

					// Check which controllers are connected
					// and update the alpha of the label
					if (((g_MpSetup.chrslots | ~joyGetConnectedControllers()) & (1 << i)) == 0) {
#if VERSION >= VERSION_PAL_FINAL
						tmp1 = g_Vars.diffframe60freal * 3;
#else
						tmp1 = g_Vars.diffframe60 * 3;
#endif

						if (g_MenuData.playerjoinalpha[i] < 255) {
							if (255 - g_MenuData.playerjoinalpha[i] > tmp1) {
								g_MenuData.playerjoinalpha[i] += tmp1;
							} else {
								g_MenuData.playerjoinalpha[i] = 255;
							}
						}
					} else {
#if VERSION >= VERSION_PAL_FINAL
						tmp2 = g_Vars.diffframe60freal * 9;
#else
						tmp2 = g_Vars.diffframe60 * 9;
#endif

						if (g_MenuData.playerjoinalpha[i] > 0) {
							if (g_MenuData.playerjoinalpha[i] > tmp2) {
								g_MenuData.playerjoinalpha[i] -= tmp2;
							} else {
								g_MenuData.playerjoinalpha[i] = 0;
							}
						}
					}

					if (g_MenuData.playerjoinalpha[i] > 0) {
						u32 weight = func0f006b08(20) * 255.0f;

						// "Player %d: "
						sprintf(text, langGet(L_MPMENU_482), i + 1);

						if (i < 2) {
							y = viewtop + 2;
						} else {
							y = viewbottom - 9;
						}

						if (i == 1 || i == 3) {
							x = viewright - textwidth - 2;
						} else {
							x = viewleft + 2;
						}

						gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, g_MenuData.playerjoinalpha[i] | 0x5070ff00, viGetWidth(), viGetHeight(), 0, 0);

						if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL && g_Vars.waitingtojoin[i]) {
							// "Ready!"
							strcpy(text, langGet(L_MISC_461));
							colour = g_MenuData.playerjoinalpha[i] | 0xd00020ff;
						} else {
							// "Press START!"
							strcpy(text, langGet(L_MPMENU_483));
							colour = colourBlend(0x00ffff00, 0xffffff00, weight) | g_MenuData.playerjoinalpha[i];
						}

						gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, viGetWidth(), viGetHeight(), 0, 0);
					}
				}
			}

			gdl = func0f153780(gdl);
		}

		gSPSetGeometryMode(gdl++, G_ZBUFFER);
	}

	// Render banner messages, such as "Please Wait...",
	// "Checking Controller Pak" and some unused game boy camera texts.
	if (g_MenuData.bannernum != -1) {
		s32 x1 = viGetViewLeft() / g_ScaleX;
		s32 y1 = viGetViewTop();
		s32 x2 = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX;
		s32 y2 = viGetViewTop() + viGetViewHeight();

#if VERSION >= VERSION_NTSC_1_0
		s32 left = 0;
		s32 right = 0;

		if (PLAYERCOUNT() >= 3) {
			if (g_Vars.currentplayernum == 1 || g_Vars.currentplayernum == 3) {
				right = 15;
			} else {
				left = 15;
			}
		}

		if (PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB())) {
			if (g_Vars.currentplayernum == 1) {
				right = 15;
			} else {
				left = 15;
			}
		}

		gdl = menuRenderBanner(gdl, x1, y1, x2, y2, PLAYERCOUNT() < 2, g_MenuData.bannernum, left, right);
#else
		if (PLAYERCOUNT() >= 3) {
			if (g_Vars.currentplayernum == 1 || g_Vars.currentplayernum == 3) {
				x2 -= 10;
			} else {
				x1 += 10;
			}
		}

		if (PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB())) {
			if (g_Vars.currentplayernum == 1) {
				x2 -= 10;
			} else {
				x1 += 10;
			}
		}

		gdl = menuRenderBanner(gdl, x1, y1, x2, y2, PLAYERCOUNT() < 2, g_MenuData.bannernum);
#endif
	}

	gdl = func0f0d49c8(gdl);

	g_ScaleX = 1;

	return gdl;
}

const char var7f1b27a4[] = "Tune Selector - mode %d\n";

u32 menuChooseMusic(void)
{
	s32 missionsuccess = MUSIC_MISSION_SUCCESS;

	if (g_StageIndex == STAGEINDEX_DEFENSE) {
		missionsuccess = MUSIC_MISSION_UNKNOWN;
	}

	if (g_MenuData.root == MENUROOT_ENDSCREEN) {
		if (g_Vars.bond->isdead || g_Vars.bond->aborted || !objectiveIsAllComplete()) {
			return MUSIC_MISSION_FAILED;
		}

		return missionsuccess;
	}

	if (g_MenuData.root == MENUROOT_MPENDSCREEN) {
		if (g_Vars.coopplayernum >= 0) {
			if ((g_Vars.bond->isdead && g_Vars.coop->isdead)
					|| g_Vars.bond->aborted
					|| g_Vars.coop->aborted
					|| !objectiveIsAllComplete()) {
				return MUSIC_MISSION_FAILED;
			}

			return missionsuccess;
		}

		if (g_Vars.antiplayernum >= 0) {
			if (g_Vars.bond->isdead || g_Vars.bond->aborted || !objectiveIsAllComplete()) {
				return MUSIC_MISSION_FAILED;
			}

			return missionsuccess;
		}
	}

	if (g_MenuData.root == MENUROOT_FILEMGR) {
		return MUSIC_MAINMENU;
	}

	if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
		return MUSIC_COMBATSIM_MENU;
	}

	if (g_MenuData.root == MENUROOT_MPPAUSE) {
		return MUSIC_COMBATSIM_COMPLETE;
	}

	if (g_MenuData.root == MENUROOT_BOOTPAKMGR) {
		return MUSIC_MISSION_UNKNOWN;
	}

	if (g_Vars.mplayerisrunning) {
		return MUSIC_COMBATSIM_COMPLETE;
	}

	if (g_Vars.stagenum == STAGE_CITRAINING || g_Vars.stagenum == STAGE_4MBMENU) {
		return MUSIC_MAINMENU;
	}

	return MUSIC_PAUSEMENU;
}

bool func0f0fcbcc(void)
{
	if (g_FileState == FILESTATE_UNSELECTED && g_Vars.stagenum == STAGE_CITRAINING) {
		return true;
	}

	return false;
}

bool func0f0fcc04(void)
{
	return false;
}

u32 menuGetRoot(void)
{
	if (g_MenuData.count == 0) {
		return 0;
	}

	return g_MenuData.root;
}

#if VERSION >= VERSION_NTSC_1_0
struct menudialogdef g_PakAttemptRepairMenuDialog;

s32 menuhandler000fcc34(s32 operation, struct menuitem *item, union handlerdata *data)
{
	bool done = false;

	if (operation == MENUOP_SET) {
		while (!done) {
			done = true;

			if (g_Menus[g_MpPlayerNum].curdialog) {
				if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakRepairSuccessMenuDialog
						|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakRemovedMenuDialog
						|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakRepairFailedMenuDialog
						|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakAttemptRepairMenuDialog
						|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakDamagedMenuDialog
						|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakFullMenuDialog) {
					done = false;
					menuPopDialog();
				}
			}
		}
	}

	return 0;
}
#endif

s32 menudialog000fcd48(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curdialog
				&& g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef
				&& joy000155b4(g_Menus[g_MpPlayerNum].fm.device3) == 0) {
			func0f0f3704(&g_PakRemovedMenuDialog);
		}
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
s32 func0f0fcdd0(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f0f3704(&g_PakDamagedMenuDialog);
	}

	return 0;
}
#endif

s32 menuhandlerRepairPak(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (pakRepair(g_Menus[g_MpPlayerNum].fm.device3)) {
			func0f0f3704(&g_PakRepairSuccessMenuDialog);
		} else {
			func0f0f3704(&g_PakRepairFailedMenuDialog);
		}
	}

	return 0;
}

void func0f0fce8c(struct menudialogdef *dialogdef, s32 playernum, s32 arg2)
{
	s32 prevplayernum = g_MpPlayerNum;

	g_MpPlayerNum = playernum;
	g_Menus[g_MpPlayerNum].fm.device3 = arg2;

	if (g_Menus[g_MpPlayerNum].curdialog == NULL) {
		if (PLAYERCOUNT() == 1) {
			menuPushRootDialog(dialogdef, MENUROOT_MAINMENU);
			lvSetPaused(true);
			g_Vars.currentplayer->pausemode = PAUSEMODE_PAUSED;
		} else {
			menuPushRootDialog(dialogdef, MENUROOT_MPPAUSE);
		}
	} else {
		menuPushDialog(dialogdef);
	}

	g_MpPlayerNum = prevplayernum;
}

struct menuitem g_PakRemovedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_174, 0x00000000, NULL }, // "The Controller Pak has been removed."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS_073, 0x00000000, menuhandler000fcc34 }, // "OK"
#else
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS_073, 0x00000000, NULL }, // "OK"
#endif
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_PakRemovedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_173, // "Error"
	g_PakRemovedMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_PakRepairSuccessMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_181, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
#if VERSION >= VERSION_NTSC_1_0
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS_073, 0x00000000, menuhandler000fcc34 },
#else
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS_073, 0x00000000, NULL },
#endif
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_PakRepairSuccessMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPWEAPONS_180, // "Repair Successful"
	g_PakRepairSuccessMenuItems,
	menudialog000fcd48,
	0,
	NULL,
};

struct menuitem g_PakRepairFailedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_183, 0x00000000, NULL }, // "The Controller Pak cannot be repaired. You will not be able to load from or save to this Controller Pak."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS_073, 0x00000000, NULL }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_PakRepairFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_182, // "Repair Failed"
	g_PakRepairFailedMenuItems,
	menudialog000fcd48,
	0,
	NULL,
};

struct menuitem g_PakAttemptRepairMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_176, 0x00000000, NULL }, // "Are you sure you want to attempt repair of this Controller Pak?"
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_177, 0x00000000, NULL }, // "Data may be lost!"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS_178, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS_179, 0x00000000, menuhandlerRepairPak }, // "Repair"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_PakAttemptRepairMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_175, // "Attempt Repair"
	g_PakAttemptRepairMenuItems,
	menudialog000fcd48,
	0,
	NULL,
};

char *menuTextSaveDeviceName(struct menuitem *item)
{
	u16 devices[] = {
		L_OPTIONS_112, // "Controller Pak 1"
		L_OPTIONS_113, // "Controller Pak 2"
		L_OPTIONS_114, // "Controller Pak 3"
		L_OPTIONS_115, // "Controller Pak 4"
#if VERSION >= VERSION_NTSC_1_0
		L_OPTIONS_111, // "Game Pak"
#endif
	};

	if ((u8)g_Menus[g_MpPlayerNum].fm.device3 < ARRAYCOUNT(devices)) {
		return langGet(devices[(u8)g_Menus[g_MpPlayerNum].fm.device3]);
	}

	return NULL;
}

s32 menuhandlerRetrySavePak(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();

#if VERSION >= VERSION_NTSC_1_0
		g_Vars.unk0004e4 &= 0xfff0;
		g_Vars.unk0004e4 |= 8;
		g_Vars.unk0004e4 |= 1 << ((u8)g_Menus[g_MpPlayerNum].fm.device3 + 8);
#else
		pak0f1169c8(g_Menus[g_MpPlayerNum].fm.device3, 0);
#endif
	}

	return 0;
}

s32 menuhandlerWarnRepairPak(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
#if VERSION >= VERSION_NTSC_1_0
		menuPushDialog(&g_PakAttemptRepairMenuDialog);
#else
		func0f0f3704(&g_PakAttemptRepairMenuDialog);
#endif
	}

	return 0;
}

u32 func0f0fd118(u32 playernum)
{
	u32 result = 0;

	if (g_Vars.normmplayerisrunning) {
		if (g_MpSetup.chrslots & (1 << playernum)) {
			result = playernum;
		}
	} else {
		if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
				&& PLAYERCOUNT() >= 2
				&& playernum == 1) {
			result = 1;
		}
	}

	return result;
}

bool func0f0fd1f4(s32 arg0, s32 arg1)
{
	s32 playernum = func0f0fd118(arg0);
	bool result = true;

	if (g_Vars.lvframenum < 20) {
		result = false;
	}

	if (g_FileState == FILESTATE_UNSELECTED) {
		result = false;
	}

	if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		result = true;
	}

	if (g_Menus[playernum].curdialog) {
		if (g_Menus[playernum].curdialog->definition == &g_PakDamagedMenuDialog
#if VERSION >= VERSION_NTSC_1_0
				|| g_Menus[playernum].curdialog->definition == &g_PakCannotReadGameBoyMenuDialog
				|| g_Menus[playernum].curdialog->definition == &g_PakDataLostMenuDialog
#endif
				|| g_Menus[playernum].curdialog->definition == &g_PakFullMenuDialog
				|| g_Menus[playernum].curdialog->definition == &g_PakAttemptRepairMenuDialog
				|| g_Menus[playernum].curdialog->definition == &g_PakRemovedMenuDialog
				|| g_Menus[playernum].curdialog->definition == &g_PakRepairSuccessMenuDialog
				|| g_Menus[playernum].curdialog->definition == &g_PakRepairFailedMenuDialog
				) {
			result = false;
		}
	} else if (g_MenuData.nextbg != 255 || g_MenuData.bg || g_MenuData.unk5d4) {
		result = false;
	}

	return result;
}

void func0f0fd320(s32 arg0, s32 arg1)
{
	s32 prevplayernum = g_MpPlayerNum;
	s32 playernum = func0f0fd118(arg0);
	bool found;
	s32 i;

	g_MpPlayerNum = playernum;

	switch (arg1) {
	case 1:
	case 2:
		func0f0fce8c(&g_PakDamagedMenuDialog, playernum, arg0);
		break;
	case 0:
		found = false;

		for (i = 0; i < g_Menus[g_MpPlayerNum].depth; i++) {
			if (g_Menus[g_MpPlayerNum].layers[i].siblings[0]
					&& g_Menus[g_MpPlayerNum].layers[i].siblings[0]->definition == &g_PakChoosePakMenuDialog) {
				found = true;
			}
		}

		if (!found) {
			func0f0fce8c(&g_PakFullMenuDialog, playernum, arg0);
		}
		break;
#if VERSION >= VERSION_NTSC_1_0
	case 3:
		func0f0fce8c(&g_PakCannotReadGameBoyMenuDialog, playernum, arg0);
		break;
	case 4:
		func0f0fce8c(&g_PakDataLostMenuDialog, playernum, arg0);
		break;
#endif
	}

	g_MpPlayerNum = prevplayernum;
}

void func0f0fd494(struct coord *pos)
{
	f32 xy[2];
	struct coord coord;
	Mtxf *matrix;

	g_MenuData.unk5d5_04 = true;

	matrix = currentPlayerGetMatrix1740();

	mtx4TransformVec(matrix, pos, &coord);
	func0f0b4d04(&coord, xy);

	g_MenuData.unk670 = (s32)xy[0] - viGetWidth() / 2;
	g_MenuData.unk674 = (s32)xy[1] - viGetHeight() / 2;

	g_MenuData.unk5d5_05 = false;
}

void func0f0fd548(s32 arg0)
{
	g_MenuData.unk669[g_MenuData.unk66e++] = arg0;
	g_MenuData.unk66f = 0;
}

struct menudialog *menuIsDialogOpen(struct menudialogdef *dialogdef)
{
	s32 i;
	s32 j;

	if (g_Menus[g_MpPlayerNum].curdialog) {
		for (i = 0; i < g_Menus[g_MpPlayerNum].depth; i++) {
			for (j = 0; j < g_Menus[g_MpPlayerNum].layers[i].numsiblings; j++) {
				if (g_Menus[g_MpPlayerNum].layers[i].siblings[j]
						&& g_Menus[g_MpPlayerNum].layers[i].siblings[j]->definition == dialogdef) {
					return g_Menus[g_MpPlayerNum].layers[i].siblings[j];
				}
			}
		}
	}

	return false;
}

struct menuitem g_PakDamagedMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&menuTextSaveDeviceName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS_065, 0x00000000, NULL }, // "is damaged or"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS_066, 0x00000000, NULL }, // "inserted incorrectly"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS_067, 0x00000000, menuhandlerWarnRepairPak }, // "Attempt Repair"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS_068, 0x00000000, menuhandlerRetrySavePak }, // "Retry"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPWEAPONS_069, 0x00000000, NULL }, // "Continue without using the Controller Pak"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_PakDamagedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_064, // "Damaged Controller Pak"
	g_PakDamagedMenuItems,
	menudialog000fcd48,
#if VERSION >= VERSION_NTSC_1_0
	0x00000020,
#else
	0,
#endif
	NULL,
};

struct menuitem g_PakFullMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&menuTextSaveDeviceName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x02000210, L_MPWEAPONS_071, 0x00000000, NULL }, // "is too full to save note - 1 note and 28 pages required to save"
	{ MENUITEMTYPE_LABEL,       0, 0x02000220, L_OPTIONS_003, 0x00000000, NULL }, // ""
	{ MENUITEMTYPE_LABEL,       0, 0x02000210, L_MPWEAPONS_072, 0x00000000, NULL }, // "Enter the Controller Pak Menu to free some space (hold START while powering up.)"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS_073, 0x00000000, NULL }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_PakFullMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_070, // "Full Controller Pak"
	g_PakFullMenuItems,
	menudialog000fcd48,
#if VERSION >= VERSION_NTSC_1_0
	0x00000020,
#else
	0,
#endif
	NULL,
};

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_PakCannotReadGameBoyMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS_254, 0x00000000, NULL }, // "Cannot read Game Boy Game Pak. Check connections and make sure correct Game Boy Game Pak is being used."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPWEAPONS_255, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_PakCannotReadGameBoyMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_253, // "Error"
	g_PakCannotReadGameBoyMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK,
	NULL,
};

struct menuitem g_PakDataLostMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&menuTextSaveDeviceName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS_257, 0x00000000, NULL }, // "The saved data has"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS_258, 0x00000000, NULL }, // "been erased due to"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS_259, 0x00000000, NULL }, // "corruption or damage."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPWEAPONS_260, 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_PakDataLostMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_256, // "Error"
	g_PakDataLostMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK,
	NULL,
};
#endif
