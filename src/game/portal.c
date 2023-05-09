#include <ultra64.h>
#include "constants.h"
#include "game/bondeyespy.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/inv.h"
#include "game/nbomb.h"
#include "game/title.h"
#include "game/chr.h"
#include "game/body.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/atan2f.h"
#include "game/quaternion.h"
#include "game/bondgun.h"
#include "game/gunfx.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b2150.h"
#include "game/tex.h"
#include "game/portal.h"
#include "game/healthbar.h"
#include "game/hudmsg.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/filemgr.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/explosions.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/bg.h"
#include "game/stagetable.h"
#include "game/room.h"
#include "game/gfxmemory.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/texdecompress.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/scenarios.h"
#include "game/radar.h"
#include "game/training.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/pak.h"
#include "game/options.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"


u16 *g_PortalXluFracs;
s32 g_NumPortalXluFracs;

void portalSetXluFrac2(s32 portalnum, f32 frac)
{
	if (portalnum >= 0) {
		u8 value = (u32)(255 * frac);
		value <<= 0;
		g_PortalXluFracs[portalnum] = (g_PortalXluFracs[portalnum] & 0xff00) | value;
	}
}

void portalSetXluFrac(s32 portalnum, f32 frac)
{
	if (portalnum >= 0) {
		u8 value = (u32)(15 * frac) & 0xf;
		g_PortalXluFracs[portalnum] = (g_PortalXluFracs[portalnum] & 0xf0ff) | (value << 8);
	}
}

f32 portalGetXluFrac(s32 arg0)
{
	f32 value = ((g_PortalXluFracs[arg0] & 0xf00) >> 8) * 0.06666667f;

	return value;
}

void portal0f0b65a8(s32 numportals)
{
	if (numportals > 0) {
		g_NumPortalXluFracs = numportals;
		g_PortalXluFracs = mempAlloc(ALIGN16(numportals * 2), MEMPOOL_STAGE);
	} else {
		g_PortalXluFracs = NULL;
	}
}

void portalsReset(void)
{
	if (g_PortalXluFracs) {
		struct prop *prop;
		s32 i;

		for (i = 0; i < g_NumPortalXluFracs; i++) {
			portalSetXluFrac(i, 1);
			portalSetXluFrac2(i, 1);
		}

		prop = g_Vars.activeprops;

		while (prop) {
			if (prop->type == PROPTYPE_OBJ) {
				struct defaultobj *obj = prop->obj;

				if (obj) {
					if (obj->type == OBJTYPE_TINTEDGLASS) {
						struct tintedglassobj *glass = (struct tintedglassobj *)obj;

						if (glass->portalnum >= 0) {
							portalSetXluFrac(glass->portalnum, 0);
						}
					} else if (obj->type == OBJTYPE_GLASS) {
						struct glassobj *glass = (struct glassobj *)obj;

						if (glass->portalnum >= 0) {
							portalSetXluFrac(glass->portalnum, 0);
						}
					}
				}
			}

			prop = prop->next;
		}
	}
}
