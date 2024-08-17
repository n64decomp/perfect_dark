#ifndef _IN_GAME_SKY_H
#define _IN_GAME_SKY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void sky_reset(u32 stagenum);

void sky_tick(void);

void sky_get_world_pos_from_screen_pos(f32 left, f32 top, struct coord *dst);
bool sky_is_screen_corner_in_sky(struct coord *corner3dpos, struct coord *dstpos, f32 *dstfrac);
bool sky_is_corner_in_water(struct coord *corner3dpos, struct coord *dstpos, f32 *dstfrac);
void sky_calculate_edge_vertex(struct coord *arg0, struct coord *arg1, struct coord *out);
f32 sky_clamp(f32 value, f32 min, f32 max);
f32 sky_round(f32 value);
void sky_choose_cloud_vtx_colour(struct skyvtx3d *arg0, f32 arg1);
void sky_choose_water_vtx_colour(struct skyvtx3d *arg0, f32 arg1);
Gfx *sky_render(Gfx *gdl);
void sky_convert_vertex(struct skyvtx3d *arg0, Mtxf *arg1, u16 arg2, f32 arg3, f32 arg4, struct skyvtx2d *arg5);
bool sky_vertices_are_same(struct skyvtx2d *arg0, struct skyvtx2d *arg1);
Gfx *sky_render_tri(Gfx *gdl, struct skyvtx2d *arg1, struct skyvtx2d *arg2, struct skyvtx2d *arg3, f32 arg4, bool textured);
Gfx *sky_render_full(Gfx *gdl, struct skyvtx2d *arg1, struct skyvtx2d *arg2, struct skyvtx2d *arg3, struct skyvtx2d *arg4, f32 arg5);
void sky_create_sun_artifact(struct artifact *artifact, s32 x, s32 y);
f32 sky_get_artifact_group_intensity_frac(struct artifact *artifacts);
Gfx *sky_render_suns(Gfx *gdl, bool xray);
Gfx *sky_render_flare(Gfx *gdl, f32 x, f32 y, f32 intensityfrac, f32 size, s32 flaretimer240, f32 alphafrac);
Gfx *sky_render_teleport_flare(Gfx *gdl, f32 x, f32 y, f32 z, f32 size, f32 intensityfrac);
Gfx *sky_render_teleport_flares(Gfx *gdl);
Gfx *sky_render_artifacts(Gfx *gdl);
void sky_set_overexposure(s32 arg0, s32 arg1, s32 arg2);
s32 sky_calculate_overexposure_component(s32 arg0, s32 arg1);
Gfx *sky_render_overexposure(Gfx *gdl);

#endif
