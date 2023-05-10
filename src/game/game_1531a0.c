#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/gfxmemory.h"
#include "game/savebuffer.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

#define SPACE_WIDTH 5

#define BLENDTYPE_DIAGONAL   0x01
#define BLENDTYPE_VERTICAL   0x02
#define BLENDTYPE_WAVE       0x04
#define BLENDTYPE_MENU       0x08
#define BLENDTYPE_HORIZONTAL 0x10

static Gfx *text0f156a24(Gfx *gdl, s32 x, s32 y, struct fontchar *char1, s32 arg4, s32 arg5, s32 arg6, s32 arg7);

struct blendsettings {
	/*0x00*/ u8 types;
	/*0x04*/ u32 colour04;
	/*0x08*/ u32 colour08;
	/*0x0c*/ s32 diagrefx;
	/*0x10*/ s32 diagrefy;
	/*0x14*/ f32 diagtimer;
	/*0x18*/ u8 diagmode;
	/*0x1c*/ s32 backupdiagrefx;
	/*0x20*/ s32 backupdiagrefy;
	/*0x24*/ f32 backupdiagtimer;
	/*0x28*/ u8 backupdiagmode;
	/*0x29*/ u8 backupdiagtypes;
	/*0x2a*/ u8 backuptypes;
	/*0x2c*/ s32 vertrefy1;
	/*0x30*/ s32 vertrefy2;
	/*0x34*/ s32 vert34;
	/*0x38*/ s32 horizrefx1;
	/*0x3c*/ s32 horizrefx2;
	/*0x40*/ s32 horiz40;
	/*0x44*/ u32 colour44;
	/*0x48*/ u32 colour48;
	/*0x4c*/ s32 wave4c;
	/*0x50*/ s32 wave50;
	/*0x54*/ s32 wave54;
	/*0x58*/ u32 wavecolour1;
	/*0x5c*/ u32 wavecolour2;
	/*0x60*/ u32 menuweight;
};

struct blendsettings g_Blend;
Gfx *var800a4634;
u32 var800a463c;

s32 var8007fac4 = 0;
bool g_TextRotated90 = false;
s32 g_WrapIndentCount = 0;
s32 var8007fad0 = 1;

s32 var8007fad4 = -1;
u32 var8007fad8 = 0x00000000;
s32 var8007fadc = 0;
s32 var8007fae0 = 0;
u32 var8007fae4 = 0x00000000;
u32 var8007fae8 = 0x00000000;

struct font *g_FontNumeric = NULL;
struct fontchar *g_CharsNumeric = NULL;
struct font *g_FontHandelGothicXs = NULL;
struct fontchar *g_CharsHandelGothicXs = NULL;
struct font *g_FontHandelGothicSm = NULL;
struct fontchar *g_CharsHandelGothicSm = NULL;
struct font *g_FontHandelGothicMd = NULL;
struct fontchar *g_CharsHandelGothicMd = NULL;
struct font *g_FontHandelGothicLg = NULL;
struct fontchar *g_CharsHandelGothicLg = NULL;

u16 var8007fb3c[] = {
	0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00,
	0xff00, 0xff24, 0xff48, 0xff6c, 0xff90, 0xffb4, 0xffd8, 0xffff,
};

u16 var8007fb5c[] = {
	0xff00, 0xff58, 0xff74, 0xff90, 0xffac, 0xffc8, 0xffe4, 0xffff,
	0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
};

bool var8007fb9c = false;
s32 var8007fba0 = 0;
s32 var8007fba4 = -1;

void textSetRotation90(bool rotated)
{
	g_TextRotated90 = rotated;
}

void text0f1531dc(bool arg0)
{
	if (arg0) {
		var8007fad0 = 2;
	} else {
		var8007fad0 = 1;
	}
}

static void textLoadFont(u8 *romstart, u8 *romend, struct font **fontptr, struct fontchar **charsptr, bool monospace)
{
	extern u8 _fonthandelgothicsmSegmentRomStart;
	extern u8 _fonthandelgothicxsSegmentRomStart;
	extern u8 _fonthandelgothicmdSegmentRomStart;

	u32 len;
	s32 maxwidth;
	s32 i;
	struct font *font;
	struct fontchar *chars;

#define NUMCHARS() 94

	len = (u32)romend - (u32)romstart;
	font = mempAlloc(len, MEMPOOL_STAGE);
	chars = font->chars;

	dmaExec(font, (u32) romstart, len);

	// Convert pointers
	for (i = 0; i < NUMCHARS(); i++) {
		chars[i].pixeldata += (u32)font;
	}

	// If requested monospace, set all widths to the max, minus 1 for some reason
	if (monospace) {
		maxwidth = 0;

		for (i = 0; i < NUMCHARS(); i++) {
			if (chars[i].width > maxwidth) {
				maxwidth = chars[i].width;
			}
		}

		maxwidth--;

		for (i = 0; i < NUMCHARS(); i++) {
			chars[i].width = maxwidth;
		}
	}

	*fontptr = font;
	*charsptr = chars;

#if PAL
	if (romstart == &_fonthandelgothicsmSegmentRomStart
			|| romstart == &_fonthandelgothicxsSegmentRomStart
			|| romstart == &_fonthandelgothicmdSegmentRomStart) {
		// Increment the baseline of the pipe character.
		// It is suspected that the pipe character is used as a reference to set
		// the size for all other text, so changing this increases the line
		// height of these fonts.
		(*charsptr)['|' - 0x21].baseline++;
	}
#endif
}

void textReset(void)
{
	extern u8 _fontbankgothicSegmentRomStart,     _fontbankgothicSegmentRomEnd;
	extern u8 _fontzurichSegmentRomStart,         _fontzurichSegmentRomEnd;
	extern u8 _fonttahomaSegmentRomStart,         _fonttahomaSegmentRomEnd;
	extern u8 _fontnumericSegmentRomStart,        _fontnumericSegmentRomEnd;
	extern u8 _fonthandelgothicsmSegmentRomStart, _fonthandelgothicsmSegmentRomEnd;
	extern u8 _fonthandelgothicxsSegmentRomStart, _fonthandelgothicxsSegmentRomEnd;
	extern u8 _fonthandelgothicmdSegmentRomStart, _fonthandelgothicmdSegmentRomEnd;
	extern u8 _fonthandelgothiclgSegmentRomStart, _fonthandelgothiclgSegmentRomEnd;
	extern u8 _fontocramdSegmentRomStart,         _fontocramdSegmentRomEnd;
	extern u8 _fontocralgSegmentRomStart,         _fontocralgSegmentRomEnd;

	g_FontNumeric = NULL;
	g_FontHandelGothicXs = NULL;
	g_FontHandelGothicSm = NULL;
	g_FontHandelGothicMd = NULL;
	g_FontHandelGothicLg = NULL;

	g_CharsNumeric = NULL;
	g_CharsHandelGothicXs = NULL;
	g_CharsHandelGothicSm = NULL;
	g_CharsHandelGothicMd = NULL;
	g_CharsHandelGothicLg = NULL;

	var8007fac4 = 0;
	g_TextRotated90 = false;
	g_WrapIndentCount = 0;
	var8007fad4 = -1;
	var8007fad8 = 0;
	var8007fadc = 0;
	var8007fae0 = 0;
	var8007fae4 = 0;
	var8007fae8 = 0;

	if (g_Vars.stagenum == STAGE_TITLE) {
		textLoadFont(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);
		textLoadFont(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
		textLoadFont(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg, &g_CharsHandelGothicLg, false);
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		textLoadFont(&_fonthandelgothicxsSegmentRomStart, &_fonthandelgothicxsSegmentRomEnd, &g_FontHandelGothicXs, &g_CharsHandelGothicXs, false);
		textLoadFont(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);
		textLoadFont(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
		textLoadFont(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg, &g_CharsHandelGothicLg, false);
	} else {
		textLoadFont(&_fontnumericSegmentRomStart, &_fontnumericSegmentRomEnd, &g_FontNumeric, &g_CharsNumeric, false);
		textLoadFont(&_fonthandelgothicxsSegmentRomStart, &_fonthandelgothicxsSegmentRomEnd, &g_FontHandelGothicXs, &g_CharsHandelGothicXs, false);
		textLoadFont(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);
		textLoadFont(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
	}
}

Gfx *text0f153628(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);

	if (var8007fad8) {
		gDPSetTextureFilter(gdl++, G_TF_AVERAGE);
	} else {
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
	}

	return gdl;
}

Gfx *text0f153780(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetTextureLOD(gdl++, G_TL_LOD);

	return gdl;
}

Gfx *textSetPrimColour(Gfx *gdl, u32 colour)
{
	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);

	return gdl;
}

Gfx *text0f153838(Gfx *gdl)
{
	gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);

	return gdl;
}

Gfx *text0f153858(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2)
{
	gdl = textSetPrimColour(gdl, 0x00000000);

	gDPFillRectangle(gdl++, *x1, *y1, *x2, *y2);

	gdl = text0f153838(gdl);

	return gdl;
}

Gfx *text0f1538e4(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2)
{
	gdl = textSetPrimColour(gdl, 0x00000000);

	gDPFillRectangleScaled(gdl++, *x1, *y1, *x2, *y2);

	gdl = text0f153838(gdl);

	return gdl;
}

Gfx *text0f153990(Gfx *gdl, s32 left, s32 top, s32 width, s32 height)
{
	gdl = textSetPrimColour(gdl, 0x00000000);

	gDPFillRectangle(gdl++, left - 1, top - 1, width * var8007fad0 + left + 1, top + height + 1);

	gdl = text0f153838(gdl);

	return gdl;
}

Gfx *text0f153a34(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour)
{
	gdl = textSetPrimColour(gdl, colour);

	gDPFillRectangle(gdl++, x1, y1, x2, y2);

	gdl = text0f153838(gdl);

	return gdl;
}

Gfx *text0f153ab0(Gfx *gdl)
{
	Gfx *allocation;

	var8007fb9c = true;

	allocation = gfxAllocate(sizeof(Gfx) * 530);

	var800a4634 = allocation;

	gSPDisplayList(gdl++, var800a4634);

	gdl = func0f0d4c80(gdl);

	var800a4634 = func0f0d4a3c(var800a4634, 0);
	var8007fba4 = -1;

	return gdl;
}

void text0f153b40(void)
{
	var8007fb9c = false;

	gSPEndDisplayList(var800a4634++);
}

static void text0f153b6c(s32 arg0)
{
	if (arg0 != var8007fba4) {
		f32 tmp = g_Blend.diagtimer * g_Blend.diagtimer - (f32)((arg0 - g_Blend.diagrefy) * (arg0 - g_Blend.diagrefy));

		if (tmp > 0.0f) {
			var8007fba0 = sqrtf(tmp) + g_Blend.diagrefx;
		} else {
			var8007fba0 = 0;
		}

		var8007fba4 = arg0;
	}
}

void textSetDiagonalBlend(s32 x, s32 y, f32 timer, u8 mode)
{
	g_Blend.types |= BLENDTYPE_DIAGONAL;
	g_Blend.diagrefx = x;
	g_Blend.diagrefy = y;
	g_Blend.diagtimer = timer;
	g_Blend.diagmode = mode;
}

void textBackupDiagonalBlendSettings(void)
{
	g_Blend.backupdiagrefx = g_Blend.diagrefx;
	g_Blend.backupdiagrefy = g_Blend.diagrefy;
	g_Blend.backupdiagtimer = g_Blend.diagtimer;
	g_Blend.backupdiagmode = g_Blend.diagmode;
	g_Blend.backupdiagtypes = g_Blend.types & BLENDTYPE_DIAGONAL;
}

void textRestoreDiagonalBlendSettings(void)
{
	g_Blend.diagrefx = g_Blend.backupdiagrefx;
	g_Blend.diagrefy = g_Blend.backupdiagrefy;
	g_Blend.diagtimer = g_Blend.backupdiagtimer;
	g_Blend.diagmode = g_Blend.backupdiagmode;
	g_Blend.types |= g_Blend.backupdiagtypes;
}

void textSetHorizontalBlend(s32 x1, s32 x2, u32 arg2)
{
	g_Blend.types |= BLENDTYPE_HORIZONTAL;
	g_Blend.horizrefx1 = x1;
	g_Blend.horizrefx2 = x2;
	g_Blend.horiz40 = arg2;
}

void textBackupAndResetBlends(void)
{
	g_Blend.backuptypes = g_Blend.types;
	g_Blend.types = 0;
}

void textRestoreBlends(void)
{
	g_Blend.types = g_Blend.backuptypes;
}

void textSetWaveBlend(s32 arg0, s32 arg1, s32 cthresh)
{
	g_Blend.types |= BLENDTYPE_WAVE;
	g_Blend.wave4c = arg0;
	g_Blend.wave50 = arg1;
	g_Blend.wave54 = cthresh;
	g_Blend.wavecolour1 = 0x44444400;
	g_Blend.wavecolour2 = 0xffffff00;
}

void textSetMenuBlend(f32 arg0)
{
	g_Blend.types |= BLENDTYPE_MENU;
	g_Blend.menuweight = arg0 * arg0 * 110.0f;
}

void textSetWaveColours(u32 colour1, u32 colour2)
{
	g_Blend.wavecolour1 = colour1;
	g_Blend.wavecolour2 = colour2;
}

void textResetBlends(void)
{
	g_Blend.types = 0;
}

bool textHasDiagonalBlend(void)
{
	return (g_Blend.types & BLENDTYPE_DIAGONAL)
		&& (g_Blend.diagmode == DIAGMODE_FADEIN || g_Blend.diagmode == DIAGMODE_FADEOUT);
}

u32 textApplyProjectionColour(s32 x, s32 y, u32 colour)
{
	u32 stack[3];
	u32 result = colour;

	if (g_Blend.types & BLENDTYPE_DIAGONAL) {
		f32 weightf;
		f32 f12;
		f32 f14;
		f32 f16;
		f32 f18;

		if (x - g_Blend.diagrefx > -3000 && x - g_Blend.diagrefx < 3000
				&& y - g_Blend.diagrefy > -3000 && y - g_Blend.diagrefy < 3000) {
			f12 = sqrtf((x - g_Blend.diagrefx) * (x - g_Blend.diagrefx) + (y - g_Blend.diagrefy) * (y - g_Blend.diagrefy));
		} else {
			f12 = 3000.0f;
		}

		f14 = 1;
		f18 = 100;
		f16 = 0x2c;

		if (g_Blend.diagmode == 0) {
			if (g_Blend.diagtimer < f12) {
				result = 0;
			} else if (g_Blend.diagtimer - f14 < f12) {
				u32 intensity;
				weightf = (f12 - (g_Blend.diagtimer - f14)) / f14 * 255.0f;
				intensity = 255 - (u32) weightf;
				result = intensity << 8 | intensity | intensity << 16 | intensity << 24;
			} else if (g_Blend.diagtimer - (f14 + f16) < f12) {
				result = (((colour & 0xff) + 0xff) >> 1) | (colour & 0xffffff00);
			} else if ((g_Blend.diagtimer - (f14 + f18 + f16)) < f12) {
				u32 colour2 = (((colour & 0xff) + 0xff) / 2) | (colour & 0xffffff00);
				weightf = (f12 - (g_Blend.diagtimer - (f14 + f18 + f16))) / f18 * 255.0f;
				result = colourBlend(colour, colour2, 0xff - (u32) weightf);
			}
		} else if (g_Blend.diagmode == 2) {
			f16 = 0.0f;

			if (g_Blend.diagtimer < f12) {
				result = 0x00000000;
			} else if (g_Blend.diagtimer - f14 < f12) {
				weightf = (f12 - (g_Blend.diagtimer - f14)) / f14 * 255.0f;
				result = colourBlend(0x00000000, colour & 0xff, weightf);
			} else if (g_Blend.diagtimer - (f14 + f16) < f12) {
				result = colour & 0xff;
			} else if ((g_Blend.diagtimer - (f14 + f18 + f16)) < f12) {
				weightf = (f12 - (g_Blend.diagtimer - (f14 + f18 + f16))) / f18 * 255.0f;
				result = colourBlend(colour & 0xff, colour, weightf);
			}
		}
	}

	return result;
}

u32 text0f1543ac(s32 x, s32 y, u32 colourarg)
{
	f32 f14;
	f32 f18;
	f32 f16;
	u32 colour = colourarg;

	if (g_Blend.types & BLENDTYPE_MENU) {
		colour = (colourBlend(0x00000000, colour, g_Blend.menuweight) & 0xffffff00) | (colour & 0xff);
	}

	if (g_Blend.types & BLENDTYPE_VERTICAL) {
		s32 v0 = y - g_Blend.vertrefy1;
		s32 v1 = y - g_Blend.vertrefy2;

		if (v0 < 0) {
			v0 = -v0;
		}

		if (v1 < 0) {
			v1 = -v1;
		}

		if (v1 < v0) {
			v0 = v1;
		}

		if (g_Blend.vert34 >= v0) {
			colour = colourBlend(colour, 0x00000000, v0 * 255 / g_Blend.vert34);
		}
	}

	if (g_Blend.types & BLENDTYPE_HORIZONTAL) {
		s32 v0 = x - g_Blend.horizrefx1;
		s32 v1 = x - g_Blend.horizrefx2;

		if (v0 < 0) {
			v0 = 0;
		}

		if (v1 < 0) {
			v1 = -v1;
		}

		if (v1 < v0) {
			v0 = v1;
		}

		if (g_Blend.horiz40 >= v0) {
			colour = colourBlend(colour, 0x00000000, v0 * 255 / g_Blend.horiz40);
		}
	}

	if (g_Blend.types & BLENDTYPE_DIAGONAL) {
		f32 f12;
		u32 stack[3];
		f32 weightf;

		if (x - g_Blend.diagrefx > -3000 && x - g_Blend.diagrefx < 3000
				&& y - g_Blend.diagrefy > -3000 && y - g_Blend.diagrefy < 3000) {
			f12 = sqrtf((x - g_Blend.diagrefx) * (x - g_Blend.diagrefx) + (y - g_Blend.diagrefy) * (y - g_Blend.diagrefy));
		} else {
			f12 = 3000.0f;
		}

		f14 = 1;
		f18 = 100;
		f16 = 0x2c;

		if (g_Blend.diagmode == 0) {
			if (g_Blend.diagtimer < f12) {
				colour = 0;
			} else if (g_Blend.diagtimer - f14 < f12) {
				u32 intensity;
				weightf = (f12 - (g_Blend.diagtimer - f14)) / f14 * 255.0f;
				intensity = 255 - (u32) weightf;
				colour = intensity << 8 | intensity | intensity << 16 | intensity << 24;
			} else if (g_Blend.diagtimer - (f14 + f16) < f12) {
				colour = 0xffffffff;
			} else if (g_Blend.diagtimer - (f14 + f18 + f16) < f12) {
				u32 add;
				u32 mult;

				weightf = (f12 - (g_Blend.diagtimer - (f14 + f18 + f16))) / f18 * 255.0f;
				add = (u32) weightf * 255;
				mult = 255 - (u32) weightf;

				colour = ((((colour >> 24) & 0xff) * mult + add) >> 8) << 24
					| ((((colour >> 16) & 0xff) * mult + add) >> 8) << 16
					| ((((colour >> 8) & 0xff) * mult + add) >> 8) << 8
					| ((colour & 0xff) * mult + add) >> 8;
			}
		} else if (g_Blend.diagmode == 2) {
			f14 = 0.00f;
			f18 = 66.0f;
			f16 = 0.0f;

			if (g_Blend.diagtimer < f12) {
				colour = 0x00000000;
			} else if (g_Blend.diagtimer - f14 < f12) {
				f32 weightf = (f12 - (g_Blend.diagtimer - f14)) / f14 * 255.0f;
				colour = colourBlend(0x00000000, colour & 0xff, weightf);
			} else if (g_Blend.diagtimer - (f14 + f16) < f12) {
				colour &= 0xff;
			} else if (g_Blend.diagtimer - (f14 + f18 + f16) < f12) {
				f32 weightf = (f12 - (g_Blend.diagtimer - (f14 + f18 + f16))) / f18 * 255.0f;
				colour = colourBlend(0x00000000, colour, weightf);
			}
		} else {
			u32 alpha[4];

			s32 burncol = 0xffffff00;

			alpha[0] = colour & 0xff;
			f18 = 50.0f;
			f16 = 22.0f;

			if (g_Blend.diagtimer < f12) {
				colour = colourBlend(alpha[0], colour, 110);
			} else if (g_Blend.diagtimer - f14 < f12) {
				f32 weightf = (f12 - (g_Blend.diagtimer - f14)) / f14 * 255.0f;
				colour = colourBlend(
						colourBlend(burncol | (colour & 0xff), colour, 0xc0),
						colourBlend(alpha[0], colour, 110),
						255 - (u32) weightf);
			} else if (g_Blend.diagtimer - (f14 + f16) < f12) {
				u32 stack;
				colour = colourBlend(burncol | (colour & 0xff), colour, 0xc0);
			} else if (g_Blend.diagtimer - (f14 + f18 + f16) < f12) {
				f32 weightf = (f12 - (g_Blend.diagtimer - (f14 + f18 + f16))) / f18 * 255.0f;
				colour = colourBlend(
						colour,
						colourBlend(burncol | (colour & 0xff), colour, 0xc0),
						255 - (u32) weightf);
			}
		}
	}

	if (g_Blend.types & BLENDTYPE_WAVE) {
		u32 stack[2];
		f32 f0 = (s32)(g_Blend.wave4c - x + g_Blend.wave50 - y + 800);
		f0 = 4.0f * f0 / g_Blend.wave54;
		f0 -= (s32) (f0 * 0.25f) * 4.0f;
		f0 -= 1.0f;

		if (f0 > 1.0f) { \
			f0 = 2.0f - f0;
		}

		if (f0 < 0.0f) {
			s32 weight = 0x3c * (0 - f0);
			colour = colourBlend(g_Blend.wavecolour1 | (colour & 0xff), colour, weight);
		} else {
			s32 weight = 0x80 * f0;
			colour = colourBlend(g_Blend.wavecolour2 | (colour & 0xff), colour, weight);
		}
	}

	return colour;
}

static Gfx *text0f154ecc(Gfx *gdl, u32 arg1, u32 arg2)
{
	u32 colour = text0f1543ac(arg1, arg2, g_Blend.colour04);

	if (colour != g_Blend.colour44) {
		gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	}

	g_Blend.colour44 = colour;

	return gdl;
}

static Gfx *text0f154f38(Gfx *gdl, s32 *arg1, struct fontchar *curchar, struct fontchar *prevchar,
		struct font *font, f32 widthscale, f32 heightscale, f32 x, f32 y)
{
	s32 tmp1;
	s32 tmp2;
	s16 sp3e;
	s16 sp3c;
	s16 sp3a;
	s16 sp38;
	s16 sp36;
	s16 sp34;
	s16 sp32;
	s16 sp30;
	struct gfxvtx *vertices;
	u32 *colours;
	s32 tmp;

	tmp = (font->kerning[prevchar->kerningindex * 13 + curchar->kerningindex] + var8007fac4);
	*arg1 = *arg1 - tmp + 1;

	gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, curchar->pixeldata);
	gDPLoadSync(gdl++);
	gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, ((curchar->height * 8 + 17) >> 1) - 1, 2048);
	gDPPipeSync(gdl++);

	tmp1 = var8007fadc;
	tmp2 = var8007fae0;

	sp3e = (tmp1 + *arg1 * 4) * widthscale * 10.0f + 40.0f * x;
	sp3c = (tmp2 + curchar->baseline * 4) * heightscale * 10.0f + 40.0f * y;
	sp3a = (tmp1 + (*arg1 + (curchar->width + 1)) * 4) * widthscale * 10.0f + 40.0f * x;
	sp38 = (tmp2 + (curchar->baseline + (curchar->height + 1)) * 4) * heightscale * 10.0f + 40.0f * y;

	sp36 = 1;
	sp32 = 1;
	sp34 = curchar->width;
	sp30 = curchar->height;
	sp34 = 1 + ((sp34 + 1) << 6);
	sp30 = 1 + ((sp30 + 1) << 6);

	vertices = gfxAllocateVertices(4);

	colours = gfxAllocateColours(1);
	colours[0] = 0xff0000ff;

	vertices[0].z = -10;
	vertices[1].z = -10;
	vertices[2].z = -10;
	vertices[3].z = -10;

	vertices[0].colour = 0;
	vertices[1].colour = 0;
	vertices[2].colour = 0;
	vertices[3].colour = 0;

	vertices[0].x = sp3e / 4;
	vertices[0].y = sp3c / 4;
	vertices[0].s = sp36;
	vertices[0].t = sp32;
	vertices[1].x = sp3a / 4;
	vertices[1].y = sp3c / 4;
	vertices[1].s = sp34;
	vertices[1].t = sp32;
	vertices[2].x = sp3a / 4;
	vertices[2].y = sp38 / 4;
	vertices[2].s = sp34;
	vertices[2].t = sp30;
	vertices[3].x = sp3e / 4;
	vertices[3].y = sp38 / 4;
	vertices[3].s = sp36;
	vertices[3].t = sp30;

	gDPSetColorArray(gdl++, colours, 1);
	gDPSetVerticeArray(gdl++, vertices, 4);

	gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);

	*arg1 += curchar->width;

	return gdl;
}

Gfx *text0f1552d4(Gfx *gdl, f32 x, f32 y, f32 widthscale, f32 heightscale,
		char *text, struct fontchar *chars, struct font *font, u32 colour, s32 hdir, s32 vdir)
{
	s32 totalheight;
	u8 prevchar;
	s32 textwidth;
	s32 textheight;
	s32 lineheight;
	s32 relx;
	f32 *ptr;
	f32 fx;
	f32 fy;

	totalheight = 0;
	prevchar = 'H';
	relx = 0;

	lineheight = chars['['].height + chars['['].baseline;

	textMeasure(&textheight, &textwidth, text, chars, font, 0);

	ptr = &x;
	fx = *ptr - (widthscale - 1.0f) * textwidth * 0.5f * hdir;
	fy = y - (heightscale - 1.0f) * lineheight * 0.5f * vdir;

	if (fx);
	if (fy);

	gDPPipeSync(gdl++);
	gDPSetTextureLUT(gdl++, G_TT_IA16);

	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(var8007fb3c));

	gDPLoadSync(gdl++);
	gDPLoadTLUTCmd(gdl++, 6, 15);
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	gDPPipeSync(gdl++);

	if (text != NULL) {
		while (*text != '\0') {
			if (*text == ' ') {
				prevchar = 'H';
				text += 1;
				relx = relx + var8007fad0 * 5;
			} else if (*text == '\n') {
				prevchar = 'H';
				text += 1;

				if (var8007fad4 >= 0 && relx == 0) {
					totalheight += var8007fad4;
					relx = 0;
				} else {
					totalheight += lineheight;
					relx = 0;
				}
			} else if (*text < 0x80) {
				gdl = text0f154f38(gdl, &relx, &chars[*text - 0x21], &chars[prevchar - 0x21], font,
						widthscale, heightscale, fx, fy);
				prevchar = *text;
				text += 1;
			} else {
				u16 codepoint = (text[0] & 0x7f) << 7 | (text[1] & 0x7f);
				struct fontchar tmpchar = {0, 0, 12, 11};

				if (1);

				if (codepoint & 0x2000) {
					tmpchar.width = 15;
					tmpchar.height = 16;
				}

				if ((codepoint & 0x1fff) >= 0x3c8) {
					codepoint = 2;
				}

				tmpchar.index = codepoint + 0x80;
				tmpchar.pixeldata = (void *) lang0f16e3fc(codepoint);

				text += 2;
			}
		}
	}

	return gdl;
}

static Gfx *text0f15568c(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, struct fontchar *prevchar,
		struct font *font, s32 savedx, s32 savedy, s32 width, s32 height, s32 arg10)
{
	s32 tmp;
	s32 sp90;
	s32 xscale = var8007fad0;

	if (g_TextRotated90) {
		xscale = 1;
	}

	sp90 = *y + arg10;
	tmp = var8007fac4 + font->kerning[prevchar->kerningindex * 13 + curchar->kerningindex];
	*x -= (tmp - 1) * xscale;
	width *= xscale;

	if (g_TextRotated90 || (*x > 0 && *x <= g_ViBackData->x && sp90 + curchar->baseline <= g_ViBackData->y)) {
		if (savedx + width >= *x
				&& savedy + height >= curchar->baseline + sp90
				&& *x >= savedx
				&& curchar->baseline + sp90 + curchar->height >= savedy) {
			gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, curchar->pixeldata);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, ((curchar->height * 8 + 17) >> 1) - 1, 2048);
			gDPPipeSync(gdl++);

			if (g_Blend.types) {
				gdl = text0f154ecc(gdl, *x, *y + arg10);
			}

			if (1);

			if (*x + xscale * curchar->width <= savedx + width) {
				if (savedy <= curchar->baseline + sp90) {
					if (curchar->baseline + sp90 + curchar->height <= savedy + height) {
						if (g_TextRotated90) {
							gSPTextureRectangleFlip(gdl++,
									(sp90 - curchar->baseline - curchar->height * var8007fad0) * 4 + var8007fae0,
									*x * 4 + var8007fadc,
									(sp90 - curchar->baseline) * 4 + var8007fae0,
									(*x + curchar->width) * 4 + var8007fadc,
									G_TX_RENDERTILE,
									var8007fae8 + 32,
									((curchar->height - 1) << 5) + var8007fae4 + 32,
									1024,
									65536 - 1024 / var8007fad0);
						} else {
							gSPTextureRectangle(gdl++,
									*x * 4 + var8007fadc,
									(sp90 + curchar->baseline) * 4 + var8007fae0,
									(*x + curchar->width * var8007fad0) * 4 + var8007fadc,
									(sp90 + curchar->baseline + curchar->height) * 4 + var8007fae0,
									G_TX_RENDERTILE,
									var8007fae4 + 32,
									var8007fae8 + 32,
									1024 / var8007fad0,
									1024);

							if (var8007fb9c) {
								text0f153b6c(*y + arg10);

								if (var8007fba0 >= *x && *x + curchar->width * var8007fad0 >= var8007fba0) {
									var800a4634 = menugfxDrawPlane(var800a4634,
											var8007fba0,
											curchar->baseline + sp90,
											var8007fba0,
											curchar->baseline + sp90 + curchar->height,
											g_Blend.colour04,
											g_Blend.colour04,
											MENUPLANE_00);
								}

								if (var8007fba0 - 3 >= *x && *x + curchar->width * var8007fad0 >= var8007fba0 - 3) {
									var800a4634 = menugfxDrawPlane(var800a4634,
											var8007fba0,
											curchar->baseline + sp90,
											var8007fba0,
											curchar->baseline + sp90 + curchar->height,
											g_Blend.colour04,
											g_Blend.colour04,
											MENUPLANE_00);
								}
							}
						}
					} else if (savedy + height >= curchar->baseline + sp90) {
						gSPTextureRectangle(gdl++,
								*x * 4 + var8007fadc,
								(sp90 + curchar->baseline) * 4 + var8007fae0,
								(*x + curchar->width * var8007fad0) * 4 + var8007fadc,
								(savedy + height) * 4 + var8007fae0,
								G_TX_RENDERTILE,
								var8007fae4 + 32,
								var8007fae8 + 32,
								1024 / var8007fad0,
								1024);
					}
				} else {
					if (curchar->baseline + sp90 + curchar->height >= savedy) {
						gSPTextureRectangle(gdl++,
								*x * 4 + var8007fadc,
								savedy * 4 + var8007fae0,
								(*x + curchar->width * var8007fad0) * 4 + var8007fadc,
								(curchar->baseline + sp90 + curchar->height) * 4 + var8007fae0,
								G_TX_RENDERTILE,
								var8007fae4 + 32,
								((savedy - sp90 - curchar->baseline) << 5) + var8007fae8 + 32,
								1024 / var8007fad0,
								1024);
					}
				}
			}
		}
	}

	*x += curchar->width * xscale;

	return gdl;
}

u32 var8007fbd8 = 0;

void text0f156024(s32 arg0)
{
	var8007fbd8 = arg0;
}

void text0f156030(u32 colour)
{
	var800a463c = colour;
}

Gfx *textRenderProjected(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *chars, struct font *font,
		s32 colour, s32 width, s32 height, s32 arg9, s32 lineheight)
{
	s32 savedx;
	s32 savedy;
	u8 prevchar;
	s32 spb0;
	u32 colour2;
	u32 tmpcolour;
	s32 newx;
	s32 newy;
	f32 alpha;

	spb0 = var8007fad0;

	if (g_TextRotated90) {
		spb0 = 1;
	}

	if (var8007fbd8) {
		alpha = (1.0f - menuGetSinOscFrac(40.0f)) * 100.0f + 150.0f;
		newx = *x;
		newy = *y;
		tmpcolour = var800a463c;
		colour2 = (colour & 0xffffff00) | (u32) alpha;

		gdl = textRender(gdl, &newx, &newy, text, chars, font, colour2, tmpcolour, width, height, arg9, lineheight);
	}

	savedx = *x;
	savedy = *y;
	prevchar = 'H';

	if (lineheight == 0) {
		lineheight = chars['['].height + chars['['].baseline;
	}

	gDPPipeSync(gdl++);
	gDPSetTextureLUT(gdl++, G_TT_IA16);

	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(var8007fb3c));

	gDPLoadSync(gdl++);
	gDPLoadTLUTCmd(gdl++, 6, 15);
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	gDPPipeSync(gdl++);

	g_Blend.colour04 = colour;
	g_Blend.colour44 = colour;

	if (text != NULL) {
		while (*text != '\0') {
			if (*text == ' ') {
				prevchar = 'H';
				*x += spb0 * 5;
				text++;
			} else if (*text == '\n') {
				prevchar = 'H';
				text++;

				if (var8007fad4 >= 0 && savedx == *x) {
					*y += var8007fad4;
				} else {
					*y += lineheight;
				}

				*x = savedx;
			} else if (*text < 0x80) {
				gdl = text0f15568c(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21], font, savedx, savedy, width, height, arg9);
				prevchar = *text;
				text++;
			} else {
				u16 codepoint = ((*text & 0x7f) << 7) | (text[1] & 0x7f);
				struct fontchar tmpchar = {0, 0, 12, 11};

				if (codepoint & 0x2000) {
					tmpchar.width = 15;
					tmpchar.height = 16;
				}

				if ((codepoint & 0x1fff) >= 0x3c8) {
					codepoint = 2;
				}

				tmpchar.index = codepoint + 0x80;
				tmpchar.pixeldata = (void *)lang0f16e3fc(codepoint);

				gdl = text0f15568c(gdl, x, y, &tmpchar, &tmpchar, font, savedx, savedy, width, height, arg9);

				text += 2;
			}
		}
	}

	return gdl;
}

static Gfx *text0f1566cc(Gfx *gdl, u32 arg1, u32 arg2)
{
	u32 colour = text0f1543ac(arg1, arg2, g_Blend.colour04);

	if (colour != g_Blend.colour44) {
		gDPSetColor(gdl++, G_SETENVCOLOR, colour);
	}

	g_Blend.colour44 = colour;

	colour = (g_Blend.colour08 & 0xffffff00) | (text0f1543ac(arg1, arg2, g_Blend.colour08) & 0xff);

	if (colour != g_Blend.colour48) {
		gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	}

	g_Blend.colour48 = colour;

	return gdl;
}

static Gfx *textRenderChar(Gfx *gdl, s32 *x, s32 *y, struct fontchar *char1, struct fontchar *char2,
		struct font *font, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10)
{
	s32 tmp;
	s32 sp38;

	sp38 = *y + arg10;

	tmp = font->kerning[char2->kerningindex * 13 + char1->kerningindex] + var8007fac4;
	*x -= (tmp - 1) * var8007fad0;

	if (*x > 0
			&& *x <= g_ViBackData->x
			&& sp38 + char1->baseline <= g_ViBackData->y
			&& *x <= arg6 + arg8
			&& char1->baseline + sp38 <= arg7 + arg9
			&& *x >= arg6
			&& sp38 + char1->baseline + char1->height >= arg7) {
		if (g_Blend.types) {
			gdl = text0f1566cc(gdl, *x, *y + arg10);
		}

		gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, char1->pixeldata);
		gDPLoadSync(gdl++);
		gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, ((char1->height * 8 + 17) >> 1) - 1, 2048);
		gDPPipeSync(gdl++);

		gdl = text0f156a24(gdl, *x - var8007fad0, sp38 - 1, char1, arg6, arg7 - 1, arg8, arg9);
	}

	*x += char1->width * var8007fad0;

	return gdl;
}

static Gfx *text0f156a24(Gfx *gdl, s32 x, s32 y, struct fontchar *char1, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
	if (arg4 + arg6 >= char1->width + x + 2) {
		if (y + char1->baseline >= arg5) {
			if (arg5 + arg7 >= y + char1->baseline + char1->height + 2) {
				if (g_TextRotated90) {
					gSPTextureRectangleFlip(gdl++,
							((y - char1->baseline) - ((char1->height + 2) * var8007fad0)) * 4,
							x * 4,
							(y - char1->baseline) * 4,
							(x + char1->width + 2) * 4,
							G_TX_RENDERTILE,
							0,
							(char1->height + 1) << 5,
							1024 / var8007fad0,
							-1024);
				} else {
					gSPTextureRectangle(gdl++,
							x * 4,
							(y + char1->baseline) * 4,
							(x + char1->width * var8007fad0 + 2) * 4,
							(y + char1->baseline + char1->height + 2) * 4,
							G_TX_RENDERTILE,
							0,
							0,
							1024 / var8007fad0,
							1024);
				}
			} else {
				if (arg5 + arg7 >= y + char1->baseline) {
					gSPTextureRectangle(gdl++,
							x * 4,
							(y + char1->baseline) * 4,
							(x + char1->width * var8007fad0 + 2) * 4,
							(arg5 + arg7) * 4,
							G_TX_RENDERTILE,
							0,
							0,
							1024 / var8007fad0,
							1024);
				}
			}
		} else {
			if (y + char1->baseline + char1->height + 2 >= arg5) {
				gSPTextureRectangle(gdl++,
						x * 4,
						arg5 * 4,
						(x + char1->width * var8007fad0 + 2) * 4,
						(y + char1->baseline + char1->height + 2) * 4,
						G_TX_RENDERTILE,
						0,
						(arg5 - char1->baseline - y) << 5,
						1024 / var8007fad0,
						1024);
			}
		}
	}

	return gdl;
}

Gfx *textRender(Gfx *gdl, s32 *x, s32 *y, char *text,
		struct fontchar *chars, struct font *font, u32 arg6, u32 colour,
		s32 width, s32 height, u32 arg10, s32 lineheight)
{
	s32 savedx;
	s32 savedy;
	s32 prevchar;

	savedx = *x;
	savedy = *y;
	prevchar = 'H';

	if (lineheight == 0) {
		lineheight = chars['['].height + chars['['].baseline;
	}

	gDPPipeSync(gdl++);
	gDPSetTextureLUT(gdl++, G_TT_IA16);
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(&var8007fb5c));
	gDPLoadSync(gdl++);
	gDPLoadTLUTCmd(gdl++, 6, 31);

	// Use wrap
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, 1, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

	gDPSetTileSize(gdl++, 1, 0, 0, 0x007c, 0x007c);
	gDPSetCycleType(gdl++, G_CYC_2CYCLE);
	gDPSetCombineLERP(gdl++,
			ENVIRONMENT, PRIMITIVE, TEXEL1_ALPHA, PRIMITIVE, 0, 0, 0, TEXEL0,
			0, 0, 0, COMBINED, COMBINED, 0, ENVIRONMENT, 0);
	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	gDPSetEnvColorViaWord(gdl++, arg6);
	gDPPipeSync(gdl++);

	g_Blend.colour08 = colour;
	g_Blend.colour48 = colour;
	g_Blend.colour04 = arg6;
	g_Blend.colour44 = arg6;

	while (*text != '\0') {
		if (*text == ' ') {
			*x += var8007fad0 * 5;
			prevchar = 'H';
			text++;
		} else if (*text == '\n') {
			*x = savedx;
			*y += lineheight;
			prevchar = 'H';
			text++;
		} else if (*text < 0x80) {
			gdl = textRenderChar(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21],
					font, savedx, savedy, width * var8007fad0, height, arg10);
			prevchar = *text;
			text++;
		} else {
			u16 codepoint = ((*text & 0x7f) << 7) | (text[1] & 0x7f);
			struct fontchar sp74 = {0, 0, 12, 11};

			if (codepoint & 0x2000) {
				sp74.width = 15;
				sp74.height = 16;
			}

			if ((codepoint & 0x1fff) >= 0x3c8) {
				codepoint = 2;
			}

			sp74.index = codepoint + 0x80;
			sp74.pixeldata = (void *)lang0f16e3fc(codepoint);

			gdl = textRenderChar(gdl, x, y, &sp74, &sp74, font, savedx, savedy, width * var8007fad0, height, arg10);

			text += 2;
		}
	}

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);

	return gdl;
}

void textMeasure(s32 *textheight, s32 *textwidth, char *text, struct fontchar *font1, struct font *font2, s32 lineheight)
{
	char prevchar;
	char thischar;
	s32 longest;
	s32 tmp;

	prevchar = 'H';
	thischar = '\0';
	longest = 0;
	*textheight = 0;
	*textwidth = 0;

	if (lineheight == 0) {
		lineheight = font1['['].baseline + font1['['].height;
	}

	if (text) {
		while (*text != '\0') {
			if (*text == ' ') {
				// Space
				if (text[1] != '\n') {
					*textwidth += 5;
				}

				prevchar = 'H';
				text++;
			} else if (*text == '\n') {
				// Line break
				if (*textwidth > longest) {
					longest = *textwidth;
				}

				*textwidth = 0;
				*textheight += lineheight;
				text++;
			} else {
				if (*text < 0x80) {
					// Normal single-byte character
					thischar = *text;
					tmp = font2->kerning[font1[prevchar - 0x21].kerningindex * 13 + font1[thischar - 0x21].kerningindex] + var8007fac4 - 1;
					*textwidth = font1[thischar - 0x21].width + *textwidth - tmp;

					prevchar = *text;
					text++;
				} else if (*text < 0xc0) {
					// Multi-byte character
					tmp = font2->kerning[0] + var8007fac4 - 1;
					*textwidth = *textwidth - tmp + 11;
					text += 2;
				} else {
					// Multi-byte character
					tmp = font2->kerning[0] + var8007fac4 - 1;
					*textwidth = *textwidth - tmp + 15;
					text += 2;
				}
			}
		}
	}

	// @bug? Shouldn't this go at the very end of the function?
	*textwidth *= var8007fad0;

	if (longest > *textwidth) {
		*textwidth = longest;
	}
}

void textWrap(s32 wrapwidth, char *src, char *dst, struct fontchar *chars, struct font *font)
{
	s32 curlinewidth = 0;
	bool itfits;
	s32 wordlen;
	s32 wordwidth;
	s32 wordheight = 0;
	bool more = true;
	s32 v1;
	s32 i;
	u32 stack;
	char curword[32];

	while (more == true) {
		// Load the next word
		wordwidth = 0;
		wordlen = 0;
		v1 = 0;

		while (*src > ' ') {
			curword[wordlen] = *src;
			v1 += chars[*src - 0x21].width;
			src++;
			wordlen++;

			if (curword[wordlen - 1] >= 0x80) {
				curword[wordlen] = *src;
				v1 += chars[*src - 0x21].width;
				src++;
				wordlen++;
			}
		}

		curword[wordlen] = '\0';

		textMeasure(&wordheight, &wordwidth, curword, chars, font, 0);

		curlinewidth += wordwidth;

		if (curlinewidth <= wrapwidth) {
			itfits = true;
		} else {
			itfits = false;
		}

		if (*src == '\n') {
			// Write a new line and indent
			if (!itfits) {
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}
			}

			curlinewidth = 0;

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the original new line that was in src
			*dst = '\n';
			dst++;
		} else if (*src == ' ') {
			if (!itfits) {
				// Write a new line and indent
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}

				curlinewidth = g_WrapIndentCount * SPACE_WIDTH + wordwidth;
			}

			curlinewidth += SPACE_WIDTH;

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the trailing space
			*dst = ' ';
			dst++;
		} else if (*src == '\0') {
			more = false;

			if (!itfits) {
				// Write a new line and indent
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}
			}

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the null terminator
			*dst = '\0';
		}

		src++;
	}
}
