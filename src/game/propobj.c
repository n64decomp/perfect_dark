#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/bondwalk.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/chrai.h"
#include "game/dlights.h"
#include "game/nbomb.h"
#include "game/playerreset.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/setuputils.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/game_096360.h"
#include "game/atan2f.h"
#include "game/acosfasinf.h"
#include "game/quaternion.h"
#include "game/floor.h"
#include "game/ceil.h"
#include "game/bondgun.h"
#include "game/gunfx.h"
#include "game/game_0b0fd0.h"
#include "game/modelmgr.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/portal.h"
#include "game/player.h"
#include "game/game_0c33f0.h"
#include "game/hudmsg.h"
#include "game/menu.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/game_1291b0.h"
#include "game/vtxstore.h"
#include "game/explosions.h"
#include "game/smoke.h"
#include "game/sparks.h"
#include "game/game_1531a0.h"
#include "game/bg.h"
#include "game/stagetable.h"
#include "game/env.h"
#include "game/gfxmemory.h"
#include "game/lv.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/mpstats.h"
#include "game/bot.h"
#include "game/botact.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/options.h"
#include "game/propobj.h"
#include "game/wallhit.h"
#include "game/shards.h"
#include "bss.h"
#include "tvcmds.h"
#include "lib/vi.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/str.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "lib/path.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "lib/lib_17ce0.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "textures.h"
#include "types.h"
#include "string.h"

static f32 objGetRotatedLocalMin(struct modelrodata_bbox *bbox, f32 arg1, f32 arg2, f32 arg3);
static f32 objGetRotatedLocalMax(struct modelrodata_bbox *bbox, f32 arg1, f32 arg2, f32 arg3);
static void func0f070ca0(struct defaultobj *obj, struct geotilef *tile, u32 flags, struct modelrodata_bbox *bbox, struct modelrodata_type19 *rodata);
static bool func0f0849dc(struct model *model, struct modelnode *nodearg, struct coord *arg2, struct coord *arg3, struct hitthing *hitthing, s32 *dstmtxindex, struct modelnode **dstnode);
static void objDeform(struct defaultobj *obj, s32 level);
static void weaponRegisterProxy(struct weaponobj *weapon);
static void weaponUnregisterProxy(struct weaponobj *weapon);
static bool doorIsRangeEmpty(struct doorobj *door);
static void func0f08c424(struct doorobj *door, Mtxf *matrix);
static void objCreateDebris(struct defaultobj *obj, struct prop *prop);
static struct defaultobj *debrisAllocate(void);
static void doorPlayOpeningSound(s32 soundtype, struct prop *prop);
static void doorPlayOpenedSound(s32 soundtype, struct prop *prop);
static void doorSetMode(struct doorobj *door, s32 newmode);
static s32 doorIsClosed(struct doorobj *door);
static s32 doorIsOpen(struct doorobj *door);
static void liftGoToStop(struct liftobj *lift, s32 stopnum);
static void doorsCalcFrac(struct doorobj *door);
static bool posIsInFrontOfDoor(struct coord *pos, struct doorobj *door);
static void doorsActivate(struct prop *doorprop, bool allowliftclose);

struct weaponobj *g_Proxies[30];
s32 g_NumProxies;
s32 g_MaxWeaponSlots;
s32 g_MaxAmmoCrates;
s32 g_MaxDebrisSlots;
s32 g_MaxProjectiles;
s32 g_MaxEmbedments;
struct weaponobj *g_WeaponSlots;
struct ammocrateobj *g_AmmoCrates;
struct defaultobj *g_DebrisSlots;
struct projectile *g_Projectiles;
struct embedment *g_Embedments;

u32 g_TintedGlassEnabled = 0;
s32 g_AlarmTimer = 0;
struct sndstate *g_AlarmAudioHandle = NULL;
f32 g_AlarmSpeakerWeight = 64;
f32 g_AlarmSpeakerDirection = 1;
u32 g_CountdownTimerOff = COUNTDOWNTIMERREASON_AI;
bool g_CountdownTimerRunning = false;
f32 g_CountdownTimerValue60 = 0;
u32 g_PlayersDetonatingMines = 0x00000000;
s32 g_NextWeaponSlot = 0;
struct linkliftdoorobj *g_LiftDoors = NULL;
struct linksceneryobj *g_LinkedScenery = NULL;
struct blockedpathobj *g_BlockedPaths = NULL;
struct prop *g_EmbedProp = NULL;
s32 g_EmbedHitPart = 0;
u32 g_EmbedSide = 0x00000000;
s16 var8006993c[3] = {0};
u32 var80069944 = 0x00000000;
f32 g_CctvWaitScale = 1;
f32 g_AutogunAccuracyScale = 1;
f32 g_AutogunDamageTxScale = 1;
f32 g_AutogunDamageRxScale = 1;
f32 g_AmmoQuantityScale = 1;
struct padeffectobj *g_PadEffects = NULL;
s32 g_LastPadEffectIndex = -1;
struct autogunobj *g_ThrownLaptops = NULL;
struct beam *g_ThrownLaptopBeams = NULL;
s32 g_MaxThrownLaptops = 0;

/**
 * Attempt to call a lift from the given door.
 *
 * Returns true if the door activation was handled by this function, or false
 * if the caller should proceed with opening or closing the door. A true return
 * doesn't necessarily mean the lift was called.
 *
 * The allowclose argument determines whether the door should be closed if the
 * lift is at the door. This is typically true when the player has activated the
 * door, and false when NPCs have activated the door. If true, doorCallLift
 * doesn't handle the activation which allows the caller to close the door.
 *
 * Lifts will not be called if it's occupied by anyone. This prevents chrs from
 * from calling lifts back when players are in them.
 */
bool doorCallLift(struct prop *doorprop, bool allowclose)
{
	struct doorobj *door = doorprop->door;
	bool handled = false;

	if (door->base.hidden & OBJHFLAG_LIFTDOOR) {
		struct linkliftdoorobj *link = g_LiftDoors;

		while (link) {
			if (doorprop == link->door && link->lift
					&& (link->lift->type & (PROPTYPE_OBJ | PROPTYPE_DOOR))) {
				bool type = link->lift->obj->type;
				handled = true;

				if (type == OBJTYPE_DOOR) {
					// This appears to be handling situations where the setup
					// file specifies a door as the lift object. It activates
					// that door, which then calls doorCallLift. This allows
					// setup files to chain lift doors to other lift doors
					// rather than directly to the lift, but this doesn't happen
					// in practice so this branch is unused.
					doorsActivate(link->lift, allowclose);
				} else if (type == OBJTYPE_LIFT) {
					if (allowclose
							&& door->base.type == OBJTYPE_DOOR
							&& !doorIsClosed(door)) {
						handled = false;
					} else {
						bool vacant = true;
						s32 numchrslots = g_NumChrSlots;
						s32 i;

						for (i = 0; i < PLAYERCOUNT(); i++) {
							if (g_Vars.players[i]->lift == link->lift) {
								vacant = false;
							}
						}

						if (vacant) {
							for (i = 0; i < numchrslots; i++) {
								/**
								 * @bug: This is missing a chrIsDead check.
								 * If a chr dies in a lift it can no longer be called.
								 */
								if (g_ChrSlots[i].prop && g_ChrSlots[i].lift == link->lift) {
									vacant = false;
									break;
								}
							}
						}

						if (vacant) {
							liftGoToStop((struct liftobj *) link->lift->obj, link->stopnum);
						}
					}
				}
			}

			link = link->next;
		}
	}

	return handled;
}

void objUpdateLinkedScenery(struct defaultobj *obj, struct prop *prop)
{
	if ((obj->hidden & OBJHFLAG_CONDITIONALSCENERY) && (obj->flags & OBJFLAG_INVINCIBLE) == 0) {
		struct linksceneryobj *link = g_LinkedScenery;

		while (link) {
			if (link->trigger == obj) {
				objCreateDebris(obj, prop);

				link->trigger->flags2 |= OBJFLAG2_INVISIBLE;
				link->trigger->hidden |= OBJHFLAG_REAPABLE;
				link->trigger->prop->forcetick;

				if (!link->trigger->prop->active) {
					propUnpause(link->trigger->prop);
				}

				if (link->unexp) {
					link->unexp->flags2 |= OBJFLAG2_INVISIBLE;
				}

				if (link->exp) {
					link->exp->flags2 &= ~OBJFLAG2_INVISIBLE;
				}

				objSetBlockedPathUnblocked(obj, true);
				return;
			}

			link = link->next;
		}
	}
}

static f32 objGetLocalXMin(struct modelrodata_bbox *bbox)
{
	return bbox->xmin;
}

static f32 objGetLocalXMax(struct modelrodata_bbox *bbox)
{
	return bbox->xmax;
}

static f32 objGetLocalYMin(struct modelrodata_bbox *bbox)
{
	return bbox->ymin;
}

static f32 objGetLocalYMax(struct modelrodata_bbox *bbox)
{
	return bbox->ymax;
}

static f32 objGetLocalZMin(struct modelrodata_bbox *bbox)
{
	return bbox->zmin;
}

static f32 objGetLocalZMax(struct modelrodata_bbox *bbox)
{
	return bbox->zmax;
}

static f32 objGetRotatedLocalXMinByMtx4(struct modelrodata_bbox *bbox, Mtxf *mtx)
{
	return objGetRotatedLocalMin(bbox, mtx->m[0][0], mtx->m[1][0], mtx->m[2][0]);
}

static f32 objGetRotatedLocalXMaxByMtx4(struct modelrodata_bbox *bbox, Mtxf *mtx)
{
	return objGetRotatedLocalMax(bbox, mtx->m[0][0], mtx->m[1][0], mtx->m[2][0]);
}

static f32 objGetRotatedLocalYMinByMtx4(struct modelrodata_bbox *bbox, Mtxf *mtx)
{
	return objGetRotatedLocalMin(bbox, mtx->m[0][1], mtx->m[1][1], mtx->m[2][1]);
}

static f32 objGetRotatedLocalYMaxByMtx4(struct modelrodata_bbox *bbox, Mtxf *mtx)
{
	return objGetRotatedLocalMax(bbox, mtx->m[0][1], mtx->m[1][1], mtx->m[2][1]);
}

static f32 objGetRotatedLocalZMinByMtx4(struct modelrodata_bbox *bbox, Mtxf *mtx)
{
	return objGetRotatedLocalMin(bbox, mtx->m[0][2], mtx->m[1][2], mtx->m[2][2]);
}

static f32 objGetRotatedLocalZMaxByMtx4(struct modelrodata_bbox *bbox, Mtxf *mtx)
{
	return objGetRotatedLocalMax(bbox, mtx->m[0][2], mtx->m[1][2], mtx->m[2][2]);
}

f32 objGetRotatedLocalXMinByMtx3(struct modelrodata_bbox *bbox, f32 realrot[3][3])
{
	return objGetRotatedLocalMin(bbox, realrot[0][0], realrot[1][0], realrot[2][0]);
}

f32 objGetRotatedLocalXMaxByMtx3(struct modelrodata_bbox *bbox, f32 realrot[3][3])
{
	return objGetRotatedLocalMax(bbox, realrot[0][0], realrot[1][0], realrot[2][0]);
}

f32 objGetRotatedLocalYMinByMtx3(struct modelrodata_bbox *bbox, f32 realrot[3][3])
{
	return objGetRotatedLocalMin(bbox, realrot[0][1], realrot[1][1], realrot[2][1]);
}

f32 objGetRotatedLocalYMaxByMtx3(struct modelrodata_bbox *bbox, f32 realrot[3][3])
{
	return objGetRotatedLocalMax(bbox, realrot[0][1], realrot[1][1], realrot[2][1]);
}

f32 objGetRotatedLocalZMinByMtx3(struct modelrodata_bbox *bbox, f32 realrot[3][3])
{
	return objGetRotatedLocalMin(bbox, realrot[0][2], realrot[1][2], realrot[2][2]);
}

f32 objGetRotatedLocalZMaxByMtx3(struct modelrodata_bbox *bbox, f32 realrot[3][3])
{
	return objGetRotatedLocalMax(bbox, realrot[0][2], realrot[1][2], realrot[2][2]);
}

static f32 objGetRotatedLocalMin(struct modelrodata_bbox *bbox, f32 arg1, f32 arg2, f32 arg3)
{
	f32 sum = 0;

	if (arg1 >= 0) {
		sum += bbox->xmin * arg1;
	} else {
		sum += bbox->xmax * arg1;
	}

	if (arg2 >= 0) {
		sum += bbox->ymin * arg2;
	} else {
		sum += bbox->ymax * arg2;
	}

	if (arg3 >= 0) {
		sum += bbox->zmin * arg3;
	} else {
		sum += bbox->zmax * arg3;
	}

	return sum;
}

static f32 objGetRotatedLocalMax(struct modelrodata_bbox *bbox, f32 arg1, f32 arg2, f32 arg3)
{
	f32 sum = 0;

	if (arg1 <= 0) {
		sum += bbox->xmin * arg1;
	} else {
		sum += bbox->xmax * arg1;
	}

	if (arg2 <= 0) {
		sum += bbox->ymin * arg2;
	} else {
		sum += bbox->ymax * arg2;
	}

	if (arg3 <= 0) {
		sum += bbox->zmin * arg3;
	} else {
		sum += bbox->zmax * arg3;
	}

	return sum;
}

static s32 objCalculateGeoBlockVertices(f32 xmin, f32 xmax, f32 ymin, f32 ymax, f32 zmin, f32 zmax, Mtxf *mtx, struct geoblock *block)
{
	s32 i;
	s32 j;
	s32 len = 0;
	s32 numindexes;
	f64 sp270[8][2];
	f64 sp1f0[8][2];
	s32 numverts;
	s32 t3 = 0;
	s32 t1 = 0;
	s32 t2 = 0;
	s32 t0 = 0;
	s32 indexes[8];
	f64 a;
	f64 b;
	f64 xmin64 = xmin;
	f64 xmax64 = xmax;
	f64 ymin64 = ymin;
	f64 ymax64 = ymax;
	f64 zmin64 = zmin;
	f64 zmax64 = zmax;
	f64 mtx00 = mtx->m[0][0];
	f64 mtx02 = mtx->m[0][2];
	f64 mtx10 = mtx->m[1][0];
	f64 mtx12 = mtx->m[1][2];
	f64 mtx20 = mtx->m[2][0];
	f64 mtx22 = mtx->m[2][2];
	f64 mtx00min = mtx00 * xmin64;
	f64 mtx02min = mtx02 * xmin64;
	f64 mtx10min = mtx10 * ymin64;
	f64 mtx12min = mtx12 * ymin64;
	f64 mtx20min = mtx20 * zmin64;
	f64 mtx22min = mtx22 * zmin64;
	f64 mtx00max = mtx00 * xmax64;
	f64 mtx02max = mtx02 * xmax64;
	f64 mtx10max = mtx10 * ymax64;
	f64 mtx12max = mtx12 * ymax64;
	f64 mtx20max = mtx20 * zmax64;
	f64 mtx22max = mtx22 * zmax64;

	sp270[0][0] = mtx00min + mtx10min + mtx20min;
	sp270[0][1] = mtx02min + mtx12min + mtx22min;
	sp270[1][0] = mtx00min + mtx10min + mtx20max;
	sp270[1][1] = mtx02min + mtx12min + mtx22max;
	sp270[2][0] = mtx00min + mtx10max + mtx20min;
	sp270[2][1] = mtx02min + mtx12max + mtx22min;
	sp270[3][0] = mtx00min + mtx10max + mtx20max;
	sp270[3][1] = mtx02min + mtx12max + mtx22max;
	sp270[4][0] = mtx00max + mtx10min + mtx20min;
	sp270[4][1] = mtx02max + mtx12min + mtx22min;
	sp270[5][0] = mtx00max + mtx10min + mtx20max;
	sp270[5][1] = mtx02max + mtx12min + mtx22max;
	sp270[6][0] = mtx00max + mtx10max + mtx20min;
	sp270[6][1] = mtx02max + mtx12max + mtx22min;
	sp270[7][0] = mtx00max + mtx10max + mtx20max;
	sp270[7][1] = mtx02max + mtx12max + mtx22max;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < len; j++) {
			f32 tmp = 0.001f;
			f64 f0 = tmp;
			a = sp270[i][0] - sp1f0[j][0];
			b = sp270[i][1] - sp1f0[j][1];

			if (a < f0 && a > -f0 && b < f0 && b > -f0) {
				break;
			}
		}

		if (j >= len) {
			sp1f0[len][0] = sp270[i][0];
			sp1f0[len][1] = sp270[i][1];
			len++;
		}
	}

	for (i = 1; i < len; i++) {
		if (sp1f0[i][0] < sp1f0[t3][0] || (sp1f0[i][0] == sp1f0[t3][0] && sp1f0[i][1] < sp1f0[t3][1])) {
			t3 = i;
		}
	}

	for (i = 1; i < len; i++) {
		if (sp1f0[t2][1] < sp1f0[i][1] || (sp1f0[i][1] == sp1f0[t2][1] && sp1f0[i][0] < sp1f0[t2][0])) {
			t2 = i;
		}
	}

	for (i = 1; i < len; i++) {
		if (sp1f0[t1][0] < sp1f0[i][0] || (sp1f0[i][0] == sp1f0[t1][0] && sp1f0[t1][1] < sp1f0[i][1])) {
			t1 = i;
		}
	}

	for (i = 1; i < len; i++) {
		if (sp1f0[i][1] < sp1f0[t0][1] || (sp1f0[i][1] == sp1f0[t0][1] && sp1f0[t0][0] < sp1f0[i][0])) {
			t0 = i;
		}
	}

	numindexes = 0;

	for (i = 0; i < len; i++) {
		if (i != t3 && i != t1 && i != t2 && i != t0) {
			indexes[numindexes] = i;
			numindexes++;
		}
	}

	numverts = 0;
	block->vertices[numverts][0] = sp1f0[t3][0];
	block->vertices[numverts][1] = sp1f0[t3][1];
	numverts++;

	if (t0 != t3) {
		for (i = 0; i < numindexes; i++) {
			s32 index = indexes[i];

			if ((sp1f0[index][0] - sp1f0[t0][0]) * (sp1f0[t3][1] - sp1f0[t0][1]) < (sp1f0[t3][0] - sp1f0[t0][0]) * (sp1f0[index][1] - sp1f0[t0][1])) {
				block->vertices[numverts][0] = sp1f0[index][0];
				block->vertices[numverts][1] = sp1f0[index][1];
				numverts++;
				break;
			}
		}

		block->vertices[numverts][0] = sp1f0[t0][0];
		block->vertices[numverts][1] = sp1f0[t0][1];
		numverts++;
	}

	if (t1 != t0) {
		for (i = 0; i < numindexes; i++) {
			s32 index = indexes[i];

			if ((sp1f0[index][0] - sp1f0[t1][0]) * (sp1f0[t0][1] - sp1f0[t1][1]) < (sp1f0[t0][0] - sp1f0[t1][0]) * (sp1f0[index][1] - sp1f0[t1][1])) {
				block->vertices[numverts][0] = sp1f0[index][0];
				block->vertices[numverts][1] = sp1f0[index][1];
				numverts++;
				break;
			}
		}

		block->vertices[numverts][0] = sp1f0[t1][0];
		block->vertices[numverts][1] = sp1f0[t1][1];
		numverts++;
	}

	if (t2 != t1) {
		for (i = 0; i < numindexes; i++) {
			s32 index = indexes[i];

			if ((sp1f0[index][0] - sp1f0[t2][0]) * (sp1f0[t1][1] - sp1f0[t2][1]) < (sp1f0[t1][0] - sp1f0[t2][0]) * (sp1f0[index][1] - sp1f0[t2][1])) {
				block->vertices[numverts][0] = sp1f0[index][0];
				block->vertices[numverts][1] = sp1f0[index][1];
				numverts++;
				break;
			}
		}
	}

	if (t2 != t1 && t3 != t2) {
		block->vertices[numverts][0] = sp1f0[t2][0];
		block->vertices[numverts][1] = sp1f0[t2][1];
		numverts++;
	}

	if (t3 != t2) {
		for (i = 0; i < numindexes; i++) {
			s32 index = indexes[i];

			if ((sp1f0[index][0] - sp1f0[t3][0]) * (sp1f0[t2][1] - sp1f0[t3][1]) < (sp1f0[t2][0] - sp1f0[t3][0]) * (sp1f0[index][1] - sp1f0[t3][1])) {
				block->vertices[numverts][0] = sp1f0[index][0];
				block->vertices[numverts][1] = sp1f0[index][1];
				numverts++;
				break;
			}
		}
	}

	for (i = 0; i < numverts; i++) {
		block->vertices[i][0] += mtx->m[3][0];
		block->vertices[i][1] += mtx->m[3][2];
	}

	return numverts;
}

static void objCalculateGeoBlockFromBboxAndMtx(struct modelrodata_bbox *bbox, Mtxf *mtx, struct geoblock *block)
{
	block->header.numvertices = objCalculateGeoBlockVertices(
			bbox->xmin, bbox->xmax, bbox->ymin, bbox->ymax, bbox->zmin, bbox->zmax, mtx, block);
	block->header.type = GEOTYPE_BLOCK;
	block->ymin = mtx->m[3][1] + objGetRotatedLocalYMinByMtx4(bbox, mtx);
	block->ymax = mtx->m[3][1] + objGetRotatedLocalYMaxByMtx4(bbox, mtx);
}

static void objCalculateGeoBlockFromNode19Data(struct modelrodata_type19 *rodata19, struct modelrodata_bbox *bbox, Mtxf *mtx, struct geoblock *block)
{
	s32 i;

	for (i = 0; i < rodata19->numvertices; i++) {
		block->vertices[i][0] = mtx->m[3][0] + mtx->m[0][0] * rodata19->vertices[i].x + mtx->m[1][0] * rodata19->vertices[i].y + mtx->m[2][0] * rodata19->vertices[i].z;
		block->vertices[i][1] = mtx->m[3][2] + mtx->m[0][2] * rodata19->vertices[i].x + mtx->m[1][2] * rodata19->vertices[i].y + mtx->m[2][2] * rodata19->vertices[i].z;
	}

	block->header.numvertices = rodata19->numvertices;
	block->header.type = GEOTYPE_BLOCK;
	block->ymin = mtx->m[3][1] + objGetRotatedLocalYMinByMtx4(bbox, mtx);
	block->ymax = mtx->m[3][1] + objGetRotatedLocalYMaxByMtx4(bbox, mtx);
}

static bool func0f0675c8(struct coord *pos, f32 arg1, struct modelrodata_bbox *bbox, Mtxf *mtx)
{
	Mtxf sp58;
	struct coord sp4c;
	struct coord sp40;
	struct coord sp34;
	struct coord sp28;

	sp34.f[0] = sp34.f[1] = sp34.f[2] = arg1;

	sp4c.x = pos->x - mtx->m[3][0];
	sp4c.y = pos->y - mtx->m[3][1];
	sp4c.z = pos->z - mtx->m[3][2];

	mtx000170e4(mtx->m, sp58.m);
	mtx4RotateVec(&sp58, &sp4c, &sp40);
	mtx4RotateVec(&sp58, &sp34, &sp28);

	if (sp28.x < 0.0f) {
		sp28.x = -sp28.x;
	}

	if (sp28.y < 0.0f) {
		sp28.y = -sp28.y;
	}

	if (sp28.z < 0.0f) {
		sp28.z = -sp28.z;
	}

	return sp40.x - sp28.x <= bbox->xmax && sp28.x + sp40.x >= bbox->xmin
		&& sp40.y - sp28.y <= bbox->ymax && sp28.y + sp40.y >= bbox->ymin
		&& sp40.z - sp28.z <= bbox->zmax && sp28.z + sp40.z >= bbox->zmin;
}

static bool func0f0677ac(struct coord *coord, struct coord *arg1, struct coord *pos,
		struct coord *normal, struct coord *up, struct coord *look,
		f32 xmin, f32 xmax, f32 ymin, f32 ymax, f32 zmin, f32 zmax)
{
	f32 xdiff = coord->x - pos->x;
	f32 ydiff = coord->y - pos->y;
	f32 zdiff = coord->z - pos->z;
	f32 f0;

	f0 = xdiff * look->f[0] + ydiff * look->f[1] + zdiff * look->f[2];

	if (f0 > arg1->z + zmax || f0 < zmin - arg1->z) {
		return false;
	}

	f0 = xdiff * up->f[0] + ydiff * up->f[1] + zdiff * up->f[2];

	if (f0 > arg1->y + ymax || f0 < ymin - arg1->y) {
		return false;
	}

	f0 = xdiff * normal->f[0] + ydiff * normal->f[1] + zdiff * normal->f[2];

	if (f0 > arg1->x + xmax || f0 < xmin - arg1->x) {
		return false;
	}

	return true;
}

static bool func0f0678f8(struct coord *coord, struct coord *arg1, s32 padnum)
{
	struct pad *pad = &g_Pads[padnum];

	return func0f0677ac(coord, arg1, &pad->pos, &pad->normal, &pad->up, &pad->look,
			pad->bbox.xmin, pad->bbox.xmax, pad->bbox.ymin, pad->bbox.ymax, pad->bbox.zmin, pad->bbox.zmax);
}

static bool func0f06797c(struct coord *coord, f32 arg1, s32 padnum)
{
	struct coord sp1c;

	sp1c.x = arg1;
	sp1c.y = arg1;
	sp1c.z = arg1;

	return func0f0678f8(coord, &sp1c, padnum);
}

bool func0f0679ac(struct model *model, f32 *max, f32 *min, f32 arg3[2], f32 arg4[2])
{
	struct modelnode *node = model->filedata->rootnode;
	bool first = true;

	while (node) {
		u32 type = node->type & 0xff;

		if (type == MODELNODETYPE_BBOX) {
			struct modelrodata_bbox *bbox = &node->rodata->bbox;
			Mtxf *mtx = model0001a5cc(model, node, 0);
			f32 dist1;
			f32 dist2;

			dist1 = objGetRotatedLocalXMaxByMtx4(bbox, mtx) + mtx->m[3][0];
			dist2 = objGetRotatedLocalXMinByMtx4(bbox, mtx) + mtx->m[3][0];

			if (arg3[0] - arg4[0] <= dist1 && arg3[0] + arg4[0] >= dist2) {
				dist1 = objGetRotatedLocalYMaxByMtx4(bbox, mtx) + mtx->m[3][1];
				dist2 = objGetRotatedLocalYMinByMtx4(bbox, mtx) + mtx->m[3][1];

				if (arg3[1] - arg4[1] <= dist1 && arg3[1] + arg4[1] >= dist2) {
					dist1 = objGetRotatedLocalZMaxByMtx4(bbox, mtx) + mtx->m[3][2];
					dist2 = objGetRotatedLocalZMinByMtx4(bbox, mtx) + mtx->m[3][2];

					if (first || dist1 > *max) {
						*max = dist1;
					}

					if (first || dist2 < *min) {
						*min = dist2;
					}

					first = false;
				}
			}
		} else {
			// empty
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	return !first;
}

static void func0f067bc4(struct model *model, f32 *max, f32 *min, s32 axis)
{
	struct modelnode *node = model->filedata->rootnode;
	bool first = true;

	while (node) {
		u32 type = node->type & 0xff;

		if (type == MODELNODETYPE_BBOX) {
			struct modelrodata_bbox *bbox = &node->rodata->bbox;
			Mtxf *mtx = model0001a5cc(model, node, 0);
			f32 dist1;
			f32 dist2;

			if (axis == 0) {
				dist1 = objGetRotatedLocalXMaxByMtx4(bbox, mtx) + mtx->m[3][0];
				dist2 = objGetRotatedLocalXMinByMtx4(bbox, mtx) + mtx->m[3][0];
			} else if (axis == 1) {
				dist1 = objGetRotatedLocalYMaxByMtx4(bbox, mtx) + mtx->m[3][1];
				dist2 = objGetRotatedLocalYMinByMtx4(bbox, mtx) + mtx->m[3][1];
			} else {
				dist1 = objGetRotatedLocalZMaxByMtx4(bbox, mtx) + mtx->m[3][2];
				dist2 = objGetRotatedLocalZMinByMtx4(bbox, mtx) + mtx->m[3][2];
			}

			if (first || dist1 > *max) {
				*max = dist1;
			}

			if (first || dist2 < *min) {
				*min = dist2;
			}

			first = false;
		} else {
			// empty
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}
}

void func0f067d88(struct model *model, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4)
{
	func0f067bc4(model, arg1, arg2, 0);
	func0f067bc4(model, arg3, arg4, 1);
}

static bool modelGetScreenCoords2(struct model *model, f32 *x2, f32 *x1, f32 *y2, f32 *y1)
{
	bool first = true;

	if (model) {
		struct modelfiledata *modeldef = model->filedata;

		if (modeldef) {
			struct modelnode *node = modeldef->rootnode;

			while (node) {
				u32 type = node->type & 0xff;

				if (type == MODELNODETYPE_BBOX) {
					struct modelrodata_bbox *bbox = &node->rodata->bbox;
					f32 sp74[2];
					f32 sp6c[2];
					f32 sp64[2];
					f32 sp5c[2];
					struct coord sp50;
					Mtxf *mtx = model0001a5cc(model, node, 0);

					if (mtx->m[3][2] < 0.0f) {
						sp50.x = mtx->m[3][0];
						sp50.y = mtx->m[3][1];
						sp50.z = mtx->m[3][2];

						sp64[0] = objGetRotatedLocalXMinByMtx4(bbox, mtx) + sp50.f[0];
						sp64[1] = objGetRotatedLocalXMaxByMtx4(bbox, mtx) + sp50.f[0];
						sp5c[0] = objGetRotatedLocalYMinByMtx4(bbox, mtx) + sp50.f[1];
						sp5c[1] = objGetRotatedLocalYMaxByMtx4(bbox, mtx) + sp50.f[1];

						func0f06803c(&sp50, sp64, sp5c, sp74, sp6c);

						if (first || sp74[0] < *x1) {
							*x1 = sp74[0];
						}

						if (first || sp6c[0] > *x2) {
							*x2 = sp6c[0];
						}

						if (first || sp74[1] < *y1) {
							*y1 = sp74[1];
						}

						if (first || sp6c[1] > *y2) {
							*y2 = sp6c[1];
						}

						first = false;
					}
				} else {
					// empty
				}

				if (node->child) {
					node = node->child;
				} else {
					while (node) {
						if (node->next) {
							node = node->next;
							break;
						}

						node = node->parent;
					}
				}
			}
		}
	}

	return first ? false : true;
}

bool modelGetScreenCoords(struct model *model, f32 *x2, f32 *x1, f32 *y2, f32 *y1)
{
	return modelGetScreenCoords2(model, x2, x1, y2, y1);
}

void func0f06803c(struct coord *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4)
{
	struct coord sp4c;
	f32 sp44[2];

	f32 aspect = g_ViBackData->aspect;
	f32 fovy = g_ViBackData->fovy;

	if (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY) {
		if (g_Vars.currentplayer->eyespy && g_Vars.currentplayer->eyespy->active) {
			fovy = 120.0f;
		}
	}

	sp4c.x = arg1[0];
	sp4c.y = arg0->y;
	sp4c.z = arg0->z;

	cam0f0b4eb8(&sp4c, sp44, fovy, aspect);

	arg3[0] = sp44[0];

	sp4c.x = arg1[1];
	sp4c.y = arg0->y;
	sp4c.z = arg0->z;

	cam0f0b4eb8(&sp4c, sp44, fovy, aspect);

	arg4[0] = sp44[0];

	sp4c.x = arg0->x;
	sp4c.y = arg2[1];
	sp4c.z = arg0->z;

	cam0f0b4eb8(&sp4c, sp44, fovy, aspect);

	arg3[1] = sp44[1];

	sp4c.x = arg0->x;
	sp4c.y = arg2[0];
	sp4c.z = arg0->z;

	cam0f0b4eb8(&sp4c, sp44, fovy, aspect);

	arg4[1] = sp44[1];
}

static struct defaultobj *objFindByPos(struct coord *pos, s16 *rooms)
{
	struct prop *prop = g_Vars.activeprops;
	u8 *sp38;
	u8 *sp34;

	while (prop) {
		if (prop->type == PROPTYPE_OBJ
				&& arrayIntersects(prop->rooms, rooms)
				&& propUpdateGeometry(prop, &sp38, &sp34)
				&& cd000266a4(pos->x, pos->z, (struct geo *)sp38)) {
			return prop->obj;
		}

		prop = prop->next;
	}

	return NULL;
}

static void projectileFree(struct projectile *projectile)
{
	if (projectile) {
		projectile->flags |= PROJECTILEFLAG_FREE;
	}
}

void projectilesUnrefOwner(struct prop *owner)
{
	s32 i;

	for (i = 0; i < g_MaxProjectiles; i++) {
		if ((g_Projectiles[i].flags & PROJECTILEFLAG_FREE) == 0
				&& g_Projectiles[i].ownerprop == owner) {
			g_Projectiles[i].ownerprop = NULL;
		}
	}
}

static void projectileReset(struct projectile *projectile)
{
	projectile->flags = 0;
	projectile->speed.x = 0;
	projectile->speed.y = 0;
	projectile->speed.z = 0;
	projectile->unk010 = 0;
	projectile->unk014 = 0;
	projectile->unk018 = 0;
	projectile->unk01c = 0;

	mtx4LoadIdentity(&projectile->mtx);

	projectile->unk060 = 1;
	projectile->ownerprop = NULL;
	projectile->unk08c = 0.05f;
	projectile->bouncecount = 0;
	projectile->bounceframe = -1;
	projectile->lastwooshframe = -1;
	projectile->flighttime240 = 0;
	projectile->unk0a4 = -1;
	projectile->droptype = DROPTYPE_DEFAULT;
	projectile->pickuptimer240 = 0;
	projectile->losttimer240 = 0;
	projectile->obj = NULL;
	projectile->unk0d8 = 0;
	projectile->smoketimer240 = 0;
	projectile->targetprop = NULL;
	projectile->pickupby = NULL;
	projectile->powerlimit240 = -1;
	projectile->unk0b8[0] = 1;
	projectile->unk0b8[1] = 1;
	projectile->unk0b8[2] = 1;
	projectile->unk0e4 = 1;
	projectile->unk098 = 0;
	projectile->unk0dc = 0;
	projectile->unk0e0 = 0;
	projectile->unk0ec = 0;
	projectile->unk0f0 = 0;
}

static struct projectile *projectileAllocate(void)
{
	s32 bestindex = -1;
	s32 i;

	// Happy path - find one that is already free
	for (i = 0; i < g_MaxProjectiles; i++) {
		if (g_Projectiles[i].flags & PROJECTILEFLAG_FREE) {
			projectileReset(&g_Projectiles[i]);
			return &g_Projectiles[i];
		}
	}

	// Find one with the lowest unk0d8 (some kind of age/timer?)
	// and some other conditions
	for (i = 0; i < g_MaxProjectiles; i++) {
		if (g_Projectiles[i].obj
				&& g_Projectiles[i].unk0d8 > 0
				&& (bestindex < 0 || g_Projectiles[i].unk0d8 < g_Projectiles[bestindex].unk0d8)) {
			bestindex = i;
		}
	}

	// If there were none, pick one at random
	if (bestindex == -1 && g_MaxProjectiles) {
		bestindex = random() % g_MaxProjectiles;
	}

	if (bestindex >= 0) {
		// Reset and return it
		if (g_Projectiles[bestindex].obj) {
			if (g_Projectiles[bestindex].obj->prop) {
				objFreeEmbedmentOrProjectile(g_Projectiles[bestindex].obj->prop);
			}

			g_Projectiles[bestindex].obj->hidden |= OBJHFLAG_REAPABLE;
		}

		projectileReset(&g_Projectiles[bestindex]);
		return &g_Projectiles[bestindex];
	} else {
		return NULL;
	}
}

void func0f0685e4(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;

	if (obj->hidden & OBJHFLAG_EMBEDDED) {
		if (obj->embedment->projectile) {
			projectileReset(obj->embedment->projectile);
		} else {
			obj->embedment->projectile = projectileAllocate();
		}
	} else if ((obj->hidden & OBJHFLAG_PROJECTILE) == 0) {
		if (obj->projectile) {
			projectileReset(obj->projectile);
		} else {
			obj->projectile = projectileAllocate();
		}

		if (obj->projectile) {
			obj->hidden |= OBJHFLAG_PROJECTILE;
		}
	}
}

void projectileSetSticky(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;
	struct projectile *projectile = NULL;

	if (obj->hidden & OBJHFLAG_EMBEDDED) {
		projectile = obj->embedment->projectile;
	} else if (obj->hidden & OBJHFLAG_PROJECTILE) {
		projectile = obj->projectile;
	}

	if (projectile) {
		projectile->flags |= PROJECTILEFLAG_STICKY;
	}
}

static void embedmentFree(struct embedment *embedment)
{
	embedment->flags |= EMBEDMENTFLAG_FREE;
}

struct embedment *embedmentAllocate(void)
{
	s32 i;

	for (i = 0; i < g_MaxEmbedments; i++) {
		if (g_Embedments[i].flags & EMBEDMENTFLAG_FREE) {
			g_Embedments[i].flags = 0;
			g_Embedments[i].projectile = NULL;

			return &g_Embedments[i];
		}
	}

	return NULL;
}

/**
 * This doesn't exactly return the number of shots taken but it's the best way
 * to describe the behaviour of the function without writing a novel into the
 * function's name.
 *
 * The number returned is 0 when at full health and only ever increments as the
 * object takes damage. While healthy, the number scales from 0 to 4 based on
 * how close it is to being destroyed, where 4 is destroyed. After being
 * destroyed, the number increments at 1 per shot up to a max of 12.
 */
static s32 objGetShotsTaken(struct defaultobj *obj)
{
	if ((obj->hidden2 & OBJH2FLAG_DESTROYED) == 0) {
		return obj->damage * 3.0f / obj->maxdamage;
	}

	return obj->damage + 4;
}

/**
 * Return 0 if not destroyed
 * Return 1 if at destroyed level 1
 * Return 2 if at destroyed level 2
 * Return 3 if at destroyed level 3
 *
 * Each destroyed level is a new phase of visual brokenness. Typically the
 * object is destroyed and it looks broken (level 1), then after a couple of
 * shots it enters level 2, and a few shots later level 3.
 *
 * While healthy, damage goes from 0 to maxdamage (eg. 1000) but this function
 * returns 0 due to the if statement.
 *
 * When destroyed, damage is reset to 0 then incremented at one unit per shot,
 * so four shots causes it to enter a new destroyed level.
 */
s32 objGetDestroyedLevel(struct defaultobj *obj)
{
	if ((obj->hidden2 & OBJH2FLAG_DESTROYED) == 0) {
		return 0;
	}

	return (obj->damage >> 2) + 1;
}

static struct modelnode *func0f0687e4(struct model *model)
{
	struct modelfiledata *filedata = model->filedata;
	struct modelnode *node = filedata->rootnode;

	while (node) {
		u32 type = node->type & 0xff;

		switch (type) {
		case MODELNODETYPE_DL:
			return node;
		case MODELNODETYPE_DISTANCE:
			model0001c784(model, node);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, node);
			break;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	return NULL;
}

static struct modelnode *modelFileDataFindBboxNode(struct modelfiledata *filedata)
{
	struct modelnode *node = filedata->rootnode;

	while (node) {
		if ((node->type & 0xff) == MODELNODETYPE_BBOX) {
			return node;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	return NULL;
}

struct modelrodata_bbox *modelFileDataFindBboxRodata(struct modelfiledata *filedata)
{
	struct modelnode *node = modelFileDataFindBboxNode(filedata);

	if (node) {
		return &node->rodata->bbox;
	}

	return NULL;
}

static struct modelnode *modelFindBboxNode(struct model *model)
{
	struct modelnode *node = model->filedata->rootnode;

	while (node) {
		u32 type = node->type & 0xff;

		switch (type) {
		case MODELNODETYPE_BBOX:
			return node;
		case MODELNODETYPE_DISTANCE:
			model0001c784(model, node);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, node);
			break;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	return NULL;
}

struct modelrodata_bbox *modelFindBboxRodata(struct model *model)
{
	struct modelnode *node = modelFindBboxNode(model);

	if (node) {
		return &node->rodata->bbox;
	}

	return NULL;
}

static struct modelnode *objFindBboxNode(struct defaultobj *obj)
{
	return modelFindBboxNode(obj->model);
}

struct modelrodata_bbox *objFindBboxRodata(struct defaultobj *obj)
{
	return modelFindBboxRodata(obj->model);
}

static s32 func0f068b14(s16 *rooms, s32 arg1)
{
	s32 total = 0;
	s32 i;

	for (i = 0; rooms[i] != -1; i++) {
		if (arg1 == 0) {
			total += func0f000b24(rooms[i]);
		} else if (arg1 == 1) {
			total += func0f000c54(rooms[i]);
		}
	}

	if (i) {
		s32 average = total / i;

		if (average > 255) {
			average = 255;
		}

		return average;
	}

	return 0;
}

static s32 door0f068c04(struct prop *prop, s32 *arg1, s32 *arg2)
{
	struct doorobj *door = prop->door;
	struct doorobj *sibling;
	s32 i;
	s32 s1;
	s32 s3 = 0;
	s32 s4 = 0;
	s32 s2 = 0;
	s32 s5 = 0;
	s32 v1;
	s32 result;
	struct prop *loopprop;
	struct pad *pad;

	sibling = door;

	while (sibling && sibling->base.prop) {
		if (sibling->portalnum == door->portalnum) {
			if (g_Vars.currentplayer->prop) {
				struct coord *campos = &g_Vars.currentplayer->cam_pos;
				loopprop = sibling->base.prop;

				pad = &g_Pads[sibling->base.pad];

				if (door->base.flags3 & OBJFLAG3_04000000) {
					s3 += func0f000b24(pad->room);
					s4 += func0f000c54(pad->room);
					s5++;

					s2 = s3 + s4;

					if (s2 > 255) {
						s2 = 255;
					}
				} else {
					f32 xdist;
					f32 ydist;
					f32 zdist;
					struct coord *pos = &pad->pos;
					struct coord normal = pad->normal;
					f32 sum1;
					f32 sum2;

					if (door->doorflags & DOORFLAG_FLIP) {
						normal.f[0] = -normal.f[0];
						normal.f[1] = -normal.f[1];
						normal.f[2] = -normal.f[2];
					}

					xdist = campos->f[0] - pos->x;
					ydist = campos->f[1] - pos->y;
					zdist = campos->f[2] - pos->z;

					sum1 = xdist * normal.x + ydist * normal.y + zdist * normal.z;

					for (i = 0; loopprop->rooms[i] != -1; i++) {
						f32 roomx = g_Rooms[loopprop->rooms[i]].centre.x;
						f32 roomy = g_Rooms[loopprop->rooms[i]].centre.y;
						f32 roomz = g_Rooms[loopprop->rooms[i]].centre.z;
						f32 xdist = roomx - pos->x;
						f32 ydist = roomy - pos->y;
						f32 zdist = roomz - pos->z;

						sum2 = xdist * normal.x + ydist * normal.y + zdist * normal.z;

						// @bug? Duplicate sum1 < 0.0f check in the first part.
						// Perhaps one of them should be sum2 < 0.0f.
						if ((sum1 < 0.0f && sum1 < 0.0f) || (sum1 > 0.0f && sum2 > 0.0f)) {
							s32 value1 = func0f000c54(loopprop->rooms[i]);
							s32 value2 = func0f000b24(loopprop->rooms[i]);
							s32 sum = value2 + value1;

							if (sum > 255) {
								sum = 255;
							}

							s5++;
							s3 += value2;
							s4 += value1;
							s2 += sum;
						}
					}
				}
			}
		}

		sibling = sibling->sibling;

		if (sibling == door) {
			break;
		}
	}

	if (s5 == 0) {
		s1 = func0f068b14(prop->rooms, 0);
		v1 = func0f068b14(prop->rooms, 1);
	} else {
		s1 = s3 / s5;
		v1 = s4 / s5;
	}

	if (arg1 != NULL) {
		*arg1 = s1;
	}

	if (arg2 != NULL) {
		*arg2 = v1;
	}

	if (s1 + v1 < 255) {
		result = s1 + v1;
	} else {
		result = 255;
	}

	return result;
}

s32 func0f068fc8(struct prop *prop, bool arg1)
{
	struct defaultobj *obj = prop->obj;
	s32 actual = 0;
	s32 extra = 0;
	s32 *actualptr;
	s32 *extraptr;

	if (prop->rooms[0] == -1) {
		actual = random() % 255;
		extra = 0;
	} else if (obj->type == OBJTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *)obj;

		if (g_Vars.normmplayerisrunning) {
			actual = 255;
		} else {
			actualptr = arg1 == 0 ? &actual : NULL;
			extraptr = arg1 == 1 ? &extra : NULL;

			door0f068c04(prop, actualptr, extraptr);

			if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
				if (g_Vars.currentplayernum == 1) {
					if (actualptr) {
						door->actual1 = actual & 0xff;
					}

					if (extraptr) {
						door->extra1 = extra & 0xff;
					}
				} else {
					if (actualptr) {
						door->actual2 = actual & 0xff;
					}

					if (extraptr) {
						door->extra2 = extra & 0xff;
					}
				}
			}
		}
	} else {
		actual = func0f068b14(prop->rooms, 0);
		extra = func0f068b14(prop->rooms, 1);
	}

	if (arg1 == 0) {
		return actual;
	}

	if (arg1 == 1) {
		return extra;
	}

	return 255;
}

void propCalculateShadeColour(struct prop *prop, u8 *nextcol, u16 floorcol)
{
	struct defaultobj *obj;
	s32 max;
	s32 med;
	s32 min;
	f32 alphafrac;
	s32 roomr;
	s32 roomg;
	s32 roomb;
	s32 tmp;

	if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
		obj = prop->obj;
	} else {
		obj = NULL;
	}

	if (prop->type == PROPTYPE_CHR) {
		struct chrdata *chr = prop->chr;
		chr->unk32c_18 = false;
	}

	// Set nextcol to the floor colour
	if (obj && (obj->flags & OBJFLAG_IGNOREFLOORCOLOUR)) {
		nextcol[0] = 0xff;
		nextcol[1] = 0xff;
		nextcol[2] = 0xff;
		nextcol[3] = 0xff;
	} else {
		u8 r = ((floorcol >> 8) & 0xf);
		u8 g = ((floorcol >> 4) & 0xf);
		u8 b = ((floorcol >> 0) & 0xf);

		nextcol[0] = ((r << 4) | r);
		nextcol[1] = ((g << 4) | g);
		nextcol[2] = ((b << 4) | b);
		nextcol[3] = 0xff;
	}

	if (obj == NULL || (obj->flags & OBJFLAG_IGNOREROOMCOLOUR) == 0 || cheatIsActive(CHEAT_PERFECTDARKNESS)) {
		s32 shade = func0f068fc8(prop, 0);

		roomr = shade;
		roomg = shade;
		roomb = shade;

		alphafrac = 1.0f - shade * (1.0f / 2550.0f);

		scenarioHighlightRoom(prop->rooms[0], &roomr, &roomg, &roomb);

		nextcol[0] = (nextcol[0] * roomr) >> 8;
		nextcol[1] = (nextcol[1] * roomg) >> 8;
		nextcol[2] = (nextcol[2] * roomb) >> 8;

		tmp = nextcol[0] * 79 + nextcol[1] * 156 + nextcol[2] * 21;
		tmp >>= 8;
		nextcol[3] = (0xff - tmp) * alphafrac;
	} else {
		tmp = nextcol[0] * 79 + nextcol[1] * 156 + nextcol[2] * 21;
		tmp >>= 8;
		nextcol[3] = (0xff - tmp) * 0.9f;
	}

	if (1);

	// Figure out which colour component is the lowest, middle and highest
	max = 0;
	min = 0;
	med = 0;

	if (nextcol[1] > nextcol[0]) {
		max = 1;
	} else {
		min = 1;
	}

	if (nextcol[2] > nextcol[max]) {
		med = max;
		max = 2;
	} else if (nextcol[2] > nextcol[min]) {
		med = 2;
	} else {
		med = min;
		min = 2;
	}

	// @bug: The min and max component values are subtracted by the same amount, but the middle value is scaled.
	// So when a prop's shade colour is changing one of the component values is out of step with the others.
	// This is pretty much impossible to notice though.
	if (nextcol[max] > 0) {
		s32 tmp = nextcol[med] * (nextcol[max] - nextcol[min]) / nextcol[max];
		s32 range = nextcol[max] - nextcol[min];
		nextcol[min] = 0;
		nextcol[med] = tmp;
		nextcol[max] = range;
	}

	// Halving the next colour values causes them to transition over
	// multiple frames and slow down as they approach the desired colour.
	nextcol[0] >>= 1;
	nextcol[1] >>= 1;
	nextcol[2] >>= 1;
}

static void propCalculateShadeInfo(struct prop *prop, u8 *nextcol, u16 floorcol)
{
	propCalculateShadeColour(prop, nextcol, floorcol);

	nextcol[0] >>= 1;
	nextcol[1] >>= 1;
	nextcol[2] >>= 1;

	if (prop->type == PROPTYPE_DOOR && (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)) {
		struct doorobj *door = prop->door;

		if (g_Vars.currentplayernum == 0) {
			door->shadeinfo1[0] = nextcol[0];
			door->shadeinfo1[1] = nextcol[1];
			door->shadeinfo1[2] = nextcol[2];
			door->shadeinfo1[3] = nextcol[3];
		} else {
			door->shadeinfo2[0] = nextcol[0];
			door->shadeinfo2[1] = nextcol[1];
			door->shadeinfo2[2] = nextcol[2];
			door->shadeinfo2[3] = nextcol[3];
		}
	}
}

/**
 * Shift col to be closer to nextcol.
 *
 * It works by moving halfway towards the nextcol colour each time it's called.
 */
void colourTween(u8 *col, u8 *nextcol)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		s32 remaining = nextcol[i] - col[i];
		s32 newcol = col[i] + (remaining >> 1);
		col[i] = newcol;
	}
}

void func0f069750(s32 *arg0, s32 arg1, f32 arg2[4])
{
	if (arg1 == 1) {
		f32 tmp;

		arg2[0] *= 255.0f;
		arg2[1] *= 255.0f;
		arg2[2] *= 255.0f;

		tmp = arg0[0];
		arg0[0] = tmp + (arg2[0] - tmp) * arg2[3];

		tmp = arg0[1];
		arg0[1] = tmp + (arg2[1] - tmp) * arg2[3];

		tmp = arg0[2];
		arg0[2] = tmp + (arg2[2] - tmp) * arg2[3];

		tmp = arg0[3];
		arg0[3] = tmp + (255.0f - tmp) * arg2[3];
	}
}

struct hovtype g_HovTypes[];

static void func0f069850(struct defaultobj *obj, struct coord *pos, f32 rot[3][3], struct geocyl *cyl)
{
	Mtxf mtx;
	struct modelrodata_bbox *bbox = objFindBboxRodata(obj);
	struct modelrodata_type19 *rodata19 = NULL;
	struct hoverbikeobj *hoverbike;
	struct hoverpropobj *hoverprop;

	mtx3ToMtx4(rot, &mtx);
	mtx4SetTranslation(pos, &mtx);

	if (obj->model->filedata->skel == &g_SkelHoverbike
			|| obj->model->filedata->skel == &g_SkelBasic
			|| obj->model->filedata->skel == &g_SkelMaianUfo
			|| obj->model->filedata->skel == &g_SkelDropship) {
		rodata19 = modelGetPartRodata(obj->model->filedata, MODELPART_HOVERBIKE_0064);
	}

	if (obj->flags3 & OBJFLAG3_GEOCYL) {
		cyl->header.type = GEOTYPE_CYL;
		cyl->header.flags = GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT;

		if (obj->type == OBJTYPE_HOVERBIKE) {
			hoverbike = (struct hoverbikeobj *)obj;
			cyl->ymax = hoverbike->hov.ground + g_HovTypes[hoverbike->hov.type].unk00 + objGetLocalYMax(bbox) * obj->model->scale;
			cyl->ymin = hoverbike->hov.ground + 20.0f;
		} else if (obj->type == OBJTYPE_HOVERPROP) {
			hoverprop = (struct hoverpropobj *)obj;
			cyl->ymax = hoverprop->hov.ground + g_HovTypes[hoverprop->hov.type].unk00 + objGetLocalYMax(bbox) * obj->model->scale;
			cyl->ymin = hoverprop->hov.ground + 20.0f;
		} else {
			cyl->ymin = mtx.m[3][1] + objGetRotatedLocalYMinByMtx4(bbox, &mtx);
			cyl->ymax = mtx.m[3][1] + objGetRotatedLocalYMaxByMtx4(bbox, &mtx);
		}

		cyl->x = pos->x;
		cyl->z = pos->z;
		cyl->radius = 90.0f;
	} else {
		if (rodata19 != NULL) {
			objCalculateGeoBlockFromNode19Data(rodata19, bbox, &mtx, (struct geoblock *)cyl);
		} else {
			objCalculateGeoBlockFromBboxAndMtx(bbox, &mtx, (struct geoblock *)cyl);
		}

		if (obj->type == OBJTYPE_HOVERBIKE) {
			hoverbike = (struct hoverbikeobj *)obj;
			cyl->ymax = hoverbike->hov.ground + g_HovTypes[hoverbike->hov.type].unk00 + objGetLocalYMax(bbox) * obj->model->scale;
			cyl->ymin = hoverbike->hov.ground + 20.0f;
		} else if (obj->type == OBJTYPE_HOVERPROP) {
			hoverprop = (struct hoverpropobj *)obj;
			cyl->ymax = hoverprop->hov.ground + g_HovTypes[hoverprop->hov.type].unk00 + objGetLocalYMax(bbox) * obj->model->scale;
			cyl->ymin = hoverprop->hov.ground + 20.0f;
		}
	}
}

static void func0f069b4c(struct defaultobj *obj)
{
	union modelrodata *rodata;
	u8 *ptr = (u8 *) obj->unkgeo;

	if (ptr != NULL) {
		if ((obj->hidden2 & OBJH2FLAG_08)) {
			if (obj->flags3 & OBJFLAG3_GEOCYL) {
				ptr += sizeof(struct geocyl);
			} else {
				ptr += sizeof(struct geoblock);
			}
		}

		rodata = modelGetPartRodata(obj->model->filedata, MODELPART_0065);

		if (rodata != NULL) {
			u32 flags = GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2;

			if (obj->type == OBJTYPE_ESCASTEP) {
				flags |= GEOFLAG_LIFTFLOOR;
			}

			func0f070ca0(obj, (struct geotilef *)ptr, flags, NULL, &rodata->type19);

			ptr += 0x40;
		}

		rodata = modelGetPartRodata(obj->model->filedata, MODELPART_0066);

		if (rodata != NULL) {
			func0f070ca0(obj, (struct geotilef *)ptr, GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT, NULL, &rodata->type19);
		}
	}
}

static void func0f069c1c(struct defaultobj *obj)
{
	if (obj->geocyl) {
		if (obj->hidden2 & OBJH2FLAG_08) {
			func0f069850(obj, &obj->prop->pos, obj->realrot, obj->geocyl);
		}

		func0f069b4c(obj);
	}
}

void func0f069c70(struct defaultobj *obj, bool arg1, bool arg2)
{
	struct prop *prop;

	if (arg1) {
		func0f069c1c(obj);
	}

	if (arg2) {
		setup0f0923d4(obj);
	}

	prop = obj->prop;
	propCalculateShadeInfo(prop, obj->nextcol, obj->floorcol);
	coordTriggerProxies(&obj->prop->pos, false);
}

/**
 * Iterate the model parts in range 201 to 220 (0xc9 to 0xdc) and disable them,
 * stopping when any part doesn't exist.
 *
 * This range of part numbers is a special range that is hidden when the object
 * is initialised.
 */
static void objInitToggleNodes(struct defaultobj *obj)
{
	struct model *model = obj->model;
	union modelrwdata *rwdata;
	s32 i;

	for (i = 0; i < 20; i++) {
		struct modelnode *node = modelGetPart(model->filedata, 201 + i);

		if (!node) {
			return;
		}

		rwdata = modelGetNodeRwData(model, node);
		rwdata->toggle.visible = false;
	}
}

static void objCreateOneDebris(struct defaultobj *obj, s32 partindex, struct prop *prop)
{
	struct defaultobj *debris = debrisAllocate();

	if (debris) {
		struct defaultobj tmp = {
			256,                    // extrascale
			0,                      // hidden2
			OBJTYPE_DEBRIS,         // type
			0,                      // modelnum
			-1,                     // pad
			OBJFLAG_00000001,       // flags
			0,                      // flags2
			0,                      // flags3
			NULL,                   // prop
			NULL,                   // model
			1, 0, 0,                // realrot
			0, 1, 0,
			0, 0, 1,
			0,                      // hidden
			NULL,                   // geo
			NULL,                   // projectile
			0,                      // damage
			1000,                   // maxdamage
			0xff, 0xff, 0xff, 0x00, // shadecol
			0xff, 0xff, 0xff, 0x00, // nextcol
			0x0fff,                 // floorcol
			0,                      // tiles
		};

		struct modelnode *node;

		*debris = tmp;
		debris->modelnum = obj->modelnum;

		if (objInitWithModelDef(debris, g_ModelStates[debris->modelnum].filedata)) {
			propReparent(debris->prop, obj->prop);
			objSetDropped(debris->prop, DROPTYPE_5);

			if (debris->hidden & OBJHFLAG_PROJECTILE) {
				f32 distance;
				struct projectile *projectile = debris->projectile;
				struct coord rot = {0, 0, 0};
				struct coord dist;

				dist.x = obj->prop->pos.x - prop->pos.x;
				dist.y = 0.0f;
				dist.z = obj->prop->pos.z - prop->pos.z;

				distance = sqrtf(dist.f[0] * dist.f[0] + dist.f[2] * dist.f[2]);

				if (distance > 0.0f) {
					distance = 1.0f / distance;
					dist.x *= distance;
					dist.z *= distance;
				} else {
					dist.x = RANDOMFRAC() * 0.5f;
					dist.z = RANDOMFRAC() * 0.5f;
				}

				projectile->speed.x = dist.x * 3.3333333f;
				projectile->speed.y = RANDOMFRAC() * 6.6666665f;
				projectile->speed.z = dist.z * 3.3333333f;

#if PAL
				rot.x = RANDOMFRAC() * 0.058895487f - 0.029447744f;
				rot.y = RANDOMFRAC() * 0.058895487f - 0.029447744f;
				rot.z = RANDOMFRAC() * 0.058895487f - 0.029447744f;
#else
				rot.x = RANDOMFRAC() * 0.04907957f - 0.024539785f;
				rot.y = RANDOMFRAC() * 0.04907957f - 0.024539785f;
				rot.z = RANDOMFRAC() * 0.04907957f - 0.024539785f;
#endif

				mtx4LoadRotation(&rot, &projectile->mtx);
			}

			debris->model->scale = obj->model->scale;

			debris->flags |= OBJFLAG_INVINCIBLE | OBJFLAG_BOUNCEIFSHOT | OBJFLAG_01000000;
			debris->flags2 |= OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_00200000;
			debris->flags3 |= OBJFLAG3_00000008;

			node = modelGetPart(debris->model->filedata, MODELPART_BASIC_00C8);

			{
				struct modelrwdata_toggle *rodata;

				if (node) {
					rodata = modelGetNodeRwData(debris->model, node);
					rodata->visible = false;
				}

				node = modelGetPart(debris->model->filedata, MODELPART_BASIC_00C9 + partindex);

				if (node) {
					rodata = modelGetNodeRwData(debris->model, node);
					rodata->visible = true;
				}
			}
		}
	}
}

static void objCreateDebris(struct defaultobj *obj, struct prop *prop)
{
	struct model *model = obj->model;
	s32 i;

	if (prop);

	for (i = 0; i < 20; i++) {
		if (modelGetPart(model->filedata, 201 + i) == NULL) {
			break;
		}

		objCreateOneDebris(obj, i, prop);
	}
}

static struct prop *objInit(struct defaultobj *obj, struct modelfiledata *filedata, struct prop *prop, struct model *model)
{
	if (prop == NULL) {
		prop = propAllocate();
	}

	if (model == NULL) {
		model = modelmgrInstantiateModelWithoutAnim(filedata);
	}

	if (prop && model) {
		s32 geosize;

		obj->model = model;

		if (modelGetPartRodata(filedata, MODELPART_BASIC_0065)) {
			obj->geocount++;
		}

		if (modelGetPartRodata(filedata, MODELPART_BASIC_0066)) {
			obj->geocount++;
		}

		geosize = obj->geocount * 0x40;

		if (obj->flags & OBJFLAG_00000100) {
			if (obj->flags3 & OBJFLAG3_GEOCYL) {
				geosize += sizeof(struct geocyl);
			} else {
				geosize += sizeof(struct geoblock);
			}

			obj->geocount++;
			obj->hidden2 |= OBJH2FLAG_08;
		} else {
			obj->hidden2 &= ~OBJH2FLAG_08;
		}

		if (obj->geocount > 0) {
			obj->unkgeo = mempAlloc(ALIGN16(geosize), MEMPOOL_STAGE);
		} else {
			obj->unkgeo = NULL;
		}

		obj->prop = prop;
		obj->damage = 0;
		obj->projectile = NULL;
		obj->shadecol[0] = 0;
		obj->shadecol[1] = 0;
		obj->shadecol[2] = 0;
		obj->shadecol[3] = 0;
		obj->nextcol[0] = 0;
		obj->nextcol[1] = 0;
		obj->nextcol[2] = 0;
		obj->nextcol[3] = 0;
		obj->floorcol = 0xfff;
		obj->model->obj = obj;
		obj->model->unk01 = 0;
		obj->model->scale = g_ModelStates[obj->modelnum].scale * (1.0f / 4096.0f);

		prop->type = PROPTYPE_OBJ;
		prop->obj = obj;
		prop->pos.x = 0;
		prop->pos.y = 0;
		prop->pos.z = 0;

		objInitToggleNodes(obj);

		if (obj->flags3 & OBJFLAG3_RENDERPOSTBG) {
			prop->flags |= PROPFLAG_RENDERPOSTBG;
		}

		if (obj->flags3 & OBJFLAG3_DRAWONTOP) {
			prop->flags |= PROPFLAG_DRAWONTOP;
		}
	} else {
		if (model) {
			modelmgrFreeModel(model);
		}

		if (prop) {
			propFree(prop);
			prop = NULL;
		}

		if (obj) {
			obj->prop = NULL;
			obj->model = NULL;
		}
	}

	if (g_Vars.normmplayerisrunning && prop && obj && obj->type == OBJTYPE_WEAPON) {
		struct weaponobj *weapon = (struct weaponobj *) obj;

		if (weapon->weaponnum == WEAPON_BRIEFCASE2) {
			if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE) {
				g_ScenarioData.htb.token = prop;
			}

			prop->forcetick = true;
			obj->flags |= OBJFLAG_INVINCIBLE | OBJFLAG_00400000;
			obj->flags2 |= OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_00200000;
		} else if (weapon->weaponnum == WEAPON_DATAUPLINK) {
			if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
				g_ScenarioData.htm.uplink = prop;
			}

			prop->forcetick = true;
			obj->flags |= OBJFLAG_INVINCIBLE | OBJFLAG_00400000;
			obj->flags2 |= OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_00200000;
		}
	}

	return prop;
}

struct prop *objInitWithModelDef(struct defaultobj *obj, struct modelfiledata *filedata)
{
	return objInit(obj, filedata, NULL, NULL);
}

struct prop *objInitWithAutoModel(struct defaultobj *obj)
{
	return objInitWithModelDef(obj, g_ModelStates[obj->modelnum].filedata);
}

void func0f06a580(struct defaultobj *obj, struct coord *pos, Mtxf *matrix, s16 *rooms)
{
	struct prop *prop = obj->prop;

	mtx4ToMtx3(matrix, obj->realrot);

	prop->pos = *pos;

	propDeregisterRooms(prop);
	roomsCopy(rooms, prop->rooms);
	func0f069c70(obj, true, true);

	obj->shadecol[0] = obj->nextcol[0];
	obj->shadecol[1] = obj->nextcol[1];
	obj->shadecol[2] = obj->nextcol[2];
	obj->shadecol[3] = obj->nextcol[3];
}

static f32 func0f06a620(struct defaultobj *obj)
{
	if (obj->type == OBJTYPE_WEAPON) {
		return 0;
	}

	return 4;
}

void func0f06a730(struct defaultobj *obj, struct coord *arg1, Mtxf *mtx, s16 *rooms, struct coord *centre)
{
	struct modelrodata_bbox *bbox = modelFindBboxRodata(obj->model);
	f32 min = objGetLocalYMin(bbox);
	f32 max = objGetLocalYMax(bbox);
	struct coord pos2;
	Mtxf sp70;
	s16 rooms2[8];
	f32 curval;
	f32 y;
	f32 maxval;
	s32 row;
	bool isnegative;

	if (obj->flags & OBJFLAG_00000004) {
		mtx4LoadZRotation(M_BADPI, &sp70);
		mtx4MultMtx4InPlace(mtx, &sp70);

		pos2.x = centre->x - sp70.m[1][0] * max;
		pos2.y = centre->y - sp70.m[1][1] * max;
		pos2.z = centre->z - sp70.m[1][2] * max;
	} else if (obj->flags & OBJFLAG_00000008) {
		mtx4Copy(mtx, &sp70);

		pos2.x = centre->x - sp70.m[1][0] * min;
		pos2.y = centre->y - sp70.m[1][1] * min;
		pos2.z = centre->z - sp70.m[1][2] * min;
	} else {
		mtx4Copy(mtx, &sp70);

		row = 0;
		isnegative = false;

		// Row 0
		curval = sp70.m[0][1];

		if (curval < 0.0f) {
			curval = -curval;
		}

		{
			row = 0;
			isnegative = sp70.m[row][1] < 0.0f;
			maxval = curval;
		}

		// Row 1
		curval = sp70.m[1][1];

		if (curval < 0.0f) {
			curval = -curval;
		}

		if (curval > maxval) {
			row = 1;
			isnegative = sp70.m[row][1] < 0.0f;
			maxval = curval;
		}

		// Row 2
		curval = sp70.m[2][1];

		if (curval < 0.0f) {
			curval = -curval;
		}

		if (curval > maxval) {
			row = 2;
			isnegative = sp70.m[row][1] < 0.0f;
			maxval = curval;
		}

		if (row == 0) {
			min = objGetLocalXMin(bbox);
			max = objGetLocalXMax(bbox);
		} else if (row == 2) {
			min = objGetLocalZMin(bbox);
			max = objGetLocalZMax(bbox);
		}

		if (isnegative) {
			f32 tmp = min;
			min = max;
			max = tmp;
		}

		pos2.x = centre->x - sp70.m[row][0] * min;
		pos2.y = centre->y - sp70.m[row][1] * min;
		pos2.z = centre->z - sp70.m[row][2] * min;

		func0f065e74(arg1, rooms, &pos2, rooms2);

		if (cdFindFloorRoomYColourFlagsAtPos(&pos2, rooms2, &y, &obj->floorcol, NULL) > 0) {
			bool updated;
			struct defaultobj *obj2 = objFindByPos(&pos2, rooms2);
			u8 *start;
			u8 *end;
			struct geoblock *block;

			if (obj2) {
				updated = propUpdateGeometry(obj2->prop, &start, &end);

				if (updated
						&& (block = (struct geoblock *) start, block->header.type == GEOTYPE_BLOCK)
						&& block->ymax > y
						&& block->ymin < y + (max - min) * sp70.m[row][1] + func0f06a620(obj)) {
					pos2.y = block->ymax - sp70.m[row][1] * min;
					obj->hidden |= OBJHFLAG_00008000;
				} else {
					pos2.y = y - min * sp70.m[row][1] + func0f06a620(obj);
				}
			} else {
				pos2.y = y - min * sp70.m[row][1] + func0f06a620(obj);
			}
		}
	}

	func0f065e74(arg1, rooms, &pos2, rooms2);
	func0f06a580(obj, &pos2, &sp70, rooms2);
}

void func0f06ab60(struct defaultobj *obj, struct coord *arg1, Mtxf *arg2, s16 *rooms, struct coord *arg4)
{
	struct modelrodata_bbox *bbox;
	f32 mult;
	struct coord newpos;
	s16 newrooms[8];
	Mtxf sp5c;
	Mtxf sp1c;

	bbox = modelFindBboxRodata(obj->model);
	mult = objGetLocalZMin(bbox);

	mtx4LoadXRotation(4.7116389274597f, &sp5c);
	mtx4LoadYRotation(M_BADPI, &sp1c);
	mtx4MultMtx4InPlace(&sp1c, &sp5c);
	mtx4MultMtx4InPlace(arg2, &sp5c);

	newpos.x = arg4->x - sp5c.m[2][0] * mult;
	newpos.y = arg4->y - sp5c.m[2][1] * mult;
	newpos.z = arg4->z - sp5c.m[2][2] * mult;

	func0f065e74(arg1, rooms, &newpos, newrooms);
	func0f06a580(obj, &newpos, &sp5c, newrooms);
}

void objFreeProjectile(struct defaultobj *obj)
{
	if (obj->hidden & OBJHFLAG_PROJECTILE) {
		projectileFree(obj->projectile);
		obj->projectile = NULL;

		obj->hidden &= ~OBJHFLAG_PROJECTILE;
	}
}

void objFreeEmbedmentOrProjectile(struct prop *prop)
{
	if (prop && prop->obj) {
		struct defaultobj *obj = prop->obj;

		if (obj->hidden & OBJHFLAG_EMBEDDED) {
			if (obj->embedment) {
				if (obj->embedment->projectile) {
					projectileFree(obj->embedment->projectile);
				}

				embedmentFree(obj->embedment);
			}

			obj->embedment = NULL;
			obj->hidden &= ~OBJHFLAG_EMBEDDED;
		} else if (obj->hidden & OBJHFLAG_PROJECTILE) {
			objFreeProjectile(obj);
		}
	}
}

/**
 * Remove an object from the game world by clearing all references to it.
 *
 * If freeprop is true, the obj's prop will be returned to the freeprops list.
 * Child objects such as attached knives and mines will always have their props
 * freed.
 */
void objFree(struct defaultobj *obj, bool freeprop, bool canregen)
{
	struct prop *child;

	if (obj->type == OBJTYPE_WEAPON) {
		struct weaponobj *weapon = (struct weaponobj *) obj;

		if (weapon->dualweapon) {
			weapon->dualweapon->dualweapon = NULL;
			weapon->dualweapon = NULL;
		}

		if (weapon->weaponnum == WEAPON_PROXIMITYMINE) {
			weaponUnregisterProxy(weapon);
		}

		if (weapon->weaponnum == WEAPON_DRAGON && weapon->gunfunc == FUNC_SECONDARY) {
			weaponUnregisterProxy(weapon);
		}

		if (weapon->weaponnum == WEAPON_NBOMB && weapon->gunfunc == FUNC_SECONDARY) {
			weaponUnregisterProxy(weapon);
		}

		if (weapon->weaponnum == WEAPON_GRENADE && weapon->gunfunc == FUNC_SECONDARY) {
			weaponUnregisterProxy(weapon);
			smokeClearForProp(obj->prop);
		}

		if (weapon->weaponnum == WEAPON_BOLT) {
			s32 beammnum = boltbeamFindByProp(obj->prop);

			if (beammnum != -1) {
				boltbeamSetAutomatic(beammnum, 1400);
			}
		}

		if (g_Vars.normmplayerisrunning
				&& weapon->weaponnum == WEAPON_SKROCKET
				&& obj->projectile
				&& obj->projectile->ownerprop) {
			s32 i;

			for (i = 0; i < g_MpNumChrs; i++) {
				if (g_MpAllChrPtrs[i]->aibot && g_MpAllChrPtrs[i]->aibot->skrocket == obj->prop) {
					g_MpAllChrPtrs[i]->aibot->skrocket = NULL;
				}
			}
		}
	} else if (obj->type == OBJTYPE_TINTEDGLASS) {
		struct tintedglassobj *glass = (struct tintedglassobj *) obj;

		if (glass->portalnum >= 0) {
			portalSetXluFrac(glass->portalnum, 1);
			portalSetOpen(glass->portalnum, true);
			g_BgPortals[glass->portalnum].flags |= PORTALFLAG_FORCEOPEN;
		}
	} else if (obj->type == OBJTYPE_GLASS) {
		struct glassobj *glass = (struct glassobj *) obj;

		if (glass->portalnum >= 0) {
			portalSetXluFrac(glass->portalnum, 1);
		}
	} else if (obj->type == OBJTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *) obj;

		doorActivatePortal(door);

		if (door->portalnum >= 0) {
			g_BgPortals[door->portalnum].flags |= PORTALFLAG_FORCEOPEN;
		}
	}

	if (obj->prop) {
		s32 prevplayernum = g_Vars.currentplayernum;
		s32 i;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);

			if (obj->prop == bmoveGetGrabbedProp() || obj->prop == bmoveGetHoverbike()) {
				bmoveSetMode(MOVEMODE_WALK);
			}

			invRemoveProp(obj->prop);
		}

		setCurrentPlayerNum(prevplayernum);

		// If obj is an occupied chair, remove the chr from it
		if (obj->hidden & OBJHFLAG_OCCUPIEDCHAIR) {
			s32 numchrs = g_NumChrSlots;
			s32 i;

			obj->hidden &= ~OBJHFLAG_OCCUPIEDCHAIR;

			for (i = 0; i < numchrs; i++) {
				// @bug: Should be ==, but this isn't a problem because occupied
				// chairs are never removed using this code. If they were, and
				// the propnum was > 0, all chrs would be disassociated with
				// their chairs but their chairs would still have the occupied
				// flag. If the propnum was 0, all chrs would be assigned to
				// this one chair, and their original chairs would still have
				// the occupied flag.
				if ((g_ChrSlots[i].proppreset1 = obj->prop - g_Vars.props)) {
					g_ChrSlots[i].proppreset1 = -1;
				}
			}
		}

		// Remove references from aibots if the obj is the item being fetched
		if (g_Vars.normmplayerisrunning) {
			s32 i;

			for (i = 0; i < g_MpNumChrs; i++) {
				if (g_MpAllChrPtrs[i]->aibot && g_MpAllChrPtrs[i]->aibot->gotoprop == obj->prop) {
					g_MpAllChrPtrs[i]->aibot->gotoprop = NULL;
				}
			}
		}

		func0f0926bc(obj->prop, 1, 0xffff);
		shieldhitsRemoveByProp(obj->prop);

		chrClearReferences(obj->prop - g_Vars.props);
		projectilesUnrefOwner(obj->prop);

		wallhitsFreeByProp(obj->prop, 0);
		wallhitsFreeByProp(obj->prop, 1);
		objFreeEmbedmentOrProjectile(obj->prop);

		child = obj->prop->child;

		while (child) {
			struct prop *next = child->next;

			objFreePermanently(child->obj, true);

			child = next;
		}

		if (!canregen) {
			if (obj->prop->parent) {
				objDetach(obj->prop);
			}

			propDeregisterRooms(obj->prop);

			if (obj->prop->type != PROPTYPE_DOOR) {
				modelFreeVertices(1, obj->model);
			}

			modelmgrFreeModel(obj->model);

			if (freeprop) {
				propDelist(obj->prop);
				propDisable(obj->prop);
				propFree(obj->prop);
			}

			obj->prop->obj = NULL;
			obj->prop = NULL;
		}
	}
}

void objFreePermanently(struct defaultobj *obj, bool freeprop)
{
	objFree(obj, freeprop, false);
}

static f32 objGetRadius(struct defaultobj *obj)
{
	if (obj->type == OBJTYPE_KEY) {
		return 20;
	}

	return 10;
}

bool func0f06b39c(struct coord *arg0, struct coord *arg1, struct coord *arg2, f32 arg3)
{
	struct coord sp0c;
	f32 value;

	sp0c.x = arg2->x - arg0->x;
	sp0c.y = arg2->y - arg0->y;
	sp0c.z = arg2->z - arg0->z;

	value = arg1->f[0] * sp0c.f[0] + arg1->f[1] * sp0c.f[1] + arg1->f[2] * sp0c.f[2];

	if (value > 0) {
		f32 a = arg1->f[0] * arg1->f[0] + arg1->f[1] * arg1->f[1] + arg1->f[2] * arg1->f[2];
		f32 b = sp0c.f[0] * sp0c.f[0] + sp0c.f[1] * sp0c.f[1] + sp0c.f[2] * sp0c.f[2];

		if ((b - arg3 * arg3) * a <= value * value) {
			return true;
		}
	}

	return false;
}

static bool func0f06b488(struct prop *prop, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4, struct coord *arg5, f32 *arg6)
{
	if (!cd0002ded8(arg1, arg2, prop)) {
		f32 f0 = (g_CdObstaclePos.f[0] - arg1->f[0]) * arg3->f[0]
			+ (g_CdObstaclePos.f[1] - arg1->f[1]) * arg3->f[1]
			+ (g_CdObstaclePos.f[2] - arg1->f[2]) * arg3->f[2];

		if (f0 < *arg6) {
			*arg6 = f0;

			*arg4 = g_CdObstaclePos;

			arg5->x = -arg3->x;
			arg5->y = 0.0f;
			arg5->z = -arg3->z;

			if (arg5->x != 0.0f || arg5->z != 0.0f) {
				guNormalize(&arg5->x, &arg5->y, &arg5->z);
			} else {
				arg5->z = 1.0f;
			}

			g_EmbedProp = prop;
			g_EmbedHitPart = 0;
			g_EmbedModel = NULL;
			g_EmbedNode = NULL;

			return true;
		}
	}

	return false;
}

static bool func0f06b610(struct defaultobj *obj, struct coord *arg1, struct coord *arg2, struct coord *arg3, f32 arg4, struct coord *arg5, struct coord *arg6, struct coord *arg7, struct coord *arg8, f32 *arg9)
{
	struct model *model = obj->model;
	f32 f0 = model0001af80(model);
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	f32 sum1 = 0.0f;
	struct prop *prop = obj->prop;
	struct prop *child;
	bool result = false;
	f32 sum2;
	struct coord spfc;
	struct coord spf0;
	struct modelnode *node1;
	s32 hitpart;
	struct modelnode *spe4 = NULL;
	struct hitthing thing1;
	s32 mtxindex1;
	struct modelnode *node;
	struct hitthing thing2;
	s32 mtxindex2;
	struct modelnode *node2;
	f32 sum3;

	if (prop->parent == NULL) {
		xdiff = prop->pos.f[0] - arg1->f[0];
		ydiff = prop->pos.f[1] - arg1->f[1];
		zdiff = prop->pos.f[2] - arg1->f[2];

		sum1 = xdiff * arg3->f[0] + ydiff * arg3->f[1] + zdiff * arg3->f[2];
	}

	if (sum1 >= -f0 && sum1 <= arg4 + f0) {
		if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
			if (var8005efc0 > 0.0f) {
				hitpart = model000225d4(model, arg5, arg6, &spe4);

				while (hitpart > 0) {
					if (func0f084594(model, spe4, arg5, arg6, &thing1, &mtxindex1, &node1)) {
						mtx4TransformVec(&model->matrices[mtxindex1], &thing1.unk00, &spfc);

						sum2 = (spfc.f[0] - arg5->f[0]) * arg6->f[0]
							+ (spfc.f[1] - arg5->f[1]) * arg6->f[1]
							+ (spfc.f[2] - arg5->f[2]) * arg6->f[2];

						if (sum2 < *arg9) {
							mtx4RotateVec(&model->matrices[mtxindex1], &thing1.unk0c, &spf0);

							*arg9 = sum2;

							mtx4TransformVec(g_Vars.currentplayer->projectionmtx, &spfc, arg7);
							mtx4RotateVec(g_Vars.currentplayer->projectionmtx, &spf0, arg8);

							if (arg8->x != 0.0f || arg8->y != 0.0f || arg8->z != 0.0f) {
								guNormalize(&arg8->x, &arg8->y, &arg8->z);
							} else {
								arg8->z = 1.0f;
							}

							g_EmbedProp = prop;
							g_EmbedModel = model;
							g_EmbedHitPart = hitpart;
							g_EmbedNode = spe4;

							g_EmbedSide = thing1.unk28 / 2;
							var8006993c[0] = thing1.unk00.x;
							var8006993c[1] = thing1.unk00.y;
							var8006993c[2] = thing1.unk00.z;

							result = 1;
						}
					}

					hitpart = model000225d4(model, arg5, arg6, &spe4);
				}
			} else {
				do {
					hitpart = model000225d4(model, arg5, arg6, &spe4);

					if (hitpart > 0) {
						if (func0f0849dc(model, spe4, arg5, arg6, &thing1, &mtxindex1, &node1)) {
							break;
						}
					}
				} while (hitpart > 0);

				if (obj->flags3 & OBJFLAG3_HOVERBEDSHIELD) {
					node = modelGetPart(model->filedata, MODELPART_BASIC_0067);

					if (node && func0f084594(model, node, arg5, arg6, &thing2, &mtxindex2, &node2)) {
						if (hitpart <= 0 ||
								+ model->matrices[mtxindex2].m[0][2] * thing2.unk00.f[0]
								+ model->matrices[mtxindex2].m[1][2] * thing2.unk00.f[1]
								+ model->matrices[mtxindex2].m[2][2] * thing2.unk00.f[2]
								>
								+ model->matrices[mtxindex1].m[0][2] * thing1.unk00.f[0]
								+ model->matrices[mtxindex1].m[1][2] * thing1.unk00.f[1]
								+ model->matrices[mtxindex1].m[2][2] * thing1.unk00.f[2]
								) {
							hitpart = 1;

							thing1 = thing2;
							mtxindex1 = mtxindex2;
							node1 = node2;
							thing1.texturenum = 10000;
						}
					}
				}

				if (hitpart > 0) {
					mtx4TransformVec(&model->matrices[mtxindex1], &thing1.unk00, &spfc);

					sum3 = (spfc.f[0] - arg5->f[0]) * arg6->f[0]
						+ (spfc.f[1] - arg5->f[1]) * arg6->f[1]
						+ (spfc.f[2] - arg5->f[2]) * arg6->f[2];

					if (sum3 >= 0.0f && sum3 <= *arg9) {
						mtx4RotateVec(&model->matrices[mtxindex1], &thing1.unk0c, &spf0);

						*arg9 = sum1;

						mtx4TransformVec(g_Vars.currentplayer->projectionmtx, &spfc, arg7);

						if (spf0.f[0] * arg6->f[0] + spf0.f[1] * arg6->f[1] + spf0.f[2] * arg6->f[2] > 0.0f) {
							spf0.f[0] = -spf0.f[0];
							spf0.f[1] = -spf0.f[1];
							spf0.f[2] = -spf0.f[2];
						}

						mtx4RotateVec(g_Vars.currentplayer->projectionmtx, &spf0, arg8);

						if (arg8->f[0] != 0.0f || arg8->f[1] != 0.0f || arg8->f[2] != 0.0f) {
							guNormalize(&arg8->x, &arg8->y, &arg8->z);
						} else {
							arg8->z = 1.0f;
						}

						g_EmbedProp = prop;
						g_EmbedHitPart = hitpart;
						g_EmbedModel = model;
						g_EmbedNode = node1;

						var80069944 = thing1.texturenum;

						result = true;

						if (thing1.texturenum == 10000) {
							g_EmbedSide = thing1.unk28 / 2;
							var8006993c[0] = thing1.unk00.x;
							var8006993c[1] = thing1.unk00.y;
							var8006993c[2] = thing1.unk00.z;
						}
					}
				}
			}
		} else {
			if (func0f06b39c(arg1, arg3, &prop->pos, model0001af80(model))
					&& func0f06b488(prop, arg1, arg2, arg3, arg7, arg8, arg9)) {
				g_EmbedModel = model;
				g_EmbedNode = model->filedata->rootnode;
				result = true;
			}
		}
	}

	if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		child = prop->child;

		while (child) {
			if (child->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
				if (func0f06b610(child->obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)) {
					result = true;
				}
			}

			child = child->next;
		}
	}

	return result;
}

bool func0f06bea0(struct model *model, struct modelnode *endnode, struct modelnode *node, struct coord *arg3, struct coord *arg4, void *arg5, f32 *arg6, struct modelnode **arg7, s32 *hitpart, s32 *arg9, struct modelnode **arg10)
{
	u32 stack;
	union modelrodata *rodata;
	bool ok = false;
	f32 sp98 = MAXFLOAT;
	Gfx *s4;
	Gfx *s6;
	struct gfxvtx *vertices;
	struct modelnode *sp88;
	struct modelnode *sp84 = NULL;
	bool s7;
	struct coord sp74;
	struct modelrwdata_dl *rwdata;

	vertices = NULL;
	s7 = false;

	var8005efc0 = 2.5f / model->scale;

	sp74.x = arg3->x + arg4->f[0] * 32767.0f;
	sp74.y = arg3->y + arg4->f[1] * 32767.0f;
	sp74.z = arg3->z + arg4->f[2] * 32767.0f;

	g_Vars.hitboundscount = 0;

	while (node) {
		u32 type = node->type & 0xff;
		s4 = NULL;
		s6 = NULL;

		switch (type) {
		case MODELNODETYPE_BBOX:
			rodata = node->rodata;

			if (model000220fc(&rodata->bbox, model0001a5cc(model, node, 0), arg3, arg4)) {
				s7 = true;
				sp84 = node;

				if (g_Vars.hitboundscount < ARRAYCOUNT(g_Vars.hitnodes)) {
					g_Vars.hitnodes[g_Vars.hitboundscount] = node;
					g_Vars.hitboundscount++;
				}
			} else {
				s7 = false;
				var8005efc0 = 10.0f / model->scale;

				if (model000220fc(&rodata->bbox, model0001a5cc(model, node, 0), arg3, arg4)) {
					if (g_Vars.hitboundscount < ARRAYCOUNT(g_Vars.hitnodes)) {
						g_Vars.hitnodes[g_Vars.hitboundscount] = node;
						g_Vars.hitboundscount++;
					}
				}

				var8005efc0 = 2.5f / model->scale;
			}
			break;
		case MODELNODETYPE_DL:
			if (s7) {
				rodata = node->rodata;
				rwdata = modelGetNodeRwData(model, node);

				if (rwdata->gdl != NULL) {
					if (rwdata->gdl == rodata->dl.primary) {
						s4 = (Gfx *)((u32)rodata->dl.colourtable + ((u32)rodata->dl.primary & 0xffffff));
					} else {
						s4 = rwdata->gdl;
					}

					if (rodata->dl.secondary != NULL) {
						s6 = (Gfx *)((u32)rodata->dl.colourtable + ((u32)rodata->dl.secondary & 0xffffff));
					}

					vertices = rwdata->vertices;
				}
			}
			break;
		case MODELNODETYPE_GUNDL:
			if (s7) {
				if (node->rodata->gundl.primary != NULL) {
					s32 base = (s32)node->rodata->gundl.baseaddr;

					s4 = (Gfx *)(base + ((u32)node->rodata->gundl.primary & 0xffffff));

					if (node->rodata->gundl.secondary != NULL) {
						s6 = (Gfx *)(base + ((u32)node->rodata->gundl.secondary & 0xffffff));
					}

					vertices = (struct gfxvtx *)base;
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c784(model, node);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, node);
			break;
		}

		if (s4 && bgTestHitOnChr(model, arg3, &sp74, arg4, s4, s6, vertices, &sp98, arg5)) {
			ok = true;
			sp88 = node;
			*arg7 = sp84;
			*hitpart = sp84->rodata->bbox.hitpart;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node == endnode) {
					node = NULL;
					break;
				}

				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	if (ok) {
		*arg6 = sqrtf(sp98);
		*arg10 = sp88;
		*arg9 = model0001a524(sp88, 0);
	}

	var8005efc0 = 0.0f;

	return ok;
}

static bool func0f06c28c(struct chrdata *chr, struct coord *arg1, struct coord *arg2, struct coord *arg3, f32 arg4, struct coord *arg5, struct coord *arg6, struct coord *arg7, struct coord *arg8, f32 *arg9)
{
	f32 spec;
	struct prop *prop = chr->prop;
	f32 spe4 = chr0f0278a4(chr);
	f32 x = (prop->pos.f[0] - arg1->f[0]);
	f32 y = (prop->pos.f[1] - arg1->f[1]);
	f32 z = (prop->pos.f[2] - arg1->f[2]);
	f32 spd4 = x * arg3->f[0] + y * arg3->f[1] + z * arg3->f[2];
	s32 hitpart = 0;
	struct modelnode *spcc = NULL;
	bool result = false;
	struct prop *child;
	struct coord spb8;
	struct coord spac;
	struct hitthing sp7c;
	s32 sp78 = 0;
	struct modelnode *sp74 = NULL;
	struct model *model = chr->model;

	if (chr->cshield > 0.0f) {
		var8005efc0 = 10.0f / chr->model->scale;
	}

	if (-spe4 <= spd4 && spd4 <= arg4 + spe4 && func0f06b39c(arg1, arg3, &prop->pos, spe4)) {
		if ((prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)) {
			if (var8005efc0 > 0.0f) {
				hitpart = model000225d4(model, arg5, arg6, &spcc);

				while (hitpart > 0) {
					if (func0f084594(model, spcc, arg5, arg6, &sp7c, &sp78, &sp74)) {
						mtx4TransformVec(&model->matrices[sp78], &sp7c.unk00, &spb8);

						spec = (spb8.f[0] - arg5->f[0]) * arg6->f[0]
							+ (spb8.f[1] - arg5->f[1]) * arg6->f[1]
							+ (spb8.f[2] - arg5->f[2]) * arg6->f[2];

						if (spec < *arg9) {
							mtx4RotateVec(&model->matrices[sp78], &sp7c.unk0c, &spac);

							*arg9 = spec;

							mtx4TransformVec(g_Vars.currentplayer->projectionmtx, &spb8, arg7);
							mtx4RotateVec(g_Vars.currentplayer->projectionmtx, &spac, arg8);

							if (arg8->x != 0.0f || arg8->y != 0.0f || arg8->z != 0.0f) {
								guNormalize(&arg8->x, &arg8->y, &arg8->z);
							} else {
								arg8->z = 1.0f;
							}

							g_EmbedProp = prop;
							g_EmbedModel = model;
							g_EmbedHitPart = hitpart;
							g_EmbedNode = spcc;
							g_EmbedSide = sp7c.unk28 / 2;

							var8006993c[0] = sp7c.unk00.x;
							var8006993c[1] = sp7c.unk00.y;
							var8006993c[2] = sp7c.unk00.z;

							result = true;
						}
					}

					hitpart = model000225d4(model, arg5, arg6, &spcc);
				}
			} else {
				hitpart = model000225d4(model, arg5, arg6, &spcc);

				if (hitpart > 0
						&& func0f06bea0(model, model->filedata->rootnode, model->filedata->rootnode, arg5, arg6, &sp7c.unk00, &spec, &spcc, &hitpart, &sp78, &sp74)
						&& spec < *arg9) {
					*arg9 = spec;
					mtx4TransformVec(g_Vars.currentplayer->projectionmtx, &sp7c.unk00, arg7);
					mtx4RotateVec(g_Vars.currentplayer->projectionmtx, &sp7c.unk0c, arg8);

					if (arg8->x != 0.0f || arg8->y != 0.0f || arg8->z != 0.0f) {
						guNormalize(&arg8->x, &arg8->y, &arg8->z);
					} else {
						arg8->z = 1.0f;
					}

					g_EmbedProp = prop;
					g_EmbedModel = model;
					g_EmbedHitPart = hitpart;
					g_EmbedNode = spcc;

					result = true;
				}
			}
		} else if (func0f06b488(prop, arg1, arg2, arg3, arg7, arg8, arg9)) {
			g_EmbedHitPart = HITPART_TORSO;
			result = true;
		}
	}

	if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		child = prop->child;

		while (child) {
			if (child->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
				if (func0f06b610(child->obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)) {
					result = true;
				}
			}

			child = child->next;
		}
	}

	if (var8005efc0 > 0.0f) {
		var8005efc0 = 0.0f;
	}

	return result;
}

static bool projectileFindCollidingProp(struct prop *prop, struct coord *pos1, struct coord *pos2, u32 cdtypes, struct coord *arg4, struct coord *arg5, s16 *rooms)
{
	bool result = false;
	f32 dist;
	s16 *propnumptr;
	s16 propnums[256];
	f32 spa8;
	bool spa4 = false;
	struct coord sp98;
	f32 tmp;
	struct coord sp88;
	struct coord sp7c;
	struct chrdata *chr;

	sp98.x = pos2->x - pos1->x;
	sp98.y = pos2->y - pos1->y;
	sp98.z = pos2->z - pos1->z;

	dist = sqrtf(sp98.f[0] * sp98.f[0] + sp98.f[1] * sp98.f[1] + sp98.f[2] * sp98.f[2]);

	if (dist == 0.0f) {
		return false;
	}

	tmp = 1.0f / dist;

	sp98.x *= tmp;
	sp98.y *= tmp;
	sp98.z *= tmp;

	sp88 = *pos1;

	mtx4TransformVecInPlace(g_Vars.currentplayer->worldtoscreenmtx, &sp88);

	sp7c = sp98;

	mtx4RotateVecInPlace(g_Vars.currentplayer->worldtoscreenmtx, &sp7c);

	spa8 = dist;

	if (cdtypes != 0) {
		roomGetProps(rooms, propnums, 256);

		for (propnumptr = propnums; *propnumptr >= 0; propnumptr++) {
			struct prop *iterprop = &g_Vars.props[*propnumptr];
			if (*propnumptr);

			if (iterprop != prop) {
				if (iterprop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
					struct defaultobj *obj = iterprop->obj;

					if ((obj->hidden & OBJHFLAG_ISRETICK) == 0 && (obj->flags2 & OBJFLAG2_THROWTHROUGH) == 0) {
						if (iterprop->type == PROPTYPE_DOOR) {
							if ((cdtypes & CDTYPE_DOORS) == 0 && (propDoorGetCdTypes(iterprop) & cdtypes) == 0) {
								continue;
							}
						} else {
							if ((cdtypes & CDTYPE_OBJS) == 0) {
								continue;
							}
						}

						if (func0f06b610(obj, pos1, pos2, &sp98, dist, &sp88, &sp7c, arg4, arg5, &spa8)) {
							spa4 = true;
						}
					}
				} else if (iterprop->type == PROPTYPE_CHR
						|| (iterprop->type == PROPTYPE_PLAYER && g_Vars.players[playermgrGetPlayerNumByProp(iterprop)]->haschrbody)) {
					struct chrdata *chr = iterprop->chr;

					if (iterprop->type == PROPTYPE_PLAYER) {
						if (!g_Vars.players[playermgrGetPlayerNumByProp(iterprop)]->bondperimenabled || (cdtypes & CDTYPE_PLAYERS) == 0) {
							continue;
						}
					} else if (iterprop->type == PROPTYPE_CHR) {
						if ((chr->hidden & CHRHFLAG_PERIMDISABLED)
								|| (chr->chrflags & CHRCFLAG_HIDDEN)
								|| (cdtypes & CDTYPE_CHRS) == 0) {
							continue;
						}
					}

					if (func0f06c28c(chr, pos1, pos2, &sp98, dist, &sp88, &sp7c, arg4, arg5, &spa8)) {
						spa4 = true;
					}
				} else if (iterprop->type == PROPTYPE_PLAYER
						&& g_Vars.players[playermgrGetPlayerNumByProp(iterprop)]->bondperimenabled) {
					if (func0f06b488(iterprop, pos1, pos2, &sp98, arg4, arg5, &spa8)) {
						spa4 = true;
					}
				}
			}
		}
	}

	if (spa4) {
		result = true;

		var8009ce78 = sp98;

		var8009ce88 = sp7c;
	}

	return result;
}

static s32 func0f06cd00(struct defaultobj *obj, struct coord *pos, struct coord *arg2, struct coord *arg3)
{
	struct prop *prop = obj->prop;
	s32 cdresult;
	struct hitthing hitthing;
	struct coord sp1c4;
	u32 stack;
	bool s0;
	s16 spcc[120];
	s16 *ptr;
	s16 spb8[8];
	s32 i;
	f32 scale = 1.0f;

	cdresult = CDRESULT_NOCOLLISION;

	if (g_Vars.normmplayerisrunning) {
		g_Vars.useperimshoot = true;
	}

	g_EmbedProp = 0;
	var80069944 = 0;

	sp1c4 = *pos;

	if ((prop->pos.x != pos->x || prop->pos.y != pos->y || prop->pos.z != pos->z)
			&& (obj->hidden & OBJHFLAG_PROJECTILE)
			&& (obj->projectile->flags & PROJECTILEFLAG_STICKY)) {
		portal00018148(&prop->pos, &sp1c4, prop->rooms, spb8, spcc, 20);

		ptr = spcc;

		while (*ptr != -1) {
			ptr++;
		}

		roomsGetActive(ptr, 100);

		for (i = 0; spcc[i] != -1; i++) {
			s0 = false;

			if (roomIsLoaded(spcc[i])) {
				if (bgTestHitInRoom(&prop->pos, &sp1c4, spcc[i], &hitthing)) {
					hitthing.unk00.x *= scale;
					hitthing.unk00.y *= scale;
					hitthing.unk00.z *= scale;

					var80069944 = hitthing.texturenum;

					s0 = true;

					if (g_Textures[hitthing.texturenum].surfacetype == SURFACETYPE_DEEPWATER) {
						struct coord spa4 = {0, 0, 0};
						s0 = false;
						sparksCreate(prop->rooms[0], prop, &hitthing.unk00, &spa4, &hitthing.unk0c, SPARKTYPE_DEEPWATER);
						propsnd0f0939f8(0, prop, SFX_HIT_WATER, -1, -1, 1024, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
						obj->hidden |= OBJHFLAG_REAPABLE;
					}
				}
			} else {
				s16 spa0[2];
				spa0[0] = spcc[i];
				spa0[1] = -1;

				if (cdExamLos09(&prop->pos, spa0, &sp1c4, CDTYPE_BG) == CDRESULT_COLLISION) {
					s0 = true;
					hitthing.unk00 = g_CdObstaclePos;
					cdGetGeoNormal(g_CdObstacleGeo, &hitthing.unk0c);
				}
			}

			if (s0
					&& ((prop->pos.x <= sp1c4.x && hitthing.unk00.x <= sp1c4.x && prop->pos.x <= hitthing.unk00.x) || (sp1c4.x <= prop->pos.x && sp1c4.x <= hitthing.unk00.x && hitthing.unk00.x <= prop->pos.x))
					&& ((prop->pos.y <= sp1c4.y && hitthing.unk00.y <= sp1c4.y && prop->pos.y <= hitthing.unk00.y) || (sp1c4.y <= prop->pos.y && sp1c4.y <= hitthing.unk00.y && hitthing.unk00.y <= prop->pos.y))
					&& ((prop->pos.z <= sp1c4.z && hitthing.unk00.z <= sp1c4.z && prop->pos.z <= hitthing.unk00.z) || (sp1c4.z <= prop->pos.z && sp1c4.z <= hitthing.unk00.z && hitthing.unk00.z <= prop->pos.z))
					&& (prop->pos.f[0] != hitthing.unk00.f[0] || prop->pos.f[1] != hitthing.unk00.f[1] || prop->pos.f[2] != hitthing.unk00.f[2])) {
				cdresult = CDRESULT_COLLISION;

				sp1c4 = hitthing.unk00;

				*arg3 = hitthing.unk0c;
			}
		}

		if (!projectileFindCollidingProp(prop, &prop->pos, &sp1c4, CDTYPE_ALL, arg2, arg3, spcc)) {
			if (cdresult == CDRESULT_COLLISION) {
				*arg2 = sp1c4;
			}
		} else {
			cdresult = CDRESULT_COLLISION;
		}

		if (cdresult != CDRESULT_NOCOLLISION) {
			struct coord dist;
			f32 sqdist;
			f32 mult;

			dist.x = pos->x - prop->pos.x;
			dist.y = pos->y - prop->pos.y;
			dist.z = pos->z - prop->pos.z;

			sqdist = dist.f[0] * dist.f[0] + dist.f[1] * dist.f[1] + dist.f[2] * dist.f[2];

			if (sqdist > 0.01f) {
				mult = 0.1f / sqrtf(sqdist);
			} else {
				mult = 0.5f;
			}

			arg2->x -= mult * dist.x;
			arg2->y -= mult * dist.y;
			arg2->z -= mult * dist.z;

			if (arg3->x != 0.0f || arg3->y != 0.0f || arg3->z != 0.0f) {
				guNormalize(&arg3->x, &arg3->y, &arg3->z);
			} else {
				arg3->z = 1.0f;
			}
		}
	}

	if (g_Vars.normmplayerisrunning) {
		g_Vars.useperimshoot = false;
	}

	return cdresult;
}

static bool func0f06d37c(struct defaultobj *obj, struct coord *arg1, struct coord *arg2, struct coord *arg3)
{
	struct prop *prop = obj->prop;
	f32 radius = objGetRadius(obj);
	bool result = true;
	bool sp98 = false;
	struct coord sp8c;
	struct coord sp80;
	s16 rooms[8];
	struct coord sp64;
	struct coord sp58;
	struct coord sp4c;
	f32 f2;

	g_EmbedProp = NULL;
	var80069944 = 0;

	sp80 = *arg1;

	if (prop->pos.x != arg1->x || prop->pos.y != arg1->y || prop->pos.z != arg1->z) {
		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			if (cdExamCylMove08(&prop->pos, prop->rooms, &sp80, rooms, radius, CDTYPE_ALL, false, 0.0f, 0.0f) != CDRESULT_COLLISION) {
				setup0f09233c(obj, &sp80, obj->realrot, rooms);

				if (cdExamCylMove02(&prop->pos, &sp80, radius, rooms, CDTYPE_ALL, false, 0.0f, 0.0f) != CDRESULT_COLLISION) {
					prop->pos = sp80;

					propDeregisterRooms(prop);
					roomsCopy(rooms, prop->rooms);
				} else {
					result = false;
				}
			} else {
				result = false;
			}

			if (!result) {
				arg3->x = g_CdEdgeVtx2.z - g_CdEdgeVtx1.z;
				arg3->y = 0.0f;
				arg3->z = g_CdEdgeVtx1.x - g_CdEdgeVtx2.x;

				if (arg3->x != 0.0f || arg3->z != 0.0f) {
					guNormalize(&arg3->x, &arg3->y, &arg3->z);
				} else {
					arg3->z = 1.0f;
				}

				if (sp80.x != prop->pos.x || sp80.y != prop->pos.y || sp80.z != prop->pos.z) {
					sp8c.x = sp80.x - prop->pos.x;
					sp8c.y = sp80.y - prop->pos.y;
					sp8c.z = sp80.z - prop->pos.z;

					func0f02e4f8(&prop->pos, &sp8c, arg2);

					if (prop->pos.x < sp80.x) {
						if (arg2->x > sp80.x) {
							arg2->x = sp80.x;
						} else if (arg2->x < prop->pos.x) {
							arg2->x = prop->pos.x;
						}
					} else {
						if (arg2->x > prop->pos.x) {
							arg2->x = prop->pos.x;
						} else if (arg2->x < sp80.x) {
							arg2->x = sp80.x;
						}
					}

					if (prop->pos.y < sp80.y) {
						if (arg2->y > sp80.y) {
							arg2->y = sp80.y;
						} else if (arg2->y < prop->pos.y) {
							arg2->y = prop->pos.y;
						}
					} else {
						if (arg2->y > prop->pos.y) {
							arg2->y = prop->pos.y;
						} else if (arg2->y < sp80.y) {
							arg2->y = sp80.y;
						}
					}

					if (prop->pos.z < sp80.z) {
						if (arg2->z > sp80.z) {
							arg2->z = sp80.z;
						} else if (arg2->z < prop->pos.z) {
							arg2->z = prop->pos.z;
						}
					} else {
						if (arg2->z > prop->pos.z) {
							arg2->z = prop->pos.z;
						} else if (arg2->z < sp80.z) {
							arg2->z = sp80.z;
						}
					}

					f2 = g_Cd8009a8b0 * 0.99f;

					sp4c.x = sp8c.x * f2 + prop->pos.x;
					sp4c.y = sp80.y;
					sp4c.z = sp8c.z * f2 + prop->pos.z;

					if (cdExamCylMove07(&prop->pos, prop->rooms, &sp4c, rooms, CDTYPE_ALL, false, 0.0f, 0.0f) != CDRESULT_COLLISION) {
						setup0f09233c(obj, &sp4c, obj->realrot, rooms);

						if (cdTestVolume(&sp4c, radius, rooms, CDTYPE_ALL, CHECKVERTICAL_NO, 0.0f, 0.0f) != CDRESULT_COLLISION) {
							prop->pos = sp4c;

							propDeregisterRooms(prop);
							roomsCopy(rooms, prop->rooms);

							sp98 = true;
						}
					}
				} else {
					*arg2 = sp80;
				}

				if (!sp98) {
					sp4c.x = prop->pos.x;
					sp4c.y = sp80.y;
					sp4c.z = prop->pos.z;

					func0f065e74(&prop->pos, prop->rooms, &sp4c, rooms);

					prop->pos.y = sp4c.y;

					propDeregisterRooms(prop);
					roomsCopy(rooms, prop->rooms);
				}
			}
		}
	}

	return result;
}

/**
 * Update a speed and distance travelled, factoring in acceleration,
 * deceleration and the global update multiplier.
 *
 * The new speed and distance done are written back to those pointers.
 */
void applySpeed(f32 *distdone, f32 maxdist, f32 *speedptr, f32 accel, f32 decel, f32 maxspeed)
{
	f32 speed = *speedptr;
	s32 i;

	for (i = 0; i < g_Vars.lvupdate60; i++) {
		f32 limit = speed * speed * 0.5f / decel;
		f32 distremaining = maxdist - *distdone;

		if (distremaining > 0.0f) {
			if (speed > 0.0f && distremaining <= limit) {
				// Slow down for end
				speed -= decel;

				if (speed < decel) {
					speed = decel;
				}
			} else if (speed < maxspeed) {
				// Accelerate
				if (speed < 0.0f) {
					speed += decel;
				} else {
					speed += accel;
				}

				if (speed > maxspeed) {
					speed = maxspeed;
				}
			}

			if (speed >= distremaining) {
				*distdone = maxdist;
				break;
			}

			*distdone += speed;
		} else {
			if (speed < 0.0f && -distremaining <= limit) {
				speed += decel;

				if (speed > -decel) {
					speed = -decel;
				}
			} else if (speed > -maxspeed) {
				if (speed > 0.0f) {
					speed -= decel;
				} else {
					speed -= accel;
				}

				if (speed < -maxspeed) {
					speed = -maxspeed;
				}
			}

			if (speed <= distremaining) {
				*distdone = maxdist;
				break;
			}

			*distdone += speed;
		}
	}

	*speedptr = speed;
}

void applyRotation(f32 *angle, f32 maxrot, f32 *speed, f32 accel, f32 decel, f32 maxspeed)
{
	f32 tmp = maxrot - *angle;

	if (tmp < -M_PI) {
		maxrot += M_BADTAU;
	} else if (tmp >= M_PI) {
		maxrot -= M_BADTAU;
	}

	applySpeed(angle, maxrot, speed, accel, decel, maxspeed);

	if (*angle < 0) {
		*angle += M_BADTAU;
	}

	if (*angle >= M_BADTAU) {
		*angle -= M_BADTAU;
	}
}

/**
 * Make a projectile fall to the ground once it's hit a wall.
 *
 * The vast majority of this is calculating the rotation for the projectile.
 */
static void projectileFall(struct defaultobj *obj, f32 arg1[3][3])
{
	s32 t2;
	s32 t4;
	s32 t3;
	struct coord sp188;
	Mtxf sp148;
	Mtxf sp108;
	Mtxf spc8;
	Mtxf sp88;
	f32 sp84;
	f32 sp80;
	struct modelrodata_bbox *bbox;
	s32 i;
	u32 stack[2];
	f32 sp6c;
	struct projectile *projectile;
	f32 f2;
	f32 sp58[3];
	f32 sp4c[3];
	f32 sp40[3];
	s32 prev;
	s32 next;

	obj->hidden &= ~OBJHFLAG_00010000;

	if (obj->hidden & OBJHFLAG_PROJECTILE) {
		projectile = obj->projectile;

		if (obj->type == OBJTYPE_DOOR) {
			objFreeProjectile(obj);
			return;
		}

		projectile->ownerprop = NULL;

		projectile->flags &= ~PROJECTILEFLAG_AIRBORNE;
		projectile->flags |= PROJECTILEFLAG_FALLING;
		projectile->flags &= ~PROJECTILEFLAG_STICKY;

		mtx3ToMtx4(obj->realrot, &sp148);
		mtx4GetRotation(sp148.m, &sp188);
		mtx4LoadRotation(&sp188, &sp108);
		quaternion0f096ca0(&sp188, projectile->unk068);
		mtx4LoadRotationFrom(sp108.m, spc8.m);
		mtx4MultMtx4(&spc8, &sp148, &sp88);

		projectile->unk0b8[0] = sqrtf(sp88.m[0][0] * sp88.m[0][0] + sp88.m[0][1] * sp88.m[0][1] + sp88.m[0][2] * sp88.m[0][2]);
		projectile->unk0b8[1] = sqrtf(sp88.m[1][0] * sp88.m[1][0] + sp88.m[1][1] * sp88.m[1][1] + sp88.m[1][2] * sp88.m[1][2]);
		projectile->unk0b8[2] = sqrtf(sp88.m[2][0] * sp88.m[2][0] + sp88.m[2][1] * sp88.m[2][1] + sp88.m[2][2] * sp88.m[2][2]);

		t2 = -1;
		t4 = -1;
		t3 = -1;

		bbox = objFindBboxRodata(obj);

		sp4c[0] = bbox->xmax - bbox->xmin;
		sp4c[1] = bbox->ymax - bbox->ymin;
		sp4c[2] = bbox->zmax - bbox->zmin;

		for (i = 0; i < 3; i++) {
			sp58[i] = sp4c[i] * projectile->unk0b8[i];
			sp40[i] = obj->realrot[i][1] * sp4c[i];

			if (sp40[i] < 0.0f) {
				sp40[i] = -sp40[i];
			}
		}

		if (obj->flags3 & (OBJFLAG3_00000008 | OBJFLAG3_00000200 | OBJFLAG3_08000000)) {
			if (obj->flags3 & OBJFLAG3_00000008) {
				for (i = 0; i < 3; i++) {
					next = i + 1;
					prev = i + 2;
					WRAP(next, 3);
					WRAP(prev, 3);
					if (sp58[i] < sp58[next] && sp58[i] < sp58[prev]) {
						t4 = i;
						break;
					}
				}
			} else {
				t4 = 1;
			}

			next = t4 + 1;
			prev = t4 + 2;
			WRAP(next, 3);
			WRAP(prev, 3);

			if (sp40[prev] <= sp40[next]) {
				t2 = next;
				t3 = prev;
			} else {
				t2 = prev;
				t3 = next;
			}
		}

		if (t2 < 0) {
			for (i = 0; i < 3; i++) {
				next = i + 1;
				prev = i + 2;
				WRAP(next, 3);
				WRAP(prev, 3);

				if (sp58[i] > sp58[next] * 3.0f && sp58[i] > sp58[prev] * 3.0f) {
					t2 = i;

					if (sp58[next] > sp58[prev] * 2.0f) {
						t4 = prev;
						t3 = next;
					} else if (sp58[prev] > sp58[next] * 2.0f) {
						t4 = next;
						t3 = prev;
					} else {
						if ((random() % 2) == 0) {
							t4 = prev;
							t3 = next;
						} else {
							t4 = next;
							t3 = prev;
						}
					}
					break;
				}
			}
		}

		if (t2 < 0) {
			for (i = 0; i < 3; i++) {
				next = i + 1;
				prev = i + 2;
				WRAP(next, 3);
				WRAP(prev, 3);

				if (sp58[i] > sp58[next] * 3.0f || sp58[i] > sp58[prev] * 3.0f) {
					if (sp58[i] > sp58[next] * 3.0f) {
						t4 = next;
					} else if (sp58[i] > sp58[prev] * 3.0f) {
						t4 = prev;
					}

					next = t4 + 1;
					prev = t4 + 2;
					WRAP(next, 3);
					WRAP(prev, 3);

					if (sp40[prev] <= sp40[next]) {
						t2 = next;
						t3 = prev;
					} else {
						t2 = prev;
						t3 = next;
					}
					break;
				}
			}
		}

		if (t2 < 0) {
			for (i = 0; i < 3; i++) {
				next = i + 1;
				prev = i + 2;
				WRAP(next, 3);
				WRAP(prev, 3);

				if (sp40[i] >= sp40[next] && sp40[i] >= sp40[prev]) {
					t4 = i;

					if (sp40[prev] <= sp40[next]) {
						t3 = prev;
						t2 = next;
					} else {
						t2 = prev;
						t3 = next;
					}
					break;
				}
			}
		}

		if (t2 < 0) {
			t2 = 0;
			t4 = 1;
			t3 = 2;
		}

		sp84 = obj->realrot[t2][0];
		sp80 = obj->realrot[t2][2];

		if (sp84 != 0.0f || sp80 != 0.0f) {
			f32 f0 = sqrtf(sp84 * sp84 + sp80 * sp80);

			if (f0 > 0.0f) {
				f0 = 1.0f / f0;
				sp84 *= f0;
				sp80 *= f0;
			} else {
				sp84 = 0.0f;
				sp80 = 1.0f;
			}
		} else {
			sp84 = 0.0f;
			sp80 = 1.0f;
		}

		spc8.m[t2][0] = sp84;
		spc8.m[t2][1] = 0.0f;
		spc8.m[t2][2] = sp80;
		spc8.m[t2][3] = 0.0f;

		next = t4 + 1;
		prev = t4 + 2;
		WRAP(next, 3);
		WRAP(prev, 3);

		if (((obj->realrot[t4][1] >= 0.0f || (obj->flags3 & OBJFLAG3_08000000)) && t3 == next)
				|| (obj->realrot[t4][1] <= 0.0f && (obj->flags3 & OBJFLAG3_08000000) == 0 && t3 == prev)) {
			spc8.m[t3][0] = -sp80;
			spc8.m[t3][1] = 0.0f;
			spc8.m[t3][2] = sp84;
			spc8.m[t3][3] = 0.0f;
		} else {
			spc8.m[t3][0] = sp80;
			spc8.m[t3][1] = 0.0f;
			spc8.m[t3][2] = -sp84;
			spc8.m[t3][3] = 0.0f;
		}

		if (obj->realrot[t4][1] >= 0.0f || (obj->flags3 & OBJFLAG3_08000000)) {
			spc8.m[t4][0] = 0.0f;
			spc8.m[t4][1] = 1.0f;
			spc8.m[t4][2] = 0.0f;
			spc8.m[t4][3] = 0.0f;
		} else {
			spc8.m[t4][0] = 0.0f;
			spc8.m[t4][1] = -1.0f;
			spc8.m[t4][2] = 0.0f;
			spc8.m[t4][3] = 0.0f;
		}

		spc8.m[3][0] = 0.0f;
		spc8.m[3][1] = 0.0f;
		spc8.m[3][2] = 0.0f;
		spc8.m[3][3] = 1.0f;

		mtx4GetRotation(spc8.m, &sp188);
		quaternion0f096ca0(&sp188, projectile->unk078);
		quaternion0f0976c0(projectile->unk068, projectile->unk078);

		projectile->unk060 = 0.0f;

		sp6c = acosf(spc8.m[t2][0] * sp108.m[t2][0] + spc8.m[t2][1] * sp108.m[t2][1] + spc8.m[t2][2] * sp108.m[t2][2]);

		if (sp6c > 0.0f && obj->realrot[t2][1] > 0.0f && obj->realrot[t2][1] > arg1[t2][1]) {
			projectile->unk064 = 0.05f / (sp6c * 0.63672113f);
		} else if (sp6c > 0.0f && obj->realrot[t2][1] < 0.0f && obj->realrot[t2][1] < arg1[t2][1]) {
			projectile->unk064 = 0.05f / (sp6c * 0.63672113f);
		} else {
			f2 = acosf((arg1[t2][0] * obj->realrot[t2][0] + arg1[t2][1] * obj->realrot[t2][1] + arg1[t2][2] * obj->realrot[t2][2]) / (obj->model->scale * obj->model->scale)) / g_Vars.lvupdate60freal;

			if (sp6c != 0.0f) {
				projectile->unk064 = f2 / sp6c;
			} else {
				projectile->unk064 = 1.0f;
			}
		}

		if (projectile->unk064 < 0.0f) {
			projectile->unk064 = -projectile->unk064;
		}

		if (projectile->unk064 < 0.03f) {
			projectile->unk064 = 0.03f;
		} else if (projectile->unk064 > 0.15f) {
			projectile->unk064 = 0.15f;
		}
	}
}

static void knifePlayWooshSound(struct defaultobj *obj)
{
	if (obj->hidden & OBJHFLAG_PROJECTILE) {
		if ((obj->projectile->flags & PROJECTILEFLAG_AIRBORNE)
				&& obj->projectile->bouncecount <= 0
				&& (obj->hidden & OBJHFLAG_00000020)) {
			u16 soundnums[] = { SFX_8074, SFX_8074, SFX_8074 };
			s32 index = random() % ARRAYCOUNT(soundnums);

			if (obj->projectile->lastwooshframe < g_Vars.lvframe60 - TICKS(6)) {
				func0f0926bc(obj->prop, 1, 0xffff);

				if (!g_LvIsPaused) {
					propsnd0f0939f8(0, obj->prop, soundnums[index], -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
					obj->projectile->lastwooshframe = g_Vars.lvframe60;
				}
			}
		} else {
			obj->hidden &= ~OBJHFLAG_00000020;
			func0f0926bc(obj->prop, 1, 0xffff);
		}
	}
}

static void func0f06e9cc(struct coord *arg0, Mtxf *arg1)
{
	f32 sp124;
	f32 sp120;
	f32 sp11c;
	f32 sp118;
	f32 sp114;
	f32 f0;
	f32 sp10c;
	f32 sp108;
	f32 sp104;
	f32 a;
	f32 b;
	f32 stack;
	f32 spf4;
	f32 spf0;
	Mtxf spb0;
	Mtxf sp70;
	Mtxf sp30;
	struct coord sp24;

	f0 = sqrtf(arg0->f[0] * arg0->f[0] + arg0->f[1] * arg0->f[1] + arg0->f[2] * arg0->f[2]);

	sp10c = arg0->x / f0;
	sp108 = arg0->y / f0;
	sp104 = arg0->z / f0;

	if (sp10c == 0.0f && sp104 == 0.0f) {
		sp124 = 0.0f;
		sp120 = 0.0f;
		sp11c = sp108;
		sp118 = 1.0f;
		sp114 = 0.0f;
	} else {
		a = sqrtf(sp10c * sp10c + sp104 * sp104);
		b = sp10c / a;

		sp118 = sp104 / a;
		sp114 = -b;

		sp124 = sp108 * b;
		sp120 = -a;
		sp11c = sp108 * sp118;
	}

	spf4 = atan2f(sp118, sp114);

	mtx4LoadYRotation(-spf4, &spb0);

	sp24.x = sp124;
	sp24.y = sp120;
	sp24.z = sp11c;

	mtx4RotateVecInPlace(&spb0, &sp24);

	spf0 = atan2f(sp24.x, sp24.y);

	mtx4LoadYRotation(-1.5705463f + spf4, &sp70);
	mtx4LoadXRotation(-1.5705463f - spf0, &sp30);

	mtx4MultMtx4(&sp70, &sp30, arg1);
}

static void objLand2(struct defaultobj *obj, struct coord *arg1, struct coord *arg2)
{
	Mtxf sp40;
	struct coord newpos;
	struct modelrodata_bbox *bbox = modelFindBboxRodata(obj->model);
	f32 ymin = objGetLocalYMin(bbox);
	struct prop *prop = obj->prop;
	s16 newrooms[8];

	func0f06e9cc(arg2, &sp40);
	mtx00015f04(obj->model->scale, &sp40);

	newpos.x = arg1->x - sp40.m[1][0] * ymin;
	newpos.y = arg1->y - sp40.m[1][1] * ymin;
	newpos.z = arg1->z - sp40.m[1][2] * ymin;

	func0f065e74(&prop->pos, prop->rooms, &newpos, newrooms);
	func0f06a580(obj, &newpos, &sp40, newrooms);
}

static void boltLand(struct weaponobj *weapon, struct coord *arg1)
{
	Mtxf mtx;
	struct coord newpos;
	struct modelrodata_bbox *bbox;
	s32 beamnum;
	f32 zmax;
	struct prop *prop;
	s16 newrooms[8];

	bbox = modelFindBboxRodata(weapon->base.model);
	prop = weapon->base.prop;

	weapon->timer240 = 13;

	zmax = objGetLocalZMax(bbox);
	zmax -= 25.0f + 2.0f * RANDOMFRAC();

	mtx3ToMtx4(weapon->base.realrot, &mtx);

	newpos.x = arg1->x - mtx.m[2][0] * zmax;
	newpos.y = arg1->y - mtx.m[2][1] * zmax;
	newpos.z = arg1->z - mtx.m[2][2] * zmax;

	func0f065dd8(&prop->pos, prop->rooms, &newpos, newrooms);
	func0f06a580(&weapon->base, &newpos, &mtx, newrooms);

	beamnum = boltbeamFindByProp(prop);

	if (beamnum != -1) {
		boltbeamSetTailPos(beamnum, &prop->pos);
		boltbeamSetAutomatic(beamnum, 2100);
	}
}

static void knifeLand(struct defaultobj *obj, struct coord *arg1, struct coord *arg2)
{
	Mtxf spd0;
	Mtxf sp90;
	Mtxf sp50;
	struct coord newpos;
	struct modelrodata_bbox *bbox = modelFindBboxRodata(obj->model);
	f32 zero = 0.0f;
	struct prop *prop = obj->prop;
	s16 newrooms[8];
	struct coord sp1c;

	sp1c.x = RANDOMFRAC() * 0.8f + arg2->x - 0.4f;
	sp1c.y = RANDOMFRAC() * 0.8f + arg2->y - 0.4f;
	sp1c.z = RANDOMFRAC() * 0.8f + arg2->z - 0.4f;

	func0f06e9cc(&sp1c, &sp90);
	mtx4LoadXRotation(-1.5705463f, &sp50);
	mtx4MultMtx4(&sp90, &sp50, &spd0);
	mtx00015f04(obj->model->scale, &spd0);

	newpos.x = arg1->x - zero;
	newpos.y = arg1->y - zero;
	newpos.z = arg1->z - zero;

	func0f065e74(&prop->pos, prop->rooms, &newpos, newrooms);
	func0f06a580(obj, &newpos, &spd0, newrooms);
}

static bool objEmbed(struct prop *prop, struct prop *parent, struct model *model, struct modelnode *node)
{
	if (parent->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		struct defaultobj *obj = prop->obj;
		Mtxf sp134;
		Mtxf spf4;
		Mtxf spb4;
		Mtxf sp74;
		Mtxf sp34;
		struct coord sp28;
		Mtxf *sp24;

		obj->embedment = embedmentAllocate();

		if (obj->embedment) {
			sp24 = model0001a5cc(model, node, 0);

			obj->hidden |= OBJHFLAG_EMBEDDED;

			propDeregisterRooms(prop);
			propDelist(prop);
			propDisable(prop);

			obj->model->attachedtomodel = model;
			obj->model->attachedtonode = node;

			propReparent(prop, parent);
			modelGetRootPosition(obj->model, &sp28);

			sp28.x = -sp28.x;
			sp28.y = -sp28.y;
			sp28.z = -sp28.z;

			mtx4LoadTranslation(&sp28, &sp74);
			mtx3ToMtx4(obj->realrot, &sp34);
			mtx4SetTranslation(&prop->pos, &sp34);
			mtx00015be4(&sp34, &sp74, &sp134);
			mtx00015be4(g_Vars.currentplayer->projectionmtx, sp24, &spf4);
			mtx000172f0(spf4.m, spb4.m);
			mtx00015be4(&spb4, &sp134, &obj->embedment->matrix);

			return true;
		}
	}

	return false;
}

static void objLand(struct prop *prop, struct coord *arg1, struct coord *arg2, bool *embedded)
{
	struct defaultobj *obj = prop->obj;
	struct prop *ownerprop = NULL;

	if (obj->hidden & OBJHFLAG_PROJECTILE) {
		ownerprop = obj->projectile->ownerprop;
		objFreeProjectile(obj);
	}

	obj->hidden |= OBJHFLAG_00020000;

	if (obj->type == OBJTYPE_WEAPON) {
		struct weaponobj *weapon = (struct weaponobj *)obj;

		if (weapon->weaponnum == WEAPON_ECMMINE
				|| weapon->weaponnum == WEAPON_COMMSRIDER
				|| weapon->weaponnum == WEAPON_TRACERBUG
				|| weapon->weaponnum == WEAPON_TARGETAMPLIFIER) {
			obj->flags |= OBJFLAG_INVINCIBLE;
			obj->flags |= OBJFLAG_00400000;
			obj->flags2 |= OBJFLAG2_IMMUNETOGUNFIRE;
		}

		if (weapon->weaponnum == WEAPON_BOLT) {
			boltLand(weapon, arg1);
		} else if (weapon->weaponnum == WEAPON_COMBATKNIFE) {
			knifeLand(obj, arg1, arg2);
		} else {
			objLand2(obj, arg1, arg2);
		}
	} else if (obj->type == OBJTYPE_AUTOGUN) {
		struct autogunobj *autogun = (struct autogunobj *)obj;

		objLand2(obj, arg1, arg2);

		autogun->yzero = atan2f(arg2->x, arg2->z);
		autogun->xzero = atan2f(arg2->y, sqrtf(arg2->f[0] * arg2->f[0] + arg2->f[2] * arg2->f[2]));

		autogun->xrot = autogun->xzero;
		autogun->yrot = autogun->yzero;
	}

	if (g_EmbedProp) {
		if (obj->type == OBJTYPE_WEAPON) {
			struct weaponobj *weapon = (struct weaponobj *)obj;

			bgunPlayPropHitSound(&weapon->gset, g_EmbedProp, -1);

			if (weapon->weaponnum == WEAPON_COMBATKNIFE
					&& (g_EmbedProp->type & (PROPTYPE_CHR | PROPTYPE_PLAYER))) {
				chrSetPoisoned(g_EmbedProp->chr, ownerprop);
			}
		}

		if (g_EmbedProp->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
			if (objEmbed(prop, g_EmbedProp, g_EmbedModel, g_EmbedNode)) {
				*embedded = true;
			}
		} else {
			obj->hidden |= OBJHFLAG_REAPABLE;
		}
	} else if (obj->type == OBJTYPE_WEAPON) {
		struct weaponobj *weapon = (struct weaponobj *)obj;

		bgunPlayBgHitSound(&weapon->gset, arg1, -1, prop->rooms);
	}
}

static bool propExplode(struct prop *prop, s32 exptype)
{
	struct defaultobj *obj = prop->obj;
	s32 playernum = (obj->hidden & 0xf0000000) >> 28;
	bool result;

	if (prop->parent) {
		struct prop *parent = prop->parent;
		struct coord pos;
		s16 rooms[8];

		while (parent->parent) {
			parent = parent->parent;
		}

		if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
			Mtxf *mtx = model0001a60c(obj->model);

			pos.x = mtx->m[3][0];
			pos.y = mtx->m[3][1];
			pos.z = mtx->m[3][2];

			mtx4TransformVecInPlace(g_Vars.currentplayer->projectionmtx, &pos);
		} else {
			pos = parent->pos;
		}

		func0f065e74(&parent->pos, parent->rooms, &pos, rooms);

		result = explosionCreateComplex(NULL, &pos, rooms, exptype, playernum);
	} else if ((obj->hidden & (OBJHFLAG_EMBEDDED | OBJHFLAG_PROJECTILE | OBJHFLAG_00020000)) == OBJHFLAG_00020000) {
		struct coord sp5c;
		struct coord sp50;
		f32 ymin = objGetLocalYMin(modelFindBboxRodata(obj->model));
		s32 room = prop->rooms[0];

		sp50.x = obj->realrot[1][0];
		sp50.y = obj->realrot[1][1];
		sp50.z = obj->realrot[1][2];

		sp5c.x = prop->pos.f[0] + obj->realrot[1][0] * ymin;
		sp5c.y = prop->pos.f[1] + obj->realrot[1][1] * ymin;
		sp5c.z = prop->pos.f[2] + obj->realrot[1][2] * ymin;

		result = explosionCreate(NULL, &prop->pos, prop->rooms, exptype,
				playernum, true, &sp5c, room, &sp50);
	} else {
		result = explosionCreateComplex(NULL, &prop->pos, prop->rooms, exptype, playernum);
	}

	return result;
}

static void ammocrateTick(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;

	if (obj->flags & OBJFLAG_AMMOCRATE_EXPLODENOW) {
		propExplode(prop, EXPLOSIONTYPE_12);
		obj->hidden |= OBJHFLAG_REAPABLE;
	}
}

/**
 * Handles the following:
 *
 * - Grenade timers
 * - Wall hugger timers
 * - Nbomb timers
 * - Rockets
 * - Timed mines
 * - Remote mines
 * - Proximity items
 * - Removal of weapons when there are too many on-screen
 */
static void weaponTick(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;
	struct weaponobj *weapon = prop->weapon;

	// Handle grenade timers
	if (((weapon->weaponnum == WEAPON_GRENADE && weapon->gunfunc == FUNC_PRIMARY)
				|| weapon->weaponnum == WEAPON_GRENADEROUND)
			&& weapon->timer240 >= 0) {
		// Handle Devastator wall hugger timer
		if (weapon->weaponnum == WEAPON_GRENADEROUND
				&& weapon->gunfunc == FUNC_SECONDARY
				&& weapon->timer240 > 0) {
			if (weapon->timer240 >= 2) {
				// Still on the wall
				weapon->timer240 -= g_Vars.lvupdate240;

				if (weapon->timer240 < 8) {
					// Time to fall
					struct coord direction = {0, -10, 0};
					struct prop *parent;
					struct projectile *projectile = NULL;

					func0f0685e4(prop);

					if (obj->hidden & OBJHFLAG_EMBEDDED) {
						projectile = obj->embedment->projectile;
					} else if (obj->hidden & OBJHFLAG_PROJECTILE) {
						projectile = obj->projectile;
					}

					if (projectile) {
						parent = prop;

						while (parent->parent) {
							parent = parent->parent;
						}

						if (parent && (parent->type & (PROPTYPE_CHR | PROPTYPE_PLAYER))) {
							parent->chr->hidden |= CHRHFLAG_00000001;
						} else {
							projectile->ownerprop = NULL;
							projectile->flags |= PROJECTILEFLAG_AIRBORNE;
						}

						weapon->timer240 = 1;

						projectileSetSticky(prop);

						projectile->speed = direction;

						mtx4LoadIdentity(&projectile->mtx);

						projectile->obj = (struct defaultobj *)weapon;
						projectile->unk0d8 = g_Vars.lvframenum;
					} else {
						// Couldn't create projectile - try again next frame
						weapon->timer240 = 2;
					}
				}
			} else {
				// empty
			}
		} else {
			// Normal grenade
			weapon->timer240 -= g_Vars.lvupdate240;

			if (weapon->timer240 < 0) {
				s32 i;

				propUnsetDangerous(prop);

				if (weapon->gunfunc == FUNC_2) {
					propExplode(prop, EXPLOSIONTYPE_SDGRENADE);
				} else {
					propExplode(prop, (obj->flags2 & OBJFLAG2_WEAPON_HUGEEXP) ? EXPLOSIONTYPE_HUGE17 : EXPLOSIONTYPE_ROCKET);
				}

				obj->hidden |= OBJHFLAG_REAPABLE;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					if (g_Vars.players[i]->slayerrocket == (struct weaponobj *) obj) {
						g_Vars.players[i]->slayerrocket = NULL;
						g_Vars.players[i]->visionmode = VISIONMODE_SLAYERROCKETSTATIC;
					}
				}
			}
		}
	} else if (weapon->weaponnum == WEAPON_NBOMB && weapon->gunfunc == FUNC_PRIMARY) {
		// Handle nbombs being thrown normally
		if (weapon->timer240 >= 0) {
			struct prop *ownerprop = NULL;

			weapon->timer240 -= g_Vars.lvupdate240;

			if (weapon->timer240 < 0) {
				// Nbombs detonate when they hit the ground, so this code only
				// runs if it's airborne for the entire duration of its timer.
				s32 ownerplayernum = (obj->hidden & 0xf0000000) >> 28;
				s32 i;

				if (g_Vars.normmplayerisrunning) {
					struct chrdata *chr = mpGetChrFromPlayerIndex(ownerplayernum);

					if (chr) {
						ownerprop = chr->prop;
					}
				}

				nbombCreateStorm(&prop->pos, ownerprop);
				propUnsetDangerous(prop);

				obj->hidden |= OBJHFLAG_REAPABLE;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					if (g_Vars.players[i]->slayerrocket == (struct weaponobj *)obj) {
						g_Vars.players[i]->slayerrocket = NULL;
						g_Vars.players[i]->visionmode = VISIONMODE_SLAYERROCKETSTATIC;
					}
				}
			}
		}
	} else if (weapon->weaponnum == WEAPON_ROCKET
			|| weapon->weaponnum == WEAPON_HOMINGROCKET
			|| weapon->weaponnum == WEAPON_SKROCKET) {
		// Handle rockets
		if (weapon->timer240 == 0) {
			s32 i;

			propExplode(prop, (obj->flags2 & OBJFLAG2_WEAPON_HUGEEXP) ? EXPLOSIONTYPE_HUGE17 : EXPLOSIONTYPE_ROCKET);

			obj->hidden |= OBJHFLAG_REAPABLE;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				if (g_Vars.players[i]->slayerrocket == (struct weaponobj *)obj) {
					g_Vars.players[i]->slayerrocket = NULL;
					g_Vars.players[i]->visionmode = VISIONMODE_SLAYERROCKETSTATIC;
				}
			}
		}
	} else if (weapon->weaponnum == WEAPON_TIMEDMINE && weapon->timer240 >= 0) {
		// Handle timed mines
		if (weapon->gunfunc == FUNC_PRIMARY) {
			weapon->timer240 -= g_Vars.lvupdate240;

			if (weapon->timer240 < 0) {
				if (propExplode(prop, (obj->flags2 & OBJFLAG2_WEAPON_HUGEEXP) ? EXPLOSIONTYPE_HUGE17 : EXPLOSIONTYPE_ROCKET)) {
					weapon->timer240 = -1;
					obj->hidden |= OBJHFLAG_REAPABLE;
				}
			}
		} else {
			// empty
		}
	} else if (weapon->weaponnum == WEAPON_REMOTEMINE) {
		// Handle remote mines
		if (g_PlayersDetonatingMines != 0) {
			s32 ownerplayernum = (obj->hidden & 0xf0000000) >> 28;
			struct chrdata *parentchr = prop->parent ? prop->parent->chr : NULL;

			// If a player manages to throw a mine on themselves, it will not detonate.
			// You can't throw a mine on yourself anyway, so this check always passes
			if (prop->parent == NULL || parentchr == NULL || mpPlayerGetIndex(parentchr) != ownerplayernum) {
				if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
					if (ownerplayernum == 2) {
						u32 mask = 0;

						if (g_Vars.coop && g_Vars.coop->prop) {
							mask |= 1 << playermgrGetPlayerNumByProp(g_Vars.coop->prop);
						}

						if (g_Vars.bond && g_Vars.bond->prop) {
							mask |= 1 << playermgrGetPlayerNumByProp(g_Vars.bond->prop);
						}

						g_PlayersDetonatingMines &= mask;

						if (g_PlayersDetonatingMines != 0) {
							weapon->timer240 = 0;
						}
					} else if (g_PlayersDetonatingMines & 1 << ownerplayernum) {
						weapon->timer240 = 0;
					}
				} else if (g_PlayersDetonatingMines & 1 << ownerplayernum) {
					weapon->timer240 = 0;
				}
			}
		}

		if (weapon->timer240 >= 2) {
			// I don't think this is reachable? Remote mines don't use a timer.
			weapon->timer240 -= g_Vars.lvupdate240;

			if (weapon->timer240 < 2) {
				weapon->timer240 = 1;
			}
		} else if (weapon->timer240 == 0) {
			// Mine was damaged or timer was set to 0 above
			s32 exptype = EXPLOSIONTYPE_ROCKET;

			if (obj->flags2 & OBJFLAG2_WEAPON_HUGEEXP) {
				exptype = EXPLOSIONTYPE_HUGE17;
			}

			if (propExplode(prop, exptype)) {
				weapon->timer240 = -1;
				obj->hidden |= OBJHFLAG_REAPABLE;
			}
		}
	} else if (weapon->weaponnum == WEAPON_PROXIMITYMINE
			|| (weapon->weaponnum == WEAPON_DRAGON && weapon->gunfunc == FUNC_SECONDARY)
			|| (weapon->weaponnum == WEAPON_GRENADE && weapon->gunfunc == FUNC_SECONDARY)
			|| (weapon->weaponnum == WEAPON_NBOMB && weapon->gunfunc == FUNC_SECONDARY)) {
		// Handle proximity items
		if (weapon->timer240 >= 2) {
			// The timer is still active, so the proxy isn't active yet
			weapon->timer240 -= g_Vars.lvupdate240;

			if (weapon->timer240 < 2) {
				weapon->timer240 = 1;
				weaponRegisterProxy(weapon);
			}
		} else if (weapon->timer240 == 1) {
			// Proxy is active
			struct coord *playerpos = &g_Vars.currentplayer->prop->pos;
			f32 xdist = playerpos->f[0] - prop->pos.f[0];
			f32 ydist = playerpos->f[1] - prop->pos.f[1];
			f32 zdist = playerpos->f[2] - prop->pos.f[2];

			if (xdist * xdist + ydist * ydist + zdist * zdist < 250 * 250) {
				weapon->timer240 = 0;
			}
		}

		if (weapon->timer240 == 0) {
			// Proxy was triggered or shot
			if (weapon->weaponnum == WEAPON_NBOMB) {
				s32 i;
				struct prop *ownerprop = NULL;
				s32 ownerplayernum = (obj->hidden & 0xf0000000) >> 28;

				if (g_Vars.normmplayerisrunning) {
					struct chrdata *chr = mpGetChrFromPlayerIndex(ownerplayernum);

					if (chr) {
						ownerprop = chr->prop;
					}
				}

				nbombCreateStorm(&prop->pos, ownerprop);
				propUnsetDangerous(prop);

				obj->hidden |= OBJHFLAG_REAPABLE;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					if (g_Vars.players[i]->slayerrocket == (struct weaponobj *) obj) {
						g_Vars.players[i]->slayerrocket = NULL;
						g_Vars.players[i]->visionmode = VISIONMODE_SLAYERROCKETSTATIC;
					}
				}
			} else {
				// Regular explosive
				s32 exptype;

				if (obj->flags2 & OBJFLAG2_WEAPON_HUGEEXP) {
					exptype = EXPLOSIONTYPE_HUGE17;
				} else {
					exptype = EXPLOSIONTYPE_ROCKET;
				}

				if (weapon->weaponnum == WEAPON_DRAGON) {
					exptype = EXPLOSIONTYPE_DRAGONBOMBSPY;
				}

				if (propExplode(prop, exptype)) {
					weapon->timer240 = -1;
					obj->hidden |= OBJHFLAG_REAPABLE;
				}
			}
		}
	} else if (weapon->weaponnum == WEAPON_BOLT) {
		// Handle crossbow bolts
		// Note that the timer240 value doesn't act like a timer at all
		if (weapon->timer240 >= 2) {
			// Bolt is travelling
			s32 i;
			struct modelrodata_bbox *bbox = modelFindBboxRodata(obj->model);
			s32 ival = weapon->timer240 - 1;
			f32 radians = 0.026179939508438f * (ival / 12.0f);
			Mtxf spf8;
			Mtxf spb8;
			Mtxf sp78;
			struct coord sp6c;
			struct coord sp60;

			if (ival < 12) {
				radians += 0.026179939508438f * ((ival + 1) / 12.0f);
			}

			if ((ival & 1) == 1) {
				radians = -radians;
			}

			mtx4LoadYRotation(radians, &spb8);

			if (obj->embedment) {
				if (prop->parent && prop->parent->type != PROPTYPE_CHR) {
					mtx4Copy(&obj->embedment->matrix, &spf8);

					spf8.m[3][0] = spf8.m[3][1] = spf8.m[3][2] = 0.0f;
					spf8.m[0][3] = spf8.m[1][3] = spf8.m[2][3] = 0.0f;

					sp6c.f[0] = sp60.f[0] = sp6c.f[1] = sp60.f[1] = 0.0f;
					sp6c.f[2] = sp60.f[2] = objGetLocalZMax(bbox);

					mtx4MultMtx4(&spf8, &spb8, &sp78);
					mtx4RotateVecInPlace(&spf8, &sp6c);
					mtx4RotateVecInPlace(&sp78, &sp60);

					sp78.m[3][0] = obj->embedment->matrix.m[3][0] - (sp60.f[0] - sp6c.f[0]);
					sp78.m[3][1] = obj->embedment->matrix.m[3][1] - (sp60.f[1] - sp6c.f[1]);
					sp78.m[3][2] = obj->embedment->matrix.m[3][2] - (sp60.f[2] - sp6c.f[2]);

					mtx4Copy(&sp78, &obj->embedment->matrix);
				}
			} else {
				sp6c.f[0] = sp60.f[0] = sp6c.f[1] = sp60.f[1] = 0.0f;
				sp6c.f[2] = sp60.f[2] = objGetLocalZMax(bbox);

				mtx3ToMtx4(obj->realrot, &spf8);
				mtx4MultMtx4(&spf8, &spb8, &sp78);
				mtx4ToMtx3(&sp78, obj->realrot);

				mtx4RotateVecInPlace(&spf8, &sp6c);
				mtx4RotateVecInPlace(&sp78, &sp60);

				prop->pos.f[0] -= sp60.f[0] - sp6c.f[0];
				prop->pos.f[1] -= sp60.f[1] - sp6c.f[1];
				prop->pos.f[2] -= sp60.f[2] - sp6c.f[2];

				func0f069c70(obj, false, true);
			}

			weapon->timer240--;
		}

		if (weapon->timer240 < 0) {
			struct projectile *projectile = obj->projectile;
			s32 beamnum = boltbeamFindByProp(prop);

			if (beamnum != -1) {
				boltbeamSetTailPos(beamnum, &prop->pos);

				boltbeamIncrementHeadPos(beamnum, 3000, 0);

				if (projectile && projectile->bouncecount > 0) {
					projectile = NULL;
				}

				if (projectile == NULL) {
					weapon->timer240 = 0;
					boltbeamSetAutomatic(beamnum, 1400);
				}
			}
		} else {
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				if (g_Vars.players[i]->slayerrocket == (struct weaponobj *)obj) {
					g_Vars.players[i]->slayerrocket = NULL;
					g_Vars.players[i]->visionmode = VISIONMODE_SLAYERROCKETSTATIC;
				}
			}
		}

		if (1);
	}

	// Hard freeing is the practice of freeing a prop while it's on screen.
	// Hard frees are triggered when there are over 20 props on screen with the
	// flag CANHARDFREE. This flag is given to dropped weapons in multiplayer.
	// When this occurs, the props past the first 20 are given the flag
	// HARDFREEING. They then fade out over 1 second, at which point they are
	// given the REAPABLE flag and soon freed.
	if (obj->flags3 & OBJFLAG3_HARDFREEING) {
		weapon->fadeouttimer60 -= g_Vars.lvupdate60;

		if (weapon->fadeouttimer60 <= 0) {
			weapon->fadeouttimer60 = 0;
			obj->hidden |= OBJHFLAG_REAPABLE;
		}
	}

	if ((obj->flags3 & OBJFLAG3_CANHARDFREE) && (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)) {
		g_Vars.hardfreeabletally++;

		if (g_Vars.hardfreeabletally > 20) {
			weapon->fadeouttimer60 = TICKS(60);
			obj->flags3 &= ~OBJFLAG3_CANHARDFREE;
			obj->flags3 |= OBJFLAG3_HARDFREEING;
		}
	}
}

void func0f07063c(struct prop *prop, bool arg1)
{
	struct defaultobj *obj = prop->obj;

	if (arg1) {
		if (obj->type == OBJTYPE_AMMOCRATE || obj->type == OBJTYPE_MULTIAMMOCRATE) {
			ammocrateTick(prop);
		} else if (obj->type == OBJTYPE_WEAPON) {
			weaponTick(prop);
		}
	}
}

void objDropRecursively(struct prop *prop, bool arg1)
{
	struct prop *child = prop->child;

	while (child) {
		struct prop *next = child->next;
		objDropRecursively(child, arg1);
		objDrop(child, arg1);
		child = next;
	}
}

void func0f0706f8(struct prop *prop, bool arg1)
{
	struct defaultobj *obj = prop->obj;
	struct prop *child;

	if (obj->hidden & OBJHFLAG_REAPABLE) {
		objFree(obj, true, obj->hidden2 & OBJH2FLAG_CANREGEN);
	} else {
		prop->flags &= ~PROPFLAG_ONTHISSCREENTHISTICK;
		func0f07063c(prop, arg1);

		// Recurse into children
		child = prop->child;

		while (child) {
			struct prop *next = child->next;
			func0f0706f8(child, arg1);
			child = next;
		}
	}
}

static void func0f07079c(struct prop *prop, bool fulltick)
{
	struct defaultobj *obj = prop->obj;
	struct model *model = obj->model;
	struct prop *child;
	struct prop *next;

	if (obj->hidden & OBJHFLAG_REAPABLE) {
		objFree(obj, true, obj->hidden2 & OBJH2FLAG_CANREGEN);
		return;
	}

	if (model->attachedtonode && (obj->hidden & OBJHFLAG_EMBEDDED)) {
		Mtxf *mtx = model0001a5cc(model->attachedtomodel, model->attachedtonode, 0);
		struct modelrenderdata renderdata = {NULL, true, 3};
		u32 stack;
		Mtxf sp30;

		prop->flags |= PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK;
		mtx00015be4(mtx, &obj->embedment->matrix, &sp30);

		renderdata.unk10 = gfxAllocate(model->filedata->nummatrices * sizeof(Mtxf));
		renderdata.unk00 = &sp30;

		model0001ce64(&renderdata, model);
		func0f07063c(prop, fulltick);

		child = prop->child;

		while (child) {
			next = child->next;
			func0f07079c(child, fulltick);
			child = next;
		}
	} else {
		prop->flags &= ~PROPFLAG_ONTHISSCREENTHISTICK;

		func0f07063c(prop, fulltick);

		child = prop->child;

		while (child) {
			next = child->next;
			func0f0706f8(child, fulltick);
			child = next;
		}
	}
}

static s32 glassCalculateOpacity(struct coord *pos, f32 xludist, f32 opadist, f32 arg3)
{
	struct coord *campos = &g_Vars.currentplayer->cam_pos;
	s32 opacity;
	f32 xdiff = pos->x - campos->x;
	f32 ydiff = pos->y - campos->y;
	f32 zdiff = pos->z - campos->z;

	f32 distance = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

	if (distance > opadist) {
		opacity = 255;
	} else if (distance < xludist) {
		opacity = arg3 * 255;
	} else {
		opacity = (((distance - xludist) * (1.0f - arg3)) / (opadist - xludist) + arg3) * 255;
	}

	return opacity;
}

struct prop *g_Lifts[MAX_LIFTS];
s32 g_NumLifts;
u8 g_LiftnumToIndex[MAX_LIFTS];

struct hovtype g_HovTypes[] = {
#if PAL
	/* HOVTYPE_BED   */ { 90,  1, 2, 0.0012, 1.200000000, 0.0062821852043271, 0.0062821852043271, 0.000012564370990731, 0.00037693112972192, 0.0062821852043271, 0.0062821852043271, 0.000012564370990731, 0.00037693112972192 },
	/* HOVTYPE_BIKE  */ { 80,  1, 3, 0.0030, 0.120000004, 0.0125643704086540, 0.0188465546816590, 0.000025128741981462, 0.00075386225944385, 0.0125643704086540, 0.0188465546816590, 0.000025128741981462, 0.00075386225944385 },
	/* HOVTYPE_CRATE */ { 70,  2, 4, 0.0012, 1.200000000, 0.0062821852043271, 0.0125643704086540, 0.000012564370990731, 0.00037693112972192, 0.0062821852043271, 0.0125643704086540, 0.000012564370990731, 0.00037693112972192 },
	/* HOVTYPE_3     */ { 170, 2, 2, 0.0012, 1.200000000, 0.0031410926021636, 0.0031410926021636, 0.000006282185495365, 0.00022615866328124, 0.0031410926021636, 0.0031410926021636, 0.000006282185495365, 0.00022615866328124 },
	/* HOVTYPE_4     */ { 170, 2, 2, 0.0012, 1.200000000, 0.0031410926021636, 0.0031410926021636, 0.000006282185495365, 0.00022615866328124, 0.0031410926021636, 0.0031410926021636, 0.000006282185495365, 0.00022615866328124 },
#else
	/* HOVTYPE_BED   */ { 90,  1, 2, 0.0010, 1.000000000, 0.0062821852043271, 0.0062821852043271, 0.000010470308552613, 0.00031410926021636, 0.0062821852043271, 0.0062821852043271, 0.000010470308552613, 0.00031410926021636 },
	/* HOVTYPE_BIKE  */ { 80,  1, 3, 0.0025, 0.100000000, 0.0125643704086540, 0.0188465546816590, 0.000020940617105225, 0.00062821852043271, 0.0125643704086540, 0.0188465546816590, 0.000020940617105225, 0.00062821852043271 },
	/* HOVTYPE_CRATE */ { 70,  2, 4, 0.0010, 1.000000000, 0.0062821852043271, 0.0125643704086540, 0.000010470308552613, 0.00031410926021636, 0.0062821852043271, 0.0125643704086540, 0.000010470308552613, 0.00031410926021636 },
	/* HOVTYPE_3     */ { 170, 2, 2, 0.0010, 1.000000000, 0.0031410926021636, 0.0031410926021636, 0.000005235154276306, 0.00018846555030905, 0.0031410926021636, 0.0031410926021636, 0.000005235154276306, 0.00018846555030905 },
	/* HOVTYPE_4     */ { 170, 2, 2, 0.0010, 1.000000000, 0.0031410926021636, 0.0031410926021636, 0.000005235154276306, 0.00018846555030905, 0.0031410926021636, 0.0031410926021636, 0.000005235154276306, 0.00018846555030905 },
#endif
};

static void func0f070a1c(struct modelrodata_bbox *bbox, f32 rot[3][3], struct coord *pos, struct coord *vertices)
{
	f32 sp54 = rot[0][0] * bbox->xmin;
	f32 sp50 = rot[0][1] * bbox->xmin;
	f32 sp4c = rot[0][2] * bbox->xmin;

	f32 sp48 = rot[2][0] * bbox->zmin;
	f32 sp44 = rot[2][1] * bbox->zmin;
	f32 sp40 = rot[2][2] * bbox->zmin;

	f32 sp3c = rot[0][0] * bbox->xmax;
	f32 sp38 = rot[0][1] * bbox->xmax;
	f32 sp34 = rot[0][2] * bbox->xmax;

	f32 sp30 = rot[2][0] * bbox->zmax;
	f32 sp2c = rot[2][1] * bbox->zmax;
	f32 sp28 = rot[2][2] * bbox->zmax;

	f32 sp24 = rot[1][0] * bbox->ymin + pos->f[0];
	f32 sp20 = rot[1][1] * bbox->ymin + pos->f[1];
	f32 sp1c = rot[1][2] * bbox->ymin + pos->f[2];

	vertices[0].x = sp54 + sp24 + sp48;
	vertices[0].y = sp50 + sp20 + sp44;
	vertices[0].z = sp4c + sp1c + sp40;

	vertices[1].x = sp54 + sp24 + sp30;
	vertices[1].y = sp50 + sp20 + sp2c;
	vertices[1].z = sp4c + sp1c + sp28;

	vertices[2].x = sp3c + sp24 + sp30;
	vertices[2].y = sp38 + sp20 + sp2c;
	vertices[2].z = sp34 + sp1c + sp28;

	vertices[3].x = sp3c + sp24 + sp48;
	vertices[3].y = sp38 + sp20 + sp44;
	vertices[3].z = sp34 + sp1c + sp40;
}

static void func0f070bd0(struct modelrodata_type19 *rodata, f32 rot[3][3], struct coord *pos, struct coord *vertices)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		vertices[i].x = pos->x + rot[0][0] * rodata->vertices[i].x + rot[1][0] * rodata->vertices[i].y + rot[2][0] * rodata->vertices[i].z;
		vertices[i].y = pos->y + rot[0][1] * rodata->vertices[i].x + rot[1][1] * rodata->vertices[i].y + rot[2][1] * rodata->vertices[i].z;
		vertices[i].z = pos->z + rot[0][2] * rodata->vertices[i].x + rot[1][2] * rodata->vertices[i].y + rot[2][2] * rodata->vertices[i].z;
	}
}

static void func0f070ca0(struct defaultobj *obj, struct geotilef *tile, u32 flags, struct modelrodata_bbox *bbox, struct modelrodata_type19 *rodata)
{
	struct coord vertices[4];
	s32 i;
	s32 j;

	if (bbox != NULL) {
		func0f070a1c(bbox, obj->realrot, &obj->prop->pos, vertices);
	} else if (rodata != NULL) {
		func0f070bd0(rodata, obj->realrot, &obj->prop->pos, vertices);
	}

	tile->header.type = GEOTYPE_TILE_F;
	tile->header.flags = flags;
	tile->header.numvertices = 4;

	for (i = 0; i < 4; i++) {
		tile->vertices[i] = vertices[i];
	}

	tile->floorcol = 0xfff;

	tile->floortype = FLOORTYPE_DEFAULT;

	for (i = 0; i < 3; i++) {
		tile->min[i] = 0;
		tile->max[i] = 0;

		for (j = 1; j < tile->header.numvertices; j++) {
			if (tile->vertices[j].f[i] < tile->vertices[tile->min[i]].f[i]) {
				tile->min[i] = j;
			}

			if (tile->vertices[j].f[i] > tile->vertices[tile->max[i]].f[i]) {
				tile->max[i] = j;
			}
		}
	}
}

void liftActivate(struct prop *prop, u8 liftnum)
{
	g_Lifts[g_NumLifts] = prop;
	g_LiftnumToIndex[liftnum] = g_NumLifts;
	g_NumLifts++;
}

struct prop *liftFindByPad(s16 padnum)
{
	if (g_Pads[padnum].liftnum <= 0 || g_Pads[padnum].liftnum > MAX_LIFTS) {
		return NULL;
	}

	return g_Lifts[g_LiftnumToIndex[g_Pads[padnum].liftnum]];
}

f32 liftGetY(struct liftobj *lift)
{
	f32 y = lift->base.prop->pos.y;

	if (lift->base.geocount > 0) {
		struct geotilef *tile = lift->base.geotilef;

		if (tile && tile->header.type == GEOTYPE_TILE_F) {
			if (tile->header.flags & GEOFLAG_FLOOR1) {
				y = tile->vertices[tile->max[1]].y;
			}
		}
	}

	return y;
}

/**
 * Recalculate a lift's tile/geometry information.
 *
 * The lift models and the part numbers in each model are:
 *
 * a51_lift_control       0
 * a51_lift_hangar        0
 * a51_lift_store         0
 * a51_lift_thinwall      0
 * a51dish                0
 * airbase_lift_angle     0 1 2
 * airbase_lift_enclosed  0 1 2
 * al_docklift                      5 6
 * baggagecarrier         0
 * chamber                0
 * ci_lift                0
 * dd_liftr               0 1 2 3 4
 * lift_platform          0 1
 * matrix_lift            0 1 2
 * ravinelift             0
 * sk_lift                0
 * skedarbridge           0
 *
 * Part 0 is the floor if rectangular
 * Parts 1-3 are walls (some lifts rely on BG geometry instead)
 * Part 4 is a door blocker (used by dataDyne tower lifts)
 * Part 5 is the first half of the floor if non-rectangular (Deep Sea lift)
 * Part 6 is the second half of the floor if non-rectangular (Deep Sea lift)
 */
void liftUpdateTiles(struct liftobj *lift, bool stationary)
{
	u8 *geo;
	union modelrodata *rodata;
	struct modelrodata_bbox *bbox;
	s32 geocount;
	u32 flags;
	s32 i;

	lift->base.geocount = 0;
	i = 0;

	do {
		geo = (u8 *)lift->base.unkgeo + lift->base.geocount * 0x40;
		bbox = NULL;
		rodata = NULL;

		do {
			if (i == 0) {
				flags = GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2 | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT | GEOFLAG_LIFTFLOOR;

				// Look for a non-rectangular floor with fallback to rectangular
				rodata = modelGetPartRodata(lift->base.model->filedata, MODELPART_LIFT_FLOORNONRECT1);

				if (rodata == NULL) {
					union modelrodata *tmp;
					tmp = modelGetPartRodata(lift->base.model->filedata, MODELPART_LIFT_FLOORRECT);
					bbox = &tmp->bbox;

					if (bbox == NULL) {
						bbox = objFindBboxRodata(&lift->base);
					}
				}
			} else if (i == 1) {
				flags = GEOFLAG_WALL;
				rodata = modelGetPartRodata(lift->base.model->filedata, MODELPART_LIFT_WALL1);
			} else if (i == 2) {
				flags = GEOFLAG_WALL;
				rodata = modelGetPartRodata(lift->base.model->filedata, MODELPART_LIFT_WALL2);
			} else if (i == 3) {
				flags = GEOFLAG_WALL;
				rodata = modelGetPartRodata(lift->base.model->filedata, MODELPART_LIFT_WALL3);
			} else if (i == 4) {
				// The doorblock model part exists in the dataDyne tower lifts.
				// It's a tile across the door that only applies while the lift
				// is moving. Without it, the player could exit the lift through
				// the doorway while it's moving.
				if (!stationary) {
					flags = GEOFLAG_WALL;
					rodata = modelGetPartRodata(lift->base.model->filedata, MODELPART_LIFT_DOORBLOCK);
				}
			} else if (i == 5) {
				flags = GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2 | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT | GEOFLAG_LIFTFLOOR;
				rodata = modelGetPartRodata(lift->base.model->filedata, MODELPART_LIFT_FLOORNONRECT2);
			} else {
				break;
			}

			i++;
		} while (!bbox && !rodata);

		if (bbox || rodata) {
			func0f070ca0(&lift->base, (struct geotilef *)geo, flags, bbox, &rodata->type19);
			lift->base.geocount++;
		}
	} while (bbox || rodata);
}

static void liftGoToStop(struct liftobj *lift, s32 stopnum)
{
	struct pad *curpad;
	struct pad *aimpad;
	struct pad *reqpad;

	if (lift->pads[stopnum] >= 0 && lift->levelaim != stopnum) {
		// If lift is stopped (cur == aim)
		// or door is not fully closed yet
		if (lift->levelcur == lift->levelaim ||
				(lift->doors[lift->levelcur] && !doorIsClosed(lift->doors[lift->levelcur]))) {
			// Sanity check to make sure lift is actually not moving
			if (lift->dist == 0 && lift->speed == 0) {
				lift->levelaim = stopnum;
				return;
			}
		}

		curpad = &g_Pads[lift->pads[lift->levelcur]];
		aimpad = &g_Pads[lift->pads[lift->levelaim]];
		reqpad = &g_Pads[lift->pads[stopnum]];

		// Figure out if the lift needs to reverse direction on any axis
		if (stopnum != lift->levelcur &&
				((aimpad->pos.x >= curpad->pos.x && reqpad->pos.x >= curpad->pos.x) ||
				 (curpad->pos.x >= aimpad->pos.x && curpad->pos.x >= reqpad->pos.x)) &&
				((aimpad->pos.y >= curpad->pos.y && reqpad->pos.y >= curpad->pos.y) ||
				 (curpad->pos.y >= aimpad->pos.y && curpad->pos.y >= reqpad->pos.y)) &&
				((aimpad->pos.z >= curpad->pos.z && reqpad->pos.z >= curpad->pos.z) ||
				 (curpad->pos.z >= aimpad->pos.z && curpad->pos.z >= reqpad->pos.z))) {
			// Same direction
			lift->levelaim = stopnum;
		} else {
			// Reverse direction
			f32 xdiff = aimpad->pos.x - curpad->pos.x;
			f32 ydiff = aimpad->pos.y - curpad->pos.y;
			f32 zdiff = aimpad->pos.z - curpad->pos.z;
			f32 result = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

			lift->levelcur = lift->levelaim;
			lift->dist = result - lift->dist;
			lift->speed = -lift->speed;
			lift->levelaim = stopnum;
		}
	}
}

f32 objGetHov04(struct defaultobj *obj)
{
	struct hov *hov = NULL;
	f32 result;

	if (obj->type == OBJTYPE_HOVERPROP) {
		struct hoverpropobj *tmp = (struct hoverpropobj *) obj;
		hov = &tmp->hov;
	} else if (obj->type == OBJTYPE_HOVERBIKE) {
		struct hoverbikeobj *tmp = (struct hoverbikeobj *) obj;
		hov = &tmp->hov;
	}

	if (hov) {
		result = hov->unk04;
	} else {
		struct modelrodata_bbox *bbox = objFindBboxRodata(obj);
		f32 value = objGetRotatedLocalYMinByMtx3(bbox, obj->realrot);
		result = func0f06a620(obj) - value;
	}

	return result;
}

void hovUpdateGround(struct defaultobj *obj, struct hov *hov, struct coord *pos, s16 *rooms, f32 matrix[3][3])
{
	f32 ground;
	s16 testrooms[8];
	struct coord testpos;

	if (g_Vars.lvframe60 > hov->nexttick60) {
		testpos.x = pos->x;
		testpos.y = pos->y - 50;
		testpos.z = pos->z;

		roomsCopy(rooms, testrooms);
		setup0f09233c(obj, &testpos, matrix, testrooms);

		ground = cdFindGroundAtCyl(pos, 5, testrooms, &obj->floorcol, NULL);

		if (ground < -30000) {
			ground = hov->ground;
		}

		hov->ground = ground;
		hov->prevtick60 = g_Vars.lvframe60;
	}
}

void hovTick(struct defaultobj *obj, struct hov *hov)
{
	struct prop *prop;
	f32 sp1d0;
	f32 sp1cc;
	f32 ground1;
	f32 ground2;
	struct modelrodata_bbox *bbox;
	struct coord sp1b4;
	struct coord sp1a8;
	s16 sp198[8];
	s16 sp188[8];
	Mtxf sp148;
	Mtxf sp108;
	Mtxf spc8;
	s32 i;
	struct hovtype *type;
	f32 spbc;
	f32 spb8;
	f32 spb4;
	f32 xrot;
	f32 spac;
	s16 sp9c[8];
	struct coord sp90;
	bool sp8c;
	f32 radius;
	f32 ymax;
	f32 ymin;

	if (g_Vars.lvframe60 > hov->nexttick60) {
		prop = obj->prop;
		bbox = objFindBboxRodata(obj);
		type = &g_HovTypes[hov->type];
		sp8c = false;

		if (hov->prevtick60 < g_Vars.lvframe60) {
			hovUpdateGround(obj, hov, &prop->pos, prop->rooms, obj->realrot);
		}

		hov->nexttick60 = g_Vars.lvframe60;

		if (obj->flags & OBJFLAG_DEACTIVATED) {
			spb4 = 0.0f;
		} else {
			if (obj->flags3 & OBJFLAG3_GEOCYL) {
				objGetBbox(prop, &radius, &ymax, &ymin);
				sp1cc = radius * 0.9f;
				sp1d0 = -sp1cc;
			} else {
				sp1d0 = bbox->zmin * 0.9f * obj->model->scale;
				sp1cc = bbox->zmax * 0.9f * obj->model->scale;
			}

			spbc = cosf(hov->unk10);
			spb8 = sinf(hov->unk10);

			sp1b4.x = prop->pos.x + sp1d0 * spb8;
			sp1b4.y = prop->pos.y;
			sp1b4.z = prop->pos.z + sp1d0 * spbc;

			sp1a8.x = prop->pos.x + sp1cc * spb8;
			sp1a8.y = prop->pos.y;
			sp1a8.z = prop->pos.z + sp1cc * spbc;

			sp90.x = prop->pos.x;
			sp90.y = prop->pos.y - 50.0f;
			sp90.z = prop->pos.z;

			roomsCopy(prop->rooms, sp9c);

			setup0f09233c(obj, &sp90, obj->realrot, sp9c);

			func0f065e74(&prop->pos, prop->rooms, &sp1b4, sp198);
			roomsAppend(sp9c, sp198, ARRAYCOUNT(sp198));
			ground1 = cdFindGroundAtCyl(&sp1b4, 5, sp198, &obj->floorcol, NULL);

			func0f065e74(&prop->pos, prop->rooms, &sp1a8, sp188);
			roomsAppend(sp9c, sp188, ARRAYCOUNT(sp188));
			ground2 = cdFindGroundAtCyl(&sp1a8, 5, sp188, NULL, NULL);

			if (ground1 >= -30000.0f && ground2 >= -30000.0f) {
				spb4 = atan2f(ground1 - ground2, sp1cc - sp1d0);

				if (spb4 >= M_PI) {
					spb4 -= M_BADTAU;
				}
			} else if (ground1 >= -30000.0f) {
				spb4 = atan2f(ground1 - hov->ground, -sp1d0);

				if (spb4 >= M_PI) {
					spb4 -= M_BADTAU;
				}
			} else if (ground2 >= -30000.0f) {
				spb4 = atan2f(hov->ground - ground2, sp1cc);

				if (spb4 >= M_PI) {
					spb4 -= M_BADTAU;
				}
			} else {
				spb4 = 0.0f;
			}
		}

		spac = hov->ground;

		if (obj->hidden & OBJHFLAG_GRABBED) {
			if (spac < g_Vars.currentplayer->vv_ground - 70.0f) {
				spac = g_Vars.currentplayer->vv_ground;
			}
		}

		if (hov->flags & 1) {
			sp8c = true;
			hov->unk04 = hov->unk08 = type->unk00;
			hov->unk30 = spac;
			hov->flags &= ~1;

			if (obj->type == OBJTYPE_HOVERBIKE) {
				propsnd0f0939f8(NULL, obj->prop, SFX_BIKE_PULSE, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
			}
		}

		applySpeed(&hov->unk04, hov->unk08, &hov->unk0c, type->unk0c, type->unk0c, type->unk10);

		if (hov->unk08 >= type->unk00 && hov->unk08 <= hov->unk04) {
			hov->unk0c = 0.0f;
			hov->unk08 = type->unk00 - type->unk04 - RANDOMFRAC() * type->unk08;
		} else if (hov->unk08 < type->unk00 && hov->unk08 >= hov->unk04) {
			hov->unk0c = 0.0f;
			hov->unk08 = type->unk00 + type->unk04 + RANDOMFRAC() * type->unk08;
		}

		applyRotation(&hov->unk14, hov->unk18, &hov->unk1c, type->unk1c, type->unk1c, type->unk20);

		if (hov->unk14 == hov->unk18) {
			if (hov->unk1c <= 2.0f * type->unk1c && hov->unk1c >= 2.0f * -type->unk1c) {
				hov->unk1c = 0.0f;

				if (hov->unk18 < M_PI) {
					hov->unk18 = M_BADTAU - type->unk14 - RANDOMFRAC() * type->unk18;
				} else {
					hov->unk18 = type->unk14 + RANDOMFRAC() * type->unk18;
				}
			}
		}

		applyRotation(&hov->unk20, hov->unk24, &hov->unk28, type->unk2c, type->unk2c, type->unk30);

		if (hov->unk20 == hov->unk24) {
			if (hov->unk28 <= 2.0f * type->unk2c && hov->unk28 >= 2.0f * -type->unk2c) {
				hov->unk28 = 0.0f;

				if (hov->unk24 < M_PI) {
					hov->unk24 = M_BADTAU - type->unk24 - RANDOMFRAC() * type->unk28;
				} else {
					hov->unk24 = type->unk24 + RANDOMFRAC() * type->unk28;
				}
			}
		}

		for (i = 0; i < g_Vars.lvupdate60; i++) {
			f32 f0;
			f32 f12;
			f32 f2;

			hov->unk2c += (spb4 - hov->unk2c) * (PAL ? 0.0893f : 0.075f);

			f0 = spac - hov->unk30;
			f12 = (PAL ? 0.102000005f : 0.085f);

			if (hov->unk30 < hov->ground) {
				if (f0 >= 0.0f) {
					f2 = f0;
				} else {
					f2 = -f0;
				}

				if (f2 > 10.0f) {
					f12 *= 1.0f + (f2 - 10.0f) * 0.2f;
				}

				if (f12 > PALUPF(0.5f)) {
					f12 = PALUPF(0.5f);
				}

				f0 *= f12;
			} else {
				f0 *= f12;

				if (obj->hidden & OBJHFLAG_MOUNTED) {
					if (f0 > 10.0f) {
						f0 = 10.0f;
					} else if (f0 < -10.0f) {
						f0 = -10.0f;
					}
				} else {
					if (f0 > 5.0f) {
						f0 = 5.0f;
					} else if (f0 < -5.0f) {
						f0 = -5.0f;
					}
				}
			}

			hov->unk30 += f0;

			if (f0 > 1.0f || f0 < -1.0f) {
				sp8c = true;
			}
		}

		if (sp8c) {
			func0f069c70(obj, true, true);
		}

		if (hov->unk30 < hov->ground - 5.0f || hov->unk30 > hov->ground + 5.0f) {
			obj->flags |= OBJFLAG_80000000;
		} else {
			obj->flags &= ~OBJFLAG_80000000;
		}

		prop->pos.y = objGetHov04(obj) + hov->unk30;

		mtx4LoadZRotation(hov->unk20, &sp148);

		xrot = hov->unk2c + hov->unk14;

		if (xrot >= M_BADTAU) {
			xrot -= M_BADTAU;
		} else if (xrot < 0.0f) {
			xrot += M_BADTAU;
		}

		mtx4LoadXRotation(xrot, &sp108);
		mtx00015be0(&sp108, &sp148);
		mtx4LoadYRotation(hov->unk10, &sp108);
		mtx00015be0(&sp108, &sp148);
		mtx00015f04(obj->model->scale, &sp148);

		if (obj->type == OBJTYPE_HOVERBIKE) {
			struct hoverbikeobj *bike = (struct hoverbikeobj *) obj;
			f32 ezreal = bike->ezreal + bike->ezreal2;

			if (bike->exreal != 0.0f) {
				mtx4LoadXRotation(bike->exreal, &sp108);
				mtx00015be4(&sp148, &sp108, &spc8);
				mtx4Copy(&spc8, &sp148);
			}

			if (ezreal != 0.0f) {
				mtx4LoadZRotation(ezreal, &sp108);
				mtx00015be4(&sp148, &sp108, &spc8);
				mtx4Copy(&spc8, &sp148);
			}
		}

		mtx4ToMtx3(&sp148, obj->realrot);
	}
}

f32 hoverpropGetTurnAngle(struct defaultobj *obj)
{
	f32 angle = 0;

	if (obj->type == OBJTYPE_HOVERPROP) {
		struct hoverpropobj *hoverprop = (struct hoverpropobj *)obj;
		angle = hoverprop->hov.unk10;
	} else if (obj->type == OBJTYPE_HOVERBIKE) {
		struct hoverbikeobj *hoverbike = (struct hoverbikeobj *)obj;
		angle = hoverbike->hov.unk10;
	}

	return angle;
}

void hoverpropSetTurnAngle(struct defaultobj *obj, f32 angle)
{
	if (obj->type == OBJTYPE_HOVERPROP) {
		struct hoverpropobj *hoverprop = (struct hoverpropobj *)obj;
		hoverprop->hov.unk10 = angle;
	} else if (obj->type == OBJTYPE_HOVERBIKE) {
		struct hoverbikeobj *hoverbike = (struct hoverbikeobj *)obj;
		hoverbike->hov.unk10 = angle;
	}
}

s32 func0f072144(struct defaultobj *obj, struct coord *arg1, f32 arg2, bool arg3)
{
	s32 cdresult = CDRESULT_NOCOLLISION;
	f32 sp460[3][3];
	f32 yrot;
	struct coord pos;
	s16 rooms[8];
	struct hov prevhov;
	struct hov *hov = NULL;
	union geounion geounion;
	struct prop *prop = obj->prop;
	struct hoverbikeobj *hoverbike;
	Mtxf spa4;
	Mtxf sp64;
	f32 sp40[3][3];

	if (obj->type == OBJTYPE_HOVERPROP || obj->type == OBJTYPE_HOVERBIKE) {
		if (arg2 != 0.0f) {
			yrot = arg2 + hoverpropGetTurnAngle(obj);

			if (yrot >= M_BADTAU) {
				yrot -= M_BADTAU;
			} else if (yrot < 0.0f) {
				yrot += M_BADTAU;
			}
		} else {
			yrot = hoverpropGetTurnAngle(obj);
		}

		mtx4LoadYRotation(yrot, &spa4);
		mtx00015f04(obj->model->scale, &spa4);
		mtx4ToMtx3(&spa4, sp460);
	} else {
		yrot = 0.0f;

		if (arg2 != 0.0f) {
			if (arg2 >= M_BADTAU) {
				arg2 -= M_BADTAU;
			} else if (arg2 < 0.0f) {
				arg2 += M_BADTAU;
			}

			mtx4LoadYRotation(arg2, &sp64);
			mtx4ToMtx3(&sp64, sp40);
			mtx00016140(sp40, obj->realrot, sp460);
		} else {
			mtx3Copy(obj->realrot, sp460);
		}
	}

	pos = prop->pos;

	propSetPerimEnabled(prop, false);

	if (arg1->x != 0.0f || arg1->z != 0.0f) {
		pos.x += arg1->x;
		pos.z += arg1->z;

		func0f065e74(&prop->pos, prop->rooms, &pos, rooms);
		setup0f09233c(obj, &pos, sp460, rooms);

		if (obj->type == OBJTYPE_HOVERBIKE) {
			hoverbike = (struct hoverbikeobj *) obj;
			hov = &hoverbike->hov;
		} else if (obj->type == OBJTYPE_HOVERPROP) {
			hov = &((struct hoverpropobj *) obj)->hov;
		}

		if (hov != NULL) {
			prevhov = *hov;

			hovUpdateGround(obj, hov, &pos, rooms, sp460);

			pos.y += hov->ground - prevhov.ground;
		}

		cdresult = cdExamCylMove05(&prop->pos, prop->rooms, &pos, rooms, CDTYPE_ALL, true, 0.0f, 0.0f);

		if (cdresult == CDRESULT_ERROR) {
			// empty
		} else if (cdresult == CDRESULT_COLLISION) {
			cdSetSavedPos(&prop->pos, &pos);
		}
	} else {
		roomsCopy(prop->rooms, rooms);
		setup0f09233c(obj, &pos, sp460, rooms);
	}

	if (cdresult == CDRESULT_NOCOLLISION) {
		func0f069850(obj, &pos, sp460, &geounion.cyl);

		if (obj->flags3 & OBJFLAG3_GEOCYL) {
			cdresult = cdExamCylMove01(&prop->pos, &pos, geounion.cyl.radius, rooms, CDTYPE_ALL,
					CHECKVERTICAL_YES, geounion.cyl.ymax - pos.y, geounion.cyl.ymin - pos.y);
		} else {
			cdresult = cd0002f02c(&geounion.block, rooms, CDTYPE_ALL);
		}
	}

	propSetPerimEnabled(prop, true);

	if (cdresult == CDRESULT_NOCOLLISION && arg3) {
		hoverpropSetTurnAngle(obj, yrot);
		mtx3Copy(sp460, obj->realrot);

		prop->pos.x = pos.x;
		prop->pos.z = pos.z;

		propDeregisterRooms(prop);
		roomsCopy(rooms, prop->rooms);

		if (obj->geocyl && (obj->hidden2 & OBJH2FLAG_08)) {
			if (obj->flags3 & OBJFLAG3_GEOCYL) {
				*obj->geocyl = geounion.cyl;
			} else {
				*obj->geoblock = geounion.block;
			}
		}
	} else if (hov) {
		*hov = prevhov;
	}

	return cdresult;
}

static void hovercarFindNextPath(struct hovercarobj *hovercar)
{
	s32 index = hovercar->path - g_StageSetup.paths + 1;

	while (true) {
		if (g_StageSetup.paths[index].pads == NULL) {
			index = 0;
		}

		if (&g_StageSetup.paths[index] == hovercar->path) {
			break;
		}

		if ((g_StageSetup.paths[index].flags & PATHFLAG_FLYING)
				&& (g_StageSetup.paths[index].flags & PATHFLAG_INUSE) == 0) {
			hovercar->path->flags &= ~PATHFLAG_INUSE;
			hovercar->path = &g_StageSetup.paths[index];
			hovercar->path->flags |= PATHFLAG_INUSE;
			return;
		}

		index++;
	}
}

static void hovercarStartNextPath(struct hovercarobj *hovercar)
{
	s32 *pads;
	struct pad *pad;
	Mtxf matrix;
	s16 rooms[2];

	hovercarFindNextPath(hovercar);

	pads = hovercar->path->pads;
	hovercar->nextstep = 0;

	pad = &g_Pads[pads[0]];

	mtx3ToMtx4(hovercar->base.realrot, &matrix);

	rooms[0] = pad->room;
	rooms[1] = -1;

	func0f06a730(&hovercar->base, &pad->pos, &matrix, rooms, &pad->pos);

	hovercar->base.flags |= OBJFLAG_HOVERCAR_20000000;
}

static void hovercarIncrementStep(struct hovercarobj *hovercar)
{
	hovercar->nextstep++;

	if (hovercar->path->pads[hovercar->nextstep] < 0) {
		if (hovercar->path->flags & PATHFLAG_CIRCULAR) {
			hovercar->nextstep = 0;
		} else {
			hovercarStartNextPath(hovercar);
		}
	}
}

/**
 * Check if the given obj is colliding with another obj. If so, transfer
 * velocity into the collided obj. Return a frac that should be applied to the
 * moving obj's speed.
 *
 * Assumes the caller has used the collision system already, so any obstacle is
 * already known by the collision system.
 *
 * For collisions with chrs, no transfer of intertia is done and the moving obj
 * rebounds at full speed. For collisions with pushable objects, the force is
 * applied half to both objects.
 */
static f32 objCollide(struct defaultobj *movingobj, struct coord *movingvel, f32 rotation)
{
	f32 force = 1.0f;
	struct prop *obstacle = g_CdObstacleProp;

	if (obstacle && g_Vars.lvupdate240 > 0) {
		if (obstacle->type & (PROPTYPE_CHR | PROPTYPE_PLAYER)) {
			if (1);
		} else if (obstacle->type == PROPTYPE_OBJ) {
			struct defaultobj *obstacleobj = obstacle->obj;

			if ((obstacleobj->hidden & OBJHFLAG_MOUNTED) == 0
					&& (obstacleobj->hidden & OBJHFLAG_GRABBED) == 0
					&& (obstacleobj->flags3 & OBJFLAG3_PUSHABLE)) {
				struct coord sp88;
				struct coord obstaclevel = {0, 0, 0};
				struct coord sp58;
				struct coord sp4c;

				obstaclevel.x = movingvel->x * 0.5f / g_Vars.lvupdate60freal;
				obstaclevel.y = 0.0f;
				obstaclevel.z = movingvel->z * 0.5f / g_Vars.lvupdate60freal;

				objApplyMomentum(obstacleobj, &obstaclevel, 0.0f, true, true);

				if (cdGetSavedPos(&sp58, &sp4c)) {
					sp4c.x -= sp58.x;
					sp4c.y -= sp58.y;
					sp4c.z -= sp58.z;
				} else {
					sp58 = movingobj->prop->pos;

					sp4c.x = obstacle->pos.x - movingobj->prop->pos.x;
					sp4c.y = obstacle->pos.y - movingobj->prop->pos.y;
					sp4c.z = obstacle->pos.z - movingobj->prop->pos.z;
				}

				func0f02e3dc(&g_CdEdgeVtx1, &g_CdEdgeVtx2, &sp58, &sp4c, &sp88);

				force = 0.5f;

				if (rotation != 0.0f) {
					f32 xdiff = sp88.f[0] - movingobj->prop->pos.f[0];
					f32 zdiff = sp88.f[2] - movingobj->prop->pos.f[2];
					f32 finalrotation = 0.0f;
					struct coord speed = {0, 0, 0};
					f32 mult = 1.0f / sqrtf(xdiff * xdiff + zdiff * zdiff);

					xdiff *= mult;
					zdiff *= mult;

					rotation /= g_Vars.lvupdate60freal;

					speed.f[0] += -zdiff * rotation * 10.0f;
					speed.f[2] += xdiff * rotation * 10.0f;

					finalrotation += rotation * 0.1f;

					objApplyMomentum(obstacleobj, &speed, finalrotation, true, true);
				}
			}
		}
	}

	return force;
}

void hoverbikeUpdateMovement(struct hoverbikeobj *bike, f32 speedforwards, f32 speedsideways, f32 speedtheta)
{
	f32 f12;
	f32 angle;
	f32 sinangle;
	f32 cosangle;
	f32 f2;
	f32 sp70 = 0;
	f32 sp6c = 0;
	f32 sp68 = 0;
	s32 i;
	u32 stack[6];
	f32 tmp;

	tmp = speedtheta * 0.04362628236413f;

	if (speedforwards < 0) {
		tmp *= 1.0f - speedforwards * 0.5f;
	}

	for (i = 0; i < g_Vars.lvupdate60; i++) {
		bike->w += (tmp - bike->w) * (PAL ? 0.0893f : 0.075f);
	}

	sp6c += bike->w * 12;
	angle = hoverpropGetTurnAngle(&bike->base);
	sinangle = sinf(angle);
	cosangle = cosf(angle);

	if (speedforwards >= 0) {
		f2 = (speedforwards + 0.1f) * 0.3f * g_Vars.lvupdate60freal;
	} else {
		f2 = (0.1f - speedforwards) * 0.3f * g_Vars.lvupdate60freal;
	}

	if (bike->rels[1] < speedforwards * 0.5f) {
		bike->rels[1] += f2;

		if (bike->rels[1] > speedforwards * 0.5f) {
			bike->rels[1] = speedforwards * 0.5f;
		}
	} else {
		bike->rels[1] -= f2;

		if (bike->rels[1] < speedforwards * 0.5f) {
			bike->rels[1] = speedforwards * 0.5f;
		}
	}

	bike->leandiff *= 0.93f;
	bike->leandiff += speedforwards - bike->leanspeed;
	bike->leanspeed = speedforwards;

	f2 = bike->leandiff * 5;

	if (f2 > 1.0f) {
		f2 = 1.0f;
	} else if (f2 < -1.0f) {
		f2 = -1.0f;
	}

	if (speedforwards >= 0) {
		if (f2 > 0) {
			f12 = speedforwards * 0.3f + speedforwards * 0.7f * f2;
		} else {
			f12 = speedforwards * 0.3f;
		}
	} else {
		if (f2 < 0) {
			f12 = speedforwards * 0.5f - speedforwards * 0.5f * f2;
		} else {
			f12 = speedforwards * 0.5f;
		}
	}

	sp70 += f12 * 0.04f * M_BADTAU;

	if (speedsideways >= 0) {
		f12 = (speedsideways + 0.1f) * 0.3f * g_Vars.lvupdate60freal;
	} else {
		f12 = (0.1f - speedsideways) * 0.3f * g_Vars.lvupdate60freal;
	}

	if (bike->rels[0] < 0.4f * speedsideways) {
		bike->rels[0] += f12;

		if (bike->rels[0] > speedsideways * 0.4f) {
			bike->rels[0] = speedsideways * 0.4f;
		}
	} else {
		bike->rels[0] -= f12;

		if (bike->rels[0] < speedsideways * 0.4f) {
			bike->rels[0] = speedsideways * 0.4f;
		}
	}

	sp68 += speedsideways * 0.2512874007225f;

	for (i = 0; i < g_Vars.lvupdate60; i++) {
		bike->speedabs[1] *= PAL ? 0.964f : 0.97f;
		bike->speedabs[0] *= PAL ? 0.964f : 0.97f;
		bike->speedabs[1] += bike->rels[1] * cosangle * PALUPF(1.08f);
		bike->speedabs[0] += bike->rels[1] * sinangle * PALUPF(1.08f);
		bike->speedabs[1] += bike->rels[0] * sinangle * PALUPF(0.72f);
		bike->speedabs[0] += -bike->rels[0] * cosangle * PALUPF(0.72f);
	}

	for (i = 0; i < g_Vars.lvupdate60; i++) {
		bike->exreal += (sp70 - bike->exreal) * (PAL ? 0.0478f : 0.04f);
		bike->ezreal += (sp6c - bike->ezreal) * (PAL ? 0.177f : 0.15f);
		bike->ezreal2 += (sp68 - bike->ezreal2) * (PAL ? 0.0478f : 0.04f);
	}

	if (speedforwards >= 0.99f) {
		bike->maxspeedtime240 += g_Vars.lvupdate240;

		if (bike->maxspeedtime240 > TICKS(2400)) {
			bike->maxspeedtime240 = TICKS(2400);
		}
	} else if (bike->maxspeedtime240 > 0) {
		if (speedforwards >= 0.8f) {
			// empty
		} else if (speedforwards >= -0.1f) {
			bike->maxspeedtime240 -= g_Vars.lvupdate240;

			if (bike->maxspeedtime240 < 0) {
				bike->maxspeedtime240 = 0;
			}
		} else {
			bike->maxspeedtime240 = 0;
		}
	}

	bike->speedrel[1] = bike->maxspeedtime240 * 5000.0f / TICKS(2400000);

	bike->speed[1] = bike->speedabs[1] + bike->speedrel[1] * cosangle + bike->speedrel[0] * sinangle;
	bike->speed[0] = bike->speedabs[0] + bike->speedrel[1] * sinangle - bike->speedrel[0] * cosangle;

	if (bike->base.flags & OBJFLAG_HOVERBIKE_MOVINGWHILEEMPTY) {
		if (bike->speed[0] > 0.1f
				|| bike->speed[1] > 0.1f
				|| bike->w > 0.001f
				|| bike->rels[0] > 0.001f
				|| bike->rels[1] > 0.001f
				|| bike->exreal > 0.001f
				|| bike->ezreal > 0.001f
				|| bike->ezreal2 > 0.001f
				|| bike->leandiff > 0.1f
				|| bike->speed[0] < -0.1f
				|| bike->speed[1] < -0.1f
				|| bike->w < -0.001f
				|| bike->rels[0] < -0.001f
				|| bike->rels[1] < -0.001f
				|| bike->exreal < -0.001f
				|| bike->ezreal < -0.001f
				|| bike->ezreal2 < -0.001f
				|| bike->leandiff < -0.1f) {
			// still moving
		} else {
			bike->speed[0] = 0;
			bike->speed[1] = 0;
			bike->w = 0;
			bike->rels[0] = 0;
			bike->rels[1] = 0;
			bike->exreal = 0;
			bike->ezreal = 0;
			bike->ezreal2 = 0;
			bike->leanspeed = 0;
			bike->leandiff = 0;
			bike->maxspeedtime240 = 0;
			bike->speedabs[0] = 0;
			bike->speedabs[1] = 0;
			bike->speedrel[0] = 0;
			bike->speedrel[1] = 0;

			if (1);

			bike->base.flags &= ~OBJFLAG_HOVERBIKE_MOVINGWHILEEMPTY;
		}
	}
}

static void platformDisplaceProps2(struct prop *platform, Mtxf *arg1)
{
	struct prop *prop;
	s16 *propnumptr;
	s16 propnums[256];
	u8 *sp9c;
	u8 *sp98;
	Mtxf sp58;

	if (propUpdateGeometry(platform, &sp9c, &sp98)) {
		roomGetProps(platform->rooms, propnums, 256);

		propnumptr = propnums;

		while (*propnumptr >= 0) {
			prop = &g_Vars.props[*propnumptr];

			if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) {
				struct defaultobj *obj = prop->obj;

				if (prop->pos.y > platform->pos.y
						&& (obj->hidden & OBJHFLAG_00008000)
						&& cd000266a4(prop->pos.x, prop->pos.z, (struct geo *)sp9c)) {
					mtx3ToMtx4(obj->realrot, &sp58);
					mtx4SetTranslation(&prop->pos, &sp58);
					mtx4MultMtx4InPlace(arg1, &sp58);
					mtx4ToMtx3(&sp58, obj->realrot);

					prop->pos.x = sp58.m[3][0];
					prop->pos.y = sp58.m[3][1];
					prop->pos.z = sp58.m[3][2];

					propDeregisterRooms(prop);
					func0f065e74(&platform->pos, platform->rooms, &prop->pos, prop->rooms);
					func0f069c70(obj, true, true);
				}
			}

			propnumptr++;
		}
	}
}

/**
 * Tick a Slayer fly-by-wire rocket that's being controlled by a bot.
 */
static bool rocketTickFbw(struct weaponobj *rocket)
{
	bool cdresult;
	f32 speed;
	s32 i;
	struct projectile *projectile = rocket->base.projectile;
	struct prop *rocketprop = rocket->base.prop;
	struct chrdata *ownerchr;
	struct coord sp164;
	struct coord sp158;
	Mtxf sp118;
	Mtxf spd8;
	Mtxf sp98;
	f32 xdist;
	f32 ydist;
	f32 zdist;
	struct prop *targetprop;
	f32 xrot;
	f32 yrot;
	struct coord newpos;
	struct coord dir;
	u32 stack[2];
	s16 newrooms[8];

	if (projectile->ownerprop && projectile->ownerprop->type == PROPTYPE_CHR) {
		ownerchr = projectile->ownerprop->chr;
	} else {
		ownerchr = NULL;
	}

	// If close to the next step (ie. a waypoint)
	// then advance to the one after that
	xdist = projectile->nextsteppos.x - rocketprop->pos.x;
	ydist = projectile->nextsteppos.y - rocketprop->pos.y;
	zdist = projectile->nextsteppos.z - rocketprop->pos.z;

	if (ownerchr && xdist * xdist + ydist * ydist + zdist * zdist < 100 * 100) {
		projectile->step++;

		if (projectile->numwaypads <= 0 || projectile->step >= projectile->numwaypads) {
			targetprop = chrGetTargetProp(ownerchr);

			if (!botactFindRocketRoute(ownerchr, &rocketprop->pos, &targetprop->pos, rocketprop->rooms, targetprop->rooms, projectile)) {
				rocket->timer240 = 0;
			}
		} else {
			botactGetRocketNextStepPos(projectile->waypads[projectile->step], &projectile->nextsteppos);
		}
	}

	if (ownerchr) {
		xrot = atan2f(xdist, zdist);
		yrot = atan2f(ydist, sqrtf(xdist * xdist + zdist * zdist));

		for (i = 0; i < g_Vars.lvupdate240; i++) {
			projectile->unk018 = model0001afe8(projectile->unk018, xrot, PAL ? 0.02246f : 0.01875f);
			projectile->unk014 = model0001afe8(projectile->unk014, yrot, PAL ? 0.02246f : 0.01875f);
		}

		mtx4LoadXRotation(M_BADTAU - projectile->unk014, &sp118);
		mtx4LoadYRotation(projectile->unk018, &spd8);
		mtx4MultMtx4(&spd8, &sp118, &sp98);
		mtx00015f04(rocket->base.model->scale, &sp98);
		mtx4ToMtx3(&sp98, rocket->base.realrot);
	}

	// Calculate new pos
	dir.f[0] = sinf(projectile->unk018) * cosf(projectile->unk014);
	dir.f[1] = sinf(projectile->unk014);
	dir.f[2] = cosf(projectile->unk018) * cosf(projectile->unk014);

	newpos = rocketprop->pos;

	for (i = 0; i < g_Vars.lvupdate60; i++) {
		projectile->unk010 += PAL ? 0.0021600001f : 0.0018f;

		speed = projectile->unk010;

		if (ownerchr && ownerchr->target == -1) {
			speed = PAL ? 0.120000004f : 0.10f;
		}

		newpos.x += dir.x * speed;
		newpos.y += dir.y * speed;
		newpos.z += dir.z * speed;
	}

	// Check if new pos would collide with anything
	if (projectile->ownerprop) {
		propSetPerimEnabled(projectile->ownerprop, false);
	}

	cdresult = func0f06cd00(&rocket->base, &newpos, &sp164, &sp158);

	if (projectile->ownerprop) {
		propSetPerimEnabled(projectile->ownerprop, true);
	}

	if (cdresult == CDRESULT_NOCOLLISION) {
		func0f065e74(&rocketprop->pos, rocketprop->rooms, &newpos, newrooms);

		rocketprop->pos = newpos;

		propDeregisterRooms(rocketprop);
		roomsCopy(newrooms, rocketprop->rooms);
		func0f069c70(&rocket->base, true, true);
	} else {
		// Boom
		rocket->timer240 = 0;
	}

	// Create smoke behind the rocket
	if (projectile->smoketimer240 <= 0) {
		projectile->smoketimer240 = TICKS(24);
		smokeCreateSimple(&rocketprop->pos, rocketprop->rooms, SMOKETYPE_ROCKETTAIL);
	} else {
		projectile->smoketimer240 -= g_Vars.lvupdate240;
	}

	// Blow up rocket if it's gone too high
	if (rocketprop->pos.y > 10000.0f) {
		rocket->timer240 = 0;
	}

	// Check if close to an enemy
	if (ownerchr && rocket->timer240) {
		for (i = 0; i < g_MpNumChrs; i++) {
			struct chrdata *chr = mpGetChrFromPlayerIndex(i);

			if (chr != ownerchr
					&& !chrIsDead(chr)
					&& chrCompareTeams(ownerchr, chr, COMPARE_ENEMIES)
					&& !botIsTargetInvisible(NULL, chr)) {
				// Explode if within 250 units
				xdist = rocketprop->pos.x - chr->prop->pos.x;
				ydist = rocketprop->pos.y - chr->prop->pos.y;
				zdist = rocketprop->pos.z - chr->prop->pos.z;

				if (xdist * xdist + ydist * ydist + zdist * zdist < 250 * 250) {
					rocket->timer240 = 0;
					break;
				}

				// Check if rocket can fly directly to target
				if (chrGetTargetProp(ownerchr) == chr->prop
						&& mpPlayerGetIndex(ownerchr) == g_Vars.lvframenum % g_MpNumChrs
						&& cdTestLos05(&rocketprop->pos, rocketprop->rooms, &chr->prop->pos, chr->prop->rooms,
							CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_PATHBLOCKER | CDTYPE_BG | CDTYPE_AIOPAQUE,
							GEOFLAG_BLOCK_SIGHT)) {
					projectile->nextsteppos = chr->prop->pos;
					projectile->numwaypads = 0;
				}
			}
		}
	}

	// If target is lost for 8 seconds, explode
	if (ownerchr && ownerchr->target == -1) {
		projectile->numwaypads = 0;

		projectile->losttimer240 += g_Vars.lvupdate240;

		if (projectile->losttimer240 > 8 * TICKS(240)) {
			rocket->timer240 = 0;
		}
	} else {
		projectile->losttimer240 = 0;
	}

	// If bot is killed, rocket becomes uncontrolled
	if (ownerchr && ((ownerchr->aibot && ownerchr->aibot->skrocket == NULL) || chrIsDead(ownerchr))) {
		projectile->ownerprop = NULL;
	}

	return cdresult;
}

s32 projectileLaunch(struct defaultobj *obj, struct projectile *projectile, struct coord *arg2, struct coord *arg3)
{
	s32 cdresult;
	struct prop *prop = obj->prop;

	if (projectile->ownerprop) {
		propSetPerimEnabled(projectile->ownerprop, false);
	}

	cdresult = func0f06cd00(obj, &projectile->nextsteppos, arg2, arg3);

	if (projectile->ownerprop) {
		propSetPerimEnabled(projectile->ownerprop, true);
	}

	if (cdresult == CDRESULT_NOCOLLISION) {
		s16 rooms[8];

		func0f065e74(&prop->pos, prop->rooms, &projectile->nextsteppos, rooms);

		prop->pos = projectile->nextsteppos;

		propDeregisterRooms(prop);
		roomsCopy(rooms, prop->rooms);
	} else if (cdresult != CDRESULT_NOCOLLISION && obj->type == OBJTYPE_WEAPON) {
		struct weaponobj *weapon = (struct weaponobj *)obj;
		s16 rooms[8];

		if (weapon->weaponnum == WEAPON_ROCKET || weapon->weaponnum == WEAPON_HOMINGROCKET) {
			weapon->timer240 = 0;

			func0f065e74(&prop->pos, prop->rooms, arg2, rooms);

			prop->pos = *arg2;

			propDeregisterRooms(prop);
			roomsCopy(rooms, prop->rooms);
		}
	}

	projectile->flags &= ~PROJECTILEFLAG_LAUNCHING;

	return cdresult;
}

s32 projectileTick(struct defaultobj *obj, bool *embedded)
{
	struct projectile *projectile = obj->projectile;
	s32 cdresult;
	struct coord sp5f4;
	struct coord sp5e8;
	struct coord sp5dc;
	bool result = false;
	struct prop *prop = obj->prop;
	struct coord sp5c8;
	s16 sp5b8[8];
	struct coord sp5ac;
	f32 sp5a8;
	struct coord sp59c;
	struct coord sp590;
	f32 sp58c;
	bool haslimitedarea;
	f32 ground;
	Mtxf sp544;
	Mtxf sp504;
	Mtxf sp4c4;
	Mtxf sp484;
	struct pad *pad;
	f32 dist;
	f32 shield;
	s32 i;

	if (g_Vars.lvupdate240 > 0) {
		if (obj->type == OBJTYPE_WEAPON && ((struct weaponobj *)obj)->weaponnum == WEAPON_SKROCKET) {
			result = rocketTickFbw((struct weaponobj *) obj);
		} else if (projectile->flags & PROJECTILEFLAG_00001000) {
			result = (projectile->flags & PROJECTILEFLAG_00002000) != 0;
			projectile->flags &= ~(PROJECTILEFLAG_00001000 | PROJECTILEFLAG_00002000);
		} else {
			obj->hidden &= ~OBJHFLAG_00020000;

			if (projectile->flags & PROJECTILEFLAG_LAUNCHING) {
				projectileLaunch(obj, projectile, &sp5e8, &sp5f4);
			}

			sp5dc = prop->pos;

			if (projectile->pickuptimer240 > 0) {
				projectile->pickuptimer240 -= g_Vars.lvupdate240;
			}

			if (projectile->flags & PROJECTILEFLAG_SLIDING) {
				f32 x;
				f32 innerdist;
				f32 outerdist;
				f32 z;

				mtx3ToMtx4(obj->realrot, &sp504);
				mtx4SetTranslation(&prop->pos, &sp504);

				if (projectile->unk0dc > 0.0f) {
					projectile->unk0dc -= projectile->unk0e0 * g_Vars.lvupdate60freal;

					if (projectile->unk0dc < 0.0f) {
						projectile->unk0dc = 0.0f;
					} else if (projectile->unk0e4 < 1.0f) {
						for (i = 0; i < g_Vars.lvupdate60; i++) {
							if (projectile->unk0dc > projectile->unk0ec) {
								projectile->unk0dc = projectile->unk0ec + (projectile->unk0dc - projectile->unk0ec) * projectile->unk0e4;
							}
						}
					}
				} else if (projectile->unk0dc < 0.0f) {
					projectile->unk0dc += projectile->unk0e0 * g_Vars.lvupdate60freal;

					if (projectile->unk0dc > 0.0f) {
						projectile->unk0dc = 0.0f;
					} else if (projectile->unk0e4 < 1.0f) {
						for (i = 0; i < g_Vars.lvupdate60; i++) {
							if (projectile->unk0dc < -projectile->unk0ec) {
								projectile->unk0dc = -projectile->unk0ec + (projectile->unk0dc + projectile->unk0ec) * projectile->unk0e4;
							}
						}
					}
				}

				if ((projectile->speed.f[0] != 0.0f || projectile->speed.f[2] != 0.0f) && projectile->unk098 > 0.0f) {
					dist = sqrtf(projectile->speed.f[0] * projectile->speed.f[0] + projectile->speed.f[2] * projectile->speed.f[2]);

					if (dist > 0.0f) {
						f32 f12 = projectile->unk098 * g_Vars.lvupdate60freal / dist;

						if (f12 >= 1.0f) {
							projectile->speed.x = 0.0f;
							projectile->speed.z = 0.0f;
						} else {
							projectile->speed.x -= projectile->speed.x * f12;
							projectile->speed.z -= projectile->speed.z * f12;

							if (projectile->unk0e4 < 1.0f) {
								for (i = 0; i < g_Vars.lvupdate60; i++) {
									if (projectile->speed.x > projectile->unk0f0) {
										projectile->speed.x = (projectile->speed.x - projectile->unk0f0) * projectile->unk0e4 + projectile->unk0f0;
									} else if (projectile->speed.x < -projectile->unk0f0) {
										projectile->speed.x = (projectile->speed.x + projectile->unk0f0) * projectile->unk0e4 + -projectile->unk0f0;
									}

									if (projectile->speed.z > projectile->unk0f0) {
										projectile->speed.z = (projectile->speed.z - projectile->unk0f0) * projectile->unk0e4 + projectile->unk0f0;
									} else if (projectile->speed.z < -projectile->unk0f0) {
										projectile->speed.z = (projectile->speed.z + projectile->unk0f0) * projectile->unk0e4 + -projectile->unk0f0;
									}
								}
							}
						}
					} else {
						projectile->speed.x = 0.0f;
						projectile->speed.z = 0.0f;
					}
				}

				if (projectile->ownerprop) {
					propSetPerimEnabled(projectile->ownerprop, false);
				}

				// Objects become more difficult to push
				// as you push them away from their pad
				haslimitedarea = obj->pad >= 0 && (obj->flags3 & (OBJFLAG3_GRABBABLE | OBJFLAG3_PUSHFREELY)) == 0;

				if (haslimitedarea) {
					pad = &g_Pads[obj->pad];

					innerdist = 200.0f;
					outerdist = 300.0f;

					if (obj->flags3 & OBJFLAG3_LONGPUSHRANGE) {
						innerdist += 700.0f;
						outerdist += 700.0f;
					}

					if (obj->modelnum == MODEL_SKPUZZLEOBJECT) {
						innerdist = 230.0f;
					}

					x = pad->pos.x - prop->pos.x;
					z = pad->pos.z - prop->pos.z;

					dist = sqrtf(x * x + z * z);

					if (dist > outerdist) {
						projectile->unk0dc = 0.0f;
					} else if (dist > innerdist) {
						projectile->unk0dc *= (outerdist - dist) * 0.01f;
					}
				}

				sp5a8 = projectile->unk0dc * g_Vars.lvupdate60freal;

				if (sp5a8 != 0.0f) {
					struct coord sp404 = {0, 0, 0};

					cdresult = func0f072144(obj, &sp404, sp5a8, true);

					if (cdresult != CDRESULT_ERROR && cdresult == CDRESULT_COLLISION) {
						projectile->unk0dc = -projectile->unk0dc * projectile->unk08c;
						objCollide(obj, &sp404, sp5a8);
					}
				}

				sp59c.x = projectile->speed.x * g_Vars.lvupdate60freal;
				sp59c.y = 0.0f;
				sp59c.z = projectile->speed.z * g_Vars.lvupdate60freal;

				if (haslimitedarea) {
					x = pad->pos.x - prop->pos.x - sp59c.x;
					z = pad->pos.z - prop->pos.z - sp59c.z;

					dist = sqrtf(x * x + z * z);

					if (dist > outerdist) {
						projectile->speed.f[0] = \
						projectile->speed.f[2] = \
						projectile->unk0dc = \
						sp59c.f[0] = \
						sp59c.f[2] = 0.0f;
					} else if (dist > innerdist) {
						projectile->speed.x *= (outerdist - dist) * 0.01f;
						projectile->speed.z *= (outerdist - dist) * 0.01f;

						sp59c.x *= (outerdist - dist) * 0.01f;
						sp59c.z *= (outerdist - dist) * 0.01f;
					}
				}

				cdresult = func0f072144(obj, &sp59c, 0.0f, true);

				if (cdresult == CDRESULT_COLLISION) {
					sp58c = objCollide(obj, &sp59c, 0.0f) * projectile->unk08c;

					if (sp58c > 0.0f) {
						f32 f0;
						struct coord sp3f4;
						struct coord sp3e8;
						struct coord sp3dc;
						struct coord sp3d0;
						struct coord sp3c4;
						struct coord sp3b8;
						struct coord sp3ac;
						f32 f0_2;

						if (cdGetSavedPos(&sp3d0, &sp3c4)) {
							sp3c4.x -= sp3d0.x;
							sp3c4.y -= sp3d0.y;
							sp3c4.z -= sp3d0.z;
						} else {
							sp3d0 = g_CdEdgeVtx1;
							sp3c4 = g_CdEdgeVtx2;

							sp3d0.x -= sp3c4.x;
							sp3d0.y -= sp3c4.y;
							sp3d0.z -= sp3c4.z;

							sp3c4.x = -sp3d0.z;
							sp3c4.y = sp3d0.y;
							sp3c4.z = sp3d0.x;

							sp3d0 = prop->pos;
						}

						func0f02e4f8(&sp3d0, &sp3c4, &sp3b8);

						sp3ac.x = prop->pos.x - sp5dc.x;
						sp3ac.y = 0.0f;
						sp3ac.z = prop->pos.z - sp5dc.z;

						sp3b8.x -= prop->pos.x;
						sp3b8.z -= prop->pos.z;

						f0 = (-sp3b8.f[0] * sp3ac.f[2] + sp3b8.f[2] * sp3ac.f[0]) * 0.0001f;

						if (f0 > projectile->unk0ec) {
							f0 = projectile->unk0ec;
						} else if (f0 < -projectile->unk0ec) {
							f0 = -projectile->unk0ec;
						}

						projectile->unk0dc += f0;

						sp3e8 = g_CdEdgeVtx1;
						sp3dc = g_CdEdgeVtx2;

						sp3f4.x = sp3dc.z - sp3e8.z;
						sp3f4.y = 0.0f;
						sp3f4.z = sp3e8.x - sp3dc.x;

						if (sp3f4.f[0] != 0.0f || sp3f4.f[2] != 0.0f) {
							guNormalize(&sp3f4.x, &sp3f4.y, &sp3f4.z);
						} else {
							sp3f4.z = 1.0f;
						}

						f0_2 = projectile->speed.f[0] * sp3f4.f[0] + projectile->speed.f[2] * sp3f4.f[2];
						f0_2 *= -(sp58c + 1.0f);

						sp590.x = projectile->speed.x + sp3f4.f[0] * f0_2;
						sp590.y = 0.0f;
						sp590.z = projectile->speed.z + sp3f4.f[2] * f0_2;

						sp59c.x = sp590.f[0] * g_Vars.lvupdate60freal;
						sp59c.y = 0.0f;
						sp59c.z = sp590.f[2] * g_Vars.lvupdate60freal;

						if (haslimitedarea) {
							x = pad->pos.x - prop->pos.x - sp59c.x;
							z = pad->pos.z - prop->pos.z - sp59c.z;

							dist = sqrtf(x * x + z * z);

							if (dist > outerdist) {
								projectile->speed.f[0] = \
								projectile->speed.f[2] = \
								projectile->unk0dc = \
								sp59c.f[0] = \
								sp59c.f[2] = 0.0f;
							} else if (dist > innerdist) {
								projectile->speed.x *= (outerdist - dist) * 0.01f;
								projectile->speed.z *= (outerdist - dist) * 0.01f;

								sp59c.x *= (outerdist - dist) * 0.01f;
								sp59c.z *= (outerdist - dist) * 0.01f;
							}
						}

						cdresult = func0f072144(obj, &sp59c, 0.0f, true);

						if (cdresult == CDRESULT_COLLISION) {
							sp58c = objCollide(obj, &sp59c, 0.0f) * projectile->unk08c;

							sp590.x = -projectile->speed.f[0] * sp58c;
							sp590.y = 0.0f;
							sp590.z = -projectile->speed.f[2] * sp58c;

							sp59c.x = sp590.f[0] * g_Vars.lvupdate60freal;
							sp59c.y = 0.0f;
							sp59c.z = sp590.f[2] * g_Vars.lvupdate60freal;

							if (haslimitedarea) {
								x = pad->pos.x - prop->pos.x - sp59c.x;
								z = pad->pos.z - prop->pos.z - sp59c.z;

								dist = sqrtf(x * x + z * z);

								if (dist > outerdist) {
									projectile->speed.f[0] = \
									projectile->speed.f[2] = \
									projectile->unk0dc = \
									sp59c.f[0] = \
									sp59c.f[2] = 0.0f;
								} else if (dist > innerdist) {
									projectile->speed.x *= (outerdist - dist) * 0.01f;
									projectile->speed.z *= (outerdist - dist) * 0.01f;

									sp59c.x *= (outerdist - dist) * 0.01f;
									sp59c.z *= (outerdist - dist) * 0.01f;
								}
							}

							cdresult = func0f072144(obj, &sp59c, 0.0f, true);

							if (cdresult == CDRESULT_COLLISION) {
								objCollide(obj, &sp59c, 0.0f);

								if (sp3e8.f[0] != sp3dc.f[0] || sp3e8.f[2] != sp3dc.f[2]) {
									f32 f12;
									struct coord sp398;
									f32 f14;

									sp398.x = sp3dc.x - sp3e8.x;
									sp398.z = sp3dc.z - sp3e8.z;

									f12 = 1.0f / sqrtf(sp398.f[0] * sp398.f[0] + sp398.f[2] * sp398.f[2]);

									sp398.x *= f12;
									sp398.z *= f12;

									f14 = projectile->speed.f[0] * sp398.f[0] + projectile->speed.f[2] * sp398.f[2];

									sp590.x = sp398.f[0] * f14;
									sp590.y = 0.0f;
									sp590.z = sp398.f[2] * f14;

									sp59c.x = sp590.f[0] * g_Vars.lvupdate60freal;
									sp59c.y = 0.0f;
									sp59c.z = sp590.f[2] * g_Vars.lvupdate60freal;

									if (haslimitedarea) {
										x = pad->pos.x - prop->pos.x - sp59c.x;
										z = pad->pos.z - prop->pos.z - sp59c.z;

										dist = sqrtf(x * x + z * z);

										if (dist > outerdist) {
											projectile->speed.f[0] = \
											projectile->speed.f[2] = \
											projectile->unk0dc = \
											sp59c.f[0] = \
											sp59c.f[2] = 0.0f;
										} else if (dist > innerdist) {
											projectile->speed.x *= (outerdist - dist) * 0.01f;
											projectile->speed.z *= (outerdist - dist) * 0.01f;

											sp59c.x *= (outerdist - dist) * 0.01f;
											sp59c.z *= (outerdist - dist) * 0.01f;
										}
									}

									cdresult = func0f072144(obj, &sp59c, 0.0f, true);

									if (cdresult == CDRESULT_COLLISION) {
										objCollide(obj, &sp59c, 0.0f);
									}
								}
							}
						}

						if (cdresult == CDRESULT_NOCOLLISION) {
							projectile->speed = sp590;
						}
					}
				}

				if (cdresult != CDRESULT_NOCOLLISION) {
					projectile->unk0dc = 0.0f;
					projectile->speed.z = 0.0f;
					projectile->speed.x = 0.0f;
				}

				if (projectile->ownerprop) {
					propSetPerimEnabled(projectile->ownerprop, true);
				}

				if (projectile->speed.f[0] == 0.0f && projectile->speed.f[2] == 0.0f && projectile->unk0dc == 0.0f) {
					objFreeProjectile(obj);
				}

				if (cdresult == CDRESULT_NOCOLLISION) {
					ground = cdFindGroundAtCyl(&prop->pos, 2, prop->rooms, &obj->floorcol, NULL);

					if (ground > -30000.0f) {
						prop->pos.y = ground + objGetHov04(obj);
					}
				}

				func0f069c70(obj, false, true);
				mtx3ToMtx4(obj->realrot, &sp484);
				mtx4SetTranslation(&prop->pos, &sp484);
				mtx000172f0(sp504.m, sp4c4.m);
				mtx4MultMtx4(&sp484, &sp4c4, &sp544);
				platformDisplaceProps2(prop, &sp544);
				result = true;
			} else if (projectile->flags & PROJECTILEFLAG_AIRBORNE) {
				f32 sp390;
				s16 roomnum;
				struct coord sp380;
				f32 sp37c;
				f32 realrot[3][3];
				bool sp354 = false;
				bool sp350 = false;
				bool handled = false;
				Mtxf sp30c;
				bool homingrocket;
				u32 stack;

				projectile->losttimer240 += g_Vars.lvupdate240;

				if (((projectile->flags & PROJECTILEFLAG_NOTIMELIMIT) == 0 && projectile->losttimer240 > TICKS(9600))
						|| prop->pos.y < -20000.0f || prop->pos.y > 32000.0f
						|| prop->pos.x < -32000.0f || prop->pos.x > 32000.0f
						|| prop->pos.z < -32000.0f || prop->pos.z > 32000.0f) {
					obj->hidden |= OBJHFLAG_REAPABLE;
				}

				projectile->flighttime240 += g_Vars.lvupdate240;

				mtx3Copy(obj->realrot, realrot);

				if (projectile->flags & PROJECTILEFLAG_00000020) {
					if (projectile->unk01c < (1.0f / 3.6f)) {
						projectile->unk0ac += projectile->unk014 * g_Vars.lvupdate60freal;
						projectile->unk0a8 += projectile->unk0ac * g_Vars.lvupdate60freal;
						projectile->unk01c += (1.0f / 90.0f) * g_Vars.lvupdate60freal;

						if (projectile->unk01c > (1.0f / 3.6f)) {
							projectile->unk01c = (1.0f / 3.6f);
						}
					} else {
						if (projectile->unk0a8 > sp5dc.y) {
							projectile->unk0ac += projectile->unk014 * g_Vars.lvupdate60freal;
							projectile->unk0a8 += projectile->unk0ac * g_Vars.lvupdate60freal;

							sp5dc.y += 0.07f * (projectile->unk0a8 - sp5dc.y) * g_Vars.lvupdate60freal;
						} else {
							sp5dc.y = projectile->unk0a8;

							projectile->flags &= ~PROJECTILEFLAG_00000020;
							projectile->flags |= PROJECTILEFLAG_POWERED;
							projectile->speed.y = projectile->unk0ac;
							projectile->unk01c = 0.0f;
						}
					}
				}

				homingrocket = false;

				if (obj->type == OBJTYPE_WEAPON && ((struct weaponobj *)obj)->weaponnum == WEAPON_HOMINGROCKET) {
					homingrocket = true;
				}

				if (homingrocket) {
					struct coord sp2f8 = {0, 0, 0};
					struct coord sp2ec = {0, 0, 1};
					struct coord sp2e0 = {0, 1, 0};

					if (obj && obj->prop && projectile->targetprop) {
						Mtxf mtx;
						f32 sp29c = sqrtf(obj->realrot[0][0] * obj->realrot[0][0] + obj->realrot[1][0] * obj->realrot[1][0] + obj->realrot[2][0] * obj->realrot[2][0]);
						struct coord sp290;
						f32 sp28c;

						mtx4LoadIdentity(&mtx);

						mtx.m[0][0] = obj->realrot[0][0] / sp29c;
						mtx.m[0][1] = obj->realrot[0][1] / sp29c;
						mtx.m[0][2] = obj->realrot[0][2] / sp29c;
						mtx.m[1][0] = obj->realrot[1][0] / sp29c;
						mtx.m[1][1] = obj->realrot[1][1] / sp29c;
						mtx.m[1][2] = obj->realrot[1][2] / sp29c;
						mtx.m[2][0] = obj->realrot[2][0] / sp29c;
						mtx.m[2][1] = obj->realrot[2][1] / sp29c;
						mtx.m[2][2] = obj->realrot[2][2] / sp29c;

						sp2f8 = obj->prop->pos;

						sp290.x = projectile->targetprop->pos.x - sp2f8.x;
						sp290.y = projectile->targetprop->pos.y - sp2f8.y;
						sp290.z = projectile->targetprop->pos.z - sp2f8.z;

						guNormalize(&sp290.x, &sp290.y, &sp290.z);

						sp2ec = projectile->speed;

						guNormalize(&sp2ec.x, &sp2ec.y, &sp2ec.z);

						sp28c = acosf(sp2ec.f[0] * sp290.f[0] + sp2ec.f[1] * sp290.f[1] + sp2ec.f[2] * sp290.f[2]);

						if (sp28c > 0.001f || sp28c < -0.001f) {
							struct coord sp280;
							f32 sp270[4];
							f32 sp260[4];
							f32 sp250[4];
							f32 angle;
							Mtxf sp20c;
							f32 tmp;
							u32 stack[2];

							static f32 var80069bc4 = 0;

							tmp = ((20 / 100.0f * var80069bc4 / LVUPDATE60FREAL()) + (120 / 100.00f * sp28c * LVUPDATE60FREAL())) * (3 / 100.000f);

							var80069bc4 = sp28c;

							sp280.x = sp2ec.f[1] * sp290.f[2] - sp2ec.f[2] * sp290.f[1];
							sp280.y = -(sp2ec.f[0] * sp290.f[2] - sp2ec.f[2] * sp290.f[0]);
							sp280.z = sp2ec.f[0] * sp290.f[1] - sp2ec.f[1] * sp290.f[0];

							sp260[0] = cosf(tmp * 0.5f);
							sp260[1] = sp280.f[0] * sinf(tmp * 0.5f);
							sp260[2] = sp280.f[1] * sinf(tmp * 0.5f);
							sp260[3] = sp280.f[2] * sinf(tmp * 0.5f);

							quaternionToMtx(sp260, &sp20c);

							projectile->unk018 = 0.0f;
							projectile->unk014 = 0.0f;
							projectile->unk010 = 0.0f;

							mtx4RotateVecInPlace(&sp20c, &projectile->speed);

							quaternion0f097044(&mtx, sp270);
							quaternionMultQuaternion(sp270, sp260, sp250);
							quaternionToMtx(sp250, &sp20c);

							obj->realrot[0][0] = sp20c.m[0][0] * sp29c;
							obj->realrot[0][1] = sp20c.m[0][1] * sp29c;
							obj->realrot[0][2] = sp20c.m[0][2] * sp29c;
							obj->realrot[1][0] = sp20c.m[1][0] * sp29c;
							obj->realrot[1][1] = sp20c.m[1][1] * sp29c;
							obj->realrot[1][2] = sp20c.m[1][2] * sp29c;
							obj->realrot[2][0] = sp20c.m[2][0] * sp29c;
							obj->realrot[2][1] = sp20c.m[2][1] * sp29c;
							obj->realrot[2][2] = sp20c.m[2][2] * sp29c;
						}
					}
				}

				if ((projectile->flags & PROJECTILEFLAG_POWERED) == 0) {
					// Apply gravity
					f32 f0;

					projectile->speed.y += (projectile->unk014 + projectile->unk01c) * g_Vars.lvupdate60freal;

					if (projectile->flags & PROJECTILEFLAG_LIGHTWEIGHT) {
						f0 = projectile->speed.y - (1.0f / 7.2f) * g_Vars.lvupdate60freal;
					} else {
						f0 = projectile->speed.y - (1.0f / 3.6f) * g_Vars.lvupdate60freal;
					}

					sp5dc.y += g_Vars.lvupdate60freal * (projectile->speed.y + f0) * 0.5f;

					projectile->speed.y = f0;
				} else {
					projectile->speed.y += (projectile->unk014 + projectile->unk01c) * g_Vars.lvupdate60freal;
					sp5dc.y += projectile->speed.y * g_Vars.lvupdate60freal;
				}

				projectile->speed.x += projectile->unk010 * g_Vars.lvupdate60freal;
				projectile->speed.z += projectile->unk018 * g_Vars.lvupdate60freal;

				sp5dc.x += projectile->speed.x * g_Vars.lvupdate60freal;
				sp5dc.z += projectile->speed.z * g_Vars.lvupdate60freal;

				mtx3ToMtx4(obj->realrot, &sp30c);
				func0f096698(&sp30c, &projectile->mtx, g_Vars.lvupdate240);
				mtx4ToMtx3(&sp30c, obj->realrot);

				sp5c8 = prop->pos;

				roomsCopy(prop->rooms, sp5b8);

				if (projectile->ownerprop) {
					propSetPerimEnabled(projectile->ownerprop, false);
				}

				if (projectile->flags & PROJECTILEFLAG_STICKY) {
					cdresult = func0f06cd00(obj, &sp5dc, &sp5e8, &sp5f4);
				} else {
					cdresult = func0f06d37c(obj, &sp5dc, &sp5e8, &sp5f4);
				}

				if (projectile->ownerprop) {
					propSetPerimEnabled(projectile->ownerprop, true);
				}

				result = true;

				if (projectile->flags & PROJECTILEFLAG_STICKY) {
					if (cdresult == CDRESULT_COLLISION) {
						bool stick = false;
						struct prop *hitprop = NULL;
						struct weaponobj *weapon2;
						struct weaponobj *weapon;

						if (g_EmbedProp != NULL) {
							hitprop = g_EmbedProp;

							while (hitprop->parent) {
								hitprop = hitprop->parent;
							}
						}

						if (obj->type == OBJTYPE_AUTOGUN) {
							// Thrown laptops can stick to the BG but not props
							if (hitprop == NULL) {
								stick = true;
							}
						} else if (obj->type == OBJTYPE_WEAPON) {
							weapon2 = (struct weaponobj *) obj;

							if (weapon2->weaponnum == WEAPON_REMOTEMINE
									|| weapon2->weaponnum == WEAPON_TIMEDMINE
									|| weapon2->weaponnum == WEAPON_PROXIMITYMINE
									|| weapon2->weaponnum == WEAPON_COMMSRIDER
									|| weapon2->weaponnum == WEAPON_TRACERBUG
									|| weapon2->weaponnum == WEAPON_TARGETAMPLIFIER
									|| weapon2->weaponnum == WEAPON_BOLT
									|| weapon2->weaponnum == WEAPON_COMBATKNIFE
									|| weapon2->weaponnum == WEAPON_ECMMINE
									|| gsetHasFunctionFlags(&weapon2->gset, FUNCFLAG_STICKTOWALL)) {
								stick = true;

								if (weapon2->weaponnum == WEAPON_GRENADEROUND && weapon2->gunfunc == FUNC_SECONDARY) {
									if (weapon2->timer240 == 1) {
										stick = false;
										weapon2->timer240 = 0;
									} else {
										weapon2->timer240 = TICKS(480);
									}
								}
							}
						}

						if (stick) {
							weapon = NULL;

							if (obj->type == OBJTYPE_WEAPON) {
								weapon = (struct weaponobj *) obj;
							}

							if (g_EmbedProp && (g_EmbedProp->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR))) {
								struct defaultobj *embedobj = g_EmbedProp->obj;

								if (weapon
										&& (weapon->weaponnum == WEAPON_BOLT || weapon->weaponnum == WEAPON_COMBATKNIFE)
										&& embedobj->type == OBJTYPE_WEAPON) {
									stick = false;
								}
							}

							if (hitprop != NULL) {
								if (hitprop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
									struct defaultobj *hitobj = hitprop->obj;

									if ((hitobj->hidden & OBJHFLAG_PROJECTILE)
											&& (hitobj->projectile->flags & PROJECTILEFLAG_SLIDING) == 0) {
										stick = false;
									}

									if (var80069944 == 10000) {
										stick = false;
									}

									if (weapon && (weapon->weaponnum == WEAPON_BOLT || weapon->weaponnum == WEAPON_COMBATKNIFE)) {
										if (hitobj->type == OBJTYPE_GLASS || hitobj->type == OBJTYPE_TINTEDGLASS) {
											bgunPlayGlassHitSound(&prop->pos, prop->rooms, -1);

											if ((hitobj->flags2 & OBJFLAG2_IMMUNETOGUNFIRE) == 0) {
												objTakeGunfire(hitobj, 100, &prop->pos, weapon->weaponnum, g_Vars.currentplayernum);
												objDropRecursively(hitprop, false);
												stick = false;
												handled = true;
											}
										}
									}
								} else if ((hitprop->type & (PROPTYPE_CHR | PROPTYPE_PLAYER))
										&& hitprop->chr->cshield > 0.0f) {
									stick = false;
								}
							}
						}

						if (!handled && g_EmbedProp && obj->type == OBJTYPE_WEAPON) {
							struct weaponobj *weapon = (struct weaponobj *) obj;

							if (weapon->weaponnum == WEAPON_BOLT || weapon->weaponnum == WEAPON_COMBATKNIFE) {
								if (hitprop->type == PROPTYPE_CHR || (hitprop->type == PROPTYPE_PLAYER && hitprop->chr)) {
									struct chrdata *hitchr = hitprop->chr;

									if ((obj->projectile->flags & PROJECTILEFLAG_AIRBORNE) && obj->projectile->bouncecount <= 0) {
										f32 ownershield;
										struct prop *ownerprop;

										ownerprop = obj->projectile->ownerprop;
										ownershield = hitchr->cshield;

										func0f0341dc(hitchr, gsetGetDamage(&weapon->gset), &var8009ce78, &weapon->gset, ownerprop,
												g_EmbedHitPart, g_EmbedProp, g_EmbedNode, g_EmbedModel, g_EmbedSide, var8006993c);

										if (ownershield <= 0.0f) {
											chrEmitSparks(hitchr, g_EmbedProp, g_EmbedHitPart, &sp5e8, &sp5f4, ownerprop ? ownerprop->chr : NULL);

											if (g_EmbedProp->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
												if (g_EmbedModel && g_EmbedHitPart != HITPART_GUN && g_EmbedHitPart != HITPART_HAT) {
													struct coord sp1c8;
													Mtxf sp188;
													Mtxf *sp184;

													sp184 = model0001a5cc(g_EmbedModel, g_EmbedNode, 0);
													mtx4TransformVec(g_Vars.currentplayer->worldtoscreenmtx, &sp5e8, &sp1c8);
													mtx0001719c(sp184->m, sp188.m);
													mtx4TransformVecInPlace(&sp188, &sp1c8);

													chr0f0260c4(g_EmbedModel, g_EmbedHitPart, g_EmbedNode, &sp1c8);
												}
											}
										}
									}
								} else if (hitprop->type == PROPTYPE_OBJ) {
									struct defaultobj *hitobj = hitprop->obj;

									if (var80069944 == 10000) {
										shield = (hitobj->flags3 & OBJFLAG3_SHOWSHIELD) ? 4 : 8;

										shieldhitCreate(hitprop, shield, g_EmbedProp, g_EmbedNode, g_EmbedModel, g_EmbedSide, var8006993c);
									}

									if (hitobj->modelnum == MODEL_TARGET && var80069944 == TEXTURE_0B9E) {
										frCalculateHit(hitobj, &sp5e8, 0.0f);
									}
								}
							} else if (weapon->weaponnum == WEAPON_ROCKET || weapon->weaponnum == WEAPON_HOMINGROCKET) {
								s32 ownerplayernum = (obj->hidden & 0xf0000000) >> 28;

								if (g_EmbedProp->type == PROPTYPE_CHR || (g_EmbedProp->type == PROPTYPE_PLAYER && g_EmbedProp->chr)) {
									struct prop *ownerprop2 = NULL;

									if (g_Vars.normmplayerisrunning) {
										struct chrdata *ownerchr = mpGetChrFromPlayerIndex(ownerplayernum);

										if (ownerchr != NULL) {
											ownerprop2 = ownerchr->prop;
										}
									}

									func0f0341dc(g_EmbedProp->chr, 2.0f, &var8009ce78, &weapon->gset, ownerprop2,
											g_EmbedHitPart, g_EmbedProp, g_EmbedNode, g_EmbedModel, g_EmbedSide, var8006993c);
								} else if (g_EmbedProp->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) {
									if (var80069944 == 10000) {
										f32 shield = (g_EmbedProp->obj->flags3 & OBJFLAG3_SHOWSHIELD) ? 4 : 8;

										shieldhitCreate(hitprop, shield, g_EmbedProp, g_EmbedNode, g_EmbedModel, g_EmbedSide, var8006993c);
									}

									objDamage(g_EmbedProp->obj, 100, &prop->pos, weapon->weaponnum, ownerplayernum);
								}

								handled = true;
								func0f069c70(obj, true, true);
								weapon->timer240 = 0;
							} else {
								if (hitprop->type == PROPTYPE_CHR || (hitprop->type == PROPTYPE_PLAYER && hitprop->chr)) {
									struct chrdata *chr = hitprop->chr;
									func0f034080(chr, g_EmbedNode, g_EmbedProp, g_EmbedModel, g_EmbedSide, var8006993c);
								} else if ((hitprop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) && var80069944 == 10000) {
									shield = (hitprop->obj->flags3 & OBJFLAG3_SHOWSHIELD) ? 4 : 8;

									shieldhitCreate(hitprop, shield, g_EmbedProp, g_EmbedNode, g_EmbedModel, g_EmbedSide, var8006993c);
								}
							}
						}

						if (!handled && stick) {
							handled = true;

							func0f069c70(obj, true, true);

							if (obj->type == OBJTYPE_WEAPON) {
								struct weaponobj *weapon = (struct weaponobj *) obj;

								if (weapon->weaponnum == WEAPON_BOLT || weapon->weaponnum == WEAPON_COMBATKNIFE) {
									if (obj->projectile->ownerprop && obj->projectile->ownerprop->type == PROPTYPE_PLAYER) {
										s32 prevplayernum = g_Vars.currentplayernum;
										setCurrentPlayerNum(playermgrGetPlayerNumByProp(obj->projectile->ownerprop));
										mpstatsIncrementPlayerShotCount(&weapon->gset, SHOTREGION_TOTAL);

										if (g_EmbedProp != NULL) {
											if (g_EmbedProp->type == PROPTYPE_OBJ) {
												if (objIsHealthy(g_EmbedProp->obj)) {
													mpstatsIncrementPlayerShotCount(&weapon->gset, SHOTREGION_OBJECT);
												}
											} else if (g_EmbedProp->type & (PROPTYPE_CHR | PROPTYPE_PLAYER)) {
												struct chrdata *embedchr = g_EmbedProp->chr;
												bool dead = false;

												if (embedchr && embedchr->actiontype == ACT_DEAD) {
													dead = true;
												}

												if (g_EmbedProp->type == PROPTYPE_PLAYER && g_Vars.players[playermgrGetPlayerNumByProp(g_EmbedProp)]->isdead) {
													dead = true;
												}

												if (!dead) {
													switch (g_EmbedHitPart) {
													case 0:
														break;
													case HITPART_HEAD:
														mpstatsIncrementPlayerShotCount(&weapon->gset, SHOTREGION_HEAD);
														break;
													case HITPART_GUN:
														mpstatsIncrementPlayerShotCount(&weapon->gset, SHOTREGION_GUN);
														break;
													case HITPART_HAT:
														mpstatsIncrementPlayerShotCount(&weapon->gset, SHOTREGION_HAT);
														break;
													case HITPART_PELVIS:
													case HITPART_TORSO:
														mpstatsIncrementPlayerShotCount(&weapon->gset, SHOTREGION_BODY);
														break;
													default:
														mpstatsIncrementPlayerShotCount(&weapon->gset, SHOTREGION_LIMB);
														break;
													}
												}
											}
										}

										setCurrentPlayerNum(prevplayernum);
									}

									if (hitprop == NULL || (hitprop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR))) {
										struct coord dir;
										struct prop *ownerprop = obj->projectile->ownerprop;

										dir = projectile->speed;

										guNormalize(&dir.x, &dir.y, &dir.z);

										if (chrIsUsingPaintball(ownerprop ? ownerprop->chr : NULL)) {
											sparksCreate(prop->rooms[0], prop, &sp5e8, &dir, &sp5f4, SPARKTYPE_PAINT);
										} else {
											sparksCreate(prop->rooms[0], prop, &sp5e8, &dir, &sp5f4, SPARKTYPE_PROJECTILE);
										}
									}
								}
							}

							objLand(prop, &sp5e8, &sp5f4, embedded);
						}
					}

					if (!handled) {
						if (cdresult != CDRESULT_COLLISION) {
							s16 rooms[8];

							func0f065e74(&prop->pos, prop->rooms, &sp5dc, rooms);

							prop->pos = sp5dc;

							propDeregisterRooms(prop);
							roomsCopy(rooms, prop->rooms);
						} else {
							s16 rooms[8];

							if (g_EmbedProp && (g_EmbedProp->type & (PROPTYPE_CHR | PROPTYPE_PLAYER))) {
								sp5dc.x = prop->pos.x;
								sp5dc.z = prop->pos.z;
							} else {
								sp5dc = sp5e8;
							}

							func0f065e74(&prop->pos, prop->rooms, &sp5dc, rooms);

							prop->pos = sp5dc;

							propDeregisterRooms(prop);
							roomsCopy(rooms, prop->rooms);
						}
					}
				}

				if (!handled) {
					u16 geoflags;

					sp37c = objGetRotatedLocalYMinByMtx3(objFindBboxRodata(obj), obj->realrot);

					sp5ac.x = prop->pos.x;
					sp5ac.y = prop->pos.y + sp37c;
					sp5ac.z = prop->pos.z;

					roomnum = cdFindCeilingRoomYColourFlagsNormalAtPos(&sp5ac, prop->rooms, &sp390, &obj->floorcol, &geoflags, &sp380);

					if (roomnum > 0
							&& prop->pos.y + sp37c < sp390
							&& !cdTestLos03(&sp5c8, sp5b8, &sp5ac, CDTYPE_OBJS | CDTYPE_BG, GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2)) {
						sp354 = true;
						sp5f4 = sp380;

						guNormalize(&sp5f4.x, &sp5f4.y, &sp5f4.z);

						sp5e8.x = prop->pos.x;
						sp5e8.y = sp390;
						sp5e8.z = prop->pos.z;

						cdresult = CDRESULT_COLLISION;

						if (geoflags & GEOFLAG_DIE) {
							obj->hidden |= OBJHFLAG_REAPABLE;
						}
					} else {
						roomnum = cdFindFloorRoomYColourNormalPropAtPos(&prop->pos, prop->rooms, &sp390, &obj->floorcol, &sp380, NULL);

						if (roomnum <= 0 && (projectile->flags & PROJECTILEFLAG_STICKY) == 0) {
							if ((projectile->flags & PROJECTILEFLAG_00010000) == 0) {
								projectile->flags |= PROJECTILEFLAG_00010000;

								if (cdFindFloorRoomAtPos(&sp5c8, sp5b8) > 0) {
									projectile->flags |= PROJECTILEFLAG_INROOM;
								}
							}

							if (projectile->flags & PROJECTILEFLAG_INROOM) {
								prop->pos = sp5c8;

								propDeregisterRooms(prop);
								roomsCopy(sp5b8, prop->rooms);

								roomnum = cdFindFloorRoomYColourFlagsAtPos(&prop->pos, prop->rooms, &sp390, &obj->floorcol, NULL);

								projectile->speed.x = 0.0f;
								projectile->speed.z = 0.0f;
							}
						}
					}

					if (roomnum > 0) {
						projectile->flags |= PROJECTILEFLAG_INROOM;
					} else {
						projectile->flags &= ~PROJECTILEFLAG_INROOM;
					}

					if (cdresult == CDRESULT_COLLISION) {
						// Bouncing
						if ((projectile->speed.y <= 0.0f && sp5c8.y <= prop->pos.y)
								|| ((projectile->flags & PROJECTILEFLAG_STICKY) == 0 && sp354)) {
							sp350 = true;
						}

						if (projectile->unk08c > 0.0f) {
							f32 oldyspeed;
							f32 f0 = projectile->speed.f[0] * sp5f4.f[0] + projectile->speed.f[1] * sp5f4.f[1] + projectile->speed.f[2] * sp5f4.f[2];

							f0 *= -(projectile->unk08c + 1.0f);

							oldyspeed = projectile->speed.y;

							projectile->speed.x += f0 * sp5f4.x;
							projectile->speed.y += f0 * sp5f4.y;
							projectile->speed.z += f0 * sp5f4.z;

							if (oldyspeed <= 0.0f && projectile->speed.y >= 0.0f) {
								sp350 = true;
							}

							if (obj->type == OBJTYPE_WEAPON) {
								struct weaponobj *weapon = (struct weaponobj *) obj;

								if (weapon->weaponnum == WEAPON_GRENADE && weapon->gunfunc == FUNC_SECONDARY) {
									smokeCreateAtProp(prop, SMOKETYPE_PINBALL);
								}
							}
						}

						if (sp350) {
							prop->pos.y = sp5e8.y - sp37c;

							if (sp354) {
								prop->pos.y += func0f06a620(obj);
							}
						}

						if ((projectile->flags & PROJECTILEFLAG_00000100) == 0
								&& (projectile->bounceframe < 0 || projectile->bounceframe < g_Vars.lvframe60 - TICKS(60))) {
							mtxLoadRandomRotation(&projectile->mtx);
						}

						projectile->bouncecount++;
						projectile->bounceframe = g_Vars.lvframe60;

						if ((obj->hidden & OBJHFLAG_00010000) == 0) {
							obj->hidden |= OBJHFLAG_00000100;
						}

						if (sp350) {
							if ((projectile->flags & PROJECTILEFLAG_STICKY) == 0 && projectile->bouncecount >= 6) {
								if (sp354) {
									projectileFall(obj, realrot);
								}
							} else if (projectile->unk08c > 0.0f) {
								if (projectile->speed.y >= 0.0f && projectile->speed.y < 2.2222223f) {
									if ((projectile->flags & PROJECTILEFLAG_00000002) && projectile->bouncecount == 1) {
										projectile->speed.y = 2.2222223f;
									} else {
										if (sp354) {
											projectileFall(obj, realrot);
										}
									}
								}
							} else {
								if (sp354) {
									projectileFall(obj, realrot);
								}
							}
						}
					}

					if (obj->type == OBJTYPE_WEAPON) {
						struct weaponobj *weapon = (struct weaponobj *) obj;

						if (weapon->weaponnum == WEAPON_COMBATKNIFE && weapon->gunfunc == FUNC_SECONDARY) {
							knifePlayWooshSound(obj);
						} else if (weapon->weaponnum == WEAPON_ROCKET) {
							if (cdresult == CDRESULT_COLLISION) {
								weapon->timer240 = 0;
							} else {
								f32 tmp = projectile->speed.f[0] * projectile->speed.f[0]
									+ projectile->speed.f[1] * projectile->speed.f[1]
									+ projectile->speed.f[2] * projectile->speed.f[2];

								if (tmp > 27777.773f) {
									projectile->unk010 = 0.0f;
									projectile->unk014 = 0.0f;
									projectile->unk018 = 0.0f;
								}

								if (projectile->powerlimit240 >= 0 && projectile->flighttime240 > projectile->powerlimit240) {
									projectile->unk01c = 0.0f;
									projectile->flags &= ~(PROJECTILEFLAG_POWERED | PROJECTILEFLAG_00000020);
								} else {
									struct coord smokepos;

									smokepos = projectile->speed;

									guNormalize(&smokepos.x, &smokepos.y, &smokepos.z);

									smokepos.x = prop->pos.x - smokepos.x * 20.0f;
									smokepos.y = prop->pos.y - smokepos.y * 20.0f;
									smokepos.z = prop->pos.z - smokepos.z * 20.0f;

									smokeCreateSimple(&smokepos, prop->rooms, SMOKETYPE_ROCKETTAIL);
								}
							}
						} else if (weapon->weaponnum == WEAPON_HOMINGROCKET) {
							if (cdresult == CDRESULT_COLLISION) {
								weapon->timer240 = 0;
							} else {
								smokeCreateSimple(&prop->pos, prop->rooms, SMOKETYPE_HOMINGTAIL);
							}
						} else if (weapon->weaponnum == WEAPON_GRENADEROUND
								|| (weapon->weaponnum == WEAPON_NBOMB && weapon->gunfunc == FUNC_PRIMARY)) {
							if (sp350
									|| (projectile->flags & PROJECTILEFLAG_FALLING)
									|| (projectile->speed.x < 0.1f && projectile->speed.x > -0.1f
										&& projectile->speed.y < 0.1f && projectile->speed.y > -0.1f
										&& projectile->speed.z < 0.1f && projectile->speed.z > -0.1f)
									|| (prop->pos.x - sp5c8.x < 0.1f && prop->pos.x - sp5c8.x > -0.1f
										&& prop->pos.y - sp5c8.y < 0.1f && prop->pos.y - sp5c8.y > -0.1f
										&& prop->pos.z - sp5c8.z < 0.1f && prop->pos.z - sp5c8.z > -0.1f)) {
								if (weapon->weaponnum != WEAPON_NBOMB || weapon->timer240 >= 0) {
									weapon->timer240 = 0;
								}
							} else if (weapon->weaponnum != WEAPON_NBOMB) {
								smokeCreateSimple(&prop->pos, prop->rooms, SMOKETYPE_GRENADETAIL);
							}
						}

						if (cdresult == CDRESULT_COLLISION) {
							if (projectile->unk0a4 < g_Vars.lvframenum - 2) {
								if (weapon->weaponnum == WEAPON_COMBATKNIFE || weapon->weaponnum == WEAPON_COMBATKNIFE) {
									propsnd0f0939f8(0, prop, SFX_808B, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
								} else if (weapon->weaponnum == WEAPON_GRENADE && weapon->gunfunc == FUNC_SECONDARY) {
									u16 sp100[] = {SFX_0027, SFX_0028, SFX_0029, SFX_002A};

									propsnd0f0939f8(0, prop, sp100[random() % 4], -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
									propsnd0f0939f8(0, prop, SFX_EYESPYHIT, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
								} else {
									propsnd0f0939f8(0, prop, SFX_EYESPYHIT, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
								}
							}

							projectile->unk0a4 = g_Vars.lvframenum;
						}
					}

					func0f069c70(obj, true, true);
				}
			} else if (projectile->flags & PROJECTILEFLAG_FALLING) {
				// Some objects are placed in mid-air and then given this flag
				// at level start, which causes them fall down to their resting
				// position. Once stopped, the flag is removed.
				bool stop = true;
				f32 quaternion[4];
				Mtxf spac;

				if (projectile->unk060 < 1.0f) {
					projectile->unk060 += projectile->unk064 * g_Vars.lvupdate60freal;

					if (g_Vars.lvupdate60 > 0) {
						projectile->unk064 *= 1.1f;
					}

					if (projectile->unk060 > 1.0f) {
						projectile->unk060 = 1.0f;
					}

					quaternionSlerp(projectile->unk068, projectile->unk078, projectile->unk060, quaternion);
					quaternionToMtx(quaternion, &spac);
					mtx00015e24(projectile->unk0b8[0], &spac);
					mtx00015e80(projectile->unk0b8[1], &spac);
					mtx00015edc(projectile->unk0b8[2], &spac);
					mtx4ToMtx3(&spac, obj->realrot);
					stop = false;
				}

				if (projectile->speed.f[0] != 0.0f || projectile->speed.f[2] != 0.0f || projectile->unk060 < 1.0f) {
					f32 f12;
					f32 spa4;
					s16 roomnum;
					s32 i;
					f32 sp98 = objGetRotatedLocalYMinByMtx3(objFindBboxRodata(obj), obj->realrot);
					u16 geoflags;

					stop = false;

					for (i = 0; i < g_Vars.lvupdate60; i++) {
						sp5dc.x += PALUPF(projectile->speed.x);
						sp5dc.z += PALUPF(projectile->speed.z);

						if (projectile->unk060 >= 1.0f) {
							if (projectile->unk098 > 0.0f) {
								f32 dist = sqrtf(projectile->speed.f[0] * projectile->speed.f[0] + projectile->speed.f[2] * projectile->speed.f[2]);

								if (dist > 0.0f) {
									f12 = projectile->unk098 * g_Vars.lvupdate60freal / dist;

									if (f12 >= 1.0f) {
										projectile->speed.x = 0.0f;
										projectile->speed.z = 0.0f;
									} else {
										projectile->speed.x -= projectile->speed.x * f12;
										projectile->speed.z -= projectile->speed.z * f12;
									}
								} else {
									projectile->speed.x = 0.0f;
									projectile->speed.z = 0.0f;
								}
							} else {
								projectile->speed.x *= 0.9f;
								projectile->speed.z *= 0.9f;
							}
						}
					}

					sp5c8 = prop->pos;

					roomsCopy(prop->rooms, sp5b8);
					func0f06d37c(obj, &sp5dc, &sp5e8, &sp5f4);

					result = true;

					sp5ac.x = prop->pos.x;
					sp5ac.y = prop->pos.y + sp98;
					sp5ac.z = prop->pos.z;

					roomnum = cdFindCeilingRoomYColourFlagsAtPos(&sp5ac, prop->rooms, &spa4, &obj->floorcol, &geoflags);

					if (roomnum <= 0 || cdTestLos03(&sp5c8, sp5b8, &sp5ac, CDTYPE_OBJS | CDTYPE_BG, GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2)) {
						roomnum = cdFindFloorRoomYColourFlagsAtPos(&prop->pos, prop->rooms, &spa4, &obj->floorcol, &geoflags);
					}

					if (roomnum <= 0) {
						prop->pos.x = sp5c8.x;
						prop->pos.z = sp5c8.z;

						propDeregisterRooms(prop);
						roomsCopy(sp5b8, prop->rooms);

						roomnum = cdFindFloorRoomYColourFlagsAtPos(&prop->pos, prop->rooms, &spa4, &obj->floorcol, &geoflags);

						projectile->speed.x = 0.0f;
						projectile->speed.z = 0.0f;
					}

					if (roomnum > 0) {
						prop->pos.y = spa4 - sp98 + func0f06a620(obj);

						if (geoflags & GEOFLAG_DIE) {
							obj->hidden |= OBJHFLAG_REAPABLE;
						}
					} else {
						prop->pos.y = sp5c8.y;
					}

					if (projectile->speed.x < 0.1f && projectile->speed.x > -0.1f
							&& projectile->speed.z < 0.1f && projectile->speed.z > -0.1f) {
						projectile->speed.z = 0.0f;
						projectile->speed.x = 0.0f;
					}
				}

				if (stop) {
					objFreeProjectile(obj);
				}

				if (result) {
					func0f069c70(obj, true, true);
				}
			}
		}
	}

	return result;
}

static void doorTick(struct prop *doorprop)
{
	struct doorobj *door = (struct doorobj *)doorprop->obj;
	struct model *model = door->base.model;
	f32 prevfrac = door->frac;
	u32 stack[2];

	// If door should autoclose this tick
	if (door->lastopen60 > 0
			&& door->mode == DOORMODE_IDLE
			&& (door->base.flags & OBJFLAG_DOOR_KEEPOPEN) == 0
			&& door->lastopen60 < g_Vars.lvframe60 - TICKS(door->autoclosetime)) {
		// Check if any sibling is automatic
		struct doorobj *loopdoor = door->sibling;
		bool pass = door->doorflags & DOORFLAG_AUTOMATIC;

		while (loopdoor && loopdoor != door && !pass) {
			pass = loopdoor->doorflags & DOORFLAG_AUTOMATIC;
			loopdoor = loopdoor->sibling;
		}

		if (!pass) {
			// Not automatic
			doorsRequestMode(door, DOORMODE_CLOSING);
		} else if (door->doorflags & DOORFLAG_AUTOMATIC) {
			// Check if any sibling has anything in range
			pass = !doorIsRangeEmpty(door);
			loopdoor = door->sibling;

			while (loopdoor && loopdoor != door && !pass) {
				pass = !doorIsRangeEmpty(loopdoor);
				loopdoor = loopdoor->sibling;
			}

			if (pass) {
				// Something is in range, so keep open
				loopdoor = door->sibling;
				door->lastopen60 = g_Vars.lvframe60;

				while (loopdoor && loopdoor != door) {
					loopdoor->lastopen60 = g_Vars.lvframe60;
					loopdoor = loopdoor->sibling;
				}
			} else {
				doorsRequestMode(door, DOORMODE_CLOSING);
			}
		}
	}

	// If waiting for sibling to close, check for that
	if (door->mode == DOORMODE_WAITING) {
		bool shouldopen = true;
		struct doorobj *loopdoor = door->sibling;

		while (loopdoor && loopdoor != door) {
			if (loopdoor->mode != DOORMODE_IDLE || loopdoor->frac > 0) {
				shouldopen = false;
			}

			loopdoor = loopdoor->sibling;
		}

		if (shouldopen) {
			doorSetMode(door, DOORMODE_OPENING);
		}
	}

	// Update frac
	if (door->lastcalc60 < g_Vars.lvframe60 || g_Vars.lvupdate240 == 0) {
		doorsCalcFrac(door);
	}

	// Consider playing a sound effect
	if (model->filedata->skel == &g_Skel13) {
		f32 soundpoint = door->maxfrac * 0.3f;

		if (door->frac > soundpoint) {
			if (prevfrac <= soundpoint) {
				// frac increased past the soundpoint
				propsnd0f0939f8(NULL, doorprop, SFX_DOOR_8014, -1,
						-1, 0, 0, 12, 0, -1, 0, -1, -1, -1, -1);
			}
		} else {
			if (prevfrac > soundpoint) {
				// frac decreased past the soundpoint
				propsnd0f0939f8(NULL, doorprop, SFX_DOOR_8015, -1,
						-1, 0, 0, 12, 0, -1, 0, -1, -1, -1, -1);
			}
		}
	}
}

struct escastepkeyframe g_EscaStepKeyframesX[] = {
	{ 0,   { -1535.98, -511,    -5258.18 } },
	{ 41,  { -1535.98, -505.76, -5188.43 } },
	{ 149, { -1535.98, -504.79, -5008.75 } },
	{ 698, { -1535.98, -100.91, -4210.86 } },
	{ 759, { -1535.98, -98.89,  -4109.62 } },
	{ 800, { -1535.98, -102,    -4039.06 } },
	{ -1,  { 0,        0,       0        } },
};

struct escastepkeyframe g_EscaStepKeyframesZ[] = {
	{ 0,   { -1932.27, -102,    -3824.58 } },
	{ 41,  { -2002.83, -98.89,  -3824.58 } },
	{ 102, { -2104.07, -100.91, -3824.58 } },
	{ 651, { -2901.96, -504.79, -3824.58 } },
	{ 759, { -3081.64, -505.76, -3824.58 } },
	{ 800, { -3151.39, -511,    -3824.58 } },
	{ -1,  { 0,        0,       0        } },
};

static void doorUpdatePortalIfWindowed(struct prop *doorprop, s32 playercount)
{
	struct doorobj *doorobj = doorprop->door;
	struct modelnode *node;
	bool canhide = true;
	struct model *model = doorprop->obj->model;
	union modelrwdata *rwdata;

	if (doorobj->doorflags & DOORFLAG_WINDOWED) {
		doorobj->fadealpha = glassCalculateOpacity(&doorprop->pos, doorobj->xludist, doorobj->opadist, 0);

		if (doorobj->fadealpha != 255 || doorobj->frac > 0) {
			canhide = false;
		}

		if (model->filedata->skel == &g_SkelWindowedDoor) {
			node = modelGetPart(model->filedata, MODELPART_WINDOWEDDOOR_0001);
			rwdata = modelGetNodeRwData(model, node);

			if (!rwdata->toggle.visible) {
				canhide = false;
			}
		}

		if (playercount >= 2) {
			canhide = false;
		}

		if (canhide) {
			doorDeactivatePortal(doorobj);
		} else {
			doorActivatePortal(doorobj);
		}
	}
}

#define MTX(i) ((Mtxf *)((u32)matrices + i * sizeof(Mtxf)))

static void doorInitMatrices(struct prop *prop)
{
	struct doorobj *door = prop->door;
	struct model *model = door->base.model;
	Mtxf *matrices = model->matrices;

	func0f08c424(door, matrices);
	mtx00015be0(g_Vars.currentplayer->worldtoscreenmtx, matrices);

	if (model->filedata->skel == &g_Skel11) {
		union modelrodata *rodata;
		f32 xrot = M_BADTAU - door->frac * 0.017450513318181f;

		rodata = modelGetPartRodata(model->filedata, 1);
		mtx4LoadXRotation(xrot, MTX(1));
		mtx4SetTranslation(&rodata->position.pos, MTX(1));
		mtx4MultMtx4InPlace(MTX(0), MTX(1));

		rodata = modelGetPartRodata(model->filedata, 2);
		mtx4LoadXRotation(M_BADTAU - xrot, MTX(2));
		mtx4SetTranslation(&rodata->position.pos, MTX(2));
		mtx4MultMtx4InPlace(MTX(0), MTX(2));
	} else if (model->filedata->skel == &g_Skel13) {
		union modelrodata *rodata;
		f32 zrot1 = 0;
		f32 zrot2 = door->frac * 0.017450513318181f;
		f32 limit = door->maxfrac * 0.3f;
		s32 i;

		if (door->frac > limit) {
			zrot1 = ((door->maxfrac * (door->frac - limit)) / (door->maxfrac - limit)) * 0.017450513318181f;
		}

		for (i = 0; i < 6; i++) {
			s32 index1 = (i << 1) + 1;
			s32 index2 = (i << 1) + 2;

			rodata = modelGetPartRodata(model->filedata, index1);
			mtx4LoadZRotation(zrot1, MTX(index1));
			mtx4SetTranslation(&rodata->position.pos, MTX(index1));
			mtx4MultMtx4InPlace(MTX(0), MTX(index1));

			rodata = modelGetPartRodata(model->filedata, index2);
			mtx4LoadZRotation(zrot2, MTX(index2));
			mtx4SetTranslation(&rodata->position.pos, MTX(index2));
			mtx4MultMtx4InPlace(MTX(index1), MTX(index2));
		}
	}
}

static void platformDisplaceProps(struct prop *platform, s16 *propnums, struct coord *prevpos, struct coord *newpos)
{
	struct prop *prop;
	s16 *propnumptr = propnums;

	while (*propnumptr >= 0) {
		prop = &g_Vars.props[*propnumptr];

		if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) {
			struct defaultobj *obj = prop->obj;
			if ((obj->hidden & OBJHFLAG_00020000) == 0) {
				if ((obj->hidden & OBJHFLAG_PROJECTILE) == 0
						|| (obj->projectile->flags & (PROJECTILEFLAG_FALLING | PROJECTILEFLAG_SLIDING))) {
					struct hov *hov = NULL;

					if (obj->type == OBJTYPE_HOVERPROP) {
						struct hoverpropobj *hoverobj = (struct hoverpropobj *)obj;
						hov = &hoverobj->hov;
					} else if (obj->type == OBJTYPE_HOVERBIKE) {
						struct hoverbikeobj *bike = (struct hoverbikeobj *)obj;
						hov = &bike->hov;
					}

					if (hov) {
						hov->unk30 += newpos->y - prevpos->y;
						hov->ground += newpos->y - prevpos->y;
					}

					prop->pos.x += newpos->x - prevpos->x;
					prop->pos.y += newpos->y - prevpos->y;
					prop->pos.z += newpos->z - prevpos->z;

					propDeregisterRooms(prop);

					func0f065e74(&platform->pos, platform->rooms, &prop->pos, prop->rooms);
					func0f069c70(obj, true, true);
				}
			}
		} else if (prop->type == PROPTYPE_CHR) {
			struct chrdata *chr = prop->chr;
			s32 nodetype;

			if (chr->fallspeed.y == 0.0f) {
				chr->ground += newpos->y - prevpos->y;
				chr->manground += newpos->y - prevpos->y;
				chr->sumground = chr->manground * (PAL ? 8.417509f : 9.999998f);

				prop->pos.x += newpos->x - prevpos->x;
				prop->pos.y += newpos->y - prevpos->y;
				prop->pos.z += newpos->z - prevpos->z;

				propDeregisterRooms(prop);

				func0f065e74(&platform->pos, platform->rooms, &prop->pos, prop->rooms);
				chr0f0220ac(chr);
				modelSetRootPosition(chr->model, &prop->pos);

				nodetype = chr->model->filedata->rootnode->type;

				if ((nodetype & 0xff) == MODELNODETYPE_CHRINFO) {
					struct modelrwdata_chrinfo *rwdata = modelGetNodeRwData(chr->model, chr->model->filedata->rootnode);
					rwdata->ground += newpos->y - prevpos->y;
				}
			}
		} else if (prop->type == PROPTYPE_PLAYER) {
			struct defaultobj *platformobj = platform->obj;
			struct coord sp8c;
			s32 playernum = playermgrGetPlayerNumByProp(prop);
			s32 prevplayernum;

			if (platformobj->type == OBJTYPE_LIFT) {
				if (g_Vars.players[playernum]->lift == platform && g_Vars.players[playernum]->bondmovemode == MOVEMODE_WALK) {
					if (platformobj->flags & OBJFLAG_20000000) {
						g_Vars.players[playernum]->bondextrapos.x += newpos->x - prevpos->x;
						g_Vars.players[playernum]->bondextrapos.z += newpos->z - prevpos->z;

						sp8c.x = newpos->x - prevpos->x;
						sp8c.y = 0.0f;
						sp8c.z = newpos->z - prevpos->z;

						prevplayernum = g_Vars.currentplayernum;

						setCurrentPlayerNum(playernum);
						bwalk0f0c63bc(&sp8c, 1, CDTYPE_BG);
						playerUpdatePerimInfo();
						bmoveUpdateRooms(g_Vars.players[playernum]);
						setCurrentPlayerNum(prevplayernum);
					}

					if (g_Vars.players[playernum]->inlift && !g_Vars.players[playernum]->onladder && !g_Vars.players[playernum]->isfalling) {
						struct coord sp78;
						s16 sp68[8];
						f32 ydist = newpos->y - prevpos->y;

						if (ydist != 0.0f) {
							g_Vars.players[playernum]->bondextrapos.y += ydist;

							prevplayernum = g_Vars.currentplayernum;

							setCurrentPlayerNum(playernum);

							g_Vars.players[playernum]->vv_ground += ydist;

							if (ydist > 0.0f || (platformobj->flags & OBJFLAG_80000000) == 0) {
								sp78.x = prop->pos.x;
								sp78.y = prop->pos.y + ydist;
								sp78.z = prop->pos.z;

								func0f065e74(&prop->pos, prop->rooms, &sp78, sp68);

								prop->pos = sp78;

								propDeregisterRooms(prop);
								roomsCopy(sp68, prop->rooms);

								g_Vars.players[playernum]->vv_manground += ydist;
								g_Vars.players[playernum]->sumground = g_Vars.players[playernum]->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);
							} else if (bwalkTryMoveUpwards(ydist) == CDRESULT_NOCOLLISION) {
								g_Vars.players[playernum]->vv_manground += ydist;
								g_Vars.players[playernum]->sumground = g_Vars.players[playernum]->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);
							}

							playerUpdatePerimInfo();
							bmoveUpdateRooms(g_Vars.players[playernum]);
							setCurrentPlayerNum(prevplayernum);

							if (g_Vars.players[playernum]->walkinitmove) {
								g_Vars.players[playernum]->walkinitstart.y += ydist;
							}
						}
					}
				}
			}
		}

		propnumptr++;
	}
}

void liftTick(struct prop *prop)
{
	struct liftobj *lift = (struct liftobj *)prop->obj;
	struct defaultobj *obj = prop->obj;
	struct doorobj *door;
	struct pad *padcur;
	struct pad *padaim;
	f32 segdist;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	struct coord curcentre;
	f32 frac;
	s32 move;
	struct coord newpos;
	s16 newrooms[8];
	struct coord prevpos;
	f32 prevdist;
	s16 propnums[256];
	s32 stop;

	lift->prevpos = prop->pos;

	if (lift->levelcur != lift->levelaim) {
		// Lift is not at the desired level. So try to move, but not if the lift
		// is disabled or if the door needs to be closed first.
		move = true;

		if (obj->flags & OBJFLAG_DEACTIVATED) {
			move = false;
		} else if (lift->doors[lift->levelcur] && !doorIsClosed(lift->doors[lift->levelcur])) {
			doorsRequestMode(lift->doors[lift->levelcur], DOORMODE_CLOSING);
			move = false;
		}

		if (move) {
			prevpos = prop->pos;

			cdGetPropsOnPlatform(prop, propnums, ARRAYCOUNT(propnums));

			if (lift->dist == 0 && lift->speed == 0) {
				doorPlayOpeningSound(lift->soundtype, lift->base.prop);

				if (obj->flags & OBJFLAG_LIFT_TRIGGERDISABLE) {
					obj->flags &= ~OBJFLAG_LIFT_TRIGGERDISABLE;
					obj->flags |= OBJFLAG_DEACTIVATED;
				}
			}

			padGetCentre(lift->pads[lift->levelcur], &curcentre);
			padcur = &g_Pads[lift->pads[lift->levelcur]];
			padaim = &g_Pads[lift->pads[lift->levelaim]];

			xdiff = padaim->pos.f[0] - padcur->pos.f[0];
			ydiff = padaim->pos.f[1] - padcur->pos.f[1];
			zdiff = padaim->pos.f[2] - padcur->pos.f[2];

			segdist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

			prevdist = lift->dist;

			applySpeed(&lift->dist, segdist, &lift->speed, lift->accel, lift->accel, lift->maxspeed);

			// If arriving at the destination, set the distance explicitly
			if (lift->speed < 1 && lift->speed > -1) {
				if (prevdist < segdist && lift->dist >= segdist) {
					lift->dist = segdist;
				} else if (prevdist > 0 && lift->dist <= 0) {
					lift->dist = 0;
				}
			}

			frac = segdist == 0 ? 0 : lift->dist / segdist;

			newpos.x = curcentre.f[0] + xdiff * frac;
			newpos.y = curcentre.f[1] + ydiff * frac;
			newpos.z = curcentre.f[2] + zdiff * frac;

			if (segdist == lift->dist) {
				lift->dist = 0;
				lift->speed = 0;
				lift->levelcur = lift->levelaim;

				doorPlayOpenedSound(lift->soundtype, lift->base.prop);

				if (obj->flags & OBJFLAG_LIFT_TRIGGERDISABLE) {
					obj->flags &= ~OBJFLAG_LIFT_TRIGGERDISABLE;
					obj->flags |= OBJFLAG_DEACTIVATED;
				}

				door = lift->doors[lift->levelcur];

				if (door && door->keyflags == 0) {
					doorsRequestMode(door, DOORMODE_OPENING);
				}
			}

			func0f065e74(&prop->pos, prop->rooms, &newpos, newrooms);

			prop->pos = newpos;

			propDeregisterRooms(prop);
			roomsCopy(newrooms, prop->rooms);
			func0f069c70(obj, true, true);
			liftUpdateTiles(lift, lift->levelcur == lift->levelaim);
			platformDisplaceProps(prop, propnums, &prevpos, &prop->pos);
		}
	} else {
		// Lift is at the aim stop
		door = lift->doors[lift->levelcur];

		if (!door || (doorIsClosed(door) && door->keyflags == 0)) {
			// Find next stop
			stop = lift->levelaim;

			do {
				stop = (stop + 1) % 4;
			} while (lift->pads[stop] < 0);

			liftGoToStop(lift, stop);
		}
	}
}

void escastepTick(struct prop *prop)
{
	struct escalatorobj *step = (struct escalatorobj *)prop->obj;
	struct defaultobj *obj = prop->obj;
	struct coord newpos;
	struct escastepkeyframe *keyframes;
	s32 i;
	f32 mult;
	struct coord oldpos;
	s16 propnums[256];
	bool resetting;

	resetting = false;

	step->frame += g_Vars.lvupdate60;

	keyframes = (obj->flags & OBJFLAG_ESCSTEP_ZALIGNED) ? g_EscaStepKeyframesZ : g_EscaStepKeyframesX;

	for (i = 0; true; i++) {
		if (keyframes[i + 1].frame == -1) {
			step->frame -= keyframes[i].frame;
			i = -1;
			resetting = true;
		} else if (step->frame < keyframes[i + 1].frame) {
			mult = (f32)(step->frame - keyframes[i].frame) / (f32)(keyframes[i + 1].frame - keyframes[i].frame);

			newpos.x = keyframes[i].pos.x + (keyframes[i + 1].pos.x - keyframes[i].pos.x) * mult;
			newpos.y = keyframes[i].pos.y + (keyframes[i + 1].pos.y - keyframes[i].pos.y) * mult;
			newpos.z = keyframes[i].pos.z + (keyframes[i + 1].pos.z - keyframes[i].pos.z) * mult;
			break;
		} else {
			// empty
		}
	}

	if (!resetting) {
		oldpos = prop->pos;

		cdGetPropsOnPlatform(prop, propnums, ARRAYCOUNT(propnums));

		step->prevpos = prop->pos;
	} else {
		step->prevpos.x = newpos.f[0];
		step->prevpos.y = newpos.f[1];
		step->prevpos.z = newpos.f[2];
	}

	prop->pos = newpos;

	if ((obj->flags & OBJFLAG_IGNOREFLOORCOLOUR) == 0) {
		cdFindFloorYColourTypeAtPos(&prop->pos, prop->rooms, &obj->floorcol, 0);
	}

	func0f069c70(obj, true, true);

	if (!resetting) {
		platformDisplaceProps(prop, propnums, &oldpos, &prop->pos);
	}
}

static void cctvTick(struct prop *camprop)
{
	struct cctvobj *camera = (struct cctvobj *)camprop->obj;
	struct defaultobj *obj = camprop->obj;
	f32 yaw;
	struct prop *playerprop;
	f32 xdist;
	f32 ydist;
	f32 zdist;
	bool canseeplayer = true;

	// If playing in coop mode, cycle between players in alternating frames
	if (g_Vars.coopplayernum >= 0) {
		if (g_Vars.lvframenum & 1) {
			playerprop = g_Vars.bond->prop;
		} else {
			playerprop = g_Vars.coop->prop;
		}
	} else {
		playerprop = g_Vars.bond->prop;
	}

	// Check distance
	xdist = playerprop->pos.x - camprop->pos.x;
	ydist = playerprop->pos.y - camprop->pos.y;
	zdist = playerprop->pos.z - camprop->pos.z;

	yaw = camera->toleft ? camera->yleft : camera->yright;

	if (camera->maxdist > 0) {
		if (xdist * xdist + ydist * ydist + zdist * zdist > camera->maxdist * camera->maxdist) {
			canseeplayer = false;
		}
	}

	if (g_Vars.bondvisible == false
			|| (obj->flags & OBJFLAG_CAMERA_DISABLED)
			|| (playerprop->chr->hidden & CHRHFLAG_CLOAKED)) {
		canseeplayer = false;
	}

	// Check horizontal angle
	if (canseeplayer) {
		f32 angle = atan2f(xdist, zdist);
		f32 yrot = camera->yrot;
		f32 finalangle;

		if (yrot < 0) {
			yrot += M_BADTAU;
		} else if (yrot >= M_BADTAU) {
			yrot -= M_BADTAU;
		}

		yrot += camera->yzero;

		if (yrot >= M_BADTAU) {
			yrot -= M_BADTAU;
		}

		finalangle = angle - yrot;

		if (angle < yrot) {
			finalangle += M_BADTAU;
		}

		finalangle -= M_BADPI;

		if (finalangle < 0) {
			finalangle += M_BADTAU;
		}

		if (finalangle > M_BADPI) {
			finalangle -= M_BADTAU;
		}

		if (finalangle > 0.7852731347084f || finalangle < -0.7852731347084f) {
			canseeplayer = false;
		}
	}

	// Check vertical angle
	if (canseeplayer) {
		f32 angle = atan2f(ydist, sqrtf(xdist * xdist + zdist * zdist));
		f32 finalangle = angle - camera->xzero;

		if (angle < camera->xzero) {
			finalangle = angle - camera->xzero + M_BADTAU;
		}

		if (finalangle > M_BADTAU) {
			finalangle -= M_BADTAU;
		}

		if (finalangle > M_BADPI) {
			finalangle -= M_BADTAU;
		}

		if (finalangle);

		if (finalangle > 0.7852731347084f || finalangle < -0.7852731347084f) {
			canseeplayer = false;
		}
	}

	// Check line of sight
	if (canseeplayer) {
		playerSetPerimEnabled(playerprop, false);

		if (!cdTestLos05(&camprop->pos, camprop->rooms, &playerprop->pos, playerprop->rooms,
					CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_CHRS | CDTYPE_PATHBLOCKER | CDTYPE_BG | CDTYPE_AIOPAQUE,
					GEOFLAG_BLOCK_SIGHT)) {
			canseeplayer = false;
		}

		playerSetPerimEnabled(playerprop, true);
	}

	if (canseeplayer) {
		obj->flags |= OBJFLAG_CAMERA_BONDINVIEW;
		camera->seebondtime60 += g_Vars.lvupdate60;

		if (g_Vars.coopplayernum >= 0) {
			camera->seebondtime60 += g_Vars.lvupdate60;
		}

		if (camera->seebondtime60 >= (s32)(TICKS(300) * g_CctvWaitScale)) {
			alarmActivate();
			camera->seebondtime60 = 0;
		}
	} else {
		obj->flags &= ~OBJFLAG_CAMERA_BONDINVIEW;
	}

	// Update yaw
	if (camera->yrot < yaw) {
		f32 tmp = camera->yspeed * camera->yspeed * 764.06536865234f;

		if (camera->yrot >= yaw - tmp) {
			camera->yspeed -= 0.00065439427271485f * g_Vars.lvupdate60freal;

			if (camera->yspeed < 0.00065439427271485f) {
				camera->yspeed = 0.00065439427271485f;
			}
		} else if (camera->yspeed < camera->ymaxspeed) {
			f32 newspeed = camera->yspeed + 0.00065439427271485f * g_Vars.lvupdate60freal;

			if (newspeed > camera->ymaxspeed) {
				newspeed = camera->ymaxspeed;
			}

			if (camera->yrot < yaw - newspeed * newspeed * 764.06536865234f) {
				camera->yspeed = newspeed;
			}
		}

		camera->yrot += camera->yspeed * g_Vars.lvupdate60freal;

		if (camera->yrot >= yaw) {
			camera->yrot = yaw;
			camera->toleft = false;
			camera->yspeed = 0;
		}
	} else {
		f32 tmp = camera->yspeed * camera->yspeed * 764.06536865234f;

		if (camera->yrot <= yaw + tmp) {
			camera->yspeed -= 0.00065439427271485f * g_Vars.lvupdate60freal;

			if (camera->yspeed < 0.00065439427271485f) {
				camera->yspeed = 0.00065439427271485f;
			}
		} else if (camera->yspeed < camera->ymaxspeed) {
			f32 newspeed = camera->yspeed + 0.00065439427271485f * g_Vars.lvupdate60freal;

			if (newspeed > camera->ymaxspeed) {
				newspeed = camera->ymaxspeed;
			}

			if (camera->yrot > yaw + newspeed * newspeed * 764.06536865234f) {
				camera->yspeed = newspeed;
			}
		}

		camera->yrot -= camera->yspeed * g_Vars.lvupdate60freal;

		if (camera->yrot <= yaw) {
			camera->yrot = yaw;
			camera->toleft = true;
			camera->yspeed = 0;
		}
	}
}

static void cctvInitMatrices(struct prop *prop, Mtxf *mtx)
{
	struct cctvobj *cctv = (struct cctvobj *)prop->obj;
	struct model *model = cctv->base.model;
	Mtxf *matrices = model->matrices;
	union modelrodata *rodata = modelGetPartRodata(model->filedata, MODELPART_CCTV_CASING);
	struct coord sp64;
	Mtxf sp24;
	f32 yrot = cctv->yrot;

	if (yrot < 0) {
		yrot += M_BADTAU;
	} else if (yrot >= M_BADTAU) {
		yrot -= M_BADTAU;
	}

	mtx4LoadYRotation(yrot, &sp24);
	mtx4MultMtx4(&sp24, &cctv->camrotm, &matrices[1]);

	sp64.x = rodata->position.pos.x;
	sp64.y = rodata->position.pos.y;
	sp64.z = rodata->position.pos.z;

	mtx4TransformVecInPlace(mtx, &sp64);
	mtx4SetTranslation(&sp64, &matrices[1]);
	mtx00015be0(g_Vars.currentplayer->worldtoscreenmtx, &matrices[1]);
}

static void fanTick(struct prop *prop)
{
	struct defaultobj *obj = (struct defaultobj *)prop->obj;
	struct fanobj *fan = (struct fanobj *)prop->obj;

	// If activated, toggle the power state
	if (obj->hidden & (OBJHFLAG_ACTIVATED_BY_BOND | OBJHFLAG_ACTIVATED_BY_COOP)) {
		if (fan->on == true) {
			fan->on = false;
			obj->hidden &= ~(OBJHFLAG_ACTIVATED_BY_BOND | OBJHFLAG_ACTIVATED_BY_COOP);
		} else {
			fan->on = true;
			obj->hidden &= ~(OBJHFLAG_ACTIVATED_BY_BOND | OBJHFLAG_ACTIVATED_BY_COOP);
		}
	}

	// Adjust fan speed
	if (fan->on == true) {
		// Accelerating
		fan->yspeed += fan->yaccel * g_Vars.lvupdate60freal;

		if (fan->yspeed > fan->ymaxspeed) {
			fan->yspeed = fan->ymaxspeed;
		}
	} else if (fan->yspeed > 0) {
		// Decelerating
		s32 i;

		for (i = 0; i < g_Vars.lvupdate240; i++) {
			fan->yspeed -= fan->yaccel * 0.2f;
		}

		if (fan->yspeed <= fan->ymaxspeed * 0.01f) {
			fan->yspeed = 0;
		}
	}

	// Rotate
	if (fan->yspeed > 0) {
		fan->yrot += fan->yspeed * g_Vars.lvupdate60freal;

		while (fan->yrot >= 1.5705462694168f) { // almost BADDEG2RAD(90)
			fan->yrot -= 1.5705462694168f;
		}

		fan->yrotprev = fan->yrot;
	}
}

static void fanUpdateModel(struct prop *prop)
{
	struct fanobj *fan = (struct fanobj *) prop->obj;
	Mtxf sp6c;
	f32 sp48[3][3];
	f32 sp24[3][3];
	f32 angle = fan->yspeed * g_Vars.lvupdate60freal;

	while (angle >= M_BADTAU) {
		angle -= M_BADTAU;
	}

	mtx4LoadYRotation(angle, &sp6c);
	mtx4ToMtx3(&sp6c, sp48);
	mtx00016140(fan->base.realrot, sp48, sp24);
	mtx3Copy(sp24, fan->base.realrot);
}

static void autogunTick(struct prop *prop)
{
	struct autogunobj *autogun;
	struct defaultobj *obj;
	f32 goalyrot;
	f32 goalxrot;
	f32 f0;
	f32 maxspeed;
	f32 xdist;
	f32 ydist;
	f32 zdist;
	f32 sqdist;
	f32 dist;
	f32 horizdist;
	bool awake;
	bool spinup;
	bool insight;
	f32 limitangle;
	struct prop *target;
	s32 ownerplayernum;
	f32 f2;
	f32 f12;
	s32 numchrs;
	struct chrdata *chr;
	s32 i;
	f32 targetangleh;
	f32 targetanglev;
	f32 relangleh;
	bool track;

	autogun = (struct autogunobj *)prop->obj;
	obj = prop->obj;
	target = NULL;
	awake = false;
	spinup = false;
	insight = false;
	limitangle = 0.0f;

	// Malfunctioning mode 1: The gun looks around continuously in random
	// directions on both axis without spinning the barrel.
	if (obj->flags2 & OBJFLAG2_AUTOGUN_MALFUNCTIONING1) {
		if (obj->flags2 & OBJFLAG2_AUTOGUN_40000000) {
			autogun->xzero = autogun->xrot;
			autogun->yzero = autogun->yrot;
		} else if (autogun->yrot == autogun->yzero && autogun->xrot == autogun->xzero) {
			autogun->xzero = (RANDOMFRAC() * 39.0f + 1.0f) * 0.017450513f;
			autogun->yzero = RANDOMFRAC() * M_BADTAU;
		}

		applyRotation(&autogun->yrot, autogun->yzero, &autogun->yspeed, PALUPF(0.00001163367596746f), PALUPF(0.00001163367596746f), PALUPF(0.00069802056532353f));
		applyRotation(&autogun->xrot, autogun->xzero, &autogun->xspeed, PALUPF(0.0000058168379837298f), PALUPF(0.0000058168379837298f), PALUPF(0.00034901028266177f));
		return;
	}

	// Malfunctioning mode 2: The gun looks around left/right continuously
	// and spins the barrel based on its angle.
	if (obj->flags2 & OBJFLAG2_AUTOGUN_MALFUNCTIONING2) {
		spinup = true;

		if (obj->flags2 & OBJFLAG2_AUTOGUN_40000000) {
			autogun->xzero = autogun->xrot;
			autogun->yzero = autogun->yrot;
		} else if (autogun->yrot == autogun->yzero) {
			autogun->yzero = RANDOMFRAC() * M_BADTAU;
		}

		applyRotation(&autogun->yrot, autogun->yzero, &autogun->yspeed, PALUPF(0.00001163367596746f), PALUPF(0.00001163367596746f), PALUPF(0.00069802056532353f));
		applyRotation(&autogun->xrot, autogun->xzero, &autogun->xspeed, PALUPF(0.0000058168379837298f), PALUPF(0.0000058168379837298f), PALUPF(0.00034901028266177f));

		maxspeed = cosf(autogun->yrot);

		if (maxspeed > 0.0f) {
			maxspeed = 0.02512874f * maxspeed;
		} else {
			maxspeed = 0.000001f;
		}

		// spinup is always true here, so the first branch is unconditional and
		// the else branch is optimised out. The spinup check and else branch
		// must be here for a match, so it was likely copied from later in the
		// function.
		if (spinup) {
			autogun->barrelspeed += 0.009971722f * g_Vars.lvupdate60freal;

			if (autogun->barrelspeed > maxspeed) {
				autogun->barrelspeed = maxspeed;
			}
		} else if (autogun->barrelspeed > 0.0f) {
			for (i = 0; i < g_Vars.lvupdate60; i++) {
				autogun->barrelspeed *= 0.99f;
			}

			if (autogun->barrelspeed <= 0.0001f) {
				autogun->barrelspeed = 0.0f;
			}
		}

		if (autogun->barrelspeed > 0.0f) {
			autogun->barrelrot += autogun->barrelspeed * g_Vars.lvupdate60freal;

			while (autogun->barrelrot >= M_BADTAU) {
				autogun->barrelrot -= M_BADTAU;
			}
		}

		return;
	}

	// Regular behaviour
	if (autogun->ammoquantity == 0) {
		// Don't set target
	} else if (autogun->target) {
		target = autogun->target;
	} else {
		// Find new target
		if (frIsInTraining()) {
			// Laptop gun in firing range
			target = frChooseAutogunTarget(&prop->pos);
			if (1);
		} else if (autogun->targetteam != 0) {
			// Autogun (solo or MP) configured to attack specific teams
			if (g_Vars.normmplayerisrunning) {
				numchrs = g_MpNumChrs;
			} else {
				numchrs = g_NumChrSlots;
			}

			while (true) {
				autogun->nextchrtest++;

				if (autogun->nextchrtest >= numchrs) {
					autogun->nextchrtest = -1;
					break;
				}

				if (g_Vars.normmplayerisrunning) {
					ownerplayernum = (obj->hidden & 0xf0000000) >> 28;

					if (autogun->nextchrtest == ownerplayernum) {
						continue;
					}

					chr = g_MpAllChrPtrs[autogun->nextchrtest];

					if (!chr->prop) {
						continue;
					}

					if (!chr->model) {
						continue;
					}

					if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) && (chr->team & autogun->targetteam) == 0) {
						continue;
					}
				} else {
					chr = &g_ChrSlots[autogun->nextchrtest];

					if (!chr->prop) {
						continue;
					}

					if ((chr->team & autogun->targetteam) == 0) {
						continue;
					}

					if ((!chr->model || (chr->prop->flags & PROPFLAG_ENABLED) == 0) && chr->prop->type != PROPTYPE_PLAYER) {
						continue;
					}
				}

				if ((chr->chrflags & CHRCFLAG_HIDDEN) == 0
						&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
						&& !chrIsDead(chr)) {
					target = chr->prop;
					break;
				}

				if (1);
			}
		} else {
			// Not configured for teams, so target a player
			if (g_Vars.coopplayernum >= 0) {
				if (g_Vars.lvframenum & 1) {
					target = g_Vars.bond->prop;
				} else {
					target = g_Vars.coop->prop;
				}
			} else {
				target = g_Vars.bond->prop;
			}
		}
	}

	if (target) {
		if (target->chr == NULL) {
			target = NULL;
		} else if ((target->type & (PROPTYPE_CHR | PROPTYPE_PLAYER)) == 0 && !frIsInTraining()) {
			target = NULL;
		}
	}

	goalyrot = autogun->yzero;
	goalxrot = autogun->xzero;

	if (target) {
		xdist = target->pos.f[0] - prop->pos.f[0];
		ydist = target->pos.f[1] - prop->pos.f[1];
		zdist = target->pos.f[2] - prop->pos.f[2];

		if (target->type == PROPTYPE_PLAYER) {
			ydist -= 20.0f;
		}

		if (ydist);

		sqdist = xdist * xdist + zdist * zdist;
		dist = sqrtf(sqdist);
		horizdist = dist;

		if (obj->flags & OBJFLAG_08000000) {
			sqdist += ydist * ydist;
			dist = sqrtf(sqdist);
		}

		limitangle = chrGetAimLimitAngle(sqdist);

		if (obj->flags && obj->flags);

		if (dist <= autogun->aimdist) {
			// Target is in range
			targetangleh = atan2f(xdist, zdist);
			targetanglev = atan2f(ydist, horizdist);

			if ((obj->flags & OBJFLAG_AUTOGUN_DAMAGED) || (obj->flags & OBJFLAG_AUTOGUN_SEENTARGET)) {
				awake = true;
			} else {
				f12 = targetangleh - autogun->yrot;

				if (f12 < 0.0f) {
					f12 += M_BADTAU;
				}

				if (f12 > M_BADPI) {
					f12 -= M_BADTAU;
				}

				f2 = targetanglev - autogun->xrot;

				if (f2 < 0.0f) {
					f2 += M_BADTAU;
				}

				if (f2 > M_BADPI) {
					f2 -= M_BADTAU;
				}

				if (f12 < 1.221536f && f12 > -1.221536f) {
					awake = true;
				}
			}

			if (awake) {
				relangleh = targetangleh - autogun->yzero;
				track = true;

				if (relangleh < -M_PI) {
					relangleh += M_BADTAU;
				} else if (relangleh >= M_PI) {
					relangleh -= M_BADTAU;
				}

				// Decide if target can be tracked
				if (target->type == PROPTYPE_PLAYER) {
					if (!g_Vars.bondvisible
							|| g_Vars.players[playermgrGetPlayerNumByProp(target)]->isdead
							|| (target->chr->chrflags & CHRCFLAG_HIDDEN)
							|| (target->chr->hidden & CHRHFLAG_CLOAKED)) {
						track = false;
					}
				} else if (target->type == PROPTYPE_CHR) {
					struct chrdata *chr = target->chr;

					if (chr == NULL
							|| (chr->chrflags & CHRCFLAG_HIDDEN)
							|| (chr->hidden & CHRHFLAG_CLOAKED)
							|| (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE)
							|| chrIsDead(chr)
							|| chr->actiontype == ACT_DRUGGEDCOMINGUP
							|| chr->actiontype == ACT_DRUGGEDDROP
							|| chr->actiontype == ACT_DRUGGEDKO) {
						track = false;
					}
				} else if (target->type == PROPTYPE_OBJ) {
					struct defaultobj *obj = target->obj;

					if (obj && obj->modelnum == MODEL_TARGET) {
						if (!frIsTargetFacingPos(target, &prop->pos)) {
							track = false;
						}
					} else {
						track = false;
					}
				}

				propSetPerimEnabled(prop, false);
				propSetPerimEnabled(target, false);

				if (relangleh <= autogun->ymaxleft
						&& relangleh >= autogun->ymaxright
						&& track
						&& cdTestLos05(&prop->pos, prop->rooms, &target->pos, target->rooms, CDTYPE_ALL, GEOFLAG_BLOCK_SIGHT)) {
					// Target is in sight
					obj->flags |= OBJFLAG_AUTOGUN_SEENTARGET;
					insight = true;
					goalxrot = targetanglev;
					goalyrot = targetangleh;

					if (autogun->target == NULL) {
						autogun->target = target;
					}
				} else if (autogun->lastseebond60 >= 0 && autogun->lastseebond60 > g_Vars.lvframe60 - TICKS(120)) {
					// Target recently lost
					goalyrot = autogun->yrot;
					goalxrot = autogun->xrot;
				} else {
					awake = false;
				}

				propSetPerimEnabled(prop, true);
				propSetPerimEnabled(target, true);
			}
		}
	}

	if (!awake) {
		autogun->target = NULL;
	}

	// The turret swivels left and right while firing
	if (autogun->firing) {
		goalyrot += limitangle * 0.8f * sinf((g_Vars.lvframe60 % TICKS(120)) * PALUPF(0.05235154f));

		if (goalyrot < 0.0f) {
			goalyrot += M_BADTAU;
		}

		if (goalyrot >= M_BADTAU) {
			goalyrot -= M_BADTAU;
		}
	}

	f0 = goalyrot - autogun->yzero;

	if (f0 < -M_PI) {
		f0 += M_BADTAU;
	} else if (f0 >= M_PI) {
		f0 -= M_BADTAU;
	}

	if (f0 > autogun->ymaxleft) {
		goalyrot = autogun->yzero + autogun->ymaxleft;
	} else if (f0 < autogun->ymaxright) {
		goalyrot = autogun->yzero + autogun->ymaxright;
	}

	if (goalyrot < 0.0f) {
		goalyrot += M_BADTAU;
	}

	if (goalyrot >= M_BADTAU) {
		goalyrot -= M_BADTAU;
	}

	applyRotation(&autogun->yrot, goalyrot, &autogun->yspeed, PALUPF(0.00087252567755058f), PALUPF(0.00087252567755058f), autogun->maxspeed);
	applyRotation(&autogun->xrot, goalxrot, &autogun->xspeed, PALUPF(0.00087252567755058f), PALUPF(0.00087252567755058f), autogun->maxspeed);

	f12 = goalyrot - autogun->yrot;

	if (f12 < 0.0f) {
		f12 += M_BADTAU;
	}

	if (f12 > M_BADPI) {
		f12 -= M_BADTAU;
	}

	f2 = goalxrot - autogun->xrot;

	if (f2 < 0.0f) {
		f2 += M_BADTAU;
	}

	if (f2 > M_BADPI) {
		f2 -= M_BADTAU;
	}

	autogun->firing = false;

	if (awake) {
		if (f12 < limitangle && -limitangle < f12 && f2 < limitangle && -limitangle < f2) {
			autogun->firing = true;
			spinup = true;

			if (insight) {
				autogun->lastseebond60 = g_Vars.lvframe60;
				autogun->lastaimbond60 = g_Vars.lvframe60;
			}
		} else {
			f32 f0 = 2.0f * limitangle;
			u32 stack[2];

			if (f12 < f0 && -f0 < f12 && f2 < f0 && -f0 < f2) {
				autogun->firing = true;
				spinup = true;

				if (insight) {
					autogun->lastseebond60 = g_Vars.lvframe60;
				}
			} else {
				if (autogun->lastseebond60 >= 0 && autogun->lastseebond60 > g_Vars.lvframe60 - TICKS(120)) {
					autogun->firing = true;
					spinup = true;
				}
			}
		}
	}

	// Increase or decrease the barrel speed and apply the rotation
	if (spinup) {
		autogun->barrelspeed += 0.009971722f * g_Vars.lvupdate60freal;

		if (autogun->barrelspeed > 0.5983033f) {
			autogun->barrelspeed = 0.5983033f;
		}
	} else if (autogun->barrelspeed > 0.0f) {
		for (i = 0; i < g_Vars.lvupdate60; i++) {
			autogun->barrelspeed *= 0.99f;
		}

		if (autogun->barrelspeed <= 0.0001f) {
			autogun->barrelspeed = 0.0f;
		}
	}

	if (autogun->barrelspeed > 0.0f) {
		autogun->barrelrot += autogun->barrelspeed * g_Vars.lvupdate60freal;

		while (autogun->barrelrot >= M_BADTAU) {
			autogun->barrelrot -= M_BADTAU;
		}
	}
}

static void autogunInitMatrices(struct prop *prop, Mtxf *mtx)
{
	struct autogunobj *autogun = (struct autogunobj *)prop->obj;
	struct model *model = autogun->base.model;
	Mtxf *matrices = model->matrices;
	union modelrodata *rodata;
	struct coord sp4c;
	f32 yrot = autogun->yrot + 1.5705462694168f;
	f32 xrot = -autogun->xrot;
	Mtxf *tmp;
	struct modelnode *node2;
	struct modelnode *node3;
	struct modelnode *node4;
	struct modelnode *node6;

	if (yrot >= M_BADTAU) {
		yrot -= M_BADTAU;
	}

	rodata = modelGetPartRodata(model->filedata, MODELPART_AUTOGUN_0001);

	sp4c = rodata->position.pos;

	mtx4TransformVecInPlace(mtx, &sp4c);
	mtx4LoadYRotation(yrot, &matrices[1]);
	mtx4SetTranslation(&sp4c, &matrices[1]);
	mtx00015f04(autogun->base.model->scale, &matrices[1]);
	mtx00015be0(g_Vars.currentplayer->worldtoscreenmtx, &matrices[1]);

	node2 = modelGetPart(model->filedata, MODELPART_AUTOGUN_0002);
	rodata = node2->rodata;
	mtx4LoadZRotation(xrot, &matrices[2]);
	mtx4SetTranslation(&rodata->position.pos, &matrices[2]);
	mtx00015be0(&matrices[1], &matrices[2]);

	tmp = model0001a5cc(model, node2, 0x100);

	if (tmp != NULL) {
		mtx4LoadZRotation(xrot * 0.5f, tmp);
		mtx4SetTranslation(&rodata->position.pos, tmp);
		mtx00015be0(&matrices[1], tmp);
	}

	node3 = modelGetPart(model->filedata, MODELPART_AUTOGUN_0003);

	if (node3 != NULL) {
		tmp = model0001a5cc(model, node3, 0);
		rodata = node3->rodata;
		mtx4LoadXRotation(autogun->barrelrot, tmp);
		mtx4SetTranslation(&rodata->position.pos, tmp);
		mtx00015be0(&matrices[2], tmp);
	}

	node4 = modelGetPart(model->filedata, MODELPART_AUTOGUN_0004);

	if (node4 != NULL) {
		tmp = model0001a5cc(model, node4, 0);
		rodata = node4->rodata;
		mtx4LoadTranslation(&rodata->position.pos, tmp);
		mtx00015be0(&matrices[2], tmp);
	}

	node6 = modelGetPart(model->filedata, MODELPART_AUTOGUN_0006);

	if (node6 != NULL) {
		tmp = model0001a5cc(model, node6, 0);
		rodata = node6->rodata;
		mtx4LoadXRotation(autogun->barrelrot, tmp);
		mtx4SetTranslation(&rodata->position.pos, tmp);
		mtx00015be0(&matrices[2], tmp);
	}
}

static void autogunTickShoot(struct prop *autogunprop)
{
	if (!g_LvIsPaused) {
		struct autogunobj *autogun = (struct autogunobj *) autogunprop->obj;
		struct defaultobj *obj = autogunprop->obj;
		bool fireleft = false;
		bool fireright = false;
		struct model *model = obj->model;
		struct modelnode *node1;
		struct modelnode *node2;
		struct prop *hitprop;
		bool friendly = false;

		if (autogun->firing && (obj->flags & OBJFLAG_DEACTIVATED) == 0) {
			autogun->firecount++;

			fireleft = (autogun->firecount % 2) == 0;

			if (modelGetPart(model->filedata, MODELPART_AUTOGUN_FLASHLEFT)) {
				fireright = (autogun->firecount % 2) == 1;
			}

			if (fireleft || fireright) {
				struct coord gunpos;
				s16 gunrooms[8];
				struct coord dir;
				bool missed = false;
				struct coord hitpos;
				s16 hitrooms[8];
				bool makebeam = (autogun->firecount % 4) == 0;
				struct prop *targetprop = autogun->target;
				struct modelnode *flashnode;
				struct modelnode *posnode = NULL;
				struct gset gset = { WEAPON_RCP45, 0, 0, FUNC_PRIMARY };
				struct prop *ownerprop = NULL;
				struct chrdata *ownerchr = NULL;
				s32 ownerplayernum = (obj->hidden & 0xf0000000) >> 28;

				if (g_Vars.normmplayerisrunning) {
					// Multiplayer - it must be a laptop gun
					ownerchr = mpGetChrFromPlayerIndex(ownerplayernum);

					if (ownerchr) {
						ownerprop = ownerchr->prop;
					}
				}

				if ((autogun->firecount & 7)
						|| (flashnode = modelGetPart(model->filedata, MODELPART_AUTOGUN_FLASHRIGHT)) == NULL) {
					flashnode = modelGetPart(model->filedata, MODELPART_AUTOGUN_FLASHLEFT);
				}

				if (flashnode == NULL) {
					posnode = modelGetPart(model->filedata, MODELPART_AUTOGUN_0003);
				}

				propSetPerimEnabled(autogunprop, false);

				if ((autogunprop->flags & PROPFLAG_ONTHISSCREENTHISTICK) && (flashnode || posnode)) {
					Mtxf *sp108;
					Mtxf spc8;
					union modelrodata *rodata;

					if (flashnode) {
						sp108 = model0001a5cc(model, flashnode, 0);
						rodata = flashnode->rodata;

						gunpos = rodata->chrgunfire.pos;
					} else {
						sp108 = model0001a5cc(model, posnode, 0);

						gunpos.x = 0.0f;
						gunpos.y = 0.0f;
						gunpos.z = 0.0f;
					}

					mtx00015be4(g_Vars.currentplayer->projectionmtx, sp108, &spc8);
					mtx4TransformVecInPlace(&spc8, &gunpos);

					if (cdTestLos10(&autogunprop->pos, autogunprop->rooms, &gunpos, gunrooms, CDTYPE_BG, GEOFLAG_BLOCK_SHOOT) == CDRESULT_COLLISION) {
						gunpos = autogunprop->pos;

						roomsCopy(autogunprop->rooms, gunrooms);
					}
				} else {
					gunpos = autogunprop->pos;

					roomsCopy(autogunprop->rooms, gunrooms);
				}

				dir.x = cosf(autogun->xrot) * sinf(autogun->yrot);
				dir.y = sinf(autogun->xrot);
				dir.z = cosf(autogun->xrot) * cosf(autogun->yrot);

				hitpos.x = gunpos.x + dir.x * 65536.0f;
				hitpos.y = gunpos.y + dir.y * 65536.0f;
				hitpos.z = gunpos.z + dir.z * 65536.0f;

				// If multiplayer, or targeting a bad guy in solo
				// (ie. autogun is a Defense autogun or a thrown laptop)
				if (g_Vars.normmplayerisrunning
						|| (targetprop && (targetprop->type == PROPTYPE_CHR))
						|| (g_Vars.antiplayernum >= 0 && targetprop && targetprop == g_Vars.anti->prop)) {
					if (cdExamLos08(&gunpos, gunrooms, &hitpos, CDTYPE_ALL, GEOFLAG_BLOCK_SHOOT) == CDRESULT_COLLISION) {
						hitpos = g_CdObstaclePos;
						hitprop = g_CdObstacleProp;

						// SP: If the hit prop is a chr and it's our target
						// MP: If the hit prop is a chr
						if (hitprop
								&& (hitprop->type & (PROPTYPE_CHR | PROPTYPE_PLAYER))
								&& (g_Vars.normmplayerisrunning || targetprop == hitprop)) {
							struct modelnode *hitnode = NULL;
							struct model *hitmodel = NULL;
							s32 hitside = -1;
							s32 hitpart = HITPART_GENERAL;
							f32 damage = gsetGetDamage(&gset);
							struct chrdata *hitchr = hitprop->chr;

							if (g_Vars.normmplayerisrunning) {
								damage *= 0.5f;
							}

							if (ownerprop == hitprop || (ownerchr && chrCompareTeams(hitprop->chr, ownerchr, COMPARE_FRIENDS))) {
								// A teammate entered the line of fire
								makebeam = false;
								fireleft = false;
								fireright = false;
								friendly = true;
							}

							if (fireleft || fireright) {
								bgunPlayPropHitSound(&gset, hitprop, -1);

								if (hitchr->model && hitchr->cshield > 0.0f) {
									chrCalculateShieldHit(hitchr, &hitpos, &dir, &hitnode, &hitpart, &hitmodel, &hitside);
								}

								chrEmitSparks(hitchr, hitprop, hitpart, &hitpos, &dir, ownerchr);
								func0f0341dc(hitchr, damage, &dir, &gset, ownerprop, HITPART_GENERAL, hitprop, hitnode, hitmodel, hitside, NULL);
							}
						} else {
							missed = true;
						}
					}
				} else if (targetprop && targetprop->type == PROPTYPE_OBJ) {
					// Laptop in firing range
					struct prop *hitprop = NULL;

					if (cdExamLos08(&gunpos, gunrooms, &hitpos,
								CDTYPE_ALL & ~CDTYPE_PLAYERS,
								GEOFLAG_BLOCK_SHOOT) == CDRESULT_COLLISION) {
						hitpos = g_CdObstaclePos;
						hitprop = g_CdObstacleProp;
						missed = true;
					}

					if (hitprop && hitprop->type == PROPTYPE_OBJ) {
						struct defaultobj *hitobj = hitprop->obj;

						if (hitobj->modelnum == MODEL_TARGET) {
							struct gset gset = { WEAPON_LAPTOPGUN, 0, 0, FUNC_SECONDARY };

							missed = false;

							frCalculateHit(hitobj, &hitpos, 0);

							if (chrIsUsingPaintball(ownerchr)) {
								sparksCreate(hitprop->rooms[0], hitprop, &hitpos, 0, 0, SPARKTYPE_PAINT);
							} else {
								sparksCreate(hitprop->rooms[0], hitprop, &hitpos, 0, 0, SPARKTYPE_DEFAULT);
							}

							bgunPlayPropHitSound(&gset, hitprop, TEXTURE_00F2);
						}
					}
				} else {
					// Enemy autogun in solo
					if (cdExamLos08(&gunpos, gunrooms, &hitpos,
								CDTYPE_DOORS | CDTYPE_BG,
								GEOFLAG_BLOCK_SHOOT) == CDRESULT_COLLISION) {
						hitpos = g_CdObstaclePos;
						missed = true;
					}

					if (g_Vars.lvframe60 == autogun->lastaimbond60
							&& targetprop && targetprop->type == PROPTYPE_PLAYER) {
						f32 x;
						f32 y;
						f32 z;
						f32 sqguntotargetdist;
						f32 sqguntohitdist;
						f32 damage;

						x = targetprop->pos.x - gunpos.x;
						y = targetprop->pos.y - gunpos.y;
						z = targetprop->pos.z - gunpos.z;

						sqguntotargetdist = x * x + y * y + z * z;

						x = hitpos.f[0] - gunpos.f[0];
						y = hitpos.f[1] - gunpos.f[1];
						z = hitpos.f[2] - gunpos.f[2];

						sqguntohitdist = x * x + y * y + z * z;

						if (sqguntohitdist >= sqguntotargetdist) {
							f32 increment = 0.16f * g_Vars.lvupdate60freal * g_AutogunAccuracyScale;

							if (sqguntotargetdist > 40000.0f) {
								increment *= 200.0f / sqrtf(sqguntotargetdist);
							}

							autogun->shotbondsum += increment;

							if (autogun->shotbondsum >= 1.0f) {
								hitpos = targetprop->pos;

								missed = false;

								if (random() % 2) {
									hitpos.y += 2 + (random() % 10);
								} else {
									hitpos.y -= 2 + (random() % 10);
								}

								bgunPlayPropHitSound(&gset, targetprop, -1);

								damage = 0.5f * g_AutogunDamageTxScale;

								chrDamageByImpact(targetprop->chr, damage, &dir, &gset, 0, HITPART_GENERAL);

								autogun->shotbondsum = 0.0f;
							}
						}
					}
				}

				propSetPerimEnabled(autogunprop, true);

				if (fireleft || fireright) {
					if (autogun->ammoquantity > 0 && autogun->ammoquantity != 255) {
						autogun->ammoquantity--;
					}
				}

				if (missed) {
					portal00018148(&gunpos, &hitpos, gunrooms, hitrooms, NULL, 0);

					if (chrIsUsingPaintball(ownerchr)) {
						sparksCreate(hitrooms[0], NULL, &hitpos, 0, 0, SPARKTYPE_PAINT);
					} else {
						sparksCreate(hitrooms[0], NULL, &hitpos, 0, 0, autogun->base.modelnum == MODEL_CETROOFGUN ? SPARKTYPE_BGHIT_GREEN : SPARKTYPE_DEFAULT);
					}

					bgunPlayBgHitSound(&gset, &hitpos, -1, hitrooms);
				}

				if (makebeam) {
					f32 distance;
					struct beam *beam = autogun->beam;
					f32 sum;
					struct coord dist;

					dist.x = hitpos.x - gunpos.x;
					dist.y = hitpos.y - gunpos.y;
					dist.z = hitpos.z - gunpos.z;

					sum = dist.f[0] * dist.f[0] + dist.f[1] * dist.f[1] + dist.f[2] * dist.f[2];

					distance = sqrtf(sum);

					if (distance > 0.0f) {
						beam->from = gunpos;

						beam->dir.x = dist.f[0];
						beam->dir.y = dist.f[1];
						beam->dir.z = dist.f[2];

						beam->dir.x *= 1.0f / distance;
						beam->dir.y *= 1.0f / distance;
						beam->dir.z *= 1.0f / distance;

						if (distance > 10000.0f) {
							distance = 10000.0f;
						}

						beam->age = 0;
						beam->weaponnum = autogun->base.modelnum == MODEL_CETROOFGUN ? WEAPON_CALLISTO : WEAPON_RCP45;
						beam->maxdist = distance;

						if (distance < 500.0f) {
							distance = 500.0f;
						}

						if (beam->weaponnum == WEAPON_LASER) {
							// Unreachable - weaponnum was assigned above
							beam->speed = 0.25f * distance;
							beam->mindist = 0.6f * distance;

							if (beam->mindist > 3000.0f) {
								beam->mindist = 3000.0f;
							}

							beam->dist = (-0.1f - RANDOMFRAC() * 0.3f) * distance;
						} else {
							beam->speed = 0.2f * distance;
							beam->mindist = 0.2f * distance;

							if (beam->mindist > 3000.0f) {
								beam->mindist = 3000.0f;
							}

							beam->dist = (2.0f * RANDOMFRAC() - 1.0f) * beam->speed;
						}
					}
				}
			}

			if (autogun->allowsoundframe < g_Vars.lvframe60) {
				s32 soundgap = 2;

				func0f0926bc(autogunprop, 1, 0xffff);

				if (!friendly) {
					s32 soundnum = SFX_806F;

					if (autogun->base.modelnum == MODEL_CETROOFGUN) {
						soundnum = SFX_MENU_ERROR;
					}

					if (autogun->base.modelnum == MODEL_CHRAUTOGUN) {
						soundnum = SFX_8044;
						soundgap = 4;
					}

					propsnd0f0939f8(NULL, autogunprop, soundnum, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
				}

				autogun->allowsoundframe = soundgap + g_Vars.lvframe60;
			}
		}

		node1 = modelGetPart(model->filedata, MODELPART_AUTOGUN_FLASHLEFT);

		if (node1) {
			union modelrwdata *rwdata = modelGetNodeRwData(model, node1);
			rwdata->chrgunfire.visible = fireleft;
		}

		node2 = modelGetPart(model->filedata, MODELPART_AUTOGUN_FLASHRIGHT);

		if (node2) {
			union modelrwdata *rwdata = modelGetNodeRwData(model, node2);
			rwdata->chrgunfire.visible = fireright;
		}
	}
}

static void chopperInitMatrices(struct prop *prop)
{
	struct chopperobj *chopper = (struct chopperobj *)prop->obj;
	struct model *model = chopper->base.model;
	Mtxf *matrices = model->matrices;
	union modelrodata *rodata;
	Mtxf spa8;
	Mtxf sp68;
	Mtxf sp28;

	rodata = modelGetPartRodata(model->filedata, MODELPART_CHOPPER_0001);
	mtx4LoadZRotation(M_BADTAU - chopper->gunrotx, &sp68);
	mtx4LoadYRotation(chopper->gunroty + 1.5707963705063f, &sp28);
	mtx00015be4(&sp28, &sp68, &spa8);

	mtx4SetTranslation(&rodata->position.pos, &spa8);
	mtx00015be4(matrices, &spa8, &matrices[1]);

	rodata = modelGetPartRodata(model->filedata, MODELPART_CHOPPER_0002);
	mtx4LoadXRotation(chopper->barrelrot, &spa8);
	mtx4SetTranslation(&rodata->position.pos, &spa8);
	mtx00015be4(&matrices[1], &spa8, &matrices[2]);
}

struct prop *chopperGetTargetProp(struct chopperobj *chopper)
{
	if (chopper->target == -1) {
		return g_Vars.currentplayer->prop;
	}

	return g_Vars.props + chopper->target;
}

struct chopperobj *chopperFromHovercar(struct chopperobj *chopper)
{
	if (chopper->base.type == OBJTYPE_CHOPPER) {
		return chopper;
	}

	return NULL;
}

bool chopperCheckTargetInFov(struct chopperobj *hovercar, u8 fov)
{
	struct chopperobj *chopper = chopperFromHovercar(hovercar);
	u8 visible = false;

	if (chopper) {
		f32 roty = chopper->roty;
		struct prop *target = chopperGetTargetProp(chopper);
		struct prop *prop = chopper->base.prop;
		f32 angle = atan2f(prop->pos.x - target->pos.x, prop->pos.z - target->pos.z);
		f32 anglediff = angle - roty;

		if (angle < roty) {
			anglediff += M_BADTAU;
		}

		visible = false;

		// This logic looks wrong, but is actually correct. I think the fov is
		// actually the not viewable area and starts at the back of the chopper,
		// which makes sense because the chopper's windows go around the side.
		if (!(anglediff < fov * 0.024539785459638f && anglediff < M_PI)
				&& !(anglediff > M_BADTAU - fov * 0.024539785459638f && anglediff > M_PI)) {
			visible = true;
		}

		chopper->targetvisible = visible;
	}

	return visible;
}

bool chopperCheckTargetInSight(struct chopperobj *obj)
{
	struct chopperobj *chopper = chopperFromHovercar(obj);

	if (chopper) {
		bool visible = false;
		struct prop *target = chopperGetTargetProp(chopper);

		if (target->type != PROPTYPE_PLAYER || g_Vars.bondvisible) {
			visible = cdTestLos05(&target->pos, target->rooms, &chopper->base.prop->pos, chopper->base.prop->rooms,
					CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_PATHBLOCKER | CDTYPE_BG | CDTYPE_AIOPAQUE,
					GEOFLAG_BLOCK_SHOOT);
		}

		chopper->targetvisible = visible;
		return visible;
	}

	return false;
}

void chopperSetTarget(struct chopperobj *obj, u32 chrnum)
{
	struct chopperobj *chopper = chopperFromHovercar(obj);

	if (chopper) {
		struct chrdata *chr = chrFindById(NULL, chrnum);

		if (chr && chr->prop) {
			chopper->target = chr->prop - g_Vars.props;
		}
	}
}

bool chopperAttack(struct chopperobj *obj)
{
	struct chopperobj *chopper = chopperFromHovercar(obj);

	if (chopper) {
		chopper->attackmode = CHOPPERMODE_COMBAT;
		chopper->patroltimer60 = TICKS(240);

		return true;
	}

	return false;
}

bool chopperStop(struct chopperobj *obj)
{
	struct chopperobj *chopper = chopperFromHovercar(obj);

	if (chopper) {
		chopper->attackmode = CHOPPERMODE_PATROL;
		chopper->patroltimer60 = TICKS(120);
		chopper->power = 0;

		return true;
	}

	return false;
}

bool chopperSetArmed(struct chopperobj *obj, bool armed)
{
	struct chopperobj *chopper = chopperFromHovercar(obj);

	if (chopper) {
		chopper->weaponsarmed = armed;
		return true;
	}

	return false;
}

void chopperRestartTimer(struct chopperobj *obj)
{
	struct chopperobj *chopper = chopperFromHovercar(obj);

	if (chopper) {
		chopper->timer60 = 0;
	}
}

s32 chopperGetTimer(struct chopperobj *obj)
{
	struct chopperobj *chopper = chopperFromHovercar(obj);

	return chopper->timer60;
}

void chopperSetMaxDamage(struct chopperobj *chopper, u16 health)
{
	chopper->base.maxdamage = health;
}

static f32 func0f07b164(struct coord *pos1, struct coord *pos2, struct coord *pos3, struct coord *result)
{
	struct coord sp34;
	struct coord sp28;
	f32 tmp;

	sp34.x = pos2->x - pos1->x;
	sp34.y = pos2->y - pos1->y;
	sp34.z = pos2->z - pos1->z;

	sp28.x = pos3->x - pos1->x;
	sp28.y = pos3->y - pos1->y;
	sp28.z = pos3->z - pos1->z;

	guNormalize(&sp34.x, &sp34.y, &sp34.z);

	tmp = sp28.f[0] * sp34.f[0] + sp28.f[1] * sp34.f[1] + sp28.f[2] * sp34.f[2];

	result->x = sp34.x * tmp + pos1->x;
	result->y = sp34.y * tmp + pos1->y;
	result->z = sp34.z * tmp + pos1->z;

	return sp28.f[0] * sp28.f[0] + sp28.f[1] * sp28.f[1] + sp28.f[2] * sp28.f[2] - tmp * tmp;
}

void chopperFireRocket(struct chopperobj *chopper, bool side)
{
	if (chopper->ontarget) {
		struct coord direction;
		struct coord pos;
		struct prop *targetprop = chopperGetTargetProp(chopper);
		struct prop *chopperprop = chopper->base.prop;
		u32 stack;
		Mtxf sp6c;
		Mtxf sp2c;

		pos.x = side ? -754 : 754;
		pos.y = -400;
		pos.z = -400;

		mtx3ToMtx4(chopper->base.realrot, &sp2c);
		mtx4LoadTranslation(&pos, &sp6c);
		mtx4MultMtx4InPlace(&sp2c, &sp6c);

		pos.x = sp6c.m[3][0] + chopperprop->pos.f[0];
		pos.y = sp6c.m[3][1] + chopperprop->pos.f[1];
		pos.z = sp6c.m[3][2] + chopperprop->pos.f[2];

		direction.x = targetprop->pos.x - pos.x;
		direction.y = targetprop->pos.y - pos.y + (s32)(random() % 100);
		direction.z = targetprop->pos.z - pos.z;

		guNormalize(&direction.x, &direction.y, &direction.z);

		smokeCreateSimple(&pos, chopperprop->rooms, SMOKETYPE_3);

		projectileCreate(chopperprop, 0, &pos, &direction, WEAPON_ROCKETLAUNCHER, targetprop);
	}
}

static void chopperIncrementBarrel(struct prop *chopperprop, bool firing)
{
	struct defaultobj *obj = chopperprop->obj;
	struct chopperobj *chopper = (struct chopperobj *)chopperprop->obj;
	struct model *model = obj->model;
	f32 angleh = 0.0f;
	f32 anglev = 0.0f;
	f32 speedmult = 1.0f;
	struct coord rot;
	struct coord gunpos;
	f32 gunroty = chopper->gunroty;
	f32 gunrotx = chopper->gunrotx;
	f32 gunturnyspeed60 = chopper->gunturnyspeed60;
	f32 gunturnxspeed60 = chopper->gunturnxspeed60;
	struct prop *targetprop = chopperGetTargetProp(chopper);
	struct modelnode *node;
	struct modelrwdata_chrgunfire *rwdata = NULL;
	struct modelrodata_position *rodata;
	Mtxf sp90;
	Mtxf sp50;
	f32 gunaimy;

	if (chopper->fireslotthing->unk00);

	chopper->fireslotthing->unk01 = (chopper->fireslotthing->unk00 % 3) == 0;

	if (firing) {
		rodata = modelGetPartRodata(model->filedata, MODELPART_CHOPPER_0001);
		gunaimy = targetprop->pos.y - 20.0f;

		gunpos.x = random() * random() * 0 * 30.0f + rodata->pos.x;
		gunpos.y = random() * 0 * 30.0f + (rodata->pos.y - 50.0f);
		gunpos.z = rodata->pos.z + 250.0f;

		if (obj->modelnum == MODEL_A51INTERCEPTOR) {
			f32 scale = 0.1f / obj->model->scale;
			gunpos.x *= scale;
			gunpos.y *= scale;
			gunpos.z *= scale;
		}

		mtx3ToMtx4(obj->realrot, &sp50);
		mtx4LoadTranslation(&gunpos, &sp90);
		mtx4MultMtx4InPlace(&sp50, &sp90);

		gunpos.x = sp90.m[3][0] + chopperprop->pos.f[0];
		gunpos.y = sp90.m[3][1] + chopperprop->pos.f[1];
		gunpos.z = sp90.m[3][2] + chopperprop->pos.f[2];

		angleh = atan2f(targetprop->pos.x - gunpos.x, targetprop->pos.z - gunpos.z);

		if (angleh <= 0.0f) {
			angleh += M_BADTAU;
		}

		if (angleh > M_BADTAU) {
			angleh -= M_BADTAU;
		}

		angleh -= chopper->roty;

		if (angleh > M_PI) {
			angleh -= M_BADTAU;
		}

		if (angleh < -M_PI) {
			angleh += M_BADTAU;
		}

		anglev = atan2f(gunaimy - gunpos.y, sqrtf((targetprop->pos.x - gunpos.x) * (targetprop->pos.x - gunpos.x) + (targetprop->pos.z - gunpos.z) * (targetprop->pos.z - gunpos.z))) - chopper->rotx + M_BADTAU;

		if (anglev > M_PI) {
			anglev -= M_BADTAU;
		}

		if (chopper->barrelrotspeed < 0.34906584f) {
			chopper->barrelrotspeed += 0.017453292f * LVUPDATE60FREAL();
		} else {
			chopper->barrelrotspeed = 0.34906584f;
		}
	} else {
		speedmult = 0.125f;

		if (chopper->barrelrotspeed > 0.0f) {
			chopper->barrelrotspeed -= 0.017453292f;
		} else {
			chopper->barrelrotspeed = 0.0f;
		}
	}

	chopper->barrelrot += chopper->barrelrotspeed * LVUPDATE60FREAL();

#if PAL
	applySpeed(&gunroty, angleh, &gunturnyspeed60, 0.0027920822612941f * speedmult, 0.0055841645225883f * speedmult, 0.16752494871616f * speedmult);

	if (gunroty == angleh && gunturnyspeed60 <= 0.0055841645225883f * speedmult && -0.0055841645225883f * speedmult <= gunturnyspeed60) {
		gunturnyspeed60 = 0.0f;
	}

	applySpeed(&gunrotx, anglev, &gunturnxspeed60, 0.0027920822612941f * speedmult, 0.0055841645225883f * speedmult, 0.16752494871616f * speedmult);

	if (gunrotx == anglev && gunturnxspeed60 <= 0.0055841645225883f * speedmult && -0.0055841645225883f * speedmult <= gunturnxspeed60) {
		gunturnxspeed60 = 0.0f;
	}
#else
	applySpeed(&gunroty, angleh, &gunturnyspeed60, 0.0023267353f * speedmult, 0.0046534706f * speedmult, 0.1396041f * speedmult);

	if (gunroty == angleh && gunturnyspeed60 <= 0.0046534706f * speedmult && -0.0046534706f * speedmult <= gunturnyspeed60) {
		gunturnyspeed60 = 0.0f;
	}

	applySpeed(&gunrotx, anglev, &gunturnxspeed60, 0.0023267353f * speedmult, 0.0046534706f * speedmult, 0.1396041f * speedmult);

	if (gunrotx == anglev && gunturnxspeed60 <= 0.0046534706f * speedmult && -0.0046534706f * speedmult <= gunturnxspeed60) {
		gunturnxspeed60 = 0.0f;
	}
#endif

	chopper->gunroty = gunroty;
	chopper->gunrotx = gunrotx;
	chopper->gunturnyspeed60 = gunturnyspeed60;
	chopper->gunturnxspeed60 = gunturnxspeed60;

	if (!(chopper->fireslotthing->unk00 % 2)) {
		firing = false;
	}

	node = modelGetPart(model->filedata, MODELPART_CHOPPER_GUNFLASH);

	if (node) {
		rwdata = modelGetNodeRwData(model, node);
	}

	if (firing) {
		f32 totalrotx = chopper->gunrotx + chopper->rotx;
		f32 totalroty = chopper->gunroty + chopper->roty;

		rot.x = sinf(totalroty) * cosf(totalrotx);
		rot.y = sinf(totalrotx);
		rot.z = cosf(totalroty) * cosf(totalrotx);

		projectileCreate(chopperprop, chopper->fireslotthing, &gunpos, &rot, WEAPON_CHOPPERGUN, targetprop);

		if (rwdata != NULL) {
			rwdata->visible = true;
		}
	} else {
		if (rwdata != NULL) {
			rwdata->visible = false;
		}
	}

	chopper->fireslotthing->unk00++;
}

static void chopperIncrementMovement(struct prop *prop, f32 goalroty, f32 goalrotx, struct coord *dir, bool firing)
{
	struct defaultobj *obj = prop->obj;
	struct chopperobj *chopper = (struct chopperobj *)obj;
	s16 newrooms[8];
	struct coord newpos;
	f32 curroty;
	f32 currotx;
	f32 currotz;
	f32 turnyspeed;
	f32 turnxspeed;
	f32 rotmtx3[3][3];
	f32 tmp;
	f32 f2;
	s32 i;
	f32 speed;
	s32 soundnum;
	struct coord spfc;
	Mtxf spbc;
	Mtxf sp7c;
	Mtxf sp3c;
	f32 angle;

	curroty = chopper->roty;
	currotx = chopper->rotx;
	currotz = chopper->rotz;
	turnyspeed = chopper->turnyspeed60;
	turnxspeed = chopper->turnxspeed60;

	chopper->otx = dir->x;
	chopper->oty = dir->y;
	chopper->otz = dir->z;

	dir->x *= chopper->power;
	dir->y *= chopper->power;
	dir->z *= chopper->power;

	if (chopper->power < 3.7f) {
		chopper->power += 0.030833334f * g_Vars.lvupdate60freal;
	}

	chopper->bob += 0.052359f;

	if (chopper->bob > M_BADTAU) {
		chopper->bob = 0.0f;
		chopper->bobstrength = ((random() % 8) + 2) * 0.01f;

		if (chopper->base.flags & OBJFLAG_CHOPPER_INACTIVE) {
			chopper->bobstrength *= 0.15f;
		}
	}

	dir->y += chopper->bobstrength * sinf(chopper->bob);

	f2 = PAL ? 0.976f : 0.98f;

	for (i = 1; i < g_Vars.lvupdate60; i++) {
		f2 *= PAL ? 0.976f : 0.98f;
	}

	chopper->vx += dir->x;
	chopper->vy += dir->y;
	chopper->vz += dir->z;

	chopper->vx *= f2;
	chopper->vy *= f2;
	chopper->vz *= f2;

	if (chopper->attackmode != CHOPPERMODE_FALL) {
		if (chopper->attackmode != CHOPPERMODE_PATROL || chopper->patroltimer60 > 0) {
			speed = 5.0f;
		} else {
			speed = 8.0f;
		}

		tmp = chopper->vx * chopper->vx + chopper->vy * chopper->vy + chopper->vz * chopper->vz;

		if (tmp > speed * speed) {
			guNormalize(&chopper->vx, &chopper->vy, &chopper->vz);

			chopper->vx *= speed;
			chopper->vy *= speed;
			chopper->vz *= speed;
		}
	}

	if (goalrotx > M_PI && goalrotx < 5.8f) {
		goalrotx = 5.8f;
	}

#if PAL
	applyRotation(&curroty, goalroty, &turnyspeed, 0.00026175772654824f, 0.00052351545309648f, 0.015705462545156f);

	if (curroty == goalroty && turnyspeed <= 0.00052351545309648f && turnyspeed >= -0.00052351545309648f) {
		turnyspeed = 0.0f;
	}

	applyRotation(&currotx, goalrotx, &turnxspeed, 0.00026175772654824, 0.00052351545309648f, 0.015705462545156f);

	if (currotx == goalrotx && turnxspeed <= 0.00052351545309648f && turnxspeed >= -0.00052351545309648f) {
		turnxspeed = 0.0f;
	}
#else
	applyRotation(&curroty, goalroty, &turnyspeed, 0.00021813141938765f, 0.00043626284f, 0.013087885f);

	if (curroty == goalroty && turnyspeed <= 0.00043626284f && turnyspeed >= -0.00043626284f) {
		turnyspeed = 0.0f;
	}

	applyRotation(&currotx, goalrotx, &turnxspeed, 0.00021813141938765f, 0.00043626284f, 0.013087885f);

	if (currotx == goalrotx && turnxspeed <= 0.00043626284f && turnxspeed >= -0.00043626284f) {
		turnxspeed = 0.0f;
	}
#endif

	currotz += (-turnyspeed * 40.0f - currotz) * 0.1f;

	spfc.x = M_BADTAU - currotx;
	spfc.y = curroty;
	spfc.z = 0.0f;

	if (currotz >= 0) {
		mtx4LoadZRotation(currotz, &sp3c);
	} else {
		mtx4LoadZRotation(currotz + M_BADTAU, &sp3c);
	}

	mtx4LoadRotation(&spfc, &sp7c);
	mtx00015f04(chopper->base.model->scale, &sp7c);
	mtx4MultMtx4(&sp7c, &sp3c, &spbc);
	mtx4ToMtx3(&spbc, rotmtx3);
	mtx3Copy(rotmtx3, chopper->base.realrot);

	if (chopper->power > 0.45f && !firing && (chopper->base.flags2 & OBJFLAG2_INVISIBLE) == 0 && objIsHealthy(&chopper->base)) {
		soundnum = g_Vars.stagenum == STAGE_EXTRACTION ? SFX_810D : SFX_8110;

		propsnd0f09294c(prop, soundnum, 6);
	} else {
		func0f0926bc(prop, 6, 0xffff);
	}

	chopper->roty = curroty;
	chopper->rotx = currotx;
	chopper->rotz = currotz;
	chopper->turnyspeed60 = turnyspeed;
	chopper->turnxspeed60 = turnxspeed;

	if (goalroty < curroty) {
		angle = curroty - goalroty;
	} else {
		angle = -(curroty - goalroty);
	}

	chopper->ontarget = angle < 0.1745f;

	newpos.x = prop->pos.x + chopper->vx * g_Vars.lvupdate60freal;
	newpos.y = prop->pos.y + chopper->vy * g_Vars.lvupdate60freal;
	newpos.z = prop->pos.z + chopper->vz * g_Vars.lvupdate60freal;

	func0f065e74(&prop->pos, prop->rooms, &newpos, newrooms);

	prop->pos = newpos;

	propDeregisterRooms(prop);
	roomsCopy(newrooms, prop->rooms);
	func0f069c70(&chopper->base, false, true);
	chopperIncrementBarrel(prop, firing);

	if ((chopper->base.flags2 & OBJFLAG2_INVISIBLE) == 0 && objIsHealthy(&chopper->base)) {
		soundnum = g_Vars.stagenum == STAGE_EXTRACTION ? SFX_SHIP_HUM : SFX_810F;

		propsnd0f09294c(prop, soundnum, 5);
	} else {
		func0f0926bc(prop, 5, 0xffff);
	}
}

#define NEXTSTEP() (chopper->cw ? i : (i + 1) % chopper->path->len)
#define PREVSTEP() (chopper->cw ? (i + 1) % chopper->path->len : i)

static void chopperTickFall(struct prop *chopperprop)
{
	struct defaultobj *obj = chopperprop->obj;
	struct chopperobj *chopper = (struct chopperobj *) obj;
	f32 goalroty;
	f32 *x = &chopper->fall.x;
	f32 *y = &chopper->fall.y;
	f32 *z = &chopper->fall.z;
	struct coord speed;
	s32 i;
	struct pad *prevpad;
	struct pad *nextpad;
	f32 xdiff;
	f32 zdiff;
	f32 tmp;
	struct coord newpos;
	struct coord newspeed;

	// The timer is set explicitly to 2 when the chopper is destroyed
	if (chopper->timer60 == 2) {
		// Figure out what direction to fall in
		xdiff = 0;
		zdiff = 0;

		chopper->timer60 -= g_Vars.lvupdate60;

		if (chopper->path) {
			for (i = 0; i < chopper->path->len; i++) {
				if (NEXTSTEP() == chopper->nextstep) {
					break;
				}
			}

			prevpad = &g_Pads[chopper->path->pads[PREVSTEP()]];
			nextpad = &g_Pads[chopper->path->pads[NEXTSTEP()]];

			xdiff = prevpad->pos.f[0] - nextpad->pos.f[0];
			zdiff = prevpad->pos.f[2] - nextpad->pos.f[2];

			tmp = 0.25f / sqrtf(xdiff * xdiff + zdiff * zdiff);

			xdiff *= tmp;
			zdiff *= tmp;
		}

		*x = -zdiff;
		*y = 0;
		*z = xdiff;
	} else if (chopper->timer60 >= 0) {
		// Haven't started falling yet
		chopper->timer60 -= g_Vars.lvupdate60;
	} else {
		if (*y > -0.7f)
		{
			// Increase fall speed
			*y -= 0.009f * g_Vars.lvupdate60f;
		}
	}

	speed.x = *x;
	speed.y = *y;
	speed.z = *z;

	goalroty = chopper->roty + *x + *z;

	if (g_Vars.stagenum == STAGE_EXTRACTION) {
		// The Extraction chopper falls without any collision checks and is
		// reaped once it reaches the lower barrier
		if (chopperprop->pos.y < -30000) {
			func0f0926bc(chopperprop, 1, 0xffff);
			obj->hidden |= OBJHFLAG_REAPABLE;
		} else {
			chopperIncrementMovement(chopperprop, goalroty, chopper->rotx < 0 ? M_PI : -M_PI, &speed, false);
		}
	} else {
		// Area 51 interceptors do collision checks
		// and explode once they hit the ground.
		f32 mult = 1.0f - PALUPF(0.02f);
		f32 bob;
		s32 i;

		for (i = 1; i < g_Vars.lvupdate60; i++) {
			mult *= 1.0f - PALUPF(0.02f);
		}

		bob = chopper->bob + 0.052358999848366f;

		if (bob > M_BADTAU) {
			bob = 0;

			chopper->bobstrength = (random() % 8 + 2) * 0.01f;

			if (obj->flags & OBJFLAG_80000000) {
				chopper->bobstrength *= 0.15f;
			}
		}

		speed.y += chopper->bobstrength * sinf(bob);

		newspeed.x = mult * (speed.f[0] * chopper->power + chopper->vx);
		newspeed.y = mult * (speed.f[1] * chopper->power + chopper->vy);
		newspeed.z = mult * (speed.f[2] * chopper->power + chopper->vz);

		newpos.x = chopperprop->pos.x + newspeed.f[0] * g_Vars.lvupdate60freal;
		newpos.y = chopperprop->pos.y + newspeed.f[1] * g_Vars.lvupdate60freal;
		newpos.z = chopperprop->pos.z + newspeed.f[2] * g_Vars.lvupdate60freal;

		if (cdExamLos09(&chopperprop->pos, chopperprop->rooms, &newpos, CDTYPE_BG) == CDRESULT_COLLISION) {
			struct coord sp74;
			s16 room;
			f32 ground;
			s16 newrooms[8];

			chopperprop->pos.y += 100;
			ground = cdFindGroundAtCyl(&chopperprop->pos, 5, chopperprop->rooms, NULL, NULL);
			chopperprop->pos.y -= 100;

			newpos.x = g_CdObstaclePos.x;
			newpos.y = ground + 20;
			newpos.z = g_CdObstaclePos.z;

			func0f065e74(&chopperprop->pos, chopperprop->rooms, &newpos, newrooms);

			chopperprop->pos = newpos;

			propDeregisterRooms(chopperprop);
			roomsCopy(newrooms, chopperprop->rooms);
			func0f069c70(obj, false, true);

			// Move to CHOPPERMODE_DEAD
			chopper->attackmode++;

			objDeform(&chopper->base, 8);

			room = chopperprop->rooms[0];

			sp74.x = 0;
			sp74.y = 1;
			sp74.z = 0;

			func0f0926bc(chopperprop, 1, 0xffff);

			explosionCreate(NULL, &chopperprop->pos, chopperprop->rooms, EXPLOSIONTYPE_ROCKET, 0, true, &newpos, room, &sp74);

			chopper->dead = true;
		} else {
			smokeCreateSimple(&chopperprop->pos, chopperprop->rooms, SMOKETYPE_3);
			chopperIncrementMovement(chopperprop, goalroty, chopper->rotx < 0 ? M_PI : -M_PI, &speed, false);
		}
	}
}

static void chopperTickIdle(struct prop *prop)
{
	struct chopperobj *chopper = (struct chopperobj *)prop->obj;
	u32 stack;
	f32 roty = chopper->roty;
	f32 rotx = chopper->rotx;
	struct coord coord;

	chraiExecute(chopper, PROPTYPE_OBJ);

	chopper->timer60 += g_Vars.lvupdate60;

	coord.x = 0;
	coord.y = 0;
	coord.z = 0;

	chopperIncrementMovement(prop, roty, rotx, &coord, false);
}

static void chopperTickPatrol(struct prop *chopperprop)
{
	struct chopperobj *chopper = (struct chopperobj *)chopperprop->obj;
	f32 xdiff;
	f32 roty = chopper->roty;
	f32 rotx = chopper->rotx;
	struct coord vector;
	struct coord padpos;
	f32 mult;
	f32 zdiff;

	chraiExecute(chopper, PROPTYPE_OBJ);

	chopper->timer60 += g_Vars.lvupdate60;

	if (chopper->patroltimer60 > 0) {
		chopper->patroltimer60 -= g_Vars.lvupdate60;
	}

	if (chopper->path) {
		padpos = g_Pads[chopper->path->pads[chopper->nextstep]].pos;
		padpos.y += -250;

		if (posIsArrivingLaterallyAtPos(&chopperprop->pos, &chopperprop->pos, &padpos, 350)) {
			chopper->nextstep = ((chopper->cw ? -1 : 1) + chopper->nextstep + chopper->path->len) % chopper->path->len;

			padpos = g_Pads[chopper->path->pads[chopper->nextstep]].pos;
			padpos.y += -250;
		}

		roty = atan2f(padpos.x - chopperprop->pos.x, padpos.z - chopperprop->pos.z);
		xdiff = padpos.x - chopperprop->pos.x;
		zdiff = padpos.z - chopperprop->pos.z;
		rotx = atan2f(padpos.y - chopperprop->pos.y, sqrtf(xdiff * xdiff + zdiff * zdiff));
	}

	if (chopper->base.flags & OBJFLAG_20000000) {
		chopper->roty = roty;
		chopper->rotx = rotx;
		if (1);
		chopper->base.flags &= ~OBJFLAG_20000000;
	}

	if (chopper->patroltimer60 > 0) {
		vector.x = padpos.x - chopperprop->pos.x;
		vector.y = padpos.y - chopperprop->pos.y;
		vector.z = padpos.z - chopperprop->pos.z;

		guNormalize(&vector.x, &vector.y, &vector.z);
	} else {
		mult = cosf(chopper->rotx);

		vector.x = sinf(chopper->roty) * mult;
		vector.y = sinf(chopper->rotx);
		vector.z = cosf(chopper->roty) * mult;
	}

	chopperIncrementMovement(chopperprop, roty, rotx, &vector, false);
}

/**
 * Tick the chopper when it's in combat mode (ie. knows where the player is).
 *
 * The actual firing logic is in the chopper's AI scripting. Same with choosing
 * to return to patrol when the player is out of sight for a few seconds.
 *
 * This function is only directly responsible for the chopper's movement during
 * combat.
 */
static void chopperTickCombat(struct prop *chopperprop)
{
	struct defaultobj *obj = chopperprop->obj;
	struct chopperobj *chopper = (struct chopperobj *)obj;
	s32 i;
	f32 f0;
	struct prop *targetprop = chopperGetTargetProp(chopper);
	f32 dist;
	struct coord goalpos;
	struct coord dir;
	struct coord padpos;
	struct coord nextpadpos;
	f32 f20;
	s32 sp90;
	s32 sp8c;
	bool reverse;
	s8 numsteps;
	s8 tmp;
	struct coord sp78;
	struct coord sp6c;

	dist = coordGetSquaredDistanceToCoord(&targetprop->pos, &chopperprop->pos);

	chraiExecute(chopper, PROPTYPE_OBJ);

	chopper->timer60 += g_Vars.lvupdate60;

	if ((chopper->targetvisible && dist < 2000000.0f) || chopper->path == NULL) {
		// Stay put

		goalpos = chopperprop->pos;
	} else {
		f20 = 2.6843546e8f;

		for (i = 0; i < chopper->path->len; i++) {
			padpos = g_Pads[chopper->path->pads[i]].pos;
			nextpadpos = g_Pads[chopper->path->pads[(i + 1) % chopper->path->len]].pos;

			padpos.y += -250.0f;
			nextpadpos.y += -250.0f;

			f0 = func0f07b164(&padpos, &nextpadpos, &targetprop->pos, &sp78);

			if (f0 < f20) {
				f20 = f0;
				sp90 = i;
				goalpos = sp78;
			}

			if ((chopper->cw ? i : (i + 1) % chopper->path->len) == chopper->nextstep) {
				sp8c = i;
				sp6c = sp78;
			}
		}

		if (sp8c != sp90) {
			if (dist > 400000.0f) {
				reverse = false;
				numsteps = sp8c - sp90;

				if (numsteps < 0) {
					numsteps *= -1;
					reverse = true;
				}

				tmp = chopper->path->len - numsteps;
				chopper->cw = numsteps < tmp;

				if (reverse) {
					chopper->cw = !chopper->cw;
				}

				chopper->nextstep = chopper->cw ? sp8c : (sp8c + 1) % chopper->path->len;

				padpos = g_Pads[chopper->path->pads[chopper->nextstep]].pos;
				padpos.y += -250.0f;

				if (coordGetSquaredDistanceToCoord(&padpos, &chopperprop->pos) < 10000.0f) {
					chopper->power = 0.0f;
					chopper->nextstep = (chopper->nextstep + (chopper->cw ? -1 : 1) + chopper->path->len) % chopper->path->len;

					padpos = g_Pads[chopper->path->pads[chopper->nextstep]].pos;
					padpos.y += -250.0f;
				}

				goalpos = padpos;
			} else {
				goalpos = sp6c;
			}
		} else if (cdTestLos03(&targetprop->pos, targetprop->rooms, &goalpos, CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_PATHBLOCKER | CDTYPE_BG | CDTYPE_AIOPAQUE, GEOFLAG_BLOCK_SHOOT) == 0) {
			padpos = g_Pads[chopper->path->pads[chopper->cw ? (sp8c + 1) % chopper->path->len : sp8c]].pos;
			padpos.y += -250.0f;

			sp78.x = padpos.x - goalpos.x;
			sp78.y = padpos.y - goalpos.y;
			sp78.z = padpos.z - goalpos.z;

			guNormalize(&sp78.x, &sp78.y, &sp78.z);

			goalpos.x += sp78.x * 400.0f;
			goalpos.y += sp78.y * 400.0f;
			goalpos.z += sp78.z * 400.0f;
		}
	}

	if (coordGetSquaredDistanceToCoord(&goalpos, &chopperprop->pos) < 2500.0f) {
		// Close to the goal pos - power off
		chopper->power = 0.0f;

		dir.x = 0.0f;
		dir.y = 0.0f;
		dir.z = 0.0f;
	} else {
		// Check if chopper has overshot the goal pos?
		dir.x = goalpos.x - chopperprop->pos.x;
		dir.y = goalpos.y - chopperprop->pos.y;
		dir.z = goalpos.z - chopperprop->pos.z;

		guNormalize(&dir.x, &dir.y, &dir.z);

		if (dir.f[0] * chopper->otx + dir.f[1] * chopper->oty + dir.f[2] * chopper->otz < 0.0f) {
			chopper->power = 0.0f;
		}
	}

	{
		f32 roty;
		f32 rotx;

		roty = atan2f(targetprop->pos.x - chopperprop->pos.x, targetprop->pos.z - chopperprop->pos.z);

		dist = sqrtf((targetprop->pos.x - chopperprop->pos.x) * (targetprop->pos.x - chopperprop->pos.x) + (targetprop->pos.z - chopperprop->pos.z) * (targetprop->pos.z - chopperprop->pos.z));
		rotx = atan2f(targetprop->pos.y - chopperprop->pos.y, dist);

		chopperIncrementMovement(chopperprop, roty, rotx, &dir, chopper->targetvisible && chopper->weaponsarmed);
	}
}

#define HOVVALUE1() ((active ? 15.0f : 5.0f) * PALUPF(0.00021813141938765f))
#define HOVVALUE2() ((active ? 15.0f : 5.0f) * PALUPF(0.013087885454297f))

static void hovercarTick(struct prop *prop)
{
	bool stopping;
	struct pad *pad;
	struct coord sp214;
	s16 sp210[2];
	struct hovercarobj *hovercar = (struct hovercarobj *) prop->obj;
	struct defaultobj *obj = &hovercar->base;
	u32 stack;
	f32 sp200 = hovercar->roty;
	f32 sp1fc = hovercar->rotx;
	u32 active = obj->flags & OBJFLAG_80000000;
	f32 sp1f4 = active ? 5 : 10;
	struct prop *doorprop;
	struct coord sp1e4;
	struct coord sp1d8;
	s16 sp1d6;
	f32 x;
	f32 z;
	struct coord sp1c0;
	s16 sp1b0[8];
	struct modelrodata_bbox *bbox;
	f32 ymin;
	s32 *padnum;
	struct doorobj *door;
	struct coord sp194;
	f32 sp190;
	f32 sp18c;
	f32 sp188;
	f32 sp184;
	f32 sp180;
	f32 sp15c[3][3];
	struct coord sp150;
	s16 sp140[8];
	f32 tmp2;
	f32 sp138;
	struct coord sp12c;
	Mtxf spec;
	Mtxf spac;
	Mtxf sp6c;

	doorprop = NULL;

	if (active && hovercar->deadtimer60 < 0) {
		// Exploding
		bbox = modelFindBboxRodata(hovercar->base.model);
		ymin = objGetLocalYMin(bbox);
		sp1d6 = prop->rooms[0];

		sp1d8.x = hovercar->base.realrot[1][0];
		sp1d8.y = hovercar->base.realrot[1][1];
		sp1d8.z = hovercar->base.realrot[1][2];

		sp1e4.x = hovercar->base.realrot[1][0] * ymin + prop->pos.x;
		sp1e4.y = hovercar->base.realrot[1][1] * ymin + prop->pos.y;
		sp1e4.z = hovercar->base.realrot[1][2] * ymin + prop->pos.z;

		func0f0926bc(prop, 1, 0xffff);
		explosionCreate(NULL, &prop->pos, prop->rooms, EXPLOSIONTYPE_7, g_Vars.currentplayernum, true, &sp1e4, sp1d6, &sp1d8);
		hovercar->base.hidden |= OBJHFLAG_REAPABLE;
		return;
	}

	if (hovercar->dead) {
		if (active) {
			hovercar->deadtimer60 -= g_Vars.lvupdate60;
			hovercar->sparkstimer60 -= g_Vars.lvupdate60;

			if (hovercar->sparkstimer60 < 0) {
				hovercar->sparkstimer60 = TICKS(50);

				propsnd0f0939f8(NULL, prop, SFX_SHIELD_DAMAGE, -1, -1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);

				sparksCreate(prop->rooms[0], prop, &prop->pos, NULL, 0, SPARKTYPE_DEFAULT);
			}
		} else {
			if (hovercar->speedtime60 == 0) {
				hovercar->speed += 6;

				sp1c0.x = prop->pos.x;
				sp1c0.y = prop->pos.y - hovercar->speed;
				sp1c0.z = prop->pos.z;

				if (sp1c0.y < hovercar->speedaim) {
					sp1c0.y = hovercar->speedaim;
					hovercar->speedtime60 = 1;
				}

				func0f065e74(&prop->pos, prop->rooms, &sp1c0, sp1b0);

				prop->pos = sp1c0;

				propDeregisterRooms(prop);
				roomsCopy(sp1b0, prop->rooms);
				func0f069c70(&hovercar->base, false, true);
			}
		}

		return;
	}

	chraiExecute(obj, PROPTYPE_OBJ);

	stopping = false;

	if (hovercar->path) {
		padnum = &hovercar->path->pads[hovercar->nextstep];
		pad = &g_Pads[*padnum];

		sp214.x = pad->pos.x;

		if (active) {
			sp210[0] = pad->room;
			sp210[1] = -1;

			sp214.y = cdFindGroundAtCyl(&pad->pos, 5, sp210, NULL, NULL) + 35;
		} else {
			sp214.y = pad->pos.y;
		}

		sp214.z = pad->pos.z;

		if ((hovercar->base.flags & OBJFLAG_20000000)
				&& posIsArrivingLaterallyAtPos(&prop->pos, &prop->pos, &sp214, (0, sp1f4))) {
			hovercarIncrementStep(hovercar);
			padnum = &hovercar->path->pads[hovercar->nextstep];
			pad = &g_Pads[*padnum];
		}

		sp200 = atan2f(sp214.x - prop->pos.x, sp214.z - prop->pos.z);
		tmp2 = sqrtf((sp214.x - prop->pos.x) * (sp214.x - prop->pos.x) + (sp214.z - prop->pos.z) * (sp214.z - prop->pos.z));
		sp1fc = atan2f(sp214.y - prop->pos.y, tmp2);

		if (hovercar->base.flags & OBJFLAG_20000000) {
			hovercar->roty = sp200;
			hovercar->rotx = sp1fc;
			obj->flags &= ~OBJFLAG_20000000;

			if (active) {
				prop->pos.y = sp214.y;
			}
		}

		if (active) {
			if (cdExamCylMove03(&prop->pos, prop->rooms, &sp214,
						CDTYPE_CLOSEDDOORS | CDTYPE_AJARDOORS, 0, 0, 0) == CDRESULT_COLLISION) {
				doorprop = g_CdObstacleProp;
			}

			if (doorprop) {
				door = (struct doorobj *) doorprop->obj;
				x = doorprop->pos.x - prop->pos.x;
				z = doorprop->pos.z - prop->pos.z;

				if (x * x + z * z < 200 * 200) {
					doorsChooseSwingDirection(prop, door);
					doorsRequestMode(door, DOORMODE_OPENING);
				}

				if (x * x + z * z < 195 * 195) {
					stopping = !doorIsOpen(door);
				}
			}
		}
	} else {
		if (hovercar->base.flags & OBJFLAG_20000000) {
			hovercar->roty = atan2f(hovercar->base.realrot[2][0], hovercar->base.realrot[2][2]);
			tmp2 = sqrtf(hovercar->base.realrot[2][2] * hovercar->base.realrot[2][2] + hovercar->base.realrot[2][0] * hovercar->base.realrot[2][0]);
			hovercar->rotx = atan2f(hovercar->base.realrot[2][1], tmp2);
			hovercar->base.flags &= ~OBJFLAG_20000000;
		}
	}

	// @bug: To calculate the speed correctly, the code needs to iterate the
	// lvupdate multiplier, then adjust the speed and test for reaching the
	// speedaim within each iteration. Or at least test for exceeding the
	// speedaim after updating it. With the below implementation, a lag frame
	// during acceleration can cause the hovercar to exceed its max speed.
	if (hovercar->speedtime60 >= 0) {
		if (1);
		if (hovercar->speedtime60 <= g_Vars.lvupdate60freal) {
			hovercar->speed = hovercar->speedaim;
		} else {
			hovercar->speed += (hovercar->speedaim - hovercar->speed) * g_Vars.lvupdate60freal / hovercar->speedtime60;
		}

		hovercar->speedtime60 -= g_Vars.lvupdate60freal;
	}

	if (active) {
		if (hovercar->turnyspeed60 > 0) {
			hovercar->speed -= hovercar->speedaim * (1.0f / 24.0f) * LVUPDATE60FREAL();

			if (hovercar->speed < 0) {
				hovercar->speed = 0.1f;
			}
		} else {
			if (hovercar->speed < hovercar->speedaim) {
				hovercar->speed += hovercar->speedaim * (1.0f / 24.0f) * LVUPDATE60FREAL();
			}
		}

		if (stopping) {
			hovercar->speed -= 50.0f / 240.f * LVUPDATE60FREAL();

			if (hovercar->speed < 0) {
				hovercar->speed = 0;
			}
		}
	}

	if (hovercar->speed != 0.0f) {
		sp190 = hovercar->roty;
		sp18c = hovercar->rotx;
		sp188 = hovercar->rotz;

		sp184 = hovercar->turnyspeed60;
		sp180 = hovercar->turnxspeed60;

		sp194.x = sinf(hovercar->roty) * cosf(hovercar->rotx);
		sp194.y = sinf(hovercar->rotx);
		sp194.z = cosf(hovercar->roty) * cosf(hovercar->rotx);

		if (posIsMovingTowardsPosOrStoppedInRange(&prop->pos, &sp194, &sp214, sp1f4)) {
			sp200 = hovercar->roty;
			sp1fc = hovercar->rotx;
		}

		applyRotation(&sp190, sp200, &sp184, HOVVALUE1(), HOVVALUE1() * 2.0f, HOVVALUE2());

		if (sp190 == sp200 && HOVVALUE1() * 2.0f >= sp184 && -HOVVALUE1() * 2.0f <= sp184) {
			sp184 = 0;
		}

		applyRotation(&sp18c, sp1fc, &sp180, HOVVALUE1(), HOVVALUE1() * 2.0f, HOVVALUE2());

		if (sp18c == sp1fc && HOVVALUE1() * 2.0f >= sp180 && -HOVVALUE1() * 2.0f <= sp180) {
			sp180 = 0;
		}

		if (hovercar->base.flags & OBJFLAG_80000000) {
			sp188 = 0;
		} else {
			sp188 += (-sp184 * 120 - sp188) * 0.1f;
		}

		sp12c.x = active ? M_BADTAU - sp18c : 0;
		sp12c.y = sp190;
		sp12c.z = 0;

		if (sp188 >= 0) {
			mtx4LoadZRotation(sp188, &sp6c);
		} else {
			mtx4LoadZRotation(sp188 + M_BADTAU, &sp6c);
		}

		mtx4LoadRotation(&sp12c, &spac);
		mtx00015f04(hovercar->base.model->scale, &spac);
		mtx4MultMtx4(&spac, &sp6c, &spec);
		mtx4ToMtx3(&spec, sp15c);
		mtx3Copy(sp15c, hovercar->base.realrot);

		sp138 = cosf(sp18c);

		sp194.x = sinf(sp190) * sp138;
		sp194.y = active ? sinf(sp1fc) : sinf(sp18c);
		sp194.z = cosf(sp190) * sp138;

		sp150.x = prop->pos.x + sp194.f[0] * (hovercar->speed * g_Vars.lvupdate60freal);
		sp150.y = prop->pos.y + sp194.f[1] * (hovercar->speed * g_Vars.lvupdate60freal);
		sp150.z = prop->pos.z + sp194.f[2] * (hovercar->speed * g_Vars.lvupdate60freal);

		func0f065e74(&prop->pos, prop->rooms, &sp150, sp140);

		if (active) {
			sp150.y = cdFindGroundAtCyl(&sp150, 5, sp140, NULL, NULL) + 35;

			if (sp150.y < -100000) {
				sp150.y = prop->pos.y + sp194.f[1] * (hovercar->speed * g_Vars.lvupdate60freal);
			}
		}

		prop->pos = sp150;

		propDeregisterRooms(prop);
		roomsCopy(sp140, prop->rooms);

		hovercar->roty = sp190;
		hovercar->rotx = sp18c;
		hovercar->rotz = sp188;
		hovercar->turnyspeed60 = sp184;
		hovercar->turnxspeed60 = sp180;

		if (hovercar->path) {
			if (hovercar->path->pads[hovercar->nextstep + 1] >= 0) {
				if (posIsArrivingLaterallyAtPos(&prop->pos, &sp150, &sp214, hovercar->speed * sp1f4)) {
					hovercarIncrementStep(hovercar);
				}
			} else {
				if (posIsArrivingLaterallyAtPos(&prop->pos, &sp150, &sp214, hovercar->speed * sp1f4)) {
					hovercarIncrementStep(hovercar);
				}
			}
		}

		func0f069c70(&hovercar->base, false, true);
	}
}

static void hoverpropTick(struct prop *prop, bool arg1)
{
	struct hoverpropobj *obj = (struct hoverpropobj *)prop->obj;

	if ((obj->base.hidden & OBJHFLAG_GRABBED) == 0
			&& (arg1 || (prop->flags & PROPFLAG_ONANYSCREENPREVTICK) || (obj->base.flags & OBJFLAG_CHOPPER_INACTIVE))) {
		hovTick(&obj->base, &obj->hov);
	}
}

static void hoverbikeTick(struct prop *prop, bool arg1)
{
	struct hoverbikeobj *obj = (struct hoverbikeobj *)prop->obj;

	if ((obj->base.hidden & OBJHFLAG_MOUNTED) == 0) {
		if ((obj->base.hidden & OBJHFLAG_GRABBED) == 0
				&& (arg1 || (prop->flags & PROPFLAG_ONANYSCREENPREVTICK))) {
			hovTick(&obj->base, &obj->hov);
		}

		if (obj->base.flags & OBJFLAG_HOVERBIKE_MOVINGWHILEEMPTY) {
			hoverbikeUpdateMovement(obj, 0, 0, 0);
		}
	}
}

/**
 * Show or hide the CI dropship's interior features depending on whether the
 * dropship object's deactivated flag is set.
 */
static void dropshipUpdateInterior(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;
	struct model *model = obj->model;

	struct modelnode *node = modelGetPart(model->filedata, MODELPART_DROPSHIP_INTERIOR);

	if (node) {
		union modelrwdata *data = modelGetNodeRwData(model, node);
		u32 flags = obj->flags;

		data->toggle.visible = (flags & OBJFLAG_DEACTIVATED) == 0;
	}
}

static void glassUpdatePortal(struct prop *prop, s32 playercount, bool *arg2)
{
	struct tintedglassobj *glass = (struct tintedglassobj *) prop->obj;

	if (g_TintedGlassEnabled) {
		glass->opacity = 255;
	} else {
		glass->opacity = glassCalculateOpacity(&prop->pos, glass->xludist, glass->opadist, glass->unk64);
	}

	if (glass->portalnum >= 0 && playercount == 1) {
		if (glass->opacity == 255) {
			portalSetOpen(glass->portalnum, false);
		} else {
			portalSetOpen(glass->portalnum, true);
		}
	}

	*arg2 = false;
}

static void weaponInitMatrices(struct prop *prop)
{
	struct weaponobj *weapon = prop->weapon;
	struct model *model = weapon->base.model;
	s32 i = 1;
	Mtxf *mtxes = model->matrices;
	Mtxf *ptr = &mtxes[i];

	for (; i < model->filedata->nummatrices; i++) {
		mtx4LoadIdentity(ptr);
		ptr++;
	}
}

static void objInitMatrices(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;
	Mtxf mtx;

	if (obj->type == OBJTYPE_DOOR) {
		doorInitMatrices(prop);
	} else {
		mtx3ToMtx4(obj->realrot, &mtx);
		mtx4SetTranslation(&prop->pos, &mtx);
		mtx00015be4(g_Vars.currentplayer->worldtoscreenmtx, &mtx, obj->model->matrices);

		if (obj->type == OBJTYPE_CCTV) {
			cctvInitMatrices(prop, &mtx);
		} else if (obj->type == OBJTYPE_AUTOGUN) {
			autogunInitMatrices(prop, &mtx);
		} else if (obj->type == OBJTYPE_CHOPPER) {
			chopperInitMatrices(prop);
		} else if (obj->type == OBJTYPE_WEAPON) {
			weaponInitMatrices(prop);
		} else {
			if (obj->model->filedata->nummatrices >= 2) {
				struct modelrenderdata thing = {NULL, 1, 3};
				u32 stack;
				Mtxf sp28;

				mtx4Copy(obj->model->matrices, &sp28);

				thing.unk10 = obj->model->matrices;
				thing.unk00 = &sp28;

				model0001ce64(&thing, obj->model);
			}
		}
	}
}

void objTick(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;
	bool silent = false;
	bool regenning;
	u32 cmdindex;
	u32 padnum;
	struct defaultobj *newparent;

	if (prop->timetoregen > 0) {
		// Prop is taken/unavailable
		regenning = true;

		if (prop->timetoregen >= TICKS(60)) {
			regenning = false;
		}

		prop->timetoregen -= g_Vars.lvupdate60;

		if (prop->timetoregen <= 0) {
			// Prop has finished fading in
			prop->timetoregen = 0;

			if (obj->hidden2 & OBJH2FLAG_10) {
				obj->hidden |= OBJHFLAG_00001000;
			} else {
				obj->hidden &= ~OBJHFLAG_00001000;
			}
		} else if (prop->timetoregen < TICKS(60) && !regenning) {
			// 1 second left - time to start fading in
			if (obj->damage == 0 && (obj->hidden2 & OBJH2FLAG_DESTROYED) == 0) {
				if (obj->flags & OBJFLAG_INSIDEANOTHEROBJ) {
					propDeregisterRooms(prop);
					propDelist(prop);
					obj->hidden &= ~OBJHFLAG_00000800;
					cmdindex = setupGetCmdIndexByProp(prop);

					// Find the parent obj (pad is repurposed here)
					padnum = obj->pad;
					newparent = setupGetObjByCmdIndex(cmdindex + padnum);

					if (newparent && newparent->prop) {
						propReparent(obj->prop, newparent->prop);
						silent = true;
					}
				} else {
					propEnable(prop);
					setup0f0923d4(obj);
					obj->hidden &= ~OBJHFLAG_00000800;
				}
			} else {
				// Object was previously damaged. Maybe glass?
				if (obj->hidden2 & OBJH2FLAG_08) {
					obj->flags |= OBJFLAG_00000100;
				} else {
					obj->flags &= ~OBJFLAG_00000100;
				}

				obj->damage = 0;
				obj->hidden2 &= ~OBJH2FLAG_DESTROYED;
				modelFreeVertices(1, obj->model);
			}

			if (obj->type == OBJTYPE_SHIELD) {
				struct shieldobj *shield = (struct shieldobj *)obj;
				shield->amount = shield->initialamount;
			}

			if (!silent) {
				// Play respawn sound
				propsnd0f0939f8(NULL, prop, SFX_REGEN, -1,
						-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
			}
		}
	}
}

/**
 * Tick the given object.
 *
 * This function is called once per player per frame. The first time it is
 * called per frame a "fulltick" is done. On consecutive calls for this tick
 * much of the logic is skipped, and only the logic specific to the current
 * player is executed.
 */
s32 objTickPlayer(struct prop *prop)
{
	bool pass;
	struct defaultobj *obj = prop->obj;
	struct model *model = obj->model;
	bool sp592 = false;
	bool pass2;
	struct prop *child;
	struct prop *next;
	s32 result = TICKOP_NONE;
	bool fulltick = false;
	u32 playercount = PLAYERCOUNT();
	bool sp564 = true;
	bool embedded = false;
	bool sp556 = false;
	bool sp552 = false;

	if (obj->hidden & OBJHFLAG_ISRETICK) {
		obj->hidden &= ~OBJHFLAG_ISRETICK;
	} else if ((obj->hidden & OBJHFLAG_PROJECTILE) && (obj->projectile->flags & PROJECTILEFLAG_SLIDING) == 0) {
		prop->flags &= ~PROPFLAG_ONTHISSCREENTHISTICK;
		obj->hidden |= OBJHFLAG_ISRETICK;
		return TICKOP_RETICK;
	}

	if (obj->hidden & OBJHFLAG_REAPABLE) {
		pass = false;

		if (obj->type == OBJTYPE_TINTEDGLASS) {
			struct tintedglassobj *glass = (struct tintedglassobj *)obj;

			if (glass->portalnum >= 0) {
				pass = PORTAL_IS_CLOSED(glass->portalnum);
				g_BgPortals[glass->portalnum].flags |= PORTALFLAG_FORCEOPEN;
			}
		} else if (obj->type == OBJTYPE_DOOR) {
			struct doorobj *door = (struct doorobj *)obj;

			if (door->portalnum >= 0) {
				pass = PORTAL_IS_CLOSED(door->portalnum);
				g_BgPortals[door->portalnum].flags |= PORTALFLAG_FORCEOPEN;
			}
		}

		if (!pass) {
			objDropRecursively(prop, true);
			objFree(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
			return TICKOP_FREE;
		}
	}

	if (prop->flags & PROPFLAG_NOTYETTICKED) {
		fulltick = true;
		prop->flags &= ~PROPFLAG_NOTYETTICKED;
	}

	if (fulltick) {
		if (obj->type == OBJTYPE_AUTOGUN) {
			struct autogunobj *autogun = (struct autogunobj *)prop->obj;

			if (autogun->beam) {
				beamTick(autogun->beam);
			}
		} else if (obj->type == OBJTYPE_CHOPPER) {
			struct chopperobj *chopper = (struct chopperobj *)prop->obj;
			beamTick(chopper->fireslotthing->beam);
		}
	}

	if (obj->hidden & OBJHFLAG_PROJECTILE) {
		struct projectile *projectile = obj->projectile;

		if (projectile->ownerprop && playermgrGetPlayerNumByProp(projectile->ownerprop) >= 0) {
			fulltick = (projectile->ownerprop == g_Vars.currentplayer->prop);
		}
	}

	if (model->anim) {
		if (g_Anims[model->anim->animnum].flags & 0x02) {
			if (g_Vars.tickmode != TICKMODE_CUTSCENE
					&& modelGetCurAnimFrame(model) >= modelGetNumAnimFrames(model) - 1) {
				modelmgrFreeAnim(model->anim);
				model->anim = NULL;
			} else {
				// In cutscene
				struct modelrenderdata sp476 = {0, 1, 3};
				Mtxf sp412;
				struct coord sp400;
				s16 sp384[8];
				struct hov *hov = NULL;

				if (fulltick) {
					s32 iVar10 = g_Vars.lvupdate240;

					if (g_Vars.tickmode == TICKMODE_CUTSCENE && iVar10 > 0 && g_Vars.cutsceneskip60ths > 0) {
						iVar10 += g_Vars.cutsceneskip60ths * 4;
					}

					model0001ee18(model, iVar10, true);
				}

				anim00023d38(model->anim->animnum);

				if ((g_Anims[model->anim->animnum].flags & 0x04)
						&& anim0002384c(model->anim->animnum, model->anim->framea) < 0) {
					sp552 = true;
				} else {
					if (fulltick) {
						model0001b3bc(model);
					}

					sp556 = true;
					sp476.unk10 = gfxAllocate(model->filedata->nummatrices * sizeof(Mtxf));
					sp476.unk00 = g_Vars.currentplayer->worldtoscreenmtx;
					model0001cebc(&sp476, model);

					if (fulltick) {
						mtx00015be4(g_Vars.currentplayer->projectionmtx, model->matrices, &sp412);
						mtx4ToMtx3(&sp412, obj->realrot);

						sp400.x = sp412.m[3][0];
						sp400.y = sp412.m[3][1];
						sp400.z = sp412.m[3][2];

						if (obj->flags3 & OBJFLAG3_00000010) {
							func0f065e98(&prop->pos, prop->rooms, &sp400, sp384);
						} else {
							func0f065e74(&prop->pos, prop->rooms, &sp400, sp384);
						}

						prop->pos = sp400;

						propDeregisterRooms(prop);
						roomsCopy(sp384, prop->rooms);

						if (obj->type == OBJTYPE_HOVERPROP) {
							hov = &((struct hoverpropobj *)obj)->hov;
						} else if (obj->type == OBJTYPE_HOVERBIKE) {
							hov = &((struct hoverbikeobj *)obj)->hov;
						}

						if (hov) {
							hovUpdateGround(obj, hov, &prop->pos, prop->rooms, obj->realrot);
							hoverpropSetTurnAngle(obj, atan2f(sp412.m[2][0], sp412.m[2][2]));

							hov->unk14 = 0;
							hov->unk1c = 0;
							hov->unk20 = 0;
							hov->unk28 = 0;
							hov->unk30 = hov->ground;
							hov->unk04 = prop->pos.y - hov->ground;
							hov->unk0c = 0;
						}

						if ((obj->flags & OBJFLAG_IGNOREFLOORCOLOUR) == 0) {
							cdFindFloorYColourTypeAtPos(&prop->pos, prop->rooms, &obj->floorcol, 0);
						}

						func0f069c70(obj, true, true);

						if (obj->type == OBJTYPE_LIFT) {
							liftUpdateTiles((struct liftobj *)obj, false);
						}

						sp592 = true;
					}
				}
			}
		} else {
			struct modelrenderdata sp312 = {0, 1, 3};
			Mtxf sp248;
			struct coord sp236;
			s16 sp220[8];
			s32 numchrs;
			Mtxf sp152;
			s32 sp148;
			s32 sp144;
			s32 i;
			struct coord sp128;
			struct coord sp116 = {0, 0, 0};
			f32 sp112;
			s32 tagnum;
			struct geo *geos[2];
			u8 *end;
			f32 damage;

			if (fulltick) {
				sp148 = floorf(model->anim->frame);
				sp148++;
				model0001ee18(model, g_Vars.lvupdate240, 1);
				sp144 = floorf(model->anim->frame);

				for (i = sp148; i <= sp144; i++) {
					anim00024b64(0, 0, model->filedata->skel, model->anim->animnum, i, &sp128, 0);

					sp116.x += sp128.x * 0.1f;
					sp112 = sp128.y * 0.1f;
					sp116.z += sp128.z * 0.1f;
				}

				mtx00016208(obj->realrot, &sp116);
			}

			mtx3ToMtx4(obj->realrot, &sp248);
			mtx4SetTranslation(&prop->pos, &sp248);
			mtx4MultMtx4(g_Vars.currentplayer->worldtoscreenmtx, &sp248, &sp152);

			sp556 = true;
			sp312.unk10 = gfxAllocate(model->filedata->nummatrices * sizeof(Mtxf));
			sp312.unk00 = &sp152;
			model0001cebc(&sp312, model);

			if (fulltick) {
				sp236.x = (f32)sp116.x + prop->pos.x;
				sp236.y = prop->pos.y;
				sp236.z = (f32)sp116.z + prop->pos.z;

				if (obj->flags3 & OBJFLAG3_00000010) {
					func0f065e98(&prop->pos, prop->rooms, &sp236, sp220);
				} else {
					func0f065e74(&prop->pos, prop->rooms, &sp236, sp220);
				}

				if (modelGetCurAnimFrame(model) >= modelGetNumAnimFrames(model) - 1) {
					modelmgrFreeAnim(model->anim);
					model->anim = NULL;
					mtx00015be4(g_Vars.currentplayer->projectionmtx, model->matrices, &sp248);
					mtx4ToMtx3(&sp248, obj->realrot);
					tagnum = objGetTagNum(obj);

					if (tagnum >= 0) {
						numchrs = g_NumChrSlots;

						for (i = 0; i < numchrs; i++) {
							if (g_ChrSlots[i].myspecial == tagnum) {
								g_ChrSlots[i].myspecial = -1;
							}
						}
					}
				}

				prop->pos.x = sp236.x;
				prop->pos.z = sp236.z;

				propDeregisterRooms(prop);
				roomsCopy(sp220, prop->rooms);

				if (sp148 <= sp144) {
					prop->pos.y = cdFindGroundAtCyl(&prop->pos, 5, prop->rooms, &obj->floorcol, NULL)
						+ func0f06a620(obj) + sp112;
				}

				func0f069c70(obj, true, true);
				sp592 = true;

				if (objUpdateGeometry(prop, (u8 **)geos, &end)
						&& geos[0]->type == GEOTYPE_BLOCK
						&& cdTestBlockOverlapsAnyProp((struct geoblock *) geos[0], prop->rooms, CDTYPE_PLAYERS) == CDRESULT_COLLISION) {
					damage = ((obj->maxdamage - obj->damage) + 1) / 250.0f;
					obj->flags &= ~OBJFLAG_INVINCIBLE;
					objDamage(obj, damage, &prop->pos, WEAPON_REMOTEMINE, -1);
				}
			}
		}
	}

	if (fulltick) {
		if (model->anim == NULL && (obj->hidden & OBJHFLAG_PROJECTILE)) {
			sp592 = projectileTick(obj, &embedded);

			if (embedded) {
				result = TICKOP_CHANGEDLIST;
			}
		}

		if (obj->type == OBJTYPE_DOOR) {
			doorTick(prop);
		} else if (obj->type == OBJTYPE_CCTV && (obj->flags & OBJFLAG_DEACTIVATED) == 0) {
			cctvTick(prop);
		} else if (obj->type == OBJTYPE_FAN) {
			fanTick(prop);
		} else if (obj->type == OBJTYPE_AUTOGUN && (obj->flags & OBJFLAG_DEACTIVATED) == 0) {
			autogunTick(prop);
		} else if (obj->type == OBJTYPE_HOVERCAR) {
			hovercarTick(prop);
		} else if (obj->type == OBJTYPE_CHOPPER) {
			struct chopperobj *chopper = (struct chopperobj *)obj;

			if (!chopper->dead) {
				if (!g_LvIsPaused) {
					if (chopper->attackmode == CHOPPERMODE_DEAD) {
						// empty
					} else if (chopper->attackmode == CHOPPERMODE_FALL) {
						if (obj->flags & OBJFLAG_CHOPPER_INACTIVE) {
							chopper->dead = true;
						} else {
							chopperTickFall(prop);
						}
					} else if (obj->flags & OBJFLAG_CHOPPER_INACTIVE) {
						chopperTickIdle(prop);
					} else if (chopper->attackmode == CHOPPERMODE_PATROL) {
						chopperTickPatrol(prop);
					} else if (chopper->attackmode == CHOPPERMODE_COMBAT) {
						chopperTickCombat(prop);
					}
				}
			} else {
				func0f0926bc(prop, 1, 0xffff);
			}
		} else if (obj->type == OBJTYPE_HOVERPROP) {
			hoverpropTick(prop, sp592);
		} else if (obj->type == OBJTYPE_HOVERBIKE) {
			hoverbikeTick(prop, sp592);
		}
	}

	if (obj->type == OBJTYPE_TINTEDGLASS) {
		glassUpdatePortal(prop, playercount, &sp564);
	} else if (obj->type == OBJTYPE_DOOR) {
		doorUpdatePortalIfWindowed(prop, playercount);
	}

	if (sp552) {
		pass2 = false;
	} else if (prop == bmoveGetHoverbike() || prop == bmoveGetGrabbedProp()) {
		pass2 = posIsInDrawDistance(&prop->pos);
	} else if (obj->flags2 & OBJFLAG2_04000000) {
		pass2 = posIsInDrawDistance(&prop->pos);
	} else if ((obj->hidden & OBJHFLAG_00000800) == 0 && (obj->flags2 & OBJFLAG2_INVISIBLE) == 0) {
		pass2 = func0f08e8ac(prop, &prop->pos, model0001af80(model), sp564);
	} else {
		pass2 = false;
	}

	if (pass2) {
		if (sp592 == false) {
			propCalculateShadeInfo(prop, obj->nextcol, obj->floorcol);
		}

		if (fulltick) {
			if (prop->flags & PROPFLAG_ONANYSCREENPREVTICK) {
				colourTween(obj->shadecol, obj->nextcol);
			} else {
				obj->shadecol[0] = obj->nextcol[0];
				obj->shadecol[1] = obj->nextcol[1];
				obj->shadecol[2] = obj->nextcol[2];
				obj->shadecol[3] = obj->nextcol[3];
			}
		}

		prop->flags |= PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONTHISSCREENTHISTICK;

		if (obj->type == OBJTYPE_FAN) {
			fanUpdateModel(prop);
		} else if (obj->model->filedata->skel == &g_SkelDropship) {
			dropshipUpdateInterior(prop);
		}

		if (sp556 == false) {
			model->matrices = gfxAllocate(model->filedata->nummatrices * sizeof(Mtxf));
			objInitMatrices(prop);
			model0001cb0c(model, model->filedata->rootnode);
		}

		prop->z = -model->matrices[0].m[3][2];
		func0f07063c(prop, fulltick);
		child = prop->child;

		while (child) {
			next = child->next;
			func0f07079c(child, fulltick);
			child = next;
		}
	} else {
		prop->flags &= ~PROPFLAG_ONTHISSCREENTHISTICK;
		func0f07063c(prop, fulltick);
		child = prop->child;

		while (child) {
			next = child->next;
			func0f0706f8(child, fulltick);
			child = next;
		}
	}

	if (obj->hidden & OBJHFLAG_00000100) {
		obj->hidden &= ~OBJHFLAG_00000100;
		objDamage(obj, RANDOMFRAC() * 4.0f + 2.0f, &prop->pos, WEAPON_NONE, (obj->hidden & 0xf0000000) >> 28);
	}

	if (fulltick) {
		if (obj->type == OBJTYPE_AUTOGUN) {
			autogunTickShoot(prop);
		}

		objDropRecursively(prop, false);
	}

	return result;
}

Gfx *propsRenderBeams(Gfx *gdl)
{
	struct prop *prop = g_Vars.activeprops;

	while (prop) {
		if (prop->type == PROPTYPE_CHR) {
			struct chrdata *chr = prop->chr;

			if (CHRRACE(chr) == RACE_ROBOT) {
				gdl = beamRender(gdl, chr->unk348[0]->beam, true, true);
				gdl = beamRender(gdl, chr->unk348[1]->beam, true, true);
			} else {
				if (chr->fireslots[0] >= 0) {
					gdl = beamRender(gdl, &g_Fireslots[chr->fireslots[0]].beam, true, false);
				}

				if (chr->fireslots[1] >= 0) {
					gdl = beamRender(gdl, &g_Fireslots[chr->fireslots[1]].beam, true, false);
				}
			}
		} else if (prop->type == PROPTYPE_OBJ) {
			struct defaultobj *obj = prop->obj;

			if (obj->type == OBJTYPE_AUTOGUN) {
				struct autogunobj *autogun = (struct autogunobj *)prop->obj;
				gdl = beamRender(gdl, autogun->beam, true, false);
			} else if (obj->type == OBJTYPE_CHOPPER) {
				struct chopperobj *chopper = (struct chopperobj *)prop->obj;
				gdl = beamRender(gdl, chopper->fireslotthing->beam, true, true);
			}
		} else if (prop->type == PROPTYPE_PLAYER) {
			if (prop->chr && playermgrGetPlayerNumByProp(prop) != g_Vars.currentplayernum) {
				struct chrdata *chr = prop->chr;

				if (chr->fireslots[0] >= 0) {
					gdl = beamRender(gdl, &g_Fireslots[chr->fireslots[0]].beam, true, false);
				}

				if (chr->fireslots[1] >= 0) {
					gdl = beamRender(gdl, &g_Fireslots[chr->fireslots[1]].beam, true, false);
				}
			}
		}

		prop = prop->next;
	}

	return gdl;
}

static void tvscreenSetCmdlist(struct tvscreen *screen, u32 *cmdlist)
{
	screen->cmdlist = cmdlist;
	screen->offset = 0;
}

u32 g_TvCmdlist00[] = {
	tvcmd_settexture(29),
	tvcmd_setcolour(0x008000ff, 1),
	tvcmd_scrollrely(-512, 80),
	tvcmd_pause(120),
	tvcmd_scrollrely(-256, 20),
	tvcmd_pause(120),
	tvcmd_scrollrely(-128, 10),
	tvcmd_pause(40),
	tvcmd_scrollrely(-512, 40),
	tvcmd_pause(60),
	tvcmd_scrollrely(-64, 30),
	tvcmd_pause(120),
	tvcmd_restart(),
};

u32 g_TvCmdlist01[] = {
	tvcmd_setcolour(0x202020ff, 1),
	tvcmd_settexture(28),
	tvcmd_scrollrelx(2048, 120),
	tvcmd_pause(120),
	tvcmd_scaleabsx(256, 1),
	tvcmd_scaleabsy(512, 60),
	tvcmd_scrollrelx(-8192, 120),
	tvcmd_pause(120),
	tvcmd_scaleabsx(1024, 1),
	tvcmd_scaleabsy(1024, 60),
	tvcmd_scaleabsy(1024, 60),
	tvcmd_scrollrelx(2048, 120),
	tvcmd_pause(120),
	tvcmd_scaleabsx(128, 1),
	tvcmd_scaleabsy(2048, 60),
	tvcmd_scaleabsy(1024, 120),
	tvcmd_scrollrely(1024, 60),
	tvcmd_scrollrelx(512, 120),
	tvcmd_pause(120),
	tvcmd_restart(),
};

u32 g_TvCmdlist02[] = {
	tvcmd_setcolour(0x202020ff, 1),
	tvcmd_settexture(28),
	tvcmd_scaleabsx(128, 1),
	tvcmd_scaleabsy(2048, 60),
	tvcmd_scaleabsy(1024, 120),
	tvcmd_scrollrely(1024, 10),
	tvcmd_scrollrelx(512, 40),
	tvcmd_pause(120),
	tvcmd_restart(),
};

u32 g_TvCmdlist03[] = {
	tvcmd_settexture(29),
	tvcmd_setcolour(0x008000ff, 1),
	tvcmd_scrollrely(-512, 80),
	tvcmd_pause(120),
	tvcmd_scrollrely(-256, 20),
	tvcmd_pause(120),
	tvcmd_scrollrely(-128, 10),
	tvcmd_pause(40),
	tvcmd_scrollrely(-512, 40),
	tvcmd_pause(60),
	tvcmd_scrollrely(-64, 30),
	tvcmd_pause(120),
	tvcmd_restart(),
};

u32 g_TvCmdlist15[] = {
	tvcmd_settexture(50),
	tvcmd_setcolour(0x008000fe, 1),
	tvcmd_scrollrely(-512, 80),
	tvcmd_pause(120),
	tvcmd_scrollrely(-256, 20),
	tvcmd_pause(120),
	tvcmd_scrollrely(-128, 10),
	tvcmd_pause(40),
	tvcmd_scrollrely(-512, 40),
	tvcmd_pause(60),
	tvcmd_scrollrely(-64, 30),
	tvcmd_pause(120),
	tvcmd_restart(),
};

u32 g_TvCmdlist04[] = {
	tvcmd_settexture(29),
	tvcmd_setcolour(0x280000ff, 1),
	tvcmd_scrollrely(512, 80),
	tvcmd_pause(120),
	tvcmd_scrollrely(256, 20),
	tvcmd_pause(120),
	tvcmd_scrollrely(128, 10),
	tvcmd_pause(40),
	tvcmd_scrollrely(512, 40),
	tvcmd_pause(60),
	tvcmd_scrollrely(64, 30),
	tvcmd_pause(120),
	tvcmd_scrollrely(256, 20),
	tvcmd_pause(120),
	tvcmd_scrollrely(128, 10),
	tvcmd_restart(),
};

u32 g_TvCmdlist05[] = {
	tvcmd_settexture(29),
	tvcmd_setcolour(0x003c00ff, 1),
	tvcmd_scrollrely(512, 80),
	tvcmd_pause(120),
	tvcmd_scrollrely(128, 10),
	tvcmd_pause(40),
	tvcmd_scrollrely(256, 20),
	tvcmd_pause(120),
	tvcmd_scrollrely(128, 10),
	tvcmd_pause(40),
	tvcmd_scrollrely(512, 40),
	tvcmd_pause(60),
	tvcmd_scrollrely(64, 30),
	tvcmd_pause(120),
	tvcmd_restart(),
};

u32 g_TvCmdlist06[] = {
	tvcmd_settexture(30),
	tvcmd_setcolour(0x404000ff, 1),
	tvcmd_scrollrelx(640, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist07[] = {
	tvcmd_settexture(30),
	tvcmd_setcolour(0x004040ff, 1),
	tvcmd_scrollrelx(640, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist08[] = {
	tvcmd_settexture(30),
	tvcmd_setcolour(0x008000ff, 1),
	tvcmd_scrollrelx(-640, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist0F[] = {
	tvcmd_settexture(49),
	tvcmd_scaleabsx(512, 0),
	tvcmd_scaleabsy(512, 0),
	tvcmd_setcolour(0xdc2828ff, 60),
	tvcmd_pause(60),
	tvcmd_setcolour(0x323232ff, 10),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist10[] = {
	tvcmd_settexture(49),
	tvcmd_scaleabsx(512, 0),
	tvcmd_scaleabsy(512, 0),
	tvcmd_setcolour(0x32c832ff, 60),
	tvcmd_pause(60),
	tvcmd_setcolour(0x323232ff, 10),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist11[] = {
	tvcmd_settexture(49),
	tvcmd_scaleabsx(512, 0),
	tvcmd_scaleabsy(512, 0),
	tvcmd_setcolour(0x323232ff, 10),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist12[] = {
	tvcmd_settexture(49),
	tvcmd_scaleabsx(512, 0),
	tvcmd_scaleabsy(512, 0),
	tvcmd_setcolour(0xdc2828ff, 10),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist13[] = {
	tvcmd_settexture(49),
	tvcmd_scaleabsx(512, 0),
	tvcmd_scaleabsy(512, 0),
	tvcmd_setcolour(0x32c832ff, 10),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist16[] = {
	tvcmd_settexture(51),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist17[] = {
	tvcmd_settexture(72),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist18[] = {
	tvcmd_settexture(73),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist19[] = {
	tvcmd_settexture(74),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist1A[] = {
	tvcmd_settexture(75),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist1B[] = {
	tvcmd_settexture(76),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist1C[] = {
	tvcmd_settexture(77),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist24[] = {
	tvcmd_setcolour(0x000000ff, 1),
	tvcmd_settexture(75),
	tvcmd_pause(1),
	tvcmd_setcolour(0xffffffff, 180),
	tvcmd_pause(360),
	tvcmd_setcolour(0x000000ff, 30),
	tvcmd_pause(30),
	tvcmd_settexture(76),
	tvcmd_pause(1),
	tvcmd_setcolour(0xffffffff, 180),
	tvcmd_pause(360),
	tvcmd_setcolour(0x000000ff, 30),
	tvcmd_pause(30),
	tvcmd_settexture(77),
	tvcmd_pause(1),
	tvcmd_setcolour(0xffffffff, 180),
	tvcmd_pause(360),
	tvcmd_setcolour(0x000000ff, 29),
	tvcmd_pause(29),
	tvcmd_restart(),
};

u32 g_TvCmdlist1D[] = {
	tvcmd_settexture(78),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist25[] = {
	tvcmd_settexture(83),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist26[] = {
	tvcmd_settexture(84),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist27[] = {
	tvcmd_settexture(85),
	tvcmd_setcolour(0x008000ff, 1),
	tvcmd_scrollrely(-512, 80),
	tvcmd_pause(80),
	tvcmd_restart(),
};

u32 g_TvCmdlist28[] = {
	tvcmd_settexture(85),
	tvcmd_setcolour(0x0032c8ff, 1),
	tvcmd_scrollrely(512, 80),
	tvcmd_pause(80),
	tvcmd_restart(),
};

u32 g_TvCmdlist29[] = {
	tvcmd_settexture(86),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist2A[] = {
	tvcmd_settexture(86),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_scrollrely(-512, 80),
	tvcmd_pause(80),
	tvcmd_restart(),
};

u32 g_TvCmdlist2B[] = {
	tvcmd_settexture(87),
	tvcmd_setcolour(0x008000ff, 1),
	tvcmd_scrollrely(-512, 80),
	tvcmd_pause(80),
	tvcmd_restart(),
};

u32 g_TvCmdlist2C[] = {
	tvcmd_settexture(87),
	tvcmd_setcolour(0x0032c8ff, 1),
	tvcmd_scrollrely(512, 80),
	tvcmd_pause(80),
	tvcmd_restart(),
};

u32 g_TvCmdlist2D[] = {
	tvcmd_settexture(88),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist2E[] = {
	tvcmd_settexture(89),
	tvcmd_setcolour(0x007f00ff, 1),
	tvcmd_scrollrely(-512, 80),
	tvcmd_pause(120),
	tvcmd_scrollrely(-256, 20),
	tvcmd_pause(120),
	tvcmd_scrollrely(-128, 10),
	tvcmd_pause(40),
	tvcmd_scrollrely(-512, 40),
	tvcmd_pause(60),
	tvcmd_scrollrely(-64, 30),
	tvcmd_pause(120),
	tvcmd_restart(),
};

u32 g_TvCmdlist2F[] = {
	tvcmd_settexture(89),
	tvcmd_setcolour(0xff7f00ff, 1),
	tvcmd_scrollrely(512, 80),
	tvcmd_pause(120),
	tvcmd_scrollrely(256, 20),
	tvcmd_pause(120),
	tvcmd_scrollrely(128, 10),
	tvcmd_pause(40),
	tvcmd_scrollrely(512, 40),
	tvcmd_pause(60),
	tvcmd_scrollrely(64, 30),
	tvcmd_pause(120),
	tvcmd_restart(),
};

u32 g_TvCmdlist30[] = {
	tvcmd_settexture(90),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist31[] = {
	tvcmd_settexture(91),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist32[] = {
	tvcmd_settexture(92),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist33[] = {
	tvcmd_setcolour(0x000000ff, 1),
	tvcmd_settexture(90),
	tvcmd_pause(1),
	tvcmd_setcolour(0xffffffff, 180),
	tvcmd_pause(360),
	tvcmd_setcolour(0x000000ff, 30),
	tvcmd_pause(30),
	tvcmd_settexture(91),
	tvcmd_pause(1),
	tvcmd_setcolour(0xffffffff, 180),
	tvcmd_pause(360),
	tvcmd_setcolour(0x000000ff, 30),
	tvcmd_pause(30),
	tvcmd_settexture(92),
	tvcmd_pause(1),
	tvcmd_setcolour(0xffffffff, 180),
	tvcmd_pause(360),
	tvcmd_setcolour(0x000000ff, 29),
	tvcmd_pause(29),
	tvcmd_restart(),
};

u32 g_TvCmdlist34[] = {
	tvcmd_settexture(93),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist35[] = {
	tvcmd_settexture(94),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist36[] = {
	tvcmd_settexture(95),
	tvcmd_setcolour(0xffffffff, 1),
	tvcmd_pause(10),
	tvcmd_restart(),
};

u32 g_TvCmdlist14[] = {
	tvcmd_settexture(0),
	tvcmd_setcolour(0x000000ff, 0),
	tvcmd_yield(),
	// flow on to next cmdlist
};

u32 var8006aaa0[] = {
	tvcmd_scaleabsx(1024, 0),
	tvcmd_scaleabsy(1024, 0),
	tvcmd_pause(1),
	tvcmd_scaleabsx(4096, 20),
	tvcmd_scaleabsy(4096, 20),
	tvcmd_pause(20),
	tvcmd_restart(),
};

u32 var8006aae4[] = {
	tvcmd_settexture(0),
	tvcmd_scrollrelx(1024, 20),
	tvcmd_pause(20),
	tvcmd_scrollrely(1024, 20),
	tvcmd_setcolour(0x000000ff, 20),
	tvcmd_pause(20),
	tvcmd_scaleabsx(512, 20),
	tvcmd_scaleabsy(512, 20),
	tvcmd_setcolour(0xffffffff, 20),
	tvcmd_pause(20),
	tvcmd_scaleabsx(1024, 20),
	tvcmd_scaleabsy(1024, 20),
	tvcmd_pause(20),
	tvcmd_restart(),
};

void tvscreenSetImageByNum(struct tvscreen *screen, s32 imagenum)
{
	u32 *image = g_TvCmdlist00;

	switch (imagenum) {
	case TVCMDLIST_01: image = g_TvCmdlist01; break;
	case TVCMDLIST_02: image = g_TvCmdlist02; break;
	case TVCMDLIST_03: image = g_TvCmdlist03; break;
	case TVCMDLIST_04: image = g_TvCmdlist04; break;
	case TVCMDLIST_05: image = g_TvCmdlist05; break;
	case TVCMDLIST_06: image = g_TvCmdlist06; break;
	case TVCMDLIST_07: image = g_TvCmdlist07; break;
	case TVCMDLIST_08: image = g_TvCmdlist08; break;
	case TVCMDLIST_09: image = g_TvCmdlist03; break;
	case TVCMDLIST_0A: image = g_TvCmdlist03; break;
	case TVCMDLIST_0B: image = g_TvCmdlist03; break;
	case TVCMDLIST_0C: image = g_TvCmdlist03; break;
	case TVCMDLIST_0D: image = g_TvCmdlist03; break;
	case TVCMDLIST_0E: image = g_TvCmdlist03; break;
	case TVCMDLIST_0F: image = g_TvCmdlist0F; break;
	case TVCMDLIST_10: image = g_TvCmdlist10; break;
	case TVCMDLIST_11: image = g_TvCmdlist11; break;
	case TVCMDLIST_12: image = g_TvCmdlist12; break;
	case TVCMDLIST_13: image = g_TvCmdlist13; break;
	case TVCMDLIST_14: image = g_TvCmdlist14; break;
	case TVCMDLIST_15: image = g_TvCmdlist15; break;
	case TVCMDLIST_16: image = g_TvCmdlist16; break;
	case TVCMDLIST_17: image = g_TvCmdlist17; break;
	case TVCMDLIST_18: image = g_TvCmdlist18; break;
	case TVCMDLIST_19: image = g_TvCmdlist19; break;
	case TVCMDLIST_1A: image = g_TvCmdlist1A; break;
	case TVCMDLIST_1B: image = g_TvCmdlist1B; break;
	case TVCMDLIST_1C: image = g_TvCmdlist1C; break;
	case TVCMDLIST_1D: image = g_TvCmdlist1D; break;
	case TVCMDLIST_24: image = g_TvCmdlist24; break;
	case TVCMDLIST_1E: image = g_TvCmdlist08; break;
	case TVCMDLIST_1F: image = g_TvCmdlist08; break;
	case TVCMDLIST_20: image = g_TvCmdlist08; break;
	case TVCMDLIST_21: image = g_TvCmdlist08; break;
	case TVCMDLIST_22: image = g_TvCmdlist08; break;
	case TVCMDLIST_23: image = g_TvCmdlist08; break;
	case TVCMDLIST_25: image = g_TvCmdlist25; break;
	case TVCMDLIST_26: image = g_TvCmdlist26; break;
	case TVCMDLIST_27: image = g_TvCmdlist27; break;
	case TVCMDLIST_28: image = g_TvCmdlist28; break;
	case TVCMDLIST_29: image = g_TvCmdlist29; break;
	case TVCMDLIST_2A: image = g_TvCmdlist2A; break;
	case TVCMDLIST_2B: image = g_TvCmdlist2B; break;
	case TVCMDLIST_2C: image = g_TvCmdlist2C; break;
	case TVCMDLIST_2D: image = g_TvCmdlist2D; break;
	case TVCMDLIST_2E: image = g_TvCmdlist2E; break;
	case TVCMDLIST_2F: image = g_TvCmdlist2F; break;
	case TVCMDLIST_30: image = g_TvCmdlist30; break;
	case TVCMDLIST_31: image = g_TvCmdlist31; break;
	case TVCMDLIST_32: image = g_TvCmdlist32; break;
	case TVCMDLIST_33: image = g_TvCmdlist33; break;
	case TVCMDLIST_34: image = g_TvCmdlist34; break;
	case TVCMDLIST_35: image = g_TvCmdlist35; break;
	case TVCMDLIST_36: image = g_TvCmdlist36; break;
	case TVCMDLIST_00:
		break;
	}

	tvscreenSetCmdlist(screen, image);
}

struct tvcmd {
	u32 type;
	s32 arg1;
	u32 arg2;
};

static Gfx *tvscreenRender(struct model *model, struct modelnode *node, struct tvscreen *screen, Gfx *gdl, s32 arg4, s32 arg5)
{
	if (node && (node->type & 0xff) == MODELNODETYPE_DL) {
		struct gfxvtx *vertices = gfxAllocateVertices(4); // b4
		struct colour *colours = gfxAllocateColours(1); // b0
		Gfx *savedgdl = gdl++; // ac
		union modelrodata *rodata = node->rodata; // a8
		union modelrwdata *rwdata = modelGetNodeRwData(model, node); // a4
		struct textureconfig *tconfig;
		bool yielding = false;

		while (!yielding) {
			struct tvcmd *cmd = (struct tvcmd *) &screen->cmdlist[screen->offset]; // 98

			switch (cmd->type) {
			case TVCMD_STOPSCROLL:
				screen->xmidinc = 0.0f;
				screen->ymidinc = 0.0f;
				screen->offset++;
				break;
			case TVCMD_SCROLLRELX:
				screen->xmidfrac = 0.0f;
				screen->xmidinc = cmd->arg2 == 0 ? 1.0f : 1.0f / cmd->arg2;
				screen->xmidold = screen->xmid;
				screen->xmidnew = screen->xmid + cmd->arg1 * (1.0f / 1024.0f);
				screen->offset += 3;
				break;
			case TVCMD_SCROLLRELY:
				screen->ymidfrac = 0.0f;
				screen->ymidinc = cmd->arg2 == 0 ? 1.0f : 1.0f / cmd->arg2;
				screen->ymidold = screen->ymid;
				screen->ymidnew = screen->ymid + cmd->arg1 * (1.0f / 1024.0f);
				screen->offset += 3;
				break;
			case TVCMD_SCROLLABSX:
				screen->xmidfrac = 0.0f;
				screen->xmidinc = cmd->arg2 == 0 ? 1.0f : 1.0f / cmd->arg2;
				screen->xmidold = screen->xmid;
				screen->xmidnew = cmd->arg1 * (1.0f / 1024.0f);
				screen->offset += 3;
				break;
			case TVCMD_SCROLLABSY:
				screen->ymidfrac = 0.0f;
				screen->ymidinc = cmd->arg2 == 0 ? 1.0f : 1.0f / cmd->arg2;
				screen->ymidold = screen->ymid;
				screen->ymidnew = cmd->arg1 * (1.0f / 1024.0f);
				screen->offset += 3;
				break;
			case TVCMD_SCALEABSX:
				screen->xscalefrac = 0.0f;
				screen->xscaleinc = cmd->arg2 == 0 ? 1.0f : 1.0f / cmd->arg2;
				screen->xscaleold = screen->xscale;
				screen->xscalenew = cmd->arg1 * (1.0f / 1024.0f);
				screen->offset += 3;
				break;
			case TVCMD_SCALEABSY:
				screen->yscalefrac = 0.0f;
				screen->yscaleinc = cmd->arg2 == 0 ? 1.0f : 1.0f / cmd->arg2;
				screen->yscaleold = screen->yscale;
				screen->yscalenew = cmd->arg1 * (1.0f / 1024.0f);
				screen->offset += 3;
				break;
			case TVCMD_SETTEXTURE:
				screen->tconfig = (struct textureconfig *)cmd->arg1;
				screen->offset += 2;
				break;
			case TVCMD_PAUSE:
				if (screen->pause60 >= 0) {
					screen->pause60 -= g_Vars.lvupdate60;

					if (screen->pause60 >= 0) {
						yielding = true;
					} else {
						screen->offset += 2;
					}
				} else {
					yielding = true;
					screen->pause60 = cmd->arg1;
				}
				break;
			case TVCMD_SETCMDLIST:
				tvscreenSetCmdlist(screen, (u32 *) cmd->arg1);
				break;
			case TVCMD_RANDSETCMDLIST:
				if ((random() >> 16) < cmd->arg2) {
					tvscreenSetCmdlist(screen, (u32 *) cmd->arg1);
				} else {
					screen->offset += 3;
				}
				break;
			case TVCMD_RESTART:
				screen->offset = 0;
				break;
			case TVCMD_YIELD:
				yielding = true;
				break;
			case TVCMD_SETCOLOUR:
				screen->colfrac = 0.0f;
				screen->colinc = cmd->arg2 == 0 ? 1.0f : 1.0f / cmd->arg2;

				screen->redold = screen->red;
				screen->rednew = ((u32)cmd->arg1 >> 24) & 0xff;

				screen->greenold = screen->green;
				screen->greennew = ((u32)cmd->arg1 >> 16) & 0xff;

				screen->blueold = screen->blue;
				screen->bluenew = ((u32)cmd->arg1 >> 8) & 0xff;

				screen->alphaold = screen->alpha;
				screen->alphanew = cmd->arg1 & 0xff;

				screen->offset += 3;
				break;
			case TVCMD_ROTATEABS:
				screen->rot = cmd->arg1 * (M_BADTAU / 65536.0f);
				screen->offset += 2;
				break;
			case TVCMD_ROTATEREL:
				screen->rot += g_Vars.lvupdate60f * cmd->arg1 * (M_BADTAU / 65536.0f);

				if (screen->rot >= M_BADTAU) {
					screen->rot -= M_BADTAU;
				}

				if (screen->rot < 0.0f) {
					screen->rot += M_BADTAU;
				}

				screen->offset += 2;
				break;
			}
		}

		// Increment X scale
		if (screen->xscaleinc > 0.0f) {
			screen->xscalefrac += screen->xscaleinc * g_Vars.lvupdate60f;

			if (screen->xscalefrac < 1.0f) {
				screen->xscale = screen->xscaleold + (screen->xscalenew - screen->xscaleold) * screen->xscalefrac;
			} else {
				screen->xscalefrac = 1.0f;
				screen->xscaleinc = 0.0f;
				screen->xscale = screen->xscalenew;
			}
		}

		// Increment Y scale
		if (screen->yscaleinc > 0.0f) {
			screen->yscalefrac += screen->yscaleinc * g_Vars.lvupdate60f;

			if (screen->yscalefrac < 1.0f) {
				screen->yscale = screen->yscaleold + (screen->yscalenew - screen->yscaleold) * screen->yscalefrac;
			} else {
				screen->yscalefrac = 1.0f;
				screen->yscaleinc = 0.0f;
				screen->yscale = screen->yscalenew;
			}
		}

		// Increment X scroll
		if (screen->xmidinc > 0.0f) {
			screen->xmidfrac += screen->xmidinc * g_Vars.lvupdate60f;

			if (screen->xmidfrac < 1.0f) {
				screen->xmid = screen->xmidold + (screen->xmidnew - screen->xmidold) * screen->xmidfrac;
			} else {
				screen->xmidfrac = 1.0f;
				screen->xmidinc = 0.0f;
				screen->xmid = screen->xmidnew;
			}
		}

		// Increment Y scroll
		if (screen->ymidinc > 0.0f) {
			screen->ymidfrac += screen->ymidinc * g_Vars.lvupdate60f;

			if (screen->ymidfrac < 1.0f) {
				screen->ymid = screen->ymidold + (screen->ymidnew - screen->ymidold) * screen->ymidfrac;
			} else {
				screen->ymidfrac = 1.0f;
				screen->ymidinc = 0.0f;
				screen->ymid = screen->ymidnew;
			}
		}

		// Increment colour change
		if (screen->colinc > 0.0f) {
			screen->colfrac += screen->colinc * g_Vars.lvupdate60f;

			if (screen->colfrac < 1.0f) {
				screen->red = screen->redold + (s32) ((screen->rednew - screen->redold) * screen->colfrac);
				screen->green = screen->greenold + (s32) ((screen->greennew - screen->greenold) * screen->colfrac);
				screen->blue = screen->blueold + (s32) ((screen->bluenew - screen->blueold) * screen->colfrac);
				screen->alpha = screen->alphaold + (s32) ((screen->alphanew - screen->alphaold) * screen->colfrac);
			} else {
				screen->colfrac = 1.0f;
				screen->colinc = 0.0f;
				screen->red = screen->rednew;
				screen->green = screen->greennew;
				screen->blue = screen->bluenew;
				screen->alpha = screen->alphanew;
			}
		}

		// Set up everything for rendering
		rwdata->dl.gdl = gdl;
		rwdata->dl.vertices = vertices;
		rwdata->dl.colours = colours;

		vertices[0] = rodata->dl.vertices[0];
		vertices[1] = rodata->dl.vertices[1];
		vertices[2] = rodata->dl.vertices[2];
		vertices[3] = rodata->dl.vertices[3];

		if ((u32)screen->tconfig < 100) {
			tconfig = &g_TexScreenConfigs[(s32)screen->tconfig];
		} else {
			tconfig = screen->tconfig;
		}

		if (tconfig != NULL) {
			u32 stack[13];
			f32 f20;
			f32 f24;
			f32 f14; // 58
			f32 f16; // 54
			u8 stack2[0x8];
			f32 a;
			f32 b;

			f20 = screen->xscale / 2.0f;
			f24 = screen->yscale / 2.0f;
			f14 = f20;
			f16 = f24;

			if (1);
			if (1);
			if (1);
			if (1);
			if (1);

			if (screen->rot != 0.0f) {
				f32 f22;
				f32 f2;

				f22 = cosf(screen->rot) * 1.4142f;
				f2 = sinf(screen->rot) * 1.4142f;

				f20 *= f22;
				f24 *= f2;
				f14 *= f2;
				f16 *= f22;
			}

			vertices[0].s = tconfig->width * (screen->xmid + f20) * 32.0f;
			vertices[0].t = tconfig->height * (screen->ymid + f24) * 32.0f;
			vertices[1].s = tconfig->width * (screen->xmid - f14) * 32.0f;
			vertices[1].t = tconfig->height * (screen->ymid + f16) * 32.0f;
			vertices[2].s = tconfig->width * (screen->xmid - f20) * 32.0f;
			vertices[2].t = tconfig->height * (screen->ymid - f24) * 32.0f;
			vertices[3].s = tconfig->width * (screen->xmid + f14) * 32.0f;
			vertices[3].t = tconfig->height * (screen->ymid - f16) * 32.0f;
		}

		colours[0].r = screen->red;
		colours[0].g = screen->green;
		colours[0].b = screen->blue;
		colours[0].a = screen->alpha;

		vertices[0].colour = 0;
		vertices[1].colour = 0;
		vertices[2].colour = 0;
		vertices[3].colour = 0;

		if (screen->alpha < 255) {
			arg5 = 2;
		}

		// Render the image
		gSPSetGeometryMode(gdl++, G_CULL_BACK);

		if (1);

		texSelect(&gdl, tconfig, arg5, arg4, 2, 1, NULL);

		gSPMatrix(gdl++, osVirtualToPhysical(model->matrices), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
		gSPSegment(gdl++, SPSEGMENT_MODEL_VTX, osVirtualToPhysical(vertices));
		gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);
		gDPSetVerticeArray(gdl++, SPSEGMENT_MODEL_VTX << 24, 4);
		gDPTri2(gdl++, 0, 1, 2, 0, 2, 3);
		gSPEndDisplayList(gdl++);

		gSPBranchList(savedgdl++, gdl);
	}

	return gdl;
}

static void objRenderProp(struct prop *prop, struct modelrenderdata *renderdata, bool xlupass)
{
	if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		struct defaultobj *obj = prop->obj;
		struct model *model = obj->model;
		bool sp6c;
		struct prop *child;
		Gfx *gdl;
		s32 sp60;

		sp6c = 0;
		sp6c += (obj->flags & OBJFLAG_00000200) && g_Vars.currentplayer->orthomtxl;

		gdl = renderdata->gdl;

		if (obj->type == OBJTYPE_SINGLEMONITOR) {
			if (renderdata->flags & 1) {
				struct singlemonitorobj *monitor = (struct singlemonitorobj *) prop->obj;

				if (obj->flags2 & OBJFLAG2_DRAWONTOP) {
					sp60 = 0;
				} else if (obj->flags & OBJFLAG_DEACTIVATED) {
					sp60 = wallhit0f140750(&prop->pos);
				} else {
					sp60 = 1;
				}

				gdl = tvscreenRender(model, modelGetPart(model->filedata, MODELPART_0000), &monitor->screen, gdl, sp60, 1);
			}
		} else if (obj->type == OBJTYPE_MULTIMONITOR) {
			if (renderdata->flags & 1) {
				struct multimonitorobj *monitor = (struct multimonitorobj *) prop->obj;

				if (obj->flags2 & OBJFLAG2_DRAWONTOP) {
					sp60 = 0;
				} else if (obj->flags & OBJFLAG_DEACTIVATED) {
					sp60 = wallhit0f140750(&prop->pos);
				} else {
					sp60 = 1;
				}

				gdl = tvscreenRender(model, modelGetPart(model->filedata, MODELPART_0000), &monitor->screens[0], gdl, sp60, 1);

				if (obj->flags2 & OBJFLAG2_DRAWONTOP) {
					sp60 = 0;
				} else if (obj->flags & (OBJFLAG_DEACTIVATED | OBJFLAG_20000000)) {
					sp60 = wallhit0f140750(&prop->pos);
				} else {
					sp60 = 1;
				}

				gdl = tvscreenRender(model, modelGetPart(model->filedata, MODELPART_0001), &monitor->screens[1], gdl, sp60, 1);
				gdl = tvscreenRender(model, modelGetPart(model->filedata, MODELPART_0002), &monitor->screens[2], gdl, sp60, 1);
				gdl = tvscreenRender(model, modelGetPart(model->filedata, MODELPART_0003), &monitor->screens[3], gdl, sp60, 1);
			}
		}

		if (obj->type == OBJTYPE_DOOR) {
			struct doorobj *door = prop->door;

			gSPClearGeometryMode(gdl++, G_CULL_BOTH);

			if (door->doorflags & DOORFLAG_FLIP) {
				renderdata->cullmode = CULLMODE_FRONT;
			} else {
				renderdata->cullmode = CULLMODE_BACK;
			}

			if (renderdata->unk30 == 9) {
				renderdata->envcolour &= 0xffffff00;
			}
		} else if ((obj->hidden2 & OBJH2FLAG_80) == 0) {
			renderdata->cullmode = CULLMODE_BACK;

			if (renderdata->unk30 == 9) {
				renderdata->envcolour &= 0xffffff00;
			}
		} else {
			s32 level = objGetDestroyedLevel(obj);

			renderdata->cullmode = CULLMODE_NONE;

			if (renderdata->unk30 == 9) {
				s32 alpha = 100 + level * 50;

				if (alpha > 255) {
					alpha = 255;
				}

				renderdata->envcolour &= 0xffffff00;
				renderdata->envcolour |= alpha;
			} else if (level > 0) {
				renderdata->envcolour |= 0x0000ff00;
			}
		}

		if (sp6c) {
			gSPMatrix(gdl++, g_Vars.currentplayer->orthomtxl, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		}

		renderdata->gdl = gdl;
		modelRender(renderdata, model);
		gdl = renderdata->gdl;

		if (obj->type == OBJTYPE_DOOR) {
			gSPClearGeometryMode(gdl++, G_CULL_BOTH);
		}

		if (obj->hidden2 & (OBJH2FLAG_HASOPA << xlupass)) {
			gdl = wallhitRenderPropHits(gdl, prop, xlupass);
		}

		if (sp6c) {
			gSPMatrix(gdl++, g_Vars.currentplayer->perspmtxl, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		}

		renderdata->gdl = gdl;

		child = prop->child;

		while (child) {
			objRenderProp(child, renderdata, xlupass);
			child = child->next;
		}

		if (xlupass) {
			if (sp6c) {
				player0f0c3320(model->matrices, model->filedata->nummatrices);
			} else {
				func0f0c33f0(model->matrices, model->filedata->nummatrices);
			}

			if ((obj->flags3 & (OBJFLAG3_SHOWSHIELD | OBJFLAG3_SHIELDHIT)) && objIsHealthy(obj)) {
				gSPSetGeometryMode(renderdata->gdl++, G_CULL_BACK);

				renderdata->gdl = shieldhitRender(renderdata->gdl, prop, prop, 0xff, 0, 0, 1, 2, 3);
			}
		}
	}
}

Gfx *gfxRenderRadialShadow(Gfx *gdl, f32 x, f32 y, f32 z, f32 angle, f32 radius, u32 colour)
{
	Mtxf spc0;
	Mtxf sp80;
	Mtxf *mtx;
	struct gfxvtx *vertices;
	u32 *colours;
	struct coord pos;
	struct textureconfig *tconfig;
	s32 i;
	f32 base1 = 0.0f;
	f32 base2 = 0.0f;
	f32 base3 = 0.0f;
	f32 base4 = 0.0f;

	if (radius);

	vertices = gfxAllocateVertices(4);
	colours = gfxAllocateColours(1);

	tconfig = &g_TexShadowConfigs[0];

	colours[0] = colour;

	pos.x = x;
	pos.y = y + 2.0f;
	pos.z = z;

	mtx = gfxAllocateMatrix();
	mtx4LoadYRotationWithTranslation(&pos, angle, &spc0);
	mtx4MultMtx4(g_Vars.currentplayer->worldtoscreenmtx, &spc0, &sp80);
	mtx00016054(&sp80, mtx);

	for (i = 0; i < 4; i++) {
		vertices[i].y = 0;
		vertices[i].colour = 0;
	}

	vertices[0].x = base1 - radius;
	vertices[0].z = base3 - radius;
	vertices[1].x = base1 - radius;
	vertices[1].z = base4 + radius;
	vertices[2].x = base2 + radius;
	vertices[2].z = base4 + radius;
	vertices[3].x = base2 + radius;
	vertices[3].z = base3 - radius;

	if (tconfig) {
		vertices[0].s = 0;
		vertices[0].t = 0;
		vertices[1].s = tconfig->width * 32 - 1;
		vertices[1].t = 0;
		vertices[2].s = tconfig->width * 32 - 1;
		vertices[2].t = tconfig->height * 32 - 1;
		vertices[3].s = 0;
		vertices[3].t = tconfig->height * 32 - 1;

		texSelect(&gdl, tconfig, 4, 1, 2, 1, NULL);
	} else {
		texSelect(&gdl, NULL, 1, 1, 2, 1, NULL);
	}

	gSPSetGeometryMode(gdl++, G_CULL_BACK);
	gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);
	gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);

	return gdl;
}

static Gfx *objRenderShadow(struct defaultobj *obj, Gfx *gdl)
{
	f32 angle;
	f32 y;

	s32 room = cdFindFloorRoomYColourFlagsAtPos(&obj->prop->pos, obj->prop->rooms, &y, NULL, NULL);

	if (room > 0 && (obj->modelnum == MODEL_HOOVERBOT || obj->modelnum == MODEL_TESTERBOT)) {
		angle = hoverpropGetTurnAngle(obj);
		gdl = gfxRenderRadialShadow(gdl, obj->prop->pos.x, y, obj->prop->pos.z, angle, 20, 0xffffff78);
	} else if (room > 0) {
		angle = hoverpropGetTurnAngle(obj);
		gdl = gfxRenderRadialShadow(gdl, obj->prop->pos.x, y, obj->prop->pos.z, angle, 30, 0xffffff78);
	}

	return gdl;
}

Gfx *objRender(struct prop *prop, Gfx *gdl, bool xlupass)
{
	f32 spe8[4];
	s32 spe4;
	struct defaultobj *obj = prop->obj;
	struct modelrenderdata renderdata = {NULL, true, 3};
	struct screenbox screenbox;
	s32 colour[4];
	s32 sp84;
	s32 healththing;
	s32 alpha = 0xff;
	f32 xrayalphafrac;
	s32 mult;
	struct weaponobj *weapon;
	struct doorobj *door;
	f32 frac;
	struct modelnode *node;
	struct modelrodata_dl *dldata1;
	struct modelrwdata_dl *dldata2;
	f32 fadedist;
	struct colour *oldcolours;
	struct colour *newcolours;
	f32 objdist;
	s32 i;

	spe4 = env0f1667f4(prop, spe8);

	if (spe4 == 0) {
		return gdl;
	}

	if (obj->type != OBJTYPE_TINTEDGLASS) {
		frac = func0f08e6bc(prop, model0001af80(obj->model));

		if (prop->timetoregen > 0 && prop->timetoregen < TICKS(60)) {
			frac *= (TICKS(60.0f) - prop->timetoregen) * (PAL ? 0.019999999552965f : 0.016666667535901f);
		}

		alpha = frac * 255.0f;

		if (alpha <= 0) {
			return gdl;
		}
	}

	if (g_Vars.currentplayer->visionmode == VISIONMODE_NORMAL) {
		// empty
	} else if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKET) {
		if (g_Vars.currentplayer->slayerrocket
				&& g_Vars.currentplayer->slayerrocket->base.prop
				&& g_Vars.currentplayer->slayerrocket->base.prop == prop) {
			return gdl;
		}
	} else if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
		fadedist;
		objdist = sqrtf(ERASERSQDIST(prop->pos.f));

		if (objdist > g_Vars.currentplayer->eraserpropdist) {
			return gdl;
		}

		alpha = 128;
		fadedist = g_Vars.currentplayer->eraserpropdist - 150.0f;

		if (objdist > fadedist) {
			alpha = (1.0f - (objdist - fadedist) / 150.0f) * 128;
		}

		xrayalphafrac = objdist / g_Vars.currentplayer->eraserpropdist;

		if (xrayalphafrac > 1.0f) {
			xrayalphafrac = 1.0f;
		}
	}

	if (g_Vars.lvmpbotlevel && obj->type == OBJTYPE_WEAPON) {
		if (obj->flags3 & OBJFLAG3_HARDFREEING) {
			weapon = (struct weaponobj *)obj;
			alpha = ((f32)alpha * (f32)weapon->fadeouttimer60) * (PAL ? 0.019999999552965f : 0.016666667535901f);

			if (alpha < 0) {
				alpha = 0;
			} else if (alpha > 0xff) {
				alpha = 0xff;
			}
		}
	}

	if (alpha < 0xff || (obj->flags2 & OBJFLAG2_DRAWONTOP)) {
		if (!xlupass) {
			return gdl;
		}

		sp84 = 3;
	} else {
		if (!xlupass) {
			sp84 = 1;
		} else {
			sp84 = 2;
		}
	}

	if (obj->type == OBJTYPE_DOOR) {
		door = (struct doorobj *)obj;

		if (door->doortype == DOORTYPE_LASER) {
			node = func0f0687e4(obj->model);
			dldata1 = &node->rodata->dl;
			dldata2 = (struct modelrwdata_dl *) modelGetNodeRwData(obj->model, node);
			oldcolours = (struct colour *) ((((u32) &dldata1->vertices[dldata1->numvertices] + 7) | 7) ^ 7);
			newcolours = (struct colour *) gfxAllocateColours(dldata1->numcolours);

			for (i = 0; i < dldata1->numcolours; i++) {
				newcolours[i] = oldcolours[i];
				newcolours[i].a = door->laserfade;
			}

			dldata2->colours = newcolours;
		}
	}

	if ((obj->flags2 & OBJFLAG2_04000000) == 0 && func0f08e5a8(prop->rooms, &screenbox) > 0) {
		gdl = currentPlayerScissorWithinViewport(gdl, screenbox.xmin, screenbox.ymin, screenbox.xmax, screenbox.ymax);
	} else {
		gdl = currentPlayerScissorToViewport(gdl);
	}

	renderdata.flags = sp84;
	renderdata.zbufferenabled = (obj->flags2 & OBJFLAG2_DRAWONTOP) == 0;
	renderdata.gdl = gdl;

	if (alpha < 0xff) {
		renderdata.unk30 = 5;
		renderdata.envcolour = alpha;
	} else {
		renderdata.unk30 = 9;

		if (obj->type == OBJTYPE_TINTEDGLASS) {
			struct tintedglassobj *glass = (struct tintedglassobj *)obj;
			renderdata.envcolour = glass->opacity << 8;
		} else {
			if (obj->type == OBJTYPE_DOOR && ((struct doorobj *)obj)->doorflags & DOORFLAG_WINDOWED) {
				renderdata.envcolour = ((struct doorobj *)obj)->fadealpha << 8;
			} else {
				renderdata.envcolour = 0;
			}
		}
	}

	if (prop->type == PROPTYPE_DOOR
			&& (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)) {
		struct doorobj *door = prop->door;

		if (g_Vars.currentplayernum == 0) {
			colour[0] = door->shadeinfo1[0];
			colour[1] = door->shadeinfo1[1];
			colour[2] = door->shadeinfo1[2];
			colour[3] = door->shadeinfo1[3];
		} else {
			colour[0] = door->shadeinfo2[0];
			colour[1] = door->shadeinfo2[1];
			colour[2] = door->shadeinfo2[2];
			colour[3] = door->shadeinfo2[3];
		}
	} else {
		colour[0] = obj->shadecol[0];
		colour[1] = obj->shadecol[1];
		colour[2] = obj->shadecol[2];
		colour[3] = obj->shadecol[3];
	}

	if (g_Vars.normmplayerisrunning) {
		scenarioHighlightProp(prop, colour);
	}

	if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
		colour[g_Vars.currentplayer->epcol_0] = xrayalphafrac * 255.0f;
		colour[g_Vars.currentplayer->epcol_1] = (1.0f - xrayalphafrac) * 255.0f;
		colour[g_Vars.currentplayer->epcol_2] = 0;
		colour[3] = 0xff;
	} else {
		colour[3] -= func0f068fc8(obj->prop, true);
		if (colour[3]);

		if (colour[3] > 0xff) {
			colour[3] = 0xff;
		}

		if (colour[3] < 0) {
			colour[3] = 0;
		}
	}

	healththing = objGetShotsTaken(obj);
	mult = 0xff - (healththing * 21);

	if (mult < 0) {
		mult = 0;
	}

	colour[0] = (colour[0] * mult) >> 8;
	colour[1] = (colour[1] * mult) >> 8;
	colour[2] = (colour[2] * mult) >> 8;
	colour[3] += healththing * 15;

	if (colour[3] > 0xff) {
		colour[3] = 0xff;
	}

	func0f069750(colour, spe4, spe8);

	if (USINGDEVICE(DEVICE_NIGHTVISION)) {
		if ((obj->flags & OBJFLAG_PATHBLOCKER) == 0) {
			colour[0] = var8009caed;
			colour[1] = var8009caed;
			colour[2] = var8009caed;
			colour[3] = var8009caee;
		}
	} else if (USINGDEVICE(DEVICE_IRSCANNER)) {
		if ((obj->hidden & OBJHFLAG_CONDITIONALSCENERY) || (obj->flags3 & OBJFLAG3_INFRARED)) {
			colour[0] = 0xff;
			colour[1] = 0xff;
			colour[2] = 0xff;
			colour[3] = 0x46;
		}
	}

	renderdata.fogcolour = colour[0] << 24 | colour[1] << 16 | colour[2] << 8 | colour[3];
	objRenderProp(prop, &renderdata, xlupass);

	gdl = renderdata.gdl;

	if (xlupass) {
		if (obj->type == OBJTYPE_HOVERPROP
				|| obj->type == OBJTYPE_HOVERBIKE
				|| obj->modelnum == MODEL_HOOVERBOT
				|| obj->modelnum == MODEL_TESTERBOT) {
			gdl = objRenderShadow(obj, gdl);
		}

		if (obj->modelnum == MODEL_A51INTERCEPTOR && (obj->flags & OBJFLAG_80000000)) {
			gdl = objRenderShadow(obj, gdl);
		}
	}

	return gdl;
}

static bool modelIsNodeNotTvscreen(struct modelfiledata *filedata, struct modelnode *node)
{
	if (filedata->skel == &g_SkelTerminal) {
		if (modelGetPart(filedata, MODELPART_TERMINAL_0000) == node) {
			return false;
		}
	}

	if (filedata->skel == &g_SkelCiHub) {
		if (modelGetPart(filedata, MODELPART_CIHUB_0000) == node
				|| modelGetPart(filedata, MODELPART_CIHUB_0001) == node
				|| modelGetPart(filedata, MODELPART_CIHUB_0002) == node
				|| modelGetPart(filedata, MODELPART_CIHUB_0003) == node) {
			return false;
		}
	}

	return true;
}

/**
 * Deform an object due to it being destroyed.
 */
static void objDeform(struct defaultobj *obj, s32 level)
{
	f32 min;
	f32 max;
	f32 average;
	f32 f2;
	f32 spbc = 0.0f;
	f32 spb0[3];
	s32 i;
	struct modelrodata_bbox *parentbbox;
	struct modelrodata_bbox *bbox;
	struct modelnode *node;
	struct modelnode *parent;
	struct model *model = obj->model;
	struct modelfiledata *modeldef = model->filedata;
	volatile s32 salt;
	bool ok = true;
	f32 mult;
	bool swap;
	s32 axis;
	s32 chance;

	func0f0926bc(obj->prop, 15, 0xffff);

	salt = 0;

	salt = random();

	wallhitsFreeByProp(obj->prop, 1);

	swap = false;
	axis = 1;

	for (i = 0; i < 3; i++) {
		bool swapthis = false;

		spb0[i] = sqrtf(obj->realrot[i][0] * obj->realrot[i][0] + obj->realrot[i][1] * obj->realrot[i][1] + obj->realrot[i][2] * obj->realrot[i][2]);

		f2 = obj->realrot[i][1] / spb0[i];

		if (f2 < 0.0f) {
			swapthis = true;
			f2 = -f2;
		}

		if (spbc < f2) {
			spbc = f2;
			axis = i;
			swap = swapthis;
		}
	}

	min = 99999.0f;
	max = -99999.0f;

	bbox = modelFindBboxRodata(model);

	if (axis == 0) {
		min = objGetLocalXMin(bbox);
		max = objGetLocalXMax(bbox);
	} else if (axis == 1) {
		min = objGetLocalYMin(bbox);
		max = objGetLocalYMax(bbox);
	} else if (axis == 2) {
		min = objGetLocalZMin(bbox);
		max = objGetLocalZMax(bbox);
	}

	if (swap) {
		f32 tmp = max;
		max = min;
		min = tmp;
	}

	if (min < max) {
		average = (min + max) * 0.5f;
	} else {
		average = 0.0f;
		min = 0.0f;
		max = 0.0f;
	}

	if (level == 3 && average - min > 4.0f) {
		average = min + 6.0f - 2.0f;
	}

	if (max - min > 6.0f) {
		if (level < 3) {
			mult = 0.9f;
		} else {
			mult = (max - min - 6.0f) / (max - min);
		}
	} else {
		mult = 1.0f;
	}

	obj->realrot[1][0] *= mult;
	obj->realrot[1][1] *= mult;
	obj->realrot[1][2] *= mult;

	obj->prop->pos.f[axis] += (1.0f - mult) * min;

	node = modeldef->rootnode;

	while (node) {
		u32 type = node->type & 0xff;

		switch (type) {
		case MODELNODETYPE_DL:
			parentbbox = NULL;
			parent = node;

			while (parent) {
				if ((parent->type & 0xff) == MODELNODETYPE_BBOX) {
					parentbbox = &parent->rodata->bbox;
					break;
				}

				parent = parent->parent;
			}

			if (modelIsNodeNotTvscreen(modeldef, node) && parentbbox == bbox) {
				struct modelrodata_dl *rodata = &node->rodata->dl;
				struct modelrwdata_dl *rwdata = (struct modelrwdata_dl *)&model->rwdatas[rodata->rwdataindex];
				struct gfxvtx *vertices = vtxstoreAllocate(rodata->numvertices, VTXSTORETYPE_OBJVTX, node, objGetDestroyedLevel(obj));

				if (vertices) {
					if (rwdata->vertices != rodata->vertices) {
						// Replacing modified vertices with a new set
						for (i = 0; i < rodata->numvertices; i++) {
							vertices[i] = rwdata->vertices[i];
						}

						vtxstoreFree(VTXSTORETYPE_OBJVTX, rwdata->vertices);
					} else {
						// Replacing original vertices with modified vertices
						for (i = 0; i < rodata->numvertices; i++) {
							vertices[i] = rodata->vertices[i];
						}
					}

					rwdata->vertices = vertices;
				} else {
					ok = false;
				}

				if ((u32)rwdata->colours == ALIGN8((u32)&rodata->vertices[rodata->numvertices])) {
					struct colour *colours = vtxstoreAllocate(rodata->numcolours, VTXSTORETYPE_OBJCOL, NULL, 0);

					if (colours) {
						for (i = 0; i < rodata->numcolours; i++) {
							colours[i] = rwdata->colours[i];
						}

						rwdata->colours = colours;
					} else {
						ok = false;
					}
				}

				if (ok) {
					for (i = 0; i < rodata->numcolours; i++) {
						if (i > 0) {
							rwdata->colours[i].a = 0;
						}
					}

					for (i = 0; i < rodata->numvertices; i++) {
						s16 tmp = average;

						rng2SetSeed(rodata->vertices[i].x + rodata->vertices[i].y + rodata->vertices[i].z + salt);

						{
							if (swap) {
								if (rwdata->vertices[i].v[axis] >= tmp) {
									chance = 20;
								} else {
									chance = 90;
								}
							} else {
								if (rwdata->vertices[i].v[axis] <= tmp) {
									chance = 20;
								} else {
									chance = 90;
								}
							}

							if ((s32)(random2() % 100) < chance) {
								rwdata->vertices[i].colour = 0;
							}
						}

						rwdata->vertices[i].x += (s32)(((s32)(random2() % 20) - 10) * spb0[0]);
						rwdata->vertices[i].y += (s32)(((s32)(random2() % 20) - 10) * spb0[1]);
						rwdata->vertices[i].z += (s32)(((s32)(random2() % 20) - 10) * spb0[2]);

						if (parentbbox != NULL) {
							if (rwdata->vertices[i].x < (s16)parentbbox->xmin) {
								rwdata->vertices[i].x = (s16)parentbbox->xmin;
							}

							if (rwdata->vertices[i].x > (s16)parentbbox->xmax) {
								rwdata->vertices[i].x = (s16)parentbbox->xmax;
							}

							if (rwdata->vertices[i].y < (s16)parentbbox->ymin) {
								rwdata->vertices[i].y = (s16)parentbbox->ymin;
							}

							if (rwdata->vertices[i].y > (s16)parentbbox->ymax) {
								rwdata->vertices[i].y = (s16)parentbbox->ymax;
							}

							if (rwdata->vertices[i].z < (s16)parentbbox->zmin) {
								rwdata->vertices[i].z = (s16)parentbbox->zmin;
							}

							if (rwdata->vertices[i].z > (s16)parentbbox->zmax) {
								rwdata->vertices[i].z = (s16)parentbbox->zmax;
							}
						}
					}
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c784(obj->model, node);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(obj->model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(obj->model, node);
			break;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	if ((obj->hidden2 & OBJH2FLAG_80) == 0) {
		if (!ok) {
			modelFreeVertices(VTXSTORETYPE_OBJVTX, model);
		} else {
			obj->hidden2 |= OBJH2FLAG_80;
		}
	}
}

/**
 * Bounce an object, such as a hoverbot when it's destroyed.
 */
static void objBounce(struct defaultobj *obj, struct coord *arg1)
{
	struct coord dir;
	struct coord rot = {0, 0, 0};
	struct projectile *projectile = NULL;

	func0f0685e4(obj->prop);

	if (obj->hidden & OBJHFLAG_EMBEDDED) {
		projectile = obj->embedment->projectile;
	} else if (obj->hidden & OBJHFLAG_PROJECTILE) {
		projectile = obj->projectile;
	}

	if (projectile) {
		projectile->speed.x = (RANDOMFRAC() * 6.6666665f) - 3.3333333f;
		projectile->speed.y = (RANDOMFRAC() * 3.3333333f) + 3.3333333f;
		projectile->speed.z = (RANDOMFRAC() * 6.6666665f) - 3.3333333f;

#if PAL
		rot.x = RANDOMFRAC() * 0.029447744f - 0.014723872f;
		rot.y = RANDOMFRAC() * 0.029447744f - 0.014723872f;
		rot.z = RANDOMFRAC() * 0.029447744f - 0.014723872f;
#else
		rot.x = RANDOMFRAC() * 0.024539785f - 0.012269893f;
		rot.y = RANDOMFRAC() * 0.024539785f - 0.012269893f;
		rot.z = RANDOMFRAC() * 0.024539785f - 0.012269893f;
#endif

		mtx4LoadRotation(&rot, &projectile->mtx);

		projectile->flags |= PROJECTILEFLAG_AIRBORNE;

		dir = *arg1;

		mtx4RotateVecInPlace(g_Vars.currentplayer->projectionmtx, &dir);

		projectile->speed.x += 3.3333333f * dir.x;
		projectile->speed.z += 3.3333333f * dir.z;
		projectile->ownerprop = g_Vars.currentplayer->prop;
		projectile->bouncecount = 1;
	}
}

void objSetDropped(struct prop *prop, u32 droptype)
{
	struct prop *parent = prop->parent;

	if (parent) {
		struct defaultobj *obj = prop->obj;

		func0f0685e4(prop);

		if ((obj->hidden & OBJHFLAG_EMBEDDED) && obj->embedment->projectile) {
			obj->embedment->projectile->droptype = droptype;
		} else if (obj->hidden & OBJHFLAG_PROJECTILE) {
			obj->projectile->droptype = droptype;
		}

		if (g_Vars.lvmpbotlevel
				&& obj->type == OBJTYPE_WEAPON
				&& obj->modelnum != MODEL_CHRBRIEFCASE
				&& obj->modelnum != MODEL_CHRDATATHIEF) {
			obj->flags3 |= OBJFLAG3_CANHARDFREE;
		}
	}
}

void objApplyMomentum(struct defaultobj *obj, struct coord *speed, f32 rotation, bool addspeed, bool addrotation)
{
	struct projectile *projectile = NULL;
	struct modelrodata_bbox *bbox;
	f32 sp24;
	f32 sp20;

	func0f0685e4(obj->prop);

	if (obj->hidden & OBJHFLAG_EMBEDDED) {
		projectile = obj->embedment->projectile;
	} else if (obj->hidden & OBJHFLAG_PROJECTILE) {
		projectile = obj->projectile;
	}

	if (projectile) {
		projectile->flags |= PROJECTILEFLAG_SLIDING;

		if (addspeed) {
			projectile->speed.x += speed->x;
			projectile->speed.y += speed->y;
			projectile->speed.z += speed->z;
		} else {
			projectile->speed = *speed;
		}

		if (addrotation) {
			projectile->unk0dc += rotation;
		} else {
			projectile->unk0dc = rotation;
		}

		if (obj->type == OBJTYPE_HOVERPROP || obj->type == OBJTYPE_HOVERBIKE) {
			if (obj->flags & OBJFLAG_20000000) {
				projectile->unk08c = 0.8f;
				projectile->unk098 = 0.0027777778f;
				projectile->unk0e0 = 0.000041881234f;
				projectile->unk0e4 = PAL ? 0.969f : 0.974f;
				projectile->unk0ec = 0.07852732f;
				projectile->unk0f0 = 6.6666665f;
			} else {
				projectile->unk08c = 0.5f;
				projectile->unk098 = 0.013888889f;
				projectile->unk0e0 = 0.00020940616f;
				projectile->unk0e4 = PAL ? 0.953f : 0.961f;
				projectile->unk0ec = 0.07852732f;
				projectile->unk0f0 = 6.6666665f;
			}
			return;
		}

		bbox = objFindBboxRodata(obj);

		sp24 = objGetRotatedLocalXMaxByMtx3(bbox, obj->realrot) - objGetRotatedLocalXMinByMtx3(bbox, obj->realrot);
		sp20 = objGetRotatedLocalZMaxByMtx3(bbox, obj->realrot) - objGetRotatedLocalZMinByMtx3(bbox, obj->realrot);

		if (sp24 > 150.0f || sp20 > 150.0f) {
			projectile->unk08c = 0.1f;
			projectile->unk098 = 0.055555556f;
			projectile->unk0e0 = 0.00083762466f;
			projectile->unk0e4 = PAL ? 0.953f : 0.961f;
			projectile->unk0ec = 0.009815915f;
			projectile->unk0f0 = 0.8333333f;
		} else if (sp24 > 75.0f || sp20 > 75.0f) {
			projectile->unk08c = 0.1f;
			projectile->unk098 = 0.055555556f;
			projectile->unk0e0 = 0.00083762466f;
			projectile->unk0e4 = PAL ? 0.953f : 0.961f;
			projectile->unk0ec = 0.01963183f;
			projectile->unk0f0 = 0.8333333f;
		} else {
			projectile->unk08c = 0.1f;
			projectile->unk098 = 0.055555556f;
			projectile->unk0e0 = 0.00041881233f;
			projectile->unk0e4 = PAL ? 0.953f : 0.961f;
			projectile->unk0ec = 0.07852732f;
			projectile->unk0f0 = 1.6666666f;
		}
	}
}

void func0f082e84(struct defaultobj *obj, struct coord *pos, struct coord *dir, struct coord *tween, bool addrotation)
{
	struct coord speed = {0, 0, 0};
	f32 a = tween->f[0] * dir->f[0] + tween->f[2] * dir->f[2];
	f32 b = pos->f[0] - obj->prop->pos.f[0];
	f32 c = pos->f[2] - obj->prop->pos.f[2];
	f32 d = -b * dir->f[2] + c * dir->f[0];

	speed.f[0] += a * dir->f[0] * 0.2f;
	speed.f[2] += a * dir->f[2] * 0.2f;

	objApplyMomentum(obj, &speed, a * d * 0.0001f, true, addrotation);
}

void objDetach(struct prop *prop)
{
	struct prop *parent = prop->parent;

	if (parent) {
		struct defaultobj *obj = prop->obj;
		struct model *model = obj->model;

		propDetach(prop);

		model->attachedtomodel = NULL;
		model->attachedtonode = NULL;

		obj->hidden &= ~OBJHFLAG_HASOWNER;

		if (parent->type & (PROPTYPE_CHR | PROPTYPE_PLAYER)) {
			struct chrdata *chr = parent->chr;

			if (chr) {
				if (prop == chr->weapons_held[HAND_RIGHT]) {
					chrSetFiring(chr, HAND_RIGHT, false);
					chr->weapons_held[HAND_RIGHT] = NULL;
				}

				if (prop == chr->weapons_held[HAND_LEFT]) {
					chrSetFiring(chr, HAND_LEFT, false);
					chr->weapons_held[HAND_LEFT] = NULL;
				}
			}
		}
	}
}

bool objDrop(struct prop *prop, bool lazy)
{
	struct prop *parent = prop->parent;
	struct defaultobj *obj = prop->obj;
	struct prop *root;
	struct model *model;
	Mtxf spf0;
	struct coord spe4;
	s16 rooms[8];

	if ((obj->hidden & OBJHFLAG_EMBEDDED) && obj->embedment->projectile) {
		struct projectile *projectile2 = obj->embedment->projectile;

		embedmentFree(obj->embedment);

		obj->projectile = projectile2;
		obj->hidden &= ~OBJHFLAG_EMBEDDED;
		obj->hidden |= OBJHFLAG_PROJECTILE;
	}

	if (parent && (obj->hidden & OBJHFLAG_PROJECTILE)) {
		struct projectile *projectile;

		model = obj->model;
		projectile = obj->projectile;
		root = parent;

		while (root->parent) {
			root = root->parent;
		}

		projectile->ownerprop = parent;
		projectile->flags |= PROJECTILEFLAG_AIRBORNE;

		if (projectile->droptype == DROPTYPE_5) {
			struct defaultobj *rootobj = root->obj;
			struct modelnode *node1;
			struct coord spb8;
			struct modelnode *node2;
			struct coord spa8;
			f32 spa4;
			f32 spa0;

			node1 = objFindBboxNode(obj);
			modelNodeGetPosition(obj->model, model0001a740(node1), &spb8);

			node2 = objFindBboxNode(rootobj);
			modelNodeGetPosition(rootobj->model, model0001a740(node2), &spa8);

			spe4.x = spb8.x - spa8.x;
			spe4.y = spb8.y - spa8.y;
			spe4.z = spb8.z - spa8.z;

			mtx00016208(rootobj->realrot, &spe4);

			spa4 = RANDOMFRAC() * 13.333333015442f;
			spa0 = atan2f(spe4.x, spe4.z);
			spa0 += RANDOMFRAC() * 0.7852731347084f - 0.3926365673542f;

			if (spa0 >= M_BADTAU) {
				spa0 -= M_BADTAU;
			} else if (spa0 < 0.0f) {
				spa0 += M_BADTAU;
			}

			projectile->speed.x += spa4 * sinf(spa0);
			projectile->speed.z += spa4 * cosf(spa0);

			mtx3ToMtx4(rootobj->realrot, &spf0);

			spe4.x += root->pos.x;
			spe4.y += root->pos.y;
			spe4.z += root->pos.z;

			mtx4SetTranslation(&spe4, &spf0);
			func0f065e74(&root->pos, root->rooms, &spe4, rooms);
		} else {
			if (projectile->droptype == DROPTYPE_SURRENDER && parent->type == PROPTYPE_CHR) {
				struct chrdata *chr = parent->chr;
				struct coord rot = {0, 0, 0};
				f32 angle = chrGetInverseTheta(chr);

				projectile->speed.x = sinf(angle) * 1.6666666269302f;
				projectile->speed.y = -RANDOMFRAC() * 0.83333331346512f;
				projectile->speed.z = cosf(angle) * 1.6666666269302f;

				rot.x = RANDOMFRAC() * PALUPF(0.012269892729819f) - PALUPF(0.0061349463649094f);
				rot.y = RANDOMFRAC() * PALUPF(0.012269892729819f) - PALUPF(0.0061349463649094f);
				rot.z = RANDOMFRAC() * PALUPF(0.012269892729819f) - PALUPF(0.0061349463649094f);

				mtx4LoadRotation(&rot, (Mtxf *)&projectile->mtx);
			} else if (projectile->droptype == DROPTYPE_THROWGRENADE && parent->type == PROPTYPE_CHR) {
				struct chrdata *chr = parent->chr;
				struct coord rot = {0, 0, 0};
				f32 angle = chrGetInverseTheta(chr);
				f32 dist;

				if (chr->aibot) {
					dist = chrGetDistanceToTarget(chr);
				} else {
					dist = chrGetAttackEntityDistance(chr, chr->act_throwgrenade.flags, chr->act_throwgrenade.entityid);
				}

				if (chr->aibot == NULL && dist < 300) {
					dist = 300;
				}

				projectile->speed.x = sinf(angle) * 13.333333015442f * (dist / 1000);
				projectile->speed.y = (((dist >= 1200) * ((dist - 1200) / 1200)) + 1) * 6.6666665077209f;
				projectile->speed.z = cosf(angle) * 13.333333015442f * (dist / 1000);

				rot.x = RANDOMFRAC() * PALUPF(0.012269892729819f) - PALUPF(0.0061349463649094f);
				rot.y = RANDOMFRAC() * PALUPF(0.012269892729819f) - PALUPF(0.0061349463649094f);
				rot.z = RANDOMFRAC() * PALUPF(0.012269892729819f) - PALUPF(0.0061349463649094f);

				mtx4LoadRotation(&rot, (Mtxf *)&projectile->mtx);
				projectileSetSticky(prop);
			} else if (projectile->droptype == DROPTYPE_HAT) {
				struct coord rot = {0, 0, 0};
				struct prop *playerprop = g_Vars.currentplayer->prop;
				f32 x = parent->pos.x - playerprop->pos.x;
				f32 z = parent->pos.z - playerprop->pos.z;
				f32 angle = atan2f(x, z);

				projectile->speed.x = (RANDOMFRAC() * 3.3333332538605f + 3.3333332538605f) * sinf(angle);
				projectile->speed.y = RANDOMFRAC() * 3.3333332538605f;
				projectile->speed.z = (RANDOMFRAC() * 3.3333332538605f + 3.3333332538605f) * cosf(angle);

				rot.x = RANDOMFRAC() * PALUPF(0.049079570919275f) - PALUPF(0.024539785459638f);
				rot.y = RANDOMFRAC() * PALUPF(0.049079570919275f) - PALUPF(0.024539785459638f);
				rot.z = RANDOMFRAC() * PALUPF(0.049079570919275f) - PALUPF(0.024539785459638f);

				mtx4LoadRotation(&rot, (Mtxf *)&projectile->mtx);
			} else if (projectile->droptype == DROPTYPE_OWNERREAP) {
				struct coord rot = {0, 0, 0};

				projectile->speed.x = (0.5f - RANDOMFRAC()) * 1.6666666269302f;
				projectile->speed.y = 0.0f;
				projectile->speed.z = (0.5f - RANDOMFRAC()) * 1.6666666269302f;

				rot.x = RANDOMFRAC() * PALUPF(0.049079570919275f) - PALUPF(0.024539785459638f);
				rot.y = RANDOMFRAC() * PALUPF(0.049079570919275f) - PALUPF(0.024539785459638f);
				rot.z = RANDOMFRAC() * PALUPF(0.049079570919275f) - PALUPF(0.024539785459638f);

				mtx4LoadRotation(&rot, (Mtxf *)&projectile->mtx);
			} else {
				// DROPTYPE_OWNERREAP
				func0f0964b4(&projectile->speed, (Mtxf *)&projectile->mtx);
			}

			if (!lazy && (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)) {
				// Do collision checks
				Mtxf *sp48 = model0001a60c(model);
				mtx00015be4(g_Vars.currentplayer->projectionmtx, sp48, &spf0);
				propSetPerimEnabled(root, false);

				spe4.x = spf0.m[3][0];
				spe4.y = spf0.m[3][1];
				spe4.z = spf0.m[3][2];

				if (cdTestLos10(&root->pos, root->rooms, &spe4, rooms, CDTYPE_ALL,
							GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2 | GEOFLAG_WALL) == CDRESULT_COLLISION
						|| (projectile->flags & PROJECTILEFLAG_STICKY) == 0) {
					if (cdTestVolume(&spe4, objGetRadius(obj), rooms, CDTYPE_ALL, CHECKVERTICAL_NO, 0.0f, 0) == CDRESULT_COLLISION) {
						spf0.m[3][0] = root->pos.x;
						spf0.m[3][2] = root->pos.z;
					}
				}

				propSetPerimEnabled(root, true);
				prop->z = -sp48->m[3][2];
			} else {
				// No collision checks
				mtx4LoadIdentity(&spf0);
				mtx00015f04(model->scale, &spf0);
				mtx4SetTranslation(&root->pos, &spf0);
				roomsCopy(root->rooms, rooms);
			}
		}

		objDetach(prop);
		propActivate(prop);
		propEnable(prop);

		prop->pos.x = spf0.m[3][0];
		prop->pos.y = spf0.m[3][1];
		prop->pos.z = spf0.m[3][2];

		propDeregisterRooms(prop);
		roomsCopy(rooms, prop->rooms);

		spf0.m[3][0] = 0;
		spf0.m[3][1] = 0;
		spf0.m[3][2] = 0;

		mtx4ToMtx3(&spf0, obj->realrot);
		func0f069c70(obj, true, true);

		obj->shadecol[0] = obj->nextcol[0];
		obj->shadecol[1] = obj->nextcol[1];
		obj->shadecol[2] = obj->nextcol[2];
		obj->shadecol[3] = obj->nextcol[3];

		obj->hidden |= OBJHFLAG_SUSPICIOUS;

		if (obj->type == OBJTYPE_WEAPON) {
			struct weaponobj *weapon = (struct weaponobj *)obj;

			if (weapon->weaponnum == WEAPON_GRENADE && weapon->timer240 >= 0) {
				propSetDangerous(prop);
			}
		}

		return true;
	}

	return false;
}

/**
 * Make an object fall. Eg. due to it sitting on a table which is now destroyed,
 * or because it was a chopper that is now destroyed.
 */
static void objFall(struct defaultobj *obj, s32 playernum)
{
	if (obj->type == OBJTYPE_AUTOGUN && g_Vars.normmplayerisrunning) {
		// Don't set owner playernum
	} else {
		obj->hidden &= 0x0fffffff;
		obj->hidden |= (playernum << 28) & 0xf0000000;
	}

	if ((obj->flags2 & OBJFLAG2_00000100) == 0
			&& (obj->flags3 & OBJFLAG3_10000000) == 0
			&& (obj->flags & (OBJFLAG_00000001 | OBJFLAG_00000008))
			&& (obj->hidden & (OBJHFLAG_EMBEDDED | OBJHFLAG_PROJECTILE)) == 0) {
		struct coord rot = {0, 0, 0};
		struct projectile *projectile = NULL;

		func0f0685e4(obj->prop);

		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			projectile = obj->projectile;
		}

		if (projectile) {
			projectile->speed.x = RANDOMFRAC() * 1.6666666f - 0.8333333f;
			projectile->speed.y = RANDOMFRAC() * 3.3333333f + 1.6666666f;
			projectile->speed.z = RANDOMFRAC() * 1.6666666f - 0.8333333f;

			if ((obj->flags2 & OBJFLAG2_00000200) == 0) {
#if PAL
				rot.x = RANDOMFRAC() * 0.0058895489f - 0.0029447745f;
				rot.y = RANDOMFRAC() * 0.0058895489f - 0.0029447745f;
				rot.z = RANDOMFRAC() * 0.0058895489f - 0.0029447745f;
#else
				rot.x = RANDOMFRAC() * 0.0049079573f - 0.0024539786f;
				rot.y = RANDOMFRAC() * 0.0049079573f - 0.0024539786f;
				rot.z = RANDOMFRAC() * 0.0049079573f - 0.0024539786f;
#endif
			}

			mtx4LoadRotation(&rot, &projectile->mtx);

			projectile->flags |= PROJECTILEFLAG_AIRBORNE;

			obj->flags &= ~OBJFLAG_00000100;
			obj->hidden &= ~OBJHFLAG_00008000;
		}
	}
}

/**
 * Destroy the objects that the given prop is supporting.
 *
 * For example, destroying a table will also destroy all the props that are
 * sitting on that table.
 */
static void objDestroySupportedObjects(struct prop *tableprop, s32 playernum)
{
	struct prop *prop;
	s16 *propnumptr;
	s16 propnums[256];
	u8 *start;
	u8 *end;

	if (propUpdateGeometry(tableprop, &start, &end)) {
		roomGetProps(tableprop->rooms, propnums, 256);

		propnumptr = propnums;

		while (*propnumptr >= 0) {
			prop = &g_Vars.props[*propnumptr];

			if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON)) {
				struct defaultobj *obj = prop->obj;

				if (obj) {
					if (prop->pos.y > tableprop->pos.y
							&& (obj->hidden & OBJHFLAG_00008000)
							&& cd000266a4(prop->pos.x, prop->pos.z, (struct geo *)start)) {
						objFall(obj, playernum);
					}
				}
			}

			propnumptr++;
		}
	}
}

static void objCheckDestroyed(struct defaultobj *obj, struct coord *pos, s32 playernum)
{
	if (obj->damage > obj->maxdamage || objGetDestroyedLevel(obj)) {
		struct prop *prop = obj->prop;
		struct prop *rootprop = prop;
		s16 exptype = g_PropExplosionTypes[8 + obj->modelnum];
		s16 rooms[8];

		// If in Deep Sea outro
		if (g_Vars.tickmode == TICKMODE_CUTSCENE && g_CutsceneAnimNum == ANIM_CUT_PAM_OUTRO_CAM) {
			exptype = EXPLOSIONTYPE_24;
		}

		while (rootprop->parent) {
			rootprop = rootprop->parent;
		}

		if (objGetDestroyedLevel(obj) == 0) {
			// Obj is now destroyed
			obj->damage = 0;
			obj->hidden2 |= OBJH2FLAG_DESTROYED;

			func0f065e74(&rootprop->pos, rootprop->rooms, pos, rooms);
			explosionCreateComplex(prop, pos, rooms, exptype, playernum);

			if (obj->flags2 & OBJFLAG2_REMOVEWHENDESTROYED) {
				obj->hidden |= OBJHFLAG_REAPABLE;
			} else if (obj->type == OBJTYPE_CHOPPER) {
				struct chopperobj *chopper = (struct chopperobj *)obj;

				objFall(obj, playernum);

				chopper->attackmode = CHOPPERMODE_FALL;
				chopper->timer60 = (obj->flags & OBJFLAG_CHOPPER_INACTIVE) ? 0 : 2;
				obj->flags &= ~OBJFLAG_CHOPPER_INACTIVE;
			} else if (obj->type == OBJTYPE_HOVERCAR) {
				struct hovercarobj *hovercar = (struct hovercarobj *)obj;
				struct coord sp40;
				struct coord sp34;

				if (obj->flags & OBJFLAG_HOVERCAR_ISHOVERBOT) {
					// Hoverbots bounce and spark when dead
					hovercar->dead = true;
					hovercar->deadtimer60 = TICKS(250);
					hovercar->sparkstimer60 = TICKS(50);

					bgunCalculatePlayerShotSpread(&sp40, &sp34, HAND_RIGHT, false);
					objBounce(obj, &sp34);
				} else if (obj->modelnum == MODEL_TAXICAB || obj->modelnum == MODEL_POLICECAR) {
					// Taxi and police car (limo) fall to the ground and retain collision
					objDeform(obj, 10);

					hovercar->dead = true;
					hovercar->speed = 0.0f;
					hovercar->speedtime60 = 0.0f;
					hovercar->speedaim += 10.0f;
				} else {
					// Cars in Defection "explode" but actually warp to their next path
					explosionCreateSimple(prop, &prop->pos, prop->rooms, exptype, playernum);
					hovercarStartNextPath(hovercar);
				}
			} else {
				// Other objects
				objDeform(obj, 1);

				if (rootprop == prop) {
					objDestroySupportedObjects(prop, playernum);

					if ((obj->hidden & OBJHFLAG_00008000) == 0) {
						obj->hidden |= OBJHFLAG_00010000;
						objFall(obj, playernum);
					}
				}
			}
		} else {
			s32 shotstaken = objGetShotsTaken(obj);

			if ((shotstaken % 4) == 0) {
				if (obj->type != OBJTYPE_CHOPPER && obj->type != OBJTYPE_HOVERCAR) {
					objDeform(obj, (shotstaken >> 2) + 1);
				}

				func0f065e74(&rootprop->pos, rootprop->rooms, pos, rooms);

				if (exptype != EXPLOSIONTYPE_NONE) {
					explosionCreateSimple(prop, pos, rooms, EXPLOSIONTYPE_6, playernum);
				}
			}

			if (objGetDestroyedLevel(obj) > 0) {
				if (obj->hidden2 & OBJH2FLAG_CANREGEN) {
					if (obj->hidden & OBJHFLAG_00001000) {
						obj->hidden2 |= OBJH2FLAG_10;
					} else {
						obj->hidden2 &= ~OBJH2FLAG_10;
					}

					prop->timetoregen = TICKS(1200);
				}
			}

			if (shotstaken >= 12) {
				obj->hidden |= OBJHFLAG_00001000;

				if ((obj->flags3 & OBJFLAG3_10000000) == 0) {
					obj->flags &= ~OBJFLAG_00000100;
				}
			}
		}
	}
}

bool func0f084594(struct model *model, struct modelnode *node, struct coord *arg2, struct coord *arg3, struct hitthing *hitthing, s32 *mtxindexptr, struct modelnode **nodeptr)
{
	s32 i;
	s32 mtxindex;
	bool ok;
	bool reset;
	s32 maxindex;
	struct modelrodata_bbox *rodata;
	s8 spc4[3];
	struct coord spb8;
	struct coord spac;
	struct coord min;
	struct coord max;
	struct coord sp88;
	struct coord sp7c;
	Mtxf mtx;

	rodata = &node->rodata->bbox;

	mtxindex = model0001a524(node, 0);
	mtx000172f0(model->matrices[mtxindex].m, mtx.m);

	spb8 = *arg2;

	mtx4TransformVecInPlace(&mtx, &spb8);

	spac = *arg3;

	mtx4RotateVecInPlace(&mtx, &spac);

	if (var8005efc0 != 0.0f) {
		min.x = rodata->xmin - var8005efc0;
		min.y = rodata->ymin - var8005efc0;
		min.z = rodata->zmin - var8005efc0;

		max.x = rodata->xmax + var8005efc0;
		max.y = rodata->ymax + var8005efc0;
		max.z = rodata->zmax + var8005efc0;
	} else {
		min.x = rodata->xmin;
		min.y = rodata->ymin;
		min.z = rodata->zmin;

		max.x = rodata->xmax;
		max.y = rodata->ymax;
		max.z = rodata->zmax;
	}

	ok = true;
	reset = true;

	hitthing->unk28 = 0;

	for (i = 0; i < 3; i++) {
		if (spb8.f[i] < min.f[i]) {
			spc4[i] = 1;
			sp88.f[i] = min.f[i];
			reset = false;
		} else if (spb8.f[i] > max.f[i]) {
			spc4[i] = 0;
			sp88.f[i] = max.f[i];
			reset = false;
		} else {
			spc4[i] = 2;
		}
	}

	if (reset) {
		for (i = 0; i < 3; i++) {
			hitthing->unk00.f[i] = spb8.f[i];
		}

		hitthing->unk0c.x = 0.0f;
		hitthing->unk0c.y = 1.0f;
		hitthing->unk0c.z = 0.0f;
		hitthing->unk28 = 2;
	} else {
		for (i = 0; i < 3; i++) {
			if (spc4[i] != 2 && spac.f[i] != 0.0f) {
				sp7c.f[i] = (sp88.f[i] - spb8.f[i]) / spac.f[i];
			} else {
				sp7c.f[i] = -1.0f;
			}
		}

		maxindex = 0;

		for (i = 1; i < 3; i++) {
			if (sp7c.f[i] > sp7c.f[maxindex]) {
				maxindex = i;
			}
		}

		if (sp7c.f[maxindex] < 0.0f) {
			ok = false;
		} else {
			for (i = 0; i < 3; i++) {
				if (maxindex != i) {
					hitthing->unk00.f[i] = spb8.f[i] + sp7c.f[maxindex] * spac.f[i];

					if (hitthing->unk00.f[i] < min.f[i] || hitthing->unk00.f[i] > max.f[i]) {
						ok = false;
					}
				} else {
					hitthing->unk00.f[i] = sp88.f[i];
				}
			}

			if (ok) {
				hitthing->unk28 = maxindex * 2;

				if (spc4[maxindex] == 0) {
					hitthing->unk28 = (maxindex << 2) + 2;

					for (i = 0; i < 3; i++) {
						hitthing->unk0c.f[i] = (i != maxindex ? 0.0f : 1.0f);
					}
				} else {
					hitthing->unk28 = maxindex << 2;

					for (i = 0; i < 3; i++) {
						hitthing->unk0c.f[i] = (i != maxindex ? 0.0f : -1.0f);
					}
				}
			}
		}
	}

	if (ok) {
		*mtxindexptr = mtxindex;
		*nodeptr = node;
	}

	return ok;
}

static bool func0f0849dc(struct model *model, struct modelnode *nodearg, struct coord *arg2, struct coord *arg3, struct hitthing *hitthing, s32 *dstmtxindex, struct modelnode **dstnode)
{
	struct coord spec;
	struct coord spe0;
	struct coord spd4;
	Mtxf *spd0 = NULL;
	bool done = false;
	struct modelnode *node = nodearg;
	struct gfxvtx *vertices = NULL;

	while (node && !done) {
		u32 type = node->type & 0xff;
		Gfx *s3 = NULL;
		void *s5 = NULL;

		switch (type) {
		case MODELNODETYPE_DL:
			{
				struct modelrodata_dl *rodata = &node->rodata->dl;
				struct modelrwdata_dl *rwdata = modelGetNodeRwData(model, node);

				if (rwdata->gdl != NULL) {
					if (rwdata->gdl == rodata->primary) {
						s3 = (Gfx *)((u32)rodata->colourtable + ((u32)rodata->primary & 0xffffff));
					} else {
						s3 = rwdata->gdl;
					}

					if (rodata->secondary != NULL) {
						s5 = (void *)((u32)rodata->colourtable + ((u32)rodata->secondary & 0xffffff));
					}

					vertices = rwdata->vertices;
				}
			}
			break;
		case MODELNODETYPE_GUNDL:
			{
				struct modelrodata_gundl *rodata = &node->rodata->gundl;

				if (rodata->primary != NULL) {
					s3 = (Gfx *)((u32)rodata->baseaddr + ((u32)rodata->primary & 0xffffff));

					if (rodata->secondary != NULL) {
						s5 = (Gfx *)((u32)rodata->baseaddr + ((u32)rodata->secondary & 0xffffff));
					}

					vertices = (void *)(u32)rodata->baseaddr;
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c784(model, node);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, node);
			break;
		}

		if (s3 != NULL) {
			s32 mtxindex = model0001a524(node, 0);
			Mtxf *mtx = NULL;
			Mtxf sp64;

			if (mtxindex >= 0) {
				mtx = &model->matrices[mtxindex];
			}

			if (mtx && mtx != spd0) {
				spd0 = mtx;

				mtx000172f0(mtx->m, sp64.m);

				spec = *arg2;

				mtx4TransformVecInPlace(&sp64, &spec);

				spd4 = *arg3;

				mtx4RotateVecInPlace(&sp64, &spd4);

				spe0.x = spd4.x * 32767.0f + spec.x;
				spe0.y = spd4.y * 32767.0f + spec.y;
				spe0.z = spd4.z * 32767.0f + spec.z;
			}

			if (bgTestHitOnObj(&spec, &spe0, &spd4, s3, s5, vertices, hitthing)) {
				*dstmtxindex = mtxindex;
				*dstnode = node;
				done = true;
			}
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node == nodearg) {
					node = NULL;
					break;
				}

				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	return done;
}

void glassDestroy(struct defaultobj *obj)
{
	struct prop *prop = obj->prop;
	struct modelrodata_bbox *bbox = objFindBboxRodata(obj);

	wallhitsFreeByProp(prop, 0);
	wallhitsFreeByProp(prop, 1);

	if (obj->modelnum == MODEL_AIVILLABOT1
			|| obj->modelnum == MODEL_AIVILLABOT2
			|| obj->modelnum == MODEL_AIVILLABOT3) {
		shardsCreate(&prop->pos, &obj->realrot[0][0], &obj->realrot[1][0], &obj->realrot[2][0],
				bbox->xmin, bbox->xmax, bbox->ymin, bbox->ymax, SHARDTYPE_BOTTLE, prop);
	} else {
		shardsCreate(&prop->pos, &obj->realrot[0][0], &obj->realrot[1][0], &obj->realrot[2][0],
				bbox->xmin, bbox->xmax, bbox->ymin, bbox->ymax, SHARDTYPE_GLASS, prop);
	}

	obj->damage = 0;
	obj->hidden |= OBJHFLAG_REAPABLE;
	obj->hidden2 |= OBJH2FLAG_DESTROYED;
}

void doorDestroyGlass(struct doorobj *door)
{
	struct modelnode *node;
	bool closed;
	struct prop *prop = door->base.prop;
	struct model *model = door->base.model;
	union modelrodata *rodata;
	union modelrwdata *rwdata;
	Mtxf matrix;

	rodata = modelGetPartRodata(model->filedata, 2);

	if (door->portalnum >= 0) {
		// @bug: Firing three shots at door glass is supposed to destroy it,
		// and this function is called when the third shot happens, but if it's
		// shot from a long distance (such that the glass is opaque) then this
		// function returns early and the glass remains in place, despite
		// setting the portal as unblocked. On the fourth shot
		// PORTALFLAG_FORCEOPEN is already set, so closed is false and the
		// glass is destroyed.
		closed = PORTAL_IS_CLOSED(door->portalnum);

		g_BgPortals[door->portalnum].flags |= PORTALFLAG_FORCEOPEN;

		if (closed) {
			return;
		}
	}

	func0f08c424(door, &matrix);
	shardsCreate((struct coord *) &matrix.m[3][0], &matrix.m[0][0], &matrix.m[1][0], &matrix.m[2][0],
			rodata->bbox.xmin, rodata->bbox.xmax, rodata->bbox.ymin, rodata->bbox.ymax,
			SHARDTYPE_GLASS, prop);
	wallhitsFreeByProp(prop, 1);

	node = modelGetPart(model->filedata, 1);
	rwdata = modelGetNodeRwData(model, node);
	rwdata->toggle.visible = false;
}

void func0f085050(struct prop *prop, f32 damage, struct coord *pos, s32 arg3, s32 playernum)
{
	struct defaultobj *obj = prop->obj;

	if (obj->type == OBJTYPE_AUTOGUN && g_Vars.normmplayerisrunning) {
		// do nothing
	} else {
		obj->hidden &= 0x0fffffff;
		obj->hidden |= (playernum << 28) & 0xf0000000;
	}

	if ((obj->hidden & OBJHFLAG_HASOWNER) == 0) {
		struct prop *child = prop->child;

		while (child) {
			struct prop *next = child->next;

			func0f085050(child, damage, pos, arg3, playernum);

			child = next;
		}

		objDamage(prop->obj, damage, pos, arg3, playernum);
	}
}

bool func0f085194(struct defaultobj *obj)
{
	switch (obj->type) {
	case OBJTYPE_KEY:
	case OBJTYPE_AMMOCRATE:
	case OBJTYPE_WEAPON:
	case OBJTYPE_HAT:
	case OBJTYPE_MULTIAMMOCRATE:
	case OBJTYPE_SHIELD:
	case OBJTYPE_ESCASTEP:
		return true;
	}

	return false;
}

static bool objIsMortal(struct defaultobj *obj)
{
	if (obj->type == OBJTYPE_DOOR) {
		return false;
	}

	if (func0f085194(obj) && obj->type != OBJTYPE_SHIELD) {
		if ((obj->flags & OBJFLAG_00010000) == 0) {
			return false;
		}
	} else if (obj->flags & OBJFLAG_INVINCIBLE) {
		return false;
	}

	return true;
}

void objTakeGunfire(struct defaultobj *obj, f32 damage, struct coord *pos, s32 weaponnum, s32 playernum)
{
	if ((obj->flags2 & OBJFLAG2_IMMUNETOGUNFIRE) == 0) {
		objDamage(obj, damage, pos, weaponnum, playernum);
	}
}

void objDamage(struct defaultobj *obj, f32 damage, struct coord *pos, s32 weaponnum, s32 playernum)
{
	// Store the attacker playernum into the object's "hidden" field
	// ...but not for deployed laptop guns in multiplayer, because those bits
	// likely designate the owner of the gun
	if (obj->type != OBJTYPE_AUTOGUN || !g_Vars.normmplayerisrunning) {
		obj->hidden &= 0x0fffffff;
		obj->hidden |= (playernum << 28) & 0xf0000000;
	}

	if (weaponnum == WEAPON_NONE) {
		if (func0f085194(obj)) {
			return;
		}

		if (obj->flags & OBJFLAG_01000000) {
			return;
		}
	} else {
		if (obj->flags & OBJFLAG_INVINCIBLE) {
			return;
		}

		if (obj->type == OBJTYPE_WEAPON) {
			struct weaponobj *weapon;

			if (obj->flags2 & OBJFLAG2_AICANNOTUSE) {
				propExplode(obj->prop, EXPLOSIONTYPE_12);
				obj->hidden |= OBJHFLAG_REAPABLE;
			}

			// If damaging an explosive item, make it explode immediately by
			// zeroing its timer
			weapon = (struct weaponobj *) obj;

			if (weapon->weaponnum == WEAPON_GRENADE
					|| weapon->weaponnum == WEAPON_TIMEDMINE
					|| weapon->weaponnum == WEAPON_REMOTEMINE
					|| weapon->weaponnum == WEAPON_PROXIMITYMINE
					|| weapon->weaponnum == WEAPON_ROCKET
					|| weapon->weaponnum == WEAPON_HOMINGROCKET
					|| weapon->weaponnum == WEAPON_GRENADEROUND
					|| (weapon->weaponnum == WEAPON_DRAGON && weapon->gunfunc == FUNC_SECONDARY)) {
				// Homing rockets are immune to remote mines? Or maybe they just
				// don't explode because the mine is exploding anyway
				if (weapon->weaponnum != WEAPON_HOMINGROCKET || weaponnum != WEAPON_REMOTEMINE) {
					weapon->timer240 = 0;
				}
			}

			return;
		}

		if (obj->type == OBJTYPE_AMMOCRATE || obj->type == OBJTYPE_MULTIAMMOCRATE) {
			// @bug: It's not safe to cast a multiammocrateobj to an ammocrateobj.
			// For multiammocrateobjs, this is reading the first model/qty pair
			// as a single word... this turns out to not have any bad effects.
			struct ammocrateobj *crate = (struct ammocrateobj *) obj;

			if (crate->ammotype == AMMOTYPE_GRENADE
					|| crate->ammotype == AMMOTYPE_ROCKET
					|| crate->ammotype == AMMOTYPE_HOMINGROCKET
					|| crate->ammotype == AMMOTYPE_REMOTE_MINE
					|| crate->ammotype == AMMOTYPE_PROXY_MINE
					|| crate->ammotype == AMMOTYPE_TIMED_MINE
					|| crate->ammotype == AMMOTYPE_DEVASTATOR) {
				obj->flags |= OBJFLAG_AMMOCRATE_EXPLODENOW;
			}

			return;
		}

		if (!objIsMortal(obj)) {
			return;
		}
	}

	// Tweak damage and apply it
	if (obj->type == OBJTYPE_CHOPPER) {
		damage *= 0.25f;
	}

	if (objGetDestroyedLevel(obj) == 0) {
		// Not destroyed
		damage *= 250;

		if (damage < 1) {
			damage = 1;
		}
	} else {
		// Figure out how much to go within this destroyed level and cap it there
		f32 max = 4 - (objGetShotsTaken(obj) % 4);

		if (damage > max) {
			damage = max;
		} else if (damage < 1) {
			damage = 1;
		}
	}

	damage = obj->damage + damage;

	if (damage >= 32767) {
		obj->damage = 32767;
	} else {
		obj->damage = damage;
	}

	// Handle objects that do things when damaged
	if (obj->modelnum == MODEL_TARGET) {
		// empty
	} else {
		if (obj->type == OBJTYPE_GLASS || obj->type == OBJTYPE_TINTEDGLASS) {
			if (obj->damage >= obj->maxdamage) {
				glassDestroy(obj);
			}
		} else {
			objSetDropped(obj->prop, DROPTYPE_DEFAULT);
			objCheckDestroyed(obj, pos, playernum);
		}

		// This code appears to be unused...
		// It appears to handle spawning a weapon when the ammo crate is shot.
		if (obj->type == OBJTYPE_CHOPPER) {
			struct chopperobj *chopper = (struct chopperobj *) obj;

			if (chopper->attackmode != CHOPPERMODE_FALL) {
				chopper->attackmode = CHOPPERMODE_COMBAT;
			}
		} else if (obj->type == OBJTYPE_AUTOGUN) {
			obj->flags |= OBJFLAG_AUTOGUN_DAMAGED;

			if (objGetDestroyedLevel(obj) == 1) {
				obj->flags |= OBJFLAG_DEACTIVATED;
			}
		} else if (obj->type == OBJTYPE_CCTV) {
			if (objGetDestroyedLevel(obj) == 1) {
				obj->flags |= OBJFLAG_DEACTIVATED;
			}
		} else if (obj->type == OBJTYPE_SINGLEMONITOR) {
			struct singlemonitorobj *monitor = (struct singlemonitorobj *) obj;

			if (objGetDestroyedLevel(obj) == 1) {
				tvscreenSetCmdlist(&monitor->screen, g_TvCmdlist14);
			}
		} else if (obj->type == OBJTYPE_MULTIMONITOR) {
			struct multimonitorobj *monitor = (struct multimonitorobj *) obj;

			if (objGetDestroyedLevel(obj) == 1) {
				tvscreenSetCmdlist(&monitor->screens[0], g_TvCmdlist14);
				tvscreenSetCmdlist(&monitor->screens[1], g_TvCmdlist14);
				tvscreenSetCmdlist(&monitor->screens[2], g_TvCmdlist14);
				tvscreenSetCmdlist(&monitor->screens[3], g_TvCmdlist14);
			}
		} else if (obj->type == OBJTYPE_SHIELD) {
			struct shieldobj *shield = (struct shieldobj *) obj;

			if (objGetDestroyedLevel(obj) == 0) {
				shield->amount = shield->initialamount * (f32)(obj->maxdamage - obj->damage) / (f32)obj->maxdamage;
			} else {
				shield->amount = 0;
			}
		}

		if (objGetDestroyedLevel(obj) == 1) {
			struct prop *child = obj->prop->child;

			while (child) {
				struct prop *next = child->next;
				objSetDropped(child, DROPTYPE_DEFAULT);
				child = next;
			}
		}
	}
}

void func0f0859a0(struct prop *prop, struct shotdata *shotdata)
{
	struct defaultobj *obj = prop->obj;
	struct model *model = obj->model;
	struct prop *child;
	struct modelnode *node1 = NULL;
	struct hitthing hitthing1;
	s32 spe4;
	struct coord spd8;
	f32 spd4;
	struct modelnode *node2;
	s32 lVar3;
	bool isnotglass;
	struct modelnode *node3;
	struct hitthing hitthing2;
	s32 sp90;
	struct modelnode *node4;
	struct prop *next;
	struct coord sp7c;
	struct coord sp70;

	if (obj->hidden & OBJHFLAG_00001000) {
		return;
	}

	if ((prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) == 0) {
		return;
	}

	child = prop->child;

	while (child) {
		next = child->next;
		func0f0859a0(child, shotdata);
		child = next;
	}

	if (var8005efc0 > 0.0f) {
		lVar3 = model000225d4(model, &shotdata->unk00, &shotdata->unk0c, &node1);

		while (lVar3 > 0) {
			if (func0f084594(model, node1, &shotdata->unk00, &shotdata->unk0c, &hitthing1, &spe4, &node2)) {
				break;
			}

			lVar3 = model000225d4(model, &shotdata->unk00, &shotdata->unk0c, &node1);
		}
	} else {
		do {
			lVar3 = model000225d4(model, &shotdata->unk00, &shotdata->unk0c, &node1);

			if (lVar3 > 0 && func0f0849dc(model, node1, &shotdata->unk00, &shotdata->unk0c, &hitthing1, &spe4, &node2)) {
				break;
			}
		} while (lVar3 > 0);
	}

	if (obj->flags3 & OBJFLAG3_HOVERBEDSHIELD) {
		node3 = modelGetPart(model->filedata, MODELPART_0067);

		if (node3 && func0f084594(model, node3, &shotdata->unk00, &shotdata->unk0c, &hitthing2, &sp90, &node4)) {
			if (lVar3 <= 0 ||
					model->matrices[sp90].m[0][2] * hitthing2.unk00.f[0] + model->matrices[sp90].m[1][2] * hitthing2.unk00.f[1] + model->matrices[sp90].m[2][2] * hitthing2.unk00.f[2] >
					model->matrices[spe4].m[0][2] * hitthing1.unk00.f[0] + model->matrices[spe4].m[1][2] * hitthing1.unk00.f[1] + model->matrices[spe4].m[2][2] * hitthing1.unk00.f[2]) {
				lVar3 = 1;
				hitthing1 = hitthing2;
				node1 = node3;
				spe4 = sp90;
				node2 = node4;
				hitthing1.texturenum = 10000;
			}
		}
	}

	if (lVar3 > 0) {
		mtx4TransformVec(&model->matrices[spe4], &hitthing1.unk00, &spd8);
		spd4 = -spd8.f[2];

		if (spd4 <= shotdata->unk34) {
			isnotglass = true;

			if ((obj->flags & OBJFLAG_INVINCIBLE) == 0) {
				if (obj->type == OBJTYPE_GLASS || obj->type == OBJTYPE_TINTEDGLASS) {
					isnotglass = false;
				} else if (obj->model->filedata->skel == &g_SkelWindowedDoor
						&& modelGetPart(obj->model->filedata, MODELPART_WINDOWEDDOOR_0003) == node2) {
					isnotglass = false;
				}
			}

			mtx4TransformVec(g_Vars.currentplayer->projectionmtx, &spd8, &sp7c);
			mtx4RotateVec(&model->matrices[spe4], &hitthing1.unk0c, &sp70);
			mtx4RotateVecInPlace(g_Vars.currentplayer->projectionmtx, &sp70);

			func0f061fa8(shotdata, prop, spd4, lVar3,
					node1, &hitthing1, spe4, node2,
					model, isnotglass && shotdata->gset.weaponnum != WEAPON_FARSIGHT,
					(obj->flags2 & OBJFLAG2_BULLETPROOF)
						&& shotdata->gset.weaponnum != WEAPON_DY357MAGNUM
						&& shotdata->gset.weaponnum != WEAPON_FARSIGHT,
					&sp7c, &sp70);
		}
	}
}

void func0f085e00(struct prop *prop, struct shotdata *shotdata)
{
	f32 tmp;
	struct defaultobj *obj = prop->obj;
	struct model *model = obj->model;
	struct modelrodata_bbox *bbox = objFindBboxRodata(obj);

	if ((prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)
			&& (obj->hidden & OBJHFLAG_00001000) == 0
			&& (obj->flags2 & OBJFLAG2_SHOOTTHROUGH) == 0) {
		tmp = -(model->matrices[0].m[3][2] + objGetRotatedLocalZMaxByMtx4(bbox, model->matrices));

		if (tmp <= shotdata->unk34) {
			func0f0859a0(prop, shotdata);
		}
	}
}

void objHit(struct shotdata *shotdata, struct hit *hit)
{
	struct defaultobj *obj;
	struct coord sp110;
	struct prop *prop;
	u8 isclosefunc = false;
	s32 i;
	bool explosiveshells = false;
	bool spfc = hit->unk4c;
	struct weaponfunc *func = gsetGetWeaponFunction(&shotdata->gset);
	struct coord spec;
	f32 tmp;
	struct prop *spe4;
	s16 textureindex;
	s16 spdc[3];

	if (func != NULL) {
		if ((func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
			isclosefunc = true;
		}

		if (func->flags & FUNCFLAG_EXPLOSIVESHELLS) {
			explosiveshells = true;
		}
	}

	prop = hit->prop;

	while (prop->parent) {
		prop = prop->parent;
	}

	obj = hit->prop->obj;

	sp110.x = shotdata->unk00.x - hit->distance * shotdata->unk0c.x / shotdata->unk0c.z;
	sp110.y = shotdata->unk00.y - hit->distance * shotdata->unk0c.y / shotdata->unk0c.z;
	sp110.z = shotdata->unk00.z - hit->distance;

	mtx4TransformVecInPlace(g_Vars.currentplayer->projectionmtx, &sp110);

	if (!spfc && chrIsUsingPaintball(g_Vars.currentplayer->prop->chr)) {
		spfc = true;
	}

	if (hit->unk4c) {
		bgunSetHitPos(&sp110);
	}

	if (obj->modelnum == MODEL_TARGET) {
		if (hit->hitthing.texturenum == TEXTURE_0B9E) {
			frCalculateHit(obj, &sp110, shotdata->gset.unk063a);
		} else if ((shotdata->gset.weaponnum != WEAPON_CALLISTO || shotdata->gset.weaponfunc != FUNC_SECONDARY)
				&& shotdata->gset.weaponnum != WEAPON_FARSIGHT) {
			// For some penetrating weapons, unset hits beyond the shot distance?
			spe4 = hit->prop;
			mtx4TransformVec(obj->model->matrices, &sp110, &spec);
			tmp = -spec.z;

			for (i = 0; i < 10; i++) {
				if (shotdata->hits[i].prop && shotdata->hits[i].prop != spe4 && shotdata->hits[i].distance > tmp) {
					shotdata->hits[i].prop = NULL;
				}
			}

			shotdata->unk34 = tmp;
		}
	}

	// Create sparks
	if (!isclosefunc) {
		if (chrIsUsingPaintball(g_Vars.currentplayer->prop->chr)) {
			sparksCreate(prop->rooms[0], prop, &sp110, 0, 0, SPARKTYPE_PAINT);
		} else {
			sparksCreate(prop->rooms[0], prop, &sp110, 0, 0, SPARKTYPE_DEFAULT);
		}
	}

	// Create shield hit if object is shielded
	if (hit->hitthing.texturenum == 10000) {
		spdc[0] = hit->hitthing.unk00.x;
		spdc[1] = hit->hitthing.unk00.y;
		spdc[2] = hit->hitthing.unk00.z;

		shieldhitCreate(prop, (obj->flags3 & OBJFLAG3_SHOWSHIELD) ? 4.0f : 8.0f, hit->prop, hit->node, hit->model, hit->hitthing.unk28 / 2, spdc);
	}

	// Increment object hit count
	if (objIsHealthy(obj) && objIsMortal(obj) && hit->unk4c) {
		mpstatsIncrementPlayerShotCount2(&shotdata->gset, SHOTREGION_OBJECT);
	}

	// Play hit sound
	if (!spfc) {
		bgunPlayGlassHitSound(&hit->prop->pos, hit->prop->rooms, hit->hitthing.texturenum);
	} else if (!isclosefunc) {
		bgunPlayPropHitSound(&shotdata->gset, hit->prop, hit->hitthing.texturenum);
	}

	// Create wall hit (bullet hole)
	if (!isclosefunc
			&& hit->hitthing.texturenum != 10000
			&& shotdata->gset.weaponnum != WEAPON_UNARMED
			&& shotdata->gset.weaponnum != WEAPON_LASER
			&& shotdata->gset.weaponnum != WEAPON_TRANQUILIZER
			&& shotdata->gset.weaponnum != WEAPON_FARSIGHT) {
		if (hit->unk4c == 0) {
			struct prop *hitprop = hit->prop;
			s8 iswindoweddoor = obj->model->filedata->skel == &g_SkelWindowedDoor ? true : false;

			textureindex = WALLHITTEX_GLASS1 + (random() % 3);

			if ((obj->type == OBJTYPE_DOOR && !iswindoweddoor)
					|| (obj->flags & OBJFLAG_INVINCIBLE)
					|| (obj->flags2 & OBJFLAG2_IMMUNETOGUNFIRE)) {
				// Use a bulletproof glass texture
				textureindex += 10;
			}

			wallhitCreate(&hit->hitthing.unk00, &hit->hitthing.unk0c, &shotdata->gunpos, 0,
					0, textureindex, 1, hitprop, hit->mtxindex, iswindoweddoor, g_Vars.currentplayer->prop->chr, true);
		} else {
			s16 textureindex;
			struct surfacetype *surfacetype;
			s32 spcc;
			s8 spcb = false;
			bool spc4;

			if (hit->hitthing.texturenum < 0 || hit->hitthing.texturenum >= NUM_TEXTURES) {
				surfacetype = g_SurfaceTypes[0];
			} else if (g_Textures[hit->hitthing.texturenum].surfacetype < 15) {
				surfacetype = g_SurfaceTypes[g_Textures[hit->hitthing.texturenum].surfacetype];
			} else {
				surfacetype = g_SurfaceTypes[0];
			}

			if (surfacetype->numwallhittexes > 0) {
				spc4 = false;
				spcc = random() % surfacetype->numwallhittexes;

				if (obj->model->filedata->skel == &g_SkelWindowedDoor && hit->unk44 == modelGetPart(obj->model->filedata, MODELPART_WINDOWEDDOOR_0003)) {
					spcb = true;
				}

				textureindex = surfacetype->wallhittexes[spcc];

				if (textureindex >= WALLHITTEX_GLASS1 && textureindex <= WALLHITTEX_GLASS3) {
					if (obj->type == OBJTYPE_DOOR
							|| (obj->flags & OBJFLAG_INVINCIBLE)
							|| (obj->flags2 & OBJFLAG2_IMMUNETOGUNFIRE)) {
						// Use a bulletproof glass texture
						textureindex += 10;
					}

					spc4 = true;
				}

				wallhitCreate(&hit->hitthing.unk00, &hit->hitthing.unk0c, &shotdata->gunpos, 0,
						0, textureindex, 1, hit->prop, hit->mtxindex, spcb, g_Vars.currentplayer->prop->chr, spc4);
			}
		}
	}

	if (g_Vars.antiplayernum < 0 || g_Vars.currentplayer != g_Vars.anti || (obj->flags2 & OBJFLAG2_IMMUNETOANTI) == 0) {
		if (hit->hitthing.texturenum != 10000) {
			f32 damage = gsetGetDamage(&shotdata->gset);

			if (obj->type == OBJTYPE_AUTOGUN) {
				damage *= g_AutogunDamageRxScale;
			} else if (explosiveshells) {
				if (obj->type == OBJTYPE_GLASS || obj->type == OBJTYPE_TINTEDGLASS) {
					damage *= 100.0f;
				} else {
					damage *= 5.0f;
				}
			}

			objTakeGunfire(obj, damage, &sp110, shotdata->gset.weaponnum, g_Vars.currentplayernum);

			if (obj->model->filedata->skel == &g_SkelWindowedDoor && !hit->unk4c) {
				struct doorobj *door = (struct doorobj *)obj;
				door->glasshits++;

				if (door->glasshits >= 3) {
					doorDestroyGlass(door);
				}
			}
		}

		objDropRecursively(hit->prop, false);

		// Handle pushing and bouncing
		if ((obj->hidden & OBJHFLAG_MOUNTED) == 0 && (obj->hidden & OBJHFLAG_GRABBED) == 0) {
			if (obj->flags3 & OBJFLAG3_PUSHABLE) {
				struct coord spb0;
				struct coord spa4;
				struct coord pushdir;
				Mtxf sp58;

				spb0.x = shotdata->dir.x * 3.0f;
				spb0.y = shotdata->dir.y * 3.0f;
				spb0.z = shotdata->dir.z * 3.0f;

				mtx4MultMtx4(g_Vars.currentplayer->projectionmtx, &obj->model->matrices[hit->mtxindex], &sp58);
				mtx4TransformVec(&sp58, &hit->hitthing.unk00, &spa4);

				pushdir = shotdata->dir;

				func0f082e84(obj, &spa4, &pushdir, &spb0, true);
			} else {
				bool bounce = false;

				if (func0f085194(obj)) {
					if ((obj->flags & OBJFLAG_00400000) == 0) {
						bounce = true;
					}
				} else if (obj->flags & OBJFLAG_BOUNCEIFSHOT) {
					bounce = true;
				}

				if (obj->flags2 & OBJFLAG2_00000002) {
					if (!objIsHealthy(obj)) {
						bounce = true;
					}
				}

				if (obj->flags2 & OBJFLAG2_LINKEDTOSAFE) {
					bounce = false;
				}

				if (bounce) {
					objBounce(obj, &shotdata->unk0c);
				}
			}
		}
	}
}

static u32 propobjGetCiTagId(struct prop *prop)
{
	if (prop && g_Vars.stagenum == STAGE_CITRAINING) {
		u8 tags[8] = { 0x0e, 0x0f, 0x10, 0x47, 0x46, 0x45, 0x1b, 0x7f };
		struct defaultobj *obj = prop->obj;
		u32 i;

		for (i = 0; i != 8; i++) {
			struct defaultobj *taggedobj = g_ObjsByTag[tags[i]];

			if (obj == taggedobj) {
				return tags[i];
			}
		}
	}

	return 0;
}

bool objIsHealthy(struct defaultobj *obj)
{
	return objGetDestroyedLevel(obj) == 0;
}

bool objTestForInteract(struct prop *prop)
{
	u32 stack;
	struct defaultobj *obj = prop->obj;
	bool maybe = false;

	if (propobjGetCiTagId(prop)) {
		maybe = true;
	} else if (obj->type == OBJTYPE_ALARM
			|| (obj->flags & OBJFLAG_THROWNLAPTOP)
			|| (obj->flags3 & (OBJFLAG3_HTMTERMINAL | OBJFLAG3_INTERACTABLE))
			|| (obj->hidden & (OBJHFLAG_LIFTDOOR | OBJHFLAG_00000002))) {
		maybe = true;
	} else if (obj->type == OBJTYPE_HOVERBIKE) {
		if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
			maybe = true;
		} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK
				&& bmoveGetCrouchPos() == CROUCHPOS_STAND
				&& g_Vars.currentplayer->crouchoffset == 0.0f) {
			maybe = true;
		}
	} else if ((obj->flags3 & OBJFLAG3_GRABBABLE)
			&& g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK
			&& bmoveGetCrouchPos() == CROUCHPOS_STAND
			&& g_Vars.currentplayer->crouchoffset == 0.0f) {
		maybe = true;
	}

	if (maybe && (obj->hidden & OBJHFLAG_MOUNTED) && prop == bmoveGetHoverbike()) {
		maybe = false;
	}

	if (maybe
			&& (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)
			&& objIsHealthy(obj)
			&& (obj->flags & OBJFLAG_CANNOT_ACTIVATE) == 0) {
		struct prop *playerprop = g_Vars.currentplayer->prop;
		f32 x = prop->pos.x - playerprop->pos.x;
		f32 y = prop->pos.y - playerprop->pos.y;
		f32 z = prop->pos.z - playerprop->pos.z;
		f32 range;

		if (obj->modelnum == MODEL_SK_SHUTTLE) {
			range = 500;
		} else if (obj->modelnum == MODEL_TAXICAB) {
			range = 300;
		} else if (obj->modelnum == MODEL_PRESCAPSULE) {
			range = 280;
		} else if (obj->flags3 & OBJFLAG3_INTERACTSHORTRANGE) {
			range = 100;
		} else {
			range = 200;
		}

		if (x * x + z * z < range * range && y < range && y > -range) {
			f32 angle = atan2f(x, z) - (360.0f - g_Vars.currentplayer->vv_theta) * M_BADTAU / 360.0f;

			if (angle < 0.0f) {
				angle += M_BADTAU;
			}

			if (angle > M_BADPI) {
				angle = M_BADTAU - angle;
			}

			if (angle <= 0.3926365673542f) {
				if ((obj->flags2 & OBJFLAG2_INTERACTCHECKLOS) == 0
						|| cdTestLos06(&playerprop->pos, playerprop->rooms, &prop->pos, prop->rooms, CDTYPE_BG)) {
					g_InteractProp = prop;
				}
			}
		}
	}

	return true;
}

bool currentPlayerTryMountHoverbike(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;
	bool mount = false;
	u32 stack[2];

	if (obj->type == OBJTYPE_HOVERBIKE
			&& g_Vars.lvframe60 - g_Vars.currentplayer->activatetimelast < TICKS(30)
			&& (obj->hidden & OBJHFLAG_MOUNTED) == 0) {
		if (obj->hidden & OBJHFLAG_GRABBED) {
			if (bmoveGetGrabbedProp() == prop) {
				mount = true;
			} else {
				mount = false;
			}
		} else {
			mount = true;
		}
	}

	if (mount && g_Vars.currentplayer->bondmovemode != MOVEMODE_GRAB) {
		if (g_Vars.currentplayer->bondmovemode != MOVEMODE_WALK
				|| bmoveGetCrouchPos() != CROUCHPOS_STAND
				|| g_Vars.currentplayer->crouchoffset != 0) {
			mount = false;
		}
	}

	if (mount) {
		f32 angle = atan2f(
				prop->pos.x - g_Vars.currentplayer->prop->pos.x,
				prop->pos.z - g_Vars.currentplayer->prop->pos.z);
		angle -= hoverpropGetTurnAngle(obj);

		if (angle < 0) {
			angle += M_BADTAU;
		}

		if ((angle > 0.3926365673542f && angle < 2.3558194637299f)
				|| (angle < 5.8895483016968f && angle > 3.9263656139374f)) {
			g_Vars.currentplayer->hoverbike = prop;
			bmoveSetMode(MOVEMODE_BIKE);
			return true;
		}
	}

	return false;
}

bool propobjInteract(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;
	bool result = false;
	u32 tag_id = propobjGetCiTagId(prop);

	if (tag_id) {
		// CI object - terminals etc
		u8 handled = false;

		if (ciIsTourDone()) {
			if (tag_id == 0x10) {
				struct trainingdata *data = dtGetData();
				handled = true;

				if (data->intraining) {
					func0f0f85e0(&g_DtDetailsMenuDialog, MENUROOT_TRAINING);
				} else {
					func0f0f85e0(&g_DtListMenuDialog, MENUROOT_TRAINING);
				}
			} else if (tag_id == 0x45) {
				struct trainingdata *data = getHoloTrainingData();
				handled = true;

				if (data->intraining) {
					func0f0f85e0(&g_HtDetailsMenuDialog, MENUROOT_TRAINING);
				} else {
					func0f0f85e0(&g_HtListMenuDialog, MENUROOT_TRAINING);
				}
			} else if (tag_id == 0x7f) {
				handled = true;

				if (frIsInTraining()) {
					func0f0f85e0(&g_FrTrainingInfoInGameMenuDialog, MENUROOT_TRAINING);
				} else {
					func0f0f85e0(&g_FrWeaponListMenuDialog, MENUROOT_TRAINING);
				}
			}
		}

		if (!handled) {
			if (tag_id == 0x0e) {
				handled = true;
				func0f0f85e0(&g_BioListMenuDialog, MENUROOT_TRAINING);
			} else if (tag_id == 0x0f) {
				handled = true;
				func0f0f85e0(&g_CheatsMenuDialog, MENUROOT_TRAINING);
			} else if (tag_id == 0x1b) {
				handled = true;
				func0f0f85e0(&g_FrWeaponsAvailableMenuDialog, MENUROOT_TRAINING);
			} else if (tag_id == 0x47) {
				handled = true;
				func0f0f85e0(&g_CiMenuViaPcMenuDialog, MENUROOT_MAINMENU);
			} else if (tag_id == 0x46) {
				handled = true;
				func0f0f85e0(&g_HangarListMenuDialog, MENUROOT_TRAINING);
			}
		}

		if (handled) {
			// Typing sound
			sndStart(var80095200, SFX_TYPING_8118, NULL, -1, -1, -1, -1, -1);
		}

		func0f0fd494(&prop->pos);
	} else if (obj->type == OBJTYPE_ALARM) {
		// Button press sound
		sndStart(var80095200, SFX_PRESS_SWITCH, NULL, -1, -1, -1, -1, -1);

		if (g_AlarmTimer > 0) {
			alarmDeactivate();
		} else {
			alarmActivate();
		}
	} else if (obj->flags & OBJFLAG_THROWNLAPTOP) {
		// Thrown laptop
		if (obj->type == OBJTYPE_AUTOGUN) {
			struct autogunobj *laptop = (struct autogunobj *)obj;
			s32 playernum;

			if (g_Vars.normmplayerisrunning) {
				playernum = mpPlayerGetIndex(g_Vars.currentplayer->prop->chr);
			} else {
				playernum = g_Vars.currentplayernum;
			}

			if (playernum >= 0 && laptop == &g_ThrownLaptops[playernum]) {
				obj->hidden |= OBJHFLAG_REAPABLE;
				invGiveSingleWeapon(WEAPON_LAPTOPGUN);
				currentPlayerQueuePickupWeaponHudmsg(WEAPON_LAPTOPGUN, false);
				weaponPlayPickupSound(WEAPON_LAPTOPGUN);

				if (laptop->ammoquantity > 0 && laptop->ammoquantity != 255) {
					s32 newqty = bgunGetAmmoQtyForWeapon(WEAPON_LAPTOPGUN, FUNC_PRIMARY) + laptop->ammoquantity;
					bgunSetAmmoQtyForWeapon(WEAPON_LAPTOPGUN, FUNC_PRIMARY, newqty);
				}
			}
		} else {
			result = propPickupByPlayer(prop, 1);
		}
	} else if (currentPlayerTryMountHoverbike(prop) == false
			&& (obj->flags3 & OBJFLAG3_GRABBABLE)
			&& g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK
			&& bmoveGetCrouchPos() == CROUCHPOS_STAND
			&& g_Vars.currentplayer->crouchoffset == 0
			&& g_Vars.currentplayer->onladder == false) {
		bmoveGrabProp(prop);
	}

	if (g_Vars.normmplayerisrunning) {
		scenarioHandleActivatedProp(g_Vars.currentplayer->prop->chr, prop);
	} else {
		if (g_Vars.currentplayernum == g_Vars.coopplayernum) {
			obj->hidden |= OBJHFLAG_ACTIVATED_BY_COOP;
		} else if (g_Vars.currentplayernum == g_Vars.bondplayernum) {
			obj->hidden |= OBJHFLAG_ACTIVATED_BY_BOND;
		}
	}

	doorCallLift(prop, false);

	return result;
}

void objSetPerimEnabled(struct prop *prop, bool enable)
{
	struct defaultobj *obj = prop->obj;

	if (enable) {
		obj->hidden &= ~OBJHFLAG_PERIMDISABLED;
	} else {
		obj->hidden |= OBJHFLAG_PERIMDISABLED;
	}
}

bool objUpdateGeometry(struct prop *prop, u8 **start, u8 **end)
{
	struct defaultobj *obj = prop->obj;

	if (obj->unkgeo && (obj->flags3 & OBJFLAG3_WALKTHROUGH) == 0) {
		if ((obj->hidden2 & OBJH2FLAG_08)) {
			s32 len = (obj->flags3 & OBJFLAG3_GEOCYL) ? sizeof(struct geocyl) : sizeof(struct geoblock);

			if (obj->flags & OBJFLAG_00000100) {
				if ((obj->hidden & (OBJHFLAG_PERIMDISABLED | OBJHFLAG_DOORPERIMDISABLED)) == 0) {
					*start = (void *) obj->unkgeo;
					*end = (void *)((u32)obj->unkgeo + len);

					if (obj->geocount >= 2) {
						*end += obj->geocount * 0x40 - 0x40;
					}

					return true;
				}
			}

			if (obj->geocount >= 2) {
				*start = (void *)((u32)obj->unkgeo + len);
				*end = (void *)(*start + obj->geocount * 0x40 - 0x40);
				return true;
			}

			*end = NULL;
			*start = NULL;
			return false;
		}

		*start = (void *) obj->unkgeo;
		*end = (void *) ((u32)obj->unkgeo + obj->geocount * 0x40);
		return true;
	}

	*end = NULL;
	*start = NULL;

	return false;
}

void objGetBbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin)
{
	struct defaultobj *obj = prop->obj;

	if (obj->unkgeo && obj->hidden2 & OBJH2FLAG_08) {
		if (obj->flags3 & OBJFLAG3_GEOCYL) {
			*radius = obj->geocyl->radius;
			*ymin = obj->geocyl->ymin;
			*ymax = obj->geocyl->ymax;
		} else {
			*radius = model0001af80(obj->model);
			*ymin = obj->geoblock->ymin;
			*ymax = obj->geoblock->ymax;
		}
	} else {
		*radius = 1;
		*ymin = 0;
		*ymax = 0;
	}
}

static void ammotypeGetDeterminer(char *dst, s32 ammotype, s32 qty)
{
	bool determiner_a = false;
	bool determiner_an = false;
	bool determiner_some = false;
	bool determiner_the = false;

	s32 playercount = PLAYERCOUNT();
	s32 full = playercount <= 2
		&& !(playercount == 2 && g_ScreenSplit == SCREENSPLIT_VERTICAL);

	switch (ammotype) {
	case AMMOTYPE_CLOAK:
		determiner_a = true;
		break;
	case AMMOTYPE_PISTOL:
	case AMMOTYPE_SMG:
	case AMMOTYPE_RIFLE:
	case AMMOTYPE_SEDATIVE:
	case AMMOTYPE_PSYCHOSIS:
	case AMMOTYPE_PLASTIQUE:
		determiner_some = true;
		break;
	case AMMOTYPE_CROSSBOW:
	case AMMOTYPE_SHOTGUN:
	case AMMOTYPE_GRENADE:
	case AMMOTYPE_ROCKET:
	case AMMOTYPE_KNIFE:
	case AMMOTYPE_MAGNUM:
	case AMMOTYPE_DEVASTATOR:
	case AMMOTYPE_REMOTE_MINE:
	case AMMOTYPE_PROXY_MINE:
	case AMMOTYPE_TIMED_MINE:
	case AMMOTYPE_REAPER:
	case AMMOTYPE_HOMINGROCKET:
	case AMMOTYPE_DART:
	case AMMOTYPE_BOOST:
	case AMMOTYPE_BUG:
	case AMMOTYPE_MICROCAMERA:
		if (qty == 1) {
			determiner_a = true;
		} else {
			determiner_some = true;
		}
		break;
	case AMMOTYPE_FARSIGHT:
	case AMMOTYPE_NBOMB:
	case AMMOTYPE_ECM_MINE:
		if (qty == 1) {
			determiner_an = true;
		} else {
			determiner_some = true;
		}
		break;
	case AMMOTYPE_TOKEN:
		if (qty == 1) {
			determiner_the = true;
		} else {
			determiner_some = true;
		}
		break;
	}

	if (determiner_a) {
		if (full) {
			strcat(dst, langGet(L_PROPOBJ_004)); // "a"
		} else {
			strcat(dst, langGet(L_PROPOBJ_005)); // "A"
		}
	}

	if (determiner_an) {
		if (full) {
			strcat(dst, langGet(L_PROPOBJ_006)); // "an"
		} else {
			strcat(dst, langGet(L_PROPOBJ_007)); // "An"
		}
	}

	if (determiner_some) {
		if (full) {
			strcat(dst, langGet(L_PROPOBJ_002)); // "some"
		} else {
			strcat(dst, langGet(L_PROPOBJ_003)); // "Some"
		}
	}

	if (determiner_the) {
		if (full) {
			strcat(dst, langGet(L_PROPOBJ_008)); // "the"
		} else {
			strcat(dst, langGet(L_PROPOBJ_009)); // "The"
		}
	}
}

static void ammotypeGetPickupName(char *dst, s32 ammotype2, s32 qty)
{
	s32 ammotype = ammotype2;

	if (ammotype == AMMOTYPE_PISTOL || ammotype == AMMOTYPE_SMG || ammotype == AMMOTYPE_RIFLE) {
		strcat(dst, langGet(L_PROPOBJ_010)); // "ammo"
	} else if (ammotype == AMMOTYPE_KNIFE) {
		strcat(dst, langGet(L_PROPOBJ_021)); // "combat"

		if (qty == 1) {
			strcat(dst, langGet(L_PROPOBJ_022)); // "knife"
		} else {
			strcat(dst, langGet(L_PROPOBJ_023)); // "knives"
		}
	} else {
		s32 textnum = -1;

		switch (ammotype) {
		case AMMOTYPE_CROSSBOW:     textnum = L_PROPOBJ_045; break; // "bolt"
		case AMMOTYPE_SHOTGUN:      textnum = L_PROPOBJ_011; break; // "cartridge"
		case AMMOTYPE_FARSIGHT:     textnum = L_PROPOBJ_046; break; // "orb"
		case AMMOTYPE_GRENADE:      textnum = L_PROPOBJ_014; break; // "grenade"
		case AMMOTYPE_ROCKET:       textnum = L_PROPOBJ_016; break; // "rocket"
		case AMMOTYPE_MAGNUM:       textnum = L_PROPOBJ_012; break; // "magnum bullet"
		case AMMOTYPE_DEVASTATOR:   textnum = L_PROPOBJ_015; break; // "grenade round"
		case AMMOTYPE_REMOTE_MINE:  textnum = L_PROPOBJ_018; break; // "remote mine"
		case AMMOTYPE_PROXY_MINE:   textnum = L_PROPOBJ_019; break; // "proximity mine"
		case AMMOTYPE_TIMED_MINE:   textnum = L_PROPOBJ_020; break; // "timed mine"
		case AMMOTYPE_REAPER:       textnum = L_PROPOBJ_047; break; // "Reaper ammo"
		case AMMOTYPE_HOMINGROCKET: textnum = L_PROPOBJ_017; break; // "homing rocket"
		case AMMOTYPE_DART:         textnum = L_PROPOBJ_025; break; // "dart"
		case AMMOTYPE_NBOMB:        textnum = L_PROPOBJ_026; break; // "N-Bomb"
		case AMMOTYPE_SEDATIVE:     textnum = L_PROPOBJ_027; break; // "sedatives"
		case AMMOTYPE_PSYCHOSIS:    textnum = L_PROPOBJ_027; break; // "sedatives"
		case AMMOTYPE_BUG:          textnum = L_PROPOBJ_035; break; // "bug"
		case AMMOTYPE_MICROCAMERA:  textnum = L_PROPOBJ_036; break; // "micro camera"
		case AMMOTYPE_TOKEN:        textnum = L_PROPOBJ_038; break; // "token"
		case AMMOTYPE_PLASTIQUE:    textnum = L_PROPOBJ_039; break; // "plastique"
		case AMMOTYPE_CLOAK:        textnum = L_PROPOBJ_048; break; // "cloaking device"
		case AMMOTYPE_BOOST:        textnum = L_PROPOBJ_049; break; // "boost pill"
		}

		if (textnum >= 0) {
			strcat(dst, langGet(textnum));
		}

		if (qty >= 2 && ammotype != AMMOTYPE_REAPER && ammotype != AMMOTYPE_SEDATIVE && ammotype != AMMOTYPE_CLOAK) {
			strcat(dst, langGet(L_PROPOBJ_024)); // "s"
		}
	}
}

static void ammotypePlayPickupSound(u32 ammotype)
{
	switch (ammotype) {
	case AMMOTYPE_PISTOL:
	case AMMOTYPE_SMG:
	case AMMOTYPE_RIFLE:
	case AMMOTYPE_SHOTGUN:
	case AMMOTYPE_GRENADE:
	case AMMOTYPE_ROCKET:
	case AMMOTYPE_MAGNUM:
	case AMMOTYPE_DEVASTATOR:
	case AMMOTYPE_REAPER:
	case AMMOTYPE_HOMINGROCKET:
	case AMMOTYPE_DART:
	case AMMOTYPE_NBOMB:
	case AMMOTYPE_SEDATIVE:
	case AMMOTYPE_CLOAK:
	case AMMOTYPE_BOOST:
	case AMMOTYPE_TOKEN:
		sndStart(var80095200, SFX_PICKUP_AMMO, NULL, -1, -1, -1, -1, -1);
		break;
	case AMMOTYPE_REMOTE_MINE:
	case AMMOTYPE_PROXY_MINE:
	case AMMOTYPE_TIMED_MINE:
	case AMMOTYPE_BUG:
	case AMMOTYPE_MICROCAMERA:
	case AMMOTYPE_PLASTIQUE:
	case AMMOTYPE_ECM_MINE:
		sndStart(var80095200, SFX_PICKUP_MINE, NULL, -1, -1, -1, -1, -1);
		break;
	case AMMOTYPE_KNIFE:
		sndStart(var80095200, SFX_PICKUP_KNIFE, NULL, -1, -1, -1, -1, -1);
		break;
	}
}

s32 propPlayPickupSound(struct prop *prop, s32 weapon)
{
	s16 sound;

	if (weapon == WEAPON_COMBATKNIFE || weapon == WEAPON_COMBATKNIFE) {
		sound = SFX_PICKUP_KNIFE;
	} else if (weapon == WEAPON_REMOTEMINE
			|| weapon == WEAPON_PROXIMITYMINE
			|| weapon == WEAPON_TIMEDMINE
			|| weapon == WEAPON_COMMSRIDER
			|| weapon == WEAPON_TRACERBUG
			|| weapon == WEAPON_TARGETAMPLIFIER
			|| weapon == WEAPON_ECMMINE) {
		sound = SFX_PICKUP_MINE;
	} else if (weapon == WEAPON_GRENADE
			|| weapon == WEAPON_GRENADEROUND
			|| weapon == WEAPON_ROCKET
			|| weapon == WEAPON_HOMINGROCKET) {
		sound = SFX_PICKUP_AMMO;
	} else if (weapon == WEAPON_LASER) {
		sound = SFX_PICKUP_LASER;
	} else {
		sound = SFX_PICKUP_GUN;
	}

	return propsnd0f0939f8(NULL, prop, sound, -1,
			-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);
}

void weaponPlayPickupSound(s32 weaponnum)
{
	s32 sound;

	if (weaponnum == WEAPON_COMBATKNIFE || weaponnum == WEAPON_COMBATKNIFE) {
		sound = SFX_PICKUP_KNIFE;
	} else if (weaponnum == WEAPON_REMOTEMINE
			|| weaponnum == WEAPON_PROXIMITYMINE
			|| weaponnum == WEAPON_TIMEDMINE
			|| weaponnum == WEAPON_TRACERBUG
			|| weaponnum == WEAPON_TARGETAMPLIFIER
			|| weaponnum == WEAPON_COMMSRIDER
			|| weaponnum == WEAPON_ECMMINE) {
		sound = SFX_PICKUP_MINE;
	} else if (weaponnum == WEAPON_GRENADE
			|| weaponnum == WEAPON_GRENADEROUND
			|| weaponnum == WEAPON_ROCKET
			|| weaponnum == WEAPON_HOMINGROCKET) {
		sound = SFX_PICKUP_AMMO;
	} else if (weaponnum == WEAPON_LASER) {
		sound = SFX_PICKUP_LASER;
	} else if (weaponnum == WEAPON_BOLT) {
		sound = SFX_PICKUP_GUN;
	} else if (weaponnum == WEAPON_EYESPY) {
		sound = SFX_PICKUP_KEYCARD;
	} else if (weaponnum > WEAPON_PSYCHOSISGUN) {
		sound = SFX_PICKUP_KEYCARD;
	} else {
		sound = SFX_PICKUP_GUN;
	}

	sndStart(var80095200, sound, NULL, -1, -1, -1, -1, -1);
}

static void ammotypeGetPickupMessage(char *dst, s32 ammotype, s32 qty)
{
	s32 playercount = PLAYERCOUNT();
	s32 full = playercount <= 2
		&& !(playercount == 2 && g_ScreenSplit == SCREENSPLIT_VERTICAL);

	*dst = '\0';

	if (full) {
		strcat(dst, langGet(L_PROPOBJ_000)); // "Picked up"
	}

	ammotypeGetDeterminer(dst, ammotype, qty); // "a", "an", "some" or "the"
	ammotypeGetPickupName(dst, ammotype, qty); // name of ammo type
	strcat(dst, ".\n");
}

static void currentPlayerQueuePickupAmmoHudmsg(s32 ammotype, s32 pickupqty)
{
	char buffer[100];

	ammotypeGetPickupMessage(buffer, ammotype, pickupqty);
	hudmsgCreateWithFlags(buffer, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE);
}

static void ammoHandlePickup(s32 ammotype, s32 quantity, bool withsound, bool withhudmsg)
{
	s32 weapon;

	if (quantity > 0) {
		if (bgunGetReservedAmmoCount(ammotype) < bgunGetCapacityByAmmotype(ammotype)) {
			bgunSetAmmoQuantity(ammotype, bgunGetReservedAmmoCount(ammotype) + quantity);

			if (withhudmsg) {
				currentPlayerQueuePickupAmmoHudmsg(ammotype, quantity);
			}
		}

		if (withsound) {
			ammotypePlayPickupSound(ammotype);
		}

		if (ammotype == AMMOTYPE_GRENADE) {
			weapon = WEAPON_GRENADE;
		} else if (ammotype == AMMOTYPE_REMOTE_MINE) {
			weapon = WEAPON_REMOTEMINE;
		} else if (ammotype == AMMOTYPE_PROXY_MINE) {
			weapon = WEAPON_PROXIMITYMINE;
		} else if (ammotype == AMMOTYPE_TIMED_MINE) {
			weapon = WEAPON_TIMEDMINE;
		} else if (ammotype == AMMOTYPE_NBOMB) {
			weapon = WEAPON_NBOMB;
		} else if (ammotype == AMMOTYPE_KNIFE) {
			weapon = WEAPON_COMBATKNIFE;
		} else if (ammotype == AMMOTYPE_ECM_MINE) {
			weapon = WEAPON_ECMMINE;
		} else if (ammotype == AMMOTYPE_TOKEN) {
			weapon = WEAPON_BRIEFCASE2;
		} else if (ammotype == AMMOTYPE_CLOAK) {
			weapon = WEAPON_CLOAKINGDEVICE;
		} else if (ammotype == AMMOTYPE_BOOST) {
			weapon = WEAPON_COMBATBOOST;
		} else {
			weapon = -1;
		}

		if (weapon >= 0) {
			invGiveSingleWeapon(weapon);
		}
	}
}

s32 ammocrateGetPickupAmmoQty(struct ammocrateobj *crate)
{
	s32 qty = 1;

	switch (crate->ammotype) {
	case AMMOTYPE_PISTOL   : qty = 10;            break;
	case AMMOTYPE_SMG      : qty = 10;            break;
	case AMMOTYPE_CROSSBOW : qty = 10;            break;
	case AMMOTYPE_RIFLE    : qty = 10;            break;
	case AMMOTYPE_SHOTGUN  : qty = 5;             break;
	case AMMOTYPE_MAGNUM   : qty = 5;             break;
	case AMMOTYPE_REAPER   : qty = 200;           break;
	case AMMOTYPE_DART     : qty = 4;             break;
	case AMMOTYPE_CLOAK    : qty = TICKS(1200); break;
	case AMMOTYPE_SEDATIVE : qty = 16;            break;
	case AMMOTYPE_BOOST    : qty = 1;             break;
	}

	if (qty > 1 && !g_Vars.normmplayerisrunning) {
		qty *= g_AmmoQuantityScale;
	}

	return qty;
}

s32 weaponGetPickupAmmoQty(struct weaponobj *weapon)
{
	s32 ammotype;
	s32 qty = 1;

	if (!weapon) {
		return 20;
	}

	ammotype = bgunGetAmmoTypeForWeapon(weapon->weaponnum, 0);

	if (weapon->weaponnum == WEAPON_COMBATKNIFE || weapon->weaponnum == WEAPON_BOLT) {
		return 1;
	}

	if (weapon->base.flags & OBJFLAG_WEAPON_40000000) {
		return 0;
	}

	if (g_Vars.normmplayerisrunning) {
		switch (ammotype) {
		case AMMOTYPE_PISTOL:       qty = 10;            break;
		case AMMOTYPE_SMG:          qty = 20;            break;
		case AMMOTYPE_CROSSBOW:     qty = 5;             break;
		case AMMOTYPE_RIFLE:        qty = 20;            break;
		case AMMOTYPE_SHOTGUN:      qty = 10;            break;
		case AMMOTYPE_FARSIGHT:     qty = 4;             break;
		case AMMOTYPE_MAGNUM:       qty = 10;            break;
		case AMMOTYPE_DEVASTATOR:   qty = 3;             break;
		case AMMOTYPE_REAPER:       qty = 200;           break;
		case AMMOTYPE_DART:         qty = 10;            break;
		case AMMOTYPE_CLOAK:        qty = TICKS(1200); break;
		case AMMOTYPE_SEDATIVE:     qty = 16;            break;
		case AMMOTYPE_BOOST:        qty = 1;             break;
		}
	} else {
		switch (ammotype) {
		case AMMOTYPE_PISTOL:     qty = 10;            break;
		case AMMOTYPE_SMG:        qty = 10;            break;
		case AMMOTYPE_CROSSBOW:   qty = 5;             break;
		case AMMOTYPE_RIFLE:      qty = 10;            break;
		case AMMOTYPE_SHOTGUN:    qty = 5;             break;
		case AMMOTYPE_FARSIGHT:   qty = 4;             break;
		case AMMOTYPE_MAGNUM:     qty = 5;             break;
		case AMMOTYPE_DEVASTATOR: qty = 3;             break;
		case AMMOTYPE_REAPER:     qty = 100;           break;
		case AMMOTYPE_DART:       qty = 4;             break;
		case AMMOTYPE_CLOAK:      qty = TICKS(1200); break;
		case AMMOTYPE_BOOST:      qty = 2;             break;
		case AMMOTYPE_SEDATIVE:   qty = 16;            break;
		}

		if (qty > 1) {
			qty *= g_AmmoQuantityScale;
		}
	}

	return qty;
}

static void weaponGetPickupText(char *buffer, s32 weaponnum, bool dual)
{
	s32 playercount = PLAYERCOUNT();
	s32 full = playercount <= 2
		&& !(playercount == 2 && g_ScreenSplit == SCREENSPLIT_VERTICAL);
	s32 textid;
	bool plural = false;

	if (dual) {
		strcat(buffer, langGet(L_PROPOBJ_001)); // "Double"
	} else {
		if (full) {
			strcat(buffer, langGet(L_PROPOBJ_000)); // "Picked up"

			if (weaponnum == WEAPON_EYESPY && g_Vars.currentplayer->eyespy) {
				textid = L_PROPOBJ_050; // "your"
			} else if (weaponHasFlag(weaponnum, WEAPONFLAG_DETERMINER_F_SOME)) {
				textid = L_PROPOBJ_002; // "some"
			} else if (weaponHasFlag(weaponnum, WEAPONFLAG_DETERMINER_F_AN)) {
				textid = L_PROPOBJ_006; // "an"
			} else if (weaponHasFlag(weaponnum, WEAPONFLAG_DETERMINER_F_THE)) {
				textid = L_PROPOBJ_008; // "the"
			} else {
				textid = L_PROPOBJ_004; // "a"
			}

			strcat(buffer, langGet(textid));
		} else {
			if (weaponnum == WEAPON_EYESPY && g_Vars.currentplayer->eyespy) {
				textid = L_PROPOBJ_051; // "Your"
			} else if (weaponHasFlag(weaponnum, WEAPONFLAG_DETERMINER_S_SOME)) {
				textid = L_PROPOBJ_003; // "Some"
			} else if (weaponHasFlag(weaponnum, WEAPONFLAG_DETERMINER_S_AN)) {
				textid = L_PROPOBJ_007; // "An"
			} else if (weaponHasFlag(weaponnum, WEAPONFLAG_DETERMINER_S_THE)) {
				textid = L_PROPOBJ_009; // "The"
			} else {
				textid = L_PROPOBJ_005; // "A"
			}

			strcat(buffer, langGet(textid));
		}
	}

	if (full) {
		strcat(buffer, bgunGetName(weaponnum));
		plural = weaponHasFlag(weaponnum, WEAPONFLAG_DETERMINER_F_SOME);
	} else {
		strcat(buffer, bgunGetShortName(weaponnum));
		plural = weaponHasFlag(weaponnum, WEAPONFLAG_DETERMINER_S_SOME);
	}

	// Note that weapon names have a line break on the end which is undesirable
	// here. The code below removes them conditionally, then ends up removing
	// them unconditionally anyway which is a bit wasteful.

	if (plural) {
		if (buffer[strlen(buffer) - 1] == '\n') {
			buffer[strlen(buffer) - 1] = '\0';
		}

		strcat(buffer, "s");
	}

	if (buffer[strlen(buffer) - 1] == '\n') {
		buffer[strlen(buffer) - 1] = '\0';
	}

	strcat(buffer, ".\n");
}

void currentPlayerQueuePickupWeaponHudmsg(u32 weaponnum, bool dual)
{
	char buffer[100];

	buffer[0] = '\0';

	weaponGetPickupText(buffer, weaponnum, dual);
	hudmsgCreateWithFlags(buffer, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_ALLOWDUPES);
}


s32 propPickupByPlayer(struct prop *prop, bool showhudmsg)
{
	struct defaultobj *obj = prop->obj;
	s32 result;
	bool given = false;

	if (g_Vars.currentplayer->isdead || g_Vars.lvupdate240 == 0) {
		return TICKOP_NONE;
	}

	switch (obj->type) {
	case OBJTYPE_KEY:
		if (g_Vars.in_cutscene == false) {
			sndStart(var80095200, SFX_PICKUP_KEYCARD, NULL, -1, -1, -1, -1, -1);
		}

		if (showhudmsg) {
			char *text = invGetPickupTextByObj(obj);

			if (text == NULL) {
				text = langGet(L_PROPOBJ_040); // "Picked up a key."
			}

			hudmsgCreateWithFlags(text, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_ALLOWDUPES);
		}

		result = TICKOP_GIVETOPLAYER;
		break;
	case OBJTYPE_AMMOCRATE:
		{
			struct ammocrateobj *crate = (struct ammocrateobj *) prop->obj;
			s32 quantity = ammocrateGetPickupAmmoQty(crate);
			ammoHandlePickup(crate->ammotype, quantity, !g_Vars.in_cutscene, showhudmsg);
			result = TICKOP_FREE;
		}
		break;
	case OBJTYPE_MULTIAMMOCRATE:
		{
			struct multiammocrateobj *crate = (struct multiammocrateobj *)prop->obj;
			u32 stack;
			s32 i;

			for (i = 0; i != 19; i++) {
				s32 qty = crate->slots[i].quantity;

				if (!g_Vars.normmplayerisrunning) {
					qty *= g_AmmoQuantityScale;
				}

				ammoHandlePickup(i + 1, qty, false, showhudmsg);
			}

			if (g_Vars.in_cutscene == false) {
				sndStart(var80095200, SFX_PICKUP_AMMO, NULL, -1, -1, -1, -1, -1);
			}

			result = TICKOP_FREE;
		}
		break;
	case OBJTYPE_WEAPON:
		{
			struct weaponobj *weapon = (struct weaponobj *) prop->obj;
			bool sp70 = false;
			s32 ammotype;
			s32 count = 0;
			s32 sp64;

			if (g_Vars.normmplayerisrunning) {
				if (weapon->weaponnum == WEAPON_BRIEFCASE2) {
					sp64 = scenarioPickUpBriefcase(g_Vars.currentplayer->prop->chr, prop);

					if (sp64) {
						weaponPlayPickupSound(weapon->weaponnum);
					}

					return sp64;
				}

				if (weapon->weaponnum == WEAPON_DATAUPLINK) {
					sp64 = scenarioPickUpUplink(g_Vars.currentplayer->prop->chr, prop);

					if (sp64) {
						weaponPlayPickupSound(weapon->weaponnum);
					}

					return sp64;
				}
			}

			if (g_Vars.in_cutscene == false) {
				weaponPlayPickupSound(weapon->weaponnum);
			}

			if (obj->hidden & OBJHFLAG_HASTEXTOVERRIDE) {
				if (weapon->weaponnum <= WEAPON_PSYCHOSISGUN) {
					count = invGiveWeaponsByProp(prop);
					given = true;
				}

				if (showhudmsg) {
					char *text = invGetPickupTextByObj(obj);

					if (text) {
						hudmsgCreateWithFlags(text, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_ALLOWDUPES);
					} else {
						currentPlayerQueuePickupWeaponHudmsg(weapon->weaponnum, count == 2);
					}

					sp70 = true;
				}

				result = TICKOP_GIVETOPLAYER;
			} else {
				if (weapon->weaponnum == WEAPON_BOLT) {
					count = 1;
					given = true;
					ammoHandlePickup(AMMOTYPE_CROSSBOW, 1, !g_Vars.in_cutscene, true);
					result = TICKOP_FREE;
					showhudmsg = false;
					sp70 = true;
				} else {
					count = invGiveWeaponsByProp(prop);

					if (count) {
						sp70 = true;
					}

					given = true;

					if (showhudmsg) {
						char *text = invGetPickupTextByWeaponNum(weapon->weaponnum);

						if (text) {
							sp70 = true;
							hudmsgCreateWithFlags(text, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_ALLOWDUPES);
						} else {
							if (sp70) {
								currentPlayerQueuePickupWeaponHudmsg(weapon->weaponnum, count == 2);
							}
						}
					}

					result = TICKOP_FREE;
				}
			}

			if (count == 2
					&& bgunGetWeaponNum(HAND_RIGHT) == weapon->weaponnum
					&& bgunGetWeaponNum(HAND_LEFT) != weapon->weaponnum) {
				bgunEquipWeapon2(HAND_LEFT, weapon->weaponnum);
			}

			ammotype = bgunGetAmmoTypeForWeapon(weapon->weaponnum, FUNC_PRIMARY);

			if (ammotype) {
				s32 pickupqty = weaponGetPickupAmmoQty(weapon);

				if (pickupqty > 0) {
					s32 heldqty = bgunGetReservedAmmoCount(ammotype);

					if (bgunGetReservedAmmoCount(ammotype) < bgunGetCapacityByAmmotype(ammotype)) {
						heldqty += pickupqty;

						bgunSetAmmoQuantity(ammotype, heldqty);

						if (!sp70 && showhudmsg) {
							currentPlayerQueuePickupAmmoHudmsg(ammotype, pickupqty);
						}
					}
				}
			}

			if (weapon->weaponnum == WEAPON_SUPERDRAGON) {
				s32 pickupqty = weaponGetPickupAmmoQty(weapon);

				if (bgunGetReservedAmmoCount(AMMOTYPE_DEVASTATOR) < bgunGetCapacityByAmmotype(AMMOTYPE_DEVASTATOR)) {
					s32 quantity = bgunGetReservedAmmoCount(AMMOTYPE_DEVASTATOR) + 5;

					bgunSetAmmoQuantity(AMMOTYPE_DEVASTATOR, quantity);

					if (!sp70 && showhudmsg) {
						currentPlayerQueuePickupAmmoHudmsg(AMMOTYPE_DEVASTATOR, pickupqty);
					}
				}
			}

			if (weapon->weaponnum == WEAPON_EYESPY && g_Vars.currentplayer->eyespy == NULL) {
				playerInitEyespy();
			}
		}
		break;
	case OBJTYPE_SHIELD:
		{
			playerSetShieldFrac(((struct shieldobj *) prop->obj)->amount);

			if (!g_Vars.in_cutscene) {
				sndStart(var80095200, SFX_PICKUP_SHIELD, NULL, -1, -1, -1, -1, -1);
			}

			if (showhudmsg) {
				char *text = invGetPickupTextByObj(obj);

				if (text == NULL) {
					s32 playercount = PLAYERCOUNT();

					if (playercount <= 2 && !(playercount == 2 && g_ScreenSplit == SCREENSPLIT_VERTICAL)) {
						text = langGet(L_PROPOBJ_041); // "Picked up a shield."
					} else {
						text = langGet(L_PROPOBJ_042); // "A shield."
					}
				}

				hudmsgCreateWithFlags(text, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE);
			}

			result = TICKOP_FREE;
		}
		break;
	case OBJTYPE_BASIC:
	case OBJTYPE_ALARM:
	case OBJTYPE_SINGLEMONITOR:
	case OBJTYPE_MULTIMONITOR:
	case OBJTYPE_AUTOGUN:
	case OBJTYPE_DEBRIS:
	case OBJTYPE_GLASS:
	case OBJTYPE_TINTEDGLASS:
	default:
		if (g_Vars.in_cutscene == false) {
			sndStart(var80095200, SFX_PICKUP_KEYCARD, NULL, -1, -1, -1, -1, -1);
		}

		if (showhudmsg) {
			char *text = invGetPickupTextByObj(obj);

			if (text == NULL) {
				text = langGet(L_PROPOBJ_043); // "Picked up something."
			}

			hudmsgCreateWithFlags(text, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_ALLOWDUPES);
		}

		result = TICKOP_GIVETOPLAYER;
		break;
	}

	if (result == TICKOP_FREE && (obj->hidden & OBJHFLAG_TAGGED) == 0) {
		objFree(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
		return TICKOP_FREE;
	}

	if (result != TICKOP_NONE) {
		if (!given) {
			invGiveProp(prop);
		}

		return TICKOP_GIVETOPLAYER;
	}

	return TICKOP_NONE;
}

s32 objTestForPickup(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;
	struct prop *playerprop = g_Vars.currentplayer->prop;
	f32 xdiff = prop->pos.x - playerprop->pos.x;
	f32 ydiff = prop->pos.y - playerprop->pos.y;
	f32 zdiff = prop->pos.z - playerprop->pos.z;
	f32 range;
	bool usebigrange;
	bool pickup;

	if (func0f085194(obj)) {
		if (obj->flags & OBJFLAG_UNCOLLECTABLE) {
			return TICKOP_NONE;
		}
	} else {
		if ((obj->flags & OBJFLAG_COLLECTABLE) == 0) {
			return TICKOP_NONE;
		}
	}

	usebigrange = (obj->flags3 & OBJFLAG3_ONSHELF)
		&& (cheatIsActive(CHEAT_SMALLJO) || cheatIsActive(CHEAT_PLAYASELVIS));

	if (usebigrange) {
		range = 200 * 200;
	} else {
		range = 100 * 100;
	}

	pickup = xdiff * xdiff + zdiff * zdiff <= range && ydiff >= -200 && ydiff <= 200;

	if (!pickup) {
		return TICKOP_NONE;
	}

	if (obj->hidden & OBJHFLAG_REAPABLE) {
		return TICKOP_NONE;
	}

	if (obj->type == OBJTYPE_WEAPON) {
		struct weaponobj *weapon = prop->weapon;
		bool maybe = true;
		s32 leftweaponnum;
		s32 rightweaponnum;

		if (weapon->weaponnum == WEAPON_GRENADE
				|| weapon->weaponnum == WEAPON_GRENADEROUND
				|| weapon->weaponnum == WEAPON_NBOMB
				|| weapon->weaponnum == WEAPON_SKROCKET) {
			if (weapon->timer240 >= 0 || (obj->hidden & OBJHFLAG_REAPABLE)) {
				return TICKOP_NONE;
			}
		}

		if (weapon->weaponnum == WEAPON_REMOTEMINE
				|| weapon->weaponnum == WEAPON_PROXIMITYMINE
				|| weapon->weaponnum == WEAPON_TIMEDMINE
				|| (weapon->weaponnum == WEAPON_DRAGON && weapon->gunfunc == FUNC_SECONDARY)
				|| weapon->weaponnum == WEAPON_TRACERBUG
				|| weapon->weaponnum == WEAPON_TARGETAMPLIFIER
				|| weapon->weaponnum == WEAPON_COMMSRIDER
				|| weapon->weaponnum == WEAPON_ECMMINE) {
			if (weapon->timer240 >= 0 || (obj->hidden & OBJHFLAG_REAPABLE)) {
				return TICKOP_NONE;
			}
		}

		if (weapon->weaponnum == WEAPON_ROCKET
				|| weapon->weaponnum == WEAPON_HOMINGROCKET
				|| weapon->weaponnum == WEAPON_BOLT
				|| weapon->weaponnum == WEAPON_COMBATKNIFE) {
			if (obj->hidden & OBJHFLAG_PROJECTILE) {
				return TICKOP_NONE;
			}
		}

		if (invHasSingleWeaponExcAllGuns(weapon->weaponnum) && bgunGetAmmoTypeForWeapon(weapon->weaponnum, FUNC_PRIMARY)) {
			if (cheatIsActive(CHEAT_UNLIMITEDAMMO) || cheatIsActive(CHEAT_UNLIMITEDAMMONORELOADS)) {
				maybe = false;
			} else {
				maybe = bgunGetAmmoQtyForWeapon(weapon->weaponnum, FUNC_PRIMARY) >= bgunGetAmmoCapacityForWeapon(weapon->weaponnum, FUNC_PRIMARY);
			}

			if (weapon->weaponnum == WEAPON_SUPERDRAGON) {
				if (bgunGetAmmoQtyForWeapon(weapon->weaponnum, FUNC_SECONDARY) < bgunGetAmmoCapacityForWeapon(weapon->weaponnum, FUNC_SECONDARY)) {
					maybe = false;
				}
			}

			if (maybe) {
				if (weapon->dualweapon || weapon->dualweaponnum >= 0) {
					if (weapon->dualweapon) {
						leftweaponnum = rightweaponnum = weapon->dualweapon->weaponnum;
					} else {
						leftweaponnum = rightweaponnum = weapon->dualweaponnum;
					}

					if ((weapon->base.flags & OBJFLAG_DEACTIVATED)) {
						rightweaponnum = weapon->weaponnum;
					} else {
						leftweaponnum = weapon->weaponnum;
					}

					if (invHasDoubleWeaponExcAllGuns(leftweaponnum, rightweaponnum)) {
						return TICKOP_NONE;
					}
				} else {
					if (g_Vars.normmplayerisrunning
							&& weaponHasFlag(weapon->weaponnum, WEAPONFLAG_DUALWIELD)
							&& !invHasDoubleWeaponExcAllGuns(weapon->weaponnum, weapon->weaponnum)) {
						struct invitem *item = invFindSingleWeapon(weapon->weaponnum);

						if ((item && item->type_weap.pickuppad == weapon->base.pad) || weapon->base.pad < 0) {
							return TICKOP_NONE;
						}
					} else {
						return TICKOP_NONE;
					}
				}
			}
		}
	} else if (obj->type == OBJTYPE_AMMOCRATE) {
		struct ammocrateobj *crate = (struct ammocrateobj *) prop->obj;

		if (bgunGetReservedAmmoCount(crate->ammotype) >= bgunGetCapacityByAmmotype(crate->ammotype)) {
			if ((crate->ammotype != AMMOTYPE_GRENADE || invHasSingleWeaponExcAllGuns(WEAPON_GRENADE))
					&& (crate->ammotype != AMMOTYPE_CLOAK || invHasSingleWeaponExcAllGuns(WEAPON_CLOAKINGDEVICE))
					&& (crate->ammotype != AMMOTYPE_BOOST || invHasSingleWeaponExcAllGuns(WEAPON_COMBATBOOST))
					&& (crate->ammotype != AMMOTYPE_NBOMB || invHasSingleWeaponExcAllGuns(WEAPON_NBOMB))
					&& (crate->ammotype != AMMOTYPE_REMOTE_MINE || invHasSingleWeaponExcAllGuns(WEAPON_REMOTEMINE))
					&& (crate->ammotype != AMMOTYPE_PROXY_MINE || invHasSingleWeaponExcAllGuns(WEAPON_PROXIMITYMINE))
					&& (crate->ammotype != AMMOTYPE_TIMED_MINE || invHasSingleWeaponExcAllGuns(WEAPON_TIMEDMINE))
					&& (crate->ammotype != AMMOTYPE_KNIFE || invHasSingleWeaponExcAllGuns(WEAPON_COMBATKNIFE))) {
				return TICKOP_NONE;
			}
		}
	} else if (obj->type == OBJTYPE_MULTIAMMOCRATE) {
		struct multiammocrateobj *crate = (struct multiammocrateobj *) prop->obj;
		bool ignore = true;
		s32 i;

		if (objGetDestroyedLevel(obj)) {
			return TICKOP_NONE;
		}

		for (i = 0; i <= AMMOTYPE_NBOMB; i++) {
			s32 ammotype = i + 1;

			if (crate->slots[i].quantity > 0) {
				if (bgunGetReservedAmmoCount(ammotype) < bgunGetCapacityByAmmotype(ammotype)) {
					ignore = false;
					break;
				}

				if ((ammotype == AMMOTYPE_GRENADE && !invHasSingleWeaponExcAllGuns(WEAPON_GRENADE))
						|| (ammotype == AMMOTYPE_CLOAK && !invHasSingleWeaponExcAllGuns(WEAPON_CLOAKINGDEVICE))
						|| (ammotype == AMMOTYPE_BOOST && !invHasSingleWeaponExcAllGuns(WEAPON_COMBATBOOST))
						|| (ammotype == AMMOTYPE_NBOMB && !invHasSingleWeaponExcAllGuns(WEAPON_NBOMB))
						|| (ammotype == AMMOTYPE_REMOTE_MINE && !invHasSingleWeaponExcAllGuns(WEAPON_REMOTEMINE))
						|| (ammotype == AMMOTYPE_PROXY_MINE && !invHasSingleWeaponExcAllGuns(WEAPON_PROXIMITYMINE))
						|| (ammotype == AMMOTYPE_TIMED_MINE && !invHasSingleWeaponExcAllGuns(WEAPON_TIMEDMINE))
						|| (ammotype == AMMOTYPE_KNIFE && !invHasSingleWeaponExcAllGuns(WEAPON_COMBATKNIFE))) {
					ignore = false;
					break;
				}
			}
		}

		if (ignore) {
			return TICKOP_NONE;
		}
	} else if (obj->type == OBJTYPE_SHIELD) {
		struct shieldobj *shield = (struct shieldobj *) prop->obj;
		bool ignore = false;

		if (shield->amount <= playerGetShieldFrac()) {
			ignore = true;
		} else if (g_Vars.normmplayerisrunning
				&& g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE
				&& invHasBriefcase()) {
			ignore = true;
		}

		if (ignore) {
			return TICKOP_NONE;
		}
	} else {
		if (obj->flags & OBJFLAG_THROWNLAPTOP) {
			return TICKOP_NONE;
		}
	}


	// For disarmed weapons that are falling, picktimer timer is 1 second and
	// pickupby is set to the chr who disarmed. This makes it so only the
	// disarmer can pick up the weapon within the first second.
	// For thrown projectiles, the pickup timer is also 1 second but there is no
	// pickupby. This prevents the thrower from picking up their own projectile
	// within the first second, unless it's immediately bounced or landed.
	if ((obj->hidden & OBJHFLAG_PROJECTILE) && obj->projectile->pickuptimer240 > 0) {
		if (obj->projectile->pickupby == NULL) {
			if (obj->projectile->bouncecount == 0) {
				return TICKOP_NONE;
			}
		} else {
			if (obj->projectile->pickupby != g_Vars.currentplayer->prop) {
				return TICKOP_NONE;
			}
		}
	}

	if ((obj->flags2 & OBJFLAG2_PICKUPWITHOUTLOS) == 0
			&& !usebigrange
			&& cdTestLos05(&playerprop->pos, playerprop->rooms, &prop->pos, prop->rooms,
				CDTYPE_DOORS | CDTYPE_BG,
				GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT | GEOFLAG_BLOCK_SHOOT) == false) {
		return TICKOP_NONE;
	}

	return propPickupByPlayer(prop, true);
}

bool func0f0899dc(struct prop *prop, struct coord *arg1, f32 *arg2, f32 *arg3)
{
	if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		struct defaultobj *obj = prop->obj;
		Mtxf *matrix = model0001a60c(obj->model);

		arg1->z = matrix->m[3][2];

		if (arg1->z < 0) {
			arg1->x = matrix->m[3][0];
			arg1->y = matrix->m[3][1];

			arg3[0] = 0;
			arg3[1] = 0;

			arg2[0] = 0;
			arg2[1] = 0;

			func0f067d88(obj->model, &arg2[1], &arg2[0], &arg3[1], &arg3[0]);

			return true;
		}
	}

	return false;
}

void modelFreeVertices(s32 vtxstoretype, struct model *model)
{
	struct modelfiledata *modeldef = model->filedata;
	struct modelnode *node = modeldef->rootnode;

	while (node) {
		u32 type = node->type & 0xff;
		union modelrodata *rodata;
		union modelrwdata *rwdata;
		s32 newtype;

		switch (type) {
		case MODELNODETYPE_DL:
			rodata = node->rodata;
			rwdata = modelGetNodeRwData(model, node);

			if (modelIsNodeNotTvscreen(modeldef, node)) {
				if (rwdata->dl.vertices != rodata->dl.vertices) {
					vtxstoreFree(vtxstoretype, rwdata->dl.vertices);
					rwdata->dl.vertices = rodata->dl.vertices;
				}

				if ((u32)rwdata->dl.colours != ALIGN8((u32)rodata->dl.vertices + rodata->dl.numvertices * sizeof(struct gfxvtx))) {
					if (vtxstoretype == VTXSTORETYPE_OBJVTX) {
						newtype = VTXSTORETYPE_OBJCOL;
					} else {
						newtype = VTXSTORETYPE_CHRCOL;
					}

					vtxstoreFree(newtype, rwdata->dl.colours);

					rwdata->dl.colours = (struct colour *)ALIGN8((u32)rodata->dl.vertices + rodata->dl.numvertices * sizeof(struct gfxvtx));
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c784(model, node);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, node);
			break;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}
}

static struct weaponobj *weaponCreate(bool musthaveprop, bool musthavemodel, struct modelfiledata *filedata)
{
	s32 i;
	struct weaponobj *tmp;
	struct weaponobj *sp4c = NULL;
	struct weaponobj *sp48 = NULL;
	s32 sp44 = -1;
	s32 sp40 = -1;
	s32 sp3c = -1;

	for (i = g_NextWeaponSlot; true; ) {
		bool usable = false;

		if (g_WeaponSlots[i].base.prop == NULL) {
			if (!musthaveprop && !musthavemodel) {
				sp44 = i;
				break;
			}
		} else {
			if ((g_WeaponSlots[i].base.hidden & OBJHFLAG_PROJECTILE) == 0
					&& (g_WeaponSlots[i].base.hidden2 & OBJH2FLAG_CANREGEN) == 0
					&& (g_WeaponSlots[i].base.flags & OBJFLAG_00800000) == 0) {
				if (g_WeaponSlots[i].base.prop->parent) {
					if (g_WeaponSlots[i].base.hidden & OBJHFLAG_EMBEDDED) {
						usable = true;
					}
				} else {
					usable = true;
				}
			}
		}

		if (usable) {
			if (!musthavemodel || modelmgrCanSlotFitRwdata(g_WeaponSlots[i].base.model, filedata)) {
				if ((g_WeaponSlots[i].base.prop->flags & (PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) == 0 && sp40 < 0) {
					sp40 = i;
				}

				if (sp3c < 0) {
					sp3c = i;
				}
			}
		}

		i++;

		if (i >= g_MaxWeaponSlots) {
			i = 0;
		}

		if (i == g_NextWeaponSlot) {
			break;
		}
	}

	if (sp44 >= 0) {
		g_NextWeaponSlot = sp44 + 1;

		if (g_NextWeaponSlot >= g_MaxWeaponSlots) {
			g_NextWeaponSlot = 0;
		}

		return &g_WeaponSlots[sp44];
	}

	tmp = (struct weaponobj *)setupFindObjForReuse(OBJTYPE_WEAPON, (struct defaultobj **)&sp4c, (struct defaultobj **)&sp48, musthaveprop, musthavemodel, filedata);

	if (tmp) {
		return tmp;
	}

	if (sp40 >= 0) {
		if (g_WeaponSlots[sp40].base.prop) {
			objFreePermanently(&g_WeaponSlots[sp40].base, true);
		}

		g_NextWeaponSlot = sp40 + 1;

		if (g_NextWeaponSlot >= g_MaxWeaponSlots) {
			g_NextWeaponSlot = 0;
		}

		return &g_WeaponSlots[sp40];
	}

	if (sp4c) {
		if (sp4c->base.prop) {
			objFreePermanently(&sp4c->base, true);
		}

		return sp4c;
	}

	if (sp3c >= 0) {
		if (g_WeaponSlots[sp3c].base.prop) {
			objFreePermanently(&g_WeaponSlots[sp3c].base, true);
		}

		g_NextWeaponSlot = sp3c + 1;

		if (g_NextWeaponSlot >= g_MaxWeaponSlots) {
			g_NextWeaponSlot = 0;
		}

		return &g_WeaponSlots[sp3c];
	}

	if (sp48) {
		if (sp48->base.prop) {
			objFreePermanently(&sp48->base, true);
		}

		return sp48;
	}

	return NULL;
}

static struct defaultobj *debrisAllocate(void)
{
	s32 i;

	// Try to find an unused slot
	for (i = 0; i < g_MaxDebrisSlots; i++) {
		if (g_DebrisSlots[i].prop == NULL) {
			return &g_DebrisSlots[i];
		}
	}

	// Try to find one that's landed and offscreen
	for (i = 0; i < g_MaxDebrisSlots; i++) {
		if ((g_DebrisSlots[i].hidden & OBJHFLAG_PROJECTILE) == 0
				&& (g_DebrisSlots[i].hidden2 & OBJH2FLAG_CANREGEN) == 0
				&& g_DebrisSlots[i].prop->parent == NULL
				&& (g_DebrisSlots[i].prop->flags & (PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) == 0) {
			objFreePermanently(&g_DebrisSlots[i], true);
			return &g_DebrisSlots[i];
		}
	}

	// Same as above but onscreen
	for (i = 0; i < g_MaxDebrisSlots; i++) {
		if ((g_DebrisSlots[i].hidden & OBJHFLAG_PROJECTILE) == 0
				&& (g_DebrisSlots[i].hidden2 & OBJH2FLAG_CANREGEN) == 0
				&& g_DebrisSlots[i].prop->parent == NULL) {
			objFreePermanently(&g_DebrisSlots[i], true);
			return &g_DebrisSlots[i];
		}
	}

	return NULL;
}

void playerActivateRemoteMineDetonator(s32 playernum)
{
	struct prop *prop = g_Vars.activeprops;

	while (prop) {
		if (prop->type == PROPTYPE_WEAPON && prop->weapon->weaponnum == WEAPON_REMOTEMINE) {
			if (!prop->active) {
				propUnpause(prop);
			}

			prop->forceonetick = true;
		}

		prop = prop->next;
	}

	g_PlayersDetonatingMines |= 1 << playernum;

	sndStart(var80095200, SFX_DETONATE, 0, -1, -1, -1, -1, -1);

	bgunStartDetonateAnimation(playernum);
}

static struct weaponobj *weaponFindChildByWeaponNum(s32 weaponnum, struct prop *prop)
{
	struct weaponobj *weapon;
	struct prop *child;

	if (prop->type == PROPTYPE_WEAPON && weaponnum == prop->weapon->weaponnum) {
		return prop->weapon;
	}

	child = prop->child;

	while (child) {
		weapon = weaponFindChildByWeaponNum(weaponnum, child);

		if (weapon) {
			return weapon;
		}

		child = child->next;
	}

	return NULL;
}

struct weaponobj *weaponFindLanded(s32 weaponnum)
{
	struct prop *prop = g_Vars.activeprops;

	while (prop) {
		struct weaponobj *weapon = weaponFindChildByWeaponNum(weaponnum, prop);

		if (weapon && (weapon->base.hidden & OBJHFLAG_PROJECTILE) == 0) {
			return weapon;
		}

		prop = prop->next;
	}

	return NULL;
}

static void weaponRegisterProxy(struct weaponobj *weapon)
{
	s32 i;

	if (g_NumProxies < ARRAYCOUNT(g_Proxies)) {
		g_Proxies[g_NumProxies] = weapon;
		g_NumProxies++;
	}
}

static void weaponUnregisterProxy(struct weaponobj *weapon)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Proxies); i++) {
		if (g_Proxies[i] == weapon) {
			g_Proxies[i] = g_Proxies[g_NumProxies - 1];
			g_NumProxies--;
			return;
		}
	}
}

void coordTriggerProxies(struct coord *pos, bool arg1)
{
	s32 i;

	for (i = 0; i < g_NumProxies; i++) {
		struct weaponobj *weapon = g_Proxies[i];

		if (weapon->timer240 == 1) {
			if (weapon->weaponnum != WEAPON_GRENADE || arg1 == true) {
				f32 xdiff;
				f32 ydiff;
				f32 zdiff;
				f32 range = 250 * 250;

				if (weapon->weaponnum == WEAPON_DRAGON) {
					range += range;
				}

				xdiff = pos->x - weapon->base.prop->pos.x;
				ydiff = pos->y - weapon->base.prop->pos.y;
				zdiff = pos->z - weapon->base.prop->pos.z;

				if (xdiff * xdiff + ydiff * ydiff + zdiff * zdiff < range) {
					weapon->timer240 = 0;
				}
			}
		}
	}
}

static void chrsTriggerProxies(void)
{
	s32 numchrs = g_NumChrSlots;
	s32 i;

	for (i = 0; i < numchrs; i++) {
		struct chrdata *chr = &g_ChrSlots[i];
		struct coord pos;

		if (chr->prop
				&& !chrIsDead(chr)
				&& (chr->chrflags & CHRCFLAG_HIDDEN) == 0
				&& (chr->prop->flags & PROPFLAG_ENABLED)
				&& chr->model) {
			chrCalculatePosition(chr, &pos);
			coordTriggerProxies(&pos, true);
		}
	}
}

void propweaponSetDual(struct weaponobj *weapon1, struct weaponobj *weapon2)
{
	weapon1->dualweaponnum = weapon2->weaponnum;
	weapon1->dualweapon = weapon2;
	weapon2->dualweaponnum = weapon1->weaponnum;
	weapon2->dualweapon = weapon1;
}

static struct prop *func0f08adc8(struct weaponobj *weapon, struct modelfiledata *filedata, struct prop *prop, struct model *model)
{
	prop = objInit(&weapon->base, filedata, prop, model);

	if (prop) {
		prop->type = PROPTYPE_WEAPON;
		weaponSetGunfireVisible(prop, false, -1);
	}

	return prop;
}

struct prop *func0f08ae0c(struct weaponobj *weapon, struct modelfiledata *filedata)
{
	struct prop *prop = objInitWithModelDef(&weapon->base, filedata);

	if (prop) {
		prop->type = PROPTYPE_WEAPON;
		weaponSetGunfireVisible(prop, false, -1);
	}

	return prop;
}

bool chrEquipWeapon(struct weaponobj *weapon, struct chrdata *chr)
{
	u32 stack1;
	s32 handnum = (weapon->base.flags & OBJFLAG_WEAPON_LEFTHANDED) ? HAND_LEFT : HAND_RIGHT;
	u32 stack2[2];

	if (weapon->base.prop && weapon->base.model) {
		if (g_Vars.mplayerisrunning) {
			s32 playernum = mpPlayerGetIndex(chr);

			weapon->base.hidden &= 0x0fffffff;
			weapon->base.hidden |= (playernum << 28) & 0xf0000000;
		}

		if ((weapon->base.flags & OBJFLAG_WEAPON_AICANNOTUSE) == 0) {
			if (chr->weapons_held[handnum]) {
				if (chr->aibot) {
					chr->weapons_held[handnum]->weapon->base.hidden |= OBJHFLAG_REAPABLE;
					chr->weapons_held[handnum] = NULL;
				} else {
					return false;
				}
			}

			if (!chr->weapons_held[handnum]) {
				if (chr->model->filedata->skel == &g_SkelChr) {
					weapon->base.model->attachedtomodel = chr->model;

					if (handnum == HAND_RIGHT) {
						weapon->base.model->attachedtonode = modelGetPart(chr->model->filedata, MODELPART_CHR_RIGHTHAND);
					} else {
						weapon->base.model->attachedtonode = modelGetPart(chr->model->filedata, MODELPART_CHR_LEFTHAND);
					}

					chr->weapons_held[handnum] = weapon->base.prop;

					if ((weapon->base.flags & OBJFLAG_80000000) && chr->weapons_held[1 - handnum]) {
						propweaponSetDual(weapon, chr->weapons_held[1 - handnum]->weapon);
					}
				} else if (chr->model->filedata->skel == &g_SkelSkedar) {
					weapon->base.model->attachedtomodel = chr->model;

					if (handnum == HAND_RIGHT) {
						weapon->base.model->attachedtonode = modelGetPart(chr->model->filedata, MODELPART_SKEDAR_RIGHTHAND);
					} else {
						weapon->base.model->attachedtonode = modelGetPart(chr->model->filedata, MODELPART_SKEDAR_LEFTHAND);
					}

					chr->weapons_held[handnum] = weapon->base.prop;

					if ((weapon->base.flags & OBJFLAG_80000000) && chr->weapons_held[1 - handnum]) {
						propweaponSetDual(weapon, chr->weapons_held[1 - handnum]->weapon);
					}
				} else {
					return false;
				}
			}
		}

		propReparent(weapon->base.prop, chr->prop);
	} else {
		return false;
	}

	return true;
}

static struct prop *func0f08b108(struct weaponobj *weapon, struct chrdata *chr, struct modelfiledata *filedata, struct prop *prop, struct model *model)
{
	prop = func0f08adc8(weapon, filedata, prop, model);

	if (prop && weapon->base.model) {
		f32 scale = weapon->base.extrascale * (1.0f / 256.0f);

		weapon->base.model->scale *= scale;

		if (!chrEquipWeapon(weapon, chr)) {
			propFree(prop);
			prop = NULL;
			weapon->base.prop = NULL;

			modelmgrFreeModel(weapon->base.model);
			weapon->base.model = NULL;
		}
	} else {
		if (prop) {
			propFree(prop);
			prop = NULL;
			weapon->base.prop = NULL;
		}

		if (weapon->base.model) {
			modelmgrFreeModel(weapon->base.model);
			weapon->base.model = NULL;
		}
	}

	return prop;
}

static void func0f08b208(struct weaponobj *weapon, struct chrdata *chr)
{
	u32 stack;
	s32 modelnum = weapon->base.modelnum;

	setupLoadModeldef(modelnum);
	func0f08b108(weapon, chr, g_ModelStates[modelnum].filedata, 0, 0);
}

void func0f08b25c(struct weaponobj *weapon, struct chrdata *chr)
{
	func0f08b208(weapon, chr);
}

struct autogunobj *laptopDeploy(s32 modelnum, struct gset *gset, struct chrdata *chr)
{
	struct modelfiledata *filedata;
	struct prop *prop;
	struct model *model;
	struct autogunobj *laptop = NULL;
	s32 index;

	if (g_Vars.normmplayerisrunning) {
		index = mpPlayerGetIndex(chr);
	} else {
		index = playermgrGetPlayerNumByProp(chr->prop);
	}

	if (index >= 0 && index < g_MaxThrownLaptops) {
		setupLoadModeldef(modelnum);
		filedata = g_ModelStates[modelnum].filedata;
		laptop = &g_ThrownLaptops[index];

		if (laptop->base.prop) {
			explosionCreateSimple(NULL, &laptop->base.prop->pos, laptop->base.prop->rooms, EXPLOSIONTYPE_LAPTOP, index);
			objFreePermanently(&laptop->base, true);
		}

		prop = propAllocate();
		model = modelmgrInstantiateModelWithoutAnim(filedata);

		if (prop == NULL) {
			prop = propAllocate();
		}

		if (model == NULL) {
			model = modelmgrInstantiateModelWithoutAnim(filedata);
		}

		if (laptop && prop && model) {
			struct defaultobj tmp = {
				256,                    // extrascale
				0,                      // hidden2
				OBJTYPE_AUTOGUN,        // type
				0,                      // modelnum
				1,                      // pad
				0,                      // flags
				0,                      // flags2
				0,                      // flags3
				NULL,                   // prop
				NULL,                   // model
				1, 0, 0,                // realrot
				0, 1, 0,
				0, 0, 1,
				0,                      // hidden
				NULL,                   // geo
				NULL,                   // projectile
				0,                      // damage
				1000,                   // maxdamage
				0xff, 0xff, 0xff, 0x00, // shadecol
				0xff, 0xff, 0xff, 0x00, // nextcol
				0x0fff,                 // floorcol
				0,                      // tiles
			};

			laptop->base = tmp;
			laptop->base.modelnum = modelnum;

			prop = objInit(&laptop->base, filedata, prop, model);

			laptop->targetpad = -1;
			laptop->aimdist = 5000;
			laptop->target = NULL;
			laptop->targetteam = ~chr->team & 0xff;
			laptop->nextchrtest = 0;
			laptop->firecount = 0;
			laptop->lastseebond60 = -1;
			laptop->lastaimbond60 = -1;
			laptop->allowsoundframe = -1;
			laptop->firing = false;
			laptop->yspeed = 0;
			laptop->xspeed = 0;
			laptop->barrelspeed = 0;
			laptop->barrelrot = 0;
			laptop->shotbondsum = 0;

			if (chr->aibot) {
				laptop->ammoquantity = botactTryRemoveAmmoFromReserve(chr->aibot, WEAPON_LAPTOPGUN, FUNC_PRIMARY, 200);
			} else if (chr->prop->type == PROPTYPE_PLAYER) {
				s32 qty;
				s32 prevplayernum = g_Vars.currentplayernum;

				setCurrentPlayerNum(playermgrGetPlayerNumByProp(chr->prop));
				qty = bgunGetAmmoQtyForWeapon(WEAPON_LAPTOPGUN, FUNC_PRIMARY);

				if (qty >= 200) {
					laptop->ammoquantity = 200;
				} else {
					laptop->ammoquantity = qty;
				}

				if (cheatIsActive(CHEAT_UNLIMITEDAMMOLAPTOP)) {
					laptop->ammoquantity = 255;
				} else {
					qty -= laptop->ammoquantity;
				}

				bgunSetAmmoQtyForWeapon(WEAPON_LAPTOPGUN, FUNC_PRIMARY, qty);
				setCurrentPlayerNum(prevplayernum);
			} else {
				laptop->ammoquantity = 255;
			}

			laptop->beam = &g_ThrownLaptopBeams[index];
			laptop->beam->age = -1;
			laptop->yzero = 0;
			laptop->xzero = 0;
			laptop->yrot = 0;
			laptop->xrot = 0;
			laptop->ymaxleft = 12.56f;
			laptop->ymaxright = -12.56f;
			laptop->maxspeed = PALUPF(0.0697f);

			prop->forcetick = true;

			laptop->base.hidden |= OBJHFLAG_TAGGED;
			laptop->base.flags |= OBJFLAG_THROWNLAPTOP | OBJFLAG_01000000 | OBJFLAG_20000000;
			laptop->base.flags3 |= OBJFLAG3_INTERACTABLE | OBJFLAG3_08000000;
		} else {
			if (model) {
				modelmgrFreeModel(model);
			}

			if (prop) {
				propFree(prop);
			}

			laptop = NULL;
		}
	}

	return laptop;
}

struct weaponobj *weaponCreateProjectileFromGset(s32 modelnum, struct gset *gset, struct chrdata *chr)
{
	struct modelfiledata *modeldef;
	struct prop *prop;
	struct model *model;
	struct weaponobj *weapon;

	setupLoadModeldef(modelnum);

	modeldef = g_ModelStates[modelnum].filedata;
	prop = propAllocate();
	model = modelmgrInstantiateModelWithoutAnim(modeldef);

	weapon = weaponCreate(prop == NULL, model == NULL, modeldef);

	if (prop == NULL) {
		prop = propAllocate();
	}

	if (model == NULL) {
		model = modelmgrInstantiateModelWithoutAnim(modeldef);
	}

	if (weapon && prop && model) {
		struct weaponobj tmp = {
			256,                    // extrascale
			0,                      // hidden2
			OBJTYPE_WEAPON,         // type
			0,                      // modelnum
			-1,                     // pad
			OBJFLAG_00000001,       // flags
			0,                      // flags2
			0,                      // flags3
			NULL,                   // prop
			NULL,                   // model
			1, 0, 0,                // realrot
			0, 1, 0,
			0, 0, 1,
			0,                      // hidden
			NULL,                   // geo
			NULL,                   // projectile
			0,                      // damage
			1000,                   // maxdamage
			0xff, 0xff, 0xff, 0x00, // shadecol
			0xff, 0xff, 0xff, 0x00, // nextcol
			0x0fff,                 // floorcol
			0,                      // tiles
			0,                      // weaponnum
			0,                      // unk5d
			0,                      // unk5e
			0,                      // gunfunc
			0,                      // fadeouttimer60
			-1,                     // dualweaponnum
			-1,                     // timer240
			NULL,                   // dualweapon
		};

		*weapon = tmp;

		weapon->weaponnum = gset->weaponnum;
		weapon->unk5d = gset->unk0639;
		weapon->unk5e = gset->unk063a;
		weapon->gunfunc = gset->weaponfunc;

		// This switch is useless because everything uses the same case
		switch (gset->weaponnum) {
		case WEAPON_SUPERDRAGON:
		case WEAPON_DEVASTATOR:
		case WEAPON_ROCKETLAUNCHER:
		case WEAPON_SLAYER:
		case WEAPON_COMBATKNIFE:
		case WEAPON_CROSSBOW:
		case WEAPON_GRENADE:
		case WEAPON_NBOMB:
		case WEAPON_TIMEDMINE:
		case WEAPON_PROXIMITYMINE:
		case WEAPON_REMOTEMINE:
		case WEAPON_ROCKETLAUNCHER_34:
		default:
			weapon->base.modelnum = modelnum;

			prop = func0f08adc8(weapon, modeldef, prop, model);

			if (g_Vars.mplayerisrunning) {
				s32 index = mpPlayerGetIndex(chr);

				weapon->base.hidden &= 0x0fffffff;
				weapon->base.hidden |= ((index << 28) & 0xf0000000);
			}

			prop->forcetick = true;
			break;
		}
	} else {
		if (weapon) {
			weapon->base.prop = NULL;
			weapon->base.model = NULL;
		}

		weapon = NULL;

		if (model) {
			modelmgrFreeModel(model);
		}

		if (prop) {
			propFree(prop);
		}
	}

	return weapon;
}

struct weaponobj *weaponCreateProjectileFromWeaponNum(s32 modelnum, s32 weaponnum, struct chrdata *chr)
{
	struct gset gset = {0};
	gset.weaponnum = weaponnum;

	return weaponCreateProjectileFromGset(modelnum, &gset, chr);
}

void weaponDeleteFromChr(struct chrdata *chr, s32 hand)
{
	if (chr && chr->weapons_held[hand]) {
		struct defaultobj *obj = chr->weapons_held[hand]->obj;
		obj->hidden |= OBJHFLAG_REAPABLE;
	}
}

struct prop *weaponCreateForChr(struct chrdata *chr, s32 modelnum, s32 weaponnum, u32 flags, struct weaponobj *obj, struct modelfiledata *filedata)
{
	struct prop *prop;
	struct model *model;

	if (filedata == NULL) {
		setupLoadModeldef(modelnum);
		filedata = g_ModelStates[modelnum].filedata;
	}

	prop = propAllocate();
	model = modelmgrInstantiateModelWithoutAnim(filedata);

	if (obj == NULL) {
		obj = weaponCreate(prop == NULL, model == NULL, filedata);
	}

	if (prop == NULL) {
		prop = propAllocate();
	}

	if (model == NULL) {
		model = modelmgrInstantiateModelWithoutAnim(filedata);
	}

	if (obj && prop && model) {
		struct weaponobj tmp = {
			256,                    // extrascale
			0,                      // hidden2
			OBJTYPE_WEAPON,         // type
			0,                      // modelnum
			0,                      // pad
			OBJFLAG_00000001 | OBJFLAG_ASSIGNEDTOCHR, // flags
			0,                      // flags2
			0,                      // flags3
			NULL,                   // prop
			NULL,                   // model
			1, 0, 0,                // realrot
			0, 1, 0,
			0, 0, 1,
			0,                      // hidden
			NULL,                   // geo
			NULL,                   // projectile
			0,                      // damage
			1000,                   // maxdamage
			0xff, 0xff, 0xff, 0x00, // shadecol
			0xff, 0xff, 0xff, 0x00, // nextcol
			0x0fff,                 // floorcol
			0,                      // tiles
			0,                      // weaponnum
			0,                      // unk5d
			0,                      // unk5e
			0,                      // gunfunc
			0,                      // fadeouttimer60
			-1,                     // dualweaponnum
			-1,                     // timer240
			NULL,                   // dualweapon
		};

		*obj = tmp;

		obj->weaponnum = weaponnum;
		obj->gunfunc = FUNC_PRIMARY;
		obj->unk5e = 0;
		obj->unk5d = 0;
		obj->base.modelnum = modelnum;
		obj->base.flags = flags | OBJFLAG_ASSIGNEDTOCHR;
		obj->base.pad = chr->chrnum;

		prop = func0f08b108(obj, chr, filedata, prop, model);
	} else {
		if (model) {
			modelmgrFreeModel(model);
		}

		if (prop) {
			propFree(prop);
			prop = NULL;
		}

		if (obj) {
			obj->base.prop = NULL;
			obj->base.model = NULL;
		}
	}

	return prop;
}

struct prop *chrGiveWeapon(struct chrdata *chr, s32 model, s32 weaponnum, u32 flags)
{
	return weaponCreateForChr(chr, model, weaponnum, flags, NULL, NULL);
}

void weaponSetGunfireVisible(struct prop *prop, bool visible, s16 room)
{
	u32 stack[4];
	bool flash = false;
	struct defaultobj *obj = prop->obj;
	struct modelnode *node1;
	struct modelnode *node2;
	union modelrwdata *rwdata1;
	union modelrwdata *rwdata2;

	if (obj && obj->type == OBJTYPE_WEAPON) {
		struct model *model = obj->model;

		if (model && model->filedata->skel == &g_SkelChrGun) {
			node1 = modelGetPart(model->filedata, MODELPART_CHRGUN_GUNFIRE);

			if (node1) {
				rwdata1 = modelGetNodeRwData(model, node1);
				rwdata1->chrgunfire.visible = visible;

				if (visible) {
					flash = true;
				}
			}

			node2 = modelGetPart(model->filedata, MODELPART_CHRGUN_0002);

			if (node2) {
				rwdata2 = modelGetNodeRwData(model, node2);
				rwdata2->toggle.visible = visible;

				if (visible) {
					flash = true;
				}
			}
		}
	}

	if (flash && room != -1) {
		roomAdjustLighting(room, 48, 128);
	}
}

static bool doorIsUnlocked(struct prop *playerprop, struct prop *doorprop)
{
	struct doorobj *door = doorprop->door;
	bool canopen = false;

	if (door->keyflags == 0) {
		canopen = true;
	} else if (invHasKeyFlags(door->keyflags)) {
		canopen = true;
	} else {
		if (posIsInFrontOfDoor(&playerprop->pos, door)) {
			if ((door->base.flags2 & OBJFLAG2_LOCKEDBACK)
					&& (door->base.flags2 & OBJFLAG2_LOCKEDFRONT) == 0) {
				canopen = true;
			}
		} else {
			if ((door->base.flags2 & OBJFLAG2_LOCKEDBACK) == 0
					&& (door->base.flags2 & OBJFLAG2_LOCKEDFRONT)) {
				canopen = true;
			}
		}
	}

	return canopen;
}

static bool doorIsPosInRange(struct doorobj *door, struct coord *pos, f32 distance, bool isbike)
{
	struct coord range;

	if ((door->doorflags & DOORFLAG_LONGRANGE) || isbike) {
		distance += 400;
	} else {
		distance += 200;
	}

	range.x = distance;
	range.y = 0;
	range.z = 0;

	if (door->doortype == DOORTYPE_VERTICAL
			|| door->doortype == DOORTYPE_SLIDING
			|| door->doortype == DOORTYPE_SWINGING) {
		if (func0f0678f8(pos, &range, door->base.pad)) {
			return true;
		}
	}

	return false;
}

static bool doorIsObjInRange(struct doorobj *door, struct defaultobj *obj, bool isbike)
{
	struct modelrodata_bbox *bbox = objFindBboxRodata(obj);
	f32 scale = 0;

	if (scale < bbox->xmin) {
		scale = bbox->xmin;
	}

	if (scale < -bbox->xmax) {
		scale = -bbox->xmax;
	}

	if (scale < bbox->ymin) {
		scale = bbox->ymin;
	}

	if (scale < -bbox->ymax) {
		scale = -bbox->ymax;
	}

	if (scale < bbox->zmin) {
		scale = bbox->zmin;
	}

	if (scale < -bbox->zmax) {
		scale = -bbox->zmax;
	}

	scale *= obj->model->scale;

	return doorIsPosInRange(door, &obj->prop->pos, scale, isbike);
}

static bool vectorIsInFrontOfDoor(struct doorobj *door, struct coord *vector)
{
	s32 result;
	struct pad *pad = &g_Pads[door->base.pad];

	result = vector->f[0] * pad->normal.f[0] + vector->f[1] * pad->normal.f[1] + vector->f[2] * pad->normal.f[2] >= 0.0f;

	if (door->doorflags & DOORFLAG_FLIP) {
		result = !result;
	}

	return result;
}

/**
 * Return true if there are no chrs or grabbed/mounted objects within opening
 * range of the door (for automatic doors).
 */
static bool doorIsRangeEmpty(struct doorobj *door)
{
	u32 stack;
	s16 *propnumptr;
	s16 propnums[256];

	roomGetProps(door->base.prop->rooms, propnums, 256);
	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop->type & (PROPTYPE_CHR | PROPTYPE_PLAYER)) {
			if (doorIsPosInRange(door, &prop->pos, 0, false)) {
				return false;
			}
		} else if (prop->type == PROPTYPE_OBJ) {
			if (prop->obj->hidden & (OBJHFLAG_MOUNTED | OBJHFLAG_GRABBED)
					&& doorIsObjInRange(door, prop->obj, (prop->obj->hidden & OBJHFLAG_MOUNTED) != 0)) {
				return false;
			}
		}

		propnumptr++;
	}

	return true;
}

/**
 * Find automatic doors and open them if the player is close to them.
 */
void doorsCheckAutomatic(void)
{
	struct prop *doorprop;
	s16 *propnumptr;
	s16 propnums[256];

	roomGetProps(g_Vars.currentplayer->prop->rooms, propnums, 256);
	propnumptr = propnums;

	while (*propnumptr >= 0) {
		doorprop = &g_Vars.props[*propnumptr];

		if (doorprop->type == PROPTYPE_DOOR) {
			struct doorobj *door = doorprop->door;

			if ((door->doorflags & DOORFLAG_AUTOMATIC)
					&& doorIsUnlocked(g_Vars.currentplayer->prop, doorprop)
					&& (door->mode == DOORMODE_CLOSING || (door->mode == DOORMODE_IDLE && door->frac <= 0))) {
				bool canopen = false;
				struct defaultobj *obj = NULL;
				bool isbike = false;
				struct doorobj *sibling;

				if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
					obj = bmoveGetGrabbedProp()->obj;
				} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
					obj = bmoveGetHoverbike()->obj;
					isbike = true;
				}

				if ((posIsInFrontOfDoor(&g_Vars.currentplayer->prop->pos, door) != vectorIsInFrontOfDoor(door, &g_Vars.currentplayer->bond2.unk00)) != 0) {
					canopen = doorIsPosInRange(door, &g_Vars.currentplayer->prop->pos, 0, isbike);

					if (!canopen && obj) {
						canopen = doorIsObjInRange(door, obj, isbike);
					}
				}

				sibling = door->sibling;

				while (sibling && sibling != door && !canopen) {
					if ((posIsInFrontOfDoor(&g_Vars.currentplayer->prop->pos, sibling) != vectorIsInFrontOfDoor(sibling, &g_Vars.currentplayer->bond2.unk00)) != 0) {
						canopen = doorIsPosInRange(sibling, &g_Vars.currentplayer->prop->pos, 0, isbike);

						if (!canopen && obj) {
							canopen = doorIsObjInRange(door, obj, isbike);
						}
					}

					sibling = sibling->sibling;
				}

				if (canopen) {
					doorsRequestMode(door, DOORMODE_OPENING);
				}
			}
		}

		propnumptr++;
	}
}

static void func0f08c424(struct doorobj *door, Mtxf *matrix)
{
	mtx3ToMtx4(door->base.realrot, matrix);
	mtx4SetTranslation(&door->base.prop->pos, matrix);

	if (door->doorflags & DOORFLAG_FLIP) {
		mtx00015edc(-1, matrix);
	}
}

static void doorGetBbox(struct doorobj *door, struct modelrodata_bbox *dst)
{
	struct modelrodata_bbox *bbox = modelFindBboxRodata(door->base.model);

	*dst = *bbox;

	if (door->doorflags & DOORFLAG_0004) {
		if (door->doortype == DOORTYPE_VERTICAL) {
			dst->ymax = bbox->ymax + (bbox->ymin - bbox->ymax) * door->frac;
		} else {
			dst->xmin = bbox->xmin + (bbox->xmax - bbox->xmin) * door->frac;
		}
	}
}

void doorUpdateTiles(struct doorobj *door)
{
	struct modelrodata_bbox bbox;
	Mtxf spdc;
	struct geoblock *geo;
	Mtxf sp98;
	struct coord sp8c;
	struct coord sp80;
	struct pad *pad;

	if (door->doorflags & DOORFLAG_0080) {
		door->base.prop->pos.x = door->unk98.x * door->frac + door->startpos.x;
		door->base.prop->pos.y = door->unk98.y * door->frac + door->startpos.y;
		door->base.prop->pos.z = door->unk98.z * door->frac + door->startpos.z;
	} else if (door->doortype == DOORTYPE_SWINGING
			|| door->doortype == DOORTYPE_AZTECCHAIR
			|| door->doortype == DOORTYPE_HULL) {
		pad = &g_Pads[door->base.pad];

		sp8c.x = pad->pos.x + pad->up.x * pad->bbox.ymin;
		sp8c.y = pad->pos.y + pad->up.y * pad->bbox.ymin;
		sp8c.z = pad->pos.z + pad->up.z * pad->bbox.ymin;

		if (door->doortype == DOORTYPE_AZTECCHAIR) {
			sp8c.x += pad->normal.x * pad->bbox.xmax;
			sp8c.y += pad->normal.y * pad->bbox.xmax;
			sp8c.z += pad->normal.z * pad->bbox.xmax;
		} else if (door->doortype == DOORTYPE_HULL) {
			sp8c.x += pad->look.x * pad->bbox.zmin;
			sp8c.y += pad->look.y * pad->bbox.zmin;
			sp8c.z += pad->look.z * pad->bbox.zmin;
		} else {
			if (door->base.flags & OBJFLAG_DOOR_OPENTOFRONT) {
				sp8c.x += pad->normal.x * pad->bbox.xmax;
				sp8c.y += pad->normal.y * pad->bbox.xmax;
				sp8c.z += pad->normal.z * pad->bbox.xmax;
			} else {
				sp8c.x += pad->normal.x * pad->bbox.xmin;
				sp8c.y += pad->normal.y * pad->bbox.xmin;
				sp8c.z += pad->normal.z * pad->bbox.xmin;
			}
		}

		sp80.x = door->startpos.x - sp8c.x;
		sp80.y = door->startpos.y - sp8c.y;
		sp80.z = door->startpos.z - sp8c.z;

		mtx3ToMtx4(door->mtx98, &spdc);
		mtx4LoadTranslation(&sp80, &sp98);
		mtx4MultMtx4InPlace(&sp98, &spdc);

		if (door->doortype == DOORTYPE_AZTECCHAIR) {
			if (door->base.flags & OBJFLAG_DOOR_OPENTOFRONT) {
				mtx4LoadZRotation(M_BADTAU - door->frac * 0.017450513318181f, &sp98);
			} else {
				mtx4LoadZRotation(door->frac * 0.017450513318181f, &sp98);
			}
		} else if (door->doortype == DOORTYPE_HULL) {
			if (door->base.flags & OBJFLAG_DOOR_OPENTOFRONT) {
				guRotateF(sp98.m, 360 - door->frac, pad->normal.x, pad->normal.y, pad->normal.z);
			} else {
				guRotateF(sp98.m, door->frac, pad->normal.x, pad->normal.y, pad->normal.z);
			}
		} else {
			if (door->base.flags & OBJFLAG_DOOR_OPENTOFRONT) {
				mtx4LoadYRotation(M_BADTAU - door->frac * 0.017450513318181f, &sp98);
			} else {
				mtx4LoadYRotation(door->frac * 0.017450513318181f, &sp98);
			}
		}

		mtx4MultMtx4InPlace(&sp98, &spdc);
		mtx4LoadTranslation(&sp8c, &sp98);
		mtx4MultMtx4InPlace(&sp98, &spdc);
		mtx4ToMtx3(&spdc, door->base.realrot);

		door->base.prop->pos.x = spdc.m[3][0];
		door->base.prop->pos.y = spdc.m[3][1];
		door->base.prop->pos.z = spdc.m[3][2];
	}

	doorGetBbox(door, &bbox);

	if (door->frac >= door->perimfrac) {
		door->base.hidden |= OBJHFLAG_DOORPERIMDISABLED;
		return;
	}

	geo = door->base.geoblock;
	door->base.hidden &= ~OBJHFLAG_DOORPERIMDISABLED;

	if ((door->doorflags & DOORFLAG_0020) == 0) {
		func0f08c424(door, &spdc);
		objCalculateGeoBlockFromBboxAndMtx(&bbox, &spdc, geo);

		if (door->doortype == DOORTYPE_VERTICAL) {
			door->doorflags |= DOORFLAG_0020;
		}
	}

	if (door->doortype == DOORTYPE_VERTICAL) {
		geo->ymin = door->startpos.y + objGetRotatedLocalYMinByMtx3(&bbox, door->base.realrot);
	} else if (door->doortype == DOORTYPE_FALLAWAY) {
		geo->ymin = door->base.prop->pos.y - 10000;
	} else if (door->doorflags & DOORFLAG_0001) {
		geo->ymin -= 1000;
	}

	if ((door->doortype == DOORTYPE_EYE && door->frac > 0.4f * door->maxfrac)
			|| (door->doortype == DOORTYPE_IRIS && door->frac > 0.4f * door->maxfrac)) {
		geo->ymax = geo->ymin + 50;
	} else if (door->doortype == DOORTYPE_FALLAWAY) {
		geo->ymax = door->base.prop->pos.y + 1000;
	} else if (door->doorflags & DOORFLAG_0001) {
		geo->ymax += 1000;
	}
}

#define NEXT1() (j + 1) % 4
#define NEXT2() (j + 2) % 4
#define NEXT3() (j + 3) % 4

static void door0f08cb20(struct doorobj *door, struct gfxvtx *src, struct gfxvtx *dst, s32 numvertices)
{
	s32 i;
	s32 j;
	s16 ref;
	struct modelrodata_bbox bbox;
	s32 stack[5];

	doorGetBbox(door, &bbox);

	if (door->doortype == DOORTYPE_VERTICAL) {
		ref = ceilf(bbox.ymax);
	} else {
		ref = floorf(bbox.xmin);
	}

	for (i = 0; i < numvertices / 4; i++) {
		struct gfxvtx *psrc = &src[i * 4];
		struct gfxvtx *pdst = &dst[i * 4];

		for (j = 0; j < 4; j++) {
			if (j == 0) {
				pdst[j] = psrc[j];
				pdst[NEXT1()] = psrc[NEXT1()];
				pdst[NEXT2()] = psrc[NEXT2()];
				pdst[NEXT3()] = psrc[NEXT3()];
				if (1);
			}

			if (door->doortype == DOORTYPE_VERTICAL) {
				if (psrc[j].y >= ref) {
					if (psrc[NEXT1()].x == psrc[j].x && psrc[NEXT1()].z == psrc[j].z && psrc[NEXT1()].y != psrc[j].y) {
						pdst[j].s = psrc[j].s + (psrc[j].y - ref) * (psrc[NEXT1()].s - psrc[j].s) / (psrc[j].y - psrc[NEXT1()].y);
						pdst[j].t = psrc[j].t + (psrc[j].y - ref) * (psrc[NEXT1()].t - psrc[j].t) / (psrc[j].y - psrc[NEXT1()].y);
					} else if (psrc[NEXT2()].x == psrc[j].x && psrc[NEXT2()].z == psrc[j].z && psrc[NEXT2()].y != psrc[j].y) {
						pdst[j].s = psrc[j].s + (psrc[j].y - ref) * (psrc[NEXT2()].s - psrc[j].s) / (psrc[j].y - psrc[NEXT2()].y);
						pdst[j].t = psrc[j].t + (psrc[j].y - ref) * (psrc[NEXT2()].t - psrc[j].t) / (psrc[j].y - psrc[NEXT2()].y);
					} else if (psrc[NEXT3()].x == psrc[j].x && psrc[NEXT3()].z == psrc[j].z && psrc[NEXT3()].y != psrc[j].y) {
						pdst[j].s = psrc[j].s + (psrc[j].y - ref) * (psrc[NEXT3()].s - psrc[j].s) / (psrc[j].y - psrc[NEXT3()].y);
						pdst[j].t = psrc[j].t + (psrc[j].y - ref) * (psrc[NEXT3()].t - psrc[j].t) / (psrc[j].y - psrc[NEXT3()].y);
					}

					pdst[j].y = ref;
				}
			} else {
				if (psrc[j].x <= ref) {
					if (psrc[NEXT1()].y == psrc[j].y && psrc[NEXT1()].z == psrc[j].z && psrc[NEXT1()].x != psrc[j].x) {
						pdst[j].s = psrc[j].s + (ref - psrc[j].x) * (psrc[NEXT1()].s - psrc[j].s) / (psrc[NEXT1()].x - psrc[j].x);
						pdst[j].t = psrc[j].t + (ref - psrc[j].x) * (psrc[NEXT1()].t - psrc[j].t) / (psrc[NEXT1()].x - psrc[j].x);
					} else if (psrc[NEXT2()].y == psrc[j].y && psrc[NEXT2()].z == psrc[j].z && psrc[NEXT2()].x != psrc[j].x) {
						pdst[j].s = psrc[j].s + (ref - psrc[j].x) * (psrc[NEXT2()].s - psrc[j].s) / (psrc[NEXT2()].x - psrc[j].x);
						pdst[j].t = psrc[j].t + (ref - psrc[j].x) * (psrc[NEXT2()].t - psrc[j].t) / (psrc[NEXT2()].x - psrc[j].x);
					} else if (psrc[NEXT3()].y == psrc[j].y && psrc[NEXT3()].z == psrc[j].z && psrc[NEXT3()].x != psrc[j].x) {
						pdst[j].s = psrc[j].s + (ref - psrc[j].x) * (psrc[NEXT3()].s - psrc[j].s) / (psrc[NEXT3()].x - psrc[j].x);
						pdst[j].t = psrc[j].t + (ref - psrc[j].x) * (psrc[NEXT3()].t - psrc[j].t) / (psrc[NEXT3()].x - psrc[j].x);
					}

					pdst[j].x = ref;
				}
			}
		}
	}
}

static void func0f08d3dc(struct doorobj *door)
{
	func0f069b4c(&door->base);

	if (door->doorflags & DOORFLAG_0004) {
		struct modelnode *node = func0f0687e4(door->base.model);
		union modelrodata *rodata = node->rodata;
		union modelrwdata *rwdata = modelGetNodeRwData(door->base.model, node);

		rwdata->dl.vertices = gfxAllocateVertices(rodata->dl.numvertices);
		door0f08cb20(door, rodata->dl.vertices, rwdata->dl.vertices, rodata->dl.numvertices);
	}
}

static void func0f08d460(struct doorobj *door)
{
	if ((door->doorflags & (DOORFLAG_0004 | DOORFLAG_0080)) == (DOORFLAG_0004 | DOORFLAG_0080)) {
		struct modelnode *node = func0f0687e4(door->base.model);
		union modelrodata *rodata = node->rodata;
		union modelrwdata *rwdata = modelGetNodeRwData(door->base.model, node);

		if (rwdata->dl.vertices != door->unka4) {
			door0f08cb20(door, rodata->dl.vertices, door->unka4, rodata->dl.numvertices);
		}

		rwdata->dl.vertices = door->unka4;
	}
}

void doorActivatePortal(struct doorobj *door)
{
	if (door->portalnum >= 0) {
		portalSetOpen(door->portalnum, true);
	}
}

void doorDeactivatePortal(struct doorobj *door)
{
	if (door->portalnum >= 0) {
		portalSetOpen(door->portalnum, false);
	}
}

struct prop *doorInit(struct doorobj *door, struct coord *pos, Mtxf *mtx, s16 *rooms, struct coord *coord, struct coord *centre)
{
	struct prop *prop;
	union modelrodata *rodata;
	Mtxf sp38;
	s16 sp28[8];

	door->base.flags |= OBJFLAG_00000100;
	prop = objInitWithAutoModel(&door->base);

	if (prop != NULL) {
		switch (door->doortype) {
		case DOORTYPE_SLIDING:
		case DOORTYPE_FLEXI1:
		case DOORTYPE_FLEXI2:
		case DOORTYPE_FLEXI3:
		case DOORTYPE_VERTICAL:
		case DOORTYPE_FALLAWAY:
		case DOORTYPE_LASER:
			door->doorflags |= DOORFLAG_0080;
			break;
		}

		mtx4Copy(mtx, &sp38);
		mtx00015f04(g_ModelStates[door->base.modelnum].scale * (1.0f / 4096.0f), &sp38);
		mtx4ToMtx3(&sp38, door->base.realrot);

		door->frac = (door->base.flags & OBJFLAG_DOOR_KEEPOPEN) ? door->maxfrac : 0;
		door->fracspeed = 0;
		door->mode = DOORMODE_IDLE;
		door->glasshits = 0;
		door->portalnum = -1;
		door->startpos = *centre;

		if (door->doorflags & DOORFLAG_0080) {
			door->unk98 = *coord;

			if (door->doorflags & DOORFLAG_0004) {
				struct modelnode *node = func0f0687e4(door->base.model);
				rodata = node->rodata;
				door->unka4 = mempAlloc(ALIGN16(rodata->dl.numvertices * sizeof(struct gfxvtx)), MEMPOOL_STAGE);
			} else {
				door->unka4 = NULL;
			}
		} else {
			mtx4ToMtx3(&sp38, door->mtx98);
		}

		func0f065e74(pos, rooms, centre, sp28);

		prop->type = PROPTYPE_DOOR;
		prop->door = door;
		prop->pos = *centre;

		propDeregisterRooms(prop);
		roomsCopy(sp28, prop->rooms);
		doorUpdateTiles(door);
		func0f069c70(&door->base, false, true);
		func0f08d3dc(door);

		door->base.shadecol[0] = door->base.nextcol[0];
		door->base.shadecol[1] = door->base.nextcol[1];
		door->base.shadecol[2] = door->base.nextcol[2];
		door->base.shadecol[3] = door->base.nextcol[3];
	}

	if (door);
	if (door);

	return prop;
}

static void doorPlayOpeningSound(s32 soundtype, struct prop *prop)
{
	s32 sound1 = 0;
	s32 sound2 = 0;
	s32 sound3 = 0;

	func0f0926bc(prop, 12, 0xffff);

	if (g_Vars.in_cutscene
			&& (prop->type & (PROPTYPE_OBJ | PROPTYPE_DOOR))
			&& (prop->obj->flags3 & OBJFLAG3_AUTOCUTSCENESOUNDS) == 0) {
		return;
	}

	switch (soundtype) {
	case 28: sound1 = SFX_DOOR_8007; break;
	case 1:  sound1 = SFX_DOOR_801A; sound2 = SFX_DOOR_801B; break;
	case 29: sound1 = SFX_DOOR_8015; sound2 = SFX_DOOR_801D; break;
	case 2:  sound1 = SFX_DOOR_801A; sound2 = SFX_DOOR_801C; break;
	case 3:  sound1 = SFX_DOOR_8014; sound2 = SFX_DOOR_8016; break;
	case 4:  sound1 = SFX_DOOR_801E; sound2 = SFX_DOOR_8020; break;
	case 5:  sound1 = SFX_DOOR_8001; break;
	case 6:  sound1 = SFX_DOOR_8004; break;
	case 7:  sound1 = SFX_DOOR_8005; break;
	case 8:  sound1 = SFX_DOOR_800A; sound2 = SFX_DOOR_8008; break;
	case 9:  sound1 = SFX_DOOR_8004; sound2 = SFX_DOOR_800B; break;
	case 10: sound1 = SFX_DOOR_800C; break;
	case 11: sound1 = SFX_DOOR_800E; break;
	case 12: sound1 = SFX_DOOR_8010; break;
	case 13: sound1 = SFX_DOOR_8012; break;
	case 30: sound1 = SFX_DOOR_816B; sound2 = SFX_DOOR_81AA; break;
	case 14: sound1 = SFX_DOOR_8017; sound2 = SFX_DOOR_8019; break;
	case 15: sound1 = SFX_DOOR_8022; break;
	case 25: sound1 = SFX_DOOR_81B8; break;
	case 16: sound1 = SFX_DOOR_8026; break;
	case 17: sound1 = SFX_DOOR_801E; break;
	case 18:
		 sound1 = SFX_DOOR_81B0;
		 sound2 = SFX_DOOR_8014;
		 sound3 = SFX_DOOR_8016;
		 break;
	case 19: sound1 = SFX_DOOR_81AE; sound2 = SFX_DOOR_81B3; break;
	case 26: sound1 = SFX_DOOR_042C; sound2 = SFX_DOOR_042B; break;
	case 20: sound1 = SFX_DOOR_81B1; sound2 = SFX_DOOR_81B6; break;
	case 21: sound1 = SFX_DOOR_81A8; sound2 = SFX_DOOR_81AA; break;
	case 32: sound1 = SFX_DOOR_81AB; sound2 = SFX_DOOR_81AD; break;
	case 31: sound1 = SFX_DOOR_81AB; sound2 = SFX_DOOR_81B4; break;
	case 22: sound1 = SFX_DOOR_81AE; sound2 = SFX_DOOR_81B5; break;
	case 23: sound1 = SFX_DOOR_80AC; sound2 = SFX_DOOR_80AE; break;
	case 24: sound1 = SFX_DOOR_816B; sound2 = SFX_DOOR_816C; break;
	case 27: sound1 = SFX_DOOR_8014; sound2 = SFX_DOOR_042B; break;
	}

	if (sound1) {
		propsnd0f0939f8(NULL, prop, sound1, -1,
				-1, 1024, 0, 12, 0, -1, 0, -1, -1, -1, -1);
	}

	if (sound2) {
		propsnd0f0939f8(NULL, prop, sound2, -1,
				-1, 0, 0, 12, 0, -1, 0, -1, -1, -1, -1);
	}

	if (sound3) {
		propsnd0f0939f8(NULL, prop, sound3, -1,
				-1, 0, 0, 12, 0, -1, 0, -1, -1, -1, -1);
	}
}

/**
 * This is identical to the function above but with less cases.
 */
static void doorPlayClosingSound(s32 soundtype, struct prop *prop)
{
	s32 sound1 = 0;
	s32 sound2 = 0;
	s32 sound3 = 0;

	func0f0926bc(prop, 12, 0xffff);

	if (g_Vars.in_cutscene
			&& (prop->type & (PROPTYPE_OBJ | PROPTYPE_DOOR))
			&& (prop->obj->flags3 & OBJFLAG3_AUTOCUTSCENESOUNDS) == 0) {
		return;
	}

	switch (soundtype) {
	case 28: sound1 = SFX_DOOR_8007; break;
	case 1:  sound1 = SFX_DOOR_801A; sound2 = SFX_DOOR_801B; break;
	case 29: sound1 = SFX_DOOR_8015; sound2 = SFX_DOOR_801D; break;
	case 2:  sound1 = SFX_DOOR_801A; sound2 = SFX_DOOR_801C; break;
	case 3:  sound1 = SFX_DOOR_8014; sound2 = SFX_DOOR_8016; break;
	case 4:  sound1 = SFX_DOOR_801E; sound2 = SFX_DOOR_8020; break;
	case 5:  sound1 = SFX_DOOR_8001; break;
	case 8:  sound1 = SFX_DOOR_800A; sound2 = SFX_DOOR_8008; break;
	case 9:  sound1 = SFX_DOOR_8004; sound2 = SFX_DOOR_800B; break;
	case 10: sound1 = SFX_DOOR_800C; break;
	case 30: sound1 = SFX_DOOR_816B; sound2 = SFX_DOOR_81AA; break;
	case 14: sound1 = SFX_DOOR_8017; sound2 = SFX_DOOR_8019; break;
	case 15: sound1 = SFX_DOOR_8022; break;
	case 25: sound1 = SFX_DOOR_81B8; break;
	case 16: sound1 = SFX_DOOR_8026; break;
	case 17: sound1 = SFX_DOOR_801E; break;
	case 18:
		 sound1 = SFX_DOOR_81B0;
		 sound2 = SFX_DOOR_8014;
		 sound3 = SFX_DOOR_8016;
		 break;
	case 23: sound1 = SFX_DOOR_80AC; sound2 = SFX_DOOR_80AE; break;
	case 24: sound1 = SFX_DOOR_816B; sound2 = SFX_DOOR_816C; break;
	}

	if (sound1) {
		propsnd0f0939f8(NULL, prop, sound1, -1,
				-1, 1024, 0, 12, 0, -1, 0, -1, -1, -1, -1);
	}

	if (sound2) {
		propsnd0f0939f8(NULL, prop, sound2, -1,
				-1, 0, 0, 12, 0, -1, 0, -1, -1, -1, -1);
	}

	if (sound3) {
		propsnd0f0939f8(NULL, prop, sound3, -1,
				-1, 0, 0, 12, 0, -1, 0, -1, -1, -1, -1);
	}
}

static void doorPlayOpenedSound(s32 soundtype, struct prop *prop)
{
	s32 sound = 0;

	func0f0926bc(prop, 12, 0xffff);

	if (g_Vars.in_cutscene
			&& (prop->type & (PROPTYPE_OBJ | PROPTYPE_DOOR))
			&& (prop->obj->flags3 & OBJFLAG3_AUTOCUTSCENESOUNDS) == 0) {
		return;
	}

	switch (soundtype) {
	case 28: sound = SFX_DOOR_801A; break;
	case 1:  sound = SFX_DOOR_801A; break;
	case 29: sound = SFX_DOOR_8015; break;
	case 2:  sound = SFX_DOOR_801A; break;
	case 3:  sound = SFX_DOOR_8015; break;
	case 4:  sound = SFX_DOOR_801F; break;
	case 5:  sound = SFX_DOOR_8002; break;
	case 8:  sound = SFX_DOOR_801A; break;
	case 9:  sound = SFX_DOOR_8003; break;
	case 10: sound = SFX_DOOR_800D; break;
	case 30: sound = SFX_DOOR_816D; break;
	case 14: sound = SFX_DOOR_816D; break;
	case 15: sound = SFX_DOOR_8021; break;
	case 25: sound = SFX_DOOR_81B7; break;
	case 16: sound = SFX_DOOR_8027; break;
	case 17: sound = SFX_DOOR_801F; break;
	case 18: sound = SFX_DOOR_8015; break;
	case 26: sound = SFX_DOOR_042C; break;
	case 19: sound = SFX_DOOR_81AF; break;
	case 20: sound = SFX_DOOR_81B2; break;
	case 21: sound = SFX_DOOR_81A8; break;
	case 32: sound = SFX_DOOR_81AB; break;
	case 31: sound = SFX_DOOR_81AB; break;
	case 22: sound = SFX_DOOR_81AF; break;
	case 23: sound = SFX_DOOR_80AD; break;
	case 24: sound = SFX_DOOR_816D; break;
	case 27: sound = SFX_DOOR_8015; break;
	}

	if (sound) {
		propsnd0f0939f8(NULL, prop, sound, -1,
				-1, 1024, 0, 12, 0, -1, 0, -1, -1, -1, -1);
	}
}

static void doorPlayClosedSound(s32 soundtype, struct prop *prop)
{
	s32 sound = 0;

	func0f0926bc(prop, 12, 0xffff);

	if (g_Vars.in_cutscene
			&& (prop->type & (PROPTYPE_OBJ | PROPTYPE_DOOR))
			&& (prop->obj->flags3 & OBJFLAG3_AUTOCUTSCENESOUNDS) == 0) {
		return;
	}

	switch (soundtype) {
	case 28: sound = SFX_DOOR_801A; break;
	case 1:  sound = SFX_DOOR_801A; break;
	case 29: sound = SFX_DOOR_8015; break;
	case 2:  sound = SFX_DOOR_801A; break;
	case 3:  sound = SFX_DOOR_8015; break;
	case 4:  sound = SFX_DOOR_801F; break;
	case 5:  sound = SFX_DOOR_8002; break;
	case 6:  sound = SFX_DOOR_8003; break;
	case 7:  sound = SFX_DOOR_8006; break;
	case 8:  sound = SFX_DOOR_801A; break;
	case 9:  sound = SFX_DOOR_8003; break;
	case 10: sound = SFX_DOOR_800D; break;
	case 11: sound = SFX_DOOR_800F; break;
	case 12: sound = SFX_DOOR_8011; break;
	case 13: sound = SFX_DOOR_8013; break;
	case 30: sound = SFX_DOOR_816D; break;
	case 14: sound = SFX_DOOR_8018; break;
	case 15: sound = SFX_DOOR_8021; break;
	case 25: sound = SFX_DOOR_81B7; break;
	case 16: sound = SFX_DOOR_8027; break;
	case 17: sound = SFX_DOOR_801F; break;
	case 18: sound = SFX_DOOR_8015; break;
	case 23: sound = SFX_DOOR_80AD; break;
	case 24: sound = SFX_DOOR_816D; break;
	}

	if (sound) {
		propsnd0f0939f8(NULL, prop, sound, -1,
				-1, 1024, 0, 12, 0, -1, 0, -1, -1, -1, -1);
	}
}

/**
 * Play the door open sound, activate the door's portal,
 * and configure the laser fade properties if it's a laser.
 */
static void doorStartOpen(struct doorobj *door)
{
	door->base.flags &= ~OBJFLAG_DOOR_KEEPOPEN;
	door->base.hidden |= OBJHFLAG_00000200;

	doorPlayOpeningSound(door->soundtype, door->base.prop);
	doorActivatePortal(door);

	if (door->doortype == DOORTYPE_FALLAWAY) {
		struct geocyl *cyl = door->base.geocyl;
		door->base.flags |= OBJFLAG_CANNOT_ACTIVATE;
		door->perimfrac = 0;

		if (cyl && (door->base.flags & OBJFLAG_00000100)) {
			cyl->header.numvertices = 0;
			door->base.flags &= ~OBJFLAG_00000100;
		}
	}

	door->fadetime60 = door->doortype == DOORTYPE_LASER ? TICKS(60) : 0;

	if (door->doortype == DOORTYPE_LASER) {
		door->laserfade = 255;
	}
}

/**
 * Play the door close sound and configure the
 * laser fade properties if it's a laser.
 */
static void doorStartClose(struct doorobj *door)
{
	door->base.flags &= ~OBJFLAG_DOOR_KEEPOPEN;

	doorPlayClosingSound(door->soundtype, door->base.prop);

	door->fadetime60 = door->doortype == DOORTYPE_LASER ? TICKS(60) : 0;

	if (door->doortype == DOORTYPE_LASER) {
		door->laserfade = 0;
	}
}

static void doorFinishOpen(struct doorobj *door)
{
	doorPlayOpenedSound(door->soundtype, door->base.prop);

	if (door->doortype == DOORTYPE_FALLAWAY) {
		func0f0685e4(door->base.prop);

		if (door->base.hidden & OBJHFLAG_PROJECTILE) {
			door->base.projectile->flags |= PROJECTILEFLAG_AIRBORNE;
			mtx4LoadIdentity((Mtxf *)&door->base.projectile->mtx);
		}
	}

	if (door->doortype == DOORTYPE_LASER) {
		door->laserfade = 0;
	}
}

extern s32 osCicId;

static void doorFinishClose(struct doorobj *door)
{
	bool pass = true;
	struct doorobj *loopdoor;

	doorPlayClosedSound(door->soundtype, door->base.prop);

	loopdoor = door;

	while (loopdoor) {
		if (loopdoor->frac > 0 && loopdoor->portalnum == door->portalnum) {
			pass = false;
		}

		loopdoor = loopdoor->sibling;

		if (loopdoor == door) {
			break;
		}
	}

	if (pass) {
		doorDeactivatePortal(door);
	}

	if (door->doortype == DOORTYPE_LASER && door->fadetime60 == 0) {
		door->laserfade = 255;
	}
}

/**
 * Apply the given mode to an individual door (not its siblings).
 *
 * Handles playing door open/close sounds and activating the portal if opening.
 */
static void doorSetMode(struct doorobj *door, s32 newmode)
{
	if (newmode == DOORMODE_OPENING) {
		if (door->mode == DOORMODE_IDLE || door->mode == DOORMODE_WAITING) {
			if (!door->base.prop->active && (door->base.prop->flags & PROPFLAG_ENABLED)) {
				propUnpause(door->base.prop);
			}

			doorStartOpen(door);
		}

		door->mode = newmode;
	} else if (newmode == DOORMODE_CLOSING) {
		if (door->mode == DOORMODE_IDLE && door->frac > 0) {
			doorStartClose(door);
		}

		if ((door->mode != DOORMODE_IDLE && door->mode != DOORMODE_WAITING) || door->frac > 0) {
			door->mode = newmode;
		} else if (door->mode == DOORMODE_WAITING) {
			door->mode = DOORMODE_IDLE;
		}
	} else {
		door->mode = newmode;
	}
}

/**
 * Request that the door and its siblings be applied the given mode
 * (opening or closing).
 *
 * When opening an airlock-style door (eg. GE Dam gate), the requested mode is
 * modified so that the sibling begins closing instead, and the main door waits
 * for the sibling before it opens.
 */
void doorsRequestMode(struct doorobj *door, s32 newmode)
{
	struct doorobj *sibling;

	s32 siblingmode = newmode;

	if ((door->base.flags2 & OBJFLAG2_AIRLOCKDOOR) && newmode == DOORMODE_OPENING) {
		siblingmode = DOORMODE_CLOSING;

		if (door->mode == DOORMODE_IDLE) {
			newmode = DOORMODE_WAITING;
		}
	}

	doorSetMode(door, newmode);

	sibling = door->sibling;

	while (sibling && sibling != door) {
		doorSetMode(sibling, siblingmode);
		sibling = sibling->sibling;
	}
}

static s32 doorIsClosed(struct doorobj *door)
{
	return (door->mode == DOORMODE_IDLE || door->mode == DOORMODE_WAITING) && door->frac <= 0;
}

static s32 doorIsOpen(struct doorobj *door)
{
	return (door->mode == DOORMODE_IDLE || door->mode == DOORMODE_WAITING) && door->frac >= door->maxfrac;
}

s32 func0f08e5a8(s16 *rooms2, struct screenbox *box)
{
	bool result = false;
	s16 *rooms = rooms2;
	s32 roomnum = *rooms;

	while (roomnum != -1) {
		struct var800a4640_00 *thing = func0f158140(roomnum);

		if (thing != var8007fc24) {
			if (result) {
				if (box->xmin > thing->box.xmin) {
					box->xmin = thing->box.xmin;
				}

				if (box->ymin > thing->box.ymin) {
					box->ymin = thing->box.ymin;
				}

				if (box->xmax < thing->box.xmax) {
					box->xmax = thing->box.xmax;
				}

				if (box->ymax < thing->box.ymax) {
					box->ymax = thing->box.ymax;
				}
			} else {
				box->xmin = thing->box.xmin;
				box->ymin = thing->box.ymin;
				box->xmax = thing->box.xmax;
				box->ymax = thing->box.ymax;
			}

			result = true;
		}

		rooms++;
		roomnum = *rooms;
	}

	return result;
}

f32 func0f08e6bc(struct prop *prop, f32 arg1)
{
	f32 result = 1;
	struct coord *coord = g_Env800a65e8;

	if (coord != NULL && coord->z < prop->z) {
		f32 scalez = g_Vars.currentplayer->c_lodscalez;
		f32 value = ((prop->z - coord->z) * 100.0f / arg1 + coord->z) * scalez;

		if (value >= coord->y) {
			result = 0;
		} else if (value > coord->x) {
			result = (coord->y - value) / (coord->y - coord->x);
		}
	}

	return result;
}

static bool func0f08e794(struct coord *coord, f32 arg1)
{
	bool result = true;
	struct coord *ptr = g_Env800a65e8;
	struct coord tmp;
	f32 sp20;

	if (ptr != NULL) {
		struct coord *campos = &g_Vars.currentplayer->cam_pos;
		Mtxf *mtx = g_Vars.currentplayer->worldtoscreenmtx;

		tmp.x = coord->x - campos->x;
		tmp.y = coord->y - campos->y;
		tmp.z = coord->z - campos->z;

		sp20 = tmp.f[0] * mtx->m[0][0] + tmp.f[1] * mtx->m[0][1] + tmp.f[2] * mtx->m[0][2];

		if (sp20 > ptr->z) {
			f32 scalez = g_Vars.currentplayer->c_lodscalez;
			sp20 = ((sp20 - ptr->z) * 100 / arg1 + ptr->z) * scalez;

			if (sp20 >= ptr->y) {
				result = false;
			}
		}
	}

	return result;
}

bool func0f08e8ac(struct prop *prop, struct coord *pos, f32 arg2, bool arg3)
{
	s16 *rooms;
	s32 roomnum;
	bool result = false;
	u32 stack;

	rooms = prop->rooms;
	roomnum = *rooms;

	while (roomnum != -1) {
		if (g_Rooms[roomnum].flags & ROOMFLAG_ONSCREEN) {
			if (env0f1666f8(pos, arg2) && (!arg3 || func0f08e794(pos, arg2))) {
				result = camIsPosInFovAndVisibleRoom(prop->rooms, pos, arg2);

				if (result) {
					struct coord *campos = &g_Vars.currentplayer->cam_pos;
					f32 xdiff = pos->x - campos->x;
					f32 ydiff = pos->y - campos->y;
					f32 zdiff = pos->z - campos->z;

					if (xdiff * xdiff + ydiff * ydiff + zdiff * zdiff > 32000 * 32000) {
						result = false;
					}
				}
			}

			break;
		}

		rooms++;
		roomnum = *rooms;
		result = false;
	}

	return result;
}

bool posIsInDrawDistance(struct coord *pos)
{
	struct coord *campos = &g_Vars.currentplayer->cam_pos;
	f32 x = pos->x - campos->x;
	f32 y = pos->y - campos->y;
	f32 z = pos->z - campos->z;
	f32 aggregate = x * x + y * y + z * z;
	bool result = true;

	if (aggregate > 1024000000) {
		result = false;
	}

	return result;
}

static void doorCreateSparks(struct doorobj *door)
{
	struct pad *pad;
	struct coord sp88;
	struct coord sp7c;
	struct coord sp70;
	s32 i;

	pad = &g_Pads[door->base.pad];

	sp88.x = sp7c.f[0] = pad->pos.f[0] + pad->up.f[0] * (pad->bbox.ymin + (1 - door->frac) * (pad->bbox.ymax - pad->bbox.ymin));
	sp88.y = sp7c.f[1] = pad->pos.f[1] + pad->up.f[1] * (pad->bbox.ymin + (1 - door->frac) * (pad->bbox.ymax - pad->bbox.ymin));
	sp88.z = sp7c.f[2] = pad->pos.f[2] + pad->up.f[2] * (pad->bbox.ymin + (1 - door->frac) * (pad->bbox.ymax - pad->bbox.ymin));

	sp88.x += pad->look.f[0] * pad->bbox.zmax;
	sp88.y += pad->look.f[1] * pad->bbox.zmax;
	sp88.z += pad->look.f[2] * pad->bbox.zmax;

	sp7c.x += pad->look.f[0] * pad->bbox.zmin;
	sp7c.y += pad->look.f[1] * pad->bbox.zmin;
	sp7c.z += pad->look.f[2] * pad->bbox.zmin;

	sp70.x = -pad->up.x;
	sp70.y = -pad->up.y;
	sp70.z = -pad->up.z;

	sparksCreate(door->base.prop->rooms[0], door->base.prop, &sp88, &sp70, &pad->up, SPARKTYPE_ENVIRONMENTAL1);

	sparksCreate(door->base.prop->rooms[0], door->base.prop, &sp7c, &sp70, &pad->up, SPARKTYPE_ENVIRONMENTAL1);

	if (random() % 2) {
		sparksCreate(door->base.prop->rooms[0], door->base.prop, &sp88, &sp70, &pad->up, SPARKTYPE_ENVIRONMENTAL4);
	} else {
		sparksCreate(door->base.prop->rooms[0], door->base.prop, &sp88, &sp70, &pad->up, SPARKTYPE_ENVIRONMENTAL5);
	}

	propsnd0f0939f8(NULL, door->base.prop, propsndGetRandomSparkSound(), -1,
			-1, 0, 0, 0, &sp88, -1, door->base.prop->rooms, -1, -1, -1, -1);

	propsnd0f0939f8(NULL, door->base.prop, propsndGetRandomSparkSound(), -1,
			-1, 0, 0, 0, &sp7c, -1, door->base.prop->rooms, -1, -1, -1, -1);

	for (i = 0; door->base.prop->rooms[i] != -1; i++) {
		roomAdjustLighting(door->base.prop->rooms[i], 128, 200);
	}
}

/**
 * Calculate/tick a door's frac (the amount it's open) without any consideration
 * for props which might be blocking the door. The new frac is written to the
 * door's frac property.
 *
 * Return true if collision checks should be considered.
 *
 * Also handles sticky doors such as the ones in Skedar Ruins.
 */
static bool doorCalcIntendedFrac(struct doorobj *door)
{
	bool checkcollision = false;

	if (door->doortype == DOORTYPE_LASER && door->fadetime60 != 0) {
		door->fadetime60 -= g_Vars.lvupdate60;

		if (door->fadetime60 < 0) {
			door->fadetime60 = 0;
		}

		if (door->mode == DOORMODE_OPENING) {
			door->laserfade = (u32)((door->fadetime60 * 255.0f) / TICKS(60.0f));
			return false;
		}

		door->laserfade = (u32)(((TICKS(60.0f) - door->fadetime60) * 255.0f) / TICKS(60.0f));
	}

	if (door->mode == DOORMODE_OPENING || door->mode == DOORMODE_CLOSING) {
		f32 end = door->mode == DOORMODE_OPENING ? door->maxfrac : 0;

		// Skedar Ruins random door stuckage
		if (door->base.flags3 & OBJFLAG3_DOOR_STICKY) {
			s32 value = (random() % 64) + 30;

			if ((g_Vars.lvframenum % value) == 0) {
				bool dothething = false;
				struct doorobj *loopdoor;

				door->fracspeed = 0.0f;
				doorCreateSparks(door);

				if (random() % 2) {
					dothething = true;
					func0f0926bc(door->base.prop, 12, 0xffff);
					door->mode = DOORMODE_IDLE;
					door->lastopen60 = g_Vars.lvframe60;
				}

				loopdoor = door;

				while (loopdoor) {
					if (random() % 2 && loopdoor->mode != DOORMODE_IDLE) {
						loopdoor->fracspeed = 0.0f;
						doorCreateSparks(loopdoor);

						if (dothething) {
							func0f0926bc(loopdoor->base.prop, 12, 0xffff);
							loopdoor->mode = DOORMODE_IDLE;
							loopdoor->lastopen60 = g_Vars.lvframe60;
						}
					}

					loopdoor = loopdoor->sibling;

					if (loopdoor == door) {
						break;
					}
				}

				doorPlayClosedSound(door->soundtype, door->base.prop);
			}
		}

		applySpeed(&door->frac, end, &door->fracspeed, door->accel, door->decel, door->maxspeed);

		if (door->frac >= door->maxfrac) {
			door->frac = door->maxfrac;
		} else if (door->frac <= 0.0f) {
			door->frac = 0.0f;
		}

		checkcollision = true;
	}

	return checkcollision;
}

/**
 * Calculate the frac of a door and its siblings, taking into consideration
 * objects which may be blocking the door.
 *
 * For each sibling, the original frac is backed up into the sibling's
 * lastcalc60 field. The desired frac is then calculated and set in the
 * sibling's frac property. Then collision checks are done, and the original
 * frac is restored if any sibling is blocked.
 *
 * Chrs who are blocking a lift door may be warped out of the way.
 */
static void doorsCalcFrac(struct doorobj *door)
{
	bool checkcollision = false;
	s32 cdresult = CDRESULT_NOCOLLISION;
	struct doorobj *loopdoor;
	struct doorobj *loopdoor2;
	f32 frac;
	s32 numsameportal;

	// For each sibling door, save their previous frac
	// then calculate the new desired frac
	loopdoor = door;

	while (loopdoor) {
		*(f32 *)&loopdoor->lastcalc60 = loopdoor->frac;

		if (doorCalcIntendedFrac(loopdoor)) {
			checkcollision = true;
		}

		loopdoor = loopdoor->sibling;

		if (loopdoor == door) {
			break;
		}
	}

	// Do collision checks
	if (checkcollision) {
		loopdoor = door;

		while (loopdoor) {
			struct prop *loopprop;

			doorUpdateTiles(loopdoor);
			setup0f0923d4(&loopdoor->base);

			loopprop = loopdoor->base.prop;

			if ((door->doorflags & DOORFLAG_UNBLOCKABLEOPEN) == 0 || loopdoor->mode == DOORMODE_CLOSING) {
				propSetPerimEnabled(loopprop, false);

				cdresult = cdTestBlockOverlapsAnyProp(loopdoor->base.geoblock, loopprop->rooms,
						CDTYPE_OBJS | CDTYPE_PLAYERS | CDTYPE_CHRS | CDTYPE_PATHBLOCKER | CDTYPE_OBJSNOTSAFEORHELI);

				propSetPerimEnabled(loopprop, true);

				if (cdresult == CDRESULT_COLLISION) {
					struct prop *blockerprop = g_CdObstacleProp;

					if (blockerprop && blockerprop->type == PROPTYPE_CHR) {
						struct chrdata *chr = blockerprop->chr;

						chr->hidden |= CHRHFLAG_BLOCKINGDOOR;

						// Consider warping the chr past the lift door
						if (!g_Vars.normmplayerisrunning && (chr->hidden & CHRHFLAG_00400000)) {
							bool isliftdoor = false;
							loopdoor2 = loopdoor;

							while (loopdoor2) {
								if (loopdoor2->base.hidden & OBJHFLAG_LIFTDOOR) {
									isliftdoor = true;
									break;
								}

								loopdoor2 = loopdoor2->sibling;

								if (loopdoor2 == loopdoor) {
									break;
								}
							}

							if (isliftdoor) {
								if (chr->actiontype == ACT_STAND
										|| (chr->actiontype == ACT_ATTACK && (chr->act_attack.flags & ATTACKFLAG_DONTTURN))
										|| (chr->actiontype == ACT_GOPOS && chrGoPosIsWaiting(chr))) {
									struct prop *target = chrGetTargetProp(chr);

									if (chrGoToRoomPos(chr, &target->pos, target->rooms, 0)) {
										chr->goposforce = TICKS(600);
									}
								} else if (chr->actiontype == ACT_GOPOS) {
									if (chr->goposforce >= 0 || chr->lastmoveok60 < g_Vars.lvframe60 - TICKS(60)) {
										chr->goposforce = TICKS(600);
									}
								}
							}
						}
					}

					break;
				}
			}

			loopdoor = loopdoor->sibling;

			if (loopdoor == door) {
				break;
			}
		}
	}

	// Finalise the frac
	loopdoor = door;

	while (loopdoor) {
		if (checkcollision) {
			if (cdresult != CDRESULT_COLLISION) {
				// No collision - handle door becoming fully open or closed
				if (loopdoor->mode == DOORMODE_OPENING) {
					if (loopdoor->frac >= loopdoor->maxfrac) {
						loopdoor->mode = DOORMODE_IDLE;
						loopdoor->fracspeed = 0;
						loopdoor->lastopen60 = g_Vars.lvframe60;

						doorFinishOpen(loopdoor);
					}
				} else {
					if (loopdoor->mode == DOORMODE_CLOSING && loopdoor->frac <= 0) {
						loopdoor->mode = DOORMODE_IDLE;
						loopdoor->fracspeed = 0;
						loopdoor->lastopen60 = 0;

						doorFinishClose(loopdoor);
					}
				}

				func0f069c70(&loopdoor->base, false, false);
				func0f08d3dc(loopdoor);
			} else {
				// Door is blocked - restore the original frac
				loopdoor->fracspeed = 0;
				loopdoor->frac = *(f32 *)&loopdoor->lastcalc60;

				doorUpdateTiles(loopdoor);
				setup0f0923d4(&loopdoor->base);
				func0f08d460(loopdoor);
			}
		} else {
			func0f08d460(loopdoor);
		}

		loopdoor->lastcalc60 = g_Vars.lvframe60;
		loopdoor = loopdoor->sibling;

		if (loopdoor == door) {
			break;
		}
	}

	// Update portal visibility
	frac = 0;
	numsameportal = 0;

	if (checkcollision) {
		loopdoor = door;

		while (loopdoor) {
			if (loopdoor->portalnum == door->portalnum) {
				numsameportal++;

				if (loopdoor->doortype == DOORTYPE_SWINGING || loopdoor->doortype == DOORTYPE_SWINGING) {
					frac += loopdoor->frac / loopdoor->maxfrac;
				} else {
					frac += loopdoor->frac / loopdoor->maxfrac;
				}
			}

			loopdoor = loopdoor->sibling;

			if (loopdoor == door) {
				break;
			}
		}

		portalSetXluFrac(door->portalnum, frac / numsameportal);
		portalSetXluFrac2(door->portalnum, frac / numsameportal);
	}
}

static f32 func0f08f538(f32 x, f32 y)
{
	f32 angle = atan2f(x, y);

	if (g_Vars.currentplayer->eyespy
			&& g_Vars.currentplayer->eyespy->active
			&& g_Vars.currentplayer->eyespy->prop
			&& g_Vars.currentplayer->eyespy->prop->chr) {
		angle -= chrGetInverseTheta(g_Vars.currentplayer->eyespy->prop->chr);
	} else {
		angle -= (360.0f - g_Vars.currentplayer->vv_theta) * M_BADTAU / 360.0f;
	}

	if (angle < 0) {
		angle += M_BADTAU;
	}

	if (angle > M_BADPI) {
		angle -= M_BADTAU;
	}

	return angle;
}

/**
 * Get some coordinates/distances related to activating doors.
 */
static void door0f08f604(struct doorobj *door, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, bool arg5)
{
	f32 value1;
	f32 value2;
	f32 value3;
	f32 value4;
	f32 x1;
	f32 y1;
	f32 x2;
	f32 y2;
	u32 stack[4];
	struct prop *playerprop;
	f32 spb0;
	f32 spac;
	f32 spa8;
	f32 spa4;
	struct coord playerpos;
	struct pad *pad;
	f32 xfrac;
	f32 zfrac;
	f32 angle;
	f32 cosine;
	f32 sine;

	if (g_Vars.currentplayer->eyespy && g_Vars.currentplayer->eyespy->active) {
		playerprop = g_Vars.currentplayer->eyespy->prop;
	} else {
		playerprop = g_Vars.currentplayer->prop;
	}

	pad = &g_Pads[door->base.pad];

	playerpos.f[0] = playerprop->pos.x;
	playerpos.f[1] = playerprop->pos.y;
	playerpos.f[2] = playerprop->pos.z;

	if (arg5) {
		spa8 = pad->bbox.xmin;
		spa4 = pad->bbox.xmax;
		spb0 = pad->up.y * pad->look.z - pad->look.y * pad->up.z;
		spac = pad->up.x * pad->look.y - pad->look.x * pad->up.y;
	} else {
		spa8 = pad->bbox.ymin;
		spa4 = pad->bbox.ymax;
		spb0 = pad->up.x;
		spac = pad->up.z;
	}

	x1 = pad->pos.x + spb0 * spa8 - playerpos.f[0];
	y1 = pad->pos.z + spac * spa8 - playerpos.f[2];
	value1 = func0f08f538(x1, y1);

	x2 = pad->pos.x + spb0 * spa4 - playerpos.f[0];
	y2 = pad->pos.z + spac * spa4 - playerpos.f[2];
	value2 = func0f08f538(x2, y2);

	if (value1 < value2) {
		*arg1 = value1;
		*arg2 = value2;
	} else {
		*arg1 = value2;
		*arg2 = value1;
	}

	if (arg3 != NULL && arg4 != NULL) {
		if (door->doortype == DOORTYPE_SWINGING) {
			angle = door->frac * 0.017450513318181f;
			value3 = value1;

			if (door->base.flags & OBJFLAG_DOOR_OPENTOFRONT) {
				angle = M_BADTAU - angle;
			}

			cosine = cosf(angle);
			sine = sinf(angle);

			x1 = pad->pos.x + (spb0 * spa8) - playerpos.f[0] + (spa4 - spa8) * (spb0 * cosine + spac * sine);
			y1 = pad->pos.z + (spac * spa8) - playerpos.f[2] + (spa4 - spa8) * (-spb0 * sine + spac * cosine);

			value4 = func0f08f538(x1, y1);
		} else if (door->doortype == DOORTYPE_SLIDING
				|| door->doortype == DOORTYPE_FLEXI1
				|| door->doortype == DOORTYPE_FLEXI2
				|| door->doortype == DOORTYPE_FLEXI3) {
			xfrac = door->unk98.x * door->frac;
			zfrac = door->unk98.z * door->frac;

			value3 = func0f08f538(x1 + xfrac, y1 + zfrac);
			value4 = func0f08f538(x2 + xfrac, y2 + zfrac);
		} else {
			value3 = value1;
			value4 = value2;
		}

		if (value3 < value4) {
			*arg3 = value3;
			*arg4 = value4;
		} else {
			*arg3 = value4;
			*arg4 = value3;
		}
	}
}

static bool func0f08f968(struct doorobj *door, bool arg1)
{
	bool checkmore = true;
	f32 sp58;
	f32 sp54;
	f32 sp50;
	f32 sp4c;
	bool maybe;
	struct prop *playerprop;
	f32 limit = 0.34901028871536f;

	if (g_InteractProp == NULL) {
		maybe = false;

		if (g_Vars.currentplayer->eyespy && g_Vars.currentplayer->eyespy->active) {
			playerprop = g_Vars.currentplayer->eyespy->prop;
		} else {
			playerprop = g_Vars.currentplayer->prop;
		}

		if ((door->doorflags & (DOORFLAG_0080 | DOORFLAG_0100)) != DOORFLAG_0080) {
			maybe = true;
		} else if (func0f06797c(&playerprop->pos, 30, door->base.pad)) {
			maybe = true;
		}

		if (maybe) {
			door0f08f604(door, &sp58, &sp54, &sp50, &sp4c, arg1);
		} else {
			door0f08f604(door, &sp58, &sp54, NULL, NULL, arg1);
		}

		if (maybe && ((sp50 >= -limit && sp50 <= limit && sp4c >= -limit && sp4c <= limit)
					|| (sp4c - sp50 < M_BADPI && sp50 < 0.0f && sp4c > 0.0f))) {
			g_InteractProp = door->base.prop;
			checkmore = false;
		} else if (sp58 >= -limit && sp58 <= limit && sp54 >= -limit && sp54 <= limit) {
			g_InteractProp = door->base.prop;
			checkmore = false;
		} else {
			struct doorobj *sibling = door->sibling;
			f32 sp38;
			f32 sp34;

			while (sibling != NULL && sibling != door && (sp58 >= 0.0f || sp54 < 0.0f)) {
				door0f08f604(sibling, &sp38, &sp34, NULL, NULL, arg1);

				if (sp58 >= 0.0f && sp38 < sp58) {
					sp58 = sp38;
				}

				if (sp54 <= 0.0f && sp54 < sp34) {
					sp54 = sp34;
				}

				sibling = sibling->sibling;
			}

			if (sp54 - sp58 < M_BADPI && sp58 < 0.0f && sp54 > 0.0f) {
				g_InteractProp = door->base.prop;
				checkmore = false;
			}
		}
	}

	return checkmore;
}

/**
 * This function is used to help find the door that should be opened when
 * interacting. The argument given is a door to be tested.
 *
 * A pointer to the best candidate is stored at g_InteractProp. This function
 * doesn't write to it directly so it must be done by one of the called
 * functions.
 *
 * This function should return true if more doors and objects should be tested,
 * or false if the prop at g_InteractProp is certain to be final.
 */
bool doorTestForInteract(struct prop *prop)
{
	bool checkmore = true;
	struct doorobj *door = prop->door;

	if ((door->base.flags & OBJFLAG_CANNOT_ACTIVATE) == 0
			&& door->maxfrac > 0
			&& (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)) {
		bool maybe = false;
		bool usingeyespy = g_Vars.currentplayer->eyespy && g_Vars.currentplayer->eyespy->active;
		struct prop *playerprop = usingeyespy ? g_Vars.currentplayer->eyespy->prop : g_Vars.currentplayer->prop;

		f32 xdiff = door->startpos.x - playerprop->pos.x;
		f32 ydiff = door->startpos.y - playerprop->pos.y;
		f32 zdiff = door->startpos.z - playerprop->pos.z;

		if (xdiff * xdiff + zdiff * zdiff < 40000 && ydiff < 200 && ydiff > -200) {
			maybe = true;
		} else if (arrayIntersects(prop->rooms, playerprop->rooms)) {
			if (func0f06797c(&playerprop->pos, 150, door->base.pad)) {
				maybe = true;
			} else if ((door->doorflags & (DOORFLAG_0080 | DOORFLAG_0100)) != DOORFLAG_0080) {
				u32 stack;
				struct modelrodata_bbox bbox;
				Mtxf matrix;

				doorGetBbox(door, &bbox);
				func0f08c424(door, &matrix);

				if (func0f0675c8(&playerprop->pos, 150, &bbox, &matrix)) {
					maybe = true;
				}
			}
		}

		if (maybe) {
			if ((door->base.flags2 & OBJFLAG2_INTERACTCHECKLOS) == 0
					|| cdTestLos06(&playerprop->pos, playerprop->rooms, &prop->pos, prop->rooms, CDTYPE_BG)) {
				checkmore = func0f08f968(door, false);

				if (checkmore && (door->base.flags2 & OBJFLAG2_80000000)) {
					checkmore = func0f08f968(door, true);
				}
			}
		}
	}

	return checkmore;
}

/**
 * Activate the doors by calling the lift or requesting the new door mode
 * (opening/closing) for the given door and its siblings.
 *
 * Assumes any lock checks have already been done and have passed.
 *
 * The allowliftclose argument determines whether the door should be closed if
 * it's a lift door and the lift is at the door. This is typically true when the
 * player has activated the door, and false when NPCs have activated the door.
 */
static void doorsActivate(struct prop *doorprop, bool allowliftclose)
{
	struct doorobj *door = doorprop->door;

	if (!doorCallLift(doorprop, allowliftclose)) {
		if (door->mode == DOORMODE_OPENING || door->mode == DOORMODE_WAITING) {
			doorsRequestMode(door, DOORMODE_CLOSING);
		} else if (door->mode == DOORMODE_CLOSING) {
			doorsRequestMode(door, DOORMODE_OPENING);
		} else if (door->mode == DOORMODE_IDLE) {
			if (door->frac > 0.5f * door->maxfrac) {
				doorsRequestMode(door, DOORMODE_CLOSING);
			} else {
				doorsRequestMode(door, DOORMODE_OPENING);
			}
		}
	}

	if (g_Vars.currentplayernum == g_Vars.coopplayernum) {
		door->base.hidden |= OBJHFLAG_ACTIVATED_BY_COOP;
	} else if (g_Vars.currentplayernum == g_Vars.bondplayernum) {
		door->base.hidden |= OBJHFLAG_ACTIVATED_BY_BOND;
	}

	door->base.flags2 &= ~OBJFLAG2_00000008;
}

static bool posIsInFrontOfDoor(struct coord *pos, struct doorobj *door)
{
	f32 x;
	f32 y;
	f32 z;
	f32 value;
	struct pad *pad;

	pad = &g_Pads[door->base.pad];

	x = pos->x - pad->pos.x;
	y = pos->y - pad->pos.y;
	z = pos->z - pad->pos.z;

	value = x * pad->normal.f[0] + y * pad->normal.f[1] + z * pad->normal.f[2];

	if (door->doorflags & DOORFLAG_FLIP) {
		value = -value;
	}

	if (value < 0) {
		return false;
	}

	if (value > 0) {
		return true;
	}

	return true;
}

void doorsChooseSwingDirection(struct prop *chrprop, struct doorobj *door)
{
	if ((door->base.flags & OBJFLAG_DOOR_TWOWAY) && door->mode == DOORMODE_IDLE && door->frac == 0) {
		bool infront = posIsInFrontOfDoor(&chrprop->pos, door);
		u32 wantflag = 0;

		if ((door->doorflags & DOORFLAG_FLIP) == 0) {
			if (!infront) {
				wantflag = OBJFLAG_DOOR_OPENTOFRONT;
			}
		} else {
			if (infront) {
				wantflag = OBJFLAG_DOOR_OPENTOFRONT;
			}
		}

		// If flags are different
		if ((s32)((door->base.flags ^ wantflag) << 2) < 0) {
			// Toggle direction on door and siblings
			struct doorobj *sibling = door;

			do {
				sibling->base.flags ^= OBJFLAG_DOOR_OPENTOFRONT;
				sibling = sibling->sibling;
			} while (sibling && sibling != door);
		}
	}
}

bool propdoorInteract(struct prop *doorprop)
{
	struct doorobj *door = doorprop->door;
	bool usingeyespy = g_Vars.currentplayer->eyespy && g_Vars.currentplayer->eyespy->active;
	struct prop *playerprop = usingeyespy ? g_Vars.currentplayer->eyespy->prop : g_Vars.currentplayer->prop;

	if (doorIsUnlocked(playerprop, doorprop)) {
		doorsChooseSwingDirection(playerprop, door);
		doorsActivate(doorprop, true);
	} else if (door->mode == DOORMODE_IDLE && door->frac < 0.5f * door->maxfrac) {
		if ((door->base.flags2 & OBJFLAG2_SKIPDOORLOCKEDMSG) == 0) {
			struct textoverride *override = invGetTextOverrideForObj(&door->base);
			u8 intraining = false;

			if (g_Vars.stagenum == STAGE_CITRAINING) {
				struct trainingdata *devdata = dtGetData();
				struct trainingdata *holodata = getHoloTrainingData();

				intraining = (devdata && devdata->intraining)
					|| (holodata && holodata->intraining)
					|| g_Vars.currentplayer->prop->rooms[0] == 0x0a;
			}

			if (override && override->pickuptext) {
				hudmsgCreateWithFlags(langGet(override->pickuptext), HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE);
			} else if (intraining) {
				hudmsgCreateWithFlags(langGet(L_DISH_080), HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE); // "Cannot exit while training is in progress."
			} else {
				hudmsgCreateWithFlags(langGet(L_PROPOBJ_044), HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE); // "This door is locked."
			}
		}

		if (g_Vars.currentplayernum == g_Vars.coopplayernum) {
			door->base.hidden |= OBJHFLAG_ACTIVATED_BY_COOP;
		} else if (g_Vars.currentplayernum == g_Vars.bondplayernum) {
			door->base.hidden |= OBJHFLAG_ACTIVATED_BY_BOND;
		}

		door->base.flags2 |= OBJFLAG2_00000008;
	}

	return TICKOP_NONE;
}

void alarmActivate(void)
{
	if (g_AlarmTimer < 1) {
		g_AlarmTimer = 1;
	}
}

void alarmStopAudio(void)
{
	if (g_AlarmAudioHandle && sndGetState(g_AlarmAudioHandle) != AL_STOPPED) {
		audioStop(g_AlarmAudioHandle);
	}
}

void alarmDeactivate(void)
{
	g_AlarmTimer = 0;
	alarmStopAudio();
}

void countdownTimerSetVisible(u32 reason, bool visible)
{
	if (visible) {
		g_CountdownTimerOff &= ~reason;
	} else {
		g_CountdownTimerOff |= reason;
	}
}

Gfx *countdownTimerRender(Gfx *gdl)
{
	s32 mins;
	s32 secs;
	s32 ms;

	f32 value60 = g_CountdownTimerValue60;
	u32 stack;
	s32 viewright = g_ViBackData->viewleft + (g_ViBackData->viewx >> 1);
	s32 y = g_ViBackData->viewtop + g_ViBackData->viewy - 18;
	s32 playercount = PLAYERCOUNT();
	char *fmt = ":\n";

	if (playercount == 2) {
		if (g_ScreenSplit != SCREENSPLIT_VERTICAL && g_Vars.currentplayernum == 0) {
			y += 10;
		} else {
			y += 2;
		}
	} else if (playercount >= 3) {
		if (g_Vars.currentplayernum <= 1) {
			y += 10;
		} else {
			y += 2;
		}
	} else {
		if (optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
			y += 8;
		}
	}

	if (value60 < 0) {
		value60 = -value60;
	}

	mins = floorf(value60 * (1.0f / 3600.0f));
	secs = (s32)floorf(value60 * (1.0f / 60.0f)) - mins * 60;
	ms = (s32)floorf(value60 * 1.6666666269302f) - mins * 6000 - secs * 100;

	gdl = text0f153628(gdl);
	gdl = bgunDrawHudInteger(gdl, (mins % 100) / 10, viewright - 18, HUDHALIGN_MIDDLE, y, HUDVALIGN_MIDDLE, 0x00ff00a0);
	gdl = bgunDrawHudInteger(gdl, mins % 10, viewright - 14, HUDHALIGN_MIDDLE, y, HUDVALIGN_MIDDLE, 0x00ff00a0);
	gdl = bgunDrawHudString(gdl, fmt, viewright - 8, HUDHALIGN_MIDDLE, y, HUDVALIGN_MIDDLE, 0x00ff00a0);
	gdl = bgunDrawHudInteger(gdl, (secs % 60) / 10, viewright - 2, HUDHALIGN_MIDDLE, y, HUDVALIGN_MIDDLE, 0x00ff00a0);
	gdl = bgunDrawHudInteger(gdl, secs % 10, viewright + 2, HUDHALIGN_MIDDLE, y, HUDVALIGN_MIDDLE, 0x00ff00a0);
	gdl = bgunDrawHudString(gdl, fmt, viewright + 8, HUDHALIGN_MIDDLE, y, HUDVALIGN_MIDDLE, 0x00ff00a0);
	gdl = bgunDrawHudInteger(gdl, (ms % 100) / 10, viewright + 14, HUDHALIGN_MIDDLE, y, HUDVALIGN_MIDDLE, 0x00ff00a0);
	gdl = bgunDrawHudInteger(gdl, ms % 10, viewright + 18, HUDHALIGN_MIDDLE, y, HUDVALIGN_MIDDLE, 0x00ff00a0);
	gdl = text0f153780(gdl);

	return gdl;
}


void alarmTick(void)
{
	if (g_AlarmTimer > 0) {
		s32 limit;
		s16 sound;

		// These sounds are alarm sounds.
		// They go for a fraction of a second and are repeated by this function.
		switch (g_Vars.stagenum) {
		case STAGE_CHICAGO:      sound = SFX_ALARM_CHICAGO; break;
		case STAGE_G5BUILDING:   sound = SFX_ALARM_2; break;
		case STAGE_AIRBASE:      sound = SFX_ALARM_AIRBASE; break;
		case STAGE_PELAGIC:      sound = SFX_ALARM_2; break;
		case STAGE_ATTACKSHIP:   sound = SFX_ALARM_ATTACKSHIP; break;
		case STAGE_INFILTRATION: sound = SFX_ALARM_INFILTRATION; break;
		default:                 sound = SFX_ALARM_DEFAULT; break;
		}

		if (!g_LvIsPaused) {
			if (g_AlarmAudioHandle) {
				// The sound is currently playing. Cycle between the left/right
				// speaker for stereo or headphone mode.
				f32 increment = g_Vars.lvupdate240 / 15.0f;

				if (increment > 10) {
					increment = 10;
				}

				g_AlarmSpeakerWeight += g_AlarmSpeakerDirection * increment;

				if (g_AlarmSpeakerWeight < 30) {
					g_AlarmSpeakerWeight = 30;
					g_AlarmSpeakerDirection *= -1;
				} else if (g_AlarmSpeakerWeight > 98) {
					g_AlarmSpeakerWeight = 98;
					g_AlarmSpeakerDirection *= -1;
				}

				sndAdjust(&g_AlarmAudioHandle, 0, 0x7fff, g_AlarmSpeakerWeight, -1, -1, 0, -1, 1);
			} else {
				// The alarm finished, or this is the first one.
				// Start the sound again.
				sndStart(var80095200, sound, &g_AlarmAudioHandle, -1, -1, -1, -1, -1);
			}
		}

		g_AlarmTimer += g_Vars.lvupdate60;

		// For G5, stop alarm after 55 seconds.
		// For all other levels, stop alarm after 30 seconds.
		limit = g_Vars.stagenum == STAGE_G5BUILDING ? 3300 : 1800;

		if (g_AlarmTimer > limit) {
			alarmDeactivate();
		}
	}

	if (g_CountdownTimerRunning) {
		g_CountdownTimerValue60 -= g_Vars.lvupdate60freal;
	}

	if (g_NumProxies) {
		chrsTriggerProxies();
	}

	g_PlayersDetonatingMines = 0;
}

void func0f091030(void)
{
	struct prop *prop = g_Vars.activeprops;

	while (prop) {
		if (prop->type == PROPTYPE_OBJ
				&& (prop->flags & (PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) == 0
				&& (prop->obj->hidden2 & OBJH2FLAG_DESTROYED)
				&& (prop->obj->hidden2 & OBJH2FLAG_80)) {
			objFreePermanently(prop->obj, true);
			return;
		}

		prop = prop->next;
	}
}

void currentPlayerDropAllItems(void)
{
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;
	s32 i;

	weaponDeleteFromChr(chr, HAND_RIGHT);
	weaponDeleteFromChr(chr, HAND_LEFT);

	for (i = WEAPON_UNARMED; i <= WEAPON_SUICIDEPILL; i++) {
		if (playermgrGetModelOfWeapon(i) >= 0 && invHasSingleWeaponExcAllGuns(i)) {
			if (!weaponHasFlag(i, WEAPONFLAG_UNDROPPABLE)
					|| (g_Vars.normmplayerisrunning
						&& g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL
						&& i == WEAPON_DATAUPLINK)) {
				if (g_Vars.coopplayernum >= 0) {
					bool canremove = true;
					struct prop *child = g_Vars.currentplayer->prop->child;

					while (child) {
						struct defaultobj *obj = child->obj;

						if (obj->type == OBJTYPE_WEAPON) {
							struct weaponobj *weapon = child->weapon;

							if (i == weapon->weaponnum && (obj->flags3 & OBJFLAG3_PLAYERUNDROPPABLE)) {
								canremove = false;
								break;
							}
						}

						child = child->next;
					}

					if (canremove) {
						invRemoveItemByNum(i);
					}

					if (!bgunIsMissionCritical(i)) {
						weaponCreateForPlayerDrop(i);
					}
				} else {
					weaponCreateForPlayerDrop(i);
				}
			}
		}
	}
}

void weaponCreateForPlayerDrop(s32 weaponnum)
{
	u32 stack;
	struct prop *prop;
	struct chrdata *chr;
	u32 stack2;

	chr = g_Vars.currentplayer->prop->chr;
	prop = weaponCreateForChr(chr, playermgrGetModelOfWeapon(weaponnum), weaponnum, OBJFLAG_WEAPON_AICANNOTUSE, NULL, NULL);

	if (prop) {
		objSetDropped(prop, DROPTYPE_DEFAULT);
		objDrop(prop, true);

		if (weaponnum == WEAPON_BRIEFCASE2) {
			scenarioHandleDroppedToken(chr, prop);
		}
	}
}

void projectileCreate(struct prop *fromprop, struct fireslotthing *arg1, struct coord *pos, struct coord *dir, u8 weaponnum, struct prop *targetprop)
{
	if (!g_LvIsPaused) {
		bool blocked = false;
		struct coord endpos;
		u32 stack;
		f32 x;
		f32 y;
		f32 z;
		f32 sqdist;
		struct prop *obstacle = NULL;
		s16 sp1c8[8];
		struct coord frompos;
		u32 stack2;
		u8 drug = false;
		u32 stack3;

		frompos = *pos;

		if (weaponnum == WEAPON_TRANQUILIZER) {
			drug = true;
		}

		if (arg1 && arg1->unk08 < g_Vars.lvframe60) {
			switch (weaponnum) {
			case WEAPON_CHOPPERGUN:
				func0f0926bc(fromprop, 7, 0xffff);
				propsnd0f0939f8(0, fromprop, SFX_810E, -1, -1, 0, 0, 7, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
				arg1->unk08 = g_Vars.lvframe60 + 4;
				break;
			case WEAPON_RCP45:
				func0f0926bc(fromprop, 1, 0xffff);
				propsnd0f0939f8(0, fromprop, SFX_805A, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
				arg1->unk08 = g_Vars.lvframe60 + 2;
				break;
			case WEAPON_WATCHLASER:
				func0f0926bc(fromprop, 1, 0xffff);
				propsnd0f0939f8(0, fromprop, SFX_8043, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
				arg1->unk08 = g_Vars.lvframe60 + 8;
				break;
			default:
				func0f0926bc(fromprop, 1, 0xffff);
				propsnd0f0939f8(0, fromprop, SFX_8045, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
				arg1->unk08 = g_Vars.lvframe60 + 2;
				break;
			}
		}

		if (targetprop) {
			x = targetprop->pos.f[0] - pos->f[0] - dir->f[0] * 15.0f;
			y = targetprop->pos.f[1] - pos->f[1] - dir->f[1] * 15.0f;
			z = targetprop->pos.f[2] - pos->f[2] - dir->f[2] * 15.0f;

			sqdist = x * x + y * y + z * z;
		} else {
			sqdist = 0x20000000;
		}

		if (weaponnum == WEAPON_ROCKETLAUNCHER) {
			struct weaponobj *rocket;
			Mtxf sp13c;
			struct coord sp130;
			struct chopperobj *chopper = chopperFromHovercar((struct chopperobj *)fromprop->obj);

			if (chopper && sqdist > 400.0f * 400.0f) {
				struct coord sp120;
				Mtxf spe0;
				Mtxf spa0;
				f32 rotx = chopper->rotx;
				f32 roty = chopper->roty;

				rocket = weaponCreateProjectileFromWeaponNum(MODEL_CHRDYROCKETMIS, WEAPON_ROCKET, NULL);

				if (rocket) {
					mtx4LoadIdentity(&sp13c);
					mtx4LoadXRotation(rotx, &spe0);
					mtx4LoadYRotation(roty, &spa0);
					mtx00015be0(&spa0, &spe0);

					sp120.x = dir->x * 0.27777776f;
					sp120.y = dir->y * 0.27777776f;
					sp120.z = dir->z * 0.27777776f;

					sp130.x = sp120.f[0] * g_Vars.lvupdate60freal;
					sp130.y = sp120.f[1] * g_Vars.lvupdate60freal;
					sp130.z = sp120.f[2] * g_Vars.lvupdate60freal;

					bgun0f09ebcc(&rocket->base, pos, fromprop->rooms, &spe0, &sp130, &sp13c, fromprop, pos);

					if (rocket->base.hidden & OBJHFLAG_PROJECTILE) {
						rocket->timer240 = -1;
						rocket->base.projectile->flags |= PROJECTILEFLAG_POWERED;
						rocket->base.projectile->unk010 = sp120.x;
						rocket->base.projectile->unk014 = sp120.y;
						rocket->base.projectile->unk018 = sp120.z;

						propsnd0f0939f8(NULL, rocket->base.prop, SFX_LAUNCH_ROCKET_8053, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
					}
				}
			}
		} else {
			struct gset gset = {0};

			gset.weaponnum = weaponnum;

			endpos.x = pos->x + dir->f[0] * 65536.0f;
			endpos.y = pos->y + dir->f[1] * 65536.0f;
			endpos.z = pos->z + dir->f[2] * 65536.0f;

			propSetPerimEnabled(fromprop, false);

			if (cdExamLos08(pos, fromprop->rooms, &endpos,
						CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_CHRS | CDTYPE_PATHBLOCKER| CDTYPE_BG,
						GEOFLAG_BLOCK_SHOOT) == CDRESULT_COLLISION) {
				blocked = true;
				endpos = g_CdObstaclePos;
				obstacle = g_CdObstacleProp;
			}

			propSetPerimEnabled(fromprop, true);

			x = endpos.x - pos->x;
			y = endpos.y - pos->y;
			z = endpos.z - pos->z;

			if (targetprop && sqdist <= x * x + y * y + z * z) {
				struct coord aimpos;

				aimpos.x = targetprop->pos.x;
				aimpos.y = targetprop->pos.y - 20.0f;
				aimpos.z = targetprop->pos.z;

				if (func0f06b39c(pos, dir, &aimpos, 30)) {
					f32 f0 = 0.16f * g_Vars.lvupdate60freal * arg1->unk0c;

					if (sqdist > 40000.0f) {
						f0 *= 200.0f / sqrtf(sqdist);
					}

					arg1->unk14 += f0;

					if (arg1->unk14 >= 1.0f) {
						blocked = false;

						endpos = targetprop->pos;

						if (random() % 2) {
							endpos.y += (random() % 10) + 2;
						} else {
							endpos.y -= (random() % 10) + 2;
						}

						bgunPlayPropHitSound(&gset, targetprop, -1);
						chrDamageByImpact(targetprop->chr, gsetGetDamage(&gset) * arg1->unk10, dir, &gset, 0, 200);
						arg1->unk14 = 0.0f;
					}
				}
			}

			if (blocked) {
				if (obstacle) {
					if (obstacle->type & (PROPTYPE_CHR | PROPTYPE_PLAYER)) {
						struct modelnode *node = NULL;
						struct model *model = NULL;
						s32 side = -1;
						s32 hitpart = HITPART_GENERAL;
						struct chrdata *chr = obstacle->chr;

						if (weaponnum != WEAPON_CHOPPERGUN) {
							bgunPlayPropHitSound(&gset, obstacle, -1);
						}

						if (chr->model) {
							chrCalculateShieldHit(chr, &endpos, dir, &node, &hitpart, &model, &side);
						}

						chrEmitSparks(chr, obstacle, hitpart, &endpos, dir, NULL);

						if (drug) {
							chr->blurdrugamount = TICKS(5000);
						}

						func0f0341dc(chr, gsetGetDamage(&gset), dir, &gset, 0, hitpart, obstacle, node, model, side, NULL);
					} else if (obstacle->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
						struct defaultobj *obj = obstacle->obj;

						if (weaponnum != WEAPON_CHOPPERGUN) {
							bgunPlayPropHitSound(&gset, obstacle, -1);
						}

						func0f065e74(pos, fromprop->rooms, &endpos, sp1c8);
						sparksCreate(sp1c8[0], obstacle, &endpos, NULL, NULL, SPARKTYPE_DEFAULT);
						objTakeGunfire(obstacle->obj, gsetGetDamage(&gset), &endpos, weaponnum, -1);

						if (obj->type == OBJTYPE_WEAPON) {
							struct weaponobj *weapon = (struct weaponobj *)obj;

							if (weapon->weaponnum == WEAPON_DRAGON && weapon->gunfunc == FUNC_SECONDARY) {
								weapon->timer240 = 0;
							}
						}
					}
				} else {
					func0f065e74(pos, fromprop->rooms, &endpos, sp1c8);

					if (weaponnum != WEAPON_CHOPPERGUN) {
						bgunPlayBgHitSound(&gset, &endpos, -1, sp1c8);
					}

					sparksCreate(sp1c8[0], NULL, &endpos, NULL, NULL, SPARKTYPE_DEFAULT);
				}
			}

			if (arg1 && arg1->unk01) {
				beamCreate(arg1->beam, weaponnum, &frompos, &endpos);
			}
		}
	}
}

void objSetModelPartVisible(struct defaultobj *obj, s32 partnum, bool visible)
{
	if (obj && obj->model && obj->model->filedata) {
		struct modelnode *node = modelGetPart(obj->model->filedata, partnum);

		if (node) {
			union modelrwdata *rwdata = modelGetNodeRwData(obj->model, node);

			if (rwdata) {
				if (visible) {
					visible = true;
				} else {
					visible = false;
				}

				rwdata->toggle.visible = visible;
			}
		}
	}
}
