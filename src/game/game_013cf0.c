#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_013cf0.h"
#include "game/room.h"
#include "game/file.h"
#include "gvars/gvars.h"
#include "types.h"

void stageLoadTiles(void)
{
	s32 index = stageGetIndex2(g_Vars.stagenum);

	if (index < 0) {
		index = 0;
	}

	var8005d9a0 = 2;
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
		if (tile->unk00 == 0) {
			tile->unk06 = mult6(tile->unk06) + 14;
			tile->unk09 = mult6(tile->unk09) + 14;
			tile->unk07 = mult6(tile->unk07) + 16;
			tile->unk0a = mult6(tile->unk0a) + 16;
			tile->unk08 = mult6(tile->unk08) + 18;
			tile->unk0b = mult6(tile->unk0b) + 18;
			tile = (struct tile *)((u8 *)tile + (u32)(tile->numvertices - 0x40) * 6 + 0x18e);
		} else if (tile->unk00 == 1) {
			tile = (struct tile *)((u8 *)tile + (u32)(tile->numvertices - 0x40) * 12 + 0x310);
		} else if (tile->unk00 == 2) {
			tile = (struct tile *)((u8 *)tile + 0x4c);
		} else if (tile->unk00 == 3) {
			tile = (struct tile *)((u8 *)tile + 0x18);
		}
	}
}
