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
bool aiMpInitSimulants(void)
{
	botSpawnAll();
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 0176
 */
bool ai0176(void)
{
	u8 *cmd = g_Vars.aioffset;
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

	if (aibot->unk059 == 1) {
		g_Vars.aioffset = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
		aibot->unk059 = 0;
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

