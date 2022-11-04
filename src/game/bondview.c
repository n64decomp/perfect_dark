#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/game_006900.h"
#include "game/atan2f.h"
#include "game/savebuffer.h"
#include "game/sky.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/joy.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"
#include "gbiex.h"

#ifdef AVOID_UB
char var800a41c0[26];
#else
char var800a41c0[24];
#endif

#if VERSION < VERSION_NTSC_1_0
u8 var800a8b58nb[0x1c0];
#endif

s32 var8007f840 = 0;
u8 var8007f844 = 0;
u8 var8007f848 = 0;
u32 var8007f854 = 0x00000000;
u32 var8007f858 = 0xb8000000;
u32 var8007f85c = 0x00000000;

Gfx *bview0f141864(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
	s32 value = viGetWidth() * arg2 + arg4;

	gDPPipeSync(gdl++);
	gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 320, value * 2 + arg1);
	gDPLoadSync(gdl++);
	gDPLoadBlock(gdl++, arg3, 0, 0, arg5 - 1, 0);

	return gdl;
}

Gfx *bview0f141940(Gfx *gdl, s32 arg1, s32 arg2, s32 tile, s32 arg4, s32 width)
{
	s32 value = viGetWidth() * arg2 + arg4;

	gDPPipeSync(gdl++);
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, value * 2 + arg1);
	gDPLoadSync(gdl++);
	gDPLoadBlock(gdl++, tile, 0, 0, width - 1, 0);

	return gdl;
}

Gfx *bview0f141a20(Gfx *gdl, s32 top, s32 height, s32 left, s32 width)
{
	gDPPipeSync(gdl++);

	gSPTextureRectangle(gdl++,
			left << 2,
			top << 2,
			(left + width) << 2,
			(top + 1) << 2,
			G_TX_RENDERTILE, 0, 0, height * 1024, 1024);

	return gdl;
}

Gfx *bviewCopyPixels(Gfx *gdl, u16 *fb, s32 top, u32 tile, s32 arg4, f32 arg5, s32 left, s32 width)
{
	u32 image;
	s32 width2;
	s32 numparts;
	s32 lrs[1];

	if (width > 320) {
		numparts = 2;
		lrs[0] = width / numparts;

		image = (u32) &fb[viGetWidth() * top + left] & 0x00ffffff;

		gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, image);
		gDPLoadBlock(gdl++, tile, 0, 0, width / numparts - 1, 0);
		gSPTextureRectangle(gdl++,
				left << 2,
				arg4 << 2,
				((s32) left + width / numparts) << 2,
				(arg4 + 1) << 2,
				G_TX_RENDERTILE,
				(s32) ((width - width / arg5) * 16.0f),
				0,
				(s32) (1024.0f / arg5),
				1024);

		left += lrs[0];

		image = (u32) &fb[viGetWidth() * top + left] & 0x00ffffff;

		gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, image);
		gDPLoadBlock(gdl++, tile, 0, 0, lrs[0] - 1, 0);

		gSPTextureRectangle(gdl++,
				left << 2,
				arg4 << 2,
				(left + lrs[0]) << (0, 2),
				(arg4 + 1) << 2,
				G_TX_RENDERTILE,
				0,
				0,
				(s32) (1024.0f / arg5),
				1024);
	} else {
		width2 = width;

		image = (u32) &fb[viGetWidth() * top + left] & 0x00ffffff;

		gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, image);
		gDPLoadBlock(gdl++, tile, 0, 0, width2 - 1, 0);

		numparts = (s32) (1024.0f / arg5);

		gSPTextureRectangle(gdl++,
				left << 2,
				arg4 << 2,
				(left + width2) << 2,
				(arg4 + 1) << 2,
				G_TX_RENDERTILE,
				(s32) ((width - width / arg5) * 16.0f),
				0,
				numparts,
				1024);
	}

	return gdl;
}

Gfx *bviewDrawFisheyeRect(Gfx *gdl, s32 arg1, f32 arg2, s32 arg3, s32 arg4)
{
	if (arg2 < 1) {
		f32 tmp = arg4 * 0.5f;
		f32 fVar4 = arg3 + tmp;
		f32 fVar7 = (s32)(arg2 * tmp);

		gDPFillRectangle(gdl++, arg3, arg1, fVar4 - fVar7, arg1 + 1);
		gDPFillRectangle(gdl++, fVar4 + fVar7, arg1, arg3 + arg4, arg1 + 1);
	}

	return gdl;
}

Gfx *bviewPrepareStaticRgba16(Gfx *gdl, u32 colour, u32 alpha)
{
	static u32 envcol = 0xffffffff;
	static u32 primcol = 0x7f7f7fff;

	mainOverrideVariable("envcol", &envcol);
	mainOverrideVariable("primcol", &primcol);

	gDPPipeSync(gdl++);
	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 5, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gSPTexture(gdl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, G_TX_RENDERTILE, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x0800, 0x0020);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetColor(gdl++, G_SETENVCOLOR, (colour & 0xffffff00) | (alpha & 0xff));
	gDPSetCombineLERP(gdl++,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetAlphaDither(gdl++, G_AD_NOISE);
	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_NOOP2);

	return gdl;
}

Gfx *bviewPrepareStaticI8(Gfx *gdl, u32 colour, u32 alpha)
{
	static u32 envcol = 0xffffffff;
	static u32 primcol = 0x7f7f7fff;

	mainOverrideVariable("envcol", &envcol);
	mainOverrideVariable("primcol", &primcol);

	gDPPipeSync(gdl++);
	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_8b, 0, 0x0000, 5, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gSPTexture(gdl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 160, 0, G_TX_RENDERTILE, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x0800, 0x0020);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetColor(gdl++, G_SETENVCOLOR, (colour & 0xffffff00) | (alpha & 0xff));
	gDPSetCombineLERP(gdl++,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetAlphaDither(gdl++, G_AD_NOISE);
	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_NOOP2);

	return gdl;
}

Gfx *bviewDrawMotionBlur(Gfx *gdl, u32 colour, u32 alpha)
{
	u16 *fb = viGetFrontBuffer();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	f32 fxxx;
	f32 fyyy;
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	f32 somefloat;
	s32 newalpha;
	s32 i;

	static u32 sfyyy = 1000;
	static u32 sfxxx = 1000;

	if (var8007f848) {
		return gdl;
	}

	var8007f848 = true;

	newalpha = alpha;
	newalpha += var8007f844;

	if (newalpha > 230) {
		newalpha = 230;
	}

	var8007f844 = 0;

	mainOverrideVariable("sfxxx", &sfxxx);
	fxxx = sfxxx / 1000.0f;
	mainOverrideVariable("sfyyy", &sfyyy);
	fyyy = sfyyy / 1000.0f;

	gDPPipeSync(gdl++);

	somefloat = (viewheight - viewheight / fyyy) * 0.5f;
	gdl = bviewPrepareStaticRgba16(gdl, colour, newalpha);

	for (i = viewtop; i < viewtop + viewheight; i++) {
		gdl = bviewCopyPixels(gdl, fb, viewtop + (s32)somefloat, 5, i, fxxx, viewleft, viewwidth);
		somefloat += 1.0f / fyyy;
	}

	return gdl;
}

/**
 * Draw static for the Infiltration intro cutscene and Slayer rockets.
 */
Gfx *bviewDrawStatic(Gfx *gdl, u32 arg1, s32 arg2)
{
	u16 *fb = viGetFrontBuffer();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	u16 *fb2 = (u16 *) PHYS_TO_K0(random() & 0xfff00);
	s32 y;

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticI8(gdl, arg1, arg2);

	for (y = viewtop; y < viewtop + viewheight; y++) {
		gdl = bviewCopyPixels(gdl, fb2, random() % 240, 5, y, 1.0f, viewleft, viewwidth);
	}

	if (fb2) {
		// empty
	}

	return gdl;
}

/**
 * Draw the yellow interlace effect for Slayer rockets.
 */
Gfx *bviewDrawSlayerRocketInterlace(Gfx *gdl, u32 colour, u32 alpha)
{
	u16 *fb = viGetBackBuffer();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 y;
	s32 viewleft = viGetViewLeft();
	f32 angle = 0.52359879016876f;
	s32 offset = (s32)(g_20SecIntervalFrac * 600.0f) % 12;
	f32 increment;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "interlaceGfx");

	gDPPipeSync(gdl++);

	increment = (2.6179938316345f - angle) / viewheight;

	gdl = bviewPrepareStaticRgba16(gdl, colour, alpha);

	for (y = viewtop; y < viewtop + viewheight; y++) {
		s32 offsety = y - offset;

		if ((offsety % 8) == 0 || y == viewtop) {
			if ((offsety % 16) < 8) {
				gDPSetEnvColor(gdl++, 0xff, 0xff, 0x00, 0xff);
			} else {
				gDPSetEnvColor(gdl++, 0xff, 0xff, 0xbf, 0xff);
			}
		}

		gdl = bviewCopyPixels(gdl, fb, y, 5, y, 2.0f - sinf(angle), viewleft, viewwidth);

		angle += increment;
	}

	return gdl;
}

/**
 * Draw the blue film interlace effect for the Infiltration intro cutscene.
 */
Gfx *bviewDrawFilmInterlace(Gfx *gdl, u32 colour, u32 alpha)
{
	u16 *fb = viGetBackBuffer();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 y;
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	s32 offset = (s32)(g_20SecIntervalFrac * 600.0f) % 12;
	u32 stack;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "BlueInterlaceGfx");

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, colour, alpha);

	for (y = viewtop; y < viewtop + viewheight; y++) {
		s32 offsety = y - offset;
		s32 tmpy = y;

		if (offsety % 6 == 0 || y == viewtop) {
			if (offsety % 12 < 6) {
				gDPSetEnvColor(gdl++, 0x7f, 0xff, 0xff, 0xff);
			} else {
				gDPSetEnvColor(gdl++, 0x00, 0xaf, 0xff, 0xff);
			}
		}

		if (random() % 20 == 1) {
			tmpy = random() % 200;
		}

		gdl = bviewCopyPixels(gdl, fb, tmpy, 5, y, 1, viewleft, viewwidth);
	}

	return gdl;
}

/**
 * Draw a zoom in/out motion blur effect.
 *
 * Used when entering/exiting combat boosts and when entering/exiting xray mode.
 */
Gfx *bviewDrawZoomBlur(Gfx *gdl, u32 colour, s32 alpha, f32 arg3, f32 arg4)
{
	u16 *fb = viGetFrontBuffer();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	f32 somefloat;
	s32 i;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "stretchBlurGfx");

	gDPPipeSync(gdl++);

	somefloat = (viewheight - viewheight / arg4) * 0.5f;

	gdl = bviewPrepareStaticRgba16(gdl, colour, alpha);

	for (i = viewtop; i < viewtop + viewheight; i++) {
		gdl = bviewCopyPixels(gdl, fb, (s32)somefloat + viewtop, 5, i, arg3, viewleft, viewwidth);
		somefloat += 1.0f / arg4;
	}

	return gdl;
}

f32 bview0f142d74(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
	f32 result;
	f32 value = arg2;

	if (arg0 < 0 || arg0 >= 0x80) {
		return 0.01f;
	}

	value += arg0 * arg1;

	if (arg3 > value * value) {
		result = sqrtf(arg3 - value * value) * 0.00625f;
	} else {
		result = 0.01f;
	}

	return result;
}

void bview0f1572f8(void)
{
	// empty
}

u8 var8007f878 = 0;

/**
 * Draw a horizontal blur/sretch effect. Unused.
 *
 * The term "Intro" used in the string suggests that was made for an older
 * version of the title screen, similar to bviewDrawIntroText.
 */
Gfx *bviewDrawIntroFaderBlur(Gfx *gdl, s32 arg1)
{
	u16 *fb = viGetBackBuffer();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	f32 halfheight;
	f32 extra;
	s32 y;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "IntroFaderBlurGfx");

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, 0xffffffff, 255);

	halfheight = viewheight * 0.5f;

	extra = 0.5f;
	extra += 0.5f;

	for (y = viewtop; y < viewtop + viewheight; y++) {
		f32 frac = (y - viewtop - halfheight) / halfheight;

		if (frac < 0.0f) {
			frac = -frac;
		}

		frac += extra;

		if (frac > 1.0f) {
			frac = 1.0f;
		}

		gdl = bviewCopyPixels(gdl, fb, y, 5, y, RANDOMFRAC() * frac + 1.0f, viewleft, viewwidth);
	}

	return gdl;
}

/**
 * Called from the title screen's "Rare Presents" mode, which is unused.
 */
Gfx *bviewDrawIntroText(Gfx *gdl)
{
	u16 *fb = viGetBackBuffer();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	s32 y;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "IntroTextInterfereGfx");

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, 0x8f8f8f8f, 255);

	for (y = viewtop; y < viewtop + viewheight; y += 2) {
		gdl = bviewCopyPixels(gdl, fb, y, 5, y, 1.0f, viewleft, viewwidth);
	}

	return gdl;
}

/**
 * Draws the black part of the IR scanner, which obscures the edges of the
 * screen and creates the binocular effect.
 *
 * The two circles are "placed" at the 1/3 and 2/3 marks horizontally. The
 * screen is then iterated top to bottom, one line at a time, and draws
 * black rectangles on each line to fill in the area outside the circles.
 */
Gfx *bview0f148b38(Gfx *gdl)
{
	return gdl;
}

void bviewSetMotionBlur(u32 bluramount)
{
	var8007f840 = 0;
	var8007f848 = 0;
	var8007f844 = (bluramount << 1) / 3;
}

void bviewClearMotionBlur(void)
{
	var8007f844 = 0;
}
