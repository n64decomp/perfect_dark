#include <ultra64.h>
#include "constants.h"
#include "game/tiles.h"
#include "game/bg.h"
#include "game/file.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void stage_parse_tiles(void);

void tiles_reset(void)
{
	s32 index = bg_get_stage_index(g_Vars.stagenum);

	if (index < 0) {
		index = 0;
	}

	g_LoadType = LOADTYPE_TILES;
	g_TileFileData.u8 = file_load_to_new(g_Stages[index].tilefileid, FILELOADMETHOD_DEFAULT);
	g_TileNumRooms = *g_TileFileData.u32;
	g_TileRooms = g_TileFileData.u32 + 1;

	stage_parse_tiles();
}

#define mult6(a) (((a) << 1) + ((a) << 2))

void stage_parse_tiles(void)
{
	struct geo *geo = (struct geo *)(g_TileFileData.u8 + g_TileRooms[0]);
	struct geo *end = (struct geo *)(g_TileFileData.u8 + g_TileRooms[g_TileNumRooms]);

	while (geo < end) {
		if (geo->type == GEOTYPE_TILE_I) {
			struct geotilei *tile = (struct geotilei *) geo;

			tile->xmin = 14 + mult6(tile->xmin);
			tile->xmax = 14 + mult6(tile->xmax);
			tile->ymin = 16 + mult6(tile->ymin);
			tile->ymax = 16 + mult6(tile->ymax);
			tile->zmin = 18 + mult6(tile->zmin);
			tile->zmax = 18 + mult6(tile->zmax);

			geo = (struct geo *) ((u8 *) geo + GEOTILEI_SIZE(tile));
		} else if (geo->type == GEOTYPE_TILE_F) {
			struct geotilef *tile = (struct geotilef *) geo;
			geo = (struct geo *) ((u8 *) geo + GEOTILEF_SIZE(tile));
		} else if (geo->type == GEOTYPE_BLOCK) {
			struct geoblock *block = (struct geoblock *) geo;
			geo = (struct geo *) ((u8 *) geo + GEOBLOCK_SIZE(geo));
		} else if (geo->type == GEOTYPE_CYL) {
			struct geocyl *cyl = (struct geocyl *) geo;
			geo = (struct geo *) ((u8 *) geo + GEOCYL_SIZE(cyl));
		}
	}
}
