#ifndef _IN_GAME_SKY_H
#define _IN_GAME_SKY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void skyReset(u32 stagenum);

void skyTick(void);

void skyGetWorldPosFromScreenPos(f32 left, f32 top, struct coord *dst);
bool skyIsScreenCornerInSky(struct coord *corner3dpos, struct coord *dstpos, f32 *dstfrac);
bool skyIsCornerInWater(struct coord *corner3dpos, struct coord *dstpos, f32 *dstfrac);
void skyCalculateEdgeVertex(struct coord *arg0, struct coord *arg1, struct coord *out);
f32 skyClamp(f32 value, f32 min, f32 max);
f32 skyRound(f32 value);
void skyChooseCloudVtxColour(struct skyvtx3d *arg0, f32 arg1);
void skyChooseWaterVtxColour(struct skyvtx3d *arg0, f32 arg1);
Gfx *skyRender(Gfx *gdl);
void skyConvertVertex(struct skyvtx3d *arg0, Mtxf *arg1, u16 arg2, f32 arg3, f32 arg4, struct skyvtx2d *arg5);
bool skyVerticesAreSame(struct skyvtx2d *arg0, struct skyvtx2d *arg1);
Gfx *skyRenderTri(Gfx *gdl, struct skyvtx2d *arg1, struct skyvtx2d *arg2, struct skyvtx2d *arg3, f32 arg4, bool textured);
Gfx *skyRenderFull(Gfx *gdl, struct skyvtx2d *arg1, struct skyvtx2d *arg2, struct skyvtx2d *arg3, struct skyvtx2d *arg4, f32 arg5);
void skyCreateSunArtifact(struct artifact *artifact, s32 x, s32 y);
f32 skyGetArtifactGroupIntensityFrac(struct artifact *artifacts);
Gfx *skyRenderSuns(Gfx *gdl, bool xray);
Gfx *skyRenderFlare(Gfx *gdl, f32 x, f32 y, f32 intensityfrac, f32 size, s32 flaretimer240, f32 alphafrac);
Gfx *skyRenderTeleportFlare(Gfx *gdl, f32 x, f32 y, f32 z, f32 size, f32 intensityfrac);
Gfx *skyRenderTeleportFlares(Gfx *gdl);
Gfx *skyRenderArtifacts(Gfx *gdl);
void skySetOverexposure(s32 arg0, s32 arg1, s32 arg2);
s32 skyCalculateOverexposureComponent(s32 arg0, s32 arg1);
Gfx *skyRenderOverexposure(Gfx *gdl);

#endif
