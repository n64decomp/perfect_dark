#include <ultra64.h>
#include "lib/sched.h"
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/game_096360.h"
#include "game/bondgun.h"
#include "game/gunfx.h"
#include "game/game_0b0fd0.h"
#include "game/modelmgr.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/game_0c33f0.h"
#include "game/playermgr.h"
#include "game/game_1291b0.h"
#include "game/vtxstore.h"
#include "game/gfxmemory.h"
#include "game/explosions.h"
#include "game/smoke.h"
#include "game/sparks.h"
#include "game/bg.h"
#include "game/file.h"
#include "game/mplayer/setup.h"
#include "game/bot.h"
#include "game/botact.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "data.h"
#include "types.h"

void propsTick(void)
{
	s32 i;
	struct prop *prop;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->bondextrapos.x = 0;
		g_Vars.players[i]->bondextrapos.y = 0;
		g_Vars.players[i]->bondextrapos.z = 0;
	}

	shieldhitsTick();
	chraTickBg();

	for (i = 0; i < g_NumLifts; i++) {
		liftTick(g_Lifts[i]);
	}

	if (g_Vars.stagenum == STAGE_AIRBASE) {
		prop = g_Vars.activeprops;

		do {
			if (prop->type == PROPTYPE_OBJ && prop->obj->type == OBJTYPE_ESCASTEP) {
				escastepTick(prop);
			}

			prop = prop->next;
		} while (prop != g_Vars.pausedprops);
	} else if (g_Vars.normmplayerisrunning) {
		prop = g_Vars.activeprops;

		do {
			if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) {
				objTick(prop);
			}

			prop = prop->next;
		} while (prop != g_Vars.pausedprops);
	}
}
