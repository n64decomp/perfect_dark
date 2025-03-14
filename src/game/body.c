#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/chr.h"
#include "game/body.h"
#include "game/prop.h"
#include "game/atan2f.h"
#include "game/modelmgr.h"
#include "game/lv.h"
#include "game/modeldef.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "lib/mema.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/ailist.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "data.h"
#include "types.h"

s32 g_NumActiveHeadsPerGender;
u32 var8009cd24;
s32 g_ActiveMaleHeads[8];
s32 g_ActiveFemaleHeads[8];

s32 g_NumTuxedos = 0;
s32 g_NumMaleGuardHeads = 0;
s32 g_NumFemaleGuardHeads = 0;
s32 g_NumMaleGuardTeamHeads = 0;
s32 g_NumFemaleGuardTeamHeads = 0;
s32 var80062b14 = 0;
s32 var80062b18 = 0;

s32 g_TuxedoBodynums[] = {
	BODY_DJBOND,
	BODY_CONNERY,
	BODY_DALTON,
	BODY_MOORE,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

s32 g_MaleGuardHeads[] = {
	HEAD_BEAU1,
	HEAD_CHRIST,
	HEAD_DARLING,
	HEAD_JON,
	HEAD_ROSS,
	HEAD_RUSS,
	HEAD_MARK2,
	HEAD_JAMIE,
	HEAD_DUNCAN2,
	HEAD_BRIAN,
	HEAD_STEVEM,
	HEAD_KEITH,
	HEAD_GRANT,
	HEAD_PENNY,
	HEAD_DAVEC,
	HEAD_JONES,
	HEAD_GRAHAM,
	HEAD_SHAUN,
	HEAD_NEIL2,
	HEAD_EDMCG,
	HEAD_MATT_C,
	HEAD_PEER_S,
	HEAD_ANDY_R,
	HEAD_BEN_R,
	HEAD_STEVE_K,
	HEAD_SCOTT_H,
	HEAD_SANCHEZ,
	HEAD_COOK,
	HEAD_PRYCE,
	HEAD_SILKE,
	HEAD_SMITH,
	HEAD_GARETH,
	HEAD_MURCHIE,
	HEAD_WONG,
	HEAD_CARTER,
	HEAD_TINTIN,
	HEAD_MUNTON,
	HEAD_PHELPS,
	HEAD_KEN,
	HEAD_JOEL,
	HEAD_TIM,
	HEAD_ROBIN,
	-1,
};

s32 g_MaleGuardTeamHeads[] = {
	HEAD_BEAU1,
	HEAD_CHRIST,
	HEAD_DARLING,
	HEAD_JON,
	HEAD_ROSS,
	HEAD_RUSS,
	HEAD_MARK2,
	HEAD_JAMIE,
	HEAD_DUNCAN2,
	HEAD_BRIAN,
	HEAD_STEVEM,
	HEAD_KEITH,
	HEAD_GRANT,
	HEAD_PENNY,
	HEAD_DAVEC,
	HEAD_JONES,
	-1,
};

s32 g_FemaleGuardHeads[] = {
	HEAD_LESLIE_S,
	HEAD_ANKA,
	HEAD_EILEEN_T,
	HEAD_EILEEN_H,
	-1,
};

s32 g_FemaleGuardTeamHeads[] = {
	HEAD_LESLIE_S,
	HEAD_ANKA,
	HEAD_EILEEN_T,
	HEAD_EILEEN_H,
	-1,
};

s32 g_TuxedoIndex = 0;
s32 g_ActiveMaleHeadsIndex = 0;
s32 g_ActiveFemaleHeadsIndex = 0;

s32 g_FemGuardHeads[3] = {
	HEAD_ALEX,
	HEAD_JULIANNE,
	HEAD_LAURA,
};

u32 body_get_race(s32 bodynum)
{
	switch (bodynum) {
	case BODY_SKEDAR:
	case BODY_MINISKEDAR:
	case BODY_SKEDARKING:
		return RACE_SKEDAR;
	case BODY_DRCAROLL:
		return RACE_DRCAROLL;
	case BODY_EYESPY:
		return RACE_EYESPY;
	case BODY_CHICROB:
		return RACE_ROBOT;
	}

	return RACE_HUMAN;
}

bool body_load_modeldef(s32 bodynum)
{
	if (!g_HeadsAndBodies[bodynum].modeldef) {
		g_HeadsAndBodies[bodynum].modeldef = modeldef_load_to_new(g_HeadsAndBodies[bodynum].filenum);
		return true;
	}

	return false;
}

struct model *body_instantiate_model_to_addr(s32 bodynum, s32 headnum, struct modeldef *bodymodeldef, struct modeldef *headmodeldef, bool sunglasses, struct model *model, bool isplayer, u8 varyheight)
{
	f32 scale = g_HeadsAndBodies[bodynum].scale * 0.10000001f;
	f32 animscale = g_HeadsAndBodies[bodynum].animscale;
	struct modelnode *node = NULL;
	u32 stack[2];

	if (cheat_is_active(CHEAT_DKMODE)) {
		scale *= 0.8f;
	}

	if (bodymodeldef == NULL) {
		if (g_HeadsAndBodies[bodynum].modeldef == NULL) {
			g_HeadsAndBodies[bodynum].modeldef = modeldef_load_to_new(g_HeadsAndBodies[bodynum].filenum);
		}

		bodymodeldef = g_HeadsAndBodies[bodynum].modeldef;
	}

	model_allocate_rw_data(bodymodeldef);

	if (!g_HeadsAndBodies[bodynum].unk00_01) {
		if (bodymodeldef->skel == &g_SkelChr) {
			node = model_get_part(bodymodeldef, MODELPART_CHR_HEADSPOT);

			if (node != NULL) {
				if (headnum < 0) {
					headmodeldef = mp_get_phead_modeldef(-1 - headnum, &headnum);
					bodymodeldef->rwdatalen += headmodeldef->rwdatalen;
				} else if (headnum > 0) {
					if (headmodeldef == NULL) {
						if (g_Vars.normmplayerisrunning && IS8MB()) {
							headmodeldef = modeldef_load_to_new(g_HeadsAndBodies[headnum].filenum);
							g_HeadsAndBodies[headnum].modeldef = headmodeldef;
							g_FileInfo[g_HeadsAndBodies[headnum].filenum].loadedsize = 0;
							body_calculate_head_offset(headmodeldef, headnum, bodynum);
						} else {
							if (g_HeadsAndBodies[headnum].modeldef == NULL) {
								g_HeadsAndBodies[headnum].modeldef = modeldef_load_to_new(g_HeadsAndBodies[headnum].filenum);
							}

							headmodeldef = g_HeadsAndBodies[headnum].modeldef;
						}
					}

					model_allocate_rw_data(headmodeldef);

					bodymodeldef->rwdatalen += headmodeldef->rwdatalen;

					if (g_HeadsAndBodies[bodynum].canvaryheight && varyheight) {
						// Set height to between 95% and 115%
						f32 frac = RANDOMFRAC() * 0.05f;
						scale *= 2.0f * frac - 0.05f + 1.0f;
					}
				}

				if (!isplayer) {
					if (cheat_is_active(CHEAT_SMALLCHARACTERS)) {
						scale *= 0.4f;
					}

					if (cheat_is_active(CHEAT_DKMODE)) {
						scale *= 1.25f;
					}
				} else {
					if (cheat_is_active(CHEAT_SMALLJO)) {
						scale *= 0.4f;
					}
				}
			}
		} else if (bodymodeldef->skel == &g_SkelSkedar) {
			if (g_HeadsAndBodies[bodynum].canvaryheight && varyheight && bodynum == BODY_SKEDAR) {
				// Set height to between 65% and 85%
				f32 frac = RANDOMFRAC();
				scale *= 2.0f * (0.1f * frac) - 0.1f + 0.75f;
			}

			if (1);
		}
	}

	if (model) {
		if (model->rwdatalen < bodymodeldef->rwdatalen);
	} else {
		model = modelmgr_instantiate_model_with_anim(bodymodeldef);
	}

	if (model) {
		model_set_scale(model, scale);
		model_set_anim_scale(model, animscale);

		if (headmodeldef && !g_HeadsAndBodies[bodynum].unk00_01) {
			bodymodeldef->rwdatalen -= headmodeldef->rwdatalen;

			modelmgr_attach_head(model, node, headmodeldef);

			if ((s16)*(s32 *)&headmodeldef->skel == SKEL_HEAD) {
				struct modelnode *node2;

				if (!sunglasses) {
					node2 = model_get_part(headmodeldef, MODELPART_HEAD_SUNGLASSES);

					if (node2) {
						union modelrwdata *rwdata = model_get_node_rw_data(model, node2);
						rwdata->toggle.visible = false;
					}
				}

				node2 = model_get_part(headmodeldef, MODELPART_HEAD_HUDPIECE);

				if (node2) {
					union modelrwdata *rwdata = model_get_node_rw_data(model, node2);
					rwdata->toggle.visible = false;
				}
			}
		}
	}

	return model;
}

struct model *body_instantiate_model_to_new(s32 bodynum, s32 headnum, struct modeldef *bodymodeldef, struct modeldef *headmodeldef, bool sunglasses, u8 varyheight)
{
	return body_instantiate_model_to_addr(bodynum, headnum, bodymodeldef, headmodeldef, sunglasses, NULL, false, varyheight);
}

struct model *body_instantiate_model_with_spawnflags(s32 bodynum, s32 headnum, u32 spawnflags)
{
	bool sunglasses = false;
	u8 varyheight = true;

	if (spawnflags & SPAWNFLAG_FORCESUNGLASSES) {
		sunglasses = true;
	} else if (spawnflags & SPAWNFLAG_MAYBESUNGLASSES) {
		sunglasses = random() % 2 == 0;
	}

	if (spawnflags & SPAWNFLAG_FIXEDHEIGHT) {
		varyheight = false;
	}

	return body_instantiate_model_to_new(bodynum, headnum, NULL, NULL, sunglasses, varyheight);
}

s32 body_get_tuxedo_bodynum(void)
{
	return g_TuxedoBodynums[g_TuxedoIndex];
}

s32 body_choose_head(s32 bodynum)
{
	s32 head;

	if (g_HeadsAndBodies[bodynum].ismale) {
		head = g_ActiveMaleHeads[g_ActiveMaleHeadsIndex++];

		if (g_ActiveMaleHeadsIndex == g_NumActiveHeadsPerGender) {
			g_ActiveMaleHeadsIndex = 0;
		}
	} else if (bodynum == BODY_FEM_GUARD) {
		head = g_FemGuardHeads[random() % 3];
	} else {
		head = g_ActiveFemaleHeads[g_ActiveFemaleHeadsIndex++];

		if (g_ActiveFemaleHeadsIndex == g_NumActiveHeadsPerGender) {
			g_ActiveFemaleHeadsIndex = 0;
		}
	}

	return head;
}

/**
 * Read a "packed" chr definition and create a runtime chr from it.
 *
 * Chr definitions are stored in a packed format in each stage's setup file.
 * The packed format is used for space saving reasons.
 */
void body_instantiate_chr(s32 stagenum, struct packedchr *packed, s32 cmdindex)
{
	struct pad pad;
	RoomNum rooms[2];
	struct chrdata *chr;
	struct modeldef *headmodeldef;
	struct model *model;
	struct prop *prop;
	s32 bodynum;
	s32 headnum;
	f32 angle;
	s32 index;

	pad_unpack(packed->padnum, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_ROOM, &pad);

	rooms[0] = pad.room;
	rooms[1] = -1;

	if (cd_test_volume_simple(&pad.pos, 20, rooms, CDTYPE_ALL, CHECKVERTICAL_YES, 200, -200) == CDRESULT_COLLISION
			&& packed->chair == -1
			&& (packed->spawnflags & SPAWNFLAG_IGNORECOLLISION) == 0) {
		return;
	}

	if (packed->spawnflags & (SPAWNFLAG_ONLYONA | SPAWNFLAG_ONLYONSA | SPAWNFLAG_ONLYONPA)) {
		if ((packed->spawnflags & (SPAWNFLAG_ONLYONA | SPAWNFLAG_ONLYONSA | SPAWNFLAG_ONLYONPA)) == 0) {
			return;
		}

		if (((packed->spawnflags & SPAWNFLAG_ONLYONA) && lv_get_difficulty() == DIFF_A)
				|| ((packed->spawnflags & SPAWNFLAG_ONLYONSA) && lv_get_difficulty() == DIFF_SA)
				|| ((packed->spawnflags & SPAWNFLAG_ONLYONPA) && lv_get_difficulty() == DIFF_PA)) {
			// ok
		} else {
			return;
		}
	}

	headnum = -55555;
	headmodeldef = NULL;

	if (packed->bodynum == 255) {
		bodynum = body_get_tuxedo_bodynum();
	} else {
		bodynum = packed->bodynum;
	}

	if (!g_HeadsAndBodies[bodynum].unk00_01) {
		if (packed->headnum >= 0) {
			headnum = packed->headnum;
		} else if (headnum == -55555) {
			headnum = body_choose_head(bodynum);
		}
	}

	if (headnum < 0) {
		index = -1 - headnum;

		if (index >= 0 && index < 22) {
			headmodeldef = mp_get_phead_modeldef(index, &headnum);
		}

		model = body_instantiate_model_to_addr(bodynum, headnum, NULL, headmodeldef, false, NULL, false, false);
	} else {
		model = body_instantiate_model_with_spawnflags(bodynum, headnum, packed->spawnflags);
	}

	if (model != NULL) {
		angle = atan2f(pad.look.x, pad.look.z);
		prop = chr_create_with_model(model, &pad.pos, rooms, angle, ailist_find_by_id(packed->ailistnum));

		if (prop != NULL) {
			prop_activate(prop);
			prop_enable(prop);

			chr = prop->chr;
			chr_set_chrnum(chr, packed->chrnum);
			chr->hearingscale = packed->hearscale / 1000.0f;
			chr->visionrange = packed->viewdist;
			chr->padpreset1 = packed->padpreset;
			chr->chrpreset1 = packed->chrpreset;
			chr->headnum = headnum;
			chr->bodynum = bodynum;
			chr->race = body_get_race(chr->bodynum);

			chr->rtracked = false;

			if (bodynum == BODY_DRCAROLL) {
				chr->drcarollimage_left = 0;
				chr->drcarollimage_right = 0;
				chr->height = 185;
				chr->radius = 30;
			} else if (bodynum == BODY_CHICROB) {
				chr->unk348[0] = memp_alloc(sizeof(struct fireslotthing), MEMPOOL_STAGE);
				chr->unk348[1] = memp_alloc(sizeof(struct fireslotthing), MEMPOOL_STAGE);
				chr->unk348[0]->beam = memp_alloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
				chr->unk348[1]->beam = memp_alloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
				chr->unk348[0]->beam->age = -1;
				chr->unk348[1]->beam->age = -1;
				chr->height = 200;
				chr->radius = 42;
			}

			if (packed->spawnflags & SPAWNFLAG_INVINCIBLE) {
				chr->chrflags |= CHRCFLAG_INVINCIBLE;
			}

			if (packed->spawnflags & SPAWNFLAG_BASICGUARD) {
				chr->hidden |= CHRHFLAG_BASICGUARD;
			}

			if (packed->spawnflags & SPAWNFLAG_ANTINONINTERACTABLE) {
				chr->hidden |= CHRHFLAG_ANTINONINTERACTABLE;
			}

			if (packed->spawnflags & SPAWNFLAG_DONTSHOOTME) {
				chr->hidden |= CHRHFLAG_DONTSHOOTME;
			}

			if (packed->spawnflags & SPAWNFLAG_HIDDEN) {
				chr->chrflags |= CHRCFLAG_HIDDEN;
			}

			if (packed->spawnflags & SPAWNFLAG_RTRACKED) {
				chr->rtracked = true;
			}

			if (packed->spawnflags & SPAWNFLAG_NOBLOOD) {
				chr->noblood = true;
			}

			if (packed->spawnflags & SPAWNFLAG_BLUESIGHT) {
				chr->hidden2 |= CHRH2FLAG_BLUESIGHT;
			}

			chr->flags = packed->flags;
			chr->flags2 = packed->flags2;

			if (cheat_is_active(CHEAT_MARQUIS)) {
				chr->flags2 &= ~CHRFLAG1_NOHANDCOMBAT;
				chr->flags2 |= CHRFLAG1_HANDCOMBATONLY;
			}

			chr->team = packed->team;
			chr->squadron = packed->squadron;
			chr->aibot = NULL;

			if (packed->tude != 4) {
				chr->tude = packed->tude;
			} else {
				chr->tude = random() % 4;
			}

			chr->voicebox = random() % 3;

			if (!g_HeadsAndBodies[chr->bodynum].ismale) {
				chr->voicebox = VOICEBOX_FEMALE;
			}

			chr->naturalanim = packed->naturalanim;
			chr->myspecial = packed->chair;
			chr->yvisang = packed->yvisang;

			packed->chrindex = chr - g_ChrSlots;

			chr->teamscandist = packed->teamscandist;
			chr->convtalk = packed->convtalk;

			if (chr->flags & CHRFLAG0_CAN_HEARSPAWN) {
				chr->chrflags |= CHRCFLAG_CLONEABLE;
			}

			if (!g_Vars.normmplayerisrunning && g_MissionConfig.iscoop && g_Vars.numaibuddies > 0) {
				chr->flags |= CHRFLAG0_AIVSAI;
			}

			if (random() % 5 == 0) {
				// Make chr punch slower
				chr->flags2 |= CHRFLAG1_ADJUSTPUNCHSPEED;
			}

			if (CHRRACE(chr) == RACE_SKEDAR) {
				chr->chrflags |= CHRCFLAG_FORCEAUTOAIM;
			}
		}
	}
}

struct prop *body_instantiate_eyespy(struct pad *pad, RoomNum room)
{
	RoomNum rooms[2];
	struct prop *prop;
	struct chrdata *chr;
	struct model *model;
	s32 inlift;
	struct prop *lift;
	f32 ground;

	rooms[0] = room;
	rooms[1] = -1;

#if PIRACYCHECKS
	{
		u32 stack[2];
		u32 checksum = 0;
		s32 *ptr = (s32 *)&lv_reset;
		s32 *end = (s32 *)&lv_configure_fade;

		while (ptr < end) {
			checksum <<= 1;
			checksum ^= *ptr;
			ptr++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			s32 *ptr2 = (s32 *)_mema_free;
			s32 *end2 = (s32 *)mema_init;

			while (ptr2 < end2) {
				ptr2[0] = 0;
				ptr2++;
			}
		}
	}
#endif

	model = body_instantiate_model_with_spawnflags(BODY_EYESPY, 0, 0);

	if (model) {
		prop = chr_create_with_model(model, &pad->pos, rooms, 0, ailist_find_by_id(GAILIST_IDLE));

		if (prop) {
			prop_activate(prop);
			prop_enable(prop);
			chr = prop->chr;
			chr_set_chrnum(chr, chrs_get_next_unused_chrnum());
			chr->bodynum = BODY_EYESPY;
			chr->padpreset1 = 0;
			chr->chrpreset1 = 0;
			chr->headnum = 0;
			chr->hearingscale = 0;
			chr->visionrange = 0;
			chr->race = body_get_race(chr->bodynum);

			ground = cd_find_ground_at_cyl_ctfril(&pad->pos, 30, rooms, NULL, NULL, NULL, NULL, &inlift, &lift);
			chr->ground = ground;
			chr->manground = ground;

			chr->flags = 0;
			chr->flags2 = 0;
			chr->team = 0;
			chr->squadron = 0;
			chr->maxdamage = 2;
			chr->tude = random() & 3;
			chr->voicebox = random() % 3;
			chr->naturalanim = 0;
			chr->myspecial = 0;
			chr->yvisang = 0;
			chr->teamscandist = 0;
			chr->convtalk = 0;
			chr->radius = 26;
			chr->height = 200;
			chr_stand_immediate(chr, 0);
			chr->chrflags |= CHRCFLAG_HIDDEN;

#if VERSION >= VERSION_NTSC_1_0
			chr->hidden2 |= CHRH2FLAG_CONSIDERPROXIES;
#else
			chr->hidden |= CHRHFLAG_CONSIDERPROXIES;
#endif

			return prop;
		}
	}

	return NULL;
}

void body0f02ddbf(void)
{
	// empty
}

/**
 * Tweak the head's Y offset to suit the body.
 *
 * By default, heads and their matching bodies align perfectly and don't need
 * any tweaking. This function is used in multiplayer where players can put any
 * heads on any bodies.
 */
void body_calculate_head_offset(struct modeldef *headmodeldef, s32 headnum, s32 bodynum)
{
	struct modelnode *node;
	struct modelnode *prev;
	Gfx *gdl;
	s32 offset;
	struct modelrodata_bbox *bbox;
	s32 i;

#if VERSION >= VERSION_JPN_FINAL
	offset = 0;

	switch (headnum) {
	case HEAD_DARK_COMBAT:
	case HEAD_DARK_FROCK:
	case HEAD_DARKAQUA:
	case HEAD_DARK_SNOW:
		switch (bodynum) {
		case BODY_DARK_COMBAT:
		case BODY_DARK_FROCK:
		case BODY_DARK_TRENCH:
		case BODY_DARK_RIPPED:
		case BODY_DARK_AF1:
		case BODY_DARKWET:
		case BODY_DARKAQUALUNG:
		case BODY_DARKSNOW:
		case BODY_DARKLAB:
		case BODY_DARK_LEATHER:
		case BODY_DARK_NEGOTIATOR:
			break;
		default:
			offset = -12;
			break;
		}
		break;
	}
#endif

	if ((s16)(*(s32 *)&headmodeldef->skel) == SKEL_HEAD) {
#if VERSION >= VERSION_JPN_FINAL
		if (g_HeadsAndBodies[headnum].type == g_HeadsAndBodies[bodynum].type && offset == 0) {
			return;
		}
#else
		if (g_HeadsAndBodies[headnum].type == g_HeadsAndBodies[bodynum].type) {
			return;
		}
#endif

		// In the switch statement below, most versions set the offset directly.
		// JPN increments it instead.
#if VERSION >= VERSION_JPN_FINAL
#define ADJUST(var, amount) (var + amount)
#else
#define ADJUST(var, amount) (amount)
#endif

		switch (g_HeadsAndBodies[headnum].type) {
		default:
		case HEADBODYTYPE_FEMALE:
			offset = ADJUST(offset, 0);
			break;
		case HEADBODYTYPE_MAIAN:
			offset = ADJUST(offset, 0);
			break;
		case HEADBODYTYPE_DEFAULT:
			offset = ADJUST(offset, -35);
			break;
		case HEADBODYTYPE_MRBLONDE:
			offset = ADJUST(offset, 0);
			break;
		case HEADBODYTYPE_CASS:
			offset = ADJUST(offset, -20);
			break;
		case HEADBODYTYPE_FEMALEGUARD:
			offset = ADJUST(offset, -40);
			break;
		}

		switch (g_HeadsAndBodies[bodynum].type) {
		case HEADBODYTYPE_FEMALE:
			break;
		case HEADBODYTYPE_MAIAN:
			offset -= 30;
			break;
		case HEADBODYTYPE_DEFAULT:
			offset += 35;
			break;
		case HEADBODYTYPE_MRBLONDE:
			break;
		case HEADBODYTYPE_CASS:
			offset += 20;
			break;
		case HEADBODYTYPE_FEMALEGUARD:
			offset += 40;
			break;
		}

		if (g_HeadsAndBodies[bodynum].type == HEADBODYTYPE_FEMALE) {
			if (g_HeadsAndBodies[headnum].type == HEADBODYTYPE_DEFAULT
					|| g_HeadsAndBodies[headnum].type == HEADBODYTYPE_MRBLONDE) {
				offset -= 10;
			} else if (g_HeadsAndBodies[headnum].type == HEADBODYTYPE_CASS
					|| g_HeadsAndBodies[headnum].type == HEADBODYTYPE_FEMALEGUARD) {
				offset -= 5;
			}
		} else if (g_HeadsAndBodies[bodynum].type == HEADBODYTYPE_CASS
				&& (g_HeadsAndBodies[headnum].type == HEADBODYTYPE_DEFAULT
					|| g_HeadsAndBodies[headnum].type == HEADBODYTYPE_MRBLONDE)) {
			offset -= 5;
		}

		// Apply the offset
		if (offset != 0) {
			node = NULL;

			do {
				prev = node;

				model_iterate_display_lists(headmodeldef, &node, &gdl);

				if (node && node != prev && node->type == MODELNODETYPE_DL) {
					struct modelrodata_dl *rodata = &node->rodata->dl;

					for (i = 0; i < rodata->numvertices; i++) {
						rodata->vertices[i].y += offset;
					}
				}
			} while (node);

			bbox = modeldef_find_bbox_rodata(headmodeldef);

			if (bbox != NULL) {
				bbox->ymin += offset;
				bbox->ymax += offset;
			}
		}
	}
}
