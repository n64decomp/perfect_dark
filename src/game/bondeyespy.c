#include <ultra64.h>
#include "constants.h"
#include "game/bondeyespy.h"
#include "game/chr/chraction.h"
#include "game/chr/chr.h"
#include "game/prop.h"
#include "game/game_092610.h"
#include "game/game_097ba0.h"
#include "game/game_0b69d0.h"
#include "game/hudmsg.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
#include "game/game_1655c0.h"
#include "game/lang.h"
#include "game/options.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/main.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "data.h"
#include "types.h"

u8 var80070ec0 = 0;
u8 var80070ec4 = 0;
u32 var80070ec8 = 0x00000000;
u32 var80070ecc = 0x00000000;
f32 g_EyespyMaxHeight = 160;
f32 g_EyespyMinHeight = 80;
u32 g_EyespyFallAccel = 100;
u32 g_EyespyMaxFallSpeed = 3000;

/**
 * Determines the eyespy's ground Y value by doing a collision check for a
 * position 50 units above the current position, or less if the eyespy is near
 * the top of its height range.
 */
f32 eyespyFindGround(s16 *floorroom)
{
	struct prop *prop = g_Vars.currentplayer->eyespy->prop;
	s32 inlift;
	struct prop *lift;
	struct coord pos;
	f32 yoffset = 50;
	f32 ground;

	if (g_EyespyMaxHeight - g_Vars.currentplayer->eyespy->height < 50) {
		yoffset = g_EyespyMaxHeight - g_Vars.currentplayer->eyespy->height;
	}

	if (yoffset < 0) {
		yoffset = 0;
	}

	pos.x = prop->pos.x;
	pos.y = prop->pos.y + yoffset;
	pos.z = prop->pos.z;

	ground = cdFindGroundY(&pos, 26, prop->rooms, NULL, NULL, NULL, floorroom, &inlift, &lift);

	if (ground < -30000) {
		ground = -30000;
	}

	return ground;
}

s32 eyespyTryMoveUpwards(f32 yvel)
{
	s32 result;
	struct prop *prop = g_Vars.currentplayer->eyespy->prop;
	struct chrdata *chr = prop->chr;
	struct coord dstpos;
	s16 dstrooms[8];
	s32 types;
	u32 stack;
	f32 f0;
	u32 stack2;

	dstpos.x = prop->pos.x;
	dstpos.y = prop->pos.y + yvel;
	dstpos.z = prop->pos.z;

	types = g_Vars.bondcollisions ? CDTYPE_ALL : CDTYPE_BG;

	// Allow eyespy to go up steps 30cm or less
	if (chr->manground + 30 >= g_Vars.currentplayer->eyespy->oldground) {
		f0 = chr->manground - prop->pos.y + 30;
	} else {
		f0 = g_Vars.currentplayer->eyespy->oldground - prop->pos.y;
	}

	func0f065e74(&prop->pos, prop->rooms, &dstpos, dstrooms);
	func0f021fa8(prop->chr, &dstpos, dstrooms);
	propSetCollisionsEnabled(prop, false);

	f0 -= 0.1f;

	result = cdTestVolume(&dstpos, 26, dstrooms, types, 1, 15, f0);
	propSetCollisionsEnabled(prop, true);

	if (result == CDRESULT_NOCOLLISION) {
		prop->pos.y = dstpos.y;
		func0f065c44(prop);
		roomsCopy(dstrooms, prop->rooms);
	}

	return result;
}

s32 eyespyCalculateNewPosition(struct coord *vel)
{
	bool result = true;
	struct prop *eyespyprop = g_Vars.currentplayer->eyespy->prop;
	struct chrdata *chr = eyespyprop->chr;
	struct coord dstpos;
	s16 dstrooms[8];
	s16 floorroom;
	s16 sp74[24];
	s32 types;
	s32 i;
	f32 f18;
	f32 xdiff;
	f32 zdiff;
	u32 stack;
	f32 limit;
	f32 halflimit;
	struct prop *prop;
	s32 playernum;
	u32 stack2;

	eyespyFindGround(&floorroom);

	if (vel->x || vel->y || vel->z) {
		propSetCollisionsEnabled(eyespyprop, false);

		dstpos.x = vel->x + eyespyprop->pos.x;
		dstpos.y = vel->y + eyespyprop->pos.y;
		dstpos.z = vel->z + eyespyprop->pos.z;

		types = g_Vars.bondcollisions ? CDTYPE_ALL : CDTYPE_BG;

		// Allow eyespy to go up steps 30cm or less
		if (g_Vars.currentplayer->eyespy->oldground <= chr->manground + 30) {
			f18 = chr->manground - eyespyprop->pos.y + 30;
		} else {
			f18 = g_Vars.currentplayer->eyespy->oldground - eyespyprop->pos.y;
		}

		// This must be populating dstrooms at least
		func0f065dfc(&eyespyprop->pos, eyespyprop->rooms, &dstpos, dstrooms, sp74, 20);

		// Check if dstrooms contains the eyespy's old room.
		// If so, simplify dstrooms so it only contains that room.
		for (i = 0; dstrooms[i] != -1; i++) {
			if (dstrooms[i] == floorroom) {
				dstrooms[0] = floorroom;
				dstrooms[1] = -1;
				break;
			}
		}

		func0f021fa8(eyespyprop->chr, &dstpos, dstrooms);

		// Check if the eyespy is moving 13cm or more along either the X or Z
		// axis in a single frame. If less, only do a collision check for the
		// dst position. If more, do a halfway check too?
		xdiff = dstpos.x - eyespyprop->pos.x;
		zdiff = dstpos.z - eyespyprop->pos.z;

		limit = 26;
		halflimit = limit * 0.5f;

		if (xdiff > halflimit || zdiff > halflimit || xdiff < -halflimit || zdiff < -halflimit) {
			result = cdTestAToB3(&eyespyprop->pos, eyespyprop->rooms, &dstpos, dstrooms, limit, types, 1, 15, f18);

			if (result == CDRESULT_NOCOLLISION) {
				result = cdTestAToB1(&eyespyprop->pos, &dstpos, limit, dstrooms, types, 1, 15, f18);
			}
		} else {
			result = cdTestAToB1(&eyespyprop->pos, &dstpos, limit, sp74, types, 1, 15, f18);
		}

		if (result == CDRESULT_COLLISION) {
			prop = cdGetObstacle();

			if (prop && prop->type == PROPTYPE_PLAYER) {
				playernum = g_Vars.currentplayernum;

				if (playernum == propGetPlayerNum(prop)) {
					var80070ec0 = true;
				}
			}
		}

		propSetCollisionsEnabled(eyespyprop, true);

		if (result == CDRESULT_NOCOLLISION) {
			// Apply the destination
			eyespyprop->pos.x = dstpos.x;
			eyespyprop->pos.y = dstpos.y;
			eyespyprop->pos.z = dstpos.z;

			func0f065c44(eyespyprop);

			roomsCopy(dstrooms, eyespyprop->rooms);
		}
	}

	return result;
}

bool eyespyCalculateNewPositionWithPush(struct coord *vel)
{
	s32 result = eyespyCalculateNewPosition(vel);
	struct prop *prop;

	if (result != CDRESULT_NOCOLLISION) {
		var80070ec4 = 1;

		prop = cdGetObstacle();

		if (prop && g_Vars.lvupdate240 > 0) {
			if (prop->type == PROPTYPE_DOOR) {
				struct doorobj *door = prop->door;
				var80070ec4 = 3;

				if (door->doorflags & DOORFLAG_DAMAGEONCONTACT) {
					f32 sp38[3];
					struct coord sp2c;
					struct coord sp20;

					func00024e4c(&sp2c, &sp20, 286, "bondeyespy.c");

					// Nothing is actually done with these coordinates...
					// This code was likely copied from bondwalk then the bounce
					// feature removed
					sp38[0] = sp20.z - sp2c.z;
					sp38[1] = 0;
					sp38[2] = sp2c.x - sp20.x;

					if (sp38[0] || sp38[2]) {
						guNormalize(&sp38[0], &sp38[1], &sp38[2]);
					} else {
						sp38[2] = 1;
					}

					if (prop);

					var80070ec4 = 4;
				}
			}

			if (prop->type == PROPTYPE_CHR) {
				var80070ec4 = 2;
			} else if (prop->type == PROPTYPE_PLAYER) {
				var80070ec4 = 2;
			} else if (prop->type == PROPTYPE_OBJ) {
				var80070ec4 = 5;
			}
		}
	}

	return result;
}

s32 eyespy0f0cf890(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4)
{
	if (func00024ea4()) {
		struct coord sp24;
		s32 someint;
		f32 somefloat = func00024e98();
		sp24.x = arg0->x * somefloat * 0.25f;
		sp24.y = arg0->y * somefloat * 0.25f;
		sp24.z = arg0->z * somefloat * 0.25f;

		someint = eyespyCalculateNewPositionWithPush(&sp24);

		if (someint == 1) {
			return 1;
		}

		if (someint == 0) {
			func00024e4c(arg3, arg4, 350, "bondeyespy.c");

			if (arg3->f[0] != arg1->f[0]
					|| arg3->f[1] != arg1->f[1]
					|| arg3->f[2] != arg1->f[2]
					|| arg4->f[0] != arg2->f[0]
					|| arg4->f[1] != arg2->f[1]
					|| arg4->f[2] != arg2->f[2]) {
				return 0;
			}
		}
	}

	return -1;
}

s32 eyespy0f0cf9f8(struct coord *arg0, struct coord *arg1, struct coord *arg2)
{
	f32 tmp;
	struct coord sp30;
	struct coord sp24;
	f32 dist;

	if (arg1->f[0] != arg2->f[0] || arg1->f[2] != arg2->f[2]) {
		sp30.x = arg2->x - arg1->x;
		sp30.y = 0;
		sp30.z = arg2->z - arg1->z;

		dist = sqrtf(sp30.f[0] * sp30.f[0] + sp30.f[2] * sp30.f[2]);

		sp30.x *= 1.0f / dist;
		sp30.z *= 1.0f / dist;

		tmp = arg0->f[0] * sp30.f[0] + arg0->f[2] * sp30.f[2];

		sp24.x = sp30.x * tmp;
		sp24.y = 0;
		sp24.z = sp30.z * tmp;

		return eyespyCalculateNewPositionWithPush(&sp24);
	}

	return -1;
}

s32 eyespy0f0cfafc(struct coord *arg0, struct coord *arg1, struct coord *arg2)
{
	struct coord sp34;
	struct coord sp28;
	f32 width = 26;
	struct prop *prop = g_Vars.currentplayer->eyespy->prop;
	f32 tmp;

	sp34.x = arg1->x - (prop->pos.x + arg0->f[0]);
	sp34.z = arg1->z - (prop->pos.z + arg0->f[2]);

	if (sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2] <= width * width) {
		if (arg1->f[0] != prop->pos.f[0] || arg1->f[2] != prop->pos.f[2]) {
			sp34.x = -(arg1->z - prop->pos.z);
			sp34.y = 0;
			sp34.z = arg1->x - prop->pos.x;

			tmp = sqrtf(sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2]);

			sp34.x = sp34.f[0] * (1.0f / tmp);
			sp34.z = sp34.f[2] * (1.0f / tmp);

			tmp = arg0->f[0] * sp34.f[0] + arg0->f[2] * sp34.f[2];

			sp34.x = sp34.x * tmp;
			sp34.z = sp34.z * tmp;

			sp28.x = sp34.x;
			sp28.y = 0;
			sp28.z = sp34.z;

			if (eyespyCalculateNewPositionWithPush(&sp28) == 1) {
				return true;
			}
		}
	} else {
		sp34.x = arg2->x - (prop->pos.x + arg0->f[0]);
		sp34.z = arg2->z - (prop->pos.z + arg0->f[2]);

		if (sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2] <= width * width) {
			if (arg2->f[0] != prop->pos.f[0] || arg2->f[2] != prop->pos.f[2]) {
				sp34.x = -(arg2->z - prop->pos.z);
				sp34.y = 0;
				sp34.z = arg2->x - prop->pos.x;

				tmp = sqrtf(sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2]);

				sp34.x = sp34.f[0] * (1.0f / tmp);
				sp34.z = sp34.f[2] * (1.0f / tmp);

				tmp = arg0->f[0] * sp34.f[0] + arg0->f[2] * sp34.f[2];

				sp34.x = sp34.x * tmp;
				sp34.z = sp34.z * tmp;

				sp28.x = sp34.x;
				sp28.y = 0;
				sp28.z = sp34.z;

				if (eyespyCalculateNewPositionWithPush(&sp28) == 1) {
					return true;
				}
			}
		}
	}

	return false;
}

s32 eyespy0f0cfdd0(struct coord *vel, struct coord *arg1, struct coord *arg2)
{
	bool result = eyespyCalculateNewPositionWithPush(vel);

	if (result != CDRESULT_NOCOLLISION) {
		func00024e4c(arg1, arg2, 473, "bondeyespy.c");
	}

	return result;
}

void eyespyUpdateVertical(void)
{
	struct coord spac;
	struct coord spa0;
	struct prop *prop = g_Vars.currentplayer->eyespy->prop;
	struct coord dist;
	f32 newground;
	struct chrdata *chr = prop->chr;
	struct coord origpos;
	f32 accel;
	f32 maxfallspeed;
	u8 sp73 = 0;
	f32 newy;
	struct coord sp60;
	struct coord sp54;
	u32 stack;
	struct coord sp44;
	struct coord sp38;

	origpos.f[0] = prop->pos.x;
	origpos.f[1] = prop->pos.y;
	origpos.f[2] = prop->pos.z;

	dist.x = g_Vars.currentplayer->eyespy->vel.x;
	dist.y = 0;
	dist.z = g_Vars.currentplayer->eyespy->vel.z;

	if (eyespy0f0cfdd0(&dist, &spac, &spa0) == CDRESULT_COLLISION) {
		if (eyespy0f0cf890(&dist, &spac, &spa0, &sp60, &sp54)) {
			if (eyespy0f0cf9f8(&dist, &spac, &spa0) <= 0) {
				eyespy0f0cfafc(&dist, &spac, &spa0);
			}
		} else {
			eyespy0f0cf890(&dist, &sp60, &sp54, &sp44, &sp38);

			if (eyespy0f0cf9f8(&dist, &sp60, &sp54) <= 0
					&& eyespy0f0cf9f8(&dist, &spac, &spa0) <= 0
					&& eyespy0f0cfafc(&dist, &sp60, &sp54) <= 0) {
				eyespy0f0cfafc(&dist, &spac, &spa0);
			}
		}
	}

	// Handle gravity
	func0000db30("g", &g_EyespyFallAccel);
	func0000db30("l", &g_EyespyMaxFallSpeed);

	accel = g_EyespyFallAccel * 0.01; // always 1
	maxfallspeed = g_EyespyMaxFallSpeed * 0.01f; // always 30

	newy = chr->manground;
	newground = eyespyFindGround(NULL);

	if (newground != chr->manground) {
		if (newground < chr->manground) {
			// Descending a slope or ledge
			if (g_Vars.currentplayer->eyespy->gravity >= maxfallspeed) {
				g_Vars.currentplayer->eyespy->gravity = maxfallspeed;
			} else {
				g_Vars.currentplayer->eyespy->gravity += accel;
			}

			newy -= g_Vars.currentplayer->eyespy->gravity;

			if (newy < newground) {
				g_Vars.currentplayer->eyespy->gravity = 0;
				newy = newground;
			}
		} else if (newground > chr->manground) {
			// Ascending a slope or steps
			if (g_Vars.currentplayer->eyespy->gravity >= maxfallspeed) {
				g_Vars.currentplayer->eyespy->gravity = maxfallspeed;
			} else {
				g_Vars.currentplayer->eyespy->gravity += accel;
			}

			newy += g_Vars.currentplayer->eyespy->gravity;

			if (newy > newground) {
				g_Vars.currentplayer->eyespy->gravity = 0;
				newy = newground;
			}
		}

		if (chr->manground + g_Vars.currentplayer->eyespy->height < newground + g_EyespyMinHeight) {
			newy = (newground + g_EyespyMinHeight) - g_Vars.currentplayer->eyespy->height;
		}
	}

	if (eyespyTryMoveUpwards(newy - chr->manground)) {
		chr->manground = newy;
	} else {
		g_Vars.currentplayer->eyespy->gravity = 0;
	}

	g_Vars.currentplayer->eyespy->oldground = newground;
	chr->ground = chr->manground;
	chr->sumground = chr->manground * (PAL ? 8.4175090789795f : 9.999998f);

	// Handle rebound if hitting the min or max height
	if (g_Vars.currentplayer->eyespy->vel.y != 0) {
		f32 newheight = g_Vars.currentplayer->eyespy->vel.y + g_Vars.currentplayer->eyespy->height;
		bool rebound = false;

		if (newheight < g_EyespyMinHeight) {
			newheight = g_EyespyMinHeight;
			rebound = true;
		} else if (newheight > g_EyespyMaxHeight) {
			newheight = g_EyespyMaxHeight;
			rebound = true;
		}

		if (eyespyTryMoveUpwards(newheight - g_Vars.currentplayer->eyespy->height)) {
			g_Vars.currentplayer->eyespy->height = newheight;
		} else {
			rebound = true;
			sp73 = 1;
		}

		if (rebound) {
			g_Vars.currentplayer->eyespy->vel.y = -g_Vars.currentplayer->eyespy->vel.y * 0.25f;
		}
	}

	if (var80070ec4 == 0) {
		var80070ec4 = sp73;
	}

	func0f0220ac(chr);

	dist.x = prop->pos.x - origpos.x;
	dist.y = prop->pos.y - origpos.y;
	dist.z = prop->pos.z - origpos.z;

	g_Vars.currentplayer->eyespy->speed =
		dist.f[0] * dist.f[0] +
		dist.f[1] * dist.f[1] +
		dist.f[2] * dist.f[2];
}

bool eyespyTryLaunch(void)
{
	struct coord playerpos;
	struct coord testfrompos;
	struct chrdata *chr = g_Vars.currentplayer->eyespy->prop->chr;
	bool launched;
	bool insafe;
	char text[48];

	insafe = stageGetIndex(g_Vars.stagenum) == STAGEINDEX_G5BUILDING
		&& g_Vars.currentplayer->prop->rooms[0] == 0x53;

	playerpos.x = g_Vars.currentplayer->prop->pos.x;
	playerpos.y = g_Vars.currentplayer->prop->pos.y;
	playerpos.z = g_Vars.currentplayer->prop->pos.z;

	chr->soundtimer = FRAMESTOTIME60(10);

	g_Vars.currentplayer->eyespy->init = 0;
	g_Vars.currentplayer->eyespy->up.x = 0;
	g_Vars.currentplayer->eyespy->up.y = 1;
	g_Vars.currentplayer->eyespy->up.z = 0;
	g_Vars.currentplayer->eyespy->startuptimer60 = 0;

	if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_G5BUILDING
			|| stageGetIndex(g_Vars.stagenum) == STAGEINDEX_CITRAINING) {
		g_EyespyMinHeight = 30;
	} else {
		g_EyespyMinHeight = 80;
	}

	g_Vars.currentplayer->eyespy->oldground = g_Vars.currentplayer->vv_ground;
	chr->ground = g_Vars.currentplayer->eyespy->oldground;
	chr->manground = g_Vars.currentplayer->eyespy->oldground;

	g_Vars.currentplayer->eyespy->height = g_EyespyMinHeight;
	g_Vars.currentplayer->eyespy->theta = g_Vars.currentplayer->vv_theta + 180;

	if (g_Vars.currentplayer->eyespy->theta >= 360) {
		g_Vars.currentplayer->eyespy->theta -= 360;
	}

	g_Vars.currentplayer->eyespy->costheta = cosf(g_Vars.currentplayer->eyespy->theta * 0.017453292384744f);
	g_Vars.currentplayer->eyespy->sintheta = sinf(g_Vars.currentplayer->eyespy->theta * 0.017453292384744f);

	chr->prevpos.x = g_Vars.currentplayer->eyespy->prop->pos.x = playerpos.f[0] + g_Vars.currentplayer->eyespy->sintheta * 100;
	chr->prevpos.y = g_Vars.currentplayer->eyespy->prop->pos.y = g_Vars.currentplayer->eyespy->oldground + g_Vars.currentplayer->eyespy->height;
	chr->prevpos.z = g_Vars.currentplayer->eyespy->prop->pos.z = playerpos.f[2] + g_Vars.currentplayer->eyespy->costheta * -100;

	chr->fallspeed.x = 0;
	chr->fallspeed.y = 0;
	chr->fallspeed.z = 0;

	testfrompos.x = playerpos.x;
	testfrompos.y = g_Vars.currentplayer->eyespy->oldground + g_Vars.currentplayer->eyespy->height;
	testfrompos.z = playerpos.z;

	g_Vars.currentplayer->eyespy->look.x = g_Vars.currentplayer->eyespy->sintheta;
	g_Vars.currentplayer->eyespy->look.y = 0;
	g_Vars.currentplayer->eyespy->look.z = -g_Vars.currentplayer->eyespy->costheta;
	g_Vars.currentplayer->eyespy->verta = 0;
	g_Vars.currentplayer->eyespy->cosverta = 1;
	g_Vars.currentplayer->eyespy->sinverta = 0;
	g_Vars.currentplayer->eyespy->vel.x = 0;
	g_Vars.currentplayer->eyespy->vel.y = 0;
	g_Vars.currentplayer->eyespy->vel.z = 0;
	g_Vars.currentplayer->eyespy->bobdir = 1;
	g_Vars.currentplayer->eyespy->bobtimer = 0;
	g_Vars.currentplayer->eyespy->bobactive = true;
	g_Vars.currentplayer->eyespy->speed = 0;
	g_Vars.currentplayer->eyespy->gravity = 0;
	g_Vars.currentplayer->eyespy->active = true;
	g_Vars.currentplayer->eyespy->camerabuttonheld = false;
	g_Vars.currentplayer->eyespy->buttonheld = g_Vars.currentplayer->eyespy->camerabuttonheld;
	g_Vars.currentplayer->eyespy->camerashuttertime = 0;
	g_Vars.currentplayer->eyespy->opendoor = false;
	g_Vars.currentplayer->eyespy->velf[0] = 0;
	g_Vars.currentplayer->eyespy->velf[1] = 0;
	g_Vars.currentplayer->eyespy->vels[0] = 0;
	g_Vars.currentplayer->eyespy->vels[1] = 0;
	g_Vars.currentplayer->eyespy->pitch = 0;

	func0f0c1e54(g_Vars.currentplayer->prop, 0);

	if (insafe || !cdTestAToB4(&testfrompos, g_Vars.currentplayer->prop->rooms,
				&g_Vars.currentplayer->eyespy->prop->pos, CDTYPE_ALL, 15)) {
		// Launch failed due to not enough physical space, or we're in the G5 safe
		g_Vars.currentplayer->eyespy->initialised = false;

		chr->prevpos.x = g_Vars.currentplayer->eyespy->prop->pos.x = playerpos.f[0];
		chr->prevpos.y = g_Vars.currentplayer->eyespy->prop->pos.y = g_Vars.currentplayer->eyespy->oldground + g_Vars.currentplayer->eyespy->height;
		chr->prevpos.z = g_Vars.currentplayer->eyespy->prop->pos.z = playerpos.f[2];

		propSetCollisionsEnabled(g_Vars.currentplayer->eyespy->prop, false);

		// "Not enough room to launch "
		sprintf(text, "%s%s", langGet(L_MISC(218)), weaponGetName(WEAPON_EYESPY));
		hudmsgCreateViaPreset(text, HUDMSGTYPE_DEFAULT);
		launched = false;
	} else {
		// Launch successful
		g_Vars.currentplayer->eyespy->initialised = true;

		audioStart(var80095200, SFX_DETONATE, 0, -1, -1, -1, -1, -1);

		launched = true;

		chr->chrflags &= ~CHRCFLAG_HIDDEN;
		chr->chrflags &= ~CHRCFLAG_INVINCIBLE_TO_GUNFIRE;

		func0f0939f8(NULL, g_Vars.currentplayer->eyespy->prop, SFX_EYESPY_RUNNING, -1,
				-1, 2, 0, 0, 0, -1, 0, -1, -1, -1, -1);
	}

	func0f0c1e54(g_Vars.currentplayer->prop, true);
	func0f065c44(g_Vars.currentplayer->eyespy->prop);
	func0f065e74(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms,
			&g_Vars.currentplayer->eyespy->prop->pos, g_Vars.currentplayer->eyespy->prop->rooms);

	func0f0220ac(chr);

	return launched;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel eyespyProcessInput
.late_rodata
glabel var7f1adaa0
.word 0x3f73b646
glabel var7f1adaa4
.word 0x3e99999a
glabel var7f1adaa8
.word 0x3c4ccccd
glabel var7f1adaac
.word 0x3c4ccccd
glabel var7f1adab0
.word 0x3f73b646
glabel var7f1adab4
.word 0x3c8efa35
glabel var7f1adab8
.word 0x3c8efa35
glabel var7f1adabc
.word 0x3c8efa35
glabel var7f1adac0
.word 0x3c8efa35
glabel var7f1adac4
.word 0x3d23d70a
glabel var7f1adac8
.word 0x3d23d70a
glabel var7f1adacc
.word 0x3c8efa35
glabel var7f1adad0
.word 0x3c8efa35
glabel var7f1adad4
.word 0x3e19999a
glabel var7f1adad8
.word 0x3e19999a
glabel var7f1adadc
.word 0x42b48000
glabel var7f1adae0
.word 0x3dcccccd
glabel var7f1adae4
.word 0x3ccccccd
glabel var7f1adae8
.word eyespyProcessInput+0x1188
glabel var7f1adaec
.word eyespyProcessInput+0x1284
glabel var7f1adaf0
.word eyespyProcessInput+0x1230
glabel var7f1adaf4
.word eyespyProcessInput+0x12d8
glabel var7f1adaf8
.word eyespyProcessInput+0x11dc
glabel var7f1adafc
.word 0x40c907a9
glabel var7f1adb00
.word 0x461c4000
.text
/*  f0d0ec8:	3c09800a */ 	lui	$t1,0x800a
/*  f0d0ecc:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d0ed0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d0ed4:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f0d0ed8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0d0edc:	afa400e8 */ 	sw	$a0,0xe8($sp)
/*  f0d0ee0:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d0ee4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d0ee8:	c424ed70 */ 	lwc1	$f4,-0x1290($at)
/*  f0d0eec:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0d0ef0:	8d2e0288 */ 	lw	$t6,0x288($t1)
/*  f0d0ef4:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f0d0ef8:	e7a400e0 */ 	swc1	$f4,0xe0($sp)
/*  f0d0efc:	afb900e4 */ 	sw	$t9,0xe4($sp)
/*  f0d0f00:	0fc54cfe */ 	jal	0xf1533f8
/*  f0d0f04:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0d0f08:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0d0f0c:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0d0f10:	a3a200c3 */ 	sb	$v0,0xc3($sp)
/*  f0d0f14:	0c0052e6 */ 	jal	0x14b98
/*  f0d0f18:	01e02025 */ 	move	$a0,$t7
/*  f0d0f1c:	83a400c3 */ 	lb	$a0,0xc3($sp)
/*  f0d0f20:	0c005310 */ 	jal	0x14c40
/*  f0d0f24:	a3a200c2 */ 	sb	$v0,0xc2($sp)
/*  f0d0f28:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f0d0f2c:	00023e00 */ 	sll	$a3,$v0,0x18
/*  f0d0f30:	0007ce03 */ 	sra	$t9,$a3,0x18
/*  f0d0f34:	3c09800a */ 	lui	$t1,0x800a
/*  f0d0f38:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d0f3c:	03203825 */ 	move	$a3,$t9
/*  f0d0f40:	11c0000c */ 	beqz	$t6,.PF0f0d0f74
/*  f0d0f44:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d0f48:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d0f4c:	83a400c3 */ 	lb	$a0,0xc3($sp)
/*  f0d0f50:	3405ffff */ 	li	$a1,0xffff
/*  f0d0f54:	0c00533a */ 	jal	0x14ce8
/*  f0d0f58:	a3b900c0 */ 	sb	$t9,0xc0($sp)
/*  f0d0f5c:	3c09800a */ 	lui	$t1,0x800a
/*  f0d0f60:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d0f64:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d0f68:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d0f6c:	10000002 */ 	b	.PF0f0d0f78
/*  f0d0f70:	3048ffff */ 	andi	$t0,$v0,0xffff
.PF0f0d0f74:
/*  f0d0f74:	00004025 */ 	move	$t0,$zero
.PF0f0d0f78:
/*  f0d0f78:	8d380288 */ 	lw	$t8,0x288($t1)
/*  f0d0f7c:	240f0001 */ 	li	$t7,0x1
/*  f0d0f80:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f0d0f84:	8f040070 */ 	lw	$a0,0x70($t8)
/*  f0d0f88:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d0f8c:	a7a800bc */ 	sh	$t0,0xbc($sp)
/*  f0d0f90:	0fc54cf0 */ 	jal	0xf1533c0
/*  f0d0f94:	a3a700c0 */ 	sb	$a3,0xc0($sp)
/*  f0d0f98:	44808000 */ 	mtc1	$zero,$f16
/*  f0d0f9c:	3c09800a */ 	lui	$t1,0x800a
/*  f0d0fa0:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d0fa4:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d0fa8:	e7b0009c */ 	swc1	$f16,0x9c($sp)
/*  f0d0fac:	e7b00098 */ 	swc1	$f16,0x98($sp)
/*  f0d0fb0:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*  f0d0fb4:	8db90480 */ 	lw	$t9,0x480($t5)
/*  f0d0fb8:	28410004 */ 	slti	$at,$v0,0x4
/*  f0d0fbc:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d0fc0:	c7260028 */ 	lwc1	$f6,0x28($t9)
/*  f0d0fc4:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f0d0fc8:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d0fcc:	00405825 */ 	move	$t3,$v0
/*  f0d0fd0:	14200035 */ 	bnez	$at,.PF0f0d10a8
/*  f0d0fd4:	e7a60088 */ 	swc1	$f6,0x88($sp)
/*  f0d0fd8:	8d2e0288 */ 	lw	$t6,0x288($t1)
/*  f0d0fdc:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0d0fe0:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d0fe4:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0d0fe8:	a7a800bc */ 	sh	$t0,0xbc($sp)
/*  f0d0fec:	0fc54d05 */ 	jal	0xf153414
/*  f0d0ff0:	a3a700c0 */ 	sb	$a3,0xc0($sp)
/*  f0d0ff4:	00021e00 */ 	sll	$v1,$v0,0x18
/*  f0d0ff8:	00037e03 */ 	sra	$t7,$v1,0x18
/*  f0d0ffc:	000f2600 */ 	sll	$a0,$t7,0x18
/*  f0d1000:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0d1004:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f0d1008:	0c0052e6 */ 	jal	0x14b98
/*  f0d100c:	03002025 */ 	move	$a0,$t8
/*  f0d1010:	83a40077 */ 	lb	$a0,0x77($sp)
/*  f0d1014:	a3a200c1 */ 	sb	$v0,0xc1($sp)
/*  f0d1018:	0c005310 */ 	jal	0x14c40
/*  f0d101c:	afa4003c */ 	sw	$a0,0x3c($sp)
/*  f0d1020:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0d1024:	00023600 */ 	sll	$a2,$v0,0x18
/*  f0d1028:	00067603 */ 	sra	$t6,$a2,0x18
/*  f0d102c:	3c09800a */ 	lui	$t1,0x800a
/*  f0d1030:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d1034:	01c03025 */ 	move	$a2,$t6
/*  f0d1038:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0d103c:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d1040:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f0d1044:	83aa00c1 */ 	lb	$t2,0xc1($sp)
/*  f0d1048:	8fab00b0 */ 	lw	$t3,0xb0($sp)
/*  f0d104c:	11e00013 */ 	beqz	$t7,.PF0f0d109c
/*  f0d1050:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d1054:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d1058:	3405ffff */ 	li	$a1,0xffff
/*  f0d105c:	a3ae00bf */ 	sb	$t6,0xbf($sp)
/*  f0d1060:	a3a700c0 */ 	sb	$a3,0xc0($sp)
/*  f0d1064:	a7a800bc */ 	sh	$t0,0xbc($sp)
/*  f0d1068:	a3aa00c1 */ 	sb	$t2,0xc1($sp)
/*  f0d106c:	0c00533a */ 	jal	0x14ce8
/*  f0d1070:	afab00b0 */ 	sw	$t3,0xb0($sp)
/*  f0d1074:	3c09800a */ 	lui	$t1,0x800a
/*  f0d1078:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d107c:	83a600bf */ 	lb	$a2,0xbf($sp)
/*  f0d1080:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d1084:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f0d1088:	83aa00c1 */ 	lb	$t2,0xc1($sp)
/*  f0d108c:	8fab00b0 */ 	lw	$t3,0xb0($sp)
/*  f0d1090:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d1094:	10000002 */ 	b	.PF0f0d10a0
/*  f0d1098:	3045ffff */ 	andi	$a1,$v0,0xffff
.PF0f0d109c:
/*  f0d109c:	00002825 */ 	move	$a1,$zero
.PF0f0d10a0:
/*  f0d10a0:	10000008 */ 	b	.PF0f0d10c4
/*  f0d10a4:	8d2d0284 */ 	lw	$t5,0x284($t1)
.PF0f0d10a8:
/*  f0d10a8:	001f5600 */ 	sll	$t2,$ra,0x18
/*  f0d10ac:	00073600 */ 	sll	$a2,$a3,0x18
/*  f0d10b0:	000ac603 */ 	sra	$t8,$t2,0x18
/*  f0d10b4:	0006ce03 */ 	sra	$t9,$a2,0x18
/*  f0d10b8:	03005025 */ 	move	$t2,$t8
/*  f0d10bc:	03203025 */ 	move	$a2,$t9
/*  f0d10c0:	3105ffff */ 	andi	$a1,$t0,0xffff
.PF0f0d10c4:
/*  f0d10c4:	24010002 */ 	li	$at,0x2
/*  f0d10c8:	11610002 */ 	beq	$t3,$at,.PF0f0d10d4
/*  f0d10cc:	24010003 */ 	li	$at,0x3
/*  f0d10d0:	15610009 */ 	bne	$t3,$at,.PF0f0d10f8
.PF0f0d10d4:
/*  f0d10d4:	310e8000 */ 	andi	$t6,$t0,0x8000
/*  f0d10d8:	310f0010 */ 	andi	$t7,$t0,0x10
/*  f0d10dc:	31184000 */ 	andi	$t8,$t0,0x4000
/*  f0d10e0:	01002025 */ 	move	$a0,$t0
/*  f0d10e4:	310c2000 */ 	andi	$t4,$t0,0x2000
/*  f0d10e8:	afae00a8 */ 	sw	$t6,0xa8($sp)
/*  f0d10ec:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f0d10f0:	1000001e */ 	b	.PF0f0d116c
/*  f0d10f4:	afb800a0 */ 	sw	$t8,0xa0($sp)
.PF0f0d10f8:
/*  f0d10f8:	29610004 */ 	slti	$at,$t3,0x4
/*  f0d10fc:	10200009 */ 	beqz	$at,.PF0f0d1124
/*  f0d1100:	01002025 */ 	move	$a0,$t0
/*  f0d1104:	31192000 */ 	andi	$t9,$t0,0x2000
/*  f0d1108:	310e8000 */ 	andi	$t6,$t0,0x8000
/*  f0d110c:	310f4000 */ 	andi	$t7,$t0,0x4000
/*  f0d1110:	310c0030 */ 	andi	$t4,$t0,0x30
/*  f0d1114:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0d1118:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f0d111c:	10000013 */ 	b	.PF0f0d116c
/*  f0d1120:	afaf00a0 */ 	sw	$t7,0xa0($sp)
.PF0f0d1124:
/*  f0d1124:	29610006 */ 	slti	$at,$t3,0x6
/*  f0d1128:	14200007 */ 	bnez	$at,.PF0f0d1148
/*  f0d112c:	00a01825 */ 	move	$v1,$a1
/*  f0d1130:	30b82000 */ 	andi	$t8,$a1,0x2000
/*  f0d1134:	01002025 */ 	move	$a0,$t0
/*  f0d1138:	310c2000 */ 	andi	$t4,$t0,0x2000
/*  f0d113c:	afb800a8 */ 	sw	$t8,0xa8($sp)
/*  f0d1140:	10000005 */ 	b	.PF0f0d1158
/*  f0d1144:	00a01825 */ 	move	$v1,$a1
.PF0f0d1148:
/*  f0d1148:	31192000 */ 	andi	$t9,$t0,0x2000
/*  f0d114c:	30ac2000 */ 	andi	$t4,$a1,0x2000
/*  f0d1150:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0d1154:	01002025 */ 	move	$a0,$t0
.PF0f0d1158:
/*  f0d1158:	00831025 */ 	or	$v0,$a0,$v1
/*  f0d115c:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0d1160:	304f4000 */ 	andi	$t7,$v0,0x4000
/*  f0d1164:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f0d1168:	afaf00a0 */ 	sw	$t7,0xa0($sp)
.PF0f0d116c:
/*  f0d116c:	2be1fff7 */ 	slti	$at,$ra,-9
/*  f0d1170:	14200004 */ 	bnez	$at,.PF0f0d1184
/*  f0d1174:	2be1000a */ 	slti	$at,$ra,0xa
/*  f0d1178:	50200003 */ 	beqzl	$at,.PF0f0d1188
/*  f0d117c:	2be1fff7 */ 	slti	$at,$ra,-9
/*  f0d1180:	0000f825 */ 	move	$ra,$zero
.PF0f0d1184:
/*  f0d1184:	2be1fff7 */ 	slti	$at,$ra,-9
.PF0f0d1188:
/*  f0d1188:	50200005 */ 	beqzl	$at,.PF0f0d11a0
/*  f0d118c:	2be1000a */ 	slti	$at,$ra,0xa
/*  f0d1190:	27ff000a */ 	addiu	$ra,$ra,0xa
/*  f0d1194:	001fc600 */ 	sll	$t8,$ra,0x18
/*  f0d1198:	0018fe03 */ 	sra	$ra,$t8,0x18
/*  f0d119c:	2be1000a */ 	slti	$at,$ra,0xa
.PF0f0d11a0:
/*  f0d11a0:	54200005 */ 	bnezl	$at,.PF0f0d11b8
/*  f0d11a4:	2941fff7 */ 	slti	$at,$t2,-9
/*  f0d11a8:	27fffff6 */ 	addiu	$ra,$ra,-10
/*  f0d11ac:	001f7600 */ 	sll	$t6,$ra,0x18
/*  f0d11b0:	000efe03 */ 	sra	$ra,$t6,0x18
/*  f0d11b4:	2941fff7 */ 	slti	$at,$t2,-9
.PF0f0d11b8:
/*  f0d11b8:	14200004 */ 	bnez	$at,.PF0f0d11cc
/*  f0d11bc:	2941000a */ 	slti	$at,$t2,0xa
/*  f0d11c0:	50200003 */ 	beqzl	$at,.PF0f0d11d0
/*  f0d11c4:	2941fff7 */ 	slti	$at,$t2,-9
/*  f0d11c8:	00005025 */ 	move	$t2,$zero
.PF0f0d11cc:
/*  f0d11cc:	2941fff7 */ 	slti	$at,$t2,-9
.PF0f0d11d0:
/*  f0d11d0:	50200005 */ 	beqzl	$at,.PF0f0d11e8
/*  f0d11d4:	2941000a */ 	slti	$at,$t2,0xa
/*  f0d11d8:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f0d11dc:	000ac600 */ 	sll	$t8,$t2,0x18
/*  f0d11e0:	00185603 */ 	sra	$t2,$t8,0x18
/*  f0d11e4:	2941000a */ 	slti	$at,$t2,0xa
.PF0f0d11e8:
/*  f0d11e8:	54200005 */ 	bnezl	$at,.PF0f0d1200
/*  f0d11ec:	28e1ffed */ 	slti	$at,$a3,-19
/*  f0d11f0:	254afff6 */ 	addiu	$t2,$t2,-10
/*  f0d11f4:	000a7600 */ 	sll	$t6,$t2,0x18
/*  f0d11f8:	000e5603 */ 	sra	$t2,$t6,0x18
/*  f0d11fc:	28e1ffed */ 	slti	$at,$a3,-19
.PF0f0d1200:
/*  f0d1200:	14200004 */ 	bnez	$at,.PF0f0d1214
/*  f0d1204:	28e10014 */ 	slti	$at,$a3,0x14
/*  f0d1208:	50200003 */ 	beqzl	$at,.PF0f0d1218
/*  f0d120c:	28e1ffed */ 	slti	$at,$a3,-19
/*  f0d1210:	00003825 */ 	move	$a3,$zero
.PF0f0d1214:
/*  f0d1214:	28e1ffed */ 	slti	$at,$a3,-19
.PF0f0d1218:
/*  f0d1218:	50200005 */ 	beqzl	$at,.PF0f0d1230
/*  f0d121c:	28e10014 */ 	slti	$at,$a3,0x14
/*  f0d1220:	24e70014 */ 	addiu	$a3,$a3,0x14
/*  f0d1224:	0007c600 */ 	sll	$t8,$a3,0x18
/*  f0d1228:	00183e03 */ 	sra	$a3,$t8,0x18
/*  f0d122c:	28e10014 */ 	slti	$at,$a3,0x14
.PF0f0d1230:
/*  f0d1230:	54200005 */ 	bnezl	$at,.PF0f0d1248
/*  f0d1234:	44874000 */ 	mtc1	$a3,$f8
/*  f0d1238:	24e7ffec */ 	addiu	$a3,$a3,-20
/*  f0d123c:	00077600 */ 	sll	$t6,$a3,0x18
/*  f0d1240:	000e3e03 */ 	sra	$a3,$t6,0x18
/*  f0d1244:	44874000 */ 	mtc1	$a3,$f8
.PF0f0d1248:
/*  f0d1248:	28c1ffed */ 	slti	$at,$a2,-19
/*  f0d124c:	14200005 */ 	bnez	$at,.PF0f0d1264
/*  f0d1250:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d1254:	28c10014 */ 	slti	$at,$a2,0x14
/*  f0d1258:	50200003 */ 	beqzl	$at,.PF0f0d1268
/*  f0d125c:	28c1ffed */ 	slti	$at,$a2,-19
/*  f0d1260:	00003025 */ 	move	$a2,$zero
.PF0f0d1264:
/*  f0d1264:	28c1ffed */ 	slti	$at,$a2,-19
.PF0f0d1268:
/*  f0d1268:	50200005 */ 	beqzl	$at,.PF0f0d1280
/*  f0d126c:	28c10014 */ 	slti	$at,$a2,0x14
/*  f0d1270:	24c60014 */ 	addiu	$a2,$a2,0x14
/*  f0d1274:	0006c600 */ 	sll	$t8,$a2,0x18
/*  f0d1278:	00183603 */ 	sra	$a2,$t8,0x18
/*  f0d127c:	28c10014 */ 	slti	$at,$a2,0x14
.PF0f0d1280:
/*  f0d1280:	14200004 */ 	bnez	$at,.PF0f0d1294
/*  f0d1284:	00000000 */ 	nop
/*  f0d1288:	24c6ffec */ 	addiu	$a2,$a2,-20
/*  f0d128c:	00067600 */ 	sll	$t6,$a2,0x18
/*  f0d1290:	000e3603 */ 	sra	$a2,$t6,0x18
.PF0f0d1294:
/*  f0d1294:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1298:	c420ed74 */ 	lwc1	$f0,-0x128c($at)
/*  f0d129c:	44864000 */ 	mtc1	$a2,$f8
/*  f0d12a0:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0d12a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d12a8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d12ac:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0d12b0:	44073000 */ 	mfc1	$a3,$f6
/*  f0d12b4:	00000000 */ 	nop
/*  f0d12b8:	0007ce00 */ 	sll	$t9,$a3,0x18
/*  f0d12bc:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d12c0:	00193e03 */ 	sra	$a3,$t9,0x18
/*  f0d12c4:	44063000 */ 	mfc1	$a2,$f6
/*  f0d12c8:	00000000 */ 	nop
/*  f0d12cc:	0006c600 */ 	sll	$t8,$a2,0x18
/*  f0d12d0:	11600004 */ 	beqz	$t3,.PF0f0d12e4
/*  f0d12d4:	00183603 */ 	sra	$a2,$t8,0x18
/*  f0d12d8:	24010002 */ 	li	$at,0x2
/*  f0d12dc:	5561002b */ 	bnel	$t3,$at,.PF0f0d138c
/*  f0d12e0:	29610004 */ 	slti	$at,$t3,0x4
.PF0f0d12e4:
/*  f0d12e4:	11800006 */ 	beqz	$t4,.PF0f0d1300
/*  f0d12e8:	308e0808 */ 	andi	$t6,$a0,0x808
/*  f0d12ec:	44874000 */ 	mtc1	$a3,$f8
/*  f0d12f0:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f0d12f4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d12f8:	10000005 */ 	b	.PF0f0d1310
/*  f0d12fc:	e7aa0098 */ 	swc1	$f10,0x98($sp)
.PF0f0d1300:
/*  f0d1300:	44872000 */ 	mtc1	$a3,$f4
/*  f0d1304:	00000000 */ 	nop
/*  f0d1308:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d130c:	e7a6009c */ 	swc1	$f6,0x9c($sp)
.PF0f0d1310:
/*  f0d1310:	11c00003 */ 	beqz	$t6,.PF0f0d1320
/*  f0d1314:	308f0404 */ 	andi	$t7,$a0,0x404
/*  f0d1318:	10000002 */ 	b	.PF0f0d1324
/*  f0d131c:	24030001 */ 	li	$v1,0x1
.PF0f0d1320:
/*  f0d1320:	00001825 */ 	move	$v1,$zero
.PF0f0d1324:
/*  f0d1324:	11e00003 */ 	beqz	$t7,.PF0f0d1334
/*  f0d1328:	308e0202 */ 	andi	$t6,$a0,0x202
/*  f0d132c:	10000002 */ 	b	.PF0f0d1338
/*  f0d1330:	24020001 */ 	li	$v0,0x1
.PF0f0d1334:
/*  f0d1334:	00001025 */ 	move	$v0,$zero
.PF0f0d1338:
/*  f0d1338:	0062c023 */ 	subu	$t8,$v1,$v0
/*  f0d133c:	44984000 */ 	mtc1	$t8,$f8
/*  f0d1340:	30990101 */ 	andi	$t9,$a0,0x101
/*  f0d1344:	00001025 */ 	move	$v0,$zero
/*  f0d1348:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d134c:	00001825 */ 	move	$v1,$zero
/*  f0d1350:	13200003 */ 	beqz	$t9,.PF0f0d1360
/*  f0d1354:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f0d1358:	10000001 */ 	b	.PF0f0d1360
/*  f0d135c:	24030001 */ 	li	$v1,0x1
.PF0f0d1360:
/*  f0d1360:	11c00003 */ 	beqz	$t6,.PF0f0d1370
/*  f0d1364:	00000000 */ 	nop
/*  f0d1368:	10000001 */ 	b	.PF0f0d1370
/*  f0d136c:	24020001 */ 	li	$v0,0x1
.PF0f0d1370:
/*  f0d1370:	00627823 */ 	subu	$t7,$v1,$v0
/*  f0d1374:	448f2000 */ 	mtc1	$t7,$f4
/*  f0d1378:	00000000 */ 	nop
/*  f0d137c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d1380:	10000063 */ 	b	.PF0f0d1510
/*  f0d1384:	e7a60094 */ 	swc1	$f6,0x94($sp)
/*  f0d1388:	29610004 */ 	slti	$at,$t3,0x4
.PF0f0d138c:
/*  f0d138c:	1020002e */ 	beqz	$at,.PF0f0d1448
/*  f0d1390:	308e0101 */ 	andi	$t6,$a0,0x101
/*  f0d1394:	11800006 */ 	beqz	$t4,.PF0f0d13b0
/*  f0d1398:	308f0202 */ 	andi	$t7,$a0,0x202
/*  f0d139c:	44874000 */ 	mtc1	$a3,$f8
/*  f0d13a0:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f0d13a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d13a8:	10000019 */ 	b	.PF0f0d1410
/*  f0d13ac:	e7aa0098 */ 	swc1	$f10,0x98($sp)
.PF0f0d13b0:
/*  f0d13b0:	44872000 */ 	mtc1	$a3,$f4
/*  f0d13b4:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d13b8:	44814000 */ 	mtc1	$at,$f8
/*  f0d13bc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d13c0:	30980808 */ 	andi	$t8,$a0,0x808
/*  f0d13c4:	3c0141c0 */ 	lui	$at,0x41c0
/*  f0d13c8:	30990404 */ 	andi	$t9,$a0,0x404
/*  f0d13cc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0d13d0:	13000004 */ 	beqz	$t8,.PF0f0d13e4
/*  f0d13d4:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f0d13d8:	44810000 */ 	mtc1	$at,$f0
/*  f0d13dc:	10000003 */ 	b	.PF0f0d13ec
/*  f0d13e0:	00000000 */ 	nop
.PF0f0d13e4:
/*  f0d13e4:	44800000 */ 	mtc1	$zero,$f0
/*  f0d13e8:	00000000 */ 	nop
.PF0f0d13ec:
/*  f0d13ec:	13200004 */ 	beqz	$t9,.PF0f0d1400
/*  f0d13f0:	3c0141c0 */ 	lui	$at,0x41c0
/*  f0d13f4:	44811000 */ 	mtc1	$at,$f2
/*  f0d13f8:	10000004 */ 	b	.PF0f0d140c
/*  f0d13fc:	46020101 */ 	sub.s	$f4,$f0,$f2
.PF0f0d1400:
/*  f0d1400:	44801000 */ 	mtc1	$zero,$f2
/*  f0d1404:	00000000 */ 	nop
/*  f0d1408:	46020101 */ 	sub.s	$f4,$f0,$f2
.PF0f0d140c:
/*  f0d140c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
.PF0f0d1410:
/*  f0d1410:	11c00003 */ 	beqz	$t6,.PF0f0d1420
/*  f0d1414:	00001825 */ 	move	$v1,$zero
/*  f0d1418:	10000001 */ 	b	.PF0f0d1420
/*  f0d141c:	24030001 */ 	li	$v1,0x1
.PF0f0d1420:
/*  f0d1420:	11e00003 */ 	beqz	$t7,.PF0f0d1430
/*  f0d1424:	00001025 */ 	move	$v0,$zero
/*  f0d1428:	10000001 */ 	b	.PF0f0d1430
/*  f0d142c:	24020001 */ 	li	$v0,0x1
.PF0f0d1430:
/*  f0d1430:	0062c023 */ 	subu	$t8,$v1,$v0
/*  f0d1434:	44983000 */ 	mtc1	$t8,$f6
/*  f0d1438:	00000000 */ 	nop
/*  f0d143c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d1440:	10000033 */ 	b	.PF0f0d1510
/*  f0d1444:	e7a80094 */ 	swc1	$f8,0x94($sp)
.PF0f0d1448:
/*  f0d1448:	24010004 */ 	li	$at,0x4
/*  f0d144c:	11610003 */ 	beq	$t3,$at,.PF0f0d145c
/*  f0d1450:	24010006 */ 	li	$at,0x6
/*  f0d1454:	15610018 */ 	bne	$t3,$at,.PF0f0d14b8
/*  f0d1458:	00000000 */ 	nop
.PF0f0d145c:
/*  f0d145c:	44875000 */ 	mtc1	$a3,$f10
/*  f0d1460:	00000000 */ 	nop
/*  f0d1464:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d1468:	11800006 */ 	beqz	$t4,.PF0f0d1484
/*  f0d146c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f0d1470:	44863000 */ 	mtc1	$a2,$f6
/*  f0d1474:	00000000 */ 	nop
/*  f0d1478:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d147c:	10000007 */ 	b	.PF0f0d149c
/*  f0d1480:	e7a80098 */ 	swc1	$f8,0x98($sp)
.PF0f0d1484:
/*  f0d1484:	44865000 */ 	mtc1	$a2,$f10
/*  f0d1488:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d148c:	44813000 */ 	mtc1	$at,$f6
/*  f0d1490:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d1494:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d1498:	e7a8008c */ 	swc1	$f8,0x8c($sp)
.PF0f0d149c:
/*  f0d149c:	448a5000 */ 	mtc1	$t2,$f10
/*  f0d14a0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d14a4:	c426ed78 */ 	lwc1	$f6,-0x1288($at)
/*  f0d14a8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d14ac:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d14b0:	10000017 */ 	b	.PF0f0d1510
/*  f0d14b4:	e7a80094 */ 	swc1	$f8,0x94($sp)
.PF0f0d14b8:
/*  f0d14b8:	51800007 */ 	beqzl	$t4,.PF0f0d14d8
/*  f0d14bc:	44873000 */ 	mtc1	$a3,$f6
/*  f0d14c0:	44875000 */ 	mtc1	$a3,$f10
/*  f0d14c4:	00000000 */ 	nop
/*  f0d14c8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d14cc:	10000007 */ 	b	.PF0f0d14ec
/*  f0d14d0:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f0d14d4:	44873000 */ 	mtc1	$a3,$f6
.PF0f0d14d8:
/*  f0d14d8:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d14dc:	44815000 */ 	mtc1	$at,$f10
/*  f0d14e0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d14e4:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0d14e8:	e7a4008c */ 	swc1	$f4,0x8c($sp)
.PF0f0d14ec:
/*  f0d14ec:	44863000 */ 	mtc1	$a2,$f6
/*  f0d14f0:	448a5000 */ 	mtc1	$t2,$f10
/*  f0d14f4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d14f8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d14fc:	c426ed7c */ 	lwc1	$f6,-0x1284($at)
/*  f0d1500:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d1504:	e7a8009c */ 	swc1	$f8,0x9c($sp)
/*  f0d1508:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d150c:	e7a80094 */ 	swc1	$f8,0x94($sp)
.PF0f0d1510:
/*  f0d1510:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d1514:	44816000 */ 	mtc1	$at,$f12
/*  f0d1518:	3c018007 */ 	lui	$at,0x8007
/*  f0d151c:	a02011a0 */ 	sb	$zero,0x11a0($at)
/*  f0d1520:	8d240038 */ 	lw	$a0,0x38($t1)
/*  f0d1524:	46006006 */ 	mov.s	$f0,$f12
/*  f0d1528:	44845000 */ 	mtc1	$a0,$f10
/*  f0d152c:	00000000 */ 	nop
/*  f0d1530:	468050a0 */ 	cvt.s.w	$f2,$f10
/*  f0d1534:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0d1538:	00000000 */ 	nop
/*  f0d153c:	4500000a */ 	bc1f	.PF0f0d1568
/*  f0d1540:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1544:	c432ed80 */ 	lwc1	$f18,-0x1280($at)
/*  f0d1548:	c7ae00e0 */ 	lwc1	$f14,0xe0($sp)
/*  f0d154c:	460c0000 */ 	add.s	$f0,$f0,$f12
.PF0f0d1550:
/*  f0d1550:	46127382 */ 	mul.s	$f14,$f14,$f18
/*  f0d1554:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0d1558:	00000000 */ 	nop
/*  f0d155c:	4503fffc */ 	bc1tl	.PF0f0d1550
/*  f0d1560:	460c0000 */ 	add.s	$f0,$f0,$f12
/*  f0d1564:	e7ae00e0 */ 	swc1	$f14,0xe0($sp)
.PF0f0d1568:
/*  f0d1568:	8da30480 */ 	lw	$v1,0x480($t5)
/*  f0d156c:	c7ae00e0 */ 	lwc1	$f14,0xe0($sp)
/*  f0d1570:	80620036 */ 	lb	$v0,0x36($v1)
/*  f0d1574:	28410029 */ 	slti	$at,$v0,0x29
/*  f0d1578:	10200003 */ 	beqz	$at,.PF0f0d1588
/*  f0d157c:	0044c821 */ 	addu	$t9,$v0,$a0
/*  f0d1580:	10000003 */ 	b	.PF0f0d1590
/*  f0d1584:	a0790036 */ 	sb	$t9,0x36($v1)
.PF0f0d1588:
/*  f0d1588:	240e0029 */ 	li	$t6,0x29
/*  f0d158c:	a06e0036 */ 	sb	$t6,0x36($v1)
.PF0f0d1590:
/*  f0d1590:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1594:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f0d1598:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0d159c:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d15a0:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f0d15a4:	c7240008 */ 	lwc1	$f4,0x8($t9)
/*  f0d15a8:	e44400c8 */ 	swc1	$f4,0xc8($v0)
/*  f0d15ac:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d15b0:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d15b4:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0d15b8:	c706000c */ 	lwc1	$f6,0xc($t8)
/*  f0d15bc:	e44600cc */ 	swc1	$f6,0xcc($v0)
/*  f0d15c0:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d15c4:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f0d15c8:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f0d15cc:	c5e80010 */ 	lwc1	$f8,0x10($t7)
/*  f0d15d0:	e44800d0 */ 	swc1	$f8,0xd0($v0)
/*  f0d15d4:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d15d8:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f0d15dc:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0d15e0:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d15e4:	e7ae00e0 */ 	swc1	$f14,0xe0($sp)
/*  f0d15e8:	0fc1968d */ 	jal	0xf065a34
/*  f0d15ec:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f0d15f0:	0fc449df */ 	jal	0xf11277c
/*  f0d15f4:	2404002e */ 	li	$a0,0x2e
/*  f0d15f8:	3c09800a */ 	lui	$t1,0x800a
/*  f0d15fc:	44808000 */ 	mtc1	$zero,$f16
/*  f0d1600:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d1604:	1440001e */ 	bnez	$v0,.PF0f0d1680
/*  f0d1608:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d160c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1610:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f0d1614:	24180001 */ 	li	$t8,0x1
/*  f0d1618:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d161c:	24010048 */ 	li	$at,0x48
/*  f0d1620:	a1e00035 */ 	sb	$zero,0x35($t7)
/*  f0d1624:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1628:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f0d162c:	a1d80034 */ 	sb	$t8,0x34($t6)
/*  f0d1630:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1634:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f0d1638:	a3200037 */ 	sb	$zero,0x37($t9)
/*  f0d163c:	8c580018 */ 	lw	$t8,0x18($v0)
/*  f0d1640:	370e0400 */ 	ori	$t6,$t8,0x400
/*  f0d1644:	ac4e0018 */ 	sw	$t6,0x18($v0)
/*  f0d1648:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d164c:	8d2e0338 */ 	lw	$t6,0x338($t1)
/*  f0d1650:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f0d1654:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f0d1658:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d165c:	030e2023 */ 	subu	$a0,$t8,$t6
/*  f0d1660:	0081001a */ 	div	$zero,$a0,$at
/*  f0d1664:	00002012 */ 	mflo	$a0
/*  f0d1668:	0fc0842c */ 	jal	0xf0210b0
/*  f0d166c:	00000000 */ 	nop
/*  f0d1670:	3c09800a */ 	lui	$t1,0x800a
/*  f0d1674:	44808000 */ 	mtc1	$zero,$f16
/*  f0d1678:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d167c:	83bf00c2 */ 	lb	$ra,0xc2($sp)
.PF0f0d1680:
/*  f0d1680:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d1684:	8da30480 */ 	lw	$v1,0x480($t5)
/*  f0d1688:	80790037 */ 	lb	$t9,0x37($v1)
/*  f0d168c:	532001c8 */ 	beqzl	$t9,.PF0f0d1db0
/*  f0d1690:	24190001 */ 	li	$t9,0x1
/*  f0d1694:	8d38028c */ 	lw	$t8,0x28c($t1)
/*  f0d1698:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0d169c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f0d16a0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0d16a4:	8def0a30 */ 	lw	$t7,0xa30($t7)
/*  f0d16a8:	51e001c1 */ 	beqzl	$t7,.PF0f0d1db0
/*  f0d16ac:	24190001 */ 	li	$t9,0x1
/*  f0d16b0:	449f5000 */ 	mtc1	$ra,$f10
/*  f0d16b4:	3c013d80 */ 	lui	$at,0x3d80
/*  f0d16b8:	44813000 */ 	mtc1	$at,$f6
/*  f0d16bc:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d16c0:	2419ffff */ 	li	$t9,-1
/*  f0d16c4:	adb91c40 */ 	sw	$t9,0x1c40($t5)
/*  f0d16c8:	c52a004c */ 	lwc1	$f10,0x4c($t1)
/*  f0d16cc:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d16d0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d16d4:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d16d8:	c466001c */ 	lwc1	$f6,0x1c($v1)
/*  f0d16dc:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0d16e0:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0d16e4:	e468001c */ 	swc1	$f8,0x1c($v1)
/*  f0d16e8:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d16ec:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d16f0:	c460001c */ 	lwc1	$f0,0x1c($v1)
/*  f0d16f4:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0d16f8:	00000000 */ 	nop
/*  f0d16fc:	4500000c */ 	bc1f	.PF0f0d1730
/*  f0d1700:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d1704:	44817000 */ 	mtc1	$at,$f14
/*  f0d1708:	00000000 */ 	nop
/*  f0d170c:	460e0280 */ 	add.s	$f10,$f0,$f14
.PF0f0d1710:
/*  f0d1710:	e46a001c */ 	swc1	$f10,0x1c($v1)
/*  f0d1714:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1718:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d171c:	c460001c */ 	lwc1	$f0,0x1c($v1)
/*  f0d1720:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0d1724:	00000000 */ 	nop
/*  f0d1728:	4503fff9 */ 	bc1tl	.PF0f0d1710
/*  f0d172c:	460e0280 */ 	add.s	$f10,$f0,$f14
.PF0f0d1730:
/*  f0d1730:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d1734:	44817000 */ 	mtc1	$at,$f14
/*  f0d1738:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d173c:	4600703e */ 	c.le.s	$f14,$f0
/*  f0d1740:	00000000 */ 	nop
/*  f0d1744:	4500000a */ 	bc1f	.PF0f0d1770
/*  f0d1748:	00000000 */ 	nop
/*  f0d174c:	460e0181 */ 	sub.s	$f6,$f0,$f14
.PF0f0d1750:
/*  f0d1750:	e466001c */ 	swc1	$f6,0x1c($v1)
/*  f0d1754:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1758:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d175c:	c460001c */ 	lwc1	$f0,0x1c($v1)
/*  f0d1760:	4600703e */ 	c.le.s	$f14,$f0
/*  f0d1764:	00000000 */ 	nop
/*  f0d1768:	4503fff9 */ 	bc1tl	.PF0f0d1750
/*  f0d176c:	460e0181 */ 	sub.s	$f6,$f0,$f14
.PF0f0d1770:
/*  f0d1770:	c424ed84 */ 	lwc1	$f4,-0x127c($at)
/*  f0d1774:	46040302 */ 	mul.s	$f12,$f0,$f4
/*  f0d1778:	0c006858 */ 	jal	0x1a160
/*  f0d177c:	00000000 */ 	nop
/*  f0d1780:	3c09800a */ 	lui	$t1,0x800a
/*  f0d1784:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d1788:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d178c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1790:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1794:	e5c00020 */ 	swc1	$f0,0x20($t6)
/*  f0d1798:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d179c:	c42aed88 */ 	lwc1	$f10,-0x1278($at)
/*  f0d17a0:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f0d17a4:	c728001c */ 	lwc1	$f8,0x1c($t9)
/*  f0d17a8:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f0d17ac:	0c00685b */ 	jal	0x1a16c
/*  f0d17b0:	00000000 */ 	nop
/*  f0d17b4:	3c09800a */ 	lui	$t1,0x800a
/*  f0d17b8:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d17bc:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d17c0:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d17c4:	44817000 */ 	mtc1	$at,$f14
/*  f0d17c8:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d17cc:	3c013d80 */ 	lui	$at,0x3d80
/*  f0d17d0:	44812000 */ 	mtc1	$at,$f4
/*  f0d17d4:	e5c00024 */ 	swc1	$f0,0x24($t6)
/*  f0d17d8:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f0d17dc:	c52a004c */ 	lwc1	$f10,0x4c($t1)
/*  f0d17e0:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d17e4:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0d17e8:	44808000 */ 	mtc1	$zero,$f16
/*  f0d17ec:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d17f0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d17f4:	c4640028 */ 	lwc1	$f4,0x28($v1)
/*  f0d17f8:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f0d17fc:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0d1800:	e4680028 */ 	swc1	$f8,0x28($v1)
/*  f0d1804:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1808:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f0d180c:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1810:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d1814:	46025032 */ 	c.eq.s	$f10,$f2
/*  f0d1818:	00000000 */ 	nop
/*  f0d181c:	45030037 */ 	bc1tl	.PF0f0d18fc
/*  f0d1820:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f0d1824:	4610103c */ 	c.lt.s	$f2,$f16
/*  f0d1828:	00000000 */ 	nop
/*  f0d182c:	4502000b */ 	bc1fl	.PF0f0d185c
/*  f0d1830:	4602703e */ 	c.le.s	$f14,$f2
/*  f0d1834:	460e1100 */ 	add.s	$f4,$f2,$f14
.PF0f0d1838:
/*  f0d1838:	e4640028 */ 	swc1	$f4,0x28($v1)
/*  f0d183c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1840:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1844:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d1848:	4610103c */ 	c.lt.s	$f2,$f16
/*  f0d184c:	00000000 */ 	nop
/*  f0d1850:	4503fff9 */ 	bc1tl	.PF0f0d1838
/*  f0d1854:	460e1100 */ 	add.s	$f4,$f2,$f14
/*  f0d1858:	4602703e */ 	c.le.s	$f14,$f2
.PF0f0d185c:
/*  f0d185c:	00000000 */ 	nop
/*  f0d1860:	4500000a */ 	bc1f	.PF0f0d188c
/*  f0d1864:	00000000 */ 	nop
/*  f0d1868:	460e1181 */ 	sub.s	$f6,$f2,$f14
.PF0f0d186c:
/*  f0d186c:	e4660028 */ 	swc1	$f6,0x28($v1)
/*  f0d1870:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1874:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1878:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d187c:	4602703e */ 	c.le.s	$f14,$f2
/*  f0d1880:	00000000 */ 	nop
/*  f0d1884:	4503fff9 */ 	bc1tl	.PF0f0d186c
/*  f0d1888:	460e1181 */ 	sub.s	$f6,$f2,$f14
.PF0f0d188c:
/*  f0d188c:	c428ed8c */ 	lwc1	$f8,-0x1274($at)
/*  f0d1890:	46081302 */ 	mul.s	$f12,$f2,$f8
/*  f0d1894:	0c006858 */ 	jal	0x1a160
/*  f0d1898:	00000000 */ 	nop
/*  f0d189c:	3c09800a */ 	lui	$t1,0x800a
/*  f0d18a0:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d18a4:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d18a8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d18ac:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f0d18b0:	e720002c */ 	swc1	$f0,0x2c($t9)
/*  f0d18b4:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d18b8:	c424ed90 */ 	lwc1	$f4,-0x1270($at)
/*  f0d18bc:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d18c0:	c5ca0028 */ 	lwc1	$f10,0x28($t6)
/*  f0d18c4:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f0d18c8:	0c00685b */ 	jal	0x1a16c
/*  f0d18cc:	00000000 */ 	nop
/*  f0d18d0:	3c09800a */ 	lui	$t1,0x800a
/*  f0d18d4:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d18d8:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d18dc:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d18e0:	44817000 */ 	mtc1	$at,$f14
/*  f0d18e4:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f0d18e8:	44808000 */ 	mtc1	$zero,$f16
/*  f0d18ec:	e7200030 */ 	swc1	$f0,0x30($t9)
/*  f0d18f0:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d18f4:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d18f8:	8fae00b4 */ 	lw	$t6,0xb4($sp)
.PF0f0d18fc:
/*  f0d18fc:	e7b000c4 */ 	swc1	$f16,0xc4($sp)
/*  f0d1900:	46008486 */ 	mov.s	$f18,$f16
/*  f0d1904:	e7b000cc */ 	swc1	$f16,0xcc($sp)
/*  f0d1908:	e7b000d0 */ 	swc1	$f16,0xd0($sp)
/*  f0d190c:	11c00069 */ 	beqz	$t6,.PF0f0d1ab4
/*  f0d1910:	e7b000d4 */ 	swc1	$f16,0xd4($sp)
/*  f0d1914:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d1918:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f0d191c:	4602803c */ 	c.lt.s	$f16,$f2
/*  f0d1920:	00000000 */ 	nop
/*  f0d1924:	45020051 */ 	bc1fl	.PF0f0d1a6c
/*  f0d1928:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f0d192c:	44804000 */ 	mtc1	$zero,$f8
/*  f0d1930:	3c014334 */ 	lui	$at,0x4334
/*  f0d1934:	46083032 */ 	c.eq.s	$f6,$f8
/*  f0d1938:	00000000 */ 	nop
/*  f0d193c:	4503004b */ 	bc1tl	.PF0f0d1a6c
/*  f0d1940:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f0d1944:	44815000 */ 	mtc1	$at,$f10
/*  f0d1948:	00000000 */ 	nop
/*  f0d194c:	460a103c */ 	c.lt.s	$f2,$f10
/*  f0d1950:	00000000 */ 	nop
/*  f0d1954:	45020017 */ 	bc1fl	.PF0f0d19b4
/*  f0d1958:	8d390038 */ 	lw	$t9,0x38($t1)
/*  f0d195c:	8d2f0038 */ 	lw	$t7,0x38($t1)
/*  f0d1960:	46001006 */ 	mov.s	$f0,$f2
/*  f0d1964:	00001025 */ 	move	$v0,$zero
/*  f0d1968:	19e00025 */ 	blez	$t7,.PF0f0d1a00
/*  f0d196c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1970:	c422ed94 */ 	lwc1	$f2,-0x126c($at)
/*  f0d1974:	8d390284 */ 	lw	$t9,0x284($t1)
.PF0f0d1978:
/*  f0d1978:	46020002 */ 	mul.s	$f0,$f0,$f2
/*  f0d197c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d1980:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1984:	c4640028 */ 	lwc1	$f4,0x28($v1)
/*  f0d1988:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0d198c:	e4660028 */ 	swc1	$f6,0x28($v1)
/*  f0d1990:	8d380038 */ 	lw	$t8,0x38($t1)
/*  f0d1994:	0058082a */ 	slt	$at,$v0,$t8
/*  f0d1998:	5420fff7 */ 	bnezl	$at,.PF0f0d1978
/*  f0d199c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d19a0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d19a4:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d19a8:	10000015 */ 	b	.PF0f0d1a00
/*  f0d19ac:	c5e20028 */ 	lwc1	$f2,0x28($t7)
/*  f0d19b0:	8d390038 */ 	lw	$t9,0x38($t1)
.PF0f0d19b4:
/*  f0d19b4:	46027001 */ 	sub.s	$f0,$f14,$f2
/*  f0d19b8:	00001025 */ 	move	$v0,$zero
/*  f0d19bc:	1b200010 */ 	blez	$t9,.PF0f0d1a00
/*  f0d19c0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d19c4:	c422ed98 */ 	lwc1	$f2,-0x1268($at)
/*  f0d19c8:	8d380284 */ 	lw	$t8,0x284($t1)
.PF0f0d19cc:
/*  f0d19cc:	46020002 */ 	mul.s	$f0,$f0,$f2
/*  f0d19d0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d19d4:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d19d8:	c4680028 */ 	lwc1	$f8,0x28($v1)
/*  f0d19dc:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f0d19e0:	e46a0028 */ 	swc1	$f10,0x28($v1)
/*  f0d19e4:	8d2e0038 */ 	lw	$t6,0x38($t1)
/*  f0d19e8:	004e082a */ 	slt	$at,$v0,$t6
/*  f0d19ec:	5420fff7 */ 	bnezl	$at,.PF0f0d19cc
/*  f0d19f0:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d19f4:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d19f8:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f0d19fc:	c7220028 */ 	lwc1	$f2,0x28($t9)
.PF0f0d1a00:
/*  f0d1a00:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1a04:	c424ed9c */ 	lwc1	$f4,-0x1264($at)
/*  f0d1a08:	46041302 */ 	mul.s	$f12,$f2,$f4
/*  f0d1a0c:	0c006858 */ 	jal	0x1a160
/*  f0d1a10:	00000000 */ 	nop
/*  f0d1a14:	3c09800a */ 	lui	$t1,0x800a
/*  f0d1a18:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d1a1c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1a20:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1a24:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1a28:	e5c0002c */ 	swc1	$f0,0x2c($t6)
/*  f0d1a2c:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1a30:	c428eda0 */ 	lwc1	$f8,-0x1260($at)
/*  f0d1a34:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f0d1a38:	c7260028 */ 	lwc1	$f6,0x28($t9)
/*  f0d1a3c:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f0d1a40:	0c00685b */ 	jal	0x1a16c
/*  f0d1a44:	00000000 */ 	nop
/*  f0d1a48:	3c09800a */ 	lui	$t1,0x800a
/*  f0d1a4c:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d1a50:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1a54:	44808000 */ 	mtc1	$zero,$f16
/*  f0d1a58:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1a5c:	e5c00030 */ 	swc1	$f0,0x30($t6)
/*  f0d1a60:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1a64:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1a68:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
.PF0f0d1a6c:
/*  f0d1a6c:	c4640024 */ 	lwc1	$f4,0x24($v1)
/*  f0d1a70:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1a74:	c42ceda4 */ 	lwc1	$f12,-0x125c($at)
/*  f0d1a78:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0d1a7c:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d1a80:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f0d1a84:	00000000 */ 	nop
/*  f0d1a88:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f0d1a8c:	46005207 */ 	neg.s	$f8,$f10
/*  f0d1a90:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f0d1a94:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0d1a98:	c4640020 */ 	lwc1	$f4,0x20($v1)
/*  f0d1a9c:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0d1aa0:	00000000 */ 	nop
/*  f0d1aa4:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f0d1aa8:	00000000 */ 	nop
/*  f0d1aac:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0d1ab0:	46088480 */ 	add.s	$f18,$f16,$f8
.PF0f0d1ab4:
/*  f0d1ab4:	c7a40094 */ 	lwc1	$f4,0x94($sp)
/*  f0d1ab8:	44803000 */ 	mtc1	$zero,$f6
/*  f0d1abc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1ac0:	c42ceda8 */ 	lwc1	$f12,-0x1258($at)
/*  f0d1ac4:	46062032 */ 	c.eq.s	$f4,$f6
/*  f0d1ac8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0d1acc:	45030016 */ 	bc1tl	.PF0f0d1b28
/*  f0d1ad0:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0d1ad4:	44815000 */ 	mtc1	$at,$f10
/*  f0d1ad8:	c4680020 */ 	lwc1	$f8,0x20($v1)
/*  f0d1adc:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d1ae0:	460a2002 */ 	mul.s	$f0,$f4,$f10
/*  f0d1ae4:	00000000 */ 	nop
/*  f0d1ae8:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f0d1aec:	00000000 */ 	nop
/*  f0d1af0:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*  f0d1af4:	00000000 */ 	nop
/*  f0d1af8:	46022282 */ 	mul.s	$f10,$f4,$f2
/*  f0d1afc:	460a8200 */ 	add.s	$f8,$f16,$f10
/*  f0d1b00:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f0d1b04:	c4660024 */ 	lwc1	$f6,0x24($v1)
/*  f0d1b08:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0d1b0c:	00000000 */ 	nop
/*  f0d1b10:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0d1b14:	00000000 */ 	nop
/*  f0d1b18:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0d1b1c:	46088180 */ 	add.s	$f6,$f16,$f8
/*  f0d1b20:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f0d1b24:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
.PF0f0d1b28:
/*  f0d1b28:	44805000 */ 	mtc1	$zero,$f10
/*  f0d1b2c:	3c014040 */ 	lui	$at,0x4040
/*  f0d1b30:	460a2032 */ 	c.eq.s	$f4,$f10
/*  f0d1b34:	00000000 */ 	nop
/*  f0d1b38:	45030019 */ 	bc1tl	.PF0f0d1ba0
/*  f0d1b3c:	c468006c */ 	lwc1	$f8,0x6c($v1)
/*  f0d1b40:	44814000 */ 	mtc1	$at,$f8
/*  f0d1b44:	4610203c */ 	c.lt.s	$f4,$f16
/*  f0d1b48:	24180001 */ 	li	$t8,0x1
/*  f0d1b4c:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0d1b50:	c528004c */ 	lwc1	$f8,0x4c($t1)
/*  f0d1b54:	2419ffff */ 	li	$t9,-1
/*  f0d1b58:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f0d1b5c:	00000000 */ 	nop
/*  f0d1b60:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d1b64:	46068280 */ 	add.s	$f10,$f16,$f6
/*  f0d1b68:	45000003 */ 	bc1f	.PF0f0d1b78
/*  f0d1b6c:	e7aa00c4 */ 	swc1	$f10,0xc4($sp)
/*  f0d1b70:	10000002 */ 	b	.PF0f0d1b7c
/*  f0d1b74:	a479003a */ 	sh	$t9,0x3a($v1)
.PF0f0d1b78:
/*  f0d1b78:	a478003a */ 	sh	$t8,0x3a($v1)
.PF0f0d1b7c:
/*  f0d1b7c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1b80:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d1b84:	a1e0003c */ 	sb	$zero,0x3c($t7)
/*  f0d1b88:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1b8c:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f0d1b90:	a300003d */ 	sb	$zero,0x3d($t8)
/*  f0d1b94:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1b98:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1b9c:	c468006c */ 	lwc1	$f8,0x6c($v1)
.PF0f0d1ba0:
/*  f0d1ba0:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f0d1ba4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1ba8:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0d1bac:	e46a006c */ 	swc1	$f10,0x6c($v1)
/*  f0d1bb0:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1bb4:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1bb8:	c4640070 */ 	lwc1	$f4,0x70($v1)
/*  f0d1bbc:	46122200 */ 	add.s	$f8,$f4,$f18
/*  f0d1bc0:	e4680070 */ 	swc1	$f8,0x70($v1)
/*  f0d1bc4:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1bc8:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0d1bcc:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1bd0:	c4660074 */ 	lwc1	$f6,0x74($v1)
/*  f0d1bd4:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f0d1bd8:	e4640074 */ 	swc1	$f4,0x74($v1)
/*  f0d1bdc:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1be0:	c7a600d0 */ 	lwc1	$f6,0xd0($sp)
/*  f0d1be4:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1be8:	c4680078 */ 	lwc1	$f8,0x78($v1)
/*  f0d1bec:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0d1bf0:	e46a0078 */ 	swc1	$f10,0x78($v1)
/*  f0d1bf4:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1bf8:	c42aedac */ 	lwc1	$f10,-0x1254($at)
/*  f0d1bfc:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d1c00:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1c04:	c46c0070 */ 	lwc1	$f12,0x70($v1)
/*  f0d1c08:	c460006c */ 	lwc1	$f0,0x6c($v1)
/*  f0d1c0c:	460c6102 */ 	mul.s	$f4,$f12,$f12
/*  f0d1c10:	00000000 */ 	nop
/*  f0d1c14:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f0d1c18:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0d1c1c:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f0d1c20:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0d1c24:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0d1c28:	4606403c */ 	c.lt.s	$f8,$f6
/*  f0d1c2c:	00000000 */ 	nop
/*  f0d1c30:	45000018 */ 	bc1f	.PF0f0d1c94
/*  f0d1c34:	00000000 */ 	nop
/*  f0d1c38:	0c0127b4 */ 	jal	0x49ed0
/*  f0d1c3c:	46003306 */ 	mov.s	$f12,$f6
/*  f0d1c40:	3c09800a */ 	lui	$t1,0x800a
/*  f0d1c44:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d1c48:	3c014118 */ 	lui	$at,0x4118
/*  f0d1c4c:	44815000 */ 	mtc1	$at,$f10
/*  f0d1c50:	c524004c */ 	lwc1	$f4,0x4c($t1)
/*  f0d1c54:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1c58:	44808000 */ 	mtc1	$zero,$f16
/*  f0d1c5c:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f0d1c60:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1c64:	c466006c */ 	lwc1	$f6,0x6c($v1)
/*  f0d1c68:	46004303 */ 	div.s	$f12,$f8,$f0
/*  f0d1c6c:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f0d1c70:	e46a006c */ 	swc1	$f10,0x6c($v1)
/*  f0d1c74:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1c78:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1c7c:	c4640070 */ 	lwc1	$f4,0x70($v1)
/*  f0d1c80:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*  f0d1c84:	e4680070 */ 	swc1	$f8,0x70($v1)
/*  f0d1c88:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1c8c:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d1c90:	8f030480 */ 	lw	$v1,0x480($t8)
.PF0f0d1c94:
/*  f0d1c94:	c46c0078 */ 	lwc1	$f12,0x78($v1)
/*  f0d1c98:	c4600074 */ 	lwc1	$f0,0x74($v1)
/*  f0d1c9c:	3c014361 */ 	lui	$at,0x4361
/*  f0d1ca0:	460c6182 */ 	mul.s	$f6,$f12,$f12
/*  f0d1ca4:	44814000 */ 	mtc1	$at,$f8
/*  f0d1ca8:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f0d1cac:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f0d1cb0:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0d1cb4:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f0d1cb8:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f0d1cbc:	4604503c */ 	c.lt.s	$f10,$f4
/*  f0d1cc0:	00000000 */ 	nop
/*  f0d1cc4:	4502001a */ 	bc1fl	.PF0f0d1d30
/*  f0d1cc8:	c4660044 */ 	lwc1	$f6,0x44($v1)
/*  f0d1ccc:	0c0127b4 */ 	jal	0x49ed0
/*  f0d1cd0:	46002306 */ 	mov.s	$f12,$f4
/*  f0d1cd4:	3c09800a */ 	lui	$t1,0x800a
/*  f0d1cd8:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d1cdc:	3c014170 */ 	lui	$at,0x4170
/*  f0d1ce0:	44814000 */ 	mtc1	$at,$f8
/*  f0d1ce4:	c526004c */ 	lwc1	$f6,0x4c($t1)
/*  f0d1ce8:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1cec:	44808000 */ 	mtc1	$zero,$f16
/*  f0d1cf0:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0d1cf4:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0d1cf8:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f0d1cfc:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1d00:	c4680074 */ 	lwc1	$f8,0x74($v1)
/*  f0d1d04:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0d1d08:	e4660074 */ 	swc1	$f6,0x74($v1)
/*  f0d1d0c:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1d10:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0d1d14:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1d18:	c46a0078 */ 	lwc1	$f10,0x78($v1)
/*  f0d1d1c:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0d1d20:	e4640078 */ 	swc1	$f4,0x78($v1)
/*  f0d1d24:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1d28:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1d2c:	c4660044 */ 	lwc1	$f6,0x44($v1)
.PF0f0d1d30:
/*  f0d1d30:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f0d1d34:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0d1d38:	44812000 */ 	mtc1	$at,$f4
/*  f0d1d3c:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0d1d40:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0d1d44:	e4680044 */ 	swc1	$f8,0x44($v1)
/*  f0d1d48:	c526004c */ 	lwc1	$f6,0x4c($t1)
/*  f0d1d4c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1d50:	46062082 */ 	mul.s	$f2,$f4,$f6
/*  f0d1d54:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1d58:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f0d1d5c:	46001307 */ 	neg.s	$f12,$f2
/*  f0d1d60:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0d1d64:	00000000 */ 	nop
/*  f0d1d68:	45020009 */ 	bc1fl	.PF0f0d1d90
/*  f0d1d6c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0d1d70:	e46c0044 */ 	swc1	$f12,0x44($v1)
/*  f0d1d74:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1d78:	c528004c */ 	lwc1	$f8,0x4c($t1)
/*  f0d1d7c:	44815000 */ 	mtc1	$at,$f10
/*  f0d1d80:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1d84:	46085082 */ 	mul.s	$f2,$f10,$f8
/*  f0d1d88:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f0d1d8c:	4600103c */ 	c.lt.s	$f2,$f0
.PF0f0d1d90:
/*  f0d1d90:	00000000 */ 	nop
/*  f0d1d94:	4502000a */ 	bc1fl	.PF0f0d1dc0
/*  f0d1d98:	c7a400c4 */ 	lwc1	$f4,0xc4($sp)
/*  f0d1d9c:	e4620044 */ 	swc1	$f2,0x44($v1)
/*  f0d1da0:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1da4:	10000005 */ 	b	.PF0f0d1dbc
/*  f0d1da8:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1dac:	24190001 */ 	li	$t9,0x1
.PF0f0d1db0:
/*  f0d1db0:	a079003d */ 	sb	$t9,0x3d($v1)
/*  f0d1db4:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1db8:	8f030480 */ 	lw	$v1,0x480($t8)
.PF0f0d1dbc:
/*  f0d1dbc:	c7a400c4 */ 	lwc1	$f4,0xc4($sp)
.PF0f0d1dc0:
/*  f0d1dc0:	46102032 */ 	c.eq.s	$f4,$f16
/*  f0d1dc4:	00000000 */ 	nop
/*  f0d1dc8:	45020037 */ 	bc1fl	.PF0f0d1ea8
/*  f0d1dcc:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f0d1dd0:	906e003d */ 	lbu	$t6,0x3d($v1)
/*  f0d1dd4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1dd8:	240f0001 */ 	li	$t7,0x1
/*  f0d1ddc:	55c00011 */ 	bnezl	$t6,.PF0f0d1e24
/*  f0d1de0:	a06f003d */ 	sb	$t7,0x3d($v1)
/*  f0d1de4:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f0d1de8:	44803000 */ 	mtc1	$zero,$f6
/*  f0d1dec:	00000000 */ 	nop
/*  f0d1df0:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0d1df4:	00000000 */ 	nop
/*  f0d1df8:	45020004 */ 	bc1fl	.PF0f0d1e0c
/*  f0d1dfc:	46000087 */ 	neg.s	$f2,$f0
/*  f0d1e00:	10000002 */ 	b	.PF0f0d1e0c
/*  f0d1e04:	46000086 */ 	mov.s	$f2,$f0
/*  f0d1e08:	46000087 */ 	neg.s	$f2,$f0
.PF0f0d1e0c:
/*  f0d1e0c:	c42aedb0 */ 	lwc1	$f10,-0x1250($at)
/*  f0d1e10:	460a103c */ 	c.lt.s	$f2,$f10
/*  f0d1e14:	00000000 */ 	nop
/*  f0d1e18:	45020023 */ 	bc1fl	.PF0f0d1ea8
/*  f0d1e1c:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f0d1e20:	a06f003d */ 	sb	$t7,0x3d($v1)
.PF0f0d1e24:
/*  f0d1e24:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1e28:	8d2e0038 */ 	lw	$t6,0x38($t1)
/*  f0d1e2c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d1e30:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1e34:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0d1e38:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f0d1e3c:	a06f003c */ 	sb	$t7,0x3c($v1)
/*  f0d1e40:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1e44:	c428edb4 */ 	lwc1	$f8,-0x124c($at)
/*  f0d1e48:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1e4c:	8478003a */ 	lh	$t8,0x3a($v1)
/*  f0d1e50:	44982000 */ 	mtc1	$t8,$f4
/*  f0d1e54:	00000000 */ 	nop
/*  f0d1e58:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d1e5c:	c4640044 */ 	lwc1	$f4,0x44($v1)
/*  f0d1e60:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0d1e64:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0d1e68:	e4680044 */ 	swc1	$f8,0x44($v1)
/*  f0d1e6c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1e70:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1e74:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0d1e78:	29e10065 */ 	slti	$at,$t7,0x65
/*  f0d1e7c:	5420000a */ 	bnezl	$at,.PF0f0d1ea8
/*  f0d1e80:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f0d1e84:	a060003c */ 	sb	$zero,0x3c($v1)
/*  f0d1e88:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1e8c:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1e90:	8478003a */ 	lh	$t8,0x3a($v1)
/*  f0d1e94:	00187023 */ 	negu	$t6,$t8
/*  f0d1e98:	a46e003a */ 	sh	$t6,0x3a($v1)
/*  f0d1e9c:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1ea0:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1ea4:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
.PF0f0d1ea8:
/*  f0d1ea8:	c4660044 */ 	lwc1	$f6,0x44($v1)
/*  f0d1eac:	3c028007 */ 	lui	$v0,0x8007
/*  f0d1eb0:	244211a4 */ 	addiu	$v0,$v0,0x11a4
/*  f0d1eb4:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f0d1eb8:	3c018007 */ 	lui	$at,0x8007
/*  f0d1ebc:	e4640044 */ 	swc1	$f4,0x44($v1)
/*  f0d1ec0:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1ec4:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1ec8:	c46a0074 */ 	lwc1	$f10,0x74($v1)
/*  f0d1ecc:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f0d1ed0:	e4680074 */ 	swc1	$f8,0x74($v1)
/*  f0d1ed4:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1ed8:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1edc:	c4660078 */ 	lwc1	$f6,0x78($v1)
/*  f0d1ee0:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f0d1ee4:	e4640078 */ 	swc1	$f4,0x78($v1)
/*  f0d1ee8:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1eec:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1ef0:	c46a006c */ 	lwc1	$f10,0x6c($v1)
/*  f0d1ef4:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f0d1ef8:	e468006c */ 	swc1	$f8,0x6c($v1)
/*  f0d1efc:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1f00:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1f04:	c4660070 */ 	lwc1	$f6,0x70($v1)
/*  f0d1f08:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f0d1f0c:	e4640070 */ 	swc1	$f4,0x70($v1)
/*  f0d1f10:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1f14:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1f18:	c46a006c */ 	lwc1	$f10,0x6c($v1)
/*  f0d1f1c:	c4680074 */ 	lwc1	$f8,0x74($v1)
/*  f0d1f20:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0d1f24:	e4660040 */ 	swc1	$f6,0x40($v1)
/*  f0d1f28:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1f2c:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1f30:	c4640070 */ 	lwc1	$f4,0x70($v1)
/*  f0d1f34:	c46a0078 */ 	lwc1	$f10,0x78($v1)
/*  f0d1f38:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0d1f3c:	e4680048 */ 	swc1	$f8,0x48($v1)
/*  f0d1f40:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1f44:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1f48:	c4660030 */ 	lwc1	$f6,0x30($v1)
/*  f0d1f4c:	e4660008 */ 	swc1	$f6,0x8($v1)
/*  f0d1f50:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1f54:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1f58:	c464002c */ 	lwc1	$f4,0x2c($v1)
/*  f0d1f5c:	c46a0024 */ 	lwc1	$f10,0x24($v1)
/*  f0d1f60:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f0d1f64:	e4680004 */ 	swc1	$f8,0x4($v1)
/*  f0d1f68:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1f6c:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1f70:	c466002c */ 	lwc1	$f6,0x2c($v1)
/*  f0d1f74:	c46a0020 */ 	lwc1	$f10,0x20($v1)
/*  f0d1f78:	46003107 */ 	neg.s	$f4,$f6
/*  f0d1f7c:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f0d1f80:	e468000c */ 	swc1	$f8,0xc($v1)
/*  f0d1f84:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1f88:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1f8c:	c466002c */ 	lwc1	$f6,0x2c($v1)
/*  f0d1f90:	e4660014 */ 	swc1	$f6,0x14($v1)
/*  f0d1f94:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1f98:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1f9c:	c4640030 */ 	lwc1	$f4,0x30($v1)
/*  f0d1fa0:	c4680024 */ 	lwc1	$f8,0x24($v1)
/*  f0d1fa4:	46002287 */ 	neg.s	$f10,$f4
/*  f0d1fa8:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d1fac:	e4660010 */ 	swc1	$f6,0x10($v1)
/*  f0d1fb0:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1fb4:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1fb8:	c4640030 */ 	lwc1	$f4,0x30($v1)
/*  f0d1fbc:	c46a0020 */ 	lwc1	$f10,0x20($v1)
/*  f0d1fc0:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f0d1fc4:	e4680018 */ 	swc1	$f8,0x18($v1)
/*  f0d1fc8:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f0d1fcc:	a03911a8 */ 	sb	$t9,0x11a8($at)
/*  f0d1fd0:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f0d1fd4:	3c018007 */ 	lui	$at,0x8007
/*  f0d1fd8:	0fc340f1 */ 	jal	0xf0d03c4
/*  f0d1fdc:	a02011ac */ 	sb	$zero,0x11ac($at)
/*  f0d1fe0:	3c09800a */ 	lui	$t1,0x800a
/*  f0d1fe4:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d1fe8:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1fec:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0d1ff0:	3c198007 */ 	lui	$t9,0x8007
/*  f0d1ff4:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1ff8:	806e0037 */ 	lb	$t6,0x37($v1)
/*  f0d1ffc:	51c0007f */ 	beqzl	$t6,.PF0f0d21fc
/*  f0d2000:	3c0144c8 */ 	lui	$at,0x44c8
/*  f0d2004:	91ef11a4 */ 	lbu	$t7,0x11a4($t7)
/*  f0d2008:	933911a8 */ 	lbu	$t9,0x11a8($t9)
/*  f0d200c:	532f007b */ 	beql	$t9,$t7,.PF0f0d21fc
/*  f0d2010:	3c0144c8 */ 	lui	$at,0x44c8
/*  f0d2014:	19e00078 */ 	blez	$t7,.PF0f0d21f8
/*  f0d2018:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0d201c:	8f0e0120 */ 	lw	$t6,0x120($t8)
/*  f0d2020:	25f9ffff */ 	addiu	$t9,$t7,-1
/*  f0d2024:	29c10009 */ 	slti	$at,$t6,0x9
/*  f0d2028:	14200073 */ 	bnez	$at,.PF0f0d21f8
/*  f0d202c:	2f210005 */ 	sltiu	$at,$t9,0x5
/*  f0d2030:	1020006f */ 	beqz	$at,.PF0f0d21f0
/*  f0d2034:	af000120 */ 	sw	$zero,0x120($t8)
/*  f0d2038:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0d203c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d2040:	00390821 */ 	addu	$at,$at,$t9
/*  f0d2044:	8c39edb8 */ 	lw	$t9,-0x1248($at)
/*  f0d2048:	03200008 */ 	jr	$t9
/*  f0d204c:	00000000 */ 	nop
/*  f0d2050:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d2054:	44813000 */ 	mtc1	$at,$f6
/*  f0d2058:	340e808c */ 	li	$t6,0x808c
/*  f0d205c:	24180001 */ 	li	$t8,0x1
/*  f0d2060:	240fffff */ 	li	$t7,-1
/*  f0d2064:	24190001 */ 	li	$t9,0x1
/*  f0d2068:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0d206c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0d2070:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0d2074:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0d2078:	00002025 */ 	move	$a0,$zero
/*  f0d207c:	00002825 */ 	move	$a1,$zero
/*  f0d2080:	24063e80 */ 	li	$a2,0x3e80
/*  f0d2084:	24070040 */ 	li	$a3,0x40
/*  f0d2088:	0c004125 */ 	jal	0x10494
/*  f0d208c:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0d2090:	3c09800a */ 	lui	$t1,0x800a
/*  f0d2094:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d2098:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d209c:	10000056 */ 	b	.PF0f0d21f8
/*  f0d20a0:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d20a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d20a8:	44812000 */ 	mtc1	$at,$f4
/*  f0d20ac:	3418808c */ 	li	$t8,0x808c
/*  f0d20b0:	240f0001 */ 	li	$t7,0x1
/*  f0d20b4:	2419ffff */ 	li	$t9,-1
/*  f0d20b8:	240e0001 */ 	li	$t6,0x1
/*  f0d20bc:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f0d20c0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0d20c4:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0d20c8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0d20cc:	00002025 */ 	move	$a0,$zero
/*  f0d20d0:	00002825 */ 	move	$a1,$zero
/*  f0d20d4:	24063e80 */ 	li	$a2,0x3e80
/*  f0d20d8:	24070040 */ 	li	$a3,0x40
/*  f0d20dc:	0c004125 */ 	jal	0x10494
/*  f0d20e0:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0d20e4:	3c09800a */ 	lui	$t1,0x800a
/*  f0d20e8:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d20ec:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d20f0:	10000041 */ 	b	.PF0f0d21f8
/*  f0d20f4:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d20f8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d20fc:	44815000 */ 	mtc1	$at,$f10
/*  f0d2100:	340f808c */ 	li	$t7,0x808c
/*  f0d2104:	24190001 */ 	li	$t9,0x1
/*  f0d2108:	240effff */ 	li	$t6,-1
/*  f0d210c:	24180001 */ 	li	$t8,0x1
/*  f0d2110:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0d2114:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0d2118:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0d211c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d2120:	00002025 */ 	move	$a0,$zero
/*  f0d2124:	00002825 */ 	move	$a1,$zero
/*  f0d2128:	24063e80 */ 	li	$a2,0x3e80
/*  f0d212c:	24070040 */ 	li	$a3,0x40
/*  f0d2130:	0c004125 */ 	jal	0x10494
/*  f0d2134:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f0d2138:	3c09800a */ 	lui	$t1,0x800a
/*  f0d213c:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d2140:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d2144:	1000002c */ 	b	.PF0f0d21f8
/*  f0d2148:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d214c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d2150:	44814000 */ 	mtc1	$at,$f8
/*  f0d2154:	3419808c */ 	li	$t9,0x808c
/*  f0d2158:	240e0001 */ 	li	$t6,0x1
/*  f0d215c:	2418ffff */ 	li	$t8,-1
/*  f0d2160:	240f0001 */ 	li	$t7,0x1
/*  f0d2164:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0d2168:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0d216c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0d2170:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0d2174:	00002025 */ 	move	$a0,$zero
/*  f0d2178:	00002825 */ 	move	$a1,$zero
/*  f0d217c:	24063e80 */ 	li	$a2,0x3e80
/*  f0d2180:	24070040 */ 	li	$a3,0x40
/*  f0d2184:	0c004125 */ 	jal	0x10494
/*  f0d2188:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0d218c:	3c09800a */ 	lui	$t1,0x800a
/*  f0d2190:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d2194:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d2198:	10000017 */ 	b	.PF0f0d21f8
/*  f0d219c:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d21a0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d21a4:	44813000 */ 	mtc1	$at,$f6
/*  f0d21a8:	3c048009 */ 	lui	$a0,0x8009
/*  f0d21ac:	240effff */ 	li	$t6,-1
/*  f0d21b0:	2418ffff */ 	li	$t8,-1
/*  f0d21b4:	240fffff */ 	li	$t7,-1
/*  f0d21b8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0d21bc:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0d21c0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0d21c4:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f0d21c8:	240500f2 */ 	li	$a1,0xf2
/*  f0d21cc:	00003025 */ 	move	$a2,$zero
/*  f0d21d0:	2407ffff */ 	li	$a3,-1
/*  f0d21d4:	0c0041a0 */ 	jal	0x10680
/*  f0d21d8:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0d21dc:	3c09800a */ 	lui	$t1,0x800a
/*  f0d21e0:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d21e4:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d21e8:	10000003 */ 	b	.PF0f0d21f8
/*  f0d21ec:	8f230480 */ 	lw	$v1,0x480($t9)
.PF0f0d21f0:
/*  f0d21f0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d21f4:	8dc30480 */ 	lw	$v1,0x480($t6)
.PF0f0d21f8:
/*  f0d21f8:	3c0144c8 */ 	lui	$at,0x44c8
.PF0f0d21fc:
/*  f0d21fc:	44816000 */ 	mtc1	$at,$f12
/*  f0d2200:	c4620058 */ 	lwc1	$f2,0x58($v1)
/*  f0d2204:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0d2208:	00000000 */ 	nop
/*  f0d220c:	45020006 */ 	bc1fl	.PF0f0d2228
/*  f0d2210:	460c1003 */ 	div.s	$f0,$f2,$f12
/*  f0d2214:	e46c0058 */ 	swc1	$f12,0x58($v1)
/*  f0d2218:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d221c:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d2220:	c4620058 */ 	lwc1	$f2,0x58($v1)
/*  f0d2224:	460c1003 */ 	div.s	$f0,$f2,$f12
.PF0f0d2228:
/*  f0d2228:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0d222c:	44812000 */ 	mtc1	$at,$f4
/*  f0d2230:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f0d2234:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f0d2238:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0d223c:	44054000 */ 	mfc1	$a1,$f8
/*  f0d2240:	0fc24da0 */ 	jal	0xf093680
/*  f0d2244:	00000000 */ 	nop
/*  f0d2248:	3c09800a */ 	lui	$t1,0x800a
/*  f0d224c:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d2250:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d2254:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d2258:	44817000 */ 	mtc1	$at,$f14
/*  f0d225c:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f0d2260:	3c014334 */ 	lui	$at,0x4334
/*  f0d2264:	44813000 */ 	mtc1	$at,$f6
/*  f0d2268:	c5c4001c */ 	lwc1	$f4,0x1c($t6)
/*  f0d226c:	44805000 */ 	mtc1	$zero,$f10
/*  f0d2270:	46043001 */ 	sub.s	$f0,$f6,$f4
/*  f0d2274:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0d2278:	00000000 */ 	nop
/*  f0d227c:	45020003 */ 	bc1fl	.PF0f0d228c
/*  f0d2280:	460e0203 */ 	div.s	$f8,$f0,$f14
/*  f0d2284:	460e0000 */ 	add.s	$f0,$f0,$f14
/*  f0d2288:	460e0203 */ 	div.s	$f8,$f0,$f14
.PF0f0d228c:
/*  f0d228c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d2290:	c426edcc */ 	lwc1	$f6,-0x1234($at)
/*  f0d2294:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f0d2298:	46064002 */ 	mul.s	$f0,$f8,$f6
/*  f0d229c:	44050000 */ 	mfc1	$a1,$f0
/*  f0d22a0:	0fc0f9af */ 	jal	0xf03e6bc
/*  f0d22a4:	00000000 */ 	nop
/*  f0d22a8:	3c09800a */ 	lui	$t1,0x800a
/*  f0d22ac:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d22b0:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d22b4:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d22b8:	806f0036 */ 	lb	$t7,0x36($v1)
/*  f0d22bc:	29e10029 */ 	slti	$at,$t7,0x29
/*  f0d22c0:	542000aa */ 	bnezl	$at,.PF0f0d256c
/*  f0d22c4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0d22c8:	80790068 */ 	lb	$t9,0x68($v1)
/*  f0d22cc:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0d22d0:	5f200013 */ 	bgtzl	$t9,.PF0f0d2320
/*  f0d22d4:	a0600039 */ 	sb	$zero,0x39($v1)
/*  f0d22d8:	51c00011 */ 	beqzl	$t6,.PF0f0d2320
/*  f0d22dc:	a0600039 */ 	sb	$zero,0x39($v1)
/*  f0d22e0:	80780037 */ 	lb	$t8,0x37($v1)
/*  f0d22e4:	5300000e */ 	beqzl	$t8,.PF0f0d2320
/*  f0d22e8:	a0600039 */ 	sb	$zero,0x39($v1)
/*  f0d22ec:	806f0039 */ 	lb	$t7,0x39($v1)
/*  f0d22f0:	24190001 */ 	li	$t9,0x1
/*  f0d22f4:	55e0000d */ 	bnezl	$t7,.PF0f0d232c
/*  f0d22f8:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0d22fc:	a0790039 */ 	sb	$t9,0x39($v1)
/*  f0d2300:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d2304:	240e0014 */ 	li	$t6,0x14
/*  f0d2308:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f0d230c:	a1ee0068 */ 	sb	$t6,0x68($t7)
/*  f0d2310:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d2314:	10000004 */ 	b	.PF0f0d2328
/*  f0d2318:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d231c:	a0600039 */ 	sb	$zero,0x39($v1)
.PF0f0d2320:
/*  f0d2320:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d2324:	8f030480 */ 	lw	$v1,0x480($t8)
.PF0f0d2328:
/*  f0d2328:	8fae00a4 */ 	lw	$t6,0xa4($sp)
.PF0f0d232c:
/*  f0d232c:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0d2330:	254a11a0 */ 	addiu	$t2,$t2,0x11a0
/*  f0d2334:	51c0000d */ 	beqzl	$t6,.PF0f0d236c
/*  f0d2338:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0d233c:	806f0037 */ 	lb	$t7,0x37($v1)
/*  f0d2340:	51e0000a */ 	beqzl	$t7,.PF0f0d236c
/*  f0d2344:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0d2348:	a0600037 */ 	sb	$zero,0x37($v1)
/*  f0d234c:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d2350:	2401fffb */ 	li	$at,-5
/*  f0d2354:	8db900c4 */ 	lw	$t9,0xc4($t5)
/*  f0d2358:	0321c024 */ 	and	$t8,$t9,$at
/*  f0d235c:	adb800c4 */ 	sw	$t8,0xc4($t5)
/*  f0d2360:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d2364:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d2368:	8faf00a0 */ 	lw	$t7,0xa0($sp)
.PF0f0d236c:
/*  f0d236c:	51e00011 */ 	beqzl	$t7,.PF0f0d23b4
/*  f0d2370:	a060006a */ 	sb	$zero,0x6a($v1)
/*  f0d2374:	80790037 */ 	lb	$t9,0x37($v1)
/*  f0d2378:	5320000e */ 	beqzl	$t9,.PF0f0d23b4
/*  f0d237c:	a060006a */ 	sb	$zero,0x6a($v1)
/*  f0d2380:	80780038 */ 	lb	$t8,0x38($v1)
/*  f0d2384:	240e0001 */ 	li	$t6,0x1
/*  f0d2388:	17000007 */ 	bnez	$t8,.PF0f0d23a8
/*  f0d238c:	00000000 */ 	nop
/*  f0d2390:	a06e0038 */ 	sb	$t6,0x38($v1)
/*  f0d2394:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d2398:	240f0001 */ 	li	$t7,0x1
/*  f0d239c:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f0d23a0:	10000007 */ 	b	.PF0f0d23c0
/*  f0d23a4:	a30f006a */ 	sb	$t7,0x6a($t8)
.PF0f0d23a8:
/*  f0d23a8:	10000005 */ 	b	.PF0f0d23c0
/*  f0d23ac:	a060006a */ 	sb	$zero,0x6a($v1)
/*  f0d23b0:	a060006a */ 	sb	$zero,0x6a($v1)
.PF0f0d23b4:
/*  f0d23b4:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d23b8:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f0d23bc:	a3200038 */ 	sb	$zero,0x38($t9)
.PF0f0d23c0:
/*  f0d23c0:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d23c4:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0d23c8:	91ef11a4 */ 	lbu	$t7,0x11a4($t7)
/*  f0d23cc:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d23d0:	a1cf0069 */ 	sb	$t7,0x69($t6)
/*  f0d23d4:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d23d8:	8da30480 */ 	lw	$v1,0x480($t5)
/*  f0d23dc:	80790037 */ 	lb	$t9,0x37($v1)
/*  f0d23e0:	5720002a */ 	bnezl	$t9,.PF0f0d248c
/*  f0d23e4:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d23e8:	91580000 */ 	lbu	$t8,0x0($t2)
/*  f0d23ec:	24190022 */ 	li	$t9,0x22
/*  f0d23f0:	57000026 */ 	bnezl	$t8,.PF0f0d248c
/*  f0d23f4:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d23f8:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f0d23fc:	8da800bc */ 	lw	$t0,0xbc($t5)
/*  f0d2400:	240f0001 */ 	li	$t7,0x1
/*  f0d2404:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0d2408:	c50a0008 */ 	lwc1	$f10,0x8($t0)
/*  f0d240c:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f0d2410:	c5060010 */ 	lwc1	$f6,0x10($t0)
/*  f0d2414:	460a2001 */ 	sub.s	$f0,$f4,$f10
/*  f0d2418:	a14f0000 */ 	sb	$t7,0x0($t2)
/*  f0d241c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d2420:	46064081 */ 	sub.s	$f2,$f8,$f6
/*  f0d2424:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f0d2428:	c424edd0 */ 	lwc1	$f4,-0x1230($at)
/*  f0d242c:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f0d2430:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0d2434:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0d2438:	00000000 */ 	nop
/*  f0d243c:	45020003 */ 	bc1fl	.PF0f0d244c
/*  f0d2440:	8dae0480 */ 	lw	$t6,0x480($t5)
/*  f0d2444:	a1400000 */ 	sb	$zero,0x0($t2)
/*  f0d2448:	8dae0480 */ 	lw	$t6,0x480($t5)
.PF0f0d244c:
/*  f0d244c:	8da800bc */ 	lw	$t0,0xbc($t5)
/*  f0d2450:	2418001c */ 	li	$t8,0x1c
/*  f0d2454:	8dc20000 */ 	lw	$v0,0x0($t6)
/*  f0d2458:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0d245c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0d2460:	25040008 */ 	addiu	$a0,$t0,0x8
/*  f0d2464:	25050028 */ 	addiu	$a1,$t0,0x28
/*  f0d2468:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f0d246c:	0c00b54f */ 	jal	0x2d53c
/*  f0d2470:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f0d2474:	3c09800a */ 	lui	$t1,0x800a
/*  f0d2478:	14400003 */ 	bnez	$v0,.PF0f0d2488
/*  f0d247c:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d2480:	3c018007 */ 	lui	$at,0x8007
/*  f0d2484:	a02011a0 */ 	sb	$zero,0x11a0($at)
.PF0f0d2488:
/*  f0d2488:	8d2d0284 */ 	lw	$t5,0x284($t1)
.PF0f0d248c:
/*  f0d248c:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0d2490:	254a11a0 */ 	addiu	$t2,$t2,0x11a0
/*  f0d2494:	8daf0480 */ 	lw	$t7,0x480($t5)
/*  f0d2498:	81ee0037 */ 	lb	$t6,0x37($t7)
/*  f0d249c:	51c00003 */ 	beqzl	$t6,.PF0f0d24ac
/*  f0d24a0:	91590000 */ 	lbu	$t9,0x0($t2)
/*  f0d24a4:	a1400000 */ 	sb	$zero,0x0($t2)
/*  f0d24a8:	91590000 */ 	lbu	$t9,0x0($t2)
.PF0f0d24ac:
/*  f0d24ac:	5320002a */ 	beqzl	$t9,.PF0f0d2558
/*  f0d24b0:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f0d24b4:	8db80480 */ 	lw	$t8,0x480($t5)
/*  f0d24b8:	240f0001 */ 	li	$t7,0x1
/*  f0d24bc:	2404002e */ 	li	$a0,0x2e
/*  f0d24c0:	a3000035 */ 	sb	$zero,0x35($t8)
/*  f0d24c4:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d24c8:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f0d24cc:	a32f0034 */ 	sb	$t7,0x34($t9)
/*  f0d24d0:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d24d4:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d24d8:	a1c00037 */ 	sb	$zero,0x37($t6)
/*  f0d24dc:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f0d24e0:	8df90018 */ 	lw	$t9,0x18($t7)
/*  f0d24e4:	37380400 */ 	ori	$t8,$t9,0x400
/*  f0d24e8:	370e0010 */ 	ori	$t6,$t8,0x10
/*  f0d24ec:	adf80018 */ 	sw	$t8,0x18($t7)
/*  f0d24f0:	0fc21fa0 */ 	jal	0xf087e80
/*  f0d24f4:	adee0018 */ 	sw	$t6,0x18($t7)
/*  f0d24f8:	2404002e */ 	li	$a0,0x2e
/*  f0d24fc:	0fc221bd */ 	jal	0xf0886f4
/*  f0d2500:	00002825 */ 	move	$a1,$zero
/*  f0d2504:	3c09800a */ 	lui	$t1,0x800a
/*  f0d2508:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d250c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d2510:	24050001 */ 	li	$a1,0x1
/*  f0d2514:	3406ffff */ 	li	$a2,0xffff
/*  f0d2518:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f0d251c:	0fc2496f */ 	jal	0xf0925bc
/*  f0d2520:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f0d2524:	3c09800a */ 	lui	$t1,0x800a
/*  f0d2528:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f0d252c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d2530:	8d380338 */ 	lw	$t8,0x338($t1)
/*  f0d2534:	24010048 */ 	li	$at,0x48
/*  f0d2538:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d253c:	8df90000 */ 	lw	$t9,0x0($t7)
/*  f0d2540:	03382023 */ 	subu	$a0,$t9,$t8
/*  f0d2544:	0081001a */ 	div	$zero,$a0,$at
/*  f0d2548:	00002012 */ 	mflo	$a0
/*  f0d254c:	0fc0842c */ 	jal	0xf0210b0
/*  f0d2550:	00000000 */ 	nop
/*  f0d2554:	8faf00e4 */ 	lw	$t7,0xe4($sp)
.PF0f0d2558:
/*  f0d2558:	24050001 */ 	li	$a1,0x1
/*  f0d255c:	8de4001c */ 	lw	$a0,0x1c($t7)
/*  f0d2560:	0fc22ac0 */ 	jal	0xf08ab00
/*  f0d2564:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d2568:	8fbf002c */ 	lw	$ra,0x2c($sp)
.PF0f0d256c:
/*  f0d256c:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f0d2570:	03e00008 */ 	jr	$ra
/*  f0d2574:	00000000 */ 	nop
/*  f0d2578:	00000000 */ 	nop
/*  f0d257c:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel eyespyProcessInput
.late_rodata
glabel var7f1adaa0
.word 0x3f75c28f
glabel var7f1adaa4
.word 0x3e99999a
glabel var7f1adaa8
.word 0x3c4ccccd
glabel var7f1adaac
.word 0x3c4ccccd
glabel var7f1adab0
.word 0x3f75c28f
glabel var7f1adab4
.word 0x3c8efa35
glabel var7f1adab8
.word 0x3c8efa35
glabel var7f1adabc
.word 0x3c8efa35
glabel var7f1adac0
.word 0x3c8efa35
glabel var7f1adac4
.word 0x3d23d70a
glabel var7f1adac8
.word 0x3d23d70a
glabel var7f1adacc
.word 0x3c8efa35
glabel var7f1adad0
.word 0x3c8efa35
glabel var7f1adad4
.word 0x3e19999a
glabel var7f1adad8
.word 0x3e19999a
glabel var7f1adadc
.word 0x42b48000
glabel var7f1adae0
.word 0x3dcccccd
glabel var7f1adae4
.word 0x3ccccccd
glabel var7f1adae8
.word eyespyProcessInput+0x1184 # f0d1aac
glabel var7f1adaec
.word eyespyProcessInput+0x1280 # f0d1ba8
glabel var7f1adaf0
.word eyespyProcessInput+0x122c # f0d1b54
glabel var7f1adaf4
.word eyespyProcessInput+0x12d4 # f0d1bfc
glabel var7f1adaf8
.word eyespyProcessInput+0x11d8 # f0d1b00
glabel var7f1adafc
.word 0x40c907a9
glabel var7f1adb00
.word 0x461c4000
.text
/*  f0d0928:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d092c:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d0930:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d0934:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f0d0938:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0d093c:	afa400e8 */ 	sw	$a0,0xe8($sp)
/*  f0d0940:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d0944:	3c017f1b */ 	lui	$at,%hi(var7f1adaa0)
/*  f0d0948:	c424daa0 */ 	lwc1	$f4,%lo(var7f1adaa0)($at)
/*  f0d094c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0d0950:	8d2e0288 */ 	lw	$t6,0x288($t1)
/*  f0d0954:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f0d0958:	e7a400e0 */ 	swc1	$f4,0xe0($sp)
/*  f0d095c:	afb900e4 */ 	sw	$t9,0xe4($sp)
/*  f0d0960:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f0d0964:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0d0968:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0d096c:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0d0970:	a3a200c3 */ 	sb	$v0,0xc3($sp)
/*  f0d0974:	0c005384 */ 	jal	contGetStickX
/*  f0d0978:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0d097c:	83a400c3 */ 	lb	$a0,0xc3($sp)
/*  f0d0980:	0c0053ae */ 	jal	contGetStickY
/*  f0d0984:	a3a200c2 */ 	sb	$v0,0xc2($sp)
/*  f0d0988:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f0d098c:	00023e00 */ 	sll	$a3,$v0,0x18
/*  f0d0990:	0007ce03 */ 	sra	$t9,$a3,0x18
/*  f0d0994:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d0998:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d099c:	03203825 */ 	or	$a3,$t9,$zero
/*  f0d09a0:	11c0000c */ 	beqz	$t6,.L0f0d09d4
/*  f0d09a4:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d09a8:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d09ac:	83a400c3 */ 	lb	$a0,0xc3($sp)
/*  f0d09b0:	3405ffff */ 	dli	$a1,0xffff
/*  f0d09b4:	0c0053d8 */ 	jal	contGetButtons
/*  f0d09b8:	a3b900c0 */ 	sb	$t9,0xc0($sp)
/*  f0d09bc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d09c0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d09c4:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d09c8:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d09cc:	10000002 */ 	b	.L0f0d09d8
/*  f0d09d0:	3048ffff */ 	andi	$t0,$v0,0xffff
.L0f0d09d4:
/*  f0d09d4:	00004025 */ 	or	$t0,$zero,$zero
.L0f0d09d8:
/*  f0d09d8:	8d380288 */ 	lw	$t8,0x288($t1)
/*  f0d09dc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d09e0:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f0d09e4:	8f040070 */ 	lw	$a0,0x70($t8)
/*  f0d09e8:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d09ec:	a7a800bc */ 	sh	$t0,0xbc($sp)
/*  f0d09f0:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0d09f4:	a3a700c0 */ 	sb	$a3,0xc0($sp)
/*  f0d09f8:	44808000 */ 	mtc1	$zero,$f16
/*  f0d09fc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d0a00:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d0a04:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d0a08:	e7b0009c */ 	swc1	$f16,0x9c($sp)
/*  f0d0a0c:	e7b00098 */ 	swc1	$f16,0x98($sp)
/*  f0d0a10:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*  f0d0a14:	8db90480 */ 	lw	$t9,0x480($t5)
/*  f0d0a18:	28410004 */ 	slti	$at,$v0,0x4
/*  f0d0a1c:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d0a20:	c7260028 */ 	lwc1	$f6,0x28($t9)
/*  f0d0a24:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f0d0a28:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d0a2c:	00405825 */ 	or	$t3,$v0,$zero
/*  f0d0a30:	14200035 */ 	bnez	$at,.L0f0d0b08
/*  f0d0a34:	e7a60088 */ 	swc1	$f6,0x88($sp)
/*  f0d0a38:	8d2e0288 */ 	lw	$t6,0x288($t1)
/*  f0d0a3c:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0d0a40:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d0a44:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0d0a48:	a7a800bc */ 	sh	$t0,0xbc($sp)
/*  f0d0a4c:	0fc549d9 */ 	jal	optionsGetContpadNum2
/*  f0d0a50:	a3a700c0 */ 	sb	$a3,0xc0($sp)
/*  f0d0a54:	00021e00 */ 	sll	$v1,$v0,0x18
/*  f0d0a58:	00037e03 */ 	sra	$t7,$v1,0x18
/*  f0d0a5c:	000f2600 */ 	sll	$a0,$t7,0x18
/*  f0d0a60:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0d0a64:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f0d0a68:	0c005384 */ 	jal	contGetStickX
/*  f0d0a6c:	03002025 */ 	or	$a0,$t8,$zero
/*  f0d0a70:	83a40077 */ 	lb	$a0,0x77($sp)
/*  f0d0a74:	a3a200c1 */ 	sb	$v0,0xc1($sp)
/*  f0d0a78:	0c0053ae */ 	jal	contGetStickY
/*  f0d0a7c:	afa4003c */ 	sw	$a0,0x3c($sp)
/*  f0d0a80:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0d0a84:	00023600 */ 	sll	$a2,$v0,0x18
/*  f0d0a88:	00067603 */ 	sra	$t6,$a2,0x18
/*  f0d0a8c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d0a90:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d0a94:	01c03025 */ 	or	$a2,$t6,$zero
/*  f0d0a98:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0d0a9c:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d0aa0:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f0d0aa4:	83aa00c1 */ 	lb	$t2,0xc1($sp)
/*  f0d0aa8:	8fab00b0 */ 	lw	$t3,0xb0($sp)
/*  f0d0aac:	11e00013 */ 	beqz	$t7,.L0f0d0afc
/*  f0d0ab0:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d0ab4:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d0ab8:	3405ffff */ 	dli	$a1,0xffff
/*  f0d0abc:	a3ae00bf */ 	sb	$t6,0xbf($sp)
/*  f0d0ac0:	a3a700c0 */ 	sb	$a3,0xc0($sp)
/*  f0d0ac4:	a7a800bc */ 	sh	$t0,0xbc($sp)
/*  f0d0ac8:	a3aa00c1 */ 	sb	$t2,0xc1($sp)
/*  f0d0acc:	0c0053d8 */ 	jal	contGetButtons
/*  f0d0ad0:	afab00b0 */ 	sw	$t3,0xb0($sp)
/*  f0d0ad4:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d0ad8:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d0adc:	83a600bf */ 	lb	$a2,0xbf($sp)
/*  f0d0ae0:	83a700c0 */ 	lb	$a3,0xc0($sp)
/*  f0d0ae4:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f0d0ae8:	83aa00c1 */ 	lb	$t2,0xc1($sp)
/*  f0d0aec:	8fab00b0 */ 	lw	$t3,0xb0($sp)
/*  f0d0af0:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d0af4:	10000002 */ 	b	.L0f0d0b00
/*  f0d0af8:	3045ffff */ 	andi	$a1,$v0,0xffff
.L0f0d0afc:
/*  f0d0afc:	00002825 */ 	or	$a1,$zero,$zero
.L0f0d0b00:
/*  f0d0b00:	10000008 */ 	b	.L0f0d0b24
/*  f0d0b04:	8d2d0284 */ 	lw	$t5,0x284($t1)
.L0f0d0b08:
/*  f0d0b08:	001f5600 */ 	sll	$t2,$ra,0x18
/*  f0d0b0c:	00073600 */ 	sll	$a2,$a3,0x18
/*  f0d0b10:	000ac603 */ 	sra	$t8,$t2,0x18
/*  f0d0b14:	0006ce03 */ 	sra	$t9,$a2,0x18
/*  f0d0b18:	03005025 */ 	or	$t2,$t8,$zero
/*  f0d0b1c:	03203025 */ 	or	$a2,$t9,$zero
/*  f0d0b20:	3105ffff */ 	andi	$a1,$t0,0xffff
.L0f0d0b24:
/*  f0d0b24:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0d0b28:	11610002 */ 	beq	$t3,$at,.L0f0d0b34
/*  f0d0b2c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0d0b30:	15610009 */ 	bne	$t3,$at,.L0f0d0b58
.L0f0d0b34:
/*  f0d0b34:	310e8000 */ 	andi	$t6,$t0,0x8000
/*  f0d0b38:	310f0010 */ 	andi	$t7,$t0,0x10
/*  f0d0b3c:	31184000 */ 	andi	$t8,$t0,0x4000
/*  f0d0b40:	01002025 */ 	or	$a0,$t0,$zero
/*  f0d0b44:	310c2000 */ 	andi	$t4,$t0,0x2000
/*  f0d0b48:	afae00a8 */ 	sw	$t6,0xa8($sp)
/*  f0d0b4c:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f0d0b50:	1000001e */ 	b	.L0f0d0bcc
/*  f0d0b54:	afb800a0 */ 	sw	$t8,0xa0($sp)
.L0f0d0b58:
/*  f0d0b58:	29610004 */ 	slti	$at,$t3,0x4
/*  f0d0b5c:	10200009 */ 	beqz	$at,.L0f0d0b84
/*  f0d0b60:	01002025 */ 	or	$a0,$t0,$zero
/*  f0d0b64:	31192000 */ 	andi	$t9,$t0,0x2000
/*  f0d0b68:	310e8000 */ 	andi	$t6,$t0,0x8000
/*  f0d0b6c:	310f4000 */ 	andi	$t7,$t0,0x4000
/*  f0d0b70:	310c0030 */ 	andi	$t4,$t0,0x30
/*  f0d0b74:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0d0b78:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f0d0b7c:	10000013 */ 	b	.L0f0d0bcc
/*  f0d0b80:	afaf00a0 */ 	sw	$t7,0xa0($sp)
.L0f0d0b84:
/*  f0d0b84:	29610006 */ 	slti	$at,$t3,0x6
/*  f0d0b88:	14200007 */ 	bnez	$at,.L0f0d0ba8
/*  f0d0b8c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0d0b90:	30b82000 */ 	andi	$t8,$a1,0x2000
/*  f0d0b94:	01002025 */ 	or	$a0,$t0,$zero
/*  f0d0b98:	310c2000 */ 	andi	$t4,$t0,0x2000
/*  f0d0b9c:	afb800a8 */ 	sw	$t8,0xa8($sp)
/*  f0d0ba0:	10000005 */ 	b	.L0f0d0bb8
/*  f0d0ba4:	00a01825 */ 	or	$v1,$a1,$zero
.L0f0d0ba8:
/*  f0d0ba8:	31192000 */ 	andi	$t9,$t0,0x2000
/*  f0d0bac:	30ac2000 */ 	andi	$t4,$a1,0x2000
/*  f0d0bb0:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0d0bb4:	01002025 */ 	or	$a0,$t0,$zero
.L0f0d0bb8:
/*  f0d0bb8:	00831025 */ 	or	$v0,$a0,$v1
/*  f0d0bbc:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0d0bc0:	304f4000 */ 	andi	$t7,$v0,0x4000
/*  f0d0bc4:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f0d0bc8:	afaf00a0 */ 	sw	$t7,0xa0($sp)
.L0f0d0bcc:
/*  f0d0bcc:	2be1fff7 */ 	slti	$at,$ra,-9
/*  f0d0bd0:	14200004 */ 	bnez	$at,.L0f0d0be4
/*  f0d0bd4:	2be1000a */ 	slti	$at,$ra,0xa
/*  f0d0bd8:	50200003 */ 	beqzl	$at,.L0f0d0be8
/*  f0d0bdc:	2be1fff7 */ 	slti	$at,$ra,-9
/*  f0d0be0:	0000f825 */ 	or	$ra,$zero,$zero
.L0f0d0be4:
/*  f0d0be4:	2be1fff7 */ 	slti	$at,$ra,-9
.L0f0d0be8:
/*  f0d0be8:	50200005 */ 	beqzl	$at,.L0f0d0c00
/*  f0d0bec:	2be1000a */ 	slti	$at,$ra,0xa
/*  f0d0bf0:	27ff000a */ 	addiu	$ra,$ra,0xa
/*  f0d0bf4:	001fc600 */ 	sll	$t8,$ra,0x18
/*  f0d0bf8:	0018fe03 */ 	sra	$ra,$t8,0x18
/*  f0d0bfc:	2be1000a */ 	slti	$at,$ra,0xa
.L0f0d0c00:
/*  f0d0c00:	54200005 */ 	bnezl	$at,.L0f0d0c18
/*  f0d0c04:	2941fff7 */ 	slti	$at,$t2,-9
/*  f0d0c08:	27fffff6 */ 	addiu	$ra,$ra,-10
/*  f0d0c0c:	001f7600 */ 	sll	$t6,$ra,0x18
/*  f0d0c10:	000efe03 */ 	sra	$ra,$t6,0x18
/*  f0d0c14:	2941fff7 */ 	slti	$at,$t2,-9
.L0f0d0c18:
/*  f0d0c18:	14200004 */ 	bnez	$at,.L0f0d0c2c
/*  f0d0c1c:	2941000a */ 	slti	$at,$t2,0xa
/*  f0d0c20:	50200003 */ 	beqzl	$at,.L0f0d0c30
/*  f0d0c24:	2941fff7 */ 	slti	$at,$t2,-9
/*  f0d0c28:	00005025 */ 	or	$t2,$zero,$zero
.L0f0d0c2c:
/*  f0d0c2c:	2941fff7 */ 	slti	$at,$t2,-9
.L0f0d0c30:
/*  f0d0c30:	50200005 */ 	beqzl	$at,.L0f0d0c48
/*  f0d0c34:	2941000a */ 	slti	$at,$t2,0xa
/*  f0d0c38:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f0d0c3c:	000ac600 */ 	sll	$t8,$t2,0x18
/*  f0d0c40:	00185603 */ 	sra	$t2,$t8,0x18
/*  f0d0c44:	2941000a */ 	slti	$at,$t2,0xa
.L0f0d0c48:
/*  f0d0c48:	54200005 */ 	bnezl	$at,.L0f0d0c60
/*  f0d0c4c:	28e1ffed */ 	slti	$at,$a3,-19
/*  f0d0c50:	254afff6 */ 	addiu	$t2,$t2,-10
/*  f0d0c54:	000a7600 */ 	sll	$t6,$t2,0x18
/*  f0d0c58:	000e5603 */ 	sra	$t2,$t6,0x18
/*  f0d0c5c:	28e1ffed */ 	slti	$at,$a3,-19
.L0f0d0c60:
/*  f0d0c60:	14200004 */ 	bnez	$at,.L0f0d0c74
/*  f0d0c64:	28e10014 */ 	slti	$at,$a3,0x14
/*  f0d0c68:	50200003 */ 	beqzl	$at,.L0f0d0c78
/*  f0d0c6c:	28e1ffed */ 	slti	$at,$a3,-19
/*  f0d0c70:	00003825 */ 	or	$a3,$zero,$zero
.L0f0d0c74:
/*  f0d0c74:	28e1ffed */ 	slti	$at,$a3,-19
.L0f0d0c78:
/*  f0d0c78:	50200005 */ 	beqzl	$at,.L0f0d0c90
/*  f0d0c7c:	28e10014 */ 	slti	$at,$a3,0x14
/*  f0d0c80:	24e70014 */ 	addiu	$a3,$a3,0x14
/*  f0d0c84:	0007c600 */ 	sll	$t8,$a3,0x18
/*  f0d0c88:	00183e03 */ 	sra	$a3,$t8,0x18
/*  f0d0c8c:	28e10014 */ 	slti	$at,$a3,0x14
.L0f0d0c90:
/*  f0d0c90:	54200005 */ 	bnezl	$at,.L0f0d0ca8
/*  f0d0c94:	44874000 */ 	mtc1	$a3,$f8
/*  f0d0c98:	24e7ffec */ 	addiu	$a3,$a3,-20
/*  f0d0c9c:	00077600 */ 	sll	$t6,$a3,0x18
/*  f0d0ca0:	000e3e03 */ 	sra	$a3,$t6,0x18
/*  f0d0ca4:	44874000 */ 	mtc1	$a3,$f8
.L0f0d0ca8:
/*  f0d0ca8:	28c1ffed */ 	slti	$at,$a2,-19
/*  f0d0cac:	14200005 */ 	bnez	$at,.L0f0d0cc4
/*  f0d0cb0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d0cb4:	28c10014 */ 	slti	$at,$a2,0x14
/*  f0d0cb8:	50200003 */ 	beqzl	$at,.L0f0d0cc8
/*  f0d0cbc:	28c1ffed */ 	slti	$at,$a2,-19
/*  f0d0cc0:	00003025 */ 	or	$a2,$zero,$zero
.L0f0d0cc4:
/*  f0d0cc4:	28c1ffed */ 	slti	$at,$a2,-19
.L0f0d0cc8:
/*  f0d0cc8:	50200005 */ 	beqzl	$at,.L0f0d0ce0
/*  f0d0ccc:	28c10014 */ 	slti	$at,$a2,0x14
/*  f0d0cd0:	24c60014 */ 	addiu	$a2,$a2,0x14
/*  f0d0cd4:	0006c600 */ 	sll	$t8,$a2,0x18
/*  f0d0cd8:	00183603 */ 	sra	$a2,$t8,0x18
/*  f0d0cdc:	28c10014 */ 	slti	$at,$a2,0x14
.L0f0d0ce0:
/*  f0d0ce0:	14200004 */ 	bnez	$at,.L0f0d0cf4
/*  f0d0ce4:	00000000 */ 	nop
/*  f0d0ce8:	24c6ffec */ 	addiu	$a2,$a2,-20
/*  f0d0cec:	00067600 */ 	sll	$t6,$a2,0x18
/*  f0d0cf0:	000e3603 */ 	sra	$a2,$t6,0x18
.L0f0d0cf4:
/*  f0d0cf4:	3c017f1b */ 	lui	$at,%hi(var7f1adaa4)
/*  f0d0cf8:	c420daa4 */ 	lwc1	$f0,%lo(var7f1adaa4)($at)
/*  f0d0cfc:	44864000 */ 	mtc1	$a2,$f8
/*  f0d0d00:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0d0d04:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d0d08:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d0d0c:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0d0d10:	44073000 */ 	mfc1	$a3,$f6
/*  f0d0d14:	00000000 */ 	nop
/*  f0d0d18:	0007ce00 */ 	sll	$t9,$a3,0x18
/*  f0d0d1c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d0d20:	00193e03 */ 	sra	$a3,$t9,0x18
/*  f0d0d24:	44063000 */ 	mfc1	$a2,$f6
/*  f0d0d28:	00000000 */ 	nop
/*  f0d0d2c:	0006c600 */ 	sll	$t8,$a2,0x18
/*  f0d0d30:	11600004 */ 	beqz	$t3,.L0f0d0d44
/*  f0d0d34:	00183603 */ 	sra	$a2,$t8,0x18
/*  f0d0d38:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0d0d3c:	5561002b */ 	bnel	$t3,$at,.L0f0d0dec
/*  f0d0d40:	29610004 */ 	slti	$at,$t3,0x4
.L0f0d0d44:
/*  f0d0d44:	11800006 */ 	beqz	$t4,.L0f0d0d60
/*  f0d0d48:	308e0808 */ 	andi	$t6,$a0,0x808
/*  f0d0d4c:	44874000 */ 	mtc1	$a3,$f8
/*  f0d0d50:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f0d0d54:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d0d58:	10000005 */ 	b	.L0f0d0d70
/*  f0d0d5c:	e7aa0098 */ 	swc1	$f10,0x98($sp)
.L0f0d0d60:
/*  f0d0d60:	44872000 */ 	mtc1	$a3,$f4
/*  f0d0d64:	00000000 */ 	nop
/*  f0d0d68:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d0d6c:	e7a6009c */ 	swc1	$f6,0x9c($sp)
.L0f0d0d70:
/*  f0d0d70:	11c00003 */ 	beqz	$t6,.L0f0d0d80
/*  f0d0d74:	308f0404 */ 	andi	$t7,$a0,0x404
/*  f0d0d78:	10000002 */ 	b	.L0f0d0d84
/*  f0d0d7c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0d0d80:
/*  f0d0d80:	00001825 */ 	or	$v1,$zero,$zero
.L0f0d0d84:
/*  f0d0d84:	11e00003 */ 	beqz	$t7,.L0f0d0d94
/*  f0d0d88:	308e0202 */ 	andi	$t6,$a0,0x202
/*  f0d0d8c:	10000002 */ 	b	.L0f0d0d98
/*  f0d0d90:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0d0d94:
/*  f0d0d94:	00001025 */ 	or	$v0,$zero,$zero
.L0f0d0d98:
/*  f0d0d98:	0062c023 */ 	subu	$t8,$v1,$v0
/*  f0d0d9c:	44984000 */ 	mtc1	$t8,$f8
/*  f0d0da0:	30990101 */ 	andi	$t9,$a0,0x101
/*  f0d0da4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d0da8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d0dac:	00001825 */ 	or	$v1,$zero,$zero
/*  f0d0db0:	13200003 */ 	beqz	$t9,.L0f0d0dc0
/*  f0d0db4:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f0d0db8:	10000001 */ 	b	.L0f0d0dc0
/*  f0d0dbc:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0d0dc0:
/*  f0d0dc0:	11c00003 */ 	beqz	$t6,.L0f0d0dd0
/*  f0d0dc4:	00000000 */ 	nop
/*  f0d0dc8:	10000001 */ 	b	.L0f0d0dd0
/*  f0d0dcc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0d0dd0:
/*  f0d0dd0:	00627823 */ 	subu	$t7,$v1,$v0
/*  f0d0dd4:	448f2000 */ 	mtc1	$t7,$f4
/*  f0d0dd8:	00000000 */ 	nop
/*  f0d0ddc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d0de0:	10000063 */ 	b	.L0f0d0f70
/*  f0d0de4:	e7a60094 */ 	swc1	$f6,0x94($sp)
/*  f0d0de8:	29610004 */ 	slti	$at,$t3,0x4
.L0f0d0dec:
/*  f0d0dec:	1020002e */ 	beqz	$at,.L0f0d0ea8
/*  f0d0df0:	308e0101 */ 	andi	$t6,$a0,0x101
/*  f0d0df4:	11800006 */ 	beqz	$t4,.L0f0d0e10
/*  f0d0df8:	308f0202 */ 	andi	$t7,$a0,0x202
/*  f0d0dfc:	44874000 */ 	mtc1	$a3,$f8
/*  f0d0e00:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f0d0e04:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d0e08:	10000019 */ 	b	.L0f0d0e70
/*  f0d0e0c:	e7aa0098 */ 	swc1	$f10,0x98($sp)
.L0f0d0e10:
/*  f0d0e10:	44872000 */ 	mtc1	$a3,$f4
/*  f0d0e14:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d0e18:	44814000 */ 	mtc1	$at,$f8
/*  f0d0e1c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d0e20:	30980808 */ 	andi	$t8,$a0,0x808
/*  f0d0e24:	3c0141c0 */ 	lui	$at,0x41c0
/*  f0d0e28:	30990404 */ 	andi	$t9,$a0,0x404
/*  f0d0e2c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0d0e30:	13000004 */ 	beqz	$t8,.L0f0d0e44
/*  f0d0e34:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f0d0e38:	44810000 */ 	mtc1	$at,$f0
/*  f0d0e3c:	10000003 */ 	b	.L0f0d0e4c
/*  f0d0e40:	00000000 */ 	nop
.L0f0d0e44:
/*  f0d0e44:	44800000 */ 	mtc1	$zero,$f0
/*  f0d0e48:	00000000 */ 	nop
.L0f0d0e4c:
/*  f0d0e4c:	13200004 */ 	beqz	$t9,.L0f0d0e60
/*  f0d0e50:	3c0141c0 */ 	lui	$at,0x41c0
/*  f0d0e54:	44811000 */ 	mtc1	$at,$f2
/*  f0d0e58:	10000004 */ 	b	.L0f0d0e6c
/*  f0d0e5c:	46020101 */ 	sub.s	$f4,$f0,$f2
.L0f0d0e60:
/*  f0d0e60:	44801000 */ 	mtc1	$zero,$f2
/*  f0d0e64:	00000000 */ 	nop
/*  f0d0e68:	46020101 */ 	sub.s	$f4,$f0,$f2
.L0f0d0e6c:
/*  f0d0e6c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
.L0f0d0e70:
/*  f0d0e70:	11c00003 */ 	beqz	$t6,.L0f0d0e80
/*  f0d0e74:	00001825 */ 	or	$v1,$zero,$zero
/*  f0d0e78:	10000001 */ 	b	.L0f0d0e80
/*  f0d0e7c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0d0e80:
/*  f0d0e80:	11e00003 */ 	beqz	$t7,.L0f0d0e90
/*  f0d0e84:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d0e88:	10000001 */ 	b	.L0f0d0e90
/*  f0d0e8c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0d0e90:
/*  f0d0e90:	0062c023 */ 	subu	$t8,$v1,$v0
/*  f0d0e94:	44983000 */ 	mtc1	$t8,$f6
/*  f0d0e98:	00000000 */ 	nop
/*  f0d0e9c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d0ea0:	10000033 */ 	b	.L0f0d0f70
/*  f0d0ea4:	e7a80094 */ 	swc1	$f8,0x94($sp)
.L0f0d0ea8:
/*  f0d0ea8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0d0eac:	11610003 */ 	beq	$t3,$at,.L0f0d0ebc
/*  f0d0eb0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0d0eb4:	15610018 */ 	bne	$t3,$at,.L0f0d0f18
/*  f0d0eb8:	00000000 */ 	nop
.L0f0d0ebc:
/*  f0d0ebc:	44875000 */ 	mtc1	$a3,$f10
/*  f0d0ec0:	00000000 */ 	nop
/*  f0d0ec4:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d0ec8:	11800006 */ 	beqz	$t4,.L0f0d0ee4
/*  f0d0ecc:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f0d0ed0:	44863000 */ 	mtc1	$a2,$f6
/*  f0d0ed4:	00000000 */ 	nop
/*  f0d0ed8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d0edc:	10000007 */ 	b	.L0f0d0efc
/*  f0d0ee0:	e7a80098 */ 	swc1	$f8,0x98($sp)
.L0f0d0ee4:
/*  f0d0ee4:	44865000 */ 	mtc1	$a2,$f10
/*  f0d0ee8:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d0eec:	44813000 */ 	mtc1	$at,$f6
/*  f0d0ef0:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d0ef4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d0ef8:	e7a8008c */ 	swc1	$f8,0x8c($sp)
.L0f0d0efc:
/*  f0d0efc:	448a5000 */ 	mtc1	$t2,$f10
/*  f0d0f00:	3c017f1b */ 	lui	$at,%hi(var7f1adaa8)
/*  f0d0f04:	c426daa8 */ 	lwc1	$f6,%lo(var7f1adaa8)($at)
/*  f0d0f08:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d0f0c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d0f10:	10000017 */ 	b	.L0f0d0f70
/*  f0d0f14:	e7a80094 */ 	swc1	$f8,0x94($sp)
.L0f0d0f18:
/*  f0d0f18:	51800007 */ 	beqzl	$t4,.L0f0d0f38
/*  f0d0f1c:	44873000 */ 	mtc1	$a3,$f6
/*  f0d0f20:	44875000 */ 	mtc1	$a3,$f10
/*  f0d0f24:	00000000 */ 	nop
/*  f0d0f28:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d0f2c:	10000007 */ 	b	.L0f0d0f4c
/*  f0d0f30:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f0d0f34:	44873000 */ 	mtc1	$a3,$f6
.L0f0d0f38:
/*  f0d0f38:	3c013e80 */ 	lui	$at,0x3e80
/*  f0d0f3c:	44815000 */ 	mtc1	$at,$f10
/*  f0d0f40:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d0f44:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0d0f48:	e7a4008c */ 	swc1	$f4,0x8c($sp)
.L0f0d0f4c:
/*  f0d0f4c:	44863000 */ 	mtc1	$a2,$f6
/*  f0d0f50:	448a5000 */ 	mtc1	$t2,$f10
/*  f0d0f54:	3c017f1b */ 	lui	$at,%hi(var7f1adaac)
/*  f0d0f58:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d0f5c:	c426daac */ 	lwc1	$f6,%lo(var7f1adaac)($at)
/*  f0d0f60:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d0f64:	e7a8009c */ 	swc1	$f8,0x9c($sp)
/*  f0d0f68:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0d0f6c:	e7a80094 */ 	swc1	$f8,0x94($sp)
.L0f0d0f70:
/*  f0d0f70:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d0f74:	44816000 */ 	mtc1	$at,$f12
/*  f0d0f78:	3c018007 */ 	lui	$at,%hi(var80070ec0)
/*  f0d0f7c:	a0200ec0 */ 	sb	$zero,%lo(var80070ec0)($at)
/*  f0d0f80:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d0f84:	46006006 */ 	mov.s	$f0,$f12
/*  f0d0f88:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0d0f8c:	00000000 */ 	nop
/*  f0d0f90:	4500000a */ 	bc1f	.L0f0d0fbc
/*  f0d0f94:	3c017f1b */ 	lui	$at,%hi(var7f1adab0)
/*  f0d0f98:	c432dab0 */ 	lwc1	$f18,%lo(var7f1adab0)($at)
/*  f0d0f9c:	c7ae00e0 */ 	lwc1	$f14,0xe0($sp)
/*  f0d0fa0:	460c0000 */ 	add.s	$f0,$f0,$f12
.L0f0d0fa4:
/*  f0d0fa4:	46127382 */ 	mul.s	$f14,$f14,$f18
/*  f0d0fa8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0d0fac:	00000000 */ 	nop
/*  f0d0fb0:	4503fffc */ 	bc1tl	.L0f0d0fa4
/*  f0d0fb4:	460c0000 */ 	add.s	$f0,$f0,$f12
/*  f0d0fb8:	e7ae00e0 */ 	swc1	$f14,0xe0($sp)
.L0f0d0fbc:
/*  f0d0fbc:	8da30480 */ 	lw	$v1,0x480($t5)
/*  f0d0fc0:	c7ae00e0 */ 	lwc1	$f14,0xe0($sp)
/*  f0d0fc4:	80620036 */ 	lb	$v0,0x36($v1)
/*  f0d0fc8:	28410032 */ 	slti	$at,$v0,0x32
/*  f0d0fcc:	50200006 */ 	beqzl	$at,.L0f0d0fe8
/*  f0d0fd0:	240f0032 */ 	addiu	$t7,$zero,0x32
/*  f0d0fd4:	8d390038 */ 	lw	$t9,0x38($t1)
/*  f0d0fd8:	00597021 */ 	addu	$t6,$v0,$t9
/*  f0d0fdc:	10000003 */ 	b	.L0f0d0fec
/*  f0d0fe0:	a06e0036 */ 	sb	$t6,0x36($v1)
/*  f0d0fe4:	240f0032 */ 	addiu	$t7,$zero,0x32
.L0f0d0fe8:
/*  f0d0fe8:	a06f0036 */ 	sb	$t7,0x36($v1)
.L0f0d0fec:
/*  f0d0fec:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d0ff0:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f0d0ff4:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0d0ff8:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f0d0ffc:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f0d1000:	c5ca0008 */ 	lwc1	$f10,0x8($t6)
/*  f0d1004:	e44a00c8 */ 	swc1	$f10,0xc8($v0)
/*  f0d1008:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d100c:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d1010:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f0d1014:	c724000c */ 	lwc1	$f4,0xc($t9)
/*  f0d1018:	e44400cc */ 	swc1	$f4,0xcc($v0)
/*  f0d101c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1020:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d1024:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0d1028:	c7060010 */ 	lwc1	$f6,0x10($t8)
/*  f0d102c:	e44600d0 */ 	swc1	$f6,0xd0($v0)
/*  f0d1030:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1034:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f0d1038:	8dc40000 */ 	lw	$a0,0x0($t6)
/*  f0d103c:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d1040:	e7ae00e0 */ 	swc1	$f14,0xe0($sp)
/*  f0d1044:	0fc195e9 */ 	jal	roomsCopy
/*  f0d1048:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f0d104c:	0fc44727 */ 	jal	invHasSingleWeaponIncAllGuns
/*  f0d1050:	2404002e */ 	addiu	$a0,$zero,0x2e
/*  f0d1054:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1058:	44808000 */ 	mtc1	$zero,$f16
/*  f0d105c:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1060:	1440001e */ 	bnez	$v0,.L0f0d10dc
/*  f0d1064:	83bf00c2 */ 	lb	$ra,0xc2($sp)
/*  f0d1068:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d106c:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f0d1070:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0d1074:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d1078:	24010048 */ 	addiu	$at,$zero,0x48
/*  f0d107c:	a3000035 */ 	sb	$zero,0x35($t8)
/*  f0d1080:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1084:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d1088:	a1f90034 */ 	sb	$t9,0x34($t7)
/*  f0d108c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1090:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1094:	a1c00037 */ 	sb	$zero,0x37($t6)
/*  f0d1098:	8c590018 */ 	lw	$t9,0x18($v0)
/*  f0d109c:	372f0400 */ 	ori	$t7,$t9,0x400
/*  f0d10a0:	ac4f0018 */ 	sw	$t7,0x18($v0)
/*  f0d10a4:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d10a8:	8d2f0338 */ 	lw	$t7,0x338($t1)
/*  f0d10ac:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d10b0:	8dd90000 */ 	lw	$t9,0x0($t6)
/*  f0d10b4:	a3bf00c2 */ 	sb	$ra,0xc2($sp)
/*  f0d10b8:	032f2023 */ 	subu	$a0,$t9,$t7
/*  f0d10bc:	0081001a */ 	div	$zero,$a0,$at
/*  f0d10c0:	00002012 */ 	mflo	$a0
/*  f0d10c4:	0fc083e4 */ 	jal	propClearReferences
/*  f0d10c8:	00000000 */ 	nop
/*  f0d10cc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d10d0:	44808000 */ 	mtc1	$zero,$f16
/*  f0d10d4:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d10d8:	83bf00c2 */ 	lb	$ra,0xc2($sp)
.L0f0d10dc:
/*  f0d10dc:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d10e0:	8da30480 */ 	lw	$v1,0x480($t5)
/*  f0d10e4:	806e0037 */ 	lb	$t6,0x37($v1)
/*  f0d10e8:	51c001c8 */ 	beqzl	$t6,.L0f0d180c
/*  f0d10ec:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d10f0:	8d39028c */ 	lw	$t9,0x28c($t1)
/*  f0d10f4:	3c188007 */ 	lui	$t8,%hi(g_PlayersWithControl)
/*  f0d10f8:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0d10fc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0d1100:	8f180750 */ 	lw	$t8,%lo(g_PlayersWithControl)($t8)
/*  f0d1104:	530001c1 */ 	beqzl	$t8,.L0f0d180c
/*  f0d1108:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d110c:	449f4000 */ 	mtc1	$ra,$f8
/*  f0d1110:	3c013d80 */ 	lui	$at,0x3d80
/*  f0d1114:	44812000 */ 	mtc1	$at,$f4
/*  f0d1118:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d111c:	240effff */ 	addiu	$t6,$zero,-1
/*  f0d1120:	adae1c40 */ 	sw	$t6,0x1c40($t5)
/*  f0d1124:	c528004c */ 	lwc1	$f8,0x4c($t1)
/*  f0d1128:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d112c:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0d1130:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1134:	c464001c */ 	lwc1	$f4,0x1c($v1)
/*  f0d1138:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0d113c:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0d1140:	e466001c */ 	swc1	$f6,0x1c($v1)
/*  f0d1144:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1148:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d114c:	c460001c */ 	lwc1	$f0,0x1c($v1)
/*  f0d1150:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0d1154:	00000000 */ 	nop
/*  f0d1158:	4500000c */ 	bc1f	.L0f0d118c
/*  f0d115c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d1160:	44817000 */ 	mtc1	$at,$f14
/*  f0d1164:	00000000 */ 	nop
/*  f0d1168:	460e0200 */ 	add.s	$f8,$f0,$f14
.L0f0d116c:
/*  f0d116c:	e468001c */ 	swc1	$f8,0x1c($v1)
/*  f0d1170:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1174:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1178:	c460001c */ 	lwc1	$f0,0x1c($v1)
/*  f0d117c:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0d1180:	00000000 */ 	nop
/*  f0d1184:	4503fff9 */ 	bc1tl	.L0f0d116c
/*  f0d1188:	460e0200 */ 	add.s	$f8,$f0,$f14
.L0f0d118c:
/*  f0d118c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d1190:	44817000 */ 	mtc1	$at,$f14
/*  f0d1194:	3c017f1b */ 	lui	$at,%hi(var7f1adab4)
/*  f0d1198:	4600703e */ 	c.le.s	$f14,$f0
/*  f0d119c:	00000000 */ 	nop
/*  f0d11a0:	4500000a */ 	bc1f	.L0f0d11cc
/*  f0d11a4:	00000000 */ 	nop
/*  f0d11a8:	460e0101 */ 	sub.s	$f4,$f0,$f14
.L0f0d11ac:
/*  f0d11ac:	e464001c */ 	swc1	$f4,0x1c($v1)
/*  f0d11b0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d11b4:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d11b8:	c460001c */ 	lwc1	$f0,0x1c($v1)
/*  f0d11bc:	4600703e */ 	c.le.s	$f14,$f0
/*  f0d11c0:	00000000 */ 	nop
/*  f0d11c4:	4503fff9 */ 	bc1tl	.L0f0d11ac
/*  f0d11c8:	460e0101 */ 	sub.s	$f4,$f0,$f14
.L0f0d11cc:
/*  f0d11cc:	c42adab4 */ 	lwc1	$f10,%lo(var7f1adab4)($at)
/*  f0d11d0:	460a0302 */ 	mul.s	$f12,$f0,$f10
/*  f0d11d4:	0c0068f4 */ 	jal	cosf
/*  f0d11d8:	00000000 */ 	nop
/*  f0d11dc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d11e0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d11e4:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d11e8:	3c017f1b */ 	lui	$at,%hi(var7f1adab8)
/*  f0d11ec:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d11f0:	e5e00020 */ 	swc1	$f0,0x20($t7)
/*  f0d11f4:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d11f8:	c428dab8 */ 	lwc1	$f8,%lo(var7f1adab8)($at)
/*  f0d11fc:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1200:	c5c6001c */ 	lwc1	$f6,0x1c($t6)
/*  f0d1204:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f0d1208:	0c0068f7 */ 	jal	sinf
/*  f0d120c:	00000000 */ 	nop
/*  f0d1210:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1214:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1218:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d121c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d1220:	44817000 */ 	mtc1	$at,$f14
/*  f0d1224:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d1228:	3c013d80 */ 	lui	$at,0x3d80
/*  f0d122c:	44815000 */ 	mtc1	$at,$f10
/*  f0d1230:	e5e00024 */ 	swc1	$f0,0x24($t7)
/*  f0d1234:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f0d1238:	c528004c */ 	lwc1	$f8,0x4c($t1)
/*  f0d123c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1240:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0d1244:	44808000 */ 	mtc1	$zero,$f16
/*  f0d1248:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d124c:	3c017f1b */ 	lui	$at,%hi(var7f1adabc)
/*  f0d1250:	c46a0028 */ 	lwc1	$f10,0x28($v1)
/*  f0d1254:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0d1258:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0d125c:	e4660028 */ 	swc1	$f6,0x28($v1)
/*  f0d1260:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1264:	c7a80088 */ 	lwc1	$f8,0x88($sp)
/*  f0d1268:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d126c:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d1270:	46024032 */ 	c.eq.s	$f8,$f2
/*  f0d1274:	00000000 */ 	nop
/*  f0d1278:	45030037 */ 	bc1tl	.L0f0d1358
/*  f0d127c:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f0d1280:	4610103c */ 	c.lt.s	$f2,$f16
/*  f0d1284:	00000000 */ 	nop
/*  f0d1288:	4502000b */ 	bc1fl	.L0f0d12b8
/*  f0d128c:	4602703e */ 	c.le.s	$f14,$f2
/*  f0d1290:	460e1280 */ 	add.s	$f10,$f2,$f14
.L0f0d1294:
/*  f0d1294:	e46a0028 */ 	swc1	$f10,0x28($v1)
/*  f0d1298:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d129c:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d12a0:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d12a4:	4610103c */ 	c.lt.s	$f2,$f16
/*  f0d12a8:	00000000 */ 	nop
/*  f0d12ac:	4503fff9 */ 	bc1tl	.L0f0d1294
/*  f0d12b0:	460e1280 */ 	add.s	$f10,$f2,$f14
/*  f0d12b4:	4602703e */ 	c.le.s	$f14,$f2
.L0f0d12b8:
/*  f0d12b8:	00000000 */ 	nop
/*  f0d12bc:	4500000a */ 	bc1f	.L0f0d12e8
/*  f0d12c0:	00000000 */ 	nop
/*  f0d12c4:	460e1101 */ 	sub.s	$f4,$f2,$f14
.L0f0d12c8:
/*  f0d12c8:	e4640028 */ 	swc1	$f4,0x28($v1)
/*  f0d12cc:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d12d0:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d12d4:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d12d8:	4602703e */ 	c.le.s	$f14,$f2
/*  f0d12dc:	00000000 */ 	nop
/*  f0d12e0:	4503fff9 */ 	bc1tl	.L0f0d12c8
/*  f0d12e4:	460e1101 */ 	sub.s	$f4,$f2,$f14
.L0f0d12e8:
/*  f0d12e8:	c426dabc */ 	lwc1	$f6,%lo(var7f1adabc)($at)
/*  f0d12ec:	46061302 */ 	mul.s	$f12,$f2,$f6
/*  f0d12f0:	0c0068f4 */ 	jal	cosf
/*  f0d12f4:	00000000 */ 	nop
/*  f0d12f8:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d12fc:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1300:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1304:	3c017f1b */ 	lui	$at,%hi(var7f1adac0)
/*  f0d1308:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d130c:	e5c0002c */ 	swc1	$f0,0x2c($t6)
/*  f0d1310:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1314:	c42adac0 */ 	lwc1	$f10,%lo(var7f1adac0)($at)
/*  f0d1318:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d131c:	c5e80028 */ 	lwc1	$f8,0x28($t7)
/*  f0d1320:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f0d1324:	0c0068f7 */ 	jal	sinf
/*  f0d1328:	00000000 */ 	nop
/*  f0d132c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1330:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1334:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1338:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d133c:	44817000 */ 	mtc1	$at,$f14
/*  f0d1340:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1344:	44808000 */ 	mtc1	$zero,$f16
/*  f0d1348:	e5c00030 */ 	swc1	$f0,0x30($t6)
/*  f0d134c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1350:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1354:	8faf00b4 */ 	lw	$t7,0xb4($sp)
.L0f0d1358:
/*  f0d1358:	e7b000c4 */ 	swc1	$f16,0xc4($sp)
/*  f0d135c:	46008486 */ 	mov.s	$f18,$f16
/*  f0d1360:	e7b000cc */ 	swc1	$f16,0xcc($sp)
/*  f0d1364:	e7b000d0 */ 	swc1	$f16,0xd0($sp)
/*  f0d1368:	11e00069 */ 	beqz	$t7,.L0f0d1510
/*  f0d136c:	e7b000d4 */ 	swc1	$f16,0xd4($sp)
/*  f0d1370:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f0d1374:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f0d1378:	4602803c */ 	c.lt.s	$f16,$f2
/*  f0d137c:	00000000 */ 	nop
/*  f0d1380:	45020051 */ 	bc1fl	.L0f0d14c8
/*  f0d1384:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0d1388:	44803000 */ 	mtc1	$zero,$f6
/*  f0d138c:	3c014334 */ 	lui	$at,0x4334
/*  f0d1390:	46062032 */ 	c.eq.s	$f4,$f6
/*  f0d1394:	00000000 */ 	nop
/*  f0d1398:	4503004b */ 	bc1tl	.L0f0d14c8
/*  f0d139c:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0d13a0:	44814000 */ 	mtc1	$at,$f8
/*  f0d13a4:	00000000 */ 	nop
/*  f0d13a8:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0d13ac:	00000000 */ 	nop
/*  f0d13b0:	45020017 */ 	bc1fl	.L0f0d1410
/*  f0d13b4:	8d2e0038 */ 	lw	$t6,0x38($t1)
/*  f0d13b8:	8d380038 */ 	lw	$t8,0x38($t1)
/*  f0d13bc:	46001006 */ 	mov.s	$f0,$f2
/*  f0d13c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d13c4:	1b000025 */ 	blez	$t8,.L0f0d145c
/*  f0d13c8:	3c017f1b */ 	lui	$at,%hi(var7f1adac4)
/*  f0d13cc:	c422dac4 */ 	lwc1	$f2,%lo(var7f1adac4)($at)
/*  f0d13d0:	8d2e0284 */ 	lw	$t6,0x284($t1)
.L0f0d13d4:
/*  f0d13d4:	46020002 */ 	mul.s	$f0,$f0,$f2
/*  f0d13d8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d13dc:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d13e0:	c46a0028 */ 	lwc1	$f10,0x28($v1)
/*  f0d13e4:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0d13e8:	e4640028 */ 	swc1	$f4,0x28($v1)
/*  f0d13ec:	8d390038 */ 	lw	$t9,0x38($t1)
/*  f0d13f0:	0059082a */ 	slt	$at,$v0,$t9
/*  f0d13f4:	5420fff7 */ 	bnezl	$at,.L0f0d13d4
/*  f0d13f8:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d13fc:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1400:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d1404:	10000015 */ 	b	.L0f0d145c
/*  f0d1408:	c7020028 */ 	lwc1	$f2,0x28($t8)
/*  f0d140c:	8d2e0038 */ 	lw	$t6,0x38($t1)
.L0f0d1410:
/*  f0d1410:	46027001 */ 	sub.s	$f0,$f14,$f2
/*  f0d1414:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d1418:	19c00010 */ 	blez	$t6,.L0f0d145c
/*  f0d141c:	3c017f1b */ 	lui	$at,%hi(var7f1adac8)
/*  f0d1420:	c422dac8 */ 	lwc1	$f2,%lo(var7f1adac8)($at)
/*  f0d1424:	8d390284 */ 	lw	$t9,0x284($t1)
.L0f0d1428:
/*  f0d1428:	46020002 */ 	mul.s	$f0,$f0,$f2
/*  f0d142c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d1430:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1434:	c4660028 */ 	lwc1	$f6,0x28($v1)
/*  f0d1438:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0d143c:	e4680028 */ 	swc1	$f8,0x28($v1)
/*  f0d1440:	8d2f0038 */ 	lw	$t7,0x38($t1)
/*  f0d1444:	004f082a */ 	slt	$at,$v0,$t7
/*  f0d1448:	5420fff7 */ 	bnezl	$at,.L0f0d1428
/*  f0d144c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1450:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1454:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1458:	c5c20028 */ 	lwc1	$f2,0x28($t6)
.L0f0d145c:
/*  f0d145c:	3c017f1b */ 	lui	$at,%hi(var7f1adacc)
/*  f0d1460:	c42adacc */ 	lwc1	$f10,%lo(var7f1adacc)($at)
/*  f0d1464:	460a1302 */ 	mul.s	$f12,$f2,$f10
/*  f0d1468:	0c0068f4 */ 	jal	cosf
/*  f0d146c:	00000000 */ 	nop
/*  f0d1470:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1474:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1478:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d147c:	3c017f1b */ 	lui	$at,%hi(var7f1adad0)
/*  f0d1480:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d1484:	e5e0002c */ 	swc1	$f0,0x2c($t7)
/*  f0d1488:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d148c:	c426dad0 */ 	lwc1	$f6,%lo(var7f1adad0)($at)
/*  f0d1490:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f0d1494:	c5c40028 */ 	lwc1	$f4,0x28($t6)
/*  f0d1498:	46062302 */ 	mul.s	$f12,$f4,$f6
/*  f0d149c:	0c0068f7 */ 	jal	sinf
/*  f0d14a0:	00000000 */ 	nop
/*  f0d14a4:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d14a8:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d14ac:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d14b0:	44808000 */ 	mtc1	$zero,$f16
/*  f0d14b4:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d14b8:	e5e00030 */ 	swc1	$f0,0x30($t7)
/*  f0d14bc:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d14c0:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d14c4:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
.L0f0d14c8:
/*  f0d14c8:	c46a0024 */ 	lwc1	$f10,0x24($v1)
/*  f0d14cc:	3c017f1b */ 	lui	$at,%hi(var7f1adad4)
/*  f0d14d0:	c42cdad4 */ 	lwc1	$f12,%lo(var7f1adad4)($at)
/*  f0d14d4:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0d14d8:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d14dc:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0d14e0:	00000000 */ 	nop
/*  f0d14e4:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f0d14e8:	46004187 */ 	neg.s	$f6,$f8
/*  f0d14ec:	460a8100 */ 	add.s	$f4,$f16,$f10
/*  f0d14f0:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0d14f4:	c46a0020 */ 	lwc1	$f10,0x20($v1)
/*  f0d14f8:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f0d14fc:	00000000 */ 	nop
/*  f0d1500:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*  f0d1504:	00000000 */ 	nop
/*  f0d1508:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0d150c:	46068480 */ 	add.s	$f18,$f16,$f6
.L0f0d1510:
/*  f0d1510:	c7aa0094 */ 	lwc1	$f10,0x94($sp)
/*  f0d1514:	44802000 */ 	mtc1	$zero,$f4
/*  f0d1518:	3c017f1b */ 	lui	$at,%hi(var7f1adad8)
/*  f0d151c:	c42cdad8 */ 	lwc1	$f12,%lo(var7f1adad8)($at)
/*  f0d1520:	46045032 */ 	c.eq.s	$f10,$f4
/*  f0d1524:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0d1528:	45030016 */ 	bc1tl	.L0f0d1584
/*  f0d152c:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
/*  f0d1530:	44814000 */ 	mtc1	$at,$f8
/*  f0d1534:	c4660020 */ 	lwc1	$f6,0x20($v1)
/*  f0d1538:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d153c:	46085002 */ 	mul.s	$f0,$f10,$f8
/*  f0d1540:	00000000 */ 	nop
/*  f0d1544:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0d1548:	00000000 */ 	nop
/*  f0d154c:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0d1550:	00000000 */ 	nop
/*  f0d1554:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0d1558:	46088180 */ 	add.s	$f6,$f16,$f8
/*  f0d155c:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0d1560:	c4640024 */ 	lwc1	$f4,0x24($v1)
/*  f0d1564:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f0d1568:	00000000 */ 	nop
/*  f0d156c:	460c5202 */ 	mul.s	$f8,$f10,$f12
/*  f0d1570:	00000000 */ 	nop
/*  f0d1574:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0d1578:	46068100 */ 	add.s	$f4,$f16,$f6
/*  f0d157c:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f0d1580:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
.L0f0d1584:
/*  f0d1584:	44804000 */ 	mtc1	$zero,$f8
/*  f0d1588:	3c014040 */ 	lui	$at,0x4040
/*  f0d158c:	46085032 */ 	c.eq.s	$f10,$f8
/*  f0d1590:	00000000 */ 	nop
/*  f0d1594:	45030019 */ 	bc1tl	.L0f0d15fc
/*  f0d1598:	c466006c */ 	lwc1	$f6,0x6c($v1)
/*  f0d159c:	44813000 */ 	mtc1	$at,$f6
/*  f0d15a0:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0d15a4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0d15a8:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f0d15ac:	c526004c */ 	lwc1	$f6,0x4c($t1)
/*  f0d15b0:	240effff */ 	addiu	$t6,$zero,-1
/*  f0d15b4:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*  f0d15b8:	00000000 */ 	nop
/*  f0d15bc:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0d15c0:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f0d15c4:	45000003 */ 	bc1f	.L0f0d15d4
/*  f0d15c8:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f0d15cc:	10000002 */ 	b	.L0f0d15d8
/*  f0d15d0:	a46e003a */ 	sh	$t6,0x3a($v1)
.L0f0d15d4:
/*  f0d15d4:	a479003a */ 	sh	$t9,0x3a($v1)
.L0f0d15d8:
/*  f0d15d8:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d15dc:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d15e0:	a300003c */ 	sb	$zero,0x3c($t8)
/*  f0d15e4:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d15e8:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f0d15ec:	a320003d */ 	sb	$zero,0x3d($t9)
/*  f0d15f0:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d15f4:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d15f8:	c466006c */ 	lwc1	$f6,0x6c($v1)
.L0f0d15fc:
/*  f0d15fc:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0d1600:	3c017f1b */ 	lui	$at,%hi(var7f1adadc)
/*  f0d1604:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0d1608:	e468006c */ 	swc1	$f8,0x6c($v1)
/*  f0d160c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1610:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1614:	c46a0070 */ 	lwc1	$f10,0x70($v1)
/*  f0d1618:	46125180 */ 	add.s	$f6,$f10,$f18
/*  f0d161c:	e4660070 */ 	swc1	$f6,0x70($v1)
/*  f0d1620:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1624:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0d1628:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d162c:	c4640074 */ 	lwc1	$f4,0x74($v1)
/*  f0d1630:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0d1634:	e46a0074 */ 	swc1	$f10,0x74($v1)
/*  f0d1638:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d163c:	c7a400d0 */ 	lwc1	$f4,0xd0($sp)
/*  f0d1640:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1644:	c4660078 */ 	lwc1	$f6,0x78($v1)
/*  f0d1648:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0d164c:	e4680078 */ 	swc1	$f8,0x78($v1)
/*  f0d1650:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1654:	c428dadc */ 	lwc1	$f8,%lo(var7f1adadc)($at)
/*  f0d1658:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d165c:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1660:	c46c0070 */ 	lwc1	$f12,0x70($v1)
/*  f0d1664:	c460006c */ 	lwc1	$f0,0x6c($v1)
/*  f0d1668:	460c6282 */ 	mul.s	$f10,$f12,$f12
/*  f0d166c:	00000000 */ 	nop
/*  f0d1670:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f0d1674:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f0d1678:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0d167c:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0d1680:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f0d1684:	4604303c */ 	c.lt.s	$f6,$f4
/*  f0d1688:	00000000 */ 	nop
/*  f0d168c:	45000018 */ 	bc1f	.L0f0d16f0
/*  f0d1690:	00000000 */ 	nop
/*  f0d1694:	0c012974 */ 	jal	sqrtf
/*  f0d1698:	46002306 */ 	mov.s	$f12,$f4
/*  f0d169c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d16a0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d16a4:	3c014118 */ 	lui	$at,0x4118
/*  f0d16a8:	44814000 */ 	mtc1	$at,$f8
/*  f0d16ac:	c52a004c */ 	lwc1	$f10,0x4c($t1)
/*  f0d16b0:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d16b4:	44808000 */ 	mtc1	$zero,$f16
/*  f0d16b8:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f0d16bc:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d16c0:	c464006c */ 	lwc1	$f4,0x6c($v1)
/*  f0d16c4:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f0d16c8:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*  f0d16cc:	e468006c */ 	swc1	$f8,0x6c($v1)
/*  f0d16d0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d16d4:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d16d8:	c46a0070 */ 	lwc1	$f10,0x70($v1)
/*  f0d16dc:	460c5182 */ 	mul.s	$f6,$f10,$f12
/*  f0d16e0:	e4660070 */ 	swc1	$f6,0x70($v1)
/*  f0d16e4:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d16e8:	c522004c */ 	lwc1	$f2,0x4c($t1)
/*  f0d16ec:	8f230480 */ 	lw	$v1,0x480($t9)
.L0f0d16f0:
/*  f0d16f0:	c46c0078 */ 	lwc1	$f12,0x78($v1)
/*  f0d16f4:	c4600074 */ 	lwc1	$f0,0x74($v1)
/*  f0d16f8:	3c014361 */ 	lui	$at,0x4361
/*  f0d16fc:	460c6102 */ 	mul.s	$f4,$f12,$f12
/*  f0d1700:	44813000 */ 	mtc1	$at,$f6
/*  f0d1704:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f0d1708:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0d170c:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f0d1710:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0d1714:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0d1718:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0d171c:	00000000 */ 	nop
/*  f0d1720:	4502001a */ 	bc1fl	.L0f0d178c
/*  f0d1724:	c4640044 */ 	lwc1	$f4,0x44($v1)
/*  f0d1728:	0c012974 */ 	jal	sqrtf
/*  f0d172c:	46005306 */ 	mov.s	$f12,$f10
/*  f0d1730:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1734:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1738:	3c014170 */ 	lui	$at,0x4170
/*  f0d173c:	44813000 */ 	mtc1	$at,$f6
/*  f0d1740:	c524004c */ 	lwc1	$f4,0x4c($t1)
/*  f0d1744:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1748:	44808000 */ 	mtc1	$zero,$f16
/*  f0d174c:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0d1750:	46004283 */ 	div.s	$f10,$f8,$f0
/*  f0d1754:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0d1758:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d175c:	c4660074 */ 	lwc1	$f6,0x74($v1)
/*  f0d1760:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f0d1764:	e4640074 */ 	swc1	$f4,0x74($v1)
/*  f0d1768:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d176c:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0d1770:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1774:	c4680078 */ 	lwc1	$f8,0x78($v1)
/*  f0d1778:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0d177c:	e46a0078 */ 	swc1	$f10,0x78($v1)
/*  f0d1780:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1784:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1788:	c4640044 */ 	lwc1	$f4,0x44($v1)
.L0f0d178c:
/*  f0d178c:	c7a800c4 */ 	lwc1	$f8,0xc4($sp)
/*  f0d1790:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0d1794:	44815000 */ 	mtc1	$at,$f10
/*  f0d1798:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0d179c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0d17a0:	e4660044 */ 	swc1	$f6,0x44($v1)
/*  f0d17a4:	c524004c */ 	lwc1	$f4,0x4c($t1)
/*  f0d17a8:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d17ac:	46045082 */ 	mul.s	$f2,$f10,$f4
/*  f0d17b0:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d17b4:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f0d17b8:	46001307 */ 	neg.s	$f12,$f2
/*  f0d17bc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0d17c0:	00000000 */ 	nop
/*  f0d17c4:	45020009 */ 	bc1fl	.L0f0d17ec
/*  f0d17c8:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0d17cc:	e46c0044 */ 	swc1	$f12,0x44($v1)
/*  f0d17d0:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d17d4:	c526004c */ 	lwc1	$f6,0x4c($t1)
/*  f0d17d8:	44814000 */ 	mtc1	$at,$f8
/*  f0d17dc:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d17e0:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f0d17e4:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f0d17e8:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0d17ec:
/*  f0d17ec:	00000000 */ 	nop
/*  f0d17f0:	4502000a */ 	bc1fl	.L0f0d181c
/*  f0d17f4:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f0d17f8:	e4620044 */ 	swc1	$f2,0x44($v1)
/*  f0d17fc:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1800:	10000005 */ 	b	.L0f0d1818
/*  f0d1804:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1808:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f0d180c:
/*  f0d180c:	a06e003d */ 	sb	$t6,0x3d($v1)
/*  f0d1810:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1814:	8f230480 */ 	lw	$v1,0x480($t9)
.L0f0d1818:
/*  f0d1818:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
.L0f0d181c:
/*  f0d181c:	46105032 */ 	c.eq.s	$f10,$f16
/*  f0d1820:	00000000 */ 	nop
/*  f0d1824:	45020037 */ 	bc1fl	.L0f0d1904
/*  f0d1828:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f0d182c:	906f003d */ 	lbu	$t7,0x3d($v1)
/*  f0d1830:	3c017f1b */ 	lui	$at,%hi(var7f1adae0)
/*  f0d1834:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1838:	55e00011 */ 	bnezl	$t7,.L0f0d1880
/*  f0d183c:	a078003d */ 	sb	$t8,0x3d($v1)
/*  f0d1840:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f0d1844:	44802000 */ 	mtc1	$zero,$f4
/*  f0d1848:	00000000 */ 	nop
/*  f0d184c:	4600203c */ 	c.lt.s	$f4,$f0
/*  f0d1850:	00000000 */ 	nop
/*  f0d1854:	45020004 */ 	bc1fl	.L0f0d1868
/*  f0d1858:	46000087 */ 	neg.s	$f2,$f0
/*  f0d185c:	10000002 */ 	b	.L0f0d1868
/*  f0d1860:	46000086 */ 	mov.s	$f2,$f0
/*  f0d1864:	46000087 */ 	neg.s	$f2,$f0
.L0f0d1868:
/*  f0d1868:	c428dae0 */ 	lwc1	$f8,%lo(var7f1adae0)($at)
/*  f0d186c:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0d1870:	00000000 */ 	nop
/*  f0d1874:	45020023 */ 	bc1fl	.L0f0d1904
/*  f0d1878:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f0d187c:	a078003d */ 	sb	$t8,0x3d($v1)
.L0f0d1880:
/*  f0d1880:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1884:	8d2f0038 */ 	lw	$t7,0x38($t1)
/*  f0d1888:	3c017f1b */ 	lui	$at,%hi(var7f1adae4)
/*  f0d188c:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1890:	9079003c */ 	lbu	$t9,0x3c($v1)
/*  f0d1894:	032fc021 */ 	addu	$t8,$t9,$t7
/*  f0d1898:	a078003c */ 	sb	$t8,0x3c($v1)
/*  f0d189c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d18a0:	c426dae4 */ 	lwc1	$f6,%lo(var7f1adae4)($at)
/*  f0d18a4:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d18a8:	8479003a */ 	lh	$t9,0x3a($v1)
/*  f0d18ac:	44995000 */ 	mtc1	$t9,$f10
/*  f0d18b0:	00000000 */ 	nop
/*  f0d18b4:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0d18b8:	c46a0044 */ 	lwc1	$f10,0x44($v1)
/*  f0d18bc:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0d18c0:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0d18c4:	e4660044 */ 	swc1	$f6,0x44($v1)
/*  f0d18c8:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d18cc:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d18d0:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0d18d4:	2b010079 */ 	slti	$at,$t8,0x79
/*  f0d18d8:	5420000a */ 	bnezl	$at,.L0f0d1904
/*  f0d18dc:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f0d18e0:	a060003c */ 	sb	$zero,0x3c($v1)
/*  f0d18e4:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d18e8:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d18ec:	8479003a */ 	lh	$t9,0x3a($v1)
/*  f0d18f0:	00197823 */ 	negu	$t7,$t9
/*  f0d18f4:	a46f003a */ 	sh	$t7,0x3a($v1)
/*  f0d18f8:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d18fc:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1900:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
.L0f0d1904:
/*  f0d1904:	c4640044 */ 	lwc1	$f4,0x44($v1)
/*  f0d1908:	3c028007 */ 	lui	$v0,%hi(var80070ec4)
/*  f0d190c:	24420ec4 */ 	addiu	$v0,$v0,%lo(var80070ec4)
/*  f0d1910:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0d1914:	3c018007 */ 	lui	$at,%hi(var80070ec8)
/*  f0d1918:	e46a0044 */ 	swc1	$f10,0x44($v1)
/*  f0d191c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1920:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1924:	c4680074 */ 	lwc1	$f8,0x74($v1)
/*  f0d1928:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0d192c:	e4660074 */ 	swc1	$f6,0x74($v1)
/*  f0d1930:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1934:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1938:	c4640078 */ 	lwc1	$f4,0x78($v1)
/*  f0d193c:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0d1940:	e46a0078 */ 	swc1	$f10,0x78($v1)
/*  f0d1944:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1948:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d194c:	c468006c */ 	lwc1	$f8,0x6c($v1)
/*  f0d1950:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0d1954:	e466006c */ 	swc1	$f6,0x6c($v1)
/*  f0d1958:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d195c:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1960:	c4640070 */ 	lwc1	$f4,0x70($v1)
/*  f0d1964:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0d1968:	e46a0070 */ 	swc1	$f10,0x70($v1)
/*  f0d196c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1970:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1974:	c468006c */ 	lwc1	$f8,0x6c($v1)
/*  f0d1978:	c4660074 */ 	lwc1	$f6,0x74($v1)
/*  f0d197c:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0d1980:	e4640040 */ 	swc1	$f4,0x40($v1)
/*  f0d1984:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1988:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d198c:	c46a0070 */ 	lwc1	$f10,0x70($v1)
/*  f0d1990:	c4680078 */ 	lwc1	$f8,0x78($v1)
/*  f0d1994:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0d1998:	e4660048 */ 	swc1	$f6,0x48($v1)
/*  f0d199c:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d19a0:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d19a4:	c4640030 */ 	lwc1	$f4,0x30($v1)
/*  f0d19a8:	e4640008 */ 	swc1	$f4,0x8($v1)
/*  f0d19ac:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d19b0:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d19b4:	c46a002c */ 	lwc1	$f10,0x2c($v1)
/*  f0d19b8:	c4680024 */ 	lwc1	$f8,0x24($v1)
/*  f0d19bc:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d19c0:	e4660004 */ 	swc1	$f6,0x4($v1)
/*  f0d19c4:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d19c8:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d19cc:	c464002c */ 	lwc1	$f4,0x2c($v1)
/*  f0d19d0:	c4680020 */ 	lwc1	$f8,0x20($v1)
/*  f0d19d4:	46002287 */ 	neg.s	$f10,$f4
/*  f0d19d8:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d19dc:	e466000c */ 	swc1	$f6,0xc($v1)
/*  f0d19e0:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d19e4:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d19e8:	c464002c */ 	lwc1	$f4,0x2c($v1)
/*  f0d19ec:	e4640014 */ 	swc1	$f4,0x14($v1)
/*  f0d19f0:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d19f4:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d19f8:	c46a0030 */ 	lwc1	$f10,0x30($v1)
/*  f0d19fc:	c4660024 */ 	lwc1	$f6,0x24($v1)
/*  f0d1a00:	46005207 */ 	neg.s	$f8,$f10
/*  f0d1a04:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0d1a08:	e4640010 */ 	swc1	$f4,0x10($v1)
/*  f0d1a0c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1a10:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1a14:	c46a0030 */ 	lwc1	$f10,0x30($v1)
/*  f0d1a18:	c4680020 */ 	lwc1	$f8,0x20($v1)
/*  f0d1a1c:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d1a20:	e4660018 */ 	swc1	$f6,0x18($v1)
/*  f0d1a24:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f0d1a28:	a02e0ec8 */ 	sb	$t6,%lo(var80070ec8)($at)
/*  f0d1a2c:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f0d1a30:	3c018007 */ 	lui	$at,%hi(var80070ecc)
/*  f0d1a34:	0fc33f89 */ 	jal	eyespyUpdateVertical
/*  f0d1a38:	a0200ecc */ 	sb	$zero,%lo(var80070ecc)($at)
/*  f0d1a3c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1a40:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1a44:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1a48:	3c188007 */ 	lui	$t8,%hi(var80070ec4)
/*  f0d1a4c:	3c0e8007 */ 	lui	$t6,%hi(var80070ec8)
/*  f0d1a50:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1a54:	806f0037 */ 	lb	$t7,0x37($v1)
/*  f0d1a58:	51e0007f */ 	beqzl	$t7,.L0f0d1c58
/*  f0d1a5c:	3c0144c8 */ 	lui	$at,0x44c8
/*  f0d1a60:	93180ec4 */ 	lbu	$t8,%lo(var80070ec4)($t8)
/*  f0d1a64:	91ce0ec8 */ 	lbu	$t6,%lo(var80070ec8)($t6)
/*  f0d1a68:	51d8007b */ 	beql	$t6,$t8,.L0f0d1c58
/*  f0d1a6c:	3c0144c8 */ 	lui	$at,0x44c8
/*  f0d1a70:	1b000078 */ 	blez	$t8,.L0f0d1c54
/*  f0d1a74:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0d1a78:	8f2f0120 */ 	lw	$t7,0x120($t9)
/*  f0d1a7c:	270effff */ 	addiu	$t6,$t8,-1
/*  f0d1a80:	29e1000b */ 	slti	$at,$t7,0xb
/*  f0d1a84:	14200073 */ 	bnez	$at,.L0f0d1c54
/*  f0d1a88:	2dc10005 */ 	sltiu	$at,$t6,0x5
/*  f0d1a8c:	1020006f */ 	beqz	$at,.L0f0d1c4c
/*  f0d1a90:	af200120 */ 	sw	$zero,0x120($t9)
/*  f0d1a94:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0d1a98:	3c017f1b */ 	lui	$at,%hi(var7f1adae8)
/*  f0d1a9c:	002e0821 */ 	addu	$at,$at,$t6
/*  f0d1aa0:	8c2edae8 */ 	lw	$t6,%lo(var7f1adae8)($at)
/*  f0d1aa4:	01c00008 */ 	jr	$t6
/*  f0d1aa8:	00000000 */ 	nop
/*  f0d1aac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d1ab0:	44812000 */ 	mtc1	$at,$f4
/*  f0d1ab4:	340f808c */ 	dli	$t7,0x808c
/*  f0d1ab8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0d1abc:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0d1ac0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d1ac4:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f0d1ac8:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0d1acc:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0d1ad0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d1ad4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d1ad8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d1adc:	24063e80 */ 	addiu	$a2,$zero,0x3e80
/*  f0d1ae0:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0d1ae4:	0c0041c6 */ 	jal	func00010718
/*  f0d1ae8:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0d1aec:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1af0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1af4:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1af8:	10000056 */ 	b	.L0f0d1c54
/*  f0d1afc:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1b00:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d1b04:	44815000 */ 	mtc1	$at,$f10
/*  f0d1b08:	3419808c */ 	dli	$t9,0x808c
/*  f0d1b0c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1b10:	240effff */ 	addiu	$t6,$zero,-1
/*  f0d1b14:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d1b18:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0d1b1c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0d1b20:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0d1b24:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0d1b28:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d1b2c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d1b30:	24063e80 */ 	addiu	$a2,$zero,0x3e80
/*  f0d1b34:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0d1b38:	0c0041c6 */ 	jal	func00010718
/*  f0d1b3c:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f0d1b40:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1b44:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1b48:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1b4c:	10000041 */ 	b	.L0f0d1c54
/*  f0d1b50:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1b54:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d1b58:	44814000 */ 	mtc1	$at,$f8
/*  f0d1b5c:	3418808c */ 	dli	$t8,0x808c
/*  f0d1b60:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d1b64:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0d1b68:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0d1b6c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0d1b70:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0d1b74:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0d1b78:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0d1b7c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d1b80:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d1b84:	24063e80 */ 	addiu	$a2,$zero,0x3e80
/*  f0d1b88:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0d1b8c:	0c0041c6 */ 	jal	func00010718
/*  f0d1b90:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0d1b94:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1b98:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1b9c:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0d1ba0:	1000002c */ 	b	.L0f0d1c54
/*  f0d1ba4:	8f030480 */ 	lw	$v1,0x480($t8)
/*  f0d1ba8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d1bac:	44813000 */ 	mtc1	$at,$f6
/*  f0d1bb0:	340e808c */ 	dli	$t6,0x808c
/*  f0d1bb4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d1bb8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0d1bbc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1bc0:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0d1bc4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0d1bc8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0d1bcc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0d1bd0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d1bd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d1bd8:	24063e80 */ 	addiu	$a2,$zero,0x3e80
/*  f0d1bdc:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0d1be0:	0c0041c6 */ 	jal	func00010718
/*  f0d1be4:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0d1be8:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1bec:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1bf0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1bf4:	10000017 */ 	b	.L0f0d1c54
/*  f0d1bf8:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1bfc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0d1c00:	44812000 */ 	mtc1	$at,$f4
/*  f0d1c04:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f0d1c08:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0d1c0c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0d1c10:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0d1c14:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0d1c18:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0d1c1c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d1c20:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f0d1c24:	240500f2 */ 	addiu	$a1,$zero,0xf2
/*  f0d1c28:	00003025 */ 	or	$a2,$zero,$zero
/*  f0d1c2c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0d1c30:	0c004241 */ 	jal	audioStart
/*  f0d1c34:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0d1c38:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1c3c:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1c40:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1c44:	10000003 */ 	b	.L0f0d1c54
/*  f0d1c48:	8dc30480 */ 	lw	$v1,0x480($t6)
.L0f0d1c4c:
/*  f0d1c4c:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1c50:	8de30480 */ 	lw	$v1,0x480($t7)
.L0f0d1c54:
/*  f0d1c54:	3c0144c8 */ 	lui	$at,0x44c8
.L0f0d1c58:
/*  f0d1c58:	44816000 */ 	mtc1	$at,$f12
/*  f0d1c5c:	c4620058 */ 	lwc1	$f2,0x58($v1)
/*  f0d1c60:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0d1c64:	00000000 */ 	nop
/*  f0d1c68:	45020006 */ 	bc1fl	.L0f0d1c84
/*  f0d1c6c:	460c1003 */ 	div.s	$f0,$f2,$f12
/*  f0d1c70:	e46c0058 */ 	swc1	$f12,0x58($v1)
/*  f0d1c74:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1c78:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1c7c:	c4620058 */ 	lwc1	$f2,0x58($v1)
/*  f0d1c80:	460c1003 */ 	div.s	$f0,$f2,$f12
.L0f0d1c84:
/*  f0d1c84:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0d1c88:	44815000 */ 	mtc1	$at,$f10
/*  f0d1c8c:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f0d1c90:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0d1c94:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0d1c98:	44053000 */ 	mfc1	$a1,$f6
/*  f0d1c9c:	0fc24de4 */ 	jal	func0f093790
/*  f0d1ca0:	00000000 */ 	nop
/*  f0d1ca4:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1ca8:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1cac:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1cb0:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0d1cb4:	44817000 */ 	mtc1	$at,$f14
/*  f0d1cb8:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f0d1cbc:	3c014334 */ 	lui	$at,0x4334
/*  f0d1cc0:	44812000 */ 	mtc1	$at,$f4
/*  f0d1cc4:	c5ea001c */ 	lwc1	$f10,0x1c($t7)
/*  f0d1cc8:	44804000 */ 	mtc1	$zero,$f8
/*  f0d1ccc:	460a2001 */ 	sub.s	$f0,$f4,$f10
/*  f0d1cd0:	4608003c */ 	c.lt.s	$f0,$f8
/*  f0d1cd4:	00000000 */ 	nop
/*  f0d1cd8:	45020003 */ 	bc1fl	.L0f0d1ce8
/*  f0d1cdc:	460e0183 */ 	div.s	$f6,$f0,$f14
/*  f0d1ce0:	460e0000 */ 	add.s	$f0,$f0,$f14
/*  f0d1ce4:	460e0183 */ 	div.s	$f6,$f0,$f14
.L0f0d1ce8:
/*  f0d1ce8:	3c017f1b */ 	lui	$at,%hi(var7f1adafc)
/*  f0d1cec:	c424dafc */ 	lwc1	$f4,%lo(var7f1adafc)($at)
/*  f0d1cf0:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f0d1cf4:	46043002 */ 	mul.s	$f0,$f6,$f4
/*  f0d1cf8:	44050000 */ 	mfc1	$a1,$f0
/*  f0d1cfc:	0fc0f94e */ 	jal	chrSetLookAngle
/*  f0d1d00:	00000000 */ 	nop
/*  f0d1d04:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1d08:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1d0c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1d10:	8f230480 */ 	lw	$v1,0x480($t9)
/*  f0d1d14:	80780036 */ 	lb	$t8,0x36($v1)
/*  f0d1d18:	2b010032 */ 	slti	$at,$t8,0x32
/*  f0d1d1c:	542000aa */ 	bnezl	$at,.L0f0d1fc8
/*  f0d1d20:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0d1d24:	806e0068 */ 	lb	$t6,0x68($v1)
/*  f0d1d28:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*  f0d1d2c:	5dc00013 */ 	bgtzl	$t6,.L0f0d1d7c
/*  f0d1d30:	a0600039 */ 	sb	$zero,0x39($v1)
/*  f0d1d34:	51e00011 */ 	beqzl	$t7,.L0f0d1d7c
/*  f0d1d38:	a0600039 */ 	sb	$zero,0x39($v1)
/*  f0d1d3c:	80790037 */ 	lb	$t9,0x37($v1)
/*  f0d1d40:	5320000e */ 	beqzl	$t9,.L0f0d1d7c
/*  f0d1d44:	a0600039 */ 	sb	$zero,0x39($v1)
/*  f0d1d48:	80780039 */ 	lb	$t8,0x39($v1)
/*  f0d1d4c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0d1d50:	5700000d */ 	bnezl	$t8,.L0f0d1d88
/*  f0d1d54:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f0d1d58:	a06e0039 */ 	sb	$t6,0x39($v1)
/*  f0d1d5c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1d60:	240f0018 */ 	addiu	$t7,$zero,0x18
/*  f0d1d64:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f0d1d68:	a30f0068 */ 	sb	$t7,0x68($t8)
/*  f0d1d6c:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1d70:	10000004 */ 	b	.L0f0d1d84
/*  f0d1d74:	8dc30480 */ 	lw	$v1,0x480($t6)
/*  f0d1d78:	a0600039 */ 	sb	$zero,0x39($v1)
.L0f0d1d7c:
/*  f0d1d7c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1d80:	8f230480 */ 	lw	$v1,0x480($t9)
.L0f0d1d84:
/*  f0d1d84:	8faf00a4 */ 	lw	$t7,0xa4($sp)
.L0f0d1d88:
/*  f0d1d88:	3c0a8007 */ 	lui	$t2,%hi(var80070ec0)
/*  f0d1d8c:	254a0ec0 */ 	addiu	$t2,$t2,%lo(var80070ec0)
/*  f0d1d90:	51e0000d */ 	beqzl	$t7,.L0f0d1dc8
/*  f0d1d94:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0d1d98:	80780037 */ 	lb	$t8,0x37($v1)
/*  f0d1d9c:	5300000a */ 	beqzl	$t8,.L0f0d1dc8
/*  f0d1da0:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0d1da4:	a0600037 */ 	sb	$zero,0x37($v1)
/*  f0d1da8:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d1dac:	2401fffb */ 	addiu	$at,$zero,-5
/*  f0d1db0:	8dae00c4 */ 	lw	$t6,0xc4($t5)
/*  f0d1db4:	01c1c824 */ 	and	$t9,$t6,$at
/*  f0d1db8:	adb900c4 */ 	sw	$t9,0xc4($t5)
/*  f0d1dbc:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1dc0:	8de30480 */ 	lw	$v1,0x480($t7)
/*  f0d1dc4:	8fb800a0 */ 	lw	$t8,0xa0($sp)
.L0f0d1dc8:
/*  f0d1dc8:	53000011 */ 	beqzl	$t8,.L0f0d1e10
/*  f0d1dcc:	a060006a */ 	sb	$zero,0x6a($v1)
/*  f0d1dd0:	806e0037 */ 	lb	$t6,0x37($v1)
/*  f0d1dd4:	51c0000e */ 	beqzl	$t6,.L0f0d1e10
/*  f0d1dd8:	a060006a */ 	sb	$zero,0x6a($v1)
/*  f0d1ddc:	80790038 */ 	lb	$t9,0x38($v1)
/*  f0d1de0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0d1de4:	17200007 */ 	bnez	$t9,.L0f0d1e04
/*  f0d1de8:	00000000 */ 	nop
/*  f0d1dec:	a06f0038 */ 	sb	$t7,0x38($v1)
/*  f0d1df0:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1df4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1df8:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f0d1dfc:	10000007 */ 	b	.L0f0d1e1c
/*  f0d1e00:	a338006a */ 	sb	$t8,0x6a($t9)
.L0f0d1e04:
/*  f0d1e04:	10000005 */ 	b	.L0f0d1e1c
/*  f0d1e08:	a060006a */ 	sb	$zero,0x6a($v1)
/*  f0d1e0c:	a060006a */ 	sb	$zero,0x6a($v1)
.L0f0d1e10:
/*  f0d1e10:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1e14:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f0d1e18:	a1c00038 */ 	sb	$zero,0x38($t6)
.L0f0d1e1c:
/*  f0d1e1c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1e20:	3c188007 */ 	lui	$t8,%hi(var80070ec4)
/*  f0d1e24:	93180ec4 */ 	lbu	$t8,%lo(var80070ec4)($t8)
/*  f0d1e28:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d1e2c:	a1f80069 */ 	sb	$t8,0x69($t7)
/*  f0d1e30:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d1e34:	8da30480 */ 	lw	$v1,0x480($t5)
/*  f0d1e38:	806e0037 */ 	lb	$t6,0x37($v1)
/*  f0d1e3c:	55c0002a */ 	bnezl	$t6,.L0f0d1ee8
/*  f0d1e40:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d1e44:	91590000 */ 	lbu	$t9,0x0($t2)
/*  f0d1e48:	240e0022 */ 	addiu	$t6,$zero,0x22
/*  f0d1e4c:	57200026 */ 	bnezl	$t9,.L0f0d1ee8
/*  f0d1e50:	8d2d0284 */ 	lw	$t5,0x284($t1)
/*  f0d1e54:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f0d1e58:	8da800bc */ 	lw	$t0,0xbc($t5)
/*  f0d1e5c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1e60:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0d1e64:	c5080008 */ 	lwc1	$f8,0x8($t0)
/*  f0d1e68:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0d1e6c:	c5040010 */ 	lwc1	$f4,0x10($t0)
/*  f0d1e70:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f0d1e74:	a1580000 */ 	sb	$t8,0x0($t2)
/*  f0d1e78:	3c017f1b */ 	lui	$at,%hi(var7f1adb00)
/*  f0d1e7c:	46043081 */ 	sub.s	$f2,$f6,$f4
/*  f0d1e80:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f0d1e84:	c42adb00 */ 	lwc1	$f10,%lo(var7f1adb00)($at)
/*  f0d1e88:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f0d1e8c:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0d1e90:	4604503c */ 	c.lt.s	$f10,$f4
/*  f0d1e94:	00000000 */ 	nop
/*  f0d1e98:	45020003 */ 	bc1fl	.L0f0d1ea8
/*  f0d1e9c:	8daf0480 */ 	lw	$t7,0x480($t5)
/*  f0d1ea0:	a1400000 */ 	sb	$zero,0x0($t2)
/*  f0d1ea4:	8daf0480 */ 	lw	$t7,0x480($t5)
.L0f0d1ea8:
/*  f0d1ea8:	8da800bc */ 	lw	$t0,0xbc($t5)
/*  f0d1eac:	2419001c */ 	addiu	$t9,$zero,0x1c
/*  f0d1eb0:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f0d1eb4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0d1eb8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0d1ebc:	25040008 */ 	addiu	$a0,$t0,0x8
/*  f0d1ec0:	25050028 */ 	addiu	$a1,$t0,0x28
/*  f0d1ec4:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f0d1ec8:	0c00b70f */ 	jal	hasLineOfSight
/*  f0d1ecc:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f0d1ed0:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1ed4:	14400003 */ 	bnez	$v0,.L0f0d1ee4
/*  f0d1ed8:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1edc:	3c018007 */ 	lui	$at,%hi(var80070ec0)
/*  f0d1ee0:	a0200ec0 */ 	sb	$zero,%lo(var80070ec0)($at)
.L0f0d1ee4:
/*  f0d1ee4:	8d2d0284 */ 	lw	$t5,0x284($t1)
.L0f0d1ee8:
/*  f0d1ee8:	3c0a8007 */ 	lui	$t2,%hi(var80070ec0)
/*  f0d1eec:	254a0ec0 */ 	addiu	$t2,$t2,%lo(var80070ec0)
/*  f0d1ef0:	8db80480 */ 	lw	$t8,0x480($t5)
/*  f0d1ef4:	830f0037 */ 	lb	$t7,0x37($t8)
/*  f0d1ef8:	51e00003 */ 	beqzl	$t7,.L0f0d1f08
/*  f0d1efc:	914e0000 */ 	lbu	$t6,0x0($t2)
/*  f0d1f00:	a1400000 */ 	sb	$zero,0x0($t2)
/*  f0d1f04:	914e0000 */ 	lbu	$t6,0x0($t2)
.L0f0d1f08:
/*  f0d1f08:	51c0002a */ 	beqzl	$t6,.L0f0d1fb4
/*  f0d1f0c:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0d1f10:	8db90480 */ 	lw	$t9,0x480($t5)
/*  f0d1f14:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d1f18:	2404002e */ 	addiu	$a0,$zero,0x2e
/*  f0d1f1c:	a3200035 */ 	sb	$zero,0x35($t9)
/*  f0d1f20:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1f24:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f0d1f28:	a1d80034 */ 	sb	$t8,0x34($t6)
/*  f0d1f2c:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0d1f30:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f0d1f34:	a1e00037 */ 	sb	$zero,0x37($t7)
/*  f0d1f38:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0d1f3c:	8f0e0018 */ 	lw	$t6,0x18($t8)
/*  f0d1f40:	35d90400 */ 	ori	$t9,$t6,0x400
/*  f0d1f44:	372f0010 */ 	ori	$t7,$t9,0x10
/*  f0d1f48:	af190018 */ 	sw	$t9,0x18($t8)
/*  f0d1f4c:	0fc21f44 */ 	jal	func0f087d10
/*  f0d1f50:	af0f0018 */ 	sw	$t7,0x18($t8)
/*  f0d1f54:	2404002e */ 	addiu	$a0,$zero,0x2e
/*  f0d1f58:	0fc221f2 */ 	jal	currentPlayerQueuePickupWeaponHudmsg
/*  f0d1f5c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d1f60:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1f64:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1f68:	8d2e0284 */ 	lw	$t6,0x284($t1)
/*  f0d1f6c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0d1f70:	3406ffff */ 	dli	$a2,0xffff
/*  f0d1f74:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f0d1f78:	0fc249af */ 	jal	func0f0926bc
/*  f0d1f7c:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0d1f80:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0d1f84:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0d1f88:	8d2f0284 */ 	lw	$t7,0x284($t1)
/*  f0d1f8c:	8d390338 */ 	lw	$t9,0x338($t1)
/*  f0d1f90:	24010048 */ 	addiu	$at,$zero,0x48
/*  f0d1f94:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f0d1f98:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f0d1f9c:	01d92023 */ 	subu	$a0,$t6,$t9
/*  f0d1fa0:	0081001a */ 	div	$zero,$a0,$at
/*  f0d1fa4:	00002012 */ 	mflo	$a0
/*  f0d1fa8:	0fc083e4 */ 	jal	propClearReferences
/*  f0d1fac:	00000000 */ 	nop
/*  f0d1fb0:	8fb800e4 */ 	lw	$t8,0xe4($sp)
.L0f0d1fb4:
/*  f0d1fb4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0d1fb8:	8f04001c */ 	lw	$a0,0x1c($t8)
/*  f0d1fbc:	0fc22af5 */ 	jal	func0f08abd4
/*  f0d1fc0:	24840008 */ 	addiu	$a0,$a0,8
/*  f0d1fc4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0d1fc8:
/*  f0d1fc8:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f0d1fcc:	03e00008 */ 	jr	$ra
/*  f0d1fd0:	00000000 */ 	nop
);
#endif
