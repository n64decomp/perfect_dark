#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/gfxmemory.h"
#include "game/savebuffer.h"
#include "game/text.h"
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

#if VERSION == VERSION_JPN_FINAL
s32 g_JpnKerning[13 * 13];
#endif

struct blendsettings g_Blend;
Gfx *g_TextHoloRayGdl;
Gfx *g_TextHoloRayGdlEnd;
#if VERSION == VERSION_JPN_FINAL
struct fontchar g_TmpJpnChar;
#endif
u32 var800a463c;

#if VERSION == VERSION_JPN_FINAL
s32 var800800f0jf = 0;
s32 g_UiScaleX = 1;
bool var80080104jf = false;
s32 g_TextCharOverlap = 0;
bool g_TextRotated90 = false;
s32 g_WrapIndentCount = 0;
s32 g_TextScaleX = 1;
s32 var80080108jf = 1;
#else
s32 g_UiScaleX = 1;
s32 g_TextCharOverlap = 0;
bool g_TextRotated90 = false;
s32 g_WrapIndentCount = 0;
s32 g_TextScaleX = 1;
#endif

s32 g_TextParaOverlap = -1; // higher value reduces margin between paragraphs
bool g_TextUseAverageSampling = false;
s32 var8007fadc = 0;
s32 var8007fae0 = 0;
u32 var8007fae4 = 0;
u32 var8007fae8 = 0;
u32 var8007faec = 0;
u32 var8007faf0 = 0;

struct font *g_FontTahoma2 = NULL;
struct fontchar *g_FontTahoma1 = NULL;
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

u32 var8007fb24 = 0;
u32 var8007fb28 = 0;
u32 var8007fb2c = 0;
u32 var8007fb30 = 0;
u32 var8007fb34 = 0;
u32 var8007fb38 = 0;

u16 var8007fb3c[] = {
	0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00,
	0xff00, 0xff24, 0xff48, 0xff6c, 0xff90, 0xffb4, 0xffd8, 0xffff,
};

u16 var8007fb5c[] = {
	0xff00, 0xff58, 0xff74, 0xff90, 0xffac, 0xffc8, 0xffe4, 0xffff,
	0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
	0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00,
	0xff00, 0xff18, 0xff30, 0xff5c, 0xff88, 0xffb4, 0xffd8, 0xffff,
};

#if VERSION == VERSION_JPN_FINAL
u16 var800801d8jf[] = {
	0xff00, 0xff11, 0xff22, 0xff33, 0xff44, 0xff55, 0xff66, 0xff77,
	0xff88, 0xff99, 0xffaa, 0xffbb, 0xffcc, 0xffdd, 0xffee, 0xffff,
};
#endif

bool g_TextHoloRayEnabled = false;
s32 g_TextBlendDistance = 0;
s32 g_TextLastBlendY = -1;
s32 var8007fba8 = 0;
u32 g_TextLAlpha = 1;
u32 g_TextLFade = 100;
u32 g_TextLLimbo = 44;
u32 g_TextSubleTY = 128;
u32 g_TextSubtleTX = 60;
u32 g_TextColourX = 0x44444400;
u32 g_TextColourY = 0xffffff00;

Gfx *text_render_char_v1_part2(Gfx *gdl, s32 x, s32 y, struct fontchar *char1, s32 arg4, s32 arg5, s32 arg6, s32 arg7);

void text_init(void)
{
	// empty
}

void text_set_default_kerning(s32 kerning)
{
	g_TextCharOverlap = -kerning;
}

void text_set_rotation90(bool rotated)
{
	g_TextRotated90 = rotated;
}

void text_set_wrap_indent(s32 count)
{
	g_WrapIndentCount = count;
}

void text_set_paragraph_overlap(s32 margin)
{
	g_TextParaOverlap = margin;
}

void text_set_hires(bool hires)
{
	if (hires) {
		g_TextScaleX = 2;
	} else {
		g_TextScaleX = 1;
	}

#if VERSION == VERSION_JPN_FINAL
	var80080108jf = 1;
#endif
}

void text_load_font(u8 *romstart, u8 *romend, struct font **fontptr, struct fontchar **charsptr, bool monospace)
{
	extern u8 _fonthandelgothicsmSegmentRomStart;
	extern u8 _fonthandelgothicxsSegmentRomStart;
	extern u8 _fonthandelgothicmdSegmentRomStart;

	u32 len;
	s32 maxwidth;
	s32 i;
	struct font *font;
	struct fontchar *chars;

#if VERSION >= VERSION_PAL_BETA
	s32 numchars = 94;

#if PAL
	// PAL has more characters in these fonts
	if (romstart == &_fonthandelgothicsmSegmentRomStart
			|| romstart == &_fonthandelgothicxsSegmentRomStart
			|| romstart == &_fonthandelgothicmdSegmentRomStart) {
		numchars = 135;
	}
#endif
#define NUMCHARS() numchars
#else
#define NUMCHARS() 94
#endif

	len = (romptr_t)romend - (romptr_t)romstart;
	font = memp_alloc(len, MEMPOOL_STAGE);
	chars = font->chars;

	dma_exec(font, (romptr_t) romstart, len);

	// Convert pointers
	for (i = 0; i < NUMCHARS(); i++) {
		chars[i].pixeldata += (uintptr_t)font;
	}

#if VERSION >= VERSION_JPN_FINAL
	if (romstart == &_fonthandelgothicsmSegmentRomStart) {
		for (i = 0; i < NUMCHARS(); i++) {
			chars[i].baseline++;
		}
	}
#endif

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

void text_reset(void)
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

	var8007faec = 0;
	g_FontTahoma2 = NULL;
	g_FontNumeric = NULL;
	g_FontHandelGothicXs = NULL;
	g_FontHandelGothicSm = NULL;
	g_FontHandelGothicMd = NULL;
	g_FontHandelGothicLg = NULL;
	var8007fb24 = 0;
	var8007fb2c = 0;
	var8007fb34 = 0;

	var8007faf0 = 0;
	g_FontTahoma1 = NULL;
	g_CharsNumeric = NULL;
	g_CharsHandelGothicXs = NULL;
	g_CharsHandelGothicSm = NULL;
	g_CharsHandelGothicMd = NULL;
	g_CharsHandelGothicLg = NULL;
	var8007fb28 = 0;
	var8007fb30 = 0;
	var8007fb38 = 0;

	g_TextCharOverlap = 0;
	g_TextRotated90 = false;
	g_WrapIndentCount = 0;
	g_TextParaOverlap = -1;
	g_TextUseAverageSampling = 0;
	var8007fadc = 0;
	var8007fae0 = 0;
	var8007fae4 = 0;
	var8007fae8 = 0;

	if (g_Vars.stagenum == STAGE_TITLE) {
		text_load_font(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);
		text_load_font(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
		text_load_font(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg, &g_CharsHandelGothicLg, false);
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		text_load_font(&_fonthandelgothicxsSegmentRomStart, &_fonthandelgothicxsSegmentRomEnd, &g_FontHandelGothicXs, &g_CharsHandelGothicXs, false);
		text_load_font(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);
		text_load_font(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
		text_load_font(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg, &g_CharsHandelGothicLg, false);
	} else {
#if VERSION >= VERSION_JPN_FINAL
		text_load_font(&_fontnumericSegmentRomStart, &_fontnumericSegmentRomEnd, &g_FontNumeric, &g_CharsNumeric, false);

		if (g_Vars.normmplayerisrunning) {
			if (IS4MB()) {
				s32 i;

				for (i = 0; i < ARRAYCOUNT(g_JpnKerning); i++) {
					g_JpnKerning[i] = 0;
				}

				g_FontHandelGothicXs = g_FontHandelGothicSm = (struct font *) g_JpnKerning;
				return;
			}
		}

		text_load_font(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);

		if (!g_Vars.normmplayerisrunning || IS8MB()) {
			text_load_font(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
		}

		if (g_Vars.stagenum == STAGE_TEST_OLD) {
			text_load_font(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg, &g_CharsHandelGothicLg, false);
		}

		text_load_font(&_fonthandelgothicxsSegmentRomStart, &_fonthandelgothicxsSegmentRomEnd, &g_FontHandelGothicXs, &g_CharsHandelGothicXs, false);
#elif VERSION >= VERSION_PAL_BETA
		text_load_font(&_fontnumericSegmentRomStart, &_fontnumericSegmentRomEnd, &g_FontNumeric, &g_CharsNumeric, false);
		text_load_font(&_fonthandelgothicxsSegmentRomStart, &_fonthandelgothicxsSegmentRomEnd, &g_FontHandelGothicXs, &g_CharsHandelGothicXs, false);
		text_load_font(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);

		if (!g_Vars.normmplayerisrunning) {
			text_load_font(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
		}

		if (g_Vars.stagenum == STAGE_TEST_OLD) {
			text_load_font(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg, &g_CharsHandelGothicLg, false);
		}
#else
		// This unused GE font exists in NTSC but was removed in the PAL version
		text_load_font(&_fonttahomaSegmentRomStart, &_fonttahomaSegmentRomEnd, &g_FontTahoma2, &g_FontTahoma1, false);

		text_load_font(&_fontnumericSegmentRomStart, &_fontnumericSegmentRomEnd, &g_FontNumeric, &g_CharsNumeric, false);
		text_load_font(&_fonthandelgothicxsSegmentRomStart, &_fonthandelgothicxsSegmentRomEnd, &g_FontHandelGothicXs, &g_CharsHandelGothicXs, false);
		text_load_font(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);
		text_load_font(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);

		if (g_Vars.stagenum == STAGE_TEST_OLD) {
			text_load_font(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg, &g_CharsHandelGothicLg, false);
		}
#endif
	}
}

Gfx *text_begin(Gfx *gdl)
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

	if (g_TextUseAverageSampling) {
		gDPSetTextureFilter(gdl++, G_TF_AVERAGE);
	}
#if VERSION == VERSION_JPN_FINAL
	else if (var80080108jf == 2) {
		gDPSetTextureFilter(gdl++, G_TF_POINT);
	}
#endif
	else {
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
	}

	return gdl;
}

Gfx *text_end(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetTextureLOD(gdl++, G_TL_LOD);

	return gdl;
}

Gfx *text_begin_boxmode(Gfx *gdl, u32 colour)
{
	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);

	return gdl;
}

Gfx *text_end_boxmode(Gfx *gdl)
{
	gDPSetCombineMode(gdl++, G_CC_CUSTOM_02, G_CC_CUSTOM_02);

	return gdl;
}

Gfx *text_draw_black_box(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2)
{
	gdl = text_begin_boxmode(gdl, 0x00000000);

	gDPFillRectangle(gdl++, *x1, *y1, *x2, *y2);

	gdl = text_end_boxmode(gdl);

	return gdl;
}

Gfx *text_draw_black_uibox(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2)
{
	gdl = text_begin_boxmode(gdl, 0x00000000);

	gDPFillRectangleScaled(gdl++, *x1, *y1, *x2, *y2);

	gdl = text_end_boxmode(gdl);

	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
Gfx *text_draw_black_textbox(Gfx *gdl, s32 left, s32 top, s32 width, s32 height)
{
	gdl = text_begin_boxmode(gdl, 0x00000000);

#if VERSION >= VERSION_JPN_FINAL
	gDPFillRectangle(gdl++, left - 1, top - 1, width * g_TextScaleX + left + 1, top + height * var80080108jf + 1);
#else
	gDPFillRectangle(gdl++, left - 1, top - 1, width * g_TextScaleX + left + 1, top + height + 1);
#endif

	gdl = text_end_boxmode(gdl);

	return gdl;
}
#endif

Gfx *text_draw_box(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour)
{
	gdl = text_begin_boxmode(gdl, colour);

	gDPFillRectangle(gdl++, x1, y1, x2, y2);

	gdl = text_end_boxmode(gdl);

	return gdl;
}

Gfx *text_enable_holo_ray(Gfx *gdl)
{
	Gfx *allocation;

	g_TextHoloRayEnabled = true;

	allocation = gfx_allocate(sizeof(Gfx) * 530);

	g_TextHoloRayGdl = allocation;
	g_TextHoloRayGdlEnd = allocation + 530;

	gSPDisplayList(gdl++, g_TextHoloRayGdl);

	gdl = func0f0d4c80(gdl);

	g_TextHoloRayGdl = func0f0d4a3c(g_TextHoloRayGdl, 0);

	g_TextLastBlendY = -1;

	return gdl;
}

void text_disable_holo_ray(void)
{
	g_TextHoloRayEnabled = false;

	gSPEndDisplayList(g_TextHoloRayGdl++);
}

void text_calculate_blend_distance(s32 y)
{
	if (y != g_TextLastBlendY) {
		f32 sqdist = g_Blend.diagtimer * g_Blend.diagtimer - (f32)((y - g_Blend.diagrefy) * (y - g_Blend.diagrefy));

		if (sqdist > 0.0f) {
			g_TextBlendDistance = g_Blend.diagrefx + sqrtf(sqdist);
		} else {
			g_TextBlendDistance = 0;
		}

		g_TextLastBlendY = y;
	}
}

void text_set_diagonal_blend(s32 x, s32 y, f32 timer, u8 mode)
{
	g_Blend.types |= BLENDTYPE_DIAGONAL;
	g_Blend.diagrefx = x;
	g_Blend.diagrefy = y;
	g_Blend.diagtimer = timer;
	g_Blend.diagmode = mode;
}

void text_backup_diagonal_blend_settings(void)
{
	g_Blend.backupdiagrefx = g_Blend.diagrefx;
	g_Blend.backupdiagrefy = g_Blend.diagrefy;
	g_Blend.backupdiagtimer = g_Blend.diagtimer;
	g_Blend.backupdiagmode = g_Blend.diagmode;
	g_Blend.backupdiagtypes = g_Blend.types & BLENDTYPE_DIAGONAL;
}

void text_restore_diagonal_blend_settings(void)
{
	g_Blend.diagrefx = g_Blend.backupdiagrefx;
	g_Blend.diagrefy = g_Blend.backupdiagrefy;
	g_Blend.diagtimer = g_Blend.backupdiagtimer;
	g_Blend.diagmode = g_Blend.backupdiagmode;
	g_Blend.types |= g_Blend.backupdiagtypes;
}

void text_set_vertical_blend(s32 y1, s32 y2, u32 arg2)
{
	g_Blend.types |= BLENDTYPE_VERTICAL;
	g_Blend.vertrefy1 = y1;
	g_Blend.vertrefy2 = y2;
	g_Blend.vert34 = arg2;
}

void text_set_horizontal_blend(s32 x1, s32 x2, u32 arg2)
{
	g_Blend.types |= BLENDTYPE_HORIZONTAL;
	g_Blend.horizrefx1 = x1;
	g_Blend.horizrefx2 = x2;
	g_Blend.horiz40 = arg2;
}

void text_reset_blends2(void)
{
	g_Blend.types = 0;
}

void text_reset_blends3(void)
{
	g_Blend.types = 0;
}

void text_backup_and_reset_blends(void)
{
	g_Blend.backuptypes = g_Blend.types;
	g_Blend.types = 0;
}

void text_restore_blends(void)
{
	g_Blend.types = g_Blend.backuptypes;
}

void text_set_wave_blend(s32 arg0, s32 arg1, s32 cthresh)
{
	g_Blend.types |= BLENDTYPE_WAVE;
	g_Blend.wave4c = arg0;
	g_Blend.wave50 = arg1;
	g_Blend.wave54 = cthresh;
	g_Blend.wavecolour1 = 0x44444400;
	g_Blend.wavecolour2 = 0xffffff00;
}

void text_set_menu_blend(f32 arg0)
{
	g_Blend.types |= BLENDTYPE_MENU;
	g_Blend.menuweight = arg0 * arg0 * 110.0f;
}

void text_set_wave_colours(u32 colour1, u32 colour2)
{
	g_Blend.wavecolour1 = colour1;
	g_Blend.wavecolour2 = colour2;
}

void text_reset_blends(void)
{
	g_Blend.types = 0;
}

bool text_has_diagonal_blend(void)
{
	return (g_Blend.types & BLENDTYPE_DIAGONAL)
		&& (g_Blend.diagmode == DIAGMODE_FADEIN || g_Blend.diagmode == DIAGMODE_FADEOUT);
}

u32 text_apply_projection_colour(s32 x, s32 y, u32 colour)
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

		f14 = g_TextLAlpha;
		f18 = g_TextLFade;
		f16 = g_TextLLimbo;

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
				result = colour_blend(colour, colour2, 0xff - (u32) weightf);
			}
		} else if (g_Blend.diagmode == 2) {
			f16 = 0.0f;

			if (g_Blend.diagtimer < f12) {
				result = 0x00000000;
			} else if (g_Blend.diagtimer - f14 < f12) {
				weightf = (f12 - (g_Blend.diagtimer - f14)) / f14 * 255.0f;
				result = colour_blend(0x00000000, colour & 0xff, weightf);
			} else if (g_Blend.diagtimer - (f14 + f16) < f12) {
				result = colour & 0xff;
			} else if ((g_Blend.diagtimer - (f14 + f18 + f16)) < f12) {
				weightf = (f12 - (g_Blend.diagtimer - (f14 + f18 + f16))) / f18 * 255.0f;
				result = colour_blend(colour & 0xff, colour, weightf);
			}
		}
	}

	return result;
}

u32 text_get_colour_at_pos(s32 x, s32 y, u32 colourarg)
{
	f32 f14;
	f32 f18;
	f32 f16;
	u32 colour = colourarg;

	if (g_Blend.types & BLENDTYPE_MENU) {
		colour = (colour_blend(0x00000000, colour, g_Blend.menuweight) & 0xffffff00) | (colour & 0xff);
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
			colour = colour_blend(colour, 0x00000000, v0 * 255 / g_Blend.vert34);
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
			colour = colour_blend(colour, 0x00000000, v0 * 255 / g_Blend.horiz40);
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

		f14 = g_TextLAlpha;
		f18 = g_TextLFade;
		f16 = g_TextLLimbo;

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
				colour = colour_blend(0x00000000, colour & 0xff, weightf);
			} else if (g_Blend.diagtimer - (f14 + f16) < f12) {
				colour &= 0xff;
			} else if (g_Blend.diagtimer - (f14 + f18 + f16) < f12) {
				f32 weightf = (f12 - (g_Blend.diagtimer - (f14 + f18 + f16))) / f18 * 255.0f;
				colour = colour_blend(0x00000000, colour, weightf);
			}
		} else {
			u32 alpha[4];

			static s32 burncol = 0xffffff00;

			alpha[0] = colour & 0xff;
			f18 = 50.0f;
			f16 = 22.0f;

			main_override_variable("burncol", &burncol);

			if (g_Blend.diagtimer < f12) {
				colour = colour_blend(alpha[0], colour, 110);
			} else if (g_Blend.diagtimer - f14 < f12) {
				f32 weightf = (f12 - (g_Blend.diagtimer - f14)) / f14 * 255.0f;
				colour = colour_blend(
						colour_blend(burncol | (colour & 0xff), colour, 0xc0),
						colour_blend(alpha[0], colour, 110),
						255 - (u32) weightf);
			} else if (g_Blend.diagtimer - (f14 + f16) < f12) {
				u32 stack;
				colour = colour_blend(burncol | (colour & 0xff), colour, 0xc0);
			} else if (g_Blend.diagtimer - (f14 + f18 + f16) < f12) {
				f32 weightf = (f12 - (g_Blend.diagtimer - (f14 + f18 + f16))) / f18 * 255.0f;
				colour = colour_blend(
						colour,
						colour_blend(burncol | (colour & 0xff), colour, 0xc0),
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
			s32 weight = g_TextSubtleTX * (0 - f0);
			colour = colour_blend(g_Blend.wavecolour1 | (colour & 0xff), colour, weight);
		} else {
			s32 weight = g_TextSubleTY * f0;
			colour = colour_blend(g_Blend.wavecolour2 | (colour & 0xff), colour, weight);
		}
	}

	return colour;
}

Gfx *text_configure_colours_v2(Gfx *gdl, s32 x, s32 y)
{
	u32 colour = text_get_colour_at_pos(x, y, g_Blend.colour04);

	if (colour != g_Blend.colour44) {
		gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	}

	g_Blend.colour44 = colour;

	return gdl;
}

#if VERSION >= VERSION_PAL_BETA
void text_map_codeunit_to_char(u8 *c)
{
	switch (*c) {
	case 0xc0:
	case 0xc1:
	case 0xc4:
		*c = 0x41;
		break;
	case 0xc8:
	case 0xc9:
		*c = 0x45;
		break;
	case 0xcc:
	case 0xcd:
		*c = 0x49;
		break;
	case 0xd2:
	case 0xd3:
	case 0xd6:
		*c = 0x4f;
		break;
	case 0xd9:
	case 0xda:
	case 0xdc:
		*c = 0x55;
		break;
	case 0xe0:
	case 0xe1:
	case 0xe2:
	case 0xe4:
		*c = 0x61;
		break;
	case 0xe8:
	case 0xe9:
	case 0xea:
	case 0xeb:
		*c = 0x65;
		break;
	case 0xec:
	case 0xed:
	case 0xee:
	case 0xef:
		*c = 0x69;
		break;
	case 0xf2:
	case 0xf3:
	case 0xf4:
	case 0xf6:
		*c = 0x6f;
		break;
	case 0xf9:
	case 0xfa:
	case 0xfb:
	case 0xfc:
		*c = 0x75;
		break;
	case 0xd1:
		*c = 0x4e;
		break;
	case 0xf1:
		*c = 0x6e;
		break;
	case 0xe7:
		*c = 0x63;
		break;
	case 0xdf:
		*c = 0x42;
		break;
	case 0xa1:
	case 0xaa:
	case 0xb0:
	case 0xbf:
		*c = 0x20;
		break;
	}
}
#endif

#if VERSION >= VERSION_JPN_FINAL
char text_codepoint_to_sbchar(u16 codepoint)
{
	char c = '\0';
	u16 codepoint16 = codepoint;
	u8 codepoint8 = codepoint;

	if (codepoint >= 0x10 && codepoint < 0x1a) { // 0-9
		c = codepoint16;
		c += 0x20;
	}

	if (codepoint >= 0x1a && codepoint < 0x34) { // A-Z
		c = codepoint16;
		c += 0x27;
	}

	if (codepoint >= 0x95 && codepoint < 0xaf) { // a-z
		c = codepoint16;
		c -= 0x34;
	}

	if (codepoint == 0x3fe || codepoint == 0x3ff) {
		c = '-';
	}

	if (codepoint < 0xff) {
		switch (codepoint8) {
		case 0x00: c = ' '; break;
		case 0x01: c = ','; break;
		case 0x02: c = '$'; break;
		case 0x03: c = '('; break;
		case 0x04: c = ')'; break;
		case 0x05: c = '.'; break;
		case 0x06: c = '%'; break;
		case 0x07: c = '['; break;
		case 0x08: c = ']'; break;
		case 0x09: c = '"'; break;
		case 0x0a: c = '<'; break;
		case 0x0b: c = '>'; break;
		case 0x0c: c = '&'; break;
		case 0x0d: c = '~'; break;
		case 0x0e: c = '.'; break;
		case 0x0f: c = ' '; break;
		case 0x34: c = '!'; break;
		case 0x35: c = '"'; break;
		case 0x36: c = '#'; break;
		case 0x37: c = '"'; break;
		case 0x38: c = '*'; break;
		case 0x39: c = '+'; break;
		case 0x3a: c = ','; break;
		case 0x3b: c = '-'; break;
		case 0x3c: c = '.'; break;
		case 0x3d: c = '/'; break;
		case 0x3e: c = ':'; break;
		case 0x3f: c = '='; break;
		case 0x40: c = '?'; break;
		case 0x41: c = '@'; break;
		}
	}

	return c;
}
#endif

#if VERSION >= VERSION_JPN_FINAL
u16 text_sbchar_to_codepoint(u8 c)
{
	u16 codepoint = 0;

	if (c >= '0' && c <= '9') {
		codepoint = c - 0x20;
	}

	if (c >= 'A' && c <= 'Z') {
		codepoint = c - 0x27;
	}

	if (c >= 'a' && c <= 'z') {
		codepoint = c + 0x34;
	}

	switch (c) {
	case ' ': codepoint = 0x00; break;
	case ',': codepoint = 0x01; break;
	case '$': codepoint = 0x02; break;
	case '(': codepoint = 0x03; break;
	case ')': codepoint = 0x04; break;
	case '.': codepoint = 0x05; break;
	case '%': codepoint = 0x06; break;
	case '[': codepoint = 0x07; break;
	case ']': codepoint = 0x08; break;
	case '"': codepoint = 0x09; break;
	case '<': codepoint = 0x0a; break;
	case '>': codepoint = 0x0b; break;
	case '&': codepoint = 0x0c; break;
	case '~': codepoint = 0x0d; break;
	case '!': codepoint = 0x34; break;
	case '#': codepoint = 0x36; break;
	case '*': codepoint = 0x38; break;
	case '+': codepoint = 0x39; break;
	case '-': codepoint = 0x3b; break;
	case '/': codepoint = 0x3d; break;
	case ':': codepoint = 0x3e; break;
	case '=': codepoint = 0x3f; break;
	case '?': codepoint = 0x40; break;
	case '@': codepoint = 0x41; break;
	}

	return codepoint;
}
#endif

void text_parse_char(char **text, struct fontchar **thischarptr, struct fontchar **prevcharptr, struct fontchar *chars, u8 *prevchar);

#if VERSION == VERSION_JPN_FINAL
#if MATCHING
GLOBAL_ASM(
glabel text_parse_char
/*  f154b00:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f154b04:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f154b08:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f154b0c:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f154b10:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f154b14:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f154b18:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f154b1c:	00808025 */ 	move	$s0,$a0
/*  f154b20:	3c047f1c */ 	lui	$a0,%hi(var7f1b8068jf)
/*  f154b24:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f154b28:	240a000b */ 	li	$t2,0xb
/*  f154b2c:	24848068 */ 	addiu	$a0,$a0,%lo(var7f1b8068jf)
/*  f154b30:	28410080 */ 	slti	$at,$v0,0x80
/*  f154b34:	10200032 */ 	beqz	$at,.JF0f154c00
/*  f154b38:	00401825 */ 	move	$v1,$v0
/*  f154b3c:	10e00004 */ 	beqz	$a3,.JF0f154b50
/*  f154b40:	3c188008 */ 	lui	$t8,%hi(var800800f0jf)
/*  f154b44:	8f1800f0 */ 	lw	$t8,%lo(var800800f0jf)($t8)
/*  f154b48:	53000016 */ 	beqzl	$t8,.JF0f154ba4
/*  f154b4c:	2404000c */ 	li	$a0,0xc
.JF0f154b50:
/*  f154b50:	3c03800a */ 	lui	$v1,%hi(g_TmpJpnChar)
/*  f154b54:	24635008 */ 	addiu	$v1,$v1,%lo(g_TmpJpnChar)
/*  f154b58:	2405000c */ 	li	$a1,0xc
/*  f154b5c:	304400ff */ 	andi	$a0,$v0,0xff
/*  f154b60:	a4600000 */ 	sh	$zero,0x0($v1)
/*  f154b64:	a0600002 */ 	sb	$zero,0x2($v1)
/*  f154b68:	a0650003 */ 	sb	$a1,0x3($v1)
/*  f154b6c:	a0650004 */ 	sb	$a1,0x4($v1)
/*  f154b70:	a4600006 */ 	sh	$zero,0x6($v1)
/*  f154b74:	0fc5525a */ 	jal	text_sbchar_to_codepoint
/*  f154b78:	ac600008 */ 	sw	$zero,0x8($v1)
/*  f154b7c:	8fab0034 */ 	lw	$t3,0x34($sp)
/*  f154b80:	3c03800a */ 	lui	$v1,%hi(g_TmpJpnChar)
/*  f154b84:	24635008 */ 	addiu	$v1,$v1,%lo(g_TmpJpnChar)
/*  f154b88:	24590080 */ 	addiu	$t9,$v0,0x80
/*  f154b8c:	a4790000 */ 	sh	$t9,0x0($v1)
/*  f154b90:	ad630000 */ 	sw	$v1,0x0($t3)
/*  f154b94:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f154b98:	10000011 */ 	b	.JF0f154be0
/*  f154b9c:	ad830000 */ 	sw	$v1,0x0($t4)
/*  f154ba0:	2404000c */ 	li	$a0,0xc
.JF0f154ba4:
/*  f154ba4:	00640019 */ 	multu	$v1,$a0
/*  f154ba8:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f154bac:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f154bb0:	00006812 */ 	mflo	$t5
/*  f154bb4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f154bb8:	25f8fe74 */ 	addiu	$t8,$t7,-396
/*  f154bbc:	af380000 */ 	sw	$t8,0x0($t9)
/*  f154bc0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f154bc4:	8fb90038 */ 	lw	$t9,0x38($sp)
/*  f154bc8:	916c0000 */ 	lbu	$t4,0x0($t3)
/*  f154bcc:	01840019 */ 	multu	$t4,$a0
/*  f154bd0:	00006812 */ 	mflo	$t5
/*  f154bd4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f154bd8:	25f8fe74 */ 	addiu	$t8,$t7,-396
/*  f154bdc:	af380000 */ 	sw	$t8,0x0($t9)
.JF0f154be0:
/*  f154be0:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f154be4:	8fad0040 */ 	lw	$t5,0x40($sp)
/*  f154be8:	916c0000 */ 	lbu	$t4,0x0($t3)
/*  f154bec:	a1ac0000 */ 	sb	$t4,0x0($t5)
/*  f154bf0:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f154bf4:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f154bf8:	10000040 */ 	b	.JF0f154cfc
/*  f154bfc:	ae0f0000 */ 	sw	$t7,0x0($s0)
.JF0f154c00:
/*  f154c00:	3c03800a */ 	lui	$v1,%hi(g_TmpJpnChar)
/*  f154c04:	24635008 */ 	addiu	$v1,$v1,%lo(g_TmpJpnChar)
/*  f154c08:	a4600000 */ 	sh	$zero,0x0($v1)
/*  f154c0c:	a0600002 */ 	sb	$zero,0x2($v1)
/*  f154c10:	a06a0003 */ 	sb	$t2,0x3($v1)
/*  f154c14:	a06a0004 */ 	sb	$t2,0x4($v1)
/*  f154c18:	a4600006 */ 	sh	$zero,0x6($v1)
/*  f154c1c:	ac600008 */ 	sw	$zero,0x8($v1)
/*  f154c20:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f154c24:	3c058008 */ 	lui	$a1,%hi(ope)
/*  f154c28:	24a50228 */ 	addiu	$a1,$a1,%lo(ope)
/*  f154c2c:	90460000 */ 	lbu	$a2,0x0($v0)
/*  f154c30:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f154c34:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f154c38:	93070000 */ 	lbu	$a3,0x0($t8)
/*  f154c3c:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f154c40:	30cb007f */ 	andi	$t3,$a2,0x7f
/*  f154c44:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f154c48:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f154c4c:	30ed007f */ 	andi	$t5,$a3,0x7f
/*  f154c50:	018d4825 */ 	or	$t1,$t4,$t5
/*  f154c54:	a7a9002a */ 	sh	$t1,0x2a($sp)
/*  f154c58:	afa90024 */ 	sw	$t1,0x24($sp)
/*  f154c5c:	0c0036b4 */ 	jal	main_override_variable
/*  f154c60:	a3a00029 */ 	sb	$zero,0x29($sp)
/*  f154c64:	3c0e8008 */ 	lui	$t6,%hi(ope)
/*  f154c68:	8dce0228 */ 	lw	$t6,%lo(ope)($t6)
/*  f154c6c:	3c03800a */ 	lui	$v1,%hi(g_TmpJpnChar)
/*  f154c70:	24635008 */ 	addiu	$v1,$v1,%lo(g_TmpJpnChar)
/*  f154c74:	93a80029 */ 	lbu	$t0,0x29($sp)
/*  f154c78:	11c00006 */ 	beqz	$t6,.JF0f154c94
/*  f154c7c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f154c80:	0fc551e1 */ 	jal	text_codepoint_to_sbchar
/*  f154c84:	3204ffff */ 	andi	$a0,$s0,0xffff
/*  f154c88:	3c03800a */ 	lui	$v1,%hi(g_TmpJpnChar)
/*  f154c8c:	24635008 */ 	addiu	$v1,$v1,%lo(g_TmpJpnChar)
/*  f154c90:	304800ff */ 	andi	$t0,$v0,0xff
.JF0f154c94:
/*  f154c94:	11000004 */ 	beqz	$t0,.JF0f154ca8
/*  f154c98:	01001025 */ 	move	$v0,$t0
/*  f154c9c:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f154ca0:	2404000c */ 	li	$a0,0xc
/*  f154ca4:	14a0000d */ 	bnez	$a1,.JF0f154cdc
.JF0f154ca8:
/*  f154ca8:	32181fff */ 	andi	$t8,$s0,0x1fff
/*  f154cac:	2b010400 */ 	slti	$at,$t8,0x400
/*  f154cb0:	14200002 */ 	bnez	$at,.JF0f154cbc
/*  f154cb4:	24190002 */ 	li	$t9,0x2
/*  f154cb8:	a7b9002a */ 	sh	$t9,0x2a($sp)
.JF0f154cbc:
/*  f154cbc:	97ab002a */ 	lhu	$t3,0x2a($sp)
/*  f154cc0:	8fad0034 */ 	lw	$t5,0x34($sp)
/*  f154cc4:	256c0080 */ 	addiu	$t4,$t3,0x80
/*  f154cc8:	a46c0000 */ 	sh	$t4,0x0($v1)
/*  f154ccc:	ada30000 */ 	sw	$v1,0x0($t5)
/*  f154cd0:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f154cd4:	10000009 */ 	b	.JF0f154cfc
/*  f154cd8:	adc30000 */ 	sw	$v1,0x0($t6)
.JF0f154cdc:
/*  f154cdc:	00440019 */ 	multu	$v0,$a0
/*  f154ce0:	8fab0034 */ 	lw	$t3,0x34($sp)
/*  f154ce4:	00007812 */ 	mflo	$t7
/*  f154ce8:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f154cec:	2719fe74 */ 	addiu	$t9,$t8,-396
/*  f154cf0:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f154cf4:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f154cf8:	ad830000 */ 	sw	$v1,0x0($t4)
.JF0f154cfc:
/*  f154cfc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f154d00:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f154d04:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f154d08:	03e00008 */ 	jr	$ra
/*  f154d0c:	00000000 */ 	nop
);

u32 ope = 0;

const char var7f1b8068jf[] = "ope";
#else
void text_parse_char(char **text, struct fontchar **thischarptr, struct fontchar **prevcharptr, struct fontchar *chars, u8 *prevchar)
{
	u16 c;
	u8 c1;
	u8 c2;
	u16 codepoint;
	u8 sbchar;

	static u32 ope = 0;

	c = **text;

	if (c < 0x80) {
		if (chars == NULL || var800800f0jf) {
			g_TmpJpnChar.index = 0;
			g_TmpJpnChar.baseline = 0;
			g_TmpJpnChar.height = 12;
			g_TmpJpnChar.width = 12;
			g_TmpJpnChar.kerningindex = 0;
			g_TmpJpnChar.pixeldata = NULL;

			g_TmpJpnChar.index = 0x80 + text_sbchar_to_codepoint(c);

			*thischarptr = &g_TmpJpnChar;
			*prevcharptr = &g_TmpJpnChar;
		} else {
			*thischarptr = &chars[c - 0x21];
			*prevcharptr = &chars[*prevchar - 0x21];
		}

		*prevchar = **text;
		*text += 1;
	} else {
		g_TmpJpnChar.index = 0;
		g_TmpJpnChar.baseline = 0;
		g_TmpJpnChar.height = 11;
		g_TmpJpnChar.width = 11;
		g_TmpJpnChar.kerningindex = 0;
		g_TmpJpnChar.pixeldata = NULL;

		c1 = **text;
		*text = *text + 1;
		c2 = **text;
		*text = *text + 1;

		codepoint = ((c1 & 0x7f) << 7) | (c2 & 0x7f);
		sbchar = '\0';

		main_override_variable("ope", &ope);

		if (ope) {
			sbchar = text_codepoint_to_sbchar(codepoint);
		}

		if (sbchar == '\0' || chars == NULL) {
			if ((codepoint & 0x1fff) >= 0x400) {
				codepoint = 2;
			}

			g_TmpJpnChar.index = codepoint + 0x80;

			*thischarptr = &g_TmpJpnChar;
			*prevcharptr = &g_TmpJpnChar;
		} else {
			*thischarptr = &chars[sbchar - 0x21];
			*prevcharptr = &g_TmpJpnChar;
		}
	}
}
#endif
#elif VERSION >= VERSION_PAL_BETA
void text_parse_char(char **text, struct fontchar **thischarptr, struct fontchar **prevcharptr, struct fontchar *chars, u8 *prevchar)
{
	u8 c;
	u8 index;

	if (g_Jpn) {
		if (**text < 0x80) {
			*thischarptr = &chars[**text - 0x21];
			*prevcharptr = &chars[*prevchar - 0x21];

			*prevchar = **text;
			*text += 1;
			return;
		}

		*thischarptr = &chars[*prevchar - 0x21];
		*prevcharptr = &chars[*prevchar - 0x21];
		return;
	}

	index = 0;
	c = **text;

	if (chars == g_CharsHandelGothicSm || chars == g_CharsHandelGothicMd || chars == g_CharsHandelGothicXs) {
		switch (c) {
		case 0xc4: index = 0x5e; break;
		case 0xc1: index = 0x66; break;
		case 0xc0: index = 0x70; break;
		case 0xc9: index = 0x67; break;
		case 0xc8: index = 0x71; break;
		case 0xcd: index = 0x68; break;
		case 0xcc: index = 0x72; break;
		case 0xd6: index = 0x5f; break;
		case 0xd3: index = 0x69; break;
		case 0xd2: index = 0x73; break;
		case 0xdc: index = 0x60; break;
		case 0xda: index = 0x6a; break;
		case 0xd9: index = 0x74; break;
		case 0xe4: index = 0x61; break;
		case 0xe1: index = 0x6b; break;
		case 0xe0: index = 0x75; break;
		case 0xe2: index = 0x7a; break;
		case 0xea: index = 0x7b; break;
		case 0xe9: index = 0x6c; break;
		case 0xeb: index = 0x62; break;
		case 0xe8: index = 0x76; break;
		case 0xec: index = 0x77; break;
		case 0xef: index = 0x63; break;
		case 0xed: index = 0x6d; break;
		case 0xee: index = 0x7c; break;
		case 0xf4: index = 0x7d; break;
		case 0xf6: index = 0x64; break;
		case 0xf3: index = 0x6e; break;
		case 0xf2: index = 0x78; break;
		case 0xf9: index = 0x79; break;
		case 0xfc: index = 0x65; break;
		case 0xfa: index = 0x6f; break;
		case 0xfb: index = 0x7e; break;
		case 0xd1: index = 0x7f; break;
		case 0xf1: index = 0x80; break;
		case 0xe7: index = 0x81; break;
		case 0xdf: index = 0x82; break;
		case 0xbf: index = 0x83; break;
		case 0xa1: index = 0x84; break;
		case 0xb0: index = 0x85; break;
		case 0xaa: index = 0x86; break;
		}
	} else {
		text_map_codeunit_to_char(&c);
	}

	if (index > 0) {
		*thischarptr = &chars[index];
	} else {
		if (c < 0x21) {
			c = '!';
		}

		if (c > 0x7e) {
			c = '!';
		}

		*thischarptr = &chars[c - 0x21];
	}

	*prevcharptr = &chars[*prevchar - 0x21];

	if (index > 0) {
		text_map_codeunit_to_char(&c);
	}

	*prevchar = c;
	*text += 1;
}
#endif

Gfx *text_render_credits_char(Gfx *gdl, s32 *arg1, struct fontchar *curchar, struct fontchar *prevchar,
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
	Vtx *vertices;
	Col *colours;

	tmp2 = font->kerning[prevchar->kerningindex * 13 + curchar->kerningindex] + g_TextCharOverlap;
	*arg1 = *arg1 - tmp2 + 1;

#if VERSION >= VERSION_JPN_FINAL
	if (curchar->pixeldata == NULL) {
		curchar->pixeldata = (void *) lang_get_jpn_char_pixels(curchar->index - 0x80);
	}

	if (curchar->index >= 0x80) {
		if (!var80080104jf) {
			gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(var800801d8jf));
			var80080104jf = true;
			gDPLoadSync(gdl++);
			gDPLoadTLUTCmd(gdl++, 6, 15);
		}
	} else {
		if (var80080104jf) {
			gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(var8007fb3c));
			var80080104jf = false;
			gDPLoadSync(gdl++);
			gDPLoadTLUTCmd(gdl++, 6, 15);
		}
	}
#endif

	gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, curchar->pixeldata);
	gDPLoadSync(gdl++);
	gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, ((curchar->height * 8 + 17) >> 1) - 1, 2048);
	gDPPipeSync(gdl++);

	tmp1 = var8007fadc;
	tmp2 = var8007fae0;

	sp3e = (var8007fadc + *arg1 * 4) * widthscale * 10.0f + 40.0f * x;
	sp3c = (var8007fae0 + curchar->baseline * 4) * heightscale * 10.0f + 40.0f * y;
	sp3a = (var8007fadc + (*arg1 + (curchar->width + 1)) * 4) * widthscale * 10.0f + 40.0f * x;
	sp38 = (var8007fae0 + (curchar->baseline + (curchar->height + 1)) * 4) * heightscale * 10.0f + 40.0f * y;

	sp36 = 1;
	sp32 = 1;
	sp34 = curchar->width;
	sp30 = curchar->height;
	sp34 = sp36 + ((sp34 + 1) << 6);
	sp30 = sp32 + ((sp30 + 1) << 6);

	vertices = gfx_allocate_vertices(4);

	colours = gfx_allocate_colours(1);
	colours[0].word = 0xff0000ff;

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

	gSPColor(gdl++, colours, 1);
	gSPVertex(gdl++, vertices, 4, 0);

	gSPTri2(gdl++, 0, 1, 2, 2, 3, 0);

	*arg1 += curchar->width;

	return gdl;
}

Gfx *text_render_credits(Gfx *gdl, f32 x, f32 y, f32 widthscale, f32 heightscale,
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

#if VERSION >= VERSION_JPN_FINAL
	if (1);
	lineheight = 13;
#else
	lineheight = chars['['].height + chars['['].baseline;

	if (g_Jpn && lineheight < 14) {
		lineheight = 14;
	}
#endif

	text_measure(&textheight, &textwidth, text, chars, font, 0);

	ptr = &x;
	fx = *ptr - (widthscale - 1.0f) * textwidth * 0.5f * hdir;
	fy = y - (heightscale - 1.0f) * lineheight * 0.5f * vdir;

	if (fx);
	if (fy);

	gDPPipeSync(gdl++);
	gDPSetTextureLUT(gdl++, G_TT_IA16);

#if VERSION >= VERSION_JPN_FINAL
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(var800801d8jf));
	var80080104jf = true;
#else
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(var8007fb3c));
#endif

	gDPLoadSync(gdl++);
	gDPLoadTLUTCmd(gdl++, 6, 15);
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	gDPPipeSync(gdl++);

#if VERSION >= VERSION_PAL_BETA
	if (text != NULL) {
		while (*text != '\0') {
			if (*text == ' ') {
				relx = relx + g_TextScaleX * 5;
				prevchar = 'H';
				text += 1;
			} else if (*text == '\n') {
				if (g_TextParaOverlap >= 0 && relx == 0) {
					totalheight += g_TextParaOverlap;
					relx = 0;
				} else {
					relx = 0;
#if VERSION >= VERSION_JPN_FINAL
					totalheight = totalheight + lineheight * var80080108jf;
#else
					totalheight += lineheight;
#endif
				}

				prevchar = 'H';
				text += 1;
			} else {
				struct fontchar *sp84;
				struct fontchar *sp80;

				text_parse_char(&text, &sp84, &sp80, chars, &prevchar);
				gdl = text_render_credits_char(gdl, &relx, sp84, sp80, font, widthscale, heightscale, fx, fy);
			}
		}
	}
#else
	if (text != NULL) {
		while (*text != '\0') {
			if (*text == ' ') {
				prevchar = 'H';
				text += 1;
				relx = relx + g_TextScaleX * 5;
			} else if (*text == '\n') {
				prevchar = 'H';
				text += 1;

				if (g_TextParaOverlap >= 0 && relx == 0) {
					totalheight += g_TextParaOverlap;
					relx = 0;
				} else {
					totalheight += lineheight;
					relx = 0;
				}
			} else if (*text < 0x80) {
				gdl = text_render_credits_char(gdl, &relx, &chars[*text - 0x21], &chars[prevchar - 0x21], font,
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
				tmpchar.pixeldata = (void *) lang_get_jpn_char_pixels(codepoint);

				text += 2;
			}
		}
	}
#endif

	return gdl;
}

Gfx *text_render_char_v2(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, struct fontchar *prevchar,
		struct font *font, s32 savedx, s32 savedy, s32 width, s32 height, s32 shadowoffset)
{
#if VERSION >= VERSION_JPN_FINAL
	s32 tmp;
	s32 sp90;
	s32 xscale = g_TextScaleX;
	s32 yscale = var80080108jf;

	savedy -= 2;

	if (g_TextRotated90) {
		xscale = 1;
	}

	sp90 = *y + shadowoffset;
	tmp = g_TextCharOverlap + font->kerning[prevchar->kerningindex * 13 + curchar->kerningindex];
	*x -= (tmp - 1) * xscale;
	width *= xscale;
	height *= yscale;

	if (g_TextRotated90 || (*x > 0 && *x <= vi_get_width() && sp90 + curchar->baseline <= vi_get_height())) {
		if (savedx + width >= *x
				&& savedy + height >= curchar->baseline + sp90
				&& *x >= savedx
				&& curchar->baseline + sp90 + curchar->height >= savedy) {
			if (curchar->pixeldata == NULL) {
				curchar->pixeldata = (void *)lang_get_jpn_char_pixels(curchar->index - 0x80);
			}

			if (curchar->index >= 0x80) {
				if (!var80080104jf) {
					gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(var800801d8jf));

					var80080104jf = true;

					gDPLoadSync(gdl++);
					gDPLoadTLUTCmd(gdl++, 6, 15);
				}
			} else {
				if (var80080104jf) {
					gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(var8007fb3c));

					var80080104jf = false;

					gDPLoadSync(gdl++);
					gDPLoadTLUTCmd(gdl++, 6, 15);
				}
			}

			gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, curchar->pixeldata);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, ((curchar->height * 8 + 17) >> 1) - 1, 2048);
			gDPPipeSync(gdl++);

			if (g_Blend.types) {
				gdl = text_configure_colours_v2(gdl, *x / g_UiScaleX, *y + shadowoffset);
			}

			if (1);

			if (*x + xscale * curchar->width <= savedx + width) {
				if (savedy <= curchar->baseline * yscale + sp90) {
					if (curchar->baseline * yscale + sp90 + curchar->height * yscale <= savedy + height) {
						if (g_TextRotated90) {
							gSPTextureRectangleFlip(gdl++,
									(sp90 - curchar->baseline - curchar->height * g_TextScaleX) * 4 + var8007fae0,
									*x * 4 + var8007fadc,
									(sp90 - curchar->baseline) * 4 + var8007fae0,
									(*x + curchar->width * var80080108jf) * 4 + var8007fadc,
									G_TX_RENDERTILE,
									var8007fae8 + 32,
									((curchar->height - 1) << 5) + var8007fae4 + 32,
									1024 / var80080108jf,
									65536 - 1024 / g_TextScaleX);
						} else {
							gSPTextureRectangle(gdl++,
									*x * 4 + var8007fadc,
									(sp90 + curchar->baseline * var80080108jf) * 4 + var8007fae0,
									(*x + curchar->width * g_TextScaleX) * 4 + var8007fadc,
									(sp90 + curchar->baseline * var80080108jf + curchar->height * var80080108jf) * 4 + var8007fae0 - (var80080108jf - 1) * 4,
									G_TX_RENDERTILE,
									var8007fae4 + 32,
									var8007fae8 + 32,
									1024 / g_TextScaleX,
									1024 / var80080108jf);

							if (g_TextHoloRayEnabled) {
								text_calculate_blend_distance(*y + shadowoffset);

								if (g_TextBlendDistance >= *x / g_UiScaleX && *x / g_UiScaleX + curchar->width * g_TextScaleX >= g_TextBlendDistance) {
									g_TextHoloRayGdl = menugfx_draw_plane(g_TextHoloRayGdl,
											g_TextBlendDistance,
											curchar->baseline * var80080108jf + sp90,
											g_TextBlendDistance,
											curchar->baseline * var80080108jf + sp90 + curchar->height * var80080108jf,
											g_Blend.colour04,
											g_Blend.colour04,
											MENUPLANE_00);
								}

								if (g_TextBlendDistance - 3 >= *x / g_UiScaleX && *x / g_UiScaleX + curchar->width * g_TextScaleX >= g_TextBlendDistance - 3) {
									g_TextHoloRayGdl = menugfx_draw_plane(g_TextHoloRayGdl,
											g_TextBlendDistance,
											curchar->baseline * var80080108jf + sp90,
											g_TextBlendDistance,
											curchar->baseline * var80080108jf + sp90 + curchar->height * var80080108jf,
											g_Blend.colour04,
											g_Blend.colour04,
											MENUPLANE_00);
								}
							}
						}
					} else if (savedy + height >= curchar->baseline * var80080108jf + sp90) {
						gSPTextureRectangle(gdl++,
								*x * 4 + var8007fadc,
								(sp90 + curchar->baseline * var80080108jf) * 4 + var8007fae0,
								(*x + curchar->width * g_TextScaleX) * 4 + var8007fadc,
								(savedy + height) * 4 + var8007fae0,
								G_TX_RENDERTILE,
								var8007fae4 + 32,
								var8007fae8 + 32,
								1024 / g_TextScaleX,
								1024 / var80080108jf);
					}
				} else {
					if (curchar->baseline * var80080108jf + sp90 + curchar->height * var80080108jf >= savedy) {
						gSPTextureRectangle(gdl++,
								*x * 4 + var8007fadc,
								savedy * 4 + var8007fae0,
								(*x + curchar->width * g_TextScaleX) * 4 + var8007fadc,
								(curchar->baseline * var80080108jf + sp90 + curchar->height * var80080108jf) * 4 + var8007fae0,
								G_TX_RENDERTILE,
								var8007fae4 + 32,
								((savedy - sp90 - curchar->baseline * var80080108jf) << 5) + var8007fae8 + 32,
								1024 / g_TextScaleX,
								1024 / var80080108jf);
					}
				}
			}
		}
	}
#else
	s32 tmp;
	s32 sp90;
	s32 xscale = g_TextScaleX;

#if VERSION >= VERSION_PAL_BETA
	savedy -= 2;
#endif

	if (g_TextRotated90) {
		xscale = 1;
	}

	sp90 = *y + shadowoffset;
	tmp = g_TextCharOverlap + font->kerning[prevchar->kerningindex * 13 + curchar->kerningindex];
	*x -= (tmp - 1) * xscale;
	width *= xscale;

	if (g_TextRotated90 || (*x > 0 && *x <= vi_get_width() && sp90 + curchar->baseline <= vi_get_height())) {
		if (savedx + width >= *x
				&& savedy + height >= curchar->baseline + sp90
				&& *x >= savedx
				&& curchar->baseline + sp90 + curchar->height >= savedy) {
			gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, curchar->pixeldata);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, ((curchar->height * 8 + 17) >> 1) - 1, 2048);
			gDPPipeSync(gdl++);

			if (g_Blend.types) {
				gdl = text_configure_colours_v2(gdl, *x / g_UiScaleX, *y + shadowoffset);
			}

			if (1);

			if (*x + xscale * curchar->width <= savedx + width) {
				if (savedy <= curchar->baseline + sp90) {
					if (curchar->baseline + sp90 + curchar->height <= savedy + height) {
						if (g_TextRotated90) {
							gSPTextureRectangleFlip(gdl++,
									(sp90 - curchar->baseline - curchar->height * g_TextScaleX) * 4 + var8007fae0,
									*x * 4 + var8007fadc,
									(sp90 - curchar->baseline) * 4 + var8007fae0,
									(*x + curchar->width) * 4 + var8007fadc,
									G_TX_RENDERTILE,
									var8007fae8 + 32,
									((curchar->height - 1) << 5) + var8007fae4 + 32,
									1024,
									65536 - 1024 / g_TextScaleX);
						} else {
							gSPTextureRectangle(gdl++,
									*x * 4 + var8007fadc,
									(sp90 + curchar->baseline) * 4 + var8007fae0,
									(*x + curchar->width * g_TextScaleX) * 4 + var8007fadc,
									(sp90 + curchar->baseline + curchar->height) * 4 + var8007fae0,
									G_TX_RENDERTILE,
									var8007fae4 + 32,
									var8007fae8 + 32,
									1024 / g_TextScaleX,
									1024);

							if (g_TextHoloRayEnabled) {
								text_calculate_blend_distance(*y + shadowoffset);

								if (g_TextBlendDistance >= *x / g_UiScaleX && *x / g_UiScaleX + curchar->width * g_TextScaleX >= g_TextBlendDistance) {
									g_TextHoloRayGdl = menugfx_draw_plane(g_TextHoloRayGdl,
											g_TextBlendDistance,
											curchar->baseline + sp90,
											g_TextBlendDistance,
											curchar->baseline + sp90 + curchar->height,
											g_Blend.colour04,
											g_Blend.colour04,
											MENUPLANE_00);
								}

								if (g_TextBlendDistance - 3 >= *x / g_UiScaleX && *x / g_UiScaleX + curchar->width * g_TextScaleX >= g_TextBlendDistance - 3) {
									g_TextHoloRayGdl = menugfx_draw_plane(g_TextHoloRayGdl,
											g_TextBlendDistance,
											curchar->baseline + sp90,
											g_TextBlendDistance,
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
								(*x + curchar->width * g_TextScaleX) * 4 + var8007fadc,
								(savedy + height) * 4 + var8007fae0,
								G_TX_RENDERTILE,
								var8007fae4 + 32,
								var8007fae8 + 32,
								1024 / g_TextScaleX,
								1024);
					}
				} else {
					if (curchar->baseline + sp90 + curchar->height >= savedy) {
						gSPTextureRectangle(gdl++,
								*x * 4 + var8007fadc,
								savedy * 4 + var8007fae0,
								(*x + curchar->width * g_TextScaleX) * 4 + var8007fadc,
								(curchar->baseline + sp90 + curchar->height) * 4 + var8007fae0,
								G_TX_RENDERTILE,
								var8007fae4 + 32,
								((savedy - sp90 - curchar->baseline) << 5) + var8007fae8 + 32,
								1024 / g_TextScaleX,
								1024);
					}
				}
			}
		}
	}
#endif

	*x += curchar->width * xscale;

	return gdl;
}

bool g_TextShadowEnabled = false;

void text_set_shadow_enabled(bool enabled)
{
	g_TextShadowEnabled = enabled;
}

void text_set_shadow_colour(u32 colour)
{
	var800a463c = colour;
}

/**
 * The v2 renderer has full support for all of PD's text rendering features.
 * - Text can be rotated 90 degrees.
 * - Shadows can be enabled/disabled and colour chosen using the above functions.
 * - The hologram refresh line can be enabled and disabled using their functions.
 * - In versions prior to JPN, shadows are drawn using the v1 renderer which
 *   means they don't use the special effects. In JPN they are drawn using a
 *   recursive call to v2 so they have all the special effects.
 * - JPN draws the shadows 4 times, each offset in each direction.
 * - Blend settings are supported, such as the fading out hologram effect and
 *   the wavy pattern in gun and function names during gameplay.
 */
Gfx *text_render_v2(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *chars, struct font *font,
		u32 textcolour, s32 width, s32 height, s32 shadowoffset, s32 lineheight)
{
	s32 savedx;
	s32 savedy;
	u8 prevchar;
	s32 scalex;
	u32 textcolourforshadow;
	u32 shadowcolour;
	s32 shadowx;
	s32 shadowy;
#if VERSION >= VERSION_JPN_FINAL
	s32 savedmode;
	s32 savedtypes;
#endif
	f32 alpha;

	static u32 sbrd = 0x00000000;

	scalex = g_TextScaleX;

	if (g_TextRotated90) {
		*y *= g_UiScaleX;
		scalex = 1;
	} else {
		*x *= g_UiScaleX;
	}

	if (g_TextShadowEnabled) {
		alpha = (1.0f - menu_get_sin_osc_frac(40.0f)) * 100.0f + 150.0f;
		shadowx = *x / g_UiScaleX;
		shadowy = *y;
		shadowcolour = var800a463c;
#if VERSION >= VERSION_JPN_FINAL
		savedmode = g_Blend.diagmode;
		savedtypes = g_Blend.types;

		if (!g_TextRotated90) {
			shadowy--;
		}

		main_override_variable("sbrd", &sbrd);

		if (sbrd) {
			shadowcolour = sbrd;
		}

		g_Blend.types &= ~BLENDTYPE_WAVE;

		if (g_Blend.diagmode != DIAGMODE_FADEIN) {
			g_Blend.types &= ~BLENDTYPE_DIAGONAL;
		} else {
			g_Blend.diagmode = DIAGMODE_FADEOUT;
		}

		g_TextShadowEnabled = false;

		shadowx = *x / g_UiScaleX + 1;
		shadowy = *y - 1;
		gdl = text_render_v2(gdl, &shadowx, &shadowy, text, chars, font, shadowcolour, width, height, shadowoffset, lineheight);

		shadowx = *x / g_UiScaleX + 1;
		shadowy = *y + 1;
		gdl = text_render_v2(gdl, &shadowx, &shadowy, text, chars, font, shadowcolour, width, height, shadowoffset, lineheight);

		shadowx = *x / g_UiScaleX - 1;
		shadowy = *y - 1;
		gdl = text_render_v2(gdl, &shadowx, &shadowy, text, chars, font, shadowcolour, width, height, shadowoffset, lineheight);

		shadowx = *x / g_UiScaleX - 1;
		shadowy = *y + 1;
		gdl = text_render_v2(gdl, &shadowx, &shadowy, text, chars, font, shadowcolour, width, height, shadowoffset, lineheight);

		g_TextShadowEnabled = true;

		g_Blend.types = savedtypes;
		g_Blend.diagmode = savedmode;
#else
		textcolourforshadow = (textcolour & 0xffffff00) | (u32) alpha;

		main_override_variable("sbrd", &sbrd);

		if (sbrd) {
			shadowcolour = sbrd;
		}

		gdl = text_render_v1(gdl, &shadowx, &shadowy, text, chars, font, textcolourforshadow, shadowcolour, width, height, shadowoffset, lineheight);
#endif
	}

#if VERSION >= VERSION_JPN_FINAL
	if (!g_TextRotated90) {
		*y = *y - 1;
	}
#endif

	main_override_variable("lalpha", &g_TextLAlpha);
	main_override_variable("subtlety", &g_TextSubleTY);
	main_override_variable("subtletx", &g_TextSubtleTX);
	main_override_variable("coly", &g_TextColourY);
	main_override_variable("colx", &g_TextColourX);
	main_override_variable("lfade", &g_TextLFade);
	main_override_variable("llimbo", &g_TextLLimbo);

	savedx = *x;
	savedy = *y;
	prevchar = 'H';

#if VERSION >= VERSION_JPN_FINAL
	if (lineheight == -1) {
		lineheight = chars['['].baseline + chars['['].height;
	} else {
		lineheight = 13;
	}
#else
	if (lineheight == 0) {
		lineheight = chars['['].height + chars['['].baseline;
	}

	if (g_Jpn && lineheight < 14) {
		lineheight = 14;
	}
#endif

	gDPPipeSync(gdl++);
	gDPSetTextureLUT(gdl++, G_TT_IA16);

#if VERSION >= VERSION_JPN_FINAL
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(var800801d8jf));
	var80080104jf = true;
#else
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(var8007fb3c));
#endif

	gDPLoadSync(gdl++);
	gDPLoadTLUTCmd(gdl++, 6, 15);
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
	gDPSetPrimColorViaWord(gdl++, 0, 0, textcolour);
	gDPPipeSync(gdl++);

	g_Blend.colour04 = textcolour;
	g_Blend.colour44 = textcolour;

#if VERSION >= VERSION_PAL_BETA
	if (text != NULL) {
		while (*text != '\0') {
			if (*text == ' ') {
				*x += scalex * 5;
				prevchar = 'H';
				text++;
			} else if (*text == '\n') {
				if (g_TextParaOverlap >= 0 && savedx == *x) {
					*y += g_TextParaOverlap;
				} else {
					*y += lineheight;
				}

				*x = savedx;
				prevchar = 'H';
				text++;
			} else {
				struct fontchar *thischardata;
				struct fontchar *prevchardata;

				text_parse_char(&text, &thischardata, &prevchardata, chars, &prevchar);

				gdl = text_render_char_v2(gdl, x, y, thischardata, prevchardata, font, savedx, savedy, width, height, shadowoffset);
			}
		}
	}
#else
	if (text != NULL) {
		while (*text != '\0') {
			if (*text == ' ') {
				prevchar = 'H';
				*x += scalex * 5;
				text++;
			} else if (*text == '\n') {
				prevchar = 'H';
				text++;

				if (g_TextParaOverlap >= 0 && savedx == *x) {
					*y += g_TextParaOverlap;
				} else {
					*y += lineheight;
				}

				*x = savedx;
			} else if (*text < 0x80) {
				gdl = text_render_char_v2(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21], font, savedx, savedy, width, height, shadowoffset);
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
				tmpchar.pixeldata = (void *)lang_get_jpn_char_pixels(codepoint);

				gdl = text_render_char_v2(gdl, x, y, &tmpchar, &tmpchar, font, savedx, savedy, width, height, shadowoffset);

				text += 2;
			}
		}
	}
#endif

	if (g_TextRotated90) {
		*y = *y / g_UiScaleX;
	} else {
		*x = *x / g_UiScaleX;
	}

	return gdl;
}

Gfx *text_configure_colours_v1(Gfx *gdl, s32 x, s32 y)
{
	u32 colour = text_get_colour_at_pos(x, y, g_Blend.colour04);

	if (colour != g_Blend.colour44) {
		gDPSetColor(gdl++, G_SETENVCOLOR, colour);
	}

	g_Blend.colour44 = colour;

	colour = (g_Blend.colour08 & 0xffffff00) | (text_get_colour_at_pos(x, y, g_Blend.colour08) & 0xff);

	if (colour != g_Blend.colour48) {
		gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	}

	g_Blend.colour48 = colour;

	return gdl;
}

Gfx *text_render_char_v1(Gfx *gdl, s32 *x, s32 *y, struct fontchar *thischardata, struct fontchar *prevchardata,
		struct font *font, s32 left, s32 top, s32 width, s32 height, s32 shadowoffset)
{
	s32 tmp;
	s32 sp38;

	sp38 = *y + shadowoffset;

	tmp = font->kerning[prevchardata->kerningindex * 13 + thischardata->kerningindex] + g_TextCharOverlap;
	*x -= (tmp - 1) * g_TextScaleX;

	if (*x > 0
			&& *x <= vi_get_width()
			&& sp38 + thischardata->baseline <= vi_get_height()
			&& *x <= left + width
			&& thischardata->baseline + sp38 <= top + height
			&& *x >= left
			&& sp38 + thischardata->baseline + thischardata->height >= top) {
#if VERSION >= VERSION_JPN_FINAL
		if (thischardata->pixeldata == NULL) {
			thischardata->pixeldata = (void *)lang_get_jpn_char_pixels(thischardata->index - 0x80);
		}
#else
		if (g_Blend.types) {
			gdl = text_configure_colours_v1(gdl, *x / g_UiScaleX, *y + shadowoffset);
		}
#endif

		gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, thischardata->pixeldata);
		gDPLoadSync(gdl++);
		gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, ((thischardata->height * 8 + 17) >> 1) - 1, 2048);
		gDPPipeSync(gdl++);

		gdl = text_render_char_v1_part2(gdl, *x - g_TextScaleX, sp38 - 1, thischardata, left, top - 1, width, height);
	}

	*x += thischardata->width * g_TextScaleX;

	return gdl;
}

Gfx *text_render_char_v1_part2(Gfx *gdl, s32 x, s32 y, struct fontchar *char1, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
	if (arg4 + arg6 >= char1->width + x + 2) {
		if (y + char1->baseline >= arg5) {
			if (arg5 + arg7 >= y + char1->baseline + char1->height + 2) {
				if (g_TextRotated90) {
					gSPTextureRectangleFlip(gdl++,
							((y - char1->baseline) - ((char1->height + 2) * g_TextScaleX)) * 4,
							x * 4,
							(y - char1->baseline) * 4,
							(x + char1->width + 2) * 4,
							G_TX_RENDERTILE,
							0,
							(char1->height + 1) << 5,
							1024 / g_TextScaleX,
							-1024);
				} else {
					gSPTextureRectangle(gdl++,
							x * 4,
							(y + char1->baseline) * 4,
							(x + char1->width * g_TextScaleX + 2) * 4,
							(y + char1->baseline + char1->height + 2) * 4,
							G_TX_RENDERTILE,
							0,
							0,
							1024 / g_TextScaleX,
							1024);
				}
			} else {
				if (arg5 + arg7 >= y + char1->baseline) {
					gSPTextureRectangle(gdl++,
							x * 4,
							(y + char1->baseline) * 4,
							(x + char1->width * g_TextScaleX + 2) * 4,
							(arg5 + arg7) * 4,
							G_TX_RENDERTILE,
							0,
							0,
							1024 / g_TextScaleX,
							1024);
				}
			}
		} else {
			if (y + char1->baseline + char1->height + 2 >= arg5) {
				gSPTextureRectangle(gdl++,
						x * 4,
						arg5 * 4,
						(x + char1->width * g_TextScaleX + 2) * 4,
						(y + char1->baseline + char1->height + 2) * 4,
						G_TX_RENDERTILE,
						0,
						(arg5 - char1->baseline - y) << 5,
						1024 / g_TextScaleX,
						1024);
			}
		}
	}

	return gdl;
}

/**
 * The v1 renderer is likely very similar, if not the same as GE's.
 *
 * It has support for shadows and implements them using the environment colour.
 *
 * It does not support the hologram refresh effect, oscillating focus colour
 * or blend effects.
 */
Gfx *text_render_v1(Gfx *gdl, s32 *x, s32 *y, char *text,
		struct fontchar *chars, struct font *font, u32 textcolour, u32 glowcolour,
		s32 width, s32 height, s32 shadowoffset, s32 lineheight)
{
	s32 savedx;
	s32 savedy;
#if VERSION >= VERSION_PAL_BETA
	u8 prevchar;
#else
	s32 prevchar;
#endif

	*x *= g_UiScaleX;

	savedx = *x;
	savedy = *y;
	prevchar = 'H';

#if VERSION >= VERSION_JPN_FINAL
	if (lineheight == -1) {
		lineheight = chars['['].baseline + chars['['].height;
	} else {
		lineheight = 13;
	}
#else
	if (lineheight == 0) {
		lineheight = chars['['].height + chars['['].baseline;
	}

	if (g_Jpn && lineheight < 14) {
		lineheight = 14;
	}
#endif

	gDPPipeSync(gdl++);
	gDPSetTextureLUT(gdl++, G_TT_IA16);
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(&var8007fb5c));
	gDPLoadSync(gdl++);
	gDPLoadTLUTCmd(gdl++, 6, 31);

#if VERSION >= VERSION_JPN_FINAL
	// Use clamp
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, 1, 1, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
#else
	// Use wrap
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, 1, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
#endif

	gDPSetTileSize(gdl++, 1, 0, 0, 0x007c, 0x007c);
	gDPSetCycleType(gdl++, G_CYC_2CYCLE);
	gDPSetCombineLERP(gdl++,
			ENVIRONMENT, PRIMITIVE, TEXEL1_ALPHA, PRIMITIVE, 0, 0, 0, TEXEL0,
			0, 0, 0, COMBINED, COMBINED, 0, ENVIRONMENT, 0);
	gDPSetPrimColorViaWord(gdl++, 0, 0, glowcolour);
	gDPSetEnvColorViaWord(gdl++, textcolour);
	gDPPipeSync(gdl++);

	g_Blend.colour08 = glowcolour;
	g_Blend.colour48 = glowcolour;
	g_Blend.colour04 = textcolour;
	g_Blend.colour44 = textcolour;

#if VERSION >= VERSION_PAL_BETA
	while (*text != '\0') {
		if (*text == ' ') {
			*x += g_TextScaleX * 5;
			prevchar = 'H';
			text++;
		} else if (*text == '\n') {
			*x = savedx;
			*y += lineheight;
			prevchar = 'H';
			text++;
		} else {
			struct fontchar *thischardata;
			struct fontchar *prevchardata;

			text_parse_char(&text, &thischardata, &prevchardata, chars, &prevchar);

			gdl = text_render_char_v1(gdl, x, y, thischardata, prevchardata,
					font, savedx, savedy, width * g_TextScaleX, height, shadowoffset);
		}
	}
#else
	while (*text != '\0') {
		if (*text == ' ') {
			*x += g_TextScaleX * 5;
			prevchar = 'H';
			text++;
		} else if (*text == '\n') {
			*x = savedx;
			*y += lineheight;
			prevchar = 'H';
			text++;
		} else if (*text < 0x80) {
			gdl = text_render_char_v1(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21],
					font, savedx, savedy, width * g_TextScaleX, height, shadowoffset);
			prevchar = *text;
			text++;
		} else {
			u16 codepoint = ((*text & 0x7f) << 7) | (text[1] & 0x7f);
			struct fontchar chardata = {0, 0, 12, 11};

			if (codepoint & 0x2000) {
				chardata.width = 15;
				chardata.height = 16;
			}

			if ((codepoint & 0x1fff) >= 0x3c8) {
				codepoint = 2;
			}

			chardata.index = codepoint + 0x80;
			chardata.pixeldata = (void *)lang_get_jpn_char_pixels(codepoint);

			gdl = text_render_char_v1(gdl, x, y, &chardata, &chardata, font, savedx, savedy, width * g_TextScaleX, height, shadowoffset);

			text += 2;
		}
	}
#endif

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);

	*x = *x / g_UiScaleX;

	return gdl;
}

#if VERSION == VERSION_JPN_FINAL
/**
 * In all versions prior to JPN, there are two functions to render text:
 * text_render_v1 and text_render_v2.
 *
 * For the Japanese version, Rare wanted to switch many of the calls from
 * text_render_v1 to text_render_v2. They introduced this helper function which
 * has the same arguments as text_render_v1 but wraps text_render_v2. This means
 * they only had to replace the function name in all the places where they
 * wanted to switch to the other function rather than change the arguments too.
 *
 * In decomp, to avoid ifdefs everywhere where it was changed, we call
 * text_render_vx. In versions prior to JPN this is redefined to text_render_v1
 * in text.h. In JPN it's Rare's wrapper function.
 */
Gfx *text_render_vx(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *font1, struct font *font2, u32 textcolour, u32 shadowcolour, s32 width, s32 height, s32 shadowoffset, s32 lineheight)
{
	return text_render_v2(gdl, x, y, text, font1, font2, textcolour, width, height, shadowoffset, lineheight);
}
#endif

#if VERSION < VERSION_PAL_BETA && MATCHING
GLOBAL_ASM(
glabel text_measure
/*  f1572f8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1572fc:	afb10008 */ 	sw	$s1,0x8($sp)
/*  f157300:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f157304:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f157308:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f15730c:	afb2000c */ 	sw	$s2,0xc($sp)
/*  f157310:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f157314:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f157318:	00808025 */ 	or	$s0,$a0,$zero
/*  f15731c:	24030048 */ 	addiu	$v1,$zero,0x48
/*  f157320:	00001025 */ 	or	$v0,$zero,$zero
/*  f157324:	16200004 */ 	bnez	$s1,.L0f157338
/*  f157328:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f15732c:	90ee0446 */ 	lbu	$t6,0x446($a3)
/*  f157330:	80ef0445 */ 	lb	$t7,0x445($a3)
/*  f157334:	01cf8821 */ 	addu	$s1,$t6,$t7
.L0f157338:
/*  f157338:	3c188008 */ 	lui	$t8,%hi(g_Jpn)
/*  f15733c:	8f184120 */ 	lw	$t8,%lo(g_Jpn)($t8)
/*  f157340:	2a21000e */ 	slti	$at,$s1,0xe
/*  f157344:	13000004 */ 	beqz	$t8,.L0f157358
/*  f157348:	00000000 */ 	nop
/*  f15734c:	10200002 */ 	beqz	$at,.L0f157358
/*  f157350:	00000000 */ 	nop
/*  f157354:	2411000e */ 	addiu	$s1,$zero,0xe
.L0f157358:
/*  f157358:	10c00059 */ 	beqz	$a2,.L0f1574c0
/*  f15735c:	00000000 */ 	nop
/*  f157360:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f157364:	3c148008 */ 	lui	$s4,%hi(g_TextCharOverlap)
/*  f157368:	2694fac4 */ 	addiu	$s4,$s4,%lo(g_TextCharOverlap)
/*  f15736c:	10800054 */ 	beqz	$a0,.L0f1574c0
/*  f157370:	00804025 */ 	or	$t0,$a0,$zero
/*  f157374:	2413000d */ 	addiu	$s3,$zero,0xd
/*  f157378:	2412000c */ 	addiu	$s2,$zero,0xc
/*  f15737c:	240c000a */ 	addiu	$t4,$zero,0xa
/*  f157380:	240b0020 */ 	addiu	$t3,$zero,0x20
/*  f157384:	8fa90028 */ 	lw	$t1,0x28($sp)
.L0f157388:
/*  f157388:	1568000a */ 	bne	$t3,$t0,.L0f1573b4
/*  f15738c:	00000000 */ 	nop
/*  f157390:	90d90001 */ 	lbu	$t9,0x1($a2)
/*  f157394:	24030048 */ 	addiu	$v1,$zero,0x48
/*  f157398:	11990004 */ 	beq	$t4,$t9,.L0f1573ac
/*  f15739c:	00000000 */ 	nop
/*  f1573a0:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f1573a4:	25cf0005 */ 	addiu	$t7,$t6,0x5
/*  f1573a8:	acaf0000 */ 	sw	$t7,0x0($a1)
.L0f1573ac:
/*  f1573ac:	10000041 */ 	b	.L0f1574b4
/*  f1573b0:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f1573b4:
/*  f1573b4:	1588000c */ 	bne	$t4,$t0,.L0f1573e8
/*  f1573b8:	29010080 */ 	slti	$at,$t0,0x80
/*  f1573bc:	8ca40000 */ 	lw	$a0,0x0($a1)
/*  f1573c0:	0044082a */ 	slt	$at,$v0,$a0
/*  f1573c4:	50200003 */ 	beqzl	$at,.L0f1573d4
/*  f1573c8:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f1573cc:	00801025 */ 	or	$v0,$a0,$zero
/*  f1573d0:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f1573d4:
/*  f1573d4:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1573d8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1573dc:	0311c821 */ 	addu	$t9,$t8,$s1
/*  f1573e0:	10000034 */ 	b	.L0f1574b4
/*  f1573e4:	ae190000 */ 	sw	$t9,0x0($s0)
.L0f1573e8:
/*  f1573e8:	5020001d */ 	beqzl	$at,.L0f157460
/*  f1573ec:	290100c0 */ 	slti	$at,$t0,0xc0
/*  f1573f0:	308800ff */ 	andi	$t0,$a0,0xff
/*  f1573f4:	01120019 */ 	multu	$t0,$s2
/*  f1573f8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1573fc:	00007012 */ 	mflo	$t6
/*  f157400:	00ee5021 */ 	addu	$t2,$a3,$t6
/*  f157404:	8d4ffe78 */ 	lw	$t7,-0x188($t2)
/*  f157408:	00720019 */ 	multu	$v1,$s2
/*  f15740c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f157410:	0138c821 */ 	addu	$t9,$t1,$t8
/*  f157414:	00007012 */ 	mflo	$t6
/*  f157418:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f15741c:	8df8fe78 */ 	lw	$t8,-0x188($t7)
/*  f157420:	03130019 */ 	multu	$t8,$s3
/*  f157424:	00007012 */ 	mflo	$t6
/*  f157428:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f15742c:	032fc021 */ 	addu	$t8,$t9,$t7
/*  f157430:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f157434:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f157438:	9158fe77 */ 	lbu	$t8,-0x189($t2)
/*  f15743c:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f157440:	01d92021 */ 	addu	$a0,$t6,$t9
/*  f157444:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f157448:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f15744c:	01c4c823 */ 	subu	$t9,$t6,$a0
/*  f157450:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f157454:	10000017 */ 	b	.L0f1574b4
/*  f157458:	90c3ffff */ 	lbu	$v1,-0x1($a2)
/*  f15745c:	290100c0 */ 	slti	$at,$t0,0xc0
.L0f157460:
/*  f157460:	5020000c */ 	beqzl	$at,.L0f157494
/*  f157464:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f157468:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f15746c:	8e980000 */ 	lw	$t8,0x0($s4)
/*  f157470:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f157474:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f157478:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f15747c:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f157480:	01c4c823 */ 	subu	$t9,$t6,$a0
/*  f157484:	272f000b */ 	addiu	$t7,$t9,0xb
/*  f157488:	1000000a */ 	b	.L0f1574b4
/*  f15748c:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f157490:	8d380000 */ 	lw	$t8,0x0($t1)
.L0f157494:
/*  f157494:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f157498:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f15749c:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f1574a0:	030e2021 */ 	addu	$a0,$t8,$t6
/*  f1574a4:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f1574a8:	03247823 */ 	subu	$t7,$t9,$a0
/*  f1574ac:	25f8000f */ 	addiu	$t8,$t7,0xf
/*  f1574b0:	acb80000 */ 	sw	$t8,0x0($a1)
.L0f1574b4:
/*  f1574b4:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f1574b8:	1480ffb3 */ 	bnez	$a0,.L0f157388
/*  f1574bc:	00804025 */ 	or	$t0,$a0,$zero
.L0f1574c0:
/*  f1574c0:	3c0e8008 */ 	lui	$t6,%hi(g_UiScaleX)
/*  f1574c4:	8dcefac0 */ 	lw	$t6,%lo(g_UiScaleX)($t6)
/*  f1574c8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1574cc:	3c0f8008 */ 	lui	$t7,%hi(g_TextScaleX)
/*  f1574d0:	55c10008 */ 	bnel	$t6,$at,.L0f1574f4
/*  f1574d4:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f1574d8:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f1574dc:	8deffad0 */ 	lw	$t7,%lo(g_TextScaleX)($t7)
/*  f1574e0:	032f0019 */ 	multu	$t9,$t7
/*  f1574e4:	0000c012 */ 	mflo	$t8
/*  f1574e8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1574ec:	00000000 */ 	nop
/*  f1574f0:	8cae0000 */ 	lw	$t6,0x0($a1)
.L0f1574f4:
/*  f1574f4:	01c2082a */ 	slt	$at,$t6,$v0
/*  f1574f8:	50200003 */ 	beqzl	$at,.L0f157508
/*  f1574fc:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f157500:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f157504:	8fb00004 */ 	lw	$s0,0x4($sp)
.L0f157508:
/*  f157508:	8fb10008 */ 	lw	$s1,0x8($sp)
/*  f15750c:	8fb2000c */ 	lw	$s2,0xc($sp)
/*  f157510:	8fb30010 */ 	lw	$s3,0x10($sp)
/*  f157514:	8fb40014 */ 	lw	$s4,0x14($sp)
/*  f157518:	03e00008 */ 	jr	$ra
/*  f15751c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);
#else
// Mismatch: Regalloc
void text_measure(s32 *textheight, s32 *textwidth, char *text, struct fontchar *font1, struct font *font2, s32 lineheight)
{
	char prevchar;
	char thischar;
	s32 longest;
#if VERSION == VERSION_JPN_FINAL
	s32 overlap = 0;
	struct fontchar *tmp2 = font1;
	struct fontchar *thischardata;
	struct fontchar *prevchardata;
#endif
	s32 tmp;

	prevchar = 'H';
	thischar = '\0';
	longest = 0;
	*textheight = 0;
	*textwidth = 0;

#if VERSION == VERSION_JPN_FINAL
	if (lineheight == -1) {
		lineheight = font1['['].baseline + font1['['].height;
	} else {
		lineheight = 13;
	}
#else
	if (lineheight == 0) {
		lineheight = font1['['].baseline + font1['['].height;
	}

	if (g_Jpn && lineheight < 14) {
		lineheight = 14;
	}
#endif

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
#if VERSION >= VERSION_JPN_FINAL
				*textwidth -= overlap;
				overlap = 0;
#endif

				if (*textwidth > longest) {
					longest = *textwidth;
				}

				*textwidth = 0;
				*textheight += lineheight;
				text++;
			} else {
#if VERSION >= VERSION_JPN_FINAL
				text_parse_char(&text, &thischardata, &prevchardata, font1, &prevchar);

				overlap = 0;

				if (thischardata->index == 0xbe) {
					overlap = 4;
				}

				if (thischardata->index == 0x84) {
					overlap = 7;
				}

				if (font2) {
					tmp = font2->kerning[prevchardata->kerningindex * 13 + thischardata->kerningindex] + g_TextCharOverlap - 1;
				} else {
					tmp = 0;
				}

				*textwidth = *textwidth + thischardata->width - tmp;
#elif VERSION >= VERSION_PAL_BETA
				struct fontchar *thischardata;
				struct fontchar *prevchardata;

				text_parse_char(&text, &thischardata, &prevchardata, font1, &prevchar);

				tmp = font2->kerning[prevchardata->kerningindex * 13 + thischardata->kerningindex] + g_TextCharOverlap - 1;
				*textwidth = *textwidth + thischardata->width - tmp;
#else
				if (*text < 0x80) {
					// Normal single-byte character
					thischar = *text;
					tmp = font2->kerning[font1[prevchar - 0x21].kerningindex * 13 + font1[thischar - 0x21].kerningindex] + g_TextCharOverlap - 1;
					*textwidth = font1[thischar - 0x21].width + *textwidth - tmp;

					prevchar = *text;
					text++;
				} else if (*text < 0xc0) {
					// Multi-byte character
					tmp = font2->kerning[0] + g_TextCharOverlap - 1;
					*textwidth = *textwidth - tmp + 11;
					text += 2;
				} else {
					// Multi-byte character
					tmp = font2->kerning[0] + g_TextCharOverlap - 1;
					*textwidth = *textwidth - tmp + 15;
					text += 2;
				}
#endif
			}
		}
	}

	// @bug? Shouldn't this go at the very end of the function?
	if (g_UiScaleX == 1) {
		*textwidth *= g_TextScaleX;
	}

#if VERSION >= VERSION_JPN_FINAL
	*textwidth -= overlap;
#endif

	if (longest > *textwidth) {
		*textwidth = longest;
	}
}
#endif

#if VERSION == VERSION_JPN_FINAL
bool text_stub(s32 arg0, s32 arg1)
{
	return false;
}
#endif

void text_wrap(s32 wrapwidth, char *src, char *dst, struct fontchar *chars, struct font *font)
{
#if VERSION >= VERSION_JPN_FINAL
	s32 curlinewidth = 0;
	s32 i = 0;
	s32 wordlen;
	s32 wordwidth;
	s32 wordheight = 0;
	bool more = true;
	bool itfits;
	bool keepchar;
	s32 unusedwordwidth;
	char curword[32];
	bool forcespace;

	while (more == true) {
		wordlen = 0;
		wordwidth = 0;
		unusedwordwidth = 0;
		forcespace = false;
		keepchar = true;

		while (keepchar) {
			u16 codepoint = 0;
			bool multibyte = false;
			s32 charwidth = 0;
			u8 c;
			u8 c1;
			u8 c2;

			if (*src < 0x80) {
				c = *src;
			} else {
				multibyte = true;

				c1 = src[0];
				c2 = src[1];
				codepoint = ((c1 & 0x7f) << 7) | (c2 & 0x7f);
				c = text_codepoint_to_sbchar(codepoint);

				if (c2 == '\0') {
					multibyte = false;
				}
			}

			if (c == '\0') {
				keepchar = false;

				if (multibyte) {
					if (codepoint >= 0x34 && codepoint < 0x4e) {
						keepchar = true;
					}

					if (codepoint >= 0xaf && codepoint < 0xb8) {
						keepchar = true;
					}

					if (codepoint == 0x104) {
						keepchar = true;
					}

					if (codepoint == 0x105) {
						keepchar = true;
					}

					if (wordlen == 0) {
						keepchar = true;
					}

					charwidth = 11;
				}
			} else {
				if (c > ' ') {
					keepchar = true;
				} else {
					keepchar = false;
				}

				charwidth = chars[c - 0x21].width;

				if (!keepchar && wordlen == 0) {
					if (c != '\0' && c != ' ') {
						keepchar = true;
					}

					if (c == ' ') {
						forcespace = true;
					}
				}

				if (wordlen != 0
						&& ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) {
					if (curword[wordlen - 1] >= 0x80) {
						u8 c1 = curword[wordlen - 2];
						u8 c2 = curword[wordlen - 1];
						u16 codepoint = ((c1 & 0x7f) << 7) | (c2 & 0x7f);
						u8 c = text_codepoint_to_sbchar(codepoint);

						if (c == '\0') {
							keepchar = false;
						}
					}
				}
			}

			if (keepchar) {
				curword[wordlen] = *src;
				src++;
				wordlen++;

				if (multibyte) {
					curword[wordlen] = *src;
					src++;
					wordlen++;
				}

				unusedwordwidth += charwidth;
			}
		}

		curword[wordlen] = '\0';

		text_measure(&wordheight, &wordwidth, curword, chars, font, 0);

		curlinewidth += wordwidth;

		if (curlinewidth <= wrapwidth) {
			itfits = true;
		} else {
			itfits = false;
		}

		if (*src == '\n') {
			if (!itfits) {
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}
			}

			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			src++;

			curlinewidth = 0;

			*dst = '\n';
			dst++;
		} else if (*src == '\0') {
			if (!itfits) {
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}
			}

			src++;

			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			*dst = '\0';
			more = false;
		} else {
			if (!itfits) {
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}

				curlinewidth = wordwidth + g_WrapIndentCount * SPACE_WIDTH;
			}

			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			if (*src == ' ' || forcespace) {
				if (*src >= 0x80) {
					src++;
				}

				src++;

				curlinewidth += SPACE_WIDTH;

				*dst = ' ';
				dst++;
			}
		}
	}
#else
	s32 curlinewidth = 0;
	s32 i;
	s32 wordlen;
	s32 wordwidth;
	s32 wordheight = 0;
	bool more = true;
	bool itfits;
	bool keepchar;
	s32 unusedwordwidth;
	char curword[32];

	while (more == true) {
		// Load the next word
		wordwidth = 0;
		wordlen = 0;
		unusedwordwidth = 0;

		while (*src > ' ') {
			curword[wordlen] = *src;
			unusedwordwidth += chars[*src - 0x21].width;
			src++;
			wordlen++;

#if VERSION >= VERSION_PAL_FINAL
			if (g_Jpn)
#endif
			{
				if (curword[wordlen - 1] >= 0x80) {
					curword[wordlen] = *src;
					unusedwordwidth += chars[*src - 0x21].width;
					src++;
					wordlen++;
				}
			}
		}

		curword[wordlen] = '\0';

		text_measure(&wordheight, &wordwidth, curword, chars, font, 0);

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

				curlinewidth = wordwidth + g_WrapIndentCount * SPACE_WIDTH;
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
#endif
}
