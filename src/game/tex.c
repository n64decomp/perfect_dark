#include <ultra64.h>
#include "constants.h"
#include "game/game_13b670.h"
#include "game/tex.h"
#include "game/texdecompress.h"
#include "bss.h"
#include "data.h"
#include "textures.h"
#include "types.h"

s32 g_TexLutMode;
u32 var800ab5b4;
struct var800ab5b8 var800ab5b8[8];
struct var800ab718 var800ab718[8];

// Default
u16 g_SurfaceTypeDefaultSounds[] = { SFX_HIT_STONE_8087, SFX_HIT_STONE_8088 };
u8 var80084334[] = { 6 };

struct surfacetype g_SurfaceTypeDefault = {
	g_SurfaceTypeDefaultSounds, var80084334, 2, 1,
};

// Stone
u16 var80084344[] = { SFX_HIT_STONE_8087, SFX_HIT_STONE_8088 };
u8 var80084348[] = { 1 };

struct surfacetype g_SurfaceTypeStone = {
	var80084344, var80084348, 2, 1,
};

// Wood
u16 g_SurfaceTypeWoodSounds[] = { SFX_HIT_WOOD_807E, SFX_HIT_WOOD_807F };
u8 var8008435c[] = { 0x10 };

struct surfacetype g_SurfaceTypeWood = {
	g_SurfaceTypeWoodSounds, var8008435c, 2, 1,
};

// Metal
u16 g_SurfaceTypeMetalSounds[] = { SFX_HIT_METAL_8079, SFX_HIT_METAL_807B };
u8 var80084370[] = { 0x11 };

struct surfacetype g_SurfaceTypeMetal = {
	g_SurfaceTypeMetalSounds, var80084370, 2, 1,
};

// Glass
u16 g_SurfaceTypeGlassSounds[] = { SFX_HIT_GLASS };
u8 var80084384[] = { 3, 4, 5 };

struct surfacetype g_SurfaceTypeGlass = {
	g_SurfaceTypeGlassSounds, var80084384, 1, 3,
};

// Snow
u16 g_SurfaceTypeSnowSounds[] = { SFX_HIT_SNOW };
u8 var80084398[] = { 1 };

struct surfacetype g_SurfaceTypeSnow = {
	g_SurfaceTypeSnowSounds, var80084398, 1, 1,
};

// Dirt
u16 g_SurfaceTypeDirtSounds[] = { SFX_HIT_DIRT_8084, SFX_HIT_DIRT_8085 };
u8 var800843ac[] = { 2 };

struct surfacetype g_SurfaceTypeDirt = {
	g_SurfaceTypeDirtSounds, var800843ac, 2, 1,
};

// Mud
u16 g_SurfaceTypeMudSounds[] = { SFX_HIT_MUD_8081, SFX_HIT_MUD_8082, SFX_HIT_MUD_8083 };
u8 var800843c4[] = { 2 };

struct surfacetype g_SurfaceTypeMud = {
	g_SurfaceTypeMudSounds, var800843c4, 3, 1,
};

// Tile
u16 g_SurfaceTypeTileSounds[] = { SFX_HIT_TILE };
u8 var800843d8[] = { 1 };

struct surfacetype g_SurfaceTypeTile = {
	g_SurfaceTypeTileSounds, var800843d8, 1, 1,
};

// Metal obj
u16 g_SurfaceTypeMetalObjSounds[] = { SFX_HIT_METALOBJ_8089, SFX_HIT_METALOBJ_808A };
u8 var800843ec[] = { 1, 6 };

struct surfacetype g_SurfaceTypeMetalObj = {
	g_SurfaceTypeMetalObjSounds, var800843ec, 2, 2,
};

// Chr
u16 g_SurfaceTypeChrSounds[] = { SFX_HIT_CHR };
u8 var80084400[] = { 2 };

struct surfacetype g_SurfaceTypeChr = {
	g_SurfaceTypeChrSounds, var80084400, 1, 1,
};

// Glass XLU
u16 g_SurfaceTypeGlassXluSounds[] = { SFX_HIT_GLASS };
u8 var80084414[] = { 3, 4, 5 };

struct surfacetype g_SurfaceTypeGlassXlu = {
	g_SurfaceTypeGlassXluSounds, var80084414, 1, 3,
};

// None
struct surfacetype g_SurfaceTypeNone = {
	NULL, NULL, 0, 0,
};

// Shallow water
u16 g_SurfaceTypeShallowWaterSounds[] = { SFX_HIT_WATER };
u8 var80084434[] = { 0 };

struct surfacetype g_SurfaceTypeShallowWater = {
	g_SurfaceTypeShallowWaterSounds, var80084434, 1, 1,
};

// Deep water
u16 g_SurfaceTypeDeepWaterSounds[] = { SFX_HIT_WATER };
u8 var80084448[] = { 0 };

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

char *var80084494[] = {
	"default",
	"stone",
	"wood",
	"metal",
	"glass",
	"shallow water",
	"snow",
	"dirt",
	"mud",
	"tile",
	"metalobj",
	"chr",
	"glass xlu",
	"no hit",
	"deep water",
};

const char var7f1b7c24[] = "";
const char var7f1b7c28[] = "";
const char var7f1b7c2c[] = "";

bool var800844d0 = false;
u32 var800844d4 = 0x00000000;
u32 var800844d8 = 0x00000000;
u32 var800844dc = 0x00000000;
u32 var800844e0 = 0x00000103;
u32 var800844e4 = 0x00000000;
u32 var800844e8 = 0x00000000;
u32 var800844ec = 0x00000000;

void tex0f173a00(void)
{
	// empty
}

void tex0f173a08(void)
{
	s32 i;

	for (i = 0; i < 8; i++) {
		var800ab5b8[i].unk00 = 0;
		var800ab718[i].inuse = false;
	}

	g_TexLutMode = -1;
}

bool texSetLutMode(u32 lutmode)
{
	if (g_TexLutMode == lutmode) {
		return false;
	}

	g_TexLutMode = lutmode;
	return true;
}

bool tex0f173a70(s32 index, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10)
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

bool tex0f173b8c(s32 index, s32 uls, s32 ult, s32 lrs, s32 lrt)
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

s32 texGetWidthAtLod(struct texloadthing *arg0, s32 lod)
{
	s32 i;
	s32 width = arg0->width;

	if (lod == 0) {
		return width;
	}

	if (arg0->unk0c_02) {
		for (i = 0; i < g_TexCacheCount; i++) {
			if (arg0->texturenum == g_TexCacheItems[i].texturenum) {
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

s32 texGetHeightAtLod(struct texloadthing *arg0, s32 lod)
{
	s32 i;
	s32 height = arg0->height;

	if (lod == 0) {
		return height;
	}

	if (arg0->unk0c_02) {
		for (i = 0; i < g_TexCacheCount; i++) {
			if (arg0->texturenum == g_TexCacheItems[i].texturenum) {
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

s32 texGetLineSizeInBytes(struct texloadthing *arg0, s32 lod)
{
	s32 depth = arg0->depth;
	s32 width = texGetWidthAtLod(arg0, lod);

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

s32 texGetSizeInBytes(struct texloadthing *arg0, s32 lod)
{
	return texGetHeightAtLod(arg0, lod) * texGetLineSizeInBytes(arg0, lod);
}

void tex0f173e50(struct texloadthing *arg0, s32 *deptharg, s32 *lenarg)
{
	s32 depth = arg0->depth;
	s32 maxlod = arg0->maxlod ? arg0->maxlod : 1;
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
		*lenarg += texGetSizeInBytes(arg0, lod) * 4;
	}
}

s32 tex0f173f18(s32 arg0)
{
	s32 i = 0;

	arg0--;

	while (arg0 > 0 && i < 8) {
		arg0 >>= 1;
		i++;
	}

	return i;
}

s32 tex0f173f48(s32 arg0)
{
	if (arg0 == 1) {
		return 2;
	}

	if (arg0 == 2) {
		return 1;
	}

	return 0;
}

GLOBAL_ASM(
glabel tex0f173f78
/*  f173f78:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f173f7c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f173f80:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f173f84:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f173f88:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f173f8c:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f173f90:	afa7009c */ 	sw	$a3,0x9c($sp)
/*  f173f94:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f173f98:	3c19800b */ 	lui	$t9,%hi(g_Textures)
/*  f173f9c:	8f39abc0 */ 	lw	$t9,%lo(g_Textures)($t9)
/*  f173fa0:	000e7d02 */ 	srl	$t7,$t6,0x14
/*  f173fa4:	00809025 */ 	or	$s2,$a0,$zero
/*  f173fa8:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f173fac:	00a08825 */ 	or	$s1,$a1,$zero
/*  f173fb0:	90a40008 */ 	lbu	$a0,0x8($a1)
/*  f173fb4:	0fc5cfc6 */ 	jal	tex0f173f18
/*  f173fb8:	03198021 */ 	addu	$s0,$t8,$t9
/*  f173fbc:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f173fc0:	0fc5cfc6 */ 	jal	tex0f173f18
/*  f173fc4:	92240009 */ 	lbu	$a0,0x9($s1)
/*  f173fc8:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f173fcc:	02202025 */ 	or	$a0,$s1,$zero
/*  f173fd0:	0fc5cf58 */ 	jal	texGetLineSizeInBytes
/*  f173fd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f173fd8:	8fa800a4 */ 	lw	$t0,0xa4($sp)
/*  f173fdc:	02401825 */ 	or	$v1,$s2,$zero
/*  f173fe0:	3c01fa00 */ 	lui	$at,0xfa00
/*  f173fe4:	310900ff */ 	andi	$t1,$t0,0xff
/*  f173fe8:	00095200 */ 	sll	$t2,$t1,0x8
/*  f173fec:	01415825 */ 	or	$t3,$t2,$at
/*  f173ff0:	240cffff */ 	addiu	$t4,$zero,-1
/*  f173ff4:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f173ff8:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f173ffc:	8e24000c */ 	lw	$a0,0xc($s1)
/*  f174000:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f174004:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f174008:	00046f82 */ 	srl	$t5,$a0,0x1e
/*  f17400c:	0fc5ce91 */ 	jal	texSetLutMode
/*  f174010:	000d2380 */ 	sll	$a0,$t5,0xe
/*  f174014:	1040000a */ 	beqz	$v0,.L0f174040
/*  f174018:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f17401c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f174020:	35ef0e02 */ 	ori	$t7,$t7,0xe02
/*  f174024:	02401025 */ 	or	$v0,$s2,$zero
/*  f174028:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f17402c:	8e38000c */ 	lw	$t8,0xc($s1)
/*  f174030:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f174034:	0018cf82 */ 	srl	$t9,$t8,0x1e
/*  f174038:	00194380 */ 	sll	$t0,$t9,0xe
/*  f17403c:	ac480004 */ 	sw	$t0,0x4($v0)
.L0f174040:
/*  f174040:	920c0004 */ 	lbu	$t4,0x4($s0)
/*  f174044:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f174048:	8e220008 */ 	lw	$v0,0x8($s1)
/*  f17404c:	318d000f */ 	andi	$t5,$t4,0xf
/*  f174050:	00ed0019 */ 	multu	$a3,$t5
/*  f174054:	000a5f02 */ 	srl	$t3,$t2,0x1c
/*  f174058:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f17405c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f174060:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f174064:	00022ec0 */ 	sll	$a1,$v0,0x1b
/*  f174068:	00054f42 */ 	srl	$t1,$a1,0x1d
/*  f17406c:	01202825 */ 	or	$a1,$t1,$zero
/*  f174070:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f174074:	00002025 */ 	or	$a0,$zero,$zero
/*  f174078:	00007012 */ 	mflo	$t6
/*  f17407c:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f174080:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f174084:	92190005 */ 	lbu	$t9,0x5($s0)
/*  f174088:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f17408c:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f174090:	00194102 */ 	srl	$t0,$t9,0x4
/*  f174094:	03084823 */ 	subu	$t1,$t8,$t0
/*  f174098:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f17409c:	960c0004 */ 	lhu	$t4,0x4($s0)
/*  f1740a0:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f1740a4:	30460003 */ 	andi	$a2,$v0,0x3
/*  f1740a8:	318d000f */ 	andi	$t5,$t4,0xf
/*  f1740ac:	014d5823 */ 	subu	$t3,$t2,$t5
/*  f1740b0:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f1740b4:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f1740b8:	0fc5ce9c */ 	jal	tex0f173a70
/*  f1740bc:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f1740c0:	1040003c */ 	beqz	$v0,.L0f1741b4
/*  f1740c4:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f1740c8:	8e2a0008 */ 	lw	$t2,0x8($s1)
/*  f1740cc:	3c01f500 */ 	lui	$at,0xf500
/*  f1740d0:	30ef01ff */ 	andi	$t7,$a3,0x1ff
/*  f1740d4:	000acec0 */ 	sll	$t9,$t2,0x1b
/*  f1740d8:	314d0003 */ 	andi	$t5,$t2,0x3
/*  f1740dc:	920a0004 */ 	lbu	$t2,0x4($s0)
/*  f1740e0:	000d5cc0 */ 	sll	$t3,$t5,0x13
/*  f1740e4:	0019c742 */ 	srl	$t8,$t9,0x1d
/*  f1740e8:	314d000f */ 	andi	$t5,$t2,0xf
/*  f1740ec:	00ed0019 */ 	multu	$a3,$t5
/*  f1740f0:	33080007 */ 	andi	$t0,$t8,0x7
/*  f1740f4:	00084d40 */ 	sll	$t1,$t0,0x15
/*  f1740f8:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f1740fc:	01216025 */ 	or	$t4,$t1,$at
/*  f174100:	018b7025 */ 	or	$t6,$t4,$t3
/*  f174104:	000fca40 */ 	sll	$t9,$t7,0x9
/*  f174108:	00084f02 */ 	srl	$t1,$t0,0x1c
/*  f17410c:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f174110:	02401825 */ 	or	$v1,$s2,$zero
/*  f174114:	00006012 */ 	mflo	$t4
/*  f174118:	012c5821 */ 	addu	$t3,$t1,$t4
/*  f17411c:	316f01ff */ 	andi	$t7,$t3,0x1ff
/*  f174120:	030f7025 */ 	or	$t6,$t8,$t7
/*  f174124:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f174128:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f17412c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f174130:	0fc5cfd2 */ 	jal	tex0f173f48
/*  f174134:	00002025 */ 	or	$a0,$zero,$zero
/*  f174138:	00002025 */ 	or	$a0,$zero,$zero
/*  f17413c:	0fc5cfd2 */ 	jal	tex0f173f48
/*  f174140:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f174144:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f174148:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f17414c:	96180004 */ 	lhu	$t8,0x4($s0)
/*  f174150:	30590003 */ 	andi	$t9,$v0,0x3
/*  f174154:	306a0003 */ 	andi	$t2,$v1,0x3
/*  f174158:	000a6c80 */ 	sll	$t5,$t2,0x12
/*  f17415c:	00194200 */ 	sll	$t0,$t9,0x8
/*  f174160:	010d4825 */ 	or	$t1,$t0,$t5
/*  f174164:	01987823 */ 	subu	$t7,$t4,$t8
/*  f174168:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*  f17416c:	31ee000f */ 	andi	$t6,$t7,0xf
/*  f174170:	920f0005 */ 	lbu	$t7,0x5($s0)
/*  f174174:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f174178:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f17417c:	01395025 */ 	or	$t2,$t1,$t9
/*  f174180:	310d000f */ 	andi	$t5,$t0,0xf
/*  f174184:	000d5a80 */ 	sll	$t3,$t5,0xa
/*  f174188:	014b6025 */ 	or	$t4,$t2,$t3
/*  f17418c:	000f7102 */ 	srl	$t6,$t7,0x4
/*  f174190:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f174194:	030e4823 */ 	subu	$t1,$t8,$t6
/*  f174198:	3139000f */ 	andi	$t9,$t1,0xf
/*  f17419c:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f1741a0:	00194100 */ 	sll	$t0,$t9,0x4
/*  f1741a4:	01886825 */ 	or	$t5,$t4,$t0
/*  f1741a8:	314b000f */ 	andi	$t3,$t2,0xf
/*  f1741ac:	01ab7825 */ 	or	$t7,$t5,$t3
/*  f1741b0:	af0f0004 */ 	sw	$t7,0x4($t8)
.L0f1741b4:
/*  f1741b4:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f1741b8:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f1741bc:	00001825 */ 	or	$v1,$zero,$zero
/*  f1741c0:	14820007 */ 	bne	$a0,$v0,.L0f1741e0
/*  f1741c4:	00000000 */ 	nop
/*  f1741c8:	8e2e000c */ 	lw	$t6,0xc($s1)
/*  f1741cc:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1741d0:	07200003 */ 	bltz	$t9,.L0f1741e0
/*  f1741d4:	00000000 */ 	nop
/*  f1741d8:	10000001 */ 	b	.L0f1741e0
/*  f1741dc:	00401825 */ 	or	$v1,$v0,$zero
.L0f1741e0:
/*  f1741e0:	14820007 */ 	bne	$a0,$v0,.L0f174200
/*  f1741e4:	00602825 */ 	or	$a1,$v1,$zero
/*  f1741e8:	8e2c000c */ 	lw	$t4,0xc($s1)
/*  f1741ec:	000c5080 */ 	sll	$t2,$t4,0x2
/*  f1741f0:	05420004 */ 	bltzl	$t2,.L0f174204
/*  f1741f4:	00001825 */ 	or	$v1,$zero,$zero
/*  f1741f8:	10000002 */ 	b	.L0f174204
/*  f1741fc:	00401825 */ 	or	$v1,$v0,$zero
.L0f174200:
/*  f174200:	00001825 */ 	or	$v1,$zero,$zero
.L0f174204:
/*  f174204:	14820007 */ 	bne	$a0,$v0,.L0f174224
/*  f174208:	00603025 */ 	or	$a2,$v1,$zero
/*  f17420c:	8e2d000c */ 	lw	$t5,0xc($s1)
/*  f174210:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f174214:	05e20004 */ 	bltzl	$t7,.L0f174228
/*  f174218:	00001825 */ 	or	$v1,$zero,$zero
/*  f17421c:	10000002 */ 	b	.L0f174228
/*  f174220:	00401825 */ 	or	$v1,$v0,$zero
.L0f174224:
/*  f174224:	00001825 */ 	or	$v1,$zero,$zero
.L0f174228:
/*  f174228:	92380008 */ 	lbu	$t8,0x8($s1)
/*  f17422c:	270effff */ 	addiu	$t6,$t8,-1
/*  f174230:	000e4880 */ 	sll	$t1,$t6,0x2
/*  f174234:	14820007 */ 	bne	$a0,$v0,.L0f174254
/*  f174238:	00693821 */ 	addu	$a3,$v1,$t1
/*  f17423c:	8e39000c */ 	lw	$t9,0xc($s1)
/*  f174240:	00194080 */ 	sll	$t0,$t9,0x2
/*  f174244:	05020004 */ 	bltzl	$t0,.L0f174258
/*  f174248:	00001825 */ 	or	$v1,$zero,$zero
/*  f17424c:	10000002 */ 	b	.L0f174258
/*  f174250:	24030002 */ 	addiu	$v1,$zero,0x2
.L0f174254:
/*  f174254:	00001825 */ 	or	$v1,$zero,$zero
.L0f174258:
/*  f174258:	922a0009 */ 	lbu	$t2,0x9($s1)
/*  f17425c:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f174260:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f174264:	254dffff */ 	addiu	$t5,$t2,-1
/*  f174268:	000d5880 */ 	sll	$t3,$t5,0x2
/*  f17426c:	006b8021 */ 	addu	$s0,$v1,$t3
/*  f174270:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f174274:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f174278:	0fc5cee3 */ 	jal	tex0f173b8c
/*  f17427c:	00002025 */ 	or	$a0,$zero,$zero
/*  f174280:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f174284:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f174288:	1040000f */ 	beqz	$v0,.L0f1742c8
/*  f17428c:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f174290:	30af0fff */ 	andi	$t7,$a1,0xfff
/*  f174294:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f174298:	02401025 */ 	or	$v0,$s2,$zero
/*  f17429c:	3c01f200 */ 	lui	$at,0xf200
/*  f1742a0:	30ec0fff */ 	andi	$t4,$a3,0xfff
/*  f1742a4:	000c4300 */ 	sll	$t0,$t4,0xc
/*  f1742a8:	03017025 */ 	or	$t6,$t8,$at
/*  f1742ac:	30c90fff */ 	andi	$t1,$a2,0xfff
/*  f1742b0:	320a0fff */ 	andi	$t2,$s0,0xfff
/*  f1742b4:	010a6825 */ 	or	$t5,$t0,$t2
/*  f1742b8:	01c9c825 */ 	or	$t9,$t6,$t1
/*  f1742bc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1742c0:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f1742c4:	26520008 */ 	addiu	$s2,$s2,0x8
.L0f1742c8:
/*  f1742c8:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1742cc:	02401025 */ 	or	$v0,$s2,$zero
/*  f1742d0:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1742d4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1742d8:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1742dc:	03e00008 */ 	jr	$ra
/*  f1742e0:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

Gfx *tex0f1742e4(Gfx *arg0, Gfx *arg1, struct texloadthing *arg2, bool arg3)
{
	s32 lod = arg2->maxlod ? arg2->maxlod - 1 : 0;

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

Gfx *tex0f1743a0(Gfx *gdl, struct texloadthing *arg1, s32 arg2)
{
	s32 depth;
	s32 sp90;

	tex0f173e50(arg1, &depth, &sp90);

	if (arg1->lutmodeindex == 0) {
		gDPSetTextureImage(gdl++, arg1->gbiformat, depth, 1, arg1->unk04);

		if (!var800844d0) {
			gDPPipeSync(gdl++);
			var800844d0 = true;
		}

		if (depth == G_IM_SIZ_16b && arg2 == 0) {
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, sp90 - 1, 0);
		} else {
			if (tex0f173a70(5, 0, depth, 0, arg2, 0, 0, 0, 0, 0, 0)) {
				gDPSetTile(gdl++, G_IM_FMT_RGBA, depth, 0, arg2, 5, 0,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			}

			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, sp90 - 1, 0);
		}
	} else {
		gDPSetTextureImage(gdl++, arg1->gbiformat, depth, 1, arg1->unk04);

		if (!var800844d0) {
			gDPPipeSync(gdl++);
			var800844d0 = true;
		}

		if (depth == G_IM_SIZ_16b && arg2 == 0) {
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, sp90 - 1, 0);
		} else {
			if (tex0f173a70(5, 0, depth, 0, arg2, 0, 0, 0, 0, 0, 0)) {
				gDPSetTile(gdl++, G_IM_FMT_RGBA, depth, 0, arg2, 5, 0,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
						G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			}

			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, sp90 - 1, 0);
		}

		{
			s32 tmp = sp90;
			s32 a2 = (u32)(0x3ff - arg1->unk0a) < sp90 ? (u32)(0x3ff - arg1->unk0a) : 0;

			tmp -= a2;

			gDPLoadSync(gdl++);
			gDPLoadTLUT06(gdl++, tmp, a2, arg1->unk0a + tmp, a2);
		}
	}

	return gdl;
}

Gfx *tex0f1747a4(Gfx *gdl, struct texloadthing *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u32 arg7)
{
	u32 tmem;
	s32 maxlod;
	s32 tile;

	tmem = arg7;
	maxlod = arg1->maxlod;

	if (arg6 >= 0 && arg6 < maxlod) {
		maxlod = arg6;
	}

	for (tile = arg5; tile < maxlod + arg5 && tile < 6; tile++) {
		s32 stack[2];
		s32 lod = tile - arg5;
		u32 masks = tex0f173f18(texGetWidthAtLod(arg1, lod));
		u32 maskt = tex0f173f18(texGetHeightAtLod(arg1, lod));
		s32 line = texGetLineSizeInBytes(arg1, lod);
		s32 uls;
		s32 ult;
		s32 lrs;
		s32 lrt;
		s32 bytes = texGetSizeInBytes(arg1, lod);
		s32 sp7c = arg1->unk0c_02;

		if (texSetLutMode(arg1->lutmodeindex << G_MDSFT_TEXTLUT)) {
			gDPSetTextureLUT(gdl++, arg1->lutmodeindex << G_MDSFT_TEXTLUT);
		}

		if (tex0f173a70(tile, arg1->gbiformat, arg1->depth, line, tmem, arg2, arg3, masks, maskt, lod, lod)) {
			gDPSetTile(gdl++, arg1->gbiformat, arg1->depth, line, tmem, tile, 0,
					tex0f173f48(arg3), maskt, lod,
					tex0f173f48(arg2), masks, tile - arg5);
		}

		uls = uls = arg4 == 2 && sp7c == 0 ? 2 : 0;
		ult = ult = arg4 == 2 && sp7c == 0 ? 2 : 0;

		lrs = ((texGetWidthAtLod(arg1, lod) - 1) << 2) + (arg4 == 2 && sp7c == 0 ? 2 : 0);
		lrt = ((texGetHeightAtLod(arg1, lod) - 1) << 2) + (arg4 == 2 && sp7c == 0 ? 2 : 0);

		if (tex0f173b8c(tile, uls, ult, lrs, lrt)) {
			gDPSetTileSize(gdl++, tile, uls, ult, lrs, lrt);
		}

		tmem += bytes;
	}

	return gdl;
}

GLOBAL_ASM(
glabel tex0f174b54
/*  f174b54:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f174b58:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f174b5c:	00808025 */ 	or	$s0,$a0,$zero
/*  f174b60:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f174b64:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f174b68:	00a02025 */ 	or	$a0,$a1,$zero
/*  f174b6c:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f174b70:	0fc5cf94 */ 	jal	tex0f173e50
/*  f174b74:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f174b78:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*  f174b7c:	3c01fd00 */ 	lui	$at,0xfd00
/*  f174b80:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f174b84:	8d0e000c */ 	lw	$t6,0xc($t0)
/*  f174b88:	02001025 */ 	or	$v0,$s0,$zero
/*  f174b8c:	000e7f82 */ 	srl	$t7,$t6,0x1e
/*  f174b90:	15e00061 */ 	bnez	$t7,.L0f174d18
/*  f174b94:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f174b98:	8d180008 */ 	lw	$t8,0x8($t0)
/*  f174b9c:	31ae0003 */ 	andi	$t6,$t5,0x3
/*  f174ba0:	000e7cc0 */ 	sll	$t7,$t6,0x13
/*  f174ba4:	0018cec0 */ 	sll	$t9,$t8,0x1b
/*  f174ba8:	00194f42 */ 	srl	$t1,$t9,0x1d
/*  f174bac:	312a0007 */ 	andi	$t2,$t1,0x7
/*  f174bb0:	000a5d40 */ 	sll	$t3,$t2,0x15
/*  f174bb4:	01616025 */ 	or	$t4,$t3,$at
/*  f174bb8:	018fc025 */ 	or	$t8,$t4,$t7
/*  f174bbc:	02001025 */ 	or	$v0,$s0,$zero
/*  f174bc0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f174bc4:	8d190004 */ 	lw	$t9,0x4($t0)
/*  f174bc8:	3c038008 */ 	lui	$v1,%hi(var800844d0)
/*  f174bcc:	246344d0 */ 	addiu	$v1,$v1,%lo(var800844d0)
/*  f174bd0:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f174bd4:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f174bd8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174bdc:	02001025 */ 	or	$v0,$s0,$zero
/*  f174be0:	15200006 */ 	bnez	$t1,.L0f174bfc
/*  f174be4:	3c0ae700 */ 	lui	$t2,0xe700
/*  f174be8:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f174bec:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f174bf0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f174bf4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174bf8:	ac6b0000 */ 	sw	$t3,0x0($v1)
.L0f174bfc:
/*  f174bfc:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f174c00:	24010002 */ 	addiu	$at,$zero,0x2
/*  f174c04:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f174c08:	14c10018 */ 	bne	$a2,$at,.L0f174c6c
/*  f174c0c:	00002825 */ 	or	$a1,$zero,$zero
/*  f174c10:	02001825 */ 	or	$v1,$s0,$zero
/*  f174c14:	3c07e600 */ 	lui	$a3,0xe600
/*  f174c18:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174c1c:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174c20:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f174c24:	02002025 */ 	or	$a0,$s0,$zero
/*  f174c28:	3c0df300 */ 	lui	$t5,0xf300
/*  f174c2c:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f174c30:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f174c34:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174c38:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f174c3c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174c40:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f174c44:	10200003 */ 	beqz	$at,.L0f174c54
/*  f174c48:	00000000 */ 	nop
/*  f174c4c:	10000001 */ 	b	.L0f174c54
/*  f174c50:	00401825 */ 	or	$v1,$v0,$zero
.L0f174c54:
/*  f174c54:	306e0fff */ 	andi	$t6,$v1,0xfff
/*  f174c58:	000e6300 */ 	sll	$t4,$t6,0xc
/*  f174c5c:	3c010700 */ 	lui	$at,0x700
/*  f174c60:	01817825 */ 	or	$t7,$t4,$at
/*  f174c64:	100000ad */ 	b	.L0f174f1c
/*  f174c68:	ac8f0004 */ 	sw	$t7,0x4($a0)
.L0f174c6c:
/*  f174c6c:	00003825 */ 	or	$a3,$zero,$zero
/*  f174c70:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f174c74:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f174c78:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f174c7c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f174c80:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f174c84:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f174c88:	0fc5ce9c */ 	jal	tex0f173a70
/*  f174c8c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f174c90:	1040000b */ 	beqz	$v0,.L0f174cc0
/*  f174c94:	3c07e600 */ 	lui	$a3,0xe600
/*  f174c98:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f174c9c:	02001025 */ 	or	$v0,$s0,$zero
/*  f174ca0:	3c01f500 */ 	lui	$at,0xf500
/*  f174ca4:	33190003 */ 	andi	$t9,$t8,0x3
/*  f174ca8:	00194cc0 */ 	sll	$t1,$t9,0x13
/*  f174cac:	01215025 */ 	or	$t2,$t1,$at
/*  f174cb0:	3c0b0500 */ 	lui	$t3,0x500
/*  f174cb4:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f174cb8:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f174cbc:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f174cc0:
/*  f174cc0:	02001825 */ 	or	$v1,$s0,$zero
/*  f174cc4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174cc8:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174ccc:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f174cd0:	02002025 */ 	or	$a0,$s0,$zero
/*  f174cd4:	3c0df300 */ 	lui	$t5,0xf300
/*  f174cd8:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f174cdc:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f174ce0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174ce4:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f174ce8:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174cec:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f174cf0:	10200003 */ 	beqz	$at,.L0f174d00
/*  f174cf4:	00000000 */ 	nop
/*  f174cf8:	10000001 */ 	b	.L0f174d00
/*  f174cfc:	00401825 */ 	or	$v1,$v0,$zero
.L0f174d00:
/*  f174d00:	306e0fff */ 	andi	$t6,$v1,0xfff
/*  f174d04:	000e6300 */ 	sll	$t4,$t6,0xc
/*  f174d08:	3c010500 */ 	lui	$at,0x500
/*  f174d0c:	01817825 */ 	or	$t7,$t4,$at
/*  f174d10:	10000082 */ 	b	.L0f174f1c
/*  f174d14:	ac8f0004 */ 	sw	$t7,0x4($a0)
.L0f174d18:
/*  f174d18:	8d180008 */ 	lw	$t8,0x8($t0)
/*  f174d1c:	3c01fd00 */ 	lui	$at,0xfd00
/*  f174d20:	31cc0003 */ 	andi	$t4,$t6,0x3
/*  f174d24:	0018cec0 */ 	sll	$t9,$t8,0x1b
/*  f174d28:	00194f42 */ 	srl	$t1,$t9,0x1d
/*  f174d2c:	312a0007 */ 	andi	$t2,$t1,0x7
/*  f174d30:	000a5d40 */ 	sll	$t3,$t2,0x15
/*  f174d34:	01616825 */ 	or	$t5,$t3,$at
/*  f174d38:	000c7cc0 */ 	sll	$t7,$t4,0x13
/*  f174d3c:	01afc025 */ 	or	$t8,$t5,$t7
/*  f174d40:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f174d44:	8d190004 */ 	lw	$t9,0x4($t0)
/*  f174d48:	3c038008 */ 	lui	$v1,%hi(var800844d0)
/*  f174d4c:	246344d0 */ 	addiu	$v1,$v1,%lo(var800844d0)
/*  f174d50:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f174d54:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f174d58:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174d5c:	02001025 */ 	or	$v0,$s0,$zero
/*  f174d60:	15200006 */ 	bnez	$t1,.L0f174d7c
/*  f174d64:	3c0ae700 */ 	lui	$t2,0xe700
/*  f174d68:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f174d6c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f174d70:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f174d74:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174d78:	ac6b0000 */ 	sw	$t3,0x0($v1)
.L0f174d7c:
/*  f174d7c:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f174d80:	24010002 */ 	addiu	$at,$zero,0x2
/*  f174d84:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f174d88:	14c10018 */ 	bne	$a2,$at,.L0f174dec
/*  f174d8c:	00002825 */ 	or	$a1,$zero,$zero
/*  f174d90:	02001825 */ 	or	$v1,$s0,$zero
/*  f174d94:	3c07e600 */ 	lui	$a3,0xe600
/*  f174d98:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174d9c:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174da0:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f174da4:	02002025 */ 	or	$a0,$s0,$zero
/*  f174da8:	3c0ef300 */ 	lui	$t6,0xf300
/*  f174dac:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f174db0:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f174db4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174db8:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f174dbc:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174dc0:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f174dc4:	10200003 */ 	beqz	$at,.L0f174dd4
/*  f174dc8:	00000000 */ 	nop
/*  f174dcc:	10000001 */ 	b	.L0f174dd4
/*  f174dd0:	00401825 */ 	or	$v1,$v0,$zero
.L0f174dd4:
/*  f174dd4:	306c0fff */ 	andi	$t4,$v1,0xfff
/*  f174dd8:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f174ddc:	3c010700 */ 	lui	$at,0x700
/*  f174de0:	01a17825 */ 	or	$t7,$t5,$at
/*  f174de4:	1000002c */ 	b	.L0f174e98
/*  f174de8:	ac8f0004 */ 	sw	$t7,0x4($a0)
.L0f174dec:
/*  f174dec:	00003825 */ 	or	$a3,$zero,$zero
/*  f174df0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f174df4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f174df8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f174dfc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f174e00:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f174e04:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f174e08:	0fc5ce9c */ 	jal	tex0f173a70
/*  f174e0c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f174e10:	1040000b */ 	beqz	$v0,.L0f174e40
/*  f174e14:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*  f174e18:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f174e1c:	02001025 */ 	or	$v0,$s0,$zero
/*  f174e20:	3c01f500 */ 	lui	$at,0xf500
/*  f174e24:	33190003 */ 	andi	$t9,$t8,0x3
/*  f174e28:	00194cc0 */ 	sll	$t1,$t9,0x13
/*  f174e2c:	01215025 */ 	or	$t2,$t1,$at
/*  f174e30:	3c0b0500 */ 	lui	$t3,0x500
/*  f174e34:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f174e38:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f174e3c:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f174e40:
/*  f174e40:	02001825 */ 	or	$v1,$s0,$zero
/*  f174e44:	3c07e600 */ 	lui	$a3,0xe600
/*  f174e48:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174e4c:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f174e50:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f174e54:	02002025 */ 	or	$a0,$s0,$zero
/*  f174e58:	3c0ef300 */ 	lui	$t6,0xf300
/*  f174e5c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f174e60:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f174e64:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174e68:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f174e6c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f174e70:	284107ff */ 	slti	$at,$v0,0x7ff
/*  f174e74:	10200003 */ 	beqz	$at,.L0f174e84
/*  f174e78:	00000000 */ 	nop
/*  f174e7c:	10000001 */ 	b	.L0f174e84
/*  f174e80:	00401825 */ 	or	$v1,$v0,$zero
.L0f174e84:
/*  f174e84:	306c0fff */ 	andi	$t4,$v1,0xfff
/*  f174e88:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f174e8c:	3c010500 */ 	lui	$at,0x500
/*  f174e90:	01a17825 */ 	or	$t7,$t5,$at
/*  f174e94:	ac8f0004 */ 	sw	$t7,0x4($a0)
.L0f174e98:
/*  f174e98:	9118000a */ 	lbu	$t8,0xa($t0)
/*  f174e9c:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f174ea0:	241903ff */ 	addiu	$t9,$zero,0x3ff
/*  f174ea4:	03381023 */ 	subu	$v0,$t9,$t8
/*  f174ea8:	0045082b */ 	sltu	$at,$v0,$a1
/*  f174eac:	10200003 */ 	beqz	$at,.L0f174ebc
/*  f174eb0:	00003025 */ 	or	$a2,$zero,$zero
/*  f174eb4:	10000001 */ 	b	.L0f174ebc
/*  f174eb8:	00403025 */ 	or	$a2,$v0,$zero
.L0f174ebc:
/*  f174ebc:	00a62823 */ 	subu	$a1,$a1,$a2
/*  f174ec0:	02001025 */ 	or	$v0,$s0,$zero
/*  f174ec4:	30ab03ff */ 	andi	$t3,$a1,0x3ff
/*  f174ec8:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f174ecc:	30c403ff */ 	andi	$a0,$a2,0x3ff
/*  f174ed0:	3c01f000 */ 	lui	$at,0xf000
/*  f174ed4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f174ed8:	01c16025 */ 	or	$t4,$t6,$at
/*  f174edc:	00045080 */ 	sll	$t2,$a0,0x2
/*  f174ee0:	ac470000 */ 	sw	$a3,0x0($v0)
/*  f174ee4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f174ee8:	018a6825 */ 	or	$t5,$t4,$t2
/*  f174eec:	02001825 */ 	or	$v1,$s0,$zero
/*  f174ef0:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f174ef4:	910f000a */ 	lbu	$t7,0xa($t0)
/*  f174ef8:	01402025 */ 	or	$a0,$t2,$zero
/*  f174efc:	3c010600 */ 	lui	$at,0x600
/*  f174f00:	01e5c821 */ 	addu	$t9,$t7,$a1
/*  f174f04:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f174f08:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f174f0c:	01215025 */ 	or	$t2,$t1,$at
/*  f174f10:	01445825 */ 	or	$t3,$t2,$a0
/*  f174f14:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f174f18:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f174f1c:
/*  f174f1c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f174f20:	02001025 */ 	or	$v0,$s0,$zero
/*  f174f24:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f174f28:	03e00008 */ 	jr	$ra
/*  f174f2c:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

Gfx *tex0f174f30(Gfx *gdl, struct texloadthing *arg1, s32 arg2, s32 arg3, s32 arg4, s32 tile)
{
	s32 masks;
	s32 maskt;
	s32 line;
	s32 uls;
	s32 ult;
	s32 lrs;
	s32 lrt;
	s32 sp50;

	masks = tex0f173f18(arg1->width);
	maskt = tex0f173f18(arg1->height);
	line = texGetLineSizeInBytes(arg1, 0);
	sp50 = arg1->unk0c_02;

	if (texSetLutMode(arg1->lutmodeindex << G_MDSFT_TEXTLUT)) {
		gDPSetTextureLUT(gdl++, arg1->lutmodeindex << G_MDSFT_TEXTLUT);
	}

	if (tex0f173a70(tile, arg1->gbiformat, arg1->depth, line, 0, arg2, arg3, masks, maskt, 0, 0)) {
		gDPSetTile(gdl++, arg1->gbiformat, arg1->depth, line, 0x0000, tile, 0,
				tex0f173f48(arg3), maskt, G_TX_NOLOD,
				tex0f173f48(arg2), masks, G_TX_NOLOD);
	}

	uls = uls = (arg4 == 2 && sp50 == 0 ? 2 : 0);
	ult = ult = (arg4 == 2 && sp50 == 0 ? 2 : 0);
	lrs = (arg4 == 2 && sp50 == 0 ? 2 : 0) + ((arg1->width - 1) << 2);
	lrt = (arg4 == 2 && sp50 == 0 ? 2 : 0) + ((arg1->height - 1) << 2);

	if (tex0f173b8c(tile, uls, ult, lrs, lrt)) {
		gDPSetTileSize(gdl++, tile, uls, ult, lrs, lrt);
	}

	return gdl;
}

Gfx *tex0f1751e4(Gfx *gdl, struct texloadthing *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
	s32 sp34 = 0;

	gdl = tex0f1743a0(gdl, arg1, 0);

	if (arg5) {
		gdl = tex0f1747a4(gdl, arg1, arg2, arg3, arg4, 0, 1, 0);
		sp34++;
	}

	gdl = tex0f1747a4(gdl, arg1, arg2, arg3, arg4, sp34, -1, 0);

	sp34 += arg1->maxlod;

	if (!arg5 && arg1->maxlod == 1) {
		gdl = tex0f1747a4(gdl, arg1, arg2, arg3, arg4, sp34, -1, 0);
	}

	gDPPipeSync(gdl++);

	var800844d0 = true;

	return gdl;
}

Gfx *tex0f175308(Gfx *gdl, struct texloadthing *arg1, s32 arg2, s32 arg3, s32 arg4, struct texloadthing *arg5, s32 arg6, s32 arg7, s32 arg8, bool arg9)
{
	s32 size = texGetSizeInBytes(arg5, 0);
	s32 sp38 = 0;

	gdl = tex0f174b54(gdl, arg5);

	gDPTileSync(gdl++);

	gdl = tex0f1743a0(gdl, arg1, size);
	gdl = tex0f173f78(gdl, arg5, arg4, arg6, arg7, arg8);

	sp38++;

	if (arg9) {
		gdl = tex0f1747a4(gdl, arg1, arg2, arg3, arg4, sp38, 1, size);
		sp38++;
	}

	gdl = tex0f1747a4(gdl, arg1, arg2, arg3, arg4, sp38, -1, size);

	sp38 += arg1->maxlod;

	if (!arg9 && arg1->maxlod == 1) {
		gdl = tex0f1747a4(gdl, arg1, arg2, arg3, arg4, sp38, -1, size);
	}

	gDPPipeSync(gdl++);

	var800844d0 = true;

	return gdl;
}

Gfx *tex0f175490(Gfx *gdl, struct texloadthing *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, bool arg8)
{
	s32 sp34 = 0;

	gdl = tex0f1743a0(gdl, arg1, 0);
	gdl = tex0f173f78(gdl, arg1, arg4, arg5, arg6, arg7);

	sp34++;

	if (arg8) {
		gdl = tex0f1747a4(gdl, arg1, arg2, arg3, arg4, sp34, 1, 0);
		sp34++;
	}

	gdl = tex0f1747a4(gdl, arg1, arg2, arg3, arg4, sp34, -1, 0);

	sp34 += arg1->maxlod;

	if (!arg8 && arg1->maxlod == 1) {
		gdl = tex0f1747a4(gdl, arg1, arg2, arg3, arg4, sp34, -1, 0);
	}

	gDPPipeSync(gdl++);

	var800844d0 = true;

	return gdl;
}

Gfx *tex0f1755dc(Gfx *gdl, struct texloadthing *arg1, s32 arg2, s32 arg3, s32 arg4)
{
	gdl = tex0f174b54(gdl, arg1);
	gdl = tex0f174f30(gdl, arg1, arg2, arg3, arg4, 0);

	gDPPipeSync(gdl++);

	var800844d0 = true;

	return gdl;
}

Gfx *tex0f17563c(Gfx *gdl, struct texloadthing *arg1, s32 arg2, s32 arg3, s32 arg4)
{
	gdl = tex0f174b54(gdl, arg1);
	gdl = tex0f174f30(gdl, arg1, arg2, arg3, arg4, 0);
	gdl = tex0f174f30(gdl, arg1, arg2, arg3, arg4, 1);

	gDPPipeSync(gdl++);

	var800844d0 = true;

	return gdl;
}

GLOBAL_ASM(
glabel tex0f1756c0
.late_rodata
glabel jtbl_var7f1b7c30
.word .L0f175c04
.word .L0f175e28
.word .L0f175e28
.word .L0f175e28
.word .L0f175e28
.word .L0f175e28
.word .L0f175e28
.word .L0f175e28
.word .L0f175e28
.word .L0f175e0c
.word .L0f175dcc
.word .L0f175e28
.word .L0f175e28
.word .L0f175e28
.word .L0f175c04
.word .L0f1757d4
glabel jtbl_var7f1b7c70
.word .L0f175880
.word .L0f1758e4
.word .L0f17597c
.word .L0f1759b8
.word .L0f1759f0
.text
/*  f1756c0:	27bdfec8 */ 	addiu	$sp,$sp,-312
/*  f1756c4:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f1756c8:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f1756cc:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f1756d0:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f1756d4:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f1756d8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1756dc:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f1756e0:	000580c3 */ 	sra	$s0,$a1,0x3
/*  f1756e4:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f1756e8:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f1756ec:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f1756f0:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f1756f4:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f1756f8:	afa60140 */ 	sw	$a2,0x140($sp)
/*  f1756fc:	afa70144 */ 	sw	$a3,0x144($sp)
/*  f175700:	afa0012c */ 	sw	$zero,0x12c($sp)
/*  f175704:	afae0104 */ 	sw	$t6,0x104($sp)
/*  f175708:	0000f025 */ 	or	$s8,$zero,$zero
/*  f17570c:	afa000e8 */ 	sw	$zero,0xe8($sp)
/*  f175710:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f175714:	ac2044d0 */ 	sw	$zero,%lo(var800844d0)($at)
/*  f175718:	afa000f4 */ 	sw	$zero,0xf4($sp)
/*  f17571c:	0080a825 */ 	or	$s5,$a0,$zero
/*  f175720:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f175724:	0fc5ce82 */ 	jal	tex0f173a08
/*  f175728:	afb00128 */ 	sw	$s0,0x128($sp)
/*  f17572c:	0fc4f13c */ 	jal	func0f13c4f0
/*  f175730:	00000000 */ 	nop
/*  f175734:	10400006 */ 	beqz	$v0,.L0f175750
/*  f175738:	afa200e0 */ 	sw	$v0,0xe0($sp)
/*  f17573c:	27a20090 */ 	addiu	$v0,$sp,0x90
/*  f175740:	27a300a0 */ 	addiu	$v1,$sp,0xa0
.L0f175744:
/*  f175744:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f175748:	1443fffe */ 	bne	$v0,$v1,.L0f175744
/*  f17574c:	a040ffff */ 	sb	$zero,-0x1($v0)
.L0f175750:
/*  f175750:	8faf0144 */ 	lw	$t7,0x144($sp)
/*  f175754:	3c18800b */ 	lui	$t8,%hi(var800aabc8)
/*  f175758:	2718abc8 */ 	addiu	$t8,$t8,%lo(var800aabc8)
/*  f17575c:	15e00002 */ 	bnez	$t7,.L0f175768
/*  f175760:	27b70090 */ 	addiu	$s7,$sp,0x90
/*  f175764:	afb80144 */ 	sw	$t8,0x144($sp)
.L0f175768:
/*  f175768:	5a0001d5 */ 	blezl	$s0,.L0f175ec0
/*  f17576c:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f175770:	92a30000 */ 	lbu	$v1,0x0($s5)
.L0f175774:
/*  f175774:	286100c1 */ 	slti	$at,$v1,0xc1
/*  f175778:	14200006 */ 	bnez	$at,.L0f175794
/*  f17577c:	00601025 */ 	or	$v0,$v1,$zero
/*  f175780:	240100e7 */ 	addiu	$at,$zero,0xe7
/*  f175784:	10410116 */ 	beq	$v0,$at,.L0f175be0
/*  f175788:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f17578c:	100001a7 */ 	b	.L0f175e2c
/*  f175790:	8ea10000 */ 	lw	$at,0x0($s5)
.L0f175794:
/*  f175794:	28410005 */ 	slti	$at,$v0,0x5
/*  f175798:	14200009 */ 	bnez	$at,.L0f1757c0
/*  f17579c:	2459ff4f */ 	addiu	$t9,$v0,-177
/*  f1757a0:	2f210010 */ 	sltiu	$at,$t9,0x10
/*  f1757a4:	102001a0 */ 	beqz	$at,.L0f175e28
/*  f1757a8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1757ac:	3c017f1b */ 	lui	$at,%hi(jtbl_var7f1b7c30)
/*  f1757b0:	00390821 */ 	addu	$at,$at,$t9
/*  f1757b4:	8c397c30 */ 	lw	$t9,%lo(jtbl_var7f1b7c30)($at)
/*  f1757b8:	03200008 */ 	jr	$t9
/*  f1757bc:	00000000 */ 	nop
.L0f1757c0:
/*  f1757c0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1757c4:	104100c8 */ 	beq	$v0,$at,.L0f175ae8
/*  f1757c8:	8fb800e0 */ 	lw	$t8,0xe0($sp)
/*  f1757cc:	10000197 */ 	b	.L0f175e2c
/*  f1757d0:	8ea10000 */ 	lw	$at,0x0($s5)
.L0f1757d4:
/*  f1757d4:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1757d8:	13c00003 */ 	beqz	$s8,.L0f1757e8
/*  f1757dc:	afac00e4 */ 	sw	$t4,0xe4($sp)
/*  f1757e0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1757e4:	afad00e8 */ 	sw	$t5,0xe8($sp)
.L0f1757e8:
/*  f1757e8:	8eb20004 */ 	lw	$s2,0x4($s5)
/*  f1757ec:	8eb30000 */ 	lw	$s3,0x0($s5)
/*  f1757f0:	8fa50144 */ 	lw	$a1,0x144($sp)
/*  f1757f4:	32440fff */ 	andi	$a0,$s2,0xfff
/*  f1757f8:	326f0200 */ 	andi	$t7,$s3,0x200
/*  f1757fc:	00809025 */ 	or	$s2,$a0,$zero
/*  f175800:	0fc5cd3a */ 	jal	texLoadFromTextureNum
/*  f175804:	01e09825 */ 	or	$s3,$t7,$zero
/*  f175808:	02402025 */ 	or	$a0,$s2,$zero
/*  f17580c:	0fc5cba3 */ 	jal	tex0f172e8c
/*  f175810:	8fa50144 */ 	lw	$a1,0x144($sp)
/*  f175814:	10400006 */ 	beqz	$v0,.L0f175830
/*  f175818:	00408825 */ 	or	$s1,$v0,$zero
/*  f17581c:	8c58000c */ 	lw	$t8,0xc($v0)
/*  f175820:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f175824:	001967c2 */ 	srl	$t4,$t9,0x1f
/*  f175828:	10000002 */ 	b	.L0f175834
/*  f17582c:	afac00f4 */ 	sw	$t4,0xf4($sp)
.L0f175830:
/*  f175830:	afa000f4 */ 	sw	$zero,0xf4($sp)
.L0f175834:
/*  f175834:	104000aa */ 	beqz	$v0,.L0f175ae0
/*  f175838:	02c02025 */ 	or	$a0,$s6,$zero
/*  f17583c:	8fa70104 */ 	lw	$a3,0x104($sp)
/*  f175840:	afa00104 */ 	sw	$zero,0x104($sp)
/*  f175844:	8fa5012c */ 	lw	$a1,0x12c($sp)
/*  f175848:	02203025 */ 	or	$a2,$s1,$zero
/*  f17584c:	0fc5d0b9 */ 	jal	tex0f1742e4
/*  f175850:	0000f025 */ 	or	$s8,$zero,$zero
/*  f175854:	8ea30000 */ 	lw	$v1,0x0($s5)
/*  f175858:	0040b025 */ 	or	$s6,$v0,$zero
/*  f17585c:	306d0007 */ 	andi	$t5,$v1,0x7
/*  f175860:	2da10005 */ 	sltiu	$at,$t5,0x5
/*  f175864:	1020006f */ 	beqz	$at,.L0f175a24
/*  f175868:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f17586c:	3c017f1b */ 	lui	$at,%hi(jtbl_var7f1b7c70)
/*  f175870:	002d0821 */ 	addu	$at,$at,$t5
/*  f175874:	8c2d7c70 */ 	lw	$t5,%lo(jtbl_var7f1b7c70)($at)
/*  f175878:	01a00008 */ 	jr	$t5
/*  f17587c:	00000000 */ 	nop
.L0f175880:
/*  f175880:	8ea80004 */ 	lw	$t0,0x4($s5)
/*  f175884:	00033582 */ 	srl	$a2,$v1,0x16
/*  f175888:	00033d02 */ 	srl	$a3,$v1,0x14
/*  f17588c:	00087602 */ 	srl	$t6,$t0,0x18
/*  f175890:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f175894:	00031482 */ 	srl	$v0,$v1,0x12
/*  f175898:	00034b82 */ 	srl	$t1,$v1,0xe
/*  f17589c:	00035282 */ 	srl	$t2,$v1,0xa
/*  f1758a0:	30d80003 */ 	andi	$t8,$a2,0x3
/*  f1758a4:	30f90003 */ 	andi	$t9,$a3,0x3
/*  f1758a8:	304c0003 */ 	andi	$t4,$v0,0x3
/*  f1758ac:	312d000f */ 	andi	$t5,$t1,0xf
/*  f1758b0:	314e000f */ 	andi	$t6,$t2,0xf
/*  f1758b4:	03003025 */ 	or	$a2,$t8,$zero
/*  f1758b8:	03203825 */ 	or	$a3,$t9,$zero
/*  f1758bc:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1758c0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f1758c4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1758c8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1758cc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1758d0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1758d4:	0fc5d524 */ 	jal	tex0f175490
/*  f1758d8:	02202825 */ 	or	$a1,$s1,$zero
/*  f1758dc:	10000051 */ 	b	.L0f175a24
/*  f1758e0:	0040b025 */ 	or	$s6,$v0,$zero
.L0f1758e4:
/*  f1758e4:	8eb00004 */ 	lw	$s0,0x4($s5)
/*  f1758e8:	8fa50144 */ 	lw	$a1,0x144($sp)
/*  f1758ec:	00107b02 */ 	srl	$t7,$s0,0xc
/*  f1758f0:	31e40fff */ 	andi	$a0,$t7,0xfff
/*  f1758f4:	0fc5cd3a */ 	jal	texLoadFromTextureNum
/*  f1758f8:	00808025 */ 	or	$s0,$a0,$zero
/*  f1758fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f175900:	0fc5cba3 */ 	jal	tex0f172e8c
/*  f175904:	8fa50144 */ 	lw	$a1,0x144($sp)
/*  f175908:	10400046 */ 	beqz	$v0,.L0f175a24
/*  f17590c:	00405825 */ 	or	$t3,$v0,$zero
/*  f175910:	8ea30000 */ 	lw	$v1,0x0($s5)
/*  f175914:	8ea80004 */ 	lw	$t0,0x4($s5)
/*  f175918:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f17591c:	00033582 */ 	srl	$a2,$v1,0x16
/*  f175920:	0008ce02 */ 	srl	$t9,$t0,0x18
/*  f175924:	332c00ff */ 	andi	$t4,$t9,0xff
/*  f175928:	00033d02 */ 	srl	$a3,$v1,0x14
/*  f17592c:	00031482 */ 	srl	$v0,$v1,0x12
/*  f175930:	00034b82 */ 	srl	$t1,$v1,0xe
/*  f175934:	00035282 */ 	srl	$t2,$v1,0xa
/*  f175938:	30cd0003 */ 	andi	$t5,$a2,0x3
/*  f17593c:	30ee0003 */ 	andi	$t6,$a3,0x3
/*  f175940:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f175944:	3138000f */ 	andi	$t8,$t1,0xf
/*  f175948:	3159000f */ 	andi	$t9,$t2,0xf
/*  f17594c:	01a03025 */ 	or	$a2,$t5,$zero
/*  f175950:	01c03825 */ 	or	$a3,$t6,$zero
/*  f175954:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f175958:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f17595c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f175960:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f175964:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f175968:	02c02025 */ 	or	$a0,$s6,$zero
/*  f17596c:	0fc5d4c2 */ 	jal	tex0f175308
/*  f175970:	02202825 */ 	or	$a1,$s1,$zero
/*  f175974:	1000002b */ 	b	.L0f175a24
/*  f175978:	0040b025 */ 	or	$s6,$v0,$zero
.L0f17597c:
/*  f17597c:	00033582 */ 	srl	$a2,$v1,0x16
/*  f175980:	00033d02 */ 	srl	$a3,$v1,0x14
/*  f175984:	00031482 */ 	srl	$v0,$v1,0x12
/*  f175988:	30cc0003 */ 	andi	$t4,$a2,0x3
/*  f17598c:	30ed0003 */ 	andi	$t5,$a3,0x3
/*  f175990:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f175994:	01803025 */ 	or	$a2,$t4,$zero
/*  f175998:	01a03825 */ 	or	$a3,$t5,$zero
/*  f17599c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1759a0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1759a4:	02202825 */ 	or	$a1,$s1,$zero
/*  f1759a8:	0fc5d479 */ 	jal	tex0f1751e4
/*  f1759ac:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f1759b0:	1000001c */ 	b	.L0f175a24
/*  f1759b4:	0040b025 */ 	or	$s6,$v0,$zero
.L0f1759b8:
/*  f1759b8:	00033582 */ 	srl	$a2,$v1,0x16
/*  f1759bc:	00033d02 */ 	srl	$a3,$v1,0x14
/*  f1759c0:	00031482 */ 	srl	$v0,$v1,0x12
/*  f1759c4:	30cf0003 */ 	andi	$t7,$a2,0x3
/*  f1759c8:	30f80003 */ 	andi	$t8,$a3,0x3
/*  f1759cc:	30590003 */ 	andi	$t9,$v0,0x3
/*  f1759d0:	01e03025 */ 	or	$a2,$t7,$zero
/*  f1759d4:	03003825 */ 	or	$a3,$t8,$zero
/*  f1759d8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1759dc:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1759e0:	0fc5d58f */ 	jal	tex0f17563c
/*  f1759e4:	02202825 */ 	or	$a1,$s1,$zero
/*  f1759e8:	1000000e */ 	b	.L0f175a24
/*  f1759ec:	0040b025 */ 	or	$s6,$v0,$zero
.L0f1759f0:
/*  f1759f0:	00033582 */ 	srl	$a2,$v1,0x16
/*  f1759f4:	00033d02 */ 	srl	$a3,$v1,0x14
/*  f1759f8:	00031482 */ 	srl	$v0,$v1,0x12
/*  f1759fc:	30cc0003 */ 	andi	$t4,$a2,0x3
/*  f175a00:	30ed0003 */ 	andi	$t5,$a3,0x3
/*  f175a04:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f175a08:	01803025 */ 	or	$a2,$t4,$zero
/*  f175a0c:	01a03825 */ 	or	$a3,$t5,$zero
/*  f175a10:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f175a14:	02c02025 */ 	or	$a0,$s6,$zero
/*  f175a18:	0fc5d577 */ 	jal	tex0f1755dc
/*  f175a1c:	02202825 */ 	or	$a1,$s1,$zero
/*  f175a20:	0040b025 */ 	or	$s6,$v0,$zero
.L0f175a24:
/*  f175a24:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f175a28:	240106cb */ 	addiu	$at,$zero,0x6cb
/*  f175a2c:	11e0002c */ 	beqz	$t7,.L0f175ae0
/*  f175a30:	00000000 */ 	nop
/*  f175a34:	56410005 */ 	bnel	$s2,$at,.L0f175a4c
/*  f175a38:	24010a6a */ 	addiu	$at,$zero,0xa6a
/*  f175a3c:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175a40:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f175a44:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f175a48:	24010a6a */ 	addiu	$at,$zero,0xa6a
.L0f175a4c:
/*  f175a4c:	16410003 */ 	bne	$s2,$at,.L0f175a5c
/*  f175a50:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f175a54:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175a58:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175a5c:
/*  f175a5c:	24010a69 */ 	addiu	$at,$zero,0xa69
/*  f175a60:	16410003 */ 	bne	$s2,$at,.L0f175a70
/*  f175a64:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f175a68:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175a6c:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175a70:
/*  f175a70:	240106e2 */ 	addiu	$at,$zero,0x6e2
/*  f175a74:	16410003 */ 	bne	$s2,$at,.L0f175a84
/*  f175a78:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f175a7c:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175a80:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175a84:
/*  f175a84:	240101c7 */ 	addiu	$at,$zero,0x1c7
/*  f175a88:	12410004 */ 	beq	$s2,$at,.L0f175a9c
/*  f175a8c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f175a90:	24010dae */ 	addiu	$at,$zero,0xdae
/*  f175a94:	56410004 */ 	bnel	$s2,$at,.L0f175aa8
/*  f175a98:	2401029b */ 	addiu	$at,$zero,0x29b
.L0f175a9c:
/*  f175a9c:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175aa0:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f175aa4:	2401029b */ 	addiu	$at,$zero,0x29b
.L0f175aa8:
/*  f175aa8:	16410003 */ 	bne	$s2,$at,.L0f175ab8
/*  f175aac:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f175ab0:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175ab4:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175ab8:
/*  f175ab8:	2401090f */ 	addiu	$at,$zero,0x90f
/*  f175abc:	16410003 */ 	bne	$s2,$at,.L0f175acc
/*  f175ac0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f175ac4:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175ac8:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175acc:
/*  f175acc:	24010a42 */ 	addiu	$at,$zero,0xa42
/*  f175ad0:	16410003 */ 	bne	$s2,$at,.L0f175ae0
/*  f175ad4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f175ad8:	0fc4f0ba */ 	jal	func0f13c2e8
/*  f175adc:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f175ae0:
/*  f175ae0:	100000d7 */ 	b	.L0f175e40
/*  f175ae4:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f175ae8:
/*  f175ae8:	1300001e */ 	beqz	$t8,.L0f175b64
/*  f175aec:	3c0100ff */ 	lui	$at,0xff
/*  f175af0:	92a30001 */ 	lbu	$v1,0x1($s5)
/*  f175af4:	8eb30004 */ 	lw	$s3,0x4($s5)
/*  f175af8:	3421ffff */ 	ori	$at,$at,0xffff
/*  f175afc:	00032102 */ 	srl	$a0,$v1,0x4
/*  f175b00:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f175b04:	3062000f */ 	andi	$v0,$v1,0xf
/*  f175b08:	0044a021 */ 	addu	$s4,$v0,$a0
/*  f175b0c:	0261c824 */ 	and	$t9,$s3,$at
/*  f175b10:	0054082a */ 	slt	$at,$v0,$s4
/*  f175b14:	03209825 */ 	or	$s3,$t9,$zero
/*  f175b18:	10200012 */ 	beqz	$at,.L0f175b64
/*  f175b1c:	00408825 */ 	or	$s1,$v0,$zero
/*  f175b20:	00026080 */ 	sll	$t4,$v0,0x2
/*  f175b24:	27ad00a0 */ 	addiu	$t5,$sp,0xa0
/*  f175b28:	018d9021 */ 	addu	$s2,$t4,$t5
.L0f175b2c:
/*  f175b2c:	13c00007 */ 	beqz	$s8,.L0f175b4c
/*  f175b30:	02f18021 */ 	addu	$s0,$s7,$s1
/*  f175b34:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f175b38:	51c00005 */ 	beqzl	$t6,.L0f175b50
/*  f175b3c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f175b40:	0fc4f01f */ 	jal	func0f13c07c
/*  f175b44:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f175b48:	a2000000 */ 	sb	$zero,0x0($s0)
.L0f175b4c:
/*  f175b4c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f175b50:
/*  f175b50:	0234082a */ 	slt	$at,$s1,$s4
/*  f175b54:	ae530000 */ 	sw	$s3,0x0($s2)
/*  f175b58:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f175b5c:	1420fff3 */ 	bnez	$at,.L0f175b2c
/*  f175b60:	2673000c */ 	addiu	$s3,$s3,0xc
.L0f175b64:
/*  f175b64:	8faf00f4 */ 	lw	$t7,0xf4($sp)
/*  f175b68:	8fb80148 */ 	lw	$t8,0x148($sp)
/*  f175b6c:	51e00016 */ 	beqzl	$t7,.L0f175bc8
/*  f175b70:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f175b74:	13000013 */ 	beqz	$t8,.L0f175bc4
/*  f175b78:	3c0100ff */ 	lui	$at,0xff
/*  f175b7c:	92a40001 */ 	lbu	$a0,0x1($s5)
/*  f175b80:	8ea50004 */ 	lw	$a1,0x4($s5)
/*  f175b84:	3421ffff */ 	ori	$at,$at,0xffff
/*  f175b88:	0004c902 */ 	srl	$t9,$a0,0x4
/*  f175b8c:	27240001 */ 	addiu	$a0,$t9,0x1
/*  f175b90:	00001825 */ 	or	$v1,$zero,$zero
/*  f175b94:	1880000b */ 	blez	$a0,.L0f175bc4
/*  f175b98:	00a16024 */ 	and	$t4,$a1,$at
/*  f175b9c:	030c1021 */ 	addu	$v0,$t8,$t4
.L0f175ba0:
/*  f175ba0:	844d0008 */ 	lh	$t5,0x8($v0)
/*  f175ba4:	844f000a */ 	lh	$t7,0xa($v0)
/*  f175ba8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f175bac:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f175bb0:	000fc843 */ 	sra	$t9,$t7,0x1
/*  f175bb4:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f175bb8:	a44efffc */ 	sh	$t6,-0x4($v0)
/*  f175bbc:	1464fff8 */ 	bne	$v1,$a0,.L0f175ba0
/*  f175bc0:	a459fffe */ 	sh	$t9,-0x2($v0)
.L0f175bc4:
/*  f175bc4:	8ea10000 */ 	lw	$at,0x0($s5)
.L0f175bc8:
/*  f175bc8:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175bcc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175bd0:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175bd4:	8eb8fffc */ 	lw	$t8,-0x4($s5)
/*  f175bd8:	10000099 */ 	b	.L0f175e40
/*  f175bdc:	aed8fffc */ 	sw	$t8,-0x4($s6)
.L0f175be0:
/*  f175be0:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f175be4:	ac2d44d0 */ 	sw	$t5,%lo(var800844d0)($at)
/*  f175be8:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f175bec:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175bf0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175bf4:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175bf8:	8eb9fffc */ 	lw	$t9,-0x4($s5)
/*  f175bfc:	10000090 */ 	b	.L0f175e40
/*  f175c00:	aed9fffc */ 	sw	$t9,-0x4($s6)
.L0f175c04:
/*  f175c04:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f175c08:	13c00067 */ 	beqz	$s8,.L0f175da8
/*  f175c0c:	afac0104 */ 	sw	$t4,0x104($sp)
/*  f175c10:	240100bf */ 	addiu	$at,$zero,0xbf
/*  f175c14:	54610015 */ 	bnel	$v1,$at,.L0f175c6c
/*  f175c18:	92a20007 */ 	lbu	$v0,0x7($s5)
/*  f175c1c:	92ad0005 */ 	lbu	$t5,0x5($s5)
/*  f175c20:	2401000a */ 	addiu	$at,$zero,0xa
/*  f175c24:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f175c28:	01a1001a */ 	div	$zero,$t5,$at
/*  f175c2c:	00007812 */ 	mflo	$t7
/*  f175c30:	02ef7021 */ 	addu	$t6,$s7,$t7
/*  f175c34:	a1d80000 */ 	sb	$t8,0x0($t6)
/*  f175c38:	92ac0006 */ 	lbu	$t4,0x6($s5)
/*  f175c3c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f175c40:	0181001a */ 	div	$zero,$t4,$at
/*  f175c44:	00006812 */ 	mflo	$t5
/*  f175c48:	02ed7821 */ 	addu	$t7,$s7,$t5
/*  f175c4c:	a1f90000 */ 	sb	$t9,0x0($t7)
/*  f175c50:	92ae0007 */ 	lbu	$t6,0x7($s5)
/*  f175c54:	01c1001a */ 	div	$zero,$t6,$at
/*  f175c58:	00006012 */ 	mflo	$t4
/*  f175c5c:	02ec6821 */ 	addu	$t5,$s7,$t4
/*  f175c60:	10000051 */ 	b	.L0f175da8
/*  f175c64:	a1b80000 */ 	sb	$t8,0x0($t5)
/*  f175c68:	92a20007 */ 	lbu	$v0,0x7($s5)
.L0f175c6c:
/*  f175c6c:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f175c70:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f175c74:	0002c902 */ 	srl	$t9,$v0,0x4
/*  f175c78:	306f000f */ 	andi	$t7,$v1,0xf
/*  f175c7c:	172f0004 */ 	bne	$t9,$t7,.L0f175c90
/*  f175c80:	01e01825 */ 	or	$v1,$t7,$zero
/*  f175c84:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f175c88:	31cc000f */ 	andi	$t4,$t6,0xf
/*  f175c8c:	132c000b */ 	beq	$t9,$t4,.L0f175cbc
.L0f175c90:
/*  f175c90:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f175c94:	02e3c021 */ 	addu	$t8,$s7,$v1
/*  f175c98:	a3020000 */ 	sb	$v0,0x0($t8)
/*  f175c9c:	92ad0007 */ 	lbu	$t5,0x7($s5)
/*  f175ca0:	000dc902 */ 	srl	$t9,$t5,0x4
/*  f175ca4:	02f97821 */ 	addu	$t7,$s7,$t9
/*  f175ca8:	a1e20000 */ 	sb	$v0,0x0($t7)
/*  f175cac:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f175cb0:	31cc000f */ 	andi	$t4,$t6,0xf
/*  f175cb4:	02ecc021 */ 	addu	$t8,$s7,$t4
/*  f175cb8:	a3020000 */ 	sb	$v0,0x0($t8)
.L0f175cbc:
/*  f175cbc:	96a30006 */ 	lhu	$v1,0x6($s5)
/*  f175cc0:	92a20006 */ 	lbu	$v0,0x6($s5)
/*  f175cc4:	00036b02 */ 	srl	$t5,$v1,0xc
/*  f175cc8:	3059000f */ 	andi	$t9,$v0,0xf
/*  f175ccc:	15b90004 */ 	bne	$t5,$t9,.L0f175ce0
/*  f175cd0:	03201025 */ 	or	$v0,$t9,$zero
/*  f175cd4:	92af0003 */ 	lbu	$t7,0x3($s5)
/*  f175cd8:	000f7102 */ 	srl	$t6,$t7,0x4
/*  f175cdc:	11ae000b */ 	beq	$t5,$t6,.L0f175d0c
.L0f175ce0:
/*  f175ce0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f175ce4:	02e26021 */ 	addu	$t4,$s7,$v0
/*  f175ce8:	a1830000 */ 	sb	$v1,0x0($t4)
/*  f175cec:	96b80006 */ 	lhu	$t8,0x6($s5)
/*  f175cf0:	00186b02 */ 	srl	$t5,$t8,0xc
/*  f175cf4:	02edc821 */ 	addu	$t9,$s7,$t5
/*  f175cf8:	a3230000 */ 	sb	$v1,0x0($t9)
/*  f175cfc:	92af0003 */ 	lbu	$t7,0x3($s5)
/*  f175d00:	000f7102 */ 	srl	$t6,$t7,0x4
/*  f175d04:	02ee6021 */ 	addu	$t4,$s7,$t6
/*  f175d08:	a1830000 */ 	sb	$v1,0x0($t4)
.L0f175d0c:
/*  f175d0c:	92a30005 */ 	lbu	$v1,0x5($s5)
/*  f175d10:	96a20004 */ 	lhu	$v0,0x4($s5)
/*  f175d14:	0003c102 */ 	srl	$t8,$v1,0x4
/*  f175d18:	304d000f */ 	andi	$t5,$v0,0xf
/*  f175d1c:	170d0004 */ 	bne	$t8,$t5,.L0f175d30
/*  f175d20:	01a01025 */ 	or	$v0,$t5,$zero
/*  f175d24:	92b90002 */ 	lbu	$t9,0x2($s5)
/*  f175d28:	332f000f */ 	andi	$t7,$t9,0xf
/*  f175d2c:	130f000a */ 	beq	$t8,$t7,.L0f175d58
.L0f175d30:
/*  f175d30:	02e27021 */ 	addu	$t6,$s7,$v0
/*  f175d34:	a1c40000 */ 	sb	$a0,0x0($t6)
/*  f175d38:	92ac0005 */ 	lbu	$t4,0x5($s5)
/*  f175d3c:	000cc102 */ 	srl	$t8,$t4,0x4
/*  f175d40:	02f86821 */ 	addu	$t5,$s7,$t8
/*  f175d44:	a1a40000 */ 	sb	$a0,0x0($t5)
/*  f175d48:	92b90002 */ 	lbu	$t9,0x2($s5)
/*  f175d4c:	332f000f */ 	andi	$t7,$t9,0xf
/*  f175d50:	02ef7021 */ 	addu	$t6,$s7,$t7
/*  f175d54:	a1c40000 */ 	sb	$a0,0x0($t6)
.L0f175d58:
/*  f175d58:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f175d5c:	92a20004 */ 	lbu	$v0,0x4($s5)
/*  f175d60:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f175d64:	00036702 */ 	srl	$t4,$v1,0x1c
/*  f175d68:	3058000f */ 	andi	$t8,$v0,0xf
/*  f175d6c:	15980004 */ 	bne	$t4,$t8,.L0f175d80
/*  f175d70:	03001025 */ 	or	$v0,$t8,$zero
/*  f175d74:	96ad0002 */ 	lhu	$t5,0x2($s5)
/*  f175d78:	000dcb02 */ 	srl	$t9,$t5,0xc
/*  f175d7c:	1199000a */ 	beq	$t4,$t9,.L0f175da8
.L0f175d80:
/*  f175d80:	02e27821 */ 	addu	$t7,$s7,$v0
/*  f175d84:	a1e40000 */ 	sb	$a0,0x0($t7)
/*  f175d88:	8eae0004 */ 	lw	$t6,0x4($s5)
/*  f175d8c:	000e6702 */ 	srl	$t4,$t6,0x1c
/*  f175d90:	02ecc021 */ 	addu	$t8,$s7,$t4
/*  f175d94:	a3040000 */ 	sb	$a0,0x0($t8)
/*  f175d98:	96ad0002 */ 	lhu	$t5,0x2($s5)
/*  f175d9c:	000dcb02 */ 	srl	$t9,$t5,0xc
/*  f175da0:	02f97821 */ 	addu	$t7,$s7,$t9
/*  f175da4:	a1e40000 */ 	sb	$a0,0x0($t7)
.L0f175da8:
/*  f175da8:	3c018008 */ 	lui	$at,%hi(var800844d0)
/*  f175dac:	ac2044d0 */ 	sw	$zero,%lo(var800844d0)($at)
/*  f175db0:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f175db4:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175db8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175dbc:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175dc0:	8eb8fffc */ 	lw	$t8,-0x4($s5)
/*  f175dc4:	1000001e */ 	b	.L0f175e40
/*  f175dc8:	aed8fffc */ 	sw	$t8,-0x4($s6)
.L0f175dcc:
/*  f175dcc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f175dd0:	001e102b */ 	sltu	$v0,$zero,$s8
/*  f175dd4:	afad00e4 */ 	sw	$t5,0xe4($sp)
/*  f175dd8:	0000f025 */ 	or	$s8,$zero,$zero
/*  f175ddc:	10400003 */ 	beqz	$v0,.L0f175dec
/*  f175de0:	afa00104 */ 	sw	$zero,0x104($sp)
/*  f175de4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f175de8:	afb900e8 */ 	sw	$t9,0xe8($sp)
.L0f175dec:
/*  f175dec:	afb6012c */ 	sw	$s6,0x12c($sp)
/*  f175df0:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f175df4:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175df8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175dfc:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175e00:	8eaefffc */ 	lw	$t6,-0x4($s5)
/*  f175e04:	1000000e */ 	b	.L0f175e40
/*  f175e08:	aecefffc */ 	sw	$t6,-0x4($s6)
.L0f175e0c:
/*  f175e0c:	8ea10000 */ 	lw	$at,0x0($s5)
/*  f175e10:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175e14:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175e18:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175e1c:	8eb9fffc */ 	lw	$t9,-0x4($s5)
/*  f175e20:	10000007 */ 	b	.L0f175e40
/*  f175e24:	aed9fffc */ 	sw	$t9,-0x4($s6)
.L0f175e28:
/*  f175e28:	8ea10000 */ 	lw	$at,0x0($s5)
.L0f175e2c:
/*  f175e2c:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f175e30:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f175e34:	aec1fff8 */ 	sw	$at,-0x8($s6)
/*  f175e38:	8eaefffc */ 	lw	$t6,-0x4($s5)
/*  f175e3c:	aecefffc */ 	sw	$t6,-0x4($s6)
.L0f175e40:
/*  f175e40:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f175e44:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f175e48:	25b8ffff */ 	addiu	$t8,$t5,-1
/*  f175e4c:	17200003 */ 	bnez	$t9,.L0f175e5c
/*  f175e50:	afb80128 */ 	sw	$t8,0x128($sp)
/*  f175e54:	5f000017 */ 	bgtzl	$t8,.L0f175eb4
/*  f175e58:	8fad0128 */ 	lw	$t5,0x128($sp)
.L0f175e5c:
/*  f175e5c:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f175e60:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f175e64:	00008025 */ 	or	$s0,$zero,$zero
/*  f175e68:	55e00004 */ 	bnezl	$t7,.L0f175e7c
/*  f175e6c:	afa000e8 */ 	sw	$zero,0xe8($sp)
/*  f175e70:	53c00010 */ 	beqzl	$s8,.L0f175eb4
/*  f175e74:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f175e78:	afa000e8 */ 	sw	$zero,0xe8($sp)
.L0f175e7c:
/*  f175e7c:	27b10090 */ 	addiu	$s1,$sp,0x90
.L0f175e80:
/*  f175e80:	922c0000 */ 	lbu	$t4,0x0($s1)
/*  f175e84:	00107080 */ 	sll	$t6,$s0,0x2
/*  f175e88:	03ae2021 */ 	addu	$a0,$sp,$t6
/*  f175e8c:	51800005 */ 	beqzl	$t4,.L0f175ea4
/*  f175e90:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f175e94:	0fc4f01f */ 	jal	func0f13c07c
/*  f175e98:	8c8400a0 */ 	lw	$a0,0xa0($a0)
/*  f175e9c:	a2200000 */ 	sb	$zero,0x0($s1)
/*  f175ea0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f175ea4:
/*  f175ea4:	24010010 */ 	addiu	$at,$zero,0x10
/*  f175ea8:	1601fff5 */ 	bne	$s0,$at,.L0f175e80
/*  f175eac:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f175eb0:	8fad0128 */ 	lw	$t5,0x128($sp)
.L0f175eb4:
/*  f175eb4:	5da0fe2f */ 	bgtzl	$t5,.L0f175774
/*  f175eb8:	92a30000 */ 	lbu	$v1,0x0($s5)
/*  f175ebc:	8fb90140 */ 	lw	$t9,0x140($sp)
.L0f175ec0:
/*  f175ec0:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f175ec4:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f175ec8:	02d91023 */ 	subu	$v0,$s6,$t9
/*  f175ecc:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f175ed0:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f175ed4:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f175ed8:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f175edc:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f175ee0:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f175ee4:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f175ee8:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f175eec:	03e00008 */ 	jr	$ra
/*  f175ef0:	27bd0138 */ 	addiu	$sp,$sp,0x138
);

// Mismatch: Extra move instruction in last half of G_VTX case
//s32 tex0f1756c0(Gfx *arg0, s32 arg1, Gfx *arg2, struct texturething *arg3, u32 arg4)
//{
//	struct texloadthing *v0;
//	struct texloadthing *v0_2;
//	Gfx *sp12c;
//	s32 sp128;
//	u32 tmp1;
//	u32 tmp2;
//	u32 tmp3;
//	u32 tmp4;
//	u32 tmp5;
//	u32 tmp6;
//	bool flag;
//	s32 j;
//	bool sp104;
//	u8 animated;
//	Gfx *s5;
//	Gfx *s6;
//	u32 spf4;
//	s32 texturenum;
//	s32 texturenum2;
//	bool spe8;
//	s32 spe4;
//	s32 spe0;
//	struct gfxvtx *spA0[16];
//	u8 sp90[16];
//
//	s32 i;
//
//	sp12c = NULL;
//	sp104 = true;
//	animated = false;
//	spe8 = false;
//	spe4 = false;
//	var800844d0 = false;
//	spf4 = 0;
//	s5 = arg0;
//	s6 = arg2;
//
//	sp128 = arg1 >> 3;
//
//	tex0f173a08();
//
//	spe0 = func0f13c4f0();
//
//	if (spe0) {
//		for (j = 0; j < 16; j++) {
//			sp90[j] = 0;
//		}
//	}
//
//	if (arg3 == NULL) {
//		arg3 = &var800aabc8;
//	}
//
//	while (sp128 > 0) {
//		switch (s5->texture.cmd) {
//		case 0xc0: // Repurposed?
//			spe4 = true;
//
//			if (animated) {
//				spe8 = true;
//			}
//
//			texturenum = s5->words.w1 & 0xfff;
//			flag = s5->words.w0 & 0x200;
//
//			texLoadFromTextureNum(texturenum, arg3);
//
//			v0 = tex0f172e8c(texturenum, arg3);
//
//			if (v0 != NULL) {
//				spf4 = v0->unk0c_03;
//			} else {
//				spf4 = 0;
//			}
//
//			if (v0 != NULL) {
//				s6 = tex0f1742e4(s6, sp12c, v0, sp104);
//				sp104 = false;
//				animated = false;
//
//				switch (s5->unkc0.subcmd) {
//				case 0:
//					tmp6 = (s5->words.w1 >> 24) & 0xff;
//					tmp1 = (s5->words.w0 >> 22) & 3;
//					tmp2 = (s5->words.w0 >> 20) & 3;
//					tmp3 = (s5->words.w0 >> 18) & 3;
//					tmp4 = (s5->words.w0 >> 14) & 0xf;
//					tmp5 = (s5->words.w0 >> 10) & 0xf;
//
//					s6 = tex0f175490(s6, v0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, flag);
//					break;
//				case 1:
//					texturenum2 = (s5->words.w1 >> 12) & 0xfff;
//					texLoadFromTextureNum(texturenum2, arg3);
//					v0_2 = tex0f172e8c(texturenum2, arg3);
//
//					if (v0_2 != NULL) {
//						tmp6 = (s5->words.w1 >> 24) & 0xff;
//						tmp1 = (s5->words.w0 >> 22) & 3;
//						tmp2 = (s5->words.w0 >> 20) & 3;
//						tmp3 = (s5->words.w0 >> 18) & 3;
//						tmp4 = (s5->words.w0 >> 14) & 0xf;
//						tmp5 = (s5->words.w0 >> 10) & 0xf;
//
//						s6 = tex0f175308(s6, v0, tmp1, tmp2, tmp3, v0_2, tmp4, tmp5, tmp6, flag);
//					}
//					break;
//				case 2:
//					tmp1 = (s5->words.w0 >> 22) & 3;
//					tmp2 = (s5->words.w0 >> 20) & 3;
//					tmp3 = (s5->words.w0 >> 18) & 3;
//
//					s6 = tex0f1751e4(s6, v0, tmp1, tmp2, tmp3, flag);
//					break;
//				case 3:
//					tmp1 = (s5->words.w0 >> 22) & 3;
//					tmp2 = (s5->words.w0 >> 20) & 3;
//					tmp3 = (s5->words.w0 >> 18) & 3;
//
//					s6 = tex0f17563c(s6, v0, tmp1, tmp2, tmp3);
//					break;
//				case 4:
//					tmp1 = (s5->words.w0 >> 22) & 3;
//					tmp2 = (s5->words.w0 >> 20) & 3;
//					tmp3 = (s5->words.w0 >> 18) & 3;
//
//					s6 = tex0f1755dc(s6, v0, tmp1, tmp2, tmp3);
//					break;
//				}
//
//				if (spe0 != 0) {
//					if (texturenum == TEXTURE_06CB) {
//						func0f13c2e8(1);
//						animated = true;
//					}
//
//					if (texturenum == TEXTURE_0A6A) {
//						func0f13c2e8(6);
//						animated = true;
//					}
//
//					if (texturenum == TEXTURE_0A69) {
//						func0f13c2e8(7);
//						animated = true;
//					}
//
//					if (texturenum == TEXTURE_06E2) {
//						func0f13c2e8(3);
//						animated = true;
//					}
//
//					if (texturenum == TEXTURE_01C7 || texturenum == TEXTURE_0DAE) {
//						func0f13c2e8(1);
//						animated = true;
//					}
//
//					if (texturenum == TEXTURE_029B) {
//						func0f13c2e8(4);
//						animated = true;
//					}
//
//					if (texturenum == TEXTURE_090F) {
//						func0f13c2e8(5);
//						animated = true;
//					}
//
//					if (texturenum == TEXTURE_0A42) {
//						func0f13c2e8(2);
//						animated = true;
//					}
//				}
//			}
//
//			s5++;
//			break;
//		case G_VTX:
//			{
//				s32 start;
//				s32 count;
//				u32 offset;
//				struct gfxvtx *vtx;
//
//				if (spe0) {
//					start = s5->bytes[1] & 0xf;
//					count = ((u32)s5->bytes[1] >> 4) + 1;
//					vtx = (struct gfxvtx *)(s5->dma.addr & 0x00ffffff);
//
//					for (i = start; i < start + count; i++) {
//						if (animated && sp90[i]) {
//							func0f13c07c(spA0[i]);
//							sp90[i] = 0;
//						}
//
//						spA0[i] = vtx;
//						vtx++;
//					}
//				}
//
//				if (spf4 && arg4) {
//					// b7c
//					u32 offset;
//					struct gfxvtx *vtx;
//					s32 i;
//
//					count = (s5->dma.par >> 4) + 1;
//					offset = s5->dma.addr & 0x00ffffff;
//					i = 0;
//					offset = (arg4 + offset);
//					vtx = (struct gfxvtx *) offset;
//
//					for (; i < count; i++) {
//						vtx[i].unk08 >>= 1;
//						vtx[i].unk0a >>= 1;
//					}
//				}
//			}
//
//			*s6 = *s5;
//			s6++;
//			s5++;
//			break;
//		case G_RDPPIPESYNC:
//			var800844d0 = true;
//			*s6 = *s5;
//			s6++;
//			s5++;
//			break;
//		case (u8)G_TRI4:
//		case (u8)G_TRI1:
//			if (animated) {
//				if (s5->texture.cmd == (u8)G_TRI1) {
//					sp90[s5->tri.tri.v[0] / 10] = 1;
//					sp90[s5->tri.tri.v[1] / 10] = 1;
//					sp90[s5->tri.tri.v[2] / 10] = 1;
//				} else {
//					// c68
//					if (s5->tri4.x1 != s5->tri4.y1 || s5->tri4.z1 != s5->tri4.y1) {
//						sp90[s5->tri4.x1] = 1;
//						sp90[s5->tri4.y1] = 1;
//						sp90[s5->tri4.z1] = 1;
//					}
//
//					// cbc
//					if (s5->tri4.x2 != s5->tri4.y2 || s5->tri4.z2 != s5->tri4.y2) {
//						sp90[s5->tri4.x2] = 1;
//						sp90[s5->tri4.y2] = 1;
//						sp90[s5->tri4.z2] = 1;
//					}
//
//					// d0c
//					if (s5->tri4.x3 != s5->tri4.y3 || s5->tri4.z3 != s5->tri4.y3) {
//						sp90[s5->tri4.x3] = 1;
//						sp90[s5->tri4.y3] = 1;
//						sp90[s5->tri4.z3] = 1;
//					}
//
//					// d58
//					if (s5->tri4.x4 != s5->tri4.y4 || s5->tri4.z4 != s5->tri4.y4) {
//						sp90[s5->tri4.x4] = 1;
//						sp90[s5->tri4.y4] = 1;
//						sp90[s5->tri4.z4] = 1;
//					}
//				}
//			}
//
//			sp104 = true;
//			var800844d0 = false;
//
//			*s6 = *s5;
//			s6++;
//			s5++;
//			break;
//		case (u8)G_TEXTURE:
//			spe4 = true;
//
//			if (animated) {
//				spe8 = true;
//			}
//
//			animated = false;
//			sp104 = false;
//
//			sp12c = s6;
//			*s6 = *s5;
//			s6++;
//			s5++;
//			break;
//		case (u8)G_SETOTHERMODE_H:
//			*s6 = *s5;
//			s6++;
//			s5++;
//			break;
//		default:
//			*s6 = *s5;
//			s6++;
//			s5++;
//			break;
//		}
//
//		sp128--;
//
//		if (spe4 || sp128 <= 0) {
//			spe4 = false;
//
//			if (spe8 || animated) {
//				s32 i;
//
//				spe8 = false;
//
//				for (i = 0; i < 16; i++) {
//					if (sp90[i]) {
//						func0f13c07c(spA0[i]);
//						sp90[i] = 0;
//					}
//				}
//			}
//		}
//	}
//
//	return (u32)s6 - (u32)arg2;
//}

void tex0f175ef4(Gfx *arg0, Gfx *arg1, s32 arg2)
{
	arg2 = (arg2 >> 3);
	arg0 = arg0 + (arg2 - 1);
	arg1 = arg1 + (arg2 - 1);

	while (arg2--) {
		arg1->force_structure_alignment = arg0->force_structure_alignment;
		arg1--;
		arg0--;
	}
}
