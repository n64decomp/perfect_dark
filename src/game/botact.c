#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/chr.h"
#include "game/propsnd.h"
#include "game/bondgun.h"
#include "game/gset.h"
#include "game/playermgr.h"
#include "game/botact.h"
#include "game/pad.h"
#include "game/padhalllv.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "data.h"
#include "types.h"

s32 botact_get_ammo_type_by_function(s32 weaponnum, s32 funcnum)
{
	if (weaponnum >= WEAPON_FALCON2 && weaponnum <= WEAPON_SUICIDEPILL) {
		struct ammodef *ammo = gset_get_ammodef(weaponnum, funcnum);

		if (ammo) {
			return ammo->type;
		}
	}

	return 0;
}

s32 botact_get_clip_capacity_by_function(s32 weaponnum, u32 funcnum)
{
	if (weaponnum >= WEAPON_FALCON2 && weaponnum <= WEAPON_SUICIDEPILL) {
		struct ammodef *ammo = gset_get_ammodef(weaponnum, funcnum);

		if (ammo) {
			return ammo->clipsize;
		}
	}

	return 0;
}

void botact_reload(struct chrdata *chr, s32 handnum, bool withsound)
{
	struct aibot *aibot = chr->aibot;

	aibot->timeuntilreload60[handnum] = 0;
	aibot->maulercharge[handnum] = 0;

	if (chr->weapons_held[handnum] && !botact_is_weapon_throwable(aibot->weaponnum, aibot->gunfunc)) {
		s32 capacity = botact_get_clip_capacity_by_function(aibot->weaponnum, aibot->gunfunc);

		if (capacity > 0) {
			s32 tryamount = capacity - aibot->loadedammo[handnum];
			s32 actualamount = botact_try_remove_ammo_from_reserve(aibot, aibot->weaponnum, aibot->gunfunc, tryamount);

			if (actualamount > 0) {
				aibot->loadedammo[handnum] += actualamount;

				if (withsound) {
					if (aibot->weaponnum == WEAPON_FARSIGHT) {
						ps_create(NULL, chr->prop, SFX_RELOAD_FARSIGHT, -1,
								-1, PSFLAG_AMBIENT, 0, PSTYPE_NONE, 0, -1, 0, -1, -1, -1, -1);
					} else {
						ps_create(NULL, chr->prop, SFX_RELOAD_DEFAULT, -1,
								-1, PSFLAG_AMBIENT, 0, PSTYPE_NONE, 0, -1, 0, -1, -1, -1, -1);
					}
				}
			}
		}
	}
}

s32 botact_get_ammo_quantity_by_weapon(struct aibot *aibot, s32 weaponnum, s32 funcnum, bool include_equipped)
{
	s32 qty = 0;
	s32 ammotype;
	s32 equippedammotype;

	if (aibot) {
		if (aibot->flags & BOTFLAG_UNLIMITEDAMMO) {
			ammotype = botact_get_ammo_type_by_function(weaponnum, funcnum);
			qty = bgun_get_capacity_by_ammotype(ammotype);
		} else {
			ammotype = botact_get_ammo_type_by_function(weaponnum, funcnum);
			qty = aibot->ammoheld[ammotype];
		}

		if (include_equipped) {
			ammotype = botact_get_ammo_type_by_function(weaponnum, funcnum);
			equippedammotype = botact_get_ammo_type_by_function(aibot->weaponnum, aibot->gunfunc);

			if (equippedammotype == ammotype) {
				qty += aibot->loadedammo[HAND_LEFT] + aibot->loadedammo[HAND_RIGHT];
			}
		}
	}

	return qty;
}

s32 botact_get_ammo_quantity_by_type(struct aibot *aibot, s32 ammotype, bool include_equipped)
{
	s32 qty = 0;

	if (aibot) {
		if (aibot->flags & BOTFLAG_UNLIMITEDAMMO) {
			qty = bgun_get_capacity_by_ammotype(ammotype);
		} else {
			qty = aibot->ammoheld[ammotype];
		}

		if (include_equipped
				&& botact_get_ammo_type_by_function(aibot->weaponnum, aibot->gunfunc) == ammotype) {
			qty += aibot->loadedammo[HAND_LEFT] + aibot->loadedammo[HAND_RIGHT];
		}
	}

	return qty;
}

/**
 * Attempt to remove the given quantity of ammo from the aibot's reserve and
 * return the amount actually removed.
 *
 * The amount removed will be less than the attempted amount if the aibot
 * doesn't have enough ammo in reserve.
 */
s32 botact_try_remove_ammo_from_reserve(struct aibot *aibot, s32 weaponnum, s32 funcnum, s32 tryqty)
{
	s32 amountremoved;
	s32 *ammoheld = &aibot->ammoheld[botact_get_ammo_type_by_function(weaponnum, funcnum)];

	if (!aibot || *ammoheld <= 0 || tryqty <= 0) {
		return 0;
	}

	if (aibot->flags & BOTFLAG_UNLIMITEDAMMO) {
		return tryqty;
	}

	dprint();
	*ammoheld -= tryqty;

	if (*ammoheld < 0) {
		amountremoved = tryqty + *ammoheld;
		*ammoheld = 0;

		if (dprint()) {
			return amountremoved;
		}
	} else {
		amountremoved = tryqty;
		dprint();
	}

	return amountremoved;
}

void botact_give_ammo_by_weapon(struct aibot *aibot, s32 weaponnum, s32 funcnum, s32 qty)
{
	s32 max;
	s32 *heldquantity = &aibot->ammoheld[botact_get_ammo_type_by_function(weaponnum, funcnum)];

	if (aibot && (aibot->flags & BOTFLAG_UNLIMITEDAMMO) == 0 && qty > 0) {
		dprint();
		*heldquantity += qty;

		if (heldquantity);

		max = bgun_get_capacity_by_ammotype(botact_get_ammo_type_by_function(weaponnum, funcnum));

		if (*heldquantity > max) {
			*heldquantity = max;
		}

		dprint();
	}
}

void botact_give_ammo_by_type(struct aibot *aibot, u32 ammotype, s32 quantity)
{
	s32 max;
	s32 *heldquantity = &aibot->ammoheld[ammotype];

	if (!aibot || (aibot->flags & BOTFLAG_UNLIMITEDAMMO) || quantity <= 0) {
		return;
	}

	dprint();

	*heldquantity += quantity;

	if (heldquantity);

	max = bgun_get_capacity_by_ammotype(ammotype);

	if (*heldquantity > max) {
		*heldquantity = max;
	}

	dprint();
}

bool botact_shoot_farsight(struct chrdata *chr, s32 arg1, struct coord *vector, struct coord *arg3)
{
	struct aibot *aibot;
	struct chrdata *oppchr;
	struct prop *oppprop;
	s32 i;
	s32 rand;
	f32 speed;

	if (!chr || !chr->aibot) {
		return false;
	}

	aibot = chr->aibot;

	if (aibot->weaponnum == WEAPON_FARSIGHT) {
		rand = random() % 100;

		// 3 in 10 chance of this passing
		if (rand < 30) {
			struct modelnode *node = NULL;
			struct model *model = NULL;
			s32 side = -1;
			s32 hitpart = HITPART_GENERAL;
			struct gset gset = {WEAPON_FARSIGHT, 0, 0, FUNC_PRIMARY};
			f32 damage = gset_get_damage(&gset);
			s32 fallback = 30;
			s32 value = fallback;

			for (i = 0; i < g_MpNumChrs; i++) {
				oppchr = g_MpAllChrPtrs[i];
				oppprop = g_MpAllChrPtrs[i]->prop;

				if (oppprop->type == PROPTYPE_PLAYER) {
					struct player *player = g_Vars.players[playermgr_get_player_num_by_prop(oppprop)];
					speed = player->speedforwards * player->speedforwards
							+ player->speedsideways * player->speedsideways;

					if (speed > 0) {
						value = fallback * 0.05f;
					}
				} else {
					if (oppchr->actiontype != ACT_STAND) {
						value = fallback * 0.05f;
					}
				}

				// value is 30 if player was still, or 1.5 if moving. So if 30
				// then this will always pass, or if 1.5 then this has 1 in 15
				// chance of passing.
				if (oppchr != chr
						&& value > rand
						&& pos_is_facing_pos(arg3, vector, &oppprop->pos, chr_get_hit_radius(oppchr))) {
					bgun_play_prop_hit_sound(&gset, oppprop, -1);

					if (oppchr->model && chr_get_shield(oppchr) > 0) {
						chr_calculate_shield_hit(oppchr, &oppprop->pos, vector, &node, &hitpart, &model, &side);
					}

					chr_emit_sparks(oppchr, oppprop, hitpart, &oppprop->pos, vector, chr);
					chr_damage_by_impact(oppchr, damage, vector, &gset, chr->prop, HITPART_GENERAL, oppprop, node, model, side, NULL);
				}
			}

			return true;
		}

		return false;
	}

	return true;
}

s32 botact_get_weapon_model(s32 weapon)
{
	return playermgr_get_model_of_weapon(weapon);
}

bool botact_is_weapon_throwable(s32 weaponnum, bool is_secondary)
{
	switch (weaponnum) {
	case WEAPON_LAPTOPGUN:
	case WEAPON_DRAGON:
	case WEAPON_COMBATKNIFE:
		return is_secondary;
	case WEAPON_GRENADE:
	case WEAPON_NBOMB:
	case WEAPON_TIMEDMINE:
	case WEAPON_PROXIMITYMINE:
	case WEAPON_REMOTEMINE:
		return true;
	}

	return false;
}

u32 botact_get_projectile_throw_interval(u32 weapon)
{
	switch (weapon) {
	case WEAPON_COMBATKNIFE:
		return TICKS(120);
	case WEAPON_GRENADE:
	case WEAPON_NBOMB:
		return TICKS(90);
	case WEAPON_CROSSBOW:
	case WEAPON_TRANQUILIZER:
	case WEAPON_LASER:
	case WEAPON_TIMEDMINE:
	case WEAPON_PROXIMITYMINE:
	case WEAPON_REMOTEMINE:
	default:
		return TICKS(60);
	}
}

s32 botact_get_weapon_by_ammo_type(s32 ammotype)
{
	switch (ammotype) {
	case AMMOTYPE_NBOMB:       return WEAPON_NBOMB;
	case AMMOTYPE_GRENADE:     return WEAPON_GRENADE;
	case AMMOTYPE_KNIFE:       return WEAPON_COMBATKNIFE;
	case AMMOTYPE_REMOTE_MINE: return WEAPON_REMOTEMINE;
	case AMMOTYPE_PROXY_MINE:  return WEAPON_PROXIMITYMINE;
	case AMMOTYPE_TIMED_MINE:  return WEAPON_TIMEDMINE;
	}

	return 0;
}

void botact_throw(struct chrdata *chr)
{
	struct coord sp228 = {0, 0, 0};
	Mtxf sp164;
	struct coord sp152;
	struct prop *prop = chr->prop;
	Mtxf sp84;
	f32 sp80 = chr_get_aimx_angle(chr);
	u32 stack;
	struct gset gset = {0};
	struct prop *target = chr_get_target_prop(chr);
	struct coord sp56;
	f32 mult;

	gset.weaponnum = chr->aibot->weaponnum;
	gset.weaponfunc = chr->aibot->gunfunc;

	if (chr_is_target_in_fov(chr, 30, 0)) {
		sp56.x = target->pos.x;
		sp56.z = target->pos.z;

		if (chr->aibot->weaponnum == WEAPON_GRENADE || chr->aibot->weaponnum == WEAPON_NBOMB) {
			sp56.y = target->chr->manground;
		} else {
			sp56.y = target->pos.y;

			if (target->type == PROPTYPE_PLAYER) {
				sp56.y -= 25.0f;
			}
		}

		chr_calculate_trajectory(&prop->pos, 16.666666f, &sp56, &sp152);
	} else {
		sp152.x = cosf(BADDTOR(20)) * sinf(sp80);
		sp152.y = sinf(BADDTOR(20));
		sp152.z = cosf(BADDTOR(20)) * cosf(sp80);
	}

	mult = 16.666666f;

	sp228.x = sp152.x * mult;
	sp228.y = sp152.y * mult;
	sp228.z = sp152.z * mult;

	mtx4_load_identity(&sp164);

	if (chr->aibot->weaponnum == WEAPON_COMBATKNIFE) {
		mtx4_load_z_rotation(BADDTOR(180) * 1.5f, &sp164);
		mtx4_load_x_rotation(BADDTOR(180), &sp84);
		mtx4_mult_mtx4_in_place(&sp84, &sp164);
	}

	mtx4_load_x_rotation(BADDTOR(20), &sp84);
	mtx00015be0(&sp84, &sp164);
	mtx4_load_y_rotation(sp80, &sp84);
	mtx00015be0(&sp84, &sp164);

	bgun_create_thrown_projectile2(chr, &gset, &prop->pos, prop->rooms, &sp164, &sp228);

	if (gset.weaponnum == WEAPON_REMOTEMINE) {
		chr->aibot->flags |= BOTFLAG_THREWREMOTEMINE;
	}
}

/**
 * Get the shoot interval of the given weapon, in time60.
 */
s32 botact_get_shoot_interval60(s32 weaponnum, s32 funcnum)
{
	s32 stack[2];
	s32 result = 1;
	struct weapondef *weapon = gset_get_weapondef(weaponnum);

	if (weapon) {
		struct funcdef *func = weapon->functions[funcnum];

		if (func) {
			if (func->type == INVENTORYFUNCTYPE_SHOOT_SINGLE) {
				struct funcdef_shoot *func2 = (struct funcdef_shoot *)func;
				result = func2->unk24 + func2->unk25;
			} else if (func->type == INVENTORYFUNCTYPE_SHOOT_AUTOMATIC) {
				struct funcdef_shoot *func2 = (struct funcdef_shoot *)func;
				result = func2->unk24 + func2->unk25;
			} else if (func->type == INVENTORYFUNCTYPE_SHOOT_PROJECTILE) {
				struct funcdef_shoot *func2 = (struct funcdef_shoot *)func;
				result = func2->unk24 + func2->unk25;
			} else if (func->type == INVENTORYFUNCTYPE_MELEE && weaponnum != WEAPON_REAPER) {
				result = 60;
			}
		}
	}

	return result;
}

/**
 * Do pathfinding for a bot's Slayer rocket in fly-by-wire mode and populate
 * the projectil's waypads.
 *
 * Return true if a route was found, false if not.
 */
bool botact_find_rocket_route(struct chrdata *chr, struct coord *frompos, struct coord *topos, RoomNum *fromrooms, RoomNum *torooms, struct projectile *projectile)
{
	struct waypoint *from = waypoint_find_closest_to_pos(frompos, fromrooms);
	struct waypoint *to = waypoint_find_closest_to_pos(topos, torooms);
	struct waypoint *waypoints[MAX_CHRWAYPOINTS];
	s32 numwaypoints;

	if (from && to) {
		nav_set_seed(CHRNAVSEED(chr), CHRNAVSEED(chr));
		numwaypoints = nav_find_route(from, to, waypoints, 6);
		nav_set_seed(0, 0);

		if (numwaypoints > 1) {
			s32 i = 0;

			while (waypoints[i]) {
				projectile->waypads[i] = waypoints[i]->padnum;
				i++;
			}

			projectile->step = 0;
			projectile->numwaypads = i;

			return true;
		}
	}

	return false;
}

/**
 * Populate pos with the position of the given pad
 * for a Slayer rocket in fly-by-wire mode.
 *
 * It's the ground position of the pad plus 1.5 metres.
 */
void botact_get_rocket_next_step_pos(u16 padnum, struct coord *pos)
{
	struct pad pad;
	RoomNum rooms[2];

	pad_unpack(padnum, PADFIELD_ROOM | PADFIELD_POS, &pad);

	rooms[0] = pad.room;
	rooms[1] = -1;

	pos->x = pad.pos.x;
	pos->y = cd_find_floor_y_colour_type_at_pos(&pad.pos, rooms, 0, 0) + 150;
	pos->z = pad.pos.z;
}

/**
 * Create a Slayer rocket in fly-by-wire mode (ie. remote controlled).
 */
void botact_create_slayer_rocket(struct chrdata *chr)
{
	struct weaponobj *rocket = weapon_create_projectile_from_weapon_num(MODEL_CHRSKROCKETMIS, WEAPON_SKROCKET, chr);

	if (rocket) {
		Mtxf sp260;
		Mtxf sp196;
		Mtxf sp132;
		struct coord sp120 = {0, 0, 0};
		f32 yrot;
		f32 xrot;
		struct coord sp100;

		yrot = chr_get_aimx_angle(chr);
		xrot = chr_get_aimy_angle(chr);

		sp100.x = cosf(xrot) * sinf(yrot);
		sp100.y = sinf(xrot);
		sp100.z = cosf(xrot) * cosf(yrot);

		mtx4_load_x_rotation(xrot, &sp196);
		mtx4_load_y_rotation(yrot, &sp132);
		mtx00015be0(&sp132, &sp196);
		mtx4_load_identity(&sp260);

		bgun0f09ebcc(&rocket->base, &chr->prop->pos, chr->prop->rooms, &sp196, &sp100, &sp260, chr->prop, &chr->prop->pos);

		if (rocket->base.hidden & OBJHFLAG_PROJECTILE) {
			struct prop *target = chr_get_target_prop(chr);
			rocket->timer240 = -1;
			rocket->base.projectile->unk010 = 7.5;
			rocket->base.projectile->unk014 = xrot;
			rocket->base.projectile->unk018 = yrot;
			rocket->base.projectile->smoketimer240 = 0;
			rocket->base.projectile->pickuptimer240 = 0x20000000;

			// Fire rocket sound
			ps_create(NULL, rocket->base.prop, SFX_LAUNCH_ROCKET_8053, -1,
					-1, 0, 0, PSTYPE_NONE, 0, -1, 0, -1, -1, -1, -1);

			if (!botact_find_rocket_route(chr, &chr->prop->pos, &target->pos, chr->prop->rooms, target->rooms, rocket->base.projectile)) {
				rocket->timer240 = 0; // blow up rocket
			} else {
				botact_get_rocket_next_step_pos(rocket->base.projectile->waypads[0], &rocket->base.projectile->nextsteppos);
				chr->aibot->skrocket = rocket->base.prop;
			}
		}
	}
}
