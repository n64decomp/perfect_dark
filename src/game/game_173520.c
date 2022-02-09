#include <ultra64.h>
#include "constants.h"
#include "game/game_0b3350.h"
#include "game/texdecompress.h"
#include "bss.h"
#include "lib/rzip.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/memp.h"
#include "data.h"
#include "textureconfig.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f173520
/*  f173520:	3c01800b */ 	lui	$at,%hi(var800ab540)
/*  f173524:	ac24b540 */ 	sw	$a0,%lo(var800ab540)($at)
/*  f173528:	3c01800b */ 	lui	$at,%hi(var800ab544)
/*  f17352c:	ac20b544 */ 	sw	$zero,%lo(var800ab544)($at)
/*  f173530:	3c01800b */ 	lui	$at,%hi(var800ab548)
/*  f173534:	03e00008 */ 	jr	$ra
/*  f173538:	ac20b548 */ 	sw	$zero,%lo(var800ab548)($at)
);

s32 func0f17353c(s32 arg0)
{
	while (var800ab548 < arg0) {
		var800ab544 = *var800ab540 | var800ab544 << 8;
		var800ab540++;
		var800ab548 += 8;
	}

	var800ab548 -= arg0;

	return var800ab544 >> var800ab548 & (1 << arg0) - 1;
}

extern u8 *g_TextureConfigSegment;
extern u32 g_TexBase;
extern Gfx *g_TexGdl3;
extern struct textureconfig *g_TexRedLinesConfigs;
extern struct textureconfig *g_TexSkyConfigs;

extern u8 _textureconfigSegmentRomStart;
extern u8 _textureconfigSegmentStart;
extern u8 _textureconfigSegmentEnd;

void texturesLoadConfigs(void)
{
	s32 stage;
	u32 len = &_textureconfigSegmentEnd - &_textureconfigSegmentStart;
	s32 i;

	g_TextureConfigSegment = mempAlloc(len, MEMPOOL_STAGE);
	dmaExec(g_TextureConfigSegment, (u32)&_textureconfigSegmentRomStart, len);

	g_TexBase = (u32)g_TextureConfigSegment - 0x02000000;
	g_TexGdl1 = (Gfx *)(g_TexBase + (u32)g_TcGdl1);
	g_TexGdl2 = (Gfx *)(g_TexBase + (u32)g_TcGdl2);
	g_TexGdl3 = (Gfx *)(g_TexBase + (u32)g_TcGdl3);
	g_ExplosionTexturePairs = (void *)(g_TexBase + (u32)g_TcExplosionTexturePairs);
	g_TexWallhitConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcWallhitConfigs);
	g_TexBeamConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcBeamConfigs);
	g_TexLaserConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcLaserConfigs);
	g_TexGroup03Configs = (struct textureconfig *)(g_TexBase + (u32)g_TcGroup03Configs);
	g_TexGeCrosshairConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcGeCrosshairConfigs);
	g_TexRedLinesConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcRedLineConfigs);
	g_TexGroup06Configs = (struct textureconfig *)(g_TexBase + (u32)g_TcGroup06Configs);
	g_TexShieldConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcShieldConfigs);
	g_TexShardConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcShardConfigs);
	g_TexScreenConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcScreenConfigs);
	g_TexWaterConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcWaterConfigs);
	g_TexSkyConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcSkyConfigs);
	g_TexLightGlareConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcLightGlareConfigs);
	g_TexSparkConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcSparkConfigs);
	g_TexGeneralConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcGeneralConfigs);
	g_TexRadarConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcRadarConfigs);

	g_TexNumConfigs = (len - (u32)&g_TcWallhitConfigs + 0x02000000) / sizeof(struct textureconfig);
	g_TexWords = mempAlloc(ALIGN16(g_TexNumConfigs * 4), MEMPOOL_STAGE);

	for (i = 0; i < g_TexNumConfigs; i++) {
		g_TexWords[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_TcExplosionTexturePairs); i++) {
		func0f173010(&g_ExplosionTexturePairs[i].texturenum1, 0, 0);
		func0f173010(&g_ExplosionTexturePairs[i].texturenum2, 0, 0);
	}

	func0f172f5c(g_TexGdl1, 0, 0);
	func0f172f5c(g_TexGdl3, 0, 0);

	stage = mainGetStageNum();

	if (IS4MB() && stage != STAGE_TITLE && stage != STAGE_CITRAINING && stage != STAGE_4MBMENU) {
		for (i = 0; i < ARRAYCOUNT(g_TcWallhitConfigs); i++) {
			func0f0b3988(&g_TexWallhitConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcBeamConfigs); i++) {
			func0f0b3988(&g_TexBeamConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcWaterConfigs); i++) {
			func0f0b3988(&g_TexWaterConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcGroup06Configs); i++) {
			func0f0b3988(&g_TexGroup06Configs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcShieldConfigs); i++) {
			func0f0b3988(&g_TexShieldConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcRadarConfigs); i++) {
			func0f0b3988(&g_TexRadarConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcSparkConfigs); i++) {
			func0f0b3988(&g_TexSparkConfigs[i]);
		}
	}
}
