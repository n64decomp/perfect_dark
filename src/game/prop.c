#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/bondwalk.h"
#include "game/chraction.h"
#include "game/dlights.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/floor.h"
#include "game/ceil.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/playermgr.h"
#include "game/explosions.h"
#include "game/smoke.h"
#include "game/sparks.h"
#include "game/bg.h"
#include "game/bot.h"
#include "game/training.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/wallhit.h"
#include "game/mpstats.h"
#include "bss.h"
#include "lib/collision.h"
#include "lib/lib_17ce0.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

static void propsDefragRoomProps(void);

s16 *g_RoomPropListChunkIndexes;
struct roomproplistchunk *g_RoomPropListChunks;
struct prop *g_InteractProp;
s32 var8009cdac;

s32 var8009cdb0;

f32 g_AutoAimScale = 1;

/**
 * Populate g_Vars.onscreenprops. This is an array of prop pointers, filtered by
 * props that are on screen and sorted by distance descending (furthest first).
 */
void propsSort(void)
{
	s32 count = 0;
	struct prop *prop = g_Vars.activeprops;
	s32 swapindex;
	f32 depth;
	s32 i;
	s32 j;
	f32 depths[201];

	// Populate onscreenprops with the list of props
	while (prop != g_Vars.pausedprops) {
		if ((prop->flags & (PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ENABLED)) == (PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ENABLED)) {
			depths[count] = prop->z;
			g_Vars.onscreenprops[count] = prop;
			count++;
		}

		prop = prop->next;
	}

	g_Vars.numonscreenprops = count;
	g_Vars.onscreenprops[count] = NULL;
	g_Vars.endonscreenprops = &g_Vars.onscreenprops[count];

	// Sort the onscreenprops list
	for (i = 0; i < count; i++) {
		swapindex = -1;
		depth = -4294967296;

		for (j = i; j < count; j++) {
			if (depths[j] > depth) {
				depth = depths[j];
				swapindex = j;
			}
		}

		if (swapindex >= 0) {
			prop = g_Vars.onscreenprops[i];
			depth = depths[i];

			g_Vars.onscreenprops[i] = g_Vars.onscreenprops[swapindex];
			depths[i] = depths[swapindex];

			g_Vars.onscreenprops[swapindex] = prop;
			depths[swapindex] = depth;
		}
	}
}

/**
 * Disable the given prop. Disabled props do not tick, do not render and do not
 * have any collision checks. This is commonly used for chrs who "spawn" later
 * in the level.
 *
 * Due to a probable bug, these props can be damaged by explosives which causes
 * them to become enabled.
 */
void propDisable(struct prop *prop)
{
	struct prop **ptr;

	prop->flags &= ~PROPFLAG_ENABLED;

	for (ptr = g_Vars.onscreenprops; ptr < g_Vars.endonscreenprops; ptr++) {
		if (*ptr == prop) {
			*ptr = NULL;
		}
	}
}

/**
 * Allocate a prop. The prop is taken from the head of the freeprops list and
 * initialised.
 */
struct prop *propAllocate(void)
{
	struct prop *prop = g_Vars.freeprops;

	if (g_Vars.freeprops) {
		g_Vars.freeprops = g_Vars.freeprops->next;

		prop->next = NULL;
		prop->prev = NULL;
		prop->parent = NULL;
		prop->child = NULL;
		prop->flags = 0;
		prop->timetoregen = 0;
		prop->rooms[0] = -1;
		prop->chr = NULL;
		prop->propstateindex = g_Vars.allocstateindex;
		prop->backgroundedframes = 0;
		prop->forceonetick = true;
		prop->forcetick = false;
		prop->active = false;
		prop->backgrounded = false;
		prop->lastupdateframe = 0xffff;
		prop->propupdate240 = 0;
		prop->propupdate60err = 2;
		prop->opawallhits = NULL;
		prop->xluwallhits = NULL;
		g_Vars.propstates[prop->propstateindex].propcount++;

		g_Vars.allocstateindex++;

		if (g_Vars.allocstateindex >= g_Vars.numpropstates) {
			g_Vars.allocstateindex = 0;
		}

		return prop;
	}

	return NULL;
}

/**
 * Free the given prop. The prop must not be in any list prior to calling this
 * function.
 *
 * The prop is inserted to the head of the freeprops list.
 */
void propFree(struct prop *prop)
{
	if (prop->type == PROPTYPE_CHR) {
		g_Vars.propstates[prop->propstateindex].chrpropcount--;
	} else {
		g_Vars.propstates[prop->propstateindex].propcount--;
	}

	prop->next = g_Vars.freeprops;
	prop->prev = NULL;
	prop->chr = NULL;
	prop->rooms[0] = -1;
	g_Vars.freeprops = prop;
}

/**
 * Insert the prop to the head of activeprops. The prop must not be in any list
 * prior to calling this function.
 *
 * If this function is being called from propsTickPlayer (which iterates active props)
 * then the prop will do its next tick on the next frame, due to it being
 * inserted at the head.
 */
void propActivate(struct prop *prop)
{
	if (g_Vars.activeprops && g_Vars.activeprops != g_Vars.pausedprops) {
		if (prop != g_Vars.activeprops && !prop->prev) {
			g_Vars.activeprops->prev = prop;
			prop->next = g_Vars.activeprops;
			prop->prev = NULL;
			g_Vars.activeprops = prop;
		}
	} else {
		prop->next = g_Vars.pausedprops;

		if (prop->next) {
			prop->next->prev = prop;
		}

		prop->prev = NULL;
		g_Vars.activeprops = prop;
		g_Vars.activepropstail = g_Vars.activeprops;
	}

	prop->backgroundedframes = 0;
	prop->active = true;
}

/**
 * Similar to propActivate, but the prop inserted to the tail of the activeprops
 * list. This makes the prop tick on the current frame if called from propsTickPlayer,
 * because propsTickPlayer iterates the activeprops list from head to tail.
 */
void propActivateThisFrame(struct prop *prop)
{
	if (g_Vars.activepropstail && g_Vars.activepropstail != g_Vars.pausedprops) {
		if (prop != g_Vars.activepropstail && !prop->next) {
			prop->prev = g_Vars.activepropstail;
			prop->next = g_Vars.activepropstail->next;

			if (prop->next) {
				prop->next->prev = prop;
			}

			g_Vars.activepropstail->next = prop;
			g_Vars.activepropstail = prop;
		}
	} else {
		prop->next = g_Vars.pausedprops;

		if (prop->next) {
			prop->next->prev = prop;
		}

		prop->prev = NULL;
		g_Vars.activeprops = prop;
		g_Vars.activepropstail = g_Vars.activeprops;
	}

	prop->backgroundedframes = 0;
	prop->active = true;
}

/**
 * Remove the prop from its current list (activeprops or pausedprops).
 */
void propDelist(struct prop *prop)
{
	if (prop->active) {
		if (prop == g_Vars.activeprops) {
			g_Vars.activeprops = prop->next;
		}

		if (prop == g_Vars.activepropstail) {
			if (g_Vars.activeprops == g_Vars.pausedprops) {
				g_Vars.activepropstail = g_Vars.pausedprops;
			} else {
				g_Vars.activepropstail = prop->prev;
			}
		}
	} else {
		if (prop == g_Vars.pausedprops) {
			if (g_Vars.activeprops == g_Vars.pausedprops) {
				g_Vars.activepropstail = prop->next;
				g_Vars.activeprops = g_Vars.activepropstail;
			}

			g_Vars.pausedprops = prop->next;
		}
	}

	if (prop->next) {
		prop->next->prev = prop->prev;
	}

	if (prop->prev) {
		prop->prev->next = prop->next;
	}

	prop->next = NULL;
	prop->prev = NULL;
	prop->active = false;
	prop->backgroundedframes = 0;
}

void propReparent(struct prop *mover, struct prop *adopter)
{
	mover->parent = adopter;

	if (adopter->child) {
		adopter->child->prev = mover;
	}

	mover->next = adopter->child;
	mover->prev = NULL;
	adopter->child = mover;
}

void propDetach(struct prop *prop)
{
	if (prop->parent) {
		if (prop == prop->parent->child) {
			prop->parent->child = prop->next;
		}

		if (prop->next) {
			prop->next->prev = prop->prev;
		}

		if (prop->prev) {
			prop->prev->next = prop->next;
		}

		prop->parent = NULL;
		prop->next = NULL;
		prop->prev = NULL;
	}
}

static Gfx *propRender(Gfx *gdl, struct prop *prop, bool xlupass)
{
	if (prop->type & (PROPTYPE_OBJ | PROPTYPE_DOOR | PROPTYPE_WEAPON)) {
		gdl = objRender(prop, gdl, xlupass);
	} else if (prop->type == PROPTYPE_CHR) {
		gdl = chrRender(prop, gdl, xlupass);
	} else if (prop->type == PROPTYPE_SMOKE) {
		gdl = smokeRender(prop, gdl, xlupass);
	} else if (prop->type == PROPTYPE_EXPLOSION) {
		gdl = explosionRender(prop, gdl, xlupass);
	} else if (prop->type == PROPTYPE_PLAYER) {
		gdl = playerRender(prop, gdl, xlupass);
	}

	return gdl;
}

/**
 * Render one pass of all props in the given room number.
 *
 * The render order is:
 * - Opaque components of props (pre-BG)
 * - Opaque components of BG
 * - Opaque components of props (post-BG)
 * - Wall hits
 * - Translucent components of BG
 * - Translucent components of props
 *
 * Most props are rendered in the pre-bg pass for performance reasons, as there
 * is less BG to draw if it's being obscured by props.
 *
 * Props can be rendered in multiple passes, such as terminals which render the
 * terminal in the pre-bg pass and the screen in the post-bg pass, likely to
 * avoid Z-fighting issues.
 */
Gfx *propsRender(Gfx *gdl, s16 renderroomnum, s32 renderpass, s16 *roomnumsbyprop)
{
	struct prop **ptr;
	struct prop *prop;
	s16 *proprooms;

	if (renderpass == RENDERPASS_OPA_PREBG || renderpass == RENDERPASS_OPA_POSTBG) {
		// Iterate onscreen props near to far
		ptr = g_Vars.endonscreenprops - 1;

		proprooms = roomnumsbyprop + (g_Vars.endonscreenprops - g_Vars.onscreenprops);
		proprooms--;

		while (ptr >= g_Vars.onscreenprops) {
			if (renderroomnum == *proprooms) {
				prop = *ptr;

				if (prop) {
					if ((renderpass == RENDERPASS_OPA_PREBG && (prop->flags & (PROPFLAG_DRAWONTOP | PROPFLAG_RENDERPOSTBG)) == 0)
							|| (renderpass == RENDERPASS_OPA_POSTBG && (prop->flags & (PROPFLAG_DRAWONTOP | PROPFLAG_RENDERPOSTBG)) == PROPFLAG_RENDERPOSTBG)) {
						gdl = propRender(gdl, prop, false);
					}
				}
			}

			ptr--;
			proprooms--;
		}
	} else {
		// Iterate onscreen props far to near
		ptr = g_Vars.onscreenprops;
		proprooms = roomnumsbyprop;

		while (ptr < g_Vars.endonscreenprops) {
			if (renderroomnum == *proprooms) {
				prop = *ptr;

				if (prop) {
					if (prop->flags & PROPFLAG_DRAWONTOP) {
						gdl = propRender(gdl, prop, false);
					}

					gdl = propRender(gdl, prop, true);
				}
			}

			ptr++;
			proprooms++;
		}
	}

	gdl = currentPlayerScissorToViewport(gdl);

	return gdl;
}

void weaponPlayWhooshSound(s32 weaponnum, struct prop *prop)
{
	s32 soundnum = -1;
	f32 speed = 1;

	if (weaponnum == WEAPON_TRANQUILIZER) {
		soundnum = SFX_RELOAD_04FB;
		speed = 2.78f;
	} else if (weaponnum == WEAPON_REAPER) {
		// empty
	} else if (weaponnum == WEAPON_COMBATKNIFE) {
		soundnum = random() % 2 == 1 ? SFX_8060 : SFX_8061;
		speed = 1.05f - RANDOMFRAC() * 0.2f;
	} else {
		soundnum = SFX_0069;
		speed = 1.0f - RANDOMFRAC() * 0.2f;
	}

	if (soundnum != -1) {
		if (prop == g_Vars.currentplayer->prop) {
			struct sndstate *handle;
			u32 stack;
			OSPri prevpri = osGetThreadPri(0);
			osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);

			handle = sndStart(var80095200, soundnum, NULL, -1, -1, -1, -1, -1);

			if (handle) {
				audioPostEvent(handle, 0x10, *(s32 *)&speed);
			}

			osSetThreadPri(0, prevpri);
		} else {
			propsnd0f0939f8(NULL, prop, soundnum, -1,
					-1, 0, 0, 0, NULL, speed, NULL, -1, -1, -1, -1);
		}
	}
}

/**
 * This is similar to the above but the sound numbers seem wrong...
 * Perhaps the function was from GE and not updated for PD.
 */
static void func0f060bac(s32 weaponnum, struct prop *prop)
{
	s32 soundnum = -1;
	f32 speed = 1;
	struct sndstate *handle;

	if (weaponnum == WEAPON_UNARMED) {
		soundnum = SFX_THUD_808F;

		if ((random() % 2) == 1) {
			soundnum = SFX_THUD_8094;
		}

		speed = 1.0f - RANDOMFRAC() * 0.1f;
	} else if (weaponnum == WEAPON_TRANQUILIZER) {
		soundnum = SFX_RELOAD_04FB;
		speed = 2.78f;
	} else {
		soundnum = SFX_HIT_METAL_8079;
		speed = 1.0f - RANDOMFRAC() * 0.1f;
	}

	if (soundnum != -1) {
		if (prop == g_Vars.currentplayer->prop) {
			OSPri prevpri = osGetThreadPri(0);
			osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);

			handle = sndStart(var80095200, soundnum, 0, -1, -1, -1, -1, -1);

			if (handle) {
				audioPostEvent(handle, 0x10, *(s32 *)&speed);
			}

			osSetThreadPri(0, prevpri);
		} else {
			propsnd0f0939f8(NULL, prop, soundnum, -1, -1, 0, 0, 0, NULL, speed, NULL, -1, -1, -1, -1);
		}
	}
}

/**
 * Calculate what was hit from a single shot.
 *
 * Multiple things can be hit, because shots can pass through glass and the more
 * powerful weapons can shoot through chrs.
 *
 * The return value is the final prop that was hit.
 */
static struct prop *shotCalculateHits(s32 handnum, bool arg1, struct coord *arg2, struct coord *arg3, struct coord *gunpos, struct coord *dir, u32 arg6, f32 arg7, bool arg8)
{
	u32 index;
	struct prop **propptr;
	struct prop *root;
	bool explosiveshells = false;
	bool sp6cc = false;
	bool hitbg = false;
	s32 room = 0;
	struct hitthing sp694;
	struct hitthing sp664;
	struct coord sp658;
	struct prop *playerprop = g_Vars.currentplayer->prop;
	struct coord hitpos;
	struct shotdata shotdata;
	s32 i;
	s32 s1 = 0;
	struct weaponfunc *func;
	bool laserstream = false;
	bool shortrange = false;
	f32 range = 200;
	struct prop *result = NULL;
	s32 hitindex;
	struct surfacetype *surfacetype;
	bool done;
	s32 sparktype;

#ifdef AVOID_UB
	s16 rooms[131];
#else
	s16 rooms[124];
#endif

	s16 spc8[8];
	s16 spb8[8];
	s32 uVar6;
	s16 *roomsptr;
	struct prop *prop;
	struct coord spa0;
	struct defaultobj *obj;
	bool doexplosiveshells;
	struct coord sp8c;
	s16 sp7c[8];
	s16 sp6c[8];
	struct prop *hitprop;

	bgun0f0a9494(arg6);

	shotdata.gunpos = *gunpos;

	shotdata.unk00 = *arg2;

	shotdata.dir = *dir;

	shotdata.unk0c = *arg3;

	gsetPopulateFromCurrentPlayer(handnum, &shotdata.gset);
	func = gsetGetWeaponFunction(&shotdata.gset);

	if (func) {
		if (arg1 && (func->flags & FUNCFLAG_EXPLOSIVESHELLS)) {
			explosiveshells = true;
		}

		if ((func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE && arg1) {
			shortrange = true;
			arg1 = false;
		}
	}

	if (shotdata.gset.weaponnum == WEAPON_LASER && shotdata.gset.weaponfunc == FUNC_SECONDARY) {
		laserstream = true;
	}

	if (arg1) {
		shotdata.penetration = gsetGetSinglePenetration(&shotdata.gset);
	} else {
		shotdata.penetration = 1;
	}

	shotdata.unk34 = arg7;

	for (i = 0; i != 10; i++) {
		shotdata.hits[i].prop = NULL;
		shotdata.hits[i].hitpart = 0;
		shotdata.hits[i].node = NULL;
	}

	if (laserstream) {
		hitpos.x = shotdata.gunpos.x + shotdata.dir.x * 300;
		hitpos.y = shotdata.gunpos.y + shotdata.dir.y * 300;
		hitpos.z = shotdata.gunpos.z + shotdata.dir.z * 300;
	} else if (shortrange) {
		if ((func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
			struct weaponfunc_close *close = (struct weaponfunc_close *) func;
			range = close->range;
		}

		hitpos.x = shotdata.gunpos.x + shotdata.dir.x * range;
		hitpos.y = shotdata.gunpos.y + shotdata.dir.y * range;
		hitpos.z = shotdata.gunpos.z + shotdata.dir.z * range;
	} else {
		hitpos.x = shotdata.gunpos.x + shotdata.dir.x * 65536;
		hitpos.y = shotdata.gunpos.y + shotdata.dir.y * 65536;
		hitpos.z = shotdata.gunpos.z + shotdata.dir.z * 65536;
	}

	portal00018148(&playerprop->pos, &shotdata.gunpos, playerprop->rooms, spc8, 0, 0);
	portal00018148(&shotdata.gunpos, &hitpos, spc8, spb8, rooms, 30);

	if (shotdata.gset.weaponnum != WEAPON_FARSIGHT || g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
		roomsptr = rooms;

		while (*roomsptr != -1) {
			roomsptr++;
		}

		roomsGetActive(roomsptr, 100);

		for (i = 0; rooms[i] != -1; i++) {
			if (bgTestHitInRoom(&shotdata.gunpos, &hitpos, rooms[i], &sp664)) {
				sp664.unk00.x *= 1;
				sp664.unk00.y *= 1;
				sp664.unk00.z *= 1;

				if (((hitpos.x >= shotdata.gunpos.x && hitpos.x >= sp664.unk00.x && sp664.unk00.x >= shotdata.gunpos.x)
							|| (hitpos.x <= shotdata.gunpos.x && hitpos.x <= sp664.unk00.x && sp664.unk00.x <= shotdata.gunpos.x))
						&& ((hitpos.y >= shotdata.gunpos.y && hitpos.y >= sp664.unk00.y && sp664.unk00.y >= shotdata.gunpos.y)
							|| (hitpos.y <= shotdata.gunpos.y && hitpos.y <= sp664.unk00.y && sp664.unk00.y <= shotdata.gunpos.y))
						&& ((shotdata.gunpos.z <= hitpos.z && sp664.unk00.z <= hitpos.z && shotdata.gunpos.z <= sp664.unk00.z)
							|| (hitpos.z <= shotdata.gunpos.z && hitpos.z <= sp664.unk00.z && sp664.unk00.z <= shotdata.gunpos.z))
						&& (shotdata.gunpos.x != sp664.unk00.x || shotdata.gunpos.y != sp664.unk00.y || shotdata.gunpos.z != sp664.unk00.z)) {
					hitbg = true;
					room = rooms[i];

					sp694 = sp664;

					hitpos = sp664.unk00;
				}
			}
		}
	}

	if (hitbg && shotdata.gset.weaponnum != WEAPON_FARSIGHT) {
		mtx4TransformVec(g_Vars.currentplayer->worldtoscreenmtx, &sp694.unk00, &sp658);

		if (shotdata.unk34 > -sp658.z) {
			shotdata.unk34 = -sp658.z;
		}
	}

	propptr = g_Vars.endonscreenprops - 1;

	while (propptr >= g_Vars.onscreenprops) {
		prop = *propptr;

		if (prop) {
			if (prop->type == PROPTYPE_CHR
					|| (prop->type == PROPTYPE_PLAYER && prop->chr && playermgrGetPlayerNumByProp(prop) != g_Vars.currentplayernum)) {
				if (!shortrange) {
					chr0f027994(prop, &shotdata, arg1, arg8);
				}
			} else if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
				func0f085e00(prop, &shotdata);
			}
		}

		propptr--;
	}

	hitindex = -1;

	if (shotdata.hits[0].prop) {
		spa0 = shotdata.hits[0].pos;
		hitindex = 0;
	}

	if (&spa0);

	if (hitindex != -1) {
		bgun0f0a94d0(arg6, &shotdata.hits[hitindex].pos, &shotdata.hits[hitindex].dir);
	} else if (hitbg) {
		bgun0f0a94d0(arg6, &sp694.unk00, &sp694.unk0c);
	}

	if (arg1) {
		for (i = 0; i < 10; i++) {
			hitprop = shotdata.hits[i].prop;

			if (hitprop && !(laserstream && shotdata.hits[i].distance > 300)) {
				obj = hitprop->obj;
				doexplosiveshells = false;
				root = hitprop;

				while (root->parent) {
					root = root->parent;
				}

				if (root->type & (PROPTYPE_CHR | PROPTYPE_PLAYER)) {
					chrHit(&shotdata, &shotdata.hits[i]);
				} else if (hitprop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
					objHit(&shotdata, &shotdata.hits[i]);
				}

				if (shotdata.hits[i].unk4d) {
					sp6cc = true;
					doexplosiveshells = explosiveshells;
					hitpos = shotdata.hits[i].pos;
				} else if (shotdata.hits[i].unk4c
						|| (explosiveshells && (obj->type == OBJTYPE_GLASS || obj->type == OBJTYPE_TINTEDGLASS))) {
					s1++;

					if (s1 >= shotdata.penetration) {
						sp6cc = true;
						doexplosiveshells = explosiveshells;
						hitpos = shotdata.hits[i].pos;
					}
				}

				if (doexplosiveshells) {
					sp8c = shotdata.hits[i].pos;

					func0f065e74(&root->pos, root->rooms, &sp8c, sp7c);
					explosionCreateSimple(0, &sp8c, sp7c, EXPLOSIONTYPE_PHOENIX, g_Vars.currentplayernum);
				}
			}
		}

		if (hitbg && !sp6cc) {
			sp6c[0] = room;
			sp6c[1] = -1;

			uVar6 = lightsHandleHit(&shotdata.gunpos, &hitpos, room);

			if (sp694.texturenum < 0 || sp694.texturenum >= NUM_TEXTURES) {
				surfacetype = g_SurfaceTypes[SURFACETYPE_DEFAULT];
			} else {
				index = g_Textures[sp694.texturenum].surfacetype;

				if (index < ARRAYCOUNT(g_SurfaceTypes)) {
					surfacetype = g_SurfaceTypes[index];
				} else {
					surfacetype = g_SurfaceTypes[SURFACETYPE_DEFAULT];
				}
			}

			bgunSetHitPos(&sp694.unk00);

			if (surfacetype->numwallhittexes > 0 && (!func || (func->type & 0xff) != INVENTORYFUNCTYPE_CLOSE)) {
				if (shotdata.gset.weaponnum != WEAPON_UNARMED
						&& shotdata.gset.weaponnum != WEAPON_LASER
						&& shotdata.gset.weaponnum != WEAPON_TRANQUILIZER
						&& shotdata.gset.weaponnum != WEAPON_FARSIGHT) {
					uVar6 = random() % surfacetype->numwallhittexes;
					uVar6 = surfacetype->wallhittexes[uVar6];

					if (uVar6 >= WALLHITTEX_GLASS1 && uVar6 <= WALLHITTEX_GLASS3) {
						// Use bulletproof glass hit textures instead
						uVar6 += 10;
					}

					if (uVar6) {
						wallhitCreate(&sp694.unk00, &sp694.unk0c, &shotdata.gunpos, 0, 0, uVar6, room, 0, -1, 0, g_Vars.currentplayer->prop->chr, sp694.unk2c == 2);
					}
				}

				bgunPlayBgHitSound(&shotdata.gset, &sp694.unk00, sp694.texturenum, sp6c);

				if (explosiveshells) {
					explosionCreateSimple(NULL, &sp694.unk00, sp6c, EXPLOSIONTYPE_PHOENIX, g_Vars.currentplayernum);
				} else {
					if (!chrIsUsingPaintball(g_Vars.currentplayer->prop->chr)) {
						if (PLAYERCOUNT() >= 2) {
							if ((random() % 8) == 0) {
								smokeCreateSimple(&sp694.unk00, sp6c, SMOKETYPE_BULLETIMPACT);
							}
						} else {
							if (uVar6) {
								explosionCreateSimple(NULL, &sp694.unk00, sp6c, EXPLOSIONTYPE_BULLETHOLE, g_Vars.currentplayernum);
							}
						}
					}

					if (PLAYERCOUNT() <= 2 || g_Vars.lvupdate240 <= 8 || (random() % 4) == 0) {
						if (sp694.unk00.x > -32000 && sp694.unk00.x < 32000
								&& sp694.unk00.y > -32000 && sp694.unk00.y < 32000
								&& sp694.unk00.z > -32000 && sp694.unk00.z < 32000) {
							sparktype = SPARKTYPE_DEFAULT;

							if (chrIsUsingPaintball(g_Vars.currentplayer->prop->chr)) {
								sparktype = SPARKTYPE_PAINT;
							} else {
								switch (shotdata.gset.weaponnum) {
								case WEAPON_FARSIGHT:
									sparktype = SPARKTYPE_BGHIT_ORANGE;
									break;
								case WEAPON_CYCLONE:
									sparktype = SPARKTYPE_ELECTRICAL;
									break;
								case WEAPON_MAULER:
								case WEAPON_PHOENIX:
								case WEAPON_CALLISTO:
								case WEAPON_REAPER:
									sparktype = SPARKTYPE_BGHIT_GREEN;
									break;
								case WEAPON_TRANQUILIZER:
									sparktype = SPARKTYPE_BGHIT_TRANQULIZER;
									break;
								}

								uVar6 = g_Textures[sp694.texturenum].surfacetype;

								if (uVar6 == SURFACETYPE_SHALLOWWATER || uVar6 == SURFACETYPE_DEEPWATER) {
									sparktype = SPARKTYPE_SHALLOWWATER;
								}
							}

							sparksCreate(room, NULL, &sp694.unk00, &shotdata.dir, &sp694.unk0c, sparktype);
						}
					}
				}
			}
		} else {
			bgunSetHitPos(&hitpos);
		}
	} else if (shortrange) {
		s32 hitindex;
		bool hitaprop = false;

		hitindex = 0;

		for (i = 0; i < 10; i++) {
			if (shotdata.hits[i].prop && shotdata.hits[i].distance < range) {
				hitaprop = true;
				hitindex = i;
				break;
			}
		}

		if (hitaprop || hitbg) {
			func0f060bac(shotdata.gset.weaponnum, g_Vars.currentplayer->prop);

			if (shotdata.gset.weaponnum != WEAPON_UNARMED && shotdata.gset.weaponnum != WEAPON_TRANQUILIZER) {
				if (hitaprop) {
					sparksCreate(shotdata.hits[hitindex].prop->rooms[0], NULL, &shotdata.hits[hitindex].pos, &shotdata.dir, &shotdata.hits[hitindex].dir, SPARKTYPE_DEFAULT);
				} else {
					sparksCreate(room, NULL, &sp694.unk00, &shotdata.dir, &sp694.unk0c, SPARKTYPE_DEFAULT);
				}
			}
		} else {
			weaponPlayWhooshSound(shotdata.gset.weaponnum, g_Vars.currentplayer->prop);
		}
	} else {
		// Figure out what prop was hit so it can be returned,
		// by iterating the props in order of distance.
		// For laser stream, bail early once the laser's range is reached.
		done = false;

		for (i = 0; i < 10; i++) {
			hitprop = shotdata.hits[i].prop;

			if (hitprop && !done) {
				if (laserstream && shotdata.hits[i].distance > 300) {
					done = true;
				} else {
					if (hitprop->type & (PROPTYPE_CHR | PROPTYPE_PLAYER)) {
						result = hitprop;
						done = true;
					} else if (hitprop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
						result = hitprop;
						done = true;
					}

					// This seems like it handles penetration (bullets going
					// through multiple props), but the loop is effectively
					// stopped when any prop is hit so this seems unlikely.
					if (shotdata.hits[i].unk4c) {
						s1++;

						if (s1 >= shotdata.penetration) {
							done = true;
						}
					}
				}
			}
		}
	}

	return result;
}

struct prop *func0f061d54(s32 handnum, u32 arg1, u32 arg2)
{
	struct coord sp64;
	struct coord sp58;
	struct coord sp4c;
	struct coord sp40;

	bgunCalculatePlayerShotSpread(&sp58, &sp64, handnum, arg2);

	if (arg2 == 2 && bgunGetWeaponNum(HAND_RIGHT) == WEAPON_REAPER) {
		sp58.y -= 15 * RANDOMFRAC();
	}

	mtx4TransformVec(g_Vars.currentplayer->projectionmtx, &sp58, &sp40);
	mtx4RotateVec(g_Vars.currentplayer->projectionmtx, &sp64, &sp4c);

	return shotCalculateHits(handnum, arg1, &sp58, &sp64, &sp40, &sp4c, 0, 4294836224, PLAYERCOUNT() >= 2);
}

static void shotCreate(s32 handnum, bool arg1, bool dorandom, s32 arg3, bool arg4)
{
	struct coord shootdir;
	struct coord shootpos;
	struct coord sp44;
	struct coord sp38;

	bgunCalculatePlayerShotSpread(&sp38, &sp44, handnum, dorandom);

	if (arg3 > 0) {
		mtx4TransformVec(g_Vars.currentplayer->projectionmtx, &sp38, &shootpos);
		mtx4RotateVec(g_Vars.currentplayer->projectionmtx, &sp44, &shootdir);

		shotCalculateHits(handnum, arg1, &sp38, &sp44, &shootpos, &shootdir, 0, 4294836224, arg4);

		if (arg3 < 2) {
			bgunSetLastShootInfo(&shootpos, &shootdir, handnum);
		}
	}
}

void func0f061fa8(struct shotdata *shotdata, struct prop *prop, f32 arg2, s32 hitpart, struct modelnode *node, struct hitthing *hitthing, s32 arg6, struct modelnode *arg7, struct model *model, bool arg9, s32 arg10, struct coord *arg11, struct coord *arg12)
{
	s32 i;
	f32 fVar8;

	if (arg9) {
		s32 bestindex = 0;
		s32 count = 0;
		f32 mostdist = 0;
		f32 prevmostdist = 0;

		for (i = 0; i < 10; i++) {
			if (shotdata->hits[i].prop && shotdata->hits[i].unk4c) {
				count++;

				if (shotdata->hits[i].distance > mostdist) {
					prevmostdist = mostdist;
					mostdist = shotdata->hits[i].distance;
					bestindex = i;
				}
			}
		}

		if (count >= shotdata->penetration) {
			shotdata->hits[bestindex].prop = NULL;
			shotdata->unk34 = prevmostdist;

			if (shotdata->unk34 < arg2) {
				shotdata->unk34 = arg2;
			}

			for (i = 0; i < 10; i++) {
				if (shotdata->hits[i].prop && !shotdata->hits[i].unk4c && shotdata->hits[i].distance > prevmostdist) {
					shotdata->hits[i].prop = NULL;
				}
			}
		} else if (count + 1 == shotdata->penetration) {
			if (shotdata->unk34 > arg2) {
				shotdata->unk34 = arg2;
			}
		}
	}

	if (arg10) {
		for (i = 0; i < 10; i++) {
			if (shotdata->hits[i].prop && shotdata->hits[i].distance > arg2) {
				shotdata->hits[i].prop = NULL;
			}
		}

		shotdata->unk34 = arg2;
	}

	for (i = 0; i < 10; i++) {
		if (shotdata->hits[i].prop == NULL) {
			struct hit *hit = &shotdata->hits[i];

			hit->distance = arg2;
			hit->prop = prop;
			hit->hitpart = hitpart;
			hit->node = node;
			hit->hitthing = *hitthing;
			hit->mtxindex = arg6;
			hit->unk44 = arg7;
			hit->model = model;
			hit->unk4c = arg9;
			hit->unk4d = arg10;
			hit->pos = *arg11;

			fVar8 = sqrtf(arg12->f[0] * arg12->f[0] + arg12->f[1] * arg12->f[1] + arg12->f[2] * arg12->f[2]);

			if (fVar8 > 0) {
				hit->dir.x = arg12->x / fVar8;
				hit->dir.y = arg12->y / fVar8;
				hit->dir.z = arg12->z / fVar8;
			} else {
				hit->dir.x = 0;
				hit->dir.y = 0;
				hit->dir.z = 1;
			}

			break;
		}
	}
}

static void handInflictCloseRangeDamage(s32 handnum, struct gset *gset, bool arg2)
{
	s32 cdtypes;
	struct prop **ptr;
	struct prop *playerprop;
	bool skipthething;

	playerprop = g_Vars.currentplayer->prop;
	ptr = g_Vars.endonscreenprops - 1;
	skipthething = false;

	// Iterate onscreen props near to far
	while (ptr >= g_Vars.onscreenprops) {
		struct prop *prop = *ptr;

		if (prop && prop->z < 500) {
			/**
			 * @bug: There is no check to make sure the prop's type is obj
			 * before accessing the obj properties. prop->obj is a void *
			 * pointer or union of pointers so it may point to a non-obj struct.
			 * This means it's checking if the byte at offset 3 in whichever
			 * struct it's pointing to has the value 0x2a (glass) or 0x2f
			 * (tinted glass).
			 *
			 * If the prop being iterated is a chr, this offset corresponds to
			 * the speedrating property in the chrdata struct. So inflicting
			 * close range damage on a chr with a speedrating of 42 (0x2a) or
			 * 47 (0x2f) will cause a crash. No chrs have these speedrating
			 * values though, and the reaction speed setting in PD mode was
			 * removed... maybe because of this bug?
			 *
			 * If the prop being iterated is an explosion or smoke, the offset
			 * corresponds to the last byte of a pointer to a struct. Because
			 * structs are 4-byte aligned, its value will never be 0x2a or 0x2f.
			 * If glass or tinted glass were assigned values that were multiples
			 * of 4 then the game could crash when you punch explosions or
			 * smoke.
			 *
			 * The other prop types use pointers that also point to chr structs,
			 * or to other objs which extend defaultobj, so the bug is not
			 * present for those.
			 */
			struct defaultobj *obj = prop->obj;
			bool isglass = false;

			if (obj && gset->weaponnum != WEAPON_TRANQUILIZER) {
				isglass = obj->type == OBJTYPE_GLASS || obj->type == OBJTYPE_TINTEDGLASS;
			}

			if (arg2) {
				isglass = false;
			}

			if (prop->type == PROPTYPE_CHR
					|| (prop->type == PROPTYPE_PLAYER && prop->chr && playermgrGetPlayerNumByProp(prop) != g_Vars.currentplayernum)
					|| isglass) {
				f32 rangelimit = 60;
				f32 distance;
				f32 sp110;
				struct chrdata *chr = prop->chr;
				f32 x;
				f32 y;
				f32 spfc[2];
				f32 spf4[2];
				struct model *model;
				struct weaponfunc *func = gsetGetWeaponFunction(gset);

				if ((func->type & 0xff) == 3) {
					struct weaponfunc_close *closefunc = (struct weaponfunc_close *)func;
					rangelimit = closefunc->range;
				}

				bgunGetCrossPos(&x, &y);

				spfc[0] = (x - g_Vars.currentplayer->c_screenleft) / (g_Vars.currentplayer->c_screenwidth * 0.5f) - 1.0f;
				spfc[1] = (y - g_Vars.currentplayer->c_screentop) / (g_Vars.currentplayer->c_screenheight * 0.5f) - 1.0f;
				spf4[0] = g_Vars.currentplayer->c_screenheight * 0.16666667163372f;
				spf4[1] = g_Vars.currentplayer->c_screenheight * 0.125f;

				if (isglass) {
					model = obj->model;
				} else {
					model = chr->model;
				}

				if (func0f0679ac(model, &distance, &sp110, spfc, spf4)
						&& sp110 <= 0
						&& distance >= -rangelimit) {
					cdtypes = CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_PATHBLOCKER | CDTYPE_BG;

					if (isglass) {
						cdtypes = 0;
					}

					if (cdTestLos04(&playerprop->pos, playerprop->rooms, &prop->pos, cdtypes)) {
						if (isglass) {
							struct model *model = obj->model;
							struct coord spd8;
							struct coord spcc;
							struct modelnode *node = NULL;

							bgunCalculatePlayerShotSpread(&spd8, &spcc, handnum, true);

							if (model000225d4(model, &spd8, &spcc, &node) > 0) {
								f32 damage = gsetGetDamage(gset) * 2.5f;
								skipthething = true;
								bgunPlayGlassHitSound(&playerprop->pos, playerprop->rooms, -1);
								objTakeGunfire(obj, damage, &prop->pos, gset->weaponnum, g_Vars.currentplayernum);
								objDropRecursively(prop, false);
							}
						} else if (arg2) {
							chr->chrflags |= CHRCFLAG_10000000;
						} else {
							struct coord spb8;
							struct coord vector;
							struct modelnode *node = NULL;
							struct model *model = NULL;
							s32 side = -1;
							s32 hitpart = HITPART_TORSO;

							if (!chrIsAvoiding(chr)) {
								bgunCalculatePlayerShotSpread(&spb8, &vector, handnum, true);
								skipthething = true;
								mtx4RotateVecInPlace(g_Vars.currentplayer->projectionmtx, &vector);
								bgunPlayPropHitSound(gset, prop, -1);

								if (chr->model && chr->cshield > 0) {
									chrCalculateShieldHit(chr, &playerprop->pos, &vector, &node, &hitpart, &model, &side);
								}

								if (bmoveGetCrouchPos() == CROUCHPOS_DUCK) {
									hitpart = HITPART_GENERAL;
								} else if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT) {
									hitpart = HITPART_GENERALHALF;
								} else {
									hitpart = HITPART_TORSO;
								}

								func0f0341dc(chr, gsetGetDamage(gset), &vector, gset,
										g_Vars.currentplayer->prop, hitpart, chr->prop, node, model, side, 0);
							}
						}
					}
				}
			}
		}

		ptr--;
	}

	if (!skipthething && !arg2) {
		g_Vars.currentplayer->hands[handnum].unk0d0f_02 = true;
	}
}

static void handTickAttack(s32 handnum)
{
	if (g_Vars.currentplayer->hands[handnum].unk0d0f_02) {
		s32 doit = true;

		if (bgunGetWeaponNum(handnum) == WEAPON_REAPER
				&& (g_Vars.currentplayer->hands[handnum].burstbullets % 3) != 1) {
			doit = false;
		}

		if (doit) {
			func0f061d54(handnum, 1, 2);
		}

		g_Vars.currentplayer->hands[handnum].unk0d0f_02 = false;
	}

	if (g_Vars.currentplayer->hands[handnum].firing) {
		s32 type = g_Vars.currentplayer->hands[handnum].attacktype;
		s32 weaponnum = bgunGetWeaponNum(handnum);
		struct gset gset;
		bool cloaked;

		g_Vars.currentplayer->hands[handnum].activatesecondary = false;

		gsetPopulateFromCurrentPlayer(handnum, &gset);
		frIncrementNumShots();

		switch (type) {
		case HANDATTACKTYPE_SHOOT:
			// Always execute if right hand, but if left hand then execute if
			// right hand is not (ie. prevent firing both guns on the same tick)
			if (handnum == HAND_RIGHT || !g_Vars.currentplayer->hands[HAND_RIGHT].firing) {
				chrUncloakTemporarily(g_Vars.currentplayer->prop->chr);
				mpstatsIncrementPlayerShotCount2(&gset, 0);

				if (weaponnum == WEAPON_SHOTGUN) {
					shotCreate(handnum, true, true, 1, true);
					shotCreate(handnum, true, true, 1, true);
					shotCreate(handnum, true, true, 1, true);
					shotCreate(handnum, true, true, 1, true);
					shotCreate(handnum, true, true, 1, true);
					shotCreate(handnum, true, true, 1, true);
				} else {
					shotCreate(handnum, true, true, bgunGetShotsToTake(handnum), g_Vars.mplayerisrunning);
				}

				mpstats0f0b0520();
			}
			break;
		case HANDATTACKTYPE_CLOSERANGE:
			chrUncloakTemporarily(g_Vars.currentplayer->prop->chr);
			handInflictCloseRangeDamage(handnum, &gset, false);
			break;
		case HANDATTACKTYPE_CLOSERANGENOUNCLOAK:
			handInflictCloseRangeDamage(handnum, &gset, true);
			break;
		case HANDATTACKTYPE_DETONATE:
			playerActivateRemoteMineDetonator(g_Vars.currentplayernum);
			break;
		case HANDATTACKTYPE_BOOST:
			bgunApplyBoost();
			break;
		case HANDATTACKTYPE_REVERTBOOST:
			bgunRevertBoost();
			break;
		case HANDATTACKTYPE_SHOOTPROJECTILE:
			bgunCreateFiredProjectile(handnum);
			break;
		case HANDATTACKTYPE_CROUCH:
			if (g_Vars.currentplayer->crouchpos == CROUCHPOS_SQUAT) {
				bwalkAdjustCrouchPos(2);
			} else {
				bwalkAdjustCrouchPos(-2);
			}
			break;
		case HANDATTACKTYPE_THROWPROJECTILE:
			bgunCreateThrownProjectile(handnum, &gset);
			break;
		case HANDATTACKTYPE_RCP120CLOAK:
			cloaked = (g_Vars.currentplayer->devicesactive & DEVICE_CLOAKRCP120) != 0;

			if (cloaked) {
				g_Vars.currentplayer->devicesactive &= ~DEVICE_CLOAKRCP120;
			} else {
				g_Vars.currentplayer->devicesactive =
					(g_Vars.currentplayer->devicesactive & ~DEVICE_CLOAKDEVICE)
					| DEVICE_CLOAKRCP120;
			}
			break;
		}
	}
}

void handsTickAttack(void)
{
	if (g_Vars.lvupdate240 > 0) {
		handTickAttack(HAND_RIGHT);
		handTickAttack(HAND_LEFT);
	}
}

void propExecuteTickOperation(struct prop *prop, s32 op)
{
	if (op == TICKOP_FREE) {
		if ((prop->type & (PROPTYPE_WEAPON | PROPTYPE_OBJ))
				&& prop->obj && (prop->obj->hidden2 & OBJH2FLAG_CANREGEN)) {
			struct defaultobj *obj = prop->obj;

			prop->timetoregen = TICKS(1200);

			obj->damage = 0;
			obj->hidden |= OBJHFLAG_00000800;
			obj->hidden &= ~OBJHFLAG_REAPABLE;
			obj->hidden2 &= ~OBJH2FLAG_DESTROYED;

			propDeregisterRooms(prop);
			propDisable(prop);

			if (!prop->active) {
				propUnpause(prop);
			}
		} else {
			propDeregisterRooms(prop);
			propDelist(prop);
			propDisable(prop);
			propFree(prop);
		}
	} else if (op == TICKOP_DISABLE) {
		propDeregisterRooms(prop);
		propDelist(prop);
		propDisable(prop);
	} else if (op == TICKOP_GIVETOPLAYER) {
		propDeregisterRooms(prop);
		propDelist(prop);
		propDisable(prop);
		objDetach(prop);
		objFreeEmbedmentOrProjectile(prop);
		propReparent(prop, g_Vars.currentplayer->prop);
	}
}

static struct prop *propFindForInteract(bool usingeyespy)
{
	struct prop **ptr;
	bool checkmore = true;

	g_InteractProp = NULL;

	// Iterate onscreen list near to far
	for (ptr = g_Vars.endonscreenprops - 1; ptr >= g_Vars.onscreenprops; ptr--) {
		struct prop *prop = *ptr;

		if (prop) {
			if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) {
				if (!usingeyespy) {
					checkmore = objTestForInteract(prop);
				}
			} else if (prop->type == PROPTYPE_DOOR) {
				checkmore = doorTestForInteract(prop);
			}

			if (!checkmore) {
				break;
			}
		}
	}

	return g_InteractProp;
}

bool currentPlayerInteract(bool eyespy)
{
	struct prop *prop;
	bool op = TICKOP_NONE;

	prop = propFindForInteract(eyespy);

	if (prop) {
		if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) {
			op = propobjInteract(prop);
		} else if (prop->type == PROPTYPE_DOOR) {
			op = propdoorInteract(prop);
		}

		propExecuteTickOperation(prop, op);

		return false;
	}

	return true;
}

/**
 * Pause a prop. Paused props still exist in the stage, but are not near the
 * player and do not tick.
 *
 * The prop is removed from its current list (activeprops or pausedprops)
 * if any, and is then inserted to the head of pausedprops.
 */
static void propPause(struct prop *prop)
{
	if ((prop->flags & PROPFLAG_DONTPAUSE) == 0) {
		propDelist(prop);

		if (g_Vars.pausedprops) {
			prop->prev = g_Vars.pausedprops->prev;

			if (prop->prev) {
				prop->prev->next = prop;
			}

			g_Vars.pausedprops->prev = prop;
			prop->next = g_Vars.pausedprops;

			if (g_Vars.activeprops == g_Vars.pausedprops) {
				g_Vars.activeprops = g_Vars.activepropstail = prop;
			}

			g_Vars.pausedprops = prop;
		} else {
			prop->next = NULL;

			if (g_Vars.activepropstail) {
				prop->prev = g_Vars.activepropstail;
				g_Vars.activepropstail->next = prop;
			} else {
				g_Vars.activepropstail = prop;
				g_Vars.activeprops = prop;
			}

			g_Vars.pausedprops = prop;
		}
	}
}

/**
 * Unpause a prop. The prop will begin ticking.
 *
 * The prop is removed from its current list (activeprops or pausedprops)
 * if any, and is then inserted to the head of activeprops.
 *
 * If this function is being called from propsTickPlayer (which iterates active props)
 * then the prop will do its next tick on the next frame, due to it being
 * inserted at the head.
 */
void propUnpause(struct prop *prop)
{
	if (prop == g_Vars.pausedprops) {
		if (g_Vars.activeprops == g_Vars.pausedprops) {
			g_Vars.activeprops = g_Vars.activepropstail = prop->next;
		}

		g_Vars.pausedprops = prop->next;
	}

	if (prop->next) {
		prop->next->prev = prop->prev;
	}

	if (prop->prev) {
		prop->prev->next = prop->next;
	}

	prop->next = NULL;
	prop->prev = NULL;

	propActivate(prop);
}

// 0 = will tick when backgrounded
// 1 = will not tick when backgrounded
u8 g_PausableObjs[] = {
	0, // dummy element because objects are 1-indexed
	0, // OBJTYPE_DOOR
	0, // OBJTYPE_DOORSCALE
	1, // OBJTYPE_BASIC
	1, // OBJTYPE_KEY
	1, // OBJTYPE_ALARM
	1, // OBJTYPE_CCTV
	1, // OBJTYPE_AMMOCRATE
	1, // OBJTYPE_WEAPON
	0, // OBJTYPE_CHR
	1, // OBJTYPE_SINGLEMONITOR
	1, // OBJTYPE_MULTIMONITOR
	1, // OBJTYPE_HANGINGMONITORS
	1, // OBJTYPE_AUTOGUN
	1, // OBJTYPE_LINKGUNS
	0, // OBJTYPE_DEBRIS
	0, // OBJTYPE_10
	1, // OBJTYPE_HAT
	1, // OBJTYPE_GRENADEPROB
	1, // OBJTYPE_LINKLIFTDOOR
	1, // OBJTYPE_MULTIAMMOCRATE
	1, // OBJTYPE_SHIELD
	0, // OBJTYPE_TAG
	0, // OBJTYPE_BEGINOBJECTIVE
	0, // OBJTYPE_ENDOBJECTIVE
	0, // OBJECTIVETYPE_DESTROYOBJ
	0, // OBJECTIVETYPE_COMPFLAGS
	0, // OBJECTIVETYPE_FAILFLAGS
	0, // OBJECTIVETYPE_COLLECTOBJ
	0, // OBJECTIVETYPE_THROWOBJ
	1, // OBJECTIVETYPE_HOLOGRAPH
	0, // OBJECTIVETYPE_1F
	0, // OBJECTIVETYPE_ENTERROOM
	0, // OBJECTIVETYPE_THROWINROOM
	0, // OBJTYPE_22
	0, // OBJTYPE_BRIEFING
	1, // OBJTYPE_GASBOTTLE
	1, // OBJTYPE_RENAMEOBJ
	0, // OBJTYPE_PADLOCKEDDOOR
	0, // OBJTYPE_TRUCK
	0, // OBJTYPE_HELI
	0, // OBJTYPE_29
	1, // OBJTYPE_GLASS
	1, // OBJTYPE_SAFE
	1, // OBJTYPE_SAFEITEM
	0, // OBJTYPE_TANK
	1, // OBJTYPE_CAMERAPOS
	1, // OBJTYPE_TINTEDGLASS
	0, // OBJTYPE_LIFT
	0, // OBJTYPE_CONDITIONALSCENERY
	0, // OBJTYPE_BLOCKEDPATH
	0, // OBJTYPE_HOVERBIKE
	0, // OBJTYPE_END
	0, // OBJTYPE_HOVERPROP
	1, // OBJTYPE_FAN
	0, // OBJTYPE_HOVERCAR
	0, // OBJTYPE_PADEFFECT
	0, // OBJTYPE_CHOPPER
	0, // OBJTYPE_MINE
	1, // OBJTYPE_ESCASTEP
};

/**
 * Figure out which props need to update their state for the current player on
 * this tick, and do so.
 *
 * This function is called once per player per frame. Most logic applies to all
 * players, but some logic only applies to the first player and some only to the
 * last.
 *
 * Props are split into two classes: foreground and background props. Foreground
 * props are generally props that are near the player. These ones are updated on
 * every tick. Background props are props elsewhere in the stage. These ones are
 * updated less frequently by assigning them to one of 7 timeslots and only
 * updating one timeslot per frame (in multiplayer, only 4 timeslots are used).
 *
 * Timeslots and propstates are the same thing. It is likely that the original
 * code called them propstates. The propstate structs are used to track timing
 * information so all props in that timeslot can be updated using the correct
 * multipliers.
 *
 * Each time all timeslots have been updated (ie. every 7 or 4 frames) the
 * timeslots are redistributed among the props, to handle situations where props
 * have been allocated or freed during gameplay. This redistribution is done by
 * categorising each prop into one of four categories:
 *
 *     - foreground chrs
 *     - background chrs
 *     - foreground non-chrs
 *     - background non-chrs
 *
 * Timeslots are then assigned evenly within those categories. This method
 * ensures that there aren't an uneven amount of props being updated on any
 * given frame, which helps give a consistent frame rate.
 */
void propsTickPlayer(bool islastplayer)
{
	struct prop *prop;
	struct prop *end;
	s32 savedlvupdate240;
	s32 savedlvupdate60;
	f32 savedlvupdate60f;
	f32 savedlvupdate60freal;
	s32 savedslotupdate240;
	s32 savedslotupdate240_60;
	f32 savedslotupdate240f;
	struct g_vars *vars = &g_Vars;
	s16 *rooms;
	u8 mostindex;
	u8 leastindex;
	u8 runstateindex;
	u8 flags;
	s32 op;
	struct prop *next;
	struct prop *savednext;
	struct defaultobj *obj;
	u16 least;
	u16 most;
	s32 i;
	bool done;
	struct chrdata *chr1;
	struct chrdata *chr2;

	g_Vars.hardfreeabletally = 0;

	var8009cdac = 0;
	var8009cdb0 = 0;

	if (islastplayer) {
		g_Vars.prevupdateframe = g_Vars.updateframe;
		g_Vars.updateframe++;
	}

	// Save these global timing values because we'll be modifying them
	// and restoring them afterwards
	savedlvupdate240 = g_Vars.lvupdate240;
	savedlvupdate60 = g_Vars.lvupdate60;
	savedlvupdate60f = g_Vars.lvupdate60f;
	savedlvupdate60freal = g_Vars.lvupdate60freal;

	for (i = 0; i < g_Vars.numpropstates; i++) {
		g_Vars.propstates[i].slotupdate240 += g_Vars.lvupdate240;
	}

	g_Vars.runstateindex++;

	if (g_Vars.runstateindex >= g_Vars.numpropstates) {
		g_Vars.runstateindex = 0;
	}

	runstateindex = g_Vars.runstateindex;

	savedslotupdate240_60 = g_Vars.propstates[runstateindex].slotupdate240 + g_Vars.propstates[runstateindex].slotupdate60error;
	g_Vars.propstates[runstateindex].slotupdate60error = (savedslotupdate240_60 & 3);

	savedslotupdate240 = g_Vars.propstates[runstateindex].slotupdate240;
	savedslotupdate240f = g_Vars.propstates[runstateindex].slotupdate240 / 4.0f;

	savedslotupdate240_60 = (savedslotupdate240 + 2) >> 2;

	for (i = 0; i < g_Vars.numpropstates; i++) {
		g_Vars.propstates[i].propcount = 0;
		g_Vars.propstates[i].chrpropcount = 0;
		g_Vars.propstates[i].foregroundpropcount = 0;
		g_Vars.propstates[i].foregroundchrpropcount = 0;
	}

	// Update the onscreen flags for all props
	if (g_Vars.currentplayerindex == 0) {
		// This is the first time propsTickPlayer has been called on this frame
		prop = g_Vars.activeprops;

		while (prop != g_Vars.pausedprops) {
			flags = prop->flags;

			if (flags & PROPFLAG_ONANYSCREENTHISTICK) {
				flags |= PROPFLAG_ONANYSCREENPREVTICK;
				flags &= ~(PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONTHISSCREENTHISTICK);
			} else {
				flags &= ~(PROPFLAG_ONANYSCREENPREVTICK | PROPFLAG_ONTHISSCREENTHISTICK);
			}

			flags |= PROPFLAG_NOTYETTICKED;

			prop->flags = flags;

			prop = prop->next;
		}
	} else {
		// This is a subsequent call of propsTickPlayer on this frame
		prop = g_Vars.activeprops;

		while (prop != g_Vars.pausedprops) {
			prop->flags &= ~PROPFLAG_ONTHISSCREENTHISTICK;
			prop = prop->next;
		}
	}

	// Iterate all active props, decide if they are in the foreground or
	// background and decide if they should be ticked.
	done = false;
	if (1);
	for (prop = g_Vars.activeprops; !done; ) {
		op = TICKOP_NONE;
		savednext = prop->next;
		done = savednext == g_Vars.pausedprops;

		// Tally up reasons for the prop to be in the foreground.
		// The i variable is being reused as the score value.
		// If the score is non-zero, the prop is a foreground prop.
		i = 0;

		if ((prop->flags & (PROPFLAG_ENABLED | PROPFLAG_ONANYSCREENPREVTICK)) == (PROPFLAG_ENABLED | PROPFLAG_ONANYSCREENPREVTICK)
				|| prop->type == PROPTYPE_PLAYER
				|| prop->forcetick
				|| prop->forceonetick
				|| ((prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) && (prop->obj->hidden & OBJHFLAG_PROJECTILE))
				|| g_Vars.tickmode != TICKMODE_NORMAL) {
			i = 1;
			prop->forceonetick = false;
		}

		if (!i) {
			rooms = prop->rooms;

			while (*rooms != -1) {
				if (g_Rooms[*rooms].flags & (ROOMFLAG_ONSCREEN | ROOMFLAG_STANDBY)) {
					i = 1;
					break;
				}

				rooms++;
			}
		}

		prop->propupdate240 += g_Vars.lvupdate240;

		if (i > 0) {
			// The prop is in the foreground, so it must be ticked on this frame
			if (prop->lastupdateframe != g_Vars.prevupdateframe) {
				g_Vars.lvupdate240 = prop->propupdate240;
				g_Vars.lvupdate60 = prop->propupdate240 + prop->propupdate60err;
				prop->propupdate60err = g_Vars.lvupdate60 & 3;
				g_Vars.lvupdate60 >>= 2;
				g_Vars.lvupdate60f = g_Vars.lvupdate240 / 4.0f;
				g_Vars.lvupdate60freal = PALUPF(g_Vars.lvupdate60f);
			} else {
				g_Vars.lvupdate240 = savedlvupdate240;
				g_Vars.lvupdate60 = savedlvupdate60;
				g_Vars.lvupdate60f = savedlvupdate60f;
				g_Vars.lvupdate60freal = savedlvupdate60freal;
			}

			prop->backgroundedframes = 0;

			// Tick the prop
			if (prop->type == PROPTYPE_CHR) {
				chr1 = prop->chr;

				splatTickChr(prop);

				if (prop->flags & PROPFLAG_NOTYETTICKED) {
					chrTickBeams(prop);
				}

				if (chr1 && chr1->aibot) {
					op = botTick(prop);
				} else {
					op = chrTick(prop);
				}

				g_Vars.propstates[prop->propstateindex].foregroundchrpropcount++;
			} else {
				g_Vars.propstates[prop->propstateindex].foregroundpropcount++;

				if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
					op = objTickPlayer(prop);
				} else if (prop->type == PROPTYPE_EXPLOSION) {
					op = explosionTickPlayer(prop);
				} else if (prop->type == PROPTYPE_SMOKE) {
					op = smokeTickPlayer(prop);
				} else if (prop->type == PROPTYPE_PLAYER) {
					if (prop->flags & PROPFLAG_NOTYETTICKED) {
						playerTickBeams(prop);
					}

					splatTickChr(prop);
					op = playerTickThirdPerson(prop);
				}
			}

			if (prop->lastupdateframe != g_Vars.prevupdateframe) {
				g_Vars.lvupdate240 = savedlvupdate240;
				g_Vars.lvupdate60 = savedlvupdate60;
				g_Vars.lvupdate60f = savedlvupdate60f;
				g_Vars.lvupdate60freal = savedlvupdate60freal;
			}

			prop->lastupdateframe = g_Vars.updateframe;
			prop->propupdate240 = 0;
			prop->backgrounded = false;
		} else {
			// The prop is in the background. It should only be ticked on this
			// frame if its propstate is the one being run on this frame.
			if (prop->type == PROPTYPE_CHR) {
				g_Vars.propstates[prop->propstateindex].chrpropcount++;
			} else {
				g_Vars.propstates[prop->propstateindex].propcount++;
			}

			if (prop->propstateindex == runstateindex) {
				if (prop->lastupdateframe != g_Vars.propstates[runstateindex].lastupdateframe) {
					g_Vars.lvupdate240 = prop->propupdate240;
					g_Vars.lvupdate60 = prop->propupdate240 + prop->propupdate60err;
					prop->propupdate60err = g_Vars.lvupdate60 & 3;
					g_Vars.lvupdate60 >>= 2;
					g_Vars.lvupdate60f = g_Vars.lvupdate240 / 4.0f;
					g_Vars.lvupdate60freal = PALUPF(g_Vars.lvupdate60f);
				} else {
					g_Vars.lvupdate240 = savedslotupdate240;
					g_Vars.lvupdate60 = savedslotupdate240_60;
					g_Vars.lvupdate60f = savedslotupdate240f;
					vars->lvupdate60freal = PALUPF(savedslotupdate240f);
				}

				// Tick the prop
				if (prop->type == PROPTYPE_CHR) {
					chr2 = prop->chr;

					splatTickChr(prop);

					if (prop->flags & PROPFLAG_NOTYETTICKED) {
						chrTickBeams(prop);
					}

					if (chr2 && chr2->aibot) {
						op = botTick(prop);
					} else {
						op = chrTick(prop);
					}
				} else if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) {
					obj = prop->obj;

					if (!g_PausableObjs[obj->type]) {
						op = objTickPlayer(prop);
					} else if (prop->timetoregen <= 0) {
						// The prop does not regenerate. If we've done a full
						// cycle of propstates while backgrounded and the prop
						// hasn't moved to the foreground, pause it.
						prop->backgroundedframes++;

						if (prop->backgroundedframes > g_Vars.numpropstates - 1) {
							propPause(prop);
							op = TICKOP_CHANGEDLIST;
						}
					}
				} else if (prop->type == PROPTYPE_DOOR) {
					struct doorobj *door = prop->door;

					op = objTickPlayer(prop);

					if (op == TICKOP_NONE && door->mode == DOORMODE_IDLE && door->frac <= 0
							&& (door->base.hidden & OBJHFLAG_REAPABLE) == 0) {
						propPause(prop);
						op = TICKOP_CHANGEDLIST;
					}
				} else if (prop->type == PROPTYPE_EXPLOSION) {
					op = explosionTickPlayer(prop);
				} else if (prop->type == PROPTYPE_SMOKE) {
					op = smokeTickPlayer(prop);
				} else if (prop->type == PROPTYPE_PLAYER) {
					if (prop->flags & PROPFLAG_NOTYETTICKED) {
						playerTickBeams(prop);
					}

					splatTickChr(prop);
					op = playerTickThirdPerson(prop);
				}

				if (prop->lastupdateframe != g_Vars.propstates[runstateindex].lastupdateframe) {
					g_Vars.lvupdate240 = savedslotupdate240;
					g_Vars.lvupdate60 = savedslotupdate240_60;
					g_Vars.lvupdate60f = savedslotupdate240f;
					vars->lvupdate60freal = PALUPF(savedslotupdate240f);
				}

				prop->lastupdateframe = g_Vars.updateframe;
				prop->propupdate240 = 0;
				prop->backgrounded = true;
			}
		}

		g_Vars.lvupdate240 = savedlvupdate240;
		g_Vars.lvupdate60 = savedlvupdate60;
		g_Vars.lvupdate60f = savedlvupdate60f;
		g_Vars.lvupdate60freal = savedlvupdate60freal;

		if (op == TICKOP_CHANGEDLIST) {
			// The prop has changed from active to paused, which means its
			// `next` pointer now points to a paused prop and must not be used.
			// Use the prop->next value that was taken before it ticked.
			next = savednext;
		} else {
			// Use the current prop->next value
			next = prop->next;
			done = next == g_Vars.pausedprops;

			if (op == TICKOP_RETICK) {
				prop->lastupdateframe = 0xffff;
				prop->forceonetick = true;

				// Delisting and activating it again appends it to the active
				// props list, which means it'll get ticked again on this frame.
				propDelist(prop);
				propActivateThisFrame(prop);

				if (done) {
					next = prop;
					done = false;
				}
			} else {
				propExecuteTickOperation(prop, op);
			}
		}

		prop = next;
	}

	// If this is the first time propsTickPlayer is being called on this frame,
	// and we've completed a full cycle of the propstates, redistribute them.
	// For each combination of background/foreground and chr/nonchr, take the
	// propstates with the highest quantity of these props and move some to the
	// lowest quantity propstate.
	if (g_Vars.currentplayerindex == 0 && g_Vars.runstateindex == 0) {
		// Background non-chrs
		leastindex = g_Vars.numpropstates;
		mostindex = g_Vars.numpropstates;
		least = 0x7fff;
		most = 0;

		for (i = 0; i < g_Vars.numpropstates; i++) {
			if (g_Vars.propstates[i].propcount < least) {
				least = g_Vars.propstates[i].propcount;
				leastindex = i;
			}

			if (g_Vars.propstates[i].propcount > most) {
				most = g_Vars.propstates[i].propcount;
				mostindex = i;
			}
		}

		i = (g_Vars.propstates[mostindex].propcount - g_Vars.propstates[leastindex].propcount) >> 1;

		if (i != 0) {
			prop = g_Vars.activeprops;

			while (prop != g_Vars.pausedprops) {
				if (prop->propstateindex == mostindex && prop->backgrounded == 1 && prop->type != PROPTYPE_CHR) {
					prop->propstateindex = leastindex;
					i--;

					if (i == 0) {
						break;
					}
				}

				prop = prop->next;
			}
		}

		// Foreground non-chrs
		leastindex = g_Vars.numpropstates;
		mostindex = g_Vars.numpropstates;
		least = 0x7fff;
		most = 0;

		for (i = 0; i < g_Vars.numpropstates; i++) {
			if (g_Vars.propstates[i].foregroundpropcount < least) {
				least = g_Vars.propstates[i].foregroundpropcount;
				leastindex = i;
			}

			if (g_Vars.propstates[i].foregroundpropcount > most) {
				most = g_Vars.propstates[i].foregroundpropcount;
				mostindex = i;
			}
		}

		i = (g_Vars.propstates[mostindex].foregroundpropcount - g_Vars.propstates[leastindex].foregroundpropcount) >> 1;

		if (i != 0) {
			prop = g_Vars.activeprops;

			while (prop != g_Vars.pausedprops) {
				if (prop->propstateindex == mostindex && prop->backgrounded == 0 && prop->type != PROPTYPE_CHR) {
					prop->propstateindex = leastindex;
					i--;

					if (i == 0) {
						break;
					}
				}

				prop = prop->next;
			}
		}

		// Background chrs
		leastindex = g_Vars.numpropstates;
		mostindex = g_Vars.numpropstates;
		least = 0x7fff;
		most = 0;

		for (i = 0; i < g_Vars.numpropstates; i++) {
			if (g_Vars.propstates[i].chrpropcount < least) {
				least = g_Vars.propstates[i].chrpropcount;
				leastindex = i;
			}

			if (g_Vars.propstates[i].chrpropcount > most) {
				most = g_Vars.propstates[i].chrpropcount;
				mostindex = i;
			}
		}

		i = (g_Vars.propstates[mostindex].chrpropcount - g_Vars.propstates[leastindex].chrpropcount) >> 1;

		if (i != 0) {
			prop = g_Vars.activeprops;

			while (prop != g_Vars.pausedprops) {
				if (prop->propstateindex == mostindex && prop->backgrounded == 1 && prop->type == PROPTYPE_CHR) {
					prop->propstateindex = leastindex;
					i--;

					if (i == 0) {
						break;
					}
				}

				prop = prop->next;
			}
		}

		// Foreground chrs
		leastindex = g_Vars.numpropstates;
		mostindex = g_Vars.numpropstates;
		least = 0x7fff;
		most = 0;

		for (i = 0; i < g_Vars.numpropstates; i++) {
			if (g_Vars.propstates[i].foregroundchrpropcount < least) {
				least = g_Vars.propstates[i].foregroundchrpropcount;
				leastindex = i;
			}

			if (g_Vars.propstates[i].foregroundchrpropcount > most) {
				most = g_Vars.propstates[i].foregroundchrpropcount;
				mostindex = i;
			}
		}

		i = (g_Vars.propstates[mostindex].foregroundchrpropcount - g_Vars.propstates[leastindex].foregroundchrpropcount) >> 1;

		if (i != 0) {
			prop = g_Vars.activeprops;

			while (prop != g_Vars.pausedprops) {
				if (prop->propstateindex == mostindex && prop->backgrounded == 0 && prop->type == PROPTYPE_CHR) {
					prop->propstateindex = leastindex;
					i--;

					if (i == 0) {
						break;
					}
				}

				prop = prop->next;
			}
		}
	}

	g_Vars.lvupdate240 = savedlvupdate240;
	g_Vars.lvupdate60 = savedlvupdate60;
	g_Vars.lvupdate60f = savedlvupdate60f;
	g_Vars.lvupdate60freal = savedlvupdate60freal;

	g_Vars.propstates[runstateindex].slotupdate240 = 0;
	g_Vars.propstates[runstateindex].lastupdateframe = g_Vars.updateframe;

	if (islastplayer) {
		alarmTick();
		propsndTick();

		if (g_Vars.tickmode != TICKMODE_NORMAL || g_Vars.lvupdate240 == 0) {
			propsDefragRoomProps();
		}
	}

	var80062964 = 0;
}

void propsTickPadEffects(void)
{
	s32 i;
	struct pad *pad;
	u32 stack;
	struct coord up;
	s16 rooms[2];
	s16 rooms2[2];
	s32 type;

	if (g_LastPadEffectIndex >= 0) {
		for (i = 0; i <= g_LastPadEffectIndex; i++) {
			struct padeffectobj *effect = &g_PadEffects[i];

			pad = &g_Pads[effect->pad];

			if (roomIsOnscreen(pad->room)) {
				switch (effect->effect) {
				case PADEFFECT_SPARKS:
				case PADEFFECT_SPARKS2:
					rooms[0] = pad->room;
					rooms[1] = -1;

					up.x = -pad->up.x;
					up.y = -pad->up.y;
					up.z = -pad->up.z;

					if ((random() % 2048) <= 50) {
						sparksCreate(rooms[0], NULL, &pad->pos, &up, &pad->up, SPARKTYPE_ENVIRONMENTAL1);
						propsnd0f0939f8(NULL, NULL, propsndGetRandomSparkSound(), -1, -1, 0, 0, 0, &pad->pos, -1, rooms, -1, -1, -1, -1);
					}

					if ((random() % 2048) <= 15) {
						sparksCreate(rooms[0], NULL, &pad->pos, &up, &pad->up, SPARKTYPE_ENVIRONMENTAL1);
						sparksCreate(rooms[0], NULL, &pad->pos, &up, &pad->up, SPARKTYPE_ENVIRONMENTAL2);
						propsnd0f0939f8(NULL, NULL, propsndGetRandomSparkSound(), -1, -1, 0, 0, 0, &pad->pos, -1, rooms, -1, -1, -1, -1);
					}

					if ((random() % 2048) <= 5) {
						sparksCreate(rooms[0], NULL, &pad->pos, &up, &pad->up, SPARKTYPE_ENVIRONMENTAL1);
						sparksCreate(rooms[0], NULL, &pad->pos, &up, &pad->up, SPARKTYPE_ENVIRONMENTAL3);
						propsnd0f0939f8(NULL, NULL, propsndGetRandomSparkSound(), -1, -1, 0, 0, 0, &pad->pos, -1, rooms, -1, -1, -1, -1);
					}
					break;
				case PADEFFECT_OUTROSMOKE:
					if (g_Vars.tickmode != TICKMODE_CUTSCENE || !objectiveIsAllComplete()) {
						// @bug: This should be a break rather than a return.
						// Because of this, subsequent pad effects won't tick.
						return;
					}
					// fall-through
				case PADEFFECT_SPLASH:
				case PADEFFECT_SMOKE:
					type = SMOKETYPE_WATER;

					switch (effect->effect) {
					case PADEFFECT_SPLASH:
						type = SMOKETYPE_WATER;
						break;
					case PADEFFECT_SMOKE:
					case PADEFFECT_OUTROSMOKE:
						type = SMOKETYPE_DEBRIS;
						break;
					}

					rooms2[0] = pad->room;
					rooms2[1] = -1;

					smokeCreateAtPadEffect(effect, &pad->pos, rooms2, type);
					break;
				case PADEFFECT_01:
					break;
				}
			}
		}
	}
}

void propSetPerimEnabled(struct prop *prop, s32 enable)
{
	if (prop->type == PROPTYPE_CHR) {
		chrSetPerimEnabled(prop->chr, enable);
	} else if (prop->type == PROPTYPE_PLAYER) {
		playerSetPerimEnabled(prop, enable);
	} else if (prop->type & (PROPTYPE_OBJ | PROPTYPE_DOOR | PROPTYPE_WEAPON)) {
		objSetPerimEnabled(prop, enable);
	}
}

void propsTestForPickup(void)
{
	s16 *propnumptr;
	s32 i;
	s16 propnums[256];
	s16 allrooms[21];
	s16 tmp[11];

	if (g_Vars.currentplayer->bondmovemode != MOVEMODE_CUTSCENE
			&& !g_PlayerInvincible
			&& g_Vars.currentplayer != g_Vars.anti
			&& g_Vars.currentplayer->vv_verta * M_BADTAU / 360.0f >= -0.7852731347084f) {
		roomsCopy(g_Vars.currentplayer->prop->rooms, allrooms);

		for (i = 0; g_Vars.currentplayer->prop->rooms[i] != -1; i++) {
			roomGetNeighbours(g_Vars.currentplayer->prop->rooms[i], tmp, 10);
			roomsAppend(tmp, allrooms, 20);
		}

		roomGetProps(allrooms, propnums, 256);
		propnumptr = propnums;

		while (*propnumptr >= 0) {
			struct prop *prop = &g_Vars.props[*propnumptr];
			s32 op = TICKOP_NONE;

			if (prop->timetoregen <= 0 && prop->obj) {
				if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) {
					op = objTestForPickup(prop);
				}
			}

			propExecuteTickOperation(prop, op);

			propnumptr++;
		}
	}
}

static f32 func0f06438c(struct prop *prop, struct coord *arg1, f32 *arg2, f32 *arg3, f32 *arg4)
{
	f32 spa0[2];
	struct coord sp94;
	f32 sp8c[2];
	f32 sp84[2];
	f32 sp7c[2];
	f32 sp74[2];
	f32 sp70;
	f32 sp6c;
	f32 top;
	f32 bottom;
	f32 left;
	f32 right;
	f32 result = -2;
	struct weaponfunc *func = currentPlayerGetWeaponFunction(HAND_RIGHT);
	bool sp50 = false;
	bool sp4c;
	f32 sp48;
	struct prop *playerprop;
	s32 ok;

	if (func && bgun0f0a27c8()) {
		sp50 = true;
	}

	if (sp50) {
		top = g_Vars.currentplayer->c_screentop;
		bottom = g_Vars.currentplayer->c_screentop + g_Vars.currentplayer->c_screenheight;
		left = g_Vars.currentplayer->c_screenleft;
		right = g_Vars.currentplayer->c_screenleft + g_Vars.currentplayer->c_screenwidth;
	} else {
		top = g_Vars.currentplayer->c_screentop + g_Vars.currentplayer->c_screenheight * 0.175f;
		bottom = g_Vars.currentplayer->c_screentop + g_Vars.currentplayer->c_screenheight * 0.825f;
		left = g_Vars.currentplayer->c_screenleft + g_Vars.currentplayer->c_screenwidth * 0.25f;
		right = g_Vars.currentplayer->c_screenleft + g_Vars.currentplayer->c_screenwidth * 0.75f;
	}

	if (arg1->z > -2.5f) {
		return -1;
	}

	cam0f0b4d04(arg1, spa0);
	sp94.x = arg2[0];
	sp94.y = arg1->y;
	sp94.z = arg1->z;
	cam0f0b4d04(&sp94, sp8c);
	sp94.x = arg2[1];
	sp94.y = arg1->y;
	sp94.z = arg1->z;
	cam0f0b4d04(&sp94, sp84);
	sp94.x = arg1->x;
	sp94.y = arg3[1];
	sp94.z = arg1->z;
	cam0f0b4d04(&sp94, sp7c);
	sp94.x = arg1->x;
	sp94.y = arg3[0];
	sp94.z = arg1->z;
	cam0f0b4d04(&sp94, sp74);

	if (sp74[1] >= top && bottom >= sp7c[1]) {
		sp4c = false;
		bgunGetCrossPos(&sp70, &sp6c);
		sp8c[0] = floorf(sp8c[0]);
		sp84[0] = ceilf(sp84[0]);

		if (sp8c[0] <= right && left <= sp84[0]) {
			sp48 = (sp84[0] - sp8c[0]) * 1.5f;

			if (!g_Vars.normmplayerisrunning) {
				sp48 = sp48 * g_AutoAimScale;
			}

			sp4c = g_Vars.currentplayer->c_screenleft + 0.5f * g_Vars.currentplayer->c_screenwidth >= (sp8c[0] + sp84[0]) * 0.5f - sp48
				&& g_Vars.currentplayer->c_screenleft + 0.5f * g_Vars.currentplayer->c_screenwidth <= (sp8c[0] + sp84[0]) * 0.5f + sp48
				&& left <= spa0[0]
				&& right >= spa0[0];
		}

		if (sp4c) {
			playerprop = g_Vars.currentplayer->prop;

			playerSetPerimEnabled(playerprop, false);

			ok = cdTestLos03(&playerprop->pos, playerprop->rooms, &prop->pos,
					CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_PATHBLOCKER | CDTYPE_BG,
					GEOFLAG_BLOCK_SHOOT);

			if (ok) {
				f32 value = spa0[1];

				if (value < top) {
					value = top;
				} else if (value > bottom) {
					value = bottom;
				}

				arg4[1] = value;

				{
					f32 value = spa0[0];

					if (value < left) {
						value = left;
					} else if (value > right) {
						value = right;
					}

					arg4[0] = value;
				}

				if (g_Vars.currentplayer->c_screenleft + 0.5f * g_Vars.currentplayer->c_screenwidth >= sp8c[0]
						&& g_Vars.currentplayer->c_screenleft + 0.5f * g_Vars.currentplayer->c_screenwidth <= sp84[0]) {
					result = 1;
				} else if (g_Vars.currentplayer->c_screenleft + 0.5f * g_Vars.currentplayer->c_screenwidth >= sp8c[0]) {
					result = 1 - ((g_Vars.currentplayer->c_screenleft + 0.5f * g_Vars.currentplayer->c_screenwidth) - sp84[0]) / sp48;
				} else {
					result = 1 - (sp8c[0] - (g_Vars.currentplayer->c_screenleft + 0.5f * g_Vars.currentplayer->c_screenwidth)) / sp48;
				}
			}

			playerSetPerimEnabled(playerprop, true);
		}
	}

	return result;
}

static void farsightChooseTarget(void)
{
	struct prop *besttarget = NULL;
	f32 bestthing = 1;
	f32 bestdist = -1;
	s32 weaponnum = bgunGetWeaponNum(HAND_RIGHT);
	s32 i;

	if (weaponnum == WEAPON_FARSIGHT) {
		s32 numchrs = g_NumChrSlots;

		for (i = numchrs - 1; i >= 0; i--) {
			struct prop *prop = g_ChrSlots[i].prop;

			if (prop && prop->chr) {
				if ((prop->type == PROPTYPE_CHR && (prop->flags & PROPFLAG_ENABLED))
						|| (prop->type == PROPTYPE_PLAYER && playermgrGetPlayerNumByProp(prop) != g_Vars.currentplayernum)) {
					struct chrdata *chr = prop->chr;

					if ((chr->chrflags & CHRCFLAG_UNEXPLODABLE) == 0
							&& !chrCompareTeams(g_Vars.currentplayer->prop->chr, chr, COMPARE_FRIENDS)
							&& chr->actiontype != ACT_DIE
							&& chr->actiontype != ACT_DRUGGEDDROP
							&& chr->actiontype != ACT_DRUGGEDKO
							&& chr->actiontype != ACT_DEAD
							&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
							&& (prop->type != PROPTYPE_PLAYER || !g_Vars.players[playermgrGetPlayerNumByProp(prop)]->isdead)) {
						f32 xdist = g_Vars.currentplayer->bond2.unk10.x - prop->pos.x;
						f32 ydist = g_Vars.currentplayer->bond2.unk10.y - prop->pos.y;
						f32 zdist = g_Vars.currentplayer->bond2.unk10.z - prop->pos.z;

						f32 dist = sqrtf(xdist * xdist + ydist * ydist + zdist * zdist);

						if (dist > 0) {
							f32 thing = (xdist * g_Vars.currentplayer->bond2.unk1c.f[0]
									+ ydist * g_Vars.currentplayer->bond2.unk1c.f[1]
									+ zdist * g_Vars.currentplayer->bond2.unk1c.f[2]) / dist;

							if (thing < 0 && thing < bestthing) {
								bestthing = thing;
								besttarget = prop;
								bestdist = dist;
							}
						}
					}
				}
			}
		}
	}

	g_Vars.currentplayer->autoeraserdist = bestdist;
	g_Vars.currentplayer->autoerasertarget = besttarget;
}

static struct prop *autoaimFindBestCmpProp(f32 aimpos[2])
{
	struct prop *bestprop = NULL;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->trackedprops); i++) {
		struct trackedprop *trackedprop = &g_Vars.currentplayer->trackedprops[i];

		if (trackedprop->prop
				&& (trackedprop->x1 >= 0 || trackedprop->x2 >= 0)
				&& (trackedprop->y1 >= 0 || trackedprop->y2 >= 0)) {
			// Define the aim limits
			f32 top = g_Vars.currentplayer->c_screentop + g_Vars.currentplayer->c_screenheight * 0.125f;
			f32 bottom = g_Vars.currentplayer->c_screentop + g_Vars.currentplayer->c_screenheight * 0.875f;
			f32 left = g_Vars.currentplayer->c_screenleft + g_Vars.currentplayer->c_screenwidth * 0.125f;
			f32 right = g_Vars.currentplayer->c_screenleft + g_Vars.currentplayer->c_screenwidth * 0.875f;
			struct chrdata *chr = NULL;

			bestprop = trackedprop->prop;

			if (bestprop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
				// trackedprop is an object
				aimpos[0] = (trackedprop->x2 + trackedprop->x1) / 2;
				aimpos[1] = (trackedprop->y2 + trackedprop->y1) / 2;

				if (bestprop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
					struct defaultobj *obj = bestprop->obj;
					Mtxf *mtx = model0001a60c(obj->model);
					struct coord spac;
					spac.z = mtx->m[3][2];

					if (spac.z < 0) {
						spac.x = mtx->m[3][0];
						spac.y = mtx->m[3][1];
						cam0f0b4d04(&spac, aimpos);
					}
				}
			} else {
				// trackedprop is a chr
				chr = bestprop->chr;
				aimpos[0] = (trackedprop->x2 + trackedprop->x1) / 2;

				if (chr && chr->race == RACE_EYESPY) {
					aimpos[1] = (trackedprop->y2 + trackedprop->y1) >> 1;
				} else {
					// Aim 2/3 up the chr, so about their chest
					aimpos[1] = (trackedprop->y2 + trackedprop->y1 * 2) / 3;
				}
			}

			// Constrain aimpos to the aim limits
			if (aimpos[0] > right) {
				aimpos[0] = right;
			}

			if (aimpos[0] < left) {
				aimpos[0] = left;
			}

			if (aimpos[1] > bottom) {
				aimpos[1] = bottom;
			}

			if (aimpos[1] < top) {
				aimpos[1] = top;
			}

			// Don't use this prop if it's an undeployed eyespy, or if
			// the trackedprop is outside of the aim limits
			if (chr && chr->race == RACE_EYESPY) {
				struct eyespy *eyespy = chrToEyespy(chr);

				if (eyespy == NULL || !eyespy->deployed) {
					bestprop = NULL;
					aimpos[0] = aimpos[1] = 0;
				}
			} else if (aimpos[0] > trackedprop->x2
					|| aimpos[0] < trackedprop->x1
					|| aimpos[1] > trackedprop->y2
					|| aimpos[1] < trackedprop->y1) {
				bestprop = NULL;
				aimpos[0] = aimpos[1] = 0;
			}
		}

		if (bestprop) {
			break;
		}
	}

	return bestprop;
}

static struct prop *autoaimFindGeneralProp(f32 aimpos[2])
{
	struct prop *bestprop = NULL;
	f32 bestthing = -1;
	struct prop *prop;
	struct coord sp94;
	f32 sp8c[2];
	f32 sp84[2];
	struct chrdata *chr;
	f32 sp78[2];
	struct prop **ptr = g_Vars.endonscreenprops - 1;

	// Iterate onscreen props near to far
	while (ptr >= g_Vars.onscreenprops) {
		prop = *ptr;

		if (prop && prop->chr) {
			if (prop->type == PROPTYPE_CHR
					|| (prop->type == PROPTYPE_PLAYER && playermgrGetPlayerNumByProp(prop) != g_Vars.currentplayernum)) {
				chr = prop->chr;

				if (!chrCompareTeams(g_Vars.currentplayer->prop->chr, chr, COMPARE_FRIENDS)
						&& (chrGetHeldProp(chr, HAND_RIGHT)
							|| chrGetHeldProp(chr, HAND_LEFT)
							|| (chr->chrflags & CHRCFLAG_FORCEAUTOAIM)
							|| chr->gunprop)
						&& chrCalculateAutoAim(prop, &sp94, sp8c, sp84)) {
					f32 thing = func0f06438c(prop, &sp94, sp8c, sp84, sp78);

					if (thing > bestthing) {
						bestthing = thing;
						aimpos[0] = sp78[0];
						aimpos[1] = sp78[1];
						bestprop = prop;

						if (thing >= 1) {
							break;
						}
					}
				}
			}
		}

		ptr--;
	}

	return bestprop;
}

static void autoaimSetProp(struct prop *prop, f32 aimpos[2])
{
	if (prop) {
		f32 x = (aimpos[0] - g_Vars.currentplayer->c_screenleft) / (g_Vars.currentplayer->c_screenwidth * 0.5f) - 1;
		f32 y = (aimpos[1] - g_Vars.currentplayer->c_screentop) / (g_Vars.currentplayer->c_screenheight * 0.5f) - 1;
		bmoveUpdateAutoAimProp(prop, x, y);
	} else {
		bmoveUpdateAutoAimProp(NULL, 0, 0);
	}
}

void autoaimTick(void)
{
	struct prop *bestprop;
	f32 aimpos[2] = {0, 0};
	s32 weaponnum = bgunGetWeaponNum(HAND_RIGHT);
	bool cangangsta = weaponHasFlag(weaponnum, WEAPONFLAG_GANGSTA);

	g_Vars.currentplayer->gunctrl.gangsta = false;

	if (bmoveIsAutoAimEnabledForCurrentWeapon() || cangangsta) {
		// Standard auto aim
		bestprop = autoaimFindGeneralProp(aimpos);
		autoaimSetProp(bestprop, aimpos);

		if (bestprop && cangangsta) {
			f32 xdist = g_Vars.currentplayer->bond2.unk10.x - bestprop->pos.x;
			f32 ydist = g_Vars.currentplayer->bond2.unk10.y - bestprop->pos.y;
			f32 zdist = g_Vars.currentplayer->bond2.unk10.z - bestprop->pos.z;
			f32 sqdist = xdist * xdist + ydist * ydist + zdist * zdist;

			if (sqdist < 40000) {
				g_Vars.currentplayer->gunctrl.gangsta = true;
			}
		}
	} else if (weaponnum == WEAPON_CMP150 && g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponfunc == FUNC_SECONDARY) {
		// For CMP on secondary mode, find the first prop that is within the aim limits
		bestprop = autoaimFindBestCmpProp(aimpos);
		autoaimSetProp(bestprop, aimpos);
	} else if (weaponnum == WEAPON_FARSIGHT) {
		if (frIsInTraining()) {
			frChooseFarsightTarget();
		} else {
			farsightChooseTarget();
		}

		bmoveUpdateAutoAimProp(NULL, 0, 0);
	} else {
		bmoveUpdateAutoAimProp(NULL, 0, 0);
	}
}

u32 propDoorGetCdTypes(struct prop *prop)
{
	struct doorobj *door = prop->door;
	u32 types;

	if (door->frac <= 0) {
		types = CDTYPE_CLOSEDDOORS;
	} else if (door->frac >= door->maxfrac) {
		types = CDTYPE_OPENDOORS;
	} else {
		types = CDTYPE_AJARDOORS;
	}

	if (door->base.flags2 & OBJFLAG2_AICANNOTUSE) {
		types |= CDTYPE_DOORSLOCKEDTOAI;
	}

	return types;
}

bool propIsOfCdType(struct prop *prop, u32 types)
{
	bool result = true;

	if (prop->type == PROPTYPE_DOOR) {
		if (types & CDTYPE_AIOPAQUE) {
			struct defaultobj *obj = prop->obj;

			if (obj->flags & OBJFLAG_AISEETHROUGH) {
				result = false;
			}
		}

		if (types & CDTYPE_DOORSWITHOUTFLAG) {
			struct defaultobj *obj = prop->obj;

			if (obj->flags3 & OBJFLAG3_80000000) {
				result = false;
			}
		}

		if ((types & CDTYPE_DOORS) == 0) {
			if ((propDoorGetCdTypes(prop) & types) == 0) {
				result = false;
			}
		}
	} else if (prop->type == PROPTYPE_PLAYER) {
		if ((types & CDTYPE_PLAYERS) == 0) {
			result = false;
		} else {
			struct player *player = g_Vars.players[playermgrGetPlayerNumByProp(prop)];

			if (!player->bondperimenabled || (g_Vars.mplayerisrunning && player->isdead)) {
				result = false;
			}
		}
	} else if (prop->type == PROPTYPE_CHR) {
		if ((types & CDTYPE_CHRS) == 0) {
			result = false;
		} else {
			struct chrdata *chr = prop->chr;

			if (chr->actiontype == ACT_DEAD
					|| (chr->chrflags & (CHRCFLAG_HIDDEN | CHRCFLAG_PERIMDISABLEDTMP))
					|| (chr->hidden & CHRHFLAG_PERIMDISABLED)) {
				result = false;
			}
		}
	} else if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) {
		struct defaultobj *obj = prop->obj;

		if (obj->unkgeo == NULL) {
			result = false;
		} else {
			if ((types & CDTYPE_AIOPAQUE) && (obj->flags & OBJFLAG_AISEETHROUGH)) {
				result = false;
			}

			if ((types & CDTYPE_OBJSWITHFLAG)
					&& (obj->flags & OBJFLAG_INVINCIBLE) == 0
					&& (obj->flags2 & OBJFLAG2_IMMUNETOGUNFIRE) == 0) {
				result = false;
			}

			if ((types & CDTYPE_OBJSWITHFLAG2)
					&& (obj->flags & OBJFLAG_INVINCIBLE) == 0
					&& (obj->flags2 & OBJFLAG2_00200000) == 0) {
				result = false;
			}

			if ((obj->flags & OBJFLAG_PATHBLOCKER)) {
				if ((types & CDTYPE_PATHBLOCKER) == 0) {
					result = false;
				}
			} else {
				if ((types & CDTYPE_OBJS) == 0) {
					result = false;
				}
			}
		}
	}

	return result;
}

void roomsCopy(s16 *src, s16 *dst)
{
	s16 *srcptr = src;
	s16 *dstptr = dst;
	s32 val;

	while ((val = *srcptr) != -1) {
		*dstptr = val;
		srcptr++;
		dstptr++;
	}

	*dstptr = -1;
}

/**
 * Append newrooms to dstrooms without duplicates.
 */
void roomsAppend(s16 *newrooms, s16 *dstrooms, s32 maxlen)
{
	s32 i;

	for (i = 0; newrooms[i] != -1; i++) {
		s32 j;

		for (j = 0; dstrooms[j] != -1 && dstrooms[j] != newrooms[i]; j++);

		if (dstrooms[j] == -1 && j < maxlen) {
			dstrooms[j] = newrooms[i];
			dstrooms[j + 1] = -1;
		}
	}
}

bool arrayIntersects(s16 *a, s16 *b)
{
	s16 *aptr = a;
	s16 aval = *aptr;
	s16 *bptr;
	s16 bval;

	while (aval != -1) {
		bptr = b; bval = *bptr;

		while (bval != -1) {
			if (aval == bval) {
				return true;
			}

			bptr++;
			bval = *bptr;
		}

		aptr++;
		aval = *aptr;
	}

	return false;
}

static bool propTryAddToChunk(s16 propnum, s32 chunkindex)
{
	struct roomproplistchunk *chunk = &g_RoomPropListChunks[chunkindex];

	if (chunk->count < ARRAYCOUNT(chunk->propnums)) {
		chunk->propnums[chunk->count] = propnum;
		chunk->count++;
		return true;
	}

	return false;
}

static s32 roomAllocatePropListChunk(s32 room, s32 prevchunkindex)
{
	u32 i;

	static u32 nextindex = 0;

	for (i = 0; i < 256; i++) {
		s32 index = (nextindex + i) % 256;

		if (g_RoomPropListChunks[index].count == 0) {
			g_RoomPropListChunks[index].next = -1;

			if (prevchunkindex >= 0) {
				g_RoomPropListChunks[prevchunkindex].next = index;
			} else {
				g_RoomPropListChunkIndexes[room] = index;
			}

			nextindex = (index + 1) % 256;

			return index;
		}
	}

	return -1;
}

static void propRegisterRoom(struct prop *prop, s16 room)
{
	s32 prev = -1;
	s32 i;
	s32 j;

	if (room >= 0 && room < g_Vars.roomcount) {
		for (j = 0; j < 2; j++) {
			// Find which chunk to start at
			s32 chunkindex = g_RoomPropListChunkIndexes[room];
			s16 propnum = prop - g_Vars.props;

			for (i = 0; chunkindex >= 0; i++) {
				if (propTryAddToChunk(propnum, chunkindex)) {
					return;
				}

				prev = chunkindex;
				chunkindex = g_RoomPropListChunks[chunkindex].next;
			}

			// Allocate a new chunk
			chunkindex = roomAllocatePropListChunk(room, prev);

			if (chunkindex >= 0) {
				propTryAddToChunk(propnum, chunkindex);
				return;
			}

			// Out of chunks - defrag and try again
			propsDefragRoomProps();
		}
	}
}

static void propDeregisterRoom(struct prop *prop, s16 room)
{
	s32 prev = -1;

	if (room >= 0 && room < g_Vars.roomcount) {
		// Find which chunk to start at
		s32 chunkindex = g_RoomPropListChunkIndexes[room];
		s16 propnum = prop - g_Vars.props;

		while (chunkindex >= 0) {
			struct roomproplistchunk *chunk = &g_RoomPropListChunks[chunkindex];
			s32 j;

			// Iterate propnums in this chunk
			for (j = 0; j < chunk->count; j++) {
				if (chunk->propnums[j] == propnum) {
					chunk->propnums[j] = chunk->propnums[chunk->count - 1];
					chunk->count--;

					if (chunk->count <= 0) {
						// This chunk is now empty
						if (prev >= 0) {
							g_RoomPropListChunks[prev].next = g_RoomPropListChunks[chunkindex].next;
						} else {
							g_RoomPropListChunkIndexes[room] = g_RoomPropListChunks[chunkindex].next;
						}
					}

					return;
				}
			}

			prev = chunkindex;
			chunkindex = g_RoomPropListChunks[chunkindex].next;
		}
	}
}

/**
 * Remove a prop from the room registration system.
 * The prop's rooms list is unchanged.
 *
 * Room registration is used to look up props by room number.
 */
void propDeregisterRooms(struct prop *prop)
{
	s16 *rooms = prop->rooms;
	s16 room = *rooms;

	while (room != -1) {
		propDeregisterRoom(prop, room);
		rooms++;
		room = *rooms;
	}
}

/**
 * Add a prop to the room registration system based on its rooms list.
 *
 * Room registration is used to look up props by room number.
 */
void propRegisterRooms(struct prop *prop)
{
	s16 *rooms = prop->rooms;
	s16 room = *rooms;

	while (room != -1) {
		propRegisterRoom(prop, room);
		rooms++;
		room = *rooms;
	}
}

void func0f065d1c(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms, s16 *morerooms, u32 arg5)
{
	s16 stackrooms[8];
	s32 index;
	s32 i;

	portal00018148(pos, newpos, rooms, stackrooms, morerooms, arg5);

	index = 0;

	for (i = 0; stackrooms[i] != -1; i++) {
		if (roomContainsCoord(newpos, stackrooms[i])) {
			newrooms[index] = stackrooms[i];
			index++;
		}
	}

	newrooms[index] = -1;
}

void func0f065dd8(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms)
{
	func0f065d1c(pos, rooms, newpos, newrooms, NULL, 0);
}

void func0f065dfc(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms, s16 *morerooms, u32 arg5)
{
	func0f065d1c(pos, rooms, newpos, newrooms, morerooms, arg5);

	if (newrooms[0] == -1) {
		func0f065e98(pos, rooms, newpos, newrooms);

		if (morerooms) {
			roomsAppend(newrooms, morerooms, arg5);
		}
	}
}

void func0f065e74(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms)
{
	func0f065dfc(pos, rooms, newpos, newrooms, NULL, 0);
}

void func0f065e98(struct coord *pos, s16 *rooms, struct coord *pos2, s16 *dstrooms)
{
	s16 inrooms[21];
	s16 aboverooms[21];
	s16 *ptr = NULL;
	s32 i;

	bgFindRoomsByPos(pos2, inrooms, aboverooms, 20, NULL);

	if (inrooms[0] != -1) {
		ptr = inrooms;
	} else if (aboverooms[0] != -1) {
		ptr = aboverooms;
	}

	if (ptr) {
		s32 room = cdFindFloorRoomAtPos(pos2, ptr);

		if (room > 0) {
			dstrooms[0] = room;
			dstrooms[1] = -1;
		} else {
			dstrooms[0] = *ptr;
			dstrooms[1] = -1;
		}
	} else {
		for (i = 0; rooms[i] != -1; i++) {
			dstrooms[i] = rooms[i];
		}

		dstrooms[i] = -1;
	}
}

/**
 * Given a list of rooms (terminated by -1), and a pointer to an empty
 * allocation of propnums, populate the propnums list based on which props are
 * in any of those rooms.
 *
 * @dangerous: The len argument is ignored, so array overflow will occur if
 * there are too many props in a small area. In most (if not all) invocations,
 * the caller uses an array that can hold 256 propnums, so if you can find a way
 * to get 256 props in a small space without exhausing the memory of the
 * console, you could potentially achieve arbitrary code execution.
 */
void roomGetProps(s16 *rooms, s16 *propnums, s32 len)
{
	s16 *writeptr = propnums;
	s32 room;
	s32 i;

	// Do first room without checking for duplicates
	room = *rooms;

	if (room != -1) {
		// Find the chunk to start at
		s32 chunkindex = g_RoomPropListChunkIndexes[room];

		// Iterate the chunks
		while (chunkindex >= 0) {
			struct roomproplistchunk *chunk = &g_RoomPropListChunks[chunkindex];

			// Iterate the propnums within each chunk
			for (i = 0; i < chunk->count; i++) {
				*writeptr = chunk->propnums[i];
				writeptr++;
			}

			chunkindex = chunk->next;
		}

		rooms++;
		room = *rooms;
	}

	// Do subsequent rooms with duplicate checks

	// Iterate rooms
	while (room != -1) {
		// Find the chunk to start at
		s32 chunkindex = g_RoomPropListChunkIndexes[room];

		// Iterate the chunks
		while (chunkindex >= 0) {
			struct roomproplistchunk *chunk = &g_RoomPropListChunks[chunkindex];

			// Iterate the propnums within each chunk
			for (i = 0; i < chunk->count; i++) {
				s16 propnum = chunk->propnums[i];

				// Check if it's in the list already
				s16 *ptr = propnums;

				while (ptr < writeptr) {
					if (*ptr == propnum) {
						break;
					}

					ptr++;
				}

				if (ptr == writeptr) {
					*writeptr = propnum;
					writeptr++;
				}
			}

			chunkindex = chunk->next;
		}

		rooms++;
		room = *rooms;
	}

	*writeptr = -1;
}

static void propsDefragRoomProps(void)
{
	s32 i;
	s32 j;

	// Iterate rooms
	for (i = 0; i < g_Vars.roomcount; i++) {
		s32 previndex = g_RoomPropListChunkIndexes[i];

		if (previndex >= 0) {
			s32 nextindex = g_RoomPropListChunks[previndex].next;

			// Iterate this room's chunks but skip the first
			while (nextindex >= 0) {
				// Iterate empty slots within this chunk
				for (j = g_RoomPropListChunks[previndex].count; j < ARRAYCOUNT(g_RoomPropListChunks[previndex].propnums); j++) {
					// Iterate forward through the chunk list and find a
					// propnum to move back to the prev chunk
					if (g_RoomPropListChunks[nextindex].count > 0) {
						g_RoomPropListChunks[previndex].propnums[j] = g_RoomPropListChunks[nextindex].propnums[g_RoomPropListChunks[nextindex].count - 1];
						g_RoomPropListChunks[nextindex].count--;
						g_RoomPropListChunks[previndex].count++;
					}

					// Check if next chunk is empty
					if (g_RoomPropListChunks[nextindex].count <= 0) {
						g_RoomPropListChunks[nextindex].count = 0;
						g_RoomPropListChunks[previndex].next = g_RoomPropListChunks[nextindex].next;

						nextindex = g_RoomPropListChunks[previndex].next;

						if (nextindex < 0) {
							break;
						}
					}
				}

				if (nextindex >= 0) {
					previndex = nextindex;
					nextindex = g_RoomPropListChunks[nextindex].next;
				}
			}
		}
	}
}

void propGetBbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin)
{
	if (prop->type == PROPTYPE_CHR) {
		chrGetBbox(prop, radius, ymax, ymin);
	} else if (prop->type == PROPTYPE_PLAYER) {
		playerGetBbox(prop, radius, ymax, ymin);
	} else if (prop->type & (PROPTYPE_OBJ | PROPTYPE_DOOR)) {
		objGetBbox(prop, radius, ymax, ymin);
	} else {
		*radius = 0;
		*ymin = 0;
		*ymax = 0;
	}
}

bool propUpdateGeometry(struct prop *prop, u8 **start, u8 **end)
{
	bool result = false;

	if (prop->type == PROPTYPE_PLAYER) {
		result = playerUpdateGeometry(prop, start, end);
	} else if (prop->type == PROPTYPE_CHR) {
		result = chrUpdateGeometry(prop, start, end);
	} else if (prop->type & (PROPTYPE_OBJ | PROPTYPE_DOOR)) {
		result = objUpdateGeometry(prop, start, end);
	}

	return result;
}
