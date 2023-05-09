#include <ultra64.h>
#include "constants.h"
#include "game/smoke.h"
#include "game/bg.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/lib_17ce0.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

#define SPLATTYPE_PUDDLE 1
#define SPLATTYPE_DROP   2

struct splatdata {
	struct coord relpos;
	struct coord unk0c;
	struct coord unk18;
	struct coord gunpos;
	s32 splattype;
	struct prop *objprop;
	struct prop *chrprop;
	struct chrdata *chr;
	s32 mtxindex;
	s32 room;
	s32 isskedar;
	s32 translucent;
	f32 unk50;
	s32 timermax;
	s32 timerspeed;
};

#define var8007f8b4 5
#define var8007f8b8 50
#define g_SplatMaxDistance 180
#define var8007f8a8 12

static s32 splatsCreate(s32 qty, f32 arg1, struct prop *prop, struct shotdata *shotdataarg, struct coord *arg4, struct coord *arg5, bool isskedar, s32 splattype, s32 timermax, struct chrdata *chr, s32 timerspeed);
static bool splat0f149274(f32 arg0, struct prop *prop, struct shotdata *shotdata, f32 arg3, bool isskedar, s32 arg5, s32 arg6, struct chrdata *chr, s32 arg8);
static void splat0f14986c(struct splatdata *splatdata);

static f32 coordsGetDistance(struct coord *a, struct coord *b)
{
	f32 xdiff = b->x - a->x;
	f32 ydiff = b->y - a->y;
	f32 zdiff = b->z - a->z;

	return sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
}

void splatTickChr(struct prop *prop)
{
	struct chrdata *chr = prop->chr;
	struct chrdata *attacker = chr->lastattacker;
	s32 race;

	if (chr->noblood || (chr->chrflags & CHRCFLAG_HIDDEN) || chr->bulletstaken == 0) {
		return;
	}

	race = CHRRACE(chr);

	if (race != RACE_DRCAROLL && race != RACE_ROBOT) {
		u8 isskedar = false;

		if (race == RACE_SKEDAR || chr->bodynum == BODY_MRBLONDE) {
			isskedar = true;
		}


		if (chr->actiontype == ACT_DEAD || chr->actiontype == ACT_DIE) {
			u32 stack;
			f32 thudframe = -1.0f;

			if (chr->actiontype == ACT_DIE) {
				if (chr->act_die.thudframe2 != -1) {
					thudframe = chr->act_die.thudframe2;
				} else if (chr->act_die.thudframe1 != -1) {
					thudframe = chr->act_die.thudframe1;
				}
			}

			if (thudframe != -1.0f && modelGetCurAnimFrame(chr->model) < thudframe) {
			} else if (chr->tickssincesplat > TICKS(30) && chr->deaddropsplatsadded < 6) {
				chr->deaddropsplatsadded += splatsCreate(1, 1.1f, prop, NULL, 0, 0, isskedar, SPLATTYPE_PUDDLE, TICKS(150), attacker, random() & 8);
			}
		} else {
			// Consider creating a wounded drop
			u32 value = chr->bulletstaken * chr->tickssincesplat;

			if (value > TICKS(240)) {
				f32 dist = coordsGetDistance(&chr->lastdroppos, &prop->pos);
				s32 addmore = false;

				if (dist > 40) {
					addmore = true;
					chr->splatsdroppedhere = 0;
				} else if (chr->splatsdroppedhere < 8) {
					addmore = true;
					chr->splatsdroppedhere++;
				}

				if (addmore) {
					chr->woundedsplatsadded += splatsCreate(1, 0.3f, prop, NULL, 0, 0, isskedar, SPLATTYPE_DROP, TICKS(80), attacker, 0);
				}
			}

			if (chr->woundedsplatsadded >= 40) {
				wallhitRemoveOldestWoundedSplatByChr(prop);
				chr->woundedsplatsadded--;
			}

			chr->deaddropsplatsadded = 0;
		}
	}

	chr->tickssincesplat += g_Vars.lvupdate60;
}

void splatsCreateForChrHit(struct prop *prop, struct shotdata *shotdata, struct coord *arg2, struct coord *arg3, bool isskedar, s32 splattype, struct chrdata *chr2)
{
	struct chrdata *chr = prop->chr;

	if (chr->bulletstaken < 7) {
		chr->bulletstaken++;
	}

	if (splattype == 0) {
		u32 qty = random() % 3;

		if (qty) {
			chr->stdsplatsadded += splatsCreate(qty, 0.8f, prop, shotdata, arg2, arg3, isskedar, splattype, TICKS(50), chr2, 0);
		}
	}
}

static s32 splatsCreate(s32 qty, f32 arg1, struct prop *prop, struct shotdata *shotdataarg,
		struct coord *arg4, struct coord *arg5, bool isskedar, s32 splattype,
		s32 timermax, struct chrdata *chr, s32 timerspeed)
{
	struct shotdata stackshotdata;
	struct shotdata *shotdata = splattype == 0 ? shotdataarg : &stackshotdata;
	struct coord spfc;
	struct coord spf0;
	struct coord spe4;
	Mtxf spa4;
	s32 numdropped = 0;
	f32 dist;
	s32 i;
	s32 j;

	if (splattype == 0) {
		dist = coordsGetDistance(&shotdata->gunpos, arg5);

		for (i = 0; i < 3; i++) {
			spfc.f[i] = shotdata->dir.f[i];
			spf0.f[i] = shotdata->unk0c.f[i];
			shotdata->gunpos.f[i] = arg5->f[i];
			shotdata->unk00.f[i] = arg4->f[i];
		}
	} else {
		f32 extraheight;

		if (prop->type == PROPTYPE_CHR) {
			extraheight = 50;
		} else {
			extraheight = 0;
		}

		dist = 0.7f;

		spfc.x = shotdata->dir.x = 0;
		spfc.y = shotdata->dir.y = -1;
		spfc.z = shotdata->dir.z = 0;

		spf0.x = shotdata->unk0c.x = 0;
		spf0.y = shotdata->unk0c.y = -1;
		spf0.z = shotdata->unk0c.z = 0;

		shotdata->gunpos.x = prop->pos.x;
		shotdata->gunpos.y = prop->pos.y + extraheight;
		shotdata->gunpos.z = prop->pos.z;

		shotdata->unk00.x = prop->pos.x;
		shotdata->unk00.y = prop->pos.y + extraheight;
		shotdata->unk00.z = prop->pos.z;
	}

	for (i = 0; i < qty; i++) {
		for (j = 0; j < 3; j++) {
			spe4.f[j] = (RANDOMFRAC() * var8007f8a8 * 2.0f - var8007f8a8) * 0.017453292384744f;
		}

		mtx4LoadRotation(&spe4, &spa4);
		mtx4RotateVec(&spa4, &spfc, &shotdata->dir);
		mtx4RotateVec(&spa4, &spf0, &shotdata->unk0c);

		func0f177164(&shotdata->dir, &shotdata->dir);
		func0f177164(&shotdata->unk0c, &shotdata->unk0c);

		if (splat0f149274(arg1, prop, shotdata, /*reused var*/ dist, isskedar, splattype, timermax, chr, timerspeed)) {
			numdropped++;
		}
	}

	if (numdropped) {
		struct chrdata *chr = prop->chr;

		chr->tickssincesplat = 0;
		chr->lastdroppos = prop->pos;
	}

	return numdropped;
}

static bool splat0f149274(f32 arg0, struct prop *chrprop, struct shotdata *shotdata, f32 arg3, bool isskedar, s32 splattype, s32 timermax, struct chrdata *chr, s32 timerspeed)
{
	struct prop **propptr;
	struct prop *objprop;
	struct hitthing hitthing;
	struct hitthing besthitthing;
	s16 rooms[32];
	s16 gunrooms[8];
	s16 endrooms[8];
	struct coord endpos;
	s32 i;
	struct coord *sp50c;
	struct coord *hitpos;
	struct coord *sp504;
	s32 bestroom = 0;
	s32 mtxindex;
	s32 room;
	f32 spraydistance;
	bool translucent;
	bool hasresult = false;
	struct shotdata stackshotdata;

	for (i = 0; i < 3; i++) {
		stackshotdata.unk00.f[i] = shotdata->unk00.f[i];
		stackshotdata.unk0c.f[i] = shotdata->unk0c.f[i];
		stackshotdata.gunpos.f[i] = shotdata->gunpos.f[i];
		stackshotdata.dir.f[i] = shotdata->dir.f[i];
	}

	stackshotdata.penetration = 1;

	for (i = 0; i < 3; i++) {
		endpos.f[i] = stackshotdata.gunpos.f[i] + stackshotdata.dir.f[i] * g_SplatMaxDistance;
	}

	portal00018148(&chrprop->pos, &stackshotdata.gunpos, chrprop->rooms, gunrooms, NULL, 0);
	portal00018148(&stackshotdata.gunpos, &endpos, gunrooms, endrooms, rooms, ARRAYCOUNT(rooms) - 1);

	for (i = 0; rooms[i] != -1; i++) {
		if (bgTestHitInRoom(&stackshotdata.gunpos, &endpos, rooms[i], &hitthing)
				&& ((stackshotdata.gunpos.x <= endpos.x && hitthing.unk00.x <= endpos.x && stackshotdata.gunpos.x <= hitthing.unk00.x) || (endpos.x <= stackshotdata.gunpos.x && endpos.x <= hitthing.unk00.x && hitthing.unk00.x <= stackshotdata.gunpos.x))
					&& ((stackshotdata.gunpos.y <= endpos.y && hitthing.unk00.y <= endpos.y && stackshotdata.gunpos.y <= hitthing.unk00.y) || (endpos.y <= stackshotdata.gunpos.y && endpos.y <= hitthing.unk00.y && hitthing.unk00.y <= stackshotdata.gunpos.y))
					&& ((stackshotdata.gunpos.z <= endpos.z && hitthing.unk00.z <= endpos.z && stackshotdata.gunpos.z <= hitthing.unk00.z) || (endpos.z <= stackshotdata.gunpos.z && endpos.z <= hitthing.unk00.z && hitthing.unk00.z <= stackshotdata.gunpos.z))) {
			if (stackshotdata.gunpos.x != hitthing.unk00.x || stackshotdata.gunpos.y != hitthing.unk00.y || stackshotdata.gunpos.z != hitthing.unk00.z) {
				bestroom = rooms[i];
				besthitthing = hitthing;

				endpos = hitthing.unk00;

				hasresult = true;
				break;
			}
		}
	}

	if (hasresult) {
		spraydistance = coordsGetDistance(&stackshotdata.gunpos, &besthitthing.unk00);

		if (spraydistance < g_SplatMaxDistance) {
			sp50c = &hitthing.unk00;
			hitpos = &hitthing.unk00;
			sp504 = &hitthing.unk0c;
			objprop = NULL;
			mtxindex = 0;
			room = bestroom;
			translucent = hitthing.unk2c == 2;
		} else {
			hasresult = false;
		}
	} else {
		spraydistance = 999999.0f;
	}

	if (splattype == 0) {
		stackshotdata.unk34 = (spraydistance < g_SplatMaxDistance ? spraydistance : g_SplatMaxDistance);
		stackshotdata.unk34 += arg3;

		for (i = 0; i < ARRAYCOUNT(stackshotdata.hits); i++) {
			stackshotdata.hits[i].prop = NULL;
			stackshotdata.hits[i].hitpart = 0;
			stackshotdata.hits[i].node = NULL;
		}

		propptr = g_Vars.endonscreenprops - 1;

		while (propptr >= g_Vars.onscreenprops) {
			struct prop *prop = *propptr;

			if (prop) {
				if (prop->type & (PROPTYPE_OBJ | PROPTYPE_DOOR | PROPTYPE_WEAPON)) {
					func0f085e00(prop, &stackshotdata);
					if (1);
				}
			}

			propptr--;
		}

		for (i = 0; i < ARRAYCOUNT(stackshotdata.hits); i++) {
			struct hit *hit = &stackshotdata.hits[i];

			if (hit->prop && (hit->hitthing.texturenum < 0
						|| hit->hitthing.texturenum >= NUM_TEXTURES
						|| g_SurfaceTypes[g_Textures[hit->hitthing.texturenum].surfacetype]->numwallhittexes != 0)) {
				sp50c = &hit->hitthing.unk00;
				hitpos = &hit->pos;
				sp504 = &hit->hitthing.unk0c;
				objprop = hit->prop;
				mtxindex = (s8)hit->mtxindex;
				room = 1;
				translucent = false;
				hasresult = true;
				break;
			}
		}
	}

	if (hasresult) {
		struct splatdata splatdata;
		u32 stack;

		for (i = 0; i < 3; i++) {
			splatdata.relpos.f[i] = sp50c->f[i];
			splatdata.unk0c.f[i] = hitpos->f[i];
			splatdata.gunpos.f[i] = stackshotdata.gunpos.f[i];
			splatdata.unk18.f[i] = sp504->f[i];
		}

		splatdata.chrprop = chrprop;
		splatdata.objprop = objprop;
		splatdata.chr = chr;
		splatdata.mtxindex = mtxindex;
		splatdata.room = room;
		splatdata.isskedar = isskedar;
		splatdata.timermax = timermax;
		splatdata.unk50 = arg0;
		splatdata.splattype = splattype;
		splatdata.timerspeed = timerspeed;
		splatdata.translucent = translucent;

		splat0f14986c(&splatdata);

		return true;
	}

	if (hitthing.unk00.x);
	if (hitthing.unk00.y);
	if (hitthing.unk00.z);

	return false;
}

static void splat0f14986c(struct splatdata *splat)
{
	f32 spac;
	f32 spa8;
	struct defaultobj *obj;
	f32 spa0;
	f32 sp9c;
	f32 height;
	f32 width;
	u8 maxalpha = 0xff;
	u8 minalpha = 0xc0;
	s32 texnum;
	bool sp88 = splat->isskedar & 1;
	bool sp84 = splat->isskedar & 1;
	bool translucent = splat->translucent;
	f32 distance;
	s16 smokerooms[2];

	texnum = WALLHITTEX_BLOOD1 + (random() % 3);

	if (splat->objprop != NULL && splat->objprop->type == PROPTYPE_OBJ) {
		obj = splat->objprop->obj;

		if (obj && (obj->type == OBJTYPE_GLASS || obj->type == OBJTYPE_TINTEDGLASS)) {
			minalpha = 0x40;
			translucent = true;
		}
	}

	switch (splat->splattype) {
	case SPLATTYPE_PUDDLE:
		texnum = WALLHITTEX_BLOOD1 + (random() % 3);
		break;
	case SPLATTYPE_DROP:
		texnum = WALLHITTEX_BLOOD4 + (random() % 1);
		break;
	}

	switch (random() % 6) {
	case 0:
	case 1:
	case 2:
		sp9c = 1.5f;
		break;
	case 3:
	case 4:
		sp9c = 5.0f;
		break;
	case 5:
		sp9c = 3.0f;
		break;
	}

	distance = coordsGetDistance(&splat->gunpos, &splat->unk0c);
	spa0 = 0.15f * distance * sp9c;

	if (var8007f8b8 < spa0) {
		spa0 = var8007f8b8;
	}

	if (var8007f8b4 > spa0) {
		spa0 = var8007f8b4;
	}

	spac = 0.5f * spa0;
	spa8 = 0.5f * spa0;

	if (spac < 1.0f) {
		spac = 1.0f;
	}

	if (spa8 < 1.0f) {
		spa8 = 1.0f;
	}

	width = RANDOMFRAC() * spac * 2.0f - spac + spa0;
	height = RANDOMFRAC() * spa8 * 2.0f - spa8 + spa0;

	if (width > var8007f8b8) {
		width = var8007f8b8;
	}

	if (height > var8007f8b8) {
		height = var8007f8b8;
	}

	width *= splat->unk50;
	height *= splat->unk50;

	wallhitChooseBloodColour(splat->chrprop);

	wallhitCreateWith20Args(&splat->relpos, &splat->unk18, splat->chr ? &splat->chr->prop->pos : NULL, NULL,
			NULL, texnum, splat->room, splat->objprop,
			splat->chrprop, splat->mtxindex, 0, splat->chr,
			width, height, minalpha, maxalpha,
			random() % 360, (u16)splat->timermax, splat->timerspeed, translucent);

	if (sp88 || sp84) {
		smokerooms[0] = splat->room;
		smokerooms[1] = -1;

		smokeCreateSimple(&splat->unk0c, smokerooms, sp88 ? SMOKETYPE_SKCORPSE : SMOKETYPE_14);
	}
}

void splatResetChr(struct chrdata *chr)
{

	chr->bulletstaken = 0;
	chr->tickssincesplat = 0;
	chr->stdsplatsadded = 0;
	chr->woundedsplatsadded = 0;
	chr->deaddropsplatsadded = 0;
	chr->splatsdroppedhere = 0;
	chr->lastdroppos.x = 0;
	chr->lastdroppos.y = 0;
	chr->lastdroppos.z = 0;
}
