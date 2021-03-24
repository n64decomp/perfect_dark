#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/title.h"
#include "game/game_0b3350.h"
#include "game/game_0b69d0.h"
#include "game/game_0d4690.h"
#include "game/game_0e0770.h"
#include "game/game_0f09f0.h"
#include "game/credits.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/gfxmemory.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/main.h"
#include "lib/memory.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

const char var7f1b57c0[] = "tload";
const char var7f1b57c8[] = "dump";

f32 var800a4160;
u32 var800a4164;
u32 var800a4168;
u32 var800a416c;
struct creditsdata *g_CreditsData;

u32 var8007f130 = 0x00000000;
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
#if VERSION >= VERSION_PAL_FINAL
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
		vertices[i].s = var8007f13c[arg2].s[i] * 4;
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

Gfx *creditsRenderBackgroundLayer(Gfx *gdl, u8 type, u8 layernum, f32 arg3, u32 alpha, s32 arg5)
{
	struct gfxvtx *vertices;
	u32 *colours;
	u32 stack;
	f32 a;
	f32 b;
	f32 c;
	f32 d;

	gdl = func0f0e2498(gdl);

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);

	func0f0b39c0(&gdl, &var800ab5a8[g_CreditsBgTypes[type].texturenum], 1, 1, 2, 1, 0);

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

Gfx *creditsRenderBackground(Gfx *gdl)
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
			gdl = creditsRenderBackgroundLayer(gdl, g_CreditsData->bglayers[s1[bestindex]].type,
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
u32 var8007f410 = 0x0000ffff;
u32 var8007f414 = 0x0044ffff;
u32 var8007f418 = 0x0088ffff;
u32 var8007f41c = 0x00ffffff;
u32 var8007f420 = 0x8888ff7f;
u32 var8007f424 = 0xff88ff7f;
u32 var8007f428 = 0xff88887f;
u32 var8007f42c = 0x6666ff7f;
u32 var8007f430 = 0xff00007f;
u32 var8007f434 = 0xffffff7f;
u32 var8007f438 = 0xff00004f;
u32 var8007f43c = 0xffffff4f;
u32 var8007f440 = 0xffffff7f;
u32 var8007f444 = 0xffffff5f;
u32 var8007f448 = 0xffffff3f;
u32 var8007f44c = 0xffffff1f;
u32 var8007f450 = 0x0000002a;
u32 var8007f454 = 0x00000000;
u32 var8007f458 = 0x00200020;
u32 var8007f45c = 0x0000002b;
u32 var8007f460 = 0x00000000;
u32 var8007f464 = 0x00200020;
u32 var8007f468 = 0x00000025;
u32 var8007f46c = 0x00000000;

struct credit g_Credits[] = {
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_002,   L_TITLE_000   }, // "perfect dark", ""

	// The order of these items are randomised
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_003,   L_TITLE_004   }, // "beau ner chesluk", "guns and visual orgasms"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_005,   L_TITLE_006   }, // "jonathan nasty mummery", "mover and shaker"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_007,   L_TITLE_008   }, // "darkmark", "reality engineer"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_009,   L_TITLE_010  }, // "chris tilston", "designs on the future"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_011,  L_TITLE_012  }, // "chris darling", "weapons specialist"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_013,  L_TITLE_014  }, // "duncan botwood", "grey area"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_015,  L_TITLE_016  }, // "b jones", "bodybuilder"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_017,  L_TITLE_018  }, // "steve malpass", "perfect locations and vox"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_019,  L_TITLE_020  }, // "brian marshall", "-aqham-"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_021,  L_TITLE_022  }, // "russel irwin", "well packed man"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_023,  L_TITLE_024  }, // "jamie 'evo' williams", "manic welsh designer"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_025,  L_TITLE_026  }, // "ross bury", "bionic backgrounds"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_027,  L_TITLE_028  }, // "martin penny", "sound geezer"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_029,  L_TITLE_030  }, // "grant kirkhope", "play that music maestro"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_031,  L_TITLE_032  }, // "david clynick", "bangin hardcore choonz"
	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_033,  L_TITLE_034  }, // "keith 'bunny' rabbette", "dinomic backgrounds"

	//load next credit for same slide
	//|  no transition in
	//|  |  no transition out
	//|  |  |  duration: 0=4s, 1=8s, 2=12s, 3=16s
	//|  |  |  |
	{ 1, 0, 1, 0, CREDITSTYLE_C_BIG,       L_TITLE_035,  L_TITLE_000   }, // "dd snipers", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_036,  L_TITLE_037  }, // "kevin bayliss", "dean smith"
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_038,  L_TITLE_001   }, // "graham smith", "\n"

	{ 1, 1, 1, 0, CREDITSTYLE_C_BIG,       L_TITLE_035,  L_TITLE_000   }, // "dd snipers", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_039,  L_TITLE_040  }, // "mike 'curry' currington", "tony wong"
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_041,  L_TITLE_001   }, // "simon farmer", "\n"

	{ 1, 1, 0, 0, CREDITSTYLE_C_BIG,       L_TITLE_035,  L_TITLE_000   }, // "dd snipers", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_042,  L_TITLE_043  }, // "leigh loveday", "rob harrison"
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_044,  L_TITLE_001   }, // "steven hurst", "\n"

	{ 1, 0, 0, 0, CREDITSTYLE_C_BIG,       L_TITLE_045,  L_TITLE_000   }, // "fearsome foursome", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_046,  L_TITLE_047  }, // "phil dunne", "ricky berwick"
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_048,  L_TITLE_049  }, // "gareth glover", "jonathan ambrose"

	{ 1, 0, 1, 0, CREDITSTYLE_C_BIG,       L_TITLE_050,  L_TITLE_000   }, // "trent's henchmen", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_051,  L_TITLE_052  }, // "lee musgrave", "johnni christensen"
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_053,  L_TITLE_001   }, // "mark betteridge", "\n"

	{ 1, 1, 0, 0, CREDITSTYLE_C_BIG,       L_TITLE_050,  L_TITLE_000   }, // "trent's henchmen", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_054,  L_TITLE_055  }, // "chris marlow", "robin beanland"
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_056,  L_TITLE_057  }, // "neil gallagher", "feargal plant"

	{ 1, 0, 1, 0, CREDITSTYLE_C_BIG,       L_TITLE_058,  L_TITLE_000   }, // "voices in the dark", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_059,  L_TITLE_060  }, // "eveline fischer", "chris sutherland"
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_061,  L_TITLE_062  }, // "chris seavor", "john silke"

	{ 1, 1, 1, 0, CREDITSTYLE_C_BIG,       L_TITLE_058,  L_TITLE_000   }, // "voices in the dark", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_063,  L_TITLE_064  }, // "ben cullum", "louise tilston"
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_065,  L_TITLE_066  }, // "alistair", "lindsay"

	{ 1, 1, 0, 0, CREDITSTYLE_C_BIG,       L_TITLE_058,  L_TITLE_000   }, // "voices in the dark", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_068,  L_TITLE_067  }, // "beau chesluk", "b jones"
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_069,  L_TITLE_001   }, // "steve malpass", "\n"

	{ 1, 0, 1, 0, CREDITSTYLE_L_BIG,       L_TITLE_093,  L_TITLE_000   }, // "rare exterminators", ""
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_094,  L_TITLE_095  }, // "huw ward", "adam munton"
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_096,  L_TITLE_097  }, // "david wong", "luke munton"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_098,  L_TITLE_109 }, // "gary phelps", "andrew wilson"

	{ 1, 1, 1, 0, CREDITSTYLE_L_BIG,       L_TITLE_093,  L_TITLE_000   }, // "rare exterminators", ""
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_099,  L_TITLE_100 }, // "john silke", "matthew carter"
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_101, L_TITLE_102 }, // "gavin price", "gareth stevenson"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_103, L_TITLE_001   }, // "bushbaby", "\n"

	{ 1, 1, 0, 0, CREDITSTYLE_L_BIG,       L_TITLE_093,  L_TITLE_000   }, // "rare exterminators", ""
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_104, L_TITLE_105 }, // "stephen stamper", "ross bullimore"
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_106, L_TITLE_107 }, // "justin cook", "dale murchie"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_108, L_TITLE_001   }, // "roger smith", "\n"

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG,       L_TITLE_070,  L_TITLE_000   }, // "ci techs", ""
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_071,  L_TITLE_072  }, // "richard 'force 9' gale", "mark green"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_073,  L_TITLE_074  }, // "alex zoro", "mark wilson"

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG,       L_TITLE_075,  L_TITLE_000   }, // "hard and wary support", ""
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_076,  L_TITLE_077  }, // "pete 'hardrom' cox", "maul 'max' mikell"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_078,  L_TITLE_000   }, // "doug crouch", ""

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG,       L_TITLE_083,  L_TITLE_000   }, // "motion capture", ""
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_084,  L_TITLE_085  }, // "alan tippertronic", "des easen"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_086,  L_TITLE_000   }, // "jim 'love' ballard", ""

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG,       L_TITLE_087,  L_TITLE_000   }, // "going through the motions", ""
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_088,  L_TITLE_089  }, // "duncan 'bot' botwood", "michelle tipper"
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_090,  L_TITLE_091  }, // "sue 'falling' fell", "doug 'crouch' crouch"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_092,  L_TITLE_000   }, // "ross bury", ""

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG,       L_TITLE_118, L_TITLE_000   }, // "testing (rare miami)", ""
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_119, L_TITLE_000   }, // "keith coll", ""

	{ 1, 0, 0, 0, CREDITSTYLE_C_BIG,       L_TITLE_113, L_TITLE_000   }, // "rare in the sun", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_114, L_TITLE_115 }, // "joel hochberg", ""
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_116, L_TITLE_117 }, // "scott hochberg", ""

	{ 1, 0, 0, 0, CREDITSTYLE_C_BIG,       L_TITLE_110, L_TITLE_000   }, // "dark commanders", ""
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_111, L_TITLE_112 }, // "bis", "wombat"

	{ 1, 0, 1, 0, CREDITSTYLE_L_BIG,       L_TITLE_120, L_TITLE_000   }, // "testing (noa)", ""
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_121, L_TITLE_122 }, // "michael kelbaugh", "tim bechtel"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_123, L_TITLE_124 }, // "tom hertzog", "melvin 'sherwood' forrest"

	{ 1, 1, 0, 0, CREDITSTYLE_L_BIG,       L_TITLE_120, L_TITLE_000   }, // "testing (noa)", ""
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_125, L_TITLE_126 }, // "dougall campbell", "roger harrison"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_127, L_TITLE_001   }, // "jeff kalles", "\n"

	{ 0, 0, 0, 0, CREDITSTYLE_R_BIG_R_MED, L_TITLE_128, L_TITLE_129 }, // "the perfect core", "-darker than you"

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG,       L_TITLE_130, L_TITLE_000   }, // "treehouse", ""
	{ 1, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_131, L_TITLE_132 }, // "armond williams junior", "henry sterchi"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_133, L_TITLE_000   }, // "ed ridgeway", ""

#if PAL
	{ 1, 0, 1, 0, CREDITSTYLE_L_BIG, L_TITLE_151, L_TITLE_000 }, // "testing (noe)"
	{ 1, 0, 0, 0, CREDITSTYLE_11,    L_TITLE_152, L_TITLE_153 }, // "supervisor", "kai 'jellybean' neumann"
	{ 0, 0, 0, 0, CREDITSTYLE_11,    L_TITLE_154, L_TITLE_155 }, // "deputy supervisor", "maurice 'pathfinder' tisdale"

	{ 1, 1, 0, 0, CREDITSTYLE_L_BIG, L_TITLE_151, L_TITLE_000 }, // "testing (noe)"
	{ 1, 0, 0, 0, CREDITSTYLE_11,    L_TITLE_156, L_TITLE_157 }, // "coordinators", "patrick 'capricorn' thieret"
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED, L_TITLE_158, L_TITLE_001 }, // "andreas 'brennero' dietz", "\n"

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG, L_TITLE_162, L_TITLE_000 }, // "localization (french)"
	{ 1, 0, 0, 0, CREDITSTYLE_12,    L_TITLE_159, L_TITLE_163 }, // "editor", "julien 'sexy boy' bardakoff"
	{ 1, 0, 0, 0, CREDITSTYLE_04,    L_TITLE_161, L_TITLE_164 }, // "assistant editors", "jean-baptiste 'ours noir' fleury"
	{ 0, 0, 0, 0, CREDITSTYLE_04,    L_TITLE_165, L_TITLE_166 }, // "nicolas 'darth lapinou' gourio", "nicolas 'el betal' robert"

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG, L_TITLE_167, L_TITLE_000 }, // "localization (german)"
	{ 1, 0, 0, 0, CREDITSTYLE_12,    L_TITLE_159, L_TITLE_168 }, // "editor", "micky 'scorpio's movement' auer"
	{ 0, 0, 0, 0, CREDITSTYLE_04,    L_TITLE_160, L_TITLE_169 }, // "assistant editor", "jan 'ian' peitzmeier"

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG, L_TITLE_170, L_TITLE_000 }, // "localization (italian)"
	{ 1, 0, 0, 0, CREDITSTYLE_12,    L_TITLE_159, L_TITLE_171 }, // "editor", "elenor isbitish"
	{ 0, 0, 0, 0, CREDITSTYLE_04,    L_TITLE_160, L_TITLE_172 }, // "assistant editor", "calimero tiiiun"

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG, L_TITLE_173, L_TITLE_000 }, // "localization (spanish)"
	{ 1, 0, 0, 0, CREDITSTYLE_12,    L_TITLE_159, L_TITLE_174 }, // "editor", "antonio 'toro' greppi"
	{ 1, 0, 0, 0, CREDITSTYLE_04,    L_TITLE_161, L_TITLE_175 }, // "assistant editors", "carlos 'yoshio' montilla"
	{ 0, 0, 0, 0, CREDITSTYLE_04,    L_TITLE_176, L_TITLE_000 }, // "susa & natalia"

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG, L_TITLE_177, L_TITLE_000 }, // "localization"
	{ 1, 0, 0, 0, CREDITSTYLE_12,    L_TITLE_178, L_TITLE_179 }, // "product coordinator", "andy 'fiedl' fey"
	{ 1, 0, 0, 0, CREDITSTYLE_12,    L_TITLE_180, L_TITLE_181 }, // "product supervisor", "tanja 'personalized sarcasm' baar"
	{ 1, 0, 0, 0, CREDITSTYLE_04,    L_TITLE_182, L_TITLE_183 }, // "product localization manager", "kai '0 to 100' zeh"
#endif

	{ 1, 0, 0, 0, CREDITSTYLE_L_BIG,       L_TITLE_134, L_TITLE_000   }, // "perfect spelling", ""
	{ 0, 0, 0, 0, CREDITSTYLE_R_MED,       L_TITLE_135, L_TITLE_000   }, // "teresa lillygren", ""

	{ 1, 0, 1, 0, CREDITSTYLE_C_BIG,       L_TITLE_136, L_TITLE_000   }, // "nintendo", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_137, L_TITLE_138 }, // "mr arakawa", ""
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_139, L_TITLE_140 }, // "don james", ""

	{ 1, 1, 0, 0, CREDITSTYLE_C_BIG,       L_TITLE_136, L_TITLE_000   }, // "nintendo", ""
	{ 1, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_141, L_TITLE_142 }, // "howard lincoln", "ken lobb"
	{ 0, 0, 0, 0, CREDITSTYLE_C_MED,       L_TITLE_143, L_TITLE_144 }, // "jacqualee story", "gail tilden"

	{ 1, 0, 0, 1, CREDITSTYLE_C_BIG_C_BIG, L_TITLE_148, L_TITLE_149 }, // "rare", "designs on the future"
	{ 1, 0, 0, 0, CREDITSTYLE_C_SML,       L_TITLE_001,   L_TITLE_145 }, // "\n", "copyright rare 2000"
	{ 0, 0, 0, 0, CREDITSTYLE_C_SML,       L_TITLE_146, L_TITLE_147 }, // "perfect dark and the pd device", "are trademarks"

	{ 0, 0, 0, 0, CREDITSTYLE_C_SML,       L_TITLE_150, L_TITLE_000   }, // "perfect dark is forever", ""

	{ 0, 0, 0, 0, CREDITSTYLE_TERMINATOR,  L_TITLE_000,   L_TITLE_000   }, // "", ""
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
		value = random() * (1.0f / U32_MAX) * range;
		value = (value + value) - range;
	} while (value < 0.0001f && value > -0.0001f);

	return value;
}

GLOBAL_ASM(
glabel creditsCreatePendingBgLayers
.late_rodata
glabel var7f1b5804
.word 0x3b122531
.text
/*  f13838c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f138390:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f138394:	afb70038 */ 	sw	$s7,0x38($sp)
/*  f138398:	afb60034 */ 	sw	$s6,0x34($sp)
/*  f13839c:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f1383a0:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f1383a4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1383a8:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f1383ac:	3c12800a */ 	lui	$s2,%hi(g_CreditsData)
/*  f1383b0:	3c017f1b */ 	lui	$at,%hi(var7f1b5804)
/*  f1383b4:	0080a025 */ 	or	$s4,$a0,$zero
/*  f1383b8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1383bc:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f1383c0:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f1383c4:	c4345804 */ 	lwc1	$f20,%lo(var7f1b5804)($at)
/*  f1383c8:	26524170 */ 	addiu	$s2,$s2,%lo(g_CreditsData)
/*  f1383cc:	00008025 */ 	or	$s0,$zero,$zero
/*  f1383d0:	2415000c */ 	addiu	$s5,$zero,0xc
/*  f1383d4:	24160006 */ 	addiu	$s6,$zero,0x6
/*  f1383d8:	24170002 */ 	addiu	$s7,$zero,0x2
/*  f1383dc:	8e4e0000 */ 	lw	$t6,0x0($s2)
.L0f1383e0:
/*  f1383e0:	001098c0 */ 	sll	$s3,$s0,0x3
/*  f1383e4:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f1383e8:	81f841b0 */ 	lb	$t8,0x41b0($t7)
/*  f1383ec:	57000023 */ 	bnezl	$t8,.L0f13847c
/*  f1383f0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1383f4:	0c004b70 */ 	jal	random
/*  f1383f8:	00108900 */ 	sll	$s1,$s0,0x4
/*  f1383fc:	0055001b */ 	divu	$zero,$v0,$s5
/*  f138400:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f138404:	0000c810 */ 	mfhi	$t9
/*  f138408:	4600a306 */ 	mov.s	$f12,$f20
/*  f13840c:	16a00002 */ 	bnez	$s5,.L0f138418
/*  f138410:	00000000 */ 	nop
/*  f138414:	0007000d */ 	break	0x7
.L0f138418:
/*  f138418:	01114821 */ 	addu	$t1,$t0,$s1
/*  f13841c:	0fc4e0b8 */ 	jal	func0f1382e0
/*  f138420:	ad3941d4 */ 	sw	$t9,0x41d4($t1)
/*  f138424:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*  f138428:	4600a306 */ 	mov.s	$f12,$f20
/*  f13842c:	01515821 */ 	addu	$t3,$t2,$s1
/*  f138430:	0fc4e0b8 */ 	jal	func0f1382e0
/*  f138434:	e56041d8 */ 	swc1	$f0,0x41d8($t3)
/*  f138438:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f13843c:	02747806 */ 	srlv	$t7,$s4,$s3
/*  f138440:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f138444:	01916821 */ 	addu	$t5,$t4,$s1
/*  f138448:	1300000b */ 	beqz	$t8,.L0f138478
/*  f13844c:	e5a041dc */ 	swc1	$f0,0x41dc($t5)
/*  f138450:	0c004b70 */ 	jal	random
/*  f138454:	00000000 */ 	nop
/*  f138458:	0056001b */ 	divu	$zero,$v0,$s6
/*  f13845c:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f138460:	00004010 */ 	mfhi	$t0
/*  f138464:	03314821 */ 	addu	$t1,$t9,$s1
/*  f138468:	ad2841e0 */ 	sw	$t0,0x41e0($t1)
/*  f13846c:	16c00002 */ 	bnez	$s6,.L0f138478
/*  f138470:	00000000 */ 	nop
/*  f138474:	0007000d */ 	break	0x7
.L0f138478:
/*  f138478:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f13847c:
/*  f13847c:	5617ffd8 */ 	bnel	$s0,$s7,.L0f1383e0
/*  f138480:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f138484:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f138488:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f13848c:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f138490:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f138494:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f138498:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f13849c:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f1384a0:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f1384a4:	8fb60034 */ 	lw	$s6,0x34($sp)
/*  f1384a8:	8fb70038 */ 	lw	$s7,0x38($sp)
/*  f1384ac:	03e00008 */ 	jr	$ra
/*  f1384b0:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

// Mismatch: regalloc
//void creditsCreatePendingBgLayers(u32 arg0)
//{
//	s32 i;
//
//	for (i = 0; i < 2; i++) {
//		s32 tmp = i * 8;
//
//		if (g_CreditsData->unk41b0[i] == 0) {
//			g_CreditsData->bglayers[i + 2].type = random() % 12;
//			g_CreditsData->bglayers[i + 2].rotatespeed = func0f1382e0(0.00223f);
//			g_CreditsData->bglayers[i + 2].unk08 = func0f1382e0(0.00223f);
//
//			if ((arg0 >> tmp) & 2) {
//				g_CreditsData->bglayers[i + 2].unk0c = random() % 6;
//			}
//		}
//	}
//}

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

	vertices[0].s = 0;
	vertices[1].s = 4;
	vertices[2].s = 4;
	vertices[3].s = 0;

	colours[0] = 0xffffffff;
	colours[1] = 0xffffffff;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);

	gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);

	return gdl;
}

void func0f13870c(void)
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

	for (i = 0; i < ARRAYCOUNT(g_CreditsData->unk000c); i++) {
		tmp = random() * (1.0f / U32_MAX);
		g_CreditsData->unk000c[i].unk00 = (tmp + tmp) * 3000.0f - 3000.0f;

		tmp = random() * (1.0f / U32_MAX);
		g_CreditsData->unk000c[i].unk04 = (tmp + tmp) * 3000.0f - 3000.0f;

		g_CreditsData->unk000c[i].unk12 = random() % 4;
		g_CreditsData->unk000c[i].unk14 = random() % 4;
		g_CreditsData->unk000c[i].unk0c = random() * (1.0f / U32_MAX) * M_BADTAU;

		if (g_CreditsData->unk4200 < g_CreditsData->unk41ff) {
			g_CreditsData->unk000c[i].unk13 = g_CreditsData->unk4200
				+ (random() % (g_CreditsData->unk41ff - g_CreditsData->unk4200));
		} else {
			g_CreditsData->unk000c[i].unk13 = g_CreditsData->unk4200;
		}

		g_CreditsData->unk000c[i].unk10 = g_CreditsData->unk41fc;

		if (random() % 2 == 1) {
			g_CreditsData->unk000c[i].unk11 = g_CreditsData->unk41fd;
		} else {
			g_CreditsData->unk000c[i].unk11 = g_CreditsData->unk41fe;
		}

		g_CreditsData->unk000c[i].unk08 = random() * (1.0f / U32_MAX) * -8000.0f;
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f13899c
.late_rodata
glabel var7f1b5810
.word 0x3be56042
glabel var7f1b5814
.word 0x3b03126f
glabel var7f1b5818
.word 0x3be56042
glabel var7f1b581c
.word 0x453b8000
glabel var7f1b5820
.word 0x3c23d70a
glabel var7f1b5824
.word 0x40c907a9
.text
/*  f13899c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f1389a0:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1389a4:	3c11800a */ 	lui	$s1,%hi(g_CreditsData)
/*  f1389a8:	26314170 */ 	addiu	$s1,$s1,%lo(g_CreditsData)
/*  f1389ac:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f1389b0:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f1389b4:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1389b8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1389bc:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f1389c0:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f1389c4:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f1389c8:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f1389cc:	806e41f5 */ 	lb	$t6,0x41f5($v1)
/*  f1389d0:	05c00019 */ 	bltz	$t6,.L0f138a38
/*  f1389d4:	3c01800a */ 	lui	$at,%hi(g_Vars+0x5c)
/*  f1389d8:	c424a008 */ 	lwc1	$f4,%lo(g_Vars+0x5c)($at)
/*  f1389dc:	3c014434 */ 	lui	$at,0x4434
/*  f1389e0:	44813000 */ 	mtc1	$at,$f6
/*  f1389e4:	c46a41f8 */ 	lwc1	$f10,0x41f8($v1)
/*  f1389e8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1389ec:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f1389f0:	44819000 */ 	mtc1	$at,$f18
/*  f1389f4:	3c012f80 */ 	lui	$at,0x2f80
/*  f1389f8:	4481d000 */ 	mtc1	$at,$f26
/*  f1389fc:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f138a00:	e47041f8 */ 	swc1	$f16,0x41f8($v1)
/*  f138a04:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138a08:	c46441f8 */ 	lwc1	$f4,0x41f8($v1)
/*  f138a0c:	4604903c */ 	c.lt.s	$f18,$f4
/*  f138a10:	00000000 */ 	nop
/*  f138a14:	45000006 */ 	bc1f	.L0f138a30
/*  f138a18:	00000000 */ 	nop
/*  f138a1c:	806f41f5 */ 	lb	$t7,0x41f5($v1)
/*  f138a20:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f138a24:	a06f41f6 */ 	sb	$t7,0x41f6($v1)
/*  f138a28:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f138a2c:	a33841f5 */ 	sb	$t8,0x41f5($t9)
.L0f138a30:
/*  f138a30:	10000020 */ 	b	.L0f138ab4
/*  f138a34:	00000000 */ 	nop
.L0f138a38:
/*  f138a38:	0c004b70 */ 	jal	random
/*  f138a3c:	00000000 */ 	nop
/*  f138a40:	44823000 */ 	mtc1	$v0,$f6
/*  f138a44:	3c012f80 */ 	lui	$at,0x2f80
/*  f138a48:	4481d000 */ 	mtc1	$at,$f26
/*  f138a4c:	04410005 */ 	bgez	$v0,.L0f138a64
/*  f138a50:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f138a54:	3c014f80 */ 	lui	$at,0x4f80
/*  f138a58:	44814000 */ 	mtc1	$at,$f8
/*  f138a5c:	00000000 */ 	nop
/*  f138a60:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f138a64:
/*  f138a64:	461a5402 */ 	mul.s	$f16,$f10,$f26
/*  f138a68:	3c017f1b */ 	lui	$at,%hi(var7f1b5810)
/*  f138a6c:	c4325810 */ 	lwc1	$f18,%lo(var7f1b5810)($at)
/*  f138a70:	00002025 */ 	or	$a0,$zero,$zero
/*  f138a74:	4612803c */ 	c.lt.s	$f16,$f18
/*  f138a78:	00000000 */ 	nop
/*  f138a7c:	4500000d */ 	bc1f	.L0f138ab4
/*  f138a80:	00000000 */ 	nop
/*  f138a84:	0c0053d8 */ 	jal	joyGetButtons
/*  f138a88:	24050030 */ 	addiu	$a1,$zero,0x30
/*  f138a8c:	14400009 */ 	bnez	$v0,.L0f138ab4
/*  f138a90:	00000000 */ 	nop
/*  f138a94:	0c004b70 */ 	jal	random
/*  f138a98:	00000000 */ 	nop
/*  f138a9c:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f138aa0:	30480003 */ 	andi	$t0,$v0,0x3
/*  f138aa4:	44802000 */ 	mtc1	$zero,$f4
/*  f138aa8:	a12841f5 */ 	sb	$t0,0x41f5($t1)
/*  f138aac:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f138ab0:	e54441f8 */ 	swc1	$f4,0x41f8($t2)
.L0f138ab4:
/*  f138ab4:	0c004b70 */ 	jal	random
/*  f138ab8:	00000000 */ 	nop
/*  f138abc:	44823000 */ 	mtc1	$v0,$f6
/*  f138ac0:	3c014f80 */ 	lui	$at,0x4f80
/*  f138ac4:	04410004 */ 	bgez	$v0,.L0f138ad8
/*  f138ac8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f138acc:	44815000 */ 	mtc1	$at,$f10
/*  f138ad0:	00000000 */ 	nop
/*  f138ad4:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f138ad8:
/*  f138ad8:	461a4402 */ 	mul.s	$f16,$f8,$f26
/*  f138adc:	3c017f1b */ 	lui	$at,%hi(var7f1b5814)
/*  f138ae0:	c4325814 */ 	lwc1	$f18,%lo(var7f1b5814)($at)
/*  f138ae4:	00002025 */ 	or	$a0,$zero,$zero
/*  f138ae8:	4612803c */ 	c.lt.s	$f16,$f18
/*  f138aec:	00000000 */ 	nop
/*  f138af0:	4502000e */ 	bc1fl	.L0f138b2c
/*  f138af4:	00002025 */ 	or	$a0,$zero,$zero
/*  f138af8:	0c0053d8 */ 	jal	joyGetButtons
/*  f138afc:	24050030 */ 	addiu	$a1,$zero,0x30
/*  f138b00:	5440000a */ 	bnezl	$v0,.L0f138b2c
/*  f138b04:	00002025 */ 	or	$a0,$zero,$zero
/*  f138b08:	0c004b70 */ 	jal	random
/*  f138b0c:	00000000 */ 	nop
/*  f138b10:	24010005 */ 	addiu	$at,$zero,0x5
/*  f138b14:	0041001b */ 	divu	$zero,$v0,$at
/*  f138b18:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f138b1c:	00005810 */ 	mfhi	$t3
/*  f138b20:	a18b41fc */ 	sb	$t3,0x41fc($t4)
/*  f138b24:	00000000 */ 	nop
/*  f138b28:	00002025 */ 	or	$a0,$zero,$zero
.L0f138b2c:
/*  f138b2c:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f138b30:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f138b34:	10400014 */ 	beqz	$v0,.L0f138b88
/*  f138b38:	00000000 */ 	nop
/*  f138b3c:	0c004b70 */ 	jal	random
/*  f138b40:	00000000 */ 	nop
/*  f138b44:	24010005 */ 	addiu	$at,$zero,0x5
/*  f138b48:	0041001b */ 	divu	$zero,$v0,$at
/*  f138b4c:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f138b50:	00006810 */ 	mfhi	$t5
/*  f138b54:	a1cd41fc */ 	sb	$t5,0x41fc($t6)
/*  f138b58:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f138b5c:	81f841f5 */ 	lb	$t8,0x41f5($t7)
/*  f138b60:	07010009 */ 	bgez	$t8,.L0f138b88
/*  f138b64:	00000000 */ 	nop
/*  f138b68:	0c004b70 */ 	jal	random
/*  f138b6c:	00000000 */ 	nop
/*  f138b70:	8e280000 */ 	lw	$t0,0x0($s1)
/*  f138b74:	30590003 */ 	andi	$t9,$v0,0x3
/*  f138b78:	44802000 */ 	mtc1	$zero,$f4
/*  f138b7c:	a11941f5 */ 	sb	$t9,0x41f5($t0)
/*  f138b80:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f138b84:	e52441f8 */ 	swc1	$f4,0x41f8($t1)
.L0f138b88:
/*  f138b88:	0c004b70 */ 	jal	random
/*  f138b8c:	00000000 */ 	nop
/*  f138b90:	44823000 */ 	mtc1	$v0,$f6
/*  f138b94:	3c014f80 */ 	lui	$at,0x4f80
/*  f138b98:	04410004 */ 	bgez	$v0,.L0f138bac
/*  f138b9c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f138ba0:	44814000 */ 	mtc1	$at,$f8
/*  f138ba4:	00000000 */ 	nop
/*  f138ba8:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f138bac:
/*  f138bac:	461a5402 */ 	mul.s	$f16,$f10,$f26
/*  f138bb0:	3c017f1b */ 	lui	$at,%hi(var7f1b5818)
/*  f138bb4:	c4325818 */ 	lwc1	$f18,%lo(var7f1b5818)($at)
/*  f138bb8:	4612803c */ 	c.lt.s	$f16,$f18
/*  f138bbc:	00000000 */ 	nop
/*  f138bc0:	4502000b */ 	bc1fl	.L0f138bf0
/*  f138bc4:	3c0141f0 */ 	lui	$at,0x41f0
/*  f138bc8:	0c004b70 */ 	jal	random
/*  f138bcc:	00000000 */ 	nop
/*  f138bd0:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f138bd4:	304a0001 */ 	andi	$t2,$v0,0x1
/*  f138bd8:	0c004b70 */ 	jal	random
/*  f138bdc:	a16a41fd */ 	sb	$t2,0x41fd($t3)
/*  f138be0:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f138be4:	304c0001 */ 	andi	$t4,$v0,0x1
/*  f138be8:	a1ac41fe */ 	sb	$t4,0x41fe($t5)
/*  f138bec:	3c0141f0 */ 	lui	$at,0x41f0
.L0f138bf0:
/*  f138bf0:	4481c000 */ 	mtc1	$at,$f24
/*  f138bf4:	3c017f1b */ 	lui	$at,%hi(var7f1b581c)
/*  f138bf8:	c436581c */ 	lwc1	$f22,%lo(var7f1b581c)($at)
/*  f138bfc:	00009025 */ 	or	$s2,$zero,$zero
/*  f138c00:	00008025 */ 	or	$s0,$zero,$zero
.L0f138c04:
/*  f138c04:	324e0007 */ 	andi	$t6,$s2,0x7
/*  f138c08:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f138c0c:	448f2000 */ 	mtc1	$t7,$f4
/*  f138c10:	3c017f1b */ 	lui	$at,%hi(var7f1b5820)
/*  f138c14:	c4285820 */ 	lwc1	$f8,%lo(var7f1b5820)($at)
/*  f138c18:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f138c1c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f138c20:	32590008 */ 	andi	$t9,$s2,0x8
/*  f138c24:	03101021 */ 	addu	$v0,$t8,$s0
/*  f138c28:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f138c2c:	17200002 */ 	bnez	$t9,.L0f138c38
/*  f138c30:	46001006 */ 	mov.s	$f0,$f2
/*  f138c34:	46001007 */ 	neg.s	$f0,$f2
.L0f138c38:
/*  f138c38:	c44a0018 */ 	lwc1	$f10,0x18($v0)
/*  f138c3c:	3c01800a */ 	lui	$at,%hi(g_Vars+0x5c)
/*  f138c40:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f138c44:	e4500018 */ 	swc1	$f16,0x18($v0)
/*  f138c48:	c432a008 */ 	lwc1	$f18,%lo(g_Vars+0x5c)($at)
/*  f138c4c:	3c013e80 */ 	lui	$at,0x3e80
/*  f138c50:	44813000 */ 	mtc1	$at,$f6
/*  f138c54:	46189102 */ 	mul.s	$f4,$f18,$f24
/*  f138c58:	8e280000 */ 	lw	$t0,0x0($s1)
/*  f138c5c:	44808000 */ 	mtc1	$zero,$f16
/*  f138c60:	01101021 */ 	addu	$v0,$t0,$s0
/*  f138c64:	c4480014 */ 	lwc1	$f8,0x14($v0)
/*  f138c68:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f138c6c:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f138c70:	e44a0014 */ 	swc1	$f10,0x14($v0)
/*  f138c74:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f138c78:	01305021 */ 	addu	$t2,$t1,$s0
/*  f138c7c:	c5520014 */ 	lwc1	$f18,0x14($t2)
/*  f138c80:	4612803c */ 	c.lt.s	$f16,$f18
/*  f138c84:	00000000 */ 	nop
/*  f138c88:	4502006b */ 	bc1fl	.L0f138e38
/*  f138c8c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f138c90:	0c004b70 */ 	jal	random
/*  f138c94:	00000000 */ 	nop
/*  f138c98:	44822000 */ 	mtc1	$v0,$f4
/*  f138c9c:	3c014f80 */ 	lui	$at,0x4f80
/*  f138ca0:	04410004 */ 	bgez	$v0,.L0f138cb4
/*  f138ca4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f138ca8:	44814000 */ 	mtc1	$at,$f8
/*  f138cac:	00000000 */ 	nop
/*  f138cb0:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f138cb4:
/*  f138cb4:	461a3502 */ 	mul.s	$f20,$f6,$f26
/*  f138cb8:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f138cbc:	01706021 */ 	addu	$t4,$t3,$s0
/*  f138cc0:	4614a280 */ 	add.s	$f10,$f20,$f20
/*  f138cc4:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f138cc8:	46168481 */ 	sub.s	$f18,$f16,$f22
/*  f138ccc:	0c004b70 */ 	jal	random
/*  f138cd0:	e592000c */ 	swc1	$f18,0xc($t4)
/*  f138cd4:	44822000 */ 	mtc1	$v0,$f4
/*  f138cd8:	3c014f80 */ 	lui	$at,0x4f80
/*  f138cdc:	04410004 */ 	bgez	$v0,.L0f138cf0
/*  f138ce0:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f138ce4:	44813000 */ 	mtc1	$at,$f6
/*  f138ce8:	00000000 */ 	nop
/*  f138cec:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f138cf0:
/*  f138cf0:	461a4502 */ 	mul.s	$f20,$f8,$f26
/*  f138cf4:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f138cf8:	01b07021 */ 	addu	$t6,$t5,$s0
/*  f138cfc:	4614a280 */ 	add.s	$f10,$f20,$f20
/*  f138d00:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f138d04:	46168481 */ 	sub.s	$f18,$f16,$f22
/*  f138d08:	0c004b70 */ 	jal	random
/*  f138d0c:	e5d20010 */ 	swc1	$f18,0x10($t6)
/*  f138d10:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f138d14:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f138d18:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f138d1c:	0c004b70 */ 	jal	random
/*  f138d20:	a32f001e */ 	sb	$t7,0x1e($t9)
/*  f138d24:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f138d28:	30480003 */ 	andi	$t0,$v0,0x3
/*  f138d2c:	01305021 */ 	addu	$t2,$t1,$s0
/*  f138d30:	0c004b70 */ 	jal	random
/*  f138d34:	a1480020 */ 	sb	$t0,0x20($t2)
/*  f138d38:	44822000 */ 	mtc1	$v0,$f4
/*  f138d3c:	3c014f80 */ 	lui	$at,0x4f80
/*  f138d40:	04410004 */ 	bgez	$v0,.L0f138d54
/*  f138d44:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f138d48:	44814000 */ 	mtc1	$at,$f8
/*  f138d4c:	00000000 */ 	nop
/*  f138d50:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f138d54:
/*  f138d54:	461a3282 */ 	mul.s	$f10,$f6,$f26
/*  f138d58:	3c017f1b */ 	lui	$at,%hi(var7f1b5824)
/*  f138d5c:	c4305824 */ 	lwc1	$f16,%lo(var7f1b5824)($at)
/*  f138d60:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f138d64:	01706021 */ 	addu	$t4,$t3,$s0
/*  f138d68:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f138d6c:	e5920018 */ 	swc1	$f18,0x18($t4)
/*  f138d70:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138d74:	90644200 */ 	lbu	$a0,0x4200($v1)
/*  f138d78:	906d41ff */ 	lbu	$t5,0x41ff($v1)
/*  f138d7c:	00704021 */ 	addu	$t0,$v1,$s0
/*  f138d80:	008d082a */ 	slt	$at,$a0,$t5
/*  f138d84:	50200012 */ 	beqzl	$at,.L0f138dd0
/*  f138d88:	a104001f */ 	sb	$a0,0x1f($t0)
/*  f138d8c:	0c004b70 */ 	jal	random
/*  f138d90:	00000000 */ 	nop
/*  f138d94:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138d98:	90644200 */ 	lbu	$a0,0x4200($v1)
/*  f138d9c:	906e41ff */ 	lbu	$t6,0x41ff($v1)
/*  f138da0:	00704821 */ 	addu	$t1,$v1,$s0
/*  f138da4:	01c4c023 */ 	subu	$t8,$t6,$a0
/*  f138da8:	0058001b */ 	divu	$zero,$v0,$t8
/*  f138dac:	00007810 */ 	mfhi	$t7
/*  f138db0:	01e4c821 */ 	addu	$t9,$t7,$a0
/*  f138db4:	17000002 */ 	bnez	$t8,.L0f138dc0
/*  f138db8:	00000000 */ 	nop
/*  f138dbc:	0007000d */ 	break	0x7
.L0f138dc0:
/*  f138dc0:	a139001f */ 	sb	$t9,0x1f($t1)
/*  f138dc4:	10000003 */ 	b	.L0f138dd4
/*  f138dc8:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138dcc:	a104001f */ 	sb	$a0,0x1f($t0)
.L0f138dd0:
/*  f138dd0:	8e230000 */ 	lw	$v1,0x0($s1)
.L0f138dd4:
/*  f138dd4:	906a41fc */ 	lbu	$t2,0x41fc($v1)
/*  f138dd8:	00705821 */ 	addu	$t3,$v1,$s0
/*  f138ddc:	0c004b70 */ 	jal	random
/*  f138de0:	a16a001c */ 	sb	$t2,0x1c($t3)
/*  f138de4:	304c0001 */ 	andi	$t4,$v0,0x1
/*  f138de8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f138dec:	55810007 */ 	bnel	$t4,$at,.L0f138e0c
/*  f138df0:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138df4:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138df8:	906d41fd */ 	lbu	$t5,0x41fd($v1)
/*  f138dfc:	00707021 */ 	addu	$t6,$v1,$s0
/*  f138e00:	10000005 */ 	b	.L0f138e18
/*  f138e04:	a1cd001d */ 	sb	$t5,0x1d($t6)
/*  f138e08:	8e230000 */ 	lw	$v1,0x0($s1)
.L0f138e0c:
/*  f138e0c:	907841fe */ 	lbu	$t8,0x41fe($v1)
/*  f138e10:	00707821 */ 	addu	$t7,$v1,$s0
/*  f138e14:	a1f8001d */ 	sb	$t8,0x1d($t7)
.L0f138e18:
/*  f138e18:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f138e1c:	3c01c5fa */ 	lui	$at,0xc5fa
/*  f138e20:	44814000 */ 	mtc1	$at,$f8
/*  f138e24:	03301021 */ 	addu	$v0,$t9,$s0
/*  f138e28:	c4440014 */ 	lwc1	$f4,0x14($v0)
/*  f138e2c:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f138e30:	e4460014 */ 	swc1	$f6,0x14($v0)
/*  f138e34:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f138e38:
/*  f138e38:	240101f4 */ 	addiu	$at,$zero,0x1f4
/*  f138e3c:	1641ff71 */ 	bne	$s2,$at,.L0f138c04
/*  f138e40:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f138e44:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f138e48:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f138e4c:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f138e50:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f138e54:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f138e58:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f138e5c:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f138e60:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f138e64:	03e00008 */ 	jr	$ra
/*  f138e68:	27bd0048 */ 	addiu	$sp,$sp,0x48
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f13899c
.late_rodata
glabel var7f1b5810
.word 0x3be56042
glabel var7f1b5814
.word 0x3b03126f
glabel var7f1b5818
.word 0x3be56042
glabel var7f1b581c
.word 0x453b8000
glabel var7f1b5820
.word 0x3c23d70a
glabel var7f1b5824
.word 0x40c907a9
.text
/*  f13899c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f1389a0:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1389a4:	3c11800a */ 	lui	$s1,%hi(g_CreditsData)
/*  f1389a8:	26314170 */ 	addiu	$s1,$s1,%lo(g_CreditsData)
/*  f1389ac:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f1389b0:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f1389b4:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1389b8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1389bc:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f1389c0:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f1389c4:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f1389c8:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f1389cc:	806e41f5 */ 	lb	$t6,0x41f5($v1)
/*  f1389d0:	05c00019 */ 	bltz	$t6,.L0f138a38
/*  f1389d4:	3c01800a */ 	lui	$at,%hi(g_Vars+0x48)
/*  f1389d8:	c424a008 */ 	lwc1	$f4,%lo(g_Vars+0x48)($at)
/*  f1389dc:	3c014434 */ 	lui	$at,0x4434
/*  f1389e0:	44813000 */ 	mtc1	$at,$f6
/*  f1389e4:	c46a41f8 */ 	lwc1	$f10,0x41f8($v1)
/*  f1389e8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1389ec:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f1389f0:	44819000 */ 	mtc1	$at,$f18
/*  f1389f4:	3c012f80 */ 	lui	$at,0x2f80
/*  f1389f8:	4481d000 */ 	mtc1	$at,$f26
/*  f1389fc:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f138a00:	e47041f8 */ 	swc1	$f16,0x41f8($v1)
/*  f138a04:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138a08:	c46441f8 */ 	lwc1	$f4,0x41f8($v1)
/*  f138a0c:	4604903c */ 	c.lt.s	$f18,$f4
/*  f138a10:	00000000 */ 	nop
/*  f138a14:	45000006 */ 	bc1f	.L0f138a30
/*  f138a18:	00000000 */ 	nop
/*  f138a1c:	806f41f5 */ 	lb	$t7,0x41f5($v1)
/*  f138a20:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f138a24:	a06f41f6 */ 	sb	$t7,0x41f6($v1)
/*  f138a28:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f138a2c:	a33841f5 */ 	sb	$t8,0x41f5($t9)
.L0f138a30:
/*  f138a30:	10000020 */ 	b	.L0f138ab4
/*  f138a34:	00000000 */ 	nop
.L0f138a38:
/*  f138a38:	0c004b70 */ 	jal	random
/*  f138a3c:	00000000 */ 	nop
/*  f138a40:	44823000 */ 	mtc1	$v0,$f6
/*  f138a44:	3c012f80 */ 	lui	$at,0x2f80
/*  f138a48:	4481d000 */ 	mtc1	$at,$f26
/*  f138a4c:	04410005 */ 	bgez	$v0,.L0f138a64
/*  f138a50:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f138a54:	3c014f80 */ 	lui	$at,0x4f80
/*  f138a58:	44814000 */ 	mtc1	$at,$f8
/*  f138a5c:	00000000 */ 	nop
/*  f138a60:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f138a64:
/*  f138a64:	461a5402 */ 	mul.s	$f16,$f10,$f26
/*  f138a68:	3c017f1b */ 	lui	$at,%hi(var7f1b5810)
/*  f138a6c:	c4325810 */ 	lwc1	$f18,%lo(var7f1b5810)($at)
/*  f138a70:	00002025 */ 	or	$a0,$zero,$zero
/*  f138a74:	4612803c */ 	c.lt.s	$f16,$f18
/*  f138a78:	00000000 */ 	nop
/*  f138a7c:	4500000d */ 	bc1f	.L0f138ab4
/*  f138a80:	00000000 */ 	nop
/*  f138a84:	0c0053d8 */ 	jal	joyGetButtons
/*  f138a88:	24050030 */ 	addiu	$a1,$zero,0x30
/*  f138a8c:	14400009 */ 	bnez	$v0,.L0f138ab4
/*  f138a90:	00000000 */ 	nop
/*  f138a94:	0c004b70 */ 	jal	random
/*  f138a98:	00000000 */ 	nop
/*  f138a9c:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f138aa0:	30480003 */ 	andi	$t0,$v0,0x3
/*  f138aa4:	44802000 */ 	mtc1	$zero,$f4
/*  f138aa8:	a12841f5 */ 	sb	$t0,0x41f5($t1)
/*  f138aac:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f138ab0:	e54441f8 */ 	swc1	$f4,0x41f8($t2)
.L0f138ab4:
/*  f138ab4:	0c004b70 */ 	jal	random
/*  f138ab8:	00000000 */ 	nop
/*  f138abc:	44823000 */ 	mtc1	$v0,$f6
/*  f138ac0:	3c014f80 */ 	lui	$at,0x4f80
/*  f138ac4:	04410004 */ 	bgez	$v0,.L0f138ad8
/*  f138ac8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f138acc:	44815000 */ 	mtc1	$at,$f10
/*  f138ad0:	00000000 */ 	nop
/*  f138ad4:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f138ad8:
/*  f138ad8:	461a4402 */ 	mul.s	$f16,$f8,$f26
/*  f138adc:	3c017f1b */ 	lui	$at,%hi(var7f1b5814)
/*  f138ae0:	c4325814 */ 	lwc1	$f18,%lo(var7f1b5814)($at)
/*  f138ae4:	00002025 */ 	or	$a0,$zero,$zero
/*  f138ae8:	4612803c */ 	c.lt.s	$f16,$f18
/*  f138aec:	00000000 */ 	nop
/*  f138af0:	4502000e */ 	bc1fl	.L0f138b2c
/*  f138af4:	00002025 */ 	or	$a0,$zero,$zero
/*  f138af8:	0c0053d8 */ 	jal	joyGetButtons
/*  f138afc:	24050030 */ 	addiu	$a1,$zero,0x30
/*  f138b00:	5440000a */ 	bnezl	$v0,.L0f138b2c
/*  f138b04:	00002025 */ 	or	$a0,$zero,$zero
/*  f138b08:	0c004b70 */ 	jal	random
/*  f138b0c:	00000000 */ 	nop
/*  f138b10:	24010005 */ 	addiu	$at,$zero,0x5
/*  f138b14:	0041001b */ 	divu	$zero,$v0,$at
/*  f138b18:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f138b1c:	00005810 */ 	mfhi	$t3
/*  f138b20:	a18b41fc */ 	sb	$t3,0x41fc($t4)
/*  f138b24:	00000000 */ 	nop
/*  f138b28:	00002025 */ 	or	$a0,$zero,$zero
.L0f138b2c:
/*  f138b2c:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f138b30:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f138b34:	10400014 */ 	beqz	$v0,.L0f138b88
/*  f138b38:	00000000 */ 	nop
/*  f138b3c:	0c004b70 */ 	jal	random
/*  f138b40:	00000000 */ 	nop
/*  f138b44:	24010005 */ 	addiu	$at,$zero,0x5
/*  f138b48:	0041001b */ 	divu	$zero,$v0,$at
/*  f138b4c:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f138b50:	00006810 */ 	mfhi	$t5
/*  f138b54:	a1cd41fc */ 	sb	$t5,0x41fc($t6)
/*  f138b58:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f138b5c:	81f841f5 */ 	lb	$t8,0x41f5($t7)
/*  f138b60:	07010009 */ 	bgez	$t8,.L0f138b88
/*  f138b64:	00000000 */ 	nop
/*  f138b68:	0c004b70 */ 	jal	random
/*  f138b6c:	00000000 */ 	nop
/*  f138b70:	8e280000 */ 	lw	$t0,0x0($s1)
/*  f138b74:	30590003 */ 	andi	$t9,$v0,0x3
/*  f138b78:	44802000 */ 	mtc1	$zero,$f4
/*  f138b7c:	a11941f5 */ 	sb	$t9,0x41f5($t0)
/*  f138b80:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f138b84:	e52441f8 */ 	swc1	$f4,0x41f8($t1)
.L0f138b88:
/*  f138b88:	0c004b70 */ 	jal	random
/*  f138b8c:	00000000 */ 	nop
/*  f138b90:	44823000 */ 	mtc1	$v0,$f6
/*  f138b94:	3c014f80 */ 	lui	$at,0x4f80
/*  f138b98:	04410004 */ 	bgez	$v0,.L0f138bac
/*  f138b9c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f138ba0:	44814000 */ 	mtc1	$at,$f8
/*  f138ba4:	00000000 */ 	nop
/*  f138ba8:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f138bac:
/*  f138bac:	461a5402 */ 	mul.s	$f16,$f10,$f26
/*  f138bb0:	3c017f1b */ 	lui	$at,%hi(var7f1b5818)
/*  f138bb4:	c4325818 */ 	lwc1	$f18,%lo(var7f1b5818)($at)
/*  f138bb8:	4612803c */ 	c.lt.s	$f16,$f18
/*  f138bbc:	00000000 */ 	nop
/*  f138bc0:	4502000b */ 	bc1fl	.L0f138bf0
/*  f138bc4:	3c0141f0 */ 	lui	$at,0x41f0
/*  f138bc8:	0c004b70 */ 	jal	random
/*  f138bcc:	00000000 */ 	nop
/*  f138bd0:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f138bd4:	304a0001 */ 	andi	$t2,$v0,0x1
/*  f138bd8:	0c004b70 */ 	jal	random
/*  f138bdc:	a16a41fd */ 	sb	$t2,0x41fd($t3)
/*  f138be0:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f138be4:	304c0001 */ 	andi	$t4,$v0,0x1
/*  f138be8:	a1ac41fe */ 	sb	$t4,0x41fe($t5)
/*  f138bec:	3c0141f0 */ 	lui	$at,0x41f0
.L0f138bf0:
/*  f138bf0:	4481c000 */ 	mtc1	$at,$f24
/*  f138bf4:	3c017f1b */ 	lui	$at,%hi(var7f1b581c)
/*  f138bf8:	c436581c */ 	lwc1	$f22,%lo(var7f1b581c)($at)
/*  f138bfc:	00009025 */ 	or	$s2,$zero,$zero
/*  f138c00:	00008025 */ 	or	$s0,$zero,$zero
.L0f138c04:
/*  f138c04:	324e0007 */ 	andi	$t6,$s2,0x7
/*  f138c08:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f138c0c:	448f2000 */ 	mtc1	$t7,$f4
/*  f138c10:	3c017f1b */ 	lui	$at,%hi(var7f1b5820)
/*  f138c14:	c4285820 */ 	lwc1	$f8,%lo(var7f1b5820)($at)
/*  f138c18:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f138c1c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f138c20:	32590008 */ 	andi	$t9,$s2,0x8
/*  f138c24:	03101021 */ 	addu	$v0,$t8,$s0
/*  f138c28:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f138c2c:	17200002 */ 	bnez	$t9,.L0f138c38
/*  f138c30:	46001006 */ 	mov.s	$f0,$f2
/*  f138c34:	46001007 */ 	neg.s	$f0,$f2
.L0f138c38:
/*  f138c38:	c44a0018 */ 	lwc1	$f10,0x18($v0)
/*  f138c3c:	3c01800a */ 	lui	$at,%hi(g_Vars+0x48)
/*  f138c40:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f138c44:	e4500018 */ 	swc1	$f16,0x18($v0)
/*  f138c48:	c432a008 */ 	lwc1	$f18,%lo(g_Vars+0x48)($at)
/*  f138c4c:	3c013e80 */ 	lui	$at,0x3e80
/*  f138c50:	44813000 */ 	mtc1	$at,$f6
/*  f138c54:	46189102 */ 	mul.s	$f4,$f18,$f24
/*  f138c58:	8e280000 */ 	lw	$t0,0x0($s1)
/*  f138c5c:	44808000 */ 	mtc1	$zero,$f16
/*  f138c60:	01101021 */ 	addu	$v0,$t0,$s0
/*  f138c64:	c4480014 */ 	lwc1	$f8,0x14($v0)
/*  f138c68:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f138c6c:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f138c70:	e44a0014 */ 	swc1	$f10,0x14($v0)
/*  f138c74:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f138c78:	01305021 */ 	addu	$t2,$t1,$s0
/*  f138c7c:	c5520014 */ 	lwc1	$f18,0x14($t2)
/*  f138c80:	4612803c */ 	c.lt.s	$f16,$f18
/*  f138c84:	00000000 */ 	nop
/*  f138c88:	4502006b */ 	bc1fl	.L0f138e38
/*  f138c8c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f138c90:	0c004b70 */ 	jal	random
/*  f138c94:	00000000 */ 	nop
/*  f138c98:	44822000 */ 	mtc1	$v0,$f4
/*  f138c9c:	3c014f80 */ 	lui	$at,0x4f80
/*  f138ca0:	04410004 */ 	bgez	$v0,.L0f138cb4
/*  f138ca4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f138ca8:	44814000 */ 	mtc1	$at,$f8
/*  f138cac:	00000000 */ 	nop
/*  f138cb0:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f138cb4:
/*  f138cb4:	461a3502 */ 	mul.s	$f20,$f6,$f26
/*  f138cb8:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f138cbc:	01706021 */ 	addu	$t4,$t3,$s0
/*  f138cc0:	4614a280 */ 	add.s	$f10,$f20,$f20
/*  f138cc4:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f138cc8:	46168481 */ 	sub.s	$f18,$f16,$f22
/*  f138ccc:	0c004b70 */ 	jal	random
/*  f138cd0:	e592000c */ 	swc1	$f18,0xc($t4)
/*  f138cd4:	44822000 */ 	mtc1	$v0,$f4
/*  f138cd8:	3c014f80 */ 	lui	$at,0x4f80
/*  f138cdc:	04410004 */ 	bgez	$v0,.L0f138cf0
/*  f138ce0:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f138ce4:	44813000 */ 	mtc1	$at,$f6
/*  f138ce8:	00000000 */ 	nop
/*  f138cec:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f138cf0:
/*  f138cf0:	461a4502 */ 	mul.s	$f20,$f8,$f26
/*  f138cf4:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f138cf8:	01b07021 */ 	addu	$t6,$t5,$s0
/*  f138cfc:	4614a280 */ 	add.s	$f10,$f20,$f20
/*  f138d00:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f138d04:	46168481 */ 	sub.s	$f18,$f16,$f22
/*  f138d08:	0c004b70 */ 	jal	random
/*  f138d0c:	e5d20010 */ 	swc1	$f18,0x10($t6)
/*  f138d10:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f138d14:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f138d18:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f138d1c:	0c004b70 */ 	jal	random
/*  f138d20:	a32f001e */ 	sb	$t7,0x1e($t9)
/*  f138d24:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f138d28:	30480003 */ 	andi	$t0,$v0,0x3
/*  f138d2c:	01305021 */ 	addu	$t2,$t1,$s0
/*  f138d30:	0c004b70 */ 	jal	random
/*  f138d34:	a1480020 */ 	sb	$t0,0x20($t2)
/*  f138d38:	44822000 */ 	mtc1	$v0,$f4
/*  f138d3c:	3c014f80 */ 	lui	$at,0x4f80
/*  f138d40:	04410004 */ 	bgez	$v0,.L0f138d54
/*  f138d44:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f138d48:	44814000 */ 	mtc1	$at,$f8
/*  f138d4c:	00000000 */ 	nop
/*  f138d50:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f138d54:
/*  f138d54:	461a3282 */ 	mul.s	$f10,$f6,$f26
/*  f138d58:	3c017f1b */ 	lui	$at,%hi(var7f1b5824)
/*  f138d5c:	c4305824 */ 	lwc1	$f16,%lo(var7f1b5824)($at)
/*  f138d60:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f138d64:	01706021 */ 	addu	$t4,$t3,$s0
/*  f138d68:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f138d6c:	e5920018 */ 	swc1	$f18,0x18($t4)
/*  f138d70:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138d74:	90644200 */ 	lbu	$a0,0x4200($v1)
/*  f138d78:	906d41ff */ 	lbu	$t5,0x41ff($v1)
/*  f138d7c:	00704021 */ 	addu	$t0,$v1,$s0
/*  f138d80:	008d082a */ 	slt	$at,$a0,$t5
/*  f138d84:	50200012 */ 	beqzl	$at,.L0f138dd0
/*  f138d88:	a104001f */ 	sb	$a0,0x1f($t0)
/*  f138d8c:	0c004b70 */ 	jal	random
/*  f138d90:	00000000 */ 	nop
/*  f138d94:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138d98:	90644200 */ 	lbu	$a0,0x4200($v1)
/*  f138d9c:	906e41ff */ 	lbu	$t6,0x41ff($v1)
/*  f138da0:	00704821 */ 	addu	$t1,$v1,$s0
/*  f138da4:	01c4c023 */ 	subu	$t8,$t6,$a0
/*  f138da8:	0058001b */ 	divu	$zero,$v0,$t8
/*  f138dac:	00007810 */ 	mfhi	$t7
/*  f138db0:	01e4c821 */ 	addu	$t9,$t7,$a0
/*  f138db4:	17000002 */ 	bnez	$t8,.L0f138dc0
/*  f138db8:	00000000 */ 	nop
/*  f138dbc:	0007000d */ 	break	0x7
.L0f138dc0:
/*  f138dc0:	a139001f */ 	sb	$t9,0x1f($t1)
/*  f138dc4:	10000003 */ 	b	.L0f138dd4
/*  f138dc8:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138dcc:	a104001f */ 	sb	$a0,0x1f($t0)
.L0f138dd0:
/*  f138dd0:	8e230000 */ 	lw	$v1,0x0($s1)
.L0f138dd4:
/*  f138dd4:	906a41fc */ 	lbu	$t2,0x41fc($v1)
/*  f138dd8:	00705821 */ 	addu	$t3,$v1,$s0
/*  f138ddc:	0c004b70 */ 	jal	random
/*  f138de0:	a16a001c */ 	sb	$t2,0x1c($t3)
/*  f138de4:	304c0001 */ 	andi	$t4,$v0,0x1
/*  f138de8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f138dec:	55810007 */ 	bnel	$t4,$at,.L0f138e0c
/*  f138df0:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138df4:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f138df8:	906d41fd */ 	lbu	$t5,0x41fd($v1)
/*  f138dfc:	00707021 */ 	addu	$t6,$v1,$s0
/*  f138e00:	10000005 */ 	b	.L0f138e18
/*  f138e04:	a1cd001d */ 	sb	$t5,0x1d($t6)
/*  f138e08:	8e230000 */ 	lw	$v1,0x0($s1)
.L0f138e0c:
/*  f138e0c:	907841fe */ 	lbu	$t8,0x41fe($v1)
/*  f138e10:	00707821 */ 	addu	$t7,$v1,$s0
/*  f138e14:	a1f8001d */ 	sb	$t8,0x1d($t7)
.L0f138e18:
/*  f138e18:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f138e1c:	3c01c5fa */ 	lui	$at,0xc5fa
/*  f138e20:	44814000 */ 	mtc1	$at,$f8
/*  f138e24:	03301021 */ 	addu	$v0,$t9,$s0
/*  f138e28:	c4440014 */ 	lwc1	$f4,0x14($v0)
/*  f138e2c:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f138e30:	e4460014 */ 	swc1	$f6,0x14($v0)
/*  f138e34:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f138e38:
/*  f138e38:	240101f4 */ 	addiu	$at,$zero,0x1f4
/*  f138e3c:	1641ff71 */ 	bne	$s2,$at,.L0f138c04
/*  f138e40:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f138e44:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f138e48:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f138e4c:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f138e50:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f138e54:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f138e58:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f138e5c:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f138e60:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f138e64:	03e00008 */ 	jr	$ra
/*  f138e68:	27bd0048 */ 	addiu	$sp,$sp,0x48
);
#else
GLOBAL_ASM(
glabel func0f13899c
.late_rodata
glabel var7f1b5810
.word 0x3be56042
glabel var7f1b5814
.word 0x3b03126f
glabel var7f1b5818
.word 0x3be56042
glabel var7f1b581c
.word 0x453b8000
glabel var7f1b5820
.word 0x3c23d70a
glabel var7f1b5824
.word 0x40c907a9
.text
/*  f13352c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f133530:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f133534:	3c11800b */ 	lui	$s1,0x800b
/*  f133538:	26318730 */ 	addiu	$s1,$s1,-30928
/*  f13353c:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f133540:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f133544:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f133548:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f13354c:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f133550:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f133554:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f133558:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f13355c:	806e41f5 */ 	lb	$t6,0x41f5($v1)
/*  f133560:	05c00019 */ 	bltz	$t6,.NB0f1335c8
/*  f133564:	3c01800a */ 	lui	$at,0x800a
/*  f133568:	c424e708 */ 	lwc1	$f4,-0x18f8($at)
/*  f13356c:	3c014434 */ 	lui	$at,0x4434
/*  f133570:	44813000 */ 	mtc1	$at,$f6
/*  f133574:	c46a41f8 */ 	lwc1	$f10,0x41f8($v1)
/*  f133578:	3c013f80 */ 	lui	$at,0x3f80
/*  f13357c:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f133580:	44819000 */ 	mtc1	$at,$f18
/*  f133584:	3c012f80 */ 	lui	$at,0x2f80
/*  f133588:	4481c000 */ 	mtc1	$at,$f24
/*  f13358c:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f133590:	e47041f8 */ 	swc1	$f16,0x41f8($v1)
/*  f133594:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f133598:	c46441f8 */ 	lwc1	$f4,0x41f8($v1)
/*  f13359c:	4604903c */ 	c.lt.s	$f18,$f4
/*  f1335a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1335a4:	45000006 */ 	bc1f	.NB0f1335c0
/*  f1335a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1335ac:	806f41f5 */ 	lb	$t7,0x41f5($v1)
/*  f1335b0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f1335b4:	a06f41f6 */ 	sb	$t7,0x41f6($v1)
/*  f1335b8:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f1335bc:	a33841f5 */ 	sb	$t8,0x41f5($t9)
.NB0f1335c0:
/*  f1335c0:	1000001b */ 	beqz	$zero,.NB0f133630
/*  f1335c4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1335c8:
/*  f1335c8:	0c004d84 */ 	jal	random
/*  f1335cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1335d0:	44823000 */ 	mtc1	$v0,$f6
/*  f1335d4:	3c012f80 */ 	lui	$at,0x2f80
/*  f1335d8:	4481c000 */ 	mtc1	$at,$f24
/*  f1335dc:	04410005 */ 	bgez	$v0,.NB0f1335f4
/*  f1335e0:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f1335e4:	3c014f80 */ 	lui	$at,0x4f80
/*  f1335e8:	44814000 */ 	mtc1	$at,$f8
/*  f1335ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1335f0:	46085280 */ 	add.s	$f10,$f10,$f8
.NB0f1335f4:
/*  f1335f4:	46185402 */ 	mul.s	$f16,$f10,$f24
/*  f1335f8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1335fc:	c432fd50 */ 	lwc1	$f18,-0x2b0($at)
/*  f133600:	4612803c */ 	c.lt.s	$f16,$f18
/*  f133604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133608:	45000009 */ 	bc1f	.NB0f133630
/*  f13360c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133610:	0c004d84 */ 	jal	random
/*  f133614:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133618:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f13361c:	30480003 */ 	andi	$t0,$v0,0x3
/*  f133620:	44802000 */ 	mtc1	$zero,$f4
/*  f133624:	a12841f5 */ 	sb	$t0,0x41f5($t1)
/*  f133628:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f13362c:	e54441f8 */ 	swc1	$f4,0x41f8($t2)
.NB0f133630:
/*  f133630:	0c004d84 */ 	jal	random
/*  f133634:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133638:	44823000 */ 	mtc1	$v0,$f6
/*  f13363c:	3c014f80 */ 	lui	$at,0x4f80
/*  f133640:	04410004 */ 	bgez	$v0,.NB0f133654
/*  f133644:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f133648:	44815000 */ 	mtc1	$at,$f10
/*  f13364c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133650:	460a4200 */ 	add.s	$f8,$f8,$f10
.NB0f133654:
/*  f133654:	46184402 */ 	mul.s	$f16,$f8,$f24
/*  f133658:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13365c:	c432fd54 */ 	lwc1	$f18,-0x2ac($at)
/*  f133660:	4612803c */ 	c.lt.s	$f16,$f18
/*  f133664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133668:	45000009 */ 	bc1f	.NB0f133690
/*  f13366c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133670:	0c004d84 */ 	jal	random
/*  f133674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133678:	24010005 */ 	addiu	$at,$zero,0x5
/*  f13367c:	0041001b */ 	divu	$zero,$v0,$at
/*  f133680:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f133684:	00005810 */ 	mfhi	$t3
/*  f133688:	a18b41fc */ 	sb	$t3,0x41fc($t4)
/*  f13368c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f133690:
/*  f133690:	0c004d84 */ 	jal	random
/*  f133694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133698:	44822000 */ 	mtc1	$v0,$f4
/*  f13369c:	3c014f80 */ 	lui	$at,0x4f80
/*  f1336a0:	04410004 */ 	bgez	$v0,.NB0f1336b4
/*  f1336a4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1336a8:	44815000 */ 	mtc1	$at,$f10
/*  f1336ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1336b0:	460a3180 */ 	add.s	$f6,$f6,$f10
.NB0f1336b4:
/*  f1336b4:	46183202 */ 	mul.s	$f8,$f6,$f24
/*  f1336b8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1336bc:	c430fd58 */ 	lwc1	$f16,-0x2a8($at)
/*  f1336c0:	4610403c */ 	c.lt.s	$f8,$f16
/*  f1336c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1336c8:	4502000b */ 	bc1fl	.NB0f1336f8
/*  f1336cc:	3c0141f0 */ 	lui	$at,0x41f0
/*  f1336d0:	0c004d84 */ 	jal	random
/*  f1336d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1336d8:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f1336dc:	304d0001 */ 	andi	$t5,$v0,0x1
/*  f1336e0:	0c004d84 */ 	jal	random
/*  f1336e4:	a1cd41fd */ 	sb	$t5,0x41fd($t6)
/*  f1336e8:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f1336ec:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f1336f0:	a30f41fe */ 	sb	$t7,0x41fe($t8)
/*  f1336f4:	3c0141f0 */ 	lui	$at,0x41f0
.NB0f1336f8:
/*  f1336f8:	4481d000 */ 	mtc1	$at,$f26
/*  f1336fc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f133700:	c436fd5c */ 	lwc1	$f22,-0x2a4($at)
/*  f133704:	00009025 */ 	or	$s2,$zero,$zero
/*  f133708:	00008025 */ 	or	$s0,$zero,$zero
.NB0f13370c:
/*  f13370c:	32590007 */ 	andi	$t9,$s2,0x7
/*  f133710:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f133714:	44889000 */ 	mtc1	$t0,$f18
/*  f133718:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13371c:	c42afd60 */ 	lwc1	$f10,-0x2a0($at)
/*  f133720:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f133724:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f133728:	324a0008 */ 	andi	$t2,$s2,0x8
/*  f13372c:	01301021 */ 	addu	$v0,$t1,$s0
/*  f133730:	460a2082 */ 	mul.s	$f2,$f4,$f10
/*  f133734:	15400002 */ 	bnez	$t2,.NB0f133740
/*  f133738:	46001006 */ 	mov.s	$f0,$f2
/*  f13373c:	46001007 */ 	neg.s	$f0,$f2
.NB0f133740:
/*  f133740:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f133744:	3c01800a */ 	lui	$at,0x800a
/*  f133748:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f13374c:	e4480018 */ 	swc1	$f8,0x18($v0)
/*  f133750:	c430e708 */ 	lwc1	$f16,-0x18f8($at)
/*  f133754:	3c013e80 */ 	lui	$at,0x3e80
/*  f133758:	44812000 */ 	mtc1	$at,$f4
/*  f13375c:	461a8482 */ 	mul.s	$f18,$f16,$f26
/*  f133760:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f133764:	44804000 */ 	mtc1	$zero,$f8
/*  f133768:	01701021 */ 	addu	$v0,$t3,$s0
/*  f13376c:	c44a0014 */ 	lwc1	$f10,0x14($v0)
/*  f133770:	46049002 */ 	mul.s	$f0,$f18,$f4
/*  f133774:	46005180 */ 	add.s	$f6,$f10,$f0
/*  f133778:	e4460014 */ 	swc1	$f6,0x14($v0)
/*  f13377c:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f133780:	01906821 */ 	addu	$t5,$t4,$s0
/*  f133784:	c5b00014 */ 	lwc1	$f16,0x14($t5)
/*  f133788:	4610403c */ 	c.lt.s	$f8,$f16
/*  f13378c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133790:	4502006b */ 	bc1fl	.NB0f133940
/*  f133794:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f133798:	0c004d84 */ 	jal	random
/*  f13379c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1337a0:	44829000 */ 	mtc1	$v0,$f18
/*  f1337a4:	3c014f80 */ 	lui	$at,0x4f80
/*  f1337a8:	04410004 */ 	bgez	$v0,.NB0f1337bc
/*  f1337ac:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f1337b0:	44815000 */ 	mtc1	$at,$f10
/*  f1337b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1337b8:	460a2100 */ 	add.s	$f4,$f4,$f10
.NB0f1337bc:
/*  f1337bc:	46182502 */ 	mul.s	$f20,$f4,$f24
/*  f1337c0:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f1337c4:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f1337c8:	4614a180 */ 	add.s	$f6,$f20,$f20
/*  f1337cc:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f1337d0:	46164401 */ 	sub.s	$f16,$f8,$f22
/*  f1337d4:	0c004d84 */ 	jal	random
/*  f1337d8:	e5f0000c */ 	swc1	$f16,0xc($t7)
/*  f1337dc:	44829000 */ 	mtc1	$v0,$f18
/*  f1337e0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1337e4:	04410004 */ 	bgez	$v0,.NB0f1337f8
/*  f1337e8:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f1337ec:	44812000 */ 	mtc1	$at,$f4
/*  f1337f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1337f4:	46045280 */ 	add.s	$f10,$f10,$f4
.NB0f1337f8:
/*  f1337f8:	46185502 */ 	mul.s	$f20,$f10,$f24
/*  f1337fc:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f133800:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f133804:	4614a180 */ 	add.s	$f6,$f20,$f20
/*  f133808:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f13380c:	46164401 */ 	sub.s	$f16,$f8,$f22
/*  f133810:	0c004d84 */ 	jal	random
/*  f133814:	e7300010 */ 	swc1	$f16,0x10($t9)
/*  f133818:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f13381c:	30480003 */ 	andi	$t0,$v0,0x3
/*  f133820:	01305021 */ 	addu	$t2,$t1,$s0
/*  f133824:	0c004d84 */ 	jal	random
/*  f133828:	a148001e */ 	sb	$t0,0x1e($t2)
/*  f13382c:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f133830:	304b0003 */ 	andi	$t3,$v0,0x3
/*  f133834:	01906821 */ 	addu	$t5,$t4,$s0
/*  f133838:	0c004d84 */ 	jal	random
/*  f13383c:	a1ab0020 */ 	sb	$t3,0x20($t5)
/*  f133840:	44829000 */ 	mtc1	$v0,$f18
/*  f133844:	3c014f80 */ 	lui	$at,0x4f80
/*  f133848:	04410004 */ 	bgez	$v0,.NB0f13385c
/*  f13384c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f133850:	44815000 */ 	mtc1	$at,$f10
/*  f133854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f133858:	460a2100 */ 	add.s	$f4,$f4,$f10
.NB0f13385c:
/*  f13385c:	46182182 */ 	mul.s	$f6,$f4,$f24
/*  f133860:	3c017f1b */ 	lui	$at,0x7f1b
/*  f133864:	c428fd64 */ 	lwc1	$f8,-0x29c($at)
/*  f133868:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f13386c:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f133870:	46083402 */ 	mul.s	$f16,$f6,$f8
/*  f133874:	e5f00018 */ 	swc1	$f16,0x18($t7)
/*  f133878:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f13387c:	90644200 */ 	lbu	$a0,0x4200($v1)
/*  f133880:	907841ff */ 	lbu	$t8,0x41ff($v1)
/*  f133884:	00705821 */ 	addu	$t3,$v1,$s0
/*  f133888:	0098082a */ 	slt	$at,$a0,$t8
/*  f13388c:	50200012 */ 	beqzl	$at,.NB0f1338d8
/*  f133890:	a164001f */ 	sb	$a0,0x1f($t3)
/*  f133894:	0c004d84 */ 	jal	random
/*  f133898:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13389c:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f1338a0:	90644200 */ 	lbu	$a0,0x4200($v1)
/*  f1338a4:	907941ff */ 	lbu	$t9,0x41ff($v1)
/*  f1338a8:	00706021 */ 	addu	$t4,$v1,$s0
/*  f1338ac:	03244823 */ 	subu	$t1,$t9,$a0
/*  f1338b0:	0049001b */ 	divu	$zero,$v0,$t1
/*  f1338b4:	00004010 */ 	mfhi	$t0
/*  f1338b8:	01045021 */ 	addu	$t2,$t0,$a0
/*  f1338bc:	15200002 */ 	bnez	$t1,.NB0f1338c8
/*  f1338c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1338c4:	0007000d */ 	break	0x7
.NB0f1338c8:
/*  f1338c8:	a18a001f */ 	sb	$t2,0x1f($t4)
/*  f1338cc:	10000003 */ 	beqz	$zero,.NB0f1338dc
/*  f1338d0:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f1338d4:	a164001f */ 	sb	$a0,0x1f($t3)
.NB0f1338d8:
/*  f1338d8:	8e230000 */ 	lw	$v1,0x0($s1)
.NB0f1338dc:
/*  f1338dc:	906d41fc */ 	lbu	$t5,0x41fc($v1)
/*  f1338e0:	00707021 */ 	addu	$t6,$v1,$s0
/*  f1338e4:	0c004d84 */ 	jal	random
/*  f1338e8:	a1cd001c */ 	sb	$t5,0x1c($t6)
/*  f1338ec:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f1338f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1338f4:	55e10007 */ 	bnel	$t7,$at,.NB0f133914
/*  f1338f8:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f1338fc:	8e230000 */ 	lw	$v1,0x0($s1)
/*  f133900:	907841fd */ 	lbu	$t8,0x41fd($v1)
/*  f133904:	0070c821 */ 	addu	$t9,$v1,$s0
/*  f133908:	10000005 */ 	beqz	$zero,.NB0f133920
/*  f13390c:	a338001d */ 	sb	$t8,0x1d($t9)
/*  f133910:	8e230000 */ 	lw	$v1,0x0($s1)
.NB0f133914:
/*  f133914:	906941fe */ 	lbu	$t1,0x41fe($v1)
/*  f133918:	00704021 */ 	addu	$t0,$v1,$s0
/*  f13391c:	a109001d */ 	sb	$t1,0x1d($t0)
.NB0f133920:
/*  f133920:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f133924:	3c01c5fa */ 	lui	$at,0xc5fa
/*  f133928:	44815000 */ 	mtc1	$at,$f10
/*  f13392c:	01501021 */ 	addu	$v0,$t2,$s0
/*  f133930:	c4520014 */ 	lwc1	$f18,0x14($v0)
/*  f133934:	460a9100 */ 	add.s	$f4,$f18,$f10
/*  f133938:	e4440014 */ 	swc1	$f4,0x14($v0)
/*  f13393c:	26520001 */ 	addiu	$s2,$s2,0x1
.NB0f133940:
/*  f133940:	240101f4 */ 	addiu	$at,$zero,0x1f4
/*  f133944:	1641ff71 */ 	bne	$s2,$at,.NB0f13370c
/*  f133948:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f13394c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f133950:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f133954:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f133958:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f13395c:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f133960:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f133964:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f133968:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f13396c:	03e00008 */ 	jr	$ra
/*  f133970:	27bd0048 */ 	addiu	$sp,$sp,0x48
);
#endif

// Mismatch: 30.0f should be loaded earlier and needs to go into a callee-save
// register.
//void func0f13899c(void)
//{
//	s32 i;
//	f32 tmp;
//
//	if (g_CreditsData->unk41f5 >= 0) {
//		g_CreditsData->unk41f8 += g_Vars.diffframe240f / 720.0f;
//
//		if (g_CreditsData->unk41f8 > 1.0f) {
//			g_CreditsData->unk41f6 = g_CreditsData->unk41f5;
//			g_CreditsData->unk41f5 = -1;
//		}
//	} else {
//		if (random() * (1.0f / U32_MAX) < 0.007f && joyGetButtons(0, L_TRIG | R_TRIG) == 0) {
//			g_CreditsData->unk41f5 = random() % 4;
//			g_CreditsData->unk41f8 = 0;
//		}
//	}
//
//	if (random() * (1.0f / U32_MAX) < 0.002f && joyGetButtons(0, L_TRIG | R_TRIG) == 0) {
//		g_CreditsData->unk41fc = random() % 5;
//	}
//
//	if (joyGetButtonsPressedThisFrame(0, R_TRIG)) {
//		g_CreditsData->unk41fc = random() % 5;
//
//		if (g_CreditsData->unk41f5 < 0) {
//			g_CreditsData->unk41f5 = random() % 4;
//			g_CreditsData->unk41f8 = 0;
//		}
//	}
//
//	if (random() * (1.0f / U32_MAX) < 0.007f) {
//		g_CreditsData->unk41fd = random() % 2;
//		g_CreditsData->unk41fe = random() % 2;
//	}
//
//	for (i = 0; i < 500; i++) {
//		tmp = ((i & 7) + 1) * 0.01f;
//
//		if ((i & 8) == 0) {
//			tmp = -tmp;
//		}
//
//		g_CreditsData->unk000c[i].unk0c += tmp;
//
//		g_CreditsData->unk000c[i].unk08 += g_Vars.diffframe240f * 30.0f * 0.25f;
//
//		if (g_CreditsData->unk000c[i].unk08 > 0) {
//			tmp = random() * (1.0f / U32_MAX);
//			g_CreditsData->unk000c[i].unk00 = (tmp + tmp) * 3000 - 3000;
//
//			tmp = random() * (1.0f / U32_MAX);
//			g_CreditsData->unk000c[i].unk04 = (tmp + tmp) * 3000 - 3000;
//
//			g_CreditsData->unk000c[i].unk12 = random() % 4;
//			g_CreditsData->unk000c[i].unk14 = random() % 4;
//
//			g_CreditsData->unk000c[i].unk0c = random() * (1.0f / U32_MAX) * M_BADTAU;
//
//			if (g_CreditsData->unk4200 < g_CreditsData->unk41ff) {
//				g_CreditsData->unk000c[i].unk13 = g_CreditsData->unk4200
//					+ random() % (g_CreditsData->unk41ff - g_CreditsData->unk4200);
//			} else {
//				g_CreditsData->unk000c[i].unk13 = g_CreditsData->unk4200;
//			}
//
//			g_CreditsData->unk000c[i].unk10 = g_CreditsData->unk41fc;
//
//			if (random() % 2 == 1) {
//				g_CreditsData->unk000c[i].unk11 = g_CreditsData->unk41fd;
//			} else {
//				g_CreditsData->unk000c[i].unk11 = g_CreditsData->unk41fe;
//			}
//
//			g_CreditsData->unk000c[i].unk08 += -8000;
//		}
//	}
//}

GLOBAL_ASM(
glabel func0f138e6c
.late_rodata
glabel var7f1b5828
.word func0f138e6c+0x3f4 # f139260
glabel var7f1b582c
.word func0f138e6c+0x60 # f138ecc
glabel var7f1b5830
.word func0f138e6c+0x158 # f138fc4
glabel var7f1b5834
.word func0f138e6c+0x1f4 # f139060
glabel var7f1b5838
.word func0f138e6c+0x2f0 # f13915c
glabel var7f1b583c
.word 0x40c907a9
glabel var7f1b5840
.word 0x40c907a9
glabel var7f1b5844
.word 0x40c907a9
.text
/*  f138e6c:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f138e70:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f138e74:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f138e78:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f138e7c:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f138e80:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f138e84:	90a20010 */ 	lbu	$v0,0x10($a1)
/*  f138e88:	00a08025 */ 	or	$s0,$a1,$zero
/*  f138e8c:	00808825 */ 	or	$s1,$a0,$zero
/*  f138e90:	28410005 */ 	slti	$at,$v0,0x5
/*  f138e94:	14200005 */ 	bnez	$at,.L0f138eac
/*  f138e98:	24010063 */ 	addiu	$at,$zero,0x63
/*  f138e9c:	504100e6 */ 	beql	$v0,$at,.L0f139238
/*  f138ea0:	3c01c57a */ 	lui	$at,0xc57a
/*  f138ea4:	100000ef */ 	b	.L0f139264
/*  f138ea8:	c6080000 */ 	lwc1	$f8,0x0($s0)
.L0f138eac:
/*  f138eac:	2c410005 */ 	sltiu	$at,$v0,0x5
/*  f138eb0:	102000eb */ 	beqz	$at,.L0f139260
/*  f138eb4:	00027080 */ 	sll	$t6,$v0,0x2
/*  f138eb8:	3c017f1b */ 	lui	$at,%hi(var7f1b5828)
/*  f138ebc:	002e0821 */ 	addu	$at,$at,$t6
/*  f138ec0:	8c2e5828 */ 	lw	$t6,%lo(var7f1b5828)($at)
/*  f138ec4:	01c00008 */ 	jr	$t6
/*  f138ec8:	00000000 */ 	nop
/*  f138ecc:	3c017f1b */ 	lui	$at,%hi(var7f1b583c)
/*  f138ed0:	c430583c */ 	lwc1	$f16,%lo(var7f1b583c)($at)
/*  f138ed4:	3c01800a */ 	lui	$at,%hi(var800a4160)
/*  f138ed8:	c4244160 */ 	lwc1	$f4,%lo(var800a4160)($at)
/*  f138edc:	3c014396 */ 	lui	$at,0x4396
/*  f138ee0:	44814000 */ 	mtc1	$at,$f8
/*  f138ee4:	46102182 */ 	mul.s	$f6,$f4,$f16
/*  f138ee8:	e7a60044 */ 	swc1	$f6,0x44($sp)
/*  f138eec:	c6000000 */ 	lwc1	$f0,0x0($s0)
/*  f138ef0:	e7a0004c */ 	swc1	$f0,0x4c($sp)
/*  f138ef4:	0c0068f7 */ 	jal	sinf
/*  f138ef8:	46080303 */ 	div.s	$f12,$f0,$f8
/*  f138efc:	3c014396 */ 	lui	$at,0x4396
/*  f138f00:	44812000 */ 	mtc1	$at,$f4
/*  f138f04:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f138f08:	46000506 */ 	mov.s	$f20,$f0
/*  f138f0c:	0c0068f4 */ 	jal	cosf
/*  f138f10:	46045303 */ 	div.s	$f12,$f10,$f4
/*  f138f14:	46140180 */ 	add.s	$f6,$f0,$f20
/*  f138f18:	3c0142c8 */ 	lui	$at,0x42c8
/*  f138f1c:	44814000 */ 	mtc1	$at,$f8
/*  f138f20:	3c01c3c8 */ 	lui	$at,0xc3c8
/*  f138f24:	44812000 */ 	mtc1	$at,$f4
/*  f138f28:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f138f2c:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f138f30:	24010001 */ 	addiu	$at,$zero,0x1
/*  f138f34:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f138f38:	46045080 */ 	add.s	$f2,$f10,$f4
/*  f138f3c:	17010005 */ 	bne	$t8,$at,.L0f138f54
/*  f138f40:	46001386 */ 	mov.s	$f14,$f2
/*  f138f44:	3c014448 */ 	lui	$at,0x4448
/*  f138f48:	44813000 */ 	mtc1	$at,$f6
/*  f138f4c:	00000000 */ 	nop
/*  f138f50:	46061380 */ 	add.s	$f14,$f2,$f6
.L0f138f54:
/*  f138f54:	c6080008 */ 	lwc1	$f8,0x8($s0)
/*  f138f58:	e6280008 */ 	swc1	$f8,0x8($s1)
/*  f138f5c:	e7ae0048 */ 	swc1	$f14,0x48($sp)
/*  f138f60:	0c0068f7 */ 	jal	sinf
/*  f138f64:	c7ac0044 */ 	lwc1	$f12,0x44($sp)
/*  f138f68:	46000506 */ 	mov.s	$f20,$f0
/*  f138f6c:	0c0068f4 */ 	jal	cosf
/*  f138f70:	c7ac0044 */ 	lwc1	$f12,0x44($sp)
/*  f138f74:	c7aa0048 */ 	lwc1	$f10,0x48($sp)
/*  f138f78:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f138f7c:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f138f80:	00000000 */ 	nop
/*  f138f84:	4606a202 */ 	mul.s	$f8,$f20,$f6
/*  f138f88:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f138f8c:	e62a0000 */ 	swc1	$f10,0x0($s1)
/*  f138f90:	0c0068f4 */ 	jal	cosf
/*  f138f94:	c7ac0044 */ 	lwc1	$f12,0x44($sp)
/*  f138f98:	46000506 */ 	mov.s	$f20,$f0
/*  f138f9c:	0c0068f7 */ 	jal	sinf
/*  f138fa0:	c7ac0044 */ 	lwc1	$f12,0x44($sp)
/*  f138fa4:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f138fa8:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f138fac:	4606a102 */ 	mul.s	$f4,$f20,$f6
/*  f138fb0:	00000000 */ 	nop
/*  f138fb4:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f138fb8:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f138fbc:	100000ae */ 	b	.L0f139278
/*  f138fc0:	e6260004 */ 	swc1	$f6,0x4($s1)
/*  f138fc4:	3c014396 */ 	lui	$at,0x4396
/*  f138fc8:	44812000 */ 	mtc1	$at,$f4
/*  f138fcc:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f138fd0:	0c0068f4 */ 	jal	cosf
/*  f138fd4:	46044303 */ 	div.s	$f12,$f8,$f4
/*  f138fd8:	3c014396 */ 	lui	$at,0x4396
/*  f138fdc:	44813000 */ 	mtc1	$at,$f6
/*  f138fe0:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f138fe4:	46000506 */ 	mov.s	$f20,$f0
/*  f138fe8:	0c0068f7 */ 	jal	sinf
/*  f138fec:	46065303 */ 	div.s	$f12,$f10,$f6
/*  f138ff0:	46140200 */ 	add.s	$f8,$f0,$f20
/*  f138ff4:	3c0142c8 */ 	lui	$at,0x42c8
/*  f138ff8:	44812000 */ 	mtc1	$at,$f4
/*  f138ffc:	c6060000 */ 	lwc1	$f6,0x0($s0)
/*  f139000:	3c014396 */ 	lui	$at,0x4396
/*  f139004:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f139008:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f13900c:	44815000 */ 	mtc1	$at,$f10
/*  f139010:	e6280000 */ 	swc1	$f8,0x0($s1)
/*  f139014:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f139018:	0c0068f7 */ 	jal	sinf
/*  f13901c:	460a2303 */ 	div.s	$f12,$f4,$f10
/*  f139020:	3c014396 */ 	lui	$at,0x4396
/*  f139024:	44814000 */ 	mtc1	$at,$f8
/*  f139028:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f13902c:	46000506 */ 	mov.s	$f20,$f0
/*  f139030:	0c0068f4 */ 	jal	cosf
/*  f139034:	46083303 */ 	div.s	$f12,$f6,$f8
/*  f139038:	46140100 */ 	add.s	$f4,$f0,$f20
/*  f13903c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f139040:	44815000 */ 	mtc1	$at,$f10
/*  f139044:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f139048:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f13904c:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f139050:	e6240004 */ 	swc1	$f4,0x4($s1)
/*  f139054:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f139058:	10000087 */ 	b	.L0f139278
/*  f13905c:	e62a0008 */ 	swc1	$f10,0x8($s1)
/*  f139060:	3c017f1b */ 	lui	$at,%hi(var7f1b5840)
/*  f139064:	c4305840 */ 	lwc1	$f16,%lo(var7f1b5840)($at)
/*  f139068:	3c0140a0 */ 	lui	$at,0x40a0
/*  f13906c:	44819000 */ 	mtc1	$at,$f18
/*  f139070:	3c01c5fa */ 	lui	$at,0xc5fa
/*  f139074:	44815000 */ 	mtc1	$at,$f10
/*  f139078:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f13907c:	c6060000 */ 	lwc1	$f6,0x0($s0)
/*  f139080:	4480a000 */ 	mtc1	$zero,$f20
/*  f139084:	460a2303 */ 	div.s	$f12,$f4,$f10
/*  f139088:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f13908c:	3c0143d2 */ 	lui	$at,0x43d2
/*  f139090:	46123083 */ 	div.s	$f2,$f6,$f18
/*  f139094:	460c6182 */ 	mul.s	$f6,$f12,$f12
/*  f139098:	00000000 */ 	nop
/*  f13909c:	46103302 */ 	mul.s	$f12,$f6,$f16
/*  f1390a0:	4614103c */ 	c.lt.s	$f2,$f20
/*  f1390a4:	00000000 */ 	nop
/*  f1390a8:	45000005 */ 	bc1f	.L0f1390c0
/*  f1390ac:	46124383 */ 	div.s	$f14,$f8,$f18
/*  f1390b0:	3c0143d2 */ 	lui	$at,0x43d2
/*  f1390b4:	44810000 */ 	mtc1	$at,$f0
/*  f1390b8:	10000004 */ 	b	.L0f1390cc
/*  f1390bc:	46001081 */ 	sub.s	$f2,$f2,$f0
.L0f1390c0:
/*  f1390c0:	44810000 */ 	mtc1	$at,$f0
/*  f1390c4:	00000000 */ 	nop
/*  f1390c8:	46001080 */ 	add.s	$f2,$f2,$f0
.L0f1390cc:
/*  f1390cc:	4614703c */ 	c.lt.s	$f14,$f20
/*  f1390d0:	00000000 */ 	nop
/*  f1390d4:	45020004 */ 	bc1fl	.L0f1390e8
/*  f1390d8:	46007380 */ 	add.s	$f14,$f14,$f0
/*  f1390dc:	10000002 */ 	b	.L0f1390e8
/*  f1390e0:	46007381 */ 	sub.s	$f14,$f14,$f0
/*  f1390e4:	46007380 */ 	add.s	$f14,$f14,$f0
.L0f1390e8:
/*  f1390e8:	e7a20040 */ 	swc1	$f2,0x40($sp)
/*  f1390ec:	e7ac0038 */ 	swc1	$f12,0x38($sp)
/*  f1390f0:	0c0068f7 */ 	jal	sinf
/*  f1390f4:	e7ae003c */ 	swc1	$f14,0x3c($sp)
/*  f1390f8:	c7ac0038 */ 	lwc1	$f12,0x38($sp)
/*  f1390fc:	0c0068f4 */ 	jal	cosf
/*  f139100:	46000506 */ 	mov.s	$f20,$f0
/*  f139104:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*  f139108:	c7a20040 */ 	lwc1	$f2,0x40($sp)
/*  f13910c:	c7ac0038 */ 	lwc1	$f12,0x38($sp)
/*  f139110:	460e0202 */ 	mul.s	$f8,$f0,$f14
/*  f139114:	00000000 */ 	nop
/*  f139118:	4602a102 */ 	mul.s	$f4,$f20,$f2
/*  f13911c:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f139120:	0c0068f4 */ 	jal	cosf
/*  f139124:	e62a0000 */ 	swc1	$f10,0x0($s1)
/*  f139128:	c7ac0038 */ 	lwc1	$f12,0x38($sp)
/*  f13912c:	0c0068f7 */ 	jal	sinf
/*  f139130:	46000506 */ 	mov.s	$f20,$f0
/*  f139134:	c7a20040 */ 	lwc1	$f2,0x40($sp)
/*  f139138:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*  f13913c:	4602a182 */ 	mul.s	$f6,$f20,$f2
/*  f139140:	00000000 */ 	nop
/*  f139144:	460e0202 */ 	mul.s	$f8,$f0,$f14
/*  f139148:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f13914c:	e6240004 */ 	swc1	$f4,0x4($s1)
/*  f139150:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f139154:	10000048 */ 	b	.L0f139278
/*  f139158:	e62a0008 */ 	swc1	$f10,0x8($s1)
/*  f13915c:	3c0143c8 */ 	lui	$at,0x43c8
/*  f139160:	44811000 */ 	mtc1	$at,$f2
/*  f139164:	3c0140a0 */ 	lui	$at,0x40a0
/*  f139168:	44819000 */ 	mtc1	$at,$f18
/*  f13916c:	c6060000 */ 	lwc1	$f6,0x0($s0)
/*  f139170:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f139174:	3c01c5fa */ 	lui	$at,0xc5fa
/*  f139178:	46123203 */ 	div.s	$f8,$f6,$f18
/*  f13917c:	44815000 */ 	mtc1	$at,$f10
/*  f139180:	24010001 */ 	addiu	$at,$zero,0x1
/*  f139184:	33280001 */ 	andi	$t0,$t9,0x1
/*  f139188:	46001006 */ 	mov.s	$f0,$f2
/*  f13918c:	e7a80034 */ 	swc1	$f8,0x34($sp)
/*  f139190:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f139194:	15010002 */ 	bne	$t0,$at,.L0f1391a0
/*  f139198:	460a2303 */ 	div.s	$f12,$f4,$f10
/*  f13919c:	46001007 */ 	neg.s	$f0,$f2
.L0f1391a0:
/*  f1391a0:	460c6182 */ 	mul.s	$f6,$f12,$f12
/*  f1391a4:	3c017f1b */ 	lui	$at,%hi(var7f1b5844)
/*  f1391a8:	c4305844 */ 	lwc1	$f16,%lo(var7f1b5844)($at)
/*  f1391ac:	3c01800a */ 	lui	$at,%hi(var800a4160)
/*  f1391b0:	c4244160 */ 	lwc1	$f4,%lo(var800a4160)($at)
/*  f1391b4:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f1391b8:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f1391bc:	00000000 */ 	nop
/*  f1391c0:	46102282 */ 	mul.s	$f10,$f4,$f16
/*  f1391c4:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f1391c8:	0c0068f7 */ 	jal	sinf
/*  f1391cc:	e7ac002c */ 	swc1	$f12,0x2c($sp)
/*  f1391d0:	c7ac002c */ 	lwc1	$f12,0x2c($sp)
/*  f1391d4:	0c0068f4 */ 	jal	cosf
/*  f1391d8:	46000506 */ 	mov.s	$f20,$f0
/*  f1391dc:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f1391e0:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f1391e4:	c7ac002c */ 	lwc1	$f12,0x2c($sp)
/*  f1391e8:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f1391ec:	00000000 */ 	nop
/*  f1391f0:	4608a282 */ 	mul.s	$f10,$f20,$f8
/*  f1391f4:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f1391f8:	0c0068f4 */ 	jal	cosf
/*  f1391fc:	e6260000 */ 	swc1	$f6,0x0($s1)
/*  f139200:	c7ac002c */ 	lwc1	$f12,0x2c($sp)
/*  f139204:	0c0068f7 */ 	jal	sinf
/*  f139208:	46000506 */ 	mov.s	$f20,$f0
/*  f13920c:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f139210:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*  f139214:	4608a102 */ 	mul.s	$f4,$f20,$f8
/*  f139218:	00000000 */ 	nop
/*  f13921c:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f139220:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f139224:	e6280004 */ 	swc1	$f8,0x4($s1)
/*  f139228:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f13922c:	10000012 */ 	b	.L0f139278
/*  f139230:	e62a0008 */ 	swc1	$f10,0x8($s1)
/*  f139234:	3c01c57a */ 	lui	$at,0xc57a
.L0f139238:
/*  f139238:	44813000 */ 	mtc1	$at,$f6
/*  f13923c:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f139240:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f139244:	46004287 */ 	neg.s	$f10,$f8
/*  f139248:	e62a0004 */ 	swc1	$f10,0x4($s1)
/*  f13924c:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f139250:	e6240000 */ 	swc1	$f4,0x0($s1)
/*  f139254:	c6060004 */ 	lwc1	$f6,0x4($s0)
/*  f139258:	10000007 */ 	b	.L0f139278
/*  f13925c:	e6260008 */ 	swc1	$f6,0x8($s1)
.L0f139260:
/*  f139260:	c6080000 */ 	lwc1	$f8,0x0($s0)
.L0f139264:
/*  f139264:	e6280000 */ 	swc1	$f8,0x0($s1)
/*  f139268:	c60a0004 */ 	lwc1	$f10,0x4($s0)
/*  f13926c:	e62a0004 */ 	swc1	$f10,0x4($s1)
/*  f139270:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f139274:	e6240008 */ 	swc1	$f4,0x8($s1)
.L0f139278:
/*  f139278:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f13927c:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f139280:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f139284:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f139288:	03e00008 */ 	jr	$ra
/*  f13928c:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel creditsRenderSprites
.late_rodata
glabel var7f1b5848
.word 0xc58ca000
glabel var7f1b584c
.word 0x455ac000
glabel var7f1b5850
.word 0x416fd70a
.text
/*  f139290:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f139294:	afa40118 */ 	sw	$a0,0x118($sp)
/*  f139298:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f13929c:	3c047f1b */ 	lui	$a0,%hi(var7f1b57c0)
/*  f1392a0:	3c058008 */ 	lui	$a1,%hi(var8007f468)
/*  f1392a4:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f1392a8:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f1392ac:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f1392b0:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f1392b4:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f1392b8:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f1392bc:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f1392c0:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f1392c4:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f1392c8:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f1392cc:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f1392d0:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f1392d4:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f1392d8:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f1392dc:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f1392e0:	24a5f468 */ 	addiu	$a1,$a1,%lo(var8007f468)
/*  f1392e4:	0c0036cc */ 	jal	func0000db30
/*  f1392e8:	248457c0 */ 	addiu	$a0,$a0,%lo(var7f1b57c0)
/*  f1392ec:	3c047f1b */ 	lui	$a0,%hi(var7f1b57c8)
/*  f1392f0:	3c058008 */ 	lui	$a1,%hi(var8007f46c)
/*  f1392f4:	24a5f46c */ 	addiu	$a1,$a1,%lo(var8007f46c)
/*  f1392f8:	0c0036cc */ 	jal	func0000db30
/*  f1392fc:	248457c8 */ 	addiu	$a0,$a0,%lo(var7f1b57c8)
/*  f139300:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f139304:	2404003c */ 	addiu	$a0,$zero,0x3c
/*  f139308:	3c01437f */ 	lui	$at,0x437f
/*  f13930c:	3c13800a */ 	lui	$s3,%hi(g_CreditsData)
/*  f139310:	3c128008 */ 	lui	$s2,%hi(var8007f410)
/*  f139314:	4481a000 */ 	mtc1	$at,$f20
/*  f139318:	0040f025 */ 	or	$s8,$v0,$zero
/*  f13931c:	2652f410 */ 	addiu	$s2,$s2,%lo(var8007f410)
/*  f139320:	26734170 */ 	addiu	$s3,$s3,%lo(g_CreditsData)
/*  f139324:	0000a025 */ 	or	$s4,$zero,$zero
/*  f139328:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13932c:	24170010 */ 	addiu	$s7,$zero,0x10
/*  f139330:	24160028 */ 	addiu	$s6,$zero,0x28
/*  f139334:	2411000f */ 	addiu	$s1,$zero,0xf
/*  f139338:	2410000f */ 	addiu	$s0,$zero,0xf
.L0f13933c:
/*  f13933c:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f139340:	804341f5 */ 	lb	$v1,0x41f5($v0)
/*  f139344:	0460002f */ 	bltz	$v1,.L0f139404
/*  f139348:	00037900 */ 	sll	$t7,$v1,0x4
/*  f13934c:	c44441f8 */ 	lwc1	$f4,0x41f8($v0)
/*  f139350:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f139354:	024fc021 */ 	addu	$t8,$s2,$t7
/*  f139358:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f13935c:	3c014f00 */ 	lui	$at,0x4f00
/*  f139360:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f139364:	444ef800 */ 	cfc1	$t6,$31
/*  f139368:	44c6f800 */ 	ctc1	$a2,$31
/*  f13936c:	00000000 */ 	nop
/*  f139370:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f139374:	4446f800 */ 	cfc1	$a2,$31
/*  f139378:	00000000 */ 	nop
/*  f13937c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f139380:	50c00013 */ 	beqzl	$a2,.L0f1393d0
/*  f139384:	44064000 */ 	mfc1	$a2,$f8
/*  f139388:	44814000 */ 	mtc1	$at,$f8
/*  f13938c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f139390:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f139394:	44c6f800 */ 	ctc1	$a2,$31
/*  f139398:	00000000 */ 	nop
/*  f13939c:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1393a0:	4446f800 */ 	cfc1	$a2,$31
/*  f1393a4:	00000000 */ 	nop
/*  f1393a8:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f1393ac:	14c00005 */ 	bnez	$a2,.L0f1393c4
/*  f1393b0:	00000000 */ 	nop
/*  f1393b4:	44064000 */ 	mfc1	$a2,$f8
/*  f1393b8:	3c018000 */ 	lui	$at,0x8000
/*  f1393bc:	10000007 */ 	b	.L0f1393dc
/*  f1393c0:	00c13025 */ 	or	$a2,$a2,$at
.L0f1393c4:
/*  f1393c4:	10000005 */ 	b	.L0f1393dc
/*  f1393c8:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1393cc:	44064000 */ 	mfc1	$a2,$f8
.L0f1393d0:
/*  f1393d0:	00000000 */ 	nop
/*  f1393d4:	04c0fffb */ 	bltz	$a2,.L0f1393c4
/*  f1393d8:	00000000 */ 	nop
.L0f1393dc:
/*  f1393dc:	804841f6 */ 	lb	$t0,0x41f6($v0)
/*  f1393e0:	44cef800 */ 	ctc1	$t6,$31
/*  f1393e4:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f1393e8:	00084900 */ 	sll	$t1,$t0,0x4
/*  f1393ec:	02495021 */ 	addu	$t2,$s2,$t1
/*  f1393f0:	01545821 */ 	addu	$t3,$t2,$s4
/*  f1393f4:	0fc01a40 */ 	jal	colourBlend
/*  f1393f8:	8d650000 */ 	lw	$a1,0x0($t3)
/*  f1393fc:	10000006 */ 	b	.L0f139418
/*  f139400:	00403025 */ 	or	$a2,$v0,$zero
.L0f139404:
/*  f139404:	804c41f6 */ 	lb	$t4,0x41f6($v0)
/*  f139408:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f13940c:	024d7021 */ 	addu	$t6,$s2,$t5
/*  f139410:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f139414:	8de60000 */ 	lw	$a2,0x0($t7)
.L0f139418:
/*  f139418:	3c188008 */ 	lui	$t8,%hi(var8007f468)
/*  f13941c:	8f18f468 */ 	lw	$t8,%lo(var8007f468)($t8)
/*  f139420:	00001025 */ 	or	$v0,$zero,$zero
/*  f139424:	02a01825 */ 	or	$v1,$s5,$zero
/*  f139428:	17160002 */ 	bne	$t8,$s6,.L0f139434
/*  f13942c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f139430:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f139434:
/*  f139434:	00c12024 */ 	and	$a0,$a2,$at
/*  f139438:	30c500ff */ 	andi	$a1,$a2,0xff
/*  f13943c:	0202c823 */ 	subu	$t9,$s0,$v0
.L0f139440:
/*  f139440:	00b90019 */ 	multu	$a1,$t9
/*  f139444:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f139448:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f13944c:	00004012 */ 	mflo	$t0
/*  f139450:	00000000 */ 	nop
/*  f139454:	00000000 */ 	nop
/*  f139458:	0111001b */ 	divu	$zero,$t0,$s1
/*  f13945c:	00004812 */ 	mflo	$t1
/*  f139460:	00895025 */ 	or	$t2,$a0,$t1
/*  f139464:	16200002 */ 	bnez	$s1,.L0f139470
/*  f139468:	00000000 */ 	nop
/*  f13946c:	0007000d */ 	break	0x7
.L0f139470:
/*  f139470:	ac6afff0 */ 	sw	$t2,-0x10($v1)
/*  f139474:	5450fff2 */ 	bnel	$v0,$s0,.L0f139440
/*  f139478:	0202c823 */ 	subu	$t9,$s0,$v0
/*  f13947c:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f139480:	1697ffae */ 	bne	$s4,$s7,.L0f13933c
/*  f139484:	26b50004 */ 	addiu	$s5,$s5,0x4
/*  f139488:	8fb00118 */ 	lw	$s0,0x118($sp)
/*  f13948c:	3c0d07ec */ 	lui	$t5,0x7ec
/*  f139490:	35ad00f0 */ 	ori	$t5,$t5,0xf0
/*  f139494:	260c0008 */ 	addiu	$t4,$s0,0x8
/*  f139498:	afac0118 */ 	sw	$t4,0x118($sp)
/*  f13949c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f1394a0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f1394a4:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f1394a8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1394ac:	3c1e800b */ 	lui	$s8,%hi(var800ab5a8)
/*  f1394b0:	4481e000 */ 	mtc1	$at,$f28
/*  f1394b4:	4480f000 */ 	mtc1	$zero,$f30
/*  f1394b8:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f1394bc:	27deb5a8 */ 	addiu	$s8,$s8,%lo(var800ab5a8)
/*  f1394c0:	0000a825 */ 	or	$s5,$zero,$zero
/*  f1394c4:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f1394c8:	27b60118 */ 	addiu	$s6,$sp,0x118
/*  f1394cc:	0000a025 */ 	or	$s4,$zero,$zero
.L0f1394d0:
/*  f1394d0:	00009025 */ 	or	$s2,$zero,$zero
/*  f1394d4:	00008825 */ 	or	$s1,$zero,$zero
.L0f1394d8:
/*  f1394d8:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f1394dc:	0015c080 */ 	sll	$t8,$s5,0x2
/*  f1394e0:	0315c023 */ 	subu	$t8,$t8,$s5
/*  f1394e4:	01d11021 */ 	addu	$v0,$t6,$s1
/*  f1394e8:	904f001d */ 	lbu	$t7,0x1d($v0)
/*  f1394ec:	3c198008 */ 	lui	$t9,%hi(var8007f450)
/*  f1394f0:	2739f450 */ 	addiu	$t9,$t9,%lo(var8007f450)
/*  f1394f4:	16af011b */ 	bne	$s5,$t7,.L0f139964
/*  f1394f8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1394fc:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f139500:	0c0068f7 */ 	jal	sinf
/*  f139504:	03198021 */ 	addu	$s0,$t8,$t9
/*  f139508:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f13950c:	46000686 */ 	mov.s	$f26,$f0
/*  f139510:	01114821 */ 	addu	$t1,$t0,$s1
/*  f139514:	0c0068f4 */ 	jal	cosf
/*  f139518:	c52c0018 */ 	lwc1	$f12,0x18($t1)
/*  f13951c:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f139520:	46000586 */ 	mov.s	$f22,$f0
/*  f139524:	3c014f80 */ 	lui	$at,0x4f80
/*  f139528:	01511021 */ 	addu	$v0,$t2,$s1
/*  f13952c:	904b001f */ 	lbu	$t3,0x1f($v0)
/*  f139530:	448b5000 */ 	mtc1	$t3,$f10
/*  f139534:	05610004 */ 	bgez	$t3,.L0f139548
/*  f139538:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f13953c:	44819000 */ 	mtc1	$at,$f18
/*  f139540:	00000000 */ 	nop
/*  f139544:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f139548:
/*  f139548:	3c014120 */ 	lui	$at,0x4120
/*  f13954c:	44812000 */ 	mtc1	$at,$f4
/*  f139550:	3c0141c8 */ 	lui	$at,0x41c8
/*  f139554:	44814000 */ 	mtc1	$at,$f8
/*  f139558:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f13955c:	1680005a */ 	bnez	$s4,.L0f1396c8
/*  f139560:	46083500 */ 	add.s	$f20,$f6,$f8
/*  f139564:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f139568:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f13956c:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f139570:	01970019 */ 	multu	$t4,$s7
/*  f139574:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f139578:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f13957c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f139580:	02c02025 */ 	or	$a0,$s6,$zero
/*  f139584:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f139588:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f13958c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f139590:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f139594:	00006812 */ 	mflo	$t5
/*  f139598:	01ae2821 */ 	addu	$a1,$t5,$t6
/*  f13959c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f1395a0:	00000000 */ 	nop
/*  f1395a4:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f1395a8:	3c09ba00 */ 	lui	$t1,0xba00
/*  f1395ac:	35291402 */ 	ori	$t1,$t1,0x1402
/*  f1395b0:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f1395b4:	afa80118 */ 	sw	$t0,0x118($sp)
/*  f1395b8:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1395bc:	af290000 */ 	sw	$t1,0x0($t9)
/*  f1395c0:	8faa0118 */ 	lw	$t2,0x118($sp)
/*  f1395c4:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1395c8:	358c0602 */ 	ori	$t4,$t4,0x602
/*  f1395cc:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f1395d0:	afab0118 */ 	sw	$t3,0x118($sp)
/*  f1395d4:	240d00c0 */ 	addiu	$t5,$zero,0xc0
/*  f1395d8:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f1395dc:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f1395e0:	8fae0118 */ 	lw	$t6,0x118($sp)
/*  f1395e4:	3c190050 */ 	lui	$t9,0x50
/*  f1395e8:	3c18b900 */ 	lui	$t8,0xb900
/*  f1395ec:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f1395f0:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f1395f4:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f1395f8:	37394240 */ 	ori	$t9,$t9,0x4240
/*  f1395fc:	add90004 */ 	sw	$t9,0x4($t6)
/*  f139600:	add80000 */ 	sw	$t8,0x0($t6)
/*  f139604:	8fa80118 */ 	lw	$t0,0x118($sp)
/*  f139608:	3c0ab900 */ 	lui	$t2,0xb900
/*  f13960c:	354a0002 */ 	ori	$t2,$t2,0x2
/*  f139610:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f139614:	afa90118 */ 	sw	$t1,0x118($sp)
/*  f139618:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f13961c:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f139620:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f139624:	3c0dba00 */ 	lui	$t5,0xba00
/*  f139628:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f13962c:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f139630:	afac0118 */ 	sw	$t4,0x118($sp)
/*  f139634:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f139638:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f13963c:	8fae0118 */ 	lw	$t6,0x118($sp)
/*  f139640:	3c18ba00 */ 	lui	$t8,0xba00
/*  f139644:	37180903 */ 	ori	$t8,$t8,0x903
/*  f139648:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f13964c:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f139650:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f139654:	add90004 */ 	sw	$t9,0x4($t6)
/*  f139658:	add80000 */ 	sw	$t8,0x0($t6)
/*  f13965c:	8fa80118 */ 	lw	$t0,0x118($sp)
/*  f139660:	3c0bff32 */ 	lui	$t3,0xff32
/*  f139664:	3c0afcff */ 	lui	$t2,0xfcff
/*  f139668:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f13966c:	afa90118 */ 	sw	$t1,0x118($sp)
/*  f139670:	354a99ff */ 	ori	$t2,$t2,0x99ff
/*  f139674:	356b7f3f */ 	ori	$t3,$t3,0x7f3f
/*  f139678:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f13967c:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f139680:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f139684:	3c0eba00 */ 	lui	$t6,0xba00
/*  f139688:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f13968c:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f139690:	afad0118 */ 	sw	$t5,0x118($sp)
/*  f139694:	240f2000 */ 	addiu	$t7,$zero,0x2000
/*  f139698:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f13969c:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f1396a0:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f1396a4:	3c08ba00 */ 	lui	$t0,0xba00
/*  f1396a8:	35081301 */ 	ori	$t0,$t0,0x1301
/*  f1396ac:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f1396b0:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f1396b4:	3c090008 */ 	lui	$t1,0x8
/*  f1396b8:	af090004 */ 	sw	$t1,0x4($t8)
/*  f1396bc:	af080000 */ 	sw	$t0,0x0($t8)
/*  f1396c0:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f1396c4:	01511021 */ 	addu	$v0,$t2,$s1
.L0f1396c8:
/*  f1396c8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f1396cc:	2445000c */ 	addiu	$a1,$v0,0xc
/*  f1396d0:	0fc4e39b */ 	jal	func0f138e6c
/*  f1396d4:	02403025 */ 	or	$a2,$s2,$zero
/*  f1396d8:	3c017f1b */ 	lui	$at,%hi(var7f1b5848)
/*  f1396dc:	c4325848 */ 	lwc1	$f18,%lo(var7f1b5848)($at)
/*  f1396e0:	c7aa00dc */ 	lwc1	$f10,0xdc($sp)
/*  f1396e4:	3c017f1b */ 	lui	$at,%hi(var7f1b584c)
/*  f1396e8:	c424584c */ 	lwc1	$f4,%lo(var7f1b584c)($at)
/*  f1396ec:	46125401 */ 	sub.s	$f16,$f10,$f18
/*  f1396f0:	46048183 */ 	div.s	$f6,$f16,$f4
/*  f1396f4:	4606e601 */ 	sub.s	$f24,$f28,$f6
/*  f1396f8:	461ec03c */ 	c.lt.s	$f24,$f30
/*  f1396fc:	00000000 */ 	nop
/*  f139700:	45020003 */ 	bc1fl	.L0f139710
/*  f139704:	4618e03c */ 	c.lt.s	$f28,$f24
/*  f139708:	4600f606 */ 	mov.s	$f24,$f30
/*  f13970c:	4618e03c */ 	c.lt.s	$f28,$f24
.L0f139710:
/*  f139710:	00000000 */ 	nop
/*  f139714:	45000002 */ 	bc1f	.L0f139720
/*  f139718:	00000000 */ 	nop
/*  f13971c:	4600e606 */ 	mov.s	$f24,$f28
.L0f139720:
/*  f139720:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f139724:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f139728:	4616d280 */ 	add.s	$f10,$f26,$f22
/*  f13972c:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f139730:	3c017f1b */ 	lui	$at,%hi(var7f1b5850)
/*  f139734:	4600d007 */ 	neg.s	$f0,$f26
/*  f139738:	460aa482 */ 	mul.s	$f18,$f20,$f10
/*  f13973c:	4600b280 */ 	add.s	$f10,$f22,$f0
/*  f139740:	00402025 */ 	or	$a0,$v0,$zero
/*  f139744:	4600b087 */ 	neg.s	$f2,$f22
/*  f139748:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f13974c:	460aa202 */ 	mul.s	$f8,$f20,$f10
/*  f139750:	4600810d */ 	trunc.w.s	$f4,$f16
/*  f139754:	440c2000 */ 	mfc1	$t4,$f4
/*  f139758:	00000000 */ 	nop
/*  f13975c:	a44c0000 */ 	sh	$t4,0x0($v0)
/*  f139760:	c7a600d8 */ 	lwc1	$f6,0xd8($sp)
/*  f139764:	46083480 */ 	add.s	$f18,$f6,$f8
/*  f139768:	4616d201 */ 	sub.s	$f8,$f26,$f22
/*  f13976c:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f139770:	4608a482 */ 	mul.s	$f18,$f20,$f8
/*  f139774:	4600b201 */ 	sub.s	$f8,$f22,$f0
/*  f139778:	440e8000 */ 	mfc1	$t6,$f16
/*  f13977c:	00000000 */ 	nop
/*  f139780:	a44e0002 */ 	sh	$t6,0x2($v0)
/*  f139784:	c7a400dc */ 	lwc1	$f4,0xdc($sp)
/*  f139788:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f13978c:	44185000 */ 	mfc1	$t8,$f10
/*  f139790:	00000000 */ 	nop
/*  f139794:	a4580004 */ 	sh	$t8,0x4($v0)
/*  f139798:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f13979c:	46123400 */ 	add.s	$f16,$f6,$f18
/*  f1397a0:	4608a182 */ 	mul.s	$f6,$f20,$f8
/*  f1397a4:	4600810d */ 	trunc.w.s	$f4,$f16
/*  f1397a8:	44082000 */ 	mfc1	$t0,$f4
/*  f1397ac:	00000000 */ 	nop
/*  f1397b0:	a448000c */ 	sh	$t0,0xc($v0)
/*  f1397b4:	c7aa00d8 */ 	lwc1	$f10,0xd8($sp)
/*  f1397b8:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f1397bc:	46160181 */ 	sub.s	$f6,$f0,$f22
/*  f1397c0:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f1397c4:	4606a482 */ 	mul.s	$f18,$f20,$f6
/*  f1397c8:	46001181 */ 	sub.s	$f6,$f2,$f0
/*  f1397cc:	440a8000 */ 	mfc1	$t2,$f16
/*  f1397d0:	00000000 */ 	nop
/*  f1397d4:	a44a000e */ 	sh	$t2,0xe($v0)
/*  f1397d8:	c7a400dc */ 	lwc1	$f4,0xdc($sp)
/*  f1397dc:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1397e0:	440c4000 */ 	mfc1	$t4,$f8
/*  f1397e4:	00000000 */ 	nop
/*  f1397e8:	a44c0010 */ 	sh	$t4,0x10($v0)
/*  f1397ec:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f1397f0:	46125400 */ 	add.s	$f16,$f10,$f18
/*  f1397f4:	4606a282 */ 	mul.s	$f10,$f20,$f6
/*  f1397f8:	4600810d */ 	trunc.w.s	$f4,$f16
/*  f1397fc:	440e2000 */ 	mfc1	$t6,$f4
/*  f139800:	00000000 */ 	nop
/*  f139804:	a44e0018 */ 	sh	$t6,0x18($v0)
/*  f139808:	c7a800d8 */ 	lwc1	$f8,0xd8($sp)
/*  f13980c:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f139810:	46160280 */ 	add.s	$f10,$f0,$f22
/*  f139814:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f139818:	460aa482 */ 	mul.s	$f18,$f20,$f10
/*  f13981c:	46001280 */ 	add.s	$f10,$f2,$f0
/*  f139820:	44188000 */ 	mfc1	$t8,$f16
/*  f139824:	00000000 */ 	nop
/*  f139828:	a458001a */ 	sh	$t8,0x1a($v0)
/*  f13982c:	c7a400dc */ 	lwc1	$f4,0xdc($sp)
/*  f139830:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f139834:	44083000 */ 	mfc1	$t0,$f6
/*  f139838:	00000000 */ 	nop
/*  f13983c:	a448001c */ 	sh	$t0,0x1c($v0)
/*  f139840:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f139844:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f139848:	460aa202 */ 	mul.s	$f8,$f20,$f10
/*  f13984c:	4600810d */ 	trunc.w.s	$f4,$f16
/*  f139850:	440a2000 */ 	mfc1	$t2,$f4
/*  f139854:	00000000 */ 	nop
/*  f139858:	a44a0024 */ 	sh	$t2,0x24($v0)
/*  f13985c:	c7a600d8 */ 	lwc1	$f6,0xd8($sp)
/*  f139860:	46083480 */ 	add.s	$f18,$f6,$f8
/*  f139864:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f139868:	440c8000 */ 	mfc1	$t4,$f16
/*  f13986c:	00000000 */ 	nop
/*  f139870:	a44c0026 */ 	sh	$t4,0x26($v0)
/*  f139874:	c7a400dc */ 	lwc1	$f4,0xdc($sp)
/*  f139878:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f13987c:	440e5000 */ 	mfc1	$t6,$f10
/*  f139880:	00000000 */ 	nop
/*  f139884:	a44e0028 */ 	sh	$t6,0x28($v0)
/*  f139888:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f13988c:	000fc140 */ 	sll	$t8,$t7,0x5
/*  f139890:	a4580008 */ 	sh	$t8,0x8($v0)
/*  f139894:	86190006 */ 	lh	$t9,0x6($s0)
/*  f139898:	00194140 */ 	sll	$t0,$t9,0x5
/*  f13989c:	a448000a */ 	sh	$t0,0xa($v0)
/*  f1398a0:	86090004 */ 	lh	$t1,0x4($s0)
/*  f1398a4:	00095140 */ 	sll	$t2,$t1,0x5
/*  f1398a8:	a44a0014 */ 	sh	$t2,0x14($v0)
/*  f1398ac:	860b000a */ 	lh	$t3,0xa($s0)
/*  f1398b0:	000b6140 */ 	sll	$t4,$t3,0x5
/*  f1398b4:	a44c0016 */ 	sh	$t4,0x16($v0)
/*  f1398b8:	860d0008 */ 	lh	$t5,0x8($s0)
/*  f1398bc:	000d7140 */ 	sll	$t6,$t5,0x5
/*  f1398c0:	a44e0020 */ 	sh	$t6,0x20($v0)
/*  f1398c4:	860f000a */ 	lh	$t7,0xa($s0)
/*  f1398c8:	000fc140 */ 	sll	$t8,$t7,0x5
/*  f1398cc:	a4580022 */ 	sh	$t8,0x22($v0)
/*  f1398d0:	86190008 */ 	lh	$t9,0x8($s0)
/*  f1398d4:	00194140 */ 	sll	$t0,$t9,0x5
/*  f1398d8:	a448002c */ 	sh	$t0,0x2c($v0)
/*  f1398dc:	86090006 */ 	lh	$t1,0x6($s0)
/*  f1398e0:	00095140 */ 	sll	$t2,$t1,0x5
/*  f1398e4:	a44a002e */ 	sh	$t2,0x2e($v0)
/*  f1398e8:	c4265850 */ 	lwc1	$f6,%lo(var7f1b5850)($at)
/*  f1398ec:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f1398f0:	3c0a0430 */ 	lui	$t2,0x430
/*  f1398f4:	4606c202 */ 	mul.s	$f8,$f24,$f6
/*  f1398f8:	01716021 */ 	addu	$t4,$t3,$s1
/*  f1398fc:	918d0020 */ 	lbu	$t5,0x20($t4)
/*  f139900:	354a0030 */ 	ori	$t2,$t2,0x30
/*  f139904:	4600448d */ 	trunc.w.s	$f18,$f8
/*  f139908:	440f9000 */ 	mfc1	$t7,$f18
/*  f13990c:	00000000 */ 	nop
/*  f139910:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f139914:	01b81021 */ 	addu	$v0,$t5,$t8
/*  f139918:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f13991c:	a0990007 */ 	sb	$t9,0x7($a0)
/*  f139920:	a0990013 */ 	sb	$t9,0x13($a0)
/*  f139924:	a099001f */ 	sb	$t9,0x1f($a0)
/*  f139928:	a099002b */ 	sb	$t9,0x2b($a0)
/*  f13992c:	8fb00118 */ 	lw	$s0,0x118($sp)
/*  f139930:	26090008 */ 	addiu	$t1,$s0,0x8
/*  f139934:	afa90118 */ 	sw	$t1,0x118($sp)
/*  f139938:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f13993c:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f139940:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f139944:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f139948:	3c0eb100 */ 	lui	$t6,0xb100
/*  f13994c:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f139950:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f139954:	afac0118 */ 	sw	$t4,0x118($sp)
/*  f139958:	240f3210 */ 	addiu	$t7,$zero,0x3210
/*  f13995c:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f139960:	ad6e0000 */ 	sw	$t6,0x0($t3)
.L0f139964:
/*  f139964:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f139968:	240101f4 */ 	addiu	$at,$zero,0x1f4
/*  f13996c:	1641feda */ 	bne	$s2,$at,.L0f1394d8
/*  f139970:	26310018 */ 	addiu	$s1,$s1,0x18
/*  f139974:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f139978:	24010002 */ 	addiu	$at,$zero,0x2
/*  f13997c:	56a1fed4 */ 	bnel	$s5,$at,.L0f1394d0
/*  f139980:	0000a025 */ 	or	$s4,$zero,$zero
/*  f139984:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f139988:	8fa20118 */ 	lw	$v0,0x118($sp)
/*  f13998c:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f139990:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f139994:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f139998:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f13999c:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f1399a0:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f1399a4:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f1399a8:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f1399ac:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f1399b0:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f1399b4:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f1399b8:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f1399bc:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f1399c0:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f1399c4:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f1399c8:	03e00008 */ 	jr	$ra
/*  f1399cc:	27bd0118 */ 	addiu	$sp,$sp,0x118
);

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

GLOBAL_ASM(
glabel func0f139d9c
.late_rodata
glabel var7f1b586c
.word 0x3eae147b
glabel var7f1b5870
.word 0x3eae147b
.text
/*  f139d9c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f139da0:	c7ac0058 */ 	lwc1	$f12,0x58($sp)
/*  f139da4:	3c014000 */ 	lui	$at,0x4000
/*  f139da8:	44812000 */ 	mtc1	$at,$f4
/*  f139dac:	460c6000 */ 	add.s	$f0,$f12,$f12
/*  f139db0:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f139db4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f139db8:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f139dbc:	46002401 */ 	sub.s	$f16,$f4,$f0
/*  f139dc0:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f139dc4:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f139dc8:	11c0000b */ 	beqz	$t6,.L0f139df8
/*  f139dcc:	46008386 */ 	mov.s	$f14,$f16
/*  f139dd0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f139dd4:	11c10015 */ 	beq	$t6,$at,.L0f139e2c
/*  f139dd8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f139ddc:	11c1001c */ 	beq	$t6,$at,.L0f139e50
/*  f139de0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f139de4:	11c1002b */ 	beq	$t6,$at,.L0f139e94
/*  f139de8:	3c013f80 */ 	lui	$at,0x3f80
/*  f139dec:	44811000 */ 	mtc1	$at,$f2
/*  f139df0:	10000037 */ 	b	.L0f139ed0
/*  f139df4:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
.L0f139df8:
/*  f139df8:	3c013f80 */ 	lui	$at,0x3f80
/*  f139dfc:	44811000 */ 	mtc1	$at,$f2
/*  f139e00:	3c014170 */ 	lui	$at,0x4170
/*  f139e04:	44813000 */ 	mtc1	$at,$f6
/*  f139e08:	3c014080 */ 	lui	$at,0x4080
/*  f139e0c:	44815000 */ 	mtc1	$at,$f10
/*  f139e10:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f139e14:	00000000 */ 	nop
/*  f139e18:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f139e1c:	46024480 */ 	add.s	$f18,$f8,$f2
/*  f139e20:	46022180 */ 	add.s	$f6,$f4,$f2
/*  f139e24:	1000002a */ 	b	.L0f139ed0
/*  f139e28:	e7a60038 */ 	swc1	$f6,0x38($sp)
.L0f139e2c:
/*  f139e2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f139e30:	44811000 */ 	mtc1	$at,$f2
/*  f139e34:	3c014296 */ 	lui	$at,0x4296
/*  f139e38:	44814000 */ 	mtc1	$at,$f8
/*  f139e3c:	46020480 */ 	add.s	$f18,$f0,$f2
/*  f139e40:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f139e44:	46025100 */ 	add.s	$f4,$f10,$f2
/*  f139e48:	10000021 */ 	b	.L0f139ed0
/*  f139e4c:	e7a40038 */ 	swc1	$f4,0x38($sp)
.L0f139e50:
/*  f139e50:	3c013f80 */ 	lui	$at,0x3f80
/*  f139e54:	44811000 */ 	mtc1	$at,$f2
/*  f139e58:	3c014170 */ 	lui	$at,0x4170
/*  f139e5c:	44813000 */ 	mtc1	$at,$f6
/*  f139e60:	3c017f1b */ 	lui	$at,%hi(var7f1b586c)
/*  f139e64:	c42a586c */ 	lwc1	$f10,%lo(var7f1b586c)($at)
/*  f139e68:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f139e6c:	460a6101 */ 	sub.s	$f4,$f12,$f10
/*  f139e70:	46041001 */ 	sub.s	$f0,$f2,$f4
/*  f139e74:	46024480 */ 	add.s	$f18,$f8,$f2
/*  f139e78:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f139e7c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f139e80:	00000000 */ 	nop
/*  f139e84:	45020013 */ 	bc1fl	.L0f139ed4
/*  f139e88:	4610103c */ 	c.lt.s	$f2,$f16
/*  f139e8c:	10000010 */ 	b	.L0f139ed0
/*  f139e90:	e7a20038 */ 	swc1	$f2,0x38($sp)
.L0f139e94:
/*  f139e94:	3c013f80 */ 	lui	$at,0x3f80
/*  f139e98:	44811000 */ 	mtc1	$at,$f2
/*  f139e9c:	3c01425c */ 	lui	$at,0x425c
/*  f139ea0:	44813000 */ 	mtc1	$at,$f6
/*  f139ea4:	3c017f1b */ 	lui	$at,%hi(var7f1b5870)
/*  f139ea8:	c4245870 */ 	lwc1	$f4,%lo(var7f1b5870)($at)
/*  f139eac:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f139eb0:	46046181 */ 	sub.s	$f6,$f12,$f4
/*  f139eb4:	46061481 */ 	sub.s	$f18,$f2,$f6
/*  f139eb8:	46024280 */ 	add.s	$f10,$f8,$f2
/*  f139ebc:	4612103c */ 	c.lt.s	$f2,$f18
/*  f139ec0:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*  f139ec4:	45020003 */ 	bc1fl	.L0f139ed4
/*  f139ec8:	4610103c */ 	c.lt.s	$f2,$f16
/*  f139ecc:	46001486 */ 	mov.s	$f18,$f2
.L0f139ed0:
/*  f139ed0:	4610103c */ 	c.lt.s	$f2,$f16
.L0f139ed4:
/*  f139ed4:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f139ed8:	45020003 */ 	bc1fl	.L0f139ee8
/*  f139edc:	448f4000 */ 	mtc1	$t7,$f8
/*  f139ee0:	46001386 */ 	mov.s	$f14,$f2
/*  f139ee4:	448f4000 */ 	mtc1	$t7,$f8
.L0f139ee8:
/*  f139ee8:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f139eec:	3c01437f */ 	lui	$at,0x437f
/*  f139ef0:	46804220 */ 	cvt.s.w	$f8,$f8
/*  f139ef4:	44813000 */ 	mtc1	$at,$f6
/*  f139ef8:	44985000 */ 	mtc1	$t8,$f10
/*  f139efc:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f139f00:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f139f04:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f139f08:	44054000 */ 	mfc1	$a1,$f8
/*  f139f0c:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f139f10:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f139f14:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f139f18:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f139f1c:	44065000 */ 	mfc1	$a2,$f10
/*  f139f20:	44079000 */ 	mfc1	$a3,$f18
/*  f139f24:	3c014f00 */ 	lui	$at,0x4f00
/*  f139f28:	444af800 */ 	cfc1	$t2,$31
/*  f139f2c:	44cbf800 */ 	ctc1	$t3,$31
/*  f139f30:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f139f34:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f139f38:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f139f3c:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f139f40:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f139f44:	444bf800 */ 	cfc1	$t3,$31
/*  f139f48:	00000000 */ 	nop
/*  f139f4c:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f139f50:	51600013 */ 	beqzl	$t3,.L0f139fa0
/*  f139f54:	440b5000 */ 	mfc1	$t3,$f10
/*  f139f58:	44815000 */ 	mtc1	$at,$f10
/*  f139f5c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f139f60:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f139f64:	44cbf800 */ 	ctc1	$t3,$31
/*  f139f68:	00000000 */ 	nop
/*  f139f6c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f139f70:	444bf800 */ 	cfc1	$t3,$31
/*  f139f74:	00000000 */ 	nop
/*  f139f78:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f139f7c:	15600005 */ 	bnez	$t3,.L0f139f94
/*  f139f80:	00000000 */ 	nop
/*  f139f84:	440b5000 */ 	mfc1	$t3,$f10
/*  f139f88:	3c018000 */ 	lui	$at,0x8000
/*  f139f8c:	10000007 */ 	b	.L0f139fac
/*  f139f90:	01615825 */ 	or	$t3,$t3,$at
.L0f139f94:
/*  f139f94:	10000005 */ 	b	.L0f139fac
/*  f139f98:	240bffff */ 	addiu	$t3,$zero,-1
/*  f139f9c:	440b5000 */ 	mfc1	$t3,$f10
.L0f139fa0:
/*  f139fa0:	00000000 */ 	nop
/*  f139fa4:	0560fffb */ 	bltz	$t3,.L0f139f94
/*  f139fa8:	00000000 */ 	nop
.L0f139fac:
/*  f139fac:	8fad005c */ 	lw	$t5,0x5c($sp)
/*  f139fb0:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f139fb4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f139fb8:	01616025 */ 	or	$t4,$t3,$at
/*  f139fbc:	44caf800 */ 	ctc1	$t2,$31
/*  f139fc0:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f139fc4:	afad0024 */ 	sw	$t5,0x24($sp)
/*  f139fc8:	0fc554b5 */ 	jal	func0f1552d4
/*  f139fcc:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f139fd0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f139fd4:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f139fd8:	03e00008 */ 	jr	$ra
/*  f139fdc:	00000000 */ 	nop
);

void creditsInitSlides(void)
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
	g_CreditsData->unk41a8[0] = 240;
	g_CreditsData->numthisslide = 1;
	g_CreditsData->slideage = 0;
}

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
#if VERSION >= VERSION_PAL_FINAL
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

				musicResumeAfterUnpause();
				musicStartPrimary(0);
			}
		} while (credit && credit->more && g_CreditsData->numthisslide < 4);

		for (i = 0; i < 8; i++) {
			g_CreditsData->unk41a8[i] = random() % 3 | random() % 3 << 2 | random() % 16 << 4;
		}

		creditsCreatePendingBgLayers(0xffffffff);
	}
}

u32 var8007f6d4 = 0x00000000;

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f13a3ec
.late_rodata
glabel var7f1b6b90pf
.word 0x7f13b0b4
glabel var7f1b6b94pf
.word 0x7f13b0b4
glabel var7f1b6b98pf
.word 0x7f13b0b4
glabel var7f1b6b9cpf
.word 0x7f13b0d0
glabel var7f1b6ba0pf
.word 0x7f13b0ec
glabel var7f1b6ba4pf
.word 0x7f13b0d0
glabel var7f1b6ba8pf
.word 0x7f13b0b4
glabel var7f1b6bacpf
.word 0x7f13b0b4
glabel var7f1b6bb0pf
.word 0x7f13b0d0
glabel var7f1b6bb4pf
.word 0x7f13b0b4
glabel var7f1b6bb8pf
.word 0x7f13b0d0
glabel var7f1b6bbcpf
.word 0x7f13b0d0
glabel var7f1b6bc0pf
.word 0x7f13b224
glabel var7f1b6bc4pf
.word 0x7f13b224
glabel var7f1b6bc8pf
.word 0x7f13b224
glabel var7f1b6bccpf
.word 0x7f13b224
glabel var7f1b6bd0pf
.word 0x7f13b224
glabel var7f1b6bd4pf
.word 0x7f13b224
glabel var7f1b6bd8pf
.word 0x7f13b25c
glabel var7f1b6bdcpf
.word 0x7f13b248
glabel var7f1b6be0pf
.word 0x7f13b248
glabel var7f1b6be4pf
.word 0x7f13b224
glabel var7f1b6be8pf
.word 0x7f13b25c
glabel var7f1b6becpf
.word 0x7f13b224
glabel var7f1b6bf0pf
.word 0x7f13b29c
glabel var7f1b6bf4pf
.word 0x7f13b2b8
glabel var7f1b6bf8pf
.word 0x7f13b2b8
glabel var7f1b6bfcpf
.word 0x7f13b2b8
glabel var7f1b6c00pf
.word 0x7f13b2b8
glabel var7f1b6c04pf
.word 0x7f13b2b8
glabel var7f1b6c08pf
.word 0x7f13b2f0
glabel var7f1b6c0cpf
.word 0x7f13b2dc
glabel var7f1b6c10pf
.word 0x7f13b2dc
glabel var7f1b6c14pf
.word 0x7f13b2b8
glabel var7f1b6c18pf
.word 0x7f13b2dc
glabel var7f1b6c1cpf
.word 0x7f13b2b8
glabel var7f1b6c20pf
.word 0x3e116873
glabel var7f1b6c24pf
.word 0x3e116873
glabel var7f1b6c28pf
.word 0x7f13b80c
glabel var7f1b6c2cpf
.word 0x7f13b810
glabel var7f1b6c30pf
.word 0x7f13b810
glabel var7f1b6c34pf
.word 0x7f13b810
glabel var7f1b6c38pf
.word 0x7f13b810
glabel var7f1b6c3cpf
.word 0x7f13b7fc
glabel var7f1b6c40pf
.word 0x7f13b804
glabel var7f1b6c44pf
.word 0x7f13b804
glabel var7f1b6c48pf
.word 0x7f13b810
glabel var7f1b6c4cpf
.word 0x7f13b804
glabel var7f1b6c50pf
.word 0x3d4ccccd
.text
/*  f13af6c:	27bdfe28 */ 	addiu	$sp,$sp,-472
/*  f13af70:	3c0f800a */ 	lui	$t7,0x800a
/*  f13af74:	8def4710 */ 	lw	$t7,0x4710($t7)
/*  f13af78:	240effff */ 	li	$t6,-1
/*  f13af7c:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f13af80:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f13af84:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f13af88:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f13af8c:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f13af90:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f13af94:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f13af98:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f13af9c:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f13afa0:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f13afa4:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f13afa8:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f13afac:	afa401d8 */ 	sw	$a0,0x1d8($sp)
/*  f13afb0:	afae00d8 */ 	sw	$t6,0xd8($sp)
/*  f13afb4:	91f8419c */ 	lbu	$t8,0x419c($t7)
/*  f13afb8:	0000f025 */ 	move	$s8,$zero
/*  f13afbc:	0000a825 */ 	move	$s5,$zero
/*  f13afc0:	1b0000dd */ 	blez	$t8,.PF0f13b338
/*  f13afc4:	3c014120 */ 	lui	$at,0x4120
/*  f13afc8:	4481a000 */ 	mtc1	$at,$f20
/*  f13afcc:	27b601c4 */ 	addiu	$s6,$sp,0x1c4
.PF0f13afd0:
/*  f13afd0:	0fc4eb19 */ 	jal	creditGetByRow
/*  f13afd4:	02a02025 */ 	move	$a0,$s5
/*  f13afd8:	1440000d */ 	bnez	$v0,.PF0f13b010
/*  f13afdc:	aec20000 */ 	sw	$v0,0x0($s6)
/*  f13afe0:	3c03800a */ 	lui	$v1,0x800a
/*  f13afe4:	24634710 */ 	addiu	$v1,$v1,0x4710
/*  f13afe8:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f13afec:	240a0001 */ 	li	$t2,0x1
/*  f13aff0:	44802000 */ 	mtc1	$zero,$f4
/*  f13aff4:	af204198 */ 	sw	$zero,0x4198($t9)
/*  f13aff8:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f13affc:	a16a419c */ 	sb	$t2,0x419c($t3)
/*  f13b000:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f13b004:	e58441a0 */ 	swc1	$f4,0x41a0($t4)
/*  f13b008:	10000249 */ 	b	.PF0f13b930
/*  f13b00c:	8fa201d8 */ 	lw	$v0,0x1d8($sp)
.PF0f13b010:
/*  f13b010:	02a01025 */ 	move	$v0,$s5
/*  f13b014:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f13b018:	8ecd0000 */ 	lw	$t5,0x0($s6)
/*  f13b01c:	27af0184 */ 	addiu	$t7,$sp,0x184
/*  f13b020:	27b80164 */ 	addiu	$t8,$sp,0x164
/*  f13b024:	27aa0100 */ 	addiu	$t2,$sp,0x100
/*  f13b028:	95a40002 */ 	lhu	$a0,0x2($t5)
/*  f13b02c:	27ad00e0 */ 	addiu	$t5,$sp,0xe0
/*  f13b030:	01ca9821 */ 	addu	$s3,$t6,$t2
/*  f13b034:	01d88821 */ 	addu	$s1,$t6,$t8
/*  f13b038:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f13b03c:	27b90140 */ 	addiu	$t9,$sp,0x140
/*  f13b040:	27ab0120 */ 	addiu	$t3,$sp,0x120
/*  f13b044:	01cb6021 */ 	addu	$t4,$t6,$t3
/*  f13b048:	01d99021 */ 	addu	$s2,$t6,$t9
/*  f13b04c:	01cdb821 */ 	addu	$s7,$t6,$t5
/*  f13b050:	01c01025 */ 	move	$v0,$t6
/*  f13b054:	26ee0004 */ 	addiu	$t6,$s7,0x4
/*  f13b058:	266f0004 */ 	addiu	$t7,$s3,0x4
/*  f13b05c:	27b801a4 */ 	addiu	$t8,$sp,0x1a4
/*  f13b060:	0058a021 */ 	addu	$s4,$v0,$t8
/*  f13b064:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f13b068:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f13b06c:	0fc5bdaa */ 	jal	langGet
/*  f13b070:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f13b074:	8ed90000 */ 	lw	$t9,0x0($s6)
/*  f13b078:	ae820000 */ 	sw	$v0,0x0($s4)
/*  f13b07c:	0fc5bdaa */ 	jal	langGet
/*  f13b080:	97240004 */ 	lhu	$a0,0x4($t9)
/*  f13b084:	8ec30000 */ 	lw	$v1,0x0($s6)
/*  f13b088:	ae820004 */ 	sw	$v0,0x4($s4)
/*  f13b08c:	906a0001 */ 	lbu	$t2,0x1($v1)
/*  f13b090:	254bffff */ 	addiu	$t3,$t2,-1
/*  f13b094:	2d61000c */ 	sltiu	$at,$t3,0xc
/*  f13b098:	10200014 */ 	beqz	$at,.PF0f13b0ec
/*  f13b09c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f13b0a0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13b0a4:	002b0821 */ 	addu	$at,$at,$t3
/*  f13b0a8:	8c2b6b90 */ 	lw	$t3,0x6b90($at)
/*  f13b0ac:	01600008 */ 	jr	$t3
/*  f13b0b0:	00000000 */ 	nop
/*  f13b0b4:	3c0c8008 */ 	lui	$t4,0x8008
/*  f13b0b8:	8d8c0080 */ 	lw	$t4,0x80($t4)
/*  f13b0bc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f13b0c0:	ae0c0000 */ 	sw	$t4,0x0($s0)
/*  f13b0c4:	8dad007c */ 	lw	$t5,0x7c($t5)
/*  f13b0c8:	1000000e */ 	b	.PF0f13b104
/*  f13b0cc:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f13b0d0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f13b0d4:	8dce0078 */ 	lw	$t6,0x78($t6)
/*  f13b0d8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f13b0dc:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f13b0e0:	8def0074 */ 	lw	$t7,0x74($t7)
/*  f13b0e4:	10000007 */ 	b	.PF0f13b104
/*  f13b0e8:	ae2f0000 */ 	sw	$t7,0x0($s1)
.PF0f13b0ec:
/*  f13b0ec:	3c188008 */ 	lui	$t8,0x8008
/*  f13b0f0:	8f180070 */ 	lw	$t8,0x70($t8)
/*  f13b0f4:	3c198008 */ 	lui	$t9,0x8008
/*  f13b0f8:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f13b0fc:	8f39006c */ 	lw	$t9,0x6c($t9)
/*  f13b100:	ae390000 */ 	sw	$t9,0x0($s1)
.PF0f13b104:
/*  f13b104:	90620001 */ 	lbu	$v0,0x1($v1)
/*  f13b108:	24010001 */ 	li	$at,0x1
/*  f13b10c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f13b110:	10410013 */ 	beq	$v0,$at,.PF0f13b160
/*  f13b114:	24010006 */ 	li	$at,0x6
/*  f13b118:	10410009 */ 	beq	$v0,$at,.PF0f13b140
/*  f13b11c:	3c0a8008 */ 	lui	$t2,0x8008
/*  f13b120:	2401000a */ 	li	$at,0xa
/*  f13b124:	1041000e */ 	beq	$v0,$at,.PF0f13b160
/*  f13b128:	00000000 */ 	nop
/*  f13b12c:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f13b130:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f13b134:	ae070004 */ 	sw	$a3,0x4($s0)
/*  f13b138:	10000010 */ 	b	.PF0f13b17c
/*  f13b13c:	ae220004 */ 	sw	$v0,0x4($s1)
.PF0f13b140:
/*  f13b140:	8d4a0070 */ 	lw	$t2,0x70($t2)
/*  f13b144:	3c0b8008 */ 	lui	$t3,0x8008
/*  f13b148:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f13b14c:	ae0a0004 */ 	sw	$t2,0x4($s0)
/*  f13b150:	8d6b006c */ 	lw	$t3,0x6c($t3)
/*  f13b154:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f13b158:	10000008 */ 	b	.PF0f13b17c
/*  f13b15c:	ae2b0004 */ 	sw	$t3,0x4($s1)
.PF0f13b160:
/*  f13b160:	8d8c0078 */ 	lw	$t4,0x78($t4)
/*  f13b164:	3c0d8008 */ 	lui	$t5,0x8008
/*  f13b168:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f13b16c:	ae0c0004 */ 	sw	$t4,0x4($s0)
/*  f13b170:	8dad0074 */ 	lw	$t5,0x74($t5)
/*  f13b174:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f13b178:	ae2d0004 */ 	sw	$t5,0x4($s1)
.PF0f13b17c:
/*  f13b17c:	8fae00d8 */ 	lw	$t6,0xd8($sp)
/*  f13b180:	24010002 */ 	li	$at,0x2
/*  f13b184:	11c10005 */ 	beq	$t6,$at,.PF0f13b19c
/*  f13b188:	24010005 */ 	li	$at,0x5
/*  f13b18c:	11c10003 */ 	beq	$t6,$at,.PF0f13b19c
/*  f13b190:	24010007 */ 	li	$at,0x7
/*  f13b194:	55c10009 */ 	bnel	$t6,$at,.PF0f13b1bc
/*  f13b198:	90780001 */ 	lbu	$t8,0x1($v1)
.PF0f13b19c:
/*  f13b19c:	449e3000 */ 	mtc1	$s8,$f6
/*  f13b1a0:	00000000 */ 	nop
/*  f13b1a4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f13b1a8:	46144280 */ 	add.s	$f10,$f8,$f20
/*  f13b1ac:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f13b1b0:	441e2000 */ 	mfc1	$s8,$f4
/*  f13b1b4:	00000000 */ 	nop
/*  f13b1b8:	90780001 */ 	lbu	$t8,0x1($v1)
.PF0f13b1bc:
/*  f13b1bc:	02e02025 */ 	move	$a0,$s7
/*  f13b1c0:	02602825 */ 	move	$a1,$s3
/*  f13b1c4:	afb800d8 */ 	sw	$t8,0xd8($sp)
/*  f13b1c8:	8e860000 */ 	lw	$a2,0x0($s4)
/*  f13b1cc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13b1d0:	0fc5609a */ 	jal	textMeasure
/*  f13b1d4:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f13b1d8:	8e390004 */ 	lw	$t9,0x4($s1)
/*  f13b1dc:	8e860004 */ 	lw	$a2,0x4($s4)
/*  f13b1e0:	8e070004 */ 	lw	$a3,0x4($s0)
/*  f13b1e4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13b1e8:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f13b1ec:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f13b1f0:	0fc5609a */ 	jal	textMeasure
/*  f13b1f4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f13b1f8:	8ec30000 */ 	lw	$v1,0x0($s6)
/*  f13b1fc:	906a0001 */ 	lbu	$t2,0x1($v1)
/*  f13b200:	254bffff */ 	addiu	$t3,$t2,-1
/*  f13b204:	2d61000c */ 	sltiu	$at,$t3,0xc
/*  f13b208:	10200014 */ 	beqz	$at,.PF0f13b25c
/*  f13b20c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f13b210:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13b214:	002b0821 */ 	addu	$at,$at,$t3
/*  f13b218:	8c2b6bc0 */ 	lw	$t3,0x6bc0($at)
/*  f13b21c:	01600008 */ 	jr	$t3
/*  f13b220:	00000000 */ 	nop
/*  f13b224:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f13b228:	240e00a0 */ 	li	$t6,0xa0
/*  f13b22c:	05810003 */ 	bgez	$t4,.PF0f13b23c
/*  f13b230:	000c6843 */ 	sra	$t5,$t4,0x1
/*  f13b234:	25810001 */ 	addiu	$at,$t4,0x1
/*  f13b238:	00016843 */ 	sra	$t5,$at,0x1
.PF0f13b23c:
/*  f13b23c:	01cd7823 */ 	subu	$t7,$t6,$t5
/*  f13b240:	10000008 */ 	b	.PF0f13b264
/*  f13b244:	ae4f0000 */ 	sw	$t7,0x0($s2)
/*  f13b248:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f13b24c:	2419010e */ 	li	$t9,0x10e
/*  f13b250:	03385023 */ 	subu	$t2,$t9,$t8
/*  f13b254:	10000003 */ 	b	.PF0f13b264
/*  f13b258:	ae4a0000 */ 	sw	$t2,0x0($s2)
.PF0f13b25c:
/*  f13b25c:	240b0032 */ 	li	$t3,0x32
/*  f13b260:	ae4b0000 */ 	sw	$t3,0x0($s2)
.PF0f13b264:
/*  f13b264:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f13b268:	8eec0000 */ 	lw	$t4,0x0($s7)
/*  f13b26c:	ac5e0000 */ 	sw	$s8,0x0($v0)
/*  f13b270:	906e0001 */ 	lbu	$t6,0x1($v1)
/*  f13b274:	03ccf021 */ 	addu	$s8,$s8,$t4
/*  f13b278:	25cdffff */ 	addiu	$t5,$t6,-1
/*  f13b27c:	2da1000c */ 	sltiu	$at,$t5,0xc
/*  f13b280:	1020001b */ 	beqz	$at,.PF0f13b2f0
/*  f13b284:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f13b288:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13b28c:	002d0821 */ 	addu	$at,$at,$t5
/*  f13b290:	8c2d6bf0 */ 	lw	$t5,0x6bf0($at)
/*  f13b294:	01a00008 */ 	jr	$t5
/*  f13b298:	00000000 */ 	nop
/*  f13b29c:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f13b2a0:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f13b2a4:	8e6a0004 */ 	lw	$t2,0x4($s3)
/*  f13b2a8:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f13b2ac:	030a5823 */ 	subu	$t3,$t8,$t2
/*  f13b2b0:	10000011 */ 	b	.PF0f13b2f8
/*  f13b2b4:	ae4b0004 */ 	sw	$t3,0x4($s2)
/*  f13b2b8:	8e6c0004 */ 	lw	$t4,0x4($s3)
/*  f13b2bc:	240d00a0 */ 	li	$t5,0xa0
/*  f13b2c0:	05810003 */ 	bgez	$t4,.PF0f13b2d0
/*  f13b2c4:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f13b2c8:	25810001 */ 	addiu	$at,$t4,0x1
/*  f13b2cc:	00017043 */ 	sra	$t6,$at,0x1
.PF0f13b2d0:
/*  f13b2d0:	01ae7823 */ 	subu	$t7,$t5,$t6
/*  f13b2d4:	10000008 */ 	b	.PF0f13b2f8
/*  f13b2d8:	ae4f0004 */ 	sw	$t7,0x4($s2)
/*  f13b2dc:	8e790004 */ 	lw	$t9,0x4($s3)
/*  f13b2e0:	2418010e */ 	li	$t8,0x10e
/*  f13b2e4:	03195023 */ 	subu	$t2,$t8,$t9
/*  f13b2e8:	10000003 */ 	b	.PF0f13b2f8
/*  f13b2ec:	ae4a0004 */ 	sw	$t2,0x4($s2)
.PF0f13b2f0:
/*  f13b2f0:	240b0032 */ 	li	$t3,0x32
/*  f13b2f4:	ae4b0004 */ 	sw	$t3,0x4($s2)
.PF0f13b2f8:
/*  f13b2f8:	ac5e0004 */ 	sw	$s8,0x4($v0)
/*  f13b2fc:	906d0001 */ 	lbu	$t5,0x1($v1)
/*  f13b300:	8eec0004 */ 	lw	$t4,0x4($s7)
/*  f13b304:	2401000c */ 	li	$at,0xc
/*  f13b308:	15a10002 */ 	bne	$t5,$at,.PF0f13b314
/*  f13b30c:	03ccf021 */ 	addu	$s8,$s8,$t4
/*  f13b310:	27de000a */ 	addiu	$s8,$s8,0xa
.PF0f13b314:
/*  f13b314:	3c0e800a */ 	lui	$t6,0x800a
/*  f13b318:	8dce4710 */ 	lw	$t6,0x4710($t6)
/*  f13b31c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f13b320:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f13b324:	91cf419c */ 	lbu	$t7,0x419c($t6)
/*  f13b328:	02af082a */ 	slt	$at,$s5,$t7
/*  f13b32c:	1420ff28 */ 	bnez	$at,.PF0f13afd0
/*  f13b330:	00000000 */ 	nop
/*  f13b334:	0000a825 */ 	move	$s5,$zero
.PF0f13b338:
/*  f13b338:	0fc550cf */ 	jal	func0f153628
/*  f13b33c:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f13b340:	3c04800a */ 	lui	$a0,0x800a
/*  f13b344:	8c844710 */ 	lw	$a0,0x4710($a0)
/*  f13b348:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f13b34c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f13b350:	9086419c */ 	lbu	$a2,0x419c($a0)
/*  f13b354:	0006c040 */ 	sll	$t8,$a2,0x1
/*  f13b358:	1b000092 */ 	blez	$t8,.PF0f13b5a4
/*  f13b35c:	03003025 */ 	move	$a2,$t8
/*  f13b360:	4481b000 */ 	mtc1	$at,$f22
/*  f13b364:	3c013f80 */ 	lui	$at,0x3f80
/*  f13b368:	4481a000 */ 	mtc1	$at,$f20
/*  f13b36c:	44809000 */ 	mtc1	$zero,$f18
/*  f13b370:	24050002 */ 	li	$a1,0x2
/*  f13b374:	44953000 */ 	mtc1	$s5,$f6
.PF0f13b378:
/*  f13b378:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13b37c:	c42a6c20 */ 	lwc1	$f10,0x6c20($at)
/*  f13b380:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f13b384:	c48641a0 */ 	lwc1	$f6,0x41a0($a0)
/*  f13b388:	46009306 */ 	mov.s	$f12,$f18
/*  f13b38c:	4600a386 */ 	mov.s	$f14,$f20
/*  f13b390:	4600a406 */ 	mov.s	$f16,$f20
/*  f13b394:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f13b398:	46043001 */ 	sub.s	$f0,$f6,$f4
/*  f13b39c:	4600903c */ 	c.lt.s	$f18,$f0
/*  f13b3a0:	00000000 */ 	nop
/*  f13b3a4:	4503000f */ 	bc1tl	.PF0f13b3e4
/*  f13b3a8:	c48241a4 */ 	lwc1	$f2,0x41a4($a0)
/*  f13b3ac:	06a10003 */ 	bgez	$s5,.PF0f13b3bc
/*  f13b3b0:	0015c843 */ 	sra	$t9,$s5,0x1
/*  f13b3b4:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f13b3b8:	0001c843 */ 	sra	$t9,$at,0x1
.PF0f13b3bc:
/*  f13b3bc:	00195080 */ 	sll	$t2,$t9,0x2
/*  f13b3c0:	03aa5821 */ 	addu	$t3,$sp,$t2
/*  f13b3c4:	8d6b01c4 */ 	lw	$t3,0x1c4($t3)
/*  f13b3c8:	956c0000 */ 	lhu	$t4,0x0($t3)
/*  f13b3cc:	000c6c40 */ 	sll	$t5,$t4,0x11
/*  f13b3d0:	000d7782 */ 	srl	$t6,$t5,0x1e
/*  f13b3d4:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f13b3d8:	54af006e */ 	bnel	$a1,$t7,.PF0f13b594
/*  f13b3dc:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f13b3e0:	c48241a4 */ 	lwc1	$f2,0x41a4($a0)
.PF0f13b3e4:
/*  f13b3e4:	06a10003 */ 	bgez	$s5,.PF0f13b3f4
/*  f13b3e8:	0015c043 */ 	sra	$t8,$s5,0x1
/*  f13b3ec:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f13b3f0:	0001c043 */ 	sra	$t8,$at,0x1
.PF0f13b3f4:
/*  f13b3f4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f13b3f8:	03b95021 */ 	addu	$t2,$sp,$t9
/*  f13b3fc:	46141200 */ 	add.s	$f8,$f2,$f20
/*  f13b400:	8d4a01c4 */ 	lw	$t2,0x1c4($t2)
/*  f13b404:	24010001 */ 	li	$at,0x1
/*  f13b408:	00151080 */ 	sll	$v0,$s5,0x2
/*  f13b40c:	95430000 */ 	lhu	$v1,0x0($t2)
/*  f13b410:	4608003c */ 	c.lt.s	$f0,$f8
/*  f13b414:	240f0078 */ 	li	$t7,0x78
/*  f13b418:	00035c40 */ 	sll	$t3,$v1,0x11
/*  f13b41c:	000b6782 */ 	srl	$t4,$t3,0x1e
/*  f13b420:	45010004 */ 	bc1t	.PF0f13b434
/*  f13b424:	01801825 */ 	move	$v1,$t4
/*  f13b428:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f13b42c:	55a10059 */ 	bnel	$t5,$at,.PF0f13b594
/*  f13b430:	26b50001 */ 	addiu	$s5,$s5,0x1
.PF0f13b434:
/*  f13b434:	4614003c */ 	c.lt.s	$f0,$f20
/*  f13b438:	27b80140 */ 	addiu	$t8,$sp,0x140
/*  f13b43c:	27b90120 */ 	addiu	$t9,$sp,0x120
/*  f13b440:	27aa01a4 */ 	addiu	$t2,$sp,0x1a4
/*  f13b444:	27ab0184 */ 	addiu	$t3,$sp,0x184
/*  f13b448:	27ac0164 */ 	addiu	$t4,$sp,0x164
/*  f13b44c:	00002025 */ 	move	$a0,$zero
/*  f13b450:	07c10003 */ 	bgez	$s8,.PF0f13b460
/*  f13b454:	001e7043 */ 	sra	$t6,$s8,0x1
/*  f13b458:	27c10001 */ 	addiu	$at,$s8,0x1
/*  f13b45c:	00017043 */ 	sra	$t6,$at,0x1
.PF0f13b460:
/*  f13b460:	01ee9823 */ 	subu	$s3,$t7,$t6
/*  f13b464:	004c4821 */ 	addu	$t1,$v0,$t4
/*  f13b468:	004b4021 */ 	addu	$t0,$v0,$t3
/*  f13b46c:	004ab821 */ 	addu	$s7,$v0,$t2
/*  f13b470:	0059b021 */ 	addu	$s6,$v0,$t9
/*  f13b474:	45000006 */ 	bc1f	.PF0f13b490
/*  f13b478:	0058a021 */ 	addu	$s4,$v0,$t8
/*  f13b47c:	306d0002 */ 	andi	$t5,$v1,0x2
/*  f13b480:	14ad001b */ 	bne	$a1,$t5,.PF0f13b4f0
/*  f13b484:	00000000 */ 	nop
/*  f13b488:	10000019 */ 	b	.PF0f13b4f0
/*  f13b48c:	24040001 */ 	li	$a0,0x1
.PF0f13b490:
/*  f13b490:	4600103c */ 	c.lt.s	$f2,$f0
/*  f13b494:	306f0001 */ 	andi	$t7,$v1,0x1
/*  f13b498:	24010001 */ 	li	$at,0x1
/*  f13b49c:	306e0002 */ 	andi	$t6,$v1,0x2
/*  f13b4a0:	45000009 */ 	bc1f	.PF0f13b4c8
/*  f13b4a4:	00000000 */ 	nop
/*  f13b4a8:	55e10004 */ 	bnel	$t7,$at,.PF0f13b4bc
/*  f13b4ac:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f13b4b0:	1000000f */ 	b	.PF0f13b4f0
/*  f13b4b4:	24040001 */ 	li	$a0,0x1
/*  f13b4b8:	46020281 */ 	sub.s	$f10,$f0,$f2
.PF0f13b4bc:
/*  f13b4bc:	46145182 */ 	mul.s	$f6,$f10,$f20
/*  f13b4c0:	1000000b */ 	b	.PF0f13b4f0
/*  f13b4c4:	4606a301 */ 	sub.s	$f12,$f20,$f6
.PF0f13b4c8:
/*  f13b4c8:	54ae0004 */ 	bnel	$a1,$t6,.PF0f13b4dc
/*  f13b4cc:	46140101 */ 	sub.s	$f4,$f0,$f20
/*  f13b4d0:	10000007 */ 	b	.PF0f13b4f0
/*  f13b4d4:	24040001 */ 	li	$a0,0x1
/*  f13b4d8:	46140101 */ 	sub.s	$f4,$f0,$f20
.PF0f13b4dc:
/*  f13b4dc:	4600a306 */ 	mov.s	$f12,$f20
/*  f13b4e0:	46141201 */ 	sub.s	$f8,$f2,$f20
/*  f13b4e4:	46082383 */ 	div.s	$f14,$f4,$f8
/*  f13b4e8:	46167402 */ 	mul.s	$f16,$f14,$f22
/*  f13b4ec:	00000000 */ 	nop
.PF0f13b4f0:
/*  f13b4f0:	50800005 */ 	beqzl	$a0,.PF0f13b508
/*  f13b4f4:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f13b4f8:	4600a306 */ 	mov.s	$f12,$f20
/*  f13b4fc:	4600a386 */ 	mov.s	$f14,$f20
/*  f13b500:	4600a406 */ 	mov.s	$f16,$f20
/*  f13b504:	460ca03c */ 	c.lt.s	$f20,$f12
.PF0f13b508:
/*  f13b508:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f13b50c:	45020003 */ 	bc1fl	.PF0f13b51c
/*  f13b510:	4610a03c */ 	c.lt.s	$f20,$f16
/*  f13b514:	4600a306 */ 	mov.s	$f12,$f20
/*  f13b518:	4610a03c */ 	c.lt.s	$f20,$f16
.PF0f13b51c:
/*  f13b51c:	00000000 */ 	nop
/*  f13b520:	45020003 */ 	bc1fl	.PF0f13b530
/*  f13b524:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f13b528:	4600a406 */ 	mov.s	$f16,$f20
/*  f13b52c:	460ea03c */ 	c.lt.s	$f20,$f14
.PF0f13b530:
/*  f13b530:	00000000 */ 	nop
/*  f13b534:	45020003 */ 	bc1fl	.PF0f13b544
/*  f13b538:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f13b53c:	4600a386 */ 	mov.s	$f14,$f20
/*  f13b540:	8d190000 */ 	lw	$t9,0x0($t0)
.PF0f13b544:
/*  f13b544:	8ed80000 */ 	lw	$t8,0x0($s6)
/*  f13b548:	8e850000 */ 	lw	$a1,0x0($s4)
/*  f13b54c:	8ee70000 */ 	lw	$a3,0x0($s7)
/*  f13b550:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f13b554:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f13b558:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*  f13b55c:	e7ae001c */ 	swc1	$f14,0x1c($sp)
/*  f13b560:	e7ac0018 */ 	swc1	$f12,0x18($sp)
/*  f13b564:	03133021 */ 	addu	$a2,$t8,$s3
/*  f13b568:	0fc4e954 */ 	jal	func0f1399d0
/*  f13b56c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f13b570:	3c04800a */ 	lui	$a0,0x800a
/*  f13b574:	8c844710 */ 	lw	$a0,0x4710($a0)
/*  f13b578:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f13b57c:	44809000 */ 	mtc1	$zero,$f18
/*  f13b580:	9086419c */ 	lbu	$a2,0x419c($a0)
/*  f13b584:	24050002 */ 	li	$a1,0x2
/*  f13b588:	00065840 */ 	sll	$t3,$a2,0x1
/*  f13b58c:	01603025 */ 	move	$a2,$t3
/*  f13b590:	26b50001 */ 	addiu	$s5,$s5,0x1
.PF0f13b594:
/*  f13b594:	02a6082a */ 	slt	$at,$s5,$a2
/*  f13b598:	5420ff77 */ 	bnezl	$at,.PF0f13b378
/*  f13b59c:	44953000 */ 	mtc1	$s5,$f6
/*  f13b5a0:	0000a825 */ 	move	$s5,$zero
.PF0f13b5a4:
/*  f13b5a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f13b5a8:	4481a000 */ 	mtc1	$at,$f20
/*  f13b5ac:	18c000de */ 	blez	$a2,.PF0f13b928
/*  f13b5b0:	24050002 */ 	li	$a1,0x2
.PF0f13b5b4:
/*  f13b5b4:	44955000 */ 	mtc1	$s5,$f10
/*  f13b5b8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13b5bc:	c4246c24 */ 	lwc1	$f4,0x6c24($at)
/*  f13b5c0:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f13b5c4:	c48a41a0 */ 	lwc1	$f10,0x41a0($a0)
/*  f13b5c8:	4480b000 */ 	mtc1	$zero,$f22
/*  f13b5cc:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f13b5d0:	44803000 */ 	mtc1	$zero,$f6
/*  f13b5d4:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f13b5d8:	4600303c */ 	c.lt.s	$f6,$f0
/*  f13b5dc:	00000000 */ 	nop
/*  f13b5e0:	4503000f */ 	bc1tl	.PF0f13b620
/*  f13b5e4:	c48241a4 */ 	lwc1	$f2,0x41a4($a0)
/*  f13b5e8:	06a10003 */ 	bgez	$s5,.PF0f13b5f8
/*  f13b5ec:	00156043 */ 	sra	$t4,$s5,0x1
/*  f13b5f0:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f13b5f4:	00016043 */ 	sra	$t4,$at,0x1
.PF0f13b5f8:
/*  f13b5f8:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f13b5fc:	03ad7821 */ 	addu	$t7,$sp,$t5
/*  f13b600:	8def01c4 */ 	lw	$t7,0x1c4($t7)
/*  f13b604:	95ee0000 */ 	lhu	$t6,0x0($t7)
/*  f13b608:	000ec440 */ 	sll	$t8,$t6,0x11
/*  f13b60c:	0018cf82 */ 	srl	$t9,$t8,0x1e
/*  f13b610:	332a0002 */ 	andi	$t2,$t9,0x2
/*  f13b614:	54aa00c1 */ 	bnel	$a1,$t2,.PF0f13b91c
/*  f13b618:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f13b61c:	c48241a4 */ 	lwc1	$f2,0x41a4($a0)
.PF0f13b620:
/*  f13b620:	06a10003 */ 	bgez	$s5,.PF0f13b630
/*  f13b624:	00155843 */ 	sra	$t3,$s5,0x1
/*  f13b628:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f13b62c:	00015843 */ 	sra	$t3,$at,0x1
.PF0f13b630:
/*  f13b630:	46141100 */ 	add.s	$f4,$f2,$f20
/*  f13b634:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f13b638:	03ac2821 */ 	addu	$a1,$sp,$t4
/*  f13b63c:	8ca501c4 */ 	lw	$a1,0x1c4($a1)
/*  f13b640:	4604003c */ 	c.lt.s	$f0,$f4
/*  f13b644:	00003825 */ 	move	$a3,$zero
/*  f13b648:	00009025 */ 	move	$s2,$zero
/*  f13b64c:	0095c821 */ 	addu	$t9,$a0,$s5
/*  f13b650:	45010008 */ 	bc1t	.PF0f13b674
/*  f13b654:	00151080 */ 	sll	$v0,$s5,0x2
/*  f13b658:	94ad0000 */ 	lhu	$t5,0x0($a1)
/*  f13b65c:	24010001 */ 	li	$at,0x1
/*  f13b660:	000d7c40 */ 	sll	$t7,$t5,0x11
/*  f13b664:	000f7782 */ 	srl	$t6,$t7,0x1e
/*  f13b668:	31d80001 */ 	andi	$t8,$t6,0x1
/*  f13b66c:	570100ab */ 	bnel	$t8,$at,.PF0f13b91c
/*  f13b670:	26b50001 */ 	addiu	$s5,$s5,0x1
.PF0f13b674:
/*  f13b674:	932341a8 */ 	lbu	$v1,0x41a8($t9)
/*  f13b678:	240c0078 */ 	li	$t4,0x78
/*  f13b67c:	27ad0140 */ 	addiu	$t5,$sp,0x140
/*  f13b680:	00038883 */ 	sra	$s1,$v1,0x2
/*  f13b684:	322a0003 */ 	andi	$t2,$s1,0x3
/*  f13b688:	01408825 */ 	move	$s1,$t2
/*  f13b68c:	27aa0164 */ 	addiu	$t2,$sp,0x164
/*  f13b690:	004da021 */ 	addu	$s4,$v0,$t5
/*  f13b694:	27b80184 */ 	addiu	$t8,$sp,0x184
/*  f13b698:	8c864198 */ 	lw	$a2,0x4198($a0)
/*  f13b69c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f13b6a0:	27af0120 */ 	addiu	$t7,$sp,0x120
/*  f13b6a4:	27ae01a4 */ 	addiu	$t6,$sp,0x1a4
/*  f13b6a8:	004eb821 */ 	addu	$s7,$v0,$t6
/*  f13b6ac:	004fb021 */ 	addu	$s6,$v0,$t7
/*  f13b6b0:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f13b6b4:	30700003 */ 	andi	$s0,$v1,0x3
/*  f13b6b8:	07c10003 */ 	bgez	$s8,.PF0f13b6c8
/*  f13b6bc:	001e5843 */ 	sra	$t3,$s8,0x1
/*  f13b6c0:	27c10001 */ 	addiu	$at,$s8,0x1
/*  f13b6c4:	00015843 */ 	sra	$t3,$at,0x1
.PF0f13b6c8:
/*  f13b6c8:	018b9823 */ 	subu	$s3,$t4,$t3
/*  f13b6cc:	00035903 */ 	sra	$t3,$v1,0x4
/*  f13b6d0:	316d0001 */ 	andi	$t5,$t3,0x1
/*  f13b6d4:	004a6021 */ 	addu	$t4,$v0,$t2
/*  f13b6d8:	24010001 */ 	li	$at,0x1
/*  f13b6dc:	15a10007 */ 	bne	$t5,$at,.PF0f13b6fc
/*  f13b6e0:	afac0070 */ 	sw	$t4,0x70($sp)
/*  f13b6e4:	90af0001 */ 	lbu	$t7,0x1($a1)
/*  f13b6e8:	24010009 */ 	li	$at,0x9
/*  f13b6ec:	51e10004 */ 	beql	$t7,$at,.PF0f13b700
/*  f13b6f0:	4614003c */ 	c.lt.s	$f0,$f20
/*  f13b6f4:	24120001 */ 	li	$s2,0x1
/*  f13b6f8:	24110001 */ 	li	$s1,0x1
.PF0f13b6fc:
/*  f13b6fc:	4614003c */ 	c.lt.s	$f0,$f20
.PF0f13b700:
/*  f13b700:	90a60001 */ 	lbu	$a2,0x1($a1)
/*  f13b704:	4502000f */ 	bc1fl	.PF0f13b744
/*  f13b708:	4600103c */ 	c.lt.s	$f2,$f0
/*  f13b70c:	94ae0000 */ 	lhu	$t6,0x0($a1)
/*  f13b710:	24010002 */ 	li	$at,0x2
/*  f13b714:	000ec440 */ 	sll	$t8,$t6,0x11
/*  f13b718:	0018cf82 */ 	srl	$t9,$t8,0x1e
/*  f13b71c:	332a0002 */ 	andi	$t2,$t9,0x2
/*  f13b720:	11410005 */ 	beq	$t2,$at,.PF0f13b738
/*  f13b724:	00000000 */ 	nop
/*  f13b728:	4600a281 */ 	sub.s	$f10,$f20,$f0
/*  f13b72c:	46145582 */ 	mul.s	$f22,$f10,$f20
/*  f13b730:	1000002a */ 	b	.PF0f13b7dc
/*  f13b734:	24cefffe */ 	addiu	$t6,$a2,-2
.PF0f13b738:
/*  f13b738:	10000027 */ 	b	.PF0f13b7d8
/*  f13b73c:	24070001 */ 	li	$a3,0x1
/*  f13b740:	4600103c */ 	c.lt.s	$f2,$f0
.PF0f13b744:
/*  f13b744:	00000000 */ 	nop
/*  f13b748:	45020023 */ 	bc1fl	.PF0f13b7d8
/*  f13b74c:	24070001 */ 	li	$a3,0x1
/*  f13b750:	94a30000 */ 	lhu	$v1,0x0($a1)
/*  f13b754:	24010001 */ 	li	$at,0x1
/*  f13b758:	24040001 */ 	li	$a0,0x1
/*  f13b75c:	00036440 */ 	sll	$t4,$v1,0x11
/*  f13b760:	000c1f82 */ 	srl	$v1,$t4,0x1e
/*  f13b764:	306d0001 */ 	andi	$t5,$v1,0x1
/*  f13b768:	11a10018 */ 	beq	$t5,$at,.PF0f13b7cc
/*  f13b76c:	00000000 */ 	nop
/*  f13b770:	46020201 */ 	sub.s	$f8,$f0,$f2
/*  f13b774:	24010001 */ 	li	$at,0x1
/*  f13b778:	00c01025 */ 	move	$v0,$a2
/*  f13b77c:	32af0001 */ 	andi	$t7,$s5,0x1
/*  f13b780:	46144582 */ 	mul.s	$f22,$f8,$f20
/*  f13b784:	10c10007 */ 	beq	$a2,$at,.PF0f13b7a4
/*  f13b788:	24010002 */ 	li	$at,0x2
/*  f13b78c:	10410003 */ 	beq	$v0,$at,.PF0f13b79c
/*  f13b790:	24010007 */ 	li	$at,0x7
/*  f13b794:	14410006 */ 	bne	$v0,$at,.PF0f13b7b0
/*  f13b798:	00000000 */ 	nop
.PF0f13b79c:
/*  f13b79c:	10000004 */ 	b	.PF0f13b7b0
/*  f13b7a0:	00002025 */ 	move	$a0,$zero
.PF0f13b7a4:
/*  f13b7a4:	15e00002 */ 	bnez	$t7,.PF0f13b7b0
/*  f13b7a8:	00000000 */ 	nop
/*  f13b7ac:	00002025 */ 	move	$a0,$zero
.PF0f13b7b0:
/*  f13b7b0:	5460000a */ 	bnezl	$v1,.PF0f13b7dc
/*  f13b7b4:	24cefffe */ 	addiu	$t6,$a2,-2
/*  f13b7b8:	50800008 */ 	beqzl	$a0,.PF0f13b7dc
/*  f13b7bc:	24cefffe */ 	addiu	$t6,$a2,-2
/*  f13b7c0:	24120002 */ 	li	$s2,0x2
/*  f13b7c4:	10000004 */ 	b	.PF0f13b7d8
/*  f13b7c8:	24110001 */ 	li	$s1,0x1
.PF0f13b7cc:
/*  f13b7cc:	10000002 */ 	b	.PF0f13b7d8
/*  f13b7d0:	24070001 */ 	li	$a3,0x1
/*  f13b7d4:	24070001 */ 	li	$a3,0x1
.PF0f13b7d8:
/*  f13b7d8:	24cefffe */ 	addiu	$t6,$a2,-2
.PF0f13b7dc:
/*  f13b7dc:	2dc1000a */ 	sltiu	$at,$t6,0xa
/*  f13b7e0:	1020000b */ 	beqz	$at,.PF0f13b810
/*  f13b7e4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f13b7e8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13b7ec:	002e0821 */ 	addu	$at,$at,$t6
/*  f13b7f0:	8c2e6c28 */ 	lw	$t6,0x6c28($at)
/*  f13b7f4:	01c00008 */ 	jr	$t6
/*  f13b7f8:	00000000 */ 	nop
/*  f13b7fc:	10000004 */ 	b	.PF0f13b810
/*  f13b800:	00008025 */ 	move	$s0,$zero
/*  f13b804:	10000002 */ 	b	.PF0f13b810
/*  f13b808:	24100002 */ 	li	$s0,0x2
/*  f13b80c:	24100001 */ 	li	$s0,0x1
.PF0f13b810:
/*  f13b810:	50e0002c */ 	beqzl	$a3,.PF0f13b8c4
/*  f13b814:	8fad0074 */ 	lw	$t5,0x74($sp)
/*  f13b818:	0c004ad4 */ 	jal	random
/*  f13b81c:	00000000 */ 	nop
/*  f13b820:	3c18800a */ 	lui	$t8,0x800a
/*  f13b824:	8f184710 */ 	lw	$t8,0x4710($t8)
/*  f13b828:	24010001 */ 	li	$at,0x1
/*  f13b82c:	9319419c */ 	lbu	$t9,0x419c($t8)
/*  f13b830:	00195100 */ 	sll	$t2,$t9,0x4
/*  f13b834:	004a001b */ 	divu	$zero,$v0,$t2
/*  f13b838:	00006010 */ 	mfhi	$t4
/*  f13b83c:	15400002 */ 	bnez	$t2,.PF0f13b848
/*  f13b840:	00000000 */ 	nop
/*  f13b844:	0007000d */ 	break	0x7
.PF0f13b848:
/*  f13b848:	5581001e */ 	bnel	$t4,$at,.PF0f13b8c4
/*  f13b84c:	8fad0074 */ 	lw	$t5,0x74($sp)
/*  f13b850:	0c004ad4 */ 	jal	random
/*  f13b854:	00000000 */ 	nop
/*  f13b858:	44823000 */ 	mtc1	$v0,$f6
/*  f13b85c:	3c014f80 */ 	lui	$at,0x4f80
/*  f13b860:	04410004 */ 	bgez	$v0,.PF0f13b874
/*  f13b864:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f13b868:	44815000 */ 	mtc1	$at,$f10
/*  f13b86c:	00000000 */ 	nop
/*  f13b870:	460a2100 */ 	add.s	$f4,$f4,$f10
.PF0f13b874:
/*  f13b874:	3c012f80 */ 	lui	$at,0x2f80
/*  f13b878:	44814000 */ 	mtc1	$at,$f8
/*  f13b87c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13b880:	c42a6c50 */ 	lwc1	$f10,0x6c50($at)
/*  f13b884:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f13b888:	00000000 */ 	nop
/*  f13b88c:	460a3582 */ 	mul.s	$f22,$f6,$f10
/*  f13b890:	0c004ad4 */ 	jal	random
/*  f13b894:	00000000 */ 	nop
/*  f13b898:	24010003 */ 	li	$at,0x3
/*  f13b89c:	0041001b */ 	divu	$zero,$v0,$at
/*  f13b8a0:	00008010 */ 	mfhi	$s0
/*  f13b8a4:	0c004ad4 */ 	jal	random
/*  f13b8a8:	00000000 */ 	nop
/*  f13b8ac:	24010003 */ 	li	$at,0x3
/*  f13b8b0:	0041001b */ 	divu	$zero,$v0,$at
/*  f13b8b4:	00008810 */ 	mfhi	$s1
/*  f13b8b8:	00000000 */ 	nop
/*  f13b8bc:	00000000 */ 	nop
/*  f13b8c0:	8fad0074 */ 	lw	$t5,0x74($sp)
.PF0f13b8c4:
/*  f13b8c4:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f13b8c8:	8ecb0000 */ 	lw	$t3,0x0($s6)
/*  f13b8cc:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f13b8d0:	8e850000 */ 	lw	$a1,0x0($s4)
/*  f13b8d4:	8ee70000 */ 	lw	$a3,0x0($s7)
/*  f13b8d8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f13b8dc:	8dd80000 */ 	lw	$t8,0x0($t6)
/*  f13b8e0:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f13b8e4:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f13b8e8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f13b8ec:	e7b60018 */ 	swc1	$f22,0x18($sp)
/*  f13b8f0:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
/*  f13b8f4:	01733021 */ 	addu	$a2,$t3,$s3
/*  f13b8f8:	0fc4ea47 */ 	jal	func0f139d9c
/*  f13b8fc:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f13b900:	3c04800a */ 	lui	$a0,0x800a
/*  f13b904:	8c844710 */ 	lw	$a0,0x4710($a0)
/*  f13b908:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f13b90c:	9086419c */ 	lbu	$a2,0x419c($a0)
/*  f13b910:	0006c840 */ 	sll	$t9,$a2,0x1
/*  f13b914:	03203025 */ 	move	$a2,$t9
/*  f13b918:	26b50001 */ 	addiu	$s5,$s5,0x1
.PF0f13b91c:
/*  f13b91c:	02a6082a */ 	slt	$at,$s5,$a2
/*  f13b920:	1420ff24 */ 	bnez	$at,.PF0f13b5b4
/*  f13b924:	24050002 */ 	li	$a1,0x2
.PF0f13b928:
/*  f13b928:	0fc55125 */ 	jal	func0f153780
/*  f13b92c:	8fa401d8 */ 	lw	$a0,0x1d8($sp)
.PF0f13b930:
/*  f13b930:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f13b934:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f13b938:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f13b93c:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f13b940:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f13b944:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f13b948:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f13b94c:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f13b950:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f13b954:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f13b958:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f13b95c:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f13b960:	03e00008 */ 	jr	$ra
/*  f13b964:	27bd01d8 */ 	addiu	$sp,$sp,0x1d8
);
#else
GLOBAL_ASM(
glabel func0f13a3ec
.late_rodata
glabel var7f1b5878
.word func0f13a3ec+0x158 # f13a544
glabel var7f1b587c
.word func0f13a3ec+0x158 # f13a544
glabel var7f1b5880
.word func0f13a3ec+0x158 # f13a544
glabel var7f1b5884
.word func0f13a3ec+0x174 # f13a560
glabel var7f1b5888
.word func0f13a3ec+0x190 # f13a57c
glabel var7f1b588c
.word func0f13a3ec+0x174 # f13a560
glabel var7f1b5890
.word func0f13a3ec+0x158 # f13a544
glabel var7f1b5894
.word func0f13a3ec+0x158 # f13a544
glabel var7f1b5898
.word func0f13a3ec+0x174 # f13a560
glabel var7f1b589c
.word func0f13a3ec+0x158 # f13a544
glabel var7f1b58a0
.word func0f13a3ec+0x174 # f13a560
glabel var7f1b58a4
.word func0f13a3ec+0x2c8 # f13a6b4
glabel var7f1b58a8
.word func0f13a3ec+0x2c8 # f13a6b4
glabel var7f1b58ac
.word func0f13a3ec+0x2c8 # f13a6b4
glabel var7f1b58b0
.word func0f13a3ec+0x2c8 # f13a6b4
glabel var7f1b58b4
.word func0f13a3ec+0x2c8 # f13a6b4
glabel var7f1b58b8
.word func0f13a3ec+0x2c8 # f13a6b4
glabel var7f1b58bc
.word func0f13a3ec+0x300 # f13a6ec
glabel var7f1b58c0
.word func0f13a3ec+0x2ec # f13a6d8
glabel var7f1b58c4
.word func0f13a3ec+0x2ec # f13a6d8
glabel var7f1b58c8
.word func0f13a3ec+0x2c8 # f13a6b4
glabel var7f1b58cc
.word func0f13a3ec+0x300 # f13a6ec
glabel var7f1b58d0
.word func0f13a3ec+0x340 # f13a72c
glabel var7f1b58d4
.word func0f13a3ec+0x35c # f13a748
glabel var7f1b58d8
.word func0f13a3ec+0x35c # f13a748
glabel var7f1b58dc
.word func0f13a3ec+0x35c # f13a748
glabel var7f1b58e0
.word func0f13a3ec+0x35c # f13a748
glabel var7f1b58e4
.word func0f13a3ec+0x35c # f13a748
glabel var7f1b58e8
.word func0f13a3ec+0x394 # f13a780
glabel var7f1b58ec
.word func0f13a3ec+0x380 # f13a76c
glabel var7f1b58f0
.word func0f13a3ec+0x380 # f13a76c
glabel var7f1b58f4
.word func0f13a3ec+0x35c # f13a748
glabel var7f1b58f8
.word func0f13a3ec+0x380 # f13a76c
glabel var7f1b58fc
.word 0x3e116873
glabel var7f1b5900
.word 0x3e116873
glabel var7f1b5904
.word func0f13a3ec+0x8b8 # f13aca4
glabel var7f1b5908
.word func0f13a3ec+0x8bc # f13aca8
glabel var7f1b590c
.word func0f13a3ec+0x8bc # f13aca8
glabel var7f1b5910
.word func0f13a3ec+0x8bc # f13aca8
glabel var7f1b5914
.word func0f13a3ec+0x8bc # f13aca8
glabel var7f1b5918
.word func0f13a3ec+0x8a8 # f13ac94
glabel var7f1b591c
.word func0f13a3ec+0x8b0 # f13ac9c
glabel var7f1b5920
.word func0f13a3ec+0x8b0 # f13ac9c
glabel var7f1b5924
.word func0f13a3ec+0x8bc # f13aca8
glabel var7f1b5928
.word func0f13a3ec+0x8b0 # f13ac9c
glabel var7f1b592c
.word 0x3d4ccccd
.text
/*  f13a3ec:	27bdfe18 */ 	addiu	$sp,$sp,-488
/*  f13a3f0:	3c0f800a */ 	lui	$t7,%hi(g_CreditsData)
/*  f13a3f4:	8def4170 */ 	lw	$t7,%lo(g_CreditsData)($t7)
/*  f13a3f8:	240effff */ 	addiu	$t6,$zero,-1
/*  f13a3fc:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f13a400:	afbe0068 */ 	sw	$s8,0x68($sp)
/*  f13a404:	afb70064 */ 	sw	$s7,0x64($sp)
/*  f13a408:	afb60060 */ 	sw	$s6,0x60($sp)
/*  f13a40c:	afb5005c */ 	sw	$s5,0x5c($sp)
/*  f13a410:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f13a414:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f13a418:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f13a41c:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f13a420:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f13a424:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f13a428:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f13a42c:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f13a430:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f13a434:	afae00e8 */ 	sw	$t6,0xe8($sp)
/*  f13a438:	91f8419c */ 	lbu	$t8,0x419c($t7)
/*  f13a43c:	0000f025 */ 	or	$s8,$zero,$zero
/*  f13a440:	0000a825 */ 	or	$s5,$zero,$zero
/*  f13a444:	1b0000e3 */ 	blez	$t8,.L0f13a7d4
/*  f13a448:	27b601d4 */ 	addiu	$s6,$sp,0x1d4
/*  f13a44c:	3c014120 */ 	lui	$at,0x4120
/*  f13a450:	4481a000 */ 	mtc1	$at,$f20
/*  f13a454:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f13a458:	8fb900a8 */ 	lw	$t9,0xa8($sp)
.L0f13a45c:
/*  f13a45c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13a460:	0fc4e839 */ 	jal	creditGetByRow
/*  f13a464:	afb900e4 */ 	sw	$t9,0xe4($sp)
/*  f13a468:	1440000d */ 	bnez	$v0,.L0f13a4a0
/*  f13a46c:	aec20000 */ 	sw	$v0,0x0($s6)
/*  f13a470:	3c03800a */ 	lui	$v1,%hi(g_CreditsData)
/*  f13a474:	24634170 */ 	addiu	$v1,$v1,%lo(g_CreditsData)
/*  f13a478:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f13a47c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f13a480:	4480c000 */ 	mtc1	$zero,$f24
/*  f13a484:	ad404198 */ 	sw	$zero,0x4198($t2)
/*  f13a488:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f13a48c:	a18b419c */ 	sb	$t3,0x419c($t4)
/*  f13a490:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f13a494:	e5b841a0 */ 	swc1	$f24,0x41a0($t5)
/*  f13a498:	1000024b */ 	b	.L0f13adc8
/*  f13a49c:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f13a4a0:
/*  f13a4a0:	8fa200a8 */ 	lw	$v0,0xa8($sp)
/*  f13a4a4:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f13a4a8:	27b80194 */ 	addiu	$t8,$sp,0x194
/*  f13a4ac:	00027880 */ 	sll	$t7,$v0,0x2
/*  f13a4b0:	27b90174 */ 	addiu	$t9,$sp,0x174
/*  f13a4b4:	27ab0110 */ 	addiu	$t3,$sp,0x110
/*  f13a4b8:	95c40002 */ 	lhu	$a0,0x2($t6)
/*  f13a4bc:	27ae00f0 */ 	addiu	$t6,$sp,0xf0
/*  f13a4c0:	01eb9821 */ 	addu	$s3,$t7,$t3
/*  f13a4c4:	01f98821 */ 	addu	$s1,$t7,$t9
/*  f13a4c8:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f13a4cc:	27aa0150 */ 	addiu	$t2,$sp,0x150
/*  f13a4d0:	27ac0130 */ 	addiu	$t4,$sp,0x130
/*  f13a4d4:	01ec6821 */ 	addu	$t5,$t7,$t4
/*  f13a4d8:	01ea9021 */ 	addu	$s2,$t7,$t2
/*  f13a4dc:	01eeb821 */ 	addu	$s7,$t7,$t6
/*  f13a4e0:	01e01025 */ 	or	$v0,$t7,$zero
/*  f13a4e4:	26ef0004 */ 	addiu	$t7,$s7,0x4
/*  f13a4e8:	26780004 */ 	addiu	$t8,$s3,0x4
/*  f13a4ec:	27b901b4 */ 	addiu	$t9,$sp,0x1b4
/*  f13a4f0:	0059a021 */ 	addu	$s4,$v0,$t9
/*  f13a4f4:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f13a4f8:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f13a4fc:	0fc5b9f1 */ 	jal	langGet
/*  f13a500:	afad008c */ 	sw	$t5,0x8c($sp)
/*  f13a504:	8eca0000 */ 	lw	$t2,0x0($s6)
/*  f13a508:	ae820000 */ 	sw	$v0,0x0($s4)
/*  f13a50c:	0fc5b9f1 */ 	jal	langGet
/*  f13a510:	95440004 */ 	lhu	$a0,0x4($t2)
/*  f13a514:	8ec30000 */ 	lw	$v1,0x0($s6)
/*  f13a518:	ae820004 */ 	sw	$v0,0x4($s4)
/*  f13a51c:	906b0001 */ 	lbu	$t3,0x1($v1)
/*  f13a520:	256cffff */ 	addiu	$t4,$t3,-1
/*  f13a524:	2d81000b */ 	sltiu	$at,$t4,0xb
/*  f13a528:	10200014 */ 	beqz	$at,.L0f13a57c
/*  f13a52c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f13a530:	3c017f1b */ 	lui	$at,%hi(var7f1b5878)
/*  f13a534:	002c0821 */ 	addu	$at,$at,$t4
/*  f13a538:	8c2c5878 */ 	lw	$t4,%lo(var7f1b5878)($at)
/*  f13a53c:	01800008 */ 	jr	$t4
/*  f13a540:	00000000 */ 	nop
/*  f13a544:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicLg1)
/*  f13a548:	8dadfb20 */ 	lw	$t5,%lo(g_FontHandelGothicLg1)($t5)
/*  f13a54c:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicLg2)
/*  f13a550:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f13a554:	8dcefb1c */ 	lw	$t6,%lo(g_FontHandelGothicLg2)($t6)
/*  f13a558:	1000000e */ 	b	.L0f13a594
/*  f13a55c:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f13a560:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicMd1)
/*  f13a564:	8deffb18 */ 	lw	$t7,%lo(g_FontHandelGothicMd1)($t7)
/*  f13a568:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicMd2)
/*  f13a56c:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f13a570:	8f18fb14 */ 	lw	$t8,%lo(g_FontHandelGothicMd2)($t8)
/*  f13a574:	10000007 */ 	b	.L0f13a594
/*  f13a578:	ae380000 */ 	sw	$t8,0x0($s1)
.L0f13a57c:
/*  f13a57c:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm1)
/*  f13a580:	8f39fb10 */ 	lw	$t9,%lo(g_FontHandelGothicSm1)($t9)
/*  f13a584:	3c0a8008 */ 	lui	$t2,%hi(g_FontHandelGothicSm2)
/*  f13a588:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f13a58c:	8d4afb0c */ 	lw	$t2,%lo(g_FontHandelGothicSm2)($t2)
/*  f13a590:	ae2a0000 */ 	sw	$t2,0x0($s1)
.L0f13a594:
/*  f13a594:	90620001 */ 	lbu	$v0,0x1($v1)
/*  f13a598:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13a59c:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicMd1)
/*  f13a5a0:	10410013 */ 	beq	$v0,$at,.L0f13a5f0
/*  f13a5a4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f13a5a8:	10410009 */ 	beq	$v0,$at,.L0f13a5d0
/*  f13a5ac:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicSm1)
/*  f13a5b0:	2401000a */ 	addiu	$at,$zero,0xa
/*  f13a5b4:	1041000e */ 	beq	$v0,$at,.L0f13a5f0
/*  f13a5b8:	00000000 */ 	nop
/*  f13a5bc:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f13a5c0:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f13a5c4:	ae070004 */ 	sw	$a3,0x4($s0)
/*  f13a5c8:	10000010 */ 	b	.L0f13a60c
/*  f13a5cc:	ae220004 */ 	sw	$v0,0x4($s1)
.L0f13a5d0:
/*  f13a5d0:	8d6bfb10 */ 	lw	$t3,%lo(g_FontHandelGothicSm1)($t3)
/*  f13a5d4:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm2)
/*  f13a5d8:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f13a5dc:	ae0b0004 */ 	sw	$t3,0x4($s0)
/*  f13a5e0:	8d8cfb0c */ 	lw	$t4,%lo(g_FontHandelGothicSm2)($t4)
/*  f13a5e4:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f13a5e8:	10000008 */ 	b	.L0f13a60c
/*  f13a5ec:	ae2c0004 */ 	sw	$t4,0x4($s1)
.L0f13a5f0:
/*  f13a5f0:	8dadfb18 */ 	lw	$t5,%lo(g_FontHandelGothicMd1)($t5)
/*  f13a5f4:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicMd2)
/*  f13a5f8:	8e070000 */ 	lw	$a3,0x0($s0)
/*  f13a5fc:	ae0d0004 */ 	sw	$t5,0x4($s0)
/*  f13a600:	8dcefb14 */ 	lw	$t6,%lo(g_FontHandelGothicMd2)($t6)
/*  f13a604:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f13a608:	ae2e0004 */ 	sw	$t6,0x4($s1)
.L0f13a60c:
/*  f13a60c:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f13a610:	24010002 */ 	addiu	$at,$zero,0x2
/*  f13a614:	11e10005 */ 	beq	$t7,$at,.L0f13a62c
/*  f13a618:	24010005 */ 	addiu	$at,$zero,0x5
/*  f13a61c:	11e10003 */ 	beq	$t7,$at,.L0f13a62c
/*  f13a620:	24010007 */ 	addiu	$at,$zero,0x7
/*  f13a624:	55e10009 */ 	bnel	$t7,$at,.L0f13a64c
/*  f13a628:	90790001 */ 	lbu	$t9,0x1($v1)
.L0f13a62c:
/*  f13a62c:	449e2000 */ 	mtc1	$s8,$f4
/*  f13a630:	00000000 */ 	nop
/*  f13a634:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13a638:	46143200 */ 	add.s	$f8,$f6,$f20
/*  f13a63c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f13a640:	441e5000 */ 	mfc1	$s8,$f10
/*  f13a644:	00000000 */ 	nop
/*  f13a648:	90790001 */ 	lbu	$t9,0x1($v1)
.L0f13a64c:
/*  f13a64c:	02e02025 */ 	or	$a0,$s7,$zero
/*  f13a650:	02602825 */ 	or	$a1,$s3,$zero
/*  f13a654:	afb900e8 */ 	sw	$t9,0xe8($sp)
/*  f13a658:	8e860000 */ 	lw	$a2,0x0($s4)
/*  f13a65c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13a660:	0fc55cbe */ 	jal	textMeasure
/*  f13a664:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f13a668:	8e2a0004 */ 	lw	$t2,0x4($s1)
/*  f13a66c:	8e860004 */ 	lw	$a2,0x4($s4)
/*  f13a670:	8e070004 */ 	lw	$a3,0x4($s0)
/*  f13a674:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13a678:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f13a67c:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f13a680:	0fc55cbe */ 	jal	textMeasure
/*  f13a684:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f13a688:	8ec30000 */ 	lw	$v1,0x0($s6)
/*  f13a68c:	906b0001 */ 	lbu	$t3,0x1($v1)
/*  f13a690:	256cffff */ 	addiu	$t4,$t3,-1
/*  f13a694:	2d81000b */ 	sltiu	$at,$t4,0xb
/*  f13a698:	10200014 */ 	beqz	$at,.L0f13a6ec
/*  f13a69c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f13a6a0:	3c017f1b */ 	lui	$at,%hi(var7f1b58a4)
/*  f13a6a4:	002c0821 */ 	addu	$at,$at,$t4
/*  f13a6a8:	8c2c58a4 */ 	lw	$t4,%lo(var7f1b58a4)($at)
/*  f13a6ac:	01800008 */ 	jr	$t4
/*  f13a6b0:	00000000 */ 	nop
/*  f13a6b4:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f13a6b8:	240f00a0 */ 	addiu	$t7,$zero,0xa0
/*  f13a6bc:	05a10003 */ 	bgez	$t5,.L0f13a6cc
/*  f13a6c0:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f13a6c4:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f13a6c8:	00017043 */ 	sra	$t6,$at,0x1
.L0f13a6cc:
/*  f13a6cc:	01eec023 */ 	subu	$t8,$t7,$t6
/*  f13a6d0:	10000008 */ 	b	.L0f13a6f4
/*  f13a6d4:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f13a6d8:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f13a6dc:	240a010e */ 	addiu	$t2,$zero,0x10e
/*  f13a6e0:	01595823 */ 	subu	$t3,$t2,$t9
/*  f13a6e4:	10000003 */ 	b	.L0f13a6f4
/*  f13a6e8:	ae4b0000 */ 	sw	$t3,0x0($s2)
.L0f13a6ec:
/*  f13a6ec:	240c0032 */ 	addiu	$t4,$zero,0x32
/*  f13a6f0:	ae4c0000 */ 	sw	$t4,0x0($s2)
.L0f13a6f4:
/*  f13a6f4:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f13a6f8:	adbe0000 */ 	sw	$s8,0x0($t5)
/*  f13a6fc:	906e0001 */ 	lbu	$t6,0x1($v1)
/*  f13a700:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f13a704:	25d8ffff */ 	addiu	$t8,$t6,-1
/*  f13a708:	2f01000b */ 	sltiu	$at,$t8,0xb
/*  f13a70c:	1020001c */ 	beqz	$at,.L0f13a780
/*  f13a710:	03cff021 */ 	addu	$s8,$s8,$t7
/*  f13a714:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f13a718:	3c017f1b */ 	lui	$at,%hi(var7f1b58d0)
/*  f13a71c:	00380821 */ 	addu	$at,$at,$t8
/*  f13a720:	8c3858d0 */ 	lw	$t8,%lo(var7f1b58d0)($at)
/*  f13a724:	03000008 */ 	jr	$t8
/*  f13a728:	00000000 */ 	nop
/*  f13a72c:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*  f13a730:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f13a734:	8e6c0004 */ 	lw	$t4,0x4($s3)
/*  f13a738:	01595821 */ 	addu	$t3,$t2,$t9
/*  f13a73c:	016c6823 */ 	subu	$t5,$t3,$t4
/*  f13a740:	10000011 */ 	b	.L0f13a788
/*  f13a744:	ae4d0004 */ 	sw	$t5,0x4($s2)
/*  f13a748:	8e6f0004 */ 	lw	$t7,0x4($s3)
/*  f13a74c:	241800a0 */ 	addiu	$t8,$zero,0xa0
/*  f13a750:	05e10003 */ 	bgez	$t7,.L0f13a760
/*  f13a754:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f13a758:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f13a75c:	00017043 */ 	sra	$t6,$at,0x1
.L0f13a760:
/*  f13a760:	030e5023 */ 	subu	$t2,$t8,$t6
/*  f13a764:	10000008 */ 	b	.L0f13a788
/*  f13a768:	ae4a0004 */ 	sw	$t2,0x4($s2)
/*  f13a76c:	8e790004 */ 	lw	$t9,0x4($s3)
/*  f13a770:	240b010e */ 	addiu	$t3,$zero,0x10e
/*  f13a774:	01796023 */ 	subu	$t4,$t3,$t9
/*  f13a778:	10000003 */ 	b	.L0f13a788
/*  f13a77c:	ae4c0004 */ 	sw	$t4,0x4($s2)
.L0f13a780:
/*  f13a780:	240d0032 */ 	addiu	$t5,$zero,0x32
/*  f13a784:	ae4d0004 */ 	sw	$t5,0x4($s2)
.L0f13a788:
/*  f13a788:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f13a78c:	3c19800a */ 	lui	$t9,%hi(g_CreditsData)
/*  f13a790:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f13a794:	00027880 */ 	sll	$t7,$v0,0x2
/*  f13a798:	03afc021 */ 	addu	$t8,$sp,$t7
/*  f13a79c:	af1e0134 */ 	sw	$s8,0x134($t8)
/*  f13a7a0:	8faa00a8 */ 	lw	$t2,0xa8($sp)
/*  f13a7a4:	8f394170 */ 	lw	$t9,%lo(g_CreditsData)($t9)
/*  f13a7a8:	03af7021 */ 	addu	$t6,$sp,$t7
/*  f13a7ac:	8dce00f4 */ 	lw	$t6,0xf4($t6)
/*  f13a7b0:	254b0002 */ 	addiu	$t3,$t2,0x2
/*  f13a7b4:	afab00a8 */ 	sw	$t3,0xa8($sp)
/*  f13a7b8:	932c419c */ 	lbu	$t4,0x419c($t9)
/*  f13a7bc:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f13a7c0:	03cef021 */ 	addu	$s8,$s8,$t6
/*  f13a7c4:	02ac082a */ 	slt	$at,$s5,$t4
/*  f13a7c8:	5420ff24 */ 	bnezl	$at,.L0f13a45c
/*  f13a7cc:	8fb900a8 */ 	lw	$t9,0xa8($sp)
/*  f13a7d0:	0000a825 */ 	or	$s5,$zero,$zero
.L0f13a7d4:
/*  f13a7d4:	0fc54d8a */ 	jal	func0f153628
/*  f13a7d8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f13a7dc:	3c04800a */ 	lui	$a0,%hi(g_CreditsData)
/*  f13a7e0:	8c844170 */ 	lw	$a0,%lo(g_CreditsData)($a0)
/*  f13a7e4:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f13a7e8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f13a7ec:	9086419c */ 	lbu	$a2,0x419c($a0)
/*  f13a7f0:	00066840 */ 	sll	$t5,$a2,0x1
/*  f13a7f4:	19a00091 */ 	blez	$t5,.L0f13aa3c
/*  f13a7f8:	01a03025 */ 	or	$a2,$t5,$zero
/*  f13a7fc:	4481b000 */ 	mtc1	$at,$f22
/*  f13a800:	3c013f80 */ 	lui	$at,0x3f80
/*  f13a804:	4481a000 */ 	mtc1	$at,$f20
/*  f13a808:	4480c000 */ 	mtc1	$zero,$f24
/*  f13a80c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f13a810:	44959000 */ 	mtc1	$s5,$f18
.L0f13a814:
/*  f13a814:	3c017f1b */ 	lui	$at,%hi(var7f1b58fc)
/*  f13a818:	c42658fc */ 	lwc1	$f6,%lo(var7f1b58fc)($at)
/*  f13a81c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f13a820:	c48a41a0 */ 	lwc1	$f10,0x41a0($a0)
/*  f13a824:	4600c306 */ 	mov.s	$f12,$f24
/*  f13a828:	4600a386 */ 	mov.s	$f14,$f20
/*  f13a82c:	4600a406 */ 	mov.s	$f16,$f20
/*  f13a830:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f13a834:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f13a838:	4600c03c */ 	c.lt.s	$f24,$f0
/*  f13a83c:	00000000 */ 	nop
/*  f13a840:	4503000f */ 	bc1tl	.L0f13a880
/*  f13a844:	c48241a4 */ 	lwc1	$f2,0x41a4($a0)
/*  f13a848:	06a10003 */ 	bgez	$s5,.L0f13a858
/*  f13a84c:	00157843 */ 	sra	$t7,$s5,0x1
/*  f13a850:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f13a854:	00017843 */ 	sra	$t7,$at,0x1
.L0f13a858:
/*  f13a858:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f13a85c:	03b87021 */ 	addu	$t6,$sp,$t8
/*  f13a860:	8dce01d4 */ 	lw	$t6,0x1d4($t6)
/*  f13a864:	95ca0000 */ 	lhu	$t2,0x0($t6)
/*  f13a868:	000a5c40 */ 	sll	$t3,$t2,0x11
/*  f13a86c:	000bcf82 */ 	srl	$t9,$t3,0x1e
/*  f13a870:	332c0002 */ 	andi	$t4,$t9,0x2
/*  f13a874:	54ac006d */ 	bnel	$a1,$t4,.L0f13aa2c
/*  f13a878:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f13a87c:	c48241a4 */ 	lwc1	$f2,0x41a4($a0)
.L0f13a880:
/*  f13a880:	06a10003 */ 	bgez	$s5,.L0f13a890
/*  f13a884:	00156843 */ 	sra	$t5,$s5,0x1
/*  f13a888:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f13a88c:	00016843 */ 	sra	$t5,$at,0x1
.L0f13a890:
/*  f13a890:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f13a894:	03afc021 */ 	addu	$t8,$sp,$t7
/*  f13a898:	46141480 */ 	add.s	$f18,$f2,$f20
/*  f13a89c:	8f1801d4 */ 	lw	$t8,0x1d4($t8)
/*  f13a8a0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13a8a4:	00151080 */ 	sll	$v0,$s5,0x2
/*  f13a8a8:	97030000 */ 	lhu	$v1,0x0($t8)
/*  f13a8ac:	4612003c */ 	c.lt.s	$f0,$f18
/*  f13a8b0:	240c0078 */ 	addiu	$t4,$zero,0x78
/*  f13a8b4:	00037440 */ 	sll	$t6,$v1,0x11
/*  f13a8b8:	000e5782 */ 	srl	$t2,$t6,0x1e
/*  f13a8bc:	45010004 */ 	bc1t	.L0f13a8d0
/*  f13a8c0:	01401825 */ 	or	$v1,$t2,$zero
/*  f13a8c4:	314b0001 */ 	andi	$t3,$t2,0x1
/*  f13a8c8:	55610058 */ 	bnel	$t3,$at,.L0f13aa2c
/*  f13a8cc:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f13a8d0:
/*  f13a8d0:	4614003c */ 	c.lt.s	$f0,$f20
/*  f13a8d4:	27ad0150 */ 	addiu	$t5,$sp,0x150
/*  f13a8d8:	27af0130 */ 	addiu	$t7,$sp,0x130
/*  f13a8dc:	27b801b4 */ 	addiu	$t8,$sp,0x1b4
/*  f13a8e0:	27ae0194 */ 	addiu	$t6,$sp,0x194
/*  f13a8e4:	27aa0174 */ 	addiu	$t2,$sp,0x174
/*  f13a8e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f13a8ec:	07c10003 */ 	bgez	$s8,.L0f13a8fc
/*  f13a8f0:	001ec843 */ 	sra	$t9,$s8,0x1
/*  f13a8f4:	27c10001 */ 	addiu	$at,$s8,0x1
/*  f13a8f8:	0001c843 */ 	sra	$t9,$at,0x1
.L0f13a8fc:
/*  f13a8fc:	01999823 */ 	subu	$s3,$t4,$t9
/*  f13a900:	004a4821 */ 	addu	$t1,$v0,$t2
/*  f13a904:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f13a908:	0058b821 */ 	addu	$s7,$v0,$t8
/*  f13a90c:	004fb021 */ 	addu	$s6,$v0,$t7
/*  f13a910:	45000006 */ 	bc1f	.L0f13a92c
/*  f13a914:	004da021 */ 	addu	$s4,$v0,$t5
/*  f13a918:	306b0002 */ 	andi	$t3,$v1,0x2
/*  f13a91c:	14ab001b */ 	bne	$a1,$t3,.L0f13a98c
/*  f13a920:	00000000 */ 	nop
/*  f13a924:	10000019 */ 	b	.L0f13a98c
/*  f13a928:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f13a92c:
/*  f13a92c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f13a930:	306c0001 */ 	andi	$t4,$v1,0x1
/*  f13a934:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13a938:	30790002 */ 	andi	$t9,$v1,0x2
/*  f13a93c:	45000009 */ 	bc1f	.L0f13a964
/*  f13a940:	00000000 */ 	nop
/*  f13a944:	55810004 */ 	bnel	$t4,$at,.L0f13a958
/*  f13a948:	46020101 */ 	sub.s	$f4,$f0,$f2
/*  f13a94c:	1000000f */ 	b	.L0f13a98c
/*  f13a950:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f13a954:	46020101 */ 	sub.s	$f4,$f0,$f2
.L0f13a958:
/*  f13a958:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f13a95c:	1000000b */ 	b	.L0f13a98c
/*  f13a960:	4606a301 */ 	sub.s	$f12,$f20,$f6
.L0f13a964:
/*  f13a964:	54b90004 */ 	bnel	$a1,$t9,.L0f13a978
/*  f13a968:	46140281 */ 	sub.s	$f10,$f0,$f20
/*  f13a96c:	10000007 */ 	b	.L0f13a98c
/*  f13a970:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f13a974:	46140281 */ 	sub.s	$f10,$f0,$f20
.L0f13a978:
/*  f13a978:	4600a306 */ 	mov.s	$f12,$f20
/*  f13a97c:	46141201 */ 	sub.s	$f8,$f2,$f20
/*  f13a980:	46085383 */ 	div.s	$f14,$f10,$f8
/*  f13a984:	46167402 */ 	mul.s	$f16,$f14,$f22
/*  f13a988:	00000000 */ 	nop
.L0f13a98c:
/*  f13a98c:	50800005 */ 	beqzl	$a0,.L0f13a9a4
/*  f13a990:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f13a994:	4600a306 */ 	mov.s	$f12,$f20
/*  f13a998:	4600a386 */ 	mov.s	$f14,$f20
/*  f13a99c:	4600a406 */ 	mov.s	$f16,$f20
/*  f13a9a0:	460ca03c */ 	c.lt.s	$f20,$f12
.L0f13a9a4:
/*  f13a9a4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f13a9a8:	45020003 */ 	bc1fl	.L0f13a9b8
/*  f13a9ac:	4610a03c */ 	c.lt.s	$f20,$f16
/*  f13a9b0:	4600a306 */ 	mov.s	$f12,$f20
/*  f13a9b4:	4610a03c */ 	c.lt.s	$f20,$f16
.L0f13a9b8:
/*  f13a9b8:	00000000 */ 	nop
/*  f13a9bc:	45020003 */ 	bc1fl	.L0f13a9cc
/*  f13a9c0:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f13a9c4:	4600a406 */ 	mov.s	$f16,$f20
/*  f13a9c8:	460ea03c */ 	c.lt.s	$f20,$f14
.L0f13a9cc:
/*  f13a9cc:	00000000 */ 	nop
/*  f13a9d0:	45020003 */ 	bc1fl	.L0f13a9e0
/*  f13a9d4:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f13a9d8:	4600a386 */ 	mov.s	$f14,$f20
/*  f13a9dc:	8d0f0000 */ 	lw	$t7,0x0($t0)
.L0f13a9e0:
/*  f13a9e0:	8ecd0000 */ 	lw	$t5,0x0($s6)
/*  f13a9e4:	8e850000 */ 	lw	$a1,0x0($s4)
/*  f13a9e8:	8ee70000 */ 	lw	$a3,0x0($s7)
/*  f13a9ec:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f13a9f0:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f13a9f4:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*  f13a9f8:	e7ae001c */ 	swc1	$f14,0x1c($sp)
/*  f13a9fc:	e7ac0018 */ 	swc1	$f12,0x18($sp)
/*  f13aa00:	01b33021 */ 	addu	$a2,$t5,$s3
/*  f13aa04:	0fc4e674 */ 	jal	func0f1399d0
/*  f13aa08:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f13aa0c:	3c04800a */ 	lui	$a0,%hi(g_CreditsData)
/*  f13aa10:	8c844170 */ 	lw	$a0,%lo(g_CreditsData)($a0)
/*  f13aa14:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f13aa18:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f13aa1c:	9086419c */ 	lbu	$a2,0x419c($a0)
/*  f13aa20:	00067040 */ 	sll	$t6,$a2,0x1
/*  f13aa24:	01c03025 */ 	or	$a2,$t6,$zero
/*  f13aa28:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f13aa2c:
/*  f13aa2c:	02a6082a */ 	slt	$at,$s5,$a2
/*  f13aa30:	5420ff78 */ 	bnezl	$at,.L0f13a814
/*  f13aa34:	44959000 */ 	mtc1	$s5,$f18
/*  f13aa38:	0000a825 */ 	or	$s5,$zero,$zero
.L0f13aa3c:
/*  f13aa3c:	3c013f80 */ 	lui	$at,0x3f80
/*  f13aa40:	4481a000 */ 	mtc1	$at,$f20
/*  f13aa44:	4480c000 */ 	mtc1	$zero,$f24
/*  f13aa48:	18c000dd */ 	blez	$a2,.L0f13adc0
/*  f13aa4c:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f13aa50:
/*  f13aa50:	44959000 */ 	mtc1	$s5,$f18
/*  f13aa54:	3c017f1b */ 	lui	$at,%hi(var7f1b5900)
/*  f13aa58:	c4265900 */ 	lwc1	$f6,%lo(var7f1b5900)($at)
/*  f13aa5c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f13aa60:	c48841a0 */ 	lwc1	$f8,0x41a0($a0)
/*  f13aa64:	4600c586 */ 	mov.s	$f22,$f24
/*  f13aa68:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f13aa6c:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f13aa70:	4600c03c */ 	c.lt.s	$f24,$f0
/*  f13aa74:	00000000 */ 	nop
/*  f13aa78:	4503000f */ 	bc1tl	.L0f13aab8
/*  f13aa7c:	c48241a4 */ 	lwc1	$f2,0x41a4($a0)
/*  f13aa80:	06a10003 */ 	bgez	$s5,.L0f13aa90
/*  f13aa84:	00155043 */ 	sra	$t2,$s5,0x1
/*  f13aa88:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f13aa8c:	00015043 */ 	sra	$t2,$at,0x1
.L0f13aa90:
/*  f13aa90:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f13aa94:	03ab6021 */ 	addu	$t4,$sp,$t3
/*  f13aa98:	8d8c01d4 */ 	lw	$t4,0x1d4($t4)
/*  f13aa9c:	95990000 */ 	lhu	$t9,0x0($t4)
/*  f13aaa0:	00196c40 */ 	sll	$t5,$t9,0x11
/*  f13aaa4:	000d7f82 */ 	srl	$t7,$t5,0x1e
/*  f13aaa8:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f13aaac:	54b800c1 */ 	bnel	$a1,$t8,.L0f13adb4
/*  f13aab0:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f13aab4:	c48241a4 */ 	lwc1	$f2,0x41a4($a0)
.L0f13aab8:
/*  f13aab8:	06a10003 */ 	bgez	$s5,.L0f13aac8
/*  f13aabc:	00157043 */ 	sra	$t6,$s5,0x1
/*  f13aac0:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f13aac4:	00017043 */ 	sra	$t6,$at,0x1
.L0f13aac8:
/*  f13aac8:	46141480 */ 	add.s	$f18,$f2,$f20
/*  f13aacc:	000e5080 */ 	sll	$t2,$t6,0x2
/*  f13aad0:	03aa2821 */ 	addu	$a1,$sp,$t2
/*  f13aad4:	8ca501d4 */ 	lw	$a1,0x1d4($a1)
/*  f13aad8:	4612003c */ 	c.lt.s	$f0,$f18
/*  f13aadc:	00003825 */ 	or	$a3,$zero,$zero
/*  f13aae0:	00009025 */ 	or	$s2,$zero,$zero
/*  f13aae4:	00957821 */ 	addu	$t7,$a0,$s5
/*  f13aae8:	45010008 */ 	bc1t	.L0f13ab0c
/*  f13aaec:	00151080 */ 	sll	$v0,$s5,0x2
/*  f13aaf0:	94ab0000 */ 	lhu	$t3,0x0($a1)
/*  f13aaf4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13aaf8:	000b6440 */ 	sll	$t4,$t3,0x11
/*  f13aafc:	000ccf82 */ 	srl	$t9,$t4,0x1e
/*  f13ab00:	332d0001 */ 	andi	$t5,$t9,0x1
/*  f13ab04:	55a100ab */ 	bnel	$t5,$at,.L0f13adb4
/*  f13ab08:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f13ab0c:
/*  f13ab0c:	91e341a8 */ 	lbu	$v1,0x41a8($t7)
/*  f13ab10:	240a0078 */ 	addiu	$t2,$zero,0x78
/*  f13ab14:	27ab0150 */ 	addiu	$t3,$sp,0x150
/*  f13ab18:	00038883 */ 	sra	$s1,$v1,0x2
/*  f13ab1c:	32380003 */ 	andi	$t8,$s1,0x3
/*  f13ab20:	03008825 */ 	or	$s1,$t8,$zero
/*  f13ab24:	27b80174 */ 	addiu	$t8,$sp,0x174
/*  f13ab28:	004ba021 */ 	addu	$s4,$v0,$t3
/*  f13ab2c:	27ad0194 */ 	addiu	$t5,$sp,0x194
/*  f13ab30:	8c864198 */ 	lw	$a2,0x4198($a0)
/*  f13ab34:	004d7821 */ 	addu	$t7,$v0,$t5
/*  f13ab38:	27ac0130 */ 	addiu	$t4,$sp,0x130
/*  f13ab3c:	27b901b4 */ 	addiu	$t9,$sp,0x1b4
/*  f13ab40:	0059b821 */ 	addu	$s7,$v0,$t9
/*  f13ab44:	004cb021 */ 	addu	$s6,$v0,$t4
/*  f13ab48:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f13ab4c:	30700003 */ 	andi	$s0,$v1,0x3
/*  f13ab50:	07c10003 */ 	bgez	$s8,.L0f13ab60
/*  f13ab54:	001e7043 */ 	sra	$t6,$s8,0x1
/*  f13ab58:	27c10001 */ 	addiu	$at,$s8,0x1
/*  f13ab5c:	00017043 */ 	sra	$t6,$at,0x1
.L0f13ab60:
/*  f13ab60:	014e9823 */ 	subu	$s3,$t2,$t6
/*  f13ab64:	00037103 */ 	sra	$t6,$v1,0x4
/*  f13ab68:	31cb0001 */ 	andi	$t3,$t6,0x1
/*  f13ab6c:	00585021 */ 	addu	$t2,$v0,$t8
/*  f13ab70:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13ab74:	15610007 */ 	bne	$t3,$at,.L0f13ab94
/*  f13ab78:	afaa0080 */ 	sw	$t2,0x80($sp)
/*  f13ab7c:	90ac0001 */ 	lbu	$t4,0x1($a1)
/*  f13ab80:	24010009 */ 	addiu	$at,$zero,0x9
/*  f13ab84:	51810004 */ 	beql	$t4,$at,.L0f13ab98
/*  f13ab88:	4614003c */ 	c.lt.s	$f0,$f20
/*  f13ab8c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f13ab90:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f13ab94:
/*  f13ab94:	4614003c */ 	c.lt.s	$f0,$f20
.L0f13ab98:
/*  f13ab98:	90a60001 */ 	lbu	$a2,0x1($a1)
/*  f13ab9c:	4502000f */ 	bc1fl	.L0f13abdc
/*  f13aba0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f13aba4:	94b90000 */ 	lhu	$t9,0x0($a1)
/*  f13aba8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f13abac:	00196c40 */ 	sll	$t5,$t9,0x11
/*  f13abb0:	000d7f82 */ 	srl	$t7,$t5,0x1e
/*  f13abb4:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f13abb8:	13010005 */ 	beq	$t8,$at,.L0f13abd0
/*  f13abbc:	00000000 */ 	nop
/*  f13abc0:	4600a101 */ 	sub.s	$f4,$f20,$f0
/*  f13abc4:	46142582 */ 	mul.s	$f22,$f4,$f20
/*  f13abc8:	1000002a */ 	b	.L0f13ac74
/*  f13abcc:	24d9fffe */ 	addiu	$t9,$a2,-2
.L0f13abd0:
/*  f13abd0:	10000027 */ 	b	.L0f13ac70
/*  f13abd4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f13abd8:	4600103c */ 	c.lt.s	$f2,$f0
.L0f13abdc:
/*  f13abdc:	00000000 */ 	nop
/*  f13abe0:	45020023 */ 	bc1fl	.L0f13ac70
/*  f13abe4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f13abe8:	94a30000 */ 	lhu	$v1,0x0($a1)
/*  f13abec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13abf0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f13abf4:	00035440 */ 	sll	$t2,$v1,0x11
/*  f13abf8:	000a1f82 */ 	srl	$v1,$t2,0x1e
/*  f13abfc:	306b0001 */ 	andi	$t3,$v1,0x1
/*  f13ac00:	11610018 */ 	beq	$t3,$at,.L0f13ac64
/*  f13ac04:	00000000 */ 	nop
/*  f13ac08:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f13ac0c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13ac10:	00c01025 */ 	or	$v0,$a2,$zero
/*  f13ac14:	32ac0001 */ 	andi	$t4,$s5,0x1
/*  f13ac18:	46143582 */ 	mul.s	$f22,$f6,$f20
/*  f13ac1c:	10c10007 */ 	beq	$a2,$at,.L0f13ac3c
/*  f13ac20:	24010002 */ 	addiu	$at,$zero,0x2
/*  f13ac24:	10410003 */ 	beq	$v0,$at,.L0f13ac34
/*  f13ac28:	24010007 */ 	addiu	$at,$zero,0x7
/*  f13ac2c:	14410006 */ 	bne	$v0,$at,.L0f13ac48
/*  f13ac30:	00000000 */ 	nop
.L0f13ac34:
/*  f13ac34:	10000004 */ 	b	.L0f13ac48
/*  f13ac38:	00002025 */ 	or	$a0,$zero,$zero
.L0f13ac3c:
/*  f13ac3c:	15800002 */ 	bnez	$t4,.L0f13ac48
/*  f13ac40:	00000000 */ 	nop
/*  f13ac44:	00002025 */ 	or	$a0,$zero,$zero
.L0f13ac48:
/*  f13ac48:	5460000a */ 	bnezl	$v1,.L0f13ac74
/*  f13ac4c:	24d9fffe */ 	addiu	$t9,$a2,-2
/*  f13ac50:	50800008 */ 	beqzl	$a0,.L0f13ac74
/*  f13ac54:	24d9fffe */ 	addiu	$t9,$a2,-2
/*  f13ac58:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f13ac5c:	10000004 */ 	b	.L0f13ac70
/*  f13ac60:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f13ac64:
/*  f13ac64:	10000002 */ 	b	.L0f13ac70
/*  f13ac68:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f13ac6c:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f13ac70:
/*  f13ac70:	24d9fffe */ 	addiu	$t9,$a2,-2
.L0f13ac74:
/*  f13ac74:	2f21000a */ 	sltiu	$at,$t9,0xa
/*  f13ac78:	1020000b */ 	beqz	$at,.L0f13aca8
/*  f13ac7c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f13ac80:	3c017f1b */ 	lui	$at,%hi(var7f1b5904)
/*  f13ac84:	00390821 */ 	addu	$at,$at,$t9
/*  f13ac88:	8c395904 */ 	lw	$t9,%lo(var7f1b5904)($at)
/*  f13ac8c:	03200008 */ 	jr	$t9
/*  f13ac90:	00000000 */ 	nop
/*  f13ac94:	10000004 */ 	b	.L0f13aca8
/*  f13ac98:	00008025 */ 	or	$s0,$zero,$zero
/*  f13ac9c:	10000002 */ 	b	.L0f13aca8
/*  f13aca0:	24100002 */ 	addiu	$s0,$zero,0x2
/*  f13aca4:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f13aca8:
/*  f13aca8:	50e0002c */ 	beqzl	$a3,.L0f13ad5c
/*  f13acac:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f13acb0:	0c004b70 */ 	jal	random
/*  f13acb4:	00000000 */ 	nop
/*  f13acb8:	3c0d800a */ 	lui	$t5,%hi(g_CreditsData)
/*  f13acbc:	8dad4170 */ 	lw	$t5,%lo(g_CreditsData)($t5)
/*  f13acc0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13acc4:	91af419c */ 	lbu	$t7,0x419c($t5)
/*  f13acc8:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f13accc:	0058001b */ 	divu	$zero,$v0,$t8
/*  f13acd0:	00005010 */ 	mfhi	$t2
/*  f13acd4:	17000002 */ 	bnez	$t8,.L0f13ace0
/*  f13acd8:	00000000 */ 	nop
/*  f13acdc:	0007000d */ 	break	0x7
.L0f13ace0:
/*  f13ace0:	5541001e */ 	bnel	$t2,$at,.L0f13ad5c
/*  f13ace4:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f13ace8:	0c004b70 */ 	jal	random
/*  f13acec:	00000000 */ 	nop
/*  f13acf0:	44824000 */ 	mtc1	$v0,$f8
/*  f13acf4:	3c014f80 */ 	lui	$at,0x4f80
/*  f13acf8:	04410004 */ 	bgez	$v0,.L0f13ad0c
/*  f13acfc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f13ad00:	44819000 */ 	mtc1	$at,$f18
/*  f13ad04:	00000000 */ 	nop
/*  f13ad08:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f13ad0c:
/*  f13ad0c:	3c012f80 */ 	lui	$at,0x2f80
/*  f13ad10:	44812000 */ 	mtc1	$at,$f4
/*  f13ad14:	3c017f1b */ 	lui	$at,%hi(var7f1b592c)
/*  f13ad18:	c428592c */ 	lwc1	$f8,%lo(var7f1b592c)($at)
/*  f13ad1c:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f13ad20:	00000000 */ 	nop
/*  f13ad24:	46083582 */ 	mul.s	$f22,$f6,$f8
/*  f13ad28:	0c004b70 */ 	jal	random
/*  f13ad2c:	00000000 */ 	nop
/*  f13ad30:	24010003 */ 	addiu	$at,$zero,0x3
/*  f13ad34:	0041001b */ 	divu	$zero,$v0,$at
/*  f13ad38:	00008010 */ 	mfhi	$s0
/*  f13ad3c:	0c004b70 */ 	jal	random
/*  f13ad40:	00000000 */ 	nop
/*  f13ad44:	24010003 */ 	addiu	$at,$zero,0x3
/*  f13ad48:	0041001b */ 	divu	$zero,$v0,$at
/*  f13ad4c:	00008810 */ 	mfhi	$s1
/*  f13ad50:	00000000 */ 	nop
/*  f13ad54:	00000000 */ 	nop
/*  f13ad58:	8fab0084 */ 	lw	$t3,0x84($sp)
.L0f13ad5c:
/*  f13ad5c:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f13ad60:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f13ad64:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f13ad68:	8e850000 */ 	lw	$a1,0x0($s4)
/*  f13ad6c:	8ee70000 */ 	lw	$a3,0x0($s7)
/*  f13ad70:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f13ad74:	8f2d0000 */ 	lw	$t5,0x0($t9)
/*  f13ad78:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f13ad7c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f13ad80:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f13ad84:	e7b60018 */ 	swc1	$f22,0x18($sp)
/*  f13ad88:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f13ad8c:	01d33021 */ 	addu	$a2,$t6,$s3
/*  f13ad90:	0fc4e767 */ 	jal	func0f139d9c
/*  f13ad94:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f13ad98:	3c04800a */ 	lui	$a0,%hi(g_CreditsData)
/*  f13ad9c:	8c844170 */ 	lw	$a0,%lo(g_CreditsData)($a0)
/*  f13ada0:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f13ada4:	9086419c */ 	lbu	$a2,0x419c($a0)
/*  f13ada8:	00067840 */ 	sll	$t7,$a2,0x1
/*  f13adac:	01e03025 */ 	or	$a2,$t7,$zero
/*  f13adb0:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f13adb4:
/*  f13adb4:	02a6082a */ 	slt	$at,$s5,$a2
/*  f13adb8:	1420ff25 */ 	bnez	$at,.L0f13aa50
/*  f13adbc:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f13adc0:
/*  f13adc0:	0fc54de0 */ 	jal	func0f153780
/*  f13adc4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.L0f13adc8:
/*  f13adc8:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f13adcc:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f13add0:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f13add4:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f13add8:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f13addc:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f13ade0:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f13ade4:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f13ade8:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f13adec:	8fb5005c */ 	lw	$s5,0x5c($sp)
/*  f13adf0:	8fb60060 */ 	lw	$s6,0x60($sp)
/*  f13adf4:	8fb70064 */ 	lw	$s7,0x64($sp)
/*  f13adf8:	8fbe0068 */ 	lw	$s8,0x68($sp)
/*  f13adfc:	03e00008 */ 	jr	$ra
/*  f13ae00:	27bd01e8 */ 	addiu	$sp,$sp,0x1e8
);
#endif

GLOBAL_ASM(
glabel func0f13ae04
/*  f13ae04:	03e00008 */ 	jr	$ra
/*  f13ae08:	afa40000 */ 	sw	$a0,0x0($sp)
);

#if VERSION >= VERSION_NTSC_1_0
void creditsTick(void)
{
	s32 i;
	static u32 var8007f6d8 = 0xffff;

	if (joyGetButtonsPressedThisFrame(0, L_TRIG)) {
		creditsCreatePendingBgLayers(0xffffffff);
	}

	func0000db30("for", &var8007f6d8);

	if (var8007f6d8 < 0xffff) {
		for (i = 0; i < 4; i++) {
			g_CreditsData->bglayers[i].type = var8007f6d8;
		}
	}

	func0000db30("flick", &var8007f6d4);

	if (var8007f6d4 != 0) {
		creditsCreatePendingBgLayers(0xffffffff);
		var8007f6d4 = 0;
	}

	if (var800a416c == 0) {
		if (g_CreditsUsingAltTitle) {
			musicSetStage(STAGE_CREDITS);
			musicStartPrimary(0);
		} else {
			musicSetStage(STAGE_CREDITS);
			musicStartMenu2(MUSIC_CREDITS);
		}
	}

	var800a4168 = var800a4164;
	var800a4164 += g_Vars.diffframe240;
	var800a416c += g_Vars.diffframe240;
	var800a4160 = (var800a416c % PALDOWN(4800)) / PALDOWN(4800.0f);

	func0f13899c();

	if (g_CreditsData->slidesenabled) {
		creditsTickSlide();
	} else if (random() * (1.0f / U32_MAX) < 0.01f && !joyGetButtons(0, L_TRIG | R_TRIG)) {
		creditsCreatePendingBgLayers(0xffffffff);
	}

	if (!g_CreditsData->slidesenabled && g_CreditsData->unk4204 < (PAL ? 1150 : 1360)) {
		g_CreditsData->unk4204 += g_Vars.diffframe60;
	}
}
#else
const char var7f1afd10nb[] = "for";
const char var7f1afd14nb[] = "flick";

GLOBAL_ASM(
glabel creditsTick
.late_rodata
glabel var7f1afe70nb
.word 0x3c23d70a
.text
/*  f135914:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f135918:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f13591c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f135920:	3c058008 */ 	lui	$a1,0x8008
/*  f135924:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f135928:	24a51f2c */ 	addiu	$a1,$a1,0x1f2c
/*  f13592c:	0c00381c */ 	jal	func0000db30
/*  f135930:	2484fd10 */ 	addiu	$a0,$a0,-752
/*  f135934:	3c0e8008 */ 	lui	$t6,0x8008
/*  f135938:	8dce1f2c */ 	lw	$t6,0x1f2c($t6)
/*  f13593c:	3401ffff */ 	dli	$at,0xffff
/*  f135940:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f135944:	01c1082b */ 	sltu	$at,$t6,$at
/*  f135948:	1020000c */ 	beqz	$at,.NB0f13597c
/*  f13594c:	2484fd14 */ 	addiu	$a0,$a0,-748
/*  f135950:	3c10800b */ 	lui	$s0,0x800b
/*  f135954:	26108730 */ 	addiu	$s0,$s0,-30928
/*  f135958:	00001025 */ 	or	$v0,$zero,$zero
/*  f13595c:	24030040 */ 	addiu	$v1,$zero,0x40
.NB0f135960:
/*  f135960:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f135964:	3c0f8008 */ 	lui	$t7,0x8008
/*  f135968:	8def1f2c */ 	lw	$t7,0x1f2c($t7)
/*  f13596c:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f135970:	24420010 */ 	addiu	$v0,$v0,0x10
/*  f135974:	1443fffa */ 	bne	$v0,$v1,.NB0f135960
/*  f135978:	af2f41b4 */ 	sw	$t7,0x41b4($t9)
.NB0f13597c:
/*  f13597c:	3c10800b */ 	lui	$s0,0x800b
/*  f135980:	3c058008 */ 	lui	$a1,0x8008
/*  f135984:	26108730 */ 	addiu	$s0,$s0,-30928
/*  f135988:	0c00381c */ 	jal	func0000db30
/*  f13598c:	24a51f28 */ 	addiu	$a1,$a1,0x1f28
/*  f135990:	3c088008 */ 	lui	$t0,0x8008
/*  f135994:	8d081f28 */ 	lw	$t0,0x1f28($t0)
/*  f135998:	11000005 */ 	beqz	$t0,.NB0f1359b0
/*  f13599c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1359a0:	0fc4cbc7 */ 	jal	creditsCreatePendingBgLayers
/*  f1359a4:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f1359a8:	3c018008 */ 	lui	$at,0x8008
/*  f1359ac:	ac201f28 */ 	sw	$zero,0x1f28($at)
.NB0f1359b0:
/*  f1359b0:	3c09800b */ 	lui	$t1,0x800b
/*  f1359b4:	8d29872c */ 	lw	$t1,-0x78d4($t1)
/*  f1359b8:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1359bc:	55200010 */ 	bnezl	$t1,.NB0f135a00
/*  f1359c0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1359c4:	8d4a1998 */ 	lw	$t2,0x1998($t2)
/*  f1359c8:	11400008 */ 	beqz	$t2,.NB0f1359ec
/*  f1359cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1359d0:	0fc5a1ab */ 	jal	musicSetStage
/*  f1359d4:	2404005c */ 	addiu	$a0,$zero,0x5c
/*  f1359d8:	44806000 */ 	mtc1	$zero,$f12
/*  f1359dc:	0fc5a063 */ 	jal	musicStartPrimary
/*  f1359e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1359e4:	10000006 */ 	beqz	$zero,.NB0f135a00
/*  f1359e8:	00002025 */ 	or	$a0,$zero,$zero
.NB0f1359ec:
/*  f1359ec:	0fc5a1ab */ 	jal	musicSetStage
/*  f1359f0:	2404005c */ 	addiu	$a0,$zero,0x5c
/*  f1359f4:	0fc5a176 */ 	jal	musicStartMenu2
/*  f1359f8:	24040058 */ 	addiu	$a0,$zero,0x58
/*  f1359fc:	00002025 */ 	or	$a0,$zero,$zero
.NB0f135a00:
/*  f135a00:	0c005790 */ 	jal	joyGetButtons
/*  f135a04:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f135a08:	1440000f */ 	bnez	$v0,.NB0f135a48
/*  f135a0c:	24052000 */ 	addiu	$a1,$zero,0x2000
/*  f135a10:	3c04800b */ 	lui	$a0,0x800b
/*  f135a14:	24848724 */ 	addiu	$a0,$a0,-30940
/*  f135a18:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f135a1c:	3c03800a */ 	lui	$v1,0x800a
/*  f135a20:	8c63e700 */ 	lw	$v1,-0x1900($v1)
/*  f135a24:	3c01800b */ 	lui	$at,0x800b
/*  f135a28:	ac228728 */ 	sw	$v0,-0x78d8($at)
/*  f135a2c:	00435821 */ 	addu	$t3,$v0,$v1
/*  f135a30:	ac8b0000 */ 	sw	$t3,0x0($a0)
/*  f135a34:	3c0c800b */ 	lui	$t4,0x800b
/*  f135a38:	8d8c872c */ 	lw	$t4,-0x78d4($t4)
/*  f135a3c:	3c01800b */ 	lui	$at,0x800b
/*  f135a40:	01836821 */ 	addu	$t5,$t4,$v1
/*  f135a44:	ac2d872c */ 	sw	$t5,-0x78d4($at)
.NB0f135a48:
/*  f135a48:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*  f135a4c:	00002025 */ 	or	$a0,$zero,$zero
/*  f135a50:	3c0e800b */ 	lui	$t6,0x800b
/*  f135a54:	8dce872c */ 	lw	$t6,-0x78d4($t6)
/*  f135a58:	240112c0 */ 	addiu	$at,$zero,0x12c0
/*  f135a5c:	01c1001b */ 	divu	$zero,$t6,$at
/*  f135a60:	0000c010 */ 	mfhi	$t8
/*  f135a64:	44982000 */ 	mtc1	$t8,$f4
/*  f135a68:	3c014f80 */ 	lui	$at,0x4f80
/*  f135a6c:	07010004 */ 	bgez	$t8,.NB0f135a80
/*  f135a70:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f135a74:	44814000 */ 	mtc1	$at,$f8
/*  f135a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135a7c:	46083180 */ 	add.s	$f6,$f6,$f8
.NB0f135a80:
/*  f135a80:	3c014596 */ 	lui	$at,0x4596
/*  f135a84:	44815000 */ 	mtc1	$at,$f10
/*  f135a88:	3c01800b */ 	lui	$at,0x800b
/*  f135a8c:	00002025 */ 	or	$a0,$zero,$zero
/*  f135a90:	460a3403 */ 	div.s	$f16,$f6,$f10
/*  f135a94:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f135a98:	0c005790 */ 	jal	joyGetButtons
/*  f135a9c:	e4308720 */ 	swc1	$f16,-0x78e0($at)
/*  f135aa0:	5440002c */ 	bnezl	$v0,.NB0f135b54
/*  f135aa4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f135aa8:	0fc4cd4b */ 	jal	func0f13899c
/*  f135aac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135ab0:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f135ab4:	91f941f4 */ 	lbu	$t9,0x41f4($t7)
/*  f135ab8:	13200005 */ 	beqz	$t9,.NB0f135ad0
/*  f135abc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135ac0:	0fc4d31b */ 	jal	creditsTickSlide
/*  f135ac4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135ac8:	10000016 */ 	beqz	$zero,.NB0f135b24
/*  f135acc:	8e020000 */ 	lw	$v0,0x0($s0)
.NB0f135ad0:
/*  f135ad0:	0c004d84 */ 	jal	random
/*  f135ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135ad8:	44829000 */ 	mtc1	$v0,$f18
/*  f135adc:	3c014f80 */ 	lui	$at,0x4f80
/*  f135ae0:	04410004 */ 	bgez	$v0,.NB0f135af4
/*  f135ae4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f135ae8:	44814000 */ 	mtc1	$at,$f8
/*  f135aec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135af0:	46082100 */ 	add.s	$f4,$f4,$f8
.NB0f135af4:
/*  f135af4:	3c012f80 */ 	lui	$at,0x2f80
/*  f135af8:	44813000 */ 	mtc1	$at,$f6
/*  f135afc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f135b00:	c430fe70 */ 	lwc1	$f16,-0x190($at)
/*  f135b04:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f135b08:	4610503c */ 	c.lt.s	$f10,$f16
/*  f135b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f135b10:	45020004 */ 	bc1fl	.NB0f135b24
/*  f135b14:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f135b18:	0fc4cbc7 */ 	jal	creditsCreatePendingBgLayers
/*  f135b1c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f135b20:	8e020000 */ 	lw	$v0,0x0($s0)
.NB0f135b24:
/*  f135b24:	904841f4 */ 	lbu	$t0,0x41f4($v0)
/*  f135b28:	5500000a */ 	bnezl	$t0,.NB0f135b54
/*  f135b2c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f135b30:	8c434204 */ 	lw	$v1,0x4204($v0)
/*  f135b34:	3c09800a */ 	lui	$t1,0x800a
/*  f135b38:	2c610550 */ 	sltiu	$at,$v1,0x550
/*  f135b3c:	50200005 */ 	beqzl	$at,.NB0f135b54
/*  f135b40:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f135b44:	8d29e6c0 */ 	lw	$t1,-0x1940($t1)
/*  f135b48:	00695021 */ 	addu	$t2,$v1,$t1
/*  f135b4c:	ac4a4204 */ 	sw	$t2,0x4204($v0)
/*  f135b50:	8fbf001c */ 	lw	$ra,0x1c($sp)
.NB0f135b54:
/*  f135b54:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f135b58:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f135b5c:	03e00008 */ 	jr	$ra
/*  f135b60:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

u32 var8007f6dc = 0;

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel creditsRender
.late_rodata
glabel var7f1b5934
.word 0xbe86051b
glabel var8f1b6c5c
.word 0x463b8000
glabel var7f1b5938
.word 0x4516d000
glabel var7f1b593c
.word 0x44504000
glabel var7f1b5940
.word 0x4283b852
glabel var7f1b5944
.word 0xc5002000
glabel var7f1b5948
.word 0x3fbbc6a8
.text
/*  f13bbc8:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f13bbcc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f13bbd0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f13bbd4:	0fc5a246 */ 	jal	gfxAllocateMatrix
/*  f13bbd8:	00808025 */ 	move	$s0,$a0
/*  f13bbdc:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f13bbe0:	0fc54fa3 */ 	jal	func0f1531dc
/*  f13bbe4:	00002025 */ 	move	$a0,$zero
/*  f13bbe8:	240e0001 */ 	li	$t6,0x1
/*  f13bbec:	3c018008 */ 	lui	$at,0x8008
/*  f13bbf0:	ac2e0020 */ 	sw	$t6,0x20($at)
/*  f13bbf4:	0c002bf1 */ 	jal	func0000b280
/*  f13bbf8:	02002025 */ 	move	$a0,$s0
/*  f13bbfc:	0c002bc5 */ 	jal	func0000b1d0
/*  f13bc00:	00402025 */ 	move	$a0,$v0
/*  f13bc04:	00402025 */ 	move	$a0,$v0
/*  f13bc08:	0fc4e40d */ 	jal	creditsClearFramebuffer
/*  f13bc0c:	240500ff */ 	li	$a1,0xff
/*  f13bc10:	3c0fed00 */ 	lui	$t7,0xed00
/*  f13bc14:	35ef0078 */ 	ori	$t7,$t7,0x78
/*  f13bc18:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f13bc1c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f13bc20:	0c002e53 */ 	jal	viGetWidth
/*  f13bc24:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f13bc28:	0c002e57 */ 	jal	viGetHeight
/*  f13bc2c:	a7a20036 */ 	sh	$v0,0x36($sp)
/*  f13bc30:	2458ffe2 */ 	addiu	$t8,$v0,-30
/*  f13bc34:	44982000 */ 	mtc1	$t8,$f4
/*  f13bc38:	87aa0036 */ 	lh	$t2,0x36($sp)
/*  f13bc3c:	3c014080 */ 	lui	$at,0x4080
/*  f13bc40:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13bc44:	448a8000 */ 	mtc1	$t2,$f16
/*  f13bc48:	44810000 */ 	mtc1	$at,$f0
/*  f13bc4c:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f13bc50:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f13bc54:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f13bc58:	00000000 */ 	nop
/*  f13bc5c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f13bc60:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f13bc64:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f13bc68:	44085000 */ 	mfc1	$t0,$f10
/*  f13bc6c:	440c3000 */ 	mfc1	$t4,$f6
/*  f13bc70:	31090fff */ 	andi	$t1,$t0,0xfff
/*  f13bc74:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f13bc78:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f13bc7c:	012e7825 */ 	or	$t7,$t1,$t6
/*  f13bc80:	0fc4ee5c */ 	jal	creditsTick
/*  f13bc84:	af0f0004 */ 	sw	$t7,0x4($t8)
/*  f13bc88:	3c07800a */ 	lui	$a3,0x800a
/*  f13bc8c:	24e74710 */ 	addiu	$a3,$a3,0x4710
/*  f13bc90:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f13bc94:	906441f4 */ 	lbu	$a0,0x41f4($v1)
/*  f13bc98:	14800007 */ 	bnez	$a0,.PF0f13bcb8
/*  f13bc9c:	00000000 */ 	nop
/*  f13bca0:	8c624204 */ 	lw	$v0,0x4204($v1)
/*  f13bca4:	2c410032 */ 	sltiu	$at,$v0,0x32
/*  f13bca8:	14200003 */ 	bnez	$at,.PF0f13bcb8
/*  f13bcac:	2c4103e9 */ 	sltiu	$at,$v0,0x3e9
/*  f13bcb0:	142000bd */ 	bnez	$at,.PF0f13bfa8
/*  f13bcb4:	00000000 */ 	nop
.PF0f13bcb8:
/*  f13bcb8:	14800066 */ 	bnez	$a0,.PF0f13be54
/*  f13bcbc:	00000000 */ 	nop
/*  f13bcc0:	8c794204 */ 	lw	$t9,0x4204($v1)
/*  f13bcc4:	3c058008 */ 	lui	$a1,0x8008
/*  f13bcc8:	24a5f600 */ 	addiu	$a1,$a1,-2560
/*  f13bccc:	2f2103e9 */ 	sltiu	$at,$t9,0x3e9
/*  f13bcd0:	14200060 */ 	bnez	$at,.PF0f13be54
/*  f13bcd4:	00000000 */ 	nop
/*  f13bcd8:	8ca80000 */ 	lw	$t0,0x0($a1)
/*  f13bcdc:	240a0001 */ 	li	$t2,0x1
/*  f13bce0:	24642ef0 */ 	addiu	$a0,$v1,0x2ef0
/*  f13bce4:	15000007 */ 	bnez	$t0,.PF0f13bd04
/*  f13bce8:	3c018008 */ 	lui	$at,0x8008
/*  f13bcec:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f13bcf0:	0fc3cfbe */ 	jal	func0f0f37a4
/*  f13bcf4:	ac20fc3c */ 	sw	$zero,-0x3c4($at)
/*  f13bcf8:	3c07800a */ 	lui	$a3,0x800a
/*  f13bcfc:	24e74710 */ 	addiu	$a3,$a3,0x4710
/*  f13bd00:	8ce30000 */ 	lw	$v1,0x0($a3)
.PF0f13bd04:
/*  f13bd04:	3c028008 */ 	lui	$v0,0x8008
/*  f13bd08:	3c0b800a */ 	lui	$t3,0x800a
/*  f13bd0c:	8c42fc3c */ 	lw	$v0,-0x3c4($v0)
/*  f13bd10:	8d6ba550 */ 	lw	$t3,-0x5ab0($t3)
/*  f13bd14:	44800000 */ 	mtc1	$zero,$f0
/*  f13bd18:	004b1021 */ 	addu	$v0,$v0,$t3
/*  f13bd1c:	2c412ee1 */ 	sltiu	$at,$v0,0x2ee1
/*  f13bd20:	54200003 */ 	bnezl	$at,.PF0f13bd30
/*  f13bd24:	e460343c */ 	swc1	$f0,0x343c($v1)
/*  f13bd28:	00001025 */ 	move	$v0,$zero
/*  f13bd2c:	e460343c */ 	swc1	$f0,0x343c($v1)
.PF0f13bd30:
/*  f13bd30:	8cec0000 */ 	lw	$t4,0x0($a3)
/*  f13bd34:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13bd38:	44829000 */ 	mtc1	$v0,$f18
/*  f13bd3c:	e5803414 */ 	swc1	$f0,0x3414($t4)
/*  f13bd40:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f13bd44:	c4286c58 */ 	lwc1	$f8,0x6c58($at)
/*  f13bd48:	3c014f80 */ 	lui	$at,0x4f80
/*  f13bd4c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f13bd50:	e5a83438 */ 	swc1	$f8,0x3438($t5)
/*  f13bd54:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f13bd58:	c46a3438 */ 	lwc1	$f10,0x3438($v1)
/*  f13bd5c:	e46a3410 */ 	swc1	$f10,0x3410($v1)
/*  f13bd60:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f13bd64:	e5203440 */ 	swc1	$f0,0x3440($t1)
/*  f13bd68:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f13bd6c:	c4703440 */ 	lwc1	$f16,0x3440($v1)
/*  f13bd70:	04410004 */ 	bgez	$v0,.PF0f13bd84
/*  f13bd74:	e4703418 */ 	swc1	$f16,0x3418($v1)
/*  f13bd78:	44813000 */ 	mtc1	$at,$f6
/*  f13bd7c:	00000000 */ 	nop
/*  f13bd80:	46062100 */ 	add.s	$f4,$f4,$f6
.PF0f13bd84:
/*  f13bd84:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13bd88:	c4286c5c */ 	lwc1	$f8,0x6c5c($at)
/*  f13bd8c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13bd90:	c4306c60 */ 	lwc1	$f16,0x6c60($at)
/*  f13bd94:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f13bd98:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13bd9c:	c4266c64 */ 	lwc1	$f6,0x6c64($at)
/*  f13bda0:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f13bda4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13bda8:	240804b0 */ 	li	$t0,0x4b0
/*  f13bdac:	02002025 */ 	move	$a0,$s0
/*  f13bdb0:	24060004 */ 	li	$a2,0x4
/*  f13bdb4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f13bdb8:	46123101 */ 	sub.s	$f4,$f6,$f18
/*  f13bdbc:	e5c43428 */ 	swc1	$f4,0x3428($t6)
/*  f13bdc0:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f13bdc4:	c4286c68 */ 	lwc1	$f8,0x6c68($at)
/*  f13bdc8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13bdcc:	e5e8342c */ 	swc1	$f8,0x342c($t7)
/*  f13bdd0:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f13bdd4:	c42a6c6c */ 	lwc1	$f10,0x6c6c($at)
/*  f13bdd8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13bddc:	e70a3430 */ 	swc1	$f10,0x3430($t8)
/*  f13bde0:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f13bde4:	c4306c70 */ 	lwc1	$f16,0x6c70($at)
/*  f13bde8:	3c018008 */ 	lui	$at,0x8008
/*  f13bdec:	e7303434 */ 	swc1	$f16,0x3434($t9)
/*  f13bdf0:	8cea0000 */ 	lw	$t2,0x0($a3)
/*  f13bdf4:	ad482efc */ 	sw	$t0,0x2efc($t2)
/*  f13bdf8:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f13bdfc:	906c34a1 */ 	lbu	$t4,0x34a1($v1)
/*  f13be00:	358d0002 */ 	ori	$t5,$t4,0x2
/*  f13be04:	a06d34a1 */ 	sb	$t5,0x34a1($v1)
/*  f13be08:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f13be0c:	ad2034a4 */ 	sw	$zero,0x34a4($t1)
/*  f13be10:	8ce50000 */ 	lw	$a1,0x0($a3)
/*  f13be14:	ac22fc3c */ 	sw	$v0,-0x3c4($at)
/*  f13be18:	0fc3d001 */ 	jal	func0f0f38b0
/*  f13be1c:	24a52ef0 */ 	addiu	$a1,$a1,0x2ef0
/*  f13be20:	3c0e0102 */ 	lui	$t6,0x102
/*  f13be24:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f13be28:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f13be2c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f13be30:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f13be34:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f13be38:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f13be3c:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f13be40:	02002025 */ 	move	$a0,$s0
/*  f13be44:	240500d8 */ 	li	$a1,0xd8
/*  f13be48:	0fc4e40d */ 	jal	creditsClearFramebuffer
/*  f13be4c:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f13be50:	00408025 */ 	move	$s0,$v0
.PF0f13be54:
/*  f13be54:	0c0055d0 */ 	jal	func000159b0
/*  f13be58:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f13be5c:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f13be60:	0c005779 */ 	jal	func00016054
/*  f13be64:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f13be68:	0fc2d54e */ 	jal	currentPlayerSetMatrix1740
/*  f13be6c:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f13be70:	3c180102 */ 	lui	$t8,0x102
/*  f13be74:	37180040 */ 	ori	$t8,$t8,0x40
/*  f13be78:	02001825 */ 	move	$v1,$s0
/*  f13be7c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f13be80:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f13be84:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f13be88:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f13be8c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f13be90:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f13be94:	3c01c47a */ 	lui	$at,0xc47a
/*  f13be98:	44810000 */ 	mtc1	$at,$f0
/*  f13be9c:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f13bea0:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f13bea4:	44803000 */ 	mtc1	$zero,$f6
/*  f13bea8:	44809000 */ 	mtc1	$zero,$f18
/*  f13beac:	44812000 */ 	mtc1	$at,$f4
/*  f13beb0:	02002025 */ 	move	$a0,$s0
/*  f13beb4:	e7a00058 */ 	swc1	$f0,0x58($sp)
/*  f13beb8:	e7a0005c */ 	swc1	$f0,0x5c($sp)
/*  f13bebc:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f13bec0:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f13bec4:	e7b20050 */ 	swc1	$f18,0x50($sp)
/*  f13bec8:	0fc4e2a9 */ 	jal	creditsRenderBackground
/*  f13becc:	e7a40054 */ 	swc1	$f4,0x54($sp)
/*  f13bed0:	0fc4e784 */ 	jal	creditsRenderSprites
/*  f13bed4:	00402025 */ 	move	$a0,$v0
/*  f13bed8:	3c07800a */ 	lui	$a3,0x800a
/*  f13bedc:	24e74710 */ 	addiu	$a3,$a3,0x4710
/*  f13bee0:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f13bee4:	00408025 */ 	move	$s0,$v0
/*  f13bee8:	906441f4 */ 	lbu	$a0,0x41f4($v1)
/*  f13beec:	10800009 */ 	beqz	$a0,.PF0f13bf14
/*  f13bef0:	00000000 */ 	nop
/*  f13bef4:	0fc3534f */ 	jal	func0f0d479c
/*  f13bef8:	00402025 */ 	move	$a0,$v0
/*  f13befc:	0fc4ebdb */ 	jal	func0f13a3ec
/*  f13bf00:	00402025 */ 	move	$a0,$v0
/*  f13bf04:	3c03800a */ 	lui	$v1,0x800a
/*  f13bf08:	8c634710 */ 	lw	$v1,0x4710($v1)
/*  f13bf0c:	00408025 */ 	move	$s0,$v0
/*  f13bf10:	906441f4 */ 	lbu	$a0,0x41f4($v1)
.PF0f13bf14:
/*  f13bf14:	14800024 */ 	bnez	$a0,.PF0f13bfa8
/*  f13bf18:	00000000 */ 	nop
/*  f13bf1c:	8c624204 */ 	lw	$v0,0x4204($v1)
/*  f13bf20:	00002825 */ 	move	$a1,$zero
/*  f13bf24:	240300ff */ 	li	$v1,0xff
/*  f13bf28:	2c410032 */ 	sltiu	$at,$v0,0x32
/*  f13bf2c:	5020000b */ 	beqzl	$at,.PF0f13bf5c
/*  f13bf30:	2c4103e9 */ 	sltiu	$at,$v0,0x3e9
/*  f13bf34:	00430019 */ 	multu	$v0,$v1
/*  f13bf38:	24010032 */ 	li	$at,0x32
/*  f13bf3c:	00002812 */ 	mflo	$a1
/*  f13bf40:	00000000 */ 	nop
/*  f13bf44:	00000000 */ 	nop
/*  f13bf48:	00a1001b */ 	divu	$zero,$a1,$at
/*  f13bf4c:	00002812 */ 	mflo	$a1
/*  f13bf50:	00000000 */ 	nop
/*  f13bf54:	00000000 */ 	nop
/*  f13bf58:	2c4103e9 */ 	sltiu	$at,$v0,0x3e9
.PF0f13bf5c:
/*  f13bf5c:	1420000d */ 	bnez	$at,.PF0f13bf94
/*  f13bf60:	240300ff */ 	li	$v1,0xff
/*  f13bf64:	2c41041a */ 	sltiu	$at,$v0,0x41a
/*  f13bf68:	1020000a */ 	beqz	$at,.PF0f13bf94
/*  f13bf6c:	2448fc18 */ 	addiu	$t0,$v0,-1000
/*  f13bf70:	01030019 */ 	multu	$t0,$v1
/*  f13bf74:	24010032 */ 	li	$at,0x32
/*  f13bf78:	00005012 */ 	mflo	$t2
/*  f13bf7c:	00000000 */ 	nop
/*  f13bf80:	00000000 */ 	nop
/*  f13bf84:	0141001b */ 	divu	$zero,$t2,$at
/*  f13bf88:	00005812 */ 	mflo	$t3
/*  f13bf8c:	006b2823 */ 	subu	$a1,$v1,$t3
/*  f13bf90:	00000000 */ 	nop
.PF0f13bf94:
/*  f13bf94:	10a00004 */ 	beqz	$a1,.PF0f13bfa8
/*  f13bf98:	00000000 */ 	nop
/*  f13bf9c:	0fc4e40d */ 	jal	creditsClearFramebuffer
/*  f13bfa0:	02002025 */ 	move	$a0,$s0
/*  f13bfa4:	00408025 */ 	move	$s0,$v0
.PF0f13bfa8:
/*  f13bfa8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f13bfac:	8d8cf608 */ 	lw	$t4,-0x9f8($t4)
/*  f13bfb0:	00002025 */ 	move	$a0,$zero
/*  f13bfb4:	51800018 */ 	beqzl	$t4,.PF0f13c018
/*  f13bfb8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f13bfbc:	0c00536a */ 	jal	joyGetButtonsPressedThisFrame
/*  f13bfc0:	3405ffcf */ 	li	$a1,0xffcf
/*  f13bfc4:	10400013 */ 	beqz	$v0,.PF0f13c014
/*  f13bfc8:	240d0026 */ 	li	$t5,0x26
/*  f13bfcc:	3c018006 */ 	lui	$at,0x8006
/*  f13bfd0:	ac2d21b4 */ 	sw	$t5,0x21b4($at)
/*  f13bfd4:	0fc0690e */ 	jal	setNumPlayers
/*  f13bfd8:	24040001 */ 	li	$a0,0x1
/*  f13bfdc:	3c048006 */ 	lui	$a0,0x8006
/*  f13bfe0:	0c0039af */ 	jal	mainSetStageNum
/*  f13bfe4:	8c8421b4 */ 	lw	$a0,0x21b4($a0)
/*  f13bfe8:	3c01800a */ 	lui	$at,0x800a
/*  f13bfec:	ac20a7a4 */ 	sw	$zero,-0x585c($at)
/*  f13bff0:	2402ffff */ 	li	$v0,-1
/*  f13bff4:	3c01800a */ 	lui	$at,0x800a
/*  f13bff8:	ac22a7a8 */ 	sw	$v0,-0x5858($at)
/*  f13bffc:	3c01800a */ 	lui	$at,0x800a
/*  f13c000:	ac22a7ac */ 	sw	$v0,-0x5854($at)
/*  f13c004:	0fc5b6fd */ 	jal	lvSetDifficulty
/*  f13c008:	00002025 */ 	move	$a0,$zero
/*  f13c00c:	0c002779 */ 	jal	func00009ec4
/*  f13c010:	24040001 */ 	li	$a0,0x1
.PF0f13c014:
/*  f13c014:	8fbf001c */ 	lw	$ra,0x1c($sp)
.PF0f13c018:
/*  f13c018:	02001025 */ 	move	$v0,$s0
/*  f13c01c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f13c020:	03e00008 */ 	jr	$ra
/*  f13c024:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel creditsRender
.late_rodata
glabel var7f1b5934
.word 0xbe86051b
glabel var7f1b5938
.word 0x4516d000
glabel var7f1b593c
.word 0x44504000
glabel var7f1b5940
.word 0x428db852
glabel var7f1b5944
.word 0xc5002000
glabel var7f1b5948
.word 0x3fbbc6a8
.text
/*  f13b064:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f13b068:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f13b06c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f13b070:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f13b074:	00808025 */ 	or	$s0,$a0,$zero
/*  f13b078:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f13b07c:	0fc54c77 */ 	jal	func0f1531dc
/*  f13b080:	00002025 */ 	or	$a0,$zero,$zero
/*  f13b084:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f13b088:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f13b08c:	ac2efac0 */ 	sw	$t6,%lo(g_ScaleX)($at)
/*  f13b090:	0c002ca0 */ 	jal	func0000b280
/*  f13b094:	02002025 */ 	or	$a0,$s0,$zero
/*  f13b098:	0c002c74 */ 	jal	func0000b1d0
/*  f13b09c:	00402025 */ 	or	$a0,$v0,$zero
/*  f13b0a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f13b0a4:	0fc4e12d */ 	jal	creditsClearFramebuffer
/*  f13b0a8:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f13b0ac:	3c0fed00 */ 	lui	$t7,0xed00
/*  f13b0b0:	35ef0078 */ 	ori	$t7,$t7,0x78
/*  f13b0b4:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f13b0b8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f13b0bc:	0c002f02 */ 	jal	viGetWidth
/*  f13b0c0:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f13b0c4:	0c002f06 */ 	jal	viGetHeight
/*  f13b0c8:	a7a20036 */ 	sh	$v0,0x36($sp)
/*  f13b0cc:	2458ffe2 */ 	addiu	$t8,$v0,-30
/*  f13b0d0:	44982000 */ 	mtc1	$t8,$f4
/*  f13b0d4:	87aa0036 */ 	lh	$t2,0x36($sp)
/*  f13b0d8:	3c014080 */ 	lui	$at,0x4080
/*  f13b0dc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13b0e0:	448a8000 */ 	mtc1	$t2,$f16
/*  f13b0e4:	44810000 */ 	mtc1	$at,$f0
/*  f13b0e8:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f13b0ec:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f13b0f0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f13b0f4:	00000000 */ 	nop
/*  f13b0f8:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f13b0fc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f13b100:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f13b104:	44085000 */ 	mfc1	$t0,$f10
/*  f13b108:	440c3000 */ 	mfc1	$t4,$f6
/*  f13b10c:	31090fff */ 	andi	$t1,$t0,0xfff
/*  f13b110:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f13b114:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f13b118:	012e7825 */ 	or	$t7,$t1,$t6
/*  f13b11c:	0fc4eb83 */ 	jal	creditsTick
/*  f13b120:	af0f0004 */ 	sw	$t7,0x4($t8)
/*  f13b124:	3c07800a */ 	lui	$a3,%hi(g_CreditsData)
/*  f13b128:	24e74170 */ 	addiu	$a3,$a3,%lo(g_CreditsData)
/*  f13b12c:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f13b130:	906441f4 */ 	lbu	$a0,0x41f4($v1)
/*  f13b134:	14800007 */ 	bnez	$a0,.L0f13b154
/*  f13b138:	00000000 */ 	nop
/*  f13b13c:	8c624204 */ 	lw	$v0,0x4204($v1)
/*  f13b140:	2c41003c */ 	sltiu	$at,$v0,0x3c
/*  f13b144:	14200003 */ 	bnez	$at,.L0f13b154
/*  f13b148:	2c4104b1 */ 	sltiu	$at,$v0,0x4b1
/*  f13b14c:	142000bd */ 	bnez	$at,.L0f13b444
/*  f13b150:	00000000 */ 	nop
.L0f13b154:
/*  f13b154:	14800066 */ 	bnez	$a0,.L0f13b2f0
/*  f13b158:	00000000 */ 	nop
/*  f13b15c:	8c794204 */ 	lw	$t9,0x4204($v1)
/*  f13b160:	3c058008 */ 	lui	$a1,%hi(var8007f130)
/*  f13b164:	24a5f130 */ 	addiu	$a1,$a1,%lo(var8007f130)
/*  f13b168:	2f2104b1 */ 	sltiu	$at,$t9,0x4b1
/*  f13b16c:	14200060 */ 	bnez	$at,.L0f13b2f0
/*  f13b170:	00000000 */ 	nop
/*  f13b174:	8ca80000 */ 	lw	$t0,0x0($a1)
/*  f13b178:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f13b17c:	24642ef0 */ 	addiu	$a0,$v1,0x2ef0
/*  f13b180:	15000007 */ 	bnez	$t0,.L0f13b1a0
/*  f13b184:	3c018008 */ 	lui	$at,%hi(var8007f6dc)
/*  f13b188:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f13b18c:	0fc3cde9 */ 	jal	func0f0f37a4
/*  f13b190:	ac20f6dc */ 	sw	$zero,%lo(var8007f6dc)($at)
/*  f13b194:	3c07800a */ 	lui	$a3,%hi(g_CreditsData)
/*  f13b198:	24e74170 */ 	addiu	$a3,$a3,%lo(g_CreditsData)
/*  f13b19c:	8ce30000 */ 	lw	$v1,0x0($a3)
.L0f13b1a0:
/*  f13b1a0:	3c028008 */ 	lui	$v0,%hi(var8007f6dc)
/*  f13b1a4:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x40)
/*  f13b1a8:	8c42f6dc */ 	lw	$v0,%lo(var8007f6dc)($v0)
/*  f13b1ac:	8d6ba000 */ 	lw	$t3,%lo(g_Vars+0x40)($t3)
/*  f13b1b0:	44800000 */ 	mtc1	$zero,$f0
/*  f13b1b4:	004b1021 */ 	addu	$v0,$v0,$t3
/*  f13b1b8:	2c413841 */ 	sltiu	$at,$v0,0x3841
/*  f13b1bc:	54200003 */ 	bnezl	$at,.L0f13b1cc
/*  f13b1c0:	e460343c */ 	swc1	$f0,0x343c($v1)
/*  f13b1c4:	00001025 */ 	or	$v0,$zero,$zero
/*  f13b1c8:	e460343c */ 	swc1	$f0,0x343c($v1)
.L0f13b1cc:
/*  f13b1cc:	8cec0000 */ 	lw	$t4,0x0($a3)
/*  f13b1d0:	3c017f1b */ 	lui	$at,%hi(var7f1b5934)
/*  f13b1d4:	44829000 */ 	mtc1	$v0,$f18
/*  f13b1d8:	e5803414 */ 	swc1	$f0,0x3414($t4)
/*  f13b1dc:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f13b1e0:	c4285934 */ 	lwc1	$f8,%lo(var7f1b5934)($at)
/*  f13b1e4:	3c014f80 */ 	lui	$at,0x4f80
/*  f13b1e8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f13b1ec:	e5a83438 */ 	swc1	$f8,0x3438($t5)
/*  f13b1f0:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f13b1f4:	c46a3438 */ 	lwc1	$f10,0x3438($v1)
/*  f13b1f8:	e46a3410 */ 	swc1	$f10,0x3410($v1)
/*  f13b1fc:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f13b200:	e5203440 */ 	swc1	$f0,0x3440($t1)
/*  f13b204:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f13b208:	c4703440 */ 	lwc1	$f16,0x3440($v1)
/*  f13b20c:	04410004 */ 	bgez	$v0,.L0f13b220
/*  f13b210:	e4703418 */ 	swc1	$f16,0x3418($v1)
/*  f13b214:	44813000 */ 	mtc1	$at,$f6
/*  f13b218:	00000000 */ 	nop
/*  f13b21c:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f13b220:
/*  f13b220:	3c014661 */ 	lui	$at,0x4661
/*  f13b224:	44814000 */ 	mtc1	$at,$f8
/*  f13b228:	3c017f1b */ 	lui	$at,%hi(var7f1b5938)
/*  f13b22c:	c4305938 */ 	lwc1	$f16,%lo(var7f1b5938)($at)
/*  f13b230:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f13b234:	3c017f1b */ 	lui	$at,%hi(var7f1b593c)
/*  f13b238:	c426593c */ 	lwc1	$f6,%lo(var7f1b593c)($at)
/*  f13b23c:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f13b240:	3c017f1b */ 	lui	$at,%hi(var7f1b5940)
/*  f13b244:	240804b0 */ 	addiu	$t0,$zero,0x4b0
/*  f13b248:	02002025 */ 	or	$a0,$s0,$zero
/*  f13b24c:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f13b250:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f13b254:	46123101 */ 	sub.s	$f4,$f6,$f18
/*  f13b258:	e5c43428 */ 	swc1	$f4,0x3428($t6)
/*  f13b25c:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f13b260:	c4285940 */ 	lwc1	$f8,%lo(var7f1b5940)($at)
/*  f13b264:	3c017f1b */ 	lui	$at,%hi(var7f1b5944)
/*  f13b268:	e5e8342c */ 	swc1	$f8,0x342c($t7)
/*  f13b26c:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f13b270:	c42a5944 */ 	lwc1	$f10,%lo(var7f1b5944)($at)
/*  f13b274:	3c017f1b */ 	lui	$at,%hi(var7f1b5948)
/*  f13b278:	e70a3430 */ 	swc1	$f10,0x3430($t8)
/*  f13b27c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f13b280:	c4305948 */ 	lwc1	$f16,%lo(var7f1b5948)($at)
/*  f13b284:	3c018008 */ 	lui	$at,%hi(var8007f6dc)
/*  f13b288:	e7303434 */ 	swc1	$f16,0x3434($t9)
/*  f13b28c:	8cea0000 */ 	lw	$t2,0x0($a3)
/*  f13b290:	ad482efc */ 	sw	$t0,0x2efc($t2)
/*  f13b294:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f13b298:	906c34a1 */ 	lbu	$t4,0x34a1($v1)
/*  f13b29c:	358d0002 */ 	ori	$t5,$t4,0x2
/*  f13b2a0:	a06d34a1 */ 	sb	$t5,0x34a1($v1)
/*  f13b2a4:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f13b2a8:	ad2034a4 */ 	sw	$zero,0x34a4($t1)
/*  f13b2ac:	8ce50000 */ 	lw	$a1,0x0($a3)
/*  f13b2b0:	ac22f6dc */ 	sw	$v0,%lo(var8007f6dc)($at)
/*  f13b2b4:	0fc3ce2c */ 	jal	func0f0f38b0
/*  f13b2b8:	24a52ef0 */ 	addiu	$a1,$a1,0x2ef0
/*  f13b2bc:	3c0e0102 */ 	lui	$t6,0x102
/*  f13b2c0:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f13b2c4:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f13b2c8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f13b2cc:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f13b2d0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f13b2d4:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f13b2d8:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f13b2dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f13b2e0:	240500d8 */ 	addiu	$a1,$zero,0xd8
/*  f13b2e4:	0fc4e12d */ 	jal	creditsClearFramebuffer
/*  f13b2e8:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f13b2ec:	00408025 */ 	or	$s0,$v0,$zero
.L0f13b2f0:
/*  f13b2f0:	0c00566c */ 	jal	func000159b0
/*  f13b2f4:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f13b2f8:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f13b2fc:	0c005815 */ 	jal	func00016054
/*  f13b300:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f13b304:	0fc2d406 */ 	jal	currentPlayerSetMatrix1740
/*  f13b308:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f13b30c:	3c180102 */ 	lui	$t8,0x102
/*  f13b310:	37180040 */ 	ori	$t8,$t8,0x40
/*  f13b314:	02001825 */ 	or	$v1,$s0,$zero
/*  f13b318:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f13b31c:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f13b320:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f13b324:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f13b328:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f13b32c:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f13b330:	3c01c47a */ 	lui	$at,0xc47a
/*  f13b334:	44810000 */ 	mtc1	$at,$f0
/*  f13b338:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f13b33c:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f13b340:	44803000 */ 	mtc1	$zero,$f6
/*  f13b344:	44809000 */ 	mtc1	$zero,$f18
/*  f13b348:	44812000 */ 	mtc1	$at,$f4
/*  f13b34c:	02002025 */ 	or	$a0,$s0,$zero
/*  f13b350:	e7a00058 */ 	swc1	$f0,0x58($sp)
/*  f13b354:	e7a0005c */ 	swc1	$f0,0x5c($sp)
/*  f13b358:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f13b35c:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f13b360:	e7b20050 */ 	swc1	$f18,0x50($sp)
/*  f13b364:	0fc4dfc9 */ 	jal	creditsRenderBackground
/*  f13b368:	e7a40054 */ 	swc1	$f4,0x54($sp)
/*  f13b36c:	0fc4e4a4 */ 	jal	creditsRenderSprites
/*  f13b370:	00402025 */ 	or	$a0,$v0,$zero
/*  f13b374:	3c07800a */ 	lui	$a3,%hi(g_CreditsData)
/*  f13b378:	24e74170 */ 	addiu	$a3,$a3,%lo(g_CreditsData)
/*  f13b37c:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f13b380:	00408025 */ 	or	$s0,$v0,$zero
/*  f13b384:	906441f4 */ 	lbu	$a0,0x41f4($v1)
/*  f13b388:	10800009 */ 	beqz	$a0,.L0f13b3b0
/*  f13b38c:	00000000 */ 	nop
/*  f13b390:	0fc351e7 */ 	jal	func0f0d479c
/*  f13b394:	00402025 */ 	or	$a0,$v0,$zero
/*  f13b398:	0fc4e8fb */ 	jal	func0f13a3ec
/*  f13b39c:	00402025 */ 	or	$a0,$v0,$zero
/*  f13b3a0:	3c03800a */ 	lui	$v1,%hi(g_CreditsData)
/*  f13b3a4:	8c634170 */ 	lw	$v1,%lo(g_CreditsData)($v1)
/*  f13b3a8:	00408025 */ 	or	$s0,$v0,$zero
/*  f13b3ac:	906441f4 */ 	lbu	$a0,0x41f4($v1)
.L0f13b3b0:
/*  f13b3b0:	14800024 */ 	bnez	$a0,.L0f13b444
/*  f13b3b4:	00000000 */ 	nop
/*  f13b3b8:	8c624204 */ 	lw	$v0,0x4204($v1)
/*  f13b3bc:	00002825 */ 	or	$a1,$zero,$zero
/*  f13b3c0:	240300ff */ 	addiu	$v1,$zero,0xff
/*  f13b3c4:	2c41003c */ 	sltiu	$at,$v0,0x3c
/*  f13b3c8:	5020000b */ 	beqzl	$at,.L0f13b3f8
/*  f13b3cc:	2c4104b1 */ 	sltiu	$at,$v0,0x4b1
/*  f13b3d0:	00430019 */ 	multu	$v0,$v1
/*  f13b3d4:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f13b3d8:	00002812 */ 	mflo	$a1
/*  f13b3dc:	00000000 */ 	nop
/*  f13b3e0:	00000000 */ 	nop
/*  f13b3e4:	00a1001b */ 	divu	$zero,$a1,$at
/*  f13b3e8:	00002812 */ 	mflo	$a1
/*  f13b3ec:	00000000 */ 	nop
/*  f13b3f0:	00000000 */ 	nop
/*  f13b3f4:	2c4104b1 */ 	sltiu	$at,$v0,0x4b1
.L0f13b3f8:
/*  f13b3f8:	1420000d */ 	bnez	$at,.L0f13b430
/*  f13b3fc:	240300ff */ 	addiu	$v1,$zero,0xff
/*  f13b400:	2c4104ec */ 	sltiu	$at,$v0,0x4ec
/*  f13b404:	1020000a */ 	beqz	$at,.L0f13b430
/*  f13b408:	2448fb50 */ 	addiu	$t0,$v0,-1200
/*  f13b40c:	01030019 */ 	multu	$t0,$v1
/*  f13b410:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f13b414:	00005012 */ 	mflo	$t2
/*  f13b418:	00000000 */ 	nop
/*  f13b41c:	00000000 */ 	nop
/*  f13b420:	0141001b */ 	divu	$zero,$t2,$at
/*  f13b424:	00005812 */ 	mflo	$t3
/*  f13b428:	006b2823 */ 	subu	$a1,$v1,$t3
/*  f13b42c:	00000000 */ 	nop
.L0f13b430:
/*  f13b430:	10a00004 */ 	beqz	$a1,.L0f13b444
/*  f13b434:	00000000 */ 	nop
/*  f13b438:	0fc4e12d */ 	jal	creditsClearFramebuffer
/*  f13b43c:	02002025 */ 	or	$a0,$s0,$zero
/*  f13b440:	00408025 */ 	or	$s0,$v0,$zero
.L0f13b444:
/*  f13b444:	3c0c8008 */ 	lui	$t4,%hi(g_CreditsUsingAltTitle)
/*  f13b448:	8d8cf138 */ 	lw	$t4,%lo(g_CreditsUsingAltTitle)($t4)
/*  f13b44c:	00002025 */ 	or	$a0,$zero,$zero
/*  f13b450:	51800018 */ 	beqzl	$t4,.L0f13b4b4
/*  f13b454:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f13b458:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f13b45c:	3405ffcf */ 	dli	$a1,0xffcf
/*  f13b460:	10400013 */ 	beqz	$v0,.L0f13b4b0
/*  f13b464:	240d0026 */ 	addiu	$t5,$zero,0x26
/*  f13b468:	3c018006 */ 	lui	$at,%hi(g_TitleNextStage)
/*  f13b46c:	ac2d24e4 */ 	sw	$t5,%lo(g_TitleNextStage)($at)
/*  f13b470:	0fc068d5 */ 	jal	setNumPlayers
/*  f13b474:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f13b478:	3c048006 */ 	lui	$a0,%hi(g_TitleNextStage)
/*  f13b47c:	0c003a57 */ 	jal	mainSetStageNum
/*  f13b480:	8c8424e4 */ 	lw	$a0,%lo(g_TitleNextStage)($a0)
/*  f13b484:	3c01800a */ 	lui	$at,%hi(g_Vars+0x294)
/*  f13b488:	ac20a254 */ 	sw	$zero,%lo(g_Vars+0x294)($at)
/*  f13b48c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f13b490:	3c01800a */ 	lui	$at,%hi(g_Vars+0x298)
/*  f13b494:	ac22a258 */ 	sw	$v0,%lo(g_Vars+0x298)($at)
/*  f13b498:	3c01800a */ 	lui	$at,%hi(g_Vars+0x29c)
/*  f13b49c:	ac22a25c */ 	sw	$v0,%lo(g_Vars+0x29c)($at)
/*  f13b4a0:	0fc5b36a */ 	jal	lvSetDifficulty
/*  f13b4a4:	00002025 */ 	or	$a0,$zero,$zero
/*  f13b4a8:	0c0027b1 */ 	jal	func00009ec4
/*  f13b4ac:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f13b4b0:
/*  f13b4b0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f13b4b4:
/*  f13b4b4:	02001025 */ 	or	$v0,$s0,$zero
/*  f13b4b8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f13b4bc:	03e00008 */ 	jr	$ra
/*  f13b4c0:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#else
GLOBAL_ASM(
glabel creditsRender
.late_rodata
glabel var7f1b5934
.word 0xbe86051b
glabel var7f1b5938
.word 0x4516d000
glabel var7f1b593c
.word 0x44504000
glabel var7f1b5940
.word 0x428db852
glabel var7f1b5944
.word 0xc5002000
glabel var7f1b5948
.word 0x3fbbc6a8
.text
/*     7f135b64:	27bdff58 */ 	addiu	$sp,$sp,-168
/*     7f135b68:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     7f135b6c:	afb00018 */ 	sw	$s0,0x18($sp)
/*     7f135b70:	0fc588b6 */ 	jal	gfxAllocateMatrix
/*     7f135b74:	00808025 */ 	or	$s0,$a0,$zero
/*     7f135b78:	afa20064 */ 	sw	$v0,0x64($sp)
/*     7f135b7c:	0fc53637 */ 	jal	func0f1531dc
/*     7f135b80:	00002025 */ 	or	$a0,$zero,$zero
/*     7f135b84:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     7f135b88:	3c018008 */ 	lui	$at,0x8008
/*     7f135b8c:	ac2e2320 */ 	sw	$t6,0x2320($at)
/*     7f135b90:	0c002d00 */ 	jal	func0000b280
/*     7f135b94:	02002025 */ 	or	$a0,$s0,$zero
/*     7f135b98:	0c002cd4 */ 	jal	func0000b1d0
/*     7f135b9c:	00402025 */ 	or	$a0,$v0,$zero
/*     7f135ba0:	00402025 */ 	or	$a0,$v0,$zero
/*     7f135ba4:	0fc4cc11 */ 	jal	creditsClearFramebuffer
/*     7f135ba8:	240500ff */ 	addiu	$a1,$zero,0xff
/*     7f135bac:	3c0fed00 */ 	lui	$t7,0xed00
/*     7f135bb0:	35ef0078 */ 	ori	$t7,$t7,0x78
/*     7f135bb4:	afa20048 */ 	sw	$v0,0x48($sp)
/*     7f135bb8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*     7f135bbc:	0c002f77 */ 	jal	viGetWidth
/*     7f135bc0:	24500008 */ 	addiu	$s0,$v0,0x8
/*     7f135bc4:	0c002f7b */ 	jal	viGetHeight
/*     7f135bc8:	a7a20036 */ 	sh	$v0,0x36($sp)
/*     7f135bcc:	2458ffe2 */ 	addiu	$t8,$v0,-30
/*     7f135bd0:	44982000 */ 	mtc1	$t8,$f4
/*     7f135bd4:	87aa0036 */ 	lh	$t2,0x36($sp)
/*     7f135bd8:	3c014080 */ 	lui	$at,0x4080
/*     7f135bdc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*     7f135be0:	448a8000 */ 	mtc1	$t2,$f16
/*     7f135be4:	44810000 */ 	mtc1	$at,$f0
/*     7f135be8:	8fb80048 */ 	lw	$t8,0x48($sp)
/*     7f135bec:	468084a0 */ 	cvt.s.w	$f18,$f16
/*     7f135bf0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*     7f135bf4:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135bf8:	46009102 */ 	mul.s	$f4,$f18,$f0
/*     7f135bfc:	4600428d */ 	trunc.w.s	$f10,$f8
/*     7f135c00:	4600218d */ 	trunc.w.s	$f6,$f4
/*     7f135c04:	44085000 */ 	mfc1	$t0,$f10
/*     7f135c08:	440c3000 */ 	mfc1	$t4,$f6
/*     7f135c0c:	31090fff */ 	andi	$t1,$t0,0xfff
/*     7f135c10:	318d0fff */ 	andi	$t5,$t4,0xfff
/*     7f135c14:	000d7300 */ 	sll	$t6,$t5,0xc
/*     7f135c18:	012e7825 */ 	or	$t7,$t1,$t6
/*     7f135c1c:	0fc4d645 */ 	jal	creditsTick
/*     7f135c20:	af0f0004 */ 	sw	$t7,0x4($t8)
/*     7f135c24:	3c07800b */ 	lui	$a3,0x800b
/*     7f135c28:	24e78730 */ 	addiu	$a3,$a3,-30928
/*     7f135c2c:	8ce30000 */ 	lw	$v1,0x0($a3)
/*     7f135c30:	906441f4 */ 	lbu	$a0,0x41f4($v1)
/*     7f135c34:	14800007 */ 	bnez	$a0,.NB7f135c54
/*     7f135c38:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135c3c:	8c624204 */ 	lw	$v0,0x4204($v1)
/*     7f135c40:	2c41003c */ 	sltiu	$at,$v0,0x3c
/*     7f135c44:	14200003 */ 	bnez	$at,.NB7f135c54
/*     7f135c48:	2c4104b1 */ 	sltiu	$at,$v0,0x4b1
/*     7f135c4c:	142000bd */ 	bnez	$at,.NB7f135f44
/*     7f135c50:	00000000 */ 	sll	$zero,$zero,0x0
.NB7f135c54:
/*     7f135c54:	14800066 */ 	bnez	$a0,.NB7f135df0
/*     7f135c58:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135c5c:	8c794204 */ 	lw	$t9,0x4204($v1)
/*     7f135c60:	3c058008 */ 	lui	$a1,0x8008
/*     7f135c64:	24a51990 */ 	addiu	$a1,$a1,0x1990
/*     7f135c68:	2f2104b1 */ 	sltiu	$at,$t9,0x4b1
/*     7f135c6c:	14200060 */ 	bnez	$at,.NB7f135df0
/*     7f135c70:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135c74:	8ca80000 */ 	lw	$t0,0x0($a1)
/*     7f135c78:	240a0001 */ 	addiu	$t2,$zero,0x1
/*     7f135c7c:	24642ef0 */ 	addiu	$a0,$v1,0x2ef0
/*     7f135c80:	15000007 */ 	bnez	$t0,.NB7f135ca0
/*     7f135c84:	3c018008 */ 	lui	$at,0x8008
/*     7f135c88:	acaa0000 */ 	sw	$t2,0x0($a1)
/*     7f135c8c:	0fc3c0ba */ 	jal	func0f0f37a4
/*     7f135c90:	ac201f30 */ 	sw	$zero,0x1f30($at)
/*     7f135c94:	3c07800b */ 	lui	$a3,0x800b
/*     7f135c98:	24e78730 */ 	addiu	$a3,$a3,-30928
/*     7f135c9c:	8ce30000 */ 	lw	$v1,0x0($a3)
.NB7f135ca0:
/*     7f135ca0:	3c028008 */ 	lui	$v0,0x8008
/*     7f135ca4:	3c0b800a */ 	lui	$t3,0x800a
/*     7f135ca8:	8c421f30 */ 	lw	$v0,0x1f30($v0)
/*     7f135cac:	8d6be700 */ 	lw	$t3,-0x1900($t3)
/*     7f135cb0:	44800000 */ 	mtc1	$zero,$f0
/*     7f135cb4:	004b1021 */ 	addu	$v0,$v0,$t3
/*     7f135cb8:	2c413841 */ 	sltiu	$at,$v0,0x3841
/*     7f135cbc:	54200003 */ 	bnezl	$at,.NB7f135ccc
/*     7f135cc0:	e460343c */ 	swc1	$f0,0x343c($v1)
/*     7f135cc4:	00001025 */ 	or	$v0,$zero,$zero
/*     7f135cc8:	e460343c */ 	swc1	$f0,0x343c($v1)
.NB7f135ccc:
/*     7f135ccc:	8cec0000 */ 	lw	$t4,0x0($a3)
/*     7f135cd0:	3c017f1b */ 	lui	$at,0x7f1b
/*     7f135cd4:	44829000 */ 	mtc1	$v0,$f18
/*     7f135cd8:	e5803414 */ 	swc1	$f0,0x3414($t4)
/*     7f135cdc:	8ced0000 */ 	lw	$t5,0x0($a3)
/*     7f135ce0:	c428fe74 */ 	lwc1	$f8,-0x18c($at)
/*     7f135ce4:	3c014f80 */ 	lui	$at,0x4f80
/*     7f135ce8:	46809120 */ 	cvt.s.w	$f4,$f18
/*     7f135cec:	e5a83438 */ 	swc1	$f8,0x3438($t5)
/*     7f135cf0:	8ce30000 */ 	lw	$v1,0x0($a3)
/*     7f135cf4:	c46a3438 */ 	lwc1	$f10,0x3438($v1)
/*     7f135cf8:	e46a3410 */ 	swc1	$f10,0x3410($v1)
/*     7f135cfc:	8ce90000 */ 	lw	$t1,0x0($a3)
/*     7f135d00:	e5203440 */ 	swc1	$f0,0x3440($t1)
/*     7f135d04:	8ce30000 */ 	lw	$v1,0x0($a3)
/*     7f135d08:	c4703440 */ 	lwc1	$f16,0x3440($v1)
/*     7f135d0c:	04410004 */ 	bgez	$v0,.NB7f135d20
/*     7f135d10:	e4703418 */ 	swc1	$f16,0x3418($v1)
/*     7f135d14:	44813000 */ 	mtc1	$at,$f6
/*     7f135d18:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135d1c:	46062100 */ 	add.s	$f4,$f4,$f6
.NB7f135d20:
/*     7f135d20:	3c014661 */ 	lui	$at,0x4661
/*     7f135d24:	44814000 */ 	mtc1	$at,$f8
/*     7f135d28:	3c017f1b */ 	lui	$at,0x7f1b
/*     7f135d2c:	c430fe78 */ 	lwc1	$f16,-0x188($at)
/*     7f135d30:	46082283 */ 	div.s	$f10,$f4,$f8
/*     7f135d34:	3c017f1b */ 	lui	$at,0x7f1b
/*     7f135d38:	c426fe7c */ 	lwc1	$f6,-0x184($at)
/*     7f135d3c:	8cee0000 */ 	lw	$t6,0x0($a3)
/*     7f135d40:	3c017f1b */ 	lui	$at,0x7f1b
/*     7f135d44:	240804b0 */ 	addiu	$t0,$zero,0x4b0
/*     7f135d48:	02002025 */ 	or	$a0,$s0,$zero
/*     7f135d4c:	24060004 */ 	addiu	$a2,$zero,0x4
/*     7f135d50:	46105482 */ 	mul.s	$f18,$f10,$f16
/*     7f135d54:	46123101 */ 	sub.s	$f4,$f6,$f18
/*     7f135d58:	e5c43428 */ 	swc1	$f4,0x3428($t6)
/*     7f135d5c:	8cef0000 */ 	lw	$t7,0x0($a3)
/*     7f135d60:	c428fe80 */ 	lwc1	$f8,-0x180($at)
/*     7f135d64:	3c017f1b */ 	lui	$at,0x7f1b
/*     7f135d68:	e5e8342c */ 	swc1	$f8,0x342c($t7)
/*     7f135d6c:	8cf80000 */ 	lw	$t8,0x0($a3)
/*     7f135d70:	c42afe84 */ 	lwc1	$f10,-0x17c($at)
/*     7f135d74:	3c017f1b */ 	lui	$at,0x7f1b
/*     7f135d78:	e70a3430 */ 	swc1	$f10,0x3430($t8)
/*     7f135d7c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*     7f135d80:	c430fe88 */ 	lwc1	$f16,-0x178($at)
/*     7f135d84:	3c018008 */ 	lui	$at,0x8008
/*     7f135d88:	e7303434 */ 	swc1	$f16,0x3434($t9)
/*     7f135d8c:	8cea0000 */ 	lw	$t2,0x0($a3)
/*     7f135d90:	ad482efc */ 	sw	$t0,0x2efc($t2)
/*     7f135d94:	8ce30000 */ 	lw	$v1,0x0($a3)
/*     7f135d98:	906c34a1 */ 	lbu	$t4,0x34a1($v1)
/*     7f135d9c:	358d0002 */ 	ori	$t5,$t4,0x2
/*     7f135da0:	a06d34a1 */ 	sb	$t5,0x34a1($v1)
/*     7f135da4:	8ce90000 */ 	lw	$t1,0x0($a3)
/*     7f135da8:	ad2034a4 */ 	sw	$zero,0x34a4($t1)
/*     7f135dac:	8ce50000 */ 	lw	$a1,0x0($a3)
/*     7f135db0:	ac221f30 */ 	sw	$v0,0x1f30($at)
/*     7f135db4:	0fc3c0fd */ 	jal	func0f0f38b0
/*     7f135db8:	24a52ef0 */ 	addiu	$a1,$a1,0x2ef0
/*     7f135dbc:	3c0e0102 */ 	lui	$t6,0x102
/*     7f135dc0:	35ce0040 */ 	ori	$t6,$t6,0x40
/*     7f135dc4:	afa20040 */ 	sw	$v0,0x40($sp)
/*     7f135dc8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*     7f135dcc:	8fa40064 */ 	lw	$a0,0x64($sp)
/*     7f135dd0:	0c013100 */ 	jal	osVirtualToPhysical
/*     7f135dd4:	24500008 */ 	addiu	$s0,$v0,0x8
/*     7f135dd8:	8faf0040 */ 	lw	$t7,0x40($sp)
/*     7f135ddc:	02002025 */ 	or	$a0,$s0,$zero
/*     7f135de0:	240500d8 */ 	addiu	$a1,$zero,0xd8
/*     7f135de4:	0fc4cc11 */ 	jal	creditsClearFramebuffer
/*     7f135de8:	ade20004 */ 	sw	$v0,0x4($t7)
/*     7f135dec:	00408025 */ 	or	$s0,$v0,$zero
.NB7f135df0:
/*     7f135df0:	0c005a28 */ 	jal	func000159b0
/*     7f135df4:	27a40068 */ 	addiu	$a0,$sp,0x68
/*     7f135df8:	27a40068 */ 	addiu	$a0,$sp,0x68
/*     7f135dfc:	0c005bd1 */ 	jal	func00016054
/*     7f135e00:	8fa50064 */ 	lw	$a1,0x64($sp)
/*     7f135e04:	0fc2cb5e */ 	jal	currentPlayerSetMatrix1740
/*     7f135e08:	27a40068 */ 	addiu	$a0,$sp,0x68
/*     7f135e0c:	3c180102 */ 	lui	$t8,0x102
/*     7f135e10:	37180040 */ 	ori	$t8,$t8,0x40
/*     7f135e14:	02001825 */ 	or	$v1,$s0,$zero
/*     7f135e18:	ac780000 */ 	sw	$t8,0x0($v1)
/*     7f135e1c:	afa3003c */ 	sw	$v1,0x3c($sp)
/*     7f135e20:	8fa40064 */ 	lw	$a0,0x64($sp)
/*     7f135e24:	0c013100 */ 	jal	osVirtualToPhysical
/*     7f135e28:	26100008 */ 	addiu	$s0,$s0,0x8
/*     7f135e2c:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*     7f135e30:	3c01c47a */ 	lui	$at,0xc47a
/*     7f135e34:	44810000 */ 	mtc1	$at,$f0
/*     7f135e38:	ac620004 */ 	sw	$v0,0x4($v1)
/*     7f135e3c:	3c01c2c8 */ 	lui	$at,0xc2c8
/*     7f135e40:	44803000 */ 	mtc1	$zero,$f6
/*     7f135e44:	44809000 */ 	mtc1	$zero,$f18
/*     7f135e48:	44812000 */ 	mtc1	$at,$f4
/*     7f135e4c:	02002025 */ 	or	$a0,$s0,$zero
/*     7f135e50:	e7a00058 */ 	swc1	$f0,0x58($sp)
/*     7f135e54:	e7a0005c */ 	swc1	$f0,0x5c($sp)
/*     7f135e58:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*     7f135e5c:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*     7f135e60:	e7b20050 */ 	swc1	$f18,0x50($sp)
/*     7f135e64:	0fc4caad */ 	jal	creditsRenderBackground
/*     7f135e68:	e7a40054 */ 	swc1	$f4,0x54($sp)
/*     7f135e6c:	0fc4cf66 */ 	jal	creditsRenderSprites
/*     7f135e70:	00402025 */ 	or	$a0,$v0,$zero
/*     7f135e74:	3c07800b */ 	lui	$a3,0x800b
/*     7f135e78:	24e78730 */ 	addiu	$a3,$a3,-30928
/*     7f135e7c:	8ce30000 */ 	lw	$v1,0x0($a3)
/*     7f135e80:	00408025 */ 	or	$s0,$v0,$zero
/*     7f135e84:	906441f4 */ 	lbu	$a0,0x41f4($v1)
/*     7f135e88:	10800009 */ 	beqz	$a0,.NB7f135eb0
/*     7f135e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135e90:	0fc347cf */ 	jal	func0f0d479c
/*     7f135e94:	00402025 */ 	or	$a0,$v0,$zero
/*     7f135e98:	0fc4d3bd */ 	jal	func0f13a3ec
/*     7f135e9c:	00402025 */ 	or	$a0,$v0,$zero
/*     7f135ea0:	3c03800b */ 	lui	$v1,0x800b
/*     7f135ea4:	8c638730 */ 	lw	$v1,-0x78d0($v1)
/*     7f135ea8:	00408025 */ 	or	$s0,$v0,$zero
/*     7f135eac:	906441f4 */ 	lbu	$a0,0x41f4($v1)
.NB7f135eb0:
/*     7f135eb0:	14800024 */ 	bnez	$a0,.NB7f135f44
/*     7f135eb4:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135eb8:	8c624204 */ 	lw	$v0,0x4204($v1)
/*     7f135ebc:	00002825 */ 	or	$a1,$zero,$zero
/*     7f135ec0:	240300ff */ 	addiu	$v1,$zero,0xff
/*     7f135ec4:	2c41003c */ 	sltiu	$at,$v0,0x3c
/*     7f135ec8:	5020000b */ 	beqzl	$at,.NB7f135ef8
/*     7f135ecc:	2c4104b1 */ 	sltiu	$at,$v0,0x4b1
/*     7f135ed0:	00430019 */ 	multu	$v0,$v1
/*     7f135ed4:	2401003c */ 	addiu	$at,$zero,0x3c
/*     7f135ed8:	00002812 */ 	mflo	$a1
/*     7f135edc:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135ee0:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135ee4:	00a1001b */ 	divu	$zero,$a1,$at
/*     7f135ee8:	00002812 */ 	mflo	$a1
/*     7f135eec:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135ef0:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135ef4:	2c4104b1 */ 	sltiu	$at,$v0,0x4b1
.NB7f135ef8:
/*     7f135ef8:	1420000d */ 	bnez	$at,.NB7f135f30
/*     7f135efc:	240300ff */ 	addiu	$v1,$zero,0xff
/*     7f135f00:	2c4104ec */ 	sltiu	$at,$v0,0x4ec
/*     7f135f04:	1020000a */ 	beqz	$at,.NB7f135f30
/*     7f135f08:	2448fb50 */ 	addiu	$t0,$v0,-1200
/*     7f135f0c:	01030019 */ 	multu	$t0,$v1
/*     7f135f10:	2401003c */ 	addiu	$at,$zero,0x3c
/*     7f135f14:	00005012 */ 	mflo	$t2
/*     7f135f18:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135f1c:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135f20:	0141001b */ 	divu	$zero,$t2,$at
/*     7f135f24:	00005812 */ 	mflo	$t3
/*     7f135f28:	006b2823 */ 	subu	$a1,$v1,$t3
/*     7f135f2c:	00000000 */ 	sll	$zero,$zero,0x0
.NB7f135f30:
/*     7f135f30:	10a00004 */ 	beqz	$a1,.NB7f135f44
/*     7f135f34:	00000000 */ 	sll	$zero,$zero,0x0
/*     7f135f38:	0fc4cc11 */ 	jal	creditsClearFramebuffer
/*     7f135f3c:	02002025 */ 	or	$a0,$s0,$zero
/*     7f135f40:	00408025 */ 	or	$s0,$v0,$zero
.NB7f135f44:
/*     7f135f44:	3c0c8008 */ 	lui	$t4,0x8008
/*     7f135f48:	8d8c1998 */ 	lw	$t4,0x1998($t4)
/*     7f135f4c:	00002025 */ 	or	$a0,$zero,$zero
/*     7f135f50:	51800018 */ 	beqzl	$t4,.NB7f135fb4
/*     7f135f54:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     7f135f58:	0c005790 */ 	jal	joyGetButtons
/*     7f135f5c:	3405ffff */ 	dli	$a1,0xffff
/*     7f135f60:	10400013 */ 	beqz	$v0,.NB7f135fb0
/*     7f135f64:	240d0026 */ 	addiu	$t5,$zero,0x26
/*     7f135f68:	3c018006 */ 	lui	$at,0x8006
/*     7f135f6c:	ac2d49f4 */ 	sw	$t5,0x49f4($at)
/*     7f135f70:	0fc06821 */ 	jal	setNumPlayers
/*     7f135f74:	24040001 */ 	addiu	$a0,$zero,0x1
/*     7f135f78:	3c048006 */ 	lui	$a0,0x8006
/*     7f135f7c:	0c003c56 */ 	jal	mainSetStageNum
/*     7f135f80:	8c8449f4 */ 	lw	$a0,0x49f4($a0)
/*     7f135f84:	3c01800a */ 	lui	$at,0x800a
/*     7f135f88:	ac20e954 */ 	sw	$zero,-0x16ac($at)
/*     7f135f8c:	2402ffff */ 	addiu	$v0,$zero,-1
/*     7f135f90:	3c01800a */ 	lui	$at,0x800a
/*     7f135f94:	ac22e958 */ 	sw	$v0,-0x16a8($at)
/*     7f135f98:	3c01800a */ 	lui	$at,0x800a
/*     7f135f9c:	ac22e95c */ 	sw	$v0,-0x16a4($at)
/*     7f135fa0:	0fc59ed6 */ 	jal	lvSetDifficulty
/*     7f135fa4:	00002025 */ 	or	$a0,$zero,$zero
/*     7f135fa8:	0c00281a */ 	jal	func00009ec4
/*     7f135fac:	24040001 */ 	addiu	$a0,$zero,0x1
.NB7f135fb0:
/*     7f135fb0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.NB7f135fb4:
/*     7f135fb4:	02001025 */ 	or	$v0,$s0,$zero
/*     7f135fb8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     7f135fbc:	03e00008 */ 	jr	$ra
/*     7f135fc0:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#endif

// Mismatch: Come back to to this when more is known about these symbols
//Gfx *creditsRender(Gfx *gdl)
//{
//	Mtxf sp68;
//	Mtxf *matrix = gfxAllocateMatrix();
//	volatile struct coord sp58;
//	volatile struct coord sp4c;
//
//	func0f1531dc(false);
//
//	g_ScaleX = 1;
//
//	gdl = func0000b280(gdl);
//	gdl = func0000b1d0(gdl);
//	gdl = creditsClearFramebuffer(gdl, 0x000000ff);
//
//	gDPSetScissorFrac(gdl++, G_SC_NON_INTERLACE, 0, 120, viGetWidth() * 4.0f, (viGetHeight() - 30) * 4.0f);
//
//	creditsTick();
//
//	if (g_CreditsData->slidesenabled || g_CreditsData->unk4204 < 60 || g_CreditsData->unk4204 > 1200) {
//		if (!g_CreditsData->slidesenabled && g_CreditsData->unk4204 > 1200) {
//			if (var8007f130 == 0) {
//				var8007f130 = 1;
//				var8007f6dc = 0;
//
//				func0f0f37a4(&g_CreditsData->unk2ef0);
//			}
//
//			var8007f6dc += g_Vars.diffframe240;
//
//			if (var8007f6dc > SECSTOTIME240(60)) {
//				var8007f6dc = 0;
//			}
//
//			g_CreditsData->unk343c = 0;
//			g_CreditsData->unk3414 = 0;
//			g_CreditsData->unk3438 = -0.26175770163536;
//			g_CreditsData->unk3410 = g_CreditsData->unk3438;
//			g_CreditsData->unk3428 = 833.0f - (var8007f6dc / 14400.0f) * 2413.0f;
//			g_CreditsData->unk3440 = 0;
//			g_CreditsData->unk3418 = g_CreditsData->unk3440;
//			g_CreditsData->unk342c = 70.86;
//			g_CreditsData->unk3430 = -2050;
//			g_CreditsData->unk3434 = 1.467;
//
//			g_CreditsData->unk2efc = 1200;
//			g_CreditsData->unk34a1 |= 0x02;
//			g_CreditsData->unk34a4 = 0;
//
//			gdl = func0f0f38b0(gdl, &g_CreditsData->unk2ef0, 4);
//
//			gSPMatrix(gdl++, osVirtualToPhysical(matrix), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
//
//			gdl = creditsClearFramebuffer(gdl, 0x000000d8);
//		}
//
//		func000159b0(&sp68);
//		func00016054(&sp68, matrix);
//		currentPlayerSetMatrix1740(&sp68);
//
//		gSPMatrix(gdl++, osVirtualToPhysical(matrix), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
//
//		sp58.x = -1000;
//		sp58.y = -1000;
//		sp58.z = -1000;
//
//		sp4c.x = 0;
//		sp4c.y = 0;
//		sp4c.z = -100;
//
//		gdl = creditsRenderBackground(gdl);
//		gdl = creditsRenderSprites(gdl);
//
//		if (g_CreditsData->slidesenabled) {
//			// Render text
//			gdl = func0f0d479c(gdl);
//			gdl = func0f13a3ec(gdl);
//		}
//
//		if (!g_CreditsData->slidesenabled) {
//			u32 uVar1 = g_CreditsData->unk4204;
//			u32 colour = 0;
//
//			if (uVar1 < 60) {
//				colour = (uVar1 * 0xff) / 60;
//			}
//
//			if (uVar1 > 1200 && uVar1 < 1260) {
//				colour = 0xff - ((uVar1 - 1200) * 0xff) / 60;
//			}
//
//			if (colour) {
//				gdl = creditsClearFramebuffer(gdl, colour);
//			}
//		}
//	}
//
//	if (g_CreditsUsingAltTitle && joyGetButtonsPressedThisFrame(0, 0xffcf)) {
//		g_TitleNextStage = STAGE_CITRAINING;
//
//		setNumPlayers(1);
//		mainSetStageNum(g_TitleNextStage);
//
//		g_Vars.bondplayernum = 0;
//		g_Vars.coopplayernum = -1;
//		g_Vars.antiplayernum = -1;
//
//		lvSetDifficulty(DIFF_A);
//		func00009ec4(1);
//	}
//
//	return gdl;
//}

void creditsInit(void)
{
	var800a4164 = 0;
	var800a416c = 0;
	var8007f130 = 0;

	g_CreditsData = malloc(sizeof(struct creditsdata), MEMPOOL_STAGE);

	g_CreditsData->unk2eec = 0;
	g_CreditsData->unk41b0[0] = 0;
	g_CreditsData->unk41b0[1] = 0;

	creditsCreatePendingBgLayers(0xffffffff);

	// Move layers 2 and 3 to 0 and 1
	creditsCopyBackgroundLayer(2, 0, true);
	creditsCopyBackgroundLayer(3, 1, true);

	g_CreditsData->slidesenabled = true;

	func0f13870c();
	creditsInitSlides();
	func0f0f8bb4(&g_CreditsData->unk2ef0, 0x25800, 1);

	g_CreditsData->unk3470 = 0;

	func0f0f372c(&g_CreditsData->unk2ef0, 0, 0, 0, 0, 0, 0, 1, 5);

	g_CreditsData->unk342c = 90;
	g_CreditsData->unk3400 = 8.2;
	g_CreditsData->unk3404 = -4.1;
	g_CreditsData->unk340c = 0.00393;
	g_CreditsData->unk343c = 0;
	g_CreditsData->unk3414 = g_CreditsData->unk343c;
	g_CreditsData->unk3468 = 60;

	g_CreditsUsingAltTitle = g_CreditsAltTitleRequested;

	if (g_CreditsAltTitleRequested) {
		g_CreditsAltTitleRequested = false;

		g_CreditsData->slidesenabled = false;
		g_CreditsData->unk4204 = PALDOWN(1140);
	}

	currentPlayerConfigureVi();
}

void creditsRequestAltTitle(void)
{
	g_CreditsAltTitleRequested = true;
}
