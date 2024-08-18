#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/bondwalk.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/footstep.h"
#include "game/game_006900.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/bondgun.h"
#include "game/player.h"
#include "game/inv.h"
#include "game/bondhead.h"
#include "game/playermgr.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "data.h"
#include "types.h"

void bwalk_init(void)
{
	u32 prevmode = g_Vars.currentplayer->bondmovemode;
	s32 i;

	g_Vars.currentplayer->bondmovemode = MOVEMODE_WALK;
	g_Vars.currentplayer->bondonground = 0;
	g_Vars.currentplayer->tank = NULL;
	g_Vars.currentplayer->unk1af0 = NULL;
	g_Vars.currentplayer->bondonturret = false;

	g_Vars.currentplayer->swaypos = 0;
	g_Vars.currentplayer->swayoffset = 0;
	g_Vars.currentplayer->swaytarget = 0;
	g_Vars.currentplayer->swayoffset0 = 0;
	g_Vars.currentplayer->swayoffset2 = 0;

	g_Vars.currentplayer->bdeltapos.x = 0;
	g_Vars.currentplayer->bdeltapos.y = -0.0001f;
	g_Vars.currentplayer->bdeltapos.z = 0;

	g_Vars.currentplayer->isfalling = false;
	g_Vars.currentplayer->fallstart = 0;

	g_Vars.currentplayer->gunextraaimx = 0;
	g_Vars.currentplayer->gunextraaimy = 0;

	g_Vars.currentplayer->bondforcespeed.x = 0;
	g_Vars.currentplayer->bondforcespeed.y = 0;
	g_Vars.currentplayer->bondforcespeed.z = 0;

	if (prevmode != MOVEMODE_WALK && prevmode != MOVEMODE_CUTSCENE) {
		g_Vars.currentplayer->sumcrouch = 0;
		g_Vars.currentplayer->crouchheight = 0;
		g_Vars.currentplayer->crouchtime240 = 0;
		g_Vars.currentplayer->crouchfall = 0;
		g_Vars.currentplayer->crouchpos = CROUCHPOS_STAND;
		g_Vars.currentplayer->autocrouchpos = CROUCHPOS_STAND;
		g_Vars.currentplayer->crouchspeed = 0;
		g_Vars.currentplayer->crouchoffset = 0;

#if VERSION < VERSION_NTSC_1_0
		bwalk_update_crouch_offset_real();
#endif

		g_Vars.currentplayer->guncloseroffset = 0;
	}

#if VERSION >= VERSION_NTSC_1_0
	bwalk_update_crouch_offset_real();
#endif

	if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		for (i = 0; i != 3; i++) {
			g_Vars.currentplayer->bondshotspeed.f[i] = 0;
		}

		g_Vars.currentplayer->speedsideways = 0;
		g_Vars.currentplayer->speedstrafe = 0;
		g_Vars.currentplayer->speedgo = 0;
		g_Vars.currentplayer->speedboost = 1;
		g_Vars.currentplayer->speedmaxtime60 = 0;
		g_Vars.currentplayer->speedforwards = 0;
		g_Vars.currentplayer->speedtheta = 0;
		g_Vars.currentplayer->speedthetacontrol = 0;
	}

	if (g_Vars.currentplayer->walkinitmove) {
		struct coord delta;
		mtx00016b58(&g_Vars.currentplayer->walkinitmtx,
				0, 0, 0,
				-g_Vars.currentplayer->bond2.unk1c.x, -g_Vars.currentplayer->bond2.unk1c.y, -g_Vars.currentplayer->bond2.unk1c.z,
				g_Vars.currentplayer->bond2.unk28.x, g_Vars.currentplayer->bond2.unk28.y, g_Vars.currentplayer->bond2.unk28.z);
		g_Vars.currentplayer->walkinitt = 0;
		g_Vars.currentplayer->walkinitt2 = 0;
		g_Vars.currentplayer->walkinitstart.x = g_Vars.currentplayer->prop->pos.x;
		g_Vars.currentplayer->walkinitstart.y = g_Vars.currentplayer->prop->pos.y;
		g_Vars.currentplayer->walkinitstart.z = g_Vars.currentplayer->prop->pos.z;

		delta.x = g_Vars.currentplayer->walkinitpos.x - g_Vars.currentplayer->prop->pos.x;
		delta.y = 0;
		delta.z = g_Vars.currentplayer->walkinitpos.z - g_Vars.currentplayer->prop->pos.z;

		prop_set_perim_enabled(g_Vars.currentplayer->hoverbike, false);
		bwalk_calculate_new_position_with_push(&delta, 0, true, 0, CDTYPE_ALL);
		prop_set_perim_enabled(g_Vars.currentplayer->hoverbike, true);
	} else if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		g_Vars.currentplayer->moveinitspeed.x = 0;
		g_Vars.currentplayer->moveinitspeed.y = 0;
		g_Vars.currentplayer->moveinitspeed.z = 0;
	}
}

void bwalk_set_sway_target(s32 value)
{
	g_Vars.currentplayer->swaytarget = value * 75.0f;
}

void bwalk_adjust_crouch_pos(s32 value)
{
	g_Vars.currentplayer->crouchpos += value;

	if (g_Vars.currentplayer->crouchpos < CROUCHPOS_SQUAT) {
		g_Vars.currentplayer->crouchpos = CROUCHPOS_SQUAT;
	} else if (g_Vars.currentplayer->crouchpos > CROUCHPOS_STAND) {
		g_Vars.currentplayer->crouchpos = CROUCHPOS_STAND;
	}
}

void bwalk0f0c3b38(struct coord *reltarget, struct defaultobj *obj)
{
	struct coord posunk;
	struct coord vector;
	struct coord tween;
	struct coord globalthinga;
	struct coord globalthingb;
	struct coord abstarget;

	abstarget.x = reltarget->x + g_Vars.currentplayer->prop->pos.x;
	abstarget.y = g_Vars.currentplayer->prop->pos.y;
	abstarget.z = reltarget->z + g_Vars.currentplayer->prop->pos.z;

#if VERSION >= VERSION_NTSC_1_0
	cd_get_edge(&globalthinga, &globalthingb, 223, "bondwalk.c");
#else
	cd_get_edge(&globalthinga, &globalthingb, 221, "bondwalk.c");
#endif

	vector.x = globalthingb.z - globalthinga.z;
	vector.y = 0;
	vector.z = globalthinga.x - globalthingb.x;

	if (vector.f[0] != 0 || vector.f[2] != 0) {
		guNormalize(&vector.x, &vector.y, &vector.z);
	} else {
		vector.z = 1;
	}

	func0f02e3dc(&globalthinga, &globalthingb, &abstarget, &vector, &posunk);

	tween.x = (abstarget.x - g_Vars.currentplayer->prop->pos.x) / g_Vars.lvupdate60freal;
	tween.y = 0;
	tween.z = (abstarget.z - g_Vars.currentplayer->prop->pos.z) / g_Vars.lvupdate60freal;

	func0f082e84(obj, &posunk, &vector, &tween, false);
}

/**
 * Attempt to move the current player up vertically by the given amount.
 *
 * Collision checks are done for the new location, and if successful the
 * player's positional values are updated.
 *
 * The function is called with amount = 0 when attempting to stand up from a
 * crouch, after increasing the player's bbox to the standing size.
 */
s32 bwalk_try_move_upwards(f32 amount)
{
	bool result;
	struct coord newpos;
	RoomNum rooms[8];
	u32 stack;
	u32 types;
	f32 ymax;
	f32 ymin;
	f32 radius;

	if (g_Vars.currentplayer->floorflags & GEOFLAG_SLOPE) {
		g_Vars.enableslopes = false;
	} else {
		g_Vars.enableslopes = true;
	}

	newpos.x = g_Vars.currentplayer->prop->pos.x;
	newpos.y = g_Vars.currentplayer->prop->pos.y + amount;
	newpos.z = g_Vars.currentplayer->prop->pos.z;

	types = g_Vars.bondcollisions ? CDTYPE_ALL : CDTYPE_BG;

	player_get_bbox(g_Vars.currentplayer->prop, &radius, &ymax, &ymin);
	los_find_final_room_exhaustive(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &newpos, rooms);
	bmove_find_entered_rooms_by_pos(g_Vars.currentplayer, &newpos, rooms);
	prop_set_perim_enabled(g_Vars.currentplayer->prop, false);

	ymin -= 0.1f;

	result = cd_test_volume(&newpos, radius, rooms, types, CHECKVERTICAL_YES,
			ymax - g_Vars.currentplayer->prop->pos.y,
			ymin - g_Vars.currentplayer->prop->pos.y);

	prop_set_perim_enabled(g_Vars.currentplayer->prop, true);

	if (result == CDRESULT_NOCOLLISION) {
		g_Vars.currentplayer->prop->pos.y = newpos.y;
		prop_deregister_rooms(g_Vars.currentplayer->prop);
		rooms_copy(rooms, g_Vars.currentplayer->prop->rooms);
	}

	g_Vars.enableslopes = true;

	return result;
}

bool bwalk_calculate_new_position(struct coord *vel, f32 rotateamount, bool apply, f32 extrawidth, s32 checktypes)
{
	s32 result = CDRESULT_NOCOLLISION;
	f32 halfradius;
	struct coord dstpos;
	RoomNum dstrooms[8];
	bool copyrooms = false;
	RoomNum sp64[22];
	s32 types;
	f32 ymax;
	f32 ymin;
	f32 radius;
	f32 xdiff;
	f32 zdiff;
	s32 i;

	if (g_Vars.currentplayer->floorflags & GEOFLAG_SLOPE) {
		g_Vars.enableslopes = false;
	} else {
		g_Vars.enableslopes = true;
	}

	dstpos.x = g_Vars.currentplayer->prop->pos.x;
	dstpos.y = g_Vars.currentplayer->prop->pos.y;
	dstpos.z = g_Vars.currentplayer->prop->pos.z;

	if (vel->x || vel->y || vel->z) {
		if (g_Vars.currentplayer->tank) {
			prop_set_perim_enabled(g_Vars.currentplayer->tank, false);
		}

		prop_set_perim_enabled(g_Vars.currentplayer->prop, false);

		dstpos.x += vel->x;
		dstpos.y += vel->y;
		dstpos.z += vel->z;

		types = g_Vars.bondcollisions ? checktypes : CDTYPE_BG;

		player_get_bbox(g_Vars.currentplayer->prop, &radius, &ymax, &ymin);
		radius += extrawidth;

		los_find_intersecting_rooms_exhaustive(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms,
				&dstpos, dstrooms, sp64, 20);

#if VERSION < VERSION_NTSC_1_0
		for (i = 0; dstrooms[i] != -1; i++) {
			if (dstrooms[i] == g_Vars.currentplayer->floorroom) {
				dstrooms[0] = g_Vars.currentplayer->floorroom;
				dstrooms[1] = -1;
				break;
			}
		}
#endif

		bmove_find_entered_rooms_by_pos(g_Vars.currentplayer, &dstpos, dstrooms);

		copyrooms = true;

		// Check if the player is moving at least half their radius along the
		// X or Z axis in a single frame. If less, only do a collision check for
		// the dst position. If more, do a halfway check too?
		xdiff = dstpos.x - g_Vars.currentplayer->prop->pos.x;
		zdiff = dstpos.z - g_Vars.currentplayer->prop->pos.z;
		halfradius = radius * 0.5f;

		if (xdiff > halfradius || zdiff > halfradius || xdiff < -halfradius || zdiff < -halfradius) {
			result = cd_exam_cyl_move06(&g_Vars.currentplayer->prop->pos,
					g_Vars.currentplayer->prop->rooms,
					&dstpos, dstrooms, radius, types, 1,
					ymax - g_Vars.currentplayer->prop->pos.y,
					ymin - g_Vars.currentplayer->prop->pos.y);

			if (result == CDRESULT_NOCOLLISION) {
				result = cd_exam_cyl_move02(&g_Vars.currentplayer->prop->pos,
						&dstpos, radius, dstrooms, types, true,
						ymax - g_Vars.currentplayer->prop->pos.y,
						ymin - g_Vars.currentplayer->prop->pos.y);
			}
		} else {
			result = cd_exam_cyl_move02(&g_Vars.currentplayer->prop->pos,
					&dstpos, radius, sp64, types, true,
					ymax - g_Vars.currentplayer->prop->pos.y,
					ymin - g_Vars.currentplayer->prop->pos.y);
		}

		prop_set_perim_enabled(g_Vars.currentplayer->prop, true);

		if (g_Vars.currentplayer->tank) {
			prop_set_perim_enabled(g_Vars.currentplayer->tank, true);
		}
	}

	if (result == CDRESULT_NOCOLLISION && apply) {
		f32 angle = g_Vars.currentplayer->vv_theta + (rotateamount * 360) / M_BADTAU;

		while (angle < 0) {
			angle += 360;
		}

		while (angle >= 360) {
			angle -= 360;
		}

		g_Vars.currentplayer->vv_theta = angle;

		g_Vars.currentplayer->prop->pos.x = dstpos.x;
		g_Vars.currentplayer->prop->pos.y = dstpos.y;
		g_Vars.currentplayer->prop->pos.z = dstpos.z;

		if (copyrooms) {
			prop_deregister_rooms(g_Vars.currentplayer->prop);
			rooms_copy(dstrooms, g_Vars.currentplayer->prop->rooms);
		}
	}

	g_Vars.enableslopes = true;

	return result;
}

bool bwalk_calculate_new_position_with_push(struct coord *delta, f32 rotateamount, bool apply, f32 extrawidth, s32 types)
{
	s32 result = bwalk_calculate_new_position(delta, rotateamount, apply, extrawidth, types);

	if (result != CDRESULT_NOCOLLISION) {
		struct prop *obstacle = cd_get_obstacle_prop();

		if (obstacle && g_Vars.lvupdate240 > 0) {
			if (obstacle->type == PROPTYPE_DOOR) {
				struct doorobj *door = obstacle->door;
				struct coord sp90;
				struct coord sp84;
				struct coord sp78;

				if (door->doorflags & DOORFLAG_DAMAGEONCONTACT) {
					if (!g_Vars.currentplayer->isdead) {
#if VERSION >= VERSION_NTSC_1_0
						cd_get_edge(&sp84, &sp78, 465, "bondwalk.c");
#else
						cd_get_edge(&sp84, &sp78, 460, "bondwalk.c");
#endif

						sp90.x = sp78.f[2] - sp84.f[2];
						sp90.y = 0;
						sp90.z = sp84.f[0] - sp78.f[0];

						if (sp90.f[0] || sp90.f[2]) {
							guNormalize(&sp90.x, &sp90.y, &sp90.z);
						} else {
							sp90.z = 1;
						}

						chr_damage_by_laser(g_Vars.currentplayer->prop->chr, 0.4f, &sp90, 0, g_Vars.currentplayer->prop);

						// Laser zap sound
						snd_start(var80095200, SFX_PICKUP_LASER, 0, -1, -1, -1, -1, -1);
					}
				}
			} else if (obstacle->type == PROPTYPE_CHR) {
				struct chrdata *chr = obstacle->chr;
				struct coord newpos;
				RoomNum newrooms[8];
				f32 movingdist;
				f32 xdist;
				f32 zdist;
				f32 disttochr;
				bool canpush = false;

				if (g_Vars.normmplayerisrunning) {
					if (chr_compare_teams(g_Vars.currentplayer->prop->chr, chr, COMPARE_FRIENDS)) {
						// AI bot on same team
						canpush = true;
					}
				} else if (chr->chrflags & CHRCFLAG_PUSHABLE) {
					if (g_Vars.antiplayernum < 0
							|| g_Vars.currentplayer != g_Vars.anti
							|| (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0) {
						canpush = true;
					}
				}

				if (canpush) {
					movingdist = sqrtf(delta->f[0] * delta->f[0] + delta->f[2] * delta->f[2]) / LVUPDATE60FREAL();

					xdist = obstacle->pos.x - g_Vars.currentplayer->prop->pos.x;
					zdist = obstacle->pos.z - g_Vars.currentplayer->prop->pos.z;

					if (xdist || zdist) {
						disttochr = sqrtf(xdist * xdist + zdist * zdist);

						if (disttochr > 0) {
							disttochr = movingdist / disttochr;

							xdist *= disttochr;
							zdist *= disttochr;

							chr->pushspeed[0] = 0.5f * xdist;
							chr->pushspeed[1] = 0.5f * zdist;

							newpos.x = obstacle->pos.x + chr->pushspeed[0] * LVUPDATE60FREAL();
							newpos.y = obstacle->pos.y;
							newpos.z = obstacle->pos.z + chr->pushspeed[1] * LVUPDATE60FREAL();

							chr_calculate_push_pos(chr, &newpos, newrooms, false);

							obstacle->pos.x = newpos.x;
							obstacle->pos.y = newpos.y;
							obstacle->pos.z = newpos.z;

							prop_deregister_rooms(obstacle);
							rooms_copy(newrooms, obstacle->rooms);
							chr_detect_rooms(chr);
							model_set_root_position(chr->model, &newpos);

							result = bwalk_calculate_new_position(delta, rotateamount, apply, extrawidth, types);
						}
					}
				}
			} else if (obstacle->type == PROPTYPE_PLAYER) {
				// empty
			} else if (obstacle->type == PROPTYPE_OBJ) {
				struct defaultobj *obj = obstacle->obj;
				bool dothething;

				if ((obj->hidden & OBJHFLAG_MOUNTED) == 0 && (obj->hidden & OBJHFLAG_GRABBED) == 0) {
					if (g_Vars.currentplayer->unk1af0 == 0 && obj->type == OBJTYPE_TANK) {
						g_Vars.currentplayer->tank = obstacle;
					} else if (obj->flags3 & OBJFLAG3_PUSHABLE) {
						g_Vars.currentplayer->speedmaxtime60 = 0;
						dothething = true;

						if ((obj->hidden & OBJHFLAG_PROJECTILE) &&
								(obj->projectile->flags & PROJECTILEFLAG_00001000)) {
							dothething = false;
						}

						if (dothething) {
							bwalk0f0c3b38(delta, obj);

							if (obj->hidden & OBJHFLAG_PROJECTILE && (obj->projectile->flags & PROJECTILEFLAG_SLIDING)) {
								bool somevalue;
								bool embedded = false;
								somevalue = projectile_tick(obj, &embedded);

								if (obj->hidden & OBJHFLAG_PROJECTILE) {
									obj->projectile->flags |= PROJECTILEFLAG_00001000;

									if (somevalue) {
										obj->projectile->flags |= PROJECTILEFLAG_00002000;
									} else {
										obj->projectile->flags &= ~PROJECTILEFLAG_00002000;
									}
								}

								if (somevalue) {
									result = bwalk_calculate_new_position(delta, rotateamount, apply, extrawidth, types);
								}
							}
						}
					}
				}
			}
		}
	}

	return result;
}

s32 bwalk0f0c4764(struct coord *delta, struct coord *arg1, struct coord *arg2, s32 types)
{
	s32 result = bwalk_calculate_new_position_with_push(delta, 0, true, 0, types);

	if (result == CDRESULT_COLLISION) {
#if VERSION >= VERSION_NTSC_1_0
		cd_get_edge(arg1, arg2, 607, "bondwalk.c");
#else
		cd_get_edge(arg1, arg2, 602, "bondwalk.c");
#endif
	}

	return result;
}

s32 bwalk0f0c47d0(struct coord *a, struct coord *b, struct coord *c,
		struct coord *d, struct coord *e, s32 types)
{
	struct coord quarter;
	bool result;

	if (cd_has_distance()) {
		f32 mult = cd_get_distance();
		quarter.x = a->x * mult * 0.25f;
		quarter.y = a->y * mult * 0.25f;
		quarter.z = a->z * mult * 0.25f;
		result = bwalk_calculate_new_position_with_push(&quarter, 0, true, 0, types);

		if (result == CDRESULT_NOCOLLISION) {
			return CDRESULT_NOCOLLISION;
		}

		if (result == CDRESULT_COLLISION) {
#if VERSION >= VERSION_NTSC_1_0
			cd_get_edge(d, e, 635, "bondwalk.c");
#else
			cd_get_edge(d, e, 630, "bondwalk.c");
#endif

			if (b->x != d->x
					|| b->y != d->y
					|| b->z != d->z
					|| c->x != e->x
					|| c->y != e->y
					|| c->z != e->z) {
				return CDRESULT_COLLISION;
			}
		}
	}

	return CDRESULT_ERROR;
}

s32 bwalk0f0c494c(struct coord *a, struct coord *b, struct coord *c, s32 types)
{
	if (b->f[0] != c->f[0] || b->f[2] != c->f[2]) {
		f32 tmp;
		struct coord sp38;
		struct coord sp2c;

		sp38.x = c->x - b->x;
		sp38.y = 0;
		sp38.z = c->z - b->z;

		tmp = sqrtf(sp38.f[0] * sp38.f[0] + sp38.f[2] * sp38.f[2]);

		sp38.x *= 1.0f / tmp;
		sp38.z *= 1.0f / tmp;

		tmp = a->f[0] * sp38.f[0] + a->f[2] * sp38.f[2];

		sp2c.x = sp38.x * tmp;
		sp2c.y = 0;
		sp2c.z = sp38.z * tmp;

		return bwalk_calculate_new_position_with_push(&sp2c, 0, true, 0, types);
	}

	return -1;
}

s32 bwalk0f0c4a5c(struct coord *arg0, struct coord *arg1, struct coord *arg2, s32 types)
{
	struct coord sp34;
	struct coord sp28;
	f32 ymax;
	f32 ymin;
	f32 tmp;
	f32 radius;

	player_get_bbox(g_Vars.currentplayer->prop, &radius, &ymax, &ymin);

	sp34.x = arg1->x - (g_Vars.currentplayer->prop->pos.x + arg0->f[0]);
	sp34.z = arg1->z - (g_Vars.currentplayer->prop->pos.z + arg0->f[2]);

	if (sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2] <= radius * radius) {
		if (arg1->f[0] != g_Vars.currentplayer->prop->pos.f[0] || arg1->f[2] != g_Vars.currentplayer->prop->pos.f[2]) {
			sp34.x = -(arg1->z - g_Vars.currentplayer->prop->pos.z);
			sp34.y = 0;
			sp34.z = arg1->x - g_Vars.currentplayer->prop->pos.x;

			tmp = sqrtf(sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2]);

			sp34.x = sp34.f[0] * (1.0f / tmp);
			sp34.z = sp34.f[2] * (1.0f / tmp);

			tmp = arg0->f[0] * sp34.f[0] + arg0->f[2] * sp34.f[2];

			sp34.x = sp34.x * tmp;
			sp34.z = sp34.z * tmp;

			sp28.x = sp34.x;
			sp28.y = 0;
			sp28.z = sp34.z;

			if (bwalk_calculate_new_position_with_push(&sp28, 0, true, 0, types) == CDRESULT_NOCOLLISION) {
				return true;
			}
		}
	} else {
		sp34.x = arg2->x - (g_Vars.currentplayer->prop->pos.x + arg0->f[0]);
		sp34.z = arg2->z - (g_Vars.currentplayer->prop->pos.z + arg0->f[2]);

		if (sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2] <= radius * radius) {
			if (arg2->f[0] != g_Vars.currentplayer->prop->pos.f[0] || arg2->f[2] != g_Vars.currentplayer->prop->pos.f[2]) {
				sp34.x = -(arg2->z - g_Vars.currentplayer->prop->pos.z);
				sp34.y = 0;
				sp34.z = arg2->x - g_Vars.currentplayer->prop->pos.x;

				tmp = sqrtf(sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2]);

				sp34.x = sp34.f[0] * (1.0f / tmp);
				sp34.z = sp34.f[2] * (1.0f / tmp);

				tmp = arg0->f[0] * sp34.f[0] + arg0->f[2] * sp34.f[2];

				sp34.x = sp34.x * tmp;
				sp34.z = sp34.z * tmp;

				sp28.x = sp34.x;
				sp28.y = 0;
				sp28.z = sp34.z;

				if (bwalk_calculate_new_position_with_push(&sp28, 0, true, 0, types) == CDRESULT_NOCOLLISION) {
					return true;
				}
			}
		}
	}

	return false;
}

void bwalk0f0c4d98(void)
{
	// empty
}

void bwalk_update_speed_sideways(f32 targetspeed, f32 accelspeed, s32 mult)
{
	if (g_Vars.normmplayerisrunning) {
		targetspeed = (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.unk1c + 25.0f) / 100 * targetspeed;
	}

	if (g_Vars.currentplayer->speedstrafe > targetspeed) {
		g_Vars.currentplayer->speedstrafe -= PALUPF(accelspeed * mult);

		if (g_Vars.currentplayer->speedstrafe < targetspeed) {
			g_Vars.currentplayer->speedstrafe = targetspeed;
		}
	} else if (g_Vars.currentplayer->speedstrafe < targetspeed) {
		g_Vars.currentplayer->speedstrafe += PALUPF(accelspeed * mult);

		if (g_Vars.currentplayer->speedstrafe > targetspeed) {
			g_Vars.currentplayer->speedstrafe = targetspeed;
		}
	}

	g_Vars.currentplayer->speedsideways = g_Vars.currentplayer->speedstrafe;
}

void bwalk_update_speed_forwards(f32 targetspeed, f32 accelspeed)
{
	if (g_Vars.normmplayerisrunning) {
		targetspeed = (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.unk1c + 25.0f) / 100 * targetspeed;
	}

	if (g_Vars.currentplayer->speedgo < targetspeed) {
		g_Vars.currentplayer->speedgo += accelspeed * g_Vars.lvupdate60freal;

		if (g_Vars.currentplayer->speedgo > targetspeed) {
			g_Vars.currentplayer->speedgo = targetspeed;
		}
	} else if (g_Vars.currentplayer->speedgo > targetspeed) {
		g_Vars.currentplayer->speedgo -= accelspeed * g_Vars.lvupdate60freal;

		if (g_Vars.currentplayer->speedgo < targetspeed) {
			g_Vars.currentplayer->speedgo = targetspeed;
		}
	}

	g_Vars.currentplayer->speedforwards = g_Vars.currentplayer->speedgo;
}

void bwalk_update_vertical(void)
{
	s32 i;
	f32 newfallspeed;
	f32 radius;
	f32 ymax;
	f32 ymin;
	f32 ground;
	bool onladder;
	bool onladder2 = false;
	RoomNum rooms[8];
	struct coord testpos;
	struct coord newpos;
	RoomNum newrooms[8];
	s32 newinlift;
	struct prop *lift = NULL;
	f32 sumground;
	f32 moveamount;
#if VERSION >= VERSION_NTSC_1_0
	f32 limit;
	f32 amount;
	struct prop *prop;
#endif
	f32 newmanground;
	f32 fallspeed;
	f32 eyeheight;
	f32 multiplier;
#if VERSION >= VERSION_NTSC_1_0
	struct defaultobj *obj;
#endif

	player_get_bbox(g_Vars.currentplayer->prop, &radius, &ymax, &ymin);

#if VERSION >= VERSION_NTSC_1_0
	// Maybe reset counter-op's radius - not sure why
	// Maybe it gets set to 0 when they die?
	if (g_Vars.antiplayernum >= 0
			&& g_Vars.currentplayer == g_Vars.anti
			&& g_Vars.currentplayer->bond2.radius != 30
			&& cd_test_volume(&g_Vars.currentplayer->prop->pos, 30, g_Vars.currentplayer->prop->rooms, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - g_Vars.currentplayer->prop->pos.y, ymin - g_Vars.currentplayer->prop->pos.y)) {
		g_Vars.currentplayer->prop->chr->radius = 30;
		g_Vars.currentplayer->bond2.radius = 30;
		radius = 30;
	}
#endif

	// Determine if player is on a ladder
	// If this comes up false, a second check is done... maybe checking if the
	// player is touching a ladder from a room which shares the same coordinate
	// space?
	onladder = cd_find_ladder(&g_Vars.currentplayer->prop->pos,
			radius * 1.2f, ymax - g_Vars.currentplayer->prop->pos.y,
			g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->prop->pos.y + 1,
			g_Vars.currentplayer->prop->rooms, GEOFLAG_LADDER | GEOFLAG_LADDER_PLAYERONLY,
			&g_Vars.currentplayer->laddernormal);

	if (!onladder) {
		testpos.x = g_Vars.currentplayer->prop->pos.x;
		testpos.y = g_Vars.currentplayer->prop->pos.y - 10;
		testpos.z = g_Vars.currentplayer->prop->pos.z;
		rooms_copy(g_Vars.currentplayer->prop->rooms, rooms);
		bmove_find_entered_rooms_by_pos(g_Vars.currentplayer, &testpos, rooms);
		onladder2 = cd_find_ladder(&g_Vars.currentplayer->prop->pos,
				radius * 1.1f, ymax - g_Vars.currentplayer->prop->pos.y,
				g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->prop->pos.y - 10,
				rooms, GEOFLAG_LADDER | GEOFLAG_LADDER_PLAYERONLY, &g_Vars.currentplayer->laddernormal);
	}

	testpos.x = g_Vars.currentplayer->prop->pos.x;
	testpos.y = g_Vars.currentplayer->prop->pos.y;
	testpos.z = g_Vars.currentplayer->prop->pos.z;

	if (g_Vars.currentplayer->inlift) {
		testpos.y -= g_Vars.currentplayer->crouchheight + g_Vars.currentplayer->crouchoffsetrealsmall;
	}

	rooms_copy(g_Vars.currentplayer->prop->rooms, rooms);
	bmove_find_entered_rooms_by_pos(g_Vars.currentplayer, &testpos, rooms);
	ground = cd_find_ground_info_at_cyl(&testpos, g_Vars.currentplayer->bond2.radius, rooms,
			&g_Vars.currentplayer->floorcol, &g_Vars.currentplayer->floortype,
			&g_Vars.currentplayer->floorflags, &g_Vars.currentplayer->floorroom,
			&newinlift, &lift);
	ground += g_Vars.currentplayer->bondonground;

	if (ground < -30000) {
		ground = -30000;
	}

#if PIRACYCHECKS
	if (g_Vars.currentplayer->inlift && newinlift == false) {
		// Exiting a lift
		piracy_restore();
	}
#endif

	if (g_Vars.currentplayer->inlift && newinlift && g_Vars.currentplayer->onladder == false) {
		// Remaining in a lift
		moveamount = ground - g_Vars.currentplayer->vv_ground;

#if VERSION >= VERSION_NTSC_1_0
		if (moveamount != 0)
#endif
		{
			// The lift is moving
			if (g_Vars.currentplayer->isfalling == false && lift == g_Vars.currentplayer->lift) {
				if (g_Vars.currentplayer->liftground - g_Vars.currentplayer->vv_manground < 1.0f
						&& g_Vars.currentplayer->liftground - g_Vars.currentplayer->vv_manground > -1.0f) {
					// It's actually moving, and not a floating point precision issue
					g_Vars.currentplayer->vv_ground += moveamount;

					if (moveamount > 0
							|| lift == NULL
							|| lift->obj == NULL
							|| (lift->obj->flags & OBJFLAG_CHOPPER_INACTIVE) == 0
							|| bwalk_try_move_upwards(moveamount) == CDRESULT_NOCOLLISION) {
						// Going up
						g_Vars.currentplayer->vv_manground += moveamount;
						g_Vars.currentplayer->sumground = g_Vars.currentplayer->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);
					}
				}
			}

			if (g_Vars.currentplayer->walkinitmove) {
				g_Vars.currentplayer->walkinitstart.y += moveamount;
			}
		}
	} else {
		lift = NULL;
	}

	g_Vars.currentplayer->inlift = newinlift;

	if (newinlift) {
		g_Vars.currentplayer->liftground = ground;
	}

	g_Vars.currentplayer->lift = lift;

	// Ladders
	if (g_Vars.currentplayer->onladder) {
		if (g_Vars.currentplayer->ladderupdown >= 0 ||
				(ground <= g_Vars.currentplayer->vv_manground &&
				 ground <= g_Vars.currentplayer->vv_manground + g_Vars.currentplayer->ladderupdown)) {
			// Still on ladder
			if (bwalk_try_move_upwards(g_Vars.currentplayer->ladderupdown) == CDRESULT_NOCOLLISION) {
				g_Vars.currentplayer->vv_manground += g_Vars.currentplayer->ladderupdown;
			}
		} else {
			if (bwalk_try_move_upwards(ground - g_Vars.currentplayer->vv_manground) == CDRESULT_NOCOLLISION) {
				g_Vars.currentplayer->vv_manground = ground;
				onladder = false;
			}
		}
	}

	g_Vars.currentplayer->onladder = onladder;

	if (g_Vars.currentplayer->onladder) {
		g_Vars.currentplayer->vv_ground = g_Vars.currentplayer->vv_manground;
	} else if (onladder2 == false) {
		g_Vars.currentplayer->vv_ground = ground;
	}

	// Standing on flat ground, or going up stairs, ledges or ramps
	// In other words, not falling
	if (g_Vars.currentplayer->bdeltapos.y >= 0.0f
			|| g_Vars.currentplayer->vv_ground > g_Vars.currentplayer->vv_manground) {
		g_Vars.currentplayer->sumground = g_Vars.currentplayer->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);

		for (i = 0; i < g_Vars.lvupdate240; i++) {
			g_Vars.currentplayer->sumground =
				g_Vars.currentplayer->sumground * (PAL ? 0.94559997320175f : 0.9545f) + g_Vars.currentplayer->vv_ground;
		}

		if (g_Vars.currentplayer->vv_manground < g_Vars.currentplayer->vv_ground) {
			// Feet are lower than the ground
			sumground = g_Vars.currentplayer->sumground * (PAL ? 0.054400026798248f : 0.045499980449677f);

			if (sumground < g_Vars.currentplayer->vv_ground - 50) {
				sumground = g_Vars.currentplayer->vv_ground - 50;
			}

			if (bwalk_try_move_upwards(sumground - g_Vars.currentplayer->vv_manground) == CDRESULT_NOCOLLISION) {
				g_Vars.currentplayer->vv_manground = sumground;
			}
#if VERSION >= VERSION_NTSC_1_0
			else {
				// Not enough room above. If on a hoverbike, blow it up
				prop = cd_get_obstacle_prop();

				if (prop
						&& g_Vars.currentplayer->prop->pos.y < prop->pos.y
						&& prop->type == PROPTYPE_OBJ) {
					obj = prop->obj;

					if (obj->modelnum == MODEL_HOVBIKE) {
						amount = (obj->maxdamage - obj->damage + 1) / 250.0f;
						obj->flags &= ~OBJFLAG_INVINCIBLE;
						obj_damage(obj, amount, &obj->prop->pos, WEAPON_REMOTEMINE, -1);
					}
				}
			}
#endif
		}

		// Kill player if standing on tile with GEOFLAG_DIE
		if ((g_Vars.currentplayer->floorflags & GEOFLAG_DIE)
				&& g_Vars.currentplayer->vv_manground - 20.0f < g_Vars.currentplayer->vv_ground
				&& g_Vars.currentplayer->onladder == false
				&& onladder2 == false) {
			player_die(true);
		}
	}

	if (g_Vars.currentplayer->vv_manground > g_Vars.currentplayer->vv_ground) {
		// Not standing on ground - probably falling, or on an object of some sort
		fallspeed = g_Vars.currentplayer->bdeltapos.y;
		newmanground = g_Vars.currentplayer->vv_manground;

		if (debug_is_turbo_mode_enabled()
				&& g_Vars.currentplayer->bondforcespeed.x == 0
				&& g_Vars.currentplayer->bondforcespeed.z == 0) {
			multiplier = 0.277777777f * 5;
		} else {
			multiplier = 0.277777777f;
		}

		newfallspeed = fallspeed - g_Vars.lvupdate60freal * multiplier;
		newmanground += g_Vars.lvupdate60freal * (fallspeed + newfallspeed) * 0.5f;
		fallspeed = newfallspeed;

		if (newmanground < g_Vars.currentplayer->vv_ground) {
			newfallspeed = g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->vv_ground;
			newmanground = g_Vars.currentplayer->vv_ground;

			fallspeed = sqrtf(g_Vars.currentplayer->bdeltapos.y *
					g_Vars.currentplayer->bdeltapos.y +
					(((newfallspeed + newfallspeed) * 0.277777777f) / 60.0f) * 60.0f);
			fallspeed = -fallspeed;
		}

		if (bwalk_try_move_upwards(newmanground - g_Vars.currentplayer->vv_manground) == CDRESULT_NOCOLLISION) {
			// Falling
			g_Vars.currentplayer->vv_manground = newmanground;
			g_Vars.currentplayer->bdeltapos.y = fallspeed;

			if (g_Vars.currentplayer->isfalling == false) {
				// Just started falling
				g_Vars.currentplayer->isfalling = true;
				g_Vars.currentplayer->fallstart = g_Vars.lvframe60;
			} else {
				if (g_Vars.lvframe60 - g_Vars.currentplayer->fallstart > TICKS(240)) {
					// Have been falling for 4 seconds
					player_die(true);
				}
			}
		} else {
			// Not falling
#if VERSION >= VERSION_NTSC_1_0
			if (g_Vars.normmplayerisrunning == false
					&& g_Vars.currentplayer->vv_ground < g_Vars.currentplayer->vv_manground - 30) {
				// Not falling - but still at least 30 units off the ground.
				// Must be something in the way...
				prop = cd_get_obstacle_prop();

				if (prop) {
					if (prop->type == PROPTYPE_CHR) {
						// Landed on top of a chr
						if (prop->chr->inlift) {
							chr_yeet_from_pos(prop->chr, &g_Vars.currentplayer->prop->pos, 0);
						}
					} else if (prop->type == PROPTYPE_PLAYER) {
						// Landed on top of a player
						u32 prevplayernum = g_Vars.currentplayernum;
						set_current_player_num(playermgr_get_player_num_by_prop(prop));

						if (g_Vars.currentplayer->inlift) {
							player_die_by_shooter(prevplayernum, true);
						}

						set_current_player_num(prevplayernum);
					}
				}
			}
#endif

			g_Vars.currentplayer->bdeltapos.y = VERSION >= VERSION_NTSC_1_0 ? 0.0f : 0;

			if (g_Vars.currentplayer->isfalling) {
				g_Vars.currentplayer->isfalling = false;
			}

			if (g_Vars.currentplayer->vv_manground <= -30000) {
				player_die(true);
			}
		}
	} else {
		// Not falling
		if (g_Vars.currentplayer->isfalling) {
			g_Vars.currentplayer->isfalling = false;
		}

		if (g_Vars.currentplayer->vv_manground <= -30000) {
			player_die(true);
		}
	}

	if (g_Vars.currentplayer->bdeltapos.y < 0 &&
			g_Vars.currentplayer->vv_manground <= g_Vars.currentplayer->vv_ground) {
		// Landing after a fall
		if (g_Vars.currentplayer->isfalling) {
			g_Vars.currentplayer->isfalling = false;
		}

		// I suspect these crouch fields are related to the recovery during
		// landing. Eg. The faster the fall speed, the longer Jo will take to
		// stand back to full height again.
		if (g_Vars.currentplayer->bdeltapos.y < -13.333333f) {
			g_Vars.currentplayer->crouchtime240 = TICKS(60);
			g_Vars.currentplayer->crouchfall = -90;
		} else if (g_Vars.currentplayer->bdeltapos.y < -5.0f) {
			g_Vars.currentplayer->crouchtime240 = TICKS(60);
			g_Vars.currentplayer->crouchfall =
				(-5.0f - g_Vars.currentplayer->bdeltapos.y) * -90.0f / 8.333333f;
		}

		if (g_Vars.currentplayer->bdeltapos.y < -6.0f) {
			// Play footstep sounds
			s32 sound;
			struct chrdata *chr = g_Vars.currentplayer->prop->chr;
			chr->floortype = g_Vars.currentplayer->floortype;
			chr->footstep = 1;

			sound = footstep_choose_sound(chr, true);

			if (sound != -1) {
				if (sound != -1) {
					ps_create(NULL, g_Vars.currentplayer->prop, sound,
							-1, -1, PSFLAG_0400 | PSFLAG_IGNOREROOMS, 0, PSTYPE_NONE, 0, -1, NULL, -1, -1, -1, -1);
				}

				chr->footstep = 2;
				sound = footstep_choose_sound(chr, true);

				if (sound != -1) {
					ps_create(NULL, g_Vars.currentplayer->prop, sound,
							-1, -1, PSFLAG_0400 | PSFLAG_IGNOREROOMS, 0, PSTYPE_NONE, 0, -1, NULL, -1, -1, -1, -1);
				}
			}

			if (g_Vars.mplayerisrunning == false
					&& (chr->headnum == HEAD_DARK_COMBAT || chr->headnum == HEAD_DARK_FROCK)
					&& g_Vars.lvframe60 - g_Vars.currentplayer->fallstart > TICKS(40)) {
				// Play Jo landing grunt
				s32 sounds[] = {
					SFX_JO_LANDING_046F,
					SFX_JO_LANDING_05B6,
					SFX_JO_LANDING_05B7
				};

				ps_create(NULL, g_Vars.currentplayer->prop, sounds[random() % 3],
						-1, -1, PSFLAG_0400 | PSFLAG_IGNOREROOMS, 0, PSTYPE_NONE, 0, -1, NULL, -1, -1, -1, -1);
			}
		}

		g_Vars.currentplayer->bdeltapos.y = 0;
	}

	// Decrease crouchtime240 for this tick.
	// If reached 0 and crouchfall is negative, start increasing
	// crouchfall over the next several ticks until it reaches 0.
	for (i = 0; i < g_Vars.lvupdate240; i++) {
		if (g_Vars.currentplayer->crouchtime240 > 0) {
			g_Vars.currentplayer->sumcrouch =
				g_Vars.currentplayer->sumcrouch * (PAL ? 0.93540000915527f : 0.9456f) + g_Vars.currentplayer->crouchfall;
			g_Vars.currentplayer->crouchtime240--;
		} else {
			if (g_Vars.currentplayer->crouchfall < 0) {
				g_Vars.currentplayer->crouchfall -= (PAL ? -1.3636363744736f : -1.125f);

				if (g_Vars.currentplayer->crouchfall >= 0) {
					g_Vars.currentplayer->crouchfall = 0;
				}
			}

			g_Vars.currentplayer->sumcrouch =
				g_Vars.currentplayer->sumcrouch * (PAL ? 0.93540000915527f : 0.9456f) + g_Vars.currentplayer->crouchfall;
		}
	}

	{
		g_Vars.currentplayer->crouchheight = g_Vars.currentplayer->sumcrouch * (PAL ? 0.064599990844727f : 0.054400026798248f);
		g_Vars.currentplayer->vv_height =
			(g_Vars.currentplayer->headpos.y / g_Vars.currentplayer->standheight)
			* g_Vars.currentplayer->vv_eyeheight;

		eyeheight = g_Vars.currentplayer->vv_height +
			g_Vars.currentplayer->crouchoffsetrealsmall +
			g_Vars.currentplayer->crouchheight *
			g_Vars.currentplayer->vv_eyeheight * 0.0062893079593778f;

		if (eyeheight < 30) {
			eyeheight = 30;
		}

		newpos.x = g_Vars.currentplayer->prop->pos.x;
		newpos.y = g_Vars.currentplayer->vv_manground + eyeheight;
		newpos.z = g_Vars.currentplayer->prop->pos.z;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (newpos.y < g_Vars.currentplayer->vv_ground + 10) {
		newpos.y = g_Vars.currentplayer->vv_ground + 10;
	}
#endif

	if (newpos.x != g_Vars.currentplayer->prop->pos.x
			|| newpos.y != g_Vars.currentplayer->prop->pos.y
			|| newpos.z != g_Vars.currentplayer->prop->pos.z) {
		los_find_final_room_exhaustive(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &newpos, newrooms);

		g_Vars.currentplayer->prop->pos.x = newpos.x;
		g_Vars.currentplayer->prop->pos.y = newpos.y;
		g_Vars.currentplayer->prop->pos.z = newpos.z;

		prop_deregister_rooms(g_Vars.currentplayer->prop);
		rooms_copy(newrooms, g_Vars.currentplayer->prop->rooms);
	}
}

void bwalk_apply_crouch_speed(void)
{
	if (bmove_get_crouch_pos() == CROUCHPOS_DUCK) {
		g_Vars.currentplayer->speedforwards *= 0.5f;
		g_Vars.currentplayer->speedsideways *= 0.5f;
	} else if (bmove_get_crouch_pos() == CROUCHPOS_SQUAT) {
		g_Vars.currentplayer->speedforwards *= 0.35f;
		g_Vars.currentplayer->speedsideways *= 0.35f;
	}
}

void bwalk_update_crouch_offset_real(void)
{
	if (g_Vars.currentplayer->vv_eyeheight + -90.0f * g_Vars.currentplayer->vv_eyeheight * (1.0f / 159.0f) < 69.0f) {
		g_Vars.currentplayer->crouchoffsetreal = g_Vars.currentplayer->crouchoffset * ((69.0f - g_Vars.currentplayer->vv_eyeheight) / -90.0f);
	} else {
		g_Vars.currentplayer->crouchoffsetreal = g_Vars.currentplayer->crouchoffset * g_Vars.currentplayer->vv_eyeheight * (1.0f / 159.0f);
	}

	if (cheat_is_active(CHEAT_SMALLJO)) {
		g_Vars.currentplayer->crouchoffsetsmall = 69.0f - g_Vars.currentplayer->vv_eyeheight;
		g_Vars.currentplayer->crouchoffsetrealsmall = 69.0f - g_Vars.currentplayer->vv_eyeheight;
	} else {
		g_Vars.currentplayer->crouchoffsetsmall = g_Vars.currentplayer->crouchoffset;
		g_Vars.currentplayer->crouchoffsetrealsmall = g_Vars.currentplayer->crouchoffsetreal;
	}
}

void bwalk_update_crouch_offset(void)
{
	f32 targetoffset = 0;

	if (bmove_get_crouch_pos() == CROUCHPOS_SQUAT) {
		targetoffset = -90;
	} else if (bmove_get_crouch_pos() == CROUCHPOS_DUCK) {
		targetoffset = -45;
	} else if (bmove_get_crouch_pos() == CROUCHPOS_STAND) {
		// empty
	}

	if (targetoffset != g_Vars.currentplayer->crouchoffset) {
		f32 prevcrouchoffset = g_Vars.currentplayer->crouchoffset;
		f32 prevcrouchoffsetreal = g_Vars.currentplayer->crouchoffsetreal;
		f32 prevcrouchoffsetsmall = g_Vars.currentplayer->crouchoffsetsmall;
		f32 prevcrouchoffsetrealsmall = g_Vars.currentplayer->crouchoffsetrealsmall;

		// f32 *frac, f32 maxfrac, f32 *fracspeed, f32 accel, f32 decel, f32 maxspeed
		apply_speed(&g_Vars.currentplayer->crouchoffset, targetoffset,
				&g_Vars.currentplayer->crouchspeed, PALUPF(0.5f), PALUPF(0.5f), PALUPF(5.0f));

		bwalk_update_crouch_offset_real();

		if (bwalk_try_move_upwards(0) == CDRESULT_COLLISION) {
			// Crouch adjustment is blocked by ceiling
			g_Vars.currentplayer->crouchoffset = prevcrouchoffset;
			g_Vars.currentplayer->crouchoffsetreal = prevcrouchoffsetreal;
			g_Vars.currentplayer->crouchoffsetsmall = prevcrouchoffsetsmall;
			g_Vars.currentplayer->crouchoffsetrealsmall = prevcrouchoffsetrealsmall;
			g_Vars.currentplayer->crouchspeed = 0;
			bwalk_adjust_crouch_pos(-1);
		}
	}

	if (targetoffset == g_Vars.currentplayer->crouchoffset) {
		g_Vars.currentplayer->crouchspeed = 0;
	}

	g_Vars.currentplayer->guncloseroffset = g_Vars.currentplayer->crouchoffset / -90;
}

void bwalk_update_theta(void)
{
	f32 mult;
	f32 rotateamount;
	struct coord delta = {0, 0, 0};

	// Turn speed is calculated from the chr's height
	mult = 159.0f / g_Vars.currentplayer->vv_eyeheight;
	rotateamount = g_Vars.currentplayer->speedtheta * mult
		* g_Vars.lvupdate60freal * 0.0174505133f * 3.5f;

	bwalk_calculate_new_position_with_push(&delta, rotateamount, true, 0, CDTYPE_ALL);
}

void bwalk0f0c63bc(struct coord *arg0, u32 arg1, s32 types)
{
	struct coord sp100;
	struct coord sp88;

	g_Vars.currentplayer->bondonturret = false;
	g_Vars.currentplayer->autocrouchpos = CROUCHPOS_STAND;

	bwalk0f0c4d98();

	if (bwalk0f0c4764(arg0, &sp100, &sp88, types) == CDRESULT_COLLISION) {
		struct coord sp76;
		struct coord sp64;

		s32 result = bwalk0f0c47d0(arg0, &sp100, &sp88, &sp76, &sp64, types);

		if (result >= CDRESULT_NOCOLLISION || result <= CDRESULT_ERROR) {
			if (result >= CDRESULT_NOCOLLISION) {
				bwalk0f0c4d98();
			}

			if (arg1
					&& bwalk0f0c494c(arg0, &sp100, &sp88, types) <= CDRESULT_COLLISION
					&& bwalk0f0c4a5c(arg0, &sp100, &sp88, types) <= CDRESULT_COLLISION) {
				// empty
			}
		} else if (result == CDRESULT_COLLISION) {
			struct coord sp48;
			struct coord sp36;

			if (bwalk0f0c47d0(arg0, &sp76, &sp64, &sp48, &sp36, types) >= CDRESULT_NOCOLLISION) {
				bwalk0f0c4d98();
			}

			if (arg1
					&& bwalk0f0c494c(arg0, &sp76, &sp64, types) <= CDRESULT_COLLISION
					&& bwalk0f0c494c(arg0, &sp100, &sp88, types) <= CDRESULT_COLLISION
					&& bwalk0f0c4a5c(arg0, &sp76, &sp64, types) <= CDRESULT_COLLISION) {
				bwalk0f0c4a5c(arg0, &sp100, &sp88, types);
			}
		}
	}

	bwalk0f0c4d98();
}

void bwalk_update_prev_pos(void)
{
	g_Vars.currentplayer->bondprevpos.x = g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->bondprevpos.y = g_Vars.currentplayer->prop->pos.y;
	g_Vars.currentplayer->bondprevpos.z = g_Vars.currentplayer->prop->pos.z;

	rooms_copy(g_Vars.currentplayer->prop->rooms, g_Vars.currentplayer->bondprevrooms);
}

void bwalk_handle_activate(void)
{
	if (g_Vars.currentplayer->walkinitmove) {
		g_Vars.currentplayer->bondactivateorreload = 0;
	}
}

void bwalk_apply_move_data(struct movedata *data)
{
	if (g_Vars.currentplayer->walkinitmove == false) {
		// Sideways
		if (data->digitalstepleft) {
			bwalk_update_speed_sideways(-1, 0.2f, data->digitalstepleft);
		} else if (data->digitalstepright) {
			bwalk_update_speed_sideways(1, 0.2f, data->digitalstepright);
		} else if (data->unk14 == false) {
			bwalk_update_speed_sideways(0, 0.2f, g_Vars.lvupdate60);
		}

		if (data->unk14) {
			bwalk_update_speed_sideways(data->analogstrafe * 0.014285714365542f, 0.2f, g_Vars.lvupdate60);
		}

		// Forward/back
		if (data->digitalstepforward) {
			bwalk_update_speed_forwards(1, 1);
			g_Vars.currentplayer->speedmaxtime60 += g_Vars.lvupdate60;
		} else if (data->digitalstepback) {
			bwalk_update_speed_forwards(-1, 1);
		} else if (data->canlookahead == false) {
			bwalk_update_speed_forwards(0, 1);
		}

		if (data->canlookahead) {
			bwalk_update_speed_forwards(data->analogwalk * 0.014285714365542f, 1);

			if (data->analogwalk > 60) {
				g_Vars.currentplayer->speedmaxtime60 += g_Vars.lvupdate60;
			} else {
				g_Vars.currentplayer->speedmaxtime60 = 0;
			}
		}

		// Force speeds to range -1 to 1
		if (g_Vars.currentplayer->speedforwards > 1) {
			g_Vars.currentplayer->speedforwards = 1;
		}

		if (g_Vars.currentplayer->speedforwards < -1) {
			g_Vars.currentplayer->speedforwards = -1;
		}

		if (g_Vars.currentplayer->speedsideways > 1) {
			g_Vars.currentplayer->speedsideways = 1;
		}

		if (g_Vars.currentplayer->speedsideways < -1) {
			g_Vars.currentplayer->speedsideways = -1;
		}

		g_Vars.currentplayer->speedforwards *= 1.08f;
		g_Vars.currentplayer->speedforwards *= g_Vars.currentplayer->speedboost;

		if ((data->canlookahead == false && data->digitalstepforward == false) ||
				bmove_get_crouch_pos() != CROUCHPOS_STAND) {
			g_Vars.currentplayer->speedmaxtime60 = 0;
		}

		if (data->rleanleft) {
			bwalk_set_sway_target(-1);
		} else if (data->rleanright) {
			bwalk_set_sway_target(1);
		} else {
			bwalk_set_sway_target(0);
		}

		while (data->crouchdown-- > 0) {
			bwalk_adjust_crouch_pos(-1);
		}

		while (data->crouchup-- > 0) {
			bwalk_adjust_crouch_pos(1);
		}

		g_Vars.currentplayer->eyesshut = data->eyesshut;
	}
}

void bwalk_update_speed_theta(void)
{
	if (bmove_get_crouch_pos() == CROUCHPOS_SQUAT) {
		g_Vars.currentplayer->speedtheta *= 0.5f;
	} else if (bmove_get_crouch_pos() == CROUCHPOS_DUCK) {
		g_Vars.currentplayer->speedtheta *= 0.75f;
	}
}

void bwalk0f0c69b8(void)
{
	s32 i;
	f32 spe0;
	f32 spdc;
	f32 spd8;
	struct coord spcc = {0, 0, 0};
	f32 shotforwards;
	f32 shotsideways;
	f32 spc0;
	f32 tmp1;
	f32 tmp2;
	f32 spb4;
	f32 spb0;
	f32 dist;
	f32 spa8;
	f32 mult;
	f32 f0;
	f32 lvupdate60f;
	s32 lvupdate240;
	s32 cdresult;
	struct escalatorobj *esc;
	f32 sp8c;
	f32 sp88;
	f32 speedforwards;
	f32 speedsideways;
	f32 speedtheta;
	f32 heartrate;
	f32 sp74;
	f32 radius;
	f32 ymax;
	f32 ymin;
	f32 xdiff;
	f32 zdiff;
	f32 xdelta;
	f32 zdelta;
	f32 sp54;
	f32 sp50;
	f32 sp4c;
	f32 sp48;
	f32 sp44;
	f32 sp40;
	f32 sp3c;
	f32 breathing;

	spc0 = g_Vars.currentplayer->vv_eyeheight - 159;

	if (inv_has_briefcase() && ((g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE || g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE))) {
		spc0 = -63.600006f;
	}

	spc0 = spc0 / 353.33331298828f + 1.0f;

	if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_FASTMOVEMENT)) {
		spc0 *= 1.25f;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (cheat_is_active(CHEAT_SMALLJO)) {
		spc0 *= 0.4f;
	}
#endif

	if (g_Vars.currentplayer->walkinitmove) {
		g_Vars.currentplayer->walkinitt += g_Vars.lvupdate60freal * (1.0f / 60.0f);

		if (g_Vars.currentplayer->walkinitt >= 1.0f) {
			g_Vars.currentplayer->walkinitt = 1.0f;
			g_Vars.currentplayer->walkinitmove = false;
		}

		g_Vars.currentplayer->walkinitt2 = 1.0f - (cosf(g_Vars.currentplayer->walkinitt * M_BADPI) + 1.0f) * 0.5f;

		bmove_update_head_with_mtx(0.0f, 0.0f, 0.0f, &g_Vars.currentplayer->walkinitmtx, 1.0f - g_Vars.currentplayer->walkinitt2);

		g_Vars.currentplayer->gunspeed = 0.0f;

		bmove_update_move_init_speed(&spcc);
		bwalk_calculate_new_position_with_push(&spcc, 0.0f, true, 0.0f, CDTYPE_ALL);
	} else {
		bwalk_apply_crouch_speed();
		bwalk_update_crouch_offset();

		bmove_shotspeed_to_lateral(&shotforwards, &shotsideways, &g_Vars.currentplayer->bondshotspeed,
				g_Vars.currentplayer->vv_sintheta, g_Vars.currentplayer->vv_costheta);

		tmp1 = -g_Vars.currentplayer->swaytarget * g_Vars.currentplayer->bond2.unk00.f[2];
		tmp2 = g_Vars.currentplayer->swaytarget * g_Vars.currentplayer->bond2.unk00.f[0];
		tmp1 *= spc0;
		tmp2 *= spc0;
		spa8 = 0.0f;

		if (g_Vars.currentplayer->crouchoffset < -45.0f) {
			tmp1 *= 0.35f;
			tmp2 *= 0.35f;
		} else if (g_Vars.currentplayer->crouchoffset < 0.0f) {
			tmp1 *= 0.5f;
			tmp2 *= 0.5f;
		}

		spb4 = tmp1 - g_Vars.currentplayer->swayoffset0;
		spb0 = tmp2 - g_Vars.currentplayer->swayoffset2;

		dist = sqrtf(spb4 * spb4 + spb0 * spb0);

		if (g_Vars.lvupdate60freal > PALUPF(4)) {
			lvupdate60f = PALUPF(4);
			lvupdate240 = 4;
		} else {
			lvupdate60f = g_Vars.lvupdate60freal;
			lvupdate240 = g_Vars.lvupdate60;
		}

		for (i = 0; i < lvupdate240; i++) {
			spa8 += (dist - spa8) * PALUPF(0.1f);
		}

		spa8 += 3.75f * lvupdate60f;

		if (g_Vars.currentplayer->crouchoffset < -45.0f) {
			spa8 *= 0.35f;
		} else if (g_Vars.currentplayer->crouchoffset < 0.0f) {
			spa8 *= 0.5f;
		}

		if (spa8 < dist) {
			spa8 /= dist;
			spb4 *= spa8;
			spb0 *= spa8;
		}

		speedsideways = (g_Vars.currentplayer->speedsideways + shotsideways) * 0.8f;
		speedforwards = g_Vars.currentplayer->speedforwards + shotforwards;
		speedtheta = g_Vars.currentplayer->speedtheta * 0.8f;

		if (speedsideways < 0.0f) {
			speedsideways = -speedsideways;
		}

		if (speedforwards < 0.0f) {
			speedforwards = -speedforwards;
		}

		if (speedtheta < 0.0f) {
			speedtheta = -speedtheta;
		}

		heartrate = speedforwards;

		if (speedsideways > heartrate) {
			heartrate = speedsideways;
		}

		if (speedtheta > heartrate) {
			heartrate = speedtheta;
		}

		if (dist >= 0.1f && heartrate < 0.8f) {
			heartrate = 0.8f;
		}

		if (heartrate >= 0.75f) {
			g_Vars.currentplayer->bondbreathing += (heartrate - 0.75f) * g_Vars.lvupdate60freal / 900;
		} else {
			g_Vars.currentplayer->bondbreathing -= (0.75f - heartrate) * g_Vars.lvupdate60freal / 2700;
		}

		if (g_Vars.currentplayer->bondbreathing < 0.0f) {
			g_Vars.currentplayer->bondbreathing = 0.0f;
		} else if (g_Vars.currentplayer->bondbreathing > 1.0f) {
			g_Vars.currentplayer->bondbreathing = 1.0f;
		}

		mult = g_HeadAnims[HEADANIM_MOVING].translateperframe * 0.5f * g_Vars.lvupdate60freal;
		spe0 = (g_Vars.currentplayer->speedsideways * spc0 + shotsideways) * mult;

#if VERSION >= VERSION_NTSC_1_0
		if (cheat_is_active(CHEAT_SMALLJO)) {
			spe0 /= 0.4f;
		}
#endif

		bmove_update_head(heartrate, g_Vars.currentplayer->speedforwards * spc0 + shotforwards, spe0);

		g_Vars.currentplayer->gunspeed = heartrate;

		spdc = g_Vars.currentplayer->headpos.x;
		spd8 = g_Vars.currentplayer->headpos.z;

#if VERSION >= VERSION_NTSC_1_0
		if (cheat_is_active(CHEAT_SMALLJO)) {
			spdc *= 0.4f;
		}
#endif

		spcc.f[0] += (spd8 * g_Vars.currentplayer->bond2.unk00.f[0] - spdc * g_Vars.currentplayer->bond2.unk00.f[2]) * g_Vars.lvupdate60freal;
		spcc.f[2] += (spd8 * g_Vars.currentplayer->bond2.unk00.f[2] + spdc * g_Vars.currentplayer->bond2.unk00.f[0]) * g_Vars.lvupdate60freal;
		spcc.f[0] += spb4;
		spcc.f[2] += spb0;

		bmove_update_move_init_speed(&spcc);

		if (debug_is_turbo_mode_enabled()) {
			spcc.f[0] += (g_Vars.currentplayer->bond2.unk00.f[0] * g_Vars.currentplayer->speedforwards - g_Vars.currentplayer->bond2.unk00.f[2] * g_Vars.currentplayer->speedsideways) * g_Vars.lvupdate60freal * 10.0f;
			spcc.f[2] += (g_Vars.currentplayer->bond2.unk00.f[2] * g_Vars.currentplayer->speedforwards + g_Vars.currentplayer->bond2.unk00.f[0] * g_Vars.currentplayer->speedsideways) * g_Vars.lvupdate60freal * 10.0f;
		}

		if (g_Vars.currentplayer->bondforcespeed.f[0] != 0.0f || g_Vars.currentplayer->bondforcespeed.f[2] != 0.0f) {
			spcc.f[0] += g_Vars.currentplayer->bondforcespeed.f[0] * g_Vars.lvupdate60freal;
			spcc.f[2] += g_Vars.currentplayer->bondforcespeed.f[2] * g_Vars.lvupdate60freal;
		}

		if (g_Vars.currentplayer->onladder) {
			guNormalize(&g_Vars.currentplayer->laddernormal.x, &g_Vars.currentplayer->laddernormal.y, &g_Vars.currentplayer->laddernormal.z);

			sp74 = -(spcc.f[0] * g_Vars.currentplayer->laddernormal.f[0] + spcc.f[2] * g_Vars.currentplayer->laddernormal.f[2]);

			if (-4.0f * g_Vars.lvupdate60freal < sp74) {
				if (sp74 < 0.0f) {
					spcc.f[0] += sp74 * g_Vars.currentplayer->laddernormal.f[0];
					spcc.f[2] += sp74 * g_Vars.currentplayer->laddernormal.f[2];
					g_Vars.currentplayer->ladderupdown = sp74 * 0.3f;
				} else {
					player_get_bbox(g_Vars.currentplayer->prop, &radius, &ymax, &ymin);

					if (!cd_0002a13c(&g_Vars.currentplayer->prop->pos,
							radius * 1.1f, ymax - g_Vars.currentplayer->prop->pos.y,
							(g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->prop->pos.y) + 1.0f,
							g_Vars.currentplayer->prop->rooms, GEOFLAG_LADDER | GEOFLAG_LADDER_PLAYERONLY)) {
						g_Vars.currentplayer->ladderupdown = 0.0f;
					} else {
						spcc.f[0] += sp74 * g_Vars.currentplayer->laddernormal.f[0];
						spcc.f[2] += sp74 * g_Vars.currentplayer->laddernormal.f[2];
						g_Vars.currentplayer->ladderupdown = sp74 * 0.3f;
					}
				}

				spcc.x *= 0.3f;
				spcc.z *= 0.3f;
			} else {
				g_Vars.currentplayer->ladderupdown = 0.0f;
			}
		}

		if (g_Vars.currentplayer->lift) {
			esc = (struct escalatorobj *) g_Vars.currentplayer->lift->obj;

			if (esc->base.type == OBJTYPE_ESCASTEP) {
				spcc.x += esc->base.prop->pos.x - esc->prevpos.x;
				spcc.z += esc->base.prop->pos.z - esc->prevpos.z;
			}
		}

		sp8c = g_Vars.currentplayer->prop->pos.x;
		sp88 = g_Vars.currentplayer->prop->pos.z;

		bwalk0f0c63bc(&spcc, g_Vars.currentplayer->swaytarget == 0.0f, CDTYPE_ALL);

		xdelta = g_Vars.currentplayer->prop->pos.x - g_Vars.currentplayer->bondprevpos.x;
		zdelta = g_Vars.currentplayer->prop->pos.z - g_Vars.currentplayer->bondprevpos.z;

		sp54 = -xdelta * g_Vars.currentplayer->bond2.unk00.f[2] + zdelta * g_Vars.currentplayer->bond2.unk00.f[0];
		sp50 = xdelta * g_Vars.currentplayer->bond2.unk00.f[0] + zdelta * g_Vars.currentplayer->bond2.unk00.f[2];

		sp4c = -spcc.f[0] * g_Vars.currentplayer->bond2.unk00.f[2] + spcc.f[2] * g_Vars.currentplayer->bond2.unk00.f[0];
		sp48 = spcc.f[0] * g_Vars.currentplayer->bond2.unk00.f[0] + spcc.f[2] * g_Vars.currentplayer->bond2.unk00.f[2];

		if (xdelta >= 0.0f) {
			if (g_Vars.currentplayer->bondshotspeed.f[0] > 0.0f) {
				if (spcc.f[0] >= 0.0f && xdelta < spcc.f[0]) {
					g_Vars.currentplayer->bondshotspeed.f[0] *= xdelta / spcc.f[0];
				}
			} else {
				if (spcc.f[0] < 0.0f) {
					g_Vars.currentplayer->bondshotspeed.f[0] = 0.0f;
				}
			}
		} else {
			if (g_Vars.currentplayer->bondshotspeed.f[0] < 0.0f) {
				if (spcc.f[0] <= 0.0f && spcc.f[0] < xdelta) {
					g_Vars.currentplayer->bondshotspeed.f[0] *= xdelta / spcc.f[0];
				}
			} else {
				if (spcc.f[0] > 0.0f) {
					g_Vars.currentplayer->bondshotspeed.f[0] = 0.0f;
				}
			}
		}

		if (zdelta >= 0.0f) {
			if (g_Vars.currentplayer->bondshotspeed.f[2] > 0.0f) {
				if (spcc.f[2] >= 0.0f && zdelta < spcc.f[2]) {
					g_Vars.currentplayer->bondshotspeed.f[2] *= zdelta / spcc.f[2];
				}
			} else {
				if (spcc.f[2] < 0.0f) {
					g_Vars.currentplayer->bondshotspeed.f[2] = 0.0f;
				}
			}
		} else {
			if (g_Vars.currentplayer->bondshotspeed.f[2] < 0.0f) {
				if (spcc.f[2] <= 0.0f && spcc.f[2] < zdelta) {
					g_Vars.currentplayer->bondshotspeed.f[2] *= zdelta / spcc.f[2];
				}
			} else {
				if (spcc.f[2] > 0.0f) {
					g_Vars.currentplayer->bondshotspeed.f[2] = 0.0f;
				}
			}
		}

		if (sp4c != 0.0f && g_Vars.currentplayer->speedstrafe * sp4c > 0.0f) {
			sp54 /= sp4c;

			if (sp54 <= 0.0f) {
				g_Vars.currentplayer->speedstrafe = 0.0f;
			} else if (sp54 < 1.0f) {
				g_Vars.currentplayer->speedstrafe *= sp54;
			}
		}

		if (sp48 != 0.0f) {
			if (g_Vars.currentplayer->speedgo * sp48 > 0.0f) {
				sp50 /= sp48;

				if (sp50 <= 0.0f) {
					g_Vars.currentplayer->speedgo = 0.0f;
				} else if (sp50 < 1.0f) {
					g_Vars.currentplayer->speedgo *= sp50;
				}
			}
		}

		xdiff = g_Vars.currentplayer->prop->pos.x - sp8c;
		zdiff = g_Vars.currentplayer->prop->pos.z - sp88;
		f0 = spcc.f[0] * spcc.f[0] + spcc.f[2] * spcc.f[2];

		if (f0 != 0.0f) {
			f0 = (xdiff * xdiff + zdiff * zdiff) / f0;
		}

		f0 = sqrtf(f0);
		g_Vars.currentplayer->swayoffset0 += f0 * spb4;
		g_Vars.currentplayer->swayoffset2 += f0 * spb0;
	}

	sp44 = g_Vars.currentplayer->speedtheta;
	sp40 = g_Vars.currentplayer->speedverta / 0.7f + g_Vars.currentplayer->crouchspeed / PALUPF(5.0f);
	sp3c = g_Vars.currentplayer->gunspeed;

	breathing = bhead_get_breathing_value();

	if (sp40 > 1.0f) {
		sp40 = 1.0f;
	} else if (sp40 < -1.0f) {
		sp40 = -1.0f;
	}

	if (g_Vars.currentplayer->headanim == HEADANIM_MOVING) {
		breathing *= 1.2f;
	}

	bgun0f09d8dc(breathing, sp3c, sp40, sp44, 0.0f);
	bgun_set_adjust_pos(g_Vars.currentplayer->vv_verta360 * 0.017450513318181f);
}

void bwalk_tick(void)
{
	bwalk_update_prev_pos();
	bwalk_update_theta();
	bmove_update_verta();
	bwalk0f0c69b8();
	bwalk_update_vertical();

#if VERSION >= VERSION_NTSC_1_0
	{
		s32 i;

		for (i = 0; g_Vars.currentplayer->prop->rooms[i] != -1; i++) {
			if (g_Vars.currentplayer->floorroom == g_Vars.currentplayer->prop->rooms[i]) {
				prop_deregister_rooms(g_Vars.currentplayer->prop);
				g_Vars.currentplayer->prop->rooms[0] = g_Vars.currentplayer->floorroom;
				g_Vars.currentplayer->prop->rooms[1] = -1;
				break;
			}
		}
	}
#endif

	bmove_update_rooms(g_Vars.currentplayer);
	objective_check_room_entered(g_Vars.currentplayer->prop->rooms[0]);

	if (g_Vars.currentplayer->walkinitmove) {
		struct coord coord;
		coord.x = (g_Vars.currentplayer->walkinitstart.x - g_Vars.currentplayer->walkinitpos.x)
			* (1.0f - g_Vars.currentplayer->walkinitt2) + g_Vars.currentplayer->prop->pos.x;

		coord.y = (g_Vars.currentplayer->walkinitstart.y - g_Vars.currentplayer->prop->pos.y)
			* (1.0f - g_Vars.currentplayer->walkinitt2) + g_Vars.currentplayer->prop->pos.y;

		coord.z = (g_Vars.currentplayer->walkinitstart.z - g_Vars.currentplayer->walkinitpos.z)
			* (1.0f - g_Vars.currentplayer->walkinitt2) + g_Vars.currentplayer->prop->pos.z;

		bmove_set_pos(&coord);
	} else {
		bmove_set_pos(&g_Vars.currentplayer->prop->pos);
	}

	player_update_perim_info();
	doors_check_automatic();
}
