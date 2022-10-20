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

char var800a41c0[24];
u8 g_IrScanlines[2][480];

#if VERSION < VERSION_NTSC_1_0
u8 var800a8b58nb[0x1c0];
#endif

s32 var8007f840 = 0;
u8 var8007f844 = 0;
u8 var8007f848 = 0;
s32 g_IrBinocularRadius = PAL ? 102 : 90;
s32 var8007f850 = 3;
u32 var8007f854 = 0x00000000;
u32 var8007f858 = 0xb8000000;
u32 var8007f85c = 0x00000000;

#if VERSION < VERSION_NTSC_1_0
void func0f13c2d0nb(void)
{
	mainOverrideVariable("fsrad", (u32 *)&g_IrBinocularRadius);
	mainOverrideVariable("fscs", (u32 *)&var8007f850);
}
#endif

Gfx *bviewDrawIrRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2)
{
	gDPFillRectangle(gdl++, x1, y1, x2, y2);

	return gdl;
}

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

/**
 * Draw the fisheye curved effect when using an eyespy.
 *
 * PAL Beta adds padding above and below to compensate for the higher vertical
 * screen resolution, by adjusting the viewtop and viewheight variables and
 * drawing black filler at the end of the function. However the size of these
 * bars is static regardless of the screen layout and size being used.
 *
 * PAL Final improves on beta's mistake by checking the screen size, but there's
 * no check for a vertical split being used, and as a result the fisheye radius
 * is smaller than it should be when using a horizontal split. @bug
 */
Gfx *bviewDrawFisheye(Gfx *gdl, u32 colour, u32 alpha, s32 shuttertime60, s8 startuptimer60, u8 hit)
{
	u16 *fb = viGetBackBuffer();
	s32 viewtop;
	s32 viewheight;
	f32 f26;
	f32 halfheight;
	f32 sqhalfheight;
	s32 viewwidth;
	s32 viewleft;
	s32 s2;
	s32 i;
	s32 s3;
	u8 starting;
	s32 curradius;
	f32 startupfrac;
	f32 fullradius;
	s32 one = 1;
	s32 spec;
	u8 alpha2;

#if VERSION >= VERSION_PAL_FINAL && PAL
	s32 vpadding;
#endif

	f32 tmp;

#if VERSION >= VERSION_PAL_FINAL
	viewtop = viGetViewTop();
	viewheight = viGetViewHeight();
	viewwidth = viGetViewWidth();
	viewleft = viGetViewLeft();

	startupfrac = 1.0f;
	s2 = 0;

#if PAL
	if (PLAYERCOUNT() >= 2
			|| optionsGetEffectiveScreenSize() == SCREENSIZE_WIDE
			|| optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA) {
		vpadding = 16;
		viewtop += vpadding;
		viewheight -= vpadding * 2;
	} else {
		vpadding = 23;
		viewtop += vpadding;
		viewheight -= vpadding * 2;
	}
#endif

	halfheight = viewheight * 0.5f;
	sqhalfheight = halfheight * halfheight;
	f26 = -(halfheight + halfheight) / viewheight;
#elif VERSION >= VERSION_PAL_BETA
	viewtop = viGetViewTop() + 16;
	viewheight = viGetViewHeight() - 32;
	halfheight = viewheight * 0.5f;
	sqhalfheight = halfheight * halfheight;
	f26 = -(halfheight + halfheight) / viewheight;
	viewwidth = viGetViewWidth();
	viewleft = viGetViewLeft();
	startupfrac = 1.0f;
	s2 = 0;
#else
	viewtop = viGetViewTop();
	viewheight = viGetViewHeight();
	halfheight = viewheight * 0.5f;
	sqhalfheight = halfheight * halfheight;
	f26 = -(halfheight + halfheight) / viewheight;
	viewwidth = viGetViewWidth();
	viewleft = viGetViewLeft();
	startupfrac = 1.0f;
	s2 = 0;
#endif

	starting = (startuptimer60 < TICKS(50));

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "blurGfxFisheye");

	s3 = 1;

	if (starting) {
		fullradius = viewheight * 0.5f;
		startupfrac = startuptimer60 / (PAL ? 41.0f : 50.0f);
		curradius = fullradius * startupfrac;
		spec = startupfrac * 255.0f;

		if (spec > 255) {
			spec = 255;
		}
	}

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, colour, alpha);

	if (starting) {
		for (i = viewtop; i < viewtop + viewheight; i++) {
			if (i % 2) {
				if (i > viewtop + fullradius - curradius && i < viewtop + fullradius + curradius) {
					gDPSetEnvColorViaWord(gdl++, (colour & 0xffffff00) | (spec & 0xff));

					tmp = bview0f142d74(s2, f26, halfheight, sqhalfheight) * startupfrac;
					gdl = bviewCopyPixels(gdl, fb, i, 5, i, tmp, viewleft, viewwidth);
				}
			}

			s2 += s3;

			if (s2 >= viewheight * 0.5f) {
				s2 = viewheight * 0.5f;
				s3 = -s3;
			}
		}
	} else {
		f32 f22 = 1.0f;

		for (i = viewtop; i < viewtop + viewheight; i++) {
			if (hit == EYESPYHIT_DAMAGE) {
				alpha2 = (random() % 120) + 120;
				colour = 0xff333300 | (alpha2 & 0xff);
				f22 = ((random() % 32) + 220.0f) * (1.0f / 256.0f);

				gDPSetEnvColorViaWord(gdl++, colour);
			} else {
				gDPSetEnvColorViaWord(gdl++, 0xffffffff);
			}

			tmp = bview0f142d74(s2, f26, halfheight, sqhalfheight) * f22;
			gdl = bviewCopyPixels(gdl, fb, i, 5, i, tmp, viewleft, viewwidth);

			if (hit == EYESPYHIT_DAMAGE) {
				gDPSetEnvColorViaWord(gdl++, 0xddaaaa99);

				tmp = bview0f142d74(s2, f26, halfheight, sqhalfheight) * 1.03f;
				gdl = bviewCopyPixels(gdl, fb, i, 5, i, tmp, viewleft, viewwidth);
			}

			s2 += s3;

			if ((i % 2) == 0) {
				gDPSetEnvColorViaWord(gdl++, 0x00000055);
				gDPFillRectangle(gdl++, viewleft, i, viewleft + viewwidth, i + 1);
			}

			if (s2 >= viewheight * 0.5f) {
				s2 = viewheight * 0.5f;
				s3 = -s3;
			}
		}
	}

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColor(gdl++, 0, 0, 0x00, 0x00, 0x00, 0xff);

	s3 = 1;

	if (shuttertime60 != 0 || starting) {
		s32 s7;
		s32 spa8 = viewheight * 0.5f;
		f32 f20;

		if (!starting) {
			shuttertime60 -= TICKS(12);

			if (shuttertime60 < 0) {
				shuttertime60 = -shuttertime60;
			}

			s7 = spa8 * (shuttertime60 / TICKS(12.0f));
		} else {
			s7 = curradius;
		}

		for (i = viewtop; i < viewtop + spa8 - s7; i++) {
			gdl = bviewDrawFisheyeRect(gdl, i, 0.0f, viewleft, viewwidth);
			gdl = bviewDrawFisheyeRect(gdl, viewtop + viewtop + viewheight - i, 0.0f, viewleft, viewwidth);
		}

		gDPSetPrimColorViaWord(gdl++, 0, 0, 0x000000ff);

		tmp = (f32) one * halfheight;
		f20 = halfheight;

		for (i = viewtop + spa8 - s7; i <= viewtop + spa8; i++) {
			f32 f2;

			if (sqhalfheight > f20 * f20) {
				f2 = sqrtf(sqhalfheight - f20 * f20) * (1.0f / 160.0f);
			} else {
				f2 = 0.01f;
			}

			f20 += -tmp / s7;

			gdl = bviewDrawFisheyeRect(gdl, i, f2 * startupfrac, viewleft, viewwidth);

			if (i != viewtop + viewtop + viewheight - i) {
				gdl = bviewDrawFisheyeRect(gdl, viewtop + viewtop + viewheight - i, f2 * startupfrac, viewleft, viewwidth);
			}
		}
	} else {
		s2 = 0;

		for (i = viewtop; i < viewtop + viewheight; i++) {
			tmp = bview0f142d74(s2, f26, halfheight, sqhalfheight);
			gdl = bviewDrawFisheyeRect(gdl, i, tmp, viewleft, viewwidth);

			s2 += s3;

			if (s2 >= viewheight * 0.5f) {
				s2 = viewheight * 0.5f;
				s3 = -s3;
			}
		}
	}

#if PAL
	s3 = viGetViewTop();
#if VERSION >= VERSION_PAL_FINAL
	s2 = s3 + viGetViewHeight() - vpadding;
#else
	s2 = s3 + viGetViewHeight() - 16;
#endif

#if VERSION >= VERSION_PAL_FINAL
	for (i = 0; i < vpadding; i++)
#else
	for (i = 0; i < 16; i++)
#endif
	{
		gDPFillRectangle(gdl++, viewleft, s3 , viewleft + viewwidth, s3 + 1);
		gDPFillRectangle(gdl++, viewleft, s2, viewleft + viewwidth, s2 + 1);

		s3++;
		s2++;
	}
#endif

	return gdl;
}

/**
 * Draw a black rectangle to the side of the circular fisheye lens.
 *
 * These are each 1px high, and go from the edge of the circle to the edge of
 * the screen. There is one drawn on every row on both sides.
 */
Gfx *bviewDrawEyespySideRect(Gfx *gdl, s32 *points, u8 r, u8 g, u8 b, u8 alpha)
{
	struct gfxvtx *vertices = gfxAllocateVertices(4);
	u32 *colours = gfxAllocateColours(2);

	vertices[0].x = points[0] * 10.0f;
	vertices[0].y = points[1] * 10.0f;
	vertices[0].z = -10;

	vertices[1].x = points[2] * 10.0f;
	vertices[1].y = points[3] * 10.0f;
	vertices[1].z = -10;

	vertices[2].x = points[4] * 10.0f;
	vertices[2].y = points[5] * 10.0f;
	vertices[2].z = -10;

	vertices[3].x = points[6] * 10.0f;
	vertices[3].y = points[7] * 10.0f;
	vertices[3].z = -10;

	colours[0] = r << 0x18 | g << 0x10 | b << 8 | 0xff;
	colours[1] = r << 0x18 | g << 0x10 | b << 8 | alpha;

	vertices[0].colour = 0;
	vertices[1].colour = 0;
	vertices[2].colour = 4;
	vertices[3].colour = 4;

	gDPSetColorArray(gdl++, colours, 2);
	gDPSetVerticeArray(gdl++, vertices, 4);

	if (colours);

	gDPTri2(gdl++, 0, 1, 2, 0, 2, 3);

	return gdl;
}

/**
 * Renders the eyespy user interface, excluding the fisheye lens. The lens is
 * drawn first by another function, then this one is called to draw the outer
 * information. Care must be taken not to draw over the top of the fisheye lens.
 *
 * Note that the dimensions of the view can differ based on hi-res on/off, as
 * well as using coop mode in both the vertical and horizontal screen splits.
 * Some elements are omitted if a vertical split is being used, and to handle
 * hi-res a scale variable is used to multiply X values and widths where needed.
 *
 * @bug: Many of the X values and widths are not multiplied by the scale which
 * causes them to display incorrectly when using hi-res:
 * - Some of the horizontal lines don't touch the lens circle.
 * - The vertical lines are thinner and closer to the screen edges than intended.
 * - The speed and height bars are stretched.
 * - The device name and model are closer to the screen edge than intended.
 */
Gfx *bviewDrawEyespyMetrics(Gfx *gdl)
{
	char text[256];
	s32 viewleft = viGetViewLeft();
#if VERSION >= VERSION_PAL_FINAL
	s32 viewwidth = viGetViewWidth();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
#elif VERSION >= VERSION_PAL_BETA
	s32 viewwidth = viGetViewWidth();
	s32 viewtop = viGetViewTop() + 16;
	s32 viewheight = viGetViewHeight() - 32;
#else
	s32 viewtop = viGetViewTop();
	s32 viewwidth = viGetViewWidth();
	s32 viewheight = viGetViewHeight();
#endif
	s32 viewright = viewleft + viewwidth - 1;
	s32 viewbottom = viewtop + viewheight - 1;
	s32 x;
	s32 y;
	s32 textwidth;
	s32 textheight;
	s32 x2;
	s32 y2;
	struct chrdata *chr;
	s32 savedy;
	s32 movex;
	s32 movey;
	s32 movez;
	f32 movedist;
	f32 sqmovedist = 0.0f;
	u32 colourtextbright;
	u32 colourtextdull;
	u32 colourglow;
#if PAL
	s32 scale = 1;
	f32 palscale = viewwidth > 320 ? 1.4f : 1.0f;
#else
	s32 scale = viewwidth > 320 ? 2 : 1;
#endif
#if VERSION >= VERSION_NTSC_1_0
	bool vsplit = false;
#endif

#if VERSION >= VERSION_PAL_FINAL
#if PAL
	if (PLAYERCOUNT() >= 2
			|| optionsGetEffectiveScreenSize() == SCREENSIZE_WIDE
			|| optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA) {
		viewtop += 16;
		viewheight -= 32;
	} else {
		viewtop += 23;
		viewheight -= 46;
	}
#endif
	viewbottom = viewtop + viewheight - 1;
#endif

	if (g_Vars.currentplayer->eyespy == NULL
			|| g_Vars.currentplayer->eyespy->prop == NULL
			|| g_Vars.currentplayer->eyespy->prop->chr == NULL) {
		return gdl;
	}

	chr = g_Vars.currentplayer->eyespy->prop->chr;

#if VERSION >= VERSION_NTSC_1_0
	if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL && PLAYERCOUNT() >= 2) {
		vsplit = true;
	}
#endif

#if VERSION >= VERSION_NTSC_1_0
	movex = chr->prop->pos.x - chr->prevpos.x;
	movey = chr->prop->pos.y - chr->prevpos.y;
	movez = chr->prop->pos.z - chr->prevpos.z;

	if (movex != 0.0f || movey != 0.0f || movez != 0.0f) {
		sqmovedist = movex * movex + movey * movey + movez * movez;
	}

	if (sqmovedist > 0.001f) {
		movedist = sqrtf(sqmovedist);
	} else {
		movedist = 0.0f;
	}
#else
	if (g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
		movex = chr->prop->pos.x - chr->prevpos.x;
		movey = chr->prop->pos.y - chr->prevpos.y;
		movez = chr->prop->pos.z - chr->prevpos.z;

		if (movex != 0.0f || movey != 0.0f || movez != 0.0f) {
			sqmovedist = movex * movex + movey * movey + movez * movez;
		}

		if (sqmovedist > 0.001f) {
			movedist = sqrtf(sqmovedist);
		} else {
			movedist = 0.0f;
		}
	} else {
		movedist = 0.0f;
	}
#endif

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		gdl = textSetPrimColour(gdl, 0x00ff0028);
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		gdl = textSetPrimColour(gdl, 0x2244ffa0);
	} else {
		gdl = textSetPrimColour(gdl, 0xff3300a0);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (!vsplit)
#endif
	{
		// Render borders/lines in background
		gDPFillRectangle(gdl++, viewleft + 25, viewtop + 55, viewleft + 26, viewbottom - 24);
		gDPFillRectangle(gdl++, viewleft + 31, viewtop + 55, viewleft + 32, viewbottom - 42);
		gDPFillRectangle(gdl++, viewleft + 25, viewbottom - 25, viewleft + 25 + viewwidth / 5.0f + 1, viewbottom - 24);
		gDPFillRectangle(gdl++, viewleft + 31, viewbottom - 43, viewleft + 25 + viewwidth / 7.0f + 1, viewbottom - 42);
		gDPFillRectangle(gdl++, viewright - 25, viewtop + 25, viewright - 24, viewbottom - 54);
		gDPFillRectangle(gdl++, viewright - 31, viewtop + 43, viewright - 30, viewbottom - 54);
		gDPFillRectangle(gdl++, viewright - 25 - viewwidth / 5.0f, viewtop + 25, viewright - 24, viewtop + 26);
		gDPFillRectangle(gdl++, viewright - 25 - viewwidth / 7.0f, viewtop + 43, viewright - 30, viewtop + 44);
		gDPFillRectangle(gdl++, viewleft, viewtop + 55, viewleft + viewwidth / 5.0f + 1, viewtop + 56);
		gDPFillRectangle(gdl++, viewright - viewwidth / 5.0f, viewbottom - 55, viewright + 1, viewbottom - 54);
	}

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		// Render crosshair
		s32 x = viewleft + (viewwidth >> 1);
		s32 y = viewtop + (viewheight >> 1);

		gDPFillRectangle(gdl++, x + 2, y + 0, x + 7, y + 1);
		gDPFillRectangle(gdl++, x + 2, y + 0, x + 5, y + 1);
		gDPFillRectangle(gdl++, x - 6, y + 0, x - 1, y + 1);
		gDPFillRectangle(gdl++, x - 4, y + 0, x - 1, y + 1);
		gDPFillRectangle(gdl++, x + 0, y + 2, x + 1, y + 7);
		gDPFillRectangle(gdl++, x + 0, y + 2, x + 1, y + 5);
		gDPFillRectangle(gdl++, x + 0, y - 6, x + 1, y - 1);
		gDPFillRectangle(gdl++, x + 0, y - 4, x + 1, y - 1);
	}

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		colourtextbright = 0x00ff00a0;
		colourtextdull = 0x005000ff;
		colourglow = 0x000f00ff;
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		colourtextbright = 0x2244ffff;
		colourtextdull = 0x2244ffff;
		colourglow = 0x00000fff;
	} else {
		colourtextbright = 0xff3300ff;
		colourtextdull = 0xff3300ff;
		colourglow = 0x0f0000ff;
	}

	// "S/MPS"
	sprintf(text, "%s %s%5.2f", langGet(L_MISC_073), "", movedist * 0.6f);
	savedy = viewtop + 14;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);

#if VERSION >= VERSION_JPN_FINAL
	gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif

	// "H/M"
	sprintf(text, "%s %s%4.2f", langGet(L_MISC_074), "", g_Vars.currentplayer->eyespy->height * 0.01f);
	savedy += 9;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
#if VERSION >= VERSION_JPN_FINAL
	gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif

	// "Y/D"
	sprintf(text, "%s %d", langGet(L_MISC_075), (s32)g_Vars.currentplayer->eyespy->theta);
	savedy += 9;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
#if VERSION >= VERSION_JPN_FINAL
	gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif

	// "P/D"
	sprintf(text, "%s %d", langGet(L_MISC_076), (s32)g_Vars.currentplayer->eyespy->verta);
	savedy += 9;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
#if VERSION >= VERSION_JPN_FINAL
	gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif

	// "CI 2023"
	sprintf(text, "%s", langGet(L_MISC_077));
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

#if VERSION >= VERSION_NTSC_1_0
	x = (vsplit ? -3 : 0) + viewleft + 25 * scale + 5;
	y = (vsplit ? 18 : 0) + viewbottom - 41;
#else
	x = viewleft + 25 * scale + 5;
	y = viewbottom - 41;
#endif
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
#if VERSION >= VERSION_JPN_FINAL
	gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		sprintf(text, "%s", langGet(L_MISC_078)); // "YKK: 95935"
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		sprintf(text, "%s", langGet(L_MISC_208)); // "JM: 201172"
	} else {
		sprintf(text, "%s", langGet(L_MISC_217)); // "BNC: 15877"
	}

	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

#if VERSION >= VERSION_NTSC_1_0
	x = viewleft + 25 * scale + (vsplit ? -3 : 0) + 5;
	y = viewbottom + (vsplit ? 20 : 0) - 34;
#else
	x = viewleft + 25 * scale + 5;
	y = viewbottom - 34;
#endif

	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
#if VERSION >= VERSION_JPN_FINAL
	gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		// "CAMSPY"
		sprintf(text, "   %s", langGet(L_MISC_079));
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

#if VERSION >= VERSION_PAL_FINAL
		x = viewright - textwidth - 27;
#else
		x = viewright - scale * 53 - 25;
#endif
#if VERSION >= VERSION_NTSC_1_0
		y = (vsplit ? -13 : 0) + viewtop + 27;
#else
		y = viewtop + 27;
#endif
		x2 = x + textwidth; \
		y2 = y + textheight; \
		gdl = text0f153858(gdl, &x, &y, &x2, &y2);
#if VERSION >= VERSION_JPN_FINAL
		gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		// "DRUGSPY"
		sprintf(text, "   %s", langGet(L_MISC_468));
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

#if VERSION >= VERSION_PAL_FINAL
		x = viewright - textwidth - 27;
#else
		x = viewright - scale * 53 - 25;
#endif
#if VERSION >= VERSION_NTSC_1_0
		y = (vsplit ? -13 : 0) + viewtop + 27;
#else
		y = viewtop + 27;
#endif
		x2 = x + textwidth; \
		y2 = y + textheight; \
		gdl = text0f153858(gdl, &x, &y, &x2, &y2);
#if VERSION >= VERSION_JPN_FINAL
		gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif
	} else {
		// "BOMBSPY"
		sprintf(text, "   %s", langGet(L_MISC_469));
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

#if VERSION >= VERSION_PAL_FINAL
		x = viewright - textwidth - 27;
#else
		x = viewright - scale * 59 - 25;
#endif
#if VERSION >= VERSION_NTSC_1_0
		y = (vsplit ? -13 : 0) + viewtop + 27;
#else
		y = viewtop + 27;
#endif
		x2 = x + textwidth; \
		y2 = y + textheight; \
		gdl = text0f153858(gdl, &x, &y, &x2, &y2);
#if VERSION >= VERSION_JPN_FINAL
		gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif
	}

	// Model number
	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		sprintf(text, "%s", langGet(L_MISC_080)); // "MODEL 1.2"
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		sprintf(text, "%s", langGet(L_MISC_207)); // "MODEL 1.4"
	} else {
		sprintf(text, "%s", langGet(L_MISC_216)); // "MODEL 1.3"
	}

	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
#if VERSION >= VERSION_PAL_FINAL
	x = (vsplit ? 3 : 0) + viewright - textwidth - 27;
	y = (vsplit ? -11 : 0) + viewtop + 34;
#elif VERSION >= VERSION_NTSC_1_0
	x = (vsplit ? 3 : 0) + viewright - scale * 46 - 25;
	y = (vsplit ? -11 : 0) + viewtop + 34;
#else
	x = viewright - scale * 46 - 25;
	y = viewtop + 34;
#endif
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
#if VERSION >= VERSION_JPN_FINAL
	gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif

	// Gyrostat/dartammo text
	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY
			|| g_Vars.currentplayer->eyespy->mode == EYESPYMODE_BOMBSPY) {
		sprintf(text, "%s", langGet(L_MISC_081)); // "GYROSTAT"
	} else {
		sprintf(text, "%s", langGet(L_MISC_206)); // "DARTAMMO"
	}

	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
#if VERSION >= VERSION_PAL_FINAL
	x = viewright - textwidth - 27;
	y = (vsplit ? -2 : 0) + viewbottom - 12;
#elif VERSION >= VERSION_NTSC_1_0
	x = (vsplit ? -35 : 0) + (viewright - viewwidth / 5.0f - 3 - (scale * 5 - 5));
	y = (vsplit ? -2 : 0) + viewbottom - 12;
#else
	x = viewright - viewwidth / 5.0f - 3 - (scale * 5 - 5);
	y = viewbottom - 12;
#endif
	if (1);
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
#if VERSION >= VERSION_JPN_FINAL
	gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#else
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
#endif

	gdl = text0f153838(gdl);

	{
		s8 contpadnum = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
		u16 buttonsdown = joyGetButtons(contpadnum, 0xffff); \
		u16 buttonsthisframe = joyGetButtonsPressedThisFrame(contpadnum, 0xffff);
		s8 cstickx = joyGetStickX(contpadnum); \
		s8 csticky = joyGetStickY(contpadnum);
		s32 xpos;
		s32 tmpval;
		u8 brightness;
		u8 brightness2;
		s32 points[8];
		s32 r;
		s32 g;
		s32 b;

		gDPPipeSync(gdl++); \
		gDPSetCycleType(gdl++, G_CYC_1CYCLE); \
		gDPSetColorDither(gdl++, G_CD_DISABLE); \
		gDPSetTexturePersp(gdl++, G_TP_NONE); \
		gDPSetAlphaCompare(gdl++, G_AC_NONE); \
		gDPSetTextureLOD(gdl++, G_TL_TILE); \
		gDPSetTextureFilter(gdl++, G_TF_BILERP); \
		gDPSetTextureConvert(gdl++, G_TC_FILT); \
		gDPSetTextureLUT(gdl++, G_TT_NONE); \
		gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2); \
		gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

#if VERSION >= VERSION_NTSC_1_0
		if (!vsplit)
#endif
		{
			xpos = (scale == 2) ? -76 : -85;

			// Up
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20; \
				if (buttonsdown & (U_JPAD | U_CBUTTONS)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) { \
					brightness += 20; \
				} \
				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff); \
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (U_JPAD | U_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) {
					brightness += 63; \
				} \
				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (U_JPAD | U_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) {
					brightness += 20; \
				} \
				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Down
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (D_JPAD | D_CBUTTONS)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Left
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (L_JPAD | L_CBUTTONS)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Right
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (R_JPAD | R_CBUTTONS)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Shoulder buttons
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (L_TRIG | R_TRIG)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (L_TRIG | R_TRIG)) {
					brightness += 63;
				}

				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (L_TRIG | R_TRIG)) {
					brightness += 20;
				}

				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Z button
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & Z_TRIG) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & Z_TRIG) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & Z_TRIG) {
					brightness += 63;
				}

				if (buttonsthisframe & Z_TRIG) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & Z_TRIG) {
					brightness += 20;
				}

				if (buttonsthisframe & Z_TRIG) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
		}

		xpos = (scale == 2) ? -48 : -55;

		// Stick X
		tmpval = cstickx * 96.0f / 80.0f;
		brightness = tmpval < 0 ? -tmpval : tmpval;

		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
			gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
		} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
			r = brightness / 96.0f * 16.0f;
			g = brightness / 96.0f * 32.0f;
			b = brightness * 2.5f;
			gDPSetPrimColor(gdl++, 0, 0, r, g, b, 0xff);
		} else {
			gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
		}

#if VERSION >= VERSION_NTSC_1_0
		if (!vsplit)
#endif
		{
			tmpval = cstickx * 28.0f / 80.0f;

			if (cstickx > 0) {
				gDPFillRectangle(gdl++,
						xpos * scale + viewright,
						viewtop + 19,
						(tmpval + xpos) * scale + viewright,
						viewtop + 21);
			} else {
				gDPFillRectangle(gdl++,
						(tmpval + xpos) * scale + viewright,
						viewtop + 19,
						xpos * scale + viewright,
						viewtop + 21);
			}
		}

		// Stick Y
		tmpval = csticky * 96.0f / 80.0f;
		brightness = tmpval < 0 ? -tmpval : tmpval;

		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
			gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
		} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
			r = brightness / 96.0f * 16.0f;
			g = brightness / 96.0f * 32.0f;
			b = brightness * 2.5f;
			gDPSetPrimColor(gdl++, 0, 0, r, g, b, 0xff);
		} else {
			gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
		}

#if VERSION >= VERSION_NTSC_1_0
		if (!vsplit)
#endif
		{
			tmpval = csticky * 28.0f / 80.0f;

			if (csticky > 0) {
				gDPFillRectangle(gdl++,
						xpos * scale + viewright,
						viewtop + 22,
						(tmpval + xpos) * scale + viewright,
						viewtop + 24);
			} else {
				gDPFillRectangle(gdl++,
						(tmpval + xpos) * scale + viewright,
						viewtop + 22,
						xpos * scale + viewright,
						viewtop + 24);
			}
		}

		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
#if VERSION >= VERSION_NTSC_1_0
			if (!vsplit)
#endif
			{
				// Camspy gyrobar 1
				x = viewright - viewwidth / 5.0f;
				y = viewbottom - 13;

				tmpval = g_Vars.currentplayer->eyespy->theta * 96.0f / 360.0f;
				textheight = g_Vars.currentplayer->eyespy->theta * 35.0f / 360.0f;
				brightness = tmpval < 0 ? -tmpval : tmpval; \
				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Camspy gyrobar 2
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Camspy gyrobar 3
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Camspy gyrobar 4
				x += scale * 2 + scale * 5;

				tmpval = g_Vars.currentplayer->eyespy->verta * 96.0f / 360.0f;
				textheight = g_Vars.currentplayer->eyespy->verta * 35.0f / 360.0f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Camspy gyrobar 5
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Camspy gyrobar 6
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				x += scale * 2 + scale * 5;
			}
		} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_BOMBSPY) {
#if VERSION >= VERSION_NTSC_1_0
			if (!vsplit)
#endif
			{
				// Bombspy gyrobar 1
				x = viewright - viewwidth / 5.0f;
				y = viewbottom - 13;

				tmpval = g_Vars.currentplayer->eyespy->theta * 96.0f / 360.0f;
				textheight = g_Vars.currentplayer->eyespy->theta * 35.0f / 360.0f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Bombspy gyrobar 2
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Bombspy gyrobar 3
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Bombspy gyrobar 4
				x += scale * 2 + scale * 5;

				tmpval = g_Vars.currentplayer->eyespy->verta * 96.0f / 360.0f;
				textheight = g_Vars.currentplayer->eyespy->verta * 35.0f / 360.0f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Bombspy gyrobar 5
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Bombspy gyrobar 6
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				x += scale * 2 + scale * 5;
			}
		} else {
			// Drugspy ammo
			s32 i;
#if VERSION >= VERSION_NTSC_1_0
			s32 width;
#endif

			brightness2 = 255;
#if VERSION >= VERSION_NTSC_1_0
			width = scale * 30;
#endif

			y = viewbottom - 13;
			x = viewright - viewwidth / 5.0f + 5;

#if VERSION >= VERSION_NTSC_1_0
			if (vsplit) {
				x -= 12;
				y -= 3;
				width = 15;
			}
#endif

			for (i = 0; i < 8; i++) {
				if (i >= g_Vars.currentplayer->eyespydarts) {
					brightness2 = 0x88;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness2, 0xff);
#if VERSION >= VERSION_NTSC_1_0
				gDPFillRectangle(gdl++, x, y - 4, x + width, y);
#else
				gDPFillRectangle(gdl++, x, y - 4, x + 30 * scale, y);
#endif

				y -= 5;
			}
		}

		gDPPipeSync(gdl++); \
		gDPSetColorDither(gdl++, G_CD_BAYER); \
		gDPSetTexturePersp(gdl++, G_TP_PERSP); \
		gDPSetTextureLOD(gdl++, G_TL_LOD);

		if (g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
			s32 barheight = (viewbottom - viewtop - 103) / 17.0f - 1;
			s32 centrey = viewheight / 2.0f;
			s32 sqcentrey = centrey * centrey;
			s32 ypos;
			u8 alpha;
			u32 stack;
			u32 stack2;
			s8 yoffset;
			s32 value;
			s32 i;

#if VERSION == VERSION_PAL_BETA
			if (centrey);
#endif

			value = 17.0f * movedist / 25.0f;

			if (value > 17) {
				value = 17;
			}

			value = 17 - value;

			if (viewheight == 220) {
				yoffset = 10;
			} else if (viewheight == 180) {
				barheight--;
				yoffset = -8;
			} else {
				yoffset = 0;
			}

			gdl = func0f0d479c(gdl);

			gSPClearGeometryMode(gdl++, G_CULL_BOTH);
			gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
			gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
			gDPSetTextureFilter(gdl++, G_TF_BILERP);
			gDPSetCycleType(gdl++, G_CYC_1CYCLE);
			gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

			// Speed bars (left side)
			y = viewtop + 58;

			if (viewheight == 180) {
				y += 5;
			}

			ypos = centrey - y + 10;

#if VERSION == VERSION_PAL_BETA
			ypos += 16;
#endif

#if VERSION == VERSION_PAL_FINAL
			if (PLAYERCOUNT() >= 2
					|| optionsGetEffectiveScreenSize() == SCREENSIZE_WIDE
					|| optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA) {
				ypos += 16;
			} else {
				ypos += 23;
			}
#endif

			for (i = 0; i < 17; i++) {
				brightness = i < value ? 40 : 80;
				alpha = i < value ? 0x22 : 0x56;

				points[0] = x = viewleft + 34;
				points[1] = y;
				points[2] = x = viewleft + 34;
				points[3] = y + barheight;
#if PAL
				points[6] = x = viewwidth / 2.0f - sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * palscale - 5.0f;
#else
				points[6] = x = viewwidth / 2.0f - sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale - 5.0f;
#endif
				points[5] = y + barheight;

				ypos -= barheight;

#if PAL
				points[4] = x = viewwidth / 2.0f - sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * palscale - 5.0f;
#else
				points[4] = x = viewwidth / 2.0f - sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale - 5.0f;
#endif
				points[7] = y;

				ypos -= 2;

				if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
					gdl = bviewDrawEyespySideRect(gdl, points, 0, brightness, 0, alpha);
				} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
					gdl = bviewDrawEyespySideRect(gdl, points, 0x10, brightness, brightness * 3, alpha);
				} else {
					gdl = bviewDrawEyespySideRect(gdl, points, brightness, brightness >> 2, 0, alpha);
				}

				y += barheight;
				y += 2;
			}

			// Height bars (right side)
			value = g_Vars.currentplayer->eyespy->height * 17.0f * (1.0f / 160.0f);

			if (value > 17) {
				value = 17;
			}

			value = 17 - value;

			y = viewtop + 46;

			if (viewheight == 180) {
				y += 5;
			}

			ypos = centrey - y + 10;

#if VERSION == VERSION_PAL_BETA
			ypos += 16;
#endif

#if VERSION == VERSION_PAL_FINAL
			if (PLAYERCOUNT() >= 2
					|| optionsGetEffectiveScreenSize() == SCREENSIZE_WIDE
					|| optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA) {
				ypos += 16;
			} else {
				ypos += 23;
			}
#endif

			for (i = 0; i < 17; i++) {
				brightness = i < value ? 40 : 80;
				alpha = i < value ? 0x22 : 0x56;

				points[0] = x = viewright - 34;
				points[1] = y;
				points[3] = y + barheight;
				points[2] = x = viewright - 34;
#if PAL
				points[6] = x = viewwidth / 2.0f + sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * palscale + 5.0f;
#else
				points[6] = x = viewwidth / 2.0f + sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale + 5.0f;
#endif
				points[5] = y + barheight;

				ypos -= barheight;

#if PAL
				points[4] = x = viewwidth / 2.0f + sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * palscale + 5.0f;
#else
				points[4] = x = viewwidth / 2.0f + sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale + 5.0f;
#endif
				points[7] = y;

				ypos -= 2;

				if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
					gdl = bviewDrawEyespySideRect(gdl, points, 0, brightness, 0, alpha);
				} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
					gdl = bviewDrawEyespySideRect(gdl, points, 0x10, brightness, brightness * 3U, alpha);
				} else {
					gdl = bviewDrawEyespySideRect(gdl, points, brightness, brightness >> 2, 0, alpha);
				}

				y += barheight;
				y += 2;
			}
		}

		gdl = func0f0d49c8(gdl);
	}

	return gdl;
}

void bview0f1572f8(void)
{
	// empty
}

u8 var8007f878 = 0;

Gfx *bviewDrawNvLens(Gfx *gdl)
{
	u16 *fb = viGetBackBuffer();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewtop = viGetViewTop();
	s32 viewleft = viGetViewLeft();
	s32 viewbottom = viewtop + viewheight;
	s32 roomvalue;
	s32 y;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "Fullscreen_DrawFaultScope");

	var8009caec = 0xbc;
	var8009caef = 0xbe;
	var8009caf0 = 0xde;
	var8009caed = 0x50;
	var8009caee = 0xc0;

	roomvalue = func0f0009c0(g_Vars.currentplayer->prop->rooms[0]);

	if (roomvalue > 128) {
		sky0f127334(roomvalue, roomvalue, roomvalue);
	}

	if (g_Menus[g_Vars.currentplayerstats->mpindex].curdialog == NULL) {
		gdl = bviewDrawMotionBlur(gdl, 0x00ff0000, 0x60);
	}

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, 0xffffffff, 0xff);

	var8007f878++;

	for (y = viewtop; y < viewbottom; y++) {
		u8 green;

		if (((var8007f878 & 1) != (y & 1)) != 0) {
			u8 tmp = random() % 12;
			green = 0xff - tmp;
		} else {
			green = 0x94;
		}

		gDPSetColor(gdl++, G_SETENVCOLOR, (green << 16) + 0xff);

		gdl = bviewCopyPixels(gdl, fb, y, 5, y, 1, viewleft, viewwidth);
	}

	return gdl;
}

/**
 * Night vision doesn't have binoculars.
 */
Gfx *bviewDrawNvBinoculars(Gfx *gdl)
{
	return gdl;
}

Gfx *bviewDrawIrLens(Gfx *gdl)
{
	s32 i;
	s32 fadeincrement;
	u16 *fb = viGetBackBuffer();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewtop = viGetViewTop();
	s32 viewleft = viGetViewLeft();
	s32 viewright;
	s32 viewbottom;
	s32 viewcentrex;
	s32 sqinnerradius;
	s32 stack[3];
	s32 scanincrement;
	s32 scantop;
	s32 scanbottom;
	s32 scanrate = 4;
	s32 faderate = 2;
	u32 red;
	s32 outerradius;
	s32 innerradius;
	s32 viewcentrey;
	f32 viewheightf;
	s32 a0;

#if VERSION < VERSION_NTSC_1_0
	static s32 fsscanline = 0;
	static s32 fslastradius = -1;
#endif

	viewright = viewleft + viewwidth;
	viewcentrex = (viewleft + viewright) / 2;

	outerradius = g_IrBinocularRadius;
	innerradius = g_IrBinocularRadius / var8007f850;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "Fullscreen_DrawFaultScope");

#if VERSION < VERSION_NTSC_1_0
	osSyncPrintf("Fault Scope is active\n");
	func0f13c2d0nb();
#endif

	viewbottom = viewtop + viewheight;
	viewcentrey = (viewtop + viewbottom) / 2;
	scantop = viewcentrey - outerradius;
	scanbottom = viewcentrey + outerradius;
	i = viewheight;

	if (scantop > viewbottom) {
		scantop = viewbottom;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (scanbottom > viewbottom) {
		scanbottom = viewbottom;
	}
#else
	if (scantop > viewbottom) {
		scantop = viewbottom;
	}
#endif

	if (scantop < viewtop) {
		scantop = viewtop;
	}

	if (scanbottom < viewtop) {
		scanbottom = viewtop;
	}

	scanincrement = (f32) scanrate * i / 240.0f;
	fadeincrement = (f32) faderate * i / 240.0f;

	// This code runs on the first frame of IR use (90 != 0),
	// and in debug versions developers could change the radius at runtime.
#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.currentplayer->fslastradius != outerradius) {
		for (i = 0; i < 480; i++) {
			g_IrScanlines[g_Vars.currentplayernum][i] = 0xff;
		}

		g_Vars.currentplayer->fsscanline = 0;
		g_Vars.currentplayer->fslastradius = outerradius;
	}
#else
	if (fslastradius != outerradius) {
		for (i = 0; i < 480; i++) {
			g_IrScanlines[0][i] = 0xff;
		}

		fsscanline = 0;
		fslastradius = outerradius;
	}
#endif

	// Increment the scanline
#if VERSION >= VERSION_NTSC_1_0
	for (i = 0; i < scanincrement; i++) {
		if (g_Vars.currentplayer->fsscanline >= scanbottom) {
			g_Vars.currentplayer->fsscanline = scantop;
		}

		g_IrScanlines[g_Vars.currentplayernum][g_Vars.currentplayer->fsscanline] = 0xff - i;

		g_Vars.currentplayer->fsscanline++;
	}
#else
	for (i = 0; i < scanincrement; i++, fsscanline++) {
		if (fsscanline == scanbottom) {
			fsscanline = scantop;
		}

		g_IrScanlines[0][fsscanline] = 0xff - i;
	}
#endif

	var8009caec = 0xff;
	var8009caef = 0xde;
	var8009caf0 = 0xde;

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, 0xffffffff, 255);

	sqinnerradius = innerradius * innerradius;

	for (i = scantop; i < scanbottom; i++) {
#if VERSION >= VERSION_NTSC_1_0
		if (i & 1) {
			red = g_IrScanlines[g_Vars.currentplayernum][i];
		} else {
			red = g_IrScanlines[g_Vars.currentplayernum][i] * 2 / 3;
		}
#else
		if (i & 1) {
			red = g_IrScanlines[0][i];
		} else {
			red = g_IrScanlines[0][i] * 2 / 3;
		}
#endif

		red += random() % 8;

		if (red > 255) {
			red = 255;
		}

		gDPSetEnvColorViaWord(gdl++, (red << 24) + 0xff);

		a0 = viewcentrey - i;

		if (a0 * a0 < sqinnerradius) {
			// Rendering a line that overlaps the semicircle
			// in the middle of the screen
			f32 f0 = a0;
			s32 semicirclewidth = sqrtf(sqinnerradius - (s32) (f0 * f0)) * (viewwidth / 320.0f);
			s32 semicircleright = viewcentrex + semicirclewidth;
			s32 rightsidewidth = viewwidth - semicircleright;

			// Left and right of semicircle
			gdl = bviewCopyPixels(gdl, fb, i, 5, i, 1.0f, viewleft, viewcentrex);
			gdl = bviewCopyPixels(gdl, fb, i, 5, i, 1.0f, semicircleright, rightsidewidth);

			// The semicircle itself has a static colour
			gDPSetEnvColorViaWord(gdl++, 0xee0000ff);
			gdl = bviewCopyPixels(gdl, fb, i, 5, i, 1.0f, viewcentrex, semicirclewidth);
		} else {
			gdl = bviewCopyPixels(gdl, fb, i, 5, i, 1.0f, viewleft, viewwidth);
		}

#if VERSION >= VERSION_NTSC_1_0
		if (g_IrScanlines[g_Vars.currentplayernum][i] > fadeincrement) {
			g_IrScanlines[g_Vars.currentplayernum][i] -= fadeincrement;
		}
#else
		if (g_IrScanlines[0][i] > fadeincrement) {
			g_IrScanlines[0][i] -= fadeincrement;
		}
#endif
	}

	if (g_Menus[g_Vars.currentplayerstats->mpindex].curdialog == NULL) {
		gdl = bviewDrawMotionBlur(gdl, 0xff000000, 0x40);
	}

	return gdl;
}

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

#if VERSION >= VERSION_NTSC_1_0
Gfx *bviewDrawHorizonScanner(Gfx *gdl)
{
	u16 *fb = viGetBackBuffer();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	char directiontext[32];
	char hertztext[24];
	char zoomtext[24];
	char nametext[52];
	f32 lookx = g_Vars.currentplayer->cam_look.x;
	f32 lookz = g_Vars.currentplayer->cam_look.z;
	s32 x;
	s32 y;

	char directions[][3] = {
		{'n', '\0', '\0'},
		{'n', 'e',  '\0'},
		{'e', '\0', '\0'},
		{'s', 'e',  '\0'},
		{'s', '\0', '\0'},
		{'s', 'w',  '\0'},
		{'w', '\0', '\0'},
		{'n', 'w',  '\0'},
		{'n', '\0', '\0'},
	};

	s32 turnangle = atan2f(-lookx, lookz) * 180.0f / M_PI;
	f32 fovy;
	char arrows[12];
	s32 tmplensheight = 130;
	s32 lenstop;
	s32 lensheight;
	s32 liney;
	s32 scale = 1;
	s32 vsplit = false;
	u32 colour;
	f32 range;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "BinocularViewGfx");

	if (!PAL && g_ViRes == VIRES_HI) {
		scale = 2;
	}

	if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL && PLAYERCOUNT() >= 2) {
		vsplit = true;
	}

	if (tmplensheight > viewheight - 30) {
		tmplensheight = viewheight - 30;
	}

	if (((s32)(g_20SecIntervalFrac * 30.0f) & 1) == 1) {
		sprintf(arrows, ">> ");
	} else {
		sprintf(arrows, " >>");
	}

	lensheight = tmplensheight;
	lenstop = viewtop + (viewheight / 2) - (lensheight / 2);

	// Black out areas above and below lens
	gdl = textSetPrimColour(gdl, 0x000000ff);

	gDPFillRectangle(gdl++, viewleft, viewtop, viewleft + viewwidth, lenstop);
	gDPFillRectangle(gdl++, viewleft, lenstop + lensheight, viewleft + viewwidth, viewtop + viewheight);

	gdl = text0f153838(gdl);

	// Prepare text buffers
	sprintf(directiontext, "%s %s:%03d", arrows, &directions[(turnangle + 22) / 45], turnangle);
	sprintf(hertztext, "%s %s%s%4.2fh", arrows, "", "", menuGetCosOscFrac(4) * 4.6f + 917.4f);

	fovy = viGetFovY();

	if (fovy == 0 || fovy == 60.0f) {
		fovy = 1;
	} else {
		fovy = 60.0f / fovy + 1;
	}

	sprintf(zoomtext, "%s %s%s%4.2fX", arrows, "", "", fovy);

	gdl = text0f153628(gdl);

	// Arrows left of product name
	if (vsplit) {
		x = viewleft + 15 * scale;
	} else {
		x = viewleft + 25 * scale;
	}

	y = lenstop - 7;
	gdl = textRenderProjected(gdl, &x, &y, arrows,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, viGetWidth(), viGetHeight(), 0, 0);

	// Product name
	strcpy(nametext, " JMBC");

	if (!vsplit) {
		strcat(nametext, " WIDE BAND");
	}

	strcat(nametext, " SCANNER\n");

	gdl = textRenderProjected(gdl, &x, &y, nametext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, viGetWidth(), viGetHeight(), 0, 0);

	// Hertz
	x = viewleft + 75 * scale;
	y = lenstop + lensheight + 1;
	gdl = textRenderProjected(gdl, &x, &y, hertztext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, viGetWidth(), viGetHeight(), 0, 0);

	// Zoom level
	if (vsplit) {
		x = viewleft + 75 * scale;
		y = lenstop + lensheight + 8;
	} else {
		x = viewleft + 150 * scale;
		y = lenstop + lensheight + 1;
	}

	gdl = textRenderProjected(gdl, &x, &y, zoomtext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, viGetWidth(), viGetHeight(), 0, 0);

	// Direction
	if (vsplit) {
		x = viewleft + 75 * scale;
		y = lenstop + lensheight + 15;
	} else {
		x = viewleft + 225 * scale;
		y = lenstop + lensheight + 1;
	}

	gdl = textRenderProjected(gdl, &x, &y, directiontext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, viGetWidth(), viGetHeight(), 0, 0);
	gdl = text0f153780(gdl);

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, 0xffffffff, 255);

	if (vsplit) {
		vsplit = 14;
	}

	// Iterate horizontal lines down the lens with a bit extra on top and bottom
	for (liney = lenstop - 9; liney < lenstop + lensheight + vsplit + 9; liney++) {
		if (liney < lenstop + lensheight && liney >= lenstop) {
			// Inside the lens
			if ((liney % 2) == 0) {
				colour = 0x00ffffff;
			} else {
				colour = 0x7fffffff;
			}

			range = (liney - lenstop - lensheight * 0.5f) / (lensheight * 0.5f);

			if (range < 0) {
				range = -range;
			}

			if (range > 1) {
				range = 0;
			}

			range = (range - 0.75f) * 4.0f;

			if (range < 0) {
				range = 0;
			}

			if (range > 0) {
				colour = colourBlend(0x000000ff, colour, range * 255.0f);
			}
		} else {
			// Outside of the lens
			if ((liney % 2) == 0) {
				colour = 0x007f7fff;
			} else {
				colour = 0x7fffffff;
			}

			range = 0;
		}

		// Different coloured lines at 1/4 and 3/4 marks in the lens
		if (liney == lenstop + lensheight / 4 || liney == lenstop + lensheight - lensheight / 4) {
			colour = 0xffffffff;
		}

		gDPSetColor(gdl++, G_SETENVCOLOR, colour);

		gdl = bviewCopyPixels(gdl, fb, liney, 5, liney, RANDOMFRAC() * range + 1, viewleft, viewwidth);
	}

	return gdl;
}
#else
const char var7f1b041cnb[] = "BinocularViewGfx";
const char var7f1b0430nb[] = ">> ";
const char var7f1b0434nb[] = " >>";
const char var7f1b0438nb[] = "%s %s:%03d";
const char var7f1b0444nb[] = "%s %s%s%4.2fh";
const char var7f1b0454nb[] = "";
const char var7f1b0458nb[] = "";
const char var7f1b045cnb[] = "%s %s%s%4.2fX";
const char var7f1b046cnb[] = "";
const char var7f1b0470nb[] = "";
const char var7f1b0474nb[] = " JMBC WIDE BAND SCANNER\n";

char directions[][3] = {
	{'n', '\0', '\0'},
	{'n', 'e',  '\0'},
	{'e', '\0', '\0'},
	{'s', 'e',  '\0'},
	{'s', '\0', '\0'},
	{'s', 'w',  '\0'},
	{'w', '\0', '\0'},
	{'n', 'w',  '\0'},
	{'n', '\0', '\0'},
};

GLOBAL_ASM(
glabel bviewDrawHorizonScanner
.late_rodata
glabel var7f1b04c0nb
.word 0x40490fdb
glabel var7f1b04c4nb
.word 0x40933333
glabel var7f1b04c8nb
.word 0x4465599a
.text
/*  f142640:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f142644:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f142648:	afb2004c */ 	sw	$s2,0x4c($sp)
/*  f14264c:	00809025 */ 	or	$s2,$a0,$zero
/*  f142650:	afb30050 */ 	sw	$s3,0x50($sp)
/*  f142654:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f142658:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f14265c:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f142660:	0c002b27 */ 	jal	viGetBackBuffer
/*  f142664:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f142668:	0c002fb9 */ 	jal	viGetViewTop
/*  f14266c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f142670:	0c002f9b */ 	jal	viGetViewHeight
/*  f142674:	afa20158 */ 	sw	$v0,0x158($sp)
/*  f142678:	0c002f97 */ 	jal	viGetViewWidth
/*  f14267c:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f142680:	0c002fb5 */ 	jal	viGetViewLeft
/*  f142684:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f142688:	3c10800a */ 	lui	$s0,0x800a
/*  f14268c:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f142690:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f142694:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f142698:	3c0f8008 */ 	lui	$t7,0x8008
/*  f14269c:	25ef20e4 */ 	addiu	$t7,$t7,0x20e4
/*  f1426a0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1426a4:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1426a8:	c4601bbc */ 	lwc1	$f0,0x1bbc($v1)
/*  f1426ac:	27ae00d0 */ 	addiu	$t6,$sp,0xd0
/*  f1426b0:	c46e1bc4 */ 	lwc1	$f14,0x1bc4($v1)
/*  f1426b4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1426b8:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1426bc:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1426c0:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1426c4:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1426c8:	8de10010 */ 	lw	$at,0x10($t7)
/*  f1426cc:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1426d0:	8de80014 */ 	lw	$t0,0x14($t7)
/*  f1426d4:	adc10010 */ 	sw	$at,0x10($t6)
/*  f1426d8:	99e1001a */ 	lwr	$at,0x1a($t7)
/*  f1426dc:	adc80014 */ 	sw	$t0,0x14($t6)
/*  f1426e0:	46000307 */ 	neg.s	$f12,$f0
/*  f1426e4:	0fc251b8 */ 	jal	atan2f
/*  f1426e8:	b9c1001a */ 	swr	$at,0x1a($t6)
/*  f1426ec:	3c014334 */ 	lui	$at,0x4334
/*  f1426f0:	44812000 */ 	mtc1	$at,$f4
/*  f1426f4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1426f8:	c42804c0 */ 	lwc1	$f8,0x4c0($at)
/*  f1426fc:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f142700:	3c028008 */ 	lui	$v0,0x8008
/*  f142704:	244220a0 */ 	addiu	$v0,$v0,0x20a0
/*  f142708:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f14270c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f142710:	3c04800b */ 	lui	$a0,0x800b
/*  f142714:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f142718:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f14271c:	29a10002 */ 	slti	$at,$t5,0x2
/*  f142720:	24110082 */ 	addiu	$s1,$zero,0x82
/*  f142724:	afab00a8 */ 	sw	$t3,0xa8($sp)
/*  f142728:	afa000a4 */ 	sw	$zero,0xa4($sp)
/*  f14272c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f142730:	24848780 */ 	addiu	$a0,$a0,-30848
/*  f142734:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f142738:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f14273c:	440a8000 */ 	mfc1	$t2,$f16
/*  f142740:	14200003 */ 	bnez	$at,.NB0f142750
/*  f142744:	afaa00cc */ 	sw	$t2,0xcc($sp)
/*  f142748:	10000234 */ 	beqz	$zero,.NB0f14301c
/*  f14274c:	02401025 */ 	or	$v0,$s2,$zero
.NB0f142750:
/*  f142750:	0c004e60 */ 	jal	strcpy
/*  f142754:	24a5041c */ 	addiu	$a1,$a1,0x41c
/*  f142758:	3c188007 */ 	lui	$t8,0x8007
/*  f14275c:	8f182d88 */ 	lw	$t8,0x2d88($t8)
/*  f142760:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f142764:	16780002 */ 	bne	$s3,$t8,.NB0f142770
/*  f142768:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f14276c:	afae00a8 */ 	sw	$t6,0xa8($sp)
.NB0f142770:
/*  f142770:	0fc53588 */ 	jal	optionsGetScreenSplit
/*  f142774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142778:	56620020 */ 	bnel	$s3,$v0,.NB0f1427fc
/*  f14277c:	8fa20154 */ 	lw	$v0,0x154($sp)
/*  f142780:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f142784:	00002825 */ 	or	$a1,$zero,$zero
/*  f142788:	00001825 */ 	or	$v1,$zero,$zero
/*  f14278c:	11e00003 */ 	beqz	$t7,.NB0f14279c
/*  f142790:	00002025 */ 	or	$a0,$zero,$zero
/*  f142794:	10000001 */ 	beqz	$zero,.NB0f14279c
/*  f142798:	02602825 */ 	or	$a1,$s3,$zero
.NB0f14279c:
/*  f14279c:	8e080068 */ 	lw	$t0,0x68($s0)
/*  f1427a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1427a4:	11000003 */ 	beqz	$t0,.NB0f1427b4
/*  f1427a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1427ac:	10000001 */ 	beqz	$zero,.NB0f1427b4
/*  f1427b0:	02601825 */ 	or	$v1,$s3,$zero
.NB0f1427b4:
/*  f1427b4:	8e090064 */ 	lw	$t1,0x64($s0)
/*  f1427b8:	11200003 */ 	beqz	$t1,.NB0f1427c8
/*  f1427bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1427c0:	10000001 */ 	beqz	$zero,.NB0f1427c8
/*  f1427c4:	02602025 */ 	or	$a0,$s3,$zero
.NB0f1427c8:
/*  f1427c8:	8e0a0070 */ 	lw	$t2,0x70($s0)
/*  f1427cc:	11400003 */ 	beqz	$t2,.NB0f1427dc
/*  f1427d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1427d4:	10000001 */ 	beqz	$zero,.NB0f1427dc
/*  f1427d8:	02601025 */ 	or	$v0,$s3,$zero
.NB0f1427dc:
/*  f1427dc:	00445821 */ 	addu	$t3,$v0,$a0
/*  f1427e0:	01636021 */ 	addu	$t4,$t3,$v1
/*  f1427e4:	01856821 */ 	addu	$t5,$t4,$a1
/*  f1427e8:	29a10002 */ 	slti	$at,$t5,0x2
/*  f1427ec:	54200003 */ 	bnezl	$at,.NB0f1427fc
/*  f1427f0:	8fa20154 */ 	lw	$v0,0x154($sp)
/*  f1427f4:	afb300a4 */ 	sw	$s3,0xa4($sp)
/*  f1427f8:	8fa20154 */ 	lw	$v0,0x154($sp)
.NB0f1427fc:
/*  f1427fc:	2442ffe2 */ 	addiu	$v0,$v0,-30
/*  f142800:	28410082 */ 	slti	$at,$v0,0x82
/*  f142804:	10200002 */ 	beqz	$at,.NB0f142810
/*  f142808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14280c:	00408825 */ 	or	$s1,$v0,$zero
.NB0f142810:
/*  f142810:	3c018006 */ 	lui	$at,0x8006
/*  f142814:	c4323b40 */ 	lwc1	$f18,0x3b40($at)
/*  f142818:	3c0141f0 */ 	lui	$at,0x41f0
/*  f14281c:	44812000 */ 	mtc1	$at,$f4
/*  f142820:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142824:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f142828:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f14282c:	44184000 */ 	mfc1	$t8,$f8
/*  f142830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142834:	330e0001 */ 	andi	$t6,$t8,0x1
/*  f142838:	166e0006 */ 	bne	$s3,$t6,.NB0f142854
/*  f14283c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f142840:	24a50430 */ 	addiu	$a1,$a1,0x430
/*  f142844:	0c004fc1 */ 	jal	sprintf
/*  f142848:	27a400bc */ 	addiu	$a0,$sp,0xbc
/*  f14284c:	10000006 */ 	beqz	$zero,.NB0f142868
/*  f142850:	8faf0154 */ 	lw	$t7,0x154($sp)
.NB0f142854:
/*  f142854:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f142858:	24a50434 */ 	addiu	$a1,$a1,0x434
/*  f14285c:	0c004fc1 */ 	jal	sprintf
/*  f142860:	27a400bc */ 	addiu	$a0,$sp,0xbc
/*  f142864:	8faf0154 */ 	lw	$t7,0x154($sp)
.NB0f142868:
/*  f142868:	8fa90158 */ 	lw	$t1,0x158($sp)
/*  f14286c:	afb100b0 */ 	sw	$s1,0xb0($sp)
/*  f142870:	05e10003 */ 	bgez	$t7,.NB0f142880
/*  f142874:	000f4043 */ 	sra	$t0,$t7,0x1
/*  f142878:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f14287c:	00014043 */ 	sra	$t0,$at,0x1
.NB0f142880:
/*  f142880:	01095021 */ 	addu	$t2,$t0,$t1
/*  f142884:	06210003 */ 	bgez	$s1,.NB0f142894
/*  f142888:	00115843 */ 	sra	$t3,$s1,0x1
/*  f14288c:	26210001 */ 	addiu	$at,$s1,0x1
/*  f142890:	00015843 */ 	sra	$t3,$at,0x1
.NB0f142894:
/*  f142894:	014b9823 */ 	subu	$s3,$t2,$t3
/*  f142898:	afb300b4 */ 	sw	$s3,0xb4($sp)
/*  f14289c:	02402025 */ 	or	$a0,$s2,$zero
/*  f1428a0:	0fc537b7 */ 	jal	textSetPrimColour
/*  f1428a4:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f1428a8:	8fa7014c */ 	lw	$a3,0x14c($sp)
/*  f1428ac:	8fac0150 */ 	lw	$t4,0x150($sp)
/*  f1428b0:	3c01f600 */ 	lui	$at,0xf600
/*  f1428b4:	326e03ff */ 	andi	$t6,$s3,0x3ff
/*  f1428b8:	00ec1821 */ 	addu	$v1,$a3,$t4
/*  f1428bc:	306d03ff */ 	andi	$t5,$v1,0x3ff
/*  f1428c0:	000dcb80 */ 	sll	$t9,$t5,0xe
/*  f1428c4:	03211825 */ 	or	$v1,$t9,$at
/*  f1428c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1428cc:	006f4025 */ 	or	$t0,$v1,$t7
/*  f1428d0:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f1428d4:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f1428d8:	30e503ff */ 	andi	$a1,$a3,0x3ff
/*  f1428dc:	00054b80 */ 	sll	$t1,$a1,0xe
/*  f1428e0:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f1428e4:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f1428e8:	012c6825 */ 	or	$t5,$t1,$t4
/*  f1428ec:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f1428f0:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f1428f4:	8fb90158 */ 	lw	$t9,0x158($sp)
/*  f1428f8:	02713021 */ 	addu	$a2,$s3,$s1
/*  f1428fc:	01202825 */ 	or	$a1,$t1,$zero
/*  f142900:	03387021 */ 	addu	$t6,$t9,$t8
/*  f142904:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f142908:	30ca03ff */ 	andi	$t2,$a2,0x3ff
/*  f14290c:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f142910:	000f4080 */ 	sll	$t0,$t7,0x2
/*  f142914:	00684825 */ 	or	$t1,$v1,$t0
/*  f142918:	00ab6025 */ 	or	$t4,$a1,$t3
/*  f14291c:	ac4c000c */ 	sw	$t4,0xc($v0)
/*  f142920:	ac490008 */ 	sw	$t1,0x8($v0)
/*  f142924:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f142928:	0fc537ce */ 	jal	text0f153838
/*  f14292c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f142930:	8fa300cc */ 	lw	$v1,0xcc($sp)
/*  f142934:	2401002d */ 	addiu	$at,$zero,0x2d
/*  f142938:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f14293c:	246d0016 */ 	addiu	$t5,$v1,0x16
/*  f142940:	01a1001a */ 	div	$zero,$t5,$at
/*  f142944:	0000c812 */ 	mflo	$t9
/*  f142948:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f14294c:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f142950:	27ae00d0 */ 	addiu	$t6,$sp,0xd0
/*  f142954:	00409025 */ 	or	$s2,$v0,$zero
/*  f142958:	030e3821 */ 	addu	$a3,$t8,$t6
/*  f14295c:	24a50438 */ 	addiu	$a1,$a1,0x438
/*  f142960:	27a4012c */ 	addiu	$a0,$sp,0x12c
/*  f142964:	27a600bc */ 	addiu	$a2,$sp,0xbc
/*  f142968:	0c004fc1 */ 	jal	sprintf
/*  f14296c:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f142970:	3c014080 */ 	lui	$at,0x4080
/*  f142974:	44816000 */ 	mtc1	$at,$f12
/*  f142978:	0fc019fe */ 	jal	menuGetCosOscFrac
/*  f14297c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142980:	3c017f1b */ 	lui	$at,0x7f1b
/*  f142984:	c42a04c4 */ 	lwc1	$f10,0x4c4($at)
/*  f142988:	3c017f1b */ 	lui	$at,0x7f1b
/*  f14298c:	c43204c8 */ 	lwc1	$f18,0x4c8($at)
/*  f142990:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f142994:	3c0f7f1b */ 	lui	$t7,0x7f1b
/*  f142998:	25ef0458 */ 	addiu	$t7,$t7,0x458
/*  f14299c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1429a0:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f1429a4:	24e70454 */ 	addiu	$a3,$a3,0x454
/*  f1429a8:	24a50444 */ 	addiu	$a1,$a1,0x444
/*  f1429ac:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f1429b0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1429b4:	27a40114 */ 	addiu	$a0,$sp,0x114
/*  f1429b8:	27a600bc */ 	addiu	$a2,$sp,0xbc
/*  f1429bc:	460021a1 */ 	cvt.d.s	$f6,$f4
/*  f1429c0:	0c004fc1 */ 	jal	sprintf
/*  f1429c4:	f7a60018 */ 	sdc1	$f6,0x18($sp)
/*  f1429c8:	0c003012 */ 	jal	viGetFovY
/*  f1429cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1429d0:	4480b000 */ 	mtc1	$zero,$f22
/*  f1429d4:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1429d8:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f1429dc:	46160032 */ 	c.eq.s	$f0,$f22
/*  f1429e0:	24e7046c */ 	addiu	$a3,$a3,0x46c
/*  f1429e4:	24a5045c */ 	addiu	$a1,$a1,0x45c
/*  f1429e8:	27a400fc */ 	addiu	$a0,$sp,0xfc
/*  f1429ec:	45010007 */ 	bc1t	.NB0f142a0c
/*  f1429f0:	27a600bc */ 	addiu	$a2,$sp,0xbc
/*  f1429f4:	3c014270 */ 	lui	$at,0x4270
/*  f1429f8:	44816000 */ 	mtc1	$at,$f12
/*  f1429fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142a00:	460c0032 */ 	c.eq.s	$f0,$f12
/*  f142a04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142a08:	45000004 */ 	bc1f	.NB0f142a1c
.NB0f142a0c:
/*  f142a0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f142a10:	44811000 */ 	mtc1	$at,$f2
/*  f142a14:	10000006 */ 	beqz	$zero,.NB0f142a30
/*  f142a18:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f142a1c:
/*  f142a1c:	46006203 */ 	div.s	$f8,$f12,$f0
/*  f142a20:	3c013f80 */ 	lui	$at,0x3f80
/*  f142a24:	44815000 */ 	mtc1	$at,$f10
/*  f142a28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142a2c:	460a4080 */ 	add.s	$f2,$f8,$f10
.NB0f142a30:
/*  f142a30:	3c087f1b */ 	lui	$t0,0x7f1b
/*  f142a34:	46001421 */ 	cvt.d.s	$f16,$f2
/*  f142a38:	25080470 */ 	addiu	$t0,$t0,0x470
/*  f142a3c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f142a40:	0c004fc1 */ 	jal	sprintf
/*  f142a44:	f7b00018 */ 	sdc1	$f16,0x18($sp)
/*  f142a48:	0fc5374a */ 	jal	text0f153628
/*  f142a4c:	02402025 */ 	or	$a0,$s2,$zero
/*  f142a50:	8fa900a4 */ 	lw	$t1,0xa4($sp)
/*  f142a54:	00409025 */ 	or	$s2,$v0,$zero
/*  f142a58:	2668fff9 */ 	addiu	$t0,$s3,-7
/*  f142a5c:	51200009 */ 	beqzl	$t1,.NB0f142a84
/*  f142a60:	8fb900a8 */ 	lw	$t9,0xa8($sp)
/*  f142a64:	8faa00a8 */ 	lw	$t2,0xa8($sp)
/*  f142a68:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f142a6c:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f142a70:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f142a74:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f142a78:	10000009 */ 	beqz	$zero,.NB0f142aa0
/*  f142a7c:	afad00f0 */ 	sw	$t5,0xf0($sp)
/*  f142a80:	8fb900a8 */ 	lw	$t9,0xa8($sp)
.NB0f142a84:
/*  f142a84:	8fae014c */ 	lw	$t6,0x14c($sp)
/*  f142a88:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f142a8c:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f142a90:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f142a94:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f142a98:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f142a9c:	afaf00f0 */ 	sw	$t7,0xf0($sp)
.NB0f142aa0:
/*  f142aa0:	0c002f77 */ 	jal	viGetWidth
/*  f142aa4:	afa800ec */ 	sw	$t0,0xec($sp)
/*  f142aa8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f142aac:	00104c03 */ 	sra	$t1,$s0,0x10
/*  f142ab0:	0c002f7b */ 	jal	viGetHeight
/*  f142ab4:	01208025 */ 	or	$s0,$t1,$zero
/*  f142ab8:	3c0a8008 */ 	lui	$t2,0x8008
/*  f142abc:	3c0b8008 */ 	lui	$t3,0x8008
/*  f142ac0:	8d6b2364 */ 	lw	$t3,0x2364($t3)
/*  f142ac4:	8d4a2368 */ 	lw	$t2,0x2368($t2)
/*  f142ac8:	240cff7f */ 	addiu	$t4,$zero,-129
/*  f142acc:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f142ad0:	02402025 */ 	or	$a0,$s2,$zero
/*  f142ad4:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f142ad8:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f142adc:	27a700bc */ 	addiu	$a3,$sp,0xbc
/*  f142ae0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f142ae4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f142ae8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f142aec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f142af0:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f142af4:	0fc541a6 */ 	jal	textRenderProjected
/*  f142af8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f142afc:	0c002f77 */ 	jal	viGetWidth
/*  f142b00:	00409025 */ 	or	$s2,$v0,$zero
/*  f142b04:	00028400 */ 	sll	$s0,$v0,0x10
/*  f142b08:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f142b0c:	0c002f7b */ 	jal	viGetHeight
/*  f142b10:	01a08025 */ 	or	$s0,$t5,$zero
/*  f142b14:	3c198008 */ 	lui	$t9,0x8008
/*  f142b18:	3c188008 */ 	lui	$t8,0x8008
/*  f142b1c:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f142b20:	8f392368 */ 	lw	$t9,0x2368($t9)
/*  f142b24:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f142b28:	240eff7f */ 	addiu	$t6,$zero,-129
/*  f142b2c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f142b30:	24e70474 */ 	addiu	$a3,$a3,0x474
/*  f142b34:	02402025 */ 	or	$a0,$s2,$zero
/*  f142b38:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f142b3c:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f142b40:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f142b44:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f142b48:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f142b4c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f142b50:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f142b54:	0fc541a6 */ 	jal	textRenderProjected
/*  f142b58:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f142b5c:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*  f142b60:	8fa9014c */ 	lw	$t1,0x14c($sp)
/*  f142b64:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f142b68:	000f4080 */ 	sll	$t0,$t7,0x2
/*  f142b6c:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f142b70:	00084080 */ 	sll	$t0,$t0,0x2
/*  f142b74:	010f4023 */ 	subu	$t0,$t0,$t7
/*  f142b78:	00084080 */ 	sll	$t0,$t0,0x2
/*  f142b7c:	010f4023 */ 	subu	$t0,$t0,$t7
/*  f142b80:	01091821 */ 	addu	$v1,$t0,$t1
/*  f142b84:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f142b88:	00409025 */ 	or	$s2,$v0,$zero
/*  f142b8c:	afa300f0 */ 	sw	$v1,0xf0($sp)
/*  f142b90:	afa400ec */ 	sw	$a0,0xec($sp)
/*  f142b94:	afa40064 */ 	sw	$a0,0x64($sp)
/*  f142b98:	0c002f77 */ 	jal	viGetWidth
/*  f142b9c:	afa3006c */ 	sw	$v1,0x6c($sp)
/*  f142ba0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f142ba4:	00105403 */ 	sra	$t2,$s0,0x10
/*  f142ba8:	0c002f7b */ 	jal	viGetHeight
/*  f142bac:	01408025 */ 	or	$s0,$t2,$zero
/*  f142bb0:	3c0b8008 */ 	lui	$t3,0x8008
/*  f142bb4:	3c0c8008 */ 	lui	$t4,0x8008
/*  f142bb8:	8d8c2364 */ 	lw	$t4,0x2364($t4)
/*  f142bbc:	8d6b2368 */ 	lw	$t3,0x2368($t3)
/*  f142bc0:	240dff7f */ 	addiu	$t5,$zero,-129
/*  f142bc4:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f142bc8:	02402025 */ 	or	$a0,$s2,$zero
/*  f142bcc:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f142bd0:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f142bd4:	27a70114 */ 	addiu	$a3,$sp,0x114
/*  f142bd8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f142bdc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f142be0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f142be4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f142be8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f142bec:	0fc541a6 */ 	jal	textRenderProjected
/*  f142bf0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f142bf4:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f142bf8:	00409025 */ 	or	$s2,$v0,$zero
/*  f142bfc:	53200008 */ 	beqzl	$t9,.NB0f142c20
/*  f142c00:	8fa800a8 */ 	lw	$t0,0xa8($sp)
/*  f142c04:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f142c08:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f142c0c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f142c10:	afaf00ec */ 	sw	$t7,0xec($sp)
/*  f142c14:	1000000e */ 	beqz	$zero,.NB0f142c50
/*  f142c18:	afb800f0 */ 	sw	$t8,0xf0($sp)
/*  f142c1c:	8fa800a8 */ 	lw	$t0,0xa8($sp)
.NB0f142c20:
/*  f142c20:	8faa014c */ 	lw	$t2,0x14c($sp)
/*  f142c24:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f142c28:	00084880 */ 	sll	$t1,$t0,0x2
/*  f142c2c:	01284821 */ 	addu	$t1,$t1,$t0
/*  f142c30:	00094880 */ 	sll	$t1,$t1,0x2
/*  f142c34:	01284823 */ 	subu	$t1,$t1,$t0
/*  f142c38:	00094880 */ 	sll	$t1,$t1,0x2
/*  f142c3c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f142c40:	00094840 */ 	sll	$t1,$t1,0x1
/*  f142c44:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f142c48:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f142c4c:	afac00ec */ 	sw	$t4,0xec($sp)
.NB0f142c50:
/*  f142c50:	0c002f77 */ 	jal	viGetWidth
/*  f142c54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142c58:	00028400 */ 	sll	$s0,$v0,0x10
/*  f142c5c:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f142c60:	0c002f7b */ 	jal	viGetHeight
/*  f142c64:	01a08025 */ 	or	$s0,$t5,$zero
/*  f142c68:	3c198008 */ 	lui	$t9,0x8008
/*  f142c6c:	3c188008 */ 	lui	$t8,0x8008
/*  f142c70:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f142c74:	8f392368 */ 	lw	$t9,0x2368($t9)
/*  f142c78:	240eff7f */ 	addiu	$t6,$zero,-129
/*  f142c7c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f142c80:	02402025 */ 	or	$a0,$s2,$zero
/*  f142c84:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f142c88:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f142c8c:	27a700fc */ 	addiu	$a3,$sp,0xfc
/*  f142c90:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f142c94:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f142c98:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f142c9c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f142ca0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f142ca4:	0fc541a6 */ 	jal	textRenderProjected
/*  f142ca8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f142cac:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f142cb0:	8fab00a8 */ 	lw	$t3,0xa8($sp)
/*  f142cb4:	00409025 */ 	or	$s2,$v0,$zero
/*  f142cb8:	11e00007 */ 	beqz	$t7,.NB0f142cd8
/*  f142cbc:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f142cc0:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f142cc4:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f142cc8:	252a000f */ 	addiu	$t2,$t1,0xf
/*  f142ccc:	afaa00ec */ 	sw	$t2,0xec($sp)
/*  f142cd0:	10000009 */ 	beqz	$zero,.NB0f142cf8
/*  f142cd4:	afa800f0 */ 	sw	$t0,0xf0($sp)
.NB0f142cd8:
/*  f142cd8:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f142cdc:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f142ce0:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f142ce4:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f142ce8:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f142cec:	018dc821 */ 	addu	$t9,$t4,$t5
/*  f142cf0:	afb900f0 */ 	sw	$t9,0xf0($sp)
/*  f142cf4:	afb800ec */ 	sw	$t8,0xec($sp)
.NB0f142cf8:
/*  f142cf8:	0c002f77 */ 	jal	viGetWidth
/*  f142cfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142d00:	00028400 */ 	sll	$s0,$v0,0x10
/*  f142d04:	00107403 */ 	sra	$t6,$s0,0x10
/*  f142d08:	0c002f7b */ 	jal	viGetHeight
/*  f142d0c:	01c08025 */ 	or	$s0,$t6,$zero
/*  f142d10:	3c0f8008 */ 	lui	$t7,0x8008
/*  f142d14:	3c088008 */ 	lui	$t0,0x8008
/*  f142d18:	8d082364 */ 	lw	$t0,0x2364($t0)
/*  f142d1c:	8def2368 */ 	lw	$t7,0x2368($t7)
/*  f142d20:	2409ff7f */ 	addiu	$t1,$zero,-129
/*  f142d24:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f142d28:	02402025 */ 	or	$a0,$s2,$zero
/*  f142d2c:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f142d30:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f142d34:	27a7012c */ 	addiu	$a3,$sp,0x12c
/*  f142d38:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f142d3c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f142d40:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f142d44:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f142d48:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f142d4c:	0fc541a6 */ 	jal	textRenderProjected
/*  f142d50:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f142d54:	0fc537a0 */ 	jal	text0f153780
/*  f142d58:	00402025 */ 	or	$a0,$v0,$zero
/*  f142d5c:	3c0ae700 */ 	lui	$t2,0xe700
/*  f142d60:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f142d64:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f142d68:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f142d6c:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f142d70:	0fc4f2e8 */ 	jal	bviewPrepareStaticRgba16
/*  f142d74:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f142d78:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f142d7c:	00409025 */ 	or	$s2,$v0,$zero
/*  f142d80:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f142d84:	51600003 */ 	beqzl	$t3,.NB0f142d94
/*  f142d88:	8fa30068 */ 	lw	$v1,0x68($sp)
/*  f142d8c:	afa400a4 */ 	sw	$a0,0xa4($sp)
/*  f142d90:	8fa30068 */ 	lw	$v1,0x68($sp)
.NB0f142d94:
/*  f142d94:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f142d98:	2670fff7 */ 	addiu	$s0,$s3,-9
/*  f142d9c:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f142da0:	00646021 */ 	addu	$t4,$v1,$a0
/*  f142da4:	258d0009 */ 	addiu	$t5,$t4,0x9
/*  f142da8:	020d082a */ 	slt	$at,$s0,$t5
/*  f142dac:	1020009a */ 	beqz	$at,.NB0f143018
/*  f142db0:	8fb800b0 */ 	lw	$t8,0xb0($sp)
/*  f142db4:	03387021 */ 	addu	$t6,$t9,$t8
/*  f142db8:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f142dbc:	25e80009 */ 	addiu	$t0,$t7,0x9
/*  f142dc0:	afa8006c */ 	sw	$t0,0x6c($sp)
/*  f142dc4:	06210003 */ 	bgez	$s1,.NB0f142dd4
/*  f142dc8:	00114883 */ 	sra	$t1,$s1,0x2
/*  f142dcc:	26210003 */ 	addiu	$at,$s1,0x3
/*  f142dd0:	00014883 */ 	sra	$t1,$at,0x2
.NB0f142dd4:
/*  f142dd4:	01335821 */ 	addu	$t3,$t1,$s3
/*  f142dd8:	afab0060 */ 	sw	$t3,0x60($sp)
/*  f142ddc:	afa90064 */ 	sw	$t1,0x64($sp)
/*  f142de0:	8fa30068 */ 	lw	$v1,0x68($sp)
.NB0f142de4:
/*  f142de4:	32180001 */ 	andi	$t8,$s0,0x1
/*  f142de8:	0203082a */ 	slt	$at,$s0,$v1
/*  f142dec:	10200058 */ 	beqz	$at,.NB0f142f50
/*  f142df0:	0213082a */ 	slt	$at,$s0,$s3
/*  f142df4:	14200056 */ 	bnez	$at,.NB0f142f50
/*  f142df8:	02136823 */ 	subu	$t5,$s0,$s3
/*  f142dfc:	44919000 */ 	mtc1	$s1,$f18
/*  f142e00:	3c013f00 */ 	lui	$at,0x3f00
/*  f142e04:	44813000 */ 	mtc1	$at,$f6
/*  f142e08:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f142e0c:	448d4000 */ 	mtc1	$t5,$f8
/*  f142e10:	3c013f80 */ 	lui	$at,0x3f80
/*  f142e14:	320c0001 */ 	andi	$t4,$s0,0x1
/*  f142e18:	44819000 */ 	mtc1	$at,$f18
/*  f142e1c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f142e20:	46062082 */ 	mul.s	$f2,$f4,$f6
/*  f142e24:	15800003 */ 	bnez	$t4,.NB0f142e34
/*  f142e28:	3c0500ff */ 	lui	$a1,0xff
/*  f142e2c:	10000003 */ 	beqz	$zero,.NB0f142e3c
/*  f142e30:	34a5ffff */ 	ori	$a1,$a1,0xffff
.NB0f142e34:
/*  f142e34:	3c057fff */ 	lui	$a1,0x7fff
/*  f142e38:	34a5ffff */ 	ori	$a1,$a1,0xffff
.NB0f142e3c:
/*  f142e3c:	46025401 */ 	sub.s	$f16,$f10,$f2
/*  f142e40:	3c013f40 */ 	lui	$at,0x3f40
/*  f142e44:	44812000 */ 	mtc1	$at,$f4
/*  f142e48:	3c014080 */ 	lui	$at,0x4080
/*  f142e4c:	46028003 */ 	div.s	$f0,$f16,$f2
/*  f142e50:	4616003c */ 	c.lt.s	$f0,$f22
/*  f142e54:	46000506 */ 	mov.s	$f20,$f0
/*  f142e58:	45020003 */ 	bc1fl	.NB0f142e68
/*  f142e5c:	4614903c */ 	c.lt.s	$f18,$f20
/*  f142e60:	46000507 */ 	neg.s	$f20,$f0
/*  f142e64:	4614903c */ 	c.lt.s	$f18,$f20
.NB0f142e68:
/*  f142e68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142e6c:	45020003 */ 	bc1fl	.NB0f142e7c
/*  f142e70:	4604a181 */ 	sub.s	$f6,$f20,$f4
/*  f142e74:	4600b506 */ 	mov.s	$f20,$f22
/*  f142e78:	4604a181 */ 	sub.s	$f6,$f20,$f4
.NB0f142e7c:
/*  f142e7c:	44814000 */ 	mtc1	$at,$f8
/*  f142e80:	3c01437f */ 	lui	$at,0x437f
/*  f142e84:	46083502 */ 	mul.s	$f20,$f6,$f8
/*  f142e88:	4616a03c */ 	c.lt.s	$f20,$f22
/*  f142e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142e90:	45020003 */ 	bc1fl	.NB0f142ea0
/*  f142e94:	4614b03c */ 	c.lt.s	$f22,$f20
/*  f142e98:	4600b506 */ 	mov.s	$f20,$f22
/*  f142e9c:	4614b03c */ 	c.lt.s	$f22,$f20
.NB0f142ea0:
/*  f142ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142ea4:	45020032 */ 	bc1fl	.NB0f142f70
/*  f142ea8:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f142eac:	44815000 */ 	mtc1	$at,$f10
/*  f142eb0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f142eb4:	3c014f00 */ 	lui	$at,0x4f00
/*  f142eb8:	460aa402 */ 	mul.s	$f16,$f20,$f10
/*  f142ebc:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f142ec0:	4459f800 */ 	cfc1	$t9,$31
/*  f142ec4:	44c6f800 */ 	ctc1	$a2,$31
/*  f142ec8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142ecc:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f142ed0:	4446f800 */ 	cfc1	$a2,$31
/*  f142ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142ed8:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f142edc:	50c00013 */ 	beqzl	$a2,.NB0f142f2c
/*  f142ee0:	44069000 */ 	mfc1	$a2,$f18
/*  f142ee4:	44819000 */ 	mtc1	$at,$f18
/*  f142ee8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f142eec:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f142ef0:	44c6f800 */ 	ctc1	$a2,$31
/*  f142ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142ef8:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f142efc:	4446f800 */ 	cfc1	$a2,$31
/*  f142f00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142f04:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f142f08:	14c00005 */ 	bnez	$a2,.NB0f142f20
/*  f142f0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142f10:	44069000 */ 	mfc1	$a2,$f18
/*  f142f14:	3c018000 */ 	lui	$at,0x8000
/*  f142f18:	10000007 */ 	beqz	$zero,.NB0f142f38
/*  f142f1c:	00c13025 */ 	or	$a2,$a2,$at
.NB0f142f20:
/*  f142f20:	10000005 */ 	beqz	$zero,.NB0f142f38
/*  f142f24:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f142f28:	44069000 */ 	mfc1	$a2,$f18
.NB0f142f2c:
/*  f142f2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142f30:	04c0fffb */ 	bltz	$a2,.NB0f142f20
/*  f142f34:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f142f38:
/*  f142f38:	44d9f800 */ 	ctc1	$t9,$31
/*  f142f3c:	0fc01990 */ 	jal	colourBlend
/*  f142f40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142f44:	00402825 */ 	or	$a1,$v0,$zero
/*  f142f48:	10000008 */ 	beqz	$zero,.NB0f142f6c
/*  f142f4c:	8fa30068 */ 	lw	$v1,0x68($sp)
.NB0f142f50:
/*  f142f50:	17000004 */ 	bnez	$t8,.NB0f142f64
/*  f142f54:	4600b506 */ 	mov.s	$f20,$f22
/*  f142f58:	3c05007f */ 	lui	$a1,0x7f
/*  f142f5c:	10000003 */ 	beqz	$zero,.NB0f142f6c
/*  f142f60:	34a57fff */ 	ori	$a1,$a1,0x7fff
.NB0f142f64:
/*  f142f64:	3c057fff */ 	lui	$a1,0x7fff
/*  f142f68:	34a5ffff */ 	ori	$a1,$a1,0xffff
.NB0f142f6c:
/*  f142f6c:	8fae0060 */ 	lw	$t6,0x60($sp)
.NB0f142f70:
/*  f142f70:	02401025 */ 	or	$v0,$s2,$zero
/*  f142f74:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f142f78:	120e0005 */ 	beq	$s0,$t6,.NB0f142f90
/*  f142f7c:	3c09fb00 */ 	lui	$t1,0xfb00
/*  f142f80:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f142f84:	006f4023 */ 	subu	$t0,$v1,$t7
/*  f142f88:	56080003 */ 	bnel	$s0,$t0,.NB0f142f98
/*  f142f8c:	ac490000 */ 	sw	$t1,0x0($v0)
.NB0f142f90:
/*  f142f90:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f142f94:	ac490000 */ 	sw	$t1,0x0($v0)
.NB0f142f98:
/*  f142f98:	0c004d84 */ 	jal	random
/*  f142f9c:	ac450004 */ 	sw	$a1,0x4($v0)
/*  f142fa0:	44822000 */ 	mtc1	$v0,$f4
/*  f142fa4:	02402025 */ 	or	$a0,$s2,$zero
/*  f142fa8:	8fa5015c */ 	lw	$a1,0x15c($sp)
/*  f142fac:	02003025 */ 	or	$a2,$s0,$zero
/*  f142fb0:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f142fb4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f142fb8:	04410005 */ 	bgez	$v0,.NB0f142fd0
/*  f142fbc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f142fc0:	3c014f80 */ 	lui	$at,0x4f80
/*  f142fc4:	44814000 */ 	mtc1	$at,$f8
/*  f142fc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142fcc:	46083180 */ 	add.s	$f6,$f6,$f8
.NB0f142fd0:
/*  f142fd0:	3c012f80 */ 	lui	$at,0x2f80
/*  f142fd4:	44815000 */ 	mtc1	$at,$f10
/*  f142fd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f142fdc:	44812000 */ 	mtc1	$at,$f4
/*  f142fe0:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f142fe4:	8faa014c */ 	lw	$t2,0x14c($sp)
/*  f142fe8:	8fab0150 */ 	lw	$t3,0x150($sp)
/*  f142fec:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f142ff0:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f142ff4:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f142ff8:	46049200 */ 	add.s	$f8,$f18,$f4
/*  f142ffc:	0fc4f168 */ 	jal	bviewCopyPixels
/*  f143000:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f143004:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f143008:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f14300c:	00409025 */ 	or	$s2,$v0,$zero
/*  f143010:	560cff74 */ 	bnel	$s0,$t4,.NB0f142de4
/*  f143014:	8fa30068 */ 	lw	$v1,0x68($sp)
.NB0f143018:
/*  f143018:	02401025 */ 	or	$v0,$s2,$zero
.NB0f14301c:
/*  f14301c:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f143020:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f143024:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f143028:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f14302c:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f143030:	8fb2004c */ 	lw	$s2,0x4c($sp)
/*  f143034:	8fb30050 */ 	lw	$s3,0x50($sp)
/*  f143038:	03e00008 */ 	jr	$ra
/*  f14303c:	27bd0160 */ 	addiu	$sp,$sp,0x160
);
#endif

/**
 * Draws the black part of the IR scanner, which obscures the edges of the
 * screen and creates the binocular effect.
 *
 * The two circles are "placed" at the 1/3 and 2/3 marks horizontally. The
 * screen is then iterated top to bottom, one line at a time, and draws
 * black rectangles on each line to fill in the area outside the circles.
 */
Gfx *bviewDrawIrBinoculars(Gfx *gdl)
{
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewtop = viGetViewTop();
	s32 viewleft = viGetViewLeft();
	s32 viewright = viewleft + viewwidth;
	s32 viewbottom = viewtop + viewheight;
	s32 leftx = viewleft + viewwidth / 3;
	s32 rightx = viewleft + (viewwidth * 2) / 3;
	s32 centrey = (viewtop + viewbottom) / 2;
	s32 radius = g_IrBinocularRadius;
	s32 sqradius = radius * radius;
	s32 y;
	u32 stack[2];

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColor(gdl++, 0, 0, 0x00, 0x00, 0x00, 0xff);

	for (y = viewtop; y < viewbottom; y++) {
		s32 ytocentre = centrey - y;
		s32 sqytocentre = ytocentre * ytocentre;

		if (sqytocentre < sqradius) {
			s32 xoffset = (viewwidth / 320.0f) * sqrtf(sqradius - sqytocentre);

			// Left side
			if (leftx - xoffset > viewleft) {
				gdl = bviewDrawIrRect(gdl, viewleft, y, leftx - xoffset, y + 1);
			}

			// Middle (top and bottom)
			if (leftx + xoffset < rightx - xoffset) {
				gdl = bviewDrawIrRect(gdl, leftx + xoffset, y, rightx - xoffset, y + 1);
			}

			// Right side
			if (rightx + xoffset < viewright) {
				gdl = bviewDrawIrRect(gdl, rightx + xoffset, y, viewright, y + 1);
			}
		} else {
			// Very top or bottom - whole line is black
#if VERSION >= VERSION_NTSC_1_0
			gdl = bviewDrawIrRect(gdl, viewleft, y, viewright, y + 1);
#else
			gdl = bviewDrawIrRect(gdl, viewleft, y, viewright - 1, y + 1);
#endif
		}
	}

	return gdl;
}

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
