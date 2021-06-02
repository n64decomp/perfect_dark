#include <ultra64.h>
#include "constants.h"
#include "game/prop.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "data.h"
#include "types.h"

void explosionsReset(void)
{
	s32 i;

	var8007e4a0 = 0;
	func0000aa50(0);

	if (g_Explosions) {
		for (i = 0; i < 6; i++) {
			if (g_Explosions[i].prop) {
				propDelist(g_Explosions[i].prop);
				propDisable(g_Explosions[i].prop);
				propFree(g_Explosions[i].prop);

				g_Explosions[i].prop = NULL;
			}
		}
	}
}
