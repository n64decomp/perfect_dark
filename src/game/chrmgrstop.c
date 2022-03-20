#include <ultra64.h>
#include "constants.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propobj.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void chrmgrStop(void)
{
	s32 i;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].chrnum >= 0
				&& g_ChrSlots[i].prop
				&& g_ChrSlots[i].prop->type == PROPTYPE_CHR) {
			chrRemove(g_ChrSlots[i].prop, true);
			propDelist(g_ChrSlots[i].prop);
			propDisable(g_ChrSlots[i].prop);
			propFree(g_ChrSlots[i].prop);
		}
	}
}
