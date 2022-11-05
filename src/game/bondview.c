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

u8 var8007f878 = 0;

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
