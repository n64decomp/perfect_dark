#include <ultra64.h>
#include "lib/sched.h"
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/chr.h"
#include "game/chrmgr.h"
#include "game/env.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/game_096360.h"
#include "game/bondgun.h"
#include "game/gunfx.h"
#include "game/game_0b0fd0.h"
#include "game/modelmgr.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/game_0c33f0.h"
#include "game/playermgr.h"
#include "game/game_1291b0.h"
#include "game/vtxstore.h"
#include "game/gfxmemory.h"
#include "game/explosions.h"
#include "game/smoke.h"
#include "game/sparks.h"
#include "game/bg.h"
#include "game/file.h"
#include "game/mplayer/setup.h"
#include "game/bot.h"
#include "game/botact.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "data.h"
#include "gbiex.h"
#include "types.h"

void *var8009ccc0[20];
s32 g_NumChrs;
s16 g_ChrIndexesByChrnum[240];
struct chrdata *g_CurModelChr;

struct var80062960 *var80062960 = NULL;
s32 var80062964 = 0;
f32 var80062968 = 0;
bool var8006296c = false;
s32 g_SelectedAnimNum = 0;
u32 var80062974 = 0x00000000;
u32 var80062978 = 0x00000000;
u32 var8006297c = 0;
u32 var80062980 = 0;
s32 g_NextChrnum = 200;

struct chrdata *g_ChrSlots = NULL;

s32 g_NumChrSlots = 0;

s32 chrsGetNumSlots(void)
{
	return g_NumChrSlots;
}

void chrSetChrnum(struct chrdata *chr, s16 newnum)
{
	s16 oldnum = chr->chrnum;
	s16 index;

	index = g_ChrIndexesByChrnum[oldnum];
	g_ChrIndexesByChrnum[oldnum] = -1;
	g_ChrIndexesByChrnum[newnum] = index;

	chr->chrnum = newnum;
}

void chrRegister(s32 chrnum, s32 chrindex)
{
	g_ChrIndexesByChrnum[chrnum] = chrindex;
}

void chrDeregister(s32 chrnum)
{
	g_ChrIndexesByChrnum[chrnum] = -1;
}

struct gfxvtx *chrAllocateVertices(s32 numvertices)
{
	return (struct gfxvtx *) gfxAllocate(numvertices * sizeof(struct gfxvtx));
}

void chrsSetVar8006297c(u32 arg0)
{
	var8006297c = arg0;
}

u32 chrsGetVar8006297c(void)
{
	return var8006297c;
}

void chrsSetVar80062980(u32 arg0)
{
	var80062980 = arg0;
}

u32 chrsGetVar80062980(void)
{
	return var80062980;
}

void chrSetPerimEnabled(struct chrdata *chr, bool enable)
{
	if (chr) {
		if (enable) {
			chr->hidden &= ~CHRHFLAG_PERIMDISABLED;
		} else {
			chr->hidden |= CHRHFLAG_PERIMDISABLED;
		}
	}
}

/**
 * When a chr is being pushed by a player, this function is called with the new
 * pos and rooms for the chr. It does collision checks and updates dstpos and
 * dstrooms to valid ones if needed.
 */
void chrCalculatePushPos(struct chrdata *chr, struct coord *dstpos, s16 *dstrooms, bool arg3)
{
	f32 ymax;
	f32 ymin;
	f32 radius;
	bool moveok = false;
	f32 movex;
	f32 movez;
	struct prop *prop = chr->prop;
	u32 stack;
	f32 halfradius;
	struct defaultobj *chair = NULL;
	s32 cdresult;
	s16 sp84[20];
#if VERSION < VERSION_NTSC_1_0
	s32 i;
#endif
	struct coord sp78;
	struct coord sp6c;
	struct coord sp60;
	struct coord sp54;
	f32 value;
	struct coord sp44;
#if VERSION < VERSION_NTSC_1_0
	s32 j;
	s32 k;
	s32 l;
#endif

	// The eyespy can't be pushed
	if (CHRRACE(chr) == RACE_EYESPY) {
		roomsCopy(prop->rooms, dstrooms);
		chrSetPerimEnabled(chr, true);
		return;
	}

	chrGetBbox(prop, &radius, &ymax, &ymin);
	halfradius = radius * 0.5f;
	chrSetPerimEnabled(chr, false);

	// myspecial is the chr's chair
	if (chr->myspecial != -1) {
		chair = objFindByTagId(chr->myspecial);

		if (chair && chair->prop) {
			objSetPerimEnabled(chair->prop, false);
		}
	}

	func0f065dfc(&prop->pos, prop->rooms, dstpos, dstrooms, sp84, 20);

#if VERSION < VERSION_NTSC_1_0
	for (i = 0; dstrooms[i] != -1; i++) {
		if (dstrooms[i] == chr->floorroom) {
			dstrooms[0] = chr->floorroom;
			dstrooms[1] = -1;
			break;
		}
	}
#endif

	chr0f021fa8(chr, dstpos, dstrooms);

	movex = dstpos->x - prop->pos.x;
	movez = dstpos->z - prop->pos.z;

	if (movex > halfradius || movez > halfradius || movex < -halfradius || movez < -halfradius) {
		cdresult = cdExamCylMove05(&prop->pos, prop->rooms, dstpos, dstrooms, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);

		if (cdresult == CDRESULT_NOCOLLISION) {
			cdresult = cdExamCylMove01(&prop->pos, dstpos, radius, dstrooms, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
		}
	} else {
		cdresult = cdExamCylMove01(&prop->pos, dstpos, radius, sp84, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
	}

	if (cdresult != CDRESULT_ERROR) {
		if (cdresult == CDRESULT_NOCOLLISION) {
			// The move was completely valid
			if (arg3) {
				chr->invalidmove = 0;
				chr->lastmoveok60 = g_Vars.lvframe60;
			}

			moveok = true;
		} else {
#if VERSION >= VERSION_PAL_FINAL
			cdGetEdge(&sp78, &sp6c, 453, "chr/chr.c");
#elif VERSION >= VERSION_PAL_BETA
			cdGetEdge(&sp78, &sp6c, 453, "chr.c");
#elif VERSION >= VERSION_NTSC_1_0
			cdGetEdge(&sp78, &sp6c, 453, "chr/chr.c");
#else
			cdGetEdge(&sp78, &sp6c, 451, "chr.c");
#endif

			// Attempt to find a valid position - method #1
			sp60.x = dstpos->x - prop->pos.x;
			sp60.z = dstpos->z - prop->pos.z;

			if (sp78.f[0] != sp6c.f[0] || sp78.f[2] != sp6c.f[2]) {
				sp54.x = sp6c.x - sp78.x;
				sp54.z = sp6c.z - sp78.z;

				value = 1.0f / sqrtf(sp54.f[0] * sp54.f[0] + sp54.f[2] * sp54.f[2]);

				sp54.x *= value;
				sp54.z *= value;

				value = sp60.f[0] * sp54.f[0] + sp60.f[2] * sp54.f[2];

				sp44.x = sp54.x * value + prop->pos.x;
				sp44.y = dstpos->y;
				sp44.z = sp54.z * value + prop->pos.z;

				func0f065dfc(&prop->pos, prop->rooms, &sp44, dstrooms, sp84, 20);

#if VERSION < VERSION_NTSC_1_0
				for (j = 0; dstrooms[j] != -1; j++) {
					if (dstrooms[j] == chr->floorroom) {
						dstrooms[0] = chr->floorroom;
						dstrooms[1] = -1;
						break;
					}
				}
#endif

				chr0f021fa8(chr, &sp44, dstrooms);

				movex = sp44.x - prop->pos.x;
				movez = sp44.z - prop->pos.z;

				if (movex > halfradius || movez > halfradius || movex < -halfradius || movez < -halfradius) {
					cdresult = cdTestCylMove02(&prop->pos, prop->rooms, &sp44, dstrooms, CDTYPE_ALL, true, ymax - prop->pos.y, ymin - prop->pos.y);

					if (cdresult == CDRESULT_NOCOLLISION) {
						cdresult = cdTestVolume(&sp44, radius, dstrooms, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
					}
				} else {
					cdresult = cdTestVolume(&sp44, radius, sp84, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
				}

				if (cdresult == CDRESULT_NOCOLLISION) {
					dstpos->x = sp44.x;
					dstpos->z = sp44.z;
					chr->invalidmove = 2;
					moveok = true;
				}
			}

			if (!moveok) {
				// Attempt to find a valid position - method #2
				sp54.x = sp78.x - dstpos->x;
				sp54.z = sp78.z - dstpos->z;

				if (sp54.f[0] * sp54.f[0] + sp54.f[2] * sp54.f[2] <= radius * radius) {
					if (sp78.f[0] != prop->pos.f[0] || sp78.f[2] != prop->pos.f[2]) {
						sp54.x = -(sp78.z - prop->pos.z);
						sp54.z = sp78.x - prop->pos.x;

						value = 1.0f / sqrtf(sp54.f[0] * sp54.f[0] + sp54.f[2] * sp54.f[2]);

						sp54.x *= value;
						sp54.z *= value;

						value = sp60.f[0] * sp54.f[0] + sp60.f[2] * sp54.f[2];

						sp44.x = sp54.x * value + prop->pos.x;
						sp44.y = dstpos->y;
						sp44.z = sp54.z * value + prop->pos.z;

						func0f065dfc(&prop->pos, prop->rooms, &sp44, dstrooms, sp84, 20);

#if VERSION < VERSION_NTSC_1_0
						for (k = 0; dstrooms[k] != -1; k++) {
							if (dstrooms[k] == chr->floorroom) {
								dstrooms[0] = chr->floorroom;
								dstrooms[1] = -1;
								break;
							}
						}
#endif

						chr0f021fa8(chr, &sp44, dstrooms);

						movex = sp44.x - prop->pos.x;
						movez = sp44.z - prop->pos.z;

						if (movex > halfradius || movez > halfradius || movex < -halfradius || movez < -halfradius) {
							cdresult = cdTestCylMove02(&prop->pos, prop->rooms, &sp44, dstrooms, CDTYPE_ALL, true, ymax - prop->pos.y, ymin - prop->pos.y);

							if (cdresult == CDRESULT_NOCOLLISION) {
								cdresult = cdTestVolume(&sp44, radius, dstrooms, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
							}
						} else {
							cdresult = cdTestVolume(&sp44, radius, sp84, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
						}

						if (cdresult == CDRESULT_NOCOLLISION) {
							dstpos->x = sp44.x;
							dstpos->z = sp44.z;
							chr->invalidmove = 2;
							moveok = true;
						}
					}
				} else {
					sp54.x = sp6c.x - dstpos->x;
					sp54.z = sp6c.z - dstpos->z;

					if (sp54.f[0] * sp54.f[0] + sp54.f[2] * sp54.f[2] <= radius * radius) {
						if (sp6c.f[0] != prop->pos.f[0] || sp6c.f[2] != prop->pos.f[2]) {
							sp54.x = -(sp6c.z - prop->pos.z);
							sp54.z = sp6c.x - prop->pos.x;

							value = 1.0f / sqrtf(sp54.f[0] * sp54.f[0] + sp54.f[2] * sp54.f[2]);

							sp54.x *= value;
							sp54.z *= value;

							value = sp60.f[0] * sp54.f[0] + sp60.f[2] * sp54.f[2];

							sp44.x = sp54.x * value + prop->pos.x;
							sp44.y = dstpos->y;
							sp44.z = sp54.z * value + prop->pos.z;

							func0f065dfc(&prop->pos, prop->rooms, &sp44, dstrooms, sp84, 20);

#if VERSION < VERSION_NTSC_1_0
							for (l = 0; dstrooms[l] != -1; l++) {
								if (dstrooms[l] == chr->floorroom) {
									dstrooms[0] = chr->floorroom;
									dstrooms[1] = -1;
									break;
								}
							}
#endif

							chr0f021fa8(chr, &sp44, dstrooms);

							movex = sp44.x - prop->pos.x;
							movez = sp44.z - prop->pos.z;

							if (movex > halfradius || movez > halfradius || movex < -halfradius || movez < -halfradius) {
								cdresult = cdTestCylMove02(&prop->pos, prop->rooms, &sp44, dstrooms, CDTYPE_ALL, true, ymax - prop->pos.y, ymin - prop->pos.y);

								if (cdresult == CDRESULT_NOCOLLISION) {
									cdresult = cdTestVolume(&sp44, radius, dstrooms, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
								}
							} else {
								cdresult = cdTestVolume(&sp44, radius, sp84, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
							}

							if (cdresult == CDRESULT_NOCOLLISION) {
								dstpos->x = sp44.x;
								dstpos->z = sp44.z;
								chr->invalidmove = 2;
								moveok = true;
							}
						}
					}
				}
			}
		}
	}

	if (!moveok) {
		// Keep chr where they are
		dstpos->x = prop->pos.x;
		dstpos->z = prop->pos.z;
		roomsCopy(prop->rooms, dstrooms);
		chr->invalidmove = 1;
	}

	chrSetPerimEnabled(chr, true);

	if (chair && chair->prop) {
		objSetPerimEnabled(chair->prop, true);
	}
}

#if VERSION >= VERSION_NTSC_1_0
bool chr0f01f264(struct chrdata *chr, struct coord *pos, s16 *rooms, f32 arg3, bool arg4)
#else
bool chr0f01f264(struct chrdata *chr, struct coord *pos, s16 *rooms, f32 arg3)
#endif
{
	bool result;
	struct coord newpos;
	s16 newrooms[8];
	f32 ymax;
	f32 ymin;
	f32 radius;

	newpos.x = pos->x;
	newpos.y = pos->y + arg3;
	newpos.z = pos->z;

	chrGetBbox(chr->prop, &radius, &ymax, &ymin);
	func0f065e74(pos, rooms, &newpos, newrooms);
	chr0f021fa8(chr, &newpos, newrooms);
	chrSetPerimEnabled(chr, false);
	result = cdTestVolume(&newpos, radius, newrooms, CDTYPE_ALL, CHECKVERTICAL_YES,
			ymax - chr->prop->pos.y,
			ymin - chr->prop->pos.y);
	chrSetPerimEnabled(chr, true);

#if VERSION >= VERSION_NTSC_1_0
	if (result == true && arg4) {
		pos->y = newpos.y;
		roomsCopy(newrooms, rooms);
	}
#endif

	return result == CDRESULT_NOCOLLISION;
}

bool chr0f01f378(struct model *model, struct coord *arg1, struct coord *arg2, f32 *mangroundptr)
{
	struct chrdata *chr = model->chr;
	struct prop *prop = chr->prop;
	struct prop *lift;
	s32 i;
	f32 ground;
	s16 spfc[8];
	f32 manground = chr->manground;
	s32 race = CHRRACE(chr);
	f32 yincrement = 0.0f;
	bool inlift;
	u16 floorflags = 0;
#if VERSION >= VERSION_NTSC_1_0
	s32 lvupdate240;
	f32 lvupdate60f;
	f32 lvupdate60freal;
	struct coord spd0;
	s16 spc0[8];
#endif

	// NTSC beta reads g_Vars lvupdate properties throughout this function,
	// while NTSC 1.0 and newer copy them into stack variables at the start.
	// A macro is used here for readability
#if VERSION >= VERSION_NTSC_1_0
	lvupdate240 = g_Vars.lvupdate240;
	lvupdate60f = g_Vars.lvupdate60f;
	lvupdate60freal = g_Vars.lvupdate60freal;

#define VAR(property) property
#else
#define VAR(property) g_Vars.property
#endif

	if (g_Anims[model->anim->animnum].flags & ANIMFLAG_02) {
		if (chr->hidden & CHRHFLAG_00020000) {
			func0f065e98(&prop->pos, prop->rooms, arg2, spfc);
		} else {
			func0f065e74(&prop->pos, prop->rooms, arg2, spfc);
		}

		ground = cdFindGroundInfoAtCyl(arg2, chr->radius, spfc, &chr->floorcol, &chr->floortype, &floorflags, &chr->floorroom, &inlift, &lift);

		if (ground < -1000000) {
			ground = 0.0f;
		}

		chr->ground = ground;
		chr->act_die.timeextra = 0.0f; // @bug? Assuming the actiontype
		chr->fallspeed.x = 0.0f;
		chr->fallspeed.y = 0.0f;
		chr->fallspeed.z = 0.0f;
		chr->manground = ground;
		chr->sumground = ground * (PAL ? 8.4175090789795f : 9.999998f);
		arg2->y -= ground;
	} else {
		arg2->y += manground;

		if (chr->aibot) {
			f32 move[2] = {0, 0};

			if (VAR(lvupdate240) > 0) {
#if VERSION >= VERSION_NTSC_1_0
				if (chr->aibot->unk078 != 0) {
					if (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) {
						chr->aibot->unk078 = 0;
					} else {
						chr->aibot->unk078--;

						if (lvupdate240 >= 25) {
							lvupdate60f = 4.0f;
							lvupdate60freal = PALUPF(4.0f);
							lvupdate240 = 16;
						}
					}
				} else if (chr->onladder
						&& ((chr->prop->flags & (PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) == 0)
						&& lvupdate240 >= 25) {
					lvupdate60f = 4.0f;
					lvupdate60freal = PALUPF(4.0f);
					lvupdate240 = 16;
				}

				bot0f1921f8(chr, move, lvupdate240, lvupdate60freal);
#else
				bot0f1921f8(chr, move);
#endif
			}

			arg2->x = arg1->x + move[0];
			arg2->z = arg1->z + move[1];
		}

		if (chr->actiontype == ACT_PATROL || chr->actiontype == ACT_GOPOS) {
			chr->onladder = cdFindLadder(&chr->prop->pos, chr->radius * 2.5f,
					chr->manground + chr->height - chr->prop->pos.y,
					chr->manground + 1.0f - chr->prop->pos.y,
					chr->prop->rooms, GEOFLAG_LADDER, &chr->laddernormal);
		} else {
			chr->onladder = false;
		}

		if (chr->aibot != NULL) {
			chr->height = 185.0f;

			if (chr->actiontype == ACT_GOPOS && (chr->act_gopos.flags & GOPOSFLAG_WALKDIRECT)) {
				chr->height = 135.0f;
			} else if (chr->actiontype == ACT_GOPOS && (chr->act_gopos.flags & GOPOSFLAG_DUCK)) {
				chr->height = 90.0f;
			} else if (cd0002a13c(&chr->prop->pos, chr->radius * 1.1f,
						chr->manground + 185.0f - chr->prop->pos.y,
						chr->manground - 10.0f - chr->prop->pos.y,
						chr->prop->rooms, GEOFLAG_AIBOTDUCK)) {
				chr->height = 135.0f;
			} else if (cd0002a13c(&chr->prop->pos, chr->radius * 1.1f,
						chr->manground + 135.0f - chr->prop->pos.y,
						chr->manground - 10.0f - chr->prop->pos.y,
						chr->prop->rooms, GEOFLAG_AIBOTCROUCH)) {
				chr->height = 90.0f;
			}

			bmove0f0cb904(&chr->aibot->shotspeed);

			arg2->x += chr->aibot->shotspeed.x * var80075c00[1].unk0c * VAR(lvupdate60freal) * 0.5f;
			arg2->z += chr->aibot->shotspeed.z * var80075c00[1].unk0c * VAR(lvupdate60freal) * 0.5f;
		}

		if (chr->actiontype == ACT_DIE && chr->act_die.timeextra > 0.0f) {
			f32 speed = model->anim->playspeed * VAR(lvupdate60f) * (chr->act_die.timeextra - chr->act_die.elapseextra) / chr->act_die.timeextra;

			arg2->x += chr->act_die.extraspeed.x * speed;
			arg2->z += chr->act_die.extraspeed.z * speed;

			yincrement += chr->act_die.extraspeed.y * speed;

			chr->act_die.elapseextra += VAR(lvupdate60f) * model->anim->playspeed;

			if (chr->act_die.elapseextra > chr->act_die.timeextra) {
				chr->act_die.timeextra = 0.0f;
			}
		} else if (chr->timeextra > 0.0f) {
			f32 speed = model->anim->playspeed * VAR(lvupdate60f) * (chr->timeextra - chr->elapseextra) / chr->timeextra;

			arg2->x += chr->extraspeed.x * speed;
			arg2->z += chr->extraspeed.z * speed;

			yincrement += chr->extraspeed.y * speed;

			chr->elapseextra += VAR(lvupdate60f) * model->anim->playspeed;

			if (chr->elapseextra > chr->timeextra) {
				chr->timeextra = 0.0f;
			}
		}

		if (chr->pushspeed[0] != 0.0f || chr->pushspeed[1] != 0.0f) {
			arg2->x += chr->pushspeed[0] * VAR(lvupdate60freal);
			arg2->z += chr->pushspeed[1] * VAR(lvupdate60freal);

			chr->pushspeed[0] *= 0.9f;
			chr->pushspeed[1] *= 0.9f;

			if (chr->pushspeed[0] != 0.0f || chr->pushspeed[1] != 0.0f) {
				f32 pushdist = sqrtf(chr->pushspeed[0] * chr->pushspeed[0] + chr->pushspeed[1] * chr->pushspeed[1]);

				if (pushdist > 0.0f) {
					pushdist = 0.1f * VAR(lvupdate60freal) / pushdist;

					if (pushdist >= 1.0f) {
						chr->pushspeed[0] = 0.0f;
						chr->pushspeed[1] = 0.0f;
					} else {
						chr->pushspeed[0] -= chr->pushspeed[0] * pushdist;
						chr->pushspeed[1] -= chr->pushspeed[1] * pushdist;
					}
				} else {
					chr->pushspeed[0] = 0.0f;
					chr->pushspeed[1] = 0.0f;
				}
			}
		}

		arg2->x += chr->fallspeed.x * VAR(lvupdate60freal);
		arg2->z += chr->fallspeed.z * VAR(lvupdate60freal);

		if (race == RACE_EYESPY) {
			struct eyespy *eyespy = chrToEyespy(chr);

			if (eyespy && eyespy->deployed) {
				*arg2 = chr->prop->pos;
			}
		} else if (chr->actiontype == ACT_SKJUMP
				&& chr->act_skjump.state == SKJUMPSTATE_AIRBORNE
				&& !chr->act_skjump.needsnewanim
				&& g_Vars.lvupdate60 != 0) {
			arg2->x = chr->act_skjump.pos.x;
			yincrement = chr->act_skjump.pos.y;
			arg2->z = chr->act_skjump.pos.z;
		} else if (chr->onladder) {
			f32 dist;
			f32 xdiff = arg2->x - arg1->x;
			f32 zdiff = arg2->z - arg1->z;

			arg2->x = arg1->x;
			arg2->z = arg1->z;

			dist = sqrtf(xdiff * xdiff + zdiff * zdiff);

#if VERSION >= VERSION_NTSC_1_0
			if (dist > 100.0f) {
				dist = 100.0f;
			}
#endif

			yincrement += dist;

			chr->floortype = FLOORTYPE_METAL;
		}

		if (prop->type == PROPTYPE_PLAYER && chr->actiontype == ACT_BONDMULTI) {
			arg2->x = prop->pos.x;
			arg2->z = prop->pos.z;

			roomsCopy(prop->rooms, spfc);

			chr->invalidmove = 0;
			chr->lastmoveok60 = g_Vars.lvframe60;
		} else {
			if (chr->chrflags & CHRCFLAG_HAS_SPECIAL_DEATH_ANIMATION) {
				arg2->x = arg1->x;
				arg2->z = arg1->z;
			}

			chrCalculatePushPos(chr, arg2, spfc, true);
		}

		if (chr->actiontype == ACT_SKJUMP
				&& chr->act_skjump.state == SKJUMPSTATE_AIRBORNE
				&& !chr->act_skjump.needsnewanim
				&& g_Vars.lvupdate60 != 0) {
#if VERSION >= VERSION_NTSC_1_0
			if (chr0f01f264(chr, arg2, spfc, yincrement, true)) {
				chr->manground += yincrement;
			}
#else
			if (chr0f01f264(chr, arg2, spfc, yincrement)) {
				chr->manground += yincrement;
				arg2->y += yincrement;
			}
#endif

			chr->sumground = chr->manground * (PAL ? 8.4175090789795f : 9.999998f);
			chr->ground = chr->manground;
			arg2->y -= chr->manground;
		} else {
			struct coord *sp98;
			s16 *sp94;
			struct coord sp88;
			s16 sp78[8];
			f32 ground;
			struct modelnode *node;
			u16 nodetype;
			f32 sp68;
			u8 die;

			if (chr->onladder) {
#if VERSION >= VERSION_NTSC_1_0
				if (chr0f01f264(chr, arg2, spfc, yincrement, true)) {
					chr->manground += yincrement;
				}
#else
				if (chr0f01f264(chr, arg2, spfc, yincrement)) {
					chr->manground += yincrement;
					arg2->y += yincrement;
				}
#endif

				chr->sumground = chr->manground * (PAL ? 8.4175090789795f : 9.999998f);
				chr->ground = chr->manground;
				arg2->y -= chr->manground;
			} else {
				if (race == RACE_EYESPY) {
					ground = chr->manground;
				} else if (prop->type == PROPTYPE_PLAYER) {
					struct player *player = g_Vars.players[playermgrGetPlayerNumByProp(prop)];
					ground = player->vv_manground;
					chr->floorcol = player->floorcol;
					chr->floortype = player->floortype;
				} else {
					if (arg2->y - manground < 69.0f) {
						sp98 = &sp88;
						sp94 = sp78;

						sp88.x = arg2->x;
						sp88.y = manground + 69.0f;
						sp88.z = arg2->z;

						func0f065e74(arg2, spfc, &sp88, sp78);
						chr0f021fa8(chr, &sp88, sp78);
					} else {
						sp98 = arg2;
						sp94 = spfc;
					}

					ground = cdFindGroundInfoAtCyl(sp98, chr->radius, sp94,
							&chr->floorcol, &chr->floortype, &floorflags, &chr->floorroom, &inlift, &lift);

#if VERSION >= VERSION_NTSC_1_0
					if (chr->aibot
							&& chr->aibot->unk078 == 0
							&& ground < -100000
							&& g_Vars.lvupdate60 >= 5
							&& (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) == 0) {
						chr->aibot->unk078 = 10;

						*arg2 = prop->pos;

						roomsCopy(prop->rooms, spfc);

						lvupdate60freal = 0.0f;

						ground = cdFindGroundInfoAtCyl(arg2, chr->radius, spfc, &chr->floorcol, &chr->floortype, &floorflags, &chr->floorroom, &inlift, &lift);
					}
#endif

					if (inlift) {
						chr->inlift = true;
						chr->lift = lift;
					} else {
						chr->inlift = false;
						chr->lift = NULL;
					}

					if (ground < -100000) {
						ground = -100000;
					}
				}

				chr->ground = ground;

				if (chr->chrflags & CHRCFLAG_00000001) {
					node = model->filedata->rootnode;
					nodetype = (u8)node->type;

					arg2->y += yincrement + chr->ground - manground;

					chr->chrflags &= ~CHRCFLAG_00000001;
					chr->manground = chr->ground;
					chr->sumground = chr->ground * (PAL ? 8.4175090789795f : 9.999998f);

					manground = chr->manground;

					if (nodetype == MODELNODETYPE_CHRINFO) {
						union modelrwdata *rwdata = modelGetNodeRwData(model, node);
						rwdata->chrinfo.unk34.y = rwdata->chrinfo.unk24.y;
					}
				} else {
					if (chr->fallspeed.y != 0.0f || chr->ground < chr->manground) {
						die = false;

						if (prop->type == PROPTYPE_CHR && chr->manground <= -30000) {
							die = true;
						}

						sp68 = chr->fallspeed.y;

						func0f0965e4(&yincrement, &sp68, VAR(lvupdate60freal));

#if VERSION >= VERSION_NTSC_1_0
						if (chr0f01f264(chr, arg2, spfc, yincrement, false))
#else
						if (chr0f01f264(chr, arg2, spfc, yincrement))
#endif
						{
							chr->manground += yincrement;
							chr->fallspeed.y = sp68;
						}

						if (chr->manground <= chr->ground) {
							chr->manground = chr->ground;
							chr->sumground = chr->ground * (PAL ? 8.4175090789795f : 9.999998f);
							chr->fallspeed.y = 0.0f;

							if (floorflags & GEOFLAG_DIE) {
								die = true;
							}
						}

						if (die) {
							if (chr->aibot) {
								s32 shooter;

								if (chr->lastshooter >= 0 && chr->timeshooter > 0) {
									shooter = chr->lastshooter;
								} else {
									shooter = mpPlayerGetIndex(chr);
								}

								chrDie(chr, shooter);
							} else {
								chr->hidden |= CHRHFLAG_REAPED;
							}
						}
					} else if (chr->manground <= chr->ground) {
						for (i = 0; i < g_Vars.lvupdate60; i++) {
							chr->sumground = chr->sumground * (PAL ? 0.88120001554489f : 0.9f) + chr->ground;
							chr->fallspeed.x *= (PAL ? 0.88120001554489f : 0.9f);
							chr->fallspeed.z *= (PAL ? 0.88120001554489f : 0.9f);
						}

						chr->manground = chr->sumground * (PAL ? 0.11879998445511f : 0.10000002384186f);

						if (chr->manground < chr->ground - 30.0f) {
							chr->manground = chr->ground - 30.0f;
							chr->sumground = (chr->ground - 30.0f) * (PAL ? 8.4175090789795f : 9.999998f);
						}

						if (chr->fallspeed.x < 0.1f && chr->fallspeed.x > -0.1f) {
							if (chr->fallspeed.z < 0.1f && chr->fallspeed.z > -0.1f) {
								chr->fallspeed.z = 0.0f;
								chr->fallspeed.x = 0.0f;
							}
						}
					}

#if VERSION >= VERSION_NTSC_1_0
					if (manground != chr->manground) {
						spd0 = *arg2;

						roomsCopy(spfc, spc0);

						arg2->y += chr->manground - manground;

						func0f065e74(&spd0, spc0, arg2, spfc);
						chr0f021fa8(chr, arg2, spfc);
					}
#endif
				}

#if VERSION < VERSION_NTSC_1_0
				arg2->y += chr->manground - manground;
#endif
				arg2->y -= chr->manground;
			}
		}
	}

	*mangroundptr = chr->manground;

	prop->pos.x = arg2->x;
	prop->pos.y = arg2->y + chr->manground;
	prop->pos.z = arg2->z;

	if (chr->actiontype == ACT_SKJUMP) {
#if VERSION >= VERSION_NTSC_1_0
		f32 ground;
#endif

		ground = chr->act_skjump.ground;

		if (prop->pos.y < ground) {
			prop->pos.y = ground;
			chr->manground = chr->act_skjump.ground;
			*mangroundptr = chr->act_skjump.ground;
		}
	}

	propDeregisterRooms(prop);
	roomsCopy(spfc, prop->rooms);

#if VERSION >= VERSION_NTSC_1_0
	if (prop->type == PROPTYPE_CHR) {
		for (i = 0; prop->rooms[i] != -1; i++) {
			if (chr->floorroom == prop->rooms[i]) {
				propDeregisterRooms(prop);
				prop->rooms[0] = chr->floorroom;
				prop->rooms[1] = -1;
				break;
			}
		}
	}
#endif

	chr0f0220ac(chr);
	propCalculateShadeColour(prop, chr->nextcol, chr->floorcol);

	return true;
}

s32 chrsGetNumFree(void)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].chrnum < 0) {
			count++;
		}
	}

	return count;
}

void chrSetMaxDamage(struct chrdata *chr, f32 maxdamage)
{
	chr->maxdamage = maxdamage;
}

f32 chrGetMaxDamage(struct chrdata *chr)
{
	return chr->maxdamage;
}

void chrAddHealth(struct chrdata *chr, f32 health)
{
	chr->damage -= health;
}

f32 chrGetArmor(struct chrdata *chr)
{
	if (chr->damage < 0) {
		return -chr->damage;
	}

	return 0;
}

s16 chrsGetNextUnusedChrnum(void)
{
	s32 chrnum;
	struct chrdata *chr;

	do {
		chrnum = ++g_NextChrnum;

		if (chrnum >= ARRAYCOUNT(g_ChrIndexesByChrnum)) {
			chrnum = g_NextChrnum = 200;
		}

		chr = chrFindByLiteralId((s16)chrnum);
	} while (chr);

	return chrnum;
}

void chrInit(struct prop *prop, u8 *ailist)
{
	s32 i;
	struct chrdata *chr = NULL;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].chrnum < 0) {
			chr = &g_ChrSlots[i];
			break;
		}
	}

	prop->chr = chr;
	chr->chrnum = chrsGetNextUnusedChrnum();
	chrRegister(chr->chrnum, i);

	chr->headnum = 0;
	chr->bodynum = 0;
	chr->prop = prop;
	chr->model = NULL;
	chr->numarghs = 0;
	chr->lastwalk60 = 0;
	chr->invalidmove = 0;
	chr->lastmoveok60 = g_Vars.lvframe60;
	chr->visionrange = 250;

	if (cheatIsActive(CHEAT_PERFECTDARKNESS)) {
		chr->visionrange = 4;
	}

	chr->shotbondsum = 0;
	chr->damage = 0;
	chr->sumground = 0;
	chr->manground = 0;
	chr->ground = 0;
	chr->fallspeed.x = 0;
	chr->fallspeed.y = 0;
	chr->fallspeed.z = 0;
	chr->prevpos.x = 0;
	chr->prevpos.y = 0;
	chr->prevpos.z = 0;
	chr->hearingscale = 1;
	chr->maxdamage = 4;

	chr->lastseetarget60 = 0;
	chr->lastvisibletarget60 = 0;
	chr->lastheartarget60 = 0;
	chr->numclosearghs = 0;
	chr->shadecol[0] = chr->nextcol[0] = 0xff;
	chr->shadecol[1] = chr->nextcol[1] = 0xff;
	chr->shadecol[2] = chr->nextcol[2] = 0xff;
	chr->shadecol[3] = chr->nextcol[3] = 0xff;
	chr->floorcol = 0x0fff;
	chr->floortype = 0;
	chr->floorroom = -1;
	chr->fadealpha = 0xff;

	chr->chrflags = CHRCFLAG_00000001;
	chr->hidden = 0;
	chr->hidden2 = 0;
	chr->actiontype = ACT_INIT;
	chr->sleep = 0;

	chr->ailist = ailist;
	chr->aioffset = ailist;
	chr->aireturnlist = NULL;
	chr->aishotlist = NULL;
	chr->aipunchdodgelist = NULL;
	chr->aishootingatmelist = NULL;
	chr->aidarkroomlist = NULL;

	chr->radius = 20;
	chr->height = 185;
	chr->morale = 0;
	chr->alertness = 0;
	chr->flags = 0;
	chr->random = 0;
	chr->timer60 = 0;
	chr->soundtimer = 0;
	chr->soundgap = 0;
	chr->talkgap = 0;
	chr->padpreset1 = -1;
	chr->proppreset1 = -1;
	chr->chrseeshot = -1;
	chr->chrseedie = -1;
	chr->chrpreset1 = -1;
	chr->chrdup = -1;
	chr->firecount[0] = 0;
	chr->firecount[1] = 0;

	chr->darkroomthing = 0;
	chr->playerdeadthing = 0;
	chr->unk32c_12 = 0;

	chr->grenadeprob = 0;
	chr->accuracyrating = 0;
	chr->speedrating = 0;
	chr->arghrating = 0;
	chr->dodgerating = 0;
	chr->unarmeddodgerating = 0;
	chr->maxdodgerating = 0;
	chr->flinchcnt = -1;
	chr->aimendcount = 0;
	chr->weapons_held[0] = NULL;
	chr->weapons_held[1] = NULL;
	chr->weapons_held[2] = NULL;
	chr->gunprop = NULL;
	chr->fireslots[0] = -1;
	chr->fireslots[1] = -1;

	chr->aimuplshoulder = 0;
	chr->aimuprshoulder = 0;
	chr->aimupback = 0;
	chr->aimsideback = 0;
	chr->aimendlshoulder = 0;
	chr->aimendrshoulder = 0;
	chr->aimendback = 0;
	chr->aimendsideback = 0;

	if (g_Vars.currentplayer->prop == NULL) {
		chr->target = -2;
	} else {
		chr->target = g_Vars.currentplayer->prop - g_Vars.props;
	}

	chr->path = -1;
	chr->team = TEAM_01;
	chrSetShield(chr, 0);
	chr->cmnum = 0;
	chr->cmnum2 = 0;
	chr->cmnum3 = 0;
	chr->cmnum4 = 0;
	chr->cmcount = random() % 300;
	chr->footstep = 0;
	chr->magicanim = -1;
	chr->cover = -1;
	chr->bdstart = 0;
	chr->oldframe = 0;
	chr->magicframe = 0;
	chr->magicspeed = VERSION >= VERSION_PAL_BETA ? 1 : 0.25;

	i = 0;

	while (i != 60) {
		chr->bdlist[i++] = 0;
	}

	chr->talktimer = TICKS(3600);
	chr->cloakfadefrac = 0;
	chr->cloakfadefinished = false;
	chr->inlift = false;
	chr->targetlastseenp.x = 0;
	chr->targetlastseenp.y = 0;
	chr->targetlastseenp.z = 0;
	chr->myaction = MA_NONE;
	chr->orders = MA_NONE;
	chr->squadron = 0;
	chr->listening = 0;
	chr->convtalk = 0;
	chr->question = 0;
	chr->runfrompos.x = 0;
	chr->runfrompos.y = 0;
	chr->runfrompos.z = 0;
	chr->oldrooms[0] = -1;
	chr->aibot = NULL;
	chr->blurdrugamount = 0;
	chr->drugheadsway = 0;
	chr->drugheadcount = 0;
	chr->blurnumtimesdied = 0;
	chr->cloakpause = 0;
	chr->timeextra = 0;
	chr->elapseextra = 0;
	chr->extraspeed.x = 0;
	chr->extraspeed.y = 0;
	chr->extraspeed.z = 0;
	chr->hitpart = 0;
	chr->voicebox = 0;
	chr->pushspeed[0] = 0;
	chr->pushspeed[1] = 0;
	chr->gunroty[0] = 0;
	chr->gunrotx[0] = 0;
	chr->gunroty[1] = 0;
	chr->gunrotx[1] = 0;
	chr->unk348[0] = 0;
	chr->unk348[1] = 0;
	chr->onladder = 0;
	chr->laddernormal.x = 0;
	chr->laddernormal.y = 0;
	chr->laddernormal.z = 0;
	chr->liftaction = 0;
	chr->lift = NULL;
	chr->pouncebits = 0;
	chr->specialdie = 0;
	chr->roomtosearch = 0;
	chr->propsoundcount = 0;
	chr->patrolnextstep = -1;
	chr->p1p2 = g_Vars.bondplayernum;
	chr->lastattacker = NULL;
	chr->race = RACE_HUMAN;
	chr->aimtesttimer60 = random() % TICKS(30);
	chr->lastfootsample = 0;
	chr->poisoncounter = 0;
	chr->poisonprop = NULL;
	chr->lastshooter = -1;
	chr->timeshooter = 0;
	chr->noblood = false;
	chr->rtracked = false;

#if VERSION >= VERSION_NTSC_1_0
	chr->goposhitcount = 0;
#endif

	splatResetChr(chr);
}

struct prop *chr0f020b14(struct prop *prop, struct model *model,
		struct coord *pos, s16 *rooms, f32 faceangle, u8 *ailist)
{
	struct chrdata *chr;
	struct coord testpos;
	f32 ground;
	u32 nodetype;

	prop->type = PROPTYPE_CHR;

	if (prop->chr == NULL) {
		chrInit(prop, ailist);
	}

	chr = prop->chr;

	modelSetAnim70(model, chr0f01f378);
	model->chr = chr;
	model->unk01 = 1;
	chr->model = model;
	chrSetLookAngle(chr, faceangle);
	modelSetAnimPlaySpeed(model, PALUPF(var80062968), 0);

	testpos.x = pos->x;
	testpos.y = pos->y + 100;
	testpos.z = pos->z;

	chr->ground = chr->manground = ground = cdFindGroundInfoAtCyl(&testpos, chr->radius, rooms, &chr->floorcol, &chr->floortype, NULL, &chr->floorroom, NULL, NULL);

	chr->sumground = ground * (PAL ? 8.4175090789795f : 9.999998f);

	prop->pos.x = testpos.x;
	prop->pos.y = ground + 100;
	prop->pos.z = testpos.z;

	propDeregisterRooms(prop);
	roomsCopy(rooms, prop->rooms);
	chr0f0220ac(chr);
	modelSetRootPosition(model, &prop->pos);

	nodetype = chr->model->filedata->rootnode->type;

	if ((nodetype & 0xff) == MODELNODETYPE_CHRINFO) {
		union modelrwdata *rwdata = modelGetNodeRwData(chr->model, chr->model->filedata->rootnode);
		rwdata->chrinfo.ground = ground;
	}

	chr->prevpos = prop->pos;

	propCalculateShadeColour(prop, chr->nextcol, chr->floorcol);

	return prop;
}

struct prop *chrAllocate(struct model *model, struct coord *pos, s16 *rooms, f32 faceangle, u8 *ailist)
{
	struct prop *prop = propAllocate();

	if (prop) {
		prop = chr0f020b14(prop, model, pos, rooms, faceangle, ailist);

		if (cheatIsActive(CHEAT_ENEMYSHIELDS)) {
			chrSetShield(prop->chr, 8);
		}
	}

	return prop;
}

/**
 * Removes a chr. If delete is true, deallocates the chr completely.
 */
void chrRemove(struct prop *prop, bool delete)
{
	struct chrdata *chr = prop->chr;
	struct model *model = chr->model;
	struct defaultobj *eyespyobj = NULL;
	struct prop *child;
	u32 stack[2];

	bgunFreeFireslotWrapper(chr->fireslots[0]);
	bgunFreeFireslotWrapper(chr->fireslots[1]);

	if (chr->proppreset1 >= 0) {
		struct prop *proppreset = &g_Vars.props[chr->proppreset1];
		struct defaultobj *chair = proppreset->obj;
		chair->hidden &= ~OBJHFLAG_OCCUPIEDCHAIR;
	}

	wallhitFadeSplatsForRemovedChr(prop);
	func0f0926bc(prop, 1, 0xffff);
	shieldhitsRemoveByProp(prop);
	modelFreeVertices(VTXSTORETYPE_CHRVTX, model);
	propDeregisterRooms(prop);

	if (g_Vars.stagenum == STAGE_CITRAINING) {
		eyespyobj = objFindByTagId(0x26);
	}

	child = prop->child;

	while (child) {
		struct defaultobj *obj = child->obj;
		struct prop *next = child->next;

		if ((obj->hidden & OBJHFLAG_HASTEXTOVERRIDE) == 0
				&& obj != eyespyobj
				&& (prop->type != PROPTYPE_PLAYER || (obj->flags3 & OBJFLAG3_PLAYERUNDROPPABLE) == 0)) {
			objDetach(child);
			objFreePermanently(obj, true);
		}

		child = next;
	}

	modelmgrFreeModel(model);
	chr->model = NULL;

	if (delete) {
		chrDeregister(chr->chrnum);

		if (chr->cover != -1) {
			coverSetInUse(chr->cover, false);
			chr->cover = -1;
		}

		chrClearReferences(prop - g_Vars.props);
		projectilesUnrefOwner(prop);

		if (g_Vars.normmplayerisrunning == false && g_MissionConfig.iscoop) {
			s32 i;

			for (i = 0; i < g_Vars.numaibuddies && i < 4; i++) {
				if (g_Vars.aibuddies[i] == prop) {
					g_Vars.aibuddies[i] = NULL;
				}
			}
		}

		chr->chrnum = -1;

		rebuildTeams();
		rebuildSquadrons();
	}
}

void chrClearReferences(s32 propnum)
{
	s32 i;
	s32 j;
	struct prop *prop = &g_Vars.props[propnum];

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].target == propnum) {
			if (propGetIndexByChrId(&g_ChrSlots[i], g_ChrSlots[i].chrpreset1) == propnum) {
				g_ChrSlots[i].chrpreset1 = -1;
			}

			g_ChrSlots[i].target = -1;
		}
	}

	for (i = 0; i < PLAYERCOUNT(); i++) {
		if (g_Vars.players[i]->lookingatprop.prop == prop) {
			g_Vars.players[i]->lookingatprop.prop = NULL;
		}

		for (j = 0; j != 4; j++) {
			if (g_Vars.players[i]->trackedprops[j].prop == prop) {
				g_Vars.players[i]->trackedprops[j].prop = NULL;
			}
		}
	}
}

void chr0f0211a8(f32 arg0)
{
	s32 i;

	var80062968 = arg0;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].model) {
			modelSetAnimPlaySpeed(g_ChrSlots[i].model, PALUPF(var80062968), 600);
		}
	}
}

f32 chr0f02124c(void)
{
	return var80062968;
}

void chrUpdateAimProperties(struct chrdata *chr)
{
	if (chr->aimendcount >= 2) {
		f32 mult = g_Vars.lvupdate60f / chr->aimendcount;

		if (mult > 1) {
			mult = 1;
		}

		chr->aimuplshoulder += (chr->aimendlshoulder - chr->aimuplshoulder) * mult;
		chr->aimuprshoulder += (chr->aimendrshoulder - chr->aimuprshoulder) * mult;
		chr->aimupback += (chr->aimendback - chr->aimupback) * mult;
		chr->aimsideback += (chr->aimendsideback - chr->aimsideback) * mult;

		chr->aimendcount -= g_Vars.lvupdate60;
	} else {
		chr->aimuplshoulder = chr->aimendlshoulder;
		chr->aimuprshoulder = chr->aimendrshoulder;
		chr->aimupback = chr->aimendback;
		chr->aimsideback = chr->aimendsideback;
	}
}

void chrFlinchBody(struct chrdata *chr)
{
	if (chr->actiontype != ACT_DEAD && chr->flinchcnt < 0) {
		chr->flinchcnt = 1;
		chr->hidden2 &= 0x0fff;
		chr->hidden2 |= (u16)(random() << 13);
	}
}

void chrFlinchHead(struct chrdata *chr, f32 arg1)
{
	s32 value;

	if (chr->flinchcnt < 0) {
		chr->flinchcnt = 1;
	} else if (chr->flinchcnt > 8) {
		chr->flinchcnt = 4;
	}

	chr->hidden2 &= 0x0fff;
	chr->hidden2 |= CHRH2FLAG_HEADSHOTTED;
	value = (arg1 + 0.3926365673542f) * 8.0f / M_BADTAU;

	if (value < 0) {
		value = 0;
	}

	if (value > 7) {
		value = 7;
	}

	chr->hidden2 |= value << 13;
}

f32 chrGetFlinchAmount(struct chrdata *chr)
{
	f32 value = chr->flinchcnt;

	if (chr->hidden2 & CHRH2FLAG_HEADSHOTTED) {
		if (value < 4) {
			value = sinf(value * 1.5705462694168f / 4);
		} else {
			value = 1 - sinf((value - 4) * (PAL ? 0.07478791475296f : 0.060405626893044f));
		}
	} else {
		if (value < TICKS(10)) {
			value = sinf(value * 1.5705462694168f / TICKS(10));
		} else {
			value = 1 - sinf((value - TICKS(10)) * (PAL ? 0.098159141838551f : 0.078527316451073f));
		}
	}

	return value;
}

/**
 * This is a callback function that is called by model code after the model's
 * animation has done its positioning. It allows tweaks to be made to the model
 * at particular joints such as changing the angle and scale.
 *
 * The function is called multiple times per model per frame, with the joint
 * argument changing each time.
 *
 * This function implements the following features:
 * - Chicago robot gun angles
 * - DK mode
 * - Head flinching when shot
 * - Body flinching when shot
 * - Chrs aiming up, down, left and right
 */
void chrHandleJointPositioned(s32 joint, Mtxf *mtx)
{
	f32 scale = 1.0f;
	s32 lshoulderjoint;
	s32 rshoulderjoint;
	s32 waistjoint;
	s32 neckjoint;
	struct coord sp138;
	Mtxf spf8;
	Mtxf spb8;
	f32 gunroty;
	f32 gunrotx;
	f32 theta;
	f32 gunrot;

	// chr is facing into the Z axis
	f32 xrot; // eg. bending over or nodding head
	f32 yrot; // eg. twist left/right or shaking head
	f32 zrot; // eg. cartwheeling

	if (g_CurModelChr->model->filedata->skel == &g_SkelRobot) {
		// Handle Chicago robot guns
		theta = chrGetInverseTheta(g_CurModelChr);

		if (joint == 1) {
			gunrotx = g_CurModelChr->gunrotx[0];
			gunroty = g_CurModelChr->gunroty[0];
		} else if (joint == 2) {
			gunrotx = g_CurModelChr->gunrotx[1];
			gunroty = g_CurModelChr->gunroty[1];
		} else {
			return;
		}

		mtx00015be0(camGetProjectionMtxF(), mtx);

		sp138.x = mtx->m[3][0];
		sp138.y = mtx->m[3][1];
		sp138.z = mtx->m[3][2];

		mtx->m[3][0] = 0.0f;
		mtx->m[3][1] = 0.0f;
		mtx->m[3][2] = 0.0f;

		if (gunrotx < 0.0f) {
			gunrotx += M_BADTAU;
		}

		if (gunroty < 0.0f) {
			gunroty += M_BADTAU;
		}

		gunrot = M_BADTAU - theta + 1.5707963705063f;

		if (gunrot >= M_BADTAU) {
			gunrot -= M_BADTAU;
		}

		mtx4LoadYRotation(gunrot, &spb8);
		mtx00015be0(&spb8, mtx);
		mtx4LoadXRotation(gunrotx, &spf8);
		mtx00015be0(&spf8, mtx);

		gunrot = gunroty + theta;

		if (gunrot >= M_BADTAU) {
			gunrot -= M_BADTAU;
		}

		mtx4LoadYRotation(gunrot, &spb8);
		mtx00015be0(&spb8, mtx);

		if (scale != 1.0f) {
			mtx00015f04(scale, mtx);
		}

		mtx->m[3][0] = sp138.x;
		mtx->m[3][1] = sp138.y;
		mtx->m[3][2] = sp138.z;

		mtx00015be0(camGetWorldToScreenMtxf(), mtx);
	} else {
		if (g_CurModelChr->model->filedata->skel == &g_SkelChr) {
			lshoulderjoint = 2;
			rshoulderjoint = 3;
			waistjoint = 1;
			neckjoint = 0;
		} else if (g_CurModelChr->model->filedata->skel == &g_SkelSkedar) {
			lshoulderjoint = 3;
			rshoulderjoint = 4;
			waistjoint = 2;
			neckjoint = 1;
		} else {
			lshoulderjoint = -1;
			rshoulderjoint = -1;
			waistjoint = -1;
			neckjoint = -1;
		}

		if (cheatIsActive(CHEAT_DKMODE) && CHRRACE(g_CurModelChr) == RACE_HUMAN) {
			if (joint == neckjoint) {
				scale = 4.0f;
			} else if (joint == lshoulderjoint || joint == rshoulderjoint) {
				scale = 2.5f;
			}
		}

		if (joint == lshoulderjoint || joint == rshoulderjoint || joint == waistjoint || joint == neckjoint) {
			xrot = 0.0f;
			yrot = 0.0f;
			zrot = 0.0f;

			// Apply rotation based on chr's aiming properties
			if (joint == rshoulderjoint) {
				xrot = g_CurModelChr->aimuprshoulder;
			} else if (joint == lshoulderjoint) {
				xrot = g_CurModelChr->aimuplshoulder;
			} else if (joint == waistjoint) {
				// Up/down at the waist
				xrot = g_CurModelChr->aimupback;

				if (g_CurModelChr->hidden2 & CHRH2FLAG_0004) {
					if (xrot > 1.0470308065414f) {
						xrot -= 1.0470308065414f;
					} else if (xrot < -0.87252569198608f) {
						xrot += 0.87252569198608f;
					} else {
						xrot = 0.0f;
					}
				}

				// Left/right at the waist
				yrot = g_CurModelChr->aimsideback;

				if (g_CurModelChr->aibot) {
					yrot += g_CurModelChr->aibot->angleoffset;
				} else if (g_CurModelChr->prop->type == PROPTYPE_PLAYER) {
					yrot += g_Vars.players[playermgrGetPlayerNumByProp(g_CurModelChr->prop)]->angleoffset;
				}
			} else if (joint == neckjoint) {
				// Head up/down
				if (g_CurModelChr->hidden2 & CHRH2FLAG_0004) {
					xrot = g_CurModelChr->aimupback;

					if (xrot > 1.0470308065414f) {
						xrot = 1.0470308065414f;
					} else if (xrot < -0.87252569198608f) {
						xrot = -0.87252569198608f;
					}
				} else if (g_CurModelChr->model->anim->flip) {
					xrot = g_CurModelChr->aimuplshoulder;
				} else {
					xrot = g_CurModelChr->aimuprshoulder;
				}

				// Apply head bobbing when dizzy
				if (g_CurModelChr->blurdrugamount > TICKS(1000)
						&& g_Vars.tickmode != TICKMODE_CUTSCENE
						&& g_CurModelChr->actiontype != ACT_DEAD
						&& g_CurModelChr->actiontype != ACT_DIE) {
					zrot = g_CurModelChr->drugheadsway / 360.0f * M_BADTAU;
					xrot -= (28.0f - ABS(g_CurModelChr->drugheadsway)) / 250.0f * M_BADTAU;
				}
			}

			// Apply flinch when chr is shot
			if (g_CurModelChr->flinchcnt >= 0
					&& (CHRRACE(g_CurModelChr) == RACE_HUMAN || CHRRACE(g_CurModelChr) == RACE_SKEDAR)) {
				bool isskedar = CHRRACE(g_CurModelChr) == RACE_SKEDAR;

				if (g_CurModelChr->hidden2 & CHRH2FLAG_HEADSHOTTED) {
					if (joint == neckjoint) {
						f32 flinchamount = chrGetFlinchAmount(g_CurModelChr);
						s32 flinchtype = (g_CurModelChr->hidden2 >> 13) & 7;
						f32 mult = isskedar ? 25.0f : 60.0f;

						if ((flinchtype & 1) == 0) {
							mult = isskedar ? 37.5f : 85.0f;
						}

						if (flinchtype >= 5 && flinchtype < 8) {
							zrot -= flinchamount * (M_BADTAU * mult / 360.0f);
						} else if (flinchtype > 0 && flinchtype < 4) {
							zrot += flinchamount * (M_BADTAU * mult / 360.0f);
						}

						if (flinchtype == 7 || flinchtype == 0 || flinchtype == 1) {
							xrot += flinchamount * (M_BADTAU * mult / 360.0f);
						} else if (flinchtype >= 3 && flinchtype < 6) {
							xrot -= flinchamount * (M_BADTAU * mult / 360.0f);
						}
					}
				} else if (joint == rshoulderjoint || joint == lshoulderjoint) {
					s32 flinchtype = (g_CurModelChr->hidden2 >> 13) & 7;
					f32 flinchamount = chrGetFlinchAmount(g_CurModelChr) * 0.26175770163536f;

					xrot -= flinchamount;

					if (flinchtype < 3) {
						yrot -= flinchamount;
					} else if (flinchtype >= 3 && flinchtype < 6) {
						yrot += flinchamount;
					}
				} else if (joint == waistjoint) {
					f32 flinchamount;
					s32 flinchtype;

					flinchamount = chrGetFlinchAmount(g_CurModelChr);
					flinchtype = (g_CurModelChr->hidden2 >> 13) & 7;

					xrot += flinchamount * 0.26175770163536f;

					if (flinchtype < 3) {
						yrot += flinchamount * 0.26175770163536f;
					} else if (flinchtype >= 3 && flinchtype < 6) {
						yrot -= flinchamount * 0.26175770163536f;
					}

					if (flinchtype == 2 || flinchtype == 5 || flinchtype == 7) {
						zrot += flinchamount * 0.17450514435768f;
					} else if (flinchtype == 1 || flinchtype == 4 || flinchtype == 6) {
						zrot -= flinchamount * 0.17450514435768f;
					}
				}
			}

			if (xrot != 0.0f || yrot != 0.0f || zrot != 0.0f || scale != 1.0f) {
				struct coord sp70;
				f32 aimangle;
				Mtxf tmpmtx;

				aimangle = chrGetAimAngle(g_CurModelChr);

				if (xrot < 0.0f) {
					xrot = -xrot;
				} else {
					xrot = M_BADTAU - xrot;
				}

				if (yrot < 0.0f) {
					yrot += M_BADTAU;
				}

				mtx00015be0(camGetProjectionMtxF(), mtx);

				sp70.x = mtx->m[3][0];
				sp70.y = mtx->m[3][1];
				sp70.z = mtx->m[3][2];

				mtx->m[3][0] = 0.0f;
				mtx->m[3][1] = 0.0f;
				mtx->m[3][2] = 0.0f;

				if (xrot != 0.0f || zrot != 0.0f) {
					yrot -= aimangle;

					if (yrot < 0.0f) {
						yrot += M_BADTAU;
					}

					mtx4LoadYRotation(yrot, &tmpmtx);
					mtx00015be0(&tmpmtx, mtx);

					if (xrot != 0.0f) {
						mtx4LoadXRotation(xrot, &tmpmtx);
						mtx00015be0(&tmpmtx, mtx);
					}

					if (zrot != 0.0f) {
						mtx4LoadZRotation(zrot, &tmpmtx);
						mtx00015be0(&tmpmtx, mtx);
					}

					mtx4LoadYRotation(aimangle, &tmpmtx);
					mtx00015be0(&tmpmtx, mtx);
				} else {
					mtx4LoadYRotation(yrot, &tmpmtx);
					mtx00015be0(&tmpmtx, mtx);
				}

				if (scale != 1.0f) {
					mtx00015f04(scale, mtx);
				}

				mtx->m[3][0] = sp70.x;
				mtx->m[3][1] = sp70.y;
				mtx->m[3][2] = sp70.z;

				mtx00015be0(camGetWorldToScreenMtxf(), mtx);
			}
		}
	}
}

void chr0f021fa8(struct chrdata *chr, struct coord *pos, s16 *rooms)
{
	struct coord lower;
	struct coord upper;
	f32 height = 110;

	if (
#if VERSION >= VERSION_NTSC_1_0
			chr && chr->race == RACE_EYESPY
#else
			chr->race == RACE_EYESPY
#endif
			) {
		struct eyespy *eyespy = chrToEyespy(chr);

		if (eyespy) {
			height = eyespy->height + 30.0f;
		} else {
			height = 230;
		}
	}

	lower.x = pos->x - 50.0f;
	lower.y = pos->y - height;
	lower.z = pos->z - 50.0f;

	upper.x = pos->x + 50.0f;
	upper.y = pos->y + height;
	upper.z = pos->z + 50.0f;

	bgFindEnteredRooms(&lower, &upper, rooms, 7, true);
}

void chr0f022084(struct chrdata *chr, s16 *room)
{
	chr0f021fa8(chr, &chr->prop->pos, room);
}

void chr0f0220ac(struct chrdata *chr)
{
	propDeregisterRooms(chr->prop);
	chr0f022084(chr, chr->prop->rooms);
	propRegisterRooms(chr->prop);
}

void chr0f0220ec(struct chrdata *chr, s32 arg1, s32 arg2)
{
	struct model *model = chr->model;

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			chr->hidden &= ~CHRHFLAG_00000800;
		}

		if (model->anim
				&& (g_Anims[model->anim->animnum].flags & ANIMFLAG_02)
				&& arg1 > 0
				&& g_Vars.cutsceneskip60ths > 0) {
			arg1 += g_Vars.cutsceneskip60ths * 4;
		}
	}

	if (chr->chrflags & CHRCFLAG_20000000) {
		chr->chrflags &= ~CHRCFLAG_20000000;
	} else if (arg2) {
		if ((chr->hidden & CHRHFLAG_00000800) == 0) {
			modelGetRootPosition(model, &chr->prevpos);
			model0001ee18(model, arg1, 1);
			model0001b3bc(model);
		}
	} else {
		model0001ee18(model, arg1, 0);
	}
}

void chr0f022214(struct chrdata *chr, struct prop *prop, bool fulltick)
{
	struct defaultobj *obj = prop->obj;
	struct model *model = obj->model;
	struct prop *child;
	struct prop *next;

	if (obj->hidden & OBJHFLAG_REAPABLE) {
		objFree(obj, true, obj->hidden2 & OBJH2FLAG_CANREGEN);
		return;
	}

	if (model->attachedtomodel && model->attachedtonode
			&& (obj->hidden & OBJHFLAG_00000800) == 0
			&& (obj->flags2 & OBJFLAG2_INVISIBLE) == 0) {
		Mtxf *sp104 = model0001a5cc(model->attachedtomodel, model->attachedtonode, 0);
		struct modelrenderdata thing = {NULL, 1, 3};
		u32 stack;
		Mtxf sp80;
		Mtxf sp40;

		prop->flags |= PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK;

		if (obj->hidden & OBJHFLAG_EMBEDDED) {
			mtx00015be4(sp104, &obj->embedment->matrix, &sp80);
			thing.unk00 = &sp80;
		} else if (CHRRACE(chr) == RACE_SKEDAR) {
			// The skedar hand position is rotated weirdly, so compensate for it
			mtx4LoadYRotation(1.3192588090897f, &sp80);
			mtx4LoadZRotation(1.5705462694168f, &sp40);
			mtx4MultMtx4InPlace(&sp40, &sp80);
			mtx4MultMtx4InPlace(sp104, &sp80);
			thing.unk00 = &sp80;
		} else if (prop == chr->weapons_held[HAND_LEFT]) {
			// Flip the model
			mtx4LoadZRotation(M_BADPI, &sp80);
			mtx4MultMtx4InPlace(sp104, &sp80);
			thing.unk00 = &sp80;
		} else {
			thing.unk00 = sp104;
		}

		thing.unk10 = gfxAllocate(model->filedata->nummatrices * sizeof(Mtxf));
		model0001ce64(&thing, model);

		func0f07063c(prop, fulltick);

		child = prop->child;

		while (child) {
			if (prop);
			if (prop);

			next = child->next;
			chr0f022214(chr, child, fulltick);
			child = next;
		}
	} else {
		prop->flags &= ~PROPFLAG_ONTHISSCREENTHISTICK;

		func0f07063c(prop, fulltick);

		child = prop->child;

		while (child) {
			next = child->next;
			func0f0706f8(child, fulltick);
			child = next;
		}
	}
}

void chrCloak(struct chrdata *chr, bool value)
{
	if (!chrIsDead(chr)) {
		chr->hidden |= CHRHFLAG_CLOAKED;

		if (value) {
			propsnd0f0939f8(0, chr->prop, SFX_CLOAK_ON, -1, -1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
		}
	}
}

void chrUncloak(struct chrdata *chr, bool value)
{
	if (chr->hidden & CHRHFLAG_CLOAKED) {
		chr->hidden &= ~CHRHFLAG_CLOAKED;

		if (value) {
			propsnd0f0939f8(0, chr->prop, SFX_CLOAK_OFF, -1, -1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
		}

#if PIRACYCHECKS
		{
			u32 checksum = 0;
			u32 *i = (u32 *)&botPickupProp;
			u32 *end = (u32 *)&botTestPropForPickup;

			while (i < end) {
				checksum += ~*i;
				i++;
			}

			if (checksum != CHECKSUM_PLACEHOLDER) {
				((u32 *)&cdReturnZero)[-2] = 0;
			}
		}
#endif
	}
}

void chrUncloakTemporarily(struct chrdata *chr)
{
	chrUncloak(chr, true);
	chr->cloakpause = TICKS(120);
}

void chrUpdateCloak(struct chrdata *chr)
{
	s32 qty;
	s32 ammotype;
	u32 prevplayernum;
	f32 fVar14;
	s32 fadefrac;

	// Decrement cloakpause
	if (chr->cloakpause > 0) {
		chr->cloakpause -= g_Vars.lvupdate60;

		if (chr->cloakpause < 1) {
			chr->cloakpause = 0;
		}
	}

	// Handle ammo decrease and determine if cloak is still enabled
	if (chr->aibot) {
		if (chr->aibot->cloakdeviceenabled) {
			qty = chr->aibot->ammoheld[AMMOTYPE_CLOAK];

			if (qty > 0 && !chrIsDead(chr)) {
				if (chr->hidden & CHRHFLAG_CLOAKED) {
					qty -= g_Vars.lvupdate60;

					if (qty <= 0) {
						qty = 0;
					}

					chr->aibot->ammoheld[AMMOTYPE_CLOAK] = qty;
				}
			} else {
				chr->aibot->cloakdeviceenabled = false;
			}
		} else if (chr->aibot->rcp120cloakenabled) {
			if (chr->aibot->weaponnum == WEAPON_RCP120
					&& !chrIsDead(chr)
					&& botactGetAmmoQuantityByWeapon(chr->aibot, WEAPON_RCP120, 0, 1) > 0) {
				if (chr->hidden & CHRHFLAG_CLOAKED) {
					chr->aibot->unk2c4 += LVUPDATE60FREAL() * 0.4f;

					if (chr->aibot->unk2c4 >= 1) {
						qty = chr->aibot->unk2c4;
						chr->aibot->unk2c4 -= qty;

						if (chr->aibot->loadedammo[0] > 0) {
							chr->aibot->loadedammo[0] -= qty;

							if (chr->aibot->loadedammo[0] <= 0) {
								chr->aibot->loadedammo[0] = 0;
							}
						} else {
							ammotype = botactGetAmmoTypeByFunction(WEAPON_RCP120, 0);

							if (chr->aibot->ammoheld[ammotype] > 0) {
								chr->aibot->ammoheld[ammotype] -= qty;

								if (chr->aibot->ammoheld[ammotype] <= 0) {
									chr->aibot->ammoheld[ammotype] = 0;
								}
							}
						}
					}
				}
			} else {
				chr->aibot->rcp120cloakenabled = false;
			}
		}

		if (chr->aibot->cloakdeviceenabled || chr->aibot->rcp120cloakenabled) {
			if ((chr->hidden & CHRHFLAG_CLOAKED) == 0) {
				if (chr->cloakpause < 1) {
					chrCloak(chr, true);
				}
			}
		} else if (chr->hidden & CHRHFLAG_CLOAKED) {
			chrUncloak(chr, true);
		}
	} else if (chr->prop->type == PROPTYPE_PLAYER) {
		prevplayernum = g_Vars.currentplayernum;
		setCurrentPlayerNum(playermgrGetPlayerNumByProp(chr->prop));

		if (g_Vars.currentplayer->devicesactive & DEVICE_CLOAKDEVICE) {
			// Cloak is active - but may or may not be in effect due to recent shooting
			s32 qty = bgunGetReservedAmmoCount(AMMOTYPE_CLOAK);

			if (qty > 0) {
				if (chr->hidden & CHRHFLAG_CLOAKED) {
					// Cloak is effective
					qty -= g_Vars.lvupdate60;

					if (qty < 1) {
						qty = 0;
					}

					bgunSetAmmoQuantity(AMMOTYPE_CLOAK, qty);
				}
			} else {
				// Out of cloak ammo - turn off cloak
				g_Vars.currentplayer->devicesactive &= ~DEVICE_CLOAKDEVICE;
			}
		}

		// If cloak is enabled via cloaking device or via RCP120
		if ((g_Vars.currentplayer->devicesactive & DEVICE_CLOAKDEVICE)
				|| (g_Vars.currentplayer->gunctrl.weaponnum == WEAPON_RCP120
					&& (g_Vars.currentplayer->devicesactive & DEVICE_CLOAKRCP120))) {
			if ((chr->hidden & CHRHFLAG_CLOAKED) == 0 && chr->cloakpause < 1) {
				chrCloak(chr, true);
			}
		} else {
			if ((g_Vars.currentplayer->devicesactive & DEVICE_CLOAKDEVICE) == false
					&& (chr->hidden & CHRHFLAG_CLOAKED)) {
				chrUncloak(chr, true);
			}
		}

		setCurrentPlayerNum(prevplayernum);
	}

	// Update cloakfade
	if (chr->hidden & CHRHFLAG_CLOAKED) {
		if (chr->cloakfadefinished == false) {
			fadefrac = chr->cloakfadefrac + (g_Vars.lvupdate240 * 5) / 8;

			if (fadefrac >= 128) {
				chr->cloakfadefinished = true;
				chr->cloakfadefrac = 0;
			} else {
				chr->cloakfadefrac = fadefrac;
			}
		} else {
			s32 tmp = chr->cloakfadefrac + g_Vars.lvupdate60;
			chr->cloakfadefrac = tmp % 127;
		}
	} else {
		if (chr->cloakfadefinished == true) {
			chr->cloakfadefinished = false;

			fVar14 = 1.0f - cosf((chr->cloakfadefrac / 127.0f + chr->cloakfadefrac / 127.0f) * M_PI);
			chr->cloakfadefrac = (254 - (s32)(fVar14 * 20.0f * 0.5f)) / 2;
		}

		if (chr->cloakfadefrac > 0) {
			fadefrac = chr->cloakfadefrac - (g_Vars.lvupdate240 * 5) / 8;

			if (fadefrac < 0) {
				fadefrac = 0;
			}

			chr->cloakfadefrac = fadefrac;
		}
	}
}

s32 chrGetCloakAlpha(struct chrdata *chr)
{
	s32 alpha = 255;

	if (chr->cloakfadefrac > 0 || chr->cloakfadefinished == true) {
		if (!chr->cloakfadefinished) {
			alpha = 255 - chr->cloakfadefrac * 2;
		} else {
			f32 fVar3 = (f32)cosf((chr->cloakfadefrac / 127.0f + chr->cloakfadefrac / 127.0f) * M_PI);
			alpha = (1.0f - fVar3) * 20.0f * 0.5f;
		}

		if (alpha == 0) {
			alpha = 1;
		}
	}

	return alpha;
}

void chrSetPoisoned(struct chrdata *chr, struct prop *poisonprop)
{
	if (chr->actiontype != ACT_DEAD
			&& chr->actiontype != ACT_DIE
			&& chr->prop->type == PROPTYPE_PLAYER) {
		// This was probably used in a debug print
		playermgrGetPlayerNumByProp(chr->prop);
	}

	if (g_Vars.normmplayerisrunning) {
		chr->poisonprop = poisonprop;
		chr->poisoncounter += TICKS(3360);
	} else if (chr->poisoncounter == 0) {
		chr->poisoncounter = TICKS(1680);
		chr->poisonprop = poisonprop;
	}
}

void chrTickPoisoned(struct chrdata *chr)
{
	if (chr->poisoncounter > 0) {
		struct coord coord = {0, 0, 0};

		struct gset gset = { WEAPON_COMBATKNIFE, 0, 0, FUNC_POISON };

		if (chr->actiontype == ACT_DEAD || chr->actiontype == ACT_DIE) {
			// Dying chr
			if (!g_Vars.normmplayerisrunning) {
				chr->poisoncounter = 0;
			} else {
				if (chr->poisoncounter > TICKS(3600)) {
					chr->poisoncounter = TICKS(3600);
				}

				if (g_MpSetup.options & MPOPTION_ONEHITKILLS) {
					chr->poisoncounter = 0;
				}
			}
		} else if (chr->prop->type == PROPTYPE_PLAYER
				&& g_Vars.players[playermgrGetPlayerNumByProp(chr->prop)]->bondhealth < 0.001f) {
			// Player who's alive but on almost zero health
			if (g_Vars.normmplayerisrunning) {
				if (chr->poisoncounter > TICKS(3600)) {
					chr->poisoncounter = TICKS(3600);
				}

				if (g_MpSetup.options & MPOPTION_ONEHITKILLS) {
					chr->poisoncounter = 0;
				}
			}
		} else {
			// Alive chr
			chr->poisoncounter -= g_Vars.lvupdate240;

			if (chr->poisoncounter <= 0) {
				if (!g_Vars.normmplayerisrunning) {
					chrDamageByMisc(chr, 100, &coord, &gset, chr->poisonprop);
					chrFlinchHead(chr, M_PI);
				}

				chr->poisoncounter = 0;
			} else if (chr->poisoncounter < TICKS(1680)) {
				chr->blurdrugamount += g_Vars.lvupdate240 * 10;
			}

			if (g_Vars.normmplayerisrunning) {
				if (chr->poisoncounter / TICKS(720) != (chr->poisoncounter + g_Vars.lvupdate240) / TICKS(720)) {
					chrDamageByMisc(chr, 1.3f, &coord, &gset, chr->poisonprop);
				}
			}
		}
	}
}

f32 var800629e8 = 1;
u32 var800629ec = 0x00000000;
u32 var800629f0 = 0x00000000;
u32 var800629f4 = 0x00000000;
u32 var800629f8 = 0x00000000;

bool chrTickBeams(struct prop *prop)
{
	struct chrdata *chr = prop->chr;

	if (chr->fireslots[0] >= 0) {
		beamTick(&g_Fireslots[chr->fireslots[0]].beam);
	}

	if (chr->fireslots[1] >= 0) {
		beamTick(&g_Fireslots[chr->fireslots[1]].beam);
	}

	if (chr->aibot && chr->aibot->unk058 > 0) {
		if (chr->aibot->unk058 > g_Vars.lvupdate60) {
			chr->aibot->unk058 -= g_Vars.lvupdate60;
		} else {
			chr->aibot->unk058 = 0;
		}
	}

	return false;
}

/**
 * Tick the given chr.
 *
 * This function is called once per player per frame. The first time it is
 * called per frame a "fulltick" is done. On consecutive calls for this tick
 * much of the logic is skipped, and only the logic specific to the current
 * player is executed.
 */
s32 chrTick(struct prop *prop)
{
	struct modelrenderdata sp210 = {0, 1, 3};
	struct chrdata *chr = prop->chr;
	struct model *model = chr->model;
	bool onscreen;
	bool hatvisible = true;
	s32 lvupdate240 = g_Vars.lvupdate240;
	struct prop *child;
	struct prop *next;
	bool fulltick = false;
	s32 race = CHRRACE(chr);
	s32 sp1e8;
	Mtxf sp1a8;
	s32 sp1a4;
	bool offscreen;
	bool offscreen2;
	struct coord sp190;
	f32 angle;
	struct player *player;
	struct coord sp17c;
	f32 sp178;
	struct hoverbikeobj *bike;
	u8 stack[0x28];

	if (prop->flags & PROPFLAG_NOTYETTICKED) {
		fulltick = true;
		prop->flags &= ~PROPFLAG_NOTYETTICKED;
	}

	if (fulltick) {
#if VERSION >= VERSION_NTSC_1_0
		if (chr->goposhitcount > 0 && (chr->hidden & CHRHFLAG_BLOCKINGDOOR) == 0) {
			chr->goposhitcount--;
		}
#endif

		if (g_Vars.in_cutscene) {
			chr->drugheadcount = 0;
			chr->drugheadsway = 0;
		} else if (chr->blurdrugamount > TICKS(1000) && chr->actiontype != ACT_DRUGGEDKO) {
			chr->drugheadcount += g_Vars.lvupdate240 >> 1;
			chr->drugheadsway = cosf(chr->drugheadcount / 255.0f * M_BADTAU) * 20.0f;
		} else if (chr->drugheadsway != 0.0f) {
			chr->drugheadcount = 0;

			if (chr->drugheadsway > 0.0f) {
#if VERSION >= VERSION_PAL_BETA
				chr->drugheadsway -= 0.175f * g_Vars.lvupdate60freal;
#else
				chr->drugheadsway -= 0.04375f * g_Vars.lvupdate240;
#endif

				if (chr->drugheadsway < 0.0f) {
					chr->drugheadsway = 0.0f;
				}
			} else if (chr->drugheadsway < 0.0f) {
#if VERSION >= VERSION_PAL_BETA
				chr->drugheadsway += 0.175f * g_Vars.lvupdate60freal;
#else
				chr->drugheadsway += 0.04375f * g_Vars.lvupdate240;
#endif

				if (chr->drugheadsway > 0.0f) {
					chr->drugheadsway = 0.0f;
				}
			}
		}

		chrUpdateCloak(chr);
		chrTickPoisoned(chr);

		if ((chr->chrflags & CHRCFLAG_HIDDEN) == 0 || (chr->chrflags & CHRCFLAG_00040000)) {
			if (var8006296c) {
				if (animHasFrames(g_SelectedAnimNum)) {
					if (modelGetAnimNum(model) != g_SelectedAnimNum || !animHasFrames(modelGetAnimNum(model))) {
						modelSetAnimation(model, g_SelectedAnimNum, 0, 0.0f, 0.5f, 0.0f);
					}
				}
			} else {
				chraTick(chr);

				if (chr->model == NULL) {
					return TICKOP_FREE;
				}
			}

			if (var80062974) {
				lvupdate240 = 0;

				if (var80062978) {
					lvupdate240 = 1;
				}
			}
		}

		if (chr->hidden & CHRHFLAG_REAPED) {
			if (chr->hidden & CHRHFLAG_00000001) {
				objDropRecursively(prop, true);
			}

			chrRemove(prop, true);
			return TICKOP_FREE;
		}
	}

	if (race == RACE_EYESPY) {
		struct eyespy *eyespy = chrToEyespy(chr);

		if (eyespy && eyespy->deployed) {
			if (eyespy == g_Vars.currentplayer->eyespy && eyespy->active) {
				onscreen = false;
			} else {
				onscreen = func0f08e8ac(prop, &prop->pos, model0001af80(model), true);
			}

			if (fulltick) {
				chr0f0220ec(chr, lvupdate240, 1);
			}
		} else {
			onscreen = false;
		}
	} else if (chr->chrflags & CHRCFLAG_HIDDEN) {
		onscreen = false;
	} else if ((chr->chrflags & CHRCFLAG_UNPLAYABLE)
			|| (prop->type == PROPTYPE_PLAYER
				&& g_Vars.currentplayer == (player = g_Vars.players[playermgrGetPlayerNumByProp(prop)])
				&& player->cameramode == CAMERAMODE_THIRDPERSON
				&& player->visionmode != VISIONMODE_SLAYERROCKET)) {
		// Cutscene chr?
		offscreen = false;

		if (fulltick) {
			model->anim->average = false;

			if (chr->actiontype == ACT_ANIM && !chr->act_anim.movewheninvis && chr->act_anim.lockpos) {
				chr0f0220ec(chr, lvupdate240, 0);
			} else {
				chr0f0220ec(chr, lvupdate240, 1);
			}
		}

		if (chr->model && chr->model->anim && (g_Anims[chr->model->anim->animnum].flags & ANIMFLAG_04)) {
			anim00023d38(chr->model->anim->animnum);

			offscreen = anim0002384c(chr->model->anim->animnum, chr->model->anim->framea) < 0
				|| (anim0002384c(chr->model->anim->animnum, chr->model->anim->frameb) < 0
						&& chr->model->anim->frac != 0.0f);
		}

		if (offscreen) {
			onscreen = false;
		} else {
			onscreen = posIsInDrawDistance(&prop->pos);
		}
	} else if (chr->actiontype == ACT_PATROL || chr->actiontype == ACT_GOPOS) {
		if ((chr->actiontype == ACT_PATROL && chr->act_patrol.waydata.mode == WAYMODE_MAGIC)
				|| (chr->actiontype == ACT_GOPOS && chr->act_gopos.waydata.mode == WAYMODE_MAGIC)) {
			onscreen = func0f08e8ac(prop, &prop->pos, model0001af80(model), true);

			if (onscreen) {
				model->anim->average = false;
				modelGetRootPosition(model, &chr->prevpos);
				model0001b3bc(model);
			}
		} else {
			if (fulltick) {
				chr0f0220ec(chr, lvupdate240, 1);
			}

			onscreen = func0f08e8ac(prop, &prop->pos, model0001af80(model), true);

			if (onscreen) {
				if (chr->actiontype == ACT_PATROL) {
					chr->act_patrol.waydata.lastvisible60 = g_Vars.lvframe60;
				} else if (chr->actiontype == ACT_GOPOS) {
					chr->act_gopos.waydata.lastvisible60 = g_Vars.lvframe60;
				}
			}

			model->anim->average = !onscreen
				&& !((prop->flags & (PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) != 0);
		}
	} else if (chr->actiontype == ACT_ANIM && !chr->act_anim.movewheninvis) {
		onscreen = func0f08e8ac(prop, &prop->pos, model0001af80(model), true);

		if (fulltick) {
			model->anim->average = false;

			if (onscreen && !chr->act_anim.lockpos) {
				chr0f0220ec(chr, lvupdate240, 1);
			} else {
				chr0f0220ec(chr, lvupdate240, 0);
			}
		}
	} else if (chr->actiontype == ACT_STAND) {
		model->anim->average = false;

		if (chr->chrflags & CHRCFLAG_00000001) {
			chr0f0220ec(chr, lvupdate240, 1);
			onscreen = func0f08e8ac(prop, &prop->pos, model0001af80(model), true);
		} else {
			onscreen = func0f08e8ac(prop, &prop->pos, model0001af80(model), true);

			if (g_Vars.mplayerisrunning) {
				if (fulltick) {
					if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
						if (onscreen) {
							chr0f0220ec(chr, lvupdate240, 1);
						} else if (model->anim->animnum2 != 0) {
							chr0f0220ec(chr, lvupdate240, 0);
						}
					} else {
						chr0f0220ec(chr, lvupdate240, 1);
					}
				}
			} else if (onscreen) {
				if (chr->act_stand.playwalkanim == true) {
					chr0f0220ec(chr, lvupdate240, 0);
				} else {
					chr0f0220ec(chr, lvupdate240, 1);
				}
			} else if (model->anim->animnum2 != 0) {
				chr0f0220ec(chr, lvupdate240, 0);
			}
		}
	} else if (chr->actiontype == ACT_DEAD) {
		onscreen = func0f08e8ac(prop, &prop->pos, model0001af80(model), true);
	} else if (prop->type == PROPTYPE_PLAYER
			&& (g_Vars.mplayerisrunning
				|| (player = g_Vars.players[playermgrGetPlayerNumByProp(prop)], player->cameramode == CAMERAMODE_EYESPY)
				|| (player->cameramode == CAMERAMODE_THIRDPERSON && player->visionmode == VISIONMODE_SLAYERROCKET))) {
		model->anim->average = false;
		chr0f0220ec(chr, lvupdate240, 1);
		onscreen = func0f08e8ac(prop, &prop->pos, model0001af80(model), true);
	} else {
		offscreen2 = false;

		if (fulltick) {
			model->anim->average = false;
			chr0f0220ec(chr, lvupdate240, 1);
		}

		if (chr->model && chr->model->anim && (g_Anims[chr->model->anim->animnum].flags & ANIMFLAG_04)) {
			anim00023d38(chr->model->anim->animnum);

			offscreen2 = anim0002384c(chr->model->anim->animnum, chr->model->anim->framea) < 0
				|| (anim0002384c(chr->model->anim->animnum, chr->model->anim->frameb) < 0 && chr->model->anim->frac != 0.0f);
		}

		if (offscreen2) {
			onscreen = false;
		} else {
			onscreen = func0f08e8ac(prop, &prop->pos, model0001af80(model), true);
		}
	}

	if (fulltick) {
		if (chr->actiontype != ACT_STAND || model->anim->animnum2 != 0 || prop->type == PROPTYPE_PLAYER) {
#if VERSION >= VERSION_NTSC_1_0
			chr->hidden2 |= CHRH2FLAG_0040;
#else
			chr->hidden |= CHRHFLAG_00000200;
#endif
		}

		chrUpdateAimProperties(chr);
	}

	if (prop->pos.y < -65536) {
		onscreen = false;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (!g_Vars.normmplayerisrunning && onscreen) {
		if (chr->actiontype == ACT_DEAD
				|| (chr->actiontype == ACT_DRUGGEDKO && (chr->chrflags & CHRCFLAG_KEEPCORPSEKO) == 0)) {
			var8009cdac++;

			if (var8009cdac > 10) {
				onscreen = false;
				chrDropItemsForOwnerReap(chr);
				chr->hidden |= CHRHFLAG_REAPED;
			}
		} else {
			var8009cdb0++;
		}

		if (var8009cdb0 + var8009cdac > 30) {
			onscreen = false;
		}
	}
#endif

	if (onscreen) {
#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
		debug0f1199f0nb();
#endif

		prop->flags |= PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK;
		chr->chrflags |= CHRCFLAG_EVERONSCREEN;

		if (g_Vars.antiplayernum >= 0 && g_Vars.currentplayer == g_Vars.bond) {
			chr->hidden |= CHRHFLAG_00800000;
		}

		if (cheatIsActive(CHEAT_DKMODE)) {
			modelSetDistanceScale(0.3125f);
		}

		g_ModelJointPositionedFunc = &chrHandleJointPositioned;
		g_CurModelChr = chr;

		if (CHRRACE(chr) == RACE_DRCAROLL && g_Vars.tickmode != TICKMODE_CUTSCENE) {
			angle = chrGetInverseTheta(chr);

			sp190.x = sinf(angle) * 19;
			sp190.y = 0.0f;
			sp190.z = cosf(angle) * 19;

			mtx4LoadTranslation(&sp190, &sp1a8);
			mtx4MultMtx4InPlace(camGetWorldToScreenMtxf(), &sp1a8);
			sp210.unk00 = &sp1a8;
		} else if (prop->type == PROPTYPE_PLAYER) {
			u8 stack[0x14];
			f32 sp130;
			player = g_Vars.players[playermgrGetPlayerNumByProp(prop)];

			if (player->bondmovemode == MOVEMODE_BIKE) {
				sp178 = chrGetInverseTheta(chr);
				bike = (struct hoverbikeobj *)player->hoverbike->obj;
				sp130 = bike->w * 1000;

				sp17c.x = cosf(sp178) * sp130;
				sp17c.y = ABS(bike->w) * 200 + 25;
				sp17c.z = sinf(-sp178) * sp130;

				mtx4LoadTranslation(&sp17c, &sp1a8);
				mtx4MultMtx4InPlace(camGetWorldToScreenMtxf(), &sp1a8);
				sp210.unk00 = &sp1a8;
			} else {
				sp210.unk00 = camGetWorldToScreenMtxf();
			}
		} else {
			sp210.unk00 = camGetWorldToScreenMtxf();
		}

		sp210.unk10 = gfxAllocate(model->filedata->nummatrices * sizeof(Mtxf));

		if (fulltick && g_CurModelChr->flinchcnt >= 0) {
			g_CurModelChr->flinchcnt += g_Vars.lvupdate60;

			if (g_CurModelChr->flinchcnt >= (PAL ? 24 : 30)) {
				g_CurModelChr->flinchcnt = -1;
			}
		}

		{
			f32 limit;
			struct anim *anim;
			struct coord *campos = &g_Vars.currentplayer->cam_pos;
			f32 xdiff;
			f32 ydiff;
			f32 zdiff;
			f32 sp114 = camGetLodScaleZ();
			bool restore = false;
			f32 prevfrac;
			s32 prevframea;
			f32 prevfrac2;
			s32 prevframe2a;

			if (g_Vars.normmplayerisrunning) {
				if (g_MpSetup.options & (MPOPTION_SLOWMOTION_ON | MPOPTION_SLOWMOTION_SMART)) {
					limit = 2000 * 2000;
				} else {
					limit = 700 * 700;
				}
			} else {
				if (debugGetSlowMotion() != SLOWMOTION_OFF) {
					limit = 2000 * 2000;
				} else {
					limit = 700 * 700;
				}
			}

			anim = model->anim;

			if (anim && anim->animnum != 0) {
				xdiff = prop->pos.x - campos->x;
				ydiff = prop->pos.y - campos->y;
				zdiff = prop->pos.z - campos->z;

				if ((xdiff * xdiff + ydiff * ydiff + zdiff * zdiff) * sp114 * sp114 > limit) {
					prevfrac = anim->frac;
					prevframea = anim->framea;
					prevfrac2 = anim->frac2;
					prevframe2a = anim->frame2a;
					restore = true;

					if (anim->frac != 0 && anim->speed * anim->playspeed >= 0.25f) {
						if (anim->frac > 0.5f) {
							anim->framea = anim->frameb;
						}

						anim->frac = 0;
					}

					if (anim->fracmerge != 0 && anim->speed2 * anim->playspeed >= 0.25f && anim->frac2 != 0) {
						if (anim->frac2 > 0.5f) {
							anim->frame2a = anim->frame2b;
						}

						anim->frac2 = 0;
					}
				}
			}

			model0001cebc(&sp210, model);

			if (restore) {
				anim->frac = prevfrac;
				anim->framea = prevframea;
				anim->frac2 = prevfrac2;
				anim->frame2a = prevframe2a;
			}

			g_ModelJointPositionedFunc = NULL;
			modelSetDistanceScale(var800629e8);

			if (fulltick) {
				colourTween(chr->shadecol, chr->nextcol);
			}

			prop->z = model0001a9e8(model);
			child = prop->child;

			while (child) {
				next = child->next;
				chr0f022214(chr, child, fulltick);
				child = next;
			}

			if (chr->weapons_held[2] != NULL) {
				s32 index;
				struct defaultobj *obj = chr->weapons_held[2]->obj;
				struct model *hatmodel = obj->model;

				if (chr->headnum >= HEAD_SHAUN && chr->headnum <= HEAD_SHAUN) {
					struct coord hatpos = {0, 0, 0};
					f32 spe4;
					f32 spe0;
					f32 spdc;
					Mtxf sp9c;
					Mtxf sp5c;
					s32 hattype = hatGetType(chr->weapons_held[2]);
					u8 stack[0x0c];

					index = chr->headnum - HEAD_SHAUN;

					hatpos.x = var8007dae4[index][hattype].x * 21.3f;
					hatpos.y = var8007dae4[index][hattype].y * 21.3f;
					hatpos.z = var8007dae4[index][hattype].z * 21.3f;

					spe4 = var8007dae4[index][hattype].unk0c;
					spe0 = var8007dae4[index][hattype].unk10;
					spdc = var8007dae4[index][hattype].unk14;

					mtx4LoadTranslation(&hatpos, &sp9c);
					mtx00015e24(spe4, &sp9c);
					mtx00015e80(spe0, &sp9c);
					mtx00015edc(spdc, &sp9c);
					mtx00015be4(hatmodel->matrices, &sp9c, &sp5c);
					mtx4Copy(&sp5c, hatmodel->matrices);

					if (hattype == HATTYPE_2) {
						hatvisible = false;
					}
				}
			}

			if (model->filedata->skel == &g_SkelChr) {
				struct modelnode *headspotnode = modelGetPart(model->filedata, MODELPART_CHR_HEADSPOT);

				if (headspotnode && headspotnode->type == MODELNODETYPE_HEADSPOT) {
					union modelrwdata *rwdata = modelGetNodeRwData(model, headspotnode);

					if (rwdata->headspot.modelfiledata != NULL) {
						struct modelnode *hatnode = modelGetPart(rwdata->headspot.modelfiledata, MODELPART_HEAD_HAT);

						if (hatnode != NULL) {
							union modelrwdata *hatrwdata = modelGetNodeRwData(model, hatnode);
							hatrwdata->toggle.visible = hatvisible;
						}
					}
				}
			}
		}
	} else {
		// Offscreen
		prop->flags &= ~PROPFLAG_ONTHISSCREENTHISTICK;

		if (g_Vars.antiplayernum >= 0 && g_Vars.currentplayer == g_Vars.bond) {
			chr->hidden &= ~CHRHFLAG_00800000;
		}

		child = prop->child;

		while (child) {
			next = child->next;
			func0f0706f8(child, fulltick);
			child = next;
		}

		chr->shadecol[0] = chr->nextcol[0];
		chr->shadecol[1] = chr->nextcol[1];
		chr->shadecol[2] = chr->nextcol[2];
		chr->shadecol[3] = chr->nextcol[3];
	}

	if (fulltick && (chr->chrflags & CHRCFLAG_HIDDEN) == 0) {
		if (chr->hidden & CHRHFLAG_00000001) {
			objDropRecursively(prop, false);
			chr->hidden &= ~CHRHFLAG_00000001;
		}

		func0f041a74(chr);
	}

	return TICKOP_NONE;
}

void chrDropConcealedItems(struct chrdata *chr)
{
	struct prop *prop = chr->prop->child;

	while (prop) {
		if (prop != chr->weapons_held[2]
				&& prop != chr->weapons_held[1]
				&& prop != chr->weapons_held[0]
				&& (prop->obj->hidden & OBJHFLAG_EMBEDDED) == 0
				&& (prop->obj->flags & OBJFLAG_AIUNDROPPABLE) == 0) {
			objSetDropped(prop, DROPTYPE_DEFAULT);
		}

		prop = prop->next;
	}

	chr->hidden |= CHRHFLAG_00000001;
}

void chrSetHudpieceVisible(struct chrdata *chr, bool visible)
{
	struct modelfiledata *modelfiledata = chr->model->filedata;

	if (modelfiledata->skel == &g_SkelChr) {
		struct modelnode *headspotnode = modelGetPart(modelfiledata, MODELPART_CHR_HEADSPOT);

		if (headspotnode && headspotnode->type == MODELNODETYPE_HEADSPOT) {
			union modelrwdata *rwdata = modelGetNodeRwData(chr->model, headspotnode);

			if (rwdata->headspot.modelfiledata) {
				struct modelnode *hudpiecenode = modelGetPart(rwdata->headspot.modelfiledata, MODELPART_HEAD_HUDPIECE);

				if (hudpiecenode) {
					union modelrwdata *rwdata2 = modelGetNodeRwData(chr->model, hudpiecenode);
					rwdata2->toggle.visible = visible;
				}
			}
		}
	}
}

void chrDropItemsForOwnerReap(struct chrdata *chr)
{
	struct prop *prop = chr->prop->child;

	while (prop)  {
		// If prop is not hat
		if (prop != chr->weapons_held[2]) {
			struct defaultobj *obj = prop->obj;

			if ((obj->flags & OBJFLAG_AIUNDROPPABLE) == 0) {
				objSetDropped(prop, DROPTYPE_OWNERREAP);
			}
		}

		prop = prop->next;
	}

	chr->hidden |= CHRHFLAG_00000001;
}

u8 var80062a48[] = { 64, 10, 10 };

void chr0f0246e4(u8 *arg0)
{
	var80062a48[0] = arg0[0];
	var80062a48[1] = arg0[1];
	var80062a48[2] = arg0[2];
}

void chr0f024708(u8 *arg0)
{
	arg0[0] = var80062a48[0];
	arg0[1] = var80062a48[1];
	arg0[2] = var80062a48[2];
}

void chr0f02472c(void)
{
	var80062964 = 0;
}

bool chr0f024738(struct chrdata *chr)
{
	s16 *propnumptr;
	s16 propnums[256];
	s32 i;
	struct var80062960 *thing;
	struct coord *campos;
	bool result = false;

	for (i = 0; i < var80062964; i++) {
		var80062960[i].unk004 = 0;
	}

	roomGetProps(chr->prop->rooms, propnums, 256);
	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop->type == PROPTYPE_DOOR) {
			if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
				struct defaultobj *obj = prop->obj;
				struct doorobj *door = prop->door;
				struct coord pos;

				if (obj->model->filedata->skel != &g_SkelWindowedDoor
						&& door->doortype != DOORTYPE_EYE
						&& door->doortype != DOORTYPE_IRIS
						&& door->doortype != DOORTYPE_FALLAWAY
						&& door->doortype != DOORTYPE_AZTECCHAIR
						&& (obj->flags & (OBJFLAG_00000010 | OBJFLAG_AISEETHROUGH)) == 0
						&& (obj->flags2 & OBJFLAG2_80000000) == 0
						&& !((door->doorflags & DOORFLAG_0080) == 0 && door->frac > 0)) {
					for (i = 0; i < var80062964; i++) {
						if (var80062960[i].prop == prop) {
							break;
						}
					}

					if (i < var80062964) {
						thing = &var80062960[i];
					} else {
						if (var80062964 > 14) {
							goto next;
						}

						thing = &var80062960[var80062964];
						thing->prop = prop;
						thing->unk00c = 0;
						thing->unk130 = 0;
						thing->unk004 = 0;

						var80062964++;
					}

					if (!thing->unk00c) {
						struct modelrodata_bbox *bbox = objFindBboxRodata(obj);
						thing->bbox = *bbox;

						mtx3ToMtx4(obj->realrot, &thing->unk02c);
						mtx4SetTranslation(&obj->prop->pos, &thing->unk02c);
						mtx000172f0(thing->unk02c.m, thing->unk06c.m);

						campos = &g_Vars.currentplayer->cam_pos;

						thing->unk12c = (
								+ thing->unk06c.m[0][2] * campos->f[0]
								+ thing->unk06c.m[1][2] * campos->f[1]
								+ thing->unk06c.m[2][2] * campos->f[2]) + thing->unk06c.m[3][2];

						mtx00015be4(&thing->unk06c, camGetProjectionMtxF(), &thing->unk0ac);
						thing->unk00c = true;
					}

					modelGetRootPosition(chr->model, &pos);

					thing->unk008 = (
							thing->unk06c.m[0][2] * pos.f[0] +
							thing->unk06c.m[1][2] * pos.f[1] +
							thing->unk06c.m[2][2] * pos.f[2]) + thing->unk06c.m[3][2];

					if ((thing->unk008 > thing->bbox.zmax && thing->unk12c < thing->bbox.zmin)
							|| (thing->unk008 < thing->bbox.zmin && thing->unk12c > thing->bbox.zmax)) {
						thing->unk004 = true;
						result = true;
					}
				}
			}
		}

next:
		propnumptr++;
	}

	return result;
}

bool chr0f024b18(struct model *model, struct modelnode *node)
{
	struct model *rootmodel;
	struct modelnode *bboxnode;
	f32 value;
	struct doorobj *door;
	struct modelrodata_bbox *bbox;
	struct var80062960 *thing;
	s32 i;
	s32 j;
	bool done;
	Mtxf spb4;
	s32 spb0;
	struct chrdata *chr;
	struct coord spa0;
	struct coord sp94;
	struct coord sp88;
	f32 sp80[2];
	Mtxf *mtx;
	struct coord sp70;
	struct coord sp64;

	rootmodel = model;

	while (rootmodel->attachedtonode && rootmodel->attachedtomodel) {
		rootmodel = rootmodel->attachedtomodel;
	}

	chr = rootmodel->chr;

	if (chr) {
		bboxnode = node;

		while (bboxnode) {
			if ((bboxnode->type & 0xff) == MODELNODETYPE_BBOX) {
				break;
			}

			bboxnode = bboxnode->parent;
		}

		if (bboxnode) {
			bbox = &bboxnode->rodata->bbox;
			mtx = model0001a5cc(model, node, 0);

			for (i = 0; i < var80062964; i++) {
				if (var80062960[i].unk004) {
					thing = &var80062960[i];
					done = false;
					spb0 = false;
					door = thing->prop->door;

					mtx00015be4(&thing->unk0ac, mtx, &spb4);

					if (thing->unk130 == 0) {
						if (door->doortype == DOORTYPE_VERTICAL) {
							spa0.x = thing->bbox.xmin;
							spa0.y = thing->bbox.ymin;
							spa0.z = thing->bbox.zmin;

							sp94.x = thing->bbox.xmax;
							sp94.y = thing->bbox.ymin;
							sp94.z = thing->bbox.zmin;

							sp88.x = thing->bbox.xmax;
							sp88.y = thing->bbox.ymax;
							sp88.z = thing->bbox.zmin;
						} else {
							spa0.x = thing->bbox.xmax;
							spa0.y = thing->bbox.ymax;
							spa0.z = thing->bbox.zmin;

							sp94.x = thing->bbox.xmax;
							sp94.y = thing->bbox.ymin;
							sp94.z = thing->bbox.zmin;

							sp88.x = thing->bbox.xmin;
							sp88.y = thing->bbox.ymin;
							sp88.z = thing->bbox.zmin;
						}

						mtx00015be4(camGetWorldToScreenMtxf(), &thing->unk02c, &thing->unk0ec);
						mtx4TransformVec(&thing->unk0ec, &spa0, &sp70);
						cam0f0b4dec(&sp70, thing->unk134);
						mtx4TransformVec(&thing->unk0ec, &sp94, &sp70);
						cam0f0b4dec(&sp70, thing->unk13c);
						mtx4TransformVec(&thing->unk0ec, &sp88, &sp70);
						cam0f0b4dec(&sp70, thing->unk144);

						thing->unk130 = 1;
						thing->unk14c = thing->unk13c[1] - thing->unk134[1];
						thing->unk150 = -(thing->unk13c[0] - thing->unk134[0]);
						thing->unk154 = thing->unk14c * thing->unk134[0] + thing->unk150 * thing->unk134[1];
						thing->unk158 = thing->unk14c * thing->unk144[0] + thing->unk150 * thing->unk144[1] - thing->unk154;
					}

					for (j = 0; j < 8; j++) {
						switch (j) {
						case 0:
							sp64.x = bbox->xmin;
							sp64.y = bbox->ymin;
							sp64.z = bbox->zmin;
							break;
						case 1:
							sp64.x = bbox->xmin;
							sp64.y = bbox->ymin;
							sp64.z = bbox->zmax;
							break;
						case 2:
							sp64.x = bbox->xmin;
							sp64.y = bbox->ymax;
							sp64.z = bbox->zmin;
							break;
						case 3:
							sp64.x = bbox->xmin;
							sp64.y = bbox->ymax;
							sp64.z = bbox->zmax;
							break;
						case 4:
							sp64.x = bbox->xmax;
							sp64.y = bbox->ymin;
							sp64.z = bbox->zmin;
							break;
						case 5:
							sp64.x = bbox->xmax;
							sp64.y = bbox->ymin;
							sp64.z = bbox->zmax;
							break;
						case 6:
							sp64.x = bbox->xmax;
							sp64.y = bbox->ymax;
							sp64.z = bbox->zmin;
							break;
						case 7:
							sp64.x = bbox->xmax;
							sp64.y = bbox->ymax;
							sp64.z = bbox->zmax;
							break;
						}

						mtx4TransformVec(mtx, &sp64, &sp70);
						cam0f0b4dec(&sp70, sp80);

						value = thing->unk14c * sp80[0] + thing->unk150 * sp80[1] - thing->unk154;

						if ((thing->unk158 >= 0.0f && value < 0.0f)
								|| (thing->unk158 <= 0.0f && value > 0.0f)) {
							spb0 = true;
							break;
						}

						if (!done) {
							mtx4TransformVec(&spb4, &sp64, &sp70);

							if (sp70.x >= thing->bbox.xmin
									&& sp70.x <= thing->bbox.xmax
									&& sp70.y >= thing->bbox.ymin
									&& sp70.y <= thing->bbox.ymax
									&& ((thing->bbox.zmax < thing->unk008 && sp70.z < thing->bbox.zmax)
										|| (thing->unk008 < thing->bbox.zmin && thing->bbox.zmin < sp70.z))) {
								done = true;
							}
						}
					}

					if (done && !spb0) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

/**
 * Render an object that's attached to or held by a chr such as their weapon,
 * mines that are stuck to them, and knives/bolts which are embedded in them.
 *
 * This function is recursive. The chr's gun can have mines placed on it, and
 * mines can also have further mines placed on them.
 */
void chrRenderAttachedObject(struct prop *prop, struct modelrenderdata *renderdata, bool xlupass, struct chrdata *chr)
{
	if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		u32 stack;
		struct defaultobj *obj = prop->obj;
		struct model *model = obj->model;
		struct prop *child;

		modelRender(renderdata, model);

		// Note: OBJH2FLAG_HASOPA << 1 is OBJH2FLAG_HASXLU
		// so this is just checking if the appropriate flag is enabled
		if (obj->hidden2 & (OBJH2FLAG_HASOPA << xlupass)) {
			renderdata->gdl = wallhitRenderPropHits(renderdata->gdl, prop, xlupass);
		}

		child = prop->child;

		while (child) {
			chrRenderAttachedObject(child, renderdata, xlupass, chr);
			child = child->next;
		}

		if (xlupass) {
			func0f0c33f0(model->matrices, model->filedata->nummatrices);
		}
	}
}

void chrGetBloodColour(s16 bodynum, u8 *colour1, u32 *colour2)
{
	switch (bodynum) {
	case BODY_ELVIS1:
	case BODY_THEKING:
	case BODY_ELVISWAISTCOAT:
		if (colour1) {
			colour1[0] = 10;
			colour1[1] = 0x40;
			colour1[2] = 10;
		}
		if (colour2) {
			colour2[0] = 0x103010ff;
			colour2[1] = 0x104010ff;
			colour2[2] = 0x005611a0;
		}
		return;
	case BODY_DRCAROLL:
	case BODY_EYESPY:
	case BODY_CHICROB:
		if (colour1) {
			colour1[0] = 10;
			colour1[1] = 10;
			colour1[2] = 10;
		}
		if (colour2) {
			colour2[0] = 0xb0b030a0;
			colour2[1] = 0xe0e030a0;
			colour2[2] = 0xe0e050a0;
		}
		return;
	case BODY_MRBLONDE:
	case BODY_SKEDAR:
	case BODY_MINISKEDAR:
	case BODY_SKEDARKING:
		if (colour1) {
			colour1[0] = 0x40;
			colour1[1] = 0x19;
			colour1[2] = 10;
		}
		if (colour2) {
			colour2[0] = 0x302010ff;
			colour2[1] = 0x402010ff;
			colour2[2] = 0x560011a0;
		}
		return;
	}

	if (colour1) {
		colour1[0] = 0x40;
		colour1[1] = 10;
		colour1[2] = 10;
	}

	if (colour2) {
		colour2[0] = 0x301010ff;
		colour2[1] = 0x401010ff;
		colour2[2] = 0x560011a0;
	}
}

Gfx *chrRender(struct prop *prop, Gfx *gdl, bool xlupass)
{
	struct chrdata *chr = prop->chr;
	struct model *model = chr->model;
	f32 sp108[4];
	s32 sp104;
	s32 sp100;
	s32 alpha;
	struct eyespy *eyespy;
	struct prop *child;
	f32 xrayalphafrac;
	u8 spec[4];
	u8 speb = 0;

	// Don't render the eyespy if we're the one controlling it
	if (CHRRACE(chr) == RACE_EYESPY) {
		eyespy = chrToEyespy(chr);

		if (eyespy) {
			if (!eyespy->deployed) {
				return gdl;
			}

			if (eyespy == g_Vars.currentplayer->eyespy && eyespy->active) {
				return gdl;
			}
		}
	}

	if (chr->chrflags & CHRCFLAG_UNPLAYABLE) {
		alpha = 0xff;
	} else {
		alpha = chr->fadealpha;
	}

	if (chr->aibot && chr->aibot->unk058 > 0) {
		alpha = (f32)alpha * (TICKS(120) - chr->aibot->unk058) * (PAL ? 0.01f : 0.0083333337679505f);
	}

	chrGetBloodColour(chr->bodynum, spec, NULL);
	chr0f0246e4(spec);
	alpha *= func0f08e6bc(prop, model0001af80(model));

	if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
		f32 fadedist;
		f32 chrdist = sqrtf(ERASERSQDIST(prop->pos.f));

		if (chrdist > g_Vars.currentplayer->eraserpropdist) {
			return gdl;
		}

		alpha = 128;
		fadedist = g_Vars.currentplayer->eraserpropdist - 150;

		if (chrdist > fadedist) {
			alpha = (1.0f - (chrdist - fadedist) / 150.0f) * 128;
		}

		xrayalphafrac = chrdist / g_Vars.currentplayer->eraserpropdist;

		if (xrayalphafrac > 1.0f) {
			xrayalphafrac = 1.0f;
		}
	}

	if (!USINGDEVICE(DEVICE_IRSCANNER)) {
		alpha = chrGetCloakAlpha(chr) * alpha * 0.0039215688593686f;
	}

	if (alpha < 0xff) {
		if (!xlupass) {
			return gdl;
		}

		sp100 = 3;
	} else {
		if (!xlupass) {
			sp100 = 1;
		} else {
			sp100 = 2;
		}
	}

	sp104 = env0f1667f4(prop, sp108);

	if (chr->unk32c_18) {
		propCalculateShadeColour(chr->prop, chr->nextcol, chr->floorcol);
		chr->unk32c_18 = false;
	}

	if (sp104 && alpha > 0) {
		struct modelrenderdata renderdata = {0, 1, 3};
		struct screenbox screenbox;
		s32 colour[4]; // rgba levels, but allowing > 256 temporarily
		u32 stack;

		if (xlupass && chr->cloakfadefrac > 0 && !chr->cloakfadefinished) {
			gdl = chrRenderCloak(gdl, chr->prop, chr->prop);
		}

		if (func0f08e5a8(prop->rooms, &screenbox) > 0 && (chr->chrflags & CHRCFLAG_UNPLAYABLE) == 0) {
			gdl = currentPlayerScissorWithinViewport(gdl, screenbox.xmin, screenbox.ymin, screenbox.xmax, screenbox.ymax);
		} else {
			gdl = currentPlayerScissorToViewport(gdl);
		}

		renderdata.flags = sp100;
		renderdata.zbufferenabled = true;
		renderdata.gdl = gdl;

		// Configure colours for IR scanner or default
		if (USINGDEVICE(DEVICE_IRSCANNER)) {
			colour[0] = 0xff;
			colour[1] = 0;
			colour[2] = 0;
			colour[3] = 0x80;
		} else {
			colour[0] = chr->shadecol[0];
			colour[1] = chr->shadecol[1];
			colour[2] = chr->shadecol[2];
			colour[3] = chr->shadecol[3];
		}

		if (g_Vars.normmplayerisrunning) {
			speb = scenarioHighlightProp(prop, colour);
		}

		if (!speb) {
			colour[3] = colour[3] - func0f068fc8(prop, true);

			if (colour[3] > 0xff) {
				colour[3] = 0xff;
			}

			if (colour[3] < 0) {
				colour[3] = 0;
			}
		}

		func0f069750(colour, sp104, sp108);

		// Configure colours for night vision if in use
		if (USINGDEVICE(DEVICE_NIGHTVISION)) {
			colour[0] = var8009caef;
			colour[1] = var8009caef;
			colour[2] = var8009caef;
			colour[3] = var8009caf0;
		}

		// Configure colours for xray if in use
		if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
			colour[g_Vars.currentplayer->epcol_0] = xrayalphafrac * 255;
			colour[g_Vars.currentplayer->epcol_1] = (1 - xrayalphafrac) * 255;
			colour[g_Vars.currentplayer->epcol_2] = 0;
			colour[3] = 0xff;
		}

		renderdata.envcolour = var80062a48[0] << 24 | var80062a48[1] << 16 | var80062a48[2] << 8;
		renderdata.fogcolour = colour[0] << 24 | colour[1] << 16 | colour[2] << 8 | colour[3];

		if (alpha < 0xff) {
			renderdata.unk30 = 8;
			renderdata.envcolour |= (u8)alpha;
		} else {
			renderdata.unk30 = 7;
		}

		// Set Skedar eyes open or closed
		if (model->filedata->skel == &g_SkelSkedar) {
			struct modelnode *node1 = modelGetPart(model->filedata, MODELPART_SKEDAR_EYESOPEN);
			struct modelnode *node2 = modelGetPart(model->filedata, MODELPART_SKEDAR_EYESCLOSED);

			if (node1 && node2) {
				union modelrwdata *data1 = modelGetNodeRwData(model, node1);
				union modelrwdata *data2 = modelGetNodeRwData(model, node2);

				data2->toggle.visible = chr->actiontype == ACT_DIE || chr->actiontype == ACT_DEAD;
				data1->toggle.visible = !data2->toggle.visible;
			}
		}

		// Set Maian eyes open or closed
		if (chr->headnum == HEAD_THEKING
				|| chr->headnum == HEAD_ELVIS
				|| chr->headnum == HEAD_MAIAN_S
				|| chr->headnum == HEAD_ELVIS_GOGS) {
			if (model->filedata->skel == &g_SkelChr) {
				struct modelnode *headspotnode = modelGetPart(model->filedata, MODELPART_CHR_HEADSPOT);

				if (headspotnode && headspotnode->type == MODELNODETYPE_HEADSPOT) {
					union modelrwdata *headrwdata = modelGetNodeRwData(model, headspotnode);

					if (headrwdata->headspot.modelfiledata) {
						struct modelnode *node1 = modelGetPart(headrwdata->headspot.modelfiledata, MODELPART_HEAD_EYESOPEN);
						struct modelnode *node2 = modelGetPart(headrwdata->headspot.modelfiledata, MODELPART_HEAD_EYESCLOSED);

						if (node1 && node2) {
							union modelrwdata *data1 = modelGetNodeRwData(model, node1);
							union modelrwdata *data2 = modelGetNodeRwData(model, node2);

							data2->toggle.visible = chr->actiontype == ACT_DIE || chr->actiontype == ACT_DEAD;
							data1->toggle.visible = !data2->toggle.visible;
						}
					}
				}
			}
		}

		if (chr->race == RACE_DRCAROLL) {
			chrSetDrCarollImages(chr, chr->drcarollimage_left, chr->drcarollimage_right);
		}

		g_Vars.currentplayerstats->drawplayercount++;

		if (chr0f024738(chr)) {
			var8005efc4 = chr0f024b18;
		}

		// Render the chr's model
		modelRender(&renderdata, model);

		// Render attached props (eg. held guns and attached mines/knives/bolts)
		child = prop->child;

		while (child) {
			chrRenderAttachedObject(child, &renderdata, xlupass, chr);
			child = child->next;
		}

		gdl = renderdata.gdl;

		var8005efc4 = NULL;

		// Render shadow
		if (xlupass) {
			if (!chr->onladder && chr->actiontype != ACT_SKJUMP) {
				s32 shadowalpha = 0;

				if (chr->ground == 0) {
					shadowalpha = 1;
				}

				// @bug: The wrong variable is being used in the minimum bounds
				// check. However, the approach to this is also flawed. The RSP
				// can crash if drawing outside of its allowed range, which is
				// actually -32768.99 to 32767.99. And this range is relative
				// to the camera, not in world coordinates. This bad check
				// doesn't cause any crashes though, because even if a chr falls
				// out of the geometry they likely wouldn't be rendered due to
				// not being in an active room and also being out of the draw
				// distance.
				if (shadowalpha > -65536.0f && chr->ground < 65536.0f) {
					f32 gaptoground = prop->pos.y - chr->ground;
					f32 radius;

					if (gaptoground <= 400 && g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
						if (chr->bodynum == BODY_SKEDAR || chr->bodynum == BODY_SKEDARKING) {
							radius = 80;
						} else if (chr->bodynum == BODY_EYESPY) {
							radius = 12;
						} else {
							radius = 35;
						}

						if (chr->chrflags & CHRCFLAG_NOSHADOW) {
							shadowalpha = 0;
						} else if (sp104 == 1) {
							shadowalpha = (1.0f - sp108[3]) * ((alpha * 100) >> 8);
						} else {
							shadowalpha = (s32)(alpha * 100) >> 8;
						}

						if (gaptoground >= 150.0f) {
							shadowalpha = shadowalpha * (400 - gaptoground) * 0.004f;
						}

						if (cheatIsActive(CHEAT_SMALLCHARACTERS)) {
							radius *= 0.4f;
						}

						gdl = gfxRenderRadialShadow(gdl, prop->pos.x, chr->ground, prop->pos.z, chrGetInverseTheta(chr), radius, 0xffffff00 | shadowalpha);
					}
				}
			}

			func0f0c33f0(model->matrices, model->filedata->nummatrices);

			if (USINGDEVICE(DEVICE_IRSCANNER)) {
				gdl = chrRenderShield(gdl, chr, 0x80);
			} else {
				gdl = chrRenderShield(gdl, chr, alpha);
			}
		}
	}

	return gdl;
}

struct shieldhit *g_ShieldHits = NULL;

void chrEmitSparks(struct chrdata *chr, struct prop *prop, s32 hitpart, struct coord *coord, struct coord *coord2, struct chrdata *chr2)
{
	struct prop *chrprop = chr->prop;
	s32 race;

	if (chrIsUsingPaintball(chr2)) {
		sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_PAINT);
		return;
	}

	if (chrGetShield(chr) > 0.0f) {
		sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_DEFAULT);
		return;
	}

	if (prop->type == PROPTYPE_OBJ
			|| prop->type == PROPTYPE_WEAPON
			|| prop->type == PROPTYPE_DOOR
			|| hitpart == HITPART_GUN
			|| hitpart == HITPART_HAT) {
		sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_DEFAULT);
		return;
	}

	race = CHRRACE(chr);

	if (race == RACE_DRCAROLL || race == RACE_ROBOT || race == RACE_EYESPY) {
		sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_ELECTRICAL);
		return;
	}

	if (chr->noblood) {
		return;
	}

	if ((random() & 4) == 0) {
		struct coord coord3;
		coord3.x = coord2->x * 42.0f + coord->x;
		coord3.y = coord2->y * 42.0f + coord->y;
		coord3.z = coord2->z * 42.0f + coord->z;

		sparksCreate(chrprop->rooms[0], chrprop, &coord3, coord2, 0, SPARKTYPE_FLESH_LARGE);
	}

#if VERSION < VERSION_JPN_FINAL
	sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_BLOOD);
	sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_FLESH);
#endif
}

#if MATCHING
GLOBAL_ASM(
glabel chr0f0260c4
/*  f0260c4:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f0260c8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0260cc:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0260d0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0260d4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0260d8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0260dc:	3c107fff */ 	lui	$s0,0x7fff
/*  f0260e0:	00e09025 */ 	or	$s2,$a3,$zero
/*  f0260e4:	00c09825 */ 	or	$s3,$a2,$zero
/*  f0260e8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0260ec:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0260f0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0260f4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0260f8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0260fc:	afa40128 */ 	sw	$a0,0x128($sp)
/*  f026100:	afa5012c */ 	sw	$a1,0x12c($sp)
/*  f026104:	00008825 */ 	or	$s1,$zero,$zero
/*  f026108:	3610ffff */ 	ori	$s0,$s0,0xffff
/*  f02610c:	0c004b70 */ 	jal	random
/*  f026110:	afa00100 */ 	sw	$zero,0x100($sp)
/*  f026114:	24010032 */ 	addiu	$at,$zero,0x32
/*  f026118:	0041001b */ 	divu	$zero,$v0,$at
/*  f02611c:	00007010 */ 	mfhi	$t6
/*  f026120:	25cf0014 */ 	addiu	$t7,$t6,0x14
/*  f026124:	afaf00cc */ 	sw	$t7,0xcc($sp)
/*  f026128:	afa000c0 */ 	sw	$zero,0xc0($sp)
/*  f02612c:	0c0069d0 */ 	jal	model0001a740
/*  f026130:	02602025 */ 	or	$a0,$s3,$zero
/*  f026134:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f026138:	00402825 */ 	or	$a1,$v0,$zero
/*  f02613c:	0c006b57 */ 	jal	modelNodeGetModelRelativePosition
/*  f026140:	27a600f4 */ 	addiu	$a2,$sp,0xf4
/*  f026144:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f026148:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f02614c:	c7b000f8 */ 	lwc1	$f16,0xf8($sp)
/*  f026150:	02602825 */ 	or	$a1,$s3,$zero
/*  f026154:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f026158:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f02615c:	24160011 */ 	addiu	$s6,$zero,0x11
/*  f026160:	2415000a */ 	addiu	$s5,$zero,0xa
/*  f026164:	e7a800dc */ 	swc1	$f8,0xdc($sp)
/*  f026168:	c64a0004 */ 	lwc1	$f10,0x4($s2)
/*  f02616c:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f026170:	e7b200e0 */ 	swc1	$f18,0xe0($sp)
/*  f026174:	c6440008 */ 	lwc1	$f4,0x8($s2)
/*  f026178:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f02617c:	126000c7 */ 	beqz	$s3,.L0f02649c
/*  f026180:	e7a800e4 */ 	swc1	$f8,0xe4($sp)
/*  f026184:	94b40000 */ 	lhu	$s4,0x0($a1)
.L0f026188:
/*  f026188:	24010008 */ 	addiu	$at,$zero,0x8
/*  f02618c:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f026190:	329800ff */ 	andi	$t8,$s4,0xff
/*  f026194:	13010099 */ 	beq	$t8,$at,.L0f0263fc
/*  f026198:	0300a025 */ 	or	$s4,$t8,$zero
/*  f02619c:	24010012 */ 	addiu	$at,$zero,0x12
/*  f0261a0:	1301009b */ 	beq	$t8,$at,.L0f026410
/*  f0261a4:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f0261a8:	24010017 */ 	addiu	$at,$zero,0x17
/*  f0261ac:	1301009d */ 	beq	$t8,$at,.L0f026424
/*  f0261b0:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f0261b4:	24010018 */ 	addiu	$at,$zero,0x18
/*  f0261b8:	13010003 */ 	beq	$t8,$at,.L0f0261c8
/*  f0261bc:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f0261c0:	1000009c */ 	b	.L0f026434
/*  f0261c4:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f0261c8:
/*  f0261c8:	8cb20004 */ 	lw	$s2,0x4($a1)
/*  f0261cc:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0261d0:	afa50110 */ 	sw	$a1,0x110($sp)
/*  f0261d4:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0261d8:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f0261dc:	54800004 */ 	bnezl	$a0,.L0f0261f0
/*  f0261e0:	8e430000 */ 	lw	$v1,0x0($s2)
/*  f0261e4:	10000093 */ 	b	.L0f026434
/*  f0261e8:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f0261ec:	8e430000 */ 	lw	$v1,0x0($s2)
.L0f0261f0:
/*  f0261f0:	3c0100ff */ 	lui	$at,0xff
/*  f0261f4:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0261f8:	14640005 */ 	bne	$v1,$a0,.L0f026210
/*  f0261fc:	0080f025 */ 	or	$s8,$a0,$zero
/*  f026200:	8e4a0008 */ 	lw	$t2,0x8($s2)
/*  f026204:	00615824 */ 	and	$t3,$v1,$at
/*  f026208:	10000001 */ 	b	.L0f026210
/*  f02620c:	014bf021 */ 	addu	$s8,$t2,$t3
.L0f026210:
/*  f026210:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f026214:	3c0100ff */ 	lui	$at,0xff
/*  f026218:	50400008 */ 	beqzl	$v0,.L0f02623c
/*  f02621c:	afa00108 */ 	sw	$zero,0x108($sp)
/*  f026220:	8e4c0008 */ 	lw	$t4,0x8($s2)
/*  f026224:	3421ffff */ 	ori	$at,$at,0xffff
/*  f026228:	00416824 */ 	and	$t5,$v0,$at
/*  f02622c:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f026230:	10000002 */ 	b	.L0f02623c
/*  f026234:	afae0108 */ 	sw	$t6,0x108($sp)
/*  f026238:	afa00108 */ 	sw	$zero,0x108($sp)
.L0f02623c:
/*  f02623c:	83c20000 */ 	lb	$v0,0x0($s8)
/*  f026240:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f026244:	8faf0108 */ 	lw	$t7,0x108($sp)
/*  f026248:	5441000a */ 	bnel	$v0,$at,.L0f026274
/*  f02624c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f026250:	51e00005 */ 	beqzl	$t7,.L0f026268
/*  f026254:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f026258:	01e0f025 */ 	or	$s8,$t7,$zero
/*  f02625c:	1000fff7 */ 	b	.L0f02623c
/*  f026260:	afa00108 */ 	sw	$zero,0x108($sp)
/*  f026264:	8fa50110 */ 	lw	$a1,0x110($sp)
.L0f026268:
/*  f026268:	10000072 */ 	b	.L0f026434
/*  f02626c:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f026270:	24010004 */ 	addiu	$at,$zero,0x4
.L0f026274:
/*  f026274:	1441003e */ 	bne	$v0,$at,.L0f026370
/*  f026278:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f02627c:	8fc20004 */ 	lw	$v0,0x4($s8)
/*  f026280:	93c90001 */ 	lbu	$t1,0x1($s8)
/*  f026284:	3c0100ff */ 	lui	$at,0xff
/*  f026288:	8e4a000c */ 	lw	$t2,0xc($s2)
/*  f02628c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f026290:	0041c824 */ 	and	$t9,$v0,$at
/*  f026294:	00095902 */ 	srl	$t3,$t1,0x4
/*  f026298:	25690001 */ 	addiu	$t1,$t3,0x1
/*  f02629c:	11800055 */ 	beqz	$t4,.L0f0263f4
/*  f0262a0:	01591821 */ 	addu	$v1,$t2,$t9
/*  f0262a4:	19200053 */ 	blez	$t1,.L0f0263f4
/*  f0262a8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0262ac:	00601025 */ 	or	$v0,$v1,$zero
.L0f0262b0:
/*  f0262b0:	84470000 */ 	lh	$a3,0x0($v0)
/*  f0262b4:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*  f0262b8:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*  f0262bc:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f0262c0:	01a71823 */ 	subu	$v1,$t5,$a3
/*  f0262c4:	00630019 */ 	multu	$v1,$v1
/*  f0262c8:	01cf2023 */ 	subu	$a0,$t6,$t7
/*  f0262cc:	8fb800d8 */ 	lw	$t8,0xd8($sp)
/*  f0262d0:	84590004 */ 	lh	$t9,0x4($v0)
/*  f0262d4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0262d8:	c7aa00e8 */ 	lwc1	$f10,0xe8($sp)
/*  f0262dc:	03192823 */ 	subu	$a1,$t8,$t9
/*  f0262e0:	00005012 */ 	mflo	$t2
/*  f0262e4:	00000000 */ 	nop
/*  f0262e8:	00000000 */ 	nop
/*  f0262ec:	00840019 */ 	multu	$a0,$a0
/*  f0262f0:	00005812 */ 	mflo	$t3
/*  f0262f4:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f0262f8:	00000000 */ 	nop
/*  f0262fc:	00a50019 */ 	multu	$a1,$a1
/*  f026300:	00006812 */ 	mflo	$t5
/*  f026304:	018d4021 */ 	addu	$t0,$t4,$t5
/*  f026308:	0110082a */ 	slt	$at,$t0,$s0
/*  f02630c:	10200014 */ 	beqz	$at,.L0f026360
/*  f026310:	00000000 */ 	nop
/*  f026314:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f026318:	c7b200ec */ 	lwc1	$f18,0xec($sp)
/*  f02631c:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
/*  f026320:	01008025 */ 	or	$s0,$t0,$zero
/*  f026324:	440f8000 */ 	mfc1	$t7,$f16
/*  f026328:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f02632c:	8fb10110 */ 	lw	$s1,0x110($sp)
/*  f026330:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f026334:	afb80114 */ 	sw	$t8,0x114($sp)
/*  f026338:	844b0002 */ 	lh	$t3,0x2($v0)
/*  f02633c:	440a2000 */ 	mfc1	$t2,$f4
/*  f026340:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f026344:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f026348:	afac0118 */ 	sw	$t4,0x118($sp)
/*  f02634c:	844f0004 */ 	lh	$t7,0x4($v0)
/*  f026350:	440e4000 */ 	mfc1	$t6,$f8
/*  f026354:	00000000 */ 	nop
/*  f026358:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f02635c:	afb8011c */ 	sw	$t8,0x11c($sp)
.L0f026360:
/*  f026360:	14c9ffd3 */ 	bne	$a2,$t1,.L0f0262b0
/*  f026364:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f026368:	1000ffb4 */ 	b	.L0f02623c
/*  f02636c:	27de0008 */ 	addiu	$s8,$s8,0x8
.L0f026370:
/*  f026370:	24010001 */ 	addiu	$at,$zero,0x1
/*  f026374:	1441001f */ 	bne	$v0,$at,.L0f0263f4
/*  f026378:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f02637c:	8fc20004 */ 	lw	$v0,0x4($s8)
/*  f026380:	3c0100ff */ 	lui	$at,0xff
/*  f026384:	3421ffff */ 	ori	$at,$at,0xffff
/*  f026388:	0041c824 */ 	and	$t9,$v0,$at
/*  f02638c:	0c00698d */ 	jal	model0001a634
/*  f026390:	00192982 */ 	srl	$a1,$t9,0x6
/*  f026394:	afa20100 */ 	sw	$v0,0x100($sp)
/*  f026398:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f02639c:	00402825 */ 	or	$a1,$v0,$zero
/*  f0263a0:	0c006b57 */ 	jal	modelNodeGetModelRelativePosition
/*  f0263a4:	27a600e8 */ 	addiu	$a2,$sp,0xe8
/*  f0263a8:	c7aa00e8 */ 	lwc1	$f10,0xe8($sp)
/*  f0263ac:	c7b000dc */ 	lwc1	$f16,0xdc($sp)
/*  f0263b0:	c7a600ec */ 	lwc1	$f6,0xec($sp)
/*  f0263b4:	c7a800e0 */ 	lwc1	$f8,0xe0($sp)
/*  f0263b8:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f0263bc:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0263c0:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0263c4:	c7b200f0 */ 	lwc1	$f18,0xf0($sp)
/*  f0263c8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0263cc:	440b2000 */ 	mfc1	$t3,$f4
/*  f0263d0:	c7a400e4 */ 	lwc1	$f4,0xe4($sp)
/*  f0263d4:	440d8000 */ 	mfc1	$t5,$f16
/*  f0263d8:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0263dc:	afab00d0 */ 	sw	$t3,0xd0($sp)
/*  f0263e0:	afad00d4 */ 	sw	$t5,0xd4($sp)
/*  f0263e4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0263e8:	440f4000 */ 	mfc1	$t7,$f8
/*  f0263ec:	00000000 */ 	nop
/*  f0263f0:	afaf00d8 */ 	sw	$t7,0xd8($sp)
.L0f0263f4:
/*  f0263f4:	1000ff91 */ 	b	.L0f02623c
/*  f0263f8:	27de0008 */ 	addiu	$s8,$s8,0x8
.L0f0263fc:
/*  f0263fc:	0c0071e1 */ 	jal	model0001c784
/*  f026400:	afa50110 */ 	sw	$a1,0x110($sp)
/*  f026404:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f026408:	1000000a */ 	b	.L0f026434
/*  f02640c:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f026410:
/*  f026410:	0c0071f4 */ 	jal	model0001c7d0
/*  f026414:	afa50110 */ 	sw	$a1,0x110($sp)
/*  f026418:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f02641c:	10000005 */ 	b	.L0f026434
/*  f026420:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f026424:
/*  f026424:	0c007207 */ 	jal	modelAttachHead
/*  f026428:	afa50110 */ 	sw	$a1,0x110($sp)
/*  f02642c:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f026430:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f026434:
/*  f026434:	10400009 */ 	beqz	$v0,.L0f02645c
/*  f026438:	00000000 */ 	nop
/*  f02643c:	10b30005 */ 	beq	$a1,$s3,.L0f026454
/*  f026440:	00000000 */ 	nop
/*  f026444:	12950005 */ 	beq	$s4,$s5,.L0f02645c
/*  f026448:	00000000 */ 	nop
/*  f02644c:	12960003 */ 	beq	$s4,$s6,.L0f02645c
/*  f026450:	00000000 */ 	nop
.L0f026454:
/*  f026454:	1000000f */ 	b	.L0f026494
/*  f026458:	00402825 */ 	or	$a1,$v0,$zero
.L0f02645c:
/*  f02645c:	10a0000d */ 	beqz	$a1,.L0f026494
/*  f026460:	00000000 */ 	nop
.L0f026464:
/*  f026464:	54b30004 */ 	bnel	$a1,$s3,.L0f026478
/*  f026468:	8ca2000c */ 	lw	$v0,0xc($a1)
/*  f02646c:	10000009 */ 	b	.L0f026494
/*  f026470:	00002825 */ 	or	$a1,$zero,$zero
/*  f026474:	8ca2000c */ 	lw	$v0,0xc($a1)
.L0f026478:
/*  f026478:	50400004 */ 	beqzl	$v0,.L0f02648c
/*  f02647c:	8ca50008 */ 	lw	$a1,0x8($a1)
/*  f026480:	10000004 */ 	b	.L0f026494
/*  f026484:	00402825 */ 	or	$a1,$v0,$zero
/*  f026488:	8ca50008 */ 	lw	$a1,0x8($a1)
.L0f02648c:
/*  f02648c:	14a0fff5 */ 	bnez	$a1,.L0f026464
/*  f026490:	00000000 */ 	nop
.L0f026494:
/*  f026494:	54a0ff3c */ 	bnezl	$a1,.L0f026188
/*  f026498:	94b40000 */ 	lhu	$s4,0x0($a1)
.L0f02649c:
/*  f02649c:	122000fb */ 	beqz	$s1,.L0f02688c
/*  f0264a0:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f0264a4:	8c8b0008 */ 	lw	$t3,0x8($a0)
/*  f0264a8:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f0264ac:	8d650000 */ 	lw	$a1,0x0($t3)
/*  f0264b0:	50a000f7 */ 	beqzl	$a1,.L0f026890
/*  f0264b4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0264b8:	94a20000 */ 	lhu	$v0,0x0($a1)
.L0f0264bc:
/*  f0264bc:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0264c0:	304c00ff */ 	andi	$t4,$v0,0xff
/*  f0264c4:	118100ce */ 	beq	$t4,$at,.L0f026800
/*  f0264c8:	24010012 */ 	addiu	$at,$zero,0x12
/*  f0264cc:	118100d2 */ 	beq	$t4,$at,.L0f026818
/*  f0264d0:	24010017 */ 	addiu	$at,$zero,0x17
/*  f0264d4:	118100d6 */ 	beq	$t4,$at,.L0f026830
/*  f0264d8:	24010018 */ 	addiu	$at,$zero,0x18
/*  f0264dc:	51810004 */ 	beql	$t4,$at,.L0f0264f0
/*  f0264e0:	8cb20004 */ 	lw	$s2,0x4($a1)
/*  f0264e4:	100000d7 */ 	b	.L0f026844
/*  f0264e8:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f0264ec:	8cb20004 */ 	lw	$s2,0x4($a1)
.L0f0264f0:
/*  f0264f0:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0264f4:	afa50110 */ 	sw	$a1,0x110($sp)
/*  f0264f8:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0264fc:	00408025 */ 	or	$s0,$v0,$zero
/*  f026500:	54800006 */ 	bnezl	$a0,.L0f02651c
/*  f026504:	8e430000 */ 	lw	$v1,0x0($s2)
/*  f026508:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f02650c:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f026510:	100000cc */ 	b	.L0f026844
/*  f026514:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f026518:	8e430000 */ 	lw	$v1,0x0($s2)
.L0f02651c:
/*  f02651c:	3c0100ff */ 	lui	$at,0xff
/*  f026520:	3421ffff */ 	ori	$at,$at,0xffff
/*  f026524:	14640005 */ 	bne	$v1,$a0,.L0f02653c
/*  f026528:	0080f025 */ 	or	$s8,$a0,$zero
/*  f02652c:	8e4e0008 */ 	lw	$t6,0x8($s2)
/*  f026530:	00617824 */ 	and	$t7,$v1,$at
/*  f026534:	10000001 */ 	b	.L0f02653c
/*  f026538:	01cff021 */ 	addu	$s8,$t6,$t7
.L0f02653c:
/*  f02653c:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f026540:	3c0100ff */ 	lui	$at,0xff
/*  f026544:	50400008 */ 	beqzl	$v0,.L0f026568
/*  f026548:	afa00108 */ 	sw	$zero,0x108($sp)
/*  f02654c:	8e580008 */ 	lw	$t8,0x8($s2)
/*  f026550:	3421ffff */ 	ori	$at,$at,0xffff
/*  f026554:	0041c824 */ 	and	$t9,$v0,$at
/*  f026558:	03195021 */ 	addu	$t2,$t8,$t9
/*  f02655c:	10000002 */ 	b	.L0f026568
/*  f026560:	afaa0108 */ 	sw	$t2,0x108($sp)
/*  f026564:	afa00108 */ 	sw	$zero,0x108($sp)
.L0f026568:
/*  f026568:	83c20000 */ 	lb	$v0,0x0($s8)
/*  f02656c:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f026570:	8fab0108 */ 	lw	$t3,0x108($sp)
/*  f026574:	5441000b */ 	bnel	$v0,$at,.L0f0265a4
/*  f026578:	24010004 */ 	addiu	$at,$zero,0x4
/*  f02657c:	51600005 */ 	beqzl	$t3,.L0f026594
/*  f026580:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f026584:	0160f025 */ 	or	$s8,$t3,$zero
/*  f026588:	1000fff7 */ 	b	.L0f026568
/*  f02658c:	afa00108 */ 	sw	$zero,0x108($sp)
/*  f026590:	8fa50110 */ 	lw	$a1,0x110($sp)
.L0f026594:
/*  f026594:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f026598:	100000aa */ 	b	.L0f026844
/*  f02659c:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f0265a0:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0265a4:
/*  f0265a4:	1441007c */ 	bne	$v0,$at,.L0f026798
/*  f0265a8:	8fb80100 */ 	lw	$t8,0x100($sp)
/*  f0265ac:	8fd50004 */ 	lw	$s5,0x4($s8)
/*  f0265b0:	93d60001 */ 	lbu	$s6,0x1($s8)
/*  f0265b4:	3c0100ff */ 	lui	$at,0xff
/*  f0265b8:	8e4e000c */ 	lw	$t6,0xc($s2)
/*  f0265bc:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0265c0:	02a16824 */ 	and	$t5,$s5,$at
/*  f0265c4:	00167902 */ 	srl	$t7,$s6,0x4
/*  f0265c8:	01a0a825 */ 	or	$s5,$t5,$zero
/*  f0265cc:	25f60001 */ 	addiu	$s6,$t7,0x1
/*  f0265d0:	13000089 */ 	beqz	$t8,.L0f0267f8
/*  f0265d4:	01cd1021 */ 	addu	$v0,$t6,$t5
/*  f0265d8:	1ac00087 */ 	blez	$s6,.L0f0267f8
/*  f0265dc:	00009825 */ 	or	$s3,$zero,$zero
/*  f0265e0:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0265e4:	00408825 */ 	or	$s1,$v0,$zero
.L0f0265e8:
/*  f0265e8:	c7aa00e8 */ 	lwc1	$f10,0xe8($sp)
/*  f0265ec:	c7b200ec */ 	lwc1	$f18,0xec($sp)
/*  f0265f0:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
/*  f0265f4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0265f8:	862b0000 */ 	lh	$t3,0x0($s1)
/*  f0265fc:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f026600:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f026604:	440a8000 */ 	mfc1	$t2,$f16
/*  f026608:	86390004 */ 	lh	$t9,0x4($s1)
/*  f02660c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f026610:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f026614:	8faa0114 */ 	lw	$t2,0x114($sp)
/*  f026618:	440d2000 */ 	mfc1	$t5,$f4
/*  f02661c:	44184000 */ 	mfc1	$t8,$f8
/*  f026620:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f026624:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f026628:	144a0055 */ 	bne	$v0,$t2,.L0f026780
/*  f02662c:	03192021 */ 	addu	$a0,$t8,$t9
/*  f026630:	146b0053 */ 	bne	$v1,$t3,.L0f026780
/*  f026634:	8fac011c */ 	lw	$t4,0x11c($sp)
/*  f026638:	548c0052 */ 	bnel	$a0,$t4,.L0f026784
/*  f02663c:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f026640:	864e0010 */ 	lh	$t6,0x10($s2)
/*  f026644:	8e4d000c */ 	lw	$t5,0xc($s2)
/*  f026648:	8e030008 */ 	lw	$v1,0x8($s0)
/*  f02664c:	01d70019 */ 	multu	$t6,$s7
/*  f026650:	00007812 */ 	mflo	$t7
/*  f026654:	01af2021 */ 	addu	$a0,$t5,$t7
/*  f026658:	24840007 */ 	addiu	$a0,$a0,0x7
/*  f02665c:	34980007 */ 	ori	$t8,$a0,0x7
/*  f026660:	3b190007 */ 	xori	$t9,$t8,0x7
/*  f026664:	17230031 */ 	bne	$t9,$v1,.L0f02672c
/*  f026668:	03202025 */ 	or	$a0,$t9,$zero
/*  f02666c:	96440016 */ 	lhu	$a0,0x16($s2)
/*  f026670:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f026674:	00003025 */ 	or	$a2,$zero,$zero
/*  f026678:	0fc4a557 */ 	jal	vtxstoreAllocate
/*  f02667c:	00003825 */ 	or	$a3,$zero,$zero
/*  f026680:	50400020 */ 	beqzl	$v0,.L0f026704
/*  f026684:	864d0010 */ 	lh	$t5,0x10($s2)
/*  f026688:	964a0016 */ 	lhu	$t2,0x16($s2)
/*  f02668c:	00001825 */ 	or	$v1,$zero,$zero
/*  f026690:	00002025 */ 	or	$a0,$zero,$zero
/*  f026694:	5940000e */ 	blezl	$t2,.L0f0266d0
/*  f026698:	ae020008 */ 	sw	$v0,0x8($s0)
/*  f02669c:	00402825 */ 	or	$a1,$v0,$zero
/*  f0266a0:	8e0b0008 */ 	lw	$t3,0x8($s0)
.L0f0266a4:
/*  f0266a4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0266a8:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f0266ac:	01646021 */ 	addu	$t4,$t3,$a0
/*  f0266b0:	8d810000 */ 	lw	$at,0x0($t4)
/*  f0266b4:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f0266b8:	aca1fffc */ 	sw	$at,-0x4($a1)
/*  f0266bc:	964f0016 */ 	lhu	$t7,0x16($s2)
/*  f0266c0:	006f082a */ 	slt	$at,$v1,$t7
/*  f0266c4:	5420fff7 */ 	bnezl	$at,.L0f0266a4
/*  f0266c8:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f0266cc:	ae020008 */ 	sw	$v0,0x8($s0)
.L0f0266d0:
/*  f0266d0:	86590010 */ 	lh	$t9,0x10($s2)
/*  f0266d4:	8e58000c */ 	lw	$t8,0xc($s2)
/*  f0266d8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0266dc:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0266e0:	01595023 */ 	subu	$t2,$t2,$t9
/*  f0266e4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0266e8:	030a2021 */ 	addu	$a0,$t8,$t2
/*  f0266ec:	24840007 */ 	addiu	$a0,$a0,0x7
/*  f0266f0:	348b0007 */ 	ori	$t3,$a0,0x7
/*  f0266f4:	396e0007 */ 	xori	$t6,$t3,0x7
/*  f0266f8:	1000000c */ 	b	.L0f02672c
/*  f0266fc:	01c02025 */ 	or	$a0,$t6,$zero
/*  f026700:	864d0010 */ 	lh	$t5,0x10($s2)
.L0f026704:
/*  f026704:	8e4c000c */ 	lw	$t4,0xc($s2)
/*  f026708:	8e030008 */ 	lw	$v1,0x8($s0)
/*  f02670c:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f026710:	01ed7823 */ 	subu	$t7,$t7,$t5
/*  f026714:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f026718:	018f2021 */ 	addu	$a0,$t4,$t7
/*  f02671c:	24840007 */ 	addiu	$a0,$a0,0x7
/*  f026720:	34990007 */ 	ori	$t9,$a0,0x7
/*  f026724:	3b380007 */ 	xori	$t8,$t9,0x7
/*  f026728:	03002025 */ 	or	$a0,$t8,$zero
.L0f02672c:
/*  f02672c:	10830014 */ 	beq	$a0,$v1,.L0f026780
/*  f026730:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f026734:	02b7001b */ 	divu	$zero,$s5,$s7
/*  f026738:	00005812 */ 	mflo	$t3
/*  f02673c:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f026740:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f026744:	01cb7023 */ 	subu	$t6,$t6,$t3
/*  f026748:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f02674c:	014e6821 */ 	addu	$t5,$t2,$t6
/*  f026750:	01b46021 */ 	addu	$t4,$t5,$s4
/*  f026754:	91820007 */ 	lbu	$v0,0x7($t4)
/*  f026758:	8fb800cc */ 	lw	$t8,0xcc($sp)
/*  f02675c:	00792021 */ 	addu	$a0,$v1,$t9
/*  f026760:	00027883 */ 	sra	$t7,$v0,0x2
/*  f026764:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f026768:	008b5021 */ 	addu	$t2,$a0,$t3
/*  f02676c:	01e01025 */ 	or	$v0,$t7,$zero
/*  f026770:	16e00002 */ 	bnez	$s7,.L0f02677c
/*  f026774:	00000000 */ 	nop
/*  f026778:	0007000d */ 	break	0x7
.L0f02677c:
/*  f02677c:	a1580003 */ 	sb	$t8,0x3($t2)
.L0f026780:
/*  f026780:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f026784:
/*  f026784:	2694000c */ 	addiu	$s4,$s4,0xc
/*  f026788:	1676ff97 */ 	bne	$s3,$s6,.L0f0265e8
/*  f02678c:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f026790:	1000ff75 */ 	b	.L0f026568
/*  f026794:	27de0008 */ 	addiu	$s8,$s8,0x8
.L0f026798:
/*  f026798:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02679c:	1441000e */ 	bne	$v0,$at,.L0f0267d8
/*  f0267a0:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f0267a4:	8fc20004 */ 	lw	$v0,0x4($s8)
/*  f0267a8:	3c0100ff */ 	lui	$at,0xff
/*  f0267ac:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0267b0:	00417024 */ 	and	$t6,$v0,$at
/*  f0267b4:	0c00698d */ 	jal	model0001a634
/*  f0267b8:	000e2982 */ 	srl	$a1,$t6,0x6
/*  f0267bc:	afa20100 */ 	sw	$v0,0x100($sp)
/*  f0267c0:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f0267c4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0267c8:	0c006b57 */ 	jal	modelNodeGetModelRelativePosition
/*  f0267cc:	27a600e8 */ 	addiu	$a2,$sp,0xe8
/*  f0267d0:	1000ff65 */ 	b	.L0f026568
/*  f0267d4:	27de0008 */ 	addiu	$s8,$s8,0x8
.L0f0267d8:
/*  f0267d8:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0267dc:	14410006 */ 	bne	$v0,$at,.L0f0267f8
/*  f0267e0:	00000000 */ 	nop
/*  f0267e4:	8fcd0004 */ 	lw	$t5,0x4($s8)
/*  f0267e8:	3c0100ff */ 	lui	$at,0xff
/*  f0267ec:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0267f0:	01a16024 */ 	and	$t4,$t5,$at
/*  f0267f4:	afac00c0 */ 	sw	$t4,0xc0($sp)
.L0f0267f8:
/*  f0267f8:	1000ff5b */ 	b	.L0f026568
/*  f0267fc:	27de0008 */ 	addiu	$s8,$s8,0x8
.L0f026800:
/*  f026800:	0c0071e1 */ 	jal	model0001c784
/*  f026804:	afa50110 */ 	sw	$a1,0x110($sp)
/*  f026808:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f02680c:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f026810:	1000000c */ 	b	.L0f026844
/*  f026814:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f026818:
/*  f026818:	0c0071f4 */ 	jal	model0001c7d0
/*  f02681c:	afa50110 */ 	sw	$a1,0x110($sp)
/*  f026820:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f026824:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f026828:	10000006 */ 	b	.L0f026844
/*  f02682c:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f026830:
/*  f026830:	0c007207 */ 	jal	modelAttachHead
/*  f026834:	afa50110 */ 	sw	$a1,0x110($sp)
/*  f026838:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f02683c:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f026840:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f026844:
/*  f026844:	10400003 */ 	beqz	$v0,.L0f026854
/*  f026848:	00000000 */ 	nop
/*  f02684c:	1000000d */ 	b	.L0f026884
/*  f026850:	00402825 */ 	or	$a1,$v0,$zero
.L0f026854:
/*  f026854:	10a0000b */ 	beqz	$a1,.L0f026884
/*  f026858:	00000000 */ 	nop
.L0f02685c:
/*  f02685c:	50a00007 */ 	beqzl	$a1,.L0f02687c
/*  f026860:	8ca50008 */ 	lw	$a1,0x8($a1)
/*  f026864:	8ca2000c */ 	lw	$v0,0xc($a1)
/*  f026868:	50400004 */ 	beqzl	$v0,.L0f02687c
/*  f02686c:	8ca50008 */ 	lw	$a1,0x8($a1)
/*  f026870:	10000004 */ 	b	.L0f026884
/*  f026874:	00402825 */ 	or	$a1,$v0,$zero
/*  f026878:	8ca50008 */ 	lw	$a1,0x8($a1)
.L0f02687c:
/*  f02687c:	14a0fff7 */ 	bnez	$a1,.L0f02685c
/*  f026880:	00000000 */ 	nop
.L0f026884:
/*  f026884:	54a0ff0d */ 	bnezl	$a1,.L0f0264bc
/*  f026888:	94a20000 */ 	lhu	$v0,0x0($a1)
.L0f02688c:
/*  f02688c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f026890:
/*  f026890:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f026894:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f026898:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f02689c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0268a0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0268a4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0268a8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0268ac:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0268b0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0268b4:	03e00008 */ 	jr	$ra
/*  f0268b8:	27bd0128 */ 	addiu	$sp,$sp,0x128
);
#else
// Mismatch: The bottom two tmp calculations should multiply by s32 0xc using
// shift operations, however doing this causes it to boot gdlptr out of s8 and
// use s8 for s32 0xc.
void chr0f0260c4(struct model *model, s32 hitpart, struct modelnode *node, struct coord *arg3)
{
	struct modelnode *bestnode = NULL;
	s32 mindist = 0x7fffffff;
	s32 bestcoords[3];
	struct modelnode *curnode;
	Gfx *gdlptr;
	Gfx *gdlptr2;
	struct gfxvtx *vertices;
	struct modelnode *posnode = NULL;
	struct coord relpos;
	struct coord spd4;
	struct coord spc8;
	s32 spbc[3];
	s32 alpha = 20 + (random() % 50);
	struct modelrodata_dl *rodata;
	struct modelrwdata_dl *rwdata;
	s32 spac = 0;
	s32 op;
	s32 nodetype;

	modelNodeGetModelRelativePosition(model, model0001a740(node), &relpos);

	spc8.f[0] = arg3->x - relpos.x;
	spc8.f[1] = arg3->y - relpos.y;
	spc8.f[2] = arg3->z - relpos.z;

	// This first pass over the node tree is deciding which modelnode to use.
	curnode = node;

	while (curnode) {
		s32 nodetype = curnode->type & 0xff;

		switch (nodetype) {
		case MODELNODETYPE_DL:
			rodata = &curnode->rodata->dl;
			rwdata = modelGetNodeRwData(model, curnode);

			if (rwdata->gdl == NULL) {
				break;
			}

			// By default, the model instance's displaylist points to the
			// one in the model definition. If it hasn't been changed we'll
			// use the space... after the model definition's colour table?
			// Let's hope that's not being used by other instances...
			if (rwdata->gdl == rodata->primary) {
				gdlptr = (Gfx *)((u32)rodata->colourtable + ((u32)rodata->primary & 0xffffff));
			} else {
				gdlptr = rwdata->gdl;
			}

			if (rodata->secondary) {
				gdlptr2 = (Gfx *)((u32)rodata->colourtable + ((u32)rodata->secondary & 0xffffff));
			} else {
				gdlptr2 = NULL;
			}

			// Iterate the primary DL, and once the end is reached
			// iterate the secondary DL if we have one.
			while (true) {
				op = *(s8 *)&gdlptr->words.w0;

				if (op == G_ENDDL) {
					if (gdlptr2) {
						// Switch to second DL
						gdlptr = gdlptr2;
						gdlptr2 = NULL;
					} else {
						// We're done
						gdlptr = NULL;
						break;
					}
				} else {
					// Note: We should have found an MTX op before VTX.
					if (op == G_VTX) {
						u8 *ptr = (u8 *)&gdlptr->words.w0;
						u32 word = gdlptr->words.w1 & 0xffffff;
						s32 numverts;
						s32 i;

						vertices = (struct gfxvtx *)((u32)rodata->vertices + word);
						numverts = (u32)ptr[1] / 16 + 1;

						if (posnode) {
							for (i = 0; i < numverts; i++) {
								s32 x = spbc[0] - vertices[i].x;
								s32 y = spbc[1] - vertices[i].y;
								s32 z = spbc[2] - vertices[i].z;
								s32 dist = x * x + y * y + z * z;

								if (dist < mindist) {
									mindist = dist;
									bestnode = curnode;
									bestcoords[0] = vertices[i].x + (s32)spd4.f[0];
									bestcoords[1] = vertices[i].y + (s32)spd4.f[1];
									bestcoords[2] = vertices[i].z + (s32)spd4.f[2];
								}
							}
						}
					} else if (op == G_MTX) {
						u32 addr = gdlptr->words.w1 & 0xffffff;
						posnode = model0001a634(model, addr / sizeof(Mtxf));
						modelNodeGetModelRelativePosition(model, posnode, &spd4);

						spbc[0] = spd4.x + spc8.x;
						spbc[1] = spd4.y + spc8.y;
						spbc[2] = spd4.z + spc8.z;
					}

					gdlptr++;
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c784(model, curnode);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, curnode);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, curnode);
			break;
		}

		if (curnode->child && (curnode == node
					|| (nodetype != MODELNODETYPE_BBOX && nodetype != MODELNODETYPE_11))) {
			curnode = curnode->child;
		} else {
			while (curnode) {
				if (curnode == node) {
					curnode = NULL;
					break;
				}

				if (curnode->next) {
					curnode = curnode->next;
					break;
				}

				curnode = curnode->parent;
			}
		}
	}

	if (bestnode == NULL) {
		return;
	}

	// Do a pass over the entire model's tree, looking for vertices that share
	// the chosen vertex, and darken then.
	curnode = model->filedata->rootnode;

	while (curnode) {
		nodetype = curnode->type & 0xff;

		switch (nodetype) {
		case MODELNODETYPE_DL:
			rodata = &curnode->rodata->dl;
			rwdata = modelGetNodeRwData(model, curnode);

			if (rwdata->gdl == NULL) {
				break;
			}

			if (rwdata->gdl == rodata->primary) {
				gdlptr = (Gfx *)((u32)rodata->colourtable + ((u32)rodata->primary & 0xffffff));
			} else {
				gdlptr = rwdata->gdl;
			}

			if (rodata->secondary) {
				gdlptr2 = (Gfx *)((u32)rodata->colourtable + ((u32)rodata->secondary & 0xffffff));
			} else {
				gdlptr2 = NULL;
			}

			while (true) {
				s32 op = *(s8 *)&gdlptr->words.w0;

				if (op == G_ENDDL) {
					if (gdlptr2) {
						// Switch to second DL
						gdlptr = gdlptr2;
						gdlptr2 = NULL;
					} else {
						// We're done
						gdlptr = NULL;
						break;
					}
				} else {
					// Note: We should have found an MTX op before VTX.
					if (op == G_VTX) {
						u8 *ptr = (u8 *)&gdlptr->words.w0;
						u32 word = gdlptr->words.w1 & 0xffffff;
						struct gfxvtx *vertices = (struct gfxvtx *)((u32)rodata->vertices + word);
						s32 numverts = (u32)ptr[1] / 16 + 1;
						s32 i;

						if (posnode) {
							for (i = 0; i < numverts; i++) {
								s32 x = vertices[i].x + (s32)spd4.f[0];
								s32 y = vertices[i].y + (s32)spd4.f[1];
								s32 z = vertices[i].z + (s32)spd4.f[2];

								if (x == bestcoords[0] && y == bestcoords[1] && z == bestcoords[2]) {
									u32 tmp = ALIGN8((u32)&rodata->vertices[(u32)rodata->numvertices]); // u32 0xc

									if ((u32)rwdata->colours == tmp) {
										struct colour *colours = vtxstoreAllocate(rodata->numcolours, VTXSTORETYPE_CHRCOL, 0, 0);
										s32 j;

										if (colours) {
											for (j = 0; j < rodata->numcolours; j++) {
												colours[j] = rwdata->colours[j];
											}

											rwdata->colours = colours;

											tmp = ALIGN8((s32)&rodata->vertices[rodata->numvertices]); // s32 0xc
										} else {
											tmp = ALIGN8((s32)&rodata->vertices[rodata->numvertices]); // s32 0xc
										}
									}

									if ((u32)rwdata->colours != tmp) {
										u32 offset = rwdata->vertices[word / 12u + i].colour >> 2; // u32 0xc (both divide and mult)
										struct colour *colours = (struct colour *) ((u32)rwdata->colours + spac);

										colours[offset].a = alpha;
									}
								}
							}
						}
					} else if (op == G_MTX) {
						u32 addr = gdlptr->words.w1 & 0xffffff;
						posnode = model0001a634(model, addr / sizeof(Mtxf));
						modelNodeGetModelRelativePosition(model, posnode, &spd4);
					} else if (op == G_SETCOLOR) {
						spac = gdlptr->words.w1 & 0xffffff;
					}

					gdlptr++;
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c784(model, curnode);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, curnode);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, curnode);
			break;
		}

		if (curnode->child) {
			curnode = curnode->child;
		} else {
			while (curnode) {
				if (curnode && curnode->next) {
					curnode = curnode->next;
					break;
				}

				curnode = curnode->parent;
			}
		}
	}
}
#endif

/**
 * Bruise a chr by darkening their vertices.
 *
 * This happens when the chr is shot, which creates the illusion of blood
 * soaking through their clothing.
 */
void chrBruise(struct model *model, s32 hitpart, struct modelnode *node, struct coord *arg3)
{
	struct modelnode *bestnode = NULL;
	bool ok;
	s32 nodetype;
	s32 mindist = 0x7fffffff;
	struct gfxvtx *vertices;
	s32 bestcoords[3];
	struct modelnode *curnode;
	Gfx *gdlptr;
	Gfx *gdlptr2;
	s32 op;
	struct modelnode *posnode = NULL;
	struct coord relpos;
	struct coord spd4;
	struct coord spc8;
	s32 spbc[3];
	s32 alpha = 20 + (random() % 50);
	struct modelrodata_dl *rodata;
	struct modelrwdata_dl *rwdata;
	s32 spac = 0;

	modelNodeGetModelRelativePosition(model, model0001a740(node), &relpos);

	spc8.f[0] = arg3->f[0] - relpos.f[0];
	spc8.f[1] = arg3->f[1] - relpos.f[1];
	spc8.f[2] = arg3->f[2] - relpos.f[2];

	// This first pass over the node tree is deciding which modelnode to use.
	curnode = node;

	while (curnode) {
		nodetype = curnode->type & 0xff;

		switch (nodetype) {
		case MODELNODETYPE_DL:
			rodata = &curnode->rodata->dl;
			rwdata = modelGetNodeRwData(model, curnode);

			if (rwdata->gdl == NULL) {
				break;
			}

			// By default, the model instance's displaylist points to the
			// one in the model definition. If it hasn't been changed we'll
			// use the space... after the model definition's colour table?
			// Let's hope that's not being used by other instances...
			if (rwdata->gdl == rodata->primary) {
				gdlptr = (Gfx *)((u32)rodata->colourtable + ((u32)rodata->primary & 0xffffff));
			} else {
				gdlptr = rwdata->gdl;
			}

			if (rodata->secondary) {
				gdlptr2 = (Gfx *)((u32)rodata->colourtable + ((u32)rodata->secondary & 0xffffff));
			} else {
				gdlptr2 = NULL;
			}

			// Iterate the primary DL, and once the end is reached
			// iterate the secondary DL if we have one.
			while (true) {
				op = *(s8 *)&gdlptr->words.w0;

				if (op == G_ENDDL) {
					if (gdlptr2) {
						// Switch to second DL
						gdlptr = gdlptr2;
						gdlptr2 = NULL;
					} else {
						// We're done
						gdlptr = NULL;
						break;
					}
				} else {
					// Note: We should have found an MTX op before VTX.
					if (op == G_VTX) {
						u8 *ptr = (u8 *)&gdlptr->words.w0;
						u32 word = gdlptr->words.w1 & 0xffffff;
						s32 numverts;
						s32 i;

						vertices = (struct gfxvtx *)((u32)rodata->vertices + word);
						numverts = (u32)ptr[1] / 16 + 1;

						if (posnode) {
							for (i = 0; i < numverts; i++) {
								s32 x = spbc[0] - vertices[i].x;
								s32 y = spbc[1] - vertices[i].y;
								s32 z = spbc[2] - vertices[i].z;
								s32 dist = x * x + y * y + z * z;

								if (dist < mindist) {
									mindist = dist;
									bestnode = curnode;
									bestcoords[0] = vertices[i].x + (s32)spd4.f[0];
									bestcoords[1] = vertices[i].y + (s32)spd4.f[1];
									bestcoords[2] = vertices[i].z + (s32)spd4.f[2];
								}
							}
						}
					} else if (op == G_MTX) {
						u32 addr = gdlptr->words.w1 & 0xffffff;
						posnode = model0001a634(model, addr / sizeof(Mtxf));
						modelNodeGetModelRelativePosition(model, posnode, &spd4);

						spbc[0] = spd4.x + spc8.x;
						spbc[1] = spd4.y + spc8.y;
						spbc[2] = spd4.z + spc8.z;
					}

					gdlptr++;
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c784(model, curnode);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, curnode);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, curnode);
			break;
		}

		if (curnode->child && (curnode == node
					|| (nodetype != MODELNODETYPE_BBOX && nodetype != MODELNODETYPE_11))) {
			curnode = curnode->child;
		} else {
			while (curnode) {
				if (curnode == node) {
					curnode = NULL;
					break;
				}

				if (curnode->next) {
					curnode = curnode->next;
					break;
				}

				curnode = curnode->parent;
			}
		}
	}

	ok = true;

	if (bestnode == NULL) {
		return;
	}

	// Do a pass over the entire model's tree, looking for vertices that share
	// the chosen vertex, and darken then.
	curnode = model->filedata->rootnode;

	while (curnode) {
		nodetype = curnode->type & 0xff;

		switch (nodetype) {
		case MODELNODETYPE_BBOX:
			if (g_Vars.hitboundscount) {
				s32 i;

				ok = false;

				for (i = 0; i < g_Vars.hitboundscount; i++) {
					if (g_Vars.hitnodes[i] == curnode) {
						ok = true;
					}
				}
			} else {
				ok = true;
			}

			break;
		case MODELNODETYPE_DL:
			if (ok) {
				rodata = &curnode->rodata->dl;
				rwdata = modelGetNodeRwData(model, curnode);

				if (rwdata->gdl == NULL) {
					break;
				}

				if (rwdata->gdl == rodata->primary) {
					gdlptr = (Gfx *)((u32)rodata->colourtable + ((u32)rodata->primary & 0xffffff));
				} else {
					gdlptr = rwdata->gdl;
				}

				if (rodata->secondary) {
					gdlptr2 = (Gfx *)((u32)rodata->colourtable + ((u32)rodata->secondary & 0xffffff));
				} else {
					gdlptr2 = NULL;
				}

				while (true) {
					s32 op = *(s8 *)&gdlptr->words.w0;

					if (op == G_ENDDL) {
						if (gdlptr2) {
							// Switch to second DL
							gdlptr = gdlptr2;
							gdlptr2 = NULL;
						} else {
							// We're done
							gdlptr = NULL;
							break;
						}
					} else {
						// Note: We should have found an MTX op before VTX.
						if (op == G_VTX) {
							u8 *ptr = (u8 *)&gdlptr->words.w0;
							u32 word = gdlptr->words.w1 & 0xffffff;
							struct gfxvtx *vertices = (struct gfxvtx *)((u32)rodata->vertices + word);
							s32 numverts = (u32)ptr[1] / 16 + 1;
							s32 i;

							if (posnode) {
								for (i = 0; i < numverts; i++) {
									s32 coordinate = vertices[i].x + (s32)spd4.f[0];

									if (coordinate == bestcoords[0]) {
										coordinate = vertices[i].y + (s32)spd4.f[1];

										if (coordinate == bestcoords[1]) {
											coordinate = vertices[i].z + (s32)spd4.f[2];

											if (coordinate == bestcoords[2]) {
												if ((u32)rwdata->colours == ALIGN8((u32)rodata->vertices + rodata->numvertices * sizeof(struct gfxvtx))) {
													struct colour *colours = vtxstoreAllocate(rodata->numcolours, VTXSTORETYPE_CHRCOL, 0, 0);
													s32 j;

													if (colours) {
														for (j = 0; j < rodata->numcolours; j++) {
															colours[j] = rwdata->colours[j];
														}

														rwdata->colours = colours;
													}
												}

												if ((u32)rwdata->colours != ALIGN8((u32)rodata->vertices + rodata->numvertices * sizeof(struct gfxvtx))) {
													s32 offset = rwdata->vertices[word / sizeof(struct gfxvtx) + i].colour >> 2;
													struct colour *colours = (struct colour *) ((u32)rwdata->colours + spac);

													colours[offset].a = alpha;
												}
											}
										}
									}
								}
							}
						} else if (op == G_MTX) {
							u32 addr = gdlptr->words.w1 & 0xffffff;
							posnode = model0001a634(model, addr / sizeof(Mtxf));
							modelNodeGetModelRelativePosition(model, posnode, &spd4);
						} else if (op == G_SETCOLOR) {
							spac = gdlptr->words.w1 & 0xffffff;
						}

						gdlptr++;
					}
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c784(model, curnode);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, curnode);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, curnode);
			break;
		}

		if (curnode->child) {
			curnode = curnode->child;
		} else {
			while (curnode) {
				if (curnode && curnode->next) {
					curnode = curnode->next;
					break;
				}

				curnode = curnode->parent;
			}
		}
	}
}

/**
 * Disfigure and darken a chr due to them dying from explosion damage.
 *
 * Vertices and colours are typically stored in the model definition which is
 * shared between all instances of that model. To have different vertices and
 * colours for a single instance requires copying that information out of the
 * model definition and into a vtx store. If the vtx store is full, the chr will
 * not become disfigured.
 *
 * The function looks for displaylist nodes in the chr's model. For each DL node
 * found, its vertex and colour information is copied to the vtx store. The GBI
 * commands are then iterated, looking for pointers into the vertex table. For
 * each pointer found, the vertices at that offset in the table are adjusted
 * randomly. Lastly, every colour in the node's colour table is darkened.
 */
void chrDisfigure(struct chrdata *chr, struct coord *exppos, f32 damageradius)
{
	struct modelnode *node;
	struct modelrodata_dl *rodata;
	struct modelrwdata_dl *rwdata;
	struct colour *colours;
	struct model *model = chr->model;
	struct gfxvtx *vertices;
	u32 stack;
	Gfx *gdlptr;
	Gfx *gdlptr2;
	struct modelnode *posnode = NULL;
	struct coord pos;
	s32 i;
	s32 j;

	u32 rand = random();

	if (g_Vars.mplayerisrunning || !chrIsDead(chr)) {
		return;
	}

	// Iterate the nodes in the chr model
	node = model->filedata->rootnode;

	while (node) {
		switch (node->type & 0xff) {
		case MODELNODETYPE_DL:
			rodata = &node->rodata->dl;
			rwdata = modelGetNodeRwData(model, node);

			if (rwdata->gdl == NULL) {
				break;
			}

			// Check that the node is using the modeldef's vertices
			// (ie. we haven't disfigured this node already)
			if (rwdata->vertices == rodata->vertices) {
				// Copy the vertices from the modeldef to the vtxstore
				if (rwdata->vertices == rodata->vertices) {
					struct gfxvtx *vertices = vtxstoreAllocate(rodata->numvertices, VTXSTORETYPE_CHRVTX, 0, 0);

					if (vertices) {
						for (i = 0; i < rodata->numvertices; i++) {
							vertices[i] = rwdata->vertices[i];
						}

						rwdata->vertices = vertices;
					}
				}

				// Copy the colours from the modeldef to the vtxstore
				if ((u32)rwdata->colours == ALIGN8((u32)&rodata->vertices[rodata->numvertices])) {
					colours = vtxstoreAllocate(rodata->numcolours, VTXSTORETYPE_CHRCOL, 0, 0);

					if (colours) {
						for (i = 0; i < rodata->numcolours; i++) {
							colours[i] = rwdata->colours[i];
						}

						rwdata->colours = colours;
					}
				}

				// Iterate the node's primary and secondary DLs, looking for
				// MTX and VTX pointers
				if (rwdata->vertices != rodata->vertices
						&& (u32)rwdata->colours != ALIGN8((u32)&rodata->vertices[rodata->numvertices])) {
					if (rwdata->gdl == rodata->primary) {
						gdlptr = (Gfx *)((u32)rodata->colourtable + ((s32)rodata->primary & 0xffffff));
					} else {
						gdlptr = rwdata->gdl;
					}

					if (rodata->secondary) {
						gdlptr2 = (Gfx *)((u32)rodata->colourtable + ((s32)rodata->secondary & 0xffffff));
					} else {
						gdlptr2 = NULL;
					}

					while (true) {
						s32 op = *(s8 *)&gdlptr->words.w0;

						if (op == G_ENDDL) {
							if (gdlptr2 == NULL) {
								// We're done
								gdlptr = NULL;
								break;
							}

							// Switch to second DL
							gdlptr = gdlptr2;
							gdlptr2 = NULL;
						} else {
							// Note: We should have found an MTX op before VTX.
							// MTX sets posnode.
							if (op == G_VTX) {
								// Iterate the vertex table and fudge them
								u8 *ptr = (u8 *)&gdlptr->words.w0;
								s32 word = gdlptr->words.w1 & 0xffffff;
								s32 numverts;

								vertices = (struct gfxvtx *)((u32)rwdata->vertices + word);
								numverts = (u32)ptr[1] / 16 + 1;

								if (posnode) {
									for (i = 0; i < numverts; i++) {
										rng2SetSeed(rand + vertices[i].x + vertices[i].y + vertices[i].z + (u32)pos.f[0] + (u32)pos.f[1] + (u32)pos.f[2]);

										if (vertices[i].x > 0) {
											vertices[i].x -= (s16)(random2() % 20);
										} else if (vertices[i].x < 0) {
											vertices[i].x += (s16)(random2() % 20);
										}

										if (vertices[i].y > 0) {
											vertices[i].y -= (s16)(random2() % 20);
										} else if (vertices[i].y < 0) {
											vertices[i].y += (s16)(random2() % 20);
										}

										if (vertices[i].z > 0) {
											vertices[i].z -= (s16)(random2() % 20);
										} else if (vertices[i].z < 0) {
											// @bug: should be z instead of y
											vertices[i].y += (s16)(random2() % 20);
										}
									}
								}
							} else if (op == G_MTX) {
								// Get the position of the node relative to the model
								u32 addr = gdlptr->words.w1 & 0xffffff;
								posnode = model0001a634(model, addr / sizeof(Mtxf));
								modelNodeGetModelRelativePosition(model, posnode, &pos);
							}

							gdlptr++;
						}
					}

					// Darken colours
					for (i = 0; i < rodata->numcolours; i++) {
						for (j = 0; j < 3; j++) {
							s32 tmp = rwdata->colours[i].bytes[j];
							tmp = tmp * 5 / 16;

							if (tmp < 0) {
								tmp = 0;
							}

							rwdata->colours[i].bytes[j] = tmp;
						}
					}
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model0001c784(model, node);
			break;
		case MODELNODETYPE_TOGGLE:
			model0001c7d0(model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			modelAttachHead(model, node);
			break;
		}

		// Find the next node to iterate
		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}
}

f32 chr0f0278a4(struct chrdata *chr)
{
	s32 i;
	f32 result;
	f32 highest = 0;

	if (chr->model) {
		result = model0001af80(chr->model);

		for (i = 0; i < 2; i++) {
			if (chr->weapons_held[i]) {
				struct defaultobj *obj = chr->weapons_held[i]->obj;
				f32 value = model0001af80(obj->model) * chr->model->scale;

				if (value > highest) {
					highest = value;
				}
			}
		}

		result += highest;

		if (chrGetShield(chr) > 0) {
			result += 10;
		}
	} else {
		result = 100;
	}

	return result;
}

void chr0f027994(struct prop *prop, struct shotdata *shotdata, bool arg2, bool arg3)
{
	struct coord spdc;
	struct coord spd0;
	struct chrdata *chr = prop->chr;

	if ((chr->chrflags & CHRCFLAG_HIDDEN) == 0 && (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)) {
		f32 fStack32 = chr0f0278a4(chr);

		if (prop->z - fStack32 < shotdata->unk34) {
			struct model *model = chr->model;
			s32 spc0 = 0;
			struct modelnode *node = NULL;
			s32 spb8 = 0;
			struct hitthing sp88;
			s32 sp84 = 0;
			struct modelnode *sp80 = NULL;
			Mtxf *iVar5 = model0001a60c(model);
			struct prop *next;
			struct prop *child;
			f32 sp70;
			Mtxf *mtx;
			f32 sp68;

			if (func0f06b39c(&shotdata->unk00, &shotdata->unk0c, (struct coord *)iVar5->m[3], fStack32)) {
				spb8 = 1;
				spc0 = 1;
			}

			if (spc0) {
				if (chrGetShield(chr) > 0.0f) {
					var8005efc0 = 10.0f / model->scale;
				}

				child = prop->child;

				while (child) {
					next = child->next;
					func0f0859a0(child, shotdata);
					child = next;
				}

				if (arg3 || var8005efc0 > 0.0f) {
					spc0 = model000225d4(model, &shotdata->unk00, &shotdata->unk0c, &node);

					while (spc0 > 0) {
						if (func0f084594(model, node, &shotdata->unk00, &shotdata->unk0c, &sp88, &sp84, &sp80)) {
							mtx4TransformVec(&model->matrices[sp84], &sp88.unk00, &spdc);
							mtx4TransformVecInPlace(camGetProjectionMtxF(), &spdc);
							mtx4RotateVec(&model->matrices[sp84], &sp88.unk0c, &spd0);
							mtx4RotateVecInPlace(camGetProjectionMtxF(), &spd0);
							break;
						}

						spc0 = model000225d4(model, &shotdata->unk00, &shotdata->unk0c, &node);
					}
				} else {
					spc0 = model000225d4(model, &shotdata->unk00, &shotdata->unk0c, &node);

					if (spc0 > 0) {
						if (func0f06bea0(model, model->filedata->rootnode, model->filedata->rootnode, &shotdata->unk00,
									&shotdata->unk0c, &sp88.unk00, &sp70, &node, &spc0, &sp84, &sp80)) {
							mtx4TransformVec(camGetProjectionMtxF(), &sp88.unk00, &spdc);
							mtx4RotateVec(camGetProjectionMtxF(), &sp88.unk0c, &spd0);
						} else {
							spc0 = 0;
						}
					}
				}

				if (var8005efc0 > 0.0f) {
					var8005efc0 = 0.0f;
				}
			}

			if (spc0 > 0) {
				mtx = camGetWorldToScreenMtxf();
				sp68 = spdc.x * mtx->m[0][2] + spdc.y * mtx->m[1][2] + spdc.z * mtx->m[2][2] + mtx->m[3][2];
				sp68 = -sp68;

				if (sp68 < shotdata->unk34) {
					func0f061fa8(shotdata, prop, sp68, spc0, node, &sp88, sp84, sp80, model, 1, chrGetShield(chr) > 0.0f, &spdc, &spd0);
				}
			}

			if (spb8 && spc0 <= 0 && prop->z <= shotdata->unk34 && arg2) {
				if (chrGetTargetProp(chr) == g_Vars.currentplayer->prop) {
					chr->chrflags |= CHRCFLAG_NEAR_MISS;
				}

				chr->numclosearghs++;
			}
		}
	}
}

/**
 * Handle a chr being shot.
 */
void chrHit(struct shotdata *shotdata, struct hit *hit)
{
	struct prop *prop;
	struct chrdata *chr;
	Mtxf spb0;
	struct coord hitpos;
	struct coord sp98;
	s16 sp90[3];
	u8 isclose = false;
	struct weaponfunc *func = gsetGetWeaponFunction(&shotdata->gset);
	f32 shield;

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
		isclose = true;
	}

	// The prop that was hit could be an item held by the chr,
	// so traverse the parents. The root parent is the chr itself.
	prop = hit->prop;

	while (prop->parent) {
		prop = prop->parent;
	}

	chr = prop->chr;

	if ((chr->chrflags & CHRCFLAG_HIDDEN) == 0) {
		sp98.x = shotdata->unk00.x - (hit->distance * shotdata->unk0c.x) / shotdata->unk0c.z;
		sp98.y = shotdata->unk00.y - (hit->distance * shotdata->unk0c.y) / shotdata->unk0c.z;
		sp98.z = shotdata->unk00.z - hit->distance;

		mtx4TransformVec(camGetProjectionMtxF(), &sp98, &hitpos);
		bgunSetHitPos(&hitpos);
		bgunPlayPropHitSound(&shotdata->gset, hit->prop, -1);

		chrEmitSparks(chr, hit->prop, hit->hitpart, &hitpos, &shotdata->dir, g_Vars.currentplayer->prop->chr);

		sp90[0] = hit->hitthing.unk00.x;
		sp90[1] = hit->hitthing.unk00.y;
		sp90[2] = hit->hitthing.unk00.z;

		shield = chrGetShield(chr);

		func0f0341dc(chr, gsetGetDamage(&shotdata->gset), &shotdata->dir, &shotdata->gset,
				g_Vars.currentplayer->prop, hit->hitpart, hit->prop, hit->node,
				hit->model, hit->hitthing.unk28 / 2, sp90);

		if (g_Vars.antiplayernum >= 0
				&& g_Vars.currentplayer == g_Vars.anti
				&& (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE)) {
			return;
		}

		if (g_Vars.coopplayernum >= 0
				&& g_Vars.coopfriendlyfire == 0
				&& prop->type == PROPTYPE_PLAYER) {
			return;
		}

		if (g_MissionConfig.iscoop && g_Vars.coopfriendlyfire == 0 && chr->team == TEAM_ALLY) {
			return;
		}

		if (shield <= 0) {
			if (hit->prop->type == PROPTYPE_WEAPON) {
				// Shot a chr's weapon
				struct weaponobj *weapon = hit->prop->weapon;
				struct surfacetype *type;
				s32 surfacetype;
				s32 index;

				// Shooting an explosive in a chr's hand causes it to explode
				if (weapon->weaponnum == WEAPON_GRENADE
						|| weapon->weaponnum == WEAPON_GRENADEROUND
						|| weapon->weaponnum == WEAPON_ROCKET
						|| weapon->weaponnum == WEAPON_HOMINGROCKET
						|| weapon->weaponnum == WEAPON_TIMEDMINE
						|| weapon->weaponnum == WEAPON_REMOTEMINE
						|| weapon->weaponnum == WEAPON_PROXIMITYMINE) {
					objSetDropped(hit->prop, DROPTYPE_DEFAULT);
					chr->hidden |= CHRHFLAG_00000001;
					objDamage(&weapon->base, gsetGetDamage(&shotdata->gset), &sp98, shotdata->gset.weaponnum, g_Vars.currentplayernum);
					return;
				}

				// Create decal depending on the weapon's surface type
				if (hit->hitthing.texturenum < 0 || hit->hitthing.texturenum >= NUM_TEXTURES) {
					surfacetype = SURFACETYPE_DEFAULT;
				} else {
					surfacetype = g_Textures[hit->hitthing.texturenum].surfacetype;
				}

				if (surfacetype >= 0 && surfacetype < 15) {
					type = g_SurfaceTypes[surfacetype];

					if (type->numwallhittexes > 0) {
						index = random() % type->numwallhittexes;

						wallhitCreate(
								&hit->hitthing.unk00,
								&hit->hitthing.unk0c,
								&shotdata->gunpos,
								0,
								0,
								type->wallhittexes[index],
								1,
								hit->prop,
								hit->mtxindex,
								0,
								g_Vars.currentplayer->prop->chr,
								0);
					}
				}

				// Drop gun
				if (chr->aibot == NULL && (chr->flags & CHRFLAG0_CANLOSEGUN)) {
					chr->gunprop = hit->prop;
					objSetDropped(hit->prop, DROPTYPE_DEFAULT);
					chr->hidden |= CHRHFLAG_00000001;
				}
			} else if (hit->hitpart == HITPART_HAT) {
				// Shot a chr's hat
				struct surfacetype *type;
				s32 index;

				// Create decal depending on the hat's surface type
				if (hit->hitthing.texturenum < 0) {
					type = g_SurfaceTypes[0];
				} else {
					type = g_SurfaceTypes[g_Textures[hit->hitthing.texturenum].surfacetype];
				}

				index = random() % type->numwallhittexes;

				wallhitCreate(
						&hit->hitthing.unk00,
						&hit->hitthing.unk0c,
						&shotdata->gunpos,
						0,
						0,
						type->wallhittexes[index],
						1,
						chr->weapons_held[2],
						hit->mtxindex,
						0,
						g_Vars.currentplayer->prop->chr,
						0);
			} else {
				// Shot a chr in the flesh
				s32 race = CHRRACE(chr);
				struct coord sp5c;
				Mtxf *sp58 = model0001a5cc(hit->model, hit->node, 0);

				// Create blood
				mtx0001719c(sp58->m, spb0.m);
				mtx4TransformVec(&spb0, &sp98, &sp5c);

#if VERSION >= VERSION_NTSC_1_0
				if (!chr->noblood
						&& race != RACE_DRCAROLL
						&& race != RACE_ROBOT
						&& race != RACE_EYESPY
						&& !isclose
						&& shotdata->gset.weaponnum != WEAPON_TRANQUILIZER) {
					u8 darker;

					if (chr->bodynum == BODY_MRBLONDE || race == RACE_SKEDAR) {
						darker = true;
					} else {
						darker = false;
					}

					if (!chrIsUsingPaintball(g_Vars.currentplayer->prop->chr)) {
						chrBruise(hit->model, hit->hitpart, hit->node, &sp5c);
					}

					splatsCreateForChrHit(prop, shotdata, &sp98, &hitpos, darker, 0, g_Vars.currentplayer->prop->chr);
				}
#else
				// NTSC beta wraps all the blood logic in this paintball check.
				// If paintball is enabled, neither blood nor paint is created.
				if (!chrIsUsingPaintball(g_Vars.currentplayer->prop->chr)
						&& !chr->noblood
						&& race != RACE_DRCAROLL
						&& race != RACE_ROBOT
						&& race != RACE_EYESPY
						&& !isclose
						&& shotdata->gset.weaponnum != WEAPON_TRANQUILIZER) {
					u8 darker;

					if (chr->bodynum == BODY_MRBLONDE || race == RACE_SKEDAR) {
						darker = true;
					} else {
						darker = false;
					}

					chrBruise(hit->model, hit->hitpart, hit->node, &sp5c);

					splatsCreateForChrHit(prop, shotdata, &sp98, &hitpos, darker, 0, g_Vars.currentplayer->prop->chr);
				}
#endif
			}
		}
	}
}

void chr0f028490(f32 arg1)
{
	// empty
}

void chr0f028498(bool value)
{
	var8006296c = value;
	var8005efbc = value;
}

void chr0f0284ac(s32 arg0)
{
	g_SelectedAnimNum -= arg0;

	if (g_SelectedAnimNum <= 0) {
		g_SelectedAnimNum = animGetNumAnimations() - 1;
	}
}

void chr0f0284f4(s32 arg0)
{
	g_SelectedAnimNum += arg0;

	if (g_SelectedAnimNum >= animGetNumAnimations()) {
		g_SelectedAnimNum = 1;
	}
}

void chr0f028544(void)
{
	var80062974 = !var80062974;
}

void chr0f02855c(s32 arg0)
{
	var80062978 = arg0;

	mainOverrideVariable("selectanimnum", &g_SelectedAnimNum);
}

void chrsCheckForNoise(f32 noiseradius)
{
	s32 i;
	f32 add = 0.075f;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].model) {
			struct prop *prop = g_ChrSlots[i].prop;

			if (prop && prop->type == PROPTYPE_CHR &&
					chrGetTargetProp(&g_ChrSlots[i]) == g_Vars.currentplayer->prop) {

				f32 distance = chrGetDistanceToCurrentPlayer(&g_ChrSlots[i]);

				if (distance == 0) {
					distance = 2;
				} else {
					distance = (noiseradius * 100 * g_ChrSlots[i].hearingscale * (1.0f + add)) / distance;
				}

				if (distance > 1.0f) {
					chrRecordLastHearTargetTime(&g_ChrSlots[i]);
#if PIRACYCHECKS
					{
						s32 *i = (s32 *)&__scHandleRetrace;
						s32 *end = (s32 *)&__scHandleTasks;
						u32 checksum = 0;

						while (i < end) {
							checksum *= 2;
							checksum += *i;
							i++;
						}

						if (checksum != CHECKSUM_PLACEHOLDER) {
							g_HeadsAndBodies[BODY_SKEDARKING].filenum = 0;
						}
					}
#endif
				}
			}
		}
	}
}

struct chrdata *chrFindByLiteralId(s32 chrnum)
{
	if (chrnum >= 0 && chrnum < ARRAYCOUNT(g_ChrIndexesByChrnum) && g_ChrIndexesByChrnum[chrnum] >= 0) {
		return &g_ChrSlots[g_ChrIndexesByChrnum[chrnum]];
	}

	return NULL;
}

struct prop *chrGetHeldProp(struct chrdata *chr, s32 hand)
{
	return chr->weapons_held[hand];
}

struct prop *chrGetHeldUsableProp(struct chrdata *chr, s32 hand)
{
	struct prop *prop = chr->weapons_held[hand];

	if (prop) {
		struct weaponobj *weapon = prop->weapon;

		if (!weaponHasFlag(weapon->weaponnum, WEAPONFLAG_AICANUSE)) {
			prop = NULL;
		}
	}

	return prop;
}

struct prop *chrGetTargetProp(struct chrdata *chr)
{
	struct prop *ret;

	if (chr->target == -1) {
		ret = g_Vars.players[chr->p1p2]->prop;
	} else {
		ret = g_Vars.props + chr->target;
	}

	return ret;
}

bool chrUpdateGeometry(struct prop *prop, u8 **start, u8 **end)
{
	struct chrdata *chr = prop->chr;

	if (chr->actiontype != ACT_DEAD &&
			chr->actiontype != ACT_DRUGGEDKO &&
			(chr->chrflags & (CHRCFLAG_PERIMDISABLEDTMP | CHRCFLAG_HIDDEN)) == 0 &&
			(chr->hidden & CHRHFLAG_PERIMDISABLED) == 0) {
		chr->geo.header.type = GEOTYPE_CYL;

		if (chr->actiontype == ACT_DIE || chr->actiontype == ACT_DRUGGEDDROP) {
			chr->geo.header.flags = GEOFLAG_BLOCK_SHOOT;
		} else {
			chr->geo.header.flags = GEOFLAG_WALL | GEOFLAG_BLOCK_SHOOT;
		}

		chr->geo.ymin = chr->manground;
		chr->geo.ymax = chr->manground + chr->height;

		if (chr->actiontype == ACT_SKJUMP) {
			if (chr->manground > chr->act_skjump.ground) {
				chr->geo.ymin = chr->act_skjump.ground;
			}
		}

		chr->geo.x = prop->pos.x;
		chr->geo.z = prop->pos.z;
		chr->geo.radius = chr->radius;

		if (g_Vars.useperimshoot) {
			chr->geo.radius = 15;
		}

		*start = (void *) &chr->geo;
		*end = *start + sizeof(struct geocyl);

		return true;
	}

	*end = NULL;
	*start = NULL;

	return false;
}

void chrGetBbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin)
{
	struct chrdata *chr = prop->chr;

	*radius = chr->radius;
	*ymax = chr->manground + chr->height;
	*ymin = chr->manground + 20;

	if (chr->actiontype == ACT_SKJUMP && chr->act_skjump.ground < chr->manground) {
		*ymin = chr->act_skjump.ground + 20;
	}
}

f32 chrGetGround(struct prop *prop)
{
	struct chrdata *chr = prop->chr;
	return chr->ground;
}

bool chrCalculateAutoAim(struct prop *prop, struct coord *arg1, f32 *arg2, f32 *arg3)
{
	struct chrdata *chr = prop->chr;

	// Check if the chr is eligible for autoaim
	if ((prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)
			&& chr->actiontype != ACT_DIE
			&& chr->actiontype != ACT_DRUGGEDDROP
			&& chr->actiontype != ACT_DRUGGEDKO
			&& chr->actiontype != ACT_DEAD
			&& (chr->chrflags & CHRCFLAG_NOAUTOAIM) == 0
			&& ((chr->hidden & CHRHFLAG_CLOAKED) == 0 || USINGDEVICE(DEVICE_IRSCANNER))
			&& !(prop->type == PROPTYPE_PLAYER && g_Vars.players[playermgrGetPlayerNumByProp(prop)]->isdead)
			&& !(g_Vars.coopplayernum >= 0 && (prop == g_Vars.bond->prop || prop == g_Vars.coop->prop))) {
		struct model *model = chr->model;
		Mtxf *mtx1;
		Mtxf *mtx2;

		if (model->filedata->skel == &g_SkelChr) {
			mtx1 = &model->matrices[0];
			mtx2 = &model->matrices[1];
			arg1->z = mtx2->m[3][2] + (mtx1->m[3][2] - mtx2->m[3][2]) * 0.5f;
		} else if (model->filedata->skel == &g_SkelSkedar) {
			mtx2 = &model->matrices[0];
			arg1->z = mtx2->m[3][2];
		} else if (model->filedata->skel == &g_SkelDrCaroll) {
			mtx2 = &model->matrices[0];
			arg1->z = mtx2->m[3][2];
		} else {
			arg1->z = model->matrices[0].m[3][2];
		}

		if (arg1->z < 0) {
			if (model->filedata->skel == &g_SkelChr) {
				arg1->x = mtx2->m[3][0] + (mtx1->m[3][0] - mtx2->m[3][0]) * 0.5f;
				arg1->y = mtx2->m[3][1] + (mtx1->m[3][1] - mtx2->m[3][1]) * 0.5f;
			} else if (model->filedata->skel == &g_SkelSkedar) {
				arg1->x = mtx2->m[3][0];
				arg1->y = mtx2->m[3][1];
			} else if (model->filedata->skel == &g_SkelDrCaroll) {
				arg1->x = mtx2->m[3][0];
				arg1->y = mtx2->m[3][1];
			} else {
				arg1->x = model->matrices[0].m[3][0];
				arg1->y = model->matrices[0].m[3][1];
			}

			arg3[0] = arg3[1] = 0;
			arg2[0] = arg2[1] = 0;

			func0f067d88(model, &arg2[1], &arg2[0], &arg3[1], &arg3[0]);

			return true;
		}
	}

	return false;
}

bool chr0f028d50(struct prop *arg0, struct prop *arg1, struct modelnode *node, struct model *model, s32 *total)
{
	if (arg1 == arg0) {
		*total += model0001a524(node, 0);
		return true;
	}

	*total += model->filedata->nummatrices;

	if (arg0->child && chr0f028d50(arg0->child, arg1, node, model, total) > 0) {
		return true;
	}

	if (arg0->next && chr0f028d50(arg0->next, arg1, node, model, total) > 0) {
		return true;
	}

	return false;
}

s32 chr0f028e18(struct prop *arg0, struct modelnode *node, struct model *model, struct prop *arg3)
{
	s32 result = 0;

	if (chr0f028d50(arg3, arg0, node, model, &result)) {
		return result;
	}

	return -1;
}

bool chr0f028e6c(s32 arg0, struct prop *prop, struct prop **propptr, struct modelnode **nodeptr, struct model **modelptr)
{ \
	while (true) {
		bool result = false;
		struct model *model;
		s32 stack;

		if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
			model = prop->chr->model;
		} else {
			model = prop->obj->model;
		}

		if (1);

		if (arg0 >= model->filedata->nummatrices) {
			arg0 -= model->filedata->nummatrices;

			if (prop->child) {
				result = chr0f028e6c(arg0, prop->child, propptr, nodeptr, modelptr);
			}

			if (prop->next && !result) {
				prop = prop->next;
				continue;
			}
		} else {
			*propptr = prop;
			*nodeptr = model0001a634(model, arg0);
			*modelptr = model;
			result = true;
		}

		return result;
	}
}

void shieldhitCreate(struct prop *prop, f32 shield, struct prop *arg2, struct modelnode *node, struct model *model, s32 side, s16 *arg6)
{
	struct shieldhit *shieldhit = NULL;
	s32 i;
	s32 j;

	// Find any slot that isn't in use (ie. prop is NULL)
	for (i = 0; i < 20; i++) {
		if (g_ShieldHits[i].prop == NULL) {
			shieldhit = &g_ShieldHits[i];
			break;
		}
	}

	// If all slots are in use, take the oldest one
	if (shieldhit == NULL) {
		struct shieldhit *oldesthit = NULL;
		s32 oldestframe = g_Vars.lvframe60;

		for (i = 0; i < 20; i++) {
			if (g_ShieldHits[i].lvframe60 < oldestframe) {
				oldesthit = &g_ShieldHits[i];
				oldestframe = g_ShieldHits[i].lvframe60;
			}
		}

		shieldhit = oldesthit;
	}

	if (shieldhit) {
		shieldhit->prop = prop;
		shieldhit->node = node;
		shieldhit->model = model;
		shieldhit->side = side;
		shieldhit->lvframe60 = g_Vars.lvframe60;

		for (i = 0; i < 32; i++) {
			shieldhit->unk018[i] = -1;
		}

		shieldhit->unk011 = 2 + (random() % 6);
		shieldhit->shield = shield;

		if (arg6) {
			shieldhit->unk012 = arg6[0];
			shieldhit->unk014 = arg6[1];
			shieldhit->unk016 = arg6[2];
		} else {
			shieldhit->unk012 = 0x7fff;
		}

		if (node) {
			bool pass = true;

			for (i = 0; i < 20; i++) {
				if (g_ShieldHits[i].prop == prop) {
					for (j = 0; j < 32; j++) {
						if (shieldhit->unk018[j] != -1 && shieldhit->unk018[j] != -2) {
							pass = false;
							break;
						}
					}

					if (!pass) {
						break;
					}
				}
			}

			if (pass) {
				s32 index = chr0f028e18(arg2, node, model, prop);

				if (index < 32) {
					shieldhit->unk018[index] = 0;
					shieldhit->unk038[index] = 0;
				}
			}
		}

		if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
			prop->chr->hidden2 |= CHRH2FLAG_SHIELDHIT;
		} else if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
			prop->obj->flags3 |= OBJFLAG3_SHIELDHIT;
		}
	}

	g_ShieldHitActive = true;
}

void shieldhitRemove(struct shieldhit *shieldhit)
{
	s32 exists = false;
	s32 i;
	struct prop *prop = shieldhit->prop;
	shieldhit->prop = NULL;

	// Check if there are other shield hits active
	g_ShieldHitActive = false;

	for (i = 0; i < 20; i++) {
		if (g_ShieldHits[i].prop) {
			g_ShieldHitActive = true;
			break;
		}
	}

	// Check if the prop being removed has other shield hits too
	for (i = 0; i < 20; i++) {
		if (prop == g_ShieldHits[i].prop) {
			exists = true;
			break;
		}
	}

	if (!exists) {
		// Mark prop as shield no longer visible
		if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
			struct chrdata *chr = prop->chr;
			chr->hidden2 &= ~CHRH2FLAG_SHIELDHIT;
		} else if (prop->type == PROPTYPE_OBJ
				|| prop->type == PROPTYPE_WEAPON
				|| prop->type == PROPTYPE_DOOR) {
			struct defaultobj *obj = prop->obj;
			obj->flags3 &= ~OBJFLAG3_SHIELDHIT;
		}
	}
}

void shieldhitsRemoveByProp(struct prop *prop)
{
	s32 i;

	for (i = 0; i < 20; i++) {
		if (prop == g_ShieldHits[i].prop) {
			shieldhitRemove(&g_ShieldHits[i]);
		}
	}
}

s32 chr0f02932c(struct prop *prop, s32 arg1)
{
	s32 result = -1;
	struct modelnode *node2;
	struct prop *prop2;
	struct modelnode *node;
	struct model *model;

	if (chr0f028e6c(arg1, prop, &prop2, &node, &model) && node) {
		node2 = model0001a784(node);

		if (node2) {
			result = chr0f028e18(prop2, node2, model, prop);
		} else if (prop2->parent && model->attachedtomodel && model->attachedtonode) {
			result = chr0f028e18(prop2->parent, model->attachedtonode, model->attachedtomodel, prop);
		}
	}

	return result;
}

s32 chr0f0293ec(struct prop *prop, s32 cmnum)
{
	s32 result = -1;
	struct modelnode *node2;
	struct prop *prop2;
	struct modelnode *node;
	struct model *model;

	if (chr0f028e6c(cmnum, prop, &prop2, &node, &model) && node) {
		node2 = model0001a7cc(node);

		if (node2) {
			result = chr0f028e18(prop2, node2, model, prop);
		} else {
			struct prop *child = prop2->child;

			while (child) {
				struct model *parentmodel = child->parentmodel;

				if (model == parentmodel->attachedtomodel) {
					if (node == parentmodel->attachedtonode) {
						result = chr0f028e18(child, parentmodel->filedata->rootnode, parentmodel, prop);
						break;
					}
				}

				child = child->next;
			}
		}
	}

	return result;
}

s32 chr0f0294cc(struct prop *prop, s32 arg1)
{
	s32 result = -1;
	struct prop *child;
	struct prop *prop2;
	struct modelnode *node2;
	struct model *model2;

	if (chr0f028e6c(arg1, prop, &prop2, &node2, &model2) && node2) {
		struct modelnode *node3 = model0001a85c(node2);

		if (node3) {
			result = chr0f028e18(prop2, node3, model2, prop);
		} else if (model0001a784(node2) == NULL && prop2->parent) {
			child = prop2->parent->child;

			while (child && child != prop2) {
				child = child->next;
			}

			if (child) {
				child = child->next;

				while (child) {
					struct model *parent = child->parentmodel;

					if (parent->attachedtomodel == model2->attachedtomodel) {
						if (parent->attachedtonode == model2->attachedtonode) {
							result = chr0f028e18(child, parent->filedata->rootnode, parent, prop);
							break;
						}
					}

					child = child->next;
				}
			}
		}
	}

	return result;
}

void chr0f0295f8(f32 arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
	if (arg0 < 1.5f) {
		*arg1 = 57 - (s32)((1.5f - arg0) * 28.0f);
		*arg2 = 75 - (s32)((1.5f - arg0) * 20.0f);
		*arg3 = 0;
		return;
	}

	if (arg0 < 3.0f) {
		*arg1 = 102 - (s32)((3.0f - arg0) * 30.0f);
		*arg2 = 90 - (s32)((3.0f - arg0) * 10.0f);
		*arg3 = 0;
		return;
	}

	if (arg0 < 4.5f) {
		*arg1 = 174 - (s32)((4.5f - arg0) * 48.0f);
		*arg2 = 129 - (s32)((4.5f - arg0) * 26.0f);
		*arg3 = 0;
		return;
	}

	if (arg0 < 6.0f) {
		*arg1 = 162 - (s32)((6.0f - arg0) * -8.0f);
		*arg2 = 54 - (s32)((6.0f - arg0) * -50.0f);
		*arg3 = 0;
		return;
	}

	*arg1 = 162;
	*arg2 = 54;
	*arg3 = 0;
}

f32 propGetShieldThing(struct prop **propptr)
{
	struct prop *prop = *propptr;

	if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
		return chrGetShield(prop->chr);
	}

	if (prop->type == PROPTYPE_OBJ
			|| prop->type == PROPTYPE_WEAPON
			|| prop->type == PROPTYPE_DOOR) {
		if (prop->obj->flags3 & OBJFLAG3_SHOWSHIELD) {
			return 4;
		}

		// If this function is returning the shield amount,
		// why would it return 8 for all objects here?
		return 8;
	}

	return 0;
}

bool g_ShieldHitActive = false;

Gfx *chrRenderShieldComponent(Gfx *gdl, struct shieldhit *hit, struct prop *prop, struct model *model,
		struct modelnode *node, s32 side, s32 arg6, s32 arg7, s32 alpha)
{
	struct modelrodata_bbox *bbox = &node->rodata->bbox;
	struct gfxvtx vtxtemplate = {0};
	struct gfxvtx *vertices;
	struct colour *colours;
	Mtxf *modelmtx;
	s32 i;
	s32 xmin;
	s32 xmax;
	s32 ymin;
	s32 ymax;
	s32 zmin;
	s32 zmax;
	s32 j;
	u32 stack;
	s16 sp180[8][3];
	u8 alpha1;
	u8 alpha2;
	s16 st1;
	s16 st2;
	s16 st4;
	s16 st3;
	f32 gap;
	f32 shieldamount;
	s32 cloakfade;
	s32 cmcount;

	s32 sp104[6][4] = {
		{ 0, 1, 3, 2 },
		{ 7, 5, 4, 6 },
		{ 5, 1, 0, 4 },
		{ 2, 3, 7, 6 },
		{ 0, 2, 6, 4 },
		{ 7, 3, 1, 5 },
	};

	s32 red1;
	s32 green1;
	s32 blue1;
	s32 red2;
	s32 green2;
	s32 blue2;
	s32 red3;
	s32 green3;
	s32 blue3;
	s32 mtxindex;

	if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
		struct chrdata *chr = prop->chr;
		gap = 10.0f / chr->model->scale;
		shieldamount = chrGetShield(chr);
		cloakfade = chr->cloakfadefrac;
		cmcount = chr->cmcount;
	} else {
		struct defaultobj *obj = prop->obj;
		gap = 0.0f;
		cloakfade = 64;
		cmcount = 0;
		shieldamount = (obj->flags3 & OBJFLAG3_SHOWSHIELD) ? 4.0f : 8.0f;
	}

	mtxindex = model0001a524(node, 0);
	modelmtx = &model->matrices[mtxindex];

	xmin = bbox->xmin - gap;
	xmax = bbox->xmax + gap;
	ymin = bbox->ymin - gap;
	ymax = bbox->ymax + gap;
	zmin = bbox->zmin - gap;
	zmax = bbox->zmax + gap;

	sp180[0][0] = xmin;
	sp180[0][1] = ymin;
	sp180[0][2] = zmin;

	sp180[1][0] = xmin;
	sp180[1][1] = ymin;
	sp180[1][2] = zmax;

	sp180[2][0] = xmin;
	sp180[2][1] = ymax;
	sp180[2][2] = zmin;

	sp180[3][0] = xmin;
	sp180[3][1] = ymax;
	sp180[3][2] = zmax;

	sp180[4][0] = xmax;
	sp180[4][1] = ymin;
	sp180[4][2] = zmin;

	sp180[5][0] = xmax;
	sp180[5][1] = ymin;
	sp180[5][2] = zmax;

	sp180[6][0] = xmax;
	sp180[6][1] = ymax;
	sp180[6][2] = zmin;

	sp180[7][0] = xmax;
	sp180[7][1] = ymax;
	sp180[7][2] = zmax;

	gSPMatrix(gdl++, osVirtualToPhysical(modelmtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	if (side == -7) {
		colours = gfxAllocateColours(1);

		gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);

		colours[0].r = 0xff;
		colours[0].g = 0xff;
		colours[0].b = 0xff;

		if (cloakfade < 64) {
			colours[0].a = (s32) (cloakfade * (f32) alpha * (1.0f / 85.0f));
		} else {
			colours[0].a = (s32) ((127 - cloakfade) * (f32) alpha * (1.0f / 85.0f));
		}

		vertices = gfxAllocateVertices(24);

		for (i = 0; i < 6; i++) {
			for (j = 0; j < 4; j++) {
				vertices[j] = vtxtemplate;
				vertices[j].x = sp180[sp104[i][j]][0];
				vertices[j].y = sp180[sp104[i][j]][1];
				vertices[j].z = sp180[sp104[i][j]][2];
				vertices[j].colour = 0;
			}

			vertices[0].s = 0;
			vertices[0].t = 0;
			vertices[1].s = 512;
			vertices[1].t = 0;
			vertices[2].s = 512;
			vertices[2].t = 512;
			vertices[3].s = 0;
			vertices[3].t = 512;

			gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);

			gDPTri2(gdl++, 0, 1, 2, 0, 2, 3);

			vertices += 4;
		}
	} else {
		f32 shield;

		texSelect(&gdl, &g_TexShieldConfigs[0], 4, 1, 2, true, NULL);

		if (side >= 0) {
			shield = hit->shield;
		} else {
			shield = shieldamount;

			if (side == -2) {
				if (hit->unk011 < arg7) {
					shield = 0.0f;
				} else {
					shield *= ((4.0f * hit->unk011) - arg7 + 1.0f) / (4.0f * hit->unk011);
				}
			}
		}

		chr0f0295f8(shield, &red1, &green1, &blue1);

		red2 = red1 - 20;
		green2 = green1 - 20;
		blue2 = blue1 - 20;

		if (red2 < 0) {
			red2 = 0;
		}

		if (green2 < 0) {
			green2 = 0;
		}

		if (blue2 < 0) {
			blue2 = 0;
		}

		red3 = red1 - 60;
		green3 = green1 - 60;
		blue3 = blue1 - 60;

		if (red3 < 0) {
			red3 = 0;
		}

		if (green3 < 0) {
			green3 = 0;
		}

		if (blue3 < 0) {
			blue3 = 0;
		}

		st1 = (sinf((g_Vars.thisframestart240 % TICKS(1200)) * PALUPF(0.005235154f)) + 1.0f) * 0.5f * 32.0f * 32.0f;
		st2 = (cosf((g_Vars.thisframestart240 % TICKS(1200)) * PALUPF(0.005235154f)) + 1.0f) * 0.5f * 32.0f * 32.0f;
		st3 = st1 + 512;
		st4 = st2 + 512;

		if (side == -3 || side == -4 || side == -5 || side == -6) {
			colours = gfxAllocateColours(1);

			gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);

			if (side == -3) {
				colours[0].r = red2;
				colours[0].g = green2;
				colours[0].b = blue2;
				colours[0].a = (cmcount < 10) ? (s32) (alpha * 0.5882353f) : 0;
			} else {
				colours[0].r = red3;
				colours[0].g = green3;
				colours[0].b = blue3;

				if (cmcount < 10) {
					if (side == -4) {
						colours[0].a = (s32) (alpha * 0.3137255f);
					} else if (side == -5) {
						colours[0].a = (s32) (alpha * 0.23529412f);
					} else if (side == -6) {
						colours[0].a = (s32) (alpha * 0.15686275f);
					}
				} else {
					colours[0].a = 0;
				}
			}

			vertices = gfxAllocateVertices(24);

			if ((prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR)
					&& (prop->obj->flags3 & OBJFLAG3_SHOWSHIELD)) {
				f32 mult = (sinf((g_Vars.thisframestart240 % TICKS(350)) * (PAL ? 0.021588264033198f : 0.0179491f)) + 1.0f) * 0.5f;

				colours->a = 50 + (u8) (s32) (120.0f * mult);
				colours->r = (u8) red2 + 50.0f * mult;
				colours->g = (u8) green2 + 50.0f * mult;
				colours->b = (u8) blue2 + 50.0f * mult;
			} else {
				st3 = 512;
				st1 = 0;
				st2 = 0;
				st4 = 512;
			}

			for (i = 0; i < 6; i++) {
				for (j = 0; j < 4; j++) {
					vertices[j] = vtxtemplate;
					vertices[j].x = sp180[sp104[i][j]][0];
					vertices[j].y = sp180[sp104[i][j]][1];
					vertices[j].z = sp180[sp104[i][j]][2];
					vertices[j].colour = 0;
				}

				vertices[0].s = st1;
				vertices[0].t = st2;
				vertices[1].s = st3;
				vertices[1].t = st2;
				vertices[2].s = st3;
				vertices[2].t = st4;
				vertices[3].s = st1;
				vertices[3].t = st4;

				gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);

				gDPTri2(gdl++, 0, 1, 2, 0, 2, 3);

				vertices += 4;
			}
		} else if (side == -2) {
			f32 alpha3;

			if (hit->unk011 < arg7) {
				alpha3 = 0.0f;
			} else {
#if PAL
				alpha3 = ((TICKS(30.0f) - arg6) * 6.4f + 40.0f) * ((hit->unk011 - (f32) arg7 + 1.0f) / hit->unk011);
#else
				alpha3 = ((TICKS(30.0f) - arg6) * 5.3333335f + 40.0f) * ((hit->unk011 - (f32) arg7 + 1.0f) / hit->unk011);
#endif
				alpha3 *= alpha * (1.0f / 255.0f);
			}

			if (alpha3 > 255.0f) {
				alpha3 = 255.0f;
			} else if (alpha3 < 0.0f) {
				alpha3 = 0.0f;
			}

			colours = gfxAllocateColours(3);

			gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 3);

			colours[0].r = red3;
			colours[1].r = red3;
			colours[0].g = green3;
			colours[1].g = green3;
			colours[0].b = blue3;
			colours[1].b = blue3;
			colours[0].a = (s32) alpha3;
			colours[1].a = 0;

			vertices = gfxAllocateVertices(30);

			for (i = 0; i < 6; i++) {
				for (j = 0; j < 4; j++) {
					vertices[j] = vtxtemplate;
					vertices[j].x = sp180[sp104[i][j]][0];
					vertices[j].y = sp180[sp104[i][j]][1];
					vertices[j].z = sp180[sp104[i][j]][2];
					vertices[j].colour = 0;
				}

				vertices[0].s = st1;
				vertices[0].t = st2;
				vertices[1].s = st3;
				vertices[1].t = st2;
				vertices[2].s = st3;
				vertices[2].t = st4;
				vertices[3].s = st1;
				vertices[3].t = st4;

				vertices[4] = vtxtemplate;
				vertices[4].x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) >> 2;
				vertices[4].y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) >> 2;
				vertices[4].z = (vertices[0].z + vertices[1].z + vertices[2].z + vertices[3].z) >> 2;
				vertices[4].s = (st1 + st3) >> 1;
				vertices[4].t = (st2 + st4) >> 1;
				vertices[4].colour = 4;

				gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 5);

				gDPTri4(gdl++, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4);

				vertices += 5;
			}
		} else if (side < 0) {
			vertices = gfxAllocateVertices(12);

			if (side == -1) {
				if (g_Vars.lvframe60 - hit->lvframe60 <= TICKS(80)) {
					f32 tmp = (hit->lvframe60 - g_Vars.lvframe60 + TICKS(80)) * (PAL ? 3.8636362552643f : 3.1875f);
					tmp *= alpha * (1.0f / 255.0f);

					alpha1 = (s32) tmp;
				} else {
					alpha1 = 0;
				}

				colours = gfxAllocateColours(1);

				gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);

				colours[0].r = red1;
				colours[0].g = green1;
				colours[0].b = blue1;
				colours[0].a = alpha1;
			} else if (side == -2) {
				f32 alpha4;

				if (hit->unk011 < arg7) {
					alpha4 = 0.0f;
				} else {
					alpha4 = (((TICKS(30.0f) - (f32) arg6) * PALUPF(4.0f)) + 40.0f)
						* (((hit->unk011 - (f32) arg7) + 1.0f) / hit->unk011);
					alpha4 *= alpha * (1.0f / 255.0f);
				}

				if (alpha4 > 255.0f) {
					alpha4 = 255.0f;
				} else if (alpha4 < 0.0f) {
					alpha4 = 0.0f;
				}

				colours = gfxAllocateColours(1);

				gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);

				colours[0].r = red3;
				colours[0].g = green3;
				colours[0].b = blue3;
				colours[0].a = (s32) alpha4;
			}

			for (j = 0; j < 8; j++) {
				vertices[j] = vtxtemplate;
				vertices[j].x = sp180[j][0];
				vertices[j].y = sp180[j][1];
				vertices[j].z = sp180[j][2];
				vertices[j].colour = 0;
			}

			vertices[0].s = st1;
			vertices[0].t = st2;
			vertices[1].s = st3;
			vertices[1].t = st2;
			vertices[5].s = st3;
			vertices[5].t = st4;
			vertices[4].s = st1;
			vertices[4].t = st4;
			vertices[3].s = st1;
			vertices[3].t = st2;
			vertices[2].t = st2;
			vertices[2].s = st3;
			vertices[6].s = st3;
			vertices[6].t = st4;
			vertices[7].s = st1;
			vertices[7].t = st4;

			vertices[8] = vtxtemplate;
			vertices[8].x = sp180[2][0];
			vertices[8].y = sp180[2][1];
			vertices[8].z = sp180[2][2];
			vertices[8].colour = 0;

			vertices[9] = vtxtemplate;
			vertices[9].x = sp180[3][0];
			vertices[9].y = sp180[3][1];
			vertices[9].z = sp180[3][2];
			vertices[9].colour = 0;

			vertices[8].s = st1;
			vertices[8].t = st4;
			vertices[9].s = st3;
			vertices[9].t = st4;

			vertices[10] = vtxtemplate;
			vertices[10].x = sp180[6][0];
			vertices[10].y = sp180[6][1];
			vertices[10].z = sp180[6][2];
			vertices[10].colour = 0;

			vertices[11] = vtxtemplate;
			vertices[11].x = sp180[7][0];
			vertices[11].y = sp180[7][1];
			vertices[11].z = sp180[7][2];
			vertices[11].colour = 0;

			vertices[10].s = st1;
			vertices[10].t = st2;
			vertices[11].s = st3;
			vertices[11].t = st2;

			gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 12);

			gDPTri4(gdl++, 0, 1, 9, 0, 9, 8, 11, 5, 4, 11, 4, 10);

			for (j = 2; j < 6; j++) {
				gDPTri2(gdl++,
						sp104[j][0], sp104[j][1], sp104[j][2],
						sp104[j][0], sp104[j][2], sp104[j][3]);
			}
		} else {
			if ((prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR)
					&& (prop->obj->flags3 & OBJFLAG3_SHOWSHIELD)) {
				alpha1 = 0xff;
				alpha2 = 0xff;
			} else if (g_Vars.lvframe60 - hit->lvframe60 <= TICKS(80)) {
				f32 value;

				value = (hit->lvframe60 - g_Vars.lvframe60 + TICKS(80)) * (PAL ? 3.8636362552643f : 3.1875f);
				value *= alpha * (1.0f / 255.0f);
				alpha1 = (s32) value;

				value = (hit->lvframe60 - g_Vars.lvframe60 + TICKS(80)) * (PAL ? 3.8636362552643f : 3.1875f);
				value *= alpha * (1.0f / 255.0f);
				alpha2 = (s32) value;
			} else {
				alpha1 = 0;
				alpha2 = 0;
			}

			colours = gfxAllocateColours(5);

			gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 5);

			colours[0].r = red1;
			colours[0].g = green1;
			colours[0].b = blue1;
			colours[0].a = alpha1;

			colours[1].r = red2;
			colours[1].g = green2;
			colours[1].b = blue2;
			colours[1].a = alpha1;

			colours[2].r = red2;
			colours[2].g = green2;
			colours[2].b = blue2;
			colours[2].a = alpha1;

			red1 += 100;

			if (red1 > 255) {
				red1 = 255;
			}

			colours[3].r = red1;

			green1 += 100;

			if (green1 > 255) {
				green1 = 255;
			}

			colours[3].g = green1;

			blue1 += 100;

			if (blue1 > 255) {
				blue1 = 255;
			}

			colours[3].b = blue1;

			colours[3].a = alpha2;

			red2 += 70;

			if (red2 > 255) {
				red2 = 255;
			}

			colours[4].r = red2;

			green2 += 70;

			if (green2 > 255) {
				green2 = 255;
			}

			colours[4].g = green2;

			blue2 += 70;

			if (blue2 > 255) {
				blue2 = 255;
			}

			colours[4].b = blue2;

			colours[4].a = alpha1;

			vertices = gfxAllocateVertices(30);

			for (j = 0; j < 4; j++) {
				vertices[j] = vtxtemplate;
				vertices[j].x = sp180[sp104[side][j]][0];
				vertices[j].y = sp180[sp104[side][j]][1];
				vertices[j].z = sp180[sp104[side][j]][2];
				vertices[j].colour = 0;
			}

			vertices[0].s = st1;
			vertices[0].t = st2;
			vertices[1].s = st3;
			vertices[1].t = st2;
			vertices[2].s = st3;
			vertices[2].t = st4;
			vertices[3].s = st1;
			vertices[3].t = st4;

			vertices[4] = vtxtemplate;

			if (hit->unk012 == 0x7fff) {
				vertices[4].x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) >> 2;
				vertices[4].y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) >> 2;
				vertices[4].z = (vertices[0].z + vertices[1].z + vertices[2].z + vertices[3].z) >> 2;
			} else {
				vertices[4].x = hit->unk012;
				vertices[4].y = hit->unk014;
				vertices[4].z = hit->unk016;
			}

			vertices[4].colour = 0xc;
			vertices[4].s = (st1 + st3) >> 1;
			vertices[4].t = (st2 + st4) >> 1;

			gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 5);

			gDPTri4(gdl++, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4);

			vertices += 5;

			for (j = 0; j < 4; j++) {
				s32 next = (j + 1) % 4;
				u32 stack;

				vertices[0] = vtxtemplate;
				vertices[0].x = sp180[sp104[side][next]][0];
				vertices[0].y = sp180[sp104[side][next]][1];
				vertices[0].z = sp180[sp104[side][next]][2];
				vertices[0].colour = 4;

				vertices[1] = vtxtemplate;
				vertices[1].x = sp180[sp104[side][j]][0];
				vertices[1].y = sp180[sp104[side][j]][1];
				vertices[1].z = sp180[sp104[side][j]][2];
				vertices[1].colour = 4;

				vertices[2] = vtxtemplate;
				vertices[2].x = sp180[sp104[side][j]][0];
				vertices[2].y = sp180[sp104[side][j]][1];
				vertices[2].z = sp180[sp104[side][j]][2];
				vertices[2].colour = 8;

				if (side == 0) {
					vertices[2].x = xmax;
				} else if (side == 1) {
					vertices[2].x = xmin;
				} else if (side == 2) {
					vertices[2].y = ymax;
				} else if (side == 3) {
					vertices[2].y = ymin;
				} else if (side == 4) {
					vertices[2].z = zmax;
				} else if (side == 5) {
					vertices[2].z = zmin;
				}

				vertices[3] = vtxtemplate;
				vertices[3].x = sp180[sp104[side][next]][0];
				vertices[3].y = sp180[sp104[side][next]][1];
				vertices[3].z = sp180[sp104[side][next]][2];
				vertices[3].colour = 8;

				if (side == 0) {
					vertices[3].x = xmax;
				} else if (side == 1) {
					vertices[3].x = xmin;
				} else if (side == 2) {
					vertices[3].y = ymax;
				} else if (side == 3) {
					vertices[3].y = ymin;
				} else if (side == 4) {
					vertices[3].z = zmax;
				} else if (side == 5) {
					vertices[3].z = zmin;
				}

				vertices[0].s = st1;
				vertices[0].t = st2;
				vertices[1].s = st3;
				vertices[1].t = st2;
				vertices[2].s = st3;
				vertices[2].t = st4;
				vertices[3].s = st1;
				vertices[3].t = st4;

				vertices[4] = vtxtemplate;
				vertices[4].x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) >> 2;
				vertices[4].y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) >> 2;
				vertices[4].z = (vertices[0].z + vertices[1].z + vertices[2].z + vertices[3].z) >> 2;
				vertices[4].colour = 0x10;
				vertices[4].s = (st1 + st3) >> 1;
				vertices[4].t = (st2 + st4) >> 1;

				gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 5);

				gDPTri4(gdl++, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4);

				vertices += 5;
			}

			for (j = 0; j < 4; j++) {
				vertices[j] = vtxtemplate;
				vertices[j].x = sp180[sp104[side][3 - j]][0];
				vertices[j].y = sp180[sp104[side][3 - j]][1];
				vertices[j].z = sp180[sp104[side][3 - j]][2];
				vertices[j].colour = 8;

				if (side == 0) {
					vertices[j].x = xmax;
				} else if (side == 1) {
					vertices[j].x = xmin;
				} else if (side == 2) {
					vertices[j].y = ymax;
				} else if (side == 3) {
					vertices[j].y = ymin;
				} else if (side == 4) {
					vertices[j].z = zmax;
				} else if (side == 5) {
					vertices[j].z = zmin;
				}
			}

			vertices[0].s = st1;
			vertices[0].t = st2;
			vertices[1].s = st3;
			vertices[1].t = st2;
			vertices[2].s = st3;
			vertices[2].t = st4;
			vertices[3].s = st1;
			vertices[3].t = st4;

			vertices[4] = vtxtemplate;

			vertices[4].x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) >> 2;
			vertices[4].y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) >> 2;
			vertices[4].z = (vertices[0].z + vertices[1].z + vertices[2].z + vertices[3].z) >> 2;
			vertices[4].colour = 0x10;
			vertices[4].s = (st1 + st3) >> 1;
			vertices[4].t = (st2 + st4) >> 1;

			gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 5);

			gDPTri4(gdl++, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4);
		}
	}

	return gdl;
}

/**
 * Render a shield hit.
 *
 * Chrs have shield bounding boxes around each bone. For chrs, a shield hit is
 * rendered around every bone.
 *
 * Objects can have a specific model part for the shield area (eg. hoverbed).
 * If not specified, every bbox node in the object will be used.
 */
Gfx *shieldhitRender(Gfx *gdl, struct prop *prop1, struct prop *prop2, s32 alpha,
		bool arg4, s32 cmnum1, s32 cmnum2, s32 cmnum3, s32 cmnum4)
{
	u32 stack[4];
	struct model *model;
	struct modelnode *specificnode = NULL;
	struct modelnode *node;

	if (prop2->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		// Find the model and specific node if any
		if (prop2->type == PROPTYPE_CHR || prop2->type == PROPTYPE_PLAYER) {
			struct chrdata *chr = prop2->chr;
			model = chr->model;
		} else {
			model = prop2->obj->model;
			specificnode = modelGetPart(model->filedata, MODELPART_BASIC_0067);
		}

		node = model->filedata->rootnode;

		while (node) {
			if ((node->type & 0xff) == MODELNODETYPE_BBOX) {
				if (specificnode == NULL || specificnode == node) {
					struct shieldhit *s0 = NULL;
					struct shieldhit *s1 = NULL;
					struct shieldhit *s2 = NULL;
					s32 index = chr0f028e18(prop2, node, model, prop1);
					s32 i;

					for (i = 0; i < 20; i++) {
						struct shieldhit *iter = &g_ShieldHits[i];

						if (iter->prop == prop1) {
							if (iter->model) {
								if (iter->node == node) {
									if (s0 == NULL || s0->lvframe60 < iter->lvframe60) {
										s0 = iter;
									}
								} else {
									if (index < 32
											&& iter->unk018[index] >= 0
											&& (s2 == NULL || s2->lvframe60 < iter->lvframe60)) {
										s2 = iter;
									}
								}
							} else {
								if (s1 == NULL || s1->lvframe60 < iter->lvframe60) {
									s1 = iter;
								}
							}
						}
					}

					if (s0) {
						gdl = chrRenderShieldComponent(gdl, s0, prop1, s0->model, s0->node, s0->side, -1, -1, 255);
					} else if (s1) {
						gdl = chrRenderShieldComponent(gdl, s1, prop1, model, node, -1, -1, -1, 255);
					} else if (s2) {
						gdl = chrRenderShieldComponent(gdl, s2, prop1, model, node, -2, s2->unk018[index], s2->unk038[index], 255);
					} else {
						if (arg4) {
							if (specificnode) {
								index = 19;
							}

							if (index > 19) {
								index = 0;
							}

							gDPPipeSync(gdl++);
							gDPSetTextureLUT(gdl++, G_TT_NONE);
							gDPLoadTextureBlock(gdl++, var8009ccc0[index], G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
							gDPSetCycleType(gdl++, G_CYC_1CYCLE);
							gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
							gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
							gSPTexture(gdl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
							gDPSetTextureFilter(gdl++, G_TF_BILERP);
							gDPSetColorDither(gdl++, G_CD_BAYER);

							gdl = chrRenderShieldComponent(gdl, NULL, prop1, model, node, -7, -1, -1, 255);
						} else {
							if (index == cmnum1) {
								gdl = chrRenderShieldComponent(gdl, NULL, prop1, model, node, -3, -1, -1, alpha);
							} else if (index == cmnum2) {
								gdl = chrRenderShieldComponent(gdl, NULL, prop1, model, node, -4, -1, -1, alpha);
							} else if (index == cmnum3) {
								gdl = chrRenderShieldComponent(gdl, NULL, prop1, model, node, -5, -1, -1, alpha);
							} else if (index == cmnum4) {
								gdl = chrRenderShieldComponent(gdl, NULL, prop1, model, node, -6, -1, -1, alpha);
							}
						}
					}
				}
			}

			if (node->child) {
				node = node->child;
			} else {
				while (node) {
					if (node->next) {
						node = node->next;
						break;
					}

					node = node->parent;
				}
			}
		}

		if (specificnode == NULL) {
			struct prop *child;

			for (child = prop2->child; child != NULL; child = child->next) {
				gdl = shieldhitRender(gdl, prop1, child, alpha, arg4, cmnum1, cmnum2, cmnum3, cmnum4);
			}
		}
	}

	return gdl;
}

/**
 * Render the cloak transition effect for a chr prop and any attached
 * child props such as held weapons or embedded knives.
 *
 * The function is initially called with both prop arguments being the chr prop.
 * The function iterates the child props and calls itself recursively, setting
 * thisprop to the current child being iterated.
 */
Gfx *chrRenderCloak(Gfx *gdl, struct prop *chrprop, struct prop *thisprop)
{
	struct model *model;
	struct modelnode *bbox = NULL;
	struct modelnode *node;

	if (thisprop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		if (thisprop->type == PROPTYPE_CHR || thisprop->type == PROPTYPE_PLAYER) {
			model = thisprop->chr->model;
		} else {
			model = thisprop->obj->model;
			bbox = modelGetPart(model->filedata, MODELPART_BASIC_0067);
		}

		if (thisprop->parent == NULL) {
			// Rendering the chr prop - configure renderer
			gDPPipeSync(gdl++);
			gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 16, 16);
			gDPSetCycleType(gdl++, G_CYC_COPY);
			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0080, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 160, 0x0080, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 15);
			gSPTexture(gdl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
			gDPSetEnvColor(gdl++, 0xff, 0xff, 0xff, 0xff);
			gDPSetPrimColor(gdl++, 0, 0, 0xff, 0xff, 0xff, 0xff);
			gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
			gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
			gDPSetTextureFilter(gdl++, G_TF_POINT);
			gDPSetTexturePersp(gdl++, G_TP_NONE);
			gDPSetColorDither(gdl++, G_CD_DISABLE);
			gDPSetAlphaDither(gdl++, G_AD_DISABLE);
			gDPSetTextureLOD(gdl++, G_TL_TILE);
			gDPSetTextureDetail(gdl++, G_TD_CLAMP);
			gDPSetTextureLUT(gdl++, G_TT_NONE);
			gDPSetAlphaCompare(gdl++, G_AC_NONE);
			gSPClearGeometryMode(gdl++, G_ZBUFFER);
		}

		// Iterate nodes in the prop and render each
		node = model->filedata->rootnode;

		while (node) {
			if ((node->type & 0xff) == MODELNODETYPE_BBOX) {
				if (bbox == NULL || node == bbox) {
					s32 index = chr0f028e18(thisprop, node, model, chrprop);

					if (bbox) {
						index = 19;
					}

					if (index <= 19) {
						Mtxf *mtx = model0001a5cc(model, model0001a740(node), 0);
						s32 uls; // upper left s coordinate
						s32 ult; // upper left t coordinate
						struct coord coord;
						f32 screenpos[2];
						s32 lrs; // lower right s coordinate
						s32 lrt; // lower right t coordinate

						coord.x = mtx->m[3][0];
						coord.y = mtx->m[3][1];
						coord.z = mtx->m[3][2];

						cam0f0b4d68(&coord, screenpos);

						if (screenpos[0] < 0.0f) {
							screenpos[0] = 0.0f;
						}

						if (screenpos[0] > viGetWidth()) {
							screenpos[0] = viGetWidth();
						}

						if (screenpos[1] < 0.0f) {
							screenpos[1] = 0.0f;
						}

						if (screenpos[1] > viGetHeight()) {
							screenpos[1] = viGetHeight();
						}

						uls = (s32)screenpos[0] - 8;
						ult = (s32)screenpos[1] - 8;

						if (uls < viGetViewLeft()) {
							uls = viGetViewLeft();
						}

						if (uls > viGetViewLeft() + viGetViewWidth() - 16) {
							uls = viGetViewLeft() + viGetViewWidth() - 16;
						}

						if (ult < viGetViewTop()) {
							ult = viGetViewTop();
						}

						if (ult > viGetViewTop() + viGetViewHeight() - 16) {
							ult = viGetViewTop() + viGetViewHeight() - 16;
						}

						lrs = uls + 15;
						lrt = ult + 15;

						gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, OS_K0_TO_PHYSICAL(var8009ccc0[index]));
						gDPTileSync(gdl++);

						gDPLoadTextureTile(gdl++, viGetBackBuffer(), G_IM_FMT_RGBA, G_IM_SIZ_16b,
								viGetWidth(), 0, uls, ult, lrs, lrt,
								0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
								4, 4, G_TX_NOLOD, G_TX_NOLOD);

						gDPPipeSync(gdl++);
						gSPTextureRectangle(gdl++, 0, 0, 60, 60, G_TX_RENDERTILE, 0, 0, 4096, 1024);
					}
				}
			}

			if (node->child) {
				node = node->child;
			} else {
				while (node) {
					if (node->next) {
						node = node->next;
						break;
					}

					node = node->parent;
				}
			}
		}

		// Render child props
		if (bbox == NULL) {
			struct prop *child;

			for (child = thisprop->child; child != NULL; child = child->next) {
				gdl = chrRenderCloak(gdl, chrprop, child);
			}
		}

		if (thisprop->parent == NULL) {
			// Back in the chr prop - reconfigure the renderer for normal use
			gDPPipeSync(gdl++);
			gDPLoadSync(gdl++);
			gDPTileSync(gdl++);
			gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viGetBufWidth(), OS_K0_TO_PHYSICAL(viGetBackBuffer()));
			gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetWidth(), viGetHeight());
			gDPSetCycleType(gdl++, G_CYC_1CYCLE);
			gDPSetRenderMode(gdl++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
			gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
			gDPSetTextureFilter(gdl++, G_TF_BILERP);
			gDPSetTexturePersp(gdl++, G_TP_PERSP);
			gSPSetGeometryMode(gdl++, G_ZBUFFER);
		}
	}

	return gdl;
}

Gfx *chrRenderShield(Gfx *gdl, struct chrdata *chr, u32 alpha)
{
	if (chrGetShield(chr) > 0 && g_Vars.lvupdate240 > 0) {
		chr->cmcount++;

		if (chr->cmcount > 300) {
			chr->cmcount = 0;
		}
	}

	if ((chr->hidden2 & CHRH2FLAG_SHIELDHIT)
			|| (chrGetShield(chr) > 0 && chr->cmcount < 10)
			|| (chr->cloakfadefrac > 0 && !chr->cloakfadefinished)) {
		if (chrGetShield(chr) > 0 && g_Vars.lvupdate240 > 0) {
			s32 numiterations = (random() % 4) + 1;
			s32 newcmnum = chr->cmnum2;
			s32 candidate;
			s8 operation = 0;
			s8 again = true;
			s32 i;

			for (i = 0; i <= numiterations; ) {
				if (operation == 0) {
					candidate = chr0f02932c(chr->prop, chr->cmnum);
					operation = 1;

					if (candidate >= 0) {
						if (candidate != chr->cmnum2) {
							newcmnum = candidate;
						}

						i++;
					} else {
						again = false;
					}
				} else if (operation == 1) {
					candidate = chr0f0293ec(chr->prop, chr->cmnum);

					if (candidate >= 0) {
						operation = 2;

						if (candidate != chr->cmnum2) {
							newcmnum = candidate;
						}

						i++;
					} else {
						if (again) {
							operation = 0;
						} else {
							break;
						}
					}
				} else if (operation == 2) {
					candidate = chr0f0294cc(chr->prop, candidate);

					if (candidate >= 0) {
						if (candidate != chr->cmnum2) {
							newcmnum = candidate;
						}

						i++;
					} else {
						operation = 0;
					}
				}
			}

			chr->cmnum4 = chr->cmnum3;
			chr->cmnum3 = chr->cmnum2;
			chr->cmnum2 = chr->cmnum;
			chr->cmnum = newcmnum;
		}

		gSPSetGeometryMode(gdl++, G_CULL_BACK);

		gdl = shieldhitRender(gdl, chr->prop, chr->prop, alpha,
				chr->cloakfadefrac > 0 && !chr->cloakfadefinished,
				chr->cmnum, chr->cmnum2, chr->cmnum3, chr->cmnum4);

		gSPSetGeometryMode(gdl++, G_CULL_BACK);
	}

	return gdl;
}

/**
 * This ticks the shield damage effect when you shoot a shielded chr.
 */
void shieldhitsTick(void)
{
	s32 index;
	bool changed = false;
	s32 time60;
	s32 i;
	s32 j;

	if (g_ShieldHitActive) {
		for (i = 0; i < 20; i++) {
			if (g_ShieldHits[i].prop) {
				if (g_ShieldHits[i].lvframe60 >= g_Vars.lvframe60 - TICKS(80)) {
					changed = true;
					g_ShieldHits[i].shield += (propGetShieldThing(&g_ShieldHits[i].prop) - g_ShieldHits[i].shield) * g_Vars.lvupdate60f * (PAL ? 0.0151515156f : 0.0125f);
				}

				for (j = 0; j < 32; j++) {
					if (g_ShieldHits[i].unk018[j] >= 0) {
						changed = true;
						time60 = g_ShieldHits[i].unk018[j] + g_Vars.lvupdate60;

						if (g_ShieldHits[i].unk018[j] < 1 && time60 > 0) {
							index = chr0f02932c(g_ShieldHits[i].prop, j);

							if (index >= 0 && index < 32) {
								if (g_ShieldHits[i].unk018[index] == -1) {
									g_ShieldHits[i].unk018[index] = -3;
									g_ShieldHits[i].unk038[index] = g_ShieldHits[i].unk038[j] + 1;
								}
							}

							index = chr0f0293ec(g_ShieldHits[i].prop, j);

							while (index >= 0) {
								if (index < 32) {
									if (g_ShieldHits[i].unk018[index] == -1) {
										g_ShieldHits[i].unk018[index] = -3;
										g_ShieldHits[i].unk038[index] = g_ShieldHits[i].unk038[j] + 1;
									}
								}

								index = chr0f0294cc(g_ShieldHits[i].prop, index);
							}
						}

						if (time60 < TICKS(30)) {
							g_ShieldHits[i].unk018[j] = time60;
						} else {
							g_ShieldHits[i].unk018[j] = -2;
						}
					}
				}

				for (j = 0; j < 32; j++) {
					if (g_ShieldHits[i].unk018[j] == -3) {
						g_ShieldHits[i].unk018[j] = 0;
					}
				}

				if (!changed) {
					shieldhitRemove(&g_ShieldHits[i]);
				}
			}
		}
	}
}

void chrSetDrCarollImages(struct chrdata *drcaroll, s32 imageleft, s32 imageright)
{
	if (drcaroll && imageleft >= 0 && imageleft < 6 && imageright >= 0 && imageright < 6) {
		struct model *model = drcaroll->model;
		struct modelnode *nodes[2];
		union modelrwdata *rwdata;
		s32 i;
		s32 j;
		u32 stack;

		// Iterate model parts relating to images
		// Parts 0-5 are the left image
		// Parts 6-11 are the right image
		for (i = 0; i < 6; i++) {
			nodes[0] = modelGetPart(model->filedata, i);
			nodes[1] = modelGetPart(model->filedata, i + 6);

			for (j = 0; j < 2; j++) {
				if (nodes[j]) {
					rwdata = modelGetNodeRwData(model, nodes[j]);

					if (j == 0) {
						rwdata->toggle.visible = (imageleft == i) ? true : false;
					} else {
						rwdata->toggle.visible = (imageright == i) ? true : false;
					}
				}
			}
		}
	}
}
