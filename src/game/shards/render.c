#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/game_092610.h"
#include "game/atan2f.h"
#include "game/game_0b3350.h"
#include "game/gfxmemory.h"
#include "game/file.h"
#include "gvars/gvars.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

Gfx *shardsRenderWood(Gfx *gdl)
{
	if (g_ShardsActive) {
		s16 prevroom = 0;
		s32 i;
		Mtxf shardmtx;
		s32 j;

		if (g_Vars.currentplayer->visionmode);

		gSPClearGeometryMode(gdl++, G_CULL_BOTH);
		gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
		gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
		gDPSetCycleType(gdl++, G_CYC_2CYCLE);
		gDPSetTextureLOD(gdl++, G_TL_LOD);
		gSPMatrix(gdl++, osVirtualToPhysical(currentPlayerGetUnk1758()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		for (i = 0; i < g_MaxShards; i++) {
			if (g_Shards[i].age60 > 0 && g_Shards[i].type == SHARDTYPE_WOOD) {
				bool render = true;
				f32 alphamult = 1.0f;
				f32 xraydist;
				Mtxf *mtx = gfxAllocateMatrix();
				u32 stack;

				if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
					xraydist = sqrtf(ERASERSQDIST(g_Shards[i].pos.f));

					if (g_Vars.currentplayer->eraserpropdist < xraydist) {
						render = false;
					}

					if (g_Vars.currentplayer->eraserpropdist - 150.0f < xraydist) {
						alphamult = 1.0f - (xraydist - (g_Vars.currentplayer->eraserpropdist - 150.0f)) / 150.0f;
					}

					xraydist = xraydist / g_Vars.currentplayer->eraserpropdist;

					if (xraydist > 1.0f) {
						xraydist = 1.0f;
					}
				}

				if (render) {
					/**
					 * The following function call is really just this:
					 *
					 * func000166a4(&g_Shards[i].pos, &g_Shards[i].rot, &shardmtx);
					 *
					 * ... but that causes a mismatch, so I'm using a hacky but
					 * matching alternative. This hack is @dangerous because it
					 * assumes the offsets of pos and rot in the shard struct.
					 */
					func000166a4(
							(struct coord *)((u8 *)g_Shards + i * sizeof(struct shard) + 0x08),
							(struct coord *)((u8 *)g_Shards + i * sizeof(struct shard) + 0x14),
							&shardmtx);

					shardmtx.m[3][0] -= g_Vars.currentplayer->globaldrawworldoffset.x;
					shardmtx.m[3][1] -= g_Vars.currentplayer->globaldrawworldoffset.y;
					shardmtx.m[3][2] -= g_Vars.currentplayer->globaldrawworldoffset.z;

					if (shardmtx.m[3][0] < 10000 && shardmtx.m[3][0] > -10000
							&& shardmtx.m[3][1] < 10000 && shardmtx.m[3][1] > -10000
							&& shardmtx.m[3][2] < 10000 && shardmtx.m[3][2] > -10000) {
						func00016054(&shardmtx, mtx);

						gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

						if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
							u8 (*colours)[4] = gfxAllocateColours(3);

							if (g_Shards[i].age60 >= 100) {
								f32 frac = g_Shards[i].age60 / 50.0f;

								if (frac > 1) {
									frac = 1;
								}

								alphamult = (1.0f - frac) * alphamult;
							}

							alphamult *= 0.5f;

							for (j = 0; j < 3; j++) {
								colours[j][0] = xraydist * 255.0f;
								colours[j][1] = (1.0f - xraydist) * 255.0f;
								colours[j][2] = 0;
								colours[j][3] = g_Shards[var8007fa80].colours[j][3] * alphamult;
							}

							gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 3);
						} else {
							if (g_Shards[i].room != prevroom) {
								gdl = func0f001138(gdl, g_Shards[i].room);
								prevroom = g_Shards[i].room;
							}

							gDPSetColorArray(gdl++, osVirtualToPhysical(g_Shards[i].colours), 3);
						}

						gDPSetVerticeArray(gdl++, osVirtualToPhysical(g_Shards[i].vertices), 3);
						gSP1Triangle(gdl++, 0, 1, 2, 0);
					}
				}
			}
		}

		if (prevroom == 0) {
			gdl = func0f001300(gdl);
		}

		gSPClearGeometryMode(gdl++, G_LIGHTING | G_TEXTURE_GEN);
		gSPMatrix(gdl++, currentPlayerGetUnk1750(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gSPMatrix(gdl++, currentPlayerGetUnk173c(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	}

	return gdl;
}

Gfx *shardsRenderGlass(Gfx *gdl)
{
	if (g_ShardsActive) {
		s16 prevroom = 0;
		s32 i;
		Mtxf shardmtx;
		s32 j;

		if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
			func0f0b39c0(&gdl, NULL, 2, 1, 2, 1, 0);
		} else {
			func0f0b39c0(&gdl, &var800ab590[1], 2, 1, 2, 1, 0);
		}

		gSPTexture(gdl++, 0x0d80, 0x0d80, 2, G_TX_RENDERTILE, G_ON);
		gDPSetCycleType(gdl++, G_CYC_2CYCLE);
		gDPSetTextureLOD(gdl++, G_TL_LOD);
		gSPClearGeometryMode(gdl++, G_CULL_BOTH);
		gDPSetTextureFilter(gdl++, G_TF_BILERP);

		if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
			gSPSetGeometryMode(gdl++, G_LIGHTING | G_TEXTURE_GEN);
		}

		gSPMatrix(gdl++, osVirtualToPhysical(currentPlayerGetUnk1758()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		for (i = 0; i < g_MaxShards; i++) {
			if (g_Shards[i].age60 > 0 && g_Shards[i].type != SHARDTYPE_WOOD) {
				bool render = true;
				f32 alphamult = 1.0f;
				f32 xraydist;
				Mtxf *mtx = gfxAllocateMatrix();
				u32 stack;

				if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
					xraydist = sqrtf(ERASERSQDIST(g_Shards[i].pos.f));

					if (g_Vars.currentplayer->eraserpropdist < xraydist) {
						render = false;
					}

					if (g_Vars.currentplayer->eraserpropdist - 150.0f < xraydist) {
						alphamult = 1.0f - (xraydist - (g_Vars.currentplayer->eraserpropdist - 150.0f)) / 150.0f;
					}

					xraydist = xraydist / g_Vars.currentplayer->eraserpropdist;

					if (xraydist > 1.0f) {
						xraydist = 1.0f;
					}
				}

				if (render) {
					/**
					 * @dangerous: See comment for similar code in shardsRenderWood.
					 */
					func000166a4(
							(struct coord *)((u8 *)g_Shards + i * sizeof(struct shard) + 0x08),
							(struct coord *)((u8 *)g_Shards + i * sizeof(struct shard) + 0x14),
							&shardmtx);

					shardmtx.m[3][0] -= g_Vars.currentplayer->globaldrawworldoffset.x;
					shardmtx.m[3][1] -= g_Vars.currentplayer->globaldrawworldoffset.y;
					shardmtx.m[3][2] -= g_Vars.currentplayer->globaldrawworldoffset.z;

					if (shardmtx.m[3][0] < 10000 && shardmtx.m[3][0] > -10000
							&& shardmtx.m[3][1] < 10000 && shardmtx.m[3][1] > -10000
							&& shardmtx.m[3][2] < 10000 && shardmtx.m[3][2] > -10000) {
						func00016054(&shardmtx, mtx);

						gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

						if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
							u8 (*colours)[4] = gfxAllocateColours(3);

							if (g_Shards[i].age60 >= 100) {
								f32 frac = g_Shards[i].age60 / 50.0f;

								if (frac > 1) {
									frac = 1;
								}

								alphamult = (1.0f - frac) * alphamult;
							}

							alphamult *= 0.5f;

							for (j = 0; j < 3; j++) {
								colours[j][0] = xraydist * 255.0f;
								colours[j][1] = (1.0f - xraydist) * 255.0f;
								colours[j][2] = 0;
								colours[j][3] = g_Shards[var8007fa80].colours[j][3] * alphamult;
							}

							gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 3);
						} else {
							if (g_Shards[i].room != prevroom) {
								gdl = func0f001138(gdl, g_Shards[i].room);
								prevroom = g_Shards[i].room;
							}

							gDPSetColorArray(gdl++, osVirtualToPhysical(g_Shards[i].colours), 3);
						}

						gDPSetVerticeArray(gdl++, osVirtualToPhysical(g_Shards[i].vertices), 3);
						gSP1Triangle(gdl++, 0, 1, 2, 0);
					}
				}
			}
		}

		if (prevroom == 0) {
			gdl = func0f001300(gdl);
		}

		gSPClearGeometryMode(gdl++, G_LIGHTING | G_TEXTURE_GEN);
		gSPMatrix(gdl++, currentPlayerGetUnk1750(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gSPMatrix(gdl++, currentPlayerGetUnk173c(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	}

	return gdl;
}

Gfx *shardsRender(Gfx *gdl)
{
	gdl = shardsRenderWood(gdl);
	gdl = shardsRenderGlass(gdl);

	return gdl;
}
