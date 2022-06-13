#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/dlights.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/setuputils.h"
#include "game/propsnd.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/explosions.h"
#include "game/smoke.h"
#include "game/bg.h"
#include "game/room.h"
#include "game/file.h"
#include "game/gfxmemory.h"
#include "game/mplayer/mplayer.h"
#include "game/propobj.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

struct explosion *g_Explosions;
s32 g_MaxExplosions;

s32 g_ExplosionShakeTotalTimer = 0;
s32 g_ExplosionShakeIntensityTimer = 0;
f32 g_ExplosionDamageReceivedScale = 1;
u32 var8007e4ac = 0x0000004b;
u32 var8007e4b0 = 0x000001e0;
u32 var8007e4b4 = 0x000000a8;

struct explosiontype g_ExplosionTypes[NUM_EXPLOSIONTYPES] = {
	//       rangeh
	//       |    rangev
	//       |    |    changerateh
	//       |    |    |    changeratev
	//       |    |    |    |     innersize
	//       |    |    |    |     |     blastradius
	//       |    |    |    |     |     |     damageradius
	//       |    |    |    |     |     |     |     duration
	//       |    |    |    |     |     |     |     |    propagationrate
	//       |    |    |    |     |     |     |     |    |  flarespeed
	//       |    |    |    |     |     |     |     |    |  |  smoketype
	//       |    |    |    |     |     |     |     |    |  |  |                       sound
	//       |    |    |    |     |     |     |     |    |  |  |                       |       damage
	//       |    |    |    |     |     |     |     |    |  |  |                       |       |
	/*00*/ { 0.1, 0.1, 0,   0,    0.1,  0,    0,    1,   1, 1, SMOKETYPE_NONE,         0x0000, 0     },
	/*01*/ { 1,   1,   0,   0,    1,    0,    0,    30,  1, 1, SMOKETYPE_BULLETIMPACT, 0x0000, 0     },
	/*02*/ { 20,  20,  0,   0,    30,   50,   50,   40,  1, 3, SMOKETYPE_MINI,         0x8099, 0.125 },
	/*03*/ { 50,  50,  0,   0,    50,   100,  100,  45,  1, 4, SMOKETYPE_MINI,         0x809a, 0.5   },
	/*04*/ { 60,  80,  2,   0.6,  100,  130,  240,  60,  2, 5, SMOKETYPE_ELECTRICAL,   0x809e, 1     },
	/*05*/ { 60,  120, 2,   0.6,  150,  160,  280,  60,  2, 5, SMOKETYPE_ELECTRICAL,   0x809e, 2     },
	/*06*/ { 20,  20,  0,   0,    22,   40,   40,   60,  1, 3, SMOKETYPE_MINI,         0x8099, 0.5   },
	/*07*/ { 35,  40,  0,   0,    35,   70,   70,   60,  1, 4, SMOKETYPE_MINI,         0x809a, 1     },
	/*08*/ { 50,  80,  2,   0.6,  50,   100,  160,  60,  2, 5, SMOKETYPE_ELECTRICAL,   0x809e, 2     },
	/*09*/ { 60,  120, 2,   0.6,  50,   130,  180,  60,  2, 5, SMOKETYPE_ELECTRICAL,   0x809e, 2     },
	/*10*/ { 40,  40,  0.8, 0.5,  70,   80,   160,  80,  4, 5, SMOKETYPE_SMALL,        0x80a0, 1     },
	/*11*/ { 50,  50,  1.2, 0.8,  100,  100,  200,  90,  1, 4, SMOKETYPE_SMALL,        0x809e, 2     },
	/*12*/ { 70,  60,  2,   1.2,  150,  140,  280,  90,  2, 5, SMOKETYPE_MEDIUM,       0x809e, 4     },
	/*13*/ { 80,  60,  4,   1.4,  200,  200,  400,  90,  2, 5, SMOKETYPE_LARGE,        0x809f, 4     },
	/*14*/ { 50,  50,  0,   0,    120,  150,  300,  150, 4, 4, SMOKETYPE_SMALL,        0x809f, 4     },
	/*15*/ { 1,   1,   0,   0,    1,    0,    0,    1,   1, 1, SMOKETYPE_BULLETIMPACT, 0x809c, 0     },
	/*16*/ { 1,   1,   0,   0,    1,    0,    0,    1,   1, 1, SMOKETYPE_BULLETIMPACT, 0x809c, 0     },
	/*17*/ { 80,  60,  10,  5,    1500, 2200, 3600, 500, 1, 2, SMOKETYPE_NONE,         0x80a5, 4     },
	/*18*/ { 80,  60,  3,   1,    300,  450,  640,  60,  1, 2, SMOKETYPE_NONE,         0x809f, 4     },
	/*19*/ { 90,  75,  2.5, 0.87, 250,  375,  600,  180, 2, 5, SMOKETYPE_LARGE,        0x809f, 4     },
	/*20*/ { 160, 120, 6,   2,    600,  450,  640,  60,  1, 2, SMOKETYPE_NONE,         0x809f, 4     },
	/*21*/ { 40,  30,  2,   0.7,  100,  140,  270,  45,  2, 5, SMOKETYPE_SMALL,        0x809f, 3.5   },
	/*22*/ { 20,  20,  0,   0,    30,   100,  200,  40,  1, 3, SMOKETYPE_MINI,         0x8099, 0.25  },
	/*23*/ { 100, 80,  4,   1.4,  210,  220,  500,  90,  2, 5, SMOKETYPE_LARGE,        0x809f, 4     },
	/*24*/ { 80,  60,  4,   1.4,  500,  200,  400,  90,  2, 5, SMOKETYPE_LARGE,        0x809f, 4     },
	/*25*/ { 640, 480, 32,  11.2, 1600, 1000, 1000, 180, 2, 5, SMOKETYPE_NONE,         0x80a4, 4     },
};

bool explosionCreateSimple(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum)
{
	return explosionCreate(prop, pos, rooms, type, playernum, false, NULL, 0, NULL);
}

bool explosionCreateComplex(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum)
{
	struct coord sp100;
	struct coord sp88;
	struct explosiontype *etype;
	bool makescorch = true;
	s16 ret;
	f32 y;
	bool sp68;

	if (type == EXPLOSIONTYPE_NONE) {
		return false;
	}

	if (prop) {
		ret = cd0002a564(&prop->pos, prop->rooms, &y, 0, &sp88, &sp68);
		sp100.x = prop->pos.x;
		sp100.y = y;
		sp100.z = prop->pos.z;
	} else {
		ret = cd0002a564(pos, rooms, &y, 0, &sp88, &sp68);
		sp100.x = pos->x;
		sp100.y = y;
		sp100.z = pos->z;
	}

	etype = &g_ExplosionTypes[type];

	if (sp68 || ret <= 0
			|| !(pos->y - y <= (etype->rangev + etype->changeratev * etype->duration + etype->innersize) * 0.5f || pos->y - y <= 75)) {
		makescorch = false;
	}

	return explosionCreate(prop, pos, rooms, type, playernum, makescorch, &sp100, ret, &sp88);
}

f32 explosionGetHorizontalRangeAtFrame(struct explosion *exp, s32 frame)
{
	struct explosiontype *type = &g_ExplosionTypes[exp->type];
	f32 changerate = PALUPF(type->changerateh);
	f32 result;

	if (exp->type == EXPLOSIONTYPE_GASBARREL && frame > TICKS(32)) {
		result = frame * PALUPF(3.0f) + 40.0f;

		if (result > 300) {
			result = 300;
		}
	} else {
		result = type->rangeh + changerate * frame;
	}

	return result;
}

f32 explosionGetVerticalRangeAtFrame(struct explosion *exp, s32 frame)
{
	struct explosiontype *type = &g_ExplosionTypes[exp->type];
	f32 changerate = PALUPF(type->changeratev);
	f32 result;

	if (exp->type == EXPLOSIONTYPE_GASBARREL && frame > TICKS(32)) {
		result = 20;
	} else {
		result = type->rangev + changerate * frame;
	}

	return result;
}

void explosionGetBboxAtFrame(struct coord *lower, struct coord *upper, s32 frame, struct prop *prop)
{
	struct explosion *exp = prop->explosion;
	struct explosiontype *type = &g_ExplosionTypes[exp->type];

	f32 rangeh = explosionGetHorizontalRangeAtFrame(exp, frame);
	f32 rangev = explosionGetVerticalRangeAtFrame(exp, frame);

	rangeh = rangeh * 0.5f + type->innersize * 1.5f;
	rangev = rangev * 0.5f + type->innersize * 1.5f;

	lower->x = prop->pos.x - rangeh;
	lower->y = prop->pos.y - rangev;
	lower->z = prop->pos.z - rangeh;

	upper->x = prop->pos.x + rangeh;
	upper->y = prop->pos.y + rangev;
	upper->z = prop->pos.z + rangeh;
}

void explosionAlertChrs(f32 *radius, struct coord *noisepos)
{
	u32 stack[2];
	s32 *end = (s32 *)&doorDestroyGlass;
	s32 i;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].model
				&& chrGetTargetProp(&g_ChrSlots[i]) == g_Vars.currentplayer->prop
				&& g_ChrSlots[i].prop
				&& g_ChrSlots[i].prop->type == PROPTYPE_CHR
				&& (g_ChrSlots[i].prop->flags & PROPFLAG_ENABLED)) {
			f32 distance = chrGetDistanceToCoord(&g_ChrSlots[i], noisepos);

			if (distance == 0) {
				distance = 2;
			} else {
				distance = (10.0f * *radius * g_ChrSlots[i].hearingscale) / distance;
			}

			if (distance > 1) {
				chrRecordLastHearTargetTime(&g_ChrSlots[i]);
			}
		}
	}

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *ptr = (s32 *)&glassDestroy;

		while (ptr < end) {
			checksum ^= *ptr;
			checksum <<= 1;
			ptr++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			struct explosiontype *type = &g_ExplosionTypes[0];
			s32 i;

			for (i = 0; i != NUM_EXPLOSIONTYPES - 1; i++) {
				type->rangeh = 80;
				type->rangev = 60;
				type->changerateh = 15;
				type->changeratev = 5;
				type->innersize = 1500;
				type->blastradius = 200;
				type->damageradius = 3600;
				type++;
			}
		}
	}
#endif
}

bool explosionCreate(struct prop *sourceprop, struct coord *exppos, s16 *exprooms,
		s16 type, s32 playernum, bool makescorch, struct coord *arg6, s16 room, struct coord *arg8)
{
	u32 stack;
	struct explosion *exp = NULL;
	s32 i;

	if (type == EXPLOSIONTYPE_NONE || exprooms[0] == -1) {
		return false;
	}

	// Bullet holes: only crate the flame (explosion) if within 4 metres
	if (type == EXPLOSIONTYPE_BULLETHOLE) {
		f32 lodscale = camGetLodScaleZ();
		struct coord *campos = &g_Vars.currentplayer->cam_pos;
		f32 xdist = exppos->x - campos->x;
		f32 ydist = exppos->y - campos->y;
		f32 zdist = exppos->z - campos->z;
		f32 sum = xdist * xdist + ydist * ydist + zdist * zdist;

		if (sum * lodscale * lodscale > 400 * 400) {
			if (random() % 2 == 0) {
				if (sourceprop) {
					smokeCreateSimple(&sourceprop->pos, sourceprop->rooms, g_ExplosionTypes[type].smoketype);
				} else {
					smokeCreateSimple(exppos, exprooms, g_ExplosionTypes[type].smoketype);
				}
			}

			return true;
		}
	}

	// Try to find an unused slot
	for (i = 0; i < g_MaxExplosions; i++) {
		if (g_Explosions[i].prop == NULL) {
			exp = &g_Explosions[i];
			break;
		}
	}

	// If there's no unused slots, find the oldest bullethole flame and replace it
	if (exp == NULL) {
		s32 maxage = -1;
		s32 index = -1;

		for (i = 0; i < g_MaxExplosions; i++) {
			if (g_Explosions[i].type == EXPLOSIONTYPE_BULLETHOLE && g_Explosions[i].age > maxage) {
				maxage = g_Explosions[i].age;
				index = i;
			}
		}

		if (index >= 0) {
			propExecuteTickOperation(g_Explosions[index].prop, TICKOP_FREE);
			g_Explosions[index].prop = NULL;
			exp = &g_Explosions[index];
		}
	}

	if (exp) {
		struct prop *expprop = propAllocate();

		if (type != EXPLOSIONTYPE_16 && type != EXPLOSIONTYPE_BULLETHOLE) {
			g_ExplosionShakeTotalTimer = 6;
		}

		if (expprop) {
			s32 exproom;
			f32 value1;
			f32 value2;
			s32 k;
			s32 index;
			s32 portalnum;
			s32 indexplus1;
			s32 indexplus2;
			struct coord portalbbmin;
			struct coord portalbbmax;
			struct coord portal2bbmin;
			struct coord portal2bbmax;
			struct coord spd4;
			struct coord spc8;
			s16 otherroom;
			s16 otherroom2;
			f32 mult = 1;
			s32 stack4;
			s32 portalnum2;
			struct coord spac;
			u32 stack2;
			u32 stack3;
			s32 j;

			expprop->type = PROPTYPE_EXPLOSION;
			expprop->explosion = exp;
			expprop->pos.x = exppos->x;
			expprop->pos.y = exppos->y;
			expprop->pos.z = exppos->z;

			for (i = 0; exprooms[i] != -1 && i < 7; i++) {
				expprop->rooms[i] = exprooms[i];

				roomAdjustLighting(exprooms[i], g_ExplosionTypes[type].rangeh, 255);
			}

			expprop->rooms[i] = -1;

			propActivateThisFrame(expprop);
			propEnable(expprop);

			exp->type = type;
			exp->prop = expprop;
			exp->source = sourceprop;
			exp->age = 0;
			exp->makescorch = makescorch;
			exp->owner = playernum;

			if (type != EXPLOSIONTYPE_BULLETHOLE && type != EXPLOSIONTYPE_PHOENIX) {
				propSetDangerous(expprop);
			}

			exproom = expprop->rooms[0];

			explosionGetBboxAtFrame(&spd4, &spc8, g_ExplosionTypes[type].duration, expprop);

			spd4.x *= mult;
			spd4.y *= mult;
			spd4.z *= mult;

			spc8.x *= mult;
			spc8.y *= mult;
			spc8.z *= mult;

			exp->bbs[0].bbmin.x = g_Rooms[exproom].bbmin[0];
			exp->bbs[0].bbmin.y = g_Rooms[exproom].bbmin[1];
			exp->bbs[0].bbmin.z = g_Rooms[exproom].bbmin[2];
			exp->bbs[0].bbmax.x = g_Rooms[exproom].bbmax[0];
			exp->bbs[0].bbmax.y = g_Rooms[exproom].bbmax[1];
			exp->bbs[0].bbmax.z = g_Rooms[exproom].bbmax[2];
			exp->bbs[0].room = exproom;
			exp->bbs[0].room2 = -1;
			exp->numbb = 1;

			if (exp->type == EXPLOSIONTYPE_HUGE25) {
				exp->numbb = 0;
			} else {
				exp->bbs[0].bbmin.x = g_Rooms[exproom].bbmin[0];
				exp->bbs[0].bbmin.y = g_Rooms[exproom].bbmin[1];
				exp->bbs[0].bbmin.z = g_Rooms[exproom].bbmin[2];
				exp->bbs[0].bbmax.x = g_Rooms[exproom].bbmax[0];
				exp->bbs[0].bbmax.y = g_Rooms[exproom].bbmax[1];
				exp->bbs[0].bbmax.z = g_Rooms[exproom].bbmax[2];
				exp->bbs[0].room = exproom;
				exp->bbs[0].room2 = -1;
				exp->numbb = 1;

				for (k = 0; k < g_Rooms[exproom].numportals; k++) {
					portalnum = g_RoomPortals[g_Rooms[exproom].roomportallistoffset + k];

					portalFindBbox(portalnum, &portalbbmin, &portalbbmax);

					if (func0f164f9c(&portalbbmin, &portalbbmax, &spd4, &spc8)) {
						otherroom2 = -1;
						index = 0;

						if (exproom == g_BgPortals[portalnum].roomnum1) {
							otherroom = g_BgPortals[portalnum].roomnum2;
						} else {
							otherroom = g_BgPortals[portalnum].roomnum1;
						}

						spac.f[0] = (var800a4ccc + portalnum)->coord.f[0];
						spac.f[1] = (var800a4ccc + portalnum)->coord.f[1];
						spac.f[2] = (var800a4ccc + portalnum)->coord.f[2];

						if (spac.f[0] < 0.0f) {
							spac.f[0] = -spac.f[0];
						}

						if (spac.f[1] < 0.0f) {
							spac.f[1] = -spac.f[1];
						}

						if (spac.f[2] < 0.0f) {
							spac.f[2] = -spac.f[2];
						}

						if (spac.f[0] < spac.f[1]) {
							index = 1;
						}

						if (spac.f[index] < spac.f[2]) {
							index = 2;
						}

						indexplus1 = (index + 1) % 3;
						indexplus2 = (index + 2) % 3;

						value1 = portalbbmax.f[indexplus1] - portalbbmin.f[indexplus1];
						value2 = portalbbmax.f[indexplus2] - portalbbmin.f[indexplus2];

						if (value2 < value1) {
							value1 = value2;
						}

						portalbbmin.f[index] -= value1;
						portalbbmax.f[index] += value1;

						if (portalbbmin.f[index] < g_Rooms[exproom].bbmin[index]) {
							portalbbmin.f[index] = g_Rooms[exproom].bbmin[index];
						}

						if (portalbbmax.f[index] > g_Rooms[exproom].bbmax[index]) {
							portalbbmax.f[index] = g_Rooms[exproom].bbmax[index];
						}

						if (portalbbmin.f[index] > g_Rooms[otherroom].bbmin[index]) {
							portalbbmin.f[index] = g_Rooms[otherroom].bbmin[index];
						}

						if (portalbbmax.f[index] < g_Rooms[otherroom].bbmax[index]) {
							portalbbmax.f[index] = g_Rooms[otherroom].bbmax[index];
						}

						for (j = 0; j < g_Rooms[otherroom].numportals; j++) {
							portalnum2 = g_RoomPortals[g_Rooms[otherroom].roomportallistoffset + j];

							if (portalnum2 != portalnum) {
								portalFindBbox(portalnum2, &portal2bbmin, &portal2bbmax);

								if (portal2bbmin.f[indexplus1] <= portalbbmin.f[indexplus1] + 10.0f * mult
										&& portal2bbmin.f[indexplus2] <= portalbbmin.f[indexplus2] + 10.0f * mult
										&& portal2bbmax.f[indexplus1] >= portalbbmax.f[indexplus1] - 10.0f * mult
										&& portal2bbmax.f[indexplus2] >= portalbbmax.f[indexplus2] - 10.0f * mult) {
									if (otherroom == g_BgPortals[portalnum2].roomnum1) {
										otherroom2 = g_BgPortals[portalnum2].roomnum2;
									} else {
										otherroom2 = g_BgPortals[portalnum2].roomnum1;
									}

									if (portalbbmin.f[index] > g_Rooms[otherroom2].bbmin[index]) {
										portalbbmin.f[index] = g_Rooms[otherroom2].bbmin[index];
									}

									if (portalbbmax.f[index] < g_Rooms[otherroom2].bbmax[index]) {
										portalbbmax.f[index] = g_Rooms[otherroom2].bbmax[index];
									}
									break;
								}
							}
						}

						portalbbmin.f[0] *= mult;
						portalbbmin.f[1] *= mult;
						portalbbmin.f[2] *= mult;

						portalbbmax.f[0] *= mult;
						portalbbmax.f[1] *= mult;
						portalbbmax.f[2] *= mult;

						exp->bbs[exp->numbb].bbmin.x = portalbbmin.f[0];
						exp->bbs[exp->numbb].bbmin.y = portalbbmin.f[1];
						exp->bbs[exp->numbb].bbmin.z = portalbbmin.f[2];
						exp->bbs[exp->numbb].bbmax.x = portalbbmax.f[0];
						exp->bbs[exp->numbb].bbmax.y = portalbbmax.f[1];
						exp->bbs[exp->numbb].bbmax.z = portalbbmax.f[2];
						exp->bbs[exp->numbb].room = otherroom;
						exp->bbs[exp->numbb].room2 = otherroom2;

						exp->numbb++;

						if (exp->numbb >= 5) {
							break;
						}
					}
				}

				exp->bbs[0].bbmin.x *= mult;
				exp->bbs[0].bbmin.y *= mult;
				exp->bbs[0].bbmin.z *= mult;
				exp->bbs[0].bbmax.x *= mult;
				exp->bbs[0].bbmax.y *= mult;
				exp->bbs[0].bbmax.z *= mult;
			}

			if (makescorch) {
				exp->unk3d0.x = arg6->x;
				exp->unk3d0.y = arg6->y;
				exp->unk3d0.z = arg6->z;
				exp->room = room;
				exp->unk3dc.x = arg8->x;
				exp->unk3dc.y = arg8->y;
				exp->unk3dc.z = arg8->z;
			} else {
				exp->unk3d0.x = 999999.875f;
			}

			exp->parts[0].frame = 1;
			exp->parts[0].pos.x = exppos->x;
			exp->parts[0].pos.y = exppos->y;
			exp->parts[0].pos.z = exppos->z;
			exp->parts[0].size = g_ExplosionTypes[type].innersize * (RANDOMFRAC() * 0.5f + 1);
			exp->parts[0].rot = RANDOMFRAC() * M_BADTAU;
			exp->parts[0].bb = 0;

			if (g_Vars.mplayerisrunning) {
				smokeClearSomeTypes();
			}

			explosionAlertChrs(&g_ExplosionTypes[type].rangeh, exppos);
		}
	}

	return exp != NULL;
}

/**
 * Start a shake without any explosion.
 *
 * This function is unused.
 */
void explosionShake(void)
{
	g_ExplosionShakeTotalTimer = 6;
	g_ExplosionShakeIntensityTimer = 6;
}

void explosionsUpdateShake(struct coord *arg0, struct coord *arg1, struct coord *arg2)
{
	u32 stack[4];
	f32 sp54;
	f32 sp50;
	s32 i;
	f32 intensity;

	if (g_ExplosionShakeTotalTimer == 0) {
		viShake(0);
		return;
	}

	sp54 = cosf(0.8f) * arg1->f[0] - sinf(0.8f) * arg1->f[2];
	sp50 = sinf(0.8f) * arg1->f[0] + cosf(0.8f) * arg1->f[2];

	intensity = 0.0f;

	for (i = 0; i < g_MaxExplosions; i++) {
		struct prop *prop = g_Explosions[i].prop;

		if (prop) {
			f32 xdiff = prop->pos.x - arg0->x;
			f32 ydiff = prop->pos.y - arg0->y;
			f32 zdiff = prop->pos.z - arg0->z;

			f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
			f32 mult;

			if (dist == 0.0f) {
				dist = 0.0001f;
			}

			mult = g_ExplosionTypes[g_Explosions[i].type].innersize / dist;

			intensity += mult * 15.0f;
		}
	}

	if (g_ExplosionShakeIntensityTimer > 0) {
		g_ExplosionShakeIntensityTimer--;
		intensity++;
	}

	g_ExplosionShakeTotalTimer--;

	if (g_ExplosionShakeTotalTimer & 2) {
		arg2->y = intensity;
		intensity = -intensity;
	} else {
		arg2->y = -intensity;
	}

	arg2->x = intensity * sp54;
	arg2->z = intensity * sp50;

	viShake(g_ExplosionShakeTotalTimer * intensity);
}

/**
 * Check if a prop is either fully or partially overlapping the given explosion.
 *
 * minpos and maxpos are the bounding boxes of the prop.
 */
bool explosionOverlapsProp(struct explosion *exp, struct prop *prop, struct coord *minpos, struct coord *maxpos)
{
	bool result = false;
	s32 i;
	s16 rooms[8];

	if (exp->type == EXPLOSIONTYPE_HUGE25) {
		result = true;
	} else {
		for (i = 0; i < exp->numbb; i++) {
			rooms[0] = exp->bbs[i].room;

			if (exp->bbs[i].room2 != -1) {
				rooms[1] = exp->bbs[i].room2;
			} else {
				rooms[1] = -1;
			}

			rooms[2] = -1;

			if (arrayIntersects(prop->rooms, rooms)
					&& minpos->x <= exp->bbs[i].bbmax.x
					&& minpos->y <= exp->bbs[i].bbmax.y
					&& minpos->z <= exp->bbs[i].bbmax.z
					&& maxpos->x >= exp->bbs[i].bbmin.x
					&& maxpos->y >= exp->bbs[i].bbmin.y
					&& maxpos->z >= exp->bbs[i].bbmin.z) {
				result = true;
				break;
			}
		}
	}

	return result;
}

void explosionInflictDamage(struct prop *expprop)
{
	s32 stack;
	struct explosion *exp = expprop->explosion;
	struct explosiontype *type = &g_ExplosionTypes[exp->type];
	s16 *propnumptr;
	s16 propnums[256];
	bool isfirstframe = exp->age <= 0;
	s32 i;
	f32 k;
	s32 j;
	f32 damageradius;

	if (g_Vars.lvupdate240_60 <= 0) {
		return;
	}

	if (type->damage <= 0.0f) {
		return;
	}

	if (isfirstframe) {
		damageradius = type->damageradius;
	} else {
#if PAL
		damageradius = type->blastradius + (type->damageradius - type->blastradius) * exp->age / (type->duration * 0.8333333f);
#else
		damageradius = type->blastradius + (type->damageradius - type->blastradius) * exp->age / type->duration;
#endif

		if (damageradius > type->damageradius) {
			damageradius = type->damageradius;
		}
	}

#if PAL
	if (exp->age > (s32)((type->duration + 7.0f * type->flarespeed) * 0.8333333f)) {
		return;
	}
#else
	if (exp->age > (s32)(type->duration + 7.0f * type->flarespeed)) {
		return;
	}
#endif

	// Flicker room lighting
	for (i = 0; expprop->rooms[i] != -1; i++) {
		if (random() % 2048 <= 240) {
			roomAdjustLighting(expprop->rooms[i], type->rangeh, 255);
		}
	}

	// Break lights
	for (i = 0; expprop->rooms[i] != -1; i++) {
		s32 roomnum = expprop->rooms[i];

		if (roomnum != 0) {
			s32 numlights = g_Rooms[roomnum].numlights;
			f32 xdist = expprop->pos.f[0];
			f32 ydist = expprop->pos.f[1];
			f32 zdist = expprop->pos.f[2];
			struct coord sp164;

			xdist -= g_BgRooms[roomnum].pos.f[0];
			ydist -= g_BgRooms[roomnum].pos.f[1];
			zdist -= g_BgRooms[roomnum].pos.f[2];

			for (j = 0; j < numlights; j++) {
				if (lightIsHealthy(roomnum, j)
						&& lightIsVulnerable(roomnum, j)
						&& lightGetBboxCentre(roomnum, j, &sp164)) {
					struct coord sp158;
					struct coord sp14c;

					sp14c.f[0] = sp164.f[0] - xdist; \
					sp14c.f[1] = sp164.f[1] - ydist; \
					sp14c.f[2] = sp164.f[2] - zdist;

					sp158.f[0] = damageradius;
					sp158.f[1] = damageradius;
					sp158.f[2] = damageradius;

					if (func0f1773c8(&sp14c, &sp158)) {
						roomSetLightBroken(roomnum, j);
					}
				}
			}
		}
	}

	// Damage props
	roomGetProps(expprop->rooms, propnums, 256);

	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop != exp->source && prop->timetoregen == 0) {
			if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
				f32 xdist;
				f32 ydist;
				f32 zdist;
				struct coord sp130;
				struct coord sp124;
				struct defaultobj *obj = prop->obj;
				bool candamage = false;

				xdist = prop->pos.x - expprop->pos.x;
				ydist = prop->pos.y - expprop->pos.y;
				zdist = prop->pos.z - expprop->pos.z;

				if (candamage);

#if VERSION >= VERSION_NTSC_1_0
				if (obj)
#endif
				{
					if (xdist <= damageradius && xdist >= -damageradius
							&& ydist <= damageradius && ydist >= -damageradius
							&& zdist <= damageradius && zdist >= -damageradius) {

						if (setup0f092304(obj, &sp130, &sp124)) {
							if (explosionOverlapsProp(exp, prop, &sp130, &sp124)) {
								candamage = true;
							}
						} else {
							candamage = true;
						}
					}

					if (candamage && prop->type == PROPTYPE_WEAPON) {
						struct weaponobj *weapon = prop->weapon;

						if (weapon && weapon->weaponnum == WEAPON_SKROCKET) {
							weapon->timer240 = 0;
						}
					}

					if (candamage) {
						f32 f0;
						f32 xfrac;
						f32 yfrac;
						f32 zfrac;
						f32 minfrac;

						xfrac = f0 = xdist / damageradius;

						if (xfrac < 0.0f) {
							xfrac = -xfrac;
						}

						xfrac = 1.0f - xfrac;

						yfrac = f0 = ydist / damageradius;

						if (yfrac < 0.0f) {
							yfrac = -yfrac;
						}

						yfrac = 1.0f - yfrac;

						zfrac = f0 = zdist / damageradius;

						if (zfrac < 0.0f) {
							zfrac = -zfrac;
						}

						zfrac = 1.0f - zfrac;

						minfrac = xfrac;

						if (yfrac < minfrac) {
							minfrac = yfrac;
						}

						if (zfrac < minfrac) {
							minfrac = zfrac;
						}

						minfrac = (minfrac * 0.7f + 0.3f) * type->damage;

						if (g_Vars.antiplayernum >= 0
								&& g_Vars.antiplayernum == exp->owner
								&& (obj->flags2 & OBJFLAG2_IMMUNETOANTI)) {
							// anti cannot damage this obj
						} else if (isfirstframe) {
							// Unblock path if this object is a path blocker
							objUpdateLinkedScenery(obj, expprop);

							// Damage the object
							if ((obj->hidden & OBJHFLAG_00001000) == 0
									&& (obj->flags2 & (OBJFLAG2_LINKEDTOSAFE | OBJFLAG2_00200000)) == 0) {
								func0f085050(prop, (RANDOMFRAC() * 0.5f + 1.0f) * minfrac, &prop->pos, 0x22, exp->owner);
							}

							// Give object momentum if it's a hover obj
							if ((obj->hidden & OBJHFLAG_MOUNTED) == 0
									&& (obj->hidden & OBJHFLAG_GRABBED) == 0
									&& (obj->flags3 & OBJFLAG3_PUSHABLE)) {
								f32 dist;
								struct coord spf4;
								spf4.x = prop->pos.x - expprop->pos.x;
								spf4.y = 0.0f;
								spf4.z = prop->pos.z - expprop->pos.z;

								if (spf4.f[0] != 0.0f || spf4.f[2] != 0.0f) {
									dist = sqrtf(spf4.f[0] * spf4.f[0] + spf4.f[2] * spf4.f[2]);

									if (dist > 0.0f) {
										f32 tmp = minfrac * 4.0f / dist;
										spf4.x *= tmp;
										spf4.z *= tmp;
									}
								}

								objApplyMomentum(obj, &spf4, 0.0f, true, true);
							}
						} else if (objIsHealthy(obj)) {
							// Sustained damage
							minfrac *= 0.05f * g_Vars.lvupdate240freal;

							if ((obj->hidden & OBJHFLAG_00001000) == 0
									&& (obj->flags2 & (OBJFLAG2_LINKEDTOSAFE | OBJFLAG2_00200000)) == 0) {
								func0f085050(prop, (RANDOMFRAC() * 0.5f + 1.0f) * minfrac,
										&prop->pos, 0x22, exp->owner);
							}
						}
					}
				}
			} else if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
				f32 xdist = prop->pos.f[0] - expprop->pos.f[0];
				f32 ydist = prop->pos.f[1] - expprop->pos.f[1];
				f32 zdist = prop->pos.f[2] - expprop->pos.f[2];
				f32 width;
				f32 ymax;
				f32 ymin;
				struct coord spcc;
				struct coord spc0;

				bool candamage = false;

				if (prop->type == PROPTYPE_CHR);

				if (xdist <= damageradius && xdist >= -damageradius
						&& ydist <= damageradius && ydist >= -damageradius
						&& zdist <= damageradius && zdist >= -damageradius) {
					propGetBbox(prop, &width, &ymax, &ymin);

					width -= 20.0f;

					if (width <= 0.0f) {
						width = 0.0f;
					}

					spcc.f[0] = prop->pos.f[0] - width;
					spcc.f[1] = ymin;
					spcc.f[2] = prop->pos.f[2] - width;

					spc0.f[0] = prop->pos.f[0] + width;
					spc0.f[1] = ymax;
					spc0.f[2] = prop->pos.f[2] + width;

					if (explosionOverlapsProp(exp, prop, &spcc, &spc0)) {
						candamage = true;
					}
				}

				if (candamage) {
					struct prop *ownerprop = NULL;
					f32 xfrac = xdist / damageradius;
					f32 yfrac = ydist / damageradius;
					f32 zfrac = zdist / damageradius;
					struct coord spa0 = {0, 0, 0};
					struct chrdata *chr = prop->chr;
					f32 minfrac;

					if (xfrac < 0.0f) {
						xfrac = -xfrac;
					}

					if (yfrac < 0.0f) {
						yfrac = -yfrac;
					}

					if (zfrac < 0.0f) {
						zfrac = -zfrac;
					}

					xfrac = 1.0f - xfrac;
					yfrac = 1.0f - yfrac;
					zfrac = 1.0f - zfrac;

					minfrac = xfrac;

					if (yfrac < minfrac) {
						minfrac = yfrac;
					}

					if (zfrac < minfrac) {
						minfrac = zfrac;
					}

					minfrac *= minfrac;
					minfrac = minfrac * type->damage * 8.0f;

					if (isfirstframe) {
						if (xdist != 0.0f || zdist != 0.0f) {
							f32 dist = sqrtf(xdist * xdist + zdist * zdist);

							if (dist > 0.0f) {
								xdist *= 1.0f / dist;
								zdist *= 1.0f / dist;

								spa0.x = xdist;
								spa0.y = 0.0f;
								spa0.z = zdist;
							}
						}
					} else {
						minfrac *= 0.05f * g_Vars.lvupdate240freal;
					}

					if (g_Vars.normmplayerisrunning) {
						struct chrdata *ownerchr = mpGetChrFromPlayerIndex(exp->owner);

						if (ownerchr) {
							ownerprop = ownerchr->prop;
						}
					} else if (exp->owner == g_Vars.bondplayernum) {
						ownerprop = g_Vars.bond->prop;
					} else if (g_Vars.coopplayernum >= 0 && exp->owner == g_Vars.coopplayernum) {
						ownerprop = g_Vars.coop->prop;
					} else if (g_Vars.antiplayernum >= 0 && exp->owner == g_Vars.antiplayernum) {
						ownerprop = g_Vars.anti->prop;
					}

					chrDamageByExplosion(chr, minfrac, &spa0, ownerprop, &expprop->pos);

					if (prop->type == PROPTYPE_CHR && !isfirstframe) {
						chrDisfigure(chr, &expprop->pos, damageradius);
					}
				}
			}
		}

		propnumptr++;
	}
}

u32 explosionTick(struct prop *prop)
{
	struct explosion *exp = prop->explosion;
	struct explosiontype *type = &g_ExplosionTypes[exp->type];
	s32 i;
	s32 j;
	s32 k;
	f32 hrange;
	f32 vrange;
	f32 lvupdate;
	struct coord bbmin;
	struct coord bbmax;
	s16 maxage;
	s32 numpartstocreate;
	struct coord sp11c;
	struct coord sp110;
	u32 stack[2];
	struct coord spfc;
	struct coord spf0;
	s32 bb;
	bool s3;
	struct chrdata *chr;
	f32 scorchsize;
	struct hitthing spb0;

	maxage = TICKS(type->duration);

	if (g_Vars.lvupdate240_60 == 0) {
		return TICKOP_NONE;
	}

	lvupdate = g_Vars.lvupdate240_60 < TICKS(15) ? g_Vars.lvupdate240_60 : (s32)TICKS(15);

#if PAL
	if (exp->age >= 7 && exp->age < maxage)
#else
	if (exp->age >= 8 && exp->age < maxage)
#endif
	{
		hrange = explosionGetHorizontalRangeAtFrame(exp, exp->age);
		vrange = explosionGetVerticalRangeAtFrame(exp, exp->age);

		sp11c.x = prop->pos.x - hrange * 0.5f;
		sp11c.y = prop->pos.y - vrange * 0.5f;
		sp11c.z = prop->pos.z - hrange * 0.5f;

		sp110.x = prop->pos.x + hrange * 0.5f;
		sp110.y = prop->pos.y + vrange * 0.5f;
		sp110.z = prop->pos.z + hrange * 0.5f;

		// Barrel explosions ascend upwards
		if (exp->type == EXPLOSIONTYPE_GASBARREL && exp->age < TICKS(32)) {
			prop->pos.y += PALUPF(10.0f) * lvupdate;
		}

		// Create new parts
		numpartstocreate = (s32)((f32)type->propagationrate * exp->age / maxage) + 1;

		for (i = 0; i < numpartstocreate; i++) {
			for (j = 0; j < 40; j++) {
				if (exp->parts[j].frame == 0) {
					if (exp->numbb == 0 || exp->type == EXPLOSIONTYPE_HUGE25) {
						spfc.f[0] = sp11c.f[0];
						spfc.f[1] = sp11c.f[1];
						spfc.f[2] = sp11c.f[2];

						spf0.f[0] = sp110.f[0];
						spf0.f[1] = sp110.f[1];
						spf0.f[2] = sp110.f[2];

						bb = 0;
					} else {
						bb = j % exp->numbb;

						spfc.x = exp->bbs[bb].bbmin.x;
						spfc.y = exp->bbs[bb].bbmin.y;
						spfc.z = exp->bbs[bb].bbmin.z;

						spf0.x = exp->bbs[bb].bbmax.x;
						spf0.y = exp->bbs[bb].bbmax.y;
						spf0.z = exp->bbs[bb].bbmax.z;

						if (spfc.x < sp11c.x) {
							spfc.x = sp11c.x;
						}

						if (spfc.y < sp11c.y) {
							spfc.y = sp11c.y;
						}

						if (spfc.z < sp11c.z) {
							spfc.z = sp11c.z;
						}

						if (sp110.x < spf0.x) {
							spf0.x = sp110.x;
						}

						if (sp110.y < spf0.y) {
							spf0.y = sp110.y;
						}

						if (sp110.z < spf0.z) {
							spf0.z = sp110.z;
						}

						if (spf0.x <= spfc.x || spf0.y <= spfc.y || spf0.z <= spfc.z) {
							bb = 0;

							spfc.x = exp->bbs[bb].bbmin.x;
							spfc.y = exp->bbs[bb].bbmin.y;
							spfc.z = exp->bbs[bb].bbmin.z;

							spf0.x = exp->bbs[bb].bbmax.x;
							spf0.y = exp->bbs[bb].bbmax.y;
							spf0.z = exp->bbs[bb].bbmax.z;

							if (spfc.x < sp11c.x) {
								spfc.x = sp11c.x;
							}

							if (spfc.y < sp11c.y) {
								spfc.y = sp11c.y;
							}

							if (spfc.z < sp11c.z) {
								spfc.z = sp11c.z;
							}

							if (sp110.x < spf0.x) {
								spf0.x = sp110.x;
							}

							if (sp110.y < spf0.y) {
								spf0.y = sp110.y;
							}

							if (sp110.z < spf0.z) {
								spf0.z = sp110.z;
							}
						}
					}

					exp->parts[j].pos.f[0] = spfc.f[0] + RANDOMFRAC() * (spf0.f[0] - spfc.f[0]);
					exp->parts[j].pos.f[1] = spfc.f[1] + RANDOMFRAC() * (spf0.f[1] - spfc.f[1]);
					exp->parts[j].pos.f[2] = spfc.f[2] + RANDOMFRAC() * (spf0.f[2] - spfc.f[2]);
					exp->parts[j].bb = bb;
					exp->parts[j].frame = 1;
					exp->parts[j].size = (1.0f + RANDOMFRAC() * 0.5f) * type->innersize;
					exp->parts[j].rot = RANDOMFRAC() * M_BADTAU;
					break;
				}
			}
		}
	}

	explosionGetBboxAtFrame(&bbmin, &bbmax, exp->age, prop);
	func0f1650d0(&bbmin, &bbmax, prop->rooms, 7, 0);
	explosionInflictDamage(prop);

	// Play boom sound if this is the first frame
	if (exp->age == 0) {
		propsnd0f0939f8(NULL, NULL, type->sound, -1, -1, 0, 0, 0, &exp->prop->pos, -1.0f, exp->prop->rooms, -1, -1.0f, -1.0f, -1.0f);
	}

	for (k = 0; k < (s32)lvupdate; k++) {
		exp->age++;

		for (j = 0; j < 40; j++) {
			if (exp->parts[j].frame > 0) {
				exp->parts[j].frame++;
			}
		}

		// Create smoke
		if (((exp->age == TICKS(15) && exp->type == EXPLOSIONTYPE_GASBARREL)
					|| (exp->age == maxage - TICKS(20) && exp->type != EXPLOSIONTYPE_GASBARREL))
				&& (exp->type != EXPLOSIONTYPE_BULLETHOLE || (random() % 2) == 0)) {
			if (exp->source) {
				smokeCreateSimple(&exp->source->pos, exp->source->rooms, type->smoketype);
			} else {
				smokeCreateSimple(&prop->pos, prop->rooms, type->smoketype);
			}
		}

		// Make scorch at half duration
		if (exp->age == (maxage >> 1) && exp->makescorch) {
			s3 = false;
			scorchsize = 2.0f * type->innersize;

			if (scorchsize > 100.0f) {
				scorchsize = 100.0f;
			}

			scorchsize *= 0.8f + 0.2f * RANDOMFRAC();

			if (g_Vars.normmplayerisrunning) {
				chr = mpGetChrFromPlayerIndex(exp->owner);
			} else if (g_Vars.antiplayernum >= 0 && exp->owner == g_Vars.antiplayernum) {
				chr = g_Vars.anti->prop->chr;
			} else if (g_Vars.coopplayernum >= 0 && exp->owner == g_Vars.coopplayernum) {
				chr = g_Vars.coop->prop->chr;
			} else {
				chr = g_Vars.bond->prop->chr;
			}

			if (g_Rooms[exp->room].gfxdata) {
				// Not 100% sure about spb0 being a struct hitthing, but it's likely
				if (g_Rooms[exp->room].gfxdata->unk0c && func0f161520(&prop->pos, &exp->unk3d0, exp->room, &spb0)) {
					s3 = spb0.unk2c == 2;
				}

				func0f13f504(&exp->unk3d0, &exp->unk3dc, &prop->pos, 0, 0, 7, exp->room, 0, 0, -1, 0, chr, scorchsize, scorchsize, 0xff, 0xff, 0, 0, 0, s3);
			}
		}
	}

	// Free explosion if finished
#if PAL
	if (exp->age >= maxage + (s32)((16.0f * type->flarespeed) * 0.8333333f))
#else
	if (exp->age >= maxage + (s32)(16.0f * type->flarespeed))
#endif
	{
		if (exp->type != EXPLOSIONTYPE_BULLETHOLE) {
			propUnsetDangerous(exp->prop);
		}

		exp->prop = NULL;
		return TICKOP_FREE;
	}

	return TICKOP_NONE;
}

u32 explosionTickPlayer(struct prop *prop)
{
	Mtxf *matrix = camGetMatrix1740();

	prop->z = -(matrix->m[0][2] * prop->pos.x + matrix->m[1][2] * prop->pos.y + matrix->m[2][2] * prop->pos.z + matrix->m[3][2]);

	if (prop->z < 100) {
		prop->z *= 0.5f;
	} else {
		prop->z -= 100;
	}

	prop->flags |= PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONTHISSCREENTHISTICK;

	return TICKOP_NONE;
}

Gfx *explosionRender(struct prop *prop, Gfx *gdl, bool withalpha)
{
	struct explosion *exp = prop->explosion;
	s32 roomnum;
	s32 i;
	s32 j;

	if (!withalpha) {
		return gdl;
	}

	j = 0;
	roomnum = prop->rooms[j];

	while (roomnum != -1) {
		if (g_Rooms[roomnum].gfxdata
				&& g_Rooms[roomnum].loaded240
				&& (g_Rooms[roomnum].flags & ROOMFLAG_VISIBLEBYPLAYER)) {
			break;
		}

		j++;
		roomnum = prop->rooms[j];
	}

	if (roomnum != -1) {
		struct screenbox screenbox;
		struct coord *coord = room0f166dd0(roomnum);
		u32 *colour;
		s32 tmp;

		if (func0f08e5a8(prop->rooms, &screenbox) > 0) {
			gdl = currentPlayerScissorWithinViewport(gdl, screenbox.xmin, screenbox.ymin, screenbox.xmax, screenbox.ymax);
		} else {
			gdl = currentPlayerScissorToViewport(gdl);
		}

		gSPClearGeometryMode(gdl++, G_CULL_BOTH | G_FOG);
		gSPMatrix(gdl++, osVirtualToPhysical(camGetUnk1758()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		gdl = room0f166d7c(gdl, roomnum);

		gSPDisplayList(gdl++, g_TexGdl2);

		colour = gfxAllocateColours(1);

		if (USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) {
			*colour = 0xffffffff;
		} else if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
			u32 alpha = 0x80;
			u32 red;
			u32 green;
			f32 expdist = sqrtf(ERASERSQDIST(prop->pos.f));

			if (g_Vars.currentplayer->eraserpropdist < expdist) {
				return gdl;
			}

			if (g_Vars.currentplayer->eraserpropdist - 150.0f < expdist) {
				alpha = (1.0f - (expdist - (g_Vars.currentplayer->eraserpropdist - 150.0f)) / 150.0f) * 128.0f;
			}

			expdist = expdist / g_Vars.currentplayer->eraserpropdist;

			if (expdist > 1.0f) {
				expdist = 1.0f;
			}

			red = expdist * 127.0f;
			green = (1.0f - expdist) * 127.0f;

			*colour = red << 24 | green << 16 | alpha | 0x80800000;
		} else {
			static u32 var8007e93c = 0xffffffff;
			mainOverrideVariable("ecol", &var8007e93c);
			*colour = 0xffffffff;
			*colour = var8007e93c;
		}

		gDPSetColorArray(gdl++, osVirtualToPhysical(colour), 1);

		for (i = 14; i >= 0; i--) {
			gDPSetTextureImage(gdl++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, g_ExplosionTexturePairs[i].texturenum1);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, 1567, 0);

			gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, g_ExplosionTexturePairs[i].texturenum2);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, 223, 0);

			gDPPipeSync(gdl++);

			for (j = 0; j < ARRAYCOUNT(exp->parts); j++) {
				if (exp->parts[j].frame > 0) {
#if PAL
					if (i == (s32)((f32)(exp->parts[j].frame - 1) / (g_ExplosionTypes[exp->type].flarespeed * 0.83333331346512f))) {
						gdl = explosionRenderPart(exp, &exp->parts[j], gdl, coord, i);
					}
#else
					if (i == (s32)((f32)(exp->parts[j].frame - 1) / g_ExplosionTypes[exp->type].flarespeed)) {
						gdl = explosionRenderPart(exp, &exp->parts[j], gdl, coord, i);
					}
#endif
				}
			}
		}

		gSPMatrix(gdl++, osVirtualToPhysical(camGetUnk1750()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

#if PAL
		tmp = (g_ExplosionTypes[exp->type].flarespeed * 15.0f) * 0.83333331346512f;
#else
		tmp = g_ExplosionTypes[exp->type].flarespeed * 15.0f;
#endif

		for (j = 0; j < ARRAYCOUNT(exp->parts); j++) {
			if (exp->parts[j].frame > tmp) {
				exp->parts[j].frame = 0;
			}
		}
	}

	return gdl;
}

GLOBAL_ASM(
glabel explosionRenderPart
.late_rodata
glabel var7f1b55ac
.word 0x3f333333
glabel var7f1b55b0
.word 0x3f266666
glabel var7f1b55b4
.word 0x3f4ccccd
glabel var7f1b55b8
.word 0x3f16db6e
glabel var7f1b55bc
.word 0x3f324925
glabel var7f1b55c0
.word 0x3f524925
glabel var7f1b55c4
.word 0x3f76db6e
.text
/*  f12cd64:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f12cd68:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f12cd6c:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f12cd70:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*  f12cd74:	00a08825 */ 	or	$s1,$a1,$zero
/*  f12cd78:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f12cd7c:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f12cd80:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f12cd84:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f12cd88:	afa600d8 */ 	sw	$a2,0xd8($sp)
/*  f12cd8c:	afa700dc */ 	sw	$a3,0xdc($sp)
/*  f12cd90:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f12cd94:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f12cd98:	0fc2d5de */ 	jal	camGetUnk174c
/*  f12cd9c:	00408025 */ 	or	$s0,$v0,$zero
/*  f12cda0:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*  f12cda4:	00405825 */ 	or	$t3,$v0,$zero
/*  f12cda8:	c636000c */ 	lwc1	$f22,0xc($s1)
/*  f12cdac:	914e03cf */ 	lbu	$t6,0x3cf($t2)
/*  f12cdb0:	c62e0000 */ 	lwc1	$f14,0x0($s1)
/*  f12cdb4:	c6300004 */ 	lwc1	$f16,0x4($s1)
/*  f12cdb8:	19c000b4 */ 	blez	$t6,.L0f12d08c
/*  f12cdbc:	c6320008 */ 	lwc1	$f18,0x8($s1)
/*  f12cdc0:	e7ae0068 */ 	swc1	$f14,0x68($sp)
/*  f12cdc4:	e7b0006c */ 	swc1	$f16,0x6c($sp)
/*  f12cdc8:	e7b20070 */ 	swc1	$f18,0x70($sp)
/*  f12cdcc:	914803cf */ 	lbu	$t0,0x3cf($t2)
/*  f12cdd0:	4480c000 */ 	mtc1	$zero,$f24
/*  f12cdd4:	92290016 */ 	lbu	$t1,0x16($s1)
/*  f12cdd8:	00003825 */ 	or	$a3,$zero,$zero
/*  f12cddc:	19000043 */ 	blez	$t0,.L0f12ceec
/*  f12cde0:	4600c506 */ 	mov.s	$f20,$f24
/*  f12cde4:	01403025 */ 	or	$a2,$t2,$zero
/*  f12cde8:	27a50074 */ 	addiu	$a1,$sp,0x74
.L0f12cdec:
/*  f12cdec:	c4c403e8 */ 	lwc1	$f4,0x3e8($a2)
/*  f12cdf0:	460e203e */ 	c.le.s	$f4,$f14
/*  f12cdf4:	00000000 */ 	nop
/*  f12cdf8:	45020039 */ 	bc1fl	.L0f12cee0
/*  f12cdfc:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce00:	c4c603f4 */ 	lwc1	$f6,0x3f4($a2)
/*  f12ce04:	4606703e */ 	c.le.s	$f14,$f6
/*  f12ce08:	00000000 */ 	nop
/*  f12ce0c:	45020034 */ 	bc1fl	.L0f12cee0
/*  f12ce10:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce14:	c4c803ec */ 	lwc1	$f8,0x3ec($a2)
/*  f12ce18:	4610403e */ 	c.le.s	$f8,$f16
/*  f12ce1c:	00000000 */ 	nop
/*  f12ce20:	4502002f */ 	bc1fl	.L0f12cee0
/*  f12ce24:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce28:	c4ca03f8 */ 	lwc1	$f10,0x3f8($a2)
/*  f12ce2c:	460a803e */ 	c.le.s	$f16,$f10
/*  f12ce30:	00000000 */ 	nop
/*  f12ce34:	4502002a */ 	bc1fl	.L0f12cee0
/*  f12ce38:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce3c:	c4c403f0 */ 	lwc1	$f4,0x3f0($a2)
/*  f12ce40:	4612203e */ 	c.le.s	$f4,$f18
/*  f12ce44:	00000000 */ 	nop
/*  f12ce48:	45020025 */ 	bc1fl	.L0f12cee0
/*  f12ce4c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce50:	c4c603fc */ 	lwc1	$f6,0x3fc($a2)
/*  f12ce54:	000778c0 */ 	sll	$t7,$a3,0x3
/*  f12ce58:	01e77823 */ 	subu	$t7,$t7,$a3
/*  f12ce5c:	4606903e */ 	c.le.s	$f18,$f6
/*  f12ce60:	3c014780 */ 	lui	$at,0x4780
/*  f12ce64:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12ce68:	27a20068 */ 	addiu	$v0,$sp,0x68
/*  f12ce6c:	4502001c */ 	bc1fl	.L0f12cee0
/*  f12ce70:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce74:	44816000 */ 	mtc1	$at,$f12
/*  f12ce78:	014f1821 */ 	addu	$v1,$t2,$t7
.L0f12ce7c:
/*  f12ce7c:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f12ce80:	c46803e8 */ 	lwc1	$f8,0x3e8($v1)
/*  f12ce84:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f12ce88:	46081001 */ 	sub.s	$f0,$f2,$f8
/*  f12ce8c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f12ce90:	00000000 */ 	nop
/*  f12ce94:	45020003 */ 	bc1fl	.L0f12cea4
/*  f12ce98:	c46a03f4 */ 	lwc1	$f10,0x3f4($v1)
/*  f12ce9c:	46000306 */ 	mov.s	$f12,$f0
/*  f12cea0:	c46a03f4 */ 	lwc1	$f10,0x3f4($v1)
.L0f12cea4:
/*  f12cea4:	46025001 */ 	sub.s	$f0,$f10,$f2
/*  f12cea8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f12ceac:	00000000 */ 	nop
/*  f12ceb0:	45000002 */ 	bc1f	.L0f12cebc
/*  f12ceb4:	00000000 */ 	nop
/*  f12ceb8:	46000306 */ 	mov.s	$f12,$f0
.L0f12cebc:
/*  f12cebc:	1445ffef */ 	bne	$v0,$a1,.L0f12ce7c
/*  f12cec0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12cec4:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f12cec8:	00000000 */ 	nop
/*  f12cecc:	45020004 */ 	bc1fl	.L0f12cee0
/*  f12ced0:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ced4:	46006506 */ 	mov.s	$f20,$f12
/*  f12ced8:	00e04825 */ 	or	$t1,$a3,$zero
/*  f12cedc:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f12cee0:
/*  f12cee0:	00e8082a */ 	slt	$at,$a3,$t0
/*  f12cee4:	1420ffc1 */ 	bnez	$at,.L0f12cdec
/*  f12cee8:	24c6001c */ 	addiu	$a2,$a2,0x1c
.L0f12ceec:
/*  f12ceec:	3c017f1b */ 	lui	$at,%hi(var7f1b55ac)
/*  f12cef0:	c42c55ac */ 	lwc1	$f12,%lo(var7f1b55ac)($at)
/*  f12cef4:	0009c0c0 */ 	sll	$t8,$t1,0x3
/*  f12cef8:	0309c023 */ 	subu	$t8,$t8,$t1
/*  f12cefc:	460cb082 */ 	mul.s	$f2,$f22,$f12
/*  f12cf00:	3c017f1b */ 	lui	$at,%hi(var7f1b55b0)
/*  f12cf04:	c43255b0 */ 	lwc1	$f18,%lo(var7f1b55b0)($at)
/*  f12cf08:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f12cf0c:	01582021 */ 	addu	$a0,$t2,$t8
/*  f12cf10:	3c017f1b */ 	lui	$at,%hi(var7f1b55b4)
/*  f12cf14:	c42e55b4 */ 	lwc1	$f14,%lo(var7f1b55b4)($at)
/*  f12cf18:	46001406 */ 	mov.s	$f16,$f2
/*  f12cf1c:	00801825 */ 	or	$v1,$a0,$zero
/*  f12cf20:	00001025 */ 	or	$v0,$zero,$zero
.L0f12cf24:
/*  f12cf24:	c46403f4 */ 	lwc1	$f4,0x3f4($v1)
/*  f12cf28:	c46603e8 */ 	lwc1	$f6,0x3e8($v1)
/*  f12cf2c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f12cf30:	2841000c */ 	slti	$at,$v0,0xc
/*  f12cf34:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12cf38:	460e4002 */ 	mul.s	$f0,$f8,$f14
/*  f12cf3c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f12cf40:	00000000 */ 	nop
/*  f12cf44:	4500000b */ 	bc1f	.L0f12cf74
/*  f12cf48:	00000000 */ 	nop
/*  f12cf4c:	460c0583 */ 	div.s	$f22,$f0,$f12
/*  f12cf50:	c62a000c */ 	lwc1	$f10,0xc($s1)
/*  f12cf54:	46125082 */ 	mul.s	$f2,$f10,$f18
/*  f12cf58:	4602b03c */ 	c.lt.s	$f22,$f2
/*  f12cf5c:	00000000 */ 	nop
/*  f12cf60:	45000002 */ 	bc1f	.L0f12cf6c
/*  f12cf64:	00000000 */ 	nop
/*  f12cf68:	46001586 */ 	mov.s	$f22,$f2
.L0f12cf6c:
/*  f12cf6c:	460cb082 */ 	mul.s	$f2,$f22,$f12
/*  f12cf70:	46001406 */ 	mov.s	$f16,$f2
.L0f12cf74:
/*  f12cf74:	1420ffeb */ 	bnez	$at,.L0f12cf24
/*  f12cf78:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12cf7c:	8fa200e0 */ 	lw	$v0,0xe0($sp)
/*  f12cf80:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12cf84:	00801825 */ 	or	$v1,$a0,$zero
/*  f12cf88:	14410006 */ 	bne	$v0,$at,.L0f12cfa4
/*  f12cf8c:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f12cf90:	3c017f1b */ 	lui	$at,%hi(var7f1b55b8)
/*  f12cf94:	c42455b8 */ 	lwc1	$f4,%lo(var7f1b55b8)($at)
/*  f12cf98:	46041402 */ 	mul.s	$f16,$f2,$f4
/*  f12cf9c:	10000016 */ 	b	.L0f12cff8
/*  f12cfa0:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cfa4:
/*  f12cfa4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f12cfa8:	14410005 */ 	bne	$v0,$at,.L0f12cfc0
/*  f12cfac:	3c017f1b */ 	lui	$at,%hi(var7f1b55bc)
/*  f12cfb0:	c42655bc */ 	lwc1	$f6,%lo(var7f1b55bc)($at)
/*  f12cfb4:	46061402 */ 	mul.s	$f16,$f2,$f6
/*  f12cfb8:	1000000f */ 	b	.L0f12cff8
/*  f12cfbc:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cfc0:
/*  f12cfc0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f12cfc4:	14410006 */ 	bne	$v0,$at,.L0f12cfe0
/*  f12cfc8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f12cfcc:	3c017f1b */ 	lui	$at,%hi(var7f1b55c0)
/*  f12cfd0:	c42855c0 */ 	lwc1	$f8,%lo(var7f1b55c0)($at)
/*  f12cfd4:	46081402 */ 	mul.s	$f16,$f2,$f8
/*  f12cfd8:	10000007 */ 	b	.L0f12cff8
/*  f12cfdc:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cfe0:
/*  f12cfe0:	14450004 */ 	bne	$v0,$a1,.L0f12cff4
/*  f12cfe4:	3c017f1b */ 	lui	$at,%hi(var7f1b55c4)
/*  f12cfe8:	c42a55c4 */ 	lwc1	$f10,%lo(var7f1b55c4)($at)
/*  f12cfec:	460a1402 */ 	mul.s	$f16,$f2,$f10
/*  f12cff0:	00000000 */ 	nop
.L0f12cff4:
/*  f12cff4:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cff8:
/*  f12cff8:	44819000 */ 	mtc1	$at,$f18
/*  f12cffc:	27a20068 */ 	addiu	$v0,$sp,0x68
.L0f12d000:
/*  f12d000:	c46c03f4 */ 	lwc1	$f12,0x3f4($v1)
/*  f12d004:	c46e03e8 */ 	lwc1	$f14,0x3e8($v1)
/*  f12d008:	460e6101 */ 	sub.s	$f4,$f12,$f14
/*  f12d00c:	4610203c */ 	c.lt.s	$f4,$f16
/*  f12d010:	00000000 */ 	nop
/*  f12d014:	45020006 */ 	bc1fl	.L0f12d030
/*  f12d018:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f12d01c:	460c7180 */ 	add.s	$f6,$f14,$f12
/*  f12d020:	46123202 */ 	mul.s	$f8,$f6,$f18
/*  f12d024:	10000013 */ 	b	.L0f12d074
/*  f12d028:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f12d02c:	46107280 */ 	add.s	$f10,$f14,$f16
.L0f12d030:
/*  f12d030:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f12d034:	46025001 */ 	sub.s	$f0,$f10,$f2
/*  f12d038:	4600c03c */ 	c.lt.s	$f24,$f0
/*  f12d03c:	00000000 */ 	nop
/*  f12d040:	45020005 */ 	bc1fl	.L0f12d058
/*  f12d044:	46106181 */ 	sub.s	$f6,$f12,$f16
/*  f12d048:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f12d04c:	10000009 */ 	b	.L0f12d074
/*  f12d050:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f12d054:	46106181 */ 	sub.s	$f6,$f12,$f16
.L0f12d058:
/*  f12d058:	46061001 */ 	sub.s	$f0,$f2,$f6
/*  f12d05c:	4600c03c */ 	c.lt.s	$f24,$f0
/*  f12d060:	00000000 */ 	nop
/*  f12d064:	45020004 */ 	bc1fl	.L0f12d078
/*  f12d068:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f12d06c:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f12d070:	e4480000 */ 	swc1	$f8,0x0($v0)
.L0f12d074:
/*  f12d074:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f12d078:
/*  f12d078:	1444ffe1 */ 	bne	$v0,$a0,.L0f12d000
/*  f12d07c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12d080:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f12d084:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f12d088:	c7b20070 */ 	lwc1	$f18,0x70($sp)
.L0f12d08c:
/*  f12d08c:	c62c0010 */ 	lwc1	$f12,0x10($s1)
/*  f12d090:	e7b2008c */ 	swc1	$f18,0x8c($sp)
/*  f12d094:	e7b00090 */ 	swc1	$f16,0x90($sp)
/*  f12d098:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f12d09c:	0c0068f4 */ 	jal	cosf
/*  f12d0a0:	afab00c8 */ 	sw	$t3,0xc8($sp)
/*  f12d0a4:	46160502 */ 	mul.s	$f20,$f0,$f22
/*  f12d0a8:	0c0068f7 */ 	jal	sinf
/*  f12d0ac:	c62c0010 */ 	lwc1	$f12,0x10($s1)
/*  f12d0b0:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f12d0b4:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f12d0b8:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f12d0bc:	c56a0000 */ 	lwc1	$f10,0x0($t3)
/*  f12d0c0:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f12d0c4:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f12d0c8:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d0cc:	240306e0 */ 	addiu	$v1,$zero,0x6e0
/*  f12d0d0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f12d0d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f12d0d8:	02001025 */ 	or	$v0,$s0,$zero
/*  f12d0dc:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f12d0e0:	c5660004 */ 	lwc1	$f6,0x4($t3)
/*  f12d0e4:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f12d0e8:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f12d0ec:	c56a0008 */ 	lwc1	$f10,0x8($t3)
/*  f12d0f0:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d0f4:	e7a400c4 */ 	swc1	$f4,0xc4($sp)
/*  f12d0f8:	46160082 */ 	mul.s	$f2,$f0,$f22
/*  f12d0fc:	c5660000 */ 	lwc1	$f6,0x0($t3)
/*  f12d100:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d104:	e7a800b0 */ 	swc1	$f8,0xb0($sp)
/*  f12d108:	c56a0004 */ 	lwc1	$f10,0x4($t3)
/*  f12d10c:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f12d110:	e7a400b4 */ 	swc1	$f4,0xb4($sp)
/*  f12d114:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f12d118:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d11c:	e7a800b8 */ 	swc1	$f8,0xb8($sp)
/*  f12d120:	c56a0010 */ 	lwc1	$f10,0x10($t3)
/*  f12d124:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d128:	e7a400a4 */ 	swc1	$f4,0xa4($sp)
/*  f12d12c:	c5660014 */ 	lwc1	$f6,0x14($t3)
/*  f12d130:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f12d134:	e7a800a8 */ 	swc1	$f8,0xa8($sp)
/*  f12d138:	c56a0018 */ 	lwc1	$f10,0x18($t3)
/*  f12d13c:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d140:	e7a400ac */ 	swc1	$f4,0xac($sp)
/*  f12d144:	c5660010 */ 	lwc1	$f6,0x10($t3)
/*  f12d148:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d14c:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f12d150:	c56a0014 */ 	lwc1	$f10,0x14($t3)
/*  f12d154:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f12d158:	c7aa00bc */ 	lwc1	$f10,0xbc($sp)
/*  f12d15c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f12d160:	c5660018 */ 	lwc1	$f6,0x18($t3)
/*  f12d164:	460a7101 */ 	sub.s	$f4,$f14,$f10
/*  f12d168:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d16c:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f12d170:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f12d174:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d178:	c58a0000 */ 	lwc1	$f10,0x0($t4)
/*  f12d17c:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d180:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f12d184:	440d3000 */ 	mfc1	$t5,$f6
/*  f12d188:	00000000 */ 	nop
/*  f12d18c:	a60d0000 */ 	sh	$t5,0x0($s0)
/*  f12d190:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f12d194:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f12d198:	46088281 */ 	sub.s	$f10,$f16,$f8
/*  f12d19c:	c5880004 */ 	lwc1	$f8,0x4($t4)
/*  f12d1a0:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d1a4:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d1a8:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f12d1ac:	440f2000 */ 	mfc1	$t7,$f4
/*  f12d1b0:	00000000 */ 	nop
/*  f12d1b4:	a60f0002 */ 	sh	$t7,0x2($s0)
/*  f12d1b8:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f12d1bc:	c7aa00a0 */ 	lwc1	$f10,0xa0($sp)
/*  f12d1c0:	46069201 */ 	sub.s	$f8,$f18,$f6
/*  f12d1c4:	c5860008 */ 	lwc1	$f6,0x8($t4)
/*  f12d1c8:	a6030008 */ 	sh	$v1,0x8($s0)
/*  f12d1cc:	a600000a */ 	sh	$zero,0xa($s0)
/*  f12d1d0:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d1d4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d1d8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f12d1dc:	44195000 */ 	mfc1	$t9,$f10
/*  f12d1e0:	00000000 */ 	nop
/*  f12d1e4:	a6190004 */ 	sh	$t9,0x4($s0)
/*  f12d1e8:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f12d1ec:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f12d1f0:	46047180 */ 	add.s	$f6,$f14,$f4
/*  f12d1f4:	c5840000 */ 	lwc1	$f4,0x0($t4)
/*  f12d1f8:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d1fc:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d200:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12d204:	440e4000 */ 	mfc1	$t6,$f8
/*  f12d208:	00000000 */ 	nop
/*  f12d20c:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f12d210:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f12d214:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f12d218:	460a8100 */ 	add.s	$f4,$f16,$f10
/*  f12d21c:	c58a0004 */ 	lwc1	$f10,0x4($t4)
/*  f12d220:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d224:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d228:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f12d22c:	44183000 */ 	mfc1	$t8,$f6
/*  f12d230:	00000000 */ 	nop
/*  f12d234:	a618000e */ 	sh	$t8,0xe($s0)
/*  f12d238:	c7a800b8 */ 	lwc1	$f8,0xb8($sp)
/*  f12d23c:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f12d240:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f12d244:	c5880008 */ 	lwc1	$f8,0x8($t4)
/*  f12d248:	a6000014 */ 	sh	$zero,0x14($s0)
/*  f12d24c:	a6000016 */ 	sh	$zero,0x16($s0)
/*  f12d250:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d254:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d258:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f12d25c:	440d2000 */ 	mfc1	$t5,$f4
/*  f12d260:	00000000 */ 	nop
/*  f12d264:	a60d0010 */ 	sh	$t5,0x10($s0)
/*  f12d268:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f12d26c:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f12d270:	46067200 */ 	add.s	$f8,$f14,$f6
/*  f12d274:	c5860000 */ 	lwc1	$f6,0x0($t4)
/*  f12d278:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f12d27c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d280:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f12d284:	440f5000 */ 	mfc1	$t7,$f10
/*  f12d288:	00000000 */ 	nop
/*  f12d28c:	a60f0018 */ 	sh	$t7,0x18($s0)
/*  f12d290:	c7a400c0 */ 	lwc1	$f4,0xc0($sp)
/*  f12d294:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f12d298:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f12d29c:	c5840004 */ 	lwc1	$f4,0x4($t4)
/*  f12d2a0:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f12d2a4:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d2a8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12d2ac:	44194000 */ 	mfc1	$t9,$f8
/*  f12d2b0:	00000000 */ 	nop
/*  f12d2b4:	a619001a */ 	sh	$t9,0x1a($s0)
/*  f12d2b8:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f12d2bc:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*  f12d2c0:	460a9100 */ 	add.s	$f4,$f18,$f10
/*  f12d2c4:	c58a0008 */ 	lwc1	$f10,0x8($t4)
/*  f12d2c8:	a6000020 */ 	sh	$zero,0x20($s0)
/*  f12d2cc:	a6030022 */ 	sh	$v1,0x22($s0)
/*  f12d2d0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f12d2d4:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d2d8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f12d2dc:	440e3000 */ 	mfc1	$t6,$f6
/*  f12d2e0:	00000000 */ 	nop
/*  f12d2e4:	a60e001c */ 	sh	$t6,0x1c($s0)
/*  f12d2e8:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f12d2ec:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*  f12d2f0:	46087281 */ 	sub.s	$f10,$f14,$f8
/*  f12d2f4:	c5880000 */ 	lwc1	$f8,0x0($t4)
/*  f12d2f8:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f12d2fc:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d300:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f12d304:	44182000 */ 	mfc1	$t8,$f4
/*  f12d308:	00000000 */ 	nop
/*  f12d30c:	a6180024 */ 	sh	$t8,0x24($s0)
/*  f12d310:	c7a600b4 */ 	lwc1	$f6,0xb4($sp)
/*  f12d314:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f12d318:	3c180430 */ 	lui	$t8,0x430
/*  f12d31c:	46068201 */ 	sub.s	$f8,$f16,$f6
/*  f12d320:	c5860004 */ 	lwc1	$f6,0x4($t4)
/*  f12d324:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f12d328:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d32c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f12d330:	440d5000 */ 	mfc1	$t5,$f10
/*  f12d334:	00000000 */ 	nop
/*  f12d338:	a60d0026 */ 	sh	$t5,0x26($s0)
/*  f12d33c:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f12d340:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f12d344:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f12d348:	c5840008 */ 	lwc1	$f4,0x8($t4)
/*  f12d34c:	a603002c */ 	sh	$v1,0x2c($s0)
/*  f12d350:	a603002e */ 	sh	$v1,0x2e($s0)
/*  f12d354:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f12d358:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d35c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12d360:	440f4000 */ 	mfc1	$t7,$f8
/*  f12d364:	00000000 */ 	nop
/*  f12d368:	a60f0028 */ 	sh	$t7,0x28($s0)
.L0f12d36c:
/*  f12d36c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f12d370:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f12d374:	1485fffd */ 	bne	$a0,$a1,.L0f12d36c
/*  f12d378:	a040fffb */ 	sb	$zero,-0x5($v0)
/*  f12d37c:	8fa200d8 */ 	lw	$v0,0xd8($sp)
/*  f12d380:	37180030 */ 	ori	$t8,$t8,0x30
/*  f12d384:	02002025 */ 	or	$a0,$s0,$zero
/*  f12d388:	00402825 */ 	or	$a1,$v0,$zero
/*  f12d38c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f12d390:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f12d394:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f12d398:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12d39c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f12d3a0:	8fa300d8 */ 	lw	$v1,0xd8($sp)
/*  f12d3a4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f12d3a8:	3c19b100 */ 	lui	$t9,0xb100
/*  f12d3ac:	37390032 */ 	ori	$t9,$t9,0x32
/*  f12d3b0:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f12d3b4:	240d2010 */ 	addiu	$t5,$zero,0x2010
/*  f12d3b8:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f12d3bc:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f12d3c0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f12d3c4:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f12d3c8:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f12d3cc:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f12d3d0:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f12d3d4:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f12d3d8:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
/*  f12d3dc:	03e00008 */ 	jr	$ra
/*  f12d3e0:	24620008 */ 	addiu	$v0,$v1,0x8
);
