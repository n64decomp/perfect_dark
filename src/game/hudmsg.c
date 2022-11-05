#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/propsnd.h"
#include "game/game_0b0fd0.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/hudmsg.h"
#include "game/menugfx.h"
#include "game/playermgr.h"
#include "game/game_1531a0.h"
#include "game/lv.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/snd.h"
#include "lib/str.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"
#include "string.h"

u32 g_NextHudMessageId;

u8 g_HudmsgsActive = 0;

u32 g_HudmsgColours[] = {
	/* 0*/ 0x00ff0000, // green
	/* 1*/ 0x9999ff00, // pastel blue
	/* 2*/ 0xffffff00, // white
	/* 3*/ 0xff777700, // pastel red
	/* 4*/ 0xffff5500, // yellow
	/* 5*/ 0x00ff0000, // green
	/* 6*/ 0xcccccc00, // gray
	/* 7*/ 0xff888800, // pastel red
	/* 8*/ 0xffaa5500, // orange
	/* 9*/ 0x55aaff00, // sky blue
	/*10*/ 0xaa55ff00, // purple
};

s32 g_HudPaddingY = 10;
s32 g_HudPaddingX = 24;
s32 g_NumHudMessages = 0;
struct hudmessage *g_HudMessages = NULL;

#if VERSION < VERSION_NTSC_1_0
struct sndstate *var800736b0nb = NULL;
#endif

struct hudmsgtype g_HudmsgTypes[] = {
	/* 0*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 80  },
	/* 1*/ { 0, 1, 0, &g_CharsHandelGothicMd, &g_FontHandelGothicMd, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_YMIDDLE,       0, 0, 120 },
#if VERSION == VERSION_JPN_FINAL
	/* 2*/ { 0, 0, 1, &g_CharsHandelGothicMd, &g_FontHandelGothicMd, 0xff999900, 0xffffffa0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_YMIDDLE,       0, 0, 120 },
#else
	/* 2*/ { 0, 0, 1, &g_CharsHandelGothicMd, &g_FontHandelGothicMd, 0xff000000, 0xffffffa0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_YMIDDLE,       0, 0, 120 },
#endif
	/* 3*/ { 0, 1, 0, &g_CharsHandelGothicMd, &g_FontHandelGothicMd, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 120 },
	/* 4*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ffc000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 40  },
	/* 5*/ { 0, 0, 0, &g_CharsHandelGothicMd, &g_FontHandelGothicMd, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_TOP,           0, 0, 120 },
	/* 6*/ { 1, 0, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_TOP,           0, 0, 120 },
	/* 7*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_TOP,           0, 0, -1  },
	/* 8*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ffc000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_BOTTOM,        0, 0, 500 },
#if VERSION == VERSION_JPN_FINAL
	/* 9*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 120 },
#else
	/* 9*/ { 1, 1, 0, &g_CharsHandelGothicXs, &g_FontHandelGothicXs, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 120 },
#endif
	/*10*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 240 },
#if VERSION >= VERSION_NTSC_1_0
	/*11*/ { 0, 0, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_BELOWVIEWPORT, 0, 0, 120 },
#else
	/*11*/ { 1, 0, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_BELOWVIEWPORT, 0, 0, 120 },
#endif
};

u8 hudmsgsAreActive(void)
{
	return g_HudmsgsActive;
}

s32 hudmsgIsZoomRangeVisible(void)
{
	return optionsGetShowZoomRange(g_Vars.currentplayerstats->mpindex)
		&& PLAYERCOUNT() == 1
		&& currentPlayerGetSight() == SIGHT_ZOOM
		&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON;
}

/**
 * hudmsgRenderMissionTimer calls viGetWidth (which returns an s16), then stores
 * the width in sp42 while it calls viGetHeight. However, when we do this it
 * stores the width to sp40 instead.
 *
 * Changing the definition of viGetHeight to return an s32 fixes this, but is
 * surely wrong and creates mismatches elsewhere. So we declare a new function
 * with the return type we need, and link it to the same address as viGetHeight
 * via the linker config.
 */
extern s32 viGetHeight_hack(void);

Gfx *hudmsgRenderMissionTimer(Gfx *gdl, u32 alpha)
{
	s32 x;
	s32 y;
	s32 viewleft;
	s32 timery;
	char buffer[24];
	u32 textcolour;
	s32 is4mb;
	s32 playercount;
	s32 playernum;
	s16 viewtop;
	s16 viewheight;

	textcolour = alpha;

	viewleft = viGetViewLeft() / g_ScaleX;
	viewtop = viGetViewTop();
	viewheight = viGetViewHeight();
	playercount = PLAYERCOUNT();
	playernum = g_Vars.currentplayernum;

	timery = viewheight;
	timery += viewtop;
	timery -= g_HudPaddingY;
	timery -= 8;

	is4mb = IS4MB();

	// @bug: There is no check for playercount >= 2 in the next two statements.
	// Because of this, in 1 player the timer is drawn out of place when the
	// screen split option is vertical and either the countdown timer is visible
	// or a zoomable weapon is in use.
	if ((is4mb || optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) && countdownTimerIsVisible()) {
		timery -= 8;
	}

	if ((IS4MB() || optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || playercount >= 3) && hudmsgIsZoomRangeVisible()) {
		timery -= 8;
	}

	if (playercount == 2) {
		if (IS4MB() || (optionsGetScreenSplit() != SCREENSPLIT_VERTICAL && playernum == 0)) {
			timery += 10;
		} else {
			timery += 2;
		}
	} else if (playercount >= 3) {
		if (playernum < 2) {
			timery += 10;
		} else {
			timery += 2;
		}
	} else {
		if (optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
			timery += 8;
		}
	}

	// If this is a second player with their viewport on the right side of the
	// screen, move the timer left a bit as the safe zone doesn't need to be
	// considered.
	if (playercount == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()) && playernum == 1) {
		viewleft -= 14;
	} else if (playercount >= 3 && (playernum & 1) == 1) {
		viewleft -= 14;
	}

	textcolour = textcolour * 160 / 255;
	if (g_Is4Mb);
	textcolour |= 0x00ff0000;

	formatTime(buffer, playerGetMissionTime(), TIMEPRECISION_HUNDREDTHS);

	x = viewleft + g_HudPaddingX + 3;
	y = timery;

	gdl = textRender(gdl, &x, &y, buffer, g_CharsNumeric, g_FontNumeric, textcolour, 0x000000a0, viGetWidth(), viGetHeight_hack(), 0, 0);

	return gdl;
}

Gfx *hudmsgRenderZoomRange(Gfx *gdl, u32 alpha)
{
	s32 viewtop;
	s32 viewleft;
	s32 viewhalfwidth;
	s32 viewheight;
	f32 zoominfovy;
	f32 zoomfov;
	s32 playercount;
	f32 curzoom;
	f32 maxzoom;
	char text[24];
	s32 weaponnum;
	s32 texty;
	s32 x;
	s32 y;
	s32 textwidth;
	s32 textheight;
	s32 x2;
	s32 y2;
	u32 colour;

	colour = (alpha * 0xa0 / 255) | 0x00ff0000;
	viewtop = viGetViewTop();
	viewleft = viGetViewLeft() / g_ScaleX;
	viewhalfwidth = (viGetViewWidth() / g_ScaleX) >> 1;
	viewheight = viGetViewHeight();
	texty = viewheight + viewtop - 1;
	maxzoom = 1.0f;
	weaponnum = g_Vars.currentplayer->hands[0].gset.weaponnum;
	playercount = PLAYERCOUNT();

	texty -= 17;

	if (countdownTimerIsVisible()) {
		texty -= 8;
	}

	if (playercount == 2) {
		if (IS4MB() || (optionsGetScreenSplit() != SCREENSPLIT_VERTICAL && g_Vars.currentplayernum == 0)) {
			texty += 10;
		} else {
			texty += 2;
		}
	} else if (playercount >= 3) {
		if (g_Vars.currentplayernum < 2) {
			texty += 10;
		} else {
			texty += 2;
		}
	} else if (optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
		texty += 8;
	}

	// Left side - current zoom level
	zoomfov = currentPlayerGetGunZoomFov();
	zoominfovy = g_Vars.currentplayer->zoominfovy;

	if (zoomfov == 0.0f || zoomfov == 60.0f) {
		if (weaponnum == WEAPON_SNIPERRIFLE) {
			curzoom = 1.0f;
		} else {
			return gdl;
		}
	} else {
		maxzoom = 60.0f / zoomfov;
		curzoom = maxzoom - 1.0f / (zoomfov / zoominfovy) + 1;
	}

	sprintf(text, "%s%s%4.2fX", "", "", curzoom);
	textMeasure(&textheight, &textwidth, text, g_CharsNumeric, g_FontNumeric, 0);

	x = viewleft + viewhalfwidth - textwidth - 5;
	y = texty;
	x2 = x + textwidth;
	y2 = y + textheight;

	gdl = text0f1538e4(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, colour, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);

	// Divider
	sprintf(text, "/");
	textMeasure(&textheight, &textwidth, text, g_CharsNumeric, g_FontNumeric, 0);

	x = viewleft + viewhalfwidth - (textwidth >> 1);
	y = texty;
	x2 = x + textwidth;
	y2 = y + textheight;

	gdl = text0f1538e4(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, colour, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);

	// Right side - max zoom level
	sprintf(text, "%s%s%4.2fX", "", "", maxzoom);
	textMeasure(&textheight, &textwidth, text, g_CharsNumeric, g_FontNumeric, 0);

	x = viewleft + viewhalfwidth + 5;
	y = texty;
	x2 = x + textwidth;
	y2 = y + textheight;

	gdl = text0f1538e4(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, colour, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);

	return gdl;
}

Gfx *hudmsgRenderBox(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, f32 bgopacity, u32 bordercolour, f32 textopacity)
{
	f32 f0;
	f32 f20;
	f32 f22;

	if (x1);

	g_HudmsgsActive = true;

	f0 = sinf(90 * bgopacity * M_PI / 180.0f);
	f22 = (x2 - x1) * 0.5f;
	f20 = (y2 - y1) * 0.5f;

	if (f0 < 0.5f) {
		f20 = 0.0f;
		f22 *= f0 + f0;
	} else {
		f20 *= (f0 - 0.5f) + (f0 - 0.5f);
	}

	gdl = func0f0d479c(gdl);

	gdl = menugfxDrawFilledRect(gdl, x1, y1, x2, y1 + 1, bordercolour, bordercolour);
	gdl = menugfxDrawFilledRect(gdl, x1, y2, x2, y2 + 1, bordercolour, bordercolour);
	gdl = menugfxDrawFilledRect(gdl, x1, y1 + 1, x1 + 1, y2, bordercolour, bordercolour);
	gdl = menugfxDrawFilledRect(gdl, x2, y1, x2 + 1, y2 + 1, bordercolour, bordercolour);

	gdl = func0f0d49c8(gdl);

	if (textopacity > 0.0f) {
		f32 width = (x1 + x2) * 0.5f;
		f32 height = (y1 + y2) * 0.5f;

		gdl = text0f153a34(gdl,
				(s32)((width - f22) + 1.0f) * g_ScaleX,
				(height - f20) + 1.0f,
				(s32)(width + f22) * g_ScaleX,
				height + f20,
				128.0f * textopacity);
	}

	return gdl;
}

s32 hudmsg0f0ddb1c(s32 *arg0, s32 arg1)
{
#if VERSION >= VERSION_PAL_FINAL
	s32 viewwidth = viGetViewWidth() / g_ScaleX;
	s32 result = 0;

	*arg0 = 24;

	if (PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
		result -= *arg0 * 2 / 3;

		if (g_Vars.currentplayernum == 0) {
			*arg0 /= 3;
		} else {
			*arg0 /= 6;
		}
	}

	result = result + viewwidth - *arg0 - arg1 - 11;

	if (PLAYERCOUNT() == 1) {
		result -= 16;

#if VERSION < VERSION_JPN_FINAL
		if (g_ViRes == VIRES_HI) {
			result -= 16;
		}
#endif
	}
#else
	s32 viewwidth = g_Vars.currentplayer->viewwidth / g_ScaleX;
	s32 result = 0;

	*arg0 = 24;

	if (PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
		result -= *arg0 * 2 / 3;

		if (g_Vars.currentplayernum == 0) {
			*arg0 /= 3;
		} else {
			*arg0 /= 6;
		}
	}

	result = result + viewwidth - *arg0 - arg1 - 11;

	if (PLAYERCOUNT() == 1) {
		result -= 16;
	}
#endif

	return result;
}

void hudmsgsHideByChannel(s32 channelnum)
{
	s32 i;

	for (i = 0; i < g_NumHudMessages; i++) {
		if (g_HudMessages[i].state != HUDMSGSTATE_FREE && g_HudMessages[i].channelnum == channelnum) {
			g_HudMessages[i].flags |= HUDMSGFLAG_FORCEOFF;
			break;
		}
	}
}

void hudmsgsReset(void)
{
	s32 i;

	g_NumHudMessages = g_Vars.mplayerisrunning ? 20 : 8;
	g_HudMessages = mempAlloc(ALIGN64(sizeof(struct hudmessage) * g_NumHudMessages), MEMPOOL_STAGE);

	for (i = 0; i < g_NumHudMessages; i++) {
		g_HudMessages[i].state = HUDMSGSTATE_FREE;
	}

	g_NextHudMessageId = 0;

#if VERSION < VERSION_NTSC_1_0
	var800736b0nb = NULL;
#endif
}

void hudmsgRemoveAll(void)
{
	s32 i;

	for (i = 0; i < g_NumHudMessages; i++) {
		g_HudMessages[i].state = HUDMSGSTATE_FREE;
	}
}

s32 hudmsgGetNext(s32 refid)
{
	s32 bestid = -1;
	s32 bestindex = -1;
	s32 i;

	// Finding the smallest ID that is greater than refid
	for (i = 0; i < g_NumHudMessages; i++) {
		if (g_HudMessages[i].state && g_HudMessages[i].id > refid) {
			if (bestid < 0 || g_HudMessages[i].id < bestid) {
				bestindex = i;
				bestid = g_HudMessages[i].id;
			}
		}
	}

	return bestindex;
}

void hudmsgCreate(char *text, s32 type)
{
	hudmsgCreateFromArgs(text, type,
			g_HudmsgTypes[type].unk00,
			g_HudmsgTypes[type].unk01,
			g_HudmsgTypes[type].unk02,
			g_HudmsgTypes[type].unk04,
			g_HudmsgTypes[type].unk08,
			g_HudmsgTypes[type].colour,
			g_HudmsgTypes[type].unk10,
			g_HudmsgTypes[type].alignh,
			g_HudmsgTypes[type].unk16,
			g_HudmsgTypes[type].alignv,
			g_HudmsgTypes[type].unk18,
			-1, 0);
}

void hudmsgCreateWithFlags(char *text, s32 type, u32 flags)
{
	hudmsgCreateFromArgs(text, type,
			g_HudmsgTypes[type].unk00,
			g_HudmsgTypes[type].unk01,
			g_HudmsgTypes[type].unk02,
			g_HudmsgTypes[type].unk04,
			g_HudmsgTypes[type].unk08,
			g_HudmsgTypes[type].colour,
			g_HudmsgTypes[type].unk10,
			g_HudmsgTypes[type].alignh,
			g_HudmsgTypes[type].unk16,
			g_HudmsgTypes[type].alignv,
			g_HudmsgTypes[type].unk18,
			-1, flags);
}

void hudmsgCreateWithColour(char *text, s32 type, u8 colournum)
{
	g_HudmsgTypes[type].colour = g_HudmsgColours[colournum];

	hudmsgCreateFromArgs(text, type,
			g_HudmsgTypes[type].unk00,
			g_HudmsgTypes[type].unk01,
			g_HudmsgTypes[type].unk02,
			g_HudmsgTypes[type].unk04,
			g_HudmsgTypes[type].unk08,
			g_HudmsgTypes[type].colour,
			g_HudmsgTypes[type].unk10,
			g_HudmsgTypes[type].alignh,
			g_HudmsgTypes[type].unk16,
			g_HudmsgTypes[type].alignv,
			g_HudmsgTypes[type].unk18,
			-1, 0);
}

void hudmsgCreateWithDuration(char *text, s32 type, struct hudmsgtype *config, s32 duration60)
{
	hudmsgCreateFromArgs(text, type,
			config->unk00,
			config->unk01,
			config->unk02,
			config->unk04,
			config->unk08,
			config->colour,
			config->unk10,
			config->alignh,
			config->unk16,
			config->alignv,
			config->unk18,
			duration60, HUDMSGFLAG_NOCHANNEL);
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel hudmsgCreateAsSubtitle
/*  f0df2b4:	27bdfe38 */ 	addiu	$sp,$sp,-456
/*  f0df2b8:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f0df2bc:	00809825 */ 	move	$s3,$a0
/*  f0df2c0:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f0df2c4:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f0df2c8:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f0df2cc:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f0df2d0:	00e09025 */ 	move	$s2,$a3
/*  f0df2d4:	30d400ff */ 	andi	$s4,$a2,0xff
/*  f0df2d8:	00a0b025 */ 	move	$s6,$a1
/*  f0df2dc:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f0df2e0:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f0df2e4:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f0df2e8:	f7b40048 */ 	sdc1	$f20,0x48($sp)
/*  f0df2ec:	afa601d0 */ 	sw	$a2,0x1d0($sp)
/*  f0df2f0:	0fc257fe */ 	jal	propsndGetDuration60
/*  f0df2f4:	00e02025 */ 	move	$a0,$a3
/*  f0df2f8:	24100006 */ 	li	$s0,0x6
/*  f0df2fc:	16d0000e */ 	bne	$s6,$s0,.JF0f0df338
/*  f0df300:	00408825 */ 	move	$s1,$v0
/*  f0df304:	3c0e800a */ 	lui	$t6,0x800a
/*  f0df308:	8dcea8dc */ 	lw	$t6,-0x5724($t6)
/*  f0df30c:	160e0007 */ 	bne	$s0,$t6,.JF0f0df32c
/*  f0df310:	00000000 */ 	nop
/*  f0df314:	0fc547ce */ 	jal	optionsGetCutsceneSubtitles
/*  f0df318:	00000000 */ 	nop
/*  f0df31c:	5040006b */ 	beqzl	$v0,.JF0f0df4cc
/*  f0df320:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f0df324:	10000004 */ 	b	.JF0f0df338
/*  f0df328:	2416000b */ 	li	$s6,0xb
.JF0f0df32c:
/*  f0df32c:	0fc547cb */ 	jal	optionsGetInGameSubtitles
/*  f0df330:	00000000 */ 	nop
/*  f0df334:	10400064 */ 	beqz	$v0,.JF0f0df4c8
.JF0f0df338:
/*  f0df338:	0014c880 */ 	sll	$t9,$s4,0x2
/*  f0df33c:	3c098007 */ 	lui	$t1,0x8007
/*  f0df340:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0df344:	8d291504 */ 	lw	$t1,0x1504($t1)
/*  f0df348:	3c188007 */ 	lui	$t8,0x8007
/*  f0df34c:	27181540 */ 	addiu	$t8,$t8,0x1540
/*  f0df350:	00167940 */ 	sll	$t7,$s6,0x5
/*  f0df354:	01f8a821 */ 	addu	$s5,$t7,$t8
/*  f0df358:	3c0a800a */ 	lui	$t2,0x800a
/*  f0df35c:	aea9000c */ 	sw	$t1,0xc($s5)
/*  f0df360:	8d4aa8dc */ 	lw	$t2,-0x5724($t2)
/*  f0df364:	560a0040 */ 	bnel	$s0,$t2,.JF0f0df468
/*  f0df368:	92b80002 */ 	lbu	$t8,0x2($s5)
/*  f0df36c:	0622003e */ 	bltzl	$s1,.JF0f0df468
/*  f0df370:	92b80002 */ 	lbu	$t8,0x2($s5)
/*  f0df374:	0c012847 */ 	jal	strlen
/*  f0df378:	02602025 */ 	move	$a0,$s3
/*  f0df37c:	304bffff */ 	andi	$t3,$v0,0xffff
/*  f0df380:	448b4000 */ 	mtc1	$t3,$f8
/*  f0df384:	44912000 */ 	mtc1	$s1,$f4
/*  f0df388:	00009025 */ 	move	$s2,$zero
/*  f0df38c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0df390:	05610005 */ 	bgez	$t3,.JF0f0df3a8
/*  f0df394:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0df398:	3c014f80 */ 	lui	$at,0x4f80
/*  f0df39c:	44818000 */ 	mtc1	$at,$f16
/*  f0df3a0:	00000000 */ 	nop
/*  f0df3a4:	46105280 */ 	add.s	$f10,$f10,$f16
.JF0f0df3a8:
/*  f0df3a8:	02608025 */ 	move	$s0,$s3
/*  f0df3ac:	460a3503 */ 	div.s	$f20,$f6,$f10
/*  f0df3b0:	24130050 */ 	li	$s3,0x50
/*  f0df3b4:	24140070 */ 	li	$s4,0x70
/*  f0df3b8:	27b10088 */ 	addiu	$s1,$sp,0x88
/*  f0df3bc:	00004025 */ 	move	$t0,$zero
.JF0f0df3c0:
/*  f0df3c0:	00002025 */ 	move	$a0,$zero
/*  f0df3c4:	92030000 */ 	lbu	$v1,0x0($s0)
.JF0f0df3c8:
/*  f0df3c8:	14600004 */ 	bnez	$v1,.JF0f0df3dc
/*  f0df3cc:	00601025 */ 	move	$v0,$v1
/*  f0df3d0:	24120001 */ 	li	$s2,0x1
/*  f0df3d4:	1000000b */ 	b	.JF0f0df404
/*  f0df3d8:	24040001 */ 	li	$a0,0x1
.JF0f0df3dc:
/*  f0df3dc:	12620003 */ 	beq	$s3,$v0,.JF0f0df3ec
/*  f0df3e0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0df3e4:	16820003 */ 	bne	$s4,$v0,.JF0f0df3f4
/*  f0df3e8:	02286021 */ 	addu	$t4,$s1,$t0
.JF0f0df3ec:
/*  f0df3ec:	10000005 */ 	b	.JF0f0df404
/*  f0df3f0:	24040001 */ 	li	$a0,0x1
.JF0f0df3f4:
/*  f0df3f4:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f0df3f8:	310d00ff */ 	andi	$t5,$t0,0xff
/*  f0df3fc:	a1830000 */ 	sb	$v1,0x0($t4)
/*  f0df400:	01a04025 */ 	move	$t0,$t5
.JF0f0df404:
/*  f0df404:	5080fff0 */ 	beqzl	$a0,.JF0f0df3c8
/*  f0df408:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f0df40c:	02287021 */ 	addu	$t6,$s1,$t0
/*  f0df410:	11000010 */ 	beqz	$t0,.JF0f0df454
/*  f0df414:	a1c00000 */ 	sb	$zero,0x0($t6)
/*  f0df418:	44889000 */ 	mtc1	$t0,$f18
/*  f0df41c:	02202025 */ 	move	$a0,$s1
/*  f0df420:	02c02825 */ 	move	$a1,$s6
/*  f0df424:	02a03025 */ 	move	$a2,$s5
/*  f0df428:	05010005 */ 	bgez	$t0,.JF0f0df440
/*  f0df42c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0df430:	3c014f80 */ 	lui	$at,0x4f80
/*  f0df434:	44814000 */ 	mtc1	$at,$f8
/*  f0df438:	00000000 */ 	nop
/*  f0df43c:	46082100 */ 	add.s	$f4,$f4,$f8
.JF0f0df440:
/*  f0df440:	46142402 */ 	mul.s	$f16,$f4,$f20
/*  f0df444:	4600818d */ 	trunc.w.s	$f6,$f16
/*  f0df448:	44073000 */ 	mfc1	$a3,$f6
/*  f0df44c:	0fc37c8a */ 	jal	hudmsgCreateWithDuration
/*  f0df450:	00000000 */ 	nop
.JF0f0df454:
/*  f0df454:	5240ffda */ 	beqzl	$s2,.JF0f0df3c0
/*  f0df458:	00004025 */ 	move	$t0,$zero
/*  f0df45c:	1000001b */ 	b	.JF0f0df4cc
/*  f0df460:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f0df464:	92b80002 */ 	lbu	$t8,0x2($s5)
.JF0f0df468:
/*  f0df468:	92a60000 */ 	lbu	$a2,0x0($s5)
/*  f0df46c:	92a70001 */ 	lbu	$a3,0x1($s5)
/*  f0df470:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0df474:	8eb90004 */ 	lw	$t9,0x4($s5)
/*  f0df478:	02602025 */ 	move	$a0,$s3
/*  f0df47c:	02c02825 */ 	move	$a1,$s6
/*  f0df480:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0df484:	8ea90008 */ 	lw	$t1,0x8($s5)
/*  f0df488:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0df48c:	8eaa000c */ 	lw	$t2,0xc($s5)
/*  f0df490:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0df494:	8eab0010 */ 	lw	$t3,0x10($s5)
/*  f0df498:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0df49c:	92ac0014 */ 	lbu	$t4,0x14($s5)
/*  f0df4a0:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f0df4a4:	86ad0016 */ 	lh	$t5,0x16($s5)
/*  f0df4a8:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f0df4ac:	92ae0015 */ 	lbu	$t6,0x15($s5)
/*  f0df4b0:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f0df4b4:	86af0018 */ 	lh	$t7,0x18($s5)
/*  f0df4b8:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f0df4bc:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f0df4c0:	0fc37f11 */ 	jal	hudmsgCreateFromArgs
/*  f0df4c4:	afaf0030 */ 	sw	$t7,0x30($sp)
.JF0f0df4c8:
/*  f0df4c8:	8fbf006c */ 	lw	$ra,0x6c($sp)
.JF0f0df4cc:
/*  f0df4cc:	d7b40048 */ 	ldc1	$f20,0x48($sp)
/*  f0df4d0:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f0df4d4:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f0df4d8:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f0df4dc:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f0df4e0:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f0df4e4:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f0df4e8:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f0df4ec:	03e00008 */ 	jr	$ra
/*  f0df4f0:	27bd01c8 */ 	addiu	$sp,$sp,0x1c8
);
#else
/**
 * Create a hudmsg that is tied to the given audio channel. When the audio
 * finishes the hudmsg is removed.
 *
 * This function is used for both in-game subtitles and cutscene subtitles.
 * If a cutscene is in progress, the function forces the type to cutscene.
 * This allows the caller to specify the type as in-game unconditionally
 * and it will do the right thing.
 *
 * For cutscene subtitles, a dynamic width is used which means the source text
 * has to be re-wrapped. There is also a limit of two lines at a time.
 *
 * The source text is split into individual messages. These splits are
 * usually at the end of each sentence, but they also occur after commas and
 * semi-colons.
 *
 * Each message is wrapped and appended to an accumulator. Every time the
 * accumulator would exceed two lines, the accumulator is queued as a hudmsg
 * and then cleared prior to appending the new message.
 *
 * Each hudmsg is assigned a duration according to its character length relative
 * to the entire string and the audio duration.
 */
void hudmsgCreateAsSubtitle(char *srctext, s32 type, u8 colourindex, s32 audiochannelnum)
{
	s32 audioduration60;
	struct hudmsgtype *config;

	audioduration60 = propsndGetDuration60(audiochannelnum);

	if (type == HUDMSGTYPE_INGAMESUBTITLE) {
		if (!optionsGetInGameSubtitles()) {
			return;
		}
	}

	config = &g_HudmsgTypes[type];
	config->colour = g_HudmsgColours[colourindex];

	hudmsgCreateFromArgs(srctext, type, config->unk00, config->unk01, config->unk02,
			config->unk04, config->unk08, config->colour, config->unk10, config->alignh,
			config->unk16, config->alignv, config->unk18, audiochannelnum, 0);
}
#endif

void hudmsgCreateFromArgsWithoutFlags(char *text, s32 type, s32 conf00, s32 conf01, s32 conf02, struct fontchar **conf04, struct font **conf08, u32 textcolour, u32 shadowcolour, u32 alignh, s32 conf16, u32 alignv, s32 conf18, s32 arg14)
{
	hudmsgCreateFromArgs(text, type,
			conf00,
			conf01,
			conf02,
			conf04,
			conf08,
			textcolour,
			shadowcolour,
			alignh,
			conf16,
			alignv,
			conf18,
			arg14, 0);
}

void hudmsgCalculatePosition(struct hudmessage *msg)
{
	s32 x;
	s32 y;
	s32 viewleft = g_Vars.players[msg->playernum]->viewleft / g_ScaleX;
	s32 viewtop = g_Vars.players[msg->playernum]->viewtop;
	s32 viewwidth = g_Vars.players[msg->playernum]->viewwidth / g_ScaleX;
	s32 viewheight = g_Vars.players[msg->playernum]->viewheight;
	s32 v0;

#if VERSION >= VERSION_NTSC_1_0
	s32 offset = (msg->alignh == HUDMSGALIGN_XMIDDLE) ? 10 : 0;

	if (PLAYERCOUNT() >= 3) {
		viewwidth -= offset;

		if (g_Vars.currentplayernum == 0 || g_Vars.currentplayernum == 2) {
			viewleft += offset;
		}
	}

	if (PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB())) {
		viewwidth -= offset;

		if (g_Vars.currentplayernum == 0) {
			viewleft += offset;
		}
	}
#endif

	switch (msg->alignh) {
	case HUDMSGALIGN_SCREENLEFT:
		x = msg->xmargin;
		break;
	case HUDMSGALIGN_LEFT:
		v0 = msg->xmarginextra;

		x = viewleft + v0 + msg->xmargin + 3;

		if (PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB())) {
			if (IS4MB()) {
				if (msg->playernum == 0) {
					x--;
				} else if (msg->playernum == 1) {
					x -= 16;
				}
			} else {
				if (msg->playernum == 0) {
					x += 15;
				} else if (msg->playernum == 1) {
					x += 4;
				}
			}
		} else if (PLAYERCOUNT() >= 3) {
			if ((msg->playernum % 2) == 0) {
				x--;
			} else {
				x -= 16;
			}
		}
		break;
	case HUDMSGALIGN_RIGHT:
		x = viewleft + viewwidth - msg->width - msg->xmargin - 57;
		break;
	case HUDMSGALIGN_XMIDDLE:
		x = (viewwidth - msg->width) / 2 + viewleft + msg->xmargin;
		break;
	default:
		x = msg->xmargin;
		break;
	}

	switch (msg->alignv) {
	case HUDMSGALIGN_SCREENTOP:
		y = msg->ymargin;
		break;
	case HUDMSGALIGN_TOP:
		y = viewtop + msg->ymargin + 13;
		break;
	case HUDMSGALIGN_BOTTOM:
		y = viewtop + viewheight - msg->height - msg->ymargin - 14;

		if (PLAYERCOUNT() == 2) {
			if (IS4MB() || (optionsGetScreenSplit() != SCREENSPLIT_VERTICAL && msg->playernum == 0)) {
				y += 8;
			} else {
				y += 3;
			}
		} else if (PLAYERCOUNT() >= 3) {
			if (msg->playernum <= 1) {
				y += 8;
			} else {
				y += 3;
			}
		} else {
			if (optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
				y += 8;
			}
		}
		break;
	case HUDMSGALIGN_YMIDDLE:
		y = (viewheight - msg->height) / 2 + viewtop + msg->ymargin;
		break;
	case HUDMSGALIGN_BELOWVIEWPORT:
		y = viewtop + viewheight - (msg->height / 2) + 18;
		break;
	default:
		y = msg->ymargin;
		break;
	}

	msg->x = x;
	msg->y = y;
}

void hudmsgCreateFromArgs(char *text, s32 type, s32 conf00, s32 conf01, s32 conf02,
		struct fontchar **conf04, struct font **conf08,
		u32 textcolour, u32 glowcolour,
		u32 alignh, s32 conf16, u32 alignv, s32 conf18, s32 arg14, u32 flags)
{
	s32 j;
	struct hudmessage *msg;
	s32 hash = 0;
	s32 i;
	s32 index;
	s32 textwidth;
	s32 textheight;
	s32 xmarginaextra;
	s32 wrapwidth;
	char stacktext[400];
	s32 writeindex;

	if (type == HUDMSGTYPE_INGAMESUBTITLE && !optionsGetInGameSubtitles()) {
		return;
	}

	for (j = 0; text[j] != '\0'; j++) {
		hash = hash + text[j];
	}

	if ((flags & HUDMSGFLAG_ONLYIFALIVE) == 0 || !g_Vars.currentplayer->isdead) {
		if ((flags & HUDMSGFLAG_ALLOWDUPES) == 0) {
			// Check for duplicate messages
			s32 dupeofindex = -1;

			for (index = 0; index < g_NumHudMessages; index++) {
				if (g_HudMessages[index].state != HUDMSGSTATE_FREE
						&& g_HudMessages[index].state != HUDMSGSTATE_FADINGOUT
						&& g_HudMessages[index].playernum == g_Vars.currentplayernum
						&& g_HudMessages[index].hash == hash) {
					dupeofindex = index;
				}
			}

			if (dupeofindex >= 0) {
				return;
			}
		}

#if PAL
		g_ScaleX = 1;
#else
		g_ScaleX = g_ViRes == VIRES_HI ? 2 : 1;
#endif

		// Find an unused index for the new message
		for (index = 0; index < g_NumHudMessages; index++) {
			if (g_HudMessages[index].state == HUDMSGSTATE_FREE) {
				break;
			}
		}

		if (index >= g_NumHudMessages
				&& (type == HUDMSGTYPE_OBJECTIVECOMPLETE
					|| type == HUDMSGTYPE_OBJECTIVEFAILED
					|| type == HUDMSGTYPE_INGAMESUBTITLE)) {
			// Out of space - Check if an existing message can be replaced
			index = hudmsgGetNext(-1);

			while (index >= 0) {
				if (g_HudMessages[index].state == HUDMSGSTATE_QUEUED) {
					if (g_HudMessages[index].type == HUDMSGTYPE_DEFAULT
							|| g_HudMessages[index].type == HUDMSGTYPE_3
							|| g_HudMessages[index].type == HUDMSGTYPE_4) {
						// Good to replace this one
						break;
					}
				}

				// Can't replace - try and find another
				index = hudmsgGetNext(g_HudMessages[index].id);
			}
		}

		if (index >= 0 && index < g_NumHudMessages) {
			xmarginaextra = 0;
			msg = &g_HudMessages[index];
			wrapwidth = hudmsg0f0ddb1c(&xmarginaextra, conf16);
			textMeasure(&textheight, &textwidth, text, *conf04, *conf08, 0);

#if VERSION >= VERSION_JPN_FINAL
			if (textwidth > wrapwidth && (flags & HUDMSGFLAG_NOWRAP) == 0)
#else
			if (textwidth > wrapwidth)
#endif
			{
				i = 0;
				writeindex = 0;

				while (i < 400 && text[i] != '\0') {
					if (text[i] != '\n') {
						stacktext[writeindex++] = text[i];
					}

					i++;
				}

				stacktext[writeindex++] = '\n';
				stacktext[writeindex++] = '\0';

				textWrap(wrapwidth, stacktext, msg->text, *conf04, *conf08);
				textMeasure(&textheight, &textwidth, msg->text, *conf04, *conf08, 0);
			} else {
				strncpy(msg->text, text, 399);
				msg->text[399] = '\0';
			}

			msg->flags = flags;
			msg->playernum = g_Vars.currentplayernum;
			msg->type = type;
			msg->id = g_NextHudMessageId++;
			msg->state = HUDMSGSTATE_QUEUED;
			msg->timer = 0;
			msg->boxed = conf00;
			msg->allowfadein = conf01;
			msg->flash = conf02;
			msg->font1 = *conf04;
			msg->font2 = *conf08;
			msg->textcolour = textcolour;
			msg->glowcolour = glowcolour;
			msg->alignh = alignh;
			msg->alignv = alignv;
			msg->width = textwidth;
			msg->height = textheight;
			msg->xmarginextra = xmarginaextra;
			msg->xmargin = conf16;
			msg->ymargin = conf18;
			msg->hash = hash;

			hudmsgCalculatePosition(msg);

			if (flags & HUDMSGFLAG_NOCHANNEL) {
				msg->showduration = TICKS(arg14);
				msg->channelnum = -1;
			} else {
				msg->showduration = TICKS(g_HudmsgTypes[type].duration);
				msg->channelnum = arg14;
			}
		}

		g_ScaleX = 1;
	}
}

void hudmsgsTick(void)
{
	s32 k;
	s32 previd;
	bool show;
	struct hudmessage *msg;
#if VERSION >= VERSION_NTSC_1_0
	s32 prevplayernum;
#endif
	s32 i;
	s32 j;
#if VERSION >= VERSION_NTSC_1_0
	s32 index;
	bool hide;
#else
	bool hide;
	s32 index;
#endif
	f32 fadeintime;
	f32 fadeouttime;

	g_HudmsgsActive = false;

#if PAL
	g_ScaleX = 1;
#else
	g_ScaleX = (g_ViRes == VIRES_HI) ? 2 : 1;
#endif

#if VERSION >= VERSION_NTSC_1_0
	prevplayernum = g_Vars.currentplayernum;

	for (k = 0; k < g_NumHudMessages; k++) {
		if (g_HudMessages[k].state != HUDMSGSTATE_FREE) {
			setCurrentPlayerNum(g_HudMessages[k].playernum);
			hudmsgCalculatePosition(&g_HudMessages[k]);
		}
	}

	setCurrentPlayerNum(prevplayernum);
#else
	for (k = 0; k < g_NumHudMessages; k++) {
		if (g_HudMessages[k].state != HUDMSGSTATE_FREE) {
			hudmsgCalculatePosition(&g_HudMessages[k]);
		}
	}
#endif

	previd = -1; \
	while (true) {
		index = hudmsgGetNext(previd);

		if (index < 0) {
			break;
		}

		msg = &g_HudMessages[index];
		previd = msg->id;

		if (msg->channelnum >= 0) {
			msg->opacity = propsndGetSubtitleOpacity(msg->channelnum);
		} else {
			msg->opacity = 0xff;
		}

		if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
			msg->state = HUDMSGSTATE_FREE;
			msg->timer = 0;
		}

		switch (msg->state) {
		case HUDMSGSTATE_QUEUED:
#if VERSION >= VERSION_NTSC_1_0
			if (msg->flags & HUDMSGFLAG_DELAY) {
				msg->timer++;

				if (msg->timer > 3) {
					msg->flags &= ~HUDMSGFLAG_DELAY;
				}
			} else
#endif
			{
				show = true;

				if (g_Vars.players[msg->playernum]->isdead) {
					show = false;
				}

				if (show) {
					// Check if any other message is occupying our space
					for (i = 0; i < g_NumHudMessages; i++) {
						if (g_HudMessages[i].state != HUDMSGSTATE_FREE
								&& g_HudMessages[i].state != HUDMSGSTATE_QUEUED
								&& g_HudMessages[i].x + g_HudMessages[i].width >= msg->x
								&& g_HudMessages[i].x <= msg->x + msg->width
								&& g_HudMessages[i].y + g_HudMessages[i].height >= msg->y
								&& g_HudMessages[i].y <= msg->y + msg->height) {
							show = false;

							// Consider booting the previous message out earlier
							if (g_HudMessages[i].type == msg->type
									&& msg->boxed
									&& g_HudMessages[i].boxed
									&& g_HudMessages[i].state == HUDMSGSTATE_FADINGOUT) {
								g_HudMessages[i].state = HUDMSGSTATE_FREE;
								g_HudMessages[i].timer = 0;
								msg->state = HUDMSGSTATE_FADINGIN;
								msg->timer = 0;
							}

							break;
						}
					}
				}

				if (show) {
					if (msg->boxed) {
						msg->state = HUDMSGSTATE_CHOOSETRANSITION;
					} else if (msg->allowfadein) {
						msg->state = HUDMSGSTATE_FADINGIN;
					} else {
						msg->state = HUDMSGSTATE_ONSCREEN;
					}

					msg->timer = 0;

					if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
						msg->state = HUDMSGSTATE_ONSCREEN;
					}
				}
			}
			break;
		case HUDMSGSTATE_CHOOSETRANSITION:
			if (msg->boxed && msg->allowfadein) {
				msg->state = HUDMSGSTATE_FADINGIN;
			} else {
				msg->state = HUDMSGSTATE_ONSCREEN;
			}

			if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
				msg->state = HUDMSGSTATE_ONSCREEN;
			}

			msg->timer = 0;
			break;
		case HUDMSGSTATE_FADINGIN:
			if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
				// Cutscene subtitles appear immediately
				msg->state = HUDMSGSTATE_ONSCREEN;
				msg->timer = 0;
			} else {
				// Most HUD messages play a swish sound effect
				if (msg->timer == 0
						&& !lvIsPaused()
						&& !mpIsPaused()
#if VERSION >= VERSION_NTSC_1_0
						&& msg->type != HUDMSGTYPE_CUTSCENESUBTITLE
						&& msg->type != HUDMSGTYPE_INGAMESUBTITLE
#endif
						&& PLAYERCOUNT() == 1) {
#if VERSION >= VERSION_NTSC_1_0
					sndStart(var80095200, SFX_HUDMSG, NULL, -1, -1, -1, -1, -1);
#else
					sndStart(var80095200, SFX_HUDMSG, &var800736b0nb, -1, -1, -1, -1, -1);
#endif
				}

				fadeintime = (sqrtf(msg->width * msg->width + msg->height * msg->height) + 132) / PALUPF(7.0f);

				msg->timer += g_Vars.lvupdate60;

				if (msg->timer >= (s32)fadeintime || msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
					msg->state = HUDMSGSTATE_ONSCREEN;
					msg->timer = 0;
				}
			}
			break;
		case HUDMSGSTATE_ONSCREEN:
			msg->timer += g_Vars.lvupdate60;

			hide = false;

			// Subtitles have an audio channel number and are hidden when the audio stops
			if (msg->channelnum >= 0) {
				if (audioIsChannelIdle(msg->channelnum)) {
					hide = true;
				} else if (msg->flags & HUDMSGFLAG_FORCEOFF) {
					msg->flags &= ~HUDMSGFLAG_FORCEOFF;
					hide = true;
				}
			} else if (msg->timer >= msg->showduration && msg->showduration != -1) {
				hide = true;
			}

			if (hide) {
				if (msg->boxed) {
					msg->state = HUDMSGSTATE_FADINGOUT;
				} else {
					msg->state = HUDMSGSTATE_FREE;
				}

				msg->timer = 0;
			}
			break;
		case HUDMSGSTATE_FADINGOUT:
			fadeouttime = (sqrtf(msg->width * msg->width + msg->height * msg->height) + 92) / PALUPF(7.0f);

			msg->timer += g_Vars.lvupdate60;

			if (msg->timer >= (s32)fadeouttime) {
				msg->state = HUDMSGSTATE_FREE;
				msg->timer = 0;
			}
			break;
		case HUDMSGSTATE_FREE:
			break;
		}
	}

	g_ScaleX = 1;
}

void hudmsgsSetOn(u32 reason)
{
	g_Vars.currentplayer->hudmessoff &= ~reason;
}

void hudmsgsSetOff(u32 reason)
{
	g_Vars.currentplayer->hudmessoff |= reason;
}

void hudmsgsRemoveForDeadPlayer(s32 playernum)
{
	s32 i;

	for (i = 0; i < g_NumHudMessages; i++) {
		if (g_HudMessages[i].state
				&& g_HudMessages[i].playernum == playernum
				&& (g_HudMessages[i].flags & HUDMSGFLAG_ONLYIFALIVE)) {
			g_HudMessages[i].state = HUDMSGSTATE_FREE;
			g_HudMessages[i].timer = 0;
		}
	}
}

Gfx *hudmsgsRender(Gfx *gdl)
{
	struct hudmessage *msg;
	s32 i;
	u32 textcolour;
	u32 glowcolour;
	f32 sin;
	s32 x;
	s32 y;
	s32 timerthing = 255;
	s32 spdc = true;

#if PAL
	g_ScaleX = 1;
#else
	g_ScaleX = g_ViRes == VIRES_HI ? 2 : 1;
#endif

	gdl = text0f153628(gdl);

	for (i = 0; i < g_NumHudMessages; i++) {
		msg = &g_HudMessages[i];

		if (!msg->opacity) {
			continue;
		}

		if (msg->state == HUDMSGSTATE_FREE
				|| msg->state == HUDMSGSTATE_QUEUED
				|| (spdc && g_Vars.currentplayernum != msg->playernum)) {
			continue;
		}

		if (msg->flash) {
			s32 alpha;
			sin = sinf((msg->timer * M_PI) / 60.0f);

			if (sin < 0.0f) {
				sin = -sin;
			}

			alpha = 192.0f * sin;

			textcolour = (msg->textcolour & 0xffffff00) + alpha;
			glowcolour = msg->glowcolour;
		} else {
			textcolour = msg->textcolour | 0xa0;
			glowcolour = msg->glowcolour;
		}

		if (msg->opacity != 255) {
			u32 textalpha = textcolour & 0xff;
			u32 glowalpha = glowcolour & 0xff;

			textalpha = (msg->opacity * textalpha) / 255;
			glowalpha = (msg->opacity * glowalpha) / 255;

			textcolour = (textcolour & 0xffffff00) + (textalpha & 0xff);
			glowcolour = (glowcolour & 0xffffff00) + (glowalpha & 0xff);
		}

		x = msg->x;
		y = msg->y;

		if (msg->type == HUDMSGTYPE_INGAMESUBTITLE && playerIsHealthVisible()) {
			y += (s32)(16.0f * playerGetHealthBarHeightFrac());
		}

		if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
#if VERSION >= VERSION_NTSC_1_0
			gDPSetScissor(gdl++, 0,
					(x - 4) * g_ScaleX, 0,
					(x + msg->width + 3) * g_ScaleX, viGetBufHeight());
#else
			gDPSetScissor(gdl++, 0,
					(x - 4) * g_ScaleX, y - 4,
					(x + msg->width + 3) * g_ScaleX, y + msg->height + 3);
#endif
		}

		switch (msg->state) {
		case HUDMSGSTATE_FREE:
		case HUDMSGSTATE_QUEUED:
			break;
		case HUDMSGSTATE_FADINGIN:
			{
				u32 bordercolour = msg->textcolour | 0x40;
				f32 tmp;
				f32 spc0;

				if (msg->opacity != 255) {
					u32 alpha = (msg->opacity * (bordercolour & 0xff)) / 255;
					bordercolour = (bordercolour & 0xffffff00) + (alpha & 0xff);
				}

				spc0 = (sqrtf(msg->width * msg->width + msg->height * msg->height) + 132.0f) / PALUPF(7.0f);

				if (spc0 > 30.0f) {
					spc0 = 30.0f;
				}

				spc0 = msg->timer / spc0;

				if (spc0 > 1.0f) {
					spc0 = 1.0f;
				}

				if (spc0 < 0.0f) {
					spc0 = 0.0f;
				}

				tmp = msg->timer * PALUPF(7.0f);

				textSetDiagonalBlend(x, y, tmp, DIAGMODE_FADEIN);

				if (msg->boxed) {
#if VERSION >= VERSION_JPN_FINAL
					gdl = hudmsgRenderBox(gdl, x - 3, y - 3, x + msg->width + 2, y + msg->height - 1, 1.0f, bordercolour, spc0);
#else
					gdl = hudmsgRenderBox(gdl, x - 3, y - 3, x + msg->width + 2, y + msg->height + 2, 1.0f, bordercolour, spc0);
#endif

					gdl = textRenderProjected(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, viGetWidth(), viGetHeight(), 0, 0);
				} else {
					gdl = text0f153a34(gdl, x, y, x + msg->width, y + msg->height, 0);

#if VERSION >= VERSION_JPN_FINAL
					gdl = func0f1574d0jf(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
#else
					gdl = textRender(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
#endif
				}

				if (msg->alignv == 6) {
					timerthing = 0;
				}

				textResetBlends();
			}
			break;
		case HUDMSGSTATE_ONSCREEN:
			if (msg->boxed) {
				u32 bordercolour = msg->textcolour | 0x40;

				if (msg->opacity != 255) {
					u32 alpha = (msg->opacity * (bordercolour & 0xff)) / 255;
					bordercolour = (bordercolour & 0xffffff00) + (alpha & 0xff);
				}

#if VERSION >= VERSION_JPN_FINAL
				gdl = hudmsgRenderBox(gdl, x - 3, y - 3, x + msg->width + 2, y + msg->height - 1, 1.0f, bordercolour, 1.0f);
#else
				gdl = hudmsgRenderBox(gdl, x - 3, y - 3, x + msg->width + 2, y + msg->height + 2, 1.0f, bordercolour, 1.0f);
#endif

				gdl = textRenderProjected(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, viGetWidth(), viGetHeight(), 0, 0);
			} else {
				gdl = text0f153a34(gdl, x, y, x + msg->width, y + msg->height, 0);

#if VERSION >= VERSION_JPN_FINAL
				gdl = func0f1574d0jf(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
#else
				gdl = textRender(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
#endif
			}
			if (msg->alignv == 6) {
				timerthing = 0;
			}
			break;
		case HUDMSGSTATE_FADINGOUT:
			{
				u32 bordercolour;
				u32 stack;
				f32 spa8 = (sqrtf(msg->width * msg->width + msg->height * msg->height) + 92.0f) / PALUPF(7.0f);
				f32 tmp;

				bordercolour = msg->textcolour | 0x40;

				if (msg->opacity != 255) {
					u32 alpha = (msg->opacity * (bordercolour & 0xff)) / 255;
					bordercolour = (bordercolour & 0xffffff00) + (alpha & 0xff);
				}

				tmp = (spa8 - msg->timer) * PALUPF(7.0f);

				textSetDiagonalBlend(x + msg->width, y + msg->height, tmp, DIAGMODE_FADEOUT);

				if (spa8 > 30.0f) {
					spa8 = 30.0f;
				}

				spa8 = msg->timer / spa8;

				if (spa8 > 1.0f) {
					spa8 = 1.0f;
				}

				if (msg->boxed) {
#if VERSION >= VERSION_JPN_FINAL
					gdl = hudmsgRenderBox(gdl, x - 3, y - 3, x + msg->width + 2, y + msg->height - 1, 1.0f, bordercolour, 1.0f - spa8);
#else
					gdl = hudmsgRenderBox(gdl, x - 3, y - 3, x + msg->width + 2, y + msg->height + 2, 1.0f, bordercolour, 1.0f - spa8);
#endif

					gdl = textRenderProjected(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, viGetWidth(), viGetHeight(), 0, 0);
				} else {
					gdl = text0f153a34(gdl, x, y, x + msg->width, y + msg->height, 0);

#if VERSION >= VERSION_JPN_FINAL
					gdl = func0f1574d0jf(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
#else
					gdl = textRender(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
#endif
				}

				if (msg->alignv == 6) {
					timerthing = 0;
				}

				textResetBlends();
			}
			break;
		}

		if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
			gDPSetScissor(gdl++, 0,
					viGetViewLeft(), viGetViewTop(),
					viGetViewLeft() + viGetViewWidth(), viGetViewTop() + viGetViewHeight());
		}
	}

	if (timerthing) {
		if (optionsGetShowMissionTime(g_Vars.currentplayerstats->mpindex)
				&& g_Vars.normmplayerisrunning == false
				&& g_Vars.stagenum != STAGE_CITRAINING
				&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON) {
			gdl = hudmsgRenderMissionTimer(gdl, timerthing);
		}

		if (hudmsgIsZoomRangeVisible()) {
			gdl = hudmsgRenderZoomRange(gdl, timerthing);
		}

		gdl = countdownTimerRender(gdl);
	}

	gdl = text0f153780(gdl);

	g_ScaleX = 1;

	return gdl;
}

void hudmsgsStop(void)
{
	s32 i;

	for (i = 0; i < g_NumHudMessages; i++) {
		g_HudMessages[i].state = HUDMSGSTATE_FREE;
	}

#if VERSION < VERSION_NTSC_1_0
	if (var800736b0nb && sndGetState(var800736b0nb) != AL_STOPPED) {
		audioStop(var800736b0nb);
	}
#endif
}
