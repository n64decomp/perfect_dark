#include <ultra64.h>
#include "lib/sched.h"
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/chr.h"
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
#include "game/mtxf2lbulk.h"
#include "game/playermgr.h"
#include "game/rng2.h"
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

void rng2_set_seed(u32 seed);

void *var8009ccc0[20];
s32 g_NumChrs;
s16 *g_Chrnums;
s16 *g_ChrIndexes;
struct chrdata *g_CurModelChr;

struct onscreendoor *g_ChrsOnscreenDoors = NULL;
s32 g_ChrsNumOnscreenDoors = 0;
f32 g_ChrsAnimSpeed = 0;
bool g_ChrsAnimDebugSetAll = false;
s32 g_ChrsAnimDebugAnimNum = 0;
u32 g_ChrsAnimDebugPaused = 0x00000000;
u32 g_ChrsAnimDebugSlow = 0x00000000;
bool g_ChrsDebugPatrols = false;
bool g_ChrsDebugSomething = false;
s32 g_NextChrnum = 5000;

struct chrdata *g_ChrSlots = NULL;

s32 g_NumChrSlots = 0;

Gfx *chr_render_cloak(Gfx *gdl, struct prop *chrprop, struct prop *thisprop);
Gfx *chr_render_shield(Gfx *gdl, struct chrdata *chr, u32 alpha);
void chr_set_drcaroll_images(struct chrdata *drcaroll, s32 imageleft, s32 imageright);

s32 chrs_get_num_slots(void)
{
	return g_NumChrSlots;
}

void chr_set_chrnum(struct chrdata *chr, s16 chrnum)
{
	s32 i;
	bool modified;
	s16 tmp;

	// Set the new chrnum
	for (i = 0; i < g_NumChrs; i++) {
		if (g_Chrnums[i] == chr->chrnum) {
			g_Chrnums[i] = chrnum;
			break;
		}

	}

	chr->chrnum = chrnum;

	// Sort the g_Chrnums and g_ChrIndexes arrays
	do {
		modified = false;

		for (i = 0; i < g_NumChrs - 1; i++) {
			if (g_Chrnums[i] > g_Chrnums[i + 1]) {
				tmp = g_Chrnums[i];
				g_Chrnums[i] = g_Chrnums[i + 1];
				g_Chrnums[i + 1] = tmp;

				tmp = g_ChrIndexes[i];
				g_ChrIndexes[i] = g_ChrIndexes[i + 1];
				g_ChrIndexes[i + 1] = tmp;

				modified = true;
			}
		}
	} while (modified);
}

void chr_register(s32 chrnum, s32 chrindex)
{
	s32 i;
	s16 tmp;

	for (i = 0; i < g_NumChrs; i++) {
		if (g_Chrnums[i] > chrnum) {
			tmp = g_Chrnums[i];
			g_Chrnums[i] = chrnum;
			chrnum = tmp;

			tmp = g_ChrIndexes[i];
			g_ChrIndexes[i] = chrindex;
			chrindex = tmp;
		}
	}

	g_Chrnums[g_NumChrs] = chrnum;
	g_ChrIndexes[g_NumChrs] = chrindex;
	g_NumChrs++;
}

void chr_deregister(s32 chrnum)
{
	s32 i;

	for (i = 0; i < g_NumChrs; i++) {
		if (g_Chrnums[i] == chrnum) {
			s32 j = i + 1;

			while (j < g_NumChrs) {
				g_Chrnums[i] = g_Chrnums[j];
				g_ChrIndexes[i] = g_ChrIndexes[j];
				i++;
				j++;
			}

			g_NumChrs--;
			return;
		}
	}
}

Vtx *chr_allocate_vertices(s32 numvertices)
{
	return (Vtx *) gfx_allocate(numvertices * sizeof(Vtx));
}

void chrs_set_debug_patrols(bool enabled)
{
	g_ChrsDebugPatrols = enabled;
}

bool chrs_get_debug_patrols(void)
{
	return g_ChrsDebugPatrols;
}

void chrs_set_debug_something(bool enabled)
{
	g_ChrsDebugSomething = enabled;
}

bool chrs_get_debug_something(void)
{
	return g_ChrsDebugSomething;
}

void chr_set_perim_enabled(struct chrdata *chr, bool enable)
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
void chr_calculate_push_pos(struct chrdata *chr, struct coord *dstpos, RoomNum *dstrooms, bool arg3)
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
	RoomNum sp84[20];
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
		rooms_copy(prop->rooms, dstrooms);
		chr_set_perim_enabled(chr, true);
		return;
	}

	chr_get_bbox(prop, &radius, &ymax, &ymin);
	halfradius = radius * 0.5f;
	chr_set_perim_enabled(chr, false);

	// myspecial is the chr's chair
	if (chr->myspecial != -1) {
		chair = obj_find_by_tag_id(chr->myspecial);

		if (chair && chair->prop) {
			obj_set_perim_enabled(chair->prop, false);
		}
	}

	los_find_intersecting_rooms_exhaustive(&prop->pos, prop->rooms, dstpos, dstrooms, sp84, 20);

#if VERSION < VERSION_NTSC_1_0
	for (i = 0; dstrooms[i] != -1; i++) {
		if (dstrooms[i] == chr->floorroom) {
			dstrooms[0] = chr->floorroom;
			dstrooms[1] = -1;
			break;
		}
	}
#endif

	chr_find_entered_rooms_at_pos(chr, dstpos, dstrooms);

	movex = dstpos->x - prop->pos.x;
	movez = dstpos->z - prop->pos.z;

	if (movex > halfradius || movez > halfradius || movex < -halfradius || movez < -halfradius) {
		cdresult = cd_exam_cyl_move05(&prop->pos, prop->rooms, dstpos, dstrooms, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);

		if (cdresult == CDRESULT_NOCOLLISION) {
			cdresult = cd_exam_cyl_move01(&prop->pos, dstpos, radius, dstrooms, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
		}
	} else {
		cdresult = cd_exam_cyl_move01(&prop->pos, dstpos, radius, sp84, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
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
			cd_get_edge(&sp78, &sp6c, 453, "chr/chr.c");
#elif VERSION >= VERSION_PAL_BETA
			cd_get_edge(&sp78, &sp6c, 453, "chr.c");
#elif VERSION >= VERSION_NTSC_1_0
			cd_get_edge(&sp78, &sp6c, 453, "chr/chr.c");
#else
			cd_get_edge(&sp78, &sp6c, 451, "chr.c");
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

				los_find_intersecting_rooms_exhaustive(&prop->pos, prop->rooms, &sp44, dstrooms, sp84, 20);

#if VERSION < VERSION_NTSC_1_0
				for (j = 0; dstrooms[j] != -1; j++) {
					if (dstrooms[j] == chr->floorroom) {
						dstrooms[0] = chr->floorroom;
						dstrooms[1] = -1;
						break;
					}
				}
#endif

				chr_find_entered_rooms_at_pos(chr, &sp44, dstrooms);

				movex = sp44.x - prop->pos.x;
				movez = sp44.z - prop->pos.z;

				if (movex > halfradius || movez > halfradius || movex < -halfradius || movez < -halfradius) {
					cdresult = cd_test_cyl_move02(&prop->pos, prop->rooms, &sp44, dstrooms, CDTYPE_ALL, true, ymax - prop->pos.y, ymin - prop->pos.y);

					if (cdresult == CDRESULT_NOCOLLISION) {
						cdresult = cd_test_volume(&sp44, radius, dstrooms, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
					}
				} else {
					cdresult = cd_test_volume(&sp44, radius, sp84, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
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

						los_find_intersecting_rooms_exhaustive(&prop->pos, prop->rooms, &sp44, dstrooms, sp84, 20);

#if VERSION < VERSION_NTSC_1_0
						for (k = 0; dstrooms[k] != -1; k++) {
							if (dstrooms[k] == chr->floorroom) {
								dstrooms[0] = chr->floorroom;
								dstrooms[1] = -1;
								break;
							}
						}
#endif

						chr_find_entered_rooms_at_pos(chr, &sp44, dstrooms);

						movex = sp44.x - prop->pos.x;
						movez = sp44.z - prop->pos.z;

						if (movex > halfradius || movez > halfradius || movex < -halfradius || movez < -halfradius) {
							cdresult = cd_test_cyl_move02(&prop->pos, prop->rooms, &sp44, dstrooms, CDTYPE_ALL, true, ymax - prop->pos.y, ymin - prop->pos.y);

							if (cdresult == CDRESULT_NOCOLLISION) {
								cdresult = cd_test_volume(&sp44, radius, dstrooms, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
							}
						} else {
							cdresult = cd_test_volume(&sp44, radius, sp84, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
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

							los_find_intersecting_rooms_exhaustive(&prop->pos, prop->rooms, &sp44, dstrooms, sp84, 20);

#if VERSION < VERSION_NTSC_1_0
							for (l = 0; dstrooms[l] != -1; l++) {
								if (dstrooms[l] == chr->floorroom) {
									dstrooms[0] = chr->floorroom;
									dstrooms[1] = -1;
									break;
								}
							}
#endif

							chr_find_entered_rooms_at_pos(chr, &sp44, dstrooms);

							movex = sp44.x - prop->pos.x;
							movez = sp44.z - prop->pos.z;

							if (movex > halfradius || movez > halfradius || movex < -halfradius || movez < -halfradius) {
								cdresult = cd_test_cyl_move02(&prop->pos, prop->rooms, &sp44, dstrooms, CDTYPE_ALL, true, ymax - prop->pos.y, ymin - prop->pos.y);

								if (cdresult == CDRESULT_NOCOLLISION) {
									cdresult = cd_test_volume(&sp44, radius, dstrooms, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
								}
							} else {
								cdresult = cd_test_volume(&sp44, radius, sp84, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y);
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
		rooms_copy(prop->rooms, dstrooms);
		chr->invalidmove = 1;
	}

	chr_set_perim_enabled(chr, true);

	if (chair && chair->prop) {
		obj_set_perim_enabled(chair->prop, true);
	}
}

#if VERSION >= VERSION_NTSC_1_0
bool chr_ascend(struct chrdata *chr, struct coord *pos, RoomNum *rooms, f32 amount, bool writerooms)
#else
bool chr_ascend(struct chrdata *chr, struct coord *pos, RoomNum *rooms, f32 amount)
#endif
{
	bool result;
	struct coord newpos;
	RoomNum newrooms[8];
	f32 ymax;
	f32 ymin;
	f32 radius;

	newpos.x = pos->x;
	newpos.y = pos->y + amount;
	newpos.z = pos->z;

	chr_get_bbox(chr->prop, &radius, &ymax, &ymin);
	los_find_final_room_exhaustive(pos, rooms, &newpos, newrooms);
	chr_find_entered_rooms_at_pos(chr, &newpos, newrooms);
	chr_set_perim_enabled(chr, false);
	result = cd_test_volume(&newpos, radius, newrooms, CDTYPE_ALL, CHECKVERTICAL_YES,
			ymax - chr->prop->pos.y,
			ymin - chr->prop->pos.y);
	chr_set_perim_enabled(chr, true);

#if VERSION >= VERSION_NTSC_1_0
	if (result == true && writerooms) {
		pos->y = newpos.y;
		rooms_copy(newrooms, rooms);
	}
#endif

	return result == CDRESULT_NOCOLLISION;
}

bool chr_update_position(struct model *model, struct coord *arg1, struct coord *arg2, f32 *mangroundptr)
{
	struct chrdata *chr = model->chr;
	struct prop *prop = chr->prop;
	struct prop *lift;
	s32 i;
	f32 ground;
	RoomNum spfc[8];
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
	RoomNum spc0[8];
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

	if (g_Anims[model->anim->animnum].flags & ANIMFLAG_ABSOLUTETRANSLATION) {
		if (chr->hidden & CHRHFLAG_FINDROOMSFAST) {
			los_find_final_room_fast(&prop->pos, prop->rooms, arg2, spfc);
		} else {
			los_find_final_room_exhaustive(&prop->pos, prop->rooms, arg2, spfc);
		}

		ground = cd_find_ground_info_at_cyl(arg2, chr->radius, spfc, &chr->floorcol, &chr->floortype, &floorflags, &chr->floorroom, &inlift, &lift);

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
				if (chr->aibot->forceslowupdates != 0) {
					// forceslowupdates is set when the bot is being saved from
					// falling out of bounds due to high lag. It forces them to
					// update in smaller increments, which gives a higher chance
					// of their collision detection working correctly.
					if (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) {
						chr->aibot->forceslowupdates = 0;
					} else {
						chr->aibot->forceslowupdates--;

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

				bot_update_lateral(chr, move, lvupdate240, lvupdate60freal);
#else
				bot_update_lateral(chr, move);
#endif
			}

			arg2->x = arg1->x + move[0];
			arg2->z = arg1->z + move[1];
		}

		if (chr->actiontype == ACT_PATROL || chr->actiontype == ACT_GOPOS) {
			chr->onladder = cd_find_ladder(&chr->prop->pos, chr->radius * 2.5f,
					chr->manground + chr->height - chr->prop->pos.y,
					chr->manground + 1.0f - chr->prop->pos.y,
					chr->prop->rooms, GEOFLAG_LADDER, &chr->laddernormal);
		} else {
			chr->onladder = false;
		}

		if (chr->aibot != NULL) {
			chr->height = 185.0f;

			if (chr->actiontype == ACT_GOPOS && (chr->act_gopos.flags & GOPOSFLAG_DUCK)) {
				chr->height = 135.0f;
			} else if (chr->actiontype == ACT_GOPOS && (chr->act_gopos.flags & GOPOSFLAG_CROUCH)) {
				chr->height = 90.0f;
			} else if (cd_0002a13c(&chr->prop->pos, chr->radius * 1.1f,
						chr->manground + 185.0f - chr->prop->pos.y,
						chr->manground - 10.0f - chr->prop->pos.y,
						chr->prop->rooms, GEOFLAG_AIBOTDUCK)) {
				chr->height = 135.0f;
			} else if (cd_0002a13c(&chr->prop->pos, chr->radius * 1.1f,
						chr->manground + 135.0f - chr->prop->pos.y,
						chr->manground - 10.0f - chr->prop->pos.y,
						chr->prop->rooms, GEOFLAG_AIBOTCROUCH)) {
				chr->height = 90.0f;
			}

			bmove_dampen_shotspeed(&chr->aibot->shotspeed);

			arg2->x += chr->aibot->shotspeed.x * g_HeadAnims[HEADANIM_MOVING].translateperframe * VAR(lvupdate60freal) * 0.5f;
			arg2->z += chr->aibot->shotspeed.z * g_HeadAnims[HEADANIM_MOVING].translateperframe * VAR(lvupdate60freal) * 0.5f;
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
			struct eyespy *eyespy = chr_to_eyespy(chr);

			if (eyespy && eyespy->deployed) {
				arg2->x = chr->prop->pos.x;
				arg2->y = chr->prop->pos.y;
				arg2->z = chr->prop->pos.z;
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

			rooms_copy(prop->rooms, spfc);

			chr->invalidmove = 0;
			chr->lastmoveok60 = g_Vars.lvframe60;
		} else {
			if (chr->chrflags & CHRCFLAG_HAS_SPECIAL_DEATH_ANIMATION) {
				arg2->x = arg1->x;
				arg2->z = arg1->z;
			}

			chr_calculate_push_pos(chr, arg2, spfc, true);
		}

		if (chr->actiontype == ACT_SKJUMP
				&& chr->act_skjump.state == SKJUMPSTATE_AIRBORNE
				&& !chr->act_skjump.needsnewanim
				&& g_Vars.lvupdate60 != 0) {
#if VERSION >= VERSION_NTSC_1_0
			if (chr_ascend(chr, arg2, spfc, yincrement, true)) {
				chr->manground += yincrement;
			}
#else
			if (chr_ascend(chr, arg2, spfc, yincrement)) {
				chr->manground += yincrement;
				arg2->y += yincrement;
			}
#endif

			chr->sumground = chr->manground * (PAL ? 8.4175090789795f : 9.999998f);
			chr->ground = chr->manground;
			arg2->y -= chr->manground;
		} else {
			struct coord *sp98;
			RoomNum *sp94;
			struct coord sp88;
			RoomNum sp78[8];
			f32 ground;
			struct modelnode *node;
			u16 nodetype;
			f32 fallspeed;
			u8 die;

			if (chr->onladder) {
#if VERSION >= VERSION_NTSC_1_0
				if (chr_ascend(chr, arg2, spfc, yincrement, true)) {
					chr->manground += yincrement;
				}
#else
				if (chr_ascend(chr, arg2, spfc, yincrement)) {
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
					struct player *player = g_Vars.players[playermgr_get_player_num_by_prop(prop)];
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

						los_find_final_room_exhaustive(arg2, spfc, &sp88, sp78);
						chr_find_entered_rooms_at_pos(chr, &sp88, sp78);
					} else {
						sp98 = arg2;
						sp94 = spfc;
					}

					ground = cd_find_ground_info_at_cyl(sp98, chr->radius, sp94,
							&chr->floorcol, &chr->floortype, &floorflags, &chr->floorroom, &inlift, &lift);

#if VERSION >= VERSION_NTSC_1_0
					if (chr->aibot
							&& chr->aibot->forceslowupdates == 0
							&& ground < -100000
							&& g_Vars.lvupdate60 >= 5
							&& (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) == 0) {
						// The new position has no ground and is offscreen,
						// So they're about to fall out of the geometry.
						// Run the previous calculations but using their current
						// position instead. This holds them in place.
						chr->aibot->forceslowupdates = 10;

						arg2->x = prop->pos.x;
						arg2->y = prop->pos.y;
						arg2->z = prop->pos.z;

						rooms_copy(prop->rooms, spfc);

						lvupdate60freal = 0.0f;

						ground = cd_find_ground_info_at_cyl(arg2, chr->radius, spfc,
								&chr->floorcol, &chr->floortype, &floorflags, &chr->floorroom, &inlift, &lift);
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

				if (chr->chrflags & CHRCFLAG_FORCETOGROUND) {
					node = model->definition->rootnode;
					nodetype = (u8)node->type;

					arg2->y += yincrement + chr->ground - manground;

					chr->chrflags &= ~CHRCFLAG_FORCETOGROUND;
					chr->manground = chr->ground;
					chr->sumground = chr->ground * (PAL ? 8.4175090789795f : 9.999998f);

					manground = chr->manground;

					if (nodetype == MODELNODETYPE_CHRINFO) {
						union modelrwdata *rwdata = model_get_node_rw_data(model, node);
						rwdata->chrinfo.unk34.y = rwdata->chrinfo.unk24.y;
					}
				} else {
					if (chr->fallspeed.y != 0.0f || chr->ground < chr->manground) {
						die = false;

						if (prop->type == PROPTYPE_CHR && chr->manground <= -30000) {
							die = true;
						}

						fallspeed = chr->fallspeed.y;

						projectile_update_fall(&yincrement, &fallspeed, VAR(lvupdate60freal));

#if VERSION >= VERSION_NTSC_1_0
						if (chr_ascend(chr, arg2, spfc, yincrement, false))
#else
						if (chr_ascend(chr, arg2, spfc, yincrement))
#endif
						{
							chr->manground += yincrement;
							chr->fallspeed.y = fallspeed;
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
									shooter = mp_player_get_index(chr);
								}

								chr_die(chr, shooter);
							} else {
								chr->hidden |= CHRHFLAG_DELETING;
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
						spd0.x = arg2->x;
						spd0.y = arg2->y;
						spd0.z = arg2->z;

						rooms_copy(spfc, spc0);

						arg2->y += chr->manground - manground;

						los_find_final_room_exhaustive(&spd0, spc0, arg2, spfc);
						chr_find_entered_rooms_at_pos(chr, arg2, spfc);
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

	prop_deregister_rooms(prop);
	rooms_copy(spfc, prop->rooms);

#if VERSION >= VERSION_NTSC_1_0
	if (prop->type == PROPTYPE_CHR) {
		for (i = 0; prop->rooms[i] != -1; i++) {
			if (chr->floorroom == prop->rooms[i]) {
				prop_deregister_rooms(prop);
				prop->rooms[0] = chr->floorroom;
				prop->rooms[1] = -1;
				break;
			}
		}
	}
#endif

	chr_detect_rooms(chr);
	prop_calculate_shade_colour(prop, chr->nextcol, chr->floorcol);

	return true;
}

s32 chrs_get_num_free(void)
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

void chr_set_max_damage(struct chrdata *chr, f32 maxdamage)
{
	chr->maxdamage = maxdamage;
}

f32 chr_get_max_damage(struct chrdata *chr)
{
	return chr->maxdamage;
}

void chr_add_health(struct chrdata *chr, f32 health)
{
	chr->damage -= health;
}

f32 chr_get_armor(struct chrdata *chr)
{
	if (chr->damage < 0) {
		return -chr->damage;
	}

	return 0;
}

s16 chrs_get_next_unused_chrnum(void)
{
	s32 chrnum;
	struct chrdata *chr;

	do {
		chrnum = ++g_NextChrnum;

		if (chrnum > 32767) {
			chrnum = g_NextChrnum = 5000;
		}

		chr = chr_find_by_literal_id((s16)chrnum);
	} while (chr);

	return chrnum;
}

/**
 * Allocate a chr from the pool, set default values, register a chrnum
 * and assign it to the prop.
 */
void chr_allocate(struct prop *prop, u8 *ailist)
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
	chr->chrnum = chrs_get_next_unused_chrnum();
	chr_register(chr->chrnum, i);

	chr->headnum = 0;
	chr->bodynum = 0;
	chr->prop = prop;
	chr->model = NULL;
	chr->numarghs = 0;
	chr->lastwalk60 = 0;
	chr->invalidmove = 0;
	chr->lastmoveok60 = g_Vars.lvframe60;
	chr->visionrange = 250;

	if (cheat_is_active(CHEAT_PERFECTDARKNESS)) {
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

	chr->chrflags = CHRCFLAG_FORCETOGROUND;
	chr->hidden = 0;
	chr->hidden2 = 0;
	chr->actiontype = ACT_INIT;
	chr->sleep = 0;

	chr->ailist = ailist;
	chr->aioffset = 0;
	chr->aireturnlist = -1;
	chr->aishotlist = -1;
	chr->aipunchdodgelist = -1;
	chr->aishootingatmelist = -1;
	chr->aidarkroomlist = -1;
	chr->aiplayerdeadlist = -1;

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
	chr_set_shield(chr, 0);
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

	splat_reset_chr(chr);
}

/**
 * Place the chr in the stage at the given position.
 * Allocate a chr struct if the prop doesn't have one yet.
 */
struct prop *chr_place(struct prop *prop, struct model *model,
		struct coord *pos, RoomNum *rooms, f32 faceangle, u8 *ailist)
{
	struct chrdata *chr;
	struct coord testpos;
	f32 ground;
	u32 nodetype;

	prop->type = PROPTYPE_CHR;

	if (prop->chr == NULL) {
		chr_allocate(prop, ailist);
	}

	chr = prop->chr;

	model_set_anim70(model, chr_update_position);
	model->chr = chr;
	model->unk01 = 1;
	chr->model = model;
	chr_set_look_angle(chr, faceangle);
	model_set_anim_play_speed(model, PALUPF(g_ChrsAnimSpeed), 0);

	testpos.x = pos->x;
	testpos.y = pos->y + 100;
	testpos.z = pos->z;

	chr->ground = chr->manground = ground = cd_find_ground_info_at_cyl(&testpos, chr->radius, rooms, &chr->floorcol, &chr->floortype, NULL, &chr->floorroom, NULL, NULL);

	chr->sumground = ground * (PAL ? 8.4175090789795f : 9.999998f);

	prop->pos.x = testpos.x;
	prop->pos.y = ground + 100;
	prop->pos.z = testpos.z;

	prop_deregister_rooms(prop);
	rooms_copy(rooms, prop->rooms);
	chr_detect_rooms(chr);
	model_set_root_position(model, &prop->pos);

	nodetype = chr->model->definition->rootnode->type;

	if ((nodetype & 0xff) == MODELNODETYPE_CHRINFO) {
		union modelrwdata *rwdata = model_get_node_rw_data(chr->model, chr->model->definition->rootnode);
		rwdata->chrinfo.ground = ground;
	}

	chr->prevpos.x = prop->pos.x;
	chr->prevpos.y = prop->pos.y;
	chr->prevpos.z = prop->pos.z;

	prop_calculate_shade_colour(prop, chr->nextcol, chr->floorcol);

	return prop;
}

struct prop *chr_create_with_model(struct model *model, struct coord *pos, RoomNum *rooms, f32 faceangle, u8 *ailist)
{
	struct prop *prop = prop_allocate();

	if (prop) {
		prop = chr_place(prop, model, pos, rooms, faceangle, ailist);

		if (cheat_is_active(CHEAT_ENEMYSHIELDS)) {
			chr_set_shield(prop->chr, 8);
		}
	}

	return prop;
}

/**
 * Removes a chr. If free is true, free the chr.
 */
void chr_remove(struct prop *prop, bool free)
{
	struct chrdata *chr = prop->chr;
	struct model *model = chr->model;
	struct defaultobj *eyespyobj = NULL;
	struct prop *child;
	u32 stack[2];

	bgun_free_fireslot_wrapper(chr->fireslots[0]);
	bgun_free_fireslot_wrapper(chr->fireslots[1]);

	if (chr->proppreset1 >= 0) {
		struct prop *proppreset = &g_Vars.props[chr->proppreset1];
		struct defaultobj *chair = proppreset->obj;
		chair->hidden &= ~OBJHFLAG_OCCUPIEDCHAIR;
	}

	wallhit_fade_splats_for_removed_chr(prop);
	ps_stop_sound(prop, PSTYPE_GENERAL, 0xffff);
	shieldhits_remove_by_prop(prop);
	model_free_vertices(VTXSTORETYPE_CHRVTX, model);
	prop_deregister_rooms(prop);

	if (g_Vars.stagenum == STAGE_CITRAINING) {
		eyespyobj = obj_find_by_tag_id(0x26);
	}

	child = prop->child;

	while (child) {
		struct defaultobj *obj = child->obj;
		struct prop *next = child->next;

		if ((obj->hidden & OBJHFLAG_HASTEXTOVERRIDE) == 0
				&& obj != eyespyobj
				&& (prop->type != PROPTYPE_PLAYER || (obj->flags3 & OBJFLAG3_PLAYERUNDROPPABLE) == 0)) {
			obj_detach(child);
			obj_free_permanently(obj, true);
		}

		child = next;
	}

	modelmgr_free_model(model);
	chr->model = NULL;

	if (free) {
		chr_deregister(chr->chrnum);

		if (chr->cover != -1) {
			cover_set_in_use(chr->cover, false);
			chr->cover = -1;
		}

		chr_clear_references(prop - g_Vars.props);
		projectiles_unref_owner(prop);

		if (g_Vars.normmplayerisrunning == false && g_MissionConfig.iscoop) {
			s32 i;

			for (i = 0; i < g_Vars.numaibuddies && i < ARRAYCOUNT(g_Vars.aibuddies); i++) {
				if (g_Vars.aibuddies[i] == prop) {
					g_Vars.aibuddies[i] = NULL;
				}
			}
		}

		chr->chrnum = -1;

		rebuild_teams();
		rebuild_squadrons();
	}
}

void chr_clear_references(s32 propnum)
{
	s32 i;
	s32 j;
	struct prop *prop = &g_Vars.props[propnum];

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].target == propnum) {
			if (prop_get_index_by_chr_id(&g_ChrSlots[i], g_ChrSlots[i].chrpreset1) == propnum) {
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

/**
 * For the fast animation cheat from GE.
 *
 * The cheat doesn't exist in PD, but the functions are still here.
 * These functions are not called.
 */
void chrs_set_anim_speed(f32 speed)
{
	s32 i;

	g_ChrsAnimSpeed = speed;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].model) {
			model_set_anim_play_speed(g_ChrSlots[i].model, PALUPF(g_ChrsAnimSpeed), 600);
		}
	}
}

f32 chrs_get_anim_speed(void)
{
	return g_ChrsAnimSpeed;
}

void chr_update_aim_properties(struct chrdata *chr)
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

void chr_flinch_body(struct chrdata *chr)
{
	if (chr->actiontype != ACT_DEAD && chr->flinchcnt < 0) {
		chr->flinchcnt = 1;
		chr->hidden2 &= 0x0fff;
		chr->hidden2 |= (u16)(random() << 13);
	}
}

void chr_flinch_head(struct chrdata *chr, f32 arg1)
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

f32 chr_get_flinch_amount(struct chrdata *chr)
{
	f32 value = chr->flinchcnt;

	if (chr->hidden2 & CHRH2FLAG_HEADSHOTTED) {
		if (value < 4) {
			value = sinf(value * RAD(90, 1.5705462694168f) / 4);
		} else {
			value = 1 - sinf((value - 4) * (PAL ? RAD(4, 0.07478791475296f) : RAD(3, 0.060405626893044f)));
		}
	} else {
		if (value < TICKS(10)) {
			value = sinf(value * RAD(90, 1.5705462694168f) / TICKS(10));
		} else {
			value = 1 - sinf((value - TICKS(10)) * (PAL ? RAD(6, 0.098159141838551f) : RAD(4, 0.078527316451073f)));
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
void chr_handle_joint_positioned(s32 joint, Mtxf *mtx)
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

	if (g_CurModelChr->model->definition->skel == &g_SkelRobot) {
		// Handle Chicago robot guns
		theta = chr_get_inverse_theta(g_CurModelChr);

		if (joint == 1) {
			gunrotx = g_CurModelChr->gunrotx[0];
			gunroty = g_CurModelChr->gunroty[0];
		} else if (joint == 2) {
			gunrotx = g_CurModelChr->gunrotx[1];
			gunroty = g_CurModelChr->gunroty[1];
		} else {
			return;
		}

		mtx00015be0(cam_get_projection_mtxf(), mtx);

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

		gunrot = M_BADTAU - theta + RAD(90, 1.5707963705063f);

		if (gunrot >= M_BADTAU) {
			gunrot -= M_BADTAU;
		}

		mtx4_load_y_rotation(gunrot, &spb8);
		mtx00015be0(&spb8, mtx);
		mtx4_load_x_rotation(gunrotx, &spf8);
		mtx00015be0(&spf8, mtx);

		gunrot = gunroty + theta;

		if (gunrot >= M_BADTAU) {
			gunrot -= M_BADTAU;
		}

		mtx4_load_y_rotation(gunrot, &spb8);
		mtx00015be0(&spb8, mtx);

		if (scale != 1.0f) {
			mtx00015f04(scale, mtx);
		}

		mtx->m[3][0] = sp138.x;
		mtx->m[3][1] = sp138.y;
		mtx->m[3][2] = sp138.z;

		mtx00015be0(cam_get_world_to_screen_mtxf(), mtx);
	} else {
		if (g_CurModelChr->model->definition->skel == &g_SkelChr) {
			lshoulderjoint = 2;
			rshoulderjoint = 3;
			waistjoint = 1;
			neckjoint = 0;
		} else if (g_CurModelChr->model->definition->skel == &g_SkelSkedar) {
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

		if (cheat_is_active(CHEAT_DKMODE) && CHRRACE(g_CurModelChr) == RACE_HUMAN) {
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

				if (g_CurModelChr->hidden2 & CHRH2FLAG_AUTOANIM) {
					if (xrot > RAD(60, 1.0470308065414f)) {
						xrot -= RAD(60, 1.0470308065414f);
					} else if (xrot < RAD(-50, -0.87252569198608f)) {
						xrot += RAD(50, 0.87252569198608f);
					} else {
						xrot = 0.0f;
					}
				}

				// Left/right at the waist
				yrot = g_CurModelChr->aimsideback;

				if (g_CurModelChr->aibot) {
					yrot += g_CurModelChr->aibot->angleoffset;
				} else if (g_CurModelChr->prop->type == PROPTYPE_PLAYER) {
					yrot += g_Vars.players[playermgr_get_player_num_by_prop(g_CurModelChr->prop)]->angleoffset;
				}
			} else if (joint == neckjoint) {
				// Head up/down
				if (g_CurModelChr->hidden2 & CHRH2FLAG_AUTOANIM) {
					xrot = g_CurModelChr->aimupback;

					if (xrot > RAD(60, 1.0470308065414f)) {
						xrot = RAD(60, 1.0470308065414f);
					} else if (xrot < RAD(-50, -0.87252569198608f)) {
						xrot = RAD(-50, -0.87252569198608f);
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
						f32 flinchamount = chr_get_flinch_amount(g_CurModelChr);
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
					f32 flinchamount = chr_get_flinch_amount(g_CurModelChr) * RAD(15, 0.26175770163536f);

					xrot -= flinchamount;

					if (flinchtype < 3) {
						yrot -= flinchamount;
					} else if (flinchtype >= 3 && flinchtype < 6) {
						yrot += flinchamount;
					}
				} else if (joint == waistjoint) {
					f32 flinchamount;
					s32 flinchtype;

					flinchamount = chr_get_flinch_amount(g_CurModelChr);
					flinchtype = (g_CurModelChr->hidden2 >> 13) & 7;

					xrot += flinchamount * RAD(15, 0.26175770163536f);

					if (flinchtype < 3) {
						yrot += flinchamount * RAD(15, 0.26175770163536f);
					} else if (flinchtype >= 3 && flinchtype < 6) {
						yrot -= flinchamount * RAD(15, 0.26175770163536f);
					}

					if (flinchtype == 2 || flinchtype == 5 || flinchtype == 7) {
						zrot += flinchamount * RAD(10, 0.17450514435768f);
					} else if (flinchtype == 1 || flinchtype == 4 || flinchtype == 6) {
						zrot -= flinchamount * RAD(10, 0.17450514435768f);
					}
				}
			}

			if (xrot != 0.0f || yrot != 0.0f || zrot != 0.0f || scale != 1.0f) {
				struct coord sp70;
				f32 aimangle;
				Mtxf tmpmtx;

				aimangle = chr_get_aim_angle(g_CurModelChr);

				if (xrot < 0.0f) {
					xrot = -xrot;
				} else {
					xrot = M_BADTAU - xrot;
				}

				if (yrot < 0.0f) {
					yrot += M_BADTAU;
				}

				mtx00015be0(cam_get_projection_mtxf(), mtx);

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

					mtx4_load_y_rotation(yrot, &tmpmtx);
					mtx00015be0(&tmpmtx, mtx);

					if (xrot != 0.0f) {
						mtx4_load_x_rotation(xrot, &tmpmtx);
						mtx00015be0(&tmpmtx, mtx);
					}

					if (zrot != 0.0f) {
						mtx4_load_z_rotation(zrot, &tmpmtx);
						mtx00015be0(&tmpmtx, mtx);
					}

					mtx4_load_y_rotation(aimangle, &tmpmtx);
					mtx00015be0(&tmpmtx, mtx);
				} else {
					mtx4_load_y_rotation(yrot, &tmpmtx);
					mtx00015be0(&tmpmtx, mtx);
				}

				if (scale != 1.0f) {
					mtx00015f04(scale, mtx);
				}

				mtx->m[3][0] = sp70.x;
				mtx->m[3][1] = sp70.y;
				mtx->m[3][2] = sp70.z;

				mtx00015be0(cam_get_world_to_screen_mtxf(), mtx);
			}
		}
	}
}

void chr_find_entered_rooms_at_pos(struct chrdata *chr, struct coord *pos, RoomNum *rooms)
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
		struct eyespy *eyespy = chr_to_eyespy(chr);

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

	bg_find_entered_rooms(&lower, &upper, rooms, 7, true);
}

void chr_find_entered_rooms(struct chrdata *chr, RoomNum *room)
{
	chr_find_entered_rooms_at_pos(chr, &chr->prop->pos, room);
}

void chr_detect_rooms(struct chrdata *chr)
{
	prop_deregister_rooms(chr->prop);
	chr_find_entered_rooms(chr, chr->prop->rooms);
	prop_register_rooms(chr->prop);
}

void chr_update_anim(struct chrdata *chr, s32 lvupdate240, bool arg2)
{
	struct model *model = chr->model;

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			chr->hidden &= ~CHRHFLAG_00000800;
		}

		if (model->anim
				&& (g_Anims[model->anim->animnum].flags & ANIMFLAG_ABSOLUTETRANSLATION)
				&& lvupdate240 > 0
				&& g_Vars.cutsceneskip60ths > 0) {
			lvupdate240 += g_Vars.cutsceneskip60ths * 4;
		}
	}

	if (chr->chrflags & CHRCFLAG_DELAYANIM) {
		chr->chrflags &= ~CHRCFLAG_DELAYANIM;
	} else if (arg2) {
		if ((chr->hidden & CHRHFLAG_00000800) == 0) {
			model_get_root_position(model, &chr->prevpos);
			model_tick_anim_quarter_speed(model, lvupdate240, true);
			model_update_info(model);
		}
	} else {
		model_tick_anim_quarter_speed(model, lvupdate240, false);
	}
}

void chr_tick_child(struct chrdata *chr, struct prop *prop, bool fulltick)
{
	struct defaultobj *obj = prop->obj;
	struct model *model = obj->model;
	struct prop *child;
	struct prop *next;

	if (obj->hidden & OBJHFLAG_DELETING) {
		obj_free(obj, true, obj->hidden2 & OBJH2FLAG_CANREGEN);
		return;
	}

	if (model->attachedtomodel && model->attachedtonode
			&& (obj->hidden & OBJHFLAG_GONE) == 0
			&& (obj->flags2 & OBJFLAG2_INVISIBLE) == 0) {
		Mtxf *sp104 = model_find_node_mtx(model->attachedtomodel, model->attachedtonode, 0);
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
			mtx4_load_y_rotation(RAD(76, 1.3192588090897f), &sp80);
			mtx4_load_z_rotation(RAD(90, 1.5705462694168f), &sp40);
			mtx4_mult_mtx4_in_place(&sp40, &sp80);
			mtx4_mult_mtx4_in_place(sp104, &sp80);
			thing.unk00 = &sp80;
		} else if (prop == chr->weapons_held[HAND_LEFT]) {
			// Flip the model
			mtx4_load_z_rotation(M_BADPI, &sp80);
			mtx4_mult_mtx4_in_place(sp104, &sp80);
			thing.unk00 = &sp80;
		} else {
			thing.unk00 = sp104;
		}

		thing.unk10 = gfx_allocate(model->definition->nummatrices * sizeof(Mtxf));
		model_set_matrices(&thing, model);

		func0f07063c(prop, fulltick);

		child = prop->child;

		while (child) {
			if (prop);
			if (prop);

			next = child->next;
			chr_tick_child(chr, child, fulltick);
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

void chr_cloak(struct chrdata *chr, bool value)
{
	if (!chr_is_dead(chr)) {
		chr->hidden |= CHRHFLAG_CLOAKED;

		if (value) {
			ps_create(0, chr->prop, SFX_CLOAK_ON, -1, -1, 0, 0, PSTYPE_NONE, 0, -1, 0, -1, -1, -1, -1);
		}
	}
}

void chr_uncloak(struct chrdata *chr, bool value)
{
	if (chr->hidden & CHRHFLAG_CLOAKED) {
		chr->hidden &= ~CHRHFLAG_CLOAKED;

		if (value) {
			ps_create(0, chr->prop, SFX_CLOAK_OFF, -1, -1, 0, 0, PSTYPE_NONE, 0, -1, 0, -1, -1, -1, -1);
		}

#if PIRACYCHECKS
		{
			u32 checksum = 0;
			u32 *i = (u32 *)&bot_pickup_prop;
			u32 *end = (u32 *)&bot_test_prop_for_pickup;

			while (i < end) {
				checksum += ~*i;
				i++;
			}

			if (checksum != CHECKSUM_PLACEHOLDER) {
				((u32 *)&cd_return_zero)[-2] = 0;
			}
		}
#endif
	}
}

void chr_uncloak_temporarily(struct chrdata *chr)
{
	chr_uncloak(chr, true);
	chr->cloakpause = TICKS(120);
}

void chr_update_cloak(struct chrdata *chr)
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

			if (qty > 0 && !chr_is_dead(chr)) {
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
					&& !chr_is_dead(chr)
					&& botact_get_ammo_quantity_by_weapon(chr->aibot, WEAPON_RCP120, 0, 1) > 0) {
				if (chr->hidden & CHRHFLAG_CLOAKED) {
					chr->aibot->rcpcloaktimer60 += LVUPDATE60FREAL() * 0.4f;

					if (chr->aibot->rcpcloaktimer60 >= 1) {
						qty = chr->aibot->rcpcloaktimer60;
						chr->aibot->rcpcloaktimer60 -= qty;

						if (chr->aibot->loadedammo[0] > 0) {
							chr->aibot->loadedammo[0] -= qty;

							if (chr->aibot->loadedammo[0] <= 0) {
								chr->aibot->loadedammo[0] = 0;
							}
						} else {
							ammotype = botact_get_ammo_type_by_function(WEAPON_RCP120, 0);

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
					chr_cloak(chr, true);
				}
			}
		} else if (chr->hidden & CHRHFLAG_CLOAKED) {
			chr_uncloak(chr, true);
		}
	} else if (chr->prop->type == PROPTYPE_PLAYER) {
		prevplayernum = g_Vars.currentplayernum;
		set_current_player_num(playermgr_get_player_num_by_prop(chr->prop));

		if (g_Vars.currentplayer->devicesactive & DEVICE_CLOAKDEVICE) {
			// Cloak is active - but may or may not be in effect due to recent shooting
			s32 qty = bgun_get_reserved_ammo_count(AMMOTYPE_CLOAK);

			if (qty > 0) {
				if (chr->hidden & CHRHFLAG_CLOAKED) {
					// Cloak is effective
					qty -= g_Vars.lvupdate60;

					if (qty < 1) {
						qty = 0;
					}

					bgun_set_ammo_quantity(AMMOTYPE_CLOAK, qty);
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
				chr_cloak(chr, true);
			}
		} else {
			if ((g_Vars.currentplayer->devicesactive & DEVICE_CLOAKDEVICE) == false
					&& (chr->hidden & CHRHFLAG_CLOAKED)) {
				chr_uncloak(chr, true);
			}
		}

		set_current_player_num(prevplayernum);
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

s32 chr_get_cloak_alpha(struct chrdata *chr)
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

void chr_set_poisoned(struct chrdata *chr, struct prop *poisonprop)
{
	if (chr->actiontype != ACT_DEAD
			&& chr->actiontype != ACT_DIE
			&& chr->prop->type == PROPTYPE_PLAYER) {
		// This was probably used in a debug print
		playermgr_get_player_num_by_prop(chr->prop);
	}

	if (g_Vars.normmplayerisrunning) {
		chr->poisonprop = poisonprop;
		chr->poisoncounter += TICKS(3360);
	} else if (chr->poisoncounter == 0) {
		chr->poisoncounter = TICKS(1680);
		chr->poisonprop = poisonprop;
	}
}

void chr_tick_poisoned(struct chrdata *chr)
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
				&& g_Vars.players[playermgr_get_player_num_by_prop(chr->prop)]->bondhealth < 0.001f) {
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
					chr_damage_by_dizziness(chr, 100, &coord, &gset, chr->poisonprop);
					chr_flinch_head(chr, M_PI);
				}

				chr->poisoncounter = 0;
			} else if (chr->poisoncounter < TICKS(1680)) {
				chr->blurdrugamount += g_Vars.lvupdate240 * 10;
			}

			if (g_Vars.normmplayerisrunning) {
				if (chr->poisoncounter / TICKS(720) != (chr->poisoncounter + g_Vars.lvupdate240) / TICKS(720)) {
					chr_damage_by_dizziness(chr, 1.3f, &coord, &gset, chr->poisonprop);
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

bool chr_tick_beams(struct prop *prop)
{
	struct chrdata *chr = prop->chr;

	if (chr->fireslots[0] >= 0) {
		beam_tick(&g_Fireslots[chr->fireslots[0]].beam);
	}

	if (chr->fireslots[1] >= 0) {
		beam_tick(&g_Fireslots[chr->fireslots[1]].beam);
	}

	if (chr->aibot && chr->aibot->fadeintimer60 > 0) {
		if (chr->aibot->fadeintimer60 > g_Vars.lvupdate60) {
			chr->aibot->fadeintimer60 -= g_Vars.lvupdate60;
		} else {
			chr->aibot->fadeintimer60 = 0;
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
s32 chr_tick(struct prop *prop)
{
	struct modelrenderdata sp210 = {0, 1, 3};
	struct chrdata *chr = prop->chr;
	struct model *model = chr->model;
	bool needsupdate;
	bool hatvisible = true;
	s32 lvupdate240 = g_Vars.lvupdate240;
	struct prop *child;
	struct prop *next;
	bool fulltick = false;
	s32 race = CHRRACE(chr);
	s32 sp1e8;
	Mtxf sp1a8;
	s32 sp1a4;
	bool isrepeatframe;
	bool isrepeatframe2;
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

		chr_update_cloak(chr);
		chr_tick_poisoned(chr);

		if ((chr->chrflags & CHRCFLAG_HIDDEN) == 0 || (chr->chrflags & CHRCFLAG_NEVERSLEEP)) {
			if (g_ChrsAnimDebugSetAll) {
				if (anim_has_frames(g_ChrsAnimDebugAnimNum)) {
					if (model_get_anim_num(model) != g_ChrsAnimDebugAnimNum || !anim_has_frames(model_get_anim_num(model))) {
						model_set_animation(model, g_ChrsAnimDebugAnimNum, 0, 0.0f, 0.5f, 0.0f);
					}
				}
			} else {
				chra_tick(chr);

				if (chr->model == NULL) {
					return TICKOP_FREE;
				}
			}

			if (g_ChrsAnimDebugPaused) {
				lvupdate240 = 0;

				if (g_ChrsAnimDebugSlow) {
					lvupdate240 = 1;
				}
			}
		}

		if (chr->hidden & CHRHFLAG_DELETING) {
			if (chr->hidden & CHRHFLAG_DROPPINGITEM) {
				obj_drop_recursively(prop, true);
			}

			chr_remove(prop, true);
			return TICKOP_FREE;
		}
	}

	if (race == RACE_EYESPY) {
		struct eyespy *eyespy = chr_to_eyespy(chr);

		if (eyespy && eyespy->deployed) {
			if (eyespy == g_Vars.currentplayer->eyespy && eyespy->active) {
				needsupdate = false;
			} else {
				needsupdate = func0f08e8ac(prop, &prop->pos, model_get_effective_scale(model), true);
			}

			if (fulltick) {
				chr_update_anim(chr, lvupdate240, true);
			}
		} else {
			needsupdate = false;
		}
	} else if (chr->chrflags & CHRCFLAG_HIDDEN) {
		needsupdate = false;
	} else if ((chr->chrflags & CHRCFLAG_UNPLAYABLE)
			|| (prop->type == PROPTYPE_PLAYER
				&& g_Vars.currentplayer == (player = g_Vars.players[playermgr_get_player_num_by_prop(prop)])
				&& player->cameramode == CAMERAMODE_THIRDPERSON
				&& player->visionmode != VISIONMODE_SLAYERROCKET)) {
		// Cutscene chr?
		isrepeatframe = false;

		if (fulltick) {
			model->anim->average = false;

			if (chr->actiontype == ACT_ANIM && !chr->act_anim.movewheninvis && chr->act_anim.lockpos) {
				chr_update_anim(chr, lvupdate240, false);
			} else {
				chr_update_anim(chr, lvupdate240, true);
			}
		}

		if (chr->model && chr->model->anim && (g_Anims[chr->model->anim->animnum].flags & ANIMFLAG_HASREPEATFRAMES)) {
			anim_load_header(chr->model->anim->animnum);

			isrepeatframe = anim_get_remapped_frame(chr->model->anim->animnum, chr->model->anim->framea) < 0
				|| (anim_get_remapped_frame(chr->model->anim->animnum, chr->model->anim->frameb) < 0
						&& chr->model->anim->frac != 0.0f);
		}

		if (isrepeatframe) {
			needsupdate = false;
		} else {
			needsupdate = pos_is_in_draw_distance(&prop->pos);
		}
	} else if (chr->actiontype == ACT_PATROL || chr->actiontype == ACT_GOPOS) {
		if ((chr->actiontype == ACT_PATROL && chr->act_patrol.waydata.mode == WAYMODE_MAGIC)
				|| (chr->actiontype == ACT_GOPOS && chr->act_gopos.waydata.mode == WAYMODE_MAGIC)) {
			needsupdate = func0f08e8ac(prop, &prop->pos, model_get_effective_scale(model), true);

			if (needsupdate) {
				model->anim->average = false;
				model_get_root_position(model, &chr->prevpos);
				model_update_info(model);
			}
		} else {
			if (fulltick) {
				chr_update_anim(chr, lvupdate240, true);
			}

			needsupdate = func0f08e8ac(prop, &prop->pos, model_get_effective_scale(model), true);

			if (needsupdate) {
				if (chr->actiontype == ACT_PATROL) {
					chr->act_patrol.waydata.lastvisible60 = g_Vars.lvframe60;
				} else if (chr->actiontype == ACT_GOPOS) {
					chr->act_gopos.waydata.lastvisible60 = g_Vars.lvframe60;
				}
			}

			model->anim->average = !needsupdate
				&& !((prop->flags & (PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) != 0);
		}
	} else if (chr->actiontype == ACT_ANIM && !chr->act_anim.movewheninvis) {
		needsupdate = func0f08e8ac(prop, &prop->pos, model_get_effective_scale(model), true);

		if (fulltick) {
			model->anim->average = false;

			if (needsupdate && !chr->act_anim.lockpos) {
				chr_update_anim(chr, lvupdate240, true);
			} else {
				chr_update_anim(chr, lvupdate240, false);
			}
		}
	} else if (chr->actiontype == ACT_STAND) {
		model->anim->average = false;

		if (chr->chrflags & CHRCFLAG_FORCETOGROUND) {
			chr_update_anim(chr, lvupdate240, true);
			needsupdate = func0f08e8ac(prop, &prop->pos, model_get_effective_scale(model), true);
		} else {
			needsupdate = func0f08e8ac(prop, &prop->pos, model_get_effective_scale(model), true);

			if (g_Vars.mplayerisrunning) {
				if (fulltick) {
					if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
						if (needsupdate) {
							chr_update_anim(chr, lvupdate240, true);
						} else if (model->anim->animnum2 != 0) {
							chr_update_anim(chr, lvupdate240, false);
						}
					} else {
						chr_update_anim(chr, lvupdate240, true);
					}
				}
			} else if (needsupdate) {
				if (chr->act_stand.playwalkanim == true) {
					chr_update_anim(chr, lvupdate240, false);
				} else {
					chr_update_anim(chr, lvupdate240, true);
				}
			} else if (model->anim->animnum2 != 0) {
				chr_update_anim(chr, lvupdate240, false);
			}
		}
	} else if (chr->actiontype == ACT_DEAD) {
		needsupdate = func0f08e8ac(prop, &prop->pos, model_get_effective_scale(model), true);
	} else if (prop->type == PROPTYPE_PLAYER
			&& (g_Vars.mplayerisrunning
				|| (player = g_Vars.players[playermgr_get_player_num_by_prop(prop)], player->cameramode == CAMERAMODE_EYESPY)
				|| (player->cameramode == CAMERAMODE_THIRDPERSON && player->visionmode == VISIONMODE_SLAYERROCKET))) {
		model->anim->average = false;
		chr_update_anim(chr, lvupdate240, true);
		needsupdate = func0f08e8ac(prop, &prop->pos, model_get_effective_scale(model), true);
	} else {
		isrepeatframe2 = false;

		if (fulltick) {
			model->anim->average = false;
			chr_update_anim(chr, lvupdate240, true);
		}

		if (chr->model && chr->model->anim && (g_Anims[chr->model->anim->animnum].flags & ANIMFLAG_HASREPEATFRAMES)) {
			anim_load_header(chr->model->anim->animnum);

			isrepeatframe2 = anim_get_remapped_frame(chr->model->anim->animnum, chr->model->anim->framea) < 0
				|| (anim_get_remapped_frame(chr->model->anim->animnum, chr->model->anim->frameb) < 0
						&& chr->model->anim->frac != 0.0f);
		}

		if (isrepeatframe2) {
			needsupdate = false;
		} else {
			needsupdate = func0f08e8ac(prop, &prop->pos, model_get_effective_scale(model), true);
		}
	}

	if (fulltick) {
		if (chr->actiontype != ACT_STAND || model->anim->animnum2 != 0 || prop->type == PROPTYPE_PLAYER) {
#if VERSION >= VERSION_NTSC_1_0
			chr->hidden2 |= CHRH2FLAG_CONSIDERPROXIES;
#else
			chr->hidden |= CHRHFLAG_CONSIDERPROXIES;
#endif
		}

		chr_update_aim_properties(chr);
	}

	if (prop->pos.y < -65536) {
		needsupdate = false;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (!g_Vars.normmplayerisrunning && needsupdate) {
		if (chr->actiontype == ACT_DEAD
				|| (chr->actiontype == ACT_DRUGGEDKO && (chr->chrflags & CHRCFLAG_KEEPCORPSEKO) == 0)) {
			var8009cdac++;

			if (var8009cdac > 10) {
				needsupdate = false;
				chr_drop_items_for_owner_reap(chr);
				chr->hidden |= CHRHFLAG_DELETING;
			}
		} else {
			var8009cdb0++;
		}

		if (var8009cdb0 + var8009cdac > 30) {
			needsupdate = false;
		}
	}
#endif

	if (needsupdate) {
#ifdef DEBUG
		debug0f1199f0nb();
#endif

		prop->flags |= PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK;
		chr->chrflags |= CHRCFLAG_EVERONSCREEN;

		if (g_Vars.antiplayernum >= 0 && g_Vars.currentplayer == g_Vars.bond) {
			chr->hidden |= CHRHFLAG_ONBONDSSCREEN;
		}

		if (cheat_is_active(CHEAT_DKMODE)) {
			model_set_distance_scale(0.3125f);
		}

		g_ModelJointPositionedFunc = &chr_handle_joint_positioned;
		g_CurModelChr = chr;

		if (CHRRACE(chr) == RACE_DRCAROLL && g_Vars.tickmode != TICKMODE_CUTSCENE) {
			angle = chr_get_inverse_theta(chr);

			sp190.x = sinf(angle) * 19;
			sp190.y = 0.0f;
			sp190.z = cosf(angle) * 19;

			mtx4_load_translation(&sp190, &sp1a8);
			mtx4_mult_mtx4_in_place(cam_get_world_to_screen_mtxf(), &sp1a8);
			sp210.unk00 = &sp1a8;
		} else if (prop->type == PROPTYPE_PLAYER) {
			u8 stack[0x14];
			f32 sp130;
			player = g_Vars.players[playermgr_get_player_num_by_prop(prop)];

			if (player->bondmovemode == MOVEMODE_BIKE) {
				sp178 = chr_get_inverse_theta(chr);
				bike = (struct hoverbikeobj *)player->hoverbike->obj;
				sp130 = bike->w * 1000;

				sp17c.x = cosf(sp178) * sp130;
				sp17c.y = ABS(bike->w) * 200 + 25;
				sp17c.z = sinf(-sp178) * sp130;

				mtx4_load_translation(&sp17c, &sp1a8);
				mtx4_mult_mtx4_in_place(cam_get_world_to_screen_mtxf(), &sp1a8);
				sp210.unk00 = &sp1a8;
			} else {
				sp210.unk00 = cam_get_world_to_screen_mtxf();
			}
		} else {
			sp210.unk00 = cam_get_world_to_screen_mtxf();
		}

		sp210.unk10 = gfx_allocate(model->definition->nummatrices * sizeof(Mtxf));

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
			f32 sp114 = cam_get_lod_scale_z();
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
				if (debug_get_slow_motion() != SLOWMOTION_OFF) {
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

			model_set_matrices_with_anim(&sp210, model);

			if (restore) {
				anim->frac = prevfrac;
				anim->framea = prevframea;
				anim->frac2 = prevfrac2;
				anim->frame2a = prevframe2a;
			}

			g_ModelJointPositionedFunc = NULL;
			model_set_distance_scale(var800629e8);

			if (fulltick) {
				colour_tween(chr->shadecol, chr->nextcol);
			}

			prop->z = model_get_screen_distance(model);
			child = prop->child;

			while (child) {
				next = child->next;
				chr_tick_child(chr, child, fulltick);
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
					s32 hattype = hat_get_type(chr->weapons_held[2]);
					u8 stack[0x0c];

					index = chr->headnum - HEAD_SHAUN;

					hatpos.x = var8007dae4[index][hattype].x * 21.3f;
					hatpos.y = var8007dae4[index][hattype].y * 21.3f;
					hatpos.z = var8007dae4[index][hattype].z * 21.3f;

					spe4 = var8007dae4[index][hattype].unk0c;
					spe0 = var8007dae4[index][hattype].unk10;
					spdc = var8007dae4[index][hattype].unk14;

					mtx4_load_translation(&hatpos, &sp9c);
					mtx00015e24(spe4, &sp9c);
					mtx00015e80(spe0, &sp9c);
					mtx00015edc(spdc, &sp9c);
					mtx00015be4(hatmodel->matrices, &sp9c, &sp5c);
					mtx4_copy(&sp5c, hatmodel->matrices);

					if (hattype == HATTYPE_2) {
						hatvisible = false;
					}
				}
			}

			if (model->definition->skel == &g_SkelChr) {
				struct modelnode *headspotnode = model_get_part(model->definition, MODELPART_CHR_HEADSPOT);

				if (headspotnode && headspotnode->type == MODELNODETYPE_HEADSPOT) {
					union modelrwdata *rwdata = model_get_node_rw_data(model, headspotnode);

					if (rwdata->headspot.headmodeldef != NULL) {
						struct modelnode *hatnode = model_get_part(rwdata->headspot.headmodeldef, MODELPART_HEAD_HAT);

						if (hatnode != NULL) {
							union modelrwdata *hatrwdata = model_get_node_rw_data(model, hatnode);
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
			chr->hidden &= ~CHRHFLAG_ONBONDSSCREEN;
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
		if (chr->hidden & CHRHFLAG_DROPPINGITEM) {
			obj_drop_recursively(prop, false);
			chr->hidden &= ~CHRHFLAG_DROPPINGITEM;
		}

		func0f041a74(chr);
	}

	return TICKOP_NONE;
}

void chr_drop_concealed_items(struct chrdata *chr)
{
	struct prop *prop = chr->prop->child;

	while (prop) {
		if (prop != chr->weapons_held[2]
				&& prop != chr->weapons_held[1]
				&& prop != chr->weapons_held[0]
				&& (prop->obj->hidden & OBJHFLAG_EMBEDDED) == 0
				&& (prop->obj->flags & OBJFLAG_AIUNDROPPABLE) == 0) {
			obj_set_dropped(prop, DROPTYPE_DEFAULT);
		}

		prop = prop->next;
	}

	chr->hidden |= CHRHFLAG_DROPPINGITEM;
}

void chr_set_hudpiece_visible(struct chrdata *chr, bool visible)
{
	struct modeldef *modeldef = chr->model->definition;

	if (modeldef->skel == &g_SkelChr) {
		struct modelnode *headspotnode = model_get_part(modeldef, MODELPART_CHR_HEADSPOT);

		if (headspotnode && headspotnode->type == MODELNODETYPE_HEADSPOT) {
			union modelrwdata *rwdata = model_get_node_rw_data(chr->model, headspotnode);

			if (rwdata->headspot.headmodeldef) {
				struct modelnode *hudpiecenode = model_get_part(rwdata->headspot.headmodeldef, MODELPART_HEAD_HUDPIECE);

				if (hudpiecenode) {
					union modelrwdata *rwdata2 = model_get_node_rw_data(chr->model, hudpiecenode);
					rwdata2->toggle.visible = visible;
				}
			}
		}
	}
}

void chr_drop_items_for_owner_reap(struct chrdata *chr)
{
	struct prop *prop = chr->prop->child;

	while (prop)  {
		// If prop is not hat
		if (prop != chr->weapons_held[2]) {
			struct defaultobj *obj = prop->obj;

			if ((obj->flags & OBJFLAG_AIUNDROPPABLE) == 0) {
				obj_set_dropped(prop, DROPTYPE_OWNERREAP);
			}
		}

		prop = prop->next;
	}

	chr->hidden |= CHRHFLAG_DROPPINGITEM;
}

u8 g_ChrBloodColour[] = { 0x40, 0x0a, 0x0a };

void chrs_set_blood_colour(u8 *rgb)
{
	g_ChrBloodColour[0] = rgb[0];
	g_ChrBloodColour[1] = rgb[1];
	g_ChrBloodColour[2] = rgb[2];
}

void chrs_get_blood_colour(u8 *rgb)
{
	rgb[0] = g_ChrBloodColour[0];
	rgb[1] = g_ChrBloodColour[1];
	rgb[2] = g_ChrBloodColour[2];
}

void chrs_reset_onscreen_doors(void)
{
	g_ChrsNumOnscreenDoors = 0;
}

bool chr_find_onscreen_doors(struct chrdata *chr)
{
	s16 *propnumptr;
	s16 propnums[256];
	s32 i;
	struct onscreendoor *osd;
	struct coord *campos;
	bool result = false;

	for (i = 0; i < g_ChrsNumOnscreenDoors; i++) {
		g_ChrsOnscreenDoors[i].unk004 = false;
	}

	room_get_props(chr->prop->rooms, propnums, 256);
	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop->type == PROPTYPE_DOOR) {
			if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
				struct defaultobj *obj = prop->obj;
				struct doorobj *door = prop->door;
				struct coord pos;

				if (obj->model->definition->skel != &g_SkelWindowedDoor
						&& door->doortype != DOORTYPE_EYE
						&& door->doortype != DOORTYPE_IRIS
						&& door->doortype != DOORTYPE_FALLAWAY
						&& door->doortype != DOORTYPE_AZTECCHAIR
						&& (obj->flags & (OBJFLAG_00000010 | OBJFLAG_AISEETHROUGH)) == 0
						&& (obj->flags2 & OBJFLAG2_DOOR_ALTCOORDSYSTEM) == 0
						&& !((door->doorflags & DOORFLAG_TRANSLATION) == 0 && door->frac > 0)) {
					for (i = 0; i < g_ChrsNumOnscreenDoors; i++) {
						if (g_ChrsOnscreenDoors[i].prop == prop) {
							break;
						}
					}

					if (i < g_ChrsNumOnscreenDoors) {
						osd = &g_ChrsOnscreenDoors[i];
					} else {
						if (g_ChrsNumOnscreenDoors > 14) {
							goto next;
						}

						osd = &g_ChrsOnscreenDoors[g_ChrsNumOnscreenDoors];
						osd->prop = prop;
						osd->unk00c = 0;
						osd->unk130 = 0;
						osd->unk004 = 0;

						g_ChrsNumOnscreenDoors++;
					}

					if (!osd->unk00c) {
						struct modelrodata_bbox *bbox = obj_find_bbox_rodata(obj);
						osd->bbox = *bbox;

						mtx3_to_mtx4(obj->realrot, &osd->unk02c);
						mtx4_set_translation(&obj->prop->pos, &osd->unk02c);
						mtx000172f0(osd->unk02c.m, osd->unk06c.m);

						campos = &g_Vars.currentplayer->cam_pos;

						osd->unk12c = (
								+ osd->unk06c.m[0][2] * campos->f[0]
								+ osd->unk06c.m[1][2] * campos->f[1]
								+ osd->unk06c.m[2][2] * campos->f[2]) + osd->unk06c.m[3][2];

						mtx00015be4(&osd->unk06c, cam_get_projection_mtxf(), &osd->unk0ac);
						osd->unk00c = true;
					}

					model_get_root_position(chr->model, &pos);

					osd->unk008 = (
							osd->unk06c.m[0][2] * pos.f[0] +
							osd->unk06c.m[1][2] * pos.f[1] +
							osd->unk06c.m[2][2] * pos.f[2]) + osd->unk06c.m[3][2];

					if ((osd->unk008 > osd->bbox.zmax && osd->unk12c < osd->bbox.zmin)
							|| (osd->unk008 < osd->bbox.zmin && osd->unk12c > osd->bbox.zmax)) {
						osd->unk004 = true;
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

bool chr_should_render_gundl(struct model *model, struct modelnode *node)
{
	struct model *rootmodel;
	struct modelnode *bboxnode;
	f32 value;
	struct doorobj *door;
	struct modelrodata_bbox *bbox;
	struct onscreendoor *osd;
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
			mtx = model_find_node_mtx(model, node, 0);

			for (i = 0; i < g_ChrsNumOnscreenDoors; i++) {
				if (g_ChrsOnscreenDoors[i].unk004) {
					osd = &g_ChrsOnscreenDoors[i];
					done = false;
					spb0 = false;
					door = osd->prop->door;

					mtx00015be4(&osd->unk0ac, mtx, &spb4);

					if (osd->unk130 == 0) {
						if (door->doortype == DOORTYPE_VERTICAL) {
							spa0.x = osd->bbox.xmin;
							spa0.y = osd->bbox.ymin;
							spa0.z = osd->bbox.zmin;

							sp94.x = osd->bbox.xmax;
							sp94.y = osd->bbox.ymin;
							sp94.z = osd->bbox.zmin;

							sp88.x = osd->bbox.xmax;
							sp88.y = osd->bbox.ymax;
							sp88.z = osd->bbox.zmin;
						} else {
							spa0.x = osd->bbox.xmax;
							spa0.y = osd->bbox.ymax;
							spa0.z = osd->bbox.zmin;

							sp94.x = osd->bbox.xmax;
							sp94.y = osd->bbox.ymin;
							sp94.z = osd->bbox.zmin;

							sp88.x = osd->bbox.xmin;
							sp88.y = osd->bbox.ymin;
							sp88.z = osd->bbox.zmin;
						}

						mtx00015be4(cam_get_world_to_screen_mtxf(), &osd->unk02c, &osd->unk0ec);
						mtx4_transform_vec(&osd->unk0ec, &spa0, &sp70);
						cam0f0b4dec(&sp70, osd->unk134);
						mtx4_transform_vec(&osd->unk0ec, &sp94, &sp70);
						cam0f0b4dec(&sp70, osd->unk13c);
						mtx4_transform_vec(&osd->unk0ec, &sp88, &sp70);
						cam0f0b4dec(&sp70, osd->unk144);

						osd->unk130 = 1;
						osd->unk14c = osd->unk13c[1] - osd->unk134[1];
						osd->unk150 = -(osd->unk13c[0] - osd->unk134[0]);
						osd->unk154 = osd->unk14c * osd->unk134[0] + osd->unk150 * osd->unk134[1];
						osd->unk158 = osd->unk14c * osd->unk144[0] + osd->unk150 * osd->unk144[1] - osd->unk154;
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

						mtx4_transform_vec(mtx, &sp64, &sp70);
						cam0f0b4dec(&sp70, sp80);

						value = osd->unk14c * sp80[0] + osd->unk150 * sp80[1] - osd->unk154;

						if ((osd->unk158 >= 0.0f && value < 0.0f) || (osd->unk158 <= 0.0f && value > 0.0f)) {
							spb0 = true;
							break;
						}

						if (!done) {
							mtx4_transform_vec(&spb4, &sp64, &sp70);

							if (sp70.x >= osd->bbox.xmin
									&& sp70.x <= osd->bbox.xmax
									&& sp70.y >= osd->bbox.ymin
									&& sp70.y <= osd->bbox.ymax
									&& ((osd->bbox.zmax < osd->unk008 && sp70.z < osd->bbox.zmax)
										|| (osd->unk008 < osd->bbox.zmin && osd->bbox.zmin < sp70.z))) {
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
void chr_render_attached_object(struct prop *prop, struct modelrenderdata *renderdata, bool xlupass, struct chrdata *chr)
{
	if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		u32 stack;
		struct defaultobj *obj = prop->obj;
		struct model *model = obj->model;
		struct prop *child;

		model_render(renderdata, model);

		// Note: OBJH2FLAG_HASOPA << 1 is OBJH2FLAG_HASXLU
		// so this is just checking if the appropriate flag is enabled
		if (obj->hidden2 & (OBJH2FLAG_HASOPA << xlupass)) {
			renderdata->gdl = wallhit_render_prop_hits(renderdata->gdl, prop, xlupass);
		}

		child = prop->child;

		while (child) {
			chr_render_attached_object(child, renderdata, xlupass, chr);
			child = child->next;
		}

		if (xlupass) {
			mtx_f2l_bulk(model->matrices, model->definition->nummatrices);
		}
	}
}

void chr_get_blood_colour(s16 bodynum, u8 *colour1, u32 *colour2)
{
	switch (bodynum) {
	case BODY_ELVIS1:
	case BODY_THEKING:
	case BODY_ELVISWAISTCOAT:
		if (colour1) {
			colour1[0] = 0x0a;
			colour1[1] = 0x40;
			colour1[2] = 0x0a;
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
			colour1[0] = 0x0a;
			colour1[1] = 0x0a;
			colour1[2] = 0x0a;
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
			colour1[2] = 0x0a;
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
		colour1[1] = 0x0a;
		colour1[2] = 0x0a;
	}

	if (colour2) {
		colour2[0] = 0x301010ff;
		colour2[1] = 0x401010ff;
		colour2[2] = 0x560011a0;
	}
}

Gfx *chr_render(struct prop *prop, Gfx *gdl, bool xlupass)
{
	struct chrdata *chr = prop->chr;
	struct model *model = chr->model;
	f32 shadecolourfracs[4];
	s32 shademode;
	s32 sp100;
	s32 alpha;
	struct eyespy *eyespy;
	struct prop *child;
	f32 xrayalphafrac;
	u8 spec[4];
	u8 speb = 0;

	// Don't render the eyespy if we're the one controlling it
	if (CHRRACE(chr) == RACE_EYESPY) {
		eyespy = chr_to_eyespy(chr);

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

	if (chr->aibot && chr->aibot->fadeintimer60 > 0) {
		alpha = (f32)alpha * (TICKS(120) - chr->aibot->fadeintimer60) * (1.0f / TICKS(120));
	}

	chr_get_blood_colour(chr->bodynum, spec, NULL);
	chrs_set_blood_colour(spec);
	alpha *= obj_calculate_fade_dist_opacity_frac(prop, model_get_effective_scale(model));

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
		alpha = chr_get_cloak_alpha(chr) * alpha * 0.0039215688593686f;
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

	shademode = env_get_obj_shade_mode(prop, shadecolourfracs);

	if (chr->unk32c_18) {
		prop_calculate_shade_colour(chr->prop, chr->nextcol, chr->floorcol);
		chr->unk32c_18 = false;
	}

	if (shademode != SHADEMODE_XLU && alpha > 0) {
		struct modelrenderdata renderdata = {0, 1, 3};
		struct screenbox screenbox;
		s32 colour[4]; // rgba levels, but allowing > 256 temporarily
		u32 stack;

		if (xlupass && chr->cloakfadefrac > 0 && !chr->cloakfadefinished) {
			gdl = chr_render_cloak(gdl, chr->prop, chr->prop);
		}

		if (func0f08e5a8(prop->rooms, &screenbox) > 0 && (chr->chrflags & CHRCFLAG_UNPLAYABLE) == 0) {
			gdl = bg_scissor_within_viewport(gdl, screenbox.xmin, screenbox.ymin, screenbox.xmax, screenbox.ymax);
		} else {
			gdl = bg_scissor_to_viewport(gdl);
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
			speb = scenario_highlight_prop(prop, colour);
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

		obj_merge_colour_fracs(colour, shademode, shadecolourfracs);

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

		renderdata.envcolour = g_ChrBloodColour[0] << 24 | g_ChrBloodColour[1] << 16 | g_ChrBloodColour[2] << 8;
		renderdata.fogcolour = colour[0] << 24 | colour[1] << 16 | colour[2] << 8 | colour[3];

		if (alpha < 0xff) {
			renderdata.unk30 = 8;
			renderdata.envcolour |= (u8)alpha;
		} else {
			renderdata.unk30 = 7;
		}

		// Set Skedar eyes open or closed
		if (model->definition->skel == &g_SkelSkedar) {
			struct modelnode *node1 = model_get_part(model->definition, MODELPART_SKEDAR_EYESOPEN);
			struct modelnode *node2 = model_get_part(model->definition, MODELPART_SKEDAR_EYESCLOSED);

			if (node1 && node2) {
				union modelrwdata *data1 = model_get_node_rw_data(model, node1);
				union modelrwdata *data2 = model_get_node_rw_data(model, node2);

				data2->toggle.visible = chr->actiontype == ACT_DIE || chr->actiontype == ACT_DEAD;
				data1->toggle.visible = !data2->toggle.visible;
			}
		}

		// Set Maian eyes open or closed
		if (chr->headnum == HEAD_THEKING
				|| chr->headnum == HEAD_ELVIS
				|| chr->headnum == HEAD_MAIAN_S
				|| chr->headnum == HEAD_ELVIS_GOGS) {
			if (model->definition->skel == &g_SkelChr) {
				struct modelnode *headspotnode = model_get_part(model->definition, MODELPART_CHR_HEADSPOT);

				if (headspotnode && headspotnode->type == MODELNODETYPE_HEADSPOT) {
					union modelrwdata *headrwdata = model_get_node_rw_data(model, headspotnode);

					if (headrwdata->headspot.headmodeldef) {
						struct modelnode *node1 = model_get_part(headrwdata->headspot.headmodeldef, MODELPART_HEAD_EYESOPEN);
						struct modelnode *node2 = model_get_part(headrwdata->headspot.headmodeldef, MODELPART_HEAD_EYESCLOSED);

						if (node1 && node2) {
							union modelrwdata *data1 = model_get_node_rw_data(model, node1);
							union modelrwdata *data2 = model_get_node_rw_data(model, node2);

							data2->toggle.visible = chr->actiontype == ACT_DIE || chr->actiontype == ACT_DEAD;
							data1->toggle.visible = !data2->toggle.visible;
						}
					}
				}
			}
		}

		if (chr->race == RACE_DRCAROLL) {
			chr_set_drcaroll_images(chr, chr->drcarollimage_left, chr->drcarollimage_right);
		}

		g_Vars.currentplayerstats->drawplayercount++;

		if (chr_find_onscreen_doors(chr)) {
			g_ModelShouldRenderGunDlCallback = chr_should_render_gundl;
		}

		// Render the chr's model
		model_render(&renderdata, model);

		// Render attached props (eg. held guns and attached mines/knives/bolts)
		child = prop->child;

		while (child) {
			chr_render_attached_object(child, &renderdata, xlupass, chr);
			child = child->next;
		}

		gdl = renderdata.gdl;

		g_ModelShouldRenderGunDlCallback = NULL;

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
						} else if (shademode == SHADEMODE_FRAC) {
							shadowalpha = (1.0f - shadecolourfracs[3]) * ((alpha * 100) >> 8);
						} else {
							shadowalpha = (s32)(alpha * 100) >> 8;
						}

						if (gaptoground >= 150.0f) {
							shadowalpha = shadowalpha * (400 - gaptoground) * 0.004f;
						}

						if (cheat_is_active(CHEAT_SMALLCHARACTERS)) {
							radius *= 0.4f;
						}

						gdl = gfx_render_radial_shadow(gdl, prop->pos.x, chr->ground, prop->pos.z, chr_get_inverse_theta(chr), radius, 0xffffff00 | shadowalpha);
					}
				}
			}

			mtx_f2l_bulk(model->matrices, model->definition->nummatrices);

			if (USINGDEVICE(DEVICE_IRSCANNER)) {
				gdl = chr_render_shield(gdl, chr, 0x80);
			} else {
				gdl = chr_render_shield(gdl, chr, alpha);
			}
		}
	}

	return gdl;
}

struct shieldhit *g_ShieldHits = NULL;

void chr_emit_sparks(struct chrdata *chr, struct prop *prop, s32 hitpart, struct coord *coord, struct coord *coord2, struct chrdata *chr2)
{
	struct prop *chrprop = chr->prop;
	s32 race;

	if (chr_is_using_paintball(chr2)) {
		sparks_create(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_PAINT);
		return;
	}

	if (chr_get_shield(chr) > 0.0f) {
		sparks_create(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_DEFAULT);
		return;
	}

	if (prop->type == PROPTYPE_OBJ
			|| prop->type == PROPTYPE_WEAPON
			|| prop->type == PROPTYPE_DOOR
			|| hitpart == HITPART_GUN
			|| hitpart == HITPART_HAT) {
		sparks_create(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_DEFAULT);
		return;
	}

	race = CHRRACE(chr);

	if (race == RACE_DRCAROLL || race == RACE_ROBOT || race == RACE_EYESPY) {
		sparks_create(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_ELECTRICAL);
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

		sparks_create(chrprop->rooms[0], chrprop, &coord3, coord2, 0, SPARKTYPE_FLESH_LARGE);
	}

#if VERSION < VERSION_JPN_FINAL
	sparks_create(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_BLOOD);
	sparks_create(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_FLESH);
#endif
}

void chr_bruise_from_stabby_projectile(struct model *model, s32 hitpart, struct modelnode *node, struct coord *arg3)
{
	struct modelnode *bestnode = NULL;
	s32 mindist = 0x7fffffff;
	s32 bestcoords[3];
	struct modelnode *curnode;
	Gfx *gdlptr;
	Gfx *gdlptr2;
	Vtx *vertices;
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

	model_node_get_model_relative_position(model, model_node_find_mtx_node(node), &relpos);

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
			rwdata = model_get_node_rw_data(model, curnode);

			if (rwdata->gdl == NULL) {
				break;
			}

			// By default, the model instance's displaylist points to the
			// one in the model definition. If it hasn't been changed we'll
			// use the space... after the model definition's colour table?
			// Let's hope that's not being used by other instances...
			if (rwdata->gdl == rodata->opagdl) {
				gdlptr = (Gfx *)((uintptr_t)rodata->colours + ((uintptr_t)rodata->opagdl & 0xffffff));
			} else {
				gdlptr = rwdata->gdl;
			}

			if (rodata->xlugdl) {
				gdlptr2 = (Gfx *)((uintptr_t)rodata->colours + ((uintptr_t)rodata->xlugdl & 0xffffff));
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

						vertices = (Vtx *)((uintptr_t)rodata->vertices + word);
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
						posnode = model_find_node_by_mtx_index(model, addr / sizeof(Mtxf));
						model_node_get_model_relative_position(model, posnode, &spd4);

						spbc[0] = spd4.x + spc8.x;
						spbc[1] = spd4.y + spc8.y;
						spbc[2] = spd4.z + spc8.z;
					}

					gdlptr++;
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model_apply_distance_relations(model, curnode);
			break;
		case MODELNODETYPE_TOGGLE:
			model_apply_toggle_relations(model, curnode);
			break;
		case MODELNODETYPE_HEADSPOT:
			model_apply_head_relations(model, curnode);
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
	// the chosen vertex, and darken them.
	curnode = model->definition->rootnode;

	while (curnode) {
		nodetype = curnode->type & 0xff;

		switch (nodetype) {
		case MODELNODETYPE_DL:
			rodata = &curnode->rodata->dl;
			rwdata = model_get_node_rw_data(model, curnode);

			if (rwdata->gdl == NULL) {
				break;
			}

			if (rwdata->gdl == rodata->opagdl) {
				gdlptr = (Gfx *)((uintptr_t)rodata->colours + ((u32)rodata->opagdl & 0xffffff));
			} else {
				gdlptr = rwdata->gdl;
			}

			if (rodata->xlugdl) {
				gdlptr2 = (Gfx *)((uintptr_t)rodata->colours + ((u32)rodata->xlugdl & 0xffffff));
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
						Vtx *vertices = (Vtx *)((uintptr_t)rodata->vertices + word);
						s32 numverts = (u32)ptr[1] / 16 + 1;
						s32 i;

						if (posnode) {
							for (i = 0; i < numverts; i++) {
								s32 x = vertices[i].x + (s32)spd4.f[0];
								s32 y = vertices[i].y + (s32)spd4.f[1];
								s32 z = vertices[i].z + (s32)spd4.f[2];

								if (x == bestcoords[0] && y == bestcoords[1] && z == bestcoords[2]) {
									if ((uintptr_t)rwdata->colours == ALIGN8((uintptr_t)rodata->vertices + rodata->numvertices * sizeof(Vtx))) {
										Col *colours = vtxstore_allocate(rodata->numcolours, VTXSTORETYPE_CHRCOL, 0, 0);
										s32 j;

										if (colours) {
											for (j = 0; j < rodata->numcolours; j++) {
												colours[j] = rwdata->colours[j];
											}

											rwdata->colours = colours;
										} else {
											// empty
										}
									}

									if ((uintptr_t)rwdata->colours != ALIGN8((uintptr_t)rodata->vertices + rodata->numvertices * sizeof(Vtx))) {
										s32 offset = rwdata->vertices[word / sizeof(Vtx) + i].colour >> 2;
										Col *colours = (Col *) ((uintptr_t)rwdata->colours + spac);

										colours[offset].a = alpha;
									}
								}
							}
						}
					} else if (op == G_MTX) {
						u32 addr = gdlptr->words.w1 & 0xffffff;
						posnode = model_find_node_by_mtx_index(model, addr / sizeof(Mtxf));
						model_node_get_model_relative_position(model, posnode, &spd4);
					} else if (op == G_COL) {
						spac = gdlptr->words.w1 & 0xffffff;
					}

					gdlptr++;
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model_apply_distance_relations(model, curnode);
			break;
		case MODELNODETYPE_TOGGLE:
			model_apply_toggle_relations(model, curnode);
			break;
		case MODELNODETYPE_HEADSPOT:
			model_apply_head_relations(model, curnode);
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
 * Bruise a chr by darkening their vertices.
 *
 * This happens when the chr is shot, which creates the illusion of blood
 * soaking through their clothing.
 */
void chr_bruise(struct model *model, s32 hitpart, struct modelnode *node, struct coord *arg3)
{
	struct modelnode *bestnode = NULL;
	bool ok;
	s32 nodetype;
	s32 mindist = 0x7fffffff;
	Vtx *vertices;
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

	model_node_get_model_relative_position(model, model_node_find_mtx_node(node), &relpos);

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
			rwdata = model_get_node_rw_data(model, curnode);

			if (rwdata->gdl == NULL) {
				break;
			}

			// By default, the model instance's displaylist points to the
			// one in the model definition. If it hasn't been changed we'll
			// use the space... after the model definition's colour table?
			// Let's hope that's not being used by other instances...
			if (rwdata->gdl == rodata->opagdl) {
				gdlptr = (Gfx *)((uintptr_t)rodata->colours + ((u32)rodata->opagdl & 0xffffff));
			} else {
				gdlptr = rwdata->gdl;
			}

			if (rodata->xlugdl) {
				gdlptr2 = (Gfx *)((uintptr_t)rodata->colours + ((u32)rodata->xlugdl & 0xffffff));
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

						vertices = (Vtx *)((uintptr_t)rodata->vertices + word);
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
						posnode = model_find_node_by_mtx_index(model, addr / sizeof(Mtxf));
						model_node_get_model_relative_position(model, posnode, &spd4);

						spbc[0] = spd4.x + spc8.x;
						spbc[1] = spd4.y + spc8.y;
						spbc[2] = spd4.z + spc8.z;
					}

					gdlptr++;
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model_apply_distance_relations(model, curnode);
			break;
		case MODELNODETYPE_TOGGLE:
			model_apply_toggle_relations(model, curnode);
			break;
		case MODELNODETYPE_HEADSPOT:
			model_apply_head_relations(model, curnode);
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
	curnode = model->definition->rootnode;

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
				rwdata = model_get_node_rw_data(model, curnode);

				if (rwdata->gdl == NULL) {
					break;
				}

				if (rwdata->gdl == rodata->opagdl) {
					gdlptr = (Gfx *)((uintptr_t)rodata->colours + ((u32)rodata->opagdl & 0xffffff));
				} else {
					gdlptr = rwdata->gdl;
				}

				if (rodata->xlugdl) {
					gdlptr2 = (Gfx *)((uintptr_t)rodata->colours + ((u32)rodata->xlugdl & 0xffffff));
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
							Vtx *vertices = (Vtx *)((uintptr_t)rodata->vertices + word);
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
												if ((uintptr_t)rwdata->colours == ALIGN8((u32)rodata->vertices + rodata->numvertices * sizeof(Vtx))) {
													Col *colours = vtxstore_allocate(rodata->numcolours, VTXSTORETYPE_CHRCOL, 0, 0);
													s32 j;

													if (colours) {
														for (j = 0; j < rodata->numcolours; j++) {
															colours[j] = rwdata->colours[j];
														}

														rwdata->colours = colours;
													}
												}

												if ((uintptr_t)rwdata->colours != ALIGN8((uintptr_t)rodata->vertices + rodata->numvertices * sizeof(Vtx))) {
													s32 offset = rwdata->vertices[word / sizeof(Vtx) + i].colour >> 2;
													Col *colours = (Col *) ((uintptr_t)rwdata->colours + spac);

													colours[offset].a = alpha;
												}
											}
										}
									}
								}
							}
						} else if (op == G_MTX) {
							u32 addr = gdlptr->words.w1 & 0xffffff;
							posnode = model_find_node_by_mtx_index(model, addr / sizeof(Mtxf));
							model_node_get_model_relative_position(model, posnode, &spd4);
						} else if (op == G_COL) {
							spac = gdlptr->words.w1 & 0xffffff;
						}

						gdlptr++;
					}
				}
			}
			break;
		case MODELNODETYPE_DISTANCE:
			model_apply_distance_relations(model, curnode);
			break;
		case MODELNODETYPE_TOGGLE:
			model_apply_toggle_relations(model, curnode);
			break;
		case MODELNODETYPE_HEADSPOT:
			model_apply_head_relations(model, curnode);
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
void chr_disfigure(struct chrdata *chr, struct coord *exppos, f32 damageradius)
{
	struct modelnode *node;
	struct modelrodata_dl *rodata;
	struct modelrwdata_dl *rwdata;
	Col *colours;
	struct model *model = chr->model;
	Vtx *vertices;
	u32 stack;
	Gfx *gdlptr;
	Gfx *gdlptr2;
	struct modelnode *posnode = NULL;
	struct coord pos;
	s32 i;
	s32 j;

	u32 rand = random();

	if (g_Vars.mplayerisrunning || !chr_is_dead(chr)) {
		return;
	}

	// Iterate the nodes in the chr model
	node = model->definition->rootnode;

	while (node) {
		switch (node->type & 0xff) {
		case MODELNODETYPE_DL:
			rodata = &node->rodata->dl;
			rwdata = model_get_node_rw_data(model, node);

			if (rwdata->gdl == NULL) {
				break;
			}

			// Check that the node is using the modeldef's vertices
			// (ie. we haven't disfigured this node already)
			if (rwdata->vertices == rodata->vertices) {
				// Copy the vertices from the modeldef to the vtxstore
				if (rwdata->vertices == rodata->vertices) {
					Vtx *vertices = vtxstore_allocate(rodata->numvertices, VTXSTORETYPE_CHRVTX, 0, 0);

					if (vertices) {
						for (i = 0; i < rodata->numvertices; i++) {
							vertices[i] = rwdata->vertices[i];
						}

						rwdata->vertices = vertices;
					}
				}

				// Copy the colours from the modeldef to the vtxstore
				if ((uintptr_t)rwdata->colours == ALIGN8((uintptr_t)&rodata->vertices[rodata->numvertices])) {
					colours = vtxstore_allocate(rodata->numcolours, VTXSTORETYPE_CHRCOL, 0, 0);

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
						&& (uintptr_t)rwdata->colours != ALIGN8((uintptr_t)&rodata->vertices[rodata->numvertices])) {
					if (rwdata->gdl == rodata->opagdl) {
						gdlptr = (Gfx *)((uintptr_t)rodata->colours + ((s32)rodata->opagdl & 0xffffff));
					} else {
						gdlptr = rwdata->gdl;
					}

					if (rodata->xlugdl) {
						gdlptr2 = (Gfx *)((uintptr_t)rodata->colours + ((s32)rodata->xlugdl & 0xffffff));
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

								vertices = (Vtx *)((uintptr_t)rwdata->vertices + word);
								numverts = (u32)ptr[1] / 16 + 1;

								if (posnode) {
									for (i = 0; i < numverts; i++) {
										rng2_set_seed(rand + vertices[i].x + vertices[i].y + vertices[i].z + (u32)pos.f[0] + (u32)pos.f[1] + (u32)pos.f[2]);

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
								posnode = model_find_node_by_mtx_index(model, addr / sizeof(Mtxf));
								model_node_get_model_relative_position(model, posnode, &pos);
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
			model_apply_distance_relations(model, node);
			break;
		case MODELNODETYPE_TOGGLE:
			model_apply_toggle_relations(model, node);
			break;
		case MODELNODETYPE_HEADSPOT:
			model_apply_head_relations(model, node);
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

f32 chr_get_hit_radius(struct chrdata *chr)
{
	s32 i;
	f32 result;
	f32 highest = 0;

	if (chr->model) {
		result = model_get_effective_scale(chr->model);

		for (i = 0; i < 2; i++) {
			if (chr->weapons_held[i]) {
				struct defaultobj *obj = chr->weapons_held[i]->obj;
				f32 value = model_get_effective_scale(obj->model) * chr->model->scale;

				if (value > highest) {
					highest = value;
				}
			}
		}

		result += highest;

		if (chr_get_shield(chr) > 0) {
			result += 10;
		}
	} else {
		result = 100;
	}

	return result;
}

void chr_test_hit(struct prop *prop, struct shotdata *shotdata, bool isshooting, bool cheap)
{
	struct coord spdc;
	struct coord spd0;
	struct chrdata *chr = prop->chr;

	if ((chr->chrflags & CHRCFLAG_HIDDEN) == 0 && (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)) {
		f32 radius = chr_get_hit_radius(chr);

		if (prop->z - radius < shotdata->distance) {
			struct model *model = chr->model;
			s32 hitpart = 0;
			struct modelnode *node = NULL;
			s32 spb8 = 0;
			struct hitthing sp88;
			s32 sp84 = 0;
			struct modelnode *sp80 = NULL;
			Mtxf *rootmtx = model_get_root_mtx(model);
			struct prop *next;
			struct prop *child;
			f32 sp70;
			Mtxf *mtx;
			f32 sp68;

			if (func0f06b39c(&shotdata->gunpos2d, &shotdata->gundir2d, (struct coord *)rootmtx->m[3], radius)) {
				spb8 = 1;
				hitpart = 1;
			}

			if (hitpart) {
				if (chr_get_shield(chr) > 0.0f) {
					var8005efc0 = 10.0f / model->scale;
				}

				child = prop->child;

				while (child) {
					next = child->next;
					func0f0859a0(child, shotdata);
					child = next;
				}

				if (cheap || var8005efc0 > 0.0f) {
					hitpart = model_test_for_hit(model, &shotdata->gunpos2d, &shotdata->gundir2d, &node);

					while (hitpart > 0) {
						if (func0f084594(model, node, &shotdata->gunpos2d, &shotdata->gundir2d, &sp88, &sp84, &sp80)) {
							mtx4_transform_vec(&model->matrices[sp84], &sp88.pos, &spdc);
							mtx4_transform_vec_in_place(cam_get_projection_mtxf(), &spdc);
							mtx4_rotate_vec(&model->matrices[sp84], &sp88.unk0c, &spd0);
							mtx4_rotate_vec_in_place(cam_get_projection_mtxf(), &spd0);
							break;
						}

						hitpart = model_test_for_hit(model, &shotdata->gunpos2d, &shotdata->gundir2d, &node);
					}
				} else {
					hitpart = model_test_for_hit(model, &shotdata->gunpos2d, &shotdata->gundir2d, &node);

					if (hitpart > 0) {
						if (func0f06bea0(model, model->definition->rootnode, model->definition->rootnode, &shotdata->gunpos2d,
									&shotdata->gundir2d, &sp88.pos, &sp70, &node, &hitpart, &sp84, &sp80)) {
							mtx4_transform_vec(cam_get_projection_mtxf(), &sp88.pos, &spdc);
							mtx4_rotate_vec(cam_get_projection_mtxf(), &sp88.unk0c, &spd0);
						} else {
							hitpart = 0;
						}
					}
				}

				if (var8005efc0 > 0.0f) {
					var8005efc0 = 0.0f;
				}
			}

			if (hitpart > 0) {
				mtx = cam_get_world_to_screen_mtxf();
				sp68 = spdc.x * mtx->m[0][2] + spdc.y * mtx->m[1][2] + spdc.z * mtx->m[2][2] + mtx->m[3][2];
				sp68 = -sp68;

				if (sp68 < shotdata->distance) {
					hit_create(shotdata, prop, sp68, hitpart, node, &sp88, sp84, sp80, model, true, chr_get_shield(chr) > 0.0f, &spdc, &spd0);
				}
			}

			if (spb8 && hitpart <= 0 && prop->z <= shotdata->distance && isshooting) {
				if (chr_get_target_prop(chr) == g_Vars.currentplayer->prop) {
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
void chr_hit(struct shotdata *shotdata, struct hit *hit)
{
	struct prop *prop;
	struct chrdata *chr;
	Mtxf spb0;
	struct coord hitpos;
	struct coord sp98;
	s16 hitpos_s16[3];
	u8 ismelee = false;
	struct weaponfunc *func = gset_get_weapon_function(&shotdata->gset);
	f32 shield;

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_MELEE) {
		ismelee = true;
	}

	// The prop that was hit could be an item held by the chr,
	// so traverse the parents. The root parent is the chr itself.
	prop = hit->prop;

	while (prop->parent) {
		prop = prop->parent;
	}

	chr = prop->chr;

	if ((chr->chrflags & CHRCFLAG_HIDDEN) == 0) {
		sp98.x = shotdata->gunpos2d.x - (hit->distance * shotdata->gundir2d.x) / shotdata->gundir2d.z;
		sp98.y = shotdata->gunpos2d.y - (hit->distance * shotdata->gundir2d.y) / shotdata->gundir2d.z;
		sp98.z = shotdata->gunpos2d.z - hit->distance;

		mtx4_transform_vec(cam_get_projection_mtxf(), &sp98, &hitpos);
		bgun_set_hit_pos(&hitpos);
		bgun_play_prop_hit_sound(&shotdata->gset, hit->prop, -1);

		chr_emit_sparks(chr, hit->prop, hit->hitpart, &hitpos, &shotdata->gundir3d, g_Vars.currentplayer->prop->chr);

		hitpos_s16[0] = hit->hitthing.pos.x;
		hitpos_s16[1] = hit->hitthing.pos.y;
		hitpos_s16[2] = hit->hitthing.pos.z;

		shield = chr_get_shield(chr);

		chr_damage_by_impact(chr, gset_get_damage(&shotdata->gset), &shotdata->gundir3d, &shotdata->gset,
				g_Vars.currentplayer->prop, hit->hitpart, hit->prop, hit->bboxnode,
				hit->model, hit->hitthing.unk28 / 2, hitpos_s16);

		if (g_Vars.antiplayernum >= 0
				&& g_Vars.currentplayer == g_Vars.anti
				&& (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE)) {
			return;
		}

		if (g_Vars.coopplayernum >= 0
				&& g_Vars.coopfriendlyfire == false
				&& prop->type == PROPTYPE_PLAYER) {
			return;
		}

		if (g_MissionConfig.iscoop && g_Vars.coopfriendlyfire == false && chr->team == TEAM_ALLY) {
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
					obj_set_dropped(hit->prop, DROPTYPE_DEFAULT);
					chr->hidden |= CHRHFLAG_DROPPINGITEM;
					obj_damage(&weapon->base, gset_get_damage(&shotdata->gset), &sp98, shotdata->gset.weaponnum, g_Vars.currentplayernum);
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

						wallhit_create(
								&hit->hitthing.pos,
								&hit->hitthing.unk0c,
								&shotdata->gunpos3d,
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
					obj_set_dropped(hit->prop, DROPTYPE_DEFAULT);
					chr->hidden |= CHRHFLAG_DROPPINGITEM;
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

				wallhit_create(
						&hit->hitthing.pos,
						&hit->hitthing.unk0c,
						&shotdata->gunpos3d,
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
				Mtxf *sp58 = model_find_node_mtx(hit->model, hit->bboxnode, 0);

				// Create blood
				mtx0001719c(sp58->m, spb0.m);
				mtx4_transform_vec(&spb0, &sp98, &sp5c);

#if VERSION >= VERSION_NTSC_1_0
				if (!chr->noblood
						&& race != RACE_DRCAROLL
						&& race != RACE_ROBOT
						&& race != RACE_EYESPY
						&& !ismelee
						&& shotdata->gset.weaponnum != WEAPON_TRANQUILIZER) {
					u8 darker;

					if (chr->bodynum == BODY_MRBLONDE || race == RACE_SKEDAR) {
						darker = true;
					} else {
						darker = false;
					}

					if (!chr_is_using_paintball(g_Vars.currentplayer->prop->chr)) {
						chr_bruise(hit->model, hit->hitpart, hit->bboxnode, &sp5c);
					}

					splats_create_for_chr_hit(prop, shotdata, &sp98, &hitpos, darker, 0, g_Vars.currentplayer->prop->chr);
				}
#else
				// NTSC beta wraps all the blood logic in this paintball check.
				// If paintball is enabled, neither blood nor paint is created.
				if (!chr_is_using_paintball(g_Vars.currentplayer->prop->chr)
						&& !chr->noblood
						&& race != RACE_DRCAROLL
						&& race != RACE_ROBOT
						&& race != RACE_EYESPY
						&& !ismelee
						&& shotdata->gset.weaponnum != WEAPON_TRANQUILIZER) {
					u8 darker;

					if (chr->bodynum == BODY_MRBLONDE || race == RACE_SKEDAR) {
						darker = true;
					} else {
						darker = false;
					}

					chr_bruise(hit->model, hit->hitpart, hit->bboxnode, &sp5c);

					splats_create_for_chr_hit(prop, shotdata, &sp98, &hitpos, darker, 0, g_Vars.currentplayer->prop->chr);
				}
#endif
			}
		}
	}
}

void chrs_set_stage_translation_thing(f32 arg1)
{
	// empty
}

void chranimdebug_everyone(bool enable)
{
	g_ChrsAnimDebugSetAll = enable;
	g_ChrsAnimDebugForceLoop = enable;
}

void chranimdebug_decrement_anim(s32 quantity)
{
	g_ChrsAnimDebugAnimNum -= quantity;

	if (g_ChrsAnimDebugAnimNum <= 0) {
		g_ChrsAnimDebugAnimNum = anim_get_num_animations() - 1;
	}
}

void chranimdebug_increment_anim(s32 quantity)
{
	g_ChrsAnimDebugAnimNum += quantity;

	if (g_ChrsAnimDebugAnimNum >= anim_get_num_animations()) {
		g_ChrsAnimDebugAnimNum = 1;
	}
}

void chranimdebug_toggle_paused(void)
{
	g_ChrsAnimDebugPaused = !g_ChrsAnimDebugPaused;
}

void chranimdebug_select_anim(bool enable)
{
	g_ChrsAnimDebugSlow = enable;

	main_override_variable("selectanimnum", &g_ChrsAnimDebugAnimNum);
}

void chrs_check_for_noise(f32 noiseradius)
{
	s32 i;
	f32 add = 0.075f;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].model) {
			struct prop *prop = g_ChrSlots[i].prop;

			if (prop && prop->type == PROPTYPE_CHR &&
					chr_get_target_prop(&g_ChrSlots[i]) == g_Vars.currentplayer->prop) {

				f32 distance = chr_get_distance_to_current_player(&g_ChrSlots[i]);

				if (distance == 0) {
					distance = 2;
				} else {
					distance = (noiseradius * 100 * g_ChrSlots[i].hearingscale * (1.0f + add)) / distance;
				}

				if (distance > 1.0f) {
					chr_record_last_hear_target_time(&g_ChrSlots[i]);
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

struct chrdata *chr_find_by_literal_id(s32 chrnum)
{
	s32 lower = 0;
	s32 upper = g_NumChrs;
	s32 i;

	while (upper >= lower) {
		i = (lower + upper) / 2;

		if (chrnum == g_Chrnums[i]) {
			return &g_ChrSlots[g_ChrIndexes[i]];
		}

		if (chrnum < g_Chrnums[i]) {
			upper = i - 1;
		} else {
			lower = i + 1;
		}
	}

	return NULL;
}

struct prop *chr_get_held_prop(struct chrdata *chr, s32 hand)
{
	return chr->weapons_held[hand];
}

struct prop *chr_get_held_usable_prop(struct chrdata *chr, s32 hand)
{
	struct prop *prop = chr->weapons_held[hand];

	if (prop) {
		struct weaponobj *weapon = prop->weapon;

		if (!weapon_has_flag(weapon->weaponnum, WEAPONFLAG_AICANUSE)) {
			prop = NULL;
		}
	}

	return prop;
}

struct prop *chr_get_target_prop(struct chrdata *chr)
{
	struct prop *ret;

	if (chr->target == -1) {
		ret = g_Vars.players[chr->p1p2]->prop;
	} else {
		ret = g_Vars.props + chr->target;
	}

	return ret;
}

bool chr_get_geometry(struct prop *prop, u8 **start, u8 **end)
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

void chr_get_bbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin)
{
	struct chrdata *chr = prop->chr;

	*radius = chr->radius;
	*ymax = chr->manground + chr->height;
	*ymin = chr->manground + 20;

	if (chr->actiontype == ACT_SKJUMP && chr->act_skjump.ground < chr->manground) {
		*ymin = chr->act_skjump.ground + 20;
	}
}

f32 chr_get_ground(struct prop *prop)
{
	struct chrdata *chr = prop->chr;
	return chr->ground;
}

bool chr_calculate_autoaim(struct prop *prop, struct coord *screenpos, f32 *xrange, f32 *yrange)
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
			&& !(prop->type == PROPTYPE_PLAYER && g_Vars.players[playermgr_get_player_num_by_prop(prop)]->isdead)
			&& !(g_Vars.coopplayernum >= 0 && (prop == g_Vars.bond->prop || prop == g_Vars.coop->prop))) {
		struct model *model = chr->model;
		Mtxf *mtx1;
		Mtxf *mtx2;

		if (model->definition->skel == &g_SkelChr) {
			mtx1 = &model->matrices[0];
			mtx2 = &model->matrices[1];
			screenpos->z = mtx2->m[3][2] + (mtx1->m[3][2] - mtx2->m[3][2]) * 0.5f;
		} else if (model->definition->skel == &g_SkelSkedar) {
			mtx2 = &model->matrices[0];
			screenpos->z = mtx2->m[3][2];
		} else if (model->definition->skel == &g_SkelDrCaroll) {
			mtx2 = &model->matrices[0];
			screenpos->z = mtx2->m[3][2];
		} else {
			screenpos->z = model->matrices[0].m[3][2];
		}

		if (screenpos->z < 0) {
			if (model->definition->skel == &g_SkelChr) {
				screenpos->x = mtx2->m[3][0] + (mtx1->m[3][0] - mtx2->m[3][0]) * 0.5f;
				screenpos->y = mtx2->m[3][1] + (mtx1->m[3][1] - mtx2->m[3][1]) * 0.5f;
			} else if (model->definition->skel == &g_SkelSkedar) {
				screenpos->x = mtx2->m[3][0];
				screenpos->y = mtx2->m[3][1];
			} else if (model->definition->skel == &g_SkelDrCaroll) {
				screenpos->x = mtx2->m[3][0];
				screenpos->y = mtx2->m[3][1];
			} else {
				screenpos->x = model->matrices[0].m[3][0];
				screenpos->y = model->matrices[0].m[3][1];
			}

			yrange[0] = yrange[1] = 0;
			xrange[0] = xrange[1] = 0;

			model_get_screen_coords3(model, &xrange[1], &xrange[0], &yrange[1], &yrange[0]);

			return true;
		}
	}

	return false;
}

/**
 * Iterate the iterprop, its children and siblings to find wantprop.
 * Sum the number of matrix slots in the model data of each model that has been iterated.
 *
 * This function is recursive, where each recursion is for an attached child
 * or sibling.
 *
 * @bug: The matrices are counted from the same model definition
 * regardless of what model the children have.
 */
bool shieldhit_find_cmnum_for_prop(struct prop *iterprop, struct prop *wantprop, struct modelnode *node, struct model *model, s32 *total)
{
	if (wantprop == iterprop) {
		*total += model_find_node_mtx_index(node, 0);
		return true;
	}

	*total += model->definition->nummatrices;

	if (iterprop->child && shieldhit_find_cmnum_for_prop(iterprop->child, wantprop, node, model, total) > 0) {
		return true;
	}

	if (iterprop->next && shieldhit_find_cmnum_for_prop(iterprop->next, wantprop, node, model, total) > 0) {
		return true;
	}

	return false;
}

/**
 * Given a model node, find the associated cmnum.
 *
 * The node may be on the root prop (chr or obj). It may also be a node on an
 * attached prop such as a knife or mine.
 */
s32 shieldhit_node_to_cmnum(struct prop *wantprop, struct modelnode *node, struct model *model, struct prop *rootprop)
{
	s32 cmnum = 0;

	if (shieldhit_find_cmnum_for_prop(rootprop, wantprop, node, model, &cmnum)) {
		return cmnum;
	}

	return -1;
}

/**
 * Convert a cmnum to a prop, model and node.
 *
 * For example, a chr might have 14 matrices, and they might have a mine
 * attached to them which has one matrix. cmnums 0-13 will refer to matrices in
 * the chr's model, while cmnum 14 will be the mine.
 *
 * Return true if the cmnum was valid and values were written to the pointers.
 */
bool shieldhit_cmnum_to_node(s32 cmnum, struct prop *prop, struct prop **propptr, struct modelnode **nodeptr, struct model **modelptr)
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

		if (cmnum >= model->definition->nummatrices) {
			cmnum -= model->definition->nummatrices;

			if (prop->child) {
				result = shieldhit_cmnum_to_node(cmnum, prop->child, propptr, nodeptr, modelptr);
			}

			if (prop->next && !result) {
				prop = prop->next;
				continue;
			}
		} else {
			*propptr = prop;
			*nodeptr = model_find_node_by_mtx_index(model, cmnum);
			*modelptr = model;
			result = true;
		}

		return result;
	}
}

void shieldhit_create(struct prop *rootprop, f32 shield, struct prop *hitprop, struct modelnode *node, struct model *model, s32 side, s16 *hitpos)
{
	struct shieldhit *shieldhit = NULL;
	s32 i;
	s32 j;

	// Find any slot that isn't in use (ie. prop is NULL)
	for (i = 0; i < MAX_SHIELDHITS; i++) {
		if (g_ShieldHits[i].prop == NULL) {
			shieldhit = &g_ShieldHits[i];
			break;
		}
	}

	// If all slots are in use, take the oldest one
	if (shieldhit == NULL) {
		struct shieldhit *oldesthit = NULL;
		s32 oldestframe = g_Vars.lvframe60;

		for (i = 0; i < MAX_SHIELDHITS; i++) {
			if (g_ShieldHits[i].lvframe60 < oldestframe) {
				oldesthit = &g_ShieldHits[i];
				oldestframe = g_ShieldHits[i].lvframe60;
			}
		}

		shieldhit = oldesthit;
	}

	if (shieldhit) {
		shieldhit->prop = rootprop;
		shieldhit->node = node;
		shieldhit->model = model;
		shieldhit->side = side;
		shieldhit->lvframe60 = g_Vars.lvframe60;

		for (i = 0; i < 32; i++) {
			shieldhit->unk018[i] = -1;
		}

		shieldhit->unk011 = 2 + (random() % 6);
		shieldhit->shield = shield;

		if (hitpos) {
			shieldhit->hitposx = hitpos[0];
			shieldhit->hitposy = hitpos[1];
			shieldhit->hitposz = hitpos[2];
		} else {
			shieldhit->hitposx = 0x7fff;
		}

		if (node) {
			bool pass = true;

			for (i = 0; i < MAX_SHIELDHITS; i++) {
				if (g_ShieldHits[i].prop == rootprop) {
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
				s32 index = shieldhit_node_to_cmnum(hitprop, node, model, rootprop);

				if (index < 32) {
					shieldhit->unk018[index] = 0;
					shieldhit->unk038[index] = 0;
				}
			}
		}

		if (rootprop->type == PROPTYPE_CHR || rootprop->type == PROPTYPE_PLAYER) {
			rootprop->chr->hidden2 |= CHRH2FLAG_SHIELDHIT;
		} else if (rootprop->type == PROPTYPE_OBJ || rootprop->type == PROPTYPE_WEAPON || rootprop->type == PROPTYPE_DOOR) {
			rootprop->obj->flags3 |= OBJFLAG3_SHIELDHIT;
		}
	}

	g_ShieldHitActive = true;
}

void shieldhit_remove(struct shieldhit *shieldhit)
{
	s32 exists = false;
	s32 i;
	struct prop *prop = shieldhit->prop;
	shieldhit->prop = NULL;

	// Check if there are other shield hits active
	g_ShieldHitActive = false;

	for (i = 0; i < MAX_SHIELDHITS; i++) {
		if (g_ShieldHits[i].prop) {
			g_ShieldHitActive = true;
			break;
		}
	}

	// Check if the prop being removed has other shield hits too
	for (i = 0; i < MAX_SHIELDHITS; i++) {
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

void shieldhits_remove_by_prop(struct prop *prop)
{
	s32 i;

	for (i = 0; i < MAX_SHIELDHITS; i++) {
		if (prop == g_ShieldHits[i].prop) {
			shieldhit_remove(&g_ShieldHits[i]);
		}
	}
}

s32 shieldhit_find_parentnode_cmnum(struct prop *prop, s32 prevcmnum)
{
	s32 cmnum = -1;
	struct modelnode *node2;
	struct prop *prop2;
	struct modelnode *node;
	struct model *model;

	if (shieldhit_cmnum_to_node(prevcmnum, prop, &prop2, &node, &model) && node) {
		node2 = model_node_find_parent_mtx_node(node);

		if (node2) {
			cmnum = shieldhit_node_to_cmnum(prop2, node2, model, prop);
		} else if (prop2->parent && model->attachedtomodel && model->attachedtonode) {
			cmnum = shieldhit_node_to_cmnum(prop2->parent, model->attachedtonode, model->attachedtomodel, prop);
		}
	}

	return cmnum;
}

s32 shieldhit_find_childnode_cmnum(struct prop *prop, s32 prevcmnum)
{
	s32 cmnum = -1;
	struct modelnode *node2;
	struct prop *prop2;
	struct modelnode *node;
	struct model *model;

	if (shieldhit_cmnum_to_node(prevcmnum, prop, &prop2, &node, &model) && node) {
		node2 = model_node_find_child_mtx_node(node);

		if (node2) {
			cmnum = shieldhit_node_to_cmnum(prop2, node2, model, prop);
		} else {
			struct prop *child = prop2->child;

			while (child) {
				struct model *parentmodel = child->parentmodel;

				if (model == parentmodel->attachedtomodel) {
					if (node == parentmodel->attachedtonode) {
						cmnum = shieldhit_node_to_cmnum(child, parentmodel->definition->rootnode, parentmodel, prop);
						break;
					}
				}

				child = child->next;
			}
		}
	}

	return cmnum;
}

s32 shieldhit_find_anynode_cmnum(struct prop *prop, s32 prevcmnum)
{
	s32 cmnum = -1;
	struct prop *child;
	struct prop *prop2;
	struct modelnode *node2;
	struct model *model2;

	if (shieldhit_cmnum_to_node(prevcmnum, prop, &prop2, &node2, &model2) && node2) {
		struct modelnode *node3 = model_node_find_child_or_parent_mtx_node(node2);

		if (node3) {
			cmnum = shieldhit_node_to_cmnum(prop2, node3, model2, prop);
		} else if (model_node_find_parent_mtx_node(node2) == NULL && prop2->parent) {
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
							cmnum = shieldhit_node_to_cmnum(child, parent->definition->rootnode, parent, prop);
							break;
						}
					}

					child = child->next;
				}
			}
		}
	}

	return cmnum;
}

void shieldhit_health_to_rgb(f32 health, s32 *r, s32 *g, s32 *b)
{
	if (health < 1.5f) {
		*r = 57 - (s32) ((1.5f - health) * 28);
		*g = 75 - (s32) ((1.5f - health) * 20);
		*b = 0;
	} else if (health < 3.0f) {
		*r = 102 - (s32) ((3.0f - health) * 30);
		*g = 90 - (s32) ((3.0f - health) * 10);
		*b = 0;
	} else if (health < 4.5f) {
		*r = 174 - (s32) ((4.5f - health) * 48);
		*g = 129 - (s32) ((4.5f - health) * 26);
		*b = 0;
	} else if (health < 6.0f) {
		*r = 162 - (s32) ((6.0f - health) * -8);
		*g = 54 - (s32) ((6.0f - health) * -50);
		*b = 0;
	} else {
		*r = 162;
		*g = 54;
		*b = 0;
	}
}

f32 shieldhit_get_health(struct prop **propptr)
{
	struct prop *prop = *propptr;

	if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
		return chr_get_shield(prop->chr);
	}

	if (prop->type == PROPTYPE_OBJ
			|| prop->type == PROPTYPE_WEAPON
			|| prop->type == PROPTYPE_DOOR) {
		if (prop->obj->flags3 & OBJFLAG3_SHOWSHIELD) {
			return 4;
		}

		// Objects don't have shields with health,
		// hence why the max health is returned here.
		return 8;
	}

	return 0;
}

bool g_ShieldHitActive = false;

Gfx *shieldhit_render_component(Gfx *gdl, struct shieldhit *hit, struct prop *prop, struct model *model,
		struct modelnode *node, s32 side, s32 arg6, s32 arg7, s32 alpha)
{
	struct modelrodata_bbox *bbox = &node->rodata->bbox;
	Vtx vtxtemplate = {0};
	Vtx *vertices;
	Col *colours;
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
		shieldamount = chr_get_shield(chr);
		cloakfade = chr->cloakfadefrac;
		cmcount = chr->cmcount;
	} else {
		struct defaultobj *obj = prop->obj;
		gap = 0.0f;
		cloakfade = 64;
		cmcount = 0;
		shieldamount = (obj->flags3 & OBJFLAG3_SHOWSHIELD) ? 4.0f : 8.0f;
	}

	mtxindex = model_find_node_mtx_index(node, 0);
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
		colours = gfx_allocate_colours(1);

		gSPColor(gdl++, osVirtualToPhysical(colours), 1);

		colours[0].r = 0xff;
		colours[0].g = 0xff;
		colours[0].b = 0xff;

		if (cloakfade < 64) {
			colours[0].a = (s32) (cloakfade * (f32) alpha * (1.0f / 85.0f));
		} else {
			colours[0].a = (s32) ((127 - cloakfade) * (f32) alpha * (1.0f / 85.0f));
		}

		vertices = gfx_allocate_vertices(24);

		for (i = 0; i < ARRAYCOUNT(sp104); i++) {
			for (j = 0; j < ARRAYCOUNT(sp104[i]); j++) {
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

			gSPVertex(gdl++, osVirtualToPhysical(vertices), 4, 0);

			gSPTri2(gdl++, 0, 1, 2, 0, 2, 3);

			vertices += 4;
		}
	} else {
		f32 shield;

		tex_select(&gdl, &g_TexShieldConfigs[0], 4, 1, 2, true, NULL);

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

		shieldhit_health_to_rgb(shield, &red1, &green1, &blue1);

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
			colours = gfx_allocate_colours(1);

			gSPColor(gdl++, osVirtualToPhysical(colours), 1);

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

			vertices = gfx_allocate_vertices(24);

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

			for (i = 0; i < ARRAYCOUNT(sp104); i++) {
				for (j = 0; j < ARRAYCOUNT(sp104[i]); j++) {
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

				gSPVertex(gdl++, osVirtualToPhysical(vertices), 4, 0);

				gSPTri2(gdl++, 0, 1, 2, 0, 2, 3);

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

			colours = gfx_allocate_colours(3);

			gSPColor(gdl++, osVirtualToPhysical(colours), 3);

			colours[0].r = red3;
			colours[1].r = red3;
			colours[0].g = green3;
			colours[1].g = green3;
			colours[0].b = blue3;
			colours[1].b = blue3;
			colours[0].a = (s32) alpha3;
			colours[1].a = 0;

			vertices = gfx_allocate_vertices(30);

			for (i = 0; i < ARRAYCOUNT(sp104); i++) {
				for (j = 0; j < ARRAYCOUNT(sp104[i]); j++) {
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

				gSPVertex(gdl++, osVirtualToPhysical(vertices), 5, 0);

				gSPTri4(gdl++, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4);

				vertices += 5;
			}
		} else if (side < 0) {
			vertices = gfx_allocate_vertices(12);

			if (side == -1) {
				if (g_Vars.lvframe60 - hit->lvframe60 <= TICKS(80)) {
					f32 tmp = (hit->lvframe60 - g_Vars.lvframe60 + TICKS(80)) * (PAL ? 3.8636362552643f : 3.1875f);
					tmp *= alpha * (1.0f / 255.0f);

					alpha1 = (s32) tmp;
				} else {
					alpha1 = 0;
				}

				colours = gfx_allocate_colours(1);

				gSPColor(gdl++, osVirtualToPhysical(colours), 1);

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

				colours = gfx_allocate_colours(1);

				gSPColor(gdl++, osVirtualToPhysical(colours), 1);

				colours[0].r = red3;
				colours[0].g = green3;
				colours[0].b = blue3;
				colours[0].a = (s32) alpha4;
			}

			for (j = 0; j < ARRAYCOUNT(sp180); j++) {
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

			gSPVertex(gdl++, osVirtualToPhysical(vertices), 12, 0);

			gSPTri4(gdl++, 0, 1, 9, 0, 9, 8, 11, 5, 4, 11, 4, 10);

			for (j = 2; j < 6; j++) {
				gSPTri2(gdl++,
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

			colours = gfx_allocate_colours(5);

			gSPColor(gdl++, osVirtualToPhysical(colours), 5);

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

			vertices = gfx_allocate_vertices(30);

			for (j = 0; j < ARRAYCOUNT(sp104[side]); j++) {
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

			if (hit->hitposx == 0x7fff) {
				vertices[4].x = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) >> 2;
				vertices[4].y = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) >> 2;
				vertices[4].z = (vertices[0].z + vertices[1].z + vertices[2].z + vertices[3].z) >> 2;
			} else {
				vertices[4].x = hit->hitposx;
				vertices[4].y = hit->hitposy;
				vertices[4].z = hit->hitposz;
			}

			vertices[4].colour = 0xc;
			vertices[4].s = (st1 + st3) >> 1;
			vertices[4].t = (st2 + st4) >> 1;

			gSPVertex(gdl++, osVirtualToPhysical(vertices), 5, 0);

			gSPTri4(gdl++, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4);

			vertices += 5;

			for (j = 0; j < ARRAYCOUNT(sp104[side]); j++) {
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

				gSPVertex(gdl++, osVirtualToPhysical(vertices), 5, 0);

				gSPTri4(gdl++, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4);

				vertices += 5;
			}

			for (j = 0; j < ARRAYCOUNT(sp104[side]); j++) {
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

			gSPVertex(gdl++, osVirtualToPhysical(vertices), 5, 0);

			gSPTri4(gdl++, 0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4);
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
Gfx *shieldhit_render(Gfx *gdl, struct prop *prop1, struct prop *prop2, s32 alpha,
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
			specificnode = model_get_part(model->definition, MODELPART_BASIC_SHIELD);
		}

		node = model->definition->rootnode;

		while (node) {
			if ((node->type & 0xff) == MODELNODETYPE_BBOX) {
				if (specificnode == NULL || specificnode == node) {
					struct shieldhit *s0 = NULL;
					struct shieldhit *s1 = NULL;
					struct shieldhit *s2 = NULL;
					s32 index = shieldhit_node_to_cmnum(prop2, node, model, prop1);
					s32 i;

					for (i = 0; i < MAX_SHIELDHITS; i++) {
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
						gdl = shieldhit_render_component(gdl, s0, prop1, s0->model, s0->node, s0->side, -1, -1, 255);
					} else if (s1) {
						gdl = shieldhit_render_component(gdl, s1, prop1, model, node, -1, -1, -1, 255);
					} else if (s2) {
						gdl = shieldhit_render_component(gdl, s2, prop1, model, node, -2, s2->unk018[index], s2->unk038[index], 255);
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

							gdl = shieldhit_render_component(gdl, NULL, prop1, model, node, -7, -1, -1, 255);
						} else {
							if (index == cmnum1) {
								gdl = shieldhit_render_component(gdl, NULL, prop1, model, node, -3, -1, -1, alpha);
							} else if (index == cmnum2) {
								gdl = shieldhit_render_component(gdl, NULL, prop1, model, node, -4, -1, -1, alpha);
							} else if (index == cmnum3) {
								gdl = shieldhit_render_component(gdl, NULL, prop1, model, node, -5, -1, -1, alpha);
							} else if (index == cmnum4) {
								gdl = shieldhit_render_component(gdl, NULL, prop1, model, node, -6, -1, -1, alpha);
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
				gdl = shieldhit_render(gdl, prop1, child, alpha, arg4, cmnum1, cmnum2, cmnum3, cmnum4);
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
Gfx *chr_render_cloak(Gfx *gdl, struct prop *chrprop, struct prop *thisprop)
{
	struct model *model;
	struct modelnode *bbox = NULL;
	struct modelnode *node;

	if (thisprop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		if (thisprop->type == PROPTYPE_CHR || thisprop->type == PROPTYPE_PLAYER) {
			model = thisprop->chr->model;
		} else {
			model = thisprop->obj->model;
			bbox = model_get_part(model->definition, MODELPART_BASIC_SHIELD);
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
		node = model->definition->rootnode;

		while (node) {
			if ((node->type & 0xff) == MODELNODETYPE_BBOX) {
				if (bbox == NULL || node == bbox) {
					s32 index = shieldhit_node_to_cmnum(thisprop, node, model, chrprop);

					if (bbox) {
						index = 19;
					}

					if (index <= 19) {
						Mtxf *mtx = model_find_node_mtx(model, model_node_find_mtx_node(node), 0);
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

						if (screenpos[0] > vi_get_width()) {
							screenpos[0] = vi_get_width();
						}

						if (screenpos[1] < 0.0f) {
							screenpos[1] = 0.0f;
						}

						if (screenpos[1] > vi_get_height()) {
							screenpos[1] = vi_get_height();
						}

						uls = (s32)screenpos[0] - 8;
						ult = (s32)screenpos[1] - 8;

						if (uls < vi_get_view_left()) {
							uls = vi_get_view_left();
						}

						if (uls > vi_get_view_left() + vi_get_view_width() - 16) {
							uls = vi_get_view_left() + vi_get_view_width() - 16;
						}

						if (ult < vi_get_view_top()) {
							ult = vi_get_view_top();
						}

						if (ult > vi_get_view_top() + vi_get_view_height() - 16) {
							ult = vi_get_view_top() + vi_get_view_height() - 16;
						}

						lrs = uls + 15;
						lrt = ult + 15;

						gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, OS_K0_TO_PHYSICAL(var8009ccc0[index]));
						gDPTileSync(gdl++);

						gDPLoadTextureTile(gdl++, vi_get_back_buffer(), G_IM_FMT_RGBA, G_IM_SIZ_16b,
								vi_get_width(), 0, uls, ult, lrs, lrt,
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
				gdl = chr_render_cloak(gdl, chrprop, child);
			}
		}

		if (thisprop->parent == NULL) {
			// Back in the chr prop - reconfigure the renderer for normal use
			gDPPipeSync(gdl++);
			gDPLoadSync(gdl++);
			gDPTileSync(gdl++);
			gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, vi_get_buf_width(), OS_K0_TO_PHYSICAL(vi_get_back_buffer()));
			gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, vi_get_width(), vi_get_height());
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

Gfx *chr_render_shield(Gfx *gdl, struct chrdata *chr, u32 alpha)
{
	if (chr_get_shield(chr) > 0 && g_Vars.lvupdate240 > 0) {
		chr->cmcount++;

		if (chr->cmcount > 300) {
			chr->cmcount = 0;
		}
	}

	if ((chr->hidden2 & CHRH2FLAG_SHIELDHIT)
			|| (chr_get_shield(chr) > 0 && chr->cmcount < 10)
			|| (chr->cloakfadefrac > 0 && !chr->cloakfadefinished)) {
		if (chr_get_shield(chr) > 0 && g_Vars.lvupdate240 > 0) {
			s32 numiterations = (random() % 4) + 1;
			s32 newcmnum = chr->cmnum2;
			s32 candidate;
			s8 operation = 0;
			s8 again = true;
			s32 i;

			for (i = 0; i <= numiterations; ) {
				if (operation == 0) {
					candidate = shieldhit_find_parentnode_cmnum(chr->prop, chr->cmnum);
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
					candidate = shieldhit_find_childnode_cmnum(chr->prop, chr->cmnum);

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
					candidate = shieldhit_find_anynode_cmnum(chr->prop, candidate);

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

		gdl = shieldhit_render(gdl, chr->prop, chr->prop, alpha,
				chr->cloakfadefrac > 0 && !chr->cloakfadefinished,
				chr->cmnum, chr->cmnum2, chr->cmnum3, chr->cmnum4);

		gSPSetGeometryMode(gdl++, G_CULL_BACK);
	}

	return gdl;
}

/**
 * This ticks the shield damage effect when you shoot a shielded chr.
 */
void shieldhits_tick(void)
{
	s32 index;
	bool changed = false;
	s32 time60;
	s32 i;
	s32 j;

	if (g_ShieldHitActive) {
		for (i = 0; i < MAX_SHIELDHITS; i++) {
			if (g_ShieldHits[i].prop) {
				if (g_ShieldHits[i].lvframe60 >= g_Vars.lvframe60 - TICKS(80)) {
					changed = true;
					g_ShieldHits[i].shield += (shieldhit_get_health(&g_ShieldHits[i].prop) - g_ShieldHits[i].shield) * g_Vars.lvupdate60f * (PAL ? 0.0151515156f : 0.0125f);
				}

				for (j = 0; j < 32; j++) {
					if (g_ShieldHits[i].unk018[j] >= 0) {
						changed = true;
						time60 = g_ShieldHits[i].unk018[j] + g_Vars.lvupdate60;

						if (g_ShieldHits[i].unk018[j] < 1 && time60 > 0) {
							index = shieldhit_find_parentnode_cmnum(g_ShieldHits[i].prop, j);

							if (index >= 0 && index < 32) {
								if (g_ShieldHits[i].unk018[index] == -1) {
									g_ShieldHits[i].unk018[index] = -3;
									g_ShieldHits[i].unk038[index] = g_ShieldHits[i].unk038[j] + 1;
								}
							}

							index = shieldhit_find_childnode_cmnum(g_ShieldHits[i].prop, j);

							while (index >= 0) {
								if (index < 32) {
									if (g_ShieldHits[i].unk018[index] == -1) {
										g_ShieldHits[i].unk018[index] = -3;
										g_ShieldHits[i].unk038[index] = g_ShieldHits[i].unk038[j] + 1;
									}
								}

								index = shieldhit_find_anynode_cmnum(g_ShieldHits[i].prop, index);
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
					shieldhit_remove(&g_ShieldHits[i]);
				}
			}
		}
	}
}

void chr_set_drcaroll_images(struct chrdata *drcaroll, s32 imageleft, s32 imageright)
{
	if (drcaroll
			&& imageleft >= DRCAROLLIMAGE_EYESDEFAULT && imageleft <= DRCAROLLIMAGE_BINARY
			&& imageright >= DRCAROLLIMAGE_EYESDEFAULT && imageright <= DRCAROLLIMAGE_BINARY) {
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
			nodes[0] = model_get_part(model->definition, i);
			nodes[1] = model_get_part(model->definition, i + 6);

			for (j = 0; j < ARRAYCOUNT(nodes); j++) {
				if (nodes[j]) {
					rwdata = model_get_node_rw_data(model, nodes[j]);

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
