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
u8 *aiMpInitSimulants(u8 *cmd)
{
	botSpawnAll();
	cmd += 2;
	return cmd;
}

/**
 * @cmd 0176
 */
u8 *ai0176(u8 *cmd)
{
	struct aibot *aibot;

	/**
	 * @bug: Missing return means a crash will occur if either of these are
	 * null.
	 */
	if (!g_Vars.chrdata || !g_Vars.chrdata->aibot) {
		cmd += 4;
		return cmd;
	}

	aibot = g_Vars.chrdata->aibot;

	if (aibot->unk059 == 1) {
		cmd = AILABEL(g_Vars.ailist, cmd[2], cmd[3]);
		aibot->unk059 = 0;
	} else {
		cmd += 4;
	}

	return cmd;
}

