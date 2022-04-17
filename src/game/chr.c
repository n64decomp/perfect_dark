#include <ultra64.h>
#include "lib/sched.h"
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/objectives.h"
#include "game/game_096360.h"
#include "game/bondgun.h"
#include "game/gunfx.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b28d0.h"
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
#include "types.h"

void *var8009ccc0[20];
s32 g_NumChrs;
s16 *g_Chrnums;
s16 *g_ChrIndexes;
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
s32 g_NextChrnum = 5000;

// 80062988
struct chrdata *g_ChrSlots = NULL;

// 8006298c
s32 g_NumChrSlots = 0;

void propsTick(void)
{
	s32 i;
	struct prop *prop;
	struct prop *next;
	struct prop *next2;
	s32 done;
	s32 tickop;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->bondextrapos.x = 0;
		g_Vars.players[i]->bondextrapos.y = 0;
		g_Vars.players[i]->bondextrapos.z = 0;
	}

	shieldhitsTick();
	func0f048398();

	prop = g_Vars.activeprops;

	do {
		next = prop->next;
		done = next == g_Vars.pausedprops;
		tickop = TICKOP_NONE;

		if (prop->type == PROPTYPE_CHR) {
			tickop = chrTickBeams(prop);
		} else if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
			tickop = objTick(prop);
		} else if (prop->type == PROPTYPE_EXPLOSION) {
			tickop = explosionTick(prop);
		} else if (prop->type == PROPTYPE_SMOKE) {
			tickop = smokeTick(prop);
		} else if (prop->type == PROPTYPE_PLAYER) {
			tickop = playerTickBeams(prop);
		}

		if (tickop == TICKOP_5) {
			next2 = next;
		} else {
			next2 = prop->next;
			done = next2 == g_Vars.pausedprops;

			if (tickop == TICKOP_RETICK) {
				propDelist(prop);
				propActivateThisFrame(prop);

				if (done) {
					next2 = prop;
					done = false;
				}
			} else {
				propExecuteTickOperation(prop, tickop);
			}
		}

		prop = next2;
	} while (!done);
}

s32 chrsGetNumSlots(void)
{
	return g_NumChrSlots;
}

void chrSetChrnum(struct chrdata *chr, s16 chrnum)
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

void chrRegister(s32 chrnum, s32 chrindex)
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

void chrDeregister(s32 chrnum)
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
	f32 width;
	bool moveok = false;
	f32 movex;
	f32 movez;
	struct prop *prop = chr->prop;
	u32 stack;
	f32 halfwidth;
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

	chrGetBbox(prop, &width, &ymax, &ymin);
	halfwidth = width * 0.5f;
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

	if (movex > halfwidth || movez > halfwidth || movex < -halfwidth || movez < -halfwidth) {
		cdresult = cd0002d8b8(&prop->pos, prop->rooms, dstpos, dstrooms, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);

		if (cdresult == CDRESULT_NOCOLLISION) {
			cdresult = cd0002a6fc(&prop->pos, dstpos, width, dstrooms, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);
		}
	} else {
		cdresult = cd0002a6fc(&prop->pos, dstpos, width, sp84, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);
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
			cd00024e4c(&sp78, &sp6c, 453, "chr/chr.c");
#elif VERSION >= VERSION_PAL_BETA
			cd00024e4c(&sp78, &sp6c, 453, "chr.c");
#elif VERSION >= VERSION_NTSC_1_0
			cd00024e4c(&sp78, &sp6c, 453, "chr/chr.c");
#else
			cd00024e4c(&sp78, &sp6c, 451, "chr.c");
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

				if (movex > halfwidth || movez > halfwidth || movex < -halfwidth || movez < -halfwidth) {
					cdresult = cdTestAToB2(&prop->pos, prop->rooms, &sp44, dstrooms, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);

					if (cdresult == CDRESULT_NOCOLLISION) {
						cdresult = cdTestVolume(&sp44, width, dstrooms, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);
					}
				} else {
					cdresult = cdTestVolume(&sp44, width, sp84, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);
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

				if (sp54.f[0] * sp54.f[0] + sp54.f[2] * sp54.f[2] <= width * width) {
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

						if (movex > halfwidth || movez > halfwidth || movex < -halfwidth || movez < -halfwidth) {
							cdresult = cdTestAToB2(&prop->pos, prop->rooms, &sp44, dstrooms, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);

							if (cdresult == CDRESULT_NOCOLLISION) {
								cdresult = cdTestVolume(&sp44, width, dstrooms, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);
							}
						} else {
							cdresult = cdTestVolume(&sp44, width, sp84, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);
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

					if (sp54.f[0] * sp54.f[0] + sp54.f[2] * sp54.f[2] <= width * width) {
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

							if (movex > halfwidth || movez > halfwidth || movex < -halfwidth || movez < -halfwidth) {
								cdresult = cdTestAToB2(&prop->pos, prop->rooms, &sp44, dstrooms, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);

								if (cdresult == CDRESULT_NOCOLLISION) {
									cdresult = cdTestVolume(&sp44, width, dstrooms, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);
								}
							} else {
								cdresult = cdTestVolume(&sp44, width, sp84, CDTYPE_ALL, 1, ymax - prop->pos.y, ymin - prop->pos.y);
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
	f32 width;

	newpos.x = pos->x;
	newpos.y = pos->y + arg3;
	newpos.z = pos->z;

	chrGetBbox(chr->prop, &width, &ymax, &ymin);
	func0f065e74(pos, rooms, &newpos, newrooms);
	chr0f021fa8(chr, &newpos, newrooms);
	chrSetPerimEnabled(chr, false);
	result = cdTestVolume(&newpos, width, newrooms, CDTYPE_ALL, 1,
			ymax - chr->prop->pos.y,
			ymin - chr->prop->pos.y);
	chrSetPerimEnabled(chr, true);

#if VERSION >= VERSION_NTSC_1_0
	if (result == true && arg4) {
		pos->y = newpos.y;
		roomsCopy(newrooms, rooms);
	}
#endif

	return result == true;
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
	f32 lvupdate240f;
	f32 lvupdate240freal;
	struct coord spd0;
	s16 spc0[8];
#endif

	// NTSC beta reads g_Vars lvupdate properties throughout this function,
	// while NTSC 1.0 and newer copy them into stack variables at the start.
	// A macro is used here for readability
#if VERSION >= VERSION_NTSC_1_0
	lvupdate240 = g_Vars.lvupdate240;
	lvupdate240f = g_Vars.lvupdate240f;
	lvupdate240freal = g_Vars.lvupdate240freal;

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

		ground = cdFindGroundY(arg2, chr->chrwidth, spfc, &chr->floorcol, &chr->floortype, &floorflags, &chr->floorroom, &inlift, &lift);

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
							lvupdate240f = 4.0f;
							lvupdate240freal = PALUPF(4.0f);
							lvupdate240 = 16;
						}
					}
				} else if (chr->onladder
						&& ((chr->prop->flags & (PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) == 0)
						&& lvupdate240 >= 25) {
					lvupdate240f = 4.0f;
					lvupdate240freal = PALUPF(4.0f);
					lvupdate240 = 16;
				}

				bot0f1921f8(chr, move, lvupdate240, lvupdate240freal);
#else
				bot0f1921f8(chr, move);
#endif
			}

			arg2->x = arg1->x + move[0];
			arg2->z = arg1->z + move[1];
		}

		if (chr->actiontype == ACT_PATROL || chr->actiontype == ACT_GOPOS) {
			chr->onladder = cd00029ffc(&chr->prop->pos, chr->chrwidth * 2.5f,
					chr->manground + chr->chrheight - chr->prop->pos.y,
					chr->manground + 1.0f - chr->prop->pos.y,
					chr->prop->rooms, 0x40, &chr->laddernormal);
		} else {
			chr->onladder = false;
		}

		if (chr->aibot != NULL) {
			chr->chrheight = 185.0f;

			if (chr->actiontype == ACT_GOPOS && (chr->act_gopos.flags & GOPOSFLAG_WALKDIRECT)) {
				chr->chrheight = 135.0f;
			} else if (chr->actiontype == ACT_GOPOS && (chr->act_gopos.flags & GOPOSFLAG_DUCK)) {
				chr->chrheight = 90.0f;
			} else if (cd0002a13c(&chr->prop->pos, chr->chrwidth * 1.1f,
						chr->manground + 185.0f - chr->prop->pos.y,
						chr->manground - 10.0f - chr->prop->pos.y,
						chr->prop->rooms, 0x1000) != CDRESULT_COLLISION) {
				chr->chrheight = 135.0f;
			} else if (cd0002a13c(&chr->prop->pos, chr->chrwidth * 1.1f,
						chr->manground + 135.0f - chr->prop->pos.y,
						chr->manground - 10.0f - chr->prop->pos.y,
						chr->prop->rooms, 0x800) != CDRESULT_COLLISION) {
				chr->chrheight = 90.0f;
			}

			bmove0f0cb904(&chr->aibot->shotspeed);

			arg2->x += chr->aibot->shotspeed.x * var80075c00[1].unk0c * VAR(lvupdate240freal) * 0.5f;
			arg2->z += chr->aibot->shotspeed.z * var80075c00[1].unk0c * VAR(lvupdate240freal) * 0.5f;
		}

		if (chr->actiontype == ACT_DIE && chr->act_die.timeextra > 0.0f) {
			f32 speed = model->anim->playspeed * VAR(lvupdate240f) * (chr->act_die.timeextra - chr->act_die.elapseextra) / chr->act_die.timeextra;

			arg2->x += chr->act_die.extraspeed.x * speed;
			arg2->z += chr->act_die.extraspeed.z * speed;

			yincrement += chr->act_die.extraspeed.y * speed;

			chr->act_die.elapseextra += VAR(lvupdate240f) * model->anim->playspeed;

			if (chr->act_die.elapseextra > chr->act_die.timeextra) {
				chr->act_die.timeextra = 0.0f;
			}
		} else if (chr->timeextra > 0.0f) {
			f32 speed = model->anim->playspeed * VAR(lvupdate240f) * (chr->timeextra - chr->elapseextra) / chr->timeextra;

			arg2->x += chr->extraspeed.x * speed;
			arg2->z += chr->extraspeed.z * speed;

			yincrement += chr->extraspeed.y * speed;

			chr->elapseextra += VAR(lvupdate240f) * model->anim->playspeed;

			if (chr->elapseextra > chr->timeextra) {
				chr->timeextra = 0.0f;
			}
		}

		if (chr->pushspeed[0] != 0.0f || chr->pushspeed[1] != 0.0f) {
			arg2->x += chr->pushspeed[0] * VAR(lvupdate240freal);
			arg2->z += chr->pushspeed[1] * VAR(lvupdate240freal);

			chr->pushspeed[0] *= 0.9f;
			chr->pushspeed[1] *= 0.9f;

			if (chr->pushspeed[0] != 0.0f || chr->pushspeed[1] != 0.0f) {
				f32 pushdist = sqrtf(chr->pushspeed[0] * chr->pushspeed[0] + chr->pushspeed[1] * chr->pushspeed[1]);

				if (pushdist > 0.0f) {
					pushdist = 0.1f * VAR(lvupdate240freal) / pushdist;

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

		arg2->x += chr->fallspeed.x * VAR(lvupdate240freal);
		arg2->z += chr->fallspeed.z * VAR(lvupdate240freal);

		if (race == RACE_EYESPY) {
			struct eyespy *eyespy = chrToEyespy(chr);

			if (eyespy && eyespy->deployed) {
				arg2->x = chr->prop->pos.x;
				arg2->y = chr->prop->pos.y;
				arg2->z = chr->prop->pos.z;
			}
		} else if (chr->actiontype == ACT_SKJUMP
				&& chr->act_skjump.state == SKJUMPSTATE_AIRBORNE
				&& !chr->act_skjump.needsnewanim
				&& g_Vars.lvupdate240_60 != 0) {
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
				&& g_Vars.lvupdate240_60 != 0) {
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

					ground = cdFindGroundY(sp98, chr->chrwidth, sp94,
							&chr->floorcol, &chr->floortype, &floorflags, &chr->floorroom, &inlift, &lift);

#if VERSION >= VERSION_NTSC_1_0
					if (chr->aibot
							&& chr->aibot->unk078 == 0
							&& ground < -100000
							&& g_Vars.lvupdate240_60 >= 5
							&& (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) == 0) {
						chr->aibot->unk078 = 10;

						arg2->x = prop->pos.x;
						arg2->y = prop->pos.y;
						arg2->z = prop->pos.z;

						roomsCopy(prop->rooms, spfc);

						lvupdate240freal = 0.0f;

						ground = cdFindGroundY(arg2, chr->chrwidth, spfc, &chr->floorcol, &chr->floortype, &floorflags, &chr->floorroom, &inlift, &lift);
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

						func0f0965e4(&yincrement, &sp68, VAR(lvupdate240freal));

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

							if (floorflags & TILEFLAG_DIE) {
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
						for (i = 0; i < g_Vars.lvupdate240_60; i++) {
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
	func0f069144(prop, chr->nextcol, chr->floorcol);

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

		if (chrnum > 32767) {
			chrnum = g_NextChrnum = 5000;
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
	chr->aioffset = 0;
	chr->aireturnlist = -1;
	chr->aishotlist = -1;
	chr->aipunchdodgelist = -1;
	chr->aishootingatmelist = -1;
	chr->aidarkroomlist = -1;
	chr->aiplayerdeadlist = -1;

	chr->chrwidth = 20;
	chr->chrheight = 185;
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

	chrInitSplats(chr);
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

	chr->ground = chr->manground = ground = cdFindGroundY(&testpos, chr->chrwidth, rooms, &chr->floorcol, &chr->floortype, NULL, &chr->floorroom, NULL, NULL);

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

	chr->prevpos.x = prop->pos.x;
	chr->prevpos.y = prop->pos.y;
	chr->prevpos.z = prop->pos.z;

	func0f069144(prop, chr->nextcol, chr->floorcol);

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

	func0f14159c(prop);
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

	modelFree(model);
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
			if (g_Vars.players[i]->cmpfollowprops[j].prop == prop) {
				g_Vars.players[i]->cmpfollowprops[j].prop = NULL;
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
		f32 mult = g_Vars.lvupdate240f / chr->aimendcount;

		if (mult > 1) {
			mult = 1;
		}

		chr->aimuplshoulder += (chr->aimendlshoulder - chr->aimuplshoulder) * mult;
		chr->aimuprshoulder += (chr->aimendrshoulder - chr->aimuprshoulder) * mult;
		chr->aimupback += (chr->aimendback - chr->aimupback) * mult;
		chr->aimsideback += (chr->aimendsideback - chr->aimsideback) * mult;

		chr->aimendcount -= g_Vars.lvupdate240_60;
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

		mtx00015be0(camGetUnk174c(), mtx);

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

		mtx00015be0(camGetMatrix1740(), mtx);
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

				mtx00015be0(camGetUnk174c(), mtx);

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

				mtx00015be0(camGetMatrix1740(), mtx);
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

	func0f1650d0(&lower, &upper, rooms, 7, 1);
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

u32 var80062998 = 0x00000000;
u32 var8006299c = 0x00000001;
u32 var800629a0 = 0x00000003;
u32 var800629a4 = 0x00000000;
u32 var800629a8 = 0x00000000;
u32 var800629ac = 0x00000000;
u32 var800629b0 = 0x00000000;
u32 var800629b4 = 0x00000000;
u32 var800629b8 = 0x00000000;
u32 var800629bc = 0x00000000;
u32 var800629c0 = 0x00000000;
u32 var800629c4 = 0x00000000;
u32 var800629c8 = 0x00000000;
u32 var800629cc = 0x00000000;
u32 var800629d0 = 0x00000000;
u32 var800629d4 = 0x00000000;

GLOBAL_ASM(
glabel chr0f022214
.late_rodata
glabel var7f1a87a0
.word 0x3fa8dd79
glabel var7f1a87a4
.word 0x3fc907a9
glabel var7f1a87a8
.word 0x404907a9
.text
/*  f022214:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f022218:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f02221c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f022220:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f022224:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f022228:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f02222c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f022230:	8cb00004 */ 	lw	$s0,0x4($a1)
/*  f022234:	00a09025 */ 	or	$s2,$a1,$zero
/*  f022238:	00c09825 */ 	or	$s3,$a2,$zero
/*  f02223c:	8e020040 */ 	lw	$v0,0x40($s0)
/*  f022240:	0080a025 */ 	or	$s4,$a0,$zero
/*  f022244:	8e030018 */ 	lw	$v1,0x18($s0)
/*  f022248:	304e0004 */ 	andi	$t6,$v0,0x4
/*  f02224c:	51c0000a */ 	beqzl	$t6,.L0f022278
/*  f022250:	8c640018 */ 	lw	$a0,0x18($v1)
/*  f022254:	92060002 */ 	lbu	$a2,0x2($s0)
/*  f022258:	02002025 */ 	or	$a0,$s0,$zero
/*  f02225c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f022260:	30cf0004 */ 	andi	$t7,$a2,0x4
/*  f022264:	0fc1ab4b */ 	jal	objFree
/*  f022268:	01e03025 */ 	or	$a2,$t7,$zero
/*  f02226c:	1000007e */ 	b	.L0f022468
/*  f022270:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f022274:	8c640018 */ 	lw	$a0,0x18($v1)
.L0f022278:
/*  f022278:	5080006c */ 	beqzl	$a0,.L0f02242c
/*  f02227c:	924a0001 */ 	lbu	$t2,0x1($s2)
/*  f022280:	8c65001c */ 	lw	$a1,0x1c($v1)
/*  f022284:	30580800 */ 	andi	$t8,$v0,0x800
/*  f022288:	50a00068 */ 	beqzl	$a1,.L0f02242c
/*  f02228c:	924a0001 */ 	lbu	$t2,0x1($s2)
/*  f022290:	57000066 */ 	bnezl	$t8,.L0f02242c
/*  f022294:	924a0001 */ 	lbu	$t2,0x1($s2)
/*  f022298:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f02229c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0222a0:	00194300 */ 	sll	$t0,$t9,0xc
/*  f0222a4:	05020061 */ 	bltzl	$t0,.L0f02242c
/*  f0222a8:	924a0001 */ 	lbu	$t2,0x1($s2)
/*  f0222ac:	0c006973 */ 	jal	model0001a5cc
/*  f0222b0:	afa30110 */ 	sw	$v1,0x110($sp)
/*  f0222b4:	3c0a8006 */ 	lui	$t2,%hi(var80062998)
/*  f0222b8:	254a2998 */ 	addiu	$t2,$t2,%lo(var80062998)
/*  f0222bc:	afa20104 */ 	sw	$v0,0x104($sp)
/*  f0222c0:	254d003c */ 	addiu	$t5,$t2,0x3c
/*  f0222c4:	27a900c4 */ 	addiu	$t1,$sp,0xc4
.L0f0222c8:
/*  f0222c8:	8d410000 */ 	lw	$at,0x0($t2)
/*  f0222cc:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f0222d0:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f0222d4:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*  f0222d8:	8d41fff8 */ 	lw	$at,-0x8($t2)
/*  f0222dc:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*  f0222e0:	8d41fffc */ 	lw	$at,-0x4($t2)
/*  f0222e4:	154dfff8 */ 	bne	$t2,$t5,.L0f0222c8
/*  f0222e8:	ad21fffc */ 	sw	$at,-0x4($t1)
/*  f0222ec:	8d410000 */ 	lw	$at,0x0($t2)
/*  f0222f0:	27b10080 */ 	addiu	$s1,$sp,0x80
/*  f0222f4:	ad210000 */ 	sw	$at,0x0($t1)
/*  f0222f8:	924e0001 */ 	lbu	$t6,0x1($s2)
/*  f0222fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f022300:	35cf0042 */ 	ori	$t7,$t6,0x42
/*  f022304:	a24f0001 */ 	sb	$t7,0x1($s2)
/*  f022308:	8e180040 */ 	lw	$t8,0x40($s0)
/*  f02230c:	8fa40104 */ 	lw	$a0,0x104($sp)
/*  f022310:	33190040 */ 	andi	$t9,$t8,0x40
/*  f022314:	13200007 */ 	beqz	$t9,.L0f022334
/*  f022318:	00000000 */ 	nop
/*  f02231c:	8e050048 */ 	lw	$a1,0x48($s0)
/*  f022320:	02203025 */ 	or	$a2,$s1,$zero
/*  f022324:	0c0056f9 */ 	jal	mtx00015be4
/*  f022328:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f02232c:	10000025 */ 	b	.L0f0223c4
/*  f022330:	afb100c4 */ 	sw	$s1,0xc4($sp)
.L0f022334:
/*  f022334:	12800003 */ 	beqz	$s4,.L0f022344
/*  f022338:	00001825 */ 	or	$v1,$zero,$zero
/*  f02233c:	10000001 */ 	b	.L0f022344
/*  f022340:	928302fe */ 	lbu	$v1,0x2fe($s4)
.L0f022344:
/*  f022344:	14610012 */ 	bne	$v1,$at,.L0f022390
/*  f022348:	27b10080 */ 	addiu	$s1,$sp,0x80
/*  f02234c:	3c017f1b */ 	lui	$at,%hi(var7f1a87a0)
/*  f022350:	c42c87a0 */ 	lwc1	$f12,%lo(var7f1a87a0)($at)
/*  f022354:	0c0058dd */ 	jal	mtx4LoadYRotation
/*  f022358:	02202825 */ 	or	$a1,$s1,$zero
/*  f02235c:	27b00040 */ 	addiu	$s0,$sp,0x40
/*  f022360:	3c017f1b */ 	lui	$at,%hi(var7f1a87a4)
/*  f022364:	c42c87a4 */ 	lwc1	$f12,%lo(var7f1a87a4)($at)
/*  f022368:	0c005900 */ 	jal	mtx4LoadZRotation
/*  f02236c:	02002825 */ 	or	$a1,$s0,$zero
/*  f022370:	02002025 */ 	or	$a0,$s0,$zero
/*  f022374:	0c00567f */ 	jal	mtx4MultMtx4InPlace
/*  f022378:	02202825 */ 	or	$a1,$s1,$zero
/*  f02237c:	8fa40104 */ 	lw	$a0,0x104($sp)
/*  f022380:	0c00567f */ 	jal	mtx4MultMtx4InPlace
/*  f022384:	02202825 */ 	or	$a1,$s1,$zero
/*  f022388:	1000000e */ 	b	.L0f0223c4
/*  f02238c:	afb100c4 */ 	sw	$s1,0xc4($sp)
.L0f022390:
/*  f022390:	8e880174 */ 	lw	$t0,0x174($s4)
/*  f022394:	27b10080 */ 	addiu	$s1,$sp,0x80
/*  f022398:	02202825 */ 	or	$a1,$s1,$zero
/*  f02239c:	16480008 */ 	bne	$s2,$t0,.L0f0223c0
/*  f0223a0:	3c017f1b */ 	lui	$at,%hi(var7f1a87a8)
/*  f0223a4:	0c005900 */ 	jal	mtx4LoadZRotation
/*  f0223a8:	c42c87a8 */ 	lwc1	$f12,%lo(var7f1a87a8)($at)
/*  f0223ac:	8fa40104 */ 	lw	$a0,0x104($sp)
/*  f0223b0:	0c00567f */ 	jal	mtx4MultMtx4InPlace
/*  f0223b4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0223b8:	10000002 */ 	b	.L0f0223c4
/*  f0223bc:	afb100c4 */ 	sw	$s1,0xc4($sp)
.L0f0223c0:
/*  f0223c0:	afa200c4 */ 	sw	$v0,0xc4($sp)
.L0f0223c4:
/*  f0223c4:	8fac0110 */ 	lw	$t4,0x110($sp)
/*  f0223c8:	8d8b0008 */ 	lw	$t3,0x8($t4)
/*  f0223cc:	8564000e */ 	lh	$a0,0xe($t3)
/*  f0223d0:	00046980 */ 	sll	$t5,$a0,0x6
/*  f0223d4:	0fc59e7d */ 	jal	gfxAllocate
/*  f0223d8:	01a02025 */ 	or	$a0,$t5,$zero
/*  f0223dc:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f0223e0:	27a400c4 */ 	addiu	$a0,$sp,0xc4
/*  f0223e4:	0c007399 */ 	jal	model0001ce64
/*  f0223e8:	8fa50110 */ 	lw	$a1,0x110($sp)
/*  f0223ec:	02402025 */ 	or	$a0,$s2,$zero
/*  f0223f0:	0fc1c18f */ 	jal	func0f07063c
/*  f0223f4:	02602825 */ 	or	$a1,$s3,$zero
/*  f0223f8:	8e51001c */ 	lw	$s1,0x1c($s2)
/*  f0223fc:	5220001a */ 	beqzl	$s1,.L0f022468
/*  f022400:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f022404:
/*  f022404:	8e300020 */ 	lw	$s0,0x20($s1)
/*  f022408:	02802025 */ 	or	$a0,$s4,$zero
/*  f02240c:	02202825 */ 	or	$a1,$s1,$zero
/*  f022410:	0fc08885 */ 	jal	chr0f022214
/*  f022414:	02603025 */ 	or	$a2,$s3,$zero
/*  f022418:	1600fffa */ 	bnez	$s0,.L0f022404
/*  f02241c:	02008825 */ 	or	$s1,$s0,$zero
/*  f022420:	10000011 */ 	b	.L0f022468
/*  f022424:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f022428:	924a0001 */ 	lbu	$t2,0x1($s2)
.L0f02242c:
/*  f02242c:	02402025 */ 	or	$a0,$s2,$zero
/*  f022430:	02602825 */ 	or	$a1,$s3,$zero
/*  f022434:	3149fffd */ 	andi	$t1,$t2,0xfffd
/*  f022438:	0fc1c18f */ 	jal	func0f07063c
/*  f02243c:	a2490001 */ 	sb	$t1,0x1($s2)
/*  f022440:	8e51001c */ 	lw	$s1,0x1c($s2)
/*  f022444:	52200008 */ 	beqzl	$s1,.L0f022468
/*  f022448:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f02244c:
/*  f02244c:	8e300020 */ 	lw	$s0,0x20($s1)
/*  f022450:	02202025 */ 	or	$a0,$s1,$zero
/*  f022454:	0fc1c1be */ 	jal	func0f0706f8
/*  f022458:	02602825 */ 	or	$a1,$s3,$zero
/*  f02245c:	1600fffb */ 	bnez	$s0,.L0f02244c
/*  f022460:	02008825 */ 	or	$s1,$s0,$zero
/*  f022464:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f022468:
/*  f022468:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f02246c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f022470:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f022474:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f022478:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f02247c:	03e00008 */ 	jr	$ra
/*  f022480:	27bd0118 */ 	addiu	$sp,$sp,0x118
);

// Mismatch: regalloc
//void chr0f022214(struct chrdata *chr, struct prop *prop, bool fulltick)
//{
//	struct defaultobj *obj = prop->obj;
//	struct model *model = obj->model;
//	struct prop *child;
//	struct prop *next;
//
//	if (obj->hidden & OBJHFLAG_REAPABLE) {
//		objFree(obj, true, obj->hidden2 & OBJH2FLAG_CANREGEN);
//		return;
//	}
//
//	if (prop);
//	if (prop);
//
//	if (model->attachedtomodel && model->attachedtonode
//			&& (obj->hidden & OBJHFLAG_00000800) == 0
//			&& (obj->flags2 & OBJFLAG2_INVISIBLE) == 0) {
//		Mtxf *sp104 = model0001a5cc(model->attachedtomodel, model->attachedtonode, 0);
//		struct modelrenderdata thing = {NULL, 1, 3};
//		u32 stack;
//		Mtxf sp80;
//		Mtxf sp40;
//
//		prop->flags |= PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK;
//
//		if (obj->hidden & OBJHFLAG_EMBEDDED) {
//			mtx00015be4(sp104, &obj->embedment->matrix, &sp80);
//			thing.matrix = &sp80;
//		} else if (CHRRACE(chr) == RACE_SKEDAR) {
//			// The skedar hand position is rotated weirdly, so compensate for it
//			mtx4LoadYRotation(1.3192588090897f, &sp80);
//			mtx4LoadZRotation(1.5705462694168f, &sp40);
//			mtx4MultMtx4InPlace(&sp40, &sp80);
//			mtx4MultMtx4InPlace(sp104, &sp80);
//			thing.matrix = &sp80;
//		} else if (prop == chr->weapons_held[HAND_LEFT]) {
//			// Flip the model
//			mtx4LoadZRotation(M_BADPI, &sp80);
//			mtx4MultMtx4InPlace(sp104, &sp80);
//			thing.matrix = &sp80;
//		} else {
//			thing.matrix = sp104;
//		}
//
//		thing.unk10 = gfxAllocate(model->filedata->nummatrices * sizeof(Mtxf));
//		model0001ce64(&thing, model);
//
//		func0f07063c(prop, fulltick);
//
//		child = prop->child;
//
//		while (child) {
//			next = child->next;
//			chr0f022214(chr, child, fulltick);
//			child = next;
//		}
//	} else {
//		prop->flags &= ~PROPFLAG_ONTHISSCREENTHISTICK;
//
//		func0f07063c(prop, fulltick);
//
//		child = prop->child;
//
//		while (child) {
//			next = child->next;
//			func0f0706f8(child, fulltick);
//			child = next;
//		}
//	}
//}

void chrCloak(struct chrdata *chr, bool value)
{
	if (!chrIsDead(chr)) {
		chr->hidden |= CHRHFLAG_CLOAKED;

		if (value) {
			func0f0939f8(0, chr->prop, SFX_CLOAK_ON, -1, -1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
		}
	}
}

void chrUncloak(struct chrdata *chr, bool value)
{
	if (chr->hidden & CHRHFLAG_CLOAKED) {
		chr->hidden &= ~CHRHFLAG_CLOAKED;

		if (value) {
			func0f0939f8(0, chr->prop, SFX_CLOAK_OFF, -1, -1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
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
				((u32 *)&cd0002a324)[-2] = 0;
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
		chr->cloakpause -= g_Vars.lvupdate240_60;

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
					qty -= g_Vars.lvupdate240_60;

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
					chr->aibot->unk2c4 += LVUPDATE240FREAL() * 0.4f;

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
					qty -= g_Vars.lvupdate240_60;

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
			s32 tmp = chr->cloakfadefrac + g_Vars.lvupdate240_60;
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
		if (chr->aibot->unk058 > g_Vars.lvupdate240_60) {
			chr->aibot->unk058 -= g_Vars.lvupdate240_60;
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
				chr->drugheadsway -= 0.175f * g_Vars.lvupdate240freal;
#else
				chr->drugheadsway -= 0.04375f * g_Vars.lvupdate240;
#endif

				if (chr->drugheadsway < 0.0f) {
					chr->drugheadsway = 0.0f;
				}
			} else if (chr->drugheadsway < 0.0f) {
#if VERSION >= VERSION_PAL_BETA
				chr->drugheadsway += 0.175f * g_Vars.lvupdate240freal;
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

		var8005efcc = &chrHandleJointPositioned;
		g_CurModelChr = chr;

		if (CHRRACE(chr) == RACE_DRCAROLL && g_Vars.tickmode != TICKMODE_CUTSCENE) {
			angle = chrGetInverseTheta(chr);

			sp190.x = sinf(angle) * 19;
			sp190.y = 0.0f;
			sp190.z = cosf(angle) * 19;

			mtx4LoadTranslation(&sp190, &sp1a8);
			mtx4MultMtx4InPlace(camGetMatrix1740(), &sp1a8);
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
				mtx4MultMtx4InPlace(camGetMatrix1740(), &sp1a8);
				sp210.unk00 = &sp1a8;
			} else {
				sp210.unk00 = camGetMatrix1740();
			}
		} else {
			sp210.unk00 = camGetMatrix1740();
		}

		sp210.unk10 = gfxAllocate(model->filedata->nummatrices * sizeof(Mtxf));

		if (fulltick && g_CurModelChr->flinchcnt >= 0) {
			g_CurModelChr->flinchcnt += g_Vars.lvupdate240_60;

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

			var8005efcc = NULL;
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

						mtx00015be4(&thing->unk06c, camGetUnk174c(), &thing->unk0ac);
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

						mtx00015be4(camGetMatrix1740(), &thing->unk02c, &thing->unk0ec);
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
void chrRenderAttachedObject(struct prop *prop, struct modelrenderdata *renderdata, bool withalpha, struct chrdata *chr)
{
	if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
		u32 stack;
		struct defaultobj *obj = prop->obj;
		struct model *model = obj->model;
		struct prop *child;

		modelRender(renderdata, model);

		// Note: OBJH2FLAG_RENDEROPAQUE << 1 is OBJH2FLAG_RENDERALPHA
		// so this is just checking if the appropriate flag is enabled
		if (obj->hidden2 & OBJH2FLAG_RENDEROPAQUE << withalpha) {
			renderdata->gdl = wallhitRenderPropHits(renderdata->gdl, prop, withalpha);
		}

		child = prop->child;

		while (child) {
			chrRenderAttachedObject(child, renderdata, withalpha, chr);
			child = child->next;
		}

		if (withalpha) {
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

Gfx *chrRender(struct prop *prop, Gfx *gdl, bool withalpha)
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
		if (!withalpha) {
			return gdl;
		}

		sp100 = 3;
	} else {
		if (!withalpha) {
			sp100 = 1;
		} else {
			sp100 = 2;
		}
	}

	sp104 = env0f1667f4(prop, sp108);

	if (chr->unk32c_18) {
		func0f069144(chr->prop, chr->nextcol, chr->floorcol);
		chr->unk32c_18 = false;
	}

	if (sp104 && alpha > 0) {
		struct modelrenderdata renderdata = {0, 1, 3};
		struct screenbox screenbox;
		s32 colour[4]; // rgba levels, but allowing > 256 temporarily
		u32 stack;

		if (withalpha && chr->cloakfadefrac > 0 && !chr->cloakfadefinished) {
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
			chrRenderAttachedObject(child, &renderdata, withalpha, chr);
			child = child->next;
		}

		gdl = renderdata.gdl;

		var8005efc4 = NULL;

		// Render shadow
		if (withalpha) {
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
					f32 size; // unsure if radius or diameter

					if (gaptoground <= 400 && g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
						if (chr->bodynum == BODY_SKEDAR || chr->bodynum == BODY_SKEDARKING) {
							size = 80;
						} else if (chr->bodynum == BODY_EYESPY) {
							size = 12;
						} else {
							size = 35;
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
							size *= 0.4f;
						}

						gdl = gfxRenderRadialShadow(gdl, prop->pos.x, chr->ground, prop->pos.z, chrGetInverseTheta(chr), size, shadowalpha | ~0xff);
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
		sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_19);
		return;
	}

	if (chrGetShield(chr) > 0.0f) {
		sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_00);
		return;
	}

	if (prop->type == PROPTYPE_OBJ
			|| prop->type == PROPTYPE_WEAPON
			|| prop->type == PROPTYPE_DOOR
			|| hitpart == HITPART_GUN
			|| hitpart == HITPART_HAT) {
		sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_00);
		return;
	}

	race = CHRRACE(chr);

	if (race == RACE_DRCAROLL || race == RACE_ROBOT || race == RACE_EYESPY) {
		sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_01);
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

		sparksCreate(chrprop->rooms[0], chrprop, &coord3, coord2, 0, SPARKTYPE_04);
	}

#if VERSION < VERSION_JPN_FINAL
	sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_02);
	sparksCreate(chrprop->rooms[0], chrprop, coord, coord2, 0, SPARKTYPE_03);
#endif
}

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

GLOBAL_ASM(
glabel chrBruise
.late_rodata
glabel var7f1a8904
.word chrBruise+0x778 # f027034
glabel var7f1a8908
.word chrBruise+0x7bc # f027078
glabel var7f1a890c
.word chrBruise+0x424 # f026ce0
glabel var7f1a8910
.word chrBruise+0x7bc # f027078
glabel var7f1a8914
.word chrBruise+0x7bc # f027078
glabel var7f1a8918
.word chrBruise+0x7bc # f027078
glabel var7f1a891c
.word chrBruise+0x7bc # f027078
glabel var7f1a8920
.word chrBruise+0x7bc # f027078
glabel var7f1a8924
.word chrBruise+0x7bc # f027078
glabel var7f1a8928
.word chrBruise+0x7bc # f027078
glabel var7f1a892c
.word chrBruise+0x790 # f02704c
glabel var7f1a8930
.word chrBruise+0x7bc # f027078
glabel var7f1a8934
.word chrBruise+0x7bc # f027078
glabel var7f1a8938
.word chrBruise+0x7bc # f027078
glabel var7f1a893c
.word chrBruise+0x7bc # f027078
glabel var7f1a8940
.word chrBruise+0x7a8 # f027064
glabel var7f1a8944
.word chrBruise+0x484 # f026d40
.text
/*  f0268bc:	27bdfee0 */ 	addiu	$sp,$sp,-288
/*  f0268c0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0268c4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0268c8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0268cc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0268d0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0268d4:	3c107fff */ 	lui	$s0,0x7fff
/*  f0268d8:	00e09025 */ 	or	$s2,$a3,$zero
/*  f0268dc:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f0268e0:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0268e4:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0268e8:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0268ec:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0268f0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0268f4:	afa40120 */ 	sw	$a0,0x120($sp)
/*  f0268f8:	afa50124 */ 	sw	$a1,0x124($sp)
/*  f0268fc:	00008825 */ 	or	$s1,$zero,$zero
/*  f026900:	3610ffff */ 	ori	$s0,$s0,0xffff
/*  f026904:	0c004b70 */ 	jal	random
/*  f026908:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f02690c:	24010032 */ 	addiu	$at,$zero,0x32
/*  f026910:	0041001b */ 	divu	$zero,$v0,$at
/*  f026914:	00007010 */ 	mfhi	$t6
/*  f026918:	25cf0014 */ 	addiu	$t7,$t6,0x14
/*  f02691c:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f026920:	afa000ac */ 	sw	$zero,0xac($sp)
/*  f026924:	0c0069d0 */ 	jal	model0001a740
/*  f026928:	02802025 */ 	or	$a0,$s4,$zero
/*  f02692c:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f026930:	00402825 */ 	or	$a1,$v0,$zero
/*  f026934:	0c006b57 */ 	jal	modelNodeGetModelRelativePosition
/*  f026938:	27a600e0 */ 	addiu	$a2,$sp,0xe0
/*  f02693c:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f026940:	c7a600e0 */ 	lwc1	$f6,0xe0($sp)
/*  f026944:	c7b000e4 */ 	lwc1	$f16,0xe4($sp)
/*  f026948:	02802825 */ 	or	$a1,$s4,$zero
/*  f02694c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f026950:	c7a600e8 */ 	lwc1	$f6,0xe8($sp)
/*  f026954:	24170017 */ 	addiu	$s7,$zero,0x17
/*  f026958:	24160012 */ 	addiu	$s6,$zero,0x12
/*  f02695c:	e7a800c8 */ 	swc1	$f8,0xc8($sp)
/*  f026960:	c64a0004 */ 	lwc1	$f10,0x4($s2)
/*  f026964:	24150008 */ 	addiu	$s5,$zero,0x8
/*  f026968:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f02696c:	e7b200cc */ 	swc1	$f18,0xcc($sp)
/*  f026970:	c6440008 */ 	lwc1	$f4,0x8($s2)
/*  f026974:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f026978:	128000c4 */ 	beqz	$s4,.L0f026c8c
/*  f02697c:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f026980:	94b30000 */ 	lhu	$s3,0x0($a1)
.L0f026984:
/*  f026984:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f026988:	327800ff */ 	andi	$t8,$s3,0xff
/*  f02698c:	13150097 */ 	beq	$t8,$s5,.L0f026bec
/*  f026990:	03009825 */ 	or	$s3,$t8,$zero
/*  f026994:	1316009a */ 	beq	$t8,$s6,.L0f026c00
/*  f026998:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f02699c:	1317009d */ 	beq	$t8,$s7,.L0f026c14
/*  f0269a0:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f0269a4:	24010018 */ 	addiu	$at,$zero,0x18
/*  f0269a8:	13010003 */ 	beq	$t8,$at,.L0f0269b8
/*  f0269ac:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f0269b0:	1000009c */ 	b	.L0f026c24
/*  f0269b4:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f0269b8:
/*  f0269b8:	8cb20004 */ 	lw	$s2,0x4($a1)
/*  f0269bc:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0269c0:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f0269c4:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0269c8:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f0269cc:	54800004 */ 	bnezl	$a0,.L0f0269e0
/*  f0269d0:	8e430000 */ 	lw	$v1,0x0($s2)
/*  f0269d4:	10000093 */ 	b	.L0f026c24
/*  f0269d8:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f0269dc:	8e430000 */ 	lw	$v1,0x0($s2)
.L0f0269e0:
/*  f0269e0:	3c0100ff */ 	lui	$at,0xff
/*  f0269e4:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0269e8:	14640005 */ 	bne	$v1,$a0,.L0f026a00
/*  f0269ec:	0080f025 */ 	or	$s8,$a0,$zero
/*  f0269f0:	8e4a0008 */ 	lw	$t2,0x8($s2)
/*  f0269f4:	00615824 */ 	and	$t3,$v1,$at
/*  f0269f8:	10000001 */ 	b	.L0f026a00
/*  f0269fc:	014bf021 */ 	addu	$s8,$t2,$t3
.L0f026a00:
/*  f026a00:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f026a04:	3c0100ff */ 	lui	$at,0xff
/*  f026a08:	50400008 */ 	beqzl	$v0,.L0f026a2c
/*  f026a0c:	afa000f4 */ 	sw	$zero,0xf4($sp)
/*  f026a10:	8e4c0008 */ 	lw	$t4,0x8($s2)
/*  f026a14:	3421ffff */ 	ori	$at,$at,0xffff
/*  f026a18:	00416824 */ 	and	$t5,$v0,$at
/*  f026a1c:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f026a20:	10000002 */ 	b	.L0f026a2c
/*  f026a24:	afae00f4 */ 	sw	$t6,0xf4($sp)
/*  f026a28:	afa000f4 */ 	sw	$zero,0xf4($sp)
.L0f026a2c:
/*  f026a2c:	83c20000 */ 	lb	$v0,0x0($s8)
/*  f026a30:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f026a34:	8faf00f4 */ 	lw	$t7,0xf4($sp)
/*  f026a38:	5441000a */ 	bnel	$v0,$at,.L0f026a64
/*  f026a3c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f026a40:	51e00005 */ 	beqzl	$t7,.L0f026a58
/*  f026a44:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f026a48:	01e0f025 */ 	or	$s8,$t7,$zero
/*  f026a4c:	1000fff7 */ 	b	.L0f026a2c
/*  f026a50:	afa000f4 */ 	sw	$zero,0xf4($sp)
/*  f026a54:	8fa500fc */ 	lw	$a1,0xfc($sp)
.L0f026a58:
/*  f026a58:	10000072 */ 	b	.L0f026c24
/*  f026a5c:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f026a60:	24010004 */ 	addiu	$at,$zero,0x4
.L0f026a64:
/*  f026a64:	1441003e */ 	bne	$v0,$at,.L0f026b60
/*  f026a68:	8fac00ec */ 	lw	$t4,0xec($sp)
/*  f026a6c:	8fc20004 */ 	lw	$v0,0x4($s8)
/*  f026a70:	93c90001 */ 	lbu	$t1,0x1($s8)
/*  f026a74:	3c0100ff */ 	lui	$at,0xff
/*  f026a78:	8e4a000c */ 	lw	$t2,0xc($s2)
/*  f026a7c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f026a80:	0041c824 */ 	and	$t9,$v0,$at
/*  f026a84:	00095902 */ 	srl	$t3,$t1,0x4
/*  f026a88:	25690001 */ 	addiu	$t1,$t3,0x1
/*  f026a8c:	11800055 */ 	beqz	$t4,.L0f026be4
/*  f026a90:	01591821 */ 	addu	$v1,$t2,$t9
/*  f026a94:	19200053 */ 	blez	$t1,.L0f026be4
/*  f026a98:	00003025 */ 	or	$a2,$zero,$zero
/*  f026a9c:	00601025 */ 	or	$v0,$v1,$zero
.L0f026aa0:
/*  f026aa0:	84470000 */ 	lh	$a3,0x0($v0)
/*  f026aa4:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f026aa8:	8fae00c0 */ 	lw	$t6,0xc0($sp)
/*  f026aac:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f026ab0:	01a71823 */ 	subu	$v1,$t5,$a3
/*  f026ab4:	00630019 */ 	multu	$v1,$v1
/*  f026ab8:	01cf2023 */ 	subu	$a0,$t6,$t7
/*  f026abc:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f026ac0:	84590004 */ 	lh	$t9,0x4($v0)
/*  f026ac4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f026ac8:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f026acc:	03192823 */ 	subu	$a1,$t8,$t9
/*  f026ad0:	00005012 */ 	mflo	$t2
/*  f026ad4:	00000000 */ 	nop
/*  f026ad8:	00000000 */ 	nop
/*  f026adc:	00840019 */ 	multu	$a0,$a0
/*  f026ae0:	00005812 */ 	mflo	$t3
/*  f026ae4:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f026ae8:	00000000 */ 	nop
/*  f026aec:	00a50019 */ 	multu	$a1,$a1
/*  f026af0:	00006812 */ 	mflo	$t5
/*  f026af4:	018d4021 */ 	addu	$t0,$t4,$t5
/*  f026af8:	0110082a */ 	slt	$at,$t0,$s0
/*  f026afc:	10200014 */ 	beqz	$at,.L0f026b50
/*  f026b00:	00000000 */ 	nop
/*  f026b04:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f026b08:	c7b200d8 */ 	lwc1	$f18,0xd8($sp)
/*  f026b0c:	c7a600dc */ 	lwc1	$f6,0xdc($sp)
/*  f026b10:	01008025 */ 	or	$s0,$t0,$zero
/*  f026b14:	440f8000 */ 	mfc1	$t7,$f16
/*  f026b18:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f026b1c:	8fb100fc */ 	lw	$s1,0xfc($sp)
/*  f026b20:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f026b24:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f026b28:	844b0002 */ 	lh	$t3,0x2($v0)
/*  f026b2c:	440a2000 */ 	mfc1	$t2,$f4
/*  f026b30:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f026b34:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f026b38:	afac0104 */ 	sw	$t4,0x104($sp)
/*  f026b3c:	844f0004 */ 	lh	$t7,0x4($v0)
/*  f026b40:	440e4000 */ 	mfc1	$t6,$f8
/*  f026b44:	00000000 */ 	nop
/*  f026b48:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f026b4c:	afb80108 */ 	sw	$t8,0x108($sp)
.L0f026b50:
/*  f026b50:	14c9ffd3 */ 	bne	$a2,$t1,.L0f026aa0
/*  f026b54:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f026b58:	1000ffb4 */ 	b	.L0f026a2c
/*  f026b5c:	27de0008 */ 	addiu	$s8,$s8,0x8
.L0f026b60:
/*  f026b60:	24010001 */ 	addiu	$at,$zero,0x1
/*  f026b64:	1441001f */ 	bne	$v0,$at,.L0f026be4
/*  f026b68:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f026b6c:	8fc20004 */ 	lw	$v0,0x4($s8)
/*  f026b70:	3c0100ff */ 	lui	$at,0xff
/*  f026b74:	3421ffff */ 	ori	$at,$at,0xffff
/*  f026b78:	0041c824 */ 	and	$t9,$v0,$at
/*  f026b7c:	0c00698d */ 	jal	model0001a634
/*  f026b80:	00192982 */ 	srl	$a1,$t9,0x6
/*  f026b84:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f026b88:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f026b8c:	00402825 */ 	or	$a1,$v0,$zero
/*  f026b90:	0c006b57 */ 	jal	modelNodeGetModelRelativePosition
/*  f026b94:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f026b98:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f026b9c:	c7b000c8 */ 	lwc1	$f16,0xc8($sp)
/*  f026ba0:	c7a600d8 */ 	lwc1	$f6,0xd8($sp)
/*  f026ba4:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f026ba8:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f026bac:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f026bb0:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f026bb4:	c7b200dc */ 	lwc1	$f18,0xdc($sp)
/*  f026bb8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f026bbc:	440b2000 */ 	mfc1	$t3,$f4
/*  f026bc0:	c7a400d0 */ 	lwc1	$f4,0xd0($sp)
/*  f026bc4:	440d8000 */ 	mfc1	$t5,$f16
/*  f026bc8:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f026bcc:	afab00bc */ 	sw	$t3,0xbc($sp)
/*  f026bd0:	afad00c0 */ 	sw	$t5,0xc0($sp)
/*  f026bd4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f026bd8:	440f4000 */ 	mfc1	$t7,$f8
/*  f026bdc:	00000000 */ 	nop
/*  f026be0:	afaf00c4 */ 	sw	$t7,0xc4($sp)
.L0f026be4:
/*  f026be4:	1000ff91 */ 	b	.L0f026a2c
/*  f026be8:	27de0008 */ 	addiu	$s8,$s8,0x8
.L0f026bec:
/*  f026bec:	0c0071e1 */ 	jal	model0001c784
/*  f026bf0:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f026bf4:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f026bf8:	1000000a */ 	b	.L0f026c24
/*  f026bfc:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f026c00:
/*  f026c00:	0c0071f4 */ 	jal	model0001c7d0
/*  f026c04:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f026c08:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f026c0c:	10000005 */ 	b	.L0f026c24
/*  f026c10:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f026c14:
/*  f026c14:	0c007207 */ 	jal	modelAttachHead
/*  f026c18:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f026c1c:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f026c20:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f026c24:
/*  f026c24:	10400009 */ 	beqz	$v0,.L0f026c4c
/*  f026c28:	00000000 */ 	nop
/*  f026c2c:	10b40005 */ 	beq	$a1,$s4,.L0f026c44
/*  f026c30:	2401000a */ 	addiu	$at,$zero,0xa
/*  f026c34:	12610005 */ 	beq	$s3,$at,.L0f026c4c
/*  f026c38:	24010011 */ 	addiu	$at,$zero,0x11
/*  f026c3c:	12610003 */ 	beq	$s3,$at,.L0f026c4c
/*  f026c40:	00000000 */ 	nop
.L0f026c44:
/*  f026c44:	1000000f */ 	b	.L0f026c84
/*  f026c48:	00402825 */ 	or	$a1,$v0,$zero
.L0f026c4c:
/*  f026c4c:	10a0000d */ 	beqz	$a1,.L0f026c84
/*  f026c50:	00000000 */ 	nop
.L0f026c54:
/*  f026c54:	54b40004 */ 	bnel	$a1,$s4,.L0f026c68
/*  f026c58:	8ca2000c */ 	lw	$v0,0xc($a1)
/*  f026c5c:	10000009 */ 	b	.L0f026c84
/*  f026c60:	00002825 */ 	or	$a1,$zero,$zero
/*  f026c64:	8ca2000c */ 	lw	$v0,0xc($a1)
.L0f026c68:
/*  f026c68:	50400004 */ 	beqzl	$v0,.L0f026c7c
/*  f026c6c:	8ca50008 */ 	lw	$a1,0x8($a1)
/*  f026c70:	10000004 */ 	b	.L0f026c84
/*  f026c74:	00402825 */ 	or	$a1,$v0,$zero
/*  f026c78:	8ca50008 */ 	lw	$a1,0x8($a1)
.L0f026c7c:
/*  f026c7c:	14a0fff5 */ 	bnez	$a1,.L0f026c54
/*  f026c80:	00000000 */ 	nop
.L0f026c84:
/*  f026c84:	54a0ff3f */ 	bnezl	$a1,.L0f026984
/*  f026c88:	94b30000 */ 	lhu	$s3,0x0($a1)
.L0f026c8c:
/*  f026c8c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f026c90:	1220010c */ 	beqz	$s1,.L0f0270c4
/*  f026c94:	afab0118 */ 	sw	$t3,0x118($sp)
/*  f026c98:	8fa70120 */ 	lw	$a3,0x120($sp)
/*  f026c9c:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f026ca0:	8cec0008 */ 	lw	$t4,0x8($a3)
/*  f026ca4:	8d850000 */ 	lw	$a1,0x0($t4)
/*  f026ca8:	50a00107 */ 	beqzl	$a1,.L0f0270c8
/*  f026cac:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f026cb0:	94b30000 */ 	lhu	$s3,0x0($a1)
.L0f026cb4:
/*  f026cb4:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f026cb8:	326d00ff */ 	andi	$t5,$s3,0xff
/*  f026cbc:	25aefff8 */ 	addiu	$t6,$t5,-8
/*  f026cc0:	2dc10011 */ 	sltiu	$at,$t6,0x11
/*  f026cc4:	102000ec */ 	beqz	$at,.L0f027078
/*  f026cc8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f026ccc:	3c017f1b */ 	lui	$at,%hi(var7f1a8904)
/*  f026cd0:	002e0821 */ 	addu	$at,$at,$t6
/*  f026cd4:	8c2e8904 */ 	lw	$t6,%lo(var7f1a8904)($at)
/*  f026cd8:	01c00008 */ 	jr	$t6
/*  f026cdc:	00000000 */ 	nop
/*  f026ce0:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x2c0)
/*  f026ce4:	8c84a280 */ 	lw	$a0,%lo(g_Vars+0x2c0)($a0)
/*  f026ce8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f026cec:	50800012 */ 	beqzl	$a0,.L0f026d38
/*  f026cf0:	afaa0118 */ 	sw	$t2,0x118($sp)
/*  f026cf4:	1880000d */ 	blez	$a0,.L0f026d2c
/*  f026cf8:	00003025 */ 	or	$a2,$zero,$zero
/*  f026cfc:	3c0f800a */ 	lui	$t7,%hi(g_Vars)
/*  f026d00:	25e29fc0 */ 	addiu	$v0,$t7,%lo(g_Vars)
/*  f026d04:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f026d08:	03021821 */ 	addu	$v1,$t8,$v0
/*  f026d0c:	8c5902c4 */ 	lw	$t9,0x2c4($v0)
.L0f026d10:
/*  f026d10:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f026d14:	0043082b */ 	sltu	$at,$v0,$v1
/*  f026d18:	14b90002 */ 	bne	$a1,$t9,.L0f026d24
/*  f026d1c:	00000000 */ 	nop
/*  f026d20:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f026d24:
/*  f026d24:	5420fffa */ 	bnezl	$at,.L0f026d10
/*  f026d28:	8c5902c4 */ 	lw	$t9,0x2c4($v0)
.L0f026d2c:
/*  f026d2c:	10000002 */ 	b	.L0f026d38
/*  f026d30:	afa60118 */ 	sw	$a2,0x118($sp)
/*  f026d34:	afaa0118 */ 	sw	$t2,0x118($sp)
.L0f026d38:
/*  f026d38:	100000d0 */ 	b	.L0f02707c
/*  f026d3c:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f026d40:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f026d44:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f026d48:	00e02025 */ 	or	$a0,$a3,$zero
/*  f026d4c:	1160002a */ 	beqz	$t3,.L0f026df8
/*  f026d50:	00000000 */ 	nop
/*  f026d54:	8cb20004 */ 	lw	$s2,0x4($a1)
/*  f026d58:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f026d5c:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f026d60:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f026d64:	00408025 */ 	or	$s0,$v0,$zero
/*  f026d68:	54800005 */ 	bnezl	$a0,.L0f026d80
/*  f026d6c:	8e430000 */ 	lw	$v1,0x0($s2)
/*  f026d70:	8fa70120 */ 	lw	$a3,0x120($sp)
/*  f026d74:	100000c0 */ 	b	.L0f027078
/*  f026d78:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f026d7c:	8e430000 */ 	lw	$v1,0x0($s2)
.L0f026d80:
/*  f026d80:	3c0600ff */ 	lui	$a2,0xff
/*  f026d84:	34c6ffff */ 	ori	$a2,$a2,0xffff
/*  f026d88:	14640007 */ 	bne	$v1,$a0,.L0f026da8
/*  f026d8c:	0080f025 */ 	or	$s8,$a0,$zero
/*  f026d90:	3c0600ff */ 	lui	$a2,0xff
/*  f026d94:	8e4c0008 */ 	lw	$t4,0x8($s2)
/*  f026d98:	34c6ffff */ 	ori	$a2,$a2,0xffff
/*  f026d9c:	00666824 */ 	and	$t5,$v1,$a2
/*  f026da0:	10000001 */ 	b	.L0f026da8
/*  f026da4:	018df021 */ 	addu	$s8,$t4,$t5
.L0f026da8:
/*  f026da8:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f026dac:	50400007 */ 	beqzl	$v0,.L0f026dcc
/*  f026db0:	afa000f4 */ 	sw	$zero,0xf4($sp)
/*  f026db4:	8e4e0008 */ 	lw	$t6,0x8($s2)
/*  f026db8:	0046c024 */ 	and	$t8,$v0,$a2
/*  f026dbc:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f026dc0:	10000002 */ 	b	.L0f026dcc
/*  f026dc4:	afaf00f4 */ 	sw	$t7,0xf4($sp)
/*  f026dc8:	afa000f4 */ 	sw	$zero,0xf4($sp)
.L0f026dcc:
/*  f026dcc:	83c20000 */ 	lb	$v0,0x0($s8)
/*  f026dd0:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f026dd4:	8fb900f4 */ 	lw	$t9,0xf4($sp)
/*  f026dd8:	5441000a */ 	bnel	$v0,$at,.L0f026e04
/*  f026ddc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f026de0:	53200005 */ 	beqzl	$t9,.L0f026df8
/*  f026de4:	8fa70120 */ 	lw	$a3,0x120($sp)
/*  f026de8:	0320f025 */ 	or	$s8,$t9,$zero
/*  f026dec:	1000fff7 */ 	b	.L0f026dcc
/*  f026df0:	afa000f4 */ 	sw	$zero,0xf4($sp)
/*  f026df4:	8fa70120 */ 	lw	$a3,0x120($sp)
.L0f026df8:
/*  f026df8:	1000009f */ 	b	.L0f027078
/*  f026dfc:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f026e00:	24010004 */ 	addiu	$at,$zero,0x4
.L0f026e04:
/*  f026e04:	14410072 */ 	bne	$v0,$at,.L0f026fd0
/*  f026e08:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f026e0c:	8fca0004 */ 	lw	$t2,0x4($s8)
/*  f026e10:	93d60001 */ 	lbu	$s6,0x1($s8)
/*  f026e14:	8e4b000c */ 	lw	$t3,0xc($s2)
/*  f026e18:	0146a824 */ 	and	$s5,$t2,$a2
/*  f026e1c:	00166102 */ 	srl	$t4,$s6,0x4
/*  f026e20:	25960001 */ 	addiu	$s6,$t4,0x1
/*  f026e24:	11a00081 */ 	beqz	$t5,.L0f02702c
/*  f026e28:	01751021 */ 	addu	$v0,$t3,$s5
/*  f026e2c:	1ac0007f */ 	blez	$s6,.L0f02702c
/*  f026e30:	00009825 */ 	or	$s3,$zero,$zero
/*  f026e34:	0000a025 */ 	or	$s4,$zero,$zero
/*  f026e38:	00408825 */ 	or	$s1,$v0,$zero
.L0f026e3c:
/*  f026e3c:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f026e40:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f026e44:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f026e48:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f026e4c:	c7b200d8 */ 	lwc1	$f18,0xd8($sp)
/*  f026e50:	44188000 */ 	mfc1	$t8,$f16
/*  f026e54:	00000000 */ 	nop
/*  f026e58:	030f1021 */ 	addu	$v0,$t8,$t7
/*  f026e5c:	54590055 */ 	bnel	$v0,$t9,.L0f026fb4
/*  f026e60:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f026e64:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f026e68:	862c0002 */ 	lh	$t4,0x2($s1)
/*  f026e6c:	8fad0104 */ 	lw	$t5,0x104($sp)
/*  f026e70:	c7a600dc */ 	lwc1	$f6,0xdc($sp)
/*  f026e74:	440b2000 */ 	mfc1	$t3,$f4
/*  f026e78:	00000000 */ 	nop
/*  f026e7c:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f026e80:	544d004c */ 	bnel	$v0,$t5,.L0f026fb4
/*  f026e84:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f026e88:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f026e8c:	862f0004 */ 	lh	$t7,0x4($s1)
/*  f026e90:	8fb90108 */ 	lw	$t9,0x108($sp)
/*  f026e94:	44184000 */ 	mfc1	$t8,$f8
/*  f026e98:	00000000 */ 	nop
/*  f026e9c:	030f1021 */ 	addu	$v0,$t8,$t7
/*  f026ea0:	54590044 */ 	bnel	$v0,$t9,.L0f026fb4
/*  f026ea4:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f026ea8:	864b0010 */ 	lh	$t3,0x10($s2)
/*  f026eac:	8e4a000c */ 	lw	$t2,0xc($s2)
/*  f026eb0:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f026eb4:	01770019 */ 	multu	$t3,$s7
/*  f026eb8:	00006012 */ 	mflo	$t4
/*  f026ebc:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f026ec0:	25ae0007 */ 	addiu	$t6,$t5,0x7
/*  f026ec4:	35d80007 */ 	ori	$t8,$t6,0x7
/*  f026ec8:	3b0f0007 */ 	xori	$t7,$t8,0x7
/*  f026ecc:	55f9001b */ 	bnel	$t7,$t9,.L0f026f3c
/*  f026ed0:	86590010 */ 	lh	$t9,0x10($s2)
/*  f026ed4:	96440016 */ 	lhu	$a0,0x16($s2)
/*  f026ed8:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f026edc:	00003025 */ 	or	$a2,$zero,$zero
/*  f026ee0:	0fc4a557 */ 	jal	vtxstoreAllocate
/*  f026ee4:	00003825 */ 	or	$a3,$zero,$zero
/*  f026ee8:	50400014 */ 	beqzl	$v0,.L0f026f3c
/*  f026eec:	86590010 */ 	lh	$t9,0x10($s2)
/*  f026ef0:	964b0016 */ 	lhu	$t3,0x16($s2)
/*  f026ef4:	00001825 */ 	or	$v1,$zero,$zero
/*  f026ef8:	00002025 */ 	or	$a0,$zero,$zero
/*  f026efc:	5960000e */ 	blezl	$t3,.L0f026f38
/*  f026f00:	ae020008 */ 	sw	$v0,0x8($s0)
/*  f026f04:	00402825 */ 	or	$a1,$v0,$zero
/*  f026f08:	8e0a0008 */ 	lw	$t2,0x8($s0)
.L0f026f0c:
/*  f026f0c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f026f10:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f026f14:	01446021 */ 	addu	$t4,$t2,$a0
/*  f026f18:	8d810000 */ 	lw	$at,0x0($t4)
/*  f026f1c:	24840004 */ 	addiu	$a0,$a0,4
/*  f026f20:	aca1fffc */ 	sw	$at,-0x4($a1)
/*  f026f24:	96580016 */ 	lhu	$t8,0x16($s2)
/*  f026f28:	0078082a */ 	slt	$at,$v1,$t8
/*  f026f2c:	5420fff7 */ 	bnezl	$at,.L0f026f0c
/*  f026f30:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f026f34:	ae020008 */ 	sw	$v0,0x8($s0)
.L0f026f38:
/*  f026f38:	86590010 */ 	lh	$t9,0x10($s2)
.L0f026f3c:
/*  f026f3c:	8e4f000c */ 	lw	$t7,0xc($s2)
/*  f026f40:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f026f44:	03370019 */ 	multu	$t9,$s7
/*  f026f48:	00005812 */ 	mflo	$t3
/*  f026f4c:	01eb5021 */ 	addu	$t2,$t7,$t3
/*  f026f50:	254d0007 */ 	addiu	$t5,$t2,0x7
/*  f026f54:	35ac0007 */ 	ori	$t4,$t5,0x7
/*  f026f58:	398e0007 */ 	xori	$t6,$t4,0x7
/*  f026f5c:	11c40014 */ 	beq	$t6,$a0,.L0f026fb0
/*  f026f60:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f026f64:	02b7001b */ 	divu	$zero,$s5,$s7
/*  f026f68:	0000c812 */ 	mflo	$t9
/*  f026f6c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f026f70:	00197880 */ 	sll	$t7,$t9,0x2
/*  f026f74:	01f97823 */ 	subu	$t7,$t7,$t9
/*  f026f78:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f026f7c:	030f5821 */ 	addu	$t3,$t8,$t7
/*  f026f80:	01745021 */ 	addu	$t2,$t3,$s4
/*  f026f84:	91420007 */ 	lbu	$v0,0x7($t2)
/*  f026f88:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f026f8c:	008c1821 */ 	addu	$v1,$a0,$t4
/*  f026f90:	00026883 */ 	sra	$t5,$v0,0x2
/*  f026f94:	000dc880 */ 	sll	$t9,$t5,0x2
/*  f026f98:	0079c021 */ 	addu	$t8,$v1,$t9
/*  f026f9c:	01a01025 */ 	or	$v0,$t5,$zero
/*  f026fa0:	16e00002 */ 	bnez	$s7,.L0f026fac
/*  f026fa4:	00000000 */ 	nop
/*  f026fa8:	0007000d */ 	break	0x7
.L0f026fac:
/*  f026fac:	a30e0003 */ 	sb	$t6,0x3($t8)
.L0f026fb0:
/*  f026fb0:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f026fb4:
/*  f026fb4:	2694000c */ 	addiu	$s4,$s4,0xc
/*  f026fb8:	1676ffa0 */ 	bne	$s3,$s6,.L0f026e3c
/*  f026fbc:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f026fc0:	3c0600ff */ 	lui	$a2,0xff
/*  f026fc4:	34c6ffff */ 	ori	$a2,$a2,0xffff
/*  f026fc8:	1000ff80 */ 	b	.L0f026dcc
/*  f026fcc:	27de0008 */ 	addiu	$s8,$s8,0x8
.L0f026fd0:
/*  f026fd0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f026fd4:	54410010 */ 	bnel	$v0,$at,.L0f027018
/*  f026fd8:	24010007 */ 	addiu	$at,$zero,0x7
/*  f026fdc:	8fcf0004 */ 	lw	$t7,0x4($s8)
/*  f026fe0:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f026fe4:	01e61024 */ 	and	$v0,$t7,$a2
/*  f026fe8:	0c00698d */ 	jal	model0001a634
/*  f026fec:	00022982 */ 	srl	$a1,$v0,0x6
/*  f026ff0:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f026ff4:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f026ff8:	00402825 */ 	or	$a1,$v0,$zero
/*  f026ffc:	0c006b57 */ 	jal	modelNodeGetModelRelativePosition
/*  f027000:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f027004:	3c0600ff */ 	lui	$a2,0xff
/*  f027008:	34c6ffff */ 	ori	$a2,$a2,0xffff
/*  f02700c:	1000ff6f */ 	b	.L0f026dcc
/*  f027010:	27de0008 */ 	addiu	$s8,$s8,0x8
/*  f027014:	24010007 */ 	addiu	$at,$zero,0x7
.L0f027018:
/*  f027018:	14410004 */ 	bne	$v0,$at,.L0f02702c
/*  f02701c:	00000000 */ 	nop
/*  f027020:	8fcb0004 */ 	lw	$t3,0x4($s8)
/*  f027024:	01665024 */ 	and	$t2,$t3,$a2
/*  f027028:	afaa00ac */ 	sw	$t2,0xac($sp)
.L0f02702c:
/*  f02702c:	1000ff67 */ 	b	.L0f026dcc
/*  f027030:	27de0008 */ 	addiu	$s8,$s8,0x8
/*  f027034:	00e02025 */ 	or	$a0,$a3,$zero
/*  f027038:	0c0071e1 */ 	jal	model0001c784
/*  f02703c:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f027040:	8fa70120 */ 	lw	$a3,0x120($sp)
/*  f027044:	1000000c */ 	b	.L0f027078
/*  f027048:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f02704c:	00e02025 */ 	or	$a0,$a3,$zero
/*  f027050:	0c0071f4 */ 	jal	model0001c7d0
/*  f027054:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f027058:	8fa70120 */ 	lw	$a3,0x120($sp)
/*  f02705c:	10000006 */ 	b	.L0f027078
/*  f027060:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f027064:	00e02025 */ 	or	$a0,$a3,$zero
/*  f027068:	0c007207 */ 	jal	modelAttachHead
/*  f02706c:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f027070:	8fa70120 */ 	lw	$a3,0x120($sp)
/*  f027074:	8fa500fc */ 	lw	$a1,0xfc($sp)
.L0f027078:
/*  f027078:	8ca20014 */ 	lw	$v0,0x14($a1)
.L0f02707c:
/*  f02707c:	10400003 */ 	beqz	$v0,.L0f02708c
/*  f027080:	00000000 */ 	nop
/*  f027084:	1000000d */ 	b	.L0f0270bc
/*  f027088:	00402825 */ 	or	$a1,$v0,$zero
.L0f02708c:
/*  f02708c:	10a0000b */ 	beqz	$a1,.L0f0270bc
/*  f027090:	00000000 */ 	nop
.L0f027094:
/*  f027094:	50a00007 */ 	beqzl	$a1,.L0f0270b4
/*  f027098:	8ca50008 */ 	lw	$a1,0x8($a1)
/*  f02709c:	8ca2000c */ 	lw	$v0,0xc($a1)
/*  f0270a0:	50400004 */ 	beqzl	$v0,.L0f0270b4
/*  f0270a4:	8ca50008 */ 	lw	$a1,0x8($a1)
/*  f0270a8:	10000004 */ 	b	.L0f0270bc
/*  f0270ac:	00402825 */ 	or	$a1,$v0,$zero
/*  f0270b0:	8ca50008 */ 	lw	$a1,0x8($a1)
.L0f0270b4:
/*  f0270b4:	14a0fff7 */ 	bnez	$a1,.L0f027094
/*  f0270b8:	00000000 */ 	nop
.L0f0270bc:
/*  f0270bc:	54a0fefd */ 	bnezl	$a1,.L0f026cb4
/*  f0270c0:	94b30000 */ 	lhu	$s3,0x0($a1)
.L0f0270c4:
/*  f0270c4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0270c8:
/*  f0270c8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0270cc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0270d0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0270d4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0270d8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0270dc:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0270e0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0270e4:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0270e8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0270ec:	03e00008 */ 	jr	$ra
/*  f0270f0:	27bd0120 */ 	addiu	$sp,$sp,0x120
);

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
					struct gfxvtx *vertices = vtxstoreAllocate(rodata->numvertices, 0, 0, 0);

					if (vertices) {
						for (i = 0; i < rodata->numvertices; i++) {
							vertices[i] = rwdata->vertices[i];
						}

						rwdata->vertices = vertices;
					}
				}

				// Copy the colours from the modeldef to the vtxstore
				if ((u32)rwdata->colours == ALIGN8((u32)&rodata->vertices[rodata->numvertices])) {
					colours = vtxstoreAllocate(rodata->numcolours, 2, 0, 0);

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
							mtx4TransformVecInPlace(camGetUnk174c(), &spdc);
							mtx4RotateVec(&model->matrices[sp84], &sp88.unk0c, &spd0);
							mtx4RotateVecInPlace(camGetUnk174c(), &spd0);
							break;
						}

						spc0 = model000225d4(model, &shotdata->unk00, &shotdata->unk0c, &node);
					}
				} else {
					spc0 = model000225d4(model, &shotdata->unk00, &shotdata->unk0c, &node);

					if (spc0 > 0) {
						if (func0f06bea0(model, model->filedata->rootnode, model->filedata->rootnode, &shotdata->unk00,
									&shotdata->unk0c, &sp88.unk00, &sp70, &node, &spc0, &sp84, &sp80)) {
							mtx4TransformVec(camGetUnk174c(), &sp88.unk00, &spdc);
							mtx4RotateVec(camGetUnk174c(), &sp88.unk0c, &spd0);
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
				mtx = camGetMatrix1740();
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

		mtx4TransformVec(camGetUnk174c(), &sp98, &hitpos);
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

					if (type->num04 > 0) {
						index = random() % type->num04;

						wallhitCreate(
								&hit->hitthing.unk00,
								&hit->hitthing.unk0c,
								&shotdata->gunpos,
								0,
								0,
								type->unk04[index],
								1,
								hit->prop,
								hit->unk40,
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

				index = random() % type->num04;

				wallhitCreate(
						&hit->hitthing.unk00,
						&hit->hitthing.unk0c,
						&shotdata->gunpos,
						0,
						0,
						type->unk04[index],
						1,
						chr->weapons_held[2],
						hit->unk40,
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

					splatsCreateForChrHit(prop, (struct splat *)shotdata, &sp98, &hitpos, darker, 0, g_Vars.currentplayer->prop->chr);
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

					splatsCreateForChrHit(prop, (struct splat *)shotdata, &sp98, &hitpos, darker, 0, g_Vars.currentplayer->prop->chr);
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
		chr->geo.header.type = TILETYPE_03;

		if (chr->actiontype == ACT_DIE || chr->actiontype == ACT_DRUGGEDDROP) {
			chr->geo.header.flags = TILEFLAG_0010;
		} else {
			chr->geo.header.flags = TILEFLAG_0004 | TILEFLAG_0010;
		}

		chr->geo.ymin = chr->manground;
		chr->geo.ymax = chr->manground + chr->chrheight;

		if (chr->actiontype == ACT_SKJUMP) {
			if (chr->manground > chr->act_skjump.ground) {
				chr->geo.ymin = chr->act_skjump.ground;
			}
		}

		chr->geo.x = prop->pos.x;
		chr->geo.z = prop->pos.z;
		chr->geo.width = chr->chrwidth;

		if (g_Vars.unk00048c) {
			chr->geo.width = 15;
		}

		*start = (void *) &chr->geo;
		*end = *start + sizeof(struct tiletype3);

		return true;
	}

	*end = NULL;
	*start = NULL;

	return false;

}

void chrGetBbox(struct prop *prop, f32 *width, f32 *ymax, f32 *ymin)
{
	struct chrdata *chr = prop->chr;

	*width = chr->chrwidth;
	*ymax = chr->manground + chr->chrheight;
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

GLOBAL_ASM(
glabel shieldhitCreate
/*  f028f7c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f028f80:	3c0a8006 */ 	lui	$t2,%hi(g_ShieldHits)
/*  f028f84:	8d4a2a8c */ 	lw	$t2,%lo(g_ShieldHits)($t2)
/*  f028f88:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f028f8c:	00808025 */ 	or	$s0,$a0,$zero
/*  f028f90:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f028f94:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f028f98:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f028f9c:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f028fa0:	00005825 */ 	or	$t3,$zero,$zero
/*  f028fa4:	00004825 */ 	or	$t1,$zero,$zero
/*  f028fa8:	01404025 */ 	or	$t0,$t2,$zero
.L0f028fac:
/*  f028fac:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f028fb0:	55c00004 */ 	bnezl	$t6,.L0f028fc4
/*  f028fb4:	2529005c */ 	addiu	$t1,$t1,0x5c
/*  f028fb8:	10000005 */ 	b	.L0f028fd0
/*  f028fbc:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f028fc0:	2529005c */ 	addiu	$t1,$t1,0x5c
.L0f028fc4:
/*  f028fc4:	29210730 */ 	slti	$at,$t1,0x730
/*  f028fc8:	1420fff8 */ 	bnez	$at,.L0f028fac
/*  f028fcc:	2508005c */ 	addiu	$t0,$t0,0x5c
.L0f028fd0:
/*  f028fd0:	15600010 */ 	bnez	$t3,.L0f029014
/*  f028fd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f028fd8:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x8)
/*  f028fdc:	8c639fc8 */ 	lw	$v1,%lo(g_Vars+0x8)($v1)
/*  f028fe0:	00004825 */ 	or	$t1,$zero,$zero
/*  f028fe4:	01404025 */ 	or	$t0,$t2,$zero
/*  f028fe8:	24040730 */ 	addiu	$a0,$zero,0x730
.L0f028fec:
/*  f028fec:	8d02000c */ 	lw	$v0,0xc($t0)
/*  f028ff0:	0043082a */ 	slt	$at,$v0,$v1
/*  f028ff4:	50200004 */ 	beqzl	$at,.L0f029008
/*  f028ff8:	2529005c */ 	addiu	$t1,$t1,0x5c
/*  f028ffc:	012a2821 */ 	addu	$a1,$t1,$t2
/*  f029000:	00401825 */ 	or	$v1,$v0,$zero
/*  f029004:	2529005c */ 	addiu	$t1,$t1,0x5c
.L0f029008:
/*  f029008:	1524fff8 */ 	bne	$t1,$a0,.L0f028fec
/*  f02900c:	2508005c */ 	addiu	$t0,$t0,0x5c
/*  f029010:	00a05825 */ 	or	$t3,$a1,$zero
.L0f029014:
/*  f029014:	51600069 */ 	beqzl	$t3,.L0f0291bc
/*  f029018:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f02901c:	ad700000 */ 	sw	$s0,0x0($t3)
/*  f029020:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f029024:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x8)
/*  f029028:	00001025 */ 	or	$v0,$zero,$zero
/*  f02902c:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f029030:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f029034:	01601825 */ 	or	$v1,$t3,$zero
/*  f029038:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f02903c:	ad780008 */ 	sw	$t8,0x8($t3)
/*  f029040:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f029044:	a1790010 */ 	sb	$t9,0x10($t3)
/*  f029048:	8d8c9fc8 */ 	lw	$t4,%lo(g_Vars+0x8)($t4)
/*  f02904c:	ad6c000c */ 	sw	$t4,0xc($t3)
.L0f029050:
/*  f029050:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f029054:	28410020 */ 	slti	$at,$v0,0x20
/*  f029058:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f02905c:	1420fffc */ 	bnez	$at,.L0f029050
/*  f029060:	a0670017 */ 	sb	$a3,0x17($v1)
/*  f029064:	0c004b70 */ 	jal	random
/*  f029068:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f02906c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f029070:	0041001b */ 	divu	$zero,$v0,$at
/*  f029074:	8fab0024 */ 	lw	$t3,0x24($sp)
/*  f029078:	00006810 */ 	mfhi	$t5
/*  f02907c:	8fa30040 */ 	lw	$v1,0x40($sp)
/*  f029080:	25ae0002 */ 	addiu	$t6,$t5,0x2
/*  f029084:	a16e0011 */ 	sb	$t6,0x11($t3)
/*  f029088:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f02908c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f029090:	10600008 */ 	beqz	$v1,.L0f0290b4
/*  f029094:	e5640058 */ 	swc1	$f4,0x58($t3)
/*  f029098:	846f0000 */ 	lh	$t7,0x0($v1)
/*  f02909c:	a56f0012 */ 	sh	$t7,0x12($t3)
/*  f0290a0:	84780002 */ 	lh	$t8,0x2($v1)
/*  f0290a4:	a5780014 */ 	sh	$t8,0x14($t3)
/*  f0290a8:	84790004 */ 	lh	$t9,0x4($v1)
/*  f0290ac:	10000003 */ 	b	.L0f0290bc
/*  f0290b0:	a5790016 */ 	sh	$t9,0x16($t3)
.L0f0290b4:
/*  f0290b4:	240c7fff */ 	addiu	$t4,$zero,0x7fff
/*  f0290b8:	a56c0012 */ 	sh	$t4,0x12($t3)
.L0f0290bc:
/*  f0290bc:	8fad0034 */ 	lw	$t5,0x34($sp)
/*  f0290c0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0290c4:	00004825 */ 	or	$t1,$zero,$zero
/*  f0290c8:	11a00024 */ 	beqz	$t5,.L0f02915c
/*  f0290cc:	3c088006 */ 	lui	$t0,%hi(g_ShieldHits)
/*  f0290d0:	8d082a8c */ 	lw	$t0,%lo(g_ShieldHits)($t0)
/*  f0290d4:	24060020 */ 	addiu	$a2,$zero,0x20
/*  f0290d8:	2405fffe */ 	addiu	$a1,$zero,-2
.L0f0290dc:
/*  f0290dc:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0290e0:	2529005c */ 	addiu	$t1,$t1,0x5c
/*  f0290e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0290e8:	160e000c */ 	bne	$s0,$t6,.L0f02911c
/*  f0290ec:	01601825 */ 	or	$v1,$t3,$zero
.L0f0290f0:
/*  f0290f0:	80640018 */ 	lb	$a0,0x18($v1)
/*  f0290f4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0290f8:	10e40005 */ 	beq	$a3,$a0,.L0f029110
/*  f0290fc:	00000000 */ 	nop
/*  f029100:	10a40003 */ 	beq	$a1,$a0,.L0f029110
/*  f029104:	00000000 */ 	nop
/*  f029108:	10000003 */ 	b	.L0f029118
/*  f02910c:	00005025 */ 	or	$t2,$zero,$zero
.L0f029110:
/*  f029110:	1446fff7 */ 	bne	$v0,$a2,.L0f0290f0
/*  f029114:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f029118:
/*  f029118:	11400003 */ 	beqz	$t2,.L0f029128
.L0f02911c:
/*  f02911c:	29210730 */ 	slti	$at,$t1,0x730
/*  f029120:	1420ffee */ 	bnez	$at,.L0f0290dc
/*  f029124:	2508005c */ 	addiu	$t0,$t0,92
.L0f029128:
/*  f029128:	1140000c */ 	beqz	$t2,.L0f02915c
/*  f02912c:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f029130:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f029134:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f029138:	02003825 */ 	or	$a3,$s0,$zero
/*  f02913c:	0fc0a386 */ 	jal	chr0f028e18
/*  f029140:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f029144:	28410020 */ 	slti	$at,$v0,0x20
/*  f029148:	10200004 */ 	beqz	$at,.L0f02915c
/*  f02914c:	8fab0024 */ 	lw	$t3,0x24($sp)
/*  f029150:	01621821 */ 	addu	$v1,$t3,$v0
/*  f029154:	a0600018 */ 	sb	$zero,0x18($v1)
/*  f029158:	a0600038 */ 	sb	$zero,0x38($v1)
.L0f02915c:
/*  f02915c:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f029160:	24010003 */ 	addiu	$at,$zero,0x3
/*  f029164:	10410003 */ 	beq	$v0,$at,.L0f029174
/*  f029168:	24010006 */ 	addiu	$at,$zero,0x6
/*  f02916c:	54410007 */ 	bnel	$v0,$at,.L0f02918c
/*  f029170:	24010001 */ 	addiu	$at,$zero,0x1
.L0f029174:
/*  f029174:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f029178:	944f0192 */ 	lhu	$t7,0x192($v0)
/*  f02917c:	35f80002 */ 	ori	$t8,$t7,0x2
/*  f029180:	1000000d */ 	b	.L0f0291b8
/*  f029184:	a4580192 */ 	sh	$t8,0x192($v0)
/*  f029188:	24010001 */ 	addiu	$at,$zero,0x1
.L0f02918c:
/*  f02918c:	10410005 */ 	beq	$v0,$at,.L0f0291a4
/*  f029190:	24010004 */ 	addiu	$at,$zero,0x4
/*  f029194:	10410003 */ 	beq	$v0,$at,.L0f0291a4
/*  f029198:	24010002 */ 	addiu	$at,$zero,0x2
/*  f02919c:	54410007 */ 	bnel	$v0,$at,.L0f0291bc
/*  f0291a0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0291a4:
/*  f0291a4:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0291a8:	3c010002 */ 	lui	$at,0x2
/*  f0291ac:	8c590010 */ 	lw	$t9,0x10($v0)
/*  f0291b0:	03216025 */ 	or	$t4,$t9,$at
/*  f0291b4:	ac4c0010 */ 	sw	$t4,0x10($v0)
.L0f0291b8:
/*  f0291b8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0291bc:
/*  f0291bc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0291c0:	3c018006 */ 	lui	$at,%hi(g_ShieldHitActive)
/*  f0291c4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0291c8:	ac2d2a90 */ 	sw	$t5,%lo(g_ShieldHitActive)($at)
/*  f0291cc:	03e00008 */ 	jr	$ra
/*  f0291d0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

// Mismatch: Goal uses a temp register for shieldhit and handles the i/j loop
// differently.
//void shieldhitCreate(struct prop *prop, f32 shield, struct prop *arg2, struct modelnode *node, struct model *model, s32 side, s16 *arg6)
//{
//	struct shieldhit *shieldhit = NULL;
//	s32 i;
//	s32 j;
//
//	for (i = 0; i < 20; i++) {
//		if (g_ShieldHits[i].prop == NULL) {
//			shieldhit = &g_ShieldHits[i];
//			break;
//		}
//	}
//
//	if (shieldhit == NULL) {
//		for (i = 0; i < 20; i++) {
//			if (g_ShieldHits[i].lvframe60 < g_Vars.lvframe60) {
//				shieldhit = &g_ShieldHits[i];
//			}
//		}
//	}
//
//	if (shieldhit) {
//		shieldhit->prop = prop;
//		shieldhit->node = node;
//		shieldhit->model = model;
//		shieldhit->side = side;
//		shieldhit->lvframe60 = g_Vars.lvframe60;
//
//		for (i = 0; i < 32; i++) {
//			shieldhit->unk018[i] = -1;
//		}
//
//		shieldhit->unk011 = 2 + (random() % 6);
//		shieldhit->shield = shield;
//
//		if (arg6) {
//			shieldhit->unk012 = arg6[0];
//			shieldhit->unk014 = arg6[1];
//			shieldhit->unk016 = arg6[2];
//		} else {
//			shieldhit->unk012 = 0x7fff;
//		}
//
//		if (node) {
//			bool pass = true;
//
//			for (i = 0; i < 20; i++) {
//				if (g_ShieldHits[i].prop == prop) {
//					for (j = 0; j < 32; j++) {
//						if (g_ShieldHits[i].unk018[j] != -1 && g_ShieldHits[i].unk018[j] != -2) {
//							pass = false;
//							break;
//						}
//					}
//
//					if (!pass) {
//						break;
//					}
//				}
//			}
//
//			if (pass) {
//				s32 index = chr0f028e18(arg2, node, model, prop);
//
//				if (index < 32) {
//					shieldhit->unk018[index] = 0;
//					shieldhit->unk038[index] = 0;
//				}
//			}
//		}
//
//		if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
//			prop->chr->hidden2 |= CHRH2FLAG_SHIELDHIT;
//		} else if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
//			prop->obj->flags3 |= OBJFLAG3_SHIELDHIT;
//		}
//	}
//
//	g_ShieldHitActive = true;
//}

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

#if VERSION == VERSION_PAL_FINAL
GLOBAL_ASM(
glabel chr0f02983c
.late_rodata
glabel var7f1a9b60pf
.word 0x3c40c0c1
glabel var7f1a9b64pf
.word 0x3c40c0c1
glabel var7f1a9b68pf
.word 0x3bcddaca
glabel var7f1a9b6cpf
.word 0x3bcddaca
glabel var7f1a9b70pf
.word 0x3f169697
glabel var7f1a9b74pf
.word 0x3ea0a0a1
glabel var7f1a9b78pf
.word 0x3e70f0f1
glabel var7f1a9b7cpf
.word 0x3e20a0a1
glabel var7f1a9b80pf
.word 0x3cb0d9df
glabel var7f1a9b84pf
.word 0x40cccccd
glabel var7f1a9b88pf
.word 0x3b808081
glabel var7f1a9b8cpf
.word 0x407745d1
glabel var7f1a9b90pf
.word 0x3b808081
glabel var7f1a9b94pf
.word 0x4099999a
glabel var7f1a9b98pf
.word 0x3b808081
glabel var7f1a9b9cpf
.word 0x407745d1
glabel var7f1a9ba0pf
.word 0x3b808081
.text
/*  f029960:	27bdfe10 */ 	addiu	$sp,$sp,-496
/*  f029964:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f029968:	3c0e8006 */ 	lui	$t6,0x8006
/*  f02996c:	8fb50200 */ 	lw	$s5,0x200($sp)
/*  f029970:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f029974:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f029978:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f02997c:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f029980:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f029984:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f029988:	afa401f0 */ 	sw	$a0,0x1f0($sp)
/*  f02998c:	afa501f4 */ 	sw	$a1,0x1f4($sp)
/*  f029990:	afa601f8 */ 	sw	$a2,0x1f8($sp)
/*  f029994:	afa701fc */ 	sw	$a3,0x1fc($sp)
/*  f029998:	25ce2774 */ 	addiu	$t6,$t6,0x2774
/*  f02999c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0299a0:	27b201e0 */ 	addiu	$s2,$sp,0x1e0
/*  f0299a4:	8eb30004 */ 	lw	$s3,0x4($s5)
/*  f0299a8:	ae410000 */ 	sw	$at,0x0($s2)
/*  f0299ac:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0299b0:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0299b4:	25ef2780 */ 	addiu	$t7,$t7,0x2780
/*  f0299b8:	ae590004 */ 	sw	$t9,0x4($s2)
/*  f0299bc:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0299c0:	25f90060 */ 	addiu	$t9,$t7,0x60
/*  f0299c4:	27b80104 */ 	addiu	$t8,$sp,0x104
/*  f0299c8:	ae410008 */ 	sw	$at,0x8($s2)
.PF0f0299cc:
/*  f0299cc:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0299d0:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f0299d4:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0299d8:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f0299dc:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f0299e0:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f0299e4:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f0299e8:	15f9fff8 */ 	bne	$t7,$t9,.PF0f0299cc
/*  f0299ec:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f0299f0:	8fae01f8 */ 	lw	$t6,0x1f8($sp)
/*  f0299f4:	24010003 */ 	li	$at,0x3
/*  f0299f8:	24110006 */ 	li	$s1,0x6
/*  f0299fc:	91c40000 */ 	lbu	$a0,0x0($t6)
/*  f029a00:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
/*  f029a04:	50810004 */ 	beql	$a0,$at,.PF0f029a18
/*  f029a08:	8f300004 */ 	lw	$s0,0x4($t9)
/*  f029a0c:	56240014 */ 	bnel	$s1,$a0,.PF0f029a60
/*  f029a10:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
/*  f029a14:	8f300004 */ 	lw	$s0,0x4($t9)
.PF0f029a18:
/*  f029a18:	3c014120 */ 	lui	$at,0x4120
/*  f029a1c:	44812000 */ 	mtc1	$at,$f4
/*  f029a20:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f029a24:	24110006 */ 	li	$s1,0x6
/*  f029a28:	02002025 */ 	move	$a0,$s0
/*  f029a2c:	c5e60014 */ 	lwc1	$f6,0x14($t7)
/*  f029a30:	46062083 */ 	div.s	$f2,$f4,$f6
/*  f029a34:	0fc0d042 */ 	jal	chrGetShield
/*  f029a38:	e7a20170 */ 	swc1	$f2,0x170($sp)
/*  f029a3c:	921402e1 */ 	lbu	$s4,0x2e1($s0)
/*  f029a40:	960e0188 */ 	lhu	$t6,0x188($s0)
/*  f029a44:	c7a20170 */ 	lwc1	$f2,0x170($sp)
/*  f029a48:	0014c042 */ 	srl	$t8,$s4,0x1
/*  f029a4c:	46000386 */ 	mov.s	$f14,$f0
/*  f029a50:	0300a025 */ 	move	$s4,$t8
/*  f029a54:	10000011 */ 	b	.PF0f029a9c
/*  f029a58:	afae0164 */ 	sw	$t6,0x164($sp)
/*  f029a5c:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
.PF0f029a60:
/*  f029a60:	44801000 */ 	mtc1	$zero,$f2
/*  f029a64:	24140040 */ 	li	$s4,0x40
/*  f029a68:	8f220004 */ 	lw	$v0,0x4($t9)
/*  f029a6c:	afa00164 */ 	sw	$zero,0x164($sp)
/*  f029a70:	3c014100 */ 	lui	$at,0x4100
/*  f029a74:	8c4f0010 */ 	lw	$t7,0x10($v0)
/*  f029a78:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f029a7c:	53000006 */ 	beqzl	$t8,.PF0f029a98
/*  f029a80:	44817000 */ 	mtc1	$at,$f14
/*  f029a84:	3c014080 */ 	lui	$at,0x4080
/*  f029a88:	44817000 */ 	mtc1	$at,$f14
/*  f029a8c:	10000004 */ 	b	.PF0f029aa0
/*  f029a90:	02a02025 */ 	move	$a0,$s5
/*  f029a94:	44817000 */ 	mtc1	$at,$f14
.PF0f029a98:
/*  f029a98:	00000000 */ 	nop
.PF0f029a9c:
/*  f029a9c:	02a02025 */ 	move	$a0,$s5
.PF0f029aa0:
/*  f029aa0:	00002825 */ 	move	$a1,$zero
/*  f029aa4:	e7a20170 */ 	swc1	$f2,0x170($sp)
/*  f029aa8:	0c0068ad */ 	jal	model0001a524
/*  f029aac:	e7ae016c */ 	swc1	$f14,0x16c($sp)
/*  f029ab0:	c7a20170 */ 	lwc1	$f2,0x170($sp)
/*  f029ab4:	c6680004 */ 	lwc1	$f8,0x4($s3)
/*  f029ab8:	c6720008 */ 	lwc1	$f18,0x8($s3)
/*  f029abc:	8fae01fc */ 	lw	$t6,0x1fc($sp)
/*  f029ac0:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f029ac4:	c668000c */ 	lwc1	$f8,0xc($s3)
/*  f029ac8:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f029acc:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f029ad0:	c6720010 */ 	lwc1	$f18,0x10($s3)
/*  f029ad4:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f029ad8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f029adc:	00027980 */ 	sll	$t7,$v0,0x6
/*  f029ae0:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f029ae4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f029ae8:	44038000 */ 	mfc1	$v1,$f16
/*  f029aec:	3c190102 */ 	lui	$t9,0x102
/*  f029af0:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f029af4:	c6680014 */ 	lwc1	$f8,0x14($s3)
/*  f029af8:	44053000 */ 	mfc1	$a1,$f6
/*  f029afc:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f029b00:	c6720018 */ 	lwc1	$f18,0x18($s3)
/*  f029b04:	260a0008 */ 	addiu	$t2,$s0,0x8
/*  f029b08:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f029b0c:	c7ae016c */ 	lwc1	$f14,0x16c($sp)
/*  f029b10:	afaa01f0 */ 	sw	$t2,0x1f0($sp)
/*  f029b14:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f029b18:	44068000 */ 	mfc1	$a2,$f16
/*  f029b1c:	37390040 */ 	ori	$t9,$t9,0x40
/*  f029b20:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f029b24:	44073000 */ 	mfc1	$a3,$f6
/*  f029b28:	a7a30180 */ 	sh	$v1,0x180($sp)
/*  f029b2c:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f029b30:	a7a30186 */ 	sh	$v1,0x186($sp)
/*  f029b34:	a7a3018c */ 	sh	$v1,0x18c($sp)
/*  f029b38:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f029b3c:	a7a30192 */ 	sh	$v1,0x192($sp)
/*  f029b40:	a7a50198 */ 	sh	$a1,0x198($sp)
/*  f029b44:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f029b48:	44088000 */ 	mfc1	$t0,$f16
/*  f029b4c:	a7a5019e */ 	sh	$a1,0x19e($sp)
/*  f029b50:	a7a501a4 */ 	sh	$a1,0x1a4($sp)
/*  f029b54:	44093000 */ 	mfc1	$t1,$f6
/*  f029b58:	a7a501aa */ 	sh	$a1,0x1aa($sp)
/*  f029b5c:	a7a60182 */ 	sh	$a2,0x182($sp)
/*  f029b60:	a7a60188 */ 	sh	$a2,0x188($sp)
/*  f029b64:	a7a6019a */ 	sh	$a2,0x19a($sp)
/*  f029b68:	a7a601a0 */ 	sh	$a2,0x1a0($sp)
/*  f029b6c:	a7a7018e */ 	sh	$a3,0x18e($sp)
/*  f029b70:	a7a70194 */ 	sh	$a3,0x194($sp)
/*  f029b74:	a7a701a6 */ 	sh	$a3,0x1a6($sp)
/*  f029b78:	a7a701ac */ 	sh	$a3,0x1ac($sp)
/*  f029b7c:	a7a80184 */ 	sh	$t0,0x184($sp)
/*  f029b80:	a7a80190 */ 	sh	$t0,0x190($sp)
/*  f029b84:	a7a8019c */ 	sh	$t0,0x19c($sp)
/*  f029b88:	a7a801a8 */ 	sh	$t0,0x1a8($sp)
/*  f029b8c:	a7a9018a */ 	sh	$t1,0x18a($sp)
/*  f029b90:	a7a90196 */ 	sh	$t1,0x196($sp)
/*  f029b94:	a7a901a2 */ 	sh	$t1,0x1a2($sp)
/*  f029b98:	a7a901ae */ 	sh	$t1,0x1ae($sp)
/*  f029b9c:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f029ba0:	afa301cc */ 	sw	$v1,0x1cc($sp)
/*  f029ba4:	afa501c8 */ 	sw	$a1,0x1c8($sp)
/*  f029ba8:	e7ae016c */ 	swc1	$f14,0x16c($sp)
/*  f029bac:	afa601c4 */ 	sw	$a2,0x1c4($sp)
/*  f029bb0:	afa701c0 */ 	sw	$a3,0x1c0($sp)
/*  f029bb4:	afa801bc */ 	sw	$t0,0x1bc($sp)
/*  f029bb8:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f029bbc:	afa901b8 */ 	sw	$t1,0x1b8($sp)
/*  f029bc0:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029bc4:	c7ae016c */ 	lwc1	$f14,0x16c($sp)
/*  f029bc8:	2401fff9 */ 	li	$at,-7
/*  f029bcc:	15010082 */ 	bne	$t0,$at,.PF0f029dd8
/*  f029bd0:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f029bd4:	0fc5a253 */ 	jal	gfxAllocateColours
/*  f029bd8:	24040001 */ 	li	$a0,0x1
/*  f029bdc:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f029be0:	3c0e0700 */ 	lui	$t6,0x700
/*  f029be4:	35ce0004 */ 	ori	$t6,$t6,0x4
/*  f029be8:	26180008 */ 	addiu	$t8,$s0,0x8
/*  f029bec:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f029bf0:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f029bf4:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f029bf8:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f029bfc:	00402025 */ 	move	$a0,$v0
/*  f029c00:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f029c04:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f029c08:	240400ff */ 	li	$a0,0xff
/*  f029c0c:	2a810040 */ 	slti	$at,$s4,0x40
/*  f029c10:	a0640000 */ 	sb	$a0,0x0($v1)
/*  f029c14:	a0640001 */ 	sb	$a0,0x1($v1)
/*  f029c18:	1020000f */ 	beqz	$at,.PF0f029c58
/*  f029c1c:	a0640002 */ 	sb	$a0,0x2($v1)
/*  f029c20:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f029c24:	44944000 */ 	mtc1	$s4,$f8
/*  f029c28:	3c017f1b */ 	lui	$at,0x7f1b
/*  f029c2c:	44998000 */ 	mtc1	$t9,$f16
/*  f029c30:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f029c34:	c4269b60 */ 	lwc1	$f6,-0x64a0($at)
/*  f029c38:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f029c3c:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f029c40:	00000000 */ 	nop
/*  f029c44:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f029c48:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f029c4c:	44188000 */ 	mfc1	$t8,$f16
/*  f029c50:	10000011 */ 	b	.PF0f029c98
/*  f029c54:	a0780003 */ 	sb	$t8,0x3($v1)
.PF0f029c58:
/*  f029c58:	8faf0210 */ 	lw	$t7,0x210($sp)
/*  f029c5c:	240e007f */ 	li	$t6,0x7f
/*  f029c60:	01d4c823 */ 	subu	$t9,$t6,$s4
/*  f029c64:	44995000 */ 	mtc1	$t9,$f10
/*  f029c68:	448f2000 */ 	mtc1	$t7,$f4
/*  f029c6c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f029c70:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f029c74:	c4309b64 */ 	lwc1	$f16,-0x649c($at)
/*  f029c78:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f029c7c:	46069202 */ 	mul.s	$f8,$f18,$f6
/*  f029c80:	00000000 */ 	nop
/*  f029c84:	46104282 */ 	mul.s	$f10,$f8,$f16
/*  f029c88:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f029c8c:	440e2000 */ 	mfc1	$t6,$f4
/*  f029c90:	00000000 */ 	nop
/*  f029c94:	a06e0003 */ 	sb	$t6,0x3($v1)
.PF0f029c98:
/*  f029c98:	0fc5a239 */ 	jal	gfxAllocateVertices
/*  f029c9c:	24040018 */ 	li	$a0,0x18
/*  f029ca0:	00408025 */ 	move	$s0,$v0
/*  f029ca4:	27a60104 */ 	addiu	$a2,$sp,0x104
/*  f029ca8:	24090004 */ 	li	$t1,0x4
/*  f029cac:	24070200 */ 	li	$a3,0x200
/*  f029cb0:	27a50180 */ 	addiu	$a1,$sp,0x180
.PF0f029cb4:
/*  f029cb4:	00002025 */ 	move	$a0,$zero
/*  f029cb8:	02001825 */ 	move	$v1,$s0
/*  f029cbc:	00c01025 */ 	move	$v0,$a2
.PF0f029cc0:
/*  f029cc0:	8e410000 */ 	lw	$at,0x0($s2)
/*  f029cc4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f029cc8:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f029ccc:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f029cd0:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f029cd4:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f029cd8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f029cdc:	a86ffff8 */ 	swl	$t7,-0x8($v1)
/*  f029ce0:	b86ffffb */ 	swr	$t7,-0x5($v1)
/*  f029ce4:	8e410008 */ 	lw	$at,0x8($s2)
/*  f029ce8:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f029cec:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f029cf0:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f029cf4:	03110019 */ 	multu	$t8,$s1
/*  f029cf8:	00007012 */ 	mflo	$t6
/*  f029cfc:	00aec821 */ 	addu	$t9,$a1,$t6
/*  f029d00:	872f0000 */ 	lh	$t7,0x0($t9)
/*  f029d04:	a46ffff4 */ 	sh	$t7,-0xc($v1)
/*  f029d08:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f029d0c:	03110019 */ 	multu	$t8,$s1
/*  f029d10:	00007012 */ 	mflo	$t6
/*  f029d14:	00aec821 */ 	addu	$t9,$a1,$t6
/*  f029d18:	872f0002 */ 	lh	$t7,0x2($t9)
/*  f029d1c:	a46ffff6 */ 	sh	$t7,-0xa($v1)
/*  f029d20:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f029d24:	03110019 */ 	multu	$t8,$s1
/*  f029d28:	00007012 */ 	mflo	$t6
/*  f029d2c:	00aec821 */ 	addu	$t9,$a1,$t6
/*  f029d30:	872f0004 */ 	lh	$t7,0x4($t9)
/*  f029d34:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f029d38:	1489ffe1 */ 	bne	$a0,$t1,.PF0f029cc0
/*  f029d3c:	a46ffff8 */ 	sh	$t7,-0x8($v1)
/*  f029d40:	a6000008 */ 	sh	$zero,0x8($s0)
/*  f029d44:	a600000a */ 	sh	$zero,0xa($s0)
/*  f029d48:	a6070014 */ 	sh	$a3,0x14($s0)
/*  f029d4c:	a6000016 */ 	sh	$zero,0x16($s0)
/*  f029d50:	a6070020 */ 	sh	$a3,0x20($s0)
/*  f029d54:	a6070022 */ 	sh	$a3,0x22($s0)
/*  f029d58:	a600002c */ 	sh	$zero,0x2c($s0)
/*  f029d5c:	a607002e */ 	sh	$a3,0x2e($s0)
/*  f029d60:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f029d64:	3c190430 */ 	lui	$t9,0x430
/*  f029d68:	37390030 */ 	ori	$t9,$t9,0x30
/*  f029d6c:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f029d70:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f029d74:	af190000 */ 	sw	$t9,0x0($t8)
/*  f029d78:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f029d7c:	02002025 */ 	move	$a0,$s0
/*  f029d80:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f029d84:	afb800c8 */ 	sw	$t8,0xc8($sp)
/*  f029d88:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*  f029d8c:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f029d90:	3c0eb100 */ 	lui	$t6,0xb100
/*  f029d94:	ad020004 */ 	sw	$v0,0x4($t0)
/*  f029d98:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f029d9c:	35ce0032 */ 	ori	$t6,$t6,0x32
/*  f029da0:	24192010 */ 	li	$t9,0x2010
/*  f029da4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f029da8:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f029dac:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f029db0:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f029db4:	27af0164 */ 	addiu	$t7,$sp,0x164
/*  f029db8:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f029dbc:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f029dc0:	24070200 */ 	li	$a3,0x200
/*  f029dc4:	24090004 */ 	li	$t1,0x4
/*  f029dc8:	14cfffba */ 	bne	$a2,$t7,.PF0f029cb4
/*  f029dcc:	26100030 */ 	addiu	$s0,$s0,0x30
/*  f029dd0:	100006c0 */ 	b	.PF0f02b8d4
/*  f029dd4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PF0f029dd8:
/*  f029dd8:	3c05800b */ 	lui	$a1,0x800b
/*  f029ddc:	24180002 */ 	li	$t8,0x2
/*  f029de0:	240e0001 */ 	li	$t6,0x1
/*  f029de4:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f029de8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f029dec:	8ca5bb2c */ 	lw	$a1,-0x44d4($a1)
/*  f029df0:	27a401f0 */ 	addiu	$a0,$sp,0x1f0
/*  f029df4:	24060004 */ 	li	$a2,0x4
/*  f029df8:	24070001 */ 	li	$a3,0x1
/*  f029dfc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f029e00:	0fc2cfb8 */ 	jal	texSelect
/*  f029e04:	e7ae016c */ 	swc1	$f14,0x16c($sp)
/*  f029e08:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029e0c:	c7ae016c */ 	lwc1	$f14,0x16c($sp)
/*  f029e10:	27a50100 */ 	addiu	$a1,$sp,0x100
/*  f029e14:	05000004 */ 	bltz	$t0,.PF0f029e28
/*  f029e18:	27a600fc */ 	addiu	$a2,$sp,0xfc
/*  f029e1c:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
/*  f029e20:	1000001c */ 	b	.PF0f029e94
/*  f029e24:	c72c0058 */ 	lwc1	$f12,0x58($t9)
.PF0f029e28:
/*  f029e28:	2401fffe */ 	li	$at,-2
/*  f029e2c:	15010019 */ 	bne	$t0,$at,.PF0f029e94
/*  f029e30:	46007306 */ 	mov.s	$f12,$f14
/*  f029e34:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f029e38:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f029e3c:	81e20011 */ 	lb	$v0,0x11($t7)
/*  f029e40:	0058082a */ 	slt	$at,$v0,$t8
/*  f029e44:	50200005 */ 	beqzl	$at,.PF0f029e5c
/*  f029e48:	44823000 */ 	mtc1	$v0,$f6
/*  f029e4c:	44806000 */ 	mtc1	$zero,$f12
/*  f029e50:	10000010 */ 	b	.PF0f029e94
/*  f029e54:	00000000 */ 	nop
/*  f029e58:	44823000 */ 	mtc1	$v0,$f6
.PF0f029e5c:
/*  f029e5c:	8fae020c */ 	lw	$t6,0x20c($sp)
/*  f029e60:	3c014080 */ 	lui	$at,0x4080
/*  f029e64:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f029e68:	44819000 */ 	mtc1	$at,$f18
/*  f029e6c:	448e8000 */ 	mtc1	$t6,$f16
/*  f029e70:	3c013f80 */ 	lui	$at,0x3f80
/*  f029e74:	44813000 */ 	mtc1	$at,$f6
/*  f029e78:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f029e7c:	46089002 */ 	mul.s	$f0,$f18,$f8
/*  f029e80:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f029e84:	46062480 */ 	add.s	$f18,$f4,$f6
/*  f029e88:	46009203 */ 	div.s	$f8,$f18,$f0
/*  f029e8c:	46087302 */ 	mul.s	$f12,$f14,$f8
/*  f029e90:	00000000 */ 	nop
.PF0f029e94:
/*  f029e94:	0fc0a5c7 */ 	jal	chr0f0295f8
/*  f029e98:	27a700f8 */ 	addiu	$a3,$sp,0xf8
/*  f029e9c:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f029ea0:	8fad00fc */ 	lw	$t5,0xfc($sp)
/*  f029ea4:	8fbf00f8 */ 	lw	$ra,0xf8($sp)
/*  f029ea8:	2587ffec */ 	addiu	$a3,$t4,-20
/*  f029eac:	25a3ffec */ 	addiu	$v1,$t5,-20
/*  f029eb0:	27e4ffec */ 	addiu	$a0,$ra,-20
/*  f029eb4:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029eb8:	00605025 */ 	move	$t2,$v1
/*  f029ebc:	04e10002 */ 	bgez	$a3,.PF0f029ec8
/*  f029ec0:	00805825 */ 	move	$t3,$a0
/*  f029ec4:	00003825 */ 	move	$a3,$zero
.PF0f029ec8:
/*  f029ec8:	04610002 */ 	bgez	$v1,.PF0f029ed4
/*  f029ecc:	2582ffc4 */ 	addiu	$v0,$t4,-60
/*  f029ed0:	00005025 */ 	move	$t2,$zero
.PF0f029ed4:
/*  f029ed4:	04810002 */ 	bgez	$a0,.PF0f029ee0
/*  f029ed8:	25a3ffc4 */ 	addiu	$v1,$t5,-60
/*  f029edc:	00005825 */ 	move	$t3,$zero
.PF0f029ee0:
/*  f029ee0:	27e4ffc4 */ 	addiu	$a0,$ra,-60
/*  f029ee4:	afa200e8 */ 	sw	$v0,0xe8($sp)
/*  f029ee8:	afa300e4 */ 	sw	$v1,0xe4($sp)
/*  f029eec:	04410002 */ 	bgez	$v0,.PF0f029ef8
/*  f029ef0:	afa400e0 */ 	sw	$a0,0xe0($sp)
/*  f029ef4:	afa000e8 */ 	sw	$zero,0xe8($sp)
.PF0f029ef8:
/*  f029ef8:	04610002 */ 	bgez	$v1,.PF0f029f04
/*  f029efc:	3c19800a */ 	lui	$t9,0x800a
/*  f029f00:	afa000e4 */ 	sw	$zero,0xe4($sp)
.PF0f029f04:
/*  f029f04:	04810002 */ 	bgez	$a0,.PF0f029f10
/*  f029f08:	00000000 */ 	nop
/*  f029f0c:	afa000e0 */ 	sw	$zero,0xe0($sp)
.PF0f029f10:
/*  f029f10:	8f39a568 */ 	lw	$t9,-0x5a98($t9)
/*  f029f14:	241003e8 */ 	li	$s0,0x3e8
/*  f029f18:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f029f1c:	0330001a */ 	div	$zero,$t9,$s0
/*  f029f20:	00007810 */ 	mfhi	$t7
/*  f029f24:	448f8000 */ 	mtc1	$t7,$f16
/*  f029f28:	16000002 */ 	bnez	$s0,.PF0f029f34
/*  f029f2c:	00000000 */ 	nop
/*  f029f30:	0007000d */ 	break	0x7
.PF0f029f34:
/*  f029f34:	2401ffff */ 	li	$at,-1
/*  f029f38:	16010004 */ 	bne	$s0,$at,.PF0f029f4c
/*  f029f3c:	3c018000 */ 	lui	$at,0x8000
/*  f029f40:	17210002 */ 	bne	$t9,$at,.PF0f029f4c
/*  f029f44:	00000000 */ 	nop
/*  f029f48:	0006000d */ 	break	0x6
.PF0f029f4c:
/*  f029f4c:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f029f50:	3c017f1b */ 	lui	$at,0x7f1b
/*  f029f54:	c4249b68 */ 	lwc1	$f4,-0x6498($at)
/*  f029f58:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f029f5c:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f029f60:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f029f64:	0c00685b */ 	jal	sinf
/*  f029f68:	00000000 */ 	nop
/*  f029f6c:	3c0f800a */ 	lui	$t7,0x800a
/*  f029f70:	8defa568 */ 	lw	$t7,-0x5a98($t7)
/*  f029f74:	3c014200 */ 	lui	$at,0x4200
/*  f029f78:	44811000 */ 	mtc1	$at,$f2
/*  f029f7c:	01f0001a */ 	div	$zero,$t7,$s0
/*  f029f80:	3c013f80 */ 	lui	$at,0x3f80
/*  f029f84:	44813000 */ 	mtc1	$at,$f6
/*  f029f88:	3c013f00 */ 	lui	$at,0x3f00
/*  f029f8c:	44814000 */ 	mtc1	$at,$f8
/*  f029f90:	46060480 */ 	add.s	$f18,$f0,$f6
/*  f029f94:	0000c010 */ 	mfhi	$t8
/*  f029f98:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f029f9c:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029fa0:	46089402 */ 	mul.s	$f16,$f18,$f8
/*  f029fa4:	44989000 */ 	mtc1	$t8,$f18
/*  f029fa8:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f029fac:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f029fb0:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f029fb4:	46028282 */ 	mul.s	$f10,$f16,$f2
/*  f029fb8:	00000000 */ 	nop
/*  f029fbc:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f029fc0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f029fc4:	44153000 */ 	mfc1	$s5,$f6
/*  f029fc8:	00000000 */ 	nop
/*  f029fcc:	00157400 */ 	sll	$t6,$s5,0x10
/*  f029fd0:	000ecc03 */ 	sra	$t9,$t6,0x10
/*  f029fd4:	0320a825 */ 	move	$s5,$t9
/*  f029fd8:	16000002 */ 	bnez	$s0,.PF0f029fe4
/*  f029fdc:	00000000 */ 	nop
/*  f029fe0:	0007000d */ 	break	0x7
.PF0f029fe4:
/*  f029fe4:	2401ffff */ 	li	$at,-1
/*  f029fe8:	16010004 */ 	bne	$s0,$at,.PF0f029ffc
/*  f029fec:	3c018000 */ 	lui	$at,0x8000
/*  f029ff0:	15e10002 */ 	bne	$t7,$at,.PF0f029ffc
/*  f029ff4:	00000000 */ 	nop
/*  f029ff8:	0006000d */ 	break	0x6
.PF0f029ffc:
/*  f029ffc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a000:	c4309b6c */ 	lwc1	$f16,-0x6494($at)
/*  f02a004:	46104302 */ 	mul.s	$f12,$f8,$f16
/*  f02a008:	0c006858 */ 	jal	cosf
/*  f02a00c:	00000000 */ 	nop
/*  f02a010:	3c014200 */ 	lui	$at,0x4200
/*  f02a014:	44811000 */ 	mtc1	$at,$f2
/*  f02a018:	3c013f80 */ 	lui	$at,0x3f80
/*  f02a01c:	44816000 */ 	mtc1	$at,$f12
/*  f02a020:	3c013f00 */ 	lui	$at,0x3f00
/*  f02a024:	44812000 */ 	mtc1	$at,$f4
/*  f02a028:	460c0280 */ 	add.s	$f10,$f0,$f12
/*  f02a02c:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02a030:	26af0200 */ 	addiu	$t7,$s5,0x200
/*  f02a034:	2401fffd */ 	li	$at,-3
/*  f02a038:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f02a03c:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02a040:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02a044:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02a048:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f02a04c:	a7af0176 */ 	sh	$t7,0x176($sp)
/*  f02a050:	24040001 */ 	li	$a0,0x1
/*  f02a054:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f02a058:	00000000 */ 	nop
/*  f02a05c:	46029202 */ 	mul.s	$f8,$f18,$f2
/*  f02a060:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f02a064:	440e8000 */ 	mfc1	$t6,$f16
/*  f02a068:	00000000 */ 	nop
/*  f02a06c:	000e9c00 */ 	sll	$s3,$t6,0x10
/*  f02a070:	0013cc03 */ 	sra	$t9,$s3,0x10
/*  f02a074:	03209825 */ 	move	$s3,$t9
/*  f02a078:	25d40200 */ 	addiu	$s4,$t6,0x200
/*  f02a07c:	0014cc00 */ 	sll	$t9,$s4,0x10
/*  f02a080:	11010008 */ 	beq	$t0,$at,.PF0f02a0a4
/*  f02a084:	0019a403 */ 	sra	$s4,$t9,0x10
/*  f02a088:	2401fffc */ 	li	$at,-4
/*  f02a08c:	11010005 */ 	beq	$t0,$at,.PF0f02a0a4
/*  f02a090:	2401fffb */ 	li	$at,-5
/*  f02a094:	11010003 */ 	beq	$t0,$at,.PF0f02a0a4
/*  f02a098:	2401fffa */ 	li	$at,-6
/*  f02a09c:	5501016b */ 	bnel	$t0,$at,.PF0f02a64c
/*  f02a0a0:	2401fffe */ 	li	$at,-2
.PF0f02a0a4:
/*  f02a0a4:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02a0a8:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02a0ac:	0fc5a253 */ 	jal	gfxAllocateColours
/*  f02a0b0:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02a0b4:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f02a0b8:	3c190700 */ 	lui	$t9,0x700
/*  f02a0bc:	37390004 */ 	ori	$t9,$t9,0x4
/*  f02a0c0:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f02a0c4:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02a0c8:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f02a0cc:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02a0d0:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02a0d4:	00402025 */ 	move	$a0,$v0
/*  f02a0d8:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02a0dc:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a0e0:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02a0e4:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02a0e8:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02a0ec:	2401fffd */ 	li	$at,-3
/*  f02a0f0:	15010014 */ 	bne	$t0,$at,.PF0f02a144
/*  f02a0f4:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f02a0f8:	a0670000 */ 	sb	$a3,0x0($v1)
/*  f02a0fc:	a06a0001 */ 	sb	$t2,0x1($v1)
/*  f02a100:	a06b0002 */ 	sb	$t3,0x2($v1)
/*  f02a104:	8faf0164 */ 	lw	$t7,0x164($sp)
/*  f02a108:	8fb80210 */ 	lw	$t8,0x210($sp)
/*  f02a10c:	29e1000a */ 	slti	$at,$t7,0xa
/*  f02a110:	1020000a */ 	beqz	$at,.PF0f02a13c
/*  f02a114:	00000000 */ 	nop
/*  f02a118:	44985000 */ 	mtc1	$t8,$f10
/*  f02a11c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a120:	c4269b70 */ 	lwc1	$f6,-0x6490($at)
/*  f02a124:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f02a128:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f02a12c:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f02a130:	44194000 */ 	mfc1	$t9,$f8
/*  f02a134:	10000031 */ 	b	.PF0f02a1fc
/*  f02a138:	a0790003 */ 	sb	$t9,0x3($v1)
.PF0f02a13c:
/*  f02a13c:	1000002f */ 	b	.PF0f02a1fc
/*  f02a140:	a0600003 */ 	sb	$zero,0x3($v1)
.PF0f02a144:
/*  f02a144:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f02a148:	a06f0000 */ 	sb	$t7,0x0($v1)
/*  f02a14c:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f02a150:	a0780001 */ 	sb	$t8,0x1($v1)
/*  f02a154:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f02a158:	a06e0002 */ 	sb	$t6,0x2($v1)
/*  f02a15c:	8fb90164 */ 	lw	$t9,0x164($sp)
/*  f02a160:	2b21000a */ 	slti	$at,$t9,0xa
/*  f02a164:	10200024 */ 	beqz	$at,.PF0f02a1f8
/*  f02a168:	2401fffc */ 	li	$at,-4
/*  f02a16c:	1501000a */ 	bne	$t0,$at,.PF0f02a198
/*  f02a170:	8faf0210 */ 	lw	$t7,0x210($sp)
/*  f02a174:	448f8000 */ 	mtc1	$t7,$f16
/*  f02a178:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a17c:	c4249b74 */ 	lwc1	$f4,-0x648c($at)
/*  f02a180:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a184:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f02a188:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f02a18c:	440e9000 */ 	mfc1	$t6,$f18
/*  f02a190:	1000001a */ 	b	.PF0f02a1fc
/*  f02a194:	a06e0003 */ 	sb	$t6,0x3($v1)
.PF0f02a198:
/*  f02a198:	2401fffb */ 	li	$at,-5
/*  f02a19c:	1501000a */ 	bne	$t0,$at,.PF0f02a1c8
/*  f02a1a0:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02a1a4:	44994000 */ 	mtc1	$t9,$f8
/*  f02a1a8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a1ac:	c42a9b78 */ 	lwc1	$f10,-0x6488($at)
/*  f02a1b0:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f02a1b4:	460a8102 */ 	mul.s	$f4,$f16,$f10
/*  f02a1b8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f02a1bc:	44183000 */ 	mfc1	$t8,$f6
/*  f02a1c0:	1000000e */ 	b	.PF0f02a1fc
/*  f02a1c4:	a0780003 */ 	sb	$t8,0x3($v1)
.PF0f02a1c8:
/*  f02a1c8:	2401fffa */ 	li	$at,-6
/*  f02a1cc:	1501000b */ 	bne	$t0,$at,.PF0f02a1fc
/*  f02a1d0:	8fae0210 */ 	lw	$t6,0x210($sp)
/*  f02a1d4:	448e9000 */ 	mtc1	$t6,$f18
/*  f02a1d8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a1dc:	c4309b7c */ 	lwc1	$f16,-0x6484($at)
/*  f02a1e0:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f02a1e4:	46104282 */ 	mul.s	$f10,$f8,$f16
/*  f02a1e8:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f02a1ec:	440f2000 */ 	mfc1	$t7,$f4
/*  f02a1f0:	10000002 */ 	b	.PF0f02a1fc
/*  f02a1f4:	a06f0003 */ 	sb	$t7,0x3($v1)
.PF0f02a1f8:
/*  f02a1f8:	a0600003 */ 	sb	$zero,0x3($v1)
.PF0f02a1fc:
/*  f02a1fc:	24040018 */ 	li	$a0,0x18
/*  f02a200:	afa301d8 */ 	sw	$v1,0x1d8($sp)
/*  f02a204:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02a208:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02a20c:	0fc5a239 */ 	jal	gfxAllocateVertices
/*  f02a210:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02a214:	8fa501f8 */ 	lw	$a1,0x1f8($sp)
/*  f02a218:	24010001 */ 	li	$at,0x1
/*  f02a21c:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a220:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f02a224:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02a228:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02a22c:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02a230:	10810006 */ 	beq	$a0,$at,.PF0f02a24c
/*  f02a234:	00408025 */ 	move	$s0,$v0
/*  f02a238:	24090004 */ 	li	$t1,0x4
/*  f02a23c:	11240003 */ 	beq	$t1,$a0,.PF0f02a24c
/*  f02a240:	24010002 */ 	li	$at,0x2
/*  f02a244:	548100b0 */ 	bnel	$a0,$at,.PF0f02a508
/*  f02a248:	24080200 */ 	li	$t0,0x200
.PF0f02a24c:
/*  f02a24c:	8cb80004 */ 	lw	$t8,0x4($a1)
/*  f02a250:	24090004 */ 	li	$t1,0x4
/*  f02a254:	3c0f800a */ 	lui	$t7,0x800a
/*  f02a258:	8f0e0010 */ 	lw	$t6,0x10($t8)
/*  f02a25c:	31d91000 */ 	andi	$t9,$t6,0x1000
/*  f02a260:	532000a9 */ 	beqzl	$t9,.PF0f02a508
/*  f02a264:	24080200 */ 	li	$t0,0x200
/*  f02a268:	8defa568 */ 	lw	$t7,-0x5a98($t7)
/*  f02a26c:	24010123 */ 	li	$at,0x123
/*  f02a270:	afa301d8 */ 	sw	$v1,0x1d8($sp)
/*  f02a274:	01e1001a */ 	div	$zero,$t7,$at
/*  f02a278:	0000c010 */ 	mfhi	$t8
/*  f02a27c:	44983000 */ 	mtc1	$t8,$f6
/*  f02a280:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a284:	c4289b80 */ 	lwc1	$f8,-0x6480($at)
/*  f02a288:	468034a0 */ 	cvt.s.w	$f18,$f6
/*  f02a28c:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02a290:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02a294:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02a298:	46089302 */ 	mul.s	$f12,$f18,$f8
/*  f02a29c:	0c00685b */ 	jal	sinf
/*  f02a2a0:	00000000 */ 	nop
/*  f02a2a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f02a2a8:	44818000 */ 	mtc1	$at,$f16
/*  f02a2ac:	3c013f00 */ 	lui	$at,0x3f00
/*  f02a2b0:	44812000 */ 	mtc1	$at,$f4
/*  f02a2b4:	46100280 */ 	add.s	$f10,$f0,$f16
/*  f02a2b8:	3c0142f0 */ 	lui	$at,0x42f0
/*  f02a2bc:	44813000 */ 	mtc1	$at,$f6
/*  f02a2c0:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02a2c4:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f02a2c8:	3c014248 */ 	lui	$at,0x4248
/*  f02a2cc:	44818000 */ 	mtc1	$at,$f16
/*  f02a2d0:	30ee00ff */ 	andi	$t6,$a3,0xff
/*  f02a2d4:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a2d8:	448e5000 */ 	mtc1	$t6,$f10
/*  f02a2dc:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02a2e0:	460c3482 */ 	mul.s	$f18,$f6,$f12
/*  f02a2e4:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02a2e8:	24090004 */ 	li	$t1,0x4
/*  f02a2ec:	460c8082 */ 	mul.s	$f2,$f16,$f12
/*  f02a2f0:	3c014f80 */ 	lui	$at,0x4f80
/*  f02a2f4:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f02a2f8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f02a2fc:	440f4000 */ 	mfc1	$t7,$f8
/*  f02a300:	00000000 */ 	nop
/*  f02a304:	25f80032 */ 	addiu	$t8,$t7,0x32
/*  f02a308:	05c10004 */ 	bgez	$t6,.PF0f02a31c
/*  f02a30c:	a0780003 */ 	sb	$t8,0x3($v1)
/*  f02a310:	44813000 */ 	mtc1	$at,$f6
/*  f02a314:	00000000 */ 	nop
/*  f02a318:	46062100 */ 	add.s	$f4,$f4,$f6
.PF0f02a31c:
/*  f02a31c:	46022480 */ 	add.s	$f18,$f4,$f2
/*  f02a320:	240f0001 */ 	li	$t7,0x1
/*  f02a324:	3c014f00 */ 	lui	$at,0x4f00
/*  f02a328:	315800ff */ 	andi	$t8,$t2,0xff
/*  f02a32c:	4459f800 */ 	cfc1	$t9,$31
/*  f02a330:	44cff800 */ 	ctc1	$t7,$31
/*  f02a334:	00000000 */ 	nop
/*  f02a338:	46009224 */ 	cvt.w.s	$f8,$f18
/*  f02a33c:	444ff800 */ 	cfc1	$t7,$31
/*  f02a340:	00000000 */ 	nop
/*  f02a344:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f02a348:	51e00013 */ 	beqzl	$t7,.PF0f02a398
/*  f02a34c:	440f4000 */ 	mfc1	$t7,$f8
/*  f02a350:	44814000 */ 	mtc1	$at,$f8
/*  f02a354:	240f0001 */ 	li	$t7,0x1
/*  f02a358:	46089201 */ 	sub.s	$f8,$f18,$f8
/*  f02a35c:	44cff800 */ 	ctc1	$t7,$31
/*  f02a360:	00000000 */ 	nop
/*  f02a364:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f02a368:	444ff800 */ 	cfc1	$t7,$31
/*  f02a36c:	00000000 */ 	nop
/*  f02a370:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f02a374:	15e00005 */ 	bnez	$t7,.PF0f02a38c
/*  f02a378:	00000000 */ 	nop
/*  f02a37c:	440f4000 */ 	mfc1	$t7,$f8
/*  f02a380:	3c018000 */ 	lui	$at,0x8000
/*  f02a384:	10000007 */ 	b	.PF0f02a3a4
/*  f02a388:	01e17825 */ 	or	$t7,$t7,$at
.PF0f02a38c:
/*  f02a38c:	10000005 */ 	b	.PF0f02a3a4
/*  f02a390:	240fffff */ 	li	$t7,-1
/*  f02a394:	440f4000 */ 	mfc1	$t7,$f8
.PF0f02a398:
/*  f02a398:	00000000 */ 	nop
/*  f02a39c:	05e0fffb */ 	bltz	$t7,.PF0f02a38c
/*  f02a3a0:	00000000 */ 	nop
.PF0f02a3a4:
/*  f02a3a4:	44d9f800 */ 	ctc1	$t9,$31
/*  f02a3a8:	44988000 */ 	mtc1	$t8,$f16
/*  f02a3ac:	a06f0000 */ 	sb	$t7,0x0($v1)
/*  f02a3b0:	07010005 */ 	bgez	$t8,.PF0f02a3c8
/*  f02a3b4:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a3b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f02a3bc:	44813000 */ 	mtc1	$at,$f6
/*  f02a3c0:	00000000 */ 	nop
/*  f02a3c4:	46065280 */ 	add.s	$f10,$f10,$f6
.PF0f02a3c8:
/*  f02a3c8:	46025100 */ 	add.s	$f4,$f10,$f2
/*  f02a3cc:	24190001 */ 	li	$t9,0x1
/*  f02a3d0:	3c014f00 */ 	lui	$at,0x4f00
/*  f02a3d4:	316f00ff */ 	andi	$t7,$t3,0xff
/*  f02a3d8:	444ef800 */ 	cfc1	$t6,$31
/*  f02a3dc:	44d9f800 */ 	ctc1	$t9,$31
/*  f02a3e0:	00000000 */ 	nop
/*  f02a3e4:	460024a4 */ 	cvt.w.s	$f18,$f4
/*  f02a3e8:	4459f800 */ 	cfc1	$t9,$31
/*  f02a3ec:	00000000 */ 	nop
/*  f02a3f0:	33390078 */ 	andi	$t9,$t9,0x78
/*  f02a3f4:	53200013 */ 	beqzl	$t9,.PF0f02a444
/*  f02a3f8:	44199000 */ 	mfc1	$t9,$f18
/*  f02a3fc:	44819000 */ 	mtc1	$at,$f18
/*  f02a400:	24190001 */ 	li	$t9,0x1
/*  f02a404:	46122481 */ 	sub.s	$f18,$f4,$f18
/*  f02a408:	44d9f800 */ 	ctc1	$t9,$31
/*  f02a40c:	00000000 */ 	nop
/*  f02a410:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f02a414:	4459f800 */ 	cfc1	$t9,$31
/*  f02a418:	00000000 */ 	nop
/*  f02a41c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f02a420:	17200005 */ 	bnez	$t9,.PF0f02a438
/*  f02a424:	00000000 */ 	nop
/*  f02a428:	44199000 */ 	mfc1	$t9,$f18
/*  f02a42c:	3c018000 */ 	lui	$at,0x8000
/*  f02a430:	10000007 */ 	b	.PF0f02a450
/*  f02a434:	0321c825 */ 	or	$t9,$t9,$at
.PF0f02a438:
/*  f02a438:	10000005 */ 	b	.PF0f02a450
/*  f02a43c:	2419ffff */ 	li	$t9,-1
/*  f02a440:	44199000 */ 	mfc1	$t9,$f18
.PF0f02a444:
/*  f02a444:	00000000 */ 	nop
/*  f02a448:	0720fffb */ 	bltz	$t9,.PF0f02a438
/*  f02a44c:	00000000 */ 	nop
.PF0f02a450:
/*  f02a450:	44cef800 */ 	ctc1	$t6,$31
/*  f02a454:	448f4000 */ 	mtc1	$t7,$f8
/*  f02a458:	a0790001 */ 	sb	$t9,0x1($v1)
/*  f02a45c:	05e10005 */ 	bgez	$t7,.PF0f02a474
/*  f02a460:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f02a464:	3c014f80 */ 	lui	$at,0x4f80
/*  f02a468:	44813000 */ 	mtc1	$at,$f6
/*  f02a46c:	00000000 */ 	nop
/*  f02a470:	46068400 */ 	add.s	$f16,$f16,$f6
.PF0f02a474:
/*  f02a474:	46028280 */ 	add.s	$f10,$f16,$f2
/*  f02a478:	240e0001 */ 	li	$t6,0x1
/*  f02a47c:	3c014f00 */ 	lui	$at,0x4f00
/*  f02a480:	4458f800 */ 	cfc1	$t8,$31
/*  f02a484:	44cef800 */ 	ctc1	$t6,$31
/*  f02a488:	00000000 */ 	nop
/*  f02a48c:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f02a490:	444ef800 */ 	cfc1	$t6,$31
/*  f02a494:	00000000 */ 	nop
/*  f02a498:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f02a49c:	51c00013 */ 	beqzl	$t6,.PF0f02a4ec
/*  f02a4a0:	440e2000 */ 	mfc1	$t6,$f4
/*  f02a4a4:	44812000 */ 	mtc1	$at,$f4
/*  f02a4a8:	240e0001 */ 	li	$t6,0x1
/*  f02a4ac:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f02a4b0:	44cef800 */ 	ctc1	$t6,$31
/*  f02a4b4:	00000000 */ 	nop
/*  f02a4b8:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f02a4bc:	444ef800 */ 	cfc1	$t6,$31
/*  f02a4c0:	00000000 */ 	nop
/*  f02a4c4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f02a4c8:	15c00005 */ 	bnez	$t6,.PF0f02a4e0
/*  f02a4cc:	00000000 */ 	nop
/*  f02a4d0:	440e2000 */ 	mfc1	$t6,$f4
/*  f02a4d4:	3c018000 */ 	lui	$at,0x8000
/*  f02a4d8:	10000007 */ 	b	.PF0f02a4f8
/*  f02a4dc:	01c17025 */ 	or	$t6,$t6,$at
.PF0f02a4e0:
/*  f02a4e0:	10000005 */ 	b	.PF0f02a4f8
/*  f02a4e4:	240effff */ 	li	$t6,-1
/*  f02a4e8:	440e2000 */ 	mfc1	$t6,$f4
.PF0f02a4ec:
/*  f02a4ec:	00000000 */ 	nop
/*  f02a4f0:	05c0fffb */ 	bltz	$t6,.PF0f02a4e0
/*  f02a4f4:	00000000 */ 	nop
.PF0f02a4f8:
/*  f02a4f8:	44d8f800 */ 	ctc1	$t8,$31
/*  f02a4fc:	10000006 */ 	b	.PF0f02a518
/*  f02a500:	a06e0002 */ 	sb	$t6,0x2($v1)
/*  f02a504:	24080200 */ 	li	$t0,0x200
.PF0f02a508:
/*  f02a508:	0000a825 */ 	move	$s5,$zero
/*  f02a50c:	00009825 */ 	move	$s3,$zero
/*  f02a510:	a7a80176 */ 	sh	$t0,0x176($sp)
/*  f02a514:	24140200 */ 	li	$s4,0x200
.PF0f02a518:
/*  f02a518:	27a60104 */ 	addiu	$a2,$sp,0x104
/*  f02a51c:	27a50180 */ 	addiu	$a1,$sp,0x180
.PF0f02a520:
/*  f02a520:	87a80176 */ 	lh	$t0,0x176($sp)
/*  f02a524:	00002025 */ 	move	$a0,$zero
/*  f02a528:	02001825 */ 	move	$v1,$s0
/*  f02a52c:	00c01025 */ 	move	$v0,$a2
.PF0f02a530:
/*  f02a530:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02a534:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f02a538:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02a53c:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f02a540:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f02a544:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f02a548:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f02a54c:	a878fff8 */ 	swl	$t8,-0x8($v1)
/*  f02a550:	b878fffb */ 	swr	$t8,-0x5($v1)
/*  f02a554:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02a558:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02a55c:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02a560:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f02a564:	01d10019 */ 	multu	$t6,$s1
/*  f02a568:	00007812 */ 	mflo	$t7
/*  f02a56c:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02a570:	87380000 */ 	lh	$t8,0x0($t9)
/*  f02a574:	a478fff4 */ 	sh	$t8,-0xc($v1)
/*  f02a578:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f02a57c:	01d10019 */ 	multu	$t6,$s1
/*  f02a580:	00007812 */ 	mflo	$t7
/*  f02a584:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02a588:	87380002 */ 	lh	$t8,0x2($t9)
/*  f02a58c:	a478fff6 */ 	sh	$t8,-0xa($v1)
/*  f02a590:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f02a594:	01d10019 */ 	multu	$t6,$s1
/*  f02a598:	00007812 */ 	mflo	$t7
/*  f02a59c:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02a5a0:	87380004 */ 	lh	$t8,0x4($t9)
/*  f02a5a4:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02a5a8:	1489ffe1 */ 	bne	$a0,$t1,.PF0f02a530
/*  f02a5ac:	a478fff8 */ 	sh	$t8,-0x8($v1)
/*  f02a5b0:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02a5b4:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02a5b8:	a6080014 */ 	sh	$t0,0x14($s0)
/*  f02a5bc:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02a5c0:	a6080020 */ 	sh	$t0,0x20($s0)
/*  f02a5c4:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02a5c8:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02a5cc:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02a5d0:	8fae01f0 */ 	lw	$t6,0x1f0($sp)
/*  f02a5d4:	3c190430 */ 	lui	$t9,0x430
/*  f02a5d8:	37390030 */ 	ori	$t9,$t9,0x30
/*  f02a5dc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f02a5e0:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02a5e4:	add90000 */ 	sw	$t9,0x0($t6)
/*  f02a5e8:	a7a80176 */ 	sh	$t0,0x176($sp)
/*  f02a5ec:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f02a5f0:	02002025 */ 	move	$a0,$s0
/*  f02a5f4:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02a5f8:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f02a5fc:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f02a600:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f02a604:	3c0fb100 */ 	lui	$t7,0xb100
/*  f02a608:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f02a60c:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02a610:	35ef0032 */ 	ori	$t7,$t7,0x32
/*  f02a614:	24192010 */ 	li	$t9,0x2010
/*  f02a618:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f02a61c:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02a620:	af190004 */ 	sw	$t9,0x4($t8)
/*  f02a624:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f02a628:	27b80164 */ 	addiu	$t8,$sp,0x164
/*  f02a62c:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f02a630:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02a634:	24090004 */ 	li	$t1,0x4
/*  f02a638:	14d8ffb9 */ 	bne	$a2,$t8,.PF0f02a520
/*  f02a63c:	26100030 */ 	addiu	$s0,$s0,0x30
/*  f02a640:	100004a4 */ 	b	.PF0f02b8d4
/*  f02a644:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f02a648:	2401fffe */ 	li	$at,-2
.PF0f02a64c:
/*  f02a64c:	150100d5 */ 	bne	$t0,$at,.PF0f02a9a4
/*  f02a650:	8fae01f4 */ 	lw	$t6,0x1f4($sp)
/*  f02a654:	8fa3020c */ 	lw	$v1,0x20c($sp)
/*  f02a658:	81c20011 */ 	lb	$v0,0x11($t6)
/*  f02a65c:	8faf0208 */ 	lw	$t7,0x208($sp)
/*  f02a660:	24040003 */ 	li	$a0,0x3
/*  f02a664:	0043082a */ 	slt	$at,$v0,$v1
/*  f02a668:	50200005 */ 	beqzl	$at,.PF0f02a680
/*  f02a66c:	448f3000 */ 	mtc1	$t7,$f6
/*  f02a670:	44806000 */ 	mtc1	$zero,$f12
/*  f02a674:	1000001f */ 	b	.PF0f02a6f4
/*  f02a678:	46006086 */ 	mov.s	$f2,$f12
/*  f02a67c:	448f3000 */ 	mtc1	$t7,$f6
.PF0f02a680:
/*  f02a680:	3c0141c8 */ 	lui	$at,0x41c8
/*  f02a684:	44814000 */ 	mtc1	$at,$f8
/*  f02a688:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f02a68c:	44829000 */ 	mtc1	$v0,$f18
/*  f02a690:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a694:	c4249b84 */ 	lwc1	$f4,-0x647c($at)
/*  f02a698:	3c014220 */ 	lui	$at,0x4220
/*  f02a69c:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f02a6a0:	44813000 */ 	mtc1	$at,$f6
/*  f02a6a4:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02a6a8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a6ac:	46104281 */ 	sub.s	$f10,$f8,$f16
/*  f02a6b0:	44838000 */ 	mtc1	$v1,$f16
/*  f02a6b4:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f02a6b8:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a6bc:	44998000 */ 	mtc1	$t9,$f16
/*  f02a6c0:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f02a6c4:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f02a6c8:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a6cc:	460c2480 */ 	add.s	$f18,$f4,$f12
/*  f02a6d0:	c4249b88 */ 	lwc1	$f4,-0x6478($at)
/*  f02a6d4:	44806000 */ 	mtc1	$zero,$f12
/*  f02a6d8:	46009183 */ 	div.s	$f6,$f18,$f0
/*  f02a6dc:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f02a6e0:	00000000 */ 	nop
/*  f02a6e4:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f02a6e8:	00000000 */ 	nop
/*  f02a6ec:	46121082 */ 	mul.s	$f2,$f2,$f18
/*  f02a6f0:	00000000 */ 	nop
.PF0f02a6f4:
/*  f02a6f4:	3c01437f */ 	lui	$at,0x437f
/*  f02a6f8:	44810000 */ 	mtc1	$at,$f0
/*  f02a6fc:	00000000 */ 	nop
/*  f02a700:	4602003c */ 	c.lt.s	$f0,$f2
/*  f02a704:	00000000 */ 	nop
/*  f02a708:	45020004 */ 	bc1fl	.PF0f02a71c
/*  f02a70c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f02a710:	10000006 */ 	b	.PF0f02a72c
/*  f02a714:	46000086 */ 	mov.s	$f2,$f0
/*  f02a718:	460c103c */ 	c.lt.s	$f2,$f12
.PF0f02a71c:
/*  f02a71c:	00000000 */ 	nop
/*  f02a720:	45000002 */ 	bc1f	.PF0f02a72c
/*  f02a724:	00000000 */ 	nop
/*  f02a728:	46006086 */ 	mov.s	$f2,$f12
.PF0f02a72c:
/*  f02a72c:	0fc5a253 */ 	jal	gfxAllocateColours
/*  f02a730:	e7a200ac */ 	swc1	$f2,0xac($sp)
/*  f02a734:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f02a738:	3c0f0708 */ 	lui	$t7,0x708
/*  f02a73c:	35ef000c */ 	ori	$t7,$t7,0xc
/*  f02a740:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f02a744:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02a748:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f02a74c:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02a750:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02a754:	00402025 */ 	move	$a0,$v0
/*  f02a758:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a75c:	c7a200ac */ 	lwc1	$f2,0xac($sp)
/*  f02a760:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f02a764:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f02a768:	8fa700e0 */ 	lw	$a3,0xe0($sp)
/*  f02a76c:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f02a770:	4600120d */ 	trunc.w.s	$f8,$f2
/*  f02a774:	2404001e */ 	li	$a0,0x1e
/*  f02a778:	a0600007 */ 	sb	$zero,0x7($v1)
/*  f02a77c:	a0650000 */ 	sb	$a1,0x0($v1)
/*  f02a780:	44184000 */ 	mfc1	$t8,$f8
/*  f02a784:	a0650004 */ 	sb	$a1,0x4($v1)
/*  f02a788:	a0660001 */ 	sb	$a2,0x1($v1)
/*  f02a78c:	a0660005 */ 	sb	$a2,0x5($v1)
/*  f02a790:	a0670002 */ 	sb	$a3,0x2($v1)
/*  f02a794:	a0670006 */ 	sb	$a3,0x6($v1)
/*  f02a798:	0fc5a239 */ 	jal	gfxAllocateVertices
/*  f02a79c:	a0780003 */ 	sb	$t8,0x3($v1)
/*  f02a7a0:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f02a7a4:	02747021 */ 	addu	$t6,$s3,$s4
/*  f02a7a8:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f02a7ac:	02abc821 */ 	addu	$t9,$s5,$t3
/*  f02a7b0:	0019c043 */ 	sra	$t8,$t9,0x1
/*  f02a7b4:	00408025 */ 	move	$s0,$v0
/*  f02a7b8:	afb80040 */ 	sw	$t8,0x40($sp)
/*  f02a7bc:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f02a7c0:	27a60104 */ 	addiu	$a2,$sp,0x104
/*  f02a7c4:	240c0004 */ 	li	$t4,0x4
/*  f02a7c8:	24090004 */ 	li	$t1,0x4
/*  f02a7cc:	27a50180 */ 	addiu	$a1,$sp,0x180
.PF0f02a7d0:
/*  f02a7d0:	00002025 */ 	move	$a0,$zero
/*  f02a7d4:	02001825 */ 	move	$v1,$s0
/*  f02a7d8:	00c01025 */ 	move	$v0,$a2
.PF0f02a7dc:
/*  f02a7dc:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02a7e0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f02a7e4:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02a7e8:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f02a7ec:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f02a7f0:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02a7f4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f02a7f8:	a879fff8 */ 	swl	$t9,-0x8($v1)
/*  f02a7fc:	b879fffb */ 	swr	$t9,-0x5($v1)
/*  f02a800:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02a804:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02a808:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02a80c:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f02a810:	03110019 */ 	multu	$t8,$s1
/*  f02a814:	00007812 */ 	mflo	$t7
/*  f02a818:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f02a81c:	85d90000 */ 	lh	$t9,0x0($t6)
/*  f02a820:	a479fff4 */ 	sh	$t9,-0xc($v1)
/*  f02a824:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f02a828:	03110019 */ 	multu	$t8,$s1
/*  f02a82c:	00007812 */ 	mflo	$t7
/*  f02a830:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f02a834:	85d90002 */ 	lh	$t9,0x2($t6)
/*  f02a838:	a479fff6 */ 	sh	$t9,-0xa($v1)
/*  f02a83c:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f02a840:	03110019 */ 	multu	$t8,$s1
/*  f02a844:	00007812 */ 	mflo	$t7
/*  f02a848:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f02a84c:	85d90004 */ 	lh	$t9,0x4($t6)
/*  f02a850:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02a854:	1489ffe1 */ 	bne	$a0,$t1,.PF0f02a7dc
/*  f02a858:	a479fff8 */ 	sh	$t9,-0x8($v1)
/*  f02a85c:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02a860:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02a864:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02a868:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02a86c:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02a870:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02a874:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02a878:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02a87c:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02a880:	860e0024 */ 	lh	$t6,0x24($s0)
/*  f02a884:	86190000 */ 	lh	$t9,0x0($s0)
/*  f02a888:	aa010030 */ 	swl	$at,0x30($s0)
/*  f02a88c:	ba010033 */ 	swr	$at,0x33($s0)
/*  f02a890:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02a894:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a898:	86190018 */ 	lh	$t9,0x18($s0)
/*  f02a89c:	aa0f0034 */ 	swl	$t7,0x34($s0)
/*  f02a8a0:	ba0f0037 */ 	swr	$t7,0x37($s0)
/*  f02a8a4:	860f000c */ 	lh	$t7,0xc($s0)
/*  f02a8a8:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02a8ac:	02002025 */ 	move	$a0,$s0
/*  f02a8b0:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f02a8b4:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a8b8:	86190002 */ 	lh	$t9,0x2($s0)
/*  f02a8bc:	860e0026 */ 	lh	$t6,0x26($s0)
/*  f02a8c0:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02a8c4:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f02a8c8:	860f000e */ 	lh	$t7,0xe($s0)
/*  f02a8cc:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a8d0:	8619001a */ 	lh	$t9,0x1a($s0)
/*  f02a8d4:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f02a8d8:	aa010038 */ 	swl	$at,0x38($s0)
/*  f02a8dc:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a8e0:	86190004 */ 	lh	$t9,0x4($s0)
/*  f02a8e4:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f02a8e8:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02a8ec:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f02a8f0:	860f0010 */ 	lh	$t7,0x10($s0)
/*  f02a8f4:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a8f8:	8619001c */ 	lh	$t9,0x1c($s0)
/*  f02a8fc:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f02a900:	ba01003b */ 	swr	$at,0x3b($s0)
/*  f02a904:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a908:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02a90c:	a60f0034 */ 	sh	$t7,0x34($s0)
/*  f02a910:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f02a914:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02a918:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f02a91c:	a20c0037 */ 	sb	$t4,0x37($s0)
/*  f02a920:	3c0e0440 */ 	lui	$t6,0x440
/*  f02a924:	a619003a */ 	sh	$t9,0x3a($s0)
/*  f02a928:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02a92c:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02a930:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02a934:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02a938:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f02a93c:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f02a940:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f02a944:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02a948:	afb800a4 */ 	sw	$t8,0xa4($sp)
/*  f02a94c:	8fa700a4 */ 	lw	$a3,0xa4($sp)
/*  f02a950:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f02a954:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f02a958:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f02a95c:	8fb901f0 */ 	lw	$t9,0x1f0($sp)
/*  f02a960:	3c0fb100 */ 	lui	$t7,0xb100
/*  f02a964:	3c0e0332 */ 	lui	$t6,0x332
/*  f02a968:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f02a96c:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f02a970:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02a974:	35ef4444 */ 	ori	$t7,$t7,0x4444
/*  f02a978:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f02a97c:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f02a980:	27b90164 */ 	addiu	$t9,$sp,0x164
/*  f02a984:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f02a988:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02a98c:	24090004 */ 	li	$t1,0x4
/*  f02a990:	240c0004 */ 	li	$t4,0x4
/*  f02a994:	14d9ff8e */ 	bne	$a2,$t9,.PF0f02a7d0
/*  f02a998:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f02a99c:	100003cd */ 	b	.PF0f02b8d4
/*  f02a9a0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PF0f02a9a4:
/*  f02a9a4:	05010130 */ 	bgez	$t0,.PF0f02ae68
/*  f02a9a8:	8fae01f8 */ 	lw	$t6,0x1f8($sp)
/*  f02a9ac:	0fc5a239 */ 	jal	gfxAllocateVertices
/*  f02a9b0:	2404000c */ 	li	$a0,0xc
/*  f02a9b4:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02a9b8:	2401ffff */ 	li	$at,-1
/*  f02a9bc:	00408025 */ 	move	$s0,$v0
/*  f02a9c0:	15010035 */ 	bne	$t0,$at,.PF0f02aa98
/*  f02a9c4:	8fb801f4 */ 	lw	$t8,0x1f4($sp)
/*  f02a9c8:	3c02800a */ 	lui	$v0,0x800a
/*  f02a9cc:	8c42a518 */ 	lw	$v0,-0x5ae8($v0)
/*  f02a9d0:	8f03000c */ 	lw	$v1,0xc($t8)
/*  f02a9d4:	00002825 */ 	move	$a1,$zero
/*  f02a9d8:	24040001 */ 	li	$a0,0x1
/*  f02a9dc:	00437823 */ 	subu	$t7,$v0,$v1
/*  f02a9e0:	29e10043 */ 	slti	$at,$t7,0x43
/*  f02a9e4:	10200016 */ 	beqz	$at,.PF0f02aa40
/*  f02a9e8:	00627023 */ 	subu	$t6,$v1,$v0
/*  f02a9ec:	25d90042 */ 	addiu	$t9,$t6,0x42
/*  f02a9f0:	44993000 */ 	mtc1	$t9,$f6
/*  f02a9f4:	8fb80210 */ 	lw	$t8,0x210($sp)
/*  f02a9f8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a9fc:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f02aa00:	44982000 */ 	mtc1	$t8,$f4
/*  f02aa04:	c42a9b8c */ 	lwc1	$f10,-0x6474($at)
/*  f02aa08:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02aa0c:	c4289b90 */ 	lwc1	$f8,-0x6470($at)
/*  f02aa10:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f02aa14:	460a8002 */ 	mul.s	$f0,$f16,$f10
/*  f02aa18:	00000000 */ 	nop
/*  f02aa1c:	46089182 */ 	mul.s	$f6,$f18,$f8
/*  f02aa20:	00000000 */ 	nop
/*  f02aa24:	46060002 */ 	mul.s	$f0,$f0,$f6
/*  f02aa28:	4600040d */ 	trunc.w.s	$f16,$f0
/*  f02aa2c:	44058000 */ 	mfc1	$a1,$f16
/*  f02aa30:	00000000 */ 	nop
/*  f02aa34:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f02aa38:	10000001 */ 	b	.PF0f02aa40
/*  f02aa3c:	01c02825 */ 	move	$a1,$t6
.PF0f02aa40:
/*  f02aa40:	0fc5a253 */ 	jal	gfxAllocateColours
/*  f02aa44:	a3a5017f */ 	sb	$a1,0x17f($sp)
/*  f02aa48:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02aa4c:	3c0f0700 */ 	lui	$t7,0x700
/*  f02aa50:	35ef0004 */ 	ori	$t7,$t7,0x4
/*  f02aa54:	26380008 */ 	addiu	$t8,$s1,0x8
/*  f02aa58:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f02aa5c:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f02aa60:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02aa64:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02aa68:	00402025 */ 	move	$a0,$v0
/*  f02aa6c:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02aa70:	93a5017f */ 	lbu	$a1,0x17f($sp)
/*  f02aa74:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02aa78:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f02aa7c:	a06e0000 */ 	sb	$t6,0x0($v1)
/*  f02aa80:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f02aa84:	a0790001 */ 	sb	$t9,0x1($v1)
/*  f02aa88:	8fb800f8 */ 	lw	$t8,0xf8($sp)
/*  f02aa8c:	a0650003 */ 	sb	$a1,0x3($v1)
/*  f02aa90:	10000053 */ 	b	.PF0f02abe0
/*  f02aa94:	a0780002 */ 	sb	$t8,0x2($v1)
.PF0f02aa98:
/*  f02aa98:	2401fffe */ 	li	$at,-2
/*  f02aa9c:	15010050 */ 	bne	$t0,$at,.PF0f02abe0
/*  f02aaa0:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f02aaa4:	8fa3020c */ 	lw	$v1,0x20c($sp)
/*  f02aaa8:	81e20011 */ 	lb	$v0,0x11($t7)
/*  f02aaac:	8fae0208 */ 	lw	$t6,0x208($sp)
/*  f02aab0:	24040001 */ 	li	$a0,0x1
/*  f02aab4:	0043082a */ 	slt	$at,$v0,$v1
/*  f02aab8:	50200005 */ 	beqzl	$at,.PF0f02aad0
/*  f02aabc:	448e9000 */ 	mtc1	$t6,$f18
/*  f02aac0:	44806000 */ 	mtc1	$zero,$f12
/*  f02aac4:	10000021 */ 	b	.PF0f02ab4c
/*  f02aac8:	46006086 */ 	mov.s	$f2,$f12
/*  f02aacc:	448e9000 */ 	mtc1	$t6,$f18
.PF0f02aad0:
/*  f02aad0:	3c0141c8 */ 	lui	$at,0x41c8
/*  f02aad4:	44812000 */ 	mtc1	$at,$f4
/*  f02aad8:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f02aadc:	44825000 */ 	mtc1	$v0,$f10
/*  f02aae0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02aae4:	c4309b94 */ 	lwc1	$f16,-0x646c($at)
/*  f02aae8:	3c014220 */ 	lui	$at,0x4220
/*  f02aaec:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f02aaf0:	44819000 */ 	mtc1	$at,$f18
/*  f02aaf4:	3c013f80 */ 	lui	$at,0x3f80
/*  f02aaf8:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02aafc:	44806000 */ 	mtc1	$zero,$f12
/*  f02ab00:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f02ab04:	44834000 */ 	mtc1	$v1,$f8
/*  f02ab08:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f02ab0c:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f02ab10:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f02ab14:	44815000 */ 	mtc1	$at,$f10
/*  f02ab18:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02ab1c:	46060401 */ 	sub.s	$f16,$f0,$f6
/*  f02ab20:	44993000 */ 	mtc1	$t9,$f6
/*  f02ab24:	460a8480 */ 	add.s	$f18,$f16,$f10
/*  f02ab28:	c42a9b98 */ 	lwc1	$f10,-0x6468($at)
/*  f02ab2c:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f02ab30:	46009203 */ 	div.s	$f8,$f18,$f0
/*  f02ab34:	46082082 */ 	mul.s	$f2,$f4,$f8
/*  f02ab38:	00000000 */ 	nop
/*  f02ab3c:	460a8482 */ 	mul.s	$f18,$f16,$f10
/*  f02ab40:	00000000 */ 	nop
/*  f02ab44:	46121082 */ 	mul.s	$f2,$f2,$f18
/*  f02ab48:	00000000 */ 	nop
.PF0f02ab4c:
/*  f02ab4c:	3c01437f */ 	lui	$at,0x437f
/*  f02ab50:	44810000 */ 	mtc1	$at,$f0
/*  f02ab54:	00000000 */ 	nop
/*  f02ab58:	4602003c */ 	c.lt.s	$f0,$f2
/*  f02ab5c:	00000000 */ 	nop
/*  f02ab60:	45020004 */ 	bc1fl	.PF0f02ab74
/*  f02ab64:	460c103c */ 	c.lt.s	$f2,$f12
/*  f02ab68:	10000006 */ 	b	.PF0f02ab84
/*  f02ab6c:	46000086 */ 	mov.s	$f2,$f0
/*  f02ab70:	460c103c */ 	c.lt.s	$f2,$f12
.PF0f02ab74:
/*  f02ab74:	00000000 */ 	nop
/*  f02ab78:	45000002 */ 	bc1f	.PF0f02ab84
/*  f02ab7c:	00000000 */ 	nop
/*  f02ab80:	46006086 */ 	mov.s	$f2,$f12
.PF0f02ab84:
/*  f02ab84:	0fc5a253 */ 	jal	gfxAllocateColours
/*  f02ab88:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f02ab8c:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02ab90:	3c0e0700 */ 	lui	$t6,0x700
/*  f02ab94:	35ce0004 */ 	ori	$t6,$t6,0x4
/*  f02ab98:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f02ab9c:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02aba0:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f02aba4:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02aba8:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02abac:	00402025 */ 	move	$a0,$v0
/*  f02abb0:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02abb4:	c7a20094 */ 	lwc1	$f2,0x94($sp)
/*  f02abb8:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02abbc:	8fb900e8 */ 	lw	$t9,0xe8($sp)
/*  f02abc0:	4600110d */ 	trunc.w.s	$f4,$f2
/*  f02abc4:	a0790000 */ 	sb	$t9,0x0($v1)
/*  f02abc8:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f02abcc:	44192000 */ 	mfc1	$t9,$f4
/*  f02abd0:	a0780001 */ 	sb	$t8,0x1($v1)
/*  f02abd4:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f02abd8:	a0790003 */ 	sb	$t9,0x3($v1)
/*  f02abdc:	a06f0002 */ 	sb	$t7,0x2($v1)
.PF0f02abe0:
/*  f02abe0:	02001825 */ 	move	$v1,$s0
/*  f02abe4:	27a20180 */ 	addiu	$v0,$sp,0x180
/*  f02abe8:	27a401b0 */ 	addiu	$a0,$sp,0x1b0
.PF0f02abec:
/*  f02abec:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02abf0:	24420006 */ 	addiu	$v0,$v0,0x6
/*  f02abf4:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02abf8:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f02abfc:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f02ac00:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02ac04:	a86ffff8 */ 	swl	$t7,-0x8($v1)
/*  f02ac08:	b86ffffb */ 	swr	$t7,-0x5($v1)
/*  f02ac0c:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02ac10:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02ac14:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02ac18:	844efffa */ 	lh	$t6,-0x6($v0)
/*  f02ac1c:	0044082b */ 	sltu	$at,$v0,$a0
/*  f02ac20:	a46efff4 */ 	sh	$t6,-0xc($v1)
/*  f02ac24:	8459fffc */ 	lh	$t9,-0x4($v0)
/*  f02ac28:	a479fff6 */ 	sh	$t9,-0xa($v1)
/*  f02ac2c:	8458fffe */ 	lh	$t8,-0x2($v0)
/*  f02ac30:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02ac34:	1420ffed */ 	bnez	$at,.PF0f02abec
/*  f02ac38:	a478fff8 */ 	sh	$t8,-0x8($v1)
/*  f02ac3c:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02ac40:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02ac44:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f02ac48:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02ac4c:	a6140046 */ 	sh	$s4,0x46($s0)
/*  f02ac50:	a6150038 */ 	sh	$s5,0x38($s0)
/*  f02ac54:	a614003a */ 	sh	$s4,0x3a($s0)
/*  f02ac58:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02ac5c:	a613002e */ 	sh	$s3,0x2e($s0)
/*  f02ac60:	a6130022 */ 	sh	$s3,0x22($s0)
/*  f02ac64:	a6140052 */ 	sh	$s4,0x52($s0)
/*  f02ac68:	a615005c */ 	sh	$s5,0x5c($s0)
/*  f02ac6c:	a614005e */ 	sh	$s4,0x5e($s0)
/*  f02ac70:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02ac74:	a60b0044 */ 	sh	$t3,0x44($s0)
/*  f02ac78:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02ac7c:	a60b0050 */ 	sh	$t3,0x50($s0)
/*  f02ac80:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02ac84:	02002025 */ 	move	$a0,$s0
/*  f02ac88:	aa010060 */ 	swl	$at,0x60($s0)
/*  f02ac8c:	ba010063 */ 	swr	$at,0x63($s0)
/*  f02ac90:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f02ac94:	aa0e0064 */ 	swl	$t6,0x64($s0)
/*  f02ac98:	ba0e0067 */ 	swr	$t6,0x67($s0)
/*  f02ac9c:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02aca0:	aa010068 */ 	swl	$at,0x68($s0)
/*  f02aca4:	ba01006b */ 	swr	$at,0x6b($s0)
/*  f02aca8:	87b9018c */ 	lh	$t9,0x18c($sp)
/*  f02acac:	a6190060 */ 	sh	$t9,0x60($s0)
/*  f02acb0:	87b8018e */ 	lh	$t8,0x18e($sp)
/*  f02acb4:	a6180062 */ 	sh	$t8,0x62($s0)
/*  f02acb8:	87af0190 */ 	lh	$t7,0x190($sp)
/*  f02acbc:	a2000067 */ 	sb	$zero,0x67($s0)
/*  f02acc0:	a60f0064 */ 	sh	$t7,0x64($s0)
/*  f02acc4:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02acc8:	aa01006c */ 	swl	$at,0x6c($s0)
/*  f02accc:	ba01006f */ 	swr	$at,0x6f($s0)
/*  f02acd0:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02acd4:	aa190070 */ 	swl	$t9,0x70($s0)
/*  f02acd8:	ba190073 */ 	swr	$t9,0x73($s0)
/*  f02acdc:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02ace0:	aa010074 */ 	swl	$at,0x74($s0)
/*  f02ace4:	ba010077 */ 	swr	$at,0x77($s0)
/*  f02ace8:	87b80192 */ 	lh	$t8,0x192($sp)
/*  f02acec:	a618006c */ 	sh	$t8,0x6c($s0)
/*  f02acf0:	87af0194 */ 	lh	$t7,0x194($sp)
/*  f02acf4:	a60f006e */ 	sh	$t7,0x6e($s0)
/*  f02acf8:	87ae0196 */ 	lh	$t6,0x196($sp)
/*  f02acfc:	a2000073 */ 	sb	$zero,0x73($s0)
/*  f02ad00:	a6150068 */ 	sh	$s5,0x68($s0)
/*  f02ad04:	a614006a */ 	sh	$s4,0x6a($s0)
/*  f02ad08:	a6140076 */ 	sh	$s4,0x76($s0)
/*  f02ad0c:	a60b0074 */ 	sh	$t3,0x74($s0)
/*  f02ad10:	a60e0070 */ 	sh	$t6,0x70($s0)
/*  f02ad14:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02ad18:	aa010078 */ 	swl	$at,0x78($s0)
/*  f02ad1c:	ba01007b */ 	swr	$at,0x7b($s0)
/*  f02ad20:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f02ad24:	aa18007c */ 	swl	$t8,0x7c($s0)
/*  f02ad28:	ba18007f */ 	swr	$t8,0x7f($s0)
/*  f02ad2c:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02ad30:	aa010080 */ 	swl	$at,0x80($s0)
/*  f02ad34:	ba010083 */ 	swr	$at,0x83($s0)
/*  f02ad38:	87af01a4 */ 	lh	$t7,0x1a4($sp)
/*  f02ad3c:	a60f0078 */ 	sh	$t7,0x78($s0)
/*  f02ad40:	87ae01a6 */ 	lh	$t6,0x1a6($sp)
/*  f02ad44:	a60e007a */ 	sh	$t6,0x7a($s0)
/*  f02ad48:	87b901a8 */ 	lh	$t9,0x1a8($sp)
/*  f02ad4c:	a200007f */ 	sb	$zero,0x7f($s0)
/*  f02ad50:	a619007c */ 	sh	$t9,0x7c($s0)
/*  f02ad54:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02ad58:	aa010084 */ 	swl	$at,0x84($s0)
/*  f02ad5c:	ba010087 */ 	swr	$at,0x87($s0)
/*  f02ad60:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02ad64:	aa0f0088 */ 	swl	$t7,0x88($s0)
/*  f02ad68:	ba0f008b */ 	swr	$t7,0x8b($s0)
/*  f02ad6c:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02ad70:	aa01008c */ 	swl	$at,0x8c($s0)
/*  f02ad74:	ba01008f */ 	swr	$at,0x8f($s0)
/*  f02ad78:	87ae01aa */ 	lh	$t6,0x1aa($sp)
/*  f02ad7c:	a60e0084 */ 	sh	$t6,0x84($s0)
/*  f02ad80:	87b901ac */ 	lh	$t9,0x1ac($sp)
/*  f02ad84:	a6190086 */ 	sh	$t9,0x86($s0)
/*  f02ad88:	87b801ae */ 	lh	$t8,0x1ae($sp)
/*  f02ad8c:	a200008b */ 	sb	$zero,0x8b($s0)
/*  f02ad90:	a6150080 */ 	sh	$s5,0x80($s0)
/*  f02ad94:	a6130082 */ 	sh	$s3,0x82($s0)
/*  f02ad98:	a613008e */ 	sh	$s3,0x8e($s0)
/*  f02ad9c:	a60b008c */ 	sh	$t3,0x8c($s0)
/*  f02ada0:	a6180088 */ 	sh	$t8,0x88($s0)
/*  f02ada4:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02ada8:	3c1904b0 */ 	lui	$t9,0x4b0
/*  f02adac:	37390090 */ 	ori	$t9,$t9,0x90
/*  f02adb0:	262e0008 */ 	addiu	$t6,$s1,0x8
/*  f02adb4:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02adb8:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02adbc:	ae390000 */ 	sw	$t9,0x0($s1)
/*  f02adc0:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02adc4:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02adc8:	3c0eb100 */ 	lui	$t6,0xb100
/*  f02adcc:	3c194b5b */ 	lui	$t9,0x4b5b
/*  f02add0:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02add4:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02add8:	37399010 */ 	ori	$t9,$t9,0x9010
/*  f02addc:	35cea489 */ 	ori	$t6,$t6,0xa489
/*  f02ade0:	27a30124 */ 	addiu	$v1,$sp,0x124
/*  f02ade4:	27a60164 */ 	addiu	$a2,$sp,0x164
/*  f02ade8:	3c05b100 */ 	lui	$a1,0xb100
/*  f02adec:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f02adf0:	af190004 */ 	sw	$t9,0x4($t8)
.PF0f02adf4:
/*  f02adf4:	8fa201f0 */ 	lw	$v0,0x1f0($sp)
/*  f02adf8:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f02adfc:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f02ae00:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02ae04:	8c6efff8 */ 	lw	$t6,-0x8($v1)
/*  f02ae08:	8c6ffffc */ 	lw	$t7,-0x4($v1)
/*  f02ae0c:	31d9000f */ 	andi	$t9,$t6,0xf
/*  f02ae10:	0325c025 */ 	or	$t8,$t9,$a1
/*  f02ae14:	31ee000f */ 	andi	$t6,$t7,0xf
/*  f02ae18:	000ec900 */ 	sll	$t9,$t6,0x4
/*  f02ae1c:	03197825 */ 	or	$t7,$t8,$t9
/*  f02ae20:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f02ae24:	8c78fff8 */ 	lw	$t8,-0x8($v1)
/*  f02ae28:	8c64fff0 */ 	lw	$a0,-0x10($v1)
/*  f02ae2c:	3319000f */ 	andi	$t9,$t8,0xf
/*  f02ae30:	308e000f */ 	andi	$t6,$a0,0xf
/*  f02ae34:	01c02025 */ 	move	$a0,$t6
/*  f02ae38:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f02ae3c:	01cf7025 */ 	or	$t6,$t6,$t7
/*  f02ae40:	8c6ffff4 */ 	lw	$t7,-0xc($v1)
/*  f02ae44:	0004c200 */ 	sll	$t8,$a0,0x8
/*  f02ae48:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f02ae4c:	31ee000f */ 	andi	$t6,$t7,0xf
/*  f02ae50:	000ec100 */ 	sll	$t8,$t6,0x4
/*  f02ae54:	03387825 */ 	or	$t7,$t9,$t8
/*  f02ae58:	1466ffe6 */ 	bne	$v1,$a2,.PF0f02adf4
/*  f02ae5c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f02ae60:	1000029c */ 	b	.PF0f02b8d4
/*  f02ae64:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PF0f02ae68:
/*  f02ae68:	91c40000 */ 	lbu	$a0,0x0($t6)
/*  f02ae6c:	24010001 */ 	li	$at,0x1
/*  f02ae70:	10810005 */ 	beq	$a0,$at,.PF0f02ae88
/*  f02ae74:	24090004 */ 	li	$t1,0x4
/*  f02ae78:	11240003 */ 	beq	$t1,$a0,.PF0f02ae88
/*  f02ae7c:	24010002 */ 	li	$at,0x2
/*  f02ae80:	5481000b */ 	bnel	$a0,$at,.PF0f02aeb0
/*  f02ae84:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
.PF0f02ae88:
/*  f02ae88:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
/*  f02ae8c:	240500ff */ 	li	$a1,0xff
/*  f02ae90:	8f380004 */ 	lw	$t8,0x4($t9)
/*  f02ae94:	8f0f0010 */ 	lw	$t7,0x10($t8)
/*  f02ae98:	31ee1000 */ 	andi	$t6,$t7,0x1000
/*  f02ae9c:	51c00004 */ 	beqzl	$t6,.PF0f02aeb0
/*  f02aea0:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
/*  f02aea4:	10000023 */ 	b	.PF0f02af34
/*  f02aea8:	240600ff */ 	li	$a2,0xff
/*  f02aeac:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
.PF0f02aeb0:
/*  f02aeb0:	3c02800a */ 	lui	$v0,0x800a
/*  f02aeb4:	8c42a518 */ 	lw	$v0,-0x5ae8($v0)
/*  f02aeb8:	8f23000c */ 	lw	$v1,0xc($t9)
/*  f02aebc:	00002825 */ 	move	$a1,$zero
/*  f02aec0:	00003025 */ 	move	$a2,$zero
/*  f02aec4:	0043c023 */ 	subu	$t8,$v0,$v1
/*  f02aec8:	2b010043 */ 	slti	$at,$t8,0x43
/*  f02aecc:	10200019 */ 	beqz	$at,.PF0f02af34
/*  f02aed0:	00627823 */ 	subu	$t7,$v1,$v0
/*  f02aed4:	25ee0042 */ 	addiu	$t6,$t7,0x42
/*  f02aed8:	448e4000 */ 	mtc1	$t6,$f8
/*  f02aedc:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02aee0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02aee4:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f02aee8:	44995000 */ 	mtc1	$t9,$f10
/*  f02aeec:	c4309b9c */ 	lwc1	$f16,-0x6464($at)
/*  f02aef0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02aef4:	c4249ba0 */ 	lwc1	$f4,-0x6460($at)
/*  f02aef8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f02aefc:	46103302 */ 	mul.s	$f12,$f6,$f16
/*  f02af00:	00000000 */ 	nop
/*  f02af04:	46049082 */ 	mul.s	$f2,$f18,$f4
/*  f02af08:	00000000 */ 	nop
/*  f02af0c:	46026002 */ 	mul.s	$f0,$f12,$f2
/*  f02af10:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f02af14:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f02af18:	44054000 */ 	mfc1	$a1,$f8
/*  f02af1c:	44063000 */ 	mfc1	$a2,$f6
/*  f02af20:	30af00ff */ 	andi	$t7,$a1,0xff
/*  f02af24:	01e02825 */ 	move	$a1,$t7
/*  f02af28:	30d900ff */ 	andi	$t9,$a2,0xff
/*  f02af2c:	10000001 */ 	b	.PF0f02af34
/*  f02af30:	03203025 */ 	move	$a2,$t9
.PF0f02af34:
/*  f02af34:	24040005 */ 	li	$a0,0x5
/*  f02af38:	a3a5017f */ 	sb	$a1,0x17f($sp)
/*  f02af3c:	a3a6017e */ 	sb	$a2,0x17e($sp)
/*  f02af40:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02af44:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02af48:	0fc5a253 */ 	jal	gfxAllocateColours
/*  f02af4c:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02af50:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f02af54:	3c0e0710 */ 	lui	$t6,0x710
/*  f02af58:	35ce0014 */ 	ori	$t6,$t6,0x14
/*  f02af5c:	260f0008 */ 	addiu	$t7,$s0,0x8
/*  f02af60:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02af64:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f02af68:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02af6c:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02af70:	00402025 */ 	move	$a0,$v0
/*  f02af74:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02af78:	93a5017f */ 	lbu	$a1,0x17f($sp)
/*  f02af7c:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02af80:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02af84:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02af88:	93a6017e */ 	lbu	$a2,0x17e($sp)
/*  f02af8c:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f02af90:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f02af94:	2404001e */ 	li	$a0,0x1e
/*  f02af98:	a0790000 */ 	sb	$t9,0x0($v1)
/*  f02af9c:	8fb800fc */ 	lw	$t8,0xfc($sp)
/*  f02afa0:	a0780001 */ 	sb	$t8,0x1($v1)
/*  f02afa4:	8faf00f8 */ 	lw	$t7,0xf8($sp)
/*  f02afa8:	a0650003 */ 	sb	$a1,0x3($v1)
/*  f02afac:	a0650007 */ 	sb	$a1,0x7($v1)
/*  f02afb0:	a065000b */ 	sb	$a1,0xb($v1)
/*  f02afb4:	a0670004 */ 	sb	$a3,0x4($v1)
/*  f02afb8:	a0670008 */ 	sb	$a3,0x8($v1)
/*  f02afbc:	a06a0005 */ 	sb	$t2,0x5($v1)
/*  f02afc0:	a06a0009 */ 	sb	$t2,0x9($v1)
/*  f02afc4:	a06b0006 */ 	sb	$t3,0x6($v1)
/*  f02afc8:	a06b000a */ 	sb	$t3,0xa($v1)
/*  f02afcc:	a06f0002 */ 	sb	$t7,0x2($v1)
/*  f02afd0:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f02afd4:	24e70046 */ 	addiu	$a3,$a3,0x46
/*  f02afd8:	254a0046 */ 	addiu	$t2,$t2,0x46
/*  f02afdc:	25d90064 */ 	addiu	$t9,$t6,0x64
/*  f02afe0:	2b210100 */ 	slti	$at,$t9,0x100
/*  f02afe4:	14200003 */ 	bnez	$at,.PF0f02aff4
/*  f02afe8:	afb90100 */ 	sw	$t9,0x100($sp)
/*  f02afec:	240c00ff */ 	li	$t4,0xff
/*  f02aff0:	afac0100 */ 	sw	$t4,0x100($sp)
.PF0f02aff4:
/*  f02aff4:	8fb80100 */ 	lw	$t8,0x100($sp)
/*  f02aff8:	256b0046 */ 	addiu	$t3,$t3,0x46
/*  f02affc:	a078000c */ 	sb	$t8,0xc($v1)
/*  f02b000:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f02b004:	25ee0064 */ 	addiu	$t6,$t7,0x64
/*  f02b008:	29c10100 */ 	slti	$at,$t6,0x100
/*  f02b00c:	14200003 */ 	bnez	$at,.PF0f02b01c
/*  f02b010:	afae00fc */ 	sw	$t6,0xfc($sp)
/*  f02b014:	240d00ff */ 	li	$t5,0xff
/*  f02b018:	afad00fc */ 	sw	$t5,0xfc($sp)
.PF0f02b01c:
/*  f02b01c:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f02b020:	a079000d */ 	sb	$t9,0xd($v1)
/*  f02b024:	8fb800f8 */ 	lw	$t8,0xf8($sp)
/*  f02b028:	270f0064 */ 	addiu	$t7,$t8,0x64
/*  f02b02c:	29e10100 */ 	slti	$at,$t7,0x100
/*  f02b030:	14200003 */ 	bnez	$at,.PF0f02b040
/*  f02b034:	afaf00f8 */ 	sw	$t7,0xf8($sp)
/*  f02b038:	241f00ff */ 	li	$ra,0xff
/*  f02b03c:	afbf00f8 */ 	sw	$ra,0xf8($sp)
.PF0f02b040:
/*  f02b040:	8fae00f8 */ 	lw	$t6,0xf8($sp)
/*  f02b044:	28e10100 */ 	slti	$at,$a3,0x100
/*  f02b048:	a066000f */ 	sb	$a2,0xf($v1)
/*  f02b04c:	14200002 */ 	bnez	$at,.PF0f02b058
/*  f02b050:	a06e000e */ 	sb	$t6,0xe($v1)
/*  f02b054:	240700ff */ 	li	$a3,0xff
.PF0f02b058:
/*  f02b058:	29410100 */ 	slti	$at,$t2,0x100
/*  f02b05c:	14200002 */ 	bnez	$at,.PF0f02b068
/*  f02b060:	a0670010 */ 	sb	$a3,0x10($v1)
/*  f02b064:	240a00ff */ 	li	$t2,0xff
.PF0f02b068:
/*  f02b068:	29610100 */ 	slti	$at,$t3,0x100
/*  f02b06c:	14200002 */ 	bnez	$at,.PF0f02b078
/*  f02b070:	a06a0011 */ 	sb	$t2,0x11($v1)
/*  f02b074:	240b00ff */ 	li	$t3,0xff
.PF0f02b078:
/*  f02b078:	a06b0012 */ 	sb	$t3,0x12($v1)
/*  f02b07c:	0fc5a239 */ 	jal	gfxAllocateVertices
/*  f02b080:	a0650013 */ 	sb	$a1,0x13($v1)
/*  f02b084:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02b088:	27b80104 */ 	addiu	$t8,$sp,0x104
/*  f02b08c:	00408025 */ 	move	$s0,$v0
/*  f02b090:	0008c900 */ 	sll	$t9,$t0,0x4
/*  f02b094:	03382821 */ 	addu	$a1,$t9,$t8
/*  f02b098:	00a03825 */ 	move	$a3,$a1
/*  f02b09c:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f02b0a0:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02b0a4:	00002025 */ 	move	$a0,$zero
/*  f02b0a8:	00401825 */ 	move	$v1,$v0
.PF0f02b0ac:
/*  f02b0ac:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b0b0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f02b0b4:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f02b0b8:	a8610000 */ 	swl	$at,0x0($v1)
/*  f02b0bc:	b8610003 */ 	swr	$at,0x3($v1)
/*  f02b0c0:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02b0c4:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02b0c8:	a879fff8 */ 	swl	$t9,-0x8($v1)
/*  f02b0cc:	b879fffb */ 	swr	$t9,-0x5($v1)
/*  f02b0d0:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b0d4:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02b0d8:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02b0dc:	8cf8fffc */ 	lw	$t8,-0x4($a3)
/*  f02b0e0:	28810004 */ 	slti	$at,$a0,0x4
/*  f02b0e4:	03110019 */ 	multu	$t8,$s1
/*  f02b0e8:	00007012 */ 	mflo	$t6
/*  f02b0ec:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f02b0f0:	85f90000 */ 	lh	$t9,0x0($t7)
/*  f02b0f4:	a479fff4 */ 	sh	$t9,-0xc($v1)
/*  f02b0f8:	8cf8fffc */ 	lw	$t8,-0x4($a3)
/*  f02b0fc:	03110019 */ 	multu	$t8,$s1
/*  f02b100:	00007012 */ 	mflo	$t6
/*  f02b104:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f02b108:	85f90002 */ 	lh	$t9,0x2($t7)
/*  f02b10c:	a479fff6 */ 	sh	$t9,-0xa($v1)
/*  f02b110:	8cf8fffc */ 	lw	$t8,-0x4($a3)
/*  f02b114:	03110019 */ 	multu	$t8,$s1
/*  f02b118:	00007012 */ 	mflo	$t6
/*  f02b11c:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f02b120:	85f90004 */ 	lh	$t9,0x4($t7)
/*  f02b124:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02b128:	1420ffe0 */ 	bnez	$at,.PF0f02b0ac
/*  f02b12c:	a479fff8 */ 	sh	$t9,-0x8($v1)
/*  f02b130:	8fa401f4 */ 	lw	$a0,0x1f4($sp)
/*  f02b134:	a4550008 */ 	sh	$s5,0x8($v0)
/*  f02b138:	a453000a */ 	sh	$s3,0xa($v0)
/*  f02b13c:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f02b140:	a4530016 */ 	sh	$s3,0x16($v0)
/*  f02b144:	a4540022 */ 	sh	$s4,0x22($v0)
/*  f02b148:	a455002c */ 	sh	$s5,0x2c($v0)
/*  f02b14c:	a454002e */ 	sh	$s4,0x2e($v0)
/*  f02b150:	a44b0014 */ 	sh	$t3,0x14($v0)
/*  f02b154:	a44b0020 */ 	sh	$t3,0x20($v0)
/*  f02b158:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b15c:	a8410030 */ 	swl	$at,0x30($v0)
/*  f02b160:	b8410033 */ 	swr	$at,0x33($v0)
/*  f02b164:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f02b168:	a84e0034 */ 	swl	$t6,0x34($v0)
/*  f02b16c:	b84e0037 */ 	swr	$t6,0x37($v0)
/*  f02b170:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b174:	a8410038 */ 	swl	$at,0x38($v0)
/*  f02b178:	b841003b */ 	swr	$at,0x3b($v0)
/*  f02b17c:	84830012 */ 	lh	$v1,0x12($a0)
/*  f02b180:	24017fff */ 	li	$at,0x7fff
/*  f02b184:	5461001e */ 	bnel	$v1,$at,.PF0f02b200
/*  f02b188:	a4430030 */ 	sh	$v1,0x30($v0)
/*  f02b18c:	844f0024 */ 	lh	$t7,0x24($v0)
/*  f02b190:	84590000 */ 	lh	$t9,0x0($v0)
/*  f02b194:	844e000c */ 	lh	$t6,0xc($v0)
/*  f02b198:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b19c:	84590018 */ 	lh	$t9,0x18($v0)
/*  f02b1a0:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f02b1a4:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b1a8:	84590002 */ 	lh	$t9,0x2($v0)
/*  f02b1ac:	844f0026 */ 	lh	$t7,0x26($v0)
/*  f02b1b0:	00187083 */ 	sra	$t6,$t8,0x2
/*  f02b1b4:	a44e0030 */ 	sh	$t6,0x30($v0)
/*  f02b1b8:	844e000e */ 	lh	$t6,0xe($v0)
/*  f02b1bc:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b1c0:	8459001a */ 	lh	$t9,0x1a($v0)
/*  f02b1c4:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f02b1c8:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b1cc:	84590004 */ 	lh	$t9,0x4($v0)
/*  f02b1d0:	844f0028 */ 	lh	$t7,0x28($v0)
/*  f02b1d4:	00187083 */ 	sra	$t6,$t8,0x2
/*  f02b1d8:	a44e0032 */ 	sh	$t6,0x32($v0)
/*  f02b1dc:	844e0010 */ 	lh	$t6,0x10($v0)
/*  f02b1e0:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b1e4:	8459001c */ 	lh	$t9,0x1c($v0)
/*  f02b1e8:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f02b1ec:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b1f0:	00187083 */ 	sra	$t6,$t8,0x2
/*  f02b1f4:	10000006 */ 	b	.PF0f02b210
/*  f02b1f8:	a44e0034 */ 	sh	$t6,0x34($v0)
/*  f02b1fc:	a4430030 */ 	sh	$v1,0x30($v0)
.PF0f02b200:
/*  f02b200:	848f0014 */ 	lh	$t7,0x14($a0)
/*  f02b204:	a44f0032 */ 	sh	$t7,0x32($v0)
/*  f02b208:	84990016 */ 	lh	$t9,0x16($a0)
/*  f02b20c:	a4590034 */ 	sh	$t9,0x34($v0)
.PF0f02b210:
/*  f02b210:	02ab1821 */ 	addu	$v1,$s5,$t3
/*  f02b214:	02741021 */ 	addu	$v0,$s3,$s4
/*  f02b218:	2418000c */ 	li	$t8,0xc
/*  f02b21c:	00037043 */ 	sra	$t6,$v1,0x1
/*  f02b220:	00027843 */ 	sra	$t7,$v0,0x1
/*  f02b224:	a2180037 */ 	sb	$t8,0x37($s0)
/*  f02b228:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02b22c:	a60f003a */ 	sh	$t7,0x3a($s0)
/*  f02b230:	8fb901f0 */ 	lw	$t9,0x1f0($sp)
/*  f02b234:	01c01825 */ 	move	$v1,$t6
/*  f02b238:	3c0e0440 */ 	lui	$t6,0x440
/*  f02b23c:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f02b240:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f02b244:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02b248:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f02b24c:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f02b250:	afa30040 */ 	sw	$v1,0x40($sp)
/*  f02b254:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f02b258:	02002025 */ 	move	$a0,$s0
/*  f02b25c:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02b260:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f02b264:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f02b268:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02b26c:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f02b270:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f02b274:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f02b278:	3c18b100 */ 	lui	$t8,0xb100
/*  f02b27c:	3c0e0332 */ 	lui	$t6,0x332
/*  f02b280:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f02b284:	afb901f0 */ 	sw	$t9,0x1f0($sp)
/*  f02b288:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02b28c:	37184444 */ 	ori	$t8,$t8,0x4444
/*  f02b290:	adf80000 */ 	sw	$t8,0x0($t7)
/*  f02b294:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f02b298:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02b29c:	24090004 */ 	li	$t1,0x4
/*  f02b2a0:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f02b2a4:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f02b2a8:	00002025 */ 	move	$a0,$zero
/*  f02b2ac:	241f0005 */ 	li	$ra,0x5
/*  f02b2b0:	240d0008 */ 	li	$t5,0x8
/*  f02b2b4:	240c0004 */ 	li	$t4,0x4
.PF0f02b2b8:
/*  f02b2b8:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b2bc:	248a0001 */ 	addiu	$t2,$a0,0x1
/*  f02b2c0:	aa010000 */ 	swl	$at,0x0($s0)
/*  f02b2c4:	ba010003 */ 	swr	$at,0x3($s0)
/*  f02b2c8:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02b2cc:	aa190004 */ 	swl	$t9,0x4($s0)
/*  f02b2d0:	ba190007 */ 	swr	$t9,0x7($s0)
/*  f02b2d4:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b2d8:	aa010008 */ 	swl	$at,0x8($s0)
/*  f02b2dc:	ba01000b */ 	swr	$at,0xb($s0)
/*  f02b2e0:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f02b2e4:	05410004 */ 	bgez	$t2,.PF0f02b2f8
/*  f02b2e8:	314e0003 */ 	andi	$t6,$t2,0x3
/*  f02b2ec:	11c00002 */ 	beqz	$t6,.PF0f02b2f8
/*  f02b2f0:	00000000 */ 	nop
/*  f02b2f4:	25cefffc */ 	addiu	$t6,$t6,-4
.PF0f02b2f8:
/*  f02b2f8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f02b2fc:	030f1021 */ 	addu	$v0,$t8,$t7
/*  f02b300:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b304:	03310019 */ 	multu	$t9,$s1
/*  f02b308:	00007012 */ 	mflo	$t6
/*  f02b30c:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b310:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b314:	a60f0000 */ 	sh	$t7,0x0($s0)
/*  f02b318:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b31c:	03310019 */ 	multu	$t9,$s1
/*  f02b320:	00007012 */ 	mflo	$t6
/*  f02b324:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b328:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b32c:	a60f0002 */ 	sh	$t7,0x2($s0)
/*  f02b330:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b334:	03310019 */ 	multu	$t9,$s1
/*  f02b338:	00007012 */ 	mflo	$t6
/*  f02b33c:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b340:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b344:	a20c0007 */ 	sb	$t4,0x7($s0)
/*  f02b348:	a60f0004 */ 	sh	$t7,0x4($s0)
/*  f02b34c:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b350:	aa01000c */ 	swl	$at,0xc($s0)
/*  f02b354:	ba01000f */ 	swr	$at,0xf($s0)
/*  f02b358:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f02b35c:	aa0e0010 */ 	swl	$t6,0x10($s0)
/*  f02b360:	ba0e0013 */ 	swr	$t6,0x13($s0)
/*  f02b364:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b368:	aa010014 */ 	swl	$at,0x14($s0)
/*  f02b36c:	ba010017 */ 	swr	$at,0x17($s0)
/*  f02b370:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f02b374:	03110019 */ 	multu	$t8,$s1
/*  f02b378:	00007812 */ 	mflo	$t7
/*  f02b37c:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02b380:	872e0000 */ 	lh	$t6,0x0($t9)
/*  f02b384:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f02b388:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f02b38c:	03110019 */ 	multu	$t8,$s1
/*  f02b390:	00007812 */ 	mflo	$t7
/*  f02b394:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02b398:	872e0002 */ 	lh	$t6,0x2($t9)
/*  f02b39c:	a60e000e */ 	sh	$t6,0xe($s0)
/*  f02b3a0:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f02b3a4:	03110019 */ 	multu	$t8,$s1
/*  f02b3a8:	00007812 */ 	mflo	$t7
/*  f02b3ac:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02b3b0:	872e0004 */ 	lh	$t6,0x4($t9)
/*  f02b3b4:	a20c0013 */ 	sb	$t4,0x13($s0)
/*  f02b3b8:	a60e0010 */ 	sh	$t6,0x10($s0)
/*  f02b3bc:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b3c0:	aa010018 */ 	swl	$at,0x18($s0)
/*  f02b3c4:	ba01001b */ 	swr	$at,0x1b($s0)
/*  f02b3c8:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b3cc:	aa0f001c */ 	swl	$t7,0x1c($s0)
/*  f02b3d0:	ba0f001f */ 	swr	$t7,0x1f($s0)
/*  f02b3d4:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b3d8:	aa010020 */ 	swl	$at,0x20($s0)
/*  f02b3dc:	ba010023 */ 	swr	$at,0x23($s0)
/*  f02b3e0:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f02b3e4:	24010001 */ 	li	$at,0x1
/*  f02b3e8:	03310019 */ 	multu	$t9,$s1
/*  f02b3ec:	00007012 */ 	mflo	$t6
/*  f02b3f0:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b3f4:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b3f8:	a60f0018 */ 	sh	$t7,0x18($s0)
/*  f02b3fc:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f02b400:	03310019 */ 	multu	$t9,$s1
/*  f02b404:	00007012 */ 	mflo	$t6
/*  f02b408:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b40c:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b410:	a60f001a */ 	sh	$t7,0x1a($s0)
/*  f02b414:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f02b418:	03310019 */ 	multu	$t9,$s1
/*  f02b41c:	00007012 */ 	mflo	$t6
/*  f02b420:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b424:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b428:	a20d001f */ 	sb	$t5,0x1f($s0)
/*  f02b42c:	15000004 */ 	bnez	$t0,.PF0f02b440
/*  f02b430:	a60f001c */ 	sh	$t7,0x1c($s0)
/*  f02b434:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f02b438:	10000016 */ 	b	.PF0f02b494
/*  f02b43c:	a6190018 */ 	sh	$t9,0x18($s0)
.PF0f02b440:
/*  f02b440:	15010003 */ 	bne	$t0,$at,.PF0f02b450
/*  f02b444:	8fae01cc */ 	lw	$t6,0x1cc($sp)
/*  f02b448:	10000012 */ 	b	.PF0f02b494
/*  f02b44c:	a60e0018 */ 	sh	$t6,0x18($s0)
.PF0f02b450:
/*  f02b450:	24010002 */ 	li	$at,0x2
/*  f02b454:	15010003 */ 	bne	$t0,$at,.PF0f02b464
/*  f02b458:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f02b45c:	1000000d */ 	b	.PF0f02b494
/*  f02b460:	a618001a */ 	sh	$t8,0x1a($s0)
.PF0f02b464:
/*  f02b464:	24010003 */ 	li	$at,0x3
/*  f02b468:	15010003 */ 	bne	$t0,$at,.PF0f02b478
/*  f02b46c:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f02b470:	10000008 */ 	b	.PF0f02b494
/*  f02b474:	a60f001a */ 	sh	$t7,0x1a($s0)
.PF0f02b478:
/*  f02b478:	15090003 */ 	bne	$t0,$t1,.PF0f02b488
/*  f02b47c:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f02b480:	10000004 */ 	b	.PF0f02b494
/*  f02b484:	a619001c */ 	sh	$t9,0x1c($s0)
.PF0f02b488:
/*  f02b488:	151f0002 */ 	bne	$t0,$ra,.PF0f02b494
/*  f02b48c:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f02b490:	a60e001c */ 	sh	$t6,0x1c($s0)
.PF0f02b494:
/*  f02b494:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b498:	aa010024 */ 	swl	$at,0x24($s0)
/*  f02b49c:	ba010027 */ 	swr	$at,0x27($s0)
/*  f02b4a0:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b4a4:	aa0f0028 */ 	swl	$t7,0x28($s0)
/*  f02b4a8:	ba0f002b */ 	swr	$t7,0x2b($s0)
/*  f02b4ac:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b4b0:	aa01002c */ 	swl	$at,0x2c($s0)
/*  f02b4b4:	ba01002f */ 	swr	$at,0x2f($s0)
/*  f02b4b8:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b4bc:	24010001 */ 	li	$at,0x1
/*  f02b4c0:	03310019 */ 	multu	$t9,$s1
/*  f02b4c4:	00007012 */ 	mflo	$t6
/*  f02b4c8:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b4cc:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b4d0:	a60f0024 */ 	sh	$t7,0x24($s0)
/*  f02b4d4:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b4d8:	03310019 */ 	multu	$t9,$s1
/*  f02b4dc:	00007012 */ 	mflo	$t6
/*  f02b4e0:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b4e4:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b4e8:	a60f0026 */ 	sh	$t7,0x26($s0)
/*  f02b4ec:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b4f0:	03310019 */ 	multu	$t9,$s1
/*  f02b4f4:	00007012 */ 	mflo	$t6
/*  f02b4f8:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b4fc:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b500:	a20d002b */ 	sb	$t5,0x2b($s0)
/*  f02b504:	15000004 */ 	bnez	$t0,.PF0f02b518
/*  f02b508:	a60f0028 */ 	sh	$t7,0x28($s0)
/*  f02b50c:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f02b510:	10000016 */ 	b	.PF0f02b56c
/*  f02b514:	a6190024 */ 	sh	$t9,0x24($s0)
.PF0f02b518:
/*  f02b518:	15010003 */ 	bne	$t0,$at,.PF0f02b528
/*  f02b51c:	8fae01cc */ 	lw	$t6,0x1cc($sp)
/*  f02b520:	10000012 */ 	b	.PF0f02b56c
/*  f02b524:	a60e0024 */ 	sh	$t6,0x24($s0)
.PF0f02b528:
/*  f02b528:	24010002 */ 	li	$at,0x2
/*  f02b52c:	15010003 */ 	bne	$t0,$at,.PF0f02b53c
/*  f02b530:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f02b534:	1000000d */ 	b	.PF0f02b56c
/*  f02b538:	a6180026 */ 	sh	$t8,0x26($s0)
.PF0f02b53c:
/*  f02b53c:	24010003 */ 	li	$at,0x3
/*  f02b540:	15010003 */ 	bne	$t0,$at,.PF0f02b550
/*  f02b544:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f02b548:	10000008 */ 	b	.PF0f02b56c
/*  f02b54c:	a60f0026 */ 	sh	$t7,0x26($s0)
.PF0f02b550:
/*  f02b550:	15090003 */ 	bne	$t0,$t1,.PF0f02b560
/*  f02b554:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f02b558:	10000004 */ 	b	.PF0f02b56c
/*  f02b55c:	a6190028 */ 	sh	$t9,0x28($s0)
.PF0f02b560:
/*  f02b560:	151f0002 */ 	bne	$t0,$ra,.PF0f02b56c
/*  f02b564:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f02b568:	a60e0028 */ 	sh	$t6,0x28($s0)
.PF0f02b56c:
/*  f02b56c:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02b570:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02b574:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02b578:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02b57c:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02b580:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02b584:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02b588:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02b58c:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b590:	86190024 */ 	lh	$t9,0x24($s0)
/*  f02b594:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f02b598:	aa010030 */ 	swl	$at,0x30($s0)
/*  f02b59c:	ba010033 */ 	swr	$at,0x33($s0)
/*  f02b5a0:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b5a4:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b5a8:	860e0018 */ 	lh	$t6,0x18($s0)
/*  f02b5ac:	aa0f0034 */ 	swl	$t7,0x34($s0)
/*  f02b5b0:	ba0f0037 */ 	swr	$t7,0x37($s0)
/*  f02b5b4:	860f000c */ 	lh	$t7,0xc($s0)
/*  f02b5b8:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b5bc:	02002025 */ 	move	$a0,$s0
/*  f02b5c0:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b5c4:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b5c8:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f02b5cc:	86190026 */ 	lh	$t9,0x26($s0)
/*  f02b5d0:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b5d4:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f02b5d8:	860f000e */ 	lh	$t7,0xe($s0)
/*  f02b5dc:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b5e0:	860e001a */ 	lh	$t6,0x1a($s0)
/*  f02b5e4:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b5e8:	aa010038 */ 	swl	$at,0x38($s0)
/*  f02b5ec:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b5f0:	860e0004 */ 	lh	$t6,0x4($s0)
/*  f02b5f4:	86190028 */ 	lh	$t9,0x28($s0)
/*  f02b5f8:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b5fc:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f02b600:	860f0010 */ 	lh	$t7,0x10($s0)
/*  f02b604:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b608:	860e001c */ 	lh	$t6,0x1c($s0)
/*  f02b60c:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b610:	ba01003b */ 	swr	$at,0x3b($s0)
/*  f02b614:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b618:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b61c:	24190010 */ 	li	$t9,0x10
/*  f02b620:	a60f0034 */ 	sh	$t7,0x34($s0)
/*  f02b624:	a2190037 */ 	sb	$t9,0x37($s0)
/*  f02b628:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f02b62c:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02b630:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f02b634:	3c0e0440 */ 	lui	$t6,0x440
/*  f02b638:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02b63c:	a618003a */ 	sh	$t8,0x3a($s0)
/*  f02b640:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f02b644:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f02b648:	afb901f0 */ 	sw	$t9,0x1f0($sp)
/*  f02b64c:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f02b650:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f02b654:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f02b658:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f02b65c:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02b660:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f02b664:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f02b668:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f02b66c:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f02b670:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02b674:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f02b678:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f02b67c:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02b680:	3c19b100 */ 	lui	$t9,0xb100
/*  f02b684:	3c0e0332 */ 	lui	$t6,0x332
/*  f02b688:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02b68c:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02b690:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02b694:	37394444 */ 	ori	$t9,$t9,0x4444
/*  f02b698:	28810004 */ 	slti	$at,$a0,0x4
/*  f02b69c:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02b6a0:	24090004 */ 	li	$t1,0x4
/*  f02b6a4:	240c0004 */ 	li	$t4,0x4
/*  f02b6a8:	240d0008 */ 	li	$t5,0x8
/*  f02b6ac:	241f0005 */ 	li	$ra,0x5
/*  f02b6b0:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f02b6b4:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f02b6b8:	af190000 */ 	sw	$t9,0x0($t8)
/*  f02b6bc:	1420fefe */ 	bnez	$at,.PF0f02b2b8
/*  f02b6c0:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f02b6c4:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f02b6c8:	02001825 */ 	move	$v1,$s0
/*  f02b6cc:	00003025 */ 	move	$a2,$zero
/*  f02b6d0:	24040010 */ 	li	$a0,0x10
/*  f02b6d4:	2442000c */ 	addiu	$v0,$v0,0xc
.PF0f02b6d8:
/*  f02b6d8:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b6dc:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f02b6e0:	2442fffc */ 	addiu	$v0,$v0,-4
/*  f02b6e4:	a8610000 */ 	swl	$at,0x0($v1)
/*  f02b6e8:	b8610003 */ 	swr	$at,0x3($v1)
/*  f02b6ec:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b6f0:	a86f0004 */ 	swl	$t7,0x4($v1)
/*  f02b6f4:	b86f0007 */ 	swr	$t7,0x7($v1)
/*  f02b6f8:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b6fc:	a8610008 */ 	swl	$at,0x8($v1)
/*  f02b700:	b861000b */ 	swr	$at,0xb($v1)
/*  f02b704:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f02b708:	24010001 */ 	li	$at,0x1
/*  f02b70c:	03310019 */ 	multu	$t9,$s1
/*  f02b710:	00007012 */ 	mflo	$t6
/*  f02b714:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b718:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b71c:	a46f0000 */ 	sh	$t7,0x0($v1)
/*  f02b720:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f02b724:	03310019 */ 	multu	$t9,$s1
/*  f02b728:	00007012 */ 	mflo	$t6
/*  f02b72c:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b730:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b734:	a46f0002 */ 	sh	$t7,0x2($v1)
/*  f02b738:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f02b73c:	03310019 */ 	multu	$t9,$s1
/*  f02b740:	00007012 */ 	mflo	$t6
/*  f02b744:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b748:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b74c:	a06d0007 */ 	sb	$t5,0x7($v1)
/*  f02b750:	15000004 */ 	bnez	$t0,.PF0f02b764
/*  f02b754:	a46f0004 */ 	sh	$t7,0x4($v1)
/*  f02b758:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f02b75c:	10000016 */ 	b	.PF0f02b7b8
/*  f02b760:	a4790000 */ 	sh	$t9,0x0($v1)
.PF0f02b764:
/*  f02b764:	15010003 */ 	bne	$t0,$at,.PF0f02b774
/*  f02b768:	8fae01cc */ 	lw	$t6,0x1cc($sp)
/*  f02b76c:	10000012 */ 	b	.PF0f02b7b8
/*  f02b770:	a46e0000 */ 	sh	$t6,0x0($v1)
.PF0f02b774:
/*  f02b774:	24010002 */ 	li	$at,0x2
/*  f02b778:	15010003 */ 	bne	$t0,$at,.PF0f02b788
/*  f02b77c:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f02b780:	1000000d */ 	b	.PF0f02b7b8
/*  f02b784:	a4780002 */ 	sh	$t8,0x2($v1)
.PF0f02b788:
/*  f02b788:	24010003 */ 	li	$at,0x3
/*  f02b78c:	15010003 */ 	bne	$t0,$at,.PF0f02b79c
/*  f02b790:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f02b794:	10000008 */ 	b	.PF0f02b7b8
/*  f02b798:	a46f0002 */ 	sh	$t7,0x2($v1)
.PF0f02b79c:
/*  f02b79c:	15090003 */ 	bne	$t0,$t1,.PF0f02b7ac
/*  f02b7a0:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f02b7a4:	10000004 */ 	b	.PF0f02b7b8
/*  f02b7a8:	a4790004 */ 	sh	$t9,0x4($v1)
.PF0f02b7ac:
/*  f02b7ac:	151f0002 */ 	bne	$t0,$ra,.PF0f02b7b8
/*  f02b7b0:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f02b7b4:	a46e0004 */ 	sh	$t6,0x4($v1)
.PF0f02b7b8:
/*  f02b7b8:	14c4ffc7 */ 	bne	$a2,$a0,.PF0f02b6d8
/*  f02b7bc:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02b7c0:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02b7c4:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02b7c8:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02b7cc:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02b7d0:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02b7d4:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02b7d8:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02b7dc:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02b7e0:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b7e4:	86190024 */ 	lh	$t9,0x24($s0)
/*  f02b7e8:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f02b7ec:	aa010030 */ 	swl	$at,0x30($s0)
/*  f02b7f0:	ba010033 */ 	swr	$at,0x33($s0)
/*  f02b7f4:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b7f8:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b7fc:	860e0018 */ 	lh	$t6,0x18($s0)
/*  f02b800:	aa0f0034 */ 	swl	$t7,0x34($s0)
/*  f02b804:	ba0f0037 */ 	swr	$t7,0x37($s0)
/*  f02b808:	860f000c */ 	lh	$t7,0xc($s0)
/*  f02b80c:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b810:	02002025 */ 	move	$a0,$s0
/*  f02b814:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b818:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b81c:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f02b820:	86190026 */ 	lh	$t9,0x26($s0)
/*  f02b824:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b828:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f02b82c:	860f000e */ 	lh	$t7,0xe($s0)
/*  f02b830:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b834:	860e001a */ 	lh	$t6,0x1a($s0)
/*  f02b838:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b83c:	aa010038 */ 	swl	$at,0x38($s0)
/*  f02b840:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b844:	860e0004 */ 	lh	$t6,0x4($s0)
/*  f02b848:	86190028 */ 	lh	$t9,0x28($s0)
/*  f02b84c:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b850:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f02b854:	860f0010 */ 	lh	$t7,0x10($s0)
/*  f02b858:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b85c:	860e001c */ 	lh	$t6,0x1c($s0)
/*  f02b860:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b864:	ba01003b */ 	swr	$at,0x3b($s0)
/*  f02b868:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b86c:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b870:	24190010 */ 	li	$t9,0x10
/*  f02b874:	a60f0034 */ 	sh	$t7,0x34($s0)
/*  f02b878:	a2190037 */ 	sb	$t9,0x37($s0)
/*  f02b87c:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f02b880:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02b884:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f02b888:	3c0e0440 */ 	lui	$t6,0x440
/*  f02b88c:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02b890:	a618003a */ 	sh	$t8,0x3a($s0)
/*  f02b894:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02b898:	26390008 */ 	addiu	$t9,$s1,0x8
/*  f02b89c:	afb901f0 */ 	sw	$t9,0x1f0($sp)
/*  f02b8a0:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f02b8a4:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f02b8a8:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02b8ac:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02b8b0:	3c19b100 */ 	lui	$t9,0xb100
/*  f02b8b4:	3c0e0332 */ 	lui	$t6,0x332
/*  f02b8b8:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02b8bc:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02b8c0:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02b8c4:	37394444 */ 	ori	$t9,$t9,0x4444
/*  f02b8c8:	af190000 */ 	sw	$t9,0x0($t8)
/*  f02b8cc:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f02b8d0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PF0f02b8d4:
/*  f02b8d4:	8fa201f0 */ 	lw	$v0,0x1f0($sp)
/*  f02b8d8:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f02b8dc:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f02b8e0:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f02b8e4:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f02b8e8:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f02b8ec:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f02b8f0:	03e00008 */ 	jr	$ra
/*  f02b8f4:	27bd01f0 */ 	addiu	$sp,$sp,0x1f0
);
#elif VERSION == VERSION_PAL_BETA
GLOBAL_ASM(
glabel chr0f02983c
.late_rodata
glabel var7f1a9b60pf
.word 0x3c40c0c1
glabel var7f1a9b64pf
.word 0x3c40c0c1
glabel var7f1a9b68pf
.word 0x3bcddaca
glabel var7f1a9b6cpf
.word 0x3bcddaca
glabel var7f1a9b70pf
.word 0x3f169697
glabel var7f1a9b74pf
.word 0x3ea0a0a1
glabel var7f1a9b78pf
.word 0x3e70f0f1
glabel var7f1a9b7cpf
.word 0x3e20a0a1
glabel var7f1a9b80pf
.word 0x3cb0d9df
glabel var7f1a9b84pf
.word 0x40cccccd
glabel var7f1a9b88pf
.word 0x3b808081
glabel var7f1a9b8cpf
.word 0x407745d1
glabel var7f1a9b90pf
.word 0x3b808081
glabel var7f1a9b94pf
.word 0x4099999a
glabel var7f1a9b98pf
.word 0x3b808081
glabel var7f1a9b9cpf
.word 0x407745d1
glabel var7f1a9ba0pf
.word 0x3b808081
.text
/*  f02990c:	27bdfe10 */ 	addiu	$sp,$sp,-496
/*  f029910:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f029914:	3c0e8006 */ 	lui	$t6,0x8006
/*  f029918:	8fb50200 */ 	lw	$s5,0x200($sp)
/*  f02991c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f029920:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f029924:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f029928:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f02992c:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f029930:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f029934:	afa401f0 */ 	sw	$a0,0x1f0($sp)
/*  f029938:	afa501f4 */ 	sw	$a1,0x1f4($sp)
/*  f02993c:	afa601f8 */ 	sw	$a2,0x1f8($sp)
/*  f029940:	afa701fc */ 	sw	$a3,0x1fc($sp)
/*  f029944:	25ce4164 */ 	addiu	$t6,$t6,0x4164
/*  f029948:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f02994c:	27b201e0 */ 	addiu	$s2,$sp,0x1e0
/*  f029950:	8eb30004 */ 	lw	$s3,0x4($s5)
/*  f029954:	ae410000 */ 	sw	$at,0x0($s2)
/*  f029958:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f02995c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f029960:	25ef4170 */ 	addiu	$t7,$t7,0x4170
/*  f029964:	ae590004 */ 	sw	$t9,0x4($s2)
/*  f029968:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f02996c:	25f90060 */ 	addiu	$t9,$t7,0x60
/*  f029970:	27b80104 */ 	addiu	$t8,$sp,0x104
/*  f029974:	ae410008 */ 	sw	$at,0x8($s2)
.PB0f029978:
/*  f029978:	8de10000 */ 	lw	$at,0x0($t7)
/*  f02997c:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f029980:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f029984:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f029988:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f02998c:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f029990:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f029994:	15f9fff8 */ 	bne	$t7,$t9,.PB0f029978
/*  f029998:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f02999c:	8fae01f8 */ 	lw	$t6,0x1f8($sp)
/*  f0299a0:	24010003 */ 	li	$at,0x3
/*  f0299a4:	24110006 */ 	li	$s1,0x6
/*  f0299a8:	91c40000 */ 	lbu	$a0,0x0($t6)
/*  f0299ac:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
/*  f0299b0:	50810004 */ 	beql	$a0,$at,.PB0f0299c4
/*  f0299b4:	8f300004 */ 	lw	$s0,0x4($t9)
/*  f0299b8:	56240014 */ 	bnel	$s1,$a0,.PB0f029a0c
/*  f0299bc:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
/*  f0299c0:	8f300004 */ 	lw	$s0,0x4($t9)
.PB0f0299c4:
/*  f0299c4:	3c014120 */ 	lui	$at,0x4120
/*  f0299c8:	44812000 */ 	mtc1	$at,$f4
/*  f0299cc:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f0299d0:	24110006 */ 	li	$s1,0x6
/*  f0299d4:	02002025 */ 	move	$a0,$s0
/*  f0299d8:	c5e60014 */ 	lwc1	$f6,0x14($t7)
/*  f0299dc:	46062083 */ 	div.s	$f2,$f4,$f6
/*  f0299e0:	0fc0d025 */ 	jal	chrGetShield
/*  f0299e4:	e7a20170 */ 	swc1	$f2,0x170($sp)
/*  f0299e8:	921402e1 */ 	lbu	$s4,0x2e1($s0)
/*  f0299ec:	960e0188 */ 	lhu	$t6,0x188($s0)
/*  f0299f0:	c7a20170 */ 	lwc1	$f2,0x170($sp)
/*  f0299f4:	0014c042 */ 	srl	$t8,$s4,0x1
/*  f0299f8:	46000386 */ 	mov.s	$f14,$f0
/*  f0299fc:	0300a025 */ 	move	$s4,$t8
/*  f029a00:	10000011 */ 	b	.PB0f029a48
/*  f029a04:	afae0164 */ 	sw	$t6,0x164($sp)
/*  f029a08:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
.PB0f029a0c:
/*  f029a0c:	44801000 */ 	mtc1	$zero,$f2
/*  f029a10:	24140040 */ 	li	$s4,0x40
/*  f029a14:	8f220004 */ 	lw	$v0,0x4($t9)
/*  f029a18:	afa00164 */ 	sw	$zero,0x164($sp)
/*  f029a1c:	3c014100 */ 	lui	$at,0x4100
/*  f029a20:	8c4f0010 */ 	lw	$t7,0x10($v0)
/*  f029a24:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f029a28:	53000006 */ 	beqzl	$t8,.PB0f029a44
/*  f029a2c:	44817000 */ 	mtc1	$at,$f14
/*  f029a30:	3c014080 */ 	lui	$at,0x4080
/*  f029a34:	44817000 */ 	mtc1	$at,$f14
/*  f029a38:	10000004 */ 	b	.PB0f029a4c
/*  f029a3c:	02a02025 */ 	move	$a0,$s5
/*  f029a40:	44817000 */ 	mtc1	$at,$f14
.PB0f029a44:
/*  f029a44:	00000000 */ 	nop
.PB0f029a48:
/*  f029a48:	02a02025 */ 	move	$a0,$s5
.PB0f029a4c:
/*  f029a4c:	00002825 */ 	move	$a1,$zero
/*  f029a50:	e7a20170 */ 	swc1	$f2,0x170($sp)
/*  f029a54:	0c006bdd */ 	jal	model0001a524
/*  f029a58:	e7ae016c */ 	swc1	$f14,0x16c($sp)
/*  f029a5c:	c7a20170 */ 	lwc1	$f2,0x170($sp)
/*  f029a60:	c6680004 */ 	lwc1	$f8,0x4($s3)
/*  f029a64:	c6720008 */ 	lwc1	$f18,0x8($s3)
/*  f029a68:	8fae01fc */ 	lw	$t6,0x1fc($sp)
/*  f029a6c:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f029a70:	c668000c */ 	lwc1	$f8,0xc($s3)
/*  f029a74:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f029a78:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f029a7c:	c6720010 */ 	lwc1	$f18,0x10($s3)
/*  f029a80:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f029a84:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f029a88:	00027980 */ 	sll	$t7,$v0,0x6
/*  f029a8c:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f029a90:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f029a94:	44038000 */ 	mfc1	$v1,$f16
/*  f029a98:	3c190102 */ 	lui	$t9,0x102
/*  f029a9c:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f029aa0:	c6680014 */ 	lwc1	$f8,0x14($s3)
/*  f029aa4:	44053000 */ 	mfc1	$a1,$f6
/*  f029aa8:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f029aac:	c6720018 */ 	lwc1	$f18,0x18($s3)
/*  f029ab0:	260a0008 */ 	addiu	$t2,$s0,0x8
/*  f029ab4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f029ab8:	c7ae016c */ 	lwc1	$f14,0x16c($sp)
/*  f029abc:	afaa01f0 */ 	sw	$t2,0x1f0($sp)
/*  f029ac0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f029ac4:	44068000 */ 	mfc1	$a2,$f16
/*  f029ac8:	37390040 */ 	ori	$t9,$t9,0x40
/*  f029acc:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f029ad0:	44073000 */ 	mfc1	$a3,$f6
/*  f029ad4:	a7a30180 */ 	sh	$v1,0x180($sp)
/*  f029ad8:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f029adc:	a7a30186 */ 	sh	$v1,0x186($sp)
/*  f029ae0:	a7a3018c */ 	sh	$v1,0x18c($sp)
/*  f029ae4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f029ae8:	a7a30192 */ 	sh	$v1,0x192($sp)
/*  f029aec:	a7a50198 */ 	sh	$a1,0x198($sp)
/*  f029af0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f029af4:	44088000 */ 	mfc1	$t0,$f16
/*  f029af8:	a7a5019e */ 	sh	$a1,0x19e($sp)
/*  f029afc:	a7a501a4 */ 	sh	$a1,0x1a4($sp)
/*  f029b00:	44093000 */ 	mfc1	$t1,$f6
/*  f029b04:	a7a501aa */ 	sh	$a1,0x1aa($sp)
/*  f029b08:	a7a60182 */ 	sh	$a2,0x182($sp)
/*  f029b0c:	a7a60188 */ 	sh	$a2,0x188($sp)
/*  f029b10:	a7a6019a */ 	sh	$a2,0x19a($sp)
/*  f029b14:	a7a601a0 */ 	sh	$a2,0x1a0($sp)
/*  f029b18:	a7a7018e */ 	sh	$a3,0x18e($sp)
/*  f029b1c:	a7a70194 */ 	sh	$a3,0x194($sp)
/*  f029b20:	a7a701a6 */ 	sh	$a3,0x1a6($sp)
/*  f029b24:	a7a701ac */ 	sh	$a3,0x1ac($sp)
/*  f029b28:	a7a80184 */ 	sh	$t0,0x184($sp)
/*  f029b2c:	a7a80190 */ 	sh	$t0,0x190($sp)
/*  f029b30:	a7a8019c */ 	sh	$t0,0x19c($sp)
/*  f029b34:	a7a801a8 */ 	sh	$t0,0x1a8($sp)
/*  f029b38:	a7a9018a */ 	sh	$t1,0x18a($sp)
/*  f029b3c:	a7a90196 */ 	sh	$t1,0x196($sp)
/*  f029b40:	a7a901a2 */ 	sh	$t1,0x1a2($sp)
/*  f029b44:	a7a901ae */ 	sh	$t1,0x1ae($sp)
/*  f029b48:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f029b4c:	afa301cc */ 	sw	$v1,0x1cc($sp)
/*  f029b50:	afa501c8 */ 	sw	$a1,0x1c8($sp)
/*  f029b54:	e7ae016c */ 	swc1	$f14,0x16c($sp)
/*  f029b58:	afa601c4 */ 	sw	$a2,0x1c4($sp)
/*  f029b5c:	afa701c0 */ 	sw	$a3,0x1c0($sp)
/*  f029b60:	afa801bc */ 	sw	$t0,0x1bc($sp)
/*  f029b64:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f029b68:	afa901b8 */ 	sw	$t1,0x1b8($sp)
/*  f029b6c:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029b70:	c7ae016c */ 	lwc1	$f14,0x16c($sp)
/*  f029b74:	2401fff9 */ 	li	$at,-7
/*  f029b78:	15010082 */ 	bne	$t0,$at,.PB0f029d84
/*  f029b7c:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f029b80:	0fc5a40f */ 	jal	gfxAllocateColours
/*  f029b84:	24040001 */ 	li	$a0,0x1
/*  f029b88:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f029b8c:	3c0e0700 */ 	lui	$t6,0x700
/*  f029b90:	35ce0004 */ 	ori	$t6,$t6,0x4
/*  f029b94:	26180008 */ 	addiu	$t8,$s0,0x8
/*  f029b98:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f029b9c:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f029ba0:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f029ba4:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f029ba8:	00402025 */ 	move	$a0,$v0
/*  f029bac:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f029bb0:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f029bb4:	240400ff */ 	li	$a0,0xff
/*  f029bb8:	2a810040 */ 	slti	$at,$s4,0x40
/*  f029bbc:	a0640000 */ 	sb	$a0,0x0($v1)
/*  f029bc0:	a0640001 */ 	sb	$a0,0x1($v1)
/*  f029bc4:	1020000f */ 	beqz	$at,.PB0f029c04
/*  f029bc8:	a0640002 */ 	sb	$a0,0x2($v1)
/*  f029bcc:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f029bd0:	44944000 */ 	mtc1	$s4,$f8
/*  f029bd4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f029bd8:	44998000 */ 	mtc1	$t9,$f16
/*  f029bdc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f029be0:	c426a60c */ 	lwc1	$f6,-0x59f4($at)
/*  f029be4:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f029be8:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f029bec:	00000000 */ 	nop
/*  f029bf0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f029bf4:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f029bf8:	44188000 */ 	mfc1	$t8,$f16
/*  f029bfc:	10000011 */ 	b	.PB0f029c44
/*  f029c00:	a0780003 */ 	sb	$t8,0x3($v1)
.PB0f029c04:
/*  f029c04:	8faf0210 */ 	lw	$t7,0x210($sp)
/*  f029c08:	240e007f */ 	li	$t6,0x7f
/*  f029c0c:	01d4c823 */ 	subu	$t9,$t6,$s4
/*  f029c10:	44995000 */ 	mtc1	$t9,$f10
/*  f029c14:	448f2000 */ 	mtc1	$t7,$f4
/*  f029c18:	3c017f1b */ 	lui	$at,0x7f1b
/*  f029c1c:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f029c20:	c430a610 */ 	lwc1	$f16,-0x59f0($at)
/*  f029c24:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f029c28:	46069202 */ 	mul.s	$f8,$f18,$f6
/*  f029c2c:	00000000 */ 	nop
/*  f029c30:	46104282 */ 	mul.s	$f10,$f8,$f16
/*  f029c34:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f029c38:	440e2000 */ 	mfc1	$t6,$f4
/*  f029c3c:	00000000 */ 	nop
/*  f029c40:	a06e0003 */ 	sb	$t6,0x3($v1)
.PB0f029c44:
/*  f029c44:	0fc5a3f5 */ 	jal	gfxAllocateVertices
/*  f029c48:	24040018 */ 	li	$a0,0x18
/*  f029c4c:	00408025 */ 	move	$s0,$v0
/*  f029c50:	27a60104 */ 	addiu	$a2,$sp,0x104
/*  f029c54:	24090004 */ 	li	$t1,0x4
/*  f029c58:	24070200 */ 	li	$a3,0x200
/*  f029c5c:	27a50180 */ 	addiu	$a1,$sp,0x180
.PB0f029c60:
/*  f029c60:	00002025 */ 	move	$a0,$zero
/*  f029c64:	02001825 */ 	move	$v1,$s0
/*  f029c68:	00c01025 */ 	move	$v0,$a2
.PB0f029c6c:
/*  f029c6c:	8e410000 */ 	lw	$at,0x0($s2)
/*  f029c70:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f029c74:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f029c78:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f029c7c:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f029c80:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f029c84:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f029c88:	a86ffff8 */ 	swl	$t7,-0x8($v1)
/*  f029c8c:	b86ffffb */ 	swr	$t7,-0x5($v1)
/*  f029c90:	8e410008 */ 	lw	$at,0x8($s2)
/*  f029c94:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f029c98:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f029c9c:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f029ca0:	03110019 */ 	multu	$t8,$s1
/*  f029ca4:	00007012 */ 	mflo	$t6
/*  f029ca8:	00aec821 */ 	addu	$t9,$a1,$t6
/*  f029cac:	872f0000 */ 	lh	$t7,0x0($t9)
/*  f029cb0:	a46ffff4 */ 	sh	$t7,-0xc($v1)
/*  f029cb4:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f029cb8:	03110019 */ 	multu	$t8,$s1
/*  f029cbc:	00007012 */ 	mflo	$t6
/*  f029cc0:	00aec821 */ 	addu	$t9,$a1,$t6
/*  f029cc4:	872f0002 */ 	lh	$t7,0x2($t9)
/*  f029cc8:	a46ffff6 */ 	sh	$t7,-0xa($v1)
/*  f029ccc:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f029cd0:	03110019 */ 	multu	$t8,$s1
/*  f029cd4:	00007012 */ 	mflo	$t6
/*  f029cd8:	00aec821 */ 	addu	$t9,$a1,$t6
/*  f029cdc:	872f0004 */ 	lh	$t7,0x4($t9)
/*  f029ce0:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f029ce4:	1489ffe1 */ 	bne	$a0,$t1,.PB0f029c6c
/*  f029ce8:	a46ffff8 */ 	sh	$t7,-0x8($v1)
/*  f029cec:	a6000008 */ 	sh	$zero,0x8($s0)
/*  f029cf0:	a600000a */ 	sh	$zero,0xa($s0)
/*  f029cf4:	a6070014 */ 	sh	$a3,0x14($s0)
/*  f029cf8:	a6000016 */ 	sh	$zero,0x16($s0)
/*  f029cfc:	a6070020 */ 	sh	$a3,0x20($s0)
/*  f029d00:	a6070022 */ 	sh	$a3,0x22($s0)
/*  f029d04:	a600002c */ 	sh	$zero,0x2c($s0)
/*  f029d08:	a607002e */ 	sh	$a3,0x2e($s0)
/*  f029d0c:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f029d10:	3c190430 */ 	lui	$t9,0x430
/*  f029d14:	37390030 */ 	ori	$t9,$t9,0x30
/*  f029d18:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f029d1c:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f029d20:	af190000 */ 	sw	$t9,0x0($t8)
/*  f029d24:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f029d28:	02002025 */ 	move	$a0,$s0
/*  f029d2c:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f029d30:	afb800c8 */ 	sw	$t8,0xc8($sp)
/*  f029d34:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*  f029d38:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f029d3c:	3c0eb100 */ 	lui	$t6,0xb100
/*  f029d40:	ad020004 */ 	sw	$v0,0x4($t0)
/*  f029d44:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f029d48:	35ce0032 */ 	ori	$t6,$t6,0x32
/*  f029d4c:	24192010 */ 	li	$t9,0x2010
/*  f029d50:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f029d54:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f029d58:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f029d5c:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f029d60:	27af0164 */ 	addiu	$t7,$sp,0x164
/*  f029d64:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f029d68:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f029d6c:	24070200 */ 	li	$a3,0x200
/*  f029d70:	24090004 */ 	li	$t1,0x4
/*  f029d74:	14cfffba */ 	bne	$a2,$t7,.PB0f029c60
/*  f029d78:	26100030 */ 	addiu	$s0,$s0,0x30
/*  f029d7c:	100006c0 */ 	b	.PB0f02b880
/*  f029d80:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PB0f029d84:
/*  f029d84:	3c05800b */ 	lui	$a1,0x800b
/*  f029d88:	24180002 */ 	li	$t8,0x2
/*  f029d8c:	240e0001 */ 	li	$t6,0x1
/*  f029d90:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f029d94:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f029d98:	8ca5fbac */ 	lw	$a1,-0x454($a1)
/*  f029d9c:	27a401f0 */ 	addiu	$a0,$sp,0x1f0
/*  f029da0:	24060004 */ 	li	$a2,0x4
/*  f029da4:	24070001 */ 	li	$a3,0x1
/*  f029da8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f029dac:	0fc2cf74 */ 	jal	texSelect
/*  f029db0:	e7ae016c */ 	swc1	$f14,0x16c($sp)
/*  f029db4:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029db8:	c7ae016c */ 	lwc1	$f14,0x16c($sp)
/*  f029dbc:	27a50100 */ 	addiu	$a1,$sp,0x100
/*  f029dc0:	05000004 */ 	bltz	$t0,.PB0f029dd4
/*  f029dc4:	27a600fc */ 	addiu	$a2,$sp,0xfc
/*  f029dc8:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
/*  f029dcc:	1000001c */ 	b	.PB0f029e40
/*  f029dd0:	c72c0058 */ 	lwc1	$f12,0x58($t9)
.PB0f029dd4:
/*  f029dd4:	2401fffe */ 	li	$at,-2
/*  f029dd8:	15010019 */ 	bne	$t0,$at,.PB0f029e40
/*  f029ddc:	46007306 */ 	mov.s	$f12,$f14
/*  f029de0:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f029de4:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f029de8:	81e20011 */ 	lb	$v0,0x11($t7)
/*  f029dec:	0058082a */ 	slt	$at,$v0,$t8
/*  f029df0:	50200005 */ 	beqzl	$at,.PB0f029e08
/*  f029df4:	44823000 */ 	mtc1	$v0,$f6
/*  f029df8:	44806000 */ 	mtc1	$zero,$f12
/*  f029dfc:	10000010 */ 	b	.PB0f029e40
/*  f029e00:	00000000 */ 	nop
/*  f029e04:	44823000 */ 	mtc1	$v0,$f6
.PB0f029e08:
/*  f029e08:	8fae020c */ 	lw	$t6,0x20c($sp)
/*  f029e0c:	3c014080 */ 	lui	$at,0x4080
/*  f029e10:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f029e14:	44819000 */ 	mtc1	$at,$f18
/*  f029e18:	448e8000 */ 	mtc1	$t6,$f16
/*  f029e1c:	3c013f80 */ 	lui	$at,0x3f80
/*  f029e20:	44813000 */ 	mtc1	$at,$f6
/*  f029e24:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f029e28:	46089002 */ 	mul.s	$f0,$f18,$f8
/*  f029e2c:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f029e30:	46062480 */ 	add.s	$f18,$f4,$f6
/*  f029e34:	46009203 */ 	div.s	$f8,$f18,$f0
/*  f029e38:	46087302 */ 	mul.s	$f12,$f14,$f8
/*  f029e3c:	00000000 */ 	nop
.PB0f029e40:
/*  f029e40:	0fc0a5b2 */ 	jal	chr0f0295f8
/*  f029e44:	27a700f8 */ 	addiu	$a3,$sp,0xf8
/*  f029e48:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f029e4c:	8fad00fc */ 	lw	$t5,0xfc($sp)
/*  f029e50:	8fbf00f8 */ 	lw	$ra,0xf8($sp)
/*  f029e54:	2587ffec */ 	addiu	$a3,$t4,-20
/*  f029e58:	25a3ffec */ 	addiu	$v1,$t5,-20
/*  f029e5c:	27e4ffec */ 	addiu	$a0,$ra,-20
/*  f029e60:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029e64:	00605025 */ 	move	$t2,$v1
/*  f029e68:	04e10002 */ 	bgez	$a3,.PB0f029e74
/*  f029e6c:	00805825 */ 	move	$t3,$a0
/*  f029e70:	00003825 */ 	move	$a3,$zero
.PB0f029e74:
/*  f029e74:	04610002 */ 	bgez	$v1,.PB0f029e80
/*  f029e78:	2582ffc4 */ 	addiu	$v0,$t4,-60
/*  f029e7c:	00005025 */ 	move	$t2,$zero
.PB0f029e80:
/*  f029e80:	04810002 */ 	bgez	$a0,.PB0f029e8c
/*  f029e84:	25a3ffc4 */ 	addiu	$v1,$t5,-60
/*  f029e88:	00005825 */ 	move	$t3,$zero
.PB0f029e8c:
/*  f029e8c:	27e4ffc4 */ 	addiu	$a0,$ra,-60
/*  f029e90:	afa200e8 */ 	sw	$v0,0xe8($sp)
/*  f029e94:	afa300e4 */ 	sw	$v1,0xe4($sp)
/*  f029e98:	04410002 */ 	bgez	$v0,.PB0f029ea4
/*  f029e9c:	afa400e0 */ 	sw	$a0,0xe0($sp)
/*  f029ea0:	afa000e8 */ 	sw	$zero,0xe8($sp)
.PB0f029ea4:
/*  f029ea4:	04610002 */ 	bgez	$v1,.PB0f029eb0
/*  f029ea8:	3c19800a */ 	lui	$t9,0x800a
/*  f029eac:	afa000e4 */ 	sw	$zero,0xe4($sp)
.PB0f029eb0:
/*  f029eb0:	04810002 */ 	bgez	$a0,.PB0f029ebc
/*  f029eb4:	00000000 */ 	nop
/*  f029eb8:	afa000e0 */ 	sw	$zero,0xe0($sp)
.PB0f029ebc:
/*  f029ebc:	8f39e528 */ 	lw	$t9,-0x1ad8($t9)
/*  f029ec0:	241003e8 */ 	li	$s0,0x3e8
/*  f029ec4:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f029ec8:	0330001a */ 	div	$zero,$t9,$s0
/*  f029ecc:	00007810 */ 	mfhi	$t7
/*  f029ed0:	448f8000 */ 	mtc1	$t7,$f16
/*  f029ed4:	16000002 */ 	bnez	$s0,.PB0f029ee0
/*  f029ed8:	00000000 */ 	nop
/*  f029edc:	0007000d */ 	break	0x7
.PB0f029ee0:
/*  f029ee0:	2401ffff */ 	li	$at,-1
/*  f029ee4:	16010004 */ 	bne	$s0,$at,.PB0f029ef8
/*  f029ee8:	3c018000 */ 	lui	$at,0x8000
/*  f029eec:	17210002 */ 	bne	$t9,$at,.PB0f029ef8
/*  f029ef0:	00000000 */ 	nop
/*  f029ef4:	0006000d */ 	break	0x6
.PB0f029ef8:
/*  f029ef8:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f029efc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f029f00:	c424a614 */ 	lwc1	$f4,-0x59ec($at)
/*  f029f04:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f029f08:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f029f0c:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f029f10:	0c006b8b */ 	jal	sinf
/*  f029f14:	00000000 */ 	nop
/*  f029f18:	3c0f800a */ 	lui	$t7,0x800a
/*  f029f1c:	8defe528 */ 	lw	$t7,-0x1ad8($t7)
/*  f029f20:	3c014200 */ 	lui	$at,0x4200
/*  f029f24:	44811000 */ 	mtc1	$at,$f2
/*  f029f28:	01f0001a */ 	div	$zero,$t7,$s0
/*  f029f2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f029f30:	44813000 */ 	mtc1	$at,$f6
/*  f029f34:	3c013f00 */ 	lui	$at,0x3f00
/*  f029f38:	44814000 */ 	mtc1	$at,$f8
/*  f029f3c:	46060480 */ 	add.s	$f18,$f0,$f6
/*  f029f40:	0000c010 */ 	mfhi	$t8
/*  f029f44:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f029f48:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029f4c:	46089402 */ 	mul.s	$f16,$f18,$f8
/*  f029f50:	44989000 */ 	mtc1	$t8,$f18
/*  f029f54:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f029f58:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f029f5c:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f029f60:	46028282 */ 	mul.s	$f10,$f16,$f2
/*  f029f64:	00000000 */ 	nop
/*  f029f68:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f029f6c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f029f70:	44153000 */ 	mfc1	$s5,$f6
/*  f029f74:	00000000 */ 	nop
/*  f029f78:	00157400 */ 	sll	$t6,$s5,0x10
/*  f029f7c:	000ecc03 */ 	sra	$t9,$t6,0x10
/*  f029f80:	0320a825 */ 	move	$s5,$t9
/*  f029f84:	16000002 */ 	bnez	$s0,.PB0f029f90
/*  f029f88:	00000000 */ 	nop
/*  f029f8c:	0007000d */ 	break	0x7
.PB0f029f90:
/*  f029f90:	2401ffff */ 	li	$at,-1
/*  f029f94:	16010004 */ 	bne	$s0,$at,.PB0f029fa8
/*  f029f98:	3c018000 */ 	lui	$at,0x8000
/*  f029f9c:	15e10002 */ 	bne	$t7,$at,.PB0f029fa8
/*  f029fa0:	00000000 */ 	nop
/*  f029fa4:	0006000d */ 	break	0x6
.PB0f029fa8:
/*  f029fa8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f029fac:	c430a618 */ 	lwc1	$f16,-0x59e8($at)
/*  f029fb0:	46104302 */ 	mul.s	$f12,$f8,$f16
/*  f029fb4:	0c006b88 */ 	jal	cosf
/*  f029fb8:	00000000 */ 	nop
/*  f029fbc:	3c014200 */ 	lui	$at,0x4200
/*  f029fc0:	44811000 */ 	mtc1	$at,$f2
/*  f029fc4:	3c013f80 */ 	lui	$at,0x3f80
/*  f029fc8:	44816000 */ 	mtc1	$at,$f12
/*  f029fcc:	3c013f00 */ 	lui	$at,0x3f00
/*  f029fd0:	44812000 */ 	mtc1	$at,$f4
/*  f029fd4:	460c0280 */ 	add.s	$f10,$f0,$f12
/*  f029fd8:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029fdc:	26af0200 */ 	addiu	$t7,$s5,0x200
/*  f029fe0:	2401fffd */ 	li	$at,-3
/*  f029fe4:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f029fe8:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f029fec:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f029ff0:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f029ff4:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f029ff8:	a7af0176 */ 	sh	$t7,0x176($sp)
/*  f029ffc:	24040001 */ 	li	$a0,0x1
/*  f02a000:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f02a004:	00000000 */ 	nop
/*  f02a008:	46029202 */ 	mul.s	$f8,$f18,$f2
/*  f02a00c:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f02a010:	440e8000 */ 	mfc1	$t6,$f16
/*  f02a014:	00000000 */ 	nop
/*  f02a018:	000e9c00 */ 	sll	$s3,$t6,0x10
/*  f02a01c:	0013cc03 */ 	sra	$t9,$s3,0x10
/*  f02a020:	03209825 */ 	move	$s3,$t9
/*  f02a024:	25d40200 */ 	addiu	$s4,$t6,0x200
/*  f02a028:	0014cc00 */ 	sll	$t9,$s4,0x10
/*  f02a02c:	11010008 */ 	beq	$t0,$at,.PB0f02a050
/*  f02a030:	0019a403 */ 	sra	$s4,$t9,0x10
/*  f02a034:	2401fffc */ 	li	$at,-4
/*  f02a038:	11010005 */ 	beq	$t0,$at,.PB0f02a050
/*  f02a03c:	2401fffb */ 	li	$at,-5
/*  f02a040:	11010003 */ 	beq	$t0,$at,.PB0f02a050
/*  f02a044:	2401fffa */ 	li	$at,-6
/*  f02a048:	5501016b */ 	bnel	$t0,$at,.PB0f02a5f8
/*  f02a04c:	2401fffe */ 	li	$at,-2
.PB0f02a050:
/*  f02a050:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02a054:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02a058:	0fc5a40f */ 	jal	gfxAllocateColours
/*  f02a05c:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02a060:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f02a064:	3c190700 */ 	lui	$t9,0x700
/*  f02a068:	37390004 */ 	ori	$t9,$t9,0x4
/*  f02a06c:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f02a070:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02a074:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f02a078:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02a07c:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02a080:	00402025 */ 	move	$a0,$v0
/*  f02a084:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02a088:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a08c:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02a090:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02a094:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02a098:	2401fffd */ 	li	$at,-3
/*  f02a09c:	15010014 */ 	bne	$t0,$at,.PB0f02a0f0
/*  f02a0a0:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f02a0a4:	a0670000 */ 	sb	$a3,0x0($v1)
/*  f02a0a8:	a06a0001 */ 	sb	$t2,0x1($v1)
/*  f02a0ac:	a06b0002 */ 	sb	$t3,0x2($v1)
/*  f02a0b0:	8faf0164 */ 	lw	$t7,0x164($sp)
/*  f02a0b4:	8fb80210 */ 	lw	$t8,0x210($sp)
/*  f02a0b8:	29e1000a */ 	slti	$at,$t7,0xa
/*  f02a0bc:	1020000a */ 	beqz	$at,.PB0f02a0e8
/*  f02a0c0:	00000000 */ 	nop
/*  f02a0c4:	44985000 */ 	mtc1	$t8,$f10
/*  f02a0c8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a0cc:	c426a61c */ 	lwc1	$f6,-0x59e4($at)
/*  f02a0d0:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f02a0d4:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f02a0d8:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f02a0dc:	44194000 */ 	mfc1	$t9,$f8
/*  f02a0e0:	10000031 */ 	b	.PB0f02a1a8
/*  f02a0e4:	a0790003 */ 	sb	$t9,0x3($v1)
.PB0f02a0e8:
/*  f02a0e8:	1000002f */ 	b	.PB0f02a1a8
/*  f02a0ec:	a0600003 */ 	sb	$zero,0x3($v1)
.PB0f02a0f0:
/*  f02a0f0:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f02a0f4:	a06f0000 */ 	sb	$t7,0x0($v1)
/*  f02a0f8:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f02a0fc:	a0780001 */ 	sb	$t8,0x1($v1)
/*  f02a100:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f02a104:	a06e0002 */ 	sb	$t6,0x2($v1)
/*  f02a108:	8fb90164 */ 	lw	$t9,0x164($sp)
/*  f02a10c:	2b21000a */ 	slti	$at,$t9,0xa
/*  f02a110:	10200024 */ 	beqz	$at,.PB0f02a1a4
/*  f02a114:	2401fffc */ 	li	$at,-4
/*  f02a118:	1501000a */ 	bne	$t0,$at,.PB0f02a144
/*  f02a11c:	8faf0210 */ 	lw	$t7,0x210($sp)
/*  f02a120:	448f8000 */ 	mtc1	$t7,$f16
/*  f02a124:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a128:	c424a620 */ 	lwc1	$f4,-0x59e0($at)
/*  f02a12c:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a130:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f02a134:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f02a138:	440e9000 */ 	mfc1	$t6,$f18
/*  f02a13c:	1000001a */ 	b	.PB0f02a1a8
/*  f02a140:	a06e0003 */ 	sb	$t6,0x3($v1)
.PB0f02a144:
/*  f02a144:	2401fffb */ 	li	$at,-5
/*  f02a148:	1501000a */ 	bne	$t0,$at,.PB0f02a174
/*  f02a14c:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02a150:	44994000 */ 	mtc1	$t9,$f8
/*  f02a154:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a158:	c42aa624 */ 	lwc1	$f10,-0x59dc($at)
/*  f02a15c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f02a160:	460a8102 */ 	mul.s	$f4,$f16,$f10
/*  f02a164:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f02a168:	44183000 */ 	mfc1	$t8,$f6
/*  f02a16c:	1000000e */ 	b	.PB0f02a1a8
/*  f02a170:	a0780003 */ 	sb	$t8,0x3($v1)
.PB0f02a174:
/*  f02a174:	2401fffa */ 	li	$at,-6
/*  f02a178:	1501000b */ 	bne	$t0,$at,.PB0f02a1a8
/*  f02a17c:	8fae0210 */ 	lw	$t6,0x210($sp)
/*  f02a180:	448e9000 */ 	mtc1	$t6,$f18
/*  f02a184:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a188:	c430a628 */ 	lwc1	$f16,-0x59d8($at)
/*  f02a18c:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f02a190:	46104282 */ 	mul.s	$f10,$f8,$f16
/*  f02a194:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f02a198:	440f2000 */ 	mfc1	$t7,$f4
/*  f02a19c:	10000002 */ 	b	.PB0f02a1a8
/*  f02a1a0:	a06f0003 */ 	sb	$t7,0x3($v1)
.PB0f02a1a4:
/*  f02a1a4:	a0600003 */ 	sb	$zero,0x3($v1)
.PB0f02a1a8:
/*  f02a1a8:	24040018 */ 	li	$a0,0x18
/*  f02a1ac:	afa301d8 */ 	sw	$v1,0x1d8($sp)
/*  f02a1b0:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02a1b4:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02a1b8:	0fc5a3f5 */ 	jal	gfxAllocateVertices
/*  f02a1bc:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02a1c0:	8fa501f8 */ 	lw	$a1,0x1f8($sp)
/*  f02a1c4:	24010001 */ 	li	$at,0x1
/*  f02a1c8:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a1cc:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f02a1d0:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02a1d4:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02a1d8:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02a1dc:	10810006 */ 	beq	$a0,$at,.PB0f02a1f8
/*  f02a1e0:	00408025 */ 	move	$s0,$v0
/*  f02a1e4:	24090004 */ 	li	$t1,0x4
/*  f02a1e8:	11240003 */ 	beq	$t1,$a0,.PB0f02a1f8
/*  f02a1ec:	24010002 */ 	li	$at,0x2
/*  f02a1f0:	548100b0 */ 	bnel	$a0,$at,.PB0f02a4b4
/*  f02a1f4:	24080200 */ 	li	$t0,0x200
.PB0f02a1f8:
/*  f02a1f8:	8cb80004 */ 	lw	$t8,0x4($a1)
/*  f02a1fc:	24090004 */ 	li	$t1,0x4
/*  f02a200:	3c0f800a */ 	lui	$t7,0x800a
/*  f02a204:	8f0e0010 */ 	lw	$t6,0x10($t8)
/*  f02a208:	31d91000 */ 	andi	$t9,$t6,0x1000
/*  f02a20c:	532000a9 */ 	beqzl	$t9,.PB0f02a4b4
/*  f02a210:	24080200 */ 	li	$t0,0x200
/*  f02a214:	8defe528 */ 	lw	$t7,-0x1ad8($t7)
/*  f02a218:	24010123 */ 	li	$at,0x123
/*  f02a21c:	afa301d8 */ 	sw	$v1,0x1d8($sp)
/*  f02a220:	01e1001a */ 	div	$zero,$t7,$at
/*  f02a224:	0000c010 */ 	mfhi	$t8
/*  f02a228:	44983000 */ 	mtc1	$t8,$f6
/*  f02a22c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a230:	c428a62c */ 	lwc1	$f8,-0x59d4($at)
/*  f02a234:	468034a0 */ 	cvt.s.w	$f18,$f6
/*  f02a238:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02a23c:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02a240:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02a244:	46089302 */ 	mul.s	$f12,$f18,$f8
/*  f02a248:	0c006b8b */ 	jal	sinf
/*  f02a24c:	00000000 */ 	nop
/*  f02a250:	3c013f80 */ 	lui	$at,0x3f80
/*  f02a254:	44818000 */ 	mtc1	$at,$f16
/*  f02a258:	3c013f00 */ 	lui	$at,0x3f00
/*  f02a25c:	44812000 */ 	mtc1	$at,$f4
/*  f02a260:	46100280 */ 	add.s	$f10,$f0,$f16
/*  f02a264:	3c0142f0 */ 	lui	$at,0x42f0
/*  f02a268:	44813000 */ 	mtc1	$at,$f6
/*  f02a26c:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02a270:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f02a274:	3c014248 */ 	lui	$at,0x4248
/*  f02a278:	44818000 */ 	mtc1	$at,$f16
/*  f02a27c:	30ee00ff */ 	andi	$t6,$a3,0xff
/*  f02a280:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a284:	448e5000 */ 	mtc1	$t6,$f10
/*  f02a288:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02a28c:	460c3482 */ 	mul.s	$f18,$f6,$f12
/*  f02a290:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02a294:	24090004 */ 	li	$t1,0x4
/*  f02a298:	460c8082 */ 	mul.s	$f2,$f16,$f12
/*  f02a29c:	3c014f80 */ 	lui	$at,0x4f80
/*  f02a2a0:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f02a2a4:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f02a2a8:	440f4000 */ 	mfc1	$t7,$f8
/*  f02a2ac:	00000000 */ 	nop
/*  f02a2b0:	25f80032 */ 	addiu	$t8,$t7,0x32
/*  f02a2b4:	05c10004 */ 	bgez	$t6,.PB0f02a2c8
/*  f02a2b8:	a0780003 */ 	sb	$t8,0x3($v1)
/*  f02a2bc:	44813000 */ 	mtc1	$at,$f6
/*  f02a2c0:	00000000 */ 	nop
/*  f02a2c4:	46062100 */ 	add.s	$f4,$f4,$f6
.PB0f02a2c8:
/*  f02a2c8:	46022480 */ 	add.s	$f18,$f4,$f2
/*  f02a2cc:	240f0001 */ 	li	$t7,0x1
/*  f02a2d0:	3c014f00 */ 	lui	$at,0x4f00
/*  f02a2d4:	315800ff */ 	andi	$t8,$t2,0xff
/*  f02a2d8:	4459f800 */ 	cfc1	$t9,$31
/*  f02a2dc:	44cff800 */ 	ctc1	$t7,$31
/*  f02a2e0:	00000000 */ 	nop
/*  f02a2e4:	46009224 */ 	cvt.w.s	$f8,$f18
/*  f02a2e8:	444ff800 */ 	cfc1	$t7,$31
/*  f02a2ec:	00000000 */ 	nop
/*  f02a2f0:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f02a2f4:	51e00013 */ 	beqzl	$t7,.PB0f02a344
/*  f02a2f8:	440f4000 */ 	mfc1	$t7,$f8
/*  f02a2fc:	44814000 */ 	mtc1	$at,$f8
/*  f02a300:	240f0001 */ 	li	$t7,0x1
/*  f02a304:	46089201 */ 	sub.s	$f8,$f18,$f8
/*  f02a308:	44cff800 */ 	ctc1	$t7,$31
/*  f02a30c:	00000000 */ 	nop
/*  f02a310:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f02a314:	444ff800 */ 	cfc1	$t7,$31
/*  f02a318:	00000000 */ 	nop
/*  f02a31c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f02a320:	15e00005 */ 	bnez	$t7,.PB0f02a338
/*  f02a324:	00000000 */ 	nop
/*  f02a328:	440f4000 */ 	mfc1	$t7,$f8
/*  f02a32c:	3c018000 */ 	lui	$at,0x8000
/*  f02a330:	10000007 */ 	b	.PB0f02a350
/*  f02a334:	01e17825 */ 	or	$t7,$t7,$at
.PB0f02a338:
/*  f02a338:	10000005 */ 	b	.PB0f02a350
/*  f02a33c:	240fffff */ 	li	$t7,-1
/*  f02a340:	440f4000 */ 	mfc1	$t7,$f8
.PB0f02a344:
/*  f02a344:	00000000 */ 	nop
/*  f02a348:	05e0fffb */ 	bltz	$t7,.PB0f02a338
/*  f02a34c:	00000000 */ 	nop
.PB0f02a350:
/*  f02a350:	44d9f800 */ 	ctc1	$t9,$31
/*  f02a354:	44988000 */ 	mtc1	$t8,$f16
/*  f02a358:	a06f0000 */ 	sb	$t7,0x0($v1)
/*  f02a35c:	07010005 */ 	bgez	$t8,.PB0f02a374
/*  f02a360:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a364:	3c014f80 */ 	lui	$at,0x4f80
/*  f02a368:	44813000 */ 	mtc1	$at,$f6
/*  f02a36c:	00000000 */ 	nop
/*  f02a370:	46065280 */ 	add.s	$f10,$f10,$f6
.PB0f02a374:
/*  f02a374:	46025100 */ 	add.s	$f4,$f10,$f2
/*  f02a378:	24190001 */ 	li	$t9,0x1
/*  f02a37c:	3c014f00 */ 	lui	$at,0x4f00
/*  f02a380:	316f00ff */ 	andi	$t7,$t3,0xff
/*  f02a384:	444ef800 */ 	cfc1	$t6,$31
/*  f02a388:	44d9f800 */ 	ctc1	$t9,$31
/*  f02a38c:	00000000 */ 	nop
/*  f02a390:	460024a4 */ 	cvt.w.s	$f18,$f4
/*  f02a394:	4459f800 */ 	cfc1	$t9,$31
/*  f02a398:	00000000 */ 	nop
/*  f02a39c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f02a3a0:	53200013 */ 	beqzl	$t9,.PB0f02a3f0
/*  f02a3a4:	44199000 */ 	mfc1	$t9,$f18
/*  f02a3a8:	44819000 */ 	mtc1	$at,$f18
/*  f02a3ac:	24190001 */ 	li	$t9,0x1
/*  f02a3b0:	46122481 */ 	sub.s	$f18,$f4,$f18
/*  f02a3b4:	44d9f800 */ 	ctc1	$t9,$31
/*  f02a3b8:	00000000 */ 	nop
/*  f02a3bc:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f02a3c0:	4459f800 */ 	cfc1	$t9,$31
/*  f02a3c4:	00000000 */ 	nop
/*  f02a3c8:	33390078 */ 	andi	$t9,$t9,0x78
/*  f02a3cc:	17200005 */ 	bnez	$t9,.PB0f02a3e4
/*  f02a3d0:	00000000 */ 	nop
/*  f02a3d4:	44199000 */ 	mfc1	$t9,$f18
/*  f02a3d8:	3c018000 */ 	lui	$at,0x8000
/*  f02a3dc:	10000007 */ 	b	.PB0f02a3fc
/*  f02a3e0:	0321c825 */ 	or	$t9,$t9,$at
.PB0f02a3e4:
/*  f02a3e4:	10000005 */ 	b	.PB0f02a3fc
/*  f02a3e8:	2419ffff */ 	li	$t9,-1
/*  f02a3ec:	44199000 */ 	mfc1	$t9,$f18
.PB0f02a3f0:
/*  f02a3f0:	00000000 */ 	nop
/*  f02a3f4:	0720fffb */ 	bltz	$t9,.PB0f02a3e4
/*  f02a3f8:	00000000 */ 	nop
.PB0f02a3fc:
/*  f02a3fc:	44cef800 */ 	ctc1	$t6,$31
/*  f02a400:	448f4000 */ 	mtc1	$t7,$f8
/*  f02a404:	a0790001 */ 	sb	$t9,0x1($v1)
/*  f02a408:	05e10005 */ 	bgez	$t7,.PB0f02a420
/*  f02a40c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f02a410:	3c014f80 */ 	lui	$at,0x4f80
/*  f02a414:	44813000 */ 	mtc1	$at,$f6
/*  f02a418:	00000000 */ 	nop
/*  f02a41c:	46068400 */ 	add.s	$f16,$f16,$f6
.PB0f02a420:
/*  f02a420:	46028280 */ 	add.s	$f10,$f16,$f2
/*  f02a424:	240e0001 */ 	li	$t6,0x1
/*  f02a428:	3c014f00 */ 	lui	$at,0x4f00
/*  f02a42c:	4458f800 */ 	cfc1	$t8,$31
/*  f02a430:	44cef800 */ 	ctc1	$t6,$31
/*  f02a434:	00000000 */ 	nop
/*  f02a438:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f02a43c:	444ef800 */ 	cfc1	$t6,$31
/*  f02a440:	00000000 */ 	nop
/*  f02a444:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f02a448:	51c00013 */ 	beqzl	$t6,.PB0f02a498
/*  f02a44c:	440e2000 */ 	mfc1	$t6,$f4
/*  f02a450:	44812000 */ 	mtc1	$at,$f4
/*  f02a454:	240e0001 */ 	li	$t6,0x1
/*  f02a458:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f02a45c:	44cef800 */ 	ctc1	$t6,$31
/*  f02a460:	00000000 */ 	nop
/*  f02a464:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f02a468:	444ef800 */ 	cfc1	$t6,$31
/*  f02a46c:	00000000 */ 	nop
/*  f02a470:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f02a474:	15c00005 */ 	bnez	$t6,.PB0f02a48c
/*  f02a478:	00000000 */ 	nop
/*  f02a47c:	440e2000 */ 	mfc1	$t6,$f4
/*  f02a480:	3c018000 */ 	lui	$at,0x8000
/*  f02a484:	10000007 */ 	b	.PB0f02a4a4
/*  f02a488:	01c17025 */ 	or	$t6,$t6,$at
.PB0f02a48c:
/*  f02a48c:	10000005 */ 	b	.PB0f02a4a4
/*  f02a490:	240effff */ 	li	$t6,-1
/*  f02a494:	440e2000 */ 	mfc1	$t6,$f4
.PB0f02a498:
/*  f02a498:	00000000 */ 	nop
/*  f02a49c:	05c0fffb */ 	bltz	$t6,.PB0f02a48c
/*  f02a4a0:	00000000 */ 	nop
.PB0f02a4a4:
/*  f02a4a4:	44d8f800 */ 	ctc1	$t8,$31
/*  f02a4a8:	10000006 */ 	b	.PB0f02a4c4
/*  f02a4ac:	a06e0002 */ 	sb	$t6,0x2($v1)
/*  f02a4b0:	24080200 */ 	li	$t0,0x200
.PB0f02a4b4:
/*  f02a4b4:	0000a825 */ 	move	$s5,$zero
/*  f02a4b8:	00009825 */ 	move	$s3,$zero
/*  f02a4bc:	a7a80176 */ 	sh	$t0,0x176($sp)
/*  f02a4c0:	24140200 */ 	li	$s4,0x200
.PB0f02a4c4:
/*  f02a4c4:	27a60104 */ 	addiu	$a2,$sp,0x104
/*  f02a4c8:	27a50180 */ 	addiu	$a1,$sp,0x180
.PB0f02a4cc:
/*  f02a4cc:	87a80176 */ 	lh	$t0,0x176($sp)
/*  f02a4d0:	00002025 */ 	move	$a0,$zero
/*  f02a4d4:	02001825 */ 	move	$v1,$s0
/*  f02a4d8:	00c01025 */ 	move	$v0,$a2
.PB0f02a4dc:
/*  f02a4dc:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02a4e0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f02a4e4:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02a4e8:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f02a4ec:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f02a4f0:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f02a4f4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f02a4f8:	a878fff8 */ 	swl	$t8,-0x8($v1)
/*  f02a4fc:	b878fffb */ 	swr	$t8,-0x5($v1)
/*  f02a500:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02a504:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02a508:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02a50c:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f02a510:	01d10019 */ 	multu	$t6,$s1
/*  f02a514:	00007812 */ 	mflo	$t7
/*  f02a518:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02a51c:	87380000 */ 	lh	$t8,0x0($t9)
/*  f02a520:	a478fff4 */ 	sh	$t8,-0xc($v1)
/*  f02a524:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f02a528:	01d10019 */ 	multu	$t6,$s1
/*  f02a52c:	00007812 */ 	mflo	$t7
/*  f02a530:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02a534:	87380002 */ 	lh	$t8,0x2($t9)
/*  f02a538:	a478fff6 */ 	sh	$t8,-0xa($v1)
/*  f02a53c:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f02a540:	01d10019 */ 	multu	$t6,$s1
/*  f02a544:	00007812 */ 	mflo	$t7
/*  f02a548:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02a54c:	87380004 */ 	lh	$t8,0x4($t9)
/*  f02a550:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02a554:	1489ffe1 */ 	bne	$a0,$t1,.PB0f02a4dc
/*  f02a558:	a478fff8 */ 	sh	$t8,-0x8($v1)
/*  f02a55c:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02a560:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02a564:	a6080014 */ 	sh	$t0,0x14($s0)
/*  f02a568:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02a56c:	a6080020 */ 	sh	$t0,0x20($s0)
/*  f02a570:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02a574:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02a578:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02a57c:	8fae01f0 */ 	lw	$t6,0x1f0($sp)
/*  f02a580:	3c190430 */ 	lui	$t9,0x430
/*  f02a584:	37390030 */ 	ori	$t9,$t9,0x30
/*  f02a588:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f02a58c:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02a590:	add90000 */ 	sw	$t9,0x0($t6)
/*  f02a594:	a7a80176 */ 	sh	$t0,0x176($sp)
/*  f02a598:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f02a59c:	02002025 */ 	move	$a0,$s0
/*  f02a5a0:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02a5a4:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f02a5a8:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f02a5ac:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f02a5b0:	3c0fb100 */ 	lui	$t7,0xb100
/*  f02a5b4:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f02a5b8:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02a5bc:	35ef0032 */ 	ori	$t7,$t7,0x32
/*  f02a5c0:	24192010 */ 	li	$t9,0x2010
/*  f02a5c4:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f02a5c8:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02a5cc:	af190004 */ 	sw	$t9,0x4($t8)
/*  f02a5d0:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f02a5d4:	27b80164 */ 	addiu	$t8,$sp,0x164
/*  f02a5d8:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f02a5dc:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02a5e0:	24090004 */ 	li	$t1,0x4
/*  f02a5e4:	14d8ffb9 */ 	bne	$a2,$t8,.PB0f02a4cc
/*  f02a5e8:	26100030 */ 	addiu	$s0,$s0,0x30
/*  f02a5ec:	100004a4 */ 	b	.PB0f02b880
/*  f02a5f0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f02a5f4:	2401fffe */ 	li	$at,-2
.PB0f02a5f8:
/*  f02a5f8:	150100d5 */ 	bne	$t0,$at,.PB0f02a950
/*  f02a5fc:	8fae01f4 */ 	lw	$t6,0x1f4($sp)
/*  f02a600:	8fa3020c */ 	lw	$v1,0x20c($sp)
/*  f02a604:	81c20011 */ 	lb	$v0,0x11($t6)
/*  f02a608:	8faf0208 */ 	lw	$t7,0x208($sp)
/*  f02a60c:	24040003 */ 	li	$a0,0x3
/*  f02a610:	0043082a */ 	slt	$at,$v0,$v1
/*  f02a614:	50200005 */ 	beqzl	$at,.PB0f02a62c
/*  f02a618:	448f3000 */ 	mtc1	$t7,$f6
/*  f02a61c:	44806000 */ 	mtc1	$zero,$f12
/*  f02a620:	1000001f */ 	b	.PB0f02a6a0
/*  f02a624:	46006086 */ 	mov.s	$f2,$f12
/*  f02a628:	448f3000 */ 	mtc1	$t7,$f6
.PB0f02a62c:
/*  f02a62c:	3c0141c8 */ 	lui	$at,0x41c8
/*  f02a630:	44814000 */ 	mtc1	$at,$f8
/*  f02a634:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f02a638:	44829000 */ 	mtc1	$v0,$f18
/*  f02a63c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a640:	c424a630 */ 	lwc1	$f4,-0x59d0($at)
/*  f02a644:	3c014220 */ 	lui	$at,0x4220
/*  f02a648:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f02a64c:	44813000 */ 	mtc1	$at,$f6
/*  f02a650:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02a654:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a658:	46104281 */ 	sub.s	$f10,$f8,$f16
/*  f02a65c:	44838000 */ 	mtc1	$v1,$f16
/*  f02a660:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f02a664:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a668:	44998000 */ 	mtc1	$t9,$f16
/*  f02a66c:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f02a670:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f02a674:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a678:	460c2480 */ 	add.s	$f18,$f4,$f12
/*  f02a67c:	c424a634 */ 	lwc1	$f4,-0x59cc($at)
/*  f02a680:	44806000 */ 	mtc1	$zero,$f12
/*  f02a684:	46009183 */ 	div.s	$f6,$f18,$f0
/*  f02a688:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f02a68c:	00000000 */ 	nop
/*  f02a690:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f02a694:	00000000 */ 	nop
/*  f02a698:	46121082 */ 	mul.s	$f2,$f2,$f18
/*  f02a69c:	00000000 */ 	nop
.PB0f02a6a0:
/*  f02a6a0:	3c01437f */ 	lui	$at,0x437f
/*  f02a6a4:	44810000 */ 	mtc1	$at,$f0
/*  f02a6a8:	00000000 */ 	nop
/*  f02a6ac:	4602003c */ 	c.lt.s	$f0,$f2
/*  f02a6b0:	00000000 */ 	nop
/*  f02a6b4:	45020004 */ 	bc1fl	.PB0f02a6c8
/*  f02a6b8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f02a6bc:	10000006 */ 	b	.PB0f02a6d8
/*  f02a6c0:	46000086 */ 	mov.s	$f2,$f0
/*  f02a6c4:	460c103c */ 	c.lt.s	$f2,$f12
.PB0f02a6c8:
/*  f02a6c8:	00000000 */ 	nop
/*  f02a6cc:	45000002 */ 	bc1f	.PB0f02a6d8
/*  f02a6d0:	00000000 */ 	nop
/*  f02a6d4:	46006086 */ 	mov.s	$f2,$f12
.PB0f02a6d8:
/*  f02a6d8:	0fc5a40f */ 	jal	gfxAllocateColours
/*  f02a6dc:	e7a200ac */ 	swc1	$f2,0xac($sp)
/*  f02a6e0:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f02a6e4:	3c0f0708 */ 	lui	$t7,0x708
/*  f02a6e8:	35ef000c */ 	ori	$t7,$t7,0xc
/*  f02a6ec:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f02a6f0:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02a6f4:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f02a6f8:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02a6fc:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02a700:	00402025 */ 	move	$a0,$v0
/*  f02a704:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a708:	c7a200ac */ 	lwc1	$f2,0xac($sp)
/*  f02a70c:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f02a710:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f02a714:	8fa700e0 */ 	lw	$a3,0xe0($sp)
/*  f02a718:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f02a71c:	4600120d */ 	trunc.w.s	$f8,$f2
/*  f02a720:	2404001e */ 	li	$a0,0x1e
/*  f02a724:	a0600007 */ 	sb	$zero,0x7($v1)
/*  f02a728:	a0650000 */ 	sb	$a1,0x0($v1)
/*  f02a72c:	44184000 */ 	mfc1	$t8,$f8
/*  f02a730:	a0650004 */ 	sb	$a1,0x4($v1)
/*  f02a734:	a0660001 */ 	sb	$a2,0x1($v1)
/*  f02a738:	a0660005 */ 	sb	$a2,0x5($v1)
/*  f02a73c:	a0670002 */ 	sb	$a3,0x2($v1)
/*  f02a740:	a0670006 */ 	sb	$a3,0x6($v1)
/*  f02a744:	0fc5a3f5 */ 	jal	gfxAllocateVertices
/*  f02a748:	a0780003 */ 	sb	$t8,0x3($v1)
/*  f02a74c:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f02a750:	02747021 */ 	addu	$t6,$s3,$s4
/*  f02a754:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f02a758:	02abc821 */ 	addu	$t9,$s5,$t3
/*  f02a75c:	0019c043 */ 	sra	$t8,$t9,0x1
/*  f02a760:	00408025 */ 	move	$s0,$v0
/*  f02a764:	afb80040 */ 	sw	$t8,0x40($sp)
/*  f02a768:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f02a76c:	27a60104 */ 	addiu	$a2,$sp,0x104
/*  f02a770:	240c0004 */ 	li	$t4,0x4
/*  f02a774:	24090004 */ 	li	$t1,0x4
/*  f02a778:	27a50180 */ 	addiu	$a1,$sp,0x180
.PB0f02a77c:
/*  f02a77c:	00002025 */ 	move	$a0,$zero
/*  f02a780:	02001825 */ 	move	$v1,$s0
/*  f02a784:	00c01025 */ 	move	$v0,$a2
.PB0f02a788:
/*  f02a788:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02a78c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f02a790:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02a794:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f02a798:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f02a79c:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02a7a0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f02a7a4:	a879fff8 */ 	swl	$t9,-0x8($v1)
/*  f02a7a8:	b879fffb */ 	swr	$t9,-0x5($v1)
/*  f02a7ac:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02a7b0:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02a7b4:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02a7b8:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f02a7bc:	03110019 */ 	multu	$t8,$s1
/*  f02a7c0:	00007812 */ 	mflo	$t7
/*  f02a7c4:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f02a7c8:	85d90000 */ 	lh	$t9,0x0($t6)
/*  f02a7cc:	a479fff4 */ 	sh	$t9,-0xc($v1)
/*  f02a7d0:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f02a7d4:	03110019 */ 	multu	$t8,$s1
/*  f02a7d8:	00007812 */ 	mflo	$t7
/*  f02a7dc:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f02a7e0:	85d90002 */ 	lh	$t9,0x2($t6)
/*  f02a7e4:	a479fff6 */ 	sh	$t9,-0xa($v1)
/*  f02a7e8:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f02a7ec:	03110019 */ 	multu	$t8,$s1
/*  f02a7f0:	00007812 */ 	mflo	$t7
/*  f02a7f4:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f02a7f8:	85d90004 */ 	lh	$t9,0x4($t6)
/*  f02a7fc:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02a800:	1489ffe1 */ 	bne	$a0,$t1,.PB0f02a788
/*  f02a804:	a479fff8 */ 	sh	$t9,-0x8($v1)
/*  f02a808:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02a80c:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02a810:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02a814:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02a818:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02a81c:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02a820:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02a824:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02a828:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02a82c:	860e0024 */ 	lh	$t6,0x24($s0)
/*  f02a830:	86190000 */ 	lh	$t9,0x0($s0)
/*  f02a834:	aa010030 */ 	swl	$at,0x30($s0)
/*  f02a838:	ba010033 */ 	swr	$at,0x33($s0)
/*  f02a83c:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02a840:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a844:	86190018 */ 	lh	$t9,0x18($s0)
/*  f02a848:	aa0f0034 */ 	swl	$t7,0x34($s0)
/*  f02a84c:	ba0f0037 */ 	swr	$t7,0x37($s0)
/*  f02a850:	860f000c */ 	lh	$t7,0xc($s0)
/*  f02a854:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02a858:	02002025 */ 	move	$a0,$s0
/*  f02a85c:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f02a860:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a864:	86190002 */ 	lh	$t9,0x2($s0)
/*  f02a868:	860e0026 */ 	lh	$t6,0x26($s0)
/*  f02a86c:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02a870:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f02a874:	860f000e */ 	lh	$t7,0xe($s0)
/*  f02a878:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a87c:	8619001a */ 	lh	$t9,0x1a($s0)
/*  f02a880:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f02a884:	aa010038 */ 	swl	$at,0x38($s0)
/*  f02a888:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a88c:	86190004 */ 	lh	$t9,0x4($s0)
/*  f02a890:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f02a894:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02a898:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f02a89c:	860f0010 */ 	lh	$t7,0x10($s0)
/*  f02a8a0:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a8a4:	8619001c */ 	lh	$t9,0x1c($s0)
/*  f02a8a8:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f02a8ac:	ba01003b */ 	swr	$at,0x3b($s0)
/*  f02a8b0:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a8b4:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02a8b8:	a60f0034 */ 	sh	$t7,0x34($s0)
/*  f02a8bc:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f02a8c0:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02a8c4:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f02a8c8:	a20c0037 */ 	sb	$t4,0x37($s0)
/*  f02a8cc:	3c0e0440 */ 	lui	$t6,0x440
/*  f02a8d0:	a619003a */ 	sh	$t9,0x3a($s0)
/*  f02a8d4:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02a8d8:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02a8dc:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02a8e0:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02a8e4:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f02a8e8:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f02a8ec:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f02a8f0:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02a8f4:	afb800a4 */ 	sw	$t8,0xa4($sp)
/*  f02a8f8:	8fa700a4 */ 	lw	$a3,0xa4($sp)
/*  f02a8fc:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f02a900:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f02a904:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f02a908:	8fb901f0 */ 	lw	$t9,0x1f0($sp)
/*  f02a90c:	3c0fb100 */ 	lui	$t7,0xb100
/*  f02a910:	3c0e0332 */ 	lui	$t6,0x332
/*  f02a914:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f02a918:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f02a91c:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02a920:	35ef4444 */ 	ori	$t7,$t7,0x4444
/*  f02a924:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f02a928:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f02a92c:	27b90164 */ 	addiu	$t9,$sp,0x164
/*  f02a930:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f02a934:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02a938:	24090004 */ 	li	$t1,0x4
/*  f02a93c:	240c0004 */ 	li	$t4,0x4
/*  f02a940:	14d9ff8e */ 	bne	$a2,$t9,.PB0f02a77c
/*  f02a944:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f02a948:	100003cd */ 	b	.PB0f02b880
/*  f02a94c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PB0f02a950:
/*  f02a950:	05010130 */ 	bgez	$t0,.PB0f02ae14
/*  f02a954:	8fae01f8 */ 	lw	$t6,0x1f8($sp)
/*  f02a958:	0fc5a3f5 */ 	jal	gfxAllocateVertices
/*  f02a95c:	2404000c */ 	li	$a0,0xc
/*  f02a960:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02a964:	2401ffff */ 	li	$at,-1
/*  f02a968:	00408025 */ 	move	$s0,$v0
/*  f02a96c:	15010035 */ 	bne	$t0,$at,.PB0f02aa44
/*  f02a970:	8fb801f4 */ 	lw	$t8,0x1f4($sp)
/*  f02a974:	3c02800a */ 	lui	$v0,0x800a
/*  f02a978:	8c42e4d8 */ 	lw	$v0,-0x1b28($v0)
/*  f02a97c:	8f03000c */ 	lw	$v1,0xc($t8)
/*  f02a980:	00002825 */ 	move	$a1,$zero
/*  f02a984:	24040001 */ 	li	$a0,0x1
/*  f02a988:	00437823 */ 	subu	$t7,$v0,$v1
/*  f02a98c:	29e10043 */ 	slti	$at,$t7,0x43
/*  f02a990:	10200016 */ 	beqz	$at,.PB0f02a9ec
/*  f02a994:	00627023 */ 	subu	$t6,$v1,$v0
/*  f02a998:	25d90042 */ 	addiu	$t9,$t6,0x42
/*  f02a99c:	44993000 */ 	mtc1	$t9,$f6
/*  f02a9a0:	8fb80210 */ 	lw	$t8,0x210($sp)
/*  f02a9a4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a9a8:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f02a9ac:	44982000 */ 	mtc1	$t8,$f4
/*  f02a9b0:	c42aa638 */ 	lwc1	$f10,-0x59c8($at)
/*  f02a9b4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02a9b8:	c428a63c */ 	lwc1	$f8,-0x59c4($at)
/*  f02a9bc:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f02a9c0:	460a8002 */ 	mul.s	$f0,$f16,$f10
/*  f02a9c4:	00000000 */ 	nop
/*  f02a9c8:	46089182 */ 	mul.s	$f6,$f18,$f8
/*  f02a9cc:	00000000 */ 	nop
/*  f02a9d0:	46060002 */ 	mul.s	$f0,$f0,$f6
/*  f02a9d4:	4600040d */ 	trunc.w.s	$f16,$f0
/*  f02a9d8:	44058000 */ 	mfc1	$a1,$f16
/*  f02a9dc:	00000000 */ 	nop
/*  f02a9e0:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f02a9e4:	10000001 */ 	b	.PB0f02a9ec
/*  f02a9e8:	01c02825 */ 	move	$a1,$t6
.PB0f02a9ec:
/*  f02a9ec:	0fc5a40f */ 	jal	gfxAllocateColours
/*  f02a9f0:	a3a5017f */ 	sb	$a1,0x17f($sp)
/*  f02a9f4:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02a9f8:	3c0f0700 */ 	lui	$t7,0x700
/*  f02a9fc:	35ef0004 */ 	ori	$t7,$t7,0x4
/*  f02aa00:	26380008 */ 	addiu	$t8,$s1,0x8
/*  f02aa04:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f02aa08:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f02aa0c:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02aa10:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02aa14:	00402025 */ 	move	$a0,$v0
/*  f02aa18:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02aa1c:	93a5017f */ 	lbu	$a1,0x17f($sp)
/*  f02aa20:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02aa24:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f02aa28:	a06e0000 */ 	sb	$t6,0x0($v1)
/*  f02aa2c:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f02aa30:	a0790001 */ 	sb	$t9,0x1($v1)
/*  f02aa34:	8fb800f8 */ 	lw	$t8,0xf8($sp)
/*  f02aa38:	a0650003 */ 	sb	$a1,0x3($v1)
/*  f02aa3c:	10000053 */ 	b	.PB0f02ab8c
/*  f02aa40:	a0780002 */ 	sb	$t8,0x2($v1)
.PB0f02aa44:
/*  f02aa44:	2401fffe */ 	li	$at,-2
/*  f02aa48:	15010050 */ 	bne	$t0,$at,.PB0f02ab8c
/*  f02aa4c:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f02aa50:	8fa3020c */ 	lw	$v1,0x20c($sp)
/*  f02aa54:	81e20011 */ 	lb	$v0,0x11($t7)
/*  f02aa58:	8fae0208 */ 	lw	$t6,0x208($sp)
/*  f02aa5c:	24040001 */ 	li	$a0,0x1
/*  f02aa60:	0043082a */ 	slt	$at,$v0,$v1
/*  f02aa64:	50200005 */ 	beqzl	$at,.PB0f02aa7c
/*  f02aa68:	448e9000 */ 	mtc1	$t6,$f18
/*  f02aa6c:	44806000 */ 	mtc1	$zero,$f12
/*  f02aa70:	10000021 */ 	b	.PB0f02aaf8
/*  f02aa74:	46006086 */ 	mov.s	$f2,$f12
/*  f02aa78:	448e9000 */ 	mtc1	$t6,$f18
.PB0f02aa7c:
/*  f02aa7c:	3c0141c8 */ 	lui	$at,0x41c8
/*  f02aa80:	44812000 */ 	mtc1	$at,$f4
/*  f02aa84:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f02aa88:	44825000 */ 	mtc1	$v0,$f10
/*  f02aa8c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02aa90:	c430a640 */ 	lwc1	$f16,-0x59c0($at)
/*  f02aa94:	3c014220 */ 	lui	$at,0x4220
/*  f02aa98:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f02aa9c:	44819000 */ 	mtc1	$at,$f18
/*  f02aaa0:	3c013f80 */ 	lui	$at,0x3f80
/*  f02aaa4:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02aaa8:	44806000 */ 	mtc1	$zero,$f12
/*  f02aaac:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f02aab0:	44834000 */ 	mtc1	$v1,$f8
/*  f02aab4:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f02aab8:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f02aabc:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f02aac0:	44815000 */ 	mtc1	$at,$f10
/*  f02aac4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02aac8:	46060401 */ 	sub.s	$f16,$f0,$f6
/*  f02aacc:	44993000 */ 	mtc1	$t9,$f6
/*  f02aad0:	460a8480 */ 	add.s	$f18,$f16,$f10
/*  f02aad4:	c42aa644 */ 	lwc1	$f10,-0x59bc($at)
/*  f02aad8:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f02aadc:	46009203 */ 	div.s	$f8,$f18,$f0
/*  f02aae0:	46082082 */ 	mul.s	$f2,$f4,$f8
/*  f02aae4:	00000000 */ 	nop
/*  f02aae8:	460a8482 */ 	mul.s	$f18,$f16,$f10
/*  f02aaec:	00000000 */ 	nop
/*  f02aaf0:	46121082 */ 	mul.s	$f2,$f2,$f18
/*  f02aaf4:	00000000 */ 	nop
.PB0f02aaf8:
/*  f02aaf8:	3c01437f */ 	lui	$at,0x437f
/*  f02aafc:	44810000 */ 	mtc1	$at,$f0
/*  f02ab00:	00000000 */ 	nop
/*  f02ab04:	4602003c */ 	c.lt.s	$f0,$f2
/*  f02ab08:	00000000 */ 	nop
/*  f02ab0c:	45020004 */ 	bc1fl	.PB0f02ab20
/*  f02ab10:	460c103c */ 	c.lt.s	$f2,$f12
/*  f02ab14:	10000006 */ 	b	.PB0f02ab30
/*  f02ab18:	46000086 */ 	mov.s	$f2,$f0
/*  f02ab1c:	460c103c */ 	c.lt.s	$f2,$f12
.PB0f02ab20:
/*  f02ab20:	00000000 */ 	nop
/*  f02ab24:	45000002 */ 	bc1f	.PB0f02ab30
/*  f02ab28:	00000000 */ 	nop
/*  f02ab2c:	46006086 */ 	mov.s	$f2,$f12
.PB0f02ab30:
/*  f02ab30:	0fc5a40f */ 	jal	gfxAllocateColours
/*  f02ab34:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f02ab38:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02ab3c:	3c0e0700 */ 	lui	$t6,0x700
/*  f02ab40:	35ce0004 */ 	ori	$t6,$t6,0x4
/*  f02ab44:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f02ab48:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02ab4c:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f02ab50:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02ab54:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02ab58:	00402025 */ 	move	$a0,$v0
/*  f02ab5c:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02ab60:	c7a20094 */ 	lwc1	$f2,0x94($sp)
/*  f02ab64:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02ab68:	8fb900e8 */ 	lw	$t9,0xe8($sp)
/*  f02ab6c:	4600110d */ 	trunc.w.s	$f4,$f2
/*  f02ab70:	a0790000 */ 	sb	$t9,0x0($v1)
/*  f02ab74:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f02ab78:	44192000 */ 	mfc1	$t9,$f4
/*  f02ab7c:	a0780001 */ 	sb	$t8,0x1($v1)
/*  f02ab80:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f02ab84:	a0790003 */ 	sb	$t9,0x3($v1)
/*  f02ab88:	a06f0002 */ 	sb	$t7,0x2($v1)
.PB0f02ab8c:
/*  f02ab8c:	02001825 */ 	move	$v1,$s0
/*  f02ab90:	27a20180 */ 	addiu	$v0,$sp,0x180
/*  f02ab94:	27a401b0 */ 	addiu	$a0,$sp,0x1b0
.PB0f02ab98:
/*  f02ab98:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02ab9c:	24420006 */ 	addiu	$v0,$v0,0x6
/*  f02aba0:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02aba4:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f02aba8:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f02abac:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02abb0:	a86ffff8 */ 	swl	$t7,-0x8($v1)
/*  f02abb4:	b86ffffb */ 	swr	$t7,-0x5($v1)
/*  f02abb8:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02abbc:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02abc0:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02abc4:	844efffa */ 	lh	$t6,-0x6($v0)
/*  f02abc8:	0044082b */ 	sltu	$at,$v0,$a0
/*  f02abcc:	a46efff4 */ 	sh	$t6,-0xc($v1)
/*  f02abd0:	8459fffc */ 	lh	$t9,-0x4($v0)
/*  f02abd4:	a479fff6 */ 	sh	$t9,-0xa($v1)
/*  f02abd8:	8458fffe */ 	lh	$t8,-0x2($v0)
/*  f02abdc:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02abe0:	1420ffed */ 	bnez	$at,.PB0f02ab98
/*  f02abe4:	a478fff8 */ 	sh	$t8,-0x8($v1)
/*  f02abe8:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02abec:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02abf0:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f02abf4:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02abf8:	a6140046 */ 	sh	$s4,0x46($s0)
/*  f02abfc:	a6150038 */ 	sh	$s5,0x38($s0)
/*  f02ac00:	a614003a */ 	sh	$s4,0x3a($s0)
/*  f02ac04:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02ac08:	a613002e */ 	sh	$s3,0x2e($s0)
/*  f02ac0c:	a6130022 */ 	sh	$s3,0x22($s0)
/*  f02ac10:	a6140052 */ 	sh	$s4,0x52($s0)
/*  f02ac14:	a615005c */ 	sh	$s5,0x5c($s0)
/*  f02ac18:	a614005e */ 	sh	$s4,0x5e($s0)
/*  f02ac1c:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02ac20:	a60b0044 */ 	sh	$t3,0x44($s0)
/*  f02ac24:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02ac28:	a60b0050 */ 	sh	$t3,0x50($s0)
/*  f02ac2c:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02ac30:	02002025 */ 	move	$a0,$s0
/*  f02ac34:	aa010060 */ 	swl	$at,0x60($s0)
/*  f02ac38:	ba010063 */ 	swr	$at,0x63($s0)
/*  f02ac3c:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f02ac40:	aa0e0064 */ 	swl	$t6,0x64($s0)
/*  f02ac44:	ba0e0067 */ 	swr	$t6,0x67($s0)
/*  f02ac48:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02ac4c:	aa010068 */ 	swl	$at,0x68($s0)
/*  f02ac50:	ba01006b */ 	swr	$at,0x6b($s0)
/*  f02ac54:	87b9018c */ 	lh	$t9,0x18c($sp)
/*  f02ac58:	a6190060 */ 	sh	$t9,0x60($s0)
/*  f02ac5c:	87b8018e */ 	lh	$t8,0x18e($sp)
/*  f02ac60:	a6180062 */ 	sh	$t8,0x62($s0)
/*  f02ac64:	87af0190 */ 	lh	$t7,0x190($sp)
/*  f02ac68:	a2000067 */ 	sb	$zero,0x67($s0)
/*  f02ac6c:	a60f0064 */ 	sh	$t7,0x64($s0)
/*  f02ac70:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02ac74:	aa01006c */ 	swl	$at,0x6c($s0)
/*  f02ac78:	ba01006f */ 	swr	$at,0x6f($s0)
/*  f02ac7c:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02ac80:	aa190070 */ 	swl	$t9,0x70($s0)
/*  f02ac84:	ba190073 */ 	swr	$t9,0x73($s0)
/*  f02ac88:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02ac8c:	aa010074 */ 	swl	$at,0x74($s0)
/*  f02ac90:	ba010077 */ 	swr	$at,0x77($s0)
/*  f02ac94:	87b80192 */ 	lh	$t8,0x192($sp)
/*  f02ac98:	a618006c */ 	sh	$t8,0x6c($s0)
/*  f02ac9c:	87af0194 */ 	lh	$t7,0x194($sp)
/*  f02aca0:	a60f006e */ 	sh	$t7,0x6e($s0)
/*  f02aca4:	87ae0196 */ 	lh	$t6,0x196($sp)
/*  f02aca8:	a2000073 */ 	sb	$zero,0x73($s0)
/*  f02acac:	a6150068 */ 	sh	$s5,0x68($s0)
/*  f02acb0:	a614006a */ 	sh	$s4,0x6a($s0)
/*  f02acb4:	a6140076 */ 	sh	$s4,0x76($s0)
/*  f02acb8:	a60b0074 */ 	sh	$t3,0x74($s0)
/*  f02acbc:	a60e0070 */ 	sh	$t6,0x70($s0)
/*  f02acc0:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02acc4:	aa010078 */ 	swl	$at,0x78($s0)
/*  f02acc8:	ba01007b */ 	swr	$at,0x7b($s0)
/*  f02accc:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f02acd0:	aa18007c */ 	swl	$t8,0x7c($s0)
/*  f02acd4:	ba18007f */ 	swr	$t8,0x7f($s0)
/*  f02acd8:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02acdc:	aa010080 */ 	swl	$at,0x80($s0)
/*  f02ace0:	ba010083 */ 	swr	$at,0x83($s0)
/*  f02ace4:	87af01a4 */ 	lh	$t7,0x1a4($sp)
/*  f02ace8:	a60f0078 */ 	sh	$t7,0x78($s0)
/*  f02acec:	87ae01a6 */ 	lh	$t6,0x1a6($sp)
/*  f02acf0:	a60e007a */ 	sh	$t6,0x7a($s0)
/*  f02acf4:	87b901a8 */ 	lh	$t9,0x1a8($sp)
/*  f02acf8:	a200007f */ 	sb	$zero,0x7f($s0)
/*  f02acfc:	a619007c */ 	sh	$t9,0x7c($s0)
/*  f02ad00:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02ad04:	aa010084 */ 	swl	$at,0x84($s0)
/*  f02ad08:	ba010087 */ 	swr	$at,0x87($s0)
/*  f02ad0c:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02ad10:	aa0f0088 */ 	swl	$t7,0x88($s0)
/*  f02ad14:	ba0f008b */ 	swr	$t7,0x8b($s0)
/*  f02ad18:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02ad1c:	aa01008c */ 	swl	$at,0x8c($s0)
/*  f02ad20:	ba01008f */ 	swr	$at,0x8f($s0)
/*  f02ad24:	87ae01aa */ 	lh	$t6,0x1aa($sp)
/*  f02ad28:	a60e0084 */ 	sh	$t6,0x84($s0)
/*  f02ad2c:	87b901ac */ 	lh	$t9,0x1ac($sp)
/*  f02ad30:	a6190086 */ 	sh	$t9,0x86($s0)
/*  f02ad34:	87b801ae */ 	lh	$t8,0x1ae($sp)
/*  f02ad38:	a200008b */ 	sb	$zero,0x8b($s0)
/*  f02ad3c:	a6150080 */ 	sh	$s5,0x80($s0)
/*  f02ad40:	a6130082 */ 	sh	$s3,0x82($s0)
/*  f02ad44:	a613008e */ 	sh	$s3,0x8e($s0)
/*  f02ad48:	a60b008c */ 	sh	$t3,0x8c($s0)
/*  f02ad4c:	a6180088 */ 	sh	$t8,0x88($s0)
/*  f02ad50:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02ad54:	3c1904b0 */ 	lui	$t9,0x4b0
/*  f02ad58:	37390090 */ 	ori	$t9,$t9,0x90
/*  f02ad5c:	262e0008 */ 	addiu	$t6,$s1,0x8
/*  f02ad60:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02ad64:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02ad68:	ae390000 */ 	sw	$t9,0x0($s1)
/*  f02ad6c:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02ad70:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02ad74:	3c0eb100 */ 	lui	$t6,0xb100
/*  f02ad78:	3c194b5b */ 	lui	$t9,0x4b5b
/*  f02ad7c:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02ad80:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02ad84:	37399010 */ 	ori	$t9,$t9,0x9010
/*  f02ad88:	35cea489 */ 	ori	$t6,$t6,0xa489
/*  f02ad8c:	27a30124 */ 	addiu	$v1,$sp,0x124
/*  f02ad90:	27a60164 */ 	addiu	$a2,$sp,0x164
/*  f02ad94:	3c05b100 */ 	lui	$a1,0xb100
/*  f02ad98:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f02ad9c:	af190004 */ 	sw	$t9,0x4($t8)
.PB0f02ada0:
/*  f02ada0:	8fa201f0 */ 	lw	$v0,0x1f0($sp)
/*  f02ada4:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f02ada8:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f02adac:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02adb0:	8c6efff8 */ 	lw	$t6,-0x8($v1)
/*  f02adb4:	8c6ffffc */ 	lw	$t7,-0x4($v1)
/*  f02adb8:	31d9000f */ 	andi	$t9,$t6,0xf
/*  f02adbc:	0325c025 */ 	or	$t8,$t9,$a1
/*  f02adc0:	31ee000f */ 	andi	$t6,$t7,0xf
/*  f02adc4:	000ec900 */ 	sll	$t9,$t6,0x4
/*  f02adc8:	03197825 */ 	or	$t7,$t8,$t9
/*  f02adcc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f02add0:	8c78fff8 */ 	lw	$t8,-0x8($v1)
/*  f02add4:	8c64fff0 */ 	lw	$a0,-0x10($v1)
/*  f02add8:	3319000f */ 	andi	$t9,$t8,0xf
/*  f02addc:	308e000f */ 	andi	$t6,$a0,0xf
/*  f02ade0:	01c02025 */ 	move	$a0,$t6
/*  f02ade4:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f02ade8:	01cf7025 */ 	or	$t6,$t6,$t7
/*  f02adec:	8c6ffff4 */ 	lw	$t7,-0xc($v1)
/*  f02adf0:	0004c200 */ 	sll	$t8,$a0,0x8
/*  f02adf4:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f02adf8:	31ee000f */ 	andi	$t6,$t7,0xf
/*  f02adfc:	000ec100 */ 	sll	$t8,$t6,0x4
/*  f02ae00:	03387825 */ 	or	$t7,$t9,$t8
/*  f02ae04:	1466ffe6 */ 	bne	$v1,$a2,.PB0f02ada0
/*  f02ae08:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f02ae0c:	1000029c */ 	b	.PB0f02b880
/*  f02ae10:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PB0f02ae14:
/*  f02ae14:	91c40000 */ 	lbu	$a0,0x0($t6)
/*  f02ae18:	24010001 */ 	li	$at,0x1
/*  f02ae1c:	10810005 */ 	beq	$a0,$at,.PB0f02ae34
/*  f02ae20:	24090004 */ 	li	$t1,0x4
/*  f02ae24:	11240003 */ 	beq	$t1,$a0,.PB0f02ae34
/*  f02ae28:	24010002 */ 	li	$at,0x2
/*  f02ae2c:	5481000b */ 	bnel	$a0,$at,.PB0f02ae5c
/*  f02ae30:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
.PB0f02ae34:
/*  f02ae34:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
/*  f02ae38:	240500ff */ 	li	$a1,0xff
/*  f02ae3c:	8f380004 */ 	lw	$t8,0x4($t9)
/*  f02ae40:	8f0f0010 */ 	lw	$t7,0x10($t8)
/*  f02ae44:	31ee1000 */ 	andi	$t6,$t7,0x1000
/*  f02ae48:	51c00004 */ 	beqzl	$t6,.PB0f02ae5c
/*  f02ae4c:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
/*  f02ae50:	10000023 */ 	b	.PB0f02aee0
/*  f02ae54:	240600ff */ 	li	$a2,0xff
/*  f02ae58:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
.PB0f02ae5c:
/*  f02ae5c:	3c02800a */ 	lui	$v0,0x800a
/*  f02ae60:	8c42e4d8 */ 	lw	$v0,-0x1b28($v0)
/*  f02ae64:	8f23000c */ 	lw	$v1,0xc($t9)
/*  f02ae68:	00002825 */ 	move	$a1,$zero
/*  f02ae6c:	00003025 */ 	move	$a2,$zero
/*  f02ae70:	0043c023 */ 	subu	$t8,$v0,$v1
/*  f02ae74:	2b010043 */ 	slti	$at,$t8,0x43
/*  f02ae78:	10200019 */ 	beqz	$at,.PB0f02aee0
/*  f02ae7c:	00627823 */ 	subu	$t7,$v1,$v0
/*  f02ae80:	25ee0042 */ 	addiu	$t6,$t7,0x42
/*  f02ae84:	448e4000 */ 	mtc1	$t6,$f8
/*  f02ae88:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02ae8c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02ae90:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f02ae94:	44995000 */ 	mtc1	$t9,$f10
/*  f02ae98:	c430a648 */ 	lwc1	$f16,-0x59b8($at)
/*  f02ae9c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f02aea0:	c424a64c */ 	lwc1	$f4,-0x59b4($at)
/*  f02aea4:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f02aea8:	46103302 */ 	mul.s	$f12,$f6,$f16
/*  f02aeac:	00000000 */ 	nop
/*  f02aeb0:	46049082 */ 	mul.s	$f2,$f18,$f4
/*  f02aeb4:	00000000 */ 	nop
/*  f02aeb8:	46026002 */ 	mul.s	$f0,$f12,$f2
/*  f02aebc:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f02aec0:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f02aec4:	44054000 */ 	mfc1	$a1,$f8
/*  f02aec8:	44063000 */ 	mfc1	$a2,$f6
/*  f02aecc:	30af00ff */ 	andi	$t7,$a1,0xff
/*  f02aed0:	01e02825 */ 	move	$a1,$t7
/*  f02aed4:	30d900ff */ 	andi	$t9,$a2,0xff
/*  f02aed8:	10000001 */ 	b	.PB0f02aee0
/*  f02aedc:	03203025 */ 	move	$a2,$t9
.PB0f02aee0:
/*  f02aee0:	24040005 */ 	li	$a0,0x5
/*  f02aee4:	a3a5017f */ 	sb	$a1,0x17f($sp)
/*  f02aee8:	a3a6017e */ 	sb	$a2,0x17e($sp)
/*  f02aeec:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02aef0:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02aef4:	0fc5a40f */ 	jal	gfxAllocateColours
/*  f02aef8:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02aefc:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f02af00:	3c0e0710 */ 	lui	$t6,0x710
/*  f02af04:	35ce0014 */ 	ori	$t6,$t6,0x14
/*  f02af08:	260f0008 */ 	addiu	$t7,$s0,0x8
/*  f02af0c:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02af10:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f02af14:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02af18:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02af1c:	00402025 */ 	move	$a0,$v0
/*  f02af20:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02af24:	93a5017f */ 	lbu	$a1,0x17f($sp)
/*  f02af28:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02af2c:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02af30:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02af34:	93a6017e */ 	lbu	$a2,0x17e($sp)
/*  f02af38:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f02af3c:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f02af40:	2404001e */ 	li	$a0,0x1e
/*  f02af44:	a0790000 */ 	sb	$t9,0x0($v1)
/*  f02af48:	8fb800fc */ 	lw	$t8,0xfc($sp)
/*  f02af4c:	a0780001 */ 	sb	$t8,0x1($v1)
/*  f02af50:	8faf00f8 */ 	lw	$t7,0xf8($sp)
/*  f02af54:	a0650003 */ 	sb	$a1,0x3($v1)
/*  f02af58:	a0650007 */ 	sb	$a1,0x7($v1)
/*  f02af5c:	a065000b */ 	sb	$a1,0xb($v1)
/*  f02af60:	a0670004 */ 	sb	$a3,0x4($v1)
/*  f02af64:	a0670008 */ 	sb	$a3,0x8($v1)
/*  f02af68:	a06a0005 */ 	sb	$t2,0x5($v1)
/*  f02af6c:	a06a0009 */ 	sb	$t2,0x9($v1)
/*  f02af70:	a06b0006 */ 	sb	$t3,0x6($v1)
/*  f02af74:	a06b000a */ 	sb	$t3,0xa($v1)
/*  f02af78:	a06f0002 */ 	sb	$t7,0x2($v1)
/*  f02af7c:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f02af80:	24e70046 */ 	addiu	$a3,$a3,0x46
/*  f02af84:	254a0046 */ 	addiu	$t2,$t2,0x46
/*  f02af88:	25d90064 */ 	addiu	$t9,$t6,0x64
/*  f02af8c:	2b210100 */ 	slti	$at,$t9,0x100
/*  f02af90:	14200003 */ 	bnez	$at,.PB0f02afa0
/*  f02af94:	afb90100 */ 	sw	$t9,0x100($sp)
/*  f02af98:	240c00ff */ 	li	$t4,0xff
/*  f02af9c:	afac0100 */ 	sw	$t4,0x100($sp)
.PB0f02afa0:
/*  f02afa0:	8fb80100 */ 	lw	$t8,0x100($sp)
/*  f02afa4:	256b0046 */ 	addiu	$t3,$t3,0x46
/*  f02afa8:	a078000c */ 	sb	$t8,0xc($v1)
/*  f02afac:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f02afb0:	25ee0064 */ 	addiu	$t6,$t7,0x64
/*  f02afb4:	29c10100 */ 	slti	$at,$t6,0x100
/*  f02afb8:	14200003 */ 	bnez	$at,.PB0f02afc8
/*  f02afbc:	afae00fc */ 	sw	$t6,0xfc($sp)
/*  f02afc0:	240d00ff */ 	li	$t5,0xff
/*  f02afc4:	afad00fc */ 	sw	$t5,0xfc($sp)
.PB0f02afc8:
/*  f02afc8:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f02afcc:	a079000d */ 	sb	$t9,0xd($v1)
/*  f02afd0:	8fb800f8 */ 	lw	$t8,0xf8($sp)
/*  f02afd4:	270f0064 */ 	addiu	$t7,$t8,0x64
/*  f02afd8:	29e10100 */ 	slti	$at,$t7,0x100
/*  f02afdc:	14200003 */ 	bnez	$at,.PB0f02afec
/*  f02afe0:	afaf00f8 */ 	sw	$t7,0xf8($sp)
/*  f02afe4:	241f00ff */ 	li	$ra,0xff
/*  f02afe8:	afbf00f8 */ 	sw	$ra,0xf8($sp)
.PB0f02afec:
/*  f02afec:	8fae00f8 */ 	lw	$t6,0xf8($sp)
/*  f02aff0:	28e10100 */ 	slti	$at,$a3,0x100
/*  f02aff4:	a066000f */ 	sb	$a2,0xf($v1)
/*  f02aff8:	14200002 */ 	bnez	$at,.PB0f02b004
/*  f02affc:	a06e000e */ 	sb	$t6,0xe($v1)
/*  f02b000:	240700ff */ 	li	$a3,0xff
.PB0f02b004:
/*  f02b004:	29410100 */ 	slti	$at,$t2,0x100
/*  f02b008:	14200002 */ 	bnez	$at,.PB0f02b014
/*  f02b00c:	a0670010 */ 	sb	$a3,0x10($v1)
/*  f02b010:	240a00ff */ 	li	$t2,0xff
.PB0f02b014:
/*  f02b014:	29610100 */ 	slti	$at,$t3,0x100
/*  f02b018:	14200002 */ 	bnez	$at,.PB0f02b024
/*  f02b01c:	a06a0011 */ 	sb	$t2,0x11($v1)
/*  f02b020:	240b00ff */ 	li	$t3,0xff
.PB0f02b024:
/*  f02b024:	a06b0012 */ 	sb	$t3,0x12($v1)
/*  f02b028:	0fc5a3f5 */ 	jal	gfxAllocateVertices
/*  f02b02c:	a0650013 */ 	sb	$a1,0x13($v1)
/*  f02b030:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02b034:	27b80104 */ 	addiu	$t8,$sp,0x104
/*  f02b038:	00408025 */ 	move	$s0,$v0
/*  f02b03c:	0008c900 */ 	sll	$t9,$t0,0x4
/*  f02b040:	03382821 */ 	addu	$a1,$t9,$t8
/*  f02b044:	00a03825 */ 	move	$a3,$a1
/*  f02b048:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f02b04c:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02b050:	00002025 */ 	move	$a0,$zero
/*  f02b054:	00401825 */ 	move	$v1,$v0
.PB0f02b058:
/*  f02b058:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b05c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f02b060:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f02b064:	a8610000 */ 	swl	$at,0x0($v1)
/*  f02b068:	b8610003 */ 	swr	$at,0x3($v1)
/*  f02b06c:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02b070:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02b074:	a879fff8 */ 	swl	$t9,-0x8($v1)
/*  f02b078:	b879fffb */ 	swr	$t9,-0x5($v1)
/*  f02b07c:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b080:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02b084:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02b088:	8cf8fffc */ 	lw	$t8,-0x4($a3)
/*  f02b08c:	28810004 */ 	slti	$at,$a0,0x4
/*  f02b090:	03110019 */ 	multu	$t8,$s1
/*  f02b094:	00007012 */ 	mflo	$t6
/*  f02b098:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f02b09c:	85f90000 */ 	lh	$t9,0x0($t7)
/*  f02b0a0:	a479fff4 */ 	sh	$t9,-0xc($v1)
/*  f02b0a4:	8cf8fffc */ 	lw	$t8,-0x4($a3)
/*  f02b0a8:	03110019 */ 	multu	$t8,$s1
/*  f02b0ac:	00007012 */ 	mflo	$t6
/*  f02b0b0:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f02b0b4:	85f90002 */ 	lh	$t9,0x2($t7)
/*  f02b0b8:	a479fff6 */ 	sh	$t9,-0xa($v1)
/*  f02b0bc:	8cf8fffc */ 	lw	$t8,-0x4($a3)
/*  f02b0c0:	03110019 */ 	multu	$t8,$s1
/*  f02b0c4:	00007012 */ 	mflo	$t6
/*  f02b0c8:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f02b0cc:	85f90004 */ 	lh	$t9,0x4($t7)
/*  f02b0d0:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02b0d4:	1420ffe0 */ 	bnez	$at,.PB0f02b058
/*  f02b0d8:	a479fff8 */ 	sh	$t9,-0x8($v1)
/*  f02b0dc:	8fa401f4 */ 	lw	$a0,0x1f4($sp)
/*  f02b0e0:	a4550008 */ 	sh	$s5,0x8($v0)
/*  f02b0e4:	a453000a */ 	sh	$s3,0xa($v0)
/*  f02b0e8:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f02b0ec:	a4530016 */ 	sh	$s3,0x16($v0)
/*  f02b0f0:	a4540022 */ 	sh	$s4,0x22($v0)
/*  f02b0f4:	a455002c */ 	sh	$s5,0x2c($v0)
/*  f02b0f8:	a454002e */ 	sh	$s4,0x2e($v0)
/*  f02b0fc:	a44b0014 */ 	sh	$t3,0x14($v0)
/*  f02b100:	a44b0020 */ 	sh	$t3,0x20($v0)
/*  f02b104:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b108:	a8410030 */ 	swl	$at,0x30($v0)
/*  f02b10c:	b8410033 */ 	swr	$at,0x33($v0)
/*  f02b110:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f02b114:	a84e0034 */ 	swl	$t6,0x34($v0)
/*  f02b118:	b84e0037 */ 	swr	$t6,0x37($v0)
/*  f02b11c:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b120:	a8410038 */ 	swl	$at,0x38($v0)
/*  f02b124:	b841003b */ 	swr	$at,0x3b($v0)
/*  f02b128:	84830012 */ 	lh	$v1,0x12($a0)
/*  f02b12c:	24017fff */ 	li	$at,0x7fff
/*  f02b130:	5461001e */ 	bnel	$v1,$at,.PB0f02b1ac
/*  f02b134:	a4430030 */ 	sh	$v1,0x30($v0)
/*  f02b138:	844f0024 */ 	lh	$t7,0x24($v0)
/*  f02b13c:	84590000 */ 	lh	$t9,0x0($v0)
/*  f02b140:	844e000c */ 	lh	$t6,0xc($v0)
/*  f02b144:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b148:	84590018 */ 	lh	$t9,0x18($v0)
/*  f02b14c:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f02b150:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b154:	84590002 */ 	lh	$t9,0x2($v0)
/*  f02b158:	844f0026 */ 	lh	$t7,0x26($v0)
/*  f02b15c:	00187083 */ 	sra	$t6,$t8,0x2
/*  f02b160:	a44e0030 */ 	sh	$t6,0x30($v0)
/*  f02b164:	844e000e */ 	lh	$t6,0xe($v0)
/*  f02b168:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b16c:	8459001a */ 	lh	$t9,0x1a($v0)
/*  f02b170:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f02b174:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b178:	84590004 */ 	lh	$t9,0x4($v0)
/*  f02b17c:	844f0028 */ 	lh	$t7,0x28($v0)
/*  f02b180:	00187083 */ 	sra	$t6,$t8,0x2
/*  f02b184:	a44e0032 */ 	sh	$t6,0x32($v0)
/*  f02b188:	844e0010 */ 	lh	$t6,0x10($v0)
/*  f02b18c:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b190:	8459001c */ 	lh	$t9,0x1c($v0)
/*  f02b194:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f02b198:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b19c:	00187083 */ 	sra	$t6,$t8,0x2
/*  f02b1a0:	10000006 */ 	b	.PB0f02b1bc
/*  f02b1a4:	a44e0034 */ 	sh	$t6,0x34($v0)
/*  f02b1a8:	a4430030 */ 	sh	$v1,0x30($v0)
.PB0f02b1ac:
/*  f02b1ac:	848f0014 */ 	lh	$t7,0x14($a0)
/*  f02b1b0:	a44f0032 */ 	sh	$t7,0x32($v0)
/*  f02b1b4:	84990016 */ 	lh	$t9,0x16($a0)
/*  f02b1b8:	a4590034 */ 	sh	$t9,0x34($v0)
.PB0f02b1bc:
/*  f02b1bc:	02ab1821 */ 	addu	$v1,$s5,$t3
/*  f02b1c0:	02741021 */ 	addu	$v0,$s3,$s4
/*  f02b1c4:	2418000c */ 	li	$t8,0xc
/*  f02b1c8:	00037043 */ 	sra	$t6,$v1,0x1
/*  f02b1cc:	00027843 */ 	sra	$t7,$v0,0x1
/*  f02b1d0:	a2180037 */ 	sb	$t8,0x37($s0)
/*  f02b1d4:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02b1d8:	a60f003a */ 	sh	$t7,0x3a($s0)
/*  f02b1dc:	8fb901f0 */ 	lw	$t9,0x1f0($sp)
/*  f02b1e0:	01c01825 */ 	move	$v1,$t6
/*  f02b1e4:	3c0e0440 */ 	lui	$t6,0x440
/*  f02b1e8:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f02b1ec:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f02b1f0:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02b1f4:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f02b1f8:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f02b1fc:	afa30040 */ 	sw	$v1,0x40($sp)
/*  f02b200:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f02b204:	02002025 */ 	move	$a0,$s0
/*  f02b208:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02b20c:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f02b210:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f02b214:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02b218:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f02b21c:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f02b220:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f02b224:	3c18b100 */ 	lui	$t8,0xb100
/*  f02b228:	3c0e0332 */ 	lui	$t6,0x332
/*  f02b22c:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f02b230:	afb901f0 */ 	sw	$t9,0x1f0($sp)
/*  f02b234:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02b238:	37184444 */ 	ori	$t8,$t8,0x4444
/*  f02b23c:	adf80000 */ 	sw	$t8,0x0($t7)
/*  f02b240:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f02b244:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02b248:	24090004 */ 	li	$t1,0x4
/*  f02b24c:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f02b250:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f02b254:	00002025 */ 	move	$a0,$zero
/*  f02b258:	241f0005 */ 	li	$ra,0x5
/*  f02b25c:	240d0008 */ 	li	$t5,0x8
/*  f02b260:	240c0004 */ 	li	$t4,0x4
.PB0f02b264:
/*  f02b264:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b268:	248a0001 */ 	addiu	$t2,$a0,0x1
/*  f02b26c:	aa010000 */ 	swl	$at,0x0($s0)
/*  f02b270:	ba010003 */ 	swr	$at,0x3($s0)
/*  f02b274:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02b278:	aa190004 */ 	swl	$t9,0x4($s0)
/*  f02b27c:	ba190007 */ 	swr	$t9,0x7($s0)
/*  f02b280:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b284:	aa010008 */ 	swl	$at,0x8($s0)
/*  f02b288:	ba01000b */ 	swr	$at,0xb($s0)
/*  f02b28c:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f02b290:	05410004 */ 	bgez	$t2,.PB0f02b2a4
/*  f02b294:	314e0003 */ 	andi	$t6,$t2,0x3
/*  f02b298:	11c00002 */ 	beqz	$t6,.PB0f02b2a4
/*  f02b29c:	00000000 */ 	nop
/*  f02b2a0:	25cefffc */ 	addiu	$t6,$t6,-4
.PB0f02b2a4:
/*  f02b2a4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f02b2a8:	030f1021 */ 	addu	$v0,$t8,$t7
/*  f02b2ac:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b2b0:	03310019 */ 	multu	$t9,$s1
/*  f02b2b4:	00007012 */ 	mflo	$t6
/*  f02b2b8:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b2bc:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b2c0:	a60f0000 */ 	sh	$t7,0x0($s0)
/*  f02b2c4:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b2c8:	03310019 */ 	multu	$t9,$s1
/*  f02b2cc:	00007012 */ 	mflo	$t6
/*  f02b2d0:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b2d4:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b2d8:	a60f0002 */ 	sh	$t7,0x2($s0)
/*  f02b2dc:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b2e0:	03310019 */ 	multu	$t9,$s1
/*  f02b2e4:	00007012 */ 	mflo	$t6
/*  f02b2e8:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b2ec:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b2f0:	a20c0007 */ 	sb	$t4,0x7($s0)
/*  f02b2f4:	a60f0004 */ 	sh	$t7,0x4($s0)
/*  f02b2f8:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b2fc:	aa01000c */ 	swl	$at,0xc($s0)
/*  f02b300:	ba01000f */ 	swr	$at,0xf($s0)
/*  f02b304:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f02b308:	aa0e0010 */ 	swl	$t6,0x10($s0)
/*  f02b30c:	ba0e0013 */ 	swr	$t6,0x13($s0)
/*  f02b310:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b314:	aa010014 */ 	swl	$at,0x14($s0)
/*  f02b318:	ba010017 */ 	swr	$at,0x17($s0)
/*  f02b31c:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f02b320:	03110019 */ 	multu	$t8,$s1
/*  f02b324:	00007812 */ 	mflo	$t7
/*  f02b328:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02b32c:	872e0000 */ 	lh	$t6,0x0($t9)
/*  f02b330:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f02b334:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f02b338:	03110019 */ 	multu	$t8,$s1
/*  f02b33c:	00007812 */ 	mflo	$t7
/*  f02b340:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02b344:	872e0002 */ 	lh	$t6,0x2($t9)
/*  f02b348:	a60e000e */ 	sh	$t6,0xe($s0)
/*  f02b34c:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f02b350:	03110019 */ 	multu	$t8,$s1
/*  f02b354:	00007812 */ 	mflo	$t7
/*  f02b358:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02b35c:	872e0004 */ 	lh	$t6,0x4($t9)
/*  f02b360:	a20c0013 */ 	sb	$t4,0x13($s0)
/*  f02b364:	a60e0010 */ 	sh	$t6,0x10($s0)
/*  f02b368:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b36c:	aa010018 */ 	swl	$at,0x18($s0)
/*  f02b370:	ba01001b */ 	swr	$at,0x1b($s0)
/*  f02b374:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b378:	aa0f001c */ 	swl	$t7,0x1c($s0)
/*  f02b37c:	ba0f001f */ 	swr	$t7,0x1f($s0)
/*  f02b380:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b384:	aa010020 */ 	swl	$at,0x20($s0)
/*  f02b388:	ba010023 */ 	swr	$at,0x23($s0)
/*  f02b38c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f02b390:	24010001 */ 	li	$at,0x1
/*  f02b394:	03310019 */ 	multu	$t9,$s1
/*  f02b398:	00007012 */ 	mflo	$t6
/*  f02b39c:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b3a0:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b3a4:	a60f0018 */ 	sh	$t7,0x18($s0)
/*  f02b3a8:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f02b3ac:	03310019 */ 	multu	$t9,$s1
/*  f02b3b0:	00007012 */ 	mflo	$t6
/*  f02b3b4:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b3b8:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b3bc:	a60f001a */ 	sh	$t7,0x1a($s0)
/*  f02b3c0:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f02b3c4:	03310019 */ 	multu	$t9,$s1
/*  f02b3c8:	00007012 */ 	mflo	$t6
/*  f02b3cc:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b3d0:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b3d4:	a20d001f */ 	sb	$t5,0x1f($s0)
/*  f02b3d8:	15000004 */ 	bnez	$t0,.PB0f02b3ec
/*  f02b3dc:	a60f001c */ 	sh	$t7,0x1c($s0)
/*  f02b3e0:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f02b3e4:	10000016 */ 	b	.PB0f02b440
/*  f02b3e8:	a6190018 */ 	sh	$t9,0x18($s0)
.PB0f02b3ec:
/*  f02b3ec:	15010003 */ 	bne	$t0,$at,.PB0f02b3fc
/*  f02b3f0:	8fae01cc */ 	lw	$t6,0x1cc($sp)
/*  f02b3f4:	10000012 */ 	b	.PB0f02b440
/*  f02b3f8:	a60e0018 */ 	sh	$t6,0x18($s0)
.PB0f02b3fc:
/*  f02b3fc:	24010002 */ 	li	$at,0x2
/*  f02b400:	15010003 */ 	bne	$t0,$at,.PB0f02b410
/*  f02b404:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f02b408:	1000000d */ 	b	.PB0f02b440
/*  f02b40c:	a618001a */ 	sh	$t8,0x1a($s0)
.PB0f02b410:
/*  f02b410:	24010003 */ 	li	$at,0x3
/*  f02b414:	15010003 */ 	bne	$t0,$at,.PB0f02b424
/*  f02b418:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f02b41c:	10000008 */ 	b	.PB0f02b440
/*  f02b420:	a60f001a */ 	sh	$t7,0x1a($s0)
.PB0f02b424:
/*  f02b424:	15090003 */ 	bne	$t0,$t1,.PB0f02b434
/*  f02b428:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f02b42c:	10000004 */ 	b	.PB0f02b440
/*  f02b430:	a619001c */ 	sh	$t9,0x1c($s0)
.PB0f02b434:
/*  f02b434:	151f0002 */ 	bne	$t0,$ra,.PB0f02b440
/*  f02b438:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f02b43c:	a60e001c */ 	sh	$t6,0x1c($s0)
.PB0f02b440:
/*  f02b440:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b444:	aa010024 */ 	swl	$at,0x24($s0)
/*  f02b448:	ba010027 */ 	swr	$at,0x27($s0)
/*  f02b44c:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b450:	aa0f0028 */ 	swl	$t7,0x28($s0)
/*  f02b454:	ba0f002b */ 	swr	$t7,0x2b($s0)
/*  f02b458:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b45c:	aa01002c */ 	swl	$at,0x2c($s0)
/*  f02b460:	ba01002f */ 	swr	$at,0x2f($s0)
/*  f02b464:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b468:	24010001 */ 	li	$at,0x1
/*  f02b46c:	03310019 */ 	multu	$t9,$s1
/*  f02b470:	00007012 */ 	mflo	$t6
/*  f02b474:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b478:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b47c:	a60f0024 */ 	sh	$t7,0x24($s0)
/*  f02b480:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b484:	03310019 */ 	multu	$t9,$s1
/*  f02b488:	00007012 */ 	mflo	$t6
/*  f02b48c:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b490:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b494:	a60f0026 */ 	sh	$t7,0x26($s0)
/*  f02b498:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b49c:	03310019 */ 	multu	$t9,$s1
/*  f02b4a0:	00007012 */ 	mflo	$t6
/*  f02b4a4:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b4a8:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b4ac:	a20d002b */ 	sb	$t5,0x2b($s0)
/*  f02b4b0:	15000004 */ 	bnez	$t0,.PB0f02b4c4
/*  f02b4b4:	a60f0028 */ 	sh	$t7,0x28($s0)
/*  f02b4b8:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f02b4bc:	10000016 */ 	b	.PB0f02b518
/*  f02b4c0:	a6190024 */ 	sh	$t9,0x24($s0)
.PB0f02b4c4:
/*  f02b4c4:	15010003 */ 	bne	$t0,$at,.PB0f02b4d4
/*  f02b4c8:	8fae01cc */ 	lw	$t6,0x1cc($sp)
/*  f02b4cc:	10000012 */ 	b	.PB0f02b518
/*  f02b4d0:	a60e0024 */ 	sh	$t6,0x24($s0)
.PB0f02b4d4:
/*  f02b4d4:	24010002 */ 	li	$at,0x2
/*  f02b4d8:	15010003 */ 	bne	$t0,$at,.PB0f02b4e8
/*  f02b4dc:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f02b4e0:	1000000d */ 	b	.PB0f02b518
/*  f02b4e4:	a6180026 */ 	sh	$t8,0x26($s0)
.PB0f02b4e8:
/*  f02b4e8:	24010003 */ 	li	$at,0x3
/*  f02b4ec:	15010003 */ 	bne	$t0,$at,.PB0f02b4fc
/*  f02b4f0:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f02b4f4:	10000008 */ 	b	.PB0f02b518
/*  f02b4f8:	a60f0026 */ 	sh	$t7,0x26($s0)
.PB0f02b4fc:
/*  f02b4fc:	15090003 */ 	bne	$t0,$t1,.PB0f02b50c
/*  f02b500:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f02b504:	10000004 */ 	b	.PB0f02b518
/*  f02b508:	a6190028 */ 	sh	$t9,0x28($s0)
.PB0f02b50c:
/*  f02b50c:	151f0002 */ 	bne	$t0,$ra,.PB0f02b518
/*  f02b510:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f02b514:	a60e0028 */ 	sh	$t6,0x28($s0)
.PB0f02b518:
/*  f02b518:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02b51c:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02b520:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02b524:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02b528:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02b52c:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02b530:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02b534:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02b538:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b53c:	86190024 */ 	lh	$t9,0x24($s0)
/*  f02b540:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f02b544:	aa010030 */ 	swl	$at,0x30($s0)
/*  f02b548:	ba010033 */ 	swr	$at,0x33($s0)
/*  f02b54c:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b550:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b554:	860e0018 */ 	lh	$t6,0x18($s0)
/*  f02b558:	aa0f0034 */ 	swl	$t7,0x34($s0)
/*  f02b55c:	ba0f0037 */ 	swr	$t7,0x37($s0)
/*  f02b560:	860f000c */ 	lh	$t7,0xc($s0)
/*  f02b564:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b568:	02002025 */ 	move	$a0,$s0
/*  f02b56c:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b570:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b574:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f02b578:	86190026 */ 	lh	$t9,0x26($s0)
/*  f02b57c:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b580:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f02b584:	860f000e */ 	lh	$t7,0xe($s0)
/*  f02b588:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b58c:	860e001a */ 	lh	$t6,0x1a($s0)
/*  f02b590:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b594:	aa010038 */ 	swl	$at,0x38($s0)
/*  f02b598:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b59c:	860e0004 */ 	lh	$t6,0x4($s0)
/*  f02b5a0:	86190028 */ 	lh	$t9,0x28($s0)
/*  f02b5a4:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b5a8:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f02b5ac:	860f0010 */ 	lh	$t7,0x10($s0)
/*  f02b5b0:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b5b4:	860e001c */ 	lh	$t6,0x1c($s0)
/*  f02b5b8:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b5bc:	ba01003b */ 	swr	$at,0x3b($s0)
/*  f02b5c0:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b5c4:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b5c8:	24190010 */ 	li	$t9,0x10
/*  f02b5cc:	a60f0034 */ 	sh	$t7,0x34($s0)
/*  f02b5d0:	a2190037 */ 	sb	$t9,0x37($s0)
/*  f02b5d4:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f02b5d8:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02b5dc:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f02b5e0:	3c0e0440 */ 	lui	$t6,0x440
/*  f02b5e4:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02b5e8:	a618003a */ 	sh	$t8,0x3a($s0)
/*  f02b5ec:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f02b5f0:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f02b5f4:	afb901f0 */ 	sw	$t9,0x1f0($sp)
/*  f02b5f8:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f02b5fc:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f02b600:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f02b604:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f02b608:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02b60c:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f02b610:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f02b614:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f02b618:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f02b61c:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02b620:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f02b624:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f02b628:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02b62c:	3c19b100 */ 	lui	$t9,0xb100
/*  f02b630:	3c0e0332 */ 	lui	$t6,0x332
/*  f02b634:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02b638:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02b63c:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02b640:	37394444 */ 	ori	$t9,$t9,0x4444
/*  f02b644:	28810004 */ 	slti	$at,$a0,0x4
/*  f02b648:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02b64c:	24090004 */ 	li	$t1,0x4
/*  f02b650:	240c0004 */ 	li	$t4,0x4
/*  f02b654:	240d0008 */ 	li	$t5,0x8
/*  f02b658:	241f0005 */ 	li	$ra,0x5
/*  f02b65c:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f02b660:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f02b664:	af190000 */ 	sw	$t9,0x0($t8)
/*  f02b668:	1420fefe */ 	bnez	$at,.PB0f02b264
/*  f02b66c:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f02b670:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f02b674:	02001825 */ 	move	$v1,$s0
/*  f02b678:	00003025 */ 	move	$a2,$zero
/*  f02b67c:	24040010 */ 	li	$a0,0x10
/*  f02b680:	2442000c */ 	addiu	$v0,$v0,0xc
.PB0f02b684:
/*  f02b684:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b688:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f02b68c:	2442fffc */ 	addiu	$v0,$v0,-4
/*  f02b690:	a8610000 */ 	swl	$at,0x0($v1)
/*  f02b694:	b8610003 */ 	swr	$at,0x3($v1)
/*  f02b698:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b69c:	a86f0004 */ 	swl	$t7,0x4($v1)
/*  f02b6a0:	b86f0007 */ 	swr	$t7,0x7($v1)
/*  f02b6a4:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b6a8:	a8610008 */ 	swl	$at,0x8($v1)
/*  f02b6ac:	b861000b */ 	swr	$at,0xb($v1)
/*  f02b6b0:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f02b6b4:	24010001 */ 	li	$at,0x1
/*  f02b6b8:	03310019 */ 	multu	$t9,$s1
/*  f02b6bc:	00007012 */ 	mflo	$t6
/*  f02b6c0:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b6c4:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b6c8:	a46f0000 */ 	sh	$t7,0x0($v1)
/*  f02b6cc:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f02b6d0:	03310019 */ 	multu	$t9,$s1
/*  f02b6d4:	00007012 */ 	mflo	$t6
/*  f02b6d8:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b6dc:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b6e0:	a46f0002 */ 	sh	$t7,0x2($v1)
/*  f02b6e4:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f02b6e8:	03310019 */ 	multu	$t9,$s1
/*  f02b6ec:	00007012 */ 	mflo	$t6
/*  f02b6f0:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b6f4:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b6f8:	a06d0007 */ 	sb	$t5,0x7($v1)
/*  f02b6fc:	15000004 */ 	bnez	$t0,.PB0f02b710
/*  f02b700:	a46f0004 */ 	sh	$t7,0x4($v1)
/*  f02b704:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f02b708:	10000016 */ 	b	.PB0f02b764
/*  f02b70c:	a4790000 */ 	sh	$t9,0x0($v1)
.PB0f02b710:
/*  f02b710:	15010003 */ 	bne	$t0,$at,.PB0f02b720
/*  f02b714:	8fae01cc */ 	lw	$t6,0x1cc($sp)
/*  f02b718:	10000012 */ 	b	.PB0f02b764
/*  f02b71c:	a46e0000 */ 	sh	$t6,0x0($v1)
.PB0f02b720:
/*  f02b720:	24010002 */ 	li	$at,0x2
/*  f02b724:	15010003 */ 	bne	$t0,$at,.PB0f02b734
/*  f02b728:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f02b72c:	1000000d */ 	b	.PB0f02b764
/*  f02b730:	a4780002 */ 	sh	$t8,0x2($v1)
.PB0f02b734:
/*  f02b734:	24010003 */ 	li	$at,0x3
/*  f02b738:	15010003 */ 	bne	$t0,$at,.PB0f02b748
/*  f02b73c:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f02b740:	10000008 */ 	b	.PB0f02b764
/*  f02b744:	a46f0002 */ 	sh	$t7,0x2($v1)
.PB0f02b748:
/*  f02b748:	15090003 */ 	bne	$t0,$t1,.PB0f02b758
/*  f02b74c:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f02b750:	10000004 */ 	b	.PB0f02b764
/*  f02b754:	a4790004 */ 	sh	$t9,0x4($v1)
.PB0f02b758:
/*  f02b758:	151f0002 */ 	bne	$t0,$ra,.PB0f02b764
/*  f02b75c:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f02b760:	a46e0004 */ 	sh	$t6,0x4($v1)
.PB0f02b764:
/*  f02b764:	14c4ffc7 */ 	bne	$a2,$a0,.PB0f02b684
/*  f02b768:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02b76c:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02b770:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02b774:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02b778:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02b77c:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02b780:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02b784:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02b788:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02b78c:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b790:	86190024 */ 	lh	$t9,0x24($s0)
/*  f02b794:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f02b798:	aa010030 */ 	swl	$at,0x30($s0)
/*  f02b79c:	ba010033 */ 	swr	$at,0x33($s0)
/*  f02b7a0:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b7a4:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b7a8:	860e0018 */ 	lh	$t6,0x18($s0)
/*  f02b7ac:	aa0f0034 */ 	swl	$t7,0x34($s0)
/*  f02b7b0:	ba0f0037 */ 	swr	$t7,0x37($s0)
/*  f02b7b4:	860f000c */ 	lh	$t7,0xc($s0)
/*  f02b7b8:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b7bc:	02002025 */ 	move	$a0,$s0
/*  f02b7c0:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b7c4:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b7c8:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f02b7cc:	86190026 */ 	lh	$t9,0x26($s0)
/*  f02b7d0:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b7d4:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f02b7d8:	860f000e */ 	lh	$t7,0xe($s0)
/*  f02b7dc:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b7e0:	860e001a */ 	lh	$t6,0x1a($s0)
/*  f02b7e4:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b7e8:	aa010038 */ 	swl	$at,0x38($s0)
/*  f02b7ec:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b7f0:	860e0004 */ 	lh	$t6,0x4($s0)
/*  f02b7f4:	86190028 */ 	lh	$t9,0x28($s0)
/*  f02b7f8:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b7fc:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f02b800:	860f0010 */ 	lh	$t7,0x10($s0)
/*  f02b804:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b808:	860e001c */ 	lh	$t6,0x1c($s0)
/*  f02b80c:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b810:	ba01003b */ 	swr	$at,0x3b($s0)
/*  f02b814:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b818:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b81c:	24190010 */ 	li	$t9,0x10
/*  f02b820:	a60f0034 */ 	sh	$t7,0x34($s0)
/*  f02b824:	a2190037 */ 	sb	$t9,0x37($s0)
/*  f02b828:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f02b82c:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02b830:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f02b834:	3c0e0440 */ 	lui	$t6,0x440
/*  f02b838:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02b83c:	a618003a */ 	sh	$t8,0x3a($s0)
/*  f02b840:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02b844:	26390008 */ 	addiu	$t9,$s1,0x8
/*  f02b848:	afb901f0 */ 	sw	$t9,0x1f0($sp)
/*  f02b84c:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f02b850:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f02b854:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02b858:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02b85c:	3c19b100 */ 	lui	$t9,0xb100
/*  f02b860:	3c0e0332 */ 	lui	$t6,0x332
/*  f02b864:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02b868:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02b86c:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02b870:	37394444 */ 	ori	$t9,$t9,0x4444
/*  f02b874:	af190000 */ 	sw	$t9,0x0($t8)
/*  f02b878:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f02b87c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PB0f02b880:
/*  f02b880:	8fa201f0 */ 	lw	$v0,0x1f0($sp)
/*  f02b884:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f02b888:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f02b88c:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f02b890:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f02b894:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f02b898:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f02b89c:	03e00008 */ 	jr	$ra
/*  f02b8a0:	27bd01f0 */ 	addiu	$sp,$sp,0x1f0
);
#else
GLOBAL_ASM(
glabel chr0f02983c
.late_rodata
glabel var7f1a894c
.word 0x3c40c0c1
glabel var7f1a8950
.word 0x3c40c0c1
glabel var7f1a8954
.word 0x3bab8ba8
glabel var7f1a8958
.word 0x3bab8ba8
glabel var7f1a895c
.word 0x3f169697
glabel var7f1a8960
.word 0x3ea0a0a1
glabel var7f1a8964
.word 0x3e70f0f1
glabel var7f1a8968
.word 0x3e20a0a1
glabel var7f1a896c
.word 0x3c9309fe
glabel var7f1a8970
.word 0x40aaaaab
glabel var7f1a8974
.word 0x3b808081
glabel var7f1a8978
.word 0x3b808081
glabel var7f1a897c
.word 0x3b808081
glabel var7f1a8980
.word 0x3b808081
.text
/*  f02983c:	27bdfe10 */ 	addiu	$sp,$sp,-496
/*  f029840:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f029844:	3c0e8006 */ 	lui	$t6,%hi(var80062a94)
/*  f029848:	8fb50200 */ 	lw	$s5,0x200($sp)
/*  f02984c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f029850:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f029854:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f029858:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f02985c:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f029860:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f029864:	afa401f0 */ 	sw	$a0,0x1f0($sp)
/*  f029868:	afa501f4 */ 	sw	$a1,0x1f4($sp)
/*  f02986c:	afa601f8 */ 	sw	$a2,0x1f8($sp)
/*  f029870:	afa701fc */ 	sw	$a3,0x1fc($sp)
/*  f029874:	25ce2a94 */ 	addiu	$t6,$t6,%lo(var80062a94)
/*  f029878:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f02987c:	27b201e0 */ 	addiu	$s2,$sp,0x1e0
/*  f029880:	8eb30004 */ 	lw	$s3,0x4($s5)
/*  f029884:	ae410000 */ 	sw	$at,0x0($s2)
/*  f029888:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f02988c:	3c0f8006 */ 	lui	$t7,%hi(var80062aa0)
/*  f029890:	25ef2aa0 */ 	addiu	$t7,$t7,%lo(var80062aa0)
/*  f029894:	ae590004 */ 	sw	$t9,0x4($s2)
/*  f029898:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f02989c:	25f90060 */ 	addiu	$t9,$t7,0x60
/*  f0298a0:	27b80104 */ 	addiu	$t8,$sp,0x104
/*  f0298a4:	ae410008 */ 	sw	$at,0x8($s2)
.L0f0298a8:
/*  f0298a8:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0298ac:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f0298b0:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0298b4:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f0298b8:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f0298bc:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f0298c0:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f0298c4:	15f9fff8 */ 	bne	$t7,$t9,.L0f0298a8
/*  f0298c8:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f0298cc:	8fae01f8 */ 	lw	$t6,0x1f8($sp)
/*  f0298d0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0298d4:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f0298d8:	91c40000 */ 	lbu	$a0,0x0($t6)
/*  f0298dc:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
/*  f0298e0:	50810004 */ 	beql	$a0,$at,.L0f0298f4
/*  f0298e4:	8f300004 */ 	lw	$s0,0x4($t9)
/*  f0298e8:	56240014 */ 	bnel	$s1,$a0,.L0f02993c
/*  f0298ec:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
/*  f0298f0:	8f300004 */ 	lw	$s0,0x4($t9)
.L0f0298f4:
/*  f0298f4:	3c014120 */ 	lui	$at,0x4120
/*  f0298f8:	44812000 */ 	mtc1	$at,$f4
/*  f0298fc:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f029900:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f029904:	02002025 */ 	or	$a0,$s0,$zero
/*  f029908:	c5e60014 */ 	lwc1	$f6,0x14($t7)
/*  f02990c:	46062083 */ 	div.s	$f2,$f4,$f6
/*  f029910:	0fc0cfe8 */ 	jal	chrGetShield
/*  f029914:	e7a20170 */ 	swc1	$f2,0x170($sp)
/*  f029918:	921402e1 */ 	lbu	$s4,0x2e1($s0)
/*  f02991c:	960e0188 */ 	lhu	$t6,0x188($s0)
/*  f029920:	c7a20170 */ 	lwc1	$f2,0x170($sp)
/*  f029924:	0014c042 */ 	srl	$t8,$s4,0x1
/*  f029928:	46000386 */ 	mov.s	$f14,$f0
/*  f02992c:	0300a025 */ 	or	$s4,$t8,$zero
/*  f029930:	10000011 */ 	b	.L0f029978
/*  f029934:	afae0164 */ 	sw	$t6,0x164($sp)
/*  f029938:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
.L0f02993c:
/*  f02993c:	44801000 */ 	mtc1	$zero,$f2
/*  f029940:	24140040 */ 	addiu	$s4,$zero,0x40
/*  f029944:	8f220004 */ 	lw	$v0,0x4($t9)
/*  f029948:	afa00164 */ 	sw	$zero,0x164($sp)
/*  f02994c:	3c014100 */ 	lui	$at,0x4100
/*  f029950:	8c4f0010 */ 	lw	$t7,0x10($v0)
/*  f029954:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f029958:	53000006 */ 	beqzl	$t8,.L0f029974
/*  f02995c:	44817000 */ 	mtc1	$at,$f14
/*  f029960:	3c014080 */ 	lui	$at,0x4080
/*  f029964:	44817000 */ 	mtc1	$at,$f14
/*  f029968:	10000004 */ 	b	.L0f02997c
/*  f02996c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f029970:	44817000 */ 	mtc1	$at,$f14
.L0f029974:
/*  f029974:	00000000 */ 	nop
.L0f029978:
/*  f029978:	02a02025 */ 	or	$a0,$s5,$zero
.L0f02997c:
/*  f02997c:	00002825 */ 	or	$a1,$zero,$zero
/*  f029980:	e7a20170 */ 	swc1	$f2,0x170($sp)
/*  f029984:	0c006949 */ 	jal	model0001a524
/*  f029988:	e7ae016c */ 	swc1	$f14,0x16c($sp)
/*  f02998c:	c7a20170 */ 	lwc1	$f2,0x170($sp)
/*  f029990:	c6680004 */ 	lwc1	$f8,0x4($s3)
/*  f029994:	c6720008 */ 	lwc1	$f18,0x8($s3)
/*  f029998:	8fae01fc */ 	lw	$t6,0x1fc($sp)
/*  f02999c:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f0299a0:	c668000c */ 	lwc1	$f8,0xc($s3)
/*  f0299a4:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f0299a8:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f0299ac:	c6720010 */ 	lwc1	$f18,0x10($s3)
/*  f0299b0:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f0299b4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0299b8:	00027980 */ 	sll	$t7,$v0,0x6
/*  f0299bc:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f0299c0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0299c4:	44038000 */ 	mfc1	$v1,$f16
/*  f0299c8:	3c190102 */ 	lui	$t9,0x102
/*  f0299cc:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f0299d0:	c6680014 */ 	lwc1	$f8,0x14($s3)
/*  f0299d4:	44053000 */ 	mfc1	$a1,$f6
/*  f0299d8:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f0299dc:	c6720018 */ 	lwc1	$f18,0x18($s3)
/*  f0299e0:	260a0008 */ 	addiu	$t2,$s0,0x8
/*  f0299e4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0299e8:	c7ae016c */ 	lwc1	$f14,0x16c($sp)
/*  f0299ec:	afaa01f0 */ 	sw	$t2,0x1f0($sp)
/*  f0299f0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0299f4:	44068000 */ 	mfc1	$a2,$f16
/*  f0299f8:	37390040 */ 	ori	$t9,$t9,0x40
/*  f0299fc:	46024281 */ 	sub.s	$f10,$f8,$f2
/*  f029a00:	44073000 */ 	mfc1	$a3,$f6
/*  f029a04:	a7a30180 */ 	sh	$v1,0x180($sp)
/*  f029a08:	46029100 */ 	add.s	$f4,$f18,$f2
/*  f029a0c:	a7a30186 */ 	sh	$v1,0x186($sp)
/*  f029a10:	a7a3018c */ 	sh	$v1,0x18c($sp)
/*  f029a14:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f029a18:	a7a30192 */ 	sh	$v1,0x192($sp)
/*  f029a1c:	a7a50198 */ 	sh	$a1,0x198($sp)
/*  f029a20:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f029a24:	44088000 */ 	mfc1	$t0,$f16
/*  f029a28:	a7a5019e */ 	sh	$a1,0x19e($sp)
/*  f029a2c:	a7a501a4 */ 	sh	$a1,0x1a4($sp)
/*  f029a30:	44093000 */ 	mfc1	$t1,$f6
/*  f029a34:	a7a501aa */ 	sh	$a1,0x1aa($sp)
/*  f029a38:	a7a60182 */ 	sh	$a2,0x182($sp)
/*  f029a3c:	a7a60188 */ 	sh	$a2,0x188($sp)
/*  f029a40:	a7a6019a */ 	sh	$a2,0x19a($sp)
/*  f029a44:	a7a601a0 */ 	sh	$a2,0x1a0($sp)
/*  f029a48:	a7a7018e */ 	sh	$a3,0x18e($sp)
/*  f029a4c:	a7a70194 */ 	sh	$a3,0x194($sp)
/*  f029a50:	a7a701a6 */ 	sh	$a3,0x1a6($sp)
/*  f029a54:	a7a701ac */ 	sh	$a3,0x1ac($sp)
/*  f029a58:	a7a80184 */ 	sh	$t0,0x184($sp)
/*  f029a5c:	a7a80190 */ 	sh	$t0,0x190($sp)
/*  f029a60:	a7a8019c */ 	sh	$t0,0x19c($sp)
/*  f029a64:	a7a801a8 */ 	sh	$t0,0x1a8($sp)
/*  f029a68:	a7a9018a */ 	sh	$t1,0x18a($sp)
/*  f029a6c:	a7a90196 */ 	sh	$t1,0x196($sp)
/*  f029a70:	a7a901a2 */ 	sh	$t1,0x1a2($sp)
/*  f029a74:	a7a901ae */ 	sh	$t1,0x1ae($sp)
/*  f029a78:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f029a7c:	afa301cc */ 	sw	$v1,0x1cc($sp)
/*  f029a80:	afa501c8 */ 	sw	$a1,0x1c8($sp)
/*  f029a84:	e7ae016c */ 	swc1	$f14,0x16c($sp)
/*  f029a88:	afa601c4 */ 	sw	$a2,0x1c4($sp)
/*  f029a8c:	afa701c0 */ 	sw	$a3,0x1c0($sp)
/*  f029a90:	afa801bc */ 	sw	$t0,0x1bc($sp)
/*  f029a94:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f029a98:	afa901b8 */ 	sw	$t1,0x1b8($sp)
/*  f029a9c:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029aa0:	c7ae016c */ 	lwc1	$f14,0x16c($sp)
/*  f029aa4:	2401fff9 */ 	addiu	$at,$zero,-7
/*  f029aa8:	15010082 */ 	bne	$t0,$at,.L0f029cb4
/*  f029aac:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f029ab0:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f029ab4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f029ab8:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f029abc:	3c0e0700 */ 	lui	$t6,0x700
/*  f029ac0:	35ce0004 */ 	ori	$t6,$t6,0x4
/*  f029ac4:	26180008 */ 	addiu	$t8,$s0,0x8
/*  f029ac8:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f029acc:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f029ad0:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f029ad4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f029ad8:	00402025 */ 	or	$a0,$v0,$zero
/*  f029adc:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f029ae0:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f029ae4:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f029ae8:	2a810040 */ 	slti	$at,$s4,0x40
/*  f029aec:	a0640000 */ 	sb	$a0,0x0($v1)
/*  f029af0:	a0640001 */ 	sb	$a0,0x1($v1)
/*  f029af4:	1020000f */ 	beqz	$at,.L0f029b34
/*  f029af8:	a0640002 */ 	sb	$a0,0x2($v1)
/*  f029afc:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f029b00:	44944000 */ 	mtc1	$s4,$f8
/*  f029b04:	3c017f1b */ 	lui	$at,%hi(var7f1a894c)
/*  f029b08:	44998000 */ 	mtc1	$t9,$f16
/*  f029b0c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f029b10:	c426894c */ 	lwc1	$f6,%lo(var7f1a894c)($at)
/*  f029b14:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f029b18:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f029b1c:	00000000 */ 	nop
/*  f029b20:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f029b24:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f029b28:	44188000 */ 	mfc1	$t8,$f16
/*  f029b2c:	10000011 */ 	b	.L0f029b74
/*  f029b30:	a0780003 */ 	sb	$t8,0x3($v1)
.L0f029b34:
/*  f029b34:	8faf0210 */ 	lw	$t7,0x210($sp)
/*  f029b38:	240e007f */ 	addiu	$t6,$zero,0x7f
/*  f029b3c:	01d4c823 */ 	subu	$t9,$t6,$s4
/*  f029b40:	44995000 */ 	mtc1	$t9,$f10
/*  f029b44:	448f2000 */ 	mtc1	$t7,$f4
/*  f029b48:	3c017f1b */ 	lui	$at,%hi(var7f1a8950)
/*  f029b4c:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f029b50:	c4308950 */ 	lwc1	$f16,%lo(var7f1a8950)($at)
/*  f029b54:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f029b58:	46069202 */ 	mul.s	$f8,$f18,$f6
/*  f029b5c:	00000000 */ 	nop
/*  f029b60:	46104282 */ 	mul.s	$f10,$f8,$f16
/*  f029b64:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f029b68:	440e2000 */ 	mfc1	$t6,$f4
/*  f029b6c:	00000000 */ 	nop
/*  f029b70:	a06e0003 */ 	sb	$t6,0x3($v1)
.L0f029b74:
/*  f029b74:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f029b78:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f029b7c:	00408025 */ 	or	$s0,$v0,$zero
/*  f029b80:	27a60104 */ 	addiu	$a2,$sp,0x104
/*  f029b84:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f029b88:	24070200 */ 	addiu	$a3,$zero,0x200
/*  f029b8c:	27a50180 */ 	addiu	$a1,$sp,0x180
.L0f029b90:
/*  f029b90:	00002025 */ 	or	$a0,$zero,$zero
/*  f029b94:	02001825 */ 	or	$v1,$s0,$zero
/*  f029b98:	00c01025 */ 	or	$v0,$a2,$zero
.L0f029b9c:
/*  f029b9c:	8e410000 */ 	lw	$at,0x0($s2)
/*  f029ba0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f029ba4:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f029ba8:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f029bac:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f029bb0:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f029bb4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f029bb8:	a86ffff8 */ 	swl	$t7,-0x8($v1)
/*  f029bbc:	b86ffffb */ 	swr	$t7,-0x5($v1)
/*  f029bc0:	8e410008 */ 	lw	$at,0x8($s2)
/*  f029bc4:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f029bc8:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f029bcc:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f029bd0:	03110019 */ 	multu	$t8,$s1
/*  f029bd4:	00007012 */ 	mflo	$t6
/*  f029bd8:	00aec821 */ 	addu	$t9,$a1,$t6
/*  f029bdc:	872f0000 */ 	lh	$t7,0x0($t9)
/*  f029be0:	a46ffff4 */ 	sh	$t7,-0xc($v1)
/*  f029be4:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f029be8:	03110019 */ 	multu	$t8,$s1
/*  f029bec:	00007012 */ 	mflo	$t6
/*  f029bf0:	00aec821 */ 	addu	$t9,$a1,$t6
/*  f029bf4:	872f0002 */ 	lh	$t7,0x2($t9)
/*  f029bf8:	a46ffff6 */ 	sh	$t7,-0xa($v1)
/*  f029bfc:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f029c00:	03110019 */ 	multu	$t8,$s1
/*  f029c04:	00007012 */ 	mflo	$t6
/*  f029c08:	00aec821 */ 	addu	$t9,$a1,$t6
/*  f029c0c:	872f0004 */ 	lh	$t7,0x4($t9)
/*  f029c10:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f029c14:	1489ffe1 */ 	bne	$a0,$t1,.L0f029b9c
/*  f029c18:	a46ffff8 */ 	sh	$t7,-0x8($v1)
/*  f029c1c:	a6000008 */ 	sh	$zero,0x8($s0)
/*  f029c20:	a600000a */ 	sh	$zero,0xa($s0)
/*  f029c24:	a6070014 */ 	sh	$a3,0x14($s0)
/*  f029c28:	a6000016 */ 	sh	$zero,0x16($s0)
/*  f029c2c:	a6070020 */ 	sh	$a3,0x20($s0)
/*  f029c30:	a6070022 */ 	sh	$a3,0x22($s0)
/*  f029c34:	a600002c */ 	sh	$zero,0x2c($s0)
/*  f029c38:	a607002e */ 	sh	$a3,0x2e($s0)
/*  f029c3c:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f029c40:	3c190430 */ 	lui	$t9,0x430
/*  f029c44:	37390030 */ 	ori	$t9,$t9,0x30
/*  f029c48:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f029c4c:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f029c50:	af190000 */ 	sw	$t9,0x0($t8)
/*  f029c54:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f029c58:	02002025 */ 	or	$a0,$s0,$zero
/*  f029c5c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f029c60:	afb800c8 */ 	sw	$t8,0xc8($sp)
/*  f029c64:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*  f029c68:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f029c6c:	3c0eb100 */ 	lui	$t6,0xb100
/*  f029c70:	ad020004 */ 	sw	$v0,0x4($t0)
/*  f029c74:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f029c78:	35ce0032 */ 	ori	$t6,$t6,0x32
/*  f029c7c:	24192010 */ 	addiu	$t9,$zero,0x2010
/*  f029c80:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f029c84:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f029c88:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f029c8c:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f029c90:	27af0164 */ 	addiu	$t7,$sp,0x164
/*  f029c94:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f029c98:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f029c9c:	24070200 */ 	addiu	$a3,$zero,0x200
/*  f029ca0:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f029ca4:	14cfffba */ 	bne	$a2,$t7,.L0f029b90
/*  f029ca8:	26100030 */ 	addiu	$s0,$s0,0x30
/*  f029cac:	100006c0 */ 	b	.L0f02b7b0
/*  f029cb0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f029cb4:
/*  f029cb4:	3c05800b */ 	lui	$a1,%hi(g_TexShieldConfigs)
/*  f029cb8:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f029cbc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f029cc0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f029cc4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f029cc8:	8ca5b58c */ 	lw	$a1,%lo(g_TexShieldConfigs)($a1)
/*  f029ccc:	27a401f0 */ 	addiu	$a0,$sp,0x1f0
/*  f029cd0:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f029cd4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f029cd8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f029cdc:	0fc2ce70 */ 	jal	texSelect
/*  f029ce0:	e7ae016c */ 	swc1	$f14,0x16c($sp)
/*  f029ce4:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029ce8:	c7ae016c */ 	lwc1	$f14,0x16c($sp)
/*  f029cec:	27a50100 */ 	addiu	$a1,$sp,0x100
/*  f029cf0:	05000004 */ 	bltz	$t0,.L0f029d04
/*  f029cf4:	27a600fc */ 	addiu	$a2,$sp,0xfc
/*  f029cf8:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
/*  f029cfc:	1000001c */ 	b	.L0f029d70
/*  f029d00:	c72c0058 */ 	lwc1	$f12,0x58($t9)
.L0f029d04:
/*  f029d04:	2401fffe */ 	addiu	$at,$zero,-2
/*  f029d08:	15010019 */ 	bne	$t0,$at,.L0f029d70
/*  f029d0c:	46007306 */ 	mov.s	$f12,$f14
/*  f029d10:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f029d14:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f029d18:	81e20011 */ 	lb	$v0,0x11($t7)
/*  f029d1c:	0058082a */ 	slt	$at,$v0,$t8
/*  f029d20:	50200005 */ 	beqzl	$at,.L0f029d38
/*  f029d24:	44823000 */ 	mtc1	$v0,$f6
/*  f029d28:	44806000 */ 	mtc1	$zero,$f12
/*  f029d2c:	10000010 */ 	b	.L0f029d70
/*  f029d30:	00000000 */ 	nop
/*  f029d34:	44823000 */ 	mtc1	$v0,$f6
.L0f029d38:
/*  f029d38:	8fae020c */ 	lw	$t6,0x20c($sp)
/*  f029d3c:	3c014080 */ 	lui	$at,0x4080
/*  f029d40:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f029d44:	44819000 */ 	mtc1	$at,$f18
/*  f029d48:	448e8000 */ 	mtc1	$t6,$f16
/*  f029d4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f029d50:	44813000 */ 	mtc1	$at,$f6
/*  f029d54:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f029d58:	46089002 */ 	mul.s	$f0,$f18,$f8
/*  f029d5c:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f029d60:	46062480 */ 	add.s	$f18,$f4,$f6
/*  f029d64:	46009203 */ 	div.s	$f8,$f18,$f0
/*  f029d68:	46087302 */ 	mul.s	$f12,$f14,$f8
/*  f029d6c:	00000000 */ 	nop
.L0f029d70:
/*  f029d70:	0fc0a57e */ 	jal	chr0f0295f8
/*  f029d74:	27a700f8 */ 	addiu	$a3,$sp,0xf8
/*  f029d78:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f029d7c:	8fad00fc */ 	lw	$t5,0xfc($sp)
/*  f029d80:	8fbf00f8 */ 	lw	$ra,0xf8($sp)
/*  f029d84:	2587ffec */ 	addiu	$a3,$t4,-20
/*  f029d88:	25a3ffec */ 	addiu	$v1,$t5,-20
/*  f029d8c:	27e4ffec */ 	addiu	$a0,$ra,-20
/*  f029d90:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029d94:	00605025 */ 	or	$t2,$v1,$zero
/*  f029d98:	04e10002 */ 	bgez	$a3,.L0f029da4
/*  f029d9c:	00805825 */ 	or	$t3,$a0,$zero
/*  f029da0:	00003825 */ 	or	$a3,$zero,$zero
.L0f029da4:
/*  f029da4:	04610002 */ 	bgez	$v1,.L0f029db0
/*  f029da8:	2582ffc4 */ 	addiu	$v0,$t4,-60
/*  f029dac:	00005025 */ 	or	$t2,$zero,$zero
.L0f029db0:
/*  f029db0:	04810002 */ 	bgez	$a0,.L0f029dbc
/*  f029db4:	25a3ffc4 */ 	addiu	$v1,$t5,-60
/*  f029db8:	00005825 */ 	or	$t3,$zero,$zero
.L0f029dbc:
/*  f029dbc:	27e4ffc4 */ 	addiu	$a0,$ra,-60
/*  f029dc0:	afa200e8 */ 	sw	$v0,0xe8($sp)
/*  f029dc4:	afa300e4 */ 	sw	$v1,0xe4($sp)
/*  f029dc8:	04410002 */ 	bgez	$v0,.L0f029dd4
/*  f029dcc:	afa400e0 */ 	sw	$a0,0xe0($sp)
/*  f029dd0:	afa000e8 */ 	sw	$zero,0xe8($sp)
.L0f029dd4:
/*  f029dd4:	04610002 */ 	bgez	$v1,.L0f029de0
/*  f029dd8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x58)
/*  f029ddc:	afa000e4 */ 	sw	$zero,0xe4($sp)
.L0f029de0:
/*  f029de0:	04810002 */ 	bgez	$a0,.L0f029dec
/*  f029de4:	00000000 */ 	nop
/*  f029de8:	afa000e0 */ 	sw	$zero,0xe0($sp)
.L0f029dec:
/*  f029dec:	8f39a018 */ 	lw	$t9,%lo(g_Vars+0x58)($t9)
/*  f029df0:	241004b0 */ 	addiu	$s0,$zero,0x4b0
/*  f029df4:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f029df8:	0330001a */ 	div	$zero,$t9,$s0
/*  f029dfc:	00007810 */ 	mfhi	$t7
/*  f029e00:	448f8000 */ 	mtc1	$t7,$f16
/*  f029e04:	16000002 */ 	bnez	$s0,.L0f029e10
/*  f029e08:	00000000 */ 	nop
/*  f029e0c:	0007000d */ 	break	0x7
.L0f029e10:
/*  f029e10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f029e14:	16010004 */ 	bne	$s0,$at,.L0f029e28
/*  f029e18:	3c018000 */ 	lui	$at,0x8000
/*  f029e1c:	17210002 */ 	bne	$t9,$at,.L0f029e28
/*  f029e20:	00000000 */ 	nop
/*  f029e24:	0006000d */ 	break	0x6
.L0f029e28:
/*  f029e28:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f029e2c:	3c017f1b */ 	lui	$at,%hi(var7f1a8954)
/*  f029e30:	c4248954 */ 	lwc1	$f4,%lo(var7f1a8954)($at)
/*  f029e34:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f029e38:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f029e3c:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f029e40:	0c0068f7 */ 	jal	sinf
/*  f029e44:	00000000 */ 	nop
/*  f029e48:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x58)
/*  f029e4c:	8defa018 */ 	lw	$t7,%lo(g_Vars+0x58)($t7)
/*  f029e50:	3c014200 */ 	lui	$at,0x4200
/*  f029e54:	44811000 */ 	mtc1	$at,$f2
/*  f029e58:	01f0001a */ 	div	$zero,$t7,$s0
/*  f029e5c:	3c013f80 */ 	lui	$at,0x3f80
/*  f029e60:	44813000 */ 	mtc1	$at,$f6
/*  f029e64:	3c013f00 */ 	lui	$at,0x3f00
/*  f029e68:	44814000 */ 	mtc1	$at,$f8
/*  f029e6c:	46060480 */ 	add.s	$f18,$f0,$f6
/*  f029e70:	0000c010 */ 	mfhi	$t8
/*  f029e74:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f029e78:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029e7c:	46089402 */ 	mul.s	$f16,$f18,$f8
/*  f029e80:	44989000 */ 	mtc1	$t8,$f18
/*  f029e84:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f029e88:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f029e8c:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f029e90:	46028282 */ 	mul.s	$f10,$f16,$f2
/*  f029e94:	00000000 */ 	nop
/*  f029e98:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f029e9c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f029ea0:	44153000 */ 	mfc1	$s5,$f6
/*  f029ea4:	00000000 */ 	nop
/*  f029ea8:	00157400 */ 	sll	$t6,$s5,0x10
/*  f029eac:	000ecc03 */ 	sra	$t9,$t6,0x10
/*  f029eb0:	0320a825 */ 	or	$s5,$t9,$zero
/*  f029eb4:	16000002 */ 	bnez	$s0,.L0f029ec0
/*  f029eb8:	00000000 */ 	nop
/*  f029ebc:	0007000d */ 	break	0x7
.L0f029ec0:
/*  f029ec0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f029ec4:	16010004 */ 	bne	$s0,$at,.L0f029ed8
/*  f029ec8:	3c018000 */ 	lui	$at,0x8000
/*  f029ecc:	15e10002 */ 	bne	$t7,$at,.L0f029ed8
/*  f029ed0:	00000000 */ 	nop
/*  f029ed4:	0006000d */ 	break	0x6
.L0f029ed8:
/*  f029ed8:	3c017f1b */ 	lui	$at,%hi(var7f1a8958)
/*  f029edc:	c4308958 */ 	lwc1	$f16,%lo(var7f1a8958)($at)
/*  f029ee0:	46104302 */ 	mul.s	$f12,$f8,$f16
/*  f029ee4:	0c0068f4 */ 	jal	cosf
/*  f029ee8:	00000000 */ 	nop
/*  f029eec:	3c014200 */ 	lui	$at,0x4200
/*  f029ef0:	44811000 */ 	mtc1	$at,$f2
/*  f029ef4:	3c013f80 */ 	lui	$at,0x3f80
/*  f029ef8:	44816000 */ 	mtc1	$at,$f12
/*  f029efc:	3c013f00 */ 	lui	$at,0x3f00
/*  f029f00:	44812000 */ 	mtc1	$at,$f4
/*  f029f04:	460c0280 */ 	add.s	$f10,$f0,$f12
/*  f029f08:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029f0c:	26af0200 */ 	addiu	$t7,$s5,0x200
/*  f029f10:	2401fffd */ 	addiu	$at,$zero,-3
/*  f029f14:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f029f18:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f029f1c:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f029f20:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f029f24:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f029f28:	a7af0176 */ 	sh	$t7,0x176($sp)
/*  f029f2c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f029f30:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f029f34:	00000000 */ 	nop
/*  f029f38:	46029202 */ 	mul.s	$f8,$f18,$f2
/*  f029f3c:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f029f40:	440e8000 */ 	mfc1	$t6,$f16
/*  f029f44:	00000000 */ 	nop
/*  f029f48:	000e9c00 */ 	sll	$s3,$t6,0x10
/*  f029f4c:	0013cc03 */ 	sra	$t9,$s3,0x10
/*  f029f50:	03209825 */ 	or	$s3,$t9,$zero
/*  f029f54:	25d40200 */ 	addiu	$s4,$t6,0x200
/*  f029f58:	0014cc00 */ 	sll	$t9,$s4,0x10
/*  f029f5c:	11010008 */ 	beq	$t0,$at,.L0f029f80
/*  f029f60:	0019a403 */ 	sra	$s4,$t9,0x10
/*  f029f64:	2401fffc */ 	addiu	$at,$zero,-4
/*  f029f68:	11010005 */ 	beq	$t0,$at,.L0f029f80
/*  f029f6c:	2401fffb */ 	addiu	$at,$zero,-5
/*  f029f70:	11010003 */ 	beq	$t0,$at,.L0f029f80
/*  f029f74:	2401fffa */ 	addiu	$at,$zero,-6
/*  f029f78:	5501016b */ 	bnel	$t0,$at,.L0f02a528
/*  f029f7c:	2401fffe */ 	addiu	$at,$zero,-2
.L0f029f80:
/*  f029f80:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f029f84:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f029f88:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f029f8c:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f029f90:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f029f94:	3c190700 */ 	lui	$t9,0x700
/*  f029f98:	37390004 */ 	ori	$t9,$t9,0x4
/*  f029f9c:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f029fa0:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f029fa4:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f029fa8:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f029fac:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f029fb0:	00402025 */ 	or	$a0,$v0,$zero
/*  f029fb4:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f029fb8:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f029fbc:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f029fc0:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f029fc4:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f029fc8:	2401fffd */ 	addiu	$at,$zero,-3
/*  f029fcc:	15010014 */ 	bne	$t0,$at,.L0f02a020
/*  f029fd0:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f029fd4:	a0670000 */ 	sb	$a3,0x0($v1)
/*  f029fd8:	a06a0001 */ 	sb	$t2,0x1($v1)
/*  f029fdc:	a06b0002 */ 	sb	$t3,0x2($v1)
/*  f029fe0:	8faf0164 */ 	lw	$t7,0x164($sp)
/*  f029fe4:	8fb80210 */ 	lw	$t8,0x210($sp)
/*  f029fe8:	29e1000a */ 	slti	$at,$t7,0xa
/*  f029fec:	1020000a */ 	beqz	$at,.L0f02a018
/*  f029ff0:	00000000 */ 	nop
/*  f029ff4:	44985000 */ 	mtc1	$t8,$f10
/*  f029ff8:	3c017f1b */ 	lui	$at,%hi(var7f1a895c)
/*  f029ffc:	c426895c */ 	lwc1	$f6,%lo(var7f1a895c)($at)
/*  f02a000:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f02a004:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f02a008:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f02a00c:	44194000 */ 	mfc1	$t9,$f8
/*  f02a010:	10000031 */ 	b	.L0f02a0d8
/*  f02a014:	a0790003 */ 	sb	$t9,0x3($v1)
.L0f02a018:
/*  f02a018:	1000002f */ 	b	.L0f02a0d8
/*  f02a01c:	a0600003 */ 	sb	$zero,0x3($v1)
.L0f02a020:
/*  f02a020:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f02a024:	a06f0000 */ 	sb	$t7,0x0($v1)
/*  f02a028:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f02a02c:	a0780001 */ 	sb	$t8,0x1($v1)
/*  f02a030:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f02a034:	a06e0002 */ 	sb	$t6,0x2($v1)
/*  f02a038:	8fb90164 */ 	lw	$t9,0x164($sp)
/*  f02a03c:	2b21000a */ 	slti	$at,$t9,0xa
/*  f02a040:	10200024 */ 	beqz	$at,.L0f02a0d4
/*  f02a044:	2401fffc */ 	addiu	$at,$zero,-4
/*  f02a048:	1501000a */ 	bne	$t0,$at,.L0f02a074
/*  f02a04c:	8faf0210 */ 	lw	$t7,0x210($sp)
/*  f02a050:	448f8000 */ 	mtc1	$t7,$f16
/*  f02a054:	3c017f1b */ 	lui	$at,%hi(var7f1a8960)
/*  f02a058:	c4248960 */ 	lwc1	$f4,%lo(var7f1a8960)($at)
/*  f02a05c:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a060:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f02a064:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f02a068:	440e9000 */ 	mfc1	$t6,$f18
/*  f02a06c:	1000001a */ 	b	.L0f02a0d8
/*  f02a070:	a06e0003 */ 	sb	$t6,0x3($v1)
.L0f02a074:
/*  f02a074:	2401fffb */ 	addiu	$at,$zero,-5
/*  f02a078:	1501000a */ 	bne	$t0,$at,.L0f02a0a4
/*  f02a07c:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02a080:	44994000 */ 	mtc1	$t9,$f8
/*  f02a084:	3c017f1b */ 	lui	$at,%hi(var7f1a8964)
/*  f02a088:	c42a8964 */ 	lwc1	$f10,%lo(var7f1a8964)($at)
/*  f02a08c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f02a090:	460a8102 */ 	mul.s	$f4,$f16,$f10
/*  f02a094:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f02a098:	44183000 */ 	mfc1	$t8,$f6
/*  f02a09c:	1000000e */ 	b	.L0f02a0d8
/*  f02a0a0:	a0780003 */ 	sb	$t8,0x3($v1)
.L0f02a0a4:
/*  f02a0a4:	2401fffa */ 	addiu	$at,$zero,-6
/*  f02a0a8:	1501000b */ 	bne	$t0,$at,.L0f02a0d8
/*  f02a0ac:	8fae0210 */ 	lw	$t6,0x210($sp)
/*  f02a0b0:	448e9000 */ 	mtc1	$t6,$f18
/*  f02a0b4:	3c017f1b */ 	lui	$at,%hi(var7f1a8968)
/*  f02a0b8:	c4308968 */ 	lwc1	$f16,%lo(var7f1a8968)($at)
/*  f02a0bc:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f02a0c0:	46104282 */ 	mul.s	$f10,$f8,$f16
/*  f02a0c4:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f02a0c8:	440f2000 */ 	mfc1	$t7,$f4
/*  f02a0cc:	10000002 */ 	b	.L0f02a0d8
/*  f02a0d0:	a06f0003 */ 	sb	$t7,0x3($v1)
.L0f02a0d4:
/*  f02a0d4:	a0600003 */ 	sb	$zero,0x3($v1)
.L0f02a0d8:
/*  f02a0d8:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f02a0dc:	afa301d8 */ 	sw	$v1,0x1d8($sp)
/*  f02a0e0:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02a0e4:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02a0e8:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f02a0ec:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02a0f0:	8fa501f8 */ 	lw	$a1,0x1f8($sp)
/*  f02a0f4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02a0f8:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a0fc:	90a40000 */ 	lbu	$a0,0x0($a1)
/*  f02a100:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02a104:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02a108:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02a10c:	10810006 */ 	beq	$a0,$at,.L0f02a128
/*  f02a110:	00408025 */ 	or	$s0,$v0,$zero
/*  f02a114:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f02a118:	11240003 */ 	beq	$t1,$a0,.L0f02a128
/*  f02a11c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f02a120:	548100b0 */ 	bnel	$a0,$at,.L0f02a3e4
/*  f02a124:	24080200 */ 	addiu	$t0,$zero,0x200
.L0f02a128:
/*  f02a128:	8cb80004 */ 	lw	$t8,0x4($a1)
/*  f02a12c:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f02a130:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x58)
/*  f02a134:	8f0e0010 */ 	lw	$t6,0x10($t8)
/*  f02a138:	31d91000 */ 	andi	$t9,$t6,0x1000
/*  f02a13c:	532000a9 */ 	beqzl	$t9,.L0f02a3e4
/*  f02a140:	24080200 */ 	addiu	$t0,$zero,0x200
/*  f02a144:	8defa018 */ 	lw	$t7,%lo(g_Vars+0x58)($t7)
/*  f02a148:	2401015e */ 	addiu	$at,$zero,0x15e
/*  f02a14c:	afa301d8 */ 	sw	$v1,0x1d8($sp)
/*  f02a150:	01e1001a */ 	div	$zero,$t7,$at
/*  f02a154:	0000c010 */ 	mfhi	$t8
/*  f02a158:	44983000 */ 	mtc1	$t8,$f6
/*  f02a15c:	3c017f1b */ 	lui	$at,%hi(var7f1a896c)
/*  f02a160:	c428896c */ 	lwc1	$f8,%lo(var7f1a896c)($at)
/*  f02a164:	468034a0 */ 	cvt.s.w	$f18,$f6
/*  f02a168:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02a16c:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02a170:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02a174:	46089302 */ 	mul.s	$f12,$f18,$f8
/*  f02a178:	0c0068f7 */ 	jal	sinf
/*  f02a17c:	00000000 */ 	nop
/*  f02a180:	3c013f80 */ 	lui	$at,0x3f80
/*  f02a184:	44818000 */ 	mtc1	$at,$f16
/*  f02a188:	3c013f00 */ 	lui	$at,0x3f00
/*  f02a18c:	44812000 */ 	mtc1	$at,$f4
/*  f02a190:	46100280 */ 	add.s	$f10,$f0,$f16
/*  f02a194:	3c0142f0 */ 	lui	$at,0x42f0
/*  f02a198:	44813000 */ 	mtc1	$at,$f6
/*  f02a19c:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02a1a0:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f02a1a4:	3c014248 */ 	lui	$at,0x4248
/*  f02a1a8:	44818000 */ 	mtc1	$at,$f16
/*  f02a1ac:	30ee00ff */ 	andi	$t6,$a3,0xff
/*  f02a1b0:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a1b4:	448e5000 */ 	mtc1	$t6,$f10
/*  f02a1b8:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02a1bc:	460c3482 */ 	mul.s	$f18,$f6,$f12
/*  f02a1c0:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02a1c4:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f02a1c8:	460c8082 */ 	mul.s	$f2,$f16,$f12
/*  f02a1cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f02a1d0:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f02a1d4:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f02a1d8:	440f4000 */ 	mfc1	$t7,$f8
/*  f02a1dc:	00000000 */ 	nop
/*  f02a1e0:	25f80032 */ 	addiu	$t8,$t7,0x32
/*  f02a1e4:	05c10004 */ 	bgez	$t6,.L0f02a1f8
/*  f02a1e8:	a0780003 */ 	sb	$t8,0x3($v1)
/*  f02a1ec:	44813000 */ 	mtc1	$at,$f6
/*  f02a1f0:	00000000 */ 	nop
/*  f02a1f4:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f02a1f8:
/*  f02a1f8:	46022480 */ 	add.s	$f18,$f4,$f2
/*  f02a1fc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f02a200:	3c014f00 */ 	lui	$at,0x4f00
/*  f02a204:	315800ff */ 	andi	$t8,$t2,0xff
/*  f02a208:	4459f800 */ 	cfc1	$t9,$31
/*  f02a20c:	44cff800 */ 	ctc1	$t7,$31
/*  f02a210:	00000000 */ 	nop
/*  f02a214:	46009224 */ 	cvt.w.s	$f8,$f18
/*  f02a218:	444ff800 */ 	cfc1	$t7,$31
/*  f02a21c:	00000000 */ 	nop
/*  f02a220:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f02a224:	51e00013 */ 	beqzl	$t7,.L0f02a274
/*  f02a228:	440f4000 */ 	mfc1	$t7,$f8
/*  f02a22c:	44814000 */ 	mtc1	$at,$f8
/*  f02a230:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f02a234:	46089201 */ 	sub.s	$f8,$f18,$f8
/*  f02a238:	44cff800 */ 	ctc1	$t7,$31
/*  f02a23c:	00000000 */ 	nop
/*  f02a240:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f02a244:	444ff800 */ 	cfc1	$t7,$31
/*  f02a248:	00000000 */ 	nop
/*  f02a24c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f02a250:	15e00005 */ 	bnez	$t7,.L0f02a268
/*  f02a254:	00000000 */ 	nop
/*  f02a258:	440f4000 */ 	mfc1	$t7,$f8
/*  f02a25c:	3c018000 */ 	lui	$at,0x8000
/*  f02a260:	10000007 */ 	b	.L0f02a280
/*  f02a264:	01e17825 */ 	or	$t7,$t7,$at
.L0f02a268:
/*  f02a268:	10000005 */ 	b	.L0f02a280
/*  f02a26c:	240fffff */ 	addiu	$t7,$zero,-1
/*  f02a270:	440f4000 */ 	mfc1	$t7,$f8
.L0f02a274:
/*  f02a274:	00000000 */ 	nop
/*  f02a278:	05e0fffb */ 	bltz	$t7,.L0f02a268
/*  f02a27c:	00000000 */ 	nop
.L0f02a280:
/*  f02a280:	44d9f800 */ 	ctc1	$t9,$31
/*  f02a284:	44988000 */ 	mtc1	$t8,$f16
/*  f02a288:	a06f0000 */ 	sb	$t7,0x0($v1)
/*  f02a28c:	07010005 */ 	bgez	$t8,.L0f02a2a4
/*  f02a290:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a294:	3c014f80 */ 	lui	$at,0x4f80
/*  f02a298:	44813000 */ 	mtc1	$at,$f6
/*  f02a29c:	00000000 */ 	nop
/*  f02a2a0:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f02a2a4:
/*  f02a2a4:	46025100 */ 	add.s	$f4,$f10,$f2
/*  f02a2a8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f02a2ac:	3c014f00 */ 	lui	$at,0x4f00
/*  f02a2b0:	316f00ff */ 	andi	$t7,$t3,0xff
/*  f02a2b4:	444ef800 */ 	cfc1	$t6,$31
/*  f02a2b8:	44d9f800 */ 	ctc1	$t9,$31
/*  f02a2bc:	00000000 */ 	nop
/*  f02a2c0:	460024a4 */ 	cvt.w.s	$f18,$f4
/*  f02a2c4:	4459f800 */ 	cfc1	$t9,$31
/*  f02a2c8:	00000000 */ 	nop
/*  f02a2cc:	33390078 */ 	andi	$t9,$t9,0x78
/*  f02a2d0:	53200013 */ 	beqzl	$t9,.L0f02a320
/*  f02a2d4:	44199000 */ 	mfc1	$t9,$f18
/*  f02a2d8:	44819000 */ 	mtc1	$at,$f18
/*  f02a2dc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f02a2e0:	46122481 */ 	sub.s	$f18,$f4,$f18
/*  f02a2e4:	44d9f800 */ 	ctc1	$t9,$31
/*  f02a2e8:	00000000 */ 	nop
/*  f02a2ec:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f02a2f0:	4459f800 */ 	cfc1	$t9,$31
/*  f02a2f4:	00000000 */ 	nop
/*  f02a2f8:	33390078 */ 	andi	$t9,$t9,0x78
/*  f02a2fc:	17200005 */ 	bnez	$t9,.L0f02a314
/*  f02a300:	00000000 */ 	nop
/*  f02a304:	44199000 */ 	mfc1	$t9,$f18
/*  f02a308:	3c018000 */ 	lui	$at,0x8000
/*  f02a30c:	10000007 */ 	b	.L0f02a32c
/*  f02a310:	0321c825 */ 	or	$t9,$t9,$at
.L0f02a314:
/*  f02a314:	10000005 */ 	b	.L0f02a32c
/*  f02a318:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f02a31c:	44199000 */ 	mfc1	$t9,$f18
.L0f02a320:
/*  f02a320:	00000000 */ 	nop
/*  f02a324:	0720fffb */ 	bltz	$t9,.L0f02a314
/*  f02a328:	00000000 */ 	nop
.L0f02a32c:
/*  f02a32c:	44cef800 */ 	ctc1	$t6,$31
/*  f02a330:	448f4000 */ 	mtc1	$t7,$f8
/*  f02a334:	a0790001 */ 	sb	$t9,0x1($v1)
/*  f02a338:	05e10005 */ 	bgez	$t7,.L0f02a350
/*  f02a33c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f02a340:	3c014f80 */ 	lui	$at,0x4f80
/*  f02a344:	44813000 */ 	mtc1	$at,$f6
/*  f02a348:	00000000 */ 	nop
/*  f02a34c:	46068400 */ 	add.s	$f16,$f16,$f6
.L0f02a350:
/*  f02a350:	46028280 */ 	add.s	$f10,$f16,$f2
/*  f02a354:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f02a358:	3c014f00 */ 	lui	$at,0x4f00
/*  f02a35c:	4458f800 */ 	cfc1	$t8,$31
/*  f02a360:	44cef800 */ 	ctc1	$t6,$31
/*  f02a364:	00000000 */ 	nop
/*  f02a368:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f02a36c:	444ef800 */ 	cfc1	$t6,$31
/*  f02a370:	00000000 */ 	nop
/*  f02a374:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f02a378:	51c00013 */ 	beqzl	$t6,.L0f02a3c8
/*  f02a37c:	440e2000 */ 	mfc1	$t6,$f4
/*  f02a380:	44812000 */ 	mtc1	$at,$f4
/*  f02a384:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f02a388:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f02a38c:	44cef800 */ 	ctc1	$t6,$31
/*  f02a390:	00000000 */ 	nop
/*  f02a394:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f02a398:	444ef800 */ 	cfc1	$t6,$31
/*  f02a39c:	00000000 */ 	nop
/*  f02a3a0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f02a3a4:	15c00005 */ 	bnez	$t6,.L0f02a3bc
/*  f02a3a8:	00000000 */ 	nop
/*  f02a3ac:	440e2000 */ 	mfc1	$t6,$f4
/*  f02a3b0:	3c018000 */ 	lui	$at,0x8000
/*  f02a3b4:	10000007 */ 	b	.L0f02a3d4
/*  f02a3b8:	01c17025 */ 	or	$t6,$t6,$at
.L0f02a3bc:
/*  f02a3bc:	10000005 */ 	b	.L0f02a3d4
/*  f02a3c0:	240effff */ 	addiu	$t6,$zero,-1
/*  f02a3c4:	440e2000 */ 	mfc1	$t6,$f4
.L0f02a3c8:
/*  f02a3c8:	00000000 */ 	nop
/*  f02a3cc:	05c0fffb */ 	bltz	$t6,.L0f02a3bc
/*  f02a3d0:	00000000 */ 	nop
.L0f02a3d4:
/*  f02a3d4:	44d8f800 */ 	ctc1	$t8,$31
/*  f02a3d8:	10000006 */ 	b	.L0f02a3f4
/*  f02a3dc:	a06e0002 */ 	sb	$t6,0x2($v1)
/*  f02a3e0:	24080200 */ 	addiu	$t0,$zero,0x200
.L0f02a3e4:
/*  f02a3e4:	0000a825 */ 	or	$s5,$zero,$zero
/*  f02a3e8:	00009825 */ 	or	$s3,$zero,$zero
/*  f02a3ec:	a7a80176 */ 	sh	$t0,0x176($sp)
/*  f02a3f0:	24140200 */ 	addiu	$s4,$zero,0x200
.L0f02a3f4:
/*  f02a3f4:	27a60104 */ 	addiu	$a2,$sp,0x104
/*  f02a3f8:	27a50180 */ 	addiu	$a1,$sp,0x180
.L0f02a3fc:
/*  f02a3fc:	87a80176 */ 	lh	$t0,0x176($sp)
/*  f02a400:	00002025 */ 	or	$a0,$zero,$zero
/*  f02a404:	02001825 */ 	or	$v1,$s0,$zero
/*  f02a408:	00c01025 */ 	or	$v0,$a2,$zero
.L0f02a40c:
/*  f02a40c:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02a410:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f02a414:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02a418:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f02a41c:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f02a420:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f02a424:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f02a428:	a878fff8 */ 	swl	$t8,-0x8($v1)
/*  f02a42c:	b878fffb */ 	swr	$t8,-0x5($v1)
/*  f02a430:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02a434:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02a438:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02a43c:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f02a440:	01d10019 */ 	multu	$t6,$s1
/*  f02a444:	00007812 */ 	mflo	$t7
/*  f02a448:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02a44c:	87380000 */ 	lh	$t8,0x0($t9)
/*  f02a450:	a478fff4 */ 	sh	$t8,-0xc($v1)
/*  f02a454:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f02a458:	01d10019 */ 	multu	$t6,$s1
/*  f02a45c:	00007812 */ 	mflo	$t7
/*  f02a460:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02a464:	87380002 */ 	lh	$t8,0x2($t9)
/*  f02a468:	a478fff6 */ 	sh	$t8,-0xa($v1)
/*  f02a46c:	8c4efffc */ 	lw	$t6,-0x4($v0)
/*  f02a470:	01d10019 */ 	multu	$t6,$s1
/*  f02a474:	00007812 */ 	mflo	$t7
/*  f02a478:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02a47c:	87380004 */ 	lh	$t8,0x4($t9)
/*  f02a480:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02a484:	1489ffe1 */ 	bne	$a0,$t1,.L0f02a40c
/*  f02a488:	a478fff8 */ 	sh	$t8,-0x8($v1)
/*  f02a48c:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02a490:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02a494:	a6080014 */ 	sh	$t0,0x14($s0)
/*  f02a498:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02a49c:	a6080020 */ 	sh	$t0,0x20($s0)
/*  f02a4a0:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02a4a4:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02a4a8:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02a4ac:	8fae01f0 */ 	lw	$t6,0x1f0($sp)
/*  f02a4b0:	3c190430 */ 	lui	$t9,0x430
/*  f02a4b4:	37390030 */ 	ori	$t9,$t9,0x30
/*  f02a4b8:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f02a4bc:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02a4c0:	add90000 */ 	sw	$t9,0x0($t6)
/*  f02a4c4:	a7a80176 */ 	sh	$t0,0x176($sp)
/*  f02a4c8:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f02a4cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f02a4d0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f02a4d4:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f02a4d8:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f02a4dc:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f02a4e0:	3c0fb100 */ 	lui	$t7,0xb100
/*  f02a4e4:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f02a4e8:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02a4ec:	35ef0032 */ 	ori	$t7,$t7,0x32
/*  f02a4f0:	24192010 */ 	addiu	$t9,$zero,0x2010
/*  f02a4f4:	270e0008 */ 	addiu	$t6,$t8,0x8
/*  f02a4f8:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02a4fc:	af190004 */ 	sw	$t9,0x4($t8)
/*  f02a500:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f02a504:	27b80164 */ 	addiu	$t8,$sp,0x164
/*  f02a508:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f02a50c:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02a510:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f02a514:	14d8ffb9 */ 	bne	$a2,$t8,.L0f02a3fc
/*  f02a518:	26100030 */ 	addiu	$s0,$s0,0x30
/*  f02a51c:	100004a4 */ 	b	.L0f02b7b0
/*  f02a520:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f02a524:	2401fffe */ 	addiu	$at,$zero,-2
.L0f02a528:
/*  f02a528:	150100d5 */ 	bne	$t0,$at,.L0f02a880
/*  f02a52c:	8fae01f4 */ 	lw	$t6,0x1f4($sp)
/*  f02a530:	8fa3020c */ 	lw	$v1,0x20c($sp)
/*  f02a534:	81c20011 */ 	lb	$v0,0x11($t6)
/*  f02a538:	8faf0208 */ 	lw	$t7,0x208($sp)
/*  f02a53c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f02a540:	0043082a */ 	slt	$at,$v0,$v1
/*  f02a544:	50200005 */ 	beqzl	$at,.L0f02a55c
/*  f02a548:	448f3000 */ 	mtc1	$t7,$f6
/*  f02a54c:	44806000 */ 	mtc1	$zero,$f12
/*  f02a550:	1000001f */ 	b	.L0f02a5d0
/*  f02a554:	46006086 */ 	mov.s	$f2,$f12
/*  f02a558:	448f3000 */ 	mtc1	$t7,$f6
.L0f02a55c:
/*  f02a55c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f02a560:	44814000 */ 	mtc1	$at,$f8
/*  f02a564:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f02a568:	44829000 */ 	mtc1	$v0,$f18
/*  f02a56c:	3c017f1b */ 	lui	$at,%hi(var7f1a8970)
/*  f02a570:	c4248970 */ 	lwc1	$f4,%lo(var7f1a8970)($at)
/*  f02a574:	3c014220 */ 	lui	$at,0x4220
/*  f02a578:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f02a57c:	44813000 */ 	mtc1	$at,$f6
/*  f02a580:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02a584:	3c017f1b */ 	lui	$at,%hi(var7f1a8974)
/*  f02a588:	46104281 */ 	sub.s	$f10,$f8,$f16
/*  f02a58c:	44838000 */ 	mtc1	$v1,$f16
/*  f02a590:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f02a594:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a598:	44998000 */ 	mtc1	$t9,$f16
/*  f02a59c:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f02a5a0:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f02a5a4:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f02a5a8:	460c2480 */ 	add.s	$f18,$f4,$f12
/*  f02a5ac:	c4248974 */ 	lwc1	$f4,%lo(var7f1a8974)($at)
/*  f02a5b0:	44806000 */ 	mtc1	$zero,$f12
/*  f02a5b4:	46009183 */ 	div.s	$f6,$f18,$f0
/*  f02a5b8:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f02a5bc:	00000000 */ 	nop
/*  f02a5c0:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f02a5c4:	00000000 */ 	nop
/*  f02a5c8:	46121082 */ 	mul.s	$f2,$f2,$f18
/*  f02a5cc:	00000000 */ 	nop
.L0f02a5d0:
/*  f02a5d0:	3c01437f */ 	lui	$at,0x437f
/*  f02a5d4:	44810000 */ 	mtc1	$at,$f0
/*  f02a5d8:	00000000 */ 	nop
/*  f02a5dc:	4602003c */ 	c.lt.s	$f0,$f2
/*  f02a5e0:	00000000 */ 	nop
/*  f02a5e4:	45020004 */ 	bc1fl	.L0f02a5f8
/*  f02a5e8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f02a5ec:	10000006 */ 	b	.L0f02a608
/*  f02a5f0:	46000086 */ 	mov.s	$f2,$f0
/*  f02a5f4:	460c103c */ 	c.lt.s	$f2,$f12
.L0f02a5f8:
/*  f02a5f8:	00000000 */ 	nop
/*  f02a5fc:	45000002 */ 	bc1f	.L0f02a608
/*  f02a600:	00000000 */ 	nop
/*  f02a604:	46006086 */ 	mov.s	$f2,$f12
.L0f02a608:
/*  f02a608:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f02a60c:	e7a200ac */ 	swc1	$f2,0xac($sp)
/*  f02a610:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f02a614:	3c0f0708 */ 	lui	$t7,0x708
/*  f02a618:	35ef000c */ 	ori	$t7,$t7,0xc
/*  f02a61c:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f02a620:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02a624:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f02a628:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02a62c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f02a630:	00402025 */ 	or	$a0,$v0,$zero
/*  f02a634:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a638:	c7a200ac */ 	lwc1	$f2,0xac($sp)
/*  f02a63c:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f02a640:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f02a644:	8fa700e0 */ 	lw	$a3,0xe0($sp)
/*  f02a648:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f02a64c:	4600120d */ 	trunc.w.s	$f8,$f2
/*  f02a650:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f02a654:	a0600007 */ 	sb	$zero,0x7($v1)
/*  f02a658:	a0650000 */ 	sb	$a1,0x0($v1)
/*  f02a65c:	44184000 */ 	mfc1	$t8,$f8
/*  f02a660:	a0650004 */ 	sb	$a1,0x4($v1)
/*  f02a664:	a0660001 */ 	sb	$a2,0x1($v1)
/*  f02a668:	a0660005 */ 	sb	$a2,0x5($v1)
/*  f02a66c:	a0670002 */ 	sb	$a3,0x2($v1)
/*  f02a670:	a0670006 */ 	sb	$a3,0x6($v1)
/*  f02a674:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f02a678:	a0780003 */ 	sb	$t8,0x3($v1)
/*  f02a67c:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f02a680:	02747021 */ 	addu	$t6,$s3,$s4
/*  f02a684:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f02a688:	02abc821 */ 	addu	$t9,$s5,$t3
/*  f02a68c:	0019c043 */ 	sra	$t8,$t9,0x1
/*  f02a690:	00408025 */ 	or	$s0,$v0,$zero
/*  f02a694:	afb80040 */ 	sw	$t8,0x40($sp)
/*  f02a698:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f02a69c:	27a60104 */ 	addiu	$a2,$sp,0x104
/*  f02a6a0:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f02a6a4:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f02a6a8:	27a50180 */ 	addiu	$a1,$sp,0x180
.L0f02a6ac:
/*  f02a6ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f02a6b0:	02001825 */ 	or	$v1,$s0,$zero
/*  f02a6b4:	00c01025 */ 	or	$v0,$a2,$zero
.L0f02a6b8:
/*  f02a6b8:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02a6bc:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f02a6c0:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02a6c4:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f02a6c8:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f02a6cc:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02a6d0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f02a6d4:	a879fff8 */ 	swl	$t9,-0x8($v1)
/*  f02a6d8:	b879fffb */ 	swr	$t9,-0x5($v1)
/*  f02a6dc:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02a6e0:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02a6e4:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02a6e8:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f02a6ec:	03110019 */ 	multu	$t8,$s1
/*  f02a6f0:	00007812 */ 	mflo	$t7
/*  f02a6f4:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f02a6f8:	85d90000 */ 	lh	$t9,0x0($t6)
/*  f02a6fc:	a479fff4 */ 	sh	$t9,-0xc($v1)
/*  f02a700:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f02a704:	03110019 */ 	multu	$t8,$s1
/*  f02a708:	00007812 */ 	mflo	$t7
/*  f02a70c:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f02a710:	85d90002 */ 	lh	$t9,0x2($t6)
/*  f02a714:	a479fff6 */ 	sh	$t9,-0xa($v1)
/*  f02a718:	8c58fffc */ 	lw	$t8,-0x4($v0)
/*  f02a71c:	03110019 */ 	multu	$t8,$s1
/*  f02a720:	00007812 */ 	mflo	$t7
/*  f02a724:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f02a728:	85d90004 */ 	lh	$t9,0x4($t6)
/*  f02a72c:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02a730:	1489ffe1 */ 	bne	$a0,$t1,.L0f02a6b8
/*  f02a734:	a479fff8 */ 	sh	$t9,-0x8($v1)
/*  f02a738:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02a73c:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02a740:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02a744:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02a748:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02a74c:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02a750:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02a754:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02a758:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02a75c:	860e0024 */ 	lh	$t6,0x24($s0)
/*  f02a760:	86190000 */ 	lh	$t9,0x0($s0)
/*  f02a764:	aa010030 */ 	swl	$at,0x30($s0)
/*  f02a768:	ba010033 */ 	swr	$at,0x33($s0)
/*  f02a76c:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02a770:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a774:	86190018 */ 	lh	$t9,0x18($s0)
/*  f02a778:	aa0f0034 */ 	swl	$t7,0x34($s0)
/*  f02a77c:	ba0f0037 */ 	swr	$t7,0x37($s0)
/*  f02a780:	860f000c */ 	lh	$t7,0xc($s0)
/*  f02a784:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02a788:	02002025 */ 	or	$a0,$s0,$zero
/*  f02a78c:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f02a790:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a794:	86190002 */ 	lh	$t9,0x2($s0)
/*  f02a798:	860e0026 */ 	lh	$t6,0x26($s0)
/*  f02a79c:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02a7a0:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f02a7a4:	860f000e */ 	lh	$t7,0xe($s0)
/*  f02a7a8:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a7ac:	8619001a */ 	lh	$t9,0x1a($s0)
/*  f02a7b0:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f02a7b4:	aa010038 */ 	swl	$at,0x38($s0)
/*  f02a7b8:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a7bc:	86190004 */ 	lh	$t9,0x4($s0)
/*  f02a7c0:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f02a7c4:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02a7c8:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f02a7cc:	860f0010 */ 	lh	$t7,0x10($s0)
/*  f02a7d0:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a7d4:	8619001c */ 	lh	$t9,0x1c($s0)
/*  f02a7d8:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f02a7dc:	ba01003b */ 	swr	$at,0x3b($s0)
/*  f02a7e0:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f02a7e4:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02a7e8:	a60f0034 */ 	sh	$t7,0x34($s0)
/*  f02a7ec:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f02a7f0:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02a7f4:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f02a7f8:	a20c0037 */ 	sb	$t4,0x37($s0)
/*  f02a7fc:	3c0e0440 */ 	lui	$t6,0x440
/*  f02a800:	a619003a */ 	sh	$t9,0x3a($s0)
/*  f02a804:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02a808:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02a80c:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02a810:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02a814:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f02a818:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f02a81c:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f02a820:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f02a824:	afb800a4 */ 	sw	$t8,0xa4($sp)
/*  f02a828:	8fa700a4 */ 	lw	$a3,0xa4($sp)
/*  f02a82c:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f02a830:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f02a834:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f02a838:	8fb901f0 */ 	lw	$t9,0x1f0($sp)
/*  f02a83c:	3c0fb100 */ 	lui	$t7,0xb100
/*  f02a840:	3c0e0332 */ 	lui	$t6,0x332
/*  f02a844:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f02a848:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f02a84c:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02a850:	35ef4444 */ 	ori	$t7,$t7,0x4444
/*  f02a854:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f02a858:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f02a85c:	27b90164 */ 	addiu	$t9,$sp,0x164
/*  f02a860:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f02a864:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02a868:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f02a86c:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f02a870:	14d9ff8e */ 	bne	$a2,$t9,.L0f02a6ac
/*  f02a874:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f02a878:	100003cd */ 	b	.L0f02b7b0
/*  f02a87c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f02a880:
/*  f02a880:	05010130 */ 	bgez	$t0,.L0f02ad44
/*  f02a884:	8fae01f8 */ 	lw	$t6,0x1f8($sp)
/*  f02a888:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f02a88c:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f02a890:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02a894:	2401ffff */ 	addiu	$at,$zero,-1
/*  f02a898:	00408025 */ 	or	$s0,$v0,$zero
/*  f02a89c:	15010035 */ 	bne	$t0,$at,.L0f02a974
/*  f02a8a0:	8fb801f4 */ 	lw	$t8,0x1f4($sp)
/*  f02a8a4:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x8)
/*  f02a8a8:	8c429fc8 */ 	lw	$v0,%lo(g_Vars+0x8)($v0)
/*  f02a8ac:	8f03000c */ 	lw	$v1,0xc($t8)
/*  f02a8b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f02a8b4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f02a8b8:	00437823 */ 	subu	$t7,$v0,$v1
/*  f02a8bc:	29e10051 */ 	slti	$at,$t7,0x51
/*  f02a8c0:	10200016 */ 	beqz	$at,.L0f02a91c
/*  f02a8c4:	00627023 */ 	subu	$t6,$v1,$v0
/*  f02a8c8:	25d90050 */ 	addiu	$t9,$t6,0x50
/*  f02a8cc:	44993000 */ 	mtc1	$t9,$f6
/*  f02a8d0:	8fb80210 */ 	lw	$t8,0x210($sp)
/*  f02a8d4:	3c01404c */ 	lui	$at,0x404c
/*  f02a8d8:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f02a8dc:	44982000 */ 	mtc1	$t8,$f4
/*  f02a8e0:	44815000 */ 	mtc1	$at,$f10
/*  f02a8e4:	3c017f1b */ 	lui	$at,%hi(var7f1a8978)
/*  f02a8e8:	c4288978 */ 	lwc1	$f8,%lo(var7f1a8978)($at)
/*  f02a8ec:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f02a8f0:	460a8002 */ 	mul.s	$f0,$f16,$f10
/*  f02a8f4:	00000000 */ 	nop
/*  f02a8f8:	46089182 */ 	mul.s	$f6,$f18,$f8
/*  f02a8fc:	00000000 */ 	nop
/*  f02a900:	46060002 */ 	mul.s	$f0,$f0,$f6
/*  f02a904:	4600040d */ 	trunc.w.s	$f16,$f0
/*  f02a908:	44058000 */ 	mfc1	$a1,$f16
/*  f02a90c:	00000000 */ 	nop
/*  f02a910:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f02a914:	10000001 */ 	b	.L0f02a91c
/*  f02a918:	01c02825 */ 	or	$a1,$t6,$zero
.L0f02a91c:
/*  f02a91c:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f02a920:	a3a5017f */ 	sb	$a1,0x17f($sp)
/*  f02a924:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02a928:	3c0f0700 */ 	lui	$t7,0x700
/*  f02a92c:	35ef0004 */ 	ori	$t7,$t7,0x4
/*  f02a930:	26380008 */ 	addiu	$t8,$s1,0x8
/*  f02a934:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f02a938:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f02a93c:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02a940:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f02a944:	00402025 */ 	or	$a0,$v0,$zero
/*  f02a948:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02a94c:	93a5017f */ 	lbu	$a1,0x17f($sp)
/*  f02a950:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02a954:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f02a958:	a06e0000 */ 	sb	$t6,0x0($v1)
/*  f02a95c:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f02a960:	a0790001 */ 	sb	$t9,0x1($v1)
/*  f02a964:	8fb800f8 */ 	lw	$t8,0xf8($sp)
/*  f02a968:	a0650003 */ 	sb	$a1,0x3($v1)
/*  f02a96c:	10000053 */ 	b	.L0f02aabc
/*  f02a970:	a0780002 */ 	sb	$t8,0x2($v1)
.L0f02a974:
/*  f02a974:	2401fffe */ 	addiu	$at,$zero,-2
/*  f02a978:	15010050 */ 	bne	$t0,$at,.L0f02aabc
/*  f02a97c:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f02a980:	8fa3020c */ 	lw	$v1,0x20c($sp)
/*  f02a984:	81e20011 */ 	lb	$v0,0x11($t7)
/*  f02a988:	8fae0208 */ 	lw	$t6,0x208($sp)
/*  f02a98c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f02a990:	0043082a */ 	slt	$at,$v0,$v1
/*  f02a994:	50200005 */ 	beqzl	$at,.L0f02a9ac
/*  f02a998:	448e9000 */ 	mtc1	$t6,$f18
/*  f02a99c:	44806000 */ 	mtc1	$zero,$f12
/*  f02a9a0:	10000021 */ 	b	.L0f02aa28
/*  f02a9a4:	46006086 */ 	mov.s	$f2,$f12
/*  f02a9a8:	448e9000 */ 	mtc1	$t6,$f18
.L0f02a9ac:
/*  f02a9ac:	3c0141f0 */ 	lui	$at,0x41f0
/*  f02a9b0:	44812000 */ 	mtc1	$at,$f4
/*  f02a9b4:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f02a9b8:	44825000 */ 	mtc1	$v0,$f10
/*  f02a9bc:	3c014080 */ 	lui	$at,0x4080
/*  f02a9c0:	44818000 */ 	mtc1	$at,$f16
/*  f02a9c4:	3c014220 */ 	lui	$at,0x4220
/*  f02a9c8:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f02a9cc:	44819000 */ 	mtc1	$at,$f18
/*  f02a9d0:	3c013f80 */ 	lui	$at,0x3f80
/*  f02a9d4:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02a9d8:	44806000 */ 	mtc1	$zero,$f12
/*  f02a9dc:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f02a9e0:	44834000 */ 	mtc1	$v1,$f8
/*  f02a9e4:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f02a9e8:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f02a9ec:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f02a9f0:	44815000 */ 	mtc1	$at,$f10
/*  f02a9f4:	3c017f1b */ 	lui	$at,%hi(var7f1a897c)
/*  f02a9f8:	46060401 */ 	sub.s	$f16,$f0,$f6
/*  f02a9fc:	44993000 */ 	mtc1	$t9,$f6
/*  f02aa00:	460a8480 */ 	add.s	$f18,$f16,$f10
/*  f02aa04:	c42a897c */ 	lwc1	$f10,%lo(var7f1a897c)($at)
/*  f02aa08:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f02aa0c:	46009203 */ 	div.s	$f8,$f18,$f0
/*  f02aa10:	46082082 */ 	mul.s	$f2,$f4,$f8
/*  f02aa14:	00000000 */ 	nop
/*  f02aa18:	460a8482 */ 	mul.s	$f18,$f16,$f10
/*  f02aa1c:	00000000 */ 	nop
/*  f02aa20:	46121082 */ 	mul.s	$f2,$f2,$f18
/*  f02aa24:	00000000 */ 	nop
.L0f02aa28:
/*  f02aa28:	3c01437f */ 	lui	$at,0x437f
/*  f02aa2c:	44810000 */ 	mtc1	$at,$f0
/*  f02aa30:	00000000 */ 	nop
/*  f02aa34:	4602003c */ 	c.lt.s	$f0,$f2
/*  f02aa38:	00000000 */ 	nop
/*  f02aa3c:	45020004 */ 	bc1fl	.L0f02aa50
/*  f02aa40:	460c103c */ 	c.lt.s	$f2,$f12
/*  f02aa44:	10000006 */ 	b	.L0f02aa60
/*  f02aa48:	46000086 */ 	mov.s	$f2,$f0
/*  f02aa4c:	460c103c */ 	c.lt.s	$f2,$f12
.L0f02aa50:
/*  f02aa50:	00000000 */ 	nop
/*  f02aa54:	45000002 */ 	bc1f	.L0f02aa60
/*  f02aa58:	00000000 */ 	nop
/*  f02aa5c:	46006086 */ 	mov.s	$f2,$f12
.L0f02aa60:
/*  f02aa60:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f02aa64:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f02aa68:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02aa6c:	3c0e0700 */ 	lui	$t6,0x700
/*  f02aa70:	35ce0004 */ 	ori	$t6,$t6,0x4
/*  f02aa74:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f02aa78:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02aa7c:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f02aa80:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02aa84:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f02aa88:	00402025 */ 	or	$a0,$v0,$zero
/*  f02aa8c:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02aa90:	c7a20094 */ 	lwc1	$f2,0x94($sp)
/*  f02aa94:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02aa98:	8fb900e8 */ 	lw	$t9,0xe8($sp)
/*  f02aa9c:	4600110d */ 	trunc.w.s	$f4,$f2
/*  f02aaa0:	a0790000 */ 	sb	$t9,0x0($v1)
/*  f02aaa4:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f02aaa8:	44192000 */ 	mfc1	$t9,$f4
/*  f02aaac:	a0780001 */ 	sb	$t8,0x1($v1)
/*  f02aab0:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f02aab4:	a0790003 */ 	sb	$t9,0x3($v1)
/*  f02aab8:	a06f0002 */ 	sb	$t7,0x2($v1)
.L0f02aabc:
/*  f02aabc:	02001825 */ 	or	$v1,$s0,$zero
/*  f02aac0:	27a20180 */ 	addiu	$v0,$sp,0x180
/*  f02aac4:	27a401b0 */ 	addiu	$a0,$sp,0x1b0
.L0f02aac8:
/*  f02aac8:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02aacc:	24420006 */ 	addiu	$v0,$v0,0x6
/*  f02aad0:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02aad4:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f02aad8:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f02aadc:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02aae0:	a86ffff8 */ 	swl	$t7,-0x8($v1)
/*  f02aae4:	b86ffffb */ 	swr	$t7,-0x5($v1)
/*  f02aae8:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02aaec:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02aaf0:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02aaf4:	844efffa */ 	lh	$t6,-0x6($v0)
/*  f02aaf8:	0044082b */ 	sltu	$at,$v0,$a0
/*  f02aafc:	a46efff4 */ 	sh	$t6,-0xc($v1)
/*  f02ab00:	8459fffc */ 	lh	$t9,-0x4($v0)
/*  f02ab04:	a479fff6 */ 	sh	$t9,-0xa($v1)
/*  f02ab08:	8458fffe */ 	lh	$t8,-0x2($v0)
/*  f02ab0c:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02ab10:	1420ffed */ 	bnez	$at,.L0f02aac8
/*  f02ab14:	a478fff8 */ 	sh	$t8,-0x8($v1)
/*  f02ab18:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02ab1c:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02ab20:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f02ab24:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02ab28:	a6140046 */ 	sh	$s4,0x46($s0)
/*  f02ab2c:	a6150038 */ 	sh	$s5,0x38($s0)
/*  f02ab30:	a614003a */ 	sh	$s4,0x3a($s0)
/*  f02ab34:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02ab38:	a613002e */ 	sh	$s3,0x2e($s0)
/*  f02ab3c:	a6130022 */ 	sh	$s3,0x22($s0)
/*  f02ab40:	a6140052 */ 	sh	$s4,0x52($s0)
/*  f02ab44:	a615005c */ 	sh	$s5,0x5c($s0)
/*  f02ab48:	a614005e */ 	sh	$s4,0x5e($s0)
/*  f02ab4c:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02ab50:	a60b0044 */ 	sh	$t3,0x44($s0)
/*  f02ab54:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02ab58:	a60b0050 */ 	sh	$t3,0x50($s0)
/*  f02ab5c:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02ab60:	02002025 */ 	or	$a0,$s0,$zero
/*  f02ab64:	aa010060 */ 	swl	$at,0x60($s0)
/*  f02ab68:	ba010063 */ 	swr	$at,0x63($s0)
/*  f02ab6c:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f02ab70:	aa0e0064 */ 	swl	$t6,0x64($s0)
/*  f02ab74:	ba0e0067 */ 	swr	$t6,0x67($s0)
/*  f02ab78:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02ab7c:	aa010068 */ 	swl	$at,0x68($s0)
/*  f02ab80:	ba01006b */ 	swr	$at,0x6b($s0)
/*  f02ab84:	87b9018c */ 	lh	$t9,0x18c($sp)
/*  f02ab88:	a6190060 */ 	sh	$t9,0x60($s0)
/*  f02ab8c:	87b8018e */ 	lh	$t8,0x18e($sp)
/*  f02ab90:	a6180062 */ 	sh	$t8,0x62($s0)
/*  f02ab94:	87af0190 */ 	lh	$t7,0x190($sp)
/*  f02ab98:	a2000067 */ 	sb	$zero,0x67($s0)
/*  f02ab9c:	a60f0064 */ 	sh	$t7,0x64($s0)
/*  f02aba0:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02aba4:	aa01006c */ 	swl	$at,0x6c($s0)
/*  f02aba8:	ba01006f */ 	swr	$at,0x6f($s0)
/*  f02abac:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02abb0:	aa190070 */ 	swl	$t9,0x70($s0)
/*  f02abb4:	ba190073 */ 	swr	$t9,0x73($s0)
/*  f02abb8:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02abbc:	aa010074 */ 	swl	$at,0x74($s0)
/*  f02abc0:	ba010077 */ 	swr	$at,0x77($s0)
/*  f02abc4:	87b80192 */ 	lh	$t8,0x192($sp)
/*  f02abc8:	a618006c */ 	sh	$t8,0x6c($s0)
/*  f02abcc:	87af0194 */ 	lh	$t7,0x194($sp)
/*  f02abd0:	a60f006e */ 	sh	$t7,0x6e($s0)
/*  f02abd4:	87ae0196 */ 	lh	$t6,0x196($sp)
/*  f02abd8:	a2000073 */ 	sb	$zero,0x73($s0)
/*  f02abdc:	a6150068 */ 	sh	$s5,0x68($s0)
/*  f02abe0:	a614006a */ 	sh	$s4,0x6a($s0)
/*  f02abe4:	a6140076 */ 	sh	$s4,0x76($s0)
/*  f02abe8:	a60b0074 */ 	sh	$t3,0x74($s0)
/*  f02abec:	a60e0070 */ 	sh	$t6,0x70($s0)
/*  f02abf0:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02abf4:	aa010078 */ 	swl	$at,0x78($s0)
/*  f02abf8:	ba01007b */ 	swr	$at,0x7b($s0)
/*  f02abfc:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f02ac00:	aa18007c */ 	swl	$t8,0x7c($s0)
/*  f02ac04:	ba18007f */ 	swr	$t8,0x7f($s0)
/*  f02ac08:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02ac0c:	aa010080 */ 	swl	$at,0x80($s0)
/*  f02ac10:	ba010083 */ 	swr	$at,0x83($s0)
/*  f02ac14:	87af01a4 */ 	lh	$t7,0x1a4($sp)
/*  f02ac18:	a60f0078 */ 	sh	$t7,0x78($s0)
/*  f02ac1c:	87ae01a6 */ 	lh	$t6,0x1a6($sp)
/*  f02ac20:	a60e007a */ 	sh	$t6,0x7a($s0)
/*  f02ac24:	87b901a8 */ 	lh	$t9,0x1a8($sp)
/*  f02ac28:	a200007f */ 	sb	$zero,0x7f($s0)
/*  f02ac2c:	a619007c */ 	sh	$t9,0x7c($s0)
/*  f02ac30:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02ac34:	aa010084 */ 	swl	$at,0x84($s0)
/*  f02ac38:	ba010087 */ 	swr	$at,0x87($s0)
/*  f02ac3c:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02ac40:	aa0f0088 */ 	swl	$t7,0x88($s0)
/*  f02ac44:	ba0f008b */ 	swr	$t7,0x8b($s0)
/*  f02ac48:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02ac4c:	aa01008c */ 	swl	$at,0x8c($s0)
/*  f02ac50:	ba01008f */ 	swr	$at,0x8f($s0)
/*  f02ac54:	87ae01aa */ 	lh	$t6,0x1aa($sp)
/*  f02ac58:	a60e0084 */ 	sh	$t6,0x84($s0)
/*  f02ac5c:	87b901ac */ 	lh	$t9,0x1ac($sp)
/*  f02ac60:	a6190086 */ 	sh	$t9,0x86($s0)
/*  f02ac64:	87b801ae */ 	lh	$t8,0x1ae($sp)
/*  f02ac68:	a200008b */ 	sb	$zero,0x8b($s0)
/*  f02ac6c:	a6150080 */ 	sh	$s5,0x80($s0)
/*  f02ac70:	a6130082 */ 	sh	$s3,0x82($s0)
/*  f02ac74:	a613008e */ 	sh	$s3,0x8e($s0)
/*  f02ac78:	a60b008c */ 	sh	$t3,0x8c($s0)
/*  f02ac7c:	a6180088 */ 	sh	$t8,0x88($s0)
/*  f02ac80:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02ac84:	3c1904b0 */ 	lui	$t9,0x4b0
/*  f02ac88:	37390090 */ 	ori	$t9,$t9,0x90
/*  f02ac8c:	262e0008 */ 	addiu	$t6,$s1,0x8
/*  f02ac90:	afae01f0 */ 	sw	$t6,0x1f0($sp)
/*  f02ac94:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f02ac98:	ae390000 */ 	sw	$t9,0x0($s1)
/*  f02ac9c:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02aca0:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02aca4:	3c0eb100 */ 	lui	$t6,0xb100
/*  f02aca8:	3c194b5b */ 	lui	$t9,0x4b5b
/*  f02acac:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02acb0:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02acb4:	37399010 */ 	ori	$t9,$t9,0x9010
/*  f02acb8:	35cea489 */ 	ori	$t6,$t6,0xa489
/*  f02acbc:	27a30124 */ 	addiu	$v1,$sp,0x124
/*  f02acc0:	27a60164 */ 	addiu	$a2,$sp,0x164
/*  f02acc4:	3c05b100 */ 	lui	$a1,0xb100
/*  f02acc8:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f02accc:	af190004 */ 	sw	$t9,0x4($t8)
.L0f02acd0:
/*  f02acd0:	8fa201f0 */ 	lw	$v0,0x1f0($sp)
/*  f02acd4:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f02acd8:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f02acdc:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02ace0:	8c6efff8 */ 	lw	$t6,-0x8($v1)
/*  f02ace4:	8c6ffffc */ 	lw	$t7,-0x4($v1)
/*  f02ace8:	31d9000f */ 	andi	$t9,$t6,0xf
/*  f02acec:	0325c025 */ 	or	$t8,$t9,$a1
/*  f02acf0:	31ee000f */ 	andi	$t6,$t7,0xf
/*  f02acf4:	000ec900 */ 	sll	$t9,$t6,0x4
/*  f02acf8:	03197825 */ 	or	$t7,$t8,$t9
/*  f02acfc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f02ad00:	8c78fff8 */ 	lw	$t8,-0x8($v1)
/*  f02ad04:	8c64fff0 */ 	lw	$a0,-0x10($v1)
/*  f02ad08:	3319000f */ 	andi	$t9,$t8,0xf
/*  f02ad0c:	308e000f */ 	andi	$t6,$a0,0xf
/*  f02ad10:	01c02025 */ 	or	$a0,$t6,$zero
/*  f02ad14:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f02ad18:	01cf7025 */ 	or	$t6,$t6,$t7
/*  f02ad1c:	8c6ffff4 */ 	lw	$t7,-0xc($v1)
/*  f02ad20:	0004c200 */ 	sll	$t8,$a0,0x8
/*  f02ad24:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f02ad28:	31ee000f */ 	andi	$t6,$t7,0xf
/*  f02ad2c:	000ec100 */ 	sll	$t8,$t6,0x4
/*  f02ad30:	03387825 */ 	or	$t7,$t9,$t8
/*  f02ad34:	1466ffe6 */ 	bne	$v1,$a2,.L0f02acd0
/*  f02ad38:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f02ad3c:	1000029c */ 	b	.L0f02b7b0
/*  f02ad40:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f02ad44:
/*  f02ad44:	91c40000 */ 	lbu	$a0,0x0($t6)
/*  f02ad48:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02ad4c:	10810005 */ 	beq	$a0,$at,.L0f02ad64
/*  f02ad50:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f02ad54:	11240003 */ 	beq	$t1,$a0,.L0f02ad64
/*  f02ad58:	24010002 */ 	addiu	$at,$zero,0x2
/*  f02ad5c:	5481000b */ 	bnel	$a0,$at,.L0f02ad8c
/*  f02ad60:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
.L0f02ad64:
/*  f02ad64:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
/*  f02ad68:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f02ad6c:	8f380004 */ 	lw	$t8,0x4($t9)
/*  f02ad70:	8f0f0010 */ 	lw	$t7,0x10($t8)
/*  f02ad74:	31ee1000 */ 	andi	$t6,$t7,0x1000
/*  f02ad78:	51c00004 */ 	beqzl	$t6,.L0f02ad8c
/*  f02ad7c:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
/*  f02ad80:	10000023 */ 	b	.L0f02ae10
/*  f02ad84:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f02ad88:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
.L0f02ad8c:
/*  f02ad8c:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x8)
/*  f02ad90:	8c429fc8 */ 	lw	$v0,%lo(g_Vars+0x8)($v0)
/*  f02ad94:	8f23000c */ 	lw	$v1,0xc($t9)
/*  f02ad98:	00002825 */ 	or	$a1,$zero,$zero
/*  f02ad9c:	00003025 */ 	or	$a2,$zero,$zero
/*  f02ada0:	0043c023 */ 	subu	$t8,$v0,$v1
/*  f02ada4:	2b010051 */ 	slti	$at,$t8,0x51
/*  f02ada8:	10200019 */ 	beqz	$at,.L0f02ae10
/*  f02adac:	00627823 */ 	subu	$t7,$v1,$v0
/*  f02adb0:	25ee0050 */ 	addiu	$t6,$t7,0x50
/*  f02adb4:	448e4000 */ 	mtc1	$t6,$f8
/*  f02adb8:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f02adbc:	3c01404c */ 	lui	$at,0x404c
/*  f02adc0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f02adc4:	44995000 */ 	mtc1	$t9,$f10
/*  f02adc8:	44818000 */ 	mtc1	$at,$f16
/*  f02adcc:	3c017f1b */ 	lui	$at,%hi(var7f1a8980)
/*  f02add0:	c4248980 */ 	lwc1	$f4,%lo(var7f1a8980)($at)
/*  f02add4:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f02add8:	46103302 */ 	mul.s	$f12,$f6,$f16
/*  f02addc:	00000000 */ 	nop
/*  f02ade0:	46049082 */ 	mul.s	$f2,$f18,$f4
/*  f02ade4:	00000000 */ 	nop
/*  f02ade8:	46026002 */ 	mul.s	$f0,$f12,$f2
/*  f02adec:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f02adf0:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f02adf4:	44054000 */ 	mfc1	$a1,$f8
/*  f02adf8:	44063000 */ 	mfc1	$a2,$f6
/*  f02adfc:	30af00ff */ 	andi	$t7,$a1,0xff
/*  f02ae00:	01e02825 */ 	or	$a1,$t7,$zero
/*  f02ae04:	30d900ff */ 	andi	$t9,$a2,0xff
/*  f02ae08:	10000001 */ 	b	.L0f02ae10
/*  f02ae0c:	03203025 */ 	or	$a2,$t9,$zero
.L0f02ae10:
/*  f02ae10:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f02ae14:	a3a5017f */ 	sb	$a1,0x17f($sp)
/*  f02ae18:	a3a6017e */ 	sb	$a2,0x17e($sp)
/*  f02ae1c:	afa700f4 */ 	sw	$a3,0xf4($sp)
/*  f02ae20:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f02ae24:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f02ae28:	afab00ec */ 	sw	$t3,0xec($sp)
/*  f02ae2c:	8fb001f0 */ 	lw	$s0,0x1f0($sp)
/*  f02ae30:	3c0e0710 */ 	lui	$t6,0x710
/*  f02ae34:	35ce0014 */ 	ori	$t6,$t6,0x14
/*  f02ae38:	260f0008 */ 	addiu	$t7,$s0,0x8
/*  f02ae3c:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02ae40:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f02ae44:	afa201d8 */ 	sw	$v0,0x1d8($sp)
/*  f02ae48:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f02ae4c:	00402025 */ 	or	$a0,$v0,$zero
/*  f02ae50:	8fa301d8 */ 	lw	$v1,0x1d8($sp)
/*  f02ae54:	93a5017f */ 	lbu	$a1,0x17f($sp)
/*  f02ae58:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f02ae5c:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f02ae60:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f02ae64:	93a6017e */ 	lbu	$a2,0x17e($sp)
/*  f02ae68:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f02ae6c:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f02ae70:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f02ae74:	a0790000 */ 	sb	$t9,0x0($v1)
/*  f02ae78:	8fb800fc */ 	lw	$t8,0xfc($sp)
/*  f02ae7c:	a0780001 */ 	sb	$t8,0x1($v1)
/*  f02ae80:	8faf00f8 */ 	lw	$t7,0xf8($sp)
/*  f02ae84:	a0650003 */ 	sb	$a1,0x3($v1)
/*  f02ae88:	a0650007 */ 	sb	$a1,0x7($v1)
/*  f02ae8c:	a065000b */ 	sb	$a1,0xb($v1)
/*  f02ae90:	a0670004 */ 	sb	$a3,0x4($v1)
/*  f02ae94:	a0670008 */ 	sb	$a3,0x8($v1)
/*  f02ae98:	a06a0005 */ 	sb	$t2,0x5($v1)
/*  f02ae9c:	a06a0009 */ 	sb	$t2,0x9($v1)
/*  f02aea0:	a06b0006 */ 	sb	$t3,0x6($v1)
/*  f02aea4:	a06b000a */ 	sb	$t3,0xa($v1)
/*  f02aea8:	a06f0002 */ 	sb	$t7,0x2($v1)
/*  f02aeac:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f02aeb0:	24e70046 */ 	addiu	$a3,$a3,0x46
/*  f02aeb4:	254a0046 */ 	addiu	$t2,$t2,0x46
/*  f02aeb8:	25d90064 */ 	addiu	$t9,$t6,0x64
/*  f02aebc:	2b210100 */ 	slti	$at,$t9,0x100
/*  f02aec0:	14200003 */ 	bnez	$at,.L0f02aed0
/*  f02aec4:	afb90100 */ 	sw	$t9,0x100($sp)
/*  f02aec8:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f02aecc:	afac0100 */ 	sw	$t4,0x100($sp)
.L0f02aed0:
/*  f02aed0:	8fb80100 */ 	lw	$t8,0x100($sp)
/*  f02aed4:	256b0046 */ 	addiu	$t3,$t3,0x46
/*  f02aed8:	a078000c */ 	sb	$t8,0xc($v1)
/*  f02aedc:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f02aee0:	25ee0064 */ 	addiu	$t6,$t7,0x64
/*  f02aee4:	29c10100 */ 	slti	$at,$t6,0x100
/*  f02aee8:	14200003 */ 	bnez	$at,.L0f02aef8
/*  f02aeec:	afae00fc */ 	sw	$t6,0xfc($sp)
/*  f02aef0:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f02aef4:	afad00fc */ 	sw	$t5,0xfc($sp)
.L0f02aef8:
/*  f02aef8:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f02aefc:	a079000d */ 	sb	$t9,0xd($v1)
/*  f02af00:	8fb800f8 */ 	lw	$t8,0xf8($sp)
/*  f02af04:	270f0064 */ 	addiu	$t7,$t8,0x64
/*  f02af08:	29e10100 */ 	slti	$at,$t7,0x100
/*  f02af0c:	14200003 */ 	bnez	$at,.L0f02af1c
/*  f02af10:	afaf00f8 */ 	sw	$t7,0xf8($sp)
/*  f02af14:	241f00ff */ 	addiu	$ra,$zero,0xff
/*  f02af18:	afbf00f8 */ 	sw	$ra,0xf8($sp)
.L0f02af1c:
/*  f02af1c:	8fae00f8 */ 	lw	$t6,0xf8($sp)
/*  f02af20:	28e10100 */ 	slti	$at,$a3,0x100
/*  f02af24:	a066000f */ 	sb	$a2,0xf($v1)
/*  f02af28:	14200002 */ 	bnez	$at,.L0f02af34
/*  f02af2c:	a06e000e */ 	sb	$t6,0xe($v1)
/*  f02af30:	240700ff */ 	addiu	$a3,$zero,0xff
.L0f02af34:
/*  f02af34:	29410100 */ 	slti	$at,$t2,0x100
/*  f02af38:	14200002 */ 	bnez	$at,.L0f02af44
/*  f02af3c:	a0670010 */ 	sb	$a3,0x10($v1)
/*  f02af40:	240a00ff */ 	addiu	$t2,$zero,0xff
.L0f02af44:
/*  f02af44:	29610100 */ 	slti	$at,$t3,0x100
/*  f02af48:	14200002 */ 	bnez	$at,.L0f02af54
/*  f02af4c:	a06a0011 */ 	sb	$t2,0x11($v1)
/*  f02af50:	240b00ff */ 	addiu	$t3,$zero,0xff
.L0f02af54:
/*  f02af54:	a06b0012 */ 	sb	$t3,0x12($v1)
/*  f02af58:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f02af5c:	a0650013 */ 	sb	$a1,0x13($v1)
/*  f02af60:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02af64:	27b80104 */ 	addiu	$t8,$sp,0x104
/*  f02af68:	00408025 */ 	or	$s0,$v0,$zero
/*  f02af6c:	0008c900 */ 	sll	$t9,$t0,0x4
/*  f02af70:	03382821 */ 	addu	$a1,$t9,$t8
/*  f02af74:	00a03825 */ 	or	$a3,$a1,$zero
/*  f02af78:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f02af7c:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02af80:	00002025 */ 	or	$a0,$zero,$zero
/*  f02af84:	00401825 */ 	or	$v1,$v0,$zero
.L0f02af88:
/*  f02af88:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02af8c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f02af90:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f02af94:	a8610000 */ 	swl	$at,0x0($v1)
/*  f02af98:	b8610003 */ 	swr	$at,0x3($v1)
/*  f02af9c:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02afa0:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02afa4:	a879fff8 */ 	swl	$t9,-0x8($v1)
/*  f02afa8:	b879fffb */ 	swr	$t9,-0x5($v1)
/*  f02afac:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02afb0:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f02afb4:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f02afb8:	8cf8fffc */ 	lw	$t8,-0x4($a3)
/*  f02afbc:	28810004 */ 	slti	$at,$a0,0x4
/*  f02afc0:	03110019 */ 	multu	$t8,$s1
/*  f02afc4:	00007012 */ 	mflo	$t6
/*  f02afc8:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f02afcc:	85f90000 */ 	lh	$t9,0x0($t7)
/*  f02afd0:	a479fff4 */ 	sh	$t9,-0xc($v1)
/*  f02afd4:	8cf8fffc */ 	lw	$t8,-0x4($a3)
/*  f02afd8:	03110019 */ 	multu	$t8,$s1
/*  f02afdc:	00007012 */ 	mflo	$t6
/*  f02afe0:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f02afe4:	85f90002 */ 	lh	$t9,0x2($t7)
/*  f02afe8:	a479fff6 */ 	sh	$t9,-0xa($v1)
/*  f02afec:	8cf8fffc */ 	lw	$t8,-0x4($a3)
/*  f02aff0:	03110019 */ 	multu	$t8,$s1
/*  f02aff4:	00007012 */ 	mflo	$t6
/*  f02aff8:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f02affc:	85f90004 */ 	lh	$t9,0x4($t7)
/*  f02b000:	a060fffb */ 	sb	$zero,-0x5($v1)
/*  f02b004:	1420ffe0 */ 	bnez	$at,.L0f02af88
/*  f02b008:	a479fff8 */ 	sh	$t9,-0x8($v1)
/*  f02b00c:	8fa401f4 */ 	lw	$a0,0x1f4($sp)
/*  f02b010:	a4550008 */ 	sh	$s5,0x8($v0)
/*  f02b014:	a453000a */ 	sh	$s3,0xa($v0)
/*  f02b018:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f02b01c:	a4530016 */ 	sh	$s3,0x16($v0)
/*  f02b020:	a4540022 */ 	sh	$s4,0x22($v0)
/*  f02b024:	a455002c */ 	sh	$s5,0x2c($v0)
/*  f02b028:	a454002e */ 	sh	$s4,0x2e($v0)
/*  f02b02c:	a44b0014 */ 	sh	$t3,0x14($v0)
/*  f02b030:	a44b0020 */ 	sh	$t3,0x20($v0)
/*  f02b034:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b038:	a8410030 */ 	swl	$at,0x30($v0)
/*  f02b03c:	b8410033 */ 	swr	$at,0x33($v0)
/*  f02b040:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f02b044:	a84e0034 */ 	swl	$t6,0x34($v0)
/*  f02b048:	b84e0037 */ 	swr	$t6,0x37($v0)
/*  f02b04c:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b050:	a8410038 */ 	swl	$at,0x38($v0)
/*  f02b054:	b841003b */ 	swr	$at,0x3b($v0)
/*  f02b058:	84830012 */ 	lh	$v1,0x12($a0)
/*  f02b05c:	24017fff */ 	addiu	$at,$zero,0x7fff
/*  f02b060:	5461001e */ 	bnel	$v1,$at,.L0f02b0dc
/*  f02b064:	a4430030 */ 	sh	$v1,0x30($v0)
/*  f02b068:	844f0024 */ 	lh	$t7,0x24($v0)
/*  f02b06c:	84590000 */ 	lh	$t9,0x0($v0)
/*  f02b070:	844e000c */ 	lh	$t6,0xc($v0)
/*  f02b074:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b078:	84590018 */ 	lh	$t9,0x18($v0)
/*  f02b07c:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f02b080:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b084:	84590002 */ 	lh	$t9,0x2($v0)
/*  f02b088:	844f0026 */ 	lh	$t7,0x26($v0)
/*  f02b08c:	00187083 */ 	sra	$t6,$t8,0x2
/*  f02b090:	a44e0030 */ 	sh	$t6,0x30($v0)
/*  f02b094:	844e000e */ 	lh	$t6,0xe($v0)
/*  f02b098:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b09c:	8459001a */ 	lh	$t9,0x1a($v0)
/*  f02b0a0:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f02b0a4:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b0a8:	84590004 */ 	lh	$t9,0x4($v0)
/*  f02b0ac:	844f0028 */ 	lh	$t7,0x28($v0)
/*  f02b0b0:	00187083 */ 	sra	$t6,$t8,0x2
/*  f02b0b4:	a44e0032 */ 	sh	$t6,0x32($v0)
/*  f02b0b8:	844e0010 */ 	lh	$t6,0x10($v0)
/*  f02b0bc:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b0c0:	8459001c */ 	lh	$t9,0x1c($v0)
/*  f02b0c4:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f02b0c8:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f02b0cc:	00187083 */ 	sra	$t6,$t8,0x2
/*  f02b0d0:	10000006 */ 	b	.L0f02b0ec
/*  f02b0d4:	a44e0034 */ 	sh	$t6,0x34($v0)
/*  f02b0d8:	a4430030 */ 	sh	$v1,0x30($v0)
.L0f02b0dc:
/*  f02b0dc:	848f0014 */ 	lh	$t7,0x14($a0)
/*  f02b0e0:	a44f0032 */ 	sh	$t7,0x32($v0)
/*  f02b0e4:	84990016 */ 	lh	$t9,0x16($a0)
/*  f02b0e8:	a4590034 */ 	sh	$t9,0x34($v0)
.L0f02b0ec:
/*  f02b0ec:	02ab1821 */ 	addu	$v1,$s5,$t3
/*  f02b0f0:	02741021 */ 	addu	$v0,$s3,$s4
/*  f02b0f4:	2418000c */ 	addiu	$t8,$zero,0xc
/*  f02b0f8:	00037043 */ 	sra	$t6,$v1,0x1
/*  f02b0fc:	00027843 */ 	sra	$t7,$v0,0x1
/*  f02b100:	a2180037 */ 	sb	$t8,0x37($s0)
/*  f02b104:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02b108:	a60f003a */ 	sh	$t7,0x3a($s0)
/*  f02b10c:	8fb901f0 */ 	lw	$t9,0x1f0($sp)
/*  f02b110:	01c01825 */ 	or	$v1,$t6,$zero
/*  f02b114:	3c0e0440 */ 	lui	$t6,0x440
/*  f02b118:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f02b11c:	afb801f0 */ 	sw	$t8,0x1f0($sp)
/*  f02b120:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02b124:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f02b128:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f02b12c:	afa30040 */ 	sw	$v1,0x40($sp)
/*  f02b130:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f02b134:	02002025 */ 	or	$a0,$s0,$zero
/*  f02b138:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f02b13c:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f02b140:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f02b144:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02b148:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f02b14c:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f02b150:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f02b154:	3c18b100 */ 	lui	$t8,0xb100
/*  f02b158:	3c0e0332 */ 	lui	$t6,0x332
/*  f02b15c:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f02b160:	afb901f0 */ 	sw	$t9,0x1f0($sp)
/*  f02b164:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02b168:	37184444 */ 	ori	$t8,$t8,0x4444
/*  f02b16c:	adf80000 */ 	sw	$t8,0x0($t7)
/*  f02b170:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f02b174:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02b178:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f02b17c:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f02b180:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f02b184:	00002025 */ 	or	$a0,$zero,$zero
/*  f02b188:	241f0005 */ 	addiu	$ra,$zero,0x5
/*  f02b18c:	240d0008 */ 	addiu	$t5,$zero,0x8
/*  f02b190:	240c0004 */ 	addiu	$t4,$zero,0x4
.L0f02b194:
/*  f02b194:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b198:	248a0001 */ 	addiu	$t2,$a0,0x1
/*  f02b19c:	aa010000 */ 	swl	$at,0x0($s0)
/*  f02b1a0:	ba010003 */ 	swr	$at,0x3($s0)
/*  f02b1a4:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f02b1a8:	aa190004 */ 	swl	$t9,0x4($s0)
/*  f02b1ac:	ba190007 */ 	swr	$t9,0x7($s0)
/*  f02b1b0:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b1b4:	aa010008 */ 	swl	$at,0x8($s0)
/*  f02b1b8:	ba01000b */ 	swr	$at,0xb($s0)
/*  f02b1bc:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f02b1c0:	05410004 */ 	bgez	$t2,.L0f02b1d4
/*  f02b1c4:	314e0003 */ 	andi	$t6,$t2,0x3
/*  f02b1c8:	11c00002 */ 	beqz	$t6,.L0f02b1d4
/*  f02b1cc:	00000000 */ 	nop
/*  f02b1d0:	25cefffc */ 	addiu	$t6,$t6,-4
.L0f02b1d4:
/*  f02b1d4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f02b1d8:	030f1021 */ 	addu	$v0,$t8,$t7
/*  f02b1dc:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b1e0:	03310019 */ 	multu	$t9,$s1
/*  f02b1e4:	00007012 */ 	mflo	$t6
/*  f02b1e8:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b1ec:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b1f0:	a60f0000 */ 	sh	$t7,0x0($s0)
/*  f02b1f4:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b1f8:	03310019 */ 	multu	$t9,$s1
/*  f02b1fc:	00007012 */ 	mflo	$t6
/*  f02b200:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b204:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b208:	a60f0002 */ 	sh	$t7,0x2($s0)
/*  f02b20c:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b210:	03310019 */ 	multu	$t9,$s1
/*  f02b214:	00007012 */ 	mflo	$t6
/*  f02b218:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b21c:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b220:	a20c0007 */ 	sb	$t4,0x7($s0)
/*  f02b224:	a60f0004 */ 	sh	$t7,0x4($s0)
/*  f02b228:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b22c:	aa01000c */ 	swl	$at,0xc($s0)
/*  f02b230:	ba01000f */ 	swr	$at,0xf($s0)
/*  f02b234:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f02b238:	aa0e0010 */ 	swl	$t6,0x10($s0)
/*  f02b23c:	ba0e0013 */ 	swr	$t6,0x13($s0)
/*  f02b240:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b244:	aa010014 */ 	swl	$at,0x14($s0)
/*  f02b248:	ba010017 */ 	swr	$at,0x17($s0)
/*  f02b24c:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f02b250:	03110019 */ 	multu	$t8,$s1
/*  f02b254:	00007812 */ 	mflo	$t7
/*  f02b258:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02b25c:	872e0000 */ 	lh	$t6,0x0($t9)
/*  f02b260:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f02b264:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f02b268:	03110019 */ 	multu	$t8,$s1
/*  f02b26c:	00007812 */ 	mflo	$t7
/*  f02b270:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02b274:	872e0002 */ 	lh	$t6,0x2($t9)
/*  f02b278:	a60e000e */ 	sh	$t6,0xe($s0)
/*  f02b27c:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f02b280:	03110019 */ 	multu	$t8,$s1
/*  f02b284:	00007812 */ 	mflo	$t7
/*  f02b288:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f02b28c:	872e0004 */ 	lh	$t6,0x4($t9)
/*  f02b290:	a20c0013 */ 	sb	$t4,0x13($s0)
/*  f02b294:	a60e0010 */ 	sh	$t6,0x10($s0)
/*  f02b298:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b29c:	aa010018 */ 	swl	$at,0x18($s0)
/*  f02b2a0:	ba01001b */ 	swr	$at,0x1b($s0)
/*  f02b2a4:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b2a8:	aa0f001c */ 	swl	$t7,0x1c($s0)
/*  f02b2ac:	ba0f001f */ 	swr	$t7,0x1f($s0)
/*  f02b2b0:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b2b4:	aa010020 */ 	swl	$at,0x20($s0)
/*  f02b2b8:	ba010023 */ 	swr	$at,0x23($s0)
/*  f02b2bc:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f02b2c0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02b2c4:	03310019 */ 	multu	$t9,$s1
/*  f02b2c8:	00007012 */ 	mflo	$t6
/*  f02b2cc:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b2d0:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b2d4:	a60f0018 */ 	sh	$t7,0x18($s0)
/*  f02b2d8:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f02b2dc:	03310019 */ 	multu	$t9,$s1
/*  f02b2e0:	00007012 */ 	mflo	$t6
/*  f02b2e4:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b2e8:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b2ec:	a60f001a */ 	sh	$t7,0x1a($s0)
/*  f02b2f0:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f02b2f4:	03310019 */ 	multu	$t9,$s1
/*  f02b2f8:	00007012 */ 	mflo	$t6
/*  f02b2fc:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b300:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b304:	a20d001f */ 	sb	$t5,0x1f($s0)
/*  f02b308:	15000004 */ 	bnez	$t0,.L0f02b31c
/*  f02b30c:	a60f001c */ 	sh	$t7,0x1c($s0)
/*  f02b310:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f02b314:	10000016 */ 	b	.L0f02b370
/*  f02b318:	a6190018 */ 	sh	$t9,0x18($s0)
.L0f02b31c:
/*  f02b31c:	15010003 */ 	bne	$t0,$at,.L0f02b32c
/*  f02b320:	8fae01cc */ 	lw	$t6,0x1cc($sp)
/*  f02b324:	10000012 */ 	b	.L0f02b370
/*  f02b328:	a60e0018 */ 	sh	$t6,0x18($s0)
.L0f02b32c:
/*  f02b32c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f02b330:	15010003 */ 	bne	$t0,$at,.L0f02b340
/*  f02b334:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f02b338:	1000000d */ 	b	.L0f02b370
/*  f02b33c:	a618001a */ 	sh	$t8,0x1a($s0)
.L0f02b340:
/*  f02b340:	24010003 */ 	addiu	$at,$zero,0x3
/*  f02b344:	15010003 */ 	bne	$t0,$at,.L0f02b354
/*  f02b348:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f02b34c:	10000008 */ 	b	.L0f02b370
/*  f02b350:	a60f001a */ 	sh	$t7,0x1a($s0)
.L0f02b354:
/*  f02b354:	15090003 */ 	bne	$t0,$t1,.L0f02b364
/*  f02b358:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f02b35c:	10000004 */ 	b	.L0f02b370
/*  f02b360:	a619001c */ 	sh	$t9,0x1c($s0)
.L0f02b364:
/*  f02b364:	151f0002 */ 	bne	$t0,$ra,.L0f02b370
/*  f02b368:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f02b36c:	a60e001c */ 	sh	$t6,0x1c($s0)
.L0f02b370:
/*  f02b370:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b374:	aa010024 */ 	swl	$at,0x24($s0)
/*  f02b378:	ba010027 */ 	swr	$at,0x27($s0)
/*  f02b37c:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b380:	aa0f0028 */ 	swl	$t7,0x28($s0)
/*  f02b384:	ba0f002b */ 	swr	$t7,0x2b($s0)
/*  f02b388:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b38c:	aa01002c */ 	swl	$at,0x2c($s0)
/*  f02b390:	ba01002f */ 	swr	$at,0x2f($s0)
/*  f02b394:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b398:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02b39c:	03310019 */ 	multu	$t9,$s1
/*  f02b3a0:	00007012 */ 	mflo	$t6
/*  f02b3a4:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b3a8:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b3ac:	a60f0024 */ 	sh	$t7,0x24($s0)
/*  f02b3b0:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b3b4:	03310019 */ 	multu	$t9,$s1
/*  f02b3b8:	00007012 */ 	mflo	$t6
/*  f02b3bc:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b3c0:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b3c4:	a60f0026 */ 	sh	$t7,0x26($s0)
/*  f02b3c8:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f02b3cc:	03310019 */ 	multu	$t9,$s1
/*  f02b3d0:	00007012 */ 	mflo	$t6
/*  f02b3d4:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b3d8:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b3dc:	a20d002b */ 	sb	$t5,0x2b($s0)
/*  f02b3e0:	15000004 */ 	bnez	$t0,.L0f02b3f4
/*  f02b3e4:	a60f0028 */ 	sh	$t7,0x28($s0)
/*  f02b3e8:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f02b3ec:	10000016 */ 	b	.L0f02b448
/*  f02b3f0:	a6190024 */ 	sh	$t9,0x24($s0)
.L0f02b3f4:
/*  f02b3f4:	15010003 */ 	bne	$t0,$at,.L0f02b404
/*  f02b3f8:	8fae01cc */ 	lw	$t6,0x1cc($sp)
/*  f02b3fc:	10000012 */ 	b	.L0f02b448
/*  f02b400:	a60e0024 */ 	sh	$t6,0x24($s0)
.L0f02b404:
/*  f02b404:	24010002 */ 	addiu	$at,$zero,0x2
/*  f02b408:	15010003 */ 	bne	$t0,$at,.L0f02b418
/*  f02b40c:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f02b410:	1000000d */ 	b	.L0f02b448
/*  f02b414:	a6180026 */ 	sh	$t8,0x26($s0)
.L0f02b418:
/*  f02b418:	24010003 */ 	addiu	$at,$zero,0x3
/*  f02b41c:	15010003 */ 	bne	$t0,$at,.L0f02b42c
/*  f02b420:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f02b424:	10000008 */ 	b	.L0f02b448
/*  f02b428:	a60f0026 */ 	sh	$t7,0x26($s0)
.L0f02b42c:
/*  f02b42c:	15090003 */ 	bne	$t0,$t1,.L0f02b43c
/*  f02b430:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f02b434:	10000004 */ 	b	.L0f02b448
/*  f02b438:	a6190028 */ 	sh	$t9,0x28($s0)
.L0f02b43c:
/*  f02b43c:	151f0002 */ 	bne	$t0,$ra,.L0f02b448
/*  f02b440:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f02b444:	a60e0028 */ 	sh	$t6,0x28($s0)
.L0f02b448:
/*  f02b448:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02b44c:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02b450:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02b454:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02b458:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02b45c:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02b460:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02b464:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02b468:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b46c:	86190024 */ 	lh	$t9,0x24($s0)
/*  f02b470:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f02b474:	aa010030 */ 	swl	$at,0x30($s0)
/*  f02b478:	ba010033 */ 	swr	$at,0x33($s0)
/*  f02b47c:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b480:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b484:	860e0018 */ 	lh	$t6,0x18($s0)
/*  f02b488:	aa0f0034 */ 	swl	$t7,0x34($s0)
/*  f02b48c:	ba0f0037 */ 	swr	$t7,0x37($s0)
/*  f02b490:	860f000c */ 	lh	$t7,0xc($s0)
/*  f02b494:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b498:	02002025 */ 	or	$a0,$s0,$zero
/*  f02b49c:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b4a0:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b4a4:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f02b4a8:	86190026 */ 	lh	$t9,0x26($s0)
/*  f02b4ac:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b4b0:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f02b4b4:	860f000e */ 	lh	$t7,0xe($s0)
/*  f02b4b8:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b4bc:	860e001a */ 	lh	$t6,0x1a($s0)
/*  f02b4c0:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b4c4:	aa010038 */ 	swl	$at,0x38($s0)
/*  f02b4c8:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b4cc:	860e0004 */ 	lh	$t6,0x4($s0)
/*  f02b4d0:	86190028 */ 	lh	$t9,0x28($s0)
/*  f02b4d4:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b4d8:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f02b4dc:	860f0010 */ 	lh	$t7,0x10($s0)
/*  f02b4e0:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b4e4:	860e001c */ 	lh	$t6,0x1c($s0)
/*  f02b4e8:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b4ec:	ba01003b */ 	swr	$at,0x3b($s0)
/*  f02b4f0:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b4f4:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b4f8:	24190010 */ 	addiu	$t9,$zero,0x10
/*  f02b4fc:	a60f0034 */ 	sh	$t7,0x34($s0)
/*  f02b500:	a2190037 */ 	sb	$t9,0x37($s0)
/*  f02b504:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f02b508:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02b50c:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f02b510:	3c0e0440 */ 	lui	$t6,0x440
/*  f02b514:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02b518:	a618003a */ 	sh	$t8,0x3a($s0)
/*  f02b51c:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f02b520:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f02b524:	afb901f0 */ 	sw	$t9,0x1f0($sp)
/*  f02b528:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f02b52c:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f02b530:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f02b534:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f02b538:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f02b53c:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f02b540:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f02b544:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f02b548:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f02b54c:	8fa80204 */ 	lw	$t0,0x204($sp)
/*  f02b550:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f02b554:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f02b558:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02b55c:	3c19b100 */ 	lui	$t9,0xb100
/*  f02b560:	3c0e0332 */ 	lui	$t6,0x332
/*  f02b564:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02b568:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02b56c:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02b570:	37394444 */ 	ori	$t9,$t9,0x4444
/*  f02b574:	28810004 */ 	slti	$at,$a0,0x4
/*  f02b578:	27a50180 */ 	addiu	$a1,$sp,0x180
/*  f02b57c:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f02b580:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f02b584:	240d0008 */ 	addiu	$t5,$zero,0x8
/*  f02b588:	241f0005 */ 	addiu	$ra,$zero,0x5
/*  f02b58c:	2610003c */ 	addiu	$s0,$s0,0x3c
/*  f02b590:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f02b594:	af190000 */ 	sw	$t9,0x0($t8)
/*  f02b598:	1420fefe */ 	bnez	$at,.L0f02b194
/*  f02b59c:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f02b5a0:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f02b5a4:	02001825 */ 	or	$v1,$s0,$zero
/*  f02b5a8:	00003025 */ 	or	$a2,$zero,$zero
/*  f02b5ac:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f02b5b0:	2442000c */ 	addiu	$v0,$v0,12
.L0f02b5b4:
/*  f02b5b4:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b5b8:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f02b5bc:	2442fffc */ 	addiu	$v0,$v0,-4
/*  f02b5c0:	a8610000 */ 	swl	$at,0x0($v1)
/*  f02b5c4:	b8610003 */ 	swr	$at,0x3($v1)
/*  f02b5c8:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b5cc:	a86f0004 */ 	swl	$t7,0x4($v1)
/*  f02b5d0:	b86f0007 */ 	swr	$t7,0x7($v1)
/*  f02b5d4:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b5d8:	a8610008 */ 	swl	$at,0x8($v1)
/*  f02b5dc:	b861000b */ 	swr	$at,0xb($v1)
/*  f02b5e0:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f02b5e4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02b5e8:	03310019 */ 	multu	$t9,$s1
/*  f02b5ec:	00007012 */ 	mflo	$t6
/*  f02b5f0:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b5f4:	870f0000 */ 	lh	$t7,0x0($t8)
/*  f02b5f8:	a46f0000 */ 	sh	$t7,0x0($v1)
/*  f02b5fc:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f02b600:	03310019 */ 	multu	$t9,$s1
/*  f02b604:	00007012 */ 	mflo	$t6
/*  f02b608:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b60c:	870f0002 */ 	lh	$t7,0x2($t8)
/*  f02b610:	a46f0002 */ 	sh	$t7,0x2($v1)
/*  f02b614:	8c590004 */ 	lw	$t9,0x4($v0)
/*  f02b618:	03310019 */ 	multu	$t9,$s1
/*  f02b61c:	00007012 */ 	mflo	$t6
/*  f02b620:	00aec021 */ 	addu	$t8,$a1,$t6
/*  f02b624:	870f0004 */ 	lh	$t7,0x4($t8)
/*  f02b628:	a06d0007 */ 	sb	$t5,0x7($v1)
/*  f02b62c:	15000004 */ 	bnez	$t0,.L0f02b640
/*  f02b630:	a46f0004 */ 	sh	$t7,0x4($v1)
/*  f02b634:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f02b638:	10000016 */ 	b	.L0f02b694
/*  f02b63c:	a4790000 */ 	sh	$t9,0x0($v1)
.L0f02b640:
/*  f02b640:	15010003 */ 	bne	$t0,$at,.L0f02b650
/*  f02b644:	8fae01cc */ 	lw	$t6,0x1cc($sp)
/*  f02b648:	10000012 */ 	b	.L0f02b694
/*  f02b64c:	a46e0000 */ 	sh	$t6,0x0($v1)
.L0f02b650:
/*  f02b650:	24010002 */ 	addiu	$at,$zero,0x2
/*  f02b654:	15010003 */ 	bne	$t0,$at,.L0f02b664
/*  f02b658:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f02b65c:	1000000d */ 	b	.L0f02b694
/*  f02b660:	a4780002 */ 	sh	$t8,0x2($v1)
.L0f02b664:
/*  f02b664:	24010003 */ 	addiu	$at,$zero,0x3
/*  f02b668:	15010003 */ 	bne	$t0,$at,.L0f02b678
/*  f02b66c:	8faf01c4 */ 	lw	$t7,0x1c4($sp)
/*  f02b670:	10000008 */ 	b	.L0f02b694
/*  f02b674:	a46f0002 */ 	sh	$t7,0x2($v1)
.L0f02b678:
/*  f02b678:	15090003 */ 	bne	$t0,$t1,.L0f02b688
/*  f02b67c:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f02b680:	10000004 */ 	b	.L0f02b694
/*  f02b684:	a4790004 */ 	sh	$t9,0x4($v1)
.L0f02b688:
/*  f02b688:	151f0002 */ 	bne	$t0,$ra,.L0f02b694
/*  f02b68c:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f02b690:	a46e0004 */ 	sh	$t6,0x4($v1)
.L0f02b694:
/*  f02b694:	14c4ffc7 */ 	bne	$a2,$a0,.L0f02b5b4
/*  f02b698:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f02b69c:	a6150008 */ 	sh	$s5,0x8($s0)
/*  f02b6a0:	a613000a */ 	sh	$s3,0xa($s0)
/*  f02b6a4:	a60b0014 */ 	sh	$t3,0x14($s0)
/*  f02b6a8:	a6130016 */ 	sh	$s3,0x16($s0)
/*  f02b6ac:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f02b6b0:	a6140022 */ 	sh	$s4,0x22($s0)
/*  f02b6b4:	a615002c */ 	sh	$s5,0x2c($s0)
/*  f02b6b8:	a614002e */ 	sh	$s4,0x2e($s0)
/*  f02b6bc:	8e410000 */ 	lw	$at,0x0($s2)
/*  f02b6c0:	86190024 */ 	lh	$t9,0x24($s0)
/*  f02b6c4:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f02b6c8:	aa010030 */ 	swl	$at,0x30($s0)
/*  f02b6cc:	ba010033 */ 	swr	$at,0x33($s0)
/*  f02b6d0:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f02b6d4:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b6d8:	860e0018 */ 	lh	$t6,0x18($s0)
/*  f02b6dc:	aa0f0034 */ 	swl	$t7,0x34($s0)
/*  f02b6e0:	ba0f0037 */ 	swr	$t7,0x37($s0)
/*  f02b6e4:	860f000c */ 	lh	$t7,0xc($s0)
/*  f02b6e8:	8e410008 */ 	lw	$at,0x8($s2)
/*  f02b6ec:	02002025 */ 	or	$a0,$s0,$zero
/*  f02b6f0:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b6f4:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b6f8:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f02b6fc:	86190026 */ 	lh	$t9,0x26($s0)
/*  f02b700:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b704:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f02b708:	860f000e */ 	lh	$t7,0xe($s0)
/*  f02b70c:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b710:	860e001a */ 	lh	$t6,0x1a($s0)
/*  f02b714:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b718:	aa010038 */ 	swl	$at,0x38($s0)
/*  f02b71c:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b720:	860e0004 */ 	lh	$t6,0x4($s0)
/*  f02b724:	86190028 */ 	lh	$t9,0x28($s0)
/*  f02b728:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b72c:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f02b730:	860f0010 */ 	lh	$t7,0x10($s0)
/*  f02b734:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b738:	860e001c */ 	lh	$t6,0x1c($s0)
/*  f02b73c:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f02b740:	ba01003b */ 	swr	$at,0x3b($s0)
/*  f02b744:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f02b748:	00187883 */ 	sra	$t7,$t8,0x2
/*  f02b74c:	24190010 */ 	addiu	$t9,$zero,0x10
/*  f02b750:	a60f0034 */ 	sh	$t7,0x34($s0)
/*  f02b754:	a2190037 */ 	sb	$t9,0x37($s0)
/*  f02b758:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f02b75c:	a60e0038 */ 	sh	$t6,0x38($s0)
/*  f02b760:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f02b764:	3c0e0440 */ 	lui	$t6,0x440
/*  f02b768:	35ce003c */ 	ori	$t6,$t6,0x3c
/*  f02b76c:	a618003a */ 	sh	$t8,0x3a($s0)
/*  f02b770:	8fb101f0 */ 	lw	$s1,0x1f0($sp)
/*  f02b774:	26390008 */ 	addiu	$t9,$s1,0x8
/*  f02b778:	afb901f0 */ 	sw	$t9,0x1f0($sp)
/*  f02b77c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f02b780:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f02b784:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f02b788:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f02b78c:	3c19b100 */ 	lui	$t9,0xb100
/*  f02b790:	3c0e0332 */ 	lui	$t6,0x332
/*  f02b794:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f02b798:	afaf01f0 */ 	sw	$t7,0x1f0($sp)
/*  f02b79c:	35ce2110 */ 	ori	$t6,$t6,0x2110
/*  f02b7a0:	37394444 */ 	ori	$t9,$t9,0x4444
/*  f02b7a4:	af190000 */ 	sw	$t9,0x0($t8)
/*  f02b7a8:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f02b7ac:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f02b7b0:
/*  f02b7b0:	8fa201f0 */ 	lw	$v0,0x1f0($sp)
/*  f02b7b4:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f02b7b8:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f02b7bc:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f02b7c0:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f02b7c4:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f02b7c8:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f02b7cc:	03e00008 */ 	jr	$ra
/*  f02b7d0:	27bd01f0 */ 	addiu	$sp,$sp,0x1f0
);
#endif

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
						gdl = chr0f02983c(gdl, s0, prop1, s0->model, s0->node, s0->side, -1, -1, 255);
					} else if (s1) {
						gdl = chr0f02983c(gdl, s1, prop1, model, node, -1, -1, -1, 255);
					} else if (s2) {
						gdl = chr0f02983c(gdl, s2, prop1, model, node, -2, s2->unk018[index], s2->unk038[index], 255);
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

							gdl = chr0f02983c(gdl, NULL, prop1, model, node, -7, -1, -1, 255);
						} else {
							if (index == cmnum1) {
								gdl = chr0f02983c(gdl, NULL, prop1, model, node, -3, -1, -1, alpha);
							} else if (index == cmnum2) {
								gdl = chr0f02983c(gdl, NULL, prop1, model, node, -4, -1, -1, alpha);
							} else if (index == cmnum3) {
								gdl = chr0f02983c(gdl, NULL, prop1, model, node, -5, -1, -1, alpha);
							} else if (index == cmnum4) {
								gdl = chr0f02983c(gdl, NULL, prop1, model, node, -6, -1, -1, alpha);
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
					g_ShieldHits[i].shield += (propGetShieldThing(&g_ShieldHits[i].prop) - g_ShieldHits[i].shield) * g_Vars.lvupdate240f * (PAL ? 0.0151515156f : 0.0125f);
				}

				for (j = 0; j < 32; j++) {
					if (g_ShieldHits[i].unk018[j] >= 0) {
						changed = true;
						time60 = g_ShieldHits[i].unk018[j] + g_Vars.lvupdate240_60;

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

s32 g_ShieldHitActive = false;
u32 var80062a94 = 0x00000000;
u32 var80062a98 = 0x00000000;
u32 var80062a9c = 0x00000000;
u32 var80062aa0 = 0x00000000;
u32 var80062aa4 = 0x00000001;
u32 var80062aa8 = 0x00000003;
u32 var80062aac = 0x00000002;
u32 var80062ab0 = 0x00000007;
u32 var80062ab4 = 0x00000005;
u32 var80062ab8 = 0x00000004;
u32 var80062abc = 0x00000006;
u32 var80062ac0 = 0x00000005;
u32 var80062ac4 = 0x00000001;
u32 var80062ac8 = 0x00000000;
u32 var80062acc = 0x00000004;
u32 var80062ad0 = 0x00000002;
u32 var80062ad4 = 0x00000003;
u32 var80062ad8 = 0x00000007;
u32 var80062adc = 0x00000006;
u32 var80062ae0 = 0x00000000;
u32 var80062ae4 = 0x00000002;
u32 var80062ae8 = 0x00000006;
u32 var80062aec = 0x00000004;
u32 var80062af0 = 0x00000007;
u32 var80062af4 = 0x00000003;
u32 var80062af8 = 0x00000001;
u32 var80062afc = 0x00000005;
