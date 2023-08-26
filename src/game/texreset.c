#include <ultra64.h>
#include "constants.h"
#include "game/tex.h"
#include "game/texdecompress.h"
#include "bss.h"
#include "lib/rzip.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/memp.h"
#include "data.h"
#include "textureconfig.h"
#include "types.h"

void texSetBitstring(u8 *bitstring)
{
	g_TexBitstring = bitstring;
	g_TexAccumValue = 0;
	g_TexAccumNumBits = 0;
}

s32 texReadBits(s32 wantnumbits)
{
	while (g_TexAccumNumBits < wantnumbits) {
		g_TexAccumValue = g_TexAccumValue << 8 | *g_TexBitstring;
		g_TexBitstring++;
		g_TexAccumNumBits += 8;
	}

	g_TexAccumNumBits -= wantnumbits;

	return (g_TexAccumValue >> g_TexAccumNumBits) & ((1 << wantnumbits) - 1);
}

extern u8 *g_TextureConfigSegment;
extern u32 g_TexBase;
extern Gfx *g_TexGdl3;
extern struct textureconfig *g_TexRedLinesConfigs;
extern struct textureconfig *g_TexGroup11Configs;

extern u8 _textureconfigSegmentRomStart;
extern u8 _textureconfigSegmentStart;
extern u8 _textureconfigSegmentEnd;

void texReset(void)
{
	s32 stage;
	u32 len = &_textureconfigSegmentEnd - &_textureconfigSegmentStart;
	s32 i;

	g_TextureConfigSegment = mempAlloc(len, MEMPOOL_STAGE);
	dmaExec(g_TextureConfigSegment, (romptr_t)&_textureconfigSegmentRomStart, len);

	g_TexBase = (uintptr_t)g_TextureConfigSegment - ROM_SIZE * 1024 * 1024;
	g_TexGdl1 = (Gfx *)(g_TexBase + (uintptr_t)g_TcGdl1);
	g_TexGdl2 = (Gfx *)(g_TexBase + (uintptr_t)g_TcGdl2);
	g_TexGdl3 = (Gfx *)(g_TexBase + (uintptr_t)g_TcGdl3);
	g_ExplosionTexturePairs = (void *)(g_TexBase + (uintptr_t)g_TcExplosionTexturePairs);
	g_TexWallhitConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcWallhitConfigs);
	g_TexBeamConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcBeamConfigs);
	g_TexLaserConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcLaserConfigs);
	g_TexGroup03Configs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcGroup03Configs);
	g_TexGeCrosshairConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcGeCrosshairConfigs);
	g_TexRedLinesConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcRedLineConfigs);
	g_TexShadowConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcShadowConfigs);
	g_TexShieldConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcShieldConfigs);
	g_TexShardConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcShardConfigs);
	g_TexScreenConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcScreenConfigs);
	g_TexSkyWaterConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcSkyWaterConfigs);
	g_TexGroup11Configs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcGroup11Configs);
	g_TexLightGlareConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcLightGlareConfigs);
	g_TexSparkConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcSparkConfigs);
	g_TexGeneralConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcGeneralConfigs);
	g_TexRadarConfigs = (struct textureconfig *)(g_TexBase + (uintptr_t)g_TcRadarConfigs);

	g_TexNumConfigs = (len - (uintptr_t)&g_TcWallhitConfigs + ROM_SIZE * 1024 * 1024) / sizeof(struct textureconfig);
	g_TexWords = mempAlloc(ALIGN16(g_TexNumConfigs * 4), MEMPOOL_STAGE);

	for (i = 0; i < g_TexNumConfigs; i++) {
		g_TexWords[i] = NULL;
	}

	for (i = 0; i < ARRAYCOUNT(g_TcExplosionTexturePairs); i++) {
		texLoad(&g_ExplosionTexturePairs[i].texturenum1, NULL, false);
		texLoad(&g_ExplosionTexturePairs[i].texturenum2, NULL, false);
	}

	texLoadFromDisplayList(g_TexGdl1, 0, 0);
	texLoadFromDisplayList(g_TexGdl3, 0, 0);

	stage = mainGetStageNum();

	if (IS4MB() && stage != STAGE_TITLE && stage != STAGE_CITRAINING && stage != STAGE_4MBMENU) {
		for (i = 0; i < ARRAYCOUNT(g_TcWallhitConfigs); i++) {
			texLoadFromConfig(&g_TexWallhitConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcBeamConfigs); i++) {
			texLoadFromConfig(&g_TexBeamConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcSkyWaterConfigs); i++) {
			texLoadFromConfig(&g_TexSkyWaterConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcShadowConfigs); i++) {
			texLoadFromConfig(&g_TexShadowConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcShieldConfigs); i++) {
			texLoadFromConfig(&g_TexShieldConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcRadarConfigs); i++) {
			texLoadFromConfig(&g_TexRadarConfigs[i]);
		}

		for (i = 0; i < ARRAYCOUNT(g_TcSparkConfigs); i++) {
			texLoadFromConfig(&g_TexSparkConfigs[i]);
		}
	}
}
