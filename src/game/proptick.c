#include <ultra64.h>
#include "lib/sched.h"
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/projectile.h"
#include "game/bondgun.h"
#include "game/gunfx.h"
#include "game/gset.h"
#include "game/modelmgr.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/playermgr.h"
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

void props_tick(void)
{
	s32 i;
	struct prop *prop;
	struct prop *next;
	struct prop *next2;
	s32 done;
	s32 tickop;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->bondextrapos.x = 0;
		g_Vars.players[i]->bondextrapos.y = 0;
		g_Vars.players[i]->bondextrapos.z = 0;
	}

	shieldhits_tick();
	chra_tick_bg();

	prop = g_Vars.activeprops;

	do {
		next = prop->next;
		done = next == g_Vars.pausedprops;
		tickop = TICKOP_NONE;

		if (prop->type == PROPTYPE_CHR) {
			tickop = chr_tick_beams(prop);
		} else if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
			tickop = obj_tick(prop);
		} else if (prop->type == PROPTYPE_EXPLOSION) {
			tickop = explosion_tick(prop);
		} else if (prop->type == PROPTYPE_SMOKE) {
			tickop = smoke_tick(prop);
		} else if (prop->type == PROPTYPE_PLAYER) {
			tickop = player_tick_beams(prop);
		}

		if (tickop == TICKOP_CHANGEDLIST) {
			next2 = next;
		} else {
			next2 = prop->next;
			done = next2 == g_Vars.pausedprops;

			if (tickop == TICKOP_RETICK) {
				prop_delist(prop);
				prop_activate_this_frame(prop);

				if (done) {
					next2 = prop;
					done = false;
				}
			} else {
				prop_execute_tick_operation(prop, tickop);
			}
		}

		prop = next2;
	} while (!done);
}
