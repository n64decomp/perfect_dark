#include <ultra64.h>
#include "constants.h"
#include "game/title.h"
#include "game/game_01afc0.h"
#include "game/bondgun.h"
#include "game/game_0b28d0.h"
#include "game/game_0b3350.h"
#include "game/inventory/inventory.h"
#include "game/playermgr.h"
#include "game/gfxmemory.h"
#include "game/credits.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/training/training.h"
#include "game/game_1a7560.h"
#include "game/lang.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/joy.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/mtx.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

u8 *var8009cca0;
u32 var8009cca4;
struct gfxvtx *var8009cca8[2];
u32 *var8009ccb0[2];
u32 var8009ccb8;

s16 g_TitleViewHeight = 480;
bool g_IsTitleDemo = false;
bool g_TitleButtonPressed = false;
bool g_TitleFastForward = false;
u32 g_TitleIdleTime60 = 0;
s32 g_TitleMode = -1;
s32 g_TitleNextMode = -1;
u32 g_TitleDelayedTimer = 2;
s32 g_TitleDelayedMode = -1;
s32 g_TitleTimer = 0;
u32 var800624c8 = 0x00000000;
u32 var800624cc = 0x00000000;
u32 var800624d0 = 0x00000000;
u32 var800624d4 = 0x00000000;
u32 var800624d8 = 0x00000000;
u32 var800624dc = 0x00000000;
u32 var800624e0 = 0x00000000;
s32 g_TitleNextStage = -1; // appears to be used for more than just title
s32 var800624e8 = 1;
u32 var800624ec = 0x00000001;
u32 var800624f0 = 0x00000000;
s32 var800624f4 = 1;
struct model *g_TitleModel = NULL;
struct model *g_TitleModelNLogo2 = NULL;
u32 var80062500 = 0x00000000;
u32 var80062504 = 0x00000000;
struct model *g_TitleModelPdTwo = NULL;
struct model *g_TitleModelPdThree = NULL;
u32 var80062510 = 0x00000000;
u32 var80062514 = 0x00000000;
u32 var80062518 = 0x96969600;
u32 var8006251c = 0x96969600;
u32 var80062520 = 0xffffff00;
u32 var80062524 = 0xffffff00;
u32 var80062528 = 0x4d4d2e00;
u32 var8006252c = 0x00000000;

Lights1 var80062530 = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
Lights1 var80062548 = gdSPDefLights1(0x3f, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
Lights1 var80062560 = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
Lights1 var80062578 = gdSPDefLights1(0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f);
Lights1 var80062590 = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

u32 var800625a8 = 0x00000000;
u32 var800625ac = 0x00000000;
u32 var800625b0 = 0xffffff00;
u32 var800625b4 = 0xffffff00;
u32 var800625b8 = 0x00007f00;
u32 var800625bc = 0x00000000;
u32 var800625c0 = 0x00000000;
u32 var800625c4 = 0x00000000;
u32 var800625c8 = 0xffffff00;
u32 var800625cc = 0xffffff00;
u32 var800625d0 = 0x00007f00;
u32 var800625d4 = 0x00000000;
u32 var800625d8 = 0x00000000;
u32 var800625dc = 0x00000000;
u32 var800625e0 = 0xffffff00;
u32 var800625e4 = 0xffffff00;
u32 var800625e8 = 0x00007f00;
u32 var800625ec = 0x00000000;

char *mpPlayerGetWeaponOfChoiceName(u32 playernum, u32 slot)
{
	char *name;
	s32 weapon1;
	s32 weapon2;
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 weapon;

	setCurrentPlayerNum(playernum);

	invGetWeaponOfChoice(&weapon1, &weapon2);

	weapon = slot == 1 ? weapon2 : weapon1;

	name = bgunGetName(weapon);
	setCurrentPlayerNum(prevplayernum);

	return name;
}

GLOBAL_ASM(
glabel func0f01616c
/*  f01616c:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f016170:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f016174:	01c02825 */ 	or	$a1,$t6,$zero
/*  f016178:	44852000 */ 	mtc1	$a1,$f4
/*  f01617c:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f016180:	30cf00ff */ 	andi	$t7,$a2,0xff
/*  f016184:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f016188:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f01618c:	03003825 */ 	or	$a3,$t8,$zero
/*  f016190:	01e03025 */ 	or	$a2,$t7,$zero
/*  f016194:	c7ac0010 */ 	lwc1	$f12,0x10($sp)
/*  f016198:	05c10005 */ 	bgez	$t6,.L0f0161b0
/*  f01619c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0161a0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0161a4:	44814000 */ 	mtc1	$at,$f8
/*  f0161a8:	00000000 */ 	nop
/*  f0161ac:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0161b0:
/*  f0161b0:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f0161b4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0161b8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0161bc:	4459f800 */ 	cfc1	$t9,$31
/*  f0161c0:	44c2f800 */ 	ctc1	$v0,$31
/*  f0161c4:	00000000 */ 	nop
/*  f0161c8:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0161cc:	4442f800 */ 	cfc1	$v0,$31
/*  f0161d0:	00000000 */ 	nop
/*  f0161d4:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0161d8:	50400013 */ 	beqzl	$v0,.L0f016228
/*  f0161dc:	44028000 */ 	mfc1	$v0,$f16
/*  f0161e0:	44818000 */ 	mtc1	$at,$f16
/*  f0161e4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0161e8:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0161ec:	44c2f800 */ 	ctc1	$v0,$31
/*  f0161f0:	00000000 */ 	nop
/*  f0161f4:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0161f8:	4442f800 */ 	cfc1	$v0,$31
/*  f0161fc:	00000000 */ 	nop
/*  f016200:	30420078 */ 	andi	$v0,$v0,0x78
/*  f016204:	14400005 */ 	bnez	$v0,.L0f01621c
/*  f016208:	00000000 */ 	nop
/*  f01620c:	44028000 */ 	mfc1	$v0,$f16
/*  f016210:	3c018000 */ 	lui	$at,0x8000
/*  f016214:	10000007 */ 	b	.L0f016234
/*  f016218:	00411025 */ 	or	$v0,$v0,$at
.L0f01621c:
/*  f01621c:	10000005 */ 	b	.L0f016234
/*  f016220:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f016224:	44028000 */ 	mfc1	$v0,$f16
.L0f016228:
/*  f016228:	00000000 */ 	nop
/*  f01622c:	0440fffb */ 	bltz	$v0,.L0f01621c
/*  f016230:	00000000 */ 	nop
.L0f016234:
/*  f016234:	44d9f800 */ 	ctc1	$t9,$31
/*  f016238:	44869000 */ 	mtc1	$a2,$f18
/*  f01623c:	a0820000 */ 	sb	$v0,0x0($a0)
/*  f016240:	04c10005 */ 	bgez	$a2,.L0f016258
/*  f016244:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f016248:	3c014f80 */ 	lui	$at,0x4f80
/*  f01624c:	44814000 */ 	mtc1	$at,$f8
/*  f016250:	00000000 */ 	nop
/*  f016254:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f016258:
/*  f016258:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f01625c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f016260:	3c014f00 */ 	lui	$at,0x4f00
/*  f016264:	4449f800 */ 	cfc1	$t1,$31
/*  f016268:	44c3f800 */ 	ctc1	$v1,$31
/*  f01626c:	00000000 */ 	nop
/*  f016270:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f016274:	4443f800 */ 	cfc1	$v1,$31
/*  f016278:	00000000 */ 	nop
/*  f01627c:	30630078 */ 	andi	$v1,$v1,0x78
/*  f016280:	50600013 */ 	beqzl	$v1,.L0f0162d0
/*  f016284:	44035000 */ 	mfc1	$v1,$f10
/*  f016288:	44815000 */ 	mtc1	$at,$f10
/*  f01628c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f016290:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f016294:	44c3f800 */ 	ctc1	$v1,$31
/*  f016298:	00000000 */ 	nop
/*  f01629c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0162a0:	4443f800 */ 	cfc1	$v1,$31
/*  f0162a4:	00000000 */ 	nop
/*  f0162a8:	30630078 */ 	andi	$v1,$v1,0x78
/*  f0162ac:	14600005 */ 	bnez	$v1,.L0f0162c4
/*  f0162b0:	00000000 */ 	nop
/*  f0162b4:	44035000 */ 	mfc1	$v1,$f10
/*  f0162b8:	3c018000 */ 	lui	$at,0x8000
/*  f0162bc:	10000007 */ 	b	.L0f0162dc
/*  f0162c0:	00611825 */ 	or	$v1,$v1,$at
.L0f0162c4:
/*  f0162c4:	10000005 */ 	b	.L0f0162dc
/*  f0162c8:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0162cc:	44035000 */ 	mfc1	$v1,$f10
.L0f0162d0:
/*  f0162d0:	00000000 */ 	nop
/*  f0162d4:	0460fffb */ 	bltz	$v1,.L0f0162c4
/*  f0162d8:	00000000 */ 	nop
.L0f0162dc:
/*  f0162dc:	44c9f800 */ 	ctc1	$t1,$31
/*  f0162e0:	44878000 */ 	mtc1	$a3,$f16
/*  f0162e4:	a0830001 */ 	sb	$v1,0x1($a0)
/*  f0162e8:	04e10005 */ 	bgez	$a3,.L0f016300
/*  f0162ec:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0162f0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0162f4:	44814000 */ 	mtc1	$at,$f8
/*  f0162f8:	00000000 */ 	nop
/*  f0162fc:	46089480 */ 	add.s	$f18,$f18,$f8
.L0f016300:
/*  f016300:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f016304:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f016308:	3c014f00 */ 	lui	$at,0x4f00
/*  f01630c:	444af800 */ 	cfc1	$t2,$31
/*  f016310:	44c8f800 */ 	ctc1	$t0,$31
/*  f016314:	00000000 */ 	nop
/*  f016318:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f01631c:	4448f800 */ 	cfc1	$t0,$31
/*  f016320:	00000000 */ 	nop
/*  f016324:	31080078 */ 	andi	$t0,$t0,0x78
/*  f016328:	51000013 */ 	beqzl	$t0,.L0f016378
/*  f01632c:	44083000 */ 	mfc1	$t0,$f6
/*  f016330:	44813000 */ 	mtc1	$at,$f6
/*  f016334:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f016338:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f01633c:	44c8f800 */ 	ctc1	$t0,$31
/*  f016340:	00000000 */ 	nop
/*  f016344:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f016348:	4448f800 */ 	cfc1	$t0,$31
/*  f01634c:	00000000 */ 	nop
/*  f016350:	31080078 */ 	andi	$t0,$t0,0x78
/*  f016354:	15000005 */ 	bnez	$t0,.L0f01636c
/*  f016358:	00000000 */ 	nop
/*  f01635c:	44083000 */ 	mfc1	$t0,$f6
/*  f016360:	3c018000 */ 	lui	$at,0x8000
/*  f016364:	10000007 */ 	b	.L0f016384
/*  f016368:	01014025 */ 	or	$t0,$t0,$at
.L0f01636c:
/*  f01636c:	10000005 */ 	b	.L0f016384
/*  f016370:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f016374:	44083000 */ 	mfc1	$t0,$f6
.L0f016378:
/*  f016378:	00000000 */ 	nop
/*  f01637c:	0500fffb */ 	bltz	$t0,.L0f01636c
/*  f016380:	00000000 */ 	nop
.L0f016384:
/*  f016384:	a0880002 */ 	sb	$t0,0x2($a0)
/*  f016388:	a0820004 */ 	sb	$v0,0x4($a0)
/*  f01638c:	a0830005 */ 	sb	$v1,0x5($a0)
/*  f016390:	a0880006 */ 	sb	$t0,0x6($a0)
/*  f016394:	a0850008 */ 	sb	$a1,0x8($a0)
/*  f016398:	8fa20014 */ 	lw	$v0,0x14($sp)
/*  f01639c:	3c0142fe */ 	lui	$at,0x42fe
/*  f0163a0:	a0860009 */ 	sb	$a2,0x9($a0)
/*  f0163a4:	a087000a */ 	sb	$a3,0xa($a0)
/*  f0163a8:	a085000c */ 	sb	$a1,0xc($a0)
/*  f0163ac:	a086000d */ 	sb	$a2,0xd($a0)
/*  f0163b0:	a087000e */ 	sb	$a3,0xe($a0)
/*  f0163b4:	44caf800 */ 	ctc1	$t2,$31
/*  f0163b8:	44810000 */ 	mtc1	$at,$f0
/*  f0163bc:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f0163c0:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0163c4:	4600820d */ 	trunc.w.s	$f8,$f16
/*  f0163c8:	440c4000 */ 	mfc1	$t4,$f8
/*  f0163cc:	00000000 */ 	nop
/*  f0163d0:	a08c0010 */ 	sb	$t4,0x10($a0)
/*  f0163d4:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f0163d8:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0163dc:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0163e0:	440e3000 */ 	mfc1	$t6,$f6
/*  f0163e4:	00000000 */ 	nop
/*  f0163e8:	a08e0011 */ 	sb	$t6,0x11($a0)
/*  f0163ec:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0163f0:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0163f4:	4600820d */ 	trunc.w.s	$f8,$f16
/*  f0163f8:	44184000 */ 	mfc1	$t8,$f8
/*  f0163fc:	03e00008 */ 	jr	$ra
/*  f016400:	a0980012 */ 	sb	$t8,0x12($a0)
);

void titleInitLegal(void)
{
	musicQueueStopAllEvent();
	var800624f4 = 1;
	g_TitleTimer = 0;
	g_TitleButtonPressed = false;
	g_TitleFastForward = false;
}

void titleExitLegal(void)
{
	// empty
}

void titleTickLegal(void)
{
	viSetFovY(60);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	viSetUseZBuf(false);

	g_TitleTimer += g_Vars.lvupdate240_60;

	if (g_TitleTimer > TICKS(180)) {
		titleSetNextMode(TITLEMODE_CHECKCONTROLLERS);
	}
}

void titleInitCheckControllers(void)
{
	g_TitleTimer = 0;
	viBlack(true);
}

void titleExitCheckControllers(void)
{
	var800624e8 = 0;
	viConfigureForLogos();
	viSetMode(VIMODE_HI);
	viBlack(false);
}

void titleTickCheckControllers(void)
{
	g_TitleTimer++;
	viSetZRange(100, 10000);
	viSetUseZBuf(false);

	if (g_TitleTimer > 6) {
		if ((joyGetConnectedControllers() & 1) == 0) {
			titleSetNextMode(TITLEMODE_NOCONTROLLER);
		} else {
			titleSetNextMode(TITLEMODE_RARELOGO);
		}
	}
}

Gfx *titleRenderCheckControllers(Gfx *gdl)
{
	if (g_TitleTimer > 2 && g_TitleTimer < 6) {
		gdl = func0f01afc0(gdl);
	}

	return gdl;
}

Gfx *title0f0165f0(Gfx *gdl, s32 xcentre, s32 ycentre, s32 xscale, s32 yscale, char *text, struct fontchar *font1, struct font *font2, s32 colour)
{
	s32 textheight;
	s32 textwidth;
	s32 x;
	s32 y;

	textwidth = 0;
	textheight = 0;

	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = xcentre - xscale * textwidth / 2;
	y = ycentre - yscale * textheight / 2;

	gdl = textRenderProjected(gdl, &x, &y, text, font1, font2, colour, viGetWidth(), viGetHeight(), 0, 0);

	return gdl;
}

bool g_LegalEnabled;

#define LEGALELEMENTTYPE_BLUETEXTSM  0
#define LEGALELEMENTTYPE_BLUETEXTMD  1
#define LEGALELEMENTTYPE_BLUETEXTLG  2
#define LEGALELEMENTTYPE_LINE        3
#define LEGALELEMENTTYPE_DOLBYLOGO   4
#define LEGALELEMENTTYPE_WHITETEXTLG 5
#define LEGALELEMENTTYPE_WHITETEXTSM 6
#define LEGALELEMENTTYPE_RARELOGO    7

struct legalelement {
	s16 x;
	s16 y;
	s16 unused04;
	s16 unused06;
	s16 type;
	u16 textid;
};

struct legalelement g_LegalElements[] = {
	{ 49,  179, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_077 }, // "Nintendo 64 Product Identification"
	{ 49,  200, 1, 1, LEGALELEMENTTYPE_LINE,        0             },
	{ 69,  207, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_078 }, // "Product ID:"
	{ 69,  227, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_079 }, // "Product Code:"
	{ 69,  247, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_080 }, // "Variant:"
	{ 69,  267, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_081 }, // "Developer:"
	{ 249, 207, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_082 }, // "Perfect Dark"
	{ 249, 227, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_083 }, // "NUS-NPDE-USA"
	{ 249, 247, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_084 }, // "NTSC version 8.7 final"
	{ 249, 267, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_085 }, // "Rare Ltd. (twycross)"
	{ 69,  290, 1, 1, LEGALELEMENTTYPE_LINE,        0             },
	{ 69,  299, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_076 }, // "N64 EXPANSION PAK"
#if VERSION >= VERSION_PAL_FINAL
	{ -1,  296, 0, 1, LEGALELEMENTTYPE_WHITETEXTSM, L_OPTIONS_075 }, // "tm"
	{ -1,  299, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_074 }, // "NOT DETECTED"
#else
	{ 266, 296, 0, 1, LEGALELEMENTTYPE_WHITETEXTSM, L_OPTIONS_075 }, // "tm"
	{ 286, 299, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_074 }, // "NOT DETECTED"
#endif
	{ 69,  320, 1, 1, LEGALELEMENTTYPE_LINE,        0             },
	{ 69,  328, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_087 }, // "The Rarewere Logo and Perfect Dark are ..."
	{ 138, 343, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_088 }, // "Presented in Dolby Surround. Dolby and ..."
	{ 69,  372, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_089 }, // "Uses Miles Sound System ..."
	{ 69,  428, 1, 1, LEGALELEMENTTYPE_LINE,        0             },
	{ 69,  433, 0, 1, LEGALELEMENTTYPE_BLUETEXTSM,  L_OPTIONS_093 }, // "rare designs on the future <<<"
	{ 69,  344, 0, 1, LEGALELEMENTTYPE_DOLBYLOGO,   0             },
};

Gfx *titleRenderLegal(Gfx *gdl)
{
#if VERSION >= VERSION_PAL_FINAL
	s32 prevx = 0;
#endif
	struct legalelement *elem;
	struct legalelement *end;
	struct modelrenderdata renderdata = { NULL, true, 3 };
	s32 x;
	s32 y;
	struct fontchar *font1;
	struct font *font2;

	if (g_LegalEnabled) {
		gdl = func0f01afc0(gdl);
		gdl = func0f153628(gdl);

		elem = g_LegalElements;
		end = &g_LegalElements[ARRAYCOUNT(g_LegalElements)];

		for (; elem < end; elem++) {
			u32 colour = 0x7f7fffff;

			switch (elem->type) {
			case LEGALELEMENTTYPE_BLUETEXTSM:
				font1 = g_CharsHandelGothicSm;
				font2 = g_FontHandelGothicSm;
				break;
			case LEGALELEMENTTYPE_BLUETEXTMD:
				font1 = g_CharsHandelGothicMd;
				font2 = g_FontHandelGothicMd;
				break;
			case LEGALELEMENTTYPE_BLUETEXTLG:
				font1 = g_CharsHandelGothicLg;
				font2 = g_FontHandelGothicLg;
				break;
			case LEGALELEMENTTYPE_WHITETEXTLG:
				font1 = g_CharsHandelGothicLg;
				font2 = g_FontHandelGothicLg;
				colour = 0xffffffff;

				if (elem->textid == L_OPTIONS_074 || elem->textid == L_OPTIONS_073) {
#if VERSION >= VERSION_PAL_FINAL
					s32 stack;
					prevx += 10;
#endif

					if (IS4MB()) {
						elem->textid = L_OPTIONS_074;
					} else {
						elem->textid = L_OPTIONS_073;
					}
				}
				break;
			case LEGALELEMENTTYPE_WHITETEXTSM:
				font1 = g_CharsHandelGothicSm;
				font2 = g_FontHandelGothicSm;
				colour = 0xffffffff;
				break;
			default:
				font1 = g_CharsHandelGothicLg;
				font2 = g_FontHandelGothicLg;
				break;
			}

			if (elem->type == LEGALELEMENTTYPE_LINE) {
				gdl = func0f153780(gdl);
				gdl = func0f153a34(gdl, elem->x, elem->y, viGetWidth(), elem->y + 2, 0x7f7fff7f);
				gdl = func0f153628(gdl);
			} else if (elem->type == LEGALELEMENTTYPE_DOLBYLOGO) {
				gdl = func0f153780(gdl);

				gDPPipeSync(gdl++);
				gDPSetTexturePersp(gdl++, G_TP_NONE);
				gDPSetAlphaCompare(gdl++, G_AC_NONE);
				gDPSetTextureLOD(gdl++, G_TL_TILE);
				gDPSetTextureConvert(gdl++, G_TC_FILT);

				func0f0b39c0(&gdl, &g_TexGeneralConfigs[47], 1, 0, 2, 1, 0);

				gDPSetCycleType(gdl++, G_CYC_1CYCLE);
				gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
				gDPSetTextureFilter(gdl++, G_TF_POINT);

				gSPTextureRectangle(gdl++,
						elem->x << 2,
						elem->y << 2,
						(elem->x + 64) << 2,
						(elem->y + 24) << 2,
						G_TX_RENDERTILE, 0, 0x0300, 0x0400, -0x0400);

				gdl = func0f153628(gdl);
			} else if (elem->type == LEGALELEMENTTYPE_RARELOGO) {
				gdl = func0f153780(gdl);

				gDPPipeSync(gdl++);
				gDPSetTexturePersp(gdl++, G_TP_NONE);
				gDPSetAlphaCompare(gdl++, G_AC_NONE);
				gDPSetTextureLOD(gdl++, G_TL_TILE);
				gDPSetTextureConvert(gdl++, G_TC_FILT);

				func0f0b39c0(&gdl, &g_TexGeneralConfigs[49], 1, 0, 2, 1, 0);

				gDPSetCycleType(gdl++, G_CYC_1CYCLE);
				gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
				gDPSetTextureFilter(gdl++, G_TF_POINT);

				gSPTextureRectangle(gdl++,
						elem->x << 2,
						elem->y << 2,
						(elem->x + 32) << 2,
						(elem->y + 42) << 2,
						G_TX_RENDERTILE, 0, 0x0540, 0x0400, -0x0400);

				gdl = func0f153628(gdl);
			} else {
#if VERSION >= VERSION_PAL_FINAL
				// Render a darker copy of the text one pixel above
				x = elem->x == -1 ? prevx : elem->x;
				y = elem->y - 1;
				gdl = textRenderProjected(gdl, &x, &y, langGet(elem->textid), font1, font2, (colour & 0xffffff00) | ((colour & 0xff) * 2 / 3), viGetWidth(), viGetHeight(), 0, 0);

				// Render the text properly
				x = elem->x == -1 ? prevx : elem->x;
				y = elem->y;
				gdl = textRenderProjected(gdl, &x, &y, langGet(elem->textid), font1, font2, colour, viGetWidth(), viGetHeight(), 0, 0);

				prevx = x;
#else
				x = elem->x;
				y = elem->y;
				gdl = textRenderProjected(gdl, &x, &y, langGet(elem->textid), font1, font2, colour, viGetWidth(), viGetHeight(), 0, 0);
#endif
			}
		}

		gdl = func0f153780(gdl);
	}

	return gdl;
}

bool g_LegalEnabled = true;
bool g_PdLogoIsFirstTick = true;
bool g_PdLogoTriggerExit = false;

u32 var80062738 = 0;
u32 var8006273c = 0;
u32 var80062740 = 0;
u32 var80062744 = 0;
u32 var80062748 = 0;
u32 var8006274c = 0;
u32 var80062750 = 0;
u32 var80062754 = 0;
u32 var80062758 = 0;
u32 var8006275c = 0;
u32 var80062760 = 0;
u32 var80062764 = 0;

GLOBAL_ASM(
glabel titleInitPdLogo
/*  f016d34:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f016d38:	3c018006 */ 	lui	$at,%hi(g_TitleTimer)
/*  f016d3c:	3c0f8006 */ 	lui	$t7,%hi(var80062738)
/*  f016d40:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f016d44:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f016d48:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f016d4c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f016d50:	ac2024c4 */ 	sw	$zero,%lo(g_TitleTimer)($at)
/*  f016d54:	25ef2738 */ 	addiu	$t7,$t7,%lo(var80062738)
/*  f016d58:	8de10000 */ 	lw	$at,0x0($t7)
/*  f016d5c:	3c10800a */ 	lui	$s0,%hi(var8009cca0)
/*  f016d60:	8e10cca0 */ 	lw	$s0,%lo(var8009cca0)($s0)
/*  f016d64:	27ae0058 */ 	addiu	$t6,$sp,0x58
/*  f016d68:	adc10000 */ 	sw	$at,0x0($t6)
/*  f016d6c:	8de10008 */ 	lw	$at,0x8($t7)
/*  f016d70:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f016d74:	3c118008 */ 	lui	$s1,%hi(g_ModelStates)
/*  f016d78:	2631b06c */ 	addiu	$s1,$s1,%lo(g_ModelStates)
/*  f016d7c:	3c060004 */ 	lui	$a2,0x4
/*  f016d80:	adc10008 */ 	sw	$at,0x8($t6)
/*  f016d84:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f016d88:	96240244 */ 	lhu	$a0,0x244($s1)
/*  f016d8c:	34c67800 */ 	ori	$a2,$a2,0x7800
/*  f016d90:	00003825 */ 	or	$a3,$zero,$zero
/*  f016d94:	0fc69de5 */ 	jal	func0f1a7794
/*  f016d98:	02002825 */ 	or	$a1,$s0,$zero
/*  f016d9c:	ae220240 */ 	sw	$v0,0x240($s1)
/*  f016da0:	0fc59ca0 */ 	jal	fileGetSize
/*  f016da4:	96240244 */ 	lhu	$a0,0x244($s1)
/*  f016da8:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016dac:	3469003f */ 	ori	$t1,$v1,0x3f
/*  f016db0:	3c0b0004 */ 	lui	$t3,0x4
/*  f016db4:	392a003f */ 	xori	$t2,$t1,0x3f
/*  f016db8:	356b7800 */ 	ori	$t3,$t3,0x7800
/*  f016dbc:	020a8021 */ 	addu	$s0,$s0,$t2
/*  f016dc0:	016a9023 */ 	subu	$s2,$t3,$t2
/*  f016dc4:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f016dc8:	8e240240 */ 	lw	$a0,0x240($s1)
/*  f016dcc:	0fc2cca0 */ 	jal	func0f0b3280
/*  f016dd0:	8e240240 */ 	lw	$a0,0x240($s1)
/*  f016dd4:	3c038006 */ 	lui	$v1,%hi(g_TitleModel)
/*  f016dd8:	246324f8 */ 	addiu	$v1,$v1,%lo(g_TitleModel)
/*  f016ddc:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f016de0:	00402025 */ 	or	$a0,$v0,$zero
/*  f016de4:	0c006bd6 */ 	jal	modelSetScale
/*  f016de8:	3c053f80 */ 	lui	$a1,0x3f80
/*  f016dec:	3c048006 */ 	lui	$a0,%hi(g_TitleModel)
/*  f016df0:	8c8424f8 */ 	lw	$a0,%lo(g_TitleModel)($a0)
/*  f016df4:	0c006b4d */ 	jal	modelSetRootPosition
/*  f016df8:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f016dfc:	3c0d8006 */ 	lui	$t5,%hi(var80062744)
/*  f016e00:	25ad2744 */ 	addiu	$t5,$t5,%lo(var80062744)
/*  f016e04:	8da10000 */ 	lw	$at,0x0($t5)
/*  f016e08:	27ac004c */ 	addiu	$t4,$sp,0x4c
/*  f016e0c:	8db80004 */ 	lw	$t8,0x4($t5)
/*  f016e10:	ad810000 */ 	sw	$at,0x0($t4)
/*  f016e14:	8da10008 */ 	lw	$at,0x8($t5)
/*  f016e18:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f016e1c:	02002825 */ 	or	$a1,$s0,$zero
/*  f016e20:	ad810008 */ 	sw	$at,0x8($t4)
/*  f016e24:	9624024c */ 	lhu	$a0,0x24c($s1)
/*  f016e28:	02403025 */ 	or	$a2,$s2,$zero
/*  f016e2c:	0fc69de5 */ 	jal	func0f1a7794
/*  f016e30:	00003825 */ 	or	$a3,$zero,$zero
/*  f016e34:	ae220248 */ 	sw	$v0,0x248($s1)
/*  f016e38:	0fc59ca0 */ 	jal	fileGetSize
/*  f016e3c:	9624024c */ 	lhu	$a0,0x24c($s1)
/*  f016e40:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016e44:	346e003f */ 	ori	$t6,$v1,0x3f
/*  f016e48:	39cf003f */ 	xori	$t7,$t6,0x3f
/*  f016e4c:	020f8021 */ 	addu	$s0,$s0,$t7
/*  f016e50:	024f9023 */ 	subu	$s2,$s2,$t7
/*  f016e54:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f016e58:	8e240248 */ 	lw	$a0,0x248($s1)
/*  f016e5c:	0fc2cca0 */ 	jal	func0f0b3280
/*  f016e60:	8e240248 */ 	lw	$a0,0x248($s1)
/*  f016e64:	3c038006 */ 	lui	$v1,%hi(g_TitleModelNLogo2)
/*  f016e68:	246324fc */ 	addiu	$v1,$v1,%lo(g_TitleModelNLogo2)
/*  f016e6c:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f016e70:	00402025 */ 	or	$a0,$v0,$zero
/*  f016e74:	0c006bd6 */ 	jal	modelSetScale
/*  f016e78:	3c053f80 */ 	lui	$a1,0x3f80
/*  f016e7c:	3c048006 */ 	lui	$a0,%hi(g_TitleModelNLogo2)
/*  f016e80:	8c8424fc */ 	lw	$a0,%lo(g_TitleModelNLogo2)($a0)
/*  f016e84:	0c006b4d */ 	jal	modelSetRootPosition
/*  f016e88:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f016e8c:	3c098006 */ 	lui	$t1,%hi(var80062750)
/*  f016e90:	25292750 */ 	addiu	$t1,$t1,%lo(var80062750)
/*  f016e94:	8d210000 */ 	lw	$at,0x0($t1)
/*  f016e98:	27a80040 */ 	addiu	$t0,$sp,0x40
/*  f016e9c:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*  f016ea0:	ad010000 */ 	sw	$at,0x0($t0)
/*  f016ea4:	8d210008 */ 	lw	$at,0x8($t1)
/*  f016ea8:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f016eac:	02002825 */ 	or	$a1,$s0,$zero
/*  f016eb0:	ad010008 */ 	sw	$at,0x8($t0)
/*  f016eb4:	9624026c */ 	lhu	$a0,0x26c($s1)
/*  f016eb8:	02403025 */ 	or	$a2,$s2,$zero
/*  f016ebc:	0fc69de5 */ 	jal	func0f1a7794
/*  f016ec0:	00003825 */ 	or	$a3,$zero,$zero
/*  f016ec4:	ae220268 */ 	sw	$v0,0x268($s1)
/*  f016ec8:	0fc59ca0 */ 	jal	fileGetSize
/*  f016ecc:	9624026c */ 	lhu	$a0,0x26c($s1)
/*  f016ed0:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016ed4:	3479003f */ 	ori	$t9,$v1,0x3f
/*  f016ed8:	3b2c003f */ 	xori	$t4,$t9,0x3f
/*  f016edc:	020c8021 */ 	addu	$s0,$s0,$t4
/*  f016ee0:	024c9023 */ 	subu	$s2,$s2,$t4
/*  f016ee4:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f016ee8:	8e240268 */ 	lw	$a0,0x268($s1)
/*  f016eec:	0fc2cc2b */ 	jal	modelInstantiate
/*  f016ef0:	8e240268 */ 	lw	$a0,0x268($s1)
/*  f016ef4:	3c038006 */ 	lui	$v1,%hi(g_TitleModelPdTwo)
/*  f016ef8:	24632508 */ 	addiu	$v1,$v1,%lo(g_TitleModelPdTwo)
/*  f016efc:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f016f00:	00402025 */ 	or	$a0,$v0,$zero
/*  f016f04:	0c006bd6 */ 	jal	modelSetScale
/*  f016f08:	3c053f80 */ 	lui	$a1,0x3f80
/*  f016f0c:	3c048006 */ 	lui	$a0,%hi(g_TitleModelPdTwo)
/*  f016f10:	8c842508 */ 	lw	$a0,%lo(g_TitleModelPdTwo)($a0)
/*  f016f14:	0c006b4d */ 	jal	modelSetRootPosition
/*  f016f18:	27a50040 */ 	addiu	$a1,$sp,0x40
/*  f016f1c:	3c188006 */ 	lui	$t8,%hi(var8006275c)
/*  f016f20:	2718275c */ 	addiu	$t8,$t8,%lo(var8006275c)
/*  f016f24:	8f010000 */ 	lw	$at,0x0($t8)
/*  f016f28:	27ad0034 */ 	addiu	$t5,$sp,0x34
/*  f016f2c:	8f0f0004 */ 	lw	$t7,0x4($t8)
/*  f016f30:	ada10000 */ 	sw	$at,0x0($t5)
/*  f016f34:	8f010008 */ 	lw	$at,0x8($t8)
/*  f016f38:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f016f3c:	02002825 */ 	or	$a1,$s0,$zero
/*  f016f40:	ada10008 */ 	sw	$at,0x8($t5)
/*  f016f44:	96240274 */ 	lhu	$a0,0x274($s1)
/*  f016f48:	02403025 */ 	or	$a2,$s2,$zero
/*  f016f4c:	0fc69de5 */ 	jal	func0f1a7794
/*  f016f50:	00003825 */ 	or	$a3,$zero,$zero
/*  f016f54:	ae220270 */ 	sw	$v0,0x270($s1)
/*  f016f58:	0fc59ca0 */ 	jal	fileGetSize
/*  f016f5c:	96240274 */ 	lhu	$a0,0x274($s1)
/*  f016f60:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016f64:	346a003f */ 	ori	$t2,$v1,0x3f
/*  f016f68:	3948003f */ 	xori	$t0,$t2,0x3f
/*  f016f6c:	02088021 */ 	addu	$s0,$s0,$t0
/*  f016f70:	02489023 */ 	subu	$s2,$s2,$t0
/*  f016f74:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f016f78:	8e240270 */ 	lw	$a0,0x270($s1)
/*  f016f7c:	0fc2cc2b */ 	jal	modelInstantiate
/*  f016f80:	8e240270 */ 	lw	$a0,0x270($s1)
/*  f016f84:	3c038006 */ 	lui	$v1,%hi(g_TitleModelPdThree)
/*  f016f88:	2463250c */ 	addiu	$v1,$v1,%lo(g_TitleModelPdThree)
/*  f016f8c:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f016f90:	00402025 */ 	or	$a0,$v0,$zero
/*  f016f94:	0c006bd6 */ 	jal	modelSetScale
/*  f016f98:	3c053f80 */ 	lui	$a1,0x3f80
/*  f016f9c:	3c048006 */ 	lui	$a0,%hi(g_TitleModelPdThree)
/*  f016fa0:	8c84250c */ 	lw	$a0,%lo(g_TitleModelPdThree)($a0)
/*  f016fa4:	0c006b4d */ 	jal	modelSetRootPosition
/*  f016fa8:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f016fac:	8e240268 */ 	lw	$a0,0x268($s1)
/*  f016fb0:	0c006a6f */ 	jal	modelGetPartRodata
/*  f016fb4:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f016fb8:	84430010 */ 	lh	$v1,0x10($v0)
/*  f016fbc:	3c04800a */ 	lui	$a0,%hi(var8009cca8)
/*  f016fc0:	2484cca8 */ 	addiu	$a0,$a0,%lo(var8009cca8)
/*  f016fc4:	00034880 */ 	sll	$t1,$v1,0x2
/*  f016fc8:	01234823 */ 	subu	$t1,$t1,$v1
/*  f016fcc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f016fd0:	25230007 */ 	addiu	$v1,$t1,0x7
/*  f016fd4:	346b0007 */ 	ori	$t3,$v1,0x7
/*  f016fd8:	39790007 */ 	xori	$t9,$t3,0x7
/*  f016fdc:	ac900000 */ 	sw	$s0,0x0($a0)
/*  f016fe0:	02198021 */ 	addu	$s0,$s0,$t9
/*  f016fe4:	ac900004 */ 	sw	$s0,0x4($a0)
/*  f016fe8:	94430016 */ 	lhu	$v1,0x16($v0)
/*  f016fec:	3c05800a */ 	lui	$a1,%hi(var8009ccb0)
/*  f016ff0:	24a5ccb0 */ 	addiu	$a1,$a1,%lo(var8009ccb0)
/*  f016ff4:	00036080 */ 	sll	$t4,$v1,0x2
/*  f016ff8:	25830007 */ 	addiu	$v1,$t4,0x7
/*  f016ffc:	02198021 */ 	addu	$s0,$s0,$t9
/*  f017000:	346e0007 */ 	ori	$t6,$v1,0x7
/*  f017004:	39cd0007 */ 	xori	$t5,$t6,0x7
/*  f017008:	acb00000 */ 	sw	$s0,0x0($a1)
/*  f01700c:	020d8021 */ 	addu	$s0,$s0,$t5
/*  f017010:	acb00004 */ 	sw	$s0,0x4($a1)
/*  f017014:	3c01800a */ 	lui	$at,%hi(var8009ccb8)
/*  f017018:	ac20ccb8 */ 	sw	$zero,%lo(var8009ccb8)($at)
/*  f01701c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f017020:	3c018006 */ 	lui	$at,%hi(var800624f4)
/*  f017024:	ac3024f4 */ 	sw	$s0,%lo(var800624f4)($at)
/*  f017028:	0c005204 */ 	jal	joy00014810
/*  f01702c:	00002025 */ 	or	$a0,$zero,$zero
/*  f017030:	3c188006 */ 	lui	$t8,%hi(g_TitleButtonPressed)
/*  f017034:	8f1824a8 */ 	lw	$t8,%lo(g_TitleButtonPressed)($t8)
/*  f017038:	3c018006 */ 	lui	$at,%hi(g_PdLogoIsFirstTick)
/*  f01703c:	ac302730 */ 	sw	$s0,%lo(g_PdLogoIsFirstTick)($at)
/*  f017040:	3c018006 */ 	lui	$at,%hi(g_PdLogoTriggerExit)
/*  f017044:	13000003 */ 	beqz	$t8,.L0f017054
/*  f017048:	ac202734 */ 	sw	$zero,%lo(g_PdLogoTriggerExit)($at)
/*  f01704c:	0fc05e60 */ 	jal	titleSkipToPdTitle
/*  f017050:	00000000 */ 	nop
.L0f017054:
/*  f017054:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f017058:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f01705c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f017060:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f017064:	03e00008 */ 	jr	$ra
/*  f017068:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

// Mismatch due to regalloc in lat block
//void titleInitPdLogo(void)
//{
//	u8 *nextaddr = var8009cca0;
//	u32 remaining;
//	u32 size;
//
//	g_TitleTimer = 0;
//
//	{
//		struct coord coord = {0, 0, 0}; // var80062738
//		g_ModelStates[MODEL_NLOGO].filedata = func0f1a7794(g_ModelStates[MODEL_NLOGO].fileid, nextaddr, 0x47800, 0);
//		size = ALIGN64(fileGetSize(g_ModelStates[MODEL_NLOGO].fileid));
//		nextaddr += size;
//		remaining = 0x47800 - size;
//		modelCalculateRwDataLen(g_ModelStates[MODEL_NLOGO].filedata);
//
//		g_TitleModel = func0f0b3280(g_ModelStates[MODEL_NLOGO].filedata);
//		modelSetScale(g_TitleModel, 1);
//		modelSetRootPosition(g_TitleModel, &coord);
//	}
//
//	{
//		struct coord coord = {0, 0, 0}; // var80062744
//		g_ModelStates[MODEL_NLOGO2].filedata = func0f1a7794(g_ModelStates[MODEL_NLOGO2].fileid, nextaddr, remaining, 0);
//		size = ALIGN64(fileGetSize(g_ModelStates[MODEL_NLOGO2].fileid));
//		nextaddr += size;
//		remaining -= size;
//		modelCalculateRwDataLen(g_ModelStates[MODEL_NLOGO2].filedata);
//
//		g_TitleModelNLogo2 = func0f0b3280(g_ModelStates[MODEL_NLOGO2].filedata);
//		modelSetScale(g_TitleModelNLogo2, 1);
//		modelSetRootPosition(g_TitleModelNLogo2, &coord);
//	}
//
//	{
//		struct coord coord = {0, 0, 0}; // var80062750
//		g_ModelStates[MODEL_PDTWO].filedata = func0f1a7794(g_ModelStates[MODEL_PDTWO].fileid, nextaddr, remaining, 0);
//		size = ALIGN64(fileGetSize(g_ModelStates[MODEL_PDTWO].fileid));
//		nextaddr += size;
//		remaining -= size;
//		modelCalculateRwDataLen(g_ModelStates[MODEL_PDTWO].filedata);
//
//		g_TitleModelPdTwo = modelInstantiate(g_ModelStates[MODEL_PDTWO].filedata);
//		modelSetScale(g_TitleModelPdTwo, 1);
//		modelSetRootPosition(g_TitleModelPdTwo, &coord);
//	}
//
//	{
//		struct coord coord = {0, 0, 0}; // var8006275c
//		g_ModelStates[MODEL_PDTHREE].filedata = func0f1a7794(g_ModelStates[MODEL_PDTHREE].fileid, nextaddr, remaining, 0);
//		size = ALIGN64(fileGetSize(g_ModelStates[MODEL_PDTHREE].fileid));
//		nextaddr += size;
//		remaining -= size;
//		modelCalculateRwDataLen(g_ModelStates[MODEL_PDTHREE].filedata);
//
//		g_TitleModelPdThree = modelInstantiate(g_ModelStates[MODEL_PDTHREE].filedata);
//		modelSetScale(g_TitleModelPdThree, 1);
//		modelSetRootPosition(g_TitleModelPdThree, &coord);
//	}
//
//	{
//		// fb0
//		struct modelrodata_dl *rodata = (struct modelrodata_dl *)modelGetPartRodata(g_ModelStates[MODEL_PDTWO].filedata, MODELPART_LOGO_0002);
//		u32 size2;
//
//		size = ALIGN8(rodata->numvertices * sizeof(struct gfxvtx));
//
//		var8009cca8[0] = nextaddr;
//
//		nextaddr += size;
//		remaining -= size;
//		var8009cca8[1] = nextaddr;
//
//		nextaddr += size;
//		remaining -= size;
//		size2 = ALIGN8(rodata->numcolours * sizeof(struct colour));
//		var8009ccb0[0] = nextaddr;
//
//		nextaddr += size2;
//		remaining -= size2;
//		var8009ccb0[1] = nextaddr;
//
//		var8009ccb8 = 0;
//		var800624f4 = 1;
//
//		joy00014810(false);
//
//		g_PdLogoIsFirstTick = true;
//		g_PdLogoTriggerExit = false;
//
//		if (g_TitleButtonPressed) {
//			titleSkipToPdTitle();
//		}
//	}
//}

void titleExitPdLogo(void)
{
	modelFree(g_TitleModel);
	modelFree(g_TitleModelNLogo2);
	modelFree(g_TitleModelPdTwo);
	modelFree(g_TitleModelPdThree);

	joy00014810(true);
}

void titleTickPdLogo(void)
{
	viSetFovY(46);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	viSetUseZBuf(false);

	g_TitleTimer += g_Vars.lvupdate240_60;
	var8009ccb8 = 1 - var8009ccb8;

	if (g_PdLogoTriggerExit) {
		// Exiting due to player not pressing anything
		if (g_AltTitleEnabled && IS8MB()) {
			g_TitleMode = TITLEMODE_SKIP;
			creditsRequestAltTitle();
			g_TitleNextStage = STAGE_CREDITS; // for alt title screen
			setNumPlayers(1);
			mainChangeToStage(g_TitleNextStage);

			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = -1;

			lvSetDifficulty(DIFF_A);
			viBlack(true);
		} else {
			titleSetNextMode(TITLEMODE_SKIP);
		}
	}

	if (g_TitleButtonPressed && g_TitleTimer > TICKS(666)) {
		titleSetNextMode(TITLEMODE_SKIP);
	}

	if (joyGetButtonsPressedThisFrame(0, 0xffff)) {
		g_TitleButtonPressed = g_TitleFastForward = true;

		if (g_TitleTimer < TICKS(549)) {
			titleSetNextMode(TITLEMODE_PDLOGO);
		}
	}
}

u32 var80062768 = 0x00000000;
u32 var8006276c = 0x00000001;
u32 var80062770 = 0x00000003;
u32 var80062774 = 0x00000000;
u32 var80062778 = 0x00000000;
u32 var8006277c = 0x00000000;
u32 var80062780 = 0x00000000;
u32 var80062784 = 0x00000000;
u32 var80062788 = 0x00000000;
u32 var8006278c = 0x00000000;
u32 var80062790 = 0x00000000;
u32 var80062794 = 0x00000000;
u32 var80062798 = 0x00000000;
u32 var8006279c = 0x00000000;
u32 var800627a0 = 0x00000000;
u32 var800627a4 = 0x00000000;

f32 g_PdLogoYRotCur = 0;
f32 g_PdLogoYRotSpeed = 0;
f32 g_PdLogoXRotCur = 0;
f32 g_PdLogoXRotSpeed = 0;
f32 g_PdLogoScale = 1;
f32 g_PdLogoFrac = 0;
bool g_PdLogoUseCombinedModel = false;
f32 g_PdLogoEndYRot = 0;
f32 g_PdLogoAmbientLightFrac = 1;
s32 g_PdLogoBlackTimer = 0;
bool g_PdLogoYRotEnabled = false;
s32 g_PdLogoPreMorphTimer = 0;
bool g_PdLogoMorphing = false;
s32 g_PdLogoExitTimer = 0;
s32 g_PdLogoMorphEndTimer = 0;
bool g_PdLogoYRotStopping = false;
bool g_PdLogoDarkenEnabled = false;
bool g_PdLogoPointlessTimerEnabled = false;
s32 g_PdLogoPreTitleTimer = 0;
f32 g_PdLogoTitleStepFrac = 0;
s32 g_PdLogoTitleStep = 0;
bool g_PdLogoTitlePresenting = false;
s32 g_PdLogoPointlessTimer = 0;
s32 var80062804 = 1;
f32 g_PdLogoUnusedRot = 1.5705462694168;
bool g_PdLogoUnusedRotEnabled = false;
bool g_PdLogoLightMoving = false;
f32 g_PdLogoLightDirFrac = 0;

GLOBAL_ASM(
glabel titleRenderPdLogoModel
/*  f017248:	27bdfeb0 */ 	addiu	$sp,$sp,-336
/*  f01724c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f017250:	3c0f8006 */ 	lui	$t7,%hi(var80062768)
/*  f017254:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f017258:	25ef2768 */ 	addiu	$t7,$t7,%lo(var80062768)
/*  f01725c:	4487a000 */ 	mtc1	$a3,$f20
/*  f017260:	00a0b825 */ 	or	$s7,$a1,$zero
/*  f017264:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f017268:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f01726c:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f017270:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f017274:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f017278:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f01727c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f017280:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f017284:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f017288:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f01728c:	afa40150 */ 	sw	$a0,0x150($sp)
/*  f017290:	afa60158 */ 	sw	$a2,0x158($sp)
/*  f017294:	25eb003c */ 	addiu	$t3,$t7,0x3c
/*  f017298:	27ae0110 */ 	addiu	$t6,$sp,0x110
.L0f01729c:
/*  f01729c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0172a0:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f0172a4:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f0172a8:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f0172ac:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f0172b0:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f0172b4:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f0172b8:	15ebfff8 */ 	bne	$t7,$t3,.L0f01729c
/*  f0172bc:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f0172c0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0172c4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0172c8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0172cc:	0c006a47 */ 	jal	modelGetPart
/*  f0172d0:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f0172d4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0172d8:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0172dc:	00402825 */ 	or	$a1,$v0,$zero
/*  f0172e0:	8fac0158 */ 	lw	$t4,0x158($sp)
/*  f0172e4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0172e8:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0172ec:	0c006a47 */ 	jal	modelGetPart
/*  f0172f0:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f0172f4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0172f8:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0172fc:	00402825 */ 	or	$a1,$v0,$zero
/*  f017300:	3c014780 */ 	lui	$at,0x4780
/*  f017304:	44812000 */ 	mtc1	$at,$f4
/*  f017308:	8fa60158 */ 	lw	$a2,0x158($sp)
/*  f01730c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f017310:	4604a182 */ 	mul.s	$f6,$f20,$f4
/*  f017314:	4480a000 */ 	mtc1	$zero,$f20
/*  f017318:	2ccd0001 */ 	sltiu	$t5,$a2,0x1
/*  f01731c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f017320:	27be00c0 */ 	addiu	$s8,$sp,0xc0
/*  f017324:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f017328:	44034000 */ 	mfc1	$v1,$f8
/*  f01732c:	00000000 */ 	nop
/*  f017330:	04610003 */ 	bgez	$v1,.L0f017340
/*  f017334:	0060b025 */ 	or	$s6,$v1,$zero
/*  f017338:	10000007 */ 	b	.L0f017358
/*  f01733c:	0000b025 */ 	or	$s6,$zero,$zero
.L0f017340:
/*  f017340:	3c010001 */ 	lui	$at,0x1
/*  f017344:	34210001 */ 	ori	$at,$at,0x1
/*  f017348:	0061082a */ 	slt	$at,$v1,$at
/*  f01734c:	54200003 */ 	bnezl	$at,.L0f01735c
/*  f017350:	8fa30160 */ 	lw	$v1,0x160($sp)
/*  f017354:	3c160001 */ 	lui	$s6,0x1
.L0f017358:
/*  f017358:	8fa30160 */ 	lw	$v1,0x160($sp)
.L0f01735c:
/*  f01735c:	06c10003 */ 	bgez	$s6,.L0f01736c
/*  f017360:	00161203 */ 	sra	$v0,$s6,0x8
/*  f017364:	26c100ff */ 	addiu	$at,$s6,0xff
/*  f017368:	00011203 */ 	sra	$v0,$at,0x8
.L0f01736c:
/*  f01736c:	0062082a */ 	slt	$at,$v1,$v0
/*  f017370:	10200002 */ 	beqz	$at,.L0f01737c
/*  f017374:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f017378:	afa300d8 */ 	sw	$v1,0xd8($sp)
.L0f01737c:
/*  f01737c:	14c00006 */ 	bnez	$a2,.L0f017398
/*  f017380:	3c180001 */ 	lui	$t8,0x1
/*  f017384:	8fab00d8 */ 	lw	$t3,0xd8($sp)
/*  f017388:	240f0100 */ 	addiu	$t7,$zero,0x100
/*  f01738c:	0316b023 */ 	subu	$s6,$t8,$s6
/*  f017390:	01eb7023 */ 	subu	$t6,$t7,$t3
/*  f017394:	afae00d8 */ 	sw	$t6,0xd8($sp)
.L0f017398:
/*  f017398:	8fac00d8 */ 	lw	$t4,0xd8($sp)
/*  f01739c:	8fad00d8 */ 	lw	$t5,0xd8($sp)
/*  f0173a0:	05810003 */ 	bgez	$t4,.L0f0173b0
/*  f0173a4:	29a10100 */ 	slti	$at,$t5,0x100
/*  f0173a8:	10000004 */ 	b	.L0f0173bc
/*  f0173ac:	afa000d8 */ 	sw	$zero,0xd8($sp)
.L0f0173b0:
/*  f0173b0:	14200002 */ 	bnez	$at,.L0f0173bc
/*  f0173b4:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f0173b8:	afb900d8 */ 	sw	$t9,0xd8($sp)
.L0f0173bc:
/*  f0173bc:	3c014380 */ 	lui	$at,0x4380
/*  f0173c0:	44818000 */ 	mtc1	$at,$f16
/*  f0173c4:	c7aa0164 */ 	lwc1	$f10,0x164($sp)
/*  f0173c8:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0173cc:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0173d0:	44022000 */ 	mfc1	$v0,$f4
/*  f0173d4:	00000000 */ 	nop
/*  f0173d8:	04410003 */ 	bgez	$v0,.L0f0173e8
/*  f0173dc:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0173e0:	10000005 */ 	b	.L0f0173f8
/*  f0173e4:	afa000b8 */ 	sw	$zero,0xb8($sp)
.L0f0173e8:
/*  f0173e8:	28410100 */ 	slti	$at,$v0,0x100
/*  f0173ec:	14200002 */ 	bnez	$at,.L0f0173f8
/*  f0173f0:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f0173f4:	afaf00b8 */ 	sw	$t7,0xb8($sp)
.L0f0173f8:
/*  f0173f8:	8fab016c */ 	lw	$t3,0x16c($sp)
/*  f0173fc:	8fae0170 */ 	lw	$t6,0x170($sp)
/*  f017400:	3c0142fe */ 	lui	$at,0x42fe
/*  f017404:	4481b000 */ 	mtc1	$at,$f22
/*  f017408:	afa00108 */ 	sw	$zero,0x108($sp)
/*  f01740c:	afab0100 */ 	sw	$t3,0x100($sp)
/*  f017410:	afae00fc */ 	sw	$t6,0xfc($sp)
.L0f017414:
/*  f017414:	8fac0108 */ 	lw	$t4,0x108($sp)
/*  f017418:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f01741c:	8fad0108 */ 	lw	$t5,0x108($sp)
/*  f017420:	15800009 */ 	bnez	$t4,.L0f017448
/*  f017424:	24010001 */ 	addiu	$at,$zero,0x1
/*  f017428:	0c006a47 */ 	jal	modelGetPart
/*  f01742c:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017430:	00408025 */ 	or	$s0,$v0,$zero
/*  f017434:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017438:	0c006a47 */ 	jal	modelGetPart
/*  f01743c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f017440:	1000001f */ 	b	.L0f0174c0
/*  f017444:	00403025 */ 	or	$a2,$v0,$zero
.L0f017448:
/*  f017448:	15a1000a */ 	bne	$t5,$at,.L0f017474
/*  f01744c:	8fb90108 */ 	lw	$t9,0x108($sp)
/*  f017450:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017454:	0c006a47 */ 	jal	modelGetPart
/*  f017458:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f01745c:	00408025 */ 	or	$s0,$v0,$zero
/*  f017460:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017464:	0c006a47 */ 	jal	modelGetPart
/*  f017468:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f01746c:	10000014 */ 	b	.L0f0174c0
/*  f017470:	00403025 */ 	or	$a2,$v0,$zero
.L0f017474:
/*  f017474:	24010002 */ 	addiu	$at,$zero,0x2
/*  f017478:	1721000a */ 	bne	$t9,$at,.L0f0174a4
/*  f01747c:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f017480:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017484:	0c006a47 */ 	jal	modelGetPart
/*  f017488:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f01748c:	00408025 */ 	or	$s0,$v0,$zero
/*  f017490:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017494:	0c006a47 */ 	jal	modelGetPart
/*  f017498:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f01749c:	10000008 */ 	b	.L0f0174c0
/*  f0174a0:	00403025 */ 	or	$a2,$v0,$zero
.L0f0174a4:
/*  f0174a4:	0c006a47 */ 	jal	modelGetPart
/*  f0174a8:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f0174ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f0174b0:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f0174b4:	0c006a47 */ 	jal	modelGetPart
/*  f0174b8:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f0174bc:	00403025 */ 	or	$a2,$v0,$zero
.L0f0174c0:
/*  f0174c0:	520000e5 */ 	beqzl	$s0,.L0f017858
/*  f0174c4:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0174c8:	104000e2 */ 	beqz	$v0,.L0f017854
/*  f0174cc:	8fb80158 */ 	lw	$t8,0x158($sp)
/*  f0174d0:	13000008 */ 	beqz	$t8,.L0f0174f4
/*  f0174d4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0174d8:	8e150004 */ 	lw	$s5,0x4($s0)
/*  f0174dc:	8cd10004 */ 	lw	$s1,0x4($a2)
/*  f0174e0:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0174e4:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0174e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0174ec:	10000006 */ 	b	.L0f017508
/*  f0174f0:	86af0010 */ 	lh	$t7,0x10($s5)
.L0f0174f4:
/*  f0174f4:	8cd50004 */ 	lw	$s5,0x4($a2)
/*  f0174f8:	8e110004 */ 	lw	$s1,0x4($s0)
/*  f0174fc:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f017500:	00c02825 */ 	or	$a1,$a2,$zero
/*  f017504:	86af0010 */ 	lh	$t7,0x10($s5)
.L0f017508:
/*  f017508:	8ea7000c */ 	lw	$a3,0xc($s5)
/*  f01750c:	862d0010 */ 	lh	$t5,0x10($s1)
/*  f017510:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f017514:	016f5823 */ 	subu	$t3,$t3,$t7
/*  f017518:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f01751c:	01674821 */ 	addu	$t1,$t3,$a3
/*  f017520:	8fab0100 */ 	lw	$t3,0x100($sp)
/*  f017524:	25290007 */ 	addiu	$t1,$t1,0x7
/*  f017528:	8e28000c */ 	lw	$t0,0xc($s1)
/*  f01752c:	352e0007 */ 	ori	$t6,$t1,0x7
/*  f017530:	39c90007 */ 	xori	$t1,$t6,0x7
/*  f017534:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f017538:	8fae00fc */ 	lw	$t6,0xfc($sp)
/*  f01753c:	000dc880 */ 	sll	$t9,$t5,0x2
/*  f017540:	032dc823 */ 	subu	$t9,$t9,$t5
/*  f017544:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f017548:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f01754c:	86a60010 */ 	lh	$a2,0x10($s5)
/*  f017550:	03285021 */ 	addu	$t2,$t9,$t0
/*  f017554:	254a0007 */ 	addiu	$t2,$t2,0x7
/*  f017558:	35580007 */ 	ori	$t8,$t2,0x7
/*  f01755c:	18c00044 */ 	blez	$a2,.L0f017670
/*  f017560:	3b0a0007 */ 	xori	$t2,$t8,0x7
/*  f017564:	8fa30100 */ 	lw	$v1,0x100($sp)
/*  f017568:	00e02025 */ 	or	$a0,$a3,$zero
/*  f01756c:	01002825 */ 	or	$a1,$t0,$zero
/*  f017570:	88810000 */ 	lwl	$at,0x0($a0)
.L0f017574:
/*  f017574:	98810003 */ 	lwr	$at,0x3($a0)
/*  f017578:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f01757c:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f017580:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f017584:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f017588:	888d0004 */ 	lwl	$t5,0x4($a0)
/*  f01758c:	988d0007 */ 	lwr	$t5,0x7($a0)
/*  f017590:	846efff4 */ 	lh	$t6,-0xc($v1)
/*  f017594:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f017598:	a86dfff8 */ 	swl	$t5,-0x8($v1)
/*  f01759c:	b86dfffb */ 	swr	$t5,-0x5($v1)
/*  f0175a0:	8881fffc */ 	lwl	$at,-0x4($a0)
/*  f0175a4:	9881ffff */ 	lwr	$at,-0x1($a0)
/*  f0175a8:	24a5000c */ 	addiu	$a1,$a1,0xc
/*  f0175ac:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f0175b0:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f0175b4:	8498fff4 */ 	lh	$t8,-0xc($a0)
/*  f0175b8:	84b9fff4 */ 	lh	$t9,-0xc($a1)
/*  f0175bc:	03387823 */ 	subu	$t7,$t9,$t8
/*  f0175c0:	01f60019 */ 	multu	$t7,$s6
/*  f0175c4:	00001012 */ 	mflo	$v0
/*  f0175c8:	04410004 */ 	bgez	$v0,.L0f0175dc
/*  f0175cc:	00025c03 */ 	sra	$t3,$v0,0x10
/*  f0175d0:	3401ffff */ 	dli	$at,0xffff
/*  f0175d4:	00220821 */ 	addu	$at,$at,$v0
/*  f0175d8:	00015c03 */ 	sra	$t3,$at,0x10
.L0f0175dc:
/*  f0175dc:	000b6400 */ 	sll	$t4,$t3,0x10
/*  f0175e0:	000c6c03 */ 	sra	$t5,$t4,0x10
/*  f0175e4:	01cdc821 */ 	addu	$t9,$t6,$t5
/*  f0175e8:	a479fff4 */ 	sh	$t9,-0xc($v1)
/*  f0175ec:	848ffff6 */ 	lh	$t7,-0xa($a0)
/*  f0175f0:	84b8fff6 */ 	lh	$t8,-0xa($a1)
/*  f0175f4:	846efff6 */ 	lh	$t6,-0xa($v1)
/*  f0175f8:	030f5823 */ 	subu	$t3,$t8,$t7
/*  f0175fc:	01760019 */ 	multu	$t3,$s6
/*  f017600:	00001012 */ 	mflo	$v0
/*  f017604:	04410004 */ 	bgez	$v0,.L0f017618
/*  f017608:	00026403 */ 	sra	$t4,$v0,0x10
/*  f01760c:	3401ffff */ 	dli	$at,0xffff
/*  f017610:	00220821 */ 	addu	$at,$at,$v0
/*  f017614:	00016403 */ 	sra	$t4,$at,0x10
.L0f017618:
/*  f017618:	000c6c00 */ 	sll	$t5,$t4,0x10
/*  f01761c:	000dcc03 */ 	sra	$t9,$t5,0x10
/*  f017620:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f017624:	a478fff6 */ 	sh	$t8,-0xa($v1)
/*  f017628:	848bfff8 */ 	lh	$t3,-0x8($a0)
/*  f01762c:	84affff8 */ 	lh	$t7,-0x8($a1)
/*  f017630:	846efff8 */ 	lh	$t6,-0x8($v1)
/*  f017634:	01eb6023 */ 	subu	$t4,$t7,$t3
/*  f017638:	01960019 */ 	multu	$t4,$s6
/*  f01763c:	00001012 */ 	mflo	$v0
/*  f017640:	04410004 */ 	bgez	$v0,.L0f017654
/*  f017644:	00026c03 */ 	sra	$t5,$v0,0x10
/*  f017648:	3401ffff */ 	dli	$at,0xffff
/*  f01764c:	00220821 */ 	addu	$at,$at,$v0
/*  f017650:	00016c03 */ 	sra	$t5,$at,0x10
.L0f017654:
/*  f017654:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f017658:	a46ffff8 */ 	sh	$t7,-0x8($v1)
/*  f01765c:	86a60010 */ 	lh	$a2,0x10($s5)
/*  f017660:	0286082a */ 	slt	$at,$s4,$a2
/*  f017664:	5420ffc3 */ 	bnezl	$at,.L0f017574
/*  f017668:	88810000 */ 	lwl	$at,0x0($a0)
/*  f01766c:	0000a025 */ 	or	$s4,$zero,$zero
.L0f017670:
/*  f017670:	96a20016 */ 	lhu	$v0,0x16($s5)
/*  f017674:	3c0b0001 */ 	lui	$t3,0x1
/*  f017678:	01769823 */ 	subu	$s3,$t3,$s6
/*  f01767c:	18400065 */ 	blez	$v0,.L0f017814
/*  f017680:	01208825 */ 	or	$s1,$t1,$zero
/*  f017684:	01409025 */ 	or	$s2,$t2,$zero
/*  f017688:	8fb000fc */ 	lw	$s0,0xfc($sp)
/*  f01768c:	822c0000 */ 	lb	$t4,0x0($s1)
.L0f017690:
/*  f017690:	82590000 */ 	lb	$t9,0x0($s2)
/*  f017694:	03c02025 */ 	or	$a0,$s8,$zero
/*  f017698:	01930019 */ 	multu	$t4,$s3
/*  f01769c:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0176a0:	00006812 */ 	mflo	$t5
/*  f0176a4:	00000000 */ 	nop
/*  f0176a8:	00000000 */ 	nop
/*  f0176ac:	03360019 */ 	multu	$t9,$s6
/*  f0176b0:	00007012 */ 	mflo	$t6
/*  f0176b4:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f0176b8:	07010004 */ 	bgez	$t8,.L0f0176cc
/*  f0176bc:	00187c03 */ 	sra	$t7,$t8,0x10
/*  f0176c0:	3401ffff */ 	dli	$at,0xffff
/*  f0176c4:	00380821 */ 	addu	$at,$at,$t8
/*  f0176c8:	00017c03 */ 	sra	$t7,$at,0x10
.L0f0176cc:
/*  f0176cc:	afaf00cc */ 	sw	$t7,0xcc($sp)
/*  f0176d0:	822b0001 */ 	lb	$t3,0x1($s1)
/*  f0176d4:	82590001 */ 	lb	$t9,0x1($s2)
/*  f0176d8:	448f3000 */ 	mtc1	$t7,$f6
/*  f0176dc:	01730019 */ 	multu	$t3,$s3
/*  f0176e0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0176e4:	4608a032 */ 	c.eq.s	$f20,$f8
/*  f0176e8:	00006012 */ 	mflo	$t4
/*  f0176ec:	00000000 */ 	nop
/*  f0176f0:	00000000 */ 	nop
/*  f0176f4:	03360019 */ 	multu	$t9,$s6
/*  f0176f8:	00006812 */ 	mflo	$t5
/*  f0176fc:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f017700:	05c10004 */ 	bgez	$t6,.L0f017714
/*  f017704:	000ec403 */ 	sra	$t8,$t6,0x10
/*  f017708:	3401ffff */ 	dli	$at,0xffff
/*  f01770c:	002e0821 */ 	addu	$at,$at,$t6
/*  f017710:	0001c403 */ 	sra	$t8,$at,0x10
.L0f017714:
/*  f017714:	afb800d0 */ 	sw	$t8,0xd0($sp)
/*  f017718:	822b0002 */ 	lb	$t3,0x2($s1)
/*  f01771c:	824c0002 */ 	lb	$t4,0x2($s2)
/*  f017720:	44985000 */ 	mtc1	$t8,$f10
/*  f017724:	01730019 */ 	multu	$t3,$s3
/*  f017728:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f01772c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f017730:	e7b000c4 */ 	swc1	$f16,0xc4($sp)
/*  f017734:	0000c812 */ 	mflo	$t9
/*  f017738:	00000000 */ 	nop
/*  f01773c:	00000000 */ 	nop
/*  f017740:	01960019 */ 	multu	$t4,$s6
/*  f017744:	00006812 */ 	mflo	$t5
/*  f017748:	032d7021 */ 	addu	$t6,$t9,$t5
/*  f01774c:	05c10004 */ 	bgez	$t6,.L0f017760
/*  f017750:	000e5c03 */ 	sra	$t3,$t6,0x10
/*  f017754:	3401ffff */ 	dli	$at,0xffff
/*  f017758:	002e0821 */ 	addu	$at,$at,$t6
/*  f01775c:	00015c03 */ 	sra	$t3,$at,0x10
.L0f017760:
/*  f017760:	448b9000 */ 	mtc1	$t3,$f18
/*  f017764:	afab00d4 */ 	sw	$t3,0xd4($sp)
/*  f017768:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f01776c:	45000009 */ 	bc1f	.L0f017794
/*  f017770:	e7a400c8 */ 	swc1	$f4,0xc8($sp)
/*  f017774:	4610a032 */ 	c.eq.s	$f20,$f16
/*  f017778:	00000000 */ 	nop
/*  f01777c:	45000005 */ 	bc1f	.L0f017794
/*  f017780:	00000000 */ 	nop
/*  f017784:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f017788:	00000000 */ 	nop
/*  f01778c:	45030004 */ 	bc1tl	.L0f0177a0
/*  f017790:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
.L0f017794:
/*  f017794:	0c0011e4 */ 	jal	guNormalize
/*  f017798:	27a600c8 */ 	addiu	$a2,$sp,0xc8
/*  f01779c:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
.L0f0177a0:
/*  f0177a0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0177a4:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0177a8:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0177ac:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0177b0:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f0177b4:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0177b8:	44199000 */ 	mfc1	$t9,$f18
/*  f0177bc:	00000000 */ 	nop
/*  f0177c0:	a219fffc */ 	sb	$t9,-0x4($s0)
/*  f0177c4:	c7a800c4 */ 	lwc1	$f8,0xc4($sp)
/*  f0177c8:	46164402 */ 	mul.s	$f16,$f8,$f22
/*  f0177cc:	4600810d */ 	trunc.w.s	$f4,$f16
/*  f0177d0:	440e2000 */ 	mfc1	$t6,$f4
/*  f0177d4:	00000000 */ 	nop
/*  f0177d8:	a20efffd */ 	sb	$t6,-0x3($s0)
/*  f0177dc:	c7a600c8 */ 	lwc1	$f6,0xc8($sp)
/*  f0177e0:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0177e4:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0177e8:	44189000 */ 	mfc1	$t8,$f18
/*  f0177ec:	00000000 */ 	nop
/*  f0177f0:	a218fffe */ 	sb	$t8,-0x2($s0)
/*  f0177f4:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*  f0177f8:	a20bffff */ 	sb	$t3,-0x1($s0)
/*  f0177fc:	96a20016 */ 	lhu	$v0,0x16($s5)
/*  f017800:	0282082a */ 	slt	$at,$s4,$v0
/*  f017804:	5420ffa2 */ 	bnezl	$at,.L0f017690
/*  f017808:	822c0000 */ 	lb	$t4,0x0($s1)
/*  f01780c:	86a60010 */ 	lh	$a2,0x10($s5)
/*  f017810:	0000a025 */ 	or	$s4,$zero,$zero
.L0f017814:
/*  f017814:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f017818:	00066080 */ 	sll	$t4,$a2,0x2
/*  f01781c:	01866023 */ 	subu	$t4,$t4,$a2
/*  f017820:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f017824:	01996821 */ 	addu	$t5,$t4,$t9
/*  f017828:	8fac00fc */ 	lw	$t4,0xfc($sp)
/*  f01782c:	25ae0007 */ 	addiu	$t6,$t5,0x7
/*  f017830:	00025880 */ 	sll	$t3,$v0,0x2
/*  f017834:	35cf0007 */ 	ori	$t7,$t6,0x7
/*  f017838:	016cc821 */ 	addu	$t9,$t3,$t4
/*  f01783c:	272d0007 */ 	addiu	$t5,$t9,0x7
/*  f017840:	39f80007 */ 	xori	$t8,$t7,0x7
/*  f017844:	35ae0007 */ 	ori	$t6,$t5,0x7
/*  f017848:	39cf0007 */ 	xori	$t7,$t6,0x7
/*  f01784c:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f017850:	afaf00fc */ 	sw	$t7,0xfc($sp)
.L0f017854:
/*  f017854:	8fb80108 */ 	lw	$t8,0x108($sp)
.L0f017858:
/*  f017858:	270b0001 */ 	addiu	$t3,$t8,0x1
/*  f01785c:	29610004 */ 	slti	$at,$t3,0x4
/*  f017860:	1420feec */ 	bnez	$at,.L0f017414
/*  f017864:	afab0108 */ 	sw	$t3,0x108($sp)
/*  f017868:	8fa20150 */ 	lw	$v0,0x150($sp)
/*  f01786c:	8fb00168 */ 	lw	$s0,0x168($sp)
/*  f017870:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f017874:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f017878:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f01787c:	24430008 */ 	addiu	$v1,$v0,0x8
/*  f017880:	332d00ff */ 	andi	$t5,$t9,0xff
/*  f017884:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f017888:	afb00110 */ 	sw	$s0,0x110($sp)
/*  f01788c:	8eee0008 */ 	lw	$t6,0x8($s7)
/*  f017890:	85c4000e */ 	lh	$a0,0xe($t6)
/*  f017894:	afa30150 */ 	sw	$v1,0x150($sp)
/*  f017898:	00047980 */ 	sll	$t7,$a0,0x6
/*  f01789c:	0fc59e7d */ 	jal	gfxAllocate
/*  f0178a0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0178a4:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0178a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0178ac:	0c005746 */ 	jal	mtx4Copy
/*  f0178b0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0178b4:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f0178b8:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0178bc:	0c007308 */ 	jal	model0001cc20
/*  f0178c0:	aef8000c */ 	sw	$t8,0xc($s7)
/*  f0178c4:	8fac0150 */ 	lw	$t4,0x150($sp)
/*  f0178c8:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f0178cc:	afab0118 */ 	sw	$t3,0x118($sp)
/*  f0178d0:	afa00114 */ 	sw	$zero,0x114($sp)
/*  f0178d4:	27a40110 */ 	addiu	$a0,$sp,0x110
/*  f0178d8:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0178dc:	0c0087bd */ 	jal	modelRender
/*  f0178e0:	afac011c */ 	sw	$t4,0x11c($sp)
/*  f0178e4:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0178e8:	00008025 */ 	or	$s0,$zero,$zero
/*  f0178ec:	27b1006c */ 	addiu	$s1,$sp,0x6c
/*  f0178f0:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f0178f4:	8eed0008 */ 	lw	$t5,0x8($s7)
/*  f0178f8:	85ae000e */ 	lh	$t6,0xe($t5)
/*  f0178fc:	59c00012 */ 	blezl	$t6,.L0f017948
/*  f017900:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f017904:	8eef000c */ 	lw	$t7,0xc($s7)
.L0f017908:
/*  f017908:	02202825 */ 	or	$a1,$s1,$zero
/*  f01790c:	0c005746 */ 	jal	mtx4Copy
/*  f017910:	01f02021 */ 	addu	$a0,$t7,$s0
/*  f017914:	8ef8000c */ 	lw	$t8,0xc($s7)
/*  f017918:	00145980 */ 	sll	$t3,$s4,0x6
/*  f01791c:	02202025 */ 	or	$a0,$s1,$zero
/*  f017920:	0c005815 */ 	jal	mtx00016054
/*  f017924:	030b2821 */ 	addu	$a1,$t8,$t3
/*  f017928:	8eec0008 */ 	lw	$t4,0x8($s7)
/*  f01792c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f017930:	26100040 */ 	addiu	$s0,$s0,0x40
/*  f017934:	8599000e */ 	lh	$t9,0xe($t4)
/*  f017938:	0299082a */ 	slt	$at,$s4,$t9
/*  f01793c:	5420fff2 */ 	bnezl	$at,.L0f017908
/*  f017940:	8eef000c */ 	lw	$t7,0xc($s7)
/*  f017944:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f017948:
/*  f017948:	8fa20150 */ 	lw	$v0,0x150($sp)
/*  f01794c:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f017950:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f017954:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f017958:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f01795c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f017960:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f017964:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f017968:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f01796c:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f017970:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f017974:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f017978:	03e00008 */ 	jr	$ra
/*  f01797c:	27bd0150 */ 	addiu	$sp,$sp,0x150
);

/**
 * Skip immediately to the "PERFECT DARK" part of the PdLogo mode.
 *
 * Assumes the title mode is already PdLogo, but at an earlier point.
 */
void titleSkipToPdTitle(void)
{
	g_PdLogoYRotCur = 0;
	g_PdLogoYRotSpeed = 0;
	g_PdLogoXRotCur = 0;
	g_PdLogoXRotSpeed = 0;
	g_PdLogoScale = 0.35f;
	g_PdLogoFrac = 1;
	g_PdLogoTitleStepFrac = 0.63f;
	g_PdLogoUnusedRot = 1.6443619728088f;
	g_PdLogoLightDirFrac = 0.19975f;
	g_PdLogoEndYRot = 0;
	g_PdLogoAmbientLightFrac = 0;

	g_PdLogoUseCombinedModel = true;
	g_PdLogoBlackTimer = 0;
	g_PdLogoYRotEnabled = false;
	g_PdLogoPreMorphTimer = 0;
	g_PdLogoMorphing = false;
	g_PdLogoExitTimer = 0;
	g_PdLogoMorphEndTimer = 0;
	g_PdLogoYRotStopping = false;
	g_PdLogoDarkenEnabled = false;
	g_PdLogoPointlessTimerEnabled = false;
	g_PdLogoPreTitleTimer = 0;
	g_PdLogoTitleStep = 1;
	g_PdLogoTitlePresenting = true;
	g_PdLogoPointlessTimer = 0;
	var80062804 = 1;
	g_PdLogoUnusedRotEnabled = true;
	g_PdLogoLightMoving = true;
	g_TitleTimer = TICKS(549);
	g_PdLogoIsFirstTick = false;

	musicStartTemporaryPrimary(MUSIC_TITLE2);
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel titleRenderPdLogo
.late_rodata
glabel var7f1a8400
.word 0x456a6000
glabel var7f1a8404
.word 0x3dcccccd
glabel var7f1a8408
.word 0x4087b1f9
glabel var7f1a840c
.word 0x3cb944e9
glabel var7f1a8410
.word 0x3ef13c64
glabel var7f1a8414
.word 0x3eb33333
glabel var7f1a8418
.word 0x3fc907a9
glabel var7f1a841c
.word 0x396d2501
glabel var7f1a8420
.word 0x3cb944e9
glabel var7f1a8424
.word 0x40c907a9
glabel var7f1a8428
.word 0x40c907a9
glabel var7f1a842c
.word 0x40c907a9
glabel var7f1a8430
.word 0x40c907a9
glabel var7f1a8434
.word 0x3b83126f
glabel var7f1a8438
.word 0x3f4ccccd
glabel var7f1a843c
.word 0x390e4967
glabel var7f1a8440
.word 0x3c5e52b2
glabel var7f1a8444
.word 0x40c907a9
glabel var7f1a8448
.word 0x3bf5c28f
glabel var7f1a844c
.word 0x3ccccccd
glabel var7f1a8450
.word 0x3db851ec
glabel var7f1a8454
.word 0x3dcccccd
glabel var7f1a8458
.word 0x3bcddaca
glabel var7f1a845c
.word 0x3c8b4396
glabel var7f1a8460
.word 0x40490fdb
glabel var7f1a8464
.word 0x3e19999a
glabel var7f1a8468
.word 0x3e9db22d
.text
/*  f017b9c:	27bdfcd0 */ 	addiu	$sp,$sp,-816
/*  f017ba0:	3c0f8006 */ 	lui	$t7,0x8006
/*  f017ba4:	3c028006 */ 	lui	$v0,0x8006
/*  f017ba8:	25ef24e8 */ 	addiu	$t7,$t7,0x24e8
/*  f017bac:	24422400 */ 	addiu	$v0,$v0,0x2400
/*  f017bb0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f017bb4:	afa40330 */ 	sw	$a0,0x330($sp)
/*  f017bb8:	25f9003c */ 	addiu	$t9,$t7,0x3c
/*  f017bbc:	27ae02f0 */ 	addiu	$t6,$sp,0x2f0
.PF0f017bc0:
/*  f017bc0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f017bc4:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f017bc8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f017bcc:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f017bd0:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f017bd4:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f017bd8:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f017bdc:	15f9fff8 */ 	bne	$t7,$t9,.PF0f017bc0
/*  f017be0:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f017be4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f017be8:	3c188006 */ 	lui	$t8,0x8006
/*  f017bec:	3c048006 */ 	lui	$a0,0x8006
/*  f017bf0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f017bf4:	8f182194 */ 	lw	$t8,0x2194($t8)
/*  f017bf8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017bfc:	c4289610 */ 	lwc1	$f8,-0x69f0($at)
/*  f017c00:	44982000 */ 	mtc1	$t8,$f4
/*  f017c04:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017c08:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f017c0c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f017c10:	c4249614 */ 	lwc1	$f4,-0x69ec($at)
/*  f017c14:	3c098006 */ 	lui	$t1,0x8006
/*  f017c18:	3c0a8006 */ 	lui	$t2,0x8006
/*  f017c1c:	3c0c8006 */ 	lui	$t4,0x8006
/*  f017c20:	3c0d8006 */ 	lui	$t5,0x8006
/*  f017c24:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f017c28:	3c0b8006 */ 	lui	$t3,0x8006
/*  f017c2c:	25ad24d0 */ 	addiu	$t5,$t5,0x24d0
/*  f017c30:	258c24c0 */ 	addiu	$t4,$t4,0x24c0
/*  f017c34:	254a24b0 */ 	addiu	$t2,$t2,0x24b0
/*  f017c38:	252924a4 */ 	addiu	$t1,$t1,0x24a4
/*  f017c3c:	3c013f80 */ 	lui	$at,0x3f80
/*  f017c40:	2484249c */ 	addiu	$a0,$a0,0x249c
/*  f017c44:	24030001 */ 	li	$v1,0x1
/*  f017c48:	256b2494 */ 	addiu	$t3,$t3,0x2494
/*  f017c4c:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f017c50:	13200041 */ 	beqz	$t9,.PF0f017d58
/*  f017c54:	e7a6013c */ 	swc1	$f6,0x13c($sp)
/*  f017c58:	44817000 */ 	mtc1	$at,$f14
/*  f017c5c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017c60:	c4289618 */ 	lwc1	$f8,-0x69e8($at)
/*  f017c64:	3c018006 */ 	lui	$at,0x8006
/*  f017c68:	44809000 */ 	mtc1	$zero,$f18
/*  f017c6c:	e4282478 */ 	swc1	$f8,0x2478($at)
/*  f017c70:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017c74:	c42a961c */ 	lwc1	$f10,-0x69e4($at)
/*  f017c78:	3c018006 */ 	lui	$at,0x8006
/*  f017c7c:	3c1f8006 */ 	lui	$ra,0x8006
/*  f017c80:	e42a247c */ 	swc1	$f10,0x247c($at)
/*  f017c84:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017c88:	c4249620 */ 	lwc1	$f4,-0x69e0($at)
/*  f017c8c:	3c018006 */ 	lui	$at,0x8006
/*  f017c90:	27ff24a8 */ 	addiu	$ra,$ra,0x24a8
/*  f017c94:	e4242480 */ 	swc1	$f4,0x2480($at)
/*  f017c98:	3c018006 */ 	lui	$at,0x8006
/*  f017c9c:	e4322484 */ 	swc1	$f18,0x2484($at)
/*  f017ca0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017ca4:	c4269624 */ 	lwc1	$f6,-0x69dc($at)
/*  f017ca8:	3c018006 */ 	lui	$at,0x8006
/*  f017cac:	240fffff */ 	li	$t7,-1
/*  f017cb0:	e4262488 */ 	swc1	$f6,0x2488($at)
/*  f017cb4:	3c018006 */ 	lui	$at,0x8006
/*  f017cb8:	e432248c */ 	swc1	$f18,0x248c($at)
/*  f017cbc:	3c018006 */ 	lui	$at,0x8006
/*  f017cc0:	ac202490 */ 	sw	$zero,0x2490($at)
/*  f017cc4:	3c018006 */ 	lui	$at,0x8006
/*  f017cc8:	e42e2498 */ 	swc1	$f14,0x2498($at)
/*  f017ccc:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f017cd0:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f017cd4:	3c018006 */ 	lui	$at,0x8006
/*  f017cd8:	ac2024a0 */ 	sw	$zero,0x24a0($at)
/*  f017cdc:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f017ce0:	afe00000 */ 	sw	$zero,0x0($ra)
/*  f017ce4:	3c018006 */ 	lui	$at,0x8006
/*  f017ce8:	ac2024ac */ 	sw	$zero,0x24ac($at)
/*  f017cec:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f017cf0:	3c018006 */ 	lui	$at,0x8006
/*  f017cf4:	ac2024b4 */ 	sw	$zero,0x24b4($at)
/*  f017cf8:	3c018006 */ 	lui	$at,0x8006
/*  f017cfc:	ac2024b8 */ 	sw	$zero,0x24b8($at)
/*  f017d00:	3c018006 */ 	lui	$at,0x8006
/*  f017d04:	ac2324d4 */ 	sw	$v1,0x24d4($at)
/*  f017d08:	3c018006 */ 	lui	$at,0x8006
/*  f017d0c:	ac2024bc */ 	sw	$zero,0x24bc($at)
/*  f017d10:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f017d14:	3c018006 */ 	lui	$at,0x8006
/*  f017d18:	e43224c4 */ 	swc1	$f18,0x24c4($at)
/*  f017d1c:	3c018006 */ 	lui	$at,0x8006
/*  f017d20:	ac2024cc */ 	sw	$zero,0x24cc($at)
/*  f017d24:	3c018006 */ 	lui	$at,0x8006
/*  f017d28:	ac2f24c8 */ 	sw	$t7,0x24c8($at)
/*  f017d2c:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f017d30:	3c018006 */ 	lui	$at,0x8006
/*  f017d34:	ac2024dc */ 	sw	$zero,0x24dc($at)
/*  f017d38:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017d3c:	c4289628 */ 	lwc1	$f8,-0x69d8($at)
/*  f017d40:	3c018006 */ 	lui	$at,0x8006
/*  f017d44:	e42824d8 */ 	swc1	$f8,0x24d8($at)
/*  f017d48:	3c018006 */ 	lui	$at,0x8006
/*  f017d4c:	ac2024e0 */ 	sw	$zero,0x24e0($at)
/*  f017d50:	3c018006 */ 	lui	$at,0x8006
/*  f017d54:	e43224e4 */ 	swc1	$f18,0x24e4($at)
.PF0f017d58:
/*  f017d58:	3c048006 */ 	lui	$a0,0x8006
/*  f017d5c:	2484249c */ 	addiu	$a0,$a0,0x249c
/*  f017d60:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f017d64:	3c013f80 */ 	lui	$at,0x3f80
/*  f017d68:	44817000 */ 	mtc1	$at,$f14
/*  f017d6c:	3c098006 */ 	lui	$t1,0x8006
/*  f017d70:	3c0a8006 */ 	lui	$t2,0x8006
/*  f017d74:	3c0c8006 */ 	lui	$t4,0x8006
/*  f017d78:	3c0d8006 */ 	lui	$t5,0x8006
/*  f017d7c:	3c1f8006 */ 	lui	$ra,0x8006
/*  f017d80:	44809000 */ 	mtc1	$zero,$f18
/*  f017d84:	27ff24a8 */ 	addiu	$ra,$ra,0x24a8
/*  f017d88:	25ad24d0 */ 	addiu	$t5,$t5,0x24d0
/*  f017d8c:	258c24c0 */ 	addiu	$t4,$t4,0x24c0
/*  f017d90:	254a24b0 */ 	addiu	$t2,$t2,0x24b0
/*  f017d94:	252924a4 */ 	addiu	$t1,$t1,0x24a4
/*  f017d98:	10400009 */ 	beqz	$v0,.PF0f017dc0
/*  f017d9c:	24030001 */ 	li	$v1,0x1
/*  f017da0:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f017da4:	29c10004 */ 	slti	$at,$t6,0x4
/*  f017da8:	14200005 */ 	bnez	$at,.PF0f017dc0
/*  f017dac:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f017db0:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f017db4:	3c018006 */ 	lui	$at,0x8006
/*  f017db8:	ac2324a0 */ 	sw	$v1,0x24a0($at)
/*  f017dbc:	ad230000 */ 	sw	$v1,0x0($t1)
.PF0f017dc0:
/*  f017dc0:	3c198006 */ 	lui	$t9,0x8006
/*  f017dc4:	8f3924b4 */ 	lw	$t9,0x24b4($t9)
/*  f017dc8:	3c018006 */ 	lui	$at,0x8006
/*  f017dcc:	13200049 */ 	beqz	$t9,.PF0f017ef4
/*  f017dd0:	00000000 */ 	nop
/*  f017dd4:	c4202478 */ 	lwc1	$f0,0x2478($at)
/*  f017dd8:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017ddc:	3c048006 */ 	lui	$a0,0x8006
/*  f017de0:	3c068006 */ 	lui	$a2,0x8006
/*  f017de4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f017de8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017dec:	24c6247c */ 	addiu	$a2,$a2,0x247c
/*  f017df0:	24842478 */ 	addiu	$a0,$a0,0x2478
/*  f017df4:	45020038 */ 	bc1fl	.PF0f017ed8
/*  f017df8:	4600103e */ 	c.le.s	$f2,$f0
/*  f017dfc:	c420962c */ 	lwc1	$f0,-0x69d4($at)
/*  f017e00:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017e04:	c42a9630 */ 	lwc1	$f10,-0x69d0($at)
/*  f017e08:	44051000 */ 	mfc1	$a1,$f2
/*  f017e0c:	44070000 */ 	mfc1	$a3,$f0
/*  f017e10:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f017e14:	0fc1b6e5 */ 	jal	applySpeed
/*  f017e18:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f017e1c:	3c028006 */ 	lui	$v0,0x8006
/*  f017e20:	3c0b8006 */ 	lui	$t3,0x8006
/*  f017e24:	256b2494 */ 	addiu	$t3,$t3,0x2494
/*  f017e28:	24422478 */ 	addiu	$v0,$v0,0x2478
/*  f017e2c:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017e30:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017e34:	3c098006 */ 	lui	$t1,0x8006
/*  f017e38:	3c0a8006 */ 	lui	$t2,0x8006
/*  f017e3c:	4600103e */ 	c.le.s	$f2,$f0
/*  f017e40:	3c0c8006 */ 	lui	$t4,0x8006
/*  f017e44:	3c0d8006 */ 	lui	$t5,0x8006
/*  f017e48:	3c1f8006 */ 	lui	$ra,0x8006
/*  f017e4c:	44809000 */ 	mtc1	$zero,$f18
/*  f017e50:	27ff24a8 */ 	addiu	$ra,$ra,0x24a8
/*  f017e54:	25ad24d0 */ 	addiu	$t5,$t5,0x24d0
/*  f017e58:	258c24c0 */ 	addiu	$t4,$t4,0x24c0
/*  f017e5c:	254a24b0 */ 	addiu	$t2,$t2,0x24b0
/*  f017e60:	45000005 */ 	bc1f	.PF0f017e78
/*  f017e64:	252924a4 */ 	addiu	$t1,$t1,0x24a4
/*  f017e68:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f017e6c:	3c018006 */ 	lui	$at,0x8006
/*  f017e70:	e432247c */ 	swc1	$f18,0x247c($at)
/*  f017e74:	c4400000 */ 	lwc1	$f0,0x0($v0)
.PF0f017e78:
/*  f017e78:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017e7c:	c42c9634 */ 	lwc1	$f12,-0x69cc($at)
/*  f017e80:	4600603e */ 	c.le.s	$f12,$f0
/*  f017e84:	00000000 */ 	nop
/*  f017e88:	45020009 */ 	bc1fl	.PF0f017eb0
/*  f017e8c:	4612003c */ 	c.lt.s	$f0,$f18
/*  f017e90:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f017e94:	460c1181 */ 	sub.s	$f6,$f2,$f12
/*  f017e98:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f017e9c:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017ea0:	e5660000 */ 	swc1	$f6,0x0($t3)
/*  f017ea4:	1000000b */ 	b	.PF0f017ed4
/*  f017ea8:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017eac:	4612003c */ 	c.lt.s	$f0,$f18
.PF0f017eb0:
/*  f017eb0:	00000000 */ 	nop
/*  f017eb4:	45020008 */ 	bc1fl	.PF0f017ed8
/*  f017eb8:	4600103e */ 	c.le.s	$f2,$f0
/*  f017ebc:	460c0200 */ 	add.s	$f8,$f0,$f12
/*  f017ec0:	460c1280 */ 	add.s	$f10,$f2,$f12
/*  f017ec4:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f017ec8:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017ecc:	e56a0000 */ 	swc1	$f10,0x0($t3)
/*  f017ed0:	c5620000 */ 	lwc1	$f2,0x0($t3)
.PF0f017ed4:
/*  f017ed4:	4600103e */ 	c.le.s	$f2,$f0
.PF0f017ed8:
/*  f017ed8:	3c013f80 */ 	lui	$at,0x3f80
/*  f017edc:	44817000 */ 	mtc1	$at,$f14
/*  f017ee0:	24030001 */ 	li	$v1,0x1
/*  f017ee4:	45000023 */ 	bc1f	.PF0f017f74
/*  f017ee8:	3c018006 */ 	lui	$at,0x8006
/*  f017eec:	10000021 */ 	b	.PF0f017f74
/*  f017ef0:	ac2024b4 */ 	sw	$zero,0x24b4($at)
.PF0f017ef4:
/*  f017ef4:	3c0f8006 */ 	lui	$t7,0x8006
/*  f017ef8:	8def24a0 */ 	lw	$t7,0x24a0($t7)
/*  f017efc:	11e0001d */ 	beqz	$t7,.PF0f017f74
/*  f017f00:	3c08800a */ 	lui	$t0,0x800a
/*  f017f04:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f017f08:	8d0e0038 */ 	lw	$t6,0x38($t0)
/*  f017f0c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017f10:	c42c963c */ 	lwc1	$f12,-0x69c4($at)
/*  f017f14:	448e3000 */ 	mtc1	$t6,$f6
/*  f017f18:	3c018006 */ 	lui	$at,0x8006
/*  f017f1c:	c424247c */ 	lwc1	$f4,0x247c($at)
/*  f017f20:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f017f24:	3c028006 */ 	lui	$v0,0x8006
/*  f017f28:	24422478 */ 	addiu	$v0,$v0,0x2478
/*  f017f2c:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f017f30:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f017f34:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f017f38:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f017f3c:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017f40:	4600603e */ 	c.le.s	$f12,$f0
/*  f017f44:	00000000 */ 	nop
/*  f017f48:	45020005 */ 	bc1fl	.PF0f017f60
/*  f017f4c:	4612003c */ 	c.lt.s	$f0,$f18
/*  f017f50:	460c0201 */ 	sub.s	$f8,$f0,$f12
/*  f017f54:	10000007 */ 	b	.PF0f017f74
/*  f017f58:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f017f5c:	4612003c */ 	c.lt.s	$f0,$f18
.PF0f017f60:
/*  f017f60:	00000000 */ 	nop
/*  f017f64:	45020004 */ 	bc1fl	.PF0f017f78
/*  f017f68:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f017f6c:	460c0180 */ 	add.s	$f6,$f0,$f12
/*  f017f70:	e4460000 */ 	swc1	$f6,0x0($v0)
.PF0f017f74:
/*  f017f74:	8d220000 */ 	lw	$v0,0x0($t1)
.PF0f017f78:
/*  f017f78:	3c08800a */ 	lui	$t0,0x800a
/*  f017f7c:	3c0b8006 */ 	lui	$t3,0x8006
/*  f017f80:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017f84:	c42c9640 */ 	lwc1	$f12,-0x69c0($at)
/*  f017f88:	256b2494 */ 	addiu	$t3,$t3,0x2494
/*  f017f8c:	1040001a */ 	beqz	$v0,.PF0f017ff8
/*  f017f90:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f017f94:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f017f98:	240f0042 */ 	li	$t7,0x42
/*  f017f9c:	3c018006 */ 	lui	$at,0x8006
/*  f017fa0:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f017fa4:	ad390000 */ 	sw	$t9,0x0($t1)
/*  f017fa8:	1b200009 */ 	blez	$t9,.PF0f017fd0
/*  f017fac:	03201025 */ 	move	$v0,$t9
/*  f017fb0:	44825000 */ 	mtc1	$v0,$f10
/*  f017fb4:	448f4000 */ 	mtc1	$t7,$f8
/*  f017fb8:	3c018006 */ 	lui	$at,0x8006
/*  f017fbc:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f017fc0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f017fc4:	46062283 */ 	div.s	$f10,$f4,$f6
/*  f017fc8:	10000002 */ 	b	.PF0f017fd4
/*  f017fcc:	e42a248c */ 	swc1	$f10,0x248c($at)
.PF0f017fd0:
/*  f017fd0:	e432248c */ 	swc1	$f18,0x248c($at)
.PF0f017fd4:
/*  f017fd4:	28410043 */ 	slti	$at,$v0,0x43
/*  f017fd8:	54200008 */ 	bnezl	$at,.PF0f017ffc
/*  f017fdc:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f017fe0:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f017fe4:	afe30000 */ 	sw	$v1,0x0($ra)
/*  f017fe8:	3c018006 */ 	lui	$at,0x8006
/*  f017fec:	e432248c */ 	swc1	$f18,0x248c($at)
/*  f017ff0:	3c018006 */ 	lui	$at,0x8006
/*  f017ff4:	ac232490 */ 	sw	$v1,0x2490($at)
.PF0f017ff8:
/*  f017ff8:	8fee0000 */ 	lw	$t6,0x0($ra)
.PF0f017ffc:
/*  f017ffc:	11c00019 */ 	beqz	$t6,.PF0f018064
/*  f018000:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018004:	c4289644 */ 	lwc1	$f8,-0x69bc($at)
/*  f018008:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f01800c:	3c018006 */ 	lui	$at,0x8006
/*  f018010:	c42a248c */ 	lwc1	$f10,0x248c($at)
/*  f018014:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f018018:	46065000 */ 	add.s	$f0,$f10,$f6
/*  f01801c:	e420248c */ 	swc1	$f0,0x248c($at)
/*  f018020:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018024:	c4249648 */ 	lwc1	$f4,-0x69b8($at)
/*  f018028:	3c018006 */ 	lui	$at,0x8006
/*  f01802c:	4600203e */ 	c.le.s	$f4,$f0
/*  f018030:	00000000 */ 	nop
/*  f018034:	45020006 */ 	bc1fl	.PF0f018050
/*  f018038:	4600703e */ 	c.le.s	$f14,$f0
/*  f01803c:	8d580000 */ 	lw	$t8,0x0($t2)
/*  f018040:	57000003 */ 	bnezl	$t8,.PF0f018050
/*  f018044:	4600703e */ 	c.le.s	$f14,$f0
/*  f018048:	ad430000 */ 	sw	$v1,0x0($t2)
/*  f01804c:	4600703e */ 	c.le.s	$f14,$f0
.PF0f018050:
/*  f018050:	00000000 */ 	nop
/*  f018054:	45020004 */ 	bc1fl	.PF0f018068
/*  f018058:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f01805c:	e42e248c */ 	swc1	$f14,0x248c($at)
/*  f018060:	afe00000 */ 	sw	$zero,0x0($ra)
.PF0f018064:
/*  f018064:	8d430000 */ 	lw	$v1,0x0($t2)
.PF0f018068:
/*  f018068:	10600064 */ 	beqz	$v1,.PF0f0181fc
/*  f01806c:	00000000 */ 	nop
/*  f018070:	8d190038 */ 	lw	$t9,0x38($t0)
/*  f018074:	3c018006 */ 	lui	$at,0x8006
/*  f018078:	3c048006 */ 	lui	$a0,0x8006
/*  f01807c:	00797821 */ 	addu	$t7,$v1,$t9
/*  f018080:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*  f018084:	c42a2480 */ 	lwc1	$f10,0x2480($at)
/*  f018088:	3c068006 */ 	lui	$a2,0x8006
/*  f01808c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018090:	460a903c */ 	c.lt.s	$f18,$f10
/*  f018094:	24c62484 */ 	addiu	$a2,$a2,0x2484
/*  f018098:	24842480 */ 	addiu	$a0,$a0,0x2480
/*  f01809c:	4502001f */ 	bc1fl	.PF0f01811c
/*  f0180a0:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f0180a4:	c420964c */ 	lwc1	$f0,-0x69b4($at)
/*  f0180a8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0180ac:	c4269650 */ 	lwc1	$f6,-0x69b0($at)
/*  f0180b0:	44059000 */ 	mfc1	$a1,$f18
/*  f0180b4:	44070000 */ 	mfc1	$a3,$f0
/*  f0180b8:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f0180bc:	0fc1b762 */ 	jal	applyRotation
/*  f0180c0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0180c4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0180c8:	c42c9654 */ 	lwc1	$f12,-0x69ac($at)
/*  f0180cc:	3c018006 */ 	lui	$at,0x8006
/*  f0180d0:	44809000 */ 	mtc1	$zero,$f18
/*  f0180d4:	c4282480 */ 	lwc1	$f8,0x2480($at)
/*  f0180d8:	3c08800a */ 	lui	$t0,0x800a
/*  f0180dc:	3c0a8006 */ 	lui	$t2,0x8006
/*  f0180e0:	4612403e */ 	c.le.s	$f8,$f18
/*  f0180e4:	3c0b8006 */ 	lui	$t3,0x8006
/*  f0180e8:	3c0c8006 */ 	lui	$t4,0x8006
/*  f0180ec:	3c0d8006 */ 	lui	$t5,0x8006
/*  f0180f0:	25ad24d0 */ 	addiu	$t5,$t5,0x24d0
/*  f0180f4:	258c24c0 */ 	addiu	$t4,$t4,0x24c0
/*  f0180f8:	256b2494 */ 	addiu	$t3,$t3,0x2494
/*  f0180fc:	254a24b0 */ 	addiu	$t2,$t2,0x24b0
/*  f018100:	45000005 */ 	bc1f	.PF0f018118
/*  f018104:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f018108:	3c018006 */ 	lui	$at,0x8006
/*  f01810c:	e4322480 */ 	swc1	$f18,0x2480($at)
/*  f018110:	3c018006 */ 	lui	$at,0x8006
/*  f018114:	e4322484 */ 	swc1	$f18,0x2484($at)
.PF0f018118:
/*  f018118:	8d430000 */ 	lw	$v1,0x0($t2)
.PF0f01811c:
/*  f01811c:	3c013f80 */ 	lui	$at,0x3f80
/*  f018120:	44817000 */ 	mtc1	$at,$f14
/*  f018124:	2861001a */ 	slti	$at,$v1,0x1a
/*  f018128:	1420001c */ 	bnez	$at,.PF0f01819c
/*  f01812c:	00000000 */ 	nop
/*  f018130:	8d0e0038 */ 	lw	$t6,0x38($t0)
/*  f018134:	24040001 */ 	li	$a0,0x1
/*  f018138:	006ec023 */ 	subu	$t8,$v1,$t6
/*  f01813c:	2b01001a */ 	slti	$at,$t8,0x1a
/*  f018140:	10200016 */ 	beqz	$at,.PF0f01819c
/*  f018144:	3c018006 */ 	lui	$at,0x8006
/*  f018148:	ac2024a0 */ 	sw	$zero,0x24a0($at)
/*  f01814c:	3c018006 */ 	lui	$at,0x8006
/*  f018150:	ac2424b4 */ 	sw	$a0,0x24b4($at)
/*  f018154:	3c018006 */ 	lui	$at,0x8006
/*  f018158:	c4242478 */ 	lwc1	$f4,0x2478($at)
/*  f01815c:	3c014080 */ 	lui	$at,0x4080
/*  f018160:	44815000 */ 	mtc1	$at,$f10
/*  f018164:	3c013e80 */ 	lui	$at,0x3e80
/*  f018168:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f01816c:	460c3203 */ 	div.s	$f8,$f6,$f12
/*  f018170:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f018174:	44022000 */ 	mfc1	$v0,$f4
/*  f018178:	44812000 */ 	mtc1	$at,$f4
/*  f01817c:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f018180:	44825000 */ 	mtc1	$v0,$f10
/*  f018184:	00000000 */ 	nop
/*  f018188:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f01818c:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f018190:	00000000 */ 	nop
/*  f018194:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f018198:	e56a0000 */ 	swc1	$f10,0x0($t3)
.PF0f01819c:
/*  f01819c:	3c028006 */ 	lui	$v0,0x8006
/*  f0181a0:	28610054 */ 	slti	$at,$v1,0x54
/*  f0181a4:	24040001 */ 	li	$a0,0x1
/*  f0181a8:	14200009 */ 	bnez	$at,.PF0f0181d0
/*  f0181ac:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f0181b0:	8d0f0038 */ 	lw	$t7,0x38($t0)
/*  f0181b4:	3c058006 */ 	lui	$a1,0x8006
/*  f0181b8:	24a524b8 */ 	addiu	$a1,$a1,0x24b8
/*  f0181bc:	006f7023 */ 	subu	$t6,$v1,$t7
/*  f0181c0:	29c10054 */ 	slti	$at,$t6,0x54
/*  f0181c4:	10200002 */ 	beqz	$at,.PF0f0181d0
/*  f0181c8:	00000000 */ 	nop
/*  f0181cc:	aca40000 */ 	sw	$a0,0x0($a1)
.PF0f0181d0:
/*  f0181d0:	3c058006 */ 	lui	$a1,0x8006
/*  f0181d4:	14400009 */ 	bnez	$v0,.PF0f0181fc
/*  f0181d8:	24a524b8 */ 	addiu	$a1,$a1,0x24b8
/*  f0181dc:	3c018006 */ 	lui	$at,0x8006
/*  f0181e0:	c4262480 */ 	lwc1	$f6,0x2480($at)
/*  f0181e4:	4612303e */ 	c.le.s	$f6,$f18
/*  f0181e8:	00000000 */ 	nop
/*  f0181ec:	45000003 */ 	bc1f	.PF0f0181fc
/*  f0181f0:	00000000 */ 	nop
/*  f0181f4:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f0181f8:	aca40000 */ 	sw	$a0,0x0($a1)
.PF0f0181fc:
/*  f0181fc:	3c058006 */ 	lui	$a1,0x8006
/*  f018200:	24a524b8 */ 	addiu	$a1,$a1,0x24b8
/*  f018204:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f018208:	24040001 */ 	li	$a0,0x1
/*  f01820c:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018210:	13000012 */ 	beqz	$t8,.PF0f01825c
/*  f018214:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018218:	c4289658 */ 	lwc1	$f8,-0x69a8($at)
/*  f01821c:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f018220:	3c038006 */ 	lui	$v1,0x8006
/*  f018224:	24632498 */ 	addiu	$v1,$v1,0x2498
/*  f018228:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f01822c:	c4660000 */ 	lwc1	$f6,0x0($v1)
/*  f018230:	3c018006 */ 	lui	$at,0x8006
/*  f018234:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f018238:	e4282498 */ 	swc1	$f8,0x2498($at)
/*  f01823c:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f018240:	4612203e */ 	c.le.s	$f4,$f18
/*  f018244:	00000000 */ 	nop
/*  f018248:	45020005 */ 	bc1fl	.PF0f018260
/*  f01824c:	8d820000 */ 	lw	$v0,0x0($t4)
/*  f018250:	e4720000 */ 	swc1	$f18,0x0($v1)
/*  f018254:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f018258:	ad840000 */ 	sw	$a0,0x0($t4)
.PF0f01825c:
/*  f01825c:	8d820000 */ 	lw	$v0,0x0($t4)
.PF0f018260:
/*  f018260:	3c188006 */ 	lui	$t8,0x8006
/*  f018264:	10400009 */ 	beqz	$v0,.PF0f01828c
/*  f018268:	00000000 */ 	nop
/*  f01826c:	8d190038 */ 	lw	$t9,0x38($t0)
/*  f018270:	00597821 */ 	addu	$t7,$v0,$t9
/*  f018274:	29e10011 */ 	slti	$at,$t7,0x11
/*  f018278:	14200004 */ 	bnez	$at,.PF0f01828c
/*  f01827c:	ad8f0000 */ 	sw	$t7,0x0($t4)
/*  f018280:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f018284:	3c018006 */ 	lui	$at,0x8006
/*  f018288:	ac2424bc */ 	sw	$a0,0x24bc($at)
.PF0f01828c:
/*  f01828c:	8f1824bc */ 	lw	$t8,0x24bc($t8)
/*  f018290:	3c018006 */ 	lui	$at,0x8006
/*  f018294:	53000004 */ 	beqzl	$t8,.PF0f0182a8
/*  f018298:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f01829c:	ac2024bc */ 	sw	$zero,0x24bc($at)
/*  f0182a0:	ada40000 */ 	sw	$a0,0x0($t5)
/*  f0182a4:	8da20000 */ 	lw	$v0,0x0($t5)
.PF0f0182a8:
/*  f0182a8:	3c018006 */ 	lui	$at,0x8006
/*  f0182ac:	1040000f */ 	beqz	$v0,.PF0f0182ec
/*  f0182b0:	00000000 */ 	nop
/*  f0182b4:	8d190038 */ 	lw	$t9,0x38($t0)
/*  f0182b8:	3c068006 */ 	lui	$a2,0x8006
/*  f0182bc:	24c624e0 */ 	addiu	$a2,$a2,0x24e0
/*  f0182c0:	00597821 */ 	addu	$t7,$v0,$t9
/*  f0182c4:	19e00009 */ 	blez	$t7,.PF0f0182ec
/*  f0182c8:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0182cc:	3c078006 */ 	lui	$a3,0x8006
/*  f0182d0:	3c098006 */ 	lui	$t1,0x8006
/*  f0182d4:	252924c8 */ 	addiu	$t1,$t1,0x24c8
/*  f0182d8:	24e724cc */ 	addiu	$a3,$a3,0x24cc
/*  f0182dc:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f0182e0:	ace40000 */ 	sw	$a0,0x0($a3)
/*  f0182e4:	ad240000 */ 	sw	$a0,0x0($t1)
/*  f0182e8:	acc40000 */ 	sw	$a0,0x0($a2)
.PF0f0182ec:
/*  f0182ec:	3c078006 */ 	lui	$a3,0x8006
/*  f0182f0:	24e724cc */ 	addiu	$a3,$a3,0x24cc
/*  f0182f4:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f0182f8:	3c068006 */ 	lui	$a2,0x8006
/*  f0182fc:	3c098006 */ 	lui	$t1,0x8006
/*  f018300:	252924c8 */ 	addiu	$t1,$t1,0x24c8
/*  f018304:	1300002c */ 	beqz	$t8,.PF0f0183b8
/*  f018308:	24c624e0 */ 	addiu	$a2,$a2,0x24e0
/*  f01830c:	ac2424dc */ 	sw	$a0,0x24dc($at)
/*  f018310:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f018314:	3c018006 */ 	lui	$at,0x8006
/*  f018318:	14400008 */ 	bnez	$v0,.PF0f01833c
/*  f01831c:	24590001 */ 	addiu	$t9,$v0,0x1
/*  f018320:	c42624c4 */ 	lwc1	$f6,0x24c4($at)
/*  f018324:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018328:	c42a965c */ 	lwc1	$f10,-0x69a4($at)
/*  f01832c:	3c018006 */ 	lui	$at,0x8006
/*  f018330:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f018334:	10000011 */ 	b	.PF0f01837c
/*  f018338:	e42824c4 */ 	swc1	$f8,0x24c4($at)
.PF0f01833c:
/*  f01833c:	14820009 */ 	bne	$a0,$v0,.PF0f018364
/*  f018340:	3c018006 */ 	lui	$at,0x8006
/*  f018344:	3c018006 */ 	lui	$at,0x8006
/*  f018348:	c42424c4 */ 	lwc1	$f4,0x24c4($at)
/*  f01834c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018350:	c4269660 */ 	lwc1	$f6,-0x69a0($at)
/*  f018354:	3c018006 */ 	lui	$at,0x8006
/*  f018358:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f01835c:	10000007 */ 	b	.PF0f01837c
/*  f018360:	e42a24c4 */ 	swc1	$f10,0x24c4($at)
.PF0f018364:
/*  f018364:	c42824c4 */ 	lwc1	$f8,0x24c4($at)
/*  f018368:	3c017f1b */ 	lui	$at,0x7f1b
/*  f01836c:	c4249664 */ 	lwc1	$f4,-0x699c($at)
/*  f018370:	3c018006 */ 	lui	$at,0x8006
/*  f018374:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f018378:	e42624c4 */ 	swc1	$f6,0x24c4($at)
.PF0f01837c:
/*  f01837c:	3c018006 */ 	lui	$at,0x8006
/*  f018380:	c42a24c4 */ 	lwc1	$f10,0x24c4($at)
/*  f018384:	3c018006 */ 	lui	$at,0x8006
/*  f018388:	460a703e */ 	c.le.s	$f14,$f10
/*  f01838c:	00000000 */ 	nop
/*  f018390:	45000009 */ 	bc1f	.PF0f0183b8
/*  f018394:	00000000 */ 	nop
/*  f018398:	e43224c4 */ 	swc1	$f18,0x24c4($at)
/*  f01839c:	24010006 */ 	li	$at,0x6
/*  f0183a0:	17210005 */ 	bne	$t9,$at,.PF0f0183b8
/*  f0183a4:	ad390000 */ 	sw	$t9,0x0($t1)
/*  f0183a8:	3c058006 */ 	lui	$a1,0x8006
/*  f0183ac:	24a524ac */ 	addiu	$a1,$a1,0x24ac
/*  f0183b0:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f0183b4:	aca40000 */ 	sw	$a0,0x0($a1)
.PF0f0183b8:
/*  f0183b8:	8dce24dc */ 	lw	$t6,0x24dc($t6)
/*  f0183bc:	3c058006 */ 	lui	$a1,0x8006
/*  f0183c0:	24a524ac */ 	addiu	$a1,$a1,0x24ac
/*  f0183c4:	11c00012 */ 	beqz	$t6,.PF0f018410
/*  f0183c8:	00003825 */ 	move	$a3,$zero
/*  f0183cc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0183d0:	c4289668 */ 	lwc1	$f8,-0x6998($at)
/*  f0183d4:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f0183d8:	3c028006 */ 	lui	$v0,0x8006
/*  f0183dc:	244224d8 */ 	addiu	$v0,$v0,0x24d8
/*  f0183e0:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0183e4:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f0183e8:	3c018006 */ 	lui	$at,0x8006
/*  f0183ec:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0183f0:	e42824d8 */ 	swc1	$f8,0x24d8($at)
/*  f0183f4:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f0183f8:	4600603e */ 	c.le.s	$f12,$f0
/*  f0183fc:	00000000 */ 	nop
/*  f018400:	45020004 */ 	bc1fl	.PF0f018414
/*  f018404:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f018408:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f01840c:	e4440000 */ 	swc1	$f4,0x0($v0)
.PF0f018410:
/*  f018410:	8cd80000 */ 	lw	$t8,0x0($a2)
.PF0f018414:
/*  f018414:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018418:	53000012 */ 	beqzl	$t8,.PF0f018464
/*  f01841c:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f018420:	c42a966c */ 	lwc1	$f10,-0x6994($at)
/*  f018424:	c506004c */ 	lwc1	$f6,0x4c($t0)
/*  f018428:	3c0a8006 */ 	lui	$t2,0x8006
/*  f01842c:	254a24e4 */ 	addiu	$t2,$t2,0x24e4
/*  f018430:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f018434:	c5440000 */ 	lwc1	$f4,0x0($t2)
/*  f018438:	3c018006 */ 	lui	$at,0x8006
/*  f01843c:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f018440:	e42a24e4 */ 	swc1	$f10,0x24e4($at)
/*  f018444:	c5460000 */ 	lwc1	$f6,0x0($t2)
/*  f018448:	4606703e */ 	c.le.s	$f14,$f6
/*  f01844c:	00000000 */ 	nop
/*  f018450:	45020004 */ 	bc1fl	.PF0f018464
/*  f018454:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f018458:	e54e0000 */ 	swc1	$f14,0x0($t2)
/*  f01845c:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f018460:	8ca20000 */ 	lw	$v0,0x0($a1)
.PF0f018464:
/*  f018464:	00003025 */ 	move	$a2,$zero
/*  f018468:	5040000a */ 	beqzl	$v0,.PF0f018494
/*  f01846c:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018470:	8d190038 */ 	lw	$t9,0x38($t0)
/*  f018474:	00597821 */ 	addu	$t7,$v0,$t9
/*  f018478:	29e10033 */ 	slti	$at,$t7,0x33
/*  f01847c:	14200004 */ 	bnez	$at,.PF0f018490
/*  f018480:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f018484:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f018488:	3c018006 */ 	lui	$at,0x8006
/*  f01848c:	ac242404 */ 	sw	$a0,0x2404($at)
.PF0f018490:
/*  f018490:	8fa40330 */ 	lw	$a0,0x330($sp)
.PF0f018494:
/*  f018494:	0c002f12 */ 	jal	viSetFillColour
/*  f018498:	00002825 */ 	move	$a1,$zero
/*  f01849c:	0c002c02 */ 	jal	viFillBuffer
/*  f0184a0:	00402025 */ 	move	$a0,$v0
/*  f0184a4:	3c188006 */ 	lui	$t8,0x8006
/*  f0184a8:	8f18249c */ 	lw	$t8,0x249c($t8)
/*  f0184ac:	00401825 */ 	move	$v1,$v0
/*  f0184b0:	24040002 */ 	li	$a0,0x2
/*  f0184b4:	13000003 */ 	beqz	$t8,.PF0f0184c4
/*  f0184b8:	00000000 */ 	nop
/*  f0184bc:	10000272 */ 	b	.PF0f018e88
/*  f0184c0:	8fbf0034 */ 	lw	$ra,0x34($sp)
.PF0f0184c4:
/*  f0184c4:	0fc5a24c */ 	jal	gfxAllocateLookAt
/*  f0184c8:	afa30330 */ 	sw	$v1,0x330($sp)
/*  f0184cc:	44809000 */ 	mtc1	$zero,$f18
/*  f0184d0:	3c01457a */ 	lui	$at,0x457a
/*  f0184d4:	44812000 */ 	mtc1	$at,$f4
/*  f0184d8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0184dc:	44814000 */ 	mtc1	$at,$f8
/*  f0184e0:	44069000 */ 	mfc1	$a2,$f18
/*  f0184e4:	44079000 */ 	mfc1	$a3,$f18
/*  f0184e8:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f0184ec:	00402825 */ 	move	$a1,$v0
/*  f0184f0:	afa20134 */ 	sw	$v0,0x134($sp)
/*  f0184f4:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0184f8:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f0184fc:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f018500:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f018504:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*  f018508:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f01850c:	0c0011b7 */ 	jal	guLookAtReflect
/*  f018510:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f018514:	8fa30330 */ 	lw	$v1,0x330($sp)
/*  f018518:	3c017f1b */ 	lui	$at,0x7f1b
/*  f01851c:	c4229670 */ 	lwc1	$f2,-0x6990($at)
/*  f018520:	8fa80134 */ 	lw	$t0,0x134($sp)
/*  f018524:	3c190384 */ 	lui	$t9,0x384
/*  f018528:	37390010 */ 	ori	$t9,$t9,0x10
/*  f01852c:	3c0f0382 */ 	lui	$t7,0x382
/*  f018530:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f018534:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f018538:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f01853c:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f018540:	250e0010 */ 	addiu	$t6,$t0,0x10
/*  f018544:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f018548:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f01854c:	3c018006 */ 	lui	$at,0x8006
/*  f018550:	c42024e4 */ 	lwc1	$f0,0x24e4($at)
/*  f018554:	3c01bf80 */ 	lui	$at,0xbf80
/*  f018558:	44815000 */ 	mtc1	$at,$f10
/*  f01855c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018560:	c4269674 */ 	lwc1	$f6,-0x698c($at)
/*  f018564:	460a0380 */ 	add.s	$f14,$f0,$f10
/*  f018568:	44809000 */ 	mtc1	$zero,$f18
/*  f01856c:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f018570:	3c058006 */ 	lui	$a1,0x8006
/*  f018574:	24a52248 */ 	addiu	$a1,$a1,0x2248
/*  f018578:	46027202 */ 	mul.s	$f8,$f14,$f2
/*  f01857c:	240200ff */ 	li	$v0,0xff
/*  f018580:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f018584:	a0a00006 */ 	sb	$zero,0x6($a1)
/*  f018588:	a0a00005 */ 	sb	$zero,0x5($a1)
/*  f01858c:	46049401 */ 	sub.s	$f16,$f18,$f4
/*  f018590:	a0a00004 */ 	sb	$zero,0x4($a1)
/*  f018594:	a0a00002 */ 	sb	$zero,0x2($a1)
/*  f018598:	46024300 */ 	add.s	$f12,$f8,$f2
/*  f01859c:	46028282 */ 	mul.s	$f10,$f16,$f2
/*  f0185a0:	a0a00001 */ 	sb	$zero,0x1($a1)
/*  f0185a4:	a0a00000 */ 	sb	$zero,0x0($a1)
/*  f0185a8:	a0a2000e */ 	sb	$v0,0xe($a1)
/*  f0185ac:	a0a2000d */ 	sb	$v0,0xd($a1)
/*  f0185b0:	a0a2000c */ 	sb	$v0,0xc($a1)
/*  f0185b4:	a0a2000a */ 	sb	$v0,0xa($a1)
/*  f0185b8:	46025400 */ 	add.s	$f16,$f10,$f2
/*  f0185bc:	a0a20009 */ 	sb	$v0,0x9($a1)
/*  f0185c0:	a0a20008 */ 	sb	$v0,0x8($a1)
/*  f0185c4:	e7ac00e4 */ 	swc1	$f12,0xe4($sp)
/*  f0185c8:	e7b000e0 */ 	swc1	$f16,0xe0($sp)
/*  f0185cc:	0c00685b */ 	jal	sinf
/*  f0185d0:	afa60330 */ 	sw	$a2,0x330($sp)
/*  f0185d4:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f0185d8:	0c006858 */ 	jal	cosf
/*  f0185dc:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f0185e0:	3c0142fe */ 	lui	$at,0x42fe
/*  f0185e4:	44813000 */ 	mtc1	$at,$f6
/*  f0185e8:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f0185ec:	3c018006 */ 	lui	$at,0x8006
/*  f0185f0:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f0185f4:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0185f8:	00000000 */ 	nop
/*  f0185fc:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f018600:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f018604:	440f3000 */ 	mfc1	$t7,$f6
/*  f018608:	0c00685b */ 	jal	sinf
/*  f01860c:	a02f2258 */ 	sb	$t7,0x2258($at)
/*  f018610:	3c0142fe */ 	lui	$at,0x42fe
/*  f018614:	44812000 */ 	mtc1	$at,$f4
/*  f018618:	3c018006 */ 	lui	$at,0x8006
/*  f01861c:	c7ac00e4 */ 	lwc1	$f12,0xe4($sp)
/*  f018620:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f018624:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f018628:	44185000 */ 	mfc1	$t8,$f10
/*  f01862c:	0c006858 */ 	jal	cosf
/*  f018630:	a0382259 */ 	sb	$t8,0x2259($at)
/*  f018634:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f018638:	0c006858 */ 	jal	cosf
/*  f01863c:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f018640:	3c0142fe */ 	lui	$at,0x42fe
/*  f018644:	44813000 */ 	mtc1	$at,$f6
/*  f018648:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f01864c:	44809000 */ 	mtc1	$zero,$f18
/*  f018650:	3c018006 */ 	lui	$at,0x8006
/*  f018654:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f018658:	44059000 */ 	mfc1	$a1,$f18
/*  f01865c:	44069000 */ 	mfc1	$a2,$f18
/*  f018660:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f018664:	3c07457a */ 	lui	$a3,0x457a
/*  f018668:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f01866c:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f018670:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f018674:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f018678:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f01867c:	e7b20024 */ 	swc1	$f18,0x24($sp)
/*  f018680:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f018684:	440f3000 */ 	mfc1	$t7,$f6
/*  f018688:	00000000 */ 	nop
/*  f01868c:	a02f225a */ 	sb	$t7,0x225a($at)
/*  f018690:	3c013f80 */ 	lui	$at,0x3f80
/*  f018694:	44812000 */ 	mtc1	$at,$f4
/*  f018698:	0c005a1d */ 	jal	mtx00016ae4
/*  f01869c:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0186a0:	3c0e8006 */ 	lui	$t6,0x8006
/*  f0186a4:	8dce2490 */ 	lw	$t6,0x2490($t6)
/*  f0186a8:	24010001 */ 	li	$at,0x1
/*  f0186ac:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f0186b0:	15c10004 */ 	bne	$t6,$at,.PF0f0186c4
/*  f0186b4:	3c188006 */ 	lui	$t8,0x8006
/*  f0186b8:	8f1821c8 */ 	lw	$t8,0x21c8($t8)
/*  f0186bc:	10000004 */ 	b	.PF0f0186d0
/*  f0186c0:	afb8022c */ 	sw	$t8,0x22c($sp)
.PF0f0186c4:
/*  f0186c4:	3c198006 */ 	lui	$t9,0x8006
/*  f0186c8:	8f3921cc */ 	lw	$t9,0x21cc($t9)
/*  f0186cc:	afb9022c */ 	sw	$t9,0x22c($sp)
.PF0f0186d0:
/*  f0186d0:	3c018006 */ 	lui	$at,0x8006
/*  f0186d4:	0c005841 */ 	jal	mtx4LoadYRotation
/*  f0186d8:	c42c2478 */ 	lwc1	$f12,0x2478($at)
/*  f0186dc:	3c018006 */ 	lui	$at,0x8006
/*  f0186e0:	c42c2480 */ 	lwc1	$f12,0x2480($at)
/*  f0186e4:	0c00581e */ 	jal	mtx4LoadXRotation
/*  f0186e8:	27a501a8 */ 	addiu	$a1,$sp,0x1a8
/*  f0186ec:	27a401a8 */ 	addiu	$a0,$sp,0x1a8
/*  f0186f0:	0c0055e3 */ 	jal	mtx4MultMtx4InPlace
/*  f0186f4:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f0186f8:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f0186fc:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018700:	0c0055e4 */ 	jal	mtx4MultMtx4
/*  f018704:	27a60270 */ 	addiu	$a2,$sp,0x270
/*  f018708:	3c018006 */ 	lui	$at,0x8006
/*  f01870c:	c42c2488 */ 	lwc1	$f12,0x2488($at)
/*  f018710:	0c005725 */ 	jal	mtx00015f04
/*  f018714:	27a50270 */ 	addiu	$a1,$sp,0x270
/*  f018718:	3c01437f */ 	lui	$at,0x437f
/*  f01871c:	44814000 */ 	mtc1	$at,$f8
/*  f018720:	3c018006 */ 	lui	$at,0x8006
/*  f018724:	c42a2498 */ 	lwc1	$f10,0x2498($at)
/*  f018728:	24020001 */ 	li	$v0,0x1
/*  f01872c:	3c038006 */ 	lui	$v1,0x8006
/*  f018730:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f018734:	24632230 */ 	addiu	$v1,$v1,0x2230
/*  f018738:	24050002 */ 	li	$a1,0x2
/*  f01873c:	444ff800 */ 	cfc1	$t7,$31
/*  f018740:	44c2f800 */ 	ctc1	$v0,$31
/*  f018744:	00000000 */ 	nop
/*  f018748:	46003124 */ 	cvt.w.s	$f4,$f6
/*  f01874c:	4442f800 */ 	cfc1	$v0,$31
/*  f018750:	00000000 */ 	nop
/*  f018754:	30420078 */ 	andi	$v0,$v0,0x78
/*  f018758:	10400012 */ 	beqz	$v0,.PF0f0187a4
/*  f01875c:	3c014f00 */ 	lui	$at,0x4f00
/*  f018760:	44812000 */ 	mtc1	$at,$f4
/*  f018764:	24020001 */ 	li	$v0,0x1
/*  f018768:	46043101 */ 	sub.s	$f4,$f6,$f4
/*  f01876c:	44c2f800 */ 	ctc1	$v0,$31
/*  f018770:	00000000 */ 	nop
/*  f018774:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f018778:	4442f800 */ 	cfc1	$v0,$31
/*  f01877c:	00000000 */ 	nop
/*  f018780:	30420078 */ 	andi	$v0,$v0,0x78
/*  f018784:	14400005 */ 	bnez	$v0,.PF0f01879c
/*  f018788:	00000000 */ 	nop
/*  f01878c:	44022000 */ 	mfc1	$v0,$f4
/*  f018790:	3c018000 */ 	lui	$at,0x8000
/*  f018794:	10000007 */ 	b	.PF0f0187b4
/*  f018798:	00411025 */ 	or	$v0,$v0,$at
.PF0f01879c:
/*  f01879c:	10000005 */ 	b	.PF0f0187b4
/*  f0187a0:	2402ffff */ 	li	$v0,-1
.PF0f0187a4:
/*  f0187a4:	44022000 */ 	mfc1	$v0,$f4
/*  f0187a8:	00000000 */ 	nop
/*  f0187ac:	0440fffb */ 	bltz	$v0,.PF0f01879c
/*  f0187b0:	00000000 */ 	nop
.PF0f0187b4:
/*  f0187b4:	8fb8022c */ 	lw	$t8,0x22c($sp)
/*  f0187b8:	44cff800 */ 	ctc1	$t7,$31
/*  f0187bc:	a0620006 */ 	sb	$v0,0x6($v1)
/*  f0187c0:	a0620005 */ 	sb	$v0,0x5($v1)
/*  f0187c4:	a0620004 */ 	sb	$v0,0x4($v1)
/*  f0187c8:	a0620002 */ 	sb	$v0,0x2($v1)
/*  f0187cc:	a0620001 */ 	sb	$v0,0x1($v1)
/*  f0187d0:	a0620000 */ 	sb	$v0,0x0($v1)
/*  f0187d4:	afa000dc */ 	sw	$zero,0xdc($sp)
/*  f0187d8:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f0187dc:	0c0069ab */ 	jal	modelGetPart
/*  f0187e0:	8f040008 */ 	lw	$a0,0x8($t8)
/*  f0187e4:	10400027 */ 	beqz	$v0,.PF0f018884
/*  f0187e8:	00402825 */ 	move	$a1,$v0
/*  f0187ec:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0187f0:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f0187f4:	84d90010 */ 	lh	$t9,0x10($a2)
/*  f0187f8:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f0187fc:	afaf00dc */ 	sw	$t7,0xdc($sp)
/*  f018800:	94ce0016 */ 	lhu	$t6,0x16($a2)
/*  f018804:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f018808:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f01880c:	0c0069eb */ 	jal	modelGetNodeRwData
/*  f018810:	afb800d8 */ 	sw	$t8,0xd8($sp)
/*  f018814:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f018818:	0fc5a25d */ 	jal	gfxAllocate
/*  f01881c:	24040028 */ 	li	$a0,0x28
/*  f018820:	8fb90160 */ 	lw	$t9,0x160($sp)
/*  f018824:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f018828:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f01882c:	af220004 */ 	sw	$v0,0x4($t9)
/*  f018830:	3c0e8000 */ 	lui	$t6,0x8000
/*  f018834:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f018838:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f01883c:	3c180386 */ 	lui	$t8,0x386
/*  f018840:	37180010 */ 	ori	$t8,$t8,0x10
/*  f018844:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f018848:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f01884c:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018850:	3c0f0388 */ 	lui	$t7,0x388
/*  f018854:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f018858:	3c198006 */ 	lui	$t9,0x8006
/*  f01885c:	27392208 */ 	addiu	$t9,$t9,0x2208
/*  f018860:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f018864:	25ce2200 */ 	addiu	$t6,$t6,0x2200
/*  f018868:	3c180601 */ 	lui	$t8,0x601
/*  f01886c:	ac4e0014 */ 	sw	$t6,0x14($v0)
/*  f018870:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f018874:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f018878:	ac580018 */ 	sw	$t8,0x18($v0)
/*  f01887c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f018880:	ac59001c */ 	sw	$t9,0x1c($v0)
.PF0f018884:
/*  f018884:	8faf022c */ 	lw	$t7,0x22c($sp)
/*  f018888:	24050004 */ 	li	$a1,0x4
/*  f01888c:	0c0069ab */ 	jal	modelGetPart
/*  f018890:	8de40008 */ 	lw	$a0,0x8($t7)
/*  f018894:	10400037 */ 	beqz	$v0,.PF0f018974
/*  f018898:	00402825 */ 	move	$a1,$v0
/*  f01889c:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0188a0:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f0188a4:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f0188a8:	84d80010 */ 	lh	$t8,0x10($a2)
/*  f0188ac:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f0188b0:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f0188b4:	afaf00dc */ 	sw	$t7,0xdc($sp)
/*  f0188b8:	8fae00d8 */ 	lw	$t6,0xd8($sp)
/*  f0188bc:	94d80016 */ 	lhu	$t8,0x16($a2)
/*  f0188c0:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f0188c4:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f0188c8:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f0188cc:	0c0069eb */ 	jal	modelGetNodeRwData
/*  f0188d0:	afaf00d8 */ 	sw	$t7,0xd8($sp)
/*  f0188d4:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0188d8:	0fc5a25d */ 	jal	gfxAllocate
/*  f0188dc:	24040028 */ 	li	$a0,0x28
/*  f0188e0:	8fae0160 */ 	lw	$t6,0x160($sp)
/*  f0188e4:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f0188e8:	3c018006 */ 	lui	$at,0x8006
/*  f0188ec:	adc20004 */ 	sw	$v0,0x4($t6)
/*  f0188f0:	44809000 */ 	mtc1	$zero,$f18
/*  f0188f4:	c4282498 */ 	lwc1	$f8,0x2498($at)
/*  f0188f8:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0188fc:	3c198000 */ 	lui	$t9,0x8000
/*  f018900:	4608903c */ 	c.lt.s	$f18,$f8
/*  f018904:	37390040 */ 	ori	$t9,$t9,0x40
/*  f018908:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f01890c:	3c0f0386 */ 	lui	$t7,0x386
/*  f018910:	45000016 */ 	bc1f	.PF0f01896c
/*  f018914:	3c18b800 */ 	lui	$t8,0xb800
/*  f018918:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f01891c:	37180002 */ 	ori	$t8,$t8,0x2
/*  f018920:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f018924:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f018928:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f01892c:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018930:	25ce2238 */ 	addiu	$t6,$t6,0x2238
/*  f018934:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f018938:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f01893c:	3c198006 */ 	lui	$t9,0x8006
/*  f018940:	3c180388 */ 	lui	$t8,0x388
/*  f018944:	37180010 */ 	ori	$t8,$t8,0x10
/*  f018948:	27392230 */ 	addiu	$t9,$t9,0x2230
/*  f01894c:	acf90004 */ 	sw	$t9,0x4($a3)
/*  f018950:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f018954:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018958:	3c0f0601 */ 	lui	$t7,0x601
/*  f01895c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f018960:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f018964:	10000003 */ 	b	.PF0f018974
/*  f018968:	ac6e0004 */ 	sw	$t6,0x4($v1)
.PF0f01896c:
/*  f01896c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f018970:	ac400004 */ 	sw	$zero,0x4($v0)
.PF0f018974:
/*  f018974:	8fb9022c */ 	lw	$t9,0x22c($sp)
/*  f018978:	24050006 */ 	li	$a1,0x6
/*  f01897c:	0c0069ab */ 	jal	modelGetPart
/*  f018980:	8f240008 */ 	lw	$a0,0x8($t9)
/*  f018984:	10400037 */ 	beqz	$v0,.PF0f018a64
/*  f018988:	00402825 */ 	move	$a1,$v0
/*  f01898c:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f018990:	8faf00dc */ 	lw	$t7,0xdc($sp)
/*  f018994:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f018998:	84ce0010 */ 	lh	$t6,0x10($a2)
/*  f01899c:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0189a0:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0189a4:	afb900dc */ 	sw	$t9,0xdc($sp)
/*  f0189a8:	8faf00d8 */ 	lw	$t7,0xd8($sp)
/*  f0189ac:	94ce0016 */ 	lhu	$t6,0x16($a2)
/*  f0189b0:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f0189b4:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0189b8:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0189bc:	0c0069eb */ 	jal	modelGetNodeRwData
/*  f0189c0:	afb900d8 */ 	sw	$t9,0xd8($sp)
/*  f0189c4:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0189c8:	0fc5a25d */ 	jal	gfxAllocate
/*  f0189cc:	24040028 */ 	li	$a0,0x28
/*  f0189d0:	8faf0160 */ 	lw	$t7,0x160($sp)
/*  f0189d4:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f0189d8:	3c018006 */ 	lui	$at,0x8006
/*  f0189dc:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f0189e0:	44809000 */ 	mtc1	$zero,$f18
/*  f0189e4:	c42a2498 */ 	lwc1	$f10,0x2498($at)
/*  f0189e8:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0189ec:	3c188000 */ 	lui	$t8,0x8000
/*  f0189f0:	460a903c */ 	c.lt.s	$f18,$f10
/*  f0189f4:	37180040 */ 	ori	$t8,$t8,0x40
/*  f0189f8:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f0189fc:	3c190386 */ 	lui	$t9,0x386
/*  f018a00:	45000016 */ 	bc1f	.PF0f018a5c
/*  f018a04:	3c0eb800 */ 	lui	$t6,0xb800
/*  f018a08:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f018a0c:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f018a10:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f018a14:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f018a18:	37390010 */ 	ori	$t9,$t9,0x10
/*  f018a1c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f018a20:	25ef2238 */ 	addiu	$t7,$t7,0x2238
/*  f018a24:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f018a28:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f018a2c:	3c188006 */ 	lui	$t8,0x8006
/*  f018a30:	3c0e0388 */ 	lui	$t6,0x388
/*  f018a34:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018a38:	27182230 */ 	addiu	$t8,$t8,0x2230
/*  f018a3c:	acf80004 */ 	sw	$t8,0x4($a3)
/*  f018a40:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f018a44:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018a48:	3c190601 */ 	lui	$t9,0x601
/*  f018a4c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f018a50:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f018a54:	10000003 */ 	b	.PF0f018a64
/*  f018a58:	ac6f0004 */ 	sw	$t7,0x4($v1)
.PF0f018a5c:
/*  f018a5c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f018a60:	ac400004 */ 	sw	$zero,0x4($v0)
.PF0f018a64:
/*  f018a64:	8fb8022c */ 	lw	$t8,0x22c($sp)
/*  f018a68:	24050008 */ 	li	$a1,0x8
/*  f018a6c:	0c0069ab */ 	jal	modelGetPart
/*  f018a70:	8f040008 */ 	lw	$a0,0x8($t8)
/*  f018a74:	10400037 */ 	beqz	$v0,.PF0f018b54
/*  f018a78:	00402825 */ 	move	$a1,$v0
/*  f018a7c:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f018a80:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f018a84:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f018a88:	84cf0010 */ 	lh	$t7,0x10($a2)
/*  f018a8c:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f018a90:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f018a94:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f018a98:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f018a9c:	94cf0016 */ 	lhu	$t7,0x16($a2)
/*  f018aa0:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f018aa4:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f018aa8:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f018aac:	0c0069eb */ 	jal	modelGetNodeRwData
/*  f018ab0:	afb800d8 */ 	sw	$t8,0xd8($sp)
/*  f018ab4:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f018ab8:	0fc5a25d */ 	jal	gfxAllocate
/*  f018abc:	24040028 */ 	li	$a0,0x28
/*  f018ac0:	8fb90160 */ 	lw	$t9,0x160($sp)
/*  f018ac4:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f018ac8:	3c018006 */ 	lui	$at,0x8006
/*  f018acc:	af220004 */ 	sw	$v0,0x4($t9)
/*  f018ad0:	44809000 */ 	mtc1	$zero,$f18
/*  f018ad4:	c4262498 */ 	lwc1	$f6,0x2498($at)
/*  f018ad8:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f018adc:	3c0e8000 */ 	lui	$t6,0x8000
/*  f018ae0:	4606903c */ 	c.lt.s	$f18,$f6
/*  f018ae4:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f018ae8:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f018aec:	3c180386 */ 	lui	$t8,0x386
/*  f018af0:	45000016 */ 	bc1f	.PF0f018b4c
/*  f018af4:	3c0fb800 */ 	lui	$t7,0xb800
/*  f018af8:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f018afc:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f018b00:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f018b04:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f018b08:	37180010 */ 	ori	$t8,$t8,0x10
/*  f018b0c:	3c198006 */ 	lui	$t9,0x8006
/*  f018b10:	27392238 */ 	addiu	$t9,$t9,0x2238
/*  f018b14:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f018b18:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f018b1c:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018b20:	3c0f0388 */ 	lui	$t7,0x388
/*  f018b24:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f018b28:	25ce2230 */ 	addiu	$t6,$t6,0x2230
/*  f018b2c:	acee0004 */ 	sw	$t6,0x4($a3)
/*  f018b30:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f018b34:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018b38:	3c180601 */ 	lui	$t8,0x601
/*  f018b3c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f018b40:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f018b44:	10000003 */ 	b	.PF0f018b54
/*  f018b48:	ac790004 */ 	sw	$t9,0x4($v1)
.PF0f018b4c:
/*  f018b4c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f018b50:	ac400004 */ 	sw	$zero,0x4($v0)
.PF0f018b54:
/*  f018b54:	0fc5a239 */ 	jal	gfxAllocateVertices
/*  f018b58:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f018b5c:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f018b60:	0fc5a253 */ 	jal	gfxAllocateColours
/*  f018b64:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f018b68:	3c013f80 */ 	lui	$at,0x3f80
/*  f018b6c:	44812000 */ 	mtc1	$at,$f4
/*  f018b70:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f018b74:	3c068006 */ 	lui	$a2,0x8006
/*  f018b78:	3c078006 */ 	lui	$a3,0x8006
/*  f018b7c:	240e00f0 */ 	li	$t6,0xf0
/*  f018b80:	27b80270 */ 	addiu	$t8,$sp,0x270
/*  f018b84:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f018b88:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018b8c:	8ce7248c */ 	lw	$a3,0x248c($a3)
/*  f018b90:	8cc624d4 */ 	lw	$a2,0x24d4($a2)
/*  f018b94:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018b98:	8fa5022c */ 	lw	$a1,0x22c($sp)
/*  f018b9c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f018ba0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f018ba4:	0fc05cc9 */ 	jal	titleRenderPdLogoModel
/*  f018ba8:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f018bac:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f018bb0:	3c0e8000 */ 	lui	$t6,0x8000
/*  f018bb4:	3c180386 */ 	lui	$t8,0x386
/*  f018bb8:	37180010 */ 	ori	$t8,$t8,0x10
/*  f018bbc:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f018bc0:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f018bc4:	3c198006 */ 	lui	$t9,0x8006
/*  f018bc8:	27392250 */ 	addiu	$t9,$t9,0x2250
/*  f018bcc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f018bd0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f018bd4:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f018bd8:	244f0018 */ 	addiu	$t7,$v0,0x18
/*  f018bdc:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f018be0:	afaf0330 */ 	sw	$t7,0x330($sp)
/*  f018be4:	3c188006 */ 	lui	$t8,0x8006
/*  f018be8:	3c0e0388 */ 	lui	$t6,0x388
/*  f018bec:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018bf0:	27182248 */ 	addiu	$t8,$t8,0x2248
/*  f018bf4:	3c198006 */ 	lui	$t9,0x8006
/*  f018bf8:	ac580014 */ 	sw	$t8,0x14($v0)
/*  f018bfc:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f018c00:	27392528 */ 	addiu	$t9,$t9,0x2528
/*  f018c04:	8f210000 */ 	lw	$at,0x0($t9)
/*  f018c08:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f018c0c:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018c10:	ac810000 */ 	sw	$at,0x0($a0)
/*  f018c14:	8f2e0004 */ 	lw	$t6,0x4($t9)
/*  f018c18:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f018c1c:	8f210008 */ 	lw	$at,0x8($t9)
/*  f018c20:	0c00591b */ 	jal	mtx4LoadTranslation
/*  f018c24:	ac810008 */ 	sw	$at,0x8($a0)
/*  f018c28:	3c013f80 */ 	lui	$at,0x3f80
/*  f018c2c:	44814000 */ 	mtc1	$at,$f8
/*  f018c30:	c7aa013c */ 	lwc1	$f10,0x13c($sp)
/*  f018c34:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018c38:	0c005746 */ 	jal	mtx00015f88
/*  f018c3c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f018c40:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f018c44:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018c48:	0c0055e4 */ 	jal	mtx4MultMtx4
/*  f018c4c:	27a60230 */ 	addiu	$a2,$sp,0x230
/*  f018c50:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018c54:	c42c9678 */ 	lwc1	$f12,-0x6988($at)
/*  f018c58:	0c005725 */ 	jal	mtx00015f04
/*  f018c5c:	27a50230 */ 	addiu	$a1,$sp,0x230
/*  f018c60:	3c028006 */ 	lui	$v0,0x8006
/*  f018c64:	8c4224c8 */ 	lw	$v0,0x24c8($v0)
/*  f018c68:	27a30230 */ 	addiu	$v1,$sp,0x230
/*  f018c6c:	04420085 */ 	bltzl	$v0,.PF0f018e84
/*  f018c70:	8fa20330 */ 	lw	$v0,0x330($sp)
/*  f018c74:	10400082 */ 	beqz	$v0,.PF0f018e80
/*  f018c78:	24010001 */ 	li	$at,0x1
/*  f018c7c:	1441001f */ 	bne	$v0,$at,.PF0f018cfc
/*  f018c80:	3c058006 */ 	lui	$a1,0x8006
/*  f018c84:	3c018006 */ 	lui	$at,0x8006
/*  f018c88:	c42024c4 */ 	lwc1	$f0,0x24c4($at)
/*  f018c8c:	3c013f00 */ 	lui	$at,0x3f00
/*  f018c90:	44813000 */ 	mtc1	$at,$f6
/*  f018c94:	44070000 */ 	mfc1	$a3,$f0
/*  f018c98:	00003025 */ 	move	$a2,$zero
/*  f018c9c:	4606003c */ 	c.lt.s	$f0,$f6
/*  f018ca0:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018ca4:	241800ff */ 	li	$t8,0xff
/*  f018ca8:	3c02800a */ 	lui	$v0,0x800a
/*  f018cac:	45000002 */ 	bc1f	.PF0f018cb8
/*  f018cb0:	3c19800a */ 	lui	$t9,0x800a
/*  f018cb4:	24060001 */ 	li	$a2,0x1
.PF0f018cb8:
/*  f018cb8:	8c42d218 */ 	lw	$v0,-0x2de8($v0)
/*  f018cbc:	3c0e800a */ 	lui	$t6,0x800a
/*  f018cc0:	8ca521dc */ 	lw	$a1,0x21dc($a1)
/*  f018cc4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f018cc8:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f018ccc:	01cf7021 */ 	addu	$t6,$t6,$t7
/*  f018cd0:	8dced210 */ 	lw	$t6,-0x2df0($t6)
/*  f018cd4:	8f39d208 */ 	lw	$t9,-0x2df8($t9)
/*  f018cd8:	01e01025 */ 	move	$v0,$t7
/*  f018cdc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f018ce0:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f018ce4:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018ce8:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f018cec:	0fc05cc9 */ 	jal	titleRenderPdLogoModel
/*  f018cf0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f018cf4:	10000062 */ 	b	.PF0f018e80
/*  f018cf8:	afa20330 */ 	sw	$v0,0x330($sp)
.PF0f018cfc:
/*  f018cfc:	24010002 */ 	li	$at,0x2
/*  f018d00:	14410023 */ 	bne	$v0,$at,.PF0f018d90
/*  f018d04:	3c058006 */ 	lui	$a1,0x8006
/*  f018d08:	3c018006 */ 	lui	$at,0x8006
/*  f018d0c:	c42024c4 */ 	lwc1	$f0,0x24c4($at)
/*  f018d10:	3c013f00 */ 	lui	$at,0x3f00
/*  f018d14:	44812000 */ 	mtc1	$at,$f4
/*  f018d18:	3c013f80 */ 	lui	$at,0x3f80
/*  f018d1c:	44814000 */ 	mtc1	$at,$f8
/*  f018d20:	4604003c */ 	c.lt.s	$f0,$f4
/*  f018d24:	00003025 */ 	move	$a2,$zero
/*  f018d28:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018d2c:	241800ff */ 	li	$t8,0xff
/*  f018d30:	45000002 */ 	bc1f	.PF0f018d3c
/*  f018d34:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f018d38:	24060001 */ 	li	$a2,0x1
.PF0f018d3c:
/*  f018d3c:	3c02800a */ 	lui	$v0,0x800a
/*  f018d40:	8c42d218 */ 	lw	$v0,-0x2de8($v0)
/*  f018d44:	3c19800a */ 	lui	$t9,0x800a
/*  f018d48:	3c0e800a */ 	lui	$t6,0x800a
/*  f018d4c:	00027880 */ 	sll	$t7,$v0,0x2
/*  f018d50:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f018d54:	01cf7021 */ 	addu	$t6,$t6,$t7
/*  f018d58:	8dced210 */ 	lw	$t6,-0x2df0($t6)
/*  f018d5c:	8f39d208 */ 	lw	$t9,-0x2df8($t9)
/*  f018d60:	44813000 */ 	mtc1	$at,$f6
/*  f018d64:	44075000 */ 	mfc1	$a3,$f10
/*  f018d68:	8ca521d8 */ 	lw	$a1,0x21d8($a1)
/*  f018d6c:	01e01025 */ 	move	$v0,$t7
/*  f018d70:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f018d74:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018d78:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f018d7c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f018d80:	0fc05cc9 */ 	jal	titleRenderPdLogoModel
/*  f018d84:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f018d88:	1000003d */ 	b	.PF0f018e80
/*  f018d8c:	afa20330 */ 	sw	$v0,0x330($sp)
.PF0f018d90:
/*  f018d90:	24010003 */ 	li	$at,0x3
/*  f018d94:	14410022 */ 	bne	$v0,$at,.PF0f018e20
/*  f018d98:	3c058006 */ 	lui	$a1,0x8006
/*  f018d9c:	3c018006 */ 	lui	$at,0x8006
/*  f018da0:	c42024c4 */ 	lwc1	$f0,0x24c4($at)
/*  f018da4:	3c013f00 */ 	lui	$at,0x3f00
/*  f018da8:	44812000 */ 	mtc1	$at,$f4
/*  f018dac:	44070000 */ 	mfc1	$a3,$f0
/*  f018db0:	00003025 */ 	move	$a2,$zero
/*  f018db4:	4604003c */ 	c.lt.s	$f0,$f4
/*  f018db8:	3c058006 */ 	lui	$a1,0x8006
/*  f018dbc:	3c013f80 */ 	lui	$at,0x3f80
/*  f018dc0:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018dc4:	45000002 */ 	bc1f	.PF0f018dd0
/*  f018dc8:	241800ff */ 	li	$t8,0xff
/*  f018dcc:	24060001 */ 	li	$a2,0x1
.PF0f018dd0:
/*  f018dd0:	3c02800a */ 	lui	$v0,0x800a
/*  f018dd4:	8c42d218 */ 	lw	$v0,-0x2de8($v0)
/*  f018dd8:	3c19800a */ 	lui	$t9,0x800a
/*  f018ddc:	3c0e800a */ 	lui	$t6,0x800a
/*  f018de0:	00027880 */ 	sll	$t7,$v0,0x2
/*  f018de4:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f018de8:	01cf7021 */ 	addu	$t6,$t6,$t7
/*  f018dec:	8dced210 */ 	lw	$t6,-0x2df0($t6)
/*  f018df0:	8f39d208 */ 	lw	$t9,-0x2df8($t9)
/*  f018df4:	44814000 */ 	mtc1	$at,$f8
/*  f018df8:	8ca521d8 */ 	lw	$a1,0x21d8($a1)
/*  f018dfc:	01e01025 */ 	move	$v0,$t7
/*  f018e00:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f018e04:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018e08:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f018e0c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f018e10:	0fc05cc9 */ 	jal	titleRenderPdLogoModel
/*  f018e14:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f018e18:	10000019 */ 	b	.PF0f018e80
/*  f018e1c:	afa20330 */ 	sw	$v0,0x330($sp)
.PF0f018e20:
/*  f018e20:	3c02800a */ 	lui	$v0,0x800a
/*  f018e24:	8c42d218 */ 	lw	$v0,-0x2de8($v0)
/*  f018e28:	3c19800a */ 	lui	$t9,0x800a
/*  f018e2c:	3c0e800a */ 	lui	$t6,0x800a
/*  f018e30:	00027880 */ 	sll	$t7,$v0,0x2
/*  f018e34:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f018e38:	01cf7021 */ 	addu	$t6,$t6,$t7
/*  f018e3c:	3c013f80 */ 	lui	$at,0x3f80
/*  f018e40:	44815000 */ 	mtc1	$at,$f10
/*  f018e44:	8dced210 */ 	lw	$t6,-0x2df0($t6)
/*  f018e48:	8f39d208 */ 	lw	$t9,-0x2df8($t9)
/*  f018e4c:	241800ff */ 	li	$t8,0xff
/*  f018e50:	8ca521d8 */ 	lw	$a1,0x21d8($a1)
/*  f018e54:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f018e58:	01e01025 */ 	move	$v0,$t7
/*  f018e5c:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018e60:	00003025 */ 	move	$a2,$zero
/*  f018e64:	3c073f80 */ 	lui	$a3,0x3f80
/*  f018e68:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018e6c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f018e70:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f018e74:	0fc05cc9 */ 	jal	titleRenderPdLogoModel
/*  f018e78:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f018e7c:	afa20330 */ 	sw	$v0,0x330($sp)
.PF0f018e80:
/*  f018e80:	8fa20330 */ 	lw	$v0,0x330($sp)
.PF0f018e84:
/*  f018e84:	8fbf0034 */ 	lw	$ra,0x34($sp)
.PF0f018e88:
/*  f018e88:	27bd0330 */ 	addiu	$sp,$sp,0x330
/*  f018e8c:	03e00008 */ 	jr	$ra
/*  f018e90:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel titleRenderPdLogo
.late_rodata
glabel var7f1a8400
.word 0x458ca000
glabel var7f1a8404
.word 0x3dcccccd
glabel var7f1a8408
.word 0x4087b1f9
glabel var7f1a840c
.word 0x3c9a6417
glabel var7f1a8410
.word 0x3ef13c64
glabel var7f1a8414
.word 0x3eb33333
glabel var7f1a8418
.word 0x3fc907a9
glabel var7f1a841c
.word 0x39459ed6
glabel var7f1a8420
.word 0x3c9a6417
glabel var7f1a8424
.word 0x40c907a9
glabel var7f1a8428
.word 0x40c907a9
glabel var7f1a842c
.word 0x40c907a9
glabel var7f1a8430
.word 0x40c907a9
glabel var7f1a8434
.word 0x3b83126f
glabel var7f1a8438
.word 0x3f4ccccd
glabel var7f1a843c
.word 0x38ed2501
glabel var7f1a8440
.word 0x3c3944e9
glabel var7f1a8444
.word 0x40c907a9
glabel var7f1a8448
.word 0x3bf5c28f
glabel var7f1a844c
.word 0x3ccccccd
glabel var7f1a8450
.word 0x3db851ec
glabel var7f1a8454
.word 0x3dcccccd
glabel var7f1a8458
.word 0x3bcddaca
glabel var7f1a845c
.word 0x3c8b4396
glabel var7f1a8460
.word 0x40490fdb
glabel var7f1a8464
.word 0x3e19999a
glabel var7f1a8468
.word 0x3e9db22d
.text
/*  f017ac0:	27bdfcd0 */ 	addiu	$sp,$sp,-816
/*  f017ac4:	3c0f8006 */ 	lui	$t7,%hi(var80062818)
/*  f017ac8:	3c028006 */ 	lui	$v0,%hi(g_PdLogoIsFirstTick)
/*  f017acc:	25ef2818 */ 	addiu	$t7,$t7,%lo(var80062818)
/*  f017ad0:	24422730 */ 	addiu	$v0,$v0,%lo(g_PdLogoIsFirstTick)
/*  f017ad4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f017ad8:	afa40330 */ 	sw	$a0,0x330($sp)
/*  f017adc:	25f9003c */ 	addiu	$t9,$t7,0x3c
/*  f017ae0:	27ae02f0 */ 	addiu	$t6,$sp,0x2f0
.L0f017ae4:
/*  f017ae4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f017ae8:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f017aec:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f017af0:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f017af4:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f017af8:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f017afc:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f017b00:	15f9fff8 */ 	bne	$t7,$t9,.L0f017ae4
/*  f017b04:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f017b08:	8de10000 */ 	lw	$at,0x0($t7)
/*  f017b0c:	3c188006 */ 	lui	$t8,%hi(g_TitleTimer)
/*  f017b10:	3c048006 */ 	lui	$a0,%hi(g_PdLogoBlackTimer)
/*  f017b14:	adc10000 */ 	sw	$at,0x0($t6)
/*  f017b18:	8f1824c4 */ 	lw	$t8,%lo(g_TitleTimer)($t8)
/*  f017b1c:	3c017f1b */ 	lui	$at,%hi(var7f1a8400)
/*  f017b20:	c4288400 */ 	lwc1	$f8,%lo(var7f1a8400)($at)
/*  f017b24:	44982000 */ 	mtc1	$t8,$f4
/*  f017b28:	3c017f1b */ 	lui	$at,%hi(var7f1a8404)
/*  f017b2c:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f017b30:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f017b34:	c4248404 */ 	lwc1	$f4,%lo(var7f1a8404)($at)
/*  f017b38:	3c098006 */ 	lui	$t1,%hi(g_PdLogoPreMorphTimer)
/*  f017b3c:	3c0a8006 */ 	lui	$t2,%hi(g_PdLogoMorphEndTimer)
/*  f017b40:	3c0c8006 */ 	lui	$t4,%hi(g_PdLogoPreTitleTimer)
/*  f017b44:	3c0d8006 */ 	lui	$t5,%hi(g_PdLogoPointlessTimer)
/*  f017b48:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f017b4c:	3c0b8006 */ 	lui	$t3,%hi(g_PdLogoEndYRot)
/*  f017b50:	25ad2800 */ 	addiu	$t5,$t5,%lo(g_PdLogoPointlessTimer)
/*  f017b54:	258c27f0 */ 	addiu	$t4,$t4,%lo(g_PdLogoPreTitleTimer)
/*  f017b58:	254a27e0 */ 	addiu	$t2,$t2,%lo(g_PdLogoMorphEndTimer)
/*  f017b5c:	252927d4 */ 	addiu	$t1,$t1,%lo(g_PdLogoPreMorphTimer)
/*  f017b60:	3c013f80 */ 	lui	$at,0x3f80
/*  f017b64:	248427cc */ 	addiu	$a0,$a0,%lo(g_PdLogoBlackTimer)
/*  f017b68:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f017b6c:	256b27c4 */ 	addiu	$t3,$t3,%lo(g_PdLogoEndYRot)
/*  f017b70:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f017b74:	13200041 */ 	beqz	$t9,.L0f017c7c
/*  f017b78:	e7a6013c */ 	swc1	$f6,0x13c($sp)
/*  f017b7c:	44817000 */ 	mtc1	$at,$f14
/*  f017b80:	3c017f1b */ 	lui	$at,%hi(var7f1a8408)
/*  f017b84:	c4288408 */ 	lwc1	$f8,%lo(var7f1a8408)($at)
/*  f017b88:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotCur)
/*  f017b8c:	44809000 */ 	mtc1	$zero,$f18
/*  f017b90:	e42827a8 */ 	swc1	$f8,%lo(g_PdLogoYRotCur)($at)
/*  f017b94:	3c017f1b */ 	lui	$at,%hi(var7f1a840c)
/*  f017b98:	c42a840c */ 	lwc1	$f10,%lo(var7f1a840c)($at)
/*  f017b9c:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotSpeed)
/*  f017ba0:	3c1f8006 */ 	lui	$ra,%hi(g_PdLogoMorphing)
/*  f017ba4:	e42a27ac */ 	swc1	$f10,%lo(g_PdLogoYRotSpeed)($at)
/*  f017ba8:	3c017f1b */ 	lui	$at,%hi(var7f1a8410)
/*  f017bac:	c4248410 */ 	lwc1	$f4,%lo(var7f1a8410)($at)
/*  f017bb0:	3c018006 */ 	lui	$at,%hi(g_PdLogoXRotCur)
/*  f017bb4:	27ff27d8 */ 	addiu	$ra,$ra,%lo(g_PdLogoMorphing)
/*  f017bb8:	e42427b0 */ 	swc1	$f4,%lo(g_PdLogoXRotCur)($at)
/*  f017bbc:	3c018006 */ 	lui	$at,%hi(g_PdLogoXRotSpeed)
/*  f017bc0:	e43227b4 */ 	swc1	$f18,%lo(g_PdLogoXRotSpeed)($at)
/*  f017bc4:	3c017f1b */ 	lui	$at,%hi(var7f1a8414)
/*  f017bc8:	c4268414 */ 	lwc1	$f6,%lo(var7f1a8414)($at)
/*  f017bcc:	3c018006 */ 	lui	$at,%hi(g_PdLogoScale)
/*  f017bd0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f017bd4:	e42627b8 */ 	swc1	$f6,%lo(g_PdLogoScale)($at)
/*  f017bd8:	3c018006 */ 	lui	$at,%hi(g_PdLogoFrac)
/*  f017bdc:	e43227bc */ 	swc1	$f18,%lo(g_PdLogoFrac)($at)
/*  f017be0:	3c018006 */ 	lui	$at,%hi(g_PdLogoUseCombinedModel)
/*  f017be4:	ac2027c0 */ 	sw	$zero,%lo(g_PdLogoUseCombinedModel)($at)
/*  f017be8:	3c018006 */ 	lui	$at,%hi(g_PdLogoAmbientLightFrac)
/*  f017bec:	e42e27c8 */ 	swc1	$f14,%lo(g_PdLogoAmbientLightFrac)($at)
/*  f017bf0:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f017bf4:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f017bf8:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotEnabled)
/*  f017bfc:	ac2027d0 */ 	sw	$zero,%lo(g_PdLogoYRotEnabled)($at)
/*  f017c00:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f017c04:	afe00000 */ 	sw	$zero,0x0($ra)
/*  f017c08:	3c018006 */ 	lui	$at,%hi(g_PdLogoExitTimer)
/*  f017c0c:	ac2027dc */ 	sw	$zero,%lo(g_PdLogoExitTimer)($at)
/*  f017c10:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f017c14:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotStopping)
/*  f017c18:	ac2027e4 */ 	sw	$zero,%lo(g_PdLogoYRotStopping)($at)
/*  f017c1c:	3c018006 */ 	lui	$at,%hi(g_PdLogoDarkenEnabled)
/*  f017c20:	ac2027e8 */ 	sw	$zero,%lo(g_PdLogoDarkenEnabled)($at)
/*  f017c24:	3c018006 */ 	lui	$at,%hi(var80062804)
/*  f017c28:	ac232804 */ 	sw	$v1,%lo(var80062804)($at)
/*  f017c2c:	3c018006 */ 	lui	$at,%hi(g_PdLogoPointlessTimerEnabled)
/*  f017c30:	ac2027ec */ 	sw	$zero,%lo(g_PdLogoPointlessTimerEnabled)($at)
/*  f017c34:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f017c38:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f017c3c:	e43227f4 */ 	swc1	$f18,%lo(g_PdLogoTitleStepFrac)($at)
/*  f017c40:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitlePresenting)
/*  f017c44:	ac2027fc */ 	sw	$zero,%lo(g_PdLogoTitlePresenting)($at)
/*  f017c48:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStep)
/*  f017c4c:	ac2f27f8 */ 	sw	$t7,%lo(g_PdLogoTitleStep)($at)
/*  f017c50:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f017c54:	3c018006 */ 	lui	$at,%hi(g_PdLogoUnusedRotEnabled)
/*  f017c58:	ac20280c */ 	sw	$zero,%lo(g_PdLogoUnusedRotEnabled)($at)
/*  f017c5c:	3c017f1b */ 	lui	$at,%hi(var7f1a8418)
/*  f017c60:	c4288418 */ 	lwc1	$f8,%lo(var7f1a8418)($at)
/*  f017c64:	3c018006 */ 	lui	$at,%hi(g_PdLogoUnusedRot)
/*  f017c68:	e4282808 */ 	swc1	$f8,%lo(g_PdLogoUnusedRot)($at)
/*  f017c6c:	3c018006 */ 	lui	$at,%hi(g_PdLogoLightMoving)
/*  f017c70:	ac202810 */ 	sw	$zero,%lo(g_PdLogoLightMoving)($at)
/*  f017c74:	3c018006 */ 	lui	$at,%hi(g_PdLogoLightDirFrac)
/*  f017c78:	e4322814 */ 	swc1	$f18,%lo(g_PdLogoLightDirFrac)($at)
.L0f017c7c:
/*  f017c7c:	3c048006 */ 	lui	$a0,%hi(g_PdLogoBlackTimer)
/*  f017c80:	248427cc */ 	addiu	$a0,$a0,%lo(g_PdLogoBlackTimer)
/*  f017c84:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f017c88:	3c013f80 */ 	lui	$at,0x3f80
/*  f017c8c:	44817000 */ 	mtc1	$at,$f14
/*  f017c90:	3c098006 */ 	lui	$t1,%hi(g_PdLogoPreMorphTimer)
/*  f017c94:	3c0a8006 */ 	lui	$t2,%hi(g_PdLogoMorphEndTimer)
/*  f017c98:	3c0c8006 */ 	lui	$t4,%hi(g_PdLogoPreTitleTimer)
/*  f017c9c:	3c0d8006 */ 	lui	$t5,%hi(g_PdLogoPointlessTimer)
/*  f017ca0:	3c1f8006 */ 	lui	$ra,%hi(g_PdLogoMorphing)
/*  f017ca4:	44809000 */ 	mtc1	$zero,$f18
/*  f017ca8:	27ff27d8 */ 	addiu	$ra,$ra,%lo(g_PdLogoMorphing)
/*  f017cac:	25ad2800 */ 	addiu	$t5,$t5,%lo(g_PdLogoPointlessTimer)
/*  f017cb0:	258c27f0 */ 	addiu	$t4,$t4,%lo(g_PdLogoPreTitleTimer)
/*  f017cb4:	254a27e0 */ 	addiu	$t2,$t2,%lo(g_PdLogoMorphEndTimer)
/*  f017cb8:	252927d4 */ 	addiu	$t1,$t1,%lo(g_PdLogoPreMorphTimer)
/*  f017cbc:	10400009 */ 	beqz	$v0,.L0f017ce4
/*  f017cc0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f017cc4:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f017cc8:	29c10004 */ 	slti	$at,$t6,0x4
/*  f017ccc:	14200005 */ 	bnez	$at,.L0f017ce4
/*  f017cd0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f017cd4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f017cd8:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotEnabled)
/*  f017cdc:	ac2327d0 */ 	sw	$v1,%lo(g_PdLogoYRotEnabled)($at)
/*  f017ce0:	ad230000 */ 	sw	$v1,0x0($t1)
.L0f017ce4:
/*  f017ce4:	3c198006 */ 	lui	$t9,%hi(g_PdLogoYRotStopping)
/*  f017ce8:	8f3927e4 */ 	lw	$t9,%lo(g_PdLogoYRotStopping)($t9)
/*  f017cec:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotCur)
/*  f017cf0:	13200049 */ 	beqz	$t9,.L0f017e18
/*  f017cf4:	00000000 */ 	nop
/*  f017cf8:	c42027a8 */ 	lwc1	$f0,%lo(g_PdLogoYRotCur)($at)
/*  f017cfc:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017d00:	3c048006 */ 	lui	$a0,%hi(g_PdLogoYRotCur)
/*  f017d04:	3c068006 */ 	lui	$a2,%hi(g_PdLogoYRotSpeed)
/*  f017d08:	4602003c */ 	c.lt.s	$f0,$f2
/*  f017d0c:	3c017f1b */ 	lui	$at,%hi(var7f1a841c)
/*  f017d10:	24c627ac */ 	addiu	$a2,$a2,%lo(g_PdLogoYRotSpeed)
/*  f017d14:	248427a8 */ 	addiu	$a0,$a0,%lo(g_PdLogoYRotCur)
/*  f017d18:	45020038 */ 	bc1fl	.L0f017dfc
/*  f017d1c:	4600103e */ 	c.le.s	$f2,$f0
/*  f017d20:	c420841c */ 	lwc1	$f0,%lo(var7f1a841c)($at)
/*  f017d24:	3c017f1b */ 	lui	$at,%hi(var7f1a8420)
/*  f017d28:	c42a8420 */ 	lwc1	$f10,%lo(var7f1a8420)($at)
/*  f017d2c:	44051000 */ 	mfc1	$a1,$f2
/*  f017d30:	44070000 */ 	mfc1	$a3,$f0
/*  f017d34:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f017d38:	0fc1b643 */ 	jal	applySpeed
/*  f017d3c:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f017d40:	3c028006 */ 	lui	$v0,%hi(g_PdLogoYRotCur)
/*  f017d44:	3c0b8006 */ 	lui	$t3,%hi(g_PdLogoEndYRot)
/*  f017d48:	256b27c4 */ 	addiu	$t3,$t3,%lo(g_PdLogoEndYRot)
/*  f017d4c:	244227a8 */ 	addiu	$v0,$v0,%lo(g_PdLogoYRotCur)
/*  f017d50:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017d54:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017d58:	3c098006 */ 	lui	$t1,%hi(g_PdLogoPreMorphTimer)
/*  f017d5c:	3c0a8006 */ 	lui	$t2,%hi(g_PdLogoMorphEndTimer)
/*  f017d60:	4600103e */ 	c.le.s	$f2,$f0
/*  f017d64:	3c0c8006 */ 	lui	$t4,%hi(g_PdLogoPreTitleTimer)
/*  f017d68:	3c0d8006 */ 	lui	$t5,%hi(g_PdLogoPointlessTimer)
/*  f017d6c:	3c1f8006 */ 	lui	$ra,%hi(g_PdLogoMorphing)
/*  f017d70:	44809000 */ 	mtc1	$zero,$f18
/*  f017d74:	27ff27d8 */ 	addiu	$ra,$ra,%lo(g_PdLogoMorphing)
/*  f017d78:	25ad2800 */ 	addiu	$t5,$t5,%lo(g_PdLogoPointlessTimer)
/*  f017d7c:	258c27f0 */ 	addiu	$t4,$t4,%lo(g_PdLogoPreTitleTimer)
/*  f017d80:	254a27e0 */ 	addiu	$t2,$t2,%lo(g_PdLogoMorphEndTimer)
/*  f017d84:	45000005 */ 	bc1f	.L0f017d9c
/*  f017d88:	252927d4 */ 	addiu	$t1,$t1,%lo(g_PdLogoPreMorphTimer)
/*  f017d8c:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f017d90:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotSpeed)
/*  f017d94:	e43227ac */ 	swc1	$f18,%lo(g_PdLogoYRotSpeed)($at)
/*  f017d98:	c4400000 */ 	lwc1	$f0,0x0($v0)
.L0f017d9c:
/*  f017d9c:	3c017f1b */ 	lui	$at,%hi(var7f1a8424)
/*  f017da0:	c42c8424 */ 	lwc1	$f12,%lo(var7f1a8424)($at)
/*  f017da4:	4600603e */ 	c.le.s	$f12,$f0
/*  f017da8:	00000000 */ 	nop
/*  f017dac:	45020009 */ 	bc1fl	.L0f017dd4
/*  f017db0:	4612003c */ 	c.lt.s	$f0,$f18
/*  f017db4:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f017db8:	460c1181 */ 	sub.s	$f6,$f2,$f12
/*  f017dbc:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f017dc0:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017dc4:	e5660000 */ 	swc1	$f6,0x0($t3)
/*  f017dc8:	1000000b */ 	b	.L0f017df8
/*  f017dcc:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017dd0:	4612003c */ 	c.lt.s	$f0,$f18
.L0f017dd4:
/*  f017dd4:	00000000 */ 	nop
/*  f017dd8:	45020008 */ 	bc1fl	.L0f017dfc
/*  f017ddc:	4600103e */ 	c.le.s	$f2,$f0
/*  f017de0:	460c0200 */ 	add.s	$f8,$f0,$f12
/*  f017de4:	460c1280 */ 	add.s	$f10,$f2,$f12
/*  f017de8:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f017dec:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017df0:	e56a0000 */ 	swc1	$f10,0x0($t3)
/*  f017df4:	c5620000 */ 	lwc1	$f2,0x0($t3)
.L0f017df8:
/*  f017df8:	4600103e */ 	c.le.s	$f2,$f0
.L0f017dfc:
/*  f017dfc:	3c013f80 */ 	lui	$at,0x3f80
/*  f017e00:	44817000 */ 	mtc1	$at,$f14
/*  f017e04:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f017e08:	45000021 */ 	bc1f	.L0f017e90
/*  f017e0c:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotStopping)
/*  f017e10:	1000001f */ 	b	.L0f017e90
/*  f017e14:	ac2027e4 */ 	sw	$zero,%lo(g_PdLogoYRotStopping)($at)
.L0f017e18:
/*  f017e18:	3c0f8006 */ 	lui	$t7,%hi(g_PdLogoYRotEnabled)
/*  f017e1c:	8def27d0 */ 	lw	$t7,%lo(g_PdLogoYRotEnabled)($t7)
/*  f017e20:	11e0001b */ 	beqz	$t7,.L0f017e90
/*  f017e24:	3c017f1b */ 	lui	$at,%hi(var7f1a842c)
/*  f017e28:	c42c842c */ 	lwc1	$f12,%lo(var7f1a842c)($at)
/*  f017e2c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f017e30:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f017e34:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotSpeed)
/*  f017e38:	c42427ac */ 	lwc1	$f4,%lo(g_PdLogoYRotSpeed)($at)
/*  f017e3c:	c506004c */ 	lwc1	$f6,0x4c($t0)
/*  f017e40:	3c028006 */ 	lui	$v0,%hi(g_PdLogoYRotCur)
/*  f017e44:	244227a8 */ 	addiu	$v0,$v0,%lo(g_PdLogoYRotCur)
/*  f017e48:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f017e4c:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f017e50:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f017e54:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f017e58:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017e5c:	4600603e */ 	c.le.s	$f12,$f0
/*  f017e60:	00000000 */ 	nop
/*  f017e64:	45020005 */ 	bc1fl	.L0f017e7c
/*  f017e68:	4612003c */ 	c.lt.s	$f0,$f18
/*  f017e6c:	460c0181 */ 	sub.s	$f6,$f0,$f12
/*  f017e70:	10000007 */ 	b	.L0f017e90
/*  f017e74:	e4460000 */ 	swc1	$f6,0x0($v0)
/*  f017e78:	4612003c */ 	c.lt.s	$f0,$f18
.L0f017e7c:
/*  f017e7c:	00000000 */ 	nop
/*  f017e80:	45020004 */ 	bc1fl	.L0f017e94
/*  f017e84:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f017e88:	460c0280 */ 	add.s	$f10,$f0,$f12
/*  f017e8c:	e44a0000 */ 	swc1	$f10,0x0($v0)
.L0f017e90:
/*  f017e90:	8d220000 */ 	lw	$v0,0x0($t1)
.L0f017e94:
/*  f017e94:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f017e98:	3c0b8006 */ 	lui	$t3,%hi(g_PdLogoEndYRot)
/*  f017e9c:	3c017f1b */ 	lui	$at,%hi(var7f1a8430)
/*  f017ea0:	c42c8430 */ 	lwc1	$f12,%lo(var7f1a8430)($at)
/*  f017ea4:	256b27c4 */ 	addiu	$t3,$t3,%lo(g_PdLogoEndYRot)
/*  f017ea8:	1040001a */ 	beqz	$v0,.L0f017f14
/*  f017eac:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f017eb0:	8d0e0038 */ 	lw	$t6,0x38($t0)
/*  f017eb4:	24190050 */ 	addiu	$t9,$zero,0x50
/*  f017eb8:	3c018006 */ 	lui	$at,%hi(g_PdLogoFrac)
/*  f017ebc:	004ec021 */ 	addu	$t8,$v0,$t6
/*  f017ec0:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f017ec4:	1b000009 */ 	blez	$t8,.L0f017eec
/*  f017ec8:	03001025 */ 	or	$v0,$t8,$zero
/*  f017ecc:	44824000 */ 	mtc1	$v0,$f8
/*  f017ed0:	44993000 */ 	mtc1	$t9,$f6
/*  f017ed4:	3c018006 */ 	lui	$at,%hi(g_PdLogoFrac)
/*  f017ed8:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f017edc:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f017ee0:	460a2203 */ 	div.s	$f8,$f4,$f10
/*  f017ee4:	10000002 */ 	b	.L0f017ef0
/*  f017ee8:	e42827bc */ 	swc1	$f8,%lo(g_PdLogoFrac)($at)
.L0f017eec:
/*  f017eec:	e43227bc */ 	swc1	$f18,%lo(g_PdLogoFrac)($at)
.L0f017ef0:
/*  f017ef0:	28410051 */ 	slti	$at,$v0,0x51
/*  f017ef4:	54200008 */ 	bnezl	$at,.L0f017f18
/*  f017ef8:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f017efc:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f017f00:	afe30000 */ 	sw	$v1,0x0($ra)
/*  f017f04:	3c018006 */ 	lui	$at,%hi(g_PdLogoFrac)
/*  f017f08:	e43227bc */ 	swc1	$f18,%lo(g_PdLogoFrac)($at)
/*  f017f0c:	3c018006 */ 	lui	$at,%hi(g_PdLogoUseCombinedModel)
/*  f017f10:	ac2327c0 */ 	sw	$v1,%lo(g_PdLogoUseCombinedModel)($at)
.L0f017f14:
/*  f017f14:	8fef0000 */ 	lw	$t7,0x0($ra)
.L0f017f18:
/*  f017f18:	11e00019 */ 	beqz	$t7,.L0f017f80
/*  f017f1c:	3c017f1b */ 	lui	$at,%hi(var7f1a8434)
/*  f017f20:	c4268434 */ 	lwc1	$f6,%lo(var7f1a8434)($at)
/*  f017f24:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f017f28:	3c018006 */ 	lui	$at,%hi(g_PdLogoFrac)
/*  f017f2c:	c42827bc */ 	lwc1	$f8,%lo(g_PdLogoFrac)($at)
/*  f017f30:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f017f34:	460a4000 */ 	add.s	$f0,$f8,$f10
/*  f017f38:	e42027bc */ 	swc1	$f0,%lo(g_PdLogoFrac)($at)
/*  f017f3c:	3c017f1b */ 	lui	$at,%hi(var7f1a8438)
/*  f017f40:	c4248438 */ 	lwc1	$f4,%lo(var7f1a8438)($at)
/*  f017f44:	3c018006 */ 	lui	$at,%hi(g_PdLogoFrac)
/*  f017f48:	4600203e */ 	c.le.s	$f4,$f0
/*  f017f4c:	00000000 */ 	nop
/*  f017f50:	45020006 */ 	bc1fl	.L0f017f6c
/*  f017f54:	4600703e */ 	c.le.s	$f14,$f0
/*  f017f58:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f017f5c:	55c00003 */ 	bnezl	$t6,.L0f017f6c
/*  f017f60:	4600703e */ 	c.le.s	$f14,$f0
/*  f017f64:	ad430000 */ 	sw	$v1,0x0($t2)
/*  f017f68:	4600703e */ 	c.le.s	$f14,$f0
.L0f017f6c:
/*  f017f6c:	00000000 */ 	nop
/*  f017f70:	45020004 */ 	bc1fl	.L0f017f84
/*  f017f74:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f017f78:	e42e27bc */ 	swc1	$f14,%lo(g_PdLogoFrac)($at)
/*  f017f7c:	afe00000 */ 	sw	$zero,0x0($ra)
.L0f017f80:
/*  f017f80:	8d430000 */ 	lw	$v1,0x0($t2)
.L0f017f84:
/*  f017f84:	10600064 */ 	beqz	$v1,.L0f018118
/*  f017f88:	00000000 */ 	nop
/*  f017f8c:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f017f90:	3c018006 */ 	lui	$at,%hi(g_PdLogoXRotCur)
/*  f017f94:	3c048006 */ 	lui	$a0,%hi(g_PdLogoXRotCur)
/*  f017f98:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f017f9c:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f017fa0:	c42827b0 */ 	lwc1	$f8,%lo(g_PdLogoXRotCur)($at)
/*  f017fa4:	3c068006 */ 	lui	$a2,%hi(g_PdLogoXRotSpeed)
/*  f017fa8:	3c017f1b */ 	lui	$at,%hi(var7f1a843c)
/*  f017fac:	4608903c */ 	c.lt.s	$f18,$f8
/*  f017fb0:	24c627b4 */ 	addiu	$a2,$a2,%lo(g_PdLogoXRotSpeed)
/*  f017fb4:	248427b0 */ 	addiu	$a0,$a0,%lo(g_PdLogoXRotCur)
/*  f017fb8:	4502001f */ 	bc1fl	.L0f018038
/*  f017fbc:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f017fc0:	c420843c */ 	lwc1	$f0,%lo(var7f1a843c)($at)
/*  f017fc4:	3c017f1b */ 	lui	$at,%hi(var7f1a8440)
/*  f017fc8:	c42a8440 */ 	lwc1	$f10,%lo(var7f1a8440)($at)
/*  f017fcc:	44059000 */ 	mfc1	$a1,$f18
/*  f017fd0:	44070000 */ 	mfc1	$a3,$f0
/*  f017fd4:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f017fd8:	0fc1b6c0 */ 	jal	applyRotation
/*  f017fdc:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f017fe0:	3c017f1b */ 	lui	$at,%hi(var7f1a8444)
/*  f017fe4:	c42c8444 */ 	lwc1	$f12,%lo(var7f1a8444)($at)
/*  f017fe8:	3c018006 */ 	lui	$at,%hi(g_PdLogoXRotCur)
/*  f017fec:	44809000 */ 	mtc1	$zero,$f18
/*  f017ff0:	c42627b0 */ 	lwc1	$f6,%lo(g_PdLogoXRotCur)($at)
/*  f017ff4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f017ff8:	3c0a8006 */ 	lui	$t2,%hi(g_PdLogoMorphEndTimer)
/*  f017ffc:	4612303e */ 	c.le.s	$f6,$f18
/*  f018000:	3c0b8006 */ 	lui	$t3,%hi(g_PdLogoEndYRot)
/*  f018004:	3c0c8006 */ 	lui	$t4,%hi(g_PdLogoPreTitleTimer)
/*  f018008:	3c0d8006 */ 	lui	$t5,%hi(g_PdLogoPointlessTimer)
/*  f01800c:	25ad2800 */ 	addiu	$t5,$t5,%lo(g_PdLogoPointlessTimer)
/*  f018010:	258c27f0 */ 	addiu	$t4,$t4,%lo(g_PdLogoPreTitleTimer)
/*  f018014:	256b27c4 */ 	addiu	$t3,$t3,%lo(g_PdLogoEndYRot)
/*  f018018:	254a27e0 */ 	addiu	$t2,$t2,%lo(g_PdLogoMorphEndTimer)
/*  f01801c:	45000005 */ 	bc1f	.L0f018034
/*  f018020:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f018024:	3c018006 */ 	lui	$at,%hi(g_PdLogoXRotCur)
/*  f018028:	e43227b0 */ 	swc1	$f18,%lo(g_PdLogoXRotCur)($at)
/*  f01802c:	3c018006 */ 	lui	$at,%hi(g_PdLogoXRotSpeed)
/*  f018030:	e43227b4 */ 	swc1	$f18,%lo(g_PdLogoXRotSpeed)($at)
.L0f018034:
/*  f018034:	8d430000 */ 	lw	$v1,0x0($t2)
.L0f018038:
/*  f018038:	3c013f80 */ 	lui	$at,0x3f80
/*  f01803c:	44817000 */ 	mtc1	$at,$f14
/*  f018040:	2861001f */ 	slti	$at,$v1,0x1f
/*  f018044:	1420001c */ 	bnez	$at,.L0f0180b8
/*  f018048:	00000000 */ 	nop
/*  f01804c:	8d0f0038 */ 	lw	$t7,0x38($t0)
/*  f018050:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f018054:	006f7023 */ 	subu	$t6,$v1,$t7
/*  f018058:	29c1001f */ 	slti	$at,$t6,0x1f
/*  f01805c:	10200016 */ 	beqz	$at,.L0f0180b8
/*  f018060:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotEnabled)
/*  f018064:	ac2027d0 */ 	sw	$zero,%lo(g_PdLogoYRotEnabled)($at)
/*  f018068:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotStopping)
/*  f01806c:	ac2427e4 */ 	sw	$a0,%lo(g_PdLogoYRotStopping)($at)
/*  f018070:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotCur)
/*  f018074:	c42427a8 */ 	lwc1	$f4,%lo(g_PdLogoYRotCur)($at)
/*  f018078:	3c014080 */ 	lui	$at,0x4080
/*  f01807c:	44814000 */ 	mtc1	$at,$f8
/*  f018080:	3c013e80 */ 	lui	$at,0x3e80
/*  f018084:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f018088:	460c5183 */ 	div.s	$f6,$f10,$f12
/*  f01808c:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f018090:	44022000 */ 	mfc1	$v0,$f4
/*  f018094:	44812000 */ 	mtc1	$at,$f4
/*  f018098:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f01809c:	44824000 */ 	mtc1	$v0,$f8
/*  f0180a0:	00000000 */ 	nop
/*  f0180a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0180a8:	460c5182 */ 	mul.s	$f6,$f10,$f12
/*  f0180ac:	00000000 */ 	nop
/*  f0180b0:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0180b4:	e5680000 */ 	swc1	$f8,0x0($t3)
.L0f0180b8:
/*  f0180b8:	3c028006 */ 	lui	$v0,%hi(g_PdLogoYRotStopping)
/*  f0180bc:	28610065 */ 	slti	$at,$v1,0x65
/*  f0180c0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0180c4:	14200009 */ 	bnez	$at,.L0f0180ec
/*  f0180c8:	8c4227e4 */ 	lw	$v0,%lo(g_PdLogoYRotStopping)($v0)
/*  f0180cc:	8d190038 */ 	lw	$t9,0x38($t0)
/*  f0180d0:	3c058006 */ 	lui	$a1,%hi(g_PdLogoDarkenEnabled)
/*  f0180d4:	24a527e8 */ 	addiu	$a1,$a1,%lo(g_PdLogoDarkenEnabled)
/*  f0180d8:	00797823 */ 	subu	$t7,$v1,$t9
/*  f0180dc:	29e10065 */ 	slti	$at,$t7,0x65
/*  f0180e0:	10200002 */ 	beqz	$at,.L0f0180ec
/*  f0180e4:	00000000 */ 	nop
/*  f0180e8:	aca40000 */ 	sw	$a0,0x0($a1)
.L0f0180ec:
/*  f0180ec:	3c058006 */ 	lui	$a1,%hi(g_PdLogoDarkenEnabled)
/*  f0180f0:	14400009 */ 	bnez	$v0,.L0f018118
/*  f0180f4:	24a527e8 */ 	addiu	$a1,$a1,%lo(g_PdLogoDarkenEnabled)
/*  f0180f8:	3c018006 */ 	lui	$at,%hi(g_PdLogoXRotCur)
/*  f0180fc:	c42a27b0 */ 	lwc1	$f10,%lo(g_PdLogoXRotCur)($at)
/*  f018100:	4612503e */ 	c.le.s	$f10,$f18
/*  f018104:	00000000 */ 	nop
/*  f018108:	45000003 */ 	bc1f	.L0f018118
/*  f01810c:	00000000 */ 	nop
/*  f018110:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f018114:	aca40000 */ 	sw	$a0,0x0($a1)
.L0f018118:
/*  f018118:	3c058006 */ 	lui	$a1,%hi(g_PdLogoDarkenEnabled)
/*  f01811c:	24a527e8 */ 	addiu	$a1,$a1,%lo(g_PdLogoDarkenEnabled)
/*  f018120:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f018124:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f018128:	3c0f8006 */ 	lui	$t7,%hi(g_PdLogoUnusedRotEnabled)
/*  f01812c:	11c00012 */ 	beqz	$t6,.L0f018178
/*  f018130:	3c017f1b */ 	lui	$at,%hi(var7f1a8448)
/*  f018134:	c4268448 */ 	lwc1	$f6,%lo(var7f1a8448)($at)
/*  f018138:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f01813c:	3c038006 */ 	lui	$v1,%hi(g_PdLogoAmbientLightFrac)
/*  f018140:	246327c8 */ 	addiu	$v1,$v1,%lo(g_PdLogoAmbientLightFrac)
/*  f018144:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f018148:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f01814c:	3c018006 */ 	lui	$at,%hi(g_PdLogoAmbientLightFrac)
/*  f018150:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f018154:	e42627c8 */ 	swc1	$f6,%lo(g_PdLogoAmbientLightFrac)($at)
/*  f018158:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f01815c:	4612203e */ 	c.le.s	$f4,$f18
/*  f018160:	00000000 */ 	nop
/*  f018164:	45020005 */ 	bc1fl	.L0f01817c
/*  f018168:	8d820000 */ 	lw	$v0,0x0($t4)
/*  f01816c:	e4720000 */ 	swc1	$f18,0x0($v1)
/*  f018170:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f018174:	ad840000 */ 	sw	$a0,0x0($t4)
.L0f018178:
/*  f018178:	8d820000 */ 	lw	$v0,0x0($t4)
.L0f01817c:
/*  f01817c:	3c0e8006 */ 	lui	$t6,%hi(g_PdLogoPointlessTimerEnabled)
/*  f018180:	10400009 */ 	beqz	$v0,.L0f0181a8
/*  f018184:	00000000 */ 	nop
/*  f018188:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f01818c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f018190:	2b210015 */ 	slti	$at,$t9,0x15
/*  f018194:	14200004 */ 	bnez	$at,.L0f0181a8
/*  f018198:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f01819c:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f0181a0:	3c018006 */ 	lui	$at,%hi(g_PdLogoPointlessTimerEnabled)
/*  f0181a4:	ac2427ec */ 	sw	$a0,%lo(g_PdLogoPointlessTimerEnabled)($at)
.L0f0181a8:
/*  f0181a8:	8dce27ec */ 	lw	$t6,%lo(g_PdLogoPointlessTimerEnabled)($t6)
/*  f0181ac:	3c018006 */ 	lui	$at,%hi(g_PdLogoPointlessTimerEnabled)
/*  f0181b0:	51c00004 */ 	beqzl	$t6,.L0f0181c4
/*  f0181b4:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f0181b8:	ac2027ec */ 	sw	$zero,%lo(g_PdLogoPointlessTimerEnabled)($at)
/*  f0181bc:	ada40000 */ 	sw	$a0,0x0($t5)
/*  f0181c0:	8da20000 */ 	lw	$v0,0x0($t5)
.L0f0181c4:
/*  f0181c4:	3c018006 */ 	lui	$at,%hi(g_PdLogoUnusedRotEnabled)
/*  f0181c8:	1040000f */ 	beqz	$v0,.L0f018208
/*  f0181cc:	00000000 */ 	nop
/*  f0181d0:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f0181d4:	3c068006 */ 	lui	$a2,%hi(g_PdLogoLightMoving)
/*  f0181d8:	24c62810 */ 	addiu	$a2,$a2,%lo(g_PdLogoLightMoving)
/*  f0181dc:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f0181e0:	1b200009 */ 	blez	$t9,.L0f018208
/*  f0181e4:	adb90000 */ 	sw	$t9,0x0($t5)
/*  f0181e8:	3c078006 */ 	lui	$a3,%hi(g_PdLogoTitlePresenting)
/*  f0181ec:	3c098006 */ 	lui	$t1,%hi(g_PdLogoTitleStep)
/*  f0181f0:	252927f8 */ 	addiu	$t1,$t1,%lo(g_PdLogoTitleStep)
/*  f0181f4:	24e727fc */ 	addiu	$a3,$a3,%lo(g_PdLogoTitlePresenting)
/*  f0181f8:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f0181fc:	ace40000 */ 	sw	$a0,0x0($a3)
/*  f018200:	ad240000 */ 	sw	$a0,0x0($t1)
/*  f018204:	acc40000 */ 	sw	$a0,0x0($a2)
.L0f018208:
/*  f018208:	3c078006 */ 	lui	$a3,%hi(g_PdLogoTitlePresenting)
/*  f01820c:	24e727fc */ 	addiu	$a3,$a3,%lo(g_PdLogoTitlePresenting)
/*  f018210:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f018214:	3c068006 */ 	lui	$a2,%hi(g_PdLogoLightMoving)
/*  f018218:	3c098006 */ 	lui	$t1,%hi(g_PdLogoTitleStep)
/*  f01821c:	252927f8 */ 	addiu	$t1,$t1,%lo(g_PdLogoTitleStep)
/*  f018220:	11c0002c */ 	beqz	$t6,.L0f0182d4
/*  f018224:	24c62810 */ 	addiu	$a2,$a2,%lo(g_PdLogoLightMoving)
/*  f018228:	ac24280c */ 	sw	$a0,%lo(g_PdLogoUnusedRotEnabled)($at)
/*  f01822c:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f018230:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f018234:	14400008 */ 	bnez	$v0,.L0f018258
/*  f018238:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f01823c:	c42a27f4 */ 	lwc1	$f10,%lo(g_PdLogoTitleStepFrac)($at)
/*  f018240:	3c017f1b */ 	lui	$at,%hi(var7f1a844c)
/*  f018244:	c428844c */ 	lwc1	$f8,%lo(var7f1a844c)($at)
/*  f018248:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f01824c:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f018250:	10000011 */ 	b	.L0f018298
/*  f018254:	e42627f4 */ 	swc1	$f6,%lo(g_PdLogoTitleStepFrac)($at)
.L0f018258:
/*  f018258:	14820009 */ 	bne	$a0,$v0,.L0f018280
/*  f01825c:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f018260:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f018264:	c42427f4 */ 	lwc1	$f4,%lo(g_PdLogoTitleStepFrac)($at)
/*  f018268:	3c017f1b */ 	lui	$at,%hi(var7f1a8450)
/*  f01826c:	c42a8450 */ 	lwc1	$f10,%lo(var7f1a8450)($at)
/*  f018270:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f018274:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f018278:	10000007 */ 	b	.L0f018298
/*  f01827c:	e42827f4 */ 	swc1	$f8,%lo(g_PdLogoTitleStepFrac)($at)
.L0f018280:
/*  f018280:	c42627f4 */ 	lwc1	$f6,%lo(g_PdLogoTitleStepFrac)($at)
/*  f018284:	3c017f1b */ 	lui	$at,%hi(var7f1a8454)
/*  f018288:	c4248454 */ 	lwc1	$f4,%lo(var7f1a8454)($at)
/*  f01828c:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f018290:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f018294:	e42a27f4 */ 	swc1	$f10,%lo(g_PdLogoTitleStepFrac)($at)
.L0f018298:
/*  f018298:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f01829c:	c42827f4 */ 	lwc1	$f8,%lo(g_PdLogoTitleStepFrac)($at)
/*  f0182a0:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f0182a4:	4608703e */ 	c.le.s	$f14,$f8
/*  f0182a8:	00000000 */ 	nop
/*  f0182ac:	45000009 */ 	bc1f	.L0f0182d4
/*  f0182b0:	00000000 */ 	nop
/*  f0182b4:	e43227f4 */ 	swc1	$f18,%lo(g_PdLogoTitleStepFrac)($at)
/*  f0182b8:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0182bc:	17010005 */ 	bne	$t8,$at,.L0f0182d4
/*  f0182c0:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f0182c4:	3c058006 */ 	lui	$a1,%hi(g_PdLogoExitTimer)
/*  f0182c8:	24a527dc */ 	addiu	$a1,$a1,%lo(g_PdLogoExitTimer)
/*  f0182cc:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f0182d0:	aca40000 */ 	sw	$a0,0x0($a1)
.L0f0182d4:
/*  f0182d4:	8def280c */ 	lw	$t7,%lo(g_PdLogoUnusedRotEnabled)($t7)
/*  f0182d8:	3c058006 */ 	lui	$a1,%hi(g_PdLogoExitTimer)
/*  f0182dc:	24a527dc */ 	addiu	$a1,$a1,%lo(g_PdLogoExitTimer)
/*  f0182e0:	11e00012 */ 	beqz	$t7,.L0f01832c
/*  f0182e4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0182e8:	3c017f1b */ 	lui	$at,%hi(var7f1a8458)
/*  f0182ec:	c4268458 */ 	lwc1	$f6,%lo(var7f1a8458)($at)
/*  f0182f0:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f0182f4:	3c028006 */ 	lui	$v0,%hi(g_PdLogoUnusedRot)
/*  f0182f8:	24422808 */ 	addiu	$v0,$v0,%lo(g_PdLogoUnusedRot)
/*  f0182fc:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f018300:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f018304:	3c018006 */ 	lui	$at,%hi(g_PdLogoUnusedRot)
/*  f018308:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f01830c:	e4262808 */ 	swc1	$f6,%lo(g_PdLogoUnusedRot)($at)
/*  f018310:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f018314:	4600603e */ 	c.le.s	$f12,$f0
/*  f018318:	00000000 */ 	nop
/*  f01831c:	45020004 */ 	bc1fl	.L0f018330
/*  f018320:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f018324:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f018328:	e4440000 */ 	swc1	$f4,0x0($v0)
.L0f01832c:
/*  f01832c:	8cce0000 */ 	lw	$t6,0x0($a2)
.L0f018330:
/*  f018330:	3c017f1b */ 	lui	$at,%hi(var7f1a845c)
/*  f018334:	51c00012 */ 	beqzl	$t6,.L0f018380
/*  f018338:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f01833c:	c428845c */ 	lwc1	$f8,%lo(var7f1a845c)($at)
/*  f018340:	c50a004c */ 	lwc1	$f10,0x4c($t0)
/*  f018344:	3c0a8006 */ 	lui	$t2,%hi(g_PdLogoLightDirFrac)
/*  f018348:	254a2814 */ 	addiu	$t2,$t2,%lo(g_PdLogoLightDirFrac)
/*  f01834c:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f018350:	c5440000 */ 	lwc1	$f4,0x0($t2)
/*  f018354:	3c018006 */ 	lui	$at,%hi(g_PdLogoLightDirFrac)
/*  f018358:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f01835c:	e4282814 */ 	swc1	$f8,%lo(g_PdLogoLightDirFrac)($at)
/*  f018360:	c54a0000 */ 	lwc1	$f10,0x0($t2)
/*  f018364:	460a703e */ 	c.le.s	$f14,$f10
/*  f018368:	00000000 */ 	nop
/*  f01836c:	45020004 */ 	bc1fl	.L0f018380
/*  f018370:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f018374:	e54e0000 */ 	swc1	$f14,0x0($t2)
/*  f018378:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f01837c:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f018380:
/*  f018380:	00003025 */ 	or	$a2,$zero,$zero
/*  f018384:	5040000a */ 	beqzl	$v0,.L0f0183b0
/*  f018388:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f01838c:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f018390:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f018394:	2b21003d */ 	slti	$at,$t9,0x3d
/*  f018398:	14200004 */ 	bnez	$at,.L0f0183ac
/*  f01839c:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f0183a0:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f0183a4:	3c018006 */ 	lui	$at,%hi(g_PdLogoTriggerExit)
/*  f0183a8:	ac242734 */ 	sw	$a0,%lo(g_PdLogoTriggerExit)($at)
.L0f0183ac:
/*  f0183ac:	8fa40330 */ 	lw	$a0,0x330($sp)
.L0f0183b0:
/*  f0183b0:	0c002fc1 */ 	jal	viSetFillColour
/*  f0183b4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0183b8:	0c002cb1 */ 	jal	viFillBuffer
/*  f0183bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0183c0:	3c0e8006 */ 	lui	$t6,%hi(g_PdLogoBlackTimer)
/*  f0183c4:	8dce27cc */ 	lw	$t6,%lo(g_PdLogoBlackTimer)($t6)
/*  f0183c8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0183cc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0183d0:	11c00003 */ 	beqz	$t6,.L0f0183e0
/*  f0183d4:	00000000 */ 	nop
/*  f0183d8:	10000272 */ 	b	.L0f018da4
/*  f0183dc:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0183e0:
/*  f0183e0:	0fc59e6c */ 	jal	gfxAllocateLookAt
/*  f0183e4:	afa30330 */ 	sw	$v1,0x330($sp)
/*  f0183e8:	44809000 */ 	mtc1	$zero,$f18
/*  f0183ec:	3c01457a */ 	lui	$at,0x457a
/*  f0183f0:	44812000 */ 	mtc1	$at,$f4
/*  f0183f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0183f8:	44813000 */ 	mtc1	$at,$f6
/*  f0183fc:	44069000 */ 	mfc1	$a2,$f18
/*  f018400:	44079000 */ 	mfc1	$a3,$f18
/*  f018404:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f018408:	00402825 */ 	or	$a1,$v0,$zero
/*  f01840c:	afa20134 */ 	sw	$v0,0x134($sp)
/*  f018410:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f018414:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f018418:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f01841c:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f018420:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*  f018424:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f018428:	0c0011c3 */ 	jal	guLookAtReflect
/*  f01842c:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f018430:	8fa30330 */ 	lw	$v1,0x330($sp)
/*  f018434:	3c017f1b */ 	lui	$at,%hi(var7f1a8460)
/*  f018438:	c4228460 */ 	lwc1	$f2,%lo(var7f1a8460)($at)
/*  f01843c:	8fa80134 */ 	lw	$t0,0x134($sp)
/*  f018440:	3c180384 */ 	lui	$t8,0x384
/*  f018444:	37180010 */ 	ori	$t8,$t8,0x10
/*  f018448:	3c190382 */ 	lui	$t9,0x382
/*  f01844c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f018450:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f018454:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f018458:	37390010 */ 	ori	$t9,$t9,0x10
/*  f01845c:	250f0010 */ 	addiu	$t7,$t0,0x10
/*  f018460:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f018464:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f018468:	3c018006 */ 	lui	$at,%hi(g_PdLogoLightDirFrac)
/*  f01846c:	c4202814 */ 	lwc1	$f0,%lo(g_PdLogoLightDirFrac)($at)
/*  f018470:	3c01bf80 */ 	lui	$at,0xbf80
/*  f018474:	44814000 */ 	mtc1	$at,$f8
/*  f018478:	3c017f1b */ 	lui	$at,%hi(var7f1a8464)
/*  f01847c:	c42a8464 */ 	lwc1	$f10,%lo(var7f1a8464)($at)
/*  f018480:	46080380 */ 	add.s	$f14,$f0,$f8
/*  f018484:	44809000 */ 	mtc1	$zero,$f18
/*  f018488:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f01848c:	3c058006 */ 	lui	$a1,%hi(var80062578)
/*  f018490:	24a52578 */ 	addiu	$a1,$a1,%lo(var80062578)
/*  f018494:	46027182 */ 	mul.s	$f6,$f14,$f2
/*  f018498:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f01849c:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f0184a0:	a0a00006 */ 	sb	$zero,0x6($a1)
/*  f0184a4:	a0a00005 */ 	sb	$zero,0x5($a1)
/*  f0184a8:	46049401 */ 	sub.s	$f16,$f18,$f4
/*  f0184ac:	a0a00004 */ 	sb	$zero,0x4($a1)
/*  f0184b0:	a0a00002 */ 	sb	$zero,0x2($a1)
/*  f0184b4:	46023300 */ 	add.s	$f12,$f6,$f2
/*  f0184b8:	46028202 */ 	mul.s	$f8,$f16,$f2
/*  f0184bc:	a0a00001 */ 	sb	$zero,0x1($a1)
/*  f0184c0:	a0a00000 */ 	sb	$zero,0x0($a1)
/*  f0184c4:	a0a2000e */ 	sb	$v0,0xe($a1)
/*  f0184c8:	a0a2000d */ 	sb	$v0,0xd($a1)
/*  f0184cc:	a0a2000c */ 	sb	$v0,0xc($a1)
/*  f0184d0:	a0a2000a */ 	sb	$v0,0xa($a1)
/*  f0184d4:	46024400 */ 	add.s	$f16,$f8,$f2
/*  f0184d8:	a0a20009 */ 	sb	$v0,0x9($a1)
/*  f0184dc:	a0a20008 */ 	sb	$v0,0x8($a1)
/*  f0184e0:	e7ac00e4 */ 	swc1	$f12,0xe4($sp)
/*  f0184e4:	e7b000e0 */ 	swc1	$f16,0xe0($sp)
/*  f0184e8:	0c0068f7 */ 	jal	sinf
/*  f0184ec:	afa60330 */ 	sw	$a2,0x330($sp)
/*  f0184f0:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f0184f4:	0c0068f4 */ 	jal	cosf
/*  f0184f8:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f0184fc:	3c0142fe */ 	lui	$at,0x42fe
/*  f018500:	44815000 */ 	mtc1	$at,$f10
/*  f018504:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f018508:	3c018006 */ 	lui	$at,%hi(var80062578+0x10)
/*  f01850c:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f018510:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f018514:	00000000 */ 	nop
/*  f018518:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f01851c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f018520:	44195000 */ 	mfc1	$t9,$f10
/*  f018524:	0c0068f7 */ 	jal	sinf
/*  f018528:	a0392588 */ 	sb	$t9,%lo(var80062578+0x10)($at)
/*  f01852c:	3c0142fe */ 	lui	$at,0x42fe
/*  f018530:	44812000 */ 	mtc1	$at,$f4
/*  f018534:	3c018006 */ 	lui	$at,%hi(var80062578+0x10+0x1)
/*  f018538:	c7ac00e4 */ 	lwc1	$f12,0xe4($sp)
/*  f01853c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f018540:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f018544:	440e4000 */ 	mfc1	$t6,$f8
/*  f018548:	0c0068f4 */ 	jal	cosf
/*  f01854c:	a02e2589 */ 	sb	$t6,%lo(var80062578+0x10+0x1)($at)
/*  f018550:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f018554:	0c0068f4 */ 	jal	cosf
/*  f018558:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f01855c:	3c0142fe */ 	lui	$at,0x42fe
/*  f018560:	44815000 */ 	mtc1	$at,$f10
/*  f018564:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f018568:	44809000 */ 	mtc1	$zero,$f18
/*  f01856c:	3c018006 */ 	lui	$at,%hi(var80062578+0x10+0x2)
/*  f018570:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f018574:	44059000 */ 	mfc1	$a1,$f18
/*  f018578:	44069000 */ 	mfc1	$a2,$f18
/*  f01857c:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f018580:	3c07457a */ 	lui	$a3,0x457a
/*  f018584:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f018588:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f01858c:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f018590:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f018594:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f018598:	e7b20024 */ 	swc1	$f18,0x24($sp)
/*  f01859c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0185a0:	44195000 */ 	mfc1	$t9,$f10
/*  f0185a4:	00000000 */ 	nop
/*  f0185a8:	a039258a */ 	sb	$t9,%lo(var80062578+0x10+0x2)($at)
/*  f0185ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0185b0:	44812000 */ 	mtc1	$at,$f4
/*  f0185b4:	0c005ab9 */ 	jal	mtx00016ae4
/*  f0185b8:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0185bc:	3c0f8006 */ 	lui	$t7,%hi(g_PdLogoUseCombinedModel)
/*  f0185c0:	8def27c0 */ 	lw	$t7,%lo(g_PdLogoUseCombinedModel)($t7)
/*  f0185c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0185c8:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f0185cc:	15e10004 */ 	bne	$t7,$at,.L0f0185e0
/*  f0185d0:	3c0e8006 */ 	lui	$t6,%hi(g_TitleModel)
/*  f0185d4:	8dce24f8 */ 	lw	$t6,%lo(g_TitleModel)($t6)
/*  f0185d8:	10000004 */ 	b	.L0f0185ec
/*  f0185dc:	afae022c */ 	sw	$t6,0x22c($sp)
.L0f0185e0:
/*  f0185e0:	3c188006 */ 	lui	$t8,%hi(g_TitleModelNLogo2)
/*  f0185e4:	8f1824fc */ 	lw	$t8,%lo(g_TitleModelNLogo2)($t8)
/*  f0185e8:	afb8022c */ 	sw	$t8,0x22c($sp)
.L0f0185ec:
/*  f0185ec:	3c018006 */ 	lui	$at,%hi(g_PdLogoYRotCur)
/*  f0185f0:	0c0058dd */ 	jal	mtx4LoadYRotation
/*  f0185f4:	c42c27a8 */ 	lwc1	$f12,%lo(g_PdLogoYRotCur)($at)
/*  f0185f8:	3c018006 */ 	lui	$at,%hi(g_PdLogoXRotCur)
/*  f0185fc:	c42c27b0 */ 	lwc1	$f12,%lo(g_PdLogoXRotCur)($at)
/*  f018600:	0c0058ba */ 	jal	mtx4LoadXRotation
/*  f018604:	27a501a8 */ 	addiu	$a1,$sp,0x1a8
/*  f018608:	27a401a8 */ 	addiu	$a0,$sp,0x1a8
/*  f01860c:	0c00567f */ 	jal	mtx4MultMtx4InPlace
/*  f018610:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018614:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f018618:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f01861c:	0c005680 */ 	jal	mtx4MultMtx4
/*  f018620:	27a60270 */ 	addiu	$a2,$sp,0x270
/*  f018624:	3c018006 */ 	lui	$at,%hi(g_PdLogoScale)
/*  f018628:	c42c27b8 */ 	lwc1	$f12,%lo(g_PdLogoScale)($at)
/*  f01862c:	0c0057c1 */ 	jal	mtx00015f04
/*  f018630:	27a50270 */ 	addiu	$a1,$sp,0x270
/*  f018634:	3c01437f */ 	lui	$at,0x437f
/*  f018638:	44813000 */ 	mtc1	$at,$f6
/*  f01863c:	3c018006 */ 	lui	$at,%hi(g_PdLogoAmbientLightFrac)
/*  f018640:	c42827c8 */ 	lwc1	$f8,%lo(g_PdLogoAmbientLightFrac)($at)
/*  f018644:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f018648:	3c038006 */ 	lui	$v1,%hi(var80062560)
/*  f01864c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f018650:	24632560 */ 	addiu	$v1,$v1,%lo(var80062560)
/*  f018654:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f018658:	4459f800 */ 	cfc1	$t9,$31
/*  f01865c:	44c2f800 */ 	ctc1	$v0,$31
/*  f018660:	00000000 */ 	nop
/*  f018664:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f018668:	4442f800 */ 	cfc1	$v0,$31
/*  f01866c:	00000000 */ 	nop
/*  f018670:	30420078 */ 	andi	$v0,$v0,0x78
/*  f018674:	10400012 */ 	beqz	$v0,.L0f0186c0
/*  f018678:	3c014f00 */ 	lui	$at,0x4f00
/*  f01867c:	44812000 */ 	mtc1	$at,$f4
/*  f018680:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f018684:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f018688:	44c2f800 */ 	ctc1	$v0,$31
/*  f01868c:	00000000 */ 	nop
/*  f018690:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f018694:	4442f800 */ 	cfc1	$v0,$31
/*  f018698:	00000000 */ 	nop
/*  f01869c:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0186a0:	14400005 */ 	bnez	$v0,.L0f0186b8
/*  f0186a4:	00000000 */ 	nop
/*  f0186a8:	44022000 */ 	mfc1	$v0,$f4
/*  f0186ac:	3c018000 */ 	lui	$at,0x8000
/*  f0186b0:	10000007 */ 	b	.L0f0186d0
/*  f0186b4:	00411025 */ 	or	$v0,$v0,$at
.L0f0186b8:
/*  f0186b8:	10000005 */ 	b	.L0f0186d0
/*  f0186bc:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0186c0:
/*  f0186c0:	44022000 */ 	mfc1	$v0,$f4
/*  f0186c4:	00000000 */ 	nop
/*  f0186c8:	0440fffb */ 	bltz	$v0,.L0f0186b8
/*  f0186cc:	00000000 */ 	nop
.L0f0186d0:
/*  f0186d0:	8fae022c */ 	lw	$t6,0x22c($sp)
/*  f0186d4:	44d9f800 */ 	ctc1	$t9,$31
/*  f0186d8:	a0620006 */ 	sb	$v0,0x6($v1)
/*  f0186dc:	a0620005 */ 	sb	$v0,0x5($v1)
/*  f0186e0:	a0620004 */ 	sb	$v0,0x4($v1)
/*  f0186e4:	a0620002 */ 	sb	$v0,0x2($v1)
/*  f0186e8:	a0620001 */ 	sb	$v0,0x1($v1)
/*  f0186ec:	a0620000 */ 	sb	$v0,0x0($v1)
/*  f0186f0:	afa000dc */ 	sw	$zero,0xdc($sp)
/*  f0186f4:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f0186f8:	0c006a47 */ 	jal	modelGetPart
/*  f0186fc:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f018700:	10400027 */ 	beqz	$v0,.L0f0187a0
/*  f018704:	00402825 */ 	or	$a1,$v0,$zero
/*  f018708:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f01870c:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f018710:	84d80010 */ 	lh	$t8,0x10($a2)
/*  f018714:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f018718:	afb900dc */ 	sw	$t9,0xdc($sp)
/*  f01871c:	94cf0016 */ 	lhu	$t7,0x16($a2)
/*  f018720:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f018724:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f018728:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f01872c:	afae00d8 */ 	sw	$t6,0xd8($sp)
/*  f018730:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f018734:	0fc59e7d */ 	jal	gfxAllocate
/*  f018738:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f01873c:	8fb80160 */ 	lw	$t8,0x160($sp)
/*  f018740:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f018744:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f018748:	af020004 */ 	sw	$v0,0x4($t8)
/*  f01874c:	3c0f8000 */ 	lui	$t7,0x8000
/*  f018750:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f018754:	37390002 */ 	ori	$t9,$t9,0x2
/*  f018758:	3c0e0386 */ 	lui	$t6,0x386
/*  f01875c:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018760:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018764:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f018768:	3c0f8006 */ 	lui	$t7,%hi(var80062530)
/*  f01876c:	3c190388 */ 	lui	$t9,0x388
/*  f018770:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f018774:	3c188006 */ 	lui	$t8,%hi(var80062530+0x8)
/*  f018778:	27182538 */ 	addiu	$t8,$t8,%lo(var80062530+0x8)
/*  f01877c:	37390010 */ 	ori	$t9,$t9,0x10
/*  f018780:	25ef2530 */ 	addiu	$t7,$t7,%lo(var80062530)
/*  f018784:	3c0e0601 */ 	lui	$t6,0x601
/*  f018788:	ac4f0014 */ 	sw	$t7,0x14($v0)
/*  f01878c:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f018790:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f018794:	ac4e0018 */ 	sw	$t6,0x18($v0)
/*  f018798:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f01879c:	ac58001c */ 	sw	$t8,0x1c($v0)
.L0f0187a0:
/*  f0187a0:	8fb9022c */ 	lw	$t9,0x22c($sp)
/*  f0187a4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0187a8:	0c006a47 */ 	jal	modelGetPart
/*  f0187ac:	8f240008 */ 	lw	$a0,0x8($t9)
/*  f0187b0:	10400037 */ 	beqz	$v0,.L0f018890
/*  f0187b4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0187b8:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0187bc:	8faf00dc */ 	lw	$t7,0xdc($sp)
/*  f0187c0:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f0187c4:	84ce0010 */ 	lh	$t6,0x10($a2)
/*  f0187c8:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0187cc:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0187d0:	afb900dc */ 	sw	$t9,0xdc($sp)
/*  f0187d4:	8faf00d8 */ 	lw	$t7,0xd8($sp)
/*  f0187d8:	94ce0016 */ 	lhu	$t6,0x16($a2)
/*  f0187dc:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f0187e0:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0187e4:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0187e8:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0187ec:	afb900d8 */ 	sw	$t9,0xd8($sp)
/*  f0187f0:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0187f4:	0fc59e7d */ 	jal	gfxAllocate
/*  f0187f8:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f0187fc:	8faf0160 */ 	lw	$t7,0x160($sp)
/*  f018800:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f018804:	3c018006 */ 	lui	$at,%hi(g_PdLogoAmbientLightFrac)
/*  f018808:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f01880c:	44809000 */ 	mtc1	$zero,$f18
/*  f018810:	c42627c8 */ 	lwc1	$f6,%lo(g_PdLogoAmbientLightFrac)($at)
/*  f018814:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f018818:	3c188000 */ 	lui	$t8,0x8000
/*  f01881c:	4606903c */ 	c.lt.s	$f18,$f6
/*  f018820:	37180040 */ 	ori	$t8,$t8,0x40
/*  f018824:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f018828:	3c190386 */ 	lui	$t9,0x386
/*  f01882c:	45000016 */ 	bc1f	.L0f018888
/*  f018830:	3c0eb800 */ 	lui	$t6,0xb800
/*  f018834:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f018838:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f01883c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f018840:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f018844:	37390010 */ 	ori	$t9,$t9,0x10
/*  f018848:	3c0f8006 */ 	lui	$t7,%hi(var80062560+0x8)
/*  f01884c:	25ef2568 */ 	addiu	$t7,$t7,%lo(var80062560+0x8)
/*  f018850:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f018854:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f018858:	3c188006 */ 	lui	$t8,%hi(var80062560)
/*  f01885c:	3c0e0388 */ 	lui	$t6,0x388
/*  f018860:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018864:	27182560 */ 	addiu	$t8,$t8,%lo(var80062560)
/*  f018868:	acf80004 */ 	sw	$t8,0x4($a3)
/*  f01886c:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f018870:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018874:	3c190601 */ 	lui	$t9,0x601
/*  f018878:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f01887c:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f018880:	10000003 */ 	b	.L0f018890
/*  f018884:	ac6f0004 */ 	sw	$t7,0x4($v1)
.L0f018888:
/*  f018888:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f01888c:	ac400004 */ 	sw	$zero,0x4($v0)
.L0f018890:
/*  f018890:	8fb8022c */ 	lw	$t8,0x22c($sp)
/*  f018894:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f018898:	0c006a47 */ 	jal	modelGetPart
/*  f01889c:	8f040008 */ 	lw	$a0,0x8($t8)
/*  f0188a0:	10400037 */ 	beqz	$v0,.L0f018980
/*  f0188a4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0188a8:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0188ac:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f0188b0:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f0188b4:	84cf0010 */ 	lh	$t7,0x10($a2)
/*  f0188b8:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f0188bc:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f0188c0:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f0188c4:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f0188c8:	94cf0016 */ 	lhu	$t7,0x16($a2)
/*  f0188cc:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f0188d0:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f0188d4:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f0188d8:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0188dc:	afb800d8 */ 	sw	$t8,0xd8($sp)
/*  f0188e0:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0188e4:	0fc59e7d */ 	jal	gfxAllocate
/*  f0188e8:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f0188ec:	8fb90160 */ 	lw	$t9,0x160($sp)
/*  f0188f0:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f0188f4:	3c018006 */ 	lui	$at,%hi(g_PdLogoAmbientLightFrac)
/*  f0188f8:	af220004 */ 	sw	$v0,0x4($t9)
/*  f0188fc:	44809000 */ 	mtc1	$zero,$f18
/*  f018900:	c42827c8 */ 	lwc1	$f8,%lo(g_PdLogoAmbientLightFrac)($at)
/*  f018904:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f018908:	3c0e8000 */ 	lui	$t6,0x8000
/*  f01890c:	4608903c */ 	c.lt.s	$f18,$f8
/*  f018910:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f018914:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f018918:	3c180386 */ 	lui	$t8,0x386
/*  f01891c:	45000016 */ 	bc1f	.L0f018978
/*  f018920:	3c0fb800 */ 	lui	$t7,0xb800
/*  f018924:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f018928:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f01892c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f018930:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f018934:	37180010 */ 	ori	$t8,$t8,0x10
/*  f018938:	3c198006 */ 	lui	$t9,%hi(var80062560+0x8)
/*  f01893c:	27392568 */ 	addiu	$t9,$t9,%lo(var80062560+0x8)
/*  f018940:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f018944:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f018948:	3c0e8006 */ 	lui	$t6,%hi(var80062560)
/*  f01894c:	3c0f0388 */ 	lui	$t7,0x388
/*  f018950:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f018954:	25ce2560 */ 	addiu	$t6,$t6,%lo(var80062560)
/*  f018958:	acee0004 */ 	sw	$t6,0x4($a3)
/*  f01895c:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f018960:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018964:	3c180601 */ 	lui	$t8,0x601
/*  f018968:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f01896c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f018970:	10000003 */ 	b	.L0f018980
/*  f018974:	ac790004 */ 	sw	$t9,0x4($v1)
.L0f018978:
/*  f018978:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f01897c:	ac400004 */ 	sw	$zero,0x4($v0)
.L0f018980:
/*  f018980:	8fae022c */ 	lw	$t6,0x22c($sp)
/*  f018984:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f018988:	0c006a47 */ 	jal	modelGetPart
/*  f01898c:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f018990:	10400037 */ 	beqz	$v0,.L0f018a70
/*  f018994:	00402825 */ 	or	$a1,$v0,$zero
/*  f018998:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f01899c:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f0189a0:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f0189a4:	84d90010 */ 	lh	$t9,0x10($a2)
/*  f0189a8:	03197821 */ 	addu	$t7,$t8,$t9
/*  f0189ac:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f0189b0:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f0189b4:	8fb800d8 */ 	lw	$t8,0xd8($sp)
/*  f0189b8:	94d90016 */ 	lhu	$t9,0x16($a2)
/*  f0189bc:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f0189c0:	03197821 */ 	addu	$t7,$t8,$t9
/*  f0189c4:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f0189c8:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0189cc:	afae00d8 */ 	sw	$t6,0xd8($sp)
/*  f0189d0:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0189d4:	0fc59e7d */ 	jal	gfxAllocate
/*  f0189d8:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f0189dc:	8fb80160 */ 	lw	$t8,0x160($sp)
/*  f0189e0:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f0189e4:	3c018006 */ 	lui	$at,%hi(g_PdLogoAmbientLightFrac)
/*  f0189e8:	af020004 */ 	sw	$v0,0x4($t8)
/*  f0189ec:	44809000 */ 	mtc1	$zero,$f18
/*  f0189f0:	c42a27c8 */ 	lwc1	$f10,%lo(g_PdLogoAmbientLightFrac)($at)
/*  f0189f4:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0189f8:	3c0f8000 */ 	lui	$t7,0x8000
/*  f0189fc:	460a903c */ 	c.lt.s	$f18,$f10
/*  f018a00:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f018a04:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f018a08:	3c0e0386 */ 	lui	$t6,0x386
/*  f018a0c:	45000016 */ 	bc1f	.L0f018a68
/*  f018a10:	3c19b800 */ 	lui	$t9,0xb800
/*  f018a14:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f018a18:	37390002 */ 	ori	$t9,$t9,0x2
/*  f018a1c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018a20:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f018a24:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018a28:	3c188006 */ 	lui	$t8,%hi(var80062560+0x8)
/*  f018a2c:	27182568 */ 	addiu	$t8,$t8,%lo(var80062560+0x8)
/*  f018a30:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f018a34:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f018a38:	3c0f8006 */ 	lui	$t7,%hi(var80062560)
/*  f018a3c:	3c190388 */ 	lui	$t9,0x388
/*  f018a40:	37390010 */ 	ori	$t9,$t9,0x10
/*  f018a44:	25ef2560 */ 	addiu	$t7,$t7,%lo(var80062560)
/*  f018a48:	acef0004 */ 	sw	$t7,0x4($a3)
/*  f018a4c:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f018a50:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018a54:	3c0e0601 */ 	lui	$t6,0x601
/*  f018a58:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f018a5c:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f018a60:	10000003 */ 	b	.L0f018a70
/*  f018a64:	ac780004 */ 	sw	$t8,0x4($v1)
.L0f018a68:
/*  f018a68:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018a6c:	ac400004 */ 	sw	$zero,0x4($v0)
.L0f018a70:
/*  f018a70:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f018a74:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f018a78:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f018a7c:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f018a80:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f018a84:	3c013f80 */ 	lui	$at,0x3f80
/*  f018a88:	44812000 */ 	mtc1	$at,$f4
/*  f018a8c:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f018a90:	3c068006 */ 	lui	$a2,%hi(var80062804)
/*  f018a94:	3c078006 */ 	lui	$a3,%hi(g_PdLogoFrac)
/*  f018a98:	240f00f0 */ 	addiu	$t7,$zero,0xf0
/*  f018a9c:	27ae0270 */ 	addiu	$t6,$sp,0x270
/*  f018aa0:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f018aa4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f018aa8:	8ce727bc */ 	lw	$a3,%lo(g_PdLogoFrac)($a3)
/*  f018aac:	8cc62804 */ 	lw	$a2,%lo(var80062804)($a2)
/*  f018ab0:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018ab4:	8fa5022c */ 	lw	$a1,0x22c($sp)
/*  f018ab8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f018abc:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018ac0:	0fc05c92 */ 	jal	titleRenderPdLogoModel
/*  f018ac4:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f018ac8:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f018acc:	3c0f8000 */ 	lui	$t7,0x8000
/*  f018ad0:	3c0e0386 */ 	lui	$t6,0x386
/*  f018ad4:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018ad8:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f018adc:	37390002 */ 	ori	$t9,$t9,0x2
/*  f018ae0:	3c188006 */ 	lui	$t8,%hi(var80062578+0x8)
/*  f018ae4:	27182580 */ 	addiu	$t8,$t8,%lo(var80062578+0x8)
/*  f018ae8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018aec:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f018af0:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f018af4:	24590018 */ 	addiu	$t9,$v0,0x18
/*  f018af8:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f018afc:	afb90330 */ 	sw	$t9,0x330($sp)
/*  f018b00:	3c0e8006 */ 	lui	$t6,%hi(var80062578)
/*  f018b04:	3c0f0388 */ 	lui	$t7,0x388
/*  f018b08:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f018b0c:	25ce2578 */ 	addiu	$t6,$t6,%lo(var80062578)
/*  f018b10:	3c188006 */ 	lui	$t8,%hi(var80062858)
/*  f018b14:	ac4e0014 */ 	sw	$t6,0x14($v0)
/*  f018b18:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f018b1c:	27182858 */ 	addiu	$t8,$t8,%lo(var80062858)
/*  f018b20:	8f010000 */ 	lw	$at,0x0($t8)
/*  f018b24:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f018b28:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018b2c:	ac810000 */ 	sw	$at,0x0($a0)
/*  f018b30:	8f0f0004 */ 	lw	$t7,0x4($t8)
/*  f018b34:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f018b38:	8f010008 */ 	lw	$at,0x8($t8)
/*  f018b3c:	0c0059b7 */ 	jal	mtx4LoadTranslation
/*  f018b40:	ac810008 */ 	sw	$at,0x8($a0)
/*  f018b44:	3c013f80 */ 	lui	$at,0x3f80
/*  f018b48:	44813000 */ 	mtc1	$at,$f6
/*  f018b4c:	c7a8013c */ 	lwc1	$f8,0x13c($sp)
/*  f018b50:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018b54:	0c0057e2 */ 	jal	mtx00015f88
/*  f018b58:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f018b5c:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f018b60:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018b64:	0c005680 */ 	jal	mtx4MultMtx4
/*  f018b68:	27a60230 */ 	addiu	$a2,$sp,0x230
/*  f018b6c:	3c017f1b */ 	lui	$at,%hi(var7f1a8468)
/*  f018b70:	c42c8468 */ 	lwc1	$f12,%lo(var7f1a8468)($at)
/*  f018b74:	0c0057c1 */ 	jal	mtx00015f04
/*  f018b78:	27a50230 */ 	addiu	$a1,$sp,0x230
/*  f018b7c:	3c028006 */ 	lui	$v0,%hi(g_PdLogoTitleStep)
/*  f018b80:	8c4227f8 */ 	lw	$v0,%lo(g_PdLogoTitleStep)($v0)
/*  f018b84:	27a30230 */ 	addiu	$v1,$sp,0x230
/*  f018b88:	04420085 */ 	bltzl	$v0,.L0f018da0
/*  f018b8c:	8fa20330 */ 	lw	$v0,0x330($sp)
/*  f018b90:	10400082 */ 	beqz	$v0,.L0f018d9c
/*  f018b94:	24010001 */ 	addiu	$at,$zero,0x1
/*  f018b98:	1441001f */ 	bne	$v0,$at,.L0f018c18
/*  f018b9c:	3c058006 */ 	lui	$a1,%hi(g_TitleModelPdThree)
/*  f018ba0:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f018ba4:	c42027f4 */ 	lwc1	$f0,%lo(g_PdLogoTitleStepFrac)($at)
/*  f018ba8:	3c013f00 */ 	lui	$at,0x3f00
/*  f018bac:	44815000 */ 	mtc1	$at,$f10
/*  f018bb0:	44070000 */ 	mfc1	$a3,$f0
/*  f018bb4:	00003025 */ 	or	$a2,$zero,$zero
/*  f018bb8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f018bbc:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018bc0:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018bc4:	3c02800a */ 	lui	$v0,%hi(var8009ccb8)
/*  f018bc8:	45000002 */ 	bc1f	.L0f018bd4
/*  f018bcc:	3c18800a */ 	lui	$t8,%hi(var8009cca8)
/*  f018bd0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f018bd4:
/*  f018bd4:	8c42ccb8 */ 	lw	$v0,%lo(var8009ccb8)($v0)
/*  f018bd8:	3c0f800a */ 	lui	$t7,%hi(var8009ccb0)
/*  f018bdc:	8ca5250c */ 	lw	$a1,%lo(g_TitleModelPdThree)($a1)
/*  f018be0:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018be4:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018be8:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018bec:	8defccb0 */ 	lw	$t7,%lo(var8009ccb0)($t7)
/*  f018bf0:	8f18cca8 */ 	lw	$t8,%lo(var8009cca8)($t8)
/*  f018bf4:	03201025 */ 	or	$v0,$t9,$zero
/*  f018bf8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018bfc:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f018c00:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018c04:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018c08:	0fc05c92 */ 	jal	titleRenderPdLogoModel
/*  f018c0c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018c10:	10000062 */ 	b	.L0f018d9c
/*  f018c14:	afa20330 */ 	sw	$v0,0x330($sp)
.L0f018c18:
/*  f018c18:	24010002 */ 	addiu	$at,$zero,0x2
/*  f018c1c:	14410023 */ 	bne	$v0,$at,.L0f018cac
/*  f018c20:	3c058006 */ 	lui	$a1,%hi(g_TitleModelPdTwo)
/*  f018c24:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f018c28:	c42027f4 */ 	lwc1	$f0,%lo(g_PdLogoTitleStepFrac)($at)
/*  f018c2c:	3c013f00 */ 	lui	$at,0x3f00
/*  f018c30:	44812000 */ 	mtc1	$at,$f4
/*  f018c34:	3c013f80 */ 	lui	$at,0x3f80
/*  f018c38:	44813000 */ 	mtc1	$at,$f6
/*  f018c3c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f018c40:	00003025 */ 	or	$a2,$zero,$zero
/*  f018c44:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018c48:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018c4c:	45000002 */ 	bc1f	.L0f018c58
/*  f018c50:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f018c54:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f018c58:
/*  f018c58:	3c02800a */ 	lui	$v0,%hi(var8009ccb8)
/*  f018c5c:	8c42ccb8 */ 	lw	$v0,%lo(var8009ccb8)($v0)
/*  f018c60:	3c18800a */ 	lui	$t8,%hi(var8009cca8)
/*  f018c64:	3c0f800a */ 	lui	$t7,%hi(var8009ccb0)
/*  f018c68:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018c6c:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018c70:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018c74:	8defccb0 */ 	lw	$t7,%lo(var8009ccb0)($t7)
/*  f018c78:	8f18cca8 */ 	lw	$t8,%lo(var8009cca8)($t8)
/*  f018c7c:	44815000 */ 	mtc1	$at,$f10
/*  f018c80:	44074000 */ 	mfc1	$a3,$f8
/*  f018c84:	8ca52508 */ 	lw	$a1,%lo(g_TitleModelPdTwo)($a1)
/*  f018c88:	03201025 */ 	or	$v0,$t9,$zero
/*  f018c8c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018c90:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018c94:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018c98:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018c9c:	0fc05c92 */ 	jal	titleRenderPdLogoModel
/*  f018ca0:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f018ca4:	1000003d */ 	b	.L0f018d9c
/*  f018ca8:	afa20330 */ 	sw	$v0,0x330($sp)
.L0f018cac:
/*  f018cac:	24010003 */ 	addiu	$at,$zero,0x3
/*  f018cb0:	14410022 */ 	bne	$v0,$at,.L0f018d3c
/*  f018cb4:	3c058006 */ 	lui	$a1,%hi(g_TitleModelPdTwo)
/*  f018cb8:	3c018006 */ 	lui	$at,%hi(g_PdLogoTitleStepFrac)
/*  f018cbc:	c42027f4 */ 	lwc1	$f0,%lo(g_PdLogoTitleStepFrac)($at)
/*  f018cc0:	3c013f00 */ 	lui	$at,0x3f00
/*  f018cc4:	44812000 */ 	mtc1	$at,$f4
/*  f018cc8:	44070000 */ 	mfc1	$a3,$f0
/*  f018ccc:	00003025 */ 	or	$a2,$zero,$zero
/*  f018cd0:	4604003c */ 	c.lt.s	$f0,$f4
/*  f018cd4:	3c058006 */ 	lui	$a1,%hi(g_TitleModelPdTwo)
/*  f018cd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f018cdc:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018ce0:	45000002 */ 	bc1f	.L0f018cec
/*  f018ce4:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018ce8:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f018cec:
/*  f018cec:	3c02800a */ 	lui	$v0,%hi(var8009ccb8)
/*  f018cf0:	8c42ccb8 */ 	lw	$v0,%lo(var8009ccb8)($v0)
/*  f018cf4:	3c18800a */ 	lui	$t8,%hi(var8009cca8)
/*  f018cf8:	3c0f800a */ 	lui	$t7,%hi(var8009ccb0)
/*  f018cfc:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018d00:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018d04:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018d08:	8defccb0 */ 	lw	$t7,%lo(var8009ccb0)($t7)
/*  f018d0c:	8f18cca8 */ 	lw	$t8,%lo(var8009cca8)($t8)
/*  f018d10:	44813000 */ 	mtc1	$at,$f6
/*  f018d14:	8ca52508 */ 	lw	$a1,%lo(g_TitleModelPdTwo)($a1)
/*  f018d18:	03201025 */ 	or	$v0,$t9,$zero
/*  f018d1c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018d20:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018d24:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018d28:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018d2c:	0fc05c92 */ 	jal	titleRenderPdLogoModel
/*  f018d30:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f018d34:	10000019 */ 	b	.L0f018d9c
/*  f018d38:	afa20330 */ 	sw	$v0,0x330($sp)
.L0f018d3c:
/*  f018d3c:	3c02800a */ 	lui	$v0,%hi(var8009ccb8)
/*  f018d40:	8c42ccb8 */ 	lw	$v0,%lo(var8009ccb8)($v0)
/*  f018d44:	3c18800a */ 	lui	$t8,%hi(var8009cca8)
/*  f018d48:	3c0f800a */ 	lui	$t7,%hi(var8009ccb0)
/*  f018d4c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018d50:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018d54:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018d58:	3c013f80 */ 	lui	$at,0x3f80
/*  f018d5c:	44814000 */ 	mtc1	$at,$f8
/*  f018d60:	8defccb0 */ 	lw	$t7,%lo(var8009ccb0)($t7)
/*  f018d64:	8f18cca8 */ 	lw	$t8,%lo(var8009cca8)($t8)
/*  f018d68:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018d6c:	8ca52508 */ 	lw	$a1,%lo(g_TitleModelPdTwo)($a1)
/*  f018d70:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018d74:	03201025 */ 	or	$v0,$t9,$zero
/*  f018d78:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018d7c:	00003025 */ 	or	$a2,$zero,$zero
/*  f018d80:	3c073f80 */ 	lui	$a3,0x3f80
/*  f018d84:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018d88:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018d8c:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f018d90:	0fc05c92 */ 	jal	titleRenderPdLogoModel
/*  f018d94:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018d98:	afa20330 */ 	sw	$v0,0x330($sp)
.L0f018d9c:
/*  f018d9c:	8fa20330 */ 	lw	$v0,0x330($sp)
.L0f018da0:
/*  f018da0:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f018da4:
/*  f018da4:	27bd0330 */ 	addiu	$sp,$sp,0x330
/*  f018da8:	03e00008 */ 	jr	$ra
/*  f018dac:	00000000 */ 	nop
);
#endif

u32 var80062818 = 0x00000000;
u32 var8006281c = 0x00000001;
u32 var80062820 = 0x00000003;
u32 var80062824 = 0x00000000;
u32 var80062828 = 0x00000000;
u32 var8006282c = 0x00000000;
u32 var80062830 = 0x00000000;
u32 var80062834 = 0x00000000;
u32 var80062838 = 0x00000000;
u32 var8006283c = 0x00000000;
u32 var80062840 = 0x00000000;
u32 var80062844 = 0x00000000;
u32 var80062848 = 0x00000000;
u32 var8006284c = 0x00000000;
u32 var80062850 = 0x00000000;
u32 var80062854 = 0x00000000;

u32 var80062858 = 0x00000000;
u32 var8006285c = 0x00000000;
f32 var80062860 = 1000;

// Mismatch: first tick assignments need to be permutated
//Gfx *titleRenderPdLogo(Gfx *gdl)
//{
//	struct modelrenderdata renderdata = { NULL, true, 3 }; // 2f0
//	Mtxf sp2b0;
//	Mtxf sp270;
//	Mtxf sp230;
//	struct model *model; // 22c
//	Mtxf sp1e8;
//	Mtxf sp1a8;
//	struct modelnode *node;
//	struct modelrodata_dl *rodata; // 164
//	struct modelrwdata_dl *rwdata; // 160
//	f32 sp13c = g_TitleTimer / 4500.0f - 0.1f;
//	LookAt *lookat; // 134
//	Mtx spf0;
//	f32 spe4;
//	f32 spe0;
//	s32 numvertices; // dc
//	s32 numcolours; // d8
//
//	// b74
//	if (g_PdLogoIsFirstTick) {
//		g_PdLogoYRotCur = 4.2404751777649f;
//		g_PdLogoYRotSpeed = 0.018846554681659f;
//		g_PdLogoXRotCur = 0.47116386890411f;
//		g_PdLogoXRotSpeed = 0.0f;
//		g_PdLogoScale = 0.35f;
//		g_PdLogoFrac = 0.0f;
//		g_PdLogoUseCombinedModel = false;
//		g_PdLogoAmbientLightFrac = 1.0f;
//		g_PdLogoIsFirstTick = false;
//		g_PdLogoBlackTimer = 1;
//		g_PdLogoYRotEnabled = false;
//		g_PdLogoPreMorphTimer = 0;
//		g_PdLogoMorphing = false;
//		g_PdLogoExitTimer = 0;
//		g_PdLogoMorphEndTimer = 0;
//		g_PdLogoYRotStopping = false;
//		g_PdLogoDarkenEnabled = false;
//		var80062804 = 1;
//		g_PdLogoPointlessTimerEnabled = false;
//		g_PdLogoPreTitleTimer = 0;
//		g_PdLogoTitleStepFrac = 0.0f;
//		g_PdLogoTitlePresenting = false;
//		g_PdLogoTitleStep = -1;
//		g_PdLogoPointlessTimer = 0;
//		g_PdLogoUnusedRotEnabled = false;
//		g_PdLogoUnusedRot = 1.5705462694168f;
//		g_PdLogoLightMoving = false;
//		g_PdLogoLightDirFrac = 0.0f;
//	}
//
//	// c7c
//	if (g_PdLogoBlackTimer != 0) {
//		g_PdLogoBlackTimer++;
//
//		if (g_PdLogoBlackTimer >= 4) {
//			g_PdLogoBlackTimer = 0;
//			g_PdLogoYRotEnabled = true;
//			g_PdLogoPreMorphTimer = 1;
//		}
//	}
//
//	// ce4
//	if (g_PdLogoYRotStopping) {
//		if (g_PdLogoYRotCur < g_PdLogoEndYRot) {
//			applySpeed(&g_PdLogoYRotCur, g_PdLogoEndYRot, &g_PdLogoYRotSpeed, 0.00018846555030905f, 0.00018846555030905f, 0.018846554681659f);
//
//			if (g_PdLogoYRotCur >= g_PdLogoEndYRot) {
//				g_PdLogoYRotCur = g_PdLogoEndYRot;
//				g_PdLogoYRotSpeed = 0.0f;
//			}
//
//			if (g_PdLogoYRotCur >= M_BADTAU) {
//				g_PdLogoYRotCur -= M_BADTAU;
//				g_PdLogoEndYRot -= M_BADTAU;
//			} else if (g_PdLogoYRotCur < 0.0f) {
//				g_PdLogoYRotCur += M_BADTAU;
//				g_PdLogoEndYRot += M_BADTAU;
//			}
//		}
//
//		if (g_PdLogoYRotCur >= g_PdLogoEndYRot) {
//			g_PdLogoYRotStopping = false;
//		}
//	} else /*e18*/ if (g_PdLogoYRotEnabled) {
//		g_PdLogoYRotCur += g_PdLogoYRotSpeed * g_Vars.lvupdate240freal;
//
//		if (g_PdLogoYRotCur >= M_BADTAU) {
//			g_PdLogoYRotCur -= M_BADTAU;
//		} else if (g_PdLogoYRotCur < 0.0f) {
//			g_PdLogoYRotCur += M_BADTAU;
//		}
//	}
//
//	// e90
//	if (g_PdLogoPreMorphTimer != 0) {
//		s32 duration = 80;
//
//		g_PdLogoPreMorphTimer += g_Vars.lvupdate240_60;
//
//		if (g_PdLogoPreMorphTimer > 0) {
//			g_PdLogoFrac = (f32) g_PdLogoPreMorphTimer / (f32) duration;
//		} else {
//			g_PdLogoFrac = 0.0f;
//		}
//
//		if (g_PdLogoPreMorphTimer > duration) {
//			g_PdLogoPreMorphTimer = 0;
//			g_PdLogoMorphing = true;
//			g_PdLogoFrac = 0.0f;
//			g_PdLogoUseCombinedModel = true;
//		}
//	}
//
//	// f14
//	if (g_PdLogoMorphing) {
//		g_PdLogoFrac += 0.004f * g_Vars.lvupdate240freal;
//
//		if (g_PdLogoFrac >= 0.8f) {
//			if (g_PdLogoMorphEndTimer == 0) {
//				g_PdLogoMorphEndTimer = 1;
//			}
//		}
//
//		if (g_PdLogoFrac >= 1.0f) {
//			g_PdLogoFrac = 1.0f;
//			g_PdLogoMorphing = false;
//		}
//	}
//
//	// f80
//	if (g_PdLogoMorphEndTimer != 0) {
//		g_PdLogoMorphEndTimer += g_Vars.lvupdate240_60;
//
//		if (g_PdLogoXRotCur > 0.0f) {
//			// Implement the camera lowering effect, but it's actually
//			// the model that rotates upwards to face the camera
//			applyRotation(&g_PdLogoXRotCur, 0.0f, &g_PdLogoXRotSpeed, 0.00011307933164062f, 0.00011307933164062f, 0.011307933367789f);
//
//			if (g_PdLogoXRotCur <= 0.0f) {
//				g_PdLogoXRotCur = 0.0f;
//				g_PdLogoXRotSpeed = 0.0f;
//			}
//		}
//
//		if (g_PdLogoMorphEndTimer > 30 && g_PdLogoMorphEndTimer - g_Vars.lvupdate240_60 <= 30) {
//			// Start slowing the spinning rotation
//			g_PdLogoYRotEnabled = false;
//			g_PdLogoYRotStopping = true;
//			g_PdLogoEndYRot = ((s32) (g_PdLogoYRotCur * 4.0f / M_BADTAU) + 2) * M_BADTAU * 0.25f;
//		}
//
//		if (g_PdLogoMorphEndTimer > 100 && g_PdLogoMorphEndTimer - g_Vars.lvupdate240_60 <= 100) {
//			g_PdLogoDarkenEnabled = true;
//		}
//
//		if (!g_PdLogoYRotStopping && g_PdLogoXRotCur <= 0.0f) {
//			// Spinning has stopped and model is also facing camera vertically
//			g_PdLogoMorphEndTimer = 0;
//			g_PdLogoDarkenEnabled = true;
//		}
//	}
//
//	// 118
//	if (g_PdLogoDarkenEnabled) {
//		// Fading out the side and back faces of the logo...
//		// This is done by adjusting the ambient lighting. I guess the front
//		// face is excluded from ambient light?
//		g_PdLogoAmbientLightFrac -= 0.0075f * g_Vars.lvupdate240freal;
//
//		if (g_PdLogoAmbientLightFrac <= 0.0f) {
//			g_PdLogoAmbientLightFrac = 0.0f;
//			g_PdLogoDarkenEnabled = false;
//			g_PdLogoPreTitleTimer = 1;
//		}
//	}
//
//	// 178
//	if (g_PdLogoPreTitleTimer != 0) {
//		g_PdLogoPreTitleTimer += g_Vars.lvupdate240_60;
//
//		if (g_PdLogoPreTitleTimer > 20) {
//			g_PdLogoPreTitleTimer = 0;
//			g_PdLogoPointlessTimerEnabled = true;
//		}
//	}
//
//	// 1a8
//	if (g_PdLogoPointlessTimerEnabled) {
//		g_PdLogoPointlessTimerEnabled = false;
//		g_PdLogoPointlessTimer = 1;
//	}
//
//	// 1c4
//	if (g_PdLogoPointlessTimer != 0) {
//		g_PdLogoPointlessTimer += g_Vars.lvupdate240_60;
//
//		if (g_PdLogoPointlessTimer > 0) {
//			g_PdLogoPointlessTimer = 0;
//			g_PdLogoTitlePresenting = true;
//			g_PdLogoTitleStep = 1;
//			g_PdLogoLightMoving = true;
//		}
//	}
//
//	// 208
//	if (g_PdLogoTitlePresenting) {
//		g_PdLogoUnusedRotEnabled = true;
//
//		if (g_PdLogoTitleStep == 0) {
//			// Unreachable - step 0 is not used
//			g_PdLogoTitleStepFrac += 0.025f;
//		} else if (g_PdLogoTitleStep == 1) {
//			g_PdLogoTitleStepFrac += 0.09f;
//		} else {
//			g_PdLogoTitleStepFrac += 0.1f;
//		}
//
//		if (g_PdLogoTitleStepFrac >= 1.0f) {
//			g_PdLogoTitleStepFrac = 0.0f;
//			g_PdLogoTitleStep++;
//
//			if (g_PdLogoTitleStep == 10) {
//				g_PdLogoTitlePresenting = false;
//				g_PdLogoExitTimer = 1;
//			}
//		}
//	}
//
//	// 2d4
//	if (g_PdLogoUnusedRotEnabled) {
//		// Some unused value... maybe a different method of rotating the light?
//		g_PdLogoUnusedRot += 0.0062821852043271f * g_Vars.lvupdate240freal;
//
//		if (g_PdLogoUnusedRot >= M_BADTAU) {
//			g_PdLogoUnusedRot -= M_BADTAU;
//		}
//	}
//
//	// 32c
//	if (g_PdLogoLightMoving) {
//		g_PdLogoLightDirFrac += 0.017f * g_Vars.lvupdate240freal;
//
//		if (g_PdLogoLightDirFrac >= 1.0f) {
//			g_PdLogoLightDirFrac = 1.0f;
//			g_PdLogoLightMoving = false;
//		}
//	}
//
//	// 380
//	if (g_PdLogoExitTimer != 0) {
//		g_PdLogoExitTimer += g_Vars.lvupdate240_60;
//
//		if (g_PdLogoExitTimer > 60) {
//			g_PdLogoExitTimer = 0;
//			g_PdLogoTriggerExit = true;
//		}
//	}
//
//	// 3b0
//	gdl = viSetFillColour(gdl, 0, 0, 0);
//	gdl = viFillBuffer(gdl);
//
//	if (g_PdLogoBlackTimer != 0) {
//		return gdl;
//	}
//
//	lookat = gfxAllocateLookAt(2);
//
//	guLookAtReflect(&spf0, lookat,
//			0.0f, 0.0f, 4000.0f,
//			0.0f, 0.0f, 0.0f,
//			0.0f, 1.0f, 0.0f);
//
//	gSPLookAt(gdl++, lookat);
//
//	spe4 = (g_PdLogoLightDirFrac + -1.0f) * M_PI + M_PI;
//	spe0 = (0.0f - 0.15f * g_PdLogoLightDirFrac) * M_PI + M_PI;
//
//	var80062578.a.l.colc[0] = var80062578.a.l.colc[1] = var80062578.a.l.colc[2] = 0;
//	var80062578.a.l.col[0] = var80062578.a.l.col[1] = var80062578.a.l.col[2] = 0;
//	var80062578.l[0].l.colc[0] = var80062578.l[0].l.colc[1] = var80062578.l[0].l.colc[2] = 255;
//	var80062578.l[0].l.col[0] = var80062578.l[0].l.col[1] = var80062578.l[0].l.col[2] = 255;
//
//	var80062578.l[0].l.dir[0] = 127.0f * sinf(spe4) * cosf(spe0);
//	var80062578.l[0].l.dir[1] = 127.0f * sinf(spe0);
//	var80062578.l[0].l.dir[2] = 127.0f * cosf(spe4) * cosf(spe0);
//
//	mtx00016ae4(&sp2b0,
//			0.0f, 0.0f, 4000,
//			0.0f, 0.0f, 0.0f,
//			0.0f, 1.0f, 0.0f);
//
//	if (g_PdLogoUseCombinedModel == true) {
//		model = g_TitleModel;
//	} else {
//		model = g_TitleModelNLogo2;
//	}
//
//	mtx4LoadYRotation(g_PdLogoYRotCur, &sp1e8);
//	mtx4LoadXRotation(g_PdLogoXRotCur, &sp1a8);
//	mtx4MultMtx4InPlace(&sp1a8, &sp1e8);
//	mtx4MultMtx4(&sp2b0, &sp1e8, &sp270);
//	mtx00015f04(g_PdLogoScale, &sp270);
//
//	var80062560.a.l.colc[0] = var80062560.a.l.colc[1] = var80062560.a.l.colc[2] = 255.0f * g_PdLogoAmbientLightFrac;
//	var80062560.a.l.col[0] = var80062560.a.l.col[1] = var80062560.a.l.col[2] = 255.0f * g_PdLogoAmbientLightFrac;
//
//	numvertices = 0;
//	numcolours = 0;
//
//	node = modelGetPart(model->filedata, MODELPART_LOGO_0002);
//
//	if (node) {
//		Gfx *tmp;
//
//		rodata = &node->rodata->dl;
//		numvertices += rodata->numvertices + 1;
//		numcolours += rodata->numcolours + 1;
//
//		rwdata = modelGetNodeRwData(model, node);
//		rwdata->gdl = tmp = gfxAllocate(5 * sizeof(Gfx));
//
//		gSPSetLights1(tmp++, var80062530);
//		gSPBranchList(tmp++, rodata->primary);
//	}
//
//	node = modelGetPart(model->filedata, MODELPART_LOGO_0004);
//
//	if (node) {
//		Gfx *tmp;
//
//		rodata = &node->rodata->dl;
//		numvertices += rodata->numvertices + 1;
//		numcolours += rodata->numcolours + 1;
//
//		rwdata = modelGetNodeRwData(model, node);
//		rwdata->gdl = tmp = gfxAllocate(5 * sizeof(Gfx));
//
//		if (g_PdLogoAmbientLightFrac > 0.0f) {
//			gSPSetLights1(tmp++, var80062560);
//			gSPBranchList(tmp++, rodata->primary);
//		} else {
//			gSPEndDisplayList(tmp++);
//		}
//	}
//
//	node = modelGetPart(model->filedata, MODELPART_LOGO_0006);
//
//	if (node) {
//		Gfx *tmp;
//
//		rodata = &node->rodata->dl;
//		numvertices += rodata->numvertices + 1;
//		numcolours += rodata->numcolours + 1;
//
//		rwdata = modelGetNodeRwData(model, node);
//		rwdata->gdl = tmp = gfxAllocate(5 * sizeof(Gfx));
//
//		if (g_PdLogoAmbientLightFrac > 0.0f) {
//			gSPSetLights1(tmp++, var80062560);
//			gSPBranchList(tmp++, rodata->primary);
//		} else {
//			gSPEndDisplayList(tmp++);
//		}
//	}
//
//	node = modelGetPart(model->filedata, MODELPART_LOGO_0008);
//
//	if (node) {
//		Gfx *tmp;
//
//		rodata = &node->rodata->dl;
//		numvertices += rodata->numvertices + 1;
//		numcolours += rodata->numcolours + 1;
//
//		rwdata = modelGetNodeRwData(model, node);
//		rwdata->gdl = tmp = gfxAllocate(5 * sizeof(Gfx));
//
//		if (g_PdLogoAmbientLightFrac > 0.0f) {
//			gSPSetLights1(tmp++, var80062560);
//			gSPBranchList(tmp++, rodata->primary);
//		} else {
//			gSPEndDisplayList(tmp++);
//		}
//	}
//
//	gdl = titleRenderPdLogoModel(gdl, model, var80062804, g_PdLogoFrac, 240, 1.0f, &sp270, gfxAllocateVertices(numvertices), gfxAllocateColours(numcolours));
//
//	gSPSetLights1(gdl++, var80062578);
//
//	{
//		struct coord sp64 = {0, 0, 1000};
//
//		mtx4LoadTranslation(&sp64, &sp1e8);
//		mtx00015f88(1.0f + sp13c, &sp1e8);
//		mtx4MultMtx4(&sp2b0, &sp1e8, &sp230);
//		mtx00015f04(0.308f, &sp230);
//
//		if (g_PdLogoTitleStep >= 0) {
//			if (g_PdLogoTitleStep == 0) {
//				// empty
//			} else if (g_PdLogoTitleStep == 1) {
//				f32 frac = g_PdLogoTitleStepFrac;
//				s32 a2 = g_PdLogoTitleStepFrac < 0.5f;
//
//				gdl = titleRenderPdLogoModel(gdl, g_TitleModelPdThree, a2, frac, 255, frac, &sp230, var8009cca8[var8009ccb8], var8009ccb0[var8009ccb8]);
//			} else if (g_PdLogoTitleStep == 2) {
//				f32 frac = g_PdLogoTitleStepFrac;
//				s32 a2 = g_PdLogoTitleStepFrac < 0.5f;
//
//				gdl = titleRenderPdLogoModel(gdl, g_TitleModelPdTwo, a2, 1.0f - frac, 255, 1.0f, &sp230, var8009cca8[var8009ccb8], var8009ccb0[var8009ccb8]);
//			} else if (g_PdLogoTitleStep == 3) {
//				f32 frac = g_PdLogoTitleStepFrac;
//				s32 a2 = g_PdLogoTitleStepFrac < 0.5f;
//
//				gdl = titleRenderPdLogoModel(gdl, g_TitleModelPdTwo, a2, frac, 255, 1.0f, &sp230, var8009cca8[var8009ccb8], var8009ccb0[var8009ccb8]);
//			} else {
//				gdl = titleRenderPdLogoModel(gdl, g_TitleModelPdTwo, 0, 1.0f, 255, 1.0f, &sp230, var8009cca8[var8009ccb8], var8009ccb0[var8009ccb8]);
//			}
//		}
//	}
//
//	return gdl;
//}

struct sndstate *g_TitleAudioHandle = NULL;
bool g_TitleTypewriterFinishing = false;

void titleInitRarePresents(void)
{
	g_TitleTimer = 0;
	joy00014810(false);
	g_TitleAudioHandle = NULL;
}

void titleExitRarePresents(void)
{
	if (g_TitleAudioHandle) {
		audioStop(g_TitleAudioHandle);
	}

	g_TitleAudioHandle = NULL;
	joy00014810(true);
}

void titleTickRarePresents(void)
{
	viSetFovY(60);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	viSetUseZBuf(false);

	g_TitleTimer += g_Vars.lvupdate240_60;

	if (g_TitleTimer > TICKS(300)) {
		titleSetNextMode(TITLEMODE_PDLOGO);
	} else if (joyGetButtonsPressedThisFrame(0, 0xffff)) {
		titleSetNextMode(TITLEMODE_SKIP);
	}
}

Gfx *titleRenderTypewriterText(Gfx *gdl, s32 *x, s32 *y, u16 textnum, s32 timer, s32 *colourcomponent)
{
	s32 lentoprint = timer / 3;
	char *text = langGet(textnum);
	s32 i;
	u8 buffer[] = {'\0', '\0'};
	s32 fulllen = strlen(text);

	if (lentoprint <= 0) {
		return gdl;
	}

	if (lentoprint > fulllen) {
		lentoprint = fulllen;
	}

	for (i = 0; i < lentoprint; i++) {
		s32 remaining = timer - 3 * i;
		s32 tmp;

		if (remaining > 60) {
			remaining = 60;
		}

		if (remaining < 10) {
			g_TitleTypewriterFinishing = true;
		}

		*colourcomponent = tmp = (60 - remaining) * 255 / 60;

		buffer[0] = text[i];
		gdl = textRenderProjected(gdl, x, y, buffer, g_CharsHandelGothicLg, g_FontHandelGothicLg,
				0x7f7fffff | (tmp << 8) | (tmp << 16), viGetWidth(), viGetHeight(), 0, 0);
	}

	return gdl;
}

Gfx *titleRenderRarePresents(Gfx *gdl)
{
	s32 x;
	s32 y;
	s32 colourcomponent = 255;

	gdl = func0f01afc0(gdl);
	gdl = func0f153628(gdl);

	x = viGetViewLeft() + 50;
	y = viGetViewTop() + viGetViewHeight() - 80;

	g_TitleTypewriterFinishing = false;

	if (g_TitleMode == TITLEMODE_RAREPRESENTS1) {
		gdl = titleRenderTypewriterText(gdl, &x, &y, L_OPTIONS_005, g_TitleTimer, &colourcomponent); // "earth:"

		if (g_TitleTimer > 70) {
			x = viGetViewLeft() + 50;
			y = viGetViewTop() + viGetViewHeight() - 60;
			gdl = titleRenderTypewriterText(gdl, &x, &y, L_OPTIONS_006, g_TitleTimer - 100, &colourcomponent); // "   prehistory"
		}
	} else {
		gdl = titleRenderTypewriterText(gdl, &x, &y, L_OPTIONS_007, g_TitleTimer - 35, &colourcomponent); // "rare presents"
	}

	gdl = func0f153780(gdl);

	if (g_TitleTypewriterFinishing) {
		if (g_TitleAudioHandle == NULL) {
			sndStart(var80095200, SFX_HUDMSG, &g_TitleAudioHandle, -1, -1, -1, -1, -1);
		}
	} else {
		if (g_TitleAudioHandle) {
			audioStop(g_TitleAudioHandle);
		}

		g_TitleAudioHandle = NULL;
	}

	if (((s32)(var80061630 * 80.0f) % 2) == 0) {
		u32 colour = (colourcomponent << 8) | 0x7f7fffff | (colourcomponent << 16);
		gdl = func0f153a34(gdl, x + 2, y, x + 12, y + 20, colour);
	}

	gdl = bviewRenderRarePresents(gdl);

	if (g_TitleTimer > TICKS(222)) {
		f32 alpha = ((g_TitleTimer - TICKS(222.0f)) / TICKS(78.0f));
		u32 stack;

		gdl = func0f153a34(gdl, viGetViewLeft(), viGetViewTop(),
				viGetViewLeft() + viGetViewWidth(),
				viGetViewTop() + viGetViewHeight(),
				255.0f * alpha);
	}

	return gdl;
}

void titleInitNintendoLogo(void)
{
	u8 *nextaddr = var8009cca0;

	g_TitleFastForward = false;

	if (g_TitleButtonPressed) {
		g_TitleTimer = PAL ? 133 : 180;
	} else {
		g_TitleTimer = 0;
	}

	{
		struct coord coord = {0, 0, 0};

		g_ModelStates[MODEL_NINTENDOLOGO].filedata = func0f1a7794(g_ModelStates[MODEL_NINTENDOLOGO].fileid, nextaddr, 0x47800, 0);

		modelCalculateRwDataLen(g_ModelStates[MODEL_NINTENDOLOGO].filedata);
		g_TitleModel = modelInstantiate(g_ModelStates[MODEL_NINTENDOLOGO].filedata);
		modelSetScale(g_TitleModel, 1);
		modelSetRootPosition(g_TitleModel, &coord);
		var800624f4 = 1;
		joy00014810(false);
	}
}

void titleExitNintendoLogo(void)
{
	modelFree(g_TitleModel);
	joy00014810(true);
}

/**
 * If no button has been pressed during the Rare logo (so g_TitleButtonPressed
 * is false) and the player presses a button within 140 ticks of the Nintendo
 * logo, the Nintendo logo sequence will play at double speed until it exits at
 * the 140 tick mark.
 */
void titleTickNintendoLogo(void)
{
	viSetFovY(60);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	viSetUseZBuf(false);

	g_TitleTimer += g_Vars.lvupdate240_60;

	if (g_TitleFastForward) {
		g_TitleTimer += g_Vars.lvupdate240_60;
	}

	if (joyGetButtonsPressedThisFrame(0, 0xffff)) {
		if (osResetType == 1 /*warm*/) {
			g_TitleButtonPressed = true;
			titleSetNextMode(TITLEMODE_PDLOGO);
		} else if (!g_TitleButtonPressed) {
			g_TitleFastForward = true;
		}
	}

	if (g_TitleFastForward && !g_TitleButtonPressed && g_TitleTimer > TICKS(140)) {
		g_TitleButtonPressed = true;
		g_TitleFastForward = false;
		titleSetNextMode(TITLEMODE_PDLOGO);
	}

	if (g_TitleTimer > (PAL ? 183 : 240)) {
		titleSetNextMode(TITLEMODE_PDLOGO);
	}
}

Gfx *titleRenderNintendoLogo(Gfx *gdl)
{
	struct modelrenderdata renderdata = { NULL, true, 3 };
	s32 i;
	s32 j;
	Mtxf sp108;
	f32 fracdone = g_TitleTimer / (PAL ? 183.0f : 240.0f);
	struct coord spf8 = {0, 0, 0};
	s32 v0;

	gdl = func0f01afc0(gdl);

	gSPSetLights1(gdl++, var80062590);

	spf8.z = sinf((1 - fracdone) * 1.5f * M_PI);
	spf8.x = cosf((1 - fracdone) * 1.5f * M_PI);

	guNormalize(&spf8.x, &spf8.y, &spf8.z);

	v0 = 255;

	if (fracdone < 0.1f) {
		v0 = 255.0f * fracdone / 0.1f;
	}

	if (fracdone > 0.9f) {
		v0 = (1 - fracdone) * 255.0f / 0.1f;
	}

	if (v0 > 255) {
		v0 = 255;
	}

	if (v0 < 0) {
		v0 = 0;
	}

	func0f01616c(&var80062590, v0, v0, v0, 0.0f, &spf8);

	{
		Mtxf spa8;
		struct coord sp9c;
		s32 stack[2];
		Mtxf sp54;

		sp9c.x = 0.0f;

		if (fracdone < 0.4f) {
			sp9c.x = (-cosf((1.0f - fracdone / .4f) * M_PI) * 0.5f + 0.5f) * 1.5707963705063f;
		}

		sp9c.y = (-cosf((1.0f - (fracdone / 1)) * M_PI) * 0.5f + .5f) * 0.35f;
		sp9c.z = 0.0f;

		mtx4LoadRotation(&sp9c, &spa8);
		mtx00015f88(fracdone * 0.2f + 1.0f, &spa8);

		mtx00016ae4(&sp108,
				/* pos  */ 0.0f, 0.0f, 4000,
				/* look */ 0.0f, 0.0f, 0.0f,
				/* up   */ 0.0f, 1.0f, 0.0f);

		mtx4MultMtx4InPlace(&sp108, &spa8);
		mtx4Copy(&spa8, &sp108);
		renderdata.unk00 = &sp108;

		renderdata.unk10 = gfxAllocate(g_TitleModel->filedata->nummatrices * sizeof(Mtxf));
		mtx4Copy(&sp108, renderdata.unk10);
		g_TitleModel->matrices = renderdata.unk10;

		model0001cc20(g_TitleModel);

		renderdata.flags = 3;
		renderdata.zbufferenabled = false;
		renderdata.gdl = gdl;

		modelRender(&renderdata, g_TitleModel);

		gdl = renderdata.gdl;

		for (i = 0, j = 0; i < g_TitleModel->filedata->nummatrices; i++, j += sizeof(Mtxf)) {
			mtx4Copy((Mtxf *)((u32)g_TitleModel->matrices + j), &sp54);
			mtx00016054(&sp54, g_TitleModel->matrices + i);
		}
	}

	return gdl;
}

void titleInitRareLogo(void)
{
	u8 *nextaddr = var8009cca0;

	g_TitleTimer = -3;

	{
		struct coord coord = {0, 0, 0};

		g_ModelStates[MODEL_RARELOGO].filedata = func0f1a7794(g_ModelStates[MODEL_RARELOGO].fileid, nextaddr, 0x47800, 0);

		modelCalculateRwDataLen(g_ModelStates[MODEL_RARELOGO].filedata);
		g_TitleModel = modelInstantiate(g_ModelStates[MODEL_RARELOGO].filedata);
		modelSetScale(g_TitleModel, 1);
		modelSetRootPosition(g_TitleModel, &coord);

		var800624f4 = 1;

		musicQueueStopAllEvent();
		joy00014810(false);

		if (!g_IsTitleDemo && IS8MB()) {
			g_IsTitleDemo = true;
		}
	}
}

void titleExitRareLogo(void)
{
	modelFree(g_TitleModel);
	joy00014810(true);
}

/**
 * If a button is pressed between 0-59 ticks, set the timer to 100 and schedule
 * the next mode for 140 (ie. in 40 ticks time).
 *
 * If a button is pressed at 60+ ticks, set the next mode immediately.
 *
 * So the fastest way to skip through the Rare logo is to press a button as
 * early as possible, but if you press the button between 20-59 ticks it'll end
 * up taking longer than if you'd waited a second.
 */
void titleTickRareLogo(void)
{
	viSetFovY(60);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	viSetUseZBuf(false);

	if (g_TitleTimer < 0) {
		g_TitleTimer++;
	} else {
		if (g_TitleTimer == 0) {
			musicQueueStartEvent(TRACKTYPE_PRIMARY, MUSIC_TITLE1, 0, 0x7fff);
		}

		g_TitleTimer += g_Vars.lvupdate240_60;

		if (joyGetButtonsPressedThisFrame(0, 0xffff)) {
			if (osResetType == 1 /*warm*/) {
				g_TitleButtonPressed = true;
				titleSetNextMode(TITLEMODE_PDLOGO);
			} else if (!g_TitleButtonPressed) {
				if (g_TitleTimer < TICKS(60)) {
					g_TitleButtonPressed = true;

					if (g_TitleTimer < TICKS(100)) {
						g_TitleTimer = TICKS(100);
					}
				} else {
					g_TitleFastForward = true;
					g_TitleButtonPressed = true;
				}
			}
		}

		if (g_TitleTimer > TICKS(240)
				|| g_TitleFastForward
				|| (g_TitleButtonPressed && g_TitleTimer > TICKS(140))) {
			titleSetNextMode(TITLEMODE_NINTENDOLOGO);
		}
	}
}

f32 func0f019d0c(f32 arg0)
{
	return ((1.0f - arg0) + (1.0f - arg0)) * M_PI - DEG2RAD(90);
}

Gfx *titleRenderRareLogo(Gfx *gdl)
{
	struct modelrenderdata renderdata = { NULL, true, 3 };
	s32 i;
	f32 fracdone = g_TitleTimer / TICKS(240.0f);
	Mtxf sp118;
	s32 j;
	s32 s0;

	static f32 var80062920 = 0;

	gdl = func0f01afc0(gdl);

	if (g_TitleTimer < 0) {
		return gdl;
	}

	{
		struct coord sp104 = {0, 0, 0};
		f32 tmp;
		Mtxf spc0;
		struct coord spb4;
		struct modelrwdata_toggle *rwdata;

		sp104.z = sinf(func0f019d0c(fracdone));
		sp104.x = cosf(func0f019d0c(fracdone));

		guNormalize(&sp104.x, &sp104.y, &sp104.z);

		s0 = 255;

		if (fracdone < 0.1f) {
			s0 = 255.0f * fracdone / 0.1f;
		}

		if (s0 > 255) {
			s0 = 255;
		}

		if (s0 < 0) {
			s0 = 0;
		}

		if (fracdone < 0.2f) {
			func0f01616c(&var80062590,
					(s32)(255.0f * fracdone / 0.2f),
					(s32)(255.0f * fracdone / 0.2f),
					(s32)(255.0f * fracdone / 0.2f),
					0, &sp104);
		} else {
			func0f01616c(&var80062590, s0, s0, s0, 0, &sp104);
		}

		s0 = s0 * 192 / 255;

		if (fracdone < 0.5f) {
			sp104.z = sinf(func0f019d0c(0.5f));
			sp104.x = cosf(func0f019d0c(0.5f));
			guNormalize(&sp104.x, &sp104.y, &sp104.z);
			func0f01616c(&var800625a8, s0, s0, s0, 0, &sp104);
		} else {
			func0f01616c(&var800625a8, s0, s0, s0, 0, &sp104);
		}

		var80062920 += g_Vars.lvupdate240f / 90;

		tmp = 1 - fracdone * 1;

		spb4.x = 0;
		spb4.y = 1.5707963705063f * tmp;
		spb4.z = 0;

		mtx4LoadRotation(&spb4, &spc0);
		mtx00015f88(1 + fracdone * 0.25f, &spc0);

		mtx00016ae4(&sp118,
				/* pos  */ 0, 0, 4000,
				/* look */ 0, 0, 0,
				/* up   */ 0, 1, 0);

		mtx4MultMtx4InPlace(&sp118, &spc0);
		mtx4Copy(&spc0, &sp118);

		renderdata.unk00 = &sp118;
		renderdata.unk10 = gfxAllocate(g_TitleModel->filedata->nummatrices * sizeof(Mtxf));
		mtx4Copy(&sp118, renderdata.unk10);

		g_TitleModel->matrices = renderdata.unk10;

		model0001cc20(g_TitleModel);

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000B));

		if (rwdata) {
			rwdata->visible = false;
		}

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000D));

		if (rwdata) {
			rwdata->visible = true;
		}

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000C));

		if (rwdata) {
			rwdata->visible = false;
		}

		gSPSetLights1(gdl++, var80062590);

		renderdata.flags = 3;
		renderdata.zbufferenabled = 0;
		renderdata.gdl = gdl;

		modelRender(&renderdata, g_TitleModel);

		gdl = renderdata.gdl;

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000B));

		if (rwdata) {
			rwdata->visible = true;
		}

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000D));

		if (rwdata) {
			rwdata->visible = false;
		}

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000C));

		if (rwdata) {
			rwdata->visible = true;
		}

		gSPSetLights1(gdl++, var80062590);

		renderdata.flags = 3;
		renderdata.zbufferenabled = 0;
		renderdata.gdl = gdl;

		modelRender(&renderdata, g_TitleModel);

		gdl = renderdata.gdl;

		for (i = 0, j = 0; i < g_TitleModel->filedata->nummatrices; i++, j += sizeof(Mtxf)) {
			Mtxf sp58;
			mtx4Copy((Mtxf *)((u32)g_TitleModel->matrices + j), &sp58);
			mtx00016054(&sp58, g_TitleModel->matrices + i);
		}
	}

	return gdl;
}

s32 g_NumPlayers = 0;
u32 var80062928 = 0x00000000;
u32 var8006292c = 0x00000001;
u32 var80062930 = 0x00000001;
u32 var80062934 = 0x00000001;
u32 var80062938 = 0x00000000;
u32 var8006293c = 0x00000000;

s32 getNumPlayers(void)
{
	return g_NumPlayers;
}

void setNumPlayers(s32 numplayers)
{
	g_NumPlayers = numplayers;
}

s32 playerGetTeam(s32 playernum)
{
	return g_PlayerConfigsArray[g_Vars.playerstats[playernum].mpindex].base.team;
}

void playerSetTeam(s32 playernum, s32 team)
{
	g_PlayerConfigsArray[g_Vars.playerstats[playernum].mpindex].base.team = team;
}

void titleInitSkip(void)
{
	g_TitleNextStage = STAGE_CITRAINING;

	setNumPlayers(1);

	if (g_IsTitleDemo) {
		g_TitleNextStage = STAGE_DEFECTION;
		g_IsTitleDemo++;
	}

	if (IS4MB()) {
		g_TitleNextStage = STAGE_4MBMENU;
		viSetAspect(PAL ? 1.7316017150879f : 1.4545454978943f);
		viSetSize(320, 220);
		viSetBufSize(320, 220);
		playermgrSetViewSize(320, 220);
		viSetViewSize(320, 220);
	}

	mainChangeToStage(g_TitleNextStage);

	g_Vars.bondplayernum = 0;
	g_Vars.coopplayernum = -1;
	g_Vars.antiplayernum = -1;

	lvSetDifficulty(DIFF_A);
	viBlack(true);
}

void titleInitNoController(void)
{
	g_TitleTimer = 0;
}

void titleExitNoController(void)
{
	// empty
}

void titleTickNoController(void)
{
	viSetFovY(60);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	viSetUseZBuf(false);

	g_TitleTimer += g_Vars.lvupdate240_60;
}

GLOBAL_ASM(
glabel titleRenderNoController
/*  f01a510:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f01a514:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f01a518:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f01a51c:	0c005013 */ 	jal	joyGetConnectedControllers
/*  f01a520:	00808025 */ 	or	$s0,$a0,$zero
/*  f01a524:	0fc06bf0 */ 	jal	func0f01afc0
/*  f01a528:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a52c:	0fc54d8a */ 	jal	func0f153628
/*  f01a530:	00402025 */ 	or	$a0,$v0,$zero
/*  f01a534:	00408025 */ 	or	$s0,$v0,$zero
/*  f01a538:	0fc5b9f1 */ 	jal	langGet
/*  f01a53c:	24045647 */ 	addiu	$a0,$zero,0x5647
/*  f01a540:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicLg)
/*  f01a544:	8dcefb1c */ 	lw	$t6,%lo(g_FontHandelGothicLg)($t6)
/*  f01a548:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicLg)
/*  f01a54c:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f01a550:	8ce7fb20 */ 	lw	$a3,%lo(g_CharsHandelGothicLg)($a3)
/*  f01a554:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f01a558:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f01a55c:	00403025 */ 	or	$a2,$v0,$zero
/*  f01a560:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f01a564:	0fc55cbe */ 	jal	textMeasure
/*  f01a568:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f01a56c:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f01a570:	3c098006 */ 	lui	$t1,%hi(g_TitleViewHeight)
/*  f01a574:	852924a0 */ 	lh	$t1,%lo(g_TitleViewHeight)($t1)
/*  f01a578:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f01a57c:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f01a580:	3c0f8008 */ 	lui	$t7,%hi(g_Jpn)
/*  f01a584:	8def4120 */ 	lw	$t7,%lo(g_Jpn)($t7)
/*  f01a588:	000b6043 */ 	sra	$t4,$t3,0x1
/*  f01a58c:	24190120 */ 	addiu	$t9,$zero,0x120
/*  f01a590:	03384023 */ 	subu	$t0,$t9,$t8
/*  f01a594:	afa8005c */ 	sw	$t0,0x5c($sp)
/*  f01a598:	05210003 */ 	bgez	$t1,.L0f01a5a8
/*  f01a59c:	00095043 */ 	sra	$t2,$t1,0x1
/*  f01a5a0:	25210001 */ 	addiu	$at,$t1,0x1
/*  f01a5a4:	00015043 */ 	sra	$t2,$at,0x1
.L0f01a5a8:
/*  f01a5a8:	014c6823 */ 	subu	$t5,$t2,$t4
/*  f01a5ac:	25aefff4 */ 	addiu	$t6,$t5,-12
/*  f01a5b0:	11e0001c */ 	beqz	$t7,.L0f01a624
/*  f01a5b4:	afae0058 */ 	sw	$t6,0x58($sp)
/*  f01a5b8:	0c002f02 */ 	jal	viGetWidth
/*  f01a5bc:	00000000 */ 	nop
/*  f01a5c0:	0c002f06 */ 	jal	viGetHeight
/*  f01a5c4:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f01a5c8:	3c198008 */ 	lui	$t9,%hi(g_CharsHandelGothicLg)
/*  f01a5cc:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicLg)
/*  f01a5d0:	8f18fb1c */ 	lw	$t8,%lo(g_FontHandelGothicLg)($t8)
/*  f01a5d4:	8f39fb20 */ 	lw	$t9,%lo(g_CharsHandelGothicLg)($t9)
/*  f01a5d8:	87ab0048 */ 	lh	$t3,0x48($sp)
/*  f01a5dc:	3c090080 */ 	lui	$t1,0x80
/*  f01a5e0:	352900ff */ 	ori	$t1,$t1,0xff
/*  f01a5e4:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f01a5e8:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f01a5ec:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f01a5f0:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a5f4:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f01a5f8:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f01a5fc:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f01a600:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f01a604:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f01a608:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f01a60c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f01a610:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f01a614:	0fc55b92 */ 	jal	textRender
/*  f01a618:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f01a61c:	10000018 */ 	b	.L0f01a680
/*  f01a620:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a624:
/*  f01a624:	0c002f02 */ 	jal	viGetWidth
/*  f01a628:	00000000 */ 	nop
/*  f01a62c:	0c002f06 */ 	jal	viGetHeight
/*  f01a630:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f01a634:	3c0a8008 */ 	lui	$t2,%hi(g_CharsHandelGothicLg)
/*  f01a638:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicLg)
/*  f01a63c:	8d8cfb1c */ 	lw	$t4,%lo(g_FontHandelGothicLg)($t4)
/*  f01a640:	8d4afb20 */ 	lw	$t2,%lo(g_CharsHandelGothicLg)($t2)
/*  f01a644:	87ae0048 */ 	lh	$t6,0x48($sp)
/*  f01a648:	240dffff */ 	addiu	$t5,$zero,-1
/*  f01a64c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f01a650:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a654:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f01a658:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f01a65c:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f01a660:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f01a664:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f01a668:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f01a66c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f01a670:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f01a674:	0fc5580f */ 	jal	textRenderProjected
/*  f01a678:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f01a67c:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a680:
/*  f01a680:	0fc5b9f1 */ 	jal	langGet
/*  f01a684:	24045648 */ 	addiu	$a0,$zero,0x5648
/*  f01a688:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicLg)
/*  f01a68c:	8deffb1c */ 	lw	$t7,%lo(g_FontHandelGothicLg)($t7)
/*  f01a690:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicLg)
/*  f01a694:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f01a698:	8ce7fb20 */ 	lw	$a3,%lo(g_CharsHandelGothicLg)($a3)
/*  f01a69c:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f01a6a0:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f01a6a4:	00403025 */ 	or	$a2,$v0,$zero
/*  f01a6a8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f01a6ac:	0fc55cbe */ 	jal	textMeasure
/*  f01a6b0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f01a6b4:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f01a6b8:	3c0b8006 */ 	lui	$t3,%hi(g_TitleViewHeight)
/*  f01a6bc:	856b24a0 */ 	lh	$t3,%lo(g_TitleViewHeight)($t3)
/*  f01a6c0:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f01a6c4:	0019c043 */ 	sra	$t8,$t9,0x1
/*  f01a6c8:	3c198008 */ 	lui	$t9,%hi(g_Jpn)
/*  f01a6cc:	8f394120 */ 	lw	$t9,%lo(g_Jpn)($t9)
/*  f01a6d0:	000c6843 */ 	sra	$t5,$t4,0x1
/*  f01a6d4:	24080120 */ 	addiu	$t0,$zero,0x120
/*  f01a6d8:	01184823 */ 	subu	$t1,$t0,$t8
/*  f01a6dc:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f01a6e0:	05610003 */ 	bgez	$t3,.L0f01a6f0
/*  f01a6e4:	000b5043 */ 	sra	$t2,$t3,0x1
/*  f01a6e8:	25610001 */ 	addiu	$at,$t3,0x1
/*  f01a6ec:	00015043 */ 	sra	$t2,$at,0x1
.L0f01a6f0:
/*  f01a6f0:	014d7023 */ 	subu	$t6,$t2,$t5
/*  f01a6f4:	25cf000c */ 	addiu	$t7,$t6,0xc
/*  f01a6f8:	1320001c */ 	beqz	$t9,.L0f01a76c
/*  f01a6fc:	afaf0058 */ 	sw	$t7,0x58($sp)
/*  f01a700:	0c002f02 */ 	jal	viGetWidth
/*  f01a704:	00000000 */ 	nop
/*  f01a708:	0c002f06 */ 	jal	viGetHeight
/*  f01a70c:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f01a710:	3c088008 */ 	lui	$t0,%hi(g_CharsHandelGothicLg)
/*  f01a714:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicLg)
/*  f01a718:	8f18fb1c */ 	lw	$t8,%lo(g_FontHandelGothicLg)($t8)
/*  f01a71c:	8d08fb20 */ 	lw	$t0,%lo(g_CharsHandelGothicLg)($t0)
/*  f01a720:	87ac0048 */ 	lh	$t4,0x48($sp)
/*  f01a724:	3c0b0080 */ 	lui	$t3,0x80
/*  f01a728:	356b00ff */ 	ori	$t3,$t3,0xff
/*  f01a72c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f01a730:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f01a734:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f01a738:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a73c:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f01a740:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f01a744:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f01a748:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f01a74c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f01a750:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f01a754:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f01a758:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f01a75c:	0fc55b92 */ 	jal	textRender
/*  f01a760:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f01a764:	10000018 */ 	b	.L0f01a7c8
/*  f01a768:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a76c:
/*  f01a76c:	0c002f02 */ 	jal	viGetWidth
/*  f01a770:	00000000 */ 	nop
/*  f01a774:	0c002f06 */ 	jal	viGetHeight
/*  f01a778:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f01a77c:	3c0a8008 */ 	lui	$t2,%hi(g_CharsHandelGothicLg)
/*  f01a780:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicLg)
/*  f01a784:	8dadfb1c */ 	lw	$t5,%lo(g_FontHandelGothicLg)($t5)
/*  f01a788:	8d4afb20 */ 	lw	$t2,%lo(g_CharsHandelGothicLg)($t2)
/*  f01a78c:	87af0048 */ 	lh	$t7,0x48($sp)
/*  f01a790:	240effff */ 	addiu	$t6,$zero,-1
/*  f01a794:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f01a798:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a79c:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f01a7a0:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f01a7a4:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f01a7a8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f01a7ac:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f01a7b0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f01a7b4:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f01a7b8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f01a7bc:	0fc5580f */ 	jal	textRenderProjected
/*  f01a7c0:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f01a7c4:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a7c8:
/*  f01a7c8:	0fc54de0 */ 	jal	func0f153780
/*  f01a7cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a7d0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f01a7d4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f01a7d8:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f01a7dc:	03e00008 */ 	jr	$ra
/*  f01a7e0:	00000000 */ 	nop
);

// Mismatch because goal uses an implicit stack address for viGetWidth's
// return value while mine uses s0, or multiple stack addresses.
//
// Each time func000bc08 is called, goal puts the result in sp72 to preserve it
// past the call to func000bc18. It uses the same stack address each time.
// However, if the below is changed to call the final func000bc08 like the
// others, it uses s0 instead. Likewise, changing all calls to load their return
// values into variables also makes it use s0. And a mix between the two
// (as shown below) causes it to use different stack addresses.
//Gfx *titleRenderNoController(Gfx *gdl)
//{
//	s32 textheight; // sp100
//	s32 textwidth; // sp96
//	s32 x; // sp92
//	s32 y; // sp88
//	char *text; // sp84
//	u16 stack[6];
//
//	// This was likely printed to console
//	joyGetConnectedControllers();
//
//	gdl = func0f01afc0(gdl);
//	gdl = func0f153628(gdl);
//
//	// First line
//	text = langGet(L_OPTIONS_071); // "- no controller in controller socket 1 -"
//	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);
//
//	x = 288 - (textwidth >> 1);
//	y = ((g_TitleViewHeight / 2) - (textheight >> 1)) - 12;
//
//	if (g_Jpn) {
//		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg,
//				-1, 0x008000ff, viGetWidth(), viGetHeight(), 0, 0);
//	} else {
//		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg,
//				-1, viGetWidth(), viGetHeight(), 0, 0);
//	}
//
//	// Second line
//	text = langGet(L_OPTIONS_072); // "please power off and attach a controller"
//	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);
//
//	x = 288 - (textwidth >> 1);
//	y = ((g_TitleViewHeight / 2) - (textheight >> 1)) + 12;
//
//	if (g_Jpn) {
//		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg,
//				-1, 0x008000ff, viGetWidth(), viGetHeight(), 0, 0);
//	} else {
//		s16 a = viGetWidth();
//		s16 b = viGetHeight();
//		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg,
//				-1, a, b, 0, 0);
//	}
//
//	return func0f153780(gdl);
//}

void titleSetNextMode(s32 mode)
{
	if (g_TitleDelayedMode != mode) {
		g_TitleNextMode = mode;
	}
}

s32 titleGetMode(void)
{
	return g_TitleMode;
}

void titleTick(void)
{
#if PAL
	viSetAspect(576.0f / g_TitleViewHeight * 1.1904761791229f);
#else
	viSetAspect(576.0f / g_TitleViewHeight);
#endif
	viSetSize(576, g_TitleViewHeight);
	viSetBufSize(576, g_TitleViewHeight);
	playermgrSetViewSize(576, g_TitleViewHeight);
	viSetViewSize(576, g_TitleViewHeight);
	playermgrSetViewPosition(0, 0);
	viSetViewPosition(0, 0);

	// If there's a new mode to transition to, schedule it to apply in 3 ticks
	// time and call the exit function for the current mode.
	if (g_TitleNextMode >= 0) {
		g_TitleDelayedTimer = 3;
		g_TitleDelayedMode = g_TitleNextMode;

		switch (g_TitleMode) {
		case TITLEMODE_LEGAL:
			titleExitLegal();
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			titleExitCheckControllers();
			break;
		case TITLEMODE_PDLOGO:
			titleExitPdLogo();
			break;
		case TITLEMODE_NINTENDOLOGO:
			titleExitNintendoLogo();
			break;
		case TITLEMODE_RARELOGO:
			titleExitRareLogo();
			break;
		case TITLEMODE_NOCONTROLLER:
			titleExitNoController();
			break;
		}

		if (g_TitleMode != TITLEMODE_CHECKCONTROLLERS) {
			viBlack(true);
		}

		g_TitleNextMode = -1;
	}

	// If there's a new mode scheduled, tick the timer down
	if (g_TitleDelayedTimer != 0) {
		g_TitleDelayedTimer--;

		if (g_TitleMode == -1) {
			g_TitleDelayedTimer = 0;
		}

		if (g_TitleDelayedTimer == 0 && g_TitleDelayedMode != -1) {
			g_TitleNextMode = g_TitleDelayedMode;
			g_TitleDelayedMode = -1;
		}
	}

	// Apply new mode
	if (g_TitleNextMode >= 0) {
		g_TitleMode = g_TitleNextMode;
		g_TitleNextMode = -1;
		g_TitleFastForward = false;

		switch (g_TitleMode) {
		case TITLEMODE_LEGAL:
			titleInitLegal();
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			titleInitCheckControllers();
			break;
		case TITLEMODE_PDLOGO:
			titleInitPdLogo();
			break;
		case TITLEMODE_NINTENDOLOGO:
			titleInitNintendoLogo();
			break;
		case TITLEMODE_RARELOGO:
			titleInitRareLogo();
			break;
		case TITLEMODE_SKIP:
			titleInitSkip();
			break;
		case TITLEMODE_NOCONTROLLER:
			titleInitNoController();
			break;
		}

		if (g_TitleMode != TITLEMODE_CHECKCONTROLLERS && g_TitleMode != TITLEMODE_SKIP) {
			viBlack(false);
		}
	}

	// Run the current mode's tick function
	switch (g_TitleMode) {
	case TITLEMODE_LEGAL:
		titleTickLegal();
		break;
	case TITLEMODE_CHECKCONTROLLERS:
		titleTickCheckControllers();
		break;
	case TITLEMODE_PDLOGO:
		titleTickPdLogo();
		break;
	case TITLEMODE_NINTENDOLOGO:
		titleTickNintendoLogo();
		break;
	case TITLEMODE_RARELOGO:
		titleTickRareLogo();
		break;
	case TITLEMODE_NOCONTROLLER:
		titleTickNoController();
		break;
	case TITLEMODE_SKIP:
		viSetUseZBuf(false);
		titleSetNextMode(TITLEMODE_RARELOGO);
		break;
	}
}

bool titleIsChangingMode(void)
{
	return g_TitleNextMode >= 0;
}

bool titleIsKeepingMode(void)
{
	if (g_TitleNextMode >= 0) {
		return false;
	}

	if (g_TitleMode == -1 || g_TitleMode == TITLEMODE_SKIP) {
		return false;
	}

	return true;
}

void titleExit(void)
{
	switch (g_TitleMode) {
	case TITLEMODE_LEGAL:
		titleExitLegal();
		break;
	case TITLEMODE_CHECKCONTROLLERS:
		titleExitCheckControllers();
		break;
	case TITLEMODE_PDLOGO:
		titleExitPdLogo();
		break;
	case TITLEMODE_NINTENDOLOGO:
		titleExitNintendoLogo();
		break;
	case TITLEMODE_RARELOGO:
		titleExitRareLogo();
		break;
	case TITLEMODE_NOCONTROLLER:
		titleExitNoController();
		break;
	case TITLEMODE_RAREPRESENTS1:
	case TITLEMODE_RAREPRESENTS2:
		titleExitRarePresents();
		break;
	}

	g_TitleNextMode = -1;
	g_TitleMode = -1;
}

void titleInitFromAiCmd(u32 value)
{
	switch (value) {
	case TITLEAIMODE_RAREPRESENTS1:
		g_TitleMode = TITLEMODE_RAREPRESENTS1;
		titleInitRarePresents();
		break;
	case TITLEAIMODE_RARELOGO:
		g_TitleMode = TITLEMODE_RARELOGO;
		titleInitRareLogo();
		break;
	case TITLEAIMODE_RAREPRESENTS2:
		g_TitleMode = TITLEMODE_RAREPRESENTS2;
		titleInitRarePresents();
		break;
	case TITLEAIMODE_NINTENDOLOGO:
		g_TitleMode = TITLEMODE_NINTENDOLOGO;
		titleInitNintendoLogo();
		break;
	case TITLEAIMODE_PDLOGO:
		g_TitleMode = TITLEMODE_PDLOGO;
		titleInitPdLogo();
		break;
	}

	g_TitleNextMode = -1;
}

bool func0f01ad5c(void)
{
	if (!titleIsKeepingMode()) {
		return false;
	}

	if (g_TitleMode == TITLEMODE_RAREPRESENTS2) {
		return false;
	}

	if (g_TitleMode == TITLEMODE_RAREPRESENTS1) {
		return false;
	}

	return true;
}

void func0f01adb8(void)
{
	viSetMode(VIMODE_HI);
	viSetSize(576, g_TitleViewHeight);
	viSetBufSize(576, g_TitleViewHeight);
	playermgrSetViewSize(576, g_TitleViewHeight);
	viSetViewSize(576, g_TitleViewHeight);
	playermgrSetViewPosition(0, 0);
	viSetViewPosition(0, 0);
}

void titleTickOld(void)
{
	if (titleIsKeepingMode()) {
		joy00014810(false);

		if (g_TitleDelayedTimer == 0) {
			switch (g_TitleMode) {
			case TITLEMODE_LEGAL:
				titleTickLegal();
				break;
			case TITLEMODE_CHECKCONTROLLERS:
				titleTickCheckControllers();
				break;
			case TITLEMODE_PDLOGO:
				titleTickPdLogo();
				break;
			case TITLEMODE_NINTENDOLOGO:
				titleTickNintendoLogo();
				break;
			case TITLEMODE_RAREPRESENTS1:
			case TITLEMODE_RAREPRESENTS2:
				titleTickRarePresents();
				break;
			case TITLEMODE_RARELOGO:
				titleTickRareLogo();
				break;
			}
		}
	}
}

Gfx *titleRender(Gfx *gdl)
{
	if (g_TitleDelayedTimer == 0) {
		switch (g_TitleMode) {
		case TITLEMODE_LEGAL:
			gdl = titleRenderLegal(gdl);
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			gdl = titleRenderCheckControllers(gdl);
			break;
		case TITLEMODE_PDLOGO:
			gdl = titleRenderPdLogo(gdl);
			break;
		case TITLEMODE_NINTENDOLOGO:
			gdl = titleRenderNintendoLogo(gdl);
			break;
		case TITLEMODE_RAREPRESENTS1:
		case TITLEMODE_RAREPRESENTS2:
			gdl = titleRenderRarePresents(gdl);
			break;
		case TITLEMODE_RARELOGO:
			gdl = titleRenderRareLogo(gdl);
			break;
		case TITLEMODE_NOCONTROLLER:
			gdl = titleRenderNoController(gdl);
			break;
		}
	}

	return gdl;
}
