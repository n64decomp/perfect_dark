#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/title.h"
#include "game/tex.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/menugfx.h"
#include "game/menu.h"
#include "game/credits.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/gfxmemory.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/joy.h"
#include "lib/main.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "lib/rng.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

/**
 * The retain values are transition settings for credits. Most credits only
 * appear on a single slide, so RETAIN_NONE is used for those which makes them
 * transition in and out at the start and end of that slide.
 *
 * For credits that span multiple slides, the credit is repeated on each slide.
 * On the first slide it should use RETAIN OUT, on inner slides use RETAIN_BOTH
 * and on the final slide use RETAIN_IN.
 */

#define RETAIN_NONE 0
#define RETAIN_OUT  1
#define RETAIN_IN   2
#define RETAIN_BOTH 3

#define HDIR_RIGHT 0
#define HDIR_MID   1
#define HDIR_LEFT  2

#define VDIR_BOTTOM 0
#define VDIR_MID    1
#define VDIR_TOP    2

#define STRETCH_NONE         0
#define STRETCH_VERTICALLY   1
#define STRETCH_HORIZONTALLY 2
#define STRETCH_3            3

f32 var800a4160;
u32 var800a4164;
u32 var800a4168;
u32 var800a416c;
struct creditsdata *g_CreditsData;

bool var8007f130 = false;
bool g_CreditsAltTitleRequested = false;
bool g_CreditsUsingAltTitle = false;

void func0f1371b0(struct gfxvtx *vertices, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
	f32 a = arg2 * sinf(arg1) + arg3 * cosf(arg1);
	f32 b = arg2 * cosf(arg1) - arg3 * sinf(arg1);

	vertices[0].unk08 = (sinf(arg4) + cosf(arg4)) * arg5 + a;
	vertices[0].unk0a = (cosf(arg4) - sinf(arg4)) * arg6 + b;

	vertices[1].unk08 = (sinf(arg4 + 1.5707963705063f) + cosf(arg4 + 1.5707963705063f)) * arg5 + a;
	vertices[1].unk0a = (cosf(arg4 + 1.5707963705063f) - sinf(arg4 + 1.5707963705063f)) * arg6 + b;

	vertices[2].unk08 = (sinf(arg4 + 3.1415927410126f) + cosf(arg4 + 3.1415927410126f)) * arg5 + a;
	vertices[2].unk0a = (cosf(arg4 + 3.1415927410126f) - sinf(arg4 + 3.1415927410126f)) * arg6 + b;

	vertices[3].unk08 = (sinf(arg4 + 4.7123889923096f) + cosf(arg4 + 4.7123889923096f)) * arg5 + a;
	vertices[3].unk0a = (cosf(arg4 + 4.7123889923096f) - sinf(arg4 + 4.7123889923096f)) * arg6 + b;
}

void func0f137430(struct gfxvtx *vertices, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
	f32 a = arg2 * sinf(arg1) + arg3 * cosf(arg1);
	f32 b = arg2 * cosf(arg1) - arg3 * sinf(arg1);

	vertices[0].unk08 = (sinf(arg4) + cosf(arg4)) * arg5 + a;
	vertices[0].unk0a = (cosf(arg4) - sinf(arg4)) * arg6 + b;

	vertices[2].unk08 = (sinf(arg4 + 1.5707963705063f) + cosf(arg4 + 1.5707963705063f)) * arg5 + a;
	vertices[2].unk0a = (cosf(arg4 + 1.5707963705063f) - sinf(arg4 + 1.5707963705063f)) * arg6 + b;

	vertices[8].unk08 = (sinf(arg4 + 3.1415927410126f) + cosf(arg4 + 3.1415927410126f)) * arg5 + a;
	vertices[8].unk0a = (cosf(arg4 + 3.1415927410126f) - sinf(arg4 + 3.1415927410126f)) * arg6 + b;

	vertices[6].unk08 = (sinf(arg4 + 4.7123889923096f) + cosf(arg4 + 4.7123889923096f)) * arg5 + a;
	vertices[6].unk0a = (cosf(arg4 + 4.7123889923096f) - sinf(arg4 + 4.7123889923096f)) * arg6 + b;

	vertices[1].unk08 = (vertices[0].unk08 + vertices[2].unk08) / 2;
	vertices[1].unk0a = (vertices[0].unk0a + vertices[2].unk0a) / 2;

	vertices[3].unk08 = (vertices[0].unk08 + vertices[6].unk08) / 2;
	vertices[3].unk0a = (vertices[0].unk0a + vertices[6].unk0a) / 2;

	vertices[5].unk08 = (vertices[8].unk08 + vertices[2].unk08) / 2;
	vertices[5].unk0a = (vertices[8].unk0a + vertices[2].unk0a) / 2;

	vertices[7].unk08 = (vertices[6].unk08 + vertices[8].unk08) / 2;
	vertices[7].unk0a = (vertices[6].unk0a + vertices[8].unk0a) / 2;

	vertices[4].unk08 = (vertices[3].unk08 + vertices[5].unk08) / 2;
	vertices[4].unk0a = (vertices[3].unk0a + vertices[5].unk0a) / 2;
}

/**
 * Initialises the vertices coordinates. The generated x and y coordinates are:
 *
 * 0:  -1800  -1800
 * 1:  0      -1800
 * 2:  1800   -1800
 * 3:  -1800  0
 * 4:  0      0
 * 5:  1800   0
 * 6:  -1800  1800
 * 7:  0      1800
 * 8:  1800   1800
 */
void creditsInitVertices(struct gfxvtx *vertices, s32 z)
{
	s32 i;

	for (i = 0; i < 9; i++) {
		vertices[i].x = (i % 3) * 1800 - 1800;
		vertices[i].y = (i / 3) * 1800 - 1800;
		vertices[i].z = z;
	}
}

struct creditthing {
	/*0x00*/ f32 unk00;
	/*0x04*/ u8 s[9];
	/*0x10*/ u32 colours[3][3];
};

struct creditthing var8007f13c[] = {
	{ 0.20, { 0, 1, 0, 1, 2, 1, 0, 1, 0 }, { { 0x000064, 0x000064, 0x000000 }, { 0x003d84, 0x003d84, 0x000000 }, { 0x36003d, 0x36003d, 0x000000 } } },
	{ 1.00, { 0, 1, 0, 1, 2, 1, 0, 1, 0 }, { { 0x000037, 0x0079a2, 0x36003d }, { 0x0079a2, 0x36003d, 0x000037 }, { 0x36003d, 0x000037, 0x0079a2 } } },
	{ 0.20, { 0, 1, 0, 1, 2, 1, 0, 1, 0 }, { { 0x36003d, 0x51003f, 0x000037 }, { 0x51003f, 0x000037, 0x36003d }, { 0x0000a6, 0x36003d, 0x51003f } } },
	{ 0.20, { 0, 1, 0, 1, 2, 1, 0, 1, 0 }, { { 0x003d84, 0x003d84, 0x000064 }, { 0x000064, 0x003d84, 0x003d84 }, { 0x36003d, 0x003d84, 0x36003d } } },
	{ 0.20, { 0, 1, 0, 1, 2, 1, 0, 1, 0 }, { { 0x004345, 0x004345, 0x51003f }, { 0x000037, 0x000037, 0x004345 }, { 0x0079a2, 0x004345, 0x0079a2 } } },
	{ 0.20, { 0, 1, 0, 1, 2, 1, 0, 1, 0 }, { { 0x0000a6, 0x0000a6, 0x000000 }, { 0x0000a6, 0x0000a6, 0x000000 }, { 0x0000a6, 0x0000a6, 0x000000 } } },
	{ 0.01, { 0, 1, 0, 1, 2, 1, 0, 1, 0 }, { { 0x00ffff, 0x0000ff, 0x000000 }, { 0x00ffff, 0x0000ff, 0x000000 }, { 0x00ffff, 0x0000ff, 0x000000 } } },
	{ 0.01, { 2, 1, 2, 1, 0, 1, 2, 1, 2 }, { { 0x00ffff, 0x0000ff, 0x000000 }, { 0xffffff, 0xffffff, 0xffffff }, { 0xffffff, 0xffffff, 0xffffff } } },
};

void func0f137874(struct gfxvtx *vertices, u32 *colours, s32 arg2, s32 alpha, s32 arg4)
{
#if PAL
	s32 iVar1 = (s32)(var8007f13c[arg2].unk00 * var800a416c / (10.0f / 3.0f) + arg4) % 180;
#else
	s32 iVar1 = (s32)(var8007f13c[arg2].unk00 * var800a416c * 0.25f + arg4) % 180;
#endif
	s32 colour1index = iVar1 / 60;
	s32 colour2index;
	f32 tmp;
	u32 weight;
	s32 i;

	if (colour1index > 2) {
		colour1index = 0;
	}

	colour2index = colour1index + 1;

	if (colour2index > 2) {
		colour2index = 0;
	}

	for (i = 0; i < ARRAYCOUNT(var8007f13c[arg2].s);) {
		vertices[i].colour = var8007f13c[arg2].s[i] * 4;
		i++;
	}

	tmp = (iVar1 % 60) / 60.0f;
	weight = 255.0f * tmp;

	colours[0] = colourBlend(
			var8007f13c[arg2].colours[colour2index][0] << 8,
			var8007f13c[arg2].colours[colour1index][0] << 8, weight) | alpha;

	colours[1] = colourBlend(
			var8007f13c[arg2].colours[colour2index][1] << 8,
			var8007f13c[arg2].colours[colour1index][1] << 8, weight) | alpha;

	colours[2] = colourBlend(
			var8007f13c[arg2].colours[colour2index][2] << 8,
			var8007f13c[arg2].colours[colour1index][2] << 8, weight) | alpha;
}

struct creditsbgtype g_CreditsBgTypes[] = {
	{ 10000, 10000, -200, 0x04, 120, 0 },
	{ 1000,  1000,  -200, 0x05, 220, 0 },
	{ 1000,  10000, -50,  0x06, 220, 0 },
	{ 1000,  10000, -200, 0x26, 220, 0 },
	{ 500,   10000, -200, 0x26, 520, 0 },
	{ 1000,  20000, -50,  0x26, 120, 0 },
	{ 10000, 10000, -200, 0x2a, 120, 0 },
	{ 10000, 10000, -200, 0x2b, 80,  0 },
	{ 10000, 3000,  -200, 0x2b, 80,  0 },
	{ 3000,  3000,  -200, 0x2d, 120, 0 },
	{ 10000, 10000, -200, 0x07, 80,  0 },
	{ 10000, 1000,  -200, 0x2d, 220, 0 },
};

Gfx *creditsDrawBackgroundLayer(Gfx *gdl, u8 type, u8 layernum, f32 arg3, u32 alpha, s32 arg5)
{
	struct gfxvtx *vertices;
	u32 *colours;
	u32 stack;
	f32 a;
	f32 b;
	f32 c;
	f32 d;

	gdl = menugfx0f0e2498(gdl);

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);

	texSelect(&gdl, &g_TexGeneralConfigs[g_CreditsBgTypes[type].texturenum], 1, 1, 2, 1, NULL);

	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

	colours = gfxAllocateColours(3);
	vertices = gfxAllocateVertices(9);

	creditsInitVertices(vertices, (s32)((g_CreditsBgTypes[type].unk04 + 2000) * arg3) - 2000);

#if PAL
	d = g_CreditsData->bglayers[layernum].rotatespeed * var800a416c / (10.0f / 3.0f);
	a = g_CreditsData->bglayers[layernum].unk08 * var800a416c / (10.0f / 3.0f);
#else
	d = g_CreditsData->bglayers[layernum].rotatespeed * var800a416c * 0.25f;
	a = g_CreditsData->bglayers[layernum].unk08 * var800a416c * 0.25f;
#endif
	b = g_CreditsBgTypes[type].unk0c * 32.0f;
	c = g_CreditsBgTypes[type].unk10 * 32.0f;

	func0f137430(vertices, a, b, c, d, g_CreditsBgTypes[type].unk00, g_CreditsBgTypes[type].unk02);

	if (g_CreditsBgTypes[type].texturenum == 4) {
		alpha = alpha * 2 / 3;
	}

	if (g_CreditsBgTypes[type].texturenum == 0x26) {
		alpha = alpha * 2 / 3;
	}

	func0f137874(vertices, colours, g_CreditsData->bglayers[layernum].unk0c, alpha, arg5 * 90);

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 3);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 9);

	gDPTri4(gdl++, 0, 1, 3, 1, 4, 3, 1, 2, 5, 5, 4, 1);
	gDPTri4(gdl++, 3, 4, 7, 7, 6, 3, 4, 5, 7, 5, 8, 7);

	return gdl;
}

void creditsCopyBackgroundLayer(s32 srcindex, s32 dstindex, bool move)
{
	g_CreditsData->bglayers[dstindex].type = g_CreditsData->bglayers[srcindex].type;
	g_CreditsData->bglayers[dstindex].rotatespeed = g_CreditsData->bglayers[srcindex].rotatespeed;
	g_CreditsData->bglayers[dstindex].unk08 = g_CreditsData->bglayers[srcindex].unk08;
	g_CreditsData->bglayers[dstindex].unk0c = g_CreditsData->bglayers[srcindex].unk0c;

	if (move) {
		g_CreditsData->bglayers[srcindex].type = -1;
	}
}

Gfx *creditsDrawBackground(Gfx *gdl)
{
	s32 s1[4] = {-1, -1, -1, -1};
	u32 s5[4];
	f32 s4[4];
	s32 s2[4];

	u32 stack;
	f32 tmp = var800a416c / (PAL ? 1000.0f : 1200.0f);
	f32 bestvalue;
	s32 bestindex;
	s32 len = 0;
	s32 i;

	for (i = 0; i < 2; i++) {
		f32 value = i * 0.5f + tmp;
		value = value - (s32)value;

		if (value > 0.8f) {
			u32 uVar14;
			s32 val = i;

			if (g_CreditsData->bglayers[i + 2].type != -1) {
				val = i + 2;
				g_CreditsData->unk41b0[i] = 1;
			} else {
				g_CreditsData->unk41b0[i] = 2;
			}

			uVar14 = ((value - 0.8f) / 0.2f) * 255.0f;

			s1[len + 0] = val;
			s2[len + 0] = uVar14;
			s4[len + 0] = value - 1.0f;
			s5[len + 0] = i;

			s1[len + 1] = i;
			s2[len + 1] = 255 - (s32)uVar14;
			s4[len + 1] = value;
			s5[len + 1] = i;

			len += 2;
		} else {
			if (g_CreditsData->unk41b0[i] == 1) {
				creditsCopyBackgroundLayer(i + 2, i, true);
			}

			g_CreditsData->unk41b0[i] = 0;

			s1[len] = i;
			s2[len] = 255;
			s4[len] = value;
			s5[len] = i;

			len++;
		}
	}

	do {
		bestvalue = 10.0f;
		bestindex = -1;

		for (i = 0; i < len; i++) {
			if (s1[i] >= 0 && s4[i] < bestvalue) {
				bestindex = i;
				bestvalue = s4[i];
			}
		}

		if (bestindex >= 0) {
			gdl = creditsDrawBackgroundLayer(gdl, g_CreditsData->bglayers[s1[bestindex]].type,
					s1[bestindex], s4[bestindex], s2[bestindex], s5[bestindex]);

			s1[bestindex] = -1;
		}
	} while (bestindex != -1);

	return gdl;
}

u32 var8007f3dc = 0x00000000;
u32 var8007f3e0 = 0x00000000;
u32 var8007f3e4 = 0x00000000;
u32 var8007f3e8 = 0x00000001;
u32 var8007f3ec = 0x00000000;
u32 var8007f3f0 = 0x00000000;
u32 var8007f3f4 = 0x010301f4;
u32 var8007f3f8 = 0x008888ff;
u32 var8007f3fc = 0x00ff88ff;
u32 var8007f400 = 0x00ff8888;
u32 var8007f404 = 0x006666ff;
u32 var8007f408 = 0x41f00000;
u32 var8007f40c = 0x41f00000;

u32 var8007f410[][4] = {
	{ 0x0000ffff, 0x0044ffff, 0x0088ffff, 0x00ffffff },
	{ 0x8888ff7f, 0xff88ff7f, 0xff88887f, 0x6666ff7f },
	{ 0xff00007f, 0xffffff7f, 0xff00004f, 0xffffff4f },
	{ 0xffffff7f, 0xffffff5f, 0xffffff3f, 0xffffff1f },
};

struct g_CreditSpriteConfigs {
	s32 texturenum;
	s16 unk04;
	s16 unk06;
	s16 unk08;
	s16 unk0a;
};

struct g_CreditSpriteConfigs g_CreditSpriteConfigs[] = {
	{ 0x2a, 0, 0, 32, 32 },
	{ 0x2b, 0, 0, 32, 32 },
};

/**
 * Generate a random float between -range and range,
 * without being within 0.0001f of zero.
 *
 * This is only called with max = 0.00223f.
 */
f32 func0f1382e0(f32 range)
{
	f32 value;

	do {
		value = RANDOMFRAC() * range;
		value = (value + value) - range;
	} while (value < 0.0001f && value > -0.0001f);

	return value;
}

void creditsCreatePendingBgLayers(u32 mask)
{
	s32 i;

	for (i = 0; i < 2; i++) {
		s32 shift = i * 8;

		if (g_CreditsData->unk41b0[i] == 0) {
			g_CreditsData->bglayers[i + 2].type = random() % 12;
			g_CreditsData->bglayers[i + 2].rotatespeed = func0f1382e0(0.00223f);
			g_CreditsData->bglayers[i + 2].unk08 = func0f1382e0(0.00223f);


			if (((u8)(mask >> shift) & 2)) {
				g_CreditsData->bglayers[i + 2].unk0c = random() % 6;
			}
		}
	}
}

Gfx *creditsClearFramebuffer(Gfx *gdl, u32 colour)
{
	gSPDisplayList(gdl++, &var800613a0);

	gdl = gfxSetPrimColour(gdl, colour);

	gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());

	gdl = func0f153838(gdl);

	return gdl;
}

/**
 * An unused function. Renders a white line between two 3D coordinates.
 * The line would be 10 units high, though I'm not sure if that's big or not.
 */
Gfx *creditsRenderLine(Gfx *gdl, struct coord *from, struct coord *to)
{
	struct gfxvtx *vertices;
	u32 *colours;

	colours = gfxAllocateColours(2);
	vertices = gfxAllocateVertices(4);

	vertices[0].x = from->x;
	vertices[0].y = from->y;
	vertices[0].z = from->z;

	vertices[1].x = from->x;
	vertices[1].y = from->y + 10.0f;
	vertices[1].z = from->z;

	vertices[2].x = to->x;
	vertices[2].y = to->y + 10.0f;
	vertices[2].z = to->z;

	vertices[3].x = to->x;
	vertices[3].y = to->y;
	vertices[3].z = to->z;

	vertices[0].colour = 0;
	vertices[1].colour = 4;
	vertices[2].colour = 4;
	vertices[3].colour = 0;

	colours[0] = 0xffffffff;
	colours[1] = 0xffffffff;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);

	gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);

	return gdl;
}

void creditsResetSprites(void)
{
	f32 tmp;
	s32 i;

	g_CreditsData->unk41f5 = -1;
	g_CreditsData->unk41f6 = 0;
	g_CreditsData->unk41fc = 0;
	g_CreditsData->unk41fd = 0;
	g_CreditsData->unk41fe = 0;
	g_CreditsData->unk4200 = 0;
	g_CreditsData->unk41ff = 7;

	for (i = 0; i < ARRAYCOUNT(g_CreditsData->sprites); i++) {
		tmp = RANDOMFRAC();
		g_CreditsData->sprites[i].unk00 = (tmp + tmp) * 3000.0f - 3000.0f;

		tmp = RANDOMFRAC();
		g_CreditsData->sprites[i].unk04 = (tmp + tmp) * 3000.0f - 3000.0f;

		g_CreditsData->sprites[i].unk12 = random() % 4;
		g_CreditsData->sprites[i].unk14 = random() % 4;
		g_CreditsData->sprites[i].rotation = RANDOMFRAC() * M_BADTAU;

		if (g_CreditsData->unk4200 < g_CreditsData->unk41ff) {
			g_CreditsData->sprites[i].unk13 = g_CreditsData->unk4200
				+ (random() % (g_CreditsData->unk41ff - g_CreditsData->unk4200));
		} else {
			g_CreditsData->sprites[i].unk13 = g_CreditsData->unk4200;
		}

		g_CreditsData->sprites[i].unk10 = g_CreditsData->unk41fc;

		if (random() % 2 == 1) {
			g_CreditsData->sprites[i].confignum = g_CreditsData->unk41fd;
		} else {
			g_CreditsData->sprites[i].confignum = g_CreditsData->unk41fe;
		}

		g_CreditsData->sprites[i].unk08 = RANDOMFRAC() * -8000.0f;
	}
}

void creditsTickSprites(void)
{
	s32 i;
	f32 amount;
	f32 zspeed = 30.0f;

	if (g_CreditsData->unk41f5 >= 0) {
#if VERSION >= VERSION_PAL_BETA
		g_CreditsData->unk41f8 += g_Vars.diffframe240freal / 720.0f;
#else
		g_CreditsData->unk41f8 += g_Vars.diffframe240f / 720.0f;
#endif

		if (g_CreditsData->unk41f8 > 1.0f) {
			g_CreditsData->unk41f6 = g_CreditsData->unk41f5;
			g_CreditsData->unk41f5 = -1;
		}
	} else {
#if VERSION >= VERSION_NTSC_1_0
		if (RANDOMFRAC() < 0.007f && joyGetButtons(0, L_TRIG | R_TRIG) == 0) {
			g_CreditsData->unk41f5 = random() % 4;
			g_CreditsData->unk41f8 = 0;
		}
#else
		if (RANDOMFRAC() < 0.007f) {
			g_CreditsData->unk41f5 = random() % 4;
			g_CreditsData->unk41f8 = 0;
		}
#endif
	}

#if VERSION >= VERSION_NTSC_1_0
	if (RANDOMFRAC() < 0.002f && joyGetButtons(0, L_TRIG | R_TRIG) == 0) {
		g_CreditsData->unk41fc = random() % 5;
	}
#else
	if (RANDOMFRAC() < 0.002f) {
		g_CreditsData->unk41fc = random() % 5;
	}
#endif

#if VERSION >= VERSION_NTSC_1_0
	if (joyGetButtonsPressedThisFrame(0, R_TRIG)) {
		g_CreditsData->unk41fc = random() % 5;

		if (g_CreditsData->unk41f5 < 0) {
			g_CreditsData->unk41f5 = random() % 4;
			g_CreditsData->unk41f8 = 0;
		}
	}
#endif

	if (RANDOMFRAC() < 0.007f) {
		g_CreditsData->unk41fd = random() % 2;
		g_CreditsData->unk41fe = random() % 2;
	}

	for (i = 0; i < ARRAYCOUNT(g_CreditsData->sprites); i++) {
		amount = ((i & 7) + 1) * 0.01f;

		if ((i & 8) == 0) {
			amount = -amount;
		}

		g_CreditsData->sprites[i].rotation += amount;

#if VERSION >= VERSION_PAL_BETA
		amount = g_Vars.diffframe240freal * zspeed * 0.25f;
#else
		amount = g_Vars.diffframe240f * zspeed * 0.25f;
#endif
		g_CreditsData->sprites[i].unk08 += amount;

		if (g_CreditsData->sprites[i].unk08 > 0.0f) {
			g_CreditsData->sprites[i].unk00 = RANDOMFRAC() * 2.0f * 3000.0f - 3000.0f;
			g_CreditsData->sprites[i].unk04 = RANDOMFRAC() * 2.0f * 3000.0f - 3000.0f;
			g_CreditsData->sprites[i].unk12 = random() % 4;
			g_CreditsData->sprites[i].unk14 = random() % 4;
			g_CreditsData->sprites[i].rotation = RANDOMFRAC() * M_BADTAU;

			if (g_CreditsData->unk4200 < g_CreditsData->unk41ff) {
				g_CreditsData->sprites[i].unk13 = g_CreditsData->unk4200
					+ random() % (g_CreditsData->unk41ff - g_CreditsData->unk4200);
			} else {
				g_CreditsData->sprites[i].unk13 = g_CreditsData->unk4200;
			}

			g_CreditsData->sprites[i].unk10 = g_CreditsData->unk41fc;

			if (random() % 2 == 1) {
				g_CreditsData->sprites[i].confignum = g_CreditsData->unk41fd;
			} else {
				g_CreditsData->sprites[i].confignum = g_CreditsData->unk41fe;
			}

			g_CreditsData->sprites[i].unk08 += -8000;
		}

		if (zspeed);
	}
}

void creditsGetSpritePos(struct coord *pos, struct creditssprite *sprite, s32 spritenum)
{
	f32 sp4c;
	f32 sp48;
	f32 sp44;
	f32 sp40;
	f32 sp3c;
	f32 sp38;
	f32 sp34;
	f32 sp30;
	f32 sp2c;

	switch (sprite->unk10) {
	case 1:
		sp44 = var800a4160 * M_BADTAU;
		sp4c = sprite->unk00;
		sp48 = -400.0f + (sinf(sprite->unk00 / 300.0f) + cosf(sprite->unk08 / 300.0f)) * 100.0f;

		if ((spritenum & 1) == 1) {
			sp48 += 800.0f;
		}

		pos->z = sprite->unk08;
		pos->x = sinf(sp44) * sp4c + cosf(sp44) * sp48;
		pos->y = cosf(sp44) * sp4c - sinf(sp44) * sp48;
		break;
	case 2:
		pos->x = sprite->unk00 + (cosf(sprite->unk04 / 300.0f) + sinf(sprite->unk08 / 300.0f)) * 100.0f;
		pos->y = sprite->unk04 + (sinf(sprite->unk00 / 300.0f) + cosf(sprite->unk08 / 300.0f)) * 100.0f;
		pos->z = sprite->unk08;
		break;
	case 3:
		sp40 = sprite->unk00 / 5.0f;
		sp3c = sprite->unk04 / 5.0f;
		sp38 = sprite->unk08 / -8000.0f;
		sp38 = sp38 * sp38 * M_BADTAU;

		if (sp40 < 0.0f) {
			sp40 -= 420.0f;
		} else {
			sp40 += 420.0f;
		}

		if (sp3c < 0.0f) {
			sp3c -= 420.0f;
		} else {
			sp3c += 420.0f;
		}

		pos->x = sinf(sp38) * sp40 + cosf(sp38) * sp3c;
		pos->y = cosf(sp38) * sp40 - sinf(sp38) * sp3c;
		pos->z = sprite->unk08;
		break;
	case 4:
		sp34 = sprite->unk00 / 5.0f;
		sp30 = 400.0f;
		sp2c = sprite->unk08 / -8000.0f;

		if ((spritenum & 1) == 1) {
			sp30 = -sp30;
		}

		sp2c = sp2c * sp2c * M_BADTAU + var800a4160 * M_BADTAU;

		pos->x = sinf(sp2c) * sp34 + cosf(sp2c) * sp30;
		pos->y = cosf(sp2c) * sp34 - sinf(sp2c) * sp30;
		pos->z = sprite->unk08;
		break;
	case 99:
		pos->y = -(sprite->unk08 - -4000.0f);
		pos->x = sprite->unk00;
		pos->z = sprite->unk04;
		break;
	case 0:
	default:
		pos->x = sprite->unk00;
		pos->y = sprite->unk04;
		pos->z = sprite->unk08;
		break;
	}
}

Gfx *creditsDrawSprites(Gfx *gdl)
{
	u32 *colours;
	u32 colour;
	s32 i;
	s32 j;
	s32 confignum;
	f32 f0;
	f32 f2;

	static u32 tload = 0x25;
	static u32 dump = 0;

	mainOverrideVariable("tload", &tload);
	mainOverrideVariable("dump", &dump);

	colours = gfxAllocateColours(60);

	for (i = 0; i < 4; i++) {
		if (g_CreditsData->unk41f5 >= 0) {
			u32 weight = g_CreditsData->unk41f8 * 255.0f;
			colour = colourBlend(var8007f410[g_CreditsData->unk41f5][i], var8007f410[g_CreditsData->unk41f6][i], weight);
		} else {
			colour = var8007f410[g_CreditsData->unk41f6][i];
		}

		if (tload == 0x28) {
			colour = 0xffffffff;
		}

		for (j = 0; j < 15; j++) {
			colours[i + j * 4] = (colour & 0xffffff00) | ((colour & 0xff) * (15 - j) / 15);
		}
	}

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 60);

	for (confignum = 0; confignum < ARRAYCOUNT(g_CreditSpriteConfigs); confignum++) {
		bool donetexture = false;

		for (i = 0; i < ARRAYCOUNT(g_CreditsData->sprites); i++) {
			if (g_CreditsData->sprites[i].confignum == confignum) {
				s32 offset;
				u32 stack[3];
				struct coord pos;
				struct gfxvtx *vertices;
				f32 f26 = sinf(g_CreditsData->sprites[i].rotation);
				f32 f22 = cosf(g_CreditsData->sprites[i].rotation);
				f32 f20 = g_CreditsData->sprites[i].unk13 * 10.0f + 25.0f;
				f32 frac;

				if (!donetexture) {
					texSelect(&gdl, &g_TexGeneralConfigs[g_CreditSpriteConfigs[confignum].texturenum], 2, 1, 2, 1, 0);

					gDPSetCycleType(gdl++, G_CYC_1CYCLE);
					gDPSetColorDither(gdl++, G_CD_DISABLE);
					gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
					gDPSetAlphaCompare(gdl++, G_AC_NONE);
					gDPSetTextureLOD(gdl++, G_TL_TILE);
					gDPSetTextureConvert(gdl++, G_TC_FILT);
					gDPSetCombineLERP(gdl++,
							0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0,
							0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0);
					gDPSetTextureFilter(gdl++, G_TF_BILERP);
					gDPSetTexturePersp(gdl++, G_TP_PERSP);

					donetexture = true;
				}

				creditsGetSpritePos(&pos, &g_CreditsData->sprites[i], i);

				frac = 1.0f - (pos.f[2] - -4500.0f) / 3500.0f;

				if (frac < 0.0f) {
					frac = 0.0f;
				}

				if (frac > 1.0f) {
					frac = 1.0f;
				}

				f0 = -f26;
				f2 = -f22;

				vertices = gfxAllocateVertices(4);

				vertices[0].x = pos.f[0] + f20 * (f26 + f22);
				vertices[0].y = pos.f[1] + f20 * (f22 + -f26);
				vertices[0].z = pos.f[2];

				vertices[1].x = pos.f[0] + f20 * (f26 - f22);
				vertices[1].y = pos.f[1] + f20 * (f22 - f0);
				vertices[1].z = pos.f[2];

				vertices[2].x = pos.f[0] + f20 * (f0 - f22);
				vertices[2].y = pos.f[1] + f20 * (f2 - f0);
				vertices[2].z = pos.f[2];

				vertices[3].x = pos.f[0] + f20 * (f0 + f22);
				vertices[3].y = pos.f[1] + f20 * (f2 + f0);
				vertices[3].z = pos.f[2];

				vertices[0].unk08 = g_CreditSpriteConfigs[confignum].unk04 * 32;
				vertices[0].unk0a = g_CreditSpriteConfigs[confignum].unk06 * 32;
				vertices[1].unk08 = g_CreditSpriteConfigs[confignum].unk04 * 32;
				vertices[1].unk0a = g_CreditSpriteConfigs[confignum].unk0a * 32;
				vertices[2].unk08 = g_CreditSpriteConfigs[confignum].unk08 * 32;
				vertices[2].unk0a = g_CreditSpriteConfigs[confignum].unk0a * 32;
				vertices[3].unk08 = g_CreditSpriteConfigs[confignum].unk08 * 32;
				vertices[3].unk0a = g_CreditSpriteConfigs[confignum].unk06 * 32;

				if (1);
				offset = (g_CreditsData->sprites[i].unk14 + ((s32) (frac * 14.99f) * 4)) * 4;

				vertices[0].colour = offset;
				vertices[1].colour = offset;
				vertices[2].colour = offset;
				vertices[3].colour = offset;

				gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);

				gDPTri2(gdl++, 0, 1, 2, 2, 3, 0)
			}
		}
	}

	return gdl;
}

GLOBAL_ASM(
glabel func0f1399d0
.late_rodata
glabel var7f1b5854
.word 0x40c907a9
glabel var7f1b5858
.word 0x40c907a9
glabel var7f1b585c
.word 0x3e4ccccd
glabel var7f1b5860
.word 0x3dcccccd
glabel var7f1b5864
.word 0x408ccccd
glabel var7f1b5868
.word 0x3e99999a
.text
/*  f1399d0:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f1399d4:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f1399d8:	3c01437f */ 	lui	$at,0x437f
/*  f1399dc:	c7b400f0 */ 	lwc1	$f20,0xf0($sp)
/*  f1399e0:	44812000 */ 	mtc1	$at,$f4
/*  f1399e4:	afb00068 */ 	sw	$s0,0x68($sp)
/*  f1399e8:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f1399ec:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f1399f0:	afb40078 */ 	sw	$s4,0x78($sp)
/*  f1399f4:	0080a025 */ 	or	$s4,$a0,$zero
/*  f1399f8:	afbe0088 */ 	sw	$s8,0x88($sp)
/*  f1399fc:	00a0f025 */ 	or	$s8,$a1,$zero
/*  f139a00:	afb5007c */ 	sw	$s5,0x7c($sp)
/*  f139a04:	3c0400ff */ 	lui	$a0,0xff
/*  f139a08:	444ef800 */ 	cfc1	$t6,$31
/*  f139a0c:	44d0f800 */ 	ctc1	$s0,$31
/*  f139a10:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f139a14:	afbf008c */ 	sw	$ra,0x8c($sp)
/*  f139a18:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f139a1c:	afb70084 */ 	sw	$s7,0x84($sp)
/*  f139a20:	afb60080 */ 	sw	$s6,0x80($sp)
/*  f139a24:	afb30074 */ 	sw	$s3,0x74($sp)
/*  f139a28:	4450f800 */ 	cfc1	$s0,$31
/*  f139a2c:	afb20070 */ 	sw	$s2,0x70($sp)
/*  f139a30:	afb1006c */ 	sw	$s1,0x6c($sp)
/*  f139a34:	32100078 */ 	andi	$s0,$s0,0x78
/*  f139a38:	f7be0060 */ 	sdc1	$f30,0x60($sp)
/*  f139a3c:	f7bc0058 */ 	sdc1	$f28,0x58($sp)
/*  f139a40:	f7ba0050 */ 	sdc1	$f26,0x50($sp)
/*  f139a44:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f139a48:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f139a4c:	afa700dc */ 	sw	$a3,0xdc($sp)
/*  f139a50:	3484ff00 */ 	ori	$a0,$a0,0xff00
/*  f139a54:	12000013 */ 	beqz	$s0,.L0f139aa4
/*  f139a58:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f139a5c:	3c014f00 */ 	lui	$at,0x4f00
/*  f139a60:	44814000 */ 	mtc1	$at,$f8
/*  f139a64:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f139a68:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f139a6c:	44d0f800 */ 	ctc1	$s0,$31
/*  f139a70:	00000000 */ 	nop
/*  f139a74:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f139a78:	4450f800 */ 	cfc1	$s0,$31
/*  f139a7c:	00000000 */ 	nop
/*  f139a80:	32100078 */ 	andi	$s0,$s0,0x78
/*  f139a84:	16000005 */ 	bnez	$s0,.L0f139a9c
/*  f139a88:	00000000 */ 	nop
/*  f139a8c:	44104000 */ 	mfc1	$s0,$f8
/*  f139a90:	3c018000 */ 	lui	$at,0x8000
/*  f139a94:	10000007 */ 	b	.L0f139ab4
/*  f139a98:	02018025 */ 	or	$s0,$s0,$at
.L0f139a9c:
/*  f139a9c:	10000005 */ 	b	.L0f139ab4
/*  f139aa0:	2410ffff */ 	addiu	$s0,$zero,-1
.L0f139aa4:
/*  f139aa4:	44104000 */ 	mfc1	$s0,$f8
/*  f139aa8:	00000000 */ 	nop
/*  f139aac:	0600fffb */ 	bltz	$s0,.L0f139a9c
/*  f139ab0:	00000000 */ 	nop
.L0f139ab4:
/*  f139ab4:	44cef800 */ 	ctc1	$t6,$31
/*  f139ab8:	0fc01a40 */ 	jal	colourBlend
/*  f139abc:	02003025 */ 	or	$a2,$s0,$zero
/*  f139ac0:	0040b025 */ 	or	$s6,$v0,$zero
/*  f139ac4:	3404af00 */ 	dli	$a0,0xaf00
/*  f139ac8:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f139acc:	0fc01a40 */ 	jal	colourBlend
/*  f139ad0:	02003025 */ 	or	$a2,$s0,$zero
/*  f139ad4:	0040b825 */ 	or	$s7,$v0,$zero
/*  f139ad8:	24100004 */ 	addiu	$s0,$zero,0x4
/*  f139adc:	06a10003 */ 	bgez	$s5,.L0f139aec
/*  f139ae0:	00157843 */ 	sra	$t7,$s5,0x1
/*  f139ae4:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f139ae8:	00017843 */ 	sra	$t7,$at,0x1
.L0f139aec:
/*  f139aec:	24010064 */ 	addiu	$at,$zero,0x64
/*  f139af0:	01e1001a */ 	div	$zero,$t7,$at
/*  f139af4:	0000c010 */ 	mfhi	$t8
/*  f139af8:	44985000 */ 	mtc1	$t8,$f10
/*  f139afc:	3c017f1b */ 	lui	$at,%hi(var7f1b5854)
/*  f139b00:	c4325854 */ 	lwc1	$f18,%lo(var7f1b5854)($at)
/*  f139b04:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f139b08:	3c0142c8 */ 	lui	$at,0x42c8
/*  f139b0c:	44813000 */ 	mtc1	$at,$f6
/*  f139b10:	3c013f00 */ 	lui	$at,0x3f00
/*  f139b14:	44815000 */ 	mtc1	$at,$f10
/*  f139b18:	241200fc */ 	addiu	$s2,$zero,0xfc
/*  f139b1c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f139b20:	460aa400 */ 	add.s	$f16,$f20,$f10
/*  f139b24:	00009825 */ 	or	$s3,$zero,$zero
/*  f139b28:	e7b00090 */ 	swc1	$f16,0x90($sp)
/*  f139b2c:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f139b30:	e7a80098 */ 	swc1	$f8,0x98($sp)
.L0f139b34:
/*  f139b34:	3c01800a */ 	lui	$at,%hi(var800a4160)
/*  f139b38:	c4244160 */ 	lwc1	$f4,%lo(var800a4160)($at)
/*  f139b3c:	3c014120 */ 	lui	$at,0x4120
/*  f139b40:	44813000 */ 	mtc1	$at,$f6
/*  f139b44:	44909000 */ 	mtc1	$s0,$f18
/*  f139b48:	3c017f1b */ 	lui	$at,%hi(var7f1b5858)
/*  f139b4c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f139b50:	c42a5858 */ 	lwc1	$f10,%lo(var7f1b5858)($at)
/*  f139b54:	3c017f1b */ 	lui	$at,%hi(var7f1b585c)
/*  f139b58:	468095a0 */ 	cvt.s.w	$f22,$f18
/*  f139b5c:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f139b60:	c432585c */ 	lwc1	$f18,%lo(var7f1b585c)($at)
/*  f139b64:	3c017f1b */ 	lui	$at,%hi(var7f1b5860)
/*  f139b68:	c42a5860 */ 	lwc1	$f10,%lo(var7f1b5860)($at)
/*  f139b6c:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f139b70:	4612b102 */ 	mul.s	$f4,$f22,$f18
/*  f139b74:	3c013f80 */ 	lui	$at,0x3f80
/*  f139b78:	460ab482 */ 	mul.s	$f18,$f22,$f10
/*  f139b7c:	46102180 */ 	add.s	$f6,$f4,$f16
/*  f139b80:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f139b84:	46049402 */ 	mul.s	$f16,$f18,$f4
/*  f139b88:	46083600 */ 	add.s	$f24,$f6,$f8
/*  f139b8c:	44813000 */ 	mtc1	$at,$f6
/*  f139b90:	00000000 */ 	nop
/*  f139b94:	46068500 */ 	add.s	$f20,$f16,$f6
/*  f139b98:	0c004b70 */ 	jal	random
/*  f139b9c:	4600a686 */ 	mov.s	$f26,$f20
/*  f139ba0:	305900ff */ 	andi	$t9,$v0,0xff
/*  f139ba4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f139ba8:	17210006 */ 	bne	$t9,$at,.L0f139bc4
/*  f139bac:	02e02025 */ 	or	$a0,$s7,$zero
/*  f139bb0:	3c014120 */ 	lui	$at,0x4120
/*  f139bb4:	44814000 */ 	mtc1	$at,$f8
/*  f139bb8:	00000000 */ 	nop
/*  f139bbc:	4608a682 */ 	mul.s	$f26,$f20,$f8
/*  f139bc0:	00000000 */ 	nop
.L0f139bc4:
/*  f139bc4:	02c02825 */ 	or	$a1,$s6,$zero
/*  f139bc8:	0fc01a40 */ 	jal	colourBlend
/*  f139bcc:	02403025 */ 	or	$a2,$s2,$zero
/*  f139bd0:	44939000 */ 	mtc1	$s3,$f18
/*  f139bd4:	3c01427c */ 	lui	$at,0x427c
/*  f139bd8:	44815000 */ 	mtc1	$at,$f10
/*  f139bdc:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f139be0:	c7a600e8 */ 	lwc1	$f6,0xe8($sp)
/*  f139be4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f139be8:	3c014f00 */ 	lui	$at,0x4f00
/*  f139bec:	46045400 */ 	add.s	$f16,$f10,$f4
/*  f139bf0:	46068202 */ 	mul.s	$f8,$f16,$f6
/*  f139bf4:	4448f800 */ 	cfc1	$t0,$31
/*  f139bf8:	44c9f800 */ 	ctc1	$t1,$31
/*  f139bfc:	00000000 */ 	nop
/*  f139c00:	460044a4 */ 	cvt.w.s	$f18,$f8
/*  f139c04:	4449f800 */ 	cfc1	$t1,$31
/*  f139c08:	00000000 */ 	nop
/*  f139c0c:	31290078 */ 	andi	$t1,$t1,0x78
/*  f139c10:	51200013 */ 	beqzl	$t1,.L0f139c60
/*  f139c14:	44099000 */ 	mfc1	$t1,$f18
/*  f139c18:	44819000 */ 	mtc1	$at,$f18
/*  f139c1c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f139c20:	46124481 */ 	sub.s	$f18,$f8,$f18
/*  f139c24:	44c9f800 */ 	ctc1	$t1,$31
/*  f139c28:	00000000 */ 	nop
/*  f139c2c:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f139c30:	4449f800 */ 	cfc1	$t1,$31
/*  f139c34:	00000000 */ 	nop
/*  f139c38:	31290078 */ 	andi	$t1,$t1,0x78
/*  f139c3c:	15200005 */ 	bnez	$t1,.L0f139c54
/*  f139c40:	00000000 */ 	nop
/*  f139c44:	44099000 */ 	mfc1	$t1,$f18
/*  f139c48:	3c018000 */ 	lui	$at,0x8000
/*  f139c4c:	10000007 */ 	b	.L0f139c6c
/*  f139c50:	01214825 */ 	or	$t1,$t1,$at
.L0f139c54:
/*  f139c54:	10000005 */ 	b	.L0f139c6c
/*  f139c58:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f139c5c:	44099000 */ 	mfc1	$t1,$f18
.L0f139c60:
/*  f139c60:	00000000 */ 	nop
/*  f139c64:	0520fffb */ 	bltz	$t1,.L0f139c54
/*  f139c68:	00000000 */ 	nop
.L0f139c6c:
/*  f139c6c:	00498825 */ 	or	$s1,$v0,$t1
/*  f139c70:	44c8f800 */ 	ctc1	$t0,$31
/*  f139c74:	322a00ff */ 	andi	$t2,$s1,0xff
/*  f139c78:	51400032 */ 	beqzl	$t2,.L0f139d44
/*  f139c7c:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f139c80:	449e5000 */ 	mtc1	$s8,$f10
/*  f139c84:	44952000 */ 	mtc1	$s5,$f4
/*  f139c88:	4600c306 */ 	mov.s	$f12,$f24
/*  f139c8c:	46805720 */ 	cvt.s.w	$f28,$f10
/*  f139c90:	0c0068f7 */ 	jal	sinf
/*  f139c94:	468027a0 */ 	cvt.s.w	$f30,$f4
/*  f139c98:	46000506 */ 	mov.s	$f20,$f0
/*  f139c9c:	0c0068f4 */ 	jal	cosf
/*  f139ca0:	4600c306 */ 	mov.s	$f12,$f24
/*  f139ca4:	260b0001 */ 	addiu	$t3,$s0,0x1
/*  f139ca8:	448b8000 */ 	mtc1	$t3,$f16
/*  f139cac:	3c017f1b */ 	lui	$at,%hi(var7f1b5864)
/*  f139cb0:	c4285864 */ 	lwc1	$f8,%lo(var7f1b5864)($at)
/*  f139cb4:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f139cb8:	c7aa00ec */ 	lwc1	$f10,0xec($sp)
/*  f139cbc:	3c017f1b */ 	lui	$at,%hi(var7f1b5868)
/*  f139cc0:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f139cc4:	8fad00e0 */ 	lw	$t5,0xe0($sp)
/*  f139cc8:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*  f139ccc:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f139cd0:	4407d000 */ 	mfc1	$a3,$f26
/*  f139cd4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f139cd8:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f139cdc:	02802025 */ 	or	$a0,$s4,$zero
/*  f139ce0:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f139ce4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f139ce8:	460a9082 */ 	mul.s	$f2,$f18,$f10
/*  f139cec:	c4325868 */ 	lwc1	$f18,%lo(var7f1b5868)($at)
/*  f139cf0:	3c013f80 */ 	lui	$at,0x3f80
/*  f139cf4:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f139cf8:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f139cfc:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f139d00:	4602a102 */ 	mul.s	$f4,$f20,$f2
/*  f139d04:	00000000 */ 	nop
/*  f139d08:	46020182 */ 	mul.s	$f6,$f0,$f2
/*  f139d0c:	00000000 */ 	nop
/*  f139d10:	4612b282 */ 	mul.s	$f10,$f22,$f18
/*  f139d14:	461c2400 */ 	add.s	$f16,$f4,$f28
/*  f139d18:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f139d1c:	461e3200 */ 	add.s	$f8,$f6,$f30
/*  f139d20:	44058000 */ 	mfc1	$a1,$f16
/*  f139d24:	46045402 */ 	mul.s	$f16,$f10,$f4
/*  f139d28:	44813000 */ 	mtc1	$at,$f6
/*  f139d2c:	44064000 */ 	mfc1	$a2,$f8
/*  f139d30:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f139d34:	0fc554b5 */ 	jal	func0f1552d4
/*  f139d38:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f139d3c:	0040a025 */ 	or	$s4,$v0,$zero
/*  f139d40:	2610ffff */ 	addiu	$s0,$s0,-1
.L0f139d44:
/*  f139d44:	2652ffc1 */ 	addiu	$s2,$s2,-63
/*  f139d48:	0601ff7a */ 	bgez	$s0,.L0f139b34
/*  f139d4c:	26730010 */ 	addiu	$s3,$s3,0x10
/*  f139d50:	8fbf008c */ 	lw	$ra,0x8c($sp)
/*  f139d54:	02801025 */ 	or	$v0,$s4,$zero
/*  f139d58:	8fb40078 */ 	lw	$s4,0x78($sp)
/*  f139d5c:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f139d60:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f139d64:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f139d68:	d7ba0050 */ 	ldc1	$f26,0x50($sp)
/*  f139d6c:	d7bc0058 */ 	ldc1	$f28,0x58($sp)
/*  f139d70:	d7be0060 */ 	ldc1	$f30,0x60($sp)
/*  f139d74:	8fb00068 */ 	lw	$s0,0x68($sp)
/*  f139d78:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*  f139d7c:	8fb20070 */ 	lw	$s2,0x70($sp)
/*  f139d80:	8fb30074 */ 	lw	$s3,0x74($sp)
/*  f139d84:	8fb5007c */ 	lw	$s5,0x7c($sp)
/*  f139d88:	8fb60080 */ 	lw	$s6,0x80($sp)
/*  f139d8c:	8fb70084 */ 	lw	$s7,0x84($sp)
/*  f139d90:	8fbe0088 */ 	lw	$s8,0x88($sp)
/*  f139d94:	03e00008 */ 	jr	$ra
/*  f139d98:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);

Gfx *creditsDrawForegroundText(Gfx *gdl, s32 x, s32 y, char *text, struct fontchar *chars, struct font *font, f32 transfrac, s32 hdir, s32 vdir, s32 stretch)
{
	f32 sp3c;
	f32 sp38;
	f32 opacityfrac;
	u32 colour;

	opacityfrac = 2.0f - 2.0f * transfrac;

	switch (stretch) {
	case STRETCH_NONE:
		sp3c = 15.0f * transfrac + 1.0f;
		sp38 = 4.0f * transfrac + 1.0f;
		break;
	case STRETCH_VERTICALLY:
		sp3c = 2.0f * transfrac + 1.0f;
		sp38 = 75.0f * transfrac + 1.0f;
		break;
	case STRETCH_HORIZONTALLY:
		sp3c = 15.0f * transfrac + 1.0f;
		sp38 = 1.0f - (transfrac - 0.34f);

		if (sp38 > 1.0f) {
			sp38 = 1.0f;
		}
		break;
	case STRETCH_3:
		sp38 = 55.0f * transfrac + 1.0f;
		sp3c = 1.0f - (transfrac - 0.34f);

		if (sp3c > 1.0f) {
			sp3c = 1.0f;
		}
		break;
	}

	if (opacityfrac > 1.0f) {
		opacityfrac = 1.0f;
	}

	colour = 0xffffff00 | (u32) (255.0f * opacityfrac);

	gdl = func0f1552d4(gdl, x, y, sp3c, sp38, text, chars, font, colour, hdir, vdir);

	return gdl;
}

void creditsResetSlides(void)
{
	u8 pool[16];
	s32 i;

	// Shuffle the core team slides
	for (i = 0; i < 16; i++) {
		pool[i] = i + 1;
	}

	for (i = 0; i < 16; i++) {
		s32 index = random() % (16 - i);

		g_CreditsData->coreteammap[i + 1] = pool[index];

		while (index < (16 - i)) {
			pool[index] = pool[index + 1];
			index++;
		}
	}

	g_CreditsData->creditnum = 0;
	g_CreditsData->unk41a8[0] = 0xf0;
	g_CreditsData->numthisslide = 1;
	g_CreditsData->slideage = 0;
}

struct credit g_Credits[] = {
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_002,  L_TITLE_000 }, // "perfect dark", ""

	// The order of these items are randomised
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_003,  L_TITLE_004 }, // "beau ner chesluk", "guns and visual orgasms"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_005,  L_TITLE_006 }, // "jonathan nasty mummery", "mover and shaker"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_007,  L_TITLE_008 }, // "darkmark", "reality engineer"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_009,  L_TITLE_010 }, // "chris tilston", "designs on the future"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_011,  L_TITLE_012 }, // "chris darling", "weapons specialist"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_013,  L_TITLE_014 }, // "duncan botwood", "grey area"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_015,  L_TITLE_016 }, // "b jones", "bodybuilder"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_017,  L_TITLE_018 }, // "steve malpass", "perfect locations and vox"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_019,  L_TITLE_020 }, // "brian marshall", "-aqham-"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_021,  L_TITLE_022 }, // "russel irwin", "well packed man"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_023,  L_TITLE_024 }, // "jamie 'evo' williams", "manic welsh designer"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_025,  L_TITLE_026 }, // "ross bury", "bionic backgrounds"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_027,  L_TITLE_028 }, // "martin penny", "sound geezer"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_029,  L_TITLE_030 }, // "grant kirkhope", "play that music maestro"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_031,  L_TITLE_032 }, // "david clynick", "bangin hardcore choonz"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM, L_TITLE_033,  L_TITLE_034 }, // "keith 'bunny' rabbette", "dinomic backgrounds"

	//load next credit for same slide
	//|               duration: 0=4s, 1=8s, 2=12s, 3=16s
	//|               |
	{ 1, RETAIN_OUT,  0, CREDITSTYLE_HEADING1,    L_TITLE_035, L_TITLE_000 }, // "dd snipers", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_036, L_TITLE_037 }, // "kevin bayliss", "dean smith"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_038, L_TITLE_001 }, // "graham smith", "\n"

	{ 1, RETAIN_BOTH, 0, CREDITSTYLE_HEADING1,    L_TITLE_035, L_TITLE_000 }, // "dd snipers", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_039, L_TITLE_040 }, // "mike 'curry' currington", "tony wong"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_041, L_TITLE_001 }, // "simon farmer", "\n"

	{ 1, RETAIN_IN,   0, CREDITSTYLE_HEADING1,    L_TITLE_035, L_TITLE_000 }, // "dd snipers", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_042, L_TITLE_043 }, // "leigh loveday", "rob harrison"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_044, L_TITLE_001 }, // "steven hurst", "\n"

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING1,    L_TITLE_045, L_TITLE_000 }, // "fearsome foursome", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_046, L_TITLE_047 }, // "phil dunne", "ricky berwick"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_048, L_TITLE_049 }, // "gareth glover", "jonathan ambrose"

	{ 1, RETAIN_OUT,  0, CREDITSTYLE_HEADING1,    L_TITLE_050, L_TITLE_000 }, // "trent's henchmen", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_051, L_TITLE_052 }, // "lee musgrave", "johnni christensen"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_053, L_TITLE_001 }, // "mark betteridge", "\n"

	{ 1, RETAIN_IN,   0, CREDITSTYLE_HEADING1,    L_TITLE_050, L_TITLE_000 }, // "trent's henchmen", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_054, L_TITLE_055 }, // "chris marlow", "robin beanland"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_056, L_TITLE_057 }, // "neil gallagher", "feargal plant"

	{ 1, RETAIN_OUT,  0, CREDITSTYLE_HEADING1,    L_TITLE_058, L_TITLE_000 }, // "voices in the dark", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_059, L_TITLE_060 }, // "eveline fischer", "chris sutherland"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_061, L_TITLE_062 }, // "chris seavor", "john silke"

	{ 1, RETAIN_BOTH, 0, CREDITSTYLE_HEADING1,    L_TITLE_058, L_TITLE_000 }, // "voices in the dark", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_063, L_TITLE_064 }, // "ben cullum", "louise tilston"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_065, L_TITLE_066 }, // "alistair", "lindsay"

	{ 1, RETAIN_IN,   0, CREDITSTYLE_HEADING1,    L_TITLE_058, L_TITLE_000 }, // "voices in the dark", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_068, L_TITLE_067 }, // "beau chesluk", "b jones"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_069, L_TITLE_001 }, // "steve malpass", "\n"

	{ 1, RETAIN_OUT,  0, CREDITSTYLE_HEADING2,    L_TITLE_093, L_TITLE_000 }, // "rare exterminators", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_094, L_TITLE_095 }, // "huw ward", "adam munton"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_096, L_TITLE_097 }, // "david wong", "luke munton"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_098, L_TITLE_109 }, // "gary phelps", "andrew wilson"

	{ 1, RETAIN_BOTH, 0, CREDITSTYLE_HEADING2,    L_TITLE_093, L_TITLE_000 }, // "rare exterminators", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_099, L_TITLE_100 }, // "john silke", "matthew carter"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_101, L_TITLE_102 }, // "gavin price", "gareth stevenson"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_103, L_TITLE_001 }, // "bushbaby", "\n"

	{ 1, RETAIN_IN,   0, CREDITSTYLE_HEADING2,    L_TITLE_093, L_TITLE_000 }, // "rare exterminators", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_104, L_TITLE_105 }, // "stephen stamper", "ross bullimore"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_106, L_TITLE_107 }, // "justin cook", "dale murchie"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_108, L_TITLE_001 }, // "roger smith", "\n"

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_070, L_TITLE_000 }, // "ci techs", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_071, L_TITLE_072 }, // "richard 'force 9' gale", "mark green"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_073, L_TITLE_074 }, // "alex zoro", "mark wilson"

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_075, L_TITLE_000 }, // "hard and wary support", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_076, L_TITLE_077 }, // "pete 'hardrom' cox", "maul 'max' mikell"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_078, L_TITLE_000 }, // "doug crouch", ""

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_083, L_TITLE_000 }, // "motion capture", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_084, L_TITLE_085 }, // "alan tippertronic", "des easen"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_086, L_TITLE_000 }, // "jim 'love' ballard", ""

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_087, L_TITLE_000 }, // "going through the motions", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_088, L_TITLE_089 }, // "duncan 'bot' botwood", "michelle tipper"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_090, L_TITLE_091 }, // "sue 'falling' fell", "doug 'crouch' crouch"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_092, L_TITLE_000 }, // "ross bury", ""

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_118, L_TITLE_000 }, // "testing (rare miami)", ""
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_119, L_TITLE_000 }, // "keith coll", ""

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING1,    L_TITLE_113, L_TITLE_000 }, // "rare in the sun", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_114, L_TITLE_115 }, // "joel hochberg", ""
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_116, L_TITLE_117 }, // "scott hochberg", ""

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING1,    L_TITLE_110, L_TITLE_000 }, // "dark commanders", ""
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_111, L_TITLE_112 }, // "bis", "wombat"

	{ 1, RETAIN_OUT,  0, CREDITSTYLE_HEADING2,    L_TITLE_120, L_TITLE_000 }, // "testing (noa)", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_121, L_TITLE_122 }, // "michael kelbaugh", "tim bechtel"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_123, L_TITLE_124 }, // "tom hertzog", "melvin 'sherwood' forrest"

	{ 1, RETAIN_IN,   0, CREDITSTYLE_HEADING2,    L_TITLE_120, L_TITLE_000 }, // "testing (noa)", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_125, L_TITLE_126 }, // "dougall campbell", "roger harrison"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_127, L_TITLE_001 }, // "jeff kalles", "\n"

	{ 0, RETAIN_NONE, 0, CREDITSTYLE_CORETEAM,    L_TITLE_128, L_TITLE_129 }, // "the perfect core", "-darker than you"

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_130, L_TITLE_000 }, // "treehouse", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_131, L_TITLE_132 }, // "armond williams junior", "henry sterchi"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_133, L_TITLE_000 }, // "ed ridgeway", ""

#if VERSION == VERSION_JPN_FINAL
	{ 1, RETAIN_OUT,  0, CREDITSTYLE_HEADING1,    L_TITLE_184, L_TITLE_000 }, // "ncl staff", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_185, L_TITLE_186 }, // "s. miyamoto", "k. miki"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_187, L_TITLE_188 }, // "s. kojoh", "y. nakano"

	{ 1, RETAIN_IN,   0, CREDITSTYLE_HEADING1,    L_TITLE_184, L_TITLE_000 }, // "ncl staff", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_189, L_TITLE_190 }, // "k.yamaguchi", "k. terasaki"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_191, L_TITLE_192 }, // "m. goto", "super mario club"
#endif

#if VERSION == VERSION_PAL_FINAL
	{ 1, RETAIN_OUT,  0, CREDITSTYLE_HEADING2,    L_TITLE_151, L_TITLE_000 }, // "testing (noe)"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_SUPERVISOR,  L_TITLE_152, L_TITLE_153 }, // "supervisor", "kai 'jellybean' neumann"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_SUPERVISOR,  L_TITLE_154, L_TITLE_155 }, // "deputy supervisor", "maurice 'pathfinder' tisdale"

	{ 1, RETAIN_IN,   0, CREDITSTYLE_HEADING2,    L_TITLE_151, L_TITLE_000 }, // "testing (noe)"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_SUPERVISOR,  L_TITLE_156, L_TITLE_157 }, // "coordinators", "patrick 'capricorn' thieret"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_158, L_TITLE_001 }, // "andreas 'brennero' dietz", "\n"

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_162, L_TITLE_000 }, // "localization (french)"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_EDITOR,      L_TITLE_159, L_TITLE_163 }, // "editor", "julien 'sexy boy' bardakoff"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_ASSISTANT,   L_TITLE_161, L_TITLE_164 }, // "assistant editors", "jean-baptiste 'ours noir' fleury"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_ASSISTANT,   L_TITLE_165, L_TITLE_166 }, // "nicolas 'darth lapinou' gourio", "nicolas 'el betal' robert"

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_167, L_TITLE_000 }, // "localization (german)"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_EDITOR,      L_TITLE_159, L_TITLE_168 }, // "editor", "micky 'scorpio's movement' auer"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_ASSISTANT,   L_TITLE_160, L_TITLE_169 }, // "assistant editor", "jan 'ian' peitzmeier"

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_170, L_TITLE_000 }, // "localization (italian)"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_EDITOR,      L_TITLE_159, L_TITLE_171 }, // "editor", "elenor isbitish"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_ASSISTANT,   L_TITLE_160, L_TITLE_172 }, // "assistant editor", "calimero tiiiun"

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_173, L_TITLE_000 }, // "localization (spanish)"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_EDITOR,      L_TITLE_159, L_TITLE_174 }, // "editor", "antonio 'toro' greppi"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_ASSISTANT,   L_TITLE_161, L_TITLE_175 }, // "assistant editors", "carlos 'yoshio' montilla"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_ASSISTANT,   L_TITLE_176, L_TITLE_000 }, // "susa & natalia"

	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_177, L_TITLE_000 }, // "localization"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_EDITOR,      L_TITLE_178, L_TITLE_179 }, // "product coordinator", "andy 'fiedl' fey"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_EDITOR,      L_TITLE_180, L_TITLE_181 }, // "product supervisor", "tanja 'personalized sarcasm' baar"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_ASSISTANT,   L_TITLE_182, L_TITLE_183 }, // "product localization manager", "kai '0 to 100' zeh"
#endif

#if VERSION >= VERSION_NTSC_1_0
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_HEADING2,    L_TITLE_134, L_TITLE_000 }, // "perfect spelling", ""
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME2,       L_TITLE_135, L_TITLE_000 }, // "teresa lillygren", ""
#endif

	{ 1, RETAIN_OUT,  0, CREDITSTYLE_HEADING1,    L_TITLE_136, L_TITLE_000 }, // "nintendo", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_137, L_TITLE_138 }, // "mr arakawa", ""
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_139, L_TITLE_140 }, // "don james", ""

	{ 1, RETAIN_IN,   0, CREDITSTYLE_HEADING1,    L_TITLE_136, L_TITLE_000 }, // "nintendo", ""
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_141, L_TITLE_142 }, // "howard lincoln", "ken lobb"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_NAME1,       L_TITLE_143, L_TITLE_144 }, // "jacqualee story", "gail tilden"

	{ 1, RETAIN_NONE, 1, CREDITSTYLE_RAREDESIGNS, L_TITLE_148, L_TITLE_149 }, // "rare", "designs on the future"
	{ 1, RETAIN_NONE, 0, CREDITSTYLE_COPYRIGHT,   L_TITLE_001, L_TITLE_145 }, // "\n", "copyright rare 2000"
	{ 0, RETAIN_NONE, 0, CREDITSTYLE_COPYRIGHT,   L_TITLE_146, L_TITLE_147 }, // "perfect dark and the pd device", "are trademarks"

	{ 0, RETAIN_NONE, 0, CREDITSTYLE_COPYRIGHT,   L_TITLE_150, L_TITLE_000 }, // "perfect dark is forever", ""

	{ 0, RETAIN_NONE, 0, CREDITSTYLE_TERMINATOR,  L_TITLE_000, L_TITLE_000 }, // "", ""
};

/**
 * Get a credit to display, based on its row index on the current slide.
 *
 * Row 0 will usually be a title.
 * Row 1 will usually be the first two names and so on.
 *
 * The first slide, "perfect dark", is always first, then the next 16 are the
 * core team and are in a random order. The rest are in the same order as
 * defined in the g_Credits array.
 */
struct credit *creditGetByRow(s32 row)
{
	// If core team, use the mapping
	if (g_CreditsData->creditnum > 0 && g_CreditsData->creditnum < ARRAYCOUNT(g_CreditsData->coreteammap)) {
		if (row > 0) {
			return NULL;
		}

		return &g_Credits[g_CreditsData->coreteammap[g_CreditsData->creditnum]];
	}

	return &g_Credits[g_CreditsData->creditnum + row];
}

void creditsTickSlide(void)
{
	struct credit *credit = creditGetByRow(0);
	s32 i;
	f32 durations[] = {4, 8, 12, 16}; // in seconds
	f32 loadat = durations[credit->durationindex] + 2.0f + 0.142f * (g_CreditsData->numthisslide * 2 - 1);
	f32 seconds;

	g_CreditsData->slidelifetime = durations[credit->durationindex] + 1.0f;
#if VERSION >= VERSION_PAL_BETA
	seconds = g_Vars.diffframe240freal / 240.0f;
#else
	seconds = g_Vars.diffframe240f / 240.0f;
#endif
	g_CreditsData->slideage += seconds;

	if (g_CreditsData->slideage > loadat) {
		// Load new slide
		g_CreditsData->slideage = 0;
		g_CreditsData->creditnum += g_CreditsData->numthisslide;
		g_CreditsData->numthisslide = 1;

		do {
			credit = creditGetByRow(g_CreditsData->numthisslide - 1);

			if (credit->more) {
				g_CreditsData->numthisslide++;
			}

			if (credit && credit->style == CREDITSTYLE_TERMINATOR && g_CreditsData->numthisslide == 1) {
				// Reached the end of the slides list
				g_CreditsData->creditnum = 0;

				credit = NULL;

				g_CreditsData->numthisslide = 1;
				g_CreditsData->slideage = 0;
				g_CreditsData->slidesenabled = false;
				g_CreditsData->unk4204 = 0;
				g_CreditsData->unk4208 = 0;

				musicEndMenu();
				musicStartPrimary(0);
			}
		} while (credit && credit->more && g_CreditsData->numthisslide < 4);

		for (i = 0; i < 8; i++) {
			g_CreditsData->unk41a8[i] = random() % 3 | random() % 3 << 2 | random() % 16 << 4;
		}

		creditsCreatePendingBgLayers(0xffffffff);
	}
}

Gfx *creditsDrawSlide(Gfx *gdl)
{
	s32 i;
	struct credit *credits[4];
	char *texts[8];
	struct fontchar *chars[8];
	struct font *fonts[8];
	s32 extray;
	s32 x[8];
	s32 y[8];
	s32 textwidths[8];
	s32 textheights[8];
	s32 cury = 0;
	s32 prevstyle = -1;
	s32 index;
	s32 hdir;
	s32 vdir;
	s32 stretch;
	bool settled;
	f32 age;
	f32 mult = 1.0f;

	// Iterate the credits on this slide and populate the arrays
	for (i = 0; i < g_CreditsData->numthisslide; i++) {
		index = i * 2;
		credits[i] = creditGetByRow(i);

		if (credits[i] == NULL) {
			g_CreditsData->creditnum = 0;
			g_CreditsData->numthisslide = 1;
			g_CreditsData->slideage = 0.0f;
			return gdl;
		}

		texts[index + 0] = langGet(credits[i]->text1);
		texts[index + 1] = langGet(credits[i]->text2);

		// Choose first font
		switch (credits[i]->style) {
		case CREDITSTYLE_CORETEAM:
		case CREDITSTYLE_HEADING1:
		case CREDITSTYLE_NAME1:
		case CREDITSTYLE_HEADING2:
		case CREDITSTYLE_UNUSED_08:
		case CREDITSTYLE_RAREDESIGNS:
			chars[index + 0] = g_CharsHandelGothicLg;
			fonts[index + 0] = g_FontHandelGothicLg;
			break;
		case CREDITSTYLE_ASSISTANT:
		case CREDITSTYLE_UNUSED_06:
		case CREDITSTYLE_NAME2:
		case CREDITSTYLE_SUPERVISOR:
#if VERSION >= VERSION_PAL_FINAL
		case CREDITSTYLE_EDITOR:
#endif
			chars[index + 0] = g_CharsHandelGothicMd;
			fonts[index + 0] = g_FontHandelGothicMd;
			break;
		default:
			chars[index + 0] = g_CharsHandelGothicSm;
			fonts[index + 0] = g_FontHandelGothicSm;
			break;
		}

		// Choose second font
		switch (credits[i]->style) {
		case CREDITSTYLE_UNUSED_06:
			chars[index + 1] = g_CharsHandelGothicSm;
			fonts[index + 1] = g_FontHandelGothicSm;
			break;
		case CREDITSTYLE_CORETEAM:
		case CREDITSTYLE_RAREDESIGNS:
			chars[index + 1] = g_CharsHandelGothicMd;
			fonts[index + 1] = g_FontHandelGothicMd;
			break;
		default:
			chars[index + 1] = chars[index + 0];
			fonts[index + 1] = fonts[index + 0];
			break;
		}

		if (1);
		if (1);

		if (prevstyle == CREDITSTYLE_HEADING1 || prevstyle == CREDITSTYLE_COPYRIGHT || prevstyle == CREDITSTYLE_HEADING2) {
			cury += 10.0f;
		}

		prevstyle = credits[i]->style;

#if VERSION >= VERSION_JPN_FINAL
		textMeasure(&textheights[index + 0], &textwidths[index + 0], texts[index + 0], chars[index + 0], fonts[index + 0], -1);
		textMeasure(&textheights[index + 1], &textwidths[index + 1], texts[index + 1], chars[index + 1], fonts[index + 1], -1);
#else
		textMeasure(&textheights[index + 0], &textwidths[index + 0], texts[index + 0], chars[index + 0], fonts[index + 0], 0);
		textMeasure(&textheights[index + 1], &textwidths[index + 1], texts[index + 1], chars[index + 1], fonts[index + 1], 0);
#endif

		// Choose first position
		switch (credits[i]->style) {
		case CREDITSTYLE_CORETEAM:
		case CREDITSTYLE_HEADING1:
		case CREDITSTYLE_NAME1:
		case CREDITSTYLE_ASSISTANT:
		case CREDITSTYLE_COPYRIGHT:
		case CREDITSTYLE_UNUSED_06:
		case CREDITSTYLE_RAREDESIGNS:
#if VERSION >= VERSION_PAL_FINAL
		case CREDITSTYLE_EDITOR:
#endif
			x[index + 0] = 160 - textwidths[index + 0] / 2;
			break;
		case CREDITSTYLE_UNUSED_08:
		case CREDITSTYLE_NAME2:
			x[index + 0] = 270 - textwidths[index + 0];
			break;
		case CREDITSTYLE_SUPERVISOR:
		default:
			x[index + 0] = 50;
			break;
		}

		y[index + 0] = cury;
		cury += textheights[index + 0];

		// Choose second position
		switch (credits[i]->style) {
		case CREDITSTYLE_CORETEAM:
			x[index + 1] = x[index + 0] + textwidths[index + 0] - textwidths[index + 1];
			break;
		case CREDITSTYLE_HEADING1:
		case CREDITSTYLE_NAME1:
		case CREDITSTYLE_ASSISTANT:
		case CREDITSTYLE_COPYRIGHT:
		case CREDITSTYLE_UNUSED_06:
		case CREDITSTYLE_RAREDESIGNS:
#if VERSION >= VERSION_PAL_FINAL
		case CREDITSTYLE_EDITOR:
#endif
			x[index + 1] = 160 - textwidths[index + 1] / 2;
			break;
		case CREDITSTYLE_UNUSED_08:
		case CREDITSTYLE_NAME2:
		case CREDITSTYLE_SUPERVISOR:
			x[index + 1] = 270 - textwidths[index + 1];
			break;
		default:
			x[index + 1] = 50;
			break;
		}

		y[index + 1] = cury;
		cury += textheights[index + 1];

#if VERSION >= VERSION_PAL_FINAL
		if (credits[i]->style == CREDITSTYLE_EDITOR) {
			cury += 10;
		}
#endif
	}

	gdl = func0f153628(gdl);

	// Draw text repetitions
	for (i = 0; i < g_CreditsData->numthisslide * 2; i++) {
		f32 opacity = 0.0f;
		f32 speed = 1.0f;
		f32 spread = 1.0f;

		age = g_CreditsData->slideage - i * 0.142f;

		if ((age > 0.0f || (credits[i / 2]->retain & RETAIN_IN) == RETAIN_IN)
				&& (age < g_CreditsData->slidelifetime + 1.0f || (credits[i / 2]->retain & RETAIN_OUT) == RETAIN_OUT)) {
			bool settled = false;
			extray = 120 - cury / 2;

			if (age < 1.0f) {
				if ((credits[i / 2]->retain & RETAIN_IN) == RETAIN_IN) {
					settled = true;
				}
			} else {
				if (age > g_CreditsData->slidelifetime) {
					if ((credits[i / 2]->retain & RETAIN_OUT) == RETAIN_OUT) {
						settled = true;
					} else {
						opacity = 1.0f - (age - g_CreditsData->slidelifetime) * speed;
					}
				} else {
					if ((credits[i / 2]->retain & RETAIN_IN) == RETAIN_IN) {
						settled = true;
					} else {
						opacity = 1.0f;
						speed = (age - 1.0f) / (g_CreditsData->slidelifetime - 1.0f);
						spread = speed * 5.0f;
					}
				}
			}

			if (settled) {
				opacity = 1.0f;
				speed = 1.0f;
				spread = 1.0f;
			}

			if (opacity > 1.0f) {
				opacity = 1.0f;
			}

			if (spread > 1.0f) {
				spread = 1.0f;
			}

			if (speed > 1.0f) {
				speed = 1.0f;
			}

			gdl = func0f1399d0(gdl, x[i], y[i] + extray, texts[i], chars[i], fonts[i], opacity, speed, spread);
		}
	}

	// Draw text properly
	for (i = 0; i < g_CreditsData->numthisslide * 2; i++) {
#if VERSION >= VERSION_PAL_FINAL
		f32 transfrac = 0;
#else
		f32 transfrac = 0.0f;
#endif

		age = g_CreditsData->slideage - i * 0.142f;

		if (age > 0.0f || (credits[i / 2]->retain & RETAIN_IN) == RETAIN_IN) {
			if (age < g_CreditsData->slidelifetime + 1.0f || (credits[i / 2]->retain & RETAIN_OUT) == RETAIN_OUT) {
				u32 a2 = g_CreditsData->creditnum;
				settled = false;
				stretch = STRETCH_NONE;
				vdir = (g_CreditsData->unk41a8[i] >> 2) & 3;
				hdir = g_CreditsData->unk41a8[i] & 3;

				// b74
				if (((g_CreditsData->unk41a8[i] >> 4) & 1) == 1 && credits[i / 2]->style != CREDITSTYLE_NAME2) {
					stretch = STRETCH_VERTICALLY;

					// This is a fake match. The asm sets vdir to 1 (VDIR_MID)
					// unconditionally, but we need to load and discard
					// g_CreditsData->creditnum, which we do here by putting it
					// in a u32 then checking if it's >= 0, which always passes.
					vdir = a2 >= 0;
				}

				if (age < 1.0f) {
					if ((credits[i / 2]->retain & RETAIN_IN) != RETAIN_IN) {
						transfrac = (1.0f - age) * mult;
					} else {
						settled = true;
					}
				} else {
					if (age > g_CreditsData->slidelifetime) {
						bool distort = true;

						if ((credits[i / 2]->retain & RETAIN_OUT) != RETAIN_OUT) {
							transfrac = (age - g_CreditsData->slidelifetime) * mult;

							switch (credits[i / 2]->style) {
							case CREDITSTYLE_HEADING1:
							case CREDITSTYLE_HEADING2:
								distort = false;
								break;
							case CREDITSTYLE_CORETEAM:
								if ((i % 2) == 0) {
									distort = false;
								}
								break;
							}

							if (credits[i / 2]->retain == RETAIN_NONE && distort) {
								stretch = STRETCH_HORIZONTALLY;
								vdir = VDIR_MID;
							}
						} else {
							settled = true;
						}
					} else {
						settled = true;
					}
				}

				switch (credits[i / 2]->style) {
				case CREDITSTYLE_HEADING2:
					hdir = HDIR_RIGHT;
					break;
				case CREDITSTYLE_UNUSED_08:
				case CREDITSTYLE_NAME2:
				case CREDITSTYLE_SUPERVISOR:
					hdir = HDIR_LEFT;
					break;
				case CREDITSTYLE_HEADING1:
					hdir = HDIR_MID;
					break;
				}

				// Apply random flicker
				if (settled && random() % (g_CreditsData->numthisslide * 16) == 1) {
					transfrac = RANDOMFRAC() * 0.05f;
					hdir = random() % 3;
					vdir = random() % 3;
				}

				extray = 120 - cury / 2;
				gdl = creditsDrawForegroundText(gdl, x[i], y[i] + extray, texts[i], chars[i], fonts[i],
						transfrac, hdir, vdir, stretch);
			}
		}
	}

	gdl = func0f153780(gdl);

	return gdl;
}

void credits0f13ae04(Mtxf *mtx)
{
	// empty
}

void creditsTick(void)
{
	s32 i;
	static bool flick = false;
	static u32 var8007f6d8 = 0xffff;

#if VERSION >= VERSION_NTSC_1_0
	if (joyGetButtonsPressedThisFrame(0, L_TRIG)) {
		creditsCreatePendingBgLayers(0xffffffff);
	}
#endif

	mainOverrideVariable("for", &var8007f6d8);

	if (var8007f6d8 < 0xffff) {
		for (i = 0; i < 4; i++) {
			g_CreditsData->bglayers[i].type = var8007f6d8;
		}
	}

	mainOverrideVariable("flick", &flick);

	if (flick) {
		creditsCreatePendingBgLayers(0xffffffff);
		flick = false;
	}

	if (var800a416c == 0) {
		if (g_CreditsUsingAltTitle) {
			musicSetStage(STAGE_CREDITS);
			musicStartPrimary(0);
		} else {
			musicSetStage(STAGE_CREDITS);
			musicStartTrackAsMenu(MUSIC_CREDITS);
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	var800a4168 = var800a4164;
	var800a4164 += g_Vars.diffframe240;
	var800a416c += g_Vars.diffframe240;
	var800a4160 = (var800a416c % TICKS(4800)) / TICKS(4800.0f);

	creditsTickSprites();

	if (g_CreditsData->slidesenabled) {
		creditsTickSlide();
	} else if (RANDOMFRAC() < 0.01f && !joyGetButtons(0, L_TRIG | R_TRIG)) {
		creditsCreatePendingBgLayers(0xffffffff);
	}

	if (!g_CreditsData->slidesenabled && g_CreditsData->unk4204 < (PAL ? 1150 : 1360)) {
		g_CreditsData->unk4204 += g_Vars.diffframe60;
	}
#else
	if (joyGetButtons(0, R_TRIG) == 0) {
		var800a4168 = var800a4164;
		var800a4164 += g_Vars.diffframe240;
		var800a416c += g_Vars.diffframe240;
	}

	joyGetButtonsPressedThisFrame(0, Z_TRIG);

	var800a4160 = (var800a416c % TICKS(4800)) / TICKS(4800.0f);

	if (joyGetButtons(0, R_TRIG) == 0) {
		creditsTickSprites();

		if (g_CreditsData->slidesenabled) {
			creditsTickSlide();
		} else if (RANDOMFRAC() < 0.01f) {
			creditsCreatePendingBgLayers(0xffffffff);
		}

		if (!g_CreditsData->slidesenabled && g_CreditsData->unk4204 < (PAL ? 1150 : 1360)) {
			g_CreditsData->unk4204 += g_Vars.diffframe60;
		}
	}
#endif
}

Gfx *creditsDraw(Gfx *gdl)
{
	Mtxf sp68;
	Mtxf *matrix = gfxAllocateMatrix();
	struct coord sp58[1];
	struct coord sp4c[1];

	static u32 var8007f6dc = 0;

	func0f1531dc(false);

#if VERSION >= VERSION_JPN_FINAL
	var800800f0jf = 0;
#endif

	g_ScaleX = 1;

	gdl = vi0000b280(gdl);
	gdl = vi0000b1d0(gdl);
	gdl = creditsClearFramebuffer(gdl, 0x000000ff);

	gDPSetScissorFrac(gdl++, G_SC_NON_INTERLACE, 0, 120, viGetWidth() * 4.0f, (viGetHeight() - 30) * 4.0f);

	creditsTick();

	if (g_CreditsData->slidesenabled || g_CreditsData->unk4204 < TICKS(60) || g_CreditsData->unk4204 > TICKS(1200)) {
		u32 stack;

		if (!g_CreditsData->slidesenabled && g_CreditsData->unk4204 > TICKS(1200)) {
			if (!var8007f130) {
				var8007f130 = true;
				var8007f6dc = 0;

				func0f0f37a4(&g_CreditsData->unk2ef0);
			}

			var8007f6dc += g_Vars.diffframe240;

			if (var8007f6dc > TICKS(14400)) {
				var8007f6dc = 0;
			}

			g_CreditsData->unk2ef0.unk54c = 0;
			g_CreditsData->unk2ef0.unk524 = 0;
			g_CreditsData->unk2ef0.unk520 = g_CreditsData->unk2ef0.unk548 = -0.26175770163536;
			g_CreditsData->unk2ef0.unk528 = g_CreditsData->unk2ef0.unk550 = 0;
			g_CreditsData->unk2ef0.unk538 = 833.0f - (var8007f6dc / TICKS(14400.0f)) * 2413.0f;
			g_CreditsData->unk2ef0.unk53c = VERSION == VERSION_PAL_FINAL ? 65.86 : 70.86;
			g_CreditsData->unk2ef0.unk540 = -2050;
			g_CreditsData->unk2ef0.unk544 = 1.467;
			g_CreditsData->unk2ef0.unk00c = 1200;
			g_CreditsData->unk2ef0.unk5b1_07 = true;
			g_CreditsData->unk2ef0.partvisibility = NULL;

			gdl = menuRenderModels(gdl, &g_CreditsData->unk2ef0, 4);

			gSPMatrix(gdl++, osVirtualToPhysical(matrix), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

			gdl = creditsClearFramebuffer(gdl, 0x000000d8);
		}

		mtx4LoadIdentity(&sp68);
		mtx00016054(&sp68, matrix);
		camSetMatrix1740(&sp68);

		gSPMatrix(gdl++, osVirtualToPhysical(matrix), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

		sp58[0].x = -1000;
		sp58[0].y = -1000;
		sp58[0].z = -1000;

		sp4c[0].x = 0;
		sp4c[0].y = 0;
		sp4c[0].z = -100;

		gdl = creditsDrawBackground(gdl);
		gdl = creditsDrawSprites(gdl);

		if (g_CreditsData->slidesenabled) {
			gdl = creditsDrawSlide(func0f0d479c(gdl));
		}

		if (!g_CreditsData->slidesenabled) {
			u32 alpha = 0;

			if (g_CreditsData->unk4204 < TICKS(60)) {
				alpha = g_CreditsData->unk4204 * 0xff / TICKS(60);
			}

			if (g_CreditsData->unk4204 > TICKS(1200) && g_CreditsData->unk4204 < TICKS(1260)) {
				alpha = 0xff - (g_CreditsData->unk4204 - TICKS(1200)) * 0xff / TICKS(60);
			}

			if (alpha) {
				gdl = creditsClearFramebuffer(gdl, alpha);
			}
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	if (g_CreditsUsingAltTitle && joyGetButtonsPressedThisFrame(0, 0xffcf))
#else
	if (g_CreditsUsingAltTitle && joyGetButtons(0, 0xffff))
#endif
	{
		g_TitleNextStage = STAGE_CITRAINING;

		setNumPlayers(1);
		mainChangeToStage(g_TitleNextStage);

		g_Vars.bondplayernum = 0;
		g_Vars.coopplayernum = -1;
		g_Vars.antiplayernum = -1;

		lvSetDifficulty(DIFF_A);
		viBlack(true);
	}

	return gdl;
}

void creditsReset(void)
{
	var800a4164 = 0;
	var800a416c = 0;
	var8007f130 = false;

	g_CreditsData = mempAlloc(sizeof(struct creditsdata), MEMPOOL_STAGE);

	g_CreditsData->unk2eec = 0;
	g_CreditsData->unk41b0[0] = 0;
	g_CreditsData->unk41b0[1] = 0;

	creditsCreatePendingBgLayers(0xffffffff);

	// Move layers 2 and 3 to 0 and 1
	creditsCopyBackgroundLayer(2, 0, true);
	creditsCopyBackgroundLayer(3, 1, true);

	g_CreditsData->slidesenabled = true;

	creditsResetSprites();
	creditsResetSlides();
	func0f0f8bb4(&g_CreditsData->unk2ef0, 0x25800, 1);

	g_CreditsData->unk2ef0.unk580 = 0;

	func0f0f372c(&g_CreditsData->unk2ef0, 0, 0, 0, 0, 0, 0, 1, 5);

	g_CreditsData->unk2ef0.unk53c = 90;
	g_CreditsData->unk2ef0.unk510 = 8.2;
	g_CreditsData->unk2ef0.unk514 = -4.1;
	g_CreditsData->unk2ef0.unk51c = 0.00393;
	g_CreditsData->unk2ef0.unk54c = 0;
	g_CreditsData->unk2ef0.unk524 = g_CreditsData->unk2ef0.unk54c;
	g_CreditsData->unk2ef0.unk578 = 60;

	g_CreditsUsingAltTitle = g_CreditsAltTitleRequested;

	if (g_CreditsAltTitleRequested) {
		g_CreditsAltTitleRequested = false;

		g_CreditsData->slidesenabled = false;
		g_CreditsData->unk4204 = TICKS(1140);
	}

	playerConfigureVi();
}

void creditsRequestAltTitle(void)
{
	g_CreditsAltTitleRequested = true;
}
