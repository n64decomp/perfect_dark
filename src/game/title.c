#include <ultra64.h>
#include "constants.h"
#include "game/title.h"
#include "game/bondgun.h"
#include "game/game_0b28d0.h"
#include "game/tex.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/gfxmemory.h"
#include "game/credits.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/training.h"
#include "game/modeldef.h"
#include "game/lang.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/crash.h"
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

#if VERSION == VERSION_JPN_FINAL
u8 jpnfill[0x20];
#endif

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

#if VERSION == VERSION_JPN_FINAL
u32 var800623f0jf = 0;
struct model *var800623f4jf = NULL;
struct model *var800623f8jf = NULL;
struct model *var800623fcjf = NULL;
#endif

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

#if VERSION == VERSION_JPN_FINAL
u32 var80062468jf[6] = {0xffffff00, 0xffffff00 };
#endif

Lights1 var80062578 = gdSPDefLights1(0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f);
Lights1 var80062590 = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
Lights1 var800625a8 = gdSPDefLights1(0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f);

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

#if VERSION == VERSION_JPN_FINAL
u32 var800624f8jf = 0;
u32 var800624fcjf = 0;
u32 var80062500jf = 0;
u32 var80062504jf = 0;
u32 var80062508jf = 0x00007f00;
u32 var8006250cjf = 0;
u32 var80062510jf = 0;
u32 var80062514jf = 0;
u32 var80062518jf = 0;
u32 var8006251cjf = 0;
u32 var80062520jf = 0x00007f00;
u32 var80062524jf = 0;
#endif

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

void titleSetLight(Lights1 *light, u8 r, u8 g, u8 b, f32 luminosity, struct coord *dir)
{
	light->a.l.col[0] = r * luminosity;
	light->a.l.col[1] = g * luminosity;
	light->a.l.col[2] = b * luminosity;

	light->a.l.colc[0] = r * luminosity;
	light->a.l.colc[1] = g * luminosity;
	light->a.l.colc[2] = b * luminosity;

	light->l[0].l.col[0] = r;
	light->l[0].l.col[1] = g;
	light->l[0].l.col[2] = b;

	light->l[0].l.colc[0] = r;
	light->l[0].l.colc[1] = g;
	light->l[0].l.colc[2] = b;

	light->l[0].l.dir[0] = dir->x * 127.0f;
	light->l[0].l.dir[1] = dir->y * 127.0f;
	light->l[0].l.dir[2] = dir->z * 127.0f;
}

void titleInitLegal(void)
{
	musicQueueStopAllEvent();
	var800624f4 = 1;
	g_TitleTimer = 0;
	g_TitleButtonPressed = false;
	g_TitleFastForward = false;

#if VERSION == VERSION_PAL_BETA
	if (g_CrashHasMessage) {
		sndStart(var80095200, SFX_8113, 0, -1, -1, -1.0f, -1, -1);
	}
#endif
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
		gdl = titleClear(gdl);
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
#if VERSION == VERSION_JPN_FINAL
	{ 49,  163, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_077   }, // "Nintendo 64 Product Identification"
	{ 49,  184, 1, 1, LEGALELEMENTTYPE_LINE,        0               },
	{ 69,  191, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_078   }, // "Product ID:"
	{ 69,  211, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_079   }, // "Product Code:"
	{ 69,  231, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_080   }, // "Variant:"
	{ 69,  251, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_081   }, // "Developer:"
	{ 249, 191, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_082   }, // "Perfect Dark"
	{ 249, 211, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_083   }, // "NUS-NPDE-USA"
	{ 249, 231, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_084   }, // "NTSC version 8.7 final"
	{ 249, 251, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_085   }, // "Rare Ltd. (twycross)"
	{ 69,  274, 1, 1, LEGALELEMENTTYPE_LINE,        0               },
	{ 69,  283, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_076   }, // "N64 EXPANSION PAK"
	{ -1,  283, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_074   }, // "NOT DETECTED"
	{ 69,  304, 1, 1, LEGALELEMENTTYPE_LINE,        0               },
	{ 69,  312, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_087   }, // "The Rarewere Logo and Perfect Dark are ..."
	{ 69,  328, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_MPWEAPONS_280 }, // "Perfect Dark Registered Trademark No..."
	{ 138, 343, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_088   }, // "Presented in Dolby Surround. Dolby and ..."
	{ 69,  372, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_089   }, // "Uses Miles Sound System ..."
	{ 69,  428, 1, 1, LEGALELEMENTTYPE_LINE,        0               },
	{ 69,  433, 0, 1, LEGALELEMENTTYPE_BLUETEXTSM,  L_OPTIONS_093   }, // "rare designs on the future <<<"
	{ 69,  343, 0, 1, LEGALELEMENTTYPE_DOLBYLOGO,   0               },
#else
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
#if VERSION >= VERSION_PAL_BETA
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
#endif
};

#if VERSION >= VERSION_JPN_FINAL
struct modelrenderdata var80063dacpb = { NULL, true, 3 };

GLOBAL_ASM(
glabel titleRenderLegal
.late_rodata
glabel var7f1a84fcjf
.word 0x7f016828
.word 0x7f01683c
.word 0x7f016850
.word 0x7f0168d8
.word 0x7f0168d8
.word 0x7f016864
.word 0x7f0168c0
.text
/*  f01673c:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f016740:	3c0f8006 */ 	lui	$t7,0x8006
/*  f016744:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f016748:	25ef2624 */ 	addiu	$t7,$t7,0x2624
/*  f01674c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f016750:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f016754:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f016758:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f01675c:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f016760:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f016764:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f016768:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f01676c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f016770:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f016774:	0000b025 */ 	move	$s6,$zero
/*  f016778:	25eb003c */ 	addiu	$t3,$t7,0x3c
/*  f01677c:	27ae00e4 */ 	addiu	$t6,$sp,0xe4
.JF0f016780:
/*  f016780:	8de10000 */ 	lw	$at,0x0($t7)
/*  f016784:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f016788:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f01678c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f016790:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f016794:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f016798:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f01679c:	15ebfff8 */ 	bne	$t7,$t3,.JF0f016780
/*  f0167a0:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f0167a4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0167a8:	3c0c8006 */ 	lui	$t4,0x8006
/*  f0167ac:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0167b0:	8d8c2664 */ 	lw	$t4,0x2664($t4)
/*  f0167b4:	518001c9 */ 	beqzl	$t4,.JF0f016edc
/*  f0167b8:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0167bc:	0fc07058 */ 	jal	titleClear
/*  f0167c0:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0167c4:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0167c8:	0fc35617 */ 	jal	func0f0d479c
/*  f0167cc:	00402025 */ 	move	$a0,$v0
/*  f0167d0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0167d4:	0fc54b55 */ 	jal	func0f153628
/*  f0167d8:	00402025 */ 	move	$a0,$v0
/*  f0167dc:	3c0d8006 */ 	lui	$t5,0x8006
/*  f0167e0:	3c128006 */ 	lui	$s2,0x8006
/*  f0167e4:	25ad2624 */ 	addiu	$t5,$t5,0x2624
/*  f0167e8:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0167ec:	26522528 */ 	addiu	$s2,$s2,0x2528
/*  f0167f0:	afad0124 */ 	sw	$t5,0x124($sp)
/*  f0167f4:	27be00e0 */ 	addiu	$s8,$sp,0xe0
/*  f0167f8:	2417ffff */ 	li	$s7,-1
/*  f0167fc:	86420008 */ 	lh	$v0,0x8($s2)
.JF0f016800:
/*  f016800:	3c157f7f */ 	lui	$s5,0x7f7f
/*  f016804:	36b5ffff */ 	ori	$s5,$s5,0xffff
/*  f016808:	2c410007 */ 	sltiu	$at,$v0,0x7
/*  f01680c:	10200032 */ 	beqz	$at,.JF0f0168d8
/*  f016810:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f016814:	3c017f1b */ 	lui	$at,0x7f1b
/*  f016818:	00390821 */ 	addu	$at,$at,$t9
/*  f01681c:	8c398f4c */ 	lw	$t9,-0x70b4($at)
/*  f016820:	03200008 */ 	jr	$t9
/*  f016824:	00000000 */ 	nop
/*  f016828:	3c138008 */ 	lui	$s3,0x8008
/*  f01682c:	3c148008 */ 	lui	$s4,0x8008
/*  f016830:	8e73014c */ 	lw	$s3,0x14c($s3)
/*  f016834:	1000002c */ 	b	.JF0f0168e8
/*  f016838:	8e940148 */ 	lw	$s4,0x148($s4)
/*  f01683c:	3c138008 */ 	lui	$s3,0x8008
/*  f016840:	3c148008 */ 	lui	$s4,0x8008
/*  f016844:	8e730154 */ 	lw	$s3,0x154($s3)
/*  f016848:	10000027 */ 	b	.JF0f0168e8
/*  f01684c:	8e940150 */ 	lw	$s4,0x150($s4)
/*  f016850:	3c138008 */ 	lui	$s3,0x8008
/*  f016854:	3c148008 */ 	lui	$s4,0x8008
/*  f016858:	8e73015c */ 	lw	$s3,0x15c($s3)
/*  f01685c:	10000022 */ 	b	.JF0f0168e8
/*  f016860:	8e940158 */ 	lw	$s4,0x158($s4)
/*  f016864:	9643000a */ 	lhu	$v1,0xa($s2)
/*  f016868:	3c138008 */ 	lui	$s3,0x8008
/*  f01686c:	3c148008 */ 	lui	$s4,0x8008
/*  f016870:	2401564a */ 	li	$at,0x564a
/*  f016874:	8e73015c */ 	lw	$s3,0x15c($s3)
/*  f016878:	8e940158 */ 	lw	$s4,0x158($s4)
/*  f01687c:	10610003 */ 	beq	$v1,$at,.JF0f01688c
/*  f016880:	2415ffff */ 	li	$s5,-1
/*  f016884:	24015649 */ 	li	$at,0x5649
/*  f016888:	14610017 */ 	bne	$v1,$at,.JF0f0168e8
.JF0f01688c:
/*  f01688c:	3c188009 */ 	lui	$t8,0x8009
/*  f016890:	93181160 */ 	lbu	$t8,0x1160($t8)
/*  f016894:	24010001 */ 	li	$at,0x1
/*  f016898:	26d6000a */ 	addiu	$s6,$s6,0xa
/*  f01689c:	17010005 */ 	bne	$t8,$at,.JF0f0168b4
/*  f0168a0:	240f5649 */ 	li	$t7,0x5649
/*  f0168a4:	240b564a */ 	li	$t3,0x564a
/*  f0168a8:	a64b000a */ 	sh	$t3,0xa($s2)
/*  f0168ac:	1000000e */ 	b	.JF0f0168e8
/*  f0168b0:	86420008 */ 	lh	$v0,0x8($s2)
.JF0f0168b4:
/*  f0168b4:	a64f000a */ 	sh	$t7,0xa($s2)
/*  f0168b8:	1000000b */ 	b	.JF0f0168e8
/*  f0168bc:	86420008 */ 	lh	$v0,0x8($s2)
/*  f0168c0:	3c138008 */ 	lui	$s3,0x8008
/*  f0168c4:	3c148008 */ 	lui	$s4,0x8008
/*  f0168c8:	8e73014c */ 	lw	$s3,0x14c($s3)
/*  f0168cc:	8e940148 */ 	lw	$s4,0x148($s4)
/*  f0168d0:	10000005 */ 	b	.JF0f0168e8
/*  f0168d4:	2415ffff */ 	li	$s5,-1
.JF0f0168d8:
/*  f0168d8:	3c138008 */ 	lui	$s3,0x8008
/*  f0168dc:	3c148008 */ 	lui	$s4,0x8008
/*  f0168e0:	8e73015c */ 	lw	$s3,0x15c($s3)
/*  f0168e4:	8e940158 */ 	lw	$s4,0x158($s4)
.JF0f0168e8:
/*  f0168e8:	24010003 */ 	li	$at,0x3
/*  f0168ec:	54410016 */ 	bnel	$v0,$at,.JF0f016948
/*  f0168f0:	24010004 */ 	li	$at,0x4
/*  f0168f4:	0fc54bb7 */ 	jal	func0f153780
/*  f0168f8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0168fc:	0c002eeb */ 	jal	viGetWidth
/*  f016900:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f016904:	86430002 */ 	lh	$v1,0x2($s2)
/*  f016908:	3c0c7f7f */ 	lui	$t4,0x7f7f
/*  f01690c:	358cff7f */ 	ori	$t4,$t4,0xff7f
/*  f016910:	86450000 */ 	lh	$a1,0x0($s2)
/*  f016914:	246e0001 */ 	addiu	$t6,$v1,0x1
/*  f016918:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f01691c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f016920:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f016924:	00403825 */ 	move	$a3,$v0
/*  f016928:	0fc54c68 */ 	jal	func0f153a34
/*  f01692c:	2466ffff */ 	addiu	$a2,$v1,-1
/*  f016930:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f016934:	0fc54b55 */ 	jal	func0f153628
/*  f016938:	00402025 */ 	move	$a0,$v0
/*  f01693c:	1000015e */ 	b	.JF0f016eb8
/*  f016940:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f016944:	24010004 */ 	li	$at,0x4
.JF0f016948:
/*  f016948:	54410075 */ 	bnel	$v0,$at,.JF0f016b20
/*  f01694c:	24010007 */ 	li	$at,0x7
/*  f016950:	0fc54bb7 */ 	jal	func0f153780
/*  f016954:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f016958:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f01695c:	afad0130 */ 	sw	$t5,0x130($sp)
/*  f016960:	3c19e700 */ 	lui	$t9,0xe700
/*  f016964:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f016968:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f01696c:	8fb80130 */ 	lw	$t8,0x130($sp)
/*  f016970:	3c0fba00 */ 	lui	$t7,0xba00
/*  f016974:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f016978:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f01697c:	afab0130 */ 	sw	$t3,0x130($sp)
/*  f016980:	af000004 */ 	sw	$zero,0x4($t8)
/*  f016984:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f016988:	8fae0130 */ 	lw	$t6,0x130($sp)
/*  f01698c:	3c0db900 */ 	lui	$t5,0xb900
/*  f016990:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f016994:	25cc0008 */ 	addiu	$t4,$t6,0x8
/*  f016998:	afac0130 */ 	sw	$t4,0x130($sp)
/*  f01699c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0169a0:	adcd0000 */ 	sw	$t5,0x0($t6)
/*  f0169a4:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f0169a8:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0169ac:	356b1001 */ 	ori	$t3,$t3,0x1001
/*  f0169b0:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f0169b4:	afb80130 */ 	sw	$t8,0x130($sp)
/*  f0169b8:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0169bc:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f0169c0:	8faf0130 */ 	lw	$t7,0x130($sp)
/*  f0169c4:	3c0cba00 */ 	lui	$t4,0xba00
/*  f0169c8:	358c0903 */ 	ori	$t4,$t4,0x903
/*  f0169cc:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f0169d0:	afae0130 */ 	sw	$t6,0x130($sp)
/*  f0169d4:	240d0c00 */ 	li	$t5,0xc00
/*  f0169d8:	3c05800b */ 	lui	$a1,0x800b
/*  f0169dc:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f0169e0:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f0169e4:	8ca5bf98 */ 	lw	$a1,-0x4068($a1)
/*  f0169e8:	24190002 */ 	li	$t9,0x2
/*  f0169ec:	24180001 */ 	li	$t8,0x1
/*  f0169f0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0169f4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0169f8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0169fc:	27a40130 */ 	addiu	$a0,$sp,0x130
/*  f016a00:	24060001 */ 	li	$a2,0x1
/*  f016a04:	00003825 */ 	move	$a3,$zero
/*  f016a08:	0fc2d290 */ 	jal	texSelect
/*  f016a0c:	24a50234 */ 	addiu	$a1,$a1,0x234
/*  f016a10:	8fab0130 */ 	lw	$t3,0x130($sp)
/*  f016a14:	3c0eba00 */ 	lui	$t6,0xba00
/*  f016a18:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f016a1c:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f016a20:	afaf0130 */ 	sw	$t7,0x130($sp)
/*  f016a24:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f016a28:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f016a2c:	8fac0130 */ 	lw	$t4,0x130($sp)
/*  f016a30:	3c19fcff */ 	lui	$t9,0xfcff
/*  f016a34:	3c18fffc */ 	lui	$t8,0xfffc
/*  f016a38:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f016a3c:	afad0130 */ 	sw	$t5,0x130($sp)
/*  f016a40:	3718f279 */ 	ori	$t8,$t8,0xf279
/*  f016a44:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f016a48:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f016a4c:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f016a50:	8fab0130 */ 	lw	$t3,0x130($sp)
/*  f016a54:	3c0eba00 */ 	lui	$t6,0xba00
/*  f016a58:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f016a5c:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f016a60:	afaf0130 */ 	sw	$t7,0x130($sp)
/*  f016a64:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f016a68:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f016a6c:	8fa50130 */ 	lw	$a1,0x130($sp)
/*  f016a70:	3c01e400 */ 	lui	$at,0xe400
/*  f016a74:	24ad0008 */ 	addiu	$t5,$a1,0x8
/*  f016a78:	afad0130 */ 	sw	$t5,0x130($sp)
/*  f016a7c:	86590000 */ 	lh	$t9,0x0($s2)
/*  f016a80:	864d0002 */ 	lh	$t5,0x2($s2)
/*  f016a84:	27380040 */ 	addiu	$t8,$t9,0x40
/*  f016a88:	00185880 */ 	sll	$t3,$t8,0x2
/*  f016a8c:	316f0fff */ 	andi	$t7,$t3,0xfff
/*  f016a90:	25b90018 */ 	addiu	$t9,$t5,0x18
/*  f016a94:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f016a98:	000f7300 */ 	sll	$t6,$t7,0xc
/*  f016a9c:	01c16025 */ 	or	$t4,$t6,$at
/*  f016aa0:	330b0fff */ 	andi	$t3,$t8,0xfff
/*  f016aa4:	018b7825 */ 	or	$t7,$t4,$t3
/*  f016aa8:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f016aac:	864e0000 */ 	lh	$t6,0x0($s2)
/*  f016ab0:	864c0002 */ 	lh	$t4,0x2($s2)
/*  f016ab4:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f016ab8:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f016abc:	000c5880 */ 	sll	$t3,$t4,0x2
/*  f016ac0:	316f0fff */ 	andi	$t7,$t3,0xfff
/*  f016ac4:	0019c300 */ 	sll	$t8,$t9,0xc
/*  f016ac8:	030f7025 */ 	or	$t6,$t8,$t7
/*  f016acc:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f016ad0:	8fad0130 */ 	lw	$t5,0x130($sp)
/*  f016ad4:	240b0300 */ 	li	$t3,0x300
/*  f016ad8:	3c0cb400 */ 	lui	$t4,0xb400
/*  f016adc:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f016ae0:	afb90130 */ 	sw	$t9,0x130($sp)
/*  f016ae4:	adab0004 */ 	sw	$t3,0x4($t5)
/*  f016ae8:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f016aec:	8fb80130 */ 	lw	$t8,0x130($sp)
/*  f016af0:	3c0d0400 */ 	lui	$t5,0x400
/*  f016af4:	35adfc00 */ 	ori	$t5,$t5,0xfc00
/*  f016af8:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f016afc:	afaf0130 */ 	sw	$t7,0x130($sp)
/*  f016b00:	3c0eb300 */ 	lui	$t6,0xb300
/*  f016b04:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f016b08:	af0d0004 */ 	sw	$t5,0x4($t8)
/*  f016b0c:	0fc54b55 */ 	jal	func0f153628
/*  f016b10:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f016b14:	100000e8 */ 	b	.JF0f016eb8
/*  f016b18:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f016b1c:	24010007 */ 	li	$at,0x7
.JF0f016b20:
/*  f016b20:	54410075 */ 	bnel	$v0,$at,.JF0f016cf8
/*  f016b24:	86430000 */ 	lh	$v1,0x0($s2)
/*  f016b28:	0fc54bb7 */ 	jal	func0f153780
/*  f016b2c:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f016b30:	24590008 */ 	addiu	$t9,$v0,0x8
/*  f016b34:	afb90130 */ 	sw	$t9,0x130($sp)
/*  f016b38:	3c0ce700 */ 	lui	$t4,0xe700
/*  f016b3c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f016b40:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f016b44:	8fab0130 */ 	lw	$t3,0x130($sp)
/*  f016b48:	3c0fba00 */ 	lui	$t7,0xba00
/*  f016b4c:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f016b50:	25780008 */ 	addiu	$t8,$t3,0x8
/*  f016b54:	afb80130 */ 	sw	$t8,0x130($sp)
/*  f016b58:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f016b5c:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f016b60:	8fae0130 */ 	lw	$t6,0x130($sp)
/*  f016b64:	3c19b900 */ 	lui	$t9,0xb900
/*  f016b68:	37390002 */ 	ori	$t9,$t9,0x2
/*  f016b6c:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*  f016b70:	afad0130 */ 	sw	$t5,0x130($sp)
/*  f016b74:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f016b78:	add90000 */ 	sw	$t9,0x0($t6)
/*  f016b7c:	8fac0130 */ 	lw	$t4,0x130($sp)
/*  f016b80:	3c18ba00 */ 	lui	$t8,0xba00
/*  f016b84:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f016b88:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f016b8c:	afab0130 */ 	sw	$t3,0x130($sp)
/*  f016b90:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f016b94:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f016b98:	8faf0130 */ 	lw	$t7,0x130($sp)
/*  f016b9c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f016ba0:	35ad0903 */ 	ori	$t5,$t5,0x903
/*  f016ba4:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f016ba8:	afae0130 */ 	sw	$t6,0x130($sp)
/*  f016bac:	24190c00 */ 	li	$t9,0xc00
/*  f016bb0:	3c05800b */ 	lui	$a1,0x800b
/*  f016bb4:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f016bb8:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f016bbc:	8ca5bf98 */ 	lw	$a1,-0x4068($a1)
/*  f016bc0:	240c0002 */ 	li	$t4,0x2
/*  f016bc4:	240b0001 */ 	li	$t3,0x1
/*  f016bc8:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f016bcc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f016bd0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f016bd4:	27a40130 */ 	addiu	$a0,$sp,0x130
/*  f016bd8:	24060001 */ 	li	$a2,0x1
/*  f016bdc:	00003825 */ 	move	$a3,$zero
/*  f016be0:	0fc2d290 */ 	jal	texSelect
/*  f016be4:	24a5024c */ 	addiu	$a1,$a1,0x24c
/*  f016be8:	8fb80130 */ 	lw	$t8,0x130($sp)
/*  f016bec:	3c0eba00 */ 	lui	$t6,0xba00
/*  f016bf0:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f016bf4:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f016bf8:	afaf0130 */ 	sw	$t7,0x130($sp)
/*  f016bfc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f016c00:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f016c04:	8fad0130 */ 	lw	$t5,0x130($sp)
/*  f016c08:	3c0cfcff */ 	lui	$t4,0xfcff
/*  f016c0c:	3c0bfffc */ 	lui	$t3,0xfffc
/*  f016c10:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f016c14:	afb90130 */ 	sw	$t9,0x130($sp)
/*  f016c18:	356bf279 */ 	ori	$t3,$t3,0xf279
/*  f016c1c:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f016c20:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f016c24:	adab0004 */ 	sw	$t3,0x4($t5)
/*  f016c28:	8fb80130 */ 	lw	$t8,0x130($sp)
/*  f016c2c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f016c30:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f016c34:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f016c38:	afaf0130 */ 	sw	$t7,0x130($sp)
/*  f016c3c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f016c40:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f016c44:	8fa50130 */ 	lw	$a1,0x130($sp)
/*  f016c48:	3c01e400 */ 	lui	$at,0xe400
/*  f016c4c:	24b90008 */ 	addiu	$t9,$a1,0x8
/*  f016c50:	afb90130 */ 	sw	$t9,0x130($sp)
/*  f016c54:	864c0000 */ 	lh	$t4,0x0($s2)
/*  f016c58:	86590002 */ 	lh	$t9,0x2($s2)
/*  f016c5c:	258b0020 */ 	addiu	$t3,$t4,0x20
/*  f016c60:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f016c64:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f016c68:	272c002a */ 	addiu	$t4,$t9,0x2a
/*  f016c6c:	000c5880 */ 	sll	$t3,$t4,0x2
/*  f016c70:	000f7300 */ 	sll	$t6,$t7,0xc
/*  f016c74:	01c16825 */ 	or	$t5,$t6,$at
/*  f016c78:	31780fff */ 	andi	$t8,$t3,0xfff
/*  f016c7c:	01b87825 */ 	or	$t7,$t5,$t8
/*  f016c80:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f016c84:	864e0000 */ 	lh	$t6,0x0($s2)
/*  f016c88:	864d0002 */ 	lh	$t5,0x2($s2)
/*  f016c8c:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f016c90:	332c0fff */ 	andi	$t4,$t9,0xfff
/*  f016c94:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f016c98:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f016c9c:	000c5b00 */ 	sll	$t3,$t4,0xc
/*  f016ca0:	016f7025 */ 	or	$t6,$t3,$t7
/*  f016ca4:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f016ca8:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f016cac:	24180540 */ 	li	$t8,0x540
/*  f016cb0:	3c0db400 */ 	lui	$t5,0xb400
/*  f016cb4:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f016cb8:	afac0130 */ 	sw	$t4,0x130($sp)
/*  f016cbc:	af380004 */ 	sw	$t8,0x4($t9)
/*  f016cc0:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f016cc4:	8fab0130 */ 	lw	$t3,0x130($sp)
/*  f016cc8:	3c190400 */ 	lui	$t9,0x400
/*  f016ccc:	3739fc00 */ 	ori	$t9,$t9,0xfc00
/*  f016cd0:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f016cd4:	afaf0130 */ 	sw	$t7,0x130($sp)
/*  f016cd8:	3c0eb300 */ 	lui	$t6,0xb300
/*  f016cdc:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f016ce0:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f016ce4:	0fc54b55 */ 	jal	func0f153628
/*  f016ce8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f016cec:	10000072 */ 	b	.JF0f016eb8
/*  f016cf0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f016cf4:	86430000 */ 	lh	$v1,0x0($s2)
.JF0f016cf8:
/*  f016cf8:	56e30004 */ 	bnel	$s7,$v1,.JF0f016d0c
/*  f016cfc:	afa300e0 */ 	sw	$v1,0xe0($sp)
/*  f016d00:	10000002 */ 	b	.JF0f016d0c
/*  f016d04:	afb600e0 */ 	sw	$s6,0xe0($sp)
/*  f016d08:	afa300e0 */ 	sw	$v1,0xe0($sp)
.JF0f016d0c:
/*  f016d0c:	864c0002 */ 	lh	$t4,0x2($s2)
/*  f016d10:	24010005 */ 	li	$at,0x5
/*  f016d14:	258dffff */ 	addiu	$t5,$t4,-1
/*  f016d18:	afad00dc */ 	sw	$t5,0xdc($sp)
/*  f016d1c:	86420008 */ 	lh	$v0,0x8($s2)
/*  f016d20:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f016d24:	10410003 */ 	beq	$v0,$at,.JF0f016d34
/*  f016d28:	270bfffd */ 	addiu	$t3,$t8,-3
/*  f016d2c:	24010006 */ 	li	$at,0x6
/*  f016d30:	14410026 */ 	bne	$v0,$at,.JF0f016dcc
.JF0f016d34:
/*  f016d34:	24020002 */ 	li	$v0,0x2
/*  f016d38:	3c018008 */ 	lui	$at,0x8008
/*  f016d3c:	ac220108 */ 	sw	$v0,0x108($at)
/*  f016d40:	3c018008 */ 	lui	$at,0x8008
/*  f016d44:	afab00dc */ 	sw	$t3,0xdc($sp)
/*  f016d48:	ac22010c */ 	sw	$v0,0x10c($at)
/*  f016d4c:	864f0000 */ 	lh	$t7,0x0($s2)
/*  f016d50:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f016d54:	16ef0002 */ 	bne	$s7,$t7,.JF0f016d60
/*  f016d58:	25d90018 */ 	addiu	$t9,$t6,0x18
/*  f016d5c:	afb900e0 */ 	sw	$t9,0xe0($sp)
.JF0f016d60:
/*  f016d60:	0fc5baa5 */ 	jal	langGet
/*  f016d64:	9644000a */ 	lhu	$a0,0xa($s2)
/*  f016d68:	0c002eeb */ 	jal	viGetWidth
/*  f016d6c:	00408025 */ 	move	$s0,$v0
/*  f016d70:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f016d74:	00116403 */ 	sra	$t4,$s1,0x10
/*  f016d78:	0c002eef */ 	jal	viGetHeight
/*  f016d7c:	01808825 */ 	move	$s1,$t4
/*  f016d80:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f016d84:	03c02825 */ 	move	$a1,$s8
/*  f016d88:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f016d8c:	02003825 */ 	move	$a3,$s0
/*  f016d90:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f016d94:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f016d98:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f016d9c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f016da0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f016da4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f016da8:	0fc55886 */ 	jal	textRenderProjected
/*  f016dac:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f016db0:	24030001 */ 	li	$v1,0x1
/*  f016db4:	3c018008 */ 	lui	$at,0x8008
/*  f016db8:	ac230108 */ 	sw	$v1,0x108($at)
/*  f016dbc:	3c018008 */ 	lui	$at,0x8008
/*  f016dc0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f016dc4:	1000003c */ 	b	.JF0f016eb8
/*  f016dc8:	ac23010c */ 	sw	$v1,0x10c($at)
.JF0f016dcc:
/*  f016dcc:	0fc5baa5 */ 	jal	langGet
/*  f016dd0:	9644000a */ 	lhu	$a0,0xa($s2)
/*  f016dd4:	0c002eeb */ 	jal	viGetWidth
/*  f016dd8:	00408025 */ 	move	$s0,$v0
/*  f016ddc:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f016de0:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f016de4:	0c002eef */ 	jal	viGetHeight
/*  f016de8:	01a08825 */ 	move	$s1,$t5
/*  f016dec:	2401ff00 */ 	li	$at,-256
/*  f016df0:	02a1c024 */ 	and	$t8,$s5,$at
/*  f016df4:	32ab00ff */ 	andi	$t3,$s5,0xff
/*  f016df8:	000b7840 */ 	sll	$t7,$t3,0x1
/*  f016dfc:	24010003 */ 	li	$at,0x3
/*  f016e00:	01e1001b */ 	divu	$zero,$t7,$at
/*  f016e04:	00007012 */ 	mflo	$t6
/*  f016e08:	030ec825 */ 	or	$t9,$t8,$t6
/*  f016e0c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f016e10:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f016e14:	03c02825 */ 	move	$a1,$s8
/*  f016e18:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f016e1c:	02003825 */ 	move	$a3,$s0
/*  f016e20:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f016e24:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f016e28:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f016e2c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f016e30:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f016e34:	0fc55886 */ 	jal	textRenderProjected
/*  f016e38:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f016e3c:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f016e40:	86430000 */ 	lh	$v1,0x0($s2)
/*  f016e44:	56e30004 */ 	bnel	$s7,$v1,.JF0f016e58
/*  f016e48:	afa300e0 */ 	sw	$v1,0xe0($sp)
/*  f016e4c:	10000002 */ 	b	.JF0f016e58
/*  f016e50:	afb600e0 */ 	sw	$s6,0xe0($sp)
/*  f016e54:	afa300e0 */ 	sw	$v1,0xe0($sp)
.JF0f016e58:
/*  f016e58:	864c0002 */ 	lh	$t4,0x2($s2)
/*  f016e5c:	afac00dc */ 	sw	$t4,0xdc($sp)
/*  f016e60:	0fc5baa5 */ 	jal	langGet
/*  f016e64:	9644000a */ 	lhu	$a0,0xa($s2)
/*  f016e68:	0c002eeb */ 	jal	viGetWidth
/*  f016e6c:	00408025 */ 	move	$s0,$v0
/*  f016e70:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f016e74:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f016e78:	0c002eef */ 	jal	viGetHeight
/*  f016e7c:	01a08825 */ 	move	$s1,$t5
/*  f016e80:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f016e84:	03c02825 */ 	move	$a1,$s8
/*  f016e88:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f016e8c:	02003825 */ 	move	$a3,$s0
/*  f016e90:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f016e94:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f016e98:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f016e9c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f016ea0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f016ea4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f016ea8:	0fc55886 */ 	jal	textRenderProjected
/*  f016eac:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f016eb0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f016eb4:	8fb600e0 */ 	lw	$s6,0xe0($sp)
.JF0f016eb8:
/*  f016eb8:	8fab0124 */ 	lw	$t3,0x124($sp)
/*  f016ebc:	2652000c */ 	addiu	$s2,$s2,0xc
/*  f016ec0:	024b082b */ 	sltu	$at,$s2,$t3
/*  f016ec4:	5420fe4e */ 	bnezl	$at,.JF0f016800
/*  f016ec8:	86420008 */ 	lh	$v0,0x8($s2)
/*  f016ecc:	0fc54bb7 */ 	jal	func0f153780
/*  f016ed0:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f016ed4:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f016ed8:	8fbf005c */ 	lw	$ra,0x5c($sp)
.JF0f016edc:
/*  f016edc:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f016ee0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f016ee4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f016ee8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f016eec:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f016ef0:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f016ef4:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f016ef8:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f016efc:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f016f00:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f016f04:	03e00008 */ 	jr	$ra
/*  f016f08:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#elif VERSION == VERSION_PAL_BETA
struct modelrenderdata var80063dacpb = { NULL, true, 3 };

GLOBAL_ASM(
glabel titleRenderLegal
.late_rodata
glabel var7f1aa08cnb
.word 0x7f016848
.word 0x7f016858
.word 0x7f01686c
.word 0x7f0168e0
.word 0x7f0168e0
.word 0x7f016878
.word 0x7f0168cc
.text
/*  f016758:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f01675c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f016760:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f016764:	25ef3dac */ 	addiu	$t7,$t7,0x3dac
/*  f016768:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f01676c:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f016770:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f016774:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f016778:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f01677c:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f016780:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f016784:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f016788:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f01678c:	afa40128 */ 	sw	$a0,0x128($sp)
/*  f016790:	00009825 */ 	move	$s3,$zero
/*  f016794:	25eb003c */ 	addiu	$t3,$t7,0x3c
/*  f016798:	27ae00dc */ 	addiu	$t6,$sp,0xdc
.PB0f01679c:
/*  f01679c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0167a0:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f0167a4:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f0167a8:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f0167ac:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f0167b0:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f0167b4:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f0167b8:	15ebfff8 */ 	bne	$t7,$t3,.PB0f01679c
/*  f0167bc:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f0167c0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0167c4:	3c0c8006 */ 	lui	$t4,0x8006
/*  f0167c8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0167cc:	8d8c3dec */ 	lw	$t4,0x3dec($t4)
/*  f0167d0:	5180016f */ 	beqzl	$t4,.PB0f016d90
/*  f0167d4:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0167d8:	0fc06c14 */ 	jal	titleClear
/*  f0167dc:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f0167e0:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f0167e4:	0fc5528f */ 	jal	func0f153628
/*  f0167e8:	00402025 */ 	move	$a0,$v0
/*  f0167ec:	3c0d8006 */ 	lui	$t5,0x8006
/*  f0167f0:	3c108006 */ 	lui	$s0,0x8006
/*  f0167f4:	25ad3dac */ 	addiu	$t5,$t5,0x3dac
/*  f0167f8:	3c1e8008 */ 	lui	$s8,0x8008
/*  f0167fc:	3c178008 */ 	lui	$s7,0x8008
/*  f016800:	3c168008 */ 	lui	$s6,0x8008
/*  f016804:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016808:	26103cb0 */ 	addiu	$s0,$s0,0x3cb0
/*  f01680c:	afad011c */ 	sw	$t5,0x11c($sp)
/*  f016810:	26d61ff0 */ 	addiu	$s6,$s6,0x1ff0
/*  f016814:	26f71fec */ 	addiu	$s7,$s7,0x1fec
/*  f016818:	27de1fe0 */ 	addiu	$s8,$s8,0x1fe0
/*  f01681c:	86030008 */ 	lh	$v1,0x8($s0)
.PB0f016820:
/*  f016820:	3c157f7f */ 	lui	$s5,0x7f7f
/*  f016824:	36b5ffff */ 	ori	$s5,$s5,0xffff
/*  f016828:	2c610007 */ 	sltiu	$at,$v1,0x7
/*  f01682c:	1020002c */ 	beqz	$at,.PB0f0168e0
/*  f016830:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f016834:	3c017f1b */ 	lui	$at,0x7f1b
/*  f016838:	00390821 */ 	addu	$at,$at,$t9
/*  f01683c:	8c39a08c */ 	lw	$t9,-0x5f74($at)
/*  f016840:	03200008 */ 	jr	$t9
/*  f016844:	00000000 */ 	nop
/*  f016848:	3c128008 */ 	lui	$s2,0x8008
/*  f01684c:	8fd10000 */ 	lw	$s1,0x0($s8)
/*  f016850:	10000025 */ 	b	.PB0f0168e8
/*  f016854:	8e521fdc */ 	lw	$s2,0x1fdc($s2)
/*  f016858:	3c118008 */ 	lui	$s1,0x8008
/*  f01685c:	3c128008 */ 	lui	$s2,0x8008
/*  f016860:	8e311fe8 */ 	lw	$s1,0x1fe8($s1)
/*  f016864:	10000020 */ 	b	.PB0f0168e8
/*  f016868:	8e521fe4 */ 	lw	$s2,0x1fe4($s2)
/*  f01686c:	8ed10000 */ 	lw	$s1,0x0($s6)
/*  f016870:	1000001d */ 	b	.PB0f0168e8
/*  f016874:	8ef20000 */ 	lw	$s2,0x0($s7)
/*  f016878:	9602000a */ 	lhu	$v0,0xa($s0)
/*  f01687c:	2401564a */ 	li	$at,0x564a
/*  f016880:	8ed10000 */ 	lw	$s1,0x0($s6)
/*  f016884:	8ef20000 */ 	lw	$s2,0x0($s7)
/*  f016888:	10410003 */ 	beq	$v0,$at,.PB0f016898
/*  f01688c:	2415ffff */ 	li	$s5,-1
/*  f016890:	24015649 */ 	li	$at,0x5649
/*  f016894:	14410014 */ 	bne	$v0,$at,.PB0f0168e8
.PB0f016898:
/*  f016898:	3c188009 */ 	lui	$t8,0x8009
/*  f01689c:	93182fd0 */ 	lbu	$t8,0x2fd0($t8)
/*  f0168a0:	24010001 */ 	li	$at,0x1
/*  f0168a4:	2673000a */ 	addiu	$s3,$s3,0xa
/*  f0168a8:	17010005 */ 	bne	$t8,$at,.PB0f0168c0
/*  f0168ac:	240f5649 */ 	li	$t7,0x5649
/*  f0168b0:	240b564a */ 	li	$t3,0x564a
/*  f0168b4:	a60b000a */ 	sh	$t3,0xa($s0)
/*  f0168b8:	1000000b */ 	b	.PB0f0168e8
/*  f0168bc:	86030008 */ 	lh	$v1,0x8($s0)
.PB0f0168c0:
/*  f0168c0:	a60f000a */ 	sh	$t7,0xa($s0)
/*  f0168c4:	10000008 */ 	b	.PB0f0168e8
/*  f0168c8:	86030008 */ 	lh	$v1,0x8($s0)
/*  f0168cc:	3c128008 */ 	lui	$s2,0x8008
/*  f0168d0:	8fd10000 */ 	lw	$s1,0x0($s8)
/*  f0168d4:	8e521fdc */ 	lw	$s2,0x1fdc($s2)
/*  f0168d8:	10000003 */ 	b	.PB0f0168e8
/*  f0168dc:	2415ffff */ 	li	$s5,-1
.PB0f0168e0:
/*  f0168e0:	8ed10000 */ 	lw	$s1,0x0($s6)
/*  f0168e4:	8ef20000 */ 	lw	$s2,0x0($s7)
.PB0f0168e8:
/*  f0168e8:	24010003 */ 	li	$at,0x3
/*  f0168ec:	54610015 */ 	bnel	$v1,$at,.PB0f016944
/*  f0168f0:	24010004 */ 	li	$at,0x4
/*  f0168f4:	0fc552e5 */ 	jal	func0f153780
/*  f0168f8:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f0168fc:	0c002e4d */ 	jal	viGetWidth
/*  f016900:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016904:	86060002 */ 	lh	$a2,0x2($s0)
/*  f016908:	3c0c7f7f */ 	lui	$t4,0x7f7f
/*  f01690c:	358cff7f */ 	ori	$t4,$t4,0xff7f
/*  f016910:	86050000 */ 	lh	$a1,0x0($s0)
/*  f016914:	24ce0002 */ 	addiu	$t6,$a2,0x2
/*  f016918:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f01691c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f016920:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016924:	0fc55392 */ 	jal	func0f153a34
/*  f016928:	00403825 */ 	move	$a3,$v0
/*  f01692c:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016930:	0fc5528f */ 	jal	func0f153628
/*  f016934:	00402025 */ 	move	$a0,$v0
/*  f016938:	1000010c */ 	b	.PB0f016d6c
/*  f01693c:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016940:	24010004 */ 	li	$at,0x4
.PB0f016944:
/*  f016944:	54610075 */ 	bnel	$v1,$at,.PB0f016b1c
/*  f016948:	24010007 */ 	li	$at,0x7
/*  f01694c:	0fc552e5 */ 	jal	func0f153780
/*  f016950:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016954:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f016958:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f01695c:	3c19e700 */ 	lui	$t9,0xe700
/*  f016960:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f016964:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f016968:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f01696c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f016970:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f016974:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f016978:	afab0128 */ 	sw	$t3,0x128($sp)
/*  f01697c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f016980:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f016984:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f016988:	3c0db900 */ 	lui	$t5,0xb900
/*  f01698c:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f016990:	25cc0008 */ 	addiu	$t4,$t6,0x8
/*  f016994:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f016998:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f01699c:	adcd0000 */ 	sw	$t5,0x0($t6)
/*  f0169a0:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f0169a4:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0169a8:	356b1001 */ 	ori	$t3,$t3,0x1001
/*  f0169ac:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f0169b0:	afb80128 */ 	sw	$t8,0x128($sp)
/*  f0169b4:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0169b8:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f0169bc:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f0169c0:	3c0cba00 */ 	lui	$t4,0xba00
/*  f0169c4:	358c0903 */ 	ori	$t4,$t4,0x903
/*  f0169c8:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f0169cc:	afae0128 */ 	sw	$t6,0x128($sp)
/*  f0169d0:	240d0c00 */ 	li	$t5,0xc00
/*  f0169d4:	3c05800b */ 	lui	$a1,0x800b
/*  f0169d8:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f0169dc:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f0169e0:	8ca5fbc8 */ 	lw	$a1,-0x438($a1)
/*  f0169e4:	24190002 */ 	li	$t9,0x2
/*  f0169e8:	24180001 */ 	li	$t8,0x1
/*  f0169ec:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0169f0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0169f4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0169f8:	27a40128 */ 	addiu	$a0,$sp,0x128
/*  f0169fc:	24060001 */ 	li	$a2,0x1
/*  f016a00:	00003825 */ 	move	$a3,$zero
/*  f016a04:	0fc2cf74 */ 	jal	texSelect
/*  f016a08:	24a50234 */ 	addiu	$a1,$a1,0x234
/*  f016a0c:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f016a10:	3c0eba00 */ 	lui	$t6,0xba00
/*  f016a14:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f016a18:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f016a1c:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f016a20:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f016a24:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f016a28:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f016a2c:	3c19fcff */ 	lui	$t9,0xfcff
/*  f016a30:	3c18fffc */ 	lui	$t8,0xfffc
/*  f016a34:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f016a38:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f016a3c:	3718f279 */ 	ori	$t8,$t8,0xf279
/*  f016a40:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f016a44:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f016a48:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f016a4c:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f016a50:	3c0eba00 */ 	lui	$t6,0xba00
/*  f016a54:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f016a58:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f016a5c:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f016a60:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f016a64:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f016a68:	8fa50128 */ 	lw	$a1,0x128($sp)
/*  f016a6c:	3c01e400 */ 	lui	$at,0xe400
/*  f016a70:	24ad0008 */ 	addiu	$t5,$a1,0x8
/*  f016a74:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f016a78:	86190000 */ 	lh	$t9,0x0($s0)
/*  f016a7c:	860d0002 */ 	lh	$t5,0x2($s0)
/*  f016a80:	27380040 */ 	addiu	$t8,$t9,0x40
/*  f016a84:	00185880 */ 	sll	$t3,$t8,0x2
/*  f016a88:	316f0fff */ 	andi	$t7,$t3,0xfff
/*  f016a8c:	25b90018 */ 	addiu	$t9,$t5,0x18
/*  f016a90:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f016a94:	000f7300 */ 	sll	$t6,$t7,0xc
/*  f016a98:	01c16025 */ 	or	$t4,$t6,$at
/*  f016a9c:	330b0fff */ 	andi	$t3,$t8,0xfff
/*  f016aa0:	018b7825 */ 	or	$t7,$t4,$t3
/*  f016aa4:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f016aa8:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f016aac:	860c0002 */ 	lh	$t4,0x2($s0)
/*  f016ab0:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f016ab4:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f016ab8:	000c5880 */ 	sll	$t3,$t4,0x2
/*  f016abc:	316f0fff */ 	andi	$t7,$t3,0xfff
/*  f016ac0:	0019c300 */ 	sll	$t8,$t9,0xc
/*  f016ac4:	030f7025 */ 	or	$t6,$t8,$t7
/*  f016ac8:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f016acc:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f016ad0:	240b0300 */ 	li	$t3,0x300
/*  f016ad4:	3c0cb400 */ 	lui	$t4,0xb400
/*  f016ad8:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f016adc:	afb90128 */ 	sw	$t9,0x128($sp)
/*  f016ae0:	adab0004 */ 	sw	$t3,0x4($t5)
/*  f016ae4:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f016ae8:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f016aec:	3c0d0400 */ 	lui	$t5,0x400
/*  f016af0:	35adfc00 */ 	ori	$t5,$t5,0xfc00
/*  f016af4:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f016af8:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f016afc:	3c0eb300 */ 	lui	$t6,0xb300
/*  f016b00:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f016b04:	af0d0004 */ 	sw	$t5,0x4($t8)
/*  f016b08:	0fc5528f */ 	jal	func0f153628
/*  f016b0c:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016b10:	10000096 */ 	b	.PB0f016d6c
/*  f016b14:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016b18:	24010007 */ 	li	$at,0x7
.PB0f016b1c:
/*  f016b1c:	54610075 */ 	bnel	$v1,$at,.PB0f016cf4
/*  f016b20:	86020000 */ 	lh	$v0,0x0($s0)
/*  f016b24:	0fc552e5 */ 	jal	func0f153780
/*  f016b28:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016b2c:	24590008 */ 	addiu	$t9,$v0,0x8
/*  f016b30:	afb90128 */ 	sw	$t9,0x128($sp)
/*  f016b34:	3c0ce700 */ 	lui	$t4,0xe700
/*  f016b38:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f016b3c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f016b40:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f016b44:	3c0fba00 */ 	lui	$t7,0xba00
/*  f016b48:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f016b4c:	25780008 */ 	addiu	$t8,$t3,0x8
/*  f016b50:	afb80128 */ 	sw	$t8,0x128($sp)
/*  f016b54:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f016b58:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f016b5c:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f016b60:	3c19b900 */ 	lui	$t9,0xb900
/*  f016b64:	37390002 */ 	ori	$t9,$t9,0x2
/*  f016b68:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*  f016b6c:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f016b70:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f016b74:	add90000 */ 	sw	$t9,0x0($t6)
/*  f016b78:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f016b7c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f016b80:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f016b84:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f016b88:	afab0128 */ 	sw	$t3,0x128($sp)
/*  f016b8c:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f016b90:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f016b94:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f016b98:	3c0dba00 */ 	lui	$t5,0xba00
/*  f016b9c:	35ad0903 */ 	ori	$t5,$t5,0x903
/*  f016ba0:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f016ba4:	afae0128 */ 	sw	$t6,0x128($sp)
/*  f016ba8:	24190c00 */ 	li	$t9,0xc00
/*  f016bac:	3c05800b */ 	lui	$a1,0x800b
/*  f016bb0:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f016bb4:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f016bb8:	8ca5fbc8 */ 	lw	$a1,-0x438($a1)
/*  f016bbc:	240c0002 */ 	li	$t4,0x2
/*  f016bc0:	240b0001 */ 	li	$t3,0x1
/*  f016bc4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f016bc8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f016bcc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f016bd0:	27a40128 */ 	addiu	$a0,$sp,0x128
/*  f016bd4:	24060001 */ 	li	$a2,0x1
/*  f016bd8:	00003825 */ 	move	$a3,$zero
/*  f016bdc:	0fc2cf74 */ 	jal	texSelect
/*  f016be0:	24a5024c */ 	addiu	$a1,$a1,0x24c
/*  f016be4:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f016be8:	3c0eba00 */ 	lui	$t6,0xba00
/*  f016bec:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f016bf0:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f016bf4:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f016bf8:	af000004 */ 	sw	$zero,0x4($t8)
/*  f016bfc:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f016c00:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f016c04:	3c0cfcff */ 	lui	$t4,0xfcff
/*  f016c08:	3c0bfffc */ 	lui	$t3,0xfffc
/*  f016c0c:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f016c10:	afb90128 */ 	sw	$t9,0x128($sp)
/*  f016c14:	356bf279 */ 	ori	$t3,$t3,0xf279
/*  f016c18:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f016c1c:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f016c20:	adab0004 */ 	sw	$t3,0x4($t5)
/*  f016c24:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f016c28:	3c0eba00 */ 	lui	$t6,0xba00
/*  f016c2c:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f016c30:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f016c34:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f016c38:	af000004 */ 	sw	$zero,0x4($t8)
/*  f016c3c:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f016c40:	8fa50128 */ 	lw	$a1,0x128($sp)
/*  f016c44:	3c01e400 */ 	lui	$at,0xe400
/*  f016c48:	24b90008 */ 	addiu	$t9,$a1,0x8
/*  f016c4c:	afb90128 */ 	sw	$t9,0x128($sp)
/*  f016c50:	860c0000 */ 	lh	$t4,0x0($s0)
/*  f016c54:	86190002 */ 	lh	$t9,0x2($s0)
/*  f016c58:	258b0020 */ 	addiu	$t3,$t4,0x20
/*  f016c5c:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f016c60:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f016c64:	272c002a */ 	addiu	$t4,$t9,0x2a
/*  f016c68:	000c5880 */ 	sll	$t3,$t4,0x2
/*  f016c6c:	000f7300 */ 	sll	$t6,$t7,0xc
/*  f016c70:	01c16825 */ 	or	$t5,$t6,$at
/*  f016c74:	31780fff */ 	andi	$t8,$t3,0xfff
/*  f016c78:	01b87825 */ 	or	$t7,$t5,$t8
/*  f016c7c:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f016c80:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f016c84:	860d0002 */ 	lh	$t5,0x2($s0)
/*  f016c88:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f016c8c:	332c0fff */ 	andi	$t4,$t9,0xfff
/*  f016c90:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f016c94:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f016c98:	000c5b00 */ 	sll	$t3,$t4,0xc
/*  f016c9c:	016f7025 */ 	or	$t6,$t3,$t7
/*  f016ca0:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f016ca4:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f016ca8:	24180540 */ 	li	$t8,0x540
/*  f016cac:	3c0db400 */ 	lui	$t5,0xb400
/*  f016cb0:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f016cb4:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f016cb8:	af380004 */ 	sw	$t8,0x4($t9)
/*  f016cbc:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f016cc0:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f016cc4:	3c190400 */ 	lui	$t9,0x400
/*  f016cc8:	3739fc00 */ 	ori	$t9,$t9,0xfc00
/*  f016ccc:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f016cd0:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f016cd4:	3c0eb300 */ 	lui	$t6,0xb300
/*  f016cd8:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f016cdc:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f016ce0:	0fc5528f */ 	jal	func0f153628
/*  f016ce4:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016ce8:	10000020 */ 	b	.PB0f016d6c
/*  f016cec:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016cf0:	86020000 */ 	lh	$v0,0x0($s0)
.PB0f016cf4:
/*  f016cf4:	2401ffff */ 	li	$at,-1
/*  f016cf8:	54410004 */ 	bnel	$v0,$at,.PB0f016d0c
/*  f016cfc:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f016d00:	10000002 */ 	b	.PB0f016d0c
/*  f016d04:	afb300d8 */ 	sw	$s3,0xd8($sp)
/*  f016d08:	afa200d8 */ 	sw	$v0,0xd8($sp)
.PB0f016d0c:
/*  f016d0c:	860c0002 */ 	lh	$t4,0x2($s0)
/*  f016d10:	afac00d4 */ 	sw	$t4,0xd4($sp)
/*  f016d14:	0fc5c06a */ 	jal	langGet
/*  f016d18:	9604000a */ 	lhu	$a0,0xa($s0)
/*  f016d1c:	0c002e4d */ 	jal	viGetWidth
/*  f016d20:	00409825 */ 	move	$s3,$v0
/*  f016d24:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f016d28:	00146c03 */ 	sra	$t5,$s4,0x10
/*  f016d2c:	0c002e51 */ 	jal	viGetHeight
/*  f016d30:	01a0a025 */ 	move	$s4,$t5
/*  f016d34:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016d38:	27a500d8 */ 	addiu	$a1,$sp,0xd8
/*  f016d3c:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f016d40:	02603825 */ 	move	$a3,$s3
/*  f016d44:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f016d48:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f016d4c:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f016d50:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f016d54:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f016d58:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f016d5c:	0fc55e10 */ 	jal	textRenderProjected
/*  f016d60:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f016d64:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016d68:	8fb300d8 */ 	lw	$s3,0xd8($sp)
.PB0f016d6c:
/*  f016d6c:	8fb8011c */ 	lw	$t8,0x11c($sp)
/*  f016d70:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f016d74:	0218082b */ 	sltu	$at,$s0,$t8
/*  f016d78:	5420fea9 */ 	bnezl	$at,.PB0f016820
/*  f016d7c:	86030008 */ 	lh	$v1,0x8($s0)
/*  f016d80:	0fc552e5 */ 	jal	func0f153780
/*  f016d84:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016d88:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016d8c:	8fbf005c */ 	lw	$ra,0x5c($sp)
.PB0f016d90:
/*  f016d90:	8fa20128 */ 	lw	$v0,0x128($sp)
/*  f016d94:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f016d98:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f016d9c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f016da0:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f016da4:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f016da8:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f016dac:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f016db0:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f016db4:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f016db8:	03e00008 */ 	jr	$ra
/*  f016dbc:	27bd0128 */ 	addiu	$sp,$sp,0x128
);
#else
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
		gdl = titleClear(gdl);
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

				texSelect(&gdl, &g_TexGeneralConfigs[47], 1, 0, 2, 1, 0);

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

				texSelect(&gdl, &g_TexGeneralConfigs[49], 1, 0, 2, 1, 0);

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
#endif

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

#if VERSION >= VERSION_JPN_FINAL
struct coord var800624a4jf = {0};

GLOBAL_ASM(
glabel titleInitPdLogo
.late_rodata
glabel var7f1a8f68jf
.word 0x3c23d70a
.word 0x3f7d70a4
.text
/*  f016f0c:	3c018006 */ 	lui	$at,0x8006
/*  f016f10:	ac2023a4 */ 	sw	$zero,0x23a4($at)
/*  f016f14:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f016f18:	3c014110 */ 	lui	$at,0x4110
/*  f016f1c:	44812000 */ 	mtc1	$at,$f4
/*  f016f20:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f016f24:	3c09800a */ 	lui	$t1,0x800a
/*  f016f28:	3c11800a */ 	lui	$s1,0x800a
/*  f016f2c:	2529d350 */ 	addiu	$t1,$t1,-11440
/*  f016f30:	8e31d330 */ 	lw	$s1,-0x2cd0($s1)
/*  f016f34:	e5240000 */ 	swc1	$f4,0x0($t1)
/*  f016f38:	c5260000 */ 	lwc1	$f6,0x0($t1)
/*  f016f3c:	3c04800a */ 	lui	$a0,0x800a
/*  f016f40:	2484d34c */ 	addiu	$a0,$a0,-11444
/*  f016f44:	3c017f1b */ 	lui	$at,0x7f1b
/*  f016f48:	e4860000 */ 	swc1	$f6,0x0($a0)
/*  f016f4c:	c4228f68 */ 	lwc1	$f2,-0x7098($at)
/*  f016f50:	3c017f1b */ 	lui	$at,0x7f1b
/*  f016f54:	3c08800a */ 	lui	$t0,0x800a
/*  f016f58:	3c05800a */ 	lui	$a1,0x800a
/*  f016f5c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f016f60:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f016f64:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f016f68:	24a5d364 */ 	addiu	$a1,$a1,-11420
/*  f016f6c:	2508d358 */ 	addiu	$t0,$t0,-11432
/*  f016f70:	c4208f6c */ 	lwc1	$f0,-0x7094($at)
/*  f016f74:	00003025 */ 	move	$a2,$zero
/*  f016f78:	24070004 */ 	li	$a3,0x4
.JF0f016f7c:
/*  f016f7c:	00001825 */ 	move	$v1,$zero
.JF0f016f80:
/*  f016f80:	c4880000 */ 	lwc1	$f8,0x0($a0)
/*  f016f84:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f016f88:	28610014 */ 	slti	$at,$v1,0x14
/*  f016f8c:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f016f90:	46025400 */ 	add.s	$f16,$f10,$f2
/*  f016f94:	1420fffa */ 	bnez	$at,.JF0f016f80
/*  f016f98:	e4900000 */ 	swc1	$f16,0x0($a0)
/*  f016f9c:	3c02800a */ 	lui	$v0,0x800a
/*  f016fa0:	2442d358 */ 	addiu	$v0,$v0,-11432
.JF0f016fa4:
/*  f016fa4:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f016fa8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f016fac:	1445fffd */ 	bne	$v0,$a1,.JF0f016fa4
/*  f016fb0:	e452fffc */ 	swc1	$f18,-0x4($v0)
/*  f016fb4:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f016fb8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f016fbc:	14c7ffef */ 	bne	$a2,$a3,.JF0f016f7c
/*  f016fc0:	e504000c */ 	swc1	$f4,0xc($t0)
/*  f016fc4:	c5060004 */ 	lwc1	$f6,0x4($t0)
/*  f016fc8:	3c0f8006 */ 	lui	$t7,0x8006
/*  f016fcc:	25ef2670 */ 	addiu	$t7,$t7,0x2670
/*  f016fd0:	e5260000 */ 	swc1	$f6,0x0($t1)
/*  f016fd4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f016fd8:	27ae0060 */ 	addiu	$t6,$sp,0x60
/*  f016fdc:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f016fe0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f016fe4:	8de10008 */ 	lw	$at,0x8($t7)
/*  f016fe8:	3c108008 */ 	lui	$s0,0x8008
/*  f016fec:	2610b65c */ 	addiu	$s0,$s0,-18852
/*  f016ff0:	3c060004 */ 	lui	$a2,0x4
/*  f016ff4:	add90004 */ 	sw	$t9,0x4($t6)
/*  f016ff8:	adc10008 */ 	sw	$at,0x8($t6)
/*  f016ffc:	96040244 */ 	lhu	$a0,0x244($s0)
/*  f017000:	34c67800 */ 	ori	$a2,$a2,0x7800
/*  f017004:	02202825 */ 	move	$a1,$s1
/*  f017008:	0fc6a0c5 */ 	jal	modeldefLoad
/*  f01700c:	00003825 */ 	move	$a3,$zero
/*  f017010:	ae020240 */ 	sw	$v0,0x240($s0)
/*  f017014:	0fc59da4 */ 	jal	fileGetLoadedSize
/*  f017018:	96040244 */ 	lhu	$a0,0x244($s0)
/*  f01701c:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f017020:	346a003f */ 	ori	$t2,$v1,0x3f
/*  f017024:	3c0c0004 */ 	lui	$t4,0x4
/*  f017028:	394b003f */ 	xori	$t3,$t2,0x3f
/*  f01702c:	358c7800 */ 	ori	$t4,$t4,0x7800
/*  f017030:	022b8821 */ 	addu	$s1,$s1,$t3
/*  f017034:	018b9023 */ 	subu	$s2,$t4,$t3
/*  f017038:	0c008a0e */ 	jal	modelCalculateRwDataLen
/*  f01703c:	8e040240 */ 	lw	$a0,0x240($s0)
/*  f017040:	0fc2d0c0 */ 	jal	modelInstantiateWithAnim
/*  f017044:	8e040240 */ 	lw	$a0,0x240($s0)
/*  f017048:	3c038006 */ 	lui	$v1,0x8006
/*  f01704c:	246323d8 */ 	addiu	$v1,$v1,0x23d8
/*  f017050:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f017054:	00402025 */ 	move	$a0,$v0
/*  f017058:	0c006bbe */ 	jal	modelSetScale
/*  f01705c:	3c053f80 */ 	lui	$a1,0x3f80
/*  f017060:	3c048006 */ 	lui	$a0,0x8006
/*  f017064:	8c8423d8 */ 	lw	$a0,0x23d8($a0)
/*  f017068:	0c006b35 */ 	jal	modelSetRootPosition
/*  f01706c:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f017070:	3c188006 */ 	lui	$t8,0x8006
/*  f017074:	2718267c */ 	addiu	$t8,$t8,0x267c
/*  f017078:	8f010000 */ 	lw	$at,0x0($t8)
/*  f01707c:	27ad0054 */ 	addiu	$t5,$sp,0x54
/*  f017080:	8f0f0004 */ 	lw	$t7,0x4($t8)
/*  f017084:	ada10000 */ 	sw	$at,0x0($t5)
/*  f017088:	8f010008 */ 	lw	$at,0x8($t8)
/*  f01708c:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f017090:	02202825 */ 	move	$a1,$s1
/*  f017094:	ada10008 */ 	sw	$at,0x8($t5)
/*  f017098:	9604024c */ 	lhu	$a0,0x24c($s0)
/*  f01709c:	02403025 */ 	move	$a2,$s2
/*  f0170a0:	0fc6a0c5 */ 	jal	modeldefLoad
/*  f0170a4:	00003825 */ 	move	$a3,$zero
/*  f0170a8:	ae020248 */ 	sw	$v0,0x248($s0)
/*  f0170ac:	0fc59da4 */ 	jal	fileGetLoadedSize
/*  f0170b0:	9604024c */ 	lhu	$a0,0x24c($s0)
/*  f0170b4:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0170b8:	3479003f */ 	ori	$t9,$v1,0x3f
/*  f0170bc:	3b2a003f */ 	xori	$t2,$t9,0x3f
/*  f0170c0:	022a8821 */ 	addu	$s1,$s1,$t2
/*  f0170c4:	024a9023 */ 	subu	$s2,$s2,$t2
/*  f0170c8:	0c008a0e */ 	jal	modelCalculateRwDataLen
/*  f0170cc:	8e040248 */ 	lw	$a0,0x248($s0)
/*  f0170d0:	0fc2d0c0 */ 	jal	modelInstantiateWithAnim
/*  f0170d4:	8e040248 */ 	lw	$a0,0x248($s0)
/*  f0170d8:	3c038006 */ 	lui	$v1,0x8006
/*  f0170dc:	246323dc */ 	addiu	$v1,$v1,0x23dc
/*  f0170e0:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f0170e4:	00402025 */ 	move	$a0,$v0
/*  f0170e8:	0c006bbe */ 	jal	modelSetScale
/*  f0170ec:	3c053f80 */ 	lui	$a1,0x3f80
/*  f0170f0:	3c048006 */ 	lui	$a0,0x8006
/*  f0170f4:	8c8423dc */ 	lw	$a0,0x23dc($a0)
/*  f0170f8:	0c006b35 */ 	jal	modelSetRootPosition
/*  f0170fc:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f017100:	3c0c8006 */ 	lui	$t4,0x8006
/*  f017104:	258c2688 */ 	addiu	$t4,$t4,0x2688
/*  f017108:	8d810000 */ 	lw	$at,0x0($t4)
/*  f01710c:	27ab0048 */ 	addiu	$t3,$sp,0x48
/*  f017110:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f017114:	ad610000 */ 	sw	$at,0x0($t3)
/*  f017118:	8d810008 */ 	lw	$at,0x8($t4)
/*  f01711c:	ad6d0004 */ 	sw	$t5,0x4($t3)
/*  f017120:	02202825 */ 	move	$a1,$s1
/*  f017124:	ad610008 */ 	sw	$at,0x8($t3)
/*  f017128:	9604026c */ 	lhu	$a0,0x26c($s0)
/*  f01712c:	02403025 */ 	move	$a2,$s2
/*  f017130:	0fc6a0c5 */ 	jal	modeldefLoad
/*  f017134:	00003825 */ 	move	$a3,$zero
/*  f017138:	ae020268 */ 	sw	$v0,0x268($s0)
/*  f01713c:	0fc59da4 */ 	jal	fileGetLoadedSize
/*  f017140:	9604026c */ 	lhu	$a0,0x26c($s0)
/*  f017144:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f017148:	3478003f */ 	ori	$t8,$v1,0x3f
/*  f01714c:	3b0f003f */ 	xori	$t7,$t8,0x3f
/*  f017150:	022f8821 */ 	addu	$s1,$s1,$t7
/*  f017154:	024f9023 */ 	subu	$s2,$s2,$t7
/*  f017158:	0c008a0e */ 	jal	modelCalculateRwDataLen
/*  f01715c:	8e040268 */ 	lw	$a0,0x268($s0)
/*  f017160:	0fc2d04b */ 	jal	modelInstantiateWithoutAnim
/*  f017164:	8e040268 */ 	lw	$a0,0x268($s0)
/*  f017168:	3c038006 */ 	lui	$v1,0x8006
/*  f01716c:	246323e8 */ 	addiu	$v1,$v1,0x23e8
/*  f017170:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f017174:	00402025 */ 	move	$a0,$v0
/*  f017178:	0c006bbe */ 	jal	modelSetScale
/*  f01717c:	3c053f80 */ 	lui	$a1,0x3f80
/*  f017180:	3c048006 */ 	lui	$a0,0x8006
/*  f017184:	8c8423e8 */ 	lw	$a0,0x23e8($a0)
/*  f017188:	0c006b35 */ 	jal	modelSetRootPosition
/*  f01718c:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f017190:	3c0a8006 */ 	lui	$t2,0x8006
/*  f017194:	254a2694 */ 	addiu	$t2,$t2,0x2694
/*  f017198:	8d410000 */ 	lw	$at,0x0($t2)
/*  f01719c:	27b9003c */ 	addiu	$t9,$sp,0x3c
/*  f0171a0:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f0171a4:	af210000 */ 	sw	$at,0x0($t9)
/*  f0171a8:	8d410008 */ 	lw	$at,0x8($t2)
/*  f0171ac:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f0171b0:	02202825 */ 	move	$a1,$s1
/*  f0171b4:	af210008 */ 	sw	$at,0x8($t9)
/*  f0171b8:	96040dcc */ 	lhu	$a0,0xdcc($s0)
/*  f0171bc:	02403025 */ 	move	$a2,$s2
/*  f0171c0:	0fc6a0c5 */ 	jal	modeldefLoad
/*  f0171c4:	00003825 */ 	move	$a3,$zero
/*  f0171c8:	ae020dc8 */ 	sw	$v0,0xdc8($s0)
/*  f0171cc:	0fc59da4 */ 	jal	fileGetLoadedSize
/*  f0171d0:	96040dcc */ 	lhu	$a0,0xdcc($s0)
/*  f0171d4:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0171d8:	346c003f */ 	ori	$t4,$v1,0x3f
/*  f0171dc:	398d003f */ 	xori	$t5,$t4,0x3f
/*  f0171e0:	022d8821 */ 	addu	$s1,$s1,$t5
/*  f0171e4:	024d9023 */ 	subu	$s2,$s2,$t5
/*  f0171e8:	0c008a0e */ 	jal	modelCalculateRwDataLen
/*  f0171ec:	8e040dc8 */ 	lw	$a0,0xdc8($s0)
/*  f0171f0:	0fc2d04b */ 	jal	modelInstantiateWithoutAnim
/*  f0171f4:	8e040dc8 */ 	lw	$a0,0xdc8($s0)
/*  f0171f8:	3c018006 */ 	lui	$at,0x8006
/*  f0171fc:	ac2223f4 */ 	sw	$v0,0x23f4($at)
/*  f017200:	0fc2d04b */ 	jal	modelInstantiateWithoutAnim
/*  f017204:	8e040dc8 */ 	lw	$a0,0xdc8($s0)
/*  f017208:	3c018006 */ 	lui	$at,0x8006
/*  f01720c:	3c048006 */ 	lui	$a0,0x8006
/*  f017210:	ac2223f8 */ 	sw	$v0,0x23f8($at)
/*  f017214:	8c8423f4 */ 	lw	$a0,0x23f4($a0)
/*  f017218:	0c006bbe */ 	jal	modelSetScale
/*  f01721c:	3c053f80 */ 	lui	$a1,0x3f80
/*  f017220:	3c048006 */ 	lui	$a0,0x8006
/*  f017224:	8c8423f8 */ 	lw	$a0,0x23f8($a0)
/*  f017228:	0c006bbe */ 	jal	modelSetScale
/*  f01722c:	3c053f80 */ 	lui	$a1,0x3f80
/*  f017230:	3c048006 */ 	lui	$a0,0x8006
/*  f017234:	8c8423f4 */ 	lw	$a0,0x23f4($a0)
/*  f017238:	0c006b35 */ 	jal	modelSetRootPosition
/*  f01723c:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f017240:	3c048006 */ 	lui	$a0,0x8006
/*  f017244:	8c8423f8 */ 	lw	$a0,0x23f8($a0)
/*  f017248:	0c006b35 */ 	jal	modelSetRootPosition
/*  f01724c:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f017250:	96040dd4 */ 	lhu	$a0,0xdd4($s0)
/*  f017254:	02202825 */ 	move	$a1,$s1
/*  f017258:	02403025 */ 	move	$a2,$s2
/*  f01725c:	0fc6a0c5 */ 	jal	modeldefLoad
/*  f017260:	00003825 */ 	move	$a3,$zero
/*  f017264:	ae020dd0 */ 	sw	$v0,0xdd0($s0)
/*  f017268:	0fc59da4 */ 	jal	fileGetLoadedSize
/*  f01726c:	96040dd4 */ 	lhu	$a0,0xdd4($s0)
/*  f017270:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f017274:	3478003f */ 	ori	$t8,$v1,0x3f
/*  f017278:	3b0f003f */ 	xori	$t7,$t8,0x3f
/*  f01727c:	022f8821 */ 	addu	$s1,$s1,$t7
/*  f017280:	024f9023 */ 	subu	$s2,$s2,$t7
/*  f017284:	0c008a0e */ 	jal	modelCalculateRwDataLen
/*  f017288:	8e040dd0 */ 	lw	$a0,0xdd0($s0)
/*  f01728c:	0fc2d04b */ 	jal	modelInstantiateWithoutAnim
/*  f017290:	8e040dd0 */ 	lw	$a0,0xdd0($s0)
/*  f017294:	3c038006 */ 	lui	$v1,0x8006
/*  f017298:	246323fc */ 	addiu	$v1,$v1,0x23fc
/*  f01729c:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f0172a0:	00402025 */ 	move	$a0,$v0
/*  f0172a4:	0c006bbe */ 	jal	modelSetScale
/*  f0172a8:	3c053f80 */ 	lui	$a1,0x3f80
/*  f0172ac:	3c048006 */ 	lui	$a0,0x8006
/*  f0172b0:	8c8423fc */ 	lw	$a0,0x23fc($a0)
/*  f0172b4:	0c006b35 */ 	jal	modelSetRootPosition
/*  f0172b8:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f0172bc:	3c198006 */ 	lui	$t9,0x8006
/*  f0172c0:	273926a0 */ 	addiu	$t9,$t9,0x26a0
/*  f0172c4:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0172c8:	27ae0030 */ 	addiu	$t6,$sp,0x30
/*  f0172cc:	8f2b0004 */ 	lw	$t3,0x4($t9)
/*  f0172d0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0172d4:	8f210008 */ 	lw	$at,0x8($t9)
/*  f0172d8:	adcb0004 */ 	sw	$t3,0x4($t6)
/*  f0172dc:	02202825 */ 	move	$a1,$s1
/*  f0172e0:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0172e4:	96040274 */ 	lhu	$a0,0x274($s0)
/*  f0172e8:	02403025 */ 	move	$a2,$s2
/*  f0172ec:	0fc6a0c5 */ 	jal	modeldefLoad
/*  f0172f0:	00003825 */ 	move	$a3,$zero
/*  f0172f4:	ae020270 */ 	sw	$v0,0x270($s0)
/*  f0172f8:	0fc59da4 */ 	jal	fileGetLoadedSize
/*  f0172fc:	96040274 */ 	lhu	$a0,0x274($s0)
/*  f017300:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f017304:	346c003f */ 	ori	$t4,$v1,0x3f
/*  f017308:	398d003f */ 	xori	$t5,$t4,0x3f
/*  f01730c:	022d8821 */ 	addu	$s1,$s1,$t5
/*  f017310:	024d9023 */ 	subu	$s2,$s2,$t5
/*  f017314:	0c008a0e */ 	jal	modelCalculateRwDataLen
/*  f017318:	8e040270 */ 	lw	$a0,0x270($s0)
/*  f01731c:	0fc2d04b */ 	jal	modelInstantiateWithoutAnim
/*  f017320:	8e040270 */ 	lw	$a0,0x270($s0)
/*  f017324:	3c038006 */ 	lui	$v1,0x8006
/*  f017328:	246323ec */ 	addiu	$v1,$v1,0x23ec
/*  f01732c:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f017330:	00402025 */ 	move	$a0,$v0
/*  f017334:	0c006bbe */ 	jal	modelSetScale
/*  f017338:	3c053f80 */ 	lui	$a1,0x3f80
/*  f01733c:	3c048006 */ 	lui	$a0,0x8006
/*  f017340:	8c8423ec */ 	lw	$a0,0x23ec($a0)
/*  f017344:	0c006b35 */ 	jal	modelSetRootPosition
/*  f017348:	27a50030 */ 	addiu	$a1,$sp,0x30
/*  f01734c:	8e040268 */ 	lw	$a0,0x268($s0)
/*  f017350:	0c006a57 */ 	jal	modelGetPartRodata
/*  f017354:	24050002 */ 	li	$a1,0x2
/*  f017358:	84430010 */ 	lh	$v1,0x10($v0)
/*  f01735c:	3c04800a */ 	lui	$a0,0x800a
/*  f017360:	2484d338 */ 	addiu	$a0,$a0,-11464
/*  f017364:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f017368:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f01736c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f017370:	27030007 */ 	addiu	$v1,$t8,0x7
/*  f017374:	346f0007 */ 	ori	$t7,$v1,0x7
/*  f017378:	39ea0007 */ 	xori	$t2,$t7,0x7
/*  f01737c:	ac910000 */ 	sw	$s1,0x0($a0)
/*  f017380:	022a8821 */ 	addu	$s1,$s1,$t2
/*  f017384:	ac910004 */ 	sw	$s1,0x4($a0)
/*  f017388:	94430016 */ 	lhu	$v1,0x16($v0)
/*  f01738c:	3c05800a */ 	lui	$a1,0x800a
/*  f017390:	24a5d340 */ 	addiu	$a1,$a1,-11456
/*  f017394:	00037080 */ 	sll	$t6,$v1,0x2
/*  f017398:	25c30007 */ 	addiu	$v1,$t6,0x7
/*  f01739c:	022a8821 */ 	addu	$s1,$s1,$t2
/*  f0173a0:	34790007 */ 	ori	$t9,$v1,0x7
/*  f0173a4:	3b2b0007 */ 	xori	$t3,$t9,0x7
/*  f0173a8:	acb10000 */ 	sw	$s1,0x0($a1)
/*  f0173ac:	022b8821 */ 	addu	$s1,$s1,$t3
/*  f0173b0:	acb10004 */ 	sw	$s1,0x4($a1)
/*  f0173b4:	3c01800a */ 	lui	$at,0x800a
/*  f0173b8:	ac20d348 */ 	sw	$zero,-0x2cb8($at)
/*  f0173bc:	24100001 */ 	li	$s0,0x1
/*  f0173c0:	3c018006 */ 	lui	$at,0x8006
/*  f0173c4:	ac3023d4 */ 	sw	$s0,0x23d4($at)
/*  f0173c8:	0c0051ea */ 	jal	joy00014810
/*  f0173cc:	00002025 */ 	move	$a0,$zero
/*  f0173d0:	3c0c8006 */ 	lui	$t4,0x8006
/*  f0173d4:	8d8c2388 */ 	lw	$t4,0x2388($t4)
/*  f0173d8:	3c018006 */ 	lui	$at,0x8006
/*  f0173dc:	ac302668 */ 	sw	$s0,0x2668($at)
/*  f0173e0:	3c018006 */ 	lui	$at,0x8006
/*  f0173e4:	11800003 */ 	beqz	$t4,.JF0f0173f4
/*  f0173e8:	ac20266c */ 	sw	$zero,0x266c($at)
/*  f0173ec:	0fc05f58 */ 	jal	titleSkipToPdTitle
/*  f0173f0:	00000000 */ 	nop
.JF0f0173f4:
/*  f0173f4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0173f8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0173fc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f017400:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f017404:	03e00008 */ 	jr	$ra
/*  f017408:	27bd0080 */ 	addiu	$sp,$sp,0x80
);
#else
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
/*  f016d94:	0fc69de5 */ 	jal	modeldefLoad
/*  f016d98:	02002825 */ 	or	$a1,$s0,$zero
/*  f016d9c:	ae220240 */ 	sw	$v0,0x240($s1)
/*  f016da0:	0fc59ca0 */ 	jal	fileGetLoadedSize
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
/*  f016dcc:	0fc2cca0 */ 	jal	modelInstantiateWithAnim
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
/*  f016e2c:	0fc69de5 */ 	jal	modeldefLoad
/*  f016e30:	00003825 */ 	or	$a3,$zero,$zero
/*  f016e34:	ae220248 */ 	sw	$v0,0x248($s1)
/*  f016e38:	0fc59ca0 */ 	jal	fileGetLoadedSize
/*  f016e3c:	9624024c */ 	lhu	$a0,0x24c($s1)
/*  f016e40:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016e44:	346e003f */ 	ori	$t6,$v1,0x3f
/*  f016e48:	39cf003f */ 	xori	$t7,$t6,0x3f
/*  f016e4c:	020f8021 */ 	addu	$s0,$s0,$t7
/*  f016e50:	024f9023 */ 	subu	$s2,$s2,$t7
/*  f016e54:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f016e58:	8e240248 */ 	lw	$a0,0x248($s1)
/*  f016e5c:	0fc2cca0 */ 	jal	modelInstantiateWithAnim
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
/*  f016ebc:	0fc69de5 */ 	jal	modeldefLoad
/*  f016ec0:	00003825 */ 	or	$a3,$zero,$zero
/*  f016ec4:	ae220268 */ 	sw	$v0,0x268($s1)
/*  f016ec8:	0fc59ca0 */ 	jal	fileGetLoadedSize
/*  f016ecc:	9624026c */ 	lhu	$a0,0x26c($s1)
/*  f016ed0:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016ed4:	3479003f */ 	ori	$t9,$v1,0x3f
/*  f016ed8:	3b2c003f */ 	xori	$t4,$t9,0x3f
/*  f016edc:	020c8021 */ 	addu	$s0,$s0,$t4
/*  f016ee0:	024c9023 */ 	subu	$s2,$s2,$t4
/*  f016ee4:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f016ee8:	8e240268 */ 	lw	$a0,0x268($s1)
/*  f016eec:	0fc2cc2b */ 	jal	modelInstantiateWithoutAnim
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
/*  f016f4c:	0fc69de5 */ 	jal	modeldefLoad
/*  f016f50:	00003825 */ 	or	$a3,$zero,$zero
/*  f016f54:	ae220270 */ 	sw	$v0,0x270($s1)
/*  f016f58:	0fc59ca0 */ 	jal	fileGetLoadedSize
/*  f016f5c:	96240274 */ 	lhu	$a0,0x274($s1)
/*  f016f60:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016f64:	346a003f */ 	ori	$t2,$v1,0x3f
/*  f016f68:	3948003f */ 	xori	$t0,$t2,0x3f
/*  f016f6c:	02088021 */ 	addu	$s0,$s0,$t0
/*  f016f70:	02489023 */ 	subu	$s2,$s2,$t0
/*  f016f74:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f016f78:	8e240270 */ 	lw	$a0,0x270($s1)
/*  f016f7c:	0fc2cc2b */ 	jal	modelInstantiateWithoutAnim
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
//		g_ModelStates[MODEL_NLOGO].filedata = modeldefLoad(g_ModelStates[MODEL_NLOGO].fileid, nextaddr, 0x47800, 0);
//		size = ALIGN64(fileGetLoadedSize(g_ModelStates[MODEL_NLOGO].fileid));
//		nextaddr += size;
//		remaining = 0x47800 - size;
//		modelCalculateRwDataLen(g_ModelStates[MODEL_NLOGO].filedata);
//
//		g_TitleModel = modelInstantiateWithAnim(g_ModelStates[MODEL_NLOGO].filedata);
//		modelSetScale(g_TitleModel, 1);
//		modelSetRootPosition(g_TitleModel, &coord);
//	}
//
//	{
//		struct coord coord = {0, 0, 0}; // var80062744
//		g_ModelStates[MODEL_NLOGO2].filedata = modeldefLoad(g_ModelStates[MODEL_NLOGO2].fileid, nextaddr, remaining, 0);
//		size = ALIGN64(fileGetLoadedSize(g_ModelStates[MODEL_NLOGO2].fileid));
//		nextaddr += size;
//		remaining -= size;
//		modelCalculateRwDataLen(g_ModelStates[MODEL_NLOGO2].filedata);
//
//		g_TitleModelNLogo2 = modelInstantiateWithAnim(g_ModelStates[MODEL_NLOGO2].filedata);
//		modelSetScale(g_TitleModelNLogo2, 1);
//		modelSetRootPosition(g_TitleModelNLogo2, &coord);
//	}
//
//	{
//		struct coord coord = {0, 0, 0}; // var80062750
//		g_ModelStates[MODEL_PDTWO].filedata = modeldefLoad(g_ModelStates[MODEL_PDTWO].fileid, nextaddr, remaining, 0);
//		size = ALIGN64(fileGetLoadedSize(g_ModelStates[MODEL_PDTWO].fileid));
//		nextaddr += size;
//		remaining -= size;
//		modelCalculateRwDataLen(g_ModelStates[MODEL_PDTWO].filedata);
//
//		g_TitleModelPdTwo = modelInstantiateWithoutAnim(g_ModelStates[MODEL_PDTWO].filedata);
//		modelSetScale(g_TitleModelPdTwo, 1);
//		modelSetRootPosition(g_TitleModelPdTwo, &coord);
//	}
//
//	{
//		struct coord coord = {0, 0, 0}; // var8006275c
//		g_ModelStates[MODEL_PDTHREE].filedata = modeldefLoad(g_ModelStates[MODEL_PDTHREE].fileid, nextaddr, remaining, 0);
//		size = ALIGN64(fileGetLoadedSize(g_ModelStates[MODEL_PDTHREE].fileid));
//		nextaddr += size;
//		remaining -= size;
//		modelCalculateRwDataLen(g_ModelStates[MODEL_PDTHREE].filedata);
//
//		g_TitleModelPdThree = modelInstantiateWithoutAnim(g_ModelStates[MODEL_PDTHREE].filedata);
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
#endif

void titleExitPdLogo(void)
{
	modelFree(g_TitleModel);
	modelFree(g_TitleModelNLogo2);
	modelFree(g_TitleModelPdTwo);
	modelFree(g_TitleModelPdThree);

#if VERSION == VERSION_JPN_FINAL
	modelFree(var800623f4jf);
	modelFree(var800623f8jf);
	modelFree(var800623fcjf);
#endif

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

#if VERSION == VERSION_JPN_FINAL
	if (g_TitleTimer > 950) {
		g_PdLogoTriggerExit = true;
	}
#endif

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

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel titleRenderPdLogo
.late_rodata
glabel var7f1a8f88jf
.word 0x4087b1f9
.word 0x3c9a6417
.word 0x3ef13c64
.word 0x3eb33333
.word 0x3fc907a9
.word 0x39459ed6
.word 0x3c9a6417
.word 0x40c907a9
.word 0x40c907a9
.word 0x40c907a9
.word 0x40c907a9
.word 0x3b83126f
.word 0x3f4ccccd
.word 0x38ed2501
.word 0x3c3944e9
.word 0x40c907a9
.word 0x3bf5c28f
.word 0x3d4ccccd
.word 0x3c23d70a
.word 0x3f7d70a4
.word 0x3c23d70a
.word 0x3c23d70a
.word 0x3bcddaca
.word 0x3c8b4396
.word 0x40490fdb
.word 0x3e19999a
.word 0x3c23d70a
.word 0x3e9db22d
.text
/*  f017ea0:	27bdfb20 */ 	addiu	$sp,$sp,-1248
/*  f017ea4:	3c0f8006 */ 	lui	$t7,0x8006
/*  f017ea8:	3c028006 */ 	lui	$v0,0x8006
/*  f017eac:	25ef275c */ 	addiu	$t7,$t7,0x275c
/*  f017eb0:	24422668 */ 	addiu	$v0,$v0,0x2668
/*  f017eb4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f017eb8:	afa404e0 */ 	sw	$a0,0x4e0($sp)
/*  f017ebc:	25f9003c */ 	addiu	$t9,$t7,0x3c
/*  f017ec0:	27ae04a0 */ 	addiu	$t6,$sp,0x4a0
.JF0f017ec4:
/*  f017ec4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f017ec8:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f017ecc:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f017ed0:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f017ed4:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f017ed8:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f017edc:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f017ee0:	15f9fff8 */ 	bne	$t7,$t9,.JF0f017ec4
/*  f017ee4:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f017ee8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f017eec:	3c038006 */ 	lui	$v1,0x8006
/*  f017ef0:	3c048006 */ 	lui	$a0,0x8006
/*  f017ef4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f017ef8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f017efc:	24842710 */ 	addiu	$a0,$a0,0x2710
/*  f017f00:	24632718 */ 	addiu	$v1,$v1,0x2718
/*  f017f04:	13000048 */ 	beqz	$t8,.JF0f018028
/*  f017f08:	24090001 */ 	li	$t1,0x1
/*  f017f0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f017f10:	44818000 */ 	mtc1	$at,$f16
/*  f017f14:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017f18:	c4248f88 */ 	lwc1	$f4,-0x7078($at)
/*  f017f1c:	3c018006 */ 	lui	$at,0x8006
/*  f017f20:	44807000 */ 	mtc1	$zero,$f14
/*  f017f24:	e42426ec */ 	swc1	$f4,0x26ec($at)
/*  f017f28:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017f2c:	c4268f8c */ 	lwc1	$f6,-0x7074($at)
/*  f017f30:	3c018006 */ 	lui	$at,0x8006
/*  f017f34:	3c0a8006 */ 	lui	$t2,0x8006
/*  f017f38:	e42626f0 */ 	swc1	$f6,0x26f0($at)
/*  f017f3c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017f40:	c4288f90 */ 	lwc1	$f8,-0x7070($at)
/*  f017f44:	3c018006 */ 	lui	$at,0x8006
/*  f017f48:	254a2724 */ 	addiu	$t2,$t2,0x2724
/*  f017f4c:	e42826f4 */ 	swc1	$f8,0x26f4($at)
/*  f017f50:	3c018006 */ 	lui	$at,0x8006
/*  f017f54:	e42e26f8 */ 	swc1	$f14,0x26f8($at)
/*  f017f58:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017f5c:	c42a8f94 */ 	lwc1	$f10,-0x706c($at)
/*  f017f60:	3c018006 */ 	lui	$at,0x8006
/*  f017f64:	3c1f8006 */ 	lui	$ra,0x8006
/*  f017f68:	e42a26fc */ 	swc1	$f10,0x26fc($at)
/*  f017f6c:	3c018006 */ 	lui	$at,0x8006
/*  f017f70:	e42e2700 */ 	swc1	$f14,0x2700($at)
/*  f017f74:	3c018006 */ 	lui	$at,0x8006
/*  f017f78:	ac202704 */ 	sw	$zero,0x2704($at)
/*  f017f7c:	3c018006 */ 	lui	$at,0x8006
/*  f017f80:	e430270c */ 	swc1	$f16,0x270c($at)
/*  f017f84:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f017f88:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f017f8c:	3c018006 */ 	lui	$at,0x8006
/*  f017f90:	ac202714 */ 	sw	$zero,0x2714($at)
/*  f017f94:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f017f98:	3c018006 */ 	lui	$at,0x8006
/*  f017f9c:	ac20271c */ 	sw	$zero,0x271c($at)
/*  f017fa0:	3c018006 */ 	lui	$at,0x8006
/*  f017fa4:	ac202720 */ 	sw	$zero,0x2720($at)
/*  f017fa8:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f017fac:	3c018006 */ 	lui	$at,0x8006
/*  f017fb0:	ac202728 */ 	sw	$zero,0x2728($at)
/*  f017fb4:	27ff272c */ 	addiu	$ra,$ra,0x272c
/*  f017fb8:	afe00000 */ 	sw	$zero,0x0($ra)
/*  f017fbc:	3c018006 */ 	lui	$at,0x8006
/*  f017fc0:	ac292748 */ 	sw	$t1,0x2748($at)
/*  f017fc4:	3c018006 */ 	lui	$at,0x8006
/*  f017fc8:	3c0c8006 */ 	lui	$t4,0x8006
/*  f017fcc:	ac202730 */ 	sw	$zero,0x2730($at)
/*  f017fd0:	258c2734 */ 	addiu	$t4,$t4,0x2734
/*  f017fd4:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f017fd8:	3c018006 */ 	lui	$at,0x8006
/*  f017fdc:	e42e2738 */ 	swc1	$f14,0x2738($at)
/*  f017fe0:	3c018006 */ 	lui	$at,0x8006
/*  f017fe4:	ac202740 */ 	sw	$zero,0x2740($at)
/*  f017fe8:	3c018006 */ 	lui	$at,0x8006
/*  f017fec:	2419ffff */ 	li	$t9,-1
/*  f017ff0:	3c0d8006 */ 	lui	$t5,0x8006
/*  f017ff4:	ac39273c */ 	sw	$t9,0x273c($at)
/*  f017ff8:	25ad2744 */ 	addiu	$t5,$t5,0x2744
/*  f017ffc:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f018000:	3c018006 */ 	lui	$at,0x8006
/*  f018004:	ac202750 */ 	sw	$zero,0x2750($at)
/*  f018008:	3c017f1b */ 	lui	$at,0x7f1b
/*  f01800c:	c4248f98 */ 	lwc1	$f4,-0x7068($at)
/*  f018010:	3c018006 */ 	lui	$at,0x8006
/*  f018014:	e424274c */ 	swc1	$f4,0x274c($at)
/*  f018018:	3c018006 */ 	lui	$at,0x8006
/*  f01801c:	ac202754 */ 	sw	$zero,0x2754($at)
/*  f018020:	3c018006 */ 	lui	$at,0x8006
/*  f018024:	e42e2758 */ 	swc1	$f14,0x2758($at)
.JF0f018028:
/*  f018028:	3c048006 */ 	lui	$a0,0x8006
/*  f01802c:	24842710 */ 	addiu	$a0,$a0,0x2710
/*  f018030:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f018034:	3c013f80 */ 	lui	$at,0x3f80
/*  f018038:	44818000 */ 	mtc1	$at,$f16
/*  f01803c:	3c038006 */ 	lui	$v1,0x8006
/*  f018040:	3c0a8006 */ 	lui	$t2,0x8006
/*  f018044:	3c0c8006 */ 	lui	$t4,0x8006
/*  f018048:	3c0d8006 */ 	lui	$t5,0x8006
/*  f01804c:	3c1f8006 */ 	lui	$ra,0x8006
/*  f018050:	44807000 */ 	mtc1	$zero,$f14
/*  f018054:	27ff272c */ 	addiu	$ra,$ra,0x272c
/*  f018058:	25ad2744 */ 	addiu	$t5,$t5,0x2744
/*  f01805c:	258c2734 */ 	addiu	$t4,$t4,0x2734
/*  f018060:	254a2724 */ 	addiu	$t2,$t2,0x2724
/*  f018064:	24632718 */ 	addiu	$v1,$v1,0x2718
/*  f018068:	10400009 */ 	beqz	$v0,.JF0f018090
/*  f01806c:	24090001 */ 	li	$t1,0x1
/*  f018070:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f018074:	29e10004 */ 	slti	$at,$t7,0x4
/*  f018078:	14200005 */ 	bnez	$at,.JF0f018090
/*  f01807c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f018080:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f018084:	3c018006 */ 	lui	$at,0x8006
/*  f018088:	ac292714 */ 	sw	$t1,0x2714($at)
/*  f01808c:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f018090:
/*  f018090:	3c188006 */ 	lui	$t8,0x8006
/*  f018094:	8f182728 */ 	lw	$t8,0x2728($t8)
/*  f018098:	3c0b8006 */ 	lui	$t3,0x8006
/*  f01809c:	256b2708 */ 	addiu	$t3,$t3,0x2708
/*  f0180a0:	1300004c */ 	beqz	$t8,.JF0f0181d4
/*  f0180a4:	3c018006 */ 	lui	$at,0x8006
/*  f0180a8:	c42026ec */ 	lwc1	$f0,0x26ec($at)
/*  f0180ac:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f0180b0:	3c048006 */ 	lui	$a0,0x8006
/*  f0180b4:	3c068006 */ 	lui	$a2,0x8006
/*  f0180b8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0180bc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0180c0:	24c626f0 */ 	addiu	$a2,$a2,0x26f0
/*  f0180c4:	248426ec */ 	addiu	$a0,$a0,0x26ec
/*  f0180c8:	4502003b */ 	bc1fl	.JF0f0181b8
/*  f0180cc:	4600103e */ 	c.le.s	$f2,$f0
/*  f0180d0:	c4208f9c */ 	lwc1	$f0,-0x7064($at)
/*  f0180d4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0180d8:	c4268fa0 */ 	lwc1	$f6,-0x7060($at)
/*  f0180dc:	44051000 */ 	mfc1	$a1,$f2
/*  f0180e0:	44070000 */ 	mfc1	$a3,$f0
/*  f0180e4:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f0180e8:	0fc1ba89 */ 	jal	applySpeed
/*  f0180ec:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0180f0:	3c028006 */ 	lui	$v0,0x8006
/*  f0180f4:	3c0b8006 */ 	lui	$t3,0x8006
/*  f0180f8:	256b2708 */ 	addiu	$t3,$t3,0x2708
/*  f0180fc:	244226ec */ 	addiu	$v0,$v0,0x26ec
/*  f018100:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f018104:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f018108:	3c038006 */ 	lui	$v1,0x8006
/*  f01810c:	3c0a8006 */ 	lui	$t2,0x8006
/*  f018110:	4600103e */ 	c.le.s	$f2,$f0
/*  f018114:	3c0c8006 */ 	lui	$t4,0x8006
/*  f018118:	3c0d8006 */ 	lui	$t5,0x8006
/*  f01811c:	3c1f8006 */ 	lui	$ra,0x8006
/*  f018120:	27ff272c */ 	addiu	$ra,$ra,0x272c
/*  f018124:	25ad2744 */ 	addiu	$t5,$t5,0x2744
/*  f018128:	258c2734 */ 	addiu	$t4,$t4,0x2734
/*  f01812c:	254a2724 */ 	addiu	$t2,$t2,0x2724
/*  f018130:	24632718 */ 	addiu	$v1,$v1,0x2718
/*  f018134:	45000006 */ 	bc1f	.JF0f018150
/*  f018138:	24090001 */ 	li	$t1,0x1
/*  f01813c:	44804000 */ 	mtc1	$zero,$f8
/*  f018140:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f018144:	3c018006 */ 	lui	$at,0x8006
/*  f018148:	e42826f0 */ 	swc1	$f8,0x26f0($at)
/*  f01814c:	c4400000 */ 	lwc1	$f0,0x0($v0)
.JF0f018150:
/*  f018150:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018154:	c42c8fa4 */ 	lwc1	$f12,-0x705c($at)
/*  f018158:	4600603e */ 	c.le.s	$f12,$f0
/*  f01815c:	00000000 */ 	nop
/*  f018160:	45020009 */ 	bc1fl	.JF0f018188
/*  f018164:	44803000 */ 	mtc1	$zero,$f6
/*  f018168:	460c0281 */ 	sub.s	$f10,$f0,$f12
/*  f01816c:	460c1101 */ 	sub.s	$f4,$f2,$f12
/*  f018170:	e44a0000 */ 	swc1	$f10,0x0($v0)
/*  f018174:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f018178:	e5640000 */ 	swc1	$f4,0x0($t3)
/*  f01817c:	1000000d */ 	b	.JF0f0181b4
/*  f018180:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f018184:	44803000 */ 	mtc1	$zero,$f6
.JF0f018188:
/*  f018188:	00000000 */ 	nop
/*  f01818c:	4606003c */ 	c.lt.s	$f0,$f6
/*  f018190:	00000000 */ 	nop
/*  f018194:	45020008 */ 	bc1fl	.JF0f0181b8
/*  f018198:	4600103e */ 	c.le.s	$f2,$f0
/*  f01819c:	460c0200 */ 	add.s	$f8,$f0,$f12
/*  f0181a0:	460c1280 */ 	add.s	$f10,$f2,$f12
/*  f0181a4:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f0181a8:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f0181ac:	e56a0000 */ 	swc1	$f10,0x0($t3)
/*  f0181b0:	c5620000 */ 	lwc1	$f2,0x0($t3)
.JF0f0181b4:
/*  f0181b4:	4600103e */ 	c.le.s	$f2,$f0
.JF0f0181b8:
/*  f0181b8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0181bc:	44818000 */ 	mtc1	$at,$f16
/*  f0181c0:	44807000 */ 	mtc1	$zero,$f14
/*  f0181c4:	45000023 */ 	bc1f	.JF0f018254
/*  f0181c8:	3c018006 */ 	lui	$at,0x8006
/*  f0181cc:	10000021 */ 	b	.JF0f018254
/*  f0181d0:	ac202728 */ 	sw	$zero,0x2728($at)
.JF0f0181d4:
/*  f0181d4:	3c198006 */ 	lui	$t9,0x8006
/*  f0181d8:	8f392714 */ 	lw	$t9,0x2714($t9)
/*  f0181dc:	1320001d */ 	beqz	$t9,.JF0f018254
/*  f0181e0:	3c08800a */ 	lui	$t0,0x800a
/*  f0181e4:	2508a630 */ 	addiu	$t0,$t0,-22992
/*  f0181e8:	8d0f0038 */ 	lw	$t7,0x38($t0)
/*  f0181ec:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0181f0:	c42c8fac */ 	lwc1	$f12,-0x7054($at)
/*  f0181f4:	448f3000 */ 	mtc1	$t7,$f6
/*  f0181f8:	3c018006 */ 	lui	$at,0x8006
/*  f0181fc:	c42426f0 */ 	lwc1	$f4,0x26f0($at)
/*  f018200:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f018204:	3c028006 */ 	lui	$v0,0x8006
/*  f018208:	244226ec */ 	addiu	$v0,$v0,0x26ec
/*  f01820c:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f018210:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f018214:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f018218:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f01821c:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f018220:	4600603e */ 	c.le.s	$f12,$f0
/*  f018224:	00000000 */ 	nop
/*  f018228:	45020005 */ 	bc1fl	.JF0f018240
/*  f01822c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f018230:	460c0201 */ 	sub.s	$f8,$f0,$f12
/*  f018234:	10000007 */ 	b	.JF0f018254
/*  f018238:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f01823c:	460e003c */ 	c.lt.s	$f0,$f14
.JF0f018240:
/*  f018240:	00000000 */ 	nop
/*  f018244:	45020004 */ 	bc1fl	.JF0f018258
/*  f018248:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f01824c:	460c0180 */ 	add.s	$f6,$f0,$f12
/*  f018250:	e4460000 */ 	swc1	$f6,0x0($v0)
.JF0f018254:
/*  f018254:	8c620000 */ 	lw	$v0,0x0($v1)
.JF0f018258:
/*  f018258:	3c08800a */ 	lui	$t0,0x800a
/*  f01825c:	3c0b8006 */ 	lui	$t3,0x8006
/*  f018260:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018264:	c42c8fb0 */ 	lwc1	$f12,-0x7050($at)
/*  f018268:	256b2708 */ 	addiu	$t3,$t3,0x2708
/*  f01826c:	1040001b */ 	beqz	$v0,.JF0f0182dc
/*  f018270:	2508a630 */ 	addiu	$t0,$t0,-22992
/*  f018274:	8d0e0038 */ 	lw	$t6,0x38($t0)
/*  f018278:	24190050 */ 	li	$t9,0x50
/*  f01827c:	3c018006 */ 	lui	$at,0x8006
/*  f018280:	004ec021 */ 	addu	$t8,$v0,$t6
/*  f018284:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f018288:	1b000009 */ 	blez	$t8,.JF0f0182b0
/*  f01828c:	03001025 */ 	move	$v0,$t8
/*  f018290:	44825000 */ 	mtc1	$v0,$f10
/*  f018294:	44994000 */ 	mtc1	$t9,$f8
/*  f018298:	3c018006 */ 	lui	$at,0x8006
/*  f01829c:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0182a0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0182a4:	46062283 */ 	div.s	$f10,$f4,$f6
/*  f0182a8:	10000002 */ 	b	.JF0f0182b4
/*  f0182ac:	e42a2700 */ 	swc1	$f10,0x2700($at)
.JF0f0182b0:
/*  f0182b0:	e42e2700 */ 	swc1	$f14,0x2700($at)
.JF0f0182b4:
/*  f0182b4:	28410051 */ 	slti	$at,$v0,0x51
/*  f0182b8:	14200008 */ 	bnez	$at,.JF0f0182dc
/*  f0182bc:	00000000 */ 	nop
/*  f0182c0:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f0182c4:	3c018006 */ 	lui	$at,0x8006
/*  f0182c8:	ac29271c */ 	sw	$t1,0x271c($at)
/*  f0182cc:	3c018006 */ 	lui	$at,0x8006
/*  f0182d0:	e42e2700 */ 	swc1	$f14,0x2700($at)
/*  f0182d4:	3c018006 */ 	lui	$at,0x8006
/*  f0182d8:	ac292704 */ 	sw	$t1,0x2704($at)
.JF0f0182dc:
/*  f0182dc:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0182e0:	8def271c */ 	lw	$t7,0x271c($t7)
/*  f0182e4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0182e8:	51e0001b */ 	beqzl	$t7,.JF0f018358
/*  f0182ec:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f0182f0:	c4288fb4 */ 	lwc1	$f8,-0x704c($at)
/*  f0182f4:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f0182f8:	3c018006 */ 	lui	$at,0x8006
/*  f0182fc:	c42a2700 */ 	lwc1	$f10,0x2700($at)
/*  f018300:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f018304:	46065080 */ 	add.s	$f2,$f10,$f6
/*  f018308:	e4222700 */ 	swc1	$f2,0x2700($at)
/*  f01830c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018310:	c4248fb8 */ 	lwc1	$f4,-0x7048($at)
/*  f018314:	3c018006 */ 	lui	$at,0x8006
/*  f018318:	4602203e */ 	c.le.s	$f4,$f2
/*  f01831c:	00000000 */ 	nop
/*  f018320:	45020006 */ 	bc1fl	.JF0f01833c
/*  f018324:	4602803e */ 	c.le.s	$f16,$f2
/*  f018328:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f01832c:	55c00003 */ 	bnezl	$t6,.JF0f01833c
/*  f018330:	4602803e */ 	c.le.s	$f16,$f2
/*  f018334:	ad490000 */ 	sw	$t1,0x0($t2)
/*  f018338:	4602803e */ 	c.le.s	$f16,$f2
.JF0f01833c:
/*  f01833c:	00000000 */ 	nop
/*  f018340:	45020005 */ 	bc1fl	.JF0f018358
/*  f018344:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f018348:	e4302700 */ 	swc1	$f16,0x2700($at)
/*  f01834c:	3c018006 */ 	lui	$at,0x8006
/*  f018350:	ac20271c */ 	sw	$zero,0x271c($at)
/*  f018354:	8d430000 */ 	lw	$v1,0x0($t2)
.JF0f018358:
/*  f018358:	50600063 */ 	beqzl	$v1,.JF0f0184e8
/*  f01835c:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f018360:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f018364:	3c018006 */ 	lui	$at,0x8006
/*  f018368:	3c048006 */ 	lui	$a0,0x8006
/*  f01836c:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f018370:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f018374:	c42a26f4 */ 	lwc1	$f10,0x26f4($at)
/*  f018378:	3c068006 */ 	lui	$a2,0x8006
/*  f01837c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018380:	460a703c */ 	c.lt.s	$f14,$f10
/*  f018384:	24c626f8 */ 	addiu	$a2,$a2,0x26f8
/*  f018388:	248426f4 */ 	addiu	$a0,$a0,0x26f4
/*  f01838c:	45020022 */ 	bc1fl	.JF0f018418
/*  f018390:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f018394:	c4208fbc */ 	lwc1	$f0,-0x7044($at)
/*  f018398:	3c017f1b */ 	lui	$at,0x7f1b
/*  f01839c:	c4268fc0 */ 	lwc1	$f6,-0x7040($at)
/*  f0183a0:	44057000 */ 	mfc1	$a1,$f14
/*  f0183a4:	44070000 */ 	mfc1	$a3,$f0
/*  f0183a8:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f0183ac:	0fc1bb06 */ 	jal	applyRotation
/*  f0183b0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0183b4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0183b8:	c42c8fc4 */ 	lwc1	$f12,-0x703c($at)
/*  f0183bc:	3c018006 */ 	lui	$at,0x8006
/*  f0183c0:	44800000 */ 	mtc1	$zero,$f0
/*  f0183c4:	c42826f4 */ 	lwc1	$f8,0x26f4($at)
/*  f0183c8:	3c08800a */ 	lui	$t0,0x800a
/*  f0183cc:	3c0a8006 */ 	lui	$t2,0x8006
/*  f0183d0:	4600403e */ 	c.le.s	$f8,$f0
/*  f0183d4:	3c0b8006 */ 	lui	$t3,0x8006
/*  f0183d8:	3c0c8006 */ 	lui	$t4,0x8006
/*  f0183dc:	3c0d8006 */ 	lui	$t5,0x8006
/*  f0183e0:	3c1f8006 */ 	lui	$ra,0x8006
/*  f0183e4:	27ff272c */ 	addiu	$ra,$ra,0x272c
/*  f0183e8:	25ad2744 */ 	addiu	$t5,$t5,0x2744
/*  f0183ec:	258c2734 */ 	addiu	$t4,$t4,0x2734
/*  f0183f0:	256b2708 */ 	addiu	$t3,$t3,0x2708
/*  f0183f4:	254a2724 */ 	addiu	$t2,$t2,0x2724
/*  f0183f8:	2508a630 */ 	addiu	$t0,$t0,-22992
/*  f0183fc:	45000005 */ 	bc1f	.JF0f018414
/*  f018400:	24090001 */ 	li	$t1,0x1
/*  f018404:	3c018006 */ 	lui	$at,0x8006
/*  f018408:	e42026f4 */ 	swc1	$f0,0x26f4($at)
/*  f01840c:	3c018006 */ 	lui	$at,0x8006
/*  f018410:	e42026f8 */ 	swc1	$f0,0x26f8($at)
.JF0f018414:
/*  f018414:	8d430000 */ 	lw	$v1,0x0($t2)
.JF0f018418:
/*  f018418:	3c013f80 */ 	lui	$at,0x3f80
/*  f01841c:	44818000 */ 	mtc1	$at,$f16
/*  f018420:	44807000 */ 	mtc1	$zero,$f14
/*  f018424:	2861001f */ 	slti	$at,$v1,0x1f
/*  f018428:	1420001b */ 	bnez	$at,.JF0f018498
/*  f01842c:	00000000 */ 	nop
/*  f018430:	8d0f0038 */ 	lw	$t7,0x38($t0)
/*  f018434:	006f7023 */ 	subu	$t6,$v1,$t7
/*  f018438:	29c1001f */ 	slti	$at,$t6,0x1f
/*  f01843c:	10200016 */ 	beqz	$at,.JF0f018498
/*  f018440:	3c018006 */ 	lui	$at,0x8006
/*  f018444:	ac202714 */ 	sw	$zero,0x2714($at)
/*  f018448:	3c018006 */ 	lui	$at,0x8006
/*  f01844c:	ac292728 */ 	sw	$t1,0x2728($at)
/*  f018450:	3c018006 */ 	lui	$at,0x8006
/*  f018454:	c42426ec */ 	lwc1	$f4,0x26ec($at)
/*  f018458:	3c014080 */ 	lui	$at,0x4080
/*  f01845c:	44815000 */ 	mtc1	$at,$f10
/*  f018460:	3c013e80 */ 	lui	$at,0x3e80
/*  f018464:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f018468:	460c3203 */ 	div.s	$f8,$f6,$f12
/*  f01846c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f018470:	44022000 */ 	mfc1	$v0,$f4
/*  f018474:	44812000 */ 	mtc1	$at,$f4
/*  f018478:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f01847c:	44825000 */ 	mtc1	$v0,$f10
/*  f018480:	00000000 */ 	nop
/*  f018484:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f018488:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f01848c:	00000000 */ 	nop
/*  f018490:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f018494:	e56a0000 */ 	swc1	$f10,0x0($t3)
.JF0f018498:
/*  f018498:	3c028006 */ 	lui	$v0,0x8006
/*  f01849c:	28610065 */ 	slti	$at,$v1,0x65
/*  f0184a0:	14200007 */ 	bnez	$at,.JF0f0184c0
/*  f0184a4:	8c422728 */ 	lw	$v0,0x2728($v0)
/*  f0184a8:	8d190038 */ 	lw	$t9,0x38($t0)
/*  f0184ac:	00797823 */ 	subu	$t7,$v1,$t9
/*  f0184b0:	29e10065 */ 	slti	$at,$t7,0x65
/*  f0184b4:	10200002 */ 	beqz	$at,.JF0f0184c0
/*  f0184b8:	00000000 */ 	nop
/*  f0184bc:	afe90000 */ 	sw	$t1,0x0($ra)
.JF0f0184c0:
/*  f0184c0:	14400008 */ 	bnez	$v0,.JF0f0184e4
/*  f0184c4:	3c018006 */ 	lui	$at,0x8006
/*  f0184c8:	c42626f4 */ 	lwc1	$f6,0x26f4($at)
/*  f0184cc:	460e303e */ 	c.le.s	$f6,$f14
/*  f0184d0:	00000000 */ 	nop
/*  f0184d4:	45020004 */ 	bc1fl	.JF0f0184e8
/*  f0184d8:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f0184dc:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f0184e0:	afe90000 */ 	sw	$t1,0x0($ra)
.JF0f0184e4:
/*  f0184e4:	8fee0000 */ 	lw	$t6,0x0($ra)
.JF0f0184e8:
/*  f0184e8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0184ec:	51c00010 */ 	beqzl	$t6,.JF0f018530
/*  f0184f0:	8d820000 */ 	lw	$v0,0x0($t4)
/*  f0184f4:	c4288fc8 */ 	lwc1	$f8,-0x7038($at)
/*  f0184f8:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f0184fc:	3c018006 */ 	lui	$at,0x8006
/*  f018500:	c426270c */ 	lwc1	$f6,0x270c($at)
/*  f018504:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f018508:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f01850c:	460e403e */ 	c.le.s	$f8,$f14
/*  f018510:	e428270c */ 	swc1	$f8,0x270c($at)
/*  f018514:	3c018006 */ 	lui	$at,0x8006
/*  f018518:	45020005 */ 	bc1fl	.JF0f018530
/*  f01851c:	8d820000 */ 	lw	$v0,0x0($t4)
/*  f018520:	e42e270c */ 	swc1	$f14,0x270c($at)
/*  f018524:	afe00000 */ 	sw	$zero,0x0($ra)
/*  f018528:	ad890000 */ 	sw	$t1,0x0($t4)
/*  f01852c:	8d820000 */ 	lw	$v0,0x0($t4)
.JF0f018530:
/*  f018530:	1040000a */ 	beqz	$v0,.JF0f01855c
/*  f018534:	00000000 */ 	nop
/*  f018538:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f01853c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f018540:	2b210015 */ 	slti	$at,$t9,0x15
/*  f018544:	14200005 */ 	bnez	$at,.JF0f01855c
/*  f018548:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f01854c:	3c028006 */ 	lui	$v0,0x8006
/*  f018550:	24422730 */ 	addiu	$v0,$v0,0x2730
/*  f018554:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f018558:	ac490000 */ 	sw	$t1,0x0($v0)
.JF0f01855c:
/*  f01855c:	3c028006 */ 	lui	$v0,0x8006
/*  f018560:	24422730 */ 	addiu	$v0,$v0,0x2730
/*  f018564:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f018568:	51c00004 */ 	beqzl	$t6,.JF0f01857c
/*  f01856c:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f018570:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f018574:	ada90000 */ 	sw	$t1,0x0($t5)
/*  f018578:	8da20000 */ 	lw	$v0,0x0($t5)
.JF0f01857c:
/*  f01857c:	1040000d */ 	beqz	$v0,.JF0f0185b4
/*  f018580:	00000000 */ 	nop
/*  f018584:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f018588:	3c0c8006 */ 	lui	$t4,0x8006
/*  f01858c:	258c273c */ 	addiu	$t4,$t4,0x273c
/*  f018590:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f018594:	1b200007 */ 	blez	$t9,.JF0f0185b4
/*  f018598:	adb90000 */ 	sw	$t9,0x0($t5)
/*  f01859c:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f0185a0:	3c018006 */ 	lui	$at,0x8006
/*  f0185a4:	ac292740 */ 	sw	$t1,0x2740($at)
/*  f0185a8:	ad890000 */ 	sw	$t1,0x0($t4)
/*  f0185ac:	3c018006 */ 	lui	$at,0x8006
/*  f0185b0:	ac292754 */ 	sw	$t1,0x2754($at)
.JF0f0185b4:
/*  f0185b4:	3c0c8006 */ 	lui	$t4,0x8006
/*  f0185b8:	258c273c */ 	addiu	$t4,$t4,0x273c
/*  f0185bc:	8d840000 */ 	lw	$a0,0x0($t4)
/*  f0185c0:	3c018006 */ 	lui	$at,0x8006
/*  f0185c4:	0480004e */ 	bltz	$a0,.JF0f018700
/*  f0185c8:	00000000 */ 	nop
/*  f0185cc:	ac292750 */ 	sw	$t1,0x2750($at)
/*  f0185d0:	28810002 */ 	slti	$at,$a0,0x2
/*  f0185d4:	1020000a */ 	beqz	$at,.JF0f018600
/*  f0185d8:	3c014140 */ 	lui	$at,0x4140
/*  f0185dc:	44813000 */ 	mtc1	$at,$f6
/*  f0185e0:	c5040044 */ 	lwc1	$f4,0x44($t0)
/*  f0185e4:	3c0b8006 */ 	lui	$t3,0x8006
/*  f0185e8:	256b2738 */ 	addiu	$t3,$t3,0x2738
/*  f0185ec:	46062283 */ 	div.s	$f10,$f4,$f6
/*  f0185f0:	c5680000 */ 	lwc1	$f8,0x0($t3)
/*  f0185f4:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0185f8:	1000000b */ 	b	.JF0f018628
/*  f0185fc:	e5640000 */ 	swc1	$f4,0x0($t3)
.JF0f018600:
/*  f018600:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018604:	c4268fcc */ 	lwc1	$f6,-0x7034($at)
/*  f018608:	c5080044 */ 	lwc1	$f8,0x44($t0)
/*  f01860c:	3c018006 */ 	lui	$at,0x8006
/*  f018610:	c4242738 */ 	lwc1	$f4,0x2738($at)
/*  f018614:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f018618:	3c0b8006 */ 	lui	$t3,0x8006
/*  f01861c:	256b2738 */ 	addiu	$t3,$t3,0x2738
/*  f018620:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f018624:	e4262738 */ 	swc1	$f6,0x2738($at)
.JF0f018628:
/*  f018628:	8d030034 */ 	lw	$v1,0x34($t0)
/*  f01862c:	00001025 */ 	move	$v0,$zero
/*  f018630:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018634:	18600015 */ 	blez	$v1,.JF0f01868c
/*  f018638:	3c0a800a */ 	lui	$t2,0x800a
/*  f01863c:	c4228fd0 */ 	lwc1	$f2,-0x7030($at)
/*  f018640:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018644:	c4208fd4 */ 	lwc1	$f0,-0x702c($at)
/*  f018648:	254ad34c */ 	addiu	$t2,$t2,-11444
/*  f01864c:	c54a0000 */ 	lwc1	$f10,0x0($t2)
/*  f018650:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f018654:	0043082a */ 	slt	$at,$v0,$v1
/*  f018658:	460a0482 */ 	mul.s	$f18,$f0,$f10
/*  f01865c:	5020000a */ 	beqzl	$at,.JF0f018688
/*  f018660:	46029280 */ 	add.s	$f10,$f18,$f2
/*  f018664:	46029280 */ 	add.s	$f10,$f18,$f2
.JF0f018668:
/*  f018668:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f01866c:	0043082a */ 	slt	$at,$v0,$v1
/*  f018670:	e54a0000 */ 	swc1	$f10,0x0($t2)
/*  f018674:	c54a0000 */ 	lwc1	$f10,0x0($t2)
/*  f018678:	460a0482 */ 	mul.s	$f18,$f0,$f10
/*  f01867c:	5420fffa */ 	bnezl	$at,.JF0f018668
/*  f018680:	46029280 */ 	add.s	$f10,$f18,$f2
/*  f018684:	46029280 */ 	add.s	$f10,$f18,$f2
.JF0f018688:
/*  f018688:	e54a0000 */ 	swc1	$f10,0x0($t2)
.JF0f01868c:
/*  f01868c:	c5660000 */ 	lwc1	$f6,0x0($t3)
/*  f018690:	3c0a800a */ 	lui	$t2,0x800a
/*  f018694:	3c05800a */ 	lui	$a1,0x800a
/*  f018698:	4606803e */ 	c.le.s	$f16,$f6
/*  f01869c:	254ad34c */ 	addiu	$t2,$t2,-11444
/*  f0186a0:	24a5d358 */ 	addiu	$a1,$a1,-11432
/*  f0186a4:	3c01800a */ 	lui	$at,0x800a
/*  f0186a8:	45000015 */ 	bc1f	.JF0f018700
/*  f0186ac:	3c02800a */ 	lui	$v0,0x800a
/*  f0186b0:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*  f0186b4:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f0186b8:	3c03800a */ 	lui	$v1,0x800a
/*  f0186bc:	2463d364 */ 	addiu	$v1,$v1,-11420
/*  f0186c0:	2442d358 */ 	addiu	$v0,$v0,-11432
/*  f0186c4:	e428d350 */ 	swc1	$f8,-0x2cb0($at)
.JF0f0186c8:
/*  f0186c8:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f0186cc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0186d0:	1443fffd */ 	bne	$v0,$v1,.JF0f0186c8
/*  f0186d4:	e444fffc */ 	swc1	$f4,-0x4($v0)
/*  f0186d8:	28810004 */ 	slti	$at,$a0,0x4
/*  f0186dc:	14200003 */ 	bnez	$at,.JF0f0186ec
/*  f0186e0:	248e0001 */ 	addiu	$t6,$a0,0x1
/*  f0186e4:	10000003 */ 	b	.JF0f0186f4
/*  f0186e8:	e4a0000c */ 	swc1	$f0,0xc($a1)
.JF0f0186ec:
/*  f0186ec:	c54a0000 */ 	lwc1	$f10,0x0($t2)
/*  f0186f0:	e4aa000c */ 	swc1	$f10,0xc($a1)
.JF0f0186f4:
/*  f0186f4:	e56e0000 */ 	swc1	$f14,0x0($t3)
/*  f0186f8:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0186fc:	01c02025 */ 	move	$a0,$t6
.JF0f018700:
/*  f018700:	3c188006 */ 	lui	$t8,0x8006
/*  f018704:	8f182750 */ 	lw	$t8,0x2750($t8)
/*  f018708:	3c0b8006 */ 	lui	$t3,0x8006
/*  f01870c:	256b2738 */ 	addiu	$t3,$t3,0x2738
/*  f018710:	1300000f */ 	beqz	$t8,.JF0f018750
/*  f018714:	3c198006 */ 	lui	$t9,0x8006
/*  f018718:	3c017f1b */ 	lui	$at,0x7f1b
/*  f01871c:	c4268fe0 */ 	lwc1	$f6,-0x7020($at)
/*  f018720:	c508004c */ 	lwc1	$f8,0x4c($t0)
/*  f018724:	3c018006 */ 	lui	$at,0x8006
/*  f018728:	c42a274c */ 	lwc1	$f10,0x274c($at)
/*  f01872c:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f018730:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f018734:	4606603e */ 	c.le.s	$f12,$f6
/*  f018738:	e426274c */ 	swc1	$f6,0x274c($at)
/*  f01873c:	45000004 */ 	bc1f	.JF0f018750
/*  f018740:	00000000 */ 	nop
/*  f018744:	460c3201 */ 	sub.s	$f8,$f6,$f12
/*  f018748:	3c018006 */ 	lui	$at,0x8006
/*  f01874c:	e428274c */ 	swc1	$f8,0x274c($at)
.JF0f018750:
/*  f018750:	8f392754 */ 	lw	$t9,0x2754($t9)
/*  f018754:	3c038006 */ 	lui	$v1,0x8006
/*  f018758:	24632720 */ 	addiu	$v1,$v1,0x2720
/*  f01875c:	13200012 */ 	beqz	$t9,.JF0f0187a8
/*  f018760:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018764:	c42a8fe4 */ 	lwc1	$f10,-0x701c($at)
/*  f018768:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f01876c:	3c0d8006 */ 	lui	$t5,0x8006
/*  f018770:	25ad2758 */ 	addiu	$t5,$t5,0x2758
/*  f018774:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f018778:	c5a80000 */ 	lwc1	$f8,0x0($t5)
/*  f01877c:	3c018006 */ 	lui	$at,0x8006
/*  f018780:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f018784:	e42a2758 */ 	swc1	$f10,0x2758($at)
/*  f018788:	c5a40000 */ 	lwc1	$f4,0x0($t5)
/*  f01878c:	3c018006 */ 	lui	$at,0x8006
/*  f018790:	4604803e */ 	c.le.s	$f16,$f4
/*  f018794:	00000000 */ 	nop
/*  f018798:	45020004 */ 	bc1fl	.JF0f0187ac
/*  f01879c:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f0187a0:	e5b00000 */ 	swc1	$f16,0x0($t5)
/*  f0187a4:	ac202754 */ 	sw	$zero,0x2754($at)
.JF0f0187a8:
/*  f0187a8:	8c620000 */ 	lw	$v0,0x0($v1)
.JF0f0187ac:
/*  f0187ac:	10400009 */ 	beqz	$v0,.JF0f0187d4
/*  f0187b0:	00000000 */ 	nop
/*  f0187b4:	8d0f0038 */ 	lw	$t7,0x38($t0)
/*  f0187b8:	004f7021 */ 	addu	$t6,$v0,$t7
/*  f0187bc:	29c1003d */ 	slti	$at,$t6,0x3d
/*  f0187c0:	14200004 */ 	bnez	$at,.JF0f0187d4
/*  f0187c4:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0187c8:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f0187cc:	3c018006 */ 	lui	$at,0x8006
/*  f0187d0:	ac29266c */ 	sw	$t1,0x266c($at)
.JF0f0187d4:
/*  f0187d4:	04810008 */ 	bgez	$a0,.JF0f0187f8
/*  f0187d8:	00000000 */ 	nop
/*  f0187dc:	8fa404e0 */ 	lw	$a0,0x4e0($sp)
/*  f0187e0:	00002825 */ 	move	$a1,$zero
/*  f0187e4:	00003025 */ 	move	$a2,$zero
/*  f0187e8:	0c002faa */ 	jal	viSetFillColour
/*  f0187ec:	00003825 */ 	move	$a3,$zero
/*  f0187f0:	1000004d */ 	b	.JF0f018928
/*  f0187f4:	afa204e0 */ 	sw	$v0,0x4e0($sp)
.JF0f0187f8:
/*  f0187f8:	1480000d */ 	bnez	$a0,.JF0f018830
/*  f0187fc:	3c01437f */ 	lui	$at,0x437f
/*  f018800:	c5680000 */ 	lwc1	$f8,0x0($t3)
/*  f018804:	44813000 */ 	mtc1	$at,$f6
/*  f018808:	8fa404e0 */ 	lw	$a0,0x4e0($sp)
/*  f01880c:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f018810:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f018814:	44052000 */ 	mfc1	$a1,$f4
/*  f018818:	00000000 */ 	nop
/*  f01881c:	00a03025 */ 	move	$a2,$a1
/*  f018820:	0c002faa */ 	jal	viSetFillColour
/*  f018824:	00a03825 */ 	move	$a3,$a1
/*  f018828:	1000003f */ 	b	.JF0f018928
/*  f01882c:	afa204e0 */ 	sw	$v0,0x4e0($sp)
.JF0f018830:
/*  f018830:	15240038 */ 	bne	$t1,$a0,.JF0f018914
/*  f018834:	240500b9 */ 	li	$a1,0xb9
/*  f018838:	3c018006 */ 	lui	$at,0x8006
/*  f01883c:	c4282738 */ 	lwc1	$f8,0x2738($at)
/*  f018840:	3c01437f */ 	lui	$at,0x437f
/*  f018844:	44813000 */ 	mtc1	$at,$f6
/*  f018848:	24060001 */ 	li	$a2,0x1
/*  f01884c:	3c014f00 */ 	lui	$at,0x4f00
/*  f018850:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f018854:	2404ffff */ 	li	$a0,-1
/*  f018858:	3c05a500 */ 	lui	$a1,0xa500
/*  f01885c:	444ff800 */ 	cfc1	$t7,$31
/*  f018860:	44c6f800 */ 	ctc1	$a2,$31
/*  f018864:	00000000 */ 	nop
/*  f018868:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f01886c:	4446f800 */ 	cfc1	$a2,$31
/*  f018870:	00000000 */ 	nop
/*  f018874:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f018878:	50c00013 */ 	beqzl	$a2,.JF0f0188c8
/*  f01887c:	44062000 */ 	mfc1	$a2,$f4
/*  f018880:	44812000 */ 	mtc1	$at,$f4
/*  f018884:	24060001 */ 	li	$a2,0x1
/*  f018888:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f01888c:	44c6f800 */ 	ctc1	$a2,$31
/*  f018890:	00000000 */ 	nop
/*  f018894:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f018898:	4446f800 */ 	cfc1	$a2,$31
/*  f01889c:	00000000 */ 	nop
/*  f0188a0:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0188a4:	14c00005 */ 	bnez	$a2,.JF0f0188bc
/*  f0188a8:	00000000 */ 	nop
/*  f0188ac:	44062000 */ 	mfc1	$a2,$f4
/*  f0188b0:	3c018000 */ 	lui	$at,0x8000
/*  f0188b4:	10000007 */ 	b	.JF0f0188d4
/*  f0188b8:	00c13025 */ 	or	$a2,$a2,$at
.JF0f0188bc:
/*  f0188bc:	10000005 */ 	b	.JF0f0188d4
/*  f0188c0:	2406ffff */ 	li	$a2,-1
/*  f0188c4:	44062000 */ 	mfc1	$a2,$f4
.JF0f0188c8:
/*  f0188c8:	00000000 */ 	nop
/*  f0188cc:	04c0fffb */ 	bltz	$a2,.JF0f0188bc
/*  f0188d0:	00000000 */ 	nop
.JF0f0188d4:
/*  f0188d4:	44cff800 */ 	ctc1	$t7,$31
/*  f0188d8:	0fc01a60 */ 	jal	colourBlend
/*  f0188dc:	34a52c00 */ 	ori	$a1,$a1,0x2c00
/*  f0188e0:	00022e02 */ 	srl	$a1,$v0,0x18
/*  f0188e4:	00023402 */ 	srl	$a2,$v0,0x10
/*  f0188e8:	00023a02 */ 	srl	$a3,$v0,0x8
/*  f0188ec:	30f900ff */ 	andi	$t9,$a3,0xff
/*  f0188f0:	30d800ff */ 	andi	$t8,$a2,0xff
/*  f0188f4:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f0188f8:	01c02825 */ 	move	$a1,$t6
/*  f0188fc:	03003025 */ 	move	$a2,$t8
/*  f018900:	03203825 */ 	move	$a3,$t9
/*  f018904:	0c002faa */ 	jal	viSetFillColour
/*  f018908:	8fa404e0 */ 	lw	$a0,0x4e0($sp)
/*  f01890c:	10000006 */ 	b	.JF0f018928
/*  f018910:	afa204e0 */ 	sw	$v0,0x4e0($sp)
.JF0f018914:
/*  f018914:	8fa404e0 */ 	lw	$a0,0x4e0($sp)
/*  f018918:	00003025 */ 	move	$a2,$zero
/*  f01891c:	0c002faa */ 	jal	viSetFillColour
/*  f018920:	2407002c */ 	li	$a3,0x2c
/*  f018924:	afa204e0 */ 	sw	$v0,0x4e0($sp)
.JF0f018928:
/*  f018928:	0c002c9a */ 	jal	viFillBuffer
/*  f01892c:	8fa404e0 */ 	lw	$a0,0x4e0($sp)
/*  f018930:	3c0f8006 */ 	lui	$t7,0x8006
/*  f018934:	8def2710 */ 	lw	$t7,0x2710($t7)
/*  f018938:	00401825 */ 	move	$v1,$v0
/*  f01893c:	51e00004 */ 	beqzl	$t7,.JF0f018950
/*  f018940:	24040002 */ 	li	$a0,0x2
/*  f018944:	1000048e */ 	b	.JF0f019b80
/*  f018948:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f01894c:	24040002 */ 	li	$a0,0x2
.JF0f018950:
/*  f018950:	0fc59f70 */ 	jal	gfxAllocateLookAt
/*  f018954:	afa304e0 */ 	sw	$v1,0x4e0($sp)
/*  f018958:	44800000 */ 	mtc1	$zero,$f0
/*  f01895c:	3c01457a */ 	lui	$at,0x457a
/*  f018960:	44814000 */ 	mtc1	$at,$f8
/*  f018964:	3c013f80 */ 	lui	$at,0x3f80
/*  f018968:	44813000 */ 	mtc1	$at,$f6
/*  f01896c:	44060000 */ 	mfc1	$a2,$f0
/*  f018970:	44070000 */ 	mfc1	$a3,$f0
/*  f018974:	27a40288 */ 	addiu	$a0,$sp,0x288
/*  f018978:	00402825 */ 	move	$a1,$v0
/*  f01897c:	afa202c8 */ 	sw	$v0,0x2c8($sp)
/*  f018980:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f018984:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f018988:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f01898c:	e7a00020 */ 	swc1	$f0,0x20($sp)
/*  f018990:	e7a00028 */ 	swc1	$f0,0x28($sp)
/*  f018994:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f018998:	0c0011c3 */ 	jal	guLookAtReflect
/*  f01899c:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f0189a0:	8fae04e0 */ 	lw	$t6,0x4e0($sp)
/*  f0189a4:	8fa802c8 */ 	lw	$t0,0x2c8($sp)
/*  f0189a8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0189ac:	25d80008 */ 	addiu	$t8,$t6,0x8
/*  f0189b0:	c4228fe8 */ 	lwc1	$f2,-0x7018($at)
/*  f0189b4:	afb804e0 */ 	sw	$t8,0x4e0($sp)
/*  f0189b8:	3c190384 */ 	lui	$t9,0x384
/*  f0189bc:	37390010 */ 	ori	$t9,$t9,0x10
/*  f0189c0:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0189c4:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f0189c8:	8faf04e0 */ 	lw	$t7,0x4e0($sp)
/*  f0189cc:	3c180382 */ 	lui	$t8,0x382
/*  f0189d0:	37180010 */ 	ori	$t8,$t8,0x10
/*  f0189d4:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f0189d8:	afae04e0 */ 	sw	$t6,0x4e0($sp)
/*  f0189dc:	25190010 */ 	addiu	$t9,$t0,0x10
/*  f0189e0:	3c018006 */ 	lui	$at,0x8006
/*  f0189e4:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f0189e8:	adf80000 */ 	sw	$t8,0x0($t7)
/*  f0189ec:	c4202758 */ 	lwc1	$f0,0x2758($at)
/*  f0189f0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0189f4:	44815000 */ 	mtc1	$at,$f10
/*  f0189f8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0189fc:	c4248fec */ 	lwc1	$f4,-0x7014($at)
/*  f018a00:	460a0380 */ 	add.s	$f14,$f0,$f10
/*  f018a04:	44808000 */ 	mtc1	$zero,$f16
/*  f018a08:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f018a0c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f018a10:	8def2704 */ 	lw	$t7,0x2704($t7)
/*  f018a14:	46027182 */ 	mul.s	$f6,$f14,$f2
/*  f018a18:	24090001 */ 	li	$t1,0x1
/*  f018a1c:	3c068006 */ 	lui	$a2,0x8006
/*  f018a20:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018a24:	3c013f80 */ 	lui	$at,0x3f80
/*  f018a28:	46088481 */ 	sub.s	$f18,$f16,$f8
/*  f018a2c:	24c62480 */ 	addiu	$a2,$a2,0x2480
/*  f018a30:	46023380 */ 	add.s	$f14,$f6,$f2
/*  f018a34:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f018a38:	152f0041 */ 	bne	$t1,$t7,.JF0f018b40
/*  f018a3c:	46025480 */ 	add.s	$f18,$f10,$f2
/*  f018a40:	8dce271c */ 	lw	$t6,0x271c($t6)
/*  f018a44:	3c01437f */ 	lui	$at,0x437f
/*  f018a48:	51c00039 */ 	beqzl	$t6,.JF0f018b30
/*  f018a4c:	44812000 */ 	mtc1	$at,$f4
/*  f018a50:	3c018006 */ 	lui	$at,0x8006
/*  f018a54:	c4222700 */ 	lwc1	$f2,0x2700($at)
/*  f018a58:	3c013f80 */ 	lui	$at,0x3f80
/*  f018a5c:	44812000 */ 	mtc1	$at,$f4
/*  f018a60:	46021200 */ 	add.s	$f8,$f2,$f2
/*  f018a64:	3c01437f */ 	lui	$at,0x437f
/*  f018a68:	44813000 */ 	mtc1	$at,$f6
/*  f018a6c:	3c014f00 */ 	lui	$at,0x4f00
/*  f018a70:	46082001 */ 	sub.s	$f0,$f4,$f8
/*  f018a74:	4610003c */ 	c.lt.s	$f0,$f16
/*  f018a78:	00000000 */ 	nop
/*  f018a7c:	45000002 */ 	bc1f	.JF0f018a88
/*  f018a80:	00000000 */ 	nop
/*  f018a84:	46008006 */ 	mov.s	$f0,$f16
.JF0f018a88:
/*  f018a88:	46003082 */ 	mul.s	$f2,$f6,$f0
/*  f018a8c:	24050001 */ 	li	$a1,0x1
/*  f018a90:	4458f800 */ 	cfc1	$t8,$31
/*  f018a94:	44c5f800 */ 	ctc1	$a1,$31
/*  f018a98:	00000000 */ 	nop
/*  f018a9c:	460012a4 */ 	cvt.w.s	$f10,$f2
/*  f018aa0:	4445f800 */ 	cfc1	$a1,$31
/*  f018aa4:	00000000 */ 	nop
/*  f018aa8:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f018aac:	50a00019 */ 	beqzl	$a1,.JF0f018b14
/*  f018ab0:	44055000 */ 	mfc1	$a1,$f10
/*  f018ab4:	44815000 */ 	mtc1	$at,$f10
/*  f018ab8:	24050001 */ 	li	$a1,0x1
/*  f018abc:	460a1281 */ 	sub.s	$f10,$f2,$f10
/*  f018ac0:	44c5f800 */ 	ctc1	$a1,$31
/*  f018ac4:	00000000 */ 	nop
/*  f018ac8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f018acc:	4445f800 */ 	cfc1	$a1,$31
/*  f018ad0:	00000000 */ 	nop
/*  f018ad4:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f018ad8:	54a00009 */ 	bnezl	$a1,.JF0f018b00
/*  f018adc:	2405ffff */ 	li	$a1,-1
/*  f018ae0:	44055000 */ 	mfc1	$a1,$f10
/*  f018ae4:	3c018000 */ 	lui	$at,0x8000
/*  f018ae8:	44d8f800 */ 	ctc1	$t8,$31
/*  f018aec:	00a12825 */ 	or	$a1,$a1,$at
/*  f018af0:	30b900ff */ 	andi	$t9,$a1,0xff
/*  f018af4:	10000018 */ 	b	.JF0f018b58
/*  f018af8:	03202825 */ 	move	$a1,$t9
.JF0f018afc:
/*  f018afc:	2405ffff */ 	li	$a1,-1
.JF0f018b00:
/*  f018b00:	30b900ff */ 	andi	$t9,$a1,0xff
/*  f018b04:	44d8f800 */ 	ctc1	$t8,$31
/*  f018b08:	10000013 */ 	b	.JF0f018b58
/*  f018b0c:	03202825 */ 	move	$a1,$t9
/*  f018b10:	44055000 */ 	mfc1	$a1,$f10
.JF0f018b14:
/*  f018b14:	00000000 */ 	nop
/*  f018b18:	04a0fff8 */ 	bltz	$a1,.JF0f018afc
/*  f018b1c:	30b900ff */ 	andi	$t9,$a1,0xff
/*  f018b20:	44d8f800 */ 	ctc1	$t8,$31
/*  f018b24:	1000000c */ 	b	.JF0f018b58
/*  f018b28:	03202825 */ 	move	$a1,$t9
/*  f018b2c:	44812000 */ 	mtc1	$at,$f4
.JF0f018b30:
/*  f018b30:	00002825 */ 	move	$a1,$zero
/*  f018b34:	46102082 */ 	mul.s	$f2,$f4,$f16
/*  f018b38:	10000007 */ 	b	.JF0f018b58
/*  f018b3c:	00000000 */ 	nop
.JF0f018b40:
/*  f018b40:	44810000 */ 	mtc1	$at,$f0
/*  f018b44:	3c01437f */ 	lui	$at,0x437f
/*  f018b48:	44814000 */ 	mtc1	$at,$f8
/*  f018b4c:	240500ff */ 	li	$a1,0xff
/*  f018b50:	46004082 */ 	mul.s	$f2,$f8,$f0
/*  f018b54:	00000000 */ 	nop
.JF0f018b58:
/*  f018b58:	3c0f8006 */ 	lui	$t7,0x8006
/*  f018b5c:	8def273c */ 	lw	$t7,0x273c($t7)
/*  f018b60:	241800ff */ 	li	$t8,0xff
/*  f018b64:	05e10008 */ 	bgez	$t7,.JF0f018b88
/*  f018b68:	00000000 */ 	nop
/*  f018b6c:	a0d8000c */ 	sb	$t8,0xc($a2)
/*  f018b70:	a0d80008 */ 	sb	$t8,0x8($a2)
/*  f018b74:	a0c5000e */ 	sb	$a1,0xe($a2)
/*  f018b78:	a0c5000d */ 	sb	$a1,0xd($a2)
/*  f018b7c:	a0c5000a */ 	sb	$a1,0xa($a2)
/*  f018b80:	10000009 */ 	b	.JF0f018ba8
/*  f018b84:	a0c50009 */ 	sb	$a1,0x9($a2)
.JF0f018b88:
/*  f018b88:	3c038006 */ 	lui	$v1,0x8006
/*  f018b8c:	24632480 */ 	addiu	$v1,$v1,0x2480
/*  f018b90:	a060000c */ 	sb	$zero,0xc($v1)
/*  f018b94:	a0600008 */ 	sb	$zero,0x8($v1)
/*  f018b98:	a060000e */ 	sb	$zero,0xe($v1)
/*  f018b9c:	a060000d */ 	sb	$zero,0xd($v1)
/*  f018ba0:	a060000a */ 	sb	$zero,0xa($v1)
/*  f018ba4:	a0600009 */ 	sb	$zero,0x9($v1)
.JF0f018ba8:
/*  f018ba8:	3c018006 */ 	lui	$at,0x8006
/*  f018bac:	c420270c */ 	lwc1	$f0,0x270c($at)
/*  f018bb0:	3c01437f */ 	lui	$at,0x437f
/*  f018bb4:	44813000 */ 	mtc1	$at,$f6
/*  f018bb8:	24040001 */ 	li	$a0,0x1
/*  f018bbc:	3c078006 */ 	lui	$a3,0x8006
/*  f018bc0:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f018bc4:	3c088006 */ 	lui	$t0,0x8006
/*  f018bc8:	25082450 */ 	addiu	$t0,$t0,0x2450
/*  f018bcc:	24e72420 */ 	addiu	$a3,$a3,0x2420
/*  f018bd0:	240e00ff */ 	li	$t6,0xff
/*  f018bd4:	444ff800 */ 	cfc1	$t7,$31
/*  f018bd8:	44c4f800 */ 	ctc1	$a0,$31
/*  f018bdc:	00000000 */ 	nop
/*  f018be0:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f018be4:	4444f800 */ 	cfc1	$a0,$31
/*  f018be8:	00000000 */ 	nop
/*  f018bec:	30840078 */ 	andi	$a0,$a0,0x78
/*  f018bf0:	10800012 */ 	beqz	$a0,.JF0f018c3c
/*  f018bf4:	3c014f00 */ 	lui	$at,0x4f00
/*  f018bf8:	44812000 */ 	mtc1	$at,$f4
/*  f018bfc:	24040001 */ 	li	$a0,0x1
/*  f018c00:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f018c04:	44c4f800 */ 	ctc1	$a0,$31
/*  f018c08:	00000000 */ 	nop
/*  f018c0c:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f018c10:	4444f800 */ 	cfc1	$a0,$31
/*  f018c14:	00000000 */ 	nop
/*  f018c18:	30840078 */ 	andi	$a0,$a0,0x78
/*  f018c1c:	14800005 */ 	bnez	$a0,.JF0f018c34
/*  f018c20:	00000000 */ 	nop
/*  f018c24:	44042000 */ 	mfc1	$a0,$f4
/*  f018c28:	3c018000 */ 	lui	$at,0x8000
/*  f018c2c:	10000007 */ 	b	.JF0f018c4c
/*  f018c30:	00812025 */ 	or	$a0,$a0,$at
.JF0f018c34:
/*  f018c34:	10000005 */ 	b	.JF0f018c4c
/*  f018c38:	2404ffff */ 	li	$a0,-1
.JF0f018c3c:
/*  f018c3c:	44042000 */ 	mfc1	$a0,$f4
/*  f018c40:	00000000 */ 	nop
/*  f018c44:	0480fffb */ 	bltz	$a0,.JF0f018c34
/*  f018c48:	00000000 */ 	nop
.JF0f018c4c:
/*  f018c4c:	44cff800 */ 	ctc1	$t7,$31
/*  f018c50:	24030001 */ 	li	$v1,0x1
/*  f018c54:	a1040004 */ 	sb	$a0,0x4($t0)
/*  f018c58:	46001202 */ 	mul.s	$f8,$f2,$f0
/*  f018c5c:	a1040000 */ 	sb	$a0,0x0($t0)
/*  f018c60:	4458f800 */ 	cfc1	$t8,$31
/*  f018c64:	44c3f800 */ 	ctc1	$v1,$31
/*  f018c68:	00000000 */ 	nop
/*  f018c6c:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f018c70:	4443f800 */ 	cfc1	$v1,$31
/*  f018c74:	00000000 */ 	nop
/*  f018c78:	30630078 */ 	andi	$v1,$v1,0x78
/*  f018c7c:	10600012 */ 	beqz	$v1,.JF0f018cc8
/*  f018c80:	3c014f00 */ 	lui	$at,0x4f00
/*  f018c84:	44813000 */ 	mtc1	$at,$f6
/*  f018c88:	24030001 */ 	li	$v1,0x1
/*  f018c8c:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f018c90:	44c3f800 */ 	ctc1	$v1,$31
/*  f018c94:	00000000 */ 	nop
/*  f018c98:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f018c9c:	4443f800 */ 	cfc1	$v1,$31
/*  f018ca0:	00000000 */ 	nop
/*  f018ca4:	30630078 */ 	andi	$v1,$v1,0x78
/*  f018ca8:	14600005 */ 	bnez	$v1,.JF0f018cc0
/*  f018cac:	00000000 */ 	nop
/*  f018cb0:	44033000 */ 	mfc1	$v1,$f6
/*  f018cb4:	3c018000 */ 	lui	$at,0x8000
/*  f018cb8:	10000007 */ 	b	.JF0f018cd8
/*  f018cbc:	00611825 */ 	or	$v1,$v1,$at
.JF0f018cc0:
/*  f018cc0:	10000005 */ 	b	.JF0f018cd8
/*  f018cc4:	2403ffff */ 	li	$v1,-1
.JF0f018cc8:
/*  f018cc8:	44033000 */ 	mfc1	$v1,$f6
/*  f018ccc:	00000000 */ 	nop
/*  f018cd0:	0460fffb */ 	bltz	$v1,.JF0f018cc0
/*  f018cd4:	00000000 */ 	nop
.JF0f018cd8:
/*  f018cd8:	44d8f800 */ 	ctc1	$t8,$31
/*  f018cdc:	a1030006 */ 	sb	$v1,0x6($t0)
/*  f018ce0:	a1030005 */ 	sb	$v1,0x5($t0)
/*  f018ce4:	a1030002 */ 	sb	$v1,0x2($t0)
/*  f018ce8:	a1030001 */ 	sb	$v1,0x1($t0)
/*  f018cec:	a0ee0004 */ 	sb	$t6,0x4($a3)
/*  f018cf0:	a0ee0000 */ 	sb	$t6,0x0($a3)
/*  f018cf4:	a0e50006 */ 	sb	$a1,0x6($a3)
/*  f018cf8:	a0e50005 */ 	sb	$a1,0x5($a3)
/*  f018cfc:	a0e50002 */ 	sb	$a1,0x2($a3)
/*  f018d00:	a0e50001 */ 	sb	$a1,0x1($a3)
/*  f018d04:	e7ae027c */ 	swc1	$f14,0x27c($sp)
/*  f018d08:	e7b20278 */ 	swc1	$f18,0x278($sp)
/*  f018d0c:	0c0068df */ 	jal	sinf
/*  f018d10:	46007306 */ 	mov.s	$f12,$f14
/*  f018d14:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f018d18:	0c0068dc */ 	jal	cosf
/*  f018d1c:	c7ac0278 */ 	lwc1	$f12,0x278($sp)
/*  f018d20:	3c0142fe */ 	lui	$at,0x42fe
/*  f018d24:	44815000 */ 	mtc1	$at,$f10
/*  f018d28:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f018d2c:	3c018006 */ 	lui	$at,0x8006
/*  f018d30:	c7ac0278 */ 	lwc1	$f12,0x278($sp)
/*  f018d34:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f018d38:	00000000 */ 	nop
/*  f018d3c:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f018d40:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f018d44:	44195000 */ 	mfc1	$t9,$f10
/*  f018d48:	0c0068df */ 	jal	sinf
/*  f018d4c:	a0392490 */ 	sb	$t9,0x2490($at)
/*  f018d50:	3c0142fe */ 	lui	$at,0x42fe
/*  f018d54:	44812000 */ 	mtc1	$at,$f4
/*  f018d58:	3c018006 */ 	lui	$at,0x8006
/*  f018d5c:	c7ac027c */ 	lwc1	$f12,0x27c($sp)
/*  f018d60:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f018d64:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f018d68:	440e3000 */ 	mfc1	$t6,$f6
/*  f018d6c:	0c0068dc */ 	jal	cosf
/*  f018d70:	a02e2491 */ 	sb	$t6,0x2491($at)
/*  f018d74:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f018d78:	0c0068dc */ 	jal	cosf
/*  f018d7c:	c7ac0278 */ 	lwc1	$f12,0x278($sp)
/*  f018d80:	3c0142fe */ 	lui	$at,0x42fe
/*  f018d84:	44815000 */ 	mtc1	$at,$f10
/*  f018d88:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f018d8c:	44801000 */ 	mtc1	$zero,$f2
/*  f018d90:	3c018006 */ 	lui	$at,0x8006
/*  f018d94:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f018d98:	44051000 */ 	mfc1	$a1,$f2
/*  f018d9c:	44061000 */ 	mfc1	$a2,$f2
/*  f018da0:	27a40460 */ 	addiu	$a0,$sp,0x460
/*  f018da4:	3c07457a */ 	lui	$a3,0x457a
/*  f018da8:	e7a20010 */ 	swc1	$f2,0x10($sp)
/*  f018dac:	e7a20014 */ 	swc1	$f2,0x14($sp)
/*  f018db0:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f018db4:	e7a20018 */ 	swc1	$f2,0x18($sp)
/*  f018db8:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f018dbc:	e7a20024 */ 	swc1	$f2,0x24($sp)
/*  f018dc0:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f018dc4:	44195000 */ 	mfc1	$t9,$f10
/*  f018dc8:	00000000 */ 	nop
/*  f018dcc:	a0392492 */ 	sb	$t9,0x2492($at)
/*  f018dd0:	3c013f80 */ 	lui	$at,0x3f80
/*  f018dd4:	44812000 */ 	mtc1	$at,$f4
/*  f018dd8:	0c005aa1 */ 	jal	mtx00016ae4
/*  f018ddc:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f018de0:	3c0f8006 */ 	lui	$t7,0x8006
/*  f018de4:	8def2704 */ 	lw	$t7,0x2704($t7)
/*  f018de8:	24090001 */ 	li	$t1,0x1
/*  f018dec:	3c018006 */ 	lui	$at,0x8006
/*  f018df0:	152f0005 */ 	bne	$t1,$t7,.JF0f018e08
/*  f018df4:	27a50398 */ 	addiu	$a1,$sp,0x398
/*  f018df8:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018dfc:	8dce23d8 */ 	lw	$t6,0x23d8($t6)
/*  f018e00:	10000004 */ 	b	.JF0f018e14
/*  f018e04:	afae03dc */ 	sw	$t6,0x3dc($sp)
.JF0f018e08:
/*  f018e08:	3c188006 */ 	lui	$t8,0x8006
/*  f018e0c:	8f1823dc */ 	lw	$t8,0x23dc($t8)
/*  f018e10:	afb803dc */ 	sw	$t8,0x3dc($sp)
.JF0f018e14:
/*  f018e14:	0c0058c5 */ 	jal	mtx4LoadYRotation
/*  f018e18:	c42c26ec */ 	lwc1	$f12,0x26ec($at)
/*  f018e1c:	3c018006 */ 	lui	$at,0x8006
/*  f018e20:	c42c26f4 */ 	lwc1	$f12,0x26f4($at)
/*  f018e24:	0c0058a2 */ 	jal	mtx4LoadXRotation
/*  f018e28:	27a50358 */ 	addiu	$a1,$sp,0x358
/*  f018e2c:	27a40358 */ 	addiu	$a0,$sp,0x358
/*  f018e30:	0c005667 */ 	jal	mtx4MultMtx4InPlace
/*  f018e34:	27a50398 */ 	addiu	$a1,$sp,0x398
/*  f018e38:	27a40460 */ 	addiu	$a0,$sp,0x460
/*  f018e3c:	27a50398 */ 	addiu	$a1,$sp,0x398
/*  f018e40:	0c005668 */ 	jal	mtx4MultMtx4
/*  f018e44:	27a60420 */ 	addiu	$a2,$sp,0x420
/*  f018e48:	3c018006 */ 	lui	$at,0x8006
/*  f018e4c:	c42c26fc */ 	lwc1	$f12,0x26fc($at)
/*  f018e50:	0c0057a9 */ 	jal	mtx00015f04
/*  f018e54:	27a50420 */ 	addiu	$a1,$sp,0x420
/*  f018e58:	3c198006 */ 	lui	$t9,0x8006
/*  f018e5c:	8f39273c */ 	lw	$t9,0x273c($t9)
/*  f018e60:	24050002 */ 	li	$a1,0x2
/*  f018e64:	5f2000fa */ 	bgtzl	$t9,.JF0f019250
/*  f018e68:	8fa204e0 */ 	lw	$v0,0x4e0($sp)
/*  f018e6c:	8faf03dc */ 	lw	$t7,0x3dc($sp)
/*  f018e70:	afa0026c */ 	sw	$zero,0x26c($sp)
/*  f018e74:	afa00268 */ 	sw	$zero,0x268($sp)
/*  f018e78:	0c006a2f */ 	jal	modelGetPart
/*  f018e7c:	8de40008 */ 	lw	$a0,0x8($t7)
/*  f018e80:	10400027 */ 	beqz	$v0,.JF0f018f20
/*  f018e84:	00402825 */ 	move	$a1,$v0
/*  f018e88:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f018e8c:	8fa403dc */ 	lw	$a0,0x3dc($sp)
/*  f018e90:	84ce0010 */ 	lh	$t6,0x10($a2)
/*  f018e94:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f018e98:	afb8026c */ 	sw	$t8,0x26c($sp)
/*  f018e9c:	94d90016 */ 	lhu	$t9,0x16($a2)
/*  f018ea0:	afa60314 */ 	sw	$a2,0x314($sp)
/*  f018ea4:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f018ea8:	0c006a6f */ 	jal	modelGetNodeRwData
/*  f018eac:	afaf0268 */ 	sw	$t7,0x268($sp)
/*  f018eb0:	afa20310 */ 	sw	$v0,0x310($sp)
/*  f018eb4:	0fc59f81 */ 	jal	gfxAllocate
/*  f018eb8:	24040028 */ 	li	$a0,0x28
/*  f018ebc:	8fae0310 */ 	lw	$t6,0x310($sp)
/*  f018ec0:	8fa60314 */ 	lw	$a2,0x314($sp)
/*  f018ec4:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f018ec8:	adc20004 */ 	sw	$v0,0x4($t6)
/*  f018ecc:	3c198000 */ 	lui	$t9,0x8000
/*  f018ed0:	37390040 */ 	ori	$t9,$t9,0x40
/*  f018ed4:	37180002 */ 	ori	$t8,$t8,0x2
/*  f018ed8:	3c0f0386 */ 	lui	$t7,0x386
/*  f018edc:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f018ee0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f018ee4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f018ee8:	3c198006 */ 	lui	$t9,0x8006
/*  f018eec:	3c180388 */ 	lui	$t8,0x388
/*  f018ef0:	ac4f0008 */ 	sw	$t7,0x8($v0)
/*  f018ef4:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018ef8:	25ce2428 */ 	addiu	$t6,$t6,0x2428
/*  f018efc:	37180010 */ 	ori	$t8,$t8,0x10
/*  f018f00:	27392420 */ 	addiu	$t9,$t9,0x2420
/*  f018f04:	3c0f0601 */ 	lui	$t7,0x601
/*  f018f08:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f018f0c:	ac580010 */ 	sw	$t8,0x10($v0)
/*  f018f10:	ac4e000c */ 	sw	$t6,0xc($v0)
/*  f018f14:	ac4f0018 */ 	sw	$t7,0x18($v0)
/*  f018f18:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f018f1c:	ac4e001c */ 	sw	$t6,0x1c($v0)
.JF0f018f20:
/*  f018f20:	8fb803dc */ 	lw	$t8,0x3dc($sp)
/*  f018f24:	24050004 */ 	li	$a1,0x4
/*  f018f28:	0c006a2f */ 	jal	modelGetPart
/*  f018f2c:	8f040008 */ 	lw	$a0,0x8($t8)
/*  f018f30:	10400037 */ 	beqz	$v0,.JF0f019010
/*  f018f34:	00402825 */ 	move	$a1,$v0
/*  f018f38:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f018f3c:	8fb9026c */ 	lw	$t9,0x26c($sp)
/*  f018f40:	8fa403dc */ 	lw	$a0,0x3dc($sp)
/*  f018f44:	84cf0010 */ 	lh	$t7,0x10($a2)
/*  f018f48:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f018f4c:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f018f50:	afb8026c */ 	sw	$t8,0x26c($sp)
/*  f018f54:	8fb90268 */ 	lw	$t9,0x268($sp)
/*  f018f58:	94cf0016 */ 	lhu	$t7,0x16($a2)
/*  f018f5c:	afa60314 */ 	sw	$a2,0x314($sp)
/*  f018f60:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f018f64:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f018f68:	0c006a6f */ 	jal	modelGetNodeRwData
/*  f018f6c:	afb80268 */ 	sw	$t8,0x268($sp)
/*  f018f70:	afa20310 */ 	sw	$v0,0x310($sp)
/*  f018f74:	0fc59f81 */ 	jal	gfxAllocate
/*  f018f78:	24040028 */ 	li	$a0,0x28
/*  f018f7c:	8fb90310 */ 	lw	$t9,0x310($sp)
/*  f018f80:	8fa60314 */ 	lw	$a2,0x314($sp)
/*  f018f84:	3c018006 */ 	lui	$at,0x8006
/*  f018f88:	af220004 */ 	sw	$v0,0x4($t9)
/*  f018f8c:	c426270c */ 	lwc1	$f6,0x270c($at)
/*  f018f90:	44804000 */ 	mtc1	$zero,$f8
/*  f018f94:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f018f98:	3c0e8000 */ 	lui	$t6,0x8000
/*  f018f9c:	4606403c */ 	c.lt.s	$f8,$f6
/*  f018fa0:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f018fa4:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f018fa8:	3c180386 */ 	lui	$t8,0x386
/*  f018fac:	45000016 */ 	bc1f	.JF0f019008
/*  f018fb0:	3c0fb800 */ 	lui	$t7,0xb800
/*  f018fb4:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f018fb8:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f018fbc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f018fc0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f018fc4:	37180010 */ 	ori	$t8,$t8,0x10
/*  f018fc8:	3c198006 */ 	lui	$t9,0x8006
/*  f018fcc:	27392458 */ 	addiu	$t9,$t9,0x2458
/*  f018fd0:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f018fd4:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f018fd8:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018fdc:	3c0f0388 */ 	lui	$t7,0x388
/*  f018fe0:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f018fe4:	25ce2450 */ 	addiu	$t6,$t6,0x2450
/*  f018fe8:	acee0004 */ 	sw	$t6,0x4($a3)
/*  f018fec:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f018ff0:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018ff4:	3c180601 */ 	lui	$t8,0x601
/*  f018ff8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f018ffc:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f019000:	10000003 */ 	b	.JF0f019010
/*  f019004:	ac790004 */ 	sw	$t9,0x4($v1)
.JF0f019008:
/*  f019008:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f01900c:	ac400004 */ 	sw	$zero,0x4($v0)
.JF0f019010:
/*  f019010:	8fae03dc */ 	lw	$t6,0x3dc($sp)
/*  f019014:	24050006 */ 	li	$a1,0x6
/*  f019018:	0c006a2f */ 	jal	modelGetPart
/*  f01901c:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f019020:	10400037 */ 	beqz	$v0,.JF0f019100
/*  f019024:	00402825 */ 	move	$a1,$v0
/*  f019028:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f01902c:	8fb8026c */ 	lw	$t8,0x26c($sp)
/*  f019030:	8fa403dc */ 	lw	$a0,0x3dc($sp)
/*  f019034:	84d90010 */ 	lh	$t9,0x10($a2)
/*  f019038:	03197821 */ 	addu	$t7,$t8,$t9
/*  f01903c:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f019040:	afae026c */ 	sw	$t6,0x26c($sp)
/*  f019044:	8fb80268 */ 	lw	$t8,0x268($sp)
/*  f019048:	94d90016 */ 	lhu	$t9,0x16($a2)
/*  f01904c:	afa60314 */ 	sw	$a2,0x314($sp)
/*  f019050:	03197821 */ 	addu	$t7,$t8,$t9
/*  f019054:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f019058:	0c006a6f */ 	jal	modelGetNodeRwData
/*  f01905c:	afae0268 */ 	sw	$t6,0x268($sp)
/*  f019060:	afa20310 */ 	sw	$v0,0x310($sp)
/*  f019064:	0fc59f81 */ 	jal	gfxAllocate
/*  f019068:	24040028 */ 	li	$a0,0x28
/*  f01906c:	8fb80310 */ 	lw	$t8,0x310($sp)
/*  f019070:	8fa60314 */ 	lw	$a2,0x314($sp)
/*  f019074:	3c018006 */ 	lui	$at,0x8006
/*  f019078:	af020004 */ 	sw	$v0,0x4($t8)
/*  f01907c:	c424270c */ 	lwc1	$f4,0x270c($at)
/*  f019080:	44805000 */ 	mtc1	$zero,$f10
/*  f019084:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f019088:	3c0f8000 */ 	lui	$t7,0x8000
/*  f01908c:	4604503c */ 	c.lt.s	$f10,$f4
/*  f019090:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f019094:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f019098:	3c0e0386 */ 	lui	$t6,0x386
/*  f01909c:	45000016 */ 	bc1f	.JF0f0190f8
/*  f0190a0:	3c19b800 */ 	lui	$t9,0xb800
/*  f0190a4:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f0190a8:	37390002 */ 	ori	$t9,$t9,0x2
/*  f0190ac:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0190b0:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0190b4:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f0190b8:	3c188006 */ 	lui	$t8,0x8006
/*  f0190bc:	27182458 */ 	addiu	$t8,$t8,0x2458
/*  f0190c0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f0190c4:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f0190c8:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0190cc:	3c190388 */ 	lui	$t9,0x388
/*  f0190d0:	37390010 */ 	ori	$t9,$t9,0x10
/*  f0190d4:	25ef2450 */ 	addiu	$t7,$t7,0x2450
/*  f0190d8:	acef0004 */ 	sw	$t7,0x4($a3)
/*  f0190dc:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f0190e0:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f0190e4:	3c0e0601 */ 	lui	$t6,0x601
/*  f0190e8:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0190ec:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0190f0:	10000003 */ 	b	.JF0f019100
/*  f0190f4:	ac780004 */ 	sw	$t8,0x4($v1)
.JF0f0190f8:
/*  f0190f8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0190fc:	ac400004 */ 	sw	$zero,0x4($v0)
.JF0f019100:
/*  f019100:	8faf03dc */ 	lw	$t7,0x3dc($sp)
/*  f019104:	24050008 */ 	li	$a1,0x8
/*  f019108:	0c006a2f */ 	jal	modelGetPart
/*  f01910c:	8de40008 */ 	lw	$a0,0x8($t7)
/*  f019110:	10400037 */ 	beqz	$v0,.JF0f0191f0
/*  f019114:	00402825 */ 	move	$a1,$v0
/*  f019118:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f01911c:	8fae026c */ 	lw	$t6,0x26c($sp)
/*  f019120:	8fa403dc */ 	lw	$a0,0x3dc($sp)
/*  f019124:	84d80010 */ 	lh	$t8,0x10($a2)
/*  f019128:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f01912c:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f019130:	afaf026c */ 	sw	$t7,0x26c($sp)
/*  f019134:	8fae0268 */ 	lw	$t6,0x268($sp)
/*  f019138:	94d80016 */ 	lhu	$t8,0x16($a2)
/*  f01913c:	afa60314 */ 	sw	$a2,0x314($sp)
/*  f019140:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f019144:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f019148:	0c006a6f */ 	jal	modelGetNodeRwData
/*  f01914c:	afaf0268 */ 	sw	$t7,0x268($sp)
/*  f019150:	afa20310 */ 	sw	$v0,0x310($sp)
/*  f019154:	0fc59f81 */ 	jal	gfxAllocate
/*  f019158:	24040028 */ 	li	$a0,0x28
/*  f01915c:	8fae0310 */ 	lw	$t6,0x310($sp)
/*  f019160:	8fa60314 */ 	lw	$a2,0x314($sp)
/*  f019164:	3c018006 */ 	lui	$at,0x8006
/*  f019168:	adc20004 */ 	sw	$v0,0x4($t6)
/*  f01916c:	c426270c */ 	lwc1	$f6,0x270c($at)
/*  f019170:	44804000 */ 	mtc1	$zero,$f8
/*  f019174:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f019178:	3c198000 */ 	lui	$t9,0x8000
/*  f01917c:	4606403c */ 	c.lt.s	$f8,$f6
/*  f019180:	37390040 */ 	ori	$t9,$t9,0x40
/*  f019184:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f019188:	3c0f0386 */ 	lui	$t7,0x386
/*  f01918c:	45000016 */ 	bc1f	.JF0f0191e8
/*  f019190:	3c18b800 */ 	lui	$t8,0xb800
/*  f019194:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f019198:	37180002 */ 	ori	$t8,$t8,0x2
/*  f01919c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0191a0:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0191a4:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f0191a8:	3c0e8006 */ 	lui	$t6,0x8006
/*  f0191ac:	25ce2458 */ 	addiu	$t6,$t6,0x2458
/*  f0191b0:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f0191b4:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f0191b8:	3c198006 */ 	lui	$t9,0x8006
/*  f0191bc:	3c180388 */ 	lui	$t8,0x388
/*  f0191c0:	37180010 */ 	ori	$t8,$t8,0x10
/*  f0191c4:	27392450 */ 	addiu	$t9,$t9,0x2450
/*  f0191c8:	acf90004 */ 	sw	$t9,0x4($a3)
/*  f0191cc:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f0191d0:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f0191d4:	3c0f0601 */ 	lui	$t7,0x601
/*  f0191d8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0191dc:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f0191e0:	10000003 */ 	b	.JF0f0191f0
/*  f0191e4:	ac6e0004 */ 	sw	$t6,0x4($v1)
.JF0f0191e8:
/*  f0191e8:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0191ec:	ac400004 */ 	sw	$zero,0x4($v0)
.JF0f0191f0:
/*  f0191f0:	0fc59f5d */ 	jal	gfxAllocateVertices
/*  f0191f4:	8fa4026c */ 	lw	$a0,0x26c($sp)
/*  f0191f8:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0191fc:	0fc59f77 */ 	jal	gfxAllocateColours
/*  f019200:	8fa40268 */ 	lw	$a0,0x268($sp)
/*  f019204:	3c013f80 */ 	lui	$at,0x3f80
/*  f019208:	44815000 */ 	mtc1	$at,$f10
/*  f01920c:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f019210:	3c068006 */ 	lui	$a2,0x8006
/*  f019214:	3c078006 */ 	lui	$a3,0x8006
/*  f019218:	241900f0 */ 	li	$t9,0xf0
/*  f01921c:	27af0420 */ 	addiu	$t7,$sp,0x420
/*  f019220:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f019224:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f019228:	8ce72700 */ 	lw	$a3,0x2700($a3)
/*  f01922c:	8cc62748 */ 	lw	$a2,0x2748($a2)
/*  f019230:	8fa404e0 */ 	lw	$a0,0x4e0($sp)
/*  f019234:	8fa503dc */ 	lw	$a1,0x3dc($sp)
/*  f019238:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f01923c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f019240:	0fc05d8a */ 	jal	titleRenderPdLogoModel
/*  f019244:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f019248:	afa204e0 */ 	sw	$v0,0x4e0($sp)
/*  f01924c:	8fa204e0 */ 	lw	$v0,0x4e0($sp)
.JF0f019250:
/*  f019250:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f019254:	37180002 */ 	ori	$t8,$t8,0x2
/*  f019258:	3c198000 */ 	lui	$t9,0x8000
/*  f01925c:	37390040 */ 	ori	$t9,$t9,0x40
/*  f019260:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f019264:	24430008 */ 	addiu	$v1,$v0,0x8
/*  f019268:	3c0f0386 */ 	lui	$t7,0x386
/*  f01926c:	3c088006 */ 	lui	$t0,0x8006
/*  f019270:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f019274:	25082488 */ 	addiu	$t0,$t0,0x2488
/*  f019278:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f01927c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f019280:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f019284:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f019288:	3c0e0388 */ 	lui	$t6,0x388
/*  f01928c:	3c098006 */ 	lui	$t1,0x8006
/*  f019290:	25292480 */ 	addiu	$t1,$t1,0x2480
/*  f019294:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f019298:	3c188006 */ 	lui	$t8,0x8006
/*  f01929c:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f0192a0:	acc90004 */ 	sw	$t1,0x4($a2)
/*  f0192a4:	2718279c */ 	addiu	$t8,$t8,0x279c
/*  f0192a8:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0192ac:	27a401f4 */ 	addiu	$a0,$sp,0x1f4
/*  f0192b0:	24c70008 */ 	addiu	$a3,$a2,0x8
/*  f0192b4:	ac810000 */ 	sw	$at,0x0($a0)
/*  f0192b8:	8f0f0004 */ 	lw	$t7,0x4($t8)
/*  f0192bc:	27a50398 */ 	addiu	$a1,$sp,0x398
/*  f0192c0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0192c4:	8f010008 */ 	lw	$at,0x8($t8)
/*  f0192c8:	ac810008 */ 	sw	$at,0x8($a0)
/*  f0192cc:	afa90040 */ 	sw	$t1,0x40($sp)
/*  f0192d0:	afa80044 */ 	sw	$t0,0x44($sp)
/*  f0192d4:	0c00599f */ 	jal	mtx4LoadTranslation
/*  f0192d8:	afa704e0 */ 	sw	$a3,0x4e0($sp)
/*  f0192dc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0192e0:	c42c8ff0 */ 	lwc1	$f12,-0x7010($at)
/*  f0192e4:	0c005792 */ 	jal	mtx00015ea8
/*  f0192e8:	27a50398 */ 	addiu	$a1,$sp,0x398
/*  f0192ec:	27a40460 */ 	addiu	$a0,$sp,0x460
/*  f0192f0:	27a50398 */ 	addiu	$a1,$sp,0x398
/*  f0192f4:	0c005668 */ 	jal	mtx4MultMtx4
/*  f0192f8:	27a603e0 */ 	addiu	$a2,$sp,0x3e0
/*  f0192fc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f019300:	c42c8ff4 */ 	lwc1	$f12,-0x700c($at)
/*  f019304:	0c0057a9 */ 	jal	mtx00015f04
/*  f019308:	27a503e0 */ 	addiu	$a1,$sp,0x3e0
/*  f01930c:	3c014060 */ 	lui	$at,0x4060
/*  f019310:	44816000 */ 	mtc1	$at,$f12
/*  f019314:	0c0057a9 */ 	jal	mtx00015f04
/*  f019318:	27a503e0 */ 	addiu	$a1,$sp,0x3e0
/*  f01931c:	3c048006 */ 	lui	$a0,0x8006
/*  f019320:	8c84273c */ 	lw	$a0,0x273c($a0)
/*  f019324:	04800214 */ 	bltz	$a0,.JF0f019b78
/*  f019328:	28810002 */ 	slti	$at,$a0,0x2
/*  f01932c:	1420008f */ 	bnez	$at,.JF0f01956c
/*  f019330:	3c013f80 */ 	lui	$at,0x3f80
/*  f019334:	44812000 */ 	mtc1	$at,$f4
/*  f019338:	3c018006 */ 	lui	$at,0x8006
/*  f01933c:	c4282738 */ 	lwc1	$f8,0x2738($at)
/*  f019340:	3c01437f */ 	lui	$at,0x437f
/*  f019344:	44815000 */ 	mtc1	$at,$f10
/*  f019348:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f01934c:	24190001 */ 	li	$t9,0x1
/*  f019350:	27a401b0 */ 	addiu	$a0,$sp,0x1b0
/*  f019354:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f019358:	444ef800 */ 	cfc1	$t6,$31
/*  f01935c:	44d9f800 */ 	ctc1	$t9,$31
/*  f019360:	00000000 */ 	nop
/*  f019364:	46002224 */ 	cvt.w.s	$f8,$f4
/*  f019368:	4459f800 */ 	cfc1	$t9,$31
/*  f01936c:	00000000 */ 	nop
/*  f019370:	33390078 */ 	andi	$t9,$t9,0x78
/*  f019374:	13200012 */ 	beqz	$t9,.JF0f0193c0
/*  f019378:	3c014f00 */ 	lui	$at,0x4f00
/*  f01937c:	44814000 */ 	mtc1	$at,$f8
/*  f019380:	24190001 */ 	li	$t9,0x1
/*  f019384:	46082201 */ 	sub.s	$f8,$f4,$f8
/*  f019388:	44d9f800 */ 	ctc1	$t9,$31
/*  f01938c:	00000000 */ 	nop
/*  f019390:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f019394:	4459f800 */ 	cfc1	$t9,$31
/*  f019398:	00000000 */ 	nop
/*  f01939c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0193a0:	17200005 */ 	bnez	$t9,.JF0f0193b8
/*  f0193a4:	00000000 */ 	nop
/*  f0193a8:	44194000 */ 	mfc1	$t9,$f8
/*  f0193ac:	3c018000 */ 	lui	$at,0x8000
/*  f0193b0:	10000007 */ 	b	.JF0f0193d0
/*  f0193b4:	0321c825 */ 	or	$t9,$t9,$at
.JF0f0193b8:
/*  f0193b8:	10000005 */ 	b	.JF0f0193d0
/*  f0193bc:	2419ffff */ 	li	$t9,-1
.JF0f0193c0:
/*  f0193c0:	44194000 */ 	mfc1	$t9,$f8
/*  f0193c4:	00000000 */ 	nop
/*  f0193c8:	0720fffb */ 	bltz	$t9,.JF0f0193b8
/*  f0193cc:	00000000 */ 	nop
.JF0f0193d0:
/*  f0193d0:	44cef800 */ 	ctc1	$t6,$31
/*  f0193d4:	0c005654 */ 	jal	mtx4LoadIdentity
/*  f0193d8:	afb90198 */ 	sw	$t9,0x198($sp)
/*  f0193dc:	3c01800a */ 	lui	$at,0x800a
/*  f0193e0:	c426d350 */ 	lwc1	$f6,-0x2cb0($at)
/*  f0193e4:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0193e8:	44815000 */ 	mtc1	$at,$f10
/*  f0193ec:	27a501b0 */ 	addiu	$a1,$sp,0x1b0
/*  f0193f0:	460a3302 */ 	mul.s	$f12,$f6,$f10
/*  f0193f4:	0c0057a9 */ 	jal	mtx00015f04
/*  f0193f8:	00000000 */ 	nop
/*  f0193fc:	44800000 */ 	mtc1	$zero,$f0
/*  f019400:	3c013f80 */ 	lui	$at,0x3f80
/*  f019404:	44812000 */ 	mtc1	$at,$f4
/*  f019408:	44050000 */ 	mfc1	$a1,$f0
/*  f01940c:	44060000 */ 	mfc1	$a2,$f0
/*  f019410:	27a40460 */ 	addiu	$a0,$sp,0x460
/*  f019414:	3c07457a */ 	lui	$a3,0x457a
/*  f019418:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f01941c:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f019420:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f019424:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f019428:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f01942c:	0c005aa1 */ 	jal	mtx00016ae4
/*  f019430:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f019434:	27a40460 */ 	addiu	$a0,$sp,0x460
/*  f019438:	0c005667 */ 	jal	mtx4MultMtx4InPlace
/*  f01943c:	27a501b0 */ 	addiu	$a1,$sp,0x1b0
/*  f019440:	27a401b0 */ 	addiu	$a0,$sp,0x1b0
/*  f019444:	0c00572e */ 	jal	mtx4Copy
/*  f019448:	27a50460 */ 	addiu	$a1,$sp,0x460
/*  f01944c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f019450:	8def23f8 */ 	lw	$t7,0x23f8($t7)
/*  f019454:	27b80460 */ 	addiu	$t8,$sp,0x460
/*  f019458:	afb804a0 */ 	sw	$t8,0x4a0($sp)
/*  f01945c:	8dee0008 */ 	lw	$t6,0x8($t7)
/*  f019460:	85c4000e */ 	lh	$a0,0xe($t6)
/*  f019464:	0004c980 */ 	sll	$t9,$a0,0x6
/*  f019468:	0fc59f81 */ 	jal	gfxAllocate
/*  f01946c:	03202025 */ 	move	$a0,$t9
/*  f019470:	afa204b0 */ 	sw	$v0,0x4b0($sp)
/*  f019474:	27a40460 */ 	addiu	$a0,$sp,0x460
/*  f019478:	0c00572e */ 	jal	mtx4Copy
/*  f01947c:	00402825 */ 	move	$a1,$v0
/*  f019480:	3c028006 */ 	lui	$v0,0x8006
/*  f019484:	244223f8 */ 	addiu	$v0,$v0,0x23f8
/*  f019488:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f01948c:	8fb804b0 */ 	lw	$t8,0x4b0($sp)
/*  f019490:	adf8000c */ 	sw	$t8,0xc($t7)
/*  f019494:	0c0072fc */ 	jal	model0001cc20
/*  f019498:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f01949c:	8fb80198 */ 	lw	$t8,0x198($sp)
/*  f0194a0:	240e0005 */ 	li	$t6,0x5
/*  f0194a4:	afae04d0 */ 	sw	$t6,0x4d0($sp)
/*  f0194a8:	8fae04e0 */ 	lw	$t6,0x4e0($sp)
/*  f0194ac:	3c19ff00 */ 	lui	$t9,0xff00
/*  f0194b0:	3c01ff00 */ 	lui	$at,0xff00
/*  f0194b4:	373900ff */ 	ori	$t9,$t9,0xff
/*  f0194b8:	3c058006 */ 	lui	$a1,0x8006
/*  f0194bc:	03017825 */ 	or	$t7,$t8,$at
/*  f0194c0:	afa004a4 */ 	sw	$zero,0x4a4($sp)
/*  f0194c4:	afb904d8 */ 	sw	$t9,0x4d8($sp)
/*  f0194c8:	afaf04d4 */ 	sw	$t7,0x4d4($sp)
/*  f0194cc:	8ca523f8 */ 	lw	$a1,0x23f8($a1)
/*  f0194d0:	27a404a0 */ 	addiu	$a0,$sp,0x4a0
/*  f0194d4:	0c008682 */ 	jal	modelRender
/*  f0194d8:	afae04ac */ 	sw	$t6,0x4ac($sp)
/*  f0194dc:	8fab04ac */ 	lw	$t3,0x4ac($sp)
/*  f0194e0:	3c038006 */ 	lui	$v1,0x8006
/*  f0194e4:	8c6323f8 */ 	lw	$v1,0x23f8($v1)
/*  f0194e8:	afab04e0 */ 	sw	$t3,0x4e0($sp)
/*  f0194ec:	00001025 */ 	move	$v0,$zero
/*  f0194f0:	8c790008 */ 	lw	$t9,0x8($v1)
/*  f0194f4:	00003025 */ 	move	$a2,$zero
/*  f0194f8:	8738000e */ 	lh	$t8,0xe($t9)
/*  f0194fc:	1b00001b */ 	blez	$t8,.JF0f01956c
/*  f019500:	00000000 */ 	nop
/*  f019504:	afab04e0 */ 	sw	$t3,0x4e0($sp)
/*  f019508:	8c6f000c */ 	lw	$t7,0xc($v1)
.JF0f01950c:
/*  f01950c:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f019510:	afa2019c */ 	sw	$v0,0x19c($sp)
/*  f019514:	27a50158 */ 	addiu	$a1,$sp,0x158
/*  f019518:	0c00572e */ 	jal	mtx4Copy
/*  f01951c:	01e62021 */ 	addu	$a0,$t7,$a2
/*  f019520:	3c0e8006 */ 	lui	$t6,0x8006
/*  f019524:	8dce23f8 */ 	lw	$t6,0x23f8($t6)
/*  f019528:	8fa2019c */ 	lw	$v0,0x19c($sp)
/*  f01952c:	27a40158 */ 	addiu	$a0,$sp,0x158
/*  f019530:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f019534:	0002c180 */ 	sll	$t8,$v0,0x6
/*  f019538:	0c0057fd */ 	jal	mtx00016054
/*  f01953c:	03382821 */ 	addu	$a1,$t9,$t8
/*  f019540:	3c038006 */ 	lui	$v1,0x8006
/*  f019544:	8c6323f8 */ 	lw	$v1,0x23f8($v1)
/*  f019548:	8fa2019c */ 	lw	$v0,0x19c($sp)
/*  f01954c:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f019550:	8c6f0008 */ 	lw	$t7,0x8($v1)
/*  f019554:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f019558:	24c60040 */ 	addiu	$a2,$a2,0x40
/*  f01955c:	85ee000e */ 	lh	$t6,0xe($t7)
/*  f019560:	004e082a */ 	slt	$at,$v0,$t6
/*  f019564:	5420ffe9 */ 	bnezl	$at,.JF0f01950c
/*  f019568:	8c6f000c */ 	lw	$t7,0xc($v1)
.JF0f01956c:
/*  f01956c:	3c048006 */ 	lui	$a0,0x8006
/*  f019570:	8c84273c */ 	lw	$a0,0x273c($a0)
/*  f019574:	3c038006 */ 	lui	$v1,0x8006
/*  f019578:	8fab04e0 */ 	lw	$t3,0x4e0($sp)
/*  f01957c:	28810003 */ 	slti	$at,$a0,0x3
/*  f019580:	10200004 */ 	beqz	$at,.JF0f019594
/*  f019584:	24632468 */ 	addiu	$v1,$v1,0x2468
/*  f019588:	00004025 */ 	move	$t0,$zero
/*  f01958c:	10000092 */ 	b	.JF0f0197d8
/*  f019590:	00004825 */ 	move	$t1,$zero
.JF0f019594:
/*  f019594:	24010003 */ 	li	$at,0x3
/*  f019598:	1481002f */ 	bne	$a0,$at,.JF0f019658
/*  f01959c:	3c01436b */ 	lui	$at,0x436b
/*  f0195a0:	44814000 */ 	mtc1	$at,$f8
/*  f0195a4:	3c018006 */ 	lui	$at,0x8006
/*  f0195a8:	c4262738 */ 	lwc1	$f6,0x2738($at)
/*  f0195ac:	24090001 */ 	li	$t1,0x1
/*  f0195b0:	00004025 */ 	move	$t0,$zero
/*  f0195b4:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0195b8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0195bc:	4459f800 */ 	cfc1	$t9,$31
/*  f0195c0:	44c9f800 */ 	ctc1	$t1,$31
/*  f0195c4:	00000000 */ 	nop
/*  f0195c8:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0195cc:	4449f800 */ 	cfc1	$t1,$31
/*  f0195d0:	00000000 */ 	nop
/*  f0195d4:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0195d8:	51200019 */ 	beqzl	$t1,.JF0f019640
/*  f0195dc:	44092000 */ 	mfc1	$t1,$f4
/*  f0195e0:	44812000 */ 	mtc1	$at,$f4
/*  f0195e4:	24090001 */ 	li	$t1,0x1
/*  f0195e8:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0195ec:	44c9f800 */ 	ctc1	$t1,$31
/*  f0195f0:	00000000 */ 	nop
/*  f0195f4:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0195f8:	4449f800 */ 	cfc1	$t1,$31
/*  f0195fc:	00000000 */ 	nop
/*  f019600:	31290078 */ 	andi	$t1,$t1,0x78
/*  f019604:	55200009 */ 	bnezl	$t1,.JF0f01962c
/*  f019608:	2409ffff */ 	li	$t1,-1
/*  f01960c:	44092000 */ 	mfc1	$t1,$f4
/*  f019610:	3c018000 */ 	lui	$at,0x8000
/*  f019614:	44d9f800 */ 	ctc1	$t9,$31
/*  f019618:	01214825 */ 	or	$t1,$t1,$at
/*  f01961c:	313800ff */ 	andi	$t8,$t1,0xff
/*  f019620:	1000006d */ 	b	.JF0f0197d8
/*  f019624:	03004825 */ 	move	$t1,$t8
.JF0f019628:
/*  f019628:	2409ffff */ 	li	$t1,-1
.JF0f01962c:
/*  f01962c:	313800ff */ 	andi	$t8,$t1,0xff
/*  f019630:	44d9f800 */ 	ctc1	$t9,$31
/*  f019634:	10000068 */ 	b	.JF0f0197d8
/*  f019638:	03004825 */ 	move	$t1,$t8
/*  f01963c:	44092000 */ 	mfc1	$t1,$f4
.JF0f019640:
/*  f019640:	00000000 */ 	nop
/*  f019644:	0520fff8 */ 	bltz	$t1,.JF0f019628
/*  f019648:	313800ff */ 	andi	$t8,$t1,0xff
/*  f01964c:	44d9f800 */ 	ctc1	$t9,$31
/*  f019650:	10000061 */ 	b	.JF0f0197d8
/*  f019654:	03004825 */ 	move	$t1,$t8
.JF0f019658:
/*  f019658:	24010004 */ 	li	$at,0x4
/*  f01965c:	1481002c */ 	bne	$a0,$at,.JF0f019710
/*  f019660:	3c01436b */ 	lui	$at,0x436b
/*  f019664:	44814000 */ 	mtc1	$at,$f8
/*  f019668:	3c018006 */ 	lui	$at,0x8006
/*  f01966c:	c4262738 */ 	lwc1	$f6,0x2738($at)
/*  f019670:	24080001 */ 	li	$t0,0x1
/*  f019674:	3c014f00 */ 	lui	$at,0x4f00
/*  f019678:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f01967c:	444ff800 */ 	cfc1	$t7,$31
/*  f019680:	44c8f800 */ 	ctc1	$t0,$31
/*  f019684:	00000000 */ 	nop
/*  f019688:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f01968c:	4448f800 */ 	cfc1	$t0,$31
/*  f019690:	00000000 */ 	nop
/*  f019694:	31080078 */ 	andi	$t0,$t0,0x78
/*  f019698:	51000017 */ 	beqzl	$t0,.JF0f0196f8
/*  f01969c:	44082000 */ 	mfc1	$t0,$f4
/*  f0196a0:	44812000 */ 	mtc1	$at,$f4
/*  f0196a4:	24080001 */ 	li	$t0,0x1
/*  f0196a8:	3c018000 */ 	lui	$at,0x8000
/*  f0196ac:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0196b0:	240900ff */ 	li	$t1,0xff
/*  f0196b4:	44c8f800 */ 	ctc1	$t0,$31
/*  f0196b8:	00000000 */ 	nop
/*  f0196bc:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0196c0:	4448f800 */ 	cfc1	$t0,$31
/*  f0196c4:	00000000 */ 	nop
/*  f0196c8:	31080078 */ 	andi	$t0,$t0,0x78
/*  f0196cc:	55000006 */ 	bnezl	$t0,.JF0f0196e8
/*  f0196d0:	44cff800 */ 	ctc1	$t7,$31
/*  f0196d4:	44082000 */ 	mfc1	$t0,$f4
/*  f0196d8:	44cff800 */ 	ctc1	$t7,$31
/*  f0196dc:	1000003e */ 	b	.JF0f0197d8
/*  f0196e0:	01014025 */ 	or	$t0,$t0,$at
/*  f0196e4:	44cff800 */ 	ctc1	$t7,$31
.JF0f0196e8:
/*  f0196e8:	2408ffff */ 	li	$t0,-1
/*  f0196ec:	1000003a */ 	b	.JF0f0197d8
/*  f0196f0:	240900ff */ 	li	$t1,0xff
/*  f0196f4:	44082000 */ 	mfc1	$t0,$f4
.JF0f0196f8:
/*  f0196f8:	00000000 */ 	nop
/*  f0196fc:	0502fffa */ 	bltzl	$t0,.JF0f0196e8
/*  f019700:	44cff800 */ 	ctc1	$t7,$31
/*  f019704:	44cff800 */ 	ctc1	$t7,$31
/*  f019708:	10000033 */ 	b	.JF0f0197d8
/*  f01970c:	240900ff */ 	li	$t1,0xff
.JF0f019710:
/*  f019710:	24010005 */ 	li	$at,0x5
/*  f019714:	1481002f */ 	bne	$a0,$at,.JF0f0197d4
/*  f019718:	24080061 */ 	li	$t0,0x61
/*  f01971c:	3c01430a */ 	lui	$at,0x430a
/*  f019720:	44814000 */ 	mtc1	$at,$f8
/*  f019724:	3c018006 */ 	lui	$at,0x8006
/*  f019728:	c4262738 */ 	lwc1	$f6,0x2738($at)
/*  f01972c:	3c01436b */ 	lui	$at,0x436b
/*  f019730:	44812000 */ 	mtc1	$at,$f4
/*  f019734:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f019738:	24020001 */ 	li	$v0,0x1
/*  f01973c:	afab04e0 */ 	sw	$t3,0x4e0($sp)
/*  f019740:	3c014f00 */ 	lui	$at,0x4f00
/*  f019744:	8fab04e0 */ 	lw	$t3,0x4e0($sp)
/*  f019748:	460a2201 */ 	sub.s	$f8,$f4,$f10
/*  f01974c:	444ef800 */ 	cfc1	$t6,$31
/*  f019750:	44c2f800 */ 	ctc1	$v0,$31
/*  f019754:	00000000 */ 	nop
/*  f019758:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f01975c:	4442f800 */ 	cfc1	$v0,$31
/*  f019760:	00000000 */ 	nop
/*  f019764:	30420078 */ 	andi	$v0,$v0,0x78
/*  f019768:	50400013 */ 	beqzl	$v0,.JF0f0197b8
/*  f01976c:	44023000 */ 	mfc1	$v0,$f6
/*  f019770:	44813000 */ 	mtc1	$at,$f6
/*  f019774:	24020001 */ 	li	$v0,0x1
/*  f019778:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f01977c:	44c2f800 */ 	ctc1	$v0,$31
/*  f019780:	00000000 */ 	nop
/*  f019784:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f019788:	4442f800 */ 	cfc1	$v0,$31
/*  f01978c:	00000000 */ 	nop
/*  f019790:	30420078 */ 	andi	$v0,$v0,0x78
/*  f019794:	14400005 */ 	bnez	$v0,.JF0f0197ac
/*  f019798:	00000000 */ 	nop
/*  f01979c:	44023000 */ 	mfc1	$v0,$f6
/*  f0197a0:	3c018000 */ 	lui	$at,0x8000
/*  f0197a4:	10000007 */ 	b	.JF0f0197c4
/*  f0197a8:	00411025 */ 	or	$v0,$v0,$at
.JF0f0197ac:
/*  f0197ac:	10000005 */ 	b	.JF0f0197c4
/*  f0197b0:	2402ffff */ 	li	$v0,-1
/*  f0197b4:	44023000 */ 	mfc1	$v0,$f6
.JF0f0197b8:
/*  f0197b8:	00000000 */ 	nop
/*  f0197bc:	0440fffb */ 	bltz	$v0,.JF0f0197ac
/*  f0197c0:	00000000 */ 	nop
.JF0f0197c4:
/*  f0197c4:	44cef800 */ 	ctc1	$t6,$31
/*  f0197c8:	00404025 */ 	move	$t0,$v0
/*  f0197cc:	10000002 */ 	b	.JF0f0197d8
/*  f0197d0:	304900ff */ 	andi	$t1,$v0,0xff
.JF0f0197d4:
/*  f0197d4:	24090061 */ 	li	$t1,0x61
.JF0f0197d8:
/*  f0197d8:	241800ff */ 	li	$t8,0xff
/*  f0197dc:	00001025 */ 	move	$v0,$zero
/*  f0197e0:	a078000c */ 	sb	$t8,0xc($v1)
/*  f0197e4:	a0780008 */ 	sb	$t8,0x8($v1)
/*  f0197e8:	a062000d */ 	sb	$v0,0xd($v1)
/*  f0197ec:	a062000a */ 	sb	$v0,0xa($v1)
/*  f0197f0:	a0620009 */ 	sb	$v0,0x9($v1)
/*  f0197f4:	a060000e */ 	sb	$zero,0xe($v1)
/*  f0197f8:	01602025 */ 	move	$a0,$t3
/*  f0197fc:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f019800:	3c0e8000 */ 	lui	$t6,0x8000
/*  f019804:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f019808:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f01980c:	25650008 */ 	addiu	$a1,$t3,0x8
/*  f019810:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f019814:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f019818:	3c188006 */ 	lui	$t8,0x8006
/*  f01981c:	3c190386 */ 	lui	$t9,0x386
/*  f019820:	37390010 */ 	ori	$t9,$t9,0x10
/*  f019824:	27182470 */ 	addiu	$t8,$t8,0x2470
/*  f019828:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f01982c:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f019830:	24a60008 */ 	addiu	$a2,$a1,0x8
/*  f019834:	3c0f0388 */ 	lui	$t7,0x388
/*  f019838:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f01983c:	24c70008 */ 	addiu	$a3,$a2,0x8
/*  f019840:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f019844:	acc30004 */ 	sw	$v1,0x4($a2)
/*  f019848:	3c198000 */ 	lui	$t9,0x8000
/*  f01984c:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f019850:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f019854:	37390040 */ 	ori	$t9,$t9,0x40
/*  f019858:	24ea0008 */ 	addiu	$t2,$a3,0x8
/*  f01985c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f019860:	acf90004 */ 	sw	$t9,0x4($a3)
/*  f019864:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f019868:	3c180386 */ 	lui	$t8,0x386
/*  f01986c:	37180010 */ 	ori	$t8,$t8,0x10
/*  f019870:	afab04e0 */ 	sw	$t3,0x4e0($sp)
/*  f019874:	ad580000 */ 	sw	$t8,0x0($t2)
/*  f019878:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f01987c:	3c180388 */ 	lui	$t8,0x388
/*  f019880:	37180010 */ 	ori	$t8,$t8,0x10
/*  f019884:	ad4f0004 */ 	sw	$t7,0x4($t2)
/*  f019888:	8fae04e0 */ 	lw	$t6,0x4e0($sp)
/*  f01988c:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f019890:	afb904e0 */ 	sw	$t9,0x4e0($sp)
/*  f019894:	add80000 */ 	sw	$t8,0x0($t6)
/*  f019898:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f01989c:	3c198006 */ 	lui	$t9,0x8006
/*  f0198a0:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0198a4:	8f3923fc */ 	lw	$t9,0x23fc($t9)
/*  f0198a8:	27ae03e0 */ 	addiu	$t6,$sp,0x3e0
/*  f0198ac:	afae04a0 */ 	sw	$t6,0x4a0($sp)
/*  f0198b0:	8f380008 */ 	lw	$t8,0x8($t9)
/*  f0198b4:	8704000e */ 	lh	$a0,0xe($t8)
/*  f0198b8:	afa90150 */ 	sw	$t1,0x150($sp)
/*  f0198bc:	afa80154 */ 	sw	$t0,0x154($sp)
/*  f0198c0:	00047980 */ 	sll	$t7,$a0,0x6
/*  f0198c4:	0fc59f81 */ 	jal	gfxAllocate
/*  f0198c8:	01e02025 */ 	move	$a0,$t7
/*  f0198cc:	afa204b0 */ 	sw	$v0,0x4b0($sp)
/*  f0198d0:	27a403e0 */ 	addiu	$a0,$sp,0x3e0
/*  f0198d4:	0c00572e */ 	jal	mtx4Copy
/*  f0198d8:	00402825 */ 	move	$a1,$v0
/*  f0198dc:	3c028006 */ 	lui	$v0,0x8006
/*  f0198e0:	244223fc */ 	addiu	$v0,$v0,0x23fc
/*  f0198e4:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0198e8:	8fae04b0 */ 	lw	$t6,0x4b0($sp)
/*  f0198ec:	af2e000c */ 	sw	$t6,0xc($t9)
/*  f0198f0:	0c0072fc */ 	jal	model0001cc20
/*  f0198f4:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f0198f8:	8fa80154 */ 	lw	$t0,0x154($sp)
/*  f0198fc:	24180005 */ 	li	$t8,0x5
/*  f019900:	8fa90150 */ 	lw	$t1,0x150($sp)
/*  f019904:	00081600 */ 	sll	$v0,$t0,0x18
/*  f019908:	0002182b */ 	sltu	$v1,$zero,$v0
/*  f01990c:	afa004a4 */ 	sw	$zero,0x4a4($sp)
/*  f019910:	14600008 */ 	bnez	$v1,.JF0f019934
/*  f019914:	afb804d0 */ 	sw	$t8,0x4d0($sp)
/*  f019918:	00081400 */ 	sll	$v0,$t0,0x10
/*  f01991c:	0002182b */ 	sltu	$v1,$zero,$v0
/*  f019920:	54600005 */ 	bnezl	$v1,.JF0f019938
/*  f019924:	8faf04e0 */ 	lw	$t7,0x4e0($sp)
/*  f019928:	00081a00 */ 	sll	$v1,$t0,0x8
/*  f01992c:	347900ff */ 	ori	$t9,$v1,0xff
/*  f019930:	0019182b */ 	sltu	$v1,$zero,$t9
.JF0f019934:
/*  f019934:	8faf04e0 */ 	lw	$t7,0x4e0($sp)
.JF0f019938:
/*  f019938:	3c058006 */ 	lui	$a1,0x8006
/*  f01993c:	afa304d8 */ 	sw	$v1,0x4d8($sp)
/*  f019940:	afa904d4 */ 	sw	$t1,0x4d4($sp)
/*  f019944:	8ca523fc */ 	lw	$a1,0x23fc($a1)
/*  f019948:	27a404a0 */ 	addiu	$a0,$sp,0x4a0
/*  f01994c:	0c008682 */ 	jal	modelRender
/*  f019950:	afaf04ac */ 	sw	$t7,0x4ac($sp)
/*  f019954:	8fae04ac */ 	lw	$t6,0x4ac($sp)
/*  f019958:	3c038006 */ 	lui	$v1,0x8006
/*  f01995c:	8c6323fc */ 	lw	$v1,0x23fc($v1)
/*  f019960:	afae04e0 */ 	sw	$t6,0x4e0($sp)
/*  f019964:	00001025 */ 	move	$v0,$zero
/*  f019968:	8c790008 */ 	lw	$t9,0x8($v1)
/*  f01996c:	00003025 */ 	move	$a2,$zero
/*  f019970:	8738000e */ 	lh	$t8,0xe($t9)
/*  f019974:	1b00001a */ 	blez	$t8,.JF0f0199e0
/*  f019978:	00000000 */ 	nop
/*  f01997c:	8c6f000c */ 	lw	$t7,0xc($v1)
.JF0f019980:
/*  f019980:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f019984:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f019988:	27a500f4 */ 	addiu	$a1,$sp,0xf4
/*  f01998c:	0c00572e */ 	jal	mtx4Copy
/*  f019990:	01e62021 */ 	addu	$a0,$t7,$a2
/*  f019994:	3c0e8006 */ 	lui	$t6,0x8006
/*  f019998:	8dce23fc */ 	lw	$t6,0x23fc($t6)
/*  f01999c:	8fa2014c */ 	lw	$v0,0x14c($sp)
/*  f0199a0:	27a400f4 */ 	addiu	$a0,$sp,0xf4
/*  f0199a4:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f0199a8:	0002c180 */ 	sll	$t8,$v0,0x6
/*  f0199ac:	0c0057fd */ 	jal	mtx00016054
/*  f0199b0:	03382821 */ 	addu	$a1,$t9,$t8
/*  f0199b4:	3c038006 */ 	lui	$v1,0x8006
/*  f0199b8:	8c6323fc */ 	lw	$v1,0x23fc($v1)
/*  f0199bc:	8fa2014c */ 	lw	$v0,0x14c($sp)
/*  f0199c0:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f0199c4:	8c6f0008 */ 	lw	$t7,0x8($v1)
/*  f0199c8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0199cc:	24c60040 */ 	addiu	$a2,$a2,0x40
/*  f0199d0:	85ee000e */ 	lh	$t6,0xe($t7)
/*  f0199d4:	004e082a */ 	slt	$at,$v0,$t6
/*  f0199d8:	5420ffe9 */ 	bnezl	$at,.JF0f019980
/*  f0199dc:	8c6f000c */ 	lw	$t7,0xc($v1)
.JF0f0199e0:
/*  f0199e0:	0c005654 */ 	jal	mtx4LoadIdentity
/*  f0199e4:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*  f0199e8:	3c01800a */ 	lui	$at,0x800a
/*  f0199ec:	c424d34c */ 	lwc1	$f4,-0x2cb4($at)
/*  f0199f0:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0199f4:	44815000 */ 	mtc1	$at,$f10
/*  f0199f8:	27a500b0 */ 	addiu	$a1,$sp,0xb0
/*  f0199fc:	460a2302 */ 	mul.s	$f12,$f4,$f10
/*  f019a00:	0c0057a9 */ 	jal	mtx00015f04
/*  f019a04:	00000000 */ 	nop
/*  f019a08:	44804000 */ 	mtc1	$zero,$f8
/*  f019a0c:	44803000 */ 	mtc1	$zero,$f6
/*  f019a10:	3c013f80 */ 	lui	$at,0x3f80
/*  f019a14:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f019a18:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f019a1c:	44803000 */ 	mtc1	$zero,$f6
/*  f019a20:	44814000 */ 	mtc1	$at,$f8
/*  f019a24:	44802000 */ 	mtc1	$zero,$f4
/*  f019a28:	44805000 */ 	mtc1	$zero,$f10
/*  f019a2c:	27a40460 */ 	addiu	$a0,$sp,0x460
/*  f019a30:	24050000 */ 	li	$a1,0x0
/*  f019a34:	24060000 */ 	li	$a2,0x0
/*  f019a38:	3c07457a */ 	lui	$a3,0x457a
/*  f019a3c:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f019a40:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*  f019a44:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*  f019a48:	0c005aa1 */ 	jal	mtx00016ae4
/*  f019a4c:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*  f019a50:	27a40460 */ 	addiu	$a0,$sp,0x460
/*  f019a54:	0c005667 */ 	jal	mtx4MultMtx4InPlace
/*  f019a58:	27a500b0 */ 	addiu	$a1,$sp,0xb0
/*  f019a5c:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*  f019a60:	0c00572e */ 	jal	mtx4Copy
/*  f019a64:	27a50460 */ 	addiu	$a1,$sp,0x460
/*  f019a68:	3c188006 */ 	lui	$t8,0x8006
/*  f019a6c:	8f1823f4 */ 	lw	$t8,0x23f4($t8)
/*  f019a70:	27b90460 */ 	addiu	$t9,$sp,0x460
/*  f019a74:	afb904a0 */ 	sw	$t9,0x4a0($sp)
/*  f019a78:	8f0f0008 */ 	lw	$t7,0x8($t8)
/*  f019a7c:	85e4000e */ 	lh	$a0,0xe($t7)
/*  f019a80:	00047180 */ 	sll	$t6,$a0,0x6
/*  f019a84:	0fc59f81 */ 	jal	gfxAllocate
/*  f019a88:	01c02025 */ 	move	$a0,$t6
/*  f019a8c:	afa204b0 */ 	sw	$v0,0x4b0($sp)
/*  f019a90:	27a40460 */ 	addiu	$a0,$sp,0x460
/*  f019a94:	0c00572e */ 	jal	mtx4Copy
/*  f019a98:	00402825 */ 	move	$a1,$v0
/*  f019a9c:	3c028006 */ 	lui	$v0,0x8006
/*  f019aa0:	244223f4 */ 	addiu	$v0,$v0,0x23f4
/*  f019aa4:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f019aa8:	8fb904b0 */ 	lw	$t9,0x4b0($sp)
/*  f019aac:	af19000c */ 	sw	$t9,0xc($t8)
/*  f019ab0:	0c0072fc */ 	jal	model0001cc20
/*  f019ab4:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f019ab8:	8fb804e0 */ 	lw	$t8,0x4e0($sp)
/*  f019abc:	240f0005 */ 	li	$t7,0x5
/*  f019ac0:	240e00ff */ 	li	$t6,0xff
/*  f019ac4:	241900ff */ 	li	$t9,0xff
/*  f019ac8:	3c058006 */ 	lui	$a1,0x8006
/*  f019acc:	afa004a4 */ 	sw	$zero,0x4a4($sp)
/*  f019ad0:	afaf04d0 */ 	sw	$t7,0x4d0($sp)
/*  f019ad4:	afae04d8 */ 	sw	$t6,0x4d8($sp)
/*  f019ad8:	afb904d4 */ 	sw	$t9,0x4d4($sp)
/*  f019adc:	8ca523f4 */ 	lw	$a1,0x23f4($a1)
/*  f019ae0:	27a404a0 */ 	addiu	$a0,$sp,0x4a0
/*  f019ae4:	0c008682 */ 	jal	modelRender
/*  f019ae8:	afb804ac */ 	sw	$t8,0x4ac($sp)
/*  f019aec:	8faf04ac */ 	lw	$t7,0x4ac($sp)
/*  f019af0:	3c038006 */ 	lui	$v1,0x8006
/*  f019af4:	8c6323f4 */ 	lw	$v1,0x23f4($v1)
/*  f019af8:	afaf04e0 */ 	sw	$t7,0x4e0($sp)
/*  f019afc:	00001025 */ 	move	$v0,$zero
/*  f019b00:	8c6e0008 */ 	lw	$t6,0x8($v1)
/*  f019b04:	00003025 */ 	move	$a2,$zero
/*  f019b08:	85d9000e */ 	lh	$t9,0xe($t6)
/*  f019b0c:	5b20001b */ 	blezl	$t9,.JF0f019b7c
/*  f019b10:	8fa204e0 */ 	lw	$v0,0x4e0($sp)
/*  f019b14:	8c78000c */ 	lw	$t8,0xc($v1)
.JF0f019b18:
/*  f019b18:	afa60044 */ 	sw	$a2,0x44($sp)
/*  f019b1c:	afa2009c */ 	sw	$v0,0x9c($sp)
/*  f019b20:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f019b24:	0c00572e */ 	jal	mtx4Copy
/*  f019b28:	03062021 */ 	addu	$a0,$t8,$a2
/*  f019b2c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f019b30:	8def23f4 */ 	lw	$t7,0x23f4($t7)
/*  f019b34:	8fa2009c */ 	lw	$v0,0x9c($sp)
/*  f019b38:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f019b3c:	8dee000c */ 	lw	$t6,0xc($t7)
/*  f019b40:	0002c980 */ 	sll	$t9,$v0,0x6
/*  f019b44:	0c0057fd */ 	jal	mtx00016054
/*  f019b48:	01d92821 */ 	addu	$a1,$t6,$t9
/*  f019b4c:	3c038006 */ 	lui	$v1,0x8006
/*  f019b50:	8c6323f4 */ 	lw	$v1,0x23f4($v1)
/*  f019b54:	8fa2009c */ 	lw	$v0,0x9c($sp)
/*  f019b58:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f019b5c:	8c780008 */ 	lw	$t8,0x8($v1)
/*  f019b60:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f019b64:	24c60040 */ 	addiu	$a2,$a2,0x40
/*  f019b68:	870f000e */ 	lh	$t7,0xe($t8)
/*  f019b6c:	004f082a */ 	slt	$at,$v0,$t7
/*  f019b70:	5420ffe9 */ 	bnezl	$at,.JF0f019b18
/*  f019b74:	8c78000c */ 	lw	$t8,0xc($v1)
.JF0f019b78:
/*  f019b78:	8fa204e0 */ 	lw	$v0,0x4e0($sp)
.JF0f019b7c:
/*  f019b7c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.JF0f019b80:
/*  f019b80:	27bd04e0 */ 	addiu	$sp,$sp,0x4e0
/*  f019b84:	03e00008 */ 	jr	$ra
/*  f019b88:	00000000 */ 	nop
);
#elif VERSION >= VERSION_PAL_FINAL
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
#elif VERSION >= VERSION_PAL_BETA
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
/*  f017b4c:	27bdfcd0 */ 	addiu	$sp,$sp,-816
/*  f017b50:	3c0f8006 */ 	lui	$t7,0x8006
/*  f017b54:	3c028006 */ 	lui	$v0,0x8006
/*  f017b58:	25ef3ed8 */ 	addiu	$t7,$t7,0x3ed8
/*  f017b5c:	24423df0 */ 	addiu	$v0,$v0,0x3df0
/*  f017b60:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f017b64:	afa40330 */ 	sw	$a0,0x330($sp)
/*  f017b68:	25f9003c */ 	addiu	$t9,$t7,0x3c
/*  f017b6c:	27ae02f0 */ 	addiu	$t6,$sp,0x2f0
.PB0f017b70:
/*  f017b70:	8de10000 */ 	lw	$at,0x0($t7)
/*  f017b74:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f017b78:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f017b7c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f017b80:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f017b84:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f017b88:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f017b8c:	15f9fff8 */ 	bne	$t7,$t9,.PB0f017b70
/*  f017b90:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f017b94:	8de10000 */ 	lw	$at,0x0($t7)
/*  f017b98:	3c188006 */ 	lui	$t8,0x8006
/*  f017b9c:	3c048006 */ 	lui	$a0,0x8006
/*  f017ba0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f017ba4:	8f183b84 */ 	lw	$t8,0x3b84($t8)
/*  f017ba8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017bac:	c428a0c0 */ 	lwc1	$f8,-0x5f40($at)
/*  f017bb0:	44982000 */ 	mtc1	$t8,$f4
/*  f017bb4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017bb8:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f017bbc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f017bc0:	c424a0c4 */ 	lwc1	$f4,-0x5f3c($at)
/*  f017bc4:	3c098006 */ 	lui	$t1,0x8006
/*  f017bc8:	3c0a8006 */ 	lui	$t2,0x8006
/*  f017bcc:	3c0c8006 */ 	lui	$t4,0x8006
/*  f017bd0:	3c0d8006 */ 	lui	$t5,0x8006
/*  f017bd4:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f017bd8:	3c0b8006 */ 	lui	$t3,0x8006
/*  f017bdc:	25ad3ec0 */ 	addiu	$t5,$t5,0x3ec0
/*  f017be0:	258c3eb0 */ 	addiu	$t4,$t4,0x3eb0
/*  f017be4:	254a3ea0 */ 	addiu	$t2,$t2,0x3ea0
/*  f017be8:	25293e94 */ 	addiu	$t1,$t1,0x3e94
/*  f017bec:	3c013f80 */ 	lui	$at,0x3f80
/*  f017bf0:	24843e8c */ 	addiu	$a0,$a0,0x3e8c
/*  f017bf4:	24030001 */ 	li	$v1,0x1
/*  f017bf8:	256b3e84 */ 	addiu	$t3,$t3,0x3e84
/*  f017bfc:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f017c00:	13200041 */ 	beqz	$t9,.PB0f017d08
/*  f017c04:	e7a6013c */ 	swc1	$f6,0x13c($sp)
/*  f017c08:	44817000 */ 	mtc1	$at,$f14
/*  f017c0c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017c10:	c428a0c8 */ 	lwc1	$f8,-0x5f38($at)
/*  f017c14:	3c018006 */ 	lui	$at,0x8006
/*  f017c18:	44809000 */ 	mtc1	$zero,$f18
/*  f017c1c:	e4283e68 */ 	swc1	$f8,0x3e68($at)
/*  f017c20:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017c24:	c42aa0cc */ 	lwc1	$f10,-0x5f34($at)
/*  f017c28:	3c018006 */ 	lui	$at,0x8006
/*  f017c2c:	3c1f8006 */ 	lui	$ra,0x8006
/*  f017c30:	e42a3e6c */ 	swc1	$f10,0x3e6c($at)
/*  f017c34:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017c38:	c424a0d0 */ 	lwc1	$f4,-0x5f30($at)
/*  f017c3c:	3c018006 */ 	lui	$at,0x8006
/*  f017c40:	27ff3e98 */ 	addiu	$ra,$ra,0x3e98
/*  f017c44:	e4243e70 */ 	swc1	$f4,0x3e70($at)
/*  f017c48:	3c018006 */ 	lui	$at,0x8006
/*  f017c4c:	e4323e74 */ 	swc1	$f18,0x3e74($at)
/*  f017c50:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017c54:	c426a0d4 */ 	lwc1	$f6,-0x5f2c($at)
/*  f017c58:	3c018006 */ 	lui	$at,0x8006
/*  f017c5c:	240fffff */ 	li	$t7,-1
/*  f017c60:	e4263e78 */ 	swc1	$f6,0x3e78($at)
/*  f017c64:	3c018006 */ 	lui	$at,0x8006
/*  f017c68:	e4323e7c */ 	swc1	$f18,0x3e7c($at)
/*  f017c6c:	3c018006 */ 	lui	$at,0x8006
/*  f017c70:	ac203e80 */ 	sw	$zero,0x3e80($at)
/*  f017c74:	3c018006 */ 	lui	$at,0x8006
/*  f017c78:	e42e3e88 */ 	swc1	$f14,0x3e88($at)
/*  f017c7c:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f017c80:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f017c84:	3c018006 */ 	lui	$at,0x8006
/*  f017c88:	ac203e90 */ 	sw	$zero,0x3e90($at)
/*  f017c8c:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f017c90:	afe00000 */ 	sw	$zero,0x0($ra)
/*  f017c94:	3c018006 */ 	lui	$at,0x8006
/*  f017c98:	ac203e9c */ 	sw	$zero,0x3e9c($at)
/*  f017c9c:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f017ca0:	3c018006 */ 	lui	$at,0x8006
/*  f017ca4:	ac203ea4 */ 	sw	$zero,0x3ea4($at)
/*  f017ca8:	3c018006 */ 	lui	$at,0x8006
/*  f017cac:	ac203ea8 */ 	sw	$zero,0x3ea8($at)
/*  f017cb0:	3c018006 */ 	lui	$at,0x8006
/*  f017cb4:	ac233ec4 */ 	sw	$v1,0x3ec4($at)
/*  f017cb8:	3c018006 */ 	lui	$at,0x8006
/*  f017cbc:	ac203eac */ 	sw	$zero,0x3eac($at)
/*  f017cc0:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f017cc4:	3c018006 */ 	lui	$at,0x8006
/*  f017cc8:	e4323eb4 */ 	swc1	$f18,0x3eb4($at)
/*  f017ccc:	3c018006 */ 	lui	$at,0x8006
/*  f017cd0:	ac203ebc */ 	sw	$zero,0x3ebc($at)
/*  f017cd4:	3c018006 */ 	lui	$at,0x8006
/*  f017cd8:	ac2f3eb8 */ 	sw	$t7,0x3eb8($at)
/*  f017cdc:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f017ce0:	3c018006 */ 	lui	$at,0x8006
/*  f017ce4:	ac203ecc */ 	sw	$zero,0x3ecc($at)
/*  f017ce8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017cec:	c428a0d8 */ 	lwc1	$f8,-0x5f28($at)
/*  f017cf0:	3c018006 */ 	lui	$at,0x8006
/*  f017cf4:	e4283ec8 */ 	swc1	$f8,0x3ec8($at)
/*  f017cf8:	3c018006 */ 	lui	$at,0x8006
/*  f017cfc:	ac203ed0 */ 	sw	$zero,0x3ed0($at)
/*  f017d00:	3c018006 */ 	lui	$at,0x8006
/*  f017d04:	e4323ed4 */ 	swc1	$f18,0x3ed4($at)
.PB0f017d08:
/*  f017d08:	3c048006 */ 	lui	$a0,0x8006
/*  f017d0c:	24843e8c */ 	addiu	$a0,$a0,0x3e8c
/*  f017d10:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f017d14:	3c013f80 */ 	lui	$at,0x3f80
/*  f017d18:	44817000 */ 	mtc1	$at,$f14
/*  f017d1c:	3c098006 */ 	lui	$t1,0x8006
/*  f017d20:	3c0a8006 */ 	lui	$t2,0x8006
/*  f017d24:	3c0c8006 */ 	lui	$t4,0x8006
/*  f017d28:	3c0d8006 */ 	lui	$t5,0x8006
/*  f017d2c:	3c1f8006 */ 	lui	$ra,0x8006
/*  f017d30:	44809000 */ 	mtc1	$zero,$f18
/*  f017d34:	27ff3e98 */ 	addiu	$ra,$ra,0x3e98
/*  f017d38:	25ad3ec0 */ 	addiu	$t5,$t5,0x3ec0
/*  f017d3c:	258c3eb0 */ 	addiu	$t4,$t4,0x3eb0
/*  f017d40:	254a3ea0 */ 	addiu	$t2,$t2,0x3ea0
/*  f017d44:	25293e94 */ 	addiu	$t1,$t1,0x3e94
/*  f017d48:	10400009 */ 	beqz	$v0,.PB0f017d70
/*  f017d4c:	24030001 */ 	li	$v1,0x1
/*  f017d50:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f017d54:	29c10004 */ 	slti	$at,$t6,0x4
/*  f017d58:	14200005 */ 	bnez	$at,.PB0f017d70
/*  f017d5c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f017d60:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f017d64:	3c018006 */ 	lui	$at,0x8006
/*  f017d68:	ac233e90 */ 	sw	$v1,0x3e90($at)
/*  f017d6c:	ad230000 */ 	sw	$v1,0x0($t1)
.PB0f017d70:
/*  f017d70:	3c198006 */ 	lui	$t9,0x8006
/*  f017d74:	8f393ea4 */ 	lw	$t9,0x3ea4($t9)
/*  f017d78:	3c018006 */ 	lui	$at,0x8006
/*  f017d7c:	13200049 */ 	beqz	$t9,.PB0f017ea4
/*  f017d80:	00000000 */ 	nop
/*  f017d84:	c4203e68 */ 	lwc1	$f0,0x3e68($at)
/*  f017d88:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017d8c:	3c048006 */ 	lui	$a0,0x8006
/*  f017d90:	3c068006 */ 	lui	$a2,0x8006
/*  f017d94:	4602003c */ 	c.lt.s	$f0,$f2
/*  f017d98:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017d9c:	24c63e6c */ 	addiu	$a2,$a2,0x3e6c
/*  f017da0:	24843e68 */ 	addiu	$a0,$a0,0x3e68
/*  f017da4:	45020038 */ 	bc1fl	.PB0f017e88
/*  f017da8:	4600103e */ 	c.le.s	$f2,$f0
/*  f017dac:	c420a0dc */ 	lwc1	$f0,-0x5f24($at)
/*  f017db0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017db4:	c42aa0e0 */ 	lwc1	$f10,-0x5f20($at)
/*  f017db8:	44051000 */ 	mfc1	$a1,$f2
/*  f017dbc:	44070000 */ 	mfc1	$a3,$f0
/*  f017dc0:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f017dc4:	0fc1b6b9 */ 	jal	applySpeed
/*  f017dc8:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f017dcc:	3c028006 */ 	lui	$v0,0x8006
/*  f017dd0:	3c0b8006 */ 	lui	$t3,0x8006
/*  f017dd4:	256b3e84 */ 	addiu	$t3,$t3,0x3e84
/*  f017dd8:	24423e68 */ 	addiu	$v0,$v0,0x3e68
/*  f017ddc:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017de0:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017de4:	3c098006 */ 	lui	$t1,0x8006
/*  f017de8:	3c0a8006 */ 	lui	$t2,0x8006
/*  f017dec:	4600103e */ 	c.le.s	$f2,$f0
/*  f017df0:	3c0c8006 */ 	lui	$t4,0x8006
/*  f017df4:	3c0d8006 */ 	lui	$t5,0x8006
/*  f017df8:	3c1f8006 */ 	lui	$ra,0x8006
/*  f017dfc:	44809000 */ 	mtc1	$zero,$f18
/*  f017e00:	27ff3e98 */ 	addiu	$ra,$ra,0x3e98
/*  f017e04:	25ad3ec0 */ 	addiu	$t5,$t5,0x3ec0
/*  f017e08:	258c3eb0 */ 	addiu	$t4,$t4,0x3eb0
/*  f017e0c:	254a3ea0 */ 	addiu	$t2,$t2,0x3ea0
/*  f017e10:	45000005 */ 	bc1f	.PB0f017e28
/*  f017e14:	25293e94 */ 	addiu	$t1,$t1,0x3e94
/*  f017e18:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f017e1c:	3c018006 */ 	lui	$at,0x8006
/*  f017e20:	e4323e6c */ 	swc1	$f18,0x3e6c($at)
/*  f017e24:	c4400000 */ 	lwc1	$f0,0x0($v0)
.PB0f017e28:
/*  f017e28:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017e2c:	c42ca0e4 */ 	lwc1	$f12,-0x5f1c($at)
/*  f017e30:	4600603e */ 	c.le.s	$f12,$f0
/*  f017e34:	00000000 */ 	nop
/*  f017e38:	45020009 */ 	bc1fl	.PB0f017e60
/*  f017e3c:	4612003c */ 	c.lt.s	$f0,$f18
/*  f017e40:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f017e44:	460c1181 */ 	sub.s	$f6,$f2,$f12
/*  f017e48:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f017e4c:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017e50:	e5660000 */ 	swc1	$f6,0x0($t3)
/*  f017e54:	1000000b */ 	b	.PB0f017e84
/*  f017e58:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017e5c:	4612003c */ 	c.lt.s	$f0,$f18
.PB0f017e60:
/*  f017e60:	00000000 */ 	nop
/*  f017e64:	45020008 */ 	bc1fl	.PB0f017e88
/*  f017e68:	4600103e */ 	c.le.s	$f2,$f0
/*  f017e6c:	460c0200 */ 	add.s	$f8,$f0,$f12
/*  f017e70:	460c1280 */ 	add.s	$f10,$f2,$f12
/*  f017e74:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f017e78:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017e7c:	e56a0000 */ 	swc1	$f10,0x0($t3)
/*  f017e80:	c5620000 */ 	lwc1	$f2,0x0($t3)
.PB0f017e84:
/*  f017e84:	4600103e */ 	c.le.s	$f2,$f0
.PB0f017e88:
/*  f017e88:	3c013f80 */ 	lui	$at,0x3f80
/*  f017e8c:	44817000 */ 	mtc1	$at,$f14
/*  f017e90:	24030001 */ 	li	$v1,0x1
/*  f017e94:	45000021 */ 	bc1f	.PB0f017f1c
/*  f017e98:	3c018006 */ 	lui	$at,0x8006
/*  f017e9c:	1000001f */ 	b	.PB0f017f1c
/*  f017ea0:	ac203ea4 */ 	sw	$zero,0x3ea4($at)
.PB0f017ea4:
/*  f017ea4:	3c0f8006 */ 	lui	$t7,0x8006
/*  f017ea8:	8def3e90 */ 	lw	$t7,0x3e90($t7)
/*  f017eac:	11e0001b */ 	beqz	$t7,.PB0f017f1c
/*  f017eb0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017eb4:	c42ca0ec */ 	lwc1	$f12,-0x5f14($at)
/*  f017eb8:	3c08800a */ 	lui	$t0,0x800a
/*  f017ebc:	2508e4d0 */ 	addiu	$t0,$t0,-6960
/*  f017ec0:	3c018006 */ 	lui	$at,0x8006
/*  f017ec4:	c4243e6c */ 	lwc1	$f4,0x3e6c($at)
/*  f017ec8:	c506004c */ 	lwc1	$f6,0x4c($t0)
/*  f017ecc:	3c028006 */ 	lui	$v0,0x8006
/*  f017ed0:	24423e68 */ 	addiu	$v0,$v0,0x3e68
/*  f017ed4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f017ed8:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f017edc:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f017ee0:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f017ee4:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017ee8:	4600603e */ 	c.le.s	$f12,$f0
/*  f017eec:	00000000 */ 	nop
/*  f017ef0:	45020005 */ 	bc1fl	.PB0f017f08
/*  f017ef4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f017ef8:	460c0181 */ 	sub.s	$f6,$f0,$f12
/*  f017efc:	10000007 */ 	b	.PB0f017f1c
/*  f017f00:	e4460000 */ 	swc1	$f6,0x0($v0)
/*  f017f04:	4612003c */ 	c.lt.s	$f0,$f18
.PB0f017f08:
/*  f017f08:	00000000 */ 	nop
/*  f017f0c:	45020004 */ 	bc1fl	.PB0f017f20
/*  f017f10:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f017f14:	460c0280 */ 	add.s	$f10,$f0,$f12
/*  f017f18:	e44a0000 */ 	swc1	$f10,0x0($v0)
.PB0f017f1c:
/*  f017f1c:	8d220000 */ 	lw	$v0,0x0($t1)
.PB0f017f20:
/*  f017f20:	3c08800a */ 	lui	$t0,0x800a
/*  f017f24:	3c0b8006 */ 	lui	$t3,0x8006
/*  f017f28:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017f2c:	c42ca0f0 */ 	lwc1	$f12,-0x5f10($at)
/*  f017f30:	256b3e84 */ 	addiu	$t3,$t3,0x3e84
/*  f017f34:	1040001a */ 	beqz	$v0,.PB0f017fa0
/*  f017f38:	2508e4d0 */ 	addiu	$t0,$t0,-6960
/*  f017f3c:	8d0e0038 */ 	lw	$t6,0x38($t0)
/*  f017f40:	24190042 */ 	li	$t9,0x42
/*  f017f44:	3c018006 */ 	lui	$at,0x8006
/*  f017f48:	004ec021 */ 	addu	$t8,$v0,$t6
/*  f017f4c:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f017f50:	1b000009 */ 	blez	$t8,.PB0f017f78
/*  f017f54:	03001025 */ 	move	$v0,$t8
/*  f017f58:	44824000 */ 	mtc1	$v0,$f8
/*  f017f5c:	44993000 */ 	mtc1	$t9,$f6
/*  f017f60:	3c018006 */ 	lui	$at,0x8006
/*  f017f64:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f017f68:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f017f6c:	460a2203 */ 	div.s	$f8,$f4,$f10
/*  f017f70:	10000002 */ 	b	.PB0f017f7c
/*  f017f74:	e4283e7c */ 	swc1	$f8,0x3e7c($at)
.PB0f017f78:
/*  f017f78:	e4323e7c */ 	swc1	$f18,0x3e7c($at)
.PB0f017f7c:
/*  f017f7c:	28410043 */ 	slti	$at,$v0,0x43
/*  f017f80:	54200008 */ 	bnezl	$at,.PB0f017fa4
/*  f017f84:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f017f88:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f017f8c:	afe30000 */ 	sw	$v1,0x0($ra)
/*  f017f90:	3c018006 */ 	lui	$at,0x8006
/*  f017f94:	e4323e7c */ 	swc1	$f18,0x3e7c($at)
/*  f017f98:	3c018006 */ 	lui	$at,0x8006
/*  f017f9c:	ac233e80 */ 	sw	$v1,0x3e80($at)
.PB0f017fa0:
/*  f017fa0:	8fef0000 */ 	lw	$t7,0x0($ra)
.PB0f017fa4:
/*  f017fa4:	11e00019 */ 	beqz	$t7,.PB0f01800c
/*  f017fa8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017fac:	c426a0f4 */ 	lwc1	$f6,-0x5f0c($at)
/*  f017fb0:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f017fb4:	3c018006 */ 	lui	$at,0x8006
/*  f017fb8:	c4283e7c */ 	lwc1	$f8,0x3e7c($at)
/*  f017fbc:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f017fc0:	460a4000 */ 	add.s	$f0,$f8,$f10
/*  f017fc4:	e4203e7c */ 	swc1	$f0,0x3e7c($at)
/*  f017fc8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f017fcc:	c424a0f8 */ 	lwc1	$f4,-0x5f08($at)
/*  f017fd0:	3c018006 */ 	lui	$at,0x8006
/*  f017fd4:	4600203e */ 	c.le.s	$f4,$f0
/*  f017fd8:	00000000 */ 	nop
/*  f017fdc:	45020006 */ 	bc1fl	.PB0f017ff8
/*  f017fe0:	4600703e */ 	c.le.s	$f14,$f0
/*  f017fe4:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f017fe8:	55c00003 */ 	bnezl	$t6,.PB0f017ff8
/*  f017fec:	4600703e */ 	c.le.s	$f14,$f0
/*  f017ff0:	ad430000 */ 	sw	$v1,0x0($t2)
/*  f017ff4:	4600703e */ 	c.le.s	$f14,$f0
.PB0f017ff8:
/*  f017ff8:	00000000 */ 	nop
/*  f017ffc:	45020004 */ 	bc1fl	.PB0f018010
/*  f018000:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f018004:	e42e3e7c */ 	swc1	$f14,0x3e7c($at)
/*  f018008:	afe00000 */ 	sw	$zero,0x0($ra)
.PB0f01800c:
/*  f01800c:	8d430000 */ 	lw	$v1,0x0($t2)
.PB0f018010:
/*  f018010:	10600064 */ 	beqz	$v1,.PB0f0181a4
/*  f018014:	00000000 */ 	nop
/*  f018018:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f01801c:	3c018006 */ 	lui	$at,0x8006
/*  f018020:	3c048006 */ 	lui	$a0,0x8006
/*  f018024:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f018028:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f01802c:	c4283e70 */ 	lwc1	$f8,0x3e70($at)
/*  f018030:	3c068006 */ 	lui	$a2,0x8006
/*  f018034:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018038:	4608903c */ 	c.lt.s	$f18,$f8
/*  f01803c:	24c63e74 */ 	addiu	$a2,$a2,0x3e74
/*  f018040:	24843e70 */ 	addiu	$a0,$a0,0x3e70
/*  f018044:	4502001f */ 	bc1fl	.PB0f0180c4
/*  f018048:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f01804c:	c420a0fc */ 	lwc1	$f0,-0x5f04($at)
/*  f018050:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018054:	c42aa100 */ 	lwc1	$f10,-0x5f00($at)
/*  f018058:	44059000 */ 	mfc1	$a1,$f18
/*  f01805c:	44070000 */ 	mfc1	$a3,$f0
/*  f018060:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f018064:	0fc1b736 */ 	jal	applyRotation
/*  f018068:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f01806c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018070:	c42ca104 */ 	lwc1	$f12,-0x5efc($at)
/*  f018074:	3c018006 */ 	lui	$at,0x8006
/*  f018078:	44809000 */ 	mtc1	$zero,$f18
/*  f01807c:	c4263e70 */ 	lwc1	$f6,0x3e70($at)
/*  f018080:	3c08800a */ 	lui	$t0,0x800a
/*  f018084:	3c0a8006 */ 	lui	$t2,0x8006
/*  f018088:	4612303e */ 	c.le.s	$f6,$f18
/*  f01808c:	3c0b8006 */ 	lui	$t3,0x8006
/*  f018090:	3c0c8006 */ 	lui	$t4,0x8006
/*  f018094:	3c0d8006 */ 	lui	$t5,0x8006
/*  f018098:	25ad3ec0 */ 	addiu	$t5,$t5,0x3ec0
/*  f01809c:	258c3eb0 */ 	addiu	$t4,$t4,0x3eb0
/*  f0180a0:	256b3e84 */ 	addiu	$t3,$t3,0x3e84
/*  f0180a4:	254a3ea0 */ 	addiu	$t2,$t2,0x3ea0
/*  f0180a8:	45000005 */ 	bc1f	.PB0f0180c0
/*  f0180ac:	2508e4d0 */ 	addiu	$t0,$t0,-6960
/*  f0180b0:	3c018006 */ 	lui	$at,0x8006
/*  f0180b4:	e4323e70 */ 	swc1	$f18,0x3e70($at)
/*  f0180b8:	3c018006 */ 	lui	$at,0x8006
/*  f0180bc:	e4323e74 */ 	swc1	$f18,0x3e74($at)
.PB0f0180c0:
/*  f0180c0:	8d430000 */ 	lw	$v1,0x0($t2)
.PB0f0180c4:
/*  f0180c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0180c8:	44817000 */ 	mtc1	$at,$f14
/*  f0180cc:	2861001a */ 	slti	$at,$v1,0x1a
/*  f0180d0:	1420001c */ 	bnez	$at,.PB0f018144
/*  f0180d4:	00000000 */ 	nop
/*  f0180d8:	8d0f0038 */ 	lw	$t7,0x38($t0)
/*  f0180dc:	24040001 */ 	li	$a0,0x1
/*  f0180e0:	006f7023 */ 	subu	$t6,$v1,$t7
/*  f0180e4:	29c1001a */ 	slti	$at,$t6,0x1a
/*  f0180e8:	10200016 */ 	beqz	$at,.PB0f018144
/*  f0180ec:	3c018006 */ 	lui	$at,0x8006
/*  f0180f0:	ac203e90 */ 	sw	$zero,0x3e90($at)
/*  f0180f4:	3c018006 */ 	lui	$at,0x8006
/*  f0180f8:	ac243ea4 */ 	sw	$a0,0x3ea4($at)
/*  f0180fc:	3c018006 */ 	lui	$at,0x8006
/*  f018100:	c4243e68 */ 	lwc1	$f4,0x3e68($at)
/*  f018104:	3c014080 */ 	lui	$at,0x4080
/*  f018108:	44814000 */ 	mtc1	$at,$f8
/*  f01810c:	3c013e80 */ 	lui	$at,0x3e80
/*  f018110:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f018114:	460c5183 */ 	div.s	$f6,$f10,$f12
/*  f018118:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f01811c:	44022000 */ 	mfc1	$v0,$f4
/*  f018120:	44812000 */ 	mtc1	$at,$f4
/*  f018124:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f018128:	44824000 */ 	mtc1	$v0,$f8
/*  f01812c:	00000000 */ 	nop
/*  f018130:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f018134:	460c5182 */ 	mul.s	$f6,$f10,$f12
/*  f018138:	00000000 */ 	nop
/*  f01813c:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f018140:	e5680000 */ 	swc1	$f8,0x0($t3)
.PB0f018144:
/*  f018144:	3c028006 */ 	lui	$v0,0x8006
/*  f018148:	28610054 */ 	slti	$at,$v1,0x54
/*  f01814c:	24040001 */ 	li	$a0,0x1
/*  f018150:	14200009 */ 	bnez	$at,.PB0f018178
/*  f018154:	8c423ea4 */ 	lw	$v0,0x3ea4($v0)
/*  f018158:	8d190038 */ 	lw	$t9,0x38($t0)
/*  f01815c:	3c058006 */ 	lui	$a1,0x8006
/*  f018160:	24a53ea8 */ 	addiu	$a1,$a1,0x3ea8
/*  f018164:	00797823 */ 	subu	$t7,$v1,$t9
/*  f018168:	29e10054 */ 	slti	$at,$t7,0x54
/*  f01816c:	10200002 */ 	beqz	$at,.PB0f018178
/*  f018170:	00000000 */ 	nop
/*  f018174:	aca40000 */ 	sw	$a0,0x0($a1)
.PB0f018178:
/*  f018178:	3c058006 */ 	lui	$a1,0x8006
/*  f01817c:	14400009 */ 	bnez	$v0,.PB0f0181a4
/*  f018180:	24a53ea8 */ 	addiu	$a1,$a1,0x3ea8
/*  f018184:	3c018006 */ 	lui	$at,0x8006
/*  f018188:	c42a3e70 */ 	lwc1	$f10,0x3e70($at)
/*  f01818c:	4612503e */ 	c.le.s	$f10,$f18
/*  f018190:	00000000 */ 	nop
/*  f018194:	45000003 */ 	bc1f	.PB0f0181a4
/*  f018198:	00000000 */ 	nop
/*  f01819c:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f0181a0:	aca40000 */ 	sw	$a0,0x0($a1)
.PB0f0181a4:
/*  f0181a4:	3c058006 */ 	lui	$a1,0x8006
/*  f0181a8:	24a53ea8 */ 	addiu	$a1,$a1,0x3ea8
/*  f0181ac:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f0181b0:	24040001 */ 	li	$a0,0x1
/*  f0181b4:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0181b8:	11c00012 */ 	beqz	$t6,.PB0f018204
/*  f0181bc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0181c0:	c426a108 */ 	lwc1	$f6,-0x5ef8($at)
/*  f0181c4:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f0181c8:	3c038006 */ 	lui	$v1,0x8006
/*  f0181cc:	24633e88 */ 	addiu	$v1,$v1,0x3e88
/*  f0181d0:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0181d4:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f0181d8:	3c018006 */ 	lui	$at,0x8006
/*  f0181dc:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f0181e0:	e4263e88 */ 	swc1	$f6,0x3e88($at)
/*  f0181e4:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f0181e8:	4612203e */ 	c.le.s	$f4,$f18
/*  f0181ec:	00000000 */ 	nop
/*  f0181f0:	45020005 */ 	bc1fl	.PB0f018208
/*  f0181f4:	8d820000 */ 	lw	$v0,0x0($t4)
/*  f0181f8:	e4720000 */ 	swc1	$f18,0x0($v1)
/*  f0181fc:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f018200:	ad840000 */ 	sw	$a0,0x0($t4)
.PB0f018204:
/*  f018204:	8d820000 */ 	lw	$v0,0x0($t4)
.PB0f018208:
/*  f018208:	3c0e8006 */ 	lui	$t6,0x8006
/*  f01820c:	10400009 */ 	beqz	$v0,.PB0f018234
/*  f018210:	00000000 */ 	nop
/*  f018214:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f018218:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f01821c:	2b210011 */ 	slti	$at,$t9,0x11
/*  f018220:	14200004 */ 	bnez	$at,.PB0f018234
/*  f018224:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f018228:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f01822c:	3c018006 */ 	lui	$at,0x8006
/*  f018230:	ac243eac */ 	sw	$a0,0x3eac($at)
.PB0f018234:
/*  f018234:	8dce3eac */ 	lw	$t6,0x3eac($t6)
/*  f018238:	3c018006 */ 	lui	$at,0x8006
/*  f01823c:	51c00004 */ 	beqzl	$t6,.PB0f018250
/*  f018240:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f018244:	ac203eac */ 	sw	$zero,0x3eac($at)
/*  f018248:	ada40000 */ 	sw	$a0,0x0($t5)
/*  f01824c:	8da20000 */ 	lw	$v0,0x0($t5)
.PB0f018250:
/*  f018250:	3c018006 */ 	lui	$at,0x8006
/*  f018254:	1040000f */ 	beqz	$v0,.PB0f018294
/*  f018258:	00000000 */ 	nop
/*  f01825c:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f018260:	3c068006 */ 	lui	$a2,0x8006
/*  f018264:	24c63ed0 */ 	addiu	$a2,$a2,0x3ed0
/*  f018268:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f01826c:	1b200009 */ 	blez	$t9,.PB0f018294
/*  f018270:	adb90000 */ 	sw	$t9,0x0($t5)
/*  f018274:	3c078006 */ 	lui	$a3,0x8006
/*  f018278:	3c098006 */ 	lui	$t1,0x8006
/*  f01827c:	25293eb8 */ 	addiu	$t1,$t1,0x3eb8
/*  f018280:	24e73ebc */ 	addiu	$a3,$a3,0x3ebc
/*  f018284:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f018288:	ace40000 */ 	sw	$a0,0x0($a3)
/*  f01828c:	ad240000 */ 	sw	$a0,0x0($t1)
/*  f018290:	acc40000 */ 	sw	$a0,0x0($a2)
.PB0f018294:
/*  f018294:	3c078006 */ 	lui	$a3,0x8006
/*  f018298:	24e73ebc */ 	addiu	$a3,$a3,0x3ebc
/*  f01829c:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0182a0:	3c068006 */ 	lui	$a2,0x8006
/*  f0182a4:	3c098006 */ 	lui	$t1,0x8006
/*  f0182a8:	25293eb8 */ 	addiu	$t1,$t1,0x3eb8
/*  f0182ac:	11c0002c */ 	beqz	$t6,.PB0f018360
/*  f0182b0:	24c63ed0 */ 	addiu	$a2,$a2,0x3ed0
/*  f0182b4:	ac243ecc */ 	sw	$a0,0x3ecc($at)
/*  f0182b8:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f0182bc:	3c018006 */ 	lui	$at,0x8006
/*  f0182c0:	14400008 */ 	bnez	$v0,.PB0f0182e4
/*  f0182c4:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0182c8:	c42a3eb4 */ 	lwc1	$f10,0x3eb4($at)
/*  f0182cc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0182d0:	c428a10c */ 	lwc1	$f8,-0x5ef4($at)
/*  f0182d4:	3c018006 */ 	lui	$at,0x8006
/*  f0182d8:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0182dc:	10000011 */ 	b	.PB0f018324
/*  f0182e0:	e4263eb4 */ 	swc1	$f6,0x3eb4($at)
.PB0f0182e4:
/*  f0182e4:	14820009 */ 	bne	$a0,$v0,.PB0f01830c
/*  f0182e8:	3c018006 */ 	lui	$at,0x8006
/*  f0182ec:	3c018006 */ 	lui	$at,0x8006
/*  f0182f0:	c4243eb4 */ 	lwc1	$f4,0x3eb4($at)
/*  f0182f4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0182f8:	c42aa110 */ 	lwc1	$f10,-0x5ef0($at)
/*  f0182fc:	3c018006 */ 	lui	$at,0x8006
/*  f018300:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f018304:	10000007 */ 	b	.PB0f018324
/*  f018308:	e4283eb4 */ 	swc1	$f8,0x3eb4($at)
.PB0f01830c:
/*  f01830c:	c4263eb4 */ 	lwc1	$f6,0x3eb4($at)
/*  f018310:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018314:	c424a114 */ 	lwc1	$f4,-0x5eec($at)
/*  f018318:	3c018006 */ 	lui	$at,0x8006
/*  f01831c:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f018320:	e42a3eb4 */ 	swc1	$f10,0x3eb4($at)
.PB0f018324:
/*  f018324:	3c018006 */ 	lui	$at,0x8006
/*  f018328:	c4283eb4 */ 	lwc1	$f8,0x3eb4($at)
/*  f01832c:	3c018006 */ 	lui	$at,0x8006
/*  f018330:	4608703e */ 	c.le.s	$f14,$f8
/*  f018334:	00000000 */ 	nop
/*  f018338:	45000009 */ 	bc1f	.PB0f018360
/*  f01833c:	00000000 */ 	nop
/*  f018340:	e4323eb4 */ 	swc1	$f18,0x3eb4($at)
/*  f018344:	2401000a */ 	li	$at,0xa
/*  f018348:	17010005 */ 	bne	$t8,$at,.PB0f018360
/*  f01834c:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f018350:	3c058006 */ 	lui	$a1,0x8006
/*  f018354:	24a53e9c */ 	addiu	$a1,$a1,0x3e9c
/*  f018358:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f01835c:	aca40000 */ 	sw	$a0,0x0($a1)
.PB0f018360:
/*  f018360:	8def3ecc */ 	lw	$t7,0x3ecc($t7)
/*  f018364:	3c058006 */ 	lui	$a1,0x8006
/*  f018368:	24a53e9c */ 	addiu	$a1,$a1,0x3e9c
/*  f01836c:	11e00012 */ 	beqz	$t7,.PB0f0183b8
/*  f018370:	00003825 */ 	move	$a3,$zero
/*  f018374:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018378:	c426a118 */ 	lwc1	$f6,-0x5ee8($at)
/*  f01837c:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f018380:	3c028006 */ 	lui	$v0,0x8006
/*  f018384:	24423ec8 */ 	addiu	$v0,$v0,0x3ec8
/*  f018388:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f01838c:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f018390:	3c018006 */ 	lui	$at,0x8006
/*  f018394:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f018398:	e4263ec8 */ 	swc1	$f6,0x3ec8($at)
/*  f01839c:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f0183a0:	4600603e */ 	c.le.s	$f12,$f0
/*  f0183a4:	00000000 */ 	nop
/*  f0183a8:	45020004 */ 	bc1fl	.PB0f0183bc
/*  f0183ac:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f0183b0:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f0183b4:	e4440000 */ 	swc1	$f4,0x0($v0)
.PB0f0183b8:
/*  f0183b8:	8cce0000 */ 	lw	$t6,0x0($a2)
.PB0f0183bc:
/*  f0183bc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0183c0:	51c00012 */ 	beqzl	$t6,.PB0f01840c
/*  f0183c4:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f0183c8:	c428a11c */ 	lwc1	$f8,-0x5ee4($at)
/*  f0183cc:	c50a004c */ 	lwc1	$f10,0x4c($t0)
/*  f0183d0:	3c0a8006 */ 	lui	$t2,0x8006
/*  f0183d4:	254a3ed4 */ 	addiu	$t2,$t2,0x3ed4
/*  f0183d8:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f0183dc:	c5440000 */ 	lwc1	$f4,0x0($t2)
/*  f0183e0:	3c018006 */ 	lui	$at,0x8006
/*  f0183e4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0183e8:	e4283ed4 */ 	swc1	$f8,0x3ed4($at)
/*  f0183ec:	c54a0000 */ 	lwc1	$f10,0x0($t2)
/*  f0183f0:	460a703e */ 	c.le.s	$f14,$f10
/*  f0183f4:	00000000 */ 	nop
/*  f0183f8:	45020004 */ 	bc1fl	.PB0f01840c
/*  f0183fc:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f018400:	e54e0000 */ 	swc1	$f14,0x0($t2)
/*  f018404:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f018408:	8ca20000 */ 	lw	$v0,0x0($a1)
.PB0f01840c:
/*  f01840c:	00003025 */ 	move	$a2,$zero
/*  f018410:	5040000a */ 	beqzl	$v0,.PB0f01843c
/*  f018414:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018418:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f01841c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f018420:	2b210033 */ 	slti	$at,$t9,0x33
/*  f018424:	14200004 */ 	bnez	$at,.PB0f018438
/*  f018428:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f01842c:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f018430:	3c018006 */ 	lui	$at,0x8006
/*  f018434:	ac243df4 */ 	sw	$a0,0x3df4($at)
.PB0f018438:
/*  f018438:	8fa40330 */ 	lw	$a0,0x330($sp)
.PB0f01843c:
/*  f01843c:	0c002f0c */ 	jal	viSetFillColour
/*  f018440:	00002825 */ 	move	$a1,$zero
/*  f018444:	0c002bfc */ 	jal	viFillBuffer
/*  f018448:	00402025 */ 	move	$a0,$v0
/*  f01844c:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018450:	8dce3e8c */ 	lw	$t6,0x3e8c($t6)
/*  f018454:	00401825 */ 	move	$v1,$v0
/*  f018458:	24040002 */ 	li	$a0,0x2
/*  f01845c:	11c00003 */ 	beqz	$t6,.PB0f01846c
/*  f018460:	00000000 */ 	nop
/*  f018464:	10000272 */ 	b	.PB0f018e30
/*  f018468:	8fbf0034 */ 	lw	$ra,0x34($sp)
.PB0f01846c:
/*  f01846c:	0fc5a408 */ 	jal	gfxAllocateLookAt
/*  f018470:	afa30330 */ 	sw	$v1,0x330($sp)
/*  f018474:	44809000 */ 	mtc1	$zero,$f18
/*  f018478:	3c01457a */ 	lui	$at,0x457a
/*  f01847c:	44812000 */ 	mtc1	$at,$f4
/*  f018480:	3c013f80 */ 	lui	$at,0x3f80
/*  f018484:	44813000 */ 	mtc1	$at,$f6
/*  f018488:	44069000 */ 	mfc1	$a2,$f18
/*  f01848c:	44079000 */ 	mfc1	$a3,$f18
/*  f018490:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f018494:	00402825 */ 	move	$a1,$v0
/*  f018498:	afa20134 */ 	sw	$v0,0x134($sp)
/*  f01849c:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0184a0:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f0184a4:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f0184a8:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f0184ac:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*  f0184b0:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0184b4:	0c0011b7 */ 	jal	guLookAtReflect
/*  f0184b8:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f0184bc:	8fa30330 */ 	lw	$v1,0x330($sp)
/*  f0184c0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0184c4:	c422a120 */ 	lwc1	$f2,-0x5ee0($at)
/*  f0184c8:	8fa80134 */ 	lw	$t0,0x134($sp)
/*  f0184cc:	3c180384 */ 	lui	$t8,0x384
/*  f0184d0:	37180010 */ 	ori	$t8,$t8,0x10
/*  f0184d4:	3c190382 */ 	lui	$t9,0x382
/*  f0184d8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0184dc:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0184e0:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f0184e4:	37390010 */ 	ori	$t9,$t9,0x10
/*  f0184e8:	250f0010 */ 	addiu	$t7,$t0,0x10
/*  f0184ec:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0184f0:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0184f4:	3c018006 */ 	lui	$at,0x8006
/*  f0184f8:	c4203ed4 */ 	lwc1	$f0,0x3ed4($at)
/*  f0184fc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f018500:	44814000 */ 	mtc1	$at,$f8
/*  f018504:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018508:	c42aa124 */ 	lwc1	$f10,-0x5edc($at)
/*  f01850c:	46080380 */ 	add.s	$f14,$f0,$f8
/*  f018510:	44809000 */ 	mtc1	$zero,$f18
/*  f018514:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f018518:	3c058006 */ 	lui	$a1,0x8006
/*  f01851c:	24a53c38 */ 	addiu	$a1,$a1,0x3c38
/*  f018520:	46027182 */ 	mul.s	$f6,$f14,$f2
/*  f018524:	240200ff */ 	li	$v0,0xff
/*  f018528:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f01852c:	a0a00006 */ 	sb	$zero,0x6($a1)
/*  f018530:	a0a00005 */ 	sb	$zero,0x5($a1)
/*  f018534:	46049401 */ 	sub.s	$f16,$f18,$f4
/*  f018538:	a0a00004 */ 	sb	$zero,0x4($a1)
/*  f01853c:	a0a00002 */ 	sb	$zero,0x2($a1)
/*  f018540:	46023300 */ 	add.s	$f12,$f6,$f2
/*  f018544:	46028202 */ 	mul.s	$f8,$f16,$f2
/*  f018548:	a0a00001 */ 	sb	$zero,0x1($a1)
/*  f01854c:	a0a00000 */ 	sb	$zero,0x0($a1)
/*  f018550:	a0a2000e */ 	sb	$v0,0xe($a1)
/*  f018554:	a0a2000d */ 	sb	$v0,0xd($a1)
/*  f018558:	a0a2000c */ 	sb	$v0,0xc($a1)
/*  f01855c:	a0a2000a */ 	sb	$v0,0xa($a1)
/*  f018560:	46024400 */ 	add.s	$f16,$f8,$f2
/*  f018564:	a0a20009 */ 	sb	$v0,0x9($a1)
/*  f018568:	a0a20008 */ 	sb	$v0,0x8($a1)
/*  f01856c:	e7ac00e4 */ 	swc1	$f12,0xe4($sp)
/*  f018570:	e7b000e0 */ 	swc1	$f16,0xe0($sp)
/*  f018574:	0c006b8b */ 	jal	sinf
/*  f018578:	afa60330 */ 	sw	$a2,0x330($sp)
/*  f01857c:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f018580:	0c006b88 */ 	jal	cosf
/*  f018584:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f018588:	3c0142fe */ 	lui	$at,0x42fe
/*  f01858c:	44815000 */ 	mtc1	$at,$f10
/*  f018590:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f018594:	3c018006 */ 	lui	$at,0x8006
/*  f018598:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f01859c:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0185a0:	00000000 */ 	nop
/*  f0185a4:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0185a8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0185ac:	44195000 */ 	mfc1	$t9,$f10
/*  f0185b0:	0c006b8b */ 	jal	sinf
/*  f0185b4:	a0393c48 */ 	sb	$t9,0x3c48($at)
/*  f0185b8:	3c0142fe */ 	lui	$at,0x42fe
/*  f0185bc:	44812000 */ 	mtc1	$at,$f4
/*  f0185c0:	3c018006 */ 	lui	$at,0x8006
/*  f0185c4:	c7ac00e4 */ 	lwc1	$f12,0xe4($sp)
/*  f0185c8:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0185cc:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0185d0:	440e4000 */ 	mfc1	$t6,$f8
/*  f0185d4:	0c006b88 */ 	jal	cosf
/*  f0185d8:	a02e3c49 */ 	sb	$t6,0x3c49($at)
/*  f0185dc:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f0185e0:	0c006b88 */ 	jal	cosf
/*  f0185e4:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f0185e8:	3c0142fe */ 	lui	$at,0x42fe
/*  f0185ec:	44815000 */ 	mtc1	$at,$f10
/*  f0185f0:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f0185f4:	44809000 */ 	mtc1	$zero,$f18
/*  f0185f8:	3c018006 */ 	lui	$at,0x8006
/*  f0185fc:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f018600:	44059000 */ 	mfc1	$a1,$f18
/*  f018604:	44069000 */ 	mfc1	$a2,$f18
/*  f018608:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f01860c:	3c07457a */ 	lui	$a3,0x457a
/*  f018610:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f018614:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f018618:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f01861c:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f018620:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f018624:	e7b20024 */ 	swc1	$f18,0x24($sp)
/*  f018628:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f01862c:	44195000 */ 	mfc1	$t9,$f10
/*  f018630:	00000000 */ 	nop
/*  f018634:	a0393c4a */ 	sb	$t9,0x3c4a($at)
/*  f018638:	3c013f80 */ 	lui	$at,0x3f80
/*  f01863c:	44812000 */ 	mtc1	$at,$f4
/*  f018640:	0c005d4d */ 	jal	mtx00016ae4
/*  f018644:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f018648:	3c0f8006 */ 	lui	$t7,0x8006
/*  f01864c:	8def3e80 */ 	lw	$t7,0x3e80($t7)
/*  f018650:	24010001 */ 	li	$at,0x1
/*  f018654:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018658:	15e10004 */ 	bne	$t7,$at,.PB0f01866c
/*  f01865c:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018660:	8dce3bb8 */ 	lw	$t6,0x3bb8($t6)
/*  f018664:	10000004 */ 	b	.PB0f018678
/*  f018668:	afae022c */ 	sw	$t6,0x22c($sp)
.PB0f01866c:
/*  f01866c:	3c188006 */ 	lui	$t8,0x8006
/*  f018670:	8f183bbc */ 	lw	$t8,0x3bbc($t8)
/*  f018674:	afb8022c */ 	sw	$t8,0x22c($sp)
.PB0f018678:
/*  f018678:	3c018006 */ 	lui	$at,0x8006
/*  f01867c:	0c005b71 */ 	jal	mtx4LoadYRotation
/*  f018680:	c42c3e68 */ 	lwc1	$f12,0x3e68($at)
/*  f018684:	3c018006 */ 	lui	$at,0x8006
/*  f018688:	c42c3e70 */ 	lwc1	$f12,0x3e70($at)
/*  f01868c:	0c005b4e */ 	jal	mtx4LoadXRotation
/*  f018690:	27a501a8 */ 	addiu	$a1,$sp,0x1a8
/*  f018694:	27a401a8 */ 	addiu	$a0,$sp,0x1a8
/*  f018698:	0c005913 */ 	jal	mtx4MultMtx4InPlace
/*  f01869c:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f0186a0:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f0186a4:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f0186a8:	0c005914 */ 	jal	mtx4MultMtx4
/*  f0186ac:	27a60270 */ 	addiu	$a2,$sp,0x270
/*  f0186b0:	3c018006 */ 	lui	$at,0x8006
/*  f0186b4:	c42c3e78 */ 	lwc1	$f12,0x3e78($at)
/*  f0186b8:	0c005a55 */ 	jal	mtx00015f04
/*  f0186bc:	27a50270 */ 	addiu	$a1,$sp,0x270
/*  f0186c0:	3c01437f */ 	lui	$at,0x437f
/*  f0186c4:	44813000 */ 	mtc1	$at,$f6
/*  f0186c8:	3c018006 */ 	lui	$at,0x8006
/*  f0186cc:	c4283e88 */ 	lwc1	$f8,0x3e88($at)
/*  f0186d0:	24020001 */ 	li	$v0,0x1
/*  f0186d4:	3c038006 */ 	lui	$v1,0x8006
/*  f0186d8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0186dc:	24633c20 */ 	addiu	$v1,$v1,0x3c20
/*  f0186e0:	24050002 */ 	li	$a1,0x2
/*  f0186e4:	4459f800 */ 	cfc1	$t9,$31
/*  f0186e8:	44c2f800 */ 	ctc1	$v0,$31
/*  f0186ec:	00000000 */ 	nop
/*  f0186f0:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0186f4:	4442f800 */ 	cfc1	$v0,$31
/*  f0186f8:	00000000 */ 	nop
/*  f0186fc:	30420078 */ 	andi	$v0,$v0,0x78
/*  f018700:	10400012 */ 	beqz	$v0,.PB0f01874c
/*  f018704:	3c014f00 */ 	lui	$at,0x4f00
/*  f018708:	44812000 */ 	mtc1	$at,$f4
/*  f01870c:	24020001 */ 	li	$v0,0x1
/*  f018710:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f018714:	44c2f800 */ 	ctc1	$v0,$31
/*  f018718:	00000000 */ 	nop
/*  f01871c:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f018720:	4442f800 */ 	cfc1	$v0,$31
/*  f018724:	00000000 */ 	nop
/*  f018728:	30420078 */ 	andi	$v0,$v0,0x78
/*  f01872c:	14400005 */ 	bnez	$v0,.PB0f018744
/*  f018730:	00000000 */ 	nop
/*  f018734:	44022000 */ 	mfc1	$v0,$f4
/*  f018738:	3c018000 */ 	lui	$at,0x8000
/*  f01873c:	10000007 */ 	b	.PB0f01875c
/*  f018740:	00411025 */ 	or	$v0,$v0,$at
.PB0f018744:
/*  f018744:	10000005 */ 	b	.PB0f01875c
/*  f018748:	2402ffff */ 	li	$v0,-1
.PB0f01874c:
/*  f01874c:	44022000 */ 	mfc1	$v0,$f4
/*  f018750:	00000000 */ 	nop
/*  f018754:	0440fffb */ 	bltz	$v0,.PB0f018744
/*  f018758:	00000000 */ 	nop
.PB0f01875c:
/*  f01875c:	8fae022c */ 	lw	$t6,0x22c($sp)
/*  f018760:	44d9f800 */ 	ctc1	$t9,$31
/*  f018764:	a0620006 */ 	sb	$v0,0x6($v1)
/*  f018768:	a0620005 */ 	sb	$v0,0x5($v1)
/*  f01876c:	a0620004 */ 	sb	$v0,0x4($v1)
/*  f018770:	a0620002 */ 	sb	$v0,0x2($v1)
/*  f018774:	a0620001 */ 	sb	$v0,0x1($v1)
/*  f018778:	a0620000 */ 	sb	$v0,0x0($v1)
/*  f01877c:	afa000dc */ 	sw	$zero,0xdc($sp)
/*  f018780:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f018784:	0c006cdb */ 	jal	modelGetPart
/*  f018788:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f01878c:	10400027 */ 	beqz	$v0,.PB0f01882c
/*  f018790:	00402825 */ 	move	$a1,$v0
/*  f018794:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f018798:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f01879c:	84d80010 */ 	lh	$t8,0x10($a2)
/*  f0187a0:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0187a4:	afb900dc */ 	sw	$t9,0xdc($sp)
/*  f0187a8:	94cf0016 */ 	lhu	$t7,0x16($a2)
/*  f0187ac:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f0187b0:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f0187b4:	0c006d1b */ 	jal	modelGetNodeRwData
/*  f0187b8:	afae00d8 */ 	sw	$t6,0xd8($sp)
/*  f0187bc:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0187c0:	0fc5a419 */ 	jal	gfxAllocate
/*  f0187c4:	24040028 */ 	li	$a0,0x28
/*  f0187c8:	8fb80160 */ 	lw	$t8,0x160($sp)
/*  f0187cc:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f0187d0:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f0187d4:	af020004 */ 	sw	$v0,0x4($t8)
/*  f0187d8:	3c0f8000 */ 	lui	$t7,0x8000
/*  f0187dc:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f0187e0:	37390002 */ 	ori	$t9,$t9,0x2
/*  f0187e4:	3c0e0386 */ 	lui	$t6,0x386
/*  f0187e8:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f0187ec:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0187f0:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0187f4:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0187f8:	3c190388 */ 	lui	$t9,0x388
/*  f0187fc:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f018800:	3c188006 */ 	lui	$t8,0x8006
/*  f018804:	27183bf8 */ 	addiu	$t8,$t8,0x3bf8
/*  f018808:	37390010 */ 	ori	$t9,$t9,0x10
/*  f01880c:	25ef3bf0 */ 	addiu	$t7,$t7,0x3bf0
/*  f018810:	3c0e0601 */ 	lui	$t6,0x601
/*  f018814:	ac4f0014 */ 	sw	$t7,0x14($v0)
/*  f018818:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f01881c:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f018820:	ac4e0018 */ 	sw	$t6,0x18($v0)
/*  f018824:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f018828:	ac58001c */ 	sw	$t8,0x1c($v0)
.PB0f01882c:
/*  f01882c:	8fb9022c */ 	lw	$t9,0x22c($sp)
/*  f018830:	24050004 */ 	li	$a1,0x4
/*  f018834:	0c006cdb */ 	jal	modelGetPart
/*  f018838:	8f240008 */ 	lw	$a0,0x8($t9)
/*  f01883c:	10400037 */ 	beqz	$v0,.PB0f01891c
/*  f018840:	00402825 */ 	move	$a1,$v0
/*  f018844:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f018848:	8faf00dc */ 	lw	$t7,0xdc($sp)
/*  f01884c:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f018850:	84ce0010 */ 	lh	$t6,0x10($a2)
/*  f018854:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f018858:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f01885c:	afb900dc */ 	sw	$t9,0xdc($sp)
/*  f018860:	8faf00d8 */ 	lw	$t7,0xd8($sp)
/*  f018864:	94ce0016 */ 	lhu	$t6,0x16($a2)
/*  f018868:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f01886c:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f018870:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f018874:	0c006d1b */ 	jal	modelGetNodeRwData
/*  f018878:	afb900d8 */ 	sw	$t9,0xd8($sp)
/*  f01887c:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f018880:	0fc5a419 */ 	jal	gfxAllocate
/*  f018884:	24040028 */ 	li	$a0,0x28
/*  f018888:	8faf0160 */ 	lw	$t7,0x160($sp)
/*  f01888c:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f018890:	3c018006 */ 	lui	$at,0x8006
/*  f018894:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f018898:	44809000 */ 	mtc1	$zero,$f18
/*  f01889c:	c4263e88 */ 	lwc1	$f6,0x3e88($at)
/*  f0188a0:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0188a4:	3c188000 */ 	lui	$t8,0x8000
/*  f0188a8:	4606903c */ 	c.lt.s	$f18,$f6
/*  f0188ac:	37180040 */ 	ori	$t8,$t8,0x40
/*  f0188b0:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f0188b4:	3c190386 */ 	lui	$t9,0x386
/*  f0188b8:	45000016 */ 	bc1f	.PB0f018914
/*  f0188bc:	3c0eb800 */ 	lui	$t6,0xb800
/*  f0188c0:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f0188c4:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f0188c8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0188cc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0188d0:	37390010 */ 	ori	$t9,$t9,0x10
/*  f0188d4:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0188d8:	25ef3c28 */ 	addiu	$t7,$t7,0x3c28
/*  f0188dc:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f0188e0:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f0188e4:	3c188006 */ 	lui	$t8,0x8006
/*  f0188e8:	3c0e0388 */ 	lui	$t6,0x388
/*  f0188ec:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f0188f0:	27183c20 */ 	addiu	$t8,$t8,0x3c20
/*  f0188f4:	acf80004 */ 	sw	$t8,0x4($a3)
/*  f0188f8:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f0188fc:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018900:	3c190601 */ 	lui	$t9,0x601
/*  f018904:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f018908:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f01890c:	10000003 */ 	b	.PB0f01891c
/*  f018910:	ac6f0004 */ 	sw	$t7,0x4($v1)
.PB0f018914:
/*  f018914:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f018918:	ac400004 */ 	sw	$zero,0x4($v0)
.PB0f01891c:
/*  f01891c:	8fb8022c */ 	lw	$t8,0x22c($sp)
/*  f018920:	24050006 */ 	li	$a1,0x6
/*  f018924:	0c006cdb */ 	jal	modelGetPart
/*  f018928:	8f040008 */ 	lw	$a0,0x8($t8)
/*  f01892c:	10400037 */ 	beqz	$v0,.PB0f018a0c
/*  f018930:	00402825 */ 	move	$a1,$v0
/*  f018934:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f018938:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f01893c:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f018940:	84cf0010 */ 	lh	$t7,0x10($a2)
/*  f018944:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f018948:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f01894c:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f018950:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f018954:	94cf0016 */ 	lhu	$t7,0x16($a2)
/*  f018958:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f01895c:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f018960:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f018964:	0c006d1b */ 	jal	modelGetNodeRwData
/*  f018968:	afb800d8 */ 	sw	$t8,0xd8($sp)
/*  f01896c:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f018970:	0fc5a419 */ 	jal	gfxAllocate
/*  f018974:	24040028 */ 	li	$a0,0x28
/*  f018978:	8fb90160 */ 	lw	$t9,0x160($sp)
/*  f01897c:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f018980:	3c018006 */ 	lui	$at,0x8006
/*  f018984:	af220004 */ 	sw	$v0,0x4($t9)
/*  f018988:	44809000 */ 	mtc1	$zero,$f18
/*  f01898c:	c4283e88 */ 	lwc1	$f8,0x3e88($at)
/*  f018990:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f018994:	3c0e8000 */ 	lui	$t6,0x8000
/*  f018998:	4608903c */ 	c.lt.s	$f18,$f8
/*  f01899c:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f0189a0:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f0189a4:	3c180386 */ 	lui	$t8,0x386
/*  f0189a8:	45000016 */ 	bc1f	.PB0f018a04
/*  f0189ac:	3c0fb800 */ 	lui	$t7,0xb800
/*  f0189b0:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f0189b4:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f0189b8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0189bc:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0189c0:	37180010 */ 	ori	$t8,$t8,0x10
/*  f0189c4:	3c198006 */ 	lui	$t9,0x8006
/*  f0189c8:	27393c28 */ 	addiu	$t9,$t9,0x3c28
/*  f0189cc:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f0189d0:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f0189d4:	3c0e8006 */ 	lui	$t6,0x8006
/*  f0189d8:	3c0f0388 */ 	lui	$t7,0x388
/*  f0189dc:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f0189e0:	25ce3c20 */ 	addiu	$t6,$t6,0x3c20
/*  f0189e4:	acee0004 */ 	sw	$t6,0x4($a3)
/*  f0189e8:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f0189ec:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f0189f0:	3c180601 */ 	lui	$t8,0x601
/*  f0189f4:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0189f8:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f0189fc:	10000003 */ 	b	.PB0f018a0c
/*  f018a00:	ac790004 */ 	sw	$t9,0x4($v1)
.PB0f018a04:
/*  f018a04:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f018a08:	ac400004 */ 	sw	$zero,0x4($v0)
.PB0f018a0c:
/*  f018a0c:	8fae022c */ 	lw	$t6,0x22c($sp)
/*  f018a10:	24050008 */ 	li	$a1,0x8
/*  f018a14:	0c006cdb */ 	jal	modelGetPart
/*  f018a18:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f018a1c:	10400037 */ 	beqz	$v0,.PB0f018afc
/*  f018a20:	00402825 */ 	move	$a1,$v0
/*  f018a24:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f018a28:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f018a2c:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f018a30:	84d90010 */ 	lh	$t9,0x10($a2)
/*  f018a34:	03197821 */ 	addu	$t7,$t8,$t9
/*  f018a38:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f018a3c:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f018a40:	8fb800d8 */ 	lw	$t8,0xd8($sp)
/*  f018a44:	94d90016 */ 	lhu	$t9,0x16($a2)
/*  f018a48:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f018a4c:	03197821 */ 	addu	$t7,$t8,$t9
/*  f018a50:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f018a54:	0c006d1b */ 	jal	modelGetNodeRwData
/*  f018a58:	afae00d8 */ 	sw	$t6,0xd8($sp)
/*  f018a5c:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f018a60:	0fc5a419 */ 	jal	gfxAllocate
/*  f018a64:	24040028 */ 	li	$a0,0x28
/*  f018a68:	8fb80160 */ 	lw	$t8,0x160($sp)
/*  f018a6c:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f018a70:	3c018006 */ 	lui	$at,0x8006
/*  f018a74:	af020004 */ 	sw	$v0,0x4($t8)
/*  f018a78:	44809000 */ 	mtc1	$zero,$f18
/*  f018a7c:	c42a3e88 */ 	lwc1	$f10,0x3e88($at)
/*  f018a80:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f018a84:	3c0f8000 */ 	lui	$t7,0x8000
/*  f018a88:	460a903c */ 	c.lt.s	$f18,$f10
/*  f018a8c:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f018a90:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f018a94:	3c0e0386 */ 	lui	$t6,0x386
/*  f018a98:	45000016 */ 	bc1f	.PB0f018af4
/*  f018a9c:	3c19b800 */ 	lui	$t9,0xb800
/*  f018aa0:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f018aa4:	37390002 */ 	ori	$t9,$t9,0x2
/*  f018aa8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018aac:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f018ab0:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018ab4:	3c188006 */ 	lui	$t8,0x8006
/*  f018ab8:	27183c28 */ 	addiu	$t8,$t8,0x3c28
/*  f018abc:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f018ac0:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f018ac4:	3c0f8006 */ 	lui	$t7,0x8006
/*  f018ac8:	3c190388 */ 	lui	$t9,0x388
/*  f018acc:	37390010 */ 	ori	$t9,$t9,0x10
/*  f018ad0:	25ef3c20 */ 	addiu	$t7,$t7,0x3c20
/*  f018ad4:	acef0004 */ 	sw	$t7,0x4($a3)
/*  f018ad8:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f018adc:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018ae0:	3c0e0601 */ 	lui	$t6,0x601
/*  f018ae4:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f018ae8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f018aec:	10000003 */ 	b	.PB0f018afc
/*  f018af0:	ac780004 */ 	sw	$t8,0x4($v1)
.PB0f018af4:
/*  f018af4:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018af8:	ac400004 */ 	sw	$zero,0x4($v0)
.PB0f018afc:
/*  f018afc:	0fc5a3f5 */ 	jal	gfxAllocateVertices
/*  f018b00:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f018b04:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f018b08:	0fc5a40f */ 	jal	gfxAllocateColours
/*  f018b0c:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f018b10:	3c013f80 */ 	lui	$at,0x3f80
/*  f018b14:	44812000 */ 	mtc1	$at,$f4
/*  f018b18:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f018b1c:	3c068006 */ 	lui	$a2,0x8006
/*  f018b20:	3c078006 */ 	lui	$a3,0x8006
/*  f018b24:	240f00f0 */ 	li	$t7,0xf0
/*  f018b28:	27ae0270 */ 	addiu	$t6,$sp,0x270
/*  f018b2c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f018b30:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f018b34:	8ce73e7c */ 	lw	$a3,0x3e7c($a3)
/*  f018b38:	8cc63ec4 */ 	lw	$a2,0x3ec4($a2)
/*  f018b3c:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018b40:	8fa5022c */ 	lw	$a1,0x22c($sp)
/*  f018b44:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f018b48:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018b4c:	0fc05cb5 */ 	jal	titleRenderPdLogoModel
/*  f018b50:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f018b54:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f018b58:	3c0f8000 */ 	lui	$t7,0x8000
/*  f018b5c:	3c0e0386 */ 	lui	$t6,0x386
/*  f018b60:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018b64:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f018b68:	37390002 */ 	ori	$t9,$t9,0x2
/*  f018b6c:	3c188006 */ 	lui	$t8,0x8006
/*  f018b70:	27183c40 */ 	addiu	$t8,$t8,0x3c40
/*  f018b74:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018b78:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f018b7c:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f018b80:	24590018 */ 	addiu	$t9,$v0,0x18
/*  f018b84:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f018b88:	afb90330 */ 	sw	$t9,0x330($sp)
/*  f018b8c:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018b90:	3c0f0388 */ 	lui	$t7,0x388
/*  f018b94:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f018b98:	25ce3c38 */ 	addiu	$t6,$t6,0x3c38
/*  f018b9c:	3c188006 */ 	lui	$t8,0x8006
/*  f018ba0:	ac4e0014 */ 	sw	$t6,0x14($v0)
/*  f018ba4:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f018ba8:	27183f18 */ 	addiu	$t8,$t8,0x3f18
/*  f018bac:	8f010000 */ 	lw	$at,0x0($t8)
/*  f018bb0:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f018bb4:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018bb8:	ac810000 */ 	sw	$at,0x0($a0)
/*  f018bbc:	8f0f0004 */ 	lw	$t7,0x4($t8)
/*  f018bc0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f018bc4:	8f010008 */ 	lw	$at,0x8($t8)
/*  f018bc8:	0c005c4b */ 	jal	mtx4LoadTranslation
/*  f018bcc:	ac810008 */ 	sw	$at,0x8($a0)
/*  f018bd0:	3c013f80 */ 	lui	$at,0x3f80
/*  f018bd4:	44813000 */ 	mtc1	$at,$f6
/*  f018bd8:	c7a8013c */ 	lwc1	$f8,0x13c($sp)
/*  f018bdc:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018be0:	0c005a76 */ 	jal	mtx00015f88
/*  f018be4:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f018be8:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f018bec:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018bf0:	0c005914 */ 	jal	mtx4MultMtx4
/*  f018bf4:	27a60230 */ 	addiu	$a2,$sp,0x230
/*  f018bf8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f018bfc:	c42ca128 */ 	lwc1	$f12,-0x5ed8($at)
/*  f018c00:	0c005a55 */ 	jal	mtx00015f04
/*  f018c04:	27a50230 */ 	addiu	$a1,$sp,0x230
/*  f018c08:	3c028006 */ 	lui	$v0,0x8006
/*  f018c0c:	8c423eb8 */ 	lw	$v0,0x3eb8($v0)
/*  f018c10:	27a30230 */ 	addiu	$v1,$sp,0x230
/*  f018c14:	04420085 */ 	bltzl	$v0,.PB0f018e2c
/*  f018c18:	8fa20330 */ 	lw	$v0,0x330($sp)
/*  f018c1c:	10400082 */ 	beqz	$v0,.PB0f018e28
/*  f018c20:	24010001 */ 	li	$at,0x1
/*  f018c24:	1441001f */ 	bne	$v0,$at,.PB0f018ca4
/*  f018c28:	3c058006 */ 	lui	$a1,0x8006
/*  f018c2c:	3c018006 */ 	lui	$at,0x8006
/*  f018c30:	c4203eb4 */ 	lwc1	$f0,0x3eb4($at)
/*  f018c34:	3c013f00 */ 	lui	$at,0x3f00
/*  f018c38:	44815000 */ 	mtc1	$at,$f10
/*  f018c3c:	44070000 */ 	mfc1	$a3,$f0
/*  f018c40:	00003025 */ 	move	$a2,$zero
/*  f018c44:	460a003c */ 	c.lt.s	$f0,$f10
/*  f018c48:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018c4c:	240e00ff */ 	li	$t6,0xff
/*  f018c50:	3c02800a */ 	lui	$v0,0x800a
/*  f018c54:	45000002 */ 	bc1f	.PB0f018c60
/*  f018c58:	3c18800a */ 	lui	$t8,0x800a
/*  f018c5c:	24060001 */ 	li	$a2,0x1
.PB0f018c60:
/*  f018c60:	8c4211d8 */ 	lw	$v0,0x11d8($v0)
/*  f018c64:	3c0f800a */ 	lui	$t7,0x800a
/*  f018c68:	8ca53bcc */ 	lw	$a1,0x3bcc($a1)
/*  f018c6c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018c70:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018c74:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018c78:	8def11d0 */ 	lw	$t7,0x11d0($t7)
/*  f018c7c:	8f1811c8 */ 	lw	$t8,0x11c8($t8)
/*  f018c80:	03201025 */ 	move	$v0,$t9
/*  f018c84:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018c88:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f018c8c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018c90:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018c94:	0fc05cb5 */ 	jal	titleRenderPdLogoModel
/*  f018c98:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018c9c:	10000062 */ 	b	.PB0f018e28
/*  f018ca0:	afa20330 */ 	sw	$v0,0x330($sp)
.PB0f018ca4:
/*  f018ca4:	24010002 */ 	li	$at,0x2
/*  f018ca8:	14410023 */ 	bne	$v0,$at,.PB0f018d38
/*  f018cac:	3c058006 */ 	lui	$a1,0x8006
/*  f018cb0:	3c018006 */ 	lui	$at,0x8006
/*  f018cb4:	c4203eb4 */ 	lwc1	$f0,0x3eb4($at)
/*  f018cb8:	3c013f00 */ 	lui	$at,0x3f00
/*  f018cbc:	44812000 */ 	mtc1	$at,$f4
/*  f018cc0:	3c013f80 */ 	lui	$at,0x3f80
/*  f018cc4:	44813000 */ 	mtc1	$at,$f6
/*  f018cc8:	4604003c */ 	c.lt.s	$f0,$f4
/*  f018ccc:	00003025 */ 	move	$a2,$zero
/*  f018cd0:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018cd4:	240e00ff */ 	li	$t6,0xff
/*  f018cd8:	45000002 */ 	bc1f	.PB0f018ce4
/*  f018cdc:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f018ce0:	24060001 */ 	li	$a2,0x1
.PB0f018ce4:
/*  f018ce4:	3c02800a */ 	lui	$v0,0x800a
/*  f018ce8:	8c4211d8 */ 	lw	$v0,0x11d8($v0)
/*  f018cec:	3c18800a */ 	lui	$t8,0x800a
/*  f018cf0:	3c0f800a */ 	lui	$t7,0x800a
/*  f018cf4:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018cf8:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018cfc:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018d00:	8def11d0 */ 	lw	$t7,0x11d0($t7)
/*  f018d04:	8f1811c8 */ 	lw	$t8,0x11c8($t8)
/*  f018d08:	44815000 */ 	mtc1	$at,$f10
/*  f018d0c:	44074000 */ 	mfc1	$a3,$f8
/*  f018d10:	8ca53bc8 */ 	lw	$a1,0x3bc8($a1)
/*  f018d14:	03201025 */ 	move	$v0,$t9
/*  f018d18:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018d1c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018d20:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018d24:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018d28:	0fc05cb5 */ 	jal	titleRenderPdLogoModel
/*  f018d2c:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f018d30:	1000003d */ 	b	.PB0f018e28
/*  f018d34:	afa20330 */ 	sw	$v0,0x330($sp)
.PB0f018d38:
/*  f018d38:	24010003 */ 	li	$at,0x3
/*  f018d3c:	14410022 */ 	bne	$v0,$at,.PB0f018dc8
/*  f018d40:	3c058006 */ 	lui	$a1,0x8006
/*  f018d44:	3c018006 */ 	lui	$at,0x8006
/*  f018d48:	c4203eb4 */ 	lwc1	$f0,0x3eb4($at)
/*  f018d4c:	3c013f00 */ 	lui	$at,0x3f00
/*  f018d50:	44812000 */ 	mtc1	$at,$f4
/*  f018d54:	44070000 */ 	mfc1	$a3,$f0
/*  f018d58:	00003025 */ 	move	$a2,$zero
/*  f018d5c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f018d60:	3c058006 */ 	lui	$a1,0x8006
/*  f018d64:	3c013f80 */ 	lui	$at,0x3f80
/*  f018d68:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018d6c:	45000002 */ 	bc1f	.PB0f018d78
/*  f018d70:	240e00ff */ 	li	$t6,0xff
/*  f018d74:	24060001 */ 	li	$a2,0x1
.PB0f018d78:
/*  f018d78:	3c02800a */ 	lui	$v0,0x800a
/*  f018d7c:	8c4211d8 */ 	lw	$v0,0x11d8($v0)
/*  f018d80:	3c18800a */ 	lui	$t8,0x800a
/*  f018d84:	3c0f800a */ 	lui	$t7,0x800a
/*  f018d88:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018d8c:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018d90:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018d94:	8def11d0 */ 	lw	$t7,0x11d0($t7)
/*  f018d98:	8f1811c8 */ 	lw	$t8,0x11c8($t8)
/*  f018d9c:	44813000 */ 	mtc1	$at,$f6
/*  f018da0:	8ca53bc8 */ 	lw	$a1,0x3bc8($a1)
/*  f018da4:	03201025 */ 	move	$v0,$t9
/*  f018da8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018dac:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018db0:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018db4:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018db8:	0fc05cb5 */ 	jal	titleRenderPdLogoModel
/*  f018dbc:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f018dc0:	10000019 */ 	b	.PB0f018e28
/*  f018dc4:	afa20330 */ 	sw	$v0,0x330($sp)
.PB0f018dc8:
/*  f018dc8:	3c02800a */ 	lui	$v0,0x800a
/*  f018dcc:	8c4211d8 */ 	lw	$v0,0x11d8($v0)
/*  f018dd0:	3c18800a */ 	lui	$t8,0x800a
/*  f018dd4:	3c0f800a */ 	lui	$t7,0x800a
/*  f018dd8:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018ddc:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018de0:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018de4:	3c013f80 */ 	lui	$at,0x3f80
/*  f018de8:	44814000 */ 	mtc1	$at,$f8
/*  f018dec:	8def11d0 */ 	lw	$t7,0x11d0($t7)
/*  f018df0:	8f1811c8 */ 	lw	$t8,0x11c8($t8)
/*  f018df4:	240e00ff */ 	li	$t6,0xff
/*  f018df8:	8ca53bc8 */ 	lw	$a1,0x3bc8($a1)
/*  f018dfc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018e00:	03201025 */ 	move	$v0,$t9
/*  f018e04:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018e08:	00003025 */ 	move	$a2,$zero
/*  f018e0c:	3c073f80 */ 	lui	$a3,0x3f80
/*  f018e10:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018e14:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018e18:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f018e1c:	0fc05cb5 */ 	jal	titleRenderPdLogoModel
/*  f018e20:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018e24:	afa20330 */ 	sw	$v0,0x330($sp)
.PB0f018e28:
/*  f018e28:	8fa20330 */ 	lw	$v0,0x330($sp)
.PB0f018e2c:
/*  f018e2c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.PB0f018e30:
/*  f018e30:	27bd0330 */ 	addiu	$sp,$sp,0x330
/*  f018e34:	03e00008 */ 	jr	$ra
/*  f018e38:	00000000 */ 	nop
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

	gdl = titleClear(gdl);
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

	gdl = bviewDrawIntroText(gdl);

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
		g_TitleTimer = VERSION == VERSION_PAL_FINAL ? TICKS(160) : TICKS(180);
	} else {
		g_TitleTimer = 0;
	}

	{
		struct coord coord = {0, 0, 0};

		g_ModelStates[MODEL_NINTENDOLOGO].filedata = modeldefLoad(g_ModelStates[MODEL_NINTENDOLOGO].fileid, nextaddr, 0x47800, 0);

		modelCalculateRwDataLen(g_ModelStates[MODEL_NINTENDOLOGO].filedata);
		g_TitleModel = modelInstantiateWithoutAnim(g_ModelStates[MODEL_NINTENDOLOGO].filedata);
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

#if VERSION == VERSION_PAL_FINAL
	if (g_TitleTimer > TICKS(220))
#else
	if (g_TitleTimer > TICKS(240))
#endif
	{
		titleSetNextMode(TITLEMODE_PDLOGO);
	}
}

Gfx *titleRenderNintendoLogo(Gfx *gdl)
{
	struct modelrenderdata renderdata = { NULL, true, 3 };
	s32 i;
	s32 j;
	Mtxf sp108;
	f32 fracdone = g_TitleTimer / (VERSION == VERSION_PAL_FINAL ? 183.0f : TICKS(240.0f));
	struct coord lightdir = {0, 0, 0};
	s32 v0;

	gdl = titleClear(gdl);

	gSPSetLights1(gdl++, var80062590);

	lightdir.z = sinf((1 - fracdone) * 1.5f * M_PI);
	lightdir.x = cosf((1 - fracdone) * 1.5f * M_PI);

	guNormalize(&lightdir.x, &lightdir.y, &lightdir.z);

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

	titleSetLight(&var80062590, v0, v0, v0, 0.0f, &lightdir);

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

		g_ModelStates[MODEL_RARELOGO].filedata = modeldefLoad(g_ModelStates[MODEL_RARELOGO].fileid, nextaddr, 0x47800, 0);

		modelCalculateRwDataLen(g_ModelStates[MODEL_RARELOGO].filedata);
		g_TitleModel = modelInstantiateWithoutAnim(g_ModelStates[MODEL_RARELOGO].filedata);
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

	gdl = titleClear(gdl);

	if (g_TitleTimer < 0) {
		return gdl;
	}

	{
		struct coord lightdir = {0, 0, 0};
		f32 tmp;
		Mtxf spc0;
		struct coord spb4;
		struct modelrwdata_toggle *rwdata;

		lightdir.z = sinf(func0f019d0c(fracdone));
		lightdir.x = cosf(func0f019d0c(fracdone));

		guNormalize(&lightdir.x, &lightdir.y, &lightdir.z);

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
			titleSetLight(&var80062590,
					(s32)(255.0f * fracdone / 0.2f),
					(s32)(255.0f * fracdone / 0.2f),
					(s32)(255.0f * fracdone / 0.2f),
					0, &lightdir);
		} else {
			titleSetLight(&var80062590, s0, s0, s0, 0, &lightdir);
		}

		s0 = s0 * 192 / 255;

		if (fracdone < 0.5f) {
			lightdir.z = sinf(func0f019d0c(0.5f));
			lightdir.x = cosf(func0f019d0c(0.5f));
			guNormalize(&lightdir.x, &lightdir.y, &lightdir.z);
			titleSetLight(&var800625a8, s0, s0, s0, 0, &lightdir);
		} else {
			titleSetLight(&var800625a8, s0, s0, s0, 0, &lightdir);
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

Gfx *titleRenderNoController(Gfx *gdl)
{
	s32 textheight;
	s32 textwidth;
	s32 x;
	s32 y;
	char *text;
	u32 stack[2];
	s16 tmp;
	s16 width;

	if (1);
	if (1);
	if (1);

	// This was likely printed to console
	joyGetConnectedControllers();

	gdl = titleClear(gdl);
	gdl = func0f153628(gdl);

#if VERSION >= VERSION_JPN_FINAL
	y = g_TitleViewHeight / 2 - 50;

	var8007fad0 = 2;
	var80080108jf = 2;

	// Line 1
	text = langGet(L_MPWEAPONS_285);
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - textwidth;
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, viGetWidth(), viGetHeight(), 0, 0);
	y += 18;

	// Line 2
	text = langGet(L_MPWEAPONS_286);
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - textwidth;
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, viGetWidth(), viGetHeight(), 0, 0);
	y += 28;

	// Line 3
	text = langGet(L_MPWEAPONS_287);
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - textwidth;
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, viGetWidth(), viGetHeight(), 0, 0);
	y += 18;

	// Line 4
	text = langGet(L_MPWEAPONS_288);
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - textwidth;
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, viGetWidth(), viGetHeight(), 0, 0);
	y += 18;

	var8007fad0 = 1;
	var80080108jf = 1;
#else
	// Line 1
	text = langGet(L_OPTIONS_071); // "- no controller in controller socket 1 -"
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - (textwidth >> 1);
	y = (g_TitleViewHeight / 2) - (textheight >> 1) - 12;

	if (g_Jpn) {
		width = viGetWidth();
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, 0x008000ff, width, viGetHeight(), 0, 0);
	} else {
		width = viGetWidth();
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, viGetHeight(), 0, 0);
	}

	// Line 2
	text = langGet(L_OPTIONS_072); // "please power off and attach a controller"
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - (textwidth >> 1);
	y = (g_TitleViewHeight / 2) - (textheight >> 1) + 12;

	if (g_Jpn) {
		width = viGetWidth();
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, 0x008000ff, width, viGetHeight(), 0, 0);
	} else {
		width = viGetWidth();
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, viGetHeight(), 0, 0);
	}
#endif

	gdl = func0f153780(gdl);

	return gdl;
}

#if VERSION >= VERSION_JPN_FINAL
void titleInitNoExpansion(void)
{
	g_TitleTimer = 0;
}
#endif

#if VERSION >= VERSION_JPN_FINAL
void titleExitNoExpansion(void)
{
	// empty
}
#endif

#if VERSION >= VERSION_JPN_FINAL
void titleTickNoExpansion(void)
{
	viSetFovY(60);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	viSetUseZBuf(0);

	g_TitleTimer += g_Vars.lvupdate240_60;
}
#endif

#if VERSION >= VERSION_JPN_FINAL
Gfx *titleRenderNoExpansion(Gfx *gdl)
{
	s32 textheight;
	s32 textwidth;
	s32 x;
	s32 y;
	char *text;
	u32 stack[2];
	s16 tmp;
	s16 width;

	if (1);
	if (1);
	if (1);

	joyGetConnectedControllers();

	gdl = titleClear(gdl);
	gdl = func0f153628(gdl);

	x = 50;
	y = g_TitleViewHeight / 2 - 36;

	var8007fad0 = 2;
	var80080108jf = 2;

	text = langGet(L_MPWEAPONS_281);
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);
	x = 288 - textwidth;
	width = viGetWidth();
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, viGetHeight(), 0, 0);
	y += 18;

	text = langGet(L_MPWEAPONS_282);
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);
	x = 288 - textwidth;
	width = viGetWidth();
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, viGetHeight(), 0, 0);
	y += 18;

	text = langGet(L_MPWEAPONS_284);
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);
	x = 288 - textwidth;
	width = viGetWidth();
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, viGetHeight(), 0, 0);
	y += 18;

	var8007fad0 = 1;
	var80080108jf = 1;

	gdl = func0f153780(gdl);

	return gdl;
}
#endif

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
#if VERSION >= VERSION_JPN_FINAL
		case TITLEMODE_NOEXPANSION:
			titleExitNoExpansion();
			break;
#endif
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
#if VERSION >= VERSION_JPN_FINAL
		case TITLEMODE_NOEXPANSION:
			titleInitNoExpansion();
			break;
#endif
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
#if VERSION >= VERSION_JPN_FINAL
	case TITLEMODE_NOEXPANSION:
		titleTickNoExpansion();
		break;
#endif
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
#if VERSION >= VERSION_JPN_FINAL
	case TITLEMODE_NOEXPANSION:
		titleExitNoExpansion();
		break;
#endif
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
#if VERSION >= VERSION_JPN_FINAL
		case TITLEMODE_NOEXPANSION:
			gdl = titleRenderNoExpansion(gdl);
			break;
#endif
		}
	}

	return gdl;
}
