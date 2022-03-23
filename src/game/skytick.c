#include <ultra64.h>
#include "constants.h"
#include "game/sky.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void skyTick(void)
{
	var8007db80 += g_Vars.lvupdate240freal * var8007db84;

	if (var8007db80 > 4096) {
		var8007db80 -= 4096;
	}
}
