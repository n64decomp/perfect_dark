#include <ultra64.h>
#include "constants.h"
#include "game/prop.h"
#include "game/text.h"
#include "game/bg.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "lib/portal.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "lib/lib_2f490.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

#define SURFACE_FLOOR   0
#define SURFACE_CEILING 1

#define ATOBTYPE_CYL 0
#define ATOBTYPE_LOS 1

struct debugtri {
	s16 vertices[3][3];
	u8 unk12;
};

union filedataptr g_TileFileData;
s32 g_TileNumRooms;
u32 *g_TileRooms;

bool g_CdReverseVertices = false;

bool g_CdHasDistance;
f32 g_CdDistance;

bool g_CdHasEdge;
struct coord g_CdEdgeVtx1;
struct coord g_CdEdgeVtx2;

struct prop *g_CdProp;

bool g_CdHasPos;
struct coord g_CdPos;

bool g_CdHasDistance2;
f32 g_CdSquaredDistance;

bool g_CdHasBlockEdge;
struct coord g_CdBlockEdgeVtx1;
struct coord g_CdBlockEdgeVtx2;

bool g_CdHasBlock = false;
struct geoblock g_CdBlock;

bool g_CdHasGeo = false;
struct geo *g_CdGeo;

void cd_get_geo_normal(struct geo *geo, struct coord *normal);

f32 cd_get_sqdistance(void)
{
	return g_CdSquaredDistance;
}

void cd_get_edge(struct coord *vtx1, struct coord *vtx2, u32 line, char *file)
{
	vtx1->x = g_CdEdgeVtx1.x;
	vtx1->y = g_CdEdgeVtx1.y;
	vtx1->z = g_CdEdgeVtx1.z;

	vtx2->x = g_CdEdgeVtx2.x;
	vtx2->y = g_CdEdgeVtx2.y;
	vtx2->z = g_CdEdgeVtx2.z;
}

f32 cd_get_distance(void)
{
	return g_CdDistance;
}

bool cd_has_distance(void)
{
	return g_CdHasDistance;
}

struct prop *cd_get_obstacle_prop(void)
{
	return g_CdProp;
}

void cd_get_obstacle_pos(struct coord *pos, u32 line, char *file)
{
	pos->x = g_CdPos.x;
	pos->y = g_CdPos.y;
	pos->z = g_CdPos.z;
}

void cd_get_obstacle_normal(struct coord *normal)
{
	cd_get_geo_normal(g_CdGeo, normal);
}

u32 cd_get_geo_flags(void)
{
	u32 flags = 0;

	switch (g_CdGeo->type) {
	case GEOTYPE_TILE_I:
		flags = g_CdGeo->flags;
		break;
	case GEOTYPE_TILE_F:
		flags = g_CdGeo->flags;
		break;
	case GEOTYPE_BLOCK:
		flags = GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT;
		break;
	case GEOTYPE_CYL:
		flags = g_CdGeo->flags;
		break;
	}

	return flags;
}

void cd_clear_results(void)
{
	g_CdHasEdge = false;
	g_CdHasDistance = false;
	g_CdProp = NULL;
	g_CdHasPos = false;
	g_CdHasDistance2 = false;
	g_CdHasBlockEdge = false;
	g_CdHasBlock = false;
	g_CdHasGeo = false;
}

void cd_set_obstacle_edge_prop(struct coord *edgevtx1, struct coord *edgevtx2, struct prop *prop)
{
	g_CdEdgeVtx1.x = edgevtx1->x;
	g_CdEdgeVtx1.y = edgevtx1->y;
	g_CdEdgeVtx1.z = edgevtx1->z;

	g_CdEdgeVtx2.x = edgevtx2->x;
	g_CdEdgeVtx2.y = edgevtx2->y;
	g_CdEdgeVtx2.z = edgevtx2->z;

	g_CdHasEdge = true;
	g_CdHasDistance = false;
	g_CdProp = prop;
	g_CdHasPos = false;
	g_CdHasDistance2 = false;
	g_CdHasBlockEdge = false;
	g_CdHasBlock = false;
	g_CdHasGeo = false;
}

void cd_set_obstacle_edge_prop_dist(struct coord *edgevtx1, struct coord *edgevtx2, struct prop *prop, f32 dist)
{
	g_CdDistance = dist;

	g_CdEdgeVtx1.x = edgevtx1->x;
	g_CdEdgeVtx1.y = edgevtx1->y;
	g_CdEdgeVtx1.z = edgevtx1->z;

	g_CdEdgeVtx2.x = edgevtx2->x;
	g_CdEdgeVtx2.y = edgevtx2->y;
	g_CdEdgeVtx2.z = edgevtx2->z;

	g_CdHasEdge = true;
	g_CdHasDistance = true;
	g_CdProp = prop;
	g_CdHasPos = false;
	g_CdHasDistance2 = false;
	g_CdHasBlockEdge = false;
	g_CdHasBlock = false;
	g_CdHasGeo = false;
}

void cd_set_obstacle_distance(struct coord *frompos, struct coord *diff, f32 radius)
{
	struct radiusxz rxz;
	struct xz edge_vtx1;
	struct xz edge_vtx2;
	struct xz diffxz;

	rxz.radius = radius;
	rxz.x = frompos->x;
	rxz.z = frompos->z;

	diffxz.x = diff->x;
	diffxz.z = diff->z;

	edge_vtx1.x = g_CdEdgeVtx1.x;
	edge_vtx1.z = g_CdEdgeVtx1.z;

	edge_vtx2.x = g_CdEdgeVtx2.x;
	edge_vtx2.z = g_CdEdgeVtx2.z;

	g_CdDistance = func0f1579cc(&rxz, &edge_vtx1, &edge_vtx2, &diffxz);
	g_CdHasDistance = true;
}

void cd_set_obstacle_prop(struct prop *prop)
{
	g_CdHasEdge = false;
	g_CdHasDistance = false;
	g_CdProp = prop;
	g_CdHasPos = false;
	g_CdHasDistance2 = false;
	g_CdHasBlockEdge = false;
	g_CdHasBlock = false;
	g_CdHasGeo = false;
}

void cd_set_obstacle_edge_pos_prop(struct coord *edgevtx1, struct coord *edgevtx2, struct coord *collisionpos, struct prop *prop)
{
	g_CdEdgeVtx1.x = edgevtx1->x;
	g_CdEdgeVtx1.y = edgevtx1->y;
	g_CdEdgeVtx1.z = edgevtx1->z;

	g_CdEdgeVtx2.x = edgevtx2->x;
	g_CdEdgeVtx2.y = edgevtx2->y;
	g_CdEdgeVtx2.z = edgevtx2->z;

	g_CdPos.x = collisionpos->x;
	g_CdPos.y = collisionpos->y;
	g_CdPos.z = collisionpos->z;

	g_CdHasEdge = true;
	g_CdHasDistance = false;
	g_CdProp = prop;
	g_CdHasPos = true;
	g_CdHasDistance2 = false;
	g_CdHasBlockEdge = false;
	g_CdHasBlock = false;
	g_CdHasGeo = false;
}

void cd_set_obstacle_edge_pos_prop_sqdist_geo(struct coord *vtxpos1, struct coord *vtxpos2, struct coord *collisionpos, struct prop *prop, f32 sqdist, struct geo *geo)
{
	g_CdEdgeVtx1.x = vtxpos1->x;
	g_CdEdgeVtx1.y = vtxpos1->y;
	g_CdEdgeVtx1.z = vtxpos1->z;

	g_CdEdgeVtx2.x = vtxpos2->x;
	g_CdEdgeVtx2.y = vtxpos2->y;
	g_CdEdgeVtx2.z = vtxpos2->z;

	g_CdPos.x = collisionpos->x;
	g_CdPos.y = collisionpos->y;
	g_CdPos.z = collisionpos->z;

	g_CdHasEdge = true;
	g_CdHasDistance = false;
	g_CdProp = prop;
	g_CdHasPos = true;
	g_CdSquaredDistance = sqdist;
	g_CdHasDistance2 = true;
	g_CdHasBlockEdge = false;
	g_CdHasBlock = false;
	g_CdGeo = geo;
	g_CdHasGeo = true;
}

void cd_set_block_edge(struct coord *vtx1, struct coord *vtx2)
{
	g_CdBlockEdgeVtx1.x = vtx1->x;
	g_CdBlockEdgeVtx1.y = vtx1->y;
	g_CdBlockEdgeVtx1.z = vtx1->z;

	g_CdBlockEdgeVtx2.x = vtx2->x;
	g_CdBlockEdgeVtx2.y = vtx2->y;
	g_CdBlockEdgeVtx2.z = vtx2->z;

	g_CdHasBlockEdge = true;
}

bool cd_get_block_edge(struct coord *vtx1, struct coord *vtx2)
{
	if (g_CdHasBlockEdge) {
		vtx1->x = g_CdBlockEdgeVtx1.x;
		vtx1->y = g_CdBlockEdgeVtx1.y;
		vtx1->z = g_CdBlockEdgeVtx1.z;

		vtx2->x = g_CdBlockEdgeVtx2.x;
		vtx2->y = g_CdBlockEdgeVtx2.y;
		vtx2->z = g_CdBlockEdgeVtx2.z;
	}

	return g_CdHasBlockEdge;
}

void cd_set_block(struct geoblock *block)
{
	g_CdBlock = *block;
	g_CdHasBlock = true;
}

s32 cd_00025410(f32 x1, f32 z1, f32 x2, f32 z2)
{
	f32 f0 = x1 * z2;
	f32 f2 = z1 * x2;

	if (f2 < f0) {
		return 1;
	}

	if (f2 > f0) {
		return -1;
	}

	if (x1 * x2 < 0.0f || z1 * z2 < 0.0f) {
		return -1;
	}

	if (x1 * x1 + z1 * z1 < x2 * x2 + z2 * z2) {
		return 1;
	}

	return 0;
}

s32 cd_000254d8(struct coord *frompos, struct coord *topos, f32 x1, f32 z1, f32 x2, f32 z2, bool *first)
{
	f32 sp54;
	f32 sp50;
	f32 sp4c;
	f32 sp48;
	s32 sp44;
	s32 sp40;
	s32 sp3c;
	s32 sp38;
	s32 sp34;
	s32 sp30;
	bool result = false;

	sp54 = frompos->x - x1;
	sp50 = frompos->z - z1;

	sp3c = cd_00025410(x2 - x1, z2 - z1, sp54, sp50);
	sp44 = cd_00025410(x2 - x1, z2 - z1, topos->x - x1, topos->z - z1);
	sp38 = sp3c * sp44;

	if (sp38 <= 0) {
		sp4c = topos->x - frompos->x;
		sp48 = topos->z - frompos->z;

		sp34 = cd_00025410(sp4c, sp48, -sp54, -sp50);
		sp40 = cd_00025410(sp4c, sp48, x2 - frompos->x, z2 - frompos->z);
		sp30 = sp34 * sp40;

		if (sp30 <= 0) {
			result = true;
		}
	}

	if (*first && (result || sp3c <= 0)) {
		*first = false;
	}

	return result;
}

/**
 * Given a line between two vertices, draw a perpendicular line to pos and
 * return the distance of that line.
 */
f32 cd_pos_get_dist_to_line(f32 x1, f32 z1, f32 x2, f32 z2, f32 posx, f32 posz)
{
	u32 stack[8];
	f32 length;

	length = sqrtf((x2 - x1) * (x2 - x1) + (z2 - z1) * (z2 - z1));

	if (length == 0.0f) {
		return sqrtf((posx - x2) * (posx - x2) + (posz - z2) * (posz - z2));
	}

	return ((posx - x1) * (z2 - z1) + -(x2 - x1) * (posz - z1)) / length;
}

f32 cd_pos_get_dist_to_vtx(f32 x1, f32 z1, f32 posx, f32 posz)
{
	posx -= x1;
	posz -= z1;

	return sqrtf(posx * posx + posz * posz);
}

/**
 * Given a line between two vertices, figure out which side of the line the
 * position is on.
 */
s32 cd_pos_get_side(f32 x1, f32 z1, f32 x2, f32 z2, f32 posx, f32 posz)
{
	f32 x2_2;
	f32 z2_2;
	f32 f16;
	f32 f18;

	posx -= x1;
	posz -= z1;

	x2_2 = x2 - x1;
	z2_2 = z2 - z1;

	f16 = posx * x2_2 + posz * z2_2;
	f18 = x2_2 * x2_2 + z2_2 * z2_2;

	return (f18 < f16 && f16 < 0) || (f16 > 0 && f18 > f16);
}

/**
 * Given a 2D cylinder/circle, and a pos that is inside the circle,
 * move pos out to the edge of the circle then calculate a "wall" that
 * separates pos from the circle. Return the vertices of that wall.
 */
void cd_pos_get_cyl_edge(f32 cylx, f32 cylz, f32 cylradius, f32 posx, f32 posz, f32 *x1, f32 *z1, f32 *x2, f32 *z2)
{
	posx -= cylx;
	posz -= cylz;

	if (posx != 0 || posz != 0) {
		f32 dist = sqrtf(posx * posx + posz * posz);

		if (dist > 0) {
			dist = cylradius / dist;
			posx *= dist;
			posz *= dist;
		}
	}

	*x1 = cylx + posx + posz;
	*z1 = cylz + posz - posx;
	*x2 = cylx + posx - posz;
	*z2 = cylz + posz + posx;
}

void cd_get_geo_normal(struct geo *geo, struct coord *normal)
{
	if (geo->type == GEOTYPE_TILE_I) {
		struct geotilei *tile = (struct geotilei *) geo;
		s32 sp38[3];
		s32 sp2c[3];
		s32 sp20[3];

		sp38[0] = tile->vertices[1][0] - tile->vertices[0][0];
		sp38[1] = tile->vertices[1][1] - tile->vertices[0][1];
		sp38[2] = tile->vertices[1][2] - tile->vertices[0][2];

		sp2c[0] = tile->vertices[2][0] - tile->vertices[0][0];
		sp2c[1] = tile->vertices[2][1] - tile->vertices[0][1];
		sp2c[2] = tile->vertices[2][2] - tile->vertices[0][2];

		sp20[0] = sp38[1] * sp2c[2] - sp38[2] * sp2c[1];
		sp20[1] = sp38[2] * sp2c[0] - sp38[0] * sp2c[2];
		sp20[2] = sp38[0] * sp2c[1] - sp38[1] * sp2c[0];

		normal->x = sp20[0];
		normal->y = sp20[1];
		normal->z = sp20[2];
	} else if (geo->type == GEOTYPE_TILE_F) {
		struct geotilef *tile = (struct geotilef *) geo;
		f32 sp10[3];
		f32 sp04[3];

		sp10[0] = tile->vertices[1].x - tile->vertices[0].x;
		sp10[1] = tile->vertices[1].y - tile->vertices[0].y;
		sp10[2] = tile->vertices[1].z - tile->vertices[0].z;

		sp04[0] = tile->vertices[2].x - tile->vertices[0].x;
		sp04[1] = tile->vertices[2].y - tile->vertices[0].y;
		sp04[2] = tile->vertices[2].z - tile->vertices[0].z;

		normal->x = sp10[1] * sp04[2] - sp10[2] * sp04[1];
		normal->y = sp10[2] * sp04[0] - sp10[0] * sp04[2];
		normal->z = sp10[0] * sp04[1] - sp10[1] * sp04[0];
	} else if (geo->type == GEOTYPE_BLOCK) {
		normal->x = 0;
		normal->y = 1;
		normal->z = 0;
	} else if (geo->type == GEOTYPE_CYL) {
		normal->x = 0;
		normal->y = 1;
		normal->z = 0;
	}
}

void cd_get_floor_col(struct geo *geo, u16 *floorcol)
{
	if (geo == NULL) {
		*floorcol = 0xfff;
		return;
	}

	if (geo->type == GEOTYPE_TILE_I) {
		struct geotilei *tile = (struct geotilei *) geo;
		*floorcol = tile->floorcol;
		return;
	}

	if (geo->type == GEOTYPE_TILE_F) {
		struct geotilef *tile = (struct geotilef *) geo;
		*floorcol = tile->floorcol;
		return;
	}

	if (geo->type == GEOTYPE_BLOCK) {
		*floorcol = 0xfff;
		return;
	}

	if (geo->type == GEOTYPE_CYL) {
		*floorcol = 0xfff;
	}
}

void cd_get_floor_type(struct geo *geo, u8 *floortype)
{
	bool water = false;

	if (geo && (geo->flags & GEOFLAG_UNDERWATER)) {
		water = true;
	}

	if (geo == NULL) {
		*floortype = 0xff;
		return;
	}

	if (water) {
		*floortype = FLOORTYPE_WATER;
		return;
	}

	if (geo->type == GEOTYPE_TILE_I) {
		struct geotilei *tile0 = (struct geotilei *) geo;
		*floortype = tile0->floortype;
		return;
	}

	if (geo->type == GEOTYPE_TILE_F) {
		struct geotilef *tile1 = (struct geotilef *) geo;
		*floortype = tile1->floortype;
		return;
	}

	if (geo->type == GEOTYPE_BLOCK) {
		*floortype = 0xff;
		return;
	}

	if (geo->type == GEOTYPE_CYL) {
		*floortype = 0xff;
	}
}

f32 cd_find_y_tilei_vtx(struct geotilei *tile, f32 x, f32 z, s32 vertexindex)
{
	struct coord sp7c;
	struct coord sp70;
	s64 sp68;
	s64 sp60;
	s64 sp58;
	s64 tmp;
	f32 ground;
	s32 next;

	if (vertexindex == 0) {
		vertexindex = 1;
	}

	next = (vertexindex + 1) % tile->header.numvertices;

	if (next == 0) {
		next = 1;
	}

	sp7c.x = tile->vertices[vertexindex][0] - tile->vertices[0][0];
	sp7c.y = tile->vertices[vertexindex][1] - tile->vertices[0][1];
	sp7c.z = tile->vertices[vertexindex][2] - tile->vertices[0][2];

	sp70.x = tile->vertices[next][0] - tile->vertices[0][0];
	sp70.y = tile->vertices[next][1] - tile->vertices[0][1];
	sp70.z = tile->vertices[next][2] - tile->vertices[0][2];

	sp58 = sp7c.f[1] * sp70.f[2] - sp7c.f[2] * sp70.f[1];
	sp60 = sp7c.f[2] * sp70.f[0] - sp7c.f[0] * sp70.f[2];
	sp68 = sp7c.f[0] * sp70.f[1] - sp7c.f[1] * sp70.f[0];

	tmp = sp58 * tile->vertices[0][0]
		+ sp60 * tile->vertices[0][1]
		+ sp68 * tile->vertices[0][2];

	if (sp60 == 0) {
		return *(s16 *)(tile->ymax + (uintptr_t)tile);
	}

	ground = (tmp - (f64)x * sp58 - (f64)z * sp68) / sp60;

	if (ground > *(s16 *)(tile->ymax + (uintptr_t)tile)) {
		ground = *(s16 *)(tile->ymax + (uintptr_t)tile);
	} else if (ground < *(s16 *)(tile->ymin + (uintptr_t)tile)) {
		ground = *(s16 *)(tile->ymin + (uintptr_t)tile);
	}

	return ground;
}

#if VERSION < VERSION_NTSC_1_0
f32 cd_find_y_tilei_vtx1(struct geotilei *tile, f32 x, f32 z)
{
	return cd_find_y_tilei_vtx(tile, x, z, 1);
}
#endif

f32 cd_find_y_tilei(struct geotilei *tile, f32 x, f32 z)
{
	s32 i = 1;
	s32 ival = -1;
	struct geotilei *tile2 = tile;

	if (tile->header.numvertices >= 4) {
		while (i < tile->header.numvertices) {
			f32 tmpz = tile2->vertices[i][2];
			f32 tmpx = tile2->vertices[i][0];

			f32 fval = ((tile->vertices[0][2] - tmpz) * (x - tmpx))
				- ((tile2->vertices[0][0] - tmpx) * (0, z - tmpz));

			if (fval != 0) {
				if (ival < 0) {
					ival = (fval > 0);
				} else if (ival != 0 && fval < 0) {
					i--;
					break;
				} else if (ival == 0 && fval > 0) {
					i--;
					break;
				}
			}

			i++;
		}
	}

	return cd_find_y_tilei_vtx(tile, x, z, i);
}

f32 cd_find_y_tilef(struct geotilef *tile, f32 x, f32 z)
{
	struct coord sp24;
	struct coord sp18;
	struct coord sp0c;
	f32 tmp;
	f32 ground;

	sp24.x = tile->vertices[1].x - tile->vertices[0].x;
	sp24.y = tile->vertices[1].y - tile->vertices[0].y;
	sp24.z = tile->vertices[1].z - tile->vertices[0].z;

	sp18.x = tile->vertices[2].x - tile->vertices[0].x;
	sp18.y = tile->vertices[2].y - tile->vertices[0].y;
	sp18.z = tile->vertices[2].z - tile->vertices[0].z;

	sp0c.x = sp24.f[1] * sp18.f[2] - sp24.f[2] * sp18.f[1];
	sp0c.y = sp24.f[2] * sp18.f[0] - sp24.f[0] * sp18.f[2];
	sp0c.z = sp24.f[0] * sp18.f[1] - sp24.f[1] * sp18.f[0];

	tmp = sp0c.f[0] * tile->vertices[0].f[0]
		+ sp0c.f[1] * tile->vertices[0].f[1]
		+ sp0c.f[2] * tile->vertices[0].f[2];

	if (sp0c.f[1] == 0) {
		return tile->vertices[tile->max[1]].y;
	}

	ground = (tmp - (f64)x * (f64)sp0c.f[0] - (f64)z * (f64)sp0c.f[2]) / (f64)sp0c.f[1];

	if (ground > tile->vertices[tile->max[1]].y) {
		ground = tile->vertices[tile->max[1]].y;
	} else if (ground < tile->vertices[tile->min[1]].y) {
		ground = tile->vertices[tile->min[1]].y;
	}

	return ground;
}

bool cd_is_xz_in_tilei(struct geotilei *tile, f32 x, f32 z)
{
	s32 result = -1;
	s32 numvertices = tile->header.numvertices;
	s32 i;

	for (i = 0; i < numvertices; i++) {
		s32 next = (i + 1) % numvertices;

		f32 value = ((f32)tile->vertices[next][2] - (f32)tile->vertices[i][2]) * (x - tile->vertices[i][0])
			- ((f32)tile->vertices[next][0] - (f32)tile->vertices[i][0]) * (z - tile->vertices[i][2]);

		if (value != 0) {
			if (i == 0 || result < 0) {
				result = (value > 0);
			} else {
				if (result != 0 && value < 0) {
					return false;
				}

				if (result == 0 && value > 0) {
					return false;
				}
			}
		}
	}

	if (result < 0) {
		return false;
	}

	return true;
}

bool cd_is_xz_in_tilef(struct geotilef *tile, f32 x, f32 z)
{
	s32 result = -1;
	s32 numvertices = tile->header.numvertices;
	s32 i;

	for (i = 0; i < numvertices; i++) {
		s32 next = (i + 1) % numvertices;

		f32 value = (tile->vertices[next].z - tile->vertices[i].z) * (x - tile->vertices[i].x)
			- (tile->vertices[next].x - tile->vertices[i].x) * (z - tile->vertices[i].z);

		if (value != 0) {
			if (i == 0 || result < 0) {
				result = (value > 0);
			} else {
				if (result != 0 && value < 0) {
					return false;
				}

				if (result == 0 && value > 0) {
					return false;
				}
			}
		}
	}

	if (result < 0) {
		return false;
	}

	return true;
}

bool cd_is_xz_in_block(struct geoblock *tile, f32 x, f32 z)
{
	s32 result = -1;
	s32 numvertices = tile->header.numvertices;
	s32 i;

	for (i = 0; i < numvertices; i++) {
		s32 next = (i + 1) % numvertices;

		f32 value = (tile->vertices[next][1] - tile->vertices[i][1]) * (x - tile->vertices[i][0])
			- (tile->vertices[next][0] - tile->vertices[i][0]) * (z - tile->vertices[i][1]);

		if (value != 0) {
			if (i == 0 || result < 0) {
				result = (value > 0);
			} else {
				if (result != 0 && value < 0) {
					return false;
				}

				if (result == 0 && value > 0) {
					return false;
				}
			}
		}
	}

	if (result < 0) {
		return false;
	}

	return true;
}

bool cd_is_xz_in_cyl(struct geocyl *cyl, f32 x, f32 z)
{
	f32 xdiff = x - cyl->x;
	f32 zdiff = z - cyl->z;

	return xdiff * xdiff + zdiff * zdiff <= cyl->radius * cyl->radius;
}

bool cd_is_xz_in_geo(f32 x, f32 z, struct geo *geo)
{
	if (geo == NULL) {
		return false;
	}

	if (geo->type == GEOTYPE_BLOCK) {
		return cd_is_xz_in_block((struct geoblock *) geo, x, z);
	}

	if (geo->type == GEOTYPE_CYL) {
		return cd_is_xz_in_cyl((struct geocyl *) geo, x, z);
	}

	return false;
}

/**
 * For a lift or escalator step, find the props which are riding on it.
 */
void cd_get_props_on_platform(struct prop *platform, s16 *propnums, s32 maxlen)
{
	u8 *start;
	u8 *end;
	s16 roompropnums[257];
	struct prop *prop;
	s16 *roompropnumptr;
	struct geo *geo;
	s32 len = 0;

	if (prop_get_geometry(platform, &start, &end)) {
		room_get_props(platform->rooms, roompropnums, 256);
		roompropnumptr = roompropnums;

		while (*roompropnumptr >= 0) {
			prop = &g_Vars.props[*roompropnumptr];

			if (prop != platform) {
				geo = (struct geo *) start;

				while (geo < (struct geo *) end) {
					if (geo->type == GEOTYPE_TILE_I) {
						struct geotilei *tile = (struct geotilei *) geo;
						geo = (struct geo *)((uintptr_t)geo + sizeof(struct geotilei) + sizeof(tile->vertices[0]) * (tile->header.numvertices - ARRAYCOUNT(tile->vertices)));
					} else if (geo->type == GEOTYPE_TILE_F) {
						struct geotilef *tile = (struct geotilef *) geo;
						struct coord *pos = &prop->pos;

						if ((geo->flags & (GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2))
								&& pos->x >= tile->vertices[tile->min[0]].x
								&& pos->x <= tile->vertices[tile->max[0]].x
								&& pos->z >= tile->vertices[tile->min[2]].z
								&& pos->z <= tile->vertices[tile->max[2]].z
								&& pos->y >= tile->vertices[tile->min[1]].y
								&& cd_is_xz_in_tilef(tile, pos->x, pos->z)
								&& pos->y >= cd_find_y_tilef(tile, pos->x, pos->z)) {
							break;
						}

						geo = (struct geo *)((uintptr_t)geo + sizeof(struct geotilef) + sizeof(struct coord) * (tile->header.numvertices - ARRAYCOUNT(tile->vertices)));
					} else if (geo->type == GEOTYPE_BLOCK) {
						geo = (struct geo *)((uintptr_t)geo + sizeof(struct geoblock));
					} else if (geo->type == GEOTYPE_CYL) {
						geo = (struct geo *)((uintptr_t)geo + sizeof(struct geocyl));
					}
				}

				if (geo < (struct geo *) end) {
					if (len < maxlen - 2) {
						propnums[len] = *roompropnumptr;
						len++;
					} else {
						break;
					}
				}
			}

			roompropnumptr++;
		}
	}

	propnums[len] = -1;
}

#if VERSION < VERSION_NTSC_1_0
void cd_set_prop_y_bounds(struct prop *prop, f32 ymax, f32 ymin)
{
	u8 *start;
	u8 *end;

	if (prop_get_geometry(prop, &start, &end)) {
		struct geo *geo = (struct geo *) start;

		while (geo < (struct geo *) end) {
			if (geo->type == GEOTYPE_TILE_I) {
				struct geotilei *tile = (struct geotilei *) geo;
				geo = (struct geo *)((uintptr_t)geo + sizeof(struct geotilei) + sizeof(tile->vertices[0]) * (tile->header.numvertices - ARRAYCOUNT(tile->vertices)));
			} else if (geo->type == GEOTYPE_TILE_F) {
				struct geotilef *tile = (struct geotilef *) geo;
				geo = (struct geo *)((uintptr_t)geo + sizeof(struct geotilef) + sizeof(struct coord) * (tile->header.numvertices - ARRAYCOUNT(tile->vertices)));
			} else if (geo->type == GEOTYPE_BLOCK) {
				struct geoblock *block = (struct geoblock *) geo;
				block->ymax = ymax;
				block->ymin = ymin;
				geo = (struct geo *)((uintptr_t)geo + sizeof(struct geoblock));
			} else if (geo->type == GEOTYPE_CYL) {
				struct geocyl *cyl = (struct geocyl *) geo;
				cyl->ymax = ymax;
				cyl->ymin = ymin;
				geo = (struct geo *)((uintptr_t)geo + sizeof(struct geocyl));
			}
		}
	}
}
#endif

bool cd_find_y_from_bytes(struct coord *pos, u8 *start, u8 *end, u16 geoflags, s32 room, struct geo **tileptr, s32 *roomptr, f32 *yptr, bool ceiling)
{
	bool result = false;
	struct geo *geo = (struct geo *) start;

	if (room);

	while (geo < (struct geo *) end) {
		if (geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *) geo;

			if ((geo->flags & geoflags)
					&& pos->x >= *(s16 *)(tile->xmin + (uintptr_t)tile)
					&& pos->x <= *(s16 *)(tile->xmax + (uintptr_t)tile)
					&& pos->z >= *(s16 *)(tile->zmin + (uintptr_t)tile)
					&& pos->z <= *(s16 *)(tile->zmax + (uintptr_t)tile)) {
				if ((!ceiling && pos->y >= *(s16 *)(tile->ymin + (uintptr_t)tile))
						|| (ceiling && pos->y <= *(s16 *)(tile->ymax + (uintptr_t)tile))) {
					if (cd_is_xz_in_tilei(tile, pos->x, pos->z)) {
						f32 y = cd_find_y_tilei(tile, pos->x, pos->z);

						if ((!ceiling && y <= pos->y && y > *yptr)
								|| (ceiling && y >= pos->y && y < *yptr)) {
							*yptr = y;
							*tileptr = geo;
							*roomptr = room;
							result = true;
						}
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + sizeof(struct geotilei) + sizeof(tile->vertices[0]) * (tile->header.numvertices - ARRAYCOUNT(tile->vertices)));
		} else if (geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *) geo;

			if ((geo->flags & geoflags)
					&& pos->x >= tile->vertices[tile->min[0]].x
					&& pos->x <= tile->vertices[tile->max[0]].x
					&& pos->z >= tile->vertices[tile->min[2]].z
					&& pos->z <= tile->vertices[tile->max[2]].z) {
				if ((!ceiling && pos->y >= tile->vertices[tile->min[1]].y)
						|| (ceiling && pos->y <= tile->vertices[tile->max[1]].y)) {
					if (cd_is_xz_in_tilef(tile, pos->x, pos->z)) {
						f32 y = cd_find_y_tilef(tile, pos->x, pos->z);

						if ((!ceiling && pos->y >= y && y > *yptr)
								|| (ceiling && pos->y <= y && y < *yptr)) {
							*yptr = y;
							*tileptr = geo;
							*roomptr = room;
							result = true;
						}
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + sizeof(struct geotilef) + sizeof(struct coord) * (tile->header.numvertices - ARRAYCOUNT(tile->vertices)));
		} else if (geo->type == GEOTYPE_BLOCK) {
			geo = (struct geo *)((uintptr_t)geo + sizeof(struct geoblock));
		} else if (geo->type == GEOTYPE_CYL) {
			geo = (struct geo *)((uintptr_t)geo + sizeof(struct geocyl));
		}
	}

	return result;
}

void cd_find_y(struct coord *pos, RoomNum *rooms, u16 geoflags, struct geo **geoptr, RoomNum *roomptr, f32 *yptr, struct prop **propptr, bool ceiling)
{
	RoomNum *roomptr2;
	s32 roomnum;
	u8 *start;
	u8 *end;
	f32 closesty;
	struct geo *geo = NULL;
	s32 room = 0;
	struct prop *bestprop = NULL;
	s16 *propnumptr;
	s16 propnums[256];

	if (ceiling) {
		closesty = 4294967296;
	} else {
		closesty = -4294967296;
	}

	// Check BG
	roomptr2 = rooms;
	roomnum = rooms[0];

	while (roomnum != -1) {
		if (roomnum < g_TileNumRooms) {
			start = g_TileFileData.u8 + g_TileRooms[roomnum];
			end = g_TileFileData.u8 + g_TileRooms[roomnum + 1];

			cd_find_y_from_bytes(pos, start, end, geoflags, roomnum, &geo, &room, &closesty, ceiling);
		}

		roomptr2++;
		roomnum = *roomptr2;
	}

	// Check props
	room_get_props(rooms, propnums, 256);
	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop_get_geometry(prop, &start, &end)
				&& cd_find_y_from_bytes(pos, start, end, geoflags, prop->rooms[0], &geo, &room, &closesty, ceiling)) {
			bestprop = prop;
		}

		propnumptr++;
	}

	*geoptr = geo;
	*roomptr = room;
	*yptr = closesty;

	if (propptr != NULL) {
		*propptr = bestprop;
	}
}

bool cd_volume_collect_tilei(struct geotilei *tile, f32 x, f32 z, f32 radius, struct prop *prop, struct collision *collision)
{
	bool result = false;

	if (cd_is_xz_in_tilei(tile, x, z)) {
		collision->geo = &tile->header;
		collision->vertexindex = 0;
		collision->prop = prop;
		result = true;
	} else {
		s32 numvertices = tile->header.numvertices;
		s32 i;

		for (i = 0; i < numvertices; i++) {
			s32 next = (i + 1) % numvertices;
			f32 value = cd_pos_get_dist_to_line(tile->vertices[i][0], tile->vertices[i][2], tile->vertices[next][0], tile->vertices[next][2], x, z);

			if (value < 0) {
				value = -value;
			}

			if (value <= radius
					&& (cd_pos_get_dist_to_vtx(tile->vertices[i][0], tile->vertices[i][2], x, z) <= radius
						|| cd_pos_get_dist_to_vtx(tile->vertices[next][0], tile->vertices[next][2], x, z) <= radius
						|| cd_pos_get_side(tile->vertices[i][0], tile->vertices[i][2], tile->vertices[next][0], tile->vertices[next][2], x, z))) {
				collision->geo = &tile->header;
				collision->vertexindex = i;
				collision->prop = prop;
				result = true;
				break;
			}
		}
	}

	return result;
}

bool cd_volume_collect_tilef(struct geotilef *tile, f32 x, f32 z, f32 radius, struct prop *prop, struct collision *collision)
{
	bool result = false;

	if (cd_is_xz_in_tilef(tile, x, z)) {
		collision->geo = &tile->header;
		collision->vertexindex = 0;
		collision->prop = prop;
		result = true;
	} else {
		s32 numvertices = tile->header.numvertices;
		s32 i;

		for (i = 0; i < numvertices; i++) {
			s32 next = (i + 1) % numvertices;
			f32 value = cd_pos_get_dist_to_line(tile->vertices[i].x, tile->vertices[i].z, tile->vertices[next].x, tile->vertices[next].z, x, z);

			if (value < 0) {
				value = -value;
			}

			if (value <= radius
					&& (cd_pos_get_dist_to_vtx(tile->vertices[i].x, tile->vertices[i].z, x, z) <= radius
						|| cd_pos_get_dist_to_vtx(tile->vertices[next].x, tile->vertices[next].z, x, z) <= radius
						|| cd_pos_get_side(tile->vertices[i].x, tile->vertices[i].z, tile->vertices[next].x, tile->vertices[next].z, x, z))) {
				collision->geo = &tile->header;
				collision->vertexindex = i;
				collision->prop = prop;
				result = true;
				break;
			}
		}
	}

	return result;
}

s32 cd_block_collides_with_cyl_laterally(struct geoblock *tile, f32 x, f32 z, f32 radius, struct prop *prop, struct collision *collision)
{
	bool result = false;

	if (cd_is_xz_in_block(tile, x, z)) {
		if (collision) {
			collision->geo = &tile->header;
			collision->vertexindex = 0;
			collision->prop = prop;
		}

		result = true;
	} else {
		s32 numvertices = tile->header.numvertices;
		s32 i;

		for (i = 0; i < numvertices; i++) {
			s32 next = (i + 1) % numvertices;
			f32 value = cd_pos_get_dist_to_line(tile->vertices[i][0], tile->vertices[i][1],
					tile->vertices[next][0], tile->vertices[next][1],
					x, z);

			if (value < 0) {
				value = -value;
			}

			if (value <= radius
					&& (cd_pos_get_dist_to_vtx(tile->vertices[i][0], tile->vertices[i][1], x, z) <= radius
						|| cd_pos_get_dist_to_vtx(tile->vertices[next][0], tile->vertices[next][1], x, z) <= radius
						|| cd_pos_get_side(tile->vertices[i][0], tile->vertices[i][1], tile->vertices[next][0], tile->vertices[next][1], x, z))) {
				if (collision) {
					collision->geo = &tile->header;
					collision->vertexindex = i;
					collision->prop = prop;
				}

				result = true;
				break;
			}
		}
	}

	return result;
}

bool cd_cyl_collides_with_cyl_laterally(struct geocyl *cyl, f32 x, f32 z, f32 radius, struct prop *prop, struct collision *collision)
{
	bool result = false;

	f32 sumx = x - cyl->x;
	f32 sumz = z - cyl->z;
	f32 sumwidth = cyl->radius + radius;

	if (sumx * sumx + sumz * sumz <= sumwidth * sumwidth) {
		result = true;

		if (collision) {
			collision->geo = &cyl->header;
			collision->vertexindex = 0;
			collision->prop = prop;
		}
	}

	return result;
}

s32 cd_test_ramp_wall(struct geotilei *tile, struct coord *pos, f32 width, f32 y1, f32 y2);

void cd_volume_collect_from_bytes(struct coord *pos, f32 radius, u8 *start, u8 *end, u16 geoflags,
		bool checkvertical, f32 ymax, f32 ymin, struct prop *prop,
		struct collision *collisions, s32 maxcollisions, s32 *numcollisions, s32 roomnum)
{
	struct geo *geo = (struct geo *) start;
	s32 result;

	while (geo < (struct geo *) end) {
		if (geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *) geo;

			if ((geo->flags & geoflags)
					&& pos->x >= *(s16 *)(tile->xmin + (uintptr_t)tile) - radius
					&& pos->x <= *(s16 *)(tile->xmax + (uintptr_t)tile) + radius
					&& pos->z >= *(s16 *)(tile->zmin + (uintptr_t)tile) - radius
					&& pos->z <= *(s16 *)(tile->zmax + (uintptr_t)tile) + radius
					&& (!checkvertical || (pos->y + ymax >= *(s16 *)(tile->ymin + (uintptr_t)tile)
							&& pos->y + ymin <= *(s16 *)(tile->ymax + (uintptr_t)tile)))) {
				if (geo->flags & GEOFLAG_RAMPWALL) {
					result = cd_test_ramp_wall(tile, pos, radius, pos->y + ymin, pos->y + ymax);
				} else {
					result = 1;
				}

				if (result != 0) {
					if (cd_volume_collect_tilei(tile, pos->x, pos->z, radius, prop, &collisions[*numcollisions])) {
						collisions[*numcollisions].room = roomnum;
						*numcollisions = *numcollisions + 1;

						if (*numcollisions >= maxcollisions) {
							break;
						}
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOTILEI_SIZE(tile));
		} else if (geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *) geo;

			if ((geo->flags & geoflags)
					&& pos->x >= tile->vertices[tile->min[0]].x - radius
					&& pos->x <= tile->vertices[tile->max[0]].x + radius
					&& pos->z >= tile->vertices[tile->min[2]].z - radius
					&& pos->z <= tile->vertices[tile->max[2]].z + radius
					&& (!checkvertical || (pos->y + ymax >= tile->vertices[tile->min[1]].y
							&& pos->y + ymin <= tile->vertices[tile->max[1]].y))) {
				result = cd_volume_collect_tilef(tile, pos->x, pos->z, radius, prop, &collisions[*numcollisions]);

				if (result != 0) {
					collisions[*numcollisions].room = roomnum;
					*numcollisions = *numcollisions + 1;

					if (*numcollisions >= maxcollisions) {
						break;
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOTILEF_SIZE(tile));
		} else if (geo->type == GEOTYPE_BLOCK) {
			struct geoblock *block = (struct geoblock *) geo;

			if ((geoflags & (GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT))
					&& (!checkvertical || (pos->y + ymax >= block->ymin && pos->y + ymin <= block->ymax))) {
				result = cd_block_collides_with_cyl_laterally(block, pos->x, pos->z, radius, prop, &collisions[*numcollisions]);

				if (result) {
					collisions[*numcollisions].room = roomnum;
					*numcollisions = *numcollisions + 1;

					if (*numcollisions >= maxcollisions) {
						break;
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOBLOCK_SIZE(block));
		} else if (geo->type == GEOTYPE_CYL) {
			struct geocyl *cyl = (struct geocyl *) geo;

			if ((geoflags & geo->flags)
					&& (!checkvertical || (pos->y + ymax >= cyl->ymin && pos->y + ymin <= cyl->ymax))) {
				result = cd_cyl_collides_with_cyl_laterally(cyl, pos->x, pos->z, radius, prop, &collisions[*numcollisions]);

				if (result) {
					collisions[*numcollisions].room = roomnum;
					*numcollisions = *numcollisions + 1;

					if (*numcollisions >= maxcollisions) {
						break;
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOCYL_SIZE(cyl));
		}
	}
}

void cd_volume_collect(struct coord *pos, f32 radius, RoomNum *rooms, u32 types, u16 geoflags, bool checkvertical, f32 ymax, f32 ymin, struct collision *collisions, s32 maxcollisions)
{
	RoomNum *roomptr;
	s32 roomnum;
	u8 *start;
	u8 *end;
	s32 numcollisions = 0;
	s16 *propnumptr;
	s16 propnums[256];

	// Check BG
	if (types & CDTYPE_BG) {
		roomptr = rooms;
		roomnum = rooms[0];

		while (roomnum != -1) {
			if (roomnum < g_TileNumRooms) {
				start = g_TileFileData.u8 + g_TileRooms[roomnum];
				end = g_TileFileData.u8 + g_TileRooms[roomnum + 1];

				cd_volume_collect_from_bytes(pos, radius, start, end, geoflags, checkvertical, ymax, ymin, NULL, collisions, maxcollisions, &numcollisions, roomnum);

				if (numcollisions >= maxcollisions) {
					goto end;
				}
			}

			roomptr++;
			roomnum = *roomptr;
		}
	}

	// Check props
	room_get_props(rooms, propnums, 256);
	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop_is_of_cd_type(prop, types) && prop_get_geometry(prop, &start, &end)) {
			cd_volume_collect_from_bytes(pos, radius, start, end, geoflags, checkvertical, ymax, ymin, prop, collisions, maxcollisions, &numcollisions, prop->rooms[0]);

			if (numcollisions >= maxcollisions) {
				break;
			}
		}

		propnumptr++;
	}

end:
	collisions[numcollisions].geo = NULL;
}

void cd_volumefromdir_collect_tilei(struct geotilei *tile, f32 posx, f32 posz, f32 radius, struct prop *prop, struct collision *collisions, s32 maxcollisions, s32 *numcollisions)
{
	s32 i;
	s32 numvertices = tile->header.numvertices;

	for (i = 0; i < numvertices; i++) {
		s32 next = (i + 1) % numvertices;

		if (tile->vertices[i][0] != tile->vertices[next][0] || tile->vertices[i][2] != tile->vertices[next][2]) {
			f32 dist = cd_pos_get_dist_to_line(tile->vertices[i][0], tile->vertices[i][2], tile->vertices[next][0], tile->vertices[next][2], posx, posz);

			if (dist < 0.0f) {
				dist = -dist;
			}

			if (dist <= radius
					&& (cd_pos_get_dist_to_vtx(tile->vertices[i][0], tile->vertices[i][2], posx, posz) <= radius
						|| cd_pos_get_dist_to_vtx(tile->vertices[next][0], tile->vertices[next][2], posx, posz) <= radius
						|| cd_pos_get_side(tile->vertices[i][0], tile->vertices[i][2], tile->vertices[next][0], tile->vertices[next][2], posx, posz))) {
				if (*numcollisions < maxcollisions) {
					collisions[*numcollisions].geo = &tile->header;
					collisions[*numcollisions].vertexindex = i;
					collisions[*numcollisions].prop = prop;
					*numcollisions += 1;
				} else {
					break;
				}
			}
		}
	}
}

/**
 * Triangular wall tiles are generally implemented with just a bounding box check,
 * but this means if the player gets on top of one they can walk across it.
 * This is a problem for ramps that the player can jump off at any height
 * such as the Air Base staircase near the baggage terminal.
 *
 * To handle this, the ramp wall tiles are flagged with GEOFLAG_RAMPWALL.
 * When collision checks are being done, tiles with this flag are passed to
 * this function which does a more extensive check.
 */
s32 cd_test_ramp_wall(struct geotilei *tile, struct coord *pos, f32 width, f32 y1, f32 y2)
{
	s32 count;
	s32 i;
	s32 y1count;
	s32 y2count;
	s32 numverts;

	if (!g_Vars.enableslopes && (tile->header.flags & GEOFLAG_SLOPE)) {
		return 0;
	}

	numverts = tile->header.numvertices;
	y2count = 0;
	y1count = 0;
	count = 0;

	for (i = 0; i < numverts; i++) {
		s32 next = i + 1;
		s32 last = numverts - 1;
		f32 posval;
		f32 thisvals[2];
		f32 nextvals[2];
		f32 somefloat;
		f32 somefloat2;
		s32 xdiff;
		s32 zdiff;

		if (i == last) {
			next = 0;
		}

		xdiff = tile->vertices[next][0] - tile->vertices[i][0];
		zdiff = tile->vertices[next][2] - tile->vertices[i][2];

		if (xdiff < 0) {
			xdiff = -xdiff;
		}

		if (zdiff < 0) {
			zdiff = -zdiff;
		}

		if (xdiff || zdiff) {
			thisvals[1] = tile->vertices[i][1];
			nextvals[1] = tile->vertices[next][1];

			if (zdiff < xdiff) {
				thisvals[0] = tile->vertices[i][0];
				nextvals[0] = tile->vertices[next][0];
				posval = pos->x;
			} else {
				thisvals[0] = tile->vertices[i][2];
				nextvals[0] = tile->vertices[next][2];
				posval = pos->z;
			}

			somefloat = (posval - thisvals[0]) / (nextvals[0] - thisvals[0]);

			if (somefloat <= 1.0f && somefloat >= 0.0f) {
				somefloat2 = thisvals[1] + (nextvals[1] - thisvals[1]) * somefloat;

				if (somefloat2 >= y2 - 1.0f) {
					y2count++;

					if (y1count != 0) {
						count++;
					}
				} else if (somefloat2 <= y1 + 1.0f) {
					y1count++;

					if (y2count != 0) {
						count++;
					}
				} else {
					count++;
				}
			}
		}
	}

	return count;
}

void cd_volumefromdir_collect_tilef(struct geotilef *tile, f32 posx, f32 posz, f32 radius, struct prop *prop, struct collision *collisions, s32 maxcollisions, s32 *numcollisions)
{
	s32 i;
	s32 numvertices = tile->header.numvertices;

	for (i = 0; i < numvertices; i++) {
		s32 next = (i + 1) % numvertices;

		if (tile->vertices[i].x != tile->vertices[next].x || tile->vertices[i].z != tile->vertices[next].z) {
			f32 dist = cd_pos_get_dist_to_line(tile->vertices[i].x, tile->vertices[i].z, tile->vertices[next].x, tile->vertices[next].z, posx, posz);

			if (dist < 0.0f) {
				dist = -dist;
			}

			if (dist <= radius
					&& (cd_pos_get_dist_to_vtx(tile->vertices[i].x, tile->vertices[i].z, posx, posz) <= radius
						|| cd_pos_get_dist_to_vtx(tile->vertices[next].x, tile->vertices[next].z, posx, posz) <= radius
						|| cd_pos_get_side(tile->vertices[i].x, tile->vertices[i].z, tile->vertices[next].x, tile->vertices[next].z, posx, posz))) {
				if (*numcollisions < maxcollisions) {
					collisions[*numcollisions].geo = &tile->header;
					collisions[*numcollisions].vertexindex = i;
					collisions[*numcollisions].prop = prop;
					*numcollisions += 1;
				} else {
					break;
				}
			}
		}
	}
}

void cd_volumefromdir_collect_block(struct geoblock *block, f32 posx, f32 posz, f32 radius, struct prop *prop, struct collision *collisions, s32 maxcollisions, s32 *numcollisions)
{
	s32 i;
	s32 numvertices = block->header.numvertices;

	for (i = 0; i < numvertices; i++) {
		s32 next = (i + 1) % numvertices;

		if (block->vertices[i][0] != block->vertices[next][0] || block->vertices[i][1] != block->vertices[next][1]) {
			f32 dist = cd_pos_get_dist_to_line(block->vertices[i][0], block->vertices[i][1], block->vertices[next][0], block->vertices[next][1], posx, posz);

			if (dist < 0.0f) {
				dist = -dist;
			}

			if (dist <= radius
					&& (cd_pos_get_dist_to_vtx(block->vertices[i][0], block->vertices[i][1], posx, posz) <= radius
						|| cd_pos_get_dist_to_vtx(block->vertices[next][0], block->vertices[next][1], posx, posz) <= radius
						|| cd_pos_get_side(block->vertices[i][0], block->vertices[i][1], block->vertices[next][0], block->vertices[next][1], posx, posz))) {
				if (*numcollisions < maxcollisions) {
					collisions[*numcollisions].geo = &block->header;
					collisions[*numcollisions].vertexindex = i;
					collisions[*numcollisions].prop = prop;
					*numcollisions += 1;
				} else {
					break;
				}
			}
		}
	}
}

void cd_volumefromdir_collect_cyl(struct geocyl *cyl, f32 posx, f32 posz, f32 radius, struct prop *prop, struct collision *collisions, s32 maxcollisions, s32 *numcollisions)
{
	f32 xdiff = posx - cyl->x;
	f32 zdiff = posz - cyl->z;
	f32 f16 = radius + cyl->radius;

	if (xdiff * xdiff + zdiff * zdiff <= f16 * f16) {
		if (*numcollisions < maxcollisions) {
			collisions[*numcollisions].geo = &cyl->header;
			collisions[*numcollisions].vertexindex = 0;
			collisions[*numcollisions].prop = prop;
			*numcollisions += 1;
		}
	}
}

void cd_volumefromdir_collect_from_bytes(u8 *start, u8 *end, struct coord *pos, f32 radius, u16 geoflags,
		bool checkvertical, f32 ymax, f32 ymin, struct prop *prop,
		struct collision *collisions, s32 maxcollisions, s32 *numcollisions)
{
	struct geo *geo = (struct geo *) start;

	while (geo < (struct geo *) end) {
		if (geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *) geo;

			if (geo->flags & geoflags) {
				if (pos->x >= *(s16 *)(tile->xmin + (uintptr_t)tile) - radius
						&& pos->x <= *(s16 *)(tile->xmax + (uintptr_t)tile) + radius
						&& pos->z >= *(s16 *)(tile->zmin + (uintptr_t)tile) - radius
						&& pos->z <= *(s16 *)(tile->zmax + (uintptr_t)tile) + radius
						&& (!checkvertical || (pos->y + ymax >= *(s16 *)(tile->ymin + (uintptr_t)tile)
								&& pos->y + ymin <= *(s16 *)(tile->ymax + (uintptr_t)tile)))) {
					bool pass;

					if (geo->flags & GEOFLAG_RAMPWALL) {
						pass = cd_test_ramp_wall(tile, pos, radius, pos->y + ymin, pos->y + ymax);
					} else {
						pass = true;
					}

					if (pass) {
						cd_volumefromdir_collect_tilei(tile, pos->x, pos->z, radius, prop, collisions, maxcollisions, numcollisions);
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOTILEI_SIZE(tile));
		} else if (geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *) geo;

			if ((geo->flags & geoflags)
					&& pos->x >= tile->vertices[tile->min[0]].x - radius
					&& pos->x <= tile->vertices[tile->max[0]].x + radius
					&& pos->z >= tile->vertices[tile->min[2]].z - radius
					&& pos->z <= tile->vertices[tile->max[2]].z + radius
					&& (!checkvertical || (pos->y + ymax >= tile->vertices[tile->min[1]].y
							&& pos->y + ymin <= tile->vertices[tile->max[1]].y))) {
				cd_volumefromdir_collect_tilef(tile, pos->x, pos->z, radius, prop, collisions, maxcollisions, numcollisions);
			}

			geo = (struct geo *)((uintptr_t)geo + GEOTILEF_SIZE(tile));
		} else if (geo->type == GEOTYPE_BLOCK) {
			struct geoblock *block = (struct geoblock *) geo;

			if ((geoflags & (GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT))
					&& (!checkvertical || (pos->y + ymax >= block->ymin && pos->y + ymin <= block->ymax))) {
				cd_volumefromdir_collect_block(block, pos->x, pos->z, radius, prop, collisions, maxcollisions, numcollisions);
			}

			geo = (struct geo *)((uintptr_t)geo + GEOBLOCK_SIZE(block));
		} else if (geo->type == GEOTYPE_CYL) {
			struct geocyl *cyl = (struct geocyl *) geo;

			if ((geoflags & geo->flags)
					&& (!checkvertical || (pos->y + ymax >= cyl->ymin && pos->y + ymin <= cyl->ymax))) {
				cd_volumefromdir_collect_cyl(cyl, pos->x, pos->z, radius, prop, collisions, maxcollisions, numcollisions);
			}

			geo = (struct geo *)((uintptr_t)geo + GEOCYL_SIZE(cyl));
		}
	}
}

void cd_volumefromdir_collect(struct coord *pos, f32 width, RoomNum *rooms, u32 types, u16 geoflags, bool checkvertical, f32 ymax, f32 ymin, struct collision *collisions, s32 maxcollisions)
{
	RoomNum *roomptr;
	s32 roomnum;
	u8 *start;
	u8 *end;
	s32 numcollisions = 0;
	s16 *propnumptr;
	s16 propnums[256];

	// Check BG
	if (types & CDTYPE_BG) {
		roomptr = rooms;
		roomnum = rooms[0];

		while (roomnum != -1) {
			if (roomnum < g_TileNumRooms) {
				start = g_TileFileData.u8 + g_TileRooms[roomnum];
				end = g_TileFileData.u8 + g_TileRooms[roomnum + 1];

				cd_volumefromdir_collect_from_bytes(start, end, pos, width, geoflags, checkvertical, ymax, ymin, NULL, collisions, maxcollisions, &numcollisions);
			}

			roomptr++;
			roomnum = *roomptr;
		}
	}

	// Check props
	room_get_props(rooms, propnums, 256);
	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop_is_of_cd_type(prop, types) && prop_get_geometry(prop, &start, &end)) {
			cd_volumefromdir_collect_from_bytes(start, end, pos, width, geoflags, checkvertical, ymax, ymin, prop, collisions, maxcollisions, &numcollisions);
		}

		propnumptr++;
	}

	collisions[numcollisions].geo = NULL;
}

void cd_volumefromdir_finalise(struct coord *frompos, struct coord *dist, f32 radius, struct collision *collisions)
{
	s32 i;
	struct radiusxz spf8;
	struct xz spf0;
	struct xz spe8;
	struct xz spe0;
	f32 bestvalue = 0.0f;
	s32 bestindex = -1;
	u32 stack;
	f32 value;
	s32 curr;
	s32 next;
	struct coord edgevtx1;
	struct coord edgevtx2;
	struct geo *geo;

	for (i = 0; (geo = collisions[i].geo) != NULL; i++) {
		if (1);
		if (geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *) geo;

			spf8.radius = radius;
			spf8.x = frompos->x;
			spf8.z = frompos->z;

			spe0.x = dist->x;
			spe0.z = dist->z;

			curr = collisions[i].vertexindex;
			next = (curr + 1) % tile->header.numvertices;

			spf0.x = tile->vertices[curr][0];
			spf0.z = tile->vertices[curr][2];

			spe8.x = tile->vertices[next][0];
			spe8.z = tile->vertices[next][2];

			value = func0f1579cc(&spf8, &spf0, &spe8, &spe0);

			if (bestindex < 0 || value < bestvalue) {
				bestvalue = value;
				bestindex = i;
			}
		} else if (geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *) geo;

			spf8.radius = radius;
			spf8.x = frompos->x;
			spf8.z = frompos->z;

			spe0.x = dist->x;
			spe0.z = dist->z;

			curr = collisions[i].vertexindex;
			next = (curr + 1) % tile->header.numvertices;

			spf0.x = tile->vertices[curr].x;
			spf0.z = tile->vertices[curr].z;

			spe8.x = tile->vertices[next].x;
			spe8.z = tile->vertices[next].z;

			value = func0f1579cc(&spf8, &spf0, &spe8, &spe0);

			if (bestindex < 0 || value < bestvalue) {
				bestvalue = value;
				bestindex = i;
			}
		} else if (geo->type == GEOTYPE_BLOCK) {
			struct geoblock *block = (struct geoblock *) geo;

			spf8.radius = radius;
			spf8.x = frompos->x;
			spf8.z = frompos->z;

			spe0.x = dist->x;
			spe0.z = dist->z;

			curr = collisions[i].vertexindex;
			next = (curr + 1) % block->header.numvertices;

			spf0.x = block->vertices[curr][0];
			spf0.z = block->vertices[curr][1];

			spe8.x = block->vertices[next][0];
			spe8.z = block->vertices[next][1];

			value = func0f1579cc(&spf8, &spf0, &spe8, &spe0);

			if (bestindex < 0 || value < bestvalue) {
				bestvalue = value;
				bestindex = i;
			}
		} else if (geo->type == GEOTYPE_CYL) {
			struct geocyl *cyl = (struct geocyl *) geo;

			spf8.radius = cyl->radius + radius;
			spf8.x = frompos->x;
			spf8.z = frompos->z;

			spe0.x = dist->x;
			spe0.z = dist->z;

			spf0.x = cyl->x;
			spf0.z = cyl->z;

			spe8.x = cyl->x;
			spe8.z = cyl->z;

			value = func0f1579cc(&spf8, &spf0, &spe8, &spe0);

			if (bestindex < 0 || value < bestvalue) {
				bestvalue = value;
				bestindex = i;
			}
		}
	}

	if (collisions[bestindex].geo->type == GEOTYPE_TILE_I) {
		struct geotilei *tile = (struct geotilei *) collisions[bestindex].geo;
		s32 curr = collisions[bestindex].vertexindex;
		s32 next = (curr + 1) % tile->header.numvertices;

		edgevtx1.x = tile->vertices[curr][0];
		edgevtx1.y = tile->vertices[curr][1];
		edgevtx1.z = tile->vertices[curr][2];

		edgevtx2.x = tile->vertices[next][0];
		edgevtx2.y = tile->vertices[next][1];
		edgevtx2.z = tile->vertices[next][2];
	} else if (collisions[bestindex].geo->type == GEOTYPE_TILE_F) {
		struct geotilef *tile = (struct geotilef *) collisions[bestindex].geo;
		s32 curr = collisions[bestindex].vertexindex;
		s32 next = (curr + 1) % tile->header.numvertices;

		edgevtx1.x = tile->vertices[curr].x;
		edgevtx1.y = tile->vertices[curr].y;
		edgevtx1.z = tile->vertices[curr].z;

		edgevtx2.x = tile->vertices[next].x;
		edgevtx2.y = tile->vertices[next].y;
		edgevtx2.z = tile->vertices[next].z;
	} else if (collisions[bestindex].geo->type == GEOTYPE_BLOCK) {
		struct geoblock *block = (struct geoblock *) collisions[bestindex].geo;
		s32 curr = collisions[bestindex].vertexindex;
		s32 next = (curr + 1) % block->header.numvertices;

		edgevtx1.x = block->vertices[curr][0];
		edgevtx1.y = frompos->y;
		edgevtx1.z = block->vertices[curr][1];

		edgevtx2.x = block->vertices[next][0];
		edgevtx2.y = frompos->y;
		edgevtx2.z = block->vertices[next][1];
	} else if (collisions[bestindex].geo->type == GEOTYPE_CYL) {
		struct geocyl *cyl = (struct geocyl *) collisions[bestindex].geo;

		cd_pos_get_cyl_edge(cyl->x, cyl->z, cyl->radius, frompos->x, frompos->z, &edgevtx1.x, &edgevtx1.z, &edgevtx2.x, &edgevtx2.z);

		edgevtx1.y = frompos->y;
		edgevtx2.y = frompos->y;
	}

	cd_set_obstacle_edge_prop_dist(&edgevtx1, &edgevtx2, collisions[bestindex].prop, bestvalue);
}

f32 cd_find_ground_finalise(struct collision *collisions, struct coord *pos, struct collision **collisionptr, f32 width)
{
	struct collision *collision;
	s32 i;
	f32 curground = -4294967296;
	bool hasground = false;
	bool anyintile = false;
	bool hasflag0100 = false;
#if VERSION >= VERSION_NTSC_1_0
	bool hasdie = false;
	bool hasgroundfromearlier;
	bool isdie;
#else
	u32 unused1;
#endif
	f32 nextvalue;
	f32 spe4;
	f32 f30;
	f32 x;
	f32 z;
	f32 spd4;
	f32 f14;
	f32 spb4;
	f32 thisvalue;
	u32 unused2;
	s32 next;
	s32 numvertices;
	f32 spb8;
#if VERSION >= VERSION_NTSC_1_0
	u32 unused3[8];
#else
	u32 unused3[7];
#endif
	f32 sp94;
	u32 unused4[6];
	f32 sp78;
	f32 sp74;
	f32 nextx;
	f32 nextz;
	f32 ground;
	u32 unused5[5];
	f32 thisx;
	f32 thisz;

	*collisionptr = NULL;

	for (collision = collisions; collision->geo != NULL; collision++) {
		if (collision->geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *) collision->geo;

			if (tile->header.flags & GEOFLAG_DIE) {
				collision->intile = false;
			} else {
				if (tile->header.flags & GEOFLAG_SLOPE) {
					hasflag0100 = true;
				}

				collision->intile = cd_is_xz_in_tilei(tile, pos->x, pos->z);

				if (collision->intile) {
					anyintile = true;
				}
			}
		} else if (collision->geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *) collision->geo;

			collision->intile = cd_is_xz_in_tilef(tile, pos->x, pos->z);

			if (collision->intile) {
				anyintile = true;
			}
		}
	}

	if (anyintile) {
		for (collision = collisions; collision->geo != NULL; collision++) {
			if (collision->intile) {
				if (collision->geo->type == GEOTYPE_TILE_I) {
					struct geotilei *tile = (struct geotilei *) collision->geo;

					if ((tile->header.flags & GEOFLAG_STEP) == 0) {
						ground = cd_find_y_tilei((void *)collision->geo, pos->x, pos->z);

						if (ground >= curground && ground < pos->y) {
							curground = ground;
							*collisionptr = collision;
							hasground = true;
						}
					}
				} else if (collision->geo->type == GEOTYPE_TILE_F) {
					struct geotilef *tile = (struct geotilef *) collision->geo;

					ground = cd_find_y_tilef((void *)collision->geo, pos->x, pos->z);

					if (ground >= curground && ground < pos->y) {
						curground = ground;
						*collisionptr = collision;
						hasground = true;
					}
				}
			}
		}

		for (collision = collisions; collision->geo != NULL; collision++) {
			if (collision->intile) {
				if (collision->geo->type == GEOTYPE_TILE_I) {
					struct geotilei *tile = (struct geotilei *) collision->geo;

					if (tile->header.flags & GEOFLAG_STEP) {
						ground = cd_find_y_tilei((void *)collision->geo, pos->x, pos->z);

						if (ground >= curground && (ground < pos->y || !hasground)) {
							curground = ground;
							*collisionptr = collision;
							hasground = true;
						}
					}
				}
			}
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	hasgroundfromearlier = hasground;
#endif

	if (!hasground || hasflag0100) {
		spe4 = 4294967296.0f;

		for (collision = collisions; collision->geo != NULL; collision++) {
#if VERSION >= VERSION_NTSC_1_0
			if (collision->intile == false
					&& (!hasgroundfromearlier || (collision->geo->type == GEOTYPE_TILE_I && (collision->geo->flags & GEOFLAG_SLOPE))))
#else
			if (collision->intile == false
					&& (!hasground || (collision->geo->type == GEOTYPE_TILE_I && (collision->geo->flags & GEOFLAG_SLOPE))))
#endif
			{
				if (collision->geo->type == GEOTYPE_TILE_I) {
					struct geotilei *tile = (struct geotilei *) collision->geo;
					numvertices = tile->header.numvertices;
#if VERSION >= VERSION_NTSC_1_0
					isdie = (tile->header.flags & GEOFLAG_DIE) != 0;
#endif

#if VERSION >= VERSION_NTSC_1_0
					if (!isdie || !hasground)
#endif
					{
						for (i = 0; i < numvertices; i++) {
							thisx = tile->vertices[i][0];
							thisz = tile->vertices[i][2];

							next = (i + 1) % numvertices;

							nextx = tile->vertices[next][0];
							nextz = tile->vertices[next][2];

							spd4 = cd_pos_get_dist_to_line(thisx, thisz, nextx, nextz, pos->x, pos->z);
							f30 = spd4;

							if (f30 < 0.0f) {
								f30 = -f30;
							}

#if VERSION >= VERSION_NTSC_1_0
							if (f30 < spe4 || hasdie)
#else
							if (f30 < spe4)
#endif
							{
								if (cd_pos_get_side(thisx, thisz, nextx, nextz, pos->x, pos->z)) {
									spb8 = nextx - thisx;
									spb4 = nextz - thisz;
									f14 = spd4 / sqrtf(spb8 * spb8 + spb4 * spb4);
									x = pos->x + f14 * -spb4;
									z = pos->z + f14 * spb8;

									ground = cd_find_y_tilei_vtx(tile, x, z, i);

									if (ground < pos->y || (collision->geo->flags & GEOFLAG_STEP)) {
										curground = ground;
										*collisionptr = collision;
										spe4 = f30;
#if VERSION >= VERSION_NTSC_1_0
										hasground = true;
										hasdie = isdie;
#endif
									}
								} else {
									thisvalue = cd_pos_get_dist_to_vtx(thisx, thisz, pos->x, pos->z);
									nextvalue = cd_pos_get_dist_to_vtx(nextx, nextz, pos->x, pos->z);

									if (thisvalue < nextvalue) {
#if VERSION >= VERSION_NTSC_1_0
										if (thisvalue < spe4 || hasdie)
#else
										if (thisvalue < spe4)
#endif
										{
											x = tile->vertices[i][0];
											z = tile->vertices[i][2];
											ground = cd_find_y_tilei_vtx(tile, x, z, i);

											if (ground < pos->y || (collision->geo->flags & GEOFLAG_STEP)) {
												curground = ground;
												*collisionptr = collision;
												spe4 = thisvalue;
#if VERSION >= VERSION_NTSC_1_0
												hasground = true;
												hasdie = isdie;
#endif
											}
										}
									} else {
#if VERSION >= VERSION_NTSC_1_0
										if (nextvalue < spe4 || hasdie)
#else
										if (nextvalue < spe4)
#endif
										{
											x = tile->vertices[next][0];
											z = tile->vertices[next][2];
											ground = cd_find_y_tilei_vtx(tile, x, z, i);

											if (ground < pos->y || (collision->geo->flags & GEOFLAG_STEP)) {
												curground = ground;
												*collisionptr = collision;
												spe4 = nextvalue;
#if VERSION >= VERSION_NTSC_1_0
												hasground = true;
												hasdie = isdie;
#endif
											}
										}
									}
								}
							}
						}
					}
				} else if (collision->geo->type == GEOTYPE_TILE_F) {
					struct geotilef *tile = (struct geotilef *) collision->geo;
					s32 numvertices = tile->header.numvertices;
					s32 i;

					for (i = 0; i < numvertices; i++) {
						thisx = tile->vertices[i].x;
						thisz = tile->vertices[i].z;

						next = (i + 1) % numvertices;

						nextx = tile->vertices[next].x;
						nextz = tile->vertices[next].z;

						sp94 = cd_pos_get_dist_to_line(thisx, thisz, nextx, nextz, pos->x, pos->z);
						f30 = sp94;

						if (f30 < 0.0f) {
							f30 = -f30;
						}

						if (f30 < spe4) {
							if (cd_pos_get_side(thisx, thisz, nextx, nextz, pos->x, pos->z)) {
								sp78 = nextx - thisx;
								sp74 = nextz - thisz;
								f14 = sp94 / sqrtf(sp78 * sp78 + sp74 * sp74);
								x = pos->x + f14 * -sp74;
								z = pos->z + f14 * sp78;

								ground = cd_find_y_tilef(tile, x, z);

								if (ground < pos->y) {
									curground = ground;
									*collisionptr = collision;
									spe4 = f30;
#if VERSION >= VERSION_NTSC_1_0
									hasground = true;
									hasdie = false;
#endif
								}
							} else {
								thisvalue = cd_pos_get_dist_to_vtx(thisx, thisz, pos->x, pos->z);
								nextvalue = cd_pos_get_dist_to_vtx(nextx, nextz, pos->x, pos->z);

								if (thisvalue < nextvalue) {
									if (thisvalue < spe4) {
										x = tile->vertices[i].x;
										z = tile->vertices[i].z;
										ground = cd_find_y_tilef(tile, x, z);

										if (ground < pos->y) {
											curground = ground;
											*collisionptr = collision;
											spe4 = thisvalue;
#if VERSION >= VERSION_NTSC_1_0
											hasground = true;
											hasdie = false;
#endif
										}
									}
								} else {
									if (nextvalue < spe4) {
										x = tile->vertices[next].x;
										z = tile->vertices[next].z;
										ground = cd_find_y_tilef(tile, x, z);

										if (ground < pos->y) {
											curground = ground;
											*collisionptr = collision;
											spe4 = nextvalue;
#if VERSION >= VERSION_NTSC_1_0
											hasground = true;
											hasdie = false;
#else
											if (numvertices);
#endif
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return curground;
}

/**
 * Test if the given cylinder is intersecting a tile with the given geoflags.
 * If so, populate the laddernormal argument and return true.
 *
 * There is nothing specific to ladders in this function, but it's only used
 * for finding ladders.
 */
bool cd_find_ladder(struct coord *pos, f32 width, f32 ymax, f32 ymin, RoomNum *rooms, u16 geoflags, struct coord *laddernormal)
{
	struct collision collisions[2];

	cd_volume_collect(pos, width, rooms, CDTYPE_BG, geoflags, CHECKVERTICAL_YES, ymax, ymin, collisions, 1);

	if (collisions[0].geo) {
		struct geotilei *tile = (struct geotilei *) collisions[0].geo;
		struct coord dist;

		cd_get_geo_normal(collisions[0].geo, laddernormal);

		dist.x = pos->x - tile->vertices[0][0];
		dist.y = pos->y - tile->vertices[0][1];
		dist.z = pos->z - tile->vertices[0][2];

		if (dist.f[0] * laddernormal->f[0] + dist.f[1] * laddernormal->f[1] + dist.f[2] * laddernormal->f[2] < 0) {
			laddernormal->x = -laddernormal->x;
			laddernormal->y = -laddernormal->y;
			laddernormal->z = -laddernormal->z;
		}

		return true;
	}

	return false;
}

bool is_cyl_touching_tile_with_flags(struct coord *pos, f32 radius, f32 ymax, f32 ymin, RoomNum *rooms, u16 geoflags)
{
	struct collision collisions[2];

	cd_volume_collect(pos, radius, rooms, CDTYPE_BG, geoflags, CHECKVERTICAL_YES, ymax, ymin, collisions, 1);

	if (collisions[0].geo) {
		return true;
	}

	return false;
}

/**
 * For the following ground/ceiling functions, the suffix on the function name
 * denotes which pointer arguments will be populated by the collision system.
 *
 * c = floor colour
 * f = floor flags (geoflags)
 * i = inlift
 * l = lift
 * n = normal
 * p = prop
 * r = room number
 * t = floor type
 * y = y coordinate
 */

f32 cd_find_ground_at_cyl_ctfril(struct coord *pos, f32 radius, RoomNum *rooms, u16 *floorcol,
		u8 *floortype, u16 *floorflags, RoomNum *floorroom, bool *inlift, struct prop **lift)
{
	struct collision collisions[21];
	struct collision *collision = NULL;
	f32 ground;
	struct geo *geo = NULL;

	cd_volume_collect(pos, radius, rooms, CDTYPE_ALL, GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2, CHECKVERTICAL_NO, 0, 0, collisions, 20);
	ground = cd_find_ground_finalise(collisions, pos, &collision, radius);

	if (collision) {
		geo = collision->geo;
	}

	if (floorcol) {
		cd_get_floor_col(geo, floorcol);
	}

	if (floortype) {
		cd_get_floor_type(geo, floortype);
	}

	if (floorflags && geo) {
		*floorflags = geo->flags;
	}

	if (floorroom) {
		if (collision) {
			*floorroom = collision->room;
		} else {
			*floorroom = -1;
		}
	}

	if (inlift) {
		if (geo && geo->type == GEOTYPE_TILE_F && (geo->flags & GEOFLAG_LIFTFLOOR)) {
			*inlift = true;
			*lift = collision->prop;

			if (*lift && (*lift)->obj->modelnum == MODEL_ESCA_STEP && floortype) {
				*floortype = FLOORTYPE_METAL;
			}
		} else {
			*inlift = false;
			*lift = NULL;
		}
	}

	return ground;
}

/**
 * This function must come immediately after cd_find_ground_at_cyl_ctfril.
 *
 * A piracy check looks for this function, then backtracks two instructions to
 * nop the jr ra at the end of cd_find_ground_at_cyl_ctfril, causing it to flow into this
 * function and return 0.
 */
f32 cd_return_zero(void)
{
	return 0;
}

f32 cd_find_ground_at_cyl_ct(struct coord *pos, f32 radius, RoomNum *rooms, u16 *floorcol, u8 *floortype)
{
	return cd_find_ground_at_cyl_ctfril(pos, radius, rooms, floorcol, floortype, NULL, NULL, NULL, NULL);
}

f32 cd_find_ground_at_pos_ct(struct coord *pos, RoomNum *rooms, u16 *floorcol, u8 *floortype)
{
	struct geo *geo;
	RoomNum room;
	f32 y;
	f32 ground = -4294967296;

	cd_find_y(pos, rooms, GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2, &geo, &room, &y, NULL, SURFACE_FLOOR);

	if (geo) {
		ground = y;
	}

	if (floorcol) {
		cd_get_floor_col(geo, floorcol);
	}

	if (floortype) {
		cd_get_floor_type(geo, floortype);
	}

	return ground;
}

RoomNum cd_find_room_at_pos(struct coord *pos, RoomNum *nearrooms)
{
	struct geo *geo;
	RoomNum room;
	f32 y;

	cd_find_y(pos, nearrooms, GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2, &geo, &room, &y, 0, SURFACE_FLOOR);

	return room;
}

#if VERSION >= VERSION_NTSC_1_0
RoomNum cd_find_room_at_pos_ycf(struct coord *pos, RoomNum *rooms, f32 *yptr, u16 *floorcolptr, u16 *flagsptr)
#else
RoomNum cd_find_room_at_pos_ycf(struct coord *pos, RoomNum *rooms, f32 *yptr, u16 *floorcolptr)
#endif
{
	struct geo *geo;
	RoomNum room;
	f32 y;

	cd_find_y(pos, rooms, GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2, &geo, &room, &y, NULL, SURFACE_FLOOR);

	if (geo != NULL) {
		*yptr = y;
	}

	if (floorcolptr != NULL) {
		cd_get_floor_col(geo, floorcolptr);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (flagsptr != NULL && geo != NULL) {
		*flagsptr = geo->flags;
	}
#endif

	return room;
}

#if VERSION >= VERSION_NTSC_1_0
RoomNum cd_find_ceiling_room_at_pos_ycf(struct coord *pos, RoomNum *rooms, f32 *yptr, u16 *floorcolptr, u16 *flagsptr)
#else
RoomNum cd_find_ceiling_room_at_pos_ycf(struct coord *pos, RoomNum *rooms, f32 *yptr, u16 *floorcolptr)
#endif
{
	struct geo *geo;
	RoomNum room;
	f32 y;

	cd_find_y(pos, rooms, GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2, &geo, &room, &y, NULL, SURFACE_CEILING);

	if (geo != NULL) {
		*yptr = y;
	}

	if (floorcolptr != NULL) {
		cd_get_floor_col(geo, floorcolptr);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (flagsptr != NULL && geo != NULL) {
		*flagsptr = geo->flags;
	}
#endif

	return room;
}

RoomNum cd_find_room_at_pos_ycnp(struct coord *pos, RoomNum *rooms, f32 *yptr, u16 *floorcol, struct coord *normal, struct prop **propptr)
{
	struct geo *geo;
	RoomNum room;
	f32 y;

	cd_find_y(pos, rooms, GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2, &geo, &room, &y, propptr, SURFACE_FLOOR);

	if (geo) {
		*yptr = y;
		cd_get_geo_normal(geo, normal);
	}

	if (floorcol) {
		cd_get_floor_col(geo, floorcol);
	}

	return room;
}

RoomNum cd_find_ceiling_room_at_pos_ycfn(struct coord *pos, RoomNum *rooms, f32 *yptr, u16 *floorcol, u16 *flagsptr, struct coord *normal)
{
	struct geo *geo;
	RoomNum room;
	f32 y;

	cd_find_y(pos, rooms, GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2, &geo, &room, &y, NULL, SURFACE_CEILING);

	if (geo) {
		*yptr = y;
		cd_get_geo_normal(geo, normal);
	}

	if (floorcol) {
		cd_get_floor_col(geo, floorcol);
	}

	if (flagsptr != NULL && geo != NULL) {
		*flagsptr = geo->flags;
	}

	return room;
}

/**
 * Tests if a cylinder volume fits in the given position.
 */
s32 cd_test_volume_simple(struct coord *pos, f32 radius, RoomNum *rooms, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	struct collision collisions[2];
	s32 result = CDRESULT_NOCOLLISION;

	cd_volume_collect(pos, radius, rooms, types, GEOFLAG_WALL, checkvertical, ymax, ymin, collisions, 1);

	if (collisions[0].geo) {
		result = CDRESULT_COLLISION;
		cd_set_obstacle_prop(collisions[0].prop);
	}

	return result;
}

/**
 * Do a volume test at topos. If there are any collisions,
 * find the edge closest to topos. Unless the collision is with a cylinder,
 * in which case the edge facing frompos is used.
 *
 * Saves the obstacle's edge vertices and prop.
 *
 * The function stops once any collision is found, so it's possible that there
 * could be a closer obstacle than the returned edge.
 *
 * Used by:
 * - Chrs being pushed
 * - Chrs navigating around obstacles
 * - Hoverbikes
 * - Player movement with a grabbed object
 */
s32 cd_test_volume_closestedge(struct coord *frompos, struct coord *topos, f32 radius, RoomNum *rooms, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	struct collision collisions[2];
	s32 result;
	struct coord edgevtx1;
	struct coord edgevtx2;

	result = CDRESULT_NOCOLLISION;

	cd_volume_collect(topos, radius, rooms, types, GEOFLAG_WALL, checkvertical, ymax, ymin, collisions, 1);

	if (collisions[0].geo != NULL) {
		result = CDRESULT_COLLISION;

		if (collisions[0].geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *) collisions[0].geo;
			s32 this = collisions[0].vertexindex;
			s32 next = (this + 1) % tile->header.numvertices;

			edgevtx1.x = tile->vertices[this][0];
			edgevtx1.y = tile->vertices[this][1];
			edgevtx1.z = tile->vertices[this][2];

			edgevtx2.x = tile->vertices[next][0];
			edgevtx2.y = tile->vertices[next][1];
			edgevtx2.z = tile->vertices[next][2];
		} else if (collisions[0].geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *) collisions[0].geo;
			s32 this = collisions[0].vertexindex;
			s32 next = (this + 1) % tile->header.numvertices;

			edgevtx1.x = tile->vertices[this].x;
			edgevtx1.y = tile->vertices[this].y;
			edgevtx1.z = tile->vertices[this].z;

			edgevtx2.x = tile->vertices[next].x;
			edgevtx2.y = tile->vertices[next].y;
			edgevtx2.z = tile->vertices[next].z;
		} else if (collisions[0].geo->type == GEOTYPE_BLOCK) {
			struct geoblock *block = (struct geoblock *) collisions[0].geo;
			s32 this = collisions[0].vertexindex;
			s32 next = (this + 1) % block->header.numvertices;

			edgevtx1.x = block->vertices[this][0];
			edgevtx1.y = frompos->y;
			edgevtx1.z = block->vertices[this][1];

			edgevtx2.x = block->vertices[next][0];
			edgevtx2.y = frompos->y;
			edgevtx2.z = block->vertices[next][1];
		} else if (collisions[0].geo->type == GEOTYPE_CYL) {
			struct geocyl *cyl = (struct geocyl *) collisions[0].geo;

			cd_pos_get_cyl_edge(cyl->x, cyl->z, cyl->radius, frompos->x, frompos->z, &edgevtx1.x, &edgevtx1.z, &edgevtx2.x, &edgevtx2.z);

			edgevtx1.y = frompos->y;
			edgevtx2.y = frompos->y;
		}

		cd_set_obstacle_edge_prop(&edgevtx1, &edgevtx2, collisions[0].prop);
	}

	return result;
}

/**
 * Do a volume test at topos. If there are any collisions,
 * find the edge of the closest object in the direction of frompos.
 *
 * Saves the obstacle's edge vertices, prop and distance.
 *
 * Used by:
 * - Player movement when walking
 * - Player movement when on hoverbike
 * - Player movement when using eyespy
 * - Projectiles
 */
s32 cd_test_volume_fromdir(struct coord *frompos, struct coord *topos, f32 radius, RoomNum *dstrooms, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	struct collision collisions[21];
	struct coord dist;
	s32 result = CDRESULT_NOCOLLISION;

	cd_volumefromdir_collect(topos, radius, dstrooms, types, GEOFLAG_WALL, checkvertical, ymax, ymin, collisions, 20);

	if (collisions[0].geo) {
		result = CDRESULT_COLLISION;

		dist.x = topos->x - frompos->x;
		dist.y = topos->y - frompos->y;
		dist.z = topos->z - frompos->z;

		cd_volumefromdir_finalise(frompos, &dist, radius, collisions);
	}

	return result;
}

bool cd_is_line_intersecting_tilei(struct coord *frompos, struct coord *topos, struct coord *dist, struct geotilei *tile, struct coord *endpos, struct coord *arg5)
{
	s32 i;
	u8 numvertices = tile->header.numvertices;

	for (i = 2; i < numvertices; i++) {
		if (func0002f490((struct vec3s16 *)&tile->vertices[0][0],
					(struct vec3s16 *)&tile->vertices[i - 1][0],
					(struct vec3s16 *)&tile->vertices[i][0],
					NULL, frompos, topos, dist, endpos, arg5)) {
			return true;
		}
	}

	return false;
}

bool cd_is_line_intersecting_tilef(struct coord *frompos, struct coord *topos, struct coord *dist, struct geotilef *tile, struct coord *endpos, struct coord *arg5)
{
	s32 i;
	u8 numvertices = tile->header.numvertices;

	for (i = 2; i < numvertices; i++) {
		if (func0002f560(&tile->vertices[0], &tile->vertices[i - 1], &tile->vertices[i],
					NULL, frompos, topos, dist, endpos, arg5)) {
			return true;
		}
	}

	return false;
}

bool cd_is_cylpath_intersecting_tilei(struct coord *frompos, struct coord *topos, struct coord *dist, struct geotilei *tile,
		struct coord *endpos, struct coord *edgevtx1, struct coord *edgevtx2, bool checkvertical, f32 cylymax, f32 cylymin)
{
	bool result = false;
	s32 i;
	f32 distfrac;
	s32 numvertices = tile->header.numvertices;
	s32 next;
	bool spb8 = true;
	f32 bestdistfrac = 1.0f;
	s32 bestvtx;
	f32 y2;
	f32 y1;
	f32 tileymax = *(s16 *)(tile->ymax + (uintptr_t)tile);
	f32 tileymin = *(s16 *)(tile->ymin + (uintptr_t)tile);
	f32 fromxz[2];
	f32 toxz[2];
	f32 vtx1xz[2];
	f32 vtx2xz[2];

	if (!checkvertical
			|| (frompos->y + cylymax >= tileymin && topos->y + cylymin <= tileymax)
			|| (frompos->y + cylymin <= tileymax && topos->y + cylymax >= tileymin)) {
		for (i = 0; i < numvertices; i++) {
			next = (i + 1) % numvertices;

			if (cd_000254d8(frompos, topos, tile->vertices[i][0], tile->vertices[i][2], tile->vertices[next][0], tile->vertices[next][2], &spb8)) {
				fromxz[0] = frompos->x;
				fromxz[1] = frompos->z;
				toxz[0] = topos->x;
				toxz[1] = topos->z;
				vtx1xz[0] = tile->vertices[i][0];
				vtx1xz[1] = tile->vertices[i][2];
				vtx2xz[0] = tile->vertices[next][0];
				vtx2xz[1] = tile->vertices[next][2];

				distfrac = func0f1577f0(fromxz, toxz, vtx1xz, vtx2xz);

				if (distfrac < bestdistfrac) {
					if (checkvertical) {
						y1 = frompos->f[1] + (topos->f[1] - frompos->f[1]) * distfrac;
						y2 = y1 + cylymax;
						y1 = y1 + cylymin;
					}

					if (!checkvertical || !(y1 >= tileymax || y2 <= tileymin)) {
						result = true;
						bestdistfrac = distfrac;
						bestvtx = i;
					}
				}
			}
		}

		if (result) {
			endpos->x = frompos->x + dist->f[0] * bestdistfrac;
			endpos->y = frompos->y + dist->f[1] * bestdistfrac;
			endpos->z = frompos->z + dist->f[2] * bestdistfrac;

			if (edgevtx1 != NULL && edgevtx2 != NULL) {
				edgevtx1->x = tile->vertices[bestvtx][0];
				edgevtx1->y = endpos->y;
				edgevtx1->z = tile->vertices[bestvtx][2];

				edgevtx2->x = tile->vertices[(bestvtx + 1) % numvertices][0];
				edgevtx2->y = endpos->y;
				edgevtx2->z = tile->vertices[(bestvtx + 1) % numvertices][2];
			}
		} else if (!result && spb8) {
			result = true;

			endpos->x = frompos->x;
			endpos->y = frompos->y;
			endpos->z = frompos->z;

			if (edgevtx1 != NULL && edgevtx2 != NULL) {
				edgevtx1->x = frompos->x;
				edgevtx1->y = frompos->y;
				edgevtx1->z = frompos->z;

				edgevtx2->x = frompos->x;
				edgevtx2->y = frompos->y;
				edgevtx2->z = frompos->z;
			}
		}
	}

	return result;
}

bool cd_is_cylpath_intersecting_tilef(struct coord *frompos, struct coord *topos, struct coord *dist, struct geotilef *tile,
		struct coord *endpos, struct coord *edgevtx1, struct coord *edgevtx2, bool checkvertical, f32 cylymax, f32 cylymin)
{
	bool result = false;
	s32 i;
	f32 distfrac;
	s32 numvertices = tile->header.numvertices;
	s32 next;
	bool spb8 = true;
	f32 bestdistfrac = 1.0f;
	s32 bestvtx;
	f32 y2;
	f32 y1;
	f32 tileymax = tile->vertices[tile->max[1]].y;
	f32 tileymin = tile->vertices[tile->min[1]].y;
	f32 fromxz[2];
	f32 toxz[2];
	f32 vtx1xz[2];
	f32 vtx2xz[2];

	if (!checkvertical
			|| (frompos->y + cylymax >= tileymin && topos->y + cylymin <= tileymax)
			|| (frompos->y + cylymin <= tileymax && topos->y + cylymax >= tileymin)) {
		for (i = 0; i < numvertices; i++) {
			next = (i + 1) % numvertices;

			if (cd_000254d8(frompos, topos, tile->vertices[i].x, tile->vertices[i].z, tile->vertices[next].x, tile->vertices[next].z, &spb8)) {
				fromxz[0] = frompos->x;
				fromxz[1] = frompos->z;
				toxz[0] = topos->x;
				toxz[1] = topos->z;
				vtx1xz[0] = tile->vertices[i].x;
				vtx1xz[1] = tile->vertices[i].z;
				vtx2xz[0] = tile->vertices[next].x;
				vtx2xz[1] = tile->vertices[next].z;

				distfrac = func0f1577f0(fromxz, toxz, vtx1xz, vtx2xz);

				if (distfrac < bestdistfrac) {
					if (checkvertical) {
						y1 = frompos->f[1] + (topos->f[1] - frompos->f[1]) * distfrac;
						y2 = y1 + cylymax;
						y1 = y1 + cylymin;
					}

					if (!checkvertical || !(y1 >= tileymax || y2 <= tileymin)) {
						result = true;
						bestdistfrac = distfrac;
						bestvtx = i;
					}
				}
			}
		}

		if (result) {
			endpos->x = frompos->x + dist->f[0] * bestdistfrac;
			endpos->y = frompos->y + dist->f[1] * bestdistfrac;
			endpos->z = frompos->z + dist->f[2] * bestdistfrac;

			if (edgevtx1 != NULL && edgevtx2 != NULL) {
				edgevtx1->x = tile->vertices[bestvtx].x;
				edgevtx1->y = endpos->y;
				edgevtx1->z = tile->vertices[bestvtx].z;

				edgevtx2->x = tile->vertices[(bestvtx + 1) % numvertices].x;
				edgevtx2->y = endpos->y;
				edgevtx2->z = tile->vertices[(bestvtx + 1) % numvertices].z;
			}
		} else if (!result && spb8) {
			result = true;

			endpos->x = frompos->x;
			endpos->y = frompos->y;
			endpos->z = frompos->z;

			if (edgevtx1 != NULL && edgevtx2 != NULL) {
				edgevtx1->x = frompos->x;
				edgevtx1->y = frompos->y;
				edgevtx1->z = frompos->z;

				edgevtx2->x = frompos->x;
				edgevtx2->y = frompos->y;
				edgevtx2->z = frompos->z;
			}
		}
	}

	return result;
}

bool cd_is_cylpath_intersecting_block(struct coord *frompos, struct coord *topos, struct coord *dist, struct geoblock *block,
		struct coord *endpos, struct coord *edgevtx1, struct coord *edgevtx2, bool checkvertical, f32 cylymax, f32 cylymin)
{
	bool result = false;
	s32 i;
	f32 distfrac;
	s32 numvertices = block->header.numvertices;
	s32 next;
	bool spb8 = true;
	f32 bestdistfrac = 1.0f;
	s32 bestvtx;
	f32 y2;
	f32 y1;
	f32 fromxz[2];
	f32 toxz[2];
	f32 vtx1xz[2];
	f32 vtx2xz[2];

	if (!checkvertical
			|| (frompos->y + cylymax >= block->ymin && topos->y + cylymin <= block->ymax)
			|| (frompos->y + cylymin <= block->ymax && topos->y + cylymax >= block->ymin)) {
		for (i = 0; i < numvertices; i++) {
			next = (i + 1) % numvertices;

			if (cd_000254d8(frompos, topos, block->vertices[i][0], block->vertices[i][1], block->vertices[next][0], block->vertices[next][1], &spb8)) {
				fromxz[0] = frompos->x;
				fromxz[1] = frompos->z;
				toxz[0] = topos->x;
				toxz[1] = topos->z;
				vtx1xz[0] = block->vertices[i][0];
				vtx1xz[1] = block->vertices[i][1];
				vtx2xz[0] = block->vertices[next][0];
				vtx2xz[1] = block->vertices[next][1];

				distfrac = func0f1577f0(fromxz, toxz, vtx1xz, vtx2xz);

				if (distfrac < bestdistfrac) {
					if (checkvertical) {
						y1 = (topos->y - frompos->y) * distfrac + frompos->y;
						y2 = y1 + cylymax;
						y1 = y1 + cylymin;
					}

					if (!checkvertical || (!(y1 >= block->ymax) && !(y2 <= block->ymin))) {
						result = true;
						bestdistfrac = distfrac;
						bestvtx = i;
					}
				}
			}
		}

		if (result) {
			endpos->x = frompos->x + dist->f[0] * bestdistfrac;
			endpos->y = frompos->y + dist->f[1] * bestdistfrac;
			endpos->z = frompos->z + dist->f[2] * bestdistfrac;

			if (edgevtx1 != NULL && edgevtx2 != NULL) {
				edgevtx1->x = block->vertices[bestvtx][0];
				edgevtx1->y = endpos->y;
				edgevtx1->z = block->vertices[bestvtx][1];

				edgevtx2->x = block->vertices[(bestvtx + 1) % numvertices][0];
				edgevtx2->y = endpos->y;
				edgevtx2->z = block->vertices[(bestvtx + 1) % numvertices][1];
			}
		} else if (!result && spb8) {
			result = true;

			endpos->x = frompos->x;
			endpos->y = frompos->y;
			endpos->z = frompos->z;

			if (edgevtx1 != NULL && edgevtx2 != NULL) {
				edgevtx1->x = frompos->x;
				edgevtx1->y = frompos->y;
				edgevtx1->z = frompos->z;

				edgevtx2->x = frompos->x;
				edgevtx2->y = frompos->y;
				edgevtx2->z = frompos->z;
			}
		}
	}

	return result;
}

bool cd_is_cylpath_intersecting_cyl(struct coord *frompos, struct coord *topos, struct coord *dist, struct geocyl *cyl,
		struct coord *endpos, struct coord *edgevtx1, struct coord *edgevtx2, bool checkvertical, f32 ymax, f32 ymin)
{
	bool result = false;
	f32 mult;
	f32 sp74;
	f32 x = cyl->x;
	f32 z = cyl->z;
	f32 radius = cyl->radius;

	if (!checkvertical
			|| (frompos->y + ymax >= cyl->ymin && topos->y + ymin <= cyl->ymax)
			|| (frompos->y + ymin <= cyl->ymax && topos->y + ymax >= cyl->ymin)) {
		sp74 = cd_pos_get_dist_to_line(frompos->x, frompos->z, topos->x, topos->z, x, z);

		if (sp74 < 0.0f) {
			sp74 = -sp74;
		}

		if (sp74 < radius
				&& (cd_pos_get_dist_to_vtx(frompos->x, frompos->z, x, z) < radius
					|| cd_pos_get_dist_to_vtx(topos->x, topos->z, x, z) < radius
					|| cd_pos_get_side(frompos->x, frompos->z, topos->x, topos->z, x, z))) {
			f32 xdiff = topos->x - frompos->x;
			f32 zdiff = topos->z - frompos->z;
			f32 sqdist;
			f32 distance;
			u32 stack;
			f32 sp50;
			f32 sp4c;
			f32 sp48;

			sp50 = sqrtf(xdiff * xdiff + zdiff * zdiff);

			if (sp50 > 0.0f) {
				xdiff = x - frompos->x;
				zdiff = z - frompos->z;

				sqdist = xdiff * xdiff + zdiff * zdiff;

				if (sp74 * sp74 <= sqdist) {
					distance = sqrtf(sqdist - sp74 * sp74) - sqrtf(radius * radius - sp74 * sp74);
				} else {
					distance = 0.0f;
				}

				mult = distance / sp50;
			} else {
				mult = 0.0f;
			}

			if (mult < 1.0f) {
				if (checkvertical) {
					sp48 = (topos->y - frompos->y) * mult + frompos->y;
					sp4c = sp48 + ymax;
					sp48 = sp48 + ymin;
				}

				if (!checkvertical || (!(sp48 >= cyl->ymax) && !(sp4c <= cyl->ymin))) {
					result = true;

					endpos->x = frompos->x + dist->f[0] * mult;
					endpos->y = frompos->y + dist->f[1] * mult;
					endpos->z = frompos->z + dist->f[2] * mult;

					if (edgevtx1 != NULL && edgevtx2 != NULL) {
						cd_pos_get_cyl_edge(x, z, radius, frompos->x, frompos->z, &edgevtx1->x, &edgevtx1->z, &edgevtx2->x, &edgevtx2->z);

						edgevtx1->y = endpos->y;
						edgevtx2->y = endpos->y;
					}
				}
			}
		}
	}

	return result;
}

bool cd_test_atobany_from_bytes(u8 *start, u8 *end, struct coord *frompos, struct coord *topos, struct coord *dist, u16 geoflags, bool islos, bool checkvertical, f32 ymax, f32 ymin)
{
	struct geo *geo = (struct geo *) start;

	while (geo < (struct geo *) end) {
		if (geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *) geo;
			struct coord min;
			struct coord max;
			struct coord endpos;
			struct coord spb8;

			if (tile->header.flags & geoflags) {
				min.x = *(s16 *)(tile->xmin + (uintptr_t)tile);

				if ((!(frompos->x < min.x)) || !(topos->x < min.x)) {
					max.x = *(s16 *)(tile->xmax + (uintptr_t)tile);

					if ((!(frompos->x > max.x)) || !(topos->x > max.x)) {
						min.z = *(s16 *)(tile->zmin + (uintptr_t)tile);

						if ((!(frompos->z < min.z)) || !(topos->z < min.z)) {
							max.z = *(s16 *)(tile->zmax + (uintptr_t)tile);

							if ((!(frompos->z > max.z)) || !(topos->z > max.z)) {
								if (1);
								if (islos) {
									min.y = *(s16 *)(tile->ymin + (uintptr_t)tile);
									max.y = *(s16 *)(tile->ymax + (uintptr_t)tile);

									if ((!(frompos->y < min.y) || !(topos->y < min.y))
											&& (!(frompos->y > max.y) || !(topos->y > max.y))
											&& bg_test_line_intersects_bbox(frompos, dist, &min, &max)
											&& cd_is_line_intersecting_tilei(frompos, topos, dist, tile, &endpos, &spb8)) {
										return false;
									}
								} else {
									if (cd_is_cylpath_intersecting_tilei(frompos, topos, dist, tile, &endpos, NULL, NULL, checkvertical, ymax, ymin)) {
										return false;
									}
								}
							}
						}
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOTILEI_SIZE(tile));
		} else if (geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *) geo;
			struct coord min;
			struct coord max;
			struct coord sp90;
			struct coord sp84;

			if (tile->header.flags & geoflags) {
				min.x = tile->vertices[tile->min[0]].x;
				max.x = tile->vertices[tile->max[0]].x;
				min.z = tile->vertices[tile->min[2]].z;
				max.z = tile->vertices[tile->max[2]].z;

				if (((!(frompos->x < min.x)) || !(topos->x < min.x))
						&& (!(frompos->x > max.x) || !(topos->x > max.x))
						&& ((!(frompos->z < min.z)) || !(topos->z < min.z))
						&& (!(frompos->z > max.z) || !(topos->z > max.z))) {
					if (islos) {
						min.y = tile->vertices[tile->min[1]].y;
						max.y = tile->vertices[tile->max[1]].y;

						if ((!(frompos->y < min.y) || !(topos->y < min.y))
								&& (!(frompos->y > max.y) || !(topos->y > max.y))
								&& bg_test_line_intersects_bbox(frompos, dist, &min, &max)
								&& cd_is_line_intersecting_tilef(frompos, topos, dist, tile, &sp90, &sp84)) {
							return false;
						}
					} else {
						if (cd_is_cylpath_intersecting_tilef(frompos, topos, dist, tile, &sp90, 0, 0, checkvertical, ymax, ymin)) {
							return false;
						}
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOTILEF_SIZE(tile));
		} else if (geo->type == GEOTYPE_BLOCK) {
			struct coord sp78;
			struct geoblock *block = (struct geoblock *) geo;

			if ((geoflags & (GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT))
					&& cd_is_cylpath_intersecting_block(frompos, topos, dist, block, &sp78, 0, 0, checkvertical, ymax, ymin)) {
				return false;
			}

			geo = (struct geo *)((uintptr_t)geo + GEOBLOCK_SIZE(block));
		} else if (geo->type == GEOTYPE_CYL) {
			struct coord sp68;
			struct geocyl *cyl = (struct geocyl *) geo;

			if ((geoflags & cyl->header.flags)
					&& cd_is_cylpath_intersecting_cyl(frompos, topos, dist, cyl, &sp68, 0, 0, checkvertical, ymax, ymin)) {
				return false;
			}

			geo = (struct geo *)((uintptr_t)geo + GEOCYL_SIZE(cyl));
		}
	}

	return true;
}

void cd_test_atobclosest_findedge_tilei(struct geotilei *tile, struct coord *endpos, struct coord *arg2, struct coord *edgevtx1, struct coord *edgevtx2)
{
	struct coord sp3c;
	u32 stack[2];
	u8 numvertices;
	f32 max = 0.0f;
	f32 min = 0.0f;
	f32 dist;
	s32 i;

	if (arg2->x != 0.0f || arg2->z != 0.0f) {
		sp3c.x = arg2->z;
		sp3c.y = 0.0f;
		sp3c.z = -arg2->x;

		dist = sqrtf(sp3c.f[0] * sp3c.f[0] + sp3c.f[2] * sp3c.f[2]);

		if (dist > 0.0f) {
			sp3c.x *= 1.0f / dist;
			sp3c.z *= 1.0f / dist;
		} else {
			sp3c.x = 0.0f;
			sp3c.y = 0.0f;
			sp3c.z = 1.0f;
		}
	} else {
		sp3c.x = 0.0f;
		sp3c.y = 0.0f;
		sp3c.z = 1.0f;
	}

	numvertices = tile->header.numvertices;

	for (i = 0; i < numvertices; i++) {
		f32 xdiff = tile->vertices[i][0] - endpos->x;
		f32 zdiff = tile->vertices[i][2] - endpos->z;
		f32 f0 = xdiff * sp3c.f[0] + zdiff * sp3c.f[2];

		if (f0 > max) {
			max = f0;
		} else if (f0 < min) {
			min = f0;
		}
	}

	edgevtx1->x = endpos->x + sp3c.f[0] * max;
	edgevtx1->y = endpos->y;
	edgevtx1->z = endpos->z + sp3c.f[2] * max;

	edgevtx2->x = endpos->x + sp3c.f[0] * min;
	edgevtx2->y = endpos->y;
	edgevtx2->z = endpos->z + sp3c.f[2] * min;
}

void cd_test_atobclosest_findedge_tilef(struct geotilef *tile, struct coord *endpos, struct coord *arg2, struct coord *edgevtx1, struct coord *edgevtx2)
{
	struct coord sp3c;
	u32 stack[2];
	u8 numvertices;
	f32 max = 0.0f;
	f32 min = 0.0f;
	f32 dist;
	s32 i;

	if (arg2->x != 0.0f || arg2->z != 0.0f) {
		sp3c.x = arg2->z;
		sp3c.y = 0.0f;
		sp3c.z = -arg2->x;

		dist = sqrtf(sp3c.f[0] * sp3c.f[0] + sp3c.f[2] * sp3c.f[2]);

		if (dist > 0.0f) {
			sp3c.x *= 1.0f / dist;
			sp3c.z *= 1.0f / dist;
		} else {
			sp3c.x = 0.0f;
			sp3c.y = 0.0f;
			sp3c.z = 1.0f;
		}
	} else {
		sp3c.x = 0.0f;
		sp3c.y = 0.0f;
		sp3c.z = 1.0f;
	}

	numvertices = tile->header.numvertices;

	for (i = 0; i < numvertices; i++) {
		f32 xdiff = tile->vertices[i].x - endpos->x;
		f32 zdiff = tile->vertices[i].z - endpos->z;
		f32 f0 = xdiff * sp3c.f[0] + zdiff * sp3c.f[2];

		if (f0 > max) {
			max = f0;
		} else if (f0 < min) {
			min = f0;
		}
	}

	edgevtx1->x = endpos->x + sp3c.f[0] * max;
	edgevtx1->y = endpos->y;
	edgevtx1->z = endpos->z + sp3c.f[2] * max;

	edgevtx2->x = endpos->x + sp3c.f[0] * min;
	edgevtx2->y = endpos->y;
	edgevtx2->z = endpos->z + sp3c.f[2] * min;
}

bool cd_test_atobclosest_from_bytes(u8 *start, u8 *end, struct coord *frompos, struct coord *topos, struct coord *dist,
		u16 geoflags, bool islos, bool checkvertical, f32 ymax, f32 ymin, f32 *closestsqdist, struct coord *closestendpos,
		struct coord *closestedgevtx1, struct coord *closestedgevtx2, struct geo **closestgeo, s32 roomnum)
{
	struct geo *geo;
	f32 x;
	f32 y;
	f32 z;
	f32 sqdist;
	bool ok;
	bool result = false;

	geo = (struct geo *) start;

	while (geo < (struct geo *) end) {
		if (geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *) geo;
			struct coord min;
			struct coord max;
			struct coord endpos;
			struct coord sp120;
			struct coord edgevtx1;
			struct coord edgevtx2;

			if (geo->flags & GEOFLAG_RAMPWALL) {
				ok = cd_test_ramp_wall(tile, frompos, 0, frompos->y + ymin, frompos->y + ymax);
			} else {
				ok = true;
			}

			if (ok && (geo->flags & geoflags)) {
				min.x = *(s16 *)(tile->xmin + (uintptr_t)tile);

				if (!(frompos->x < min.x) || !(topos->x < min.x)) {
					max.x = *(s16 *)(tile->xmax + (uintptr_t)tile);

					if (!(frompos->x > max.x) || !(topos->x > max.x)) {
						min.z = *(s16 *)(tile->zmin + (uintptr_t)tile);

						if (!(frompos->z < min.z) || !(topos->z < min.z)) {
							max.z = *(s16 *)(tile->zmax + (uintptr_t)tile);

							if (!(frompos->z > max.z) || !(topos->z > max.z)) {
								if (islos) {
									min.y = *(s16 *)(tile->ymin + (uintptr_t)tile);
									max.y = *(s16 *)(tile->ymax + (uintptr_t)tile);

									if ((!(frompos->y < min.y) || !(topos->y < min.y))
											&& (!(frompos->y > max.y) || !(topos->y > max.y))
											&& bg_test_line_intersects_bbox(frompos, dist, &min, &max)
											&& cd_is_line_intersecting_tilei(frompos, topos, dist, tile, &endpos, &sp120)) {
										x = endpos.x - frompos->x;
										y = endpos.y - frompos->y;
										z = endpos.z - frompos->z;

										sqdist = x * x + y * y + z * z;

										if (sqdist < *closestsqdist) {
											result = true;
											*closestsqdist = sqdist;

											closestendpos->x = endpos.x;
											closestendpos->y = endpos.y;
											closestendpos->z = endpos.z;

											cd_test_atobclosest_findedge_tilei(tile, &endpos, &sp120, closestedgevtx1, closestedgevtx2);

											*closestgeo = geo;
										}
									}
								} else if (cd_is_cylpath_intersecting_tilei(frompos, topos, dist, tile, &endpos, &edgevtx1, &edgevtx2, checkvertical, ymax, ymin)) {
									x = endpos.x - frompos->x;
									y = endpos.y - frompos->y;
									z = endpos.z - frompos->z;

									sqdist = x * x + y * y + z * z;

									if (sqdist < *closestsqdist) {
										result = true;
										*closestsqdist = sqdist;

										closestendpos->x = endpos.x;
										closestendpos->y = endpos.y;
										closestendpos->z = endpos.z;

										closestedgevtx1->x = edgevtx1.x;
										closestedgevtx1->y = edgevtx1.y;
										closestedgevtx1->z = edgevtx1.z;

										closestedgevtx2->x = edgevtx2.x;
										closestedgevtx2->y = edgevtx2.y;
										closestedgevtx2->z = edgevtx2.z;

										*closestgeo = geo;
									}
								}
							}
						}
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOTILEI_SIZE(tile));
		} else if (geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *) geo;
			struct coord min;
			struct coord max;
			struct coord endpos;
			struct coord spd4;
			struct coord edgevtx1;
			struct coord edgevtx2;

			if (geo->flags & geoflags) {
				min.x = tile->vertices[tile->min[0]].x;
				max.x = tile->vertices[tile->max[0]].x;
				min.z = tile->vertices[tile->min[2]].z;
				max.z = tile->vertices[tile->max[2]].z;

				if ((!(frompos->x < min.x) || !(topos->x < min.x))
						&& (!(frompos->x > max.x) || !(topos->x > max.x))
						&& (!(frompos->z < min.z) || !(topos->z < min.z))
						&& (!(frompos->z > max.z) || !(topos->z > max.z))) {
					if (islos) {
						min.y = tile->vertices[tile->min[1]].y;
						max.y = tile->vertices[tile->max[1]].y;

						if ((!(frompos->y < min.y) || !(topos->y < min.y))
								&& (!(frompos->y > max.y) || !(topos->y > max.y))
								&& bg_test_line_intersects_bbox(frompos, dist, &min, &max)
								&& cd_is_line_intersecting_tilef(frompos, topos, dist, tile, &endpos, &spd4)) {
							x = endpos.x - frompos->x;
							y = endpos.y - frompos->y;
							z = endpos.z - frompos->z;

							sqdist = x * x + y * y + z * z;

							if (sqdist < *closestsqdist) {
								result = true;
								*closestsqdist = sqdist;

								closestendpos->x = endpos.x;
								closestendpos->y = endpos.y;
								closestendpos->z = endpos.z;

								cd_test_atobclosest_findedge_tilef(tile, &endpos, &spd4, closestedgevtx1, closestedgevtx2);

								*closestgeo = geo;
							}
						}
					} else if (cd_is_cylpath_intersecting_tilef(frompos, topos, dist, tile, &endpos, &edgevtx1, &edgevtx2, checkvertical, ymax, ymin)) {
						x = endpos.x - frompos->x;
						y = endpos.y - frompos->y;
						z = endpos.z - frompos->z;

						sqdist = x * x + y * y + z * z;

						if (sqdist < *closestsqdist) {
							result = true;
							*closestsqdist = sqdist;

							closestendpos->x = endpos.x;
							closestendpos->y = endpos.y;
							closestendpos->z = endpos.z;

							closestedgevtx1->x = edgevtx1.x;
							closestedgevtx1->y = edgevtx1.y;
							closestedgevtx1->z = edgevtx1.z;

							closestedgevtx2->x = edgevtx2.x;
							closestedgevtx2->y = edgevtx2.y;
							closestedgevtx2->z = edgevtx2.z;

							*closestgeo = geo;
						}
					}
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOTILEF_SIZE(tile));
		} else if (geo->type == GEOTYPE_BLOCK) {
			struct coord endpos;
			struct coord edgevtx1;
			struct coord edgevtx2;

			if ((geoflags & (GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT))
					&& (cd_is_cylpath_intersecting_block(frompos, topos, dist, (struct geoblock *)geo, &endpos, &edgevtx1, &edgevtx2, checkvertical, ymax, ymin))) {
				x = endpos.x - frompos->x;
				y = endpos.y - frompos->y;
				z = endpos.z - frompos->z;

				sqdist = x * x + y * y + z * z;

				if (sqdist < *closestsqdist) {
					result = true;
					*closestsqdist = sqdist;

					closestendpos->x = endpos.x;
					closestendpos->y = endpos.y;
					closestendpos->z = endpos.z;

					closestedgevtx1->x = edgevtx1.x;
					closestedgevtx1->y = edgevtx1.y;
					closestedgevtx1->z = edgevtx1.z;

					closestedgevtx2->x = edgevtx2.x;
					closestedgevtx2->y = edgevtx2.y;
					closestedgevtx2->z = edgevtx2.z;

					*closestgeo = geo;
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOBLOCK_SIZE(geo));
		} else if (geo->type == GEOTYPE_CYL) {
			struct geocyl *cyl = (struct geocyl *) geo;
			struct coord endpos;
			struct coord edgevtx1;
			struct coord edgevtx2;

			if ((geoflags & geo->flags)
					&& cd_is_cylpath_intersecting_cyl(frompos, topos, dist, cyl, &endpos, &edgevtx1, &edgevtx2, checkvertical, ymax, ymin)) {
				x = endpos.x - frompos->x;
				y = endpos.y - frompos->y;
				z = endpos.z - frompos->z;

				sqdist = x * x + y * y + z * z;

				if (sqdist < *closestsqdist) {
					result = true;
					*closestsqdist = sqdist;

					closestendpos->x = endpos.x;
					closestendpos->y = endpos.y;
					closestendpos->z = endpos.z;

					closestedgevtx1->x = edgevtx1.x;
					closestedgevtx1->y = edgevtx1.y;
					closestedgevtx1->z = edgevtx1.z;

					closestedgevtx2->x = edgevtx2.x;
					closestedgevtx2->y = edgevtx2.y;
					closestedgevtx2->z = edgevtx2.z;

					*closestgeo = geo;
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOCYL_SIZE(cyl));
		}
	}

	return !result;
}

/**
 * Do an A to B test, stopping once any obstacle is found. The obstacle may not
 * be the closest one.
 *
 * If islos is true, the test is a line of sight test which means the checkvertical,
 * ymax and ymin arguments will be ignored (LOS tests always check vertical).
 *
 * If islos is false, the test is a cylinder move test. The cylinder radius not
 * checked or even passed to this function, so the radius is effectively almost 0.
 * The caller may set checkvertical to true if they want Y values compared.
 */
bool cd_test_atobany(struct coord *frompos, struct coord *topos, RoomNum *throughrooms, u32 types, u16 geoflags, bool islos, bool checkvertical, f32 ymax, f32 ymin)
{
	s32 roomnum;
	RoomNum *roomptr;
	u8 *start;
	u8 *end;
	struct coord dist;
	s16 *propnumptr;
	s16 propnums[256];

	dist.x = topos->x - frompos->x;
	dist.y = topos->y - frompos->y;
	dist.z = topos->z - frompos->z;

	// Check BG
	if (types & CDTYPE_BG) {
		roomptr = throughrooms;
		roomnum = throughrooms[0];

		while (roomnum != -1) {
			if (roomnum < g_TileNumRooms) {
				start = g_TileFileData.u8 + g_TileRooms[roomnum];
				end = g_TileFileData.u8 + g_TileRooms[roomnum + 1];

				if (cd_test_atobany_from_bytes(start, end, frompos, topos, &dist, geoflags, islos, checkvertical, ymax, ymin) == 0) {
					cd_set_obstacle_prop(NULL);
					return false;
				}
			}

			roomptr++;
			roomnum = *roomptr;
		}
	}

	// Check props
	room_get_props(throughrooms, propnums, 256);

	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop_is_of_cd_type(prop, types)
				&& prop_get_geometry(prop, &start, &end)
				&& cd_test_atobany_from_bytes(start, end, frompos, topos, &dist, geoflags, islos, checkvertical, ymax, ymin) == 0) {
			cd_set_obstacle_prop(prop);
			return false;
		}

		propnumptr++;
	}

	return true;
}

/**
 * Do an A to B test, finding the closest obstacle and information about it so
 * the caller can query it afterwards.
 *
 * If islos is true, the test is a line of sight test which means the checkvertical,
 * ymax and ymin arguments will be ignored (LOS tests always check vertical).
 *
 * If islos is false, the test is a cylinder move test. The cylinder radius not
 * checked or even passed to this function, so the radius is effectively almost 0.
 * The caller may set checkvertical to true if they want Y values compared.
 */
s32 cd_test_atobclosest(struct coord *frompos, struct coord *topos, RoomNum *rooms, u32 types, u16 geoflags, bool islos, bool checkvertical, f32 ymax, f32 ymin)
{
	s32 roomnum;
	RoomNum *roomptr;
	u8 *start;
	u8 *end;
	struct coord dist;
	bool result = false;
	struct coord endpos;
	struct coord edgevtx1;
	struct coord edgevtx2;
	f32 sqdist = 4294967296;
	struct geo *geo;
	s16 *propnumptr;
	s16 propnums[256];

	dist.x = topos->x - frompos->x;
	dist.y = topos->y - frompos->y;
	dist.z = topos->z - frompos->z;

	// Check BG
	if (types & CDTYPE_BG) {
		roomptr = rooms;
		roomnum = rooms[0];

		while (roomnum != -1) {
			if (roomnum < g_TileNumRooms) {
				u32 *ptr = &g_TileRooms[roomnum];
				start = g_TileFileData.u8 + ptr[0];
				end = g_TileFileData.u8 + ptr[1];

				if (!cd_test_atobclosest_from_bytes(start, end, frompos, topos, &dist, geoflags, islos, checkvertical, ymax, ymin,
							&sqdist, &endpos, &edgevtx1, &edgevtx2, &geo, roomnum)) {
					result = true;
					cd_set_obstacle_edge_pos_prop_sqdist_geo(&edgevtx1, &edgevtx2, &endpos, NULL, sqdist, geo);
				}
			}

			roomptr++;
			roomnum = *roomptr;
		}
	}

	// Check props
	room_get_props(rooms, propnums, 256);
	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop_is_of_cd_type(prop, types)
				&& prop_get_geometry(prop, &start, &end)
				&& !cd_test_atobclosest_from_bytes(start, end, frompos, topos, &dist, geoflags, islos, checkvertical, ymax, ymin,
					&sqdist, &endpos, &edgevtx1, &edgevtx2, &geo, -999)) {
			result = true;
			cd_set_obstacle_edge_pos_prop_sqdist_geo(&edgevtx1, &edgevtx2, &endpos, prop, sqdist, geo);
		}

		propnumptr++;
	}

	return !result;
}

/**
 * Naming conventions for cylmove and los functions:
 *
 * oobok/oobfail:
 *   - Denotes what the function does if topos is out of bounds
 *     and no collisions were found matching the criteria.
 *     If oobok, the function will return CDRESULT_NOCOLLISION.
 *     If oobfail, the function will return CDRESULT_COLLISION.
 *
 * findclosest:
 *   - The function will examines all collisions and find the closest one,
 *     instead of stopping once any collision is found.
 *
 * getfinalroom:
 *   - The function has a finalrooms pointer argument which will be populated
 *     with the final rooms that topos is in. Usually just one room and a -1 terminator.
 *
 * finddist:
 *   - The function will find the distance to the obstacle and save it,
 *     allowing the caller to read it by calling cd_get_distance().
 *
 * autoflags:
 *   - The collision system will use the flags GEOFLAG_WALL, GEOFLAG_BLOCK_SHOOT
 *     and GEOFLAG_BLOCK_SIGHT instead of having the caller pass a flags argument.
 */

s32 cd_test_cylmove_oobok(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	RoomNum throughrooms[21];
	RoomNum finalrooms[8];

	portal_find_rooms(frompos, topos, fromrooms, finalrooms, throughrooms, 20);

	return cd_test_atobany(frompos, topos, throughrooms, types, GEOFLAG_WALL, ATOBTYPE_CYL, checkvertical, ymax, ymin);
}

s32 cd_test_cylmove_oobfail(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	s32 result;
	RoomNum throughrooms[20];
	RoomNum finalrooms[8];

	los_find_intersecting_rooms_properly(frompos, fromrooms, topos, finalrooms, throughrooms, 20);

	if (array_intersects(finalrooms, torooms)) {
		result = cd_test_atobany(frompos, topos, throughrooms, types, GEOFLAG_WALL, ATOBTYPE_CYL, checkvertical, ymax, ymin);
	} else {
		result = CDRESULT_COLLISION;
	}

	return result;
}

s32 cd_test_cylmove_oobok_findclosest(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	RoomNum throughrooms[21];
	RoomNum finalrooms[8];

	portal_find_rooms(frompos, topos, fromrooms, finalrooms, throughrooms, 20);

	return cd_test_atobclosest(frompos, topos, throughrooms, types, GEOFLAG_WALL, ATOBTYPE_CYL, checkvertical, ymax, ymin);
}

s32 cd_test_cylmove_oobok_getfinalroom(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	RoomNum rooms[21];

	portal_find_rooms(frompos, topos, fromrooms, finalrooms, rooms, 20);

	return cd_test_atobany(frompos, topos, rooms, types, GEOFLAG_WALL, ATOBTYPE_CYL, checkvertical, ymax, ymin);
}

s32 cd_test_cylmove_oobfail_findclosest(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	RoomNum throughrooms[21];
	RoomNum finalrooms[8];
	s32 result;

	los_find_intersecting_rooms_properly(frompos, fromrooms, topos, finalrooms, throughrooms, 20);

	result = cd_test_atobclosest(frompos, topos, throughrooms, types, GEOFLAG_WALL, ATOBTYPE_CYL, checkvertical, ymax, ymin);

	if (result != CDRESULT_COLLISION && !array_intersects(finalrooms, torooms)) {
		cd_clear_results();
		result = CDRESULT_ERROR;
	}

	return result;
}

s32 cd_test_cylmove_oobfail_findclosest_finddist(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, f32 radius, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	RoomNum throughrooms[21];
	RoomNum finalrooms[8];
	struct coord dist;
	s32 result;

	los_find_intersecting_rooms_properly(frompos, fromrooms, topos, finalrooms, throughrooms, 20);

	result = cd_test_atobclosest(frompos, topos, throughrooms, types, GEOFLAG_WALL, ATOBTYPE_CYL, checkvertical, ymax, ymin);

	if (result == CDRESULT_COLLISION) {
		dist.x = topos->x - frompos->x;
		dist.y = topos->y - frompos->y;
		dist.z = topos->z - frompos->z;

		cd_set_obstacle_distance(frompos, &dist, radius);
	} else if (!array_intersects(finalrooms, torooms)) {
		cd_clear_results();
		result = CDRESULT_ERROR;
	}

	return result;
}

s32 cd_test_cylmove_oobok_findclosest_getfinalroom(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	RoomNum throughrooms[21];

	portal_find_rooms(frompos, topos, fromrooms, finalrooms, throughrooms, 20);

	return cd_test_atobclosest(frompos, topos, throughrooms, types, GEOFLAG_WALL, ATOBTYPE_CYL, checkvertical, ymax, ymin);
}

s32 cd_test_cylmove_oobok_findclosest_getfinalroom_finddist(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, f32 radius, u32 types, bool checkvertical, f32 ymax, f32 ymin)
{
	RoomNum throughrooms[21];
	struct coord diff;
	s32 result;

	portal_find_rooms(frompos, topos, fromrooms, finalrooms, throughrooms, 20);

	result = cd_test_atobclosest(frompos, topos, throughrooms, types, GEOFLAG_WALL, ATOBTYPE_CYL, checkvertical, ymax, ymin);

	if (result == CDRESULT_COLLISION) {
		diff.x = topos->x - frompos->x;
		diff.y = topos->y - frompos->y;
		diff.z = topos->z - frompos->z;

		cd_set_obstacle_distance(frompos, &diff, radius);
	}

	return result;
}

s32 cd_test_los_oobok(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types, u16 geoflags)
{
	RoomNum throughrooms[21];
	RoomNum finalrooms[8];

	portal_find_rooms(frompos, topos, fromrooms, finalrooms, throughrooms, 20);

	return cd_test_atobany(frompos, topos, throughrooms, types, geoflags, ATOBTYPE_LOS, CHECKVERTICAL_YES, 0, 0);
}

s32 cd_test_los_oobok_autoflags(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types)
{
	return cd_test_los_oobok(frompos, fromrooms, topos, types, GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT);
}

s32 cd_test_los_oobfail(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, u32 types, u16 geoflags)
{
	bool result;
	RoomNum throughrooms[20];
	RoomNum finalrooms[8];

	los_find_intersecting_rooms_properly(frompos, fromrooms, topos, finalrooms, throughrooms, 20);

	if (array_intersects(finalrooms, torooms)) {
		result = cd_test_atobany(frompos, topos, throughrooms, types, geoflags, ATOBTYPE_LOS, CHECKVERTICAL_YES, 0, 0);
	} else {
		result = CDRESULT_COLLISION;
	}

	return result;
}

s32 cd_test_los_oobtail_autoflags(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, u32 types)
{
	return cd_test_los_oobfail(frompos, fromrooms, topos, torooms, types, GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT);
}

s32 cd_test_los_oobfail_getfinalroom(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *torooms, RoomNum *finalrooms, u32 types, u16 geoflags)
{
	bool result;
	RoomNum throughrooms[20];

	los_find_intersecting_rooms_properly(frompos, fromrooms, topos, finalrooms, throughrooms, 20);

	if (array_intersects(finalrooms, torooms)) {
		result = cd_test_atobany(frompos, topos, throughrooms, types, geoflags, ATOBTYPE_LOS, CHECKVERTICAL_YES, 0, 0);
	} else {
		result = CDRESULT_COLLISION;
	}

	return result;
}

s32 cd_test_los_oobok_findclosest(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types, u16 geoflags)
{
	RoomNum throughrooms[21];
	RoomNum finalrooms[8];

	portal_find_rooms(frompos, topos, fromrooms, finalrooms, throughrooms, 20);

	return cd_test_atobclosest(frompos, topos, throughrooms, types, geoflags, ATOBTYPE_LOS, CHECKVERTICAL_YES, 0, 0);
}

s32 cd_test_los_oobok_findclosest_autoflags(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, u32 types)
{
	return cd_test_los_oobok_findclosest(frompos, fromrooms, topos, types, GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT);
}

s32 cd_test_los_oobok_getfinalroom(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, u32 types, u16 geoflags)
{
	RoomNum throughrooms[21];

	portal_find_rooms(frompos, topos, fromrooms, finalrooms, throughrooms, 20);

	return cd_test_atobany(frompos, topos, throughrooms, types, geoflags, ATOBTYPE_LOS, CHECKVERTICAL_YES, 0, 0);
}

s32 cd_test_los_oobok_getfinalroom_autoflags(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, RoomNum *finalrooms, u32 types)
{
	return cd_test_los_oobok_getfinalroom(frompos, fromrooms, topos, finalrooms, types, GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT);
}

bool cd_test_line_intersects_prop(struct coord *frompos, struct coord *topos, struct prop *prop)
{
	u8 *start;
	u8 *end;
	struct coord dist;
	bool result = false;
	struct coord sp6c;
	struct coord sp60;
	struct coord sp54;
	f32 sp50 = 4294967296;
	struct geo *geo;

	dist.x = topos->x - frompos->x;
	dist.y = topos->y - frompos->y;
	dist.z = topos->z - frompos->z;

	if (prop_get_geometry(prop, &start, &end)) {
		if (!cd_test_atobclosest_from_bytes(start, end, frompos, topos, &dist,
					GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT,
					ATOBTYPE_LOS, CHECKVERTICAL_YES, 0, 0, &sp50, &sp6c, &sp60, &sp54, &geo, -999)) {
			result = true;
			cd_set_obstacle_edge_pos_prop_sqdist_geo(&sp60, &sp54, &sp6c, prop, sp50, geo);
		}
	}

	return !result;
}

/**
 * Return true if both blocks are not intersecting on the X/Z plane.
 */
bool cd_block_collides_with_block_laterally(struct geoblock *block1, struct geoblock *block2)
{
	u32 stack[4];
	f32 zero = 0.0f;
	s32 numvertices0 = block1->header.numvertices;
	s32 numvertices1 = block2->header.numvertices;
	s32 i;

	for (i = 0; i < numvertices0; i++) {
		s32 next = (i + 1) % numvertices0;
		f64 diff1;
		f64 diff2;

		diff1 = block1->vertices[next][1] - (f64)block1->vertices[i][1];
		diff2 = block1->vertices[i][0] - (f64)block1->vertices[next][0];

		if (diff1 == zero && diff2 == zero) {
			if (cd_is_xz_in_block(block2, block1->vertices[i][0], block1->vertices[i][1])) {
				return false;
			}
		} else {
			f64 sum1 = block1->vertices[i][0] * diff1 + block1->vertices[i][1] * diff2;
			f64 sum2;
			s32 j = (next + 1) % numvertices0;
			s32 k;

			while (j != i) {
				sum2 = block1->vertices[j][0] * diff1 + block1->vertices[j][1] * diff2;

				if (1);
				if (1);
				if (1);

				if (sum2 != sum1) {
					break;
				}

				j = (j + 1) % numvertices0;
			}

			for (k = 0; k < numvertices1; k++) {
				f64 sum3 = block2->vertices[k][0] * diff1 + block2->vertices[k][1] * diff2;

				if (sum2 == sum1) {
					sum2 = sum1 - sum3 + sum1;
				}

				if ((sum3 < sum1 && sum2 < sum1) || (sum3 > sum1 && sum2 > sum1)) {
					break;
				}
			}

			if (k == numvertices1) {
				return true;
			}
		}
	}

	return false;
}

s32 cd_test_blockvolume_from_bytes(u8 *start, u8 *end, struct geoblock *block, u16 geoflags)
{
	struct geo *geo = (struct geo *) start;

	while (geo < (struct geo *) end) {
		if (geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *) geo;
			geo = (struct geo *)((uintptr_t)geo + GEOTILEI_SIZE(tile));
		} else if (geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *) geo;
			geo = (struct geo *)((uintptr_t)geo + GEOTILEF_SIZE(tile));
		} else if (geo->type == GEOTYPE_BLOCK) {
			struct geoblock *thisblock = (struct geoblock *) geo;

			if ((geoflags & (GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT))
					&& thisblock->ymax >= block->ymin
					&& thisblock->ymin <= block->ymax) {
				// Tiles are overlapping vertically
				s32 i;

				for (i = 0; i < block->header.numvertices; i++) {
					if (cd_is_xz_in_block(thisblock, block->vertices[i][0], block->vertices[i][1])) {
						return CDRESULT_COLLISION;
					}
				}

				for (i = 0; i < thisblock->header.numvertices; i++) {
					if (cd_is_xz_in_block(block, thisblock->vertices[i][0], thisblock->vertices[i][1])) {
						return CDRESULT_COLLISION;
					}
				}

				if (!cd_block_collides_with_block_laterally(block, thisblock) && !cd_block_collides_with_block_laterally(thisblock, block)) {
					return CDRESULT_COLLISION;
				}
			}

			geo = (struct geo *)((uintptr_t)geo + GEOBLOCK_SIZE(thisblock));
		} else if (geo->type == GEOTYPE_CYL) {
			struct geocyl *cyl = (struct geocyl *) geo;

			if ((geoflags & geo->flags)
					&& cyl->ymax >= block->ymin
					&& cyl->ymin <= block->ymax
					&& cd_block_collides_with_cyl_laterally(block, cyl->x, cyl->z, cyl->radius, NULL, NULL)) {
				return CDRESULT_COLLISION;
			}

			geo = (struct geo *)((uintptr_t)geo + GEOCYL_SIZE(cyl));
		}
	}

	return CDRESULT_NOCOLLISION;
}

/**
 * Test if the given block overlaps any prop. Set the saved obstacle prop if so.
 *
 * The BG tests are pointless and not used, as cd_test_blockvolume_from_bytes only
 * tests blocks and cylinders.
 *
 * The function is used to check if a door is being blocked by another prop,
 * and is also used in a sanity check to make sure a moved object hasn't moved
 * into the player's position.
 */
s32 cd_test_blockvolume(struct geoblock *block, RoomNum *rooms, u32 types)
{
	s32 result = CDRESULT_NOCOLLISION;
	s32 roomnum;
	u8 *start;
	u8 *end;
	RoomNum *roomptr;
	s16 propnums[256];
	s16 *propnumptr;

	// Check BG
	if (types & CDTYPE_BG) {
		roomptr = rooms;
		roomnum = rooms[0];

		while (roomnum != -1) {
			if (roomnum < g_TileNumRooms) {
				start = g_TileFileData.u8 + g_TileRooms[roomnum];
				end = g_TileFileData.u8 + g_TileRooms[roomnum + 1];

				result = cd_test_blockvolume_from_bytes(start, end, block, GEOFLAG_WALL);

				if (result == CDRESULT_COLLISION) {
					cd_set_obstacle_prop(NULL);
					break;
				}
			}

			roomptr++;
			roomnum = *roomptr;
		}
	}

	// Check props
	if (result != CDRESULT_COLLISION) {
		room_get_props(rooms, propnums, 256);
		propnumptr = propnums;

		while (*propnumptr >= 0) {
			struct prop *prop = &g_Vars.props[*propnumptr];

			if (prop_is_of_cd_type(prop, types) && prop_get_geometry(prop, &start, &end)) {
				result = cd_test_blockvolume_from_bytes(start, end, block, GEOFLAG_WALL);

				if (result == CDRESULT_COLLISION) {
					cd_set_obstacle_prop(prop);
					break;
				}
			}

			propnumptr++;
		}
	}

	return result;
}

bool cd_test_blockmove_tilei(struct geotilei *tile, s32 numvertices, struct coord *verts, struct coord *diffs, struct prop *prop, struct geoblock *block)
{
	bool result = false;
	s32 i;
	s32 next;
	s32 curr;
	struct coord sp84;
	struct coord sp78;
	struct coord sp6c;

	for (i = 0; i < numvertices; i++) {
		if (g_CdReverseVertices) {
			s32 remaining = numvertices - i;
			next = (remaining + numvertices - 2) % numvertices;
			curr = remaining - 1;
		} else {
			next = (i + 1) % numvertices;
			curr = i;
		}

		if (cd_is_cylpath_intersecting_tilei((struct coord *)((uintptr_t)verts + curr * sizeof(struct coord)),
					(struct coord *)((uintptr_t)verts + next * sizeof(struct coord)),
					(struct coord *)((uintptr_t)diffs + curr * sizeof(struct coord)),
					tile, &sp6c, &sp84, &sp78, 0, 0.0f, 0.0f)) {
			cd_set_obstacle_edge_pos_prop(&sp84, &sp78, &sp6c, prop);
			cd_set_block_edge((struct coord *)((uintptr_t)verts + curr * sizeof(struct coord)), (struct coord *)((uintptr_t)verts + next * sizeof(struct coord)));
			cd_set_block(block);
			result = true;
			break;
		}
	}

	return result;
}

bool cd_test_blockmove_tilef(struct geotilef *tile, s32 numvertices, struct coord *verts, struct coord *diffs, struct prop *prop, struct geoblock *block)
{
	bool result = false;
	s32 i;
	s32 next;
	s32 curr;
	struct coord sp84;
	struct coord sp78;
	struct coord sp6c;

	for (i = 0; i < numvertices; i++) {
		if (g_CdReverseVertices) {
			s32 remaining = numvertices - i;
			next = (remaining + numvertices - 2) % numvertices;
			curr = remaining - 1;
		} else {
			next = (i + 1) % numvertices;
			curr = i;
		}

		if (cd_is_cylpath_intersecting_tilef((struct coord *)((uintptr_t)verts + curr * sizeof(struct coord)),
					(struct coord *)((uintptr_t)verts + next * sizeof(struct coord)),
					(struct coord *)((uintptr_t)diffs + curr * sizeof(struct coord)),
					tile, &sp6c, &sp84, &sp78, 0, 0.0f, 0.0f)) {
			cd_set_obstacle_edge_pos_prop(&sp84, &sp78, &sp6c, prop);
			cd_set_block_edge((struct coord *)((uintptr_t)verts + curr * sizeof(struct coord)), (struct coord *)((uintptr_t)verts + next * sizeof(struct coord)));
			cd_set_block(block);
			result = true;
			break;
		}
	}

	return result;
}

bool cd_test_blockmove_block(struct geoblock *thisblock, s32 numvertices, struct coord *verts, struct coord *diffs, struct prop *prop, struct geoblock *block)
{
	bool result = false;
	s32 i;
	s32 next;
	s32 curr;
	struct coord sp84;
	struct coord sp78;
	struct coord sp6c;

	for (i = 0; i < numvertices; i++) {
		if (g_CdReverseVertices) {
			s32 remaining = numvertices - i;
			next = (remaining + numvertices - 2) % numvertices;
			curr = remaining - 1;
		} else {
			next = (i + 1) % numvertices;
			curr = i;
		}

		if (cd_is_cylpath_intersecting_block((struct coord *)((uintptr_t)verts + curr * sizeof(struct coord)),
					(struct coord *)((uintptr_t)verts + next * sizeof(struct coord)),
					(struct coord *)((uintptr_t)diffs + curr * sizeof(struct coord)),
					thisblock, &sp6c, &sp84, &sp78, 0, 0.0f, 0.0f)) {
			cd_set_obstacle_edge_pos_prop(&sp84, &sp78, &sp6c, prop);
			cd_set_block_edge((struct coord *)((uintptr_t)verts + curr * sizeof(struct coord)), (struct coord *)((uintptr_t)verts + next * sizeof(struct coord)));
			cd_set_block(block);
			result = true;
			break;
		}
	}

	return result;
}

bool cd_test_blockmove_cyl(struct geocyl *cyl, s32 numvertices, struct coord *verts, struct coord *diffs, struct prop *prop, struct geoblock *block)
{
	bool result = false;
	s32 i;
	s32 next;
	s32 curr;
	struct coord sp84;
	struct coord sp78;
	struct coord sp6c;

	for (i = 0; i < numvertices; i++) {
		if (g_CdReverseVertices) {
			s32 remaining = numvertices - i;
			next = (remaining + numvertices - 2) % numvertices;
			curr = remaining - 1;
		} else {
			next = (i + 1) % numvertices;
			curr = i;
		}

		if (cd_is_cylpath_intersecting_cyl((struct coord *)((uintptr_t)verts + curr * sizeof(struct coord)),
					(struct coord *)((uintptr_t)verts + next * sizeof(struct coord)),
					(struct coord *)((uintptr_t)diffs + curr * sizeof(struct coord)),
					cyl, &sp6c, &sp84, &sp78, 0, 0.0f, 0.0f)) {
			cd_set_obstacle_edge_pos_prop(&sp84, &sp78, &sp6c, prop);
			cd_set_block_edge((struct coord *)((uintptr_t)verts + curr * sizeof(struct coord)), (struct coord *)((uintptr_t)verts + next * sizeof(struct coord)));
			cd_set_block(block);
			result = true;
			break;
		}
	}

	return result;
}

s32 cd_test_blockmove_from_bytes(u8 *start, u8 *end, struct geoblock *block, s32 numvertices, struct coord *verts, struct coord *diffs, u16 geoflags, struct prop *prop)
{
	struct geo *geo = (struct geo *) start;

	while (geo < (struct geo *) end) {
		if (1);

		if (geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *)geo;

			if ((geoflags & geo->flags)
					&& *(s16 *)(tile->ymax + (uintptr_t)tile) >= block->ymin
					&& *(s16 *)(tile->ymin + (uintptr_t)tile) <= block->ymax
					&& cd_test_blockmove_tilei(tile, numvertices, verts, diffs, prop, block)) {
				return CDRESULT_COLLISION;
			}

			geo = (struct geo *)((uintptr_t)geo + GEOTILEI_SIZE(tile));
		} else if (geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *)geo;

			if ((geoflags & geo->flags)
					&& tile->vertices[tile->max[1]].y >= block->ymin
					&& tile->vertices[tile->min[1]].y <= block->ymax
					&& cd_test_blockmove_tilef(tile, numvertices, verts, diffs, prop, block)) {
				return CDRESULT_COLLISION;
			}

			geo = (struct geo *)((uintptr_t)geo + GEOTILEF_SIZE(tile));
		} else if (geo->type == GEOTYPE_BLOCK) {
			struct geoblock *block2 = (struct geoblock *)geo;

			if ((geoflags & (GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT))
					&& block2->ymax >= block->ymin
					&& block2->ymin <= block->ymax
					&& cd_test_blockmove_block(block2, numvertices, verts, diffs, prop, block)) {
				return CDRESULT_COLLISION;
			}

			geo = (struct geo *)((uintptr_t)geo + GEOBLOCK_SIZE(block2));
		} else if (geo->type == GEOTYPE_CYL) {
			struct geocyl *cyl = (struct geocyl *)geo;

			if ((geoflags & geo->flags)
					&& cyl->ymax >= block->ymin
					&& cyl->ymin <= block->ymax
					&& cd_test_blockmove_cyl(cyl, numvertices, verts, diffs, prop, block)) {
				return CDRESULT_COLLISION;
			}

			geo = (struct geo *)((uintptr_t)geo + GEOCYL_SIZE(cyl));
		}
	}

	return CDRESULT_NOCOLLISION;
}

/**
 * Test a block moving horizontally into other geometry.
 */
bool cd_test_blockmove(struct geoblock *block, RoomNum *rooms, u32 types)
{
	s32 numvertices = block->header.numvertices;
	s32 i;
	u8 *start;
	u8 *end;
	s32 next;
	s16 propnums[256];
	s16 *propnumptr;
	bool result = true;
	struct coord verts[8];
	struct coord diffs[8];

	for (i = 0; i < numvertices; i++) {
		verts[i].x = block->vertices[i][0];
		verts[i].y = block->ymax;
		verts[i].z = block->vertices[i][1];
	}

	for (i = 0; i < numvertices; i++) {
		next = (i + 1) % numvertices;

		diffs[i].x = verts[next].x - verts[i].x;
		diffs[i].y = verts[next].y - verts[i].y;
		diffs[i].z = verts[next].z - verts[i].z;
	}

	// Check BG
	if (types & CDTYPE_BG) {
		RoomNum *roomsptr = rooms;
		s32 roomnum = *roomsptr;

		while (roomnum != -1) {
			if (roomnum < g_TileNumRooms) {
				start = g_TileFileData.u8 + g_TileRooms[roomnum];
				end = g_TileFileData.u8 + g_TileRooms[roomnum + 1];

				result = cd_test_blockmove_from_bytes(start, end, block, numvertices, verts, diffs, GEOFLAG_WALL, NULL);

				if (result == CDRESULT_COLLISION) {
					break;
				}
			}

			roomsptr++;
			roomnum = *roomsptr;
		}
	}

	if (result != CDRESULT_COLLISION) {
		// Check props
		room_get_props(rooms, propnums, 256);

		propnumptr = propnums;

		while (*propnumptr >= 0) {
			struct prop *prop = &g_Vars.props[*propnumptr];

			if (prop_is_of_cd_type(prop, types)) {
				if (prop_get_geometry(prop, &start, &end)) {
					result = cd_test_blockmove_from_bytes(start, end, block, numvertices, verts, diffs, GEOFLAG_WALL, prop);

					if (result == CDRESULT_COLLISION) {
						break;
					}
				}
			}

			propnumptr++;
		}
	}

	return result;
}

#if VERSION < VERSION_NTSC_1_0
struct debugtri *cd_read_int_tile_vertices(struct debugtri *ptr, s32 *remaining, struct geotilei *tile)
{
	if (tile->header.flags & (GEOFLAG_FLOOR1 | GEOFLAG_WALL)) {
		s32 i;
		s32 numvertices = tile->header.numvertices;
		s16 vertices[16][3];

		if (numvertices > 16) {
			numvertices = 16;
		}

		for (i = 0; i < numvertices; i++) {
			vertices[i][0] = tile->vertices[i][0] - g_Vars.currentplayer->globaldrawworldoffset.x;
			vertices[i][1] = tile->vertices[i][1] - g_Vars.currentplayer->globaldrawworldoffset.y;
			vertices[i][2] = tile->vertices[i][2] - g_Vars.currentplayer->globaldrawworldoffset.z;
		}

		for (i = 2; i < numvertices; i++) {
			if (*remaining > 0) {
				ptr->vertices[0][0] = vertices[0][0];
				ptr->vertices[0][1] = vertices[0][1];
				ptr->vertices[0][2] = vertices[0][2];
				ptr->vertices[1][0] = vertices[i - 1][0];
				ptr->vertices[1][1] = vertices[i - 1][1];
				ptr->vertices[1][2] = vertices[i - 1][2];
				ptr->vertices[2][0] = vertices[i][0];
				ptr->vertices[2][1] = vertices[i][1];
				ptr->vertices[2][2] = vertices[i][2];
				ptr->unk12 = 0;

				ptr++;
			}

			*remaining -= 1;
		}
	}

	return ptr;
}
#endif

#if VERSION < VERSION_NTSC_1_0
struct debugtri *cd_read_flt_tile_vertices(struct debugtri *ptr, s32 *remaining, struct geotilef *tile)
{
	if (tile->header.flags & (GEOFLAG_FLOOR1 | GEOFLAG_WALL)) {
		s32 i;
		s32 numvertices = tile->header.numvertices;
		s16 vertices[16][3];

		if (numvertices > 16) {
			numvertices = 16;
		}

		for (i = 0; i < numvertices; i++) {
			vertices[i][0] = tile->vertices[i].x - g_Vars.currentplayer->globaldrawworldoffset.x;
			vertices[i][1] = tile->vertices[i].y - g_Vars.currentplayer->globaldrawworldoffset.y;
			vertices[i][2] = tile->vertices[i].z - g_Vars.currentplayer->globaldrawworldoffset.z;
		}

		for (i = 2; i < numvertices; i++) {
			if (*remaining > 0) {
				ptr->vertices[0][0] = vertices[0][0];
				ptr->vertices[0][1] = vertices[0][1];
				ptr->vertices[0][2] = vertices[0][2];
				ptr->vertices[1][0] = vertices[i - 1][0];
				ptr->vertices[1][1] = vertices[i - 1][1];
				ptr->vertices[1][2] = vertices[i - 1][2];
				ptr->vertices[2][0] = vertices[i][0];
				ptr->vertices[2][1] = vertices[i][1];
				ptr->vertices[2][2] = vertices[i][2];
				ptr->unk12 = 0;

				ptr++;
			}

			*remaining -= 1;
		}
	}

	return ptr;
}
#endif

Gfx *cd_render(Gfx *gdl, u32 arg1, u32 arg2, u32 arg3)
{
	return gdl;
}

void cd_stub(u32 arg0, u32 arg1)
{
	// empty
}

/**
 * Check direct line of sight, then check positions left and right of topos
 * using the distance argument.
 */
bool cd_is_nearly_in_sight_with_flags(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, f32 distance, u32 types, u16 geoflags)
{
	struct coord diff;
	f32 x;
	f32 z;
	struct coord vector;

	if (cd_test_los_oobok(frompos, fromrooms, topos, types, geoflags)) {
		return true;
	}

	vector.x = topos->x - frompos->x;
	vector.y = 0;
	vector.z = topos->z - frompos->z;

	guNormalize(&vector.x, &vector.y, &vector.z);

	x = vector.f[0] * distance;
	z = vector.f[2] * distance;

	diff.x = topos->x - z;
	diff.y = topos->y;
	diff.z = topos->z + x;

	if (cd_test_los_oobok(frompos, fromrooms, &diff, types, geoflags)) {
		return true;
	}

	diff.x = topos->x + z;
	diff.y = topos->y;
	diff.z = topos->z - x;

	if (cd_test_los_oobok(frompos, fromrooms, &diff, types, geoflags)) {
		return true;
	}

	return false;
}

bool cd_is_nearly_in_sight(struct coord *frompos, RoomNum *fromrooms, struct coord *topos, f32 distance, u32 types)
{
	return cd_is_nearly_in_sight_with_flags(frompos, fromrooms, topos, distance, types, GEOFLAG_BLOCK_SIGHT);
}
