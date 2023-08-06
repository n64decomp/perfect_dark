#include <ultra64.h>
#include "constants.h"
#include "game/bondgrab.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/prop.h"
#include "game/objectives.h"
#include "game/bondgun.h"
#include "game/player.h"
#include "game/bondhead.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "data.h"
#include "types.h"

struct prop *var8009de70;
u32 var8009de74;
struct coord var8009de78;
u32 var8009de84;
u32 var8009de88;
u32 var8009de8c;

bool var80070e80 = false;

void bgrabInit(void)
{
	s32 prevmode = g_Vars.currentplayer->bondmovemode;
	Mtxf matrix;
	struct prop *prop = g_Vars.currentplayer->grabbedprop;

	g_Vars.currentplayer->bondmovemode = MOVEMODE_GRAB;

	g_Vars.currentplayer->bondgrabthetaspeedsum = 0;
	g_Vars.currentplayer->grabbedprevpos.x = prop->pos.x;
	g_Vars.currentplayer->grabbedprevpos.y = prop->pos.y;
	g_Vars.currentplayer->grabbedprevpos.z = prop->pos.z;
	g_Vars.currentplayer->grabbedrotoffset = 0;
	g_Vars.currentplayer->grabbedforcez = 0;
	g_Vars.currentplayer->grabbedposoffset.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->grabbedposoffset.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
	g_Vars.currentplayer->grabbedposoffset.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;
	g_Vars.currentplayer->grabbeddoextra = false;
	g_Vars.currentplayer->grabbedrotextra = 0;
	g_Vars.currentplayer->grabbedposextra.x = 0;
	g_Vars.currentplayer->grabbedposextra.y = 0;
	g_Vars.currentplayer->grabbedposextra.z = 0;
	g_Vars.currentplayer->grabbedrotextrasum = 0;
	g_Vars.currentplayer->grabbedposextrasum.x = 0;
	g_Vars.currentplayer->grabbedposextrasum.y = 0;
	g_Vars.currentplayer->grabbedposextrasum.z = 0;
	g_Vars.currentplayer->guncloseroffset = 0;
	g_Vars.currentplayer->gunextraaimx = 0;
	g_Vars.currentplayer->gunextraaimy = 0;

	mtx4LoadYRotation((g_Vars.currentplayer->vv_theta * M_BADTAU) / 360.0f, &matrix);
	mtx4RotateVecInPlace(&matrix, &g_Vars.currentplayer->grabbedposoffset);

	g_Vars.currentplayer->bondprevtheta = g_Vars.currentplayer->vv_theta;

	if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_DOOR || prop->type == PROPTYPE_WEAPON) {
		struct defaultobj *obj = prop->obj;
		struct hov *hov = NULL;
		s32 cdresult;

		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			struct projectile *projectile = obj->projectile;
			g_Vars.currentplayer->bondshotspeed.x += projectile->speed.x * 0.2f;
			g_Vars.currentplayer->bondshotspeed.z += projectile->speed.z * 0.2f;
			objFreeProjectile(obj);
		}

		if (obj->type == OBJTYPE_HOVERPROP) {
			struct hoverpropobj *hoverprop = (struct hoverpropobj *)prop->obj;
			hov = &hoverprop->hov;
		} else if (obj->type == OBJTYPE_HOVERBIKE) {
			struct hoverbikeobj *hoverprop = (struct hoverbikeobj *)prop->obj;
			hov = &hoverprop->hov;
		}

		if (hov) {
			g_Vars.currentplayer->grabbedrotoffset =
				hov->yrot - (M_BADTAU - (g_Vars.currentplayer->vv_theta * M_BADTAU) / 360.0f);

			if (g_Vars.currentplayer->grabbedrotoffset >= M_BADTAU) {
				g_Vars.currentplayer->grabbedrotoffset -= M_BADTAU;
			} else if (g_Vars.currentplayer->grabbedrotoffset < 0) {
				g_Vars.currentplayer->grabbedrotoffset += M_BADTAU;
			}
		}

		obj->hidden |= OBJHFLAG_GRABBED;

		if (obj->flags3 & OBJFLAG3_GEOCYL) {
			cdresult = cd000276c8Cyl(obj->geocyl,
					g_Vars.currentplayer->prop->pos.x,
					g_Vars.currentplayer->prop->pos.z,
					VERSION >= VERSION_NTSC_1_0 ? 45 : 40, 0, 0);
		} else {
			cdresult = cd000274e0Block(obj->geoblock,
					g_Vars.currentplayer->prop->pos.x,
					g_Vars.currentplayer->prop->pos.z,
					VERSION >= VERSION_NTSC_1_0 ? 45 : 40, 0, 0);
		}

		if (cdresult != CDRESULT_COLLISION) {
			g_Vars.currentplayer->grabbedforcez = VERSION >= VERSION_NTSC_1_0 ? 15 : 10;
		}
	}

	if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		s32 i;

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
		g_Vars.currentplayer->moveinitspeed.x = 0;
		g_Vars.currentplayer->moveinitspeed.y = 0;
		g_Vars.currentplayer->moveinitspeed.z = 0;
	}

	g_Vars.currentplayer->grabstarttime = g_Vars.lvframe60;
}

void bgrabExit(void)
{
	struct coord moveamount;
	struct defaultobj *obj;
	f32 rotateamount;

	if (g_Vars.currentplayer->grabbedprop) {
		struct defaultobj *obj = g_Vars.currentplayer->grabbedprop->obj;
		obj->hidden &= ~OBJHFLAG_GRABBED;

		if (g_Vars.lvupdate240 > 0) {
			moveamount.x = (g_Vars.currentplayer->grabbedprop->pos.x - g_Vars.currentplayer->grabbedprevpos.x) / g_Vars.lvupdate60freal;
			moveamount.y = 0;
			moveamount.z = (g_Vars.currentplayer->grabbedprop->pos.z - g_Vars.currentplayer->grabbedprevpos.z) / g_Vars.lvupdate60freal;

			rotateamount = -(g_Vars.currentplayer->vv_theta - g_Vars.currentplayer->bondprevtheta)
				* M_BADTAU / 360;

			if (rotateamount < -M_PI) {
				rotateamount += M_BADTAU;
			} else if (rotateamount >= M_PI) {
				rotateamount -= M_BADTAU;
			}

			rotateamount /= g_Vars.lvupdate60freal;

			objApplyMomentum(g_Vars.currentplayer->grabbedprop->obj, &moveamount,
					rotateamount, 0, 0);
		}

		g_Vars.currentplayer->grabbedprop = NULL;
	}
}

void bgrab0f0ccbf0(struct coord *delta, f32 angle, struct defaultobj *obj)
{
	struct coord spd4;
	struct coord spc8;
	struct coord spbc;
	struct coord spb0;
	struct coord spa4;
	struct coord sp98;

	if (g_Vars.lvupdate240 > 0) {
		if (var8009de70->type == PROPTYPE_PLAYER) {
			sp98.x = delta->x + g_Vars.currentplayer->prop->pos.x;
			sp98.y = g_Vars.currentplayer->prop->pos.y;
			sp98.z = delta->z + g_Vars.currentplayer->prop->pos.z;

#if VERSION >= VERSION_NTSC_1_0
			cdGetEdge(&spb0, &spa4, 201, "bondgrab.c");
#else
			cdGetEdge(&spb0, &spa4, 200, "bondgrab.c");
#endif

			spc8.x = spa4.z - spb0.z;
			spc8.y = 0.0f;
			spc8.z = spb0.x - spa4.x;

			if (spc8.f[0] != 0.0f || spc8.f[2] != 0.0f) {
				guNormalize(&spc8.x, &spc8.y, &spc8.z);
			} else {
				spc8.z = 1.0f;
			}

			func0f02e3dc(&spb0, &spa4, &sp98, &spc8, &spd4);

			spbc.x = (sp98.x - g_Vars.currentplayer->prop->pos.x) / g_Vars.lvupdate60freal;
			spbc.y = 0.0f;
			spbc.z = (sp98.z - g_Vars.currentplayer->prop->pos.z) / g_Vars.lvupdate60freal;

			func0f082e84(obj, &spd4, &spc8, &spbc, false);
		} else {
			struct coord sp8c;
			struct coord sp80;
			struct coord sp74 = {0, 0, 0};
			struct coord sp68;
			struct coord sp5c;
			struct coord sp50;
			struct coord sp44;

#if VERSION >= VERSION_NTSC_1_0
			cdGetEdge(&sp68, &sp5c, 228, "bondgrab.c");
#else
			cdGetEdge(&sp68, &sp5c, 227, "bondgrab.c");
#endif

			if (cdGetSavedPos(&sp50, &sp44)) {
				sp44.x -= sp50.x;
				sp44.y -= sp50.y;
				sp44.z -= sp50.z;
			} else {
				sp50.x = var8009de70->pos.x;
				sp50.y = var8009de70->pos.y;
				sp50.z = var8009de70->pos.z;

				sp44.x = obj->prop->pos.x - var8009de70->pos.x;
				sp44.y = obj->prop->pos.y - var8009de70->pos.y;
				sp44.z = obj->prop->pos.z - var8009de70->pos.z;
			}

			func0f02e3dc(&sp68, &sp5c, &sp50, &sp44, &sp8c);

			sp80.x = delta->x;
			sp80.y = 0.0f;
			sp80.z = delta->z;

			if (sp80.f[0] != 0.0f || sp80.f[2] != 0.0f) {
				guNormalize(&sp80.x, &sp80.y, &sp80.z);
			} else {
				sp80.z = 1.0f;
			}

			if (delta->x != 0.0f) {
				sp74.x += delta->x / g_Vars.lvupdate60freal;
			}

			if (delta->z != 0.0f) {
				sp74.z += delta->z / g_Vars.lvupdate60freal;
			}

			func0f082e84(obj, &sp8c, &sp80, &sp74, false);

			if (angle != 0.0f) {
				f32 sp40 = sp8c.x - g_Vars.currentplayer->prop->pos.x;
				f32 sp3c = sp8c.z - g_Vars.currentplayer->prop->pos.z;
				f32 rotation = 0.0f;
				struct coord sp2c = {0, 0, 0};
				f32 mult = 1.0f / sqrtf(sp40 * sp40 + sp3c * sp3c);

				sp40 *= mult;
				sp3c *= mult;
				angle = angle / g_Vars.lvupdate60freal;

				sp2c.x += -sp3c * angle * 40.0f;
				sp2c.z += sp40 * angle * 40.0f;

				rotation += angle * 0.1f;

				objApplyMomentum(obj, &sp2c, rotation, true, true);
			}
		}
	}
}

bool bgrabTryMoveUpwards(f32 y)
{
	bool result;
	struct coord newpos;
	RoomNum rooms[8];
	f32 ymax;
	f32 ymin;
	f32 radius;

	newpos.x = g_Vars.currentplayer->prop->pos.x;
	newpos.y = g_Vars.currentplayer->prop->pos.y + y;
	newpos.z = g_Vars.currentplayer->prop->pos.z;

	playerGetBbox(g_Vars.currentplayer->prop, &radius, &ymax, &ymin);
	func0f065e74(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &newpos, rooms);
	bmoveFindEnteredRoomsByPos(g_Vars.currentplayer, &newpos, rooms);
	propSetPerimEnabled(g_Vars.currentplayer->prop, false);

	ymin -= 0.1f;

	result = cdTestVolume(&newpos, radius, rooms, CDTYPE_ALL, CHECKVERTICAL_YES,
			ymax - g_Vars.currentplayer->prop->pos.y,
			ymin - g_Vars.currentplayer->prop->pos.y);

	propSetPerimEnabled(g_Vars.currentplayer->prop, true);

	if (result == CDRESULT_NOCOLLISION) {
		g_Vars.currentplayer->prop->pos.y = newpos.y;
		propDeregisterRooms(g_Vars.currentplayer->prop);
		roomsCopy(rooms, g_Vars.currentplayer->prop->rooms);
	}

	return result;
}

s32 bgrabCalculateNewPosition(struct coord *delta, f32 angle, bool arg2)
{
	s32 cdresult = CDRESULT_NOCOLLISION;
	s32 i;
	struct coord pos;
	RoomNum rooms[8];
	bool ismoving = false;
	f32 ymax;
	f32 ymin;
	f32 radius;
	f32 rotextrasum;
	struct coord posextrasum;
	f32 rotextra;
	struct coord posextra;
	struct defaultobj *obj;
	struct hov *hov;
	struct coord sp88;

	var80070e80 = 0;

	playerGetBbox(g_Vars.currentplayer->prop, &radius, &ymax, &ymin);

	propSetPerimEnabled(g_Vars.currentplayer->prop, false);
	propSetPerimEnabled(g_Vars.currentplayer->grabbedprop, false);

	pos.x = g_Vars.currentplayer->prop->pos.x;
	pos.y = g_Vars.currentplayer->prop->pos.y;
	pos.z = g_Vars.currentplayer->prop->pos.z;

	if (delta->f[0] != 0.0f || delta->f[1] != 0.0f || delta->f[2] != 0.0f) {
		pos.x += delta->x;
		pos.y += delta->y;
		pos.z += delta->z;

		func0f065e74(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &pos, rooms);

#if VERSION < VERSION_NTSC_1_0
		{
			s32 i;

			for (i = 0; rooms[i] != -1; i++) {
				if (rooms[i] == g_Vars.currentplayer->floorroom) {
					rooms[0] = g_Vars.currentplayer->floorroom;
					rooms[1] = -1;
					break;
				}
			}
		}
#endif

		bmoveFindEnteredRoomsByPos(g_Vars.currentplayer, &pos, rooms);

		ismoving = true;

		cdresult = cdExamCylMove05(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms,
				&pos, rooms, CDTYPE_ALL, true,
				ymax - g_Vars.currentplayer->prop->pos.y,
				ymin - g_Vars.currentplayer->prop->pos.y);

		if (cdresult == CDRESULT_NOCOLLISION) {
			cdresult = cdExamCylMove01(&g_Vars.currentplayer->prop->pos, &pos, radius, rooms, CDTYPE_ALL, CHECKVERTICAL_YES,
					ymax - g_Vars.currentplayer->prop->pos.y,
					ymin - g_Vars.currentplayer->prop->pos.y);
		}

		if (cdresult != CDRESULT_NOCOLLISION) {
			var8009de70 = g_Vars.currentplayer->prop;
		}
	}

	propSetPerimEnabled(g_Vars.currentplayer->grabbedprop, true);

	if (cdresult == CDRESULT_NOCOLLISION) {
		struct coord sp7c;
		f32 sp78 = -angle;
		f32 sp74;
		f32 sp70;
		f32 sp6c;

		obj = g_Vars.currentplayer->grabbedprop->obj;
		hov = NULL;

		if (g_Vars.currentplayer->grabbeddoextra) {
			f32 f0 = -g_Vars.currentplayer->speedtheta * 0.017450513f * 3.5f;

			if (f0 * 6.0f * 10.0f);

			sp88.f[0] = f0 * 5.0f * 100.0f + g_Vars.currentplayer->speedsideways * 10.0f;
			sp88.f[1] = 0.0f;
			sp88.f[2] = -g_Vars.currentplayer->speedforwards * 10.0f + g_Vars.currentplayer->grabbedforcez;

			rotextrasum = g_Vars.currentplayer->grabbedrotextrasum;

			posextrasum.f[0] = g_Vars.currentplayer->grabbedposextrasum.f[0];
			posextrasum.f[1] = g_Vars.currentplayer->grabbedposextrasum.f[1];
			posextrasum.f[2] = g_Vars.currentplayer->grabbedposextrasum.f[2];

			for (i = 0; i < g_Vars.lvupdate240; i++) {
				rotextrasum = (PAL ? 0.9847f : 0.9873f) * rotextrasum + f0 * 6.0f;

				posextrasum.f[0] = (PAL ? 0.9847f : 0.9873f) * posextrasum.f[0] + sp88.f[0];
				posextrasum.f[1] = (PAL ? 0.9847f : 0.9873f) * posextrasum.f[1] + sp88.f[1];
				posextrasum.f[2] = (PAL ? 0.9847f : 0.9873f) * posextrasum.f[2] + sp88.f[2];
			}

			rotextra = rotextrasum * (PAL ? 0.01529997587204f : 0.012700021266937f);
			posextra.f[0] = posextrasum.f[0] * (PAL ? 0.01529997587204f : 0.012700021266937f);
			posextra.f[1] = posextrasum.f[1] * (PAL ? 0.01529997587204f : 0.012700021266937f);
			posextra.f[2] = posextrasum.f[2] * (PAL ? 0.01529997587204f : 0.012700021266937f);
		} else {
			rotextra = g_Vars.currentplayer->grabbedrotextra;
			posextra.f[0] = g_Vars.currentplayer->grabbedposextra.f[0];
			posextra.f[1] = g_Vars.currentplayer->grabbedposextra.f[1];
			posextra.f[2] = g_Vars.currentplayer->grabbedposextra.f[2];
		}

		sp7c.x = delta->x;
		sp7c.y = delta->y;
		sp7c.z = delta->z;

		if (obj->type == OBJTYPE_HOVERPROP) {
			struct hoverpropobj *tmp = (struct hoverpropobj *)g_Vars.currentplayer->grabbedprop->obj;
			hov = &tmp->hov;
		} else if (obj->type == OBJTYPE_HOVERBIKE) {
			struct hoverbikeobj *tmp = (struct hoverbikeobj *)g_Vars.currentplayer->grabbedprop->obj;
			hov = &tmp->hov;
		}

		if (hov != NULL) {
			sp78 = M_BADTAU
				- g_Vars.currentplayer->vv_theta * M_BADTAU / 360.0f
				+ -angle
				+ g_Vars.currentplayer->grabbedrotoffset
				- hov->yrot
				+ rotextra;

			while (sp78 >= M_PI) {
				sp78 -= M_BADTAU;
			}

			while (sp78 < -M_PI) {
				sp78 += M_BADTAU;
			}
		}

		if (angle != 0.0f || g_Vars.currentplayer->grabbeddoextra) {
			f32 f12;
			f32 f18;

			sp74 = M_BADTAU - g_Vars.currentplayer->vv_theta * M_BADTAU / 360.0f - angle;

			if (sp74 >= M_BADTAU) {
				sp74 -= M_BADTAU;
			} else if (sp74 < 0.0f) {
				sp74 += M_BADTAU;
			}

			sp70 = cosf(sp74);
			sp6c = sinf(sp74);

			f12 = g_Vars.currentplayer->grabbedposoffset.f[0] + posextra.f[0];
			f18 = g_Vars.currentplayer->grabbedposoffset.f[2] + posextra.f[2];

			sp7c.x = pos.f[0] + f12 * sp70 + f18 * sp6c - g_Vars.currentplayer->grabbedprop->pos.f[0];
			sp7c.z = pos.f[2] + f18 * sp70 - f12 * sp6c - g_Vars.currentplayer->grabbedprop->pos.f[2];
		}

		var80070e80 = true;

		var8009de78.x = g_Vars.currentplayer->grabbedprop->pos.x + sp7c.x;
		var8009de78.y = g_Vars.currentplayer->grabbedprop->pos.y + sp7c.y;
		var8009de78.z = g_Vars.currentplayer->grabbedprop->pos.z + sp7c.z;

		cdresult = func0f072144(g_Vars.currentplayer->grabbedprop->obj, &sp7c, sp78, arg2);

		if (cdresult != CDRESULT_NOCOLLISION) {
			var8009de70 = g_Vars.currentplayer->grabbedprop;
		}
	}

	propSetPerimEnabled(g_Vars.currentplayer->prop, true);

	if (cdresult == CDRESULT_NOCOLLISION) {
		var8009de70 = NULL;

		if (arg2) {
			f32 theta = g_Vars.currentplayer->vv_theta + angle * 360.0f / M_BADTAU;

			while (theta < 0.0f) {
				theta += 360.0f;
			}

			while (theta >= 360.0f) {
				theta -= 360.0f;
			}

			g_Vars.currentplayer->vv_theta = theta;

			g_Vars.currentplayer->prop->pos.x = pos.x;
			g_Vars.currentplayer->prop->pos.y = pos.y;
			g_Vars.currentplayer->prop->pos.z = pos.z;

			if (ismoving) {
				propDeregisterRooms(g_Vars.currentplayer->prop);
				roomsCopy(rooms, g_Vars.currentplayer->prop->rooms);
			}

			if (g_Vars.currentplayer->grabbeddoextra) {
				g_Vars.currentplayer->grabbedrotextra = rotextra;
				g_Vars.currentplayer->grabbedposextra.x = posextra.x;
				g_Vars.currentplayer->grabbedposextra.y = posextra.y;
				g_Vars.currentplayer->grabbedposextra.z = posextra.z;
				g_Vars.currentplayer->grabbedrotextrasum = rotextrasum;
				g_Vars.currentplayer->grabbedposextrasum.x = posextrasum.x;
				g_Vars.currentplayer->grabbedposextrasum.y = posextrasum.y;
				g_Vars.currentplayer->grabbedposextrasum.z = posextrasum.z;
			}
		}
	}

	return cdresult;
}

bool bgrabCalculateNewPositiontWithPush(struct coord *delta, f32 angle, bool arg2)
{
	s32 result = bgrabCalculateNewPosition(delta, angle, arg2);

	if (result != CDRESULT_NOCOLLISION) {
		struct prop *obstacle = cdGetObstacleProp();

		if (obstacle && g_Vars.lvupdate240 > 0) {
			if (obstacle->type == PROPTYPE_CHR) {
				// empty
			} else if (obstacle->type == PROPTYPE_PLAYER) {
				// empty
			} else if (obstacle->type == PROPTYPE_OBJ) {
				struct defaultobj *obj = obstacle->obj;

				if ((obj->hidden & OBJHFLAG_MOUNTED) == 0
						&& (obj->hidden & OBJHFLAG_GRABBED) == 0
						&& (obj->flags3 & OBJFLAG3_PUSHABLE)) {
					bool canpush = true;

					g_Vars.currentplayer->speedmaxtime60 = 0;

					if ((obj->hidden & OBJHFLAG_PROJECTILE)
							&& (obj->projectile->flags & PROJECTILEFLAG_00001000)) {
						canpush = false;
					}

					if (canpush) {
						bgrab0f0ccbf0(delta, angle, obj);

						if ((obj->hidden & OBJHFLAG_PROJECTILE)
								&& (obj->projectile->flags & PROJECTILEFLAG_SLIDING)) {
							s32 someint;
							bool embedded = false;
							someint = projectileTick(obj, &embedded);

							if ((obj->hidden & OBJHFLAG_PROJECTILE)) {
								obj->projectile->flags |= PROJECTILEFLAG_00001000;

								if (someint) {
									obj->projectile->flags |= PROJECTILEFLAG_00002000;
								} else {
									obj->projectile->flags &= ~PROJECTILEFLAG_00002000;
								}
							}

							if (someint) {
								result = bgrabCalculateNewPosition(delta, angle, arg2);
							}
						}
					}
				}
			}
		}
	}

	return result;
}

bool bgrab0f0cdb04(f32 angle, bool arg2)
{
	struct coord coord = {0, 0, 0};
	bool result;

	g_Vars.currentplayer->grabbeddoextra = true;
	result = bgrabCalculateNewPositiontWithPush(&coord, angle, arg2);
	g_Vars.currentplayer->grabbeddoextra = false;

	return result;
}

bool bgrab0f0cdb68(f32 angle)
{
	struct coord spa4;
	struct coord sp98;
	struct coord sp8c;
	struct coord sp80;
	f32 sp7c;
	f32 sp78;
	f32 f2;
	f32 f20;
	f32 f22;
	s32 i;
	f32 f0;
	f32 sp60 = -1.0f;
	struct coord sp54;
	f32 f12;
	f32 radius;
	f32 ymax;
	f32 ymin;

#if VERSION >= VERSION_NTSC_1_0
	cdGetEdge(&spa4, &sp98, 678, "bondgrab.c");
#else
	cdGetEdge(&spa4, &sp98, 674, "bondgrab.c");
#endif

	sp7c = sp98.f[0] - spa4.f[0];
	sp78 = sp98.f[2] - spa4.f[2];

	if (sp7c == 0.0f && sp78 == 0.0f) {
		sp78 = 1.0f;
	} else {
		f12 = 1.0f / sqrtf(sp7c * sp7c + sp78 * sp78);
		sp7c = sp7c * f12;
		sp78 = sp78 * f12;
	}

	f20 = sp78;
	f22 = -sp7c;

	if ((f20 * (g_Vars.currentplayer->prop->pos.x - spa4.f[0]) + f22 * (g_Vars.currentplayer->prop->pos.z - spa4.f[2])) < 0.0f) {
		f20 = -f20;
		f22 = -f22;
	}

	if (g_CdHasSavedBlock) {
		for (i = 0; i < g_CdSavedBlock.header.numvertices; i++) {
			f0 = (g_CdSavedBlock.vertices[i][0] - spa4.f[0]) * f20 + (g_CdSavedBlock.vertices[i][1] - spa4.f[2]) * f22;

			if (f0 < 0.0f) {
				f0 = -f0;

				if (f0 > sp60) {
					sp60 = f0;
				}
			}
		}
	} else {
		if (cdGetSavedPos(&sp8c, &sp80)) {
			f32 f0 = (sp8c.f[0] - spa4.f[0]) * f20 + f22 * (sp8c.f[2] - spa4.f[2]);
			f32 f16 = (sp80.f[0] - spa4.f[0]) * f20 + f22 * (sp80.f[2] - spa4.f[2]);

			if (f16 < f0) {
				f0 = f16;
			}

			if (f0 < 0.0f) {
				sp60 = -f0;
			}
		} else if (var80070e80 != 0) {
			if (g_Vars.currentplayer->grabbedprop->type == PROPTYPE_OBJ) {
				if (g_Vars.currentplayer->grabbedprop->obj->flags3 & OBJFLAG3_GEOCYL) {
					objGetBbox(g_Vars.currentplayer->grabbedprop, &radius, &ymax, &ymin);

					f0 = (var8009de78.f[0] - spa4.f[0]) * f20 + (var8009de78.f[2] - spa4.f[2]) * f22;
					f0 -= radius;

					if (f0 < 0.0f) {
						sp60 = -f0;
					}
				}
			}
		}
	}

	f2 = sinf(angle) * 400.0f;

	if (f2 < 0.0f) {
		f2 = -f2;
	}

	if (f2 < sp60) {
		sp60 = f2;
	}

	if (sp60 >= 0.0f) {
		sp54.x = sp60 * f20 * 1.01f;
		sp54.y = 0.0f;
		sp54.z = sp60 * f22 * 1.01f;

		bgrab0f0ce0bc(&sp54);

		return bgrab0f0cdb04(angle, true);
	}

	return false;
}

void bgrab0f0cdef0(void)
{
	if (g_Vars.lvupdate240 > 0) {
		f32 angle = g_Vars.currentplayer->speedtheta * g_Vars.lvupdate60freal * 0.017450513318181f * 3.5f;

		if (bgrab0f0cdb04(angle, true) == 0) {
			bgrab0f0cdb68(angle);
		}
	}
}

bool bgrab0f0cdf64(struct coord *delta, struct coord *arg1, struct coord *arg2)
{
	bool result = bgrabCalculateNewPositiontWithPush(delta, 0, true);

	if (!result) {
#if VERSION >= VERSION_NTSC_1_0
		cdGetEdge(arg1, arg2, 815, "bondgrab.c");
#else
		cdGetEdge(arg1, arg2, 811, "bondgrab.c");
#endif
	}

	return result;
}

s32 bgrab0f0cdfbc(struct coord *delta, struct coord *arg1, struct coord *arg2)
{
	if (arg1->f[0] != arg2->f[0] || arg1->f[2] != arg2->f[2]) {
		f32 tmp;
		struct coord sp30;
		struct coord sp24;

		sp30.x = arg2->x - arg1->x;
		sp30.z = arg2->z - arg1->z;

		tmp = 1.0f / sqrtf(sp30.f[0] * sp30.f[0] + sp30.f[2] * sp30.f[2]);

		sp30.x *= tmp;
		sp30.z *= tmp;

		tmp = delta->f[0] * sp30.f[0] + delta->f[2] * sp30.f[2];

		sp24.x = sp30.x * tmp;
		sp24.y = 0;
		sp24.z = sp30.z * tmp;

		return bgrabCalculateNewPositiontWithPush(&sp24, 0, true);
	}

	return -1;
}

void bgrab0f0ce0bc(struct coord *arg0)
{
	struct coord a;
	struct coord b;
	s32 value = bgrab0f0cdf64(arg0, &a, &b);

	if (value == 0) {
		value = bgrab0f0cdfbc(arg0, &a, &b);

		if (value <= 0) {
			value = 1;
		}
	}

	if (value) {
		// empty
	}
}

void bgrabUpdatePrevPos(void)
{
	g_Vars.currentplayer->bondprevpos.x = g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->bondprevpos.y = g_Vars.currentplayer->prop->pos.y;
	g_Vars.currentplayer->bondprevpos.z = g_Vars.currentplayer->prop->pos.z;

	g_Vars.currentplayer->bondprevtheta = g_Vars.currentplayer->vv_theta;

	g_Vars.currentplayer->grabbedprevpos.x = g_Vars.currentplayer->grabbedprop->pos.x;
	g_Vars.currentplayer->grabbedprevpos.y = g_Vars.currentplayer->grabbedprop->pos.y;
	g_Vars.currentplayer->grabbedprevpos.z = g_Vars.currentplayer->grabbedprop->pos.z;
}

void bgrab0f0ce178(void)
{
	func0f069c70(g_Vars.currentplayer->grabbedprop->obj, 0, 1);
}

void bgrabUpdateVertical(void)
{
	f32 stack;
	s32 i;
	f32 tmp;
	s32 inlift;
	struct prop *lift = NULL;
	f32 dist;
	f32 f14;
	f32 fVar3;
	f32 f0;

	f14 = cdFindGroundInfoAtCyl(&g_Vars.currentplayer->prop->pos,
			g_Vars.currentplayer->bond2.radius,
			g_Vars.currentplayer->prop->rooms,
			&g_Vars.currentplayer->floorcol,
			&g_Vars.currentplayer->floortype,
			&g_Vars.currentplayer->floorflags,
			&g_Vars.currentplayer->floorroom, &inlift, &lift);

	if (f14 < -30000) {
		f14 = -30000;
	}

	if (g_Vars.currentplayer->inlift && inlift) {
		if (g_Vars.currentplayer->lift == lift) {
			dist = g_Vars.currentplayer->liftground - g_Vars.currentplayer->vv_manground;

			if (dist < 1.0f && dist > -1.0f) {
				f0 = f14 - g_Vars.currentplayer->vv_ground;
				g_Vars.currentplayer->vv_ground += f0;
				g_Vars.currentplayer->vv_manground += f0;
				g_Vars.currentplayer->sumground = g_Vars.currentplayer->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);
			}
		}
	} else {
		lift = NULL;
	}

	g_Vars.currentplayer->inlift = inlift;

	if (inlift) {
		g_Vars.currentplayer->liftground = f14;
	}

	g_Vars.currentplayer->lift = lift;
	g_Vars.currentplayer->vv_ground = f14;
	g_Vars.currentplayer->vv_height =
		(g_Vars.currentplayer->headpos.y / g_Vars.currentplayer->standheight) *
		g_Vars.currentplayer->vv_eyeheight;
	fVar3 = g_Vars.currentplayer->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		fVar3 = (PAL ? 0.94559997320175f : 0.9545f) * fVar3 + g_Vars.currentplayer->vv_ground;
	}

	f0 = g_Vars.currentplayer->vv_height;

	if (f0 < 30) {
		f0 = 30;
	}

	tmp = fVar3 * (PAL ? 0.054400026798248f : 0.045499980449677f) + f0 - g_Vars.currentplayer->prop->pos.y;

#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.currentplayer->prop->pos.y + tmp < g_Vars.currentplayer->vv_ground + 10.0f) {
		tmp = g_Vars.currentplayer->vv_ground + 10.0f - g_Vars.currentplayer->prop->pos.y;
	}
#endif

	if (bgrabTryMoveUpwards(tmp)) {
		g_Vars.currentplayer->sumground = fVar3;
		g_Vars.currentplayer->vv_manground = fVar3 * (PAL ? 0.054400026798248f : 0.045499980449677f);
	}

	if ((g_Vars.currentplayer->floorflags & GEOFLAG_DIE) &&
			g_Vars.currentplayer->vv_manground - 20.0f < g_Vars.currentplayer->vv_ground) {
		playerDie(true);
	}
}

void bgrabHandleActivate(void)
{
	if (currentPlayerTryMountHoverbike(g_Vars.currentplayer->grabbedprop)) {
		g_Vars.currentplayer->bondactivateorreload = 0;
	} else {
		g_Vars.currentplayer->bondactivateorreload = 0;
		bmoveSetMode(MOVEMODE_WALK);
	}
}

void bgrabUpdateSpeedSideways(f32 targetspeed, f32 accelspeed, s32 mult)
{
	if (targetspeed < g_Vars.currentplayer->speedstrafe) {
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

void bgrabUpdateSpeedForwards(f32 target, f32 speed)
{
	if (g_Vars.currentplayer->speedgo < target) {
		g_Vars.currentplayer->speedgo += speed * g_Vars.lvupdate60freal;

		if (g_Vars.currentplayer->speedgo > target) {
			g_Vars.currentplayer->speedgo = target;
		}
	} else if (g_Vars.currentplayer->speedgo > target) {
		g_Vars.currentplayer->speedgo -= speed * g_Vars.lvupdate60freal;

		if (g_Vars.currentplayer->speedgo < target) {
			g_Vars.currentplayer->speedgo = target;
		}
	}

	g_Vars.currentplayer->speedforwards = g_Vars.currentplayer->speedgo;
}

void bgrabApplyMoveData(struct movedata *data)
{
	// Sideways
	if (data->digitalstepleft) {
		bgrabUpdateSpeedSideways(-1, 0.2f / 3.0f, data->digitalstepleft);
	} else if (data->digitalstepright) {
		bgrabUpdateSpeedSideways(1, 0.2f / 3.0f, data->digitalstepright);
	} else if (data->unk14 == 0) {
		bgrabUpdateSpeedSideways(0, 0.2f / 3.0f, g_Vars.lvupdate60);
	}

	if (data->unk14) {
		bgrabUpdateSpeedSideways(data->analogstrafe * 0.014285714365542f, 0.2f / 3.0f, g_Vars.lvupdate60);
	}

	// Forward/back
	if (data->digitalstepforward) {
		bgrabUpdateSpeedForwards(1, 0.2f / 3.0f);
		g_Vars.currentplayer->speedmaxtime60 += g_Vars.lvupdate60;
	} else if (data->digitalstepback) {
		bgrabUpdateSpeedForwards(-1, 0.2f / 3.0f);
	} else if (data->canlookahead == false) {
		bgrabUpdateSpeedForwards(0, 0.2f / 3.0f);
	}

	if (data->canlookahead) {
		bgrabUpdateSpeedForwards(data->analogwalk * 0.014285714365542f, 0.2f / 3.0f);

		if (data->analogwalk > 60) {
			g_Vars.currentplayer->speedmaxtime60 += g_Vars.lvupdate60;
		} else {
			g_Vars.currentplayer->speedmaxtime60 = 0;
		}
	}

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

	if (data->canlookahead == false && data->digitalstepforward == false) {
		g_Vars.currentplayer->speedmaxtime60 = 0;
	}
}

void bgrabUpdateSpeedTheta(void)
{
	f32 mult = (PAL ? 0.97519999742508f : 0.98470002412796f);
	f32 speedtheta = g_Vars.currentplayer->speedtheta * 0.75f;
	s32 i;

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		g_Vars.currentplayer->bondgrabthetaspeedsum = g_Vars.currentplayer->bondgrabthetaspeedsum * mult + speedtheta;
	}

	g_Vars.currentplayer->speedtheta = g_Vars.currentplayer->bondgrabthetaspeedsum * (PAL ? 0.024800002574921f : 0.01529997587204f);
}

void bgrab0f0ce924(void)
{
	f32 mult;
	f32 sp88;
	f32 sp84;
	f32 sp80;
	struct coord sp74 = {0, 0, 0};
	f32 sp70;
	f32 sp6c;
	f32 speedforwards;
	f32 speedsideways;
	f32 speedtheta;
	f32 maxspeed;
	f32 xdelta;
	f32 zdelta;
	f32 sp50;
	f32 sp4c;
	f32 sp48;
	f32 sp44;
	f32 sp40;
	f32 sp3c;
	f32 sp38;
	f32 breathing;

	if (g_Vars.lvupdate240 > 0) {
		bmove0f0cba88(&sp70, &sp6c, &g_Vars.currentplayer->bondshotspeed, g_Vars.currentplayer->vv_sintheta, g_Vars.currentplayer->vv_costheta);

		g_Vars.currentplayer->speedforwards += sp70;
		g_Vars.currentplayer->speedsideways += sp6c;

		mult = g_HeadAnims[HEADANIM_MOVING].translateperframe * 0.5f * g_Vars.lvupdate60freal;
		sp88 = mult * g_Vars.currentplayer->speedsideways;

		speedsideways = g_Vars.currentplayer->speedsideways * 0.8f;
		speedforwards = g_Vars.currentplayer->speedforwards;
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

		maxspeed = speedforwards;

		if (speedsideways > maxspeed) {
			maxspeed = speedsideways;
		}

		if (speedtheta > maxspeed) {
			maxspeed = speedtheta;
		}

		if (maxspeed >= 0.75f) {
			g_Vars.currentplayer->bondbreathing += (maxspeed - 0.75f) * g_Vars.lvupdate60freal / 900.0f;
		} else {
			g_Vars.currentplayer->bondbreathing -= (0.75f - maxspeed) * g_Vars.lvupdate60freal / 2700.0f;
		}

		if (g_Vars.currentplayer->bondbreathing < 0.0f) {
			g_Vars.currentplayer->bondbreathing = 0.0f;
		} else if (g_Vars.currentplayer->bondbreathing > 1.0f) {
			g_Vars.currentplayer->bondbreathing = 1.0f;
		}

		bmove0f0cc654(maxspeed, g_Vars.currentplayer->speedforwards, sp88);

		g_Vars.currentplayer->gunspeed = maxspeed;

		sp84 = g_Vars.currentplayer->headpos.x;
		sp80 = g_Vars.currentplayer->headpos.z;

#if VERSION >= VERSION_NTSC_1_0
		if (cheatIsActive(CHEAT_SMALLJO)) {
			sp84 *= 0.4f;
			sp80 *= 0.4f;
		}
#endif

		sp74.x += (sp80 * g_Vars.currentplayer->bond2.unk00.f[0] - sp84 * g_Vars.currentplayer->bond2.unk00.f[2]) * g_Vars.lvupdate60freal;
		sp74.z += (sp80 * g_Vars.currentplayer->bond2.unk00.f[2] + sp84 * g_Vars.currentplayer->bond2.unk00.f[0]) * g_Vars.lvupdate60freal;

		bmoveUpdateMoveInitSpeed(&sp74);

		if (debugIsTurboModeEnabled()) {
			sp74.x += (g_Vars.currentplayer->bond2.unk00.f[0] * g_Vars.currentplayer->speedforwards - (g_Vars.currentplayer->bond2.unk00.f[2] * g_Vars.currentplayer->speedsideways)) * g_Vars.lvupdate60freal * 10.0f;
			sp74.z += (g_Vars.currentplayer->bond2.unk00.f[2] * g_Vars.currentplayer->speedforwards + (g_Vars.currentplayer->bond2.unk00.f[0] * g_Vars.currentplayer->speedsideways)) * g_Vars.lvupdate60freal * 10.0f;
		}

		bgrab0f0ce0bc(&sp74);

		xdelta = g_Vars.currentplayer->prop->pos.f[0] - g_Vars.currentplayer->bondprevpos.f[0];
		zdelta = g_Vars.currentplayer->prop->pos.f[2] - g_Vars.currentplayer->bondprevpos.f[2];

		sp50 = -xdelta * g_Vars.currentplayer->bond2.unk00.f[2] + zdelta * g_Vars.currentplayer->bond2.unk00.f[0];
		sp4c = xdelta * g_Vars.currentplayer->bond2.unk00.f[0] + zdelta * g_Vars.currentplayer->bond2.unk00.f[2];
		sp48 = -sp74.f[0] * g_Vars.currentplayer->bond2.unk00.f[2] + sp74.f[2] * g_Vars.currentplayer->bond2.unk00.f[0];
		sp44 = sp74.f[0] * g_Vars.currentplayer->bond2.unk00.f[0] + sp74.f[2] * g_Vars.currentplayer->bond2.unk00.f[2];

		if (sp48 != 0.0f) {
			if (g_Vars.currentplayer->speedstrafe * sp48 > 0.0f) {
				sp50 /= sp48;

				if (sp50 <= 0.0f) {
					g_Vars.currentplayer->speedstrafe = 0.0f;
				} else if (sp50 < 1.0f) {
					g_Vars.currentplayer->speedstrafe *= sp50;
				}
			}
		}

		if (sp44 != 0.0f) {
			if (g_Vars.currentplayer->speedgo * sp44 > 0.0f) {
				sp4c /= sp44;

				if (sp4c <= 0.0f) {
					g_Vars.currentplayer->speedgo = 0.0f;
				} else if (sp4c < 1.0f) {
					g_Vars.currentplayer->speedgo *= sp4c;
				}
			}
		}

		sp40 = g_Vars.currentplayer->speedtheta;
		sp3c = g_Vars.currentplayer->speedverta / 0.7f;
		sp38 = g_Vars.currentplayer->gunspeed;

		breathing = bheadGetBreathingValue();

		if (sp3c > 1.0f) {
			sp3c = 1.0f;
		} else if (sp3c < -1.0f) {
			sp3c = -1.0f;
		}

		if (g_Vars.currentplayer->headanim == HEADANIM_MOVING) {
			breathing *= 1.2f;
		}

		bgun0f09d8dc(breathing, sp38, sp3c, sp40, 0.0f);
		bgunSetAdjustPos(g_Vars.currentplayer->vv_verta360 * 0.017450513f);
	}
}

void bgrabTick(void)
{
	bgrabUpdatePrevPos();
	bgrab0f0cdef0();
	bmoveUpdateVerta();
	bgrab0f0ce924();
	bgrab0f0ce178();
	bgrabUpdateVertical();

#if VERSION >= VERSION_NTSC_1_0
	{
		s32 i;

		for (i = 0; g_Vars.currentplayer->prop->rooms[i] != -1; i++) {
			if (g_Vars.currentplayer->prop->rooms[i] == g_Vars.currentplayer->floorroom) {
				propDeregisterRooms(g_Vars.currentplayer->prop);
				g_Vars.currentplayer->prop->rooms[0] = g_Vars.currentplayer->floorroom;
				g_Vars.currentplayer->prop->rooms[1] = -1;
				break;
			}
		}
	}
#endif

	{
		struct defaultobj *obj = g_Vars.currentplayer->grabbedprop->obj;
		struct hov *hov = NULL;

		if (obj->type == OBJTYPE_HOVERPROP) {
			struct hoverpropobj *hoverprop = (struct hoverpropobj *)g_Vars.currentplayer->grabbedprop->obj;
			hov = &hoverprop->hov;
		} else if (obj->type == OBJTYPE_HOVERBIKE) {
			struct hoverbikeobj *hoverbike = (struct hoverbikeobj *)g_Vars.currentplayer->grabbedprop->obj;
			hov = &hoverbike->hov;
		}

		if (hov) {
			hovTick(obj, hov);
		}

		bmoveUpdateRooms(g_Vars.currentplayer);
		objectiveCheckRoomEntered(g_Vars.currentplayer->prop->rooms[0]);
		bmove0f0cc19c(&g_Vars.currentplayer->prop->pos);
		playerUpdatePerimInfo();
		doorsCheckAutomatic();

		if (g_Vars.currentplayer->grabbedprop) {
			// Determine if the grabbed prop should be force released
			f32 ydiff = g_Vars.currentplayer->grabbedprop->pos.y
				- objGetHovBobOffsetY(g_Vars.currentplayer->grabbedprop->obj)
				- g_Vars.currentplayer->vv_manground;

			struct prop *grabbedprop = g_Vars.currentplayer->grabbedprop;

			propSetPerimEnabled(g_Vars.currentplayer->prop, false);
			propSetPerimEnabled(grabbedprop, false);

			if (g_Vars.currentplayer->vv_ground <= -30000
					|| ydiff < -100 || ydiff > 100
					|| g_Vars.currentplayer->vv_ground < g_Vars.currentplayer->vv_manground - 50
					|| !cdTestLos05(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms,
						&g_Vars.currentplayer->grabbedprop->pos, g_Vars.currentplayer->grabbedprop->rooms,
						CDTYPE_ALL,
						GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT)) {
				bmoveSetMode(MOVEMODE_WALK);
			}

			propSetPerimEnabled(g_Vars.currentplayer->prop, true);
			propSetPerimEnabled(grabbedprop, true);
		}
	}
}
