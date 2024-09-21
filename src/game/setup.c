#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chraireset.h"
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
#include "lib/args.h"
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

s32 g_SetupCurMpLocation;

void setup_reset_tvscreens(void);
void setup_reset_proxy_mines(void);

void props_reset(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Lifts); i++) {
		g_Lifts[i] = NULL;
	}

	g_MaxWeaponSlots = 50;
	g_MaxHatSlots = 10;
	g_MaxAmmoCrates = 20;
	g_MaxDebrisSlots = 15;
	g_MaxProjectiles = IS4MB() ? 20 : 100;
	g_MaxEmbedments = IS4MB() ? 40 : 80;

	if (g_Vars.stagenum >= STAGE_TITLE) {
		g_MaxWeaponSlots = 0;
		g_MaxHatSlots = 0;
		g_MaxAmmoCrates = 0;
		g_MaxDebrisSlots = 0;
		g_MaxProjectiles = 0;
		g_MaxEmbedments = 0;
	}

	setup_reset_tvscreens();
	setup_reset_proxy_mines();

	g_AlarmTimer = 0;
	g_AlarmAudioHandle = NULL;
	g_AlarmSpeakerWeight = 64;

	g_GasReleaseTimer240 = 0;
	g_GasReleasing = false;
	g_GasPos.x = 0;
	g_GasPos.y = 0;
	g_GasPos.z = 0;
	g_GasLastCough60 = 0;
	g_GasSoundTimer240 = 0;
	g_GasAudioHandle = NULL;

	g_CountdownTimerOff = COUNTDOWNTIMERREASON_AI;
	g_CountdownTimerRunning = false;
	g_CountdownTimerValue60 = 0;

	g_PlayersDetonatingMines = 0;
	g_TintedGlassEnabled = false;

	if (g_MaxWeaponSlots == 0) {
		g_WeaponSlots = NULL;
	} else {
		g_WeaponSlots = memp_alloc(ALIGN16(g_MaxWeaponSlots * sizeof(struct weaponobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxWeaponSlots; i++) {
			g_WeaponSlots[i].base.prop = NULL;
		}

		g_NextWeaponSlot = 0;
	}

	if (g_MaxHatSlots == 0) {
		g_HatSlots = NULL;
	} else {
		g_HatSlots = memp_alloc(ALIGN16(g_MaxHatSlots * sizeof(struct hatobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxHatSlots; i++) {
			g_HatSlots[i].base.prop = NULL;
		}

		g_NextHatSlot = 0;
	}

	if (g_MaxAmmoCrates == 0) {
		g_AmmoCrates = NULL;
	} else {
		g_AmmoCrates = memp_alloc(ALIGN16(g_MaxAmmoCrates * sizeof(struct ammocrateobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxAmmoCrates; i++) {
			g_AmmoCrates[i].base.prop = NULL;
		}
	}

	if (g_MaxDebrisSlots == 0) {
		g_DebrisSlots = NULL;
	} else {
		g_DebrisSlots = memp_alloc(ALIGN16(g_MaxDebrisSlots * sizeof(struct defaultobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxDebrisSlots; i++) {
			g_DebrisSlots[i].prop = NULL;
		}
	}

	if (g_MaxProjectiles == 0) {
		g_Projectiles = NULL;
	} else {
		g_Projectiles = memp_alloc(ALIGN16(g_MaxProjectiles * sizeof(struct projectile)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxProjectiles; i++) {
			g_Projectiles[i].flags = PROJECTILEFLAG_FREE;
		}
	}

	if (g_MaxEmbedments == 0) {
		g_Embedments = NULL;
	} else {
		g_Embedments = memp_alloc(ALIGN16(g_MaxEmbedments * sizeof(struct embedment)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxEmbedments; i++) {
			g_Embedments[i].flags = EMBEDMENTFLAG_FREE;
		}
	}

	g_LiftDoors = NULL;
	g_PadlockedDoors = NULL;
	g_SafeItems = NULL;
	g_LinkedScenery = NULL;
	g_BlockedPaths = NULL;

	g_EmbedProp = NULL;
	g_EmbedHitPart = -1;
	g_CctvWaitScale = 1;
	g_CctvDamageRxScale = 1;
	g_AutogunAccuracyScale = 1;
	g_AutogunDamageTxScale = 1;
	g_AutogunDamageRxScale = 1;
	g_AmmoQuantityScale = 1;

	g_MaxThrownLaptops = g_Vars.normmplayerisrunning ? 12 : PLAYERCOUNT();

	g_ThrownLaptops = memp_alloc(ALIGN16(g_MaxThrownLaptops * sizeof(struct autogunobj)), MEMPOOL_STAGE);
	g_ThrownLaptopBeams = memp_alloc(ALIGN16(g_MaxThrownLaptops * sizeof(struct beam)), MEMPOOL_STAGE);

	for (i = 0; i < g_MaxThrownLaptops; i++) {
		g_ThrownLaptops[i].base.prop = NULL;
	}
}

void setup_create_lift_door(struct linkliftdoorobj *link)
{
	link->next = g_LiftDoors;
	g_LiftDoors = link;
}

void setup_create_padlocked_door(struct padlockeddoorobj *link)
{
	link->next = g_PadlockedDoors;
	g_PadlockedDoors = link;
}

void setup_create_safe_item(struct safeitemobj *link)
{
	link->next = g_SafeItems;
	g_SafeItems = link;
}

void setup_create_conditional_scenery(struct linksceneryobj *link)
{
	link->next = g_LinkedScenery;
	g_LinkedScenery = link;
}

void setup_create_blocked_path(struct blockedpathobj *blockedpath)
{
	blockedpath->next = g_BlockedPaths;
	g_BlockedPaths = blockedpath;
}

#define MKTVSCREEN(cmdlist) { \
		cmdlist, /* cmdlist    */ \
		0,       /* offset     */ \
		0xffff,  /* pause60    */ \
		0,       /* tconfig    */ \
		0,       /* rot        */ \
		1,       /* xscale     */ \
		0,       /* xscalefrac */ \
		0,       /* xscaleinc  */ \
		1,       /* xscaleold  */ \
		1,       /* xscalenew  */ \
		1,       /* yscale     */ \
		0,       /* yscalefrac */ \
		0,       /* yscaleinc  */ \
		1,       /* yscaleold  */ \
		1,       /* yscalenew  */ \
		0.5,     /* xmid       */ \
		0,       /* xmidfrac   */ \
		0,       /* xmidinc    */ \
		0.5,     /* xmidold    */ \
		0.5,     /* xmidnew    */ \
		0.5,     /* ymid       */ \
		0,       /* ymidfrac   */ \
		0,       /* ymidinc    */ \
		0.5,     /* ymidold    */ \
		0.5,     /* ymidnew    */ \
		0xff,    /* red        */ \
		0xff,    /* redold     */ \
		0xff,    /* rednew     */ \
		0xff,    /* green      */ \
		0xff,    /* greenold   */ \
		0xff,    /* greennew   */ \
		0xff,    /* blue       */ \
		0xff,    /* blueold    */ \
		0xff,    /* bluenew    */ \
		0xff,    /* alpha      */ \
		0xff,    /* alphaold   */ \
		0xff,    /* alphanew   */ \
		1,       /* colfrac    */ \
		0,       /* colinc     */ \
	}

void setup_reset_tvscreens(void)
{
	{ struct tvscreen tmp = MKTVSCREEN(g_TvCmdlistDefault); g_TvCmdlistDefaultCopy = tmp; }
	{ struct tvscreen tmp = MKTVSCREEN(g_TvCmdlistBondZoom); g_TvCmdlistBondZoomCopy = tmp; }
	{ struct tvscreen tmp = MKTVSCREEN(g_TvCmdlistBondPan); g_TvCmdlistBondPanCopy = tmp; }
}

u32 var80061bdc = 0;

void setup_reset_proxy_mines(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Proxies); i++) {
		g_Proxies[i] = NULL;
	}
}

s32 setup_count_command_type(u32 type)
{
	struct defaultobj *obj = (struct defaultobj *)g_StageSetup.props;
	s32 count = 0;

	if (obj) {
		while (obj->type != OBJTYPE_END) {
			if (obj->type == (u8)type) {
				count++;
			}

			obj = (struct defaultobj *)((u32 *)obj + setup_get_cmd_length((u32 *)obj));
		}
	}

	return count;
}

void setup_create_object(struct defaultobj *obj, s32 cmdindex)
{
	f32 f0;
	s32 modelnum;
	struct pad pad;
	Mtxf mtx;
	struct coord centre;
	f32 scale;
	struct coord pos;
	RoomNum rooms[8];
	struct prop *prop2;
	u32 flag40;
	u32 stack;
	struct chrdata *chr;
	struct prop *prop;

	modelnum = obj->modelnum;
	setup_load_modeldef(modelnum);
	scale = obj->extrascale * (1.0f / 256.0f);

	if (g_Vars.normmplayerisrunning || g_Vars.lvmpbotlevel) {
		obj->hidden2 |= OBJH2FLAG_CANREGEN;
	}

	if (obj->flags & OBJFLAG_INSIDEANOTHEROBJ) {
		if (obj->type == OBJTYPE_WEAPON) {
			weapon_init_with_modeldef((struct weaponobj *)obj, g_ModelStates[modelnum].modeldef);
		} else {
			obj_init_with_modeldef(obj, g_ModelStates[modelnum].modeldef);
		}

		model_set_scale(obj->model, obj->model->scale * scale);
		return;
	}

	if (obj->flags & OBJFLAG_ASSIGNEDTOCHR) {
		chr = chr_find_by_literal_id(obj->pad);

		if (chr && chr->prop && chr->model) {
			if (obj->type == OBJTYPE_WEAPON) {
				prop = weapon_init_with_modeldef((struct weaponobj *)obj, g_ModelStates[modelnum].modeldef);
			} else {
				prop = obj_init_with_modeldef(obj, g_ModelStates[modelnum].modeldef);
			}

			model_set_scale(obj->model, obj->model->scale * scale);
			prop_reparent(prop, chr->prop);
		}
	} else {
		if (obj->pad < 0) {
			if (obj->type == OBJTYPE_WEAPON) {
				weapon_init_with_modeldef((struct weaponobj *)obj, g_ModelStates[modelnum].modeldef);
			} else {
				obj_init_with_modeldef(obj, g_ModelStates[modelnum].modeldef);
			}

			model_set_scale(obj->model, obj->model->scale * scale);
			return;
		}

		pad_unpack(obj->pad, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_BBOX | PADFIELD_ROOM, &pad);

		if (pad.room > 0) {
			mtx00016d58(&mtx, 0, 0, 0, -pad.look.x, -pad.look.y, -pad.look.z, pad.up.x, pad.up.y, pad.up.z);

			pos.x = pad.pos.x;
			pos.y = pad.pos.y;
			pos.z = pad.pos.z;

			rooms[0] = pad.room;
			rooms[1] = -1;

			if (!pad_has_bbox_data(obj->pad)) {
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
				pad_get_centre(obj->pad, &centre);
				centre.x += (pad.bbox.ymin - pad.bbox.ymax) * 0.5f * pad.up.x;
				centre.y += (pad.bbox.ymin - pad.bbox.ymax) * 0.5f * pad.up.y;
				centre.z += (pad.bbox.ymin - pad.bbox.ymax) * 0.5f * pad.up.z;
			}

			if (obj->type == OBJTYPE_WEAPON) {
				prop2 = weapon_init_with_modeldef((struct weaponobj *)obj, g_ModelStates[modelnum].modeldef);
			} else {
				prop2 = obj_init_with_auto_model(obj);
			}

			if (pad_has_bbox_data(obj->pad)) {
				struct modelrodata_bbox *bbox = obj_find_bbox_rodata(obj);

				if (bbox != NULL) {
					f32 xscale = 1.0f;
					f32 yscale = 1.0f;
					f32 zscale = 1.0f;
					f32 minscale;
					f32 maxscale;

					flag40 = OBJFLAG_YTOPADBOUNDS;

					if (obj->flags & OBJFLAG_XTOPADBOUNDS) {
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

					if (obj->flags & OBJFLAG_ZTOPADBOUNDS) {
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

					if ((obj->flags & OBJFLAG_XTOPADBOUNDS) == 0) {
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

					if ((obj->flags & OBJFLAG_ZTOPADBOUNDS) == 0) {
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

					model_set_scale(obj->model, obj->model->scale * maxscale);
				}
			}

			model_set_scale(obj->model, obj->model->scale * scale);
			mtx00015f04(obj->model->scale, &mtx);

			if (obj->flags2 & OBJFLAG2_DONTPAUSE) {
				prop2->flags |= PROPFLAG_DONTPAUSE;
			}

			if (obj->flags & OBJFLAG_00000002) {
				func0f06ab60(obj, &pos, &mtx, rooms, &centre);
			} else {
				func0f06a730(obj, &pos, &mtx, rooms, &centre);
			}

			if (obj->hidden & OBJHFLAG_00008000) {
				prop_activate_this_frame(prop2);
			} else {
				prop_activate(prop2);
			}

			prop_enable(prop2);
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
void setup_place_weapon(struct weaponobj *weapon, s32 cmdindex)
{
	if (weapon->base.flags & OBJFLAG_ASSIGNEDTOCHR) {
		u32 stack[2];
		struct chrdata *chr = chr_find_by_literal_id(weapon->base.pad);

		if (chr && chr->prop && chr->model) {
			if (cheat_is_active(CHEAT_MARQUIS)) {
				// NTSC 1.0 and newer simplifies the Marquis logic
#if VERSION >= VERSION_NTSC_1_0
				weapon->base.flags &= ~OBJFLAG_DEACTIVATED;
				weapon->base.flags |= OBJFLAG_WEAPON_AICANNOTUSE;
				modelmgr_load_projectile_modeldefs(weapon->weaponnum);
				func0f08b25c(weapon, chr);
#else
				if (g_Vars.stagenum == STAGE_INVESTIGATION
						&& lv_get_difficulty() == DIFF_PA
						&& weapon->weaponnum == WEAPON_K7AVENGER) {
					modelmgr_load_projectile_modeldefs(weapon->weaponnum);
					func0f08b25c(weapon, chr);
				} else if (g_Vars.stagenum == STAGE_ATTACKSHIP) {
					weapon->base.flags &= ~OBJFLAG_DEACTIVATED;
					weapon->base.flags |= OBJFLAG_WEAPON_AICANNOTUSE;
					modelmgr_load_projectile_modeldefs(weapon->weaponnum);
					func0f08b25c(weapon, chr);
				} else {
					weapon->weaponnum = WEAPON_NONE;
				}
#endif
			} else {
				if (cheat_is_active(CHEAT_ENEMYROCKETS)) {
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
						if (g_Vars.stagenum != STAGE_INVESTIGATION || lv_get_difficulty() != DIFF_PA) {
							weapon->weaponnum = WEAPON_ROCKETLAUNCHER;
							weapon->base.modelnum = MODEL_CHRDYROCKET;
							weapon->base.extrascale = 256;
						}
						break;
					}
				}

				modelmgr_load_projectile_modeldefs(weapon->weaponnum);
				func0f08b25c(weapon, chr);
			}
		}
	} else {
		bool createweapon = true;

		if (g_Vars.normmplayerisrunning || g_Vars.lvmpbotlevel) {
			struct mpweapon *mpweapon;
			s32 locationindex;

			g_SetupCurMpLocation = -1;

			switch (weapon->weaponnum) {
			case WEAPON_MPLOCATION00:
			case WEAPON_MPLOCATION01:
			case WEAPON_MPLOCATION02:
			case WEAPON_MPLOCATION03:
			case WEAPON_MPLOCATION04:
			case WEAPON_MPLOCATION05:
			case WEAPON_MPLOCATION06:
			case WEAPON_MPLOCATION07:
			case WEAPON_MPLOCATION08:
			case WEAPON_MPLOCATION09:
			case WEAPON_MPLOCATION10:
			case WEAPON_MPLOCATION11:
			case WEAPON_MPLOCATION12:
			case WEAPON_MPLOCATION13:
			case WEAPON_MPLOCATION14:
			case WEAPON_MPLOCATION15:
				locationindex = weapon->weaponnum - WEAPON_MPLOCATION00;
				mpweapon = mp_get_mp_weapon_by_location(locationindex);
				g_SetupCurMpLocation = locationindex;
				weapon->weaponnum = mpweapon->weaponnum;
				weapon->base.modelnum = mpweapon->model;
				weapon->base.extrascale = mpweapon->extrascale;
				createweapon = mpweapon->hasweapon;

				if (mpweapon->weaponnum == WEAPON_MPSHIELD) {
					struct shieldobj *shield = (struct shieldobj *)weapon;
					shield->base.modelnum = MODEL_CHRSHIELD;
					shield->base.type = OBJTYPE_SHIELD;
					shield->base.flags |= OBJFLAG_01000000 | OBJFLAG_INVINCIBLE;
					shield->base.flags2 |= OBJFLAG2_IMMUNETOEXPLOSIONS | OBJFLAG2_IMMUNETOGUNFIRE;
					shield->initialamount = 1;
					shield->amount = 1;
					setup_create_object(&shield->base, cmdindex);
					createweapon = false;
				}
				break;
			}
		}

		if (weapon->weaponnum != WEAPON_NONE && createweapon) {
			modelmgr_load_projectile_modeldefs(weapon->weaponnum);
			setup_create_object(&weapon->base, cmdindex);
		}
	}
}

void setup_create_hat(struct hatobj *hat, s32 cmdindex)
{
	if (hat->base.flags & OBJFLAG_ASSIGNEDTOCHR) {
		struct chrdata *chr = chr_find_by_literal_id(hat->base.pad);

		if (chr && chr->prop && chr->model) {
			hat_assign_to_chr(hat, chr);
		}
	} else {
		setup_create_object(&hat->base, cmdindex);
	}
}

void setup_create_key(struct keyobj *key, s32 cmdindex)
{
	setup_create_object(&key->base, cmdindex);
}

void setup_create_mine(struct mineobj *mine, s32 cmdindex)
{
	mine->base.type = OBJTYPE_WEAPON;

	setup_create_object(&mine->base, cmdindex);

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mine->base.hidden = (mine->base.hidden & 0x0fffffff) | (2 << 28);
	}

	mine->base.prop->forcetick = true;
}

void setup_create_cctv(struct cctvobj *cctv, s32 cmdindex)
{
	struct defaultobj *obj = &cctv->base;

	setup_create_object(obj, cmdindex);

	if (cctv->lookatpadnum >= 0) {
		struct coord lenspos;
		union modelrodata *lens = model_get_part_rodata(obj->model->definition, MODELPART_CCTV_CASING);
		struct pad pad;
		f32 xdiff;
		f32 ydiff;
		f32 zdiff;

		pad_unpack(cctv->lookatpadnum, PADFIELD_POS, &pad);

		lenspos.x = lens->position.pos.x;
		lenspos.y = lens->position.pos.y;
		lenspos.z = lens->position.pos.z;

		mtx00016208(obj->realrot, &lenspos);

		lenspos.x += obj->prop->pos.x;
		lenspos.y += obj->prop->pos.y;
		lenspos.z += obj->prop->pos.z;

		xdiff = lenspos.x - pad.pos.x;
		ydiff = lenspos.y - pad.pos.y;
		zdiff = lenspos.z - pad.pos.z;

		if (ydiff) {
			// empty
		}

		mtx00016d58(&cctv->camrotm, 0.0f, 0.0f, 0.0f, xdiff, ydiff, zdiff, 0.0f, 1.0f, 0.0f);
		mtx00015f04(obj->model->scale, &cctv->camrotm);

		cctv->toleft = 0;
		cctv->yleft = *(s32 *)&cctv->yleft * BADDTOR(360) / 65536.0f;
		cctv->yright = *(s32 *)&cctv->yright * BADDTOR(360) / 65536.0f;
		cctv->yspeed = 0.0f;
		cctv->ymaxspeed = *(s32 *)&cctv->ymaxspeed * BADDTOR(360) / 65536.0f;
		cctv->maxdist = *(s32 *)&cctv->maxdist;
		cctv->yrot = cctv->yleft;

		cctv->yzero = atan2f(xdiff, zdiff);
		cctv->xzero = BADDTOR(360) - atan2f(ydiff, sqrtf(xdiff * xdiff + zdiff * zdiff));

		if (xdiff || zdiff) {
			// empty
		}

		cctv->seebondtime60 = 0;
	}
}

void setup_create_autogun(struct autogunobj *autogun, s32 cmdindex)
{
	setup_create_object(&autogun->base, cmdindex);

	autogun->maxspeed = *(s32 *)&autogun->maxspeed * PALUPF(BADDTOR(360)) / 65536.0f;
	autogun->aimdist = *(s32 *)&autogun->aimdist * 100.0f / 65536.0f;
	autogun->ymaxleft = *(s32 *)&autogun->ymaxleft * BADDTOR(360) / 65536.0f;
	autogun->ymaxright = *(s32 *)&autogun->ymaxright * BADDTOR(360) / 65536.0f;

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
	autogun->beam = memp_alloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
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
		struct pad pad;

		pad_unpack(autogun->targetpad, PADFIELD_POS, &pad);

		xdiff = pad.pos.x - autogun->base.prop->pos.x;
		ydiff = pad.pos.y - autogun->base.prop->pos.y;
		zdiff = pad.pos.z - autogun->base.prop->pos.z;

		autogun->yzero = atan2f(xdiff, zdiff);
		autogun->xzero = atan2f(ydiff, sqrtf(xdiff * xdiff + zdiff * zdiff));
	} else if (autogun->base.modelnum == MODEL_CETROOFGUN) {
		// Deep Sea roofgun
		autogun->xzero = BADDTOR(-90);
	}
}

void setup_create_hanging_monitors(struct hangingmonitorsobj *monitors, s32 cmdindex)
{
	setup_create_object(&monitors->base, cmdindex);
}

void setup_create_single_monitor(struct singlemonitorobj *monitor, s32 cmdindex)
{
	u32 stack[2];

	monitor->screen = g_TvCmdlistDefaultCopy;
	tvscreen_set_program(&monitor->screen, monitor->imagenum);

	// In GE, monitors with a negative pad are hanging TVs which attach to a
	// hangingmonitors object, which is actually just the mount. In PD, hanging
	// monitors do not exist in the setup files so this code is unused.
	if (monitor->base.pad < 0 && (monitor->base.flags & OBJFLAG_INSIDEANOTHEROBJ) == 0) {
		s32 modelnum = monitor->base.modelnum;
		struct defaultobj *owner = (struct defaultobj *)setup_get_cmd_by_index(cmdindex + monitor->owneroffset);
		struct prop *prop;
		f32 scale;
		struct coord spa4;
		Mtxf sp64;
		Mtxf sp24;

		setup_load_modeldef(modelnum);

		scale = monitor->base.extrascale * (1.0f / 256.0f);

		if (g_Vars.normmplayerisrunning || g_Vars.lvmpbotlevel) {
			monitor->base.hidden2 |= OBJH2FLAG_CANREGEN;
		}

		prop = obj_init_with_auto_model(&monitor->base);
		monitor->base.embedment = embedment_allocate();

		if (prop && monitor->base.embedment) {
			monitor->base.hidden |= OBJHFLAG_EMBEDDED;
			model_set_scale(monitor->base.model, monitor->base.model->scale * scale);
			monitor->base.model->attachedtomodel = owner->model;

			if (monitor->ownerpart == MODELPART_0000) {
				monitor->base.model->attachedtonode = model_get_part(owner->model->definition, MODELPART_0000);
			} else if (monitor->ownerpart == MODELPART_0001) {
				monitor->base.model->attachedtonode = model_get_part(owner->model->definition, MODELPART_0001);
			} else if (monitor->ownerpart == MODELPART_0002) {
				monitor->base.model->attachedtonode = model_get_part(owner->model->definition, MODELPART_0002);
			} else {
				monitor->base.model->attachedtonode = model_get_part(owner->model->definition, MODELPART_0003);
			}

			prop_reparent(prop, owner->prop);
			mtx4_load_x_rotation(0.3664608001709f, &sp64);
			mtx00015f04(monitor->base.model->scale / owner->model->scale, &sp64);
			model_get_root_position(monitor->base.model, &spa4);

			spa4.x = -spa4.x;
			spa4.y = -spa4.y;
			spa4.z = -spa4.z;

			mtx4_load_translation(&spa4, &sp24);
			mtx00015be4(&sp64, &sp24, &monitor->base.embedment->matrix);
		}
	} else {
		setup_create_object(&monitor->base, cmdindex);
	}

	if (monitor->base.prop && (monitor->base.flags & OBJFLAG_MONITOR_RENDERPOSTBG)) {
		monitor->base.prop->flags |= PROPFLAG_RENDERPOSTBG;
	}
}

void setup_create_multi_monitor(struct multimonitorobj *monitor, s32 cmdindex)
{
	monitor->screens[0] = g_TvCmdlistDefaultCopy;
	tvscreen_set_program(&monitor->screens[0], monitor->imagenums[0]);

	monitor->screens[1] = g_TvCmdlistDefaultCopy;
	tvscreen_set_program(&monitor->screens[1], monitor->imagenums[1]);

	monitor->screens[2] = g_TvCmdlistDefaultCopy;
	tvscreen_set_program(&monitor->screens[2], monitor->imagenums[2]);

	monitor->screens[3] = g_TvCmdlistDefaultCopy;
	tvscreen_set_program(&monitor->screens[3], monitor->imagenums[3]);

	setup_create_object(&monitor->base, cmdindex);
}

s32 setup_get_portal_by_pad(s32 padnum)
{
	f32 mult;
	struct coord centre;
	struct coord coord;
	u32 stack;
	struct pad pad;

	pad_get_centre(padnum, &centre);
	pad_unpack(padnum, PADFIELD_BBOX | PADFIELD_UP, &pad);

	mult = (pad.bbox.ymax - pad.bbox.ymin) * 0.5f + 10;

	coord.x = pad.up.x * mult + centre.x;
	coord.y = pad.up.y * mult + centre.y;
	coord.z = pad.up.z * mult + centre.z;

	centre.x = centre.x - pad.up.x * mult;
	centre.y = centre.y - pad.up.y * mult;
	centre.z = centre.z - pad.up.z * mult;

	return bg_find_portal_between_positions(&centre, &coord);
}

s32 setup_get_portal_by_door_pad(s32 padnum)
{
	f32 mult;
	struct coord centre;
	struct coord coord;
	u32 stack;
	struct pad pad;

	pad_get_centre(padnum, &centre);
	pad_unpack(padnum, PADFIELD_BBOX | PADFIELD_NORMAL, &pad);

	mult = (pad.bbox.xmax - pad.bbox.xmin) * 0.5f + 10;

	coord.x = pad.normal.x * mult + centre.x;
	coord.y = pad.normal.y * mult + centre.y;
	coord.z = pad.normal.z * mult + centre.z;

	centre.x = centre.x - pad.normal.x * mult;
	centre.y = centre.y - pad.normal.y * mult;
	centre.z = centre.z - pad.normal.z * mult;

	return bg_find_portal_between_positions(&centre, &coord);
}

f32 g_DoorScale = 1;

void setup_create_door(struct doorobj *door, s32 cmdindex)
{
	f32 scale;
	s32 modelnum = door->base.modelnum;
	s32 portalnum = -1;
	struct pad pad;

	setup_load_modeldef(modelnum);

	if (door->doorflags & DOORFLAG_ROTATEDPAD) {
		pad_rotate_for_door(door->base.pad);
	}

	if (door->base.flags & OBJFLAG_DOOR_HASPORTAL) {
		portalnum = setup_get_portal_by_door_pad(door->base.pad);
	}

	pad_unpack(door->base.pad, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_NORMAL | PADFIELD_BBOX | PADFIELD_ROOM, &pad);

	if (g_DoorScale != 1) {
		pad.bbox.xmin *= g_DoorScale;
		pad.bbox.xmax *= g_DoorScale;

		// If the door has a portal, adjust the pad's bbox to match the portal's dimensions
		if (portalnum >= 0) {
			struct portalmetric *ptr = &g_PortalMetrics[portalnum];
			f32 f0 = pad.pos.f[0] * ptr->normal.f[0] + pad.pos.f[1] * ptr->normal.f[1] + pad.pos.f[2] * ptr->normal.f[2];
			f32 min = ptr->min;
			struct coord sp150;
			f0 = (f0 - min) * (g_DoorScale - 1);

			sp150.x = ptr->normal.x * f0;
			sp150.y = ptr->normal.y * f0;
			sp150.z = ptr->normal.z * f0;

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
		pad_copy_bbox_from_pad(door->base.pad, &pad);
	}

	if (pad.room > 0) {
		Mtxf sp110;
		struct prop *prop;
		s32 siblingcmdindex;
		struct coord pos;
		RoomNum rooms[8];
		Mtxf finalmtx;
		struct coord centre;
		Mtxf zrotmtx;
		struct coord slidedist;
		f32 xscale;
		f32 yscale;
		f32 zscale;
		struct modelrodata_bbox *bbox;

		bbox = modeldef_find_bbox_rodata(g_ModelStates[modelnum].modeldef);

		mtx00016d58(&sp110, 0, 0, 0,
				-pad.look.x, -pad.look.y, -pad.look.z,
				pad.up.x, pad.up.y, pad.up.z);
		mtx4_load_x_rotation(BADDTOR(90), &finalmtx);
		mtx4_load_z_rotation(BADDTOR(90), &zrotmtx);
		mtx4_mult_mtx4_in_place(&zrotmtx, &finalmtx);
		mtx4_mult_mtx4_in_place(&sp110, &finalmtx);

		pad_get_centre(door->base.pad, &centre);

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
			slidedist.x = pad.look.f[0] * (pad.bbox.zmax - pad.bbox.zmin);
			slidedist.y = pad.look.f[1] * (pad.bbox.zmax - pad.bbox.zmin);
			slidedist.z = pad.look.f[2] * (pad.bbox.zmax - pad.bbox.zmin);
		} else {
			slidedist.x = pad.up.f[0] * (pad.bbox.ymin - pad.bbox.ymax);
			slidedist.y = pad.up.f[1] * (pad.bbox.ymin - pad.bbox.ymax);
			slidedist.z = pad.up.f[2] * (pad.bbox.ymin - pad.bbox.ymax);
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
			door->sibling = (struct doorobj *) setup_get_cmd_by_index(siblingcmdindex);
		}

		prop = door_init(door, &pos, &finalmtx, rooms, &slidedist, &centre);

		if (door->base.flags & OBJFLAG_DOOR_HASPORTAL) {
			door->portalnum = portalnum;

			if (door->portalnum >= 0 && door->frac == 0) {
				door_deactivate_portal(door);
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

			model_set_scale(door->base.model, door->base.model->scale * scale);
		}

		prop_activate(prop);
		prop_enable(prop);
	} else {
		door->base.prop = NULL;
	}
}

void setup_create_hov(struct defaultobj *obj, struct hov *hov)
{
	hov->bobycur = 0;
	hov->bobytarget = 0;
	hov->bobyspeed = 0;
	hov->yrot = atan2f(obj->realrot[2][0], obj->realrot[2][2]);
	hov->bobpitchcur = 0;
	hov->bobpitchtarget = 0;
	hov->bobpitchspeed = 0;
	hov->bobrollcur = 0;
	hov->bobrolltarget = 0;
	hov->bobrollspeed = 0;
	hov->groundpitch = 0;
	hov->y = 0;
	hov->ground = 0;
	hov->prevframe60 = -1;
	hov->prevgroundframe60 = -1;
}

void setup_load_briefing(s32 stagenum, u8 *buffer, s32 bufferlen, struct briefing *briefing)
{
	if (stagenum < STAGE_TITLE) {
		s32 stageindex = stage_get_index(stagenum);
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
		g_LoadType = LOADTYPE_LANG;

		file_load_to_addr(setupfilenum, FILELOADMETHOD_DEFAULT, buffer, bufferlen);

		setup = (struct stagesetup *)buffer;
		setupfilesize = file_get_loaded_size(setupfilenum);
		langbuffer = &buffer[setupfilesize];
		langbufferlen = bufferlen - setupfilesize;

		briefing->langbank = lang_get_lang_bank_index_from_stagenum(stagenum);

		lang_load_to_addr(briefing->langbank, langbuffer, langbufferlen);

		start = (struct defaultobj *)((uintptr_t)setup + (u32)setup->props);

		if (start != NULL) {
			struct defaultobj *obj;
			s32 wanttype = BRIEFINGTYPE_TEXT_PA;

			if (lv_get_difficulty() == DIFF_A) {
				wanttype = BRIEFINGTYPE_TEXT_A;
			}

			if (lv_get_difficulty() == DIFF_SA) {
				wanttype = BRIEFINGTYPE_TEXT_SA;
			}

			for (i = 0; (u32)(i < ARRAYCOUNT(briefing->objectivenames)); i++) {
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

				obj = (struct defaultobj *)((u32 *)obj + setup_get_cmd_length((u32 *)obj));
			}
		}
	}
}

void setup_load_files(s32 stagenum)
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
		g_ModelStates[i].modeldef = NULL;
	}

	if (stagenum < STAGE_TITLE) {
		if (g_Vars.normmplayerisrunning) {
			filenum = g_Stages[g_StageIndex].mpsetupfileid;
		} else {
			filenum = g_Stages[g_StageIndex].setupfileid;
		}

		g_LoadType = LOADTYPE_SETUP;

		g_GeCreditsData = (u8 *)file_load_to_new(filenum, FILELOADMETHOD_DEFAULT);
		setup = (struct stagesetup *)g_GeCreditsData;
		lang_load(lang_get_lang_bank_index_from_stagenum(stagenum));

		g_StageSetup.intro = (s32 *)((uintptr_t)setup + (u32)setup->intro);
		g_StageSetup.props = (u32 *)((uintptr_t)setup + (u32)setup->props);
		g_StageSetup.paths = (struct path *)((uintptr_t)setup + (u32)setup->paths);
		g_StageSetup.ailists = (struct ailist *)((uintptr_t)setup + (u32)setup->ailists);

		g_LoadType = LOADTYPE_PADS;

		g_StageSetup.padfiledata = file_load_to_new(g_Stages[g_StageIndex].padsfileid, FILELOADMETHOD_DEFAULT);

		g_StageSetup.waypoints = NULL;
		g_StageSetup.waygroups = NULL;
		g_StageSetup.cover = NULL;

		// Convert ailist pointers from file-local to proper pointers
		if (g_StageSetup.ailists) {
			for (i = 0; g_StageSetup.ailists[i].list != NULL; i++) {
				g_StageSetup.ailists[i].list = (u8 *)((uintptr_t)setup + (u32)g_StageSetup.ailists[i].list);
			}
		}

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
				g_StageSetup.paths[i].pads = (s32 *)((uintptr_t)g_StageSetup.paths[i].pads + (u32)setup);

				for (j = 0; g_StageSetup.paths[i].pads[j] >= 0; j++);

				g_StageSetup.paths[i].len = j;
			}
		}

		// Count the number of chrs and objects so enough model slots can be allocated
		numchrs += setup_count_command_type(OBJTYPE_CHR);

		if (!g_Vars.normmplayerisrunning && g_MissionConfig.iscoop && g_Vars.numaibuddies > 0) {
			// @bug? The Hotshot buddy has two guns, but only one is counted here.
			numchrs += g_Vars.numaibuddies;
			numobjs += g_Vars.numaibuddies; // the buddy's weapon
		}

		numobjs += setup_count_command_type(OBJTYPE_WEAPON);
		numobjs += setup_count_command_type(OBJTYPE_KEY);
		numobjs += setup_count_command_type(OBJTYPE_HAT);
		numobjs += setup_count_command_type(OBJTYPE_DOOR);
		numobjs += setup_count_command_type(OBJTYPE_CCTV);
		numobjs += setup_count_command_type(OBJTYPE_AUTOGUN);
		numobjs += setup_count_command_type(OBJTYPE_HANGINGMONITORS);
		numobjs += setup_count_command_type(OBJTYPE_SINGLEMONITOR);
		numobjs += setup_count_command_type(OBJTYPE_MULTIMONITOR);
		numobjs += setup_count_command_type(OBJTYPE_SHIELD);
		numobjs += setup_count_command_type(OBJTYPE_BASIC);
		numobjs += setup_count_command_type(OBJTYPE_DEBRIS);
		numobjs += setup_count_command_type(OBJTYPE_GLASS);
		numobjs += setup_count_command_type(OBJTYPE_TINTEDGLASS);
		numobjs += setup_count_command_type(OBJTYPE_SAFE);
		numobjs += setup_count_command_type(OBJTYPE_29);
		numobjs += setup_count_command_type(OBJTYPE_GASBOTTLE);
		numobjs += setup_count_command_type(OBJTYPE_ALARM);
		numobjs += setup_count_command_type(OBJTYPE_AMMOCRATE);
		numobjs += setup_count_command_type(OBJTYPE_MULTIAMMOCRATE);
		numobjs += setup_count_command_type(OBJTYPE_TRUCK);
		numobjs += setup_count_command_type(OBJTYPE_TANK);
		numobjs += setup_count_command_type(OBJTYPE_LIFT);
		numobjs += setup_count_command_type(OBJTYPE_HOVERBIKE);
		numobjs += setup_count_command_type(OBJTYPE_HOVERPROP);
		numobjs += setup_count_command_type(OBJTYPE_FAN);
		numobjs += setup_count_command_type(OBJTYPE_HOVERCAR);
		numobjs += setup_count_command_type(OBJTYPE_CHOPPER);
		numobjs += setup_count_command_type(OBJTYPE_HELI);
		numobjs += setup_count_command_type(OBJTYPE_ESCASTEP);

		if (g_Vars.normmplayerisrunning) {
			numobjs += scenario_num_props();
		}

		modelmgr_allocate_slots(numobjs, numchrs);
	} else {
		// cover isn't set to NULL here... I guess it's not important
		g_StageSetup.waypoints = NULL;
		g_StageSetup.waygroups = NULL;
		g_StageSetup.intro = 0;
		g_StageSetup.props = 0;
		g_StageSetup.paths = NULL;
		g_StageSetup.ailists = NULL;
		g_StageSetup.padfiledata = NULL;

		modelmgr_allocate_slots(0, 0);
	}

	if (IS4MB()) {
		extra = 40;
	} else {
		extra = 60;
	}

	if (IS4MB());

	g_Vars.maxprops = numobjs + numchrs + extra + 40;
}

void setup_create_props(s32 stagenum)
{
	s32 withchrs = !arg_find_by_prefix(1, "-nochr") && !arg_find_by_prefix(1, "-noprop");
	s32 withobjs = !arg_find_by_prefix(1, "-noobj") && !arg_find_by_prefix(1, "-noprop");
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

	for (j = 0; j != ARRAYCOUNT(g_Briefing.objectivenames); j++) {
		g_Briefing.objectivenames[j] = 0;
		g_Briefing.objectivedifficulties[j] = 0;
	}

	g_Briefing.briefingtextnum = L_MISC_042; // "No briefing for this mission"

	if (stagenum < STAGE_TITLE) {
		if (g_StageSetup.padfiledata) {
			setup_prepare_pads();
		}

		setup_load_waypoints();

		if (withchrs) {
			s32 numchrs = 0;

			numchrs += setup_count_command_type(OBJTYPE_CHR);

			if (g_Vars.normmplayerisrunning == false
					&& g_MissionConfig.iscoop
					&& g_Vars.numaibuddies > 0) {
				numchrs += g_Vars.numaibuddies;
			}

			chrmgr_configure(numchrs);
		} else {
			chrmgr_configure(0);
		}

		for (j = 0; j < PLAYERCOUNT(); j++) {
			set_current_player_num(j);
			inv_init(setup_count_command_type(OBJTYPE_LINKGUNS));
		}

		if (g_StageSetup.props) {
			u32 diffflag = 0;
			s32 index;

			diffflag |= 1 << (lv_get_difficulty() + 4);

			if (g_Vars.mplayerisrunning) {
				if (PLAYERCOUNT() == 2) {
					diffflag |= OBJFLAG2_EXCLUDE_2P;
				} else if (PLAYERCOUNT() == 3) {
					diffflag |= OBJFLAG2_EXCLUDE_3P;
				} else if (PLAYERCOUNT() == 4) {
					diffflag |= OBJFLAG2_EXCLUDE_4P;
				}
			}

			botmgr_remove_all();
			index = 0;

			obj = (struct defaultobj *)g_StageSetup.props;

			while (obj->type != OBJTYPE_END) {
				switch (obj->type) {
				case OBJTYPE_GRENADEPROB:
					{
						struct grenadeprobobj *grenadeprob = (struct grenadeprobobj *)obj;
						u8 probability = grenadeprob->probability;
						struct chrdata *chr = chr_find_by_literal_id(grenadeprob->chrnum);

						if (chr && chr->prop && chr->model) {
							chr->grenadeprob = probability;
						}
					}
					break;
				case OBJTYPE_CHR:
					if (withchrs) {
						body_instantiate_chr(stagenum, (struct packedchr *) obj, index);
					}
					break;
				case OBJTYPE_DOOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setup_create_door((struct doorobj *)obj, index);
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
						setup_place_weapon((struct weaponobj *)obj, index);
					}
					break;
				case OBJTYPE_KEY:
					if (withchrs && (obj->flags2 & diffflag) == 0) {
						setup_create_key((struct keyobj *)obj, index);
					}
					break;
				case OBJTYPE_HAT:
					if (withchrs && (obj->flags2 & diffflag) == 0) {
						setup_create_hat((struct hatobj *)obj, index);
					}
					break;
				case OBJTYPE_CCTV:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setup_create_cctv((struct cctvobj *)obj, index);
					}
					break;
				case OBJTYPE_AUTOGUN:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setup_create_autogun((struct autogunobj *)obj, index);
					}
					break;
				case OBJTYPE_HANGINGMONITORS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setup_create_hanging_monitors((struct hangingmonitorsobj *)obj, index);
					}
					break;
				case OBJTYPE_SINGLEMONITOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setup_create_single_monitor((struct singlemonitorobj *)obj, index);
					}
					break;
				case OBJTYPE_MULTIMONITOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setup_create_multi_monitor((struct multimonitorobj *)obj, index);
					}
					break;
				case OBJTYPE_SHIELD:
					if (withobjs) {
#if VERSION >= VERSION_JPN_FINAL
						if ((obj->flags2 & diffflag) == 0)
#else
						if ((obj->flags2 & diffflag) == 0 || g_Jpn)
#endif
						{
							struct shieldobj *shield = (struct shieldobj *)obj;
							shield->initialamount = *(s32 *)&shield->initialamount / 65536.0f;
							shield->amount = shield->initialamount;
							setup_create_object(obj, index);
						}
					}
					break;
				case OBJTYPE_TINTEDGLASS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						if (obj->flags & OBJFLAG_GLASS_HASPORTAL) {
							struct tintedglassobj *glass = (struct tintedglassobj *)obj;
							glass->portalnum = setup_get_portal_by_pad(obj->pad);
							glass->unk64 = *(s32 *)&glass->unk64 / 65536.0f;
						}

						setup_create_object(obj, index);
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

						for (i = 0; i < ARRAYCOUNT(lift->doors); i++) {
							if (lift->doors[i]) {
								lift->doors[i] = (struct doorobj *)setup_get_cmd_by_index(index + *(s32*)&lift->doors[i]);
							}
						}

						obj->geocount = 1;
						setup_load_modeldef(modelnum);
						modelstate = &g_ModelStates[modelnum];

						if (modelstate->modeldef) {
							if (model_get_part_rodata(modelstate->modeldef, MODELPART_LIFT_WALL1)) {
								obj->geocount++;
							}
							if (model_get_part_rodata(modelstate->modeldef, MODELPART_LIFT_WALL2)) {
								obj->geocount++;
							}
							if (model_get_part_rodata(modelstate->modeldef, MODELPART_LIFT_WALL3)) {
								obj->geocount++;
							}
							if (model_get_part_rodata(modelstate->modeldef, MODELPART_LIFT_DOORBLOCK)) {
								obj->geocount++;
							}
							if (model_get_part_rodata(modelstate->modeldef, MODELPART_LIFT_FLOORNONRECT2)) {
								obj->geocount++;
							}
						}

						obj->flags &= ~OBJFLAG_CORE_GEO_INUSE;

						setup_create_object(obj, index);

						prop = obj->prop;

						if (prop) {
							lift->prevpos.x = prop->pos.x;
							lift->prevpos.y = prop->pos.y;
							lift->prevpos.z = prop->pos.z;

							lift_update_tiles(lift, true);
						}
					}
					break;
				case OBJTYPE_HOVERPROP:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct hoverpropobj *hoverprop = (struct hoverpropobj *)obj;

						setup_create_object(obj, index);
						setup_create_hov(obj, &hoverprop->hov);
					}
					break;
				case OBJTYPE_HOVERBIKE:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct hoverbikeobj *bike = (struct hoverbikeobj *)obj;

						setup_create_object(obj, index);
						setup_create_hov(obj, &bike->hov);

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

						setup_create_object(obj, index);
					}
					break;
				case OBJTYPE_GLASS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						if (obj->flags & OBJFLAG_GLASS_HASPORTAL) {
							struct glassobj *glass = (struct glassobj *)obj;
							glass->portalnum = setup_get_portal_by_pad(obj->pad);
						}

						setup_create_object(obj, index);
					}
					break;
				case OBJTYPE_ESCASTEP:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct escalatorobj *step = (struct escalatorobj *)obj;
						struct prop *prop;

#ifdef AVOID_UB
						Mtxf sp1a8;
#else
						// TODO: There is a stack problem here that should be
						// resolved. sp1a8 is really an Mtxf which doesn't fit
						// in its current location in the stack.
						f32 sp1a8[12];
#endif
						f32 sp184[3][3];

						setup_create_object(obj, index);

						prop = obj->prop;

						if (prop) {
							step->prevpos.x = prop->pos.x;
							step->prevpos.y = prop->pos.y;
							step->prevpos.z = prop->pos.z;
						}

						if (obj->flags & OBJFLAG_ESCSTEP_ZALIGNED) {
							step->frame = escstepy;
							escstepy += 40;
							mtx4_load_y_rotation(BADDTOR(270), (Mtxf *) &sp1a8);
							mtx4_to_mtx3((Mtxf *) &sp1a8, sp184);
							mtx00016110(sp184, obj->realrot);
						} else {
							step->frame = escstepx;
							escstepx += 40;
							mtx4_load_y_rotation(BADDTOR(180), (Mtxf *) &sp1a8);
							mtx4_to_mtx3((Mtxf *) &sp1a8, sp184);
							mtx00016110(sp184, obj->realrot);
						}
					}
					break;
				case OBJTYPE_BASIC:
				case OBJTYPE_ALARM:
				case OBJTYPE_AMMOCRATE:
				case OBJTYPE_DEBRIS:
				case OBJTYPE_GASBOTTLE:
				case OBJTYPE_29:
				case OBJTYPE_SAFE:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setup_create_object(obj, index);
					}
					break;
				case OBJTYPE_MULTIAMMOCRATE:
					{
						struct multiammocrateobj *crate = (struct multiammocrateobj *)obj;
						s32 ammoqty = 1;
						s32 i;

						if (g_Vars.normmplayerisrunning && g_SetupCurMpLocation >= 0) {
							struct mpweapon *mpweapon = mp_get_mp_weapon_by_location(g_SetupCurMpLocation);
							ammoqty = mpweapon->priammoqty;

							if (mpweapon->priammotype > 0 && mpweapon->priammotype < 20) {
								crate->slots[mpweapon->priammotype - 1].quantity = ammoqty;
							}

							if (mpweapon->secammotype > 0 && mpweapon->secammotype < 20) {
								crate->slots[mpweapon->secammotype - 1].quantity = mpweapon->secammoqty;
							}
						}

						if (ammoqty > 0 && withobjs && (obj->flags2 & diffflag) == 0) {
							for (i = 0; i < ARRAYCOUNT(crate->slots); i++) {
								if (crate->slots[i].quantity > 0 && crate->slots[i].modelnum != 0xffff) {
									setup_load_modeldef(crate->slots[i].modelnum);
								}
							}

							setup_create_object(obj, index);
						}
					}
					break;
				case OBJTYPE_TRUCK:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct truckobj *truck = (struct truckobj *)obj;

						setup_create_object(obj, index);

						if (obj->model) {
							struct modelnode *node = model_get_part(obj->model->definition, MODELPART_TRUCK_0005);

							if (node) {
								// The truck model doesn't exist in PD, so I'm assuming this is a toggle node
								union modelrwdata *rwdata = model_get_node_rw_data(obj->model, node);
								rwdata->toggle.visible = ((obj->flags & OBJFLAG_DEACTIVATED) == 0);
							}
						}

						truck->speed = 0;
						truck->wheelxrot = 0;
						truck->wheelyrot = 0;
						truck->speedaim = 0;
						truck->speedtime60 = -1;
						truck->turnrot60 = 0;
						truck->roty = 0;
						truck->ailist = ailist_find_by_id((u32)truck->ailist);
						truck->aioffset = 0;
						truck->aireturnlist = -1;
						truck->path = NULL;
						truck->nextstep = 0;
					}
					break;
				case OBJTYPE_HOVERCAR:
					if (withhovercars && withobjs && (obj->flags2 & diffflag) == 0) {
						struct hovercarobj *car = (struct hovercarobj *)obj;
						struct prop *prop;

						setup_create_object(obj, index);

						prop = obj->prop;

						car->speed = 0;
						car->speedaim = 0;
						car->turnrot60 = 0;
						car->roty = 0;
						car->rotx = 0;
						car->speedtime60 = -1;
						car->ailist = ailist_find_by_id((s32)car->ailist);
						car->aioffset = 0;
						car->aireturnlist = -1;
						car->path = NULL;
						car->nextstep = 0;

						if (obj->flags & OBJFLAG_CHOPPER_INACTIVE) {
							prop->pos.y = cd_find_floor_y_colour_type_at_pos(&prop->pos, prop->rooms, NULL, 0) + 30;
						}

						prop->forcetick = true;
					}
					break;
				case OBJTYPE_CHOPPER:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct chopperobj *chopper = (struct chopperobj *)obj;

						setup_create_object(obj, index);

						obj->flags |= OBJFLAG_CHOPPER_INIT;
						obj->prop->forcetick = true;

						chopper->turnrot60 = 0;
						chopper->roty = 0;
						chopper->rotx = 0;
						chopper->gunroty = 0;
						chopper->gunrotx = 0;
						chopper->barrelrot = 0;
						chopper->barrelrotspeed = 0;
						chopper->ailist = ailist_find_by_id((u32)chopper->ailist);
						chopper->aioffset = 0;
						chopper->aireturnlist = -1;
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
						chopper->fireslotthing = memp_alloc(sizeof(struct fireslotthing), MEMPOOL_STAGE);
						chopper->fireslotthing->beam = memp_alloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
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
				case OBJTYPE_HELI:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct heliobj *heli = (struct heliobj *)obj;

						setup_create_object(obj, index);

						heli->speed = 0;
						heli->speedaim = 0;
						heli->rotoryrot = 0;
						heli->rotoryspeed = 0;
						heli->rotoryspeedaim = 0;
						heli->yrot = 0;
						heli->speedtime60 = -1;
						heli->rotoryspeedtime = -1;
						heli->ailist = ailist_find_by_id((u32)heli->ailist);
						heli->aioffset = 0;
						heli->aireturnlist = -1;
						heli->path = NULL;
						heli->nextstep = 0;
					}
					break;
				case OBJTYPE_TAG:
					{
						struct tag *tag = (struct tag *)obj;
						struct defaultobj *taggedobj = setup_get_obj_by_cmd_index(index + tag->cmdoffset);
						tag->obj = taggedobj;

						if (taggedobj) {
							taggedobj->hidden |= OBJHFLAG_TAGGED;
						}

						tag_insert(tag);
					}
					break;
				case OBJTYPE_RENAMEOBJ:
					{
						struct textoverride *override = (struct textoverride *)obj;
						struct defaultobj *targetobj = setup_get_obj_by_cmd_index(override->objoffset + index);
						override->obj = targetobj;

						if (targetobj) {
							targetobj->hidden |= OBJHFLAG_HASTEXTOVERRIDE;
						}

						inv_insert_text_override(override);
					}
					break;
				case OBJTYPE_BRIEFING:
					{
						struct briefingobj *briefing = (struct briefingobj *)obj;
						s32 wanttype = BRIEFINGTYPE_TEXT_PA;

						briefing_insert(briefing);

						if (lv_get_difficulty() == DIFF_A) {
							wanttype = BRIEFINGTYPE_TEXT_A;
						}

						if (lv_get_difficulty() == DIFF_SA) {
							wanttype = BRIEFINGTYPE_TEXT_SA;
						}

						if (briefing->type == wanttype) {
							g_Briefing.briefingtextnum = briefing->text;
						}
					}
					break;
				case OBJTYPE_CAMERAPRESET:
					{
						struct camerapresetobj *preset = (struct camerapresetobj *)obj;
						preset->x = *(s32 *)&preset->x / 100.0f;
						preset->y = *(s32 *)&preset->y / 100.0f;
						preset->z = *(s32 *)&preset->z / 100.0f;
						preset->theta = *(s32 *)&preset->theta / 65536.0f;
						preset->verta = *(s32 *)&preset->verta / 65536.0f;
					}
					break;
				case OBJTYPE_BEGINOBJECTIVE:
					{
						struct objective *objective = (struct objective *)obj;

						objective_insert(objective);

						if ((u32)objective->index < 7) {
							g_Briefing.objectivenames[objective->index] = objective->text;
							g_Briefing.objectivedifficulties[objective->index] = objective->difficulties;
						}
					}
					break;
				case OBJECTIVETYPE_ENTERROOM:
					objective_add_room_entered_criteria((struct criteria_roomentered *)obj);
					break;
				case OBJECTIVETYPE_THROWINROOM:
					objective_add_throw_in_room_criteria((struct criteria_throwinroom *)obj);
					break;
				case OBJECTIVETYPE_HOLOGRAPH:
					objective_add_holograph_criteria((struct criteria_holograph *)obj);
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
						setup_create_mine((struct mineobj *)obj, index);
					}
					break;
				}

				obj = (struct defaultobj *)((u32 *)obj + setup_get_cmd_length((u32 *)obj));
				index++;
			}

			index = 0;

			if (g_Vars.normmplayerisrunning && mp_has_simulants()) {
				u32 stack[4];
				s32 i;
				s32 slotsdone[MAX_BOTS];
				s32 chrnum = 0;
				s32 maxsimulants;
				s32 slotnum;

				if (challenge_is_feature_unlocked(MPFEATURE_8BOTS)) {
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
							&& mp_is_sim_slot_enabled(slotnum)) {
						botmgr_allocate_bot(chrnum, slotnum);
						chrnum++;
					}

					slotsdone[slotnum] = true;
				}
			}

			if (g_Vars.normmplayerisrunning) {
				scenario_init_props();
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
				case OBJTYPE_GASBOTTLE:
				case OBJTYPE_29:
				case OBJTYPE_GLASS:
				case OBJTYPE_SAFE:
				case OBJTYPE_TINTEDGLASS:
					if (obj->prop && (obj->flags & OBJFLAG_INSIDEANOTHEROBJ)) {
						s32 offset = obj->pad;
						struct defaultobj *owner = setup_get_obj_by_cmd_index(index + offset);

						if (owner && owner->prop) {
							obj->hidden |= OBJHFLAG_HASOWNER;
							model_set_scale(obj->model, obj->model->scale);
							prop_reparent(obj->prop, owner->prop);
						}
					}
					break;
				case OBJTYPE_LINKGUNS:
					{
						struct linkgunsobj *link = (struct linkgunsobj *)obj;
						struct weaponobj *gun1 = (struct weaponobj *)setup_get_cmd_by_index(link->offset1 + index);
						struct weaponobj *gun2 = (struct weaponobj *)setup_get_cmd_by_index(link->offset2 + index);

						if (gun1 && gun2
								&& gun1->base.type == OBJTYPE_WEAPON
								&& gun2->base.type == OBJTYPE_WEAPON) {
							weapon_set_dual(gun1, gun2);
						}
					}
					break;
				case OBJTYPE_LINKLIFTDOOR:
					{
						struct linkliftdoorobj *link = (struct linkliftdoorobj *)obj;
						s32 dooroffset = (s32)link->door;
						s32 liftoffset = (s32)link->lift;
						struct defaultobj *door = setup_get_obj_by_cmd_index(index + dooroffset);
						struct defaultobj *lift = setup_get_obj_by_cmd_index(index + liftoffset);

						if (door && door->prop && lift && lift->prop) {
							link->door = door->prop;
							link->lift = lift->prop;

							setup_create_lift_door(link);

							door->hidden |= OBJHFLAG_LIFTDOOR;
						}
					}
					break;
				case OBJTYPE_SAFEITEM:
					{
						struct safeitemobj *link = (struct safeitemobj *)obj;
						s32 itemoffset = (s32)link->item;
						s32 safeoffset = (s32)link->safe;
						s32 dooroffset = (s32)link->door;
						struct defaultobj *item = setup_get_obj_by_cmd_index(index + itemoffset);
						struct defaultobj *safe = setup_get_obj_by_cmd_index(index + safeoffset);
						struct defaultobj *door = setup_get_obj_by_cmd_index(index + dooroffset);

						if (item && item->prop
								&& safe && safe->prop && safe->type == OBJTYPE_SAFE
								&& door && door->prop && door->type == OBJTYPE_DOOR) {
							link->item = item;
							link->safe = (struct safeobj *)safe;
							link->door = (struct doorobj *)door;

							setup_create_safe_item(link);

							item->flags2 |= OBJFLAG2_LINKEDTOSAFE;
							door->flags2 |= OBJFLAG2_LINKEDTOSAFE;
						}
					}
					break;
				case OBJTYPE_PADLOCKEDDOOR:
					{
						struct padlockeddoorobj *link = (struct padlockeddoorobj *)obj;
						s32 dooroffset = (s32)link->door;
						s32 lockoffset = (s32)link->lock;
						struct defaultobj *door = setup_get_obj_by_cmd_index(index + dooroffset);
						struct defaultobj *lock = setup_get_obj_by_cmd_index(index + lockoffset);

						if (door && door->prop && lock && lock->prop
								&& door->type == OBJTYPE_DOOR) {
							link->door = (struct doorobj *)door;
							link->lock = lock;

							setup_create_padlocked_door(link);

							door->hidden |= OBJHFLAG_PADLOCKEDDOOR;
						}
					}
					break;
				case OBJTYPE_CONDITIONALSCENERY:
					{
						struct linksceneryobj *link = (struct linksceneryobj *)obj;
						s32 triggeroffset = (s32)link->trigger;
						s32 unexpoffset = (s32)link->unexp;
						s32 expoffset = (s32)link->exp;
						struct defaultobj *trigger = setup_get_obj_by_cmd_index(index + triggeroffset);
						struct defaultobj *unexp = NULL;
						struct defaultobj *exp = NULL;
						s32 alwayszero = 0;

						if (unexpoffset) {
							unexp = setup_get_obj_by_cmd_index(index + unexpoffset);
						}

						if (expoffset) {
							exp = setup_get_obj_by_cmd_index(index + expoffset);
						}

						if (trigger && trigger->prop
								&& (unexpoffset == 0 || (unexp && unexp->prop))
								&& (expoffset == 0 || (exp && exp->prop))) {
							link->trigger = trigger;
							link->unexp = unexp;
							link->exp = exp;

							setup_create_conditional_scenery(link);

							trigger->hidden |= OBJHFLAG_CONDITIONALSCENERY;

							if (unexpoffset) {
								unexp->hidden |= OBJHFLAG_CONDITIONALSCENERY;
							}

							// This gets optimised out but makes v0 unavailable
							// for storing OBJHFLAG_CONDITIONALSCENERY, which is required
							// for a match. Any function call would work.
							if (alwayszero) {
								random();
							}

							if (expoffset) {
								exp->hidden |= OBJHFLAG_CONDITIONALSCENERY;
								exp->flags2 |= OBJFLAG2_INVISIBLE;
							}

							if (trigger->hidden & OBJHFLAG_BLOCKEDPATH) {
								obj_set_blocked_path_unblocked(trigger, false);
							}
						}
					}
					break;
				case OBJTYPE_BLOCKEDPATH:
					{
						struct blockedpathobj *blockedpath = (struct blockedpathobj *)obj;
						s32 objoffset = (s32)blockedpath->blocker;
						struct defaultobj *blocker = setup_get_obj_by_cmd_index(index + objoffset);

						if (blocker && blocker->prop) {
							blockedpath->blocker = blocker;

							setup_create_blocked_path(blockedpath);

							blocker->hidden |= OBJHFLAG_BLOCKEDPATH;

							if (blocker->hidden & OBJHFLAG_CONDITIONALSCENERY) {
								obj_set_blocked_path_unblocked(blocker, false);
							}
						}
					}
					break;
				}

				obj = (struct defaultobj *)((u32 *)obj + setup_get_cmd_length((u32 *)obj));
				index++;
			}
		}
	} else {
		chrmgr_configure(0);
	}

	chrai_load_bgchrs();
}
