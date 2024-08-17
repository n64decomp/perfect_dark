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

const char var7f1ad160[] = "ACOUSTIC -> Allocating %d bytes for %d portal AV structures\n";
const char var7f1ad1a0[] = "ACOUSTIC -> DGD WARNING: portalAVInit no portals!\n";
const char var7f1ad1d4[] = "ACOUSTIC -> portalAVReset: checking propobj type %d\n";
const char var7f1ad20c[] = "ACOUSTIC -> portalAVReset: found PROPDEF_WINDOWFADE for portal %d\n";
const char var7f1ad250[] = "ACOUSTIC -> portalAVReset: found PROPDEF_WINDOW for portal %d\n";
const char var7f1ad290[] = "ACOUSTIC -> Portal %3d - A=%.2f, V=%.2f\n";
const char var7f1ad2bc[] = "ACOUSTIC -> DGD WARNING: portalAVReset no portals!\n";

struct roomacousticdata *g_RoomAcousticData;
u32 var8009dd74;
struct var8009dd78 var8009dd78[10];
u16 *g_PortalXluFracs;
s32 g_NumPortalXluFracs;

void portal_set_xlu_frac2(s32 portalnum, f32 frac)
{
	if (portalnum >= 0) {
		u8 value = (u32)(255 * frac);
		value <<= 0;
		g_PortalXluFracs[portalnum] = (g_PortalXluFracs[portalnum] & 0xff00) | value;
	}
}

void portal_set_xlu_frac(s32 portalnum, f32 frac)
{
	if (portalnum >= 0) {
		u8 value = (u32)(15 * frac) & 0xf;
		g_PortalXluFracs[portalnum] = (g_PortalXluFracs[portalnum] & 0xf0ff) | (value << 8);
	}
}

f32 portal_get_xlu_frac2(s32 arg0)
{
	f32 value = (g_PortalXluFracs[arg0] & 0xff) * 0.0039215688593686f;

	return value;
}

f32 portal_get_xlu_frac(s32 arg0)
{
	f32 value = ((g_PortalXluFracs[arg0] & 0xf00) >> 8) * 0.06666667f;

	return value;
}

void portal0f0b65a8(s32 numportals)
{
	if (numportals > 0) {
		g_NumPortalXluFracs = numportals;
		g_PortalXluFracs = memp_alloc(ALIGN16(numportals * 2), MEMPOOL_STAGE);
	} else {
		g_PortalXluFracs = NULL;
	}
}

void portals_reset(void)
{
	if (g_PortalXluFracs) {
		struct prop *prop;
		s32 i;

		for (i = 0; i < g_NumPortalXluFracs; i++) {
			portal_set_xlu_frac(i, 1);
			portal_set_xlu_frac2(i, 1);
		}

		prop = g_Vars.activeprops;

		while (prop) {
			if (prop->type == PROPTYPE_OBJ) {
				struct defaultobj *obj = prop->obj;

				if (obj) {
					if (obj->type == OBJTYPE_TINTEDGLASS) {
						struct tintedglassobj *glass = (struct tintedglassobj *)obj;

						if (glass->portalnum >= 0) {
							portal_set_xlu_frac(glass->portalnum, 0);
						}
					} else if (obj->type == OBJTYPE_GLASS) {
						struct glassobj *glass = (struct glassobj *)obj;

						if (glass->portalnum >= 0) {
							portal_set_xlu_frac(glass->portalnum, 0);
						}
					}
				}
			}

			prop = prop->next;
		}

		for (i = 0; i < g_NumPortalXluFracs; i++) {
			portal_get_xlu_frac(i);
			portal_get_xlu_frac2(i);
		}
	}
}

void acoustic_reset(void)
{
	s32 i;
	s32 j;
	u32 size = ALIGN16(g_Vars.roomcount * sizeof(struct roomacousticdata));
	f32 range;
	f32 width;
	f32 height;
	f32 depth;
	f32 halfsurfacearea;

	osSyncPrintf("Acoustic Reset -> Allocating %d bytes for %d roomacousticdata structures\n", size, g_Vars.roomcount);

	g_RoomAcousticData = memp_alloc(size, MEMPOOL_STAGE);

	for (i = 0; i < g_Vars.roomcount; i++) {
		bool allgood = true;

		g_RoomAcousticData[i].roomvolume = 1;
		g_RoomAcousticData[i].surfacearea = 1;

		for (j = 0; j < 3; j++) {
			osSyncPrintf("ACOUSTIC ->    room %d bb %f %f\n", i, g_Rooms[i].bbmin[j], g_Rooms[i].bbmax[j]);

			range = g_Rooms[i].bbmax[j] - g_Rooms[i].bbmin[j];

			if (range > 0) {
				g_RoomAcousticData[i].roomvolume *= (g_Rooms[i].bbmax[j] - g_Rooms[i].bbmin[j]) / 100;
			} else {
				osSyncPrintf("ACOUSTIC -> DGD: acousticReset room %d does not have a 3D bounding box => radata[room].roomvolume is bodged!\n", i);
				allgood = false;
			}
		}

		if (allgood) {
			if (g_Rooms[i].bbmin[0] < g_Rooms[i].bbmax[0]) {
				width = g_Rooms[i].bbmax[0] - g_Rooms[i].bbmin[0];
			} else {
				width = -(g_Rooms[i].bbmax[0] - g_Rooms[i].bbmin[0]);
			}

			if (g_Rooms[i].bbmin[1] < g_Rooms[i].bbmax[1]) {
				height = g_Rooms[i].bbmax[1] - g_Rooms[i].bbmin[1];
			} else {
				height = -(g_Rooms[i].bbmax[1] - g_Rooms[i].bbmin[1]);
			}

			if (g_Rooms[i].bbmin[2] < g_Rooms[i].bbmax[2]) {
				depth = g_Rooms[i].bbmax[2] - g_Rooms[i].bbmin[2];
			} else {
				depth = -(g_Rooms[i].bbmax[2] - g_Rooms[i].bbmin[2]);
			}

			halfsurfacearea = width * height + width * depth + height * depth;

			g_RoomAcousticData[i].surfacearea = halfsurfacearea + halfsurfacearea;
		} else {
			osSyncPrintf("%s%sL2 -> Surface area bodged for room %d - using %f\n", "", "", i, 20000000);
			g_RoomAcousticData[i].surfacearea = 20000000;
		}
	}

	for (j = 0; j < g_Vars.roomcount; j++) {
		g_RoomAcousticData[j].unk08 = 0;
		g_RoomAcousticData[j].unk04 = g_RoomAcousticData[j].unk08;
	}

	for (j = 0; j < ARRAYCOUNT(var8009dd78); j++) {
		var8009dd78[j].unk00 = -1;
		var8009dd78[j].unk04 = 0;
	}
}
