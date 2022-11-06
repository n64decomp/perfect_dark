#include <ultra64.h>
#include "constants.h"
#include "game/game_00b820.h"
#include "game/setup.h"
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
#include "lib/args.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "lib/path.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "lib/vars.h"
#include "data.h"
#include "types.h"

s32 var8009cc30;
u32 var8009cc34;
u32 var8009cc38;
u32 var8009cc3c;

s32 g_NumBots = 0;

u32 var80061bdc = 0x00000000;
f32 g_DoorScale = 1;
u32 var80061be4 = 0x00000000;
u32 var80061be8 = 0x00000000;
u32 var80061bec = 0x00000000;

void propsReset(bool withlaptops)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Lifts); i++) {
		g_Lifts[i] = NULL;
	}

	g_MaxWeaponSlots = 50;
	g_MaxAmmoCrates = 20;
	g_MaxProjectiles = 20;
	g_MaxEmbedments = 40;

	if (g_Vars.stagenum >= STAGE_TITLE) {
		g_MaxWeaponSlots = 0;
		g_MaxAmmoCrates = 0;
		g_MaxProjectiles = 0;
		g_MaxEmbedments = 0;
	}

	setupResetProxyMines();

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

	g_EmbedProp = NULL;
	g_EmbedHitPart = -1;
	g_AutogunAccuracyScale = 1;
	g_AutogunDamageTxScale = 1;
	g_AutogunDamageRxScale = 1;
	g_AmmoQuantityScale = 1;

	if (withlaptops) {
		g_MaxThrownLaptops = PLAYERCOUNT() + g_NumBots;
		g_ThrownLaptops = mempAlloc(ALIGN16(g_MaxThrownLaptops * sizeof(struct autogunobj)), MEMPOOL_STAGE);
		g_ThrownLaptopBeams = mempAlloc(ALIGN16(g_MaxThrownLaptops * sizeof(struct beam)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxThrownLaptops; i++) {
			g_ThrownLaptops[i].base.prop = NULL;
		}
	} else {
		g_MaxThrownLaptops = 0;
		g_ThrownLaptops = NULL;
		g_ThrownLaptopBeams = NULL;
	}
}

void setupCreateLiftDoor(struct linkliftdoorobj *link)
{
	link->next = g_LiftDoors;
	g_LiftDoors = link;
}

void setupResetProxyMines(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Proxies); i++) {
		g_Proxies[i] = NULL;
	}
}

s32 setupCountCommandType(u32 type)
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
	struct pad pad;
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

		modelSetScale(obj->model, obj->model->scale * scale);
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

			modelSetScale(obj->model, obj->model->scale * scale);
			propReparent(prop, chr->prop);
		}
	} else {
		if (obj->pad < 0) {
			if (obj->type == OBJTYPE_WEAPON) {
				func0f08ae0c((struct weaponobj *)obj, g_ModelStates[modelnum].filedata);
			} else {
				objInitWithModelDef(obj, g_ModelStates[modelnum].filedata);
			}

			modelSetScale(obj->model, obj->model->scale * scale);
			return;
		}

		padUnpack(obj->pad, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_BBOX | PADFIELD_ROOM, &pad);

		if (pad.room > 0) {
			mtx00016d58(&mtx, 0, 0, 0, -pad.look.x, -pad.look.y, -pad.look.z, pad.up.x, pad.up.y, pad.up.z);

			pos.x = pad.pos.x;
			pos.y = pad.pos.y;
			pos.z = pad.pos.z;

			rooms[0] = pad.room;
			rooms[1] = -1;

			if (!padHasBboxData(obj->pad)) {
				if (obj->flags & OBJFLAG_00000002) {
					centre.x = pad.pos.x;
					centre.y = pad.pos.y;
					centre.z = pad.pos.z;
				} else {
					centre.x = pad.pos.x;
					centre.y = pad.pos.y;
					centre.z = pad.pos.z;
				}
			} else {
				padGetCentre(obj->pad, &centre);
				centre.x += (pad.bbox.ymin - pad.bbox.ymax) * 0.5f * pad.up.x;
				centre.y += (pad.bbox.ymin - pad.bbox.ymax) * 0.5f * pad.up.y;
				centre.z += (pad.bbox.ymin - pad.bbox.ymax) * 0.5f * pad.up.z;
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
								xscale = (pad.bbox.xmax - pad.bbox.xmin) / ((bbox->xmax - bbox->xmin) * obj->model->scale);
							} else {
								xscale = (pad.bbox.xmax - pad.bbox.xmin) / ((bbox->xmax - bbox->xmin) * obj->model->scale);
							}
						}
					}

					if (obj->flags & flag40) {
						if (bbox->ymin < bbox->ymax) {
							if (obj->flags & OBJFLAG_00000002) {
								zscale = (pad.bbox.zmax - pad.bbox.zmin) / ((bbox->ymax - bbox->ymin) * obj->model->scale);
							} else {
								yscale = (pad.bbox.ymax - pad.bbox.ymin) / ((bbox->ymax - bbox->ymin) * obj->model->scale);
							}
						}
					}

					if (obj->flags & OBJFLAG_00000080) {
						if (bbox->zmin < bbox->zmax) {
							if (obj->flags & OBJFLAG_00000002) {
								yscale = (pad.bbox.ymax - pad.bbox.ymin) / ((bbox->zmax - bbox->zmin) * obj->model->scale);
							} else {
								zscale = (pad.bbox.zmax - pad.bbox.zmin) / ((bbox->zmax - bbox->zmin) * obj->model->scale);
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

					modelSetScale(obj->model, obj->model->scale * maxscale);
				}
			}

			modelSetScale(obj->model, obj->model->scale * scale);
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
			modelmgrLoadProjectileModeldefs(weapon->weaponnum);
			func0f08b25c(weapon, chr);
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

s32 setupGetPortalByPad(s32 padnum)
{
	f32 mult;
	struct coord centre;
	struct coord coord;
	u32 stack;
	struct pad pad;

	padGetCentre(padnum, &centre);
	padUnpack(padnum, PADFIELD_BBOX | PADFIELD_UP, &pad);

	mult = (pad.bbox.ymax - pad.bbox.ymin) * 0.5f + 10;

	coord.x = pad.up.x * mult + centre.x;
	coord.y = pad.up.y * mult + centre.y;
	coord.z = pad.up.z * mult + centre.z;

	centre.x = centre.x - pad.up.x * mult;
	centre.y = centre.y - pad.up.y * mult;
	centre.z = centre.z - pad.up.z * mult;

	return bg0f164e8c(&centre, &coord);
}

s32 setupGetPortalByDoorPad(s32 padnum)
{
	f32 mult;
	struct coord centre;
	struct coord coord;
	u32 stack;
	struct pad pad;

	padGetCentre(padnum, &centre);
	padUnpack(padnum, PADFIELD_BBOX | PADFIELD_NORMAL, &pad);

	mult = (pad.bbox.xmax - pad.bbox.xmin) * 0.5f + 10;

	coord.x = pad.normal.x * mult + centre.x;
	coord.y = pad.normal.y * mult + centre.y;
	coord.z = pad.normal.z * mult + centre.z;

	centre.x = centre.x - pad.normal.x * mult;
	centre.y = centre.y - pad.normal.y * mult;
	centre.z = centre.z - pad.normal.z * mult;

	return bg0f164e8c(&centre, &coord);
}

void setupCreateDoor(struct doorobj *door, s32 cmdindex)
{
	f32 scale;
	s32 modelnum = door->base.modelnum;
	s32 portalnum = -1;
	struct pad pad;

	setupLoadModeldef(modelnum);

	if (door->doorflags & DOORFLAG_ROTATEDPAD) {
		padRotateForDoor(door->base.pad);
	}

	if (door->base.flags & OBJFLAG_DOOR_HASPORTAL) {
		portalnum = setupGetPortalByDoorPad(door->base.pad);
	}

	padUnpack(door->base.pad, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_NORMAL | PADFIELD_BBOX | PADFIELD_ROOM, &pad);

	if (g_DoorScale != 1) {
		pad.bbox.xmin *= g_DoorScale;
		pad.bbox.xmax *= g_DoorScale;

		// If the door has a portal, adjust the pad's bbox to match the portal's dimensions
		if (portalnum >= 0) {
			struct var800a4ccc *ptr = &var800a4ccc[portalnum];
			f32 f0 = pad.pos.f[0] * ptr->coord.f[0] + pad.pos.f[1] * ptr->coord.f[1] + pad.pos.f[2] * ptr->coord.f[2];
			f32 min = ptr->min;
			struct coord sp150;
			f0 = (f0 - min) * (g_DoorScale - 1);

			sp150.x = ptr->coord.x * f0;
			sp150.y = ptr->coord.y * f0;
			sp150.z = ptr->coord.z * f0;

			f0 = sp150.f[0] * pad.normal.f[0] + sp150.f[1] * pad.normal.f[1] + sp150.f[2] * pad.normal.f[2];
			pad.bbox.xmin += f0;
			pad.bbox.xmax += f0;

			f0 = sp150.f[0] * pad.up.f[0] + sp150.f[1] * pad.up.f[1] + sp150.f[2] * pad.up.f[2];
			pad.bbox.ymin += f0;
			pad.bbox.ymax += f0;

			f0 = sp150.f[0] * pad.look.f[0] + sp150.f[1] * pad.look.f[1] + sp150.f[2] * pad.look.f[2];
			pad.bbox.zmin += f0;
			pad.bbox.zmax += f0;
		}

		// Write the modified bbox into the pad file data
		padCopyBboxFromPad(door->base.pad, &pad);
	}

	if (pad.room > 0) {
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
				-pad.look.x, -pad.look.y, -pad.look.z,
				pad.up.x, pad.up.y, pad.up.z);
		mtx4LoadXRotation(1.5705462694168f, &finalmtx);
		mtx4LoadZRotation(1.5705462694168f, &zrotmtx);
		mtx4MultMtx4InPlace(&zrotmtx, &finalmtx);
		mtx4MultMtx4InPlace(&sp110, &finalmtx);

		padGetCentre(door->base.pad, &centre);

		xscale = (pad.bbox.ymax - pad.bbox.ymin) / (bbox->xmax - bbox->xmin);
		yscale = (pad.bbox.zmax - pad.bbox.zmin) / (bbox->ymax - bbox->ymin);
		zscale = (pad.bbox.xmax - pad.bbox.xmin) / (bbox->zmax - bbox->zmin);

		if (xscale <= 0.000001f || yscale <= 0.000001f || zscale <= 0.000001f) {
			xscale = yscale = zscale = 1;
		}

		mtx00015e24(xscale, &finalmtx);
		mtx00015e80(yscale, &finalmtx);
		mtx00015edc(zscale, &finalmtx);

		pos.x = pad.pos.x;
		pos.y = pad.pos.y;
		pos.z = pad.pos.z;

		rooms[0] = pad.room;
		rooms[1] = -1;

		if (door->doortype == DOORTYPE_VERTICAL || door->doortype == DOORTYPE_FALLAWAY) {
			sp54.x = pad.look.f[0] * (pad.bbox.zmax - pad.bbox.zmin);
			sp54.y = pad.look.f[1] * (pad.bbox.zmax - pad.bbox.zmin);
			sp54.z = pad.look.f[2] * (pad.bbox.zmax - pad.bbox.zmin);
		} else {
			sp54.x = pad.up.f[0] * (pad.bbox.ymin - pad.bbox.ymax);
			sp54.y = pad.up.f[1] * (pad.bbox.ymin - pad.bbox.ymax);
			sp54.z = pad.up.f[2] * (pad.bbox.ymin - pad.bbox.ymax);
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

			modelSetScale(door->base.model, door->base.model->scale * scale);
		}

		propActivate(prop);
		propEnable(prop);
	} else {
		door->base.prop = NULL;
	}
}

void setupCreateHov(struct defaultobj *obj, struct hov *hov)
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

void setupLoadFiles(s32 stagenum)
{
	s32 i;
	s32 j;
	s32 numchrs = 0;
	s32 numobjs = 0;
	s32 extra;
	struct stagesetup *setup;
	u16 filenum;
	bool modified;

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

		g_LoadType = LOADTYPE_SETUP;

		g_GeCreditsData = (u8 *)fileLoadToNew(filenum, FILELOADMETHOD_DEFAULT);
		setup = (struct stagesetup *)g_GeCreditsData;
		langLoad(langGetLangBankIndexFromStagenum(stagenum));

		g_StageSetup.intro = (s32 *)((u32)setup + (u32)setup->intro);
		g_StageSetup.props = (u32 *)((u32)setup + (u32)setup->props);
		g_StageSetup.paths = (struct path *)((u32)setup + (u32)setup->paths);

		g_LoadType = LOADTYPE_PADS;

		g_StageSetup.padfiledata = fileLoadToNew(g_Stages[g_StageIndex].padsfileid, FILELOADMETHOD_DEFAULT);

		g_StageSetup.waypoints = NULL;
		g_StageSetup.waygroups = NULL;
		g_StageSetup.cover = NULL;

		// Convert path pad pointers from file-local to proper pointers
		// and calculate the path lengths
		if (g_StageSetup.paths) {
			for (i = 0; g_StageSetup.paths[i].pads != NULL; i++) {
				g_StageSetup.paths[i].pads = (s32 *)((u32)g_StageSetup.paths[i].pads + (u32)setup);

				for (j = 0; g_StageSetup.paths[i].pads[j] >= 0; j++);

				g_StageSetup.paths[i].len = j;
			}
		}

		// Count the number of objects so enough model slots can be allocated
		numchrs += setupCountCommandType(OBJTYPE_CHR);

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
		numobjs += setupCountCommandType(OBJTYPE_HOVERPROP);
		numobjs += setupCountCommandType(OBJTYPE_FAN);
		numobjs += setupCountCommandType(OBJTYPE_HOVERCAR);
		numobjs += setupCountCommandType(OBJTYPE_CHOPPER);
		numobjs += setupCountCommandType(OBJTYPE_HELI);
		numobjs += setupCountCommandType(OBJTYPE_ESCASTEP);

		if (g_Vars.normmplayerisrunning) {
			numobjs += scenarioNumProps();
		}
	} else {
		// cover isn't set to NULL here... I guess it's not important
		g_StageSetup.waypoints = NULL;
		g_StageSetup.waygroups = NULL;
		g_StageSetup.intro = 0;
		g_StageSetup.props = 0;
		g_StageSetup.paths = NULL;
		g_StageSetup.ailists = NULL;
		g_StageSetup.padfiledata = NULL;
	}

	g_ModelNumObjs = numobjs;
	g_Vars.maxprops = numobjs + MAX_DROPPED_ITEMS;
}

s32 setupGetNumRequestedBots(void)
{
	s32 i;
	s32 numbots = 0;

	if (g_Vars.normmplayerisrunning && mpHasSimulants()) {
		for (i = 0; i < MAX_BOTS; i++) {
			if ((g_MpSetup.chrslots & (1 << (i + 4))) && mpIsSimSlotEnabled(i)) {
				numbots++;
			}
		}
	}

	return numbots;
}

s32 setupCalculateMaxBots(s32 numrequested, bool haslaptops)
{
	return numrequested;
}

void setupAllocateEverything(void)
{
	s32 numbotsrequested;
	bool haslaptops = false;
	s32 i;

	// Count how many bots were requested
	numbotsrequested = setupGetNumRequestedBots();

	// Check if we have laptop guns in our setup
	haslaptops = false;

	for (i = 0; i < 6; i++) {
		if (g_MpSetup.weapons[i] == MPWEAPON_LAPTOPGUN) {
			haslaptops = true;
			break;
		}
	}

	// Figure out how many we can allocate based on available memory
	g_NumBots = setupCalculateMaxBots(numbotsrequested, haslaptops);

	// Allocate everything
	modelmgrAllocateSlots(g_ModelNumObjs, PLAYERCOUNT() + g_NumBots);

	g_Vars.maxprops += PLAYERCOUNT() + g_NumBots;

	varsReset();
	propsReset(haslaptops);

	chrmgrReset();
	chrmgrConfigure(g_NumBots);

	botmgrRemoveAll();

	if (g_Vars.normmplayerisrunning && mpHasSimulants()) {
		s32 chrnum = 0;

		for (i = 0; i < MAX_BOTS; i++) {
			if ((g_MpSetup.chrslots & (1 << (i + 4))) && mpIsSimSlotEnabled(i)) {
				botmgrAllocateBot(chrnum, i);
				chrnum++;
			}
		}
	}

	if (g_Vars.normmplayerisrunning) {
		scenarioInitProps();
	}
}

void setupCreateProps(s32 stagenum)
{
	s32 withchrs = !argFindByPrefix(1, "-nochr") && !argFindByPrefix(1, "-noprop");
	s32 withobjs = !argFindByPrefix(1, "-noobj") && !argFindByPrefix(1, "-noprop");
	s32 withhovercars;
	s32 escstepx;
	s32 escstepy;
	struct defaultobj *obj;
	s32 i;
	s32 j;
	s32 liftnum = 0;

	withhovercars = true;

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

		for (j = 0; j < PLAYERCOUNT(); j++) {
			setCurrentPlayerNum(j);
			invInit();
		}

		if (g_StageSetup.props) {
			u32 diffflag = 0;
			s32 index;

			diffflag |= 1 << (lvGetDifficulty() + 4);

			if (g_Vars.mplayerisrunning) {
				if (PLAYERCOUNT() == 2) {
					diffflag |= OBJFLAG2_EXCLUDE_2P;
				} else if (PLAYERCOUNT() == 3) {
					diffflag |= OBJFLAG2_EXCLUDE_3P;
				} else if (PLAYERCOUNT() == 4) {
					diffflag |= OBJFLAG2_EXCLUDE_4P;
				}
			}

			setupAllocateEverything();

			index = 0;

			obj = (struct defaultobj *)g_StageSetup.props;

			while (obj->type != OBJTYPE_END) {
				switch (obj->type) {
				case OBJTYPE_DOOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateDoor((struct doorobj *)obj, index);
					}
					break;
				case OBJTYPE_WEAPON:
					if (withchrs && (obj->flags2 & diffflag) == 0) {
						setupPlaceWeapon((struct weaponobj *)obj, index);
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
							lift->prevpos.x = prop->pos.x;
							lift->prevpos.y = prop->pos.y;
							lift->prevpos.z = prop->pos.z;

							liftUpdateTiles(lift, true);
						}

						liftnum++;
						liftActivate(prop, liftnum);
					}
					break;
				case OBJTYPE_HOVERPROP:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct hoverpropobj *hoverprop = (struct hoverpropobj *)obj;

						setupCreateObject(obj, index);
						setupCreateHov(obj, &hoverprop->hov);
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
				case OBJTYPE_BASIC:
				case OBJTYPE_AMMOCRATE:
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
				}

				obj = (struct defaultobj *)((u32 *)obj + setupGetCmdLength((u32 *)obj));
				index++;
			}

			index = 0;

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
				case OBJTYPE_GASBOTTLE:
				case OBJTYPE_29:
				case OBJTYPE_GLASS:
				case OBJTYPE_SAFE:
				case OBJTYPE_TINTEDGLASS:
					if (obj->prop && (obj->flags & OBJFLAG_INSIDEANOTHEROBJ)) {
						s32 offset = obj->pad;
						struct defaultobj *owner = setupGetObjByCmdIndex(index + offset);

						if (owner && owner->prop) {
							obj->hidden |= OBJHFLAG_HASOWNER;
							modelSetScale(obj->model, obj->model->scale);
							propReparent(obj->prop, owner->prop);
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
				}
				obj = (struct defaultobj *)((u32 *)obj + setupGetCmdLength((u32 *)obj));
				index++;
			}
		}
	} else {
		setupAllocateEverything();
	}
}
