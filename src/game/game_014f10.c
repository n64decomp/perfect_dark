#include <ultra64.h>
#include "constants.h"
#include "game/game_014f10.h"
#include "game/chr/chr.h"
#include "game/prop.h"
#include "game/propobj.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void chrsReset(void)
{
	s32 i;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].chrnum >= 0
				&& g_ChrSlots[i].prop
				&& g_ChrSlots[i].prop->type == PROPTYPE_CHR) {
			func0f020d44(g_ChrSlots[i].prop, true);
			propDelist(g_ChrSlots[i].prop);
			propDisable(g_ChrSlots[i].prop);
			propFree(g_ChrSlots[i].prop);
		}
	}
}

void alarmReset(void)
{
	alarmDeactivate();
	gasStopAudio();
}
