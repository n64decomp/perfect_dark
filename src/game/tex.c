#include <ultra64.h>
#include "constants.h"
#include "game/dyntex.h"
#include "game/tex.h"
#include "game/texdecompress.h"
#include "bss.h"
#include "data.h"
#include "gbiex.h"
#include "textures.h"
#include "types.h"

s32 g_TexLutMode;
struct var800ab5b8 var800ab5b8[8];
struct var800ab718 var800ab718[8];

// Default
u16 g_SurfaceTypeDefaultSounds[] = { SFX_HIT_STONE_8087, SFX_HIT_STONE_8088 };
u8 g_SurfaceTypeDefaultTexes[] = { WALLHITTEX_BULLET2 };

struct surfacetype g_SurfaceTypeDefault = {
	g_SurfaceTypeDefaultSounds, g_SurfaceTypeDefaultTexes, 2, 1,
};

// Stone
u16 var80084344[] = { SFX_HIT_STONE_8087, SFX_HIT_STONE_8088 };
u8 var80084348[] = { WALLHITTEX_BULLET1 };

struct surfacetype g_SurfaceTypeStone = {
	var80084344, var80084348, 2, 1,
};

// Wood
u16 g_SurfaceTypeWoodSounds[] = { SFX_HIT_WOOD_807E, SFX_HIT_WOOD_807F };
u8 var8008435c[] = { WALLHITTEX_WOOD };

struct surfacetype g_SurfaceTypeWood = {
	g_SurfaceTypeWoodSounds, var8008435c, 2, 1,
};

// Metal
u16 g_SurfaceTypeMetalSounds[] = { SFX_HIT_METAL_8079, SFX_HIT_METAL_807B };
u8 var80084370[] = { WALLHITTEX_METAL };

struct surfacetype g_SurfaceTypeMetal = {
	g_SurfaceTypeMetalSounds, var80084370, 2, 1,
};

// Glass
u16 g_SurfaceTypeGlassSounds[] = { SFX_HIT_GLASS };
u8 var80084384[] = { WALLHITTEX_GLASS1, WALLHITTEX_GLASS2, WALLHITTEX_GLASS3 };

struct surfacetype g_SurfaceTypeGlass = {
	g_SurfaceTypeGlassSounds, var80084384, 1, 3,
};

// Snow
u16 g_SurfaceTypeSnowSounds[] = { SFX_HIT_SNOW };
u8 var80084398[] = { WALLHITTEX_BULLET1 };

struct surfacetype g_SurfaceTypeSnow = {
	g_SurfaceTypeSnowSounds, var80084398, 1, 1,
};

// Dirt
u16 g_SurfaceTypeDirtSounds[] = { SFX_HIT_DIRT_8084, SFX_HIT_DIRT_8085 };
u8 var800843ac[] = { WALLHITTEX_SOFT };

struct surfacetype g_SurfaceTypeDirt = {
	g_SurfaceTypeDirtSounds, var800843ac, 2, 1,
};

// Mud
u16 g_SurfaceTypeMudSounds[] = { SFX_HIT_MUD_8081, SFX_HIT_MUD_8082, SFX_HIT_MUD_8083 };
u8 var800843c4[] = { WALLHITTEX_SOFT };

struct surfacetype g_SurfaceTypeMud = {
	g_SurfaceTypeMudSounds, var800843c4, 3, 1,
};

// Tile
u16 g_SurfaceTypeTileSounds[] = { SFX_HIT_TILE };
u8 var800843d8[] = { WALLHITTEX_BULLET1 };

struct surfacetype g_SurfaceTypeTile = {
	g_SurfaceTypeTileSounds, var800843d8, 1, 1,
};

// Metal obj
u16 g_SurfaceTypeMetalObjSounds[] = { SFX_HIT_METALOBJ_8089, SFX_HIT_METALOBJ_808A };
u8 var800843ec[] = { WALLHITTEX_BULLET1, WALLHITTEX_BULLET2 };

struct surfacetype g_SurfaceTypeMetalObj = {
	g_SurfaceTypeMetalObjSounds, var800843ec, 2, 2,
};

// Chr
u16 g_SurfaceTypeChrSounds[] = { SFX_HIT_CHR };
u8 var80084400[] = { WALLHITTEX_SOFT };

struct surfacetype g_SurfaceTypeChr = {
	g_SurfaceTypeChrSounds, var80084400, 1, 1,
};

// Glass XLU
u16 g_SurfaceTypeGlassXluSounds[] = { SFX_HIT_GLASS };
u8 var80084414[] = { WALLHITTEX_GLASS1, WALLHITTEX_GLASS2, WALLHITTEX_GLASS3 };

struct surfacetype g_SurfaceTypeGlassXlu = {
	g_SurfaceTypeGlassXluSounds, var80084414, 1, 3,
};

// None
struct surfacetype g_SurfaceTypeNone = {
	NULL, NULL, 0, 0,
};

// Shallow water
u16 g_SurfaceTypeShallowWaterSounds[] = { SFX_HIT_WATER };
u8 var80084434[] = { WALLHITTEX_WATER };

struct surfacetype g_SurfaceTypeShallowWater = {
	g_SurfaceTypeShallowWaterSounds, var80084434, 1, 1,
};

// Deep water
u16 g_SurfaceTypeDeepWaterSounds[] = { SFX_HIT_WATER };
u8 var80084448[] = { WALLHITTEX_WATER };

struct surfacetype g_SurfaceTypeDeepWater = {
	g_SurfaceTypeDeepWaterSounds, var80084448, 1, 1,
};

struct surfacetype *g_SurfaceTypes[] = {
	/* 0*/ &g_SurfaceTypeDefault,
	/* 1*/ &g_SurfaceTypeStone,
	/* 2*/ &g_SurfaceTypeWood,
	/* 3*/ &g_SurfaceTypeMetal,
	/* 4*/ &g_SurfaceTypeGlass,
	/* 5*/ &g_SurfaceTypeShallowWater,
	/* 6*/ &g_SurfaceTypeSnow,
	/* 7*/ &g_SurfaceTypeDirt,
	/* 8*/ &g_SurfaceTypeMud,
	/* 9*/ &g_SurfaceTypeTile,
	/*10*/ &g_SurfaceTypeMetalObj,
	/*11*/ &g_SurfaceTypeChr,
	/*12*/ &g_SurfaceTypeGlassXlu,
	/*13*/ &g_SurfaceTypeNone,
	/*14*/ &g_SurfaceTypeDeepWater,
};

bool var800844d0 = false;

static void tex0f173a08(void)
{
	s32 i;

	for (i = 0; i < 8; i++) {
		var800ab5b8[i].unk00 = 0;
		var800ab718[i].inuse = false;
	}

	g_TexLutMode = -1;
}

static bool texSetLutMode(u32 lutmode)
{
	if (g_TexLutMode == lutmode) {
		return false;
	}

	g_TexLutMode = lutmode;
	return true;
}

static bool tex0f173a70(s32 index, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10)
{
	bool result = false;

	if (var800ab5b8[index].unk00 == 0
			|| arg1 != var800ab5b8[index].unk04
			|| arg2 != var800ab5b8[index].unk08
			|| arg3 != var800ab5b8[index].unk0c
			|| arg4 != var800ab5b8[index].unk10
			|| arg5 != var800ab5b8[index].unk14
			|| arg6 != var800ab5b8[index].unk18
			|| arg7 != var800ab5b8[index].unk1c
			|| arg8 != var800ab5b8[index].unk20
			|| arg9 != var800ab5b8[index].unk24
			|| arg10 != var800ab5b8[index].unk28) {
		result = true;
		var800ab5b8[index].unk00 = 1;
		var800ab5b8[index].unk04 = arg1;
		var800ab5b8[index].unk08 = arg2;
		var800ab5b8[index].unk0c = arg3;
		var800ab5b8[index].unk10 = arg4;
		var800ab5b8[index].unk14 = arg5;
		var800ab5b8[index].unk18 = arg6;
		var800ab5b8[index].unk1c = arg7;
		var800ab5b8[index].unk20 = arg8;
		var800ab5b8[index].unk24 = arg9;
		var800ab5b8[index].unk28 = arg10;
	}

	return result;
}

static bool tex0f173b8c(s32 index, s32 uls, s32 ult, s32 lrs, s32 lrt)
{
	bool result = false;

	if (var800ab718[index].inuse == false
			|| uls != var800ab718[index].uls
			|| ult != var800ab718[index].ult
			|| lrs != var800ab718[index].lrs
			|| lrt != var800ab718[index].lrt) {
		result = true;
		var800ab718[index].inuse = true;
		var800ab718[index].uls = uls;
		var800ab718[index].ult = ult;
		var800ab718[index].lrs = lrs;
		var800ab718[index].lrt = lrt;
	}

	return result;
}

s32 texGetWidthAtLod(struct tex *tex, s32 lod)
{
	s32 i;
	s32 width = tex->width;

	if (lod == 0) {
		return width;
	}

	if (tex->unk0c_02) {
		for (i = 0; i < g_TexCacheCount; i++) {
			if (tex->texturenum == g_TexCacheItems[i].texturenum) {
				return g_TexCacheItems[i].widths[lod - 1];
			}
		}

		return 1;
	}

	for (i = 0; i < lod; i++) {
		width = (width + 1) >> 1;
	}

	return width;
}

s32 texGetHeightAtLod(struct tex *tex, s32 lod)
{
	s32 i;
	s32 height = tex->height;

	if (lod == 0) {
		return height;
	}

	if (tex->unk0c_02) {
		for (i = 0; i < g_TexCacheCount; i++) {
			if (tex->texturenum == g_TexCacheItems[i].texturenum) {
				return g_TexCacheItems[i].heights[lod - 1];
			}
		}

		return 1;
	}

	for (i = 0; i < lod; i++) {
		height = (height + 1) >> 1;
	}

	return height;
}

static s32 texGetLineSizeInBytes(struct tex *tex, s32 lod)
{
	s32 depth = tex->depth;
	s32 width = texGetWidthAtLod(tex, lod);

	if (depth == G_IM_SIZ_32b) {
		return (width + 3) / 4;
	}

	if (depth == G_IM_SIZ_16b) {
		return (width + 3) / 4;
	}

	if (depth == G_IM_SIZ_8b) {
		return (width + 7) / 8;
	}

	return (width + 15) / 16;
}

static s32 texGetSizeInBytes(struct tex *tex, s32 lod)
{
	return texGetHeightAtLod(tex, lod) * texGetLineSizeInBytes(tex, lod);
}

void tex0f173e50(struct tex *tex, s32 *deptharg, s32 *lenarg)
{
	s32 depth = tex->depth;
	s32 maxlod = tex->maxlod ? tex->maxlod : 1;
	s32 lod;

	*lenarg = 0;

	if (depth == G_IM_SIZ_32b) {
		*deptharg = G_IM_SIZ_32b;
	} else if (depth == G_IM_SIZ_16b) {
		*deptharg = G_IM_SIZ_16b;
	} else if (depth == G_IM_SIZ_8b) {
		*deptharg = G_IM_SIZ_16b;
	} else {
		*deptharg = G_IM_SIZ_16b;
	}

	for (lod = 0; lod < maxlod; lod++) {
		*lenarg += texGetSizeInBytes(tex, lod) * 4;
	}
}

static s32 tex0f173f18(s32 arg0)
{
	s32 i = 0;

	arg0--;

	while (arg0 > 0 && i < 8) {
		arg0 >>= 1;
		i++;
	}

	return i;
}

static s32 tex0f173f48(s32 arg0)
{
	if (arg0 == 1) {
		return 2;
	}

	if (arg0 == 2) {
		return 1;
	}

	return 0;
}

static Gfx *tex0f173f78(Gfx *gdl, struct tex *tex, s32 arg2, s32 shifts, s32 shiftt, s32 arg5)
{
	struct texture *s0 = &g_Textures[tex->texturenum];
	s32 sp88;
	s32 sp84;
	s32 line;
	u32 stack[4];
	s32 uls;
	s32 ult;
	s32 lrs;
	s32 lrt;

	sp88 = tex0f173f18(tex->width);
	sp84 = tex0f173f18(tex->height);

	line = texGetLineSizeInBytes(tex, 0);

	gDPSetPrimColorViaWord(gdl++, arg5, 0, 0xffffffff);

	if (texSetLutMode(tex->lutmodeindex << G_MDSFT_TEXTLUT)) {
		gDPSetTextureLUT(gdl++, tex->lutmodeindex << G_MDSFT_TEXTLUT);
	}

	if (tex0f173a70(0, tex->gbiformat, tex->depth, line, s0->unk04_00 + line * s0->unk04_04, 0, 0, sp88 - s0->unk04_08, sp84 - s0->unk04_0c, shifts, shiftt)) {
		gDPSetTile(gdl++, tex->gbiformat, tex->depth, line, s0->unk04_00 + line * s0->unk04_04, 0, 0,
				tex0f173f48(0), sp84 - s0->unk04_0c, shiftt,
				tex0f173f48(0), sp88 - s0->unk04_08, shifts);
	}

	uls = (arg2 == 2 && !tex->unk0c_02 ? 2 : 0) + 0;
	ult = (arg2 == 2 && !tex->unk0c_02 ? 2 : 0) + 0;
	lrs = (arg2 == 2 && !tex->unk0c_02 ? 2 : 0) + ((tex->width - 1) << 2);
	lrt = (arg2 == 2 && !tex->unk0c_02 ? 2 : 0) + ((tex->height - 1) << 2);

	if (tex0f173b8c(0, uls, ult, lrs, lrt)) {
		gDPSetTileSize(gdl++, 0, uls, ult, lrs, lrt);
	}

	return gdl;
}

static Gfx *tex0f1742e4(Gfx *arg0, Gfx *arg1, struct tex *tex, bool arg3)
{
	s32 lod = tex->maxlod ? tex->maxlod - 1 : 0;

	if (arg3) {
		if (arg1 != NULL) {
			u32 v0 = (arg1->words.w0 & ~0x3800) | (lod << 11);

			if (v0 != arg1->words.w0) {
				arg0->words.w0 = v0;
				arg0->words.w1 = arg1->words.w1;
				arg0++;
			}
		} else {
			gSPTexture(arg0++, 0xffff, 0xffff, lod, G_TX_RENDERTILE, G_ON);
		}
	} else {
		arg1->words.w0 &= ~0x3800;
		arg1->words.w0 |= lod << 11;
	}

	return arg0;
}

static Gfx *tex0f1743a0(Gfx *gdl, struct tex *tex, s32 arg2)
{
	s32 depth;
	s32 len;

	tex0f173e50(tex, &depth, &len);

	if (tex->lutmodeindex == 0) {
		gDPSetTextureImage(gdl++, tex->gbiformat, depth, 1, tex->data);

		if (!var800844d0) {
			gDPPipeSync(gdl++);
			var800844d0 = true;
		}

		if (depth == G_IM_SIZ_16b && arg2 == 0) {
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, len - 1, 0);
		} else {
			if (tex0f173a70(5, 0, depth, 0, arg2, 0, 0, 0, 0, 0, 0)) {
				gDPSetTile(gdl++, G_IM_FMT_RGBA, depth, 0, arg2, 5, 0,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			}

			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, len - 1, 0);
		}
	} else {
		gDPSetTextureImage(gdl++, tex->gbiformat, depth, 1, tex->data);

		if (!var800844d0) {
			gDPPipeSync(gdl++);
			var800844d0 = true;
		}

		if (depth == G_IM_SIZ_16b && arg2 == 0) {
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, len - 1, 0);
		} else {
			if (tex0f173a70(5, 0, depth, 0, arg2, 0, 0, 0, 0, 0, 0)) {
				gDPSetTile(gdl++, G_IM_FMT_RGBA, depth, 0, arg2, 5, 0,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			}

			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, len - 1, 0);
		}

		{
			s32 tmp = len;
			s32 a2 = (u32)(0x3ff - tex->unk0a) < len ? (u32)(0x3ff - tex->unk0a) : 0;

			tmp -= a2;

			gDPLoadSync(gdl++);
			gDPLoadTLUT06(gdl++, tmp, a2, tex->unk0a + tmp, a2);
		}
	}

	return gdl;
}

static Gfx *tex0f1747a4(Gfx *gdl, struct tex *tex, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u32 arg7)
{
	u32 tmem;
	s32 maxlod;
	s32 tile;

	tmem = arg7;
	maxlod = tex->maxlod;

	if (arg6 >= 0 && arg6 < maxlod) {
		maxlod = arg6;
	}

	for (tile = arg5; tile < maxlod + arg5 && tile < 6; tile++) {
		s32 stack[2];
		s32 lod = tile - arg5;
		u32 masks = tex0f173f18(texGetWidthAtLod(tex, lod));
		u32 maskt = tex0f173f18(texGetHeightAtLod(tex, lod));
		s32 line = texGetLineSizeInBytes(tex, lod);
		s32 uls;
		s32 ult;
		s32 lrs;
		s32 lrt;
		s32 bytes = texGetSizeInBytes(tex, lod);
		s32 sp7c = tex->unk0c_02;

		if (texSetLutMode(tex->lutmodeindex << G_MDSFT_TEXTLUT)) {
			gDPSetTextureLUT(gdl++, tex->lutmodeindex << G_MDSFT_TEXTLUT);
		}

		if (tex0f173a70(tile, tex->gbiformat, tex->depth, line, tmem, arg2, arg3, masks, maskt, lod, lod)) {
			gDPSetTile(gdl++, tex->gbiformat, tex->depth, line, tmem, tile, 0,
					tex0f173f48(arg3), maskt, lod,
					tex0f173f48(arg2), masks, tile - arg5);
		}

		uls = (arg4 == 2 && sp7c == 0 ? 2 : 0) + 0;
		ult = (arg4 == 2 && sp7c == 0 ? 2 : 0) + 0;
		lrs = ((texGetWidthAtLod(tex, lod) - 1) << 2) + (arg4 == 2 && sp7c == 0 ? 2 : 0);
		lrt = ((texGetHeightAtLod(tex, lod) - 1) << 2) + (arg4 == 2 && sp7c == 0 ? 2 : 0);

		if (tex0f173b8c(tile, uls, ult, lrs, lrt)) {
			gDPSetTileSize(gdl++, tile, uls, ult, lrs, lrt);
		}

		tmem += bytes;
	}

	return gdl;
}

static Gfx *tex0f174b54(Gfx *gdl, struct tex *tex)
{
	s32 depth;
	s32 len;

	tex0f173e50(tex, &depth, &len);

	if (tex->lutmodeindex == 0) {
		gDPSetTextureImage(gdl++, tex->gbiformat, depth, 1, tex->data);

		if (!var800844d0) {
			gDPPipeSync(gdl++);
			var800844d0 = true;
		}

		if (depth == G_IM_SIZ_16b) {
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, len - 1, 0);
		} else {
			if (tex0f173a70(5, 0, depth, 0, 0, 0, 0, 0, 0, 0, 0)) {
				gDPSetTile(gdl++, G_IM_FMT_RGBA, depth, 0, 0x0000, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			}

			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, len - 1, 0);
		}
	} else {
		gDPSetTextureImage(gdl++, tex->gbiformat, depth, 1, tex->data);

		if (!var800844d0) {
			gDPPipeSync(gdl++);
			var800844d0 = true;
		}

		if (depth == G_IM_SIZ_16b) {
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, len - 1, 0);
		} else {
			if (tex0f173a70(5, 0, depth, 0, 0, 0, 0, 0, 0, 0, 0)) {
				gDPSetTile(gdl++, G_IM_FMT_RGBA, depth, 0, 0x0000, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			}

			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, len - 1, 0);
		}

		{
			s32 tmp = len;
			s32 a2 = (u32)(0x3ff - tex->unk0a) < len ? (u32)(0x3ff - tex->unk0a) : 0;

			tmp -= a2;

			gDPLoadSync(gdl++);
			gDPLoadTLUT06(gdl++, tmp, a2, tex->unk0a + tmp, a2);
		}
	}

	return gdl;
}

static Gfx *tex0f174f30(Gfx *gdl, struct tex *tex, s32 arg2, s32 arg3, s32 arg4, s32 tile)
{
	s32 masks;
	s32 maskt;
	s32 line;
	s32 uls;
	s32 ult;
	s32 lrs;
	s32 lrt;
	s32 sp50;

	masks = tex0f173f18(tex->width);
	maskt = tex0f173f18(tex->height);
	line = texGetLineSizeInBytes(tex, 0);
	sp50 = tex->unk0c_02;

	if (texSetLutMode(tex->lutmodeindex << G_MDSFT_TEXTLUT)) {
		gDPSetTextureLUT(gdl++, tex->lutmodeindex << G_MDSFT_TEXTLUT);
	}

	if (tex0f173a70(tile, tex->gbiformat, tex->depth, line, 0, arg2, arg3, masks, maskt, 0, 0)) {
		gDPSetTile(gdl++, tex->gbiformat, tex->depth, line, 0x0000, tile, 0,
				tex0f173f48(arg3), maskt, G_TX_NOLOD,
				tex0f173f48(arg2), masks, G_TX_NOLOD);
	}

	uls = (arg4 == 2 && sp50 == 0 ? 2 : 0) + 0;
	ult = (arg4 == 2 && sp50 == 0 ? 2 : 0) + 0;
	lrs = (arg4 == 2 && sp50 == 0 ? 2 : 0) + ((tex->width - 1) << 2);
	lrt = (arg4 == 2 && sp50 == 0 ? 2 : 0) + ((tex->height - 1) << 2);

	if (tex0f173b8c(tile, uls, ult, lrs, lrt)) {
		gDPSetTileSize(gdl++, tile, uls, ult, lrs, lrt);
	}

	return gdl;
}

static Gfx *tex0f1751e4(Gfx *gdl, struct tex *tex, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
	s32 sp34 = 0;

	gdl = tex0f1743a0(gdl, tex, 0);

	if (arg5) {
		gdl = tex0f1747a4(gdl, tex, arg2, arg3, arg4, 0, 1, 0);
		sp34++;
	}

	gdl = tex0f1747a4(gdl, tex, arg2, arg3, arg4, sp34, -1, 0);

	sp34 += tex->maxlod;

	if (!arg5 && tex->maxlod == 1) {
		gdl = tex0f1747a4(gdl, tex, arg2, arg3, arg4, sp34, -1, 0);
	}

	gDPPipeSync(gdl++);

	var800844d0 = true;

	return gdl;
}

static Gfx *tex0f175308(Gfx *gdl, struct tex *tex1, s32 arg2, s32 arg3, s32 arg4, struct tex *tex2, s32 arg6, s32 arg7, s32 arg8, bool arg9)
{
	s32 size = texGetSizeInBytes(tex2, 0);
	s32 sp38 = 0;

	gdl = tex0f174b54(gdl, tex2);

	gDPTileSync(gdl++);

	gdl = tex0f1743a0(gdl, tex1, size);
	gdl = tex0f173f78(gdl, tex2, arg4, arg6, arg7, arg8);

	sp38++;

	if (arg9) {
		gdl = tex0f1747a4(gdl, tex1, arg2, arg3, arg4, sp38, 1, size);
		sp38++;
	}

	gdl = tex0f1747a4(gdl, tex1, arg2, arg3, arg4, sp38, -1, size);

	sp38 += tex1->maxlod;

	if (!arg9 && tex1->maxlod == 1) {
		gdl = tex0f1747a4(gdl, tex1, arg2, arg3, arg4, sp38, -1, size);
	}

	gDPPipeSync(gdl++);

	var800844d0 = true;

	return gdl;
}

static Gfx *tex0f175490(Gfx *gdl, struct tex *tex, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, bool arg8)
{
	s32 sp34 = 0;

	gdl = tex0f1743a0(gdl, tex, 0);
	gdl = tex0f173f78(gdl, tex, arg4, arg5, arg6, arg7);

	sp34++;

	if (arg8) {
		gdl = tex0f1747a4(gdl, tex, arg2, arg3, arg4, sp34, 1, 0);
		sp34++;
	}

	gdl = tex0f1747a4(gdl, tex, arg2, arg3, arg4, sp34, -1, 0);

	sp34 += tex->maxlod;

	if (!arg8 && tex->maxlod == 1) {
		gdl = tex0f1747a4(gdl, tex, arg2, arg3, arg4, sp34, -1, 0);
	}

	gDPPipeSync(gdl++);

	var800844d0 = true;

	return gdl;
}

static Gfx *tex0f1755dc(Gfx *gdl, struct tex *tex, s32 arg2, s32 arg3, s32 arg4)
{
	gdl = tex0f174b54(gdl, tex);
	gdl = tex0f174f30(gdl, tex, arg2, arg3, arg4, 0);

	gDPPipeSync(gdl++);

	var800844d0 = true;

	return gdl;
}

static Gfx *tex0f17563c(Gfx *gdl, struct tex *tex, s32 arg2, s32 arg3, s32 arg4)
{
	gdl = tex0f174b54(gdl, tex);
	gdl = tex0f174f30(gdl, tex, arg2, arg3, arg4, 0);
	gdl = tex0f174f30(gdl, tex, arg2, arg3, arg4, 1);

	gDPPipeSync(gdl++);

	var800844d0 = true;

	return gdl;
}

s32 texLoadFromGdl(Gfx *arg0, s32 gdlsizeinbytes, Gfx *arg2, struct texpool *pool, u8 *arg4)
{
	struct tex *tex1;
	struct tex *tex2;
	Gfx *sp12c;
	s32 sp128;
	u32 tmp1;
	u32 tmp2;
	u32 tmp3;
	u32 tmp4;
	u32 tmp5;
	u32 tmp6;
	bool flag;
	s32 j;
	bool sp104;
	u8 animated;
	Gfx *s5;
	Gfx *s6;
	u32 spf4;
	s32 texturenum;
	s32 texturenum2;
	bool spe8;
	s32 spe4;
	s32 spe0;
	struct gfxvtx *spa0[16];
	u8 sp90[16];

	s32 i;

	sp12c = NULL;
	sp104 = true;
	animated = false;
	spe8 = false;
	spe4 = false;
	var800844d0 = false;
	spf4 = 0;
	s5 = arg0;
	s6 = arg2;

	sp128 = gdlsizeinbytes >> 3;

	tex0f173a08();

	spe0 = g_DyntexCurRoom >= 0;

	if (spe0) {
		for (j = 0; j < 16; j++) {
			sp90[j] = 0;
		}
	}

	if (pool == NULL) {
		pool = &g_TexSharedPool;
	}

	while (sp128 > 0) {
		switch (s5->texture.cmd) {
		case 0xc0: // Repurposed?
			spe4 = true;

			if (animated) {
				spe8 = true;
			}

			texturenum = s5->words.w1 & 0xfff;
			flag = s5->words.w0 & 0x200;

			texLoadFromTextureNum(texturenum, pool);

			tex1 = texFindInPool(texturenum, pool);

			if (tex1 != NULL) {
				spf4 = tex1->unk0c_03;
			} else {
				spf4 = 0;
			}

			if (tex1 != NULL) {
				s6 = tex0f1742e4(s6, sp12c, tex1, sp104);
				sp104 = false;
				animated = false;

				switch (s5->unkc0.subcmd) {
				case 0:
					tmp6 = (s5->words.w1 >> 24) & 0xff;
					tmp1 = (s5->words.w0 >> 22) & 3;
					tmp2 = (s5->words.w0 >> 20) & 3;
					tmp3 = (s5->words.w0 >> 18) & 3;
					tmp4 = (s5->words.w0 >> 14) & 0xf;
					tmp5 = (s5->words.w0 >> 10) & 0xf;

					s6 = tex0f175490(s6, tex1, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, flag);
					break;
				case 1:
					texturenum2 = (s5->words.w1 >> 12) & 0xfff;
					texLoadFromTextureNum(texturenum2, pool);
					tex2 = texFindInPool(texturenum2, pool);

					if (tex2 != NULL) {
						tmp6 = (s5->words.w1 >> 24) & 0xff;
						tmp1 = (s5->words.w0 >> 22) & 3;
						tmp2 = (s5->words.w0 >> 20) & 3;
						tmp3 = (s5->words.w0 >> 18) & 3;
						tmp4 = (s5->words.w0 >> 14) & 0xf;
						tmp5 = (s5->words.w0 >> 10) & 0xf;

						s6 = tex0f175308(s6, tex1, tmp1, tmp2, tmp3, tex2, tmp4, tmp5, tmp6, flag);
					}
					break;
				case 2:
					tmp1 = (s5->words.w0 >> 22) & 3;
					tmp2 = (s5->words.w0 >> 20) & 3;
					tmp3 = (s5->words.w0 >> 18) & 3;

					s6 = tex0f1751e4(s6, tex1, tmp1, tmp2, tmp3, flag);
					break;
				case 3:
					tmp1 = (s5->words.w0 >> 22) & 3;
					tmp2 = (s5->words.w0 >> 20) & 3;
					tmp3 = (s5->words.w0 >> 18) & 3;

					s6 = tex0f17563c(s6, tex1, tmp1, tmp2, tmp3);
					break;
				case 4:
					tmp1 = (s5->words.w0 >> 22) & 3;
					tmp2 = (s5->words.w0 >> 20) & 3;
					tmp3 = (s5->words.w0 >> 18) & 3;

					s6 = tex0f1755dc(s6, tex1, tmp1, tmp2, tmp3);
					break;
				}

				if (spe0 != 0) {
					// Deep Sea - green river under floor
					if (texturenum == TEXTURE_06CB) {
						dyntexSetCurrentType(DYNTEXTYPE_RIVER);
						animated = true;
					}

					// Deep Sea - juice that flows inside SA megaweapon
					// Attack Ship - juice that flows inside engine power node
					if (texturenum == TEXTURE_0A6A) {
						dyntexSetCurrentType(DYNTEXTYPE_POWERJUICE);
						animated = true;
					}

					// Deep Sea - white rings around SA megaweapon node
					// Attack Ship - white rings around engine power node
					if (texturenum == TEXTURE_0A69) {
						dyntexSetCurrentType(DYNTEXTYPE_POWERRING);
						animated = true;
					}

					// Deep Sea - teleport
					if (texturenum == TEXTURE_06E2) {
						dyntexSetCurrentType(DYNTEXTYPE_TELEPORTAL);
						animated = true;
					}

					// 01c7 - Air Base - distant water
					// 01c7 - Investigation - puddle behind glass near shield
					// 0dae - Chicago - canal
					// 0dae - Villa - shallow water
					// 0dae - Sewers (MP)
					if (texturenum == TEXTURE_01C7 || texturenum == TEXTURE_0DAE) {
						dyntexSetCurrentType(DYNTEXTYPE_RIVER);
						animated = true;
					}

					// Air Force One - Monitor
					if (texturenum == TEXTURE_029B) {
						dyntexSetCurrentType(DYNTEXTYPE_MONITOR);
						animated = true;
					}

					// Villa - deep water
					// Complex - water
					if (texturenum == TEXTURE_090F) {
						dyntexSetCurrentType(DYNTEXTYPE_OCEAN);
						animated = true;
					}

					// Attack Ship - triangular arrows
					if (texturenum == TEXTURE_0A42) {
						dyntexSetCurrentType(DYNTEXTYPE_ARROWS);
						animated = true;
					}
				}
			}

			s5++;
			break;
		case G_VTX:
			{
				s32 start;
				s32 count;
				u32 offset;
				struct gfxvtx *vtx;

				if (spe0) {
					start = s5->bytes[1] & 0xf;
					count = s5->vtx.unk08 + 1;
					vtx = (struct gfxvtx *)(s5->dma.addr & 0x00ffffff);

					for (i = start; i < start + count; i++) {
						if (animated && sp90[i]) {
							dyntexAddVertex(spa0[i]);
							sp90[i] = 0;
						}

						spa0[i] = vtx;
						vtx++;
					}
				}

				if (spf4 && arg4) {
					s32 count = s5->vtx.unk08 + 1;
					struct gfxvtx *vtx;
					s32 i;

					offset = s5->dma.addr & 0x00ffffff;
					vtx = (struct gfxvtx *) (arg4 + offset);

					for (i = 0; i < count; i++) {
						vtx[i].s >>= 1;
						vtx[i].t >>= 1;
					}
				}
			}

			*s6 = *s5;
			s6++;
			s5++;
			break;
		case G_RDPPIPESYNC:
			var800844d0 = true;
			*s6 = *s5;
			s6++;
			s5++;
			break;
		case (u8) G_TRI4:
		case (u8) G_TRI1:
			if (animated) {
				if (s5->texture.cmd == (u8) G_TRI1) {
					sp90[s5->tri.tri.v[0] / 10] = 1;
					sp90[s5->tri.tri.v[1] / 10] = 1;
					sp90[s5->tri.tri.v[2] / 10] = 1;
				} else {
					Gfx *tmp = s5;

					if (tmp->tri4.x1 != tmp->tri4.y1 || tmp->tri4.z1 != tmp->tri4.y1) {
						sp90[tmp->tri4.x1] = 1;
						sp90[tmp->tri4.y1] = 1;
						sp90[tmp->tri4.z1] = 1;
					}

					if (tmp->tri4.x2 != tmp->tri4.y2 || tmp->tri4.z2 != tmp->tri4.y2) {
						sp90[tmp->tri4.x2] = 1;
						sp90[tmp->tri4.y2] = 1;
						sp90[tmp->tri4.z2] = 1;
					}

					if (tmp->tri4.x3 != tmp->tri4.y3 || tmp->tri4.z3 != tmp->tri4.y3) {
						sp90[tmp->tri4.x3] = 1;
						sp90[tmp->tri4.y3] = 1;
						sp90[tmp->tri4.z3] = 1;
					}

					if (tmp->tri4.x4 != tmp->tri4.y4 || tmp->tri4.z4 != tmp->tri4.y4) {
						sp90[tmp->tri4.x4] = 1;
						sp90[tmp->tri4.y4] = 1;
						sp90[tmp->tri4.z4] = 1;
					}
				}
			}

			sp104 = true;
			var800844d0 = false;

			*s6 = *s5;
			s6++;
			s5++;
			break;
		case (u8) G_TEXTURE:
			spe4 = true;

			if (animated) {
				spe8 = true;
			}

			animated = false;
			sp104 = false;

			sp12c = s6;
			*s6 = *s5;
			s6++;
			s5++;
			break;
		case (u8) G_SETOTHERMODE_H:
			*s6 = *s5;
			s6++;
			s5++;
			break;
		default:
			*s6 = *s5;
			s6++;
			s5++;
			break;
		}

		sp128--;

		if (spe4 || sp128 <= 0) {
			spe4 = false;

			if (spe8 || animated) {
				s32 i;

				spe8 = false;

				for (i = 0; i < 16; i++) {
					if (sp90[i]) {
						dyntexAddVertex(spa0[i]);
						sp90[i] = 0;
					}
				}
			}
		}
	}

	return (u32) s6 - (u32) arg2;
}

void texCopyGdls(Gfx *src, Gfx *dst, s32 arg2)
{
	arg2 = (arg2 >> 3);
	src = src + (arg2 - 1);
	dst = dst + (arg2 - 1);

	while (arg2--) {
		dst->force_structure_alignment = src->force_structure_alignment;
		dst--;
		src--;
	}
}
