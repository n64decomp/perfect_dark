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

#define g_IrBinocularRadius 90

u8 g_IrScanlines[2][480];

s32 var8007f840 = 0;
u8 var8007f844 = 0;
u8 var8007f848 = 0;

static Gfx *bviewDrawIrRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2)
{
	gDPFillRectangle(gdl++, x1, y1, x2, y2);

	return gdl;
}

static Gfx *bviewCopyPixels(Gfx *gdl, u16 *fb, s32 top, u32 tile, s32 arg4, f32 arg5, s32 left, s32 width)
{
	u32 image;
	s32 width2;
	s32 numparts;
	s32 lrs[1];

	if (width > 320) {
		numparts = 2;
		lrs[0] = width / numparts;

		image = (u32) &fb[g_ViBackData->x * top + left] & 0x00ffffff;

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

		image = (u32) &fb[g_ViBackData->x * top + left] & 0x00ffffff;

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

		image = (u32) &fb[g_ViBackData->x * top + left] & 0x00ffffff;

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

static Gfx *bviewDrawFisheyeRect(Gfx *gdl, s32 arg1, f32 arg2, s32 arg3, s32 arg4)
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

static Gfx *bviewPrepareStaticRgba16(Gfx *gdl, u32 colour, u32 alpha)
{
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

static Gfx *bviewPrepareStaticI8(Gfx *gdl, u32 colour, u32 alpha)
{
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
	u16 *fb = g_ViFrontData->fb;
	s32 viewtop = g_ViBackData->viewtop;
	s32 viewheight = g_ViBackData->viewy;
	f32 fxxx;
	f32 fyyy;
	s32 viewwidth = g_ViBackData->viewx;
	s32 viewleft = g_ViBackData->viewleft;
	f32 somefloat;
	s32 newalpha;
	s32 i;

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

	gDPPipeSync(gdl++);

	somefloat = (viewheight - viewheight / 1) * 0.5f;
	gdl = bviewPrepareStaticRgba16(gdl, colour, newalpha);

	for (i = viewtop; i < viewtop + viewheight; i++) {
		gdl = bviewCopyPixels(gdl, fb, viewtop + (s32)somefloat, 5, i, 1, viewleft, viewwidth);
		somefloat += 1.0f;
	}

	return gdl;
}

/**
 * Draw static for the Infiltration intro cutscene and Slayer rockets.
 */
Gfx *bviewDrawStatic(Gfx *gdl, u32 arg1, s32 arg2)
{
	u16 *fb = g_ViFrontData->fb;
	s32 viewtop = g_ViBackData->viewtop;
	s32 viewheight = g_ViBackData->viewy;
	s32 viewwidth = g_ViBackData->viewx;
	s32 viewleft = g_ViBackData->viewleft;
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
	u16 *fb = g_ViBackData->fb;
	s32 viewtop = g_ViBackData->viewtop;
	s32 viewheight = g_ViBackData->viewy;
	s32 viewwidth = g_ViBackData->viewx;
	s32 y;
	s32 viewleft = g_ViBackData->viewleft;
	f32 angle = 0.52359879016876f;
	s32 offset = (s32)(g_20SecIntervalFrac * 600.0f) % 12;
	f32 increment;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

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
	u16 *fb = g_ViBackData->fb;
	s32 viewtop = g_ViBackData->viewtop;
	s32 viewheight = g_ViBackData->viewy;
	s32 y;
	s32 viewwidth = g_ViBackData->viewx;
	s32 viewleft = g_ViBackData->viewleft;
	s32 offset = (s32)(g_20SecIntervalFrac * 600.0f) % 12;
	u32 stack;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

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
	u16 *fb = g_ViFrontData->fb;
	s32 viewtop = g_ViBackData->viewtop;
	s32 viewheight = g_ViBackData->viewy;
	s32 viewwidth = g_ViBackData->viewx;
	s32 viewleft = g_ViBackData->viewleft;
	f32 somefloat;
	s32 i;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	gDPPipeSync(gdl++);

	somefloat = (viewheight - viewheight / arg4) * 0.5f;

	gdl = bviewPrepareStaticRgba16(gdl, colour, alpha);

	for (i = viewtop; i < viewtop + viewheight; i++) {
		gdl = bviewCopyPixels(gdl, fb, (s32)somefloat + viewtop, 5, i, arg3, viewleft, viewwidth);
		somefloat += 1.0f / arg4;
	}

	return gdl;
}

static f32 bview0f142d74(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
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
	u16 *fb = g_ViBackData->fb;
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

	f32 tmp;

	viewtop = g_ViBackData->viewtop;
	viewheight = g_ViBackData->viewy;
	halfheight = viewheight * 0.5f;
	sqhalfheight = halfheight * halfheight;
	f26 = -(halfheight + halfheight) / viewheight;
	viewwidth = g_ViBackData->viewx;
	viewleft = g_ViBackData->viewleft;
	startupfrac = 1.0f;
	s2 = 0;

	starting = (startuptimer60 < TICKS(50));

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

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

	return gdl;
}

/**
 * Draw a black rectangle to the side of the circular fisheye lens.
 *
 * These are each 1px high, and go from the edge of the circle to the edge of
 * the screen. There is one drawn on every row on both sides.
 */
static Gfx *bviewDrawEyespySideRect(Gfx *gdl, s32 *points, u8 r, u8 g, u8 b, u8 alpha)
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
	s32 viewleft = g_ViBackData->viewleft;
	s32 viewtop = g_ViBackData->viewtop;
	s32 viewwidth = g_ViBackData->viewx;
	s32 viewheight = g_ViBackData->viewy;
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
	bool vsplit = false;

	if (g_Vars.currentplayer->eyespy == NULL
			|| g_Vars.currentplayer->eyespy->prop == NULL
			|| g_Vars.currentplayer->eyespy->prop->chr == NULL) {
		return gdl;
	}

	chr = g_Vars.currentplayer->eyespy->prop->chr;

	if (g_ScreenSplit == SCREENSPLIT_VERTICAL && PLAYERCOUNT() >= 2) {
		vsplit = true;
	}

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

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		gdl = textSetPrimColour(gdl, 0x00ff0028);
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		gdl = textSetPrimColour(gdl, 0x2244ffa0);
	} else {
		gdl = textSetPrimColour(gdl, 0xff3300a0);
	}

	if (!vsplit) {
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

	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// "H/M"
	sprintf(text, "%s %s%4.2f", langGet(L_MISC_074), "", g_Vars.currentplayer->eyespy->height * 0.01f);
	savedy += 9;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// "Y/D"
	sprintf(text, "%s %d", langGet(L_MISC_075), (s32)g_Vars.currentplayer->eyespy->theta);
	savedy += 9;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// "P/D"
	sprintf(text, "%s %d", langGet(L_MISC_076), (s32)g_Vars.currentplayer->eyespy->verta);
	savedy += 9;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// "CI 2023"
	sprintf(text, "%s", langGet(L_MISC_077));
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

	x = (vsplit ? -3 : 0) + viewleft + 25 * scale + 5;
	y = (vsplit ? 18 : 0) + viewbottom - 41;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		sprintf(text, "%s", langGet(L_MISC_078)); // "YKK: 95935"
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		sprintf(text, "%s", langGet(L_MISC_208)); // "JM: 201172"
	} else {
		sprintf(text, "%s", langGet(L_MISC_217)); // "BNC: 15877"
	}

	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

	x = viewleft + 25 * scale + (vsplit ? -3 : 0) + 5;
	y = viewbottom + (vsplit ? 20 : 0) - 34;

	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		// "CAMSPY"
		sprintf(text, "   %s", langGet(L_MISC_079));
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x = viewright - scale * 53 - 25;
		y = (vsplit ? -13 : 0) + viewtop + 27;
		x2 = x + textwidth; \
		y2 = y + textheight; \
		gdl = text0f153858(gdl, &x, &y, &x2, &y2);
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		// "DRUGSPY"
		sprintf(text, "   %s", langGet(L_MISC_468));
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x = viewright - scale * 53 - 25;
		y = (vsplit ? -13 : 0) + viewtop + 27;
		x2 = x + textwidth; \
		y2 = y + textheight; \
		gdl = text0f153858(gdl, &x, &y, &x2, &y2);
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);
	} else {
		// "BOMBSPY"
		sprintf(text, "   %s", langGet(L_MISC_469));
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x = viewright - scale * 59 - 25;
		y = (vsplit ? -13 : 0) + viewtop + 27;
		x2 = x + textwidth; \
		y2 = y + textheight; \
		gdl = text0f153858(gdl, &x, &y, &x2, &y2);
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);
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
	x = (vsplit ? 3 : 0) + viewright - scale * 46 - 25;
	y = (vsplit ? -11 : 0) + viewtop + 34;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// Gyrostat/dartammo text
	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY
			|| g_Vars.currentplayer->eyespy->mode == EYESPYMODE_BOMBSPY) {
		sprintf(text, "%s", langGet(L_MISC_081)); // "GYROSTAT"
	} else {
		sprintf(text, "%s", langGet(L_MISC_206)); // "DARTAMMO"
	}

	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = (vsplit ? -35 : 0) + (viewright - viewwidth / 5.0f - 3 - (scale * 5 - 5));
	y = (vsplit ? -2 : 0) + viewbottom - 12;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, g_ViBackData->x, g_ViBackData->y, 0, 0);

	gdl = text0f153838(gdl);

	{
		s8 contpadnum = g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].contpad1;
		u16 buttonsdown = joyGetButtons(contpadnum, 0xffff);
		u16 buttonsthisframe = joyGetButtonsPressedThisFrame(contpadnum, 0xffff);
		s8 cstickx = joyGetStickX(contpadnum);
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

		if (!vsplit) {
			xpos = (scale == 2) ? -76 : -85;

			// Up
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20; \
				if (buttonsdown & (0 | U_CBUTTONS)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (0 | U_CBUTTONS)) { \
					brightness += 20; \
				} \
				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff); \
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (0 | U_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (0 | U_CBUTTONS)) {
					brightness += 63; \
				} \
				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (0 | U_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (0 | U_CBUTTONS)) {
					brightness += 20; \
				} \
				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Down
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (0 | D_CBUTTONS)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (0 | D_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (0 | D_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (0 | D_CBUTTONS)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (0 | D_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (0 | D_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Left
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (0 | L_CBUTTONS)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (0 | L_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (0 | L_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (0 | L_CBUTTONS)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (0 | L_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (0 | L_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Right
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (0 | R_CBUTTONS)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (0 | R_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (0 | R_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (0 | R_CBUTTONS)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (0 | R_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (0 | R_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Shoulder buttons
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (0 | R_TRIG)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (0 | R_TRIG)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (0 | R_TRIG)) {
					brightness += 63;
				}

				if (buttonsthisframe & (0 | R_TRIG)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (0 | R_TRIG)) {
					brightness += 20;
				}

				if (buttonsthisframe & (0 | R_TRIG)) {
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

		if (!vsplit) {
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

		if (!vsplit) {
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
			if (!vsplit) {
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
			if (!vsplit) {
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
			s32 width;

			brightness2 = 255;
			width = scale * 30;

			y = viewbottom - 13;
			x = viewright - viewwidth / 5.0f + 5;

			if (vsplit) {
				x -= 12;
				y -= 3;
				width = 15;
			}

			for (i = 0; i < 8; i++) {
				if (i >= g_Vars.currentplayer->eyespydarts) {
					brightness2 = 0x88;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness2, 0xff);
				gDPFillRectangle(gdl++, x, y - 4, x + width, y);

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

u8 var8007f878 = 0;

Gfx *bviewDrawNvLens(Gfx *gdl)
{
	u16 *fb = g_ViBackData->fb;
	s32 viewheight = g_ViBackData->viewy;
	s32 viewwidth = g_ViBackData->viewx;
	s32 viewtop = g_ViBackData->viewtop;
	s32 viewleft = g_ViBackData->viewleft;
	s32 viewbottom = viewtop + viewheight;
	s32 roomvalue;
	s32 y;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

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

Gfx *bviewDrawIrLens(Gfx *gdl)
{
	s32 i;
	s32 fadeincrement;
	u16 *fb = g_ViBackData->fb;
	s32 viewheight = g_ViBackData->viewy;
	s32 viewwidth = g_ViBackData->viewx;
	s32 viewtop = g_ViBackData->viewtop;
	s32 viewleft = g_ViBackData->viewleft;
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

	viewright = viewleft + viewwidth;
	viewcentrex = (viewleft + viewright) / 2;

	outerradius = g_IrBinocularRadius;
	innerradius = g_IrBinocularRadius / 3;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	viewbottom = viewtop + viewheight;
	viewcentrey = (viewtop + viewbottom) / 2;
	scantop = viewcentrey - outerradius;
	scanbottom = viewcentrey + outerradius;
	i = viewheight;

	if (scantop > viewbottom) {
		scantop = viewbottom;
	}

	if (scanbottom > viewbottom) {
		scanbottom = viewbottom;
	}

	if (scantop < viewtop) {
		scantop = viewtop;
	}

	if (scanbottom < viewtop) {
		scanbottom = viewtop;
	}

	scanincrement = (f32) scanrate * i / 240.0f;
	fadeincrement = (f32) faderate * i / 240.0f;

	if (g_Vars.currentplayer->fslastradius != outerradius) {
		for (i = 0; i < 480; i++) {
			g_IrScanlines[g_Vars.currentplayernum][i] = 0xff;
		}

		g_Vars.currentplayer->fsscanline = 0;
		g_Vars.currentplayer->fslastradius = outerradius;
	}

	// Increment the scanline
	for (i = 0; i < scanincrement; i++) {
		if (g_Vars.currentplayer->fsscanline >= scanbottom) {
			g_Vars.currentplayer->fsscanline = scantop;
		}

		g_IrScanlines[g_Vars.currentplayernum][g_Vars.currentplayer->fsscanline] = 0xff - i;

		g_Vars.currentplayer->fsscanline++;
	}

	var8009caec = 0xff;
	var8009caef = 0xde;
	var8009caf0 = 0xde;

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, 0xffffffff, 255);

	sqinnerradius = innerradius * innerradius;

	for (i = scantop; i < scanbottom; i++) {
		if (i & 1) {
			red = g_IrScanlines[g_Vars.currentplayernum][i];
		} else {
			red = g_IrScanlines[g_Vars.currentplayernum][i] * 2 / 3;
		}

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

		if (g_IrScanlines[g_Vars.currentplayernum][i] > fadeincrement) {
			g_IrScanlines[g_Vars.currentplayernum][i] -= fadeincrement;
		}
	}

	if (g_Menus[g_Vars.currentplayerstats->mpindex].curdialog == NULL) {
		gdl = bviewDrawMotionBlur(gdl, 0xff000000, 0x40);
	}

	return gdl;
}

Gfx *bviewDrawHorizonScanner(Gfx *gdl)
{
	u16 *fb = g_ViBackData->fb;
	s32 viewtop = g_ViBackData->viewtop;
	s32 viewheight = g_ViBackData->viewy;
	s32 viewwidth = g_ViBackData->viewx;
	s32 viewleft = g_ViBackData->viewleft;
	char directiontext[32];
	char hertztext[24];
	char zoomtext[24];
	char nametext[52];
	f32 lookx = g_Vars.currentplayer->cam_look.x;
	f32 lookz = g_Vars.currentplayer->cam_look.z;
	s32 x;
	s32 y;

	static char directions[][3] = {
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

	if (g_ScreenSplit == SCREENSPLIT_VERTICAL && PLAYERCOUNT() >= 2) {
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

	fovy = g_ViBackData->fovy;

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
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// Product name
	strcpy(nametext, " JMBC");

	if (!vsplit) {
		strcat(nametext, " WIDE BAND");
	}

	strcat(nametext, " SCANNER\n");

	gdl = textRenderProjected(gdl, &x, &y, nametext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// Hertz
	x = viewleft + 75 * scale;
	y = lenstop + lensheight + 1;
	gdl = textRenderProjected(gdl, &x, &y, hertztext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// Zoom level
	if (vsplit) {
		x = viewleft + 75 * scale;
		y = lenstop + lensheight + 8;
	} else {
		x = viewleft + 150 * scale;
		y = lenstop + lensheight + 1;
	}

	gdl = textRenderProjected(gdl, &x, &y, zoomtext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// Direction
	if (vsplit) {
		x = viewleft + 75 * scale;
		y = lenstop + lensheight + 15;
	} else {
		x = viewleft + 225 * scale;
		y = lenstop + lensheight + 1;
	}

	gdl = textRenderProjected(gdl, &x, &y, directiontext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, g_ViBackData->x, g_ViBackData->y, 0, 0);
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
	s32 viewheight = g_ViBackData->viewy;
	s32 viewwidth = g_ViBackData->viewx;
	s32 viewtop = g_ViBackData->viewtop;
	s32 viewleft = g_ViBackData->viewleft;
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
			gdl = bviewDrawIrRect(gdl, viewleft, y, viewright, y + 1);
		}
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
