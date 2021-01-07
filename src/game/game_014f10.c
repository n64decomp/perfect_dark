#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_014f10.h"
#include "game/chr/chr.h"
#include "game/game_0601b0.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "types.h"

void func0f014f10(void)
{
	s32 i;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].chrnum >= 0
				&& g_ChrSlots[i].prop
				&& g_ChrSlots[i].prop->type == PROPTYPE_CHR) {
			func0f020d44(g_ChrSlots[i].prop, true);
			propRemoveFromCurrentList(g_ChrSlots[i].prop);
			propHide(g_ChrSlots[i].prop);
			propFree(g_ChrSlots[i].prop);
		}
	}
}

void func0f014fe0(void)
{
	alarmDeactivate();
	func0f0904e0();
}
