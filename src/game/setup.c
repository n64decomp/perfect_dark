#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/game_00b820.h"
#include "game/setup.h"
#include "game/objectives.h"
#include "game/playerreset.h"
#include "game/botmgr.h"
#include "game/chr.h"
#include "game/chrmgr.h"
#include "game/body.h"
#include "game/prop.h"
#include "game/setuputils.h"
#include "game/atan2f.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/bg.h"
#include "game/stagetable.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/mplayer/scenarios.h"
#include "game/challenge.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "lib/path.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/ailist.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "data.h"
#include "types.h"

static void setupReset0f00cc8c(void);
static void setupResetProxyMines(void);

s32 var8009cc30;

struct tvscreen var80061a80 = {
	g_TvCmdlist00, // cmdlist
	0,           // offset
	0xffff,      // pause60
	0,           // tconfig
	0,           // rot
	1,           // xscale
	0,           // xscalefrac
	0,           // xscaleinc
	1,           // xscaleold
	1,           // xscalenew
	1,           // yscale
	0,           // yscalefrac
	0,           // yscaleinc
	1,           // yscaleold
	1,           // yscalenew
	0.5,         // xmid
	0,           // xmidfrac
	0,           // xmidinc
	0.5,         // xmidold
	0.5,         // xmidnew
	0.5,         // ymid
	0,           // ymidfrac
	0,           // ymidinc
	0.5,         // ymidold
	0.5,         // ymidnew
	0xff,        // red
	0xff,        // redold
	0xff,        // rednew
	0xff,        // green
	0xff,        // greenold
	0xff,        // greennew
	0xff,        // blue
	0xff,        // blueold
	0xff,        // bluenew
	0xff,        // alpha
	0xff,        // alphaold
	0xff,        // alphanew
	1,           // colfrac
	0,           // colinc
};

f32 g_DoorScale = 1;

void propsReset(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Lifts); i++) {
		g_Lifts[i] = NULL;
		g_LiftnumToIndex[i] = 0;
	}

	g_NumLifts = 0;

	g_MaxWeaponSlots = 50;
	g_MaxAmmoCrates = 20;
	g_MaxDebrisSlots = 15;
	g_MaxProjectiles = 100;
	g_MaxEmbedments = 80;

	if (g_Vars.stagenum >= STAGE_TITLE) {
		g_MaxWeaponSlots = 0;
		g_MaxAmmoCrates = 0;
		g_MaxDebrisSlots = 0;
		g_MaxProjectiles = 0;
		g_MaxEmbedments = 0;
	}

	setupReset0f00cc8c();
	setupResetProxyMines();

	g_AlarmTimer = 0;
	g_AlarmAudioHandle = NULL;
	g_AlarmSpeakerWeight = 64;

	g_CountdownTimerOff = COUNTDOWNTIMERREASON_AI;
	g_CountdownTimerRunning = false;
	g_CountdownTimerValue60 = 0;

	g_PlayersDetonatingMines = 0;
	g_TintedGlassEnabled = false;

	if (g_MaxWeaponSlots == 0) {
		g_WeaponSlots = NULL;
	} else {
		g_WeaponSlots = mempAlloc(ALIGN16(g_MaxWeaponSlots * sizeof(struct weaponobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxWeaponSlots; i++) {
			g_WeaponSlots[i].base.prop = NULL;
		}

		g_NextWeaponSlot = 0;
	}

	if (g_MaxAmmoCrates == 0) {
		g_AmmoCrates = NULL;
	} else {
		g_AmmoCrates = mempAlloc(ALIGN16(g_MaxAmmoCrates * sizeof(struct ammocrateobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxAmmoCrates; i++) {
			g_AmmoCrates[i].base.prop = NULL;
		}
	}

	if (g_MaxDebrisSlots == 0) {
		g_DebrisSlots = NULL;
	} else {
		g_DebrisSlots = mempAlloc(ALIGN16(g_MaxDebrisSlots * sizeof(struct defaultobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxDebrisSlots; i++) {
			g_DebrisSlots[i].prop = NULL;
		}
	}

	if (g_MaxProjectiles == 0) {
		g_Projectiles = NULL;
	} else {
		g_Projectiles = mempAlloc(ALIGN16(g_MaxProjectiles * sizeof(struct projectile)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxProjectiles; i++) {
			g_Projectiles[i].flags = PROJECTILEFLAG_FREE;
		}
	}

	if (g_MaxEmbedments == 0) {
		g_Embedments = NULL;
	} else {
		g_Embedments = mempAlloc(ALIGN16(g_MaxEmbedments * sizeof(struct embedment)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxEmbedments; i++) {
			g_Embedments[i].flags = EMBEDMENTFLAG_FREE;
		}
	}

	g_LiftDoors = NULL;
	g_LinkedScenery = NULL;
	g_BlockedPaths = NULL;

	g_EmbedProp = NULL;
	g_EmbedHitPart = -1;
	g_CctvWaitScale = 1;
	g_AutogunAccuracyScale = 1;
	g_AutogunDamageTxScale = 1;
	g_AutogunDamageRxScale = 1;
	g_AmmoQuantityScale = 1;

	g_MaxThrownLaptops = g_Vars.normmplayerisrunning ? 12 : PLAYERCOUNT();

	g_ThrownLaptops = mempAlloc(ALIGN16(g_MaxThrownLaptops * sizeof(struct autogunobj)), MEMPOOL_STAGE);
	g_ThrownLaptopBeams = mempAlloc(ALIGN16(g_MaxThrownLaptops * sizeof(struct beam)), MEMPOOL_STAGE);

	for (i = 0; i < g_MaxThrownLaptops; i++) {
		g_ThrownLaptops[i].base.prop = NULL;
	}
}

static void setupCreateLiftDoor(struct linkliftdoorobj *link)
{
	link->next = g_LiftDoors;
	g_LiftDoors = link;
}

static void setupCreateConditionalScenery(struct linksceneryobj *link)
{
	link->next = g_LinkedScenery;
	g_LinkedScenery = link;
}

static void setupCreateBlockedPath(struct blockedpathobj *blockedpath)
{
	blockedpath->next = g_BlockedPaths;
	g_BlockedPaths = blockedpath;
}

static void setupReset0f00cc8c(void)
{
	var8009ce98 = var80061a80;
}

static void setupResetProxyMines(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Proxies); i++) {
		g_Proxies[i] = NULL;
	}

	g_NumProxies = 0;
}

static s32 setupCountCommandType(u32 type)
{
	struct defaultobj *obj = (struct defaultobj *)g_StageSetup.props;
	s32 count = 0;

	if (obj) {
		while (obj->type != OBJTYPE_END) {
			if (obj->type == (u8)type) {
				count++;
			}

			obj = (struct defaultobj *)((u32 *)obj + setupGetCmdLength((u32 *)obj));
		}
	}

	return count;
}

void setupCreateObject(struct defaultobj *obj, s32 cmdindex)
{
	f32 f0;
	s32 modelnum;
	struct pad *pad;
	Mtxf mtx;
	struct coord centre;
	f32 scale;
	struct coord pos;
	s16 rooms[8];
	struct prop *prop2;
	u32 flag40;
	u32 stack;
	struct chrdata *chr;
	struct prop *prop;

	modelnum = obj->modelnum;
	setupLoadModeldef(modelnum);
	scale = obj->extrascale * (1.0f / 256.0f);

	if (g_Vars.normmplayerisrunning || g_Vars.lvmpbotlevel) {
		obj->hidden2 |= OBJH2FLAG_CANREGEN;
	}

	if (obj->flags & OBJFLAG_INSIDEANOTHEROBJ) {
		if (obj->type == OBJTYPE_WEAPON) {
			func0f08ae0c((struct weaponobj *)obj, g_ModelStates[modelnum].filedata);
		} else {
			objInitWithModelDef(obj, g_ModelStates[modelnum].filedata);
		}

		obj->model->scale *= scale;
		return;
	}

	if (obj->flags & OBJFLAG_ASSIGNEDTOCHR) {
		chr = chrFindByLiteralId(obj->pad);

		if (chr && chr->prop && chr->model) {
			if (obj->type == OBJTYPE_WEAPON) {
				prop = func0f08ae0c((struct weaponobj *)obj, g_ModelStates[modelnum].filedata);
			} else {
				prop = objInitWithModelDef(obj, g_ModelStates[modelnum].filedata);
			}

			obj->model->scale *= scale;
			propReparent(prop, chr->prop);
		}
	} else {
		if (obj->pad < 0) {
			if (obj->type == OBJTYPE_WEAPON) {
				func0f08ae0c((struct weaponobj *)obj, g_ModelStates[modelnum].filedata);
			} else {
				objInitWithModelDef(obj, g_ModelStates[modelnum].filedata);
			}

			obj->model->scale *= scale;
			return;
		}

		pad = &g_Pads[obj->pad];

		if (pad->room > 0) {
			mtx00016d58(&mtx, 0, 0, 0, -pad->look.x, -pad->look.y, -pad->look.z, pad->up.x, pad->up.y, pad->up.z);

			pos = pad->pos;

			rooms[0] = pad->room;
			rooms[1] = -1;

			if (!padHasBboxData(obj->pad)) {
				if (obj->flags & OBJFLAG_00000002) {
					centre = pad->pos;
				} else {
					centre = pad->pos;
				}
			} else {
				padGetCentre(obj->pad, &centre);
				centre.x += (pad->bbox.ymin - pad->bbox.ymax) * 0.5f * pad->up.x;
				centre.y += (pad->bbox.ymin - pad->bbox.ymax) * 0.5f * pad->up.y;
				centre.z += (pad->bbox.ymin - pad->bbox.ymax) * 0.5f * pad->up.z;
			}

			if (obj->type == OBJTYPE_WEAPON) {
				prop2 = func0f08ae0c((struct weaponobj *)obj, g_ModelStates[modelnum].filedata);
			} else {
				prop2 = objInitWithAutoModel(obj);
			}

			if (padHasBboxData(obj->pad)) {
				struct modelrodata_bbox *bbox = objFindBboxRodata(obj);

				if (bbox != NULL) {
					f32 xscale = 1.0f;
					f32 yscale = 1.0f;
					f32 zscale = 1.0f;
					f32 minscale;
					f32 maxscale;

					flag40 = OBJFLAG_00000040;

					if (obj->flags & OBJFLAG_00000020) {
						if (bbox->xmin < bbox->xmax) {
							if (obj->flags & OBJFLAG_00000002) {
								xscale = (pad->bbox.xmax - pad->bbox.xmin) / ((bbox->xmax - bbox->xmin) * obj->model->scale);
							} else {
								xscale = (pad->bbox.xmax - pad->bbox.xmin) / ((bbox->xmax - bbox->xmin) * obj->model->scale);
							}
						}
					}

					if (obj->flags & flag40) {
						if (bbox->ymin < bbox->ymax) {
							if (obj->flags & OBJFLAG_00000002) {
								zscale = (pad->bbox.zmax - pad->bbox.zmin) / ((bbox->ymax - bbox->ymin) * obj->model->scale);
							} else {
								yscale = (pad->bbox.ymax - pad->bbox.ymin) / ((bbox->ymax - bbox->ymin) * obj->model->scale);
							}
						}
					}

					if (obj->flags & OBJFLAG_00000080) {
						if (bbox->zmin < bbox->zmax) {
							if (obj->flags & OBJFLAG_00000002) {
								yscale = (pad->bbox.ymax - pad->bbox.ymin) / ((bbox->zmax - bbox->zmin) * obj->model->scale);
							} else {
								zscale = (pad->bbox.zmax - pad->bbox.zmin) / ((bbox->zmax - bbox->zmin) * obj->model->scale);
							}
						}
					}

					minscale = xscale;

					if (yscale < minscale) {
						minscale = yscale;
					}

					if (zscale < minscale) {
						minscale = zscale;
					}

					maxscale = xscale;

					if (yscale > maxscale) {
						maxscale = yscale;
					}

					if (zscale > maxscale) {
						maxscale = zscale;
					}

					if ((obj->flags & OBJFLAG_00000020) == 0) {
						if (obj->flags & OBJFLAG_00000002) {
							if (bbox->xmax == bbox->xmin) {
								xscale = maxscale;
							}
						} else if (bbox->xmax == bbox->xmin) {
							xscale = maxscale;
						}
					}

					if ((u32)(obj->flags & flag40) == 0) {
						if (obj->flags & OBJFLAG_00000002) {
							if (bbox->ymax == bbox->ymin) {
								zscale = maxscale;
							}
						} else if (bbox->ymax == bbox->ymin) {
							yscale = maxscale;
						}
					}

					if ((obj->flags & OBJFLAG_00000080) == 0) {
						if (obj->flags & OBJFLAG_00000002) {
							if (bbox->zmax == bbox->zmin) {
								yscale = maxscale;
							}
						} else if (bbox->zmax == bbox->zmin) {
							zscale = maxscale;
						}
					}

					xscale /= maxscale;
					yscale /= maxscale;
					zscale /= maxscale;

					if (xscale <= 0.000001f || yscale <= 0.000001f || zscale <= 0.000001f) {
						xscale = yscale = zscale = 1;
					}

					mtx00015e24(xscale, &mtx);
					mtx00015e80(yscale, &mtx);
					mtx00015edc(zscale, &mtx);

					obj->model->scale *= maxscale;
				}
			}

			obj->model->scale *= scale;
			mtx00015f04(obj->model->scale, &mtx);

			if (obj->flags2 & OBJFLAG2_00020000) {
				prop2->flags |= PROPFLAG_DONTPAUSE;
			}

			if (obj->flags & OBJFLAG_00000002) {
				func0f06ab60(obj, &pos, &mtx, rooms, &centre);
			} else {
				func0f06a730(obj, &pos, &mtx, rooms, &centre);
			}

			if (obj->hidden & OBJHFLAG_00008000) {
				propActivateThisFrame(prop2);
			} else {
				propActivate(prop2);
			}

			propEnable(prop2);
		}
	}
}

/**
 * Assigns a weapon to its home.
 *
 * Its home is a chr's hand or a pad, as defined in the stage's setup file.
 *
 * The Marquis of Queensbury Rules (everyone unarmed) and Enemy Rockets cheats
 * are implemented here.
 */
void setupPlaceWeapon(struct weaponobj *weapon, s32 cmdindex)
{
	if (weapon->base.flags & OBJFLAG_ASSIGNEDTOCHR) {
		u32 stack[2];
		struct chrdata *chr = chrFindByLiteralId(weapon->base.pad);

		if (chr && chr->prop && chr->model) {
			if (cheatIsActive(CHEAT_MARQUIS)) {
				weapon->base.flags &= ~OBJFLAG_DEACTIVATED;
				weapon->base.flags |= OBJFLAG_WEAPON_AICANNOTUSE;
				modelmgrLoadProjectileModeldefs(weapon->weaponnum);
				func0f08b25c(weapon, chr);
			} else {
				if (cheatIsActive(CHEAT_ENEMYROCKETS)) {
					switch (weapon->weaponnum) {
					case WEAPON_FALCON2:
					case WEAPON_FALCON2_SILENCER:
					case WEAPON_FALCON2_SCOPE:
					case WEAPON_MAGSEC4:
					case WEAPON_MAULER:
					case WEAPON_PHOENIX:
					case WEAPON_DY357MAGNUM:
					case WEAPON_DY357LX:
					case WEAPON_CMP150:
					case WEAPON_CYCLONE:
					case WEAPON_CALLISTO:
					case WEAPON_RCP120:
					case WEAPON_LAPTOPGUN:
					case WEAPON_DRAGON:
					case WEAPON_AR34:
					case WEAPON_SUPERDRAGON:
					case WEAPON_SHOTGUN:
					case WEAPON_REAPER:
					case WEAPON_SNIPERRIFLE:
					case WEAPON_FARSIGHT:
					case WEAPON_DEVASTATOR:
					case WEAPON_ROCKETLAUNCHER:
					case WEAPON_SLAYER:
					case WEAPON_COMBATKNIFE:
					case WEAPON_CROSSBOW:
					case WEAPON_TRANQUILIZER:
					case WEAPON_GRENADE:
					case WEAPON_NBOMB:
					case WEAPON_TIMEDMINE:
					case WEAPON_PROXIMITYMINE:
					case WEAPON_REMOTEMINE:
						weapon->weaponnum = WEAPON_ROCKETLAUNCHER;
						weapon->base.modelnum = MODEL_CHRDYROCKET;
						weapon->base.extrascale = 256;
						break;
					case WEAPON_K7AVENGER:
						// Don't replace the K7 guard's weapon in Investigation
						// because it would make an objective impossible.
						// @bug: It's still replaced on PD mode difficulty.
						if (g_Vars.stagenum != STAGE_INVESTIGATION || g_Difficulty != DIFF_PA) {
							weapon->weaponnum = WEAPON_ROCKETLAUNCHER;
							weapon->base.modelnum = MODEL_CHRDYROCKET;
							weapon->base.extrascale = 256;
						}
						break;
					}
				}

				modelmgrLoadProjectileModeldefs(weapon->weaponnum);
				func0f08b25c(weapon, chr);
			}
		}
	} else {
		bool giveweapon = true;

		if (g_Vars.normmplayerisrunning || g_Vars.lvmpbotlevel) {
			struct mpweapon *mpweapon;
			s32 mpweaponnum;

			var8009cc30 = -1;

			// Seems like a weaponnum >= 240 means an mpweaponnum...
			switch (weapon->weaponnum) {
			case 0xf0:
			case 0xf1:
			case 0xf2:
			case 0xf3:
			case 0xf4:
			case 0xf5:
			case 0xf6:
			case 0xf7:
			case 0xf8:
			case 0xf9:
			case 0xfa:
			case 0xfb:
			case 0xfc:
			case 0xfd:
			case 0xfe:
			case 0xff:
				mpweaponnum = weapon->weaponnum - 0xf0;
				mpweapon = func0f188e24(mpweaponnum);
				var8009cc30 = mpweaponnum;
				weapon->weaponnum = mpweapon->weaponnum;
				weapon->base.modelnum = mpweapon->model;
				weapon->base.extrascale = mpweapon->extrascale;
				giveweapon = mpweapon->giveweapon;

				if (mpweapon->weaponnum == WEAPON_MPSHIELD) {
					struct shieldobj *shield = (struct shieldobj *)weapon;
					shield->base.modelnum = MODEL_CHRSHIELD;
					shield->base.type = OBJTYPE_SHIELD;
					shield->base.flags |= OBJFLAG_01000000 | OBJFLAG_INVINCIBLE;
					shield->base.flags2 |= OBJFLAG2_00200000 | OBJFLAG2_IMMUNETOGUNFIRE;
					shield->initialamount = 1;
					shield->amount = 1;
					setupCreateObject(&shield->base, cmdindex);
					giveweapon = false;
				}
				break;
			}
		}

		if (weapon->weaponnum != WEAPON_NONE && giveweapon) {
			modelmgrLoadProjectileModeldefs(weapon->weaponnum);
			setupCreateObject(&weapon->base, cmdindex);
		}
	}
}

static void setupCreateKey(struct keyobj *key, s32 cmdindex)
{
	setupCreateObject(&key->base, cmdindex);
}

static void setupCreateMine(struct mineobj *mine, s32 cmdindex)
{
	mine->base.type = OBJTYPE_WEAPON;

	setupCreateObject(&mine->base, cmdindex);

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mine->base.hidden = (mine->base.hidden & 0x0fffffff) | OBJHFLAG_20000000;
	}
}

static void setupCreateCctv(struct cctvobj *cctv, s32 cmdindex)
{
	struct defaultobj *obj = &cctv->base;

	setupCreateObject(obj, cmdindex);

	if (cctv->lookatpadnum >= 0) {
		struct coord lenspos;
		union modelrodata *lens = modelGetPartRodata(obj->model->filedata, MODELPART_CCTV_CASING);
		struct pad *pad;
		f32 xdiff;
		f32 ydiff;
		f32 zdiff;

		pad = &g_Pads[cctv->lookatpadnum];

		lenspos = lens->position.pos;

		mtx00016208(obj->realrot, &lenspos);

		lenspos.x += obj->prop->pos.x;
		lenspos.y += obj->prop->pos.y;
		lenspos.z += obj->prop->pos.z;

		xdiff = lenspos.x - pad->pos.x;
		ydiff = lenspos.y - pad->pos.y;
		zdiff = lenspos.z - pad->pos.z;

		if (ydiff) {
			// empty
		}

		mtx00016d58(&cctv->camrotm, 0.0f, 0.0f, 0.0f, xdiff, ydiff, zdiff, 0.0f, 1.0f, 0.0f);
		mtx00015f04(obj->model->scale, &cctv->camrotm);

		cctv->toleft = 0;
		cctv->yleft = *(s32 *)&cctv->yleft * M_BADTAU / 65536.0f;
		cctv->yright = *(s32 *)&cctv->yright * M_BADTAU / 65536.0f;
		cctv->yspeed = 0.0f;
		cctv->ymaxspeed = *(s32 *)&cctv->ymaxspeed * M_BADTAU / 65536.0f;
		cctv->maxdist = *(s32 *)&cctv->maxdist;
		cctv->yrot = cctv->yleft;

		cctv->yzero = atan2f(xdiff, zdiff);
		cctv->xzero = M_BADTAU - atan2f(ydiff, sqrtf(xdiff * xdiff + zdiff * zdiff));

		if (xdiff || zdiff) {
			// empty
		}

		cctv->seebondtime60 = 0;
	}
}

static void setupCreateAutogun(struct autogunobj *autogun, s32 cmdindex)
{
	setupCreateObject(&autogun->base, cmdindex);

	autogun->maxspeed = *(s32 *)&autogun->maxspeed * PALUPF(M_BADTAU) / 65536.0f;
	autogun->aimdist = *(s32 *)&autogun->aimdist * 100.0f / 65536.0f;
	autogun->ymaxleft = *(s32 *)&autogun->ymaxleft * M_BADTAU / 65536.0f;
	autogun->ymaxright = *(s32 *)&autogun->ymaxright * M_BADTAU / 65536.0f;

	autogun->firecount = 0;
	autogun->lastseebond60 = -1;
	autogun->lastaimbond60 = -1;
	autogun->allowsoundframe = -1;
	autogun->yrot = 0;
	autogun->yspeed = 0;
	autogun->yzero = 0;
	autogun->xrot = 0;
	autogun->xspeed = 0;
	autogun->xzero = 0;
	autogun->barrelspeed = 0;
	autogun->barrelrot = 0;
	autogun->beam = mempAlloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
	autogun->beam->age = -1;
	autogun->firing = false;
	autogun->ammoquantity = 255;
	autogun->shotbondsum = 0;

	if (autogun->targetpad >= 0) {
		u32 stack1;
		f32 xdiff;
		f32 ydiff;
		f32 zdiff;
		u32 stack2;
		struct pad *pad;

		pad = &g_Pads[autogun->targetpad];

		xdiff = pad->pos.x - autogun->base.prop->pos.x;
		ydiff = pad->pos.y - autogun->base.prop->pos.y;
		zdiff = pad->pos.z - autogun->base.prop->pos.z;

		autogun->yzero = atan2f(xdiff, zdiff);
		autogun->xzero = atan2f(ydiff, sqrtf(xdiff * xdiff + zdiff * zdiff));
	} else if (autogun->base.modelnum == MODEL_CETROOFGUN) {
		// Deep Sea roofgun
		autogun->xzero = -1.5705462694168f;
	}
}

static void setupCreateSingleMonitor(struct singlemonitorobj *monitor, s32 cmdindex)
{
	u32 stack[2];

	monitor->screen = var8009ce98;
	tvscreenSetImageByNum(&monitor->screen, monitor->imagenum);

	// In GE, monitors with a negative pad are hanging TVs which attach to a
	// hangingmonitors object, which is actually just the mount. In PD, hanging
	// monitors do not exist in the setup files so this code is unused.
	if (monitor->base.pad < 0 && (monitor->base.flags & OBJFLAG_INSIDEANOTHEROBJ) == 0) {
		s32 modelnum = monitor->base.modelnum;
		struct defaultobj *owner = (struct defaultobj *)setupGetCmdByIndex(cmdindex + monitor->owneroffset);
		struct prop *prop;
		f32 scale;
		struct coord spa4;
		Mtxf sp64;
		Mtxf sp24;

		setupLoadModeldef(modelnum);

		scale = monitor->base.extrascale * (1.0f / 256.0f);

		if (g_Vars.normmplayerisrunning || g_Vars.lvmpbotlevel) {
			monitor->base.hidden2 |= OBJH2FLAG_CANREGEN;
		}

		prop = objInitWithAutoModel(&monitor->base);
		monitor->base.embedment = embedmentAllocate();

		if (prop && monitor->base.embedment) {
			monitor->base.hidden |= OBJHFLAG_EMBEDDED;
			monitor->base.model->scale *= scale;
			monitor->base.model->attachedtomodel = owner->model;

			if (monitor->ownerpart == MODELPART_0000) {
				monitor->base.model->attachedtonode = modelGetPart(owner->model->filedata, MODELPART_0000);
			} else if (monitor->ownerpart == MODELPART_0001) {
				monitor->base.model->attachedtonode = modelGetPart(owner->model->filedata, MODELPART_0001);
			} else if (monitor->ownerpart == MODELPART_0002) {
				monitor->base.model->attachedtonode = modelGetPart(owner->model->filedata, MODELPART_0002);
			} else {
				monitor->base.model->attachedtonode = modelGetPart(owner->model->filedata, MODELPART_0003);
			}

			propReparent(prop, owner->prop);
			mtx4LoadXRotation(0.3664608001709f, &sp64);
			mtx00015f04(monitor->base.model->scale / owner->model->scale, &sp64);
			modelGetRootPosition(monitor->base.model, &spa4);

			spa4.x = -spa4.x;
			spa4.y = -spa4.y;
			spa4.z = -spa4.z;

			mtx4LoadTranslation(&spa4, &sp24);
			mtx00015be4(&sp64, &sp24, &monitor->base.embedment->matrix);
		}
	} else {
		setupCreateObject(&monitor->base, cmdindex);
	}

	if (monitor->base.prop && (monitor->base.flags & OBJFLAG_MONITOR_RENDERPOSTBG)) {
		monitor->base.prop->flags |= PROPFLAG_RENDERPOSTBG;
	}
}

static void setupCreateMultiMonitor(struct multimonitorobj *monitor, s32 cmdindex)
{
	monitor->screens[0] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[0], monitor->imagenums[0]);

	monitor->screens[1] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[1], monitor->imagenums[1]);

	monitor->screens[2] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[2], monitor->imagenums[2]);

	monitor->screens[3] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[3], monitor->imagenums[3]);

	setupCreateObject(&monitor->base, cmdindex);
}

static s32 setupGetPortalByPad(s32 padnum)
{
	f32 mult;
	struct coord centre;
	struct coord coord;
	u32 stack;
	struct pad *pad;

	padGetCentre(padnum, &centre);
	pad = &g_Pads[padnum];

	mult = (pad->bbox.ymax - pad->bbox.ymin) * 0.5f + 10;

	coord.x = pad->up.x * mult + centre.x;
	coord.y = pad->up.y * mult + centre.y;
	coord.z = pad->up.z * mult + centre.z;

	centre.x = centre.x - pad->up.x * mult;
	centre.y = centre.y - pad->up.y * mult;
	centre.z = centre.z - pad->up.z * mult;

	return bg0f164e8c(&centre, &coord);
}

static s32 setupGetPortalByDoorPad(s32 padnum)
{
	f32 mult;
	struct coord centre;
	struct coord coord;
	u32 stack;
	struct pad *pad;

	padGetCentre(padnum, &centre);

	pad = &g_Pads[padnum];

	mult = (pad->bbox.xmax - pad->bbox.xmin) * 0.5f + 10;

	coord.x = pad->normal.x * mult + centre.x;
	coord.y = pad->normal.y * mult + centre.y;
	coord.z = pad->normal.z * mult + centre.z;

	centre.x = centre.x - pad->normal.x * mult;
	centre.y = centre.y - pad->normal.y * mult;
	centre.z = centre.z - pad->normal.z * mult;

	return bg0f164e8c(&centre, &coord);
}

static void setupCreateDoor(struct doorobj *door, s32 cmdindex)
{
	f32 scale;
	s32 modelnum = door->base.modelnum;
	s32 portalnum = -1;
	struct pad *pad;

	setupLoadModeldef(modelnum);

	if (door->doorflags & DOORFLAG_ROTATEDPAD) {
		padRotateForDoor(door->base.pad);
	}

	if (door->base.flags & OBJFLAG_DOOR_HASPORTAL) {
		portalnum = setupGetPortalByDoorPad(door->base.pad);
	}

	pad = &g_Pads[door->base.pad];

	if (g_DoorScale != 1) {
		pad->bbox.xmin *= g_DoorScale;
		pad->bbox.xmax *= g_DoorScale;

		// If the door has a portal, adjust the pad's bbox to match the portal's dimensions
		if (portalnum >= 0) {
			struct var800a4ccc *ptr = &var800a4ccc[portalnum];
			f32 f0 = pad->pos.f[0] * ptr->coord.f[0] + pad->pos.f[1] * ptr->coord.f[1] + pad->pos.f[2] * ptr->coord.f[2];
			f32 min = ptr->min;
			struct coord sp150;
			f0 = (f0 - min) * (g_DoorScale - 1);

			sp150.x = ptr->coord.x * f0;
			sp150.y = ptr->coord.y * f0;
			sp150.z = ptr->coord.z * f0;

			f0 = sp150.f[0] * pad->normal.f[0] + sp150.f[1] * pad->normal.f[1] + sp150.f[2] * pad->normal.f[2];
			pad->bbox.xmin += f0;
			pad->bbox.xmax += f0;

			f0 = sp150.f[0] * pad->up.f[0] + sp150.f[1] * pad->up.f[1] + sp150.f[2] * pad->up.f[2];
			pad->bbox.ymin += f0;
			pad->bbox.ymax += f0;

			f0 = sp150.f[0] * pad->look.f[0] + sp150.f[1] * pad->look.f[1] + sp150.f[2] * pad->look.f[2];
			pad->bbox.zmin += f0;
			pad->bbox.zmax += f0;
		}
	}

	if (pad->room > 0) {
		Mtxf sp110;
		struct prop *prop;
		s32 siblingcmdindex;
		struct coord pos;
		s16 rooms[8];
		Mtxf finalmtx;
		struct coord centre;
		Mtxf zrotmtx;
		struct coord sp54;
		f32 xscale;
		f32 yscale;
		f32 zscale;
		struct modelrodata_bbox *bbox;

		bbox = modelFileDataFindBboxRodata(g_ModelStates[modelnum].filedata);

		mtx00016d58(&sp110, 0, 0, 0,
				-pad->look.x, -pad->look.y, -pad->look.z,
				pad->up.x, pad->up.y, pad->up.z);
		mtx4LoadXRotation(1.5705462694168f, &finalmtx);
		mtx4LoadZRotation(1.5705462694168f, &zrotmtx);
		mtx4MultMtx4InPlace(&zrotmtx, &finalmtx);
		mtx4MultMtx4InPlace(&sp110, &finalmtx);

		padGetCentre(door->base.pad, &centre);

		xscale = (pad->bbox.ymax - pad->bbox.ymin) / (bbox->xmax - bbox->xmin);
		yscale = (pad->bbox.zmax - pad->bbox.zmin) / (bbox->ymax - bbox->ymin);
		zscale = (pad->bbox.xmax - pad->bbox.xmin) / (bbox->zmax - bbox->zmin);

		if (xscale <= 0.000001f || yscale <= 0.000001f || zscale <= 0.000001f) {
			xscale = yscale = zscale = 1;
		}

		mtx00015e24(xscale, &finalmtx);
		mtx00015e80(yscale, &finalmtx);
		mtx00015edc(zscale, &finalmtx);

		pos = pad->pos;

		rooms[0] = pad->room;
		rooms[1] = -1;

		if (door->doortype == DOORTYPE_VERTICAL || door->doortype == DOORTYPE_FALLAWAY) {
			sp54.x = pad->look.f[0] * (pad->bbox.zmax - pad->bbox.zmin);
			sp54.y = pad->look.f[1] * (pad->bbox.zmax - pad->bbox.zmin);
			sp54.z = pad->look.f[2] * (pad->bbox.zmax - pad->bbox.zmin);
		} else {
			sp54.x = pad->up.f[0] * (pad->bbox.ymin - pad->bbox.ymax);
			sp54.y = pad->up.f[1] * (pad->bbox.ymin - pad->bbox.ymax);
			sp54.z = pad->up.f[2] * (pad->bbox.ymin - pad->bbox.ymax);
		}

		// These values are stored in the setup files as integers, but at
		// runtime they are floats. Hence reading a "float" as an integer,
		// converting it to a float and writing it back to the same property.
		door->maxfrac = *(s32 *) &door->maxfrac / 65536.0f;
		door->perimfrac = *(s32 *) &door->perimfrac / 65536.0f;
		door->accel = PALUPF(*(s32 *) &door->accel) / 65536000.0f;
		door->decel = PALUPF(*(s32 *) &door->decel) / 65536000.0f;
		door->maxspeed = PALUPF(*(s32 *) &door->maxspeed) / 65536.0f;

		// The sibling door is stored as a relative command number,
		// but at runtime it's a pointer.
		if (door->sibling) {
			siblingcmdindex = *(s32 *) &door->sibling + cmdindex;
			door->sibling = (struct doorobj *) setupGetCmdByIndex(siblingcmdindex);
		}

		prop = doorInit(door, &pos, &finalmtx, rooms, &sp54, &centre);

		if (door->base.flags & OBJFLAG_DOOR_HASPORTAL) {
			door->portalnum = portalnum;

			if (door->portalnum >= 0 && door->frac == 0) {
				doorDeactivatePortal(door);
			}
		}

		if (door->base.model) {
			scale = xscale;

			if (yscale > scale) {
				scale = yscale;
			}

			if (zscale > scale) {
				scale = zscale;
			}

			door->base.model->scale *= scale;
		}

		propActivate(prop);
		propEnable(prop);
	} else {
		door->base.prop = NULL;
	}
}

static void setupCreateHov(struct defaultobj *obj, struct hov *hov)
{
	hov->unk04 = 0;
	hov->unk08 = 0;
	hov->unk0c = 0;
	hov->unk10 = atan2f(obj->realrot[2][0], obj->realrot[2][2]);
	hov->unk14 = 0;
	hov->unk18 = 0;
	hov->unk1c = 0;
	hov->unk20 = 0;
	hov->unk24 = 0;
	hov->unk28 = 0;
	hov->unk2c = 0;
	hov->unk30 = 0;
	hov->ground = 0;
	hov->nexttick60 = -1;
	hov->prevtick60 = -1;
}

void setupLoadBriefing(s32 stagenum, u8 *buffer, s32 bufferlen, struct briefing *briefing)
{
	if (stagenum < STAGE_TITLE) {
		s32 stageindex = stageGetIndex(stagenum);
		struct defaultobj *start;
		u16 setupfilenum;
		s32 setupfilesize;
		struct objective *objective;
		struct briefingobj *briefingobj;
		s32 i;
		u8 *langbuffer;
		s32 langbufferlen;
		struct stagesetup *setup;

		if (stageindex < 0) {
			stageindex = 0;
		}

		setupfilenum = g_Stages[stageindex].setupfileid;

		fileLoadToAddr(setupfilenum, FILELOADMETHOD_DEFAULT, buffer, bufferlen);

		setup = (struct stagesetup *)buffer;
		setupfilesize = fileGetLoadedSize(setupfilenum);
		langbuffer = &buffer[setupfilesize];
		langbufferlen = bufferlen - setupfilesize;

		briefing->langbank = langGetLangBankIndexFromStagenum(stagenum);

		langLoadToAddr(briefing->langbank, langbuffer, langbufferlen);

		start = (struct defaultobj *)((u32)setup + (u32)setup->props);

		if (start != NULL) {
			struct defaultobj *obj;
			s32 wanttype = BRIEFINGTYPE_TEXT_PA;

			if (g_Difficulty == DIFF_A) {
				wanttype = BRIEFINGTYPE_TEXT_A;
			}

			if (g_Difficulty == DIFF_SA) {
				wanttype = BRIEFINGTYPE_TEXT_SA;
			}

			for (i = 0; (u32)(i < 6); i++) {
				briefing->objectivenames[i] = 0;
			}

			briefing->briefingtextnum = L_MISC_042; // "No briefing for this mission"

			obj = start;

			while (obj->type != OBJTYPE_END) {
				if (1);
				switch (obj->type) {
				case OBJTYPE_BRIEFING:
					briefingobj = (struct briefingobj *) obj;

					if (briefingobj->type == BRIEFINGTYPE_TEXT_PA) {
						briefing->briefingtextnum = briefingobj->text;
					}

					if (briefingobj->type == wanttype) {
						briefing->briefingtextnum = briefingobj->text;
					}
					break;
				case OBJTYPE_BEGINOBJECTIVE:
					objective = (struct objective *) obj;

					if (objective->index < 7U) {
						briefing->objectivenames[objective->index] = objective->text;
						briefing->objectivedifficulties[objective->index] = objective->difficulties;
					}
					break;
				}

				obj = (struct defaultobj *)((u32 *)obj + setupGetCmdLength((u32 *)obj));
			}
		}
	}
}

extern u8 _setupdishasmSegmentStart;

static struct ailist *getStageAilists(void)
{
	if (g_StageIndex >= 0 && g_StageIndex < ARRAYCOUNT(g_Stages)) {
		if (g_Stages[g_StageIndex].ailistsromstart) {
			u8 *dst = &_setupdishasmSegmentStart;
			u32 len = g_Stages[g_StageIndex].ailistsromend - g_Stages[g_StageIndex].ailistsromstart;

			dmaExec(dst, (u32) g_Stages[g_StageIndex].ailistsromstart, len);

			osInvalICache(0, ICACHE_SIZE);
			osInvalDCache(0, DCACHE_SIZE);

			return g_Stages[g_StageIndex].ailists;
		}
	}

	return NULL;
}

void setupLoadFiles(s32 stagenum)
{
	s32 i;
	s32 j;
	struct ailist tmp;
	s32 numchrs = 0;
	s32 numobjs = 0;
	s32 extra;
	struct stagesetup *setup;
	u16 filenum;
	bool modified;

	g_PadEffects = NULL;
	g_LastPadEffectIndex = -1;

	g_DoorScale = 1;

	for (i = 0; i < NUM_MODELS; i++) {
		g_ModelStates[i].filedata = NULL;
	}

	if (stagenum < STAGE_TITLE) {
		if (g_Vars.normmplayerisrunning) {
			filenum = g_Stages[g_StageIndex].mpsetupfileid;
		} else {
			filenum = g_Stages[g_StageIndex].setupfileid;
		}

		g_GeCreditsData = (u8 *)fileLoadToNew(filenum, FILELOADMETHOD_DEFAULT);
		setup = (struct stagesetup *)g_GeCreditsData;
		langLoad(langGetLangBankIndexFromStagenum(stagenum));

		g_StageSetup.intro = (s32 *)((u32)setup + (u32)setup->intro);
		g_StageSetup.props = (u32 *)((u32)setup + (u32)setup->props);
		g_StageSetup.paths = (struct path *)((u32)setup + (u32)setup->paths);
		g_StageSetup.ailists = getStageAilists();

		g_StageSetup.padfiledata = fileLoadToNew(g_Stages[g_StageIndex].padsfileid, FILELOADMETHOD_DEFAULT);

		g_StageSetup.waypoints = NULL;
		g_StageSetup.waygroups = NULL;
		g_StageSetup.cover = NULL;

		// Sort the global AI lists by ID asc
		do {
			modified = false;

			for (i = 0; g_GlobalAilists[i + 1].list != NULL; i++) {
				if (g_GlobalAilists[i + 1].id < g_GlobalAilists[i].id) {
					// Swap them
					tmp = g_GlobalAilists[i];
					g_GlobalAilists[i] = g_GlobalAilists[i + 1];
					g_GlobalAilists[i + 1] = tmp;

					modified = true;
				}
			}
		} while (modified);

		// Sort the stage AI lists by ID asc
		do {
			modified = false;

			for (i = 0; g_StageSetup.ailists[i + 1].list != NULL; i++) {
				if (g_StageSetup.ailists[i + 1].id < g_StageSetup.ailists[i].id) {
					// Swap them
					tmp = g_StageSetup.ailists[i];
					g_StageSetup.ailists[i] = g_StageSetup.ailists[i + 1];
					g_StageSetup.ailists[i + 1] = tmp;

					modified = true;
				}
			}
		} while (modified);

		// Count the AI lists
		for (g_NumGlobalAilists = 0; g_GlobalAilists[g_NumGlobalAilists].list != NULL; g_NumGlobalAilists++);
		for (g_NumLvAilists = 0; g_StageSetup.ailists[g_NumLvAilists].list != NULL; g_NumLvAilists++);

		// Convert path pad pointers from file-local to proper pointers
		// and calculate the path lengths
		if (g_StageSetup.paths) {
			for (i = 0; g_StageSetup.paths[i].pads != NULL; i++) {
				g_StageSetup.paths[i].pads = (s32 *)((u32)g_StageSetup.paths[i].pads + (u32)setup);

				for (j = 0; g_StageSetup.paths[i].pads[j] >= 0; j++);

				g_StageSetup.paths[i].len = j;
			}
		}

		// Count the number of chrs and objects so enough model slots can be allocated
		numchrs += setupCountCommandType(OBJTYPE_CHR);

		if (!g_Vars.normmplayerisrunning && g_MissionConfig.iscoop && g_Vars.numaibuddies > 0) {
			// @bug? The Hotshot buddy has two guns, but only one is counted here.
			numchrs += g_Vars.numaibuddies;
			numobjs += g_Vars.numaibuddies; // the buddy's weapon
		}

		numobjs += setupCountCommandType(OBJTYPE_WEAPON);
		numobjs += setupCountCommandType(OBJTYPE_KEY);
		numobjs += setupCountCommandType(OBJTYPE_HAT);
		numobjs += setupCountCommandType(OBJTYPE_DOOR);
		numobjs += setupCountCommandType(OBJTYPE_CCTV);
		numobjs += setupCountCommandType(OBJTYPE_AUTOGUN);
		numobjs += setupCountCommandType(OBJTYPE_HANGINGMONITORS);
		numobjs += setupCountCommandType(OBJTYPE_SINGLEMONITOR);
		numobjs += setupCountCommandType(OBJTYPE_MULTIMONITOR);
		numobjs += setupCountCommandType(OBJTYPE_SHIELD);
		numobjs += setupCountCommandType(OBJTYPE_BASIC);
		numobjs += setupCountCommandType(OBJTYPE_DEBRIS);
		numobjs += setupCountCommandType(OBJTYPE_GLASS);
		numobjs += setupCountCommandType(OBJTYPE_TINTEDGLASS);
		numobjs += setupCountCommandType(OBJTYPE_SAFE);
		numobjs += setupCountCommandType(OBJTYPE_29);
		numobjs += setupCountCommandType(OBJTYPE_GASBOTTLE);
		numobjs += setupCountCommandType(OBJTYPE_ALARM);
		numobjs += setupCountCommandType(OBJTYPE_AMMOCRATE);
		numobjs += setupCountCommandType(OBJTYPE_MULTIAMMOCRATE);
		numobjs += setupCountCommandType(OBJTYPE_TRUCK);
		numobjs += setupCountCommandType(OBJTYPE_TANK);
		numobjs += setupCountCommandType(OBJTYPE_LIFT);
		numobjs += setupCountCommandType(OBJTYPE_HOVERBIKE);
		numobjs += setupCountCommandType(OBJTYPE_HOVERPROP);
		numobjs += setupCountCommandType(OBJTYPE_FAN);
		numobjs += setupCountCommandType(OBJTYPE_HOVERCAR);
		numobjs += setupCountCommandType(OBJTYPE_CHOPPER);
		numobjs += setupCountCommandType(OBJTYPE_HELI);
		numobjs += setupCountCommandType(OBJTYPE_ESCASTEP);

		if (g_Vars.normmplayerisrunning) {
			numobjs += scenarioNumProps();
		}

		modelmgrAllocateSlots(numobjs, numchrs);
	} else {
		// cover isn't set to NULL here... I guess it's not important
		g_StageSetup.waypoints = NULL;
		g_StageSetup.waygroups = NULL;
		g_StageSetup.intro = 0;
		g_StageSetup.props = 0;
		g_StageSetup.paths = NULL;
		g_StageSetup.ailists = NULL;
		g_StageSetup.padfiledata = NULL;

		modelmgrAllocateSlots(0, 0);
	}

	extra = 60;

	g_Vars.maxprops = numobjs + numchrs + extra + 40;
}

void setupCreateProps(s32 stagenum)
{
	s32 withchrs = true;
	s32 withobjs = true;
	s32 withhovercars;
	s32 escstepx;
	s32 escstepy;
	struct defaultobj *obj;
	s32 i;
	s32 j;

	withhovercars = !(stagenum == STAGE_EXTRACTION || stagenum == STAGE_DEFECTION)
		|| !(g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0);

	escstepx = 0;
	escstepy = 0;
	g_Vars.textoverrides = NULL;

	for (j = 0; j != 6; j++) {
		g_Briefing.objectivenames[j] = 0;
		g_Briefing.objectivedifficulties[j] = 0;
	}

	g_Briefing.briefingtextnum = L_MISC_042; // "No briefing for this mission"

	if (stagenum < STAGE_TITLE) {
		if (g_StageSetup.padfiledata) {
			setupPreparePads();
		}

		setupLoadWaypoints();

		if (withchrs) {
			s32 numchrs = 0;

			numchrs += setupCountCommandType(OBJTYPE_CHR);

			if (g_Vars.normmplayerisrunning == false
					&& g_MissionConfig.iscoop
					&& g_Vars.numaibuddies > 0) {
				numchrs += g_Vars.numaibuddies;
			}

			chrmgrConfigure(numchrs);
		} else {
			chrmgrConfigure(0);
		}

		for (j = 0; j < PLAYERCOUNT(); j++) {
			setCurrentPlayerNum(j);
			invInit(setupCountCommandType(OBJTYPE_LINKGUNS));
		}

		if (g_StageSetup.props) {
			u32 diffflag = 0;
			s32 index;

			diffflag |= 1 << (g_Difficulty + 4);

			if (g_Vars.mplayerisrunning) {
				if (PLAYERCOUNT() == 2) {
					diffflag |= OBJFLAG2_EXCLUDE_2P;
				} else if (PLAYERCOUNT() == 3) {
					diffflag |= OBJFLAG2_EXCLUDE_3P;
				} else if (PLAYERCOUNT() == 4) {
					diffflag |= OBJFLAG2_EXCLUDE_4P;
				}
			}

			botmgrRemoveAll();
			index = 0;

			obj = (struct defaultobj *)g_StageSetup.props;

			while (obj->type != OBJTYPE_END) {
				switch (obj->type) {
				case OBJTYPE_CHR:
					if (withchrs) {
						bodyAllocateChr(stagenum, (struct packedchr *) obj, index);
					}
					break;
				case OBJTYPE_DOOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateDoor((struct doorobj *)obj, index);
					}
					break;
				case OBJTYPE_DOORSCALE:
					{
						struct doorscaleobj *scale = (struct doorscaleobj *)obj;
						g_DoorScale = scale->scale / 65536.0f;
					}
					break;
				case OBJTYPE_WEAPON:
					if (withchrs && (obj->flags2 & diffflag) == 0) {
						setupPlaceWeapon((struct weaponobj *)obj, index);
					}
					break;
				case OBJTYPE_KEY:
					if (withchrs && (obj->flags2 & diffflag) == 0) {
						setupCreateKey((struct keyobj *)obj, index);
					}
					break;
				case OBJTYPE_CCTV:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateCctv((struct cctvobj *)obj, index);
					}
					break;
				case OBJTYPE_AUTOGUN:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateAutogun((struct autogunobj *)obj, index);
					}
					break;
				case OBJTYPE_SINGLEMONITOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateSingleMonitor((struct singlemonitorobj *)obj, index);
					}
					break;
				case OBJTYPE_MULTIMONITOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateMultiMonitor((struct multimonitorobj *)obj, index);
					}
					break;
				case OBJTYPE_SHIELD:
					if (withobjs) {
						if ((obj->flags2 & diffflag) == 0) {
							struct shieldobj *shield = (struct shieldobj *)obj;
							shield->initialamount = *(s32 *)&shield->initialamount / 65536.0f;
							shield->amount = shield->initialamount;
							setupCreateObject(obj, index);
						}
					}
					break;
				case OBJTYPE_TINTEDGLASS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						if (obj->flags & OBJFLAG_GLASS_HASPORTAL) {
							struct tintedglassobj *glass = (struct tintedglassobj *)obj;
							glass->portalnum = setupGetPortalByPad(obj->pad);
							glass->unk64 = *(s32 *)&glass->unk64 / 65536.0f;
						}

						setupCreateObject(obj, index);
					}
					break;
				case OBJTYPE_LIFT:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct liftobj *lift = (struct liftobj *)obj;
						struct modelstate *modelstate;
						s32 modelnum = obj->modelnum;
						struct prop *prop;
						s32 i;

						lift->accel = PALUPF(*(s32 *)&lift->accel) / 65536.0f;
						lift->maxspeed = PALUPF(*(s32 *)&lift->maxspeed) / 65536.0f;
						lift->dist = 0;
						lift->speed = 0;
						lift->levelcur = 0;
						lift->levelaim = 0;

						for (i = 0; i < 4; i++) {
							if (lift->doors[i]) {
								lift->doors[i] = (struct doorobj *)setupGetCmdByIndex(index + *(s32*)&lift->doors[i]);
							}
						}

						obj->geocount = 1;
						setupLoadModeldef(modelnum);
						modelstate = &g_ModelStates[modelnum];

						if (modelstate->filedata) {
							if (modelGetPartRodata(modelstate->filedata, 1)) {
								obj->geocount++;
							}
							if (modelGetPartRodata(modelstate->filedata, 2)) {
								obj->geocount++;
							}
							if (modelGetPartRodata(modelstate->filedata, 3)) {
								obj->geocount++;
							}
							if (modelGetPartRodata(modelstate->filedata, 4)) {
								obj->geocount++;
							}
							if (modelGetPartRodata(modelstate->filedata, 6)) {
								obj->geocount++;
							}
						}

						obj->flags &= ~OBJFLAG_00000100;

						setupCreateObject(obj, index);

						prop = obj->prop;

						if (prop) {
							lift->prevpos = prop->pos;

							liftUpdateTiles(lift, true);
						}
					}
					break;
				case OBJTYPE_HOVERPROP:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct hoverpropobj *hoverprop = (struct hoverpropobj *)obj;

						setupCreateObject(obj, index);
						setupCreateHov(obj, &hoverprop->hov);
					}
					break;
				case OBJTYPE_HOVERBIKE:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct hoverbikeobj *bike = (struct hoverbikeobj *)obj;

						setupCreateObject(obj, index);
						setupCreateHov(obj, &bike->hov);

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
					}
					break;
				case OBJTYPE_FAN:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct fanobj *fan = (struct fanobj *)obj;

						fan->yrot = 0;
						fan->ymaxspeed = PALUPF(*(s32 *)&fan->ymaxspeed) / 65536.0f;
						fan->yaccel = PALUPF(*(s32 *)&fan->yaccel) / 65536.0f;

						setupCreateObject(obj, index);
					}
					break;
				case OBJTYPE_GLASS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						if (obj->flags & OBJFLAG_GLASS_HASPORTAL) {
							struct glassobj *glass = (struct glassobj *)obj;
							glass->portalnum = setupGetPortalByPad(obj->pad);
						}

						setupCreateObject(obj, index);
					}
					break;
				case OBJTYPE_ESCASTEP:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct escalatorobj *step = (struct escalatorobj *)obj;
						struct prop *prop;

						Mtxf sp1a8;
						f32 sp184[3][3];

						setupCreateObject(obj, index);

						prop = obj->prop;

						if (prop) {
							step->prevpos = prop->pos;
						}

						if (obj->flags & OBJFLAG_ESCSTEP_ZALIGNED) {
							step->frame = escstepy;
							escstepy += 40;
							mtx4LoadYRotation(4.7116389274597f, &sp1a8);
							mtx4ToMtx3(&sp1a8, sp184);
							mtx00016110(sp184, obj->realrot);
						} else {
							step->frame = escstepx;
							escstepx += 40;
							mtx4LoadYRotation(M_BADPI, &sp1a8);
							mtx4ToMtx3(&sp1a8, sp184);
							mtx00016110(sp184, obj->realrot);
						}
					}
					break;
				case OBJTYPE_BASIC:
				case OBJTYPE_ALARM:
				case OBJTYPE_AMMOCRATE:
				case OBJTYPE_DEBRIS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateObject(obj, index);
					}
					break;
				case OBJTYPE_MULTIAMMOCRATE:
					{
						struct multiammocrateobj *crate = (struct multiammocrateobj *)obj;
						s32 ammoqty = 1;
						s32 i;

						if (g_Vars.normmplayerisrunning && var8009cc30 >= 0) {
							struct mpweapon *mpweapon = func0f188e24(var8009cc30);
							ammoqty = mpweapon->weapon1ammoqty;

							if (mpweapon->weapon1ammotypeminusone > 0 && mpweapon->weapon1ammotypeminusone < 20) {
								crate->slots[mpweapon->weapon1ammotypeminusone - 1].quantity = ammoqty;
							}

							if (mpweapon->weapon2ammotypeminusone > 0 && mpweapon->weapon2ammotypeminusone < 20) {
								crate->slots[mpweapon->weapon2ammotypeminusone - 1].quantity = mpweapon->weapon2ammoqty;
							}
						}

						if (ammoqty > 0 && withobjs && (obj->flags2 & diffflag) == 0) {
							for (i = 0; i < 19; i++) {
								if (crate->slots[i].quantity > 0 && crate->slots[i].modelnum != 0xffff) {
									setupLoadModeldef(crate->slots[i].modelnum);
								}
							}

							setupCreateObject(obj, index);
						}
					}
					break;
				case OBJTYPE_HOVERCAR:
					if (withhovercars && withobjs && (obj->flags2 & diffflag) == 0) {
						struct hovercarobj *car = (struct hovercarobj *)obj;
						struct prop *prop;

						setupCreateObject(obj, index);

						prop = obj->prop;

						car->speed = 0;
						car->speedaim = 0;
						car->turnrot60 = 0;
						car->roty = 0;
						car->rotx = 0;
						car->speedtime60 = -1;
						car->aioffset = ailistFindById((s32)car->aioffset);
						car->aireturnlist = NULL;
						car->path = NULL;
						car->nextstep = 0;

						if (obj->flags & OBJFLAG_CHOPPER_INACTIVE) {
							prop->pos.y = cdFindFloorYColourTypeAtPos(&prop->pos, prop->rooms, NULL, 0) + 30;
						}

						prop->forcetick = true;
					}
					break;
				case OBJTYPE_CHOPPER:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct chopperobj *chopper = (struct chopperobj *)obj;

						setupCreateObject(obj, index);

						obj->flags |= OBJFLAG_20000000;
						obj->prop->forcetick = true;

						chopper->turnrot60 = 0;
						chopper->roty = 0;
						chopper->rotx = 0;
						chopper->gunroty = 0;
						chopper->gunrotx = 0;
						chopper->barrelrot = 0;
						chopper->barrelrotspeed = 0;
						chopper->aioffset = ailistFindById((u32)chopper->aioffset);
						chopper->aireturnlist = NULL;
						chopper->path = NULL;
						chopper->nextstep = 0;
						chopper->target = -1;
						chopper->targetvisible = false;
						chopper->attackmode = CHOPPERMODE_PATROL;
						chopper->vz = 0;
						chopper->vy = 0;
						chopper->vx = 0;
						chopper->otz = 0;
						chopper->oty = 0;
						chopper->otx = 0;
						chopper->power = 0;
						chopper->bob = 0;
						chopper->bobstrength = 0.05f;
						chopper->timer60 = 0;
						chopper->patroltimer60 = 0;
						chopper->cw = 0;
						chopper->weaponsarmed = true;
						chopper->fireslotthing = mempAlloc(sizeof(struct fireslotthing), MEMPOOL_STAGE);
						chopper->fireslotthing->beam = mempAlloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
						chopper->fireslotthing->beam->age = -1;
						chopper->fireslotthing->unk08 = -1;
						chopper->fireslotthing->unk00 = 0;
						chopper->fireslotthing->unk01 = 0;
						chopper->fireslotthing->unk0c = 0.85f;
						chopper->fireslotthing->unk10 = 0.2f;
						chopper->fireslotthing->unk14 = 0;
						chopper->dead = false;
					}
					break;
				case OBJTYPE_TAG:
					{
						struct tag *tag = (struct tag *)obj;
						struct defaultobj *taggedobj = setupGetObjByCmdIndex(index + tag->cmdoffset);
						tag->obj = taggedobj;

						if (taggedobj) {
							taggedobj->hidden |= OBJHFLAG_TAGGED;
						}

						tagInsert(tag);
					}
					break;
				case OBJTYPE_RENAMEOBJ:
					{
						struct textoverride *override = (struct textoverride *)obj;
						struct defaultobj *targetobj = setupGetObjByCmdIndex(override->objoffset + index);
						override->obj = targetobj;

						if (targetobj) {
							targetobj->hidden |= OBJHFLAG_HASTEXTOVERRIDE;
						}

						invInsertTextOverride(override);
					}
					break;
				case OBJTYPE_BRIEFING:
					{
						struct briefingobj *briefing = (struct briefingobj *)obj;
						s32 wanttype = BRIEFINGTYPE_TEXT_PA;

						briefingInsert(briefing);

						if (g_Difficulty == DIFF_A) {
							wanttype = BRIEFINGTYPE_TEXT_A;
						}

						if (g_Difficulty == DIFF_SA) {
							wanttype = BRIEFINGTYPE_TEXT_SA;
						}

						if (briefing->type == wanttype) {
							g_Briefing.briefingtextnum = briefing->text;
						}
					}
					break;
				case OBJTYPE_CAMERAPOS:
					{
						struct cameraposobj *camera = (struct cameraposobj *)obj;
						camera->x = *(s32 *)&camera->x / 100.0f;
						camera->y = *(s32 *)&camera->y / 100.0f;
						camera->z = *(s32 *)&camera->z / 100.0f;
						camera->theta = *(s32 *)&camera->theta / 65536.0f;
						camera->verta = *(s32 *)&camera->verta / 65536.0f;
					}
					break;
				case OBJTYPE_BEGINOBJECTIVE:
					{
						struct objective *objective = (struct objective *)obj;

						objectiveInsert(objective);

						if ((u32)objective->index < 7) {
							g_Briefing.objectivenames[objective->index] = objective->text;
							g_Briefing.objectivedifficulties[objective->index] = objective->difficulties;
						}
					}
					break;
				case OBJECTIVETYPE_HOLOGRAPH:
					objectiveAddHolographCriteria((struct criteria_holograph *)obj);
					break;
				case OBJTYPE_PADEFFECT:
					{
						struct padeffectobj *padeffect = (struct padeffectobj *)obj;
						if (g_LastPadEffectIndex == -1) {
							g_PadEffects = padeffect;
						}
						g_LastPadEffectIndex++;
					}
					break;
				case OBJTYPE_MINE:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateMine((struct mineobj *)obj, index);
					}
					break;
				}

				obj = (struct defaultobj *)((u32 *)obj + setupGetCmdLength((u32 *)obj));
				index++;
			}

			index = 0;

			if (g_Vars.normmplayerisrunning && mpHasSimulants()) {
				u32 stack[4];
				s32 i;
				s32 slotsdone[MAX_BOTS];
				s32 chrnum = 0;
				s32 maxsimulants;
				s32 slotnum;

				if (challengeIsFeatureUnlocked(MPFEATURE_8BOTS)) {
					maxsimulants = MAX_BOTS;
				} else {
					maxsimulants = 4;
				}

				for (i = 0; i < MAX_BOTS; i++) {
					slotsdone[i] = false;
				}

				for (i = 0; i < maxsimulants; i++) {
					slotnum = random() % maxsimulants;

					while (slotsdone[slotnum]) {
						slotnum = (slotnum + 1) % maxsimulants;
					}

					if ((g_MpSetup.chrslots & (1 << (slotnum + 4)))
							&& mpIsSimSlotEnabled(slotnum)) {
						botmgrAllocateBot(chrnum, slotnum);
						chrnum++;
					}

					slotsdone[slotnum] = true;
				}
			}

			if (g_Vars.normmplayerisrunning) {
				scenarioInitProps();
			}

			obj = (struct defaultobj *)g_StageSetup.props;

			while (obj->type != OBJTYPE_END) {
				switch (obj->type) {
				case OBJTYPE_BASIC:
				case OBJTYPE_KEY:
				case OBJTYPE_AMMOCRATE:
				case OBJTYPE_WEAPON:
				case OBJTYPE_SINGLEMONITOR:
				case OBJTYPE_DEBRIS:
				case OBJTYPE_MULTIAMMOCRATE:
				case OBJTYPE_SHIELD:
				case OBJTYPE_GLASS:
				case OBJTYPE_TINTEDGLASS:
					if (obj->prop && (obj->flags & OBJFLAG_INSIDEANOTHEROBJ)) {
						s32 offset = obj->pad;
						struct defaultobj *owner = setupGetObjByCmdIndex(index + offset);

						if (owner && owner->prop) {
							obj->hidden |= OBJHFLAG_HASOWNER;
							propReparent(obj->prop, owner->prop);
						}
					}
					break;
				case OBJTYPE_LINKGUNS:
					{
						struct linkgunsobj *link = (struct linkgunsobj *)obj;
						struct weaponobj *gun1 = (struct weaponobj *)setupGetCmdByIndex(link->offset1 + index);
						struct weaponobj *gun2 = (struct weaponobj *)setupGetCmdByIndex(link->offset2 + index);

						if (gun1 && gun2
								&& gun1->base.type == OBJTYPE_WEAPON
								&& gun2->base.type == OBJTYPE_WEAPON) {
							propweaponSetDual(gun1, gun2);
						}
					}
					break;
				case OBJTYPE_LINKLIFTDOOR:
					{
						struct linkliftdoorobj *link = (struct linkliftdoorobj *)obj;
						s32 dooroffset = (s32)link->door;
						s32 liftoffset = (s32)link->lift;
						struct defaultobj *door = setupGetObjByCmdIndex(index + dooroffset);
						struct defaultobj *lift = setupGetObjByCmdIndex(index + liftoffset);

						if (door && door->prop && lift && lift->prop) {
							link->door = door->prop;
							link->lift = lift->prop;

							setupCreateLiftDoor(link);

							door->hidden |= OBJHFLAG_LIFTDOOR;
						}
					}
					break;
				case OBJTYPE_CONDITIONALSCENERY:
					{
						struct linksceneryobj *link = (struct linksceneryobj *)obj;
						s32 triggeroffset = (s32)link->trigger;
						s32 unexpoffset = (s32)link->unexp;
						s32 expoffset = (s32)link->exp;
						struct defaultobj *trigger = setupGetObjByCmdIndex(index + triggeroffset);
						struct defaultobj *unexp = NULL;
						struct defaultobj *exp = NULL;

						if (unexpoffset) {
							unexp = setupGetObjByCmdIndex(index + unexpoffset);
						}

						if (expoffset) {
							exp = setupGetObjByCmdIndex(index + expoffset);
						}

						if (trigger && trigger->prop
								&& (unexpoffset == 0 || (unexp && unexp->prop))
								&& (expoffset == 0 || (exp && exp->prop))) {
							link->trigger = trigger;
							link->unexp = unexp;
							link->exp = exp;

							setupCreateConditionalScenery(link);

							trigger->hidden |= OBJHFLAG_CONDITIONALSCENERY;

							if (unexpoffset) {
								unexp->hidden |= OBJHFLAG_CONDITIONALSCENERY;
							}

							if (expoffset) {
								exp->hidden |= OBJHFLAG_CONDITIONALSCENERY;
								exp->flags2 |= OBJFLAG2_INVISIBLE;
							}

							if (trigger->hidden & OBJHFLAG_02000000) {
								objSetBlockedPathUnblocked(trigger, false);
							}
						}
					}
					break;
				case OBJTYPE_BLOCKEDPATH:
					{
						struct blockedpathobj *blockedpath = (struct blockedpathobj *)obj;
						s32 objoffset = (s32)blockedpath->blocker;
						struct defaultobj *blocker = setupGetObjByCmdIndex(index + objoffset);

						if (blocker && blocker->prop) {
							blockedpath->blocker = blocker;

							setupCreateBlockedPath(blockedpath);

							blocker->hidden |= OBJHFLAG_02000000;

							if (blocker->hidden & OBJHFLAG_CONDITIONALSCENERY) {
								objSetBlockedPathUnblocked(blocker, false);
							}
						}
					}
					break;
				}

				obj = (struct defaultobj *)((u32 *)obj + setupGetCmdLength((u32 *)obj));
				index++;
			}
		}
	} else {
		chrmgrConfigure(0);
	}

	stageAllocateBgChrs();
}
