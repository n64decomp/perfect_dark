#include <ultra64.h>
#include "constants.h"
#include "game/game_013cf0.h"
#include "game/room.h"
#include "game/file.h"
#include "gvars/gvars.h"
#include "data.h"
#include "types.h"

void stageLoadTiles(void)
{
	s32 index = stageGetIndex2(g_Vars.stagenum);

	if (index < 0) {
		index = 0;
	}

	g_LoadType = LOADTYPE_TILES;
	g_TileFileData.u8 = func0f1670fc(g_Stages[index].tilefileid, 0x22);
	g_TileNumRooms = *g_TileFileData.u32;
	g_TileRooms = g_TileFileData.u32 + 1;

	stageParseTiles();
}

#define mult6(a) (((a) << 1) + ((a) << 2))

void stageParseTiles(void)
{
	struct tile *tile = (struct tile *)(g_TileFileData.u8 + g_TileRooms[0]);
	struct tile *end = (struct tile *)(g_TileFileData.u8 + g_TileRooms[g_TileNumRooms]);

	while (tile < end) {
		if (tile->type == TILETYPE_00) {
			struct tiletype0 *tile0 = (struct tiletype0 *) tile;
			tile0->xmin = mult6(tile0->xmin) + 14;
			tile0->xmax = mult6(tile0->xmax) + 14;
			tile0->ymin = mult6(tile0->ymin) + 16;
			tile0->ymax = mult6(tile0->ymax) + 16;
			tile0->zmin = mult6(tile0->zmin) + 18;
			tile0->zmax = mult6(tile0->zmax) + 18;
			tile = (struct tile *)((u8 *)tile + (u32)(tile->numvertices - 0x40) * 6 + 0x18e);
		} else if (tile->type == TILETYPE_01) {
			tile = (struct tile *)((u8 *)tile + (u32)(tile->numvertices - 0x40) * 12 + 0x310);
		} else if (tile->type == TILETYPE_02) {
			tile = (struct tile *)((u8 *)tile + 0x4c);
		} else if (tile->type == TILETYPE_03) {
			tile = (struct tile *)((u8 *)tile + 0x18);
		}
	}
}
