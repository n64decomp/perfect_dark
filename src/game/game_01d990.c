#include <ultra64.h>
#include "constants.h"
#include "game/game_01d990.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void func0f01d990(void)
{
	var8007db80 += g_Vars.lvupdate240freal * var8007db84;

	if (var8007db80 > 4096) {
		var8007db80 -= 4096;
	}
}
