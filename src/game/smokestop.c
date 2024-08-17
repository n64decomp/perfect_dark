#include <ultra64.h>
#include "constants.h"
#include "game/prop.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void smoke_stop(void)
{
	s32 i;

	if (g_Smokes) {
		for (i = 0; i < g_MaxSmokes; i++) {
			if (g_Smokes[i].prop) {
				prop_delist(g_Smokes[i].prop);
				prop_disable(g_Smokes[i].prop);
				prop_free(g_Smokes[i].prop);

				g_Smokes[i].prop = NULL;
			}
		}
	}
}
