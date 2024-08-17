#include <ultra64.h>
#include "constants.h"
#include "game/chrai.h"
#include "game/bot.h"
#include "bss.h"
#include "data.h"
#include "types.h"

/**
 * @cmd 0185
 */
bool ai_mp_init_simulants(void)
{
	bot_spawn_all();
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 0176
 */
bool ai_if_bot_respawning(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct aibot *aibot;

	/**
	 * @bug: Missing return means a crash will occur if either of these are
	 * null.
	 */
	if (!g_Vars.chrdata || !g_Vars.chrdata->aibot) {
		g_Vars.aioffset += 3;
		//return false;
	}

	aibot = g_Vars.chrdata->aibot;

	if (aibot->respawning == true) {
		g_Vars.aioffset = chrai_go_to_label(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
		aibot->respawning = false;
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}
