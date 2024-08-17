#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/inv.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/player.h"
#include "game/hudmsg.h"
#include "game/playermgr.h"
#include "game/mplayer/setup.h"
#include "game/botcmd.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "data.h"
#include "types.h"

struct weapon *weapon_find_by_id(s32 itemid)
{
	if (itemid < 0) {
		return NULL;
	}

	if (itemid >= ARRAYCOUNT(g_Weapons)) {
		return NULL;
	}

	return g_Weapons[itemid];
}

struct weaponfunc *weapon_get_function_by_id(u32 weaponnum, u32 which)
{
	struct weapon *weapon = weapon_find_by_id(weaponnum);

	if (weapon) {
		return weapon->functions[which];
	}

	return NULL;
}

struct weaponfunc *gset_get_weapon_function2(struct gset *gset)
{
	struct weapon *weapon = weapon_find_by_id(gset->weaponnum);

	if (weapon) {
		return weapon->functions[gset->weaponfunc];
	}

	return NULL;
}

struct weaponfunc *gset_get_weapon_function(struct gset *gset)
{
	struct weapon *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->functions[gset->weaponfunc];
	}

	return NULL;
}

struct weaponfunc *weapon_get_function(struct gset *gset, s32 which)
{
	struct weapon *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->functions[which];
	}

	return NULL;
}

struct weaponfunc *current_player_get_weapon_function(u32 hand)
{
	struct weapon *weapon = weapon_find_by_id(g_Vars.currentplayer->hands[hand].gset.weaponnum);

	if (weapon) {
		return weapon->functions[g_Vars.currentplayer->hands[hand].gset.weaponfunc];
	}

	return NULL;
}

u32 weapon_get_num_functions(u32 weaponnum)
{
	struct weapon *weapon = weapon_find_by_id(weaponnum);
	s32 i;

	if (!weapon) {
		return 0;
	}

	for (i = 0; i < 2; i++) {
		if (weapon->functions[i] == NULL) {
			return i;
		}
	}

	return 2;
}

struct invaimsettings *gset_get_aim_settings(struct gset *gset)
{
	struct weapon *weapon = weapon_find_by_id(gset->weaponnum);

	if (weapon) {
		return weapon->aimsettings;
	}

	return &invaimsettings_default;
}

struct inventory_ammo *weapon_get_ammo_by_function(u32 weaponnum, u32 funcnum)
{
	struct weapon *weapon = weapon_find_by_id(weaponnum);
	struct weaponfunc *func = weapon_get_function_by_id(weaponnum, funcnum);

	if (func && weapon && func->ammoindex >= 0) {
		return weapon->ammos[func->ammoindex];
	}

	return NULL;
}

void current_player_get_weapon_pos(struct coord *pos)
{
	struct weapon *weapon = weapon_find_by_id(bgun_get_weapon_num(HAND_RIGHT));

	if (weapon) {
		pos->x = weapon->posx;
		pos->y = weapon->posy;
		pos->z = weapon->posz;
	}
}

void current_player_set_weapon_pos(struct coord *pos)
{
	struct weapon *weapon = weapon_find_by_id(bgun_get_weapon_num(HAND_RIGHT));

	if (weapon) {
		weapon->posx = pos->x;
		weapon->posy = pos->y;
		weapon->posz = pos->z;
	}
}

f32 hand_get_x_shift(s32 handnum)
{
	return g_Vars.currentplayer->hands[handnum].xshift;
}

f32 func0f0b131c(s32 hand)
{
	f32 x;
	struct weapon *weapon;

	if (hand == 0) {
		weapon = weapon_find_by_id(bgun_get_weapon_num2(0));
		x = weapon->posx;

		if (PLAYERCOUNT() == 2 && options_get_screen_split() == SCREENSPLIT_VERTICAL) {
			x -= 3.5f;

			if (g_Vars.currentplayernum == 0) {
				x += 2.0f;
			}
		}
	} else {
		weapon = weapon_find_by_id(bgun_get_weapon_num2(1));
		x = -weapon->posx;

		if (PLAYERCOUNT() == 2 && options_get_screen_split() == SCREENSPLIT_VERTICAL) {
			x += 3.5f;

			if (g_Vars.currentplayernum == 0) {
				x += 2.0f;
			}
		}
	}

	return x;
}

f32 current_player_get_gun_zoom_fov(void)
{
	s32 index = -1;
	struct weapon *weapon;

	switch (bgun_get_weapon_num2(0)) {
	case WEAPON_SNIPERRIFLE:
		index = 0;
		break;
	case WEAPON_FARSIGHT:
		index = 1;
		break;
	case WEAPON_HORIZONSCANNER:
		index = 2;
		break;
	}

	if (index >= 0) {
		return g_Vars.currentplayer->gunzoomfovs[index];
	}

	weapon = weapon_find_by_id(bgun_get_weapon_num2(0));

	if (weapon) {
		f32 fov = weapon->aimsettings->zoomfov;
		return fov;
	}

	return 0;
}

void current_player_zoom_out(f32 fovpersec)
{
	s32 index = -1;

	switch (bgun_get_weapon_num2(0)) {
	case WEAPON_SNIPERRIFLE:
		index = 0;
		break;
	case WEAPON_FARSIGHT:
		index = 1;
		break;
	case WEAPON_HORIZONSCANNER:
		index = 2;
		break;
	}

	if (index >= 0) {
		f32 amount = fovpersec * 0.25f * LVUPDATE60FREAL();

		if (bgun_get_weapon_num2(0) == WEAPON_FARSIGHT) {
			amount *= 0.5f;
		}

		g_Vars.currentplayer->gunzoomfovs[index] *= 1.0f + amount * 0.1f;

		if (g_Vars.currentplayer->gunzoomfovs[index] > 60) {
			g_Vars.currentplayer->gunzoomfovs[index] = 60;
		}
	}
}

void current_player_zoom_in(f32 fovpersec)
{
	s32 index = -1;

	switch (bgun_get_weapon_num2(0)) {
	case WEAPON_SNIPERRIFLE:
		index = 0;
		break;
	case WEAPON_FARSIGHT:
		index = 1;
		break;
	case WEAPON_HORIZONSCANNER:
		index = 2;
		break;
	}

	if (index >= 0) {
		f32 amount = fovpersec * 0.25f * LVUPDATE60FREAL();

		if (bgun_get_weapon_num2(0) == WEAPON_FARSIGHT) {
			amount *= 0.5f;
		}

		g_Vars.currentplayer->gunzoomfovs[index] /= 1 + amount * 0.1f;

		if (g_Vars.currentplayer->gunzoomfovs[index] < 2) {
			g_Vars.currentplayer->gunzoomfovs[index] = 2;
		}
	}
}

bool weapon_has_flag(s32 itemid, u32 flag)
{
	struct weapon *weapon = weapon_find_by_id(itemid);

	if (!weapon) {
		return false;
	}

	return (weapon->flags & flag) != 0;
}

bool weapon_has_aim_flag(s32 weaponnum, u32 flag)
{
	struct weapon *weapon = weapon_find_by_id(weaponnum);

	if (!weapon) {
		return false;
	}

	return (weapon->aimsettings->flags & flag) != 0;
}

bool weapon_has_ammo_flag(s32 weaponnum, s32 funcnum, u32 flag)
{
	struct weapon *weapon = weapon_find_by_id(weaponnum);
	struct inventory_ammo *ammo;

	if (weapon == NULL) {
		return false;
	}

	ammo = weapon->ammos[funcnum];

	if (ammo) {
		return (ammo->flags & flag) != 0;
	}

	return false;
}

void func0f0b18ac(s32 arg0)
{
	// empty
}

void func0f0b18b4(s32 arg0)
{
	// empty
}

s32 current_player_get_device_state(s32 weaponnum)
{
	struct weapon *weapon = weapon_find_by_id(weaponnum);
	s32 i;

	if (!weapon) {
		return DEVICESTATE_UNEQUIPPED;
	}

	for (i = 0; i < ARRAYCOUNT(weapon->functions); i++) {
		if (weapon->functions[i]) {
			struct weaponfunc_device *devicefunc = weapon->functions[i];

			if ((devicefunc->base.type & 0xff) == INVENTORYFUNCTYPE_DEVICE) {
				if ((g_Vars.currentplayer->devicesactive & devicefunc->device) == 0) {
					return DEVICESTATE_INACTIVE;
				}

				return DEVICESTATE_ACTIVE;
			}
		}
	}

	return DEVICESTATE_UNEQUIPPED;
}

void current_player_set_device_active(s32 weaponnum, bool active)
{
	struct weapon *weapon = weapon_find_by_id(weaponnum);
	s32 i;

	if (!weapon) {
		return;
	}

	for (i = 0; i < ARRAYCOUNT(weapon->functions); i++) {
		if (weapon->functions[i]) {
			struct weaponfunc_device *devicefunc = weapon->functions[i];

			if ((devicefunc->base.type & 0xff) == INVENTORYFUNCTYPE_DEVICE) {
				if (active) {
					if (devicefunc->device & (DEVICE_NIGHTVISION | DEVICE_XRAYSCANNER | DEVICE_EYESPY | DEVICE_IRSCANNER)) {
						g_Vars.currentplayer->devicesactive &= ~(DEVICE_NIGHTVISION | DEVICE_XRAYSCANNER | DEVICE_EYESPY | DEVICE_IRSCANNER);
					}

					g_Vars.currentplayer->devicesactive |= devicefunc->device;
					return;
				}

				g_Vars.currentplayer->devicesactive &= ~devicefunc->device;
				return;
			}
		}
	}
}

u16 weapon_get_file_num(s32 weaponnum)
{
	struct weapon *weapon = NULL;

	if (weaponnum != -1) {
		weapon = g_Weapons[weaponnum];
	}

	if (weapon) {
		if (PLAYERCOUNT() >= 2) {
			return weapon->lo_model;
		}

		return weapon->hi_model;
	}

	return 0;
}

u16 weapon_get_file_num2(s32 weaponnum)
{
	return weapon_get_file_num(weaponnum);
}

void gset_populate_from_current_player(s32 handnum, struct gset *gset)
{
	gset->weaponnum = g_Vars.currentplayer->gunctrl.weaponnum;
	gset->weaponfunc = g_Vars.currentplayer->hands[handnum].gset.weaponfunc;
	gset->unk063a = g_Vars.currentplayer->hands[handnum].gset.unk063a;
	gset->unk0639 = g_Vars.currentplayer->hands[handnum].gset.unk0639;

	if (gset->weaponnum == WEAPON_MAULER) {
		gset->unk063a = g_Vars.currentplayer->hands[handnum].matmot1 * 10.0f;
	}

	if (gset->weaponnum == WEAPON_LASER) {
		gset->unk063a = g_Vars.currentplayer->hands[handnum].burstbullets & 0xff;
	}
}

struct inventory_ammo *gset_get_ammo_definition(struct gset *gset)
{
	struct weaponfunc *func = gset_get_weapon_function(gset);
	struct weapon *weapon = weapon_find_by_id(gset->weaponnum);

	if (func && func->ammoindex >= 0) {
		return weapon->ammos[func->ammoindex];
	}

	return NULL;
}

u8 gset_get_single_penetration(struct gset *gset)
{
	struct weaponfunc *func = gset_get_weapon_function(gset);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct weaponfunc_shoot *funcshoot = (struct weaponfunc_shoot *)func;
		return funcshoot->penetration;
	}

	return 0;
}

s32 hand_get_casing_eject(struct gset *gset)
{
	s32 result = 0;
	struct inventory_ammo *ammo = gset_get_ammo_definition(gset);

	if (ammo) {
		result = ammo->casingeject;
	}

	return result;
}

f32 gset_get_impact_force(struct gset *gset)
{
	struct weaponfunc *func = gset_get_weapon_function(gset);
	f32 result = 0;

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct weaponfunc_shoot *funcshoot = (struct weaponfunc_shoot *)func;
		result = funcshoot->impactforce;
	}

	return result;
}

f32 gset_get_damage(struct gset *gset)
{
	struct weaponfunc *func = gset_get_weapon_function(gset);
	f32 damage = 0;

	if (func) {
		if ((func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
			struct weaponfunc_shoot *shootfunc = (struct weaponfunc_shoot *)func;
			damage = shootfunc->damage;
		}

		if ((func->type & 0xff) == INVENTORYFUNCTYPE_MELEE) {
			struct weaponfunc_melee *meleefunc = (struct weaponfunc_melee *)func;
			damage = meleefunc->damage;

			if (gset->weaponnum == WEAPON_REAPER) {
				damage *= LVUPDATE60FREAL();
			}
		}

		if ((func->type & 0xff) == INVENTORYFUNCTYPE_THROW) {
			struct weaponfunc_throw *throwfunc = (struct weaponfunc_throw *)func;
			damage = throwfunc->damage;
		}
	}

	if (gset->weaponnum == WEAPON_MAULER) {
		damage = (gset->unk063a / 3.0f + 1.0f) * damage;
	}

	if (bgun_is_firing(HAND_LEFT) && bgun_is_firing(HAND_RIGHT)) {
		damage += damage;
	}

	return damage;
}

u8 gset_get_fireslot_duration(struct gset *gset)
{
#if VERSION >= VERSION_PAL_FINAL
	struct weaponfunc *func = gset_get_weapon_function(gset);
	u8 result = 0;

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct weaponfunc_shoot *funcshoot = (struct weaponfunc_shoot *)func;
		result = funcshoot->duration60;
	}

	if (result >= 4) {
		result = TICKS(result);
	}

	return result;
#else
	struct weaponfunc *func = gset_get_weapon_function(gset);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct weaponfunc_shoot *funcshoot = (struct weaponfunc_shoot *)func;
		return funcshoot->duration60;
	}

	return 0;
#endif
}

u16 gset_get_single_shoot_sound(struct gset *gset)
{
	struct weaponfunc *func = gset_get_weapon_function(gset);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct weaponfunc_shoot *funcshoot = (struct weaponfunc_shoot *)func;
		return funcshoot->shootsound;
	}

	return 0;
}

bool gset_has_function_flags(struct gset *gset, u32 flags)
{
	struct weaponfunc *func = gset_get_weapon_function(gset);

	if (func) {
		return (func->flags & flags) == flags;
	}

	return false;
}

s8 weapon_get_num_ticks_per_shot(u32 weaponnum, u32 funcindex)
{
	u32 stack[2];
	s32 result = 0;
	struct weapon *weapon = weapon_find_by_id(weaponnum);
	struct weaponfunc *func = weapon->functions[funcindex];

	if (func && func->type == INVENTORYFUNCTYPE_SHOOT_AUTOMATIC) {
		struct weaponfunc_shootauto *autofunc = (struct weaponfunc_shootauto *)func;

		result = 3600.0f / autofunc->maxrpm;
	}

#if VERSION != VERSION_PAL_BETA
	// PAL beta removes this check, only for it to be added back in PAL final
	if (result > 3) {
		result = TICKS(result);
	}
#endif

	return result;
}

u32 current_player_get_sight(void)
{
	struct weaponfunc *func = weapon_get_function_by_id(
			g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponnum,
			g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponfunc);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_MELEE) {
		return SIGHT_NONE;
	}

	if (cheat_is_active(CHEAT_CLASSICSIGHT)) {
		return SIGHT_CLASSIC;
	}

	switch (g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponnum) {
	case WEAPON_HORIZONSCANNER:
		return SIGHT_NONE;
	case WEAPON_NONE:
	case WEAPON_UNARMED:
	case WEAPON_FALCON2:
	case WEAPON_FALCON2_SILENCER:
	case WEAPON_DY357MAGNUM:
	case WEAPON_DY357LX:
	case WEAPON_CMP150:
	case WEAPON_CYCLONE:
	case WEAPON_RCP120:
	case WEAPON_SHOTGUN:
	case WEAPON_DEVASTATOR:
	case WEAPON_ROCKETLAUNCHER:
	case WEAPON_SLAYER:
	case WEAPON_COMBATKNIFE:
	case WEAPON_CROSSBOW:
	case WEAPON_TRANQUILIZER:
	case WEAPON_LASER:
	case WEAPON_GRENADE:
	case WEAPON_NBOMB:
	case WEAPON_TIMEDMINE:
	case WEAPON_PROXIMITYMINE:
	case WEAPON_REMOTEMINE:
	case WEAPON_ECMMINE:
		return SIGHT_DEFAULT;
	case WEAPON_FALCON2_SCOPE:
	case WEAPON_MAGSEC4:
	case WEAPON_SNIPERRIFLE:
	case WEAPON_LAPTOPGUN:
	case WEAPON_DRAGON:
	case WEAPON_K7AVENGER:
	case WEAPON_AR34:
	case WEAPON_SUPERDRAGON:
		return SIGHT_ZOOM;
	case WEAPON_MAULER:
	case WEAPON_REAPER:
		return SIGHT_SKEDAR;
	case WEAPON_PHOENIX:
	case WEAPON_CALLISTO:
	case WEAPON_FARSIGHT:
		return SIGHT_MAIAN;
	case WEAPON_PP9I:
	case WEAPON_CC13:
	case WEAPON_KL01313:
	case WEAPON_KF7SPECIAL:
	case WEAPON_ZZT:
	case WEAPON_DMC:
	case WEAPON_AR53:
	case WEAPON_RCP45:
		return SIGHT_CLASSIC;
	}

	return SIGHT_DEFAULT;
}

void gset_get_noise_settings(struct gset *gset, struct noisesettings *dst)
{
	struct noisesettings *settings = NULL;
	struct weaponfunc *func = gset_get_weapon_function(gset);

	if (func != NULL) {
		settings = func->noisesettings;
	}

	if (settings == NULL) {
		settings = &invnoisesettings_silent;
	}

	dst->minradius = settings->minradius;
	dst->maxradius = settings->maxradius;
	dst->incradius = settings->incradius;
	dst->decbasespeed = settings->decbasespeed;
	dst->decremspeed = settings->decremspeed;
}

struct guncmd *hand_get_equip_anim(struct gset *gset)
{
	struct weapon *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->equip_animation;
	}

	return NULL;
}

struct guncmd *hand_get_unequip_anim(struct gset *gset)
{
	struct weapon *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->unequip_animation;
	}

	return NULL;
}

struct guncmd *gset_get_pri_to_sec_anim(struct gset *gset)
{
	struct weapon *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->pritosec_animation;
	}

	return NULL;
}

struct guncmd *gset_get_sec_to_pri_anim(struct gset *gset)
{
	struct weapon *weapon = g_Weapons[gset->weaponnum];

	if (weapon) {
		return weapon->sectopri_animation;
	}

	return NULL;
}
