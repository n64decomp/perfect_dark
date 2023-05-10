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

extern u8 *g_TextureConfigSegment;
extern u32 g_TexBase;
extern Gfx *g_TexGdl3;

extern u8 _textureconfigSegmentRomStart;
extern u8 _textureconfigSegmentStart;
extern u8 _textureconfigSegmentEnd;

void texReset(void)
{
	u32 len = &_textureconfigSegmentEnd - &_textureconfigSegmentStart;
	s32 i;

	g_TextureConfigSegment = mempAlloc(len, MEMPOOL_STAGE);
	dmaExec(g_TextureConfigSegment, (u32)&_textureconfigSegmentRomStart, len);

	g_TexBase = (u32)g_TextureConfigSegment - ROM_SIZE * 1024 * 1024;
	g_TexGdl1 = (Gfx *)(g_TexBase + (u32)g_TcGdl1);
	g_TexGdl2 = (Gfx *)(g_TexBase + (u32)g_TcGdl2);
	g_TexGdl3 = (Gfx *)(g_TexBase + (u32)g_TcGdl3);
	g_ExplosionTexturePairs = (void *)(g_TexBase + (u32)g_TcExplosionTexturePairs);
	g_TexWallhitConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcWallhitConfigs);
	g_TexBeamConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcBeamConfigs);
	g_TexLaserConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcLaserConfigs);
	g_TexGroup03Configs = (struct textureconfig *)(g_TexBase + (u32)g_TcGroup03Configs);
	g_TexGeCrosshairConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcGeCrosshairConfigs);
	g_TexShadowConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcGroup06Configs);
	g_TexShieldConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcShieldConfigs);
	g_TexShardConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcShardConfigs);
	g_TexScreenConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcScreenConfigs);
	g_TexWaterConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcWaterConfigs);
	g_TexLightGlareConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcLightGlareConfigs);
	g_TexSparkConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcSparkConfigs);
	g_TexGeneralConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcGeneralConfigs);
	g_TexRadarConfigs = (struct textureconfig *)(g_TexBase + (u32)g_TcRadarConfigs);

	g_TexNumConfigs = (len - (u32)&g_TcWallhitConfigs + ROM_SIZE * 1024 * 1024) / sizeof(struct textureconfig);
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
}
